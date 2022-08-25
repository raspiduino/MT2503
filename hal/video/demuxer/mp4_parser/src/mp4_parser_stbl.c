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
 * mp4_parser_stbl.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   MPEG-4 Parser, sample table related functions.
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#if defined(__M3GPMP4_FILE_FORMAT_SUPPORT__)
#include "drv_features_video.h"
#include "mp4_parser.h"
#include "vcodec_v2_trc.h"

#include "mp4_common.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "fsal.h"

typedef enum
{
    MP4_PARSER_STSS,
    MP4_PARSER_STSC,
    MP4_PARSER_STTS,
    MP4_PARSER_CTTS
} MP4_Parser_STBL_IDX_T;

static MP4_Parser_Status MP4_STTS_ProcCacheTableByTrack( STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, kal_uint16 uCount );

#ifndef __LOW_COST_SUPPORT_COMMON__
static MP4_Parser_Status MP4_STSS_ProcCacheTableByTrack( STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, kal_uint32 uCount );
#endif

#ifdef __VE_MP4_PARSER_SUPPORT_CTTS__
static MP4_Parser_Status MP4_CTTS_ProcCacheTableByTrack( STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, kal_uint16 uCount );
#endif

#ifdef __VE_MM_DCM_SUPPORT__
#include "dcmgr.h" //DCM

#pragma arm section code = "DYNAMIC_CODE_VECOM_ROCODE", rodata = "DYNAMIC_CODE_VECOM_RODATA"
#endif

/*******************************************************************************
   Get the track index number with respect to the specified track type.
*******************************************************************************/
MP4_Parser_Status MP4_GetTrackNoByType(STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, kal_uint8 *pbTrackNo)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL | pbTrackNo!=NULL);

   if (MP4_TRACK_AUDIO == eTrackType) {
      *pbTrackNo = pstMp4Parser->bAudioTrack;
   } else if (MP4_TRACK_VIDEO == eTrackType) {
      *pbTrackNo = pstMp4Parser->bVideoTrack;
   } else {
      return MP4_PARSER_NO_SUCH_TRACK;
   }
   /// Note: the initial value of bAudioTrack or bVideoTrack is MP4_RESERVED_TRACK_NO.
   if (MP4_RESERVED_TRACK_NO == *pbTrackNo)
      return MP4_PARSER_NO_SUCH_TRACK;

   return MP4_PARSER_OK;
}



/* --------------------- Media Header related functions --------------------- */

/*******************************************************************************
   Get the media time scale with respect to the specified track type.
*******************************************************************************/
MP4_Parser_Status MP4_GetMediaTimeScale(STMp4Parser *pstMp4Parser, kal_uint32 *puTimeScale, MP4_Track_Type eTrackType)
{
   MP4_Parser_Status ret;
   kal_uint8 bTrackNo;

   MP4_PARSER_CHECK_ARG(puTimeScale!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

#ifdef MP4_PARSER_TRC_LOG
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_GETMEDIATIMESCALE,pstMp4Parser->uParserFinish, (int)(pstMp4Parser->stMp4Track[bTrackNo].uMediaTimeScale));
#endif
   *puTimeScale = pstMp4Parser->stMp4Track[bTrackNo].uMediaTimeScale;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the duration with respect to the specified track type.
*******************************************************************************/
MP4_Parser_Status MP4_GetMediaDuration(STMp4Parser *pstMp4Parser, kal_uint32 *puDuration, MP4_Track_Type eTrackType)
{
   MP4_Parser_Status ret;
   kal_uint8 bTrackNo;

   MP4_PARSER_CHECK_ARG(puDuration!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

#ifdef MP4_PARSER_TRC_LOG
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_GETMEDIADURATION,pstMp4Parser->uParserFinish, (int)(pstMp4Parser->stMp4Track[bTrackNo].uMediaDuration));
#endif
   *puDuration = pstMp4Parser->stMp4Track[bTrackNo].uMediaDuration;

   return MP4_PARSER_OK;
}



/* --------------------- Sample Size Table related functions --------------------- */

/*******************************************************************************
   Get the sample count of the specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetSampleCount(STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, kal_uint32 *puSampleCount)
{
   MP4_Parser_Status ret;
   kal_uint8 bTrackNo;

   MP4_PARSER_CHECK_ARG(puSampleCount!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   *puSampleCount = pstMp4Parser->stMp4Track[bTrackNo].uSampleCount;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the sample size of the specified sample in the specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetSampleSize(STMp4Parser *pstMp4Parser, kal_uint32 uSampleNo,
                                    kal_uint32 *puSampleSize, MP4_Track_Type eTrackType)
{
   MP4_Parser_Status ret;
   kal_uint8 bTrackNo;
   STFSAL *pstFSAL_STSZ;
   STMp4Track *prTrack;

   MP4_PARSER_CHECK_ARG(puSampleSize!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

    prTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);
   *puSampleSize = prTrack->uConstantSampleSize;

   pstFSAL_STSZ = prTrack->pstFSAL_STSZ;

                  // terminate by source
   if (pstMp4Parser->fgQuickClose == KAL_TRUE)
     return MP4_PARSER_PARSE_QUICK_CLOSED;

   if (*puSampleSize != 0) {
      return MP4_PARSER_OK;
   } else {
      kal_uint32 uOffset;
      MP4_PARSER_ASSERT(uSampleNo<prTrack->uSampleCount);
      uOffset = prTrack->uOffsetSampleSizeTable;
      uOffset += (uSampleNo * 4);
      if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstFSAL_STSZ, uOffset))!=FSAL_OK)
         return MP4_PARSER_FILE_SEEK_ERROR;
      if ((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstFSAL_STSZ, puSampleSize))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;

      return MP4_PARSER_OK;
   }
}

/* --------------------- Chunk Offset Table related functions --------------------- */

/*******************************************************************************
   Get the number of chunks in the specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetChunkCount(STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, kal_uint32 *puChunkCount)
{
   MP4_Parser_Status ret;
   kal_uint8 bTrackNo;

   MP4_PARSER_CHECK_ARG(puChunkCount!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   *puChunkCount = pstMp4Parser->stMp4Track[bTrackNo].uChunkCount;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the number of chunks in the specified track.
*******************************************************************************/
static MP4_Parser_Status MP4_GetChunkOffset(STMp4Parser *pstMp4Parser, kal_uint32 uChunkNo,
                                            kal_uint32 *puChunkOffset, MP4_Track_Type type)
{
   MP4_Parser_Status ret;
   kal_uint32 uOffset;
   kal_uint8 bTrackNo;
   STMp4Track *pCurTrack;

                  // terminate by source
   if (pstMp4Parser->fgQuickClose == KAL_TRUE)
      return MP4_PARSER_PARSE_QUICK_CLOSED;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, type, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

#ifdef MP4_PARSER_TRC_LOG_DEBUG1
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_GetChunkOffset,bTrackNo);
#endif

   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   MP4_PARSER_ASSERT(uChunkNo < pCurTrack->uChunkCount);

   uOffset = pCurTrack->uOffsetChunkOffsetTable;
   uOffset += (uChunkNo * pCurTrack->uEntrySize);

   if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstMp4Parser->pstFSAL, uOffset))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

#if 1 // Pibben for 64 bit
   if ((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, puChunkOffset))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if(pCurTrack->uEntrySize == 8)
   {
       if(*puChunkOffset != 0)
       {
           //ASSERT(0);
           return MP4_PARSER_64BIT_NOT_SUPPORT;
       }
       if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, puChunkOffset))!=FSAL_OK)
           return MP4_PARSER_FILE_READ_ERROR;
   }
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   return MP4_PARSER_OK;
}



/* --------------------- Sample To Chunk Table related functions --------------------- */

/*******************************************************************************
   Get the the number of entries in the STSC box of the specified track.
*******************************************************************************/
static MP4_Parser_Status MP4_GetSampleToChunkEntryCount(STMp4Parser *pstMp4Parser, MP4_Track_Type type, kal_uint32 *puEntryCount)
{
   MP4_Parser_Status ret;
   kal_uint8 bTrackNo;

   MP4_PARSER_CHECK_ARG(puEntryCount!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, type, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   *puEntryCount = pstMp4Parser->stMp4Track[bTrackNo].uSampleToChunkEntryCount;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the index of the first chunk of the specified run in the STSC box
   of the specified track.
*******************************************************************************/
static MP4_Parser_Status MP4_GetFirstChunkInRun(STMp4Parser *pstMp4Parser, kal_uint32 uRun,
                                                kal_uint32 *puFirstChunkInRun, MP4_Track_Type type)
{
   MP4_Parser_Status ret;
   kal_uint32 uOffset;
   kal_uint8 bTrackNo;
   STFSAL *pstFSAL_STCO;
   STMp4Track *prTrack;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, type, &bTrackNo))!=MP4_PARSER_OK) {
      return ret;
   }

   prTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);
   MP4_PARSER_ASSERT(uRun<prTrack->uSampleToChunkEntryCount);

   pstFSAL_STCO = prTrack->pstFSAL_STCO;
   if (pstFSAL_STCO == NULL)
      pstFSAL_STCO = pstMp4Parser->pstFSAL;

   uOffset = prTrack->uOffsetSampleToChunkTable;
   uOffset += (uRun * 12);

   if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstFSAL_STCO, uOffset))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   if ((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstFSAL_STCO, puFirstChunkInRun))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   *puFirstChunkInRun -= 1; /// index from 0

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the number of samples per chunk of the specified run in the STSC box
   of the specified track.
*******************************************************************************/
static MP4_Parser_Status MP4_GetSamplePerChunkInRun(STMp4Parser *pstMp4Parser, kal_uint32 uRun,
                                                    kal_uint32 *puSamplePerChunk, MP4_Track_Type type)
{
   MP4_Parser_Status ret;
   kal_uint32 uOffset;
   kal_uint8  bTrackNo;
   STMp4Track *pCurTrack;
   STFSAL *pstFSAL_STCO;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, type, &bTrackNo))!=MP4_PARSER_OK)
      return ret;
   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   MP4_PARSER_ASSERT(uRun < pCurTrack->uSampleToChunkEntryCount);

   pstFSAL_STCO = pCurTrack->pstFSAL_STCO;
   if (pstFSAL_STCO == NULL)
      pstFSAL_STCO = pstMp4Parser->pstFSAL;

   uOffset = pCurTrack->uOffsetSampleToChunkTable;
   uOffset += (uRun * 12 + 4);

   if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstFSAL_STCO, uOffset))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   if ((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstFSAL_STCO, puSamplePerChunk))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if (*puSamplePerChunk == 0)
      return MP4_PARSER_PARSE_SAMPLE_PERCHUNK_ERROR;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the number of the chunk and the file offset of the chunk
   where the specified sample resides in.
