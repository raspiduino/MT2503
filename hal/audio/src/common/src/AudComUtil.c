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
 *   AudComUtil.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   The utility function for basic audio component
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if !defined(__SMART_PHONE_MODEM__) && !defined(__L1_STANDALONE__) && !defined(MED_MODEM)

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "reg_base.h"
#include "l1d_reg.h"
#include "fsal.h"
#include "string.h"
#include "audio_enum.h"
#include "l1sp_trc.h"
#include "l1audio.h"
#include "audio_def.h"
#include "media.h"
#include "AudCom.h"
#include "OMX_Core.h"
#include "OMX_Types.h"
#include "OMX_Index.h"
#include "AudComUtil.h"
#include "MedAdapt.h"

/*------------------------------------------------*/
/* Service to execute callback.                   */
/*------------------------------------------------*/
#define COMMAND_QSIZE 128

typedef struct {
   AudComHdlInt *ihdl;
   OMX_U32 type;
   OMX_U32 event;
   OMX_U32 nData1;
   OMX_U32 nData2;
   void *pEventData;
} CommandElement;

typedef struct {
   OMX_U32              read;
   OMX_U32              write;
   CommandElement       element[COMMAND_QSIZE];
} CommandQueue;

static struct {
   kal_uint32 aud_id;
   CommandQueue queue;
} ACU_Control;

uint32   SaveAndSetIRQMask( void );
void     RestoreIRQMask( uint32 );

extern kal_bool Is_PutPcmrutOn(void);

kal_bool ACU_IsFlushed(void)
{
   if (ACU_Control.queue.write == ACU_Control.queue.read)
      return true;
   else
      return false;
}

static void ACU_EventHandler( void *data )
{
   CommandElement *pCommand;
   void *pFWData;
   
   while (ACU_Control.queue.write != ACU_Control.queue.read) {
      pCommand = &ACU_Control.queue.element[ACU_Control.queue.read & (COMMAND_QSIZE - 1)];
      pFWData = pCommand->ihdl->pFWData;
      switch (pCommand->type) {
         case 0:
            // EventHandler
            pCommand->ihdl->callbacks->EventHandler( (AudComHdl *)pCommand->ihdl, pFWData, (OMX_EVENTTYPE)pCommand->event, pCommand->nData1, pCommand->nData2, (void *)0 );
            break;
         case 1:
            // EmptyBufferDone
            pCommand->ihdl->callbacks->EmptyBufferDone( (AudComHdl *)pCommand->ihdl, pFWData, (OMX_BUFFERHEADERTYPE *)pCommand->pEventData);
            break;
         case 2:
            // FillBufferDone
            pCommand->ihdl->callbacks->FillBufferDone( (AudComHdl *)pCommand->ihdl, pFWData, (OMX_BUFFERHEADERTYPE *)pCommand->pEventData);
            break;
         case 3:
            // Process function
            pCommand->ihdl->basic.Process( (AudComHdl *)pCommand->ihdl );
            break;
         case 4:
            // End
            {
               MHPB_Internal  *hdl = (MHPB_Internal *)pCommand->pEventData ;
               hdl->endflag = KAL_TRUE;
               break;
            }
         case 5:
            // Media hdl send cmd
            {
            	 MHdl *hdl = (MHdl *)pCommand->pEventData ;
            	 hdl->handler( hdl, (Media_Event)hdl->data );               
               break;
            }
         case 6:
            // Process done cmd
            {
               pCommand->ihdl->isProcessDone = KAL_TRUE;
               break;
            }   
         default:
            ASSERT(0);
      }
      
      ACU_Control.queue.read++;
   }
}

void ACU_Init( void )
{
   memset(&ACU_Control, 0, sizeof(ACU_Control));
   ACU_Control.aud_id = L1Audio_GetAudioID();
   L1Audio_SetEventHandler(ACU_Control.aud_id, ACU_EventHandler);
}

void ACU_SendCommand(AudComHdlInt *ihdl, OMX_U32 type, OMX_U32 event, OMX_U32 data1, OMX_U32 data2, void *pData)
{
   uint32 savedMask;
   CommandElement *pCommand;

   savedMask = SaveAndSetIRQMask();
   if ( (ACU_Control.queue.write - ACU_Control.queue.read) >= COMMAND_QSIZE ) {
      // Queue full
      ASSERT(0);
   }
   pCommand = &ACU_Control.queue.element[ACU_Control.queue.write & (COMMAND_QSIZE - 1)];
   pCommand->ihdl = ihdl;
   pCommand->type = type;
   pCommand->event = event;
   pCommand->nData1 = data1;
   pCommand->nData2 = data2;
   pCommand->pEventData = pData;
   ACU_Control.queue.write++;
   RestoreIRQMask(savedMask);
   
   L1Audio_SetEvent(ACU_Control.aud_id, (void *)0);
}

void ACU_SendProcessCommandl(AudComHdlInt *ihdl) {
   ACU_SendCommand(ihdl, 3, 0, 0, 0, NULL);
}

void ACU_SendEndCommandl(MHPB_Internal *ihdl) {
   ACU_SendCommand(NULL, 4, 0, 0, 0, ihdl);
}

void ACU_SendMediaEvent(MHdl *ihdl) {
   ACU_SendCommand(NULL, 5, 0, 0, 0, ihdl);
}

void ACU_SendProcessDoneCommandl(AudComHdlInt *ihdl) {
   ACU_SendCommand(ihdl, 6, 0, 0, 0, NULL);
}

/*------------------------------------------------*/
/* Queue Operation.                               */
/*------------------------------------------------*/
void ACU_Queue_Init(BufferQueue *queue)
{
   queue->read = queue->write = 0;
}

void ACU_Queue_Enqueue(BufferQueue *queue, OMX_BUFFERHEADERTYPE *pBufHdr)
{
   OMX_U32 qCount = queue->write - queue->read;

   ASSERT(qCount < BUFQSIZE);
   queue->element[queue->write & (BUFQSIZE-1)] = pBufHdr;
   queue->write++;
}

