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
 *   swje_structure.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __SWJE_STRUCTURE_H__
#define __SWJE_STRUCTURE_H__

#include "kal_general_types.h"

#include "fsal.h"

#include "iul_x_math.h"

#include "drv_features_jpeg.h"

#define SWJE_FRAG_PROC_DST_SAMPLING_FORMAT_TOTAL_NUMBER		2
#define SWJE_FRAG_PROC_SRC_RGB_FORMAT_TOTAL_NUMBER				3

typedef enum
{
   SWJE_FRAG_PROC_ROTATE_ANGLE_000 = 0,                     ///< No rotation.
   SWJE_FRAG_PROC_ROTATE_ANGLE_090,                         ///< Rotate 90 degree.
   ///SWJE_FRAG_PROC_ROTATE_ANGLE_180,                      ///< Rotate 180 degree.
   SWJE_FRAG_PROC_ROTATE_ANGLE_270,                         ///< Rotate 270 degree.
   ///SWJE_FRAG_PROC_ROTATE_ANGLE_MIRROR_000,               ///< Mirror with no rotation.
   ///SWJE_FRAG_PROC_ROTATE_ANGLE_MIRROR_090,               ///< Rotate 90 degree and mirror.
   ///SWJE_FRAG_PROC_ROTATE_ANGLE_MIRROR_180,               ///< Rotate 180 degree and mirror.
   ///SWJE_FRAG_PROC_ROTATE_ANGLE_MIRROR_270                ///< Rotate 270 degree and mirror.
   SWJE_FRAG_PROC_ROTATE_ANGLE_TOTAL_NUMBER
} SWJE_FRAG_PROC_ROTATE_ANGLE_ENUM;



typedef enum {
   SWJE_FRAG_PROC_SAMPLING_FORMAT_YUV420 = 0,
   SWJE_FRAG_PROC_SAMPLING_FORMAT_YUV422,
   SWJE_FRAG_PROC_SAMPLING_FORMAT_UYVY,

   SWJE_FRAG_PROC_SAMPLING_FORMAT_TOTAL_NUMBER
} SWJE_FRAG_PROC_SAMPLING_FORMAT_ENUM;


/// related to swje_frag_proc_func_array, Can not change the order
typedef enum {
   SWJE_FRAG_PROC_RGB_FORMAT_RGB565 = 0,
   SWJE_FRAG_PROC_RGB_FORMAT_RGB888,
   SWJE_FRAG_PROC_RGB_FORMAT_BGR888,

   SWJE_FRAG_PROC_RGB_FORMAT_TOTAL_NUMBER,
   SWJE_FRAG_PROC_RGB_FORMAT_UNSUPPORTED
} SWJE_FRAG_PROC_RGB_FORMAT_ENUM;



typedef enum {
   SWJE_FRAG_PROC_COLOR_FORMAT_YUV = 1,
   SWJE_FRAG_PROC_COLOR_FORMAT_RGB
} SWJE_FRAG_PROC_COLOR_FORMAT_ENUM;



typedef enum {
   SWJE_FRAG_PROC_RESIZE_CSC_FUNC_TYPE_NO_CSC_NO_RESIZE_NO_PAD = 0,
   SWJE_FRAG_PROC_RESIZE_CSC_FUNC_TYPE_NO_CSC_NO_RESIZE_PAD,
   SWJE_FRAG_PROC_RESIZE_CSC_FUNC_TYPE_NO_CSC_RESIZE_NO_PAD,
   SWJE_FRAG_PROC_RESIZE_CSC_FUNC_TYPE_NO_CSC_RESIZE_PAD,   /// SWJE_FRAG_PROC_RESIZE_CSC_FUNC_TYPE_NO_CSC_RESIZE_SRCPAD_NO_DSTPAD +
                                                 /// SWJE_FRAG_PROC_RESIZE_CSC_FUNC_TYPE_NO_CSC_RESIZE_NO_SRCPAD_DSTPAD
                                                 /// SWJE_FRAG_PROC_RESIZE_CSC_FUNC_TYPE_NO_CSC_RESIZE_SRCPAD_DSTPAD

   SWJE_FRAG_PROC_RESIZE_CSC_FUNC_TYPE_NO_CSC_HW_RESIZE_PAD,

   SWJE_FRAG_PROC_RESIZE_CSC_FUNC_TYPE_CSC_RESIZE_NO_PAD,
   SWJE_FRAG_PROC_RESIZE_CSC_FUNC_TYPE_CSC_RESIZE_PAD,
   SWJE_FRAG_PROC_RESIZE_CSC_FUNC_TYPE_CSC_NO_RESIZE_NO_PAD,
   SWJE_FRAG_PROC_RESIZE_CSC_FUNC_TYPE_CSC_NO_RESIZE_PAD
} SWJE_FRAG_PROC_RESIZE_CSC_FUNC_TYPE_ENUM;



