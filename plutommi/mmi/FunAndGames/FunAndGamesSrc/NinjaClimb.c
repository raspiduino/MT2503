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
 * Filename:
 * ---------
 *  NinjaClimb.c
 *
 * Project:
 * --------
 *  Maui
 *
 * Description:
 * ------------
 *  Game NinjaClimb function.
 *
 *
 * Author:
 * -------
 * -------
 * -------
 *
 ****************************************************************************/

#include "mmi_features.h"
#include "GameDefs.h"

#if defined(__MMI_GAME_NINJACLIMB__)
#include "GameInc.h"
#include "NinjaClimbProts.h"
#include "mmi_rp_app_games_def.h"

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
#include "GameProts.h"
#endif
/*****************************************************************************
* Define
*****************************************************************************/
#if defined(__MMI_MAINLCD_128X128__)

#define MMI_GX_NINJACLIMB_LCD_HEIGHT        (128)
#define MMI_GX_NINJACLIMB_LCD_WIDTH         (128)

#define MMI_GX_NINJACLIMB_LEFT_NINJA       (18)
#define MMI_GX_NINJACLIMB_MID_NINJA        (60)
#define MMI_GX_NINJACLIMB_RIGHT_NINJA      (100)
#define MMI_GX_NINJACLIMB_ROPE_WIDTH       (8)
#define MMI_GX_NINJACLIMB_ROLE_WIDTH        (25)
#define MMI_GX_NINJACLIMB_ROLE_HEIGHT       (38)
#define MMI_GX_NINJACLIMB_ENEMY_WIDTH       (18)
#define MMI_GX_NINJACLIMB_ENEMY_HEIGHT      (23)
#define MMI_GX_NINJACLIMB_CLOCK_WIDTH       (16)
#define MMI_GX_NINJACLIMB_CLOCK_HEIGHT      (16)
#define MMI_GX_NINJACLIMB_ROLE_SPEED        (4)
#define MMI_GX_NINJACLIMB_ROLE_ATTACK_SPEED (8)
#define MMI_GX_NINJACLIMB_ENEMY_NEW_INTERVAL_1 (12)
#define MMI_GX_NINJACLIMB_ENEMY_NEW_INTERVAL_2 (6)
#define MMI_GX_NINJACLIMB_ENEMY_SLOW_SPEED  (2)  //MMI_GX_NINJACLIMB_ENEMY_NEW_INTERVAL_1 * MMI_GX_NINJACLIMB_ENEMY_SLOW_SPEED > ~ MMI_GX_NINJACLIMB_ENEMY_HEIGHT
#define MMI_GX_NINJACLIMB_FALLING_SPEED     (8)
#define MMI_GX_NINJACLIMB_TOP_MARGIN        (8)
#define MMI_GX_NINJACLIMB_CLOCK_SPEED       (2)

#define MMI_GX_NINJACLIMB_SCORE_X (42)
#define MMI_GX_NINJACLIMB_SCORE_Y (4)

#define MMI_GX_NINJACLIMB_DIGIT_X (112)
#define MMI_GX_NINJACLIMB_DIGIT_Y (4)
#define MMI_GX_NINJACLIMB_DIGIT_WIDTH (9)

#define MMI_GX_NINJACLIMB_ROLE_OFFSET (8)
#define MMI_GX_NINJACLIMB_ENEMY_OFFSET (8)

#define MMI_GX_NINJACLIMB_LEFT_SPACE_X (36)
#define MMI_GX_NINJACLIMB_RIGHT_SPACE_X (80)

#define MMI_GX_NINJACLIMB_DYING_ROLE_OFFSET_X MMI_GX_NINJACLIMB_ROLE_OFFSET
#define MMI_GX_NINJACLIMB_DYING_ENEMY_OFFSET_X MMI_GX_NINJACLIMB_ENEMY_OFFSET


#elif defined(__MMI_MAINLCD_128X160__)

#define MMI_GX_NINJACLIMB_LCD_HEIGHT        (160)
#define MMI_GX_NINJACLIMB_LCD_WIDTH         (128)

#define MMI_GX_NINJACLIMB_LEFT_NINJA       (18)
#define MMI_GX_NINJACLIMB_MID_NINJA        (60)
#define MMI_GX_NINJACLIMB_RIGHT_NINJA      (100)
#define MMI_GX_NINJACLIMB_ROPE_WIDTH       (8)
#define MMI_GX_NINJACLIMB_ROLE_WIDTH        (25)
#define MMI_GX_NINJACLIMB_ROLE_HEIGHT       (38)
#define MMI_GX_NINJACLIMB_ENEMY_WIDTH       (18)
#define MMI_GX_NINJACLIMB_ENEMY_HEIGHT      (23)
#define MMI_GX_NINJACLIMB_CLOCK_WIDTH       (16)
#define MMI_GX_NINJACLIMB_CLOCK_HEIGHT      (16)
#define MMI_GX_NINJACLIMB_ROLE_SPEED        (4)
#define MMI_GX_NINJACLIMB_ROLE_ATTACK_SPEED (8)
#define MMI_GX_NINJACLIMB_ENEMY_NEW_INTERVAL_1 (12)
#define MMI_GX_NINJACLIMB_ENEMY_NEW_INTERVAL_2 (6)
#define MMI_GX_NINJACLIMB_ENEMY_SLOW_SPEED  (2)  //MMI_GX_NINJACLIMB_ENEMY_NEW_INTERVAL_1 * MMI_GX_NINJACLIMB_ENEMY_SLOW_SPEED > ~ MMI_GX_NINJACLIMB_ENEMY_HEIGHT
#define MMI_GX_NINJACLIMB_FALLING_SPEED     (8)
#define MMI_GX_NINJACLIMB_TOP_MARGIN        (8)
#define MMI_GX_NINJACLIMB_CLOCK_SPEED       (2)

#define MMI_GX_NINJACLIMB_SCORE_X (42)
#define MMI_GX_NINJACLIMB_SCORE_Y (4)

#define MMI_GX_NINJACLIMB_DIGIT_X (112)
#define MMI_GX_NINJACLIMB_DIGIT_Y (4)
#define MMI_GX_NINJACLIMB_DIGIT_WIDTH (9)

#define MMI_GX_NINJACLIMB_ROLE_OFFSET (8)
#define MMI_GX_NINJACLIMB_ENEMY_OFFSET (8)

#define MMI_GX_NINJACLIMB_LEFT_SPACE_X (36)
#define MMI_GX_NINJACLIMB_RIGHT_SPACE_X (80)

#define MMI_GX_NINJACLIMB_DYING_ROLE_OFFSET_X MMI_GX_NINJACLIMB_ROLE_OFFSET
#define MMI_GX_NINJACLIMB_DYING_ENEMY_OFFSET_X MMI_GX_NINJACLIMB_ENEMY_OFFSET

#elif defined(__MMI_MAINLCD_176X220__)

#define MMI_GX_NINJACLIMB_LCD_HEIGHT        (220)
#define MMI_GX_NINJACLIMB_LCD_WIDTH         (176)

#define MMI_GX_NINJACLIMB_LEFT_NINJA       (28)
#define MMI_GX_NINJACLIMB_MID_NINJA        (82)
#define MMI_GX_NINJACLIMB_RIGHT_NINJA      (138)
#define MMI_GX_NINJACLIMB_ROPE_WIDTH       (10)
#define MMI_GX_NINJACLIMB_ROLE_WIDTH        (30)
#define MMI_GX_NINJACLIMB_ROLE_HEIGHT       (43)
#define MMI_GX_NINJACLIMB_ENEMY_WIDTH       (21)
#define MMI_GX_NINJACLIMB_ENEMY_HEIGHT      (28)
#define MMI_GX_NINJACLIMB_CLOCK_WIDTH       (20)
#define MMI_GX_NINJACLIMB_CLOCK_HEIGHT      (20)
#define MMI_GX_NINJACLIMB_ROLE_SPEED        (5)
#define MMI_GX_NINJACLIMB_ROLE_ATTACK_SPEED (10)
#define MMI_GX_NINJACLIMB_ENEMY_NEW_INTERVAL_1 (10)
#define MMI_GX_NINJACLIMB_ENEMY_NEW_INTERVAL_2 (6)
#define MMI_GX_NINJACLIMB_ENEMY_SLOW_SPEED  (3) //MMI_GX_NINJACLIMB_ENEMY_NEW_INTERVAL_1 * MMI_GX_NINJACLIMB_ENEMY_SLOW_SPEED > ~ MMI_GX_NINJACLIMB_ENEMY_HEIGHT
#define MMI_GX_NINJACLIMB_FALLING_SPEED     (10)
#define MMI_GX_NINJACLIMB_TOP_MARGIN        (12)
#define MMI_GX_NINJACLIMB_CLOCK_SPEED       (3)

#define MMI_GX_NINJACLIMB_SCORE_X (55)
#define MMI_GX_NINJACLIMB_SCORE_Y (8)

#define MMI_GX_NINJACLIMB_DIGIT_X (154)
#define MMI_GX_NINJACLIMB_DIGIT_Y (8)
#define MMI_GX_NINJACLIMB_DIGIT_WIDTH (13)

#define MMI_GX_NINJACLIMB_ROLE_OFFSET (10)
#define MMI_GX_NINJACLIMB_ENEMY_OFFSET (8)

#define MMI_GX_NINJACLIMB_LEFT_SPACE_X (50)
#define MMI_GX_NINJACLIMB_RIGHT_SPACE_X (110)

#define MMI_GX_NINJACLIMB_DYING_ROLE_OFFSET_X MMI_GX_NINJACLIMB_ROLE_OFFSET
#define MMI_GX_NINJACLIMB_DYING_ENEMY_OFFSET_X MMI_GX_NINJACLIMB_ENEMY_OFFSET


#elif defined(__MMI_MAINLCD_240X320__)

#define MMI_GX_NINJACLIMB_LCD_HEIGHT        (320)
#define MMI_GX_NINJACLIMB_LCD_WIDTH         (240)

#define MMI_GX_NINJACLIMB_LEFT_NINJA       (36)
#define MMI_GX_NINJACLIMB_MID_NINJA        (115)
#define MMI_GX_NINJACLIMB_RIGHT_NINJA      (193)
#define MMI_GX_NINJACLIMB_ROPE_WIDTH       (13)
#define MMI_GX_NINJACLIMB_ROLE_WIDTH        (40)
#define MMI_GX_NINJACLIMB_ROLE_HEIGHT       (63)
#define MMI_GX_NINJACLIMB_ENEMY_WIDTH       (34)
#define MMI_GX_NINJACLIMB_ENEMY_HEIGHT      (46)
#define MMI_GX_NINJACLIMB_CLOCK_WIDTH       (35)
#define MMI_GX_NINJACLIMB_CLOCK_HEIGHT      (35)
#define MMI_GX_NINJACLIMB_ROLE_SPEED        (6)
#define MMI_GX_NINJACLIMB_ROLE_ATTACK_SPEED (12)
#define MMI_GX_NINJACLIMB_ENEMY_NEW_INTERVAL_1 (12)
#define MMI_GX_NINJACLIMB_ENEMY_NEW_INTERVAL_2 (8)
#define MMI_GX_NINJACLIMB_ENEMY_SLOW_SPEED  (4) //Speed x internal_new_enemy >= enemy height
#define MMI_GX_NINJACLIMB_FALLING_SPEED     (12)
#define MMI_GX_NINJACLIMB_TOP_MARGIN        (16)
#define MMI_GX_NINJACLIMB_CLOCK_SPEED       (4)

#define MMI_GX_NINJACLIMB_SCORE_X (70)
#define MMI_GX_NINJACLIMB_SCORE_Y (8)

#define MMI_GX_NINJACLIMB_DIGIT_X (210)
#define MMI_GX_NINJACLIMB_DIGIT_Y (8)
#define MMI_GX_NINJACLIMB_DIGIT_WIDTH (17)

#define MMI_GX_NINJACLIMB_ROLE_OFFSET (12)
#define MMI_GX_NINJACLIMB_ENEMY_OFFSET (12)

#define MMI_GX_NINJACLIMB_LEFT_SPACE_X (70)
#define MMI_GX_NINJACLIMB_RIGHT_SPACE_X (150)

#define MMI_GX_NINJACLIMB_DYING_ROLE_OFFSET_X MMI_GX_NINJACLIMB_ROLE_OFFSET
#define MMI_GX_NINJACLIMB_DYING_ENEMY_OFFSET_X MMI_GX_NINJACLIMB_ENEMY_OFFSET

#endif

#define MMI_GX_NINJACLIMB_IS_ROLE           (0)
#define MMI_GX_NINJACLIMB_IS_ENEMY          (1)
#define MMI_GX_NINJACLIMB_IS_CLOCK          (2)
#define MMI_GX_NINJACLIMB_IS_DYING_ROLE     (3)
#define MMI_GX_NINJACLIMB_IS_DYING_ENEMY    (4)
#define MMI_GX_NINJACLIMB_TRANSPARENT_COLOR (GDI_COLOR_BLUE)
#define MMI_GX_NINJACLIMB_GO_LEFT           (0)
#define MMI_GX_NINJACLIMB_GO_RIGHT          (1)
#define MMI_GX_NINJACLIMB_TOTAL_TIME        (70)
#define MMI_GX_NINJACLIMB_ENEMY_COUNT       (9)      /* 9 = floor(LCD_HEIGHT / (ENEMY_SLOW_SPEED * 10)) + 1 */
#define MMI_GX_NINJACLIMB_SIDE_COUNT        (6)
#define MMI_GX_NINJACLIMB_TIME_EXTENSION    (25)
#define MMI_GX_NINJACLIMB_SCORE_PER_ENEMY   (5)

#ifdef __MMI_TOUCH_SCREEN__
//#define MMI_GX_NINJACLIMB_ATTACK_INTERVAL    (100)     /* if interval of pen down to up is smaller than this, raise attack */
#define MMI_GX_NINJACLIMB_MOVE_THRESHOLD     (8)
#endif

/*
 * ninja length = 160 - TOP_MARGIN (12) = 148
 * An enemy every second
 * up-going enemy speed: ENEMY_SLOW_SPEED
 *
 *
 * thus there are at most ENEMY_COUNT enemies on one side of a ninja
 *
 * How many enemies on one side of a ninja is DEPENDS on the speed of the slowest enemies!
 */

/*****************************************************************************
* Typedef
*****************************************************************************/
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
//added for multi-language support
typedef enum
{
    MMI_NINJACLIMB_STRING_BACKGROUND,
    MMI_NINJACLIMB_STRING_TOTAL
}mmi_frogcandy_string_enum;
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

typedef enum
{
    LEFT_ROPE_LEFT,
    LEFT_ROPE_RIGHT,
    MID_ROPE_LEFT,
    MID_ROPE_RIGHT,
    RIGHT_ROPE_LEFT,
    RIGHT_ROPE_RIGHT,
    LEFT_SPACE,
    RIGHT_SPACE
} gx_ninjaclimb_pos_state_enum;

typedef enum
{
    NORMAL,
    ATTACK,
    FLYING
} gx_ninjaclimb_state_enum;

typedef enum
{
    ENEMY_1,
    ENEMY_2,

    ENEMY_MAX
} gx_ninjaclimb_type_enum;

typedef struct t_ninjaclimb_node
{
    struct t_ninjaclimb_node *previous;
    struct t_ninjaclimb_node *next;
    S16 position_y;
    S16 old_position_y;
    gx_ninjaclimb_type_enum type;
    BOOL is_dying;
} gx_ninjaclimb_node_struct;

typedef struct
{
    gx_ninjaclimb_node_struct enemy[MMI_GX_NINJACLIMB_ENEMY_COUNT];
    gx_ninjaclimb_node_struct *first;
    gx_ninjaclimb_node_struct *last;
    gx_ninjaclimb_node_struct *empty;
    gx_ninjaclimb_node_struct *empty_last;
} gx_ninjaclimb_tree_struct;

/* game context */
typedef struct
{
    /* variables needs to be init */
    BOOL is_gameover;
    BOOL is_new_game;
    U8 game_level;
    S16 game_grade;
    U16 timer_elapse;
    BOOL up_key_pressed;
    BOOL down_key_pressed;
    U16 tick;

    BOOL clock_falling;
    BOOL is_dying;
    U16 total_time;
    S16 clock_position_y;
    S16 clock_x_position;
    S16 clock_old_position_y;
    U8 enemy_speed;
    gdi_handle background;
    gdi_handle foreground;

    gx_ninjaclimb_pos_state_enum clock_pos_state;
    gx_ninjaclimb_pos_state_enum pos_state;
    gx_ninjaclimb_pos_state_enum old_pos_state;
    gx_ninjaclimb_state_enum old_state;
    gx_ninjaclimb_state_enum state;
    mmi_gfx_position position;
    mmi_gfx_position old_position;
    gx_ninjaclimb_tree_struct tree[6];

#ifdef __MMI_TOUCH_SCREEN__
    MMI_BOOL is_pen_hit;
    mmi_pen_point_struct pen_down_pos;
    mmi_pen_point_struct pen_up_pos;
#endif
} gx_ninjaclimb_context_struct;

/*****************************************************************************
* Local Variable
*****************************************************************************/
gx_ninjaclimb_context_struct g_gx_ninjaclimb_context =
{
    FALSE,                      /* is_gameover */
    TRUE,                       /* is_new_game */
    0,                          /* game_level */
    0,                          /* game_grade */
    100,                        /* timer_elapse */
    FALSE,                      /* up_key_preesed */
    FALSE,                      /* down_key_pressed */
    0,                          /* tick */
    MMI_GX_NINJACLIMB_TOTAL_TIME,    /* total time for gameplay */
};

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
static U16 mmi_ninjaclimb_language_index;
#define MMI_NINJACLIMB_STRING_COUNT  MMI_NINJACLIMB_STRING_TOTAL
#endif

/*****************************************************************************
* Local Function
*****************************************************************************/
/* Game framework related functions */
S16 mmi_gx_ninjaclimb_calc_best_grade(S16 old_grade, S16 new_grade); /* descide which is best grade */
void mmi_gx_ninjaclimb_enter_game(void);     /* entry function of the game */
void mmi_gx_ninjaclimb_exit_game(void);      /* exit function - usually will stop timer and release buffer */
void mmi_gx_ninjaclimb_draw_gameover(void);  /* draw gameover screen */

