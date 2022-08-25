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
 *   AudCom.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   The adaptation for MED operation. (Internal Use)
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_public_api.h"
#include "kal_trace.h"
#include "fsal.h"
#include "string.h"

#include "l1audio.h"
#include "audio_def.h"
#include "OMX_Core.h"
#include "AudCom.h"
#include "OMX_Types.h"
#include "OMX_Index.h"
#include "ast.h"
#include "MedAdapt.h"
#include "media.h"
#include "audio_enum.h"
#include "l1sp_trc.h"
#include "AudComUtil.h"
#include "postprocess.h"
#include "PcmSource.h"
#include "SphProcess.h"

void DummyHisr_AudioV2( void *data ){}

static OMX_ERRORTYPE AudComGenEmptyBufferDone(
   AudComHdl *hdl,
   void *pFWData,
   OMX_BUFFERHEADERTYPE *pBufHdr)
{
   AcHdlNode *pHdlNode = (AcHdlNode *)pFWData;
   
   pBufHdr->nOffset = 0;
   pBufHdr->nFilledLen = 0;
   
   if (pHdlNode->prev) 
   {
      AudComHdl *pPrevHdl = pHdlNode->prev;
      
      pPrevHdl->FillThisBuffer(pPrevHdl, pBufHdr);
      pPrevHdl->Process(pPrevHdl);
   }
   
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE AudComGenFillBufferDone(
   AudComHdl *hdl,
   void *pFWData,
   OMX_BUFFERHEADERTYPE *pBufHdr)
{
   AcHdlNode *pHdlNode = (AcHdlNode *)pFWData;
   
   if (pHdlNode->next) 
   {
      AudComHdl *pNextHdl = pHdlNode->next;
      
      pNextHdl->EmptyThisBuffer(pNextHdl, pBufHdr);
      pNextHdl->Process(pNextHdl);
   }

   return OMX_ErrorNone;
}

static OMX_ERRORTYPE AudComGenEventHandler(
   AudComHdl *hdl,
   void *pFWData,
   OMX_EVENTTYPE eEvent,
   OMX_U32 nData1,
   OMX_U32 nData2,
   void *pEventData)
{
   if (OMX_EventBufferFlag == eEvent)
   {
      AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
      if(ihdl->mhdl)
      {
         ihdl->mhdl->eof = KAL_TRUE;
      }
   }
   return OMX_ErrorNone;
}

AudComCallback AudComGenCallbacks = {
   AudComGenEventHandler,
   AudComGenEmptyBufferDone,
   AudComGenFillBufferDone
};


//-------------------------------------------------
static Media_Status GenCompPlay( MHdl *hdl )
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   kal_int32 I;
#if defined(__AUDIO_NOT_SUPPORTED__)
   return MEDIA_FAIL;
#endif
   PcmSink_TerminateSound();

   hdl->waiting = KAL_FALSE;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY, hdl->mediaType, hdl->state, 0,0,0,0,0);
   for (I=0; I<ihdl->numComp; I++) 
   {
      ihdl->NodeArray[I].curHdl->Start(ihdl->NodeArray[I].curHdl);
   }
   // Change status
   hdl->state = COMPONENT_STATE_PLAY;
   ihdl->endflag = KAL_FALSE;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_SUCCESS, hdl->mediaType, hdl->state, 0,0,0,0,0);
   return MEDIA_SUCCESS;
}

Media_Status GenCompStop( MHdl *hdl )
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   kal_int32 I,J;
   
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_STOP, hdl->mediaType, hdl->state,0,0,0,0);
   if( hdl->state == COMPONENT_STATE_PAUSE || hdl->state == COMPONENT_STATE_IDLE )
      return MEDIA_SUCCESS;
      
   Media_A2V_REMOVE_MEDIA_END_CALLBACK(GenCompStop);

   // Stop component
   for(I = (ihdl->numComp-1); I>=0; I-- ) 
   {
      ihdl->NodeArray[I].curHdl->Stop(ihdl->NodeArray[I].curHdl);
   }
   for(I = (ihdl->numComp-1); I>=0; I-- ) 
   {
      ACU_FlushBufferQueue( (AudComHdl *)ihdl->NodeArray[I].curHdl );
   }

   ACU_SendEndCommandl( ihdl );
   
   for (J = 0; ; J++) {
      if (ihdl->endflag){
      	 break;
      }
      kal_sleep_task( 1 );
   }

#if defined(__BES_TS_SUPPORT__)
   BesTS_FreeAudioHandle();
#endif

#if defined(__AUDIO_DSP_LOWPOWER_V2__)
  if (ihdl->pstFSAL) {
    if(AUDLP_Check_LowPower_Status())
       AUDLP_Mode(KAL_FALSE, 1);     
  }
#endif
   
   // Change status
   hdl->state = COMPONENT_STATE_IDLE;
   
   if (ihdl->region != DPMGR_NOT_MATCH) {
      // Unload code
      DPMGR_Unload(ihdl->region);
      ihdl->region = DPMGR_NOT_MATCH;
   }
   
   hdl->rbInfo.write = 0;
   hdl->rbInfo.read = 0;

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_STOP_FINISH, hdl->mediaType, hdl->state, 0,0,0,0,0);
   return MEDIA_SUCCESS;
}