OMX_BUFFERHEADERTYPE *ACU_Queue_Dequeue(BufferQueue *queue)
{
   OMX_BUFFERHEADERTYPE *pBufHdr;
   
   ASSERT(queue->write != queue->read);
   pBufHdr = queue->pCurBufHdr = queue->element[queue->read & (BUFQSIZE-1)];
   queue->read++;
   
   
   return pBufHdr;
}

OMX_BUFFERHEADERTYPE *ACU_Queue_Peek(BufferQueue *queue)
{
   OMX_BUFFERHEADERTYPE *pBufHdr;
   
   if (queue->write != queue->read)
      pBufHdr = queue->element[queue->read & (BUFQSIZE-1)];
   else
      pBufHdr = NULL;
      
   return pBufHdr;
}

OMX_U32 ACU_Queue_Count(BufferQueue *queue)
{
   return (queue->write - queue->read);
}

OMX_BOOL ACU_Queue_IsFull(BufferQueue *queue)
{
   OMX_U32 count;
   
   count = ACU_Queue_Count(queue);
   if (count == BUFQSIZE)
      return OMX_TRUE;
   else
      return OMX_FALSE;
}

OMX_BOOL ACU_Queue_IsEmpty(BufferQueue *queue)
{
   OMX_U32 count;
   
   count = ACU_Queue_Count(queue);
   if (count == 0)
      return OMX_TRUE;
   else
      return OMX_FALSE;
}

/*------------------------------------------------*/
/* Set Input and Output Buffer Header.            */
/*------------------------------------------------*/
static OMX_ERRORTYPE ACU_IndicateThisBuffer(AudComHdl *hdl, OMX_BUFFERHEADERTYPE *pBufHdr, OMX_U32 dir)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   BufferQueue *queue = NULL;

   // Check hdl is valid
   if (NULL == hdl)
      return OMX_ErrorInvalidComponent;
   
   // Choose queue
   if (dir == 0)
      queue = &ihdl->InputQ;
   else if (dir == 1)
      queue = &ihdl->OutputQ;
   else
      ASSERT(0);
   
   // Check whether queue is full
   if ( ACU_Queue_IsFull(queue) )
      return OMX_ErrorOverflow;
   
   // Enqueue
   ACU_Queue_Enqueue(queue, pBufHdr);
   
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE ACU_EmptyThisBuffer(AudComHdl *hdl, OMX_BUFFERHEADERTYPE *pBufHdr)
{
   return ACU_IndicateThisBuffer(hdl, pBufHdr, 0);
}

static OMX_ERRORTYPE ACU_FillThisBuffer(AudComHdl *hdl, OMX_BUFFERHEADERTYPE *pBufHdr)
{
   return ACU_IndicateThisBuffer(hdl, pBufHdr, 1);
}

/*------------------------------------------------*/
/* Provide the dummy functions.                   */
/*------------------------------------------------*/
static OMX_ERRORTYPE ACU_DummyStart(AudComHdl *hdl)
{
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE ACU_DummyStop(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   
   ihdl->mediaStatus = COMPONENT_STATE_IDLE;
   
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE ACU_DummyDeinit(AudComHdl *hdl)
{
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE ACU_DummyProcess(AudComHdl *hdl)
{
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE ACU_DummyGetMetaData(AudComHdl *hdl, OMX_PTR pMetaData)
{
   return OMX_ErrorNotImplemented;
}

static OMX_ERRORTYPE ACU_DummySetParameter(AudComHdl *hdl, OMX_INDEXTYPE index, OMX_PTR pStruct)
{
   return OMX_ErrorNotImplemented;
}


OMX_ERRORTYPE ACU_ParGenStop(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_STOP, ihdl->mediaType, ihdl->mediaStatus,ihdl->endStatus,0,0);   
   if (ihdl->mediaStatus == COMPONENT_STATE_PLAY) 
   {
      ihdl->mediaStatus = COMPONENT_STATE_IDLE;
      ihdl->endStatus = MEDIA_TERMINATED;
   }
   return OMX_ErrorNone;
}


OMX_ERRORTYPE ACU_GenDeinit(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_DEINIT, ihdl->mediaType, ihdl->mediaStatus,0,0,0);
   ASSERT(ihdl->mediaStatus != COMPONENT_STATE_PLAY);
   ACU_FlushBufferQueue(hdl);
   return OMX_ErrorNone;
}

OMX_ERRORTYPE ACU_DSPDecoderProcess(AudComHdl *hdl)
{
   OMX_BUFFERHEADERTYPE *pBufHdr;
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   if (ihdl->isDspDecodeEOF && !ihdl->isEOFSet){    
     pBufHdr = ACU_GetBufferHeader( hdl, 1);
     if(pBufHdr != NULL){     
     	  ihdl->isEOFSet = KAL_TRUE;
        pBufHdr->nFlags |= OMX_BUFFERFLAG_EOS;
        ACU_SendCommand(ihdl, 0, OMX_EventBufferFlag, 1, pBufHdr->nFlags, pBufHdr);         
        ACU_WriteDataDone_ImmediateCallback(hdl, 0);
     } 
   }
   return OMX_ErrorNone;        
}

void ACU_DSPEofHandler(AudComHdlInt *ihdl)
{
   OMX_BUFFERHEADERTYPE *pBufHdr;
         
   ihdl->data = MEDIA_END;
   ihdl->isDspDecodeEOF =KAL_TRUE;
   pBufHdr = ACU_GetBufferHeader( (AudComHdl *)ihdl, 1);
   if(pBufHdr != NULL){
   	 ihdl->isEOFSet = KAL_TRUE;
     pBufHdr->nFlags |= OMX_BUFFERFLAG_EOS;
     ACU_SendCommand(ihdl, 0, OMX_EventBufferFlag, 1, pBufHdr->nFlags, pBufHdr);
     ACU_WriteDataDone_ImmediateCallback((AudComHdl *)ihdl, 0);
   }

   if(!Is_PutPcmrutOn()){
   	  mhdlException( ihdl->mhdl , MEDIA_END );
   }
   
   kal_brief_trace( TRACE_STATE, L1AUDIO_IDLE_STATE);
   ihdl->endStatus = MEDIA_TERMINATED;  
}

/*------------------------------------------------*/
/* Initialize the audio component.                */
/*------------------------------------------------*/
OMX_ERRORTYPE ACU_InitHdl(AudComHdl *hdl, void *pFWData, AudComCallback *pCallback)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   
   // Check hdl is valid
   if (NULL == hdl)
      return OMX_ErrorInvalidComponent;
   
   // Use the dummy function
   hdl->Start = ACU_DummyStart;
   hdl->Stop = ACU_DummyStop;
   hdl->Deinit = ACU_DummyDeinit;
   hdl->Process = ACU_DummyProcess;
   hdl->GetMetaData = ACU_DummyGetMetaData;
   hdl->SetParameter = ACU_DummySetParameter;
   
   // Indicate the member function
   hdl->EmptyThisBuffer = ACU_EmptyThisBuffer;
   hdl->FillThisBuffer = ACU_FillThisBuffer;

   // Save the pFWData and pCallback
   ihdl->pFWData = pFWData;
   ihdl->callbacks = pCallback;

   return OMX_ErrorNone;
}

/*------------------------------------------------*/
/* Buffer Operations.                             */
/*------------------------------------------------*/
void ACU_GetReadBuffer(AudComHdl *hdl, OMX_U8 **buffer, OMX_U32 *uLen)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   OMX_BUFFERHEADERTYPE *pBufHdr;
   
   // Set initial value
   *buffer = NULL;
   *uLen = 0;

   // Get the input buffer header      
   if (!ihdl->InputQ.pCurBufHdr) {
      BufferQueue *pInputQ;
      
      pInputQ = &ihdl->InputQ;
      
      if ( ACU_Queue_Count(pInputQ) ) {
         ihdl->InputQ.pCurBufHdr = ACU_Queue_Dequeue(pInputQ);
      } else {
         // No input buffer
         return;
      }
   }
   
   pBufHdr = ihdl->InputQ.pCurBufHdr;
   *buffer = pBufHdr->pBuffer + pBufHdr->nOffset;
   *uLen = pBufHdr->nFilledLen;
}

