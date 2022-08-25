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
 *   g2d_drv_api.h
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
#ifndef __G2D_DRV_API_H__
#define __G2D_DRV_API_H__

#include "kal_general_types.h"

#include "g2d_enum.h"
#include "g2d_structure.h"

/// function prototype for common driver function
kal_bool g2d_irq_handler(void* g2d_status);

   
G2D_STATUS_ENUM g2d_drv_bitblt_start(G2D_HANDLE_STRUCT *handle);
G2D_STATUS_ENUM g2d_drv_bitblt_query_src_alpha_support(void);

G2D_STATUS_ENUM g2d_drv_font_start(G2D_HANDLE_STRUCT *handle);
G2D_STATUS_ENUM g2d_drv_font_query_aa_font_support(void);
G2D_STATUS_ENUM g2d_drv_font_query_tilt_font_support(void);

G2D_STATUS_ENUM g2d_drv_sad_start(G2D_HANDLE_STRUCT *handle);
G2D_STATUS_ENUM g2d_drv_sad_pause(G2D_HANDLE_STRUCT *handle);
G2D_STATUS_ENUM g2d_drv_get_sad_sum(kal_uint32 *g2d_sad_sum);

G2D_STATUS_ENUM g2d_drv_lt_start(G2D_HANDLE_STRUCT *handle);
G2D_STATUS_ENUM g2d_drv_lt_query_src_alpha_support(void);
G2D_STATUS_ENUM g2d_drv_lt_query_dst_alpha_support(void);

G2D_STATUS_ENUM g2d_drv_rectfill_start(G2D_HANDLE_STRUCT *handle);
G2D_STATUS_ENUM g2d_drv_overlay_start(G2D_HANDLE_STRUCT *handle);

void g2d_drv_set_clipping_window(G2D_HANDLE_STRUCT *handle);

void g2d_drv_set_replacement_colors(G2D_HANDLE_STRUCT *handle);

void g2d_drv_set_source_color_key(G2D_HANDLE_STRUCT *handle, 
                                  G2D_COLOR_FORMAT_ENUM src_color_format);

void g2d_drv_set_max_outstanding(G2D_HANDLE_STRUCT *handle);

void g2d_drv_power_on(void);
void g2d_drv_power_off(void);
void g2d_drv_init(void);
void g2d_drv_deinit(void);
void g2d_drv_set_hw_hisr_callback(G2D_CALLBACK_FUNC_PTR hisr_callback);
kal_int32 g2d_drv_get_hw_status(void);

void g2d_drv_set_dithering(G2D_HANDLE_STRUCT *handle);


void g2d_drv_set_burst_type(G2D_HANDLE_STRUCT *handle);
void g2d_drv_set_slow_down(G2D_HANDLE_STRUCT *handle);
void g2d_drv_set_tile(G2D_HANDLE_STRUCT *handle);


G2D_STATUS_ENUM g2d_drv_check_dst_canvas_info(kal_uint32 pitch);
G2D_STATUS_ENUM g2d_drv_check_src_canvas_info(kal_uint32 pitch);

G2D_STATUS_ENUM g2d_drv_check_src_window(kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h);
G2D_STATUS_ENUM g2d_drv_check_dst_window(kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h);

G2D_STATUS_ENUM g2d_drv_check_lt_src_window(kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h);
G2D_STATUS_ENUM g2d_drv_check_lt_dst_window(kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h);

G2D_STATUS_ENUM g2d_drv_check_clip_window(kal_int32 x, kal_int32 y, kal_uint32 x_max_clip, kal_uint32 y_max_clip);

G2D_STATUS_ENUM g2d_drv_query_src_canvas_info(kal_uint32 *min_width, kal_uint32 *max_width, kal_uint32 *min_height, kal_uint32 *max_height);
G2D_STATUS_ENUM g2d_drv_query_dst_canvas_info(kal_uint32 *min_width, kal_uint32 *max_width, kal_uint32 *min_height, kal_uint32 *max_height);

G2D_STATUS_ENUM g2d_drv_query_src_window(kal_int32 *min_x, kal_int32 *max_x, kal_int32 *min_y, kal_int32 *max_y,
                                       kal_uint32 *min_w, kal_uint32 *max_w, kal_uint32 *min_h, kal_uint32 *max_h);
G2D_STATUS_ENUM g2d_drv_query_dst_window(kal_int32 *min_x, kal_int32 *max_x, kal_int32 *min_y, kal_int32 *max_y,
                                       kal_uint32 *min_w, kal_uint32 *max_w, kal_uint32 *min_h, kal_uint32 *max_h);                                       
G2D_STATUS_ENUM g2d_drv_query_lt_src_window(kal_int32 *min_x, kal_int32 *max_x, kal_int32 *min_y, kal_int32 *max_y,
                                       kal_uint32 *min_w, kal_uint32 *max_w, kal_uint32 *min_h, kal_uint32 *max_h);
G2D_STATUS_ENUM g2d_drv_query_lt_dst_window(kal_int32 *min_x, kal_int32 *max_x, kal_int32 *min_y, kal_int32 *max_y,
                                       kal_uint32 *min_w, kal_uint32 *max_w, kal_uint32 *min_h, kal_uint32 *max_h);
                                       
                                       
#endif


