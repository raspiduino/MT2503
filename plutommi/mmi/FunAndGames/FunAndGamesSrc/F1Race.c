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
 *  F1Race.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  F1 Race Game
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

#ifdef __MMI_GAME_F1RACE__
#include "GameInc.h"
#include "F1RaceProts.h"
#include "mmi_rp_app_games_def.h"

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__      //added for multi-language
#include "GameProts.h"
#endif
/************************************************************************/
/* Game Defines                                                         */
/************************************************************************/
/* Car Infomation */
#define F1RACE_PLAYER_CAR_IMAGE_SIZE_X          (15)
#define F1RACE_PLAYER_CAR_IMAGE_SIZE_Y          (20)

#define F1RACE_PLAYER_CAR_CARSH_IMAGE_SIZE_X    (15)
#define F1RACE_PLAYER_CAR_CARSH_IMAGE_SIZE_Y    (25)

#define F1RACE_PLAYER_CAR_FLY_IMAGE_SIZE_X         (23)
#define  F1RACE_PLAYER_CAR_FLY_IMAGE_SIZE_Y        (27)

#define F1RACE_PLAYER_CAR_HEAD_LIGHT_IMAGE_SIZE_X  (7)
#define F1RACE_PLAYER_CAR_HEAD_LIGHT_IMAGE_SIZE_Y  (15)
#define F1RACE_PLAYER_CAR_HEAD_LIGHT_0_SHIFT    (1)
#define F1RACE_PLAYER_CAR_HEAD_LIGHT_1_SHIFT    (7)

#define F1RACE_OPPOSITE_CAR_TYPE_COUNT    (7)
#define F1RACE_PLAYER_CAR_FLY_FRAME_COUNT (10)

#define F1RACE_OPPOSITE_CAR_0_IMAGE_SIZE_X   (17)
#define F1RACE_OPPOSITE_CAR_0_IMAGE_SIZE_Y   (35)

#define F1RACE_OPPOSITE_CAR_1_IMAGE_SIZE_X   (12)
#define F1RACE_OPPOSITE_CAR_1_IMAGE_SIZE_Y   (18)

#define F1RACE_OPPOSITE_CAR_2_IMAGE_SIZE_X   (15)
#define F1RACE_OPPOSITE_CAR_2_IMAGE_SIZE_Y   (20)

#define F1RACE_OPPOSITE_CAR_3_IMAGE_SIZE_X   (12)
#define F1RACE_OPPOSITE_CAR_3_IMAGE_SIZE_Y   (18)

#define F1RACE_OPPOSITE_CAR_4_IMAGE_SIZE_X   (17)
#define F1RACE_OPPOSITE_CAR_4_IMAGE_SIZE_Y   (27)

#define F1RACE_OPPOSITE_CAR_5_IMAGE_SIZE_X   (13)
#define F1RACE_OPPOSITE_CAR_5_IMAGE_SIZE_Y   (21)

#define F1RACE_OPPOSITE_CAR_6_IMAGE_SIZE_X   (13)
#define F1RACE_OPPOSITE_CAR_6_IMAGE_SIZE_Y   (22)

#define F1RACE_OPPOSITE_CAR_COUNT               (8)
#define F1RACE_OPPOSITE_CAR_DEFAULT_APPEAR_RATE    (2)  /* n frame will show one car */

#define F1RACE_MAX_FLY_COUNT        (9)

#define F1RACE_TIMER_ELAPSE            (100)    /* 100 ms = 10 fps */
#define F1RACE_PLAYER_CAR_SHIFT        (5)
#define F1RACE_PLAYER_CAR_FLY_SHIFT    (2)

/* define display regions */
#define F1RACE_DISPLAY_START_X         (3)
#define F1RACE_DISPLAY_START_Y         (3)
#define F1RACE_DISPLAY_END_X        (124)
#define F1RACE_DISPLAY_END_Y        (124)

#define F1RACE_ROAD_WIDTH           (23)
#define F1RACE_SEPARATOR_WIDTH         (3)
#define F1RACE_GRASS_WIDTH          (7)
#define F1RACE_STATUS_WIDTH            (32)     /* calc by hand */

#define F1RACE_SEPARATOR_HEIGHT_SPACE  (3)
#define F1RACE_SEPARATOR_RATIO         (6)
#define F1RACE_SEPARATOR_HEIGHT        (F1RACE_SEPARATOR_HEIGHT_SPACE*F1RACE_SEPARATOR_RATIO)

#define F1RACE_STATUS_NUMBER_WIDTH     (4)
#define F1RACE_STATUS_NUBBER_HEIGHT    (7)

/* define width from left to right */
/* ugly but has to do it this way  >< */
#define F1RACE_GRASS_0_START_X         (F1RACE_DISPLAY_START_X)
#define F1RACE_GRASS_0_END_X        (F1RACE_GRASS_0_START_X + F1RACE_GRASS_WIDTH)-1

#define F1RACE_ROAD_0_START_X       (F1RACE_GRASS_0_START_X + F1RACE_GRASS_WIDTH)
#define F1RACE_ROAD_0_END_X            (F1RACE_ROAD_0_START_X + F1RACE_ROAD_WIDTH)-1

#define F1RACE_SEPARATOR_0_START_X     (F1RACE_ROAD_0_START_X + F1RACE_ROAD_WIDTH)
#define F1RACE_SEPARATOR_0_END_X    (F1RACE_SEPARATOR_0_START_X + F1RACE_SEPARATOR_WIDTH)-1

#define F1RACE_ROAD_1_START_X       (F1RACE_SEPARATOR_0_START_X + F1RACE_SEPARATOR_WIDTH)
#define F1RACE_ROAD_1_END_X            (F1RACE_ROAD_1_START_X + F1RACE_ROAD_WIDTH)-1

#define F1RACE_SEPARATOR_1_START_X     (F1RACE_ROAD_1_START_X + F1RACE_ROAD_WIDTH)
#define F1RACE_SEPARATOR_1_END_X    (F1RACE_SEPARATOR_1_START_X + F1RACE_SEPARATOR_WIDTH)-1

#define F1RACE_ROAD_2_START_X       (F1RACE_SEPARATOR_1_START_X + F1RACE_SEPARATOR_WIDTH)
#define F1RACE_ROAD_2_END_X            (F1RACE_ROAD_2_START_X + F1RACE_ROAD_WIDTH)-1

#define F1RACE_GRASS_1_START_X         (F1RACE_ROAD_2_START_X + F1RACE_ROAD_WIDTH)
#define F1RACE_GRASS_1_END_X        (F1RACE_GRASS_1_START_X + F1RACE_GRASS_WIDTH)-1

#define F1RACE_STATUS_START_X       (F1RACE_GRASS_1_START_X + F1RACE_GRASS_WIDTH)
#define F1RACE_STATUS_END_X            (F1RACE_STATUS_START_X + F1RACE_STATUS_WIDTH)

/*
 * width of each element in screen.
 * 
 * 3  10   33 36   59 62   85 92       124
 * |  |    |  |    |  |    |  |        |
 * |G | R  |S | R  |S | R  |G | status |
 * |0 | 0  |0 | 1  |1 | 2  |1 |  (32)  |    
 * |  |    |  |    |  |    |  |        |
 * |  |    |  |    |  |    |  |        |
 * |  |    |  |    |  |    |  |        |
 * 
 */

/************************************************************************/
/* Macros                                                */
/************************************************************************/
#define F1RACE_RELEASE_ALL_KEY            \
{                                         \
   f1race_key_up_pressed      = FALSE;    \
   f1race_key_down_pressed    = FALSE;    \
   f1race_key_left_pressed    = FALSE;    \
   f1race_key_right_pressed   = FALSE;    \
   if(f1race_is_crashing == TRUE)         \
      return;                             \
}                                         \

#define F1RACE_GET_NUMBER_IMAGE(value, image)        \
{                                                    \
   switch(value)                                     \
   {                                                 \
   case 0:                                           \
      image = (PU8)get_image(IMG_GX_F1RACE_NUMBER_0);\
      break;                                         \
   case 1:                                           \
      image = (PU8)get_image(IMG_GX_F1RACE_NUMBER_1);\
      break;                                         \
   case 2:                                           \
      image = (PU8)get_image(IMG_GX_F1RACE_NUMBER_2);\
      break;                                         \
   case 3:                                           \
      image = (PU8)get_image(IMG_GX_F1RACE_NUMBER_3);\
      break;                                         \
   case 4:                                           \
      image = (PU8)get_image(IMG_GX_F1RACE_NUMBER_4);\
      break;                                         \
   case 5:                                           \
      image = (PU8)get_image(IMG_GX_F1RACE_NUMBER_5);\
      break;                                         \
   case 6:                                           \
      image = (PU8)get_image(IMG_GX_F1RACE_NUMBER_6);\
      break;                                         \
   case 7:                                           \
      image = (PU8)get_image(IMG_GX_F1RACE_NUMBER_7);\
      break;                                         \
   case 8:                                           \
      image = (PU8)get_image(IMG_GX_F1RACE_NUMBER_8);\
      break;                                         \
   case 9:                                           \
      image = (PU8)get_image(IMG_GX_F1RACE_NUMBER_9);\
      break;                                         \
   }                                                 \
}
/************************************************************************/
/* Structure                                             */
/************************************************************************/
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
//added for multi-language support
typedef enum
{
    MMI_F1RACE_STRING_SCORE,
    MMI_F1RACE_STRING_LEVEL,
    MMI_F1RACE_STRING_FLY,
    MMI_F1RACE_STRING_GAMEOVER,
    MMI_F1RACE_STRING_TOTAL
}mmi_f1race_string_enum;
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

/* Player Car */
typedef struct
{
    S16 pos_x;
    S16 pos_y;
    S16 dx;
    S16 dy;
    PU8 image;
    PU8 image_fly;
    PU8 image_head_light;

} F1RACE_CAR_STRUCT;

/* Opposite Car */
typedef struct
{
    S16 dx;
    S16 dy;
    S16 speed;
    S16 dx_from_road;
    PU8 image;

} F1RACE_OPPOSITE_CAR_TYPE_STRUCT;

typedef struct
{
    S16 dx;
    S16 dy;
    S16 speed;
    S16 dx_from_road;
    PU8 image;

    S16 pos_x;
    S16 pos_y;
    U8 road_id; /* road 0 - road 2 */
    BOOL is_empty;
    BOOL is_add_score;
} F1RACE_OPPOSITE_CAR_STRUCT;

/************************************************************************/
/* Audio [Const]                                         */
/************************************************************************/

#if (defined(EXT_AUDIO_CHIP) || defined(DSP_WT_SYN)) && !defined(LOW_COST_SUPPORT)

