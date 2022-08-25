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
 *   DafDecoder.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   The basic functions of DAF decoder.
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

#ifdef DAF_DECODE

#include "kal_trace.h"
#include "l1sp_trc.h"
#include "OMX_Types.h"
#include "OMX_Core.h"
#include "audio_enum.h"
#include "AudCom.h"
#include "AudComUtil.h"
#include "DAF_codec.h"
#include "mp3_dec_exp.h"
#include "common_def.h"
//#include "dpmgr.h"

#define DAF_DECODE_FRAME_LEN 4608
#define DAF_MAX_FRAME_SIZE 2881
#define DAF_MIN_DECODER_INPUT_LEN (DAF_MAX_FRAME_SIZE + 8)

static const kal_uint16 dafSampleFreq[9] = {44100, 48000, 32000, 22050, 24000, 16000, 11025, 12000, 8000};

extern void AFE_SetDigitalGain( kal_uint8 aud_func, kal_uint8 level );

/*------------------------------------------------*/
/* The private functions of DAF decoder.          */
/*------------------------------------------------*/

static kal_uint32 dafRbGetDataCount( DAF_DecData *pDecData )
{
   int32 count;

   count = pDecData->uWrite - pDecData->uRead;
   if (count < 0) {
      count += pDecData->bsSize;
   }
   
   return count;
}

static kal_uint32 dafRbGetFreeSpace( DAF_DecData *pDecData )
{
   int32 count;

   count = pDecData->uRead - pDecData->uWrite - 1;
   if (count < 0) {
      count += pDecData->bsSize;
   }
   
   return count;
}

static void dafRbGetWriteBuffer( DAF_DecData *pDecData, kal_uint8 **buffer, kal_uint32 *buf_len )// in bytes
{
   int32 count;

   if (pDecData->uRead > pDecData->uWrite) {
      count = pDecData->uRead - pDecData->uWrite - 1;
   } else if (pDecData->uRead == 0) {
      count = pDecData->bsSize - pDecData->uWrite - 1;
   } else {
      count = pDecData->bsSize - pDecData->uWrite;
   }
   
   ASSERT( count>=0 );
   *buffer = ((kal_uint8 *)pDecData->bs_buf) + pDecData->uWrite;
   *buf_len = count;
}

static void dafRbWriteDataDone( DAF_DecData *pDecData, kal_uint32 len ) // in bytes
{
   pDecData->uWrite += len;

   ASSERT(pDecData->uWrite <= pDecData->bsSize);
   if (pDecData->uWrite == pDecData->bsSize ) {
      pDecData->uWrite = 0;
   }
}

static void dafRbReadDataDone( DAF_DecData *pDecData, kal_uint32 len ) // in bytes
{
   pDecData->uRead += len;
   if (pDecData->uRead >= pDecData->bsSize ) {
      pDecData->uRead -= pDecData->bsSize;
   }
}

static void dafDec_ResetMem(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   DAF_DecData *pDecData = (DAF_DecData *)ihdl->pPrivateData;
   
   // Load code
//   DPMGR_Load(DPMGR_MP3);
   
   // Initialize memory
   ihdl->isTimeUP = KAL_FALSE;
   ihdl->endStatus = MEDIA_NONE;
   ihdl->isEOF = KAL_FALSE;
   ihdl->Decode_EOF = KAL_FALSE;
   ihdl->errorReport = 0;
   ihdl->wDspReadIdx = 0xFFFF;
   pDecData->fDecoderSuccess = false;
   pDecData->uWrite = pDecData->uRead = 0;
   pDecData->errorFrame = 0;
   pDecData->fFirstDecode = KAL_TRUE;
   memset(pDecData->bs_buf, 0, pDecData->bsSize*sizeof(kal_uint8));

   pDecData->decHandle = MP3Dec_Init(pDecData->work1_buf, pDecData->work2_buf);
}

/*------------------------------------------------*/
/* The private member functions of DAF decoder.   */
/*------------------------------------------------*/

