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
 *  Doll.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Catch Doll Game
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

#ifdef __MMI_GAME_DOLL__
#include "GameInc.h"
#include "DollProts.h"
#include "mmi_rp_app_games_def.h"
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
#include "GameProts.h"
#endif
/************************************************************************/
/* Game Defines                                                         */
/************************************************************************/
#define DOLL_NO_PARENT                 (0xff)
#define DOLL_NO_CHILD                  (0xfe)
#define DOLL_NO_SEAL                   (0xff)   /* no seal in this postion */

#define DOLL_SEAL_TYPE_COUNT           (4)
#define DOLL_SEAL_COUNT                (16)     /* 16 seal pos in 4 level, 3 4 5 4 */

#define DOLL_CLAW_COUNT                (4)

#define DOLL_SEAL_WIDTH                (30)
#define DOLL_SEAL_HEIGHT               (30)

#define DOLL_ARM_ONE_STEP_HOR          (4)
#define DOLL_ARM_ONE_STEP_VER          (3)

#define DOLL_ARM_EXTENTION_MIN         (15)
#define DOLL_ARM_EXTENTION_MAX         (85)
#define DOLL_ARM_POSITION_MIN          (22)
#define DOLL_ARM_POSITION_MAX          (120)

#define DOLL_DEFAULT_TIMER_ELAPSE      (100)
#define DOLL_CLAW_TIMER_ELAPSE         (300)

#define DOLL_DEFAULT_COIN_COUNT        (10)
#define DOLL_CATCHED_DROP_FRAME_COUNT  (5)

#define SEAL_DROP_FRAME_COUNT          (4)

#define DOLL_IDLE_TIME                 (30000)  /* 30 sec */

#define DOLL_LCD_WIDTH                 (128)
#define DOLL_LCD_HEIGHT                (128)

/************************************************************************/
/* Structure                                                            */
/************************************************************************/
typedef struct
{
    U8 x;
    U8 y;
    U8 parent_idx[2];
    U8 child_idx[2];
} DOLL_SEAL_STRUCT;

typedef struct
{
    BOOL is_drop;
    U8 parent_idx;
} DOLL_SEAL_DROP_STRUCT;

typedef struct
{
    S16 x_start_shift;
    S16 y_start_shift;
    S16 extent_limit;
} DOLL_ARM_STRUCT;

typedef struct
{
    S16 shift_x;
} DOLL_CLAW_STRUCT;

typedef struct
{
    BOOL is_catched;
    U16 img_id;
} DOLL_CATCH_DOLL_STRUCT;

typedef enum
{
    ARM_MOVE_ORIGINAL,
    ARM_MOVE_RIGHT,
    ARM_MOVE_LEFT,
    ARM_MOVE_DOWN,
    ARM_MOVE_UP,
    CLAW_OPEN,
    CLAW_CLOSE,
    DOLL_DROP
} DOLL_STATE_ENUM;

/************************************************************************/
/* Golbal Varable [Const]                                               */
/************************************************************************/
/* doll arrangement - 16 doll position in 4 level */
/*
 *    13  14  15  
 *    09  10  11  12
 *    04  05  06  07  08
 *    00  01  02  03
 */
static const DOLL_SEAL_STRUCT seal_list[DOLL_SEAL_COUNT] = 
{
    {34, 102,
     {4, 5},
     {DOLL_NO_CHILD, DOLL_NO_CHILD}},   /* 0 */

    {56, 102,
     {5, 6},
     {DOLL_NO_CHILD, DOLL_NO_CHILD}},   /* 1 */

    {78, 102,
     {6, 7},
     {DOLL_NO_CHILD, DOLL_NO_CHILD}},   /* 2 */

    {100, 102,
     {7, 8},
     {DOLL_NO_CHILD, DOLL_NO_CHILD}},   /* 3 */

    {32, 88,
     {DOLL_NO_PARENT, 9},
     {DOLL_NO_CHILD, 0}},   /* 4 */

    {45, 88,
     {9, 10},
     {0, 1}},   /* 5 */

    {67, 88,
     {10, 11},
     {1, 2}},   /* 6 */

    {89, 88,
     {11, 12},
     {2, 3}},   /* 7 */

    {111, 88,
     {12, DOLL_NO_PARENT},
     {3, DOLL_NO_CHILD}},   /* 8 */

    {34, 74,
     {DOLL_NO_PARENT, 13},
     {4, 5}},   /* 9 */

    {56, 74,
     {13, 14},
     {5, 6}},   /* 10 */

    {78, 74,
     {14, 15},
     {6, 7}},   /* 11 */

    {100, 74,
     {15, DOLL_NO_PARENT},
     {7, 8}},   /* 12 */

    {45, 59,
     {DOLL_NO_PARENT, DOLL_NO_PARENT},
     {9, 10}},  /* 13 */

    {67, 59,
     {DOLL_NO_PARENT, DOLL_NO_PARENT},
     {9, 10}},  /* 14 */

    {89, 59,
     {DOLL_NO_PARENT, DOLL_NO_PARENT},
     {11, 12}}, /* 15 */
};

static const DOLL_CLAW_STRUCT claw_list[DOLL_CLAW_COUNT] = 
{
    {-19},
    {-18},
    {-17},
    {-16}
};

/************************************************************************/
/* Audio [Const]                                                        */
/************************************************************************/
#define DOLL_AUD_BGM             1045   /* midi */
#define DOLL_AUD_CATCH_GOOD      2875   /* dvi */
#define DOLL_AUD_CATCH_BAD       2000   /* dvi */

