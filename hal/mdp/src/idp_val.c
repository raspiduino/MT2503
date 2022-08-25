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
 *    idp_val.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    The adaptation layer for video related legacy API functions.
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
 * 12 05 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 10 12 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 09 30 2011 ct.fang
 * removed!
 * .
 *
 * 06 17 2011 chrono.wu
 * removed!
 * .
 *
 * 06 09 2011 peter.wang
 * removed!
 * .
 *
 * 05 24 2011 peter.wang
 * removed!
 * .
 *
 * 04 11 2011 ct.fang
 * removed!
 * .
 *
 * 04 07 2011 ct.fang
 * removed!
 * .
 *
 * 12 06 2010 cm.huang
 * removed!
 * .
 *
 * 11 23 2010 cm.huang
 * removed!
 * .
 *
 * 11 13 2010 cm.huang
 * NULL
 * .
 *
 * 08 10 2010 ct.fang
 * removed!
 * .
 *
 * 08 05 2010 ct.fang
 * removed!
 * .
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Fix build warnings
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#define THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL

#include "drv_features_mdp.h"

#if defined(DRV_IDP_SUPPORT)

#include "kal_general_types.h"

#include "img_common_enum.h"
#include "idp_val.h"
#include "idp_video_decode.h"

/***************************************************
 *                Video Processing
 ***************************************************/
/***************************************************
 *                macro definitions
 ***************************************************/
#if defined(__MTK_TARGET__)
#if defined(DRV_IDP_MT6236_SERIES) \
    || defined(DRV_IDP_MT6276E2_SERIES) \
    || defined(DRV_IDP_6238_SERIES) \
    || defined(DRV_IDP_MT6255_SERIES) \
    || defined(DRV_IDP_MT6256_SERIES)

#define IDP_VAL_VP_API_IS_SUPPORTED

#endif
#endif

#if defined(DRV_IDP_6238_SERIES)
typedef struct
{
    kal_uint32 clip_conv_disp_width;
    kal_uint32 clip_conv_disp_height;
    kal_uint32 clip_conv_clip_left;
    kal_uint32 clip_conv_clip_right;
    kal_uint32 clip_conv_clip_top;
    kal_uint32 clip_conv_clip_bottom;
} CLIP_CONVERT_T;

static void
srcclip_2_dstclip_hori(img_rot_angle_enum_t const rot_angle,
                         kal_uint32 const src_width,
                         kal_uint32 const tar_width,
                         kal_uint32 const src_x1,
                         kal_uint32 const src_x2,
                         kal_uint32 * const dst_x1,
                         kal_uint32 * const dst_x2)
{
  if (NULL == dst_x1)
  {
    ASSERT(0);
  }
  if (NULL == dst_x2)
  {
    ASSERT(0);
  }

  {
    kal_uint32 const tar_x1 = ((src_x1 * tar_width) / src_width);
    // [MAUI_01207646]
    kal_uint32 const tar_x2 = (((src_x2 + 1) * tar_width) / src_width) - 1;

    (*dst_x1) = tar_x1;
    (*dst_x2) = tar_x2;
  }
}

static void
srcclip_2_dstclip_vert(img_rot_angle_enum_t const rot_angle,
                         kal_uint32 const src_height,
                         kal_uint32 const tar_height,
                         kal_uint32 const src_y1,
                         kal_uint32 const src_y2,
                         kal_uint32 * const dst_y1,
                         kal_uint32 * const dst_y2)
{
  if (NULL == dst_y1)
  {
    ASSERT(0);
  }
  if (NULL == dst_y2)
  {
    ASSERT(0);
  }

  {
    kal_uint32 const tar_y1 = ((src_y1 * tar_height) / src_height);
    // [MAUI_01207646]
    kal_uint32 const tar_y2 = (((src_y2 + 1) * tar_height) / src_height) - 1;

    (*dst_y1) = tar_y1;
    (*dst_y2) = tar_y2;
  }
}

/**
 *  @status OK
 *  @common none
 */