void ACU_ReadDataDone(AudComHdl *hdl, OMX_U32 uLen)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   OMX_BUFFERHEADERTYPE *pBufHdr = ihdl->InputQ.pCurBufHdr;
   OMX_U32 flag = pBufHdr->nFlags;
   
   // Useless information
   if ((ihdl == NULL) || (pBufHdr == NULL))
      return;
   
   // Update input buffer
   ASSERT(pBufHdr->nFilledLen >= uLen);
   pBufHdr->nFilledLen -= uLen;
   pBufHdr->nOffset += uLen;
   // If input buffer is empty, callback
   if (0 == pBufHdr->nFilledLen) {
      ihdl->InputQ.pCurBufHdr = NULL;
      ACU_SendCommand(ihdl, 1, 0, 0, 0, (void *)pBufHdr);
      //ihdl->callbacks->EmptyBufferDone( hdl, ihdl->pFWData, pBufHdr );
   
      if (flag & OMX_BUFFERFLAG_EOS) {
         ihdl->isEOF = KAL_TRUE;
         ACU_SendCommand(ihdl, 0, OMX_EventBufferFlag, 0, flag, pBufHdr);
      }
   }
}

void ACU_GetWriteBuffer(AudComHdl *hdl, OMX_U8 **buffer, OMX_U32 *uLen)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   OMX_BUFFERHEADERTYPE *pBufHdr;
   
   // Set initial value
   *buffer = NULL;
   *uLen = 0;
   
   // Check and Get the output buffer
   if (!ihdl->OutputQ.pCurBufHdr) {
      BufferQueue *pOutputQ;
      
      pOutputQ = &ihdl->OutputQ;
      if ( ACU_Queue_Count(pOutputQ) ) {
         ihdl->OutputQ.pCurBufHdr = ACU_Queue_Dequeue(pOutputQ);
      } else {
         // No output buffer
         return;
      }
   }
   
   pBufHdr = ihdl->OutputQ.pCurBufHdr;
   pBufHdr->nFlags &= ~OMX_BUFFERFLAG_EOS;
   *uLen = pBufHdr->nAllocLen - (pBufHdr->nOffset + pBufHdr->nFilledLen);
   *buffer = pBufHdr->pBuffer + pBufHdr->nOffset + pBufHdr->nFilledLen;
}

void ACU_WriteDataDone(AudComHdl *hdl, OMX_U32 uLen)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   OMX_BUFFERHEADERTYPE *pBufHdr = ihdl->OutputQ.pCurBufHdr;
   
   // Useless information
   if (uLen == 0)
      return;
   
   pBufHdr->nFilledLen += uLen;
   ASSERT( (pBufHdr->nOffset + pBufHdr->nFilledLen) <= pBufHdr->nAllocLen );
   if ( pBufHdr->nAllocLen == (pBufHdr->nOffset + pBufHdr->nFilledLen) ) {
      // Buffer is full
      ihdl->OutputQ.pCurBufHdr = NULL;
      ACU_SendCommand(ihdl, 2, 0, 1, 0, (void *)pBufHdr);
      //ihdl->callbacks->FillBufferDone( hdl, ihdl->pFWData, pBufHdr );
   }
}

void ACU_WriteDataDone_ImmediateCallback(AudComHdl *hdl, OMX_U32 uLen)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   OMX_BUFFERHEADERTYPE *pBufHdr = ihdl->OutputQ.pCurBufHdr;
   
   pBufHdr->nFilledLen += uLen;
   ASSERT( (pBufHdr->nOffset + pBufHdr->nFilledLen) <= pBufHdr->nAllocLen );
   ihdl->OutputQ.pCurBufHdr = NULL;
   ACU_SendCommand(ihdl, 2, 0, 1, 0, (void *)pBufHdr);
   
   //ihdl->callbacks->FillBufferDone( hdl, ihdl->pFWData, pBufHdr );
}

