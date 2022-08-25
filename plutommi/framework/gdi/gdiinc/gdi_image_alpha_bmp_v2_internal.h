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
*  LAWS PRINCIPLES.	ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  gdi_image_alpha_bmp_v2_internal.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Internal header for alpha bitmap v2
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *			   HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __GDI_IMAGE_ALPHA_BMP_V2_INTERNAL_H__
#define __GDI_IMAGE_ALPHA_BMP_V2_INTERNAL_H__

/*
 * Check ABMv2 Type
 */
#if !defined(__FUE__) && !defined(__UBL__)
#define GDI_IMAGE_AB2_HAS_GDI
#endif


/***************************************************************************** 
 * Include
 *****************************************************************************/
/*
 * If there is no GDI, define some needed headers
 */
#ifdef GDI_IMAGE_AB2_HAS_GDI

#include "kal_general_types.h"
#include "gdi_datatype.h"
#include "gdi_const.h"

#else /* GDI_IMAGE_AB2_HAS_GDI */

#include <stdlib.h>
#include <string.h>

#endif /* GDI_IMAGE_AB2_HAS_GDI */



/***************************************************************************** 
 * Define
 *****************************************************************************/
/*
 * If there is no GDI, define some needed types
 */
#ifndef GDI_IMAGE_AB2_HAS_GDI

#define MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL          16
#define GDI_ASSERT(x)
#define GDI_UNUSED(x)                               (void)x

#define MMI_TRUE                                    (!0)
#define MMI_FALSE                                   0

#define DEVICE_BITMAP_BPP                           16

#endif /* GDI_IMAGE_AB2_HAS_GDI */


/* AB2 Helpers */
#define GDI_IMAGE_AB2_INLINE            __inline

#define GDI_IMAGE_AB2_MAX(a, b)         ((a) > (b) ? (a) : (b))
#define GDI_IMAGE_AB2_MIN(a, b)         ((a) < (b) ? (a) : (b))

/* GDI_IMAGE_AB2_DIV_255(x) == int(x / 255 + 0.5) */
#define GDI_IMAGE_AB2_DIV_255(x)        ((((x) + 128) * 257) >> 16)

/* GDI_IMAGE_AB2_DIV_15(x) == int(x / 15 + 0.5) */
#define GDI_IMAGE_AB2_DIV_15(x)         ((((x) + 8) * 4369) >> 16)

/*
 * Divide by 63. the result will equal to (int)(x / 63 + 0.5)
 * Only support 0 <= x < 256 * 256
 */
#define GDI_IMAGE_AB2_DIV_63(_x)        ((4161 * ((_x) + 32)) >> 18)


/* GDI_IMAGE_AB2_BITS_5_to_8(x) ~= int(x * 255 / 31 + 0.5) */
#define GDI_IMAGE_AB2_BITS_5_to_8(x)    (((x) << 3) | ((x) >> 2))

/* GDI_IMAGE_AB2_BITS_6_to_8(x) ~= int(x * 255 / 63 + 0.5) */
#define GDI_IMAGE_AB2_BITS_6_to_8(x)    (((x) << 2) | ((x) >> 4))

#define GDI_IMAGE_AB2_BITS_5_to_6(x)             (((x) << 1) | ((x) >> 4))
#define GDI_IMAGE_AB2_BITS_6_to_5(x)             ((x) >> 1)



/* AB2 limitations and constants */
#define GDI_IMAGE_AB2_MAX_COLOR_CNT                 (0xffff)
#define GDI_IMAGE_AB2_MAX_NORMAL_COLOR_CNT          (0xffff - 1)
#define GDI_IMAGE_AB2_MAX_ALPHA_COLOR_CNT           (0xffff - 1)

#define GDI_IMAGE_AB2_HEADER_SIZE                   8

#define GDI_IMAGE_AB2_INVALID_COLOR_IDX             0xffff