static kal_bool
_src_clip_to_dst_clip_convert(idp_val_vp_param_t* param,CLIP_CONVERT_T *prRender_Convert)
{
  kal_uint32 dst_clip_x1;
  kal_uint32 dst_clip_x2;
  kal_uint32 dst_clip_y1;
  kal_uint32 dst_clip_y2;
  kal_uint32 video_src_width_with_dummy, video_src_height_with_dummy;
  kal_uint32 video_target_width_with_dummy, video_target_height_with_dummy;
  kal_uint32 video_target_width_wo_dummy, video_target_height_wo_dummy;
  kal_uint32 real_video_display_width; /* The display target width after rotation */
  kal_uint32 real_video_display_height; /* The display target height after rotation */
  kal_uint32 real_video_clip_left; /* the clip_left after resizing and rotation. */
  kal_uint32 real_video_clip_right; /* the clip_right after resizing and rotation. */
  kal_uint32 real_video_clip_top; /* the clip_top after resizing and rotation. */
  kal_uint32 real_video_clip_bottom; /* the clip_bottom after resizing and rotation. */

  kal_uint32 const src_clip_width = param->src_clip_left - param->src_clip_right + 1;
  kal_uint32 const src_clip_height= param->src_clip_bottom - param->src_clip_top + 1;

  video_src_width_with_dummy  = param->video_src_width;
  video_src_height_with_dummy = param->video_src_height;
  video_target_width_wo_dummy = param->dst_width;
  video_target_height_wo_dummy = param->dst_height;

  // [MAUI_01245490]
  video_target_width_with_dummy = (((kal_uint32)(video_target_width_wo_dummy) *
                                    (kal_uint32)(video_src_width_with_dummy) +
                                    (kal_uint32)(src_clip_width) - 1) /
                                   (kal_uint32)(src_clip_width));
  video_target_height_with_dummy = (((kal_uint32)(video_target_height_wo_dummy) *
                                     (kal_uint32)(video_src_height_with_dummy) +
                                     (kal_uint32)(src_clip_height) - 1) /
                                    (kal_uint32)(src_clip_height));

  for (;;)
  {
    srcclip_2_dstclip_hori(param->rotation_angle,
                             video_src_width_with_dummy,
                             video_target_width_with_dummy,
                             param->src_clip_left,
                             param->src_clip_right,
                             &dst_clip_x1,
                             &dst_clip_x2);

    if ((dst_clip_x2 - dst_clip_x1 + 1) < video_target_width_wo_dummy)
    {
      ++video_target_width_with_dummy;
      continue;
    }
    else if ((dst_clip_x2 - dst_clip_x1 + 1) > video_target_width_wo_dummy)
    {
      dst_clip_x2 = (dst_clip_x1 + video_target_width_wo_dummy - 1);
      break;
    }
    else
    {
      break;
    }
  }

  for (;;)
  {
    srcclip_2_dstclip_vert(param->rotation_angle,
                             video_src_height_with_dummy,
                             video_target_height_with_dummy,
                             param->src_clip_top,
                             param->src_clip_bottom,
                             &dst_clip_y1,
                             &dst_clip_y2);

    if ((dst_clip_y2 - dst_clip_y1 + 1) < video_target_height_wo_dummy)
    {
      ++video_target_height_with_dummy;
      continue;
    }
    else if ((dst_clip_y2 - dst_clip_y1 + 1) > video_target_height_wo_dummy)
    {
      dst_clip_y2 = (dst_clip_y1 + video_target_height_wo_dummy - 1);
      break;
    }
    else
    {
      break;
    }
  }

  real_video_display_width = video_target_width_with_dummy;
  real_video_display_height = video_target_height_with_dummy;
  real_video_clip_left = dst_clip_x1;
  real_video_clip_right = dst_clip_x2;
  real_video_clip_top = dst_clip_y1;
  real_video_clip_bottom = dst_clip_y2;

  (*prRender_Convert).clip_conv_disp_width  = real_video_display_width;
  (*prRender_Convert).clip_conv_disp_height = real_video_display_height;
  (*prRender_Convert).clip_conv_clip_left   = real_video_clip_left;
  (*prRender_Convert).clip_conv_clip_right  = real_video_clip_right;
  (*prRender_Convert).clip_conv_clip_top    = real_video_clip_top;
  (*prRender_Convert).clip_conv_clip_bottom = real_video_clip_bottom;
}  // end of va2_vr_vp_6268_src_clip_to_dst_clip_convert

