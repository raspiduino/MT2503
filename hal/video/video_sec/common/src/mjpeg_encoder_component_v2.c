/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 *   mjpeg_encoder_component_v2.c
 *
 * Project:
 * --------
 *  MTK
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
 ****************************************************************************/
#include "drv_comm.h"

#ifdef __VIDEO_ARCHI_V2__
#include "video_encoder_component_v2.h"
#ifdef __MJPEG_ENC_SUPPORT__

#include "kal_general_types.h"      /* Basic data type */
#include "kal_public_defs.h"
#include "kal_public_api.h"

#include "vcodec_v2_trc.h"
#include "video_buffer_management_v2.h"
#include "video_encoder_component_v2.h"
#include "mjpeg_encoder_component_v2.h"
#include "jpeg_mjpeg_mem.h"
#include "jpeg_encode_api.h"

#define EVENT_MJPEG_ENCODING  ((kal_uint32)0x00000001)

static MJPEG_ENCODER_MGR_T _rMJPEGEncMgr;



static kal_int32 _MJPEGEncCallback(JPEG_CODEC_STATE_ENUM eState)
{
    const kal_int32 u4Correct = 0;
    const kal_int32 u4Error = -1;
    MJPEG_ENCODER_MGR_T* pMgr = &_rMJPEGEncMgr;

    ///drv_trace1(TRACE_GROUP_10, MJPGENC_FUNC_CALL, _MJPEGEncCallback_FUNC);
    if(KAL_TRUE != pMgr->fgWaitingCallback)
    {
       ASSERT(0);
    }

    pMgr->fgWaitingCallback = KAL_FALSE;
    VideoEncoderReleaseYUV(pMgr->pu1CodingFrameAddr);

    pMgr->eCallbackStatus = eState;

    kal_set_eg_events(pMgr->rEncodeEvent, EVENT_MJPEG_ENCODING, KAL_OR);
    if(JPEG_CODEC_STATE_COMPLETE != eState)
    {
        ASSERT(0);
        return u4Error;
    }


    return u4Correct;
}



VIDEO_ENCODER_CODEC_ERROR_T MJPEGEncOpenAdapt(void)
{
    MJPEG_ENCODER_MGR_T* pMgr = &_rMJPEGEncMgr;
    JPEG_STATUS_ENUM eRet = JPEG_STATUS_CODEC_UNAVAILABLE;

    ///drv_trace1(TRACE_GROUP_10, MJPGENC_FUNC_CALL, MJPEGEncOpenAdapt_FUNC);
    if(MJPEG_ENC_CLOSE != pMgr->eEncState)
    {
       ASSERT(0);
    }

    // Initialize control variables of driver
    pMgr->pu1ExtMemAddr = NULL;
    pMgr->pu1IntMemAddr = NULL;
    pMgr->eSrcFormat = JPEG_YUV_FORMAT_YUV420;
    pMgr->fgWaitingCallback = KAL_FALSE;
    pMgr->pu1CodingFrameAddr = NULL;
    if(0 == pMgr->rEncodeEvent)
    {
        pMgr->rEncodeEvent = kal_create_event_group("MJPEG_ENC_EVEVT");
    }

    // Set source mode as YUV buffer
    eRet = jpegEncSetSrcMode(pMgr->rJPGHandle, JPEG_ENCODE_SOURCE_YUV_BUFFER);
    if (JPEG_STATUS_OK != eRet)
    {
       return VIDEO_ENCODER_CODEC_ERROR;
    }

    // Set YUV buffer as YUV420 format
    eRet = jpegEncSetSrcYUVFormat(pMgr->rJPGHandle, pMgr->eSrcFormat);
    if (JPEG_STATUS_OK != eRet)
    {
       return VIDEO_ENCODER_CODEC_ERROR;
    }

    // Set output sample format as YUV420 as well
    // YUV422 has better quality but the encoding speed is slower
    eRet = jpegEncSetDstSampleFormat(pMgr->rJPGHandle, JPEG_YUV_FORMAT_YUV420);
    if (JPEG_STATUS_OK != eRet)
    {
       return VIDEO_ENCODER_CODEC_ERROR;
    }

    // Set callback function for jpeg encoder
    eRet = jpegEncSetCallbackFunction(pMgr->rJPGHandle, _MJPEGEncCallback);
    if (JPEG_STATUS_OK != eRet)
    {
       return VIDEO_ENCODER_CODEC_ERROR;
    }

    pMgr->eEncState = MJPEG_ENC_OPEN;
    return VIDEO_ENCODER_CODEC_ERROR_NONE;
}



