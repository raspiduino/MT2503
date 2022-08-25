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
 *  wav_drv.c
 *
 * Project:
 * --------
 *  Maui_sw
 *
 * Description:
 * ------------
 *  WAV playback Cilent
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(__WAV_DECODE_SWIP__)

#include "audio_enum.h"
#include "kal_trace.h"
#include "MedAdapt.h"
#include "l1sp_trc.h"
#include "AudComUtil.h"
#include "WAV_codec.h"
#include "l1audio.h"
#include "media.h"
#include "common_def.h"
#include "pcmsink.h"

#if defined(__DRA_DECODE_SUPPORT__)
#include "DRA_codec.h"
#endif

#define WAV_CILENT_UNKNOW     0
#define WAV_CILENT_WAV_FILE   1
#define WAV_CILENT_PCM_FILE   2
#define WAV_CILENT_PCM_STRM   3
#define WAV_CILENT_DRA_FILE   4
#define WAV_CILENT_DRA_STRM   5

#define WAV_CILENT_PDL_PREBUFFER_TIME   10000

static WAV_STATUS wavSearchHeader(STFSAL *pstFSAL, WAV_DEC_HDL **pRetWavHdl, kal_uint8 **pRetWorkBuf, kal_uint8 **pRetBsBuf)
{
   kal_int32 iSearchTime;
   kal_uint32 uWorkBufSize=0, uBsBufSize=0, uPcmBufSize=0, uConsume=0, uReadFromFile=0, uOffset=0;
   kal_uint8 *pWorkBuf, *pBsBuf;
   WAV_DEC_HDL *pWavHdl;
   WAV_STATUS ParStatus = WAV_SUCCESS;
   kal_int32 uDataInBuf=0;
   
   iSearchTime = WAVPAR_MAX_DATA_SEARCH_TIME;
   uBsBufSize = 1024;
   WAV_GetDecBufferSize(uBsBufSize, &uPcmBufSize, &uWorkBufSize);
   *pRetWorkBuf = pWorkBuf = (kal_uint8 *)get_ctrl_buffer( uWorkBufSize );
   *pRetBsBuf = pBsBuf   = (kal_uint8 *)get_ctrl_buffer( uBsBufSize );
   memset(pWorkBuf, 0, uWorkBufSize);
   memset(pBsBuf, 0, uBsBufSize);
   
   *pRetWavHdl = pWavHdl = WAV_InitDecoder(pWorkBuf);
   
   while(iSearchTime--)
   {
      if(uConsume)
      {
         uDataInBuf -= uConsume;
         uReadFromFile = uBsBufSize - uDataInBuf;
         memcpy(pBsBuf, pBsBuf+uConsume, uDataInBuf);
         ACU_GetBytesFromFile(pstFSAL, &uOffset, &uReadFromFile, pBsBuf+uDataInBuf);
         uDataInBuf += uReadFromFile;  
      }
      else
      {
         uReadFromFile = uBsBufSize; 
         ACU_GetBytesFromFile(pstFSAL, &uOffset, &uReadFromFile, pBsBuf);
         uDataInBuf = uReadFromFile;
      }
      uConsume = 0;
      uOffset+=uReadFromFile;
      ParStatus = WAV_ParseHeader(pWavHdl, pBsBuf, uDataInBuf, &uConsume);
      if(WAV_REFILL_INBUF != ParStatus || uReadFromFile == 0)
      {
         break;
      }
   }

   return ParStatus;   
}

static Media_Status wavGetFileInfo( STFSAL *pstFSAL, WAV_FileInfo *info)
{
   kal_uint8 *pWorkBuf, *pBsBuf;
   WAV_DEC_HDL *pWavHdl;
   WAV_STATUS ParStatus;

   ParStatus = wavSearchHeader(pstFSAL, &pWavHdl, &pWorkBuf, &pBsBuf);
   
   if(WAV_SUCCESS == ParStatus)
   {
      info->format = pWavHdl->format;    
      info->uDataChunkOffset = pWavHdl->data_offset;    
      info->uDataLength = pWavHdl->data_chunk_length;    
      info->uBitRate = pWavHdl->bit_rate;    
      info->uTotalDuration = pWavHdl->total_duration; 
      info->uSampleRate = pWavHdl->sample_rate; 
      info->uChannelNum = pWavHdl->channel_num;
   }
   free_ctrl_buffer(pWorkBuf);
   free_ctrl_buffer(pBsBuf);
   if(WAV_SUCCESS != ParStatus)
   {
      return MEDIA_FAIL;
   }
   return MEDIA_SUCCESS;
}