#endif //#if defined(DRV_IDP_6238_SERIES)

kal_bool 
idp_val_vp_open(
    kal_uint32 * const key)
{
#if defined(IDP_VAL_VP_API_IS_SUPPORTED)

#if defined(DRV_IDP_MT6256_E2_SERIES) && defined(MJPG_DECODE)
    idp_video_decode_mjpg_mode_disable();
#endif

    return idp_video_decode_open(key);
#else   // #if defined(IDP_VAL_VP_API_IS_SUPPORTED)
    return KAL_FALSE;
#endif  // #if defined(IDP_VAL_VP_API_IS_SUPPORTED)
}

extern kal_bool
idp_val_vp_close(
    kal_uint32 const key)
{
#if defined(IDP_VAL_VP_API_IS_SUPPORTED)
    return idp_video_decode_close(key);
#else
    return KAL_FALSE;
#endif
}

extern kal_bool
idp_val_vp_start(
    kal_uint32 const key)
{
#if defined(IDP_VAL_VP_API_IS_SUPPORTED)
    return idp_video_decode_start_all(key);
#else
    return KAL_FALSE;
#endif
}

extern kal_bool
idp_val_vp_stop(
    kal_uint32 const key)
{
#if defined(IDP_VAL_VP_API_IS_SUPPORTED)
    return idp_video_decode_stop(key);
#else
    return KAL_FALSE;
#endif
}

extern kal_bool 
idp_val_vp_is_busy(
    kal_uint32 const key,
    kal_bool * const busy)
{
#if defined(IDP_VAL_VP_API_IS_SUPPORTED)
    return idp_video_decode_is_busy(key, busy);
#else
    return KAL_FALSE;
#endif
}


