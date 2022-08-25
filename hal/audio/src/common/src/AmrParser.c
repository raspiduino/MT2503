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
 *   AmrParser.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   AMR parser component
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
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(AMR_CODEC)

#include "audio_enum.h"
#include "kal_trace.h"
#include "l1sp_trc.h"
#include "AudComUtil.h"
#include "AMR_codec.h"
#include "media.h"

#define AMR_PARSE_FRAME_THRESHOLD 100

static const kal_uint16 lenSpeechBitsAMR[9]={ 95, 103, 118, 134, 148, 159, 204, 244, 39 };

#if defined(AMRWB_DECODE)
static const kal_uint16 lenSpeechBitsAMR_WB[10]={132, 177, 253, 285, 317, 365, 397, 461, 477, 40 };
#endif

/*------------------------------------------------*/
/* The private functions of AMR parser.           */
/*------------------------------------------------*/

Media_Format amrChkFileHeader( STFSAL *pstFSAL, kal_uint32 *uOffset)
{
   kal_uint8 AMR_Header[9];
   kal_uint32 fileOffset = 0;
   kal_uint32 uReadLen = 9;
   OMX_ERRORTYPE eResult;

   *uOffset = 0;
   eResult = ACU_GetBytesFromFile(pstFSAL, &fileOffset, &uReadLen, AMR_Header);
   if ( OMX_ErrorNone != eResult || uReadLen != 9 )
   {
      return MEDIA_FORMAT_UNKNOWN;
   }
#if defined(AMRWB_DECODE)
   if(memcmp(AMR_Header, "#!AMR-WB\n", 9)==0)
   {
      *uOffset = 9;
      return MEDIA_FORMAT_AMR_WB;
   }
   else
#endif
   if(memcmp(AMR_Header, "#!AMR\n", 6) == 0)
   {
      *uOffset = 6;
      return MEDIA_FORMAT_AMR;
   }
   return MEDIA_FORMAT_UNKNOWN;
}

kal_uint32 amrGetByteRate( STFSAL *pstFSAL , Media_Format uMediaType, kal_uint32 uOffset)
{
   kal_uint32 i, accumByte;
   kal_uint8 AMR_Header;
   kal_int32 frameLen;
   kal_uint8 FT;
   kal_uint32 uFileOffset = uOffset;
   kal_uint32 uReadByte = 1;
   
   accumByte = 0;
   i = 0;

#if defined(AMRWB_DECODE)
   if (MEDIA_FORMAT_AMR_WB == uMediaType ) 
   {
      for (i=0; i<AMR_PARSE_FRAME_THRESHOLD; i++) 
      {
         ACU_GetBytesFromFile(pstFSAL, &uFileOffset, &uReadByte, &AMR_Header);
         if (uReadByte != 1)
         {
            break;
         }
         else
         {
            FT = (AMR_Header >> 3) & 0x0F;
            if (FT <= 9) 
            {
               frameLen = ((lenSpeechBitsAMR_WB[FT]+7)>>3) + 1;
            } 
            else if (FT == 15) 
            {
               frameLen = 1;
            }
            else if (FT == 14) 
            {
               kal_uint8 FQI = (AMR_Header >> 2) & 0x01;
               if (FQI == 0)
               {
                  frameLen = 1;
               }
               else
               {
                  break;
               }
            } 
            else
            {
               break;
            }
            accumByte += frameLen;
            uFileOffset += frameLen;
         }
      }
   } else
#endif
   if (MEDIA_FORMAT_AMR == uMediaType ) 
   {
      for (i=0; i<AMR_PARSE_FRAME_THRESHOLD; i++)
      {
         ACU_GetBytesFromFile(pstFSAL, &uFileOffset, &uReadByte, &AMR_Header);
         if (uReadByte != 1) 
         {
            break;
         }
         else
         {
            FT = (AMR_Header >> 3) & 0x0F;
            if (FT <= 8) 
            {
               frameLen = ((lenSpeechBitsAMR[FT]+7)>>3) + 1;
            } 
            else if (FT == 15)
            {
               frameLen = 1;
            } 
            else 
            {
               break;
            }
            accumByte += frameLen;
            uFileOffset += frameLen;
         }
      }
   }

   if (i)
   {
      return (kal_uint64) accumByte * 50 / i;
   }
   else
   {
      return 0;
   }
}


