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
 *   SDKGdi.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   SDK Application GDI API prototypes
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
  *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef SDKGDI_H
#define SDKGDI_H

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMIDataType.h"
#include "gdi_const.h"
#include "gdi_datatype.h"


/****************************************************************************
 * gdi_include.h
 ****************************************************************************/
#include "gdi_include.h"
extern GDI_RESULT gdi_image_get_frame_count_mem(
            U8  image_type,
            U8  *image_ptr,
            S32 size,
            S32 *frame_count);
extern void gdi_draw_point(S32 x, S32 y, gdi_color pixel_color);
extern void gdi_draw_line(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color line_color);
extern void gdi_draw_antialiasing_line(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color line_color);
extern void gdi_draw_rect(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color rect_color);
extern void gdi_draw_solid_rect(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color rect_color);
extern void gdi_draw_circle(S32 x, S32 y, S32 r, gdi_color circle_color);
//extern void gdi_draw_arc(S32 circle_x, S32 circle_y, S32 circle_r, int startAngle, int angleExtent, gdi_color color);
extern void gdi_draw_round_rect(
                S32 x1,
                S32 y1,
                S32 x2,
                S32 y2,
                gdi_color rect_color,
                gdi_color frame_color,
                S32 frame_width);

extern void gdi_draw_darken_rect(S32 x1, S32 y1, S32 x2, S32 y2, S32 brightness_value);                
extern void gdi_effect_alpha_blending_rect(
                gdi_handle src_layer_handle,
                S32 x1,
                S32 y1,
                S32 x2,
                S32 y2,
                U32 transparent_color_a,
                U32 transparent_color_r,
                U32 transparent_color_g,
                U32 transparent_color_b);

extern GDI_RESULT gdi_layer_create_cf(
                    gdi_color_format cf,
                    S32 offset_x,
                    S32 offset_y,
                    S32 width,
                    S32 height,
                    gdi_handle *handle_ptr);
#define gdi_layer_create(OFFSET_X,OFFSET_Y,WIDTH,HEIGHT,HANDLE_PTR) \
      gdi_layer_create_cf(GDI_LCD->cf,OFFSET_X,OFFSET_Y,WIDTH,HEIGHT,HANDLE_PTR)
extern GDI_RESULT gdi_layer_create_cf_double(
                    gdi_color_format cf,
                    S32 offset_x,
                    S32 offset_y,
                    S32 width,
                    S32 height,
                    gdi_handle *handle_ptr);
#define gdi_layer_create_double(OFFSET_X, OFFSET_Y,WIDTH,HEIGHT,HANDLE_PTR) \
      gdi_layer_create_cf_double(GDI_LCD->cf,OFFSET_X,OFFSET_Y,WIDTH,HEIGHT,HANDLE_PTR)
extern GDI_RESULT gdi_layer_create_cf_using_outside_memory(
                    gdi_color_format cf,
                    S32 offset_x,
                    S32 offset_y,
                    S32 width,
                    S32 height,
                    gdi_handle *handle_ptr,
                    U8 *outside_memory,
                    S32 outside_memory_size);
#define gdi_layer_create_using_outside_memory(X,Y,WIDTH,HEIGHT,HANDLE_PTR,OUTMEM_PTR,OUTMEM_SIZE) \
      gdi_layer_create_cf_using_outside_memory(GDI_LCD->cf,X,Y,WIDTH,HEIGHT,HANDLE_PTR,OUTMEM_PTR,OUTMEM_SIZE)
extern GDI_RESULT gdi_layer_create_cf_double_using_outside_memory(
                    gdi_color_format cf,
                    S32 offset_x,
                    S32 offset_y,
                    S32 width,
                    S32 height,
                    gdi_handle *handle_ptr,
                    U8 *outside_memory1,
                    S32 outside_memory_size_1,
                    U8 *outside_memory2,
                    S32 outside_memory_size_2);
#define gdi_layer_create_double_using_outside_memory(X,Y, WIDTH,HEIGHT,HANDLE_PTR,OUTMEM_PTR,OUTMEM_SIZE) \
         gdi_layer_create_cf_double_using_outside_memory                                                  \
            (GDI_LCD->cf,X,Y,WIDTH,HEIGHT,HANDLE_PTR,                                                     \
             OUTMEM_PTR,(OUTMEM_SIZE)>>1,OUTMEM_PTR+(OUTMEM_SIZE>>1),(OUTMEM_SIZE)>>1)
