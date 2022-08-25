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
 *  ColorBalls.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  ColorBall game
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"

#include "GameDefs.h"

#ifdef __MMI_GAME_COLORBALLS__
#include "GameInc.h"
#include "mmi_rp_app_games_def.h"
#include "ColorBallsProts.h"

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__      //added for multi-language
#include "GameProts.h"
#endif
    
/************************************************************************/
/* Game Defines                                                         */
/************************************************************************/
#define MAX_FALLING_BALLS           4
#define MAX_RUNNNING_BULLETS        6
#define SCORE_CHNAGE_LEVEL          300
#define COLORBALL_TIMER             400
#define BULLET_COUNT                10
#define DROP_BALL_COUNT             24
#define DEFAULT_LAUCHER_POSITION    2
#define DEFAULT_BULLET_BALL         4
#define TOTAL_BALL_TYPE             4
#define COLORBALL_LEVELS            3
#define DEFAULT_LANUCHER_Y          120
#define GAME_INTERMIDATE_LEVELS     5
#define INTERMIDATE_SPEED_INCREASE  10
#define MINIMUM_CB_TIMER            30
#define MAXIMUM_CB_ENERGY           6
#define BULLET_TIMER                30

/************************************************************************/
/* Structure / Enum                                                     */
/************************************************************************/
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
//added for multi-language support
typedef enum
{
    MMI_COLORBALL_STRING_LEVEL = 0,
    MMI_COLORBALL_STRING_GRADE,
    MMI_COLORBALL_STRING_ENERGY,
    MMI_COLORBALL_STRING_GAMEOVER,
    MMI_COLORBALL_STRING_TOTAL
}mmi_colorball_string_enum;
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

typedef struct
{
    S32 cb_height;
    S32 cb_width;
    U8 cb_score;
    PU8 cb_image;
} CB_FALLING_BALL_STRUCT;

typedef struct
{
    U8 ballType;
    S16 X;
    S16 Y;
    bitmap bgBuffer;
} CB_RUNNING_BALL_STRUCT;

typedef enum
{
    BIG_BLUE_BALL = 0,
    BIG_GREEN_BALL,
    BIG_LIGHT_BALL,
    BIG_PINK_BALL,
    SMALL_BLUE_BALL,
    SMALL_GREEN_BALL,
    SMALL_LIGHT_BALL,
    SMALL_PINK_BALL,
    TOTAL_COLORBALLS    /* Dont Remove This Keeping The Count */
} COLORBALLS_OBJECT;

/************************************************************************/
/* Golbal Varable [Const]                                   */
/************************************************************************/
static const U16 cb_game_speed_level[COLORBALL_LEVELS][GAME_INTERMIDATE_LEVELS] = 
{
    {COLORBALL_TIMER, COLORBALL_TIMER - 50, COLORBALL_TIMER - 100, COLORBALL_TIMER - 150, COLORBALL_TIMER - 200},       /* 250, 200, 150, 100, 50 */
    {COLORBALL_TIMER - 100, COLORBALL_TIMER - 100 - 25, COLORBALL_TIMER - 100 - 50, COLORBALL_TIMER - 100 - 75, COLORBALL_TIMER - 100 - 100},   /* 150, 125, 100, 75,  50 */
    {COLORBALL_TIMER - 150, COLORBALL_TIMER - 150 - 10, COLORBALL_TIMER - 150 - 20, COLORBALL_TIMER - 150 - 30, COLORBALL_TIMER - 150 - 40}     /* 100,  90,  80, 70,  60 */
};

static const U8 cb_launcher_move_x[4] = {6, 26, 46, 66};

static const U16 cb_img_id_array[TOTAL_BALL_TYPE * 2] = 
{
    IMG_GX_COLORBALLS_BIG_BLUE, IMG_GX_COLORBALLS_BIG_GREEN,
    IMG_GX_COLORBALLS_BIG_LIGHT, IMG_GX_COLORBALLS_BIG_PINK,
    IMG_GX_COLORBALLS_SMALL_BLUE, IMG_GX_COLORBALLS_SMALL_GREEN,
    IMG_GX_COLORBALLS_SMALL_LIGHT, IMG_GX_COLORBALLS_SMALL_PINK
};

/************************************************************************/
/* Audio [Const]                                         */
/************************************************************************/
#define COLORBALLSHOOTSIZE    122
#define COLORBALLHITGOOD      108
#define COLORBALLHITBAD       173

__align(2)
     const U8 colorBallShoot[122] = 
     {
         0x4D, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01, 0x03, 0xC0, 0x4D, 0x54, 0x72,
         0x6B, 0x00, 0x00, 0x00, 0x64, 0x00, 0xFF, 0x02, 0x16, 0x43, 0x6F, 0x70, 0x79, 0x72, 0x69, 0x67,
         0x68, 0x74, 0x20, 0x63, 0x20, 0x32, 0x30, 0x30, 0x33, 0x20, 0x62, 0x79, 0x20, 0x43, 0x43, 0x00,
         0xFF, 0x01, 0x02, 0x43, 0x43, 0x00, 0xFF, 0x58, 0x04, 0x04, 0x02, 0x18, 0x08, 0x00, 0xFF, 0x59,
         0x02, 0x00, 0x00, 0x00, 0xFF, 0x51, 0x03, 0x03, 0xA9, 0x80, 0x00, 0xC0, 0x77, 0x00, 0xB0, 0x07,
         0x74, 0x00, 0x90, 0x3C, 0x7E, 0x00, 0xC1, 0x78, 0x00, 0xB1, 0x07, 0x62, 0x00, 0x91, 0x3E, 0x6F,
         0x00, 0x3C, 0x7D, 0x00, 0x3B, 0x6F, 0x87, 0x40, 0x3B, 0x00, 0x00, 0x90, 0x3C, 0x00, 0x00, 0x91,
         0x3E, 0x00, 0x00, 0x3C, 0x00, 0x00, 0xFF, 0x2F, 0x00
     };

__align(2)
     const U8 colorBallHitGood[108] = 
     {
         0x4D, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01, 0x03, 0xC0, 0x4D, 0x54, 0x72,
         0x6B, 0x00, 0x00, 0x00, 0x56, 0x00, 0xFF, 0x02, 0x16, 0x43, 0x6F, 0x70, 0x79, 0x72, 0x69, 0x67,
         0x68, 0x74, 0x20, 0x63, 0x20, 0x32, 0x30, 0x30, 0x33, 0x20, 0x62, 0x79, 0x20, 0x43, 0x43, 0x00,
         0xFF, 0x01, 0x02, 0x43, 0x43, 0x00, 0xFF, 0x58, 0x04, 0x04, 0x02, 0x18, 0x08, 0x00, 0xFF, 0x59,
         0x02, 0x00, 0x00, 0x00, 0xFF, 0x51, 0x03, 0x09, 0x27, 0xC0, 0x00, 0xC0, 0x09, 0x00, 0x90, 0x59,
         0x64, 0x00, 0x51, 0x64, 0x05, 0x54, 0x64, 0x00, 0x4D, 0x64, 0x83, 0x5B, 0x51, 0x00, 0x00, 0x59,
         0x00, 0x05, 0x54, 0x00, 0x00, 0x4D, 0x00, 0x00, 0xFF, 0x2F, 0x00
     };

