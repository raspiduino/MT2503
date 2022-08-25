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
 *  TOH.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Tower of Hanoi
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#include "GameDefs.h"
#ifdef __MMI_GAME_HANOI__
#include "GameInc.h"
#include "mmi_rp_app_games_def.h"
#include "TOHProts.h"

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
#include "GameProts.h"
#endif
/************************************************************************/
/* Game Defines                                                         */
/************************************************************************/
#define TOH_GAME_LEVELS             4
#define MAX_SCORE_LENGTH            5
#define BYTES_PER_PIXEL             2
#define TOH_TITLE_BAR_WIDTH         128
#define POPUP_TOH_DURATION          1000

/* Title  bar dimensions */
#define TOH_TITLE_BAR_WIDTH         128
#define TOH_TITLE_BAR_HEIGHT        18
#define TOH_TITLE_BAR_START_X       0
#define TOH_TITLE_BAR_START_Y       0
#define TOH_TITLE_BAR_END_X            TOH_TITLE_BAR_START_X + TOH_TITLE_BAR_WIDTH-1
#define TOH_TITLE_BAR_END_Y            TOH_TITLE_BAR_START_Y + TOH_TITLE_BAR_HEIGHT-1

#define TOH_TITLE_BAR_WIDTH_CENTRE     TOH_TITLE_BAR_START_X + (TOH_TITLE_BAR_WIDTH/2)
#define TOH_TITLE_BAR_HEIGHT_CENTRE    TOH_TITLE_BAR_START_Y + (TOH_TITLE_BAR_HEIGHT/2)

/* Level bar dimensions */
#define TOH_LEVEL_BAR_WIDTH         128
#define TOH_LEVEL_BAR_HEIGHT        17

#define TOH_LEVEL_BAR_START_X       0
#define TOH_LEVEL_BAR_START_Y       0
#define TOH_LEVEL_BAR_END_X            TOH_LEVEL_BAR_START_X + TOH_LEVEL_BAR_WIDTH-1
#define TOH_LEVEL_BAR_END_Y            TOH_LEVEL_BAR_START_Y + TOH_LEVEL_BAR_HEIGHT-1

#define TOH_LEVEL_BAR_WIDTH_CENTRE     TOH_LEVEL_BAR_START_X + (TOH_LEVEL_BAR_WIDTH/2)
#define TOH_LEVEL_BAR_HEIGHT_CENTRE    TOH_LEVEL_BAR_START_Y + (TOH_LEVEL_BAR_HEIGHT/2)

/* Level icon dimensions */
#define TOH_LEVEL_ICON_WIDTH        12
#define TOH_LEVEL_ICON_HEIGHT       12
#define LEVEL_ICON_DISTANCE_X       2
#define LEVEL_ICON_DISTANCE_Y       2

#define TOH_LEVEL_TEXT_X            12
#define TOH_NO_LEVELS               4

#define TOH_BACKGROUND_X            0
#define TOH_BACKGROUND_Y            (128 - 74)

/* Time bar dimensions */
#define TOH_TIME_BAR_WIDTH          128
#define TOH_TIME_BAR_HEIGHT         20
#define TOH_TIME_BAR_X              0
#define TOH_TIME_BAR_Y              TOH_LEVEL_BAR_END_Y+1
#define TOH_TIME_BAR_CENTRE         (TOH_TIME_BAR_X+TOH_TIME_BAR_WIDTH)/2

/* Tower Bar Dimesions */
#define TOH_TOWER_BAR_WIDTH            4
#define TOH_TOWER_BAR_HEIGHT           32

#define TOH_TOWER_BAR_Y                128-1
#define TOH_TOWER2_CENTRE_BOTTOM_X     (128/4 * 2)

#define TOH_TOWER1_CENTRE_BOTTOM_X     (TOH_TOWER2_CENTRE_BOTTOM_X - 42)
#define TOH_TOWER3_CENTRE_BOTTOM_X     (TOH_TOWER2_CENTRE_BOTTOM_X + 42)

#define TOH_INDICATOR_GAP              1

#define TOH_IDEL_TIME_LIMIT            (60)     /* if no movement after xx sec, back to menu */

/* Brick Size Dimesions */
#define TOH_BRICK_HEIGHT            8
#define TOH_BRICK1_WIDTH            12
#define TOH_BRICK2_WIDTH            16
#define TOH_BRICK3_WIDTH            20
#define TOH_BRICK4_WIDTH            24
#define TOH_BRICK5_WIDTH            28
#define TOH_BRICK6_WIDTH            32
#define TOH_DISTANCE_BRICKS         0

/************************************************************************/
/* Structure / Enum                                         */
/************************************************************************/
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__  //added for multi-language
typedef enum
{
    MMI_TOH_STRING_LEVEL = 0,
    MMI_TOH_STRING_GAMEOVER,
    MMI_TOH_STRING_TOTAL
}mmi_toh_string_enum;
#endif /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

typedef struct
{
    S32 startx;
    S32 starty;
    S32 endx;
    S32 endy;
    bitmap bgbitmap;
} TOH_BRICK_BMP_INFO_STRUCT;

typedef enum
{
    TOH_TOWER1 = 0,
    TOH_TOWER2,
    TOH_TOWER3,
    TOTAL_TOH_TOWERS
} TOH_TOWERS_ENUM;

typedef enum
{
    TOH_BRICK1 = 0,
    TOH_BRICK2,
    TOH_BRICK3,
    TOH_BRICK4,
    TOH_BRICK5,
    TOH_BRICK6,
    TOTAL_TOH_BRICKS,
    TOH_NIL
} TOH_BRICKS_ENUM;

typedef enum
{
    TOH_POSITION1 = 0,  /* Bottom Most */
    TOH_POSITION2,
    TOH_POSITION3,
    TOH_POSITION4,
    TOH_POSITION5,
    TOH_POSITION6       /* Top Most */
} TOH_BRICKS_POSITION_ENUM;

typedef enum
{
    HIGHLIGHTED,
    NOT_HIGHLIGHTED
} TOH_HIGHLIGHT_ENUM;

typedef enum
{
    ON_TOP,
    NOT_ON_TOP
} TOH_TOP_ENUM;

typedef enum
{
    SAVE_BG,
    DONT_SAVE_BG
} TOH_SAVE_BG_ENUM;

/************************************************************************/
/* Golbal Varable [Const]                                   */
/************************************************************************/
static const S32 toh_towers_bottom_x[TOTAL_TOH_TOWERS] = 
{
    TOH_TOWER1_CENTRE_BOTTOM_X,
    TOH_TOWER2_CENTRE_BOTTOM_X,
    TOH_TOWER3_CENTRE_BOTTOM_X
};

/************************************************************************/
/* Audio [Const]                                         */
/************************************************************************/
#define TOHMOVE               138
#define TOHCANTMOVE           140