static OMX_ERRORTYPE DafDec_Start(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   kal_int32 J;
   if (ihdl->mediaStatus == COMPONENT_STATE_PLAY) {
      return OMX_ErrorIncorrectStateOperation;
   }
   
   if (ihdl->mediaStatus != COMPONENT_STATE_READY_SET) {
      // Initialize memory
      dafDec_ResetMem(hdl);
   }

   ACU_LoadResumeInfo(hdl);
   
   ihdl->mediaStatus = COMPONENT_STATE_PLAY;
   
   ACU_SendProcessCommandl(ihdl);
   ACU_SendProcessDoneCommandl(ihdl);
   for (J = 0; ; J++) {
      if (ihdl->isProcessDone){
      	 break;
      }
      kal_sleep_task( 1 );
   }
   
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE DafDec_Stop(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;

   //clear resume buffer
   ihdl->bsInfo.pResBuf = NULL;
   ihdl->mediaStatus = COMPONENT_STATE_TERMINATE;
   ihdl->endStatus = MEDIA_TERMINATED;
     
   kal_trace( TRACE_FUNC, L1AUDIO_STOP, ihdl->mediaType );

   return OMX_ErrorNone;
}


static void dafDec_WritePcmInfo(AudComHdlInt *ihdl)
{
   DAF_DecData *pDecData = (DAF_DecData *)ihdl->pPrivateData;
   
   ASSERT((pDecData->decHandle->sampleRateIndex >= 0) && (pDecData->decHandle->sampleRateIndex < 9));
   
   ihdl->pcmInfo.uSampleFreq = dafSampleFreq[pDecData->decHandle->sampleRateIndex];
   ihdl->pcmInfo.uChannel = pDecData->decHandle->CHNumber;
}

static OMX_ERRORTYPE DafDec_Process_Frame(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   DAF_DecData *pDecData = (DAF_DecData *)ihdl->pPrivateData;
   kal_uint8 *pRead, *pBsWrite, *pWrite;
   kal_uint32 uReadLen, uWriteLen;
   kal_uint32 uFreeSpace, uFreeWrite;
   int uConsume, uBytesAvailable;
   
   if ( (ihdl->Decode_EOF) || (ihdl->endStatus == MEDIA_TERMINATED) )
      return OMX_ErrorNone;
   
   // To fill bitstream buffer
   uFreeSpace = dafRbGetFreeSpace(pDecData);
   ACU_GetReadBuffer(hdl, &pRead, &uReadLen);
   while ( (uFreeSpace != 0) && (pRead != NULL) ) {
      kal_uint32 segment;
      
      // Move to bitstream buffer
      dafRbGetWriteBuffer(pDecData, &pBsWrite, &uFreeWrite);
      if (uReadLen > uFreeWrite)
         segment = uFreeWrite;
      else
         segment = uReadLen;
      // Check data amount
      if (segment != 0)
         memcpy(pBsWrite, pRead, segment);
      
      // Update pointer
      dafRbWriteDataDone(pDecData, segment);
      ACU_ReadDataDone(hdl, segment);

      // Get data count
      uFreeSpace = dafRbGetFreeSpace(pDecData);
      ACU_GetReadBuffer(hdl, &pRead, &uReadLen);
   };

   if(pDecData->fFirstDecode)
   {  // to prevent data less than mp3 framelength table 
      pDecData->fFirstDecode = KAL_FALSE;
      if(pDecData->uWrite < DAF_MIN_DECODER_INPUT_LEN)
      {
         pDecData->uWrite = DAF_MIN_DECODER_INPUT_LEN; 
         ASSERT(DAF_MIN_DECODER_INPUT_LEN<pDecData->bsSize - 1);
      }
   }

   if (dafRbGetDataCount(pDecData) == 0) {
      if (ihdl->isEOF) {
         OMX_BUFFERHEADERTYPE *pBufHdr;
         
         pBufHdr = ACU_GetBufferHeader(hdl, 1);
         if (pBufHdr != NULL) {
            ihdl->Decode_EOF = true;
            ACU_SetEOS(hdl);
            ACU_WriteDataDone_ImmediateCallback(hdl, 0);
         }
         return OMX_ErrorNone;
      } else {
         return OMX_ErrorUnderflow;
      }
   }
   
   // Check output data
   ACU_GetWriteBuffer(hdl, &pWrite, &uWriteLen);
   if (uWriteLen < DAF_DECODE_FRAME_LEN)
      return OMX_ErrorOverflow;
   
   // Decode a frame
   uBytesAvailable = dafRbGetDataCount(pDecData);
   if(uBytesAvailable<DAF_MIN_DECODER_INPUT_LEN && !ihdl->isEOF)
   {
      return OMX_ErrorUnderflow;
   }

   pRead = ((kal_uint8 *)pDecData->bs_buf) + pDecData->uRead;
   {
      kal_uint32 uBufSize;
      
      if (pDecData->uWrite >= pDecData->uRead) {
         uBufSize = pDecData->uWrite;
      } else {
         uBufSize = pDecData->bsSize;
      }
      uConsume = MP3Dec_Decode(pDecData->decHandle, (void *)pWrite, pDecData->bs_buf, uBufSize, pRead);
      kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_DEC_OK, MTKAUD_DECODER_DAF, uConsume,pDecData->decHandle->CHNumber, pDecData->decHandle->sampleRateIndex, uBytesAvailable,0,0,0);

      //for resume
      if ((pDecData->decHandle->CHNumber != -1) && (pDecData->decHandle->sampleRateIndex != -1))
      {
         ACU_SetResumePoint(ihdl->bsInfo.pResBuf, ihdl->bsInfo.uCurrentOffset, ihdl->bsInfo.uCurrentFrame);
         ihdl->bsInfo.uCurrentFrame++;
      }
      ihdl->bsInfo.uCurrentOffset += uConsume;
      //for resume end
   }
   
   // Check the consume of SWIP
   if ( (ihdl->isEOF) && ((uConsume >= uBytesAvailable) || (uConsume == 0)) ) {
      OMX_BUFFERHEADERTYPE *pBufHdr;
      
      pBufHdr = ACU_GetBufferHeader(hdl, 1);
      if (pBufHdr != NULL) {
         ihdl->Decode_EOF = true;
         ACU_SetEOS(hdl);
         ACU_WriteDataDone_ImmediateCallback(hdl, 0);
      }
      return OMX_ErrorNone;
   } else if (uConsume <= uBytesAvailable) {
      // Comcume the bitstream
      dafRbReadDataDone(pDecData, uConsume);
   }

   // Move to output buffer
   if ((pDecData->decHandle->CHNumber != -1) && (pDecData->decHandle->sampleRateIndex != -1)) {
      kal_uint32 uDataLen;
     
      pDecData->fDecoderSuccess = true;
      uDataLen = pDecData->decHandle->PCMSamplesPerCH * pDecData->decHandle->CHNumber * 2;
      dafDec_WritePcmInfo(ihdl);
      ACU_WriteDataDone(hdl, uDataLen);
   } else {
      pDecData->errorFrame++;
   }

   return OMX_ErrorNone;
}