__align(2)
     const U8 doll_aud_bgm[1045] = 
     {
         0x4D, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06,
         0x00, 0x00, 0x00, 0x01, 0x03, 0xC0, 0x4D, 0x54,
         0x72, 0x6B, 0x00, 0x00, 0x03, 0xFF, 0x00, 0xFF,
         0x03, 0x08, 0x75, 0x6E, 0x74, 0x69, 0x74, 0x6C,
         0x65, 0x64, 0x00, 0xFF, 0x02, 0x16, 0x43, 0x6F,
         0x70, 0x79, 0x72, 0x69, 0x67, 0x68, 0x74, 0x20,
         0x63, 0x20, 0x32, 0x30, 0x30, 0x33, 0x20, 0x62,
         0x79, 0x20, 0x43, 0x43, 0x00, 0xFF, 0x01, 0x03,
         0x43, 0x43, 0x0A, 0x00, 0xFF, 0x58, 0x04, 0x04,
         0x02, 0x18, 0x08, 0x00, 0xFF, 0x59, 0x02, 0x00,
         0x00, 0x00, 0xFF, 0x51, 0x03, 0x05, 0x07, 0xC6,
         0x00, 0xC1, 0x38, 0x00, 0xB1, 0x07, 0x78, 0x00,
         0x07, 0x70, 0x00, 0x91, 0x58, 0x67, 0x00, 0xC3,
         0x51, 0x00, 0xB3, 0x07, 0x7E, 0x00, 0x07, 0x3A,
         0x00, 0x93, 0x3C, 0x67, 0x83, 0x60, 0x91, 0x58,
         0x00, 0x81, 0x70, 0x57, 0x7C, 0x81, 0x70, 0x57,
         0x00, 0x00, 0x58, 0x67, 0x00, 0x93, 0x4C, 0x6F,
         0x00, 0x48, 0x7C, 0x14, 0x3C, 0x00, 0x83, 0x4C,
         0x91, 0x58, 0x00, 0x81, 0x70, 0x93, 0x4C, 0x00,
         0x00, 0x48, 0x00, 0x00, 0x91, 0x57, 0x7C, 0x81,
         0x70, 0x57, 0x00, 0x00, 0x58, 0x6F, 0x00, 0x93,
         0x3C, 0x67, 0x81, 0x70, 0x91, 0x58, 0x00, 0x81,
         0x70, 0x93, 0x3C, 0x00, 0x00, 0x91, 0x5B, 0x7C,
         0x00, 0x93, 0x4C, 0x7C, 0x00, 0x48, 0x7D, 0x85,
         0x50, 0x48, 0x00, 0x00, 0x4C, 0x00, 0x00, 0x91,
         0x5B, 0x00, 0x81, 0x70, 0x58, 0x67, 0x00, 0x93,
         0x3C, 0x5A, 0x00, 0x4C, 0x67, 0x00, 0x48, 0x6F,
         0x81, 0x70, 0x48, 0x00, 0x00, 0x91, 0x58, 0x00,
         0x00, 0x93, 0x3C, 0x00, 0x00, 0x4C, 0x00, 0x81,
         0x70, 0x91, 0x59, 0x67, 0x00, 0x93, 0x43, 0x7D,
         0x83, 0x60, 0x91, 0x59, 0x00, 0x81, 0x70, 0x5B,
         0x53, 0x81, 0x70, 0x5B, 0x00, 0x00, 0x93, 0x43,
         0x00, 0x00, 0x91, 0x59, 0x67, 0x00, 0x93, 0x4D,
         0x6F, 0x00, 0x4A, 0x7C, 0x81, 0x70, 0x91, 0x59,
         0x00, 0x81, 0x70, 0x56, 0x6F, 0x81, 0x70, 0x93,
         0x4A, 0x00, 0x81, 0x70, 0x4D, 0x00, 0x00, 0x43,
         0x7D, 0x83, 0x60, 0x43, 0x00, 0x00, 0x4D, 0x6F,
         0x00, 0x4A, 0x7C, 0x85, 0x50, 0x4A, 0x00, 0x00,
         0x4D, 0x00, 0x00, 0x91, 0x56, 0x00, 0x81, 0x70,
         0x93, 0x4D, 0x6F, 0x00, 0x4A, 0x7C, 0x00, 0x43,
         0x7C, 0x81, 0x70, 0x43, 0x00, 0x00, 0x4A, 0x00,
         0x00, 0x4D, 0x00, 0x81, 0x70, 0x91, 0x56, 0x67,
         0x00, 0x93, 0x43, 0x7C, 0x83, 0x60, 0x91, 0x56,
         0x00, 0x81, 0x70, 0x55, 0x53, 0x81, 0x70, 0x55,
         0x00, 0x00, 0x93, 0x43, 0x00, 0x00, 0x91, 0x56,
         0x67, 0x00, 0x93, 0x4F, 0x7C, 0x00, 0x4A, 0x7C,
         0x83, 0x60, 0x91, 0x56, 0x00, 0x81, 0x70, 0x93,
         0x4A, 0x00, 0x00, 0x4F, 0x00, 0x00, 0x91, 0x55,
         0x67, 0x81, 0x70, 0x55, 0x00, 0x00, 0x56, 0x53,
         0x00, 0x93, 0x43, 0x7C, 0x81, 0x70, 0x91, 0x56,
         0x00, 0x81, 0x70, 0x93, 0x43, 0x00, 0x00, 0x91,
         0x59, 0x67, 0x00, 0x93, 0x4F, 0x6F, 0x00, 0x4A,
         0x6F, 0x85, 0x50, 0x4A, 0x00, 0x00, 0x4F, 0x00,
         0x00, 0x91, 0x59, 0x00, 0x81, 0x70, 0x56, 0x5A,
         0x00, 0x93, 0x4D, 0x6F, 0x00, 0x4A, 0x6F, 0x81,
         0x70, 0x91, 0x56, 0x00, 0x81, 0x70, 0x93, 0x4A,
         0x00, 0x00, 0x4D, 0x00, 0x00, 0x91, 0x58, 0x67,
         0x00, 0x93, 0x3C, 0x67, 0x83, 0x60, 0x91, 0x58,
         0x00, 0x81, 0x70, 0x57, 0x7C, 0x81, 0x70, 0x57,
         0x00, 0x00, 0x93, 0x3C, 0x00, 0x00, 0x91, 0x58,
         0x67, 0x00, 0x93, 0x4F, 0x7D, 0x00, 0x4C, 0x7C,
         0x83, 0x60, 0x91, 0x58, 0x00, 0x81, 0x70, 0x93,
         0x4C, 0x00, 0x00, 0x4F, 0x00, 0x00, 0x91, 0x59,
         0x51, 0x81, 0x70, 0x59, 0x00, 0x00, 0x5B, 0x67,
         0x00, 0x93, 0x3C, 0x67, 0x83, 0x60, 0x3C, 0x00,
         0x00, 0x91, 0x5B, 0x00, 0x00, 0x93, 0x4F, 0x6F,
         0x00, 0x4C, 0x7C, 0x81, 0x70, 0x91, 0x54, 0x52,
         0x81, 0x70, 0x54, 0x00, 0x00, 0x58, 0x67, 0x81,
         0x70, 0x93, 0x4C, 0x00, 0x00, 0x4F, 0x00, 0x81,
         0x70, 0x91, 0x58, 0x00, 0x00, 0x93, 0x4F, 0x6F,
         0x00, 0x4C, 0x6F, 0x00, 0x3C, 0x67, 0x81, 0x70,
         0x3C, 0x00, 0x00, 0x4C, 0x00, 0x00, 0x4F, 0x00,
         0x00, 0x91, 0x5B, 0x5A, 0x81, 0x70, 0x5B, 0x00,
         0x00, 0x5D, 0x6F, 0x00, 0x93, 0x41, 0x7C, 0x83,
         0x60, 0x91, 0x5D, 0x00, 0x81, 0x70, 0x5C, 0x7C,
         0x81, 0x70, 0x5C, 0x00, 0x00, 0x93, 0x41, 0x00,
         0x00, 0x91, 0x5D, 0x48, 0x00, 0x93, 0x4D, 0x6F,
         0x00, 0x51, 0x50, 0x81, 0x70, 0x91, 0x5D, 0x00,
         0x81, 0x5C, 0x59, 0x6F, 0x82, 0x04, 0x93, 0x51,
         0x00, 0x00, 0x4D, 0x00, 0x81, 0x70, 0x41, 0x7D,
         0x81, 0x70, 0x91, 0x59, 0x00, 0x81, 0x70, 0x93,
         0x41, 0x00, 0x00, 0x91, 0x5D, 0x6F, 0x14, 0x93,
         0x4D, 0x7C, 0x00, 0x51, 0x6F, 0x83, 0x60, 0x51,
         0x00, 0x00, 0x4D, 0x00, 0x83, 0x4C, 0x51, 0x52,
         0x00, 0x4D, 0x52, 0x00, 0x41, 0x53, 0x81, 0x70,
         0x41, 0x00, 0x00, 0x91, 0x5D, 0x00, 0x00, 0x93,
         0x51, 0x00, 0x00, 0x4D, 0x00, 0x81, 0x70, 0x91,
         0x5B, 0x67, 0x00, 0x93, 0x3C, 0x53, 0x83, 0x60,
         0x91, 0x5B, 0x00, 0x81, 0x70, 0x5A, 0x7C, 0x81,
         0x70, 0x5A, 0x00, 0x00, 0x93, 0x3C, 0x00, 0x00,
         0x91, 0x5B, 0x51, 0x00, 0x93, 0x4F, 0x6F, 0x00,
         0x4C, 0x7C, 0x81, 0x70, 0x91, 0x5B, 0x00, 0x81,
         0x70, 0x58, 0x6F, 0x81, 0x70, 0x93, 0x4C, 0x00,
         0x00, 0x4F, 0x00, 0x81, 0x70, 0x3C, 0x67, 0x82,
         0x04, 0x91, 0x58, 0x00, 0x81, 0x5C, 0x93, 0x3C,
         0x00, 0x00, 0x91, 0x5B, 0x6F, 0x00, 0x93, 0x4F,
         0x7C, 0x00, 0x4C, 0x7C, 0x83, 0x60, 0x4C, 0x00,
         0x00, 0x4F, 0x00, 0x83, 0x60, 0x4F, 0x67, 0x00,
         0x4C, 0x6F, 0x00, 0x3C, 0x53, 0x81, 0x70, 0x3C,
         0x00, 0x00, 0x91, 0x5B, 0x00, 0x81, 0x70, 0x93,
         0x4C, 0x00, 0x00, 0x4F, 0x00, 0x00, 0x91, 0x59,
         0x67, 0x00, 0x93, 0x43, 0x7D, 0x83, 0x60, 0x91,
         0x59, 0x00, 0x81, 0x70, 0x58, 0x53, 0x81, 0x70,
         0x58, 0x00, 0x00, 0x93, 0x43, 0x00, 0x00, 0x91,
         0x59, 0x48, 0x00, 0x93, 0x53, 0x7C, 0x00, 0x4D,
         0x7C, 0x83, 0x60, 0x91, 0x59, 0x00, 0x81, 0x70,
         0x93, 0x4D, 0x00, 0x00, 0x53, 0x00, 0x00, 0x91,
         0x58, 0x51, 0x81, 0x70, 0x58, 0x00, 0x00, 0x56,
         0x49, 0x00, 0x93, 0x43, 0x7C, 0x83, 0x60, 0x43,
         0x00, 0x00, 0x91, 0x56, 0x00, 0x00, 0x93, 0x53,
         0x6F, 0x14, 0x4D, 0x6F, 0x81, 0x5C, 0x91, 0x55,
         0x6F, 0x81, 0x70, 0x55, 0x00, 0x00, 0x56, 0x5A,
         0x82, 0x04, 0x93, 0x53, 0x00, 0x14, 0x4D, 0x00,
         0x81, 0x0C, 0x43, 0x7C, 0x28, 0x53, 0x67, 0x14,
         0x91, 0x56, 0x00, 0x00, 0x93, 0x4D, 0x5A, 0x81,
         0x34, 0x43, 0x00, 0x28, 0x53, 0x00, 0x14, 0x4D,
         0x00, 0x00, 0x91, 0x59, 0x5A, 0x81, 0x70, 0x59,
         0x00, 0x00, 0x58, 0x5A, 0x00, 0x93, 0x3C, 0x6F,
         0x83, 0x60, 0x91, 0x58, 0x00, 0x00, 0x57, 0x67,
         0x83, 0x60, 0x57, 0x00, 0x00, 0x93, 0x3C, 0x00,
         0x00, 0x91, 0x58, 0x67, 0x00, 0x93, 0x4F, 0x6F,
         0x00, 0x4C, 0x7C, 0x81, 0x70, 0x91, 0x58, 0x00,
         0x81, 0x70, 0x54, 0x67, 0x81, 0x70, 0x93, 0x4C,
         0x00, 0x00, 0x4F, 0x00, 0x81, 0x70, 0x3C, 0x5A,
         0x83, 0x60, 0x3C, 0x00, 0x00, 0x54, 0x7C, 0x00,
         0x4C, 0x67, 0x00, 0x4F, 0x7C, 0x83, 0x60, 0x91,
         0x54, 0x00, 0x81, 0x70, 0x93, 0x54, 0x00, 0x00,
         0x4C, 0x00, 0x00, 0x4F, 0x00, 0x81, 0x70, 0x54,
         0x53, 0x00, 0x4C, 0x50, 0x00, 0x4F, 0x52, 0x83,
         0x60, 0x4F, 0x00, 0x00, 0x4C, 0x00, 0x00, 0x54,
         0x00, 0x00, 0xFF, 0x2F, 0x00,
     };