__align(2)
     const U8 TOHMove[138] = 
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
     const U8 TOHCantMove[140] = 
     {
         0x4D, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01, 0x03, 0xC0, 0x4D, 0x54, 0x72,
         0x6B, 0x00, 0x00, 0x00, 0x76, 0x00, 0xFF, 0x02, 0x16, 0x43, 0x6F, 0x70, 0x79, 0x72, 0x69, 0x67,
         0x68, 0x74, 0x20, 0x63, 0x20, 0x32, 0x30, 0x30, 0x33, 0x20, 0x62, 0x79, 0x20, 0x43, 0x43, 0x00,
         0xFF, 0x01, 0x02, 0x43, 0x43, 0x00, 0xFF, 0x58, 0x04, 0x04, 0x02, 0x18, 0x08, 0x00, 0xFF, 0x59,
         0x02, 0x00, 0x00, 0x00, 0xFF, 0x51, 0x03, 0x09, 0x27, 0xC0, 0x00, 0x99, 0x44, 0x64, 0x00, 0x4F,
         0x64, 0x00, 0x52, 0x7D, 0x05, 0x38, 0x64, 0x23, 0x4B, 0x64, 0x2A, 0x4A, 0x64, 0x05, 0x3E, 0x64,
         0x35, 0x41, 0x64, 0x53, 0x4D, 0x64, 0x05, 0x42, 0x64, 0x0C, 0x52, 0x00, 0x00, 0x44, 0x00, 0x00,
         0x4F, 0x00, 0x05, 0x38, 0x00, 0x23, 0x4B, 0x00, 0x2A, 0x4A, 0x00, 0x05, 0x3E, 0x00, 0x35, 0x41,
         0x00, 0x53, 0x4D, 0x00, 0x05, 0x42, 0x00, 0x00, 0xFF, 0x2F, 0x00
     };

/************************************************************************/
/* Golbal Varable [123 Byte]                                */
/************************************************************************/
static U8 toh_game_level = 0;
static BOOL toh_is_new_game = TRUE;
static S32 toh_max_bricks_in_game = TOTAL_TOH_BRICKS;
static S16 toh_game_time = 0;
static S16 toh_idle_time = 0;

static TOH_BRICK_BMP_INFO_STRUCT toh_time_info;

static PU8 toh_brick_image[TOTAL_TOH_BRICKS];
static PU8 toh_brick_image_h[TOTAL_TOH_BRICKS];

S32 toh_selecte_tower = TOH_TOWER1;
S32 toh_brick_width[TOTAL_TOH_BRICKS];
S32 toh_brick_height;
S32 toh_present_brick_condition[TOTAL_TOH_BRICKS][TOTAL_TOH_TOWERS];
S32 toh_present_brick_num[TOTAL_TOH_TOWERS];
S32 toh_selected_Tower_brick_on_top[TOTAL_TOH_TOWERS];

TOH_BRICK_BMP_INFO_STRUCT toh_brick_bitmap_info[TOTAL_TOH_BRICKS];
TOH_BRICK_BMP_INFO_STRUCT toh_tower_in_bitmap_info;

 #if defined (__MMI_GAME_MULTICHANNEL_SOUND__)
S32 move_midi;
S32 cantmove_midi;
 #endif /* defined (__MMI_GAME_MULTICHANNEL_SOUND__) */ 

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__  /*added for game multi-language*/
static U16 mmi_toh_language_index;
#define MMI_TOH_STRING_COUNT  MMI_TOH_STRING_TOTAL
#endif

/************************************************************************/
/* Function Declare                                      */
/************************************************************************/
/* Game framework related functions */
void TOH_Draw_GameOver(void);
void TOH_Enter_Game(void);
void TOH_Exit_Game(void);
S16 TOH_Calc_Best_Grade(S16 old_grade, S16 new_grade);

/* Game play functions */
void TOH_Init_Variable(void);
void TOH_End_Game(void);
void TOH_Redraw_Screen(void);
void TOH_Draw_Title_Bar(void);
void TOH_Draw_Level_Bar(void);
void TOH_Draw_Background(void);
void TOH_Draw_Timer(void);
void TOH_Draw_Tower_Indicator(TOH_TOWERS_ENUM tower);
void TOH_Display_Time(void);
void TOH_Draw_Tower(void);
void TOH_Draw_Brick(
        TOH_TOWERS_ENUM tower,
        TOH_BRICKS_ENUM brick,
        S32 position,
        S32 is_highlighted,
        S32 is_top,
        S32 get_bg);
void TOH_Redraw_Bg_Brick_Area(TOH_BRICKS_ENUM brick);
void TOH_Left_Arrow(void);
void TOH_Right_Arrow(void);
void TOH_Up_Arrow(void);
void TOH_Down_Arrow(void);
void TOH_DeInit_Variable(void);

extern void _show_bitmap(S32 x1, S32 y1, bitmap *b);
extern void _get_bitmap(S32 x1, S32 y1, S32 x2, S32 y2, bitmap *b);


/*****************************************************************************
 * FUNCTION
 *  TOH_Enter_GFX
 * DESCRIPTION
 *  Set Game Framework (GFX) Parameter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TOH_Enter_GFX(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Game menu */
    GFX.game_data.game_img_id = IMG_GX_TOH_GAME_ICON;   /* game icon img ID */
    GFX.game_data.game_str_id = STR_GX_TOH_GAME_NAME;   /* game name string ID */
    GFX.game_data.menu_resume_str_id = STR_GAME_RESUME; /* "Resume" string ID */
    GFX.game_data.menu_new_str_id = STR_GAME_NEW;       /* "New Game" string ID */
    GFX.game_data.menu_level_str_id = STR_GAME_LEVEL;   /* "Game Level" string ID */
    GFX.game_data.menu_grade_str_id = STR_GAME_GRADE;   /* "Best Grade" string ID */
    GFX.game_data.menu_help_str_id = STR_GLOBAL_HELP;     /* "Game Help string ID */

    /* level / grade */
    GFX.game_data.level_count = 4;                          /* how many levels */
    GFX.game_data.level_str_id_list[0] = STR_GX_TOH_LEVEL1; /* level string ID */
    GFX.game_data.level_str_id_list[1] = STR_GX_TOH_LEVEL2; /* level string ID */
    GFX.game_data.level_str_id_list[2] = STR_GX_TOH_LEVEL3; /* level string ID */
    GFX.game_data.level_str_id_list[3] = STR_GX_TOH_LEVEL4; /* level string ID */

    GFX.game_data.grade_nvram_id_list[0] = TOH_LEVEL1_HIGHEST_SCORE;    /* grade slot in NVRAM */
    GFX.game_data.grade_nvram_id_list[1] = TOH_LEVEL2_HIGHEST_SCORE;    /* grade slot in NVRAM */
    GFX.game_data.grade_nvram_id_list[2] = TOH_LEVEL3_HIGHEST_SCORE;    /* grade slot in NVRAM */
    GFX.game_data.grade_nvram_id_list[3] = TOH_LEVEL4_HIGHEST_SCORE;    /* grade slot in NVRAM */
    GFX.game_data.level_nvram_id = TOH_CURRENT_LEVEL;   /* current lvl idnex stored in NVRAM */

    /* help */
    GFX.game_data.help_str_id = STR_GX_TOH_HELP_DESCRIPTION;    /* help desciption string id */

    /* misc */
    GFX.game_data.grade_value_ptr = (S16*) (&toh_game_time);   /* current level's grade (S16*) */
    GFX.game_data.level_index_ptr = (U8*) (&toh_game_level);   /* ptr to current level index (U8*) */
    GFX.game_data.is_new_game = (BOOL*) & toh_is_new_game;  /* ptr to new game flag (BOOL*) */

    /* function ptr */
    GFX.game_data.best_grade_func_ptr = TOH_Calc_Best_Grade;    /* function to calculate best grade */
    GFX.game_data.enter_game_func_ptr = TOH_Enter_Game; /* function to enter new game */
    GFX.game_data.exit_game_func_ptr = TOH_Exit_Game;   /* function to exit game */
    GFX.game_data.draw_gameover_func_ptr = TOH_Draw_GameOver;   /* function to draw gameover screen */

    /* some flags */
    GFX.game_data.is_keypad_audio_enable = FALSE;   /* play keypad tone or not */

    mmi_gfx_entry_menu_screen();
}


