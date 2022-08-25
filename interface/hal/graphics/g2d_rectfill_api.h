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
 *   g2d_rectfill_api.h
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
#ifndef __G2D_RECTFILL_H__
#define __G2D_RECTFILL_H__

#include "kal_general_types.h"

#include "g2d_enum.h"
#include "g2d_common_api.h"

/// re-define structure
/// This is for compatible with old AP
/// #define 	G2D_HANDLE_STRUCT 		void




/**
 *  Setting the overlay buffer information
 *  @param addr         : base address of the overlay buffer
 *  @param width        : width of the overlay buffer
 *  @param height       : height of the overlay buffer
 *  @param overlay_buf_enable       : enable overlay's functionality
 *  @param color_format : enumaration type of the source color format(GRAY,RGB565,RGB888,ARGB8888,etc)
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks This function set the destination buffer information
 *           Must be called before starting the G2D features
 */
G2D_STATUS_ENUM g2dRectFillOverlayBufferInfo(G2D_HANDLE_STRUCT *handle, kal_bool overlay_buf_enable,
                                       kal_uint8 *bufferAddr, kal_uint32 bufferSize,
                                       kal_uint32 width, kal_uint32 height, G2D_COLOR_FORMAT_ENUM color_format);


/**
 *  Setting the rectangle fill region
 *  @param x     : start x-coordinate point
 *  @param y     : start y-coordinate point
 *  @param width : width of rectangle fill
 *  @param height: height of rectangle fill
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks This function sets the rectangle information that wants to fill
 */
G2D_STATUS_ENUM g2dRectFillSetDstWindow(G2D_HANDLE_STRUCT *handle, kal_int32 x, kal_int32 y, kal_int32 width, kal_int32 height);

/**
 *  Enable rectfill with alpha blending
 *  @param alpha_blend_enable : To enable alpha blending or not
 *  @param constant_alpha : The constant alpha value
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dRectFillSetSrcAlpha(G2D_HANDLE_STRUCT *handle, kal_bool src_alpha_enable, kal_uint32 src_alpha_value);

/**
 *  Setting the rectangle fill color
 *  @param color      : the color of the fill region, if the color gradient is disable,  \n
 *                      all the specified rectangle region will bed filled with color    \n
 *                      if the color gradient is enable (the gradient value is not zero),\n
 *                      the color will be the start color for rectangle gradient fill
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks This function sets the rectangle fill color
 */
G2D_STATUS_ENUM g2dRectFillSetColor(G2D_HANDLE_STRUCT *handle, kal_uint32 color);



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
G2D_STATUS_ENUM g2dRectFillQueryDstWindowRange(G2D_HANDLE_STRUCT *handle,
                                               kal_int32 *min_x, kal_int32 *max_x, kal_int32 *min_y, kal_int32 *max_y,
                                               kal_uint32 *min_w, kal_uint32 *max_w, kal_uint32 *min_h, kal_uint32 *max_h);



/**
 *  Start the rectangle fill operation
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks This function start the operation of rectangle fill
 */
G2D_STATUS_ENUM g2dRectFillStart(G2D_HANDLE_STRUCT *handle);


#endif /* g2d_rectfill.h */
