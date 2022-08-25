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
 *   PcmMixer.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Mix multiple playback audio pcm data.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_public_api.h"
#include "kal_trace.h"
#include "l1audio.h"
#include "audio_enum.h"
#include "audio_def.h"
#include "MedAdapt.h"
#include "AudCom.h"
#include "media.h"
#include "am.h"
#include "afe.h"
#include "l1sp_trc.h"
#include "OMX_Types.h"
#include "OMX_Core.h"
#include "OMX_Index.h"
#include "AudComUtil.h"
#include "PcmSink.h"
#include "PostProcess.h"
#include "PcmMixer.h"
#include "common_def.h"

#if defined(__LOW_COST_SUPPORT_COMMON__)&& (defined(__BT_AUDIO_VIA_SCO__) || defined(__AUD_SW_CODEC__)) 
#include "blisrc_exp.h"    
extern kal_bool Bli_AP_flag;  //1: AP is activate
extern kal_bool Bli_DRV_flag; //1: BLISRC table exsit   
#endif

#if defined(__AUDIO_MIXER_SUPPORT__) 

#pragma arm section code="SECONDARY_ROCODE"

#define MIXER_OUT_CHANNEL_NUMBER 2

static struct {
   AudComHdlInt  *pIntCompHandle[PCM_MIXER_MAX_STREAM_NUMBER];
   kal_uint32    uValidStreamID;
   kal_uint16    uSampleRate;
   kal_bool      fRunning;
} MIXER;

static void pcmmixer_GetReadStream(kal_uint32 uStreamID, kal_int16 **pSrc16, kal_uint32 *uSrcSample)
{
   kal_uint8 *pSrc8;
   kal_uint32 uSrcByte;
   PCM_MixerData *pMixerData = (PCM_MixerData *)MIXER.pIntCompHandle[uStreamID]->pPrivateData;
   if(pMixerData->pSrcHandle)
   {
      rbGetReadBuffer(&pMixerData->PCM, &pSrc8, &uSrcByte);
   }
   else
   {
      ACU_GetReadBuffer((AudComHdl *)MIXER.pIntCompHandle[uStreamID], &pSrc8, &uSrcByte);
   }
   *pSrc16 = (kal_int16 *)pSrc8;
   *uSrcSample = uSrcByte >>1;
}

static void pcmmixer_ReadStreamDone(kal_uint32 uStreamID, kal_uint32 uSrcSample)
{
   AudComHdlInt *pIntCompHandle = MIXER.pIntCompHandle[uStreamID];
   PCM_MixerData *pMixerData = (PCM_MixerData *)pIntCompHandle->pPrivateData;
   if(pMixerData->pSrcHandle)
   {
      rbReadDataDone(&pMixerData->PCM, uSrcSample<<1);
      if(pIntCompHandle->isEOF)
      {
         if(rbGetDataCount(&pMixerData->PCM)<4)
         {
            pIntCompHandle->Decode_EOF = KAL_TRUE;
            pMixerData->fEOF = KAL_TRUE;
         }
      }
   }
   else
   {
      ACU_ReadDataDone((AudComHdl *)pIntCompHandle, uSrcSample<<1);
      if(pIntCompHandle->isEOF)
      {
         pIntCompHandle->Decode_EOF = KAL_TRUE;
         pMixerData->fEOF = KAL_TRUE;
      }
   }
   if(pIntCompHandle->Decode_EOF)
   {
      mhdlException(pIntCompHandle->mhdl, MEDIA_END);
   }
}

static kal_uint32 pcmmixer_GetOneStreamSampleCount(kal_uint32 uStreamID)
{
   kal_uint32 uDataByte;
   AudComHdlInt *pIntCompHandle = MIXER.pIntCompHandle[uStreamID];
   PCM_MixerData *pMixerData = (PCM_MixerData *)pIntCompHandle->pPrivateData;
   if(pMixerData->pSrcHandle)
   {
      if(pIntCompHandle->isEOF)
      {
         uDataByte = 0xFFFFFFFF;
      }
      else
      {
         uDataByte = rbGetDataCount(&pMixerData->PCM);
      }
   }
   else
   {
     if(ACU_PeekIsEOS((AudComHdl *)pIntCompHandle) || pIntCompHandle->isEOF )
     {
        uDataByte = 0xFFFFFFFF;
     }
     else
     {
        uDataByte = ACU_PeekDataCount((AudComHdl *)pIntCompHandle);
     }
   }
   return (uDataByte>>1);
}

