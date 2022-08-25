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
 *   WavParser.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   WAV parser component
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


#if defined(__DRA_DECODE_SUPPORT__)

extern AST_Status draParseFrame(void *hdlptr, kal_uint32 *CurOffset, kal_uint32 *ParseFrameNum);

kal_bool draParSeek( AudComHdl *hdl, kal_bool bEnableAST )
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   WAV_ParData *pParData = (WAV_ParData *)ihdl->pPrivateData;
   MHPB_Internal *pPBhdl = (MHPB_Internal *)ihdl->mhdl;
   kal_uint32 CurFrames, StartFrame, uFrameDur = 0;

   if(!pParData->pDecHdl->sample_rate)
   {
      return KAL_FALSE;
   }
   
   uFrameDur = (kal_uint32)((kal_int64)1024 * 1000000000 / pParData->pDecHdl->sample_rate);
   StartFrame = (kal_uint64)pPBhdl->mh.start_time * 1000000 / uFrameDur;

   CurFrames=StartFrame;

   if(bEnableAST && pPBhdl->AudioSeekTbl && pPBhdl->AudioSeekTbl->CurrentIndex!=1)
   {
      pParData->uOffset=AST_Seek(ihdl->mhdl, pPBhdl->AudioSeekTbl, &CurFrames);
   }
   else
   {
      draParseFrame(ihdl->mhdl, &pParData->uOffset, &CurFrames);
   }
   pPBhdl->mh.start_time = (kal_uint32)((kal_uint64)CurFrames * uFrameDur / 1000000); // update start time 
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SEEK, MTKAUD_PARSER_DRA, StartFrame,CurFrames,pPBhdl->mh.start_time,pParData->uOffset,0,0);
   if (CurFrames != StartFrame)
   {
      return KAL_FALSE;
   }
   else
   {
      return KAL_TRUE;
   }

}


kal_bool draParSeekWithResume( AudComHdl *hdl )
{   
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   WAV_ParData *pParData = (WAV_ParData *)ihdl->pPrivateData;
   kal_uint32 uResumeFrame, uPauseFrame, uJumpFrame;

   if(ihdl->bsInfo.uFrameDur==0)
   {
      return KAL_FALSE;
   }

   uResumeFrame = (kal_uint64)ihdl->mhdl->start_time * 1000000 / ihdl->bsInfo.uFrameDur;

   ACU_GetResumePoint(&pParData->ResBuf, &pParData->uOffset, &uPauseFrame);

   if(uPauseFrame<uResumeFrame)
   {
      uJumpFrame = uResumeFrame - uPauseFrame;
      draParseFrame(ihdl->mhdl, &pParData->uOffset, &uJumpFrame);
      uPauseFrame += uJumpFrame;
   }
   ihdl->mhdl->start_time = (kal_uint32)((kal_uint64)uPauseFrame * ihdl->bsInfo.uFrameDur / 1000000); // update start time 
   return KAL_TRUE;
}


#endif


