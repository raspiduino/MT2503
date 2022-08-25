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
 *  custom_user_profiles_defs.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef CUSTOM_USER_PROFILES_DEFS_H
#define CUSTOM_USER_PROFILES_DEFS_H

#include "MMI_features.h"

#define MIN_RING_TONE_ID 101
#ifdef __MMI_PROFILES_SLIM_PROFILE_SUPPORT__
#define MAX_RING_TONE_ID 105
#else
#define MAX_RING_TONE_ID 110
#endif

#define MIN_MIDI_ID 151
#ifdef __MMI_PROFILES_SLIM_PROFILE_SUPPORT__
#define MAX_MIDI_ID 155
#else
#define MAX_MIDI_ID 165
#endif

#define MIN_SND_ID	201
#ifdef __MMI_PROFILES_SLIM_PROFILE_SUPPORT__
#define MAX_SND_ID 205
#else
#define MAX_SND_ID 210
#endif

#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__) || defined(DIGIT_TONE_SUPPORT)
#define MIN_HUMAN_VOICE_ID	1024
#define MAX_HUMAN_VOICE_ID	1036
#endif

#ifdef CUST_KEYPAD_TONE_SUPPORT 
#define MIN_KEYPAD_TONE_ID	4096
#define MAX_KEYPAD_TONE_ID	4096
#endif

typedef enum
{
    NO_COLOR,
    COLOR_PATTERN1,
    COLOR_PATTERN2,
    COLOR_PATTERN3,
    COLOR_PATTERN4,
    COLOR_PATTERN5,
    COLOR_PATTERN6
} mmi_profiles_color_pattern_enum;

typedef enum
{
    SINGLE,
    REPEAT,
    ASCENDING
} mmi_profiles_ring_type_enum;

typedef enum
{
    KEYPAD_SILENT,
    KEYPAD_CLICK,
    KEYPAD_TONE,
    KEYPAD_TONE_HUMAN_VOICE_1,
    KEYPAD_TONE_HUMAN_VOICE_2,
    KEYPAD_TONE_HUMAN_VOICE_3,
    KEYPAD_TONE_HUMAN_VOICE_4,
    KEYPAD_TONE_HUMAN_VOICE_5,
    KEYPAD_TONE_HUMAN_VOICE_6,
    KEYPAD_TONE_CUST_1,
    KEYPAD_TONE_CUST_2,
    KEYPAD_TONE_CUST_3,
    KEYPAD_TONE_CUST_4,
    KEYPAD_TONE_CUST_5,
    KEYPAD_TONE_CUST_6
} mmi_profiles_keypad_tone_list_enum;

#endif /* CUSTOM_USER_PROFILES_DEFS_H */