/* Game play functions */
void mmi_gx_ninjaclimb_framemove(void);
void mmi_gx_ninjaclimb_render(void);
void mmi_gx_ninjaclimb_gameover(void);
void mmi_gx_ninjaclimb_cyclic_timer(void);
void mmi_gx_ninjaclimb_init_game(void);  /* draw gameover screen */
void mmi_gx_ninjaclimb_key_2_press(void);
void mmi_gx_ninjaclimb_key_8_press(void);
void mmi_gx_ninjaclimb_key_5_press(void);
void mmi_gx_ninjaclimb_key_2_release(void);
void mmi_gx_ninjaclimb_key_8_release(void);
void mmi_gx_ninjaclimb_key_5_release(void);
void mmi_gx_ninjaclimb_key_4_press(void);
void mmi_gx_ninjaclimb_key_6_press(void);
S16 mmi_gx_ninjaclimb_get_x_position(gx_ninjaclimb_pos_state_enum state, U8 type);
void mmi_gx_ninjaclimb_turn_or_fly(U8 action);
void mmi_gx_ninjaclimb_draw_digits(U16 x, U16 y, U16 number);
void mmi_gx_ninjaclimb_init_enemy_list(void);

#ifdef __MMI_TOUCH_SCREEN__
void mmi_gx_ninjaclimb_pen_down_hdlr(mmi_pen_point_struct pos);
void mmi_gx_ninjaclimb_pen_up_hdlr(mmi_pen_point_struct pos);
void mmi_gx_ninjaclimb_pen_move_hdlr(mmi_pen_point_struct pos);
#endif  //__MMI_TOUCH_SCREEN__

/************************************************************************/
/* Audio [Const]                                                        */
/************************************************************************/


#define  NINJABOUNCE_DVI   536

__align(2)
const U8 NinjaBounce_dvi[536] =
{
    0x77, 0xD7, 0x77, 0x77, 0x0E, 0x08, 0xB7, 0xB7, 0x08, 0x17, 0x8C, 0x08, 0x08, 0x08, 0x88, 0x80,
    0x00, 0x90, 0x19, 0x01, 0x90, 0x9C, 0x87, 0x3A, 0xB0, 0x18, 0x2C, 0x97, 0x1B, 0xA3, 0x2B, 0xB3,
    0x89, 0x7B, 0xA4, 0x1C, 0x82, 0x8C, 0x52, 0xD1, 0x2B, 0x85, 0x9B, 0x22, 0xA9, 0x42, 0xD0, 0x0A,
    0x13, 0x99, 0x23, 0xEB, 0x3B, 0x17, 0x9D, 0x13, 0xAA, 0x32, 0xD9, 0x38, 0x93, 0x9B, 0x03, 0xAC,
    0x64, 0xC9, 0x58, 0xB0, 0x29, 0xA2, 0x29, 0xA3, 0x8E, 0x22, 0x99, 0x21, 0xCB, 0x79, 0xC3, 0x3B,
    0xB3, 0x4B, 0xB2, 0x1D, 0x04, 0x9A, 0x02, 0x9B, 0x44, 0xDB, 0x33, 0xAC, 0x23, 0x9B, 0x23, 0xBD,
    0x42, 0xA8, 0x21, 0xEA, 0x70, 0xB8, 0x30, 0xA9, 0x22, 0xAC, 0x42, 0xA9, 0x20, 0xAA, 0x62, 0xD8,
    0x21, 0xB9, 0x22, 0x9A, 0x23, 0xBC, 0x32, 0xA9, 0x04, 0xBC, 0x27, 0x0E, 0x93, 0x2B, 0xC2, 0x4A,
    0xA2, 0x2A, 0xC1, 0x48, 0xF3, 0x49, 0xB8, 0x22, 0x9B, 0x14, 0x9C, 0x12, 0x0A, 0x83, 0x1F, 0xB4,
    0x49, 0xB8, 0x21, 0xAA, 0x33, 0xAB, 0x83, 0x1B, 0xA7, 0x4B, 0xA0, 0x20, 0x8A, 0x83, 0x9B, 0x83,
    0x59, 0xB0, 0x6F, 0xB8, 0x13, 0x1D, 0xB3, 0x3B, 0xB3, 0x49, 0xD8, 0x50, 0xC9, 0x04, 0x2D, 0xB2,
    0x48, 0xA9, 0x30, 0xA9, 0x03, 0xAC, 0x07, 0x3D, 0xC1, 0x21, 0xBA, 0x14, 0x8B, 0x94, 0x2B, 0xD5,
    0x40, 0x9B, 0x84, 0x3B, 0xB1, 0x39, 0xC0, 0x22, 0xCB, 0x87, 0x3C, 0xD1, 0x22, 0x8C, 0x83, 0x09,
    0xA1, 0x49, 0xE1, 0x12, 0x2D, 0xB1, 0x21, 0x8A, 0x80, 0x10, 0x88, 0x2B, 0xE5, 0x83, 0x3B, 0xA8,
    0x81, 0x02, 0x0B, 0x19, 0x70, 0x0C, 0x20, 0x1D, 0xC2, 0x31, 0x9D, 0x84, 0x19, 0xC0, 0x23, 0xAC,
    0xA7, 0x38, 0xAA, 0x04, 0x0B, 0xA2, 0x58, 0xCA, 0x96, 0x5B, 0xA9, 0x03, 0x1B, 0xB3, 0x49, 0xAA,
    0x86, 0x5D, 0xAA, 0x94, 0x3A, 0xB0, 0x30, 0x0B, 0xA4, 0x6E, 0xAA, 0xA5, 0x39, 0xA9, 0x22, 0x8B,
    0xB3, 0x79, 0xAA, 0xB7, 0x30, 0x8B, 0x94, 0x1B, 0xB2, 0x13, 0x8E, 0xD7, 0x22, 0x2D, 0xB1, 0x30,
    0xB9, 0xA4, 0x69, 0xC9, 0xB6, 0x49, 0x8A, 0xA3, 0x2A, 0xB1, 0x13, 0x1F, 0xF4, 0x85, 0x3B, 0xC0,
    0x31, 0x8B, 0xC3, 0x78, 0x8C, 0xD5, 0x12, 0x2B, 0xC2, 0x49, 0x89, 0x92, 0x6E, 0x8C, 0xD5, 0x12,
    0x0B, 0x93, 0x3A, 0xAB, 0x87, 0x6C, 0x0C, 0xB2, 0x31, 0xAB, 0x84, 0x4A, 0xE9, 0xA5, 0x6A, 0x1C,
    0xB1, 0x30, 0x99, 0xC3, 0x68, 0xAA, 0xD7, 0x21, 0x2C, 0xB1, 0x20, 0x2B, 0xD2, 0x79, 0x3D, 0xC1,
    0x02, 0x2B, 0xB1, 0x02, 0x2C, 0xF4, 0x22, 0x4E, 0xA9, 0x95, 0x2A, 0x89, 0x93, 0x3D, 0xF2, 0xB5,
    0x48, 0x0C, 0xB3, 0x30, 0x0D, 0x93, 0x7D, 0x2E, 0xE2, 0x04, 0x2C, 0xA0, 0x83, 0x8B, 0xE7, 0x85,
    0x6B, 0x9B, 0x93, 0x28, 0x0C, 0x12, 0x5F, 0x0C, 0xC2, 0x03, 0x1B, 0x88, 0x93, 0xBA, 0xC7, 0x94,
    0x49, 0x0B, 0x91, 0x81, 0x1A, 0x31, 0x5F, 0x2D, 0xB0, 0x95, 0x19, 0x19, 0x90, 0xA8, 0xC7, 0xA4,
    0x20, 0x2D, 0x88, 0xB2, 0x10, 0x91, 0x7B, 0x3C, 0x0A, 0xC3, 0x91, 0x20, 0x1A, 0x4C, 0xB8, 0xB5,
    0xA4, 0x39, 0x2A, 0xA9, 0xB3, 0xD7, 0x93, 0x10, 0x4B, 0x89, 0xA0, 0x83, 0x08, 0x7E, 0x2C, 0x19,
    0xB0, 0x92, 0x21, 0x2D, 0x5A, 0x0B, 0xB2, 0xB3, 0x31, 0x3D, 0x2D, 0x80, 0xB8, 0xA7, 0x10, 0x4A,
    0x1C, 0x08, 0xA1, 0x80, 0xA3, 0x7B, 0x1A, 0x09, 0xB2, 0xD3, 0x02, 0x98, 0x69, 0x8A, 0xA2, 0xD4,
    0x81, 0x82, 0xA9, 0x84, 0xE0, 0xB5, 0xB3, 0x92, 0x91, 0x08, 0xD3, 0xB2, 0xC7, 0xA3, 0x92, 0x88,
    0x01, 0xD1, 0x11, 0xB0, 0x82, 0x00, 0x0A, 0xA4, 0xA0, 0x78, 0x2D, 0x00, 0x3C, 0x18, 0x9A, 0x48,
    0x08, 0x1E, 0x82, 0x2A, 0x19, 0x88, 0x6A, 0x2B, 0x2B, 0xD1, 0x04, 0xBA, 0x24, 0x1A, 0x2F, 0x10,
    0xBA, 0x96, 0xB1, 0xB3, 0x02, 0x2A, 0x29, 0x8A
};

#define  NINJADOWN_DVI  1038

__align(2)
const U8 NinjaDown_dvi[1038] =
{
    0x77, 0xD7, 0x77, 0x77, 0x0E, 0x08, 0xB7, 0xB7, 0x08, 0x17, 0xC9, 0x80, 0x80, 0x08, 0x08, 0x80,
    0x80, 0x80, 0x08, 0x00, 0x08, 0x09, 0x08, 0x00, 0x00, 0x99, 0x19, 0x22, 0x81, 0xAC, 0x1B, 0x44,
    0x81, 0xDA, 0x19, 0x34, 0x92, 0xCC, 0x19, 0x53, 0x83, 0xBC, 0x89, 0x64, 0x80, 0xCA, 0x09, 0x43,
    0x92, 0xDA, 0x89, 0x32, 0x85, 0xCA, 0x0A, 0x43, 0x83, 0xEB, 0x8A, 0x43, 0x03, 0xDA, 0xAA, 0x34,
    0x02, 0xDB, 0x8B, 0x52, 0x02, 0xBB, 0x8D, 0x51, 0x02, 0xC9, 0x9B, 0x42, 0x13, 0xB8, 0x9F, 0x31,
    0x12, 0xD9, 0xAB, 0x41, 0x32, 0xBB, 0xBC, 0x50, 0x14, 0xB0, 0xAD, 0x38, 0x35, 0xA8, 0xAC, 0x38,
    0x23, 0xB1, 0xAF, 0x0A, 0x25, 0x90, 0xAC, 0x18, 0x34, 0x92, 0xBD, 0x09, 0x35, 0x82, 0xCB, 0x9A,
    0x53, 0x02, 0xEB, 0x89, 0x42, 0x02, 0xCA, 0x8B, 0x42, 0x13, 0xBA, 0xAD, 0x32, 0x15, 0xB8, 0x9D,
    0x30, 0x24, 0xB8, 0xAD, 0x20, 0x25, 0xA0, 0xAC, 0x29, 0x25, 0x90, 0xAD, 0x18, 0x43, 0x81, 0xBC,
    0x09, 0x63, 0x92, 0xBA, 0x8B, 0x44, 0x93, 0xCB, 0x8B, 0x34, 0x04, 0xB8, 0x8D, 0x41, 0x13, 0xBA,
    0x9D, 0x20, 0x32, 0xC0, 0xAD, 0x21, 0x15, 0x91, 0xBB, 0x39, 0x26, 0x90, 0xBC, 0x1B, 0x34, 0x03,
    0xBD, 0x0A, 0x53, 0x04, 0xCA, 0x0B, 0x41, 0x82, 0xD9, 0x89, 0x31, 0x05, 0x99, 0xAB, 0x22, 0x53,
    0xB8, 0xDD, 0x18, 0x42, 0x80, 0xAB, 0x20, 0x25, 0x82, 0xDC, 0x89, 0x21, 0x81, 0xC9, 0x09, 0x51,
    0x12, 0x89, 0xAC, 0x20, 0x14, 0xBC, 0x9B, 0x41, 0x44, 0xB0, 0x9B, 0x3A, 0x24, 0xB2, 0xCF, 0x08,
    0x33, 0x01, 0xBA, 0x9A, 0x35, 0x11, 0xDC, 0x9C, 0x31, 0x14, 0xA0, 0x8A, 0x38, 0x24, 0xD8, 0xBD,
    0x0A, 0x25, 0x82, 0x98, 0x09, 0x42, 0x82, 0xCC, 0x9E, 0x20, 0x32, 0x88, 0x88, 0x30, 0x34, 0xDB,
    0xEC, 0x19, 0x21, 0x03, 0x99, 0x18, 0x25, 0x80, 0xEC, 0x8B, 0x30, 0x14, 0x08, 0x8B, 0x38, 0x84,
    0xE0, 0x8C, 0x28, 0x43, 0x01, 0xB8, 0x89, 0x18, 0xF0, 0xB9, 0x19, 0x63, 0x33, 0x80, 0xCB, 0x99,
    0x00, 0x98, 0xB9, 0x49, 0x47, 0x01, 0xB9, 0x9F, 0x10, 0x23, 0xA8, 0xAB, 0x24, 0x32, 0xF8, 0xAB,
    0x38, 0x35, 0x81, 0xCA, 0x0B, 0x11, 0x81, 0xBB, 0x29, 0x47, 0x03, 0xE9, 0xBA, 0x2B, 0x34, 0x83,
    0xA9, 0x08, 0x15, 0xC1, 0x9F, 0x09, 0x33, 0x15, 0xA9, 0x9C, 0x88, 0x20, 0x10, 0x0A, 0x32, 0x26,
    0xB8, 0xDF, 0x88, 0x22, 0x14, 0x90, 0xAA, 0x08, 0x08, 0xB8, 0x88, 0x64, 0x23, 0xC8, 0xCC, 0x0A,
    0x52, 0x11, 0x90, 0xA9, 0x88, 0x09, 0xB0, 0x18, 0x37, 0x15, 0xC9, 0xBC, 0x1A, 0x52, 0x13, 0x90,
    0xAB, 0x99, 0x01, 0x09, 0x88, 0x46, 0x01, 0xB9, 0x9E, 0x19, 0x32, 0x17, 0xA9, 0xAC, 0x18, 0x42,
    0x21, 0xC8, 0xA8, 0xA8, 0x28, 0x8A, 0x40, 0x37, 0x93, 0xCC, 0xCB, 0x48, 0x32, 0x84, 0xC9, 0x9C,
    0x22, 0x20, 0x98, 0x80, 0x2B, 0x3A, 0xF3, 0x8B, 0x41, 0x04, 0xC1, 0x8C, 0x89, 0x23, 0x26, 0xB9,
    0xAD, 0x21, 0x31, 0x90, 0xEA, 0x88, 0x69, 0x83, 0x99, 0x98, 0x08, 0xE8, 0x32, 0x99, 0x42, 0x02,
    0xFB, 0x8D, 0x11, 0x60, 0x11, 0xB9, 0xAD, 0x20, 0x12, 0x13, 0xA8, 0xDC, 0x29, 0x13, 0x88, 0x11,
    0xA9, 0xBA, 0x82, 0x9C, 0x72, 0x16, 0xAA, 0x99, 0x9A, 0x43, 0x23, 0xF9, 0x1A, 0x00, 0x22, 0x90,
    0xFB, 0x3B, 0x25, 0x08, 0xA9, 0xDA, 0x39, 0x16, 0x80, 0xB9, 0xB9, 0x3A, 0x37, 0x88, 0x99, 0xA9,
    0x1E, 0x24, 0x00, 0x88, 0xBA, 0x9E, 0x24, 0x20, 0x82, 0xBB, 0xAF, 0x22, 0x31, 0x22, 0xEA, 0x9E,
    0x11, 0x32, 0x02, 0xDA, 0x9D, 0x21, 0x32, 0x82, 0xCC, 0x0B, 0x23, 0x42, 0xA0, 0xBD, 0x2B, 0x25,
    0x12, 0xC9, 0xBC, 0x30, 0x24, 0x12, 0xDB, 0xAC, 0x31, 0x32, 0x03, 0xEB, 0x8C, 0x21, 0x02, 0x92,
    0xDB, 0x2A, 0x14, 0x12, 0xD8, 0xBC, 0x31, 0x14, 0x01, 0xEA, 0x0B, 0x42, 0x11, 0xA0, 0xCC, 0x29,
    0x24, 0x00, 0xB9, 0xAE, 0x42, 0x12, 0x80, 0xEB, 0x0B, 0x33, 0x33, 0xB0, 0xCE, 0x08, 0x32, 0x12,
    0xD8, 0x8C, 0x28, 0x23, 0x01, 0xBE, 0x08, 0x31, 0x22, 0xF0, 0x0C, 0x11, 0x20, 0x80, 0xBC, 0x22,
    0x81, 0x82, 0xDD, 0x29, 0x25, 0x91, 0xD8, 0x8C, 0x41, 0x12, 0x99, 0xCC, 0x10, 0x24, 0x81, 0xDB,
    0x8A, 0x53, 0x11, 0xC9, 0x8C, 0x30, 0x24, 0xA0, 0xAE, 0x08, 0x33, 0x03, 0xFB, 0x8A, 0x32, 0x23,
    0xD8, 0xAC, 0x20, 0x43, 0xA2, 0xBC, 0x09, 0x33, 0x23, 0xDC, 0x89, 0x31, 0x12, 0xD9, 0x9B, 0x42,
    0x23, 0xC9, 0xAB, 0x30, 0x16, 0xA8, 0xAB, 0x30, 0x16, 0xC8, 0x8B, 0x21, 0x25, 0xD8, 0x9C, 0x22,
    0x24, 0xB8, 0xAF, 0x20, 0x53, 0xA1, 0xAD, 0x19, 0x53, 0x82, 0xDB, 0x8A, 0x42, 0x22, 0xC9, 0xAB,
    0x31, 0x24, 0xA8, 0xBC, 0x38, 0x24, 0xA1, 0xCA, 0x2A, 0x32, 0x98, 0xC0, 0x49, 0x01, 0xCA, 0x90,
    0x51, 0x13, 0x9E, 0x98, 0x30, 0x23, 0xBD, 0x98, 0x62, 0x01, 0xBA, 0x9A, 0x61, 0x82, 0x8A, 0xAA,
    0x52, 0xA1, 0x89, 0x88, 0x15, 0xD9, 0x19, 0x38, 0x17, 0xBB, 0x0B, 0x50, 0x15, 0xBB, 0x9B, 0x61,
    0x04, 0xA9, 0xBA, 0x50, 0x83, 0x8A, 0x9A, 0x50, 0xB3, 0x0C, 0x00, 0x43, 0xE0, 0x8B, 0x20, 0x16,
    0xB8, 0x9C, 0x30, 0x16, 0xB9, 0xAA, 0x40, 0x04, 0x99, 0xAA, 0x41, 0x91, 0x0A, 0x0B, 0x27, 0xB9,
    0xA8, 0x4A, 0x06, 0x99, 0xB9, 0x58, 0x83, 0x89, 0xDB, 0x31, 0x81, 0x02, 0x9C, 0x81, 0x1C, 0x13,
    0x38, 0xF2, 0x0C, 0x00, 0x34, 0xDA, 0x88, 0x28, 0x05, 0x8C, 0x90, 0x40, 0xC1, 0x09, 0x01, 0x43,
    0xEB, 0x88, 0x48, 0x84, 0xAA, 0xA9, 0x71, 0x91, 0x88, 0x9A, 0x13, 0x0A, 0x83, 0x4B, 0xD0, 0x19,
    0x10, 0x05, 0xBB, 0x88, 0x70, 0xB2, 0x19, 0xAA, 0x26, 0xAC, 0x02, 0x49, 0xC3, 0x0B, 0xA0, 0x45,
    0xB9, 0xA0, 0x3A, 0x87, 0x1A, 0x98, 0x21, 0xDB, 0x11, 0x48, 0x94, 0x8D, 0x8A, 0x53, 0x90, 0xB8,
    0x2B, 0x03, 0x30, 0xAD, 0x12, 0x0B, 0xC3, 0x68, 0xC1, 0x00, 0x8C, 0x04, 0x29, 0xD2, 0x29, 0xD9,
    0x33, 0x0B, 0xA4, 0x1D, 0xA1, 0x51, 0xA9, 0x01, 0x0B, 0xA4, 0x4A, 0xB0, 0x22, 0x9D, 0x84, 0x2A,
    0xB1, 0x48, 0xA9, 0x82, 0x2D, 0x94, 0x10, 0xBD, 0x04, 0x20, 0xF2, 0x19, 0x80, 0x12, 0x0B, 0xA4,
    0x19, 0xEA, 0x23, 0x11, 0xF2, 0x1B, 0x00, 0x24, 0x0D, 0x90, 0x48, 0xB9, 0x12, 0x28, 0xE4, 0x1A,
    0x80, 0x15, 0x9B, 0xB1, 0x78, 0xA8, 0x11, 0x2B, 0xC4, 0x29, 0x99, 0x34, 0x0D, 0xA1, 0x4A, 0xA9,
    0x24, 0x0B, 0xD3, 0x2A, 0x80, 0x14, 0x8C, 0xB1, 0x59, 0x98, 0x02, 0x0A, 0xC1, 0x28, 0x08, 0x82,
    0x09, 0xA9, 0x80, 0x6D, 0x81, 0x80, 0x8F, 0x01, 0x41, 0xC9, 0x81, 0x1C, 0xB4, 0x50, 0x9A, 0x83,
    0x1F, 0xA1, 0x30, 0x89, 0x94, 0x0D, 0xB0, 0x34, 0x0A, 0xD0, 0x39, 0x90, 0x83, 0x2B, 0xD1, 0x18,
    0x2A, 0x05, 0x89, 0xAA, 0x10, 0x29, 0xA3, 0x06, 0xCB, 0xC9, 0x34, 0x02, 0xF8, 0x29, 0x88, 0x11,
    0x5B, 0xA1, 0x99, 0x2D, 0x04, 0x08, 0x8C, 0x03, 0x98, 0xBC, 0x27, 0x00, 0xFA, 0x10, 0x20, 0xA1,
    0x18, 0x8A, 0xD0, 0x78, 0x18, 0xB1, 0x1C, 0x91, 0x13, 0x1E, 0xA2, 0x10, 0x8D, 0x84, 0x38, 0xEB,
    0x03, 0x19, 0xF1, 0x21, 0x09, 0xD1, 0x38, 0x88, 0xA3, 0x3E, 0xB1, 0x02, 0x1F, 0x82, 0x28, 0x8D,
    0x81, 0x20, 0xA8, 0x83, 0x0B, 0xCA, 0x16, 0x08, 0xB9, 0x11, 0x28, 0xF8, 0x21, 0x28, 0xE0, 0x08,
    0x18, 0xB2, 0x41, 0x8A, 0xF0, 0x49, 0x10, 0xB1, 0x3C, 0x89, 0x95, 0x4C, 0xA0, 0x82 
};

