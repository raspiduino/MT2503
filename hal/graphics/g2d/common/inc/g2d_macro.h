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
 *   g2d_macro.h
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
#ifndef __G2D_MACRO_H__
#define __G2D_MACRO_H__


#ifndef MIN
   #define MIN(x, y) ((((x)) <= ((y)))? x: y)
#endif // MIN

#ifndef MAX
   #define MAX(x, y) ((((x)) <= ((y)))? y: x)
#endif // MAX


/// color format conversion

/// RGB888 to RGB565
#define  G2D_RGB888_TO_RGB565(R, G, B)          ((R & 0xF8) << 8) | ((G & 0xFC) << 3) | ((B & 0xF8)>> 3)
/// packed RGB888 to 32-bit
#define  G2D_RGB888_PACKED(R, G, B)             (((R << 16)| (G << 8) | B) & 0x00FFFFFF )
/// ARGB888 to ARGB4444
#define  G2D_ARGB8888_TO_ARGB4444(A, R, G, B)   ((((A >> 4) << 12) | ((R >> 4) << 8) | ((G >> 4) << 4) | B ) & 0x0000FFFF)
/// packed ARGB8888 to 32-bit
#define  G2D_ARGB8888_PACKED(A, R, G, B)        ((A << 24) | (R << 16) | (G << 8) | B)

#define  G2D_ARGB6666_PACKED(A, R, G, B)        ((A << 18) | (R << 12) | (G << 6) | B)

/// ARGB8888 to ARGB8565
#define  G2D_ARGB8888_TO_ARGB8565(A, R, G, B)   (((A << 16) | (G2D_RGB888_TO_RGB565(R, G, B))) & 0x00FFFFFF)
/// ARGB8888 to ARGB6666
#define  G2D_ARGB8888_TO_ARGB6666(A, R, G, B)   ((((A >> 2) << 18) | ((R >> 2) << 12) | ((G >> 2) << 6) | (B >> 2) ) & 0x00FFFFFF)

#define  G2D_ARGB6666_TO_ARGB8888(A, R, G, B)   (((A << 2) << 24) | ((R << 2) << 16) | ((G << 2) << 8) | (B << 2))

#define  G2D_ARGB6666_TO_RGB565(R, G, B)        (((R >> 1) << 11) | ((G) << 5) | (B >> 1))
/*

/// RGB565 to RGB888
#define RGB565_R_MASK 0xF800
#define RGB565_G_MASK 0x07E0
#define RGB565_B_MASK 0x001F

#define RGB565_TO_RGB888_R(VALUE)   ((((VALUE) & RGB565_R_MASK)>>8))
#define RGB565_TO_RGB888_G(VALUE)   ((((VALUE) & RGB565_G_MASK)>>3))
#define RGB565_TO_RGB888_B(VALUE)   ((((VALUE) & RGB565_B_MASK)<<3))

#define A_OF_RGB8888(c)              (((c)&0xFF000000 ) >> 24)
#define R_OF_RGB8888(c)              (((c)&0x00FF0000 ) >> 16)
#define G_OF_RGB8888(c)              (((c)&0x0000FF00 ) >> 8)
#define B_OF_RGB8888(c)              (((c)&0x000000FF ))
*/

#endif  /*g2d_macro.h*/