/*****************************************************************************
 * FUNCTION
 *  TOH_Calc_Best_Grade
 * DESCRIPTION
 *  Calculate new best grade [Callback required by GFX]
 * PARAMETERS
 *  old_grade       [IN]        
 *  new_grade       [IN]        
 * RETURNS
 *  S16
 *****************************************************************************/
S16 TOH_Calc_Best_Grade(S16 old_grade, S16 new_grade)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (old_grade == 0)
    {
        return new_grade;
    }

    if (new_grade > old_grade)
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
 *  TOH_Draw_GameOver
 * DESCRIPTION
 *  Draw Gameover Screen [Callback required by GFX]
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void TOH_Draw_GameOver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TOH_DeInit_Variable();

    GFX_PLAY_AUDIO_COMPLETE();

    /* call this function to draw standard gameover screen */
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ /* used for multi-language*/
    mmi_gfx_draw_gameover_screen(IMG_GX_TOH_GOTEXT, IMG_GX_TOH_GRADESMAP, IMG_GX_TOH_GOPIC, toh_game_time);
#else   /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    mmi_gfx_draw_gameover_screen(
     mmi_gfx_get_multilanguage_image_ID(
      mmi_toh_language_index,
      IMG_GX_TOH_LEVEL_LANGUAGE0, 
      MMI_TOH_STRING_COUNT,
      MMI_TOH_STRING_GAMEOVER), 
    IMG_GX_TOH_GRADESMAP, 
    IMG_GX_TOH_GOPIC, 
    toh_game_time);
#endif  /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

}


/*****************************************************************************
 * FUNCTION
 *  TOH_Enter_Game
 * DESCRIPTION
 *  Enter Game [Callback required by GFX]
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void TOH_Enter_Game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (toh_is_new_game == TRUE)
    {
        TOH_Init_Variable();
    }

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    mmi_toh_language_index = g_mmi_game_current_language_index;
    mmi_gfx_check_image_get_valid_language(
        &mmi_toh_language_index, 
        IMG_GX_TOH_LEVEL_LANGUAGE0, 
        MMI_TOH_STRING_COUNT);
#endif
    
#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    GFX_OPEN_SOUND_EFFECTS_MIDI(TOHMove, TOHMOVE, 1, move_midi);
    GFX_OPEN_SOUND_EFFECTS_MIDI(TOHCantMove, TOHCANTMOVE, 1, cantmove_midi);
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

    toh_idle_time = 0;  /* reset idel timer */
    TOH_Redraw_Screen();
}


