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
 *  Snake.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Snake Game 
 *
 * Author:
  * -------
  * Bear (MTK00612)
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

#ifdef __MMI_GAME_SNAKE__
#include "GameInc.h"
#include "SnakeProts.h"
#include "mmi_rp_app_games_def.h"
#include "SnakeConst.h"
#include "ScreenSaverDefs.h"

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
#include "GameProts.h"
#endif

/************************************************************************/
/* game multi language support                                                         */
/************************************************************************/
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
typedef enum
{
    MMI_SNAKE_STRING_GOTEXT ,
    MMI_SNAKE_STRING_STAGE,
    MMI_SNAKE_STRING_TOTAL
}mmi_snake_string_enum;
#endif

/************************************************************************/
/* Game Defines                                                         */
/************************************************************************/
/* grid size */
#define SNAKE_GRID_ROW_COUNT  19
#define SNAKE_GRID_COL_COUNT  23
#define SNAKE_GRID_CELL_SIZE  5
#define SNAKE_GRID_START_X    5
#define SNAKE_GRID_START_Y    5
#define SNAKE_SPACE_START_X   SNAKE_GRID_START_X+1
#define SNAKE_SPACE_START_Y   SNAKE_GRID_START_Y+1

/* snake move direction */
#define SNAKE_DIRECTION_UP          0
#define SNAKE_DIRECTION_DOWN        1
#define SNAKE_DIRECTION_RIGHT       2
#define SNAKE_DIRECTION_LEFT        3
#define SNAKE_DIRECTION_UP_RIGHT    4
#define SNAKE_DIRECTION_UP_LEFT     5
#define SNAKE_DIRECTION_DOWN_RIGHT  6
#define SNAKE_DIRECTION_DOWN_LEFT   7
#define SNAKE_DIRECTION_NONE        8

/* snake level & speed */
#define SNAKE_GAME_SPEED_EASY       300
#define SNAKE_GAME_SPEED_NORMAL     230
#define SNAKE_GAME_SPEED_HARD       180
#define SNAKE_GAME_SPEED_LIMIT      150
#define SNAKE_LEVEL_COUNT           3

#define SNAKE_GAME_LEVEL_EASY       (0) /* Level 1 */
#define SNAKE_GAME_LEVEL_NORMAL     (1) /* Level 2 */
#define SNAKE_GAME_LEVEL_HARD       (2) /* Level 3 */

/* snake null next index, used to show the tail and none use slot */
#define SNAKE_NEXT_INDEX_NULL    (0x07ff)

/************************************************************************/
/* Macros                                                */
/************************************************************************/

/* transfrom the position from index to x and y */
#define CALCULATE_RENDER_POSITION(x, y, index)           \
{                                                        \
   x = index%SNAKE_GRID_COL_COUNT;                       \
   x *= SNAKE_GRID_CELL_SIZE;                            \
   x += SNAKE_SPACE_START_X;                             \
   y = index/SNAKE_GRID_COL_COUNT;                       \
   y *= SNAKE_GRID_CELL_SIZE;                            \
   y += SNAKE_SPACE_START_Y;                             \
}                                                        \