static OMX_ERRORTYPE WAV_PutToBuffer_8bit(AudComHdl *hdl, kal_uint8 *pSrcBuf, kal_uint32 *ulength, kal_uint32 uThreshold)
{

   OMX_U32 bsLength = *ulength;
   OMX_U32 bufDataSize, dataCount;
   OMX_U8 *pBuf;
   OMX_U16 *pBuf16;
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   OMX_BUFFERHEADERTYPE *pBufHdr;
   kal_int32 i = 0;
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

   pBuf16 = (OMX_U16 *)pBuf;
   pBufHdr = ihdl->OutputQ.pCurBufHdr;
   
   // Compare the data count
   if (bsLength*2 >= bufDataSize)
      dataCount = bufDataSize;
   else
      dataCount = bsLength*2;

   dataCount = (dataCount>>2)<<2;

   for(i = dataCount >> 1 ; i >=0 ; i--)
   {
      kal_uint16 uSample;
      uSample = ((kal_uint16)(*pSrcBuf++)<<8)-0x8000;
      *pBuf16++ = uSample;
   }
   *ulength = dataCount>>1;

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

OMX_ERRORTYPE WavPar_Process_internal(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   WAV_ParData *pParData = (WAV_ParData *)ihdl->pPrivateData;

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PROCESS_I, MTKAUD_PARSER_WAV, ihdl->mediaStatus, ihdl->Decode_EOF,0,0,0,0);
   if(ihdl->mediaStatus != COMPONENT_STATE_PLAY || ihdl->Decode_EOF)
      return OMX_ErrorNone;

   if(WAV_FORMAT_DRA == pParData->pDecHdl->format && pParData->pstFSAL)
   {
      // for DRA File Pause/Resume
      OMX_BUFFERHEADERTYPE *pBufHdr;
      pBufHdr = ACU_GetBufferHeader(hdl, 1);
      if(pBufHdr)
      {
         pBufHdr->pOutputPortPrivate = &ihdl->bsInfo;
      }
   }
   
   if(pParData->pstFSAL)
   {
      // File Playback, DRA/WAV
      OMX_ERRORTYPE result;
      
      result = ACU_FileReadGeneral(hdl, pParData->pstFSAL, &pParData->uOffset, pParData->uEOSOffset);
      if(ihdl->isEOF)
      {
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_EOF, MTKAUD_PARSER_WAV, 0,0,0,0,0);
         ihdl->Decode_EOF = KAL_TRUE;
      }
      return result;
   }
   else
   {
      kal_bool fByte2Word = KAL_FALSE;
      if((pParData->bIsPCMStreaming) && (pParData->pcmInfo.BitsPerSample == 8))
      {
         fByte2Word = KAL_TRUE;
      }
   
      // DRA streaming, pcm(word) Streaming
      {
         MHdl *medhdl = (MHdl *)ihdl->mhdl;  
         kal_uint8 *pBuf;
         kal_uint32 bsLen, i;
         for(i=0;i<2;i++)
         {
            medhdl->GetReadBuffer(medhdl, &pBuf, &bsLen);
            kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PAR_OK, MTKAUD_PARSER_WAV, ihdl->mhdl->eof, bsLen,pBuf,0,0,0);
            bsLen &= 0xFFFFFFFE;
            if((ihdl->mhdl->eof||bsLen) && pBuf)
            {
               if(fByte2Word)
               {
                  WAV_PutToBuffer_8bit(hdl, pBuf, &bsLen, WAVDEC_PARSER_BUFSIZE/4);
               }
               else
               {
                  ACU_PutToBuffer_Threshold(hdl, pBuf, &bsLen, WAVDEC_PARSER_BUFSIZE/4);
               }
               medhdl->ReadDataDone(medhdl, bsLen);
               if(ihdl->isEOF)
               {
                  kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_EOF, MTKAUD_PARSER_WAV, 0,0,0,0,0);
               }
            }
         }
      }
   }
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE WavPar_Process(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   WAV_ParData *pParData = (WAV_ParData *)ihdl->pPrivateData;
   MHdl *pMedHdl = (MHdl *)ihdl->mhdl;

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PROCESS, MTKAUD_PARSER_WAV, pMedHdl->waiting, ihdl->Decode_EOF,0,0,0,0);
   if (ihdl->Decode_EOF)
   {
      return OMX_ErrorNone;
   }
   if(pParData->pstFSAL == NULL)
   {
      mhdlRefillAndUpdateVideoBuffer(pMedHdl);
      WavPar_Process_internal(hdl);
   }
   if(!pMedHdl->waiting && pMedHdl->pStrmStruct==NULL )
   {
      pMedHdl->handler( pMedHdl, MEDIA_DATA_REQUEST );
      pMedHdl->waiting = KAL_TRUE;   
   }
   return OMX_ErrorNone;
}