VIDEO_ENCODER_CODEC_ERROR_T MJPEGEncCloseAdapt(void)
{
   MJPEG_ENCODER_MGR_T* pMgr = &_rMJPEGEncMgr;
   JPEG_STATUS_ENUM eRet = JPEG_STATUS_CODEC_UNAVAILABLE;

   ///drv_trace1(TRACE_GROUP_10, MJPGENC_FUNC_CALL, MJPEGEncCloseAdapt_FUNC);
   ///ASSERT((MJPEG_ENC_DEINIT == pMgr->eEncState) || (MJPEG_ENC_OPEN == pMgr->eEncState));
   if((MJPEG_ENC_DEINIT != pMgr->eEncState) && (MJPEG_ENC_OPEN != pMgr->eEncState))
   {
      ASSERT(0);
   }

   /// free memory
   if (NULL != (pMgr->pu1ExtMemAddr))
   {
      VideoEncoderFreeAligned((void*)(pMgr->pu1ExtMemAddr));
      pMgr->pu1ExtMemAddr = NULL;
   }

   // Release the handler of jpeg encoder
   eRet = jpegEncReleaseEncoder(pMgr->rJPGHandle);
   if (JPEG_STATUS_OK != eRet)
   {
      return VIDEO_ENCODER_CODEC_ERROR;
   }

   _rMJPEGEncMgr.eEncState = MJPEG_ENC_CLOSE;
   return VIDEO_ENCODER_CODEC_ERROR_NONE;
}



