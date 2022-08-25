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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * AudioDrain.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Audio drain
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *==============================================================================
 *******************************************************************************/

#include "kal_public_api.h"
#include "kal_trace.h"
#include "l1audio.h"
#include "audio_enum.h"
#include "audio_def.h"
#include "MedAdapt.h"
#include "AudCom.h"
#include "OMX_Types.h"
#include "OMX_Core.h"
#include "OMX_Index.h"
#include "l1sp_trc.h"
#include "AudComUtil.h"
#include "PcmSink.h"
#include "postprocess.h"

#if defined(__BES_TS_SUPPORT__)

static AudComHdl *pBesTS_AudComHdl = NULL;
static kal_uint32 uBesTsCurrentTime = 0;
static BesTSParam BesTS_Param;
static kal_bool bIsCurrentAudioEnableTS = KAL_FALSE;

static void AudioDrain_SetTSParam_Internal()
{
   kal_uint16 uMode = AudioPP_TS_GetSpeed();
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_DRAIN_SET_TS_PARAM, pBesTS_AudComHdl,uMode,0,0,0,0);
   if(pBesTS_AudComHdl)
   {
      BesTS_Param.mode = uMode;
      if(BesTS_Param.mode)
      {
         BesTS_Param.uEnabled = KAL_TRUE;
      }
      pBesTS_AudComHdl->SetParameter(pBesTS_AudComHdl, OMX_IndexParamBesTS, &BesTS_Param);
   }
}

void AudioDrain_SetTSParam()
{
   if(PcmSink_IsAudioRuning())
   {
      AudioDrain_SetTSParam_Internal();
   }
}

void BesTS_SetHandle(AudComHdl *pCurHdl)
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_DRAIN_SET_TS_HANDLE,0,0,0,0,0);
   pBesTS_AudComHdl = pCurHdl;
   uBesTsCurrentTime = 0;
}


void BesTS_SetAudioHandle(AudComHdl *pCurHdl, kal_uint32 uSampleRate, kal_uint32 uChannelNum)
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_DRAIN_SET_TS_HANDLE, pCurHdl,uSampleRate,uChannelNum,0,0,0);
   pBesTS_AudComHdl = pCurHdl;
   BesTS_Param.uChannelNumber = uChannelNum;
   BesTS_Param.uSamplingFreq = uSampleRate;
   BesTS_Param.uEnabled = KAL_FALSE;
   uBesTsCurrentTime = 0;
   AudioDrain_SetTSParam_Internal();
}

void BesTS_FreeAudioHandle()
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_DRAIN_FREE_TS_HANDLE, pBesTS_AudComHdl,0,0,0,0,0);
   pBesTS_AudComHdl = NULL;
   BesTS_Param.uChannelNumber = 0;
   BesTS_Param.uSamplingFreq = 0;
   uBesTsCurrentTime = 0;
}

kal_uint32 AudioDrain_GetCurrentTimeFromTS()
{
   BesTsProcessInfo Param;
   if(pBesTS_AudComHdl && BesTS_Param.uEnabled && PcmSink_IsAudioRuning())
   {
      pBesTS_AudComHdl->SetParameter(pBesTS_AudComHdl, OMX_IndexParamMediaTekGetTSProcessInfo, &Param);
      if( Param.uChannelNumber && Param.uSamplingFreq )
      {
         uBesTsCurrentTime = (kal_uint64)Param.uAccInputSample * 1000  / (Param.uChannelNumber * Param.uSamplingFreq);
      }
	  else
	  {
	     uBesTsCurrentTime = 0;
	  }
   }
   return uBesTsCurrentTime;
}

#else

OMX_U32 BesTS_GetMemSize( void )
{
   return OMX_ErrorNone;
}

OMX_ERRORTYPE BesTS_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
)
{
   return OMX_ErrorNone;
}

#endif