/*****************************************************************************
 * FUNCTION
 *  TOH_Exit_Game
 * DESCRIPTION
 *  Exit Game [Callback required by GFX]
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void TOH_Exit_Game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(TOH_Display_Time);
#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    GFX_STOP_SOUND_EFFECTS_MIDI(move_midi);
    GFX_STOP_SOUND_EFFECTS_MIDI(cantmove_midi);

    GFX_CLOSE_SOUND_EFFECTS_MIDI(move_midi);
    GFX_CLOSE_SOUND_EFFECTS_MIDI(cantmove_midi);
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

}

/************************************************************************/
/************************************************************************/
/* BELOW THIS LINE IS GAME KERNAL IMPLMENTED BY PIXTEL.              */
/************************************************************************/
/************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  TOH_Init_Variable
 * DESCRIPTION
 *  Function Call At The New Game Start To Intialize TOH Variables.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TOH_Init_Variable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, iheight, iwidth;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    toh_is_new_game = FALSE;
    toh_selecte_tower = TOH_TOWER1;
    toh_game_time = 0;
    toh_idle_time = 0;
    toh_max_bricks_in_game = toh_game_level + 3;

    toh_brick_image[TOH_BRICK1] = (PU8) GetImage(IMG_GX_TOH_BRICK1);
    toh_brick_image[TOH_BRICK2] = (PU8) GetImage(IMG_GX_TOH_BRICK2);
    toh_brick_image[TOH_BRICK3] = (PU8) GetImage(IMG_GX_TOH_BRICK3);
    toh_brick_image[TOH_BRICK4] = (PU8) GetImage(IMG_GX_TOH_BRICK4);
    toh_brick_image[TOH_BRICK5] = (PU8) GetImage(IMG_GX_TOH_BRICK5);
    toh_brick_image[TOH_BRICK6] = (PU8) GetImage(IMG_GX_TOH_BRICK6);

    toh_brick_image_h[TOH_BRICK1] = (PU8) GetImage(IMG_GX_TOH_BRICK1_HL);
    toh_brick_image_h[TOH_BRICK2] = (PU8) GetImage(IMG_GX_TOH_BRICK2_HL);
    toh_brick_image_h[TOH_BRICK3] = (PU8) GetImage(IMG_GX_TOH_BRICK3_HL);
    toh_brick_image_h[TOH_BRICK4] = (PU8) GetImage(IMG_GX_TOH_BRICK4_HL);
    toh_brick_image_h[TOH_BRICK5] = (PU8) GetImage(IMG_GX_TOH_BRICK5_HL);
    toh_brick_image_h[TOH_BRICK6] = (PU8) GetImage(IMG_GX_TOH_BRICK6_HL);

    gui_measure_image((PU8) GetImage(IMG_GX_TOH_TOWER_IN), &iwidth, &iheight);

    toh_tower_in_bitmap_info.bgbitmap.data = (U8*) (subMenuDataPtrs[0]);

    for (i = 0; i < toh_max_bricks_in_game; i++)
    {
        gui_measure_image(toh_brick_image[i], &iwidth, &iheight);
        toh_brick_width[i] = iwidth;

        switch (i)
        {

            case 0:
                toh_brick_bitmap_info[i].bgbitmap.data = (U8*) (subMenuDataPtrs[7]);
                break;

            case 1:
                toh_brick_bitmap_info[i].bgbitmap.data = (U8*) (subMenuDataPtrs[12]);
                break;

            case 2:
                toh_brick_bitmap_info[i].bgbitmap.data = (U8*) (subMenuDataPtrs[19]);
                break;

            case 3:
                toh_brick_bitmap_info[i].bgbitmap.data = (U8*) (subMenuDataPtrs[27]);
                break;

            case 4:
                toh_brick_bitmap_info[i].bgbitmap.data = (U8*) (subMenuDataPtrs[36]);
                break;

            case 5:
                toh_brick_bitmap_info[i].bgbitmap.data = (U8*) (subMenuDataPtrs[46]);
                break;

        }
        /* toh_brick_bitmap_info[i].bgbitmap.data=gui_malloc(4000); */
    }

    toh_brick_height = iheight;

    toh_present_brick_num[TOH_TOWER1] = toh_max_bricks_in_game;
    toh_present_brick_num[TOH_TOWER2] = 0;
    toh_present_brick_num[TOH_TOWER3] = 0;
    toh_selected_Tower_brick_on_top[TOH_TOWER1] = FALSE;
    toh_selected_Tower_brick_on_top[TOH_TOWER2] = FALSE;
    toh_selected_Tower_brick_on_top[TOH_TOWER3] = FALSE;

    for (i = 0; i < toh_max_bricks_in_game; i++)
    {
        toh_present_brick_condition[i][TOH_TOWER1] = toh_max_bricks_in_game - 1 - i;
        toh_present_brick_condition[i][TOH_TOWER2] = TOH_NIL;
        toh_present_brick_condition[i][TOH_TOWER3] = TOH_NIL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  TOH_Redraw_Screen
 * DESCRIPTION
 *  Draw the TOH Screen Depending Upon Diffrent Varaibles Value. In Case Of
 *  New Game Default New Games Screen Drawn
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TOH_Redraw_Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S32 brick, brick_position;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_screen();
    gui_hide_animations();
    gui_reset_clip();

    gui_lock_double_buffer();
    TOH_Draw_Level_Bar();
    TOH_Draw_Background();
    TOH_Draw_Tower();
    TOH_Draw_Tower_Indicator(toh_selecte_tower);
    TOH_Draw_Timer();
    gui_unlock_double_buffer();

    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);

    for (i = 0; i < TOTAL_TOH_TOWERS; i++)
    {
        for (j = 0; j < toh_present_brick_num[i]; j++)
        {
            TOH_Draw_Brick(i, toh_present_brick_condition[j][i], j, NOT_HIGHLIGHTED, NOT_ON_TOP, SAVE_BG);
        }
    }
    if (toh_present_brick_num[toh_selecte_tower] > 0)
    {
        brick_position = toh_present_brick_num[toh_selecte_tower] - 1;
        brick = toh_present_brick_condition[brick_position][toh_selecte_tower];
        if (toh_selected_Tower_brick_on_top[toh_selecte_tower])
        {
            TOH_Redraw_Bg_Brick_Area(brick);
            TOH_Draw_Brick(toh_selecte_tower, brick, brick_position, HIGHLIGHTED, ON_TOP, SAVE_BG);
        }
        else
        {
            TOH_Draw_Brick(toh_selecte_tower, brick, brick_position, HIGHLIGHTED, NOT_ON_TOP, DONT_SAVE_BG);
        }
    }

    SetKeyHandler(TOH_Left_Arrow, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(TOH_Right_Arrow, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(TOH_Up_Arrow, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(TOH_Down_Arrow, KEY_DOWN_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(TOH_Left_Arrow, KEY_4, KEY_EVENT_DOWN);
    SetKeyHandler(TOH_Right_Arrow, KEY_6, KEY_EVENT_DOWN);
    SetKeyHandler(TOH_Up_Arrow, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(TOH_Down_Arrow, KEY_8, KEY_EVENT_DOWN);

}

const UI_filled_area toh_title_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_DOUBLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

const color toh_title_text_color = {255, 255, 255, 100};


/*****************************************************************************
 * FUNCTION
 *  TOH_Draw_Title_Bar
 * DESCRIPTION
 *  Draw The TOH Game Screen Title Bar Contain TOH Caption.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TOH_Draw_Title_Bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 character_height, tx = 0, w;
    S32 tw;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_clip(TOH_TITLE_BAR_START_X, TOH_TITLE_BAR_START_Y, TOH_TITLE_BAR_END_X, TOH_TITLE_BAR_END_Y);

    gui_set_text_clip(TOH_TITLE_BAR_START_X, TOH_TITLE_BAR_START_Y, TOH_TITLE_BAR_END_X, TOH_TITLE_BAR_END_Y);

    gui_draw_filled_area(
        TOH_TITLE_BAR_START_X,
        TOH_TITLE_BAR_START_Y,
        TOH_TITLE_BAR_END_X,
        TOH_TITLE_BAR_END_Y,
        (UI_filled_area*)&toh_title_filler /* current_MMI_theme->active_window_title_filler */ );

    gui_set_font(&MMI_large_font);
    character_height = gui_get_character_height();
    /* gui_set_text_color(*current_MMI_theme->active_title_text_color); */
    gui_set_text_color(toh_title_text_color);

    tw = TOH_TITLE_BAR_END_X - tx;
    w = gui_get_string_width((UI_string_type) GetString(STR_GX_TOH_TITLE));
    if (w < tw)
    {
        tx = tx + (tw >> 1) - (w >> 1); /* Centers the title */
    }

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(tx, TOH_TITLE_BAR_HEIGHT_CENTRE + (character_height >> 1));
    }
    else
    {
        gui_move_text_cursor(tx, TOH_TITLE_BAR_HEIGHT_CENTRE - (character_height >> 1));
    }

    gui_print_text((UI_string_type) GetString(STR_GX_TOH_TITLE));

}

const UI_filled_area toh_level_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {255, 255, 255, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};
const color toh_level_text_color = {255, 255, 255, 100};
const color toh_level_text_border_color = {15, 70, 120, 100};


/*****************************************************************************
 * FUNCTION
 *  TOH_Draw_Level_Bar
 * DESCRIPTION
 *  Draw The Level Bar For TOH Comes Just Below The Title Bar
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void TOH_Draw_Level_Bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__  /*used for multi-language */
    S32 character_height = 0, str_width = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_clip(TOH_LEVEL_BAR_START_X, TOH_LEVEL_BAR_START_Y, TOH_LEVEL_BAR_END_X, TOH_LEVEL_BAR_END_Y);

    gui_set_text_clip(TOH_LEVEL_BAR_START_X, TOH_LEVEL_BAR_START_Y, TOH_LEVEL_BAR_END_X, TOH_LEVEL_BAR_END_Y);

    //      gui_draw_filled_area(TOH_LEVEL_BAR_START_X,TOH_LEVEL_BAR_START_Y,
    //                                                      TOH_LEVEL_BAR_END_X,TOH_LEVEL_BAR_END_Y,
    //                                                      &toh_level_filler);

    gui_show_transparent_image(TOH_LEVEL_BAR_START_X, TOH_LEVEL_BAR_START_Y, (PU8) GetImage(IMG_GX_TOH_TITLEBAR), 0);

#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__     /*used for multi-language */
    gui_set_font(&MMI_medium_font);
    character_height = gui_get_character_height();
    gui_set_text_color(toh_level_text_color);
    gui_set_text_border_color(toh_level_text_border_color);

    str_width = gui_get_string_width((UI_string_type) GetString(STR_GX_TOH_LEVEL));

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(TOH_LEVEL_TEXT_X + str_width, TOH_LEVEL_BAR_HEIGHT_CENTRE - (character_height >> 1) + 1);
    }
    else
    {
        gui_move_text_cursor(TOH_LEVEL_TEXT_X, TOH_LEVEL_BAR_HEIGHT_CENTRE - (character_height >> 1) + 1);
    }

    gui_print_bordered_text((UI_string_type) GetString(STR_GX_TOH_LEVEL));