*******************************************************************************/
static MP4_Parser_Status MP4_GetChunkNoAndOffset(STMp4Parser *pstMp4Parser, kal_uint32 uSampleNo,
                                                 kal_uint32 *puSampleInChunk, kal_uint32 *puSampleOffsetChunk,
                                                 MP4_Track_Type eTrackType )
{
   MP4_Parser_Status ret;
   kal_uint32 uSamplePerChunk;
   kal_uint32 uSampleToChunkIndex = 0;
   kal_uint32 uFirstChunk, uLastChunk;
   kal_uint32 uSampleToChunkEntryCount = 0;
   kal_uint32 uSampleSumPrev = 0, uSampleSum = 0;
   STMp4Track *pCurTrack;
   kal_uint8  bTrackNo;

   MP4_PARSER_CHECK_ARG(puSampleInChunk!=NULL | puSampleOffsetChunk!=NULL);

   if ((ret = MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
       return ret;

#ifdef MP4_PARSER_TRC_LOG_DEBUG1
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_GetChunkNoAndOffset,bTrackNo);
#endif

               // terminate by source
   if (pstMp4Parser->fgQuickClose == KAL_TRUE)
       return MP4_PARSER_PARSE_QUICK_CLOSED;

   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   if ((ret = MP4_GetSampleToChunkEntryCount(pstMp4Parser, eTrackType, &uSampleToChunkEntryCount))!=MP4_PARSER_OK)
       return ret;

   if (pCurTrack->uSTSCCacheTableEntryCount > 0)
   {  /// STSC cache is enabled. Perform binary search in the cache.
      kal_uint16 start_index, end_index;
      STSC_Cache_Entry *stsc_cache_table;

      stsc_cache_table = pCurTrack->pSTSCCacheTable;
      start_index = 0;
      end_index = pCurTrack->uSTSCCacheTableEntryCount-1;
      while ((end_index-start_index)>1)
      {
         kal_uint16 middle_index = (start_index+end_index)>>1;
         if( uSampleNo > stsc_cache_table[middle_index].accumulated_sample_count )
            start_index = middle_index;
         else
            end_index = middle_index;
      }

      if (start_index)
      {
         uSampleToChunkIndex=end_index * pCurTrack->uSTSCCacheTableStepSize;
         uSampleSum = stsc_cache_table[start_index].accumulated_sample_count;
         uSampleSumPrev = uSampleSum;
      }
   }

   for (; uSampleToChunkIndex<uSampleToChunkEntryCount; uSampleToChunkIndex++) {
      if ((ret = MP4_GetSamplePerChunkInRun(pstMp4Parser, uSampleToChunkIndex, &uSamplePerChunk, eTrackType))!=MP4_PARSER_OK)
         return ret;
      if (uSampleToChunkIndex == uSampleToChunkEntryCount-1) {
         if ((ret = MP4_GetChunkCount(pstMp4Parser, eTrackType, &uLastChunk))!=MP4_PARSER_OK)
            return ret;
         if(uLastChunk == 0)
            return MP4_PARSER_LASTCHUNK_ERROR;
         uLastChunk--;
      } else {
         if ((ret = MP4_GetFirstChunkInRun(pstMp4Parser, uSampleToChunkIndex+1, &uLastChunk, eTrackType))!=MP4_PARSER_OK)
            return ret;
         if(uLastChunk == 0)
            return MP4_PARSER_LASTCHUNK_ERROR;
         uLastChunk--;
      }
      if ((ret = MP4_GetFirstChunkInRun(pstMp4Parser, uSampleToChunkIndex, &uFirstChunk, eTrackType))!=MP4_PARSER_OK)
         return ret;
      if((uLastChunk+1) < uFirstChunk)
         return MP4_PARSER_LASTCHUNK_ERROR;
      uSampleSum += (uLastChunk - uFirstChunk + 1)*uSamplePerChunk;
      if (uSampleNo<=uSampleSum) {
         *puSampleInChunk = (uSampleNo - uSampleSumPrev) / uSamplePerChunk + uFirstChunk;
         *puSampleOffsetChunk = (uSampleNo - uSampleSumPrev) % uSamplePerChunk;

         pCurTrack->uSampleToChunkIndex = uSampleToChunkIndex;
         pCurTrack->uSamplePerChunk     = uSamplePerChunk;
         pCurTrack->uFirstChunk         = uFirstChunk;
         pCurTrack->uSampleSum          = uSampleSum;
         pCurTrack->uSampleSumPrev      = uSampleSumPrev;

         return MP4_PARSER_OK;
      }
      uSampleSumPrev = uSampleSum;
   }
   return MP4_PARSER_INTERNAL_ERROR;
}

static MP4_Parser_Status MP4_GetChunkNoAndOffset_Next_Prev(STMp4Parser *pstMp4Parser,
kal_uint32 *uSampleInChunk, kal_uint32 *uSampleOffsetChunk, MP4_Track_Type type, kal_bool fgNext)
{
   kal_uint32 uSampleToChunkIndex, uSampleNo;
   kal_uint32 uFirstChunk, uLastChunk;
   kal_uint32 uSampleToChunkEntryCount;
   kal_uint32 uSamplePerChunk;
   kal_uint32 uSampleSum, uSampleSumPrev;
   MP4_Parser_Status ret;
   STMp4Track *pCurTrack;
   kal_uint8  bTrackNo;

   MP4_PARSER_CHECK_ARG(uSampleInChunk!=NULL | uSampleOffsetChunk!=NULL);

   if ((ret = MP4_GetTrackNoByType(pstMp4Parser, type, &bTrackNo))!=MP4_PARSER_OK)
       return ret;

   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   uSampleNo                = pCurTrack->uCurSampleNo;
   uSampleToChunkEntryCount = pCurTrack->uSampleToChunkEntryCount;
   uSampleToChunkIndex      = pCurTrack->uSampleToChunkIndex;
   uSampleSum               = pCurTrack->uSampleSum;
   uSampleSumPrev           = pCurTrack->uSampleSumPrev;
   uSamplePerChunk          = pCurTrack->uSamplePerChunk;
   uFirstChunk              = pCurTrack->uFirstChunk;

   if (((uSampleNo<uSampleSum) && (fgNext == KAL_TRUE)) || ((uSampleNo > uSampleSumPrev) && (fgNext == KAL_FALSE))) {
      *uSampleInChunk = (uSampleNo - uSampleSumPrev) / uSamplePerChunk + uFirstChunk;
      *uSampleOffsetChunk = (uSampleNo - uSampleSumPrev) % uSamplePerChunk;
      return MP4_PARSER_OK;
   }

    if (fgNext == KAL_TRUE)
   {
   uSampleSumPrev = uSampleSum;
   uSampleToChunkIndex++;
   }
    else
    {
       if(uSampleToChunkIndex == 0)
          return MP4_PARSER_SAMPLECHUNK_INDEX_ERROR;
       uSampleSum = uSampleSumPrev;
       uSampleToChunkIndex--;
    }

   if ((ret = MP4_GetSamplePerChunkInRun(pstMp4Parser, uSampleToChunkIndex, &uSamplePerChunk, type))!=MP4_PARSER_OK) {
      return ret;
   }

   if (uSampleToChunkIndex == uSampleToChunkEntryCount-1) {
      if ((ret = MP4_GetChunkCount(pstMp4Parser, type, &uLastChunk))!=MP4_PARSER_OK) {
         return ret;
      }
   }
   else {
      if ((ret = MP4_GetFirstChunkInRun(pstMp4Parser, uSampleToChunkIndex+1, &uLastChunk, type))!=MP4_PARSER_OK) {
         return ret;
      }
   }
      if(uLastChunk == 0)
         return MP4_PARSER_LASTCHUNK_ERROR;
      uLastChunk--;

   if ((ret = MP4_GetFirstChunkInRun(pstMp4Parser, uSampleToChunkIndex, &uFirstChunk, type))!=MP4_PARSER_OK) {
      return ret;
   }
    if (fgNext == KAL_TRUE)
    {
   if((uLastChunk+1) < uFirstChunk)
      return MP4_PARSER_LASTCHUNK_ERROR;

   uSampleSum += (uLastChunk - uFirstChunk + 1)*uSamplePerChunk;
}
    else
{
   uSampleSumPrev -= (uLastChunk - uFirstChunk + 1)*uSamplePerChunk;
    }

   *uSampleInChunk = (uSampleNo - uSampleSumPrev) / uSamplePerChunk + uFirstChunk;
   *uSampleOffsetChunk = (uSampleNo - uSampleSumPrev) % uSamplePerChunk;

   pCurTrack->uSampleToChunkIndex = uSampleToChunkIndex;
   pCurTrack->uSamplePerChunk     = uSamplePerChunk;
   pCurTrack->uFirstChunk         = uFirstChunk;
   pCurTrack->uSampleSum          = uSampleSum;
   pCurTrack->uSampleSumPrev      = uSampleSumPrev;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the file offset of the specified sample in the specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetSampleOffset(STMp4Parser *pstMp4Parser, kal_uint32 uSampleNo, kal_uint32 *puSampleOffset, MP4_Track_Type type)
{
   MP4_Parser_Status ret;
   STMp4Track *pCurTrack;
   kal_uint8  bTrackNo;
#ifdef MP4_PARSER_TRC_LOG
   kal_uint16 m_case = 0;
#endif
   kal_uint32 uSampleInChunk, uSampleOffsetChunk;

   MP4_PARSER_CHECK_ARG(puSampleOffset!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, type, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

#ifdef MP4_PARSER_TRC_LOG
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_GETSAMPLEOFFSET_START,bTrackNo);
#endif


   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   /// locate the chuck of the sample
   if ((ret=MP4_GetChunkNoAndOffset(pstMp4Parser, uSampleNo, &uSampleInChunk, &uSampleOffsetChunk, type))!=MP4_PARSER_OK)
      return ret;

   /// Check if the single-point cache is valid or not
   if (pCurTrack->uSampleOffset_Cache != 0) {
      if (pCurTrack->uSampleInChunk_Cache == uSampleInChunk) {
         /// Case 1: uSampleNo == uCurSampleNo
         if (uSampleNo == pCurTrack->uCurSampleNo) {
            *puSampleOffset = pCurTrack->uSampleOffset_Cache;
#ifdef MP4_PARSER_TRC_LOG
            m_case = 1;
#endif
            goto MP4_GetSampleOffset_OK; //return MP4_PARSER_OK;
         }

         /// Case 2: uSampleNo > uCurSampleNo, seek forward from current sample
         if (uSampleNo > pCurTrack->uCurSampleNo) {
            kal_uint32 i = uSampleNo - pCurTrack->uCurSampleNo + 1;
            while (--i > 0) {
               if ((ret=MP4_GetSampleOffset_Next(pstMp4Parser, puSampleOffset, type))!=MP4_PARSER_OK)
                  return ret;

			   // terminate by source
               if (pstMp4Parser->fgQuickClose == KAL_TRUE)
                  return MP4_PARSER_PARSE_QUICK_CLOSED;
            }
#ifdef MP4_PARSER_TRC_LOG
            m_case = 2;
#endif
            goto MP4_GetSampleOffset_OK; //return MP4_PARSER_OK;
         }
      }

      /// Case 3: uSampleNo < uCurSampleNo and (uCurSampleNo - uSampleNo) < uSampleOffsetChunk
      /// In this case, seek backward from current sample
      if ((uSampleNo < pCurTrack->uCurSampleNo) &&
          ((pCurTrack->uCurSampleNo - uSampleNo) < uSampleOffsetChunk)) {
         kal_uint32 i = pCurTrack->uCurSampleNo - uSampleNo + 1;
         while (--i > 0) {
            if ((ret=MP4_GetSampleOffset_Previous(pstMp4Parser, puSampleOffset, type))!=MP4_PARSER_OK)
               return ret;

			   // terminate by source
            if (pstMp4Parser->fgQuickClose == KAL_TRUE)
               return MP4_PARSER_PARSE_QUICK_CLOSED;
         }
#ifdef MP4_PARSER_TRC_LOG
         m_case = 3;
#endif
         goto MP4_GetSampleOffset_OK; //return MP4_PARSER_OK;
      }
   }

   {
      /// Case 4: General case, seek forward from the beginning of the chunk
      kal_uint32 j, k;
      kal_uint32 temp_offset;

      if ((ret=MP4_GetChunkOffset(pstMp4Parser, uSampleInChunk, &temp_offset, type))!=MP4_PARSER_OK)
         return ret;

      k = uSampleNo - uSampleOffsetChunk;
      for (j=uSampleOffsetChunk+1; --j>0; ) {
         kal_uint32 uSampleSize;
         if ((ret=MP4_GetSampleSize(pstMp4Parser, k++, &uSampleSize, type))!=MP4_PARSER_OK)
            return ret;
         temp_offset += uSampleSize;
      }
      *puSampleOffset = temp_offset;
      pCurTrack->uCurSampleNo         = uSampleNo;
      pCurTrack->uSampleInChunk_Cache = uSampleInChunk;
      pCurTrack->uSampleOffset_Cache  = temp_offset;
#ifdef MP4_PARSER_TRC_LOG
      m_case = 4;
#endif
      goto MP4_GetSampleOffset_OK; //return MP4_PARSER_OK;
   }
MP4_GetSampleOffset_OK:
#ifdef MP4_PARSER_TRC_LOG
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_GETSAMPLEOFFSET,pstMp4Parser->uParserFinish, m_case, uSampleNo,(int)(*puSampleOffset));
#endif
   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the file offset of the "NEXT" sample in the specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetSampleOffset_Next(STMp4Parser *pstMp4Parser, kal_uint32 *puSampleOffset, MP4_Track_Type type)
{
   kal_uint32 uSampleInChunk, uSampleOffsetChunk;
   kal_uint32 uSampleSize;
   MP4_Parser_Status ret;
   kal_uint8  bTrackNo;
   STMp4Track *pCurTrack;

   MP4_PARSER_CHECK_ARG(puSampleOffset!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, type, &bTrackNo))!=MP4_PARSER_OK)
      return ret;
   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   pCurTrack->uCurSampleNo++;

   /// locate the chuck of the sample
    if ((ret=MP4_GetChunkNoAndOffset_Next_Prev(pstMp4Parser, &uSampleInChunk, &uSampleOffsetChunk, type, KAL_TRUE))!=MP4_PARSER_OK) {
      return ret;
   }

   if (uSampleInChunk == pCurTrack->uSampleInChunk_Cache) {
      if ((ret=MP4_GetSampleSize(pstMp4Parser, pCurTrack->uCurSampleNo - 1, &uSampleSize, type))!=MP4_PARSER_OK) {
         return ret;
      }
      *puSampleOffset = pCurTrack->uSampleOffset_Cache + uSampleSize;
   } else {
      if ((ret=MP4_GetChunkOffset(pstMp4Parser, uSampleInChunk, puSampleOffset, type))!=MP4_PARSER_OK) {
      	 return ret;
      }
      pCurTrack->uSampleInChunk_Cache = uSampleInChunk;
   }

   pCurTrack->uSampleOffset_Cache = *puSampleOffset;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the file offset of the "PREVIOUS" sample in the specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetSampleOffset_Previous(STMp4Parser *pstMp4Parser, kal_uint32 *puSampleOffset, MP4_Track_Type type)
{
   kal_uint32 uSampleInChunk, uSampleOffsetChunk;
   kal_uint32 uSampleSize;
   MP4_Parser_Status ret;
   kal_uint8  bTrackNo;
   STMp4Track *pCurTrack;

   MP4_PARSER_CHECK_ARG(puSampleOffset!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, type, &bTrackNo))!=MP4_PARSER_OK)
      return ret;
   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   pCurTrack->uCurSampleNo--;

   /// locate the chuck of the sample
   if ((ret=MP4_GetChunkNoAndOffset_Next_Prev(pstMp4Parser, &uSampleInChunk, &uSampleOffsetChunk, type, KAL_FALSE))!=MP4_PARSER_OK) {
      return ret;
   }

   if (uSampleInChunk == pCurTrack->uSampleInChunk_Cache) {
      /// Get the size of current sample
      if ((ret=MP4_GetSampleSize(pstMp4Parser, pCurTrack->uCurSampleNo, &uSampleSize, type))!=MP4_PARSER_OK) {
         return ret;
      }
      *puSampleOffset = pCurTrack->uSampleOffset_Cache - uSampleSize;
   } else {
      kal_uint32 temp_offset, k, j;
      if ((ret=MP4_GetChunkOffset(pstMp4Parser, uSampleInChunk, &temp_offset, type))!=MP4_PARSER_OK) {
      	 return ret;
      }
      k = pCurTrack->uCurSampleNo - uSampleOffsetChunk;
      for (j=uSampleOffsetChunk+1; --j>0; ) {
         kal_uint32 uSampleSize;
         if ((ret=MP4_GetSampleSize(pstMp4Parser, k++, &uSampleSize, type))!=MP4_PARSER_OK)
            return ret;
         temp_offset += uSampleSize;
      }
      *puSampleOffset = temp_offset;
      pCurTrack->uSampleInChunk_Cache = uSampleInChunk;
   }
   pCurTrack->uSampleOffset_Cache = *puSampleOffset;

   return MP4_PARSER_OK;
}

