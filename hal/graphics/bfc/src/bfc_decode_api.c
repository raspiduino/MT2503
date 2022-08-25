#include "bfc_decode_int.h"

#if defined(WIN32)
#include "assert.h"
#define ASSERT assert
#else
#include "kal_public_api.h"
#endif

/**
 * @brief   Function to initialize the font decoder handle
 * @return  If the function succeeds, it will return BFC_STATUS_RETURN_SUCCESS
 * @remarks
 */
BFC_STATUS_ENUM bfcDecGetDecoder(BFC_DECODER_HANDLE *pHandle)
{
   static BFC_DECODE_STRUCT decoder;   

   if (NULL == pHandle)
   {
      return BFC_STATUS_INVALID_POINTER;
   }

   memset(&decoder, 0x0, sizeof(decoder));

   decoder.fontStyle     = BFC_STYLE_NORMAL;
   decoder.canvasFormat  = BFC_RGB_FORMAT_RGB565;
   decoder.canvasBPPVal  = 2;
   decoder.clipWidth     = 0x7FFFFFFF;
   decoder.clipHeight    = 0x7FFFFFFF;

   *pHandle = &decoder;  // Set the return value

   return BFC_STATUS_RETURN_SUCCESS;
}


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
                                    const void         *pLV2Table)
{
   if (NULL == handle)
   {
      return BFC_STATUS_INVALID_HANDLE;
   }

   handle->pLV1Table = (BFC_LEVEL1_TABLE_STRUCT*)pLV1Table;
   handle->pLV2Table = (BFC_LEVEL2_TABLE_STRUCT*)pLV2Table;

   return BFC_STATUS_RETURN_SUCCESS;
}


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
                                   kal_uint32          borderColor)
{
   if (NULL == handle)
   {
      return BFC_STATUS_INVALID_HANDLE;
   }

   if ((BFC_STYLE_NORMAL != fontStyle) &&
       (BFC_STYLE_BOLD != fontStyle) && 
       (BFC_STYLE_ITALIC != fontStyle) &&
       (BFC_STYLE_BOLD_ITALIC != fontStyle) &&
       (BFC_STYLE_BORDER != fontStyle))
   {
      return BFC_STATUS_INVALID_STYLE;
   }

   handle->fontStyle     = fontStyle;
   handle->fontColor     = fontColor;
   handle->borderColor   = borderColor;

   handle->drawNoClip    = (void*)getRasterFuncNoClip(handle->canvasFormat, fontStyle);
   handle->drawWithClip  = (void*)getRasterFuncWithClip(handle->canvasFormat, fontStyle);

   return BFC_STATUS_RETURN_SUCCESS;
}


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
                                BFC_RGB_FORMAT_ENUM   canvasFormat)
{
   kal_int32 clipWidth;
   kal_int32 clipHeight;

   if (NULL == handle)
   {
      return BFC_STATUS_INVALID_HANDLE;
   }

   if (NULL == pCanvasBase)
   {
      return BFC_STATUS_INVALID_CANVAS;
   }

   if (canvasWidth <= 0)
   {
      return BFC_STATUS_INVALID_WIDTH;
   }

   if (canvasPitch <= 0)
   {
      return BFC_STATUS_INVALID_PITCH;
   }

   if (canvasHeight <= 0)
   {
      return BFC_STATUS_INVALID_HEIGHT;
   }

   switch(canvasFormat)
   {
	   case BFC_RGB_FORMAT_1BPP:
         handle->canvasFormat = canvasFormat;
         handle->canvasBPPVal = 1;
         break;
      case BFC_RGB_FORMAT_RGB565:
         handle->canvasFormat = canvasFormat;
         handle->canvasBPPVal = 16;
         break;
      case BFC_RGB_FORMAT_RGB888:
         handle->canvasFormat = canvasFormat;
         handle->canvasBPPVal = 24;
         break;
      case BFC_RGB_FORMAT_PARGB8888:
         handle->canvasFormat = canvasFormat;
         handle->canvasBPPVal = 32;
         break;
      case BFC_RGB_FORMAT_ARGB8888:
         handle->canvasFormat = canvasFormat;
         handle->canvasBPPVal = 32;
         break;
      default:
         return BFC_STATUS_INVALID_FORMAT;
   }
    
   handle->pCanvasBase  = pCanvasBase;
   handle->canvasWidth  = canvasWidth;
   handle->canvasPitch  = canvasPitch;
   handle->canvasHeight = canvasHeight;

   clipWidth    = MIN(handle->clipWidth, canvasWidth);
   clipHeight   = MIN(handle->clipHeight, canvasHeight);

   handle->clipLeft     = 0;
   handle->clipRight    = clipWidth - 1;
   handle->clipTop      = 0;
   handle->clipBottom   = clipHeight - 1;

   handle->drawNoClip   = (void*)getRasterFuncNoClip(canvasFormat, handle->fontStyle);
   handle->drawWithClip = (void*)getRasterFuncWithClip(canvasFormat, handle->fontStyle);

   return BFC_STATUS_RETURN_SUCCESS;
}


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
                                    kal_int32           clipHeight)
{
   if (NULL == handle)
   {
      return BFC_STATUS_INVALID_HANDLE;
   }

   if (0 >= clipWidth)
   {
      return BFC_STATUS_INVALID_WIDTH;
   }

   if (0 >= clipHeight)
   {
      return BFC_STATUS_INVALID_HEIGHT;
   }

   xClipStart = MAX(xClipStart, 0);
   yClipStart = MAX(yClipStart, 0);

   clipWidth  = MIN(clipWidth,  handle->canvasWidth);
   clipHeight = MIN(clipHeight, handle->canvasHeight);

   handle->clipWidth  = clipWidth;
   handle->clipHeight = clipHeight;
   handle->clipLeft   = xClipStart;
   handle->clipRight  = xClipStart + clipWidth - 1;
   handle->clipTop    = yClipStart;
   handle->clipBottom = yClipStart + clipHeight - 1;

   return BFC_STATUS_RETURN_SUCCESS;
}

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
                                kal_int32          yPosition)
{
   BFC_STATUS_ENUM   status;

   ASSERT(handle != NULL);
   ASSERT(pSrcData != NULL);
   ASSERT(glyphWidth > 0);
   ASSERT(glyphHeight > 0);

   status = drawGlyphCore(handle,
                          pSrcData,
                          glyphWidth,
                          glyphHeight,
                          xPosition,
                          yPosition);

   return status;
}