extern GDI_RESULT gdi_layer_free(gdi_handle handle);
extern void gdi_layer_set_active(gdi_handle handle);
extern GDI_RESULT gdi_layer_toggle_double(void);
extern GDI_RESULT gdi_layer_get_base_handle(gdi_handle *handle_ptr);
extern void gdi_layer_restore_base_active(void);
extern void gdi_layer_get_active(gdi_handle *handle_ptr);

extern BOOL gdi_layer_is_double(gdi_handle layer);
extern GDI_RESULT gdi_layer_set_position(S32 offset_x, S32 offset_y);
extern GDI_RESULT gdi_layer_set_source_key(BOOL source_key_enable, gdi_color source_key_value);
extern GDI_RESULT gdi_layer_get_source_key(BOOL *source_key_enable, gdi_color *source_key_value);
extern GDI_RESULT gdi_layer_set_opacity(BOOL opacity_enable, U8 opacity_value);
extern GDI_RESULT gdi_layer_get_opacity(BOOL *opacity_enable, U8 *opacity_value);
extern void gdi_layer_get_clip(S32 *x1, S32 *y1, S32 *x2, S32 *y2);
extern void gdi_layer_set_clip(S32 x1, S32 y1, S32 x2, S32 y2);
extern void gdi_layer_reset_clip(void);

extern void gdi_layer_set_clip_preset(S32 x1, S32 y1, S32 x2, S32 y2);
extern GDI_RESULT gdi_layer_get_buffer_ptr(U8 **buf_ptr);
extern GDI_RESULT gdi_layer_get_dimension(S32 *width, S32 *height);
extern GDI_RESULT gdi_layer_get_position(S32 *offset_x, S32 *offset_y);
extern GDI_RESULT gdi_layer_blt_ext(gdi_handle handle0, gdi_handle handle1, gdi_handle handle2, gdi_handle handle3,
                                #ifdef GDI_6_LAYERS
                                    gdi_handle handle4, gdi_handle handle5,
                                #endif
                                    S32 x1, S32 y1, S32 x2, S32 y2);
extern GDI_RESULT gdi_layer_blt_previous(S32 x1, S32 y1, S32 x2, S32 y2);
extern GDI_RESULT gdi_layer_blt_base_layer(S32 x1, S32 y1, S32 x2, S32 y2);
extern GDI_RESULT gdi_layer_set_blt_layer_ext(gdi_handle handle0, gdi_handle handle1, gdi_handle handle2,
                                              gdi_handle handle3
                                          #ifdef GDI_6_LAYERS
                                              , gdi_handle handle4, gdi_handle handle5
                                          #endif
    );
extern GDI_RESULT gdi_layer_get_blt_layer_ext(gdi_handle *handle0, gdi_handle *handle1, gdi_handle *handle2,
                                              gdi_handle *handle3
                                          #ifdef GDI_6_LAYERS
                                              , gdi_handle *handle4, gdi_handle *handle5
                                          #endif
    );

extern GDI_RESULT gdi_layer_clear(gdi_color color);
extern GDI_RESULT gdi_layer_flatten_previous_to_base(void);
extern GDI_RESULT gdi_layer_flatten_to_base_ext(gdi_handle src_handle0, gdi_handle src_handle1, gdi_handle src_handle2,
                                                gdi_handle src_handle3
                                            #ifdef GDI_6_LAYERS
                                                , gdi_handle src_handle4, gdi_handle src_handle5
                                            #endif
    );
extern GDI_RESULT gdi_layer_flatten_ext(gdi_handle handle0, gdi_handle handle1, gdi_handle handle2, gdi_handle handle3
                                    #ifdef GDI_6_LAYERS
                                        , gdi_handle handle4, gdi_handle handle5
                                    #endif
    );
extern GDI_RESULT gdi_layer_flatten_with_clipping_ext(gdi_handle handle0, gdi_handle handle1, gdi_handle handle2,
                                                      gdi_handle handle3
                                                  #ifdef GDI_6_LAYERS
                                                      , gdi_handle handle4, gdi_handle handle5
                                                  #endif
    );