void ACU_GetWriteBuffer_Threshold(AudComHdl *hdl, OMX_U8 **buffer, OMX_U32 *uLen, OMX_U32 uThreshold)
{
   OMX_U8 *pCurBuffer;
   OMX_U32 uCurLen;
   
   // Set initial value
   *buffer = NULL;
   *uLen = 0;
   
   // First time
   ACU_GetWriteBuffer(hdl, &pCurBuffer, &uCurLen);
   if (pCurBuffer == NULL) {
      return;
   } else if (uCurLen >= uThreshold) {
      *buffer = pCurBuffer;
      *uLen = uCurLen;
      return;
   } else {
      ACU_WriteDataDone_ImmediateCallback(hdl, 0);
   }
   
   // Second time
   ACU_GetWriteBuffer(hdl, &pCurBuffer, &uCurLen);
   if (pCurBuffer == NULL) {
      return;
   } else if (uCurLen >= uThreshold) {
      *buffer = pCurBuffer;
      *uLen = uCurLen;
      return;
   } else {
      // The buffer should be sufficient
      ASSERT(0);
   }
}

/*------------------------------------------------*/
/* DSP Buffer Operations.                         */
/*------------------------------------------------*/
static OMX_U32 ACU_GetDspFreeLength(
   kal_uint16 *dspWritePtr,
   kal_uint16 *dspReadPtr,
   kal_uint32 dsp_rb_size
)
{
   kal_int32 DSP_FreeLen, DSP_R;
   kal_uint16 DSP_W;
   
   DSP_W = *dspWritePtr;
   do {
      DSP_R = (int32)*dspReadPtr;
   } while( DSP_R != (int32)*dspReadPtr );

   DSP_FreeLen = DSP_R - (int32)DSP_W - 1;
   if ( DSP_FreeLen < 0 )
      DSP_FreeLen += dsp_rb_size;

   return DSP_FreeLen;
}

void ACU_WriteDataToDSP(
   AudComHdl *hdl,
   kal_uint16 *dspWritePtr,
   kal_uint16 *dspReadPtr,
   kal_uint32 pageNum
)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   BufferQueue *pInputQ;
   Media_Format format = Media_GetAudioFormat();
   pInputQ = &ihdl->InputQ;
   
   do {
      // DSP buffer is full
      if (0 == ACU_GetDspFreeLength(dspWritePtr, dspReadPtr, ihdl->dsp_rb_size) ) {
         break;
      }
      
      // There is no more bitstream
      if ( (!pInputQ->pCurBufHdr) &&
           (0 == ACU_Queue_Count(pInputQ) ) )
      {
         break;
      }
      
      // Write data
      {
         kal_int32 DSP_FreeLenLow, DSP_R, sWordCnt;
         kal_uint16 DSP_W, mcuReadTemp16;
         OMX_U8 *mcuReadBuf8;
         OMX_U32 mcuBufLen;
         volatile uint16 *idmaPtr;
         kal_bool fOdd = KAL_FALSE;
         kal_bool Odd  = KAL_FALSE;
         // Get DSP read/write position
         DSP_W = *dspWritePtr;
         do {
            DSP_R = (int32)*dspReadPtr;
         } while( DSP_R != (int32)*dspReadPtr );
         
         // Calculate the consecutive DSP write buffer (in word)
         if (DSP_R == ihdl->dsp_rb_base) {
            DSP_FreeLenLow = ihdl->dsp_rb_end - DSP_W - 1;
         } else if (DSP_W >= DSP_R) {
            DSP_FreeLenLow = ihdl->dsp_rb_end - DSP_W;
         } else {
            DSP_FreeLenLow = DSP_R - DSP_W - 1;
         }
         
         // Get MCU data count (in byte)
         ACU_GetReadBuffer(hdl, &mcuReadBuf8, &mcuBufLen);
         if ((mcuBufLen/2) >= DSP_FreeLenLow) 
         {
            sWordCnt = DSP_FreeLenLow;
         }  
         else if(mcuBufLen ==1)
         {
         	   if (ACU_PeekDataCount(hdl) > 1)
         	   {        	   	 
         	   	  mcuReadTemp16 = (kal_uint16)(*mcuReadBuf8);
         	   	  ACU_ReadDataDone (hdl, 1);
         	   	  ACU_GetReadBuffer(hdl, &mcuReadBuf8, &mcuBufLen);
         	   	  mcuReadTemp16 = (kal_uint16)(mcuReadTemp16 |((*mcuReadBuf8)<<8));
         	   	  ACU_ReadDataDone (hdl, 1);
#if defined(MT6256) || defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)      
                if(format==MEDIA_FORMAT_AAC ||format==MEDIA_FORMAT_AAC_PLUS)
                	idmaPtr = DSP_DM_ADDR(pageNum, DSP_W);                
                else
#endif
         	   	  idmaPtr = DSP_PM_ADDR(pageNum, DSP_W);
         	   	  (*idmaPtr++) = mcuReadTemp16;
         	   	  DSP_W += 1;
         	   	  if ( DSP_W >= ihdl->dsp_rb_end )
                   DSP_W = ihdl->dsp_rb_base;
                *dspWritePtr = DSP_W;
                Odd = KAL_TRUE;
         	   	      	   	  
         	   }
         	   else{
         	   	  mcuReadTemp16 = (kal_uint16)((*mcuReadBuf8));
                mcuReadBuf8 = (kal_uint8*)&mcuReadTemp16;
                sWordCnt = 1;
         	      fOdd = KAL_TRUE;
         	   }
         }  
         else 
         {
            sWordCnt = mcuBufLen/2;
         }
         if (!Odd){
         	   kal_uint32 I;
         	   OMX_U8 *mcuReadBufTemp8;   
             // Write data to DSP via IDMA
#if defined(MT6256) || defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)     
                if(format==MEDIA_FORMAT_AAC ||format==MEDIA_FORMAT_AAC_PLUS)
                	idmaPtr = DSP_DM_ADDR(pageNum, DSP_W);                
                else
#endif            
             idmaPtr = DSP_PM_ADDR(pageNum, DSP_W);
             mcuReadBufTemp8 = mcuReadBuf8;
             //check if addr word aligned
             if (((kal_uint32)mcuReadBuf8 & 0x1) !=0){        
                  for(I=sWordCnt; I>0; I--){                                                                                                                                                              
                     (*idmaPtr++) = (kal_uint16)((*mcuReadBufTemp8) | ((*(mcuReadBufTemp8+1))<<8));                                                                    
                     mcuReadBufTemp8 = mcuReadBufTemp8+2;
                  }
             }
         	   else
         IDMA_WriteToDSP(idmaPtr, (uint16*)mcuReadBuf8, sWordCnt);
         
         // Update DSP position
         DSP_W += sWordCnt;
         if ( DSP_W >= ihdl->dsp_rb_end )
            DSP_W = ihdl->dsp_rb_base;
         *dspWritePtr = DSP_W;
         // Update MCU position
             if (fOdd) {
                ACU_ReadDataDone(hdl, 1);
             } 
             else {
         ACU_ReadDataDone(hdl, sWordCnt<<1);
             }
         }
      }
   } while (1);
}

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
#if 0
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
#if 0
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
#endif