static Media_Status GenCompPause( MHdl *hdl )
{
   ASSERT( hdl->state == COMPONENT_STATE_PLAY );
   hdl->Stop(hdl);
   hdl->bIsPause = KAL_TRUE; 
   hdl->start_time = hdl->current_time;
   hdl->state = COMPONENT_STATE_PAUSE;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PAUSE, hdl->mediaType, hdl->start_time,0,0,0,0,0);
   return MEDIA_SUCCESS;
}

static Media_Status GenCompResume( MHdl *hdl )
{
   ASSERT(hdl->state == COMPONENT_STATE_PAUSE);
   hdl->state = COMPONENT_STATE_IDLE;
   
   if (hdl->Play)
      return hdl->Play(hdl);
   else
      return hdl->Record(hdl);
}


static Media_Status GenCompClose( MHdl *hdl )
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   kal_int32 I;

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_CLOSE, hdl->mediaType, hdl, hdl->state,0,0,0,0,0);
   ASSERT( hdl != 0 );
   if(hdl->state == COMPONENT_STATE_PLAY)
   {
      hdl->Stop(hdl);
   }

   // Deinit component
   for (I=ihdl->numComp-1; I>=0; I--) 
   {
      ihdl->NodeArray[I].curHdl->Deinit(ihdl->NodeArray[I].curHdl);
   }
   
   // Wav only
   if (ihdl->pPublicInfo) {
      free_ctrl_buffer( ihdl->pPublicInfo );
   }
   
   // Free memory
   if (ihdl->pAllocBuf) {
      if (ihdl->fIspAllocBufOnMED) {
         audio_free_mem( (void **) &ihdl->pAllocBuf);
      } else {
         free_ctrl_buffer(ihdl->pAllocBuf);
         ihdl->pAllocBuf = NULL;
      }
   }
   mhdlFinalize(hdl, NULL);
   free_ctrl_buffer( hdl );
   return MEDIA_SUCCESS;
}

static Media_Event GenCompProcess( MHdl *hdl, Media_Event event )
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PROCESS, hdl->mediaType, hdl, event, hdl->state, hdl->eof,0,0,0);
   switch(event) {
      case MEDIA_END:
      case MEDIA_STOP_TIME_UP:
         Media_A2V_NOTIFY_MEDIA_END(hdl->Stop, hdl);
         break;
      case MEDIA_ERROR:
         hdl->Stop(hdl);
         break;
      case MEDIA_DATA_REQUEST:
         
         return MEDIA_NONE;
      default:
         // should never reach here
         ASSERT(0);
   }
   
   //return MEDIA_NONE;
   
   return event;
}

