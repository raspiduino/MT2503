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
 *   iul_csc_macros.h
 *
 * Project:
 * --------
 *   N/A
 *
 * Description:
 * ------------
 *   Image Utility Library: APIs for color space conversion
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 04 17 2012 sophie.chen
 * removed!
 * .
 *
 * 11 23 2010 rey.su
 * removed!
 * .
 *
 * 10 26 2010 rey.su
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __IUL_CSC_MACROS_H__
#define __IUL_CSC_MACROS_H__

#define RGB565_R_MASK      0xF800                     ///< mask for R component in RGB565 packed data
#define RGB565_G_MASK      0x07E0                     ///< mask for G component in RGB565 packed data
#define RGB565_B_MASK      0x001F                     ///< mask for B component in RGB565 packed data

#define ARGB8888_R_MASK    0x00FF0000                 ///< mask for R component in ARGB8888 packed data
#define ARGB8888_G_MASK    0x0000FF00                 ///< mask for G component in ARGB8888 packed data
#define ARGB8888_B_MASK    0x000000FF                 ///< mask for B component in ARGB8888 packed data

#define ARGB6666_R_MASK    0x0003F000
#define ARGB6666_G_MASK    0x00000FC0
#define ARGB6666_B_MASK    0x0000003F

/// Convert RGB888 data into RGB565 packed data
#define RGB888_TO_RGB565(R, G, B)      ((unsigned short)(((B) & 0xF8)  >> 3) | (((G) & 0xFC) << 3) | (((R) & 0xF8) << 8))

/// Extract the R component from RGB565 data and extend it to 8 bits
#define RGB565_TO_RGB888_R(VALUE)	   (((VALUE) & RGB565_R_MASK) >> 8)

/// Extract the G component from RGB565 data and extend it to 8 bits
#define RGB565_TO_RGB888_G(VALUE)	   (((VALUE) & RGB565_G_MASK) >> 3)

/// Extract the B component from RGB565 data and extend it to 8 bits
#define RGB565_TO_RGB888_B(VALUE)      (((VALUE) & RGB565_B_MASK) << 3)


#define ARGB8888_TO_RGB888_R(VALUE)    (((VALUE) & ARGB8888_R_MASK) >> 16)
#define ARGB8888_TO_RGB888_G(VALUE)    (((VALUE) & ARGB8888_G_MASK) >> 8)
#define ARGB8888_TO_RGB888_B(VALUE)    (((VALUE) & ARGB8888_B_MASK) >> 0)

#define RGB888_TO_ARGB8888(R, G, B)    ((unsigned int)(0xFF000000 | ((R) << 16) | ((G) << 8) | (B)))

#define ARGB6666_TO_RGB888_R(VALUE)    (((VALUE) & ARGB6666_R_MASK) >> 10)
#define ARGB6666_TO_RGB888_G(VALUE)    (((VALUE) & ARGB6666_G_MASK) >>  4)
#define ARGB6666_TO_RGB888_B(VALUE)    (((VALUE) & ARGB6666_B_MASK) <<  2)


/// If the constant fits into 8-bits, we can spare a load instructions instead of a move instruction.
/*
/// Get the Y value according to the given R, G, B values
#define RGB888_TO_YUV_Y(R, G, B)    ((  306 * (R) + 601 * (G) + 117 * (B)) >> 10)

/// Get the U value according to the given R, G, B values
#define RGB888_TO_YUV_U(R, G, B)    (((-173 * (R) - 339 * (G) + 512 * (B)) >> 10) + 128)

/// Get the V value according to the given R, G, B values
#define RGB888_TO_YUV_V(R, G, B)    ((( 512 * (R) - 429 * (G) -  83 * (B)) >> 10) + 128)

#define YUV_TO_RGB_COEF_0       (256)     ///  1 << 8
#define YUV_TO_RGB_COEF_1       (359)     ///  1.402 * (1 << 8)
#define YUV_TO_RGB_COEF_2       (-88)     /// -0.34414 * (1 << 8)
#define YUV_TO_RGB_COEF_3       (-183)    /// -0.71414 * (1 << 8)
#define YUV_TO_RGB_COEF_4       (454)     ///  1.772 * (1 << 8)

#define YUV_TO_RGB_R5_SHIFT_BITS  11
#define YUV_TO_RGB_G6_SHIFT_BITS  10
#define YUV_TO_RGB_B5_SHIFT_BITS  11
*/

/// Get the Y value according to the given R, G, B values
#define RGB888_TO_YUV_Y(R, G, B)    ((  77 * (R) + 150 * (G) +  29 * (B)) >> 8)

/// Get the U value according to the given R, G, B values
#define RGB888_TO_YUV_U(R, G, B)    (((-86 * (R) - 169 * (G) + 256 * (B)) >> 9) + 128)

/// Get the V value according to the given R, G, B values
#define RGB888_TO_YUV_V(R, G, B)    (((256 * (R) - 214 * (G) -  41 * (B)) >> 9) + 128)



#define YUV_TO_RGB888_SHIFT_BITS    (7)
#define YUV_TO_RGB_COEF_0           (128)     ///  1 << 7
#define YUV_TO_RGB_COEF_1           (179)     ///  1.402 * (1 << 7)
#define YUV_TO_RGB_COEF_2           (-44)     /// -0.34414 * (1 << 7)
#define YUV_TO_RGB_COEF_3           (-91)     /// -0.71414 * (1 << 7)
#define YUV_TO_RGB_COEF_4           (227)     ///  1.772 * (1 << 7)

#define YUV_TO_RGB_R5_SHIFT_BITS    (10)
#define YUV_TO_RGB_G6_SHIFT_BITS    (9)
#define YUV_TO_RGB_B5_SHIFT_BITS    (10)



/// Fast saturate-zero macro: ARM compiler will use bic (bit clear) instruction.
#define SATURATE_ZERO(value)        (~((signed int)(value) >> 31) & (value))



/// Macro for range limitation. Notice that lower must be 0.
#define RANGE_LIMIT(lower, upper, x)   \
{                                      \
   if (x > upper)                      \
   {                                   \
      x = upper;                       \
   }                                   \
   else                                \
   {                                   \
      x = SATURATE_ZERO(x);            \
   }                                   \
}


#endif /// __IUL_CSC_MACROS_H__