#else   /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */
    gui_show_transparent_image(0, 0, 
        (PU8)GetImage(
         mmi_gfx_get_multilanguage_image_ID(
         mmi_toh_language_index,
         IMG_GX_TOH_LEVEL_LANGUAGE0, 
         MMI_TOH_STRING_COUNT,
         MMI_TOH_STRING_LEVEL)),
        0);
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

    for (i = TOH_NO_LEVELS; i > (toh_game_level + 1); i--)
    {
        S32 x, y, iwidth, iheight;

        gui_measure_image((PU8) GetImage(IMG_GX_TOH_LEVEL), &iwidth, &iheight);
        x = TOH_LEVEL_BAR_END_X - (TOH_NO_LEVELS - i + 1) * LEVEL_ICON_DISTANCE_Y - (TOH_NO_LEVELS - i + 1) * iwidth;
        y = TOH_LEVEL_BAR_START_Y + ((TOH_LEVEL_BAR_HEIGHT - iheight) >> 1);
        gui_show_transparent_image(x, y, (PU8) GetImage(IMG_GX_TOH_LEVEL), 0);
    }
    while (i)
    {
        S32 x, y, iwidth, iheight;

        gui_measure_image((PU8) GetImage(IMG_GX_TOH_LEVEL_HL), &iwidth, &iheight);
        x = TOH_LEVEL_BAR_END_X - (TOH_NO_LEVELS - i + 1) * LEVEL_ICON_DISTANCE_Y - (TOH_NO_LEVELS - i + 1) * iwidth;
        y = TOH_LEVEL_BAR_START_Y + ((TOH_LEVEL_BAR_HEIGHT - iheight) >> 1);
        gui_show_transparent_image(x, y, (PU8) GetImage(IMG_GX_TOH_LEVEL_HL), 0);
        i--;
    }

}


/*****************************************************************************
 * FUNCTION
 *  TOH_Draw_Background
 * DESCRIPTION
 *  Draw TOH Background Image Contains The Portion After Title And Level Bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TOH_Draw_Background(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iwidth, iheight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_measure_image((PU8) GetImage(IMG_GX_TOH_BG), &iwidth, &iheight);

    gui_set_clip(TOH_BACKGROUND_X, TOH_BACKGROUND_Y, TOH_BACKGROUND_Y + iwidth, TOH_BACKGROUND_Y + iheight);

    gui_show_transparent_image(TOH_BACKGROUND_X, TOH_BACKGROUND_Y, (PU8) GetImage(IMG_GX_TOH_BG), 0);
}

const UI_filled_area toh_time_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_TYPE_NO_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {100, 100, 100, 100},
    {255, 255, 255, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};

const color toh_time_text_color = {0, 0, 0, 100};


/*****************************************************************************
 * FUNCTION
 *  TOH_Draw_Timer
 * DESCRIPTION
 *  Redraw The Timer Text On Timer Bar And Start The Timer Count Callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TOH_Draw_Timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TOH_Display_Time();
    gui_start_timer(1000, TOH_Display_Time);
}


/*****************************************************************************
 * FUNCTION
 *  TOH_Display_Time
 * DESCRIPTION
 *  Draw The Timer Count After 1 Sec Interval.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TOH_Display_Time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 string_width;
    S32 string_height;
    S32 character_height;
    UI_character_type secs[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(TOH_Display_Time);
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    gui_reset_text_clip();

    toh_time_info.startx = TOH_TIME_BAR_X;
    toh_time_info.starty = TOH_TIME_BAR_Y;
    toh_time_info.endx = TOH_TIME_BAR_X + TOH_TIME_BAR_WIDTH - 1;
    toh_time_info.endy = TOH_TIME_BAR_Y + TOH_TIME_BAR_HEIGHT - 1;

    if (toh_game_time)
    {
        gui_set_clip(toh_time_info.startx, toh_time_info.starty, toh_time_info.endx, toh_time_info.endy);

        gui_fill_rectangle(
            toh_time_info.startx,
            toh_time_info.starty,
            toh_time_info.endx,
            toh_time_info.endy,
            gui_color(255, 255, 255));
    }

    gui_set_font(&MMI_medium_font);
    gui_itoa(++toh_game_time, secs, 10);
    toh_idle_time++;

    gui_measure_string(secs, &string_width, &string_height);
    character_height = gui_get_character_height();

    gui_reset_text_clip();

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(
            TOH_TIME_BAR_X + ((TOH_TIME_BAR_WIDTH - string_width) >> 1) + string_width,
            TOH_TIME_BAR_Y + ((TOH_TIME_BAR_HEIGHT - string_height) >> 1));
    }
    else
    {
        gui_move_text_cursor(
            TOH_TIME_BAR_X + ((TOH_TIME_BAR_WIDTH - string_width) >> 1),
            TOH_TIME_BAR_Y + ((TOH_TIME_BAR_HEIGHT - string_height) >> 1));
    }

    gui_set_text_color(gui_color(0, 0, 0));
    gui_print_text(secs);

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(toh_time_info.startx, toh_time_info.starty, toh_time_info.endx, toh_time_info.endy);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

    if (toh_idle_time >= TOH_IDEL_TIME_LIMIT)
    {
        GoBackHistory();
    }
    else
    {
        gui_start_timer(1000, TOH_Display_Time);
    }

}


/*****************************************************************************
 * FUNCTION
 *  TOH_Draw_Tower
 * DESCRIPTION
 *  Draw Vertical Tower Bars.
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void TOH_Draw_Tower(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iwidth, iheight, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_measure_image((PU8) GetImage(IMG_GX_TOH_TOWER), &iwidth, &iheight);

    for (i = 0; i < TOTAL_TOH_TOWERS; i++)
    {
        gui_set_clip(
            toh_towers_bottom_x[i] - (iwidth >> 1),
            TOH_TOWER_BAR_Y - iheight,
            toh_towers_bottom_x[i] + (iwidth >> 1),
            TOH_TOWER_BAR_Y);

        gui_show_transparent_image(
            toh_towers_bottom_x[i] - (iwidth >> 1),
            TOH_TOWER_BAR_Y - iheight,
            (PU8) GetImage(IMG_GX_TOH_TOWER),
            0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  TOH_Draw_Brick
 * DESCRIPTION
 *  Draw Bricks On The Vertical Title Bar.
 * PARAMETERS
 *  tower               [IN]        
 *  brick               [IN]        
 *  position            [IN]        
 *  is_highlighted      [IN]        
 *  is_top              [IN]        
 *  get_bg              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void TOH_Draw_Brick(
        TOH_TOWERS_ENUM tower,
        TOH_BRICKS_ENUM brick,
        S32 position,
        S32 is_highlighted,
        S32 is_top,
        S32 get_bg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 brick_image;
    S32 iwidth, iheight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    if (is_highlighted == HIGHLIGHTED)
    {
        brick_image = toh_brick_image_h[brick];
    }
    else
    {
        brick_image = toh_brick_image[brick];
    }

    iwidth = toh_brick_width[brick];
    iheight = toh_brick_height;
    /* gui_measure_image(brick_image,&iwidth,&iheight); */
    if (is_top == ON_TOP)
    {
        S32 iwidth1, iheight1;

        gui_measure_image((PU8) GetImage(IMG_GX_TOH_TOWER), &iwidth1, &iheight1);
        toh_brick_bitmap_info[brick].startx = toh_towers_bottom_x[tower] - (iwidth >> 1);
        toh_brick_bitmap_info[brick].starty = TOH_TOWER_BAR_Y - iheight1;
        toh_brick_bitmap_info[brick].endx = toh_brick_bitmap_info[brick].startx + iwidth - 1;
        toh_brick_bitmap_info[brick].endy = toh_brick_bitmap_info[brick].starty + iheight - 1;
    }
    else
    {
        toh_brick_bitmap_info[brick].startx = toh_towers_bottom_x[tower] - (iwidth >> 1);
        toh_brick_bitmap_info[brick].starty = TOH_TOWER_BAR_Y - (position + 1) * (TOH_DISTANCE_BRICKS + iheight);
        toh_brick_bitmap_info[brick].endx = toh_brick_bitmap_info[brick].startx + iwidth - 1;
        toh_brick_bitmap_info[brick].endy = toh_brick_bitmap_info[brick].starty + iheight - 1;
    }

    gui_set_clip(
        toh_brick_bitmap_info[brick].startx,
        toh_brick_bitmap_info[brick].starty,
        toh_brick_bitmap_info[brick].endx,
        toh_brick_bitmap_info[brick].endy);

    /* gui_set_clip(toh_towers_bottom_x[tower] - (iwidth>>1),
       TOH_TOWER_BAR_Y - position * (TOH_DISTANCE_BRICKS + iheight) ,
       toh_towers_bottom_x[tower] + (iwidth>>1),
       TOH_TOWER_BAR_Y - position * (TOH_DISTANCE_BRICKS)
       ); */

    /* toh_brick_bitmap_info[brick].noofbytesrequired=(toh_brick_bitmap_info[brick].endx-toh_brick_bitmap_info[brick].startx)*
       (toh_brick_bitmap_info[brick].endy-toh_brick_bitmap_info[brick].starty)*BYTES_PER_PIXEL; */
    /* temp_bitmap=toh_brick_bitmap_info[brick].bgbitmap; */

    if (get_bg == SAVE_BG)
    {
        _get_bitmap(
            toh_brick_bitmap_info[brick].startx,
            toh_brick_bitmap_info[brick].starty,
            toh_brick_bitmap_info[brick].endx,
            toh_brick_bitmap_info[brick].endy,
            &toh_brick_bitmap_info[brick].bgbitmap);
    }
    /* toh_brick_bitmap_info[brick].bgbitmap=temp_bitmap; */

    gui_show_transparent_image(
        toh_brick_bitmap_info[brick].startx,
        toh_brick_bitmap_info[brick].starty,
        brick_image,
        0);
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(
        toh_brick_bitmap_info[brick].startx,
        toh_brick_bitmap_info[brick].starty,
        toh_brick_bitmap_info[brick].endx,
        toh_brick_bitmap_info[brick].endy);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

}