OMX_ERRORTYPE AudioDrain_Check_SR_CH(kal_uint32 uSampleRate, kal_uint32 uChannelNum)
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_DRAIN_CHECK_SR_CH, uSampleRate,uChannelNum,0,0,0);
   if(uChannelNum != 1 && uChannelNum!=2)
   {
      return OMX_ErrorUndefined;
   }
   if(    uSampleRate!=8000  && uSampleRate!=11025 && uSampleRate!=12000  
       && uSampleRate!=16000 && uSampleRate!=22050 && uSampleRate!=24000 
       && uSampleRate!=32000 && uSampleRate!=44100 && uSampleRate!=48000 )
   {
      return OMX_ErrorUndefined;
   }
   return OMX_ErrorNone;
}


OMX_ERRORTYPE AudioDrain_Free(MHPB_Internal *ihdl)
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_DRAIN_FREE, ihdl, 0,0,0,0,0);
#if defined(__BES_TS_SUPPORT__)
   if (ihdl->TSNode.curHdl != NULL)
   {
      ihdl->TSNode.curHdl->Deinit(ihdl->TSNode.curHdl);
      ihdl->TSNode.curHdl = NULL;
      pBesTS_AudComHdl = NULL;
   }
#endif
   if (ihdl->APMNode.curHdl != NULL)
   {
      ihdl->APMNode.curHdl->Deinit(ihdl->APMNode.curHdl);
      ihdl->APMNode.curHdl = NULL;
   }
   if (ihdl->SinkNode.curHdl != NULL)
   {
      ihdl->SinkNode.curHdl->Deinit(ihdl->SinkNode.curHdl);
      ihdl->SinkNode.curHdl = NULL;
   }
   ASSERT(ihdl->pAudioDrainAllocBuf);
   audio_free_mem( (void **) &ihdl->pAudioDrainAllocBuf);
   ihdl->pAudioDrainAllocBuf = NULL;
   
   return OMX_ErrorNone;
}

OMX_ERRORTYPE AudioDrain_Stop(MHPB_Internal *ihdl)
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_DRAIN_STOP, ihdl, 0,0,0,0,0);

   if (ihdl->SinkNode.curHdl != NULL)
   {
      ihdl->SinkNode.curHdl->Stop(ihdl->SinkNode.curHdl);
   }
#if defined(__BES_TS_SUPPORT__)
   if (ihdl->TSNode.curHdl != NULL)
   {
      ihdl->TSNode.curHdl->Stop(ihdl->TSNode.curHdl);
   }
#endif
   if (ihdl->APMNode.curHdl != NULL)
   {
      ihdl->APMNode.curHdl->Stop(ihdl->APMNode.curHdl);
   }

#if defined(__BES_TS_SUPPORT__)
   if (ihdl->TSNode.curHdl != NULL)
   {
      ACU_FlushBufferQueue( (AudComHdl *)ihdl->TSNode.curHdl );
   }
#endif
   if (ihdl->APMNode.curHdl != NULL)
   {
      ACU_FlushBufferQueue( (AudComHdl *)ihdl->APMNode.curHdl );
   }
   if (ihdl->SinkNode.curHdl != NULL)
   {
      ACU_FlushBufferQueue( (AudComHdl *)ihdl->SinkNode.curHdl );   
   }
   
   return OMX_ErrorNone;
}

OMX_ERRORTYPE AudioDrain_Start(MHPB_Internal *ihdl, kal_uint32 uSampleRate, kal_uint32 uChannelNum)
{
   OMX_ERRORTYPE uResult = OMX_ErrorNone;
   SinkParam Sink_param;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_DRAIN_START, ihdl, uSampleRate,uChannelNum,0,0,0);
   
   if( OMX_ErrorNone != AudioDrain_Check_SR_CH(uSampleRate, uChannelNum))
   {
      return OMX_ErrorUndefined;
   }

   Sink_param.uChannelNum   = uChannelNum;
   Sink_param.uSamplingFreq = uSampleRate;

