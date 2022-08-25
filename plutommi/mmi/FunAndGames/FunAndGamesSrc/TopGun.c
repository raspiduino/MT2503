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
 *  TopGun.c
 *
 * Project:
 * --------
 *  Maui
 *
 * Description:
 * ------------
 *  Game TopGun
 *
 * Author:
 * -------
 * -------
 * -------
 *
 ****************************************************************************/

#include "mmi_features.h"
#include "GameDefs.h"

#ifdef __MMI_GAME_TOPGUN__
#include "GameInc.h"
#include "TopGunProts.h"
#include "mmi_rp_app_games_def.h"

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__      //added for multi-language
#include "GameProts.h"
#endif


/***************************************************************************** 
* Define
*****************************************************************************/
#if defined(__MMI_MAINLCD_128X160__)
#define MMI_GX_TOPGUN_LCD_HEIGHT                (160)
#define MMI_GX_TOPGUN_LCD_WIDTH                 (128)
#elif defined(__MMI_MAINLCD_128X128__)
#define MMI_GX_TOPGUN_LCD_HEIGHT                (128)
#define MMI_GX_TOPGUN_LCD_WIDTH                 (128)
#elif defined(__MMI_MAINLCD_176X220__)
#define MMI_GX_TOPGUN_LCD_HEIGHT                (220)
#define MMI_GX_TOPGUN_LCD_WIDTH                 (176)
#elif defined(__MMI_MAINLCD_240X320__)
#define MMI_GX_TOPGUN_LCD_HEIGHT                (320)
#define MMI_GX_TOPGUN_LCD_WIDTH                 (240)
#endif 


#if defined(__MMI_MAINLCD_128X128__)

#define MMI_GX_TOPGUN_FIGHTER_SPEED             (4)
#define MMI_GX_TOPGUN_BACKGROUND_SPEED          (3)
#define MMI_GX_TOPGUN_ORIGIN                    (13)
#define MMI_GX_TOPGUN_ENERGY_UNIT_WIDTH         (6)
#define MMI_GX_TOPGUN_DIGIT_WIDTH               (5)
#define MMI_GX_TOPGUN_ROLE_WIDTH                (21)
#define MMI_GX_TOPGUN_ROLE_HEIGHT               (29)
#define MMI_GX_TOPGUN_BULLET_SPEED              (MMI_GX_TOPGUN_FIGHTER_SPEED)
#define MMI_GX_TOPGUN_BULLET_WIDTH              (5)
#define MMI_GX_TOPGUN_BULLET_HEIGHT             (26)
#define MMI_GX_TOPGUN_BOSS_WIDTH                (22)
#define MMI_GX_TOPGUN_BOSS_HEIGHT               (27)
#define MMI_GX_TOPGUN_BOSS_BULLET_WIDTH         (15)
#define MMI_GX_TOPGUN_BOSS_BULLET_HEIGHT        (17)
#define MMI_GX_TOPGUN_ENEMY_BULLET_HEIGHT       (7)
#define MMI_GX_TOPGUN_ENEMY_BULLET_WIDTH        (12)
#define MMI_GX_TOPGUN_ENEMY_WIDTH               (21)
#define MMI_GX_TOPGUN_ENEMY_HEIGHT              (18)
#define MMI_GX_TOPGUN_ENEMY_BULLET_SPEED        (4)
#define MMI_GX_TOPGUN_TREASURE_SPEED            (MMI_GX_TOPGUN_FIGHTER_SPEED)
#define MMI_GX_TOPGUN_TREASURE_HEIGHT           (11)
#define MMI_GX_TOPGUN_TREASURE_WIDTH            (13)

#define MMI_GX_TOPGUN_SCORE_X                   (1)

#define MMI_GX_TOPGUN_SCORE_TEXT_X             (58)

#define MMI_GX_TOPGUN_ENERGY_X                 (62)

#define MMI_GX_TOPGUN_ENERGY_TEXT_X            (100)

#define MMI_GX_TOPGUN_INFO_HEIGHT               (12)  //score and level bar height

#define MMI_GX_TOPGUN_LEVEL_CLEAR_WIDTH          (102)
#define MMI_GX_TOPGUN_LEVEL_CLEAR_HEIGHT         (28)

#define MMI_GX_TOPGUN_ENEMY_VELOCITY_X         (2)
#define MMI_GX_TOPGUN_ENEMY_VELOCITY_Y         (4)
#define MMI_GX_TOPGUN_BOSS_VELOCITY_Y          (6)

#define MMI_GX_TOPGUN_ENEMY_HORIZONTAL_INTERVAL_FACTOR (13) 

#define MMI_GX_TOPGUN_MOVE_TYPE_6_REVERT_TIME_MIN (27)
#define MMI_GX_TOPGUN_MOVE_TYPE_6_REVERT_TIME_MAX (42)

#define MMI_GX_TOPGUN_MOVE_TYPE_7_REVERT_TIME_MIN (41)
#define MMI_GX_TOPGUN_MOVE_TYPE_7_REVERT_TIME_MAX (55)

#elif defined(__MMI_MAINLCD_128X160__)

#define MMI_GX_TOPGUN_FIGHTER_SPEED             (5)
#define MMI_GX_TOPGUN_BACKGROUND_SPEED          (3)
#define MMI_GX_TOPGUN_ORIGIN                    (13)
#define MMI_GX_TOPGUN_ENERGY_UNIT_WIDTH         (6)
#define MMI_GX_TOPGUN_DIGIT_WIDTH               (5)
#define MMI_GX_TOPGUN_ROLE_WIDTH                (21)
#define MMI_GX_TOPGUN_ROLE_HEIGHT               (29)
#define MMI_GX_TOPGUN_BULLET_SPEED              (MMI_GX_TOPGUN_FIGHTER_SPEED)
#define MMI_GX_TOPGUN_BULLET_WIDTH              (5)
#define MMI_GX_TOPGUN_BULLET_HEIGHT             (26)
#define MMI_GX_TOPGUN_BOSS_WIDTH                (22)
#define MMI_GX_TOPGUN_BOSS_HEIGHT               (27)
#define MMI_GX_TOPGUN_BOSS_BULLET_WIDTH         (15)
#define MMI_GX_TOPGUN_BOSS_BULLET_HEIGHT        (17)
#define MMI_GX_TOPGUN_ENEMY_BULLET_HEIGHT       (7)
#define MMI_GX_TOPGUN_ENEMY_BULLET_WIDTH        (12)
#define MMI_GX_TOPGUN_ENEMY_WIDTH               (21)
#define MMI_GX_TOPGUN_ENEMY_HEIGHT              (18)
#define MMI_GX_TOPGUN_ENEMY_BULLET_SPEED        (4)
#define MMI_GX_TOPGUN_TREASURE_SPEED            (MMI_GX_TOPGUN_FIGHTER_SPEED)
#define MMI_GX_TOPGUN_TREASURE_HEIGHT           (11)
#define MMI_GX_TOPGUN_TREASURE_WIDTH            (13)

#define MMI_GX_TOPGUN_SCORE_X                   (1)

#define MMI_GX_TOPGUN_SCORE_TEXT_X             (58)

#define MMI_GX_TOPGUN_ENERGY_X                 (62)

#define MMI_GX_TOPGUN_ENERGY_TEXT_X            (100)

#define MMI_GX_TOPGUN_INFO_HEIGHT               (12)  //score and level bar height

#define MMI_GX_TOPGUN_LEVEL_CLEAR_WIDTH          (102)
#define MMI_GX_TOPGUN_LEVEL_CLEAR_HEIGHT         (28)

#define MMI_GX_TOPGUN_ENEMY_VELOCITY_X         (2)
#define MMI_GX_TOPGUN_ENEMY_VELOCITY_Y         (4)
#define MMI_GX_TOPGUN_BOSS_VELOCITY_Y          (6)

#define MMI_GX_TOPGUN_ENEMY_HORIZONTAL_INTERVAL_FACTOR (13) 

#define MMI_GX_TOPGUN_MOVE_TYPE_6_REVERT_TIME_MIN (27)
#define MMI_GX_TOPGUN_MOVE_TYPE_6_REVERT_TIME_MAX (42)

#define MMI_GX_TOPGUN_MOVE_TYPE_7_REVERT_TIME_MIN (41)
#define MMI_GX_TOPGUN_MOVE_TYPE_7_REVERT_TIME_MAX (55)

#elif defined(__MMI_MAINLCD_176X220__)

#define MMI_GX_TOPGUN_FIGHTER_SPEED             (6)
#define MMI_GX_TOPGUN_BACKGROUND_SPEED          (3)
#define MMI_GX_TOPGUN_ORIGIN                    (13)
#define MMI_GX_TOPGUN_ENERGY_UNIT_WIDTH         (6)
#define MMI_GX_TOPGUN_DIGIT_WIDTH               (7)
#define MMI_GX_TOPGUN_ROLE_WIDTH                (21)
#define MMI_GX_TOPGUN_ROLE_HEIGHT               (29)
#define MMI_GX_TOPGUN_BULLET_SPEED              (MMI_GX_TOPGUN_FIGHTER_SPEED)
#define MMI_GX_TOPGUN_BULLET_WIDTH              (5)
#define MMI_GX_TOPGUN_BULLET_HEIGHT             (26)
#define MMI_GX_TOPGUN_BOSS_WIDTH                (22)
#define MMI_GX_TOPGUN_BOSS_HEIGHT               (27)
#define MMI_GX_TOPGUN_BOSS_BULLET_WIDTH         (15)
#define MMI_GX_TOPGUN_BOSS_BULLET_HEIGHT        (17)
#define MMI_GX_TOPGUN_ENEMY_BULLET_HEIGHT       (7)
#define MMI_GX_TOPGUN_ENEMY_BULLET_WIDTH        (12)
#define MMI_GX_TOPGUN_ENEMY_WIDTH               (21)
#define MMI_GX_TOPGUN_ENEMY_HEIGHT              (18)
#define MMI_GX_TOPGUN_ENEMY_BULLET_SPEED        (4)
#define MMI_GX_TOPGUN_TREASURE_SPEED            (MMI_GX_TOPGUN_FIGHTER_SPEED)
#define MMI_GX_TOPGUN_TREASURE_HEIGHT           (11)
#define MMI_GX_TOPGUN_TREASURE_WIDTH            (13)

#define MMI_GX_TOPGUN_SCORE_X                   (4)

#define MMI_GX_TOPGUN_SCORE_TEXT_X             (78)

#define MMI_GX_TOPGUN_ENERGY_X                 (92)

#define MMI_GX_TOPGUN_ENERGY_TEXT_X            (142)

#define MMI_GX_TOPGUN_INFO_HEIGHT               (13)  //score and level bar height

#define MMI_GX_TOPGUN_LEVEL_CLEAR_WIDTH          (102)
#define MMI_GX_TOPGUN_LEVEL_CLEAR_HEIGHT         (28)

#define MMI_GX_TOPGUN_ENEMY_VELOCITY_X         (2)
#define MMI_GX_TOPGUN_ENEMY_VELOCITY_Y         (4)
#define MMI_GX_TOPGUN_BOSS_VELOCITY_Y          (6)

#define MMI_GX_TOPGUN_ENEMY_HORIZONTAL_INTERVAL_FACTOR (12) 

#define MMI_GX_TOPGUN_MOVE_TYPE_6_REVERT_TIME_MIN (27)
#define MMI_GX_TOPGUN_MOVE_TYPE_6_REVERT_TIME_MAX (42)

#define MMI_GX_TOPGUN_MOVE_TYPE_7_REVERT_TIME_MIN (41)
#define MMI_GX_TOPGUN_MOVE_TYPE_7_REVERT_TIME_MAX (55)

#elif defined(__MMI_MAINLCD_240X320__)
#define MMI_GX_TOPGUN_FIGHTER_SPEED             (7)
#define MMI_GX_TOPGUN_BACKGROUND_SPEED          (5)
#define MMI_GX_TOPGUN_ORIGIN                    (13)
#define MMI_GX_TOPGUN_ENERGY_UNIT_WIDTH         (6)
#define MMI_GX_TOPGUN_DIGIT_WIDTH               (7)
#define MMI_GX_TOPGUN_ROLE_WIDTH                (26)
#define MMI_GX_TOPGUN_ROLE_HEIGHT               (40)
#define MMI_GX_TOPGUN_BULLET_SPEED              (MMI_GX_TOPGUN_FIGHTER_SPEED)
#define MMI_GX_TOPGUN_BULLET_WIDTH              (5)
#define MMI_GX_TOPGUN_BULLET_HEIGHT             (35)
#define MMI_GX_TOPGUN_BOSS_WIDTH                (29)
#define MMI_GX_TOPGUN_BOSS_HEIGHT               (36)
#define MMI_GX_TOPGUN_BOSS_BULLET_WIDTH         (19)
#define MMI_GX_TOPGUN_BOSS_BULLET_HEIGHT        (21)
#define MMI_GX_TOPGUN_ENEMY_WIDTH               (21)
#define MMI_GX_TOPGUN_ENEMY_HEIGHT              (18)
#define MMI_GX_TOPGUN_ENEMY_BULLET_WIDTH        (8)
#define MMI_GX_TOPGUN_ENEMY_BULLET_HEIGHT       (14)
#define MMI_GX_TOPGUN_ENEMY_BULLET_SPEED        (4)
#define MMI_GX_TOPGUN_TREASURE_SPEED            (MMI_GX_TOPGUN_FIGHTER_SPEED)
#define MMI_GX_TOPGUN_TREASURE_HEIGHT           (16)
#define MMI_GX_TOPGUN_TREASURE_WIDTH            (16)

#define MMI_GX_TOPGUN_SCORE_X                   (10)

#define MMI_GX_TOPGUN_SCORE_TEXT_X             (88)

#define MMI_GX_TOPGUN_ENERGY_X                 (128)

#define MMI_GX_TOPGUN_ENERGY_TEXT_X            (188)

#define MMI_GX_TOPGUN_INFO_HEIGHT               (11)  //score and level bar height

#define MMI_GX_TOPGUN_LEVEL_CLEAR_WIDTH          (102)
#define MMI_GX_TOPGUN_LEVEL_CLEAR_HEIGHT         (28)

#define MMI_GX_TOPGUN_ENEMY_VELOCITY_X         (2)
#define MMI_GX_TOPGUN_ENEMY_VELOCITY_Y         (4)
#define MMI_GX_TOPGUN_BOSS_VELOCITY_Y          (6)

#define MMI_GX_TOPGUN_ENEMY_HORIZONTAL_INTERVAL_FACTOR (13) 

#define MMI_GX_TOPGUN_MOVE_TYPE_6_REVERT_TIME_MIN (27)
#define MMI_GX_TOPGUN_MOVE_TYPE_6_REVERT_TIME_MAX (42)

#define MMI_GX_TOPGUN_MOVE_TYPE_7_REVERT_TIME_MIN (41)
#define MMI_GX_TOPGUN_MOVE_TYPE_7_REVERT_TIME_MAX (55)

#endif 

#define MMI_GX_TOPGUN_LEVEL_CLEAR_X            ((LCD_WIDTH-MMI_GX_TOPGUN_LEVEL_CLEAR_WIDTH)/2)
#define MMI_GX_TOPGUN_LEVEL_CLEAR_Y            ((LCD_HEIGHT-MMI_GX_TOPGUN_ORIGIN-MMI_GX_TOPGUN_LEVEL_CLEAR_HEIGHT)/2)

#define MMI_GX_TOPGUN_INFO_Y                    (2)

#define MMI_GX_TOPGUN_MAX_SCORE_DIGIT             (5)
#define MMI_GX_TOPGUN_SCORE_TEXT_X1            (MMI_GX_TOPGUN_SCORE_TEXT_X-MMI_GX_TOPGUN_DIGIT_WIDTH*MMI_GX_TOPGUN_MAX_SCORE_DIGIT)

#define MMI_GX_TOPGUN_BACKGROUND_MAX_MOVE_Y     (MMI_GX_TOPGUN_BACKGROUND_HEIGHT+MMI_GX_TOPGUN_ORIGIN-MMI_GX_TOPGUN_LCD_HEIGHT)

#define MMI_GX_TOPGUN_FIGHTER_INIT_X            ((MMI_GX_TOPGUN_LCD_WIDTH-MMI_GX_TOPGUN_ROLE_WIDTH)/2)

#define MMI_GX_TOPGUN_ENERGY_UNIT_COUNT         (4)
#define MMI_GX_TOPGUN_BULLET_INTERVAL           (MMI_GX_TOPGUN_BULLET_HEIGHT / MMI_GX_TOPGUN_BULLET_SPEED + 2)
#define MMI_GX_TOPGUN_BULLET_COUNT              (MMI_GX_TOPGUN_LCD_HEIGHT / MMI_GX_TOPGUN_BULLET_SPEED / MMI_GX_TOPGUN_BULLET_INTERVAL + 3)
#define MMI_GX_TOPGUN_ENEMY_COUNT               (10)
#define MMI_GX_TOPGUN_ENEMY_BULLET_COUNT        (3 * MMI_GX_TOPGUN_ENEMY_COUNT)
#define MMI_GX_TOPGUN_ENEMY_INTERVAL            (7)
#define MMI_GX_TOPGUN_ENEMY_IMAGE_COUNT         (4)
#define MMI_GX_TOPGUN_ENEMY_BULLET_IMAGE_COUNT  (2)
#define MMI_GX_TOPGUN_ENEMY_LIFE_BASE           (1)
#define MMI_GX_TOPGUN_INVINCIBLE_INTERVAL       (60)
#define MMI_GX_TOPGUN_ENEMY_SCORE               (2)
#define MMI_GX_TOPGUN_ENEMY_PATTERN_NUMBER      (3)
#define MMI_GX_TOPGUN_STAGE_INTERVAL            (50)

#define MMI_GX_TOPGUN_BOSS_APPEAR_TIME  (MMI_GX_TOPGUN_STAGE_INTERVAL * 4 + 10)//(MMI_GX_TOPGUN_STAGE_INTERVAL * 4 + 70)
                                                                         

/***************************************************************************** 
* Typedef 
*****************************************************************************/
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
//added for multi-language support
typedef enum
{
    MMI_TOPGUN_STRING_LEVEL_CLEAR,
    MMI_TOPGUN_STRING_ENERGY,
    MMI_TOPGUN_STRING_SCORE,
    MMI_TOPGUN_STRING_TOTAL
} mmi_topgun_string_enum;
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

typedef enum
{
    TOPGUN_OFF = 0,
    TOPGUN_SHOOT,
    TOPGUN_HIT,
    TOPGUN_EXPLODING,
    TOPGUN_EAT
} audio_priority;

typedef enum
{
    MMI_GX_TOPGUN_NORMAL_STATE,
    MMI_GX_TOPGUN_HIT_STATE,
    MMI_GX_TOPGUN_EXPLODING_STATE_0,
    MMI_GX_TOPGUN_EXPLODING_STATE_1,
    MMI_GX_TOPGUN_EXPLODING_STATE_2,
    MMI_GX_TOPGUN_EXPLODING_STATE_3,
    MMI_GX_TOPGUN_EXPLODING_STATE_END 
} mmi_gx_topgun_state_enum;

typedef enum
{
    MMI_GX_TOPGUN_BULLET_1 = 1,
    MMI_GX_TOPGUN_BULLET_2,
    MMI_GX_TOPGUN_BULLET_3
} mmi_gx_topgun_bullet_enum;

typedef enum
{
    MMI_GX_TOPGUN_MOVE_TYPE_1,        /* vertical */
    MMI_GX_TOPGUN_MOVE_TYPE_2,        /* straight with slope */
    MMI_GX_TOPGUN_MOVE_TYPE_3,        /* straight with -slope (compared with above) */
    MMI_GX_TOPGUN_MOVE_TYPE_4,        /* zig-zag */
    MMI_GX_TOPGUN_MOVE_TYPE_5,        /* zig-zag in another direction (compared with above) */
    MMI_GX_TOPGUN_MOVE_TYPE_6,        /* U turn */
    MMI_GX_TOPGUN_MOVE_TYPE_7,        /* U turn in another direction (compared with above */
    MMI_GX_TOPGUN_MOVE_TYPE_COUNT
} mmi_gx_topgun_move_type_enum;

typedef enum
{
    MMI_GX_TOPGUN_ATTACK_TYPE_1,
    MMI_GX_TOPGUN_ATTACK_TYPE_2,
    MMI_GX_TOPGUN_ATTACK_TYPE_3,
    MMI_GX_TOPGUN_ATTACK_TYPE_COUNT
} mmi_gx_topgun_attack_type_enum;

typedef enum
{
    MMI_GX_TOPGUN_ENERGY_TREASURE = 1,
    MMI_GX_TOPGUN_WEAPON_TREASURE,
    MMI_GX_TOPGUN_BOMB_TREASURE,
    MMI_GX_TOPGUN_INVINCIBLE_TREASURE
} mmi_gx_topgun_trease_enum;

typedef struct t_topgun_bullet
{
    U8 x;
    S16 y;
    U8 old_x;
    S16 old_y;
    U8 type;
    struct t_topgun_bullet *previous;
    struct t_topgun_bullet *next;
} gx_topgun_bullet_struct;

typedef struct t_topgun_enemy
{
    S16 x;
    S16 y;
    S16 old_x;
    S16 old_y;
    U8 move_type;
    U8 attack_type;
    S16 vector_x;
    S16 vector_y;
    U16 starting_time;
    S16 life;
    U8 image_offset;
    U8 state;
    struct t_topgun_enemy *previous;
    struct t_topgun_enemy *next;
} gx_topgun_enemy_struct;

typedef struct t_topgun_e_bullet
{
    S16 x;
    S16 y;
    S16 old_x;
    S16 old_y;
    S16 vector_x;
    S16 vector_y;
    U8 image_offset;
    struct t_topgun_e_bullet *previous;
    struct t_topgun_e_bullet *next;
} gx_topgun_enemy_bullet_struct;

/* game context */
typedef struct
{
    MMI_BOOL is_gameover;
    MMI_BOOL is_new_game;
    U8 game_level;
    S16 game_grade;
    U16 timer_elapse;

    gdi_handle background;
    gdi_handle foreground;

    MMI_BOOL left_key_pressed;
    MMI_BOOL right_key_pressed;
    MMI_BOOL up_key_pressed;
    MMI_BOOL down_key_pressed;
    U16 tick;
    U8 energy;

    S16 boss_appearing_time;
    mmi_gfx_position fighter_position;
    mmi_gfx_position fighter_old_position;
    U8 fighter_weapon;
    U8 fighter_invincible;
    U8 fighter_state;
    U16 fighter_dying_time;

    mmi_gfx_position treasure_old_position;
    mmi_gfx_position treasure_position;
    U8 treasure_type;
    MMI_BOOL is_treasure_on;
    MMI_BOOL is_boss_on;

    MMI_BOOL is_invisible;

    U16 stage_ending_time;
    U8 stage_count;

    U8 enemy_pattern_number;
    gx_topgun_enemy_struct *enemy_model;
    gx_topgun_enemy_struct enemy_model_memory[1];

    gx_topgun_bullet_struct bullet[MMI_GX_TOPGUN_BULLET_COUNT];
    gx_topgun_bullet_struct *first_bullet;
    gx_topgun_bullet_struct *last_bullet;
    gx_topgun_bullet_struct *first_empty_bullet_list;
    gx_topgun_bullet_struct *last_empty_bullet_list;

    gx_topgun_enemy_struct enemy[MMI_GX_TOPGUN_ENEMY_COUNT];
    gx_topgun_enemy_struct *first_enemy;
    gx_topgun_enemy_struct *last_enemy;
    gx_topgun_enemy_struct *first_empty_enemy_list;
    gx_topgun_enemy_struct *last_empty_enemy_list;

    gx_topgun_enemy_bullet_struct enemy_bullet[MMI_GX_TOPGUN_ENEMY_BULLET_COUNT];
    gx_topgun_enemy_bullet_struct *first_enemy_bullet;
    gx_topgun_enemy_bullet_struct *last_enemy_bullet;
    gx_topgun_enemy_bullet_struct *first_empty_enemy_bullet_list;
    gx_topgun_enemy_bullet_struct *last_empty_enemy_bullet_list;

    audio_priority audio_to_play;

#ifdef __MMI_TOUCH_SCREEN__
    MMI_BOOL is_pen_hit;
    //U32 pen_down_tick;
    //mmi_pen_point_struct pen_down_pos;    
#endif

} gx_topgun_context_struct;