// dir: 0 is input, and 1 is output.
OMX_BUFFERHEADERTYPE *ACU_GetBufferHeader(AudComHdl *hdl, OMX_U32 dir)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   BufferQueue *pQueue = NULL;
   
   if (dir == 0) {
      pQueue = &ihdl->InputQ;
   } else if (dir == 1) {
      pQueue = &ihdl->OutputQ;
   } else {
      ASSERT(0);
   }
    
   if (!pQueue->pCurBufHdr) {      
      if ( ACU_Queue_Count(pQueue) ) {
         pQueue->pCurBufHdr = ACU_Queue_Dequeue(pQueue);
      } else {
         // No output buffer
         return NULL;
      }
   }
   
   return pQueue->pCurBufHdr;
}

void ACU_SetEOS(AudComHdl *hdl)
{
   OMX_BUFFERHEADERTYPE *pBufHdr;
   
   pBufHdr = ACU_GetBufferHeader(hdl, 1);
   pBufHdr->nFlags |= OMX_BUFFERFLAG_EOS;
}

void ACU_FlushBufferQueue(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   BufferQueue *pQueue;
   OMX_BUFFERHEADERTYPE *pBufHdr;
   
   // Process the input queue
   pQueue = &ihdl->InputQ;
   if (pQueue->pCurBufHdr) {
      ACU_SendCommand(ihdl, 1, 0, 0, 0, (void *)pQueue->pCurBufHdr);
      //ihdl->callbacks->EmptyBufferDone( hdl, ihdl->pFWData, pQueue->pCurBufHdr );
      pQueue->pCurBufHdr = NULL;
   }
   while ( ACU_Queue_Count(pQueue) ) {
      pBufHdr = ACU_Queue_Dequeue(pQueue);
      pBufHdr->nFlags = 0;
      ACU_SendCommand(ihdl, 1, 0, 0, 0, (void *)pBufHdr);
      //ihdl->callbacks->EmptyBufferDone( hdl, ihdl->pFWData, pBufHdr );
      pQueue->pCurBufHdr = NULL;
   }
   
   pQueue = &ihdl->OutputQ;
   if (pQueue->pCurBufHdr) {
      pQueue->pCurBufHdr->nFilledLen = 0;
      pQueue->pCurBufHdr->nOffset = 0;
   }
}

// KH 20100205: Should be peek all buffer in queue
Media_BufferEvent ACU_PeekByte(AudComHdl *hdl, kal_uint8 *uData)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   OMX_BUFFERHEADERTYPE *pBufHdr;
   
   *uData = 0;
   if (ihdl->isEOF)
      return MEDIA_BUFFER_EOF;
   
   // Get the input buffer header
   pBufHdr = ACU_GetBufferHeader(hdl, 0);
   if (pBufHdr == NULL)
      return MEDIA_BUFFER_NOT_READY;
   
   *uData = pBufHdr->pBuffer[pBufHdr->nOffset];
   
   return MEDIA_BUFFER_SUCCESS;
}

OMX_U32 ACU_PeekDataCount(AudComHdl *hdl)
{
   OMX_U32 dataCount = 0;
   OMX_BUFFERHEADERTYPE *pBufHdr;
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   BufferQueue *pQueue = &ihdl->InputQ;
   OMX_U32 i;

   pBufHdr = pQueue->pCurBufHdr;
   if (pBufHdr) {
      dataCount += pBufHdr->nFilledLen;
   }
   
   for (i=pQueue->read; i != pQueue->write; i++) {
      pBufHdr = pQueue->element[i & (BUFQSIZE-1)];
      dataCount += pBufHdr->nFilledLen;
   }
   
   return dataCount;
}

OMX_U32 ACU_PeekFreeCount(AudComHdl *hdl)
{
   OMX_U32 freeCount = 0;
   OMX_BUFFERHEADERTYPE *pBufHdr;
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   BufferQueue *pQueue = &ihdl->OutputQ;
   OMX_U32 i;

   pBufHdr = pQueue->pCurBufHdr;
   if (pBufHdr) {
      freeCount += pBufHdr->nAllocLen - (pBufHdr->nOffset + pBufHdr->nFilledLen);
   }
   
   for (i=pQueue->read; i != pQueue->write; i++) {
      pBufHdr = pQueue->element[i & (BUFQSIZE-1)];
      freeCount += pBufHdr->nAllocLen - (pBufHdr->nOffset + pBufHdr->nFilledLen);
   }
   
   return freeCount;
}