/* powerful midi player */
#define F1RACEBACKGROUND      2479
__align(2)
     const U8 F1RaceBackGround[2479] = 
     {
         0x4D, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01, 0x03, 0xC0, 0x4D, 0x54, 0x72,
         0x6B, 0x00, 0x00, 0x09, 0x99, 0x00, 0xFF, 0x03, 0x08, 0x75, 0x6E, 0x74, 0x69, 0x74, 0x6C, 0x65,
         0x64, 0x00, 0xFF, 0x02, 0x16, 0x43, 0x6F, 0x70, 0x79, 0x72, 0x69, 0x67, 0x68, 0x74, 0x20, 0x63,
         0x20, 0x32, 0x30, 0x30, 0x33, 0x20, 0x62, 0x79, 0x20, 0x43, 0x43, 0x00, 0xFF, 0x01, 0x03, 0x43,
         0x43, 0x0A, 0x00, 0xFF, 0x58, 0x04, 0x04, 0x02, 0x18, 0x08, 0x00, 0xFF, 0x59, 0x02, 0x00, 0x00,
         0x00, 0xFF, 0x51, 0x03, 0x07, 0x44, 0x1E, 0x00, 0xC0, 0x54, 0x00, 0xB0, 0x07, 0x62, 0x00, 0x90,
         0x48, 0x6F, 0x00, 0xC1, 0x0B, 0x00, 0xB1, 0x07, 0x64, 0x00, 0x91, 0x48, 0x67, 0x00, 0xC2, 0x01,
         0x00, 0xB2, 0x07, 0x6A, 0x00, 0x92, 0x47, 0x7C, 0x00, 0x43, 0x7E, 0x00, 0x3C, 0x7F, 0x00, 0x40,
         0x7C, 0x81, 0x70, 0x40, 0x00, 0x00, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x3C,
         0x50, 0x00, 0x47, 0x51, 0x00, 0x43, 0x5A, 0x00, 0x40, 0x53, 0x50, 0x91, 0x48, 0x00, 0x00, 0x49,
         0x67, 0x81, 0x20, 0x92, 0x3C, 0x00, 0x00, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x90, 0x48, 0x00,
         0x00, 0x92, 0x40, 0x00, 0x00, 0x90, 0x4C, 0x7C, 0x00, 0x92, 0x3C, 0x50, 0x00, 0x47, 0x50, 0x00,
         0x43, 0x5A, 0x00, 0x40, 0x5A, 0x81, 0x20, 0x91, 0x49, 0x00, 0x00, 0x4A, 0x51, 0x50, 0x92, 0x3C,
         0x00, 0x00, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x40, 0x00, 0x00, 0x3C, 0x51, 0x00, 0x43, 0x5A,
         0x00, 0x47, 0x51, 0x00, 0x40, 0x53, 0x81, 0x70, 0x40, 0x00, 0x00, 0x90, 0x4C, 0x00, 0x00, 0x92,
         0x3C, 0x00, 0x00, 0x91, 0x4A, 0x00, 0x00, 0x92, 0x47, 0x00, 0x00, 0x43, 0x00, 0x00, 0x90, 0x4F,
         0x7C, 0x00, 0x91, 0x4B, 0x7D, 0x00, 0x92, 0x3C, 0x50, 0x00, 0x43, 0x53, 0x00, 0x47, 0x49, 0x00,
         0x40, 0x51, 0x81, 0x70, 0x40, 0x00, 0x00, 0x43, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x47, 0x00, 0x00,
         0x3C, 0x51, 0x00, 0x47, 0x51, 0x00, 0x43, 0x53, 0x00, 0x40, 0x53, 0x50, 0x91, 0x4B, 0x00, 0x00,
         0x4A, 0x51, 0x81, 0x20, 0x92, 0x3C, 0x00, 0x00, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x90, 0x4F,
         0x00, 0x00, 0x92, 0x40, 0x00, 0x00, 0x90, 0x48, 0x67, 0x00, 0x92, 0x47, 0x52, 0x00, 0x43, 0x5A,
         0x00, 0x3C, 0x49, 0x00, 0x40, 0x5A, 0x81, 0x20, 0x91, 0x4A, 0x00, 0x00, 0x49, 0x53, 0x50, 0x92,
         0x47, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x43, 0x00, 0x00, 0x90, 0x48, 0x00, 0x00, 0x92, 0x40, 0x00,
         0x00, 0x90, 0x4C, 0x7C, 0x00, 0x92, 0x47, 0x53, 0x00, 0x3C, 0x51, 0x00, 0x43, 0x5A, 0x00, 0x40,
         0x5A, 0x81, 0x70, 0x40, 0x00, 0x00, 0x91, 0x49, 0x00, 0x00, 0x92, 0x47, 0x00, 0x00, 0x3C, 0x00,
         0x00, 0x43, 0x00, 0x00, 0x91, 0x48, 0x7C, 0x00, 0x92, 0x47, 0x67, 0x00, 0x43, 0x6C, 0x00, 0x40,
         0x6E, 0x00, 0x3C, 0x6E, 0x81, 0x70, 0x3C, 0x00, 0x00, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x40,
         0x00, 0x00, 0x47, 0x51, 0x00, 0x3C, 0x50, 0x00, 0x43, 0x5A, 0x00, 0x40, 0x5A, 0x81, 0x69, 0x90,
         0x4C, 0x00, 0x07, 0x92, 0x47, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x91, 0x48, 0x00, 0x00, 0x92, 0x40,
         0x00, 0x00, 0x43, 0x00, 0x00, 0x90, 0x4F, 0x7C, 0x00, 0x91, 0x4C, 0x7D, 0x00, 0x92, 0x47, 0x52,
         0x00, 0x43, 0x53, 0x00, 0x3C, 0x49, 0x00, 0x40, 0x5A, 0x81, 0x70, 0x40, 0x00, 0x00, 0x91, 0x4C,
         0x00, 0x00, 0x92, 0x47, 0x00, 0x00, 0x43, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x91, 0x4D, 0x7C, 0x00,
         0x92, 0x47, 0x52, 0x00, 0x3C, 0x50, 0x00, 0x43, 0x52, 0x00, 0x40, 0x5A, 0x81, 0x70, 0x40, 0x00,
         0x00, 0x91, 0x4D, 0x00, 0x00, 0x92, 0x47, 0x00, 0x00, 0x90, 0x4F, 0x00, 0x00, 0x92, 0x43, 0x00,
         0x00, 0x3C, 0x00, 0x00, 0x90, 0x48, 0x67, 0x00, 0x91, 0x4F, 0x7C, 0x00, 0x92, 0x3C, 0x51, 0x00,
         0x47, 0x53, 0x00, 0x43, 0x5A, 0x00, 0x40, 0x67, 0x81, 0x70, 0x40, 0x00, 0x00, 0x91, 0x4F, 0x00,
         0x00, 0x92, 0x3C, 0x00, 0x00, 0x47, 0x00, 0x00, 0x43, 0x00, 0x00, 0x91, 0x4D, 0x7D, 0x00, 0x92,
         0x47, 0x52, 0x00, 0x3C, 0x51, 0x00, 0x43, 0x53, 0x00, 0x40, 0x5A, 0x81, 0x70, 0x40, 0x00, 0x00,
         0x91, 0x4D, 0x00, 0x00, 0x92, 0x47, 0x00, 0x00, 0x90, 0x48, 0x00, 0x00, 0x92, 0x43, 0x00, 0x00,
         0x3C, 0x00, 0x00, 0x90, 0x4C, 0x6F, 0x00, 0x91, 0x4C, 0x7D, 0x00, 0x92, 0x47, 0x52, 0x00, 0x43,
         0x53, 0x00, 0x40, 0x53, 0x00, 0x3C, 0x48, 0x81, 0x70, 0x3C, 0x00, 0x00, 0x43, 0x00, 0x00, 0x47,
         0x00, 0x00, 0x40, 0x00, 0x00, 0x47, 0x51, 0x00, 0x43, 0x5A, 0x00, 0x40, 0x67, 0x00, 0x3C, 0x50,
         0x81, 0x70, 0x3C, 0x00, 0x00, 0x90, 0x4C, 0x00, 0x00, 0x92, 0x47, 0x00, 0x00, 0x91, 0x4C, 0x00,
         0x00, 0x92, 0x40, 0x00, 0x00, 0x43, 0x00, 0x00, 0x90, 0x4D, 0x7C, 0x00, 0x91, 0x4D, 0x7D, 0x00,
         0x92, 0x48, 0x78, 0x00, 0x45, 0x70, 0x00, 0x41, 0x72, 0x00, 0x3E, 0x7C, 0x81, 0x70, 0x3E, 0x00,
         0x00, 0x45, 0x00, 0x00, 0x48, 0x00, 0x00, 0x41, 0x00, 0x00, 0x48, 0x50, 0x00, 0x45, 0x52, 0x00,
         0x41, 0x53, 0x00, 0x3E, 0x51, 0x50, 0x91, 0x4D, 0x00, 0x00, 0x4E, 0x6F, 0x81, 0x20, 0x92, 0x48,
         0x00, 0x00, 0x41, 0x00, 0x00, 0x45, 0x00, 0x00, 0x90, 0x4D, 0x00, 0x00, 0x92, 0x3E, 0x00, 0x00,
         0x90, 0x51, 0x7C, 0x00, 0x92, 0x48, 0x42, 0x00, 0x45, 0x50, 0x00, 0x41, 0x52, 0x00, 0x3E, 0x49,
         0x81, 0x20, 0x91, 0x4E, 0x00, 0x00, 0x4F, 0x5A, 0x50, 0x92, 0x48, 0x00, 0x00, 0x41, 0x00, 0x00,
         0x45, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x48, 0x3F, 0x00, 0x45, 0x51, 0x00, 0x41, 0x51, 0x00, 0x3E,
         0x42, 0x81, 0x70, 0x3E, 0x00, 0x00, 0x90, 0x51, 0x00, 0x00, 0x92, 0x48, 0x00, 0x00, 0x91, 0x4F,
         0x00, 0x00, 0x92, 0x41, 0x00, 0x00, 0x45, 0x00, 0x00, 0x90, 0x54, 0x7C, 0x00, 0x91, 0x50, 0x7C,
         0x00, 0x92, 0x45, 0x53, 0x00, 0x48, 0x49, 0x00, 0x41, 0x53, 0x00, 0x3E, 0x49, 0x81, 0x70, 0x3E,
         0x00, 0x00, 0x48, 0x00, 0x00, 0x45, 0x00, 0x00, 0x41, 0x00, 0x00, 0x48, 0x49, 0x00, 0x45, 0x52,
         0x00, 0x41, 0x52, 0x00, 0x3E, 0x51, 0x50, 0x91, 0x50, 0x00, 0x00, 0x4F, 0x53, 0x81, 0x20, 0x92,
         0x48, 0x00, 0x00, 0x41, 0x00, 0x00, 0x45, 0x00, 0x00, 0x90, 0x54, 0x00, 0x00, 0x92, 0x3E, 0x00,
         0x00, 0x90, 0x4D, 0x7C, 0x00, 0x92, 0x45, 0x52, 0x00, 0x3E, 0x50, 0x00, 0x48, 0x42, 0x00, 0x41,
         0x52, 0x81, 0x20, 0x91, 0x4F, 0x00, 0x00, 0x4E, 0x7C, 0x50, 0x92, 0x45, 0x00, 0x00, 0x48, 0x00,
         0x00, 0x3E, 0x00, 0x00, 0x90, 0x4D, 0x00, 0x00, 0x92, 0x41, 0x00, 0x00, 0x90, 0x51, 0x7C, 0x00,
         0x92, 0x3E, 0x52, 0x00, 0x48, 0x48, 0x00, 0x45, 0x52, 0x00, 0x41, 0x53, 0x81, 0x70, 0x41, 0x00,
         0x00, 0x91, 0x4E, 0x00, 0x00, 0x92, 0x3E, 0x00, 0x00, 0x48, 0x00, 0x00, 0x45, 0x00, 0x00, 0x91,
         0x4D, 0x7C, 0x00, 0x92, 0x48, 0x64, 0x00, 0x45, 0x6C, 0x00, 0x3E, 0x6E, 0x00, 0x41, 0x6A, 0x81,
         0x70, 0x41, 0x00, 0x00, 0x45, 0x00, 0x00, 0x48, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x48, 0x48, 0x00,
         0x3E, 0x50, 0x00, 0x45, 0x53, 0x00, 0x41, 0x53, 0x81, 0x70, 0x41, 0x00, 0x00, 0x91, 0x4D, 0x00,
         0x00, 0x92, 0x48, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x45, 0x00, 0x00, 0x90, 0x54, 0x7C, 0x00, 0x91,
         0x51, 0x7D, 0x00, 0x92, 0x48, 0x49, 0x00, 0x45, 0x53, 0x00, 0x3E, 0x51, 0x00, 0x41, 0x53, 0x06,
         0x90, 0x51, 0x00, 0x81, 0x6A, 0x92, 0x3E, 0x00, 0x00, 0x91, 0x51, 0x00, 0x00, 0x92, 0x48, 0x00,
         0x00, 0x45, 0x00, 0x00, 0x41, 0x00, 0x00, 0x91, 0x53, 0x7C, 0x00, 0x92, 0x48, 0x49, 0x00, 0x45,
         0x53, 0x00, 0x3E, 0x49, 0x00, 0x41, 0x53, 0x81, 0x70, 0x41, 0x00, 0x00, 0x91, 0x53, 0x00, 0x00,
         0x92, 0x48, 0x00, 0x00, 0x90, 0x54, 0x00, 0x00, 0x92, 0x3E, 0x00, 0x00, 0x45, 0x00, 0x00, 0x90,
         0x4D, 0x7D, 0x00, 0x91, 0x54, 0x6F, 0x00, 0x92, 0x48, 0x50, 0x00, 0x3E, 0x52, 0x00, 0x45, 0x53,
         0x00, 0x41, 0x5A, 0x81, 0x70, 0x41, 0x00, 0x00, 0x91, 0x54, 0x00, 0x00, 0x92, 0x48, 0x00, 0x00,
         0x3E, 0x00, 0x00, 0x45, 0x00, 0x00, 0x91, 0x53, 0x7C, 0x00, 0x92, 0x48, 0x52, 0x00, 0x45, 0x53,
         0x00, 0x41, 0x67, 0x00, 0x3E, 0x50, 0x81, 0x70, 0x3E, 0x00, 0x00, 0x91, 0x53, 0x00, 0x00, 0x92,
         0x48, 0x00, 0x00, 0x90, 0x4D, 0x00, 0x00, 0x92, 0x41, 0x00, 0x00, 0x45, 0x00, 0x00, 0x90, 0x51,
         0x7C, 0x00, 0x91, 0x51, 0x7C, 0x00, 0x92, 0x3E, 0x52, 0x00, 0x48, 0x51, 0x00, 0x45, 0x53, 0x00,
         0x41, 0x67, 0x81, 0x70, 0x41, 0x00, 0x00, 0x48, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x45, 0x00, 0x00,
         0x48, 0x50, 0x00, 0x45, 0x52, 0x00, 0x41, 0x5A, 0x00, 0x3E, 0x52, 0x81, 0x70, 0x3E, 0x00, 0x00,
         0x90, 0x51, 0x00, 0x00, 0x92, 0x48, 0x00, 0x00, 0x91, 0x51, 0x00, 0x00, 0x92, 0x41, 0x00, 0x00,
         0x45, 0x00, 0x00, 0x90, 0x4F, 0x7C, 0x00, 0x91, 0x4F, 0x67, 0x00, 0x92, 0x4A, 0x78, 0x00, 0x47,
         0x78, 0x00, 0x43, 0x78, 0x00, 0x40, 0x7A, 0x81, 0x70, 0x40, 0x00, 0x00, 0x47, 0x00, 0x00, 0x4A,
         0x00, 0x00, 0x43, 0x00, 0x00, 0x4A, 0x41, 0x00, 0x47, 0x49, 0x00, 0x40, 0x48, 0x00, 0x43, 0x50,
         0x50, 0x91, 0x4F, 0x00, 0x00, 0x50, 0x7D, 0x81, 0x20, 0x92, 0x4A, 0x00, 0x00, 0x40, 0x00, 0x00,
         0x47, 0x00, 0x00, 0x90, 0x4F, 0x00, 0x00, 0x92, 0x43, 0x00, 0x00, 0x90, 0x53, 0x5A, 0x00, 0x92,
         0x4A, 0x49, 0x00, 0x47, 0x49, 0x00, 0x40, 0x50, 0x00, 0x43, 0x51, 0x81, 0x20, 0x91, 0x50, 0x00,
         0x00, 0x51, 0x5A, 0x50, 0x92, 0x4A, 0x00, 0x00, 0x40, 0x00, 0x00, 0x47, 0x00, 0x00, 0x43, 0x00,
         0x00, 0x4A, 0x49, 0x00, 0x40, 0x49, 0x00, 0x47, 0x51, 0x00, 0x43, 0x51, 0x81, 0x70, 0x43, 0x00,
         0x00, 0x90, 0x53, 0x00, 0x00, 0x92, 0x4A, 0x00, 0x00, 0x91, 0x51, 0x00, 0x00, 0x92, 0x47, 0x00,
         0x00, 0x40, 0x00, 0x00, 0x90, 0x56, 0x7C, 0x00, 0x91, 0x52, 0x7C, 0x00, 0x92, 0x4A, 0x49, 0x00,
         0x47, 0x51, 0x00, 0x43, 0x52, 0x00, 0x40, 0x48, 0x00, 0x4A, 0x42, 0x00, 0x40, 0x51, 0x00, 0x43,
         0x52, 0x81, 0x70, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x40, 0x00, 0x00, 0x43, 0x00, 0x00, 0x4A,
         0x00, 0x00, 0x4A, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x50, 0x00, 0x4A, 0x50, 0x00, 0x47, 0x53,
         0x00, 0x43, 0x5A, 0x50, 0x91, 0x52, 0x00, 0x00, 0x51, 0x52, 0x81, 0x20, 0x92, 0x40, 0x00, 0x00,
         0x47, 0x00, 0x00, 0x4A, 0x00, 0x00, 0x90, 0x56, 0x00, 0x00, 0x92, 0x43, 0x00, 0x00, 0x90, 0x4F,
         0x6F, 0x00, 0x92, 0x40, 0x13, 0x00, 0x4A, 0x38, 0x00, 0x47, 0x50, 0x00, 0x43, 0x34, 0x81, 0x20,
         0x91, 0x51, 0x00, 0x00, 0x50, 0x7C, 0x50, 0x92, 0x40, 0x00, 0x00, 0x47, 0x00, 0x00, 0x4A, 0x00,
         0x00, 0x90, 0x4F, 0x00, 0x00, 0x92, 0x43, 0x00, 0x00, 0x90, 0x53, 0x7C, 0x00, 0x92, 0x4A, 0x7C,
         0x00, 0x47, 0x6F, 0x00, 0x43, 0x7C, 0x00, 0x40, 0x6F, 0x81, 0x70, 0x40, 0x00, 0x00, 0x91, 0x50,
         0x00, 0x00, 0x92, 0x4A, 0x00, 0x00, 0x47, 0x00, 0x00, 0x43, 0x00, 0x00, 0x91, 0x4F, 0x7D, 0x00,
         0x92, 0x4A, 0x41, 0x00, 0x47, 0x51, 0x00, 0x43, 0x51, 0x00, 0x40, 0x49, 0x81, 0x70, 0x40, 0x00,
         0x00, 0x47, 0x00, 0x00, 0x4A, 0x00, 0x00, 0x43, 0x00, 0x00, 0x4A, 0x64, 0x00, 0x47, 0x68, 0x00,
         0x41, 0x72, 0x00, 0x43, 0x64, 0x81, 0x70, 0x43, 0x00, 0x00, 0x91, 0x4F, 0x00, 0x00, 0x92, 0x4A,
         0x00, 0x00, 0x47, 0x00, 0x00, 0x41, 0x00, 0x00, 0x90, 0x59, 0x7C, 0x00, 0x91, 0x53, 0x7C, 0x00,
         0x92, 0x4A, 0x41, 0x00, 0x47, 0x50, 0x00, 0x43, 0x53, 0x00, 0x41, 0x49, 0x0E, 0x90, 0x53, 0x00,
         0x81, 0x62, 0x92, 0x43, 0x00, 0x00, 0x91, 0x53, 0x00, 0x00, 0x92, 0x4A, 0x00, 0x00, 0x47, 0x00,
         0x00, 0x41, 0x00, 0x00, 0x91, 0x54, 0x7C, 0x00, 0x92, 0x4A, 0x51, 0x00, 0x47, 0x52, 0x00, 0x43,
         0x52, 0x00, 0x41, 0x50, 0x81, 0x70, 0x41, 0x00, 0x00, 0x91, 0x54, 0x00, 0x00, 0x92, 0x4A, 0x00,
         0x00, 0x90, 0x59, 0x00, 0x00, 0x92, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x90, 0x4F, 0x7C, 0x00,
         0x91, 0x56, 0x7C, 0x00, 0x92, 0x4A, 0x50, 0x00, 0x47, 0x50, 0x00, 0x41, 0x50, 0x00, 0x43, 0x53,
         0x81, 0x70, 0x43, 0x00, 0x00, 0x91, 0x56, 0x00, 0x00, 0x92, 0x4A, 0x00, 0x00, 0x47, 0x00, 0x00,
         0x41, 0x00, 0x00, 0x91, 0x54, 0x7C, 0x00, 0x92, 0x4A, 0x50, 0x00, 0x47, 0x52, 0x00, 0x43, 0x53,
         0x00, 0x41, 0x52, 0x81, 0x70, 0x41, 0x00, 0x00, 0x91, 0x54, 0x00, 0x00, 0x92, 0x4A, 0x00, 0x00,
         0x90, 0x4F, 0x00, 0x00, 0x92, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x90, 0x53, 0x7C, 0x00, 0x91,
         0x53, 0x7C, 0x00, 0x92, 0x4A, 0x48, 0x00, 0x47, 0x52, 0x00, 0x41, 0x3F, 0x00, 0x43, 0x50, 0x81,
         0x70, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x4A, 0x00, 0x00, 0x41, 0x00, 0x00, 0x4A, 0x5A, 0x00,
         0x47, 0x58, 0x00, 0x43, 0x56, 0x00, 0x41, 0x60, 0x81, 0x70, 0x41, 0x00, 0x00, 0x90, 0x53, 0x00,
         0x00, 0x92, 0x4A, 0x00, 0x00, 0x91, 0x53, 0x00, 0x00, 0x92, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00,
         0x90, 0x54, 0x7C, 0x00, 0x91, 0x54, 0x6F, 0x00, 0x92, 0x4C, 0x78, 0x00, 0x47, 0x78, 0x00, 0x43,
         0x78, 0x00, 0x48, 0x78, 0x81, 0x70, 0x48, 0x00, 0x00, 0x47, 0x00, 0x00, 0x4C, 0x00, 0x00, 0x43,
         0x00, 0x00, 0x4C, 0x42, 0x00, 0x48, 0x51, 0x00, 0x47, 0x41, 0x00, 0x43, 0x41, 0x50, 0x91, 0x54,
         0x00, 0x00, 0x55, 0x5A, 0x81, 0x20, 0x92, 0x4C, 0x00, 0x00, 0x47, 0x00, 0x00, 0x48, 0x00, 0x00,
         0x90, 0x54, 0x00, 0x00, 0x92, 0x43, 0x00, 0x00, 0x90, 0x58, 0x67, 0x00, 0x92, 0x4C, 0x3F, 0x00,
         0x47, 0x42, 0x00, 0x43, 0x41, 0x00, 0x48, 0x52, 0x81, 0x20, 0x91, 0x55, 0x00, 0x00, 0x56, 0x53,
         0x50, 0x92, 0x4C, 0x00, 0x00, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x48, 0x00, 0x00, 0x47, 0x51,
         0x00, 0x4C, 0x50, 0x00, 0x48, 0x42, 0x00, 0x43, 0x52, 0x81, 0x70, 0x43, 0x00, 0x00, 0x90, 0x58,
         0x00, 0x00, 0x92, 0x47, 0x00, 0x00, 0x91, 0x56, 0x00, 0x00, 0x92, 0x48, 0x00, 0x00, 0x4C, 0x00,
         0x00, 0x90, 0x5B, 0x7C, 0x00, 0x91, 0x57, 0x7C, 0x00, 0x92, 0x4C, 0x50, 0x00, 0x48, 0x42, 0x00,
         0x47, 0x49, 0x00, 0x43, 0x49, 0x81, 0x70, 0x43, 0x00, 0x00, 0x48, 0x00, 0x00, 0x4C, 0x00, 0x00,
         0x47, 0x00, 0x00, 0x4C, 0x50, 0x00, 0x48, 0x50, 0x00, 0x47, 0x52, 0x00, 0x43, 0x52, 0x50, 0x91,
         0x57, 0x00, 0x00, 0x56, 0x6F, 0x81, 0x20, 0x92, 0x4C, 0x00, 0x00, 0x47, 0x00, 0x00, 0x48, 0x00,
         0x00, 0x90, 0x5B, 0x00, 0x00, 0x92, 0x43, 0x00, 0x00, 0x90, 0x54, 0x6F, 0x00, 0x92, 0x4C, 0x51,
         0x00, 0x48, 0x50, 0x00, 0x47, 0x52, 0x00, 0x43, 0x53, 0x81, 0x20, 0x91, 0x56, 0x00, 0x00, 0x55,
         0x5A, 0x50, 0x92, 0x4C, 0x00, 0x00, 0x47, 0x00, 0x00, 0x48, 0x00, 0x00, 0x90, 0x54, 0x00, 0x00,
         0x92, 0x43, 0x00, 0x00, 0x90, 0x58, 0x7C, 0x00, 0x92, 0x4C, 0x5A, 0x00, 0x48, 0x5A, 0x00, 0x47,
         0x6F, 0x00, 0x43, 0x6F, 0x81, 0x70, 0x43, 0x00, 0x00, 0x91, 0x55, 0x00, 0x00, 0x92, 0x4C, 0x00,
         0x00, 0x48, 0x00, 0x00, 0x47, 0x00, 0x00, 0x91, 0x54, 0x67, 0x00, 0x92, 0x4C, 0x6E, 0x00, 0x48,
         0x65, 0x00, 0x47, 0x70, 0x00, 0x43, 0x6C, 0x81, 0x70, 0x43, 0x00, 0x00, 0x48, 0x00, 0x00, 0x4C,
         0x00, 0x00, 0x47, 0x00, 0x00, 0x4C, 0x4A, 0x00, 0x48, 0x4A, 0x00, 0x47, 0x48, 0x00, 0x43, 0x47,
         0x81, 0x48, 0x90, 0x58, 0x00, 0x28, 0x92, 0x4C, 0x00, 0x00, 0x48, 0x00, 0x00, 0x91, 0x54, 0x00,
         0x00, 0x92, 0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x90, 0x5B, 0x6F, 0x00, 0x91, 0x4F, 0x7C, 0x00,
         0x92, 0x4C, 0x50, 0x00, 0x48, 0x50, 0x00, 0x47, 0x50, 0x00, 0x43, 0x54, 0x81, 0x70, 0x43, 0x00,
         0x00, 0x91, 0x4F, 0x00, 0x00, 0x92, 0x4C, 0x00, 0x00, 0x48, 0x00, 0x00, 0x47, 0x00, 0x00, 0x91,
         0x4D, 0x7C, 0x00, 0x92, 0x4C, 0x46, 0x00, 0x48, 0x48, 0x00, 0x47, 0x46, 0x00, 0x43, 0x49, 0x81,
         0x70, 0x43, 0x00, 0x00, 0x91, 0x4D, 0x00, 0x00, 0x92, 0x4C, 0x00, 0x00, 0x90, 0x5B, 0x00, 0x00,
         0x92, 0x47, 0x00, 0x00, 0x48, 0x00, 0x00, 0x90, 0x54, 0x6F, 0x00, 0x91, 0x4C, 0x7C, 0x00, 0x92,
         0x4C, 0x51, 0x00, 0x48, 0x4B, 0x00, 0x47, 0x27, 0x00, 0x43, 0x52, 0x81, 0x70, 0x43, 0x00, 0x00,
         0x91, 0x4C, 0x00, 0x00, 0x92, 0x4C, 0x00, 0x00, 0x48, 0x00, 0x00, 0x47, 0x00, 0x00, 0x91, 0x4B,
         0x7D, 0x00, 0x92, 0x4C, 0x50, 0x00, 0x47, 0x4E, 0x00, 0x43, 0x50, 0x00, 0x48, 0x52, 0x81, 0x70,
         0x48, 0x00, 0x00, 0x91, 0x4B, 0x00, 0x00, 0x92, 0x4C, 0x00, 0x00, 0x90, 0x54, 0x00, 0x00, 0x92,
         0x43, 0x00, 0x00, 0x47, 0x00, 0x00, 0x90, 0x58, 0x7C, 0x00, 0x91, 0x4A, 0x7C, 0x00, 0x92, 0x4C,
         0x51, 0x00, 0x47, 0x50, 0x00, 0x43, 0x52, 0x00, 0x48, 0x52, 0x81, 0x70, 0x48, 0x00, 0x00, 0x47,
         0x00, 0x00, 0x4C, 0x00, 0x00, 0x43, 0x00, 0x00, 0x4C, 0x53, 0x00, 0x47, 0x52, 0x00, 0x48, 0x51,
         0x00, 0x43, 0x52, 0x81, 0x70, 0x43, 0x00, 0x00, 0x90, 0x58, 0x00, 0x00, 0x92, 0x4C, 0x00, 0x00,
         0x91, 0x4A, 0x00, 0x00, 0x92, 0x48, 0x00, 0x00, 0x47, 0x00, 0x00, 0xFF, 0x2F, 0x00
     };