VIDEO_ENCODER_CODEC_ERROR_T MJPEGEncInitAdapt(void)
{
   const kal_uint32 u4AlignedReq = 4;
   MJPEG_ENCODER_MGR_T* pMgr = &_rMJPEGEncMgr;
   JPEG_STATUS_ENUM eRet = JPEG_STATUS_CODEC_UNAVAILABLE;

   ///drv_trace1(TRACE_GROUP_10, MJPGENC_FUNC_CALL, MJPEGEncInitAdapt_FUNC);
   if(MJPEG_ENC_OPEN != pMgr->eEncState)
   {
      ASSERT(0);
   }

   // Set the dimention of YUV buffer
   eRet = jpegEncSetSrcDimension(pMgr->rJPGHandle, pMgr->u4Width, pMgr->u4Height);
   if (JPEG_STATUS_OK != eRet)
   {
      return VIDEO_ENCODER_CODEC_ERROR;
   }

   // Set the dimention of destination, which is the same as YUV buffer in our case
   eRet = jpegEncSetDstDimension(pMgr->rJPGHandle, pMgr->u4Width, pMgr->u4Height);
   if (JPEG_STATUS_OK != eRet)
   {
      return VIDEO_ENCODER_CODEC_ERROR;
   }

   // Set quality
   eRet = jpegEncSetDstQuality(pMgr->rJPGHandle, pMgr->eQuality);
   if (JPEG_STATUS_OK != eRet)
   {
      return VIDEO_ENCODER_CODEC_ERROR;
   }

   // Set rotation angle
   switch(pMgr->eGotRotateAngle)
   {
      case VIDEO_CODEC_ROTATE_0:
         pMgr->eCodecRotationAngle = JPEG_ENCODE_ROTATE_ANGLE_000;
      break;
      case VIDEO_CODEC_ROTATE_90:
         pMgr->eCodecRotationAngle = JPEG_ENCODE_ROTATE_ANGLE_090;
      break;
      ///case VIDEO_CODEC_ROTATE_180:
      ///   pMgr->eCodecRotationAngle = JPEG_ENCODE_ROTATE_ANGLE_180;
      ///break;
      case VIDEO_CODEC_ROTATE_270:
         pMgr->eCodecRotationAngle = JPEG_ENCODE_ROTATE_ANGLE_270;
      break;
      default:
         ASSERT(0);
      ///break;
   }
   eRet = jpegEncSetRotation(pMgr->rJPGHandle, pMgr->eCodecRotationAngle);
   if (JPEG_STATUS_OK != eRet)
   {
      return VIDEO_ENCODER_CODEC_ERROR;
   }

   // Query the working memory needed by jpeg encoder
   eRet = jpegEncQueryWorkingMemory(pMgr->rJPGHandle, &pMgr->u4IntMemSizeBest, &pMgr->u4IntMemSizeMin, &pMgr->u4ExtMemSizeBest, &pMgr->u4ExtMemSizeMin);
   if (JPEG_STATUS_OK != eRet)
   {
      return VIDEO_ENCODER_CODEC_ERROR;
   }

   // Set working memory to jpeg encoder
   if (NULL == pMgr->pu1IntMemAddr)
   {
      // Internal buffer has to be four-byte-aligned
      if (0 != pMgr->u4IntMemSizeMin)
      {
         pMgr->pu1IntMemAddr = (kal_uint8*)VideoEncoderGetIntMem(pMgr->u4IntMemSizeMin + (u4AlignedReq- 1));
         if ((kal_uint32)(pMgr->pu1IntMemAddr)%u4AlignedReq != 0)
         {
            pMgr->pu1IntMemAddr = (kal_uint8*)((((kal_uint32)(pMgr->pu1IntMemAddr) + (u4AlignedReq - 1))/u4AlignedReq)*u4AlignedReq);
         }
      }
   }
   if (NULL == pMgr->pu1ExtMemAddr)
   {
      // External buffer has to be four-byte-aligned
      if (0 != pMgr->u4ExtMemSizeMin)
      {
         pMgr->pu1ExtMemAddr = (kal_uint8*)VideoEncoderMallocCacheLineAlign(pMgr->u4ExtMemSizeMin + (u4AlignedReq - 1), KAL_FALSE);
         if ((kal_uint32)(pMgr->pu1ExtMemAddr)%u4AlignedReq != 0)
         {
            pMgr->pu1ExtMemAddr = (kal_uint8*)((((kal_uint32)(pMgr->pu1ExtMemAddr) + (u4AlignedReq - 1))/u4AlignedReq)*u4AlignedReq);
         }
      }
   }
   eRet = jpegEncSetWorkingMemory(pMgr->rJPGHandle, (kal_uint32*)pMgr->pu1IntMemAddr, pMgr->u4IntMemSizeMin, (kal_uint32*)pMgr->pu1ExtMemAddr, pMgr->u4ExtMemSizeMin);

   // Query the minimun size of bitstream buffer encoder required
   eRet = jpegEncQueryDstBufferSize(&pMgr->u4DstRequiredSize, JPEG_ENCODE_EVALUATION_MODE_WORST, pMgr->eQuality, pMgr->eSrcFormat, pMgr->u4Width, pMgr->u4Height, KAL_FALSE);
   if (JPEG_STATUS_OK != eRet)
   {
      return VIDEO_ENCODER_CODEC_ERROR;
   }

   pMgr->eEncState = MJPEG_ENC_INIT;
   return VIDEO_ENCODER_CODEC_ERROR_NONE;
}



VIDEO_ENCODER_CODEC_ERROR_T MJPEGEncDeInitAdapt(void)
{
    MJPEG_ENCODER_MGR_T* pMgr = &_rMJPEGEncMgr;

    ///drv_trace1(TRACE_GROUP_10, MJPGENC_FUNC_CALL, MJPEGEncDeInitAdapt_FUNC);
    if((MJPEG_ENC_CLOSE == pMgr->eEncState))
    {
       ASSERT(0);
    }

    pMgr->eEncState = MJPEG_ENC_DEINIT;
    return VIDEO_ENCODER_CODEC_ERROR_NONE;
}



