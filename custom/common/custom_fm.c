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
 * custom_fm.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for factory mode.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 ****************************************************************************/
#if defined(PLUTO_MMI)
#ifndef __L1_STANDALONE__

    #include "kal_general_types.h"

#include "custom_fm.h"
#include "MMI_features.h"
#include "GlobalConstants.h"

/*----------------------------------------------------------------*/
/* Keypad test                                                    */
/*----------------------------------------------------------------*/
/* To add a new key, please follow below steps
   1. Add key code and showing text in g_fm_keypad_table. 
      Key code are defined in globalconstants.h, mmi_keypads_enum. Please use macro for a key as it defined in mmi_keypads_enum.
   2. Add key code in g_fm_keypad_order_table to make it displayed in test screen.
      There are three g_fm_keypad_order_table defination, for Qwerty keypad, non-touch keypad and touch keypad.
      KEY_INVALID is used to seperate keys in different lines. You can place the key at any position you want.
      Please note that the key you add should be wrapped by correct macro

   To make a existing key be shown in test screen or to hide it, just modify g_fm_keypad_order_table.
*/

/* Key code and key text mapping table*/
const mmi_fm_key_info_struct g_fm_keypad_table[] = {
    /* Key code         Key text*/
    {KEY_0,             L"0"},
    {KEY_1,             L"1"},
    {KEY_2,             L"2"},
    {KEY_3,             L"3"},
    {KEY_4,             L"4"},
    {KEY_5,             L"5"},
    {KEY_6,             L"6"},
    {KEY_7,             L"7"},
    {KEY_8,             L"8"},
    {KEY_9,             L"9"},
    {KEY_LSK,           L"LSK"},
    {KEY_RSK,           L"RSK"},
    {KEY_CSK,           L"CSK"},
    {KEY_UP_ARROW,      L"UP"},
    {KEY_DOWN_ARROW,    L"DN"},
    {KEY_LEFT_ARROW,    L"LF"},
    {KEY_RIGHT_ARROW,   L"RT"},
#ifdef __SENDKEY2_SUPPORT__
    {KEY_SEND,          L"SND1"},
#else
    {KEY_SEND,          L"SND"},
#endif
    {KEY_END,           L"END"},
    {KEY_CLEAR,         L"CLR"},
    {KEY_STAR,          L"*"},
    {KEY_POUND,         L"#"},
    {KEY_VOL_UP,        L"VUP"},
    {KEY_VOL_DOWN,      L"VDN"},
    {KEY_CAMERA,        L"CAM"},
    {KEY_QUICK_ACS,     L"ACS"},
    {KEY_ENTER,         L"CSK"},
    {KEY_WAP,           L"WAP"},
    {KEY_IP,            L"IP"},
    {KEY_EXTRA_1,       L"EXT1"},
    {KEY_EXTRA_2,       L"EXT2"},
    {KEY_PLAY_STOP,     L"STOP"},
    {KEY_FWD,           L"PWD"},
    {KEY_BACK,          L"BACK"},
    {KEY_POWER,         L"PWR"},
    {KEY_EXTRA_A,       L"EXTA"},
    {KEY_EXTRA_B,       L"EXTB"},
#ifdef __SENDKEY2_SUPPORT__
    {KEY_SEND1,         L"SND1"},
    {KEY_SEND2,         L"SND2"},
#endif
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    {KEY_A,             L"A"},
    {KEY_B,             L"B"},
    {KEY_C,             L"C"},
    {KEY_D,             L"D"},
    {KEY_E,             L"E"},
    {KEY_F,             L"F"},
    {KEY_G,             L"G"},
    {KEY_H,             L"H"},
    {KEY_I,             L"I"},
    {KEY_J,             L"J"},
    {KEY_K,             L"K"},
    {KEY_L,             L"L"},
    {KEY_M,             L"M"},
    {KEY_N,             L"N"},
    {KEY_O,             L"O"},
    {KEY_P,             L"P"},
    {KEY_Q,             L"Q"},
    {KEY_R,             L"R"},
    {KEY_S,             L"S"},
    {KEY_T,             L"T"},
    {KEY_U,             L"U"},
    {KEY_V,             L"V"},
    {KEY_W,             L"W"},
    {KEY_X,             L"X"},
    {KEY_Y,             L"Y"},
    {KEY_Z,             L"Z"},
    {KEY_SPACE,         L"SP"},
    {KEY_TAB,           L"TAB"},
    {KEY_DEL,           L"DEL"},
    {KEY_ALT,           L"ALT"},
    {KEY_CTRL,          L"CTRL"},
    {KEY_WIN,           L"WIN"},
    {KEY_SHIFT,         L"SHF"},
    {KEY_QUESTION,      L"?"},
    {KEY_PERIOD,        L"."},
    {KEY_COMMA,         L","},
    {KEY_EXCLAMATION,   L"!"},
    {KEY_APOSTROPHE,    L"."},
    {KEY_AT,            L"@"},
    {KEY_BACKSPACE,     L"BK"},
    {KEY_QWERTY_ENTER,  L"ENT"},
    {KEY_FN,            L"FN"},
    {KEY_SYMBOL,        L"SYM"},
    {KEY_NUM_LOCK,      L"NUM"},
    {KEY_QWERTY_MENU,   L"MEU"},
    {KEY_OK,            L"OK"},
    {MAX_QWERTY_KEYS,   L"KEYS"},
#endif /* __QWERTY_KEYPAD_SUPPORT__ */
    {KEY_HOME,          L"HOME"},
    {KEY_INVALID,       L"\n"}
};

