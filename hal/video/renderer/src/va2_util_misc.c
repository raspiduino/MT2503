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
 *    
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    
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
 ****************************************************************************/
#if defined(__VIDEO_ARCHI_V2__)
/****************************************************************************
 * include directives
 ****************************************************************************/
/******* driver common **********************/
#include "drv_comm.h"

#include "kal_general_types.h"
#include "va2_util_misc.h"
#include "img_common_enum.h"
#include "video_types_v2.h"
#include "kal_public_api.h"
#include "va2_video_renderer_common.h"
#include "custom_vrender.h"

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_RENDER_ROCODE", rodata = "DYNAMIC_CODE_RENDER_ROCODE"
#endif

/****************************************************************************
 * external function bodies
 ****************************************************************************/
img_color_fmt_rgb_enum_t 
va2_util_convert_to_idp_rgb_format(
  VA2_VIDEO_RENDERER_COLOR_FORMAT_T color)
{
  switch (color)
  {
  case VIDEO_RENDERER_COLOR_RGB565: 
    return IMG_COLOR_FMT_RGB565;
    //break;

  case VIDEO_RENDERER_COLOR_RGB888: /**< R in MSB. */
    return IMG_COLOR_FMT_RGB888;
    //break;

  case VIDEO_RENDERER_COLOR_BGR888: /**< B in MSB. */
    return IMG_COLOR_FMT_BGR888;
    //break;

  case VIDEO_RENDERER_COLOR_ARGB8888: 
    return IMG_COLOR_FMT_ARGB8888;
    //break;

  default: 
    ASSERT(0);
    break;
  }
  
  return IMG_COLOR_FMT_RGB565;
}

// Convert Video Renderer color format to IDP color format
kal_uint32  
va2_util_convert_to_idp_color_format(
  VA2_VIDEO_RENDERER_COLOR_FORMAT_T color)
{
  switch (color)
  {
  case VIDEO_RENDERER_COLOR_RGB565: 
    return IMG_COLOR_FMT_RGB565;
    //break;

  case VIDEO_RENDERER_COLOR_RGB888: /**< R in MSB. */
    return IMG_COLOR_FMT_RGB888;
    //break;

  case VIDEO_RENDERER_COLOR_BGR888: /**< B in MSB. */
    return IMG_COLOR_FMT_BGR888;
    //break;

  case VIDEO_RENDERER_COLOR_ARGB8888: 
    return IMG_COLOR_FMT_ARGB8888;
    //break;

  case VIDEO_RENDERER_COLOR_PACKED_UYVY422: 
    return IMG_COLOR_FMT_PACKET_YUYV422;
    //break;

  case VIDEO_RENDERER_COLOR_YUV444: 
    return IMG_COLOR_FMT_YUV444; 
    //break;

  case VIDEO_RENDERER_COLOR_YUV422: 
    return IMG_COLOR_FMT_YUV422;
    //break;

  case VIDEO_RENDERER_COLOR_YUV420: 
    return IMG_COLOR_FMT_YUV420;
    //break;

  case VIDEO_RENDERER_COLOR_YUV411: 
    return IMG_COLOR_FMT_YUV411;
    //break;

  case VIDEO_RENDERER_COLOR_YUV400: 
    return IMG_COLOR_FMT_YUV400;
    //break;

  default: 
    ASSERT(0);
    break;
  }
  
  return IMG_COLOR_FMT_RGB565;
}

// Convert Video Renderer rotate angle to IDP rotate angle
img_rot_angle_enum_t
va2_util_convert_to_idp_rot_angle(
  kal_uint32 rot_angle, kal_bool flip)
{
  if (KAL_TRUE == flip)
  {
    switch (rot_angle)
    {
    case 0: 
      return IMG_MIRROR_ROT_ANGLE_0;
      //break;
  
    case 90:
      return IMG_MIRROR_ROT_ANGLE_90;
      //break;
  
    case 180: 
      return IMG_MIRROR_ROT_ANGLE_180;
      //break;
  
    case 270: 
      return IMG_MIRROR_ROT_ANGLE_270;
      //break;
  
    default: 
      ASSERT(0);
      break;
    }
  }
  else
  {
    switch (rot_angle)
    {
    case 0: 
      return IMG_ROT_ANGLE_0;
      //break;
  
    case 90:
      return IMG_ROT_ANGLE_90;
      //break;
  
    case 180: 
      return IMG_ROT_ANGLE_180;
      //break;
  
    case 270: 
      return IMG_ROT_ANGLE_270;
      //break;
  
    default: 
      ASSERT(0);
      break;
    }
  }

  return IMG_ROT_ANGLE_0;
}

kal_uint32 
va2_util_get_bpp(
  VA2_VIDEO_RENDERER_COLOR_FORMAT_T color)
{
  switch (color)
  {
  case VIDEO_RENDERER_COLOR_PACKED_UYVY422: 
  case VIDEO_RENDERER_COLOR_RGB565: 
    return 2;
    //break;

  case VIDEO_RENDERER_COLOR_RGB888: /**< R in MSB. */
  case VIDEO_RENDERER_COLOR_BGR888: /**< B in MSB. */
    return 3;
    //break;

  case VIDEO_RENDERER_COLOR_ARGB8888:
    return 4;
    //break;

  default: 
    return 1;
    //break;
  }
  
  //return 1;
}

