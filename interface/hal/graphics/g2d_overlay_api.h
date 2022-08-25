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
 *   g2d_overlay_api.h
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
#ifndef __G2D_OVERLAY_H__
#define __G2D_OVERLAY_H__

#include "kal_general_types.h"

#include "g2d_enum.h"
#include "g2d_common_api.h"

/**
 *  Enable layer
 *  @param layer           : the layer that we want to enable
 *  @param layer_enable    : enable or not
 *  @return                : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dOverlayEnableLayer(G2D_HANDLE_STRUCT *handle,
                                      G2D_OVERLAY_LAYER_ENUM layer, kal_bool layer_enable);



/**
 *  Set function to this layer
 *  @param layer           : the layer that we want to enable
 *  @param function        :
 *  @return                : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dOverlaySetLayerFunction(G2D_HANDLE_STRUCT *handle,
                                           G2D_OVERLAY_LAYER_ENUM layer, G2D_OVERLAY_LAYER_FUNCTION_ENUM function);



/**
 *  Set font bit to this layer
 *  @param layer           : the layer that we want to enable
 *  @param font_bit        :
 *  @return                : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dOverlaySetLayerFontBit(G2D_HANDLE_STRUCT *handle,
                                          G2D_OVERLAY_LAYER_ENUM layer, G2D_FONT_BIT_ENUM font_bit);



/**
 *  set font fore-ground color to this layer
 *  @param layer           : the layer that we want to enable
 *  @param fg_color        : the font fore-ground color
 *  @return                : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dOverlaySetLayerFontFgColor(G2D_HANDLE_STRUCT *handle,
                                              G2D_OVERLAY_LAYER_ENUM layer, kal_uint32 fg_color);



/**
 *  set rectangle fill color  to this layer
 *  @param layer           : the layer that we want to enable
 *  @param rect_fill_color : the rectangle fill color
 *  @return                : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dOverlaySetLayerRectFillColor(G2D_HANDLE_STRUCT *handle,
                                                G2D_OVERLAY_LAYER_ENUM layer, kal_uint32 rect_fill_color);



/**
 *  set buffer information to this layer
 *  @param layer           : the layer that we want to enable
 *  @param bufferAddr      : the buffer address
 *  @param bufferSize      : the buffer size
 *  @return                : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dOverlaySetLayerBufferInfo(G2D_HANDLE_STRUCT *handle, G2D_OVERLAY_LAYER_ENUM layer,
                                             kal_uint8 *bufferAddr, kal_uint32 bufferSize);


/**
 *  set rgb buffer information to this layer
 *  @param layer           : the layer that we want to enable
 *  @param bufferAddr      : the buffer address
 *  @param bufferSize      : the buffer size
 *  @param width           :
 *  @param height          :
 *  @param color_format    :
 *  @return                : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dOverlaySetLayerRGBBufferInfo(G2D_HANDLE_STRUCT *handle, G2D_OVERLAY_LAYER_ENUM layer,
                                                kal_uint8 *bufferAddr, kal_uint32 bufferSize,
                                                kal_uint32 width, kal_uint32 height, G2D_COLOR_FORMAT_ENUM color_format);



/**
 *  set yuv buffer information to this layer
 *  @param layer           : the layer that we want to enable
 *  @param bufferAddr      : the buffer address
 *  @param bufferSize      : the buffer size
 *  @param width           :
 *  @param height          :
 *  @param color_format    :
 *  @return                : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dOverlaySetLayerYUVBufferInfo(G2D_HANDLE_STRUCT *handle, G2D_OVERLAY_LAYER_ENUM layer,
                                                kal_uint8 *bufferAddr[3], kal_uint32 bufferSize[3],
                                                kal_uint32 width, kal_uint32 height, G2D_COLOR_FORMAT_ENUM color_format);



/**
 *  set rectangle to this layer
 *  @param layer           : the layer that we want to enable
 *  @param x               :
 *  @param y               :
 *  @param w               :
 *  @param h               :
 *  @return                : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dOverlaySetLayerWindow(G2D_HANDLE_STRUCT *handle,
                                         G2D_OVERLAY_LAYER_ENUM layer, kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h);



/**
 *  enable source key to this layer
 *  @param layer           : the layer that we want to enable
 *  @param src_key_enable  :
 *  @param src_key_value   :
 *  @return                : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dOverlaySetLayerSrcKey(G2D_HANDLE_STRUCT *handle,
                                         G2D_OVERLAY_LAYER_ENUM layer, kal_bool src_key_enable, kal_uint32 src_key_value);



/**
 *  set rotation to this layer
 *  @param layer           : the layer that we want to enable
 *  @param rotation        :
 *  @return                : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dOverlaySetLayerRotation(G2D_HANDLE_STRUCT *handle,
                                           G2D_OVERLAY_LAYER_ENUM layer, G2D_CW_ROTATE_ANGLE_ENUM rotation);



/**
 *  enable alpha to this layer
 *  @param layer           : the layer that we want to enable
 *  @param alpha_enable    :
 *  @param alpha_value     :
 *  @return                : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dOverlaySetLayerAlpha(G2D_HANDLE_STRUCT *handle,
                                        G2D_OVERLAY_LAYER_ENUM layer, kal_bool alpha_enable, kal_uint32 alpha_value);



/**
 *  set background color
 *  @param bg_color        : the background color
 *  @return                : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dOverlaySetBgColor(G2D_HANDLE_STRUCT *handle, kal_uint32 bg_color);



/**
 *  set destination alpha
 *  @param alpha_enable    :
 *  @param alpha_enable    :
 *  @return                : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dOverlaySetDstAlpha(G2D_HANDLE_STRUCT *handle, kal_bool alpha_enable, kal_uint32 alpha_value);




/**
 *  set destination rectangle
 *  @param x               :
 *  @param y               :
 *  @return                : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dOverlaySetDstWindow(G2D_HANDLE_STRUCT *handle, kal_int32 x, kal_int32 y);




/**
 *  set roi rectangle
 *  @param x               :
 *  @param y               :
 *  @param w               :
 *  @param h               :
 *  @return                : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dOverlaySetRoiWindow(G2D_HANDLE_STRUCT *handle, kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h);




/**
 *  start overlay
 *  @return                : enumeration type of G2D status
 *  @remarks
 */
G2D_STATUS_ENUM g2dOverlayStart(G2D_HANDLE_STRUCT *handle);



#if defined(G2D_FPGA)

G2D_STATUS_ENUM g2dOverlayDisableBg(G2D_HANDLE_STRUCT *handle, kal_bool backgroundDisable);

#endif

#endif


