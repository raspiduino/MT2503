/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *   WavDecoder.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   WAV decoder component
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(__WAV_DECODE_SWIP__)

#include "audio_enum.h"
#include "kal_trace.h"
#include "fsal.h"
#include "l1sp_trc.h"
#include "AudComUtil.h"
#include "WAV_codec.h"
#include "media.h"
#include "common_def.h"
#include "dpmgr.h"

#define WAVDEC_POST_SILENCE_CNT 5

static void wavPageLock( AudComHdl *hdl , kal_bool bLock)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   WAV_DecData *pDecData = (WAV_DecData *)ihdl->pPrivateData;

   if(bLock) //lock
   {
      if(!pDecData->isPageLock)
      {
         DPMGR_Load(DPMGR_WAV);
         pDecData->isPageLock = KAL_TRUE;
      }
   }
   else  //unlock
   {
      if(pDecData->isPageLock)
      { 
         DPMGR_Unload(DPMGR_WAV);
         pDecData->isPageLock = KAL_FALSE;
      }
   }
}


static void WavDec_ApplyGain(kal_int16* pBuf, kal_uint32 ulen, kal_uint8 uGain)
{
   kal_int32 i; 
   kal_uint16 uMaxGain, uCurGain;
   if(uGain >= WAVDEC_MAX_GAIN || ulen == 0)
   {
      return;
   }
   
   uMaxGain = WAVDEC_MAX_GAIN * WAVDEC_MAX_GAIN;
   uCurGain = uGain * uGain;

   for(i=ulen-1 ; i>=0 ; i--)
   {
      kal_int32 iTemp = (kal_int32)(*pBuf) * uCurGain / uMaxGain;
      *pBuf++ = (kal_int16)iTemp;    
   }   
}

static OMX_U32 wavDec_MoveDataFromInputQueue(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   WAV_DecData *pDecData = (WAV_DecData *)ihdl->pPrivateData;
   while (1) 
   {
      OMX_U32 uFileReadLen = 0, data_size = 0;
      OMX_U8 *pBufQueue;
      ACU_GetReadBuffer(hdl, &pBufQueue, &data_size);
      if(NULL == pBufQueue)
         break;

      if((pDecData->uBsBufSize - pDecData->uBsBufDataLen) || (pDecData->uBsBufRead == 0 && pDecData->uBsBufDataLen != pDecData->uBsBufSize) )
      {  
         if(pDecData->uBsBufDataLen && pDecData->uBsBufRead!=0)
         {
            memcpy(pDecData->pBsBuf, pDecData->pBsBuf + pDecData->uBsBufRead, pDecData->uBsBufDataLen);
            uFileReadLen = pDecData->uBsBufSize - pDecData->uBsBufDataLen;
            pDecData->uBsBufRead = 0;
         }
         uFileReadLen = pDecData->uBsBufSize - pDecData->uBsBufDataLen;
         if(uFileReadLen > data_size)
         {
            uFileReadLen = data_size;
         }
         memcpy(pDecData->pBsBuf + pDecData->uBsBufDataLen, pBufQueue, uFileReadLen);
         pDecData->uBsBufDataLen += uFileReadLen;
         pDecData->uBsBufRead = 0;
      }
      else
      {
         break;
      }
      ACU_ReadDataDone(hdl, uFileReadLen);
   }
   return pDecData->uBsBufDataLen;
}