kal_uint32 amrGetFrameLength( Media_Format uMediaType, kal_uint8 bFrameHeader)
{
   kal_uint8  FT;
   kal_uint32 frameLen = 0;
   FT  = (bFrameHeader >> 3) & 0x0F;

   if( MEDIA_FORMAT_AMR == uMediaType )
   {
       if (FT <= 8) 
       {
          frameLen = ((lenSpeechBitsAMR[FT]+7)>>3) + 1;
       } 
       else
       {
          frameLen = 1;
       }              	              	              	 
   }
#if defined(AMRWB_DECODE)             
   else if(MEDIA_FORMAT_AMR_WB == uMediaType)
   {
   	   if (FT <= 9) 
       {
          frameLen = ((lenSpeechBitsAMR_WB[FT]+7)>>3) + 1;
       } 
       else
       {
         frameLen = 1;
       }       	              	           	 
   }
#endif  
   
   return frameLen;                        
}


AST_Status amrParseFileHeader(void *hdlptr, kal_uint32 *FirstFrameOffset, kal_uint32 *uFrameDur)
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdlptr;
   MHdl *hdl = &ihdl->mh; 

   *uFrameDur = AMR_FRAME_DURATION;
   hdl->mediaType = amrChkFileHeader(ihdl->pstFSAL, FirstFrameOffset);
   if(MEDIA_FORMAT_UNKNOWN == hdl->mediaType)
   {
      return AST_PARSE_FILE_HEADER_FAIL;
   }
   return AST_SUCCESS;
}

AST_Status amrParseFrame(void *hdlptr, kal_uint32 *CurOffset, kal_uint32 *ParseFrameNum)
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdlptr;
   MHdl *hdl = &ihdl->mh; 
   AST_Status ParseResult; 
   kal_uint32 AccOffset=0, Remains=0, uBufLen=0, uOffset = 0, uCurPos=0, ByteCnt = 0;
   kal_uint8 *pbHeader;

   if(hdl->rbInfo.rb_base == NULL)
   {
      uBufLen = SEEK_TABLE_BS_BUFFER_LEN;
      pbHeader = (kal_uint8 *)audio_alloc_mem_cacheable(uBufLen);
      ASSERT(pbHeader);
   }
   else
   {
      hdl->GetWriteBuffer(hdl, &pbHeader, &uBufLen );
   }

   ParseResult=AST_SUCCESS;
   AccOffset = *CurOffset;
   Remains = *ParseFrameNum;

   if(OMX_ErrorNone != ACU_GetBytesFromFile(ihdl->pstFSAL, &AccOffset, &uBufLen, pbHeader))
   {
      ByteCnt = 0;
   }
   else
   {
      ByteCnt = uBufLen;
   }
   FSAL_GetCurPos(ihdl->pstFSAL, &uCurPos);  

   while(Remains!=0)
   {
      kal_uint32 uHeader;
      if(0==ByteCnt)
      {
         ByteCnt = uBufLen;
         if(OMX_ErrorNone != ACU_GetBytesFromFile(ihdl->pstFSAL, &AccOffset, &ByteCnt, pbHeader))
         {
            ByteCnt = 0;
         }
         
         if(0==ByteCnt)
         {
            ParseResult = AST_EOF;
            break;
         }
      }
      uHeader = (kal_uint32)*(pbHeader+uOffset);

#if defined(AMRWB_DECODE)
      if (MEDIA_FORMAT_AMR_WB == hdl->mediaType)
      {
         kal_uint32  FT, FQI;
         FT = (uHeader >> 3) & 0x0F;
         FQI = (uHeader >> 2) & 0x01;
         if (FT<=9) 
         {
            uOffset += (((kal_uint32)lenSpeechBitsAMR_WB[FT]+7)>>3) + 1;
         }
         else if(FT==14)
         {
            if (FQI==0)
            {
               uOffset += 1;
            }
            else
            {
               ParseResult = AST_PARSE_FRAME_FAIL;
               break;
            }
         }
         else if(FT==15)
         { /* NO_DATA */
            uOffset += 1;
         }
         else
         { /* 'for-future-use' mode */
            ParseResult = AST_PARSE_FRAME_FAIL;
            break;
         }
      }//if (MEDIA_FORMAT_AMR_WB == ihdl->mh.mediaType)...
      else
#endif
      {
         kal_uint32  FT;
         
         FT = (uHeader >> 3) & 0x0F;
         if(FT<=8) /* AMR 4.75 ~ 12.2 kbps */ /* AMR SID */
         {
            uOffset += (((kal_uint32)lenSpeechBitsAMR[FT]+7)>>3) + 1;
         }
         else if(FT>=9 && FT<=14) /* GSM/TDMA/PDC SID and 'for-future-use' mode */
         { 
            ParseResult = AST_PARSE_FRAME_FAIL;
            break;
         }
         else if(FT==15)
         { /* No_Data*/
            uOffset += 1;
         }
      }
      Remains--;
      if(uOffset >= ByteCnt)
      {
         AccOffset += uOffset;
         ByteCnt = 0;
         uOffset = 0;
      }
   }
   AccOffset+=uOffset;
   *CurOffset=AccOffset;
   *ParseFrameNum -= Remains;
   FSAL_Seek( ihdl->pstFSAL, uCurPos);
   if(hdl->rbInfo.rb_base == NULL)
   {
      audio_free_mem( (void **) &pbHeader);
   }
   return ParseResult;
}


