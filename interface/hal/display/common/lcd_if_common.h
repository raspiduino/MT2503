/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001-2007
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
 * lcd_if_common.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for common LCD interface driver APIs shared by both ddv1 and ddv2.
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 11 12 2012 joey.pan
 * removed!
 * Fix MT6260 LCD build error.
 *
 * 08 25 2011 bin.han
 * removed!
 * .
 *
 *
 *
 *******************************************************************************/


#ifndef __LCD_IF_COMMON_H__
#define __LCD_IF_COMMON_H__

#include "kal_release.h"

typedef enum
{
   MAIN_LCD = 1,
   SUB_LCD =  2
} LCD_TYPE_ENUM;



void lcd_set_bias(kal_uint8 lcd_id, kal_uint8 *bias);
void lcd_set_contrast(kal_uint8 lcd_id, kal_uint8 *contrast);
void lcd_set_linerate(kal_uint8 lcd_id, kal_uint8 *linereate);
void lcd_set_linerate(kal_uint8 lcd_id, kal_uint8 *linereate);
void lcd_set_temp_compensate(kal_uint8 lcd_id, kal_uint8 *compensate);
void lcd_set_rotate(kal_uint8 lcd_id, kal_uint8 rotate_value);
void lcd_get_screen_para_info(
   LCD_TYPE_ENUM screen_id,
   kal_uint32* scren_width,
   kal_uint32* screen_height,
   kal_uint32* color_depth);
void lcd_get_size(kal_uint8 lcd_id, kal_uint16 *lcd_width, kal_uint16 *lcd_height);

void lcd_power_ctrl(kal_bool enable);
void lcd_power_on(kal_uint8 lcd_id, kal_bool on);
void lcd_screen_on(kal_uint8 lcd_id, kal_bool on);
kal_bool lcd_sleep_in(kal_uint8 lcd_id);
void lcd_sleep_out(kal_uint8 lcd_id);
void lcd_partial_on(kal_uint8 lcd_id, kal_uint16 start_line, kal_uint16 end_line);
void lcd_partial_off(kal_uint8 lcd_id);
kal_uint8 lcd_partial_display_align_line(kal_uint8 lcd_id);
void lcd_bright_level(kal_uint8 lcd_id, kal_uint8 bright_level);



#endif /* __LCD_IF_COMMON_H__ */