static OMX_ERRORTYPE WavDec_Process(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   WAV_DecData *pDecData = (WAV_DecData *)ihdl->pPrivateData;
   OMX_U32 pcm_buf_size, uOutputSamples, uPrepareLen, uConsumeLen;
   OMX_S32 sBsLen;
   OMX_U8 *pcm_buf;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PROCESS, MTKAUD_DECODER_WAV, ihdl->mediaStatus, ihdl->Decode_EOF, 0,0,0);
   if(ihdl->mediaStatus != COMPONENT_STATE_PLAY)
      return OMX_ErrorNone;

   {
      kal_uint32 uCurrentTime = ihdl->mhdl->GetCurrentTime(ihdl->mhdl);
      if( uCurrentTime >= ihdl->mhdl->stop_time )   
      {
         if(!ihdl->isTimeUP)
         {
            ihdl->isTimeUP = KAL_TRUE;
            mhdlException( ihdl->mhdl, MEDIA_STOP_TIME_UP );
         }
         return OMX_ErrorNone;
      }
   }
   
   while(1)
   {
      OMX_S32 i=0;
      ACU_GetWriteBuffer(hdl, &pcm_buf, &pcm_buf_size);

      if(pcm_buf_size==0 || ihdl->Decode_EOF)
         break;

      if(pDecData->bPostSilence)
      {
         kal_int16 *pSample = (kal_int16*)pcm_buf;
         pDecData->uPostSilenceCnt--;
         if(pDecData->uPostSilenceCnt==0)
         {
            kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_EOF, MTKAUD_DECODER_WAV, 0,0,0,0,0);
            ihdl->Decode_EOF = KAL_TRUE;
            ACU_SetEOS(hdl);
         } 

         if(pDecData->uPostSilenceCnt==0)
         {
            if((pDecData->pDecHdl->channel_num == 1) && (pcm_buf_size >= 768*2)) 
            {
               pcm_buf_size = 768*2; //prevent popup noise
            }
            else if( pcm_buf_size >= 768*2*2 )
            {
               pcm_buf_size = 768*2*2; //prevent popup noise
            }            
         }
         
         for(i=0;i<(pcm_buf_size>>2);i++)
         {
            if(pDecData->uRampDownGain)
            {
               *pSample++ = (kal_int16)((kal_int32)pDecData->iLastSample_L*pDecData->uRampDownGain>>15);
               *pSample++ = (kal_int16)((kal_int32)pDecData->iLastSample_R*pDecData->uRampDownGain>>15);
               pDecData->uRampDownGain -= WAVDEC_RAMPDOWN_SPEED;
            }
            else
            {
               *pSample++ = 0;
               *pSample++ = 0;
            }
         }

         pDecData->uTotalDecSamples += (pcm_buf_size/2) / pDecData->pDecHdl->channel_num;
         ACU_WriteDataDone_ImmediateCallback(hdl, pcm_buf_size);
         break;
      }

      sBsLen = wavDec_MoveDataFromInputQueue(hdl);
      
      if(sBsLen < WAVDEC_BS_SIZE && !ihdl->isEOF ) 
         break;

      if(sBsLen < WAVDEC_BS_SIZE)
      {
         uPrepareLen = pDecData->uBsBufDataLen;
      }
      else
      {
         uPrepareLen = WAVDEC_BS_SIZE;
      }

      uConsumeLen = WAV_Decode(pDecData->pDecHdl, 
                               pDecData->pBsBuf+pDecData->uBsBufRead, 
                               uPrepareLen, 
                               pcm_buf, 
                               &uOutputSamples);
      WavDec_ApplyGain((kal_int16*)pcm_buf, uOutputSamples,pDecData->uGain);
 
      if(uOutputSamples)
      {
         pDecData->iLastSample_L = pDecData->iLastSample_R = *( ((kal_int16*)pcm_buf) + uOutputSamples - 1);
         if(pDecData->pDecHdl->channel_num == 2)
         {
            if(uOutputSamples>1)
            {
               pDecData->iLastSample_L = *(((kal_int16*)pcm_buf) + uOutputSamples - 2);
            }
         }
      }
      
      pDecData->uTotalDecSamples += uOutputSamples / pDecData->pDecHdl->channel_num;

      ASSERT(uPrepareLen >= uConsumeLen);
      ASSERT(pcm_buf_size >= uOutputSamples<<1);

      pDecData->uBsBufDataLen -= uConsumeLen;
      pDecData->uBsBufRead += uConsumeLen;
      kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_DEC_OK, MTKAUD_DECODER_WAV, uConsumeLen,uOutputSamples<<1,0,0,0);
      if (ihdl->isEOF && (pDecData->uBsBufDataLen==0 || uOutputSamples == 0 ) )
      {
         sBsLen -= uConsumeLen;
         if(sBsLen==0 || uConsumeLen==0)
         {
            pDecData->bPostSilence = KAL_TRUE;
            if(!pDecData->bEnableFillSilence)
            {
               pDecData->uPostSilenceCnt = 1;
            }
            ACU_WriteDataDone_ImmediateCallback(hdl, uOutputSamples<<1);
            break;
         }
      }
      if(   (pcm_buf_size*2 >= uOutputSamples<<1)
          &&(  pDecData->pDecHdl->format == WAV_FORMAT_LPCM 
             ||pDecData->pDecHdl->format == WAV_FORMAT_ALAW 
             ||pDecData->pDecHdl->format == WAV_FORMAT_ULAW))
      {
         ACU_WriteDataDone(hdl, uOutputSamples<<1);
      }
      else
      {
         ACU_WriteDataDone_ImmediateCallback(hdl, uOutputSamples<<1);
      }
   }
   return OMX_ErrorNone;
}