/*------------------------------------------------*/
/* To obtain the handle for component list.       */
/*------------------------------------------------*/
static MHdl *MH_Component_Construct(MHPB_CompList const *pFunc[])
{
   MHdl *hdl;
   MHPB_Internal *ihdl;
   MHPB_CompList const *pFuncCurr;
   kal_uint8 *pBuffer = NULL;
   OMX_U32 uMemSizeTotal, uMemSizeCurrent;
   OMX_ERRORTYPE result;
   kal_uint32 I;
   
   ASSERT(pFunc != NULL);
  
   ihdl = (MHPB_Internal *)get_ctrl_buffer( sizeof(MHPB_Internal) );
   memset(ihdl, 0, sizeof(MHPB_Internal));
   hdl = (MHdl *) ihdl;
   mhdlInitEx( hdl, 0, NULL );

   //-- Use two pass to calculate 
   // Pass 1: To calaulate the total size
   
   uMemSizeTotal = 0;
   I = 0;
   while (pFunc[I] != NULL) {
      pFuncCurr = pFunc[I];
      ASSERT(I < MAX_COMPONENT_LIST_SIZE);
      uMemSizeCurrent = pFuncCurr->GetMemSize();
      uMemSizeTotal += uMemSizeCurrent;
      uMemSizeTotal += (sizeof(OMX_BUFFERHEADERTYPE) + pFuncCurr->OutputBufferSize) * pFuncCurr->OutputBufferNum;
      I++;
   }
   ihdl->numComp = I;
   
   // Allocate memory
   if (uMemSizeTotal) {
      if (uMemSizeTotal > 2048) {
         pBuffer = (kal_uint8 *)audio_alloc_mem_cacheable(uMemSizeTotal);
         ihdl->fIspAllocBufOnMED = KAL_TRUE;
      } else {
         pBuffer = (kal_uint8 *)get_ctrl_buffer( uMemSizeTotal );
      }
      ihdl->pAllocBuf = pBuffer;
      ASSERT(pBuffer != NULL);
      memset(pBuffer, 0, uMemSizeTotal);
      kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_ALLOC_MEM, ihdl->pAllocBuf, hdl->mediaType, uMemSizeTotal,0,0,0,0);
   }
   
   // Pass 2: Assign buffer and initialize
   
   I = 0;
   while (pFunc[I] != NULL) {
      AudComHdlInt *pIntHdl;
      int K;
      
      pFuncCurr = pFunc[I];
      uMemSizeCurrent = pFuncCurr->GetMemSize();
      result = pFuncCurr->Init(&ihdl->NodeArray[I].curHdl, pBuffer, &ihdl->NodeArray[I], &AudComGenCallbacks);
      ASSERT(result == OMX_ErrorNone);
      
      pIntHdl = (AudComHdlInt *)ihdl->NodeArray[I].curHdl;
      pIntHdl->mhdl = hdl;
      pBuffer += uMemSizeCurrent;
      
      // Assign to parser output
      for (K=0; K<pFuncCurr->OutputBufferNum; K++) {
         OMX_BUFFERHEADERTYPE *pBufHdr;
         
         pBufHdr = (OMX_BUFFERHEADERTYPE *)pBuffer;
         pBuffer += sizeof(OMX_BUFFERHEADERTYPE);
         
         pBufHdr->pBuffer = (OMX_U8 *)pBuffer;
         pBufHdr->nAllocLen = pFuncCurr->OutputBufferSize;
         pBuffer += pFuncCurr->OutputBufferSize;
         
         ihdl->NodeArray[I].curHdl->FillThisBuffer(ihdl->NodeArray[I].curHdl, pBufHdr);
      }
      
      I++;
   }
   
   // Arrange the linked list
   for (I=0; I<ihdl->numComp; I++) {
      // link to next
      if (I < ihdl->numComp-1) {
         ihdl->NodeArray[I].next = ihdl->NodeArray[I+1].curHdl;
         ihdl->NodeArray[I].pNextNode = &ihdl->NodeArray[I+1];
      }
      
      // link to previous
      if (I > 0) {
         ihdl->NodeArray[I].prev = ihdl->NodeArray[I-1].curHdl;
         ihdl->NodeArray[I].pPrevNode = &ihdl->NodeArray[I-1];
      }

#if defined(__AUDIO_RECORD_DYNAMIC_HOOK_SUPPORT__)
      ihdl->fNodeUsed[I] = KAL_TRUE;
#endif
   }
   
   return hdl;
}

MHdl *MH_Component_List_Open(
   void(*handler)( MHdl *handle, Media_Event event ),
   STFSAL *pstFSAL,
   MHPB_CompList const *pFunc[])
{
   MHdl *hdl;
   MHPB_Internal *ihdl;

   hdl = MH_Component_Construct(pFunc);
   ihdl = (MHPB_Internal *)hdl;
   
   hdl->handler = handler;
   // File handle
   ihdl->pstFSAL = pstFSAL;
   FSAL_GetFileSize(pstFSAL, &ihdl->uFileSize);
   
   // KH 20100818 need revise
   hdl->Play    = GenCompPlay;
   hdl->Pause   = GenCompPause;
   hdl->Resume  = GenCompResume;
   hdl->Stop    = GenCompStop;
   hdl->Close   = GenCompClose;
   hdl->Process = GenCompProcess;
   
   if (ihdl->numComp) {
      AcuFileParam parseInfo;
      
      parseInfo.pstFSAL = pstFSAL;
      parseInfo.pFileInfo = hdl->pFileInfo;
      ihdl->NodeArray[0].curHdl->SetParameter(ihdl->NodeArray[0].curHdl, OMX_IndexParamMedFileHandle, &parseInfo);
   }
   
   hdl->state = COMPONENT_STATE_IDLE;
   
   return hdl;
}

#if defined(__BES_TS_SUPPORT__)
static const MHPB_CompList TsFuncArray = {
   BesTS_GetMemSize, BesTS_Init, BES_TS_BUFSIZE, BES_TS_BUFNUM
};
#endif

#if !defined(__REMOVE_APM_FOR_LOWPOWER__)
static const MHPB_CompList ApmFuncArray = {
   APMCom_GetMemSize, APMCom_Init, APM_OUT_BUFSIZE, APM_OUT_BUFNUM
};
#endif

static const MHPB_CompList SinkFuncArray = {
   PcmSink_GetMemSize, PcmSinkGen_Init, 0, 0
};