/*****************************************************************************
 * FUNCTION
 *  TOH_Redraw_Bg_Brick_Area
 * DESCRIPTION
 *  TOH Back Ground Area Need To Redraw After Movement Of Bricks.
 *  This API redraw the Background.
 * PARAMETERS
 *  brick       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void TOH_Redraw_Bg_Brick_Area(TOH_BRICKS_ENUM brick)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    gui_set_clip(
        toh_brick_bitmap_info[brick].startx,
        toh_brick_bitmap_info[brick].starty,
        toh_brick_bitmap_info[brick].endx,
        toh_brick_bitmap_info[brick].endy);

    _show_bitmap(
        toh_brick_bitmap_info[brick].startx,
        toh_brick_bitmap_info[brick].starty,
        &toh_brick_bitmap_info[brick].bgbitmap);

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(
        toh_brick_bitmap_info[brick].startx,
        toh_brick_bitmap_info[brick].starty,
        toh_brick_bitmap_info[brick].endx,
        toh_brick_bitmap_info[brick].endy);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  TOH_Left_Arrow
 * DESCRIPTION
 *  Move The Brick To Left If It Is Not The On The Leftmost Title Bar.
 *  Otherwise An Error Sound Played.
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void TOH_Left_Arrow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    toh_idle_time = 0;  /* have movement, reset idle time */

    if (toh_selected_Tower_brick_on_top[toh_selecte_tower] == TRUE && toh_selecte_tower > TOH_TOWER1)
    {
        S32 brick, brick_position;

    #ifdef __MMI_GAME_MULTICHANNEL_SOUND__
        GFX_STOP_SOUND_EFFECTS_MIDI(move_midi);
        GFX_STOP_SOUND_EFFECTS_MIDI(cantmove_midi);

        GFX_PLAY_SOUND_EFFECTS_MIDI(move_midi);
    #else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
        GFX_PLAY_AUDIO_MIDI(TOHMove, TOHMOVE, DEVICE_AUDIO_PLAY_ONCE);
    #endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

        brick_position = toh_present_brick_num[toh_selecte_tower] - 1;
        brick = toh_present_brick_condition[brick_position][toh_selecte_tower];
        toh_present_brick_num[toh_selecte_tower]--;
        toh_selected_Tower_brick_on_top[toh_selecte_tower] = FALSE;
        toh_selecte_tower--;
        TOH_Draw_Tower_Indicator(toh_selecte_tower);
        toh_present_brick_condition[toh_present_brick_num[toh_selecte_tower]][toh_selecte_tower] = brick;
        toh_present_brick_num[toh_selecte_tower]++;
        TOH_Redraw_Bg_Brick_Area(brick);
        TOH_Draw_Brick(toh_selecte_tower, brick, 0, HIGHLIGHTED, ON_TOP, SAVE_BG);
        toh_selected_Tower_brick_on_top[toh_selecte_tower] = TRUE;

    }
    else if (toh_selected_Tower_brick_on_top[toh_selecte_tower] == FALSE && toh_selecte_tower > TOH_TOWER1)
    {
        S32 brick, brick_position;

        brick_position = toh_present_brick_num[toh_selecte_tower] - 1;
        brick = toh_present_brick_condition[brick_position][toh_selecte_tower];
        if (toh_present_brick_num[toh_selecte_tower] > 0 &&
            (brick_position == 0 || brick < toh_present_brick_condition[brick_position - 1][toh_selecte_tower]))
        {
            TOH_Redraw_Bg_Brick_Area(brick);
            TOH_Draw_Brick(toh_selecte_tower, brick, brick_position, NOT_HIGHLIGHTED, NOT_ON_TOP, DONT_SAVE_BG);
            toh_selected_Tower_brick_on_top[toh_selecte_tower] = FALSE;
        }
        toh_selecte_tower--;
        TOH_Draw_Tower_Indicator(toh_selecte_tower);
        brick_position = toh_present_brick_num[toh_selecte_tower] - 1;
        brick = toh_present_brick_condition[brick_position][toh_selecte_tower];
        if (toh_present_brick_num[toh_selecte_tower] > 0 &&
            (brick_position == 0 || brick < toh_present_brick_condition[brick_position - 1][toh_selecte_tower]))
        {
            TOH_Redraw_Bg_Brick_Area(brick);
            TOH_Draw_Brick(toh_selecte_tower, brick, brick_position, HIGHLIGHTED, NOT_ON_TOP, DONT_SAVE_BG);
            toh_selected_Tower_brick_on_top[toh_selecte_tower] = FALSE;
        }

    }
    else
    {
    #ifdef __MMI_GAME_MULTICHANNEL_SOUND__
        GFX_STOP_SOUND_EFFECTS_MIDI(move_midi);
        GFX_STOP_SOUND_EFFECTS_MIDI(cantmove_midi);

        GFX_PLAY_SOUND_EFFECTS_MIDI(cantmove_midi);
    #else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
        GFX_PLAY_AUDIO_MIDI(TOHCantMove, TOHCANTMOVE, DEVICE_AUDIO_PLAY_ONCE);
    #endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  TOH_Right_Arrow
 * DESCRIPTION
 *  Move The Brick To Right If It Is Not The On The Rightmost Title Bar.
 *  Otherwise An Error Sound Played.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TOH_Right_Arrow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    toh_idle_time = 0;  /* have movement, reset idle time */

    if (toh_selected_Tower_brick_on_top[toh_selecte_tower] == TRUE && toh_selecte_tower < TOH_TOWER3)
    {
        S32 brick, brick_position;

    #ifdef __MMI_GAME_MULTICHANNEL_SOUND__
        GFX_STOP_SOUND_EFFECTS_MIDI(move_midi);
        GFX_STOP_SOUND_EFFECTS_MIDI(cantmove_midi);

        GFX_PLAY_SOUND_EFFECTS_MIDI(move_midi);
    #else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
        GFX_PLAY_AUDIO_MIDI(TOHMove, TOHMOVE, DEVICE_AUDIO_PLAY_ONCE);
    #endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

        brick_position = toh_present_brick_num[toh_selecte_tower] - 1;
        brick = toh_present_brick_condition[brick_position][toh_selecte_tower];
        toh_present_brick_num[toh_selecte_tower]--;
        toh_selected_Tower_brick_on_top[toh_selecte_tower] = FALSE;
        toh_selecte_tower++;
        TOH_Draw_Tower_Indicator(toh_selecte_tower);
        toh_present_brick_condition[toh_present_brick_num[toh_selecte_tower]][toh_selecte_tower] = brick;
        toh_present_brick_num[toh_selecte_tower]++;
        TOH_Redraw_Bg_Brick_Area(brick);
        TOH_Draw_Brick(toh_selecte_tower, brick, 0, HIGHLIGHTED, ON_TOP, SAVE_BG);
        toh_selected_Tower_brick_on_top[toh_selecte_tower] = TRUE;
    }
    else if (toh_selected_Tower_brick_on_top[toh_selecte_tower] == FALSE && toh_selecte_tower < TOH_TOWER3)
    {
        S32 brick, brick_position;

        brick_position = toh_present_brick_num[toh_selecte_tower] - 1;
        brick = toh_present_brick_condition[brick_position][toh_selecte_tower];
        if (toh_present_brick_num[toh_selecte_tower] > 0 &&
            (brick_position == 0 || brick < toh_present_brick_condition[brick_position - 1][toh_selecte_tower]))
        {
            TOH_Redraw_Bg_Brick_Area(brick);
            TOH_Draw_Brick(toh_selecte_tower, brick, brick_position, NOT_HIGHLIGHTED, NOT_ON_TOP, DONT_SAVE_BG);
            toh_selected_Tower_brick_on_top[toh_selecte_tower] = FALSE;
        }
        toh_selecte_tower++;
        TOH_Draw_Tower_Indicator(toh_selecte_tower);
        brick_position = toh_present_brick_num[toh_selecte_tower] - 1;
        brick = toh_present_brick_condition[brick_position][toh_selecte_tower];
        if (toh_present_brick_num[toh_selecte_tower] > 0 &&
            (brick_position == 0 || brick < toh_present_brick_condition[brick_position - 1][toh_selecte_tower]))
        {
            TOH_Redraw_Bg_Brick_Area(brick);
            TOH_Draw_Brick(toh_selecte_tower, brick, brick_position, HIGHLIGHTED, NOT_ON_TOP, DONT_SAVE_BG);
            toh_selected_Tower_brick_on_top[toh_selecte_tower] = FALSE;
        }
    }
    else
    {
    #ifdef __MMI_GAME_MULTICHANNEL_SOUND__
        GFX_STOP_SOUND_EFFECTS_MIDI(move_midi);
        GFX_STOP_SOUND_EFFECTS_MIDI(cantmove_midi);

        GFX_PLAY_SOUND_EFFECTS_MIDI(cantmove_midi);
    #else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
        GFX_PLAY_AUDIO_MIDI(TOHCantMove, TOHCANTMOVE, DEVICE_AUDIO_PLAY_ONCE);
    #endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

    }
}