OMX_BOOL ACU_PeekIsEOS(AudComHdl *hdl)
{
   OMX_BUFFERHEADERTYPE *pBufHdr;
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   OMX_U32 i;
   BufferQueue *pQueue = &ihdl->InputQ;
   
   pBufHdr = ACU_GetBufferHeader(hdl, 0);
   if (pBufHdr) {
      if (pBufHdr->nFlags & OMX_BUFFERFLAG_EOS)
         return OMX_TRUE;
   } else {
      return OMX_FALSE;
   }
   
   for (i=pQueue->read; i != pQueue->write; i++) {
      pBufHdr = pQueue->element[i & (BUFQSIZE-1)];
      if (pBufHdr->nFlags & OMX_BUFFERFLAG_EOS)
         return OMX_TRUE;
   }
   
   return OMX_FALSE;
}

OMX_U32 ACU_PeekSpaceCount(AudComHdl *hdl)
{
   OMX_U32 dataCount = 0;
   OMX_BUFFERHEADERTYPE *pBufHdr;
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   
   pBufHdr = ACU_GetBufferHeader(hdl, 1);
   if (pBufHdr) {
      dataCount += pBufHdr->nAllocLen - (pBufHdr->nOffset + pBufHdr->nFilledLen);
   } else {
      return dataCount;
   }
   
   pBufHdr = ACU_Queue_Peek( &ihdl->OutputQ );
   if (pBufHdr) {
      dataCount += pBufHdr->nAllocLen - (pBufHdr->nOffset + pBufHdr->nFilledLen);
   }
   
   return dataCount;
}

void ACU_PeekNBytes(AudComHdl *hdl, OMX_U8 *pBufDest, OMX_U32 uLenDest)
{
   OMX_U32 segment;
   OMX_BUFFERHEADERTYPE *pBufHdr;
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   BufferQueue *pQueue = &ihdl->InputQ;
   OMX_U32 i;

   pBufHdr = pQueue->pCurBufHdr;
   if (pBufHdr) {
      segment = pBufHdr->nFilledLen;
      if (segment > uLenDest)
         segment = uLenDest;
      
      memcpy(pBufDest, pBufHdr->pBuffer + pBufHdr->nOffset, segment);
      uLenDest -= segment;
      pBufDest += segment;
   }
   
   for (i=pQueue->read; i != pQueue->write; i++) {
      pBufHdr = pQueue->element[i & (BUFQSIZE-1)];
      segment = pBufHdr->nFilledLen;
      if (segment > uLenDest)
         segment = uLenDest;
      
      memcpy(pBufDest, pBufHdr->pBuffer + pBufHdr->nOffset, segment);
      uLenDest -= segment;
      pBufDest += segment;
      
      if (uLenDest == 0)
         break;
   }
}

void ACU_PeekNByteDone(AudComHdl *hdl, OMX_U32 uLenDest)
{
   OMX_U32 segment;
   OMX_BUFFERHEADERTYPE *pBufHdr;

   do
   {
      pBufHdr = ACU_GetBufferHeader(hdl, 0);
      if(!pBufHdr)
      {
         break;
      }
      segment = pBufHdr->nFilledLen;
      if (segment > uLenDest) 
      {
         segment = uLenDest;
      }
      ACU_ReadDataDone(hdl, segment);
      uLenDest -= segment;
   }
   while(uLenDest > 0);
}

void ACU_GetNBytes(AudComHdl *hdl, OMX_U8 *pBufDest, OMX_U32 uLenDest)
{
   OMX_U8 *pBurSrc;
   OMX_U8 *pBufDesttemp;
   OMX_U32 uLenSrc, copyLen;;
   
   ASSERT(pBufDest != NULL);
   pBufDesttemp = pBufDest;
   
   while(uLenDest){
      ACU_GetReadBuffer(hdl, &pBurSrc, &uLenSrc);
      if (pBurSrc == NULL)
      	 break;
      if (uLenSrc >= uLenDest)
         copyLen = uLenDest;
      else
         copyLen = uLenSrc;
      memcpy(pBufDesttemp, pBurSrc, copyLen);
      uLenDest -= copyLen;
      ACU_ReadDataDone(hdl, copyLen);
      pBufDesttemp = pBufDesttemp + copyLen;
   }
}


/*------------------------------------------------*/
/* The utility functions for file operation.      */
/*------------------------------------------------*/
#if !defined(MED_NOT_PRESENT)
static OMX_ERRORTYPE ACU_FileOpenGeneral(STFSAL *pstFSAL, kal_char *pPath, kal_uint8 *pCacheBuf, FSAL_FileMode eMode)
{
   kal_wchar filename[256];
   
   kal_wsprintf( filename, "%s", pPath);
   if ( FSAL_OK != FSAL_Open(pstFSAL, filename, eMode) ) {
      // failure to open file
      //ihdl->callbacks->EventHandler( hdl, ihdl->pFWData, OMX_ErrorContentPipeOpenFailed, 0, 0, (void *)0 );
      return OMX_ErrorContentPipeOpenFailed;
   }
   
   // Set cache buffer to increase the performance
   FSAL_SetBuffer(pstFSAL, FILE_CACHE_BUFFER_SIZE, pCacheBuf);
   
   return OMX_ErrorNone;
}

OMX_ERRORTYPE ACU_FileOpenForRead(STFSAL *pstFSAL, kal_char *pPath, kal_uint8 *pCacheBuf)
{
   return ACU_FileOpenGeneral(pstFSAL, pPath, pCacheBuf, FSAL_READ_SHARED);
}

OMX_ERRORTYPE ACU_FileOpenForWrite(STFSAL *pstFSAL, kal_char *pPath, kal_uint8 *pCacheBuf)
{
   return ACU_FileOpenGeneral(pstFSAL, pPath, pCacheBuf, FSAL_WRITE);
}

static OMX_ERRORTYPE acu_WriteData_Common(AudComHdl *hdl, OMX_BUFFERHEADERTYPE *pBufHdr, kal_uint32 dataCount)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   
   if(ihdl->isEOF)
   {
      ihdl->Decode_EOF = KAL_TRUE;
      pBufHdr->nFlags |= OMX_BUFFERFLAG_EOS;
      ACU_SendCommand(ihdl, 0, OMX_EventBufferFlag, 1, pBufHdr->nFlags, pBufHdr);
   }
   else 
   {
      pBufHdr->nFlags &= ~OMX_BUFFERFLAG_EOS;
   }
   
   ACU_WriteDataDone_ImmediateCallback(hdl, dataCount);
   
   return OMX_ErrorNone;
}

