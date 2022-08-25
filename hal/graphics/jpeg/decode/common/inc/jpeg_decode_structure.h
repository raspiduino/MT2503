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
 *   jpeg_decode_structure.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Structure definition for JPEG decode.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __JPEG_DECODE_STRUCTURE_H__
#define __JPEG_DECODE_STRUCTURE_H__

#include "drv_features_jpeg.h"
#include "kal_general_types.h"
#include "simple_memory_manager.h"
#include "jpeg_enum.h"
#include "jpeg_parse_structure.h"
#include "exif_dec_structure.h"
#include "rs_buffer.h"
#include "swjd_huffman_decoder.h"
#include "swjd_dequant_idct_unit.h"
#include "swjd_fragment_processor.h"
#include "jpeg_misc_api.h"
#include "gfx_cache_switch_behavior_enum.h"


/// This bit is used to indicate that an EOF is encountered in the progressive decoding iteration.
/// Notice that we may need several EOFs for during the decoding of a progressive JPEG file.
/// This bit is used with the member variable: JPEG_DECODER.hwProgressiveDecodeLeft.
#define JPEG_DEC_PROG_ITERATION_COMPLETE_BIT       0x80000000

/// This two macros are used to access the variable huffTableReadyFlag.
#define SET_DC_HUFFMAN_TABLE_READY(flag, index)    (flag |= (1 << ((index) + 0)))
#define IS_DC_HUFFMAN_TABLE_READY(flag, index)     (flag &  (1 << ((index) + 0)))

#define SET_AC_HUFFMAN_TABLE_READY(flag, index)    (flag |= (1 << ((index) + 4)))
#define IS_AC_HUFFMAN_TABLE_READY(flag, index)     (flag &  (1 << ((index) + 4)))

#define IS_HUFFMAN_TABLE_READY(flag)               (flag &  0x33)

#define SET_QUANTIZATION_TABLE_READY(flag, index)  (flag |= (1 << ((index) + 8)))
#define IS_QUANTIZATION_TABLE_READY(flag, index)   (flag  & (1 << ((index) + 8)))

#define SW_DECODE_CHECK_ABORT(handle, pCheckAbort);                                                 \
do {                                                                             \
   if (pCheckAbort)                                                              \
   {                                                                             \
      if (!pCheckAbort())                                                        \
      {                                                                          \
         handle->codecState = JPEG_CODEC_STATE_IDLE;                             \
         handle->lastStatus = JPEG_STATUS_OK;                                    \
         return handle->lastStatus;                                              \
      }                                                                          \
   }                                                                             \
} while(0)


typedef kal_int32 (*CHECK_ABORT_FUNC)(void);

/// JPEG_DECODER structure defines the decoder
typedef struct JPEG_DECODER_T
{

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)    
   GFX_CACHE_SWITCH_BEHAVIOR_ENUM  dstBufferCacheSwitchBehavior; 