/***************************************************************************** 
* Local Variable
*****************************************************************************/
gx_topgun_context_struct g_gx_topgun_context = 
{
    MMI_FALSE,  /* is_gameover */
    MMI_TRUE,   /* is_new_game */
    0,      /* game_level */
    0,      /* game_grade */
    100     /* timer_elapse */
};

#ifdef  __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ /*added for game multi-language*/
static U16 mmi_topgun_language_index;
#define MMI_TOPGUN_STRING_COUNT MMI_TOPGUN_STRING_TOTAL
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

/***************************************************************************** 
* Local Function
*****************************************************************************/
/* Game framework related functions */
S16 mmi_gx_topgun_calc_best_grade(S16 old_grade, S16 new_grade);   /* descide which is best grade */
void mmi_gx_topgun_enter_game(void);       /* entry function of the game */
void mmi_gx_topgun_exit_game(void);        /* exit function - usually will stop timer and release buffer */
void mmi_gx_topgun_draw_gameover(void);    /* draw gameover screen */

/* Game play functions */
void mmi_gx_topgun_framemove(void);
void mmi_gx_topgun_render(void);
void mmi_gx_topgun_gameover(void);
void mmi_gx_topgun_cyclic_timer(void);
void mmi_gx_topgun_init_game(void);    /* draw gameover screen */
void mmi_gx_topgun_key_2_press(void);
void mmi_gx_topgun_key_2_release(void);
void mmi_gx_topgun_key_4_press(void);
void mmi_gx_topgun_key_4_release(void);
void mmi_gx_topgun_key_6_press(void);
void mmi_gx_topgun_key_6_release(void);
void mmi_gx_topgun_key_8_press(void);
void mmi_gx_topgun_key_8_release(void);
void mmi_gx_topgun_draw_static_background(void);
void mmi_gx_topgun_draw_score(void);
void mmi_gx_topgun_draw_energy(void);
void mmi_gx_topgun_draw_background(void);
void mmi_gx_topgun_init_bullet_list(void);
void mmi_gx_topgun_init_enemy_list(void);
void mmi_gx_topgun_init_enemy_bullet_list(void);
U8 mmi_gx_topgun_get_bullet_position_x(U8 type);
S16 mmi_gx_topgun_get_bullet_position_y(void);
U8 mmi_gx_topgun_get_enemy_position_x(U8 type);
void mmi_gx_topgun_update_enemy_vector(gx_topgun_enemy_struct *enemy);

#ifdef __MMI_TOUCH_SCREEN__
void mmi_gx_topgun_pen_down_hdlr(mmi_pen_point_struct pos);
void mmi_gx_topgun_pen_up_hdlr(mmi_pen_point_struct pos);
void mmi_gx_topgun_pen_move_hdlr(mmi_pen_point_struct pos);
#endif  //__MMI_TOUCH_SCREEN__

/************************************************************************/
/* Audio [Const]                                                        */
/************************************************************************/


#define  TOPGUNEAT_DVI  3082

__align(2)
     const U8 TopGunEat_dvi[3082] = 
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
         0xBA, 0xBD, 0xAC, 0x9A, 0x08, 0x31, 0x34, 0x23, 0x03, 0x00, 0x99, 0x0A, 0x09, 0x90, 0xDA, 0xEC,
         0xBC, 0xAC, 0x8A, 0x31, 0x46, 0x35, 0x23, 0x12, 0x98, 0xBD, 0xBD, 0xBB, 0xAB, 0x08, 0x32, 0x36,
         0x24, 0x23, 0x11, 0x88, 0xBA, 0xAD, 0xAC, 0xAB, 0x99, 0x08, 0x21, 0x35, 0x26, 0x23, 0x13, 0x81,
         0xB9, 0xBE, 0xAD, 0xAC, 0xAA, 0x09, 0x20, 0x34, 0x26, 0x24, 0x32, 0x12, 0x80, 0xBB, 0xBF, 0xBC,
         0xAC, 0x9B, 0x08, 0x32, 0x37, 0x34, 0x23, 0x01, 0xB9, 0xBD, 0xBD, 0xAB, 0x89, 0x21, 0x34, 0x25,
         0x23, 0x01, 0x98, 0xA9, 0xBA, 0xAA, 0xAA, 0xBB, 0xBF, 0xAD, 0x9B, 0x19, 0x54, 0x36, 0x24, 0x23,
         0x01, 0xBA, 0xBE, 0xBD, 0xAB, 0x89, 0x11, 0x44, 0x33, 0x24, 0x02, 0x90, 0xCA, 0xBB, 0xAD, 0x9A,
         0x09, 0x00, 0x32, 0x44, 0x33, 0x33, 0x23, 0x02, 0xA8, 0xBD, 0xBF, 0xCB, 0xAC, 0x9A, 0x09, 0x21,
         0x35, 0x36, 0x33, 0x14, 0x01, 0xA9, 0xCC, 0xAD, 0xBB, 0xAA, 0x08, 0x52, 0x34, 0x34, 0x23, 0x01,
         0xA9, 0xBD, 0xAE, 0xAB, 0x99, 0x00, 0x33, 0x35, 0x43, 0x12, 0x01, 0x90, 0xA9, 0xB9, 0xCA, 0xCB,
         0xBC, 0xBD, 0xAB, 0x09, 0x51, 0x45, 0x34, 0x24, 0x02, 0x98, 0xCC, 0xAC, 0x9C, 0x8A, 0x18, 0x32,
         0x35, 0x33, 0x13, 0x91, 0xBA, 0xBD, 0xAD, 0xAB, 0xAA, 0x88, 0x21, 0x44, 0x53, 0x33, 0x23, 0x13,
         0x91, 0xCA, 0xCD, 0xBB, 0xBC, 0xAA, 0x8A, 0x28, 0x52, 0x44, 0x24, 0x33, 0x12, 0x91, 0xDA, 0xCC,
         0xBC, 0xAB, 0x0A, 0x30, 0x45, 0x34, 0x24, 0x02, 0x90, 0xDB, 0xBC, 0xBB, 0xAB, 0x19, 0x31, 0x26,
         0x24, 0x13, 0x02, 0x80, 0x89, 0x89, 0x89, 0xC9, 0xDB, 0xCC, 0xAC, 0x9B, 0x19, 0x62, 0x44, 0x24,
         0x13, 0x91, 0xC9, 0xBD, 0xBB, 0x9C, 0x19, 0x41, 0x34, 0x24, 0x22, 0x00, 0xA9, 0xBC, 0xCB, 0xAB,
         0x9A, 0x89, 0x08, 0x21, 0x34, 0x54, 0x43, 0x23, 0x13, 0x81, 0xCA, 0xBD, 0xBD, 0xBB, 0x9B, 0x19,
         0x42, 0x35, 0x34, 0x33, 0x12, 0x90, 0xDA, 0xCC, 0xBC, 0xBA, 0x8A, 0x20, 0x63, 0x44, 0x33, 0x13,
         0x82, 0xC9, 0xCC, 0xCB, 0xAB, 0x8B, 0x08, 0x42, 0x34, 0x24, 0x22, 0x11, 0x80, 0x99, 0xBB, 0xDB,
         0xCA, 0xBB, 0xCB, 0xAA, 0x18, 0x73, 0x35, 0x34, 0x23, 0x82, 0xC9, 0xDC, 0xAC, 0xBB, 0x99, 0x21,
         0x44, 0x34, 0x24, 0x11, 0x80, 0xBA, 0xBC, 0xBC, 0xAB, 0x99, 0x88, 0x12, 0x43, 0x44, 0x33, 0x24,
         0x22, 0x00, 0xB9, 0xCD, 0xCC, 0xAB, 0xAA, 0x09, 0x22, 0x35, 0x35, 0x24, 0x22, 0x81, 0xBA, 0xCD,
         0xBC, 0xBB, 0xAB, 0x08, 0x44, 0x44, 0x24, 0x23, 0x02, 0x99, 0xBC, 0xAE, 0xBB, 0x9A, 0x09, 0x22,
         0x34, 0x43, 0x32, 0x21, 0x11, 0x88, 0xA9, 0xBB, 0xCD, 0xBC, 0xBC, 0x9C, 0x09, 0x42, 0x45, 0x43,
         0x23, 0x12, 0xA9, 0xCE, 0xAC, 0x9C, 0x8A, 0x00, 0x33, 0x26, 0x24, 0x12, 0x00, 0xA9, 0xBB, 0xAD,
         0xAB, 0xAA, 0x99, 0x08, 0x22, 0x44, 0x34, 0x43, 0x33, 0x12, 0x98, 0xDC, 0xBC, 0xBC, 0xAA, 0x09,
         0x21, 0x35, 0x35, 0x33, 0x13, 0x81, 0xBA, 0xBE, 0xBD, 0xBC, 0xBB, 0x8A, 0x31, 0x37, 0x44, 0x33,
         0x22, 0x81, 0xBA, 0xBE, 0xAD, 0xAB, 0x89, 0x00, 0x23, 0x34, 0x24, 0x12, 0x00, 0x98, 0x98, 0xA8,
         0xB9, 0xCC, 0xBC, 0xAC, 0x9A, 0x20, 0x45, 0x36, 0x25, 0x12, 0x91, 0xCB, 0xBD, 0xAD, 0xAB, 0x09,
         0x21, 0x44, 0x25, 0x23, 0x01, 0x80, 0xBA, 0xCB, 0xCB, 0xAA, 0x99, 0x80, 0x01, 0x21, 0x22, 0x35,
         0x35, 0x23, 0x12, 0xA8, 0xCD, 0xBC, 0xAD, 0x9B, 0x09, 0x52, 0x34, 0x34, 0x23, 0x12, 0xA0, 0xEB,
         0xBC, 0xAD, 0xAB, 0x9A, 0x28, 0x52, 0x34, 0x34, 0x24, 0x11, 0x98, 0xBB, 0xAE, 0xBB, 0xAB, 0x99,
         0x21, 0x53, 0x43, 0x22, 0x21, 0x10, 0x80, 0xB9, 0xEB, 0xCB, 0xAC, 0xAB, 0x8B, 0x29, 0x55, 0x35,
         0x25, 0x13, 0x01, 0xB9, 0xDC, 0xBC, 0xAC, 0x9A, 0x08, 0x33, 0x26, 0x24, 0x13, 0x11, 0x98, 0xBB,
         0xBD, 0xBB, 0xAA, 0x88, 0x18, 0x31, 0x44, 0x34, 0x33, 0x13, 0x82, 0xB8, 0xEC, 0xCC, 0xAC, 0x9B,
         0x0A, 0x31, 0x54, 0x43, 0x24, 0x23, 0x82, 0xA9, 0xCD, 0xCB, 0xAC, 0xAA, 0x89, 0x20, 0x44, 0x34,
         0x33, 0x13, 0x81, 0xB9, 0xCD, 0xAC, 0x9B, 0x8A, 0x10, 0x33, 0x34, 0x33, 0x24, 0x11, 0x80, 0xBA,
         0xCC, 0xBC, 0xCC, 0xCB, 0x9A, 0x19, 0x62, 0x34, 0x35, 0x23, 0x13, 0xA0, 0xEB, 0xCC, 0xAB, 0x9C,
         0x88, 0x20, 0x33, 0x35, 0x33, 0x22, 0x90, 0xBA, 0xBC, 0xBC, 0xBA, 0xAA, 0x88, 0x32, 0x45, 0x33,
         0x34, 0x33, 0x23, 0xA0, 0xED, 0xBC, 0xAD, 0xAB, 0x99, 0x10, 0x43, 0x36, 0x34, 0x33, 0x11, 0x98,
         0xBB, 0xBE, 0xAD, 0x9C, 0x9A, 0x18, 0x31, 0x53, 0x33, 0x24, 0x12, 0x88, 0xBC, 0xAD, 0xAC, 0x99,
         0x00, 0x21, 0x34, 0x35, 0x32, 0x01, 0x98, 0xBA, 0xBC, 0xBD, 0xCC, 0xAB, 0xAA, 0x08, 0x42, 0x44,
         0x35, 0x34, 0x23, 0x01, 0xB9, 0xBE, 0xBC, 0xAC, 0x9A, 0x88, 0x32, 0x35, 0x25, 0x21, 0x80, 0x99,
         0xBB, 0xBC, 0xAC, 0x99, 0x10, 0x33, 0x35, 0x33, 0x24, 0x33, 0x13, 0xA8, 0xDD, 0xBC, 0xBC, 0xBC,
         0xAB, 0x8A, 0x32, 0x47, 0x43, 0x32, 0x22, 0x00, 0xA8, 0xBD, 0xBD, 0xBB, 0x9A, 0x08, 0x22, 0x44,
         0x43, 0x33, 0x12, 0xA8, 0xCC, 0xCB, 0xBB, 0xAB, 0x9A, 0x31, 0x37, 0x44, 0x32, 0x12, 0x11, 0x90,
         0xCA, 0xDC, 0xCB, 0xAB, 0x9B, 0x8A, 0x10, 0x63, 0x44, 0x24, 0x13, 0x02, 0xA8, 0xBB, 0xBE, 0xBC,
         0xAA, 0x09, 0x32, 0x36, 0x33, 0x33, 0x21, 0xA8, 0xCC, 0xBD, 0xBC, 0x9A, 0x89, 0x20, 0x41, 0x44,
         0x43, 0x33, 0x12, 0x81, 0xA9, 0xEB, 0xBC, 0xBD, 0xAB, 0x9A, 0x20, 0x43, 0x44, 0x24, 0x33, 0x12,
         0xA8, 0xEB, 0xCB, 0xAB, 0xAA, 0x89, 0x21, 0x45, 0x34, 0x14, 0x02, 0x90, 0xBA, 0xCC, 0xAC, 0xAC,
         0x9A, 0x00, 0x33, 0x35, 0x43, 0x33, 0x23, 0x02, 0xB8, 0xCD, 0xBB, 0xBC, 0xBC, 0xAB, 0x0A, 0x41,
         0x45, 0x33, 0x24, 0x13, 0x81, 0xCA, 0xBD, 0xAD, 0x9B, 0x1A, 0x30, 0x34, 0x35, 0x33, 0x23, 0x90,
         0xCC, 0xBC, 0xAC, 0x9B, 0x9A, 0x89, 0x31, 0x45, 0x34, 0x33, 0x22, 0x13, 0x81, 0xD9, 0xDC, 0xCB,
         0xBB, 0x9A, 0x09, 0x30, 0x44, 0x35, 0x24, 0x02, 0x90, 0xBA, 0xCC, 0xAB, 0xAC, 0x8A, 0x30, 0x44,
         0x34, 0x14, 0x12, 0x01, 0xB8, 0xEB, 0xBC, 0xAC, 0x9B, 0x89, 0x11, 0x43, 0x35, 0x34, 0x24, 0x11,
         0x98, 0xAA, 0xDB, 0xCB, 0xCB, 0xAA, 0x89, 0x21, 0x43, 0x34, 0x34, 0x33, 0x03, 0xC8, 0xCC, 0xBC,
         0xAB, 0x8B, 0x19, 0x43, 0x36, 0x25, 0x13, 0x81, 0xA8, 0xBC, 0xBC, 0xAD, 0xAB, 0x9A, 0x11, 0x34,
         0x34, 0x34, 0x43, 0x22, 0x02, 0xA8, 0xCC, 0xBC, 0xBB, 0xAC, 0x9B, 0x09, 0x53, 0x44, 0x23, 0x13,
         0x01, 0x98, 0xCC, 0xBC, 0xAD, 0x99, 0x10, 0x33, 0x35, 0x24, 0x24, 0x11, 0x90, 0xDB, 0xBC, 0xAC,
         0xAB, 0x9A, 0x89, 0x31, 0x36, 0x35, 0x32, 0x22, 0x11, 0x88, 0xCA, 0xCD, 0xAB, 0xAB, 0x99, 0x10,
         0x31, 0x45, 0x34, 0x23, 0x01, 0xBA, 0xBE, 0xBC, 0xAC, 0xAA, 0x08, 0x53, 0x35, 0x34, 0x23, 0x12,
         0x88, 0xBB, 0xCE, 0xCB, 0xAB, 0xAA, 0x08, 0x20, 0x42, 0x44, 0x43, 0x23, 0x02, 0x88, 0xBA, 0xBC,
         0xAD, 0xAC, 0x9A, 0x10, 0x34, 0x25, 0x23, 0x13, 0x01, 0xBA, 0xCF, 0xBC, 0xBB, 0x9A, 0x00, 0x32,
         0x46, 0x43, 0x24, 0x13, 0x81, 0x99, 0xBC, 0xBC, 0xBC, 0xCB, 0x99, 0x18, 0x32, 0x34, 0x34, 0x33,
         0x32, 0x81, 0xCA, 0xBD, 0xBB, 0xAB, 0x89, 0x18, 0x63, 0x44, 0x34, 0x13, 0x81, 0xB9, 0xBD, 0xAF,
         0xAC, 0xAB, 0x8A, 0x21, 0x35, 0x35, 0x33, 0x24, 0x02, 0x90, 0xCB, 0xBC, 0xCB, 0xBA, 0x9A, 0x89,
         0x20, 0x53, 0x34, 0x23, 0x13, 0x01, 0xA0, 0xCB, 0xBE, 0xAC, 0x8A, 0x20, 0x53, 0x34, 0x25, 0x23,
         0x02, 0xB8, 0xDD, 0xCB, 0xAC, 0xAB, 0x99, 0x18, 0x52, 0x44, 0x33, 0x23, 0x13, 0x81, 0xA9, 0xCC,
         0xBC, 0xAD, 0xA9, 0x88, 0x00, 0x22, 0x43, 0x34, 0x13, 0x81, 0xC9, 0xCB, 0xBB, 0xBB, 0x8C, 0x38,
         0x73, 0x35, 0x24, 0x22, 0x82, 0xA1, 0xDA, 0xDC, 0xCB, 0xAB, 0x9A, 0x09, 0x22, 0x35, 0x35, 0x24,
         0x13, 0x01, 0x99, 0xBB, 0xCC, 0xBB, 0xAB, 0x9A, 0x10, 0x43, 0x24, 0x33, 0x14, 0x02, 0xB8, 0xDD,
         0xBC, 0x9B, 0x8A, 0x38, 0x62, 0x53, 0x24, 0x24, 0x12, 0x90, 0xBA, 0xCC, 0xAD, 0xAC, 0xAA, 0x8A,
         0x11, 0x34, 0x34, 0x34, 0x23, 0x13, 0x88, 0xBB, 0xBE, 0xAB, 0xAB, 0x99, 0x18, 0x42, 0x35, 0x33,
         0x13, 0x98, 0xCC, 0xCC, 0xCB, 0xBB, 0x9B, 0x29, 0x73, 0x43, 0x34, 0x33, 0x24, 0x02, 0xA8, 0xCC,
         0xCC, 0xAB, 0xAC, 0x99, 0x09, 0x22, 0x35, 0x34, 0x22, 0x11, 0x08, 0xAA, 0xBB, 0xAD, 0x9A, 0x80,
         0x23, 0x25, 0x33, 0x43, 0x22, 0x90, 0xEC, 0xDC, 0xBB, 0xAC, 0xAA, 0x09, 0x30, 0x46, 0x34, 0x24,
         0x13, 0x02, 0x80, 0xAB, 0xBD, 0xBD, 0xAB, 0xAB, 0x98, 0x10, 0x33, 0x35, 0x34, 0x13, 0x00, 0xAB,
         0xAC, 0xBB, 0x9A, 0x18, 0x44, 0x36, 0x25, 0x23, 0x02, 0x98, 0xDB, 0xCC, 0xCC, 0xAB, 0xAB, 0x0A,
         0x10, 0x34, 0x36, 0x34, 0x33, 0x23, 0x01, 0xA8, 0xCB, 0xBD, 0xAD, 0xBB, 0x9A, 0x00, 0x23, 0x35,
         0x23, 0x21, 0x98, 0xCB, 0xBD, 0xBB, 0x89, 0x32, 0x46, 0x42, 0x32, 0x33, 0x14, 0x81, 0xB8, 0xCD,
         0xCC, 0xCB, 0xAC, 0x9A, 0x09, 0x31, 0x35, 0x25, 0x24, 0x12, 0x11, 0x98, 0xAA, 0xAD, 0xAC, 0xBA,
         0x99, 0x88, 0x22, 0x34, 0x25, 0x12, 0x80, 0xBA, 0xBD, 0xBC, 0xAB, 0x09, 0x51, 0x44, 0x34, 0x23,
         0x23, 0x12, 0x90, 0xFA, 0xDB, 0xAC, 0xAC, 0x9A, 0x0A, 0x28, 0x43, 0x35, 0x24, 0x23, 0x12, 0x80,
         0xAA, 0xBD, 0xAD, 0xAB, 0x9A, 0x00, 0x33, 0x35, 0x24, 0x13, 0x80, 0xDB, 0xBC, 0xBC, 0x9A, 0x09,
         0x31, 0x73, 0x33, 0x34, 0x23, 0x13, 0x92, 0xC9, 0xDC, 0xBD, 0xAC, 0x9C, 0x0A, 0x28, 0x42, 0x34,
         0x24, 0x23, 0x02, 0x98, 0xAA, 0xBC, 0xAC, 0xAB, 0x9C, 0x89, 0x20, 0x35, 0x25, 0x23, 0x02, 0xB8,
         0xCD, 0xBD, 0xAB, 0x8B, 0x20, 0x63, 0x43, 0x24, 0x23, 0x12, 0x80, 0xB9, 0xCC, 0xDB, 0xBB, 0xAD,
         0x9B, 0x8A, 0x30, 0x44, 0x34, 0x24, 0x23, 0x12, 0x98, 0xBB, 0xAE, 0x9C, 0x8A, 0x88, 0x12, 0x24,
         0x25, 0x02, 0x90, 0xDB, 0xBC, 0xAC, 0x9B, 0x89, 0x11, 0x34, 0x35, 0x34, 0x33, 0x24, 0x23, 0x82,
         0xC8, 0xDC, 0xBD, 0xCB, 0xAB, 0x8A, 0x28, 0x43, 0x25, 0x14, 0x02, 0x00, 0x89, 0x89, 0x8A, 0x89,
         0x08, 0x02, 0x83, 0x83, 0x04, 0x22, 0x01, 0xEC, 0xCF, 0xBC, 0xAC, 0xAA, 0x88, 0x32, 0x46, 0x34,
         0x33, 0x23, 0x11, 0x80, 0x9A, 0xCC, 0xBC, 0xAD, 0xBB, 0xAA, 0x99, 0x10, 0x42, 0x34, 0x25, 0x12,
         0x10, 0x09, 0x9A, 0x8B, 0x8A, 0x10, 0x27, 0x26, 0x23, 0x03, 0x98, 0xBE, 0xBD, 0xAE, 0xAB, 0xAA,
         0x08, 0x32, 0x35, 0x43, 0x33, 0x34, 0x32, 0x23, 0x12, 0x90, 0xDC, 0xBD, 0xAE, 0xBB, 0xA9, 0x00,
         0x12, 0x15, 0x13, 0x02, 0x08, 0x8B, 0x0A, 0x30, 0x54, 0x24, 0x23, 0x13, 0x12, 0x01, 0xA8, 0xDD,
         0xCC, 0xBC, 0xCC, 0xAB, 0x9B, 0x08, 0x43, 0x44, 0x33, 0x33, 0x33, 0x24, 0x12, 0x00, 0x99, 0xBC,
         0xBF, 0xBC, 0xCB, 0x99, 0x08, 0x22, 0x23, 0x02, 0x80, 0x9B
    };