static void amrParSeekWithResume( AudComHdl *hdl )
{   
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   MHPB_Internal *pPBhdl = (MHPB_Internal *)ihdl->mhdl;
   AMR_ParData *pParData = (AMR_ParData *)ihdl->pPrivateData;
   kal_uint32 uResumeFrame, uPauseFrame, uJumpFrame;

   uResumeFrame = (kal_uint64)pPBhdl->mh.start_time * 1000000 / AMR_FRAME_DURATION;

   ACU_GetResumePoint(&pParData->ResBuf, &pParData->uOffset, &uPauseFrame);

   if(uPauseFrame<uResumeFrame)
   {
      uJumpFrame = uResumeFrame - uPauseFrame;
      amrParseFrame(ihdl->mhdl, &pParData->uOffset, &uJumpFrame);
      uPauseFrame += uJumpFrame;
   }
   ihdl->mhdl->start_time = (kal_uint32)((kal_uint64)uPauseFrame * AMR_FRAME_DURATION / 1000000); // update start time 
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SEEK_RESUME, MTKAUD_PARSER_AMR, uResumeFrame,uPauseFrame,ihdl->mhdl->start_time,pParData->uOffset,0,0);
   
}

static kal_bool amrParSeek( AudComHdl *hdl, kal_bool bEnableAST )
{   
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   MHPB_Internal *pPBhdl = (MHPB_Internal *)ihdl->mhdl;
   AMR_ParData *pParData = (AMR_ParData *)ihdl->pPrivateData;
   kal_uint32 CurFrames, StartFrame;

   StartFrame = ((kal_uint64)pPBhdl->mh.start_time * 1000000 / AMR_FRAME_DURATION);
   if ((kal_uint64)pPBhdl->mh.start_time * 1000000 - (StartFrame *AMR_FRAME_DURATION)){
      StartFrame += 1;
   }
   
   CurFrames=StartFrame;

   if(bEnableAST && pPBhdl->AudioSeekTbl && pPBhdl->AudioSeekTbl->CurrentIndex!=1)
   {
      pParData->uOffset=AST_Seek(ihdl->mhdl, pPBhdl->AudioSeekTbl, &CurFrames);
   }
   else
   {
      amrParseFrame(ihdl->mhdl, &pParData->uOffset, &CurFrames);
   }
   
   pPBhdl->mh.start_time = (kal_uint32)((kal_uint64)CurFrames * AMR_FRAME_DURATION / 1000000); // update start time 

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SEEK, MTKAUD_PARSER_AMR, StartFrame,CurFrames,pPBhdl->mh.start_time,pParData->uOffset,0,0);
   if (CurFrames != StartFrame)
   {
      return KAL_FALSE;
   }
   else
   {
      return KAL_TRUE;
   }
}