#define  NINJAFALL_DVI  988

__align(2)
const U8 NinjaFall_dvi[988] =
{  
    0x77, 0xD7, 0x77, 0x77, 0x0E, 0x08, 0xB7, 0xB7, 0x08, 0x17, 0xAB, 0x80, 0x80, 0x80, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x88, 0x80, 0x08, 0x00, 0x90, 0x10, 0xA8, 0x08, 0x11, 0x00,
    0xC0, 0x2C, 0x23, 0x1F, 0x10, 0x1C, 0x10, 0x3F, 0xB2, 0x5D, 0x88, 0x5C, 0x98, 0x28, 0xC8, 0x04,
    0xAA, 0x86, 0x2B, 0x91, 0x5B, 0xA8, 0x30, 0xE8, 0x83, 0xA8, 0xC5, 0xB4, 0x28, 0xC3, 0x3B, 0x95,
    0x1D, 0x12, 0x8D, 0x51, 0x9B, 0x58, 0x19, 0x2D, 0x59, 0x0C, 0x91, 0x92, 0xC0, 0x95, 0x28, 0x2D,
    0x91, 0x3A, 0xB9, 0x87, 0x2B, 0x18, 0x5B, 0xE8, 0x94, 0xA1, 0x01, 0x1A, 0x00, 0xC8, 0x95, 0x90,
    0x01, 0x99, 0x82, 0xE2, 0x82, 0xA1, 0x90, 0x93, 0xE2, 0x01, 0xB2, 0x18, 0x10, 0x3B, 0x2D, 0x80,
    0xF2, 0x02, 0x4A, 0x3D, 0x4B, 0x09, 0x99, 0x93, 0x91, 0xA0, 0x20, 0xA1, 0xD0, 0xB5, 0xB5, 0x92,
    0x7C, 0x1A, 0x5A, 0x1C, 0x00, 0xC0, 0x93, 0xB1, 0x83, 0xA0, 0x21, 0x0B, 0x49, 0x3B, 0x2C, 0x08,
    0xA8, 0xA5, 0xA1, 0x82, 0x88, 0x00, 0x81, 0x4B, 0x99, 0x30, 0xF9, 0x07, 0x2F, 0x28, 0x0E, 0x84,
    0x9B, 0x86, 0xA9, 0x84, 0xB0, 0x41, 0x0B, 0x5A, 0x2A, 0x1C, 0x01, 0xD8, 0x03, 0xC0, 0x40, 0x98,
    0x5C, 0x19, 0x2B, 0x00, 0x9A, 0x03, 0xB8, 0x40, 0x88, 0x3C, 0x49, 0x1D, 0x28, 0x8A, 0x10, 0xE2,
    0x81, 0x01, 0x1A, 0x29, 0x80, 0x5F, 0x3A, 0x1E, 0x11, 0x9C, 0x04, 0xB9, 0x84, 0xC1, 0x20, 0xC1,
    0x91, 0x93, 0xD0, 0x22, 0xB0, 0x5C, 0x00, 0x0D, 0x03, 0xCA, 0x04, 0xB0, 0x28, 0x92, 0x0C, 0x13,
    0xAB, 0x31, 0xF2, 0x80, 0xB4, 0xB1, 0x04, 0x99, 0x79, 0x89, 0x19, 0x91, 0xC1, 0x11, 0x58, 0x2F,
    0x29, 0x1B, 0x49, 0x99, 0x6A, 0x09, 0x3B, 0x00, 0x9A, 0x32, 0x8B, 0x19, 0x23, 0xAF, 0x43, 0x9B,
    0x7B, 0x80, 0x8B, 0x86, 0xC8, 0x22, 0x09, 0x3E, 0x39, 0x8C, 0x11, 0xB0, 0x28, 0x11, 0x1E, 0x49,
    0x1A, 0x3C, 0x80, 0xC9, 0x96, 0xB1, 0x11, 0x18, 0x8A, 0x10, 0x91, 0x2D, 0x92, 0xA8, 0x40, 0xA0,
    0x5F, 0x88, 0x1A, 0x92, 0xD1, 0x11, 0xB1, 0xC1, 0x84, 0xF2, 0x01, 0xA2, 0x89, 0x03, 0xB9, 0x7A,
    0x00, 0x2F, 0x10, 0xAA, 0x12, 0xB1, 0x98, 0x86, 0xC0, 0x38, 0x81, 0x8C, 0x22, 0x0A, 0x5F, 0x09,
    0x89, 0x01, 0xC1, 0x00, 0xA4, 0xD1, 0x21, 0x98, 0x88, 0x11, 0xA8, 0x39, 0x01, 0x8C, 0x30, 0xE2,
    0x29, 0x11, 0x9D, 0x04, 0xC8, 0x30, 0x91, 0xBB, 0x17, 0xA9, 0x28, 0xA2, 0xF1, 0x02, 0x01, 0x3F,
    0x19, 0x09, 0x6F, 0x2A, 0x2C, 0x29, 0x09, 0x0A, 0x83, 0xC0, 0x10, 0x91, 0xA0, 0xC4, 0x82, 0xC1,
    0xA4, 0x91, 0x29, 0x12, 0x9E, 0x31, 0x98, 0xA9, 0x84, 0x91, 0xB2, 0x2C, 0x23, 0xCB, 0x81, 0xC3,
    0x87, 0x1D, 0x81, 0x28, 0x5F, 0x0A, 0x19, 0x01, 0x8A, 0x3A, 0x30, 0x1D, 0x1A, 0x00, 0x49, 0x6C,
    0x1E, 0x49, 0x3A, 0x2E, 0x4A, 0x19, 0x1A, 0x4B, 0x18, 0x2B, 0x3B, 0x3A, 0x5B, 0x8A, 0x4C, 0x28,
    0x0A, 0x1B, 0x40, 0x89, 0xA8, 0x39, 0x52, 0x8C, 0x3C, 0x11, 0x8B, 0x81, 0x19, 0x11, 0xD8, 0xA0,
    0x97, 0xB8, 0xB7, 0xC4, 0x02, 0xD1, 0x80, 0x84, 0xA8, 0x00, 0x01, 0x19, 0xF2, 0xA0, 0xA7, 0xE3,
    0xD5, 0xB4, 0xA4, 0xC4, 0x98, 0x23, 0xC0, 0x98, 0x03, 0x88, 0x10, 0x0F, 0x40, 0x09, 0x9A, 0x58,
    0x29, 0x2B, 0x0C, 0x48, 0x00, 0xBA, 0x39, 0x96, 0xB0, 0xB1, 0xA5, 0xA4, 0xC2, 0xA1, 0x94, 0xA2,
    0xA0, 0x48, 0x28, 0x4F, 0x2C, 0x4A, 0x2A, 0x1B, 0x2A, 0x20, 0xA9, 0xB9, 0x87, 0xA2, 0xD2, 0x90,
    0x84, 0xC2, 0xC2, 0x00, 0x21, 0x08, 0x0F, 0x20, 0x00, 0x9A, 0x3B, 0x22, 0xC1, 0xF8, 0x11, 0x83,
    0x8A, 0x9A, 0x41, 0x40, 0x9B, 0x2F, 0x30, 0x99, 0xA8, 0x80, 0x95, 0xA3, 0xF1, 0x28, 0x21, 0x1C,
    0x2D, 0x38, 0x0A, 0x88, 0x9A, 0x32, 0xA7, 0xE8, 0x10, 0x83, 0x09, 0x1B, 0x4C, 0x38, 0xB0, 0xF9,
    0x94, 0xB4, 0xB2, 0xA1, 0x11, 0x04, 0xBB, 0x4D, 0x21, 0xB9, 0xC1, 0x93, 0x84, 0xA1, 0xBB, 0x71,
    0x01, 0x0C, 0x09, 0x00, 0x83, 0xD1, 0xA9, 0x33, 0x58, 0x3D, 0x1E, 0x3A, 0x10, 0xB8, 0x98, 0x13,
    0x01, 0xA9, 0x1F, 0x40, 0x90, 0xB9, 0x82, 0x94, 0xB2, 0xC1, 0x59, 0x49, 0x0A, 0x9B, 0x95, 0xB3,
    0x00, 0x29, 0x3D, 0x28, 0xAB, 0x81, 0x96, 0xD1, 0x92, 0xB2, 0x20, 0x70, 0x0D, 0x09, 0xA4, 0xB4,
    0x98, 0x38, 0x38, 0x98, 0xD9, 0x08, 0x72, 0x88, 0xAA, 0x4A, 0x31, 0xA8, 0xA8, 0xCA, 0x87, 0x03,
    0x8B, 0x8C, 0x83, 0x95, 0x00, 0x8A, 0x0E, 0x03, 0x96, 0x8A, 0x2B, 0x80, 0x97, 0xA1, 0x0A, 0x4A,
    0x01, 0xC3, 0xA8, 0x3B, 0x22, 0xC5, 0xB1, 0x3B, 0x4A, 0xB6, 0xC3, 0x90, 0x4B, 0x20, 0xC3, 0xB0,
    0x3C, 0x5A, 0x82, 0xD1, 0x89, 0x4A, 0x82, 0xD4, 0x80, 0x3A, 0x08, 0xB2, 0x11, 0x3B, 0x8F, 0x92,
    0x05, 0x1A, 0x8D, 0xB2, 0x87, 0x00, 0x8C, 0x80, 0x84, 0x00, 0x0B, 0x99, 0x04, 0x38, 0x2D, 0x99,
    0xA0, 0x79, 0x28, 0xA8, 0xC0, 0x4A, 0x58, 0xB1, 0xB0, 0x2A, 0x28, 0x96, 0x80, 0x0C, 0x09, 0x84,
    0x30, 0x0D, 0xA9, 0x83, 0x50, 0x2B, 0xA8, 0xB1, 0x6D, 0x29, 0xB2, 0xB1, 0x1C, 0x10, 0x87, 0x09,
    0x8C, 0x91, 0x24, 0x19, 0xBB, 0xA1, 0x70, 0x3A, 0x98, 0x08, 0x2D, 0x89, 0x04, 0x10, 0xBB, 0xF1,
    0x12, 0x40, 0xB8, 0xD1, 0x39, 0x08, 0x95, 0x18, 0x0D, 0x90, 0x12, 0x6A, 0x8A, 0xB0, 0x30, 0x3B,
    0xB4, 0x12, 0x0F, 0xB8, 0x15, 0x39, 0xC9, 0xB0, 0x30, 0x11, 0xB4, 0x89, 0x8C, 0xB4, 0x04, 0x18,
    0xD2, 0x90, 0x2D, 0x81, 0x14, 0x2B, 0xCC, 0x81, 0x51, 0x90, 0xA0, 0x2A, 0x0A, 0x96, 0x38, 0x0B,
    0xE2, 0x18, 0x09, 0x96, 0x81, 0xC9, 0xA1, 0x42, 0x18, 0xC0, 0x09, 0x1A, 0xA5, 0x21, 0x89, 0xD3,
    0x2B, 0x0D, 0x15, 0x20, 0xCB, 0xA8, 0x58, 0x10, 0xA2, 0x1A, 0xBB, 0x12, 0x79, 0x90, 0x82, 0x0B,
    0xBB, 0x71, 0x4A, 0xB3, 0x09, 0xBD, 0x85, 0x40, 0x88, 0x98, 0x0B, 0x88, 0x62, 0x00, 0xD1, 0x98,
    0x2C, 0x93, 0x53, 0xBA, 0xA2, 0x2F, 0x90, 0x12, 0x3A, 0xB1, 0x09, 0x9E, 0x93, 0x34, 0xA0, 0x88,
    0x1F, 0x8A, 0x52, 0x08, 0x91, 0x0E, 0xA8, 0x23, 0x01, 0xB2, 0x8C, 0x99, 0x22, 0x20, 0xB4, 0x80,
    0x8F, 0xB2, 0x68, 0x00, 0x10, 0x9C, 0xC1, 0x30, 0x09, 0x04, 0x09, 0xB0, 0x2F, 0x8A, 0x04, 0x22,
    0xD0, 0x99, 0x8B, 0x42, 0x40, 0x92, 0xBB, 0xF9, 0x81, 0x14, 0x20, 0xC9, 0x98, 0x19, 0x38, 0x02,
    0x91, 0xC0, 0x1A, 0xA9, 0x73, 0x0D, 0x31, 0x3A, 0xB4, 0x8F, 0xB9, 0x34, 0x21, 0x81, 0x9E, 0xA9,
    0x11, 0x48, 0x05, 0x89, 0xE8, 0x09, 0x00, 0x13, 0xB3, 0x80, 0x0E, 0x08, 0x88, 0x30, 0x81, 0x50,
    0xD9, 0x98, 0xD1, 0x21, 0x02, 0x22, 0xBA, 0x1F, 0xAA, 0x79, 0x92, 0x50, 0xB9, 0x89, 0xC0, 0x32,
    0x39, 0xA3, 0xA9, 0xE2, 0x2A, 0x88, 0x14, 0x08, 0x68, 0x1E, 0x08, 0x9A, 0x10, 0x31, 0x01, 0xF3,
    0xB9, 0x01, 0x38, 0x90, 0x12, 0x19, 0x30, 0x8F, 0x9D, 0x11, 0x23, 0x79, 0xB8, 0x98, 0xB8, 0x60,
    0x89, 0x13, 0xB8, 0x7A, 0x89, 0xC1, 0x10, 0x1B, 0x79, 0xB3, 0x29, 0x0A
};

#define  NINJAHIT_DVI   764