#define  TOPGUNEXPLODE_DVI 982

__align(2)
     const U8 TopGunExplode_dvi[982] = 
     {
         0x77, 0xD7, 0x77, 0x77, 0x0E, 0x08, 0xB7, 0xB7, 0x08, 0x17, 0xAB, 0x80, 0x10, 0x99, 0x10, 0x90,
         0x03, 0xC0, 0x81, 0x80, 0x88, 0x22, 0x0F, 0x29, 0x09, 0xB2, 0x49, 0xBA, 0x87, 0x10, 0x31, 0xF0,
         0x0F, 0x28, 0x43, 0xA8, 0xBA, 0x0D, 0x40, 0x81, 0x48, 0x80, 0xBC, 0x09, 0x01, 0x88, 0x04, 0x83,
         0xB0, 0x1B, 0x60, 0x22, 0xF9, 0xB9, 0x39, 0x00, 0x1D, 0x01, 0x83, 0x19, 0x92, 0xDE, 0x28, 0x39,
         0x11, 0x25, 0xA3, 0xD0, 0xEB, 0x09, 0x18, 0x31, 0x24, 0x20, 0x1B, 0xB9, 0xDB, 0x2B, 0x5B, 0x12,
         0x99, 0xBB, 0x4C, 0x11, 0x90, 0x92, 0x52, 0x9D, 0x82, 0x92, 0x87, 0x92, 0x81, 0xAB, 0xCE, 0x18,
         0x35, 0x80, 0x89, 0xB9, 0x99, 0x2B, 0x66, 0x01, 0x99, 0xAC, 0x38, 0x00, 0x35, 0x22, 0xF8, 0x9D,
         0x89, 0x28, 0x14, 0x00, 0x90, 0x81, 0xAB, 0xBB, 0xC8, 0x48, 0x37, 0xA9, 0x0A, 0x46, 0x01, 0xB0,
         0xA8, 0x38, 0xBA, 0x9F, 0x29, 0x81, 0x22, 0x96, 0xA9, 0xCB, 0x29, 0x01, 0x24, 0x05, 0x10, 0xDC,
         0x89, 0x38, 0x14, 0x88, 0xB8, 0xB8, 0x29, 0x47, 0xA0, 0x10, 0x02, 0xC2, 0xED, 0x0A, 0x32, 0x82,
         0x98, 0xAA, 0x1A, 0x01, 0x48, 0x10, 0x37, 0x90, 0x9D, 0xCB, 0x21, 0x32, 0x12, 0xFB, 0x0B, 0x50,
         0x84, 0x19, 0x98, 0xBB, 0x39, 0x10, 0x88, 0x38, 0x27, 0x8A, 0x29, 0x2F, 0x03, 0xD9, 0x89, 0xA9,
         0x0A, 0x28, 0x77, 0x80, 0x98, 0x9A, 0xAB, 0x09, 0x73, 0x15, 0x88, 0x88, 0xD9, 0x09, 0x20, 0x23,
         0xCA, 0x8A, 0x80, 0x00, 0x41, 0x21, 0x03, 0xE1, 0xCD, 0x18, 0x21, 0x18, 0x34, 0xDC, 0x9B, 0x30,
         0x02, 0x88, 0x80, 0x17, 0x81, 0x08, 0x8A, 0xE8, 0x19, 0x42, 0x81, 0xBC, 0x41, 0x91, 0xAA, 0x17,
         0xB9, 0x0C, 0x88, 0x03, 0x11, 0x15, 0xC9, 0x0D, 0x89, 0x91, 0xAB, 0x78, 0x16, 0x08, 0x91, 0xA0,
         0x9A, 0x0A, 0xA9, 0x62, 0x13, 0xA8, 0x9A, 0xCA, 0xAA, 0x55, 0x13, 0xCA, 0xBB, 0x48, 0x13, 0x81,
         0x84, 0xE9, 0x30, 0x08, 0x29, 0xCA, 0x38, 0x12, 0xDC, 0x0B, 0x80, 0x19, 0x27, 0x08, 0xD0, 0x81,
         0x12, 0x30, 0xA2, 0xD2, 0xAD, 0x98, 0x3A, 0x47, 0xA0, 0xAC, 0x09, 0x13, 0x8A, 0x42, 0x92, 0xFB,
         0x29, 0x52, 0x98, 0x98, 0xA1, 0x28, 0x99, 0x38, 0x71, 0x80, 0xAE, 0x02, 0x51, 0x88, 0x98, 0xAD,
         0x39, 0x15, 0x9D, 0x42, 0x90, 0x8A, 0x98, 0x22, 0xA0, 0x0C, 0x98, 0x8A, 0x41, 0x37, 0x08, 0xA8,
         0xA9, 0xE1, 0x9A, 0x78, 0x12, 0x18, 0x90, 0xCC, 0x89, 0x22, 0x22, 0xB8, 0x18, 0x34, 0xDA, 0xB0,
         0x52, 0x81, 0xDA, 0xBA, 0x59, 0x06, 0x18, 0x00, 0xDB, 0x0A, 0x88, 0x27, 0x98, 0x5B, 0x80, 0x99,
         0x80, 0x8C, 0x91, 0x42, 0xB8, 0x49, 0x28, 0x11, 0x02, 0xAA, 0xF0, 0xAB, 0x49, 0x27, 0x88, 0x08,
         0xB8, 0xC9, 0x88, 0x42, 0x90, 0x98, 0xC9, 0x49, 0x36, 0x00, 0xC9, 0x8D, 0x00, 0x90, 0x59, 0x82,
         0x21, 0xB8, 0xB9, 0xAD, 0x70, 0x03, 0x99, 0x9B, 0x89, 0x42, 0x15, 0xA8, 0x8D, 0x89, 0x12, 0x9B,
         0x47, 0x00, 0xA8, 0x8E, 0x88, 0x42, 0x08, 0x0A, 0x01, 0x89, 0xD9, 0x19, 0x22, 0x90, 0xDB, 0x09,
         0x30, 0x71, 0x05, 0xB0, 0x9C, 0x19, 0x05, 0x80, 0x1C, 0x12, 0x12, 0x98, 0xFB, 0x0D, 0x21, 0x20,
         0x88, 0xB0, 0xCB, 0x00, 0x52, 0x02, 0x09, 0xC0, 0x9D, 0x40, 0x30, 0x11, 0xC9, 0x92, 0x8B, 0x10,
         0x01, 0xAE, 0x08, 0x41, 0xB0, 0x2C, 0x28, 0xA0, 0x09, 0x1D, 0x14, 0x52, 0x41, 0xAB, 0x38, 0x18,
         0x83, 0xCF, 0xB8, 0xAA, 0x28, 0x35, 0x51, 0xA8, 0x90, 0x32, 0x0F, 0x81, 0x3C, 0x16, 0xC8, 0x0C,
         0x09, 0x10, 0x11, 0x81, 0xA0, 0xC9, 0x91, 0x38, 0x16, 0xA9, 0x0F, 0x08, 0x29, 0x33, 0xA9, 0x28,
         0x23, 0x12, 0xB9, 0x4F, 0xE9, 0x01, 0x91, 0x0A, 0xA9, 0xD4, 0x28, 0x80, 0x11, 0x8F, 0x32, 0x93,
         0x10, 0xDA, 0x19, 0x23, 0xF8, 0x39, 0xD8, 0x02, 0x99, 0x43, 0x9A, 0xA3, 0xB2, 0x2B, 0x7C, 0xE0,
         0x08, 0x11, 0x32, 0xB2, 0xAE, 0x22, 0x8A, 0x40, 0xA0, 0x91, 0x9F, 0x18, 0x87, 0x90, 0x98, 0x1B,
         0x98, 0x51, 0x92, 0x4A, 0x94, 0x90, 0xA8, 0x98, 0x39, 0x11, 0x71, 0xA8, 0xAA, 0xEB, 0x23, 0x10,
         0xF2, 0xAB, 0x21, 0x89, 0x42, 0x95, 0x22, 0x8A, 0x9C, 0xC1, 0x60, 0x01, 0x90, 0x0C, 0x88, 0xA3,
         0x93, 0xCB, 0x11, 0xB4, 0x3C, 0xB2, 0x9E, 0x33, 0xA1, 0x2A, 0xA0, 0x10, 0x73, 0x02, 0x81, 0xBF,
         0x00, 0x25, 0xA8, 0xB8, 0x0D, 0x20, 0x8D, 0x23, 0x23, 0xBA, 0x9D, 0xC0, 0x31, 0x02, 0x25, 0x8A,
         0xC9, 0xB9, 0xB0, 0x73, 0x10, 0x11, 0xA8, 0x0C, 0x1A, 0x84, 0x10, 0xA0, 0xFD, 0x88, 0x21, 0x90,
         0x90, 0x17, 0x29, 0x90, 0xAA, 0x59, 0x12, 0xB0, 0xAE, 0x00, 0x07, 0x3A, 0xA8, 0xAC, 0x88, 0x12,
         0x52, 0xA0, 0x99, 0xA2, 0x29, 0x80, 0x9C, 0x75, 0x10, 0xA0, 0xBC, 0x4B, 0x02, 0x90, 0x72, 0x90,
         0xC9, 0xAB, 0x30, 0x17, 0x00, 0xB9, 0x9C, 0x10, 0x31, 0x21, 0xD0, 0x10, 0x10, 0xDA, 0x90, 0x3C,
         0x16, 0x91, 0x01, 0xE0, 0x9A, 0x02, 0x02, 0x39, 0x08, 0xBC, 0x8B, 0x8B, 0x43, 0x87, 0xD1, 0x1A,
         0x24, 0x98, 0x12, 0xAC, 0x90, 0x1C, 0x34, 0x8C, 0x81, 0xA2, 0x9C, 0x28, 0x8A, 0x07, 0x11, 0x82,
         0x9C, 0x10, 0x72, 0x88, 0xD1, 0xB8, 0x99, 0x10, 0x61, 0xA3, 0x9A, 0x13, 0x00, 0xF0, 0x0F, 0x82,
         0x12, 0x9A, 0xAA, 0x5A, 0x23, 0x90, 0x80, 0xAC, 0x89, 0x4B, 0x45, 0x99, 0x18, 0x03, 0xCB, 0x28,
         0x03, 0x80, 0xF8, 0x2C, 0x88, 0x02, 0xBC, 0x31, 0x13, 0x9F, 0x12, 0x31, 0xA0, 0x0D, 0xB4, 0x8C,
         0x16, 0x8A, 0x1A, 0x28, 0xBB, 0x36, 0xB2, 0x98, 0xBB, 0x29, 0x2E, 0x71, 0x18, 0x00, 0x00, 0xB0,
         0x9D, 0x20, 0xC9, 0x2A, 0x40, 0x00, 0x83, 0x6A, 0xA9, 0x1E, 0x14, 0xA0, 0x00, 0x00, 0xD9, 0x89,
         0x04, 0x28, 0xD9, 0x8C, 0x08, 0x28, 0x06, 0x10, 0x88, 0xC9, 0x80, 0x85, 0x19, 0x02, 0xAB, 0x12,
         0xF3, 0xA1, 0x03, 0xA8, 0x60, 0x8B, 0xDB, 0x8A, 0x62, 0x03, 0x88, 0xBA, 0x98, 0x78, 0x01, 0x0A,
         0x10, 0x81, 0xF9, 0x2A, 0x08, 0x29, 0x31, 0x87, 0x89, 0x99, 0x07, 0xC8, 0x2B, 0xA2, 0x1A, 0x09,
         0x41, 0x21, 0xF8, 0x29, 0x87, 0xAA, 0x80, 0x42, 0x80, 0xB0, 0x10, 0xF1, 0x1C, 0x12, 0xA8, 0x8A,
         0x1A, 0x81, 0x80, 0x57, 0x8A, 0x00, 0x9A, 0x42, 0x29, 0x58, 0x98, 0xDA, 0x08, 0x28, 0x24, 0xAB,
         0xCB, 0x31, 0x02, 0xE8, 0x99, 0x24, 0xE8, 0x18, 0x91, 0x30, 0x49, 0x91, 0xB9, 0x2D, 0x01, 0xBA,
         0x62, 0x91, 0x14, 0x9A, 0x20, 0xFD, 0x09, 0x12, 0x10, 0x88, 0x58, 0x90, 0x8A, 0xD1, 0x08, 0x34,
         0x98, 0x8A, 0x1A, 0x87, 0x1B, 0x15, 0xAA, 0xBC, 0x39, 0xD2, 0x59, 0x82, 0x08, 0x94, 0xC9, 0x09,
         0x29, 0x38, 0x15, 0x09, 0xB9, 0x50, 0x94, 0xC9, 0x30, 0x80, 0xBC, 0x0A, 0x71, 0x80, 0x99, 0xA1,
         0xB2, 0x28, 0x92, 0x8D, 0x42, 0x44, 0x91, 0xAB, 0x80, 0xAD, 0x1B, 0xA9, 0x77, 0x80, 0x88, 0x88,
         0xAA, 0x1A, 0x41, 0x29, 0x38, 0x88, 0x4A, 0x86, 0xCA, 0x18, 0x23, 0xAB, 0xA8, 0x32, 0xB8, 0x20,
         0xBF, 0xE1, 0x0B, 0x22, 0x95, 0x89
     };

#define  TOPGUNHIT_DVI  822

__align(2)
     const U8 TopGunHit_dvi[822] = 
     {
         0x77, 0xD7, 0x77, 0x77, 0x0E, 0x08, 0x3F, 0xB7, 0x08, 0x17, 0x8C, 0x08, 0x08, 0x08, 0x08, 0x88,
         0x80, 0x80, 0x80, 0x80, 0x80, 0x08, 0x00, 0x00, 0x08, 0x11, 0x98, 0xA9, 0x8A, 0x32, 0x13, 0x28,
         0x14, 0xFB, 0x9E, 0xA9, 0x89, 0x38, 0x46, 0x12, 0x21, 0x82, 0xA9, 0xBB, 0xBD, 0x9B, 0xBB, 0x0A,
         0x02, 0x00, 0x8A, 0x57, 0x32, 0x27, 0x11, 0x10, 0xC9, 0xBB, 0xCD, 0xBB, 0x9B, 0x00, 0x74, 0x14,
         0x01, 0x22, 0xA2, 0xBA, 0xA9, 0xCF, 0x99, 0x10, 0x01, 0x41, 0x25, 0x90, 0x00, 0xC8, 0xAC, 0x08,
         0x81, 0x10, 0x41, 0x26, 0xA8, 0x8A, 0xB8, 0xBB, 0xCD, 0xCB, 0x9B, 0x31, 0x55, 0x45, 0x22, 0x22,
         0x80, 0xCC, 0xBB, 0xCB, 0xBB, 0x9B, 0x08, 0x43, 0x34, 0x63, 0x34, 0x33, 0x82, 0xDB, 0xCB, 0xDB,
         0xAA, 0x00, 0x11, 0x21, 0x44, 0x13, 0x90, 0xBB, 0xAD, 0x89, 0x11, 0x22, 0x44, 0x23, 0x01, 0xA9,
         0xDB, 0xAB, 0x9A, 0x98, 0xCE, 0xBC, 0x9A, 0x30, 0x67, 0x24, 0x13, 0x90, 0xC9, 0xCC, 0xAB, 0x9A,
         0x18, 0x41, 0x43, 0x22, 0x33, 0x32, 0x23, 0xB0, 0xDE, 0xBC, 0xAC, 0x9A, 0x19, 0x63, 0x34, 0x43,
         0x22, 0xA8, 0xCD, 0xBC, 0xAB, 0x89, 0x21, 0x35, 0x33, 0x23, 0x01, 0xB8, 0xDC, 0xBB, 0xAA, 0x18,
         0x43, 0x44, 0x22, 0x22, 0x22, 0x02, 0xDA, 0xAC, 0xBB, 0xBD, 0xAA, 0xA9, 0x99, 0x0A, 0x73, 0x43,
         0x24, 0x23, 0x11, 0xB9, 0xCD, 0xBC, 0xAA, 0x18, 0x65, 0x43, 0x11, 0x80, 0xB9, 0xDC, 0xBC, 0xAB,
         0x08, 0x48, 0x44, 0x43, 0x23, 0x01, 0x80, 0xA0, 0xCE, 0xBC, 0xBA, 0x80, 0x08, 0x60, 0x34, 0x33,
         0x02, 0x08, 0xC0, 0xDC, 0xBA, 0xAB, 0x08, 0x31, 0x34, 0x34, 0x23, 0x12, 0x98, 0xBA, 0xCE, 0xBC,
         0x9B, 0x08, 0x31, 0x44, 0x43, 0x12, 0x00, 0x98, 0xAB, 0xBC, 0xBB, 0x09, 0x11, 0x90, 0x10, 0x42,
         0x43, 0x33, 0x36, 0x14, 0xA0, 0xBC, 0xBC, 0xBA, 0xAA, 0x09, 0x54, 0x33, 0x90, 0xEC, 0xCB, 0x8A,
         0x30, 0x44, 0x33, 0x33, 0x81, 0xCA, 0xBB, 0x9B, 0x09, 0x62, 0x24, 0x80, 0x9A, 0xBA, 0xCD, 0xAB,
         0x19, 0x22, 0x23, 0x33, 0x12, 0xDA, 0xBF, 0x8A, 0x42, 0x53, 0x53, 0x33, 0x02, 0xA8, 0xCD, 0xCC,
         0xBA, 0x9B, 0x09, 0x41, 0x34, 0x35, 0x43, 0x13, 0x91, 0xDA, 0xCC, 0xAB, 0xBB, 0x9B, 0x18, 0x53,
         0x35, 0x35, 0x23, 0x12, 0xA9, 0xCD, 0xCB, 0xAB, 0x9B, 0x18, 0x53, 0x34, 0x34, 0x12, 0x80, 0xCA,
         0xBC, 0xAD, 0xAA, 0x09, 0x42, 0x44, 0x33, 0x13, 0x81, 0xCA, 0xBD, 0xAC, 0x9B, 0x08, 0x32, 0x44,
         0x33, 0x23, 0x81, 0xBA, 0xEC, 0xDB, 0xAB, 0x99, 0x21, 0x63, 0x34, 0x33, 0x12, 0x90, 0xCB, 0xCC,
         0xBA, 0xBB, 0x9A, 0x20, 0x63, 0x43, 0x23, 0x23, 0x02, 0xA0, 0xCB, 0xCC, 0xBB, 0xBB, 0xAA, 0x9B,
         0x10, 0x73, 0x34, 0x44, 0x32, 0x12, 0x80, 0xDB, 0xBC, 0xCB, 0xAA, 0x99, 0x28, 0x43, 0x35, 0x23,
         0x11, 0x80, 0xA8, 0x98, 0x08, 0x98, 0xFA, 0xDC, 0xAB, 0xAB, 0x09, 0x42, 0x36, 0x35, 0x22, 0x81,
         0xA8, 0xCB, 0xAA, 0xA9, 0xAA, 0x99, 0x88, 0x00, 0xB9, 0xBC, 0xCB, 0x09, 0x74, 0x44, 0x44, 0x33,
         0x22, 0xA8, 0xDC, 0xBC, 0xBC, 0xBB, 0x9A, 0x30, 0x45, 0x34, 0x24, 0x22, 0x80, 0xA9, 0xCC, 0xBB,
         0xAA, 0x09, 0x21, 0x34, 0x24, 0x11, 0x98, 0xCB, 0xCB, 0x9A, 0x09, 0x32, 0x45, 0x43, 0x12, 0x90,
         0xDB, 0xBC, 0xBC, 0x9A, 0x10, 0x44, 0x34, 0x32, 0x11, 0x90, 0xCB, 0xCC, 0xCB, 0xAA, 0x89, 0x41,
         0x63, 0x33, 0x24, 0x12, 0x90, 0xCA, 0xBC, 0xBC, 0xBB, 0xAB, 0x19, 0x41, 0x54, 0x33, 0x24, 0x12,
         0x80, 0xAA, 0xBC, 0xDB, 0xBA, 0x9A, 0x89, 0x00, 0x30, 0x53, 0x53, 0x53, 0x33, 0x22, 0x81, 0xBA,
         0xCE, 0xCB, 0xAC, 0x9B, 0x89, 0x21, 0x53, 0x23, 0x33, 0x42, 0x32, 0x33, 0x22, 0xB8, 0xDF, 0xDB,
         0xBB, 0xBB, 0x9A, 0x31, 0x47, 0x43, 0x32, 0x01, 0xA9, 0xBC, 0xBD, 0xBA, 0x09, 0x31, 0x45, 0x33,
         0x02, 0x98, 0xBC, 0xCC, 0xAB, 0x88, 0x41, 0x53, 0x23, 0x12, 0x80, 0xCA, 0xCC, 0xAB, 0x8A, 0x20,
         0x34, 0x44, 0x23, 0x81, 0xB9, 0xCC, 0xBB, 0xCB, 0x89, 0x32, 0x35, 0x25, 0x22, 0x80, 0xBA, 0xBD,
         0xAA, 0x08, 0x52, 0x43, 0x23, 0x81, 0xEB, 0xDC, 0xBB, 0x9C, 0x89, 0x32, 0x45, 0x24, 0x33, 0x12,
         0x98, 0xCB, 0xCC, 0xBB, 0xAB, 0x09, 0x30, 0x45, 0x33, 0x23, 0x01, 0xA8, 0xBC, 0xBC, 0xAB, 0x8A,
         0x20, 0x53, 0x43, 0x13, 0x11, 0x98, 0xDB, 0xBD, 0xAA, 0x99, 0x10, 0x42, 0x35, 0x34, 0x23, 0xA8,
         0xCD, 0xBD, 0xAC, 0x8A, 0x30, 0x45, 0x34, 0x24, 0x02, 0xA0, 0xDB, 0xCC, 0xAB, 0x9B, 0x09, 0x31,
         0x44, 0x44, 0x32, 0x12, 0x91, 0xC9, 0xCB, 0xBC, 0xBB, 0x9B, 0x19, 0x53, 0x35, 0x25, 0x13, 0x80,
         0xBA, 0xCD, 0xBB, 0xAA, 0x08, 0x53, 0x44, 0x23, 0x12, 0x98, 0xCB, 0xBD, 0xBB, 0x9B, 0x08, 0x53,
         0x34, 0x43, 0x22, 0x80, 0xA9, 0xCA, 0xAA, 0xAA, 0x09, 0x20, 0x02, 0x81, 0x98, 0xBB, 0xCD, 0xAC,
         0x19, 0x41, 0x45, 0x34, 0x23, 0x82, 0xA8, 0xCC, 0xAA, 0xA9, 0x08, 0x11, 0x02, 0xD9, 0xDD, 0xBC,
         0xAB, 0x89, 0x53, 0x45, 0x43, 0x32, 0x21, 0x98, 0xDA, 0xBC, 0xBB, 0xAB, 0x09, 0x42, 0x53, 0x33,
         0x03, 0xA0, 0xCC, 0xCB, 0xAA, 0x09, 0x42, 0x44, 0x34, 0x22, 0x01, 0xB9, 0xCD, 0xBC, 0xBB, 0xAA,
         0x10, 0x42, 0x35, 0x34, 0x24, 0x12, 0x98, 0xEB, 0xCC, 0xBA, 0xAB, 0x09, 0x42, 0x45, 0x24, 0x23,
         0x02, 0xA8, 0xDC, 0xCB, 0xAB, 0x9A, 0x10, 0x42, 0x35, 0x33, 0x22, 0x80, 0xCA, 0xBC, 0xBC, 0xBA,
         0x8A, 0x20, 0x63, 0x43, 0x33, 0x33, 0x80, 0xCA, 0xBD, 0xAC, 0xAB, 0x89, 0x20, 0x44, 0x53, 0x22,
         0x02, 0xA8, 0xBC, 0xBD, 0xAC, 0x8A, 0x28, 0x52, 0x43, 0x43, 0x11, 0x81, 0xA9, 0xCB, 0xBB, 0xBB,
         0x99, 0x00, 0x33, 0x44, 0x22, 0x81, 0x98, 0xBB, 0xCB, 0x89, 0x52, 0x44, 0x33, 0x13, 0x91, 0xCC,
         0xCC, 0xBC, 0x9C, 0x89, 0x21, 0x33
     };