#ifdef __VE_MP4_PARSER_SUPPORT_CTTS__
/* --------------------- Composition Time to Sample Table related functions --------------------- */

/*******************************************************************************
   Get the sample count of sample offset of the specified index in the CTTS table
   of the specified track.
*******************************************************************************/
static MP4_Parser_Status MP4_GetSampleCountAndOffset(STMp4Parser *pstMp4Parser, kal_uint32 uIndex,
                                                    kal_uint32 *puSampleCount, kal_uint32 *puSampleOffset,
                                                    MP4_Track_Type type)
{
   MP4_Parser_Status ret;
   kal_uint32 uOffset;
   kal_uint8 bTrackNo;
   STMp4Track *prTrack;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, type, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   prTrack = &pstMp4Parser->stMp4Track[bTrackNo];
   MP4_PARSER_ASSERT(uIndex < prTrack->uCTimeToSampleTableEntryCount);

   uOffset = prTrack->uCOffsetTimeToSampleTable;
   uOffset += (uIndex * 8);

   if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstMp4Parser->pstFSAL, uOffset))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   if ((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, puSampleCount))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if ((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, puSampleOffset))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if(prTrack->uSampleCount == 0)
   {
      return MP4_PARSER_PARSE_ERROR;
   }
   /// trick: use the average sample duration instead if the recorded one is negative.
   if (*puSampleOffset & 0x80000000) {
      *puSampleOffset = prTrack->uMediaDuration / prTrack->uSampleCount;
   }

   #if 0 // Pibben: why we need this?
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif

   return MP4_PARSER_OK;
}
#endif
/* --------------------- Decoding Time to Sample Table related functions --------------------- */

/*******************************************************************************
   Get the sample count of sample delta of the specified index in the STTS table
   of the specified track.
*******************************************************************************/
static MP4_Parser_Status MP4_GetSampleCountAndDelta(STMp4Parser *pstMp4Parser, kal_uint32 uIndex,
                                                    kal_uint32 *puSampleCount, kal_uint32 *puSampleDelta,
                                                    MP4_Track_Type type)
{
   MP4_Parser_Status ret;
   STMp4Track *prTrack;
   kal_uint32 uOffset;
   kal_uint8 bTrackNo;
   STFSAL *pstFSAL;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, type, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   prTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);
   MP4_PARSER_ASSERT(uIndex < prTrack->uTimeToSampleTableEntryCount);

   if (prTrack->pstFSAL_STTS)
   {
       pstFSAL = prTrack->pstFSAL_STTS;
   }
   else
   {
       pstFSAL = pstMp4Parser->pstFSAL;
   }

   uOffset = prTrack->uOffsetTimeToSampleTable;
   uOffset += (uIndex * 8);

   if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstFSAL, uOffset))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   if ((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstFSAL, puSampleCount))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if ((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstFSAL, puSampleDelta))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if(prTrack->uSampleCount == 0)
   {
      return MP4_PARSER_PARSE_ERROR;
   }

   /// trick: use the average sample duration instead if the recorded one is negative.
   if (*puSampleDelta & 0x80000000) {
      *puSampleDelta = prTrack->uMediaDuration / prTrack->uSampleCount;
   }

   /// to prevent from divided by zero
   if (*puSampleDelta == 0) {
      *puSampleDelta = 1;
   }

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the sample number with respect to the specified decoding time in the
   specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetSampleNumber(STMp4Parser *pstMp4Parser, kal_uint32 *puSampleNo,
                                      kal_uint64 uDecodeTime, MP4_Track_Type eTrackType)
{
   kal_uint64 uCurDecodeTime = 0;
   kal_uint32 uDecodeTimeToSampleTableSize;
   kal_uint32 uThisSampleCount;
   kal_uint32 uThisSampleDelta;
   kal_uint32 uCurSampleCount = 0;
   kal_uint32 uIndex = 0;
   kal_uint8  bTrackNo;
   MP4_Parser_Status ret;
   STMp4Track *pCurTrack;
   kal_uint32 uSampleCount;

   MP4_PARSER_CHECK_ARG(puSampleNo!=NULL);

   if ((ret=MP4_GetSampleCount(pstMp4Parser, eTrackType, &uSampleCount))!=MP4_PARSER_OK)
      return ret;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   if (pCurTrack->uSTTSCacheTableEntryCount > 0) {
      /// STTS cache is enabled. Perform bunary search.
      kal_uint16 start_index, end_index;
      STTS_Cache_Entry *stts_cache_table;

      stts_cache_table = pCurTrack->pSTTSCacheTable;

      do { /// Initial Cache
         if ((ret=MP4_STTS_ProcCacheTableByTrack(pstMp4Parser, eTrackType, 64 )) != MP4_PARSER_OK)
         		return ret;
      }
      while (pCurTrack->uSTTSCacheIndex != pCurTrack->uSTTSCacheTableEntryCount &&
          uDecodeTime > stts_cache_table[pCurTrack->uSTTSCacheIndex-1].accumulated_decode_time);

      start_index = 0;
      end_index = pCurTrack->uSTTSCacheIndex-1;
      while ((end_index-start_index)>1) {
         kal_uint16 middle_index = (start_index+end_index)>>1;
         if (uDecodeTime > stts_cache_table[middle_index].accumulated_decode_time)
            start_index = middle_index;
         else
            end_index = middle_index;
      }

      if (start_index) {
         uIndex = end_index * pCurTrack->uSTTSCacheTableStepSize;
         uCurSampleCount = stts_cache_table[start_index].accumulated_sample_count;
         uCurDecodeTime = stts_cache_table[start_index].accumulated_decode_time;
      }
   }

   uDecodeTimeToSampleTableSize = pCurTrack->uTimeToSampleTableEntryCount;

   for (; uIndex<uDecodeTimeToSampleTableSize; uIndex++) {
      if ((ret=MP4_GetSampleCountAndDelta(pstMp4Parser, uIndex, &uThisSampleCount, &uThisSampleDelta, eTrackType))!=MP4_PARSER_OK)
         return ret;
      uCurDecodeTime += (kal_uint64)uThisSampleCount * (kal_uint64)uThisSampleDelta;
      uCurSampleCount += uThisSampleCount;
      if (uCurDecodeTime >= uDecodeTime) {
         *puSampleNo = uCurSampleCount - (kal_uint32)((kal_uint64)(uCurDecodeTime-uDecodeTime+uThisSampleDelta-1)/(kal_uint64)uThisSampleDelta);
         if (*puSampleNo >= uSampleCount)
             *puSampleNo = uSampleCount - 1;

#ifdef MP4_PARSER_TRC_LOG_DEBUG1
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_GetSampleNumber,bTrackNo,(int)(*puSampleNo));
#endif
         return MP4_PARSER_OK;
      }
   }
#ifdef MP4_PARSER_TRC_LOG
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_GetSampleNumber_Err,bTrackNo,(int)uDecodeTime);
#endif
   return MP4_PARSER_NO_SUCH_SAMPLE;
}