__align(2)
const U8 NinjaHit_dvi[764] =
{
    0x77, 0xD7, 0x77, 0x77, 0x0E, 0x08, 0xB7, 0xB7, 0x08, 0x17, 0x8C, 0x08, 0x08, 0x88, 0x00, 0x08,
    0x88, 0x80, 0x80, 0x80, 0x88, 0x00, 0x80, 0xA8, 0x09, 0x84, 0xB0, 0xF1, 0x48, 0x04, 0x0A, 0xBA,
    0x6A, 0x95, 0x98, 0xB0, 0x89, 0x20, 0x71, 0xE8, 0x2B, 0x16, 0xA8, 0x10, 0x92, 0x0E, 0x44, 0xC8,
    0x0B, 0x81, 0x98, 0x15, 0xD8, 0x99, 0x31, 0x25, 0xA8, 0xAA, 0x28, 0x35, 0x84, 0xDE, 0x19, 0x22,
    0x00, 0xCB, 0x0C, 0x53, 0x82, 0xAA, 0x08, 0x20, 0x14, 0x98, 0xA8, 0xDF, 0x11, 0x14, 0xC9, 0x8A,
    0x18, 0x27, 0x99, 0xBA, 0x41, 0x13, 0xA8, 0x9C, 0x80, 0x98, 0x32, 0xC2, 0x9E, 0x08, 0x71, 0xA3,
    0x2B, 0x0F, 0x33, 0x91, 0xBA, 0x0A, 0x21, 0x99, 0x28, 0xD9, 0x9B, 0x43, 0x25, 0x92, 0xCD, 0x40,
    0x85, 0xA0, 0x9A, 0x10, 0x91, 0xAA, 0x20, 0xC8, 0x1B, 0x35, 0x10, 0x00, 0x9A, 0x72, 0x84, 0xBA,
    0x09, 0x11, 0xFA, 0x8B, 0x43, 0xC8, 0x0A, 0x14, 0x00, 0x21, 0x80, 0x28, 0x98, 0x2A, 0x82, 0xDC,
    0xEC, 0x1A, 0x25, 0xC9, 0x0A, 0x14, 0x00, 0x02, 0x88, 0x20, 0x99, 0x49, 0xA1, 0xAD, 0xAA, 0x8D,
    0x34, 0xE8, 0x1A, 0x13, 0x18, 0x14, 0xB8, 0x10, 0x13, 0x88, 0xEA, 0x0A, 0xA0, 0x9D, 0x01, 0xAC,
    0x72, 0xA1, 0x1B, 0x26, 0x98, 0x19, 0x01, 0x01, 0xC0, 0x9B, 0x80, 0x80, 0xD8, 0x9D, 0x63, 0xA0,
    0x1A, 0x23, 0x09, 0x12, 0x9A, 0x72, 0xA1, 0xAB, 0x88, 0x28, 0xA5, 0xBE, 0x32, 0xB2, 0x19, 0xA3,
    0x1C, 0x27, 0xB8, 0x2A, 0x12, 0x08, 0xB9, 0x1D, 0x14, 0x9C, 0x20, 0xEA, 0x38, 0x83, 0xAC, 0x13,
    0xC8, 0x20, 0x02, 0x31, 0xE0, 0x0B, 0x24, 0x21, 0x92, 0xFF, 0x3A, 0x23, 0xBA, 0x9B, 0x28, 0x14,
    0x9A, 0x31, 0xA1, 0x20, 0xA2, 0x72, 0x07, 0xDC, 0x29, 0x04, 0xB9, 0x9A, 0x10, 0x23, 0xB9, 0x09,
    0x32, 0x25, 0xB8, 0x69, 0x05, 0xDA, 0x29, 0x83, 0xAC, 0x00, 0xA9, 0x30, 0xB1, 0x0D, 0x34, 0x83,
    0xBA, 0x61, 0x14, 0xC9, 0x19, 0x81, 0x8C, 0x01, 0xBE, 0x41, 0xB2, 0x9D, 0x43, 0x81, 0x99, 0x21,
    0x23, 0xA0, 0xAB, 0x80, 0x28, 0xF3, 0xCF, 0x41, 0x91, 0x9C, 0x30, 0x13, 0x98, 0x89, 0x30, 0x23,
    0x98, 0xDD, 0x1A, 0x05, 0xCC, 0x20, 0x92, 0x9B, 0x42, 0x01, 0x00, 0x99, 0x38, 0x24, 0x11, 0xEF,
    0x1B, 0x24, 0xC8, 0x89, 0x80, 0x30, 0x15, 0xB9, 0x19, 0x21, 0x12, 0xBA, 0x30, 0xFE, 0x2B, 0x16,
    0xC9, 0x19, 0x81, 0x20, 0x05, 0xBA, 0x19, 0x33, 0xA2, 0xAD, 0x11, 0xFA, 0x39, 0x05, 0xBC, 0x30,
    0x83, 0x1A, 0x33, 0xAA, 0x1A, 0x41, 0xA3, 0xCF, 0x11, 0xC9, 0x49, 0x84, 0xBD, 0x52, 0x92, 0x8A,
    0x02, 0x10, 0x88, 0x0A, 0x83, 0xBF, 0x40, 0xB0, 0x2B, 0x84, 0x9D, 0x44, 0x90, 0x0A, 0x02, 0x00,
    0xA1, 0x9A, 0x85, 0xBE, 0x50, 0x90, 0x0B, 0x81, 0x1A, 0x36, 0xB8, 0x2B, 0x15, 0x89, 0x90, 0x0A,
    0x94, 0xBE, 0x32, 0xE0, 0x19, 0x82, 0x0B, 0x26, 0xB9, 0x59, 0x82, 0x0A, 0x00, 0x0A, 0x81, 0xAE,
    0x32, 0xFA, 0x29, 0x83, 0x9A, 0x14, 0xA9, 0x63, 0xA1, 0x0A, 0x91, 0x1A, 0x04, 0x9F, 0x20, 0xC9,
    0x49, 0x82, 0x8B, 0x12, 0x0B, 0x37, 0xC8, 0x19, 0x92, 0x09, 0x93, 0xBC, 0x31, 0xDC, 0x61, 0xA1,
    0x0B, 0x83, 0x2A, 0x27, 0xCB, 0x18, 0x12, 0x88, 0xC8, 0x0A, 0x06, 0xDA, 0x41, 0xB1, 0x1B, 0x03,
    0x1A, 0x14, 0xCB, 0x39, 0x21, 0x20, 0xED, 0x2A, 0x05, 0xBA, 0x41, 0xC0, 0x19, 0x03, 0x88, 0xA3,
    0xAC, 0x53, 0xA1, 0x19, 0xD8, 0x2B, 0x25, 0xAC, 0x30, 0xC9, 0x58, 0x81, 0x2A, 0x92, 0x9E, 0x34,
    0xC0, 0x89, 0x01, 0x89, 0x01, 0x89, 0x81, 0x9F, 0x63, 0xB0, 0x3A, 0x83, 0x8E, 0x43, 0xC8, 0x1A,
    0x12, 0xAA, 0x08, 0x01, 0xB2, 0x9E, 0x35, 0xD0, 0x29, 0x83, 0x0B, 0x43, 0xDA, 0x39, 0x82, 0xAC,
    0x10, 0x11, 0xC8, 0x8D, 0x26, 0xB8, 0x39, 0x92, 0x1A, 0x15, 0xBB, 0x38, 0x82, 0xAD, 0x18, 0x21,
    0xF9, 0x0D, 0x25, 0xB9, 0x28, 0x92, 0x08, 0x14, 0xA8, 0x9A, 0x11, 0x91, 0xDB, 0x38, 0xF8, 0x1F,
    0x24, 0xBA, 0x29, 0x03, 0x08, 0x11, 0x90, 0x9A, 0x89, 0x24, 0xFA, 0x1B, 0xC1, 0x1C, 0x17, 0xB9,
    0x28, 0x12, 0x00, 0x00, 0x89, 0x08, 0x9A, 0x41, 0xFA, 0x0A, 0xB1, 0x3A, 0x87, 0x9A, 0x32, 0x91,
    0x48, 0x83, 0x9A, 0x10, 0xBC, 0x40, 0xB8, 0x8E, 0x99, 0x61, 0xA2, 0x8C, 0x34, 0xA0, 0x39, 0x93,
    0x8B, 0x14, 0xDC, 0x18, 0x81, 0xBA, 0x89, 0x61, 0x93, 0x8C, 0x62, 0x80, 0x28, 0xC0, 0x1A, 0x04,
    0xCA, 0x88, 0x89, 0x19, 0x82, 0x18, 0x83, 0x0C, 0x65, 0x81, 0x10, 0xDA, 0x1A, 0x13, 0xAA, 0xDB,
    0xBB, 0x73, 0x92, 0x8A, 0x12, 0x98, 0x54, 0x92, 0x99, 0x88, 0x08, 0xA9, 0x20, 0xFB, 0xBF, 0x53,
    0xB2, 0x9B, 0x53, 0x90, 0x20, 0x11, 0xC9, 0x49, 0x03, 0xAF, 0x18, 0x92, 0xAD, 0x41, 0xA2, 0x9D,
    0x43, 0x91, 0x0A, 0x32, 0xB0, 0x1A, 0x16, 0xCB, 0x0A, 0x03, 0xDB, 0x38, 0x93, 0xAF, 0x42, 0x83,
    0xAA, 0x40, 0x83, 0x9B, 0x33, 0xE8, 0x9B, 0x23, 0xEA, 0x2A, 0x84, 0xAC, 0x50, 0x02, 0xA9, 0x20,
    0x03, 0x99, 0x22, 0xC1, 0xBE, 0x42, 0xD0, 0x0B, 0x14, 0xDB, 0x48, 0x13, 0xBB, 0x48, 0x03, 0x9A,
    0x30, 0xB1, 0x9F, 0x41, 0xC0, 0x8B, 0x33, 0xEA, 0x39, 0x15, 0xC9, 0x29, 0x14, 0xB9, 0x28, 0x92,
    0xAD, 0x41, 0xA1, 0x8D, 0x31, 0xB0, 0x1A, 0x26, 0xC9, 0x29, 0x15, 0xCA, 0x18, 0x82, 0xAA, 0x29,
    0x92, 0x8A, 0x31, 0x81, 0x49, 0x44, 0xC9, 0x39, 0x06, 0xDB, 0x18, 0x92
};

#define  NINJAUP_DOWN_DVI  616

__align(2)
const U8 NinjaUp_down_dvi[616] =
{
    0x77, 0xD7, 0x77, 0x77, 0x0E, 0x08, 0xB7, 0xB7, 0x08, 0x17, 0x8C, 0x39, 0x99, 0xB2, 0x40, 0x0D,
    0x95, 0x19, 0x8B, 0x92, 0x70, 0x90, 0xA0, 0x1B, 0x88, 0x26, 0x88, 0xB9, 0x89, 0x29, 0x25, 0x81,
    0xAA, 0xAB, 0x39, 0x26, 0x00, 0xB9, 0xAA, 0x4A, 0x83, 0x21, 0xAB, 0xB0, 0x31, 0xBD, 0x92, 0x70,
    0x91, 0xC4, 0x0D, 0x89, 0x15, 0x30, 0xE9, 0x99, 0x29, 0x04, 0x13, 0xAC, 0xD9, 0x30, 0x48, 0xA4,
    0x09, 0xAC, 0x82, 0x60, 0x90, 0x91, 0x0B, 0xA8, 0x25, 0x19, 0x08, 0x0A, 0x0C, 0xC5, 0x41, 0x0A,
    0xD1, 0x11, 0x2B, 0xB3, 0x11, 0x0C, 0x92, 0x48, 0xBB, 0x95, 0x68, 0x98, 0xA8, 0x3B, 0x01, 0x17,
    0x8A, 0xCB, 0x10, 0x41, 0x01, 0xB8, 0xAA, 0x1A, 0x21, 0x24, 0x90, 0xAA, 0x9E, 0x88, 0x25, 0x39,
    0xF8, 0x08, 0x09, 0x22, 0x99, 0xE2, 0x39, 0x89, 0x04, 0x99, 0x08, 0x0B, 0xA5, 0x10, 0x18, 0x8A,
    0xA7, 0x39, 0xB8, 0x4C, 0xA3, 0x05, 0x1D, 0xC9, 0x83, 0x40, 0x18, 0xA0, 0xE8, 0x38, 0x2C, 0x87,
    0x80, 0x0C, 0x99, 0x42, 0x02, 0xA8, 0x9C, 0x0B, 0x35, 0x12, 0xD8, 0xAB, 0x39, 0x34, 0x01, 0xDA,
    0x8A, 0x20, 0x11, 0x03, 0xB9, 0xA8, 0x8A, 0x30, 0x14, 0x8A, 0x90, 0xBC, 0x8E, 0xB2, 0x60, 0x32,
    0xE1, 0x9A, 0x9C, 0x41, 0x35, 0xC9, 0x9A, 0x8A, 0x50, 0x14, 0x99, 0xBA, 0x88, 0x49, 0x34, 0x88,
    0xAE, 0xB1, 0x50, 0x22, 0xC1, 0x8C, 0x19, 0x04, 0x00, 0xD8, 0x8A, 0x42, 0x90, 0xA8, 0x09, 0x80,
    0x32, 0x9B, 0xFB, 0x40, 0x18, 0xA0, 0x01, 0x8F, 0x80, 0x03, 0x09, 0xA2, 0x9C, 0x1A, 0x07, 0x18,
    0xA8, 0xC8, 0x48, 0x21, 0x90, 0xA8, 0xAC, 0x74, 0x80, 0xA1, 0x8A, 0x2B, 0x96, 0x21, 0x9B, 0xB0,
    0x41, 0x1A, 0xA4, 0x09, 0x99, 0x03, 0xEB, 0x03, 0x5D, 0x9A, 0xC2, 0x21, 0x5A, 0x0A, 0xE9, 0x92,
    0x50, 0x1A, 0x98, 0xC2, 0x00, 0x7B, 0x89, 0xB2, 0x01, 0x4A, 0x1A, 0xB3, 0x84, 0x8E, 0x90, 0x04,
    0x21, 0x8F, 0x98, 0x14, 0x00, 0xBA, 0x80, 0x70, 0x88, 0xC1, 0x18, 0x20, 0x81, 0x0C, 0x89, 0x06,
    0x19, 0xAA, 0x38, 0x18, 0xB3, 0x89, 0xAD, 0x34, 0x2B, 0xC5, 0x88, 0xAA, 0x34, 0x89, 0xD1, 0x2D,
    0x82, 0x22, 0xF9, 0x28, 0x09, 0x13, 0xAC, 0x02, 0x0A, 0x86, 0x8A, 0xA1, 0x4A, 0x94, 0x0B, 0xC0,
    0x3B, 0x87, 0x1A, 0xA8, 0x1A, 0x87, 0x88, 0x80, 0x0B, 0x34, 0x8A, 0x08, 0xDB, 0x63, 0x91, 0x88,
    0xB0, 0x3A, 0x16, 0xA9, 0x80, 0x8A, 0x70, 0x91, 0x8B, 0x82, 0x99, 0x44, 0xC8, 0x19, 0x11, 0xAA,
    0x03, 0xC8, 0x50, 0x0E, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x47, 0x9C, 0x10, 0xC1, 0x01,
    0x83, 0xAC, 0x6B, 0x88, 0x1A, 0x92, 0xC9, 0x25, 0x81, 0xAE, 0x21, 0x80, 0x20, 0xB2, 0xBF, 0x61,
    0x02, 0xAB, 0x00, 0x82, 0x12, 0x94, 0xF8, 0x7D, 0x18, 0xA8, 0x00, 0x28, 0x99, 0xD4, 0xB3, 0x39,
    0x93, 0x80, 0x09, 0xF3, 0x7F, 0x39, 0x0D, 0xC0, 0x87, 0x88, 0x2A, 0x3A, 0x82, 0xD8, 0x90, 0x51,
    0x00, 0xAB, 0x89, 0x34, 0x91, 0xCB, 0x2A, 0x24, 0x88, 0xCB, 0x29, 0x84, 0x81, 0x99, 0x3A, 0x8B,
    0x93, 0x96, 0x92, 0x8F, 0x28, 0x12, 0xF2, 0x99, 0x30, 0x42, 0xAB, 0xDA, 0x13, 0x14, 0x0A, 0x0F,
    0x00, 0x93, 0xB1, 0x19, 0x5A, 0x88, 0xC3, 0xA1, 0x10, 0x29, 0x21, 0x2D, 0x0D, 0xA1, 0x24, 0x89,
    0x0C, 0xAA, 0x17, 0x82, 0xBB, 0x2B, 0x70, 0x82, 0xD8, 0x89, 0x21, 0x12, 0x9B, 0xAA, 0x02, 0x85,
    0x88, 0x1A, 0x8A, 0x94, 0x19, 0x8A, 0xA4, 0x50, 0x9C, 0xB0, 0x61, 0x38, 0xB0, 0xBC, 0x81, 0x46,
    0x2A, 0xFA, 0x81, 0x11, 0x91, 0x0B, 0x49, 0x31, 0xA9, 0xDA, 0x81, 0x07, 0x00, 0xAA, 0x3B, 0x38,
    0x95, 0xD2, 0x1A, 0x28, 0x86, 0xA9, 0x9A, 0x31, 0x14, 0xA0, 0xC9, 0x1C, 0x00, 0x06, 0x19, 0xC8,
    0x90, 0x19, 0x18, 0x83, 0x01, 0xBC, 0xB9, 0x5A, 0x03, 0x95, 0x1B, 0xBD, 0x82, 0x60, 0x80, 0x91,
    0x8B, 0xAA, 0x61, 0x30, 0xC2, 0xA8, 0x0F, 0x81, 0x43, 0x19, 0xD8, 0x88, 0x2A, 0x94, 0x31, 0x0D,
    0xC0, 0x01, 0x2B, 0x81, 0x21, 0xBA, 0xF3, 0x2C, 0x38, 0xA3, 0x4B, 0x9D, 0x91, 0x68, 0x88, 0x82,
    0x0C, 0xB9, 0x13, 0x62, 0xA0, 0x99, 0x0C, 0x84, 0x32, 0x9C, 0xA0, 0x41, 0x8A, 0xA2, 0x60, 0xA8,
    0xA1, 0x2C, 0xC2, 0x33, 0x0C, 0xB2, 0x39, 0x9F, 0x93, 0x68, 0x90, 0x92, 0x0E, 0x98, 0x43, 0x19,
    0xC0, 0x1B, 0x8B, 0x16, 0x10, 0xD8, 0x00, 0x2B
};

#define  NINJAEAT_DVI   1540