MHdl *MH_Component_Open(
   void(*handler)( MHdl *handle, Media_Event event ),
   STFSAL *pstFSAL,
   MHPB_CompList const *pParFunc,
   MHPB_CompList const *pDecFunc)
{
   MHdl *hdl;
   MHPB_Internal *ihdl;
   MHPB_CompList const *pArray[6];
   int I = 0;
   
   pArray[I++] = pParFunc;
   if (pDecFunc) {
      pArray[I++] = pDecFunc;
   }
#if defined(__BES_TS_SUPPORT__)
   pArray[I++] = &TsFuncArray;
#endif
#if !defined(__REMOVE_APM_FOR_LOWPOWER__)
   pArray[I++] = &ApmFuncArray;
#endif
   pArray[I++] = &SinkFuncArray;
   pArray[I] = NULL;

   hdl = MH_Component_List_Open(handler, pstFSAL, pArray);
   ihdl = (MHPB_Internal *)hdl;
   
   // Alias. Will be remove later
   I = 0;
   memcpy(&ihdl->ParNode,  &ihdl->NodeArray[I++], sizeof(AcHdlNode));
   if (pDecFunc) {
      memcpy(&ihdl->DecNode,  &ihdl->NodeArray[I++], sizeof(AcHdlNode));
   }
#if defined(__BES_TS_SUPPORT__)
   BesTS_SetHandle(ihdl->NodeArray[I].curHdl);
   memcpy(&ihdl->TSNode,   &ihdl->NodeArray[I++], sizeof(AcHdlNode));
#endif
#if !defined(__REMOVE_APM_FOR_LOWPOWER__)
   memcpy(&ihdl->APMNode,  &ihdl->NodeArray[I++], sizeof(AcHdlNode));
#endif
   memcpy(&ihdl->SinkNode, &ihdl->NodeArray[I++], sizeof(AcHdlNode));
   
   return hdl;
}

void MH_FlushPostProcess(AudComHdl *hdlSink)
{
   AudComHdlInt *ihdlSink = (AudComHdlInt *)hdlSink;
   MHPB_Internal *ihdl = (MHPB_Internal *)ihdlSink->mhdl;
   
#if defined(__BES_TS_SUPPORT__)
   if (ihdl->TSNode.curHdl) {
      ACU_FlushBufferQueue( ihdl->TSNode.curHdl );
      ihdl->TSNode.curHdl->SetParameter(ihdl->TSNode.curHdl, OMX_IndexParamMediaTekResetTSVariable, NULL);
   }
#endif
#if !defined(__REMOVE_APM_FOR_LOWPOWER__)
   if (ihdl->APMNode.curHdl)
      ACU_FlushBufferQueue( ihdl->APMNode.curHdl );
#endif
   ACU_FlushBufferQueue( ihdl->SinkNode.curHdl );
}

void MH_RegPutComponent(AudComHdl *hdlDec)
{
   AudComHdlInt *ihdlDec = (AudComHdlInt *)hdlDec;
   MHPB_Internal *ihdl = (MHPB_Internal *)ihdlDec->mhdl;
   
   PcmRut_RegPutComponent(ihdl->SinkNode.curHdl);
}

void MH_UnregPutComponent(AudComHdl *hdlDec)
{
   AudComHdlInt *ihdlDec = (AudComHdlInt *)hdlDec;
   MHPB_Internal *ihdl = (MHPB_Internal *)ihdlDec->mhdl;
   
   PcmRut_UnregPutComponent(ihdl->SinkNode.curHdl);
}

/*------------------------------------------------*/
/* Recording related part.                        */
/*------------------------------------------------*/

#if defined(__AUDIO_RECORD_COMPONENT_SUPPORT__)

static const MHPB_CompList PcmSourceFunc = {
   PcmSrc_GetMemSize, PcmSrc_Init, PCM_SOURCE_BUFSIZE, PCM_SOURCE_BUFNUM
};

static const MHPB_CompList SampleRateConvertFunc = {
   SRC_GetMemSize, SRC_Init, SRC_BUFSIZE, SRC_BUFNUM
};

#if defined(__SPEECH_ENHENCEMENT_SWIP_SUPPORT__)
static const MHPB_CompList SpeechEnhanceFunc = {
   SphEnh_GetMemSize, SphEnh_Init, SPH_ENH_BUFSIZE, SPH_ENH_BUFNUM
};
#endif

const MHPB_CompList DirectPackFunc = {
   PcmPack_GetMemSize, PcmPack_Init, 0, 0
};

static kal_uint32 SwDecision(void)
{
   return (COMPONENT_SOURCE_REQUIRED + COMPONENT_ENHANCEMENT_REQUIRED);
}

static kal_uint32 DspDecision(void)
{
   return COMPONENT_ENCODER_DSP_REQUIRED;
}