/* marco to get easy stage info */
#define SNAKE_GET_STAGE_CASE_EASY(index)          \
{                                                 \
   case index:                                    \
      *count = sizeof(snake_stage_easy_##index)/2;\
      return (S16*)snake_stage_easy_##index;      \
      break;                                      \
}

/* marco to get  normal stage info */
#define SNAKE_GET_STAGE_CASE_NORMAL(index)          \
{                                                   \
   case index:                                      \
      *count = sizeof(snake_stage_normal_##index)/2;\
      return (S16*)snake_stage_normal_##index;      \
      break;                                        \
}

/* marco to get  hard stage info */
#define SNAKE_GET_STAGE_CASE_HARD(index)          \
{                                                 \
   case index:                                    \
      *count = sizeof(snake_stage_hard_##index)/2;\
      return (S16*)snake_stage_hard_##index;      \
      break;                                      \
}

/************************************************************************/
/* Structure                                             */
/************************************************************************/
/* structure for snake node. use bitwise data to reduce memory usage */
typedef struct
{
    unsigned next_index:11;
    unsigned need_update_render:1;
    unsigned direction:4;
} snake_node;

/************************************************************************/
/* Golbal Varable [Const]                                   */
/************************************************************************/
/* colors to draw background */
const color snake_bg_color = {255, 220, 210, 100};
const UI_filled_area snake_border =
    {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_DOUBLE_BORDER | UI_FILLED_AREA_SHADOW |
UI_FILLED_AREA_SHADOW_DOUBLE_LINE | UI_FILLED_AREA_ROUNDED_BORDER,
    UI_IMAGE_ID_NULL,
    NULL,
    {255, 220, 210, 100},
    {0, 0, 0, 100},
    {200, 0, 0, 50},
    {50, 50, 50, 30},
    0
};

const UI_filled_area score_border = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_ROUNDED_BORDER,
    UI_IMAGE_ID_NULL,
    NULL,
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    {0, 0, 0, 100},
    0
};

/************************************************************************/
/* Audio [Const]                                         */
/************************************************************************/
#define SNAKEEATEGG           138

__align(2)
     const U8 SnakeEatEgg[138] = 
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

/************************************************************************/
/* Golbal Varable [906 Byte]                                */
/************************************************************************/
/* image ptr for snake images - 14 byte */
static PU8 snake_head_image[4];
static PU8 snake_body_image[6];
static PU8 snake_tail_image[4];

/* Init global variable */
snake_node snake_matrix[SNAKE_GRID_ROW_COUNT * SNAKE_GRID_COL_COUNT];   /* 874 byte */
S16 snake_head_index = 0;
S16 snake_game_speed = 100;
S16 snake_move_direction = SNAKE_DIRECTION_LEFT;
S16 snake_egg_index = 0;
BOOL snake_is_new_game = TRUE;
S16 snake_current_stage = 0;
U8 snake_current_level = SNAKE_GAME_LEVEL_EASY;

/* snake_move_input tries to queue two continouse input direction */
S16 snake_move_input[2] = {SNAKE_DIRECTION_NONE, SNAKE_DIRECTION_NONE};
U8 snake_game_over = FALSE;
U8 snake_new_egg = TRUE;
S16 snake_total_score = 0;

 #if defined (__MMI_GAME_MULTICHANNEL_SOUND__)
S32 eategg_midi;
 #endif 

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
static U16 mmi_snake_language_index;
#define MMI_SNAKE_STRING_COUNT MMI_SNAKE_STRING_TOTAL
#endif

/* auto run test */
/* S16 snake_auto_move_dir[SNAKE_GRID_ROW_COUNT*SNAKE_GRID_COL_COUNT]; */
/* call this function for auto run test, avoid blacklight shutdown */
/* extern void SetBacklightModeExe(U8 mode); */

/************************************************************************/
/* Function Declare                                      */
/************************************************************************/
/* Game framework related functions */
void Snake_Enter_GFX(void);
void Snake_Draw_GameOver(void);
void Snake_Enter_Game(void);
void Snake_Exit_Game(void);

/* Game play functions */
void Snake_Main(void);
S16 *Snake_Get_Stage_Ptr(S16 *count);
S16 Snake_Calc_Best_Grade(S16 old_grade, S16 new_grade);
void Snake_Calc_Egg_Position(void);
void Snake_Init(void);
void Snake_Render_Status(void);
void Snake_Render_Background(void);
void Snake_Render_Wall(void);
void Snake_Render_Egg(void);
void Snake_Render_Snake(void);
void Snake_Framemove(void);
void Snake_Cyclic_Timer(void);
void Snake_Gameover(void);
void Snake_Key_Direction_Handler(S8 input, S8 conflict);
void Snake_Key_Up(void);
void Snake_Key_Down(void);
void Snake_Key_Right(void);
void Snake_Key_Left(void);


/*****************************************************************************
 * FUNCTION
 *  Snake_Enter_GFX
 * DESCRIPTION
 *  Set Game Framework (GFX) Parameter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Snake_Enter_GFX(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Game menu */
    GFX.game_data.game_img_id = IMG_GX_SNAKE_GAME_ICON; /* game icon img ID */
    GFX.game_data.game_str_id = STR_GX_SNAKE_GAME_NAME; /* game name string ID */
    GFX.game_data.menu_resume_str_id = STR_GAME_RESUME; /* "Resume" string ID */
    GFX.game_data.menu_new_str_id = STR_GAME_NEW;       /* "New Game" string ID */
    GFX.game_data.menu_level_str_id = STR_GAME_LEVEL;   /* "Game Level" string ID */
    GFX.game_data.menu_grade_str_id = STR_GAME_GRADE;   /* "Best Grade" string ID */
    GFX.game_data.menu_help_str_id = STR_GLOBAL_HELP;     /* "Game Help string ID */

    /* level / grade */
    GFX.game_data.level_count = 3;                          /* how many levels */
    GFX.game_data.level_str_id_list[0] = STR_GX_SNAKE_EASY; /* level string ID */
    GFX.game_data.level_str_id_list[1] = STR_GX_SNAKE_NORMAL;   /* level string ID */
    GFX.game_data.level_str_id_list[2] = STR_GX_SNAKE_HARD; /* level string ID */

    GFX.game_data.grade_nvram_id_list[0] = NVRAM_SNAKE_LEVEL1_SCORE;    /* grade slot in NVRAM */
    GFX.game_data.grade_nvram_id_list[1] = NVRAM_SNAKE_LEVEL2_SCORE;    /* grade slot in NVRAM */
    GFX.game_data.grade_nvram_id_list[2] = NVRAM_SNAKE_LEVEL3_SCORE;    /* grade slot in NVRAM */
    GFX.game_data.level_nvram_id = NVRAM_GAME_SNAKE_LEVEL;  /* current lvl idnex stored in NVRAM */

    /* help */
    GFX.game_data.help_str_id = STR_GX_SNAKE_HELP_DESCRIPTION;  /* help desciption string id */

    /* misc */
    GFX.game_data.grade_value_ptr = (S16*) (&snake_total_score);       /* current level's grade (S16*) */
    GFX.game_data.level_index_ptr = (U8*) (&snake_current_level);      /* ptr to current level index (U8*) */
    GFX.game_data.is_new_game = (BOOL*) & snake_is_new_game;   /* ptr to new game flag (BOOL*) */

    /* function ptr */
    GFX.game_data.best_grade_func_ptr = Snake_Calc_Best_Grade;  /* function to calculate best grade */
    GFX.game_data.enter_game_func_ptr = Snake_Enter_Game;   /* function to enter new game */
    GFX.game_data.exit_game_func_ptr = Snake_Exit_Game;     /* function to exit game */
    GFX.game_data.draw_gameover_func_ptr = Snake_Draw_GameOver; /* function to draw gameover screen */

    /* some flags */
    GFX.game_data.is_keypad_audio_enable = TRUE;    /* play keypad tone or not */

    mmi_gfx_entry_menu_screen();
}


/*****************************************************************************
 * FUNCTION
 *  Snake_Calc_Best_Grade
 * DESCRIPTION
 *  Calculate new best grade [Callback required by GFX]
 * PARAMETERS
 *  old_grade       [IN]        
 *  new_grade       [IN]        
 * RETURNS
 *  S16
 *****************************************************************************/
S16 Snake_Calc_Best_Grade(S16 old_grade, S16 new_grade)
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
 *  Snake_Draw_GameOver
 * DESCRIPTION
 *  Draw Gameover Screen [Callback required by GFX]
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Snake_Draw_GameOver(void)
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
    mmi_gfx_draw_gameover_screen(IMG_GX_SNAKE_GOTEXT, IMG_GX_SNAKE_GRADESMAP, IMG_GX_SNAKE_GOPIC, snake_total_score);
#else
    mmi_gfx_draw_gameover_screen(
        mmi_gfx_get_multilanguage_image_ID(
         mmi_snake_language_index,
         IMG_GX_SNAKE_GOTEXT_LANGUAGE0, 
         MMI_SNAKE_STRING_COUNT,
         MMI_SNAKE_STRING_GOTEXT),
        IMG_GX_SNAKE_GRADESMAP, 
        IMG_GX_SNAKE_GOPIC, 
        snake_total_score);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  Snake_Enter_Game
 * DESCRIPTION
 *  Enter Game [Callback required by GFX]
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Snake_Enter_Game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_screen();

    SetKeyHandler(GoBackHistory, KEY_LSK, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_RSK, KEY_EVENT_UP);

    SetKeyHandler(Snake_Key_Up, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Snake_Key_Down, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Snake_Key_Right, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Snake_Key_Left, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(Snake_Key_Up, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(Snake_Key_Down, KEY_8, KEY_EVENT_DOWN);
    SetKeyHandler(Snake_Key_Right, KEY_6, KEY_EVENT_DOWN);
    SetKeyHandler(Snake_Key_Left, KEY_4, KEY_EVENT_DOWN);

#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    GFX_OPEN_SOUND_EFFECTS_MIDI(SnakeEatEgg, SNAKEEATEGG, 1, eategg_midi);
#endif 

    Snake_Main();
}


/*****************************************************************************
 * FUNCTION
 *  Snake_Exit_Game
 * DESCRIPTION
 *  Exit Game [Callback required by GFX]
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Snake_Exit_Game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(Snake_Cyclic_Timer);
#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    GFX_STOP_SOUND_EFFECTS_MIDI(eategg_midi);
    GFX_CLOSE_SOUND_EFFECTS_MIDI(eategg_midi);
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  Snake_Main
 * DESCRIPTION
 *  Snake Main function
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Snake_Main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Init Snake Game parameters */
    if (snake_is_new_game == TRUE)
    {
        Snake_Init();
        snake_is_new_game = FALSE;
    }

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    mmi_snake_language_index = g_mmi_game_current_language_index;
    mmi_gfx_check_image_get_valid_language(
        &mmi_snake_language_index, 
        IMG_GX_SNAKE_GOTEXT_LANGUAGE0, 
        MMI_SNAKE_STRING_COUNT);
#endif

    /* refresh whole snake's update render flag */
    index = snake_head_index;

    while (1)
    {
        if (snake_matrix[index].next_index == SNAKE_NEXT_INDEX_NULL)
        {
            snake_matrix[index].need_update_render = TRUE;
            break;
        }

        snake_matrix[index].need_update_render = TRUE;
        index = snake_matrix[index].next_index;
    }

    gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);
    Snake_Render_Background();
    Snake_Render_Wall();
    Snake_Render_Snake();
    Snake_Render_Egg();

    gui_start_timer(snake_game_speed, Snake_Cyclic_Timer);
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  Snake_Get_Stage_Ptr
 * DESCRIPTION
 *  Get the stage ptr index based on different game level
 * PARAMETERS
 *  count       [?]     
 * RETURNS
 *  S16*
 *****************************************************************************/
S16 *Snake_Get_Stage_Ptr(S16 *count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (snake_current_level == SNAKE_GAME_LEVEL_EASY)
    {

        /*  init level as empty, for auto run test */
        //   *count = 0;
        //   return (S16*)snake_stage_easy_0;

        switch (snake_current_stage)
        {
                SNAKE_GET_STAGE_CASE_EASY(0);
                SNAKE_GET_STAGE_CASE_EASY(1);
                SNAKE_GET_STAGE_CASE_EASY(2);
                SNAKE_GET_STAGE_CASE_EASY(3);
                SNAKE_GET_STAGE_CASE_EASY(4);
                SNAKE_GET_STAGE_CASE_EASY(5);
                SNAKE_GET_STAGE_CASE_EASY(6);
                SNAKE_GET_STAGE_CASE_EASY(7);
                SNAKE_GET_STAGE_CASE_EASY(8);
                SNAKE_GET_STAGE_CASE_EASY(9);
        }
    }
    else if (snake_current_level == SNAKE_GAME_LEVEL_NORMAL)
    {
        switch (snake_current_stage)
        {
                SNAKE_GET_STAGE_CASE_NORMAL(0);
                SNAKE_GET_STAGE_CASE_NORMAL(1);
                SNAKE_GET_STAGE_CASE_NORMAL(2);
                SNAKE_GET_STAGE_CASE_NORMAL(3);
                SNAKE_GET_STAGE_CASE_NORMAL(4);
                SNAKE_GET_STAGE_CASE_NORMAL(5);
                SNAKE_GET_STAGE_CASE_NORMAL(6);
                SNAKE_GET_STAGE_CASE_NORMAL(7);
                SNAKE_GET_STAGE_CASE_NORMAL(8);
                SNAKE_GET_STAGE_CASE_NORMAL(9);
        }
    }
    else if (snake_current_level == SNAKE_GAME_LEVEL_HARD)
    {
        switch (snake_current_stage)
        {
                SNAKE_GET_STAGE_CASE_HARD(0);
                SNAKE_GET_STAGE_CASE_HARD(1);
                SNAKE_GET_STAGE_CASE_HARD(2);
                SNAKE_GET_STAGE_CASE_HARD(3);
                SNAKE_GET_STAGE_CASE_HARD(4);
                SNAKE_GET_STAGE_CASE_HARD(5);
                SNAKE_GET_STAGE_CASE_HARD(6);
                SNAKE_GET_STAGE_CASE_HARD(7);
                SNAKE_GET_STAGE_CASE_HARD(8);
                SNAKE_GET_STAGE_CASE_HARD(9);
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  Snake_Calc_Egg_Position
 * DESCRIPTION
 *  Calculate next egg appear position
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Snake_Calc_Egg_Position(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 stage_wall_count;
    S16 *pStage_ptr = Snake_Get_Stage_Ptr(&stage_wall_count);
    S16 i, j;
    S16 valid_count;
    BOOL valid_pos;
    S16 valid_table[SNAKE_GRID_ROW_COUNT * SNAKE_GRID_COL_COUNT];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    snake_new_egg = TRUE;

    /* calculate valid entry count to put egg */
    valid_count = 0;

    for (i = 0; i < SNAKE_GRID_ROW_COUNT * SNAKE_GRID_COL_COUNT; i++)
    {
        if (snake_matrix[i].direction != SNAKE_DIRECTION_NONE)  /* inside snake */
        {
            continue;
        }

        /* Chekc if lies inside wall */

        valid_pos = TRUE;
        for (j = 0; j < stage_wall_count; j++)
        {
            if (i == pStage_ptr[j])
            {
                valid_pos = FALSE;
                break;
            }
        }

        if (valid_pos == TRUE)
        {
            valid_table[valid_count] = i;
            valid_count++;
        }
    }

    /* screen is full */
    if (valid_count == 0)
    {
        Snake_Gameover();
        return;
    }

    snake_egg_index = valid_table[(rand() % valid_count)];
}


/*****************************************************************************
 * FUNCTION
 *  Snake_Init
 * DESCRIPTION
 *  Init - Init game parameters when enter new game
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Snake_Init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    U16 id;
    int index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* S16          dx, dy; */

    snake_total_score = 0;
    snake_game_over = FALSE;

    switch (snake_current_level)
    {
        case SNAKE_GAME_LEVEL_EASY:
            snake_game_speed = SNAKE_GAME_SPEED_EASY;
            break;
        case SNAKE_GAME_LEVEL_NORMAL:
            snake_game_speed = SNAKE_GAME_SPEED_NORMAL;
            break;
        case SNAKE_GAME_LEVEL_HARD:
            snake_game_speed = SNAKE_GAME_SPEED_NORMAL;
            break;
        default:
            /* assert, use which one? */
            break;
    }

    /* Clean Snake Matrix */
    for (i = 0; i < SNAKE_GRID_ROW_COUNT * SNAKE_GRID_COL_COUNT; i++)
    {
        snake_matrix[i].direction = SNAKE_DIRECTION_NONE;
        snake_matrix[i].next_index = SNAKE_NEXT_INDEX_NULL;
        snake_matrix[i].need_update_render = FALSE;
    }

    /* Init ImageIndex */
    for (i = 0; i < 4; i++)
    {
        id = IMG_GX_SNAKE_SNAKE_HEAD_UP + i;
        snake_head_image[i] = (PU8) get_image(id);
    }

    for (i = 0; i < 4; i++)
    {
        id = IMG_GX_SNAKE_SNAKE_TAIL_UP + i;
        snake_tail_image[i] = (PU8) get_image(id);
    }

    for (i = 0; i < 6; i++)
    {
        id = IMG_GX_SNAKE_SNAKE_BODY_UP_DOWN + i;
        snake_body_image[i] = (PU8) get_image(id);
    }

    /* Init stage */
    /* Something wrong with rand generator, will gen negative number .. ???? */
    snake_current_stage = rand();
    snake_current_stage++;
    snake_current_stage = (snake_current_stage < 0) ? (-snake_current_stage) : snake_current_stage;

    snake_current_stage %= SNAKE_STAGE_COUNT;

    /* Init First Snake */
    snake_move_direction = SNAKE_DIRECTION_RIGHT;
    snake_head_index = 6;
    index = snake_head_index;

    for (i = 0; i < 6; i++)
    {
        snake_matrix[index].direction = SNAKE_DIRECTION_RIGHT;
        snake_matrix[index].next_index = index - 1;
        snake_matrix[index].need_update_render = TRUE;
        index--;
    }
    snake_matrix[index + 1].next_index = SNAKE_NEXT_INDEX_NULL;

    Snake_Calc_Egg_Position();

    //  /* init auto run test */
    //
    //      for(i = 0; i < SNAKE_GRID_ROW_COUNT*SNAKE_GRID_COL_COUNT; i++)
    //      {
    //              dx = i%SNAKE_GRID_COL_COUNT;
    //              dy = i/SNAKE_GRID_COL_COUNT;
    //
    //              if(dx == 0)
    //              {
    //                      snake_auto_move_dir[i] = SNAKE_DIRECTION_UP;
    //              }
    //              else
    //              {
    //                      if(dy%2 == 0)
    //                      {
    //                              if(dx == (SNAKE_GRID_COL_COUNT-1) )
    //                              {
    //                                      snake_auto_move_dir[i] = SNAKE_DIRECTION_DOWN;  
    //                              }
    //                              else
    //                              {
    //                                      snake_auto_move_dir[i] = SNAKE_DIRECTION_RIGHT;
    //                              }
    //                      }
    //                      else
    //                      {
    //                              if(dx == 1 )
    //                              {
    //                                      if(dy == SNAKE_GRID_ROW_COUNT-1)
    //                                              snake_auto_move_dir[i] = SNAKE_DIRECTION_LEFT;
    //                                      else
    //                                              snake_auto_move_dir[i] = SNAKE_DIRECTION_DOWN;
    //                              }
    //                              else
    //                              {
    //                                      snake_auto_move_dir[i] = SNAKE_DIRECTION_LEFT;
    //                              }
    //                      }
    //              }
    //      }
    //      snake_auto_move_dir[0] = SNAKE_DIRECTION_RIGHT;

}


/*****************************************************************************
 * FUNCTION
 *  Snake_Render_Status
 * DESCRIPTION
 *  Render Status Bar ( stage / score )
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Snake_Render_Status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 x_pos, y_pos;
    S16 score, remain, value;
    MMI_ID_TYPE iamge_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x_pos = 115;
    y_pos = 112;
    score = snake_total_score;

    value = score % 10;
    remain = score / 10;

    /* draw numbers */
    while (1)
    {
        iamge_id = IMG_GX_SNAKE_NUMBER_0 + value;
        gui_show_image(x_pos, y_pos, (PU8) get_image(iamge_id));

        /* next loop ? */
        x_pos -= 5;
        if (remain > 0)
        {
            value = remain % 10;
            remain = remain / 10;
        }
        else
        {
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  Snake_Render_Background
 * DESCRIPTION
 *  Render background
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Snake_Render_Background(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 endx;
    S16 endy;
    S16 x_pos, y_pos;
    S16 stage, remain, value;

    MMI_ID_TYPE image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    endx = SNAKE_GRID_START_X + (SNAKE_GRID_COL_COUNT + 1) * SNAKE_GRID_CELL_SIZE - 2;
    endy = SNAKE_GRID_START_Y + (SNAKE_GRID_ROW_COUNT + 1) * SNAKE_GRID_CELL_SIZE - 2;

    gui_draw_filled_area(SNAKE_GRID_START_X - 2, SNAKE_GRID_START_Y - 2, endx, endy, (UI_filled_area*)&snake_border);

    gui_draw_filled_area(SNAKE_GRID_START_X - 2, endy + 4, endx, UI_device_height - 5, (UI_filled_area*)&snake_border);

    gui_draw_filled_area(
        SNAKE_GRID_START_X + 1,
        endy + 7,
        endx - 3,
        UI_device_height - 8,
        (UI_filled_area*)&score_border);

    /* render status */
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    gui_show_image(8, 112, (PU8) get_image(IMG_GX_SNAKE_STAGE_TXT));
#else
    gui_show_image(
        8,
        112, 
        (PU8) get_image(
           mmi_gfx_get_multilanguage_image_ID(
            mmi_snake_language_index, 
            IMG_GX_SNAKE_GOTEXT_LANGUAGE0, 
            MMI_SNAKE_STRING_COUNT, 
            MMI_SNAKE_STRING_STAGE)));
#endif


    x_pos = 45;
    y_pos = 112;

    stage = (snake_current_level) * 10 + snake_current_stage + 1;

    value = stage % 10;
    remain = stage / 10;

    while (1)
    {
        image_id = IMG_GX_SNAKE_NUMBER_0 + value;
        gui_show_image(x_pos, y_pos, (PU8) get_image(image_id));

        /* next loop ? */
        x_pos -= 5;
        if (remain > 0)
        {
            value = remain % 10;
            remain = remain / 10;
        }
        else
        {
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  Snake_Render_Wall
 * DESCRIPTION
 *  Render wall
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Snake_Render_Wall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;
    S16 dx, dy;

    S16 stage_wall_count;
    const S16 *pStage_ptr = Snake_Get_Stage_Ptr(&stage_wall_count);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < stage_wall_count; index++)
    {

        CALCULATE_RENDER_POSITION(dx, dy, pStage_ptr[index]);
        gui_show_image(dx, dy, (PU8) get_image(IMG_GX_SNAKE_WALL));
    }
}


/*****************************************************************************
 * FUNCTION
 *  Snake_Render_Egg
 * DESCRIPTION
 *  Render Egg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Snake_Render_Egg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 dx, dy;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Calc render position */
    CALCULATE_RENDER_POSITION(dx, dy, snake_egg_index);

    gui_show_image(dx, dy, (PU8) get_image(IMG_GX_SNAKE_EGG));
}


/*****************************************************************************
 * FUNCTION
 *  Snake_Render_Snake
 * DESCRIPTION
 *  Render snake
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Snake_Render_Snake(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int index;
    int dx, dy;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* no snake */
    if (snake_head_index == -1)
    {
        return;
    }

    index = snake_head_index;

    /* render sanke */
    while (1)
    {
        if (snake_matrix[index].need_update_render != FALSE)    /* TRUE */
        {
            /* calc render position */
            CALCULATE_RENDER_POSITION(dx, dy, index);

            if (index == snake_head_index)  /* head */
            {
                gui_show_image(dx, dy, snake_head_image[snake_matrix[index].direction]);
            }
            else if (snake_matrix[index].next_index == SNAKE_NEXT_INDEX_NULL)   /* tail */
            {
                gui_show_image(dx, dy, snake_tail_image[snake_matrix[index].direction]);
            }
            else    /* body */
            {
                switch (snake_matrix[index].direction)
                {
                    case SNAKE_DIRECTION_UP:
                    case SNAKE_DIRECTION_DOWN:
                        gui_show_image(dx, dy, snake_body_image[0]);
                        break;

                    case SNAKE_DIRECTION_LEFT:
                    case SNAKE_DIRECTION_RIGHT:
                        gui_show_image(dx, dy, snake_body_image[1]);
                        break;

                    case SNAKE_DIRECTION_UP_RIGHT:
                        gui_show_image(dx, dy, snake_body_image[2]);
                        break;
                    case SNAKE_DIRECTION_UP_LEFT:
                        gui_show_image(dx, dy, snake_body_image[3]);
                        break;
                    case SNAKE_DIRECTION_DOWN_RIGHT:
                        gui_show_image(dx, dy, snake_body_image[4]);
                        break;
                    case SNAKE_DIRECTION_DOWN_LEFT:
                        gui_show_image(dx, dy, snake_body_image[5]);
                        break;
                }
            }
        }

        index = snake_matrix[index].next_index;

        if (index == SNAKE_NEXT_INDEX_NULL)
        {
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  Snake_Framemove
 * DESCRIPTION
 *  Framemove - prcoess the game logic, snake movement
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Snake_Framemove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int index = snake_head_index;
    int new_head_index;
    int next_index;
    int prev_index;

    int dx = index % SNAKE_GRID_COL_COUNT;
    int dy = index / SNAKE_GRID_COL_COUNT;

    U8 bHitEgg = TRUE;

    S16 stage_wall_count;
    const S16 *pStage_ptr = Snake_Get_Stage_Ptr(&stage_wall_count);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Retrive one movement from snake_move_input buffer */
    if (snake_move_input[0] != SNAKE_DIRECTION_NONE)
    {
        snake_move_direction = snake_move_input[0];

        if (snake_move_input[1] != SNAKE_DIRECTION_NONE)    /* Second slot not empty */
        {
            snake_move_input[0] = snake_move_input[1];
            snake_move_input[1] = SNAKE_DIRECTION_NONE;
        }
        else
        {
            snake_move_input[0] = SNAKE_DIRECTION_NONE;
        }
    }

    //  /* auto move test */
    //      snake_move_direction = snake_auto_move_dir[snake_head_index];
    //      SetBacklightModeExe(0);

    switch (snake_move_direction)
    {
        case SNAKE_DIRECTION_UP:
            dy -= 1;
            break;
        case SNAKE_DIRECTION_DOWN:
            dy += 1;
            break;
        case SNAKE_DIRECTION_LEFT:
            dx -= 1;
            break;
        case SNAKE_DIRECTION_RIGHT:
            dx += 1;
            break;
    }

    /* Test if Snake within valid area */
    if ((dx >= 0) && (dx < SNAKE_GRID_COL_COUNT) && (dy >= 0) && (dy < SNAKE_GRID_ROW_COUNT))
    {
        new_head_index = dy * SNAKE_GRID_COL_COUNT + dx;

        /* Test if Snake bit himself */
        index = snake_head_index;
        while (1)
        {
            if (snake_matrix[index].next_index != SNAKE_NEXT_INDEX_NULL)        /* Not Tail, since Tail will be removed */
            {
                if (index == new_head_index)
                {
                    Snake_Gameover();
                    return;
                }
            }
            else
            {
                break;
            }

            index = snake_matrix[index].next_index;
        }

        /* Test if Snake hit wall */
        for (index = 0; index < stage_wall_count; index++)
        {
            if (new_head_index == pStage_ptr[index])
            {
                Snake_Gameover();
                return;
            }
        }

        /* Test if hit egg. If not hit, remove last tail since snake move one step foward */
        if (snake_egg_index != new_head_index)
        {
            bHitEgg = FALSE;

            /* Remove last tail */
            index = snake_head_index;
            prev_index = snake_head_index;
            while (1)
            {
                next_index = snake_matrix[index].next_index;

                if (next_index == SNAKE_NEXT_INDEX_NULL)
                {
                    snake_matrix[index].direction = SNAKE_DIRECTION_NONE;
                    snake_matrix[prev_index].next_index = SNAKE_NEXT_INDEX_NULL;
                    snake_matrix[prev_index].need_update_render = FALSE;

                    /* calc render position */
                    CALCULATE_RENDER_POSITION(dx, dy, index);

                    /* clear it with background color */
                    gui_fill_rectangle(
                        dx,
                        dy,
                        dx + SNAKE_GRID_CELL_SIZE - 1,
                        dy + SNAKE_GRID_CELL_SIZE - 1,
                        snake_bg_color);

                    break;
                }

                prev_index = index;
                index = next_index;
            }
        }

        /* Adjust Tail's Direction , for render purpose */
        index = snake_head_index;
        prev_index = snake_head_index;
        while (1)
        {
            if (snake_matrix[index].next_index == SNAKE_NEXT_INDEX_NULL)        /* is Tail */
            {
                /* check direction of prev segment and set the new tail direction */
                if ((prev_index - index) == -1)
                {
                    snake_matrix[index].direction = SNAKE_DIRECTION_LEFT;
                }
                else if ((prev_index - index) == 1)
                {
                    snake_matrix[index].direction = SNAKE_DIRECTION_RIGHT;
                }
                else if ((prev_index - index) < -1) /* above one line */
                {
                    snake_matrix[index].direction = SNAKE_DIRECTION_UP;
                }
                else if ((prev_index - index) > 1)  /* below one line */
                {
                    snake_matrix[index].direction = SNAKE_DIRECTION_DOWN;
                }

                /* change from body iamge to tail image, need update render */
                snake_matrix[index].need_update_render = TRUE;
                break;
            }

            prev_index = index;
            index = snake_matrix[index].next_index;
            snake_matrix[index].need_update_render = FALSE;
        }

        /* change second segment's direction if needed, for render purpose */
        switch (snake_matrix[snake_head_index].direction)
        {
            case SNAKE_DIRECTION_UP:
                if (snake_move_direction == SNAKE_DIRECTION_RIGHT)
                {
                    snake_matrix[snake_head_index].direction = SNAKE_DIRECTION_DOWN_RIGHT;
                }

                if (snake_move_direction == SNAKE_DIRECTION_LEFT)
                {
                    snake_matrix[snake_head_index].direction = SNAKE_DIRECTION_DOWN_LEFT;
                }
                break;

            case SNAKE_DIRECTION_DOWN:
                if (snake_move_direction == SNAKE_DIRECTION_RIGHT)
                {
                    snake_matrix[snake_head_index].direction = SNAKE_DIRECTION_UP_RIGHT;
                }

                if (snake_move_direction == SNAKE_DIRECTION_LEFT)
                {
                    snake_matrix[snake_head_index].direction = SNAKE_DIRECTION_UP_LEFT;
                }
                break;

            case SNAKE_DIRECTION_RIGHT:
                if (snake_move_direction == SNAKE_DIRECTION_UP)
                {
                    snake_matrix[snake_head_index].direction = SNAKE_DIRECTION_UP_LEFT;
                }

                if (snake_move_direction == SNAKE_DIRECTION_DOWN)
                {
                    snake_matrix[snake_head_index].direction = SNAKE_DIRECTION_DOWN_LEFT;
                }
                break;

            case SNAKE_DIRECTION_LEFT:
                if (snake_move_direction == SNAKE_DIRECTION_UP)
                {
                    snake_matrix[snake_head_index].direction = SNAKE_DIRECTION_UP_RIGHT;
                }

                if (snake_move_direction == SNAKE_DIRECTION_DOWN)
                {
                    snake_matrix[snake_head_index].direction = SNAKE_DIRECTION_DOWN_RIGHT;
                }
                break;

            default:
                break;
        }

        /* second segment need update image */
        snake_matrix[snake_head_index].need_update_render = TRUE;

        /* Assign new head */
        snake_matrix[new_head_index].direction = snake_move_direction;
        snake_matrix[new_head_index].next_index = snake_head_index;
        snake_matrix[new_head_index].need_update_render = TRUE;
        snake_head_index = new_head_index;

        if (bHitEgg)
        {
            snake_total_score++;
        #ifdef __MMI_GAME_MULTICHANNEL_SOUND__
            GFX_STOP_SOUND_EFFECTS_MIDI(eategg_midi);

            GFX_PLAY_SOUND_EFFECTS_MIDI(eategg_midi);
        #else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
            GFX_PLAY_AUDIO_MIDI(SnakeEatEgg, SNAKEEATEGG, DEVICE_AUDIO_PLAY_ONCE);
        #endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

            if (snake_game_speed > SNAKE_GAME_SPEED_LIMIT)
            {
                snake_game_speed--;
            }

            Snake_Calc_Egg_Position();
        }
    }
    else    /* Out */
    {
        Snake_Gameover();
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  Snake_Cyclic_Timer
 * DESCRIPTION
 *  Timer - Looping
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Snake_Cyclic_Timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_start_timer(snake_game_speed, Snake_Cyclic_Timer);

    /* LCD size, sould use a golbal variable instead of 128 x 128 */

    Snake_Framemove();

    /* 0 = false. (not gameover) */
    if (snake_game_over == FALSE)
    {
        if (snake_new_egg != FALSE)
        {
            Snake_Render_Egg();
        }

        Snake_Render_Snake();
        Snake_Render_Status();

    }

    gui_BLT_double_buffer(0, 0, UI_device_width, UI_device_height);

}


/*****************************************************************************
 * FUNCTION
 *  Snake_Gameover
 * DESCRIPTION
 *  Gameover - set gameover flag and go to gameover screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Snake_Gameover(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    snake_game_over = TRUE;
    snake_is_new_game = TRUE;

    mmi_gfx_entry_gameover_screen();
}


/*****************************************************************************
 * FUNCTION
 *  Snake_Key_Direction_Handler
 * DESCRIPTION
 *  Key handler - will queue two keys
 * PARAMETERS
 *  input           [IN]        
 *  conflict        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void Snake_Key_Direction_Handler(S8 input, S8 conflict)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (snake_move_input[0] == SNAKE_DIRECTION_NONE)
    {
        if (snake_move_direction == conflict)
        {
            return;
        }
        else
        {
            snake_move_input[0] = input;
        }
    }
    else
    {
        /* buffer still have one empty slot */
        if (snake_move_input[1] == SNAKE_DIRECTION_NONE)
        {
            if (snake_move_input[0] == conflict)
            {
                return;
            }
            else
            {
                snake_move_input[1] = input;
            }
        }
        else    /* snake_move_input buffer is full */
        {
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  Snake_Key_Up
 * DESCRIPTION
 *  Key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Snake_Key_Up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Snake_Key_Direction_Handler(SNAKE_DIRECTION_UP, SNAKE_DIRECTION_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  Snake_Key_Down
 * DESCRIPTION
 *  Key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Snake_Key_Down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Snake_Key_Direction_Handler(SNAKE_DIRECTION_DOWN, SNAKE_DIRECTION_UP);
}


/*****************************************************************************
 * FUNCTION
 *  Snake_Key_Right
 * DESCRIPTION
 *  Key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Snake_Key_Right(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Snake_Key_Direction_Handler(SNAKE_DIRECTION_RIGHT, SNAKE_DIRECTION_LEFT);
}


/*****************************************************************************
 * FUNCTION
 *  Snake_Key_Left
 * DESCRIPTION
 *  Key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Snake_Key_Left(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Snake_Key_Direction_Handler(SNAKE_DIRECTION_LEFT, SNAKE_DIRECTION_RIGHT);
}

#endif /* IS_SNAKE_BASE_GAME */ 

