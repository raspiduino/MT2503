/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *   lcd_exception_api.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   LCD exception function
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 * HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * $Log$
 *
 * 03 29 2012 xiaoyong.ye
 * removed!
 * 
 * Fix some problem.
 *
 * 02 22 2011 tianshu.qiu
 * removed!
 * .
 *
 * 02 22 2011 tianshu.qiu
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef __LCD_EXCEPTION_API_H__
#define __LCD_EXCEPTION_API_H__
#include "kal_general_types.h"

typedef enum
{
  LCD_EXPT_LAYER_FORMAT_8BPP_INDEX = 0,
  LCD_EXPT_LAYER_FORMAT_RGB565,
  LCD_EXPT_LAYER_FORMAT_UYVY422,
  LCD_EXPT_LAYER_FORMAT_RGB888,
  LCD_EXPT_LAYER_FORMAT_ARGB8888,
  LCD_EXPT_LAYER_FORMAT_PARGB8888,
  LCD_EXPT_LAYER_FORMAT_ARGB6666,
  LCD_EXPT_LAYER_FORMAT_PARGB6666,
  LCD_EXPT_LAYER_FORMAT_RSD
} LCD_EXPT_LAYER_SOURCE_COLOR_FORMAT_ENUM;

typedef struct
{
    kal_bool src_key_en;
    kal_bool dst_key_en;
    kal_uint32 color_key;
    kal_bool alpha_blend_en;
    kal_uint8 alpha;
    kal_uint16 rotate_angle;   // may be defined as enum.
    kal_bool flip_en;
    kal_bool swap_en;
    kal_bool dither_en;
    LCD_EXPT_LAYER_SOURCE_COLOR_FORMAT_ENUM color_format; // may be defined as other enum
    kal_uint32 frame_buffer;
    kal_uint32 src_rect[4]; // x, y, width, height
    kal_uint32 dst_rect[4]; // x, y, width, height
    kal_uint32 mem_pitch;   // Unit in bytes
} lcd_exception_layer_struct;

kal_uint32 lcd_exception_flatten(kal_uint32 layers, lcd_exception_layer_struct* pLayerInfo, kal_uint8* pFramebuffer, kal_uint32 bg_color, kal_uint32 width, kal_uint32 height);
kal_uint32 lcd_exception_screen_update(kal_uint8* pFramebuffer, kal_uint32 width, kal_uint32 height);

#endif