/*------------------------------------------------*/
/* Support dynamic hook.                          */
/*------------------------------------------------*/
static AcHdlNode *HookAndConstructComponent(
   MHPB_Internal *ihdl,
   AcHdlNode *pPrevNode,
   AcHdlNode *pNextNode,
   MHPB_CompList const *pFunc)
{
   kal_int32 I, K;
   AcHdlNode *pCurNode;
   OMX_U32 uMemSizeTotal, uMemSizeCurrent;
   kal_uint8 *pBuffer = NULL;
   OMX_ERRORTYPE result;
   
   // To select a unused node
   for (I=0; I<MAX_COMPONENT_LIST_SIZE; I++) {
      if (ihdl->fNodeUsed[I] == KAL_FALSE)
         break;
   }
   ASSERT(I < MAX_COMPONENT_LIST_SIZE);
   
   // Mark as used
   pCurNode = &ihdl->NodeArray[I];
   memset(pCurNode, 0, sizeof(AcHdlNode));
   ihdl->fNodeUsed[I] = KAL_TRUE;
   ihdl->numComp++;
   
   // Construct
   uMemSizeCurrent = uMemSizeTotal = pFunc->GetMemSize();
   uMemSizeTotal += (sizeof(OMX_BUFFERHEADERTYPE) + pFunc->OutputBufferSize) * pFunc->OutputBufferNum;
   pBuffer = (kal_uint8 *)audio_alloc_mem_cacheable(uMemSizeTotal);
   pCurNode->pAllocBuf = pBuffer;
   result = pFunc->Init(&pCurNode->curHdl, pBuffer, pCurNode, &AudComGenCallbacks);
   ASSERT(result == OMX_ErrorNone);

   pBuffer += uMemSizeCurrent;
   
   for (K=0; K<pFunc->OutputBufferNum; K++) {
      OMX_BUFFERHEADERTYPE *pBufHdr;
      
      pBufHdr = (OMX_BUFFERHEADERTYPE *)pBuffer;
      pBuffer += sizeof(OMX_BUFFERHEADERTYPE);
      
      pBufHdr->pBuffer = (OMX_U8 *)pBuffer;
      pBufHdr->nAllocLen = pFunc->OutputBufferSize;
      pBuffer += pFunc->OutputBufferSize;
      
      pCurNode->curHdl->FillThisBuffer(pCurNode->curHdl, pBufHdr);
   }
   
   // Adjust linked list
   if (pNextNode) {
      pCurNode->next = pNextNode->curHdl;
      pNextNode->prev = pCurNode->curHdl;
      pCurNode->pNextNode = pNextNode;
      pNextNode->pPrevNode = pCurNode;
   } else {
      ihdl->pNodeEnd = pCurNode;
   }
   if (pPrevNode) {
      pCurNode->prev = pPrevNode->curHdl;
      pPrevNode->next = pCurNode->curHdl;
      pCurNode->pPrevNode = pPrevNode;
      pPrevNode->pNextNode = pCurNode;
   } else {
      ihdl->pNodeStart = pCurNode;
   }
   
   return pCurNode;
}

static void UnhookAndDeconstructComponent(
   MHPB_Internal *ihdl,
   AcHdlNode **pNode)
{
   kal_int32 I;
   AcHdlNode *pPrevNode, *pNextNode, *pCurNode;
   
   // To check node
   pCurNode = *pNode;
   for (I=0; I<MAX_COMPONENT_LIST_SIZE; I++) {
      if (pCurNode == &ihdl->NodeArray[I])
         break;
   }
   ASSERT(I < MAX_COMPONENT_LIST_SIZE);
   ASSERT( ihdl->fNodeUsed[I] );
   
   // Deconstruct
   pCurNode->curHdl->Deinit(pCurNode->curHdl);
   audio_free_mem( (void **) &pCurNode->pAllocBuf);
   
   // Adjust linked list
   pPrevNode = pCurNode->pPrevNode;
   pNextNode = pCurNode->pNextNode;
   if (pNextNode) {
      if (pPrevNode)
         pNextNode->prev = pPrevNode->curHdl;
      else
         pNextNode->prev = NULL;
      pNextNode->pPrevNode = pPrevNode;
   } else {
      ihdl->pNodeEnd = pPrevNode;
   }
   if (pPrevNode) {
      if (pNextNode)
         pPrevNode->next = pNextNode->curHdl;
      else
         pPrevNode->next = NULL;
      pPrevNode->pNextNode = pNextNode;
   } else {
      ihdl->pNodeStart = pNextNode;
   }
   
   // Mark as unused
   ihdl->fNodeUsed[I] = KAL_FALSE;
   ihdl->numComp--;
   *pNode = NULL;
}

static Media_Status GenCompRecord( MHdl *hdl )
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   
   hdl->waiting = KAL_FALSE;

   // Backward
   {
      AcHdlNode *pNode = ihdl->pNodeEnd;
      
      while (pNode) {
         pNode->curHdl->Start( pNode->curHdl );
         pNode = pNode->pPrevNode;
      }
   }

   // Change status
   hdl->state = COMPONENT_STATE_RECORD;
   ihdl->endflag = KAL_FALSE;

   return MEDIA_SUCCESS;
}

static Media_Status GenCompRecPause( MHdl *hdl )
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   kal_int32 J;
   
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_STOP, hdl->mediaType, hdl->state,0,0,0,0);
   if( hdl->state == COMPONENT_STATE_PAUSE || hdl->state == COMPONENT_STATE_IDLE )
      return MEDIA_SUCCESS;

   // Stop component
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
   {
      AcHdlNode *pNode = ihdl->pNodeStart;
      kal_uint8 *pWrite;
      kal_uint32 uWriteLen;
      
      while (pNode) {
         // Stop the component
         pNode->curHdl->Stop( pNode->curHdl );
         
         // Flush: Push to next component
         ACU_GetWriteBuffer(pNode->curHdl, &pWrite, &uWriteLen);
         if (uWriteLen)
            ACU_WriteDataDone_ImmediateCallback(pNode->curHdl, 0);
         
         pNode = pNode->pNextNode;
      }
   }

   ACU_SendEndCommandl( ihdl );
   
   for (J = 0; ; J++) {
      if (ihdl->endflag){
      	 break;
      }
      kal_sleep_task( 1 );
   }