__align(2)
const U8 NinjaEat_dvi[1540] =
{
    0x77, 0xD7, 0x77, 0x77, 0x0E, 0x08, 0x3F, 0xB7, 0x08, 0x17, 0xD8, 0x08, 0x80, 0x08, 0x80, 0x08,
    0x08, 0x80, 0x80, 0x80, 0x00, 0x08, 0x80, 0x08, 0x88, 0x88, 0x08, 0x88, 0x98, 0x88, 0x80, 0x01,
    0x01, 0x08, 0x21, 0x43, 0x24, 0x02, 0x00, 0x99, 0xA9, 0xEB, 0xBC, 0xBB, 0x8A, 0x00, 0x00, 0x99,
    0x9A, 0x48, 0x26, 0x22, 0x41, 0x87, 0x9B, 0x8D, 0xB2, 0x8E, 0x10, 0x86, 0x19, 0x23, 0x86, 0x1C,
    0x01, 0xB0, 0x0F, 0x81, 0xB8, 0x1D, 0x83, 0x99, 0x3A, 0x27, 0x09, 0x49, 0x07, 0x0A, 0x19, 0xB2,
    0xAF, 0x8A, 0xA1, 0x0B, 0x16, 0x06, 0x28, 0x13, 0x81, 0x8F, 0x99, 0xA9, 0x8C, 0x80, 0x88, 0x30,
    0x17, 0x02, 0x21, 0x84, 0x0A, 0x18, 0xD1, 0x9F, 0x09, 0xB0, 0x8D, 0x12, 0x94, 0x39, 0x16, 0x02,
    0x2B, 0x03, 0xCB, 0x9F, 0x91, 0xAA, 0x0D, 0x83, 0x01, 0x52, 0x07, 0x00, 0x28, 0x91, 0x9D, 0x9B,
    0xAA, 0x8D, 0x01, 0x82, 0x40, 0x17, 0x10, 0x18, 0x82, 0x8D, 0x0A, 0xA0, 0x9E, 0x00, 0x92, 0x0C,
    0x22, 0x84, 0x1A, 0x16, 0x82, 0x1A, 0x01, 0xDB, 0x9F, 0x89, 0x98, 0x09, 0x14, 0x15, 0x32, 0x23,
    0x80, 0x8D, 0xAB, 0xBB, 0xAE, 0x9A, 0x01, 0x13, 0x33, 0x26, 0x12, 0x20, 0x11, 0x9A, 0x9D, 0xAB,
    0xAD, 0x9D, 0x88, 0x92, 0x00, 0x36, 0x17, 0x00, 0x10, 0x80, 0x9D, 0x89, 0xC8, 0xAD, 0x19, 0x82,
    0x89, 0x25, 0x07, 0x20, 0x22, 0x81, 0x8F, 0x8A, 0xB9, 0x9D, 0x00, 0x82, 0x20, 0x16, 0x12, 0x08,
    0x81, 0x9A, 0x8D, 0x90, 0xA9, 0x8A, 0x80, 0x08, 0x00, 0x80, 0x53, 0x47, 0x12, 0x22, 0x80, 0x9F,
    0x8C, 0xBB, 0x9E, 0x08, 0x03, 0x32, 0x27, 0x13, 0x09, 0x00, 0xBA, 0xAF, 0x99, 0xA9, 0x0A, 0x15,
    0x82, 0x18, 0x16, 0x01, 0x18, 0x02, 0xAB, 0x8D, 0x88, 0xBD, 0x9C, 0x01, 0x00, 0x33, 0x27, 0x12,
    0x21, 0x01, 0xAB, 0xAE, 0xBB, 0x9D, 0x9A, 0x88, 0x02, 0x15, 0x26, 0x24, 0x12, 0x80, 0x99, 0xAE,
    0xAC, 0xBA, 0xAA, 0x08, 0x27, 0x13, 0x22, 0x14, 0x88, 0x0A, 0x99, 0xAE, 0x9B, 0x91, 0xAA, 0x09,
    0x03, 0x89, 0x46, 0x27, 0x02, 0x21, 0x01, 0xAD, 0x9D, 0xAB, 0x9E, 0x89, 0x03, 0x14, 0x24, 0x14,
    0x11, 0x09, 0x99, 0xAE, 0x9C, 0x89, 0x99, 0x00, 0x14, 0x12, 0x33, 0x16, 0x81, 0x89, 0x80, 0xBB,
    0x9F, 0xA9, 0xAC, 0x09, 0x13, 0x03, 0x25, 0x27, 0x11, 0x10, 0x80, 0xBC, 0x9D, 0x9B, 0xAC, 0x9A,
    0x01, 0x33, 0x37, 0x15, 0x13, 0x81, 0x88, 0xAC, 0x9F, 0xAB, 0x99, 0x08, 0x33, 0x17, 0x11, 0x11,
    0x02, 0xAA, 0x9B, 0xA9, 0xAD, 0x08, 0x81, 0xAF, 0x08, 0x12, 0x18, 0x37, 0x15, 0x01, 0x11, 0xA0,
    0xBF, 0x9C, 0xAA, 0x8B, 0x31, 0x15, 0x22, 0x26, 0x03, 0x89, 0x89, 0xCB, 0x9D, 0x89, 0x99, 0x0A,
    0x22, 0x24, 0x22, 0x17, 0x01, 0x00, 0x81, 0xCA, 0xAD, 0x9C, 0x9B, 0x89, 0x11, 0x43, 0x34, 0x25,
    0x14, 0x01, 0xA9, 0xB9, 0xBC, 0xAD, 0x9B, 0x9C, 0x0B, 0x43, 0x24, 0x33, 0x27, 0x13, 0x80, 0x98,
    0xBF, 0x9D, 0x8A, 0x89, 0x10, 0x34, 0x14, 0x23, 0x13, 0xA9, 0xAD, 0x9A, 0x9B, 0x9B, 0x80, 0x9A,
    0x0A, 0x33, 0x20, 0x55, 0x47, 0x23, 0x13, 0x91, 0xDC, 0xBC, 0xAC, 0x9B, 0x0A, 0x32, 0x36, 0x25,
    0x12, 0x82, 0x99, 0xAC, 0xAB, 0xAD, 0x9A, 0x18, 0x21, 0x42, 0x24, 0x11, 0x12, 0x15, 0x91, 0xBA,
    0xCA, 0xAE, 0x9C, 0x8A, 0x8C, 0x28, 0x35, 0x24, 0x33, 0x04, 0x91, 0x98, 0xCB, 0xBE, 0xAB, 0x9B,
    0x1A, 0x40, 0x33, 0x26, 0x25, 0x13, 0x81, 0xB9, 0xBD, 0xAD, 0xAB, 0x8B, 0x19, 0x34, 0x26, 0x15,
    0x02, 0x80, 0x99, 0xAA, 0x9C, 0x9B, 0x9B, 0x8A, 0x10, 0x09, 0x2B, 0x64, 0x35, 0x26, 0x13, 0x92,
    0xC9, 0xCB, 0xAE, 0x9C, 0x0A, 0x28, 0x43, 0x25, 0x13, 0x02, 0x90, 0xBA, 0xAE, 0x9C, 0x8B, 0x09,
    0x21, 0x22, 0x24, 0x23, 0x15, 0x12, 0x90, 0xA8, 0xCA, 0xBC, 0xAD, 0x9D, 0x8B, 0x29, 0x42, 0x43,
    0x25, 0x23, 0x03, 0x92, 0xDA, 0xAE, 0x9C, 0x9A, 0x8A, 0x18, 0x33, 0x36, 0x25, 0x13, 0x91, 0xB8,
    0xCB, 0xAE, 0x9C, 0x9A, 0x08, 0x33, 0x26, 0x13, 0x13, 0x02, 0x99, 0xBB, 0xAE, 0xAB, 0x89, 0x88,
    0x98, 0xAA, 0x09, 0x60, 0x54, 0x25, 0x14, 0x03, 0x91, 0xDB, 0xAE, 0xAC, 0x8B, 0x18, 0x43, 0x34,
    0x24, 0x03, 0x91, 0xCA, 0xBC, 0xAC, 0x8A, 0x19, 0x21, 0x13, 0x15, 0x13, 0x11, 0x00, 0x08, 0x08,
    0x81, 0xEA, 0xDC, 0xBB, 0x9C, 0x8A, 0x28, 0x53, 0x35, 0x25, 0x13, 0x80, 0xB9, 0xBD, 0xAC, 0x9C,
    0x9A, 0x08, 0x33, 0x27, 0x14, 0x12, 0x82, 0x90, 0xBB, 0xBE, 0xAD, 0x9A, 0x09, 0x21, 0x34, 0x25,
    0x23, 0x13, 0x80, 0xAC, 0xAD, 0x9B, 0x89, 0x88, 0x90, 0x98, 0x89, 0x10, 0x31, 0x47, 0x36, 0x15,
    0x12, 0xB8, 0xCD, 0xAD, 0x9B, 0x0A, 0x20, 0x35, 0x26, 0x13, 0x82, 0xA9, 0xBC, 0xAD, 0xAA, 0x09,
    0x10, 0x23, 0x25, 0x13, 0x00, 0x88, 0x08, 0x10, 0x01, 0xA9, 0xEB, 0xBC, 0xAD, 0xAC, 0x99, 0x21,
    0x37, 0x25, 0x22, 0x02, 0xA8, 0xAC, 0xBD, 0xBC, 0x9B, 0x08, 0x33, 0x45, 0x24, 0x13, 0x12, 0x91,
    0xCB, 0xAE, 0xBB, 0xAB, 0x8A, 0x11, 0x33, 0x37, 0x15, 0x12, 0x80, 0xA8, 0x9B, 0xAB, 0xAA, 0xAC,
    0x99, 0x80, 0x19, 0x01, 0x23, 0x57, 0x36, 0x33, 0x11, 0xB9, 0xCF, 0xAC, 0xBB, 0x9B, 0x20, 0x36,
    0x26, 0x23, 0x12, 0x99, 0xAC, 0xBC, 0xAC, 0x9A, 0x00, 0x22, 0x25, 0x12, 0x01, 0x01, 0x00, 0x00,
    0x91, 0xA9, 0xAC, 0xCC, 0xAE, 0x9C, 0x89, 0x31, 0x36, 0x15, 0x22, 0x11, 0x88, 0xBC, 0xBD, 0xBC,
    0x9B, 0x88, 0x12, 0x25, 0x26, 0x32, 0x23, 0x01, 0xBA, 0xAF, 0xBB, 0xAC, 0x9B, 0x08, 0x32, 0x36,
    0x25, 0x21, 0x00, 0x98, 0xAA, 0xBB, 0xAD, 0x9B, 0x88, 0x00, 0x80, 0x90, 0x32, 0x57, 0x25, 0x23,
    0x11, 0x90, 0xBD, 0xBF, 0xAC, 0xAB, 0x08, 0x34, 0x26, 0x24, 0x22, 0x80, 0xB9, 0xBD, 0xBC, 0x9A,
    0x09, 0x22, 0x33, 0x24, 0x11, 0x02, 0x00, 0x09, 0x01, 0x11, 0x99, 0xDE, 0xAF, 0xBB, 0x99, 0x20,
    0x35, 0x35, 0x24, 0x23, 0x80, 0xBC, 0xBD, 0xBC, 0x9A, 0x89, 0x10, 0x34, 0x35, 0x43, 0x22, 0x00,
    0x99, 0xBB, 0xBE, 0xBC, 0xAB, 0x9A, 0x21, 0x35, 0x34, 0x33, 0x24, 0x02, 0x99, 0xCC, 0xAC, 0xAB,
    0x9A, 0x89, 0x08, 0x32, 0x45, 0x24, 0x24, 0x13, 0x12, 0x80, 0xEB, 0xAF, 0xBC, 0x9B, 0x0A, 0x21,
    0x36, 0x25, 0x24, 0x11, 0x98, 0xAC, 0xAD, 0x9B, 0x8A, 0x00, 0x22, 0x24, 0x24, 0x01, 0x90, 0x98,
    0x88, 0x01, 0x81, 0xDB, 0xBD, 0xAD, 0x9B, 0x0A, 0x32, 0x57, 0x43, 0x13, 0x01, 0xB9, 0xBD, 0xBC,
    0xBB, 0x9B, 0x18, 0x43, 0x36, 0x33, 0x23, 0x11, 0x90, 0xBA, 0xBF, 0xCB, 0xAB, 0x8A, 0x10, 0x32,
    0x44, 0x34, 0x33, 0x03, 0xA0, 0xBC, 0xBC, 0xAC, 0xAC, 0x9B, 0x0A, 0x30, 0x45, 0x43, 0x33, 0x25,
    0x14, 0x80, 0xD9, 0xBC, 0xAD, 0x9C, 0x8A, 0x18, 0x43, 0x35, 0x24, 0x13, 0x80, 0xCA, 0xAC, 0xAC,
    0x9B, 0x09, 0x21, 0x34, 0x24, 0x11, 0x80, 0x08, 0x08, 0x00, 0xA8, 0xEA, 0xCB, 0xBD, 0xAC, 0x8A,
    0x48, 0x45, 0x25, 0x23, 0x01, 0xA0, 0xBC, 0xBD, 0xAC, 0x8B, 0x19, 0x31, 0x25, 0x33, 0x23, 0x23,
    0x01, 0xB9, 0xCD, 0xCB, 0x9C, 0xAB, 0x8A, 0x18, 0x54, 0x34, 0x24, 0x12, 0x91, 0xB9, 0xCC, 0xAC,
    0xAB, 0x8B, 0x18, 0x32, 0x43, 0x24, 0x34, 0x34, 0x23, 0x82, 0xC9, 0xDC, 0xBC, 0xAD, 0xAB, 0x09,
    0x31, 0x37, 0x34, 0x23, 0x82, 0xB8, 0xCC, 0xBC, 0x9C, 0x8A, 0x11, 0x43, 0x33, 0x13, 0x02, 0x88,
    0x9A, 0xAB, 0x9A, 0x88, 0xCA, 0xCE, 0xBD, 0xAB, 0x18, 0x54, 0x44, 0x24, 0x13, 0x81, 0xBA, 0xCE,
    0xAB, 0x8C, 0x09, 0x20, 0x43, 0x23, 0x14, 0x02, 0x80, 0xAA, 0xBB, 0xAC, 0xAC, 0xBB, 0x9B, 0x29,
    0x54, 0x35, 0x24, 0x14, 0x01, 0xA0, 0xCB, 0xBD, 0x9C, 0x9A, 0x88, 0x11, 0x32, 0x34, 0x34, 0x24,
    0x13, 0x81, 0x98, 0xCC, 0xDC, 0xCB, 0xAB, 0x8A, 0x31, 0x45, 0x34, 0x14, 0x03, 0x90, 0xCB, 0xAE,
    0xAB, 0x9A, 0x18, 0x32, 0x35, 0x33, 0x23, 0x81, 0x99, 0x9C, 0x9A, 0x99, 0xC9, 0xCC, 0xBC, 0x9C,
    0x09, 0x31, 0x46, 0x34, 0x15, 0x02, 0xA0, 0xDB, 0xAC, 0xAB, 0x9A, 0x18, 0x33, 0x26, 0x24, 0x12,
    0x00, 0x99, 0xAA, 0xBC, 0xBC, 0xBC, 0x9A, 0x00, 0x43, 0x35, 0x34, 0x24, 0x12, 0x90, 0xCB, 0xBC,
    0xAC, 0xAA, 0x99, 0x98, 0x01, 0x32, 0x35, 0x35, 0x34, 0x24, 0x13, 0xA0, 0xDD, 0xCC, 0xAB, 0x9B,
    0x10, 0x43, 0x36, 0x33, 0x14, 0x90, 0xBB, 0xBE, 0xBB, 0x9A, 0x19, 0x22, 0x26, 0x23, 0x13, 0x00,
    0x89, 0x09, 0x18, 0x00, 0xA9, 0xBF, 0xBE, 0xBC, 0xAB, 0x09, 0x44, 0x36, 0x24, 0x13, 0x91, 0xBA,
    0xAE, 0xBC, 0x9A, 0x09, 0x31, 0x35, 0x43, 0x12, 0x01, 0x89, 0xAA, 0xBC, 0xBC, 0xBB, 0xBB, 0x99,
    0x11, 0x45, 0x45, 0x43, 0x23, 0x01, 0xA9, 0xAD, 0xAC, 0xBB, 0xAA, 0x09, 0x11, 0x33, 0x24, 0x33,
    0x35, 0x35, 0x23, 0x81, 0xEB, 0xCD, 0xCB, 0xAB, 0x8A, 0x32, 0x46, 0x34, 0x23, 0x02, 0xAA, 0xBD,
    0xBD, 0xAB, 0x9A, 0x10, 0x34, 0x34, 0x23, 0x12, 0x80, 0x89, 0x99, 0xA9, 0xAA, 0xBA, 0xBE, 0xAE,
    0xAC, 0x9A, 0x22, 0x47, 0x43, 0x23, 0x12, 0x99, 0xCD, 0xBC, 0xAC, 0x8A, 0x28, 0x43, 0x34, 0x24,
    0x22, 0x00, 0xAA, 0xBC, 0xAD, 0xAB, 0x9A, 0x89, 0x00, 0x33, 0x37, 0x43, 0x23, 0x12, 0x90, 0xBA,
    0xBE, 0xAD, 0xAB, 0x99, 0x00, 0x32, 0x43, 0x34, 0x34, 0x24, 0x13, 0x90, 0xCC, 0xBD, 0xBD, 0xAC,
    0x99, 0x21, 0x35, 0x26, 0x23, 0x12, 0x98, 0xCB, 0xBD, 0xBB, 0x9B, 0x08, 0x33, 0x25, 0x24, 0x12,
    0x11, 0x08, 0x99, 0xA9, 0xBA, 0xCB, 0xCC, 0xBC, 0xAB, 0x0A, 0x53, 0x36, 0x35, 0x23, 0x12, 0xA8,
    0xCD, 0xAD, 0xAC, 0x99, 0x08, 0x32, 0x35, 0x34, 0x23, 0x01, 0xA8, 0xDB, 0xCB, 0xAB, 0x9C, 0x8A,
    0x08, 0x32, 0x35, 0x25, 0x23, 0x13, 0x80, 0xCA, 0xCC, 0xBB, 0x9C, 0x8A, 0x10, 0x31, 0x43, 0x24,
    0x24, 0x23, 0x12, 0x91, 0xD9, 0xCD, 0xBD, 0xAC, 0x9B, 0x28, 0x63, 0x34, 0x25, 0x12, 0x81, 0xBA,
    0xBD, 0xAD, 0x9A, 0x09, 0x21, 0x43, 0x23, 0x13, 0x00, 0x98, 0x9A, 0x8A, 0x00, 0x80, 0xDA, 0xCD,
    0xAC, 0x9B, 0x29, 0x73, 0x34, 0x25, 0x13, 0x80, 0xCB, 0xBD, 0xAD, 0x9A, 0x09, 0x21, 0x44, 0x43,
    0x22, 0x02, 0x88, 0xAB, 0xAD, 0xBB, 0xAB, 0x9A, 0x08, 0x21, 0x34, 0x44, 0x33, 0x24, 0x22, 0x90,
    0xCB, 0xBE, 0xCB, 0xAA, 0x8A, 0x18, 0x53, 0x34, 0x34, 0x32, 0x12, 0x91, 0xC9, 0xDC, 0xCC, 0xBB,
    0xAB, 0x0A, 0x42, 0x36, 0x35, 0x23, 0x03, 0xB0, 0xCC, 0xBC, 0xAC, 0x89, 0x18, 0x22, 0x34, 0x23,
    0x02, 0x80, 0x8A, 0x8A, 0x09, 0x98, 0xDA, 0xDC, 0xCB, 0x9B, 0x0A, 0x52, 0x36, 0x35, 0x23, 0x82,
    0xB9, 0xCD, 0xBC, 0x9C, 0x9A, 0x18, 0x32, 0x35, 0x25, 0x22, 0x01, 0x89, 0xBB, 0xBD, 0xBB, 0x9C,
    0x89, 0x20, 0x32, 0x34, 0x25, 0x23, 0x02, 0x80, 0xBA, 0xCD, 0xCB, 0xBB, 0x9C, 0x0A, 0x20, 0x44,
    0x35, 0x43, 0x23, 0x13, 0x90, 0xEB, 0xBD, 0xAD, 0xAB, 0x9A, 0x10, 0x44, 0x35, 0x43, 0x12, 0x90,
    0xBA, 0xBD, 0xAC, 0x9A
};