/*******************************************************************************
   Get the decode time with respect to the specified sample number in the
   specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetDecodeTime(STMp4Parser *pstMp4Parser, kal_uint32 uSampleNo,
                                    kal_uint64 *puDecodeTime, MP4_Track_Type eTrackType )
{
   kal_uint32 uDecodeTimeToSampleTableSize;
   kal_uint32 uThisSampleCount;
   kal_uint32 uThisSampleDelta = 0;
   kal_uint32 uCurSampleCount = 0;
   kal_uint32 uIndex = 0;
   kal_uint32 uSampleCount;
   kal_uint8 bTrackNo;
   MP4_Parser_Status ret;
   STMp4Track *pCurTrack;

   MP4_PARSER_CHECK_ARG(puDecodeTime!=NULL);

   *puDecodeTime = 0;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;
   if ((ret=MP4_GetSampleCount(pstMp4Parser, eTrackType, &uSampleCount))!=MP4_PARSER_OK)
      return ret;
   //should only " > " not " >= ",due to video need to send index+1
   //to get the delta time of the last video frame
   if (uSampleNo > uSampleCount)
      return MP4_PARSER_NO_SUCH_SAMPLE;

   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   if (pCurTrack->uSTTSCacheTableEntryCount > 0) {
      /// STTS cache is enabled. Perform binary search.
      kal_uint16 start_index, end_index;
      STTS_Cache_Entry *stts_cache_table;

      stts_cache_table = pCurTrack->pSTTSCacheTable;

      do { /// Initial Cache
         if ((ret=MP4_STTS_ProcCacheTableByTrack(pstMp4Parser, eTrackType, 32 )) != MP4_PARSER_OK)
         		return ret;
      }
      while (pCurTrack->uSTTSCacheIndex != pCurTrack->uSTTSCacheTableEntryCount &&
          uSampleNo > stts_cache_table[pCurTrack->uSTTSCacheIndex-1].accumulated_sample_count);

      //binary search
      start_index = 0;
      end_index = pCurTrack->uSTTSCacheIndex-1;
      while ((end_index-start_index)>1) {
         kal_uint16 middle_index = (start_index+end_index)>>1;
         if (uSampleNo > stts_cache_table[middle_index].accumulated_sample_count)
            start_index = middle_index;
         else
            end_index = middle_index;
      }

      if (start_index) {
         uIndex = end_index * pCurTrack->uSTTSCacheTableStepSize;
         uCurSampleCount = stts_cache_table[start_index].accumulated_sample_count;
         *puDecodeTime = stts_cache_table[start_index].accumulated_decode_time;
      }
   }

   uDecodeTimeToSampleTableSize = pCurTrack->uTimeToSampleTableEntryCount;

   for (; uIndex<uDecodeTimeToSampleTableSize; uIndex++) {
      if ((ret=MP4_GetSampleCountAndDelta(pstMp4Parser, uIndex, &uThisSampleCount, &uThisSampleDelta, eTrackType))!=MP4_PARSER_OK)
         return ret;
      uCurSampleCount += uThisSampleCount;
      if (uCurSampleCount > uSampleNo) {
         *puDecodeTime += (kal_uint64)uThisSampleDelta * (kal_uint64)(uSampleNo - uCurSampleCount + uThisSampleCount );
         break;
      } else {
         *puDecodeTime += (kal_uint64)uThisSampleDelta * (kal_uint64)uThisSampleCount;
      }
   }

   /// if the decode time of the specified sample is 0, it is an error case.
   if (uSampleNo != 0 && *puDecodeTime == pCurTrack->uDecodeTime_PrevDecodeTime
       && uSampleNo != pCurTrack->uDecodeTime_SampleNo)
      return MP4_PARSER_PARSE_ERROR;

#ifdef MP4_PARSER_TRC_LOG
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_GETDECODETIME,pstMp4Parser->uParserFinish, bTrackNo, uSampleNo, (int)(*puDecodeTime));
#endif
   pCurTrack->uDecodeTime_SampleNo        = uSampleNo;
   pCurTrack->uDecodeTime_TableIndex      = uIndex;
   pCurTrack->uDecodeTime_PrevDecodeTime  = *puDecodeTime;
   pCurTrack->uDecodeTime_ThisSampleDelta = uThisSampleDelta;
   pCurTrack->uDecodeTime_CurSampleCount  = uCurSampleCount;
   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the decode time of the "NEXT" sample in the specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetDecodeTime_Next(STMp4Parser *pstMp4Parser, kal_uint64 *puDecodeTime,
                                         MP4_Track_Type eTrackType)
{
   MP4_Parser_Status ret;
   kal_uint32 uSampleNo;
   kal_uint32 uDecodeTimeToSampleTableSize;
   kal_uint32 uThisSampleCount;
   kal_uint32 uThisSampleDelta;
   kal_uint8  bTrackNo;
   STMp4Track *pCurTrack;

   MP4_PARSER_CHECK_ARG(puDecodeTime!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;
   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   uSampleNo = pCurTrack->uDecodeTime_SampleNo;
   pCurTrack->uDecodeTime_SampleNo++;

   if (uSampleNo < pCurTrack->uDecodeTime_CurSampleCount) {
      pCurTrack->uDecodeTime_PrevDecodeTime += pCurTrack->uDecodeTime_ThisSampleDelta;
      *puDecodeTime = pCurTrack->uDecodeTime_PrevDecodeTime;
      return MP4_PARSER_OK;
   }

   pCurTrack->uDecodeTime_TableIndex++;

   uDecodeTimeToSampleTableSize = pCurTrack->uTimeToSampleTableEntryCount;

   if (pCurTrack->uDecodeTime_TableIndex >= uDecodeTimeToSampleTableSize)
      return MP4_PARSER_READ_EOF;

   if ((ret=MP4_GetSampleCountAndDelta(pstMp4Parser, pCurTrack->uDecodeTime_TableIndex, &uThisSampleCount, &uThisSampleDelta, eTrackType))!=MP4_PARSER_OK)
      return ret;

   pCurTrack->uDecodeTime_PrevDecodeTime += uThisSampleDelta;
   pCurTrack->uDecodeTime_CurSampleCount += uThisSampleCount;
   pCurTrack->uDecodeTime_ThisSampleDelta = uThisSampleDelta;
   *puDecodeTime = pCurTrack->uDecodeTime_PrevDecodeTime;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the composition time with respect to the specified sample number in the
   specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetCompositionTime(STMp4Parser *pstMp4Parser, kal_uint32 uSampleNo,
                                         kal_uint64 *puTime, MP4_Track_Type eTrackType)
{
   kal_uint8  bTrackNo;
   MP4_Parser_Status ret;
#ifdef __VE_MP4_PARSER_SUPPORT_CTTS__
    kal_uint32 uCompositionTimeToSampleTableSize;
    kal_uint32 uThisSampleCount;
    kal_uint32 uThisSampleDelta = 0;
    kal_uint32 uCurSampleCount = 0;
    kal_uint32 uIndex = 0;
    STMp4Track *pCurTrack;
#endif

   MP4_PARSER_CHECK_ARG(puTime!=NULL);

   *puTime = 0;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

#ifdef __VE_MP4_PARSER_SUPPORT_CTTS__
   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);
   if(pCurTrack->bHasCTTS){
      if (pCurTrack->uCTTSCacheTableEntryCount > 0) {
         /// CTTS cache is enabled. Perform binary search.
         kal_uint16 start_index, end_index;
         CTTS_Cache_Entry *ctts_cache_table;

         ctts_cache_table = pCurTrack->pCTTSCacheTable;

         do { /// Initial Cache
            if ((ret=MP4_CTTS_ProcCacheTableByTrack(pstMp4Parser, eTrackType, 32 ))!=MP4_PARSER_OK)
            	return ret;
         }
         while (pCurTrack->uCTTSCacheIndex != pCurTrack->uCTTSCacheTableEntryCount &&
             uSampleNo > ctts_cache_table[pCurTrack->uCTTSCacheIndex-1].accumulated_sample_count);

         start_index = 0;
         end_index = pCurTrack->uCTTSCacheIndex-1;
         while ((end_index-start_index)>1) {
            kal_uint16 middle_index = (start_index+end_index)>>1;
            if (uSampleNo > ctts_cache_table[middle_index].accumulated_sample_count)
               start_index = middle_index;
            else
               end_index = middle_index;
         }

         if (start_index) {
            uIndex = end_index * pCurTrack->uCTTSCacheTableStepSize;
            uCurSampleCount = ctts_cache_table[start_index].accumulated_sample_count;
         }
      }

      uCompositionTimeToSampleTableSize = pCurTrack->uCTimeToSampleTableEntryCount;

      for (; uIndex<uCompositionTimeToSampleTableSize; uIndex++) {
         if ((ret=MP4_GetSampleCountAndOffset(pstMp4Parser, uIndex, &uThisSampleCount, &uThisSampleDelta, eTrackType))!=MP4_PARSER_OK)
            return ret;
         uCurSampleCount += uThisSampleCount;
         if (uCurSampleCount > uSampleNo)
         {
               kal_uint64 uDecodeTime;
               if ((ret=MP4_GetDecodeTime(pstMp4Parser, uSampleNo, &uDecodeTime, eTrackType))!=MP4_PARSER_OK)
                  return ret;
               *puTime = uDecodeTime + uThisSampleDelta;
            break;
         }
      }

      pCurTrack->uCompositionTime_SampleNo        = uSampleNo + 1;
      pCurTrack->uCompositionTime_TableIndex      = uIndex;
      pCurTrack->uCompositionTime_ThisSampleDelta = uThisSampleDelta;
      pCurTrack->uCompositionTime_CurSampleCount  = uCurSampleCount;
   }
   else
#endif
   {
      //here should use (uSampleNo + 1) to get DecodeTime to present CompositionTime , but not do this
      //due to [VID] task design. Should be modified on other design.
      if ((ret=MP4_GetDecodeTime(pstMp4Parser, uSampleNo, puTime, eTrackType))!=MP4_PARSER_OK)
         return ret;
   }
#ifdef MP4_PARSER_TRC_LOG
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_GetCompositionTime,bTrackNo,uSampleNo,(int)(*puTime));
#endif

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the composition time of the "NEXT" sample in the specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetCompositionTime_Next(STMp4Parser *pstMp4Parser, kal_uint64 *puTime,
                                              MP4_Track_Type eTrackType)
{
   MP4_Parser_Status ret;
   kal_uint8  bTrackNo;
   kal_uint64 uDecodeTime;

#ifdef __VE_MP4_PARSER_SUPPORT_CTTS__
   kal_uint32 uSampleNo;
   kal_uint32 uCompositionTimeToSampleTableSize;
   kal_uint32 uThisSampleCount;
   kal_uint32 uThisSampleDelta;
   STMp4Track *pCurTrack;
#endif

   MP4_PARSER_CHECK_ARG(puTime!=NULL);

   if ((ret=MP4_GetDecodeTime_Next(pstMp4Parser, &uDecodeTime, eTrackType))!=MP4_PARSER_OK)
      return ret;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

#ifdef __VE_MP4_PARSER_SUPPORT_CTTS__
   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);
   if(pCurTrack->bHasCTTS){
      uSampleNo = pCurTrack->uCompositionTime_SampleNo;
      pCurTrack->uCompositionTime_SampleNo++;

      if (uSampleNo < pCurTrack->uCompositionTime_CurSampleCount) {
         *puTime = uDecodeTime + pCurTrack->uCompositionTime_ThisSampleDelta;
         return MP4_PARSER_OK;
      }

      pCurTrack->uCompositionTime_TableIndex++;

      uCompositionTimeToSampleTableSize = pCurTrack->uCTimeToSampleTableEntryCount;

      if (pCurTrack->uCompositionTime_TableIndex >= uCompositionTimeToSampleTableSize)
         return MP4_PARSER_READ_EOF;

      if ((ret=MP4_GetSampleCountAndOffset(pstMp4Parser, pCurTrack->uCompositionTime_TableIndex, &uThisSampleCount, &uThisSampleDelta, eTrackType))!=MP4_PARSER_OK)
         return ret;

      pCurTrack->uCompositionTime_CurSampleCount += uThisSampleCount;
      pCurTrack->uCompositionTime_ThisSampleDelta = uThisSampleDelta;
      *puTime = uDecodeTime + uThisSampleDelta;
   }
   else
#endif
    {
      *puTime = uDecodeTime;
   }

   return MP4_PARSER_OK;
}

/* --------------------- Sync Sample Box related functions --------------------- */

/*******************************************************************************
   Get the sync sample number with respect to the given index in the sync
   sample table of the specified track.
*******************************************************************************/
static MP4_Parser_Status MP4_GetSyncSampleNo(STMp4Parser *pstMp4Parser, kal_uint32 uIndex,
                                             kal_uint32 *puSyncSampleNo, MP4_Track_Type type)
{
   MP4_Parser_Status ret;
   kal_uint32 uOffset;
   kal_uint8 bTrackNo;
   STFSAL *pstFSAL;
   STMp4Track *prTrack;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, type, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   prTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);
   MP4_PARSER_ASSERT(uIndex < prTrack->uSyncCount);

#if defined(__VIDEO_ARCHI_V2__)
   if (prTrack->pstFSAL_STSS)
      pstFSAL = prTrack->pstFSAL_STSS;
   else
#endif
      pstFSAL = pstMp4Parser->pstFSAL;

   uOffset = prTrack->uOffsetSyncSampleTable;
   uOffset += (uIndex * 4);

   if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstFSAL, uOffset))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   if ((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstFSAL, puSyncSampleNo))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   /// Change starting number of index from 1 to 0.
   *puSyncSampleNo -= 1;

#ifdef MP4_PARSER_TRC_LOG_DEBUG1
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_GetSyncSampleNo,bTrackNo,(int)(*puSyncSampleNo));
#endif
   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the sample number of the previous sync sample of the specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetPrevSyncSampleNo(STMp4Parser *pstMp4Parser, kal_uint32 uCurSampleNo,
                                          kal_uint32 *puPrevSyncSampleNo, MP4_Track_Type eTrackType)
{
   kal_uint32 uSyncSampleNo = 0;
   kal_uint32 uStartIndex, uEndIndex;
   kal_uint8 bTrackNo;
   MP4_Parser_Status ret;
   STMp4Track *pCurTrack;

   MP4_PARSER_CHECK_ARG(puPrevSyncSampleNo!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

#ifdef MP4_PARSER_TRC_LOG_DEBUG1
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_GetPrevSyncSampleNo,bTrackNo);
#endif

   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);
   uEndIndex = pCurTrack->uSyncCount;

   /// If the Sync Sample Box is not present, every sample is a random access point.
   if(!pCurTrack->bHasSTSS || pCurTrack->uSyncCount == 0) {
      *puPrevSyncSampleNo = uCurSampleNo;
      return MP4_PARSER_OK;
   }

   if (uEndIndex==0) {
      *puPrevSyncSampleNo = 0;
      return MP4_PARSER_OK;
   }
#ifndef __LOW_COST_SUPPORT_COMMON__
   if (pCurTrack->uSTSSCacheTableEntryCount > 0) {
      /// STSS cache is enabled. Perform binary search.
      kal_uint16 start_index, end_index;
      STSS_Cache_Entry *stss_cache_table;

      stss_cache_table = pCurTrack->pSTSSCacheTable;
      if(pCurTrack->uSTSSCacheIndex < 1)
         return MP4_PARSER_INTERNAL_ERROR;
      do { /// Initial Cache
         if ((ret=MP4_STSS_ProcCacheTableByTrack(pstMp4Parser, eTrackType, 4 )) != MP4_PARSER_OK)
				    return ret;
      }
      while (pCurTrack->uSTSSCacheIndex != pCurTrack->uSTSSCacheTableEntryCount &&
          uCurSampleNo > stss_cache_table[pCurTrack->uSTSSCacheIndex-1].sample_number);

      start_index = 0;
      end_index = pCurTrack->uSTSSCacheIndex-1;
      while ((end_index-start_index)>1) {
         kal_uint16 middle_index = (start_index+end_index)>>1;
         if (uCurSampleNo > stss_cache_table[middle_index].sample_number)
            start_index = middle_index;
         else
            end_index = middle_index;
      }
      if (uCurSampleNo < stss_cache_table[end_index].sample_number)
      {
         uStartIndex = start_index * pCurTrack->uSTSSCacheTableStepSize;
         uEndIndex = end_index * pCurTrack->uSTSSCacheTableStepSize;
      }
      else
      {
         uStartIndex = end_index * pCurTrack->uSTSSCacheTableStepSize;
         //uEndIndex --;
      }
   }
   else {
      uStartIndex = 0;
      //uEndIndex --;
   }
#else
    uStartIndex = 0;
#endif

   /// Perform binary search
   while ((uEndIndex-uStartIndex)>1) {
      kal_uint32 uMiddleIndex = (uStartIndex+uEndIndex)>>1;
      if ((ret=MP4_GetSyncSampleNo(pstMp4Parser, uMiddleIndex, &uSyncSampleNo, eTrackType))!=MP4_PARSER_OK)
         return ret;
      if (uCurSampleNo > uSyncSampleNo)
         uStartIndex = uMiddleIndex;
      else
         uEndIndex = uMiddleIndex;
   }
   if ((ret=MP4_GetSyncSampleNo(pstMp4Parser, uStartIndex, puPrevSyncSampleNo, eTrackType))!=MP4_PARSER_OK)
      return ret;
   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the sample number of the next sync sample of the specified track.
