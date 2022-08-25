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
 *   jpeg_encode_structure.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Structure definition of JPEG encode.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __JPEG_ENCODE_STRUCTURE_H__
#define __JPEG_ENCODE_STRUCTURE_H__

#include "kal_general_types.h"

#include "simple_memory_manager.h"

#include "iul_x_math.h"

#include "drv_features_jpeg.h"
#include "jpeg_enum.h"
#include "jpeg_misc_api.h"

#include "swje_structure.h"

/// the size of marker segment should < 65535 (16 bits)
#define JPEG_THUMBNAIL_3BPP_MAX_SIZE   63600    /// 168 * 126 * 3 = 63504
/// Set the DRI number as 0xFFFFFFFF means that there is DRI = 0
/// This can reduce the if-else statement from "if((0 != (handle->driNum)) && (0 == restartInterval))" to "if(0 == restartInterval)"
#define JPEG_ENCODE_DRI_NUMBER_0      0xFFFFFFFF
#define JPEG_ENCODE_DRI_NUMBER        0x8
#define JPEG_ENCODE_ABORT_NUMBER      0xA


/// HW
typedef struct JPEG_QUICK_VIEW_IMAGE_INFO_T
{
   void *qvimg_src_addr;
   void *qvimg_dst_addr;
   void *qvimg_rot_src_addr;
 
   kal_uint32 qvimg_dst_buffer_size;
 
   kal_uint32 qvimg_width;
   kal_uint32 qvimg_height;
 
   void *app_nine_start_addr;
   kal_uint32 qvimg_offset;
   kal_uint32 qvimg_size;
 
   kal_uint32 qvimg_color_format;
   kal_uint32 qvimg_rot_angle;

} JPEG_QUICK_VIEW_IMAGE_INFO;



/// All
typedef struct JPEG_GENGERAL_ENCODE_INFO_T {
   kal_uint32 numComponent;
   kal_uint32 hSamplingFactor[3];
   kal_uint32 hSamplingFactorMax;

   kal_uint32 vSamplingFactor[3];
   kal_uint32 vSamplingFactorMax;

} JPEG_GENGERAL_ENCODE_INFO;



typedef struct JPEG_ENCODE_INFO_T {

   /// Destination attribute
   kal_uint32 dstWidth;
   kal_uint32 dstHeight;

   #if defined(__SW_JPEG_ENCODER_SUPPORT__)
      IUL_FIXED srcStepX;                 ///< srcStepX = srcImageWidth / outputWnd.w
      IUL_FIXED srcStepY;                 ///< srcStepY = srcImageHeight / outputWnd.h

      IUL_FIXED dstStepX;                 ///< dstStepX = outputWnd.w / srcImageWidth
      IUL_FIXED dstStepY;                 ///< dstStepY = outputWnd.h / srcImageHeight

      kal_uint32 srcPitch;
      kal_uint32 dstPitch;

      kal_uint32 dstMcuWidth;
      kal_uint32 dstMcuHeight;
      kal_int32 srcMcuWidth;
      kal_int32 srcMcuHeight;

      kal_uint32 srcCompWidthPerMcu[3];
      kal_uint32 srcCompHeightPerMcu[3];

      kal_uint32 dstTotalMcuPerRow;
      kal_uint32 dstTotalMcuPerColumn;
   #endif
} JPEG_ENCODE_INFO;