/*------------------------------------------------*/
/* The private member functions of AMR parser.    */
/*------------------------------------------------*/
static OMX_ERRORTYPE AmrPar_Start(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   AMR_ParData *pParData = (AMR_ParData *)ihdl->pPrivateData;
   Media_Format uAmrHeaderFormat;
   MHdl *medhdl = (MHdl *)ihdl->mhdl;
   MHPB_Internal *pPBhdl = (MHPB_Internal *)ihdl->mhdl;
   
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_START, MTKAUD_PARSER_AMR, ihdl->mediaStatus,0,0,0,0);
   ASSERT(ihdl->mediaStatus != COMPONENT_STATE_PLAY); 
   {
      //reset data
      ihdl->isEOF = KAL_FALSE;
      ihdl->Decode_EOF = KAL_FALSE;
      ihdl->endStatus = MEDIA_NONE;
      pParData->uOffset = 0;
      pParData->uFileSize = 0;
      uAmrHeaderFormat = MEDIA_FORMAT_UNKNOWN;
   }

   if(NULL == pParData->pstFSAL)
   {
      if(!medhdl->bIsPause)
	    {
         FSAL_Status eFSALStatus;
         if(medhdl->rbInfo.write==0)
         {
            return OMX_ErrorUndefined;
         }
         pParData->pstFSAL = (STFSAL*)get_ctrl_buffer( sizeof(STFSAL) );
         if(pParData->pstFSAL == NULL)
         {
            return OMX_ErrorUndefined;
         }
         FSAL_Direct_SetRamFileSize(pParData->pstFSAL, medhdl->rbInfo.write);
         eFSALStatus = FSAL_Open(pParData->pstFSAL, medhdl->rbInfo.rb_base, FSAL_ROMFILE);
         ASSERT(eFSALStatus == FSAL_OK);
         uAmrHeaderFormat = amrChkFileHeader( pParData->pstFSAL, &pParData->uOffset );
         medhdl->rbInfo.read = pParData->uOffset;
         free_ctrl_buffer(pParData->pstFSAL);
         pParData->pstFSAL = NULL;
	    }
   }
   else
   {
      uAmrHeaderFormat = amrChkFileHeader( pParData->pstFSAL, &pParData->uOffset );
      if(MEDIA_FORMAT_UNKNOWN == uAmrHeaderFormat)
      {
         return OMX_ErrorUndefined;
      }
   }

   if(MEDIA_FORMAT_UNKNOWN == uAmrHeaderFormat)
   {
      ihdl->mediaType = medhdl->mediaType;
   }
   else
   {
      ihdl->mediaType = uAmrHeaderFormat;
      medhdl->mediaType = uAmrHeaderFormat;
   }
   
   if(pParData->pstFSAL)
   {
      if(medhdl->bIsPause && pPBhdl->AudioSeekTbl==NULL && medhdl->start_time!=0)
      {
         amrParSeekWithResume(hdl);
         medhdl->bIsPause = KAL_FALSE;
      }
      else
      {
         if(!amrParSeek(hdl, KAL_TRUE))
         {
            return OMX_ErrorContentEndOfFile;
         }
      }
      FSAL_GetFileSize(pParData->pstFSAL, &pParData->uFileSize);
      if(pParData->uOffset>=pParData->uFileSize)
      {
         return OMX_ErrorContentEndOfFile;
      }

      //for resume
      ihdl->bsInfo.uFrameDur = AMR_FRAME_DURATION; 
      if(ihdl->bsInfo.uFrameDur)
      {
         ihdl->bsInfo.uCurrentFrame = (kal_uint32)((kal_uint64)pPBhdl->mh.start_time * 1000000 / ihdl->bsInfo.uFrameDur);
      }
      ihdl->bsInfo.uCurrentOffset = pParData->uOffset; 
      ihdl->bsInfo.pResBuf = &pParData->ResBuf; 

      kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_START_TIME_OFFSET, MTKAUD_PARSER_AMR, medhdl->start_time, pParData->uOffset,0,0,0,0);
   }
 
   // To execute process function in advance to avoid buffer underflow in the next stage
   ihdl->mediaStatus = COMPONENT_STATE_PLAY; 

   if(pParData->pstFSAL)
   {
      kal_uint32 I;
      for (I=0; I<AMRDEC_PARSER_BUFNUM; I++) 
      {
         AmrPar_Process_Internal(hdl);
      }
   }
   else
   {
      ACU_SendProcessCommandl( (AudComHdlInt *)hdl );
   }
   return OMX_ErrorNone; 
}