*******************************************************************************/
MP4_Parser_Status MP4_GetNextSyncSampleNo(STMp4Parser *pstMp4Parser, kal_uint32 uCurSampleNo,
                                          kal_uint32 *puNextSyncSampleNo, MP4_Track_Type eTrackType)
{
   kal_uint32 uSyncSampleNo = 0;
   kal_uint32 uSampleCount;
   kal_uint32 uStartIndex, uEndIndex;
   kal_uint8 bTrackNo;
   MP4_Parser_Status ret;
   STMp4Track *pCurTrack;

   MP4_PARSER_CHECK_ARG(puNextSyncSampleNo!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   if ((ret=MP4_GetSampleCount(pstMp4Parser, eTrackType, &uSampleCount))!=MP4_PARSER_OK)
      return ret;

   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);
   uEndIndex = pCurTrack->uSyncCount;

   /// If the Sync Sample Box is not present, every sample is a random access point.
   if(!pCurTrack->bHasSTSS || pCurTrack->uSyncCount == 0) {
      if((uCurSampleNo+1) < (uSampleCount-1))
         *puNextSyncSampleNo = uCurSampleNo+1;
      else
         *puNextSyncSampleNo = uSampleCount-1;
      return MP4_PARSER_OK;
   }

   if (uEndIndex==0) {
      *puNextSyncSampleNo = 0;
      return MP4_PARSER_OK;
   }
#ifndef __LOW_COST_SUPPORT_COMMON__
   if (pCurTrack->uSTSSCacheTableEntryCount > 0) {
      /// STSS cache is enabled. Perform binary search.
      kal_uint16 start_index, end_index;
      STSS_Cache_Entry *stss_cache_table;

      stss_cache_table = pCurTrack->pSTSSCacheTable;
      if(pCurTrack->uSTSSCacheIndex < 1)
         return MP4_PARSER_INTERNAL_ERROR;
      do { /// Initial Cache
         if ((ret=MP4_STSS_ProcCacheTableByTrack(pstMp4Parser, eTrackType, 4 )) != MP4_PARSER_OK)
            return ret;
      }
      while (pCurTrack->uSTSSCacheIndex != pCurTrack->uSTSSCacheTableEntryCount &&
          uCurSampleNo >= stss_cache_table[pCurTrack->uSTSSCacheIndex-1].sample_number);

      start_index = 0;
      end_index = pCurTrack->uSTSSCacheIndex-1;
      while ((end_index-start_index)>1) {
         kal_uint16 middle_index = (start_index+end_index)>>1;
         if (uCurSampleNo >= stss_cache_table[middle_index].sample_number)
            start_index = middle_index;
         else
            end_index = middle_index;
      }
      uStartIndex = start_index * pCurTrack->uSTSSCacheTableStepSize;
      uEndIndex = end_index * pCurTrack->uSTSSCacheTableStepSize;
   }
   else {
      uStartIndex = 0;
      uEndIndex --;
   }
#else
          uStartIndex = 0;
      uEndIndex --;
#endif

   /// Perform binary search
   while ((uEndIndex-uStartIndex)>1) {
      kal_uint32 uMiddleIndex = (uStartIndex+uEndIndex)>>1;
      if ((ret=MP4_GetSyncSampleNo(pstMp4Parser, uMiddleIndex, &uSyncSampleNo, eTrackType))!=MP4_PARSER_OK)
         return ret;
      if (uCurSampleNo >= uSyncSampleNo)
         uStartIndex = uMiddleIndex;
      else
         uEndIndex = uMiddleIndex;
   }
   if ((ret=MP4_GetSyncSampleNo(pstMp4Parser, uEndIndex, puNextSyncSampleNo, eTrackType))!=MP4_PARSER_OK)
      return ret;
   return MP4_PARSER_OK;
}

/*******************************************************************************
   Check if it is a sync sample number of the specified track.
*******************************************************************************/
MP4_Parser_Status MP4_ChkIsSyncSample(STMp4Parser *pstMp4Parser, kal_uint32 uCurSampleNo,
                                      MP4_Track_Type eTrackType, kal_bool *pbIsSync,
                                      kal_uint32 *puSTSSNextIdx)
{
   kal_uint32 uSyncSampleNo = 0;
   kal_uint32 uStartIndex, uEndIndex, uIdx;
   kal_uint8 bTrackNo;
   MP4_Parser_Status ret;
   STMp4Track *pCurTrack;

   MP4_PARSER_CHECK_ARG(pbIsSync != NULL | puSTSSNextIdx != NULL);

   *pbIsSync = KAL_FALSE;

   if ((ret = MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo)) != MP4_PARSER_OK)
      return ret;

   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);
   uEndIndex = pCurTrack->uSyncCount;

   /// If the Sync Sample Box is not present, every sample is a random access point.
   if(!pCurTrack->bHasSTSS || pCurTrack->uSyncCount == 0) {
      *pbIsSync = KAL_TRUE;
      return MP4_PARSER_OK;
   }

   if (uEndIndex == 0) {
      if (uCurSampleNo == 0)
         *pbIsSync = KAL_TRUE;
      return MP4_PARSER_OK;
   }
#ifndef __LOW_COST_SUPPORT_COMMON__
   if (pCurTrack->uSTSSCacheTableEntryCount > 0) {
      /// STSS cache is enabled. Perform binary search.
      kal_uint16 start_index, end_index;
      STSS_Cache_Entry *stss_cache_table;

      stss_cache_table = pCurTrack->pSTSSCacheTable;
      if(pCurTrack->uSTSSCacheIndex < 1)
         return MP4_PARSER_INTERNAL_ERROR;
      do { /// Initial Cache
         if ((ret=MP4_STSS_ProcCacheTableByTrack(pstMp4Parser, eTrackType, 4 )) != MP4_PARSER_OK)
                    return ret;
      }
      while (pCurTrack->uSTSSCacheIndex != pCurTrack->uSTSSCacheTableEntryCount &&
          uCurSampleNo > stss_cache_table[pCurTrack->uSTSSCacheIndex-1].sample_number);

      start_index = 0;
      end_index = pCurTrack->uSTSSCacheIndex-1;
      while ((end_index-start_index)>1) {
         kal_uint16 middle_index = (start_index+end_index)>>1;
         if (uCurSampleNo > stss_cache_table[middle_index].sample_number)
            start_index = middle_index;
         else
            end_index = middle_index;
      }
      uStartIndex = start_index * pCurTrack->uSTSSCacheTableStepSize;
      uEndIndex = end_index * pCurTrack->uSTSSCacheTableStepSize;
   }
   else {
      uStartIndex = 0;
      uEndIndex --;
   }
#else
      uStartIndex = 0;
      uEndIndex --;
#endif

   /// Perform binary search
   while ((uEndIndex-uStartIndex)>1) {
      kal_uint32 uMiddleIndex = (uStartIndex+uEndIndex)>>1;
      if ((ret=MP4_GetSyncSampleNo(pstMp4Parser, uMiddleIndex, &uSyncSampleNo, eTrackType))!=MP4_PARSER_OK)
         return ret;
      if (uCurSampleNo > uSyncSampleNo)
         uStartIndex = uMiddleIndex;
      else
         uEndIndex = uMiddleIndex;
   }

   *pbIsSync = KAL_FALSE;
   for (uIdx = uStartIndex; uIdx < pCurTrack->uSyncCount; uIdx++) {
      if ((ret = MP4_GetSyncSampleNo(pstMp4Parser, uIdx, &uSyncSampleNo, eTrackType))!=MP4_PARSER_OK)
         return ret;
      if (uSyncSampleNo == uCurSampleNo) {
         *pbIsSync = KAL_TRUE;
         break;
      }
      else if (uSyncSampleNo > uCurSampleNo) {
         break;
      }
   }

   *puSTSSNextIdx = uIdx;
   return MP4_PARSER_OK;
}

MP4_Parser_Status MP4_ChkIsSyncSample_Next(STMp4Parser *pstMp4Parser, kal_uint32 uCurSampleNo,
                                           MP4_Track_Type eTrackType, kal_bool *pbIsSync,
                                           kal_uint32 *puSTSSNextIdx)
{
   kal_uint32 uSyncSampleNo = 0;
   kal_uint8 bTrackNo;
   MP4_Parser_Status ret;
   STMp4Track *pCurTrack;
   kal_uint32 uIdx;

   MP4_PARSER_CHECK_ARG(pbIsSync != NULL | puSTSSNextIdx != NULL);

   uIdx = *puSTSSNextIdx;
   *pbIsSync = KAL_FALSE;

   if ((ret = MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo)) != MP4_PARSER_OK)
      return ret;

   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   /// If the Sync Sample Box is not present, every sample is a random access point.
   if(!pCurTrack->bHasSTSS || pCurTrack->uSyncCount == 0) {
      *pbIsSync = KAL_TRUE;
      return MP4_PARSER_OK;
   }

   if (pCurTrack->uSyncCount == 0) {
      if (uCurSampleNo == 0)
         *pbIsSync = KAL_TRUE;
      return MP4_PARSER_OK;
   }

   if (uIdx >= pCurTrack->uSyncCount)
      return MP4_PARSER_OK;

   if ((ret = MP4_GetSyncSampleNo(pstMp4Parser, uIdx, &uSyncSampleNo, eTrackType))!=MP4_PARSER_OK)
      return ret;
   if (uSyncSampleNo == uCurSampleNo) {
      *pbIsSync = KAL_TRUE;
      *puSTSSNextIdx = uIdx + 1;
   }

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the audio type of the MP4 parser.
*******************************************************************************/
MP4_Audio_Type MP4_GetAudioType(STMp4Parser *pstMp4Parser)
{
   if (pstMp4Parser!=NULL)
      return pstMp4Parser->bAudioType[pstMp4Parser->bAudioTrack];
   else
      return MP4_AUDIO_NONE;
}

/*******************************************************************************
   Get the video type of the MP4 parser.
*******************************************************************************/
MP4_Video_Type MP4_GetVideoType(STMp4Parser *pstMp4Parser)
{
   if (pstMp4Parser!=NULL)
      return pstMp4Parser->bVideoType[pstMp4Parser->bVideoTrack];
   else
      return MP4_VIDEO_NONE;
}

/*******************************************************************************
   Get the offset of VOS.
*******************************************************************************/
kal_uint32 MP4_Video_GetVOSOffset(STMp4Parser *pstMp4Parser)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_ASSERT(MP4_VIDEO_MPEG4==MP4_GetVideoType(pstMp4Parser));

   return pstMp4Parser->uVOSOffset;
}

/*******************************************************************************
   Get the size of VOS.
*******************************************************************************/
kal_uint32 MP4_Video_GetVOSSize(STMp4Parser *pstMp4Parser)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_ASSERT(MP4_VIDEO_MPEG4==MP4_GetVideoType(pstMp4Parser));

   return pstMp4Parser->uVOSSize;
}

#ifdef __VE_H264_DEC_SUPPORT__
/*******************************************************************************
   Get the offset of parameter set.
*******************************************************************************/
kal_uint32 MP4_Video_GetParameterSetOffset(STMp4Parser *pstMp4Parser, kal_uint32 current_frame)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_ASSERT(MP4_VIDEO_H264==MP4_GetVideoType(pstMp4Parser));

   return pstMp4Parser->stMp4AVC.uParameterSetOffset;
}

/*******************************************************************************
   Get the size of parameter set.
*******************************************************************************/
kal_uint32 MP4_Video_GetParameterSetSize(STMp4Parser *pstMp4Parser, kal_uint32 current_frame)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_ASSERT(MP4_VIDEO_H264==MP4_GetVideoType(pstMp4Parser));

   return pstMp4Parser->stMp4AVC.uParameterSetSize;
}

/*******************************************************************************
   Get the offset of AVC config.
*******************************************************************************/
kal_uint32 MP4_Video_GetAVCConfigOffset(STMp4Parser *pstMp4Parser)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_ASSERT(MP4_VIDEO_H264==MP4_GetVideoType(pstMp4Parser));

   return pstMp4Parser->stMp4AVC.uConfigOffset;
}

/*******************************************************************************
   Get the size of AVC config.
*******************************************************************************/
kal_uint32 MP4_Video_GetAVCConfigSize(STMp4Parser *pstMp4Parser)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_ASSERT(MP4_VIDEO_H264==MP4_GetVideoType(pstMp4Parser));

   return pstMp4Parser->stMp4AVC.uConfigSize;
}

STAVCInfo* MP4_Video_GetAVCConfigRecord(STMp4Parser *pstMp4Parser)
{
    return &(pstMp4Parser->stMp4AVC);
}
#endif