OMX_ERRORTYPE ACU_FileReadGeneral(AudComHdl *hdl, STFSAL *pstFSAL, kal_uint32 *uOffset, kal_uint32 uBoundary)
{
   kal_uint32 fileLen;
   kal_uint32 fileDataSize, dataCount;
   OMX_U32 bufDataSize;
   OMX_U8 *pBuf;
   OMX_BUFFERHEADERTYPE *pBufHdr;
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   
   
   // Count the free space of output buffer
   ACU_GetWriteBuffer(hdl, &pBuf, &bufDataSize);
   if (bufDataSize == 0) {
      return OMX_ErrorNone;
   } else {
      pBufHdr = ihdl->OutputQ.pCurBufHdr;
   }
   
   // Count the valid data amount in file
   FSAL_GetFileSize(pstFSAL, &fileLen);
   if (fileLen > uBoundary) {
      fileLen = uBoundary;
   }
   fileDataSize = fileLen - (*uOffset);

   if(*uOffset > fileLen || fileDataSize == 0)
   {
      ihdl->isEOF = KAL_TRUE;
      pBufHdr->nFlags |= OMX_BUFFERFLAG_EOS;
      ACU_SendCommand(ihdl, 0, OMX_EventBufferFlag, 1, pBufHdr->nFlags, pBufHdr);
      ACU_WriteDataDone_ImmediateCallback(hdl, 0);
      return OMX_ErrorNone;
   }
      
   // Compare the adta count
   if (fileDataSize >= bufDataSize)
      dataCount = bufDataSize;
   else
      dataCount = fileDataSize;

#if defined(__AUDIO_DSP_LOWPOWER_V2__)
   kal_trace( TRACE_GROUP_AUDIOLP, ACU_FILEREAD, dataCount); //Dior add for debug
#endif

   // Read file
   FSAL_Seek( pstFSAL, *uOffset);
   if (FSAL_Read_Bytes( pstFSAL, pBuf, dataCount) != FSAL_OK) {
      // Playback should be terminated
      return OMX_ErrorContentPipeCreationFailed;
   }

   // Update offset
   *uOffset = (*uOffset) + dataCount;
   if (fileLen == *uOffset) {
      ihdl->isEOF = KAL_TRUE;
   }

   return acu_WriteData_Common(hdl, pBufHdr, dataCount);
}

OMX_ERRORTYPE ACU_FileRead(AudComHdl *hdl, STFSAL *pstFSAL, kal_uint32 *uOffset)
{
   return ACU_FileReadGeneral(hdl, pstFSAL, uOffset, 0xFFFFFFFF);
}

OMX_ERRORTYPE ACU_FileWrite(AudComHdl *hdl, STFSAL *pstFSAL, kal_uint32 *length)
{
   OMX_U32 bufDataSize;
   OMX_U8 *pBuf;
   OMX_BUFFERHEADERTYPE *pBufHdr;
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   
   *length = 0;
   
   // Count the data amount of output buffer
   ACU_GetReadBuffer(hdl, &pBuf, &bufDataSize);
   if (bufDataSize == 0) {
      return OMX_ErrorNone;
   } else {
      pBufHdr = ihdl->InputQ.pCurBufHdr;
   }
   
   // Write file
   if (FSAL_Write_Bytes( pstFSAL, pBuf, bufDataSize) != FSAL_OK) {
      // Record should be terminated
      return OMX_ErrorContentPipeCreationFailed;
   }

   // Update offset
   *length = bufDataSize;
   if (pBufHdr->nFlags & OMX_BUFFERFLAG_EOS) {
      ACU_SendCommand(ihdl, 0, OMX_EventBufferFlag, 0, pBufHdr->nFlags, pBufHdr);
   }
   ACU_ReadDataDone(hdl, bufDataSize);
   
   return OMX_ErrorNone;
}
#endif

OMX_ERRORTYPE ACU_PutToBuffer_Threshold(AudComHdl *hdl, kal_uint8 *pSrcBuf, kal_uint32 *ulength, kal_uint32 uThreshold)
{

   OMX_U32 bsLength = *ulength;
   OMX_U32 bufDataSize, dataCount;
   OMX_U8 *pBuf;
   OMX_BUFFERHEADERTYPE *pBufHdr;
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   *ulength = 0;

   // Count the valid data amount in file
   if(ihdl->Decode_EOF)
   {
      return OMX_ErrorNone;
   }

   if(bsLength == 0)
   {
      ihdl->isEOF = KAL_TRUE;
   }
   
   // Count the free space of output buffer
   ACU_GetWriteBuffer(hdl, &pBuf, &bufDataSize);
   if (bufDataSize == 0) {
      return OMX_ErrorNone;
   }

   pBufHdr = ihdl->OutputQ.pCurBufHdr;
   
   // Compare the data count
   if (bsLength >= bufDataSize)
      dataCount = bufDataSize;
   else
      dataCount = bsLength;

   memcpy(pBuf, pSrcBuf, dataCount);
   *ulength = dataCount;

   if(ihdl->isEOF)
   {
      ihdl->Decode_EOF = KAL_TRUE;
      pBufHdr->nFlags |= OMX_BUFFERFLAG_EOS;
      ACU_SendCommand(ihdl, 0, OMX_EventBufferFlag, 1, pBufHdr->nFlags, pBufHdr);
   }
   else 
   {
      pBufHdr->nFlags &= ~OMX_BUFFERFLAG_EOS;
   }
   
   if(ihdl->isEOF || uThreshold <= (pBufHdr->nFilledLen + dataCount))
   {
      ACU_WriteDataDone_ImmediateCallback(hdl, dataCount);
   }
   else
   {
      ACU_WriteDataDone(hdl, dataCount);
   }
   return OMX_ErrorNone;
}

OMX_ERRORTYPE ACU_PutToBuffer(AudComHdl *hdl, kal_uint8 *pSrcBuf, kal_uint32 *ulength)
{
   return ACU_PutToBuffer_Threshold(hdl, pSrcBuf, ulength, 0);
}

