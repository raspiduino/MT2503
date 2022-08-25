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
 * GlobalConstants.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Global const define
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
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
#ifndef _GLOBALCONSTANTS_H_
#define _GLOBALCONSTANTS_H_

#ifdef __cplusplus
extern "C"
{
#endif

//RHR Add
#include "MMIDataType.h"
/* DOM-NOT_FOR_SDK-BEGIN */
/* Constants from Menu.h */

#ifndef __COSMOS_MMI_PACKAGE__
#define MAX_SUB_MENUS               (64)
#else
#define MAX_SUB_MENUS               (60)
#endif
#define MAX_SUBMENU_CHARACTERS      (41)
#define MAX_SUB_MENU_SIZE           (41*ENCODING_LENGTH + ENCODING_LENGTH)
#define MAX_SUB_MENU_HINT_SIZE      (41*ENCODING_LENGTH + ENCODING_LENGTH)

/* Queue structures */
#define MAX_PRT_NODES               (50)
#define INVALID_HANDLER             (0)
#define QUEUE_NOT_YET_CREATED       (0)
/* DOM-NOT_FOR_SDK-END */

/*QWERTY KEY DEFINITION*/
#define KEY_QWERTY 230

/* mmi key code */
typedef enum
{
/*
 * The key code sequency cannot be changed.
 */
    KEY_0 = 0,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,
    KEY_LSK, //10
    KEY_RSK, //11
    KEY_CSK, //12
    KEY_ENTER = KEY_CSK, //12
    KEY_WAP = KEY_ENTER, //12
    KEY_IP = KEY_ENTER,  //12
    KEY_UP_ARROW, //13
    KEY_DOWN_ARROW, //14
    KEY_LEFT_ARROW, //15
    KEY_RIGHT_ARROW, //16
    KEY_SEND, //17
    KEY_END, //18
    KEY_CLEAR, //19
    KEY_STAR, //20
    KEY_POUND, //21
    KEY_VOL_UP, //22
    KEY_VOL_DOWN, //23
    KEY_CAMERA, //24
    KEY_QUICK_ACS = KEY_CAMERA, //24
    KEY_EXTRA_1, //25
    KEY_EXTRA_2, //26
    KEY_PLAY_STOP, //27
    KEY_FWD, //28
    KEY_BACK, //29
    KEY_POWER, //30
    KEY_EXTRA_A, //31
    KEY_EXTRA_B, //32
    KEY_SEND1, //33
    KEY_SEND2, //34
    KEY_HOME, //35
    KEY_F1,
    KEY_F2,
    KEY_F3,
    KEY_F4,
    KEY_F5,
    KEY_F6,
    KEY_F7,
    KEY_F8,
    KEY_F9,
    KEY_F10,
    KEY_F11,
    KEY_F12,
    KEY_MESSAGE,
    MAX_KEYS,
    KEY_A = MAX_KEYS,
    KEY_B,
    KEY_C,
    KEY_D,
    KEY_E,
    KEY_F,
    KEY_G,
    KEY_H,
    KEY_I,
    KEY_J,
    KEY_K,
    KEY_L,
    KEY_M,
    KEY_N,
    KEY_O,
    KEY_P,
    KEY_Q,
    KEY_R,
    KEY_S,
    KEY_T,
    KEY_U,
    KEY_V,
    KEY_W,
    KEY_X,
    KEY_Y,
    KEY_Z,
    KEY_SPACE,
    KEY_TAB,
    KEY_DEL,
    KEY_ALT,
    KEY_CTRL,
    KEY_WIN,
    KEY_SHIFT,
    KEY_QUESTION,
    KEY_PERIOD,
    KEY_COMMA,
    KEY_EXCLAMATION,
    KEY_APOSTROPHE,
    KEY_AT,
    KEY_BACKSPACE,
    KEY_QWERTY_ENTER,
    KEY_FN,
    KEY_SYMBOL,
    KEY_NUM_LOCK,
    KEY_QWERTY_MENU,
    KEY_OK,
    KEY_DOLLAR,
    #if defined (__KEYPAD_MOD__) && defined(__GPS_TRACK__)
    KEY_SOS,
    KEY_TR1,
    KEY_TR2,
    KEY_FUN,
#endif /* __KEYPAD_MOD__ */
    MAX_QWERTY_KEYS,

    KEY_INVALID = 0xFE
} mmi_keypads_enum;


/* mmi key type */
typedef enum
{
    KEY_FULL_PRESS_DOWN,
    KEY_EVENT_DOWN = KEY_FULL_PRESS_DOWN,
    KEY_EVENT_UP,
    KEY_LONG_PRESS,
    KEY_REPEAT,
    KEY_HALF_PRESS_DOWN,
    KEY_HALF_PRESS_UP,
    #if defined( __KEYPAD_MOD__) && defined(__GPS_TRACK__)
    KEY_SHORT_PRESS,
#endif /* __KEYPAD_MOD__ */

    MAX_KEY_TYPE
} mmi_key_types_enum;

#define MAX_NON_2STEP_KEY_TYPE KEY_HALF_PRESS_DOWN

/* DOM-NOT_FOR_SDK-BEGIN */

#define KEY_EVENT_REPEAT      KEY_REPEAT
#define KEY_EVENT_LONG_PRESS  KEY_LONG_PRESS
#define START_MELODY          (1)
#define STOP_MELODY           (2)
#define RESUME_MELODY         (3)

/* EVENT TYPES */
#define KBD_EVENT             (1)
#define PRT_EVENT             (2)
#define TMR_EVENT             (3)
#define HWR_EVENT             (4)
#define MEDIA_EVENT           (5)

#define KEY_IDLE              (0)
#define KEY_PRESS             (1)

/* Equivalent to WM_KEYDOWN for key board keys */
#define WM_KEYBRD_PRESS       (256)
/* Equivalent to WM_KEYUP for key board keys */
#define WM_KEYBRD_RELEASE     (257)       
/* DOM-NOT_FOR_SDK-END */

#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif /* _GLOBALCONSTANTS_H_ */ 