#define DAF_DECODE_FRAME_NUMBER 6
#define DAF_ALLOW_ERROR_FRAME_NUMBER 4
#define DAF_VALID_THRESHOLD 50


static OMX_ERRORTYPE DafDec_SetParameter(AudComHdl *hdl, OMX_INDEXTYPE index, OMX_PTR pStruct)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   switch (index) {
      case OMX_IndexParamMediaTekPcmSink:
      {
         SinkParam *pParam = (SinkParam *)pStruct;
         pParam ->uSamplingFreq = ihdl->pcmInfo.uSampleFreq;
         pParam ->uChannelNum   = ihdl->pcmInfo.uChannel;
         break;
      }
      default:
         return OMX_ErrorNotImplemented;
   }
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE DafDec_Process(AudComHdl *hdl)
{
   int i;
   OMX_BUFFERHEADERTYPE *pBufHdr;
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   DAF_DecData *pDecData = (DAF_DecData *)ihdl->pPrivateData;
   
   if ( (ihdl->mediaStatus == COMPONENT_STATE_IDLE) || (ihdl->mediaStatus == COMPONENT_STATE_NONE) ) {
      dafDec_ResetMem(hdl);
      ihdl->mediaStatus = COMPONENT_STATE_READY_SET;
   }

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
   
   if ( (ihdl->Decode_EOF) || (ihdl->endStatus == MEDIA_TERMINATED) )
      return OMX_ErrorNone;

   ACU_LoadResumeInfo(hdl);
   
   for (i=0; i<DAF_DECODE_FRAME_NUMBER; i++) {
      DafDec_Process_Frame(hdl);
   }
   
   pBufHdr = ACU_GetBufferHeader(hdl, 1);
   if ((pBufHdr != NULL) && (pBufHdr->nFilledLen != 0)) {
      ACU_WriteDataDone_ImmediateCallback(hdl, 0);
   }
   
   if ( (pDecData->fDecoderSuccess == false) && (!ihdl->Decode_EOF) ) {
      kal_uint32 dataCount;
      
      dataCount = dafRbGetDataCount(pDecData);
      if ( (pDecData->errorFrame >= DAF_ALLOW_ERROR_FRAME_NUMBER) ||
           (ihdl->isEOF && (dataCount < DAF_VALID_THRESHOLD) ) ) {
      
         ihdl->Decode_EOF = true;
         mhdlException( ihdl->mhdl, MEDIA_END );
      }
   }
   
   return OMX_ErrorNone;
}