#define  TOPGUNSHOOT_DVI   924

__align(2)
     const U8 TopGunShoot_dvi[924] = 
     {
         0x77, 0xD7, 0x77, 0x77, 0x0E, 0x08, 0xB7, 0xB7, 0x08, 0x17, 0xAB, 0x80, 0x80, 0x80, 0x00, 0x08,
         0x88, 0x08, 0x80, 0x88, 0x11, 0xA1, 0xAB, 0x30, 0x91, 0x8A, 0x20, 0x67, 0x93, 0xDE, 0x19, 0x35,
         0x82, 0xEB, 0x0A, 0x33, 0xE8, 0x9B, 0x21, 0x91, 0x28, 0x12, 0x72, 0x26, 0xC9, 0x9C, 0x21, 0x81,
         0xBA, 0xBB, 0x29, 0x35, 0x90, 0x40, 0x25, 0xAA, 0x19, 0x82, 0x9C, 0x01, 0xFB, 0x8B, 0x23, 0xA8,
         0x89, 0x54, 0x35, 0xB8, 0x0C, 0x35, 0xD0, 0xAE, 0x28, 0x13, 0xA9, 0x28, 0x01, 0x8A, 0x52, 0x91,
         0x0A, 0x25, 0xFA, 0x8C, 0x61, 0x91, 0xAB, 0x19, 0x43, 0x12, 0xE9, 0x1A, 0x14, 0xBA, 0x8B, 0x33,
         0x01, 0x9A, 0x9A, 0x73, 0x02, 0x89, 0x01, 0xED, 0x19, 0x13, 0xB9, 0x0A, 0x51, 0x16, 0xA8, 0x9C,
         0x22, 0xA1, 0x9D, 0x11, 0x88, 0x11, 0x00, 0x23, 0xB8, 0x1A, 0x00, 0x24, 0xFF, 0x2A, 0x83, 0xAA,
         0x52, 0x03, 0xBA, 0x38, 0xB1, 0x89, 0xFB, 0x30, 0xA1, 0x8C, 0x43, 0x24, 0xC9, 0x09, 0x21, 0x82,
         0xCF, 0x18, 0x01, 0x89, 0xA0, 0x4B, 0x57, 0xB9, 0x18, 0x91, 0x28, 0xA2, 0xBD, 0x19, 0x14, 0xC9,
         0x40, 0x80, 0x31, 0xD8, 0x39, 0x95, 0x9C, 0x32, 0xFA, 0x28, 0x02, 0xCA, 0x28, 0x13, 0x88, 0x8A,
         0x11, 0x31, 0xF0, 0x9C, 0x22, 0x00, 0xC8, 0x1B, 0x17, 0x8A, 0x12, 0xBC, 0x32, 0x91, 0x08, 0x89,
         0xAB, 0x73, 0xE0, 0x39, 0xA3, 0x8C, 0x25, 0xB9, 0x18, 0x09, 0x14, 0x9E, 0x23, 0xCA, 0x48, 0xA2,
         0x9B, 0x21, 0x11, 0x90, 0x99, 0x12, 0xCD, 0x51, 0x81, 0x8A, 0x10, 0xD9, 0x48, 0xA2, 0x19, 0xEB,
         0x72, 0xA1, 0x0C, 0x14, 0xCA, 0x30, 0x92, 0x9C, 0x11, 0x90, 0x00, 0x08, 0x22, 0xEA, 0x48, 0xA3,
         0x8B, 0x01, 0xD0, 0x2B, 0x84, 0x58, 0xD0, 0x58, 0xC0, 0x29, 0x92, 0x19, 0xA0, 0x0C, 0x25, 0xB9,
         0x2A, 0x15, 0xAC, 0x11, 0x81, 0xAB, 0x72, 0x91, 0x9B, 0x31, 0xA8, 0xBA, 0x71, 0xA4, 0x9B, 0x21,
         0x04, 0xBC, 0x40, 0xA1, 0x38, 0xF9, 0x38, 0xB3, 0x1C, 0x85, 0x8B, 0x03, 0x8A, 0x92, 0x0A, 0x24,
         0xCA, 0x28, 0xD8, 0x71, 0xC1, 0x1B, 0x25, 0xCA, 0x28, 0x90, 0x21, 0xBC, 0x43, 0x90, 0x09, 0xA9,
         0x32, 0xAB, 0x13, 0x1A, 0xC0, 0x51, 0x99, 0x24, 0xEB, 0x88, 0x19, 0x44, 0xC0, 0x1C, 0x84, 0x19,
         0x90, 0xBA, 0x79, 0x06, 0xAD, 0x31, 0xA8, 0x40, 0xC0, 0x2A, 0x13, 0xAA, 0x8C, 0x35, 0xC9, 0x39,
         0x92, 0x0E, 0x13, 0xAA, 0x01, 0x80, 0x00, 0xA2, 0xAF, 0x26, 0xB9, 0x01, 0x0A, 0x06, 0x9C, 0x12,
         0x80, 0xBA, 0x62, 0xB1, 0x0B, 0x13, 0x8B, 0x01, 0x01, 0x92, 0xAE, 0x53, 0xDA, 0x20, 0x03, 0xB9,
         0x18, 0xC1, 0x3B, 0x17, 0xCA, 0x1A, 0x35, 0xB9, 0x0A, 0x12, 0xCA, 0x68, 0x94, 0x9C, 0x11, 0x11,
         0xBA, 0x10, 0x11, 0xAA, 0x43, 0xA1, 0x8F, 0x12, 0x0C, 0x05, 0xBB, 0x41, 0xA0, 0x32, 0xFA, 0x4A,
         0x83, 0xAD, 0x32, 0xB9, 0x52, 0xA1, 0x9B, 0x10, 0x91, 0x10, 0xD8, 0x48, 0xB2, 0x49, 0xA5, 0x8D,
         0x84, 0x8B, 0x22, 0x89, 0x22, 0xCE, 0x51, 0xA1, 0x1C, 0x83, 0x8C, 0x02, 0x28, 0xA2, 0xAB, 0x21,
         0x8C, 0x26, 0xAD, 0x22, 0x09, 0x92, 0x8A, 0x41, 0xF9, 0x39, 0xA4, 0x1A, 0xA4, 0x2C, 0x94, 0x0B,
         0x91, 0x21, 0xB9, 0x20, 0x1A, 0xA4, 0x7B, 0xD2, 0x59, 0xE8, 0x20, 0x80, 0xA0, 0x68, 0xC0, 0x28,
         0xB1, 0x19, 0x03, 0x9C, 0x32, 0xCA, 0x50, 0xB0, 0x28, 0xA0, 0x88, 0x72, 0xB0, 0x0C, 0x12, 0xA0,
         0x9B, 0x44, 0xBA, 0x25, 0x88, 0xCA, 0x20, 0x1A, 0xC5, 0x1E, 0x05, 0x1A, 0xA0, 0x59, 0xC8, 0x40,
         0xC9, 0x20, 0x01, 0x98, 0x18, 0x90, 0xA9, 0x31, 0xB9, 0x46, 0xDA, 0x48, 0xB1, 0x19, 0xB8, 0x71,
         0xA1, 0x09, 0x83, 0xBA, 0x31, 0xDC, 0x62, 0xB9, 0x41, 0x99, 0x03, 0xAC, 0x32, 0xC8, 0x28, 0xA8,
         0x42, 0xB9, 0x28, 0xB3, 0x2D, 0x95, 0x8A, 0x80, 0x01, 0x40, 0xFA, 0x48, 0x90, 0x00, 0x88, 0x00,
         0xBB, 0x61, 0x91, 0x1C, 0x13, 0x8A, 0xAA, 0x33, 0x1D, 0xB6, 0x2E, 0xA4, 0x2A, 0xA0, 0x29, 0x23,
         0xF0, 0x48, 0xD2, 0x2B, 0x82, 0x8B, 0x18, 0x23, 0x09, 0xA0, 0x28, 0x00, 0xF9, 0x1B, 0x25, 0xB9,
         0x21, 0x9D, 0x14, 0x9D, 0x43, 0xB2, 0x0E, 0x12, 0x8B, 0x91, 0x18, 0x12, 0xA0, 0x8F, 0x23, 0xBA,
         0x08, 0x43, 0xA1, 0x0A, 0x01, 0x22, 0xAF, 0xC9, 0x71, 0xA0, 0x00, 0x18, 0xE0, 0x58, 0xA3, 0x0B,
         0xA2, 0x2B, 0xA2, 0x99, 0x40, 0x92, 0xCA, 0x78, 0x93, 0xAA, 0x3A, 0x82, 0x45, 0xCD, 0x10, 0x08,
         0x80, 0x92, 0x0E, 0x05, 0x0C, 0x06, 0xA9, 0x98, 0x31, 0xF8, 0x29, 0x83, 0x1A, 0x93, 0x39, 0xFA,
         0x48, 0xB0, 0x28, 0x88, 0x01, 0x89, 0x13, 0xEB, 0x49, 0xA3, 0x1D, 0x82, 0x10, 0xBB, 0x34, 0xDA,
         0x48, 0xA0, 0x28, 0x81, 0xA8, 0x3A, 0xE8, 0x71, 0xB1, 0x0C, 0x42, 0xA0, 0x8C, 0x03, 0x19, 0xC0,
         0x29, 0x01, 0x98, 0x44, 0xF9, 0x29, 0x84, 0xAA, 0x39, 0x84, 0x9D, 0x41, 0x91, 0x89, 0x98, 0x19,
         0x93, 0x6A, 0xD2, 0x1D, 0x15, 0xA9, 0x99, 0x58, 0xA2, 0x1B, 0x82, 0x09, 0x08, 0x80, 0xAB, 0x56,
         0xB8, 0x20, 0xBB, 0x73, 0xC9, 0x2A, 0x12, 0x91, 0x8D, 0x25, 0xA8, 0xAB, 0x34, 0xCB, 0x41, 0xA1,
         0xBA, 0x62, 0xB1, 0x1A, 0x84, 0xBA, 0x41, 0xA1, 0x8C, 0x24, 0xA8, 0x10, 0x8C, 0x15, 0xBE, 0x30,
         0x04, 0xBA, 0x51, 0xB1, 0x2A, 0xA3, 0x9E, 0x31, 0x90, 0x2B, 0x83, 0x0B, 0x16, 0xDA, 0x39, 0x84,
         0x8B, 0x02, 0xAA, 0x40, 0xC1, 0x0E, 0x14, 0x88, 0x80, 0x18, 0xC8, 0x30, 0xF9, 0x30, 0xA9, 0x43,
         0xA8, 0xAA, 0x58, 0xA1, 0x62, 0xC8, 0x18, 0xA9, 0x22, 0xBC, 0x22, 0x8A, 0x57, 0xB0, 0x0A, 0x98,
         0x30, 0xC0, 0x1B, 0x33, 0x91, 0xB9, 0x72, 0xE2, 0x1B, 0x94, 0x0B, 0x14, 0x90, 0x8C, 0x13, 0xAB,
         0x23, 0xBA, 0x60, 0x84, 0x9E, 0x22, 0xBA, 0x12, 0x8C, 0x27, 0xD9, 0x20, 0x90, 0x0A, 0x81, 0x98,
         0x00, 0x32, 0x94, 0x9C, 0x02, 0x9B, 0xA0, 0x0C, 0x27, 0x8A, 0x31, 0xD8, 0x49, 0xB1, 0x0D, 0x22,
         0x90, 0x29, 0xC1, 0x3B, 0xA4, 0x2B, 0xF1, 0x3A, 0x17, 0x8A, 0x98, 0x20, 0x90, 0xD9, 0x4A, 0x93,
         0x29, 0xA9, 0x54, 0xDB, 0x50, 0xB0, 0x1A, 0x13, 0x99, 0xA1, 0x0B, 0x93, 0x8A, 0x56, 0xD0, 0x29,
         0x03, 0xFA, 0x39, 0x84, 0x9C, 0x11, 0x88, 0x11, 0x98, 0x21, 0xBB, 0x22, 0x8A, 0x13, 0xFC, 0x50,
         0x90, 0x89, 0x0A, 0x26, 0xAC, 0x32, 0xB8, 0x08, 0x33, 0xFC, 0x30, 0xA9, 0x31, 0x9A, 0x21, 0x88,
         0xB0, 0x50, 0xE9, 0x40, 0xA0, 0xB9, 0x71, 0xC0, 0x48, 0x90, 0x29, 0xB1, 0x1C, 0x13, 0xEB, 0x51,
         0xC0, 0x49, 0x92, 0x8B, 0x18, 0x22, 0xFA, 0x38, 0x92, 0x8A, 0xA2, 0x5B
     };

/******************************************AUDIO************************************/

#ifdef __MMI_TOUCH_SCREEN__
static void mmi_gx_topgun_update_fighter_position_by_pen(void)                                                                                          
{                                                                                                                          
   /* when the fighter is exploding, its explosion moving speed is identical to the background */                          
   if (g_gx_topgun_context.fighter_state != MMI_GX_TOPGUN_NORMAL_STATE && g_gx_topgun_context.fighter_state != MMI_GX_TOPGUN_HIT_STATE)
   {                                                                                                                       
      g_gx_topgun_context.fighter_position.y = g_gx_topgun_context.fighter_position.y + MMI_GX_TOPGUN_BACKGROUND_SPEED;             
      /* when 2 seconds past after the explosion ended */                                                                  
      if (g_gx_topgun_context.tick - g_gx_topgun_context.fighter_dying_time > 25)                                                
      {                                                                                                                    
         mmi_gx_topgun_gameover();                                                                                            
      }                                                                                                                    
   }                                                                                                                       
}       
#endif  //__MMI_TOUCH_SCREEN__
static void mmi_gx_topgun_update_fighter_position_by_key(void)                                                                                          
{                                                                                                                          
   g_gx_topgun_context.fighter_old_position.y = g_gx_topgun_context.fighter_position.y;                                          
   g_gx_topgun_context.fighter_old_position.x = g_gx_topgun_context.fighter_position.x;                                          
   /* when the fighter is alive, it move normally */                                                                       
   if (g_gx_topgun_context.fighter_state == MMI_GX_TOPGUN_NORMAL_STATE || g_gx_topgun_context.fighter_state == MMI_GX_TOPGUN_HIT_STATE)
   {                                                                                                                       
      if (g_gx_topgun_context.up_key_pressed != MMI_FALSE)                                                                        
      {                                                                                                                    
         g_gx_topgun_context.fighter_position.y = g_gx_topgun_context.fighter_position.y - MMI_GX_TOPGUN_FIGHTER_SPEED;             
         if (g_gx_topgun_context.fighter_position.y < MMI_GX_TOPGUN_ORIGIN)                                                      
         {                                                                                                                 
            g_gx_topgun_context.fighter_position.y = MMI_GX_TOPGUN_ORIGIN;                                                      
         }                                                                                                                 
      }                                                                                                                    
      if (g_gx_topgun_context.down_key_pressed != MMI_FALSE)                                                                      
      {                                                                                                                    
         g_gx_topgun_context.fighter_position.y = g_gx_topgun_context.fighter_position.y + MMI_GX_TOPGUN_FIGHTER_SPEED;             
         if (g_gx_topgun_context.fighter_position.y > MMI_GX_TOPGUN_LCD_HEIGHT - MMI_GX_TOPGUN_ROLE_HEIGHT - 1)                     
         {                                                                                                                 
            g_gx_topgun_context.fighter_position.y = MMI_GX_TOPGUN_LCD_HEIGHT - MMI_GX_TOPGUN_ROLE_HEIGHT - 1;                      
         }                                                                                                                 
      }                                                                                                                    
      if (g_gx_topgun_context.left_key_pressed != MMI_FALSE)                                                                      
      {                                                                                                                    
         g_gx_topgun_context.fighter_position.x = g_gx_topgun_context.fighter_position.x - MMI_GX_TOPGUN_FIGHTER_SPEED;             
         if (g_gx_topgun_context.fighter_position.x < 0)                                                                      
         {                                                                                                                 
            g_gx_topgun_context.fighter_position.x = 0;                                                                       
         }                                                                                                                 
      }                                                                                                                    
      if (g_gx_topgun_context.right_key_pressed != MMI_FALSE)                                                                     
      {                                                                                                                    
         g_gx_topgun_context.fighter_position.x = g_gx_topgun_context.fighter_position.x + MMI_GX_TOPGUN_FIGHTER_SPEED;             
         if (g_gx_topgun_context.fighter_position.x > MMI_GX_TOPGUN_LCD_WIDTH - MMI_GX_TOPGUN_ROLE_WIDTH - 1)                       
         {                                                                                                                
            g_gx_topgun_context.fighter_position.x = MMI_GX_TOPGUN_LCD_WIDTH - MMI_GX_TOPGUN_ROLE_WIDTH - 1;                        
         }                                                                                                                 
      }                                                                                                                    
   }                                                                                                                       
   /* when the fighter is exploding, its explosion moving speed is identical to the background */                          
   else                                                                                                                    
   {                                                                                                                       
      g_gx_topgun_context.fighter_position.y = g_gx_topgun_context.fighter_position.y + MMI_GX_TOPGUN_BACKGROUND_SPEED;             
      /* when 2 seconds past after the explosion ended */                                                                  
      if (g_gx_topgun_context.tick - g_gx_topgun_context.fighter_dying_time > 25)                                                
      {                                                                                                                    
         mmi_gx_topgun_gameover();                                                                                            
      }                                                                                                                    
   }                                                                                                                       
}


static void mmi_gx_topgun_new_enemy_bullet(gx_topgun_enemy_struct *enemy)                                                                                  
{                                                                                                           
   /* maintain the data structure */                                                                        
   if (g_gx_topgun_context.first_empty_enemy_bullet_list == NULL)                                                                                 
   {                                                                                                                          
      return;                                            
   }                                                                                                                          
   /* when the list is not empty */                                                                         
   if (g_gx_topgun_context.first_enemy_bullet != NULL)                                                         
   {                                                                                                        
      g_gx_topgun_context.last_enemy_bullet->next = g_gx_topgun_context.first_empty_enemy_bullet_list;            
      g_gx_topgun_context.first_empty_enemy_bullet_list->previous = g_gx_topgun_context.last_enemy_bullet;        
      g_gx_topgun_context.last_enemy_bullet = g_gx_topgun_context.first_empty_enemy_bullet_list;                  
      g_gx_topgun_context.first_empty_enemy_bullet_list = g_gx_topgun_context.first_empty_enemy_bullet_list->next;
   }                                                                                                        
   /* when the list is empty */                                                                             
   else                                                                                                     
   {                                                                                                        
      g_gx_topgun_context.first_enemy_bullet = g_gx_topgun_context.first_empty_enemy_bullet_list;                 
      g_gx_topgun_context.last_enemy_bullet = g_gx_topgun_context.first_empty_enemy_bullet_list;                  
      g_gx_topgun_context.first_empty_enemy_bullet_list = g_gx_topgun_context.first_empty_enemy_bullet_list->next;
   }                                                                                                        
   g_gx_topgun_context.last_enemy_bullet->next = NULL;                                                         
   /* initialize the data of the bullet */                                                                  
   if (enemy->image_offset == (IMG_ID_GX_TOPGUN_BOSS - IMG_ID_GX_TOPGUN_ENEMY_1))                                                      
   {                                                                                                        
       g_gx_topgun_context.last_enemy_bullet->image_offset = (IMG_ID_GX_TOPGUN_BOSS_BULLET - IMG_ID_GX_TOPGUN_ENEMY_BULLET_1);        
   }                                                                                                        
   else                                                                                               
   {                                                                                                  
       g_gx_topgun_context.last_enemy_bullet->image_offset = rand() % MMI_GX_TOPGUN_ENEMY_BULLET_IMAGE_COUNT;        
   }                                                                                                  
   g_gx_topgun_context.last_enemy_bullet->x = enemy->x + MMI_GX_TOPGUN_ENEMY_WIDTH / 2 - MMI_GX_TOPGUN_ENEMY_BULLET_WIDTH / 2;  
   g_gx_topgun_context.last_enemy_bullet->y = enemy->y + MMI_GX_TOPGUN_ENEMY_HEIGHT;                                         
   /* if the enemy is in attack type 2, then the bullet will simply go down */                              
   if (enemy->attack_type == MMI_GX_TOPGUN_ATTACK_TYPE_2)                                                      
   {                                                                                                        
      g_gx_topgun_context.last_enemy_bullet->vector_x = 0;                                                     
      g_gx_topgun_context.last_enemy_bullet->vector_y = MMI_GX_TOPGUN_ENEMY_BULLET_SPEED;                         
   }                                                                                                        
   /* if the enemy is in attack type 3, then the bullet will roughly trace the fighter */                   
   else if (enemy->attack_type == MMI_GX_TOPGUN_ATTACK_TYPE_3)                                                 
   {                                                                                                        
      /* if the fighter and the enemy are on the same horizontal line */                                    
      if (enemy->y == g_gx_topgun_context.fighter_position.y)                                                  
      {                                                                                                     
         /* if the fighter is at right side */                                                              
         if (g_gx_topgun_context.fighter_position.x > enemy->x)                                                
         {                                                                                                  
            g_gx_topgun_context.last_enemy_bullet->vector_x = MMI_GX_TOPGUN_ENEMY_BULLET_SPEED;                   
         }                                                                                                  
         else                                                                                               
         {                                                                                                  
            g_gx_topgun_context.last_enemy_bullet->vector_x = -MMI_GX_TOPGUN_ENEMY_BULLET_SPEED;                  
         }                                                                                                  
      }                                                                                                     
      /* if the fighter and the enemy are on the same vertical line */                                      
      else if (enemy->x == g_gx_topgun_context.fighter_position.x)                                             
      {                                                                                                     
         /* if the fighter is at lower side */                                                              
         if (g_gx_topgun_context.fighter_position.y > enemy->y)                                                
         {                                                                                                  
            g_gx_topgun_context.last_enemy_bullet->vector_y = MMI_GX_TOPGUN_ENEMY_BULLET_SPEED;                   
         }                                                                                                  
         else                                                                                               
         {                                                                                                  
            g_gx_topgun_context.last_enemy_bullet->vector_y = -MMI_GX_TOPGUN_ENEMY_BULLET_SPEED;                  
         }                                                                                                  
      }                                                                                                     
      /* other case */                                                                                      
      else                                                                                                  
      {                                                                                                     
         S32 offset_x = g_gx_topgun_context.fighter_position.x - enemy->x;                                         
         S32 offset_y = g_gx_topgun_context.fighter_position.y - enemy->y;                                         
         if (offset_x > 0 && offset_y > 0)                                                                  
         {                                                                                                  
            if (offset_x > offset_y)                                                                        
            {                                                                                               
               g_gx_topgun_context.last_enemy_bullet->vector_x = (MMI_GX_TOPGUN_ENEMY_BULLET_SPEED + 1) / 1;      
               g_gx_topgun_context.last_enemy_bullet->vector_y = (MMI_GX_TOPGUN_ENEMY_BULLET_SPEED - 1) / 1;      
            }                                                                                               
            else                                                                                            
            {                                                                                               
               g_gx_topgun_context.last_enemy_bullet->vector_x = (MMI_GX_TOPGUN_ENEMY_BULLET_SPEED - 1) / 1;      
               g_gx_topgun_context.last_enemy_bullet->vector_y = (MMI_GX_TOPGUN_ENEMY_BULLET_SPEED + 1) / 1;      
            }                                                                                               
         }                                                                                                  
         else if (offset_x > 0 && offset_y < 0)                                                             
         {                                                                                                  
            if (offset_x > -offset_y)                                                                       
            {                                                                                               
               g_gx_topgun_context.last_enemy_bullet->vector_x = (MMI_GX_TOPGUN_ENEMY_BULLET_SPEED + 1) / 1;      
               g_gx_topgun_context.last_enemy_bullet->vector_y = -(MMI_GX_TOPGUN_ENEMY_BULLET_SPEED - 1) / 1;     
            }                                                                                               
            else                                                                                            
            {                                                                                               
               g_gx_topgun_context.last_enemy_bullet->vector_x = (MMI_GX_TOPGUN_ENEMY_BULLET_SPEED - 1) / 1;      
               g_gx_topgun_context.last_enemy_bullet->vector_y = -(MMI_GX_TOPGUN_ENEMY_BULLET_SPEED + 1) / 1;     
            }                                                                                               
         }                                                                                                  
         else if (offset_x < 0 && offset_y > 0)                                                             
         {                                                                                                  
            if (-offset_x > offset_y)                                                                       
            {                                                                                               
               g_gx_topgun_context.last_enemy_bullet->vector_x = -(MMI_GX_TOPGUN_ENEMY_BULLET_SPEED + 1) / 1;     
               g_gx_topgun_context.last_enemy_bullet->vector_y = (MMI_GX_TOPGUN_ENEMY_BULLET_SPEED - 1) / 1;      
            }                                                                                               
            else                                                                                            
            {                                                                                               
               g_gx_topgun_context.last_enemy_bullet->vector_x = -(MMI_GX_TOPGUN_ENEMY_BULLET_SPEED - 1) / 1;     
               g_gx_topgun_context.last_enemy_bullet->vector_y = (MMI_GX_TOPGUN_ENEMY_BULLET_SPEED + 1) / 1;      
            }                                                                                               
         }                                                                                                  
         else if (offset_x < 0 && offset_y < 0)                                                             
         {                                                                                                  
            if (-offset_x > -offset_y)                                                                      
            {                                                                                               
               g_gx_topgun_context.last_enemy_bullet->vector_x = -(MMI_GX_TOPGUN_ENEMY_BULLET_SPEED + 1) / 1;     
               g_gx_topgun_context.last_enemy_bullet->vector_y = -(MMI_GX_TOPGUN_ENEMY_BULLET_SPEED - 1) / 1;     
            }                                                                                               
            else                                                                                            
            {                                                                                               
               g_gx_topgun_context.last_enemy_bullet->vector_x = -(MMI_GX_TOPGUN_ENEMY_BULLET_SPEED - 1) / 1;     
               g_gx_topgun_context.last_enemy_bullet->vector_y = -(MMI_GX_TOPGUN_ENEMY_BULLET_SPEED + 1) / 1;     
            }                                                                                               
         }                                                                                                  
      }                                                                                                     
   }                                                                                                        
   g_gx_topgun_context.last_enemy_bullet->old_x = g_gx_topgun_context.last_enemy_bullet->x;                       
   g_gx_topgun_context.last_enemy_bullet->old_y = g_gx_topgun_context.last_enemy_bullet->y;                       
}                                                                                                           