static Media_Status wavMedReachValidRegion( MHdl *hdl )
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   kal_uint32 uFileSize=0, uOffset=0;
   kal_uint8 *pWorkBuf, *pBsBuf;
   WAV_DEC_HDL *pWavHdl;
   kal_uint32 uStartTime;
   Media_Status retStatus = MEDIA_SUCCESS;

   wavSearchHeader(ihdl->pstFSAL, &pWavHdl, &pWorkBuf, &pBsBuf);

   if (pWavHdl->format == WAV_FORMAT_DRA) {
      retStatus = MEDIA_SUCCESS;
   } else {
      uStartTime = hdl->start_time + WAV_CILENT_PDL_PREBUFFER_TIME;
      uOffset = WAV_Seek(pWavHdl, &uStartTime);
      if (uOffset==0xFFFFFFFF) {
         retStatus = MEDIA_FILE_INCOMPLETE;
      } else {
         uOffset+=pWavHdl->data_offset; 
         FSAL_GetFileSize(ihdl->pstFSAL, &uFileSize);
         if (uOffset>=uFileSize) {
            retStatus = MEDIA_FILE_INCOMPLETE;
         }
      }
   }
   free_ctrl_buffer(pWorkBuf);
   free_ctrl_buffer(pBsBuf);
   
   return retStatus;
}

Media_Status PCM_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param )
{
   kal_uint32 file_size;
   Media_Format eFormat;

   memset(contentInfo, 0, sizeof(audInfoStruct));
   contentInfo->sampleRate = 8000;

   eFormat = (Media_Format) ((kal_uint32)param);
   FSAL_GetFileSize(pstFSAL, &file_size);
   switch (eFormat) {
      case MEDIA_FORMAT_DVI_ADPCM:
         contentInfo->time = (file_size >> 2);
         contentInfo->bitRate = 32000;
         break;
      case MEDIA_FORMAT_G711_ALAW:
      case MEDIA_FORMAT_G711_ULAW:
         contentInfo->time = (file_size >> 3);
         contentInfo->bitRate = 64000;
         break;
      case MEDIA_FORMAT_PCM_8K:
         contentInfo->time = (file_size >> 4);
         contentInfo->bitRate = 128000;
         break;
      case MEDIA_FORMAT_PCM_16K:
         contentInfo->sampleRate = 16000;
         contentInfo->time = (file_size >> 5);
         contentInfo->bitRate = 256000;
      default:
         ASSERT(0);
   }
   return MEDIA_SUCCESS;
}

kal_bool WAV_IsPPSupport(STFSAL *pstFSAL)
{
   return KAL_TRUE;
}

Media_Status WAV_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param )
{
   WAV_FileInfo info;

   memset(contentInfo, 0, sizeof(audInfoStruct));
   if(MEDIA_SUCCESS != wavGetFileInfo(pstFSAL, &info))
   {
      return MEDIA_FAIL;
   }
   contentInfo->sampleRate = info.uSampleRate;
   contentInfo->time = info.uTotalDuration;
   contentInfo->bitRate = info.uBitRate;
   if( 2 == info.uChannelNum)
   {
      contentInfo->stereo = KAL_TRUE;
   }
   return MEDIA_SUCCESS;
}

/*
Media_Status WAV_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param )
{
   return autGetID3MetaData(filename, pbBuf, uSize, contentInfo, param, WAV_GetContentDescInfo);
}
*/

Media_Status AU_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param )
{
   return WAV_GetContentDescInfo( pstFSAL, contentInfo, param );
}

/*
Media_Status AU_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param )
{
   return autGetID3MetaData(filename, pbBuf, uSize, contentInfo, param, WAV_GetContentDescInfo);
}
*/

Media_Status AIFF_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param )
{
   return WAV_GetContentDescInfo( pstFSAL, contentInfo, param );
}

/*
Media_Status AIFF_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param )
{
   return autGetID3MetaData(filename, pbBuf, uSize, contentInfo, param, WAV_GetContentDescInfo);
}
*/

#if defined(__DRA_DECODE_SUPPORT__)

extern OMX_U32 dra_SyncFrame(kal_bool bIsDraStreaming, OMX_U8 *pBsbuf, OMX_U32 uBsbufLen, OMX_U32* pFrameLen, OMX_U32* pOffset);

AST_Status draParseFileHeader(void *hdlptr, kal_uint32 *FirstFrameOffset, kal_uint32 *uFrameDur)
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdlptr;
   WAV_FileInfo info;
   if(MEDIA_SUCCESS != wavGetFileInfo(ihdl->pstFSAL, &info))
   {
      *FirstFrameOffset = 0;
      return AST_PARSE_FILE_HEADER_FAIL;
   }

   *uFrameDur =  (kal_uint32)((kal_int64)1024 * 1000000000 / info.uSampleRate);
   *FirstFrameOffset = info.uDataChunkOffset;
   return AST_SUCCESS;
}

