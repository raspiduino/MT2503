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
 * TimerEvents.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for MMI timer resource.
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
 * removed!
 * removed!
 * removed!
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
/**************************************************************

   FILENAME : TimerEvents.h

   PURPOSE     : struct, defines & globle variables

   REMARKS     : nil

   AUTHOR      : Magesh k

   DATE     : sep' 03, 2002

**************************************************************/

#ifndef _PIXCOM_TIMER_EVENT_H
#define _PIXCOM_TIMER_EVENT_H

#ifndef __MMI_FEATURES__
#error "Please include MMI_features.h before this header file!"
#endif

typedef enum
{
    /*
     * Start for for Keypad based timer.
     */
    KEY_TIMER_ID_NONE = 0,
    KEY_TIMER_ID0 = 1,
    KEY_TIMER_ID1,
    KEY_TIMER_ID2,
    KEY_TIMER_ID3,
    KEY_TIMER_ID4,
    KEY_TIMER_ID5,
    KEY_TIMER_ID6,
    KEY_TIMER_ID7,
    KEY_TIMER_ID8,
    KEY_TIMER_ID9,
    KEY_TIMER_ID10,
    KEY_TIMER_ID11,
    KEY_TIMER_ID12,
    KEY_TIMER_ID13,
    KEY_TIMER_ID14,
    KEY_TIMER_ID15,
    KEY_TIMER_ID16,
    KEY_TIMER_ID17,
    KEY_TIMER_ID18,
    KEY_TIMER_ID19,
    KEY_TIMER_ID20,
    KEY_TIMER_ID21,
    KEY_TIMER_ID22,
    KEY_TIMER_ID23,
    KEY_TIMER_ID24,
    KEY_TIMER_ID25,
    KEY_TIMER_ID26,
    KEY_TIMER_ID27,
    KEY_TIMER_ID28,
    KEY_TIMER_ID29,
    KEY_TIMER_ID30,
    KEY_TIMER_ID31,
    KEY_TIMER_ID32,
    KEY_TIMER_ID33,

    /*
     * Start for for UI based timer.
     */
    UI_TIMER_ID_BASE,
    UI_TIMER_ID_MAX = (UI_TIMER_ID_BASE + 10),

    /*
     * Start for MMI APP based timer
     */
    MMI_TIMER_BASE = UI_TIMER_ID_MAX + 1,

    MMI_MEMORY_MONITOR_TIMER,

    /*
     * For GUI
     */
    UI_ELEMENTS_TIMER,

    /*
     * For Sim detection timers
     */
    /* micha1108 */
    /* micha0201 */
    KEYPADUNLOCKEDMESSAGE_TIMER,

    /*
     * Timer for showing "press to unlock" after pressing
     */
    KEYPADUNLOCKEDHELPMESSAGE_TIMER,

    /*
     * For Call Management 
     */


	/*
     * For SS
     */ 

    /*
     * For Bootup/shutdown
     */
    SYSTEM_SHUTDOWN,
    APHORISM_SCR_TIMER,
    WELCOME_SCR_TIMER,
    SEARCHING_SCREEN_TIMER, /* Robin 1107 */
    RAC_ACTIVATION_TIMER, /* Gemini: timer of RAC activation */

    /*
     * for Call Log
     */
    CHIST_READ_LOG_TIMER,
    CHIST_READ_LOG_SIM2_TIMER,

    /*
     * for SMS
     */



    /*
     * for Ring Tone Compser Timer
     */
    TIMER_COMPOSE_RINGTONE,




	
    /*
     * for Idle and Misc 
     */
    SP_FAIL_TIMER,
    EARPHONE_SCR_TIMER,
    IDLE_HS_DEVICE_STATUS_REFRESH_TIMER,
    IDLE_HS_ENTRY_GUARD_TIMER,
    IDLE_HS_SOFTNOTE_GUARD_TIMER,
    IDLE_HS_RECENT_EVENT_GUARD_TIMER,
    IDLE_HS_CLEAR_ALL_GUARD_TIMER,
    IDLE_TB_ENTRY_GUARD_TIMER,

    IDLE_HS32_REVERT_TIMER,
    

    /*
     * for SIM 
     */
    CODE_VERIFIED_TIMER,

    /*
     * for Organize,  Fun and Game
     */
    PLAY_DOWNLOAD_AUDIO,
    SCREENSAVER_TIMER,
    AT_TEST_TIMER,
    TIMER_POPUP_HEALTH_MENSIS,

    /*
     * for input method
     */
    T9_REQ_TIMER,
    T9_FRAME_TIMER,
    ZI_REQ_TIMER,
    ZI_FRAME_TIMER,
    NOTE_MULTITAP_TIMER,
    CSTAR_REQ_TIMER,
    CSTAR_FRAME_TIMER,

    /*
     * for Engineering mode
     */    
    /*
    EM_NW_EVENT_PLAY_TONE_TIMER,
    FM_LCD_COLOR_CHANGE_TIMER,
    FM_AUTO_TEST_COMMNON_TIMER,
    FM_RTC_START_TIMER,
    FM_VIB_TIMER,
    FM_GENERAL_TIMER,
    */

    /*for CUI ToneSelector*/

    /*
     * for Profiles and Settings
     */
    /* micha1109 */
    TIMER_SET_GPRS_MODE,
    AT_PUK_IN_CALL_TIMER,
    FLIGHT_MODE_CAMP_ON_TONE_TIMER,
    FLIGHT_MODE_DEACTIVATE_BT_TIMER,

    /*
     * for Common Screen
     */
    //POPUP_TIMER,
    //POPUP_SUBLCD,

    /*
     * for file management
     */
    FMGR_PROG_UPDATE_TIMER,
    FMGR_DM_FWU_SHUTDOWN_TIMER,


    /*
     * for Bluetooth
     */
    BT_INQ_TIMER,
    BT_RING_TIMER,
    BT_AUD_OFF_TIMER,
    BT_DEV_DISC_TIMER,
    BT_DISCOVER_PERIOD_TIMER,
    BT_MAKE_IDLE_STATE_TIMER,
    BT_POPUP_TIMER,
    BT_PASSCODE_INPUT_PROMPTED_TIMER,
    BT_DISCONNECT_2ND_INCOMING_HFG_TIMER,
    BT_DEACTIVATE_PROHIBITED_PROFILES_TIMER,
    BT_ACTIVATE_PROFILE_TIMER,
    BT_WAIT_HW_READY_TIMER,
    BT_DELAY_DEACTIVATE_OBEX_RELATED_PROFILES_TIMER,
    BT_DELAY_AVRCP_CONN_POPUP_TIMER,
    BT_DELAY_AVRCP_DISC_POPUP_TIMER,
    BT_DELAY_SCO_CONN_POPUP_TIMER,
    BT_DUMMY_SCR_TIMER,
    BT_BPP_DUMMY_SCR_TIMER,
    BT_AUTHORIZE_SCREEN_HID_TIMER,
    
    
    /*
     * for BT OPP request timeout
     */
    BT_OPP_REQ_TIMER,
    BT_OPP_ACCEPT_CONNECT_TIMER,
    BT_OPP_ABORT_REQ_TIMER,
    //BT_OPP_PUSH_IND_TIMER,
    //BT_OPP_CACULATE_SENDING_SIZE,
    /*
     * for BT FTP request timeout
     */

    /*
     * for BT BPP printing timeout
     */
    BT_BPP_PRINTING_TIMER,
    
    /*
     * for BT BIP request timeout
     */
    BT_BIP_REQ_TIMER,
    BT_BIP_BLINKING_TIMER,
    BT_BIP_FS_TIMER,

    /*
     * for BT HID user confirm timeout
     */
    BT_HID_USER_CNF_TIMER,
    
    /*
     * for audio player
     */
  /*  AUDPLY_PROCESS_ADD_FILE_TIMER,
    AUDPLY_COUNT_PLAY_TIMER,
    AUDPLY_DELAY_PLAY_TIMER,
    AUDPLY_SINGLE_PLAY_TIMER,
    AUDPLY_SEEKING_TIMER,
    AUDPLY_STATUS_ICON_TIMER,*/
    
    /*
     * for media player
     */
    MEDPLY_WAIT_NEXT_TIMER,
    MEDPLY_DELAY_INPUT_TIMER,
    MEDPLY_SINGLE_WAIT_NEXT_TIMER,
    MEDPLY_DELAY_PLST_POPUP_TIMER,
    MEDPLY_UPDATE_TIME_TIMER,
    MEDPLY_DELAY_ENTER_STATE_TIMER,
    MEDPLY_STREAM_BUFFER_TIMER,
    MEDPLY_PDL_BUFFER_TIMER,
    MEDPLY_PDL_CALC_DOWNLOAD_TIMER,
    MEDPLY_TOUCH_AUTO_RUN_TIMER,
    MEDPLY_STATUS_ICON_TIMER,
    MEDPLY_INTRO_PLAY_TIMER,
    MEDPLY_WAIT_DATACOUNT_CHECK,
    MEDPLY_GENERATE_TIMER,
    MEDPLY_STATE_MACHINE_TIMER,
    MEDPLY_TOUCH_LONG_PRESS_TIMER,
    MEDPLY_WIDGET_CALLBACK_TIMER,
    MEDPLY_KURO_TASK_TIMER,
    MEDPLY_KURO_GPRS_TIMER,
    MEDPLY_KURO_SMS_TIMER,
    MEDPLY_KURO_GET_TOTAL_FEE_TIMER,
    MEDPLY_KURO_DOWNLOAD_TIMER,
    MEDPLY_KURO_UPDATE_DOWNLOAD_MANAGER_TIMER,
    MEDPLY_KURO_SMS_SHORT_TIMER,
    MEDPLY_KURO_SCAN_TIMER,
    
    /*
     * for AB repeater
     */
    ABREPEAT_PROGRESS_BAR_DRAW_TIMER,
    ABREPEAT_BUILD_CACHE_DELAY_TIMER,
    ABREPEAT_DUMMY_FILE_PROG_TIMER,

    /*
     * for sound recorder SMS record
     */
    SND_SMS_RECORD_STOP_TIMER,
    
    /*
     * for MMIAPI
     */
    MMIAPI_SMS_TIMER,


    /*
     * for WAP
     */
   // WAP_NOT_READY_TIMER,  [MAUI_03167355]

    /*
     * for DownloadAgent
     */
    MMI_DA_TIMER_UPDATE_STATUS,
    MMI_DA_WPS_TIMER_0,
    MMI_DA_WPS_TIMER_END = MMI_DA_WPS_TIMER_0 + 10,
    MMI_DA_TIMER_TRIGGERED_PROC_TIMER_BASE,
    MMI_DA_TIMER_TRIGGERED_PROC_TIMER_END = MMI_DA_TIMER_TRIGGERED_PROC_TIMER_BASE + 5,
    
    /*
     * for VRSD
     */
    VRSD_DIAL_AUTO_DIAL_TIMER,
    VRSD_DIAL_PLAYBACK_TIMER,
    VRSD_PLAYTONE_TIMER,

    /*
     * for touch screen
     */
    PEN_POLLING_TIMER,


    /*
     * for SVG
     */
    SVG_TIMER_BASE,

    /* micha_PoC */
    /*
     * for PoC
     */
    POC_IND_TIMER,

    /*
     * for Shcedule FM Recording
     */


    /*
     * for Jataayu WAP and MMS
     */
    JDD_TIMER_00,
    JDD_TIMER_01,
    JDD_TIMER_02,
    JDD_TIMER_03,
    JDD_TIMER_04,
    JBROWSER_WAP_NOT_READY_TIMER,
    JMMS_WAP_NOT_READY_TIMER,
    JMMS_NO_COMM_TIMER_CHECK,
    JMMS_VIEW_PREVIEW_TIMER,
	JMMS_ASYNC_PARSE_TIMER,
	JMMS_ASYNC_SEND_TIMER,
	JMMS_ASYNC_SAVE_TIMER,
    JMMS_SEND_TIMEOUT_TIMER,

    /*
     * for Unified Message
     */
   	
	

    /*
     * for VoIP
     */
    VOIP_AUTOLOGIN_TIMER,
    VOIP_AUTOANSWER_TIMER,
    VOIP_AUTOREDIAL_TIMER,
    VOIP_DTMF_TIMER,
    VOIP_POPUP_TIMER,

    /*
     * for UCM
     */

    /*
     * for VT
     */

    /*
     * for Unified Composer
     */
     #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif  
    
    /*
     * Avatar
     */
    AVATAR_DELAY_DECODE_0,
    AVATAR_DELAY_DECODE_1,
    AVATAR_DELAY_DECODE_2,
    AVATAR_DELAY_DECODE_3,
    AVATAR_DELAY_DECODE_4,


    AVATAR_DELAY_DECODE_5,
    AVATAR_DELAY_DECODE_6,
    AVATAR_DELAY_DECODE_7,
    AVATAR_DELAY_DECODE_8,
    AVATAR_DELAY_DECODE_9,

    /* for Q05A Browser */
	BRW_PSH_INIT_TIMER,

    /*
     * for owl sound integration
     */
    //OWL_SND_VIB_TIMER, [MAUI_03167355]
    /*
    * for dictionary
    */
    DICTIONARY_TTS_TIMER,

	/*
	 *for DM Self-Register
	 */

    /*
     * for Language Learning
     */
     LANGLN_UPDATE_TIMER_ID,
     LANGLN_DK_PLAY_DELAY_TIME,
     LANGLN_SK_PLAY_DELAY_TIME,
     LANGLN_LK_PLAYING_TIMER,
     LANGLN_LK_INTERVAL_TIMER,
     LANGLN_WK_ALERT_TOP_TIMER_ID,
	 
    /*
	 * for DCD
	 */
	 DCD_TIMER,
	 DCD_RETRY_TIMER,
	 DCD_TTL_TIMER,
	 
    /*
     * EM benchmark
     */
     BENCHMARK_TIMER_ID,

	 /*Certificate Manger */
	 //MMI_CERTMAN_TIMER_ID,
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    /*
     * GIS
     */
     GIS_TIMER_ID_0,
     GIS_TIMER_ID_1,
     GIS_TIMER_ID_2,
     GIS_TIMER_ID_3,
     GIS_TIMER_ID_4,
     GIS_TIMER_ID_5,
     GIS_TIMER_ID_6,
     GIS_TIMER_ID_7,
     GIS_TIMER_ID_8,
     GIS_TIMER_ID_9,
     GIS_TIMER_ID_10,
     GIS_TIMER_ID_11,
     GIS_TIMER_ID_12,
     GIS_TIMER_ID_13,
     GIS_TIMER_ID_14,
     GIS_TIMER_ID_15,
     GIS_TIMER_ID_16,
     GIS_TIMER_ID_17,
     GIS_TIMER_ID_18,
     GIS_TIMER_ID_19,
     
        SWTR_START_TIMER,
        SWTR_DURATION_TIMER,

/*
 * for dual mode support
 * MERCURY MASTER USE
 */
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	/* __MMI_DUAL_SIM_MASTER__ */

    /* for settings */

#if defined(__MMI_ATV_SUPPORT__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    MTV_PLAYER_UT_TIMER,
#endif

#if defined (__FLAVOR_VENDOR_SDK__) || defined(__MAUI_SDK_TEST__)
    MMI_DEVAPP_TIMER_ID_0,
    MMI_DEVAPP_TIMER_ID_1,
    MMI_DEVAPP_TIMER_ID_2,
    MMI_DEVAPP_TIMER_ID_3,
    MMI_DEVAPP_TIMER_ID_4,
    MMI_DEVAPP_TIMER_ID_5,
    MMI_DEVAPP_TIMER_ID_6,
    MMI_DEVAPP_TIMER_ID_7,
    MMI_DEVAPP_TIMER_ID_8,
    MMI_DEVAPP_TIMER_ID_9,
#endif


#ifdef __MMI_FM_RADIO_SCHEDULER__
    FMRDO_SCHD_STOP_TIMER,
#endif 
#ifdef __UCWEB6__
    UCWEB_TIMER_BASE_ID,
    UCWEB_TIMER_END_ID = UCWEB_TIMER_BASE_ID + 5,
#endif
#ifdef __QQIM_SUPPORT__
	  QQ_TIMER,
#endif

#ifdef __A8BOX_SUPPORT__
    A8BOX_TIMDER_ID_0,
    A8BOX_TIMDER_ID_1,
    A8BOX_TIMDER_ID_2,
    A8BOX_TIMDER_ID_3,
    A8BOX_TIMDER_ID_4,
    A8BOX_TIMDER_ID_5,
    A8BOX_TIMDER_ID_6,
    A8BOX_TIMDER_ID_7,
    A8BOX_TIMDER_ID_8,
    A8BOX_TIMDER_ID_9,
#endif

#ifdef __QQMOVIE_SUPPORT__
    QQMOVIE_TIMER_ID_0,
	QQMOVIE_TIMER_ID_1,
	QQMOVIE_TIMER_ID_2,
	QQMOVIE_TIMER_ID_3,
	QQMOVIE_TIMER_ID_4,
	QQMOVIE_TIMER_ID_5,
	QQMOVIE_TIMER_ID_6,
	QQMOVIE_TIMER_ID_7,
	QQMOVIE_TIMER_ID_8,
	QQMOVIE_TIMER_ID_9,
#endif

    //For MMS V01 Agent
    MMSV01_AGENT_WAP_NOT_READY_TIMER_ID,
    MMSV01_AGENT_SEND_TIMER,
#ifdef __FM_RADIO_HW_SCAN__
    TIMER_MMI_FMRDO_CHECK_HW_SCAN,
#endif 

#if !defined(HARDWARE_LED_NOT_SUPPORT)
    /* phone setup led */
    PHONESET_LED_SWITCHING_TIMER,
#endif    


#ifdef __NMC_SUPPORT__
    NMC_TIMER,
#endif
    VS_FW_CUI_MENU_TIMER_1,
    VS_SDK_SCENARIO,
#ifdef __MMI_OP01_WIFI__
    WIFI_AUTO_SEARCH_TIMER,
#endif

/*#ifdef __WPS_SUPPORT__
    WIFI_WPS_CONNECT_TIMER,
#endif*/


#if 0
#ifdef __MMI_TETHERING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_TETHERING__ */
#endif

  /*  PXS_SENSOR_GET_RAW_DATA_TIMER, */

#ifdef __COSMOS_MUSICPLY__
    COSMOS_MUSICPLY_TIMER_FIND_NEXT,
#endif

    AVK_PLUTO_TIMER_TEST_BASE,
    AVK_PLUTO_TIMER_TEST_MAX = (AVK_PLUTO_TIMER_TEST_BASE + 9),

/* ADD-S 20120417 FOR CMMBCAS2GPP*/
#ifdef CMMB_CAS_2GPP_V10
	OPENLITE_MMI_TIMER,
	OPENLITE_MMI_TIMER_MAX = OPENLITE_MMI_TIMER+20,
#endif
/* ADD-E 20120417 FOR CMMBCAS2GPP*/

    MAX_TIMERS  /* Imp: Please do not modify this */
} MMI_TIMER_IDS;

#endif /* _PIXCOM_TIMER_EVENT_H */ 