#endif

   // Change status
   hdl->state = COMPONENT_STATE_PAUSE;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_STOP_FINISH, hdl->mediaType, hdl->state, 0,0,0,0,0);
   return MEDIA_SUCCESS;
}

static Media_Status GenCompRecResume( MHdl *hdl )
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;

   ASSERT(hdl->state == COMPONENT_STATE_PAUSE);
   hdl->state = COMPONENT_STATE_IDLE;
   
   hdl->waiting = KAL_FALSE;

   // Re-configure
   {
      kal_uint32 uEncDecision = 0;
      
      uEncDecision = ihdl->EncDecision();
      {
         MHPB_CompList const *pEncFunc;
         kal_bool fReHookEncode = KAL_FALSE;
         
         if (uEncDecision & COMPONENT_ENCODER_DSP_REQUIRED) {
            pEncFunc = ihdl->pDspEncFunc;
            if ( !ihdl->fDspEncode ) {
               UnhookAndDeconstructComponent(ihdl, &ihdl->pNodeEncode);
               fReHookEncode = KAL_TRUE;
            }
            ihdl->fDspEncode = KAL_TRUE;
         } else {
            pEncFunc = ihdl->pSwEncFunc;
            if ( ihdl->fDspEncode ) {
               UnhookAndDeconstructComponent(ihdl, &ihdl->pNodeEncode);
               fReHookEncode = KAL_TRUE;
            }
            ihdl->fDspEncode = KAL_FALSE;
         }
         if (fReHookEncode)
            ihdl->pNodeEncode = HookAndConstructComponent(ihdl, NULL, ihdl->pNodePack, pEncFunc);
      }
   
      if (uEncDecision & COMPONENT_SOURCE_REQUIRED) {
         SrcCapParam stCap;
         
         //-- Consturct source component
         if ( ihdl->pNodeSource == NULL )
            ihdl->pNodeSource = HookAndConstructComponent(ihdl, NULL, ihdl->pNodeEncode, &PcmSourceFunc);
         
         //-- Negotiation information
         // Get the capability of Encoder
         Pcmsrc_ConvertEncCapability(&ihdl->stFormat, &stCap);
         
         // Negotiate with Sourcer
         ihdl->pNodeSource->curHdl->SetParameter(ihdl->pNodeSource->curHdl, OMX_IndexParamMediaTekPcmSourceNegotiation, (OMX_PTR) &stCap);
         
         // Set the negotiated information to encoder
         ihdl->pNodeEncode->curHdl->SetParameter(ihdl->pNodeEncode->curHdl, OMX_IndexParamMediaTekSetEncodeFormat, (OMX_PTR) &stCap);
         
         //-- SRC (Sampling Rate Convert) part
         // Get the sampling rate and channel number of source and encoder
         ihdl->pNodeSource->curHdl->SetParameter(ihdl->pNodeSource->curHdl, OMX_IndexParamMediaTekQuerySetPcmSourceInfo, (OMX_PTR) &ihdl->stFormat);
         
         if (ihdl->pNodeSRC)
            UnhookAndDeconstructComponent(ihdl, &ihdl->pNodeSRC);
            
         if ( (ihdl->stFormat.uOriChannelNum != ihdl->stFormat.uOutputChannelNum) || (ihdl->stFormat.uOriSamplingFreq != ihdl->stFormat.uOutputSamplingFreq) ) {
            //-- Hook SRC (Sampling Rate Convert)
            
            // Construct and set alias
            ihdl->pNodeSRC = HookAndConstructComponent(ihdl, ihdl->pNodeSource, ihdl->pNodeEncode, &SampleRateConvertFunc);
            
            // Set sampling rate and channel number information
            ihdl->pNodeSRC->curHdl->SetParameter(ihdl->pNodeSRC->curHdl, OMX_IndexParamMediaTekQuerySetPcmSourceInfo, (OMX_PTR) &ihdl->stFormat);
         }
#if defined(__SPEECH_ENHENCEMENT_SWIP_SUPPORT__)
         if (ihdl->pNodeSphEnh)
            UnhookAndDeconstructComponent(ihdl, &ihdl->pNodeSphEnh);
         
         if ( isNeedSphEnh() ) {
            //-- Hook speech enhancement
            AcHdlNode *pNext;
            
            if (ihdl->pNodeSRC)
               pNext = ihdl->pNodeSRC;
            else
               pNext = ihdl->pNodeEncode;
            
            // Construct and set alias
            ihdl->pNodeSphEnh = HookAndConstructComponent(ihdl, ihdl->pNodeSource, ipNext, &SpeechEnhanceFunc);
            
            // Set sampling rate and channel number information
            ihdl->pNodeSphEnh->curHdl->SetParameter(ihdl->pNodeSphEnh->curHdl, OMX_IndexParamMediaTekQuerySetPcmSourceInfo, (OMX_PTR) &ihdl->stFormat);
         }
#endif
      } else {
         // Don't need source component
         if (ihdl->pNodeSource)
            UnhookAndDeconstructComponent(ihdl, &ihdl->pNodeSource);
      }
   }
   
   {
      AcHdlNode *pNode = ihdl->pNodeEnd;
      
      while (pNode) {
         pNode->curHdl->Start( pNode->curHdl );
         ACU_SendProcessCommandl( (AudComHdlInt *)pNode->curHdl );
         pNode = pNode->pPrevNode;
      }
   }

   // Change status
   hdl->state = COMPONENT_STATE_PLAY;
   ihdl->endflag = KAL_FALSE;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_SUCCESS, hdl->mediaType, hdl->state, 0,0,0,0,0);
   return MEDIA_SUCCESS;
}