typedef enum {
   SWJE_QUANT_TABLE_LUMINANCE_1 = 0,
   SWJE_QUANT_TABLE_CHROMINANCE_1
} SWJE_QUANT_TABLE_ENUM;



typedef enum {
   SWJE_HUFF_TABLE_TYPE_DC = 0,
   SWJE_HUFF_TABLE_TYPE_AC

} SWJE_HUFF_TABLE_TYPE_ENUM;



typedef enum {
   SWJE_HUFF_TABLE_COMPONENT_TYPE_DC_LUMINANCE   = 0,
   SWJE_HUFF_TABLE_COMPONENT_TYPE_DC_CHROMINANCE = 1,
   SWJE_HUFF_TABLE_COMPONENT_TYPE_AC_LUMINANCE   = 2,
   SWJE_HUFF_TABLE_COMPONENT_TYPE_AC_CHROMINANCE = 3

} SWJE_HUFF_TABLE_COMPONENT_TYPE_ENUM;



typedef enum {
   SWJE_STATUS_OK = 0,
   SWJE_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY,
   SWJE_STATUS_ENC_ERROR_GENERAL_ERROR
} SWJE_STATUS_ENUM;


typedef enum {
   SWJE_ERROR_STATUS_WRITE_TO_MEMORY_ERROR = -10,
   SWJE_ERROR_STATUS_WRITE_TO_FILE_ERROR = -15
} SWJE_ERROR_STATUS_ENUM;


typedef kal_int32 (*SWJE_FRAG_PROC_FUNC)(void *swjeFragProcessor);


typedef struct SWJE_RECTANGLE_T {
   kal_int32 x;                        ///< X coordinate of the left-top point.
   kal_int32 y;                        ///< Y coordinate of the left-top point.
   kal_uint32 w;                       ///< Width of the rectangle.
   kal_uint32 h;                       ///< Height of the rectangle.
} SWJE_RECTANGLE;



typedef struct SWJE_FRAGMENT_PROCESSOR_T {
   void *srcRGBBuffer;                                /// For the use of encode from RGB buffer

   void *srcResizeRGBBuffer;                          /// For the use of encode from RGB buffer
   void *dstResizeRGBBuffer;                          /// For the use of encode from RGB buffer
   void *srcResizeYUVBuffer[3];                       /// For the use of encode from RGB buffer

   void *dstRotateRGBBuffer;                          /// For the use of encode from RGB buffer
   void *dstRotateYUVBuffer[3];                       /// For the use of encode from RGB buffer
   kal_uint32 dstRotateYUVBufferSize[3];

   void *srcYUVBuffer[3];                             /// For the use of encode from YUV buffer
   void *dstYUVBuffer[3];                             /// For the use of encode from YUV buffer

   kal_bool srcPadFlag;
   kal_bool dstPadFlag;

   SWJE_FRAG_PROC_ROTATE_ANGLE_ENUM rotation;

   SWJE_FRAG_PROC_COLOR_FORMAT_ENUM srcColorFormat;
   SWJE_FRAG_PROC_RGB_FORMAT_ENUM srcRGBFormat;  ///< Canvas color format.
   SWJE_FRAG_PROC_SAMPLING_FORMAT_ENUM srcSamplingFormat;
   kal_uint32 srcWidth;
   kal_uint32 srcHeight;

   kal_uint32 srcResizeWidth;
   kal_uint32 srcResizeHeight;

   kal_uint32 dstExpectResizeWidth;
   kal_uint32 dstExpectResizeHeight;
   kal_uint32 dstActualResizeWidth;
   kal_uint32 dstActualResizeHeight;

   kal_uint32 srcResizeClipWidth;
   kal_uint32 srcResizeClipHeight;
   SWJE_RECTANGLE srcResizeClipWnd;

   kal_uint32 srcCompWidth[3];
   SWJE_RECTANGLE srcClipWnd;

   kal_int32 startX;
   kal_int32 startY;

   SWJE_FRAG_PROC_SAMPLING_FORMAT_ENUM dstSamplingFormat;
   kal_uint32 dstWidth;
   kal_uint32 dstHeight;
   kal_uint32 dstCompWidth[3];
   kal_uint32 dstHSamplingFactorShiftBit[3];
   kal_uint32 dstVSamplingFactorShiftBit[3];
   kal_uint32 dstHSamplingFactor[3];

   kal_uint32 outputImageWidth;
   kal_uint32 outputImageHeight;

   IUL_FIXED srcStepX;                 ///< srcStepX = srcImageWidth / outputWnd.w
   IUL_FIXED srcStepY;                 ///< srcStepY = srcImageHeight / outputWnd.h

   IUL_FIXED dstStepX;                 ///< dstStepX = outputWnd.w / srcImageWidth
   IUL_FIXED dstStepY;                 ///< dstStepY = outputWnd.h / srcImageHeight

   SWJE_FRAG_PROC_RESIZE_CSC_FUNC_TYPE_ENUM fragProcResizeCscFuncType;
   SWJE_FRAG_PROC_FUNC (fragProcResizeCscFunc);
   SWJE_FRAG_PROC_FUNC (fragProcRotateFunc);

} SWJE_FRAGMENT_PROCESSOR;