typedef struct JPEG_ENCODER_T {
   JPEG_CODEC_TYPE_ENUM codecType;
   JPEG_CODEC_STATE_ENUM codecState;
   JPEG_STATUS_ENUM lastStatus;

   JPEG_GENGERAL_ENCODE_INFO gengralEncodeInfo;
   JPEG_ENCODE_INFO* curEncodeInfo;
   JPEG_ENCODE_INFO mainEncodeInfo;                ///< The JPEG Encoder information.

   /// source attribute
   kal_uint32 srcWidth;
   kal_uint32 srcHeight;
   MY_RECTANGLE srcWindow;                         ///< source window (ROI)

   JPEG_ENCODE_ROTATE_ANGLE_ENUM rotation;

   JPEG_ENCODE_SOURCE_ENUM srcMode;                /// The source mode
   JPEG_RGB_FORMAT_ENUM srcRGBFormat;              /// The color format of source RGB
   JPEG_YUV_FORMAT_ENUM srcSamplingFormat;         /// The sampling format of source YUV

   #if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
      kal_bool enableSrcDynamicSwitch;
      kal_bool enableDstDynamicSwitch;
   #endif

   void *srcRGBBuffer;                             /// For the use of encode from RGB buffer
   void *srcYUVBuffer[3];                          /// For the use of encode from RGB/YUV buffer
   kal_uint32 srcBufferSize[3];

   #if defined(__SW_JPEG_ENCODER_SUPPORT__)
      void *YUVWorkingBuffer[3];
      void *RGBWorkingBuffer;
      void *RGBRotateWorkingBuffer;
      void *YUVRotateWorkingBuffer[3];
      kal_uint32 YUVRotateWorkingBufferSize[3];

      kal_int32 workingBufferMcuNum;
      kal_int32 workingBufferActualMcuNum;
   #endif

   JPEG_ENCODE_QUALITTY_ENUM dstQuality;
   #if defined(__SW_JPEG_ENCODER_SUPPORT__)
      kal_int32 dstQualityDevider;
   #endif

   JPEG_YUV_FORMAT_ENUM dstSamplingFormat;
   JPEG_FILE_FORMAT_ENUM dstFileFormat;

   SWJE_FILE dstFile;

   /// Thumbnail attributes
   kal_bool enableThumbnail;

   #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DYNAMIC_QUALITY_ADJUSTMENT)
      kal_bool enableDynamicQuantAdjustment;
      float quantScaleFactor; 
   #endif
   
   #if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__)
      void *dstThumbnailAddr;                           ///< this variable stores the thumbnail address which resides in output JPEG file buffer
      void *srcThumbnailAddr;                           ///< RGB/BGR source thumbnail image address

   #endif

   kal_int32 (*callback_function)(JPEG_CODEC_STATE_ENUM state);

   void *intMemoryAddr;
   void *extMemoryAddr;
   kal_uint32 intMemorySize;
   kal_uint32 extMemorySize;
   kal_bool extMemoryEnableDynamicSwitch;
   #ifdef __SW_JPEG_ENC_V2_USING_INTERNAL_MEMORY__
      kal_bool intMemoryAllocateEnable;
   #endif

   kal_uint32 intMemorySizeMinimum;
   kal_uint32 extMemorySizeMinimum;
   kal_uint32 intMemorySizeBest;
   kal_uint32 extMemorySizeBest;
   
   #if defined(__SW_JPEG_ENCODER_SUPPORT__)
      STSMM intMemorySMM;
      STSMM extMemorySMM;
   #endif
   
   #if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__)
      kal_uint32 stallOffset;

      /// variables for IDP
      kal_uint32 idpKey;
      kal_uint32 *idpIntMemoryAddr;
      kal_uint32  idpIntMemorySize;
      kal_uint32 *idpExtMemoryAddr;
      kal_uint32  idpExtMemorySize;

      /// variables for overlay
      kal_uint8 *ovlBufferAddr;
      kal_uint32 ovlBufferWidth;
      kal_uint32 ovlBufferHeight;
      ///JPEG_OVL_PALETTE_DEPTH_ENUM ovlBufferPaletteDepth;
      kal_uint32 ovlSourceKey;

      /// function pointers for IDP control
      kal_bool (*idp_open_func)(kal_uint32 *key);
      kal_bool (*idp_close_func)(kal_uint32 const key);
      kal_bool (*idp_config_func)(void *handle);
      kal_bool (*idp_start_output_func)(kal_uint32 const key);
      kal_bool (*idp_start_all_func)(kal_uint32 const key);
   #endif

   #if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SEPARATED_FROM_MDP__) || defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_ENCODE_SUPPORTED__)
      kal_uint32 hwAcceleratorHandle;
   #endif

   #if defined(__SW_JPEG_ENCODER_SUPPORT__)
      kal_uint32 driNum;
      kal_uint32 curRstNum;
      SWJE_QUANT_TABLE QuantTables[2];                      ///< Pointer to the quant tables
      kal_uint32 *zZagTable;
      SWJE_HUFF_TABLE huffTables[4];                        ///< Pointer to the huff tables
      kal_uint8 *pWorkingBuffer;                            ///< Working buffer for Qunat/FDCT/Huff
      kal_uint8 *exifWorkingBuffer;                         ///< Working buffer for Qunat/FDCT/Huff

      SWJE_FDCT_QUANT_FUNC (pFDCTQuantFunc); 

      SWJE_FRAGMENT_PROCESSOR *pFragProcessor;              ///< Pointer to the fragment processor.
      SWJE_FDCT_QUANT_UNIT *pFDCTQuantUnits;                ///< Pointer to the quant-FDCT unit for the YUV compoments.
      SWJE_HUFFMAN_ENCODER *pHuffEncoder;
   #endif
   /// abort function
   kal_int32 (*check_abort_func)(void);

   /// Quick view image temporal information
   void *qviImageBufferAddr;
   kal_uint32 qviImageWidth;
   kal_uint32 qviImageHeight;
   kal_uint32 qviImageColorFormat;
   kal_uint32 qviImageRotAngle;

} JPEG_ENCODER;



typedef JPEG_ENCODER* JPEG_ENCODER_HANDLE;



#endif