/*******************************************************************************
   Set the FSAL interface for STCO box.
*******************************************************************************/
MP4_Parser_Status MP4_SetFSAL_STCO(STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, STFSAL *pstFSAL)
{
   MP4_Parser_Status ret;
   kal_uint8 bTrackNo;

   MP4_PARSER_CHECK_ARG(pstFSAL!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   pstMp4Parser->stMp4Track[bTrackNo].pstFSAL_STCO = pstFSAL;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Set the FSAL interface for STSZ box.
*******************************************************************************/
MP4_Parser_Status MP4_SetFSAL_STSZ(STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, STFSAL *pstFSAL)
{
   MP4_Parser_Status ret;
   kal_uint8 bTrackNo;

   MP4_PARSER_CHECK_ARG(pstFSAL!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   pstMp4Parser->stMp4Track[bTrackNo].pstFSAL_STSZ = pstFSAL;

   return MP4_PARSER_OK;
}

#if defined(__VIDEO_ARCHI_V2__)
/*******************************************************************************
   Set the FSAL interface for STSS box.
*******************************************************************************/
MP4_Parser_Status MP4_SetFSAL_STSS(STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, STFSAL *pstFSAL)
{
   MP4_Parser_Status ret;
   kal_uint8 bTrackNo;

   MP4_PARSER_CHECK_ARG(pstFSAL!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   pstMp4Parser->stMp4Track[bTrackNo].pstFSAL_STSS = pstFSAL;

   return MP4_PARSER_OK;
}
#endif

/*******************************************************************************
   Set the FSAL interface for STTS box.
*******************************************************************************/
MP4_Parser_Status MP4_SetFSAL_STTS(STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, STFSAL *pstFSAL)
{
   MP4_Parser_Status ret;
   kal_uint8 bTrackNo;

   MP4_PARSER_CHECK_ARG(pstFSAL!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   pstMp4Parser->stMp4Track[bTrackNo].pstFSAL_STTS = pstFSAL;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Update the sample count. Compare the sample count calculated from STSC and
   stored in STSZ and make the smaller one to be the real sample count.
*******************************************************************************/
//until 1132
MP4_Parser_Status MP4_UpdateSampleCount(STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType)
{
   kal_uint32 uSampleToChunkIndex;
   kal_uint32 uFirstChunk, uLastChunk;
   kal_uint32 uSampleToChunkEntryCount;
   kal_uint32 uSampleSum = 0;
   kal_uint32 uSamplePerChunk;
   kal_uint8  bTrackNo;
   STMp4Track *pCurTrack;
   MP4_Parser_Status ret;

   if ((ret = MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

#ifdef MP4_PARSER_TRC_LOG_DEBUG1
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_UpdateSampleCount,bTrackNo);
#endif

   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   if (pCurTrack->bSampleCountUpdated)
      return MP4_PARSER_OK;

   if ((ret = MP4_GetSampleToChunkEntryCount(pstMp4Parser, eTrackType, &uSampleToChunkEntryCount))!=MP4_PARSER_OK)
      return ret;

   pCurTrack->uSampleToChunkEntryCount = uSampleToChunkEntryCount;
   if(uSampleToChunkEntryCount == 0)
      return MP4_PARSER_SAMPLECHUNK_ENTRY_ERROR;
   uSampleToChunkEntryCount--;
   for (uSampleToChunkIndex=0; uSampleToChunkIndex<uSampleToChunkEntryCount; uSampleToChunkIndex++) {
      // terminate by source
      if (pstMp4Parser->fgQuickClose == KAL_TRUE)
         return MP4_PARSER_PARSE_QUICK_CLOSED; 

      if ((ret = MP4_GetSamplePerChunkInRun(pstMp4Parser, uSampleToChunkIndex, &uSamplePerChunk, eTrackType))!=MP4_PARSER_OK)
         return ret;
      if ((ret = MP4_GetFirstChunkInRun(pstMp4Parser, uSampleToChunkIndex+1, &uLastChunk, eTrackType))!=MP4_PARSER_OK)
         return ret;
      if ((ret = MP4_GetFirstChunkInRun(pstMp4Parser, uSampleToChunkIndex, &uFirstChunk, eTrackType))!=MP4_PARSER_OK)
         return ret;
      uSampleSum += (uLastChunk - uFirstChunk)*uSamplePerChunk;
   }
   // handle the last entry
   if ((ret = MP4_GetSamplePerChunkInRun(pstMp4Parser, uSampleToChunkIndex, &uSamplePerChunk, eTrackType))!=MP4_PARSER_OK)
         return ret;
   if ((ret = MP4_GetChunkCount(pstMp4Parser, eTrackType, &uLastChunk))!=MP4_PARSER_OK)
        return ret;
   if ((ret = MP4_GetFirstChunkInRun(pstMp4Parser, uSampleToChunkIndex, &uFirstChunk, eTrackType))!=MP4_PARSER_OK)
         return ret;
   uSampleSum += (uLastChunk - uFirstChunk)*uSamplePerChunk;

   if( pCurTrack->uSampleCount > uSampleSum )
      pCurTrack->uSampleCount = uSampleSum;
   pCurTrack->bSampleCountUpdated = KAL_TRUE;

   return MP4_PARSER_OK;
}
#ifdef __VE_MP4_PARSER_SUPPORT_CTTS__
/******************************************************************************* // JF
   Initialize the CTTS cache of the specified track.
*******************************************************************************/
static MP4_Parser_Status MP4_CTTS_InitCacheTableByTrack( STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType,
                                                         void *pCacheTable, kal_uint32 uCTTSCacheTableCount,
                                                         kal_uint32 *puCTTSCacheTblCntExist)
{
   kal_uint32 uThisSampleCount;
   kal_uint32 uThisSampleDelta;
   kal_uint32 uIndex = 0;
   kal_uint32 uCTTSEntryCount = 0;
   kal_uint32 uCurSampleCount = 0;
   kal_uint64 uCurCompositionTime = 0;
   kal_uint16 uCacheIndex = 0;
   kal_uint16 uStepSize = 0;
   kal_uint16 uStepCounter = 0;
   kal_uint8  bTrackNo;
   MP4_Parser_Status ret;
   CTTS_Cache_Entry* pCTTSCacheTable;
   STMp4Track *prTrack;

   *puCTTSCacheTblCntExist = 0;
   pCTTSCacheTable = (CTTS_Cache_Entry *)pCacheTable;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   prTrack = &pstMp4Parser->stMp4Track[bTrackNo];

   if ((0==uCTTSCacheTableCount) || (0==prTrack->uCTimeToSampleTableEntryCount))
      return MP4_PARSER_OK;

   uStepSize = (prTrack->uCTimeToSampleTableEntryCount+uCTTSCacheTableCount-1) / uCTTSCacheTableCount;
   /* avoid divide-by-zero */
   if (0 == uStepSize)
      uStepSize = 1;
   uCTTSCacheTableCount = prTrack->uCTimeToSampleTableEntryCount / uStepSize;

   /// In the initialization, process at most 2048 CTTS entries to prevent the response time
   /// from being too long.
   uCTTSEntryCount = prTrack->uCTimeToSampleTableEntryCount;
   if (uCTTSEntryCount > 4096)
      uCTTSEntryCount = 4096;
   for (uIndex=0; uIndex<uCTTSEntryCount; uIndex++) {
      if ((ret=MP4_GetSampleCountAndOffset(pstMp4Parser, uIndex, &uThisSampleCount, &uThisSampleDelta, eTrackType))!=MP4_PARSER_OK)
         return ret;
      uCurSampleCount += uThisSampleCount;
      uCurCompositionTime += (kal_uint64)uThisSampleDelta * (kal_uint64)uThisSampleCount;
      uStepCounter++;
      if (uStepCounter == uStepSize) {
         uStepCounter = 0;
         pCTTSCacheTable[uCacheIndex].accumulated_sample_count = uCurSampleCount;
         pCTTSCacheTable[uCacheIndex++].accumulated_composition_time = uCurCompositionTime;
         if( uCacheIndex == uCTTSCacheTableCount )
            break;
      }
   }
   prTrack->uCTTSStepCounter          = uStepCounter;
   prTrack->uCTTSCurSampleCount       = uCurSampleCount;
   prTrack->uCTTSCurCompositionTime   = uCurCompositionTime;
   prTrack->uCTTSCacheIndex           = uCacheIndex;
   prTrack->uCTTSIndex                = uIndex;
   prTrack->pCTTSCacheTable           = pCTTSCacheTable;
   prTrack->uCTTSCacheTableStepSize   = uStepSize;
   prTrack->uCTTSCacheTableEntryCount = uCTTSCacheTableCount;

   *puCTTSCacheTblCntExist = uCTTSCacheTableCount;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Process certain number of CTTS cache of the specified track.
   uCount is the number of CTTS entries to be processed.
*******************************************************************************/
static MP4_Parser_Status MP4_CTTS_ProcCacheTableByTrack( STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, kal_uint16 uCount )
{
   kal_uint32 uIndex, local_counter;
   kal_uint32 uCTTSEntryCount, uCTTSCacheTableCount;
   kal_uint32 uThisSampleCount;
   kal_uint32 uThisSampleDelta;
   kal_uint32 uCurSampleCount;
   kal_uint64 uCurCompositionTime;
   kal_uint16 uCacheIndex;
   kal_uint16 uStepSize;
   kal_uint16 uStepCounter;
   kal_uint8  bTrackNo;
   MP4_Parser_Status ret;
   CTTS_Cache_Entry *pCTTSCacheTable;
   STMp4Track *pCurTrack;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;
   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   uCacheIndex          = pCurTrack->uCTTSCacheIndex;
   uCTTSCacheTableCount = pCurTrack->uCTTSCacheTableEntryCount;

   if (uCTTSCacheTableCount==0 || uCacheIndex==uCTTSCacheTableCount)
      return MP4_PARSER_OK;

   uCTTSEntryCount      = pCurTrack->uCTimeToSampleTableEntryCount;
   uStepCounter         = pCurTrack->uCTTSStepCounter;
   uCurSampleCount      = pCurTrack->uCTTSCurSampleCount;
   uCurCompositionTime  = pCurTrack->uCTTSCurCompositionTime;
   uIndex               = pCurTrack->uCTTSIndex;
   pCTTSCacheTable      = pCurTrack->pCTTSCacheTable;
   uStepSize            = pCurTrack->uCTTSCacheTableStepSize;

   for (local_counter=0; uIndex<uCTTSEntryCount && local_counter<uCount; uIndex++, local_counter++) {
      if ((ret=MP4_GetSampleCountAndOffset(pstMp4Parser, uIndex, &uThisSampleCount, &uThisSampleDelta, eTrackType))!=MP4_PARSER_OK)
         return ret;
      uCurSampleCount += uThisSampleCount;
      uCurCompositionTime += (kal_uint64)uThisSampleDelta * (kal_uint64)uThisSampleCount;
      uStepCounter++;
      if (uStepCounter == uStepSize) {
         uStepCounter = 0;
         pCTTSCacheTable[uCacheIndex].accumulated_sample_count = uCurSampleCount;
         pCTTSCacheTable[uCacheIndex++].accumulated_composition_time = uCurCompositionTime;
         if( uCacheIndex == uCTTSCacheTableCount )
            break;
      }
   }
   pCurTrack->uCTTSStepCounter             = uStepCounter;
   pCurTrack->uCTTSCurSampleCount          = uCurSampleCount;
   pCurTrack->uCTTSCurCompositionTime      = uCurCompositionTime;
   pCurTrack->uCTTSCacheIndex              = uCacheIndex;
   pCurTrack->uCTTSIndex                   = uIndex;

   return MP4_PARSER_OK;
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
#endif
#endif

static MP4_Parser_Status MP4_STTS_FillCacheTableByTrack(STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, STMp4Track *prTrack, kal_uint32 u4IdxCnt, kal_uint32 uCount )
{
    kal_uint64 uCurDecodeTime = prTrack->uSTTSCurDecodeTime;
    kal_uint32 uIndex = prTrack->uSTTSIndex;
    kal_uint32 uThisSampleCount;
    kal_uint32 uThisSampleDelta;
    kal_uint32 uCurSampleCount = prTrack->uSTTSCurSampleCount;
    kal_uint32 uSTTSEntryCount = prTrack->uSTTSCacheTableEntryCount;
    kal_uint32 uLocalCounter;
    MP4_Parser_Status ret;
    STTS_Cache_Entry *pSTTSCacheTable = prTrack->pSTTSCacheTable;
    kal_uint16 uStepCounter = prTrack->uSTTSStepCounter;
    kal_uint16 uStepSize = prTrack->uSTTSCacheTableStepSize;
    kal_uint16 uCacheIndex = prTrack->uSTTSCacheIndex;

    for (uLocalCounter=0; uIndex<u4IdxCnt && uLocalCounter<uCount; uIndex++, uLocalCounter++) {
        if ((ret=MP4_GetSampleCountAndDelta(pstMp4Parser, uIndex, &uThisSampleCount, &uThisSampleDelta, eTrackType))!=MP4_PARSER_OK)
            return ret;
        uCurSampleCount += uThisSampleCount;
        uCurDecodeTime += (kal_uint64)uThisSampleDelta * (kal_uint64)uThisSampleCount;
        uStepCounter++;
        if (uStepCounter == uStepSize) {
            uStepCounter = 0;
            pSTTSCacheTable[uCacheIndex].accumulated_sample_count = uCurSampleCount;
            pSTTSCacheTable[uCacheIndex++].accumulated_decode_time = uCurDecodeTime;
            if( uCacheIndex == uSTTSEntryCount)
                break;
        }
    }
    prTrack->uSTTSStepCounter          = uStepCounter;
    prTrack->uSTTSCurSampleCount       = uCurSampleCount;
    prTrack->uSTTSCurDecodeTime        = uCurDecodeTime;
    prTrack->uSTTSCacheIndex           = uCacheIndex;
    prTrack->uSTTSIndex                = uIndex;

    return MP4_PARSER_OK;
}

/*******************************************************************************
   Initialize the STTS cache of the specified track.
*******************************************************************************/
static MP4_Parser_Status MP4_STTS_InitCacheTableByTrack( STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType,
                                                         void *pSTTSCacheTable, kal_uint32 uSTTSCacheTableCount,
                                                         kal_uint32 *puSTTSCacheTblCntExist)
{
   kal_uint32 uSTTSEntryCount = 0;
   kal_uint16 uStepSize = 0;
   kal_uint8  bTrackNo;
   MP4_Parser_Status ret;
   STMp4Track *prTrack;

   *puSTTSCacheTblCntExist = 0;
   pSTTSCacheTable = (STTS_Cache_Entry *)pSTTSCacheTable;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   prTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);
   uSTTSEntryCount = prTrack->uTimeToSampleTableEntryCount;

   if ((0==uSTTSCacheTableCount) || (0==uSTTSEntryCount))
      return MP4_PARSER_OK;

   uStepSize = (uSTTSEntryCount+uSTTSCacheTableCount-1) / uSTTSCacheTableCount;
   /* avoid divide-by-zero */
   if (0 == uStepSize)
      uStepSize = 1;
   uSTTSCacheTableCount = uSTTSEntryCount / uStepSize;

   /// In the initialization, process at most 2048 STTS entries to prevent the response time
   /// from being too long.
   if (uSTTSEntryCount > 4096)
      uSTTSEntryCount = 4096;

   prTrack->pSTTSCacheTable           = pSTTSCacheTable;
   prTrack->uSTTSCacheTableStepSize   = uStepSize;
   prTrack->uSTTSCacheTableEntryCount = uSTTSCacheTableCount;
   prTrack->uSTTSStepCounter = 0;
   prTrack->uSTTSCurSampleCount = 0;
   prTrack->uSTTSCurDecodeTime = 0;
   prTrack->uSTTSIndex = 0;
   prTrack->uSTTSCacheIndex = 0;

   if ((ret = MP4_STTS_FillCacheTableByTrack(pstMp4Parser, eTrackType, prTrack, uSTTSEntryCount, 0xffffffff)) != MP4_PARSER_OK)
        return ret;

   *puSTTSCacheTblCntExist = uSTTSCacheTableCount;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Process certain number of STTS cache of the specified track.
   uCount is the number of STTS entries to be processed.
*******************************************************************************/
static MP4_Parser_Status MP4_STTS_ProcCacheTableByTrack( STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, kal_uint16 uCount )
{
   kal_uint32 uSTTSCacheTableCount;
   kal_uint16 uCacheIndex;
   kal_uint8  bTrackNo;
   MP4_Parser_Status ret;
   STMp4Track *pCurTrack;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;
   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   uCacheIndex          = pCurTrack->uSTTSCacheIndex;
   uSTTSCacheTableCount = pCurTrack->uSTTSCacheTableEntryCount;

   if (uSTTSCacheTableCount==0 || uCacheIndex==uSTTSCacheTableCount)
      return MP4_PARSER_OK;

   if ((ret = MP4_STTS_FillCacheTableByTrack(pstMp4Parser, eTrackType, pCurTrack, pCurTrack->uTimeToSampleTableEntryCount, uCount)) != MP4_PARSER_OK)
         return ret;

   return MP4_PARSER_OK;
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
#endif

/*******************************************************************************
   Process the STSC cache of the specified track.
   STSC cache table will be processed all at once.
*******************************************************************************/
static MP4_Parser_Status MP4_STSC_ProcCacheTableByTrack( STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, void *pCacheTable, kal_uint32 uSTSCCacheTableCount, kal_uint32 *puSTSCCacheTblCntExist)
{
   kal_uint32 uIndex;
   kal_uint32 uSTSCEntryCount;
   kal_uint32 uSamplePerChunk;
   kal_uint32 uCurSampleCount = 0;
   kal_uint32 uFirstChunk, uLastChunk;
   kal_uint16 uCacheIndex = 0;
   kal_uint16 uStepSize = 0;
   kal_uint16 uStepCounter = 0;
   kal_uint8  bTrackNo;
   MP4_Parser_Status ret;
   STMp4Track *prTrack;
   STSC_Cache_Entry* pSTSCCacheTable;

   *puSTSCCacheTblCntExist = 0;
   pSTSCCacheTable = (STSC_Cache_Entry *)pCacheTable;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   prTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);
   uSTSCEntryCount = prTrack->uSampleToChunkEntryCount;

   if ((0 == uSTSCCacheTableCount) || (0 == uSTSCEntryCount))
      return MP4_PARSER_OK;

   uStepSize = (uSTSCEntryCount+uSTSCCacheTableCount-1) / uSTSCCacheTableCount;
   /* avoid divide by zero */
   if (0 == uStepSize)
     uStepSize = 1;
   uSTSCCacheTableCount = uSTSCEntryCount / uStepSize;

   uSTSCEntryCount--;
   for (uIndex=0; uIndex<uSTSCEntryCount; uIndex++) {
      if ((ret=MP4_GetSamplePerChunkInRun(pstMp4Parser, uIndex, &uSamplePerChunk, eTrackType))!=MP4_PARSER_OK)
         return ret;
      if ((ret = MP4_GetFirstChunkInRun(pstMp4Parser, uIndex+1, &uLastChunk, eTrackType))!=MP4_PARSER_OK)
         return ret;
      if ((ret = MP4_GetFirstChunkInRun(pstMp4Parser, uIndex, &uFirstChunk, eTrackType))!=MP4_PARSER_OK)
         return ret;
      uCurSampleCount += (uLastChunk - uFirstChunk)*uSamplePerChunk;
      uStepCounter++;
      if (uStepCounter == uStepSize) {
         uStepCounter = 0;
         pSTSCCacheTable[uCacheIndex++].accumulated_sample_count = uCurSampleCount;
      }
   }

   // handle the last one
   if ((ret=MP4_GetSamplePerChunkInRun(pstMp4Parser, uIndex, &uSamplePerChunk, eTrackType))!=MP4_PARSER_OK)
      return ret;
   if ((ret = MP4_GetChunkCount(pstMp4Parser, eTrackType, &uLastChunk))!=MP4_PARSER_OK)
      return ret;
   if ((ret = MP4_GetFirstChunkInRun(pstMp4Parser, uIndex, &uFirstChunk, eTrackType))!=MP4_PARSER_OK)
      return ret;
   uCurSampleCount += (uLastChunk - uFirstChunk)*uSamplePerChunk;
   uStepCounter++;
   if (uStepCounter == uStepSize) {
      uStepCounter = 0;
      pSTSCCacheTable[uCacheIndex++].accumulated_sample_count = uCurSampleCount;
   }

   prTrack->pSTSCCacheTable           = pSTSCCacheTable;
   prTrack->uSTSCCacheTableStepSize   = uStepSize;
   prTrack->uSTSCCacheTableEntryCount = uSTSCCacheTableCount;

   *puSTSCCacheTblCntExist = uSTSCCacheTableCount;

   if (prTrack->uSampleCount > uCurSampleCount)
      prTrack->uSampleCount = uCurSampleCount;
   prTrack->bSampleCountUpdated = KAL_TRUE;

   return MP4_PARSER_OK;
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
#endif

#ifndef __LOW_COST_SUPPORT_COMMON__
/*******************************************************************************
   Initialize the STSS cache of the specified track.
*******************************************************************************/
static MP4_Parser_Status MP4_STSS_InitCacheTableByTrack( STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType,
                                                         void *pCacheTable, kal_uint32 uSTSSCacheTableCount,
                                                         kal_uint32 *puSTSSCacheTblCntExist)
{
   kal_uint32 uSTSSEntryCount;
   kal_uint32 uIndex;
   kal_uint16 uCacheIndex;
   kal_uint16 uStepSize;
   kal_uint8  bTrackNo;
   MP4_Parser_Status ret;
   STMp4Track *prTrack;
   STSS_Cache_Entry* pSTSSCacheTable;

   *puSTSSCacheTblCntExist = 0;
   pSTSSCacheTable = (STSS_Cache_Entry *)pCacheTable;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   prTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);
   uSTSSEntryCount = prTrack->uSyncCount;

   if ((0==uSTSSCacheTableCount) || (0==uSTSSEntryCount))
      return MP4_PARSER_OK;

   uStepSize = (uSTSSEntryCount+uSTSSCacheTableCount-1) / uSTSSCacheTableCount;
   /* avoid divide by zero */
   if (0 == uStepSize)
      uStepSize = 1;
   uSTSSCacheTableCount = uSTSSEntryCount / uStepSize;

   /// In the initialization, process at most 16 STSS "CACHE" entries to prevent the response time
   /// from being too long.
   uSTSSEntryCount = uSTSSCacheTableCount;   /// Use uSTSSEntryCount as temporary variable
   if (uSTSSEntryCount > 32)
      uSTSSEntryCount = 32;
   for (uCacheIndex=0, uIndex=0; uCacheIndex<uSTSSEntryCount; uCacheIndex++, uIndex+=uStepSize) {
      if ((ret=MP4_GetSyncSampleNo(pstMp4Parser, uIndex, &(pSTSSCacheTable[uCacheIndex].sample_number), eTrackType))!=MP4_PARSER_OK)
         return ret;
   }
   prTrack->pSTSSCacheTable             = pSTSSCacheTable;
   prTrack->uSTSSCacheIndex             = uCacheIndex;
   prTrack->uSTSSIndex                  = uIndex;
   prTrack->uSTSSCacheTableStepSize     = uStepSize;
   prTrack->uSTSSCacheTableEntryCount   = uSTSSCacheTableCount;

   *puSTSSCacheTblCntExist = uSTSSCacheTableCount;

   return MP4_PARSER_OK;
}

/*******************************************************************************
   Process certain number of STSS cache of the specified track.
   uCount is the number of STSS "CACHE" entries to be processed.
*******************************************************************************/
static MP4_Parser_Status MP4_STSS_ProcCacheTableByTrack( STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, kal_uint32 uCount )
{
   kal_uint32 uIndex, local_counter;
   kal_uint32 uSTSSCacheTableCount;
   kal_uint16 uStepSize;
   kal_uint16 uCacheIndex;
   kal_uint8  bTrackNo;
   MP4_Parser_Status ret;
   STSS_Cache_Entry *pSTSSCacheTable;
   STMp4Track *prTrack;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   prTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   uCacheIndex          = prTrack->uSTSSCacheIndex;
   uSTSSCacheTableCount = prTrack->uSTSSCacheTableEntryCount;

   if (uSTSSCacheTableCount==0 || uCacheIndex==uSTSSCacheTableCount)
      return MP4_PARSER_OK;

   uIndex               = prTrack->uSTSSIndex;
   pSTSSCacheTable      = prTrack->pSTSSCacheTable;
   uStepSize            = prTrack->uSTSSCacheTableStepSize;

   for (local_counter=0; uCacheIndex<uSTSSCacheTableCount && local_counter<uCount; uCacheIndex++, uIndex+=uStepSize, local_counter++) {
      if ((ret=MP4_GetSyncSampleNo(pstMp4Parser, uIndex, &(pSTSSCacheTable[uCacheIndex].sample_number), eTrackType))!=MP4_PARSER_OK)
         return ret;
   }
   prTrack->uSTSSCacheIndex = uCacheIndex;
   prTrack->uSTSSIndex      = uIndex;

   return MP4_PARSER_OK;
}
#endif

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
#endif

MP4_Parser_Status (*pfnMP4InitCacheTableByTrack)( STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType,
                                                         void *pCacheTable, kal_uint32 uCacheTableCount,kal_uint32 *puCacheTblCntExist);

static MP4_Parser_Status MP4_STBL_InitCacheTable(STMp4Parser *pstMp4Parser, kal_uint32 *pSTBLCachePool,
                                    kal_uint32 uSTBLCachePoolSize, kal_uint32 *puSTBLCachePoolUsed, MP4_Parser_STBL_IDX_T eStbl)
{
   MP4_Parser_Status ret;
   kal_uint8 bTrackNo;
   STMp4Track *pAudioTrack, *pVideoTrack;
   kal_uint32 u4VideoCnt, u4AudioCnt;
   kal_uint16 entry_size;// = sizeof(STTS_Cache_Entry)/sizeof(kal_uint32);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, MP4_TRACK_AUDIO, &bTrackNo))!=MP4_PARSER_OK)
      pAudioTrack = NULL;
   else
      pAudioTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, MP4_TRACK_VIDEO, &bTrackNo))!=MP4_PARSER_OK)
      pVideoTrack = NULL;
   else
      pVideoTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   //if no track, entry count force to zero.
   if (eStbl == MP4_PARSER_STSC)
   {
        u4VideoCnt = (pVideoTrack) ? pVideoTrack->uSampleToChunkEntryCount : 0;
        u4AudioCnt = (pAudioTrack) ? pAudioTrack->uSampleToChunkEntryCount : 0;
        entry_size = sizeof(STSC_Cache_Entry)/sizeof(kal_uint32);
        pfnMP4InitCacheTableByTrack = MP4_STSC_ProcCacheTableByTrack;
   }
#ifndef __LOW_COST_SUPPORT_COMMON__
   else if (eStbl == MP4_PARSER_STSS)
   {
        u4VideoCnt = (pVideoTrack) ? pVideoTrack->uSyncCount : 0;
        u4AudioCnt = (pAudioTrack) ? pAudioTrack->uSyncCount : 0;
        entry_size = sizeof(STSS_Cache_Entry)/sizeof(kal_uint32);
        pfnMP4InitCacheTableByTrack = MP4_STSS_InitCacheTableByTrack;
   }
#endif
#ifdef __VE_MP4_PARSER_SUPPORT_CTTS__
   else if (eStbl == MP4_PARSER_CTTS)
   {
        u4VideoCnt = (pVideoTrack) ? pVideoTrack->uCTimeToSampleTableEntryCount : 0;
        u4AudioCnt = (pAudioTrack) ? pAudioTrack->uCTimeToSampleTableEntryCount : 0;
        entry_size = sizeof(CTTS_Cache_Entry)/sizeof(kal_uint32);
        pfnMP4InitCacheTableByTrack = MP4_CTTS_InitCacheTableByTrack;
   }
#endif
   else if (eStbl == MP4_PARSER_STTS)
   {
        u4VideoCnt = (pVideoTrack) ? pVideoTrack->uTimeToSampleTableEntryCount : 0;
        u4AudioCnt = (pAudioTrack) ? pAudioTrack->uTimeToSampleTableEntryCount : 0;
        entry_size = sizeof(STTS_Cache_Entry)/sizeof(kal_uint32);
        pfnMP4InitCacheTableByTrack = MP4_STTS_InitCacheTableByTrack;
   }
   else
   {
        *puSTBLCachePoolUsed = 0;
        return MP4_PARSER_OK;
   }

   *puSTBLCachePoolUsed = 0;

   if (pAudioTrack!=NULL && pVideoTrack!=NULL) {
      kal_uint32 audio_cache_size, video_cache_size;
      /// avoid divide by zero
      if ((0==u4AudioCnt) && (0==u4VideoCnt))
         return MP4_PARSER_OK;

      audio_cache_size = (kal_uint32)(((kal_uint64) u4AudioCnt * uSTBLCachePoolSize) / (u4AudioCnt + u4VideoCnt));
      video_cache_size = uSTBLCachePoolSize - audio_cache_size;

      if ((ret = pfnMP4InitCacheTableByTrack( pstMp4Parser, MP4_TRACK_VIDEO, (void *)pSTBLCachePool, video_cache_size/entry_size, &video_cache_size)) != MP4_PARSER_OK)
         return ret;
      if ((ret = pfnMP4InitCacheTableByTrack( pstMp4Parser, MP4_TRACK_AUDIO, (void *)(pSTBLCachePool+(video_cache_size*entry_size)), audio_cache_size/entry_size, &audio_cache_size)) != MP4_PARSER_OK)
         return ret;
      *puSTBLCachePoolUsed = audio_cache_size + video_cache_size;
   }
   else if (pAudioTrack!=NULL) {
      if ((ret = pfnMP4InitCacheTableByTrack( pstMp4Parser, MP4_TRACK_AUDIO, (void *)pSTBLCachePool, uSTBLCachePoolSize/entry_size, puSTBLCachePoolUsed)) != MP4_PARSER_OK)
         return ret;
   }
   else if (pVideoTrack!=NULL) {
      if( (ret = pfnMP4InitCacheTableByTrack( pstMp4Parser, MP4_TRACK_VIDEO, (void *)pSTBLCachePool, uSTBLCachePoolSize/entry_size, puSTBLCachePoolUsed)) != MP4_PARSER_OK )
         return ret;
   }
   *puSTBLCachePoolUsed *= entry_size;
   return MP4_PARSER_OK;
}


/*******************************************************************************
   Initialize the STBL cache.
*******************************************************************************/
MP4_Parser_Status MP4_STBL_CacheTablePreprocess(STMp4Parser *pstMp4Parser, kal_uint32 *pCachePool, kal_uint32 uCachePoolSize)
{
   MP4_Parser_Status eMp4ParserRet = MP4_PARSER_OK;
   kal_uint32 uCachePoolUsed = 0, u4Size;
   //kal_uint8 bCacheEnableFlag = 15;
   MP4_Parser_STBL_IDX_T eIdx;

   MP4_PARSER_CHECK_ARG(pCachePool!=NULL | uCachePoolSize!=0);

    for (eIdx = MP4_PARSER_STSS; eIdx <= MP4_PARSER_CTTS; eIdx++)
    {
      pCachePool += uCachePoolUsed;
      uCachePoolSize -= uCachePoolUsed;
      if (eIdx == MP4_PARSER_STSS)
        u4Size = uCachePoolSize>>4;
      else if (eIdx == MP4_PARSER_STSC)
        u4Size = uCachePoolSize*3/15;
      else if (eIdx == MP4_PARSER_STTS)
        u4Size = uCachePoolSize/3;
      else //CTTS
        u4Size = uCachePoolSize;

      eMp4ParserRet = MP4_STBL_InitCacheTable(pstMp4Parser, pCachePool, u4Size, &uCachePoolUsed, eIdx);
      if(eMp4ParserRet!=MP4_PARSER_OK )
   return eMp4ParserRet;
}

   return eMp4ParserRet;
}
MP4_Parser_Status MP4_GetMovieTimeScaleDuration(STMp4Parser *pstMp4Parser, kal_uint32 *puTimeScale, kal_uint32 *puDuration)
{
   MP4_Parser_Status ret;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL | puTimeScale!=NULL | puDuration!=NULL);

   if(pstMp4Parser->bHasMVHD)
   {
      *puTimeScale = pstMp4Parser->timescale;
      *puDuration = pstMp4Parser->duration;
      ret = MP4_PARSER_OK;
   }
   else
      ret = MP4_PARSER_NO_MVHD;

   return ret;
}

MP4_Parser_Status MP4_GetVideoResolution(STMp4Parser *pstMp4Parser, kal_uint32 *width, kal_uint32 *height)
{
   MP4_Parser_Status ret;
   kal_uint8 bTrackNo;
   STMp4Track *pCurTrack;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, MP4_TRACK_VIDEO, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   *width = pCurTrack->width;
   *height = pCurTrack->height;

   return MP4_PARSER_OK;
}

#ifdef __VE_MM_DCM_SUPPORT__
#pragma arm section code, rodata
#endif

MP4_Parser_Status MP4_GetSampleSizeAccumulate(STMp4Parser *pstMp4Parser, kal_uint32 uSampleNo, kal_uint32 uAccumSampleNum,
                                    kal_uint32 *puAccumSampleSize, MP4_Track_Type eTrackType)
{
   MP4_Parser_Status ret;
   kal_uint8 bTrackNo;
   STFSAL *pstFSAL_STSZ;
   STMp4Track *prTrack;

   MP4_PARSER_CHECK_ARG(puAccumSampleSize!=NULL);

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   prTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);
   MP4_PARSER_ASSERT(uSampleNo<prTrack->uSampleCount);
   MP4_PARSER_ASSERT((uSampleNo+ uAccumSampleNum)<= prTrack->uSampleCount);

   *puAccumSampleSize = prTrack->uConstantSampleSize;
   pstFSAL_STSZ = prTrack->pstFSAL_STSZ;

   if (*puAccumSampleSize != 0) {
   	  *puAccumSampleSize = (*puAccumSampleSize) * uAccumSampleNum;
      return MP4_PARSER_OK;
   } else {
      kal_uint32 uOffset;
      kal_uint32 uSampleSize;
      kal_uint32 AccumSampleSize = 0;
      kal_uint32 i;

      uOffset = prTrack->uOffsetSampleSizeTable;
      uOffset += (uSampleNo * 4);
      if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstFSAL_STSZ, uOffset))!=FSAL_OK)
         return MP4_PARSER_FILE_SEEK_ERROR;

      for(i=0; i<uAccumSampleNum ; i++)
      {
         if ((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstFSAL_STSZ, &uSampleSize))!=FSAL_OK)
            return MP4_PARSER_FILE_READ_ERROR;
         AccumSampleSize += uSampleSize;
      }
      *puAccumSampleSize = AccumSampleSize;
      return MP4_PARSER_OK;
   }
}