#else /* ((defined(EXT_AUDIO_CHIP)) || (defined(DSP_WT_SYN)) && !defined(LOW_COST_SUPPORT)) */ /* software midi synth */

/* software AUD_SYNTH */
#define  F1RACEBACKGROUND 304
__align(2)
     const U8 F1RaceBackGround[304] = 
     {
         0x4D, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01, 0x03, 0xC0, 0x4D, 0x54,
         0x72, 0x6B, 0x00, 0x00, 0x01, 0x1A, 0x00, 0xFF, 0x02, 0x16, 0x43, 0x6F, 0x70, 0x79, 0x72, 0x69,
         0x67, 0x68, 0x74, 0x20, 0x63, 0x20, 0x32, 0x30, 0x30, 0x33, 0x20, 0x62, 0x79, 0x20, 0x43, 0x43,
         0x00, 0xFF, 0x01, 0x02, 0x43, 0x43, 0x00, 0xFF, 0x58, 0x04, 0x04, 0x02, 0x18, 0x08, 0x00, 0xFF,
         0x59, 0x02, 0x00, 0x00, 0x00, 0xFF, 0x51, 0x03, 0x06, 0xC8, 0x1C, 0x00, 0x90, 0x48, 0x6F, 0x83,
         0x60, 0x48, 0x00, 0x00, 0x4C, 0x7C, 0x83, 0x60, 0x4C, 0x00, 0x00, 0x4F, 0x7C, 0x83, 0x60, 0x4F,
         0x00, 0x00, 0x48, 0x67, 0x81, 0x70, 0x48, 0x00, 0x00, 0x4C, 0x7C, 0x85, 0x49, 0x4C, 0x00, 0x07,
         0x4F, 0x7C, 0x83, 0x60, 0x4F, 0x00, 0x00, 0x48, 0x67, 0x83, 0x60, 0x48, 0x00, 0x00, 0x4C, 0x6F,
         0x83, 0x60, 0x4C, 0x00, 0x00, 0x4D, 0x7C, 0x83, 0x60, 0x4D, 0x00, 0x00, 0x51, 0x7C, 0x83, 0x60,
         0x51, 0x00, 0x00, 0x54, 0x7C, 0x83, 0x60, 0x54, 0x00, 0x00, 0x4D, 0x7C, 0x81, 0x70, 0x4D, 0x00,
         0x00, 0x51, 0x7C, 0x85, 0x50, 0x54, 0x7C, 0x06, 0x51, 0x00, 0x83, 0x5A, 0x54, 0x00, 0x00, 0x4D,
         0x7D, 0x83, 0x60, 0x4D, 0x00, 0x00, 0x51, 0x7C, 0x83, 0x60, 0x51, 0x00, 0x00, 0x4F, 0x7C, 0x83,
         0x60, 0x4F, 0x00, 0x00, 0x53, 0x5A, 0x83, 0x60, 0x53, 0x00, 0x00, 0x56, 0x7C, 0x83, 0x60, 0x56,
         0x00, 0x00, 0x4F, 0x6F, 0x81, 0x70, 0x4F, 0x00, 0x00, 0x53, 0x7C, 0x85, 0x50, 0x59, 0x7C, 0x0E,
         0x53, 0x00, 0x83, 0x52, 0x59, 0x00, 0x00, 0x4F, 0x7C, 0x83, 0x60, 0x4F, 0x00, 0x00, 0x53, 0x7C,
         0x83, 0x60, 0x53, 0x00, 0x00, 0x54, 0x7C, 0x83, 0x60, 0x54, 0x00, 0x00, 0x58, 0x67, 0x83, 0x60,
         0x58, 0x00, 0x00, 0x5B, 0x7C, 0x83, 0x60, 0x5B, 0x00, 0x00, 0x54, 0x6F, 0x81, 0x70, 0x54, 0x00,
         0x00, 0x58, 0x7C, 0x85, 0x28, 0x58, 0x00, 0x28, 0x5B, 0x6F, 0x83, 0x60, 0x5B, 0x00, 0x00, 0x54,
         0x6F, 0x83, 0x60, 0x54, 0x00, 0x00, 0x58, 0x7C, 0x83, 0x60, 0x58, 0x00, 0x00, 0xFF, 0x2F, 0x00
     };