AST_Status draParseFrame(void *hdlptr, kal_uint32 *CurOffset, kal_uint32 *ParseFrameNum)
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdlptr;
   MHdl *hdl = &ihdl->mh; 
   AST_Status ParseResult=AST_SUCCESS;
   kal_uint32 AccOffset;
   kal_uint32 Remains;
   kal_uint32 uBufLen;
   kal_uint8  *pBuf;


   if(hdl->rbInfo.rb_base == NULL)
   {
      uBufLen = SEEK_TABLE_BS_BUFFER_LEN;
      pBuf = (kal_uint8 *)audio_alloc_mem_cacheable(uBufLen);
      ASSERT(pBuf);
   }
   else
   {
      hdl->GetWriteBuffer(hdl, &pBuf, &uBufLen );
   }

   AccOffset = *CurOffset;
   Remains=*ParseFrameNum;
   while(Remains!=0)
   {
      kal_uint32 num_bytes = 0, frameLen = 0, uOffset = 0;
      //kal_uint16 sync, msg;
      num_bytes = autGetBytesFromFileNoEnd((MHdl *)ihdl, ihdl->pstFSAL, AccOffset, 4, pBuf);
      if(num_bytes <4 )
      {
         ParseResult = AST_EOF;
         break;
      }
      if(OMX_ErrorNone != dra_SyncFrame(KAL_FALSE, pBuf, 4, &frameLen, &uOffset))
      {
         ParseResult = AST_PARSE_FRAME_FAIL;
         break;
      }
      AccOffset+=frameLen + uOffset;
      Remains--;
   }
   *CurOffset=AccOffset;
   *ParseFrameNum -= Remains;
   if(hdl->rbInfo.rb_base == NULL)
   {
      audio_free_mem( (void **) &pBuf);
   }
   return ParseResult;
}

void draMedSetCacheTbl( MHdl *hdl, kal_uint8 *ptr, kal_uint32 usize )
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   /* make sure 4-byte alignment */
   ASSERT(((uint32)ptr & 0x03) == 0 );
   ihdl->AudioSeekTbl = (AudioSeekTable *)ptr;

   if(ihdl->AudioSeekTbl->CurrentIndex==0)
   {
      AST_InitTable(ihdl->AudioSeekTbl,DRA_AST_MIN_ENTRY_SIZE,usize,draParseFrame,draParseFileHeader);
   }
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_SET_AST, hdl, ptr, usize);
}

void draMedBuildCache( MHdl *hdl, Media_Status *eLastRet, kal_uint32 *uProgress, kal_bool fLimitFrameNumber)
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   AST_Status ParseResult;

   if(hdl->uGetDurProgress == 0)
      *uProgress=0;
   else
      *uProgress = hdl->uGetDurProgress;
   
   ParseResult = AST_BuildTable(hdl, ihdl->AudioSeekTbl, uProgress, ihdl->uFileSize ,fLimitFrameNumber);
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_BUILD_AST, hdl, *uProgress, ParseResult);

   if (AST_SUCCESS == ParseResult || AST_PARSE_FRAME_BREAK == ParseResult)
   { 
      *eLastRet = MEDIA_SUCCESS;
   }
   else if (AST_EOF == ParseResult)
   {
      *uProgress=100;
      *eLastRet = MEDIA_SUCCESS;
   }
   else if (AST_PARSE_FRAME_FAIL == ParseResult )
   {
      *uProgress=100;
      *eLastRet = MEDIA_SEEK_FAIL;
   }
   else
   {
       *eLastRet = MEDIA_FAIL;
   }

   hdl->uGetDurProgress = *uProgress;
   if( 100 == hdl->uGetDurProgress )
   {
      *eLastRet = MEDIA_SUCCESS;
      hdl->start_time = 0;
      ihdl->uOffset = 0;
   }
}

kal_uint32 draMedGetCacheDur(MHdl *hdl)
{
   kal_uint32 uDur, CurFrames;
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   ASSERT(ihdl->AudioSeekTbl != 0);
   CurFrames=AST_GetIndexedFrames(ihdl->AudioSeekTbl);
   uDur = (kal_uint64)CurFrames*AST_GetFrameDuration(ihdl->AudioSeekTbl)/1000000;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_AST_DUR, uDur, hdl, CurFrames, AST_GetFrameDuration(ihdl->AudioSeekTbl),0,0);
   return uDur;
}