/******************************************AUDIO************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_ninjaclimb_enter_gfx
 * DESCRIPTION
 *  Set Game Framework (GFX) Parameter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* keep this game old naming style */
void mmi_gx_ninjaclimb_enter_gfx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Game menu */
    GFX.game_data.game_img_id = 0;//IMG_ID_GX_NINJACLIMB_GAME_ICON;  /* game icon img ID */
#if defined(__MMI_GAME_NINJACLIMB__)
    GFX.game_data.game_str_id = STR_ID_GX_NINJACLIMB_GAME_NAME;  /* game name string ID */
#elif defined(__MMI_GAME_MONKEY__)
    GFX.game_data.game_str_id = STR_ID_GX_NINJACLIMB_GAME_NAME_MONKEY;       /* game name string ID */
#endif
    GFX.game_data.menu_resume_str_id = STR_GAME_RESUME;     /* "Resume" string ID */
    GFX.game_data.menu_new_str_id = STR_GAME_NEW;           /* "New Game" string ID */
    GFX.game_data.menu_level_str_id = 0;                    /* "Game Level" string ID */
    GFX.game_data.menu_grade_str_id = STR_GAME_GRADE;       /* "Best Grade" string ID */
    GFX.game_data.menu_help_str_id = STR_GLOBAL_HELP;         /* "Game Help" string ID */

    /* level / grade */
    GFX.game_data.level_count = 1;                          /* how many levels */
    GFX.game_data.level_str_id_list[0] = STR_GAME_SCORE;    /* level string ID */

    /* add slot in NVRAMEnum.h */
    GFX.game_data.grade_nvram_id_list[0] = NVRAM_GX_NINJACLIMB_SCORE;        /* current lvl idnex  in NVRAM (byte) */

    /* help */
#if defined(__MMI_GAME_NINJACLIMB__)
    #ifndef __MMI_TOUCH_SCREEN__
    GFX.game_data.help_str_id = STR_ID_GX_NINJACLIMB_HELP_DESCRIPTION;       /* help desciption string id */
    #else
    GFX.game_data.help_str_id = STR_ID_GX_NINJACLIMB_HELP_DESCRIPTION_TOUCH;
    #endif
#elif defined(__MMI_GAME_MONKEY__)
    GFX.game_data.help_str_id = STR_ID_GX_NINJACLIMB_HELP_DESCRIPTION_MONKEY;        /* help desciption string id */
#endif

    /* misc */
    GFX.game_data.grade_value_ptr = (S16*) (&g_gx_ninjaclimb_context.game_grade);   /* current level's grade (S16*) */
    GFX.game_data.level_index_ptr = (U8*) (&g_gx_ninjaclimb_context.game_level);    /* ptr to current level index (U8*) */
    GFX.game_data.is_new_game = (BOOL*) (&g_gx_ninjaclimb_context.is_new_game);     /* ptr to new game flag (BOOL*) */

    /* function ptr */
    GFX.game_data.best_grade_func_ptr = mmi_gx_ninjaclimb_calc_best_grade;   /* function to calculate best grade */
    GFX.game_data.enter_game_func_ptr = mmi_gx_ninjaclimb_enter_game;        /* function to enter new game */
    GFX.game_data.exit_game_func_ptr = mmi_gx_ninjaclimb_exit_game;  /* function to exit game */
    GFX.game_data.draw_gameover_func_ptr = mmi_gx_ninjaclimb_draw_gameover;  /* function to draw gameover screen */

    /* some flags */
    GFX.game_data.is_keypad_audio_enable = FALSE;   /* play keypad tone or not */

    mmi_gfx_entry_menu_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_ninjaclimb_calc_best_grade
 * DESCRIPTION
 *  Calculate new best grade [Callback required by GFX]
 * PARAMETERS
 *  old_grade       [IN]
 *  new_grade       [IN]
 * RETURNS
 *  S16
 *****************************************************************************/
S16 mmi_gx_ninjaclimb_calc_best_grade(S16 old_grade, S16 new_grade)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* compare the best grade and return it */
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
 *  mmi_gx_ninjaclimb_draw_gameover
 * DESCRIPTION
 *  Draw Gameover Screen [Callback required by GFX]
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_ninjaclimb_draw_gameover(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GFX_PLAY_AUDIO_GAMEOVER();
    gdi_draw_solid_rect(0, 0, MMI_GX_NINJACLIMB_LCD_WIDTH - 1, MMI_GX_NINJACLIMB_LCD_HEIGHT - 1, GDI_COLOR_BLACK);

    /* call this function to draw standard gameover screen */
    mmi_gfx_draw_gameover_screen(
        NULL,
        NULL,
        IMG_ID_GX_NINJACLIMB_ROLE_FALL_RIGHT_FRAME_1,
        g_gx_ninjaclimb_context.game_grade);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_ninjaclimb_enter_game
 * DESCRIPTION
 *  Enter Game [Callback required by GFX]
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_ninjaclimb_enter_game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_gx_ninjaclimb_context.is_new_game == TRUE)
    {
        mmi_gx_ninjaclimb_init_game();   /* is new game, otherwise resume game */
    }
    if(g_gx_ninjaclimb_context.state == ATTACK)
        g_gx_ninjaclimb_context.state = NORMAL;

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    mmi_ninjaclimb_language_index = g_mmi_game_current_language_index;
    mmi_gfx_check_image_get_valid_language(
        &mmi_ninjaclimb_language_index,
        IMG_ID_GX_NINJACLIMB_BACKGROUND_LANGUAGE0,
        MMI_NINJACLIMB_STRING_COUNT);
#endif  /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

    g_gx_ninjaclimb_context.is_new_game = FALSE;
    g_gx_ninjaclimb_context.is_gameover = FALSE;

    /* init key's state */
    g_gx_ninjaclimb_context.up_key_pressed = FALSE;
    g_gx_ninjaclimb_context.down_key_pressed = FALSE;

    gdi_layer_multi_layer_enable();

    gdi_layer_get_base_handle(&g_gx_ninjaclimb_context.background);

    gdi_layer_create(0, 0, MMI_GX_NINJACLIMB_LCD_WIDTH, MMI_GX_NINJACLIMB_LCD_HEIGHT, &g_gx_ninjaclimb_context.foreground);
    gdi_layer_set_active(g_gx_ninjaclimb_context.foreground);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_BLUE); /* set pure-blue as the transparent color in foreground */
    gdi_layer_clear_background(GDI_COLOR_BLUE);     /* clean foreground layer */
    // gdi_image_draw_id(50,50,IMG_GLOBAL_WARNING); /* only use for demo */

    /* draw background image */
    gdi_layer_set_active(g_gx_ninjaclimb_context.background);
    gdi_layer_set_clip(0, 0, MMI_GX_NINJACLIMB_LCD_WIDTH - 1, MMI_GX_NINJACLIMB_LCD_HEIGHT - 1);
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    gdi_image_draw_id(0, 0, IMG_ID_GX_NINJACLIMB_BACKGROUND);
#else   /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */
    gdi_image_draw_id(
        0,
        0,
        mmi_gfx_get_multilanguage_image_ID(
            mmi_ninjaclimb_language_index,
            IMG_ID_GX_NINJACLIMB_BACKGROUND_LANGUAGE0,
            MMI_NINJACLIMB_STRING_COUNT,
            MMI_NINJACLIMB_STRING_BACKGROUND));
#endif /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

    SetKeyHandler(mmi_gx_ninjaclimb_key_2_press, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_ninjaclimb_key_8_press, KEY_8, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_gx_ninjaclimb_key_2_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_ninjaclimb_key_8_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_gx_ninjaclimb_key_2_release, KEY_2, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_ninjaclimb_key_8_release, KEY_8, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_ninjaclimb_key_4_press, KEY_4, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_ninjaclimb_key_6_press, KEY_6, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_gx_ninjaclimb_key_2_release, KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_ninjaclimb_key_8_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_ninjaclimb_key_4_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_ninjaclimb_key_6_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_gx_ninjaclimb_key_5_press, KEY_5, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_ninjaclimb_key_5_release, KEY_5, KEY_EVENT_UP);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_pen_down_handler(mmi_gx_ninjaclimb_pen_down_hdlr);    /* function to pen down event */
    wgui_register_pen_up_handler(mmi_gx_ninjaclimb_pen_up_hdlr);        /* function to pen up event */
    wgui_register_pen_move_handler(mmi_gx_ninjaclimb_pen_move_hdlr);    /* function to pen up event */