#endif /* ((defined(EXT_AUDIO_CHIP)) || (defined(DSP_WT_SYN)) && !defined(LOW_COST_SUPPORT)) */ 

#define  F1RACECRASH 132
__align(2)
     const U8 F1RaceCrash[132] = 
     {
         0x4D, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01, 0x03, 0xC0, 0x4D, 0x54, 0x72,
         0x6B, 0x00, 0x00, 0x00, 0x6E, 0x00, 0xFF, 0x03, 0x08, 0x75, 0x6E, 0x74, 0x69, 0x74, 0x6C, 0x65,
         0x64, 0x00, 0xFF, 0x02, 0x16, 0x43, 0x6F, 0x70, 0x79, 0x72, 0x69, 0x67, 0x68, 0x74, 0x20, 0x63,
         0x20, 0x32, 0x30, 0x30, 0x33, 0x20, 0x62, 0x79, 0x20, 0x43, 0x43, 0x00, 0xFF, 0x01, 0x03, 0x43,
         0x43, 0x0A, 0x00, 0xFF, 0x58, 0x04, 0x04, 0x02, 0x18, 0x08, 0x00, 0xFF, 0x59, 0x02, 0x00, 0x00,
         0x00, 0xFF, 0x51, 0x03, 0x09, 0x27, 0xC0, 0x00, 0xC0, 0x7F, 0x00, 0xB0, 0x07, 0x64, 0x11, 0x90,
         0x28, 0x67, 0x10, 0x2B, 0x67, 0x03, 0x29, 0x7D, 0x1D, 0x26, 0x7F, 0x03, 0x24, 0x6F, 0x9C, 0x45,
         0x29, 0x00, 0x0F, 0x2B, 0x00, 0x82, 0x63, 0x24, 0x00, 0x13, 0x28, 0x00, 0x10, 0x26, 0x00, 0x00,
         0xFF, 0x2F, 0x00
     };

/******************************************AUDIO************************************/

/************************************************************************/
/* Golbal Varable [228 Byte]                                */
/************************************************************************/

static BOOL f1race_is_new_game = TRUE;
static BOOL f1race_is_crashing = FALSE;
static S16 f1race_crashing_count_down;
static S16 f1race_separator_0_block_start_y;
static S16 f1race_separator_1_block_start_y;
static BOOL f1race_key_up_pressed;
static BOOL f1race_key_down_pressed;
static BOOL f1race_key_right_pressed;
static BOOL f1race_key_left_pressed;

static S16 f1race_last_car_road;        /* use this to avoid oppoiste car appear in same road */
static BOOL f1race_player_is_car_fly;   /* True or false */
static S16 f1race_player_car_fly_duration;
static S16 f1race_score;
static S16 f1race_level;
static S16 f1race_pass;
static S16 f1race_fly_count;
static S16 f1race_fly_charger_count;

