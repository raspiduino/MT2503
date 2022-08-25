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
 *    idp_img_rot_flip.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    For idp rot angle and flip extraction and calculation.
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
 * 12 13 2011 chrono.wu
 * removed!
 * .
 *
 * 12 06 2011 chelun.tsai
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
#include "kal_general_types.h"
#include "img_common_enum.h"

/****************************************************************************
 * type definitions
 ****************************************************************************/

/****************************************************************************
 * local variables
 ****************************************************************************/

/****************************************************************************
 * utilities
 ****************************************************************************/

kal_bool idp_img_rot_angle_get_flip(img_rot_angle_enum_t rot_angle)
{
  if (IMG_MIRROR_ROT_ANGLE_0 <= rot_angle)
  {
    return KAL_TRUE;
  }
  else
  {
    return KAL_FALSE;
  }
}


img_rot_angle_enum_t idp_img_rot_angle_get_rot_angle(img_rot_angle_enum_t rot_angle)
{
  if (IMG_MIRROR_ROT_ANGLE_0 <= rot_angle)
  {
    return (img_rot_angle_enum_t)(rot_angle - IMG_MIRROR_ROT_ANGLE_0);
  }
  else
  {
    return rot_angle;
  }
}


void idp_img_rot_angle_adjust_curr_img_flip_rot_angle(
  kal_bool               prev_img_flip, 
  img_rot_angle_enum_t   prev_img_rot_angle, 
  kal_bool             * curr_img_flip,
  img_rot_angle_enum_t * curr_img_rot_angle)
{
  kal_bool adj_flip;
  img_rot_angle_enum_t adj_rot;

  // if prev flip is enabled, modify curr flip 
  if ((prev_img_flip == KAL_TRUE)&&
      (*curr_img_flip == KAL_TRUE))
  {
    adj_flip = KAL_FALSE;
  }
  else if ((prev_img_flip == KAL_TRUE)&&
           (*curr_img_flip == KAL_FALSE))
  {
    adj_flip = KAL_TRUE;
  }
  else
  {
    adj_flip = *curr_img_flip;
  }

  // Rp + Fp + Rn + Fn = Ro + Fo(p = previous, n = next, o = output, R = rotation, F = flip)
  // if Fp == KAL_TRUE, (Rp - Rn) + (Fp + Fn) = Ro + Fo(if flip is enable, flip + rot = -rot + flip)
  // Rn = Rp - Ro, Fn = Fo - Fp
  if (prev_img_flip == KAL_TRUE)
  {
    if (prev_img_rot_angle >= *curr_img_rot_angle)
    {
      adj_rot = (img_rot_angle_enum_t)(prev_img_rot_angle - *curr_img_rot_angle);
    }
    else
    {
      adj_rot = (img_rot_angle_enum_t)(IMG_MIRROR_ROT_ANGLE_0 + prev_img_rot_angle - (*curr_img_rot_angle));
    }
  }
  // if Fp == KAL_FALSE, (Rp + Rn) + (Fp + Fn) = Ro + Fo
  // Rn = Ro - Rp, Fn = Fo - Fp
  else
  {
    // if curr rotate angle >= prev rotate angle
    // modify back rotate angle by subtract rotate angle of front
    if (*curr_img_rot_angle >= prev_img_rot_angle)
    {
      adj_rot = (img_rot_angle_enum_t)(*curr_img_rot_angle - prev_img_rot_angle);
    }
    // if curr rotate angle < prev rotate angle
    // modify curr rotate angle by subtract rotate angle of prev from 360 degree
    else
    {
      adj_rot = (img_rot_angle_enum_t)(IMG_MIRROR_ROT_ANGLE_0 + (*curr_img_rot_angle) - prev_img_rot_angle);
    }
  }

  *curr_img_flip = adj_flip;
  *curr_img_rot_angle = adj_rot;
}