/* AB2 Header format */
#define GDI_IMAGE_AB2_HEADER_WIDTH_BITS             12
#define GDI_IMAGE_AB2_HEADER_HEIGHT_BITS            12
#define GDI_IMAGE_AB2_HEADER_BOUND_LEFT_BITS        8
#define GDI_IMAGE_AB2_HEADER_BOUND_TOP_BITS         8
#define GDI_IMAGE_AB2_HEADER_BOUND_RIGHT_BITS       8
#define GDI_IMAGE_AB2_HEADER_BOUND_BOTTOM_BITS      8
#define GDI_IMAGE_AB2_HEADER_FORMAT_BITS            4
#define GDI_IMAGE_AB2_HEADER_ALGORITHM_BITS         3
#define GDI_IMAGE_AB2_HEADER_RESERVED_1_BITS        1

/* AB2 Color formats */
#define GDI_IMAGE_AB2_FORMAT_RGB888_SRC_KEY         0x0
#define GDI_IMAGE_AB2_FORMAT_RGB565_SRC_KEY         0x1
#define GDI_IMAGE_AB2_FORMAT_PARGB8888              0x2
#define GDI_IMAGE_AB2_FORMAT_PARGB8565              0x3
#define GDI_IMAGE_AB2_FORMAT_RGB888_FULLY_OPAQUE    0x4
#define GDI_IMAGE_AB2_FORMAT_RGB565_FULLY_OPAQUE    0x5

/* Algorithms */
#define GDI_IMAGE_AB2_ALGORITHM_PACKED_COLOR        0x0
#define GDI_IMAGE_AB2_ALGORITHM_RLE                 0x1

/* Color bytes */
#define GDI_IMAGE_AB2_RGB888_SRC_KEY_NORMAL_BYTES   3
#define GDI_IMAGE_AB2_RGB888_SRC_KEY_ALPHA_BYTES    0

#define GDI_IMAGE_AB2_RGB565_SRC_KEY_NORMAL_BYTES   2
#define GDI_IMAGE_AB2_RGB565_SRC_KEY_ALPHA_BYTES    0

#define GDI_IMAGE_AB2_PARGB8888_NORMAL_BYTES        3
#define GDI_IMAGE_AB2_PARGB8888_ALPHA_BYTES         4

#define GDI_IMAGE_AB2_PARGB8565_NORMAL_BYTES        2
#define GDI_IMAGE_AB2_PARGB8565_ALPHA_BYTES         3

#define PUT_IMAGE_PIXEL_EX(ptr, p, bytes)   \
    do { \
        switch (bytes) { \
            case 2: GDI_MEM_PUT_16(ptr, p); break; \
            case 3: GDI_MEM_PUT_24(ptr, p); break; \
            case 4: GDI_MEM_PUT_32(ptr, p); break; \
        } \
    } while (0)

#define GET_IMAGE_PIXEL_EX(p, ptr, bytes)   \
    do { \
        switch (bytes) { \
            case 2: p = GDI_MEM_GET_16(ptr); break; \
            case 3: p = GDI_MEM_GET_24(ptr); break; \
            case 4: p = GDI_MEM_GET_32(ptr); break; \
            default: p = 0; break; \
        } \
    } while (0)

/* color table helper macro */
#define GET_TABLE_16(pal, idx)          GDI_MEM_GET_16((U8 *)(pal) + 2 * (idx))
#define GET_TABLE_24(pal, idx)          GDI_MEM_GET_24((U8 *)(pal) + 3 * (idx))
#define GET_TABLE_32(pal, idx)          GDI_MEM_GET_32((U8 *)(pal) + 4 * (idx))


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
/*
 * If there is no GDI, define some needed types
 */
#ifndef GDI_IMAGE_AB2_HAS_GDI

typedef unsigned char   U8;
typedef signed char     S8;
typedef unsigned int    U32;
typedef signed int      S32;
typedef unsigned short  U16;
typedef signed short    S16;
typedef int             MMI_BOOL;

typedef struct
{
    S32 x1;
    S32 y1;
    S32 x2;
    S32 y2;
} gdi_rect_struct;

typedef struct
{
    S16 x;
    S16 y;
} gdi_point2D_struct;

#endif /* GDI_IMAGE_AB2_HAS_GDI */


/* Image Buffer data structure */
typedef struct
{
    U8 *ptr;
    U32 pixel_bytes;
    U32 pitch_bytes;
    U8 cf;
} gdi_image_ab2_img_buf_struct;