kal_uint32 draMedGetTotalDuration( MHdl *hdl )
{
   kal_uint32 uDur, TotalFrames;
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   
   ASSERT(ihdl->AudioSeekTbl != 0);

   FSAL_GetFileSize(ihdl->pstFSAL, &ihdl->uFileSize);
   if(1==ihdl->AudioSeekTbl->IsFail || 1==ihdl->AudioSeekTbl->IsDone)
   {
      TotalFrames=AST_GetIndexedFrames(ihdl->AudioSeekTbl);
   }
   else
   {
      TotalFrames=AST_EstimateTotalFrames(ihdl->AudioSeekTbl,ihdl->uFileSize);
   }
   
   if(TotalFrames==0)
   {
      uDur = 0;
   }
   else
   {
      uDur = (kal_uint64)TotalFrames*AST_GetFrameDuration(ihdl->AudioSeekTbl)/1000000;
   }
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_TOTAL_DUR_AST, uDur, hdl, TotalFrames, AST_GetFrameDuration(ihdl->AudioSeekTbl),0,0);
   return uDur;
}

#endif

static kal_uint32 wavMedGetCurrentTime( MHdl *hdl )
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   WAV_FileInfo *pInfo = (WAV_FileInfo*)ihdl->pPublicInfo;
   kal_uint32 uCurrentTime;
   if(pInfo->fUseRender)
   {
      ihdl->SinkNode.curHdl->SetParameter(ihdl->SinkNode.curHdl, OMX_IndexParamMediaTekGetCurrentTime, &uCurrentTime );
   }
   else
   {
      uCurrentTime = PcmSink_GetCurrentTime();
   }
   hdl->current_time = hdl->start_time + uCurrentTime;
   kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_CURRENT_TIME, hdl->mediaType, hdl->current_time, hdl->start_time,1,0,0,0);
   if(hdl->current_time > hdl->uTotalDuration)
      return hdl->uTotalDuration;
   else
      return hdl->current_time; 
}

static Media_Status wavMedSetLevel( MHdl *hdl, kal_uint8 level )
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_SET_LEVEL, level, 0,0,0,0,0,0);
   ihdl->DecNode.curHdl->SetParameter(ihdl->DecNode.curHdl, OMX_IndexConfigMelodySetChannelVolume, &level);
   return MEDIA_SUCCESS;
}

static kal_uint8 wavMedGetLevel( MHdl *hdl )
{
   kal_uint8 level;
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_LEVEL, level, 0,0,0,0,0,0);
   ihdl->DecNode.curHdl->SetParameter(ihdl->DecNode.curHdl, OMX_IndexConfigMelodyGetChannelVolume, &level);
   return level;
}

static Media_Status wavMedPlay( MHdl *hdl )
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   WAV_FileInfo *pInfo = (WAV_FileInfo*)ihdl->pPublicInfo;
   OMX_ERRORTYPE uStatus = OMX_ErrorNone;
   kal_bool fUseRender = KAL_FALSE;
#if defined(__AUDIO_MIXER_SUPPORT__) 
   fUseRender = ((WAV_FileInfo*)ihdl->pPublicInfo)->fUseRender;
#endif
#if defined(__AUDIO_NOT_SUPPORTED__)
   return MEDIA_FAIL;
#endif
   if (!fUseRender)
   {
      PcmSink_TerminateSound();
   }
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY, hdl->mediaType, hdl->state, hdl->GetDataCount(hdl),0,0,0,0);
   hdl->eof = KAL_FALSE;
   hdl->waiting = KAL_FALSE;
   hdl->isUnderflow = KAL_FALSE;
   ihdl->endflag = KAL_FALSE;
   mhdlRefillAndUpdateVideoBuffer(hdl); //call this function, if video eof, hdl->eof will be set.    
   
   {
      SinkParam Sink_param;
      WAV_Par2DecInfo pWavInfo;

      hdl->state = COMPONENT_STATE_PLAY;

      if(WAV_CILENT_PCM_FILE == pInfo->uCilentType)
      {
         PCM_PARAM pcmInfo;
         pcmInfo.FormatTag       = pInfo->format;
         pcmInfo.SampleRate      = pInfo->uSampleRate;
         pcmInfo.ChannelNum      = pInfo->uChannelNum;
         pcmInfo.DataLength      = pInfo->uDataLength;
         pcmInfo.BitsPerSample   = pInfo->uBitPerSample;
         pcmInfo.SamplesPerBlock = 512;
         pcmInfo.BlockAlign      = 256; 
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PCM_STRM_FORMAT, pInfo->uSampleRate, pInfo->uBitPerSample,pInfo->uChannelNum,0,0,0);
         if(OMX_ErrorNone != ihdl->ParNode.curHdl->SetParameter(ihdl->ParNode.curHdl, OMX_IndexParamAudioPcm, &pcmInfo))
         {
            kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 0,MEDIA_FAIL,0,0,0,0);
            return MEDIA_FAIL;
         }
      }
      else if(WAV_CILENT_PCM_STRM == pInfo->uCilentType)
      {
         PCM_PARAM pcmInfo;
         pcmInfo.FormatTag       = WAV_FORMAT_LPCM;
         pcmInfo.SampleRate      = pInfo->uSampleRate;
         pcmInfo.ChannelNum      = pInfo->uChannelNum;
         pcmInfo.DataLength      = 0x7FFFFFFF;
         pcmInfo.BitsPerSample   = pInfo->uBitPerSample;
         pcmInfo.SamplesPerBlock = 4;
         pcmInfo.BlockAlign      = 4; 
         if(OMX_ErrorNone != ihdl->ParNode.curHdl->SetParameter(ihdl->ParNode.curHdl, OMX_IndexParamMediaAudioPCMStreaming, &pcmInfo))
         {
            if(hdl->eof)
            {
               kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 2,MEDIA_SEEK_EOF,0,0,0,0);
               return MEDIA_SEEK_EOF;     
            }
            kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 1,MEDIA_FAIL,0,0,0,0);
            return MEDIA_FAIL;
         }
         Sink_param.uChannelNum = pInfo->uChannelNum;
         Sink_param.uSamplingFreq = pInfo->uSampleRate;
      }