/************************************************************************/
/* Golbal Varable [94 Byte]                                 */
/************************************************************************/
static BOOL doll_is_gameover = FALSE;
static BOOL doll_is_new_game = TRUE;
static S16 doll_game_grade = 0;
static BOOL doll_is_in_game = FALSE;
static U8 doll_coin_remain = DOLL_DEFAULT_COIN_COUNT;

static U8 doll_arm_extention = DOLL_ARM_EXTENTION_MIN;
static U8 doll_arm_position = DOLL_ARM_POSITION_MIN;
static U8 doll_claw_index = 0;

static U8 doll_arm_catch_pos_x;
static U8 doll_arm_catch_pos_y;
static BOOL doll_draw_all;
static S16 doll_update_min_x;
static S16 doll_update_max_x;
static S16 doll_update_min_y;
static S16 doll_update_max_y;

static U8 doll_seal_render_sequence[DOLL_SEAL_COUNT];
static U8 doll_seal_img_id[DOLL_SEAL_COUNT];
static U8 doll_catched_drop_countdown;
static U8 doll_seal_drop_frame;

static DOLL_STATE_ENUM doll_state = ARM_MOVE_ORIGINAL;
static DOLL_CATCH_DOLL_STRUCT doll_catched_doll;    /* 4 byte */
static DOLL_SEAL_DROP_STRUCT doll_seal_drop[DOLL_SEAL_COUNT];   /* 32 byte */

 #if defined (__MMI_GAME_MULTICHANNEL_SOUND__)