VIDEO_ENCODER_CODEC_ERROR_T MJPEGEncGetParameterAdapt(VIDEO_ENCODER_PARAM_TYPE_T eCmd, void *pParam)
{
    VIDEO_ENCODER_CODEC_ERROR_T rRet = VIDEO_ENCODER_CODEC_ERROR_NONE;

    ///drv_trace1(TRACE_GROUP_10, MJPGENC_FUNC_CALL, MJPEGEncGetParameterAdapt_FUNC);
    switch(eCmd)
    {
        case VENC_PARAM_MEMORY_REQUIREMENT:
        {
            VIDEO_ENC_MEMORY_T* prMemorySize = (VIDEO_ENC_MEMORY_T*)pParam;

            ///#if 0
            ///JPEG_STATUS_ENUM eRet = JPEG_STATUS_CODEC_UNAVAILABLE;
            ///
            ///// Query the working memory needed by jpeg encoder
            ///eRet = jpegEncQueryWorkingMemory(pMgr->rJPGHandle,
            ///                                &pMgr->u4IntMemSizeBest,
            ///                                &pMgr->u4IntMemSizeMin,
            ///                                &pMgr->u4ExtMemSizeBest,
            ///                                &pMgr->u4ExtMemSizeMin);
            ///if (KAL_FALSE == _MJPEGEncCheckStatus(eRet))
            ///{
            ///    ASSERT(0);
            ///}
            ///prMemorySize->u4Height          = pMgr->u4Height;
            ///prMemorySize->u4Width           = pMgr->u4Width;
            ///prMemorySize->u4ExternalSize    = pMgr->u4ExtMemSizeBest;
            ///prMemorySize->u4InternalSize    = pMgr->u4IntMemSizeBest;
            ///#endif

            prMemorySize->u4ExternalSize    = JPEG_ENC_MJPEG_EXT_MIN_MEM_SIZE;
            prMemorySize->u4InternalSize    = 0;
        }
        break;
        case VENC_PARAM_BITSTREAM_IN_CACHE:
            *(kal_bool*)pParam = KAL_FALSE;
         break;
        default:
           rRet = VIDEO_ENCODER_CODEC_PARAM_NOT_SUPPORT;
        ///break;
    }
    return rRet;
}



VIDEO_ENCODER_CODEC_ERROR_T MJPEGEncSetParameterAdapt(VIDEO_ENCODER_PARAM_TYPE_T eCmd, void *pParam)
{
    MJPEG_ENCODER_MGR_T* pMgr = &_rMJPEGEncMgr;
    VIDEO_ENCODER_CODEC_ERROR_T rRet = VIDEO_ENCODER_CODEC_ERROR_NONE;

    ///drv_trace1(TRACE_GROUP_10, MJPGENC_FUNC_CALL, MJPEGEncSetParameterAdapt_FUNC);
    switch(eCmd)
    {
       case VENC_PARAM_WIDTH:
          pMgr->u4Width = *(kal_uint32*)(pParam);
       break;
       case VENC_PARAM_HEIGHT:
          pMgr->u4Height = *(kal_uint32*)(pParam);
       break;
       case VENC_PARAM_ROTATE:
          pMgr->eGotRotateAngle = *(VIDEO_CODEC_ROTATE_ANGLE_T*)(pParam);
       break;
       case VENC_PARAM_QUALITY:
       {
          VIDEO_ENCODER_QUALITY_T quality = *(VIDEO_ENCODER_QUALITY_T*)pParam;

          #if defined(MT6250) && (!defined(__MED_VIDEO_ULC__)) && (!defined(__MJPEG_ENC_SW_SLIM__))
             switch(quality)
             {
                case VIDEO_ENCODER_QUALITY_LOW:
                   pMgr->eQuality = JPEG_ENCODE_QUALITY_POOR;
                break;
                case VIDEO_ENCODER_QUALITY_NORMAL:
                   pMgr->eQuality = JPEG_ENCODE_QUALITY_LOW;
                break;
                case VIDEO_ENCODER_QUALITY_GOOD:
                   pMgr->eQuality = JPEG_ENCODE_QUALITY_FAIR;
                break;
                case VIDEO_ENCODER_QUALITY_FINE:
                   pMgr->eQuality = JPEG_ENCODE_QUALITY_FAIR;  // degrade one level for frame rate spec
                break;
                default:
                   pMgr->eQuality = JPEG_ENCODE_QUALITY_GOOD;
                ///break;
             }
          #else
             switch(quality)
             {
                case VIDEO_ENCODER_QUALITY_LOW:
                   pMgr->eQuality = JPEG_ENCODE_QUALITY_POOR;
                break;
                case VIDEO_ENCODER_QUALITY_NORMAL:
                   pMgr->eQuality = JPEG_ENCODE_QUALITY_LOW;
                break;
                case VIDEO_ENCODER_QUALITY_GOOD:
                   pMgr->eQuality = JPEG_ENCODE_QUALITY_FAIR;
                break;
                case VIDEO_ENCODER_QUALITY_FINE:
                   pMgr->eQuality = JPEG_ENCODE_QUALITY_GOOD;
                break;
                default:
                   pMgr->eQuality = JPEG_ENCODE_QUALITY_GOOD;
                ///break;
             }
          #endif
       }
       break;
       default:
          rRet = VIDEO_ENCODER_CODEC_PARAM_NOT_SUPPORT;
       ///break;
    }

    return rRet;
}