typedef struct 
{
    U32 width           : GDI_IMAGE_AB2_HEADER_WIDTH_BITS;
    U32 height          : GDI_IMAGE_AB2_HEADER_HEIGHT_BITS;
    U32 boundary_left   : GDI_IMAGE_AB2_HEADER_BOUND_LEFT_BITS;
    U32 boundary_top    : GDI_IMAGE_AB2_HEADER_BOUND_TOP_BITS;
    U32 boundary_right  : GDI_IMAGE_AB2_HEADER_BOUND_RIGHT_BITS;
    U32 boundary_bottom : GDI_IMAGE_AB2_HEADER_BOUND_BOTTOM_BITS;
    U32 format          : GDI_IMAGE_AB2_HEADER_FORMAT_BITS;
    U32 algorithm       : GDI_IMAGE_AB2_HEADER_ALGORITHM_BITS;
    U32 reserved_1      : GDI_IMAGE_AB2_HEADER_RESERVED_1_BITS;
} gdi_image_ab2_header_format_struct;

typedef struct
{
    U32 width;
    U32 height;
    U32 boundary_left;
    U32 boundary_top;
    U32 boundary_right;
    U32 boundary_bottom;
    U32 pixel_format;
    U32 algorithm;
    const U8  *algorithm_header_ptr;
    U8 to_replace_color;
    U32 replace_color;
} gdi_image_ab2_info_struct;

typedef struct
{
    U32 normal_color_cnt;
    U32 alpha_color_cnt;
    U32 color_idx_bits;
    const U8  *normal_color_pal_ptr;
    const U8  *alpha_color_pal_ptr;
    const U8  *bs_ptr;
    U8 use_ext_palette;
    U8 *ext_buffer_ptr;
    U32 normal_color_bytes;
    U32 alpha_color_bytes;
    U8 to_replace_color;
    U32 replace_color;
} gdi_image_ab2_rle_info_struct;

typedef enum
{
    GDI_IMAGE_AB2_DECODE_MODE_AUTO,     /* Auto dectect */
    GDI_IMAGE_AB2_DECODE_MODE_OUTPUT,   /* Direct output */
    GDI_IMAGE_AB2_DECODE_MODE_SRC_KEY,  /* Source color key mode */
    GDI_IMAGE_AB2_DECODE_MODE_ALPHA,    /* Alpha Blending mode */
    GDI_IMAGE_AB2_DECODE_MODE_2_LAYERS, /* 2-Layers mode (Not support yet) */
    GDI_IMAGE_AB2_DECODE_MODE_FORCE_ALPHA,
    GDI_IMAGE_AB2_DECODE_MODE_END_OF_ENUM
} gdi_image_ab2_decode_mode_enum;


/***************************************************************************** 
 * Global Function
 *****************************************************************************/
/* 
 * Image Buffer Functions 
 */
extern void gdi_image_ab2_img_buf_null(
    gdi_image_ab2_img_buf_struct *img_buf);

#ifdef GDI_IMAGE_AB2_HAS_GDI
extern void gdi_image_ab2_img_buf_init(
    gdi_image_ab2_img_buf_struct *img_buf,
    gdi_handle layer_handle,
    S32 x,
    S32 y);
#endif /* GDI_IMAGE_AB2_HAS_GDI */

extern void gdi_image_ab2_img_buf_clear(
    gdi_image_ab2_img_buf_struct *dst_buf,
    U32 w,
    U32 h);

extern void gdi_image_ab2_img_buf_copy(
    gdi_image_ab2_img_buf_struct *dst_buf,
    const gdi_image_ab2_img_buf_struct *src_buf,
    U32 w,
    U32 h);

/* 
 * Core Functions 
 */
extern void gdi_image_ab2_rle_decode_full_opaque(
    gdi_image_ab2_img_buf_struct *dst_buf,
    const gdi_image_ab2_rle_info_struct *rle_info,
    U32 draw_width, 
    U32 draw_height,
    U32 begin_ignore,
    U32 line_ignore);

extern void gdi_image_ab2_rle_decode_direct_output(
    gdi_image_ab2_img_buf_struct *dst_buf,
    const gdi_image_ab2_rle_info_struct *rle_info,
    U32 draw_width, 
    U32 draw_height,
    U32 begin_ignore,
    U32 line_ignore);