/*------------------------------------------------*/
/* The public functions of DAF decoder.           */
/*------------------------------------------------*/
OMX_U32 DafDec_GetMemSize( void )
{
   OMX_U32 uTempSize, uReqSizeTotal;
   int int_buf_size, tmp_buf_size, bs_buf_size, pcm_buf_size;

   uReqSizeTotal = 0;
   
   // The memory size for AudComHdlInt
   uTempSize = (sizeof(AudComHdlInt) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   
   // The memory for DAF private data
   uTempSize = (sizeof(DAF_DecData) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   
   // The memory for AMR decoder SWIP
   MP3Dec_GetMemSize(&bs_buf_size, &pcm_buf_size, &int_buf_size, &tmp_buf_size);
   int_buf_size = (int_buf_size + 3) & ~0x3;
   tmp_buf_size = (tmp_buf_size + 3) & ~0x3;
   bs_buf_size = (bs_buf_size + 3) & ~0x3;
   uReqSizeTotal += int_buf_size + tmp_buf_size + bs_buf_size;
   
   return uReqSizeTotal;
}


OMX_ERRORTYPE DafDec_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
)
{
   //OMX_U32 uBufSize;
   AudComHdlInt *ihdl;
   kal_uint8 *pBuffer8;
   
   *pHandle = NULL;
   
   // The buffer address should be 4 bytes aligned
   ASSERT( (((kal_uint32)pBuffer) & 0x3) == 0);
     
   // Assign and distribute the memory
   *pHandle = pBuffer;
   pBuffer8 = (kal_uint8 *)pBuffer;
   ihdl = (AudComHdlInt *)pBuffer;
   pBuffer8 += (sizeof(AudComHdlInt) + 3) & ~0x3;
   ihdl->pPrivateData = (void *)pBuffer8;
   pBuffer8 += (sizeof(DAF_DecData) + 3) & ~0x3;
   // Assign for MP3 SWIP
   {
      int int_buf_size, tmp_buf_size, bs_buf_size, pcm_buf_size;
      DAF_DecData *pDecData = (DAF_DecData *)ihdl->pPrivateData;
      
      MP3Dec_GetMemSize(&bs_buf_size, &pcm_buf_size, &int_buf_size, &tmp_buf_size);
      pDecData->w1Size  = int_buf_size;
      pDecData->w2Size  = tmp_buf_size;
      pDecData->bsSize  = bs_buf_size;
      
      int_buf_size = (int_buf_size + 3) & ~0x3;
      tmp_buf_size = (tmp_buf_size + 3) & ~0x3;
      bs_buf_size = (bs_buf_size + 3) & ~0x3;
   
      pDecData->work1_buf = (void *)pBuffer8;
      pBuffer8 += int_buf_size;
      pDecData->work2_buf = (void *)pBuffer8;
      pBuffer8 += tmp_buf_size;
      pDecData->bs_buf = (void *)pBuffer8;
      pBuffer8 += bs_buf_size;
   }
   
   ihdl->mediaType = MEDIA_FORMAT_DAF;
   ihdl->isProcessDone = KAL_FALSE;
   // Initialize the audio handler as default setting
   ACU_InitHdl(*pHandle, pFWData, pCallback);
   
   // Overwrite the member functions
   ihdl->basic.Start = DafDec_Start;
   ihdl->basic.Stop = DafDec_Stop;
   ihdl->basic.Process = DafDec_Process;
   ihdl->basic.SetParameter = DafDec_SetParameter;
   ihdl->basic.Deinit = ACU_GenDeinit;

   // Obtain l1audio service
   // KH: should re-organize
   AFE_SetDigitalGain( L1SP_AUDIO, 100 );
   AFE_SetDigitalGain( L1SP_VOICE, 100 );

   return OMX_ErrorNone;
}

#endif