#if !defined(__REMOVE_APM_FOR_LOWPOWER__)
#if defined(__BES_TS_SUPPORT__)
   BesTS_Param.uSamplingFreq = uSampleRate;
   BesTS_Param.uChannelNumber = uChannelNum;
   BesTS_Param.mode = AudioPP_TS_GetSpeed();
   if(BesTS_Param.mode)
   {
      BesTS_Param.uEnabled = KAL_TRUE;
   }
   else
   {
      BesTS_Param.uEnabled = KAL_FALSE;
   }
   uResult = ihdl->TSNode.curHdl->SetParameter(ihdl->TSNode.curHdl, OMX_IndexParamBesTS, &BesTS_Param);
   if(uResult != OMX_ErrorNone)
   {
      return uResult;
   }
   uBesTsCurrentTime = 0;
   uResult = ihdl->TSNode.curHdl->Start(ihdl->TSNode.curHdl);
   if(uResult != OMX_ErrorNone)
   {
      return uResult;
   }
#endif
   uResult = ihdl->APMNode.curHdl->SetParameter(ihdl->APMNode.curHdl, OMX_IndexParamMediaTekAPMParam, &Sink_param);
   if(uResult != OMX_ErrorNone)
   {
      return uResult;
   }
#endif // __REMOVE_APM_FOR_LOWPOWER__

   uResult = ihdl->SinkNode.curHdl->SetParameter(ihdl->SinkNode.curHdl, OMX_IndexParamMediaTekPcmSink, &Sink_param);
   if(uResult != OMX_ErrorNone)
   {
      return uResult;
   }

#if !defined(__REMOVE_APM_FOR_LOWPOWER__)
   uResult = ihdl->APMNode.curHdl->Start(ihdl->APMNode.curHdl);
   if(uResult != OMX_ErrorNone)
   {
      return uResult;
   }
#endif //__REMOVE_APM_FOR_LOWPOWER__

   uResult = ihdl->SinkNode.curHdl->Start(ihdl->SinkNode.curHdl);
   if(uResult != OMX_ErrorNone)
   {
      return uResult;
   }
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_DRAIN_START_SUCCESS, ihdl, uSampleRate,uChannelNum,0,0,0);
   return uResult;
}

AudComHdl* AudioDrain_Init(MHPB_Internal *ihdl, AudComHdl *PrevHdl)
{
   kal_uint32 uBufSize = 0, uMemSizeAPM = 0, uMemSizeSink = 0, uMemSizeTS = 0;
   kal_uint8 *pBuffer;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_DRAIN_INIT, ihdl, PrevHdl,0,0,0,0);

#if !defined(__REMOVE_APM_FOR_LOWPOWER__) 
   uMemSizeAPM  = (APMCom_GetMemSize() + 3) & ~0x3;
#if defined(__BES_TS_SUPPORT__)
   uMemSizeTS = (BesTS_GetMemSize() + 3) & ~0x3;
#endif 
#endif // __REMOVE_APM_FOR_LOWPOWER__
   uMemSizeSink = (PcmSink_GetMemSize() + 3) & ~0x3;

   uBufSize = uMemSizeAPM + uMemSizeSink + uMemSizeTS;
#if !defined(__REMOVE_APM_FOR_LOWPOWER__)
   uBufSize += sizeof(OMX_BUFFERHEADERTYPE) * APM_OUT_BUFNUM; 
   uBufSize += APM_OUT_BUFNUM * APM_OUT_BUFSIZE;
#if defined(__BES_TS_SUPPORT__)
   uBufSize   += sizeof(OMX_BUFFERHEADERTYPE) * BES_TS_BUFNUM; 
   uBufSize   += BES_TS_BUFNUM * BES_TS_BUFSIZE; 
#endif
#endif // __REMOVE_APM_FOR_LOWPOWER__

   ihdl->pAudioDrainAllocBuf = (void *)audio_alloc_mem_cacheable( uBufSize );
   pBuffer = (kal_uint8 *)ihdl->pAudioDrainAllocBuf;
   ASSERT( (((kal_uint32)pBuffer) & 0x3) == 0);
   ASSERT(pBuffer != NULL);
   memset(pBuffer, 0, uBufSize);