OMX_ERRORTYPE AmrPar_Process_Internal(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   AMR_ParData *pParData = (AMR_ParData *)ihdl->pPrivateData;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PROCESS_I, MTKAUD_PARSER_AMR, ihdl->mediaStatus, ihdl->Decode_EOF,0,0,0,0);
   if(ihdl->mediaStatus != COMPONENT_STATE_PLAY || ihdl->Decode_EOF)
      return OMX_ErrorNone;

   {
      OMX_BUFFERHEADERTYPE *pBufHdr;
      pBufHdr = ACU_GetBufferHeader(hdl, 1);
      if(pBufHdr)
      {
         pBufHdr->pOutputPortPrivate = &ihdl->bsInfo;
      }
   }

   if(pParData->pstFSAL)
   {
      OMX_ERRORTYPE result;
      
      result = ACU_FileRead(hdl, pParData->pstFSAL, &pParData->uOffset);
      kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PAR_OK, MTKAUD_PARSER_AMR, pParData->uOffset,0,0,0,0,0);
      if(ihdl->isEOF)
      {
         ihdl->Decode_EOF = KAL_TRUE;
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_EOF, MTKAUD_PARSER_AMR, 0,0,0,0,0);
      }
      return result;
   }
   else
   {
      MHdl *medhdl = (MHdl *)ihdl->mhdl;  
      kal_uint8 *pBuf;
      kal_uint32 bsLen = 0, bsLen_total = 0, i = 0, dataCount=0;
      for(i=0;i<2;i++)
      {
         medhdl->GetReadBuffer(medhdl, &pBuf, &bsLen);
         bsLen_total = medhdl->GetDataCount(medhdl);
         if(medhdl->pStrmStruct == NULL)
         {
         	  OMX_U8 *uBuf;
         	  OMX_U32 bufDataSize;
         	  // Count the free space of output buffer
            ACU_GetWriteBuffer(hdl, &uBuf, &bufDataSize);
            // Compare the data count
            if (bsLen >= bufDataSize)
               dataCount = bufDataSize;
            else
               dataCount = bsLen;
         }
         if((medhdl->eof||bsLen) && pBuf)   
         {
            if(medhdl->pStrmStruct == NULL)
            {
            	 kal_uint8  bFrameHeader = 0;
            	 kal_int32  bsparse = dataCount;
            	 kal_uint32 uframeLen = 0, accbslen = 0;
            	 if(dataCount ==0 )
            	 {
            	 	 if(!bsLen)
            	 	 {
            	 	    ACU_PutToBuffer_Threshold(hdl, pBuf, &dataCount, AMRDEC_PARSER_BUFSIZE/4);
            	 	    medhdl->ReadDataDone(medhdl, dataCount);
            	 	 }
            	 	 break;
            	 }
            	 while(bsparse > 0)
            	 {
                  bFrameHeader = pBuf[accbslen];
                  uframeLen = amrGetFrameLength( ihdl->mediaType, bFrameHeader);
                  accbslen += uframeLen;
                  bsparse -= uframeLen;
               }
               if(bsparse < 0)
               { 
               	  accbslen -= uframeLen;
               }
               if(accbslen ==0)
               {
               	  if(bsLen_total<uframeLen && medhdl->eof==KAL_FALSE)
               	  {
               	     kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PAR_OK, MTKAUD_PARSER_AMR, bsLen_total, uframeLen,0,0,0,0);
               	     break;
               	  }
               	  else
               	  {
               	  	 ACU_PutToBuffer_Threshold(hdl, pBuf, &dataCount, AMRDEC_PARSER_BUFSIZE/4);
               	  	 medhdl->ReadDataDone(medhdl, dataCount);
               	  	 medhdl->GetReadBuffer(medhdl, &pBuf, &bsLen);
               	  	 bsLen = uframeLen - dataCount;
               	  	 ACU_PutToBuffer_Threshold(hdl, pBuf, &bsLen, AMRDEC_PARSER_BUFSIZE/4);
               	  	 medhdl->ReadDataDone(medhdl, bsLen);
               	  	 kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PAR_OK, MTKAUD_PARSER_AMR, ihdl->mhdl->eof, (dataCount+bsLen),pBuf,0,0,0);
               	  } 
               }
               else
               {
            	    ACU_PutToBuffer_Threshold(hdl, pBuf, &accbslen, AMRDEC_PARSER_BUFSIZE/4);
            	    medhdl->ReadDataDone(medhdl, accbslen);
            	    kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PAR_OK, MTKAUD_PARSER_AMR, ihdl->mhdl->eof, accbslen,pBuf,0,0,0);            	    
            	 }            	 
            }
            else
            {
               ACU_PutToBuffer_Threshold(hdl, pBuf, &bsLen, AMRDEC_PARSER_BUFSIZE/4);
               medhdl->ReadDataDone(medhdl, bsLen);
               kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PAR_OK, MTKAUD_PARSER_AMR, ihdl->mhdl->eof, bsLen,pBuf,0,0,0);
            }
            if(ihdl->isEOF)
            {
               kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_EOF, MTKAUD_PARSER_AMR, 0,0,0,0,0);
            }
         }
      }
   }

   return OMX_ErrorNone;
}