#endif  //__MMI_TOUCH_SCREEN__

    /* start game loop */
    mmi_gx_ninjaclimb_cyclic_timer();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_ninjaclimb_exit_game
 * DESCRIPTION
 *  Exit Game [Callback required by GFX]
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_ninjaclimb_exit_game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset bgm resume handler */
    /* SetProtocolEventHandler(NULL, PRT_EQ_PLAY_AUDIO_FINISH_IND); */

    gui_cancel_timer(mmi_gx_ninjaclimb_cyclic_timer);    /* cancle the looping timer */

    gdi_layer_multi_layer_disable();
    gdi_layer_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
    gdi_layer_free(g_gx_ninjaclimb_context.foreground);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_ninjaclimb_init_enemy_list
 * DESCRIPTION
 *  init_enemy_list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_ninjaclimb_init_enemy_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gx_ninjaclimb_pos_state_enum i;
    U8 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = LEFT_ROPE_LEFT; i <= RIGHT_ROPE_RIGHT; i++)
    {
        g_gx_ninjaclimb_context.tree[i].first = &(g_gx_ninjaclimb_context.tree[i].enemy[0]);
        g_gx_ninjaclimb_context.tree[i].last = &(g_gx_ninjaclimb_context.tree[i].enemy[0]);
        g_gx_ninjaclimb_context.tree[i].empty = &(g_gx_ninjaclimb_context.tree[i].enemy[1]);
        g_gx_ninjaclimb_context.tree[i].empty_last = &(g_gx_ninjaclimb_context.tree[i].enemy[MMI_GX_NINJACLIMB_ENEMY_COUNT - 1]);
        for (j = 0; j < MMI_GX_NINJACLIMB_ENEMY_COUNT; j++)
        {
            if (j == 0)
            {
                g_gx_ninjaclimb_context.tree[i].enemy[j].position_y =
                    MMI_GX_NINJACLIMB_LCD_HEIGHT + MMI_GX_NINJACLIMB_ENEMY_HEIGHT * (rand() % RIGHT_ROPE_RIGHT);
                g_gx_ninjaclimb_context.tree[i].enemy[j].old_position_y = g_gx_ninjaclimb_context.tree[i].enemy[j].position_y;
                g_gx_ninjaclimb_context.tree[i].enemy[j].type = ENEMY_1 + (gx_ninjaclimb_type_enum) (rand() % ENEMY_MAX);
            }
            if (j != 0)
            {
                g_gx_ninjaclimb_context.tree[i].enemy[j].previous = &(g_gx_ninjaclimb_context.tree[i].enemy[j - 1]);
            }
            if (j != MMI_GX_NINJACLIMB_ENEMY_COUNT - 1)
            {
                g_gx_ninjaclimb_context.tree[i].enemy[j].next = &(g_gx_ninjaclimb_context.tree[i].enemy[j + 1]);
            }
            g_gx_ninjaclimb_context.tree[i].enemy[j].is_dying = FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_ninjaclimb_init_game
 * DESCRIPTION
 *  Game initilization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_ninjaclimb_init_game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init game */
    g_gx_ninjaclimb_context.pos_state = MID_ROPE_LEFT;
    g_gx_ninjaclimb_context.state = NORMAL;

    g_gx_ninjaclimb_context.position.y = MMI_GX_NINJACLIMB_TOP_MARGIN + 1;             /* initial role's y position */
    g_gx_ninjaclimb_context.pos_state = MID_ROPE_LEFT;   /* on the LEFT of the MIDDLE NINJA */
    g_gx_ninjaclimb_context.state = NORMAL;              /* Not in ATTACK STATE */
    g_gx_ninjaclimb_context.old_state = NORMAL;          /* Not in ATTACK STATE */
    g_gx_ninjaclimb_context.old_pos_state = MID_ROPE_LEFT;
    g_gx_ninjaclimb_context.tick = 0;                    /* tick initialization */
    g_gx_ninjaclimb_context.total_time = MMI_GX_NINJACLIMB_TOTAL_TIME;
    g_gx_ninjaclimb_context.up_key_pressed = FALSE;
    g_gx_ninjaclimb_context.down_key_pressed = FALSE;
    g_gx_ninjaclimb_context.position.x = mmi_gx_ninjaclimb_get_x_position(g_gx_ninjaclimb_context.pos_state, MMI_GX_NINJACLIMB_IS_ROLE);
    g_gx_ninjaclimb_context.old_position = g_gx_ninjaclimb_context.position;
    g_gx_ninjaclimb_context.clock_falling = FALSE;
    g_gx_ninjaclimb_context.is_dying = FALSE;
    g_gx_ninjaclimb_context.game_grade = 0;
    g_gx_ninjaclimb_context.enemy_speed = MMI_GX_NINJACLIMB_ENEMY_SLOW_SPEED;

    mmi_gx_ninjaclimb_init_enemy_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_ninjaclimb_framemove
 * DESCRIPTION
 *  Framemove - process the game logic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_ninjaclimb_framemove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 moving_speed;    /* the moving speed of role */
    U8 tree_number;
    BOOL is_reach_button = FALSE;
    gx_ninjaclimb_node_struct *current_node;
    gx_ninjaclimb_node_struct *next_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* determine the moving speed of the role */
    if (g_gx_ninjaclimb_context.state != ATTACK)
    {
        moving_speed = MMI_GX_NINJACLIMB_ROLE_SPEED;
    }
    else
    {
        moving_speed = MMI_GX_NINJACLIMB_ROLE_ATTACK_SPEED;
    }

    /* not dying */
    if (g_gx_ninjaclimb_context.is_dying != TRUE)
    {
        /* detect if role goes to the bottom */
        if (g_gx_ninjaclimb_context.down_key_pressed != FALSE)
        {
            g_gx_ninjaclimb_context.position.y = g_gx_ninjaclimb_context.position.y + moving_speed;
            if (g_gx_ninjaclimb_context.position.y >= MMI_GX_NINJACLIMB_LCD_HEIGHT - MMI_GX_NINJACLIMB_ROLE_HEIGHT - 1)
            {
                if (g_gx_ninjaclimb_context.state == ATTACK)
                {
                    is_reach_button = TRUE;
                }

                g_gx_ninjaclimb_context.position.y = MMI_GX_NINJACLIMB_LCD_HEIGHT - MMI_GX_NINJACLIMB_ROLE_HEIGHT - 1;
            }
        }

        /* detect if role goes to the upmost */
        if (g_gx_ninjaclimb_context.up_key_pressed != FALSE)
        {
            g_gx_ninjaclimb_context.position.y = g_gx_ninjaclimb_context.position.y - MMI_GX_NINJACLIMB_ROLE_SPEED;
            if (g_gx_ninjaclimb_context.position.y < MMI_GX_NINJACLIMB_TOP_MARGIN)
            {
                g_gx_ninjaclimb_context.position.y = MMI_GX_NINJACLIMB_TOP_MARGIN + 1;
            }
        }
    }

    /* every 1.2 second (when total time < 3 minutes) and every 0.8 second (when total time > 3 minutes), new() a enemy */
    if (((g_gx_ninjaclimb_context.tick <= 1800 && g_gx_ninjaclimb_context.tick % MMI_GX_NINJACLIMB_ENEMY_NEW_INTERVAL_1 == 0) ||
            (g_gx_ninjaclimb_context.tick > 1800 && g_gx_ninjaclimb_context.tick % MMI_GX_NINJACLIMB_ENEMY_NEW_INTERVAL_2 == 0)) && g_gx_ninjaclimb_context.tick != 0)
    {
        tree_number = rand() % MMI_GX_NINJACLIMB_SIDE_COUNT;
        g_gx_ninjaclimb_context.tree[tree_number].empty->position_y = MMI_GX_NINJACLIMB_LCD_HEIGHT + 1;
        g_gx_ninjaclimb_context.tree[tree_number].empty->type = ENEMY_1 + rand() % ENEMY_MAX;
        g_gx_ninjaclimb_context.tree[tree_number].last = g_gx_ninjaclimb_context.tree[tree_number].empty;
        g_gx_ninjaclimb_context.tree[tree_number].empty = g_gx_ninjaclimb_context.tree[tree_number].empty->next;
    }

    /* check if the "clock" (for time extension) should appear after attacking 10 enemies */
    if ((g_gx_ninjaclimb_context.game_grade + 5) % 50 == 0)
    {
        g_gx_ninjaclimb_context.clock_falling = TRUE;
        g_gx_ninjaclimb_context.clock_position_y = -MMI_GX_NINJACLIMB_CLOCK_HEIGHT - 10;
        g_gx_ninjaclimb_context.clock_old_position_y = -MMI_GX_NINJACLIMB_CLOCK_HEIGHT - 10;
        /* determine which space between two ninjas the clock should appear */
        if (rand() % 2 != 0)
        {
            g_gx_ninjaclimb_context.clock_pos_state = LEFT_SPACE;
        }
        else
        {
            g_gx_ninjaclimb_context.clock_pos_state = RIGHT_SPACE;
        }
        g_gx_ninjaclimb_context.clock_x_position =
            (S16) mmi_gx_ninjaclimb_get_x_position(g_gx_ninjaclimb_context.clock_pos_state, MMI_GX_NINJACLIMB_IS_CLOCK);
    }

    /* dying, calc positon and do not need do collision detection */
    if (g_gx_ninjaclimb_context.is_dying == TRUE)
    {
        g_gx_ninjaclimb_context.position.x = mmi_gx_ninjaclimb_get_x_position(g_gx_ninjaclimb_context.pos_state, MMI_GX_NINJACLIMB_IS_DYING_ROLE);
        return;
    }

    /* collision detection */
    if (g_gx_ninjaclimb_context.state != FLYING && g_gx_ninjaclimb_context.old_state != FLYING)
    {
        current_node = g_gx_ninjaclimb_context.tree[g_gx_ninjaclimb_context.pos_state].first;
        while (current_node != g_gx_ninjaclimb_context.tree[g_gx_ninjaclimb_context.pos_state].empty)
        {
            next_node = current_node->next;
            /* Of course, if the enemy is dying, then we don't have to check if the collision happens */
            if (current_node->is_dying != TRUE)
            {
                if ((current_node->position_y >= g_gx_ninjaclimb_context.position.y &&
                        current_node->position_y < g_gx_ninjaclimb_context.position.y + MMI_GX_NINJACLIMB_ROLE_HEIGHT) ||
                        (g_gx_ninjaclimb_context.position.y >= current_node->position_y &&
                         g_gx_ninjaclimb_context.position.y < current_node->position_y + MMI_GX_NINJACLIMB_ENEMY_HEIGHT))
                {
                    /* in attack mode */
                    if (g_gx_ninjaclimb_context.state == ATTACK && current_node->is_dying != TRUE)
                    {
                        current_node->is_dying = TRUE;
                        /* increase score */
                        g_gx_ninjaclimb_context.game_grade = (g_gx_ninjaclimb_context.game_grade < 0xFFFF )?(g_gx_ninjaclimb_context.game_grade + MMI_GX_NINJACLIMB_SCORE_PER_ENEMY):0xFFFF;

                        GFX_PLAY_AUDIO_DVI(NinjaHit_dvi, NINJAHIT_DVI, DEVICE_AUDIO_PLAY_ONCE);

                        /* GFX_PLAY_VIBRATION(); */
                    }
                    /* in normal mode */
                    else if (g_gx_ninjaclimb_context.state == NORMAL)
                    {
                        g_gx_ninjaclimb_context.is_dying = TRUE;
                        /* determine which space will the dying role fall */
                        g_gx_ninjaclimb_context.position.x = mmi_gx_ninjaclimb_get_x_position(g_gx_ninjaclimb_context.pos_state, MMI_GX_NINJACLIMB_IS_DYING_ROLE);

                        GFX_PLAY_AUDIO_DVI(NinjaFall_dvi, NINJAFALL_DVI, DEVICE_AUDIO_PLAY_ONCE);
                    }
                }
            }
            current_node = next_node;
        }
    }

    if (is_reach_button == TRUE)
    {
        g_gx_ninjaclimb_context.state = NORMAL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_ninjaclimb_render
 * DESCRIPTION
 *  Render the game images
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_ninjaclimb_render(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE role_image = 0;
    S16 i;
    S16 enemy_x_position;
    //S16 old_enemy_x_position;
    gx_ninjaclimb_node_struct *current_node;
    gx_ninjaclimb_node_struct *next_node;
    gx_ninjaclimb_node_struct *tmp_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_set_active(g_gx_ninjaclimb_context.foreground);

    gdi_layer_clear_background(MMI_GX_NINJACLIMB_TRANSPARENT_COLOR);

    /* decrease time left for every second */
    if (g_gx_ninjaclimb_context.tick % 10 == 0)
    {
        g_gx_ninjaclimb_context.total_time = g_gx_ninjaclimb_context.total_time - 1;
    }

    /* time is up */
    if (g_gx_ninjaclimb_context.total_time == 0)
    {
        mmi_gx_ninjaclimb_gameover();
        if (g_gx_ninjaclimb_context.is_gameover != FALSE)
        {
            return;
        }
    }

    /* increase the speed of enemy for every 1.5 minutes */
    if ((g_gx_ninjaclimb_context.tick + 1) % 900 == 0)
    {
        g_gx_ninjaclimb_context.enemy_speed = g_gx_ninjaclimb_context.enemy_speed + 1;
    }

    /* erase all enemies */
    for (i = LEFT_ROPE_LEFT; i <= RIGHT_ROPE_RIGHT; i++)
    {
        current_node = g_gx_ninjaclimb_context.tree[i].first;
        while (current_node != g_gx_ninjaclimb_context.tree[i].empty)
        {
            /* determine enemy's position_x while not dying */
            if (current_node->is_dying != TRUE)
            {
                enemy_x_position = mmi_gx_ninjaclimb_get_x_position(i, MMI_GX_NINJACLIMB_IS_ENEMY);
            }
            /* determine enemy's position_x while dying */
            else
            {
                enemy_x_position = mmi_gx_ninjaclimb_get_x_position(i, MMI_GX_NINJACLIMB_IS_DYING_ENEMY);
                //old_enemy_x_position = mmi_gx_ninjaclimb_get_x_position(i, MMI_GX_NINJACLIMB_IS_ENEMY);
            }

            current_node = current_node->next;
        }
    }

    /* draw enemies and update their position */
    for (i = LEFT_ROPE_LEFT; i <= RIGHT_ROPE_RIGHT; i++)
    {
        current_node = g_gx_ninjaclimb_context.tree[i].first;
        while (current_node != g_gx_ninjaclimb_context.tree[i].empty)
        {
            /* determine enemy's position_x while not dying */
            if (current_node->is_dying != TRUE)
            {
                enemy_x_position = mmi_gx_ninjaclimb_get_x_position(i, MMI_GX_NINJACLIMB_IS_ENEMY);
            }
            /* determine enemy's position_x while dying */
            else
            {
                enemy_x_position = mmi_gx_ninjaclimb_get_x_position(i, MMI_GX_NINJACLIMB_IS_DYING_ENEMY);
                //old_enemy_x_position = mmi_gx_ninjaclimb_get_x_position(i, MMI_GX_NINJACLIMB_IS_ENEMY);
            }
            /* left enemy case */
            {
                if (i % 2 == 0)
                {
                    gdi_image_draw_id(
                        enemy_x_position,
                        current_node->position_y,
                        (U16) (IMG_ID_GX_NINJACLIMB_ENEMY_1_LEFT + current_node->type + (g_gx_ninjaclimb_context.tick / 2 % 2) * ENEMY_MAX));
                }
                /* right enemy case */
                else
                {
                    gdi_image_draw_id(
                        enemy_x_position,
                        current_node->position_y,
                        (U16) (IMG_ID_GX_NINJACLIMB_ENEMY_1_RIGHT + current_node->type + (g_gx_ninjaclimb_context.tick / 2 % 2) * ENEMY_MAX));
                }
            }

            /* update information */
            current_node->old_position_y = current_node->position_y;
            if (current_node->is_dying != TRUE)
            {
                current_node->position_y = current_node->position_y - g_gx_ninjaclimb_context.enemy_speed;
            }
            else
            {
                current_node->position_y = current_node->position_y + MMI_GX_NINJACLIMB_FALLING_SPEED;
            }

            next_node = current_node->next;

            /* if the enemy is going out of the boundary, remove it from ninja */
            if (current_node->position_y + MMI_GX_NINJACLIMB_ENEMY_HEIGHT + 1 < 0 ||
                    current_node->position_y > MMI_GX_NINJACLIMB_LCD_HEIGHT)
            {
                /* normal case */
                if (current_node->is_dying != TRUE)
                {
                    /* remove the first enemy in the list and append to the last position of the list */
                    g_gx_ninjaclimb_context.tree[i].empty_last->next = g_gx_ninjaclimb_context.tree[i].first;
                    g_gx_ninjaclimb_context.tree[i].first->previous = g_gx_ninjaclimb_context.tree[i].empty_last;
                    g_gx_ninjaclimb_context.tree[i].empty_last = g_gx_ninjaclimb_context.tree[i].first;
                    g_gx_ninjaclimb_context.tree[i].first = current_node->next;
                }
                /* enemy dying case */
                else
                {
                    /* if the dying enemy is the first enemy on the ninja */
                    if (current_node == g_gx_ninjaclimb_context.tree[i].first)
                    {
                        g_gx_ninjaclimb_context.tree[i].empty_last->next = g_gx_ninjaclimb_context.tree[i].first;
                        g_gx_ninjaclimb_context.tree[i].first->previous = g_gx_ninjaclimb_context.tree[i].empty_last;
                        g_gx_ninjaclimb_context.tree[i].empty_last = g_gx_ninjaclimb_context.tree[i].first;
                        g_gx_ninjaclimb_context.tree[i].first = current_node->next;
                    }
                    else
                    {
                        tmp_node = current_node->previous;
                        tmp_node->next = current_node->next;
                        current_node->next->previous = tmp_node;
                        g_gx_ninjaclimb_context.tree[i].empty_last->next = current_node;
                        current_node->previous = g_gx_ninjaclimb_context.tree[i].empty_last;
                        g_gx_ninjaclimb_context.tree[i].empty_last = current_node;
                    }
                    /* because it became empty, need to restore the state */
                    current_node->is_dying = FALSE;
                }
            }

            current_node = next_node;
        }
    }

    /* display time left */
    mmi_gx_ninjaclimb_draw_digits(MMI_GX_NINJACLIMB_DIGIT_X, MMI_GX_NINJACLIMB_DIGIT_Y, g_gx_ninjaclimb_context.total_time);

    /* display score */
    mmi_gx_ninjaclimb_draw_digits( MMI_GX_NINJACLIMB_SCORE_X, MMI_GX_NINJACLIMB_SCORE_Y, g_gx_ninjaclimb_context.game_grade);


    /* drawing clock */
    if (g_gx_ninjaclimb_context.clock_falling != FALSE)
    {
        g_gx_ninjaclimb_context.clock_position_y = g_gx_ninjaclimb_context.clock_position_y + MMI_GX_NINJACLIMB_CLOCK_SPEED;
        /* draw new clock image */
        gdi_image_draw_id(
            g_gx_ninjaclimb_context.clock_x_position,
            g_gx_ninjaclimb_context.clock_position_y,
            IMG_ID_GX_NINJACLIMB_CLOCK);
        g_gx_ninjaclimb_context.clock_old_position_y = g_gx_ninjaclimb_context.clock_position_y;

        if (g_gx_ninjaclimb_context.clock_position_y > MMI_GX_NINJACLIMB_LCD_HEIGHT)
        {
            g_gx_ninjaclimb_context.clock_falling = FALSE;
        }
    }

    /* while the role is alive */
    if (g_gx_ninjaclimb_context.is_dying != TRUE)
    {
        /* determine the role image */
        /* while key pressing, the role is moving as a result we need to draw animation */
        if (g_gx_ninjaclimb_context.up_key_pressed != FALSE || g_gx_ninjaclimb_context.down_key_pressed != FALSE)
        {
            switch (g_gx_ninjaclimb_context.pos_state)
            {
                    /* all LEFT cases */
                case LEFT_ROPE_LEFT:
                case MID_ROPE_LEFT:
                case RIGHT_ROPE_LEFT:
                    if (g_gx_ninjaclimb_context.state == ATTACK)
                    {
                        role_image = IMG_ID_GX_NINJACLIMB_ROLE_ATTACK_L_FRAME_0 + (g_gx_ninjaclimb_context.tick % 2);
                    }
                    else
                    {
                        role_image = IMG_ID_GX_NINJACLIMB_ROLE_LEFT_FRAME_0 + (g_gx_ninjaclimb_context.tick % 2);
                    }
                    break;
                    /* all RIGHT cases */
                case LEFT_ROPE_RIGHT:
                case MID_ROPE_RIGHT:
                case RIGHT_ROPE_RIGHT:
                    if (g_gx_ninjaclimb_context.state == ATTACK)
                    {
                        role_image = IMG_ID_GX_NINJACLIMB_ROLE_ATTACK_R_FRAME_0 + (g_gx_ninjaclimb_context.tick % 2);
                    }
                    else
                    {
                        role_image = IMG_ID_GX_NINJACLIMB_ROLE_RIGHT_FRAME_0 + (g_gx_ninjaclimb_context.tick % 2);
                    }
                    break;
            }
        }
        /* while key not pressing, the role is still */
        else if (g_gx_ninjaclimb_context.up_key_pressed != TRUE && g_gx_ninjaclimb_context.down_key_pressed != TRUE)
        {
            switch (g_gx_ninjaclimb_context.pos_state)
            {
                    /* all LEFT cases */
                case LEFT_ROPE_LEFT:
                case MID_ROPE_LEFT:
                case RIGHT_ROPE_LEFT:
                    role_image = IMG_ID_GX_NINJACLIMB_ROLE_LEFT_FRAME_0;
                    break;
                    /* all RIGHT cases */
                case LEFT_ROPE_RIGHT:
                case MID_ROPE_RIGHT:
                case RIGHT_ROPE_RIGHT:
                    role_image = IMG_ID_GX_NINJACLIMB_ROLE_RIGHT_FRAME_0;
                    break;
            }
        }

        /* while the role is flying */
        if (g_gx_ninjaclimb_context.state == FLYING)
        {
            /* check if the role get the clock */
            if (g_gx_ninjaclimb_context.clock_falling != FALSE)
            {
                /* the role from left_tree to mid_tree or from mid_tree to left_tree */
                /* or the role from right_tree to mid_tree or from mid_tree to right_tree */
                if ((g_gx_ninjaclimb_context.clock_pos_state == LEFT_SPACE &&
                        ((g_gx_ninjaclimb_context.old_pos_state == LEFT_ROPE_RIGHT &&
                          g_gx_ninjaclimb_context.pos_state == MID_ROPE_LEFT) ||
                         (g_gx_ninjaclimb_context.pos_state == LEFT_ROPE_RIGHT &&
                          g_gx_ninjaclimb_context.old_pos_state == MID_ROPE_LEFT))) ||
                        (g_gx_ninjaclimb_context.clock_pos_state == RIGHT_SPACE &&
                         ((g_gx_ninjaclimb_context.old_pos_state == RIGHT_ROPE_LEFT &&
                           g_gx_ninjaclimb_context.pos_state == MID_ROPE_RIGHT) ||
                          (g_gx_ninjaclimb_context.pos_state == RIGHT_ROPE_LEFT &&
                           g_gx_ninjaclimb_context.old_pos_state == MID_ROPE_RIGHT))))
                {
                    /* the role does touch the clock */
                    if ((g_gx_ninjaclimb_context.position.y >= g_gx_ninjaclimb_context.clock_position_y &&
                            g_gx_ninjaclimb_context.position.y <
                            g_gx_ninjaclimb_context.clock_position_y + MMI_GX_NINJACLIMB_CLOCK_HEIGHT) ||
                            (g_gx_ninjaclimb_context.clock_position_y >= g_gx_ninjaclimb_context.position.y &&
                             g_gx_ninjaclimb_context.clock_position_y <
                             g_gx_ninjaclimb_context.position.y + MMI_GX_NINJACLIMB_ROLE_HEIGHT))
                    {
                        /* extend 20 seconds */
                        g_gx_ninjaclimb_context.total_time = g_gx_ninjaclimb_context.total_time + MMI_GX_NINJACLIMB_TIME_EXTENSION;
                        g_gx_ninjaclimb_context.clock_falling = FALSE;


                        GFX_PLAY_AUDIO_DVI(NinjaEat_dvi, NINJAEAT_DVI, DEVICE_AUDIO_PLAY_ONCE);
                    }
                }
                if (g_gx_ninjaclimb_context.total_time > 99)
                {
                    g_gx_ninjaclimb_context.total_time = 99;
                }
            }
        }
    }
    /* while the role is dying */
    else
    {
        if (g_gx_ninjaclimb_context.pos_state == LEFT_ROPE_LEFT || g_gx_ninjaclimb_context.pos_state == MID_ROPE_LEFT || g_gx_ninjaclimb_context.pos_state == RIGHT_ROPE_LEFT )
        {
            role_image = IMG_ID_GX_NINJACLIMB_ROLE_FALL_LEFT_FRAME_0 + (g_gx_ninjaclimb_context.tick % 2);
        }
        if (g_gx_ninjaclimb_context.pos_state == LEFT_ROPE_RIGHT || g_gx_ninjaclimb_context.pos_state == MID_ROPE_RIGHT || g_gx_ninjaclimb_context.pos_state == RIGHT_ROPE_RIGHT )
        {
            role_image = IMG_ID_GX_NINJACLIMB_ROLE_FALL_RIGHT_FRAME_0 + (g_gx_ninjaclimb_context.tick % 2);
        }
    }

    g_gx_ninjaclimb_context.old_position = g_gx_ninjaclimb_context.position;
    g_gx_ninjaclimb_context.old_pos_state = g_gx_ninjaclimb_context.pos_state;
    if (g_gx_ninjaclimb_context.old_state == FLYING)
    {
        g_gx_ninjaclimb_context.old_state = NORMAL;
    }

    /* Last, draw the role image because it should be on top of the layer to show correct display order */
    if (g_gx_ninjaclimb_context.state != FLYING)
    {
        gdi_image_draw_id(g_gx_ninjaclimb_context.position.x, g_gx_ninjaclimb_context.position.y, role_image);
    }
    /* set the flying role's position to the landing position */
    if (g_gx_ninjaclimb_context.state == FLYING)
    {
        g_gx_ninjaclimb_context.state = NORMAL;
        g_gx_ninjaclimb_context.old_state = FLYING;
        g_gx_ninjaclimb_context.position.x = mmi_gx_ninjaclimb_get_x_position(g_gx_ninjaclimb_context.pos_state, MMI_GX_NINJACLIMB_IS_ROLE);
    }

    /* if the role is dying */
    if (g_gx_ninjaclimb_context.is_dying != FALSE)
    {
        g_gx_ninjaclimb_context.position.y = g_gx_ninjaclimb_context.position.y + MMI_GX_NINJACLIMB_FALLING_SPEED;
        if (g_gx_ninjaclimb_context.position.y > MMI_GX_NINJACLIMB_LCD_HEIGHT)
        {
            mmi_gx_ninjaclimb_gameover();
            gdi_layer_set_active(g_gx_ninjaclimb_context.background);
            return;
        }
    }

    gdi_layer_blt(
        g_gx_ninjaclimb_context.background,  /* layer 0 */
        g_gx_ninjaclimb_context.foreground,  /* layer 1 */
        0,                              /* layer 2 */
        0,                              /* layer 3 */
        0,                              /* offset x */
        0,                              /* offset y */
        UI_device_width - 1,            /* widht */
        UI_device_height - 1);          /* height */

    gdi_layer_set_active(g_gx_ninjaclimb_context.background);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_ninjaclimb_draw_digits
 * DESCRIPTION
 *  Drawing digits
 * PARAMETERS
 *  x           [IN]        X position for images
 *  y           [IN]        Y position for images
 *  number      [IN]        The number to be displayed
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_ninjaclimb_draw_digits(U16 x, U16 y, U16 number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 bits;
    U8 current_digit;
    U8 i, j;
    U16 curr_start_x;
    U16 score;
    U16 bias;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_start_x = x;

    score = number;
    bits = 1;
    while ((score / 10) != 0 )
    {
        score /= 10;
        bits++;
    }

    score = number;
    for (i = bits ; i > 0; i--)
    {
        bias = 1;
        for (j = 1; j < i; j++)
        {
            bias *= 10;
        }
        current_digit = number / bias % 10;
        gdi_image_draw_id(curr_start_x + MMI_GX_NINJACLIMB_DIGIT_WIDTH * (bits - i) - 6, y, IMG_ID_GX_NINJACLIMB_DIGIT_0 + current_digit);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_ninjaclimb_turn_or_fly
 * DESCRIPTION
 *  React to turn left or turn right action
 * PARAMETERS
 *  action      [IN]        Indicate the input is left-pressing or right-pressing
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_ninjaclimb_turn_or_fly(U8 action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if the role is dying, we don't need to process the key press */
    if (g_gx_ninjaclimb_context.is_dying != FALSE)
    {
        return;
    }

    g_gx_ninjaclimb_context.old_pos_state = g_gx_ninjaclimb_context.pos_state;

    if (action == MMI_GX_NINJACLIMB_GO_LEFT)
    {
        /* it's not in the leftmost position thus there is action happen */
        if (g_gx_ninjaclimb_context.pos_state != LEFT_ROPE_LEFT)
        {
            g_gx_ninjaclimb_context.pos_state = g_gx_ninjaclimb_context.pos_state - 1;
            if ((g_gx_ninjaclimb_context.pos_state - LEFT_ROPE_LEFT) % 2 == 1)
            {
                g_gx_ninjaclimb_context.state = FLYING;
            }
        }
    }
    else if (action == MMI_GX_NINJACLIMB_GO_RIGHT)
    {
        /* it's not in the rightmost position thus there is action happen */
        if (g_gx_ninjaclimb_context.pos_state != RIGHT_ROPE_RIGHT)
        {
            g_gx_ninjaclimb_context.pos_state = g_gx_ninjaclimb_context.pos_state + 1;
            if ((g_gx_ninjaclimb_context.pos_state - LEFT_ROPE_LEFT) % 2 == 0)
            {
                g_gx_ninjaclimb_context.state = FLYING;
            }
        }
    }

    g_gx_ninjaclimb_context.position.x = mmi_gx_ninjaclimb_get_x_position(g_gx_ninjaclimb_context.pos_state, MMI_GX_NINJACLIMB_IS_ROLE);
    /* adjust the X-position in FLYING state */
    if (g_gx_ninjaclimb_context.state == FLYING)
    {
        g_gx_ninjaclimb_context.position.x =
            (g_gx_ninjaclimb_context.position.x +
             mmi_gx_ninjaclimb_get_x_position(g_gx_ninjaclimb_context.old_pos_state, MMI_GX_NINJACLIMB_IS_ROLE)) / 2;

        GFX_PLAY_AUDIO_DVI(NinjaBounce_dvi, NINJABOUNCE_DVI, DEVICE_AUDIO_PLAY_ONCE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_ninjaclimb_gameover
 * DESCRIPTION
 *  Gameover function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_ninjaclimb_gameover(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gx_ninjaclimb_context.is_gameover = TRUE;
    g_gx_ninjaclimb_context.is_new_game = TRUE;

    /* call this function to draw gameover screen */
    mmi_gfx_entry_gameover_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_ninjaclimb_cyclic_timer
 * DESCRIPTION
 *  Timer trigger function - looping
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_ninjaclimb_cyclic_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gx_ninjaclimb_context.tick = g_gx_ninjaclimb_context.tick + 1;

    gui_start_timer(g_gx_ninjaclimb_context.timer_elapse, mmi_gx_ninjaclimb_cyclic_timer);

    if (g_gx_ninjaclimb_context.is_gameover == FALSE)
    {
        mmi_gx_ninjaclimb_framemove();
        mmi_gx_ninjaclimb_render();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_ninjaclimb_key_2_press
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_ninjaclimb_key_2_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if the role is dying, we don't need to process the key press */
    if (g_gx_ninjaclimb_context.is_dying != FALSE)
    {
        return;
    }

    g_gx_ninjaclimb_context.up_key_pressed = TRUE;

    GFX_PLAY_AUDIO_DVI(NinjaUp_down_dvi, NINJAUP_DOWN_DVI, DEVICE_AUDIO_PLAY_ONCE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_ninjaclimb_key_8_press
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_ninjaclimb_key_8_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if the role is dying, we don't need to process the key press */
    if (g_gx_ninjaclimb_context.is_dying != FALSE)
    {
        return;
    }

    g_gx_ninjaclimb_context.down_key_pressed = TRUE;

    GFX_PLAY_AUDIO_DVI(NinjaUp_down_dvi, NINJAUP_DOWN_DVI, DEVICE_AUDIO_PLAY_ONCE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_ninjaclimb_key_5_press
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_ninjaclimb_key_5_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if the role is dying or flying, we don't need to process the key press */
    if (g_gx_ninjaclimb_context.is_dying != FALSE || g_gx_ninjaclimb_context.state == FLYING)
    {
        return;
    }

    /* if at the button, cant go down anymore */
    if (g_gx_ninjaclimb_context.position.y == MMI_GX_NINJACLIMB_LCD_HEIGHT - MMI_GX_NINJACLIMB_ROLE_HEIGHT - 1)
    {
        return;
    }

    g_gx_ninjaclimb_context.state = ATTACK;
    g_gx_ninjaclimb_context.down_key_pressed = TRUE;

    GFX_PLAY_AUDIO_DVI(NinjaDown_dvi, NINJADOWN_DVI, DEVICE_AUDIO_PLAY_ONCE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_ninjaclimb_key_2_release
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_ninjaclimb_key_2_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gx_ninjaclimb_context.up_key_pressed = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_ninjaclimb_key_8_release
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_ninjaclimb_key_8_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gx_ninjaclimb_context.down_key_pressed = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_ninjaclimb_key_5_release
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_ninjaclimb_key_5_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gx_ninjaclimb_context.down_key_pressed = FALSE;
    g_gx_ninjaclimb_context.state = NORMAL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_ninjaclimb_key_4_press
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_ninjaclimb_key_4_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_gx_ninjaclimb_turn_or_fly(MMI_GX_NINJACLIMB_GO_LEFT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_ninjaclimb_key_6_press
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_ninjaclimb_key_6_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_gx_ninjaclimb_turn_or_fly(MMI_GX_NINJACLIMB_GO_RIGHT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_ninjaclimb_get_x_position
 * DESCRIPTION
 *  Calculate the x position of objects from its position-state
 * PARAMETERS
 *  state       [IN]        Current position-state of object.
 *  type        [IN]        Type of object
 * RETURNS
 *  The position in X-direction
 *****************************************************************************/
S16 mmi_gx_ninjaclimb_get_x_position(gx_ninjaclimb_pos_state_enum state, U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 offset = 0;
    S16 object_width = 0;
    S16 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == MMI_GX_NINJACLIMB_IS_ROLE || type == MMI_GX_NINJACLIMB_IS_DYING_ROLE)
    {
        offset = MMI_GX_NINJACLIMB_ROLE_OFFSET;
        object_width = MMI_GX_NINJACLIMB_ROLE_WIDTH;
    }
    else if (type == MMI_GX_NINJACLIMB_IS_ENEMY || type == MMI_GX_NINJACLIMB_IS_DYING_ENEMY)
    {
        offset = MMI_GX_NINJACLIMB_ENEMY_OFFSET;
        object_width = MMI_GX_NINJACLIMB_ENEMY_WIDTH;
    }
    else if (type == MMI_GX_NINJACLIMB_IS_CLOCK)
    {
        switch (state)
        {
            case LEFT_SPACE:
                return MMI_GX_NINJACLIMB_LEFT_SPACE_X;
            case RIGHT_SPACE:
                return MMI_GX_NINJACLIMB_RIGHT_SPACE_X;
        }
    }

    switch (state)
    {
        case LEFT_ROPE_LEFT:
            result = MMI_GX_NINJACLIMB_LEFT_NINJA - (object_width - offset);
            if (type == MMI_GX_NINJACLIMB_IS_DYING_ROLE)
            {
                result = result - MMI_GX_NINJACLIMB_DYING_ROLE_OFFSET_X;
            }
            else if (type == MMI_GX_NINJACLIMB_IS_DYING_ENEMY)
            {
                result = result - MMI_GX_NINJACLIMB_DYING_ENEMY_OFFSET_X;
            }
            break;
        case LEFT_ROPE_RIGHT:
            result = MMI_GX_NINJACLIMB_LEFT_NINJA + MMI_GX_NINJACLIMB_ROPE_WIDTH - offset;
            if (type == MMI_GX_NINJACLIMB_IS_DYING_ROLE)
            {
                result = result + MMI_GX_NINJACLIMB_DYING_ROLE_OFFSET_X;
            }
            else if (type == MMI_GX_NINJACLIMB_IS_DYING_ENEMY)
            {
                result = result + MMI_GX_NINJACLIMB_DYING_ENEMY_OFFSET_X;
            }
            break;
        case MID_ROPE_LEFT:
            result = MMI_GX_NINJACLIMB_MID_NINJA - (object_width - offset);
            if (type == MMI_GX_NINJACLIMB_IS_DYING_ROLE)
            {
                result = result - MMI_GX_NINJACLIMB_DYING_ROLE_OFFSET_X;
            }
            else if (type == MMI_GX_NINJACLIMB_IS_DYING_ENEMY)
            {
                result = result - MMI_GX_NINJACLIMB_DYING_ENEMY_OFFSET_X;
            }
            break;
        case MID_ROPE_RIGHT:
            result = MMI_GX_NINJACLIMB_MID_NINJA + MMI_GX_NINJACLIMB_ROPE_WIDTH - offset;
            if (type == MMI_GX_NINJACLIMB_IS_DYING_ROLE)
            {
                result = result + MMI_GX_NINJACLIMB_DYING_ROLE_OFFSET_X;
            }
            else if (type == MMI_GX_NINJACLIMB_IS_DYING_ENEMY)
            {
                result = result + MMI_GX_NINJACLIMB_DYING_ENEMY_OFFSET_X;
            }
            break;
        case RIGHT_ROPE_LEFT:
            result = MMI_GX_NINJACLIMB_RIGHT_NINJA - (object_width - offset);
            if (type == MMI_GX_NINJACLIMB_IS_DYING_ROLE)
            {
                result = result - MMI_GX_NINJACLIMB_DYING_ROLE_OFFSET_X;
            }
            else if (type == MMI_GX_NINJACLIMB_IS_DYING_ENEMY)
            {
                result = result - MMI_GX_NINJACLIMB_DYING_ENEMY_OFFSET_X;
            }
            break;
        case RIGHT_ROPE_RIGHT:
            result = MMI_GX_NINJACLIMB_RIGHT_NINJA + MMI_GX_NINJACLIMB_ROPE_WIDTH - offset;
            if (type == MMI_GX_NINJACLIMB_IS_DYING_ROLE)
            {
                result = result + MMI_GX_NINJACLIMB_DYING_ROLE_OFFSET_X;
            }
            else if (type == MMI_GX_NINJACLIMB_IS_DYING_ENEMY)
            {
                result = result + MMI_GX_NINJACLIMB_DYING_ENEMY_OFFSET_X;
            }
            break;
    }

    return result;
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_gx_ninjaclimb_pen_down_hdlr
 * DESCRIPTION
 *  pen down event handler
 * PARAMETERS
 *  pos     [IN]        Position of pen
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_ninjaclimb_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* if the role is dying or flying, we don't need to process the key press */
    if (g_gx_ninjaclimb_context.is_dying || g_gx_ninjaclimb_context.state == FLYING)
    {
        return;
    }

    if (pos.x >= g_gx_ninjaclimb_context.position.x - MMI_GX_NINJACLIMB_ROLE_WIDTH/2 && pos.x <= g_gx_ninjaclimb_context.position.x + MMI_GX_NINJACLIMB_ROLE_WIDTH*3/2 &&
            pos.y >= g_gx_ninjaclimb_context.position.y - MMI_GX_NINJACLIMB_ROLE_HEIGHT/2 && pos.y <= g_gx_ninjaclimb_context.position.y + MMI_GX_NINJACLIMB_ROLE_HEIGHT*3/2)
    {
        g_gx_ninjaclimb_context.is_pen_hit = MMI_TRUE;
        g_gx_ninjaclimb_context.pen_down_pos.x = pos.x;
        g_gx_ninjaclimb_context.pen_down_pos.y = pos.y;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_ninjaclimb_pen_up_hdlr
 * DESCRIPTION
 *  pen up event handler
 * PARAMETERS
 *  pos     [IN]        Position of pen
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_ninjaclimb_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* if the role is dying or flying, we don't need to process the key press */
    if (g_gx_ninjaclimb_context.is_dying || g_gx_ninjaclimb_context.state == FLYING)
    {
        return;
    }

    if (g_gx_ninjaclimb_context.is_pen_hit)
    {
        S16 diff_x = pos.x - g_gx_ninjaclimb_context.pen_down_pos.x;
        S16 diff_y = pos.y - g_gx_ninjaclimb_context.pen_down_pos.y;

        if (GFX_ABS(diff_y) <= MMI_GX_NINJACLIMB_MOVE_THRESHOLD*3 &&
                GFX_ABS(diff_x) > MMI_GX_NINJACLIMB_MOVE_THRESHOLD)
        {//horizontal move
            if (diff_x > 0)
            {
                mmi_gx_ninjaclimb_turn_or_fly(MMI_GX_NINJACLIMB_GO_RIGHT);
            }
            else
            {
                mmi_gx_ninjaclimb_turn_or_fly(MMI_GX_NINJACLIMB_GO_LEFT);
            }
            mmi_gx_ninjaclimb_cyclic_timer();
        }
        diff_x = pos.x - g_gx_ninjaclimb_context.pen_up_pos.x;
        diff_y = pos.y - g_gx_ninjaclimb_context.pen_up_pos.y;
        if (GFX_ABS(diff_y) <= MMI_GX_NINJACLIMB_MOVE_THRESHOLD &&
                GFX_ABS(diff_x) <= MMI_GX_NINJACLIMB_MOVE_THRESHOLD)                
        {
            mmi_gx_ninjaclimb_key_5_press();
            mmi_gx_ninjaclimb_cyclic_timer();
            mmi_gx_ninjaclimb_key_5_release();
            g_gx_ninjaclimb_context.pen_up_pos.x = -MMI_GX_NINJACLIMB_MOVE_THRESHOLD;
            g_gx_ninjaclimb_context.pen_up_pos.y = -MMI_GX_NINJACLIMB_MOVE_THRESHOLD;
        }
        else
        {
            g_gx_ninjaclimb_context.pen_up_pos.x = pos.x;
            g_gx_ninjaclimb_context.pen_up_pos.y = pos.y;
        }
    }
    g_gx_ninjaclimb_context.is_pen_hit = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_ninjaclimb_pen_move_hdlr
 * DESCRIPTION
 *  pen move event handler
 * PARAMETERS
 *  pos     [IN]        Position of pen
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_ninjaclimb_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* if the role is dying or flying, we don't need to process the key press */
    if (g_gx_ninjaclimb_context.is_dying || g_gx_ninjaclimb_context.state == FLYING)
    {
        return;
    }

    if (g_gx_ninjaclimb_context.is_pen_hit)
    {
        S16 diff_y = pos.y - g_gx_ninjaclimb_context.pen_down_pos.y;

        if (GFX_ABS(pos.x - g_gx_ninjaclimb_context.pen_down_pos.x) <= MMI_GX_NINJACLIMB_MOVE_THRESHOLD &&
                GFX_ABS(diff_y) > MMI_GX_NINJACLIMB_MOVE_THRESHOLD)
        {//vertical move
            g_gx_ninjaclimb_context.position.y = pos.y - MMI_GX_NINJACLIMB_ROLE_HEIGHT / 2;

            if (g_gx_ninjaclimb_context.position.y < MMI_GX_NINJACLIMB_TOP_MARGIN)
            {
                g_gx_ninjaclimb_context.position.y = MMI_GX_NINJACLIMB_TOP_MARGIN + 1;
            }
            else if (g_gx_ninjaclimb_context.position.y >= MMI_GX_NINJACLIMB_LCD_HEIGHT - MMI_GX_NINJACLIMB_ROLE_HEIGHT - 1)
            {
                g_gx_ninjaclimb_context.position.y = MMI_GX_NINJACLIMB_LCD_HEIGHT - MMI_GX_NINJACLIMB_ROLE_HEIGHT - 1;
            }
        }
    }
}

#endif  //__MMI_TOUCH_SCREEN__

#endif  //defined(__MMI_GAME_NINJACLIMB__)