extern void gdi_image_ab2_rle_decode_na(
    gdi_image_ab2_img_buf_struct *dst_buf,
    const gdi_image_ab2_rle_info_struct *rle_info,
    U32 draw_width, 
    U32 draw_height,
    U32 begin_ignore,
    U32 line_ignore);

extern void gdi_image_ab2_rle_decode_alpha(
    gdi_image_ab2_img_buf_struct *dst_buf,
    const gdi_image_ab2_img_buf_struct *src_buf,
    const gdi_image_ab2_rle_info_struct *rle_info,
    U32 draw_width, 
    U32 draw_height,
    U32 begin_ignore,
    U32 line_ignore);


/* Export Functions */
extern void gdi_image_ab2_read_header(
    gdi_image_ab2_info_struct *info_ptr, 
    const U8 *header_ptr);

extern MMI_BOOL gdi_image_ab2_is_src_color_key_mode(
    const gdi_image_ab2_info_struct *info);

extern U32 gdi_image_ab2_normal_color_bytes(
    U32 pixel_format);

extern U32 gdi_image_ab2_alpha_color_bytes(
    U32 pixel_format);

extern MMI_BOOL gdi_image_ab2_draw_to_buf(
    gdi_image_ab2_img_buf_struct *dst_buf,
    S32 offset_x, 
    S32 offset_y, 
    const U8 *data_ptr);

extern S32 gdi_image_ab2_draw_to_buf_internal(
    gdi_image_ab2_img_buf_struct *dst_buf,
    S32 offset_x, 
    S32 offset_y, 
    const U8 *data_ptr,
    gdi_image_ab2_decode_mode_enum decode_mode);    

#ifdef GDI_IMAGE_AB2_HAS_GDI
extern GDI_RESULT gdi_image_ab2_draw_internal(
    gdi_handle dst_layer,
    S32 dst_layer_x, 
    S32 dst_layer_y, 
    gdi_handle src_layer,
    const U8 *data_ptr,
    gdi_image_ab2_decode_mode_enum decode_mode);

extern GDI_RESULT gdi_image_ab2_draw_internal_with_color(
    gdi_handle dst_layer,
    S32 dst_layer_x, 
    S32 dst_layer_y, 
    gdi_handle src_layer,
    const U8 *data_ptr,
    gdi_image_ab2_decode_mode_enum decode_mode,
    U32 color);

#endif /* GDI_IMAGE_AB2_HAS_GDI */


typedef struct
{
    const U8 *mem_ptr;
    U32 buf;
    U32 buf_bits;
} gdi_image_ab2_bs_struct;

/* RLE Pixel Stream data structure */
typedef struct
{
    gdi_image_ab2_bs_struct bs;
    
    U32 color_idx_bits;
    
    U32 count;
    U32 is_discount;
    U32 repeat_color_idx;
    
} gdi_image_ab2_rle_ps_struct;


extern void gdi_image_ab2_rle_ps_init(
    gdi_image_ab2_rle_ps_struct *ps,
    const U8 *mem_ptr,
    U32 color_idx_bits);

extern void gdi_image_ab2_rle_ps_ignore(gdi_image_ab2_rle_ps_struct *ps, U32 n);

extern void gdi_image_ab2_rle_ps_fetch_pack(gdi_image_ab2_rle_ps_struct *ps);

extern MMI_BOOL gdi_image_ab2_prepare_palette_from_PARGB8565(
    gdi_image_ab2_rle_info_struct *rle_info_ptr,
    const U8  *ori_normal_color_pal_ptr,
    const U8  *ori_alpha_color_pal_ptr,
    U8 dst_layer_cf,
    U32 normal_color_cnt,
    U32 alpha_color_cnt);

extern MMI_BOOL gdi_image_ab2_prepare_palette_from_PARGB8888(
    gdi_image_ab2_rle_info_struct *rle_info_ptr,
    const U8  *ori_normal_color_pal_ptr,
    const U8  *ori_alpha_color_pal_ptr,
    U8 dst_layer_cf,
    U32 normal_color_cnt,
    U32 alpha_color_cnt);

#endif /* __GDI_IMAGE_ALPHA_BMP_v2_INTERNAL_H__ */