static void mmi_gx_topgun_new_fighter_bullet()                                                                              
{                                                                                                         
   /* maintain the data structure */                                                                      
   if (g_gx_topgun_context.first_empty_bullet_list == NULL)                                                                                 
   {                                                                                                                          
      return;                                            
   }                                                                                                                          
   /* when the list is not empty */                                                                       
   if (g_gx_topgun_context.first_bullet != NULL)                                                             
   {                                                                                                      
      g_gx_topgun_context.last_bullet->next = g_gx_topgun_context.first_empty_bullet_list;                      
      g_gx_topgun_context.first_empty_bullet_list->previous = g_gx_topgun_context.last_bullet;                  
      g_gx_topgun_context.last_bullet = g_gx_topgun_context.first_empty_bullet_list;                            
      g_gx_topgun_context.first_empty_bullet_list = g_gx_topgun_context.first_empty_bullet_list->next;          
   }                                                                                                      
   /* when the list is empty */                                                                           
   else                                                                                                   
   {                                                                                                      
      g_gx_topgun_context.first_bullet = g_gx_topgun_context.first_empty_bullet_list;                           
      g_gx_topgun_context.last_bullet = g_gx_topgun_context.first_empty_bullet_list;                            
      g_gx_topgun_context.first_empty_bullet_list = g_gx_topgun_context.first_empty_bullet_list->next;          
   }                                                                                                      
   g_gx_topgun_context.last_bullet->next = NULL;                                                             
                                                                                                          
   /* initialize the data of the bullet */                                                                
   g_gx_topgun_context.last_bullet->type = g_gx_topgun_context.fighter_weapon;                                  
   g_gx_topgun_context.last_bullet->x = mmi_gx_topgun_get_bullet_position_x(g_gx_topgun_context.last_bullet->type);
   g_gx_topgun_context.last_bullet->y = mmi_gx_topgun_get_bullet_position_y();                                  
   g_gx_topgun_context.last_bullet->old_x = g_gx_topgun_context.last_bullet->x;                                 
   g_gx_topgun_context.last_bullet->old_y = g_gx_topgun_context.last_bullet->y;                                 
}                                                                                                         

static void mmi_gx_topgun_copy_enemy_data(gx_topgun_enemy_struct *target_enemy, gx_topgun_enemy_struct *source_enemy)        
{                                                          
   target_enemy->image_offset = source_enemy->image_offset;
   target_enemy->move_type = source_enemy->move_type;      
   target_enemy->vector_x = source_enemy->vector_x;        
   target_enemy->attack_type = source_enemy->attack_type;  
   target_enemy->life = source_enemy->life;                
   target_enemy->x = source_enemy->x;                      
   target_enemy->y = source_enemy->y;                      
   target_enemy->old_x = source_enemy->old_x;              
   target_enemy->old_y = source_enemy->old_y;              
   target_enemy->state = source_enemy->state;              
}                                                          

static void mmi_gx_topgun_new_enemy()                                                                                                           
{                                                                                                                             
   /* maintain the data structure */                                                                                          
   if (g_gx_topgun_context.first_empty_enemy_list == NULL)                                                                                  
   {                                                                                                                          
      return;                                            
   }                                                                                                                          
   /* when the list is not empty */                                                                                           
   if (g_gx_topgun_context.first_enemy != NULL)                                                                                  
   {                                                                                                                          
      g_gx_topgun_context.last_enemy->next = g_gx_topgun_context.first_empty_enemy_list;                                            
      g_gx_topgun_context.first_empty_enemy_list->previous = g_gx_topgun_context.last_enemy;                                        
      g_gx_topgun_context.last_enemy = g_gx_topgun_context.first_empty_enemy_list;                                                  
      g_gx_topgun_context.first_empty_enemy_list = g_gx_topgun_context.first_empty_enemy_list->next;                                
   }                                                                                                                          
   /* when the list is empty */                                                                                               
   else                                                                                                                       
   {                                                                                                                          
      g_gx_topgun_context.first_enemy = g_gx_topgun_context.first_empty_enemy_list;                                                 
      g_gx_topgun_context.last_enemy = g_gx_topgun_context.first_empty_enemy_list;                                                  
      g_gx_topgun_context.first_empty_enemy_list = g_gx_topgun_context.first_empty_enemy_list->next;                                
   }                                                                                                                          
                                                                                                                              
   /* initialize the data of the enemy */                                                                                     
   /* when the enemy is just a normal enemy, not a boss */                                                                    
   if (g_gx_topgun_context.is_boss_on != MMI_TRUE)                                                                                  
   {                                                                                                                          
      /* it's the first enemy of the enemy series */                                                                          
      if (g_gx_topgun_context.enemy_pattern_number == 0)                                                                         
      {                                                                                                                       
         /* determine how many enemies there are in this series */                                                            
         g_gx_topgun_context.enemy_pattern_number = rand() % MMI_GX_TOPGUN_ENEMY_PATTERN_NUMBER;                                    
                                                                                                                              
         g_gx_topgun_context.last_enemy->image_offset = rand() % MMI_GX_TOPGUN_ENEMY_IMAGE_COUNT;                                   
         g_gx_topgun_context.last_enemy->move_type = rand() % MMI_GX_TOPGUN_MOVE_TYPE_COUNT;                                        
         if (g_gx_topgun_context.last_enemy->move_type == MMI_GX_TOPGUN_MOVE_TYPE_4)                                                
         {                                                                                                                    
            g_gx_topgun_context.last_enemy->vector_x = 3;                                                                        
         }                                                                                                                    
         else if (g_gx_topgun_context.last_enemy->move_type == MMI_GX_TOPGUN_MOVE_TYPE_5)                                          
         {                                                                                                                    
            g_gx_topgun_context.last_enemy->vector_x = -3;                                                                       
         }                                                                                                                    
         /* for the first 30 sec., the enemy is in attack mode 1 */                                                           
         if (g_gx_topgun_context.tick < MMI_GX_TOPGUN_STAGE_INTERVAL)                                                               
         {                                                                                                                    
            g_gx_topgun_context.last_enemy->attack_type = MMI_GX_TOPGUN_ATTACK_TYPE_1;                                              
         }                                                                                                                    
         /* between 30 sec. and 60 sec., it's in attack mdoe 2 */                                                             
         else if (g_gx_topgun_context.tick >= MMI_GX_TOPGUN_STAGE_INTERVAL && g_gx_topgun_context.tick < MMI_GX_TOPGUN_STAGE_INTERVAL * 2)
         {                                                                                                                    
            g_gx_topgun_context.last_enemy->attack_type = MMI_GX_TOPGUN_ATTACK_TYPE_2;                                              
         }                                                                                                                    
         /* after 60 sec., it enters attack mdoe 3 */                                                                         
         else if (g_gx_topgun_context.tick >= MMI_GX_TOPGUN_STAGE_INTERVAL * 2)                                                     
         {                                                                                                                    
            g_gx_topgun_context.last_enemy->attack_type = MMI_GX_TOPGUN_ATTACK_TYPE_3;                                              
         }                                                                                                                    
                                                                                                                              
         g_gx_topgun_context.last_enemy->starting_time = g_gx_topgun_context.tick;                                                  
         /* the life of enemy is about MMI_GX_TOPGUN_ENEMY_LIFE_BASE to MMI_GX_TOPGUN_ENEMY_LIFE_BASE + 1 */                        
         g_gx_topgun_context.last_enemy->life = g_gx_topgun_context.stage_count * MMI_GX_TOPGUN_ENEMY_LIFE_BASE + rand() % 2;          
         g_gx_topgun_context.last_enemy->x = mmi_gx_topgun_get_enemy_position_x(g_gx_topgun_context.last_enemy->move_type);            
         g_gx_topgun_context.last_enemy->y = 0;                                                                                  
         g_gx_topgun_context.last_enemy->old_x = g_gx_topgun_context.last_enemy->x;                                                 
         g_gx_topgun_context.last_enemy->old_y = g_gx_topgun_context.last_enemy->y;                                                 
         g_gx_topgun_context.last_enemy->state = MMI_GX_TOPGUN_NORMAL_STATE;                                                        
         /* copy the information of this enemy for later use (to set up the next enemy in this series) */                     
         mmi_gx_topgun_copy_enemy_data(g_gx_topgun_context.enemy_model, g_gx_topgun_context.last_enemy);                                          
      }                                                                                                                       
      /* it's the enemy in a series other than the first one */                                                               
      else                                                                                                                    
      {                                                                                                                       
         g_gx_topgun_context.enemy_pattern_number = g_gx_topgun_context.enemy_pattern_number - 1;                                   
         g_gx_topgun_context.last_enemy->starting_time = g_gx_topgun_context.tick;                                                  
         /* copy the information needed of the first enemy of this series to this new enemy */                                
         mmi_gx_topgun_copy_enemy_data(g_gx_topgun_context.last_enemy, g_gx_topgun_context.enemy_model);                                          
      }                                                                                                                       
   }                                                                                                                          
   /* the new enermy is a boss */                                                                                             
   else                                                                                                                       
   {                                                                                                                          
      g_gx_topgun_context.last_enemy->image_offset = IMG_ID_GX_TOPGUN_BOSS - IMG_ID_GX_TOPGUN_ENEMY_1;                                 
      g_gx_topgun_context.last_enemy->move_type = rand() % MMI_GX_TOPGUN_MOVE_TYPE_COUNT;                                          
      if (g_gx_topgun_context.last_enemy->move_type == MMI_GX_TOPGUN_MOVE_TYPE_4)                                                   
      {                                                                                                                       
         g_gx_topgun_context.last_enemy->vector_x = 4;                                                                           
      }                                                                                                                       
      else if (g_gx_topgun_context.last_enemy->move_type == MMI_GX_TOPGUN_MOVE_TYPE_5)                                              
      {                                                                                                                       
         g_gx_topgun_context.last_enemy->vector_x = -4;                                                                          
      }                                                                                                                       
      g_gx_topgun_context.last_enemy->attack_type = MMI_GX_TOPGUN_ATTACK_TYPE_3;                                                    
      g_gx_topgun_context.last_enemy->starting_time = g_gx_topgun_context.tick;                                                     
      g_gx_topgun_context.last_enemy->life = 15 * (g_gx_topgun_context.stage_count * MMI_GX_TOPGUN_ENEMY_LIFE_BASE + rand() % 2);      
      g_gx_topgun_context.last_enemy->x = mmi_gx_topgun_get_enemy_position_x(g_gx_topgun_context.last_enemy->move_type);               
      g_gx_topgun_context.last_enemy->y = 0;                                                                                     
      g_gx_topgun_context.last_enemy->old_x = g_gx_topgun_context.last_enemy->x;                                                    
      g_gx_topgun_context.last_enemy->old_y = g_gx_topgun_context.last_enemy->y;                                                    
      g_gx_topgun_context.last_enemy->state = MMI_GX_TOPGUN_NORMAL_STATE;                                                           
   }                                                                                                                          
}                                                                                                                             

static void mmi_gx_topgun_remove_enemy_from_list(gx_topgun_enemy_struct *enemy)                                                
{                                                                                    
   /* if there is only one enemy in the list */                                      
   if (enemy == g_gx_topgun_context.first_enemy && enemy == g_gx_topgun_context.last_enemy)
   {
        mmi_gx_topgun_init_enemy_list();
   }                                                                                 
   /* there are more than one enemies in the list */                                 
   else                                                                              
   {                                                                                 
      /* if it's the first enemy in the list */                                      
      if (enemy == g_gx_topgun_context.first_enemy)                                     
      {                                                   
         g_gx_topgun_context.first_enemy = enemy->next;                                   
         g_gx_topgun_context.last_empty_enemy_list->next = enemy;                       
         enemy->previous = g_gx_topgun_context.last_empty_enemy_list;                   
         g_gx_topgun_context.last_empty_enemy_list = enemy;    
         g_gx_topgun_context.last_empty_enemy_list->next = NULL;                         
      }                                                                              
      /* if it's the last enemy in the list */                                       
      else if (enemy == g_gx_topgun_context.last_enemy)                                 
      {                                                                              
         g_gx_topgun_context.last_enemy = enemy->previous;                              
         g_gx_topgun_context.last_empty_enemy_list->next = enemy;                       
         enemy->previous = g_gx_topgun_context.last_empty_enemy_list;                   
         g_gx_topgun_context.last_empty_enemy_list = enemy;    
         g_gx_topgun_context.last_empty_enemy_list->next = NULL;                         
         g_gx_topgun_context.last_enemy->next = NULL;                                   
      }                                                                              
      /* normal case */                                                              
      else                                                                           
      {                                                                              
         enemy->previous->next = enemy->next;     
         if (enemy->next != NULL)
            enemy->next->previous = enemy->previous;                                    
         g_gx_topgun_context.last_empty_enemy_list->next = enemy;                       
         enemy->previous = g_gx_topgun_context.last_empty_enemy_list;                   
         g_gx_topgun_context.last_empty_enemy_list = enemy;
         g_gx_topgun_context.last_empty_enemy_list->next = NULL;
      }                                                                              
   }                                                                                 
}                                                                                    

static void mmi_gx_topgun_remove_enemy_bullet_from_list(gx_topgun_enemy_bullet_struct *bullet)                                                        
{                                                                                                    
   /* if there is only one enemy bullet in the list */                                               
   if (bullet == g_gx_topgun_context.first_enemy_bullet && bullet == g_gx_topgun_context.last_enemy_bullet)
   {
        mmi_gx_topgun_init_enemy_bullet_list();
   }                                                                                                 
   /* there are more than one enemy bullets in the list */                                           
   else                                                                                              
   {                                                                                                 
      /* if it's the first bullet in the list */                                                     
      if (bullet == g_gx_topgun_context.first_enemy_bullet)                                             
      {                                                                                               
         g_gx_topgun_context.first_enemy_bullet = bullet->next;                                       
         g_gx_topgun_context.last_empty_enemy_bullet_list->next = bullet;                               
         bullet->previous = g_gx_topgun_context.last_empty_enemy_bullet_list;                           
         g_gx_topgun_context.last_empty_enemy_bullet_list = bullet;     
         g_gx_topgun_context.last_empty_enemy_bullet_list->next = NULL;                                 
      }                                                                                              
      /* if it's the last bullet in the list */                                                      
      else if (bullet == g_gx_topgun_context.last_enemy_bullet)                                         
      {                                                                                              
         g_gx_topgun_context.last_enemy_bullet = bullet->previous;                                      
         g_gx_topgun_context.last_empty_enemy_bullet_list->next = bullet;                               
         bullet->previous = g_gx_topgun_context.last_empty_enemy_bullet_list;                           
         g_gx_topgun_context.last_empty_enemy_bullet_list = bullet;    
         g_gx_topgun_context.last_empty_enemy_bullet_list->next = NULL;                                    
         g_gx_topgun_context.last_enemy_bullet->next = NULL;                                            
      }                                                                                              
      /* normal case */                                                                              
      else                                                                                           
      {                                                                                              
         bullet->previous->next = bullet->next;     
         if (bullet->next != NULL)
            bullet->next->previous = bullet->previous;                                                  
         g_gx_topgun_context.last_empty_enemy_bullet_list->next = bullet;                               
         bullet->previous = g_gx_topgun_context.last_empty_enemy_bullet_list;                           
         g_gx_topgun_context.last_empty_enemy_bullet_list = bullet;         
         g_gx_topgun_context.last_empty_enemy_bullet_list->next = NULL;                               
      }                                                                                              
   }                                                                                                 
}                                                                                                    


static void mmi_gx_topgun_remove_bullet_from_list(gx_topgun_bullet_struct *i)                                             
{                                                                              
   /* if there is only one bullet in the list */                               
   if (i == g_gx_topgun_context.first_bullet && i == g_gx_topgun_context.last_bullet)
   {      
        mmi_gx_topgun_init_bullet_list();
   }                                                                           
   /* there are more than one bullets in the list */                           
   else                                                                        
   {                                                                           
      /* if it's the first bullet in the list */                               
      if (i == g_gx_topgun_context.first_bullet)                                  
      {                                                                    
         g_gx_topgun_context.first_bullet = i->next;                                 
         g_gx_topgun_context.last_empty_bullet_list->next = i;                    
         i->previous = g_gx_topgun_context.last_empty_bullet_list;                
         g_gx_topgun_context.last_empty_bullet_list = i;                          
         g_gx_topgun_context.last_empty_bullet_list->next = NULL;       
         g_gx_topgun_context.last_empty_bullet_list->next = NULL;                 
      }                                                                        
      /* if it's the last bullet in the list */                                
      else if (i == g_gx_topgun_context.last_bullet)                              
      {                                                                        
         g_gx_topgun_context.last_bullet = i->previous;                           
         g_gx_topgun_context.last_empty_bullet_list->next = i;                    
         i->previous = g_gx_topgun_context.last_empty_bullet_list;                
         g_gx_topgun_context.last_empty_bullet_list = i;                          
         g_gx_topgun_context.last_empty_bullet_list->next = NULL;    
         g_gx_topgun_context.last_empty_bullet_list->next = NULL;                         
         g_gx_topgun_context.last_bullet->next = NULL;                            
      }                                                                        
      /* normal case */                                                        
      else                                                                     
      {                                                                        
         i->previous->next = i->next;    
         if (i->next != NULL)
            i->next->previous = i->previous;                                      
         g_gx_topgun_context.last_empty_bullet_list->next = i;                    
         i->previous = g_gx_topgun_context.last_empty_bullet_list;                
         g_gx_topgun_context.last_empty_bullet_list = i;                          
         g_gx_topgun_context.last_empty_bullet_list->next = NULL;                    
      }                                                                        
   }                                                                           
}                                                                              

static U8 mmi_gx_topgun_get_treasure_type(void)                                                                       
{                                                                                                     
   /* the probability distribution of treasures => energy: weapon: invincibility: bomb = 2: 2: 1: 1 */
   S32 tmp = rand() % 6;                  
   U8 type = MMI_GX_TOPGUN_WEAPON_TREASURE;
   
   if (tmp < 2)                                                                                       
   {                                                                                                  
      type = MMI_GX_TOPGUN_ENERGY_TREASURE;                                                              
   }                                                                                                  
   else if (tmp > 4 && g_gx_topgun_context.tick < MMI_GX_TOPGUN_STAGE_INTERVAL * 4)                         
   {                                                                                                  
      type = MMI_GX_TOPGUN_BOMB_TREASURE;                                                                
   }                                                                                                  
   else if (tmp > 3 && tmp < 5)                                                                       
   {                                                                                                  
      type = MMI_GX_TOPGUN_INVINCIBLE_TREASURE;                                                          
   }                                                                                                  
   else                                                                                               
   {                                                                                                  
      type = MMI_GX_TOPGUN_WEAPON_TREASURE;                                                              
   }                                      
   return type;
}                                                                                                    