BFC_STATUS_ENUM bfcDecGetStyleWidth(BFC_DECODER_HANDLE   handle,
                                    BFC_STYLE_ENUM       fontStyle,
                                    kal_int32            glyphWidth,
                                    kal_int32			   glyphHeight,
                                    kal_int32			   *pStyleWidth)
{
   switch(fontStyle)
   {
      case BFC_STYLE_NORMAL:
         *pStyleWidth = glyphWidth;
         break;
      case BFC_STYLE_BOLD:
         *pStyleWidth = glyphWidth + 1;
         break;
      case BFC_STYLE_ITALIC:
         *pStyleWidth = glyphWidth + tiltTable[glyphHeight];
         break;
      case BFC_STYLE_BOLD_ITALIC:
         *pStyleWidth = glyphWidth + tiltTable[glyphHeight] + 1;
         break;
      case BFC_STYLE_BORDER:
         *pStyleWidth = glyphWidth + 2;
         break;
      default:
         return BFC_STATUS_INVALID_STYLE;
   }

   return BFC_STATUS_RETURN_SUCCESS;
}

/**
 * @brief   Function to deinitalize the font decoder object
 * @param   handle      The bitmap font decoder handle
 * @remarks
 */
void bfcDecReleaseDecoder(BFC_DECODER_HANDLE handle)
{
   // Do nothing
}