VIDEO_ENCODER_CODEC_ERROR_T MJPEGEncGenerateHeader(void)
{
    MJPEG_ENCODER_MGR_T* pMgr = &_rMJPEGEncMgr;

    ///drv_trace1(TRACE_GROUP_10, MJPGENC_FUNC_CALL, MJPEGEncGenerateHeader_FUNC);
    if(MJPEG_ENC_INIT != pMgr->eEncState)
    {
       ASSERT(0);
    }

    return VIDEO_ENCODER_CODEC_ERROR_NONE;
}



VIDEO_ENCODER_CODEC_ERROR_T MJPEGEncEncodeOneFrame(VIDEO_BUFFERHEADER_TYPE_T *prBufferHeader)
{
   MJPEG_ENCODER_MGR_T* pMgr = &_rMJPEGEncMgr;
   JPEG_STATUS_ENUM eRet = JPEG_STATUS_CODEC_UNAVAILABLE;
   kal_uint32 u4BufferYSize = 0;
   kal_uint32 u4BufferUSize = 0;
   kal_uint32 u4BufferVSize = 0;
   kal_uint8* pu1BufferY = NULL;
   kal_uint8* pu1BufferU = NULL;
   kal_uint8* pu1BufferV = NULL;
   kal_uint32 u4AvailableBufferSize = 0;

   ///drv_trace1(TRACE_GROUP_10, MJPGENC_FUNC_CALL, MJPEGEncEncodeOneFrame_FUNC);
   if (NULL == prBufferHeader)
   {
       return VIDEO_ENCODER_CODEC_ERROR_NONE;
   }

   ///ASSERT((MJPEG_ENC_INIT == pMgr->eEncState)||(MJPEG_ENC_READY_2_ENCODE == pMgr->eEncState));
   if((MJPEG_ENC_INIT != pMgr->eEncState) && (MJPEG_ENC_READY_2_ENCODE != pMgr->eEncState))
   {
      ASSERT(0);
   }

   // Support only source format YUV420
   if (JPEG_YUV_FORMAT_YUV420  == pMgr->eSrcFormat)
   {
       u4BufferYSize = pMgr->u4Width * pMgr->u4Height;
       u4BufferUSize = (pMgr->u4Width>>1) * (pMgr->u4Height>>1);
       u4BufferVSize = u4BufferUSize;
   }
   else
   {
       return VIDEO_ENCODER_CODEC_PARAM_NOT_SUPPORT;
       ///ASSERT(0);
   }
   pu1BufferY = prBufferHeader->pu1Buffer;
   pu1BufferU = pu1BufferY + u4BufferYSize;
   pu1BufferV = pu1BufferU + u4BufferUSize;

   // Set frame buffer to encoder
   pMgr->pu1CodingFrameAddr = pu1BufferY;
   eRet = jpegEncSetYUVBuffer(pMgr->rJPGHandle, (void*)pu1BufferY, (void*)pu1BufferU, (void*)pu1BufferV, u4BufferYSize, u4BufferUSize, u4BufferVSize);
   if (JPEG_STATUS_OK != eRet)
   {
      return VIDEO_ENCODER_CODEC_ERROR;
   }

   // Set bitstream buffer to encoder
   VideoEncoderAllocateBitstreamBuffer(&pMgr->rBistreamInfo.pu1StartAddr,
                                       &pMgr->rBistreamInfo.pu1EndAddr,
                                       &pMgr->rBistreamInfo.pu1WriteAddr,
                                       &pMgr->rBistreamInfo.pu1ReadAddr,
                                       &pMgr->rBistreamInfo.u4TotalLength);
                                       //&u4AvailableBufferSize);
   u4AvailableBufferSize = VideoEncoderGetBitstreamBufferAvailableSize();

   // the size of bitstream buffer has to be assured, otherwise reject input and wait for more space to encode
   if (pMgr->u4DstRequiredSize > u4AvailableBufferSize)
   {
       // if the space is not enough and the write pointer is near the buffer end
       // not updating write pointer to head would cause a infinite loop
       if (pMgr->rBistreamInfo.pu1ReadAddr < pMgr->rBistreamInfo.pu1WriteAddr)
       {
           const kal_uint32 u4ContainedNoSlice = 0;
           VideoEncoderUpdateBitstreamWP(pMgr->rBistreamInfo.pu1EndAddr, u4ContainedNoSlice);
           ///drv_trace4(TRACE_GROUP_10, MJPGENC_BUFF_NOT_ENOUGH,
           ///          (kal_uint32)pMgr->rBistreamInfo.pu1WriteAddr,
           ///          u4AvailableBufferSize,
           ///          pMgr->u4DstRequiredSize,
           ///          __LINE__);
       }
       return VIDEO_ENCODER_CODEC_BS_BUFFER_NOT_ENOUGH;
   }

   eRet = jpegEncSetDstBuffer(pMgr->rJPGHandle, (void*)pMgr->rBistreamInfo.pu1WriteAddr, u4AvailableBufferSize);
   if (JPEG_STATUS_OK != eRet)
   {
      return VIDEO_ENCODER_CODEC_ERROR;
   }

   // Start encoding
   ///drv_trace2(TRACE_GROUP_10, MJPGENC_ENCODE, (kal_uint32)pMgr->pu1CodingFrameAddr, (kal_uint32)pMgr->rBistreamInfo.pu1WriteAddr);
   pMgr->fgWaitingCallback = KAL_TRUE;
   eRet = jpegEncStart(pMgr->rJPGHandle);
   if (JPEG_STATUS_OK != eRet)
   {
      return VIDEO_ENCODER_CODEC_ERROR;
   }

   pMgr->eEncState = MJPEG_ENC_READY_2_GET_STREAM;
   return VIDEO_ENCODER_CODEC_ERROR_NONE;
}