#ifdef GDI_6_LAYERS
#define gdi_layer_blt(H1,H2,H3,H4,X1,Y1,X2,Y2)        gdi_layer_blt_ext(H1,H2,H3,H4,0,0,X1,Y1,X2,Y2)
#define gdi_layer_get_blt_layer(H1,H2,H3,H4)       gdi_layer_get_blt_layer_ext(H1,H2,H3,H4,0,0)
#define gdi_layer_set_blt_layer(H1,H2,H3,H4)       gdi_layer_set_blt_layer_ext(H1,H2,H3,H4,0,0)
#define gdi_layer_flatten_to_base(H1,H2,H3,H4)     gdi_layer_flatten_to_base_ext(H1,H2,H3,H4,0,0)
#define gdi_layer_flatten(H1,H2,H3,H4)             gdi_layer_flatten_ext(H1,H2,H3,H4,0,0)
#define gdi_layer_flatten_with_clipping(H1,H2,H3,H4)  gdi_layer_flatten_with_clipping_ext(H1,H2,H3,H4,0,0)
#else
#define gdi_layer_blt(H1,H2,H3,H4,X1,Y1,X2,Y2)        gdi_layer_blt_ext(H1,H2,H3,H4,X1,Y1,X2,Y2)
#define gdi_layer_get_blt_layer(H1,H2,H3,H4)       gdi_layer_get_blt_layer_ext(H1,H2,H3,H4)
#define gdi_layer_set_blt_layer(H1,H2,H3,H4)       gdi_layer_set_blt_layer_ext(H1,H2,H3,H4)
#define gdi_layer_flatten_to_base(H1,H2,H3,H4)     gdi_layer_flatten_to_base_ext(H1,H2,H3,H4)
#define gdi_layer_flatten(H1,H2,H3,H4)             gdi_layer_flatten_ext(H1,H2,H3,H4)
#define gdi_layer_flatten_with_clipping(H1,H2,H3,H4)  gdi_layer_flatten_with_clipping_ext(H1,H2,H3,H4)
#endif
extern GDI_RESULT gdi_layer_save_jpeg_file(gdi_handle layer_handle, PS8 file_name);
extern GDI_RESULT gdi_layer_save_pbm_file(gdi_handle layer_handle, PS8 file_name);
extern GDI_RESULT gdi_layer_save_bmp_file(gdi_handle layer_handle, PS8 file_name);
extern int gdi_layer_get_bit_per_pixel(void);
extern void gdi_layer_resize(S32 width, S32 height);
extern void gdi_layer_set_rotate(U8 rotate_value);
extern void gdi_layer_copy_double(void);
#ifdef GDI_COLORFORMAT8_PALETTE
extern void gdi_layer_set_palette(U8 index, gdi_color color);
extern gdi_color *gdi_layer_get_palette(void);
#endif /* GDI_COLORFORMAT8_PALETTE */
extern void gdi_enable_non_block_blt(void);
extern void gdi_disable_non_block_blt(void);
extern BOOL gdi_layer_set_background(gdi_color color);
extern gdi_color gdi_layer_get_background(void);
extern void gdi_lcd_set_active(gdi_handle lcd_handle);
extern void gdi_lcd_get_active(gdi_handle *lcd_handle_ptr);
extern void gdi_lcd_get_dimension(S32 *width, S32 *height);
extern int gdi_lcd_get_bits_per_pixel(void);
extern void gdi_lcd_freeze(BOOL is_freeze);
extern BOOL gdi_lcd_get_freeze(void);
extern U8 gdi_lcd_get_rotate(void);
extern void gdi_lcd_set_rotate(U8 rotate_value);
extern GDI_RESULT gdi_lcd_blt(gdi_handle handle0, gdi_handle handle1, gdi_handle handle2, gdi_handle handle3);
extern GDI_RESULT gdi_lcd_repaint(S32 x1, S32 y1, S32 x2, S32 y2);
extern GDI_RESULT gdi_lcd_repaint_all(void);
extern GDI_RESULT gdi_image_codec_draw(
                    gdi_image_src_enum src_type,
                    U8 *img_src,
                    U8 img_type,
                    S32 img_size,
                    S32 x,
                    S32 y,
                    S32 w,
                    S32 h,
                    U32 flag,
                    U32 frame_pos);
#define gdi_image_draw(OFFSET_X,OFFSET_Y,IMAGE_PTR) \
                    gdi_image_codec_draw(                       \
                                GDI_IMAGE_SRC_FROM_RESOURCE,    \
                                IMAGE_PTR,                      \
                                GDI_IMAGE_TYPE_INVALID,         \
                                0,                              \
                                OFFSET_X,                       \
                                OFFSET_Y,                       \
                                0,                              \
                                0,                              \
                                0,                              \
                                0)
