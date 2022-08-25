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
 *   g2d_bitblt_api.h
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
#ifndef __G2D_BITBLT_H__
#define __G2D_BITBLT_H__

#include "kal_general_types.h"

#include "g2d_enum.h"
#include "g2d_common_api.h"

/// re-define structure
/// This is for compatible with old AP
/// #define 	G2D_HANDLE_STRUCT 		void

/**
 *  Setting the bitblt source buffer information
 *  @param addr         : address pointer of source buffer
 *  @param width        : the source buffer width
 *  @param height       : the source buffer height
 *  @param color_format : enumeration type of source color format
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks  This fuction sets the source buffer used in bitblt feature
 *            The buffer must be assigned before start bitblt operation
 */
G2D_STATUS_ENUM g2dBitBltSetSrcRGBBufferInfo(G2D_HANDLE_STRUCT *handle,
                                             kal_uint8 *bufferAddr, kal_uint32 bufferSize,
                                             kal_uint32 width, kal_uint32 height, G2D_COLOR_FORMAT_ENUM color_format);



/**
 *  Setting the bitblt source rectangle information
 *  @param x : x-coordinate of top-left point in source bitblt rectangle
 *  @param y : y-coordinate of top-left point in source bitblt rectangle
 *  @param w : bitblt source rectangle width
 *  @param h : bitblt source rectangle height
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks  This function sets the source rectangle of the bitblt region,
 *            The rectangle must be assigned before start bitblt operation
 */
G2D_STATUS_ENUM g2dBitBltSetSrcWindow(G2D_HANDLE_STRUCT *handle, kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h);




/**
 *  Setting the bitblt destination rectangle information
 *  @param x : x-coordinate of top-left point in destination bitblt rectangle
 *  @param y : y-coordinate of top-left point in destination bitblt rectangle
 *  @param w : bitblt destination rectangle width
 *  @param h : bitblt destination rectangle height
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks  This function sets the destination rectangle of the bitblt region,
 *            The rectangle must be assigned before start bitblt operation
 */
G2D_STATUS_ENUM g2dBitBltSetDstWindow(G2D_HANDLE_STRUCT *handle, kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h);




/**
 *  Setting the bitblt rotation mode
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks This function sets the different rotation types of bitblt operation \n
 *           based on enumeration types of BITBLT_ROT_ANGLE_ENUM. There are 7 types \n
 *           of rotation can be specified
 *           The rotation can be appied in "bitlt only","bitblt with alpha blending", and
 *           "bitblt with ROP2" at the same time
 *
 */
G2D_STATUS_ENUM g2dBitBltSetRotation(G2D_HANDLE_STRUCT *handle, G2D_CW_ROTATE_ANGLE_ENUM rotation);



/**
 *  Enable Bitblt with alpha blending
 *  @param alpha_blend_enable : To enable alpha blending or not
 *  @param constant_alpha : The constant alpha value
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks  This function sets the alpha value for bitblt operation,
 *            If the alpha channel exists( in ARGB8888 or ARGB4444 color format), \n
 *            the per-pixel alpha is used for blending operation instead of constant alpha
 */
G2D_STATUS_ENUM g2dBitBltSetSrcAlpha(G2D_HANDLE_STRUCT *handle, kal_bool src_alpha_enable, kal_uint32 src_alpha_value);



/**
 *  Enable transparent
 *  @param alpha_tarnsparent_enable : To enable tarnsparent or not
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dBitBltSetDstAlpha(G2D_HANDLE_STRUCT *handle, kal_bool dst_alpha_enable, kal_uint32 dst_alpha_value);



/**
 *  Set index-color table
 *  @param palette_table : Palette table base address
 *  @param palette_size  : Palette table size
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM  g2dBitBltSetIndexColorTable(G2D_HANDLE_STRUCT *handle, kal_uint32 *palette_table, G2D_INDEX_COLOR_TABLE_SIZE_ENUM palette_size);



/**
 *  Query the srouce buffer range
 *  @param min_width  : minimum of width
 *  @param max_width  : maximum of width
 *  @param min_height : minimum of height
 *  @param max_height : maximum of height
 *  @return           : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dBitBltQuerySrcRGBBufferRange(G2D_HANDLE_STRUCT *handle, kal_uint32 *min_width, kal_uint32 *max_width, kal_uint32 *min_height, kal_uint32 *max_height);


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
G2D_STATUS_ENUM g2dBitBltQuerySrcWindowRange(G2D_HANDLE_STRUCT *handle,
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
G2D_STATUS_ENUM g2dBitBltQueryDstWindowRange(G2D_HANDLE_STRUCT *handle,
                                             kal_int32 *min_x, kal_int32 *max_x, kal_int32 *min_y, kal_int32 *max_y,
                                             kal_uint32 *min_w, kal_uint32 *max_w, kal_uint32 *min_h, kal_uint32 *max_h);


/**
 *  Start the bitblt operation feature
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks This function start performing the bitblt operation based \n
 *           on previous API setting
 */
G2D_STATUS_ENUM g2dBitBltStart(G2D_HANDLE_STRUCT *handle);




#endif