static S32 background_midi;
 #endif 

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__  //added for multi-language support
U16 mmi_doll_language_index;
#define MMI_DOLL_STRING_COUNT 1
#endif

/************************************************************************/
/* Function Declare                                      */
/************************************************************************/
/* call back function for GFX */
S16 Doll_Calc_Best_Grade(S16, S16); /* descide which is best grade */
void Doll_Enter_Game(void);         /* entry function of the game */
void Doll_Exit_Game(void);          /* exit function - usually will stop timer and release buffer */
void Doll_Draw_GameOver(void);      /* draw gameover screen */

/* Game function */
void Doll_Right_Arrow(void);
void Doll_Down_Arrow(void);
void Doll_ReStack_Seal(void);
void Doll_Catch_Test(void);
void Doll_Init(void);
void Doll_Framemove(void);
void Doll_Draw_Background_Grid(U16 x1, U16 y1, U16 x2, U16 y2);
void Doll_Render(void);
void Doll_Gameover(void);
void Doll_Cyclic_Timer(void);
void Doll_IDle_Too_Long(void);
void Doll_Start_BGM(void);

/* void Doll_Resume_BGM(void *info); */


/*****************************************************************************
 * FUNCTION
 *  Doll_Enter_GFX
 * DESCRIPTION
 *  Set Game Framework (GFX) Parameter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Doll_Enter_GFX(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Game menu */
    GFX.game_data.game_img_id = IMG_GX_DOLL_GAME_ICON;  /* game icon img ID */
    GFX.game_data.game_str_id = STR_GX_DOLL_GAME_NAME;  /* game name string ID */
    GFX.game_data.menu_resume_str_id = STR_GAME_RESUME; /* "Resume" string ID */
    GFX.game_data.menu_new_str_id = STR_GAME_NEW;       /* "New Game" string ID */
    GFX.game_data.menu_level_str_id = 0;                /* "Game Level" string ID */
    GFX.game_data.menu_grade_str_id = STR_GAME_GRADE;   /* "Best Grade" string ID */
    GFX.game_data.menu_help_str_id = STR_GLOBAL_HELP;     /* "Game Help string ID */

    /* level / grade */
    GFX.game_data.level_count = 1;  /* how many levels */
    GFX.game_data.level_str_id_list[0] = STR_GAME_SCORE;
    GFX.game_data.grade_nvram_id_list[0] = NVRAM_GAME_DOLL_GRADE;       /* grade slot in NVRAM (short) */

    /* help */
    GFX.game_data.help_str_id = STR_GX_DOLL_HELP_DESCRIPTION;   /* help desciption string id */

    /* misc */
    GFX.game_data.grade_value_ptr = (S16*) (&doll_game_grade); /* current level's grade (S16*) */
    GFX.game_data.is_new_game = (BOOL*) & doll_is_new_game; /* ptr to new game flag (BOOL*) */

    /* function ptr */
    GFX.game_data.best_grade_func_ptr = Doll_Calc_Best_Grade;   /* function to calculate best grade */
    GFX.game_data.enter_game_func_ptr = Doll_Enter_Game;    /* function to enter new game */
    GFX.game_data.exit_game_func_ptr = Doll_Exit_Game;      /* function to exit game */
    GFX.game_data.draw_gameover_func_ptr = Doll_Draw_GameOver;  /* function to draw gameover screen */

    /* some flags */
    GFX.game_data.is_keypad_audio_enable = FALSE;   /* play keypad tone or not */

    mmi_gfx_entry_menu_screen();
}


/*****************************************************************************
 * FUNCTION
 *  Doll_Calc_Best_Grade
 * DESCRIPTION
 *  Calculate new best grade [Callback required by GFX]
 * PARAMETERS
 *  old_grade       [IN]        
 *  new_grade       [IN]        
 * RETURNS
 *  S16
 *****************************************************************************/