#define gdi_image_draw_resized(OFFSET_X,OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_PTR) \
                    gdi_image_codec_draw(                       \
                                GDI_IMAGE_SRC_FROM_RESOURCE,    \
                                IMAGE_PTR,                      \
                                GDI_IMAGE_TYPE_INVALID,         \
                                0,                              \
                                OFFSET_X,                       \
                                OFFSET_Y,                       \
                                RESIZED_WIDTH,                  \
                                RESIZED_HEIGHT,                 \
                                0,                              \
                                0)
#define gdi_image_draw_frames(OFFSET_X,OFFSET_Y,IMAGE_PTR,FRAME_NO) \
                    gdi_image_codec_draw(                       \
                                GDI_IMAGE_SRC_FROM_RESOURCE,    \
                                IMAGE_PTR,                      \
                                GDI_IMAGE_TYPE_INVALID,         \
                                0,                              \
                                OFFSET_X,                       \
                                OFFSET_Y,                       \
                                0,                              \
                                0,                              \
                                0,                              \
                                (U32) FRAME_NO)
#define gdi_image_draw_resized_frames(OFFSET_X,OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_PTR,FRAME_NO) \
                    gdi_image_codec_draw(                       \
                                GDI_IMAGE_SRC_FROM_RESOURCE,    \
                                IMAGE_PTR,                      \
                                GDI_IMAGE_TYPE_INVALID,         \
                                0,                              \
                                OFFSET_X,                       \
                                OFFSET_Y,                       \
                                RESIZED_WIDTH,                  \
                                RESIZED_HEIGHT,                 \
                                0,                              \
                                (U32) FRAME_NO)

#define gdi_image_draw_id(OFFSET_X,OFFSET_Y,IMAGE_ID)           gdi_image_draw(OFFSET_X,OFFSET_Y,(U8*) GetImage(IMAGE_ID))
#define gdi_image_draw_resized_id(OFFSET_X,OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_ID) \
                    gdi_image_draw_resized(OFFSET_X,OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,(U8*) GetImage(IMAGE_ID))
#define gdi_image_draw_id_with_transparent_color(OFFSET_X,OFFSET_Y,IMAGE_ID) \
                    gdi_image_codec_draw(                       \
                                GDI_IMAGE_SRC_FROM_RESOURCE,    \
                                (U8*) GetImage(IMAGE_ID),       \
                                GDI_IMAGE_TYPE_INVALID,         \
                                0,                              \
                                OFFSET_X,                       \
                                OFFSET_Y,                       \
                                0,                              \
                                0,                              \
                                GDI_IMAGE_CODEC_FLAG_DISABLE_SRC_KEY,\
                                0)
#define gdi_image_draw_mem(OFFSET_X,OFFSET_Y,IMAGE_PTR,IMAGE_TYPE,IMAGE_LENGTH) \
                    gdi_image_codec_draw(                       \
                                GDI_IMAGE_SRC_FROM_MEMORY,      \
                                IMAGE_PTR,                      \
                                IMAGE_TYPE,                     \
                                IMAGE_LENGTH,                   \
                                OFFSET_X,                       \
                                OFFSET_Y,                       \
                                0,                              \
                                0,                              \
                                0,                              \
                                0)
#define gdi_image_draw_ext                              gdi_image_draw_mem
#define gdi_image_draw_mem_frames(OFFSET_X,OFFSET_Y,IMAGE_PTR,IMAGE_TYPE,IMAGE_LENGTH,FRAME_NO) \
                    gdi_image_codec_draw(                       \
                                GDI_IMAGE_SRC_FROM_MEMORY,      \
                                IMAGE_PTR,                      \
                                IMAGE_TYPE,                     \
                                IMAGE_LENGTH,                   \
                                OFFSET_X,                       \
                                OFFSET_Y,                       \
                                0,                              \
                                0,                              \
                                0,                              \
                                (U32)FRAME_NO)
#define gdi_image_draw_resized_mem_frames(OFFSET_X,OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_PTR,IMAGE_TYPE,IMAGE_LENGTH,FRAME_NO) \
                    gdi_image_codec_draw(                       \
                                GDI_IMAGE_SRC_FROM_MEMORY,      \
                                IMAGE_PTR,                      \
                                IMAGE_TYPE,                     \
                                IMAGE_LENGTH,                   \
                                OFFSET_X,                       \
                                OFFSET_Y,                       \
                                RESIZED_WIDTH,                  \
                                RESIZED_HEIGHT,                 \
                                0,                              \
                                (U32)FRAME_NO)