/*------------------------------------------------*/
/* The private member functions of Wav parser.    */
/*------------------------------------------------*/
static OMX_ERRORTYPE WavPar_Start(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   WAV_ParData *pParData = (WAV_ParData *)ihdl->pPrivateData;
   MHdl *medhdl = (MHdl *)ihdl->mhdl;
   MHPB_Internal *pPBhdl = (MHPB_Internal *)ihdl->mhdl;
   WAV_STATUS   ParStatus = WAV_SUCCESS;
   
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_START, MTKAUD_PARSER_WAV, ihdl->mediaStatus,0,0,0,0);
   ASSERT(ihdl->mediaStatus != COMPONENT_STATE_PLAY);
   memset(pParData->pWorkBuf, 0, pParData->uWorkBufSize);

   {
      //reset data
      ihdl->endStatus = MEDIA_NONE;
      ihdl->isEOF = KAL_FALSE;
      ihdl->Decode_EOF = KAL_FALSE;
      pParData->uOffset = 0;
      pParData->uFileSize = 0;
      pParData->uEOSOffset = 0xFFFFFFFF;

   }

   if(pParData->bIsDraStreaming == KAL_TRUE)
   {

   }
   else if(pParData->bIsPCMStreaming == KAL_TRUE)
   {
      if(pParData->pcmInfo.BitsPerSample != 8 && pParData->pcmInfo.BitsPerSample != 16)
      {
         return OMX_ErrorUndefined;
      }         
   }
   else
   {
      pParData->pDecHdl = WAV_InitDecoder(pParData->pWorkBuf);
      if(pParData->pcmInfo.FormatTag)
      {
         ParStatus = WAV_FillPCMParam(pParData->pDecHdl, &pParData->pcmInfo);  
      }
      else
      {
         kal_uint32 uConsume = 0, uDataInBuf=0, uReadFromFile = 0, iSearchTime;
         iSearchTime = WAVPAR_MAX_DATA_SEARCH_TIME;
         FSAL_GetFileSize(pParData->pstFSAL, &pParData->uFileSize);
         while(iSearchTime--)
         {
            if(uConsume)
            {
               uDataInBuf -= uConsume;
               uReadFromFile = pParData->uBsBufSize - uDataInBuf;
               memcpy(pParData->pBsBuf, pParData->pBsBuf+uConsume, uDataInBuf);
               ACU_GetBytesFromFile(pParData->pstFSAL, &pParData->uOffset, &uReadFromFile, pParData->pBsBuf+uDataInBuf);
               uDataInBuf += uReadFromFile;  
            }
            else
            {
               uReadFromFile = pParData->uBsBufSize; 
               ACU_GetBytesFromFile(pParData->pstFSAL, &pParData->uOffset, &uReadFromFile, pParData->pBsBuf);
               uDataInBuf = uReadFromFile;
            }
            uConsume = 0;
            pParData->uOffset+=uReadFromFile;
            ParStatus = WAV_ParseHeader(pParData->pDecHdl, pParData->pBsBuf, uDataInBuf, &uConsume);
            switch( pParData->pDecHdl->sample_rate / 1000 )
            {
               case 7: case 8:   
                  pParData->pDecHdl->sample_rate = 8000;
                  break;
               case 10: case 11: 
                  pParData->pDecHdl->sample_rate = 11025;
                  break;
               case 12:          
                  pParData->pDecHdl->sample_rate = 12000;
                  break;
               case 15: case 16: 
                  pParData->pDecHdl->sample_rate = 16000;
                  break;
               case 21: case 22: 
                  pParData->pDecHdl->sample_rate = 22050;
                  break;
               case 23: case 24: 
                  pParData->pDecHdl->sample_rate = 24000;
                  break;
               case 31: case 32: 
                  pParData->pDecHdl->sample_rate = 32000;
                  break;
               case 43: case 44: 
                  pParData->pDecHdl->sample_rate = 44100;
                  break;
               case 47: case 48: 
                  pParData->pDecHdl->sample_rate = 48000;
                  break;
               default:
                  //return OMX_ErrorUndefined;
            }
            if(WAV_REFILL_INBUF != ParStatus || uReadFromFile == 0)
            {
               pParData->uOffset = pParData->pDecHdl->data_offset;
               pParData->uEOSOffset = pParData->pDecHdl->data_offset + pParData->pDecHdl->data_chunk_length;
               break;
            }
         }
      }
      if(ParStatus != WAV_SUCCESS) 
      {
         // The string is wrong or unsupport
         ihdl->callbacks->EventHandler(hdl, ihdl->pFWData, OMX_EventError, 0, 0, (void *)0);
         return OMX_ErrorUndefined;
      }

      if(WAV_FORMAT_DRA == pParData->pDecHdl->format )
      {
#if defined(__DRA_DECODE_SUPPORT__)
         if(medhdl->bIsPause && pPBhdl->AudioSeekTbl==NULL)
         {
            medhdl->bIsPause = KAL_FALSE;
            if(KAL_TRUE != draParSeekWithResume(hdl))
            {
               return OMX_ErrorContentEndOfFile;
            }
         }
         else if(KAL_TRUE != draParSeek(hdl, KAL_TRUE))
         {
            return OMX_ErrorContentEndOfFile;
         }
         //for resume
         if(pParData->pDecHdl->sample_rate)
         {
            ihdl->bsInfo.uFrameDur = (kal_uint32)((kal_int64)1024 * 1000000000 / pParData->pDecHdl->sample_rate);
            ihdl->bsInfo.uCurrentFrame = (kal_uint32)((kal_uint64)medhdl->start_time * 1000000 / ihdl->bsInfo.uFrameDur);
         }
         ihdl->bsInfo.uCurrentOffset = pParData->uOffset; 
         ihdl->bsInfo.pResBuf = &pParData->ResBuf; 
         {
            OMX_BUFFERHEADERTYPE *pBufHdr;
            pBufHdr = ACU_GetBufferHeader(hdl, 1);
            if(pBufHdr)
            {
               pBufHdr->pOutputPortPrivate = &ihdl->bsInfo;
            }
         }
         //for resume end
#else
         ihdl->callbacks->EventHandler(hdl, ihdl->pFWData, OMX_EventError, 0, 0, (void *)0);
         return OMX_ErrorUndefined;
#endif
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_START_TIME_OFFSET, MTKAUD_PARSER_WAV, medhdl->start_time, pParData->uOffset,0,0,0,0);
      }
      else if(!pParData->pcmInfo.FormatTag)
      { 
         medhdl->bIsPause = KAL_FALSE;
         pParData->uOffset = WAV_Seek(pParData->pDecHdl, &medhdl->start_time);
         if(pParData->uOffset==0xFFFFFFFF)
         {
            return OMX_ErrorContentEndOfFile;
         }
         pParData->uOffset+=pParData->pDecHdl->data_offset; 
         if(pParData->uOffset>=pParData->uFileSize || pParData->uOffset >= pParData->uEOSOffset)
         {
            return OMX_ErrorContentEndOfFile;
         }
         if(medhdl->start_time && pParData->uEOSOffset-pParData->uOffset<256) //prevent seek to last sample, and sounds like pop up noise
         {
            return OMX_ErrorContentEndOfFile;
         }
      }
      kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_START_TIME_OFFSET, MTKAUD_PARSER_WAV, medhdl->start_time, pParData->uOffset,0,0,0,0);
   }
   // To execute process function in advance to avoid buffer underflow in the next stage
   ihdl->mediaStatus = COMPONENT_STATE_PLAY;
   if(pParData->pstFSAL)
   {
      kal_uint32 I;
      kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_START_TIME_OFFSET, MTKAUD_PARSER_WAV, medhdl->start_time, pParData->uOffset,0,0,0,0);
      for (I=0; I<WAVDEC_PARSER_BUFNUM; I++) 
      {
         WavPar_Process_internal(hdl);
      }
   }
   else
   {
      ACU_SendProcessCommandl( (AudComHdlInt *)hdl );
   }
   return OMX_ErrorNone;
}