typedef kal_int32 (*SWJE_FDCT_QUANT_FUNC)(void *swjeFdctQuant, kal_int32 compID);

/// Quant-FDCT processor for a component.
typedef struct SWJE_QUANT_TABLE_T {
   kal_uint32 quantTableID;
   kal_int16 *pIntQuantTable;                ///< Pointer to the dequantization table.
   kal_int32 *pFixedQuantTable;              ///< Pointer to the dequantization table.
} SWJE_QUANT_TABLE;



/// Quant-FDCT processor for a component.
typedef struct SWJE_FDCT_QUANT_UNIT_T {
   SWJE_QUANT_TABLE quantTableItems;
   kal_uint32 *zZagTable;
   kal_uint8 *pSrc;                          ///< Pointer to the input coefficient block (8x8) buffer. Must be aligned on a 8-byte boundary.
   kal_uint8 *pFDCTDst;                      ///< Pointer to the output macro-block (8x8) buffer.
   kal_uint8 *pQuantDst;                     ///< Pointer to the output macro-block (8x8) buffer.
   kal_uint32 srcPitch;
   kal_uint8 *pDUWorkingBuffer;
   kal_uint32 lastNonzeroCoeff;
} SWJE_FDCT_QUANT_UNIT;



typedef struct SWJE_HUFF_TABLE_T{
   kal_uint8 huffTableID;
   SWJE_HUFF_TABLE_TYPE_ENUM type;
   kal_uint8 *pBits;
   kal_uint8 *pHuffValue;
   kal_uint16 *pHuffCode;
   kal_uint8 *pHufFSize;
} SWJE_HUFF_TABLE;



/// Huffman
typedef struct SWJE_COMPONENT_T {
   SWJE_HUFF_TABLE *pDCHuffTable;
   SWJE_HUFF_TABLE *pACHuffTable;
   kal_int32 lastDcVal;

} SWJE_HUFFMAN_COMPONENT;



typedef struct SWJE_FILE_T {
   STFSAL *pDstFileHandle;
   void *dstBufferAddr;
   kal_uint8 *dstWritePtr;
   kal_uint32 dstBufferSize;
   kal_int32 dstBufferLeft;
   kal_uint32 dstFileSize;                            ///< the output JPEG file size, returned with the API jpegEncGetEncodedDataLength

   #if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__)
      kal_bool dstFileCompleted;                    ///< Flag to indicate the completion of output file
   #endif

} SWJE_FILE;



typedef struct SWJE_HUFFMAN_ENCODER_T {
   SWJE_HUFFMAN_COMPONENT huffComponent[3];

   kal_uint32 srcLength;
   kal_uint8 *pSrc;
   /// Sync the write pointer of handle with the write pointer of handle
   /// This will point to handle->dstFile
   SWJE_FILE *dstFile;

   kal_uint32 unfinishEncodedBits;
   kal_uint32 unfinishEncodedSize;
   kal_uint32 lastNonzeroCoeff;
} SWJE_HUFFMAN_ENCODER;