#define gdi_image_draw_file(OFFSET_X,OFFSET_Y,IMAGE_NAME) \
                    gdi_image_codec_draw(                       \
                                GDI_IMAGE_SRC_FROM_FILE,        \
                                (U8*) IMAGE_NAME,               \
                                GDI_IMAGE_TYPE_INVALID,         \
                                0,                              \
                                OFFSET_X,                       \
                                OFFSET_Y,                       \
                                0,                              \
                                0,                              \
                                0,                              \
                                0)
#define gdi_image_draw_resized_file(OFFSET_X,OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_NAME) \
                    gdi_image_codec_draw(                       \
                                GDI_IMAGE_SRC_FROM_FILE,        \
                                (U8*) IMAGE_NAME,               \
                                GDI_IMAGE_TYPE_INVALID,         \
                                0,                              \
                                OFFSET_X,                       \
                                OFFSET_Y,                       \
                                RESIZED_WIDTH,                  \
                                RESIZED_HEIGHT,                 \
                                0,                              \
                                0)
#define gdi_image_draw_file_frames(OFFSET_X,OFFSET_Y,IMAGE_NAME,FRAME_NO) \
                    gdi_image_codec_draw(                       \
                                GDI_IMAGE_SRC_FROM_FILE,        \
                                (U8*) IMAGE_NAME,               \
                                GDI_IMAGE_TYPE_INVALID,         \
                                0,                              \
                                OFFSET_X,                       \
                                OFFSET_Y,                       \
                                0,                              \
                                0,                              \
                                0,                              \
                                (U32)FRAME_NO)
#define gdi_image_draw_resized_file_frames(OFFSET_X,OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_NAME,FRAME_NO) \
                    gdi_image_codec_draw(                       \
                                GDI_IMAGE_SRC_FROM_FILE,        \
                                (U8*) IMAGE_NAME,               \
                                GDI_IMAGE_TYPE_INVALID,         \
                                0,                              \
                                OFFSET_X,                       \
                                OFFSET_Y,                       \
                                RESIZED_WIDTH,                  \
                                RESIZED_HEIGHT,                 \
                                0,                              \
                                (U32)FRAME_NO)
extern GDI_RESULT gdi_image_get_frame_count(U8 *image_ptr, S32 *frame_count);
extern GDI_RESULT gdi_image_get_frame_count_id(U16 image_id, S32 *frame_count);
extern GDI_RESULT gdi_image_get_frame_count_file(U8 *image_ptr, S32 *frame_count);
extern GDI_RESULT gdi_image_get_dimension(U8 *image_ptr, S32 *width, S32 *height);
extern GDI_RESULT gdi_image_get_dimension_id(U16 image_id, S32 *width, S32 *height);
extern GDI_RESULT gdi_image_get_dimension_file(S8 *image_name, S32 *width, S32 *height);
extern GDI_RESULT gdi_image_get_dimension_mem(U8 img_type,U8 *img_ptr,S32 img_size,S32 *width, S32 *height);
extern U16 gdi_image_get_type_from_file(S8 *file_name);
extern U16 gdi_image_get_type_from_mem(PS8 ptr);
extern U16 gdi_image_get_buf_type(U8 * image_ptr);
extern S32 gdi_image_get_buf_len(U8* image);
extern U8 *gdi_image_get_buf_ptr(U8* image);
#define gdi_image_get_buf_len_from_id(ID) gdi_image_get_buf_len((U8*)GetImage(ID))
#define gdi_image_get_buf_ptr_from_id(ID) gdi_image_get_buf_ptr((U8*)GetImage(ID))
#define gdi_image_get_type_from_id(ID)    gdi_image_get_buf_type((U8*)GetImage(ID))
extern void gdi_util_fit_box(
                S32 mode,
                S32 bbox_width,
                S32 bbox_height,
                S32 src_width,
                S32 src_height,
                S32 *offset_x,
                S32 *offset_y,
                S32 *dest_width,
                S32 *dest_height);
extern GDI_RESULT gdi_bitblt_resized(gdi_handle src_layer, S32 sx1,S32 sy1,S32 sx2,S32 sy2,S32 dx1,S32 dy1,S32 dx2,S32 dy2);
extern GDI_RESULT gdi_image_cache_bmp_get(S32 x1, S32 y1, S32 x2, S32 y2, gdi_image_cache_bmp_struct *bmp_ptr);
extern GDI_RESULT gdi_image_cache_bmp_draw(S32 offset_x, S32 offset_y, gdi_image_cache_bmp_struct *bmp_ptr);
extern GDI_RESULT gdi_anim_codec_draw_internal(
                    gdi_image_src_enum src_type,
                    U8 *img_src,
                    U8 img_type,
                    S32 img_size,
                    S32 x,
                    S32 y,
                    S32 w,
                    S32 h,
                    U32 flag,
                    gdi_handle *handle_ptr,
                    U32 frame_pos,
                    S32 draw_count);