static OMX_ERRORTYPE WavPar_SetParameter(AudComHdl *hdl, OMX_INDEXTYPE index, OMX_PTR pStruct)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   WAV_ParData *pParData = (WAV_ParData *)ihdl->pPrivateData;

   switch(index)
   {
      case OMX_IndexParamMedFileHandle:
      {
         AcuParseParam *pParam = (AcuParseParam *)pStruct;
         pParData->pstFSAL = pParam->pstFSAL;
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SETPARAM, MTKAUD_PARSER_WAV, 0, pParData->pstFSAL ,0,0,0);
         break;
      }
      case OMX_IndexParamAudioPcm:
      {
         PCM_PARAM *pParam = (PCM_PARAM *)pStruct;
         pParData->pcmInfo.DataLength      = pParam->DataLength;
         pParData->pcmInfo.ChannelNum      = pParam->ChannelNum;
         pParData->pcmInfo.SampleRate      = pParam->SampleRate;
         pParData->pcmInfo.FormatTag       = pParam->FormatTag;
         pParData->pcmInfo.BitsPerSample   = pParam->BitsPerSample;
         pParData->pcmInfo.SamplesPerBlock = pParam->SamplesPerBlock;
         pParData->pcmInfo.BlockAlign      = pParam->BlockAlign;
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SETPARAM, MTKAUD_PARSER_WAV, 1, pParam->DataLength ,pParam->ChannelNum,pParam->SampleRate,0);
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SETPARAM, MTKAUD_PARSER_WAV, 2, pParam->FormatTag ,pParam->BitsPerSample,pParam->SamplesPerBlock,pParam->BlockAlign);

         break;
      }
      case OMX_IndexParamMediaTekPcmSink:
      {
         SinkParam *pParam = (SinkParam *)pStruct;
         pParam ->uSamplingFreq = pParData->pDecHdl->sample_rate;
         pParam ->uChannelNum   = pParData->pDecHdl->channel_num;
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SETPARAM, MTKAUD_PARSER_WAV, 3, pParam->uSamplingFreq ,pParam->uChannelNum,0,0);
         break;
      }
      case OMX_IndexParamMediaTekWavDecSWIPHdl:
      {
         WAV_Par2DecInfo *pParam = (WAV_Par2DecInfo *)pStruct;
         pParam->pDecHdl = pParData->pDecHdl;
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SETPARAM, MTKAUD_PARSER_WAV, 5, pParData->pDecHdl ,0,0,0);
         break;
      }
      case OMX_IndexParamMediaAudioPCMStreaming:
      {
         PCM_PARAM *pParam = (PCM_PARAM *)pStruct;
         pParData->bIsPCMStreaming = KAL_TRUE;
         pParData->pcmInfo.DataLength      = pParam->DataLength;
         pParData->pcmInfo.ChannelNum      = pParam->ChannelNum;
         pParData->pcmInfo.SampleRate      = pParam->SampleRate;
         pParData->pcmInfo.FormatTag       = pParam->FormatTag;
         pParData->pcmInfo.BitsPerSample   = pParam->BitsPerSample;
         pParData->pcmInfo.SamplesPerBlock = pParam->SamplesPerBlock;
         pParData->pcmInfo.BlockAlign      = pParam->BlockAlign;
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SETPARAM, MTKAUD_PARSER_WAV, 6, pParam->DataLength ,pParam->ChannelNum,pParam->SampleRate,0);
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SETPARAM, MTKAUD_PARSER_WAV, 7, pParam->FormatTag ,pParam->BitsPerSample,pParam->SamplesPerBlock,pParam->BlockAlign);
         break;
      }
