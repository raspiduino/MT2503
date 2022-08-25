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
 *   g2d_sad_api.h
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
#ifndef __G2D_SAD_H__
#define __G2D_SAD_H__

#include "kal_general_types.h"

#include "g2d_enum.h"
#include "g2d_common_api.h"

/**
 *  Setting the SAD source buffer information
 *  @param addr         : address pointer of source buffer
 *  @param width        : the source buffer width
 *  @param height       : the source buffer height
 *  @param color_format : enumeration type of source color format
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks  This fuction sets the source buffer used in bitblt feature
 *            The buffer must be assigned before start bitblt operation
 */
G2D_STATUS_ENUM g2dSADSetSrcBufferInfo(G2D_HANDLE_STRUCT *handle, G2D_SAD_IMAGE_ENUM image_num, 
                                       kal_uint8 *bufferAddr, kal_uint32 bufferSize,
                                       kal_uint32 width, kal_uint32 height);




/**
 *  Setting the SAD source rectangle information
 *  @param x : x-coordinate of top-left point in source bitblt rectangle
 *  @param y : y-coordinate of top-left point in source bitblt rectangle
 *  @param w : bitblt source rectangle width
 *  @param h : bitblt source rectangle height
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks  This function sets the source rectangle of the bitblt region,
 *            The rectangle must be assigned before start bitblt operation
 */
G2D_STATUS_ENUM g2dSADSetSrcWindow(G2D_HANDLE_STRUCT *handle, G2D_SAD_IMAGE_ENUM image_num, kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h);




/**
 *  Setting the SAD destination rectangle information
 *  @param x : x-coordinate of top-left point in destination bitblt rectangle
 *  @param y : y-coordinate of top-left point in destination bitblt rectangle
 *  @param w : bitblt destination rectangle width
 *  @param h : bitblt destination rectangle height
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks  This function sets the destination rectangle of the bitblt region,
 *            The rectangle must be assigned before start bitblt operation
 */
G2D_STATUS_ENUM g2dSADSetDstWindow(G2D_HANDLE_STRUCT *handle, kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h);



/**
 *  Query the srouce buffer range
 *  @param min_width  : minimum of width
 *  @param max_width  : maximum of width
 *  @param min_height : minimum of height
 *  @param max_height : maximum of height
 *  @return           : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dSADQuerySrcBufferRange(G2D_HANDLE_STRUCT *handle, kal_uint32 *min_width, kal_uint32 *max_width, kal_uint32 *min_height, kal_uint32 *max_height);


/**
 *  Query the source ractangle range
 *  @param min_x : minimum of x
 *  @param max_x : maximum of x
 *  @param min_y : minimum of y
 *  @param max_y : maximum of y
 *  @param min_w : minimum of w
 *  @param max_w : maximum of w
 *  @param min_h : minimum of h
 *  @param max_h : maximum of h
 *  @return           : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dSADQuerySrcWindowRange(G2D_HANDLE_STRUCT *handle, 
                                          kal_int32 *min_x, kal_int32 *max_x, kal_int32 *min_y, kal_int32 *max_y,
                                          kal_uint32 *min_w, kal_uint32 *max_w, kal_uint32 *min_h, kal_uint32 *max_h);



/**
 *  Query the destination ractangle range
 *  @param min_x : minimum of x
 *  @param max_x : maximum of x
 *  @param min_y : minimum of y
 *  @param max_y : maximum of y
 *  @param min_w : minimum of w
 *  @param max_w : maximum of w
 *  @param min_h : minimum of h
 *  @param max_h : maximum of h
 *  @return           : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dSADQueryDstWindowRange(G2D_HANDLE_STRUCT *handle, 
                                          kal_int32 *min_x, kal_int32 *max_x, kal_int32 *min_y, kal_int32 *max_y,
                                          kal_uint32 *min_w, kal_uint32 *max_w, kal_uint32 *min_h, kal_uint32 *max_h);



/**
 *  Start the SAD operation feature
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks This function start performing the SAD operation based \n
 *           on previous API setting
 */
G2D_STATUS_ENUM g2dSADStart(G2D_HANDLE_STRUCT *handle);



/**
 *  Pause the SAD operation feature
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks This function pause performing the SAD operation based \n
 *           on previous API setting
 */
G2D_STATUS_ENUM g2dSADPause(G2D_HANDLE_STRUCT *handle);

/**
 *  Get Sum of SAD
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks This function start performing the bitblt operation based \n
 *           on previous API setting
 */
G2D_STATUS_ENUM g2dSADGetSum(G2D_HANDLE_STRUCT *handle, kal_uint32 *g2d_sad_sum);

#endif
