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
 *  sw_rectfill.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __SW_RECTFILL_H__
#define __SW_RECTFILL_H__


#include "kal_general_types.h"

typedef enum {
  SW_RECTFILL_COLOR_FORMAT_RGB565 = 0,
  SW_RECTFILL_COLOR_FORMAT_RGB888,
  SW_RECTFILL_COLOR_FORMAT_BGR888,
  SW_RECTFILL_COLOR_FORMAT_ARGB8888,
  SW_RECTFILL_COLOR_FORMAT_PARGB8888,
  SW_RECTFILL_COLOR_FORMAT_PARGB6666,
  SW_RECTFILL_COLOR_FORMAT_UYVY422
} SW_RECTFILL_COLOR_FORMAT_ENUM;


typedef struct SW_RECTFILL_RECTANGLE_T {
   kal_int32 x;                        ///< X coordinate of the left-top point.
   kal_int32 y;                        ///< Y coordinate of the left-top point.
   kal_uint32 w;                       ///< Width of the rectangle.
   kal_uint32 h;                       ///< Height of the rectangle.
} SW_RECTFILL_RECTANGLE;


typedef struct SWRECTFILL_PROCESSOR_T {
   void *srcBuffer;                             /// For the use of encode from RGB buffer
   void *dstBuffer;                             /// For the use of encode from RGB buffer

   SW_RECTFILL_COLOR_FORMAT_ENUM srcColorFormat;
   SW_RECTFILL_COLOR_FORMAT_ENUM dstColorFormat;

   kal_uint32 srcBpp;
   kal_uint32 dstBpp;

   SW_RECTFILL_RECTANGLE dstWnd;

   kal_uint32 srcWidth;
   kal_uint32 srcHeight;
   kal_uint32 dstWidth;
   kal_uint32 dstHeight;

   kal_uint32 rectFillColor;

   kal_bool overlayBufferEnable;
   kal_bool srcAlphaEnable;
   kal_uint32 srcAlphaValue;
} SWRECTFILL_PROCESSOR;

typedef char                S8;      /* signed 8 bit integer */
typedef char                *PS8;    /* signed 8 bit integer pointer */
typedef unsigned char       U8;      /* unsigned 8 bit integer */
typedef unsigned char       *PU8;    /* unsigned 8 bit integer pointer */

typedef signed short int    S16;     /* signed 16 bit integer */
typedef signed short int    *PS16;   /* signed 16 bit integer pointer */
typedef unsigned short int  U16;     /* unsigned 16 bit integer */
typedef unsigned short int  *PU16;   /* unsigned 16 bit integer pointer */

typedef signed int          S32;     /* signed 32 bit integer */
typedef signed int          *PS32;   /* signed 32 bit integer pointer */
typedef unsigned int        U32;     /* unsigned 32 bit integer */
typedef unsigned int        *PU32;   /* unsigned 32 bit integer pointer */

typedef U32 (*g2d_color_from_rgb_func) (U32 A, U32 R, U32 G, U32 B);
typedef void (*g2d_color_to_rgb_func) (U32 *A, U32 *R, U32 *G, U32 *B, U32 c);
typedef U32 (*g2d_get_buf_pixel_func) (U8 *buf_ptr, U32 buf_width, int x, int y);
typedef void (*g2d_put_buf_pixel_func) (U8 *buf_ptr, U32 buf_width, int x, int y, U32 c);

extern U32 g2d_color_from_rgb_16(U32 A, U32 R, U32 G, U32 B);
extern U32 g2d_color_from_rgb_24(U32 A, U32 R, U32 G, U32 B);
extern U32 g2d_color_from_rgb_32(U32 A, U32 R, U32 G, U32 B);
extern U32 g2d_color_from_rgb_32PARGB(U32 A, U32 R, U32 G, U32 B);
extern U32 g2d_color_from_rgb_PARGB6666(U32 A, U32 R, U32 G, U32 B);