typedef struct SWJE_YUV_RESIZER_COMPONENT_T {

   // Destination buffer base addresses
   kal_uint8 *bufferAddr;

   kal_uint32 width;
   kal_uint32 height;

   kal_int32 xStart;
   kal_int32 yStart;
   kal_uint32 clipWidth;
   kal_uint32 clipHeight;
} SWJE_YUV_RESIZER_COMPONENT;


typedef struct SWJE_YUV_RESIZER_T {
   kal_int32 srcStepX;
   kal_int32 srcStepY;

   // Source buffer base addresses
   kal_uint8 *pSrcYBase;
   kal_uint8 *pSrcUBase;
   kal_uint8 *pSrcVBase;

    // Source buffer width & height
    kal_uint32 srcWidth;
    kal_uint32 srcHeight;

    // Source buffer clipping info
    kal_int32 srcX;
    kal_int32 srcY;
    kal_uint32 srcClipWidth;
    kal_uint32 srcClipHeight;

    // Destination buffer base addresses
    kal_uint8 *pDstYBase;
    kal_uint8 *pDstUBase;
    kal_uint8 *pDstVBase;

    // Destination buffer width & height
    kal_uint32 dstWidth;
    kal_uint32 dstHeight;

    // Destination buffer clipping info
    kal_int32 dstX;
    kal_int32 dstY;
    kal_uint32 dstClipWidth;
    kal_uint32 dstClipHeight;
} SWJE_YUV_RESIZER;


#ifndef MIN
   #define MIN(x, y) ((((x)) <= ((y)))? x: y)
#endif // MIN

#ifndef MAX
   #define MAX(x, y) ((((x)) <= ((y)))? y: x)
#endif // MAX



#define JPEG_ENC_SW_EMIT_UINT8(c, dstWritePtr, dstBufferLeft, pHandle)                                                                          \
do                                                                                                                                              \
  {                                                                                                                                             \
   if(dstBufferLeft > 0)                                                                                                                        \
   {                                                                                                                                            \
      *dstWritePtr++ = c;                                                                                                                       \
      dstBufferLeft--;                                                                                                                          \
   }                                                                                                                                            \
   else                                                                                                                                         \
   {                                                                                                                                            \
      if(NULL != (pHandle->pDstFileHandle))                                                                                                     \
      {                                                                                                                                         \
          if(SWJE_ERROR_STATUS_WRITE_TO_FILE_ERROR != dstBufferLeft)                                                                            \
          {                                                                                                                                     \
             if (FSAL_OK != FSAL_Direct_Write((pHandle->pDstFileHandle), (pHandle->dstBufferAddr), (pHandle->dstBufferSize)))                   \
             {                                                                                                                                  \
                dstBufferLeft = SWJE_ERROR_STATUS_WRITE_TO_FILE_ERROR;                                                                          \
             }                                                                                                                                  \
             else                                                                                                                               \
             {                                                                                                                                  \
                *((kal_uint8 *)pHandle->dstBufferAddr) = c;                                                                                     \
                dstWritePtr = ((kal_uint8 *)pHandle->dstBufferAddr) + 1;                                                                        \
                dstBufferLeft = pHandle->dstBufferSize - 1;                                                                                     \
             }                                                                                                                                  \
         }                                                                                                                                      \
      }                                                                                                                                         \
      else                                                                                                                                      \
      {                                                                                                                                         \
         dstBufferLeft = SWJE_ERROR_STATUS_WRITE_TO_MEMORY_ERROR;                                                                               \
      }                                                                                                                                         \
   }                                                                                                                                            \
} while (0)



#define JPEG_ENC_SW_EMIT_UINT16(c, dstWritePtr, dstBufferLeft, pHandle)                                         \
do                                                                                                              \
  {                                                                                                             \
   JPEG_ENC_SW_EMIT_UINT8((kal_uint8)((c >> 8) & 0xFF), dstWritePtr, dstBufferLeft, pHandle);                   \
   JPEG_ENC_SW_EMIT_UINT8((kal_uint8)(c & 0xFF), dstWritePtr, dstBufferLeft, pHandle);                          \
} while (0)