static F1RACE_CAR_STRUCT f1race_player_car; /* 11 Byte */
static F1RACE_OPPOSITE_CAR_TYPE_STRUCT f1race_opposite_car_type[F1RACE_OPPOSITE_CAR_TYPE_COUNT];        /* 9*7 = 63 Byte */
static F1RACE_OPPOSITE_CAR_STRUCT f1race_opposite_car[F1RACE_OPPOSITE_CAR_COUNT];       /* 16*8 = 124 Byte */

 #if defined (__MMI_GAME_MULTICHANNEL_SOUND__)
static S32 background_midi;
S32 crash_midi;
 #endif /* defined (__MMI_GAME_MULTICHANNEL_SOUND__) */ 

#ifdef  __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ /*added for game multi-language*/
static U16 mmi_f1race_language_index;
#define MMI_F1RACE_STRING_COUNT MMI_F1RACE_STRING_TOTAL
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

/************************************************************************/
/* Function Declare                                      */
/************************************************************************/
/* Game framework related functions */
void F1Race_Enter_GFX(void);
void F1Race_Draw_GameOver(void);
void F1Race_Enter_Game(void);
void F1Race_Exit_Game(void);
S16 F1Race_Calc_Best_Grade(S16 old_grade, S16 new_grade);

/* Game play functions */
void F1Race_Render_Background(void);
void F1Race_Render_Road(void);
void F1Race_CollisionCheck(void);
void F1Race_Render_Separator(void);
void F1Race_Render_Player_Car_Crash(void);
void F1Race_Render_Player_Car(void);
void F1Race_Render_Opposite_Car(void);
void F1Race_Init(void);
void F1Race_Render_Status(void);
void F1Race_Render(void);
void F1Race_New_Opposite_Car(void);
void F1Race_Framemove(void);
void F1Race_Cyclic_Timer(void);
void F1Race_Crashing(void);
void F1Race_Main(void);
void F1Race_Key_Up_Pressed(void);
void F1Race_Key_Down_Pressed(void);
void F1Race_Key_Right_Pressed(void);
void F1Race_Key_Left_Pressed(void);
void F1Race_Key_Up_Released(void);
void F1Race_Key_Down_Released(void);
void F1Race_Key_Right_Released(void);
void F1Race_Key_Left_Released(void);
void F1Race_Key_Fly_Pressed(void);
void F1Race_Keyboard_Key_Handler(S32 vkey_code, S32 key_state);
void F1Race_Start_BGM(void);

/* void F1Race_Resume_BGM(void *info); */


/*****************************************************************************
 * FUNCTION
 *  F1Race_Enter_GFX
 * DESCRIPTION
 *  Set Game Framework (GFX) Parameter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Enter_GFX(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Game menu */
    GFX.game_data.game_img_id = IMG_GX_F1RACE_GAME_ICON;    /* game icon img ID */
    GFX.game_data.game_str_id = STR_GX_F1RACE_GAME_NAME;    /* game name string ID */
    GFX.game_data.menu_resume_str_id = STR_GAME_RESUME;     /* "Resume" string ID */
    GFX.game_data.menu_new_str_id = STR_GAME_NEW;           /* "New Game" string ID */
    GFX.game_data.menu_level_str_id = 0;                    /* no level string */
    GFX.game_data.menu_grade_str_id = STR_GAME_GRADE;       /* "Best Grade" string ID */
    GFX.game_data.menu_help_str_id = STR_GLOBAL_HELP;         /* "Game Help string ID */

    /* level / grade */
    GFX.game_data.level_count = 1;                          /* how many levels */
    GFX.game_data.level_str_id_list[0] = STR_GAME_SCORE;    /* level string ID */
    GFX.game_data.grade_nvram_id_list[0] = NVRAM_F1RACE_SCORE;  /* grade slot in NVRAM */

    /* help */
    GFX.game_data.help_str_id = STR_GX_F1RACE_HELP_DESCRIPTION; /* help desciption string id */

    /* misc */
    GFX.game_data.grade_value_ptr = (S16*) (&f1race_score); /* current level's grade (S16*) */
    GFX.game_data.is_new_game = (BOOL*) (&f1race_is_new_game); /* ptr to new game flag (BOOL*) */

    /* function ptr */
    GFX.game_data.best_grade_func_ptr = F1Race_Calc_Best_Grade; /* function to calculate best grade */
    GFX.game_data.enter_game_func_ptr = F1Race_Enter_Game;  /* function to enter new game */
    GFX.game_data.exit_game_func_ptr = F1Race_Exit_Game;    /* function to exit game */
    GFX.game_data.draw_gameover_func_ptr = F1Race_Draw_GameOver;        /* function to draw gameover screen */

    /* some flags */
    GFX.game_data.is_keypad_audio_enable = FALSE;   /* play keypad tone or not */

    mmi_gfx_entry_menu_screen();
}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Calc_Best_Grade
 * DESCRIPTION
 *  Calculate new best grade [Callback required by GFX]
 * PARAMETERS
 *  old_grade       [IN]        
 *  new_grade       [IN]        
 * RETURNS
 *  S16
 *****************************************************************************/
S16 F1Race_Calc_Best_Grade(S16 old_grade, S16 new_grade)
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
 *  F1Race_Draw_GameOver
 * DESCRIPTION
 *  Draw Gameover Screen [Callback required by GFX]
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Draw_GameOver(void)
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
    mmi_gfx_draw_gameover_screen(IMG_GX_F1RACE_GOTEXT, IMG_GX_F1RACE_GRADESMAP, IMG_GX_F1RACE_GOPIC, f1race_score);