/* Keypad arrangement table, below is for Qwerty keypad*/

#ifdef __COSMOS_MMI_PACKAGE__    
const kal_uint16 g_fm_keypad_order_table[] = 
{
    /* 1st line*/
    KEY_VOL_DOWN, KEY_VOL_UP, KEY_INVALID,
    
    /* new line*/
    KEY_SEND,   KEY_END, KEY_INVALID,
    
    /* new line*/
    KEY_BACK, KEY_HOME, KEY_INVALID,

    /* new line */
    KEY_CAMERA
};
#else   /*__COSMOS_MMI_PACKAGE__*/
	
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__

const kal_uint16 g_fm_keypad_order_table[] = 
{
    /* 1st line*/
    KEY_LSK, KEY_RSK,
#ifdef __SENDKEY2_SUPPORT__
    KEY_SEND, KEY_SEND2,
#else
    KEY_SEND,
#endif
    KEY_END, 
#if defined(__MMI_IP_KEY__) || defined(__MMI_FACTORY_MODE_I_KEY__)
    KEY_IP,
#endif
    KEY_INVALID,
    
    /* new line*/
#if defined(__MMI_FACTORY_MODE_NAV_KEY__) 
     KEY_CLEAR,KEY_CSK, KEY_INVALID,
#endif
    /* new line*/
    KEY_LEFT_ARROW, KEY_UP_ARROW,  KEY_ENTER, KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_INVALID,
    /* new line*/
//#ifndef __MMI_NO_SIDEKEY__
    KEY_VOL_UP, KEY_VOL_DOWN, KEY_INVALID,
//#endif
    /* new line*/
    KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T, KEY_Y, KEY_U, KEY_I, KEY_O, KEY_P, KEY_INVALID,
    /* new line*/
    KEY_A, KEY_S, KEY_D, KEY_F, KEY_G, KEY_H, KEY_J, KEY_K, KEY_L, KEY_BACKSPACE, KEY_INVALID,
    /* new line*/
    KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B, KEY_N, KEY_M, KEY_PERIOD, KEY_QWERTY_ENTER, KEY_INVALID,
    /* new line*/
    KEY_FN, KEY_SHIFT, KEY_SPACE, KEY_SYMBOL, KEY_QWERTY_MENU, 
//#if defined(__MMI_CAMERA__)
    KEY_CAMERA
//#endif
};

#else /* __MMI_QWERTY_KEYPAD_SUPPORT__ */

/* For non-Qwerty keypad, below is for projects that support normal keypad*/
#if !defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_NORMAL_KEYPAD__)

const kal_uint16 g_fm_keypad_order_table[] = 
{
    /* 1st line*/
    KEY_LSK, KEY_RSK, KEY_INVALID,
    /* new line*/
#ifdef __SENDKEY2_SUPPORT__
    KEY_SEND, KEY_SEND2,
#else
    KEY_SEND,
#endif
    KEY_END, KEY_INVALID,
    /* new line*/
    KEY_LEFT_ARROW, KEY_UP_ARROW, KEY_ENTER, KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_INVALID, 
    /* new line*/
#if defined(__MMI_FACTORY_MODE_NAV_KEY__) 
    KEY_CLEAR, KEY_CSK, KEY_INVALID,
#endif
    /* new line*/
//#ifndef __MMI_NO_SIDEKEY__
   // KEY_VOL_UP, KEY_VOL_DOWN, KEY_INVALID,
//#endif
    /* new line*/
    KEY_1, KEY_2, KEY_3, KEY_INVALID,
    KEY_4, KEY_5, KEY_6, KEY_INVALID,
    KEY_7, KEY_8, KEY_9, KEY_INVALID,
    KEY_STAR, KEY_0, KEY_POUND, KEY_INVALID,
#if defined(__MMI_IP_KEY__) || defined(__MMI_FACTORY_MODE_I_KEY__)
    KEY_IP,
#endif   
//#if defined(__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
    KEY_CAMERA
//#endif
};

#else /* __MMI_TOUCH_SCREEN__ */
/* This is for touch screen projects with keypad only have some control keys*/
const kal_uint16 g_fm_keypad_order_table[] = 
{
    /* 1st line*/
    KEY_LSK, KEY_RSK, KEY_INVALID,
#if defined(__MMI_FOURWAYS_KEY_DISABLE__)
#else
    /* new line*/
    KEY_LEFT_ARROW, KEY_UP_ARROW, KEY_ENTER, KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_INVALID,
#endif
    /* new line*/
#ifdef __SENDKEY2_SUPPORT__
    KEY_SEND, KEY_SEND2,
#else
    KEY_SEND,
#endif
    KEY_END
};

#endif /* __MMI_TOUCH_SCREEN__ */
#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */
#endif /*__COSMOS_MMI_PACKAGE__*/

kal_uint32 mmi_fm_keypad_get_keypad_table_size(void)
{
    return sizeof(g_fm_keypad_table) / sizeof(g_fm_keypad_table[0]);
}

kal_uint32 mmi_fm_keypad_get_order_table_size(void)
{
    return sizeof(g_fm_keypad_order_table) / sizeof(g_fm_keypad_order_table[0]);
}

#endif /* __L1_STANDALONE__*/
#endif /* PLUTO_MMI*/