static Media_Status GenCompRecStop( MHdl *hdl )
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   kal_int32 J;
   
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_STOP, hdl->mediaType, hdl->state,0,0,0,0);
   if( hdl->state == COMPONENT_STATE_PAUSE || hdl->state == COMPONENT_STATE_IDLE )
      return MEDIA_SUCCESS;

   {
      AcHdlNode *pNode = ihdl->pNodeStart;
      kal_uint8 *pWrite;
      kal_uint32 uWriteLen;
      
      while (pNode) {
         for (J=4; J>=0; J--) {
            ACU_SendProcessCommandl( (AudComHdlInt *)pNode->curHdl );
         }
         pNode->curHdl->Stop( pNode->curHdl );
         
         // Flush: Push to next component
         ACU_GetWriteBuffer(pNode->curHdl, &pWrite, &uWriteLen);
         if (uWriteLen)
            ACU_WriteDataDone_ImmediateCallback(pNode->curHdl, 0);
         
         pNode = pNode->pNextNode;
      }
      pNode = ihdl->pNodeEnd;
      while (pNode) {
         ACU_FlushBufferQueue( pNode->curHdl );
         pNode = pNode->pPrevNode;
      }
   }

   ACU_SendEndCommandl( ihdl );
   
   for (J = 0; ; J++) {
      if (ihdl->endflag){
      	 break;
      }
      kal_sleep_task( 1 );
   }
      
   // Change status
   hdl->state = COMPONENT_STATE_IDLE;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_STOP_FINISH, hdl->mediaType, hdl->state, 0,0,0,0,0);
   
   return MEDIA_SUCCESS;
}

static Media_Status GenCompRecClose( MHdl *hdl )
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_CLOSE, hdl->mediaType, hdl, hdl->state,0,0,0,0,0);
   
   ASSERT( hdl != 0 );
   if (hdl->state == COMPONENT_STATE_PLAY) {
      hdl->Stop(hdl);
   }
   
   // Deinit component
   {
      AcHdlNode *pNode = ihdl->pNodeStart;
      
      while (pNode) {
         pNode->curHdl->Deinit( pNode->curHdl );
         if (pNode->pAllocBuf) {
            audio_free_mem( (void **) &pNode->pAllocBuf);
         }
         pNode = pNode->pNextNode;
      }
   }

   // Wav only
   if (ihdl->pPublicInfo) {
      free_ctrl_buffer( ihdl->pPublicInfo );
   }
   
   // Free memory
   if (ihdl->pAllocBuf) {
      if (ihdl->fIspAllocBufOnMED) {
         audio_free_mem( (void **) &ihdl->pAllocBuf);
      } else {
         free_ctrl_buffer(ihdl->pAllocBuf);
         ihdl->pAllocBuf = NULL;
      }
   }
   mhdlFinalize(hdl, NULL);
   free_ctrl_buffer( hdl );
   
   return MEDIA_SUCCESS;
}

#if defined(__SPEECH_ENHENCEMENT_SWIP_SUPPORT__)
static kal_bool isNeedSphEnh(void)
{
   if ( AM_IsSpeechOn() || Media_IsCSDMode() )
      return KAL_FALSE;
   
#if defined( __I2S_INPUT_MODE_SUPPORT__ )
   if (I2S_is_I2S_open())
      return KAL_FALSE;
#endif

   return KAL_TRUE;
}
#endif

