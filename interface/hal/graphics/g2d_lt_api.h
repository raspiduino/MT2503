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
 *   g2d_lt_api.h
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
 * removed!
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
#ifndef __G2D_LT_H__
#define __G2D_LT_H__

#include "kal_general_types.h"

#include "g2d_enum.h"
#include "g2d_common_api.h"

/// re-define structure
/// This is for compatible with old AP
/// #define 	G2D_HANDLE_STRUCT 		void

/**
 *  Enable lt with alpha blending
 *  @param alpha_blend_enable : To enable alpha blending or not
 *  @param constant_alpha : The constant alpha value
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dLTSetSrcAlpha(G2D_HANDLE_STRUCT *handle, kal_bool src_alpha_enable, kal_uint32 src_alpha_value);



/**
 *  Enable transparent
 *  @param alpha_tarnsparent_enable : To enable tarnsparent or not
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dLTSetDstAlpha(G2D_HANDLE_STRUCT *handle, kal_bool dst_alpha_enable, kal_uint32 dst_alpha_value);

/**
 *  Setting the Virtual Source Buffer Info, actually, It is RectFill, it doesn't need the buffer address.
 *  @param rectfillEnable        : Enable rectfill
 *  @param width        : the source buffer width
 *  @param height       : the source buffer height
 *  @param color_format : enumeration type of source color format
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks
 */

G2D_STATUS_ENUM g2dLTSetVirtualSrcBufferInfo(G2D_HANDLE_STRUCT *handle,
                                             kal_bool rectfillEnable, kal_uint32 rectfillColor, kal_uint32 width, kal_uint32 height, G2D_COLOR_FORMAT_ENUM color_format);


/**
 *  Setting the lt RGB source buffer information
 *  @param addr         : address pointer of source buffer
 *  @param width        : the source buffer width
 *  @param height       : the source buffer height
 *  @param color_format : enumeration type of source color format
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dLTSetSrcRGBBufferInfo(G2D_HANDLE_STRUCT *handle,
                                         kal_uint8 *bufferAddr, kal_uint32 bufferSize,
                                         kal_uint32 width, kal_uint32 height, G2D_COLOR_FORMAT_ENUM color_format);



/**
 *  Setting the lt YUV source buffer information
 *  @param addr         : address pointer of source buffer
 *  @param width        : the source buffer width
 *  @param height       : the source buffer height
 *  @param color_format : enumeration type of source color format
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dLTSetSrcYUVBufferInfo(G2D_HANDLE_STRUCT *handle,
                                         kal_uint8 *bufferAddr[3], kal_uint32 bufferSize[3],
                                         kal_uint32 width, kal_uint32 height, G2D_COLOR_FORMAT_ENUM color_format);



/**
 *  Setting the lt source rectangle information
 *  @param x : x-coordinate of top-left point in source rectangle
 *  @param y : y-coordinate of top-left point in source rectangle
 *  @param w : source rectangle width
 *  @param h : source rectangle height
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dLTSetSrcWindow(G2D_HANDLE_STRUCT *handle, kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h);



/**
 *  Setting the lt destination rectangle information
 *  @param x : x-coordinate of top-left point in source rectangle
 *  @param y : y-coordinate of top-left point in source rectangle
 *  @param w : source rectangle width. Each pixel in this destination rectangle will be scanned (And this will affect the performance).
 *  @param h : source rectangle height. Each pixel in this destination rectangle will be scanned (And this will affect the performance).
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dLTSetDstWindow(G2D_HANDLE_STRUCT *handle, kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h);



/**
 *  Set the edge filter mode when enabling source key
 *  @param filter_modes : The edge filter mode
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks  This API only takes effect while enabling source key
 */
G2D_STATUS_ENUM g2dLTSetSrcKeyEdgeFilterMode(G2D_HANDLE_STRUCT *handle, G2D_LT_SRC_KEY_EDGE_FILTER_ENUM filter_mode);



/**
 *  Set the user specific color for edge filter
 *  @param color        : The user specific color
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks  This function can be called in 2 condition
 *            1.  If AP enables linear transform with source key and sets G2D_LT_SRC_KEY_EDGE_FILTER_USER_SPEC_COLOR as the edge filter mode, this function is used to set the color for the boundary between source key and non source key.
 *            2.  If AP enables linear transform without source key and sets G2D_LT_SAMPLE_MODE_BILINEAR_WITH_EDGE_FILTER_USER_SPEC_COLOR as the sample mode, this function is used to set the color for the boundary.
 */
G2D_STATUS_ENUM g2dLTSetEdgeFilterColor(G2D_HANDLE_STRUCT *handle, kal_uint32 color);



/**
 *  Setting the lt the sample mode
 *  @param sample_mode  : The sample mode
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dLTSetSampleMode(G2D_HANDLE_STRUCT *handle, G2D_LT_SAMPLE_MODE_ENUM sample_mode);



/**
 *  Set the float-point matrix
 *  @param m : The inverse matrix
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dLTSetMatrix(G2D_HANDLE_STRUCT *handle, float* m);



/**
 *  Set the float-point inverse matrix
 *  @param m : The inverse matrix
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dLTSetInverseMatrix(G2D_HANDLE_STRUCT *handle, float* m);



/**
 *  Query working memory
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dLTQueryWorkingMemory(G2D_HANDLE_STRUCT *handle, kal_uint32 *int_memory_size, kal_uint32 *ext_memory_size);


/**
 *  Set working memory
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dLTSetWorkingMemory(G2D_HANDLE_STRUCT *handle,
                                      kal_uint32 *int_memory, kal_uint32 int_size,
                                      kal_uint32 *ext_memory, kal_uint32 ext_size);



/**
 *  Start Linear transform
 *  @return G2D_STATUS_ENUM : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dLTStart(G2D_HANDLE_STRUCT *handle);



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
G2D_STATUS_ENUM g2dLTQuerySrcWindowRange(G2D_HANDLE_STRUCT *handle,
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
G2D_STATUS_ENUM g2dLTQueryDstWindowRange(G2D_HANDLE_STRUCT *handle,
                                         kal_int32 *min_x, kal_int32 *max_x, kal_int32 *min_y, kal_int32 *max_y,
                                         kal_uint32 *min_w, kal_uint32 *max_w, kal_uint32 *min_h, kal_uint32 *max_h);




/**
 *  Query the RGB srouce buffer range
 *  @param min_width  : minimum of width
 *  @param max_width  : maximum of width
 *  @param min_height : minimum of height
 *  @param max_height : maximum of height
 *  @return           : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dLTQuerySrcRGBBufferRange(G2D_HANDLE_STRUCT *handle,
                                            kal_uint32 *min_width, kal_uint32 *max_width, kal_uint32 *min_height, kal_uint32 *max_height);



/**
 *  Query the YUV srouce buffer range
 *  @param min_width  : minimum of width
 *  @param max_width  : maximum of width
 *  @param min_height : minimum of height
 *  @param max_height : maximum of height
 *  @return           : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dLTQuerySrcYUVBufferRange(G2D_HANDLE_STRUCT *handle,
                                            kal_uint32 *min_width, kal_uint32 *max_width, kal_uint32 *min_height, kal_uint32 *max_height);




G2D_STATUS_ENUM g2dLTSetCacheSize(G2D_HANDLE_STRUCT *handle, G2D_LT_CACHE_SIZE_ENUM cache_size);
#endif