/*****************************************************************************
 * FUNCTION
 *  TOH_Up_Arrow
 * DESCRIPTION
 *  Lift The Bar Up If Any Bar Is Present On The Tower And Pointer Is Empty.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TOH_Up_Arrow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    toh_idle_time = 0;  /* have movement, reset idle time */

    if (toh_selected_Tower_brick_on_top[toh_selecte_tower] == FALSE && toh_present_brick_num[toh_selecte_tower] > 0)
    {
        S32 brick, brick_position;

    #ifdef __MMI_GAME_MULTICHANNEL_SOUND__
        GFX_STOP_SOUND_EFFECTS_MIDI(move_midi);
        GFX_STOP_SOUND_EFFECTS_MIDI(cantmove_midi);

        GFX_PLAY_SOUND_EFFECTS_MIDI(move_midi);
    #else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
        GFX_PLAY_AUDIO_MIDI(TOHMove, TOHMOVE, DEVICE_AUDIO_PLAY_ONCE);
    #endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

        brick_position = toh_present_brick_num[toh_selecte_tower] - 1;
        brick = toh_present_brick_condition[brick_position][toh_selecte_tower];
        TOH_Redraw_Bg_Brick_Area(brick);
        TOH_Draw_Brick(toh_selecte_tower, brick, 0, HIGHLIGHTED, ON_TOP, SAVE_BG);
        toh_selected_Tower_brick_on_top[toh_selecte_tower] = TRUE;
    }
    else
    {
    #ifdef __MMI_GAME_MULTICHANNEL_SOUND__
        GFX_STOP_SOUND_EFFECTS_MIDI(move_midi);
        GFX_STOP_SOUND_EFFECTS_MIDI(cantmove_midi);

        GFX_PLAY_SOUND_EFFECTS_MIDI(cantmove_midi);
    #else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
        GFX_PLAY_AUDIO_MIDI(TOHCantMove, TOHCANTMOVE, DEVICE_AUDIO_PLAY_ONCE);
    #endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

    }
}