#endif

   /// Decoder related attribute
   JPEG_CODEC_TYPE_ENUM    codecType;
   JPEG_CODEC_STATE_ENUM   codecState;
   JPEG_STATUS_ENUM        lastStatus;
   JPEG_SCENARIO_TYPE_ENUM scenarioType;

   JPEG_FILE_INFO          fileInfo;                  ///< The parse result of JPEG file will be stored in this structure.
   kal_uint32              fileIsInMemory;            ///< Flag to record the location of source file.
   kal_uint32              imageOffsetInFile;         ///< The offset of the JPEG image in the file.
   
   kal_int32 (*callback_function)(JPEG_CODEC_STATE_ENUM state);   ///< Callback function.

   /// Canvas related attribute
   void                    *canvasBuffer[3];          ///< Pointer to the canvas buffer. (RGB or YUV)
   kal_uint32              canvasFormat;     			      ///< Canvas color format.
   MY_RECTANGLE            canvasWnd;                 ///< Canvas area.
   kal_uint32              canvasBytesPerPixel;       ///< Bytes per pixel of the canvas. This variable is set internally.

   /// Output window and clip window attribute
   /// Notice that the definition of output window and clip window is the same as PNG decoder.
   /// Both of these windows are in the canvas coordinate.
   kal_uint32              clipWndIsSet;              ///< Flag to record if clip window is set.
   MY_RECTANGLE            clipWnd;                   ///< Clip window (in canvas coordinate).
   kal_uint32              outputWndIsSet;            ///< Flag to record if output window is set.
   MY_RECTANGLE            outputWnd;                 ///< Output window (in canvas coordinate).

   MY_RECTANGLE            targetClipWnd;             ///< The intersection window of the clipWnd and the outputWnd. 
                                                      ///< The targetClipWnd is aligned with the output window coordinate, for internal use.

   /// Working memory control variables
   void                    *intMemoryAddr;            ///< Start address of internal working memory.
   kal_uint32              intMemorySize;             ///< Size of internal working memory.
   STSMM                   intMemorySMM;
   kal_uint32              intMemorySizeBest;         ///< The best size for internal memory buffer.
   kal_uint32              intMemorySizeMinimum;      ///< The minimum size for interal memory buffer.

   void                    *extMemoryAddr;            ///< Start address of external working memory.
   kal_uint32              extMemorySize;             ///< Size of external working memory.
   STSMM                   extMemorySMM;

   kal_uint32              extMemorySizeBest;         ///< The best size for external memory buffer.
   kal_uint32              extMemorySizeMinimum;      ///< The minimum size for external memory buffer.
   kal_bool                extMemorySwitched;         ///< KAL_TRUE if we switched the buffer into cached memory

   kal_uint8               *fsalCacheAddr;            ///< Start address of FSAL cache.
   kal_uint32              fsalCacheSize;             ///< Size of FSAL cache.

   kal_uint8               *fsalReadBufferAddr;       ///< Start address of FSAL read buffer.
   kal_uint32              fsalReadBufferSize;        ///< Size of FSAL read buffer.
   
   EXIF_APP1_INFO          *app1InfoBuffer;           ///< The pointer to a APP1 parser for APP1 marker parsing.

   JPEG_DECODE_MODE_ENUM   decodeMode;                ///< The decoding mode of the decode process.
   JPEG_DECODE_MODE_ENUM   decodingSource;            ///< Specify the current image to be decoded (thumbnail or main image)
                                                      ///< This variable is for internal use.

   JPEG_FILE_INFO          *fileInfoBackup;           ///< The backup for the fileInfo of the main image.
                                                      ///< When we are going to decode the thumbnail, we must backup the fileInfo of the main image.

#if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__)
   kal_int32               dataLeft;                  ///< Data left to be processed. This value is updated after each decode iteration.
                                                      ///< We may use this variable to determine if the file is corrupt.

   MY_RECTANGLE            paddedOutputWnd;           ///< Padded output window (with JPEG block padding), for internal use.
   RS_BUFFER               rsBuffer;                  ///< JPEG file read buffer for decoder.

   kal_uint32              *hwDecodeTableAddr;        ///< (HW decoder) Start address of decoding table.
   kal_uint32              hwDecodeTableSize;         ///< (HW decoder) Size of decoding table.

   kal_uint32              *hwProgCoefBufferAddr[3];  ///< (HW decoder) Start addresses of progressive coefficient buffer.
   kal_uint32              hwProgCoefBufferSize[3];   ///< (HW decoder) Sizes of progressive coefficient buffer.

   kal_uint8              *hwDecodeSysBufferAddr[3];    ///< (HW decoder) Start addresses of decoded sysram buffer.
   kal_uint8              *hwDecodeSysBufferAddr2[3];   ///< (HW decoder) Start addresses of decoded sysram buffer.
   kal_uint32              hwDecodeSysBufferSize[3];    ///< (HW decoder) Sizes of decoded sysram buffer.
   kal_uint32              hwDecodeSysBufferTotalSize;  ///< (HW decoder) Sizes of decoded sysram buffer.
   kal_uint32              hwDecodeSysBufferFlag;       ///< (HW decoder) Flag of toggling double sysram buffer.

   kal_uint32              hwTotalDU[3];                ///< (HW decoder) Number of DU for each component.
   kal_uint32              hwDUPerMCURow[3];            ///< (HW decoder) DU per MCU row for each component.
   kal_uint32              hwDummyDU[3];                ///< (HW decoder) Number of dummy DU for each component.

   kal_uint32              hwProgressiveDecodeLeft;     ///< (HW decoder) Decoding iteration left of the image.
                                                        ///< The most significant bit of this variable is used to
                                                        ///< indicate the completion of a progressive decoding iteration.

   kal_uint32              hwInterleaveStartMCU;      ///< (HW decoder)
   kal_uint32              hwInterleaveStepMCU;       ///< (HW decoder)
   kal_uint32              hwNonInterleaveStartDU[3]; ///< (HW decoder)
   kal_uint32              hwNonInterleaveStepDU[3];  ///< (HW decoder)

   /// (HW decoder) IDP related variable
   kal_uint32              idpKey;                    ///< (HW decoder) IDP key
   kal_uint32              *idpIntMemoryAddr;         ///< (HW decoder) start address of internal working memory for IDP.
   kal_uint32              idpIntMemorySize;          ///< (HW decoder) size of internal working memory for IDP.
   kal_uint32              *idpExtMemoryAddr;         ///< (HW decoder) start address of external working memory for IDP.
   kal_uint32              idpExtMemorySize;          ///< (HW decoder) size of external working memory for IDP.

   kal_uint32              hwMcuHLimit;               ///< (HW decoder) Number of MCU horizontal limit.
   kal_uint32              hwMcuHLimit2;              ///< (HW decoder) Number of MCU horizontal limit.
   kal_uint32              hwMcuPrevHLimit;           ///< (HW decoder) Number of previous MCU horizontal limit.
   kal_uint32              hwBrzFactor;               ///< (HW decoder) BRZ resize factor.
   kal_uint32              hwDecodeMcuCount[2];       ///< (HW decoder) Decoded MCU count.
   kal_uint32              hwDecodeSysPitch[3];       ///< (HW decoder) Pitch of decoded sysram buffer.