extern void g2d_color_to_rgb_16(U32 *R, U32 *A, U32 *G, U32 *B, U32 c);
extern void g2d_color_to_rgb_24(U32 *R, U32 *A, U32 *G, U32 *B, U32 c);
extern void g2d_color_to_rgb_32(U32 *R, U32 *A, U32 *G, U32 *B, U32 c);
extern void g2d_color_to_rgb_32PARGB(U32 *R, U32 *A, U32 *G, U32 *B, U32 c);
extern void g2d_color_to_rgb_PARGB6666(U32 *R, U32 *A, U32 *G, U32 *B, U32 c);

extern void g2d_put_buf_pixel_16(U8 *buf_ptr, U32 buf_width, int x, int y, U32 c);
extern void g2d_put_buf_pixel_24(U8 *buf_ptr, U32 buf_width, int x, int y, U32 c);
extern void g2d_put_buf_pixel_32(U8 *buf_ptr, U32 buf_width, int x, int y, U32 c);
extern void g2d_put_buf_pixel_32PARGB(U8 *buf_ptr, U32 buf_width, int x, int y, U32 c);
extern void g2d_put_buf_pixel_PARGB6666(U8 *buf_ptr, U32 buf_width, int x, int y, U32 c);

extern U32 g2d_get_buf_pixel_16(U8 *buf_ptr, U32 buf_width, int x, int y);
extern U32 g2d_get_buf_pixel_24(U8 *buf_ptr, U32 buf_width, int x, int y);
extern U32 g2d_get_buf_pixel_32(U8 *buf_ptr, U32 buf_width, int x, int y);
extern U32 g2d_get_buf_pixel_32PARGB(U8 *buf_ptr, U32 buf_width, int x, int y);
extern U32 g2d_get_buf_pixel_PARGB6666(U8 *buf_ptr, U32 buf_width, int x, int y);


#define SW_RECTFILL_INV_ALPHA_MUL_255_PRECISION_BITS 7

#define G2D_PARGB8888(_a, _pr, _pg, _pb) (((_a) << 24) | ((_pr) << 16) | ((_pg) << 8) | (_pb))

#define G2D_BITS_5_to_8(_x)             (((_x) << 3) | ((_x) >> 2))
#define G2D_BITS_8_to_5(_x)             ((_x) >> 3)

#define G2D_BITS_6_to_8(_x)             (((_x) << 2) | ((_x) >> 4))
#define G2D_BITS_8_to_6(_x)             ((_x) >> 2)

#define G2D_RGB565(_r, _g, _b)          (((_r) << 11) | ((_g) << 5) | (_b))
#define G2D_R_OF_RGB565(_c)             (((_c) << 16) >> 27)
#define G2D_G_OF_RGB565(_c)             (((_c) << 21) >> 26)
#define G2D_B_OF_RGB565(_c)             (((_c) << 27) >> 27)

#define G2D_RGB888(_r, _g, _b)          (((_r) << 16) | ((_g) << 8) | (_b))
#define G2D_R_OF_RGB888(_c)             (((_c) <<  8) >> 24)
#define G2D_G_OF_RGB888(_c)             (((_c) << 16) >> 24)
#define G2D_B_OF_RGB888(_c)             (((_c) << 24) >> 24)
#define G2D_RGB888_FROM_RGB565(_c) \
    (G2D_RGB888( \
        G2D_BITS_5_to_8(G2D_R_OF_RGB565(_c)), \
        G2D_BITS_6_to_8(G2D_G_OF_RGB565(_c)), \
        G2D_BITS_5_to_8(G2D_B_OF_RGB565(_c))))

#define G2D_RGB565_FROM_RGB888(_c) \
    (G2D_RGB565( \
        G2D_BITS_8_to_5(G2D_R_OF_RGB888(_c)), \
        G2D_BITS_8_to_6(G2D_G_OF_RGB888(_c)), \
        G2D_BITS_8_to_5(G2D_B_OF_RGB888(_c))))

//Put in sw_lt_calc.c (folder:mcu\hal\graphics\gfx_core\g2d\src)
extern const kal_int16 sw_lt_inverse_alpha_table[256];