static OMX_ERRORTYPE AmrPar_Process(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   AMR_ParData *pParData = (AMR_ParData *)ihdl->pPrivateData;
   MHdl *pMedHdl = (MHdl *)ihdl->mhdl;

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PROCESS, MTKAUD_PARSER_AMR, pMedHdl->waiting, ihdl->Decode_EOF,0,0,0,0);
   if (ihdl->Decode_EOF)
   {
      return OMX_ErrorNone;
   }
   if(pParData->pstFSAL == NULL)
   {
      mhdlRefillAndUpdateVideoBuffer(pMedHdl);
      AmrPar_Process_Internal(hdl);
   }
   if(!pMedHdl->waiting && pMedHdl->pStrmStruct==NULL )
   {
      pMedHdl->waiting = KAL_TRUE;   
      pMedHdl->handler( pMedHdl, MEDIA_DATA_REQUEST );
   }
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE AmrPar_SetParameter(AudComHdl *hdl, OMX_INDEXTYPE index, OMX_PTR pStruct)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   AMR_ParData *pParData = (AMR_ParData *)ihdl->pPrivateData;

   switch(index)
   {
      case OMX_IndexParamMedFileHandle:
      {
         AcuParseParam *pParam = (AcuParseParam *)pStruct;
         pParData->pstFSAL = pParam->pstFSAL;
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SETPARAM, MTKAUD_PARSER_AMR, 0, pParData->pstFSAL ,0,0,0);
         break;
      }
      case OMX_IndexParamAudioAmr:
      {
         AMR_FrameInfo *pParam = (AMR_FrameInfo *)pStruct;
         pParam->bIsStereo   = KAL_FALSE;
         pParam->uFrameDur   = AMR_FRAME_DURATION / 1000;
         pParam->uSampleRate = 8000;
         pParam->bIsWideBand = KAL_FALSE;
#if defined(AMRWB_DECODE)
         if(MEDIA_FORMAT_AMR_WB == ihdl->mediaType)
         {
            pParam->uSampleRate = 16000;
            pParam->bIsWideBand = KAL_TRUE;
         }
#endif
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SETPARAM, MTKAUD_PARSER_AMR, 1, pParam->bIsWideBand ,0,0,0);
         break;
      }
      default:
         return OMX_ErrorNotImplemented;
   }
   return OMX_ErrorNone;
}


/*------------------------------------------------*/
/* The public functions of AMR parser.            */
/*------------------------------------------------*/
OMX_U32 AmrPar_GetMemSize( void )
{
   OMX_U32 uTempSize, uReqSizeTotal;

   uReqSizeTotal = 0;
   
   // The memory size for AudComHdlInt
   uTempSize = (sizeof(AudComHdlInt) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   
   // The memory for AMR private data
   uTempSize = (sizeof(AMR_ParData) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_GETMEMSIZE, MTKAUD_PARSER_AMR, uReqSizeTotal,0,0,0,0,0);
   return uReqSizeTotal;
}

OMX_ERRORTYPE AmrPar_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
)
{
   //OMX_U32 uBufSize;
   AudComHdlInt *ihdl;
   OMX_U8 *pBuffer8;
   
   *pHandle = NULL;
   
   // The buffer address should be 4 bytes aligned
   ASSERT( (((kal_uint32)pBuffer) & 0x3) == 0);
   
   // Empty the memory
   //uBufSize = AmrPar_GetMemSize();
   //memset(pBuffer, 0, uBufSize);
   
   // Assign and distribute the memory
   *pHandle = pBuffer;
   pBuffer8 = (kal_uint8 *)pBuffer;
   ihdl = (AudComHdlInt *)pBuffer;
   pBuffer8 += (sizeof(AudComHdlInt) + 3) & ~0x3;
   ihdl->pPrivateData = (void *)pBuffer8;
   
   // Initialize the audio handler as default setting
   ACU_InitHdl(*pHandle, pFWData, pCallback);
   
   // Overwrite the member functions
   ihdl->basic.Start        = AmrPar_Start;
   ihdl->basic.Stop         = ACU_ParGenStop;
   ihdl->basic.Deinit       = ACU_GenDeinit;
   ihdl->basic.Process      = AmrPar_Process;
   ihdl->basic.SetParameter = AmrPar_SetParameter;

   ihdl->mediaStatus = COMPONENT_STATE_READY;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_INIT, MTKAUD_PARSER_AMR, ihdl->mediaStatus,0,0,0,0);
   return OMX_ErrorNone;
}

#endif