#if defined(__DRA_DECODE_SUPPORT__)      
      case OMX_IndexParamMediaAudioDRA:
      {
         pParData->bIsDraStreaming = KAL_TRUE;
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SETPARAM, MTKAUD_PARSER_WAV, 8, pParData->pDecHdl ,0,0,0);
         break;
      }
#endif      
      default:
         return OMX_ErrorNotImplemented;
   }
   return OMX_ErrorNone;
}

/*------------------------------------------------*/
/* The public functions of WAV parser.            */
/*------------------------------------------------*/
OMX_U32 WavPar_GetMemSize( void )
{
   OMX_U32 uTempSize, uReqSizeTotal;
   OMX_U32 uBsBufSize, uPcmBufSize, uWorkBufSize;

   uReqSizeTotal = 0;
   
   // The memory size for AudComHdlInt
   uTempSize = (sizeof(AudComHdlInt) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   
   // The memory for WAV private data
   uTempSize = (sizeof(WAV_ParData) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;

   WAV_GetDecBufferSize( WAVDEC_BS_SIZE, &uPcmBufSize, &uWorkBufSize);

   uBsBufSize     = WAVDEC_BS_SIZE;
   uPcmBufSize    = 0;//(uPcmBufSize    + 3) & ~0x3;
   uWorkBufSize   = (uWorkBufSize   + 3) & ~0x3;
   uReqSizeTotal += uBsBufSize + uPcmBufSize + uWorkBufSize;

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_GETMEMSIZE, MTKAUD_PARSER_WAV, uReqSizeTotal,0,0,0,0,0);
   return uReqSizeTotal;
   
}

OMX_ERRORTYPE WavPar_Init(
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
   uBufSize = WavPar_GetMemSize();
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
   ihdl->basic.Start        = WavPar_Start;
   ihdl->basic.Process      = WavPar_Process;
   ihdl->basic.SetParameter = WavPar_SetParameter;
   ihdl->basic.Stop         = ACU_ParGenStop;
   ihdl->basic.Deinit       = ACU_GenDeinit;

   {
      WAV_ParData *pParData = (WAV_ParData *)ihdl->pPrivateData;
      OMX_U32 uBsBufSize, uPcmBufSize, uWorkBufSize, uParStructSize;
      kal_uint8 *privatebuf = (kal_uint8 *)ihdl->pPrivateData;
      pParData->uTotalDecSamples = 0;
      memset(pParData, 0, sizeof(WAV_ParData));

      WAV_GetDecBufferSize( WAVDEC_BS_SIZE, &uPcmBufSize, &uWorkBufSize);
      uParStructSize = (sizeof(WAV_ParData) + 3) & ~0x3;
      uBsBufSize     = WAVDEC_BS_SIZE;
      uPcmBufSize    = 0;//(uPcmBufSize    + 3) & ~0x3;
      uWorkBufSize   = (uWorkBufSize   + 3) & ~0x3;

      privatebuf+=uParStructSize;
      pParData->pWorkBuf = (void *)privatebuf;
      privatebuf+=uWorkBufSize;
      pParData->pBsBuf = (void *)privatebuf;
      pParData->uBsBufSize = uBsBufSize;
      pParData->uWorkBufSize = uWorkBufSize;
   }
   // Obtain l1audio service
   ihdl->mediaStatus = COMPONENT_STATE_READY;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_INIT, MTKAUD_PARSER_WAV, ihdl->mediaStatus,0,0,0,0);
   return OMX_ErrorNone;
}

#endif