#if defined(__AUDIO_STREAMING_NON_RINGBUFFER_SUPPORT__)
OMX_ERRORTYPE ACU_BsQToBuffer(AudComHdl *hdl, kal_bool fPCMByte2Word)
{
   OMX_U32 bufDataSize;
   OMX_U32 uFillLength;
   OMX_U8 *pBuf;
   OMX_BUFFERHEADERTYPE *pBufHdr;
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;

   // Count the valid data amount in file
   if(ihdl->Decode_EOF)
   {
      return OMX_ErrorNone;
   }

   // Count the free space of output buffer
   ACU_GetWriteBuffer(hdl, &pBuf, &bufDataSize);
   if (bufDataSize == 0) 
   {
      return OMX_ErrorNone;
   }

   pBufHdr = ihdl->OutputQ.pCurBufHdr;

   uFillLength = AudBufQ_AutoFillBuffer(ihdl->mhdl, ihdl->mhdl->pStrmStruct, pBuf, bufDataSize, fPCMByte2Word);
   if(uFillLength == 0 && ihdl->mhdl->eof )
   {
      ihdl->isEOF = KAL_TRUE;
   }

   return acu_WriteData_Common(hdl, pBufHdr, uFillLength);
}
#endif

#if !defined(MED_NOT_PRESENT)
OMX_ERRORTYPE ACU_GetBytesFromFile(STFSAL *pstFSAL, kal_uint32 *uOffset, kal_uint32 *num_bytes, kal_uint8 *ptr)
{
   kal_uint32 fileLen, fileDataSize;
   
   // Count the valid data amount in file
   FSAL_GetFileSize(pstFSAL, &fileLen);
   fileDataSize = fileLen - (*uOffset);
   
   if (fileDataSize <= (*num_bytes)) {
      // EOF
      *num_bytes = fileDataSize;
   }
   
   FSAL_Seek( pstFSAL, *uOffset);
   if (FSAL_Read_Bytes( pstFSAL, ptr, *num_bytes) != FSAL_OK) {
      // Playback should be terminated
      *num_bytes = 0;
      return OMX_ErrorUndefined;
   }
   
   return OMX_ErrorNone;
}

void ACU_SkipID3Tag(STFSAL *pstFSAL, kal_uint32 *fileOffset, kal_uint8 *ptr)
{
   kal_uint32 num_bytes, file_size, tagsize, fileDataSize;
   
   file_size = 0;

   while (1) {
      OMX_ERRORTYPE eResult;
      
      tagsize = 0;
      num_bytes = ID3V2_HEADER_LEN;
      eResult = ACU_GetBytesFromFile(pstFSAL, fileOffset, &num_bytes, ptr);
      if ( (OMX_ErrorNone != eResult) || (num_bytes != ID3V2_HEADER_LEN) )
         return;
      
      if (kal_mem_cmp(ptr, "ID3", 3) == 0) {
         tagsize = (ptr[6] << 21) | (ptr[7] << 14) | (ptr[8] <<  7) | (ptr[9] <<  0);
         
         // Count the valid data amount in file
         FSAL_GetFileSize(pstFSAL, &file_size);
         fileDataSize = file_size - (*fileOffset);
         
         if (fileDataSize >= (tagsize + 10)) {
            *fileOffset += (tagsize+10);            
         } else {
            // Don't skip ID3 tag if tagsize is invalid
            return;
         }
      } else {
         return;
      }
   }
}

#endif

#define AUDIO_RESUME_BUFFER_FRAME_SKIP 300

void ACU_SetResumePoint(AudResumeBuffer *pResBuf, kal_uint32 uOffset, kal_uint32 uFrameNum)
{
   kal_uint32 uPreIndex;

   if(pResBuf==NULL)
   {
      return;
   }
   
   uPreIndex = (pResBuf->uIndex + 1) & 0x0001;

   if(pResBuf->uFrame[0]==0 || uFrameNum < pResBuf->uFrame[1] || uFrameNum < pResBuf->uFrame[0])
   { 
      //initialize
      pResBuf->uIndex = 1;
      pResBuf->uOffset[0] = pResBuf->uOffset[1] = uOffset;
      pResBuf->uFrame[0]  = pResBuf->uFrame[1]  = uFrameNum; 
      return;
   }

   if(uFrameNum > pResBuf->uFrame[uPreIndex] + AUDIO_RESUME_BUFFER_FRAME_SKIP)
   {
      pResBuf->uOffset[pResBuf->uIndex] = uOffset;
      pResBuf->uFrame[pResBuf->uIndex] = uFrameNum; 
      pResBuf->uIndex = (pResBuf->uIndex + 1) & 0x0001;
   }
}

void ACU_GetResumePoint(AudResumeBuffer *pResBuf, kal_uint32 *uOffset, kal_uint32 *uFrameNum)
{
   if(pResBuf)
   {
      *uOffset = pResBuf->uOffset[pResBuf->uIndex];
      *uFrameNum = pResBuf->uFrame[pResBuf->uIndex]; 
   }
   else
   {
      *uOffset = 0;
      *uFrameNum = 0; 
   }
}

void ACU_LoadResumeInfo(AudComHdl *hdl)
{
   OMX_BUFFERHEADERTYPE *pBufHdr;
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;

   pBufHdr = ACU_GetBufferHeader(hdl, 0);
   if(pBufHdr) 
   {
      BsBufferInfo *bsInfo = (BsBufferInfo*)pBufHdr->pOutputPortPrivate;
      if(bsInfo)
      {
         ihdl->bsInfo.uFrameDur = bsInfo->uFrameDur;
         ihdl->bsInfo.uCurrentFrame = bsInfo->uCurrentFrame;
         ihdl->bsInfo.uCurrentOffset = bsInfo->uCurrentOffset;
         ihdl->bsInfo.pResBuf = bsInfo->pResBuf;
      }
   }
}

#endif /* !defined(__SMART_PHONE_MODEM__) */