#if !defined(__REMOVE_APM_FOR_LOWPOWER__)
#if defined(__BES_TS_SUPPORT__)
      BesTS_Init(&ihdl->TSNode.curHdl, pBuffer, &ihdl->TSNode, &AudComGenCallbacks);
      {
         AudComHdlInt *pIntHdl = (AudComHdlInt *)ihdl->TSNode.curHdl;
         pIntHdl->mhdl = (MHdl *) ihdl;
      }
      ihdl->TSNode.pBuffer = (void *)pBuffer;
      pBesTS_AudComHdl = ihdl->TSNode.curHdl;
      pBuffer += uMemSizeTS;
#endif  //__REMOVE_APM_FOR_LOWPOWER__

      APMCom_Init(&ihdl->APMNode.curHdl, pBuffer, &ihdl->APMNode, &AudComGenCallbacks);
      {
         AudComHdlInt *pIntHdl = (AudComHdlInt *)ihdl->APMNode.curHdl;
         SinkParam Sink_param;
         
         pIntHdl->mhdl = (MHdl *) ihdl;
         Sink_param.uSamplingFreq = 48000;
         Sink_param.uChannelNum = 2;
         ihdl->APMNode.curHdl->SetParameter(ihdl->APMNode.curHdl, OMX_IndexParamMediaTekAPMParam, &Sink_param);
      }
      
      ihdl->APMNode.pBuffer = (void *)pBuffer;
      pBuffer += uMemSizeAPM;
#endif

   PcmSinkGen_Init(&ihdl->SinkNode.curHdl, pBuffer, &ihdl->SinkNode, &AudComGenCallbacks);
   {
      AudComHdlInt *pIntHdl = (AudComHdlInt *)ihdl->SinkNode.curHdl;
      SinkParam Sink_param;
      
      pIntHdl->mhdl = (MHdl *) ihdl;
      Sink_param.uSamplingFreq = 48000;
      Sink_param.uChannelNum = 2;
      ihdl->SinkNode.curHdl->SetParameter(ihdl->SinkNode.curHdl, OMX_IndexParamMediaTekPcmSink, &Sink_param);
   }

   ihdl->SinkNode.pBuffer = (void *)pBuffer;
   pBuffer += uMemSizeSink;

#if !defined(__REMOVE_APM_FOR_LOWPOWER__)
   {
      OMX_BUFFERHEADERTYPE *pBufHdr;
      kal_uint8 *pBufferH;
      int i;
      pBufferH = pBuffer;
      pBuffer += sizeof(OMX_BUFFERHEADERTYPE) * (APM_OUT_BUFNUM);
#if defined(__BES_TS_SUPPORT__)
      pBuffer += sizeof(OMX_BUFFERHEADERTYPE) * (BES_TS_BUFNUM);
#endif      
      for (i=0; i<APM_OUT_BUFNUM; i++) 
      {
         pBufHdr = (OMX_BUFFERHEADERTYPE *)pBufferH;
         pBufferH += sizeof(OMX_BUFFERHEADERTYPE);
           
         pBufHdr->pBuffer = (OMX_U8 *)pBuffer;
         pBufHdr->nAllocLen = APM_OUT_BUFSIZE;
         pBuffer += APM_OUT_BUFSIZE;
         ihdl->APMNode.curHdl->FillThisBuffer(ihdl->APMNode.curHdl, pBufHdr);
      }
#if defined(__BES_TS_SUPPORT__)
      for (i=0; i<BES_TS_BUFNUM; i++) 
      {
         pBufHdr = (OMX_BUFFERHEADERTYPE *)pBufferH;
         pBufferH += sizeof(OMX_BUFFERHEADERTYPE);
           
         pBufHdr->pBuffer = (OMX_U8 *)pBuffer;
         pBufHdr->nAllocLen = BES_TS_BUFSIZE;
         pBuffer += BES_TS_BUFSIZE;
         ihdl->TSNode.curHdl->FillThisBuffer(ihdl->TSNode.curHdl, pBufHdr);
      }
      uBesTsCurrentTime = 0;
#endif
   }  
#endif // __REMOVE_APM_FOR_LOWPOWER__

#if !defined(__REMOVE_APM_FOR_LOWPOWER__)
   ihdl->APMNode.next   = ihdl->SinkNode.curHdl;
   ihdl->SinkNode.prev = ihdl->APMNode.curHdl;
   ihdl->APMNode.prev   = PrevHdl;