/* G2D_DIV_255(x) == int(x / 255 + 0.5) */
#define G2D_DIV_255(_x)                 ((((_x) + 128) * 257) >> 16)
#define G2D_PARGB6666(_a, _pr, _pg, _pb) (((_a) << 18) | ((_pr) << 12) | ((_pg) << 6) | (_pb))
#define G2D_A_OF_PARGB6666(_c)          ((_c) >> 18)
#define G2D_PR_OF_PARGB6666(_c)         (((_c) << 14) >> 26)
#define G2D_PG_OF_PARGB6666(_c)         (((_c) << 20) >> 26)
#define G2D_PB_OF_PARGB6666(_c)         (((_c) << 26) >> 26)

#define G2D_BITS_8_to_6(_x)             ((_x) >> 2)
#define G2D_BITS_6_to_8(_x)             (((_x) << 2) | ((_x) >> 4))

#define G2D_PARGB6666_FROM_ARGB8888_EXT(_a, _r, _g, _b) \
    (G2D_PARGB6666( \
        G2D_BITS_8_to_6(_a), \
        G2D_BITS_8_to_6(G2D_DIV_255((_a) * (_r))), \
        G2D_BITS_8_to_6(G2D_DIV_255((_a) * (_g))), \
        G2D_BITS_8_to_6(G2D_DIV_255((_a) * (_b))) ))

/*
 * For a PARGB8888 element = (A, AR, AG, AB), use this macro to divide
 * PR, PG or PB by A to recover R, G, B.
 * That is, corresponding ARGB8888 = (A, GDI_DIVIDE_ALPHA_255(A, PR), ...)
 */
#define G2D_DIVIDE_ALPHA_255(a, pc) \
    (((pc) * sw_lt_inverse_alpha_table[(a)]) >> SW_RECTFILL_INV_ALPHA_MUL_255_PRECISION_BITS)

#define G2D_MEM_GET_16(_ptr)            (*((U16*)(_ptr)))
#define G2D_MEM_PUT_16(_ptr, _v)        (*((U16*)(_ptr)) = _v)

#define G2D_MEM_GET_24(_ptr)            ((((U8 *)(_ptr))[0]) | (((U8 *)(_ptr))[1] << 8) | (((U8*)(_ptr))[2] << 16))
#define G2D_MEM_PUT_24(_ptr, _v) \
    do \
    { \
        U8 *ptr8 = (U8*)(_ptr); \
        ptr8[0] = _v; \
        ptr8[1] = _v >> 8; \
        ptr8[2] = _v >> 16; \
    } while (0)

#define G2D_MEM_GET_PTR_24(_buf_base, _width, _x, _y) \
    ((kal_uint8*)(_buf_base) + ((_width) * (_y) + (_x)) * 3)


#ifndef MIN
   #define MIN(x, y) ((((x)) <= ((y)))? x: y)
#endif // MIN

#ifndef MAX
   #define MAX(x, y) ((((x)) <= ((y)))? y: x)
#endif // MAX


G2D_STATUS_ENUM g2d_rectfill_start(G2D_HANDLE_STRUCT *handle);


kal_int32 RectFillSetDstBuffer(SWRECTFILL_PROCESSOR *pSwRectFill,
                           void *dstYBuffer, kal_uint32 dstWidth, kal_uint32 dstHeight, G2D_COLOR_FORMAT_ENUM dstColorFormat);

kal_int32 RectFillSetSrcBuffer(SWRECTFILL_PROCESSOR *pSwRectFill,
                           void *srcBuffer, kal_uint32 srcWidth, kal_uint32 srcHeight, G2D_COLOR_FORMAT_ENUM srcColorFormat);

kal_int32 RectFillSetDstBufferAddr(SWRECTFILL_PROCESSOR *pSwRectFill, void *dstYBuffer);

kal_int32 RectFillSetSrcBufferAddr(SWRECTFILL_PROCESSOR *pSwRectFill, void *srcBuffer);

kal_int32 RectFillSetDstWindow(SWRECTFILL_PROCESSOR *pSwRectFill,
                               kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h);

kal_int32 RectFillSetOverLayerEnable(SWRECTFILL_PROCESSOR *pSwRectFill, kal_bool OverlayBufferEnable);

kal_int32 RectFillSetSrcAlpha(SWRECTFILL_PROCESSOR *pSwRectFill, kal_bool srcAlphaEnable, kal_uint32 srcAlphaValue);

#endif