#if defined(__DRA_DECODE_SUPPORT__)
      else if(WAV_CILENT_DRA_STRM == pInfo->uCilentType)
      {
         if(OMX_ErrorNone != ihdl->ParNode.curHdl->SetParameter(ihdl->ParNode.curHdl, OMX_IndexParamMediaAudioDRA, NULL))
         {
            kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 3,MEDIA_FAIL,0,0,0,0);
            return MEDIA_FAIL;
         }
         if(OMX_ErrorNone != ihdl->DecNode.curHdl->SetParameter(ihdl->DecNode.curHdl, OMX_IndexParamMediaAudioDRA, NULL))
         {
            kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 3,MEDIA_FAIL,0,0,0,0);
            return MEDIA_FAIL;
         }
      }
#endif

      uStatus = ihdl->ParNode.curHdl->Start(ihdl->ParNode.curHdl);
      if(OMX_ErrorContentEndOfFile == uStatus)
      {
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 4,MEDIA_SEEK_EOF,0,0,0,0);
         return MEDIA_SEEK_EOF;
      }
      else if(OMX_ErrorNone != uStatus)
      {
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 5,MEDIA_FAIL,0,0,0,0);
         return MEDIA_FAIL;
      }

      if((pInfo->format != WAV_FORMAT_DRA)&&(WAV_CILENT_PCM_STRM != pInfo->uCilentType))
      {
         if(OMX_ErrorNone != ihdl->ParNode.curHdl->SetParameter(ihdl->ParNode.curHdl, OMX_IndexParamMediaTekPcmSink, &Sink_param))
         {
            kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 6,MEDIA_FAIL,0,0,0,0);
            return MEDIA_FAIL;
         }
         if(OMX_ErrorNone != ihdl->ParNode.curHdl->SetParameter(ihdl->ParNode.curHdl, OMX_IndexParamMediaTekWavDecSWIPHdl, &pWavInfo))
         {
            kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 7,MEDIA_FAIL,0,0,0,0);
            return MEDIA_FAIL;
         }
         if(OMX_ErrorNone != ihdl->DecNode.curHdl->SetParameter(ihdl->DecNode.curHdl, OMX_IndexParamMediaTekWavDecSWIPHdl, &pWavInfo))
         {
            kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 8,MEDIA_FAIL,0,0,0,0);
            return MEDIA_FAIL;
         }
      }

      if(WAV_CILENT_PCM_STRM != pInfo->uCilentType)
      {
         ihdl->DecNode.curHdl->Start(ihdl->DecNode.curHdl);
      }
#if defined(__DRA_DECODE_SUPPORT__)
      if(pInfo->format == WAV_FORMAT_DRA)
      {
         if(OMX_ErrorNone != ihdl->DecNode.curHdl->SetParameter(ihdl->DecNode.curHdl, OMX_IndexParamMediaTekPcmSink, &Sink_param))
         {
            kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 9,MEDIA_FAIL,0,0,0,0);
            return MEDIA_FAIL;
         }
      }
#endif

