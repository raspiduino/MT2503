/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   g2d_font_api.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   G2D Driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __G2D_FONT_H__
#define __G2D_FONT_H__

#include "kal_general_types.h"

#include "g2d_enum.h"
#include "g2d_common_api.h"

/// re-define structure
/// This is for compatible with old AP
/// #define 	G2D_HANDLE_STRUCT 		void

/**
 *  Setting the font source buffer information
 *  @param addr         : address pointer of source buffer 
 *  @param color_format : enumeration type of source color format
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks This function sets the source buffer adress of font data, 
 *           The font data to be rendered must stored in one-bit-per-pixel
 *           format. The one bits will be rendered based on foreground color,
 *           and the zero bits will be rendered based on background color if
 *           the background color mode is enable.
 */
G2D_STATUS_ENUM g2dFontSetSrcBufferInfo(G2D_HANDLE_STRUCT *handle, kal_uint8 *bufferAddr, kal_uint32 bufferSize);



/**
 *  Setting the tilt mode for font caching
 *  @param tilt_mode_enable : enable/disable the tilt mode
 *  @param tilt_table       : array to store tilted values, maximum items is 32
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks This function set the tilt_mode of font and the tilt value for font drawing
 */
G2D_STATUS_ENUM g2dFontSetTiltMode(G2D_HANDLE_STRUCT *handle, kal_bool tilt_mode_enable, kal_int32 *tilt_table, kal_int32 table_size);


/**
 *  Enable the AA font
 *  @param aa_font_enable    : enable/disable the AA font
 *  @param font_weight_value : The font weight value
 *  @param constant_alpha    : The constant alpha value
 *  @return G2D_STATUS_ENUM  : enumeration type of G2D status
 *  @remarks This function set the tilt_mode of font and the tilt value for font drawing
 */
G2D_STATUS_ENUM g2dFontSetAAFont(G2D_HANDLE_STRUCT *handle, kal_bool aa_font_enable);



/**
 *  Set font bit
 *  @param font_bit          : The font bit
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks This function set the tilt_mode of font and the tilt value for font drawing
 */
G2D_STATUS_ENUM g2dFontSetFontBit(G2D_HANDLE_STRUCT *handle, G2D_FONT_BIT_ENUM font_bit);


/**
 *  Setting the foreground color for font caching
 *  @param a0 : alpha color component of foreground color
 *  @param r0 : red color component of foreground color
 *  @param g0 : green color component of foreground color
 *  @param b0 : blue components of foreground color
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks This function set the foreground color of font
 */
G2D_STATUS_ENUM g2dFontSetFgColor(G2D_HANDLE_STRUCT *handle, kal_uint8 a0, kal_uint8 r0, kal_uint8 g0, kal_uint8 b0);



/**
 *  Setting the background color for font caching
 *  @param  bg_color_enable : enable/disable background color for font caching
 *  @param  a0              : alpha color components of background color
 *  @param  r0              : red color components of background color
 *  @param  g0              : green color components of background color
 *  @param  b0              : blue color components of background color
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks This function set the background color and bg_color_enable for font caching\n
 *           If bg_color_enable is TRUE, the background color will be appled
 */
///G2D_STATUS_ENUM g2dFontSetBackgroundColor(G2D_HANDLE_STRUCT *handle, kal_bool bg_color_enable,kal_uint8 a0, kal_uint8 r0, kal_uint8 g0, kal_uint8 b0);



/**
 *  Setting the font object
 *  @param  x0 : x-coordinate of top-left vertex of the the destination font rectangle
 *  @param  y0 : x-coordinate of top-left vertex of the the destination font rectangle
 *  @param  width  : width of the destination font rectangle
 *  @param  height : height of the destination font rectangle
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks This function define the rendering font's base location, width, and height 
 */
G2D_STATUS_ENUM g2dFontSetDstWindow(G2D_HANDLE_STRUCT *handle, kal_int32 x0, kal_int32 y0, kal_int32 width, kal_int32 height);



/**
 *  Query the destination ractangle range
 *  @param min_x : minimum of x
 *  @param max_x : maximum of x
 *  @param min_y : minimum of y
 *  @param max_y : maximum of y  
 *  @param min_w : minimum of w
 *  @param max_w : maximum of w
 *  @param min_h : minimum of h
 *  @param max_h : maximum of h 
 *  @return           : enumeration type of G2D status
 *  @remarks  
 */
G2D_STATUS_ENUM g2dFontQueryDstWindowRange(G2D_HANDLE_STRUCT *handle, 
                                           kal_int32 *min_x, kal_int32 *max_x, kal_int32 *min_y, kal_int32 *max_y,
                                           kal_uint32 *min_w, kal_uint32 *max_w, kal_uint32 *min_h, kal_uint32 *max_h);
                                           

/**
 *  Starting the font drawing feature
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks This function start performing the font drawing feature
 */
G2D_STATUS_ENUM g2dFontStart(G2D_HANDLE_STRUCT *handle);


#endif /* font.h */