static void pcmmixer_Resample(AudComHdlInt *pIntCompHandle)
{
   kal_uint8 *pSrc, *pDst;
   kal_uint32 uSrcByte, uDstByte, uConsumeByte;
   PCM_MixerData *pMixerData = (PCM_MixerData *)pIntCompHandle->pPrivateData;
   while(1)
   {
      ACU_GetReadBuffer((AudComHdl *)pIntCompHandle, &pSrc, &uSrcByte);
      if(uSrcByte < pMixerData->uChannelNumber*2)
      {
         break;
      }
      rbGetWriteBuffer(&pMixerData->PCM, &pDst, &uDstByte);
      if(uDstByte < MIXER_OUT_CHANNEL_NUMBER*2)
      {
         break;
      }
      uConsumeByte = BLI_Convert(pMixerData->pSrcHandle, (short *)pSrc, &uSrcByte, (short *)pDst, &uDstByte); 
      ACU_ReadDataDone((AudComHdl *)pIntCompHandle, uConsumeByte);
      rbWriteDataDone(&pMixerData->PCM, uDstByte);
      if(uConsumeByte == 0 && uDstByte ==0)
      {
         break;
      }
   }
}

static kal_uint32 pcmmixer_AddStream(AudComHdlInt *pIntCompHandle, kal_uint32 uSampleRate, kal_uint32 uChannelNumber)
{
   kal_uint32 uStreamID=0;
   ASSERT(pIntCompHandle);
   for(uStreamID=0;uStreamID<PCM_MIXER_MAX_STREAM_NUMBER;uStreamID++)
   {
      if( !(MIXER.uValidStreamID & (1<<uStreamID)) )
      {
         PCM_MixerData *pMixerData = (PCM_MixerData *)pIntCompHandle->pPrivateData;
         MIXER.pIntCompHandle[uStreamID] = pIntCompHandle;
         if( uSampleRate != MIXER.uSampleRate || uChannelNumber != MIXER_OUT_CHANNEL_NUMBER )
         {
            kal_uint32 uMemSize = 0;
            kal_uint8  *pAllocBuf = NULL;
            BLI_GetMemSize(uSampleRate, uChannelNumber, MIXER.uSampleRate, MIXER_OUT_CHANNEL_NUMBER, &uMemSize);
            uMemSize += PCM_MIXER_BUFFER_SIZE;
            pAllocBuf = (kal_uint8 *)audio_alloc_mem(uMemSize);  
            ASSERT(pAllocBuf);
            pMixerData->PCM.rb_base = pAllocBuf;
            pMixerData->PCM.read = 0;
            pMixerData->PCM.write = 0;
            pMixerData->PCM.rb_size = PCM_MIXER_BUFFER_SIZE;
            pAllocBuf += PCM_MIXER_BUFFER_SIZE;
            pMixerData->pSrcHandle = (void*)BLI_Open(uSampleRate, uChannelNumber, MIXER.uSampleRate, MIXER_OUT_CHANNEL_NUMBER, pAllocBuf, audio_alloc_ext_mem_simplified);
            ASSERT(pMixerData->pSrcHandle);
         }
         MIXER.uValidStreamID |= (1<<uStreamID);
         pMixerData->uPlaySampleRate = MIXER.uSampleRate;
         pMixerData->uPlayedSamples = 0;
         pMixerData->uGain = 0;
         pMixerData->fEOF = KAL_FALSE;
         pMixerData->fRampup = KAL_TRUE;
         pMixerData->fRampdown = KAL_FALSE;
         break;
      }
   }
   return uStreamID;
}

static void pcmmixer_DeleteStream(AudComHdlInt *pIntCompHandle)
{
   kal_uint32 uStreamID=0, I=0;
   PCM_MixerData *pMixerData = (PCM_MixerData *)pIntCompHandle->pPrivateData;
   if(pMixerData->uStreamID == PCM_MIXER_MAX_STREAM_NUMBER)
   {
      return;   
   }
   ASSERT(pIntCompHandle);
   ASSERT( MIXER.pIntCompHandle[pMixerData->uStreamID] == pIntCompHandle);
   pMixerData->fRampup = KAL_FALSE;
   pMixerData->fRampdown = KAL_TRUE;
   PcmMixer_DataRequestCallback();
   while(1)
   {
      I++;
      if(I==PCM_MIXER_STOP_WAIT_TICK || pMixerData->uGain == 0 || pMixerData->fEOF == KAL_TRUE)
      {
         break;
      }
      kal_sleep_task(1);
   }
   MIXER.uValidStreamID &= ~(1<<pMixerData->uStreamID);
   MIXER.pIntCompHandle[pMixerData->uStreamID] = NULL;
   BLI_Close(pMixerData->pSrcHandle, audio_free_ext_mem_simplified);
   audio_free_mem( (void **) &pMixerData->PCM.rb_base);
   pMixerData->pSrcHandle = NULL;
}