#if defined(__AUDIO_MIXER_SUPPORT__) 
      if (fUseRender)
      {
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_SR_CH, hdl->mediaType, Sink_param.uSamplingFreq,Sink_param.uChannelNum,0,0,0);
         if(OMX_ErrorNone != ihdl->SinkNode.curHdl->SetParameter(ihdl->SinkNode.curHdl, OMX_IndexParamMediaTekPcmSink, &Sink_param))
         {
            kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 10,MEDIA_FAIL,0,0,0,0);
            return MEDIA_FAIL;
         }
         if(OMX_ErrorNone != ihdl->SinkNode.curHdl->Start(ihdl->SinkNode.curHdl) )
         {
            return MEDIA_FAIL;
         }
      }
      else
#endif
      {
         if( OMX_ErrorNone != AudioDrain_Start(ihdl, Sink_param.uSamplingFreq, Sink_param.uChannelNum))
         {
            if(ihdl->mh.eof)
            {
               kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType,11,MEDIA_SEEK_EOF,0,0,0,0);
               return MEDIA_SEEK_EOF;    
            }
            else
            {
               kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 12,MEDIA_FAIL,0,0,0,0);
               return MEDIA_FAIL;    
            }
         }
      }
   }
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_SUCCESS, hdl->mediaType, hdl->state, 0,0,0,0,0);
   return MEDIA_SUCCESS;
}

static Media_Event wavMedProcess( MHdl *hdl, Media_Event event )
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   WAV_FileInfo *pInfo = (WAV_FileInfo*)ihdl->pPublicInfo;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PROCESS, hdl->mediaType, hdl, event, hdl->state, hdl->eof,0,0,0);
    
   switch(event) {
      case MEDIA_READY_TO_PLAY:
         return event;
      case MEDIA_END:
      case MEDIA_STOP_TIME_UP:
#if defined(__AUDIO_MIXER_SUPPORT__) 
         if(pInfo->fUseRender && ihdl->SinkNode.curHdl)
         {
            ihdl->SinkNode.curHdl->SetParameter(ihdl->SinkNode.curHdl, OMX_IndexParamMediaTekRenderDelayStop, NULL);
         }
#endif
         if( hdl->state == COMPONENT_STATE_PLAY ) 
         {
            Media_A2V_NOTIFY_MEDIA_END(hdl->Stop, hdl);
         }
         break;
      case MEDIA_ERROR:
         hdl->Stop(hdl);
         break;
      case MEDIA_DATA_REQUEST:
      case MEDIA_BUFFER_UNDERFLOW:
         if(ihdl->pstFSAL)
         {
            kal_int32 I;
            OMX_ERRORTYPE result;
            
            for (I=0; I<WAVDEC_PARSER_BUFNUM; I++)
            {
               result = WavPar_Process_internal(ihdl->ParNode.curHdl);
               if (result != OMX_ErrorNone) 
               {
                  return MEDIA_READ_ERROR;
               }
            }
         }
         else
         {
            ACU_SendProcessCommandl((AudComHdlInt *)ihdl->ParNode.curHdl); 
         }
         if(!(hdl->pStrmStruct== NULL && ihdl->pstFSAL==NULL))
         {
            hdl->FinishWriteData(hdl);
         }
         if(ihdl->pstFSAL)
         {
            return MEDIA_NONE;
         }
         break;
      default:
         // should never reach here
         ASSERT(0);
   }
   return event;
}


static const MHPB_CompList WavDecFuncArray[2] = {
   {WavPar_GetMemSize, WavPar_Init, WAVDEC_PARSER_BUFSIZE, WAVDEC_PARSER_BUFNUM},
   {WavDec_GetMemSize, WavDec_Init, WAVDEC_DECODER_BUFSIZE, WAVDEC_DECODER_BUFNUM}
};

static const MHPB_CompList WavParRendFunc = {
   WavPar_GetMemSize, WavPar_Init, WAVDEC_PARSER_RENDER_BUFSIZE, WAVDEC_PARSER_RENDER_BUFNUM
};

#if defined(__AUDIO_MIXER_SUPPORT__) 
static const MHPB_CompList RenderFuncArray = {
   PcmRender_GetMemSize, PcmRender_Init, 0, 0
};
#endif

#if defined(__DRA_DECODE_SUPPORT__)
static const MHPB_CompList DraDecFuncArray[2] = {
   {WavPar_GetMemSize, WavPar_Init, DRADEC_PARSER_BUFSIZE, DRADEC_PARSER_BUFNUM},
   {DraDec_GetMemSize, DraDec_Init, DRADEC_DECODER_BUFSIZE, DRADEC_DECODER_BUFNUM}
};
#endif