VIDEO_ENCODER_CODEC_ERROR_T MJPEGEncGetNextBitstream(kal_uint8 **ppu1BitstreamAddr, VIDEO_ENCODER_PRIVATE_OUTPUT_T *prPrivateOutput)
{
    MJPEG_ENCODER_MGR_T* pMgr = &_rMJPEGEncMgr;
    JPEG_STATUS_ENUM eRet = JPEG_STATUS_CODEC_UNAVAILABLE;

    ///drv_trace1(TRACE_GROUP_10, MJPGENC_FUNC_CALL, MJPEGEncGetNextBitstream_FUNC);
    if (MJPEG_ENC_READY_2_GET_STREAM == pMgr->eEncState)
    {
        // The first time common part call GetNextBitstream
        // Retrive the bitstream information and feedback

        // Wait for codec callback
        kal_retrieve_eg_events(pMgr->rEncodeEvent,
                               EVENT_MJPEG_ENCODING,
                               KAL_OR_CONSUME,
                               &pMgr->u4EncodeEventGroup,
                               KAL_SUSPEND);

      if (JPEG_CODEC_STATE_COMPLETE == pMgr->eCallbackStatus)
      {
          const kal_uint32 u4ContainedSlice = 1;
          const kal_uint32 u4ContainedNoSlice = 0;
          kal_uint8*  pu1NewWp = NULL;
          kal_uint32  u4AvailableBufferSize = 0;

          eRet = jpegEncGetEncodedData(pMgr->rJPGHandle, &prPrivateOutput->pu1BitstreamAddr, &prPrivateOutput->u4BitstreamLength);
          ///drv_trace2(TRACE_GROUP_10, MJPGENC_RETURN_BS, (kal_uint32)prPrivateOutput->pu1BitstreamAddr, prPrivateOutput->u4BitstreamLength);
          if (JPEG_STATUS_OK != eRet)
          {
             return VIDEO_ENCODER_CODEC_ERROR;
          }

          // padded to 8 byte alignment
          prPrivateOutput->u4BitstreamLength = (prPrivateOutput->u4BitstreamLength + (0x7)) & (~0x7);

          pu1NewWp = prPrivateOutput->pu1BitstreamAddr + prPrivateOutput->u4BitstreamLength;

          //The encoded data in sw jpeg would be 4 byte aligned,
          //so that the start addres may not be the same as the startAddr queried from common part
          //return this to commmon part. common part would know there's a vacancy here
          //since prPrivateOutput->pu1BitstreamAddr is different from this one
          *ppu1BitstreamAddr = pMgr->rBistreamInfo.pu1WriteAddr;
          VideoEncoderUpdateBitstreamWP(pu1NewWp, u4ContainedSlice);

          // Query the available buffer size
          VideoEncoderAllocateBitstreamBuffer(&pMgr->rBistreamInfo.pu1StartAddr,
                                              &pMgr->rBistreamInfo.pu1EndAddr,
                                              &pMgr->rBistreamInfo.pu1WriteAddr,
                                              &pMgr->rBistreamInfo.pu1ReadAddr,
                                              &pMgr->rBistreamInfo.u4TotalLength);
                                              //&u4AvailableBufferSize);
          u4AvailableBufferSize = VideoEncoderGetBitstreamBufferAvailableSize();

          // Consume the last piece of bitstream buffer when the size is not enough
          if ((pMgr->u4DstRequiredSize > u4AvailableBufferSize) && ((pMgr->rBistreamInfo.pu1ReadAddr) < (pMgr->rBistreamInfo.pu1WriteAddr)))
          {
             VideoEncoderUpdateBitstreamWP(pMgr->rBistreamInfo.pu1EndAddr, u4ContainedNoSlice);
             ///drv_trace4(TRACE_GROUP_10, MJPGENC_BUFF_NOT_ENOUGH,
             ///           (kal_uint32)pMgr->rBistreamInfo.pu1WriteAddr,
             ///           u4AvailableBufferSize,
             ///           pMgr->u4DstRequiredSize,
             ///           __LINE__);
          }

          prPrivateOutput->fgEndOfFrame = KAL_TRUE;
          prPrivateOutput->eFrameType = VIDEO_CODEC_FRAMETYPE_I;
      }
      else
      {
          ASSERT(0);
      }
    }
    else
    {
        // Otherwise, return NULL to indicate there's no bitstream coded
        *ppu1BitstreamAddr = NULL;

        prPrivateOutput->u4BitstreamLength = 0;
        prPrivateOutput->fgEndOfFrame = KAL_FALSE;
        prPrivateOutput->eFrameType = VIDEO_CODEC_UNKNOWN_TYPE;
    }

    pMgr->eEncState = MJPEG_ENC_READY_2_ENCODE;
    return VIDEO_ENCODER_CODEC_ERROR_NONE;
}



