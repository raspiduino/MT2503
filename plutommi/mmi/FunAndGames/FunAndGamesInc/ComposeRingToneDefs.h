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

/*******************************************************************************
 * Filename:
 * ---------
 * ComposeRingToneDefs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for defining enum, constant, and data structure for ring tone composer
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : ComposeRingToneDefs.h

   PURPOSE     : Resource IDs for the ComposeRingTone Application

   REMARKS     : nil

   AUTHOR      : Ashish Garg

   DATE     : July-28-2003

**************************************************************/
#ifndef _MMI_COMPOSE_RINGTONE_DEFS_H
#define _MMI_COMPOSE_RINGTONE_DEFS_H

#include "MMI_features.h"
#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)
//#include "MMIDataType.h"
//#include "gui_data_types.h"
//#include "custom_mmi_default_value.h"
#include "custom_equipment.h"

/* 
 * Define
 */

#ifndef HARDWARE_LED_NOT_SUPPORT
    #define __MMI_RNGC_ENABLE_INS_LED_NOTE__
#endif /* #ifndef HARDWARE_LED_NOT_SUPPORT */

#define  RNGC_MAX_ENG_CHAR    26

typedef enum
{
    ENUM_COMP_OPT_PLAY = 0,
    ENUM_COMP_OPT_EDIT,
    ENUM_COMP_OPT_ADD,
    ENUM_COMP_OPT_RENAME,
    ENUM_COMP_OPT_DELETE,
    ENUM_COMP_OPT_DELETE_ALL,
    ENUM_COMP_OPT_FORWARD,
    ENUM_COMP_OPT_TOTAL
} RNGC_TONE_OPTION_ENUM;

typedef enum
{
    ENUM_COMP_ADD = 0,
    ENUM_COMP_EDIT,
    ENUM_COMP_RENAME
} RNGC_EDIT_STATE_ENUM;

typedef enum
{
    ENUM_ADD_TONE_OPT_PLAY = 0,
    ENUM_ADD_TONE_OPT_SPEED,
#ifdef __MMI_RING_COMPOSER_STYLE__	
    ENUM_ADD_TONE_OPT_STYLE,
#endif
    ENUM_ADD_TONE_OPT_INSTR,
    ENUM_ADD_TONE_OPT_SAVE,
    ENUM_ADD_TONE_OPT_TOTAL
} RNGC_COMP_TONE_OPTION_ENUM;

typedef enum
{
    ENUM_SPEED_FAST = 0,
    ENUM_SPEED_NORMAL,
    ENUM_SPEED_SLOW,
    ENUM_SPEED_TOTAL
} RNGC_SPEED_ENUM;

#ifdef __MMI_RING_COMPOSER_STYLE__	
typedef enum
{
    ENUM_CONTINUOUS_STYLE = 0,
    ENUM_NORMAL_STYLE,
    ENUM_STACCATO_STYLE,
    ENUM_STYLE_TOTAL
} RNGC_STYLE_ENUM;
#endif

typedef enum
{
    RSK_UP,
    RSK_DOWN,
    RSK_LONGPRESS
} RSK_STATES;

typedef enum
{
    RC_SUCCESS = 0,
    RC_ERROR,
    RC_EMPTY_FILENAME,
    RC_DUP_FILENAME,
    RC_MEMORY_FULL,
    RC_FILENAME_ERR
} RC_ERROR_ENUM;

enum NotesList
{
    NOTE_C = 0x0001,
    NOTE_D,
    NOTE_E,
    NOTE_F,
    NOTE_G,
    NOTE_A,
    NOTE_B,
    NOTE_REST,
    NOTE_VIBRATION_ON,
    NOTE_VIBRATION_OFF,
    NOTE_LED_ON,
    NOTE_LED_OFF,
    NOTE_BACKLIGHT_ON,
    NOTE_BACKLIGHT_OFF
};  /* First Four bits of the Note */

enum NoteType
{
    NORMAL = 0x0010,
    FLAT = 0x0020,
    SHARP = 0x0030
};  /* Bit 5 , 6 */

enum Octave
{
    OCTAVE_3 = 0x0040,  /* //000000000100000 */
    OCTAVE_4 = 0x0080,  /* //000000001000000 */
    OCTAVE_5 = 0x00C0   /* //000000001100000 */
};                      /* bits 7,8 for octave */

enum Duration
{
    DURATION_3BY2 = 0x0100, /* 00001000000000 */
    DURATION_1 = 0x0200,
    DURATION_3BY4 = 0x0300,
    DURATION_1BY2 = 0x0400,
    DURATION_3BY8 = 0x0500,
    DURATION_1BY4 = 0x0600,
    DURATION_3BY16 = 0x0700,
    DURATION_1BY8 = 0x0800,
    DURATION_3BY32 = 0x0900,
    DURATION_1BY16 = 0x0A00
};                          /* bits 9,10,11,12 */

#ifdef __MMI_RING_COMPOSER_REPEAT__	
enum Repeat
{
    REPEAT_START = 0x1000, /* 00001000000000 */
    REPEAT_INFINITE = 0x2000,
    REPEAT_ONE = 0x3000,
    REPEAT_TWO = 0x4000,
    REPEAT_THREE = 0x5000,
    REPEAT_FOUR = 0x6000,
    REPEAT_FIVE = 0x7000,
    REPEAT_SIX = 0x8000,
    REPEAT_SEVEN = 0x9000,
    REPEAT_EIGHT = 0xA000,
    REPEAT_NINE = 0xB000,
    REPEAT_END = REPEAT_ONE
};                          /* bits 13,14,15,16 */
#endif

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */

#endif /* defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__) */ // #if defined(__MMI_RING_COMPOSER__)
#endif /* _MMI_COMPOSE_RINGTONE_DEFS_H */ 