#if defined(__BES_TS_SUPPORT__)
   ihdl->TSNode.next   = ihdl->APMNode.curHdl;
   ihdl->APMNode.prev   = ihdl->TSNode.curHdl;
   ihdl->TSNode.prev   = PrevHdl;
#endif
#if defined(__BES_TS_SUPPORT__)
   return ihdl->TSNode.curHdl;
#else
   return ihdl->APMNode.curHdl;
#endif

#else //__REMOVE_APM_FOR_LOWPOWER__
   ihdl->SinkNode.prev = PrevHdl;
   return ihdl->SinkNode.curHdl;
#endif //__REMOVE_APM_FOR_LOWPOWER__
}


OMX_ERRORTYPE AudioRoute2Drain_Free(MHPB_Internal *ihdl)
{
   ihdl->mh.Close( (MHdl *)ihdl );
   
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_ROUTE2DRAIN_FREE, ihdl, 0,0,0,0,0);
   
   return OMX_ErrorNone;
}

OMX_ERRORTYPE AudioRoute2Drain_Stop(MHPB_Internal *ihdl)
{
   ihdl->mh.Stop( (MHdl *)ihdl );
   
   PcmRut_UnregPutComponent(ihdl->SinkNode.curHdl);
   
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_ROUTE2DRAIN_STOP, ihdl, 0,0,0,0,0);
   
   return OMX_ErrorNone;
}

OMX_ERRORTYPE AudioRoute2Drain_Start(MHPB_Internal *ihdl)
{
   SinkParam Sink_param;

   PcmRut_RegPutComponent(ihdl->SinkNode.curHdl);

   ihdl->RouteNode.curHdl->SetParameter(ihdl->RouteNode.curHdl, OMX_IndexParamMediaTekGetPCMInfo, &Sink_param);
   ihdl->APMNode.curHdl->SetParameter(ihdl->APMNode.curHdl, OMX_IndexParamMediaTekSetPCMInfo, &Sink_param);
   ihdl->SinkNode.curHdl->SetParameter(ihdl->SinkNode.curHdl, OMX_IndexParamMediaTekSetPCMInfo, &Sink_param);
   ihdl->SinkNode.curHdl->SetParameter(ihdl->SinkNode.curHdl, OMX_IndexParamMediaTekPcmSinkSkip, NULL);
   
   ihdl->mh.Play( (MHdl *)ihdl );
   
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_ROUTE2DRAIN_START_SUCCESS, ihdl, Sink_param.uSamplingFreq,Sink_param.uChannelNum,0,0,0);
   
   return OMX_ErrorNone;
}



static const MHPB_CompList RouteFuncArray[3] = {
   {PcmRouteSrc_GetMemSize, PcmRouteSrcGen_Init, PCMROUTE_BUFSIZE, PCMROUTE_BUFNUM},
   {APMCom_GetMemSize,      APMCom_Init,         APM_OUT_BUFSIZE,  APM_OUT_BUFNUM},
   {PcmSink_GetMemSize,     PcmSinkGen_Init,     0,                0}
};

OMX_ERRORTYPE AudioRoute2Drain_Init(MHPB_Internal **ihdl, kal_uint16 fc_aud_id)
{
   MHdl *hdl;
   MHPB_Internal *phdl;
   MHPB_CompList const *pArray[4] = {&RouteFuncArray[0], &RouteFuncArray[1], &RouteFuncArray[2], NULL};
   
   hdl = MH_Component_List_Open(NULL, NULL, pArray);
   phdl = (MHPB_Internal *)hdl;
   *ihdl = (MHPB_Internal *)hdl;
   
   memcpy(&phdl->RouteNode, &phdl->NodeArray[0], sizeof(AcHdlNode));
   memcpy(&phdl->APMNode,   &phdl->NodeArray[1], sizeof(AcHdlNode));
   memcpy(&phdl->SinkNode,  &phdl->NodeArray[2], sizeof(AcHdlNode));
      
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_ROUTE2DRAIN_INIT, ihdl, fc_aud_id,0,0,0,0);
   
   return OMX_ErrorUndefined;
}


 