static OMX_ERRORTYPE pcmmixer_Start(AudComHdl *pCompHandle)
{
   AudComHdlInt *pIntCompHandle = (AudComHdlInt *)pCompHandle;
   PCM_MixerData *pMixerData = (PCM_MixerData *)pIntCompHandle->pPrivateData;
   pIntCompHandle->isEOF = KAL_FALSE;
   pIntCompHandle->Decode_EOF = KAL_FALSE;
   if(!MIXER.fRunning)
   {
      kal_uint8 uChannelNumber;
      PcmSink_GetCurrentPcmInfo(&MIXER.uSampleRate, &uChannelNumber);
      if(MIXER.uSampleRate == 0)
      {
         MIXER.uSampleRate = PCM_MIXER_DEFAULT_SAMPLE_RATE;
      }
#if defined(__LOW_COST_SUPPORT_COMMON__)&& (defined(__BT_AUDIO_VIA_SCO__) || defined(__AUD_SW_CODEC__)) 
      if(Bli_AP_flag && !Bli_DRV_flag)
      {
         BLI_Open(0, 0, 0, 0, 0, audio_alloc_ext_mem_simplified);
      }
#endif      
   }
   pMixerData->uPlayedSamples = 0;
   pMixerData->uStreamID = pcmmixer_AddStream(pIntCompHandle, pMixerData->uSampleRate, pMixerData->uChannelNumber);
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, MIXER_START, pCompHandle, MIXER.fRunning, pMixerData->uStreamID, pMixerData->uSampleRate, pMixerData->uChannelNumber);
   if(pMixerData->uStreamID == PCM_MIXER_MAX_STREAM_NUMBER)
   {
      return OMX_ErrorInsufficientResources;
   }
   PcmMixer_DataRequestCallback();
   if(!MIXER.fRunning)
   {
      MIXER.fRunning = KAL_TRUE;
      PcmSink_StartSound(PCM_FUNC_MIXER, MIXER.uSampleRate, MIXER_OUT_CHANNEL_NUMBER);
   }
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE pcmmixer_Stop(AudComHdl *pCompHandle)
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, MIXER_STOP, pCompHandle, MIXER.fRunning, MIXER.uValidStreamID);
   if(MIXER.uValidStreamID)
   {
      pcmmixer_DeleteStream((AudComHdlInt *)pCompHandle);
   }
   if(MIXER.uValidStreamID == 0)
   {
      PcmSink_StopSound(PCM_FUNC_MIXER);
      MIXER.fRunning = KAL_FALSE;
   }
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE pcmmixer_Deinit(AudComHdl *pCompHandle)
{
   AudComHdlInt *pIntCompHandle = (AudComHdlInt *)pCompHandle;
   ACU_FlushBufferQueue(pCompHandle);
   L1Audio_FreeAudioID( pIntCompHandle->aud_id );
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE pcmmixer_Process(AudComHdl *pCompHandle)
{
   AudComHdlInt *pIntCompHandle = (AudComHdlInt *)pCompHandle;
   PCM_MixerData *pMixerData = (PCM_MixerData *)pIntCompHandle->pPrivateData;
   if(pIntCompHandle->isEOF)
   {
      return OMX_ErrorNone;
   }
   if(pMixerData->pSrcHandle) 
   {
      pcmmixer_Resample(pIntCompHandle);
   }
}

static OMX_ERRORTYPE pcmmixer_SetParameter(AudComHdl *pCompHandle, OMX_INDEXTYPE index, OMX_PTR pStruct)
{
   AudComHdlInt *pIntCompHandle = (AudComHdlInt *)pCompHandle;
   PCM_MixerData *pMixerData = (PCM_MixerData *)pIntCompHandle->pPrivateData;
   switch (index) 
   {
      case OMX_IndexParamMediaTekSetPCMInfo:
      case OMX_IndexParamMediaTekPcmSink:
      {
         SinkParam *pParam = (SinkParam *)pStruct;
         pMixerData->uSampleRate    = pParam->uSamplingFreq;
         pMixerData->uChannelNumber = pParam->uChannelNum;
         if(  (   pParam->uSamplingFreq!=8000  && pParam->uSamplingFreq!=11025 && pParam->uSamplingFreq!=12000  
               && pParam->uSamplingFreq!=16000 && pParam->uSamplingFreq!=22050 && pParam->uSamplingFreq!=24000 
               && pParam->uSamplingFreq!=32000 && pParam->uSamplingFreq!=44100 && pParam->uSamplingFreq!=48000)
                ||(pParam->uChannelNum != 1 && pParam->uChannelNum != 2))
         {
            return OMX_ErrorBadParameter;
         }
         break;
      }
      case OMX_IndexParamMediaTekGetCurrentTime:
      {
         kal_uint32 *uCurrentTime = (kal_uint32 *)pStruct;
         *uCurrentTime = 0;
         if(pMixerData->uPlaySampleRate)
         {
            *uCurrentTime = (kal_uint32)((kal_uint64)pMixerData->uPlayedSamples * 1000 / (pMixerData->uPlaySampleRate * MIXER_OUT_CHANNEL_NUMBER));
         }
         break;
      }
/*
      case OMX_IndexParamMediaTekSetGain:
      {
         pMixerData->uGain = *((kal_uint16 *)pStruct);
         break;
      }
*/
   }
   return OMX_ErrorNone;
}

kal_bool PcmMixer_IsRunning()
{
   return MIXER.fRunning;
}

void PcmMixer_MixSample(kal_int32 *pMixBuffer, const kal_uint32 uSampleCount)
{
   kal_uint32 uStreamID, I;
   kal_bool fStop = KAL_FALSE;
   for(uStreamID=0 ; uStreamID<PCM_MIXER_MAX_STREAM_NUMBER ; uStreamID++)
   {
      if( MIXER.uValidStreamID & (1<<uStreamID) )
      {
         AudComHdlInt *pIntCompHandle = MIXER.pIntCompHandle[uStreamID];
         PCM_MixerData *pMixerData = (PCM_MixerData *)pIntCompHandle->pPrivateData;
         kal_int32 iGain = (kal_int32)pMixerData->uGain;
         kal_uint32 uRemainSample = uSampleCount;
         kal_int32 *pDst = pMixBuffer;
         while(uRemainSample && !pIntCompHandle->Decode_EOF && !fStop )
         { 
            kal_uint32 uSrcSamples;
            kal_int16  *pSrc;
            kal_int32 iGainStep = 0;
            pcmmixer_GetReadStream(uStreamID, &pSrc, &uSrcSamples);
            if(uSrcSamples > uRemainSample)
            {
               uSrcSamples = uRemainSample;
            }
            else if(uSrcSamples == 0)
            {
               break;
            }
            if(pMixerData->fRampup)
            {
               iGainStep = PCM_MIXER_GAIN_STEP;
            }
            else if(pMixerData->fRampdown)
            {
               iGainStep = -PCM_MIXER_GAIN_STEP;
            }
            if(pMixerData->fEOF)
            {

            }
            else if(iGainStep == 0)
            {
               for(I=0;I<uSrcSamples;I++)
               {
                  kal_int32 iSample = *pDst + *pSrc++;
                  *pDst++ = iSample;
               }
            }
            else
            {
               for(I=0;I<uSrcSamples;I++)
               {
                  kal_int32 iSample = (iGain * (*pSrc++)) >> 15 ;
                  *pDst = iSample + *pDst;
                  pDst++;
                  iGain += iGainStep;
                  if(iGain==0 || iGain==PCM_MIXER_MAX_GAIN)
                  {
                     pMixerData->fRampup = KAL_FALSE;
                     pMixerData->fRampdown = KAL_FALSE;
                     iGainStep = 0;
                     if(iGain == 0)
                     {
                        pMixerData->fEOF = KAL_TRUE;
                        fStop = KAL_TRUE;
                        break;
                     }
                  }
               }
            }
            pcmmixer_ReadStreamDone(uStreamID, uSrcSamples);  
            pMixerData->uPlayedSamples += uSrcSamples;
            uRemainSample -= uSrcSamples;
         }
         pMixerData->uGain = (kal_uint16)iGain;
         if(!pIntCompHandle->Decode_EOF && pIntCompHandle->mhdl && !pIntCompHandle->mhdl->waiting)
         {
            pIntCompHandle->mhdl->waiting = KAL_TRUE;
            mhdlException(pIntCompHandle->mhdl, MEDIA_DATA_REQUEST);
         }
      }
   }
}

kal_uint32 PcmMixer_GetDataCount()
{
   kal_uint32 uSample=0xFFFFFFFF, uStreamID, uCurrentCount;
   for(uStreamID=0 ; uStreamID<PCM_MIXER_MAX_STREAM_NUMBER ; uStreamID++)
   {
      if( MIXER.uValidStreamID & (1<<uStreamID) )
      {
         uCurrentCount = pcmmixer_GetOneStreamSampleCount(uStreamID);
         if(uSample > uCurrentCount)
         {
            uSample = uCurrentCount;
         }
      }
   }
   return uSample;
}

void PcmMixer_DataRequestCallback()
{
   kal_uint32 uStreamID;
   for(uStreamID=0;uStreamID<PCM_MIXER_MAX_STREAM_NUMBER;uStreamID++)
   {
      if(MIXER.uValidStreamID&(1<<uStreamID))
      {
         AudComHdlInt *pIntCompHandle = MIXER.pIntCompHandle[uStreamID];
         PCM_MixerData *pMixerData = (PCM_MixerData *)pIntCompHandle->pPrivateData;
         if(pMixerData->pSrcHandle && !pIntCompHandle->isEOF)
         {
            ACU_SendProcessCommandl(pIntCompHandle);
         }
      }
   }
}

kal_uint32 PcmMixer_GetMemSize( void )
{
   kal_uint32 uHandleSize, uPrivateSize;
   uHandleSize  = (sizeof(AudComHdlInt ) + 3) & ~0x3;
   uPrivateSize = (sizeof(PCM_MixerData) + 3) & ~0x3;
   return uHandleSize + uPrivateSize;
}

OMX_ERRORTYPE PcmMixer_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
)
{
   kal_uint32 uBufSize;
   AudComHdlInt *pIntCompHandle;
   kal_uint8 *pBuffer8;
   
   *pHandle = NULL;
   
   // The buffer address should be 4 bytes aligned
   ASSERT( (((kal_uint32)pBuffer) & 0x3) == 0);
   
   // Empty the memory
   uBufSize = PcmMixer_GetMemSize();
   memset(pBuffer, 0, uBufSize);
   
   // Assign and distribute the memory
   *pHandle = pBuffer;
   pBuffer8 = (kal_uint8 *)pBuffer;
   pIntCompHandle = (AudComHdlInt *)pBuffer;
   pBuffer8 += (sizeof(AudComHdlInt) + 3) & ~0x3;
   // Wrapper of AAC SWIP
   pIntCompHandle->pPrivateData = (void *)pBuffer8;
   
   // Initialize the audio handler as default setting
   ACU_InitHdl(*pHandle, pFWData, pCallback);
   
   // Overwrite the member functions
   pIntCompHandle->basic.Start        = pcmmixer_Start;
   pIntCompHandle->basic.Stop         = pcmmixer_Stop;
   pIntCompHandle->basic.Deinit       = pcmmixer_Deinit;
   pIntCompHandle->basic.SetParameter = pcmmixer_SetParameter;
   pIntCompHandle->basic.Process      = pcmmixer_Process;
   
   // Obtain l1audio service
   pIntCompHandle->aud_id = L1Audio_GetAudioID();
   L1Audio_SetEventHandler( pIntCompHandle->aud_id, mhdlCallbackTask );
   {
      PCM_MixerData *pMixerData = (PCM_MixerData *)pIntCompHandle->pPrivateData;
   }  
   //kal_trace( TRACE_GROUP_PLAYBACK_COMPONENT, L1AUDIO_COM_INIT, MTKAUD_PCMSINK_GEN, pIntCompHandle->aud_id, pIntCompHandle->mediaStatus);
   return OMX_ErrorNone;
}

OMX_ERRORTYPE PcmRender_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
)
{
   PcmMixer_Init(pHandle, pBuffer, pFWData, pCallback);
}

kal_uint32 PcmRender_GetMemSize( void )
{
   return PcmMixer_GetMemSize();
}

#pragma arm section 

#endif

