/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *	 MediaPlayerKuroSkin.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Kuro skin structure.
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MEDIA_PLAYER_KURO_SKIN_H_
#define _MEDIA_PLAYER_KURO_SKIN_H_

#include "MMI_features.h"

#if defined(__MMI_KURO_SUPPORT__)

#include "MMIDataType.h"
#include "gdi_lcd_config.h"

/***************************************************************************** 
* Struct
*****************************************************************************/
#if defined(__MMI_MEDIA_PLAYER_FTE__)
typedef struct
{
    /* kuro region */
    S16 kuro_rgn_x, kuro_rgn_y, kuro_rgn_w, kuro_rgn_h;

    /*falling tone button positon*/
    S16 kuro_btn_pos_x, kuro_btn_pos_y;
    S16 kuro_btn_rgn_x, kuro_btn_rgn_y, kuro_btn_rgn_w, kuro_btn_rgn_h;
    U16 kuro_btn_img_id;  
    U16 kuro_btn_down_img_id; 

    /* kuro button region */
    S16 kuro_shuff_pos_x, kuro_shuff_pos_y;
    S16 kuro_shuff_rgn_x, kuro_shuff_rgn_y, kuro_shuff_rgn_w, kuro_shuff_rgn_h;
   
    /*tone bar*/
    S16 kuro_repeat_pos_x, kuro_repeat_pos_y;
    S16 kuro_repeat_rgn_x, kuro_repeat_rgn_y, kuro_repeat_rgn_w, kuro_repeat_rgn_h;

    /*index step*/
    U16 index_step;

} medply_kuro_fte_skin_struct;

extern const medply_kuro_fte_skin_struct   g_kuro_fte_skin;

#else

typedef struct
{
	/*mute voice button positon*/
	S16 mute_voice_pos_x, mute_voice_pos_y;
    S16 mute_voice_rgn_x, mute_voice_rgn_y, mute_voice_rgn_w, mute_voice_rgn_h;
    U16 mute_voice_up_img_id;  
    U16 mute_voice_down_img_id;  
    U16 unmute_voice_up_img_id; 
    U16 unmute_voice_down_img_id;
	U16 mute_voice_disable_id;

	/*rising tone button positon*/
	S16 tone_rising_pos_x, tone_rising_pos_y;
    S16 tone_rising_rgn_x, tone_rising_rgn_y, tone_rising_rgn_w, tone_rising_rgn_h;
    U16 tone_rising_up_img_id;  
    U16 tone_rising_down_img_id; 
    U16 tone_rising_disable_img_id;

	/*falling tone button positon*/
	S16 tone_falling_pos_x, tone_falling_pos_y;
    S16 tone_falling_rgn_x, tone_falling_rgn_y, tone_falling_rgn_w, tone_falling_rgn_h;
    U16 tone_falling_up_img_id;  
    U16 tone_falling_down_img_id; 
    U16 tone_falling_disable_img_id;

	/*tone bar*/
	S16 tone_bar_bg_pos_x, tone_bar_bg_pos_y;
	S16 tone_bar_fg_pos_x;
	S16 tone_bar_fg_offset_y, tone_bar_fg_step;
	U16 tone_bar_bg_img_id;
	U16 tone_bar_fg_img_id;

#if defined (__MMI_FTE_SUPPORT__) && defined (__MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__)
    /*kuro activate*/
	S16 activate_pos_x, activate_pos_y;
    S16 activate_rgn_x, activate_rgn_y, activate_rgn_w, activate_rgn_h;
    U16 activate_up_img_id;  
    U16 activate_down_img_id; 
    U16 activate_disable_img_id;
#endif    

	/*default background image*/
	U16 def_bg_img_id;

} medply_kuro_skin_struct;

extern const medply_kuro_skin_struct   g_kuro_skin;

#endif /*#if defined(__MMI_MEDIA_PLAYER_FTE__)*/

#endif /*#if defined(__MMI_KURO_SUPPORT__)*/
#endif /* _MEDIA_PLAYER_KURO_SKIN_H_ */