/*****************************************************************************
 * FUNCTION
 *  TOH_Down_Arrow
 * DESCRIPTION
 *  Drop The Bar Down To Tower If No Bar Is Present Or Bar Is Bigger Then The
 *  Pointed Bar.
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void TOH_Down_Arrow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    toh_idle_time = 0;  /* have movement, reset idle time */

    if (toh_selected_Tower_brick_on_top[toh_selecte_tower] == TRUE && toh_present_brick_num[toh_selecte_tower] > 0)
    {
        S32 brick, brick_position;

        brick_position = toh_present_brick_num[toh_selecte_tower] - 1;
        brick = toh_present_brick_condition[brick_position][toh_selecte_tower];
        if (toh_present_brick_num[toh_selecte_tower] > 0 &&
            (brick_position == 0 || brick < toh_present_brick_condition[brick_position - 1][toh_selecte_tower]))
        {

        #ifdef __MMI_GAME_MULTICHANNEL_SOUND__
            GFX_STOP_SOUND_EFFECTS_MIDI(move_midi);
            GFX_STOP_SOUND_EFFECTS_MIDI(cantmove_midi);

            GFX_PLAY_SOUND_EFFECTS_MIDI(move_midi);
        #else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
            GFX_PLAY_AUDIO_MIDI(TOHMove, TOHMOVE, DEVICE_AUDIO_PLAY_ONCE);
        #endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

            TOH_Redraw_Bg_Brick_Area(brick);
            TOH_Draw_Brick(toh_selecte_tower, brick, brick_position, HIGHLIGHTED, NOT_ON_TOP, SAVE_BG);
            toh_selected_Tower_brick_on_top[toh_selecte_tower] = FALSE;
            if (toh_present_brick_num[TOH_TOWER3] == toh_max_bricks_in_game ||
                toh_present_brick_num[TOH_TOWER2] == toh_max_bricks_in_game)
            {
                TOH_End_Game();
            }
        }
        else
        {
        #ifdef __MMI_GAME_MULTICHANNEL_SOUND__
            GFX_STOP_SOUND_EFFECTS_MIDI(move_midi);
            GFX_STOP_SOUND_EFFECTS_MIDI(cantmove_midi);

            GFX_PLAY_SOUND_EFFECTS_MIDI(cantmove_midi);
        #else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
            GFX_PLAY_AUDIO_MIDI(TOHCantMove, TOHCANTMOVE, DEVICE_AUDIO_PLAY_ONCE);
        #endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

        }
    }
    else
    {
    #ifdef __MMI_GAME_MULTICHANNEL_SOUND__
        GFX_STOP_SOUND_EFFECTS_MIDI(move_midi);
        GFX_STOP_SOUND_EFFECTS_MIDI(cantmove_midi);

        GFX_PLAY_SOUND_EFFECTS_MIDI(cantmove_midi);
    #else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
        GFX_PLAY_AUDIO_MIDI(TOHCantMove, TOHCANTMOVE, DEVICE_AUDIO_PLAY_ONCE);
    #endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  TOH_End_Game
 * DESCRIPTION
 *  Call The Game End Framework Function.
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void TOH_End_Game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_gfx_entry_gameover_screen();
}


/*****************************************************************************
 * FUNCTION
 *  TOH_DeInit_Variable
 * DESCRIPTION
 *  Reset The New Game Variable To True On Game Over.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TOH_DeInit_Variable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (toh_is_new_game == FALSE)
    {
        toh_is_new_game = TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  TOH_Draw_Tower_Indicator
 * DESCRIPTION
 *  Shows The Hand Pointer On Top Of The Tower To Indicate The Current
 *  Position.
 * PARAMETERS
 *  tower       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void TOH_Draw_Tower_Indicator(TOH_TOWERS_ENUM tower)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iwidth, iheight, iwidth1, iheight1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    gui_measure_image((PU8) GetImage(IMG_GX_TOH_TOWER), &iwidth1, &iheight1);
    gui_measure_image((PU8) GetImage(IMG_GX_TOH_TOWER_IN), &iwidth, &iheight);
    if (toh_game_time)
    {
        gui_set_clip(
            toh_tower_in_bitmap_info.startx,
            toh_tower_in_bitmap_info.starty,
            toh_tower_in_bitmap_info.endx,
            toh_tower_in_bitmap_info.endy);
        /* _show_bitmap(toh_tower_in_bitmap_info.startx,toh_tower_in_bitmap_info.starty,&toh_tower_in_bitmap_info.bgbitmap); */
        gui_fill_rectangle(
            toh_tower_in_bitmap_info.startx,
            toh_tower_in_bitmap_info.starty,
            toh_tower_in_bitmap_info.endx,
            toh_tower_in_bitmap_info.endy,
            gui_color(255, 255, 255));

        gui_BLT_double_buffer(
            toh_tower_in_bitmap_info.startx,
            toh_tower_in_bitmap_info.starty,
            toh_tower_in_bitmap_info.endx,
            toh_tower_in_bitmap_info.endy);
    }

    toh_tower_in_bitmap_info.startx = toh_towers_bottom_x[tower] - (iwidth >> 1);
    toh_tower_in_bitmap_info.starty = TOH_TOWER_BAR_Y - iheight1 - iheight - TOH_INDICATOR_GAP;
    toh_tower_in_bitmap_info.endx = toh_tower_in_bitmap_info.startx + iwidth - 1;
    toh_tower_in_bitmap_info.endy = toh_tower_in_bitmap_info.starty + iheight - 1;

    gui_set_clip(
        toh_tower_in_bitmap_info.startx,
        toh_tower_in_bitmap_info.starty,
        toh_tower_in_bitmap_info.endx,
        toh_tower_in_bitmap_info.endy);

    //      _get_bitmap(toh_tower_in_bitmap_info.startx,toh_tower_in_bitmap_info.starty,
    //                              toh_tower_in_bitmap_info.endx,toh_tower_in_bitmap_info.endy,&toh_tower_in_bitmap_info.bgbitmap);

    gui_show_transparent_image(
        toh_tower_in_bitmap_info.startx,
        toh_tower_in_bitmap_info.starty,
        (PU8) GetImage(IMG_GX_TOH_TOWER_IN),
        0);
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(
        toh_tower_in_bitmap_info.startx,
        toh_tower_in_bitmap_info.starty,
        toh_tower_in_bitmap_info.endx,
        toh_tower_in_bitmap_info.endy);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}

#endif /* IS_HANOI_BASE_GAME */ 

