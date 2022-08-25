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
 *  GameDefs.h
  *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Game Defines
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

#ifndef GAME_DEF_H
#define GAME_DEF_H

#include "GameResDef.h"

/* skip audio align in PC environment */
#ifndef __MTK_TARGET__
#define __align(X)
#endif 

typedef enum
{

#ifdef __MMI_GAME_F1RACE__
    game_f1race,
#endif 

#ifdef __MMI_GAME_HANOI__
    game_hanoi,
#endif 

#ifdef __MMI_GAME_RICHES__
    game_riches,
#endif 

#ifdef __MMI_GAME_COLORBALL__
    game_colorballs,
#endif 

#ifdef __MMI_GAME_SNAKE__
    game_snake,
#endif 

#ifdef __MMI_GAME_SMASH__
    game_smash,
#endif 

#ifdef __MMI_GAME_DOLL__
    game_doll,
#endif 

#ifdef __MMI_GAME_MAJUNG__
    game_majung,
#endif 

#ifdef __MMI_GAME_COPTER__
    game_copter,
#endif 

#ifdef __MMI_GAME_SUBMARINE__
    game_submarine,
#endif

#ifdef __MMI_GAME_JET__
    game_jet,
#endif

#ifdef __MMI_GAME_PUZZLE__
    game_puzzle,
#endif 

#ifdef __MMI_GAME_PANDA__
    game_panda,
#endif 

#ifdef __MMI_GAME_MONKEY__
    game_panda,
#endif 

#ifdef __MMI_GAME_CHICKEN__
    game_chicken,
#endif 

#ifdef __MMI_GAME_ROBOT__
    game_robot,
#endif
#ifdef __MMI_GAME_UFO__
    game_ufo,
#endif 

#ifdef __MMI_GAME_DANCE__
    game_dance,
#endif 

#ifdef __MMI_GAME_MAGICSUSHI__
    game_magicsushi,
#endif 

#ifdef __MMI_GAME_FRUIT__
    game_fruit,
#endif 

#ifdef __MMI_GAME_VSMJ__
    game_vsmj,
#endif 

#ifdef __MMI_GAME_FRUITNINJA__
    game_fruitninja,
#endif

#ifdef __MMI_GAME_DIAMOND__
        game_diamond,
#endif 

#ifdef __MMI_GAME_NINJACLIMB__
        game_ninjaclimb,
#endif 

#ifdef __MMI_GAME_FROGCANDY__
        game_frogcandy,
#endif 

#ifdef __MMI_GAME_TRUEMAN__
        game_trueman,
#endif 

#ifdef __MMI_GAME_TOPGUN__
        game_topgun,
#endif 

    game_list_count
} GAME_LIST_NEUM;

typedef enum
{

#ifdef __MMI_MOTIONGAME_DICE__
    motion_dice,
#endif 

#ifdef __MMI_MOTIONGAME_DJ__
    motion_dj,
#endif 

    motion_list_count
} MOTION_LIST_NEUM;

#define GAME_NOTIFYDURATION                  ST_NOTIFYDURATION

#endif /* GAME_DEF_H */ 