#define gdi_anim_draw_mem(OFFSET_X,OFFSET_Y,IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,HANDLE_PTR) \
            gdi_anim_codec_draw_internal(                                               \
                     GDI_IMAGE_SRC_FROM_MEMORY,                                         \
                     (U8*)IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,                              \
                     OFFSET_X,OFFSET_Y,                                                 \
                     0,0,/* resized width,height */                                       \
                     0,/* flag */                                                         \
                     HANDLE_PTR,                                                        \
                     0,/* start_frame */                                                  \
                     -1)/* is_draw_once */                                             \
                     
#define gdi_anim_draw_mem_resized_frames(OFFSET_X,OFFSET_Y,RESIZED_W,RESIZED_H,IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,HANDLE_PTR,START_FRAME) \
            gdi_anim_codec_draw_internal(                                                                  \
                     GDI_IMAGE_SRC_FROM_MEMORY,                                                            \
                     (U8*)IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,                                                 \
                     OFFSET_X,OFFSET_Y,                                                                    \
                     RESIZED_W,RESIZED_H,/* resized width,height */                                                   \
                     0,/* flag */                                                                            \
                     HANDLE_PTR,                                                                           \
                     START_FRAME,/* start_frame */                                                           \
                     -1)/* is_draw_once */                                                                \
                     
#define gdi_anim_draw_mem_resized(OFFSET_X,OFFSET_Y,RESIZED_W,RESIZED_H,IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,HANDLE_PTR) \
            gdi_anim_codec_draw_internal(                                                                           \
                     GDI_IMAGE_SRC_FROM_MEMORY,                                                                     \
                     (U8*)IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,                                                          \
                     OFFSET_X,OFFSET_Y,                                                                             \
                     RESIZED_W,RESIZED_H,/* resized width,height */                                                   \
                     0,/* flag */                                                                                     \
                     HANDLE_PTR,                                                                                    \
                     0,/* start_frame */                                                                              \
                     -1)/* is_draw_once */                                                                         \
                     
#define gdi_anim_draw_mem_once(OFFSET_X,OFFSET_Y,IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,HANDLE_PTR) \
            gdi_anim_codec_draw_internal(                                                    \
                     GDI_IMAGE_SRC_FROM_MEMORY,                                              \
                     (U8*)IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,                                   \
                     OFFSET_X,OFFSET_Y,                                                      \
                     0,0,/* resized width,height */                                            \
                     0,/* flag */                                                              \
                     HANDLE_PTR,                                                             \
                     0,/* start_frame */                                                       \
                     1)/* is_draw_once */                                                   \

extern GDI_RESULT gdi_anim_set_draw_before_callback(void (*callback_ptr)(GDI_RESULT result));
extern GDI_RESULT gdi_anim_set_draw_after_callback(void (*callback_ptr)(GDI_RESULT result));
extern GDI_RESULT gdi_anim_set_blt_before_callback(void (*callback_ptr)(GDI_RESULT result));
extern GDI_RESULT gdi_anim_set_blt_after_callback(void (*callback_ptr)(GDI_RESULT result));
extern GDI_RESULT gdi_anim_set_last_frame_callback(void (*callback_ptr) (GDI_RESULT result));
extern GDI_RESULT gdi_anim_stop(gdi_handle a_handle);
extern U32 gdi_anim_get_delay(void);
extern GDI_RESULT gdi_anim_set_disable_blt(void);
extern GDI_RESULT gdi_anim_resume(gdi_handle a_handle);
extern GDI_RESULT gdi_anim_pause(gdi_handle a_handle);
extern GDI_RESULT gdi_image_encode_file_to_jpeg(
                    S8 *src_file_name,
                    S8 *dest_file_name,
                    S32 dest_width,
                    S32 dest_height,
                    U8 *buf_ptr,
                    S32 buf_size);
extern gdi_handle gdi_image_nb_draw_internal(
                            gdi_image_src_enum src_type,
                            U8 *img_src,
                            U8 img_type,
                            S32 img_size,
                            S32 x,
                            S32 y,
                            S32 w,
                            S32 h,
                            U32 img_flag,
                            U32 frame_pos,
                            gdc_job_flag_enum job_flag);