__align(2)
     const U8 colorBallHitBad[173] = 
     {
         0x4D, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01, 0x03, 0xC0, 0x4D, 0x54, 0x72,
         0x6B, 0x00, 0x00, 0x00, 0x97, 0x00, 0xFF, 0x03, 0x08, 0x75, 0x6E, 0x74, 0x69, 0x74, 0x6C, 0x65,
         0x64, 0x00, 0xFF, 0x02, 0x16, 0x43, 0x6F, 0x70, 0x79, 0x72, 0x69, 0x67, 0x68, 0x74, 0x20, 0x63,
         0x20, 0x32, 0x30, 0x30, 0x33, 0x20, 0x62, 0x79, 0x20, 0x43, 0x43, 0x00, 0xFF, 0x01, 0x03, 0x43,
         0x43, 0x0A, 0x00, 0xFF, 0x58, 0x04, 0x04, 0x02, 0x18, 0x08, 0x00, 0xFF, 0x59, 0x02, 0x00, 0x00,
         0x00, 0xFF, 0x51, 0x03, 0x09, 0x27, 0xC0, 0x00, 0xC0, 0x7F, 0x00, 0xB0, 0x07, 0x64, 0x00, 0x90,
         0x5D, 0x6F, 0x00, 0x5B, 0x6F, 0x00, 0x59, 0x67, 0x00, 0x58, 0x5A, 0x00, 0xB9, 0x07, 0x50, 0x00,
         0x99, 0x26, 0x5A, 0x78, 0x27, 0x7D, 0x28, 0x90, 0x5D, 0x27, 0x00, 0x5B, 0x27, 0x00, 0x59, 0x25,
         0x00, 0x58, 0x20, 0x83, 0x38, 0x99, 0x27, 0x00, 0x82, 0x68, 0x90, 0x58, 0x00, 0x00, 0x5D, 0x00,
         0x00, 0x59, 0x00, 0x00, 0x99, 0x26, 0x00, 0x00, 0x90, 0x5B, 0x00, 0x81, 0x20, 0x59, 0x00, 0x00,
         0x58, 0x00, 0x00, 0x5D, 0x00, 0x00, 0x5B, 0x00, 0x00, 0xFF, 0x2F, 0x00
     };

 /********************************************AUDIO*********************************************/

/************************************************************************/
/* Golbal Varable [258 Byte]                                */
/************************************************************************/
static U16 cb_timer_elapse;
static BOOL cb_is_new_game = TRUE;
static BOOL cb_is_change_bullet = FALSE;
static BOOL cb_is_change_opp_color = FALSE;
static BOOL cb_is_fire_bullet = FALSE;
static BOOL cb_is_launcher_right = FALSE;
static BOOL cb_is_launcher_left = FALSE;
static BOOL cb_is_bullet_on_launcher = FALSE;
static U8 cb_is_gameover = FALSE;

static U8 cb_remain_drop_ball = DROP_BALL_COUNT;
static U8 cb_launcher_movement = DEFAULT_LAUCHER_POSITION;

static U8 cb_cur_bullet_color = DEFAULT_BULLET_BALL;
static S16 cb_game_grade = 0;
static U8 cb_colorball_setting = 0; /* difficulty */
static U8 cb_cur_game_level = 0;
static U8 cb_game_energy = 0;

/* memory taking elements - 168 byte */
static CB_FALLING_BALL_STRUCT *cb_falling_ball_ptr[TOTAL_COLORBALLS];
static CB_FALLING_BALL_STRUCT cb_launcher;              /* 6 Byte */
static CB_RUNNING_BALL_STRUCT cb_runtime_falling_ball[MAX_FALLING_BALLS];       /* 20*4 Byte */
static CB_RUNNING_BALL_STRUCT cb_runtime_bullet[MAX_RUNNNING_BULLETS];  /* 20*6 Byte */
static CB_RUNNING_BALL_STRUCT cb_bullet_on_launcher;    /* 20 Byte */
static CB_RUNNING_BALL_STRUCT cb_runtime_launcher;      /* 20 Byte */

 #if defined (__MMI_GAME_MULTICHANNEL_SOUND__)
S32 shoot_midi;
S32 hitgood_midi;
S32 hitbad_midi;

 #endif /* defined (__MMI_GAME_MULTICHANNEL_SOUND__) */ 

#ifdef  __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ /*added for game multi-language*/
static const mmi_game_point_struct mmi_colorball_multi_language_string[] = 
    {{84, 6}, {84, 35}, {84, 64}};
static U16 mmi_colorBall_language_index;
#define MMI_COLORBALL_STRING_COUNT MMI_COLORBALL_STRING_TOTAL
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */


/************************************************************************/
/* Function Declare                                      */
/************************************************************************/
/* Game framework related functions */
void ColorBalls_Draw_GameOver(void);
void ColorBalls_Enter_Game(void);
void ColorBalls_Exit_Game(void);
S16 ColorBalls_Calc_Best_Grade(S16 old_grade, S16 new_grade);

/* Game play functions */
void ColorBalls_Enter_Resume_Game(void);
void ColorBalls_Enter_New_Game(void);
void ColorBalls_Init_Objects(void);
void ColorBalls_Init(void);
void ColorBalls_Clear_All_Res(void);
void ColorBalls_Set_Game_Level(void);
void ColorBalls_Init_Default_Value(void);
void ColorBalls_Init_Bit_Buffer(void);
void ColorBalls_Draw_Background(void);
void ColorBalls_Draw_Launcher(void);
void ColorBalls_Draw_Bullet_On_Launcher(void);
void ColorBalls_Init_Key_Handler(void);
void ColorBalls_Draw_Level(void);
void ColorBalls_Draw_Grade(void);
void ColorBalls_Draw_Energy(void);
void ColorBalls_Get_BG_Buffer_On_Resume(void);
void ColorBalls_Bullet_Callback(void);
void ColorBalls_Start(void);
void ColorBalls_Game_End(void);
void ColorBalls_Key_Change_Bullet_Color(void);
void ColorBalls_Key_Change_Opp_Color(void);
void ColorBalls_Key_Fire_Bullet(void);
void ColorBalls_Key_Move_Laucher_Rigth(void);
void ColorBalls_Key_Move_Laucher_Left(void);
void ColorBalls_Check_Unperfect_Collision(void);
void ColorBalls_Check_Collision(void);
void ColorBalls_New_Bullet(void);
void ColorBalls_Gen_Dropping_Ball(void);
void ColorBalls_Update_Status(U8 i, U8 j);
void ColorBalls_Change_Level(void);

extern void _show_bitmap(S32 x1, S32 y1, bitmap *b);
extern void _get_bitmap(S32 x1, S32 y1, S32 x2, S32 y2, bitmap *b);

#ifdef  __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ /*added for game multi-language*/
void mmi_colorball_show_level_grade_power_image(void);
#endif  