extern kal_bool 
idp_val_vp_config(
    kal_uint32 const key,
    idp_val_vp_param_t* param)
{
#if defined(IDP_VAL_VP_API_IS_SUPPORTED)
#if defined(DRV_IDP_6238_SERIES)
    CLIP_CONVERT_T idp_val_vp_Convert;
    _src_clip_to_dst_clip_convert(param,&idp_val_vp_Convert);
#endif //#if defined(DRV_IDP_6238_SERIES)
    return idp_video_decode_config(
        key,

        /* not in use */
        IDP_VIDEO_DECODE_INTMEM_START_ADDRESS, 0,
        IDP_VIDEO_DECODE_INTMEM_SIZE, 0,
#if defined(DRV_IDP_6238_SERIES)
        IDP_VIDEO_DECODE_DC_TARGET_WIDTH, idp_val_vp_Convert.clip_conv_disp_width,
        IDP_VIDEO_DECODE_DC_TARGET_HEIGHT, idp_val_vp_Convert.clip_conv_disp_height,
#endif //#if defined(DRV_IDP_6238_SERIES)
        IDP_VIDEO_DECODE_EXTMEM_START_ADDRESS, param->ext_working_buffer_addr,
        IDP_VIDEO_DECODE_EXTMEM_SIZE, param->ext_working_buffer_size,
        IDP_VIDEO_DECODE_DONE_CB, param->frame_done_cb, 
        IDP_VIDEO_DECODE_DONE_CB_PARAM, param->frame_done_cb_param, 
      
        IDP_VIDEO_DECODE_SRC_WIDTH, param->video_src_width, 
        IDP_VIDEO_DECODE_SRC_HEIGHT, param->video_src_height, 

        /* not in use */
        IDP_VIDEO_DECODE_TARGET_WIDTH_FOR_TVOUT, 0,
        IDP_VIDEO_DECODE_TARGET_HEIGHT_FOR_TVOUT, 0,
#if defined(DRV_IDP_6238_SERIES)
        IDP_VIDEO_DECODE_TARGET_WIDTH, idp_val_vp_Convert.clip_conv_disp_width, 
        IDP_VIDEO_DECODE_TARGET_HEIGHT, idp_val_vp_Convert.clip_conv_disp_height, 
      
        IDP_VIDEO_DECODE_ENABLE_CLIP, KAL_TRUE,
        IDP_VIDEO_DECODE_CLIP_LEFT, idp_val_vp_Convert.clip_conv_clip_left, 
        IDP_VIDEO_DECODE_CLIP_RIGHT, idp_val_vp_Convert.clip_conv_clip_right, 
        IDP_VIDEO_DECODE_CLIP_TOP, idp_val_vp_Convert.clip_conv_clip_top, 
        IDP_VIDEO_DECODE_CLIP_BOTTOM, idp_val_vp_Convert.clip_conv_clip_bottom, 
#else
        IDP_VIDEO_DECODE_TARGET_WIDTH, param->dst_width, 
        IDP_VIDEO_DECODE_TARGET_HEIGHT, param->dst_height, 
      
        IDP_VIDEO_DECODE_ENABLE_CLIP, KAL_TRUE,
        IDP_VIDEO_DECODE_CLIP_LEFT, param->src_clip_left, 
        IDP_VIDEO_DECODE_CLIP_RIGHT, param->src_clip_right, 
        IDP_VIDEO_DECODE_CLIP_TOP, param->src_clip_top, 
        IDP_VIDEO_DECODE_CLIP_BOTTOM, param->src_clip_bottom, 
#endif // #if defined(DRV_IDP_6238_SERIES) 
        IDP_VIDEO_DECODE_CONTRAST_LEVEL, param->contrast_level, /**< should be 0x80 in normal cases. */
        IDP_VIDEO_DECODE_BRIGHTNESS_LEVEL, param->brightness_level, /**< should be 0x80 in normal cases. */

        IDP_VIDEO_DECODE_ROT_ANGLE, param->rotation_angle,

        IDP_VIDEO_DECODE_IMAGE_DATA_FORMAT, param->dst_color_format, /**< most common is IMG_COLOR_FMT_RGB565 */

        IDP_VIDEO_DECODE_ENABLE_PITCH, param->pitch_enable, 
        IDP_VIDEO_DECODE_BG_IMAGE_WIDTH, param->pitch_width, 

        IDP_VIDEO_DECODE_TRIGGER_LCD, KAL_FALSE, 
        IDP_VIDEO_DECODE_FORCE_LCD_HW_TRIGGER, KAL_FALSE, 

        /* not in use */
        IDP_VIDEO_DECODE_SRC_FMT_4X4, KAL_FALSE, 
        IDP_VIDEO_DECODE_ENABLE_MP4DEBLK, KAL_FALSE, 
        IDP_VIDEO_DECODE_MP4DEBLK_QUANT_BUF, 0x0, 

        IDP_VIDEO_DECODE_RESIZER_U_VALUE, 8,
        IDP_VIDEO_DECODE_RESIZER_V_VALUE, 15,
      
        0);
#else   // #if defined(IDP_VAL_VP_API_IS_SUPPORTED)
    return KAL_FALSE;
#endif  // #if defined(IDP_VAL_VP_API_IS_SUPPORTED)
}

extern kal_bool 
idp_val_vp_config_src_buffer_addr(
    kal_uint32 const key,
    kal_uint32 addr0, 
    kal_uint32 addr1, 
    kal_uint32 addr2)
{
#if defined(IDP_VAL_VP_API_IS_SUPPORTED)
    return idp_video_decode_config(
        key,
        IDP_VIDEO_DECODE_VIDEO_Y_BUFFER_ADDRESS, addr0,
        IDP_VIDEO_DECODE_VIDEO_U_BUFFER_ADDRESS, addr1,
        IDP_VIDEO_DECODE_VIDEO_V_BUFFER_ADDRESS, addr2,
        0);
#else
    return KAL_FALSE;
#endif
}

extern kal_bool 
idp_val_vp_config_dst_buffer_addr(
    kal_uint32 const key,
    kal_uint32 addr0, 
    kal_uint32 addr1, 
    kal_uint32 addr2)
{
#if defined(IDP_VAL_VP_API_IS_SUPPORTED)
    return idp_video_decode_config(
        key, 
#if defined(DRV_IDP_6238_SERIES)
        IDP_VIDEO_DECODE_DC_RDMA_ADDR,addr0,
#endif //#if defined(DRV_IDP_6238_SERIES)
        IDP_VIDEO_DECODE_FRAME_BUFFER_ADDRESS, addr0, 
        IDP_VIDEO_DECODE_FRAME_BUFFER_ADDRESS_2, addr0, 
        0);
#else
    return KAL_FALSE;
#endif
}