/*------------------------------------------------*/
/* The private member functions of Wav decoder.    */
/*------------------------------------------------*/
static OMX_ERRORTYPE WavDec_Start(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   WAV_DecData *pDecData = (WAV_DecData *)ihdl->pPrivateData;

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_START, MTKAUD_DECODER_WAV, ihdl->mediaStatus,0,0,0,0);
  
   {
      //reset data
      ihdl->isTimeUP = KAL_FALSE;
      ihdl->endStatus = MEDIA_NONE;
      ihdl->isEOF = KAL_FALSE;
      ihdl->Decode_EOF = KAL_FALSE;
      pDecData->bPostSilence = KAL_FALSE;
      pDecData->uBsBufRead = 0;
      pDecData->uBsBufDataLen = 0;
      pDecData->uPostSilenceCnt = WAVDEC_POST_SILENCE_CNT;
      pDecData->uTotalDecSamples = 0;
      pDecData->iLastSample_L = 0;
      pDecData->iLastSample_R = 0;
      pDecData->uRampDownGain = WAVDEC_RAMPDOWN_START_GAIN;
   }

   ASSERT(ihdl->mediaStatus != COMPONENT_STATE_PLAY);

   // To execute process function in advance to avoid buffer underflow in the next stage
   ihdl->mediaStatus = COMPONENT_STATE_PLAY;
   wavPageLock( hdl , KAL_TRUE);

   pDecData->uStartTime = PcmSink_GetCurrentTime();
   pDecData->uCurrentTime = pDecData->uStartTime;

   ACU_SendProcessCommandl( (AudComHdlInt *)hdl );
   
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE WavDec_Stop(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   WAV_DecData *pDecData = (WAV_DecData *)ihdl->pPrivateData;
   kal_uint32 uCurrentTime;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_STOP, MTKAUD_DECODER_WAV, ihdl->mediaStatus,ihdl->endStatus,0,0,0);
   if (ihdl->mediaStatus == COMPONENT_STATE_PLAY) 
   {
      ihdl->mediaStatus = COMPONENT_STATE_IDLE;
      ihdl->endStatus = MEDIA_TERMINATED;
   }
   uCurrentTime = PcmSink_GetCurrentTime();
   if(uCurrentTime > pDecData->uCurrentTime )
   {
      pDecData->uCurrentTime = uCurrentTime;
   }
   wavPageLock( hdl , KAL_FALSE);
   return OMX_ErrorNone;
}


static OMX_ERRORTYPE WavDec_SetParameter(AudComHdl *hdl, OMX_INDEXTYPE index, OMX_PTR pStruct)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   WAV_DecData *pDecData = (WAV_DecData *)ihdl->pPrivateData;

   switch(index)
   {
      case OMX_IndexParamAudioPcm:
      {
         break;
      }
      case OMX_IndexParamMediaTekWavDecSWIPHdl:
      {
         WAV_Par2DecInfo *pParam = (WAV_Par2DecInfo *)pStruct;
         pDecData->pDecHdl = pParam->pDecHdl;
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SETPARAM, MTKAUD_DECODER_WAV, 0, pParam->pDecHdl ,0,0,0);
         break;
      }
      case OMX_IndexConfigMelodySetChannelVolume:
      {
         kal_uint8 *uGain = (kal_uint8 *)pStruct;
         pDecData->uGain = *uGain;
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SETPARAM, MTKAUD_DECODER_WAV, 1, pDecData->uGain ,0,0,0,0);
         break;
      }
      case OMX_IndexConfigMelodyGetChannelVolume:
      {
         kal_uint8 *uGain = (kal_uint8 *)pStruct;
         *uGain = pDecData->uGain;
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SETPARAM, MTKAUD_DECODER_WAV, 2, pDecData->uGain,0,0,0,0);
         break;
      }
      case OMX_IndexConfigMelodyGetCurrentTime:
      {
           kal_uint32 *uTime = (kal_uint32 *)pStruct;
           WAV_DecData *pDecData = (WAV_DecData *)ihdl->pPrivateData;
           kal_uint32 uCurrentTime;
           uCurrentTime = PcmSink_GetCurrentTime();
           if(uCurrentTime > pDecData->uCurrentTime )
           {
              pDecData->uCurrentTime = uCurrentTime;
           }
           *uTime = pDecData->uCurrentTime - pDecData->uStartTime;
           kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SETPARAM, MTKAUD_DECODER_WAV, 3, *uTime,0,0,0,0);
         break;
      }
      case OMX_IndexParamMediaTekAddTileSilence:
      {
           WAV_DecData *pDecData = (WAV_DecData *)ihdl->pPrivateData;
           pDecData->bEnableFillSilence = KAL_TRUE;
           kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SETPARAM, MTKAUD_DECODER_WAV, 4, pDecData->bEnableFillSilence,0,0,0,0);
         break;
      }
      default:
         return OMX_ErrorNotImplemented;
   }
   return OMX_ErrorNone;
}