MHdl *MH_Rec_Component_Open_General(
   void(*handler)( MHdl *handle, Media_Event event ),
   MHPB_CompList const *pSwEncFunc,
   MHPB_CompList const *pDspEncFunc,
   kal_uint32 (*Decision)(void) )
{
   MHdl *hdl;
   MHPB_Internal *ihdl;
   SrcCapParam stCap;
   kal_uint32 uEncDecision = 0;
   
   MHPB_CompList const *pArray[2];
   
   pArray[0] = &DirectPackFunc;
   pArray[1] = NULL;
   
   // Construct handle
   hdl = MH_Component_Construct(pArray);
   ihdl = (MHPB_Internal *)hdl;
   
   // Set default member function
   hdl->Record  = GenCompRecord;
   hdl->Pause   = GenCompRecPause;
   hdl->Resume  = GenCompRecResume;
   hdl->Stop    = GenCompRecStop;
   hdl->Close   = GenCompRecClose;
   hdl->Process = GenCompProcess;
   
   // Store information
   ihdl->pSwEncFunc = pSwEncFunc;
   ihdl->pDspEncFunc = pDspEncFunc;
   ihdl->EncDecision = Decision;
   
   // Set alias
   ihdl->pNodeStart = ihdl->pNodeEnd = ihdl->pNodePack = &ihdl->NodeArray[0];

   uEncDecision = Decision();
   
   // Encoder
   {
      MHPB_CompList const *pEncFunc;
      
      if (uEncDecision & COMPONENT_ENCODER_DSP_REQUIRED) {
         pEncFunc = pDspEncFunc;
         ihdl->fDspEncode = KAL_TRUE;
      } else {
         pEncFunc = pSwEncFunc;
         ihdl->fDspEncode = KAL_FALSE;
      }
      ihdl->pNodeEncode = HookAndConstructComponent(ihdl, NULL, ihdl->pNodePack, pEncFunc);
   }
   
   if (uEncDecision & COMPONENT_SOURCE_REQUIRED) {
      //-- Consturct source component
      ihdl->pNodeSource = HookAndConstructComponent(ihdl, NULL, ihdl->pNodeEncode, &PcmSourceFunc);
      
      //-- Negotiation information
      // Get the capability of Encoder
      ihdl->pNodeEncode->curHdl->SetParameter(ihdl->pNodeEncode->curHdl, OMX_IndexParamMediaTekQueryEncodeSupportFormat, (OMX_PTR) &stCap);
      
      // Negotiate with Sourcer
      ihdl->pNodeSource->curHdl->SetParameter(ihdl->pNodeSource->curHdl, OMX_IndexParamMediaTekPcmSourceNegotiation, (OMX_PTR) &stCap);
      
      // Set the negotiated information to encoder
      ihdl->pNodeEncode->curHdl->SetParameter(ihdl->pNodeEncode->curHdl, OMX_IndexParamMediaTekSetEncodeFormat, (OMX_PTR) &stCap);
      
      //-- SRC (Sampling Rate Convert) part
      // Get the sampling rate and channel number of source and encoder
      ihdl->pNodeSource->curHdl->SetParameter(ihdl->pNodeSource->curHdl, OMX_IndexParamMediaTekQuerySetPcmSourceInfo, (OMX_PTR) &ihdl->stFormat);
      
      if ( (ihdl->stFormat.uOriChannelNum != ihdl->stFormat.uOutputChannelNum) || (ihdl->stFormat.uOriSamplingFreq != ihdl->stFormat.uOutputSamplingFreq) ) {
         //-- Hook SRC (Sampling Rate Convert)
         
         // Construct and set alias
         ihdl->pNodeSRC = HookAndConstructComponent(ihdl, ihdl->pNodeSource, ihdl->pNodeEncode, &SampleRateConvertFunc);
         
         // Set sampling rate and channel number information
         ihdl->pNodeSRC->curHdl->SetParameter(ihdl->pNodeSRC->curHdl, OMX_IndexParamMediaTekQuerySetPcmSourceInfo, (OMX_PTR) &ihdl->stFormat);
      }
#if defined(__SPEECH_ENHENCEMENT_SWIP_SUPPORT__)
      if ( isNeedSphEnh() ) {
         //-- Hook speech enhancement
         AcHdlNode *pNext;
         
         if (ihdl->pNodeSRC)
            pNext = ihdl->pNodeSRC;
         else
            pNext = ihdl->pNodeEncode;
         
         // Construct and set alias
         ihdl->pNodeSphEnh = HookAndConstructComponent(ihdl, ihdl->pNodeSource, ipNext, &SpeechEnhanceFunc);
         
         // Set sampling rate and channel number information
         ihdl->pNodeSphEnh->curHdl->SetParameter(ihdl->pNodeSphEnh->curHdl, OMX_IndexParamMediaTekQuerySetPcmSourceInfo, (OMX_PTR) &ihdl->stFormat);
      }
#endif
   }
              
   return hdl;
}

#if 1

MHdl *MH_Rec_Component_Open(
   void(*handler)( MHdl *handle, Media_Event event ),
   MHPB_CompList const *pEncFunc,
   MHPB_CompList const *pPackFunc)
{

   return MH_Rec_Component_Open_General(handler, pEncFunc, NULL, SwDecision);

}

MHdl *MH_Rec_Direct_Open(
   void(*handler)( MHdl *handle, Media_Event event ),
   MHPB_CompList const *pEncFunc,
   MHPB_CompList const *pPackFunc)
{
   return MH_Rec_Component_Open_General(handler, NULL, pEncFunc, DspDecision);
}

#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__SPEECH_ENHENCEMENT_SWIP_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#endif  // #if defined(__AUDIO_RECORD_COMPONENT_SUPPORT__)
