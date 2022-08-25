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
 *    idp_img_rot_flip.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __IDP_IMG_ROT_FLIP_H__
#define __IDP_IMG_ROT_FLIP_H__

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
 * external symbol prototypes and declarations
 ****************************************************************************/

/* "idp_img_rot_angle_get_flip"
 * ret : return flip or not
 */
kal_bool idp_img_rot_angle_get_flip(img_rot_angle_enum_t rot_angle);

/* "idp_img_rot_angle_get_rot_angle"
 * ret : return rot angle without flip
 */
img_rot_angle_enum_t idp_img_rot_angle_get_rot_angle(img_rot_angle_enum_t rot_angle);

/* "idp_img_rot_angle_adjust_curr_img_flip_rot_angle"
 * ajudst rot/flip of current engine according to rot/flip of previous engine  
 *
 * prev_img_flip : flip of previous engine
 * prev_img_rot_angle : rot angle of previous engine
 * * curr_img_flip : inout, flip of current engine
 * * curr_img_rot_angle : inout, rot angle of current engine
 */
void idp_img_rot_angle_adjust_curr_img_flip_rot_angle(
  kal_bool               prev_img_flip, 
  img_rot_angle_enum_t   prev_img_rot_angle, 
  kal_bool             * curr_img_flip,
  img_rot_angle_enum_t * curr_img_rot_angle);



#endif // __IDP_IMG_ROT_FLIP_H__