S16 Doll_Calc_Best_Grade(S16 old_grade, S16 new_grade)
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
 *  Doll_Draw_GameOver
 * DESCRIPTION
 *  Draw Gameover Screen [Callback required by GFX]
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Doll_Draw_GameOver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GFX_PLAY_AUDIO_COMPLETE();

    /* call this function to draw standard gameover screen */
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    mmi_gfx_draw_gameover_screen(IMG_GX_DOLL_GOTEXT, IMG_GX_DOLL_GRADESMAP, IMG_GX_DOLL_CATCHED, doll_game_grade);
#else
    mmi_gfx_draw_gameover_screen(
     mmi_gfx_get_multilanguage_image_ID(
         mmi_doll_language_index, 
         IMG_GX_DOLL_GOTEXT_LANGUAGE0, 
         MMI_DOLL_STRING_COUNT, 
         0), 
     IMG_GX_DOLL_GRADESMAP, 
     IMG_GX_DOLL_CATCHED, 
     doll_game_grade);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  Doll_Enter_Game
 * DESCRIPTION
 *  Enter Game [Callback required by GFX]
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Doll_Enter_Game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    doll_is_in_game = TRUE;
    clear_screen();
    SetKeyHandler(Doll_Right_Arrow, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Doll_Down_Arrow, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Doll_Right_Arrow, KEY_6, KEY_EVENT_DOWN);
    SetKeyHandler(Doll_Down_Arrow, KEY_8, KEY_EVENT_DOWN);

    if (doll_is_new_game == TRUE)
    {
        doll_is_new_game = FALSE;
        Doll_Init();
    }

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__      /*used for multi-language*/
    mmi_doll_language_index = g_mmi_game_current_language_index;
    mmi_gfx_check_image_get_valid_language(&mmi_doll_language_index, IMG_GX_DOLL_GOTEXT_LANGUAGE0, MMI_DOLL_STRING_COUNT);
#endif  /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

    doll_update_min_x = 0;
    doll_update_max_x = (S16) DOLL_LCD_WIDTH;
    doll_update_min_y = 0;
    doll_update_max_y = (S16) DOLL_LCD_HEIGHT;

    doll_draw_all = TRUE;

    /* Delay some time then play BGM */
    /* or AUDIO will not have enough time to parse MIDI if user in/out game frenquently */
#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    GFX_OPEN_BACKGROUND_SOUND(doll_aud_bgm, DOLL_AUD_BGM, background_midi);
    GFX_PLAY_BACKGROUND_SOUND(background_midi);

    GFX_OPEN_DUMMY_BACKGROUND_SOUND();
    GFX_PLAY_DUMMY_BACKGROUND_SOUND();
#else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    gui_start_timer(500, Doll_Start_BGM);
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

    gui_start_timer(100, Doll_Cyclic_Timer);
    gui_start_timer(DOLL_IDLE_TIME, Doll_IDle_Too_Long);

    /* set bgm resume handle */
    /* SetProtocolEventHandler(Doll_Resume_BGM, PRT_EQ_PLAY_AUDIO_FINISH_IND); */

    Doll_Render();

}


/*****************************************************************************
 * FUNCTION
 *  Doll_Exit_Game
 * DESCRIPTION
 *  Exit Game [Callback required by GFX]
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Doll_Exit_Game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    doll_is_in_game = FALSE;
    gui_cancel_timer(Doll_Cyclic_Timer);
    gui_cancel_timer(Doll_IDle_Too_Long);
#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    GFX_STOP_DUMMY_BACKGROUND_SOUND();
    GFX_CLOSE_DUMMY_BACKGROUND_SOUND();

    GFX_STOP_BACKGROUND_SOUND(background_midi);
    GFX_CLOSE_BACKGROUND_SOUND(background_midi);
#else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    gui_cancel_timer(Doll_Start_BGM);
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 

    /* reset bgm resume handler */
    /* SetProtocolEventHandler(NULL, PRT_EQ_PLAY_AUDIO_FINISH_IND); */
}


/*****************************************************************************
 * FUNCTION
 *  Doll_IDle_Too_Long
 * DESCRIPTION
 *  Will back to menu when idle too long.
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Doll_IDle_Too_Long(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    doll_is_in_game = FALSE;
    gui_cancel_timer(Doll_Cyclic_Timer);
    gui_cancel_timer(Doll_IDle_Too_Long);
    gui_cancel_timer(Doll_Start_BGM);

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  Doll_Start_BGM
 * DESCRIPTION
 *  Function to start BGM
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Doll_Start_BGM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GFX_PLAY_AUDIO_MIDI(doll_aud_bgm, DOLL_AUD_BGM, DEVICE_AUDIO_PLAY_INFINITE);
}

/*****************************************************************************
* FUNCTION
*  Doll_Resume_BGM
* DESCRIPTION
*  Function to resume BGM  
* PARAMETERS
*  viod
* RETURNS
*  void
* GLOBALS AFFECTED
*  NIL
*****************************************************************************/
//void Doll_Resume_BGM(void *info)
//{
//
//      if( GFX_is_audio_on == TRUE )
//      {
//              SetRingerVolume(GFX_audio_volumn);      
//              PlayAudioMidiStream((PU8)doll_aud_bgm, DOLL_AUD_BGM, DEVICE_AUDIO_PLAY_INFINITE);
//      }
//}