#define gdi_image_nb_draw(OFFSET_X,OFFSET_Y,IMAGE_PTR)              \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_RESOURCE,    \
                                    IMAGE_PTR,                      \
                                    GDI_IMAGE_TYPE_INVALID,         \
                                    0,                              \
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    0,                              \
                                    0,                              \
                                    0,                              \
                                    0,                              \
                                    GDC_JOB_DUMMY)
#define gdi_image_nb_draw_resized(OFFSET_X, OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_PTR) \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_RESOURCE,    \
                                    IMAGE_PTR,                      \
                                    GDI_IMAGE_TYPE_INVALID,         \
                                    0,                              \
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    RESIZED_WIDTH,                  \
                                    RESIZED_HEIGHT,                 \
                                    0,                              \
                                    0,                              \
                                    GDC_JOB_DUMMY)
#define gdi_image_nb_draw_frames(OFFSET_X,OFFSET_Y,IMAGE_PTR,FRAME_NO)              \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_RESOURCE,    \
                                    IMAGE_PTR,                      \
                                    GDI_IMAGE_TYPE_INVALID,         \
                                    0,                              \
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    0,                              \
                                    0,                              \
                                    0,                              \
                                    (U32)FRAME_NO,                              \
                                    GDC_JOB_DUMMY)
#define gdi_image_nb_draw_resized_frames(OFFSET_X, OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_PTR,FRAME_NO) \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_RESOURCE,    \
                                    IMAGE_PTR,                      \
                                    GDI_IMAGE_TYPE_INVALID,         \
                                    0,                              \
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    RESIZED_WIDTH,                  \
                                    RESIZED_HEIGHT,                 \
                                    0,                              \
                                    (U32)FRAME_NO,                  \
                                    GDC_JOB_DUMMY)
#define gdi_image_nb_draw_mem(OFFSET_X,OFFSET_Y,IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE)              \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_MEMORY,      \
                                    IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,\
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    0,                              \
                                    0,                              \
                                    0,                              \
                                    0,                              \
                                    GDC_JOB_DUMMY)
#define gdi_image_nb_draw_resized_mem(OFFSET_X, OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE) \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_MEMORY,      \
                                    IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,\
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    RESIZED_WIDTH,                  \
                                    RESIZED_HEIGHT,                 \
                                    0,                              \
                                    0,                              \
                                    GDC_JOB_DUMMY)
#define gdi_image_nb_draw_mem_frames(OFFSET_X,OFFSET_Y,IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,FRAME_NO)              \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_MEMORY,      \
                                    IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,\
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    0,                              \
                                    0,                              \
                                    0,                              \
                                    (U32)FRAME_NO,                  \
                                    GDC_JOB_DUMMY)
#define gdi_image_nb_draw_resized_mem_frames(OFFSET_X, OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,FRAME_NO) \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_MEMORY,      \
                                    IMAGE_PTR,IMAGE_TYPE,IMAGE_SIZE,\
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    RESIZED_WIDTH,                  \
                                    RESIZED_HEIGHT,                 \
                                    0,                              \
                                    (U32)FRAME_NO,                  \
                                    GDC_JOB_DUMMY)
#define gdi_image_nb_draw_file(OFFSET_X,OFFSET_Y,IMAGE_NAME) \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_FILE,        \
                                    (U8*)(IMAGE_NAME),                     \
                                    GDI_IMAGE_TYPE_INVALID,         \
                                    0,                              \
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    0,                              \
                                    0,                              \
                                    0,                              \
                                    0,                              \
                                    GDC_JOB_DUMMY)
#define gdi_image_nb_draw_resized_file(OFFSET_X,OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_NAME) \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_FILE,        \
                                    (U8*)(IMAGE_NAME),                     \
                                    GDI_IMAGE_TYPE_INVALID,         \
                                    0,                              \
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    RESIZED_WIDTH,                  \
                                    RESIZED_HEIGHT,                 \
                                    0,                              \
                                    0,                              \
                                    GDC_JOB_DUMMY)
#define gdi_image_nb_draw_file_frames(OFFSET_X,OFFSET_Y,IMAGE_NAME,FRAME_NO) \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_FILE,        \
                                    (U8*)(IMAGE_NAME),              \
                                    GDI_IMAGE_TYPE_INVALID,         \
                                    0,                              \
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    0,                              \
                                    0,                              \
                                    0,                              \
                                    (U32)FRAME_NO,                  \
                                    GDC_JOB_DUMMY)