static VIDEO_ENCODER_CODEC_API_T _rMJPEGEncAPI =
{
    MJPEGEncOpenAdapt,
    MJPEGEncInitAdapt,
    MJPEGEncGetParameterAdapt,
    MJPEGEncSetParameterAdapt,
    MJPEGEncGenerateHeader,
    MJPEGEncEncodeOneFrame,
    MJPEGEncDeInitAdapt,
    MJPEGEncCloseAdapt,
    MJPEGEncGetNextBitstream
};



VIDEO_ENCODER_CODEC_API_T* GetMJPEGEncoderHandler(MJPEG_ENC_SCENARIO_T eScenario)
{
    MJPEG_ENCODER_MGR_T* pMgr = &_rMJPEGEncMgr;
    JPEG_STATUS_ENUM eRet = JPEG_STATUS_CODEC_UNAVAILABLE;

    ///drv_trace1(TRACE_GROUP_10, MJPGENC_FUNC_CALL, GetMJPEGEncoderHandler_FUNC);
    if(MJPEG_SCENARIO_UNKNOWN == eScenario)
    {
       ASSERT(0);
    }

    pMgr->eScenario = eScenario;

    // Get JPEG SW handler
    eRet = jpegEncGetEncoder(JPEG_CODEC_TYPE_SW, &pMgr->rJPGHandle);

    if (JPEG_STATUS_OK != eRet)
    {
        ASSERT(0);
    }

    /// Put compiler option to JPEG Codec
    jpegEncSetDynamicQuantAdjustment(pMgr->rJPGHandle, KAL_TRUE);

    eRet = jpegEncSetDstFileFormat(pMgr->rJPGHandle, JPEG_FILE_FORMAT_JPEG);
    if (JPEG_STATUS_OK != eRet)
    {
        ASSERT(0);
    }

    pMgr->eEncState = MJPEG_ENC_CLOSE;
    return &_rMJPEGEncAPI;
}



VIDEO_ENCODER_CODEC_ERROR_T GetMJPEGEncoderType(MJPEG_ENC_TYPE_ENUM *type)
{
   #if defined(__VE_MJPEG_ENC_BYPASS__)
      *type = MJPEG_ENC_TYPE_HW;
   #else
      *type = MJPEG_ENC_TYPE_SW;
   #endif

   return VIDEO_ENCODER_CODEC_ERROR_NONE;
}
#endif /* __MJPEG_ENC_SW_SUPPORT__ */
#endif /* __VIDEO_ARCHI_V2__*/