/*****************************************************************************
 * FUNCTION
 *  Doll_Right_Arrow
 * DESCRIPTION
 *  Right arrow key handler
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Doll_Right_Arrow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (doll_state == ARM_MOVE_ORIGINAL)
    {
        doll_state = ARM_MOVE_RIGHT;

        if (doll_coin_remain > 0)
        {
            doll_coin_remain--;
        }

        Doll_Cyclic_Timer();
    }
    gui_start_timer(DOLL_IDLE_TIME, Doll_IDle_Too_Long);
}


/*****************************************************************************
 * FUNCTION
 *  Doll_Down_Arrow
 * DESCRIPTION
 *  Down arrow key handler
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Doll_Down_Arrow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (doll_state == ARM_MOVE_RIGHT)
    {
        doll_state = ARM_MOVE_DOWN;
    }
    else if (doll_state == ARM_MOVE_DOWN)
    {
        doll_state = CLAW_CLOSE;
    }

    gui_start_timer(DOLL_IDLE_TIME, Doll_IDle_Too_Long);
}


/*****************************************************************************
 * FUNCTION
 *  Doll_ReStack_Seal
 * DESCRIPTION
 *  Restack the doll, doll drop down
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Doll_ReStack_Seal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    U8 parent_id;
    U8 parent_index = 0;
    BOOL is_first_enter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < DOLL_SEAL_COUNT; i++)
    {
        /* if this space is empty but parent not empty, move parent downward */
        if (doll_seal_img_id[i] == DOLL_NO_SEAL)
        {
            is_first_enter = TRUE;
            for (j = 0; j < 2; j++) /* loop for left and right parent */
            {

                /* random choose one parent */
                if (is_first_enter == TRUE)
                {
                    parent_index = rand() % 2;
                    is_first_enter = FALSE;
                }
                else
                {
                    parent_index = (parent_index == 0) ? 1 : 0;
                }

                parent_id = (U8) seal_list[i].parent_idx[parent_index];

                /* has parent and parent not emtpy */
                if ((doll_seal_img_id[i] == DOLL_NO_SEAL) &&
                    (parent_id != DOLL_NO_PARENT) && (doll_seal_img_id[parent_id] != DOLL_NO_SEAL))
                {
                    /* move the seal downward */
                    doll_seal_img_id[i] = doll_seal_img_id[parent_id];
                    doll_seal_img_id[parent_id] = DOLL_NO_SEAL;

                    /* get drop data to draw intermediate frames */
                    doll_seal_drop[i].is_drop = TRUE;
                    doll_seal_drop[i].parent_idx = parent_id;
                    doll_seal_drop_frame = 0;

                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  Doll_Catch_Test
 * DESCRIPTION
 *  Test if claw catch the doll
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Doll_Catch_Test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 kernal_x_min, kernal_x_max;
    U16 kernal_y_min, kernal_y_max;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < DOLL_SEAL_COUNT; i++)
    {
        if (doll_seal_img_id[i] != DOLL_NO_SEAL)    /* not empty */
        {
            kernal_x_min = seal_list[i].x + DOLL_SEAL_WIDTH / 2 - 2;
            kernal_x_max = seal_list[i].x + DOLL_SEAL_WIDTH / 2 + 3;
            kernal_y_min = seal_list[i].y + DOLL_SEAL_HEIGHT / 2 - 2;
            kernal_y_max = seal_list[i].y + DOLL_SEAL_HEIGHT / 2 + 3;

            if ((doll_arm_catch_pos_x >= kernal_x_min) &&
                (doll_arm_catch_pos_x <= kernal_x_max) &&
                (doll_arm_catch_pos_y >= kernal_y_min) && (doll_arm_catch_pos_y <= kernal_y_max))
            {
                doll_catched_doll.is_catched = TRUE;
                doll_seal_img_id[i] = DOLL_NO_SEAL;
                Doll_ReStack_Seal();

            }
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  Doll_Init
 * DESCRIPTION
 *  Init Doll game variable
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Doll_Init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    doll_game_grade = 0;

    /* randomly assign seal image id */
    for (i = 0; i < DOLL_SEAL_COUNT; i++)
    {
        while (1)
        {
            doll_seal_img_id[i] = rand() % DOLL_SEAL_TYPE_COUNT;
            if (i != 0)
            {
                if (doll_seal_img_id[i - 1] != doll_seal_img_id[i])
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }

    gui_set_clip(0, 0, DOLL_LCD_WIDTH, DOLL_LCD_HEIGHT);

    for (i = 0; i < DOLL_SEAL_COUNT; i++)
    {
        doll_seal_drop[i].is_drop = FALSE;
        doll_seal_drop[i].parent_idx = DOLL_NO_SEAL;
    }

    /* remove some seal from above list */
    doll_seal_img_id[4] = DOLL_NO_SEAL;
    doll_seal_img_id[8] = DOLL_NO_SEAL;
    doll_seal_img_id[9] = DOLL_NO_SEAL;
    doll_seal_img_id[12] = DOLL_NO_SEAL;
    doll_seal_img_id[13] = DOLL_NO_SEAL;
    doll_seal_img_id[15] = DOLL_NO_SEAL;

    /* init seal render sequence to make stack in a more realistic ways */
    doll_seal_render_sequence[0] = 14;
    doll_seal_render_sequence[1] = 13;
    doll_seal_render_sequence[2] = 15;

    doll_seal_render_sequence[3] = 10;
    doll_seal_render_sequence[4] = 11;
    doll_seal_render_sequence[5] = 9;
    doll_seal_render_sequence[6] = 12;

    doll_seal_render_sequence[7] = 4;
    doll_seal_render_sequence[8] = 8;
    doll_seal_render_sequence[9] = 6;
    doll_seal_render_sequence[10] = 7;
    doll_seal_render_sequence[11] = 5;

    doll_seal_render_sequence[12] = 0;
    doll_seal_render_sequence[13] = 3;
    doll_seal_render_sequence[14] = 2;
    doll_seal_render_sequence[15] = 1;

    /* set arm to start position state */
    doll_state = ARM_MOVE_ORIGINAL;

    doll_arm_extention = DOLL_ARM_EXTENTION_MIN;
    doll_arm_position = DOLL_ARM_POSITION_MIN;

    /* adjust catch kernal postion */
    doll_arm_catch_pos_x = doll_arm_position;
    doll_arm_catch_pos_y = 50;

    doll_catched_doll.img_id = IMG_GX_DOLL_CATCHED;
    doll_catched_doll.is_catched = FALSE;

    doll_state = ARM_MOVE_ORIGINAL;

    doll_coin_remain = DOLL_DEFAULT_COIN_COUNT;

    doll_claw_index = 0;
    doll_is_gameover = FALSE;

    doll_catched_drop_countdown = 0;

}


/*****************************************************************************
 * FUNCTION
 *  Doll_Framemove
 * DESCRIPTION
 *  Game logic caluclation.
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Doll_Framemove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Doll_ReStack_Seal();

    switch (doll_state)
    {
        case ARM_MOVE_RIGHT:
        {
            if (doll_arm_position < DOLL_ARM_POSITION_MAX)
            {
                doll_arm_position += DOLL_ARM_ONE_STEP_HOR;
                doll_arm_catch_pos_x += DOLL_ARM_ONE_STEP_HOR;
            }
            else    /* reach limit, force to move down */
            {
                doll_state = ARM_MOVE_DOWN;
            }

            break;
        }

        case ARM_MOVE_DOWN:
        {
            if (doll_arm_extention < DOLL_ARM_EXTENTION_MAX)
            {
                doll_arm_extention += DOLL_ARM_ONE_STEP_VER;
                doll_arm_catch_pos_y += DOLL_ARM_ONE_STEP_VER;
            }
            else    /* reach extention limit, close the claw */
            {
                doll_state = CLAW_CLOSE;
            }

            break;
        }

        case ARM_MOVE_UP:
        {
            if (doll_arm_extention > DOLL_ARM_EXTENTION_MIN)
            {
                doll_arm_extention -= DOLL_ARM_ONE_STEP_VER;
                doll_arm_catch_pos_y -= DOLL_ARM_ONE_STEP_VER;
            }
            else    /* reach extention limit, force to move up */
            {
                doll_state = ARM_MOVE_LEFT;
            }

            break;
        }

        case ARM_MOVE_LEFT:
        {
            if (doll_arm_position > DOLL_ARM_POSITION_MIN)
            {
                doll_arm_position -= DOLL_ARM_ONE_STEP_HOR;
                doll_arm_catch_pos_x -= DOLL_ARM_ONE_STEP_HOR;
            }
            else    /* open the claw */
            {
                doll_state = CLAW_OPEN;
            }

            break;
        }

        case CLAW_CLOSE:
        {
            if (doll_claw_index < DOLL_CLAW_COUNT - 1)
            {
                doll_claw_index++;
            }
            else    /* claw closed , move upward */
            {
                doll_state = ARM_MOVE_UP;
                Doll_Catch_Test();
            }

            break;
        }

        case CLAW_OPEN:
        {
            if (doll_claw_index > 0)
            {
                doll_claw_index--;
            }
            else    /* claw opened , back to original state  */
            {
                doll_state = ARM_MOVE_ORIGINAL;
                gui_cancel_timer(Doll_Cyclic_Timer);
                if (doll_coin_remain == 0)
                {
                    Doll_Gameover();
                    return;
                }
            }

            if (doll_catched_doll.is_catched == TRUE)
            {
                doll_catched_drop_countdown = DOLL_CATCHED_DROP_FRAME_COUNT;
                doll_game_grade++;
            }

            doll_catched_doll.is_catched = FALSE;
            break;
        }
    }

    /* restack - some doll will drop */
    for (i = 0; i < DOLL_SEAL_COUNT; i++)
    {
        if (doll_seal_drop_frame >= SEAL_DROP_FRAME_COUNT)
        {
            doll_seal_drop[i].is_drop = FALSE;
            doll_seal_drop[i].parent_idx = DOLL_NO_SEAL;
        }
    }
    doll_seal_drop_frame++;

    if (doll_catched_drop_countdown > 0)
    {
        doll_catched_drop_countdown--;
    }

}


/*****************************************************************************
 * FUNCTION
 *  Doll_Draw_Background_Grid
 * DESCRIPTION
 *  Render the background grid.
 * PARAMETERS
 *  x1      [IN]        Min x
 *  y1      [IN]        Min y
 *  x2      [IN]        Max x
 *  y2      [IN]        Min y
 * RETURNS
 *  void
 *****************************************************************************/
void Doll_Draw_Background_Grid(U16 x1, U16 y1, U16 x2, U16 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color dark = gui_color(62, 146, 190);
    color light = gui_color(140, 216, 255);
    U16 i;
    U16 x, y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < 8; i++)
    {

        x = i * 16;
        if (x >= x1 && x <= x2)
        {
            gui_draw_vertical_line(y1, y2, x, light);
            gui_draw_vertical_line(y1, y2, x + 1, dark);
        }
    }

    for (i = 0; i < 8; i++)
    {
        y = i * 16;
        if (y >= y1 && y <= y2)
        {
            gui_draw_horizontal_line(x1, x2, y, light);
            gui_draw_horizontal_line(x1, x2, y + 1, dark);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  Doll_Render
 * DESCRIPTION
 *  Render the screen
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Doll_Render(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i, j;
    U8 render_index;
    U16 inter_pos_x;
    U16 inter_pos_y;

    BOOL seal_dropping;
    color cc = gui_color(76, 183, 239);
    color dark = gui_color(62, 146, 190);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((doll_state == ARM_MOVE_ORIGINAL) ||    /* render first frame */
        (doll_state == ARM_MOVE_DOWN) ||
        (doll_state == ARM_MOVE_UP) || (doll_state == CLAW_CLOSE) || (doll_draw_all == TRUE))
        /* (chat_need_update == TRUE) ) */
    {

        seal_dropping = FALSE;
        for (j = 0; j < DOLL_SEAL_COUNT; j++)
        {
            if (doll_seal_drop[j].is_drop == TRUE)
            {
                seal_dropping = TRUE;
                break;
            }
        }

        if ((doll_state == ARM_MOVE_ORIGINAL) || (seal_dropping == TRUE))
        {
            gui_set_clip(0, 0, DOLL_LCD_WIDTH - 1, DOLL_LCD_HEIGHT - 1);
        }
        else
        {
            gui_set_clip(
                doll_update_min_x,
                doll_update_min_y,
                doll_update_max_x,
                doll_update_max_y + DOLL_ARM_ONE_STEP_VER + 5);
        }

        gui_fill_rectangle(43, 44, DOLL_LCD_WIDTH - 1, DOLL_LCD_HEIGHT - 1, cc);
        Doll_Draw_Background_Grid(43, 44, (U16) (DOLL_LCD_WIDTH - 1), (U16) (DOLL_LCD_HEIGHT - 1));

        if ((doll_arm_position < 33) || (doll_draw_all == TRUE))
        {
            gui_draw_vertical_line(67, DOLL_LCD_HEIGHT - 1, 0, dark);
            gui_show_image(1, 67, get_image(IMG_GX_DOLL_CAN_2));
        }

        if ((doll_arm_position < 53) || (doll_draw_all == TRUE))
        {
            gui_show_image(13, 67, get_image(IMG_GX_DOLL_CAN_1));
        }

        if ((doll_arm_position < 63) || (doll_draw_all == TRUE))
        {
            gui_show_image(33, 67, get_image(IMG_GX_DOLL_CAN_0));
        }

        /* draw seals */
        for (i = 0; i < DOLL_SEAL_COUNT; i++)
        {
            render_index = doll_seal_render_sequence[i];

            if (doll_seal_img_id[render_index] != DOLL_NO_SEAL)
            {

                if (doll_seal_drop[render_index].is_drop == FALSE)
                {
                    /* draw normal seal */
                    gui_show_transparent_image(
                        seal_list[render_index].x,
                        seal_list[render_index].y,
                        get_image((U16) (IMG_GX_DOLL_SEAL_0 + doll_seal_img_id[render_index])),
                        0);

                }
                else
                {
                    gui_set_clip(0, 0, DOLL_LCD_WIDTH - 1, DOLL_LCD_HEIGHT - 1);
                    /* draw dropping seal */
                    inter_pos_x = seal_list[render_index].x * doll_seal_drop_frame;
                    inter_pos_x +=
                        seal_list[doll_seal_drop[render_index].parent_idx].x * (SEAL_DROP_FRAME_COUNT -
                                                                                doll_seal_drop_frame);
                    inter_pos_x /= SEAL_DROP_FRAME_COUNT;

                    inter_pos_y = seal_list[render_index].y * doll_seal_drop_frame;
                    inter_pos_y +=
                        seal_list[doll_seal_drop[render_index].parent_idx].y * (SEAL_DROP_FRAME_COUNT -
                                                                                doll_seal_drop_frame);
                    inter_pos_y /= SEAL_DROP_FRAME_COUNT;

                    gui_show_transparent_image(
                        inter_pos_x,
                        inter_pos_y,
                        get_image((U16) (IMG_GX_DOLL_SEAL_0 + doll_seal_img_id[render_index])),
                        0);
                }
            }
        }
    }

    /* draw arm */
    /* clear background */
    gui_set_clip(
        doll_update_min_x,
        doll_update_min_y,
        doll_update_max_x + DOLL_ARM_ONE_STEP_HOR,
        doll_update_max_y + DOLL_ARM_ONE_STEP_VER + 2);
    gui_fill_rectangle(0, 0, DOLL_LCD_WIDTH - 1, 60, cc);
    Doll_Draw_Background_Grid(0, 0, (U16) (DOLL_LCD_WIDTH - 1), 60);

    gui_fill_rectangle(0, 60, 42, 66, cc);
    Doll_Draw_Background_Grid(0, 60, 42, 66);

    /* draw catched doll */
    if (doll_catched_doll.is_catched == TRUE)
    {
        gui_show_transparent_image(
            doll_arm_position - 12,
            doll_arm_extention + 20,
            get_image((U16) (doll_catched_doll.img_id)),
            0);
    }

    if (doll_catched_drop_countdown > 0)
    {
        gui_set_clip(0, 0, 40, 66);
        gui_fill_rectangle(0, 0, 40, 66, cc);
        Doll_Draw_Background_Grid(0, 0, 40, 66);

        inter_pos_x = DOLL_ARM_POSITION_MIN - 12;
        inter_pos_y = (doll_arm_extention + 20) * doll_catched_drop_countdown;
        inter_pos_y += (80) * (DOLL_CATCHED_DROP_FRAME_COUNT - doll_catched_drop_countdown);
        inter_pos_y /= DOLL_CATCHED_DROP_FRAME_COUNT;

        gui_show_transparent_image(inter_pos_x, inter_pos_y, get_image((U16) (doll_catched_doll.img_id)), 0);
    }

    gui_set_clip(0, 0, DOLL_LCD_WIDTH - 1, 15);
    gui_fill_rectangle(0, 0, DOLL_LCD_WIDTH - 1, 15, cc);
    Doll_Draw_Background_Grid(0, 0, (U16) (DOLL_LCD_WIDTH - 1), 15);

    /* Render catched seal icons */
    for (i = 0; i < doll_game_grade; i++)
    {
        gui_show_transparent_image(117 - 11 * i, 3, get_image(IMG_GX_DOLL_SMALLDOLL), 0);
    }

    /* Render coin */
    gui_set_clip(0, 82, 50, 100);

    if (doll_coin_remain >= 9)
    {
        gui_show_image(33, 67, get_image(IMG_GX_DOLL_CAN_0));
    }

    gui_show_image(27, 84, get_image(IMG_GX_DOLL_CAN_BOX));

    /* draw remain coin number */
    gui_show_image(27, 85, get_image((U16) (IMG_GX_DOLL_NUM_0 + doll_coin_remain)));

    gui_set_clip(
        doll_update_min_x,
        doll_update_min_y,
        doll_update_max_x + DOLL_ARM_ONE_STEP_HOR,
        doll_update_max_y + DOLL_ARM_ONE_STEP_VER);

    /* draw arm */
    gui_show_image(doll_arm_position - 1, doll_arm_extention - 90, get_image((U16) (IMG_GX_DOLL_ARM)));

    gui_show_image(doll_arm_position - 8, 0, get_image((U16) (IMG_GX_DOLL_ARM_BASE)));

    /* draw claw */
    gui_show_transparent_image(
        doll_arm_position + claw_list[doll_claw_index].shift_x,
        doll_arm_extention + 8,
        get_image((U16) (IMG_GX_DOLL_CLAW_0 + doll_claw_index)),
        0);

    doll_update_min_x = (S16) doll_arm_catch_pos_x - 19;
    doll_update_min_y = 0;
    doll_update_max_x = (S16) doll_arm_catch_pos_x + 19;
    doll_update_max_y = (S16) doll_arm_catch_pos_y + 10;

    /* gui_putpixel(doll_arm_catch_pos_x, doll_arm_catch_pos_y, c); */

    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);

    doll_draw_all = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  Doll_Gameover
 * DESCRIPTION
 *  Gameover
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Doll_Gameover(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    doll_is_gameover = TRUE;
    doll_is_new_game = TRUE;
    doll_is_in_game = FALSE;
    /* call this function to draw gameover screen */
    mmi_gfx_entry_gameover_screen();
}


/*****************************************************************************
 * FUNCTION
 *  Doll_Cyclic_Timer
 * DESCRIPTION
 *  Doll game cyclic timer. looping.
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
void Doll_Cyclic_Timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (doll_is_in_game == FALSE)
    {
        return;
    }

    Doll_Framemove();
    if (doll_is_gameover == FALSE)
    {
        Doll_Render();
        if ((doll_state == CLAW_CLOSE) || (doll_state == CLAW_OPEN))
        {
            gui_start_timer(DOLL_CLAW_TIMER_ELAPSE, Doll_Cyclic_Timer);
        }
        else
        {
            gui_start_timer(DOLL_DEFAULT_TIMER_ELAPSE, Doll_Cyclic_Timer);
        }
    }
}

#endif /* IS_DOLL_BASE_GAME */ 