#endif /// __DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__

#if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SEPARATED_FROM_MDP__) || defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_DECODE_SUPPORTED__)
   kal_uint32              hwAcceleratorHandle;       ///< (HW decoder) hw accelerator handler
#endif

   /// The followings member variables are for SW decoder
   MY_RECTANGLE            validMcuWnd;               ///< The valid MCU information in the clipping window.
                                                      ///< The unit of this structure is MCU.

   // The following fields are for the Huffman decoder
   HuffmanDecoder          *pHuffDecoder;             ///< Pointer to the SW Huffman decoders for the image

   void                    *pHuffDecOutputBuf;        ///< Pointer to the Huffman decoder output buffer.
   kal_int32               huffDecOutputSize;         ///< Field for the Huffman decoder output buffer size.
   kal_int32               huffDecOutputAlign;        ///< The Huffman decoder output buffer alignment.
   kal_int32               huffDecOutputWidth;

   kal_uint32              tableReadyFlag;            ///< Bit mask to indicate the status of the Huffman tables.
   kal_uint32              tableLoadFlag;             ///< Trigger load table flag

   HuffmanDecDCTable       *pHuffDCTable[4];          ///< Huffman decoder DC table of the decoding image
   HuffmanDecACTable       *pHuffACTable[4];          ///< Huffman decoder AC table of the decoding image

   // The following fileds are for the dequant & IDCT
   SWJD_DEQUANT_IDCT_UNIT  *pDequantIDCTUnit;         ///< Pointer to the dequant-IDCT unit for the YUV compoments.
   kal_int32               dequantIDCTOutputSize;     ///< 
   kal_int32               dequantIDCTOutputAlign;    ///<
   void                    *pDequantIDCTOutputBuf;    ///<

   HuffmanDecQuantTable    *pInverseQuantTable[4];    ///< The quantization table for the dequant & IDCT processing.

   kal_int32               dctScaleBits;              ///< DCT scaling bits for different scaling ratio 1/2, 1/4 or 1/8.
   kal_int32               dctLod;                    ///< The LOD value ranges depends on the IDCT scaling ratio.
   

   // The following fields are for the fragment processor
   SWJD_FRAGMENT_PROCESSOR *pFragProcessor;           ///< Pointer to the fragment processor for Y2R and resizing.

   // The foolwing fields are for the SW JPEG decoder control
   kal_uint16              restartInterval;           ///< Restart interval for the baseline JPEG images.
   kal_int32               mcuWidthBits;              ///< (2 ^ mcuWidthBits)  = the width of a MCU AFTER DCT scaling.
   kal_int32               mcuHeightBits;             ///< (2 ^ mcuHeightBits) = the height of a MCU AFTER DCT scaling.

   JPEG_DECODE_ROTATE_ANGLE_ENUM rotationAngle;

   CHECK_ABORT_FUNC        pCheckAbort;               ///< Check-abort callback function. This function will be invoked regularly during the decoding process.
   
   kal_bool                bypassFragment;

   kal_bool                useHybridIDCTEnhance;      ///move HW IDCT to huffman decode phase to reduce output copy, and enhance performance    

} JPEG_DECODER;

typedef JPEG_DECODER*   JPEG_DECODER_HANDLE;
typedef JPEG_FILE_INFO  JPEG_PARSER;

#endif