#else
    mmi_gfx_draw_gameover_screen(
        mmi_gfx_get_multilanguage_image_ID(
         mmi_f1race_language_index, 
         IMG_GX_F1RACE_STATUS_SCORE_LANGUAGE0, 
         MMI_F1RACE_STRING_COUNT, 
         MMI_F1RACE_STRING_GAMEOVER),
        IMG_GX_F1RACE_GRADESMAP,
        IMG_GX_F1RACE_GOPIC,
        f1race_score);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Enter_Game
 * DESCRIPTION
 *  Enter Game [Callback required by GFX]
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Enter_Game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__  //used for multilanguage
    mmi_f1race_language_index = g_mmi_game_current_language_index;
    mmi_gfx_check_image_get_valid_language(
        &mmi_f1race_language_index, 
        IMG_GX_F1RACE_STATUS_SCORE_LANGUAGE0, 
        MMI_F1RACE_STRING_COUNT);
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

    clear_screen();

    SetKeyHandler(F1Race_Key_Fly_Pressed, KEY_5, KEY_EVENT_DOWN);

    SetKeyHandler(F1Race_Key_Up_Pressed, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(F1Race_Key_Down_Pressed, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(F1Race_Key_Right_Pressed, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(F1Race_Key_Left_Pressed, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(F1Race_Key_Up_Released, KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(F1Race_Key_Down_Released, KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(F1Race_Key_Right_Released, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(F1Race_Key_Left_Released, KEY_LEFT_ARROW, KEY_EVENT_UP);

    SetKeyHandler(F1Race_Key_Up_Pressed, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(F1Race_Key_Down_Pressed, KEY_8, KEY_EVENT_DOWN);
    SetKeyHandler(F1Race_Key_Right_Pressed, KEY_6, KEY_EVENT_DOWN);
    SetKeyHandler(F1Race_Key_Left_Pressed, KEY_4, KEY_EVENT_DOWN);

    SetKeyHandler(F1Race_Key_Up_Released, KEY_2, KEY_EVENT_UP);
    SetKeyHandler(F1Race_Key_Down_Released, KEY_8, KEY_EVENT_UP);
    SetKeyHandler(F1Race_Key_Right_Released, KEY_6, KEY_EVENT_UP);
    SetKeyHandler(F1Race_Key_Left_Released, KEY_4, KEY_EVENT_UP);

    register_keyboard_key_handler(F1Race_Keyboard_Key_Handler);

    /* set bgm resume handle */
    /* SetProtocolEventHandler(F1Race_Resume_BGM, PRT_EQ_PLAY_AUDIO_FINISH_IND); */

    F1Race_Main();
}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Exit_Game
 * DESCRIPTION
 *  Exit Game [Callback required by GFX]
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Exit_Game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    GFX_STOP_MULTICHANNEL_MIDI(crash_midi);
    GFX_CLOSE_MULTICHANNEL_MIDI(crash_midi);

    GFX_STOP_DUMMY_BACKGROUND_SOUND();
    GFX_CLOSE_DUMMY_BACKGROUND_SOUND();

    GFX_STOP_BACKGROUND_SOUND(background_midi);
    GFX_CLOSE_BACKGROUND_SOUND(background_midi);
#else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    gui_cancel_timer(F1Race_Start_BGM);
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

    gui_cancel_timer(F1Race_Cyclic_Timer);

    /* reset bgm resume handler */
    /* SetProtocolEventHandler(NULL, PRT_EQ_PLAY_AUDIO_FINISH_IND); */
}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Render_Background
 * DESCRIPTION
 *  Render Background
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Render_Background(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* this background will only draw once */
    /* draw display border and grass part that will not be modified */

    color c = gui_color(255, 255, 255);
    UI_filled_area background_border = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
        UI_IMAGE_ID_NULL,
        NULL,
        {255, 255, 255, 100},   /* white filling */
        {0, 0, 0, 0},
        {0, 0, 0, 100},         /* black border */
        {0, 0, 0, 0},
        0
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear background to white, can remove this if have proper screen category */
    gui_fill_rectangle(
        F1RACE_DISPLAY_START_X - 3,
        F1RACE_DISPLAY_START_Y - 3,
        F1RACE_DISPLAY_END_X + 3,
        F1RACE_DISPLAY_END_Y + 3,
        c);

    /* draw dispaly region border, draw outer line */
    gui_draw_filled_area(
        F1RACE_DISPLAY_START_X - 1,
        F1RACE_DISPLAY_START_Y - 1,
        F1RACE_DISPLAY_END_X + 1,
        F1RACE_DISPLAY_END_Y + 1,
        &background_border);

    /* draw left grass */
    c = gui_color(130, 230, 100);   /* green */
    gui_fill_rectangle(F1RACE_GRASS_0_START_X, F1RACE_DISPLAY_START_Y, F1RACE_GRASS_0_END_X, F1RACE_DISPLAY_END_Y, c);

    /* draw shdowed border between grass and road */
    c = gui_color(100, 180, 100);   /* drak green */
    gui_draw_vertical_line(F1RACE_DISPLAY_START_Y, F1RACE_DISPLAY_END_Y, F1RACE_GRASS_0_END_X - 1, c);

    c = gui_color(0, 0, 0); /* back */
    gui_draw_vertical_line(F1RACE_DISPLAY_START_Y, F1RACE_DISPLAY_END_Y, F1RACE_GRASS_0_END_X, c);

    /* draw rigth grass */
    c = gui_color(130, 230, 100);   /* green */
    gui_fill_rectangle(F1RACE_GRASS_1_START_X, F1RACE_DISPLAY_START_Y, F1RACE_GRASS_1_END_X, F1RACE_DISPLAY_END_Y, c);

    /* draw shdowed border between grass and road */
    c = gui_color(100, 180, 100);   /* drak green */
    gui_draw_vertical_line(F1RACE_DISPLAY_START_Y, F1RACE_DISPLAY_END_Y, F1RACE_GRASS_1_START_X + 1, c);

    c = gui_color(0, 0, 0); /* back */
    gui_draw_vertical_line(F1RACE_DISPLAY_START_Y, F1RACE_DISPLAY_END_Y, F1RACE_GRASS_1_START_X, c);

    c = gui_color(0, 0, 0); /* back */
    gui_fill_rectangle(F1RACE_STATUS_START_X, F1RACE_DISPLAY_START_Y, F1RACE_STATUS_END_X, F1RACE_DISPLAY_END_Y, c);

    /* render status Column */
    gui_show_image(F1RACE_STATUS_START_X, F1RACE_DISPLAY_START_Y, (PU8) get_image(IMG_GX_F1RACE_STATUS_LOGO));

    /* position hard coded.. Since it will only use here. */
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    gui_show_image(F1RACE_STATUS_START_X + 5, F1RACE_DISPLAY_START_Y + 42, (PU8) get_image(IMG_GX_F1RACE_STATUS_SCORE));
#else
    gui_show_image(
        F1RACE_STATUS_START_X + 5, 
        F1RACE_DISPLAY_START_Y + 38,  
        (PU8) get_image(
            mmi_gfx_get_multilanguage_image_ID(
             mmi_f1race_language_index, 
             IMG_GX_F1RACE_STATUS_SCORE_LANGUAGE0, 
             MMI_F1RACE_STRING_COUNT, 
             MMI_F1RACE_STRING_SCORE)));
#endif

    gui_show_image(F1RACE_STATUS_START_X + 2, F1RACE_DISPLAY_START_Y + 50, (PU8) get_image(IMG_GX_F1RACE_STATUS_BOX));

    /* position hard coded.. Since it will only use here. */
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    gui_show_image(F1RACE_STATUS_START_X + 6, F1RACE_DISPLAY_START_Y + 64, (PU8) get_image(IMG_GX_F1RACE_STATUS_LEVEL));
#else
    gui_show_image(
        F1RACE_STATUS_START_X + 6, 
        F1RACE_DISPLAY_START_Y + 61,  
        (PU8) get_image(
            mmi_gfx_get_multilanguage_image_ID(
             mmi_f1race_language_index, 
             IMG_GX_F1RACE_STATUS_SCORE_LANGUAGE0, 
             MMI_F1RACE_STRING_COUNT, 
             MMI_F1RACE_STRING_LEVEL)));
#endif
    gui_show_image(F1RACE_STATUS_START_X + 2, F1RACE_DISPLAY_START_Y + 72, (PU8) get_image(IMG_GX_F1RACE_STATUS_BOX));

#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    gui_show_image(F1RACE_STATUS_START_X + 2, F1RACE_DISPLAY_START_Y + 89, (PU8) get_image(IMG_GX_F1RACE_STATUS_FLY));
#else
    gui_show_image(
        F1RACE_STATUS_START_X + 2, 
        F1RACE_DISPLAY_START_Y + 86,  
        (PU8) get_image(
            mmi_gfx_get_multilanguage_image_ID(
             mmi_f1race_language_index, 
             IMG_GX_F1RACE_STATUS_SCORE_LANGUAGE0, 
             MMI_F1RACE_STRING_COUNT, 
             MMI_F1RACE_STRING_FLY)));
#endif
}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Render_Road
 * DESCRIPTION
 *  Render Road
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Render_Road(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_fill_rectangle(
        F1RACE_ROAD_0_START_X,
        F1RACE_DISPLAY_START_Y,
        F1RACE_ROAD_2_END_X,
        F1RACE_DISPLAY_END_Y,
        gui_color(150, 150, 150));
}


/*****************************************************************************
 * FUNCTION
 *  F1Race_CollisionCheck
 * DESCRIPTION
 *  Collision test - test if hit other car or not
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_CollisionCheck(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;
    S16 minA_x, minA_y, maxA_x, maxA_y;
    S16 minB_x, minB_y, maxB_x, maxB_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* A is player car */
    minA_x = f1race_player_car.pos_x - 1;
    maxA_x = minA_x + f1race_player_car.dx - 1;
    minA_y = f1race_player_car.pos_y - 1;
    maxA_y = minA_y + f1race_player_car.dy - 1;

    for (index = 0; index < F1RACE_OPPOSITE_CAR_COUNT; index++)
    {
        if (f1race_opposite_car[index].is_empty == FALSE)
        {
            /* not empty, process bbox check */
            minB_x = f1race_opposite_car[index].pos_x - 1;
            maxB_x = minB_x + f1race_opposite_car[index].dx - 1;
            minB_y = f1race_opposite_car[index].pos_y - 1;
            maxB_y = minB_y + f1race_opposite_car[index].dy - 1;

            /* x axis */
            if (((minA_x <= minB_x) && (minB_x <= maxA_x)) || ((minA_x <= maxB_x) && (maxB_x <= maxA_x)))
            {
                /* y axis */
                if (((minA_y <= minB_y) && (minB_y <= maxA_y)) || ((minA_y <= maxB_y) && (maxB_y <= maxA_y)))
                {
                    F1Race_Crashing();
                    return;
                }
            }

            /* check left up corner */
            if ((minA_x >= minB_x) && (minA_x <= maxB_x) && (minA_y >= minB_y) && (minA_y <= maxB_y))
            {
                F1Race_Crashing();
                return;
            }

            /* check left down corner */
            if ((minA_x >= minB_x) && (minA_x <= maxB_x) && (maxA_y >= minB_y) && (maxA_y <= maxB_y))
            {
                F1Race_Crashing();
                return;
            }

            /* check right up corner */
            if ((maxA_x >= minB_x) && (maxA_x <= maxB_x) && (minA_y >= minB_y) && (minA_y <= maxB_y))
            {
                F1Race_Crashing();
                return;
            }

            /* check right down corner */
            if ((maxA_x >= minB_x) && (maxA_x <= maxB_x) && (maxA_y >= minB_y) && (maxA_y <= maxB_y))
            {
                F1Race_Crashing();
                return;
            }

            /* calculate score */
            if ((maxA_y < minB_y) && (f1race_opposite_car[index].is_add_score == FALSE))
            {
                f1race_score++;
                f1race_pass++;
                f1race_opposite_car[index].is_add_score = TRUE;

                /* change level */
                if (f1race_pass == 10)
                {
                    f1race_level++; /* level 2 */
                }
                else if (f1race_pass == 20)
                {
                    f1race_level++; /* level 3 */
                }
                else if (f1race_pass == 30)
                {
                    f1race_level++; /* level 4 */
                }
                else if (f1race_pass == 40)
                {
                    f1race_level++; /* level 5 */
                }
                else if (f1race_pass == 50)
                {
                    f1race_level++; /* level 6 */
                }
                else if (f1race_pass == 60)
                {
                    f1race_level++; /* level 7 */
                }
                else if (f1race_pass == 70)
                {
                    f1race_level++; /* level 8 */
                }
                else if (f1race_pass == 100)
                {
                    f1race_level++; /* level 9 */
                }

                f1race_fly_charger_count++;
                if (f1race_fly_charger_count >= 6)
                {
                    if (f1race_fly_count < F1RACE_MAX_FLY_COUNT)
                    {
                        f1race_fly_charger_count = 0;
                        f1race_fly_count++;
                    }
                    else    /* fly count each max. */
                    {
                        f1race_fly_charger_count--;
                    }
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Render_Separator
 * DESCRIPTION
 *  Render the separator between two road. Will move over time
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Render_Separator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 start_y, end_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_fill_rectangle(
        F1RACE_SEPARATOR_0_START_X,
        F1RACE_DISPLAY_START_Y,
        F1RACE_SEPARATOR_0_END_X,
        F1RACE_DISPLAY_END_Y,
        gui_color(250, 250, 250));

    gui_fill_rectangle(
        F1RACE_SEPARATOR_1_START_X,
        F1RACE_DISPLAY_START_Y,
        F1RACE_SEPARATOR_1_END_X,
        F1RACE_DISPLAY_END_Y,
        gui_color(250, 250, 250));

    /* separator 0 */
    start_y = f1race_separator_0_block_start_y;
    end_y = start_y + F1RACE_SEPARATOR_HEIGHT_SPACE;

    while (1)
    {
        gui_fill_rectangle(
            F1RACE_SEPARATOR_0_START_X,
            start_y,
            F1RACE_SEPARATOR_0_END_X,
            end_y,
            gui_color(150, 150, 150));

        start_y += F1RACE_SEPARATOR_HEIGHT;
        end_y = start_y + F1RACE_SEPARATOR_HEIGHT_SPACE;

        if (start_y > F1RACE_DISPLAY_END_Y)
        {
            break;
        }

        if (end_y > F1RACE_DISPLAY_END_Y)
        {
            end_y = F1RACE_DISPLAY_END_Y;
        }
    }

    f1race_separator_0_block_start_y += F1RACE_SEPARATOR_HEIGHT_SPACE;
    if (f1race_separator_0_block_start_y >=
        (F1RACE_DISPLAY_START_Y + F1RACE_SEPARATOR_HEIGHT_SPACE * F1RACE_SEPARATOR_RATIO))
    {
        f1race_separator_0_block_start_y = F1RACE_DISPLAY_START_Y;
    }

    /* separator 1 */
    start_y = f1race_separator_1_block_start_y;
    end_y = start_y + F1RACE_SEPARATOR_HEIGHT_SPACE;

    while (1)
    {
        gui_fill_rectangle(
            F1RACE_SEPARATOR_1_START_X,
            start_y,
            F1RACE_SEPARATOR_1_END_X,
            end_y,
            gui_color(150, 150, 150));

        start_y += F1RACE_SEPARATOR_HEIGHT;
        end_y = start_y + F1RACE_SEPARATOR_HEIGHT_SPACE;

        if (start_y > F1RACE_DISPLAY_END_Y)
        {
            break;
        }

        if (end_y > F1RACE_DISPLAY_END_Y)
        {
            end_y = F1RACE_DISPLAY_END_Y;
        }
    }

    f1race_separator_1_block_start_y += F1RACE_SEPARATOR_HEIGHT_SPACE;
    if (f1race_separator_1_block_start_y >=
        (F1RACE_DISPLAY_START_Y + F1RACE_SEPARATOR_HEIGHT_SPACE * F1RACE_SEPARATOR_RATIO))
    {
        f1race_separator_1_block_start_y = F1RACE_DISPLAY_START_Y;
    }

}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Render_Player_Car_Crash
 * DESCRIPTION
 *  Render the car crash image
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Render_Player_Car_Crash(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_show_transparent_image(
        f1race_player_car.pos_x,
        f1race_player_car.pos_y - 5,
        (PU8) get_image(IMG_GX_F1RACE_PLAYER_CAR_CRASH),
        0);

}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Render_Player_Car
 * DESCRIPTION
 *  Render the player car
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Render_Player_Car(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 dx;
    S16 dy;
    PU8 image;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (f1race_player_is_car_fly == FALSE)
    {
        /* car on land */
        gui_show_transparent_image(f1race_player_car.pos_x, f1race_player_car.pos_y, f1race_player_car.image, 0);
    }
    else
    {

        /* car is flying */

        dx = (F1RACE_PLAYER_CAR_FLY_IMAGE_SIZE_X - F1RACE_PLAYER_CAR_IMAGE_SIZE_X) / 2;
        dy = (F1RACE_PLAYER_CAR_FLY_IMAGE_SIZE_Y - F1RACE_PLAYER_CAR_IMAGE_SIZE_Y) / 2;

        dx = f1race_player_car.pos_x - dx;
        dy = f1race_player_car.pos_y - dy;

        switch (f1race_player_car_fly_duration)
        {
            case 0:
            case 1:
                image = (PU8) get_image(IMG_GX_F1RACE_PLAYER_CAR_FLY_UP);
                break;

            case (F1RACE_PLAYER_CAR_FLY_FRAME_COUNT - 1):
            case (F1RACE_PLAYER_CAR_FLY_FRAME_COUNT - 2):
                image = (PU8) get_image(IMG_GX_F1RACE_PLAYER_CAR_FLY_DOWN);
                break;
            default:
                image = (PU8) get_image(IMG_GX_F1RACE_PLAYER_CAR_FLY);
                break;
        }

        gui_show_transparent_image(dx, dy, image, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Render_Opposite_Car
 * DESCRIPTION
 *  Render opposite direction cars
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Render_Opposite_Car(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < F1RACE_OPPOSITE_CAR_COUNT; index++)
    {
        if (f1race_opposite_car[index].is_empty == FALSE)
        {
            gui_show_transparent_image(
                f1race_opposite_car[index].pos_x,
                f1race_opposite_car[index].pos_y,
                f1race_opposite_car[index].image,
                0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Init
 * DESCRIPTION
 *  Initization Parameters
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    f1race_key_up_pressed = FALSE;
    f1race_key_down_pressed = FALSE;
    f1race_key_right_pressed = FALSE;
    f1race_key_left_pressed = FALSE;

    /* Init separator position */
    /* separator_1 shift 3 steps that they wont align in same line */
    f1race_separator_0_block_start_y = F1RACE_DISPLAY_START_Y;
    f1race_separator_1_block_start_y = F1RACE_DISPLAY_START_Y + F1RACE_SEPARATOR_HEIGHT_SPACE * 3;

    /* Init player car */
    /* place at center road */

    f1race_player_car.pos_x = ((F1RACE_ROAD_1_START_X + F1RACE_ROAD_1_END_X - F1RACE_PLAYER_CAR_IMAGE_SIZE_X) / 2);
    f1race_player_car.dx = F1RACE_PLAYER_CAR_IMAGE_SIZE_X;
    f1race_player_car.pos_y = F1RACE_DISPLAY_END_Y - F1RACE_PLAYER_CAR_IMAGE_SIZE_Y - 1;
    f1race_player_car.dy = F1RACE_PLAYER_CAR_IMAGE_SIZE_Y;
    f1race_player_car.image = (PU8) get_image(IMG_GX_F1RACE_PLAYER_CAR);
    f1race_player_car.image_fly = (PU8) get_image(IMG_GX_F1RACE_PLAYER_CAR_FLY);
    f1race_player_car.image_head_light = (PU8) get_image(IMG_GX_F1RACE_PLAYER_CAR_HEAD_LIGHT);

    /* TODO change init opposite to MARCO ??* */

    /* Init opposite car type */

    f1race_opposite_car_type[0].dx = F1RACE_OPPOSITE_CAR_0_IMAGE_SIZE_X;
    f1race_opposite_car_type[0].dy = F1RACE_OPPOSITE_CAR_0_IMAGE_SIZE_Y;
    f1race_opposite_car_type[0].image = (PU8) get_image(IMG_GX_F1RACE_OPPOSITE_CAR_0);
    f1race_opposite_car_type[0].speed = 3;
    f1race_opposite_car_type[0].dx_from_road = (F1RACE_ROAD_WIDTH - F1RACE_OPPOSITE_CAR_0_IMAGE_SIZE_X) / 2;

    f1race_opposite_car_type[1].dx = F1RACE_OPPOSITE_CAR_1_IMAGE_SIZE_X;
    f1race_opposite_car_type[1].dy = F1RACE_OPPOSITE_CAR_1_IMAGE_SIZE_Y;
    f1race_opposite_car_type[1].image = (PU8) get_image(IMG_GX_F1RACE_OPPOSITE_CAR_1);
    f1race_opposite_car_type[1].speed = 4;
    f1race_opposite_car_type[1].dx_from_road = (F1RACE_ROAD_WIDTH - F1RACE_OPPOSITE_CAR_1_IMAGE_SIZE_X) / 2;

    f1race_opposite_car_type[2].dx = F1RACE_OPPOSITE_CAR_2_IMAGE_SIZE_X;
    f1race_opposite_car_type[2].dy = F1RACE_OPPOSITE_CAR_2_IMAGE_SIZE_Y;
    f1race_opposite_car_type[2].image = (PU8) get_image(IMG_GX_F1RACE_OPPOSITE_CAR_2);
    f1race_opposite_car_type[2].speed = 6;
    f1race_opposite_car_type[2].dx_from_road = (F1RACE_ROAD_WIDTH - F1RACE_OPPOSITE_CAR_2_IMAGE_SIZE_X) / 2;

    f1race_opposite_car_type[3].dx = F1RACE_OPPOSITE_CAR_3_IMAGE_SIZE_X;
    f1race_opposite_car_type[3].dy = F1RACE_OPPOSITE_CAR_3_IMAGE_SIZE_Y;
    f1race_opposite_car_type[3].image = (PU8) get_image(IMG_GX_F1RACE_OPPOSITE_CAR_3);
    f1race_opposite_car_type[3].speed = 3;
    f1race_opposite_car_type[3].dx_from_road = (F1RACE_ROAD_WIDTH - F1RACE_OPPOSITE_CAR_3_IMAGE_SIZE_X) / 2;

    f1race_opposite_car_type[4].dx = F1RACE_OPPOSITE_CAR_4_IMAGE_SIZE_X;
    f1race_opposite_car_type[4].dy = F1RACE_OPPOSITE_CAR_4_IMAGE_SIZE_Y;
    f1race_opposite_car_type[4].image = (PU8) get_image(IMG_GX_F1RACE_OPPOSITE_CAR_4);
    f1race_opposite_car_type[4].speed = 3;
    f1race_opposite_car_type[4].dx_from_road = (F1RACE_ROAD_WIDTH - F1RACE_OPPOSITE_CAR_4_IMAGE_SIZE_X) / 2;

    f1race_opposite_car_type[5].dx = F1RACE_OPPOSITE_CAR_5_IMAGE_SIZE_X;
    f1race_opposite_car_type[5].dy = F1RACE_OPPOSITE_CAR_5_IMAGE_SIZE_Y;
    f1race_opposite_car_type[5].image = (PU8) get_image(IMG_GX_F1RACE_OPPOSITE_CAR_5);
    f1race_opposite_car_type[5].speed = 5;
    f1race_opposite_car_type[5].dx_from_road = (F1RACE_ROAD_WIDTH - F1RACE_OPPOSITE_CAR_5_IMAGE_SIZE_X) / 2;

    f1race_opposite_car_type[6].dx = F1RACE_OPPOSITE_CAR_6_IMAGE_SIZE_X;
    f1race_opposite_car_type[6].dy = F1RACE_OPPOSITE_CAR_6_IMAGE_SIZE_Y;
    f1race_opposite_car_type[6].image = (PU8) get_image(IMG_GX_F1RACE_OPPOSITE_CAR_6);
    f1race_opposite_car_type[6].speed = 3;
    f1race_opposite_car_type[6].dx_from_road = (F1RACE_ROAD_WIDTH - F1RACE_OPPOSITE_CAR_6_IMAGE_SIZE_X) / 2;

    /* Init opposite car list */
    for (index = 0; index < F1RACE_OPPOSITE_CAR_COUNT; index++)
    {
        f1race_opposite_car[index].is_empty = TRUE; /* clear all slot, no car */
        f1race_opposite_car[index].is_add_score = FALSE;
    }

    f1race_is_crashing = FALSE;
    f1race_last_car_road = 0;
    f1race_player_is_car_fly = FALSE;
    f1race_score = 0;
    f1race_level = 1;
    f1race_pass = 0;
    f1race_fly_count = 1;
    f1race_fly_charger_count = 0;
}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Render_Status
 * DESCRIPTION
 *  Render Status ( Score/level, etc )
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Render_Status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 x_pos;
    S16 y_pos;
    S16 value;
    S16 remain;
    S16 score;
    color c;
    S16 index;

    MMI_ID_TYPE image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* start pos for score box , position hard coded.... */
    /* clear box with black */
    c = gui_color(0, 0, 0); /* back */
    gui_fill_rectangle(
        F1RACE_STATUS_START_X + 4,
        F1RACE_DISPLAY_START_Y + 52,
        F1RACE_STATUS_START_X + 29,
        F1RACE_DISPLAY_START_Y + 58,
        c);

    x_pos = F1RACE_STATUS_START_X + 25;
    y_pos = F1RACE_DISPLAY_START_Y + 52;
    score = f1race_score;

    value = score % 10;
    remain = score / 10;

    while (1)
    {
        image_id = IMG_GX_F1RACE_NUMBER_0 + value;
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

    /* render level */
    c = gui_color(0, 0, 0); /* back */
    gui_fill_rectangle(
        F1RACE_STATUS_START_X + 4,
        F1RACE_DISPLAY_START_Y + 74,
        F1RACE_STATUS_START_X + 29,
        F1RACE_DISPLAY_START_Y + 80,
        c);

    x_pos = F1RACE_STATUS_START_X + 16;
    y_pos = F1RACE_DISPLAY_START_Y + 74;

    image_id = IMG_GX_F1RACE_NUMBER_0 + f1race_level;
    gui_show_image(x_pos, y_pos, (PU8) get_image(image_id));

    /* render fly status */

    /* charger bar */
    x_pos = F1RACE_STATUS_START_X + 4;
    y_pos = F1RACE_DISPLAY_START_Y + 102;
    for (index = 0; index < 5; index++)
    {
        if (index < f1race_fly_charger_count)
        {
            c = gui_color(255, 0, 0);
        }
        else
        {
            c = gui_color(100, 100, 100);
        }

        gui_fill_rectangle(x_pos + index * 4, y_pos - 2 - index, x_pos + 2 + index * 4, y_pos, c);
    }

    /* fly count */
    image_id = IMG_GX_F1RACE_NUMBER_0 + f1race_fly_count;
    x_pos = F1RACE_STATUS_START_X + 25;
    y_pos = F1RACE_DISPLAY_START_Y + 96;
    gui_show_image(x_pos, y_pos, (PU8) get_image(image_id));

}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Render
 * DESCRIPTION
 *  Render
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Render(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_clip(F1RACE_STATUS_START_X, F1RACE_DISPLAY_START_Y, F1RACE_STATUS_END_X, F1RACE_DISPLAY_END_Y);

    F1Race_Render_Status();

    gui_set_clip(F1RACE_ROAD_0_START_X, F1RACE_DISPLAY_START_Y, F1RACE_ROAD_2_END_X, F1RACE_DISPLAY_END_Y);
    F1Race_Render_Road();
    F1Race_Render_Separator();
    F1Race_Render_Opposite_Car();
    F1Race_Render_Player_Car();
}


/*****************************************************************************
 * FUNCTION
 *  F1Race_New_Opposite_Car
 * DESCRIPTION
 *  Randomly create a new car in opposite direction
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_New_Opposite_Car(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;
    S16 validIndex = 0;
    S16 no_slot;
    S16 car_type = 0;
    U16 road;
    S16 car_pos_x = 0;
    S16 car_shift;
    S16 enough_space;
    S16 rand_num;
    S16 speed_add;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* random generate new car based on SHOW_RATE */
    no_slot = TRUE;
    if ((rand() % F1RACE_OPPOSITE_CAR_DEFAULT_APPEAR_RATE) == 0)
    {
        /* enter here will try to create a new opposite car */
        for (index = 0; index < F1RACE_OPPOSITE_CAR_COUNT; index++)
        {
            if (f1race_opposite_car[index].is_empty != FALSE)
            {
                validIndex = index;
                no_slot = FALSE;
                break;
            }
        }
    }

    /* no slot availabe */
    if (no_slot != FALSE)
    {
        return;
    }

    /* choose opposite car type */
    road = rand() % 3;  /* 3 = road count */

    /* avoid one car after another in the same road */
    if (road == f1race_last_car_road)
    {
        road++;
        road %= 3;
    }

    /* proablilty for showing different car */
    /* 0,1      = trunk, */
    /* 2,3,4    = red small car */
    /* 5     = race car */
    /* 6, 7     = green small car */
    /* 8     = small truck */
    /* 9        = red sport */
    /* 10    = s.small truck */

    if (f1race_level < 3)
    {
        rand_num = rand() % 11;
        switch (rand_num)
        {
            case 0:
            case 1:
                car_type = 0;
                break;

            case 2:
            case 3:
            case 4:
                car_type = 1;
                break;
            case 5:
                car_type = 2;
                break;
            case 6:
            case 7:
                car_type = 3;
                break;
            case 8:
                car_type = 4;
                break;
            case 9:
                car_type = 5;
                break;
            case 10:
                car_type = 6;
                break;
        }
    }

    /* proablilty for showing different car */
    /* 0,1      = trunk, */
    /* 2,3,4    = red small car */
    /* 5     = race car */
    /* 6, 7     = green small car */
    /* 8     = small truck */
    /* 9        = red sport */
    /* 10    = s.small truck */

    if (f1race_level >= 3)
    {
        rand_num = rand() % 11;
        switch (rand_num)
        {
            case 0:
                car_type = 0;
                break;

            case 1:
            case 2:
                car_type = 1;
                break;
            case 3:
            case 4:
                car_type = 2;
                break;
            case 5:
            case 6:
                car_type = 3;
                break;
            case 7:
                car_type = 4;
                break;
            case 8:
            case 9:
                car_type = 5;
                break;
            case 10:
                car_type = 6;
                break;
        }
    }
    /* car_type = 6; */
    /* make sure there is enought space for user car to change road */
    enough_space = TRUE;
    for (index = 0; index < F1RACE_OPPOSITE_CAR_COUNT; index++)
    {
        if ((f1race_opposite_car[index].is_empty == FALSE) &&
            (f1race_opposite_car[index].pos_y < (F1RACE_PLAYER_CAR_IMAGE_SIZE_Y * 1.5)))
        {
            enough_space = FALSE;
        }
    }

    if (enough_space == FALSE)
    {
        return;
    }

    speed_add = f1race_level - 1;

    /* Init opposite car */
    f1race_opposite_car[validIndex].is_empty = FALSE;
    f1race_opposite_car[validIndex].is_add_score = FALSE;
    f1race_opposite_car[validIndex].dx = f1race_opposite_car_type[car_type].dx;
    f1race_opposite_car[validIndex].dy = f1race_opposite_car_type[car_type].dy;
    f1race_opposite_car[validIndex].speed = f1race_opposite_car_type[car_type].speed + speed_add;
    f1race_opposite_car[validIndex].dx_from_road = f1race_opposite_car_type[car_type].dx_from_road;
    f1race_opposite_car[validIndex].image = f1race_opposite_car_type[car_type].image;

    car_shift = f1race_opposite_car[validIndex].dx_from_road;

    switch (road)
    {
        case 0:
            car_pos_x = F1RACE_ROAD_0_START_X + car_shift;
            break;
        case 1:
            car_pos_x = F1RACE_ROAD_1_START_X + car_shift;
            break;
        case 2:
            car_pos_x = F1RACE_ROAD_2_START_X + car_shift;
            break;
    }

    f1race_opposite_car[validIndex].pos_x = car_pos_x;
    f1race_opposite_car[validIndex].pos_y = F1RACE_DISPLAY_START_Y - f1race_opposite_car[validIndex].dy;
    f1race_opposite_car[validIndex].road_id = (U8) road;

    f1race_last_car_road = road;

}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Framemove
 * DESCRIPTION
 *  Framemove, calcualte the movement
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Framemove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 shift;
    S16 max;
    S16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if stop fly */
    f1race_player_car_fly_duration++;
    if (f1race_player_car_fly_duration == F1RACE_PLAYER_CAR_FLY_FRAME_COUNT)
    {
        f1race_player_is_car_fly = FALSE;
    }

    /* Player car movement */
    shift = F1RACE_PLAYER_CAR_SHIFT;
    if (f1race_key_up_pressed)
    {
        if (f1race_player_car.pos_y - shift < F1RACE_DISPLAY_START_Y)
        {
            shift = f1race_player_car.pos_y - F1RACE_DISPLAY_START_Y - 1;
        }

        if (f1race_player_is_car_fly == FALSE)
        {
            f1race_player_car.pos_y -= shift;
        }
    }

    if (f1race_key_down_pressed)
    {
        max = f1race_player_car.pos_y + f1race_player_car.dy;
        if (max + shift > F1RACE_DISPLAY_END_Y)
        {
            shift = F1RACE_DISPLAY_END_Y - max;
        }

        if (f1race_player_is_car_fly == FALSE)
        {
            f1race_player_car.pos_y += shift;
        }
    }

    if (f1race_key_right_pressed)
    {
        max = f1race_player_car.pos_x + f1race_player_car.dx;
        if (max + shift > F1RACE_ROAD_2_END_X)
        {
            shift = F1RACE_ROAD_2_END_X - max;
        }

        f1race_player_car.pos_x += shift;
    }

    if (f1race_key_left_pressed)
    {
        if (f1race_player_car.pos_x - shift < F1RACE_ROAD_0_START_X)
        {
            shift = f1race_player_car.pos_x - F1RACE_ROAD_0_START_X - 1;
        }

        f1race_player_car.pos_x -= shift;
    }

    /* Oppoiste Car movement */
    for (index = 0; index < F1RACE_OPPOSITE_CAR_COUNT; index++)
    {
        if (f1race_opposite_car[index].is_empty == FALSE)
        {
            /* move one step foward */
            f1race_opposite_car[index].pos_y += f1race_opposite_car[index].speed;

            /* Test if this car within valid display region */
            if (f1race_opposite_car[index].pos_y > (F1RACE_DISPLAY_END_Y + f1race_opposite_car[index].dy))
            {
                /* out of display region, free the slot */
                f1race_opposite_car[index].is_empty = TRUE;
            }

        }
    }

    /* Player car fly */
    if (f1race_player_is_car_fly != FALSE)
    {
        /* car fly movement */
        shift = F1RACE_PLAYER_CAR_FLY_SHIFT;
        if (f1race_player_car.pos_y - shift < F1RACE_DISPLAY_START_Y)
        {
            shift = f1race_player_car.pos_y - F1RACE_DISPLAY_START_Y - 1;
        }

        f1race_player_car.pos_y -= shift;
    }
    else
    {
        /* Car not flying , process collision Test */
        F1Race_CollisionCheck();
    }

    F1Race_New_Opposite_Car();

}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Cyclic_Timer
 * DESCRIPTION
 *  Game cyclic timer - looping
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Cyclic_Timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_start_timer(F1RACE_TIMER_ELAPSE, F1Race_Cyclic_Timer);

    /* 0 = false. (not gameover) */
    if (f1race_is_crashing == FALSE)
    {
        F1Race_Framemove();
        F1Race_Render();
    }
    else
    {
        f1race_crashing_count_down--;
        F1Race_Render_Player_Car_Crash();

        if (f1race_crashing_count_down <= 0)
        {
            f1race_is_crashing = FALSE;
            f1race_is_new_game = TRUE;
            mmi_gfx_entry_gameover_screen();
        }
    }

    gui_BLT_double_buffer(0, 0, 127, 127);
}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Crashing
 * DESCRIPTION
 *  Gameover
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Crashing(void)
{
#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GFX_STOP_MULTICHANNEL_MIDI(crash_midi);

    GFX_PLAY_MULTICHANNEL_MIDI(crash_midi);
#else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    GFX_PLAY_AUDIO_MIDI(F1RaceCrash, F1RACECRASH, DEVICE_AUDIO_PLAY_ONCE);
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

    GFX_PLAY_VIBRATION();

    f1race_is_crashing = TRUE;
    f1race_crashing_count_down = 10;
}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Main
 * DESCRIPTION
 *  Main function
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Init Race game */
    if (f1race_is_new_game != FALSE)
    {
        F1Race_Init();
        f1race_is_new_game = FALSE;
    }

    /* Render First Frame */
    F1Race_Render_Background();
    F1Race_Render();

    /* Delay some time then play BGM */
    /* or AUDIO will not have enough time to parse MIDI if user in/out game frenquently */
#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    GFX_OPEN_BACKGROUND_SOUND(F1RaceBackGround, F1RACEBACKGROUND, background_midi);
    GFX_PLAY_BACKGROUND_SOUND(background_midi);

    GFX_OPEN_DUMMY_BACKGROUND_SOUND();
    GFX_PLAY_DUMMY_BACKGROUND_SOUND();

    GFX_OPEN_MULTICHANNEL_MIDI(F1RaceCrash, F1RACECRASH, 1, crash_midi);
#else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    gui_start_timer(500, F1Race_Start_BGM);
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

    gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);

    gui_start_timer(F1RACE_TIMER_ELAPSE, F1Race_Cyclic_Timer);

    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);

    if (f1race_is_crashing == TRUE)
    {
        GFX_PLAY_VIBRATION();
    }

}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Start_BGM
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Start_BGM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!f1race_is_crashing)
    {
        GFX_PLAY_AUDIO_MIDI(F1RaceBackGround, F1RACEBACKGROUND, DEVICE_AUDIO_PLAY_INFINITE);
    }
}

/*****************************************************************************
* FUNCTION
*  F1Race_Resume_BGM
* DESCRIPTION
*  Key handling
* PARAMETERS
*  viod
* RETURNS
*  void
* GLOBALS AFFECTED
*  NIL
****************************************************************************/
//void F1Race_Resume_BGM(void *info)
//{
//      if( GFX_is_audio_on == TRUE )
//      {
//              SetRingerVolume(GFX_audio_volumn);      
//              PlayAudioMidiStream((PU8)F1RaceBackGround, F1RACEBACKGROUND, DEVICE_AUDIO_PLAY_INFINITE);
//}
//}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Key_Up_Pressed
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Key_Up_Pressed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    F1RACE_RELEASE_ALL_KEY;
    f1race_key_up_pressed = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Key_Down_Pressed
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Key_Down_Pressed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    F1RACE_RELEASE_ALL_KEY;
    f1race_key_down_pressed = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Key_Right_Pressed
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Key_Right_Pressed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    F1RACE_RELEASE_ALL_KEY;
    f1race_key_right_pressed = TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Key_Left_Pressed
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Key_Left_Pressed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    F1RACE_RELEASE_ALL_KEY;
    f1race_key_left_pressed = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Key_Up_Released
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Key_Up_Released(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    f1race_key_up_pressed = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Key_Down_Released
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Key_Down_Released(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    f1race_key_down_pressed = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Key_Right_Released
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Key_Right_Released(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    f1race_key_right_pressed = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Key_Left_Released
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Key_Left_Released(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    f1race_key_left_pressed = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Key_Fly_Pressed
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Key_Fly_Pressed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (f1race_player_is_car_fly != FALSE)
    {
        return;
    }

    if (f1race_fly_count > 0)
    {
        f1race_player_is_car_fly = TRUE;
        f1race_player_car_fly_duration = 0;
        f1race_fly_count--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  F1Race_Keyboard_Key_Handler
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  vkey_code       [IN]        
 *  key_state       [IN]        
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void F1Race_Keyboard_Key_Handler(S32 vkey_code, S32 key_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32)
    if (key_state)
    {
        switch (vkey_code)  /* key down */
        {
            case 37:
                F1Race_Key_Left_Pressed();  /* left */
                break;
            case 38:
                F1Race_Key_Up_Pressed();    /* up */
                break;
            case 39:
                F1Race_Key_Right_Pressed(); /* right */
                break;
            case 40:
                F1Race_Key_Down_Pressed();  /* down */
                break;
                //     case 1:         tetris_handle_key_exit();
                //                             break;
        }
    }
    else    /* key up */
    {
        switch (vkey_code)
        {
            case 37:
                F1Race_Key_Left_Released();     /* left */
                break;
            case 38:
                F1Race_Key_Up_Released();       /* up */
                break;
            case 39:
                F1Race_Key_Right_Released();    /* right */
                break;
            case 40:
                F1Race_Key_Down_Released();     /* down */
                break;
                //     case 1:         tetris_handle_key_exit();
                //                             break;
        }
    }
#else /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 
    UI_UNUSED_PARAMETER(vkey_code);
    UI_UNUSED_PARAMETER(key_state);
#endif /* (MMI_BUILD_TYPE == BUILD_TYPE_X86WIN32) */ 

}

#endif /* IS_F1RACE_BASE_GAME */ 