// Clear the specific address and size with UYVY black color
kal_bool 
va2_util_clear_uyvy_buffer_black(kal_uint32* pu4Addr, kal_uint32 u4Size)	
{
     kal_uint32 i;
     
     for (i = 0; i < (u4Size >> 2); i++)
     {
          *(pu4Addr + i) = 0x00800080;
     }

     return KAL_TRUE;
}

// Calculate total rotation/flip according to Video Frame and UI display rotation/flip
// There are 2 cases needed to be discuss: Video Frame flip is enabled/disabled
void va2_util_calculate_total_rotate_angle_n_flip(
  va2_video_renderer_rotate_flip_t  video_frame_rotate_flip, 
  va2_video_renderer_rotate_flip_t  display_rotate_flip,
  va2_video_renderer_rotate_flip_t* rotate_flip)
{
  // Rv + Fv + Rd + Fd = Ro + Fo(v = video frame, d = display, o = output, R = rotation, F = flip)
  // if Fv == KAL_TRUE, (Rv - Rd) + (Fv + Fd) = Ro + Fo(if flip is enable, flip + rot = -rot + flip)
  if (video_frame_rotate_flip.b_flip== KAL_TRUE)
  {
    if (video_frame_rotate_flip.u2_cw_rotate_angle >= display_rotate_flip.u2_cw_rotate_angle)
    {
      rotate_flip->u2_cw_rotate_angle = video_frame_rotate_flip.u2_cw_rotate_angle - display_rotate_flip.u2_cw_rotate_angle;
    }
    else
    {
      rotate_flip->u2_cw_rotate_angle = 360 + video_frame_rotate_flip.u2_cw_rotate_angle - display_rotate_flip.u2_cw_rotate_angle;
    }
  }
  // if Fp == KAL_FALSE, (Rv + Rd) + (Fv + Fd) = Ro + Fo
  else
  {
    rotate_flip->u2_cw_rotate_angle = video_frame_rotate_flip.u2_cw_rotate_angle + display_rotate_flip.u2_cw_rotate_angle;
    if (rotate_flip->u2_cw_rotate_angle >= 360)
    {rotate_flip->u2_cw_rotate_angle -= 360;}
  }
  rotate_flip->b_flip = (kal_bool)(video_frame_rotate_flip.b_flip ^ display_rotate_flip.b_flip);
}

// This function is used to indicate current redraw should be apply or bypass(KAL_TRUE = bypass)
// 1. early render: if early redraw left time(video frame period duration - 1.5 * max LCD transfer time) > 0 
//                  and current duration < early redraw left time
// 2. late redraw: if not 1. and current duration > (video frame period duration + late redraw threshold)
//                 currently late redraw threshold is 250 ms
kal_bool va2_util_check_bypass_redraw(void *render_ctrl_blk)
{
  kal_uint32 save_irq_mask, u4DurationmS, u4CustFixedRedrawInterval;
  VRNDR_REDRAW_MODE redraw_mode;
  va2_comp_video_renderer_cb_t *cb = (va2_comp_video_renderer_cb_t*) render_ctrl_blk;

  if (NULL == cb)
  {
    ASSERT(0);
  }

  redraw_mode = VdoRndrGetRedrawMode(&u4CustFixedRedrawInterval);
  switch(redraw_mode)
  {
    case VDO_RNDR_REDRAW_FRM_PERIOD_AVOID:
    {
      kal_uint32 frame_duration_upper_bound;
      kal_int32 i4LeftTimeForEarlyRender;
      //kal_uint32 save_irq_mask;

      save_irq_mask = SaveAndSetIRQMask();

      u4DurationmS = drv_get_duration_ms(cb->u4LastSrcRenderTimestamp);
  
      frame_duration_upper_bound = cb->u4FramePeriodInMS + VA2_COMP_VR_DSPL_LATE_REDRAW_THRESHOLD;
      i4LeftTimeForEarlyRender = cb->u4FramePeriodInMS - cb->u4MaxLcdTransferDuration - ((cb->u4MaxLcdTransferDuration)>>1);
  
      if(i4LeftTimeForEarlyRender <= 0)
      {
        // if frame period is less than render duration, check late redraw only
        if(u4DurationmS < frame_duration_upper_bound)
        {
          RestoreIRQMask(save_irq_mask);
          return KAL_TRUE;
        }
      }
      else
      {
        // check if early redraw needed
        if(u4DurationmS > (kal_uint32) i4LeftTimeForEarlyRender)
        {
          // check if late redraw needed
          if(u4DurationmS < frame_duration_upper_bound)
          {
            RestoreIRQMask(save_irq_mask);
            return KAL_TRUE;
          }
        }
      }
      RestoreIRQMask(save_irq_mask);
    }
    break;

    case VDO_RNDR_REDRAW_CUST_FIXED_INTERVAL:
    {
      u4DurationmS = drv_get_duration_ms(cb->u4LastRenderTimestamp);
      if(u4DurationmS < u4CustFixedRedrawInterval)
      {
        return KAL_TRUE;
      }
    }
    break;

    case VDO_RNDR_REDRAW_DISABLE:
      return KAL_TRUE;
    //break;

    default:
      ASSERT(0);
  }

  return KAL_FALSE;
}

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

#endif  // #if defined(__VIDEO_ARCHI_V2__)

