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
 *    stereo_video_color_transformation.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is the I/F definition of stereo_video_color_transformation module.
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
 * 12 06 2011 chelun.tsai
 * removed!
 * .
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
#ifndef __STEREO_VIDEO_COLOR_TRANSFORMATION__
#define __STEREO_VIDEO_COLOR_TRANSFORMATION__

/****************************************************************************
 * macro definitions
 ****************************************************************************/

/****************************************************************************
 * Include directives
 ****************************************************************************/
#include "video_types_v2.h"
#include "kal_general_types.h"

/****************************************************************************
 * type definitions
 ****************************************************************************/
typedef enum 
{
  STEREO_VIDEO_MODE_SIDE_BY_SIDE /**< 2 frames are located on the left & right of the source image */
, STEREO_VIDEO_MODE_TOP_DOWN     /**< 2 frames are located on the top & down of the source image */
} stereo_video_mode_enum_t;

typedef enum 
{
  STEREO_VIDEO_FORMAT_RGB565
, STEREO_VIDEO_FORMAT_RGB888
} stereo_video_format_enum_t;

typedef enum 
{
  STEREO_VIDEO_ALG_COLOR_TRANSFORM  /**< no calcuation, quality is poor */
, STEREO_VIDEO_ALG_GAMMA_TRANSFORM  /**< apply gamma correction, quality is good */
} stereo_video_algorithm_enum_t;


/****************************************************************************
 * external symbol prototypes and declarations
 ****************************************************************************/

/* 
 * "stereo_video_transformation" 
 * To process stereo video color conversion.
 *
 * src : source address, must be 4 byte alignmemt when format is RGB565
 * dst : destination address, must be 4 byte alignmemt when format is RGB565
 * src_width : source image width, must be 4 pixel alignment when format is RGB565
 * src_height : source image height, no any restriction about alignmemt
 * format : Only support RGB565 now.
 * mode : Only support STEREO_VIDEO_MODE_SIDE_BY_SIDE now.
 * algorithm : Only support STEREO_VIDEO_ALG_COLOR_TRANSFORM now.
 */
 
extern kal_bool 
stereo_video_transformation(
  void * src,
  void * dst,
  kal_uint32 src_width,
  kal_uint32 src_height,
  stereo_video_format_enum_t format,
  stereo_video_mode_enum_t mode,
  stereo_video_algorithm_enum_t algorithm);

#endif // __STEREO_VIDEO_COLOR_TRANSFORMATION__