#define gdi_image_nb_draw_resized_file_frames(OFFSET_X,OFFSET_Y,RESIZED_WIDTH,RESIZED_HEIGHT,IMAGE_NAME,FRAME_NO) \
                          gdi_image_nb_draw_internal(               \
                                    GDI_IMAGE_SRC_FROM_FILE,        \
                                    (U8*)(IMAGE_NAME),              \
                                    GDI_IMAGE_TYPE_INVALID,         \
                                    0,                              \
                                    OFFSET_X,                       \
                                    OFFSET_Y,                       \
                                    RESIZED_WIDTH,                  \
                                    RESIZED_HEIGHT,                 \
                                    0,                              \
                                    (U32)FRAME_NO,                  \
                                    GDC_JOB_DUMMY)
extern GDI_RESULT gdi_image_nb_stop(gdi_handle handle);
extern GDI_RESULT gdi_image_nb_stop_all(void);
extern void gdi_nb_set_blt(BOOL is_blt,BOOL is_progress);
extern void gdi_nb_set_done_callback(void (*callback)(GDI_RESULT result,gdi_handle handle));
extern gd_color_from_rgb_func gdi_act_color_from_rgb;
#include "pixcomfontengine.h"
extern U32 mmi_fe_show_string_n(
                U32 x_unsigned,
                U32 y_unsigned,
                U8 *String,
                int Len);
extern void mmi_fe_set_text_color(mmi_fe_color c);
extern void Get_CharWidthHeight(U32 Ch, S32 *pWidth, S32 *pHeight);


typedef struct
{
    float m[9];
} gdi_lt_matrix_struct;

extern gdi_result gdi_lt_projective_transform(
                    gdi_lt_matrix_struct *matrix, 
                    gdi_handle src_layer_handle,
                    kal_int32 src_rect_x,
                    kal_int32 src_rect_y,
                    kal_int32 src_rect_w,
                    kal_int32 src_rect_h,
                    GDI_LT_SRC_KEY_EDGE_FILTER_ENUM edge_filter_mode,
                    kal_uint32 edge_filter_color,
                    GDI_LT_SAMPLE_MODE_ENUM sample_mode);

extern gdi_result gdi_lt_projective_transform_ext(
                    gdi_lt_matrix_struct *matrix,
                    gdi_handle src_layer_handle,
                    kal_int32 src_rect_x,
                    kal_int32 src_rect_y,
                    kal_int32 src_rect_w,
                    kal_int32 src_rect_h,
                    kal_int32 dst_rect_x,
                    kal_int32 dst_rect_y,
                    kal_int32 dst_rect_w,
                    kal_int32 dst_rect_h,
                    GDI_LT_SRC_KEY_EDGE_FILTER_ENUM edge_filter_mode,
                    kal_uint32 edge_filter_color,
                    GDI_LT_SAMPLE_MODE_ENUM sample_mode,
                    kal_uint32 flag);

extern void gdi_lt_projective_transform_get_inverse_matrix(
                    gdi_lt_matrix_struct *in, 
                    gdi_lt_matrix_struct *out);

extern void gdi_lt_projective_transform_get_output_rect(
                    gdi_lt_matrix_struct *matrix, 
                    S32 in_width, 
                    S32 in_height, 
                    gdi_rect_struct *out_rect);

extern void gdi_lt_projective_transform_apply_point(
                    gdi_lt_matrix_struct *matrix, 
                    gdi_point_S32_struct *point);

extern kal_bool gdi_lt_projective_transform_hw_support(void);

/*****************************************************************************
 * FUNCTION
 *  gdi_bitblt
 * DESCRIPTION
 *  bitblt the content in src_layer_handle to active layer
 *  The color format of source layer and act layer can be different.
 *  The bitblt reagion (width, height) = (sx2-sx1+1, sy2-sy1+1).
 *  This region out of act layer clipping won't be drawn.
 *  All color on source layer, include source key, will be copy to act layer.
 * PARAMETERS
 *  src_layer_handle    [IN]    source layer
 *  sx1                 [IN]    region in source layer to bitblt
 *  sy1                 [IN]    region in source layer to bitblt
 *  sx2                 [IN]    region in source layer to bitblt
 *  sy2                 [IN]    region in source layer to bitblt
 *  dx1                 [IN]    region in active layer to bitblt to
 *  dy1                 [IN]    region in active layer to bitblt to
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
extern GDI_RESULT gdi_bitblt(
                gdi_handle src_layer_handle, 
                S32 sx1,
                S32 sy1,
                S32 sx2,
                S32 sy2,
                S32 dx1,
                S32 dy1);

#endif /* SDKGDI_H */ 