static void mmi_gx_topgun_reset_status(void)                                                       
{                                                                            
   g_gx_topgun_context.tick = 0;                                                
   g_gx_topgun_context.stage_ending_time = 0;                                   
   g_gx_topgun_context.energy = MMI_GX_TOPGUN_ENERGY_UNIT_COUNT;                   
   mmi_gx_topgun_draw_energy();                                                 
                                                                             
   g_gx_topgun_context.enemy_pattern_number = 0;                                
   g_gx_topgun_context.enemy_model = &(g_gx_topgun_context.enemy_model_memory[0]); 
   mmi_gx_topgun_init_enemy_list();                                             
   mmi_gx_topgun_init_enemy_bullet_list();                                      
   g_gx_topgun_context.boss_appearing_time = MMI_GX_TOPGUN_BOSS_APPEAR_TIME;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_enter_gfx
 * DESCRIPTION
 *  Set Game Framework (GFX) Parameter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* keep this game old naming style */
void mmi_gx_topgun_enter_gfx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Game menu */
    //GFX.game_data.game_img_id = IMG_ID_GX_TOPGUN_GAME_ICON;    /* game icon img ID */
    GFX.game_data.game_str_id = STR_ID_GX_TOPGUN_GAME_NAME;    /* game name string ID */
    GFX.game_data.menu_resume_str_id = STR_GAME_RESUME;     /* "Resume" string ID */
    GFX.game_data.menu_new_str_id = STR_GAME_NEW;           /* "New Game" string ID */
    GFX.game_data.menu_level_str_id = 0;                    /* "Game Level" string ID */
    GFX.game_data.menu_grade_str_id = STR_GAME_GRADE;       /* "Best Grade" string ID */
    GFX.game_data.menu_help_str_id = STR_GLOBAL_HELP;         /* "Game Help" string ID */

    /* level / grade */
    GFX.game_data.level_count = 1;                          /* how many levels */
    GFX.game_data.level_str_id_list[0] = STR_GAME_SCORE;    /* level string ID */

    /* add slot in NVRAMEnum.h */
    GFX.game_data.grade_nvram_id_list[0] = NVRAM_GX_TOPGUN_SCORE;  /* grade slot in NVRAM (short) */

    /* help */
    #ifndef __MMI_TOUCH_SCREEN__
    GFX.game_data.help_str_id = STR_ID_GX_TOPGUN_HELP_DESCRIPTION; /* help description string id */
    #else
    GFX.game_data.help_str_id = STR_ID_GX_TOPGUN_HELP_DESCRIPTION_TOUCH; /* help description string id */
    #endif

    /* misc */
    GFX.game_data.grade_value_ptr = (S16*) (&g_gx_topgun_context.game_grade);     /* current level's grade (S16*) */
    GFX.game_data.level_index_ptr = (U8*) (&g_gx_topgun_context.game_level);      /* ptr to current level index (U8*) */
    GFX.game_data.is_new_game = (MMI_BOOL*) (&g_gx_topgun_context.is_new_game);       /* ptr to new game flag (MMI_BOOL*) */

    /* function ptr */
    GFX.game_data.best_grade_func_ptr = mmi_gx_topgun_calc_best_grade;     /* function to calculate best grade */
    GFX.game_data.enter_game_func_ptr = mmi_gx_topgun_enter_game;  /* function to enter new game */
    GFX.game_data.exit_game_func_ptr = mmi_gx_topgun_exit_game;    /* function to exit game */
    GFX.game_data.draw_gameover_func_ptr = mmi_gx_topgun_draw_gameover;    /* function to draw gameover screen */

    /* some flags */
    GFX.game_data.is_keypad_audio_enable = MMI_FALSE;   /* play keypad tone or not */

    mmi_gfx_entry_menu_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_calc_best_grade
 * DESCRIPTION
 *  Calculate new best grade [Callback required by GFX]
 * PARAMETERS
 *  old_grade       [IN]        
 *  new_grade       [IN]        
 * RETURNS
 *  S16
 *****************************************************************************/
S16 mmi_gx_topgun_calc_best_grade(S16 old_grade, S16 new_grade)
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
 *  mmi_gx_topgun_draw_gameover
 * DESCRIPTION
 *  Draw Gameover Screen [Callback required by GFX]
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_draw_gameover(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GFX_PLAY_AUDIO_GAMEOVER();

    /* call this function to draw standard gameover screen */
    mmi_gfx_draw_gameover_screen(
        NULL,
        NULL,
        IMG_ID_GX_TOPGUN_BOSS_BULLET,
        g_gx_topgun_context.game_grade);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_enter_game
 * DESCRIPTION
 *  Enter Game [Callback required by GFX]
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_enter_game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__  //used for multilanguage
    mmi_topgun_language_index = g_mmi_game_current_language_index;
    mmi_gfx_check_image_get_valid_language(
        &mmi_topgun_language_index, 
        IMG_ID_GX_TOPGUN_LEVEL_CLEAR_LANGUAGE0, 
        MMI_TOPGUN_STRING_COUNT);
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */
    if (g_gx_topgun_context.is_new_game == MMI_TRUE)
    {
        mmi_gx_topgun_init_game(); /* is new game, otherwise resume game */
    }

    /* clear all keys */
    g_gx_topgun_context.up_key_pressed = MMI_FALSE;
    g_gx_topgun_context.down_key_pressed = MMI_FALSE;
    g_gx_topgun_context.left_key_pressed = MMI_FALSE;
    g_gx_topgun_context.right_key_pressed = MMI_FALSE;

    g_gx_topgun_context.is_new_game = MMI_FALSE;
    g_gx_topgun_context.is_gameover = MMI_FALSE;

    gdi_layer_multi_layer_enable();

    gdi_layer_get_base_handle(&g_gx_topgun_context.background);

    gdi_layer_create(0, 0, MMI_GX_TOPGUN_LCD_WIDTH, MMI_GX_TOPGUN_LCD_HEIGHT, &g_gx_topgun_context.foreground);
    gdi_layer_push_and_set_active(g_gx_topgun_context.foreground);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_BLUE); /* set pure-blue as the transparent color in foreground */
    gdi_layer_clear_background(GDI_COLOR_BLUE);     /* clean foreground layer */
    gdi_layer_pop_and_restore_active();

    SetKeyHandler(mmi_gx_topgun_key_2_press, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_topgun_key_8_press, KEY_8, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_topgun_key_4_press, KEY_4, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_topgun_key_6_press, KEY_6, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_gx_topgun_key_2_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_topgun_key_8_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_topgun_key_4_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_gx_topgun_key_6_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_gx_topgun_key_2_release, KEY_2, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_topgun_key_8_release, KEY_8, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_topgun_key_4_release, KEY_4, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_topgun_key_6_release, KEY_6, KEY_EVENT_UP);

    SetKeyHandler(mmi_gx_topgun_key_2_release, KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_topgun_key_8_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_topgun_key_4_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_topgun_key_6_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
     
#ifdef __MMI_TOUCH_SCREEN__ 
    wgui_register_pen_down_handler(mmi_gx_topgun_pen_down_hdlr);    /* function to pen down event */
    wgui_register_pen_up_handler(mmi_gx_topgun_pen_up_hdlr);        /* function to pen up event */
    wgui_register_pen_move_handler(mmi_gx_topgun_pen_move_hdlr);    /* function to pen up event */
#endif  //__MMI_TOUCH_SCREEN__

    /* draw background image (on background layer) */
    mmi_gx_topgun_draw_static_background();

    /* start game loop */
    mmi_gx_topgun_cyclic_timer();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_draw_static_background
 * DESCRIPTION
 *  Draw static background
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_draw_static_background(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(0, 0, MMI_GX_TOPGUN_LCD_WIDTH, MMI_GX_TOPGUN_LCD_HEIGHT, GDI_COLOR_BLACK);

#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    gdi_image_draw_id(MMI_GX_TOPGUN_SCORE_X, MMI_GX_TOPGUN_INFO_Y, IMG_ID_GX_TOPGUN_SCORE);
    gdi_image_draw_id(MMI_GX_TOPGUN_ENERGY_X, MMI_GX_TOPGUN_INFO_Y, IMG_ID_GX_TOPGUN_ENERGY);
#else   /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */
    gdi_image_draw_id(
        MMI_GX_TOPGUN_SCORE_X,
        MMI_GX_TOPGUN_INFO_Y,
        mmi_gfx_get_multilanguage_image_ID(
            mmi_topgun_language_index,
            IMG_ID_GX_TOPGUN_LEVEL_CLEAR_LANGUAGE0,
            MMI_TOPGUN_STRING_COUNT,
            MMI_TOPGUN_STRING_SCORE));
    gdi_image_draw_id(
        MMI_GX_TOPGUN_ENERGY_X,
        MMI_GX_TOPGUN_INFO_Y,
        mmi_gfx_get_multilanguage_image_ID(
            mmi_topgun_language_index,
            IMG_ID_GX_TOPGUN_LEVEL_CLEAR_LANGUAGE0,
            MMI_TOPGUN_STRING_COUNT,
            MMI_TOPGUN_STRING_ENERGY));
#endif /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

    mmi_gx_topgun_draw_background();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_draw_score
 * DESCRIPTION
 *  Draw score values
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_draw_score(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 tmp_digit;
    S16 tmp_grade;
    S16 position_x;
    U8 i;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    position_x = MMI_GX_TOPGUN_SCORE_TEXT_X - MMI_GX_TOPGUN_DIGIT_WIDTH;

    gdi_layer_push_and_set_clip(MMI_GX_TOPGUN_SCORE_TEXT_X1, MMI_GX_TOPGUN_INFO_Y, MMI_GX_TOPGUN_SCORE_TEXT_X, MMI_GX_TOPGUN_INFO_HEIGHT);
    gdi_draw_solid_rect(MMI_GX_TOPGUN_SCORE_TEXT_X1, MMI_GX_TOPGUN_INFO_Y, MMI_GX_TOPGUN_SCORE_TEXT_X, MMI_GX_TOPGUN_INFO_HEIGHT, GDI_COLOR_TRANSPARENT);
    tmp_grade = g_gx_topgun_context.game_grade;
    
    for (i = 0; i < MMI_GX_TOPGUN_MAX_SCORE_DIGIT; i++)
    {
        tmp_digit = tmp_grade % 10;
        tmp_grade = tmp_grade / 10;
        gdi_image_draw_id(position_x, MMI_GX_TOPGUN_INFO_Y, IMG_ID_GX_TOPGUN_DIGIT_0 + tmp_digit);
        position_x = position_x - MMI_GX_TOPGUN_DIGIT_WIDTH;
    }
    
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_draw_energy
 * DESCRIPTION
 *  Draw energy status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_draw_energy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 position_x;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    position_x = MMI_GX_TOPGUN_ENERGY_TEXT_X;
    
    gdi_layer_push_and_set_clip(MMI_GX_TOPGUN_ENERGY_TEXT_X, MMI_GX_TOPGUN_INFO_Y, LCD_WIDTH, MMI_GX_TOPGUN_INFO_HEIGHT);
    gdi_draw_solid_rect(
        MMI_GX_TOPGUN_ENERGY_TEXT_X, MMI_GX_TOPGUN_INFO_Y, LCD_WIDTH, MMI_GX_TOPGUN_INFO_HEIGHT, GDI_COLOR_TRANSPARENT);

    for (i = 0; i < g_gx_topgun_context.energy; i++)
    {
        gdi_image_draw_id(position_x, MMI_GX_TOPGUN_INFO_Y, IMG_ID_GX_TOPGUN_ENERGY_UNIT);
        position_x = position_x + MMI_GX_TOPGUN_ENERGY_UNIT_WIDTH + 1;
    }

    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_exit_game
 * DESCRIPTION
 *  Exit Game [Callback required by GFX]
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_exit_game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_gx_topgun_cyclic_timer);  /* cancle the looping timer */

    gdi_layer_free(g_gx_topgun_context.foreground);
    gdi_layer_multi_layer_disable();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_init_game
 * DESCRIPTION
 *  Game initilization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_init_game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init game */

    g_gx_topgun_context.up_key_pressed = MMI_FALSE;
    g_gx_topgun_context.down_key_pressed = MMI_FALSE;
    g_gx_topgun_context.left_key_pressed = MMI_FALSE;
    g_gx_topgun_context.right_key_pressed = MMI_FALSE;

    g_gx_topgun_context.tick = 0;
    g_gx_topgun_context.stage_ending_time = 0;
    g_gx_topgun_context.stage_count = 1;
    g_gx_topgun_context.game_grade = 0;
    g_gx_topgun_context.energy = MMI_GX_TOPGUN_ENERGY_UNIT_COUNT;

    g_gx_topgun_context.fighter_position.x = MMI_GX_TOPGUN_FIGHTER_INIT_X;
    g_gx_topgun_context.fighter_position.y = MMI_GX_TOPGUN_LCD_HEIGHT - MMI_GX_TOPGUN_ROLE_HEIGHT;
    g_gx_topgun_context.fighter_old_position.x = g_gx_topgun_context.fighter_position.x;
    g_gx_topgun_context.fighter_old_position.y = g_gx_topgun_context.fighter_position.y;
    g_gx_topgun_context.fighter_invincible = 0;
    g_gx_topgun_context.fighter_state = MMI_GX_TOPGUN_NORMAL_STATE;

    g_gx_topgun_context.is_treasure_on = MMI_FALSE;
    g_gx_topgun_context.is_boss_on = MMI_FALSE;

    g_gx_topgun_context.enemy_pattern_number = 0;
    g_gx_topgun_context.enemy_model = &(g_gx_topgun_context.enemy_model_memory[0]);

    g_gx_topgun_context.fighter_weapon = MMI_GX_TOPGUN_BULLET_1;
    mmi_gx_topgun_init_bullet_list();
    mmi_gx_topgun_init_enemy_list();
    mmi_gx_topgun_init_enemy_bullet_list();

    g_gx_topgun_context.boss_appearing_time = MMI_GX_TOPGUN_BOSS_APPEAR_TIME;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_init_enemy_list
 * DESCRIPTION
 *  Initialization of the enemies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_init_enemy_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_gx_topgun_context.enemy, 0, sizeof(gx_topgun_enemy_struct)*MMI_GX_TOPGUN_ENEMY_COUNT);
    for (i = 0; i < MMI_GX_TOPGUN_ENEMY_COUNT - 1; i++)
    {
        g_gx_topgun_context.enemy[i].next = &(g_gx_topgun_context.enemy[i + 1]);
    }

    for (i = 1; i < MMI_GX_TOPGUN_ENEMY_COUNT; i++)
    {
        g_gx_topgun_context.enemy[i].previous = &(g_gx_topgun_context.enemy[i - 1]);
    }

    g_gx_topgun_context.first_enemy = NULL;
    g_gx_topgun_context.last_enemy = NULL;
    g_gx_topgun_context.first_empty_enemy_list = &(g_gx_topgun_context.enemy[0]);
    g_gx_topgun_context.last_empty_enemy_list = &(g_gx_topgun_context.enemy[MMI_GX_TOPGUN_ENEMY_COUNT - 1]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_init_enemy_bullet_list
 * DESCRIPTION
 *  Initialization of the bullet list of enemies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_init_enemy_bullet_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_gx_topgun_context.enemy_bullet, 0, sizeof(gx_topgun_enemy_bullet_struct)*MMI_GX_TOPGUN_ENEMY_BULLET_COUNT);
    for (i = 0; i < MMI_GX_TOPGUN_ENEMY_BULLET_COUNT - 1; i++)
    {
        g_gx_topgun_context.enemy_bullet[i].next = &(g_gx_topgun_context.enemy_bullet[i + 1]);
    }

    for (i = 1; i < MMI_GX_TOPGUN_ENEMY_BULLET_COUNT; i++)
    {
        g_gx_topgun_context.enemy_bullet[i].previous = &(g_gx_topgun_context.enemy_bullet[i - 1]);
    }

    g_gx_topgun_context.first_enemy_bullet = NULL;
    g_gx_topgun_context.last_enemy_bullet = NULL;
    g_gx_topgun_context.first_empty_enemy_bullet_list = &(g_gx_topgun_context.enemy_bullet[0]);
    g_gx_topgun_context.last_empty_enemy_bullet_list = &(g_gx_topgun_context.enemy_bullet[MMI_GX_TOPGUN_ENEMY_BULLET_COUNT - 1]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_init_bullet_list
 * DESCRIPTION
 *  Initialization of the bullet list of the fighter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_init_bullet_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_gx_topgun_context.bullet, 0, sizeof(gx_topgun_bullet_struct)*MMI_GX_TOPGUN_BULLET_COUNT);
    for (i = 0; i < MMI_GX_TOPGUN_BULLET_COUNT - 1; i++)
    {
        g_gx_topgun_context.bullet[i].next = &(g_gx_topgun_context.bullet[i + 1]);
    }

    for (i = 1; i < MMI_GX_TOPGUN_BULLET_COUNT; i++)
    {
        g_gx_topgun_context.bullet[i].previous = &(g_gx_topgun_context.bullet[i - 1]);
    }

    g_gx_topgun_context.first_bullet = NULL;
    g_gx_topgun_context.last_bullet = NULL;
    g_gx_topgun_context.first_empty_bullet_list = &(g_gx_topgun_context.bullet[0]);
    g_gx_topgun_context.last_empty_bullet_list = &(g_gx_topgun_context.bullet[MMI_GX_TOPGUN_BULLET_COUNT - 1]);

    mmi_gx_topgun_new_fighter_bullet();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_get_bullet_position_x
 * DESCRIPTION
 *  Initialization of bullet position in x direction
 * PARAMETERS
 *  type        [IN]        Bullet type
 * RETURNS
 *  x position of the bullet
 *****************************************************************************/
U8 mmi_gx_topgun_get_bullet_position_x(U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == MMI_GX_TOPGUN_BULLET_1)
    {
        return g_gx_topgun_context.fighter_position.x + MMI_GX_TOPGUN_ROLE_WIDTH / 2 - MMI_GX_TOPGUN_BULLET_WIDTH / 2;
    }
    else if (type == MMI_GX_TOPGUN_BULLET_2)
    {
        return g_gx_topgun_context.fighter_position.x + MMI_GX_TOPGUN_ROLE_WIDTH / 2 - MMI_GX_TOPGUN_BULLET_WIDTH;
    }
    else if (type == MMI_GX_TOPGUN_BULLET_3)
    {
        return g_gx_topgun_context.fighter_position.x + MMI_GX_TOPGUN_ROLE_WIDTH / 2 - 3 * MMI_GX_TOPGUN_BULLET_WIDTH / 2;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_get_bullet_position_y
 * DESCRIPTION
 *  Initialization of bullet position in y direction
 * PARAMETERS
 *  void
 * RETURNS
 *  y position of the bullet
 *****************************************************************************/
S16 mmi_gx_topgun_get_bullet_position_y(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_gx_topgun_context.fighter_position.y - MMI_GX_TOPGUN_BULLET_HEIGHT;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_draw_background
 * DESCRIPTION
 *  Draw background
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_draw_background(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_clip(0, MMI_GX_TOPGUN_ORIGIN, MMI_GX_TOPGUN_LCD_WIDTH - 1, MMI_GX_TOPGUN_LCD_HEIGHT - 1);
    gdi_image_draw_id(0, 0, IMG_ID_GX_TOPGUN_BACKGROUND);    
    
    gdi_layer_pop_clip(); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_framemove
 * DESCRIPTION
 *  Framemove - process the game logic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_framemove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gx_topgun_bullet_struct *bullet;
    gx_topgun_enemy_struct *enemy;
    gx_topgun_enemy_bullet_struct *enemy_bullet;
    S16 offset_x;
    S16 offset_y;
    S16 tmp;
    S16 enemy_width;
    S16 enemy_height;
    U8 image_offset;
    MMI_BOOL need_point_next = MMI_TRUE;  //while removed, no need to point to next

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_gx_topgun_context.is_boss_on != MMI_TRUE)
    {
        enemy_width = MMI_GX_TOPGUN_ENEMY_WIDTH;
        enemy_height = MMI_GX_TOPGUN_ENEMY_HEIGHT;
    }
    else
    {
        enemy_width = MMI_GX_TOPGUN_BOSS_WIDTH;
        enemy_height = MMI_GX_TOPGUN_BOSS_HEIGHT;
    }

    g_gx_topgun_context.audio_to_play = TOPGUN_OFF;

    /* check if there should be a treasure for every 14 seconds */
    if ((g_gx_topgun_context.tick + 1) % 140 == 0)
    {
        g_gx_topgun_context.is_treasure_on = MMI_TRUE;
        g_gx_topgun_context.treasure_type = mmi_gx_topgun_get_treasure_type();
        g_gx_topgun_context.treasure_position.x = rand() % (MMI_GX_TOPGUN_LCD_WIDTH - MMI_GX_TOPGUN_TREASURE_WIDTH);
        g_gx_topgun_context.treasure_position.y = -MMI_GX_TOPGUN_ORIGIN;
        g_gx_topgun_context.treasure_old_position.x = g_gx_topgun_context.treasure_position.x;
        g_gx_topgun_context.treasure_old_position.y = g_gx_topgun_context.treasure_position.y;
    }

    /* update the position of the treasure */
    if (g_gx_topgun_context.is_treasure_on != MMI_FALSE)
    {
        g_gx_topgun_context.treasure_old_position.y = g_gx_topgun_context.treasure_position.y;
        g_gx_topgun_context.treasure_position.y = g_gx_topgun_context.treasure_position.y + MMI_GX_TOPGUN_TREASURE_SPEED;

        /* if the treasure is going out of the screen, disable it */
        if (g_gx_topgun_context.treasure_position.y > MMI_GX_TOPGUN_LCD_HEIGHT + 2 * MMI_GX_TOPGUN_TREASURE_HEIGHT)
        {
            g_gx_topgun_context.is_treasure_on = MMI_FALSE;
        }
    }

    /* determine the position of the fighter */
#ifdef __MMI_TOUCH_SCREEN__
    if (g_gx_topgun_context.is_pen_hit)
    {
        mmi_gx_topgun_update_fighter_position_by_pen();
    }
    else
#endif
    {
        mmi_gx_topgun_update_fighter_position_by_key();
    }

    /* determine if the fighter takes the treasure */
    if (g_gx_topgun_context.is_treasure_on != MMI_FALSE &&
        (g_gx_topgun_context.fighter_state == MMI_GX_TOPGUN_NORMAL_STATE ||
         g_gx_topgun_context.fighter_state == MMI_GX_TOPGUN_HIT_STATE))
    {
        if ((g_gx_topgun_context.treasure_position.x >= g_gx_topgun_context.fighter_position.x &&
             g_gx_topgun_context.treasure_position.x < g_gx_topgun_context.fighter_position.x + MMI_GX_TOPGUN_ROLE_WIDTH &&
             g_gx_topgun_context.treasure_position.y >= g_gx_topgun_context.fighter_position.y &&
             g_gx_topgun_context.treasure_position.y < g_gx_topgun_context.fighter_position.y + MMI_GX_TOPGUN_ROLE_HEIGHT) ||
            (g_gx_topgun_context.treasure_position.x + MMI_GX_TOPGUN_TREASURE_WIDTH - 1 >= g_gx_topgun_context.fighter_position.x
             && g_gx_topgun_context.treasure_position.x + MMI_GX_TOPGUN_TREASURE_WIDTH - 1 <
             g_gx_topgun_context.fighter_position.x + MMI_GX_TOPGUN_ROLE_WIDTH &&
             g_gx_topgun_context.treasure_position.y >= g_gx_topgun_context.fighter_position.y &&
             g_gx_topgun_context.treasure_position.y < g_gx_topgun_context.fighter_position.y + MMI_GX_TOPGUN_ROLE_HEIGHT) ||
            (g_gx_topgun_context.treasure_position.x >= g_gx_topgun_context.fighter_position.x &&
             g_gx_topgun_context.treasure_position.x < g_gx_topgun_context.fighter_position.x + MMI_GX_TOPGUN_ROLE_WIDTH &&
             g_gx_topgun_context.treasure_position.y + MMI_GX_TOPGUN_TREASURE_HEIGHT - 1 >=
             g_gx_topgun_context.fighter_position.y &&
             g_gx_topgun_context.treasure_position.y + MMI_GX_TOPGUN_TREASURE_HEIGHT - 1 <
             g_gx_topgun_context.fighter_position.y + MMI_GX_TOPGUN_ROLE_HEIGHT) ||
            (g_gx_topgun_context.treasure_position.x + MMI_GX_TOPGUN_TREASURE_WIDTH - 1 >= g_gx_topgun_context.fighter_position.x
             && g_gx_topgun_context.treasure_position.x + MMI_GX_TOPGUN_TREASURE_WIDTH - 1 <
             g_gx_topgun_context.fighter_position.x + MMI_GX_TOPGUN_ROLE_WIDTH &&
             g_gx_topgun_context.treasure_position.y + MMI_GX_TOPGUN_TREASURE_HEIGHT - 1 >=
             g_gx_topgun_context.fighter_position.y &&
             g_gx_topgun_context.treasure_position.y + MMI_GX_TOPGUN_TREASURE_HEIGHT - 1 <
             g_gx_topgun_context.fighter_position.y + MMI_GX_TOPGUN_ROLE_HEIGHT))
        {

            g_gx_topgun_context.audio_to_play = TOPGUN_EAT;

            g_gx_topgun_context.is_treasure_on = MMI_FALSE;
            /* show the effect of this treasure */
            /* if it's a energy filling treasure */
            if (g_gx_topgun_context.treasure_type == MMI_GX_TOPGUN_ENERGY_TREASURE)
            {
                g_gx_topgun_context.energy = g_gx_topgun_context.energy + 1;
                /* the maximum of the fighter energy is MMI_GX_TOPGUN_ENERGY_UNIT_COUNT */
                if (g_gx_topgun_context.energy > MMI_GX_TOPGUN_ENERGY_UNIT_COUNT)
                {
                    g_gx_topgun_context.energy = MMI_GX_TOPGUN_ENERGY_UNIT_COUNT;
                }
            }
            /* if it's a weapon treasure */
            else if (g_gx_topgun_context.treasure_type == MMI_GX_TOPGUN_WEAPON_TREASURE)
            {
                /* increase the weapon */
                g_gx_topgun_context.fighter_weapon = g_gx_topgun_context.fighter_weapon + 1;
                /* the weapon is in BULLET_3 at most */
                if (g_gx_topgun_context.fighter_weapon > MMI_GX_TOPGUN_BULLET_3)
                {
                    g_gx_topgun_context.fighter_weapon = MMI_GX_TOPGUN_BULLET_3;
                }
            }
            /* if it's a bomb treasure */
            else if (g_gx_topgun_context.treasure_type == MMI_GX_TOPGUN_BOMB_TREASURE)
            {
                /* make all enemy's life become 0 */
                for (enemy = g_gx_topgun_context.first_enemy;
                     enemy != NULL && enemy != g_gx_topgun_context.first_empty_enemy_list; enemy = enemy->next)
                {

                    if (g_gx_topgun_context.audio_to_play < TOPGUN_EXPLODING)
                    {
                        g_gx_topgun_context.audio_to_play = TOPGUN_EXPLODING;
                    }

                    enemy->life = 0;
                    enemy->state = MMI_GX_TOPGUN_HIT_STATE;
                    /* increase the score */
                    g_gx_topgun_context.game_grade = mmi_gfx_cal_grade(g_gx_topgun_context.game_grade, MMI_GX_TOPGUN_ENEMY_SCORE);
                }
            }
            /* if it's a invincible treasure */
            else if (g_gx_topgun_context.treasure_type == MMI_GX_TOPGUN_INVINCIBLE_TREASURE)
            {
                g_gx_topgun_context.fighter_state = MMI_GX_TOPGUN_HIT_STATE;
                g_gx_topgun_context.is_invisible = MMI_TRUE;
                g_gx_topgun_context.fighter_invincible = MMI_GX_TOPGUN_INVINCIBLE_INTERVAL;
            }
        }
    }

    /* update positions of bullets */
    for (bullet = g_gx_topgun_context.first_bullet; bullet != NULL && bullet != g_gx_topgun_context.first_empty_bullet_list; 
        (bullet = need_point_next ? bullet->next : bullet))
    {
        need_point_next = MMI_TRUE;
        bullet->old_y = bullet->y;
        bullet->y = bullet->y - MMI_GX_TOPGUN_BULLET_SPEED;
        /* if the bullet is going out of the boundary, remove it back to the empty bullet list */
        if (bullet->old_y + MMI_GX_TOPGUN_BULLET_HEIGHT < MMI_GX_TOPGUN_ORIGIN - 2 * MMI_GX_TOPGUN_BULLET_HEIGHT)
        {
            gx_topgun_bullet_struct *tmp = bullet->next;
            need_point_next = MMI_FALSE;
            mmi_gx_topgun_remove_bullet_from_list(bullet);
            bullet = tmp;
        }
    }

    /* update positions of bullets of enemies */
    for (enemy_bullet = g_gx_topgun_context.first_enemy_bullet;
         enemy_bullet != NULL && enemy_bullet != g_gx_topgun_context.first_empty_enemy_bullet_list; 
         (enemy_bullet = need_point_next ? enemy_bullet->next : enemy_bullet))
    {
        need_point_next = MMI_TRUE;
        enemy_bullet->old_x = enemy_bullet->x;
        enemy_bullet->old_y = enemy_bullet->y;
        enemy_bullet->x = enemy_bullet->x + enemy_bullet->vector_x;
        enemy_bullet->y = enemy_bullet->y + enemy_bullet->vector_y;

        /* if the enemy bullet is going out of the boundary, remove it back to the empty list */
        if (enemy_bullet->old_x < -MMI_GX_TOPGUN_ENEMY_BULLET_WIDTH || enemy_bullet->old_x > MMI_GX_TOPGUN_LCD_WIDTH ||
            enemy_bullet->old_y < MMI_GX_TOPGUN_ORIGIN - MMI_GX_TOPGUN_ENEMY_BULLET_HEIGHT || enemy_bullet->old_y > MMI_GX_TOPGUN_LCD_HEIGHT)
        {
            gx_topgun_enemy_bullet_struct *tmp = enemy_bullet->next;
            need_point_next = MMI_FALSE;
            mmi_gx_topgun_remove_enemy_bullet_from_list(enemy_bullet);
            enemy_bullet = tmp;
            continue;
        }

        /* check if the bullet hit the fighter */
        if ((g_gx_topgun_context.fighter_state == MMI_GX_TOPGUN_NORMAL_STATE) && ((enemy_bullet->x >=
                                                                             g_gx_topgun_context.fighter_position.x &&
                                                                             enemy_bullet->x <
                                                                             g_gx_topgun_context.fighter_position.x +
                                                                             MMI_GX_TOPGUN_ROLE_WIDTH &&
                                                                             enemy_bullet->y >=
                                                                             g_gx_topgun_context.fighter_position.y &&
                                                                             enemy_bullet->y <
                                                                             g_gx_topgun_context.fighter_position.y +
                                                                             MMI_GX_TOPGUN_ROLE_HEIGHT) ||
                                                                            (enemy_bullet->x + MMI_GX_TOPGUN_ENEMY_BULLET_WIDTH -
                                                                             1 >= g_gx_topgun_context.fighter_position.x &&
                                                                             enemy_bullet->x + MMI_GX_TOPGUN_ENEMY_BULLET_WIDTH -
                                                                             1 <
                                                                             g_gx_topgun_context.fighter_position.x +
                                                                             MMI_GX_TOPGUN_ROLE_WIDTH &&
                                                                             enemy_bullet->y >=
                                                                             g_gx_topgun_context.fighter_position.y &&
                                                                             enemy_bullet->y <
                                                                             g_gx_topgun_context.fighter_position.y +
                                                                             MMI_GX_TOPGUN_ROLE_HEIGHT) ||
                                                                            (enemy_bullet->x >=
                                                                             g_gx_topgun_context.fighter_position.x &&
                                                                             enemy_bullet->x <
                                                                             g_gx_topgun_context.fighter_position.x +
                                                                             MMI_GX_TOPGUN_ROLE_WIDTH &&
                                                                             enemy_bullet->y +
                                                                             MMI_GX_TOPGUN_ENEMY_BULLET_HEIGHT - 1 >=
                                                                             g_gx_topgun_context.fighter_position.y &&
                                                                             enemy_bullet->y +
                                                                             MMI_GX_TOPGUN_ENEMY_BULLET_HEIGHT - 1 <
                                                                             g_gx_topgun_context.fighter_position.y +
                                                                             MMI_GX_TOPGUN_ROLE_HEIGHT) ||
                                                                            (enemy_bullet->x + MMI_GX_TOPGUN_ENEMY_BULLET_WIDTH -
                                                                             1 >= g_gx_topgun_context.fighter_position.x &&
                                                                             enemy_bullet->x + MMI_GX_TOPGUN_ENEMY_BULLET_WIDTH -
                                                                             1 <
                                                                             g_gx_topgun_context.fighter_position.x +
                                                                             MMI_GX_TOPGUN_ROLE_WIDTH &&
                                                                             enemy_bullet->y +
                                                                             MMI_GX_TOPGUN_ENEMY_BULLET_HEIGHT - 1 >=
                                                                             g_gx_topgun_context.fighter_position.y &&
                                                                             enemy_bullet->y +
                                                                             MMI_GX_TOPGUN_ENEMY_BULLET_HEIGHT - 1 <
                                                                             g_gx_topgun_context.fighter_position.y +
                                                                             MMI_GX_TOPGUN_ROLE_HEIGHT)))
        {
            gx_topgun_enemy_bullet_struct *tmp = enemy_bullet->next;
            need_point_next = MMI_FALSE;
            GFX_PLAY_VIBRATION();
            g_gx_topgun_context.energy = g_gx_topgun_context.energy - 1;
            mmi_gx_topgun_remove_enemy_bullet_from_list(enemy_bullet);
            enemy_bullet = tmp;
            /* when the energy > 0, the fighter is still alive */
            if (g_gx_topgun_context.energy != 0)
            {
                if (g_gx_topgun_context.audio_to_play < TOPGUN_HIT)
                {
                    g_gx_topgun_context.audio_to_play = TOPGUN_HIT;
                }

                g_gx_topgun_context.fighter_state = MMI_GX_TOPGUN_HIT_STATE;
                g_gx_topgun_context.fighter_invincible = MMI_GX_TOPGUN_INVINCIBLE_INTERVAL;
            }
            /* when the energy is 0, the fighter is going to exploding */
            else
            {
                g_gx_topgun_context.fighter_state = MMI_GX_TOPGUN_EXPLODING_STATE_1;

                if (g_gx_topgun_context.audio_to_play < TOPGUN_EXPLODING)
                {
                    g_gx_topgun_context.audio_to_play = TOPGUN_EXPLODING;
                }
            }
        }
    }

    /* update positions of enemies */
    for (enemy = g_gx_topgun_context.first_enemy; enemy != NULL && enemy != g_gx_topgun_context.first_empty_enemy_list;
         (enemy = need_point_next ? enemy->next : enemy))
    {
        need_point_next = MMI_TRUE;
        image_offset = enemy->image_offset;
        enemy->old_x = enemy->x;
        enemy->old_y = enemy->y;
        mmi_gx_topgun_update_enemy_vector(enemy);
        enemy->x = enemy->x + enemy->vector_x;
        enemy->y = enemy->y + enemy->vector_y;
        /* if the enemy is going out of the boundary, remove it back to the empty list */
        if (enemy->old_x < -enemy_width || enemy->old_x > MMI_GX_TOPGUN_LCD_WIDTH ||
            enemy->old_y < MMI_GX_TOPGUN_ORIGIN - enemy_height || enemy->old_y > MMI_GX_TOPGUN_LCD_HEIGHT)
        {
            /* if it's a normal enemy */
            if (g_gx_topgun_context.is_boss_on != MMI_TRUE)
            {
                gx_topgun_enemy_struct *tmp = enemy->next;
                need_point_next = MMI_FALSE;
                mmi_gx_topgun_remove_enemy_from_list(enemy);
                enemy = tmp;
            }
            /* when the enemy is a boss, reset it's move type instead of removing it from the list */
            else
            {
                enemy->move_type = rand() % MMI_GX_TOPGUN_MOVE_TYPE_COUNT;
                if (g_gx_topgun_context.last_enemy->move_type == MMI_GX_TOPGUN_MOVE_TYPE_4)
                {
                    g_gx_topgun_context.last_enemy->vector_x = 4;
                }
                else if (g_gx_topgun_context.last_enemy->move_type == MMI_GX_TOPGUN_MOVE_TYPE_5)
                {
                    g_gx_topgun_context.last_enemy->vector_x = -4;
                }
                g_gx_topgun_context.last_enemy->starting_time = g_gx_topgun_context.tick;
                g_gx_topgun_context.last_enemy->x = mmi_gx_topgun_get_enemy_position_x(g_gx_topgun_context.last_enemy->move_type);
                g_gx_topgun_context.last_enemy->y = 0;
                g_gx_topgun_context.last_enemy->state = MMI_GX_TOPGUN_NORMAL_STATE;
            }
            continue;
        }
        /* when the enemy is shot by the bullet(s) of the fighter, it will get hurts or explode */
        for (bullet = g_gx_topgun_context.first_bullet;
             enemy->state == MMI_GX_TOPGUN_NORMAL_STATE && bullet != NULL && bullet != g_gx_topgun_context.first_empty_bullet_list;
             (bullet = need_point_next ? bullet->next : bullet))
        {
            need_point_next = MMI_TRUE;
            if ((bullet->x >= enemy->x && bullet->x < enemy->x + enemy_width && bullet->y >= enemy->y &&
                 bullet->y < enemy->y + enemy_height) || (bullet->x + bullet->type * MMI_GX_TOPGUN_BULLET_WIDTH - 1 >= enemy->x &&
                                                     bullet->x + bullet->type * MMI_GX_TOPGUN_BULLET_WIDTH - 1 <
                                                     enemy->x + enemy_width && bullet->y >= enemy->y &&
                                                     bullet->y < enemy->y + enemy_height) || (bullet->x >= enemy->x &&
                                                                                         bullet->x < enemy->x + enemy_width
                                                                                         && bullet->y +
                                                                                         MMI_GX_TOPGUN_BULLET_HEIGHT - 1 >=
                                                                                         enemy->y &&
                                                                                         bullet->y +
                                                                                         MMI_GX_TOPGUN_BULLET_HEIGHT - 1 <
                                                                                         enemy->y + enemy_height) ||
                (bullet->x + bullet->type * MMI_GX_TOPGUN_BULLET_WIDTH - 1 >= enemy->x &&
                 bullet->x + bullet->type * MMI_GX_TOPGUN_BULLET_WIDTH - 1 < enemy->x + enemy_width &&
                 bullet->y + MMI_GX_TOPGUN_BULLET_HEIGHT - 1 >= enemy->y &&
                 bullet->y + MMI_GX_TOPGUN_BULLET_HEIGHT - 1 < enemy->y + enemy_height))
            {
                gx_topgun_bullet_struct *tmp = bullet->next;
                need_point_next = MMI_FALSE;
                enemy->life -= bullet->type;
                enemy->state = MMI_GX_TOPGUN_HIT_STATE;
                mmi_gx_topgun_remove_bullet_from_list(bullet);
                bullet = tmp;
                /* increase the score for killing one enemy */
                if (enemy->life <= 0)
                {
                    if (g_gx_topgun_context.audio_to_play < TOPGUN_EXPLODING)
                    {
                        g_gx_topgun_context.audio_to_play = TOPGUN_EXPLODING;
                    }

                    if (g_gx_topgun_context.is_boss_on != MMI_TRUE)
                    {
                        g_gx_topgun_context.game_grade = mmi_gfx_cal_grade(g_gx_topgun_context.game_grade, MMI_GX_TOPGUN_ENEMY_SCORE);
                    }
                    /* the score of the boss is 15 times more than a normal enemy */
                    else
                    {
                        g_gx_topgun_context.game_grade = mmi_gfx_cal_grade(g_gx_topgun_context.game_grade, 15 * MMI_GX_TOPGUN_ENEMY_SCORE);
                    }
                }
                else
                {
                    if (g_gx_topgun_context.audio_to_play < TOPGUN_HIT)
                    {
                        g_gx_topgun_context.audio_to_play = TOPGUN_HIT;
                    }
                }
            }
        }

        /* check if the fighter touched the enemy */
        if (((g_gx_topgun_context.is_boss_on != MMI_TRUE) &&
             ((g_gx_topgun_context.fighter_state == MMI_GX_TOPGUN_NORMAL_STATE) &&
              ((enemy->x >= g_gx_topgun_context.fighter_position.x &&
                enemy->x < g_gx_topgun_context.fighter_position.x + MMI_GX_TOPGUN_ROLE_WIDTH &&
                enemy->y >= g_gx_topgun_context.fighter_position.y &&
                enemy->y < g_gx_topgun_context.fighter_position.y + MMI_GX_TOPGUN_ROLE_HEIGHT) ||
               (enemy->x + MMI_GX_TOPGUN_ENEMY_WIDTH - 1 >= g_gx_topgun_context.fighter_position.x &&
                enemy->x + MMI_GX_TOPGUN_ENEMY_WIDTH - 1 < g_gx_topgun_context.fighter_position.x + MMI_GX_TOPGUN_ROLE_WIDTH &&
                enemy->y >= g_gx_topgun_context.fighter_position.y &&
                enemy->y < g_gx_topgun_context.fighter_position.y + MMI_GX_TOPGUN_ROLE_HEIGHT) ||
               (enemy->x >= g_gx_topgun_context.fighter_position.x &&
                enemy->x < g_gx_topgun_context.fighter_position.x + MMI_GX_TOPGUN_ROLE_WIDTH &&
                enemy->y + MMI_GX_TOPGUN_ENEMY_HEIGHT - 1 >= g_gx_topgun_context.fighter_position.y &&
                enemy->y + MMI_GX_TOPGUN_ENEMY_HEIGHT - 1 < g_gx_topgun_context.fighter_position.y + MMI_GX_TOPGUN_ROLE_HEIGHT)
               || (enemy->x + MMI_GX_TOPGUN_ENEMY_WIDTH - 1 >= g_gx_topgun_context.fighter_position.x &&
                   enemy->x + MMI_GX_TOPGUN_ENEMY_WIDTH - 1 < g_gx_topgun_context.fighter_position.x + MMI_GX_TOPGUN_ROLE_WIDTH
                   && enemy->y + MMI_GX_TOPGUN_ENEMY_HEIGHT - 1 >= g_gx_topgun_context.fighter_position.y &&
                   enemy->y + MMI_GX_TOPGUN_ENEMY_HEIGHT - 1 <
                   g_gx_topgun_context.fighter_position.y + MMI_GX_TOPGUN_ROLE_HEIGHT)))) ||
            ((g_gx_topgun_context.is_boss_on != MMI_FALSE) &&
             ((g_gx_topgun_context.fighter_state == MMI_GX_TOPGUN_NORMAL_STATE) &&
              ((g_gx_topgun_context.fighter_position.x >= enemy->x &&
                g_gx_topgun_context.fighter_position.x < enemy->x + enemy_width &&
                g_gx_topgun_context.fighter_position.y >= enemy->y &&
                g_gx_topgun_context.fighter_position.y < enemy->y + enemy_height) ||
               (g_gx_topgun_context.fighter_position.x + MMI_GX_TOPGUN_ROLE_WIDTH - 1 >= enemy->x &&
                g_gx_topgun_context.fighter_position.x + MMI_GX_TOPGUN_ROLE_WIDTH - 1 < enemy->x + enemy_width &&
                g_gx_topgun_context.fighter_position.y >= enemy->y &&
                g_gx_topgun_context.fighter_position.y < enemy->y + enemy_height) ||
               (g_gx_topgun_context.fighter_position.x >= enemy->x &&
                g_gx_topgun_context.fighter_position.x < enemy->x + enemy_width &&
                g_gx_topgun_context.fighter_position.y + MMI_GX_TOPGUN_ROLE_HEIGHT - 1 >= enemy->y &&
                g_gx_topgun_context.fighter_position.y + MMI_GX_TOPGUN_ROLE_HEIGHT - 1 < enemy->y + enemy_height) ||
               (g_gx_topgun_context.fighter_position.x + MMI_GX_TOPGUN_ROLE_WIDTH - 1 >= enemy->x &&
                g_gx_topgun_context.fighter_position.x + MMI_GX_TOPGUN_ROLE_WIDTH - 1 < enemy->x + enemy_width &&
                g_gx_topgun_context.fighter_position.y + MMI_GX_TOPGUN_ROLE_HEIGHT - 1 >= enemy->y &&
                g_gx_topgun_context.fighter_position.y + MMI_GX_TOPGUN_ROLE_HEIGHT - 1 < enemy->y + enemy_height)))))
        {
            if (g_gx_topgun_context.audio_to_play < TOPGUN_HIT)
            {
                g_gx_topgun_context.audio_to_play = TOPGUN_HIT;
            }

            GFX_PLAY_VIBRATION();
            g_gx_topgun_context.energy = g_gx_topgun_context.energy - 1;
            /* when the energy > 0, the fighter is still alive */
            if (g_gx_topgun_context.energy != 0)
            {
                g_gx_topgun_context.fighter_state = MMI_GX_TOPGUN_HIT_STATE;
                g_gx_topgun_context.fighter_invincible = MMI_GX_TOPGUN_INVINCIBLE_INTERVAL;
            }
            /* when the energy is 0, the fighter is going to exploding */
            else
            {
                if (g_gx_topgun_context.audio_to_play < TOPGUN_EXPLODING)
                {
                    g_gx_topgun_context.audio_to_play = TOPGUN_EXPLODING;
                }

                g_gx_topgun_context.fighter_state = MMI_GX_TOPGUN_EXPLODING_STATE_1;
            }
        }

        /* if the enemy is exploding, it will not shoot */
        if (enemy->state != MMI_GX_TOPGUN_NORMAL_STATE)
        {
            continue;
        }
        /* if the attack type of the enemy is in type 1, it will not shoot */
        if (enemy->attack_type == MMI_GX_TOPGUN_ATTACK_TYPE_1)
        {
            continue;
        }

        /* set up the data of bullets of the enemy */
        /* the number of bullets one enemy can shoot is at most 3 */
        if (g_gx_topgun_context.is_boss_on != MMI_TRUE &&
            ((g_gx_topgun_context.tick - enemy->starting_time) % (20 + (rand() % 3)) == 0))
        {
            /* new() a new bullt of enemy */
            mmi_gx_topgun_new_enemy_bullet(enemy);
        }
        /* when the enemy is the boss, it will shoot for every 0.4~0.6 seconds */
        else if (g_gx_topgun_context.is_boss_on != MMI_FALSE &&
                 ((g_gx_topgun_context.tick - enemy->starting_time) % (4 + (rand() % 3)) == 0))
        {
            mmi_gx_topgun_new_enemy_bullet(enemy);
        }
    }

    /* new() a new bullet for every MMI_GX_TOPGUN_BULLET_INTERVAL */
    if ((g_gx_topgun_context.tick + 1) % MMI_GX_TOPGUN_BULLET_INTERVAL == 0 &&
        (g_gx_topgun_context.fighter_state == MMI_GX_TOPGUN_NORMAL_STATE ||
         g_gx_topgun_context.fighter_state == MMI_GX_TOPGUN_HIT_STATE))
    {
        mmi_gx_topgun_new_fighter_bullet();
        if (g_gx_topgun_context.audio_to_play < TOPGUN_SHOOT)
        {
            g_gx_topgun_context.audio_to_play = TOPGUN_SHOOT;
        }
    }

    /* new() a new enemy for every MMI_GX_TOPGUN_ENEMY_INTERVAL (for the first 120 seconds, all enemies are normal enemies) */
    if ((g_gx_topgun_context.tick + 1) % MMI_GX_TOPGUN_ENEMY_INTERVAL == 0 &&
        (g_gx_topgun_context.tick < MMI_GX_TOPGUN_STAGE_INTERVAL * 4))
    {
        mmi_gx_topgun_new_enemy();
    }
    /* after 127 seconds, the boss appears */
    else if ((g_gx_topgun_context.tick > g_gx_topgun_context.boss_appearing_time) && (g_gx_topgun_context.is_boss_on != MMI_TRUE) &&
             (g_gx_topgun_context.tick < g_gx_topgun_context.boss_appearing_time + 2))
    {
        /* make sure that all enemies are out of screen */
        if (g_gx_topgun_context.first_enemy != NULL &&
            g_gx_topgun_context.first_enemy != g_gx_topgun_context.first_empty_enemy_list)
        {
            /* or the appearing of the boss will be delayed for 0.1 sec */
            g_gx_topgun_context.boss_appearing_time = g_gx_topgun_context.boss_appearing_time + 1;
        }
        /* when there are no enemies, the boss is appearing */
        else
        {
            g_gx_topgun_context.is_boss_on = MMI_TRUE;
            mmi_gx_topgun_new_enemy();
        }
    }

    switch (g_gx_topgun_context.audio_to_play)
    {
        case TOPGUN_HIT:
            GFX_PLAY_AUDIO_DVI(TopGunHit_dvi, TOPGUNHIT_DVI, DEVICE_AUDIO_PLAY_ONCE);
            break;
        case TOPGUN_EXPLODING:
            GFX_PLAY_AUDIO_DVI(TopGunExplode_dvi, TOPGUNEXPLODE_DVI, DEVICE_AUDIO_PLAY_ONCE);
            break;
        case TOPGUN_SHOOT:
            GFX_PLAY_AUDIO_DVI(TopGunShoot_dvi, TOPGUNSHOOT_DVI, DEVICE_AUDIO_PLAY_ONCE);
            break;
        case TOPGUN_EAT:
            GFX_PLAY_AUDIO_DVI(TopGunEat_dvi, TOPGUNEAT_DVI, DEVICE_AUDIO_PLAY_ONCE);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_render
 * DESCRIPTION
 *  Render the game images
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_render(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gx_topgun_bullet_struct *bullet;
    gx_topgun_enemy_struct *enemy;
    gx_topgun_enemy_bullet_struct *enemy_bullet;
    U8 i = 0;
    MMI_ID_TYPE image_type = IMG_ID_GX_TOPGUN_ENERGY_FILL;
    MMI_BOOL need_point_next = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* avoid redrawing the screen */
    if (g_gx_topgun_context.is_gameover != MMI_FALSE)
    {
        return;
    }

    gdi_layer_push_and_set_active(g_gx_topgun_context.foreground);
    gdi_layer_push_and_set_clip(0, MMI_GX_TOPGUN_ORIGIN, MMI_GX_TOPGUN_LCD_WIDTH - 1, MMI_GX_TOPGUN_LCD_HEIGHT - 1);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);

    mmi_gx_topgun_draw_score();
    mmi_gx_topgun_draw_energy();

    /* draw the treasure if there is one */
    if (g_gx_topgun_context.is_treasure_on != MMI_FALSE)
    {
        /* determine the type of the image */
        if (g_gx_topgun_context.treasure_type == MMI_GX_TOPGUN_ENERGY_TREASURE)
        {
            image_type = IMG_ID_GX_TOPGUN_ENERGY_FILL;
        }
        else if (g_gx_topgun_context.treasure_type == MMI_GX_TOPGUN_WEAPON_TREASURE)
        {
            image_type = IMG_ID_GX_TOPGUN_WEAPON;
        }
        else if (g_gx_topgun_context.treasure_type == MMI_GX_TOPGUN_BOMB_TREASURE)
        {
            image_type = IMG_ID_GX_TOPGUN_BOMB;
        }
        else if (g_gx_topgun_context.treasure_type == MMI_GX_TOPGUN_INVINCIBLE_TREASURE)
        {
            image_type = IMG_ID_GX_TOPGUN_INVINCIBLE;
        }
        gdi_image_draw_id(
            g_gx_topgun_context.treasure_position.x,
            g_gx_topgun_context.treasure_position.y,
            (U16) (image_type));
    }
    /* draw enemies */

    for (enemy = g_gx_topgun_context.first_enemy; enemy != NULL && enemy != g_gx_topgun_context.first_empty_enemy_list;
         (enemy = need_point_next ? enemy->next : enemy))
    {
        need_point_next = MMI_TRUE;
        
        if (enemy->state == MMI_GX_TOPGUN_NORMAL_STATE)
        {
            gdi_image_draw_id(enemy->x, enemy->y, (U16) (IMG_ID_GX_TOPGUN_ENEMY_1 + enemy->image_offset));
        }
        /* the enemy is shot or exploding */
        else
        {
            /* the enemy is simply shot */
            if (enemy->life > 0)
            {
                //flash enemy when it is hit
                if (g_gx_topgun_context.tick % 2 == 0)
                {                
                    gdi_image_draw_id(enemy->x, enemy->y, (U16) (IMG_ID_GX_TOPGUN_ENEMY_1 + enemy->image_offset));
                }
                enemy->state = MMI_GX_TOPGUN_NORMAL_STATE;
            }
            /* it is exploding */
            else
            {
                /* exploding frame 1 */
                if (enemy->state == MMI_GX_TOPGUN_HIT_STATE)
                {
                    gdi_image_draw_id(enemy->x, enemy->y, IMG_ID_GX_TOPGUN_FLAME_1);
                    enemy->state = MMI_GX_TOPGUN_EXPLODING_STATE_1;
                    mmi_gx_topgun_draw_score();
                }
                /* exploding frame 2 */
                else if (enemy->state == MMI_GX_TOPGUN_EXPLODING_STATE_1)
                {
                    gdi_image_draw_id(enemy->x, enemy->y, IMG_ID_GX_TOPGUN_FLAME_2);
                    enemy->state = MMI_GX_TOPGUN_EXPLODING_STATE_2;
                }
                /* exploding frame 3 */
                else if (enemy->state == MMI_GX_TOPGUN_EXPLODING_STATE_2)
                {
                    gdi_image_draw_id(enemy->x, enemy->y, IMG_ID_GX_TOPGUN_FLAME_3);
                    enemy->state = MMI_GX_TOPGUN_EXPLODING_STATE_3;
                }
                /* remove the enemy from list */
                else if (enemy->state == MMI_GX_TOPGUN_EXPLODING_STATE_3)
                {
                    gx_topgun_enemy_struct *tmp = enemy->next;
                    mmi_gx_topgun_remove_enemy_from_list(enemy);
                    /* after the boss is killed, return to the normal stage */
                    if (g_gx_topgun_context.is_boss_on != MMI_FALSE)
                    {
                        g_gx_topgun_context.is_boss_on = MMI_FALSE;
                        g_gx_topgun_context.stage_ending_time = g_gx_topgun_context.tick;
                    }
                    else
                    {
                        need_point_next = MMI_FALSE;
                        enemy = tmp;
                    }
                }
            }
        }
    }
    
    /* draw enemy bullets */
    for (enemy_bullet = g_gx_topgun_context.first_enemy_bullet;
         enemy_bullet != NULL && enemy_bullet != g_gx_topgun_context.first_empty_enemy_bullet_list;
         enemy_bullet = enemy_bullet->next)
    {
        gdi_image_draw_id(
            enemy_bullet->x,
            enemy_bullet->y,
            (U16) (IMG_ID_GX_TOPGUN_ENEMY_BULLET_1 + enemy_bullet->image_offset));
    }
    /* draw the fighter */
    /* in normal state */
    if (g_gx_topgun_context.fighter_state == MMI_GX_TOPGUN_NORMAL_STATE)
    {
        gdi_image_draw_id(g_gx_topgun_context.fighter_position.x, g_gx_topgun_context.fighter_position.y, IMG_ID_GX_TOPGUN_ROLE);
    }
    /* the fighter is exploding or shot */
    else
    {
        /* if the fighter is simply shot */
        if (g_gx_topgun_context.fighter_state == MMI_GX_TOPGUN_HIT_STATE)
        {
            /* when the fighter is shot, re-draw the energy bar */
            if (g_gx_topgun_context.fighter_invincible == MMI_GX_TOPGUN_INVINCIBLE_INTERVAL)
            {
                mmi_gx_topgun_draw_energy();
                /* restore the weapon of the fighter back to 1 */
                if (g_gx_topgun_context.is_invisible == MMI_FALSE)
                {
                    g_gx_topgun_context.fighter_weapon = MMI_GX_TOPGUN_BULLET_1;
                }
            }

            g_gx_topgun_context.fighter_invincible = g_gx_topgun_context.fighter_invincible - 1;
            /* when the invincible state is over, restore the fighter to normal state */
            if (g_gx_topgun_context.fighter_invincible == 0)
            {
                g_gx_topgun_context.fighter_state = MMI_GX_TOPGUN_NORMAL_STATE;
                g_gx_topgun_context.is_invisible = MMI_FALSE;
            }
            /* flashing image when the fighter is in invincible state */
            if (g_gx_topgun_context.tick % 2 == 0 && g_gx_topgun_context.fighter_invincible != MMI_GX_TOPGUN_INVINCIBLE_INTERVAL)
            {
                gdi_image_draw_id(
                    g_gx_topgun_context.fighter_position.x,
                    g_gx_topgun_context.fighter_position.y,
                    IMG_ID_GX_TOPGUN_ROLE);
            }
        }
        /* if the fighter is exploding */
        else
        {
            /* explosion frame 1 */
            if (g_gx_topgun_context.fighter_state == MMI_GX_TOPGUN_EXPLODING_STATE_1)
            {
                mmi_gx_topgun_draw_energy();
                gdi_image_draw_id(
                    g_gx_topgun_context.fighter_position.x,
                    g_gx_topgun_context.fighter_position.y,
                    IMG_ID_GX_TOPGUN_FLAME_1);
                g_gx_topgun_context.fighter_state = MMI_GX_TOPGUN_EXPLODING_STATE_2;
                g_gx_topgun_context.fighter_dying_time = g_gx_topgun_context.tick;
            }
            /* explosion frame 2 */
            else if (g_gx_topgun_context.fighter_state == MMI_GX_TOPGUN_EXPLODING_STATE_2)
            {
                gdi_image_draw_id(
                    g_gx_topgun_context.fighter_position.x,
                    g_gx_topgun_context.fighter_position.y,
                    IMG_ID_GX_TOPGUN_FLAME_2);
                g_gx_topgun_context.fighter_state = MMI_GX_TOPGUN_EXPLODING_STATE_3;
            }
            /* explosion frame 3 */
            else if (g_gx_topgun_context.fighter_state == MMI_GX_TOPGUN_EXPLODING_STATE_3)
            {
                gdi_image_draw_id(
                    g_gx_topgun_context.fighter_position.x,
                    g_gx_topgun_context.fighter_position.y,
                    IMG_ID_GX_TOPGUN_FLAME_3);
                g_gx_topgun_context.fighter_state = MMI_GX_TOPGUN_EXPLODING_STATE_END;
            }
            /* explosion end, draw nothing about the fighter */
            else if (g_gx_topgun_context.fighter_state == MMI_GX_TOPGUN_EXPLODING_STATE_END)
            {
                /* DO NOTHING */
            }
        }
    }
    /* draw bullets of the fighter */
    for (bullet = g_gx_topgun_context.first_bullet; bullet != NULL && bullet != g_gx_topgun_context.first_empty_bullet_list;
         bullet = bullet->next)
    {
        for (i = 0; i < bullet->type; i++)
        {
            gdi_image_draw_id(bullet->x + i * MMI_GX_TOPGUN_BULLET_WIDTH, bullet->y, IMG_ID_GX_TOPGUN_ROLE_BULLET);
        }
    }

    /* draw LEVEL_CLRAE string */
    if (g_gx_topgun_context.stage_ending_time > 0)
    {
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
        gdi_image_draw_id(MMI_GX_TOPGUN_LEVEL_CLEAR_X, MMI_GX_TOPGUN_LEVEL_CLEAR_Y, IMG_ID_GX_TOPGUN_LEVEL_CLEAR);
#else   /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */
        gdi_image_draw_id(
            MMI_GX_TOPGUN_LEVEL_CLEAR_X,
            MMI_GX_TOPGUN_LEVEL_CLEAR_Y,
            mmi_gfx_get_multilanguage_image_ID(
                mmi_topgun_language_index,
                IMG_ID_GX_TOPGUN_LEVEL_CLEAR_LANGUAGE0,
                MMI_TOPGUN_STRING_COUNT,
                MMI_TOPGUN_STRING_LEVEL_CLEAR));
#endif /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

        /* reset all states after 5 seconds after the ending */
        if (g_gx_topgun_context.tick - g_gx_topgun_context.stage_ending_time > 50)
        {
            gdi_draw_solid_rect(
                MMI_GX_TOPGUN_LEVEL_CLEAR_X,
                MMI_GX_TOPGUN_LEVEL_CLEAR_Y,
                MMI_GX_TOPGUN_LEVEL_CLEAR_X + MMI_GX_TOPGUN_LEVEL_CLEAR_WIDTH,
                MMI_GX_TOPGUN_LEVEL_CLEAR_Y + MMI_GX_TOPGUN_LEVEL_CLEAR_HEIGHT,
                GDI_COLOR_TRANSPARENT);
            g_gx_topgun_context.stage_count = g_gx_topgun_context.stage_count + 1;
            mmi_gx_topgun_reset_status();
        }
    }

    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();

    gdi_layer_blt(
        g_gx_topgun_context.background,    /* layer 0 */
        g_gx_topgun_context.foreground,    /* layer 1 */
        0,                              /* layer 2 */
        0,                              /* layer 3 */
        0,                              /* offset x */
        0,                              /* offset y */
        MMI_GX_TOPGUN_LCD_WIDTH - 1,       /* width */
        MMI_GX_TOPGUN_LCD_HEIGHT - 1);     /* height */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_update_enemy_vector
 * DESCRIPTION
 *  Update the moving vector of the enemy according to its type
 * PARAMETERS
 *  enemy       [?]     The enemy to be updated
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_update_enemy_vector(gx_topgun_enemy_struct *enemy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 horizontal_interval;
    U8 y_velocity;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_gx_topgun_context.is_boss_on != MMI_TRUE)
    {
        y_velocity = MMI_GX_TOPGUN_ENEMY_VELOCITY_Y;
    }
    else
    {
        y_velocity = MMI_GX_TOPGUN_BOSS_VELOCITY_Y;
    }

    /* if the enemy is not alive, it should be exploding. Thus the moving vector should be identical to the background */
    if (enemy->life <= 0)
    {
        enemy->vector_x = 0;
        enemy->vector_y = MMI_GX_TOPGUN_BACKGROUND_SPEED;
        return;
    }

    /* when the enemy is alive */
    if (enemy->move_type == MMI_GX_TOPGUN_MOVE_TYPE_1)
    {
        enemy->vector_x = 0;
        enemy->vector_y = y_velocity;
    }
    else if (enemy->move_type == MMI_GX_TOPGUN_MOVE_TYPE_2)
    {
        enemy->vector_x = MMI_GX_TOPGUN_ENEMY_VELOCITY_X;
        enemy->vector_y = y_velocity;
    }
    else if (enemy->move_type == MMI_GX_TOPGUN_MOVE_TYPE_3)
    {
        enemy->vector_x = -MMI_GX_TOPGUN_ENEMY_VELOCITY_X;
        enemy->vector_y = y_velocity;
    }
    else if (enemy->move_type == MMI_GX_TOPGUN_MOVE_TYPE_4)
    {
        enemy->vector_y = y_velocity;
        if (enemy->x + enemy->vector_x > MMI_GX_TOPGUN_LCD_WIDTH - MMI_GX_TOPGUN_ENEMY_WIDTH ||
            enemy->x + enemy->vector_x < 0)
        {
            enemy->vector_x = -enemy->vector_x;
        }
    }
    else if (enemy->move_type == MMI_GX_TOPGUN_MOVE_TYPE_5)
    {
        enemy->vector_y = y_velocity;
        if (enemy->x + enemy->vector_x > MMI_GX_TOPGUN_LCD_WIDTH - MMI_GX_TOPGUN_ENEMY_WIDTH ||
            enemy->x + enemy->vector_x < 0)
        {
            enemy->vector_x = -enemy->vector_x;
        }
    }
    else if (enemy->move_type == MMI_GX_TOPGUN_MOVE_TYPE_6)
    {
        horizontal_interval = rand() % MMI_GX_TOPGUN_ENEMY_HORIZONTAL_INTERVAL_FACTOR;

        if (g_gx_topgun_context.tick - enemy->starting_time < MMI_GX_TOPGUN_MOVE_TYPE_6_REVERT_TIME_MIN + horizontal_interval)
        {
            enemy->vector_x = 0;
            enemy->vector_y = y_velocity;
        }
        else if (g_gx_topgun_context.tick - enemy->starting_time > MMI_GX_TOPGUN_MOVE_TYPE_6_REVERT_TIME_MAX + horizontal_interval)
        {
            enemy->vector_x = 0;
            enemy->vector_y = -y_velocity;
        }
        else
        {
            enemy->vector_y = 0;
            enemy->vector_x = y_velocity;
        }
    }
    else if (enemy->move_type == MMI_GX_TOPGUN_MOVE_TYPE_7)
    {
        horizontal_interval = rand() % 10;

        if (g_gx_topgun_context.tick - enemy->starting_time < MMI_GX_TOPGUN_MOVE_TYPE_7_REVERT_TIME_MIN + horizontal_interval)
        {
            enemy->vector_x = 0;
            enemy->vector_y = y_velocity;
        }
        else if (g_gx_topgun_context.tick - enemy->starting_time > MMI_GX_TOPGUN_MOVE_TYPE_7_REVERT_TIME_MAX + horizontal_interval)
        {
            enemy->vector_x = 0;
            enemy->vector_y = -y_velocity;
        }
        else
        {
            enemy->vector_y = 0;
            enemy->vector_x = -y_velocity;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_get_enemy_position_x
 * DESCRIPTION
 *  Initialization of enemy position in x direction
 * PARAMETERS
 *  type        [IN]        The moving type of the enemy
 * RETURNS
 *  the position of enemy in x direction
 *****************************************************************************/
U8 mmi_gx_topgun_get_enemy_position_x(U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 enemy_width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_gx_topgun_context.is_boss_on == MMI_TRUE)
    {
        enemy_width = MMI_GX_TOPGUN_BOSS_WIDTH;
    }
    else
    {
        enemy_width = MMI_GX_TOPGUN_ENEMY_WIDTH;
    }

    switch (type)
    {
        case MMI_GX_TOPGUN_MOVE_TYPE_1:
            return rand() % (MMI_GX_TOPGUN_LCD_WIDTH - enemy_width);
        case MMI_GX_TOPGUN_MOVE_TYPE_2:
            return rand() % (MMI_GX_TOPGUN_LCD_WIDTH / 2 - enemy_width);
        case MMI_GX_TOPGUN_MOVE_TYPE_3:
            return (rand() % (MMI_GX_TOPGUN_LCD_WIDTH / 2 - enemy_width)) + MMI_GX_TOPGUN_LCD_WIDTH / 2;
        case MMI_GX_TOPGUN_MOVE_TYPE_4:
            return rand() % (MMI_GX_TOPGUN_LCD_WIDTH / 2 - enemy_width);
        case MMI_GX_TOPGUN_MOVE_TYPE_5:
            return (rand() % (MMI_GX_TOPGUN_LCD_WIDTH / 2 - enemy_width)) + MMI_GX_TOPGUN_LCD_WIDTH / 2;
        case MMI_GX_TOPGUN_MOVE_TYPE_6:
            return rand() % (MMI_GX_TOPGUN_LCD_WIDTH / 2 - enemy_width);
        case MMI_GX_TOPGUN_MOVE_TYPE_7:
            return (rand() % (MMI_GX_TOPGUN_LCD_WIDTH / 2 - enemy_width)) + MMI_GX_TOPGUN_LCD_WIDTH / 2;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_gameover
 * DESCRIPTION
 *  Gameover function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_gameover(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gx_topgun_context.is_gameover = MMI_TRUE;
    g_gx_topgun_context.is_new_game = MMI_TRUE;
    /* call this function to draw gameover screen */
    mmi_gfx_entry_gameover_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_cyclic_timer
 * DESCRIPTION
 *  Timer trigger function - looping
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_cyclic_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gx_topgun_context.tick = g_gx_topgun_context.tick + 1;

    gui_start_timer(g_gx_topgun_context.timer_elapse, mmi_gx_topgun_cyclic_timer);

    if (g_gx_topgun_context.is_gameover == MMI_FALSE)
    {
        mmi_gx_topgun_framemove();
        mmi_gx_topgun_render();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_key_2_press
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_key_2_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gx_topgun_context.up_key_pressed = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_key_2_release
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_key_2_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gx_topgun_context.up_key_pressed = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_key_4_press
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_key_4_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gx_topgun_context.left_key_pressed = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_key_4_release
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_key_4_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gx_topgun_context.left_key_pressed = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_key_6_press
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_key_6_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gx_topgun_context.right_key_pressed = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_key_6_release
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_key_6_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gx_topgun_context.right_key_pressed = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_key_8_press
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_key_8_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gx_topgun_context.down_key_pressed = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_key_8_release
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_key_8_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gx_topgun_context.down_key_pressed = MMI_FALSE;
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_pen_down_hdlr
 * DESCRIPTION
 *  pen down event handler
 * PARAMETERS
 *  pos     [IN]        Position of pen
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_gx_topgun_context.is_gameover)
    {
        return;
    }
    
    if (pos.x >= g_gx_topgun_context.fighter_position.x && pos.x <= g_gx_topgun_context.fighter_position.x + MMI_GX_TOPGUN_ROLE_WIDTH &&
        pos.y >= g_gx_topgun_context.fighter_position.y && pos.y <= g_gx_topgun_context.fighter_position.y + MMI_GX_TOPGUN_ROLE_HEIGHT)
    {
        g_gx_topgun_context.is_pen_hit = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_pen_up_hdlr
 * DESCRIPTION
 *  pen up event handler
 * PARAMETERS
 *  pos     [IN]        Position of pen
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gx_topgun_context.is_pen_hit = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_topgun_pen_move_hdlr
 * DESCRIPTION
 *  pen move event handler
 * PARAMETERS
 *  pos     [IN]        Position of pen
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_topgun_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_gx_topgun_context.is_gameover)
    {
        return;
    }
    
    if (g_gx_topgun_context.is_pen_hit)
    {
        g_gx_topgun_context.fighter_old_position.x = g_gx_topgun_context.fighter_position.x;
        g_gx_topgun_context.fighter_old_position.y = g_gx_topgun_context.fighter_position.y;
        g_gx_topgun_context.fighter_position.x = pos.x - MMI_GX_TOPGUN_ROLE_WIDTH/2;
        g_gx_topgun_context.fighter_position.y = pos.y - MMI_GX_TOPGUN_ROLE_HEIGHT/2;
        
        if (g_gx_topgun_context.fighter_position.x < 0)
            g_gx_topgun_context.fighter_position.x = 0;
        else if (g_gx_topgun_context.fighter_position.x > MMI_GX_TOPGUN_LCD_WIDTH - MMI_GX_TOPGUN_ROLE_WIDTH)
            g_gx_topgun_context.fighter_position.x = MMI_GX_TOPGUN_LCD_WIDTH - MMI_GX_TOPGUN_ROLE_WIDTH;
            
        if (g_gx_topgun_context.fighter_position.y < 0)
            g_gx_topgun_context.fighter_position.y = 0;
        else if (g_gx_topgun_context.fighter_position.y > MMI_GX_TOPGUN_LCD_HEIGHT - MMI_GX_TOPGUN_ROLE_HEIGHT)
            g_gx_topgun_context.fighter_position.y = MMI_GX_TOPGUN_LCD_HEIGHT - MMI_GX_TOPGUN_ROLE_HEIGHT;
    }
}
#endif  //__MMI_TOUCH_SCREEN__

#endif  //__MMI_GAME_TOPGUN__ 

