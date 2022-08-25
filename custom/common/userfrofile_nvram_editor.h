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
 * userfrofile_nvram_editor.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file contains `vendor' defined logical data items stored in NVRAM.
 *    These logical data items are used in object code of Protocol Stack software.
 *
 *    As for customizable logical data items, they are defined in nvram_user_config.c
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VENUS_USERPROFILE_NVRAM_EDITOR_H__
#define __VENUS_USERPROFILE_NVRAM_EDITOR_H__
#ifndef NVRAM_NOT_PRESENT

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

/*
 *   Include Headers
 */


/*
 *   NVRAM Basic Headers
 */
#include "nvram_data_items.h"
 
/*
 *   User Headers
 */
#include "userprofile_nvram_def.h"


/*
 *   Bit Level Description Language
 */
#ifdef GEN_FOR_PC
BEGIN_NVRAM_DATA
#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
     LID_BIT VER_LID(NVRAM_EF_SRV_PROF_SETTING_LID)
     nvram_srv_prof_setting_struct *NVRAM_SRV_PROF_RECORD_TOTAL
     {
         ring_vol:"ring volume level {min:0 max:7}"
         {
             ring_vol:8 "ring volume level"
             {
                 0x00: "level 0";
                 0x01: "level 1";
                 0x02: "level 2";
                 0x03: "level 3";
                 0x04: "level 4";
                 0x05: "level 5";
                 0x06: "level 6";
                 0x07: "level 7";
     };
         };

         keypad_vol:"keypad volume level {min:0 max:7}"
         {
             keypad_vol:8 "keypad volume level"
             {
                 0x00: "level 0";
                 0x01: "level 1";
                 0x02: "level 2";
                 0x03: "level 3";
                 0x04: "level 4";
                 0x05: "level 5";
                 0x06: "level 6";
                 0x07: "level 7";
             };
         };

         msg_vol:"message volume level {min:0 max:7}"
         {
             msg_vol:8 "message volume level"
             {
                 0x00: "level 0";
                 0x01: "level 1";
                 0x02: "level 2";
                 0x03: "level 3";
                 0x04: "level 4";
                 0x05: "level 5";
                 0x06: "level 6";
                 0x07: "level 7";
             };
         };

         media_vol:"media volume level {min:0 max:16}"
         {
             msg_vol:8 "media volume level"
             {
                 0x00: "level 0";
                 0x01: "level 1";
                 0x02: "level 2";
                 0x03: "level 3";
                 0x04: "level 4";
                 0x05: "level 5";
                 0x06: "level 6";
                 0x07: "level 7";
                 0x08: "level 8";
                 0x09: "level 9";
                 0x0A: "level 10";
                 0x0B: "level 11";
                 0x0C: "level 12";
                 0x0D: "level 13";
                 0x0E: "level 14";
                 0x0F: "level 15";
                 0x10: "level 16";
             };
         };

         alert_type:"alert type"
         {
            alert_type:8 "alert type"
            {
                0x01: "Ring only";
                0x02: "Vibrate only";
                0x03: "Ring and vibrate";
                0x04: "Vibrate first and then ring";
                0x05: "Slient";
            };
         };

         noti_sound:"notification sound"
         {
            noti_sound:8 "notificattion sound"
            {
                0x00: "Off";
                0x01: "On";
            };
         };

         vibrate:"if can vibrate (shall sync with alert type)"
         {
            vibrate:8 "if can vibrate"
            {
                0x00: "Off";
                0x01: "On";
            };
         };

         ring_type:"ring type"
         {
            ring_type:8 "ring type"
            {
                0x00: "Repeat";
                0x01: "Ascending";
                0x02: "Once";
                0x03: "Beep once";
            };
         };

         intelligent_call_alert:"intelligent call alert"
         {
            intelligent_call_alert:8 "intelligent call alert"
            {
                0x00: "Off";
                0x01: "On";
            };
         };

         system_alert:"system alert"
         {
            system_alert:8 "system alert"
            {
                0x00: "Off";
                0x01: "On";
            };
         };

         led_pattern:"led color pattern"
         {
            led_pattern:8 "led color pattern"
            {
                0x00: "None";
                0x01: "Pattern 1";
                0x02: "Pattern 2";
                0x03: "Pattern 3";
                0x04: "Pattern 4";
                0x05: "Pattern 5";
                0x06: "Pattern 6";
            };
         };

         keypad_tone_type:"keypad tone type"
         {
            keypad_tone_type:8 "keypad tone type"
            {
                0x00: "Slient";
                0x01: "Click";
                0x02: "Tone";
            };
         };

         touch_vol:"touch feedback volume level"
         {
            touch_vol:8 "touch feedback volume level"
            {
                0x00: "mute";
                0x01: "level 1";
                0x02: "level 2";
                0x03: "level 3";
                0x04: "level 4";
                0x05: "level 5";
                0x06: "level 6";
                0x07: "level 7";
            };
         };

         touch_vib:"touch feedback vibration level"
         {
            touch_vib:8 "touch feedback vibration level"
            {
                0x00: "Off";
                0x01: "level 1";
                0x02: "level 2";
                0x03: "level 3";
            };
         };

         power_on_tone:"power on tone"
         {
            power_on_tone:16 "power on tone"
            {
                0x00: "Silent";
                0x65: "Tone 1";
                0x66: "Tone 2";
                0x67: "Tone 3";
                0x68: "Tone 4";
                0x69: "Tone 5";
                0x6A: "Tone 6";
                0x6B: "Tone 7";
                0x6C: "Tone 8";
                0x6D: "Tone 9";
                0x6E: "Tone 10";
            };
         };

         power_off_tone:"power off tone"
         {
             power_off_tone:16 "power off tone"
             {
                 0x00: "Silent";
                 0x65: "Tone 1";
                 0x66: "Tone 2";
                 0x67: "Tone 3";
                 0x68: "Tone 4";
                 0x69: "Tone 5";
                 0x6A: "Tone 6";
                 0x6B: "Tone 7";
                 0x6C: "Tone 8";
                 0x6D: "Tone 9";
                 0x6E: "Tone 10";
             };
         };

         power_on_off_tone:"powr on/off tone switcher"
         {
            power_on_off_tone:8 "play tone during power on / off"
            {
                0x00: "Off";
                0x01: "On";
            };
         };

         cover_open_tone:"cover open tone"
         {
             cover_open_tone:16 "cover open tone"
             {
                 0x00: "Silent";
                 0x65: "Tone 1";
                 0x66: "Tone 2";
                 0x67: "Tone 3";
                 0x68: "Tone 4";
                 0x69: "Tone 5";
                 0x6A: "Tone 6";
                 0x6B: "Tone 7";
                 0x6C: "Tone 8";
                 0x6D: "Tone 9";
                 0x6E: "Tone 10";
             };
         };

         cover_close_tone:"cover close tone"
         {
             cover_close_tone:16 "cover close tone"
             {
                 0x00: "Silent";
                 0x65: "Tone 1";
                 0x66: "Tone 2";
                 0x67: "Tone 3";
                 0x68: "Tone 4";
                 0x69: "Tone 5";
                 0x6A: "Tone 6";
                 0x6B: "Tone 7";
                 0x6C: "Tone 8";
                 0x6D: "Tone 9";
                 0x6E: "Tone 10";
             };
         };

         sms_tone:"sms tone"
         {
             sms_tone:16 "sms_tone"
             {
                 0x00: "Silent";
                 0x65: "Tone 1";
                 0x66: "Tone 2";
                 0x67: "Tone 3";
                 0x68: "Tone 4";
                 0x69: "Tone 5";
                 0x6A: "Tone 6";
                 0x6B: "Tone 7";
                 0x6C: "Tone 8";
                 0x6D: "Tone 9";
                 0x6E: "Tone 10";
             };
         };

         mms_tone:"mms tone"
         {
             mms_tone:16 "mms_tone"
             {
                 0x00: "Silent";
                 0x65: "Tone 1";
                 0x66: "Tone 2";
                 0x67: "Tone 3";
                 0x68: "Tone 4";
                 0x69: "Tone 5";
                 0x6A: "Tone 6";
                 0x6B: "Tone 7";
                 0x6C: "Tone 8";
                 0x6D: "Tone 9";
                 0x6E: "Tone 10";
             };
         };

         email_tone:"email tone"
         {
             email_tone:16 "email_tone"
             {
                 0x00: "Silent";
                 0x65: "Tone 1";
                 0x66: "Tone 2";
                 0x67: "Tone 3";
                 0x68: "Tone 4";
                 0x69: "Tone 5";
                 0x6A: "Tone 6";
                 0x6B: "Tone 7";
                 0x6C: "Tone 8";
                 0x6D: "Tone 9";
                 0x6E: "Tone 10";
             };
         };

         voice_tone:"voice tone"
         {
             voice_tone:16 "voice_tone"
             {
                 0x00: "Silent";
                 0x65: "Tone 1";
                 0x66: "Tone 2";
                 0x67: "Tone 3";
                 0x68: "Tone 4";
                 0x69: "Tone 5";
                 0x6A: "Tone 6";
                 0x6B: "Tone 7";
                 0x6C: "Tone 8";
                 0x6D: "Tone 9";
                 0x6E: "Tone 10";
             };
         };

         mt_call_tone:"mt call tone"
         {
            mt_call_tone:16 "mt call tone"
            {
                0x97: "Ring 1";
                0x98: "Ring 2";
                0x99: "Ring 3";
                0x9A: "Ring 4";
                0x9B: "Ring 5";
                0x9C: "Ring 6";
                0x9D: "Ring 7";
                0x9E: "Ring 8";
                0x9F: "Ring 9";
                0xa0: "Ring 10";
                0xa1: "Ring 11";
                0xa2: "Ring 12";
                0xa3: "Ring 13";
                0xa4: "Ring 14";
                0xa5: "Ring 15";
                0xa6: "Ring 16";
                0xa7: "Ring 17";
                0xa8: "Ring 18";
                0xa9: "Ring 19";
                0xaa: "Ring 20";
            };
         };
         
         vt_call_tone:"vt call tone"
         {
            vt_call_tone:16 "vt call tone"
            {
                0x97: "Ring 1";
                0x98: "Ring 2";
                0x99: "Ring 3";
                0x9A: "Ring 4";
                0x9B: "Ring 5";
                0x9C: "Ring 6";
                0x9D: "Ring 7";
                0x9E: "Ring 8";
                0x9F: "Ring 9";
                0xa0: "Ring 10";
                0xa1: "Ring 11";
                0xa2: "Ring 12";
                0xa3: "Ring 13";
                0xa4: "Ring 14";
                0xa5: "Ring 15";
                0xa6: "Ring 16";
                0xa7: "Ring 17";
                0xa8: "Ring 18";
                0xa9: "Ring 19";
                0xaa: "Ring 20";
            };
         };
     };

     LID_BIT VER_LID(NVRAM_EF_SRV_PROF_EXT_MELODY_LID)
     nvram_srv_prof_ext_melody_info_struct *NVRAM_EF_SRV_PROF_EXT_MELODY_TOTAL
     {
     };
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /* !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */

END_NVRAM_DATA

#endif  /* GEN_FOR_PC */
#endif  /* !NVRAM_NOT_PRESENT */
#endif  /* __VENUS_USERPROFILE_NVRAM_EDITOR_H__ */