static MHdl *wavMedOpen(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param)
{
   MHdl *hdl;
   MHPB_Internal *ihdl;
   WAV_FileInfo *pInfo = (WAV_FileInfo*)param;
   
   if (handler == NULL) 
   {
      MHPB_CompList const *pArray[1] = {NULL};
      
      hdl = MH_Component_List_Open(handler, pstFSAL, pArray);
   } else {
      MHPB_CompList const *pArray[4];
      
      // Dispatch the type: Wav / DRA / streaming, and render
#if defined(__DRA_DECODE_SUPPORT__)
      if ((WAV_CILENT_DRA_FILE == pInfo->uCilentType)||(WAV_CILENT_DRA_STRM == pInfo->uCilentType))
      {
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
#endif
         {
            hdl = MH_Component_Open(handler, pstFSAL, &DraDecFuncArray[0], &DraDecFuncArray[1]);
         }
      } else
#endif
      if (WAV_CILENT_PCM_STRM == pInfo->uCilentType)
      {
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
#endif
         {
            hdl = MH_Component_Open(handler, pstFSAL, &WavDecFuncArray[0], NULL);
         }
      } 
      else 
      {
#if defined(__AUDIO_MIXER_SUPPORT__) 
         if (pInfo->fUseRender) 
         {
            pArray[0] = &WavParRendFunc;
            pArray[1] = &WavDecFuncArray[1];
            pArray[2] = &RenderFuncArray;
            pArray[3] = NULL;
            
            hdl = MH_Component_List_Open(handler, pstFSAL, pArray);
            ihdl = (MHPB_Internal *)hdl;
            
            memcpy(&ihdl->ParNode,  &ihdl->NodeArray[0], sizeof(AcHdlNode));
            memcpy(&ihdl->DecNode,  &ihdl->NodeArray[1], sizeof(AcHdlNode));
            memcpy(&ihdl->SinkNode, &ihdl->NodeArray[2], sizeof(AcHdlNode));
         } 
         else 
#endif
         {
            hdl = MH_Component_Open(handler, pstFSAL, &WavDecFuncArray[0], &WavDecFuncArray[1]);
         }
      }
   }
   ihdl = (MHPB_Internal *)hdl;
   
   hdl->mediaType = MEDIA_FORMAT_WAV;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_OPEN, hdl->mediaType, hdl, handler,0,0,0,0);
   
   ihdl->pPublicInfo = pInfo;
   
   hdl->Play    = wavMedPlay;
   hdl->Process = wavMedProcess;
   hdl->ReachValidRegion = wavMedReachValidRegion;

#if defined(__AUDIO_MIXER_SUPPORT__) 
   if (pInfo->fUseRender) {
      hdl->GetLevel = wavMedGetLevel; 
      hdl->SetLevel = wavMedSetLevel; 
      hdl->GetCurrentTime = wavMedGetCurrentTime;    
   }
#endif
   
   hdl->uTotalDuration = pInfo->uTotalDuration;
   if (pInfo->uSampleRate) { 
      ihdl->frameDur = (kal_uint32)((kal_int64)1024 * 1000000000 / pInfo->uSampleRate);
   }

#if defined(__DRA_DECODE_SUPPORT__)
   if (WAV_CILENT_DRA_FILE == pInfo->uCilentType) {
      hdl->SetCacheTbl      = draMedSetCacheTbl;
      hdl->BuildCache       = draMedBuildCache;
      hdl->GetCacheDuration = draMedGetCacheDur;
      hdl->GetTotalDuration = draMedGetTotalDuration;
   }
#endif   
   if(pInfo->fUseRender)
   {
      if(ihdl->DecNode.curHdl)
      {
         ihdl->DecNode.curHdl->SetParameter(ihdl->DecNode.curHdl, OMX_IndexParamMediaTekAddTileSilence, NULL);
      }
   }
   return hdl;
}

static MHdl *WAV_OpenCommon(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param, kal_bool fRender)
{
   WAV_FileInfo *pInfo;
   pInfo = (WAV_FileInfo *)get_ctrl_buffer( sizeof(WAV_FileInfo) );
   memset(pInfo, 0, sizeof(WAV_FileInfo));
   if(MEDIA_SUCCESS != wavGetFileInfo(pstFSAL, pInfo))
   {
      pInfo->uCilentType = WAV_CILENT_UNKNOW;
   }
   else if(WAV_FORMAT_DRA == pInfo->format)
   {
      pInfo->uCilentType = WAV_CILENT_DRA_FILE;
   }
   else
   {
      pInfo->uCilentType = WAV_CILENT_WAV_FILE;
   }
   
   pInfo->fUseRender = fRender;
   
   return wavMedOpen(handler, pstFSAL, pInfo);
}

MHdl *WAV_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param)
{
   return WAV_OpenCommon(handler, pstFSAL, param, KAL_FALSE);
}

MHdl *WAV_OpenRender(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param)
{
   return WAV_OpenCommon(handler, pstFSAL, param, KAL_TRUE);
}