MP4_Parser_Status MP4_GetAverageBitRate(STMp4Parser *pstMp4Parser, kal_uint32 *puAverageBitRate, MP4_Track_Type eTrackType)
{
   MP4_Parser_Status ret;
   kal_uint32 uTimeScale;
   kal_uint32 uSampleCount;
   kal_uint32 uAccumSampleNum;
   kal_uint32 uAccumSampleSize;
   kal_uint64 uDecodeTime;

   MP4_PARSER_CHECK_ARG(puAverageBitRate!=NULL);
   *puAverageBitRate = 0;

   if ((ret=MP4_GetSampleCount(pstMp4Parser, eTrackType, &uSampleCount))!=MP4_PARSER_OK)
      return ret;

   if(uSampleCount > 500)
      uAccumSampleNum = 500;
   else
      uAccumSampleNum = uSampleCount;

   if ((ret=MP4_GetMediaTimeScale(pstMp4Parser, &uTimeScale, eTrackType))!=MP4_PARSER_OK)
      return ret;

   if ((ret=MP4_GetSampleSizeAccumulate(pstMp4Parser, (kal_uint32)0, uAccumSampleNum, &uAccumSampleSize, eTrackType))!=MP4_PARSER_OK)
      return ret;

   if (eTrackType == MP4_TRACK_VIDEO)
   {
      if ((ret=MP4_GetDecodeTime(pstMp4Parser, uAccumSampleNum, &uDecodeTime, eTrackType))!=MP4_PARSER_OK)
         return ret;
   }
   else if(eTrackType == MP4_TRACK_AUDIO)
   {
      // this specially design is used fro audio only for reducing to allocate catch buffer.
      if((pstMp4Parser->bAudioType[pstMp4Parser->bAudioTrack] == MP4_AUDIO_AAC) ||
         (pstMp4Parser->bAudioType[pstMp4Parser->bAudioTrack] == MP4_AUDIO_BSAC))
      {
         kal_uint32 SamplingFreq = MP4_Audio_GetSamplingFreq(pstMp4Parser);
         if(SamplingFreq == 0) SamplingFreq = 8000;
         uDecodeTime = ((kal_uint64)1024  * uAccumSampleNum * uTimeScale) / SamplingFreq;
      }
      else if((pstMp4Parser->bAudioType[pstMp4Parser->bAudioTrack] == MP4_AUDIO_AMR) ||
              (pstMp4Parser->bAudioType[pstMp4Parser->bAudioTrack] == MP4_AUDIO_AMR_WB))
         uDecodeTime = (kal_uint64)(20 * uAccumSampleNum * uTimeScale) / 1000;        // 20 ms perframe
      else
         return MP4_PARSER_PARSE_ERROR;
   }
   if(uDecodeTime == 0) uDecodeTime = 1;

   *puAverageBitRate = (kal_uint32)((kal_uint64)uAccumSampleSize * 8 * uTimeScale / uDecodeTime );
   return MP4_PARSER_OK;
}