/*------------------------------------------------*/
/* The public functions of WAV Decoder.           */
/*------------------------------------------------*/
OMX_U32 WavDec_GetMemSize( void )
{
   OMX_U32 uTempSize, uReqSizeTotal;
   OMX_U32 uBsBufSize, uPcmBufSize, uWorkBufSize;

   uReqSizeTotal = 0;
  
   // The memory size for AudComHdlInt
   uTempSize = (sizeof(AudComHdlInt) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   
   // The memory for WAV private data
   uTempSize = (sizeof(WAV_DecData) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;

   uBsBufSize     = WAVDEC_BS_BUFFER_SIZE;
   uPcmBufSize    = 0;//(uPcmBufSize    + 3) & ~0x3;
   uWorkBufSize   = 0;//(uWorkBufSize   + 3) & ~0x3;
   uReqSizeTotal += uBsBufSize + uPcmBufSize + uWorkBufSize;

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_GETMEMSIZE, MTKAUD_DECODER_WAV, uReqSizeTotal,0,0,0,0,0);
   return uReqSizeTotal;
   
}

OMX_ERRORTYPE WavDec_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
)
{
   OMX_U32 uBufSize;
   AudComHdlInt *ihdl;
   kal_uint8 *pBuffer8;
   
   *pHandle = NULL;
   // The buffer address should be 4 bytes aligned
   ASSERT( (((kal_uint32)pBuffer) & 0x3) == 0);
   
   // Empty the memory
   uBufSize = WavDec_GetMemSize();
   memset(pBuffer, 0, uBufSize);
   
   // Assign and distribute the memory
   *pHandle = pBuffer;
   pBuffer8 = (kal_uint8 *)pBuffer;
   ihdl = (AudComHdlInt *)pBuffer;
   pBuffer8 += (sizeof(AudComHdlInt) + 3) & ~0x3;
   ihdl->pPrivateData = (void *)pBuffer8;
   ihdl->mediaType = MEDIA_FORMAT_WAV;
   
   // Initialize the audio handler as default setting
   ACU_InitHdl(*pHandle, pFWData, pCallback);
   
   // Overwrite the member functions
   ihdl->basic.Start        = WavDec_Start;
   ihdl->basic.Stop         = WavDec_Stop;
   ihdl->basic.Process      = WavDec_Process;
   ihdl->basic.SetParameter = WavDec_SetParameter;
   ihdl->basic.Deinit       = ACU_GenDeinit;

   {
      WAV_DecData *pDecData = (WAV_DecData *)ihdl->pPrivateData;
      OMX_U32 uDecStructSize;
      kal_uint8 *privatebuf = (kal_uint8 *)ihdl->pPrivateData;
      
      memset(pDecData, 0, sizeof(WAV_DecData));

      uDecStructSize = (sizeof(WAV_DecData) + 3) & ~0x3;
      privatebuf+=uDecStructSize;
      pDecData->pBsBuf = (void *)privatebuf;
      pDecData->uBsBufSize = WAVDEC_BS_BUFFER_SIZE;

      pDecData->uGain = WAVDEC_MAX_GAIN;
   }
   ihdl->mediaStatus = COMPONENT_STATE_READY;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_INIT, MTKAUD_DECODER_WAV, ihdl->mediaStatus,0,0,0,0);
   return OMX_ErrorNone;
}

#endif
