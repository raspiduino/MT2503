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
 *   bmp_font_decode.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Bitmap font decoder interfaces
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

#ifndef __BFC_DECODE_API_H__
#define __BFC_DECODE_API_H__

#include "kal_general_types.h"
#include "bfc_enum.h"

typedef struct BFC_DECODE_STRUCT_T* BFC_DECODER_HANDLE;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Function to initialize the font decoder handle
 * @return  If the function succeeds, it will return BFC_STATUS_RETURN_SUCCESS
 * @remarks
 */
BFC_STATUS_ENUM bfcDecGetDecoder(BFC_DECODER_HANDLE *pHandle);

/**
 * @brief   Function to set the level1 and level2 pattern table
 * @param   handle      The bitmap font decoder handle
 * @param   pLV1Table   Pointer to the level1 pattern table
 * @param   pLV2Table   Pointer to the level2 pattern table
 * @return  If the function succeeds, it will return BFC_STATUS_RETURN_SUCCESS
 * @remarks
 */
BFC_STATUS_ENUM bfcDecSetDictionary(BFC_DECODER_HANDLE handle,
                                    const void         *pLV1Table,
                                    const void         *pLV2Table);

/**
 * @brief   Function to set the encoded font data for decoding
 * @param   handle      The bitmap font decoder handle
 * @param   fontStyle   The desired font style
 * @param   fontColor   The desired drawing color
 * @param   borderColor The font border color
 * @return  If the function succeeds, it will return BFC_STATUS_RETURN_SUCCESS
 * @remarks The fontColor and borderColor parameters should concide with canvas format
 */
BFC_STATUS_ENUM bfcDecSetAttribute(BFC_DECODER_HANDLE  handle,
                                   BFC_STYLE_ENUM      fontStyle,
                                   kal_uint32          fontColor,
                                   kal_uint32          borderColor);

/**
 * @brief   Function to set the target canvas for decoding
 * @param   handle          The bitmap font decoder handle
 * @param   pCanvasBase     The target canvas buffer base address
 * @param   canvasWidth     The target canvas buffer width
 * @param   canvasPitch     The target canvas buffer pitch
 * @param   canvasHeight    The target canvas buffer height
 * @param   canvasFormat    The pixel format of the canvas buffer
 * @return  If the function succeeds, it will return BFC_STATUS_RETURN_SUCCESS
 * @remarks
 */
BFC_STATUS_ENUM bfcDecSetCanvas(BFC_DECODER_HANDLE		handle,
                                void*						pCanvasBase,
                                kal_int32					canvasWidth,
                                kal_int32					canvasPitch,
                                kal_int32					canvasHeight,
                                BFC_RGB_FORMAT_ENUM   canvasFormat);

/**
 * @brief   Function to set the canvas clipping rectangle
 * @param   handle      The bitmap font decoder handle
 * @param   xClipStart  The x coordinate of the left-top corner
 * @param   yClipStart  The y coordinate of the left-top corner
 * @param   clipWidth   The width of the clipping rectangle
 * @param   clipHeight  The height of the clipping rectangle
 * @return  If the function succeeds, it will return BFC_STATUS_RETURN_SUCCESS
 * @remarks
 */
BFC_STATUS_ENUM bfcDecSetClipWindow(BFC_DECODER_HANDLE  handle,
                                    kal_int32           xClipStart,
                                    kal_int32           yClipStart,
                                    kal_int32           clipWidth,
                                    kal_int32           clipHeight);

/**
 * @brief   Function to start the font decoding progress
 * @param   handle      The bitmap font decoder handle
 * @param   pSrcData    The compressed bitmap font glyph data
 * @param   glyphWidth  The bitmap font glyph data width
 * @param   glyphHeight The bitmap font glyph data height
 * @param   xPosition   The left coorindate of the output window
 * @param   yPosition   The toop coordinate of the output window
 * @return  If the function succeeds, it will return BF_DEC_STATUS_RETURN_SUCCESS
 * @remarks If the glyph width is not in byte boundary, the source data should be
 *          padded with zeros to align the data in byte boundary.
 */
BFC_STATUS_ENUM bfcDecDrawGlyph(BFC_DECODER_HANDLE handle,
                                const kal_uint8    *pSrcData,
                                kal_int32          glyphWidth,
                                kal_int32          glyphHeight,
                                kal_int32          xPosition,
                                kal_int32          yPosition);

BFC_STATUS_ENUM bfcDecGetStyleWidth(BFC_DECODER_HANDLE   handle,
                                    BFC_STYLE_ENUM       fontStyle,
                                    kal_int32            glyphWidth,
                                    kal_int32			   glyphHeight,
                                    kal_int32			   *pStyleWidth);

/**
 * @brief   Function to deinitalize the font decoder object
 * @param   handle      The bitmap font decoder handle
 * @remarks
 */
void bfcDecReleaseDecoder(BFC_DECODER_HANDLE handle);

#ifdef __cplusplus
}
#endif

#endif // __BFC_DECODE_API_H__
