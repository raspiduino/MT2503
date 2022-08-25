/****************************************************************************
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
 *    stereo_video_color_transformation.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    Module to process stereo video color transformation.    
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
 * 02 09 2012 peter.wang
 * removed!
 * <saved by Perforce>
 *
 * 12 06 2011 chelun.tsai
 * removed!
 * .
 *
 * 11 30 2011 chelun.tsai
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/****************************************************************************
 * macro definitions
 ****************************************************************************/

/****************************************************************************
 * Include directives
 ****************************************************************************/
#include "kal_public_api.h"
#include "stereo_video_color_transformation.h"
#include "video_types_v2.h"

/****************************************************************************
 * type definitions
 ****************************************************************************/

/****************************************************************************
 * local variables
 ****************************************************************************/

/****************************************************************************
 * local fucntion declartaion
 ****************************************************************************/
static kal_bool stereo_video_side_by_side_color_transform_RGB565(void *src, void *dst, int src_width, int src_height);

/****************************************************************************
 * external function
 ****************************************************************************/

// move out form demand page
#pragma arm section code="SECONDARY_ROCODE"
#pragma arm section rodata="SECONDARY_RODATA"

kal_bool 
stereo_video_transformation(
  void * src,
  void * dst,
  kal_uint32 src_width,
  kal_uint32 src_height,
  stereo_video_format_enum_t format,
  stereo_video_mode_enum_t mode,
  stereo_video_algorithm_enum_t algorithm)
{
#if defined(__MTK_TARGET__)

  if ((STEREO_VIDEO_FORMAT_RGB565==format) &&
      (STEREO_VIDEO_MODE_SIDE_BY_SIDE==mode) && 
      (STEREO_VIDEO_ALG_COLOR_TRANSFORM==algorithm))
  {
    return stereo_video_side_by_side_color_transform_RGB565(src, dst, src_width, src_height);
  }

  return KAL_FALSE;
#else
  return KAL_TRUE;
#endif //#if defined(__MTK_TARGET__)
}


/****************************************************************************
 * utilities
 ****************************************************************************/

#if defined(__MTK_TARGET__)

#define R_MASK (0xF800)
#define G_MASK (0x07E0)
#define B_MASK (0x001F)

/*
 * stereo_video_side_by_side_color_transform_RGB565
 * mode : side by side 
 * algorithm : color transform(direct sample)  
 * format : RGB565
 *
 * params
 * src : source buffer address
 * dst : destination buffer address
 * src_width : source image width
 * src_height : source image height
 */

static kal_bool stereo_video_side_by_side_color_transform_RGB565(void *src, void *dst, int src_width, int src_height)
{
  kal_int32 i, j;
  kal_uint32 l_R, r_G, r_B;
  kal_uint32 *pleft, *pright, *pout;
  kal_uint32 width_offset; 
  kal_uint32 input;
  
  // input width must be 4-pixel align, it means left or right image are 2-pixel align
  if (src_width & 0x3)
  {
    return KAL_FALSE;
  }

  // buffer address must be 4 pixel align for performance optimize
  if (((kal_uint32)src & 0x3)||((kal_uint32)dst & 0x3))
  {
    return KAL_FALSE;
  }

  width_offset = src_width >> 2; // for left & right image, offset type is 2pixel, 4 byte
  pleft  = src;
  pright = pleft + width_offset;
  pout   = dst;

  i = src_height;
  while (--i >= 0) // column
  {
    j = width_offset;

    while(--j >= 0) // row
    {
      input = *pleft++;
      l_R = (input & (((kal_uint32)R_MASK<<16)|R_MASK));
    
      input = *pright++;
      r_G = (input & ((G_MASK<<16)|G_MASK));
      r_B = (input & ((B_MASK<<16)|B_MASK));

      *pout++ = l_R | r_G | r_B;
    }

    pleft += width_offset;
    pright += width_offset;
  }

  return KAL_TRUE;
}

#endif //#if defined(__MTK_TARGET__)