MHdl *AU_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param)
{
   return WAV_Open(handler, pstFSAL, NULL);
}

MHdl *AIFF_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param)
{
   return WAV_Open(handler, pstFSAL, NULL);
}

MHdl *PCM_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param)
{
   kal_uint32 uFileSize;
   WAV_FileInfo *pInfo;
   Media_VM_PCM_Param *pcm_param = (Media_VM_PCM_Param *) param;
   pInfo = (WAV_FileInfo *)get_ctrl_buffer( sizeof(WAV_FileInfo) );
   memset(pInfo, 0, sizeof(WAV_FileInfo));
   FSAL_GetFileSize(pstFSAL, &uFileSize);
   pInfo->uCilentType = WAV_CILENT_PCM_FILE;
   pInfo->uSampleRate = 8000;
   pInfo->uChannelNum = 1; 
   pInfo->uDataLength = uFileSize;
   pInfo->uDataChunkOffset = 0;
   switch (pcm_param->mediaType) 
   {
      case MEDIA_FORMAT_PCM_16K:
         pInfo->uSampleRate = 16000;
         pInfo->uBitPerSample = 16;
         pInfo->format = WAV_FORMAT_LPCM;
         pInfo->uTotalDuration = (uFileSize >> 5);
         pInfo->uBitRate = 256000;
         break;
      case MEDIA_FORMAT_PCM_8K:
         pInfo->uBitPerSample = 16;
         pInfo->format = WAV_FORMAT_LPCM;
         pInfo->uTotalDuration = (uFileSize >> 4);
         pInfo->uBitRate = 128000;
         break;
      case MEDIA_FORMAT_G711_ALAW:
         pInfo->uBitPerSample = 8;
         pInfo->format = WAV_FORMAT_ALAW;
         pInfo->uTotalDuration = (uFileSize >> 3);
         pInfo->uBitRate = 64000;
         break;
      case MEDIA_FORMAT_G711_ULAW:
         pInfo->uBitPerSample = 8;
         pInfo->format = WAV_FORMAT_ULAW;
         pInfo->uTotalDuration = (uFileSize >> 3);
         pInfo->uBitRate = 64000;
         break;
      case MEDIA_FORMAT_DVI_ADPCM:
         pInfo->uBitPerSample = 4;
         pInfo->format = WAV_FORMAT_DVIADPCM;
         pInfo->uTotalDuration = (uFileSize >> 2);
         pInfo->uBitRate = 32000;
         break;
      default:
         ASSERT(0);
   }
   return wavMedOpen(handler, pstFSAL, pInfo);
}

MHdl *PCM_Strm_Open_cilent(void(*handler)( MHdl *handle, Media_Event event ), void *param)
{
   MHdl *hdl;
   WAV_FileInfo *pInfo;
   Media_PCM_Stream_Param *pcm_param = (Media_PCM_Stream_Param *) param;
   
   pInfo = (WAV_FileInfo *)get_ctrl_buffer( sizeof(WAV_FileInfo) );
   memset(pInfo, 0, sizeof(WAV_FileInfo));
   pInfo->uCilentType = WAV_CILENT_PCM_STRM;
   pInfo->format = WAV_FORMAT_LPCM;
   pInfo->uDataChunkOffset = 0;
   pInfo->uDataLength = 0x7FFFFFFF;    //fake
   pInfo->uBitRate = 256000;           //fake
   pInfo->uTotalDuration = 0x7FFFFFFF; //fake
   pInfo->uSampleRate = pcm_param->sampleFreq;
   pInfo->uBitPerSample = pcm_param->bitPerSample;
   pInfo->uChannelNum = 1;
   if(pcm_param->isStereo)
   {
      pInfo->uChannelNum = 2;
   }
   
   hdl = wavMedOpen(handler, NULL, pInfo);
   if (pcm_param->forceVoice) {
      MHPB_Internal *ihdl;
      
      ihdl = (MHPB_Internal *)hdl;
      ihdl->SinkNode.curHdl->SetParameter(ihdl->SinkNode.curHdl, OMX_IndexParamMediaTekPcmSinkVoice, NULL);
   }
   
   return hdl;
}

#if defined(__DRA_DECODE_SUPPORT__)
MHdl *DRA_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param)
{
   WAV_FileInfo *pInfo;
   pInfo = (WAV_FileInfo *)get_ctrl_buffer( sizeof(WAV_FileInfo) );
   memset(pInfo, 0, sizeof(WAV_FileInfo));
   pInfo->uCilentType = WAV_CILENT_DRA_STRM;
   pInfo->format = WAV_FORMAT_DRA;
   return wavMedOpen(handler, pstFSAL, pInfo);
}
#endif 

#endif //__WAV_DECODE_SWIP__