MP4_Parser_Status MP4_GetPrevDecodeTime(STMp4Parser *pstMp4Parser, kal_uint64 *puDecodeTime, MP4_Track_Type eTrackType)
{
   kal_uint8 bTrackNo;
   MP4_Parser_Status ret;
   STMp4Track *pCurTrack;

   MP4_PARSER_CHECK_ARG(puDecodeTime!=NULL);

   *puDecodeTime = 0;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, eTrackType, &bTrackNo))!=MP4_PARSER_OK)
      return ret;
   pCurTrack = &(pstMp4Parser->stMp4Track[bTrackNo]);

   *puDecodeTime = pCurTrack->uDecodeTime_PrevDecodeTime;

   return MP4_PARSER_OK;
}

MP4_Parser_Status MP4_GetSyncSampleCount(STMp4Parser *pstMp4Parser,
                                         kal_uint32 *puSyncSampleCount,
                                         MP4_Track_Type type)
{
   MP4_Parser_Status ret;
   kal_uint8 bTrackNo;

   if ((ret=MP4_GetTrackNoByType(pstMp4Parser, type, &bTrackNo))!=MP4_PARSER_OK)
      return ret;

   *puSyncSampleCount = pstMp4Parser->stMp4Track[bTrackNo].uSyncCount;
   return MP4_PARSER_OK;
}

/*******************************************************************************
   Get the offset of MOOV box.
*******************************************************************************/
kal_uint32 MP4_GetMovieHeaderOffset(STMp4Parser *pstMp4Parser)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   return pstMp4Parser->uMOOVOffset;
}

#endif //(__M3GPMP4_FILE_FORMAT_SUPPORT__)