/*
__inline kal_int32 jpeg_enc_sw_emit_uint8(kal_uint8 c, SWJE_FILE *pDstFileHandle)
{
   if((pDstFileHandle->dstBufferLeft) > 0 )
   {
      *(pDstFileHandle->dstWritePtr) = c;
      (pDstFileHandle->dstBufferLeft)--;
      (pDstFileHandle->dstWritePtr)++;
   }
   else
   {
      if(NULL != (pDstFileHandle->pDstFileHandle))
      {
          /// Direct file ouput
          if (FSAL_OK != FSAL_Direct_Write((pDstFileHandle->pDstFileHandle), (pDstFileHandle->dstBufferAddr), (pDstFileHandle->dstBufferSize)))
          {
             return -1;
          }
          /// (*bufferAddr) = startBufferAddr;
          /// (*buffeSizeLeft) = buffeSize;
          /// *(*bufferAddr) = c;
          /// (*buffeSizeLeft)--;
          /// (*bufferAddr)++;
          pDstFileHandle->dstWritePtr = pDstFileHandle->dstBufferAddr;
          *(pDstFileHandle->dstWritePtr) = c;
          pDstFileHandle->dstWritePtr++;
          pDstFileHandle->dstBufferLeft = (pDstFileHandle->dstBufferSize) - 1;
      }
      else
      {
         return -1;
      }
   }
   return 0;
}



__inline kal_int32 JPEG_ENC_SW_EMIT_UINT16(kal_uint16 c, SWJE_FILE *pDstFileHandle)
{
   kal_int32 ret;

   ret = jpeg_enc_sw_emit_uint8((kal_uint8)((c >> 8) & 0xFF), pDstFileHandle);
   ret = jpeg_enc_sw_emit_uint8((kal_uint8)(c & 0xFF), pDstFileHandle);

   return ret;
}


__inline kal_int32 jpeg_enc_sw_flush(SWJE_FILE *pDstFileHandle)
{

   if(NULL != (pDstFileHandle->pDstFileHandle))
   {
      if((pDstFileHandle->dstWritePtr) != (pDstFileHandle->dstBufferAddr))
      {
          kal_uint32 size = ((pDstFileHandle->dstBufferSize) - (pDstFileHandle->dstBufferLeft));

          /// Direct file ouput
          if (FSAL_OK != FSAL_Direct_Write((pDstFileHandle->pDstFileHandle), (pDstFileHandle->dstBufferAddr), size))
          {
             pDstFileHandle->dstBufferLeft = -10;
          }
          pDstFileHandle->dstWritePtr = pDstFileHandle->dstBufferAddr;
          pDstFileHandle->dstBufferLeft = pDstFileHandle->dstBufferSize;
      }
   }
   return 0;
}

#define jpeg_enc_sw_emit_uint8(c, pHandle)                                                                                                      \
do                                                                                                                                              \
  {                                                                                                                                             \
   if((pHandle->dstBufferLeft) > 0)                                                                                                             \
   {                                                                                                                                            \
      *pHandle->dstWritePtr++ = c;                                                                                                              \
      (pHandle->dstBufferLeft)--;                                                                                                               \
   }                                                                                                                                            \
   else                                                                                                                                         \
   {                                                                                                                                            \
      if(NULL != (pHandle->pDstFileHandle))                                                                                                     \
      {                                                                                                                                         \
          if (FSAL_OK != FSAL_Direct_Write((pHandle->pDstFileHandle), (pHandle->dstBufferAddr), (pHandle->dstBufferSize)))                      \
          {                                                                                                                                     \
             pHandle->dstBufferLeft = -10;                                                                                                      \
          }                                                                                                                                     \
          *((kal_uint8 *)pHandle->dstBufferAddr) = c;                                                                                           \
          pHandle->dstWritePtr = ((kal_uint8 *)pHandle->dstBufferAddr) + 1;                                                                     \
          pHandle->dstBufferLeft = (pHandle->dstBufferSize) - 1;                                                                                \
      }                                                                                                                                         \
      else                                                                                                                                      \
      {                                                                                                                                         \
         pHandle->dstBufferLeft = -15;                                                                                                          \
      }                                                                                                                                         \
   }                                                                                                                                            \
} while (0)

*/

#endif