/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Enter_GFX
 * DESCRIPTION
 *  Set Game Framework (GFX) Parameter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Enter_GFX(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Game menu */
    GFX.game_data.game_img_id = IMG_GX_COLORBALLS_GAME_ICON;    /* game icon img ID */
    GFX.game_data.game_str_id = STR_GX_COLORBALLS_GAME_NAME;    /* game name string ID */
    GFX.game_data.menu_resume_str_id = STR_GAME_RESUME; /* "Resume" string ID */
    GFX.game_data.menu_new_str_id = STR_GAME_NEW;       /* "New Game" string ID */
    GFX.game_data.menu_level_str_id = STR_GAME_LEVEL;   /* "Game Level" string ID */
    GFX.game_data.menu_grade_str_id = STR_GAME_GRADE;   /* "Best Grade" string ID */
    GFX.game_data.menu_help_str_id = STR_GLOBAL_HELP;     /* "Game Help string ID */

    /* level / grade */
    GFX.game_data.level_count = 3;  /* how many levels */
    GFX.game_data.level_str_id_list[0] = STR_GX_COLORBALLS_EASY;        /* level string ID */
    GFX.game_data.level_str_id_list[1] = STR_GX_COLORBALLS_NORMAL;      /* level string ID */
    GFX.game_data.level_str_id_list[2] = STR_GX_COLORBALLS_HARD;        /* level string ID */

    GFX.game_data.grade_nvram_id_list[0] = NVRAM_COLORBALLS_EASY_SCORE; /* grade slot in NVRAM */
    GFX.game_data.grade_nvram_id_list[1] = NVRAM_COLORBALLS_NORMAL_SCORE;       /* grade slot in NVRAM */
    GFX.game_data.grade_nvram_id_list[2] = NVRAM_COLORBALLS_HARD_SCORE; /* grade slot in NVRAM */
    GFX.game_data.level_nvram_id = NVRAM_COLORBALLS_OPTION_STATUS;      /* current lvl idnex stored in NVRAM */

    /* help */
    GFX.game_data.help_str_id = STR_GX_COLORBALLS_DESCRIPTION;  /* help desciption string id */

    /* misc */
    GFX.game_data.grade_value_ptr = (S16*) (&cb_game_grade);   /* current level's grade (S16*) */
    GFX.game_data.level_index_ptr = (U8*) (&cb_colorball_setting);     /* ptr to current level index (U8*) */
    GFX.game_data.is_new_game = (BOOL*) (&cb_is_new_game);  /* ptr to new game flag (BOOL*) */

    /* function ptr */
    GFX.game_data.best_grade_func_ptr = ColorBalls_Calc_Best_Grade;     /* function to calculate best grade */
    GFX.game_data.enter_game_func_ptr = ColorBalls_Enter_Game;  /* function to enter new game */
    GFX.game_data.exit_game_func_ptr = ColorBalls_Exit_Game;    /* function to exit game */
    GFX.game_data.draw_gameover_func_ptr = ColorBalls_Draw_GameOver;    /* function to draw gameover screen */

    /* some flags */
    GFX.game_data.is_keypad_audio_enable = FALSE;   /* play keypad tone or not */

    mmi_gfx_entry_menu_screen();
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Calc_Best_Grade
 * DESCRIPTION
 *  Calculate new best grade [Callback required by GFX]
 * PARAMETERS
 *  old_grade       [IN]        
 *  new_grade       [IN]        
 * RETURNS
 *  S16
 *****************************************************************************/
S16 ColorBalls_Calc_Best_Grade(S16 old_grade, S16 new_grade)
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
 *  ColorBalls_Draw_GameOver
 * DESCRIPTION
 *  Draw Gameover Screen [Callback required by GFX]
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Draw_GameOver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GFX_PLAY_AUDIO_GAMEOVER();

    /* call this function to draw standard gameover screen */
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    mmi_gfx_draw_gameover_screen(
        IMG_GX_COLORBALLS_GOTEXT,
        IMG_GX_COLORBALLS_GRADESMAP,
        IMG_GX_COLORBALLS_GOPIC,
        cb_game_grade);
#else
    mmi_gfx_draw_gameover_screen(
        mmi_gfx_get_multilanguage_image_ID(
         mmi_colorBall_language_index, 
         IMG_GX_COLORBALLS_LEVEL_LANGUAGE0, 
         MMI_COLORBALL_STRING_COUNT, 
         MMI_COLORBALL_STRING_GAMEOVER),
        IMG_GX_COLORBALLS_GRADESMAP,
        IMG_GX_COLORBALLS_GOPIC,
        cb_game_grade);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Enter_Game
 * DESCRIPTION
 *  Enter Game [Callback required by GFX]
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Enter_Game()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__  //used for multilanguage
    mmi_colorBall_language_index = g_mmi_game_current_language_index;
    mmi_gfx_check_image_get_valid_language(
        &mmi_colorBall_language_index, 
        IMG_GX_COLORBALLS_LEVEL_LANGUAGE0, 
        MMI_COLORBALL_STRING_COUNT);
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

    if (cb_is_new_game == TRUE)
    {
        cb_is_new_game = FALSE;
        ColorBalls_Enter_New_Game();
    }
    else
    {
        ColorBalls_Enter_Resume_Game();
    }
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Exit_Game
 * DESCRIPTION
 *  Exit Game [Callback required by GFX]
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Exit_Game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(ColorBalls_Start);
    gui_cancel_timer(ColorBalls_Bullet_Callback);

#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    GFX_STOP_SOUND_EFFECTS_MIDI(shoot_midi);
    GFX_STOP_SOUND_EFFECTS_MIDI(hitgood_midi);
    GFX_STOP_SOUND_EFFECTS_MIDI(hitbad_midi);

    GFX_CLOSE_SOUND_EFFECTS_MIDI(shoot_midi);
    GFX_CLOSE_SOUND_EFFECTS_MIDI(hitgood_midi);
    GFX_CLOSE_SOUND_EFFECTS_MIDI(hitbad_midi);
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

}