static kal_bool
_idp_val_vp_sample_callback_func(void* param)
{
    return KAL_TRUE;
}

void 
idp_val_vp_sample_code(void)
{
    kal_uint32 key;
    idp_val_vp_param_t param;
    kal_uint32 y_addr = 0, u_addr = 0, v_addr = 0;
    kal_uint32 dst_fb_1 = 0;//, dst_fb_2;

    if (KAL_FALSE == idp_val_vp_open(&key))
    {
        return; // Open fail, do error handling...
    }

    // For each video frame
    {
        kal_bool busy;
        do 
        {
            if (KAL_FALSE == idp_val_vp_is_busy(key, &busy))
            {
                return; // check busy fail, do error handling...
            }
            if (KAL_TRUE == busy)
            {
                // Do sleep like kal_sleep_task(1); for 4.615ms to yield CPU to other tasks.
            }
            else
            {
                break;
            }
        } while (1);

        param.ext_working_buffer_addr = 0x0;
        param.ext_working_buffer_size = 0x0;
        param.video_src_width = 320;
        param.video_src_height = 240;
        param.src_color_format = IMG_COLOR_FMT_YUV420;
        param.src_clip_left = 0;
        param.src_clip_right = 319;
        param.src_clip_top = 0;
        param.src_clip_bottom = 239;
        param.contrast_level = 0x80;
        param.brightness_level = 0x80;
        // Assume both MT6236/MT6276 EVB both use HVGA (480x320) LCM
        param.dst_width = 426; 
        param.dst_height = 320;
        // Destination clip is currently not supported, just ignore those or set them as no dst clipping
        param.dst_clip_left = 0; 
        param.dst_clip_right = 425;
        param.dst_clip_top = 0;
        param.dst_clip_bottom = 319;
        param.rotation_angle = IMG_ROT_ANGLE_90;
        // Use RGB565 or UYVY, suggest to use UYVY on MT6236 since no HW spatial dithering is supported.
        param.dst_color_format = IMG_COLOR_FMT_RGB565;
        param.pitch_enable = KAL_FALSE;
        param.pitch_width = 320; // Since the destinaation frame buffer is for rotated image, the pitch width should be 320 rather than 426.
        param.frame_done_cb = _idp_val_vp_sample_callback_func; // Will be invoked in HISR once done...
        param.frame_done_cb_param = NULL;
        
        if (KAL_FALSE == idp_val_vp_config(key, &param))
        {
            return; // config error, do error handling...
        }

        // Please be careful the Y, U, V addresses cannot be cacheable, i.e., cannot be any address higher than 0xF000_0000.
        // Please notice the addresses need to be format aligned...they cannot be odd number
        if (KAL_FALSE == idp_val_vp_config_src_buffer_addr(key, y_addr, u_addr, v_addr))
        {
            return; // config error, do error handling...
        }

        // Do something to toggle dst double frame buffer switch.
        // Assume to use color formats those have only single plane, such as RGB or UYVY packed format.
        if (KAL_FALSE == idp_val_vp_config_dst_buffer_addr(key, dst_fb_1, 0, 0))
        {
            return;
        }
    }

    // To stop video processing...
    {
        kal_bool busy;
        do 
        {
            if (KAL_FALSE == idp_val_vp_is_busy(key, &busy))
            {
                return; // check busy fail, do error handling...
            }
            if (KAL_TRUE == busy)
            {
                // Do sleep like kal_sleep_task(1); for 4.615ms to yield CPU to other tasks.
            }
            else
            {
                break;
            }
        } while (1);
    }

    // To close video processing to release resources...
    if (KAL_FALSE == idp_val_vp_close(key))
    {
        return; // do error handling...
    }
    key = 0x0;

    return;
}

#endif  //#if defined(DRV_IDP_SUPPORT)