/************************************************************************/
/************************************************************************/
/* BELOW THIS LINE IS GAME KERNAL IMPLMENTED BY PIXTEL.              */
/************************************************************************/
/************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Enter_Resume_Game
 * DESCRIPTION
 *  Entry Function On Game Resume. Reinitalize Colorball Objects and Call
 *  Colorball game intilization function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Enter_Resume_Game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ColorBalls_Init_Objects();
    ColorBalls_Init();
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Enter_New_Game
 * DESCRIPTION
 *  Entry Function On New ColorBall Game.
 *  1. Clear All Game Resources.
 *  2. Set Game Level from the global GFX Variable.
 *  3. Initlize Colorball Objects for Default Values
 *  4. Initlize memory buffer pool for Colorball Objects
 *  5. Initlize Colorball Game Data Structure.
 *  6. Initlize Colorball to Get Start
 *  Colorball game intilization function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Enter_New_Game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ColorBalls_Clear_All_Res();
    ColorBalls_Set_Game_Level();
    ColorBalls_Init_Default_Value();
    ColorBalls_Init_Bit_Buffer();
    ColorBalls_Init_Objects();
    ColorBalls_Init();
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Init
 * DESCRIPTION
 *  Initlize Colorball Game To Get Start.
 *  Draw ColorBall Background
 *  Draw Launcher
 *  Draw Sidebar
 *  Get Back Ground Buffer In Case of Resume Game
 *  Start Bullet Call Back Function
 *  Enter Game Start
 *  Colorball game intilization function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_screen();
    ColorBalls_Init_Key_Handler();
    gui_set_clip(0, 0, 128, 128);
    cb_cur_game_level = 0;

#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    GFX_OPEN_SOUND_EFFECTS_MIDI(colorBallShoot, COLORBALLSHOOTSIZE, 1, shoot_midi);
    GFX_OPEN_SOUND_EFFECTS_MIDI(colorBallHitGood, COLORBALLHITGOOD, 1, hitgood_midi);
    GFX_OPEN_SOUND_EFFECTS_MIDI(colorBallHitBad, COLORBALLHITBAD, 1, hitbad_midi);
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

    ColorBalls_Draw_Background();
    ColorBalls_Draw_Launcher();
    ColorBalls_Draw_Bullet_On_Launcher();

    /* draw side bar */
    ColorBalls_Draw_Level();
    ColorBalls_Draw_Grade();
    ColorBalls_Draw_Energy();

    ColorBalls_Get_BG_Buffer_On_Resume();

    ColorBalls_Bullet_Callback();
    ColorBalls_Start();
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Init_Objects
 * DESCRIPTION
 *  Assoicate ColorBall Data Structure with Default Value Of Image, Image
 *  Size And Score
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Init_Objects(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_falling_ball_ptr[0]->cb_image = (PU8) get_image(IMG_GX_COLORBALLS_BIG_BLUE);
    gui_measure_image(
        cb_falling_ball_ptr[0]->cb_image,
        &cb_falling_ball_ptr[0]->cb_width,
        &cb_falling_ball_ptr[0]->cb_height);
    cb_falling_ball_ptr[0]->cb_score = 20;

    cb_falling_ball_ptr[1]->cb_image = (PU8) get_image(IMG_GX_COLORBALLS_BIG_GREEN);
    gui_measure_image(
        cb_falling_ball_ptr[1]->cb_image,
        &cb_falling_ball_ptr[1]->cb_width,
        &cb_falling_ball_ptr[1]->cb_height);
    cb_falling_ball_ptr[1]->cb_score = 15;

    cb_falling_ball_ptr[2]->cb_image = (PU8) get_image(IMG_GX_COLORBALLS_BIG_LIGHT);
    gui_measure_image(
        cb_falling_ball_ptr[2]->cb_image,
        &cb_falling_ball_ptr[2]->cb_width,
        &cb_falling_ball_ptr[2]->cb_height);
    cb_falling_ball_ptr[2]->cb_score = 10;

    cb_falling_ball_ptr[3]->cb_image = (PU8) get_image(IMG_GX_COLORBALLS_BIG_PINK);
    gui_measure_image(
        cb_falling_ball_ptr[3]->cb_image,
        &cb_falling_ball_ptr[3]->cb_width,
        &cb_falling_ball_ptr[3]->cb_height);
    cb_falling_ball_ptr[3]->cb_score = 5;

    cb_falling_ball_ptr[4]->cb_image = (PU8) get_image(IMG_GX_COLORBALLS_SMALL_BLUE);
    gui_measure_image(
        cb_falling_ball_ptr[4]->cb_image,
        &cb_falling_ball_ptr[4]->cb_width,
        &cb_falling_ball_ptr[4]->cb_height);
    cb_falling_ball_ptr[4]->cb_score = 0;

    cb_falling_ball_ptr[5]->cb_image = (PU8) get_image(IMG_GX_COLORBALLS_SMALL_GREEN);
    gui_measure_image(
        cb_falling_ball_ptr[5]->cb_image,
        &cb_falling_ball_ptr[5]->cb_width,
        &cb_falling_ball_ptr[5]->cb_height);
    cb_falling_ball_ptr[5]->cb_score = 0;

    cb_falling_ball_ptr[6]->cb_image = (PU8) get_image(IMG_GX_COLORBALLS_SMALL_LIGHT);
    gui_measure_image(
        cb_falling_ball_ptr[6]->cb_image,
        &cb_falling_ball_ptr[6]->cb_width,
        &cb_falling_ball_ptr[6]->cb_height);
    cb_falling_ball_ptr[6]->cb_score = 0;

    cb_falling_ball_ptr[7]->cb_image = (PU8) get_image(IMG_GX_COLORBALLS_SMALL_PINK);
    gui_measure_image(
        cb_falling_ball_ptr[7]->cb_image,
        &cb_falling_ball_ptr[7]->cb_width,
        &cb_falling_ball_ptr[7]->cb_height);
    cb_falling_ball_ptr[7]->cb_score = 0;

    cb_launcher.cb_image = (PU8) get_image(IMG_GX_COLORBALLS_LAUNCH);
    gui_measure_image(cb_launcher.cb_image, &cb_launcher.cb_width, &cb_launcher.cb_height);
    cb_launcher.cb_score = 0;
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Clear_All_Res
 * DESCRIPTION
 *  Clear All Game Resource In Case Of New Game
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Clear_All_Res(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(cb_runtime_falling_ball, 255, MAX_FALLING_BALLS * sizeof(CB_RUNNING_BALL_STRUCT));
    memset(&cb_runtime_bullet, 255, sizeof(CB_RUNNING_BALL_STRUCT) * MAX_RUNNNING_BULLETS);
    memset(&cb_runtime_launcher, 255, sizeof(CB_RUNNING_BALL_STRUCT));

    cb_launcher_movement = DEFAULT_LAUCHER_POSITION;
    cb_cur_bullet_color = DEFAULT_BULLET_BALL;
    cb_remain_drop_ball = DROP_BALL_COUNT;
    cb_game_grade = 0;
    cb_runtime_launcher.X = cb_launcher_move_x[cb_launcher_movement];
    cb_runtime_launcher.Y = DEFAULT_LANUCHER_Y;
    cb_bullet_on_launcher.X = cb_runtime_launcher.X;
    cb_bullet_on_launcher.Y = cb_runtime_launcher.Y;
    cb_bullet_on_launcher.ballType = DEFAULT_BULLET_BALL;
    cb_is_bullet_on_launcher = TRUE;

    cb_is_fire_bullet = FALSE;
    cb_is_change_bullet = FALSE;
    cb_is_change_opp_color = FALSE;
    cb_is_launcher_right = FALSE;
    cb_is_launcher_left = FALSE;
    cb_is_gameover = FALSE;
    cb_game_energy = MAXIMUM_CB_ENERGY;
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Set_Game_Level
 * DESCRIPTION
 *  Set the game level in case of new game.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Set_Game_Level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_timer_elapse = cb_game_speed_level[cb_colorball_setting][cb_cur_game_level];
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Init_Key_Handler
 * DESCRIPTION
 *  Initilize Games Keys.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Init_Key_Handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(GoBackHistory, KEY_LSK, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_RSK, KEY_EVENT_UP);

    SetKeyHandler(ColorBalls_Key_Change_Bullet_Color, KEY_5, KEY_EVENT_DOWN);
    SetKeyHandler(ColorBalls_Key_Change_Opp_Color, KEY_8, KEY_EVENT_DOWN);

    SetKeyHandler(ColorBalls_Key_Fire_Bullet, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(ColorBalls_Key_Move_Laucher_Rigth, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(ColorBalls_Key_Move_Laucher_Left, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(ColorBalls_Key_Fire_Bullet, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(ColorBalls_Key_Move_Laucher_Rigth, KEY_6, KEY_EVENT_DOWN);
    SetKeyHandler(ColorBalls_Key_Move_Laucher_Left, KEY_4, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Key_Change_Bullet_Color
 * DESCRIPTION
 *  Change The Flag To True On Pressing 5 Key For Change In ColorBall Bullet
 *  Color
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Key_Change_Bullet_Color(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_is_change_bullet = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Key_Change_Opp_Color
 * DESCRIPTION
 *  Change The Flag To True On Pressing 8 Key For Change In ColorBall Bullet
 *  Color To The Opposite Color. Opposite Color Meaning Is Not Clear, Neither
 *  To Pixtel And MTK So No Functionality Is Their For It.
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Key_Change_Opp_Color(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_is_change_opp_color = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Key_Fire_Bullet
 * DESCRIPTION
 *  Set The Fire Bullet Flag To True, On Prssing Up Key Fire Flag Is Set To
 *  True
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Key_Fire_Bullet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_is_fire_bullet = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Key_Move_Laucher_Rigth
 * DESCRIPTION
 *  Set The Right Movement Flag of Launcher To True, On Prssing Right Arrow Key
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Key_Move_Laucher_Rigth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_is_launcher_right = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Key_Move_Laucher_Left
 * DESCRIPTION
 *  Set The Left Movement Flag of Launcher To True, On Prssing Left Arrow Key
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Key_Move_Laucher_Left(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_is_launcher_left = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Draw_Background
 * DESCRIPTION
 *  Draw the Colorball Background.
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Draw_Background(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_show_transparent_image(0, 0, get_image(IMG_GX_COLORBALLS_BG), 0);
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Draw_Launcher
 * DESCRIPTION
 *  Get Background At Laucher Position And Draw The Launcher
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Draw_Launcher(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    _get_bitmap(
        cb_runtime_launcher.X,
        cb_runtime_launcher.Y,
        cb_runtime_launcher.X + cb_launcher.cb_width - 1,
        cb_runtime_launcher.Y + cb_launcher.cb_height - 1,
        &cb_runtime_launcher.bgBuffer);
    gui_show_transparent_image(cb_runtime_launcher.X, cb_runtime_launcher.Y, get_image(IMG_GX_COLORBALLS_LAUNCH), 0);
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Draw_Bullet_On_Launcher
 * DESCRIPTION
 *  Get The Background And Display Bullet On Laucher In Case Ball Is Already
 *  Not On The Launcher
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Draw_Bullet_On_Launcher(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cb_is_bullet_on_launcher == TRUE)
    {
        if (cb_is_change_bullet == FALSE)
        {
            _get_bitmap(
                cb_bullet_on_launcher.X,
                cb_bullet_on_launcher.Y - cb_falling_ball_ptr[cb_bullet_on_launcher.ballType]->cb_height,
                cb_bullet_on_launcher.X + cb_falling_ball_ptr[cb_bullet_on_launcher.ballType]->cb_width - 1,
                cb_bullet_on_launcher.Y - 1,
                &cb_bullet_on_launcher.bgBuffer);
        }
        gui_show_transparent_image(
            cb_bullet_on_launcher.X,
            cb_bullet_on_launcher.Y - cb_falling_ball_ptr[cb_bullet_on_launcher.ballType]->cb_height,
            get_image(cb_img_id_array[cb_bullet_on_launcher.ballType]),
            0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Start
 * DESCRIPTION
 *  ColorBall Game Kernal
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U8 newBulletAvailable = 0;
    U8 i = 0;
    static U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ColorBalls_Check_Collision();

    /* If Game Is Over Call Game End API */
    if (cb_is_gameover == TRUE)
    {
        ColorBalls_Game_End();
        return;
    }

    /* If newBulletAvailable is At Default Value make Bullet Avail To TRUE */
    if (newBulletAvailable++ == 255)
    {
        newBulletAvailable = 1;
    }

    if (cb_is_fire_bullet == TRUE && cb_bullet_on_launcher.ballType != 255)
    {
        for (i = 0; i < MAX_RUNNNING_BULLETS; i++)
        {
            /* Look For The First Empty Runtime Bullet Slot And Copy Bullet On Luacher Data To Empty Slot */
            if (cb_runtime_bullet[i].ballType == 255)
            {
            #ifdef __MMI_GAME_MULTICHANNEL_SOUND__
                GFX_STOP_SOUND_EFFECTS_MIDI(shoot_midi);
                GFX_STOP_SOUND_EFFECTS_MIDI(hitgood_midi);
                GFX_STOP_SOUND_EFFECTS_MIDI(hitbad_midi);

                GFX_PLAY_SOUND_EFFECTS_MIDI(shoot_midi);
            #else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
                GFX_PLAY_AUDIO_MIDI(colorBallShoot, COLORBALLSHOOTSIZE, DEVICE_AUDIO_PLAY_ONCE);
            #endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
                _show_bitmap(
                    cb_bullet_on_launcher.X,
                    cb_bullet_on_launcher.Y - cb_falling_ball_ptr[cb_bullet_on_launcher.ballType]->cb_height,
                    &cb_bullet_on_launcher.bgBuffer);
                cb_runtime_bullet[i].ballType = cb_bullet_on_launcher.ballType;
                cb_runtime_bullet[i].X = cb_bullet_on_launcher.X;
                cb_runtime_bullet[i].Y =
                    cb_bullet_on_launcher.Y - (U8) cb_falling_ball_ptr[cb_bullet_on_launcher.ballType]->cb_height;
                _get_bitmap(
                    cb_runtime_bullet[i].X,
                    cb_runtime_bullet[i].Y,
                    cb_runtime_bullet[i].X + cb_falling_ball_ptr[cb_runtime_bullet[i].ballType]->cb_width - 1,
                    cb_runtime_bullet[i].Y + cb_falling_ball_ptr[cb_runtime_bullet[i].ballType]->cb_height - 1,
                    &cb_runtime_bullet[i].bgBuffer);
                cb_bullet_on_launcher.ballType = 255;
                newBulletAvailable = 0;
                cb_is_bullet_on_launcher = FALSE;
                break;
            }
        }
        cb_is_fire_bullet = FALSE;
    }
    /* Change The Bullet Color If Bullet Is On The Launcher */
    if (cb_is_change_bullet == TRUE && cb_is_bullet_on_launcher == TRUE)
    {
        if (cb_bullet_on_launcher.ballType == 7)
        {
            cb_bullet_on_launcher.ballType = 4;
        }
        else
        {
            cb_bullet_on_launcher.ballType++;
        }
        cb_cur_bullet_color = cb_bullet_on_launcher.ballType;
        ColorBalls_Draw_Bullet_On_Launcher();
        cb_is_change_bullet = FALSE;
    }

    /* This Flag Is Not In Use */
    if (cb_is_change_opp_color == TRUE && cb_is_bullet_on_launcher == TRUE)
    {
        cb_is_change_opp_color = FALSE;
    }

    /* Move The Laucher To Right If Laucher Is Not On The Right Most Position */
    if (cb_is_launcher_right == TRUE)
    {
        if (cb_launcher_movement < 3)
        {
            if (cb_is_bullet_on_launcher == TRUE)
            {
                _show_bitmap(
                    cb_bullet_on_launcher.X,
                    cb_bullet_on_launcher.Y - cb_falling_ball_ptr[cb_bullet_on_launcher.ballType]->cb_height,
                    &cb_bullet_on_launcher.bgBuffer);
            }
            _show_bitmap(cb_runtime_launcher.X, cb_runtime_launcher.Y, &cb_runtime_launcher.bgBuffer);
            cb_launcher_movement++;
            cb_runtime_launcher.X = cb_launcher_move_x[cb_launcher_movement];
            cb_bullet_on_launcher.X = cb_runtime_launcher.X;
            if (cb_is_bullet_on_launcher == TRUE)
            {
                ColorBalls_Draw_Bullet_On_Launcher();
            }
            ColorBalls_Draw_Launcher();
        }
        cb_is_launcher_right = FALSE;
    }

    /* Move The Laucher To Right If Laucher Is Not On The Left Most Position */
    if (cb_is_launcher_left == TRUE)
    {
        if (cb_launcher_movement > 0)
        {
            cb_launcher_movement--;
            if (cb_is_bullet_on_launcher == TRUE)
            {
                _show_bitmap(
                    cb_bullet_on_launcher.X,
                    cb_bullet_on_launcher.Y - cb_falling_ball_ptr[cb_bullet_on_launcher.ballType]->cb_height,
                    &cb_bullet_on_launcher.bgBuffer);
            }
            _show_bitmap(cb_runtime_launcher.X, cb_runtime_launcher.Y, &cb_runtime_launcher.bgBuffer);
            cb_runtime_launcher.X = cb_launcher_move_x[cb_launcher_movement];
            cb_bullet_on_launcher.X = cb_runtime_launcher.X;
            if (cb_is_bullet_on_launcher == TRUE)
            {
                ColorBalls_Draw_Bullet_On_Launcher();
            }
            ColorBalls_Draw_Launcher();
        }
        cb_is_launcher_left = FALSE;
    }

    /* Create New Ball On The Laucher */
    if (cb_bullet_on_launcher.ballType == 255 && newBulletAvailable >= 1)
    {
        ColorBalls_New_Bullet();
    }

    /* Check Status Of All Falling Balls */
    for (i = 0; i < MAX_FALLING_BALLS; i++)
    {
        /* If Falling Ball Is Valid */
        if (cb_runtime_falling_ball[i].ballType != 255)
        {
            /* If Falling Ball Y is Less Then 0, then Use 0 Else Use Its Actual Value */
            if (cb_runtime_falling_ball[i].Y < 0)
            {
                _show_bitmap(cb_runtime_falling_ball[i].X, 0, &cb_runtime_falling_ball[i].bgBuffer);
            }
            else
            {
                _show_bitmap(
                    cb_runtime_falling_ball[i].X,
                    cb_runtime_falling_ball[i].Y,
                    &cb_runtime_falling_ball[i].bgBuffer);
            }

            /* If Fallinf Ball Is Dead, Remove Is From DS, Reduce Energy, If Energy Is 
               Zero End The Game */
            if ((cb_runtime_falling_ball[i].Y + 5) > 85)
            {
                cb_runtime_falling_ball[i].ballType = 255;
                cb_remain_drop_ball--;
                if (cb_remain_drop_ball % 4 == 0)
                {
                    cb_game_energy--;
                    ColorBalls_Draw_Energy();
                }
                if (cb_remain_drop_ball == 0)
                {
                    cb_is_gameover = TRUE;
                }
            }
            /* Display The Falling Ball At New Location */
            else
            {
                cb_runtime_falling_ball[i].Y += 5;
                if (cb_runtime_falling_ball[i].Y < 0)
                {
                    _get_bitmap(
                        cb_runtime_falling_ball[i].X,
                        0,
                        cb_runtime_falling_ball[i].X + cb_falling_ball_ptr[cb_runtime_falling_ball[i].ballType]->cb_width - 1,
                        cb_runtime_falling_ball[i].Y + cb_falling_ball_ptr[cb_runtime_falling_ball[i].ballType]->cb_height - 1,
                        &cb_runtime_falling_ball[i].bgBuffer);
                }
                else
                {
                    _get_bitmap(
                        cb_runtime_falling_ball[i].X,
                        cb_runtime_falling_ball[i].Y,
                        cb_runtime_falling_ball[i].X + cb_falling_ball_ptr[cb_runtime_falling_ball[i].ballType]->cb_width - 1,
                        cb_runtime_falling_ball[i].Y + cb_falling_ball_ptr[cb_runtime_falling_ball[i].ballType]->cb_height - 1,
                        &cb_runtime_falling_ball[i].bgBuffer);
                }
                gui_show_transparent_image(
                    cb_runtime_falling_ball[i].X,
                    cb_runtime_falling_ball[i].Y,
                    get_image(cb_img_id_array[cb_runtime_falling_ball[i].ballType]),
                    0);
            }
        }
    }
    count++;
    /* If Count ( A Static Counting Variable ) is 5(Enough To Make The Game Moving(Magic Number), Generate New Ball */
    if (count == 5)
    {
        ColorBalls_Gen_Dropping_Ball();
        count = 0;
    }

    /* Check Falling Balls Crash With Bullets */
    ColorBalls_Check_Unperfect_Collision();

    gui_BLT_double_buffer(0, 0, 128, 128);
    gui_start_timer(cb_timer_elapse, ColorBalls_Start);
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Bullet_Callback
 * DESCRIPTION
 *  Call Back Function For Bullet Movement.
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Bullet_Callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ColorBalls_Check_Collision();
    for (i = 0; i < MAX_RUNNNING_BULLETS; i++)
    {
        if (cb_runtime_bullet[i].ballType != 255)
        {
            _show_bitmap(cb_runtime_bullet[i].X, cb_runtime_bullet[i].Y, &cb_runtime_bullet[i].bgBuffer);
            if (((S16) cb_runtime_bullet[i].Y - 5) <= 0)
            {
                cb_runtime_bullet[i].ballType = 255;
            }
            else
            {
                cb_runtime_bullet[i].Y -= 10;
                _get_bitmap(
                    cb_runtime_bullet[i].X,
                    cb_runtime_bullet[i].Y,
                    cb_runtime_bullet[i].X + cb_falling_ball_ptr[cb_runtime_bullet[i].ballType]->cb_width - 1,
                    cb_runtime_bullet[i].Y + cb_falling_ball_ptr[cb_runtime_bullet[i].ballType]->cb_height - 1,
                    &cb_runtime_bullet[i].bgBuffer);
                gui_show_transparent_image(
                    cb_runtime_bullet[i].X,
                    cb_runtime_bullet[i].Y,
                    get_image(cb_img_id_array[cb_runtime_bullet[i].ballType]),
                    0);
            }
        }
    }

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    //this is used to support multi-language
    mmi_colorball_show_level_grade_power_image();
#endif /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

    /* Check The Bullets For Collision With Falling Balls */
    ColorBalls_Check_Unperfect_Collision();
    gui_BLT_double_buffer(0, 0, 128, 128);
    gui_start_timer(BULLET_TIMER, ColorBalls_Bullet_Callback);
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Check_Unperfect_Collision
 * DESCRIPTION
 *  Check The Bullets In Collision With Falling Balls
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Check_Unperfect_Collision(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_FALLING_BALLS; i++)
    {
        if (cb_runtime_falling_ball[i].ballType == 255)
        {
            continue;
        }
        else
        {
            for (j = 0; j < MAX_RUNNNING_BULLETS; j++)
            {
                if (cb_runtime_bullet[j].ballType == 255)
                {
                    continue;
                }
                else if ((cb_runtime_falling_ball[i].Y +
                          cb_falling_ball_ptr[cb_runtime_falling_ball[i].ballType]->cb_height + 5 ==
                          cb_runtime_bullet[j].Y) && cb_runtime_falling_ball[i].X == cb_runtime_bullet[j].X - 4)
                {
                    _show_bitmap(cb_runtime_bullet[j].X, cb_runtime_bullet[j].Y, &cb_runtime_bullet[j].bgBuffer);
                    cb_runtime_bullet[j].Y -= 5;
                    _get_bitmap(
                        cb_runtime_bullet[j].X,
                        cb_runtime_bullet[j].Y,
                        cb_runtime_bullet[j].X + cb_falling_ball_ptr[cb_runtime_bullet[j].ballType]->cb_width - 1,
                        cb_runtime_bullet[j].Y + cb_falling_ball_ptr[cb_runtime_bullet[j].ballType]->cb_height - 1,
                        &cb_runtime_bullet[j].bgBuffer);
                    gui_show_transparent_image(
                        cb_runtime_bullet[j].X,
                        cb_runtime_bullet[j].Y,
                        get_image(cb_img_id_array[cb_runtime_bullet[j].ballType]),
                        0);
                    break;
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Check_Collision
 * DESCRIPTION
 *  Collision Case For Unperfect, Where Balls Overlaps
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Check_Collision()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_FALLING_BALLS; i++)
    {
        if (cb_runtime_falling_ball[i].ballType == 255)
        {
            continue;
        }
        else
        {
            for (j = 0; j < MAX_RUNNNING_BULLETS; j++)
            {
                if (cb_runtime_bullet[j].ballType == 255)
                {
                    continue;
                }
                if (((cb_runtime_falling_ball[i].Y +
                      cb_falling_ball_ptr[cb_runtime_falling_ball[i].ballType]->cb_height == cb_runtime_bullet[j].Y) ||
                     (cb_runtime_falling_ball[i].Y +
                      cb_falling_ball_ptr[cb_runtime_falling_ball[i].ballType]->cb_height - 5 ==
                      cb_runtime_bullet[j].Y)) && cb_runtime_falling_ball[i].X == cb_runtime_bullet[j].X - 4)
                {

                    if (cb_runtime_falling_ball[i].ballType == cb_runtime_bullet[j].ballType - 4)
                    {
                    #ifdef __MMI_GAME_MULTICHANNEL_SOUND__
                        GFX_STOP_SOUND_EFFECTS_MIDI(shoot_midi);
                        GFX_STOP_SOUND_EFFECTS_MIDI(hitgood_midi);
                        GFX_STOP_SOUND_EFFECTS_MIDI(hitbad_midi);

                        GFX_PLAY_SOUND_EFFECTS_MIDI(hitgood_midi);
                    #else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
                        GFX_PLAY_AUDIO_MIDI(colorBallHitGood, COLORBALLHITGOOD, DEVICE_AUDIO_PLAY_ONCE);
                    #endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
                    }
                    else
                    {
                    #ifdef __MMI_GAME_MULTICHANNEL_SOUND__
                        GFX_STOP_SOUND_EFFECTS_MIDI(shoot_midi);
                        GFX_STOP_SOUND_EFFECTS_MIDI(hitgood_midi);
                        GFX_STOP_SOUND_EFFECTS_MIDI(hitbad_midi);

                        GFX_PLAY_SOUND_EFFECTS_MIDI(hitbad_midi);
                    #else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
                        GFX_PLAY_AUDIO_MIDI(colorBallHitBad, COLORBALLHITBAD, DEVICE_AUDIO_PLAY_ONCE);
                    #endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

                    }
                    if (cb_runtime_falling_ball[i].Y < 0)
                    {
                        _show_bitmap(cb_runtime_falling_ball[i].X, 0, &cb_runtime_falling_ball[i].bgBuffer);
                    }
                    else
                    {
                        _show_bitmap(
                            cb_runtime_falling_ball[i].X,
                            cb_runtime_falling_ball[i].Y,
                            &cb_runtime_falling_ball[i].bgBuffer);
                    }
                    _show_bitmap(cb_runtime_bullet[j].X, cb_runtime_bullet[j].Y, &cb_runtime_bullet[j].bgBuffer);
                    ColorBalls_Update_Status(i, j);
                    cb_runtime_falling_ball[i].ballType = 255;
                    cb_runtime_bullet[j].ballType = 255;
                    break;
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Gen_Dropping_Ball
 * DESCRIPTION
 *  Random Generate A Falling Ball
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Gen_Dropping_Ball(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_FALLING_BALLS; i++)
    {
        if (cb_runtime_falling_ball[i].ballType == 255)
        {
            U8 k = 0;

            cb_runtime_falling_ball[i].ballType = rand() % 4;
            while (1)
            {
                U8 colomn = rand() % 4;
                U8 ballInColomn = FALSE;

                cb_runtime_falling_ball[i].X = colomn * 18 + 2 * (colomn + 1);
                for (k = 0; k < MAX_FALLING_BALLS; k++)
                {
                    if (i == k)
                    {
                        continue;
                    }
                    if (cb_runtime_falling_ball[i].X == cb_runtime_falling_ball[k].X &&
                        cb_runtime_falling_ball[i].Y +
                        cb_falling_ball_ptr[cb_runtime_falling_ball[i].ballType]->cb_height + 10 <
                        cb_runtime_falling_ball[k].Y)
                    {
                        ballInColomn = TRUE;
                        break;
                    }
                }
                if (ballInColomn == FALSE)
                {
                    break;
                }
            }
            cb_runtime_falling_ball[i].Y = -13;
            if (cb_runtime_falling_ball[i].Y < 0)
            {
                _get_bitmap(
                    cb_runtime_falling_ball[i].X,
                    0,
                    cb_runtime_falling_ball[i].X + cb_falling_ball_ptr[cb_runtime_falling_ball[i].ballType]->cb_width - 1,
                    cb_runtime_falling_ball[i].Y + cb_falling_ball_ptr[cb_runtime_falling_ball[i].ballType]->cb_height - 1,
                    &cb_runtime_falling_ball[i].bgBuffer);
            }
            else
            {
                _get_bitmap(
                    cb_runtime_falling_ball[i].X,
                    cb_runtime_falling_ball[i].Y,
                    cb_runtime_falling_ball[i].X + cb_falling_ball_ptr[cb_runtime_falling_ball[i].ballType]->cb_width - 1,
                    cb_runtime_falling_ball[i].Y + cb_falling_ball_ptr[cb_runtime_falling_ball[i].ballType]->cb_height - 1,
                    &cb_runtime_falling_ball[i].bgBuffer);
            }
            gui_show_transparent_image(
                cb_runtime_falling_ball[i].X,
                cb_runtime_falling_ball[i].Y,
                get_image(cb_img_id_array[cb_runtime_falling_ball[i].ballType]),
                0);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Game_End
 * DESCRIPTION
 *  Set The Game Over Flag And Call Game Over API
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Game_End(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_is_new_game = TRUE;
    cb_is_gameover = FALSE;

    mmi_gfx_entry_gameover_screen();
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_New_Bullet
 * DESCRIPTION
 *  Generate New Bullet On Laucher
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_New_Bullet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_bullet_on_launcher.X = cb_runtime_launcher.X;
    cb_bullet_on_launcher.Y = cb_runtime_launcher.Y;
    cb_bullet_on_launcher.ballType = cb_cur_bullet_color;
    cb_is_bullet_on_launcher = TRUE;
    ColorBalls_Draw_Bullet_On_Launcher();
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Init_Bit_Buffer
 * DESCRIPTION
 *  Initilize Bit Buffer Memory For Balls
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Init_Bit_Buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //      if( TOTAL_COLORBALLS <= RICHES_TOTAL_OBJECTS )
    //      {
    for (i = 0; i < TOTAL_COLORBALLS; i++)
    {
        cb_falling_ball_ptr[i] = (CB_FALLING_BALL_STRUCT*) (&hintData[i]);
    }
    /* } */

    /* Playing with these values may result in Crash */
    cb_runtime_bullet[0].bgBuffer.data = (U8*) (subMenuDataPtrs[0]);
    cb_runtime_bullet[1].bgBuffer.data = (U8*) (subMenuDataPtrs[3]);
    cb_runtime_bullet[2].bgBuffer.data = (U8*) (subMenuDataPtrs[6]);
    cb_runtime_bullet[3].bgBuffer.data = (U8*) (subMenuDataPtrs[9]);
    cb_runtime_bullet[4].bgBuffer.data = (U8*) (subMenuDataPtrs[12]);
    cb_runtime_bullet[5].bgBuffer.data = (U8*) (subMenuDataPtrs[15]);

    cb_runtime_falling_ball[0].bgBuffer.data = (U8*) (subMenuDataPtrs[18]);
    cb_runtime_falling_ball[1].bgBuffer.data = (U8*) (subMenuDataPtrs[27]);
    cb_runtime_falling_ball[2].bgBuffer.data = (U8*) (subMenuDataPtrs[36]);
    cb_runtime_falling_ball[3].bgBuffer.data = (U8*) (subMenuDataPtrs[45]);

    cb_runtime_launcher.bgBuffer.data = (U8*) (subMenuDataPtrs[54]);
    cb_bullet_on_launcher.bgBuffer.data = (U8*) (subMenuDataPtrs[57]);

}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Init_Default_Value
 * DESCRIPTION
 *  Set The Colorball Data Structure Values To Default.
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Init_Default_Value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; i < MAX_RUNNNING_BULLETS; i++)
    {
        cb_runtime_bullet[i].ballType = 255;
    }
    for (i = 0; i < MAX_FALLING_BALLS; i++)
    {
        cb_runtime_falling_ball[i].ballType = 255;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Update_Status
 * DESCRIPTION
 *  Modify The ColorBall Game Status In Case Of Collision
 * PARAMETERS
 *  i       [IN]        
 *  j       [IN]        
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Update_Status(U8 i, U8 j)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cb_runtime_falling_ball[i].ballType == cb_runtime_bullet[j].ballType - 4)
    {
        cb_game_grade += cb_falling_ball_ptr[cb_runtime_falling_ball[i].ballType]->cb_score;
        ColorBalls_Draw_Grade();
    }
    else
    {
        cb_remain_drop_ball--;
        if (cb_remain_drop_ball % 4 == 0)
        {
            cb_game_energy--;
            ColorBalls_Draw_Energy();
        }
        if (cb_remain_drop_ball == 0)
        {
            cb_is_gameover = TRUE;
        }
    }

    if (cb_game_grade <= 0)
    {
        cb_game_grade = 0;
        ColorBalls_Draw_Grade();
    }
    else if ((cb_game_grade >= SCORE_CHNAGE_LEVEL * (cb_cur_game_level + 1)) &&
             cb_cur_game_level + 1 < GAME_INTERMIDATE_LEVELS)
    {
        cb_cur_game_level++;
        ColorBalls_Change_Level();
        ColorBalls_Draw_Level();
    }

}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Change_Level
 * DESCRIPTION
 *  Set The ColorBall Game Level On Start
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Change_Level()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_timer_elapse = cb_game_speed_level[cb_colorball_setting][cb_cur_game_level];
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Get_BG_Buffer_On_Resume
 * DESCRIPTION
 *  Get ColorBalls BackGround Buffer On Resume
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Get_BG_Buffer_On_Resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* For Falling Balls */
    for (i = 0; i < MAX_FALLING_BALLS; i++)
        if (cb_runtime_falling_ball[i].ballType != 255)
        {
            if (cb_runtime_falling_ball[i].Y < 0)
            {
                _get_bitmap(
                    cb_runtime_falling_ball[i].X,
                    0,
                    cb_runtime_falling_ball[i].X + cb_falling_ball_ptr[cb_runtime_falling_ball[i].ballType]->cb_width - 1,
                    cb_runtime_falling_ball[i].Y + cb_falling_ball_ptr[cb_runtime_falling_ball[i].ballType]->cb_height - 1,
                    &cb_runtime_falling_ball[i].bgBuffer);
            }
            else
            {
                _get_bitmap(
                    cb_runtime_falling_ball[i].X,
                    cb_runtime_falling_ball[i].Y,
                    cb_runtime_falling_ball[i].X + cb_falling_ball_ptr[cb_runtime_falling_ball[i].ballType]->cb_width - 1,
                    cb_runtime_falling_ball[i].Y + cb_falling_ball_ptr[cb_runtime_falling_ball[i].ballType]->cb_height - 1,
                    &cb_runtime_falling_ball[i].bgBuffer);
            }
        }
    /* For Running Bullets */
    for (i = 0; i < MAX_RUNNNING_BULLETS; i++)
        if (cb_runtime_bullet[i].ballType != 255)
        {
            _get_bitmap(
                cb_runtime_bullet[i].X,
                cb_runtime_bullet[i].Y,
                cb_runtime_bullet[i].X + cb_falling_ball_ptr[cb_runtime_bullet[i].ballType]->cb_width - 1,
                cb_runtime_bullet[i].Y + cb_falling_ball_ptr[cb_runtime_bullet[i].ballType]->cb_height - 1,
                &cb_runtime_bullet[i].bgBuffer);
        }
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Draw_Level
 * DESCRIPTION
 *  Draw ColorBall Level On Side Bar.
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Draw_Level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 displayString[64];
    U8 tempString[64];
    S32 strWidth;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((PS8) tempString, "%d", cb_cur_game_level + 1);
    mmi_asc_to_ucs2((PS8) displayString, (PS8) tempString);

    gui_show_transparent_image(87, 18, get_image(IMG_GX_COLORBALLS_LEVELBG), 0);

    gui_reset_text_clip();
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));

    strWidth = gui_get_string_width((UI_string_type) displayString);
    strWidth /= 2;

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(105 + strWidth, 20);
    }
    else
    {
        gui_move_text_cursor(105 - strWidth, 20);
    }

    gui_print_text((UI_string_type) displayString);
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Draw_Grade
 * DESCRIPTION
 *  Draw ColorBall Grades On Side Bar
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Draw_Grade(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 displayString[64];
    U8 tempString[64];
    S32 strWidth;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((PS8) tempString, "%d", cb_game_grade);
    mmi_asc_to_ucs2((PS8) displayString, (PS8) tempString);

    gui_show_transparent_image(87, 47, get_image(IMG_GX_COLORBALLS_GRADEBG), 0);

    gui_reset_text_clip();
    gui_set_font(&MMI_small_font);
    gui_set_text_color(gui_color(0, 0, 0));

    strWidth = gui_get_string_width((UI_string_type) displayString);
    strWidth /= 2;

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(105 + strWidth, 49);
    }
    else
    {
        gui_move_text_cursor(105 - strWidth, 49);
    }

    gui_print_text((UI_string_type) displayString);
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Draw_Energy
 * DESCRIPTION
 *  Draw ColorBall Energy On Side Bar
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ColorBalls_Draw_Energy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_show_transparent_image(87, 78, get_image(IMG_GX_COLORBALLS_ENERGYBG), 0);
    for (; i < cb_game_energy; i++)
    {
        gui_show_transparent_image(89, 124 - 2 - (i * 7) - 7, get_image(IMG_GX_COLORBALLS_ENERGYBAR), 0);
    }
}


#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__  //used for multi-language
/*****************************************************************************
 * FUNCTION
 *  mmi_colorball_show_level_grade_power_image
 * DESCRIPTION
 *  show level, grade, power image
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_colorball_show_level_grade_power_image(void)
{
    U8 i;

    for (i = MMI_COLORBALL_STRING_LEVEL ; i <= MMI_COLORBALL_STRING_ENERGY ; i++)
    {
        gui_show_image(mmi_colorball_multi_language_string[i].x, mmi_colorball_multi_language_string[i].y,
            (PU8) GetImage(mmi_gfx_get_multilanguage_image_ID(mmi_colorBall_language_index, 
            IMG_GX_COLORBALLS_LEVEL_LANGUAGE0, MMI_COLORBALL_STRING_COUNT, i)));
    }
}
#endif /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

#endif /* IS_COLORBALL_BASE_GAME */ 

