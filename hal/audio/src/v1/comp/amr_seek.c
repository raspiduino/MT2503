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
 *   amr_seek.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   The member function for AMR seek
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
#if !defined (__AUDIO_COMPONENT_SUPPORT__)
#if defined(AMR_CODEC)

#include "kal_general_types.h"
#include "kal_public_api.h"
//#include "kal_release.h"
//#include "kal_non_specific_general_types.h"
#include "kal_trace.h"
#include "fsal.h"

#include "l1audio.h"
#include "common_def.h"
#include "ast.h"
//#include "media.h"
#include "l1sp_trc.h"
#include "amr_drv.h"
#include "amr_table.h"

AST_Status amrASTParseFileHeader(void *hdlptr, kal_uint32 *FirstFrameOffset)
{
   MHdl *hdl = hdlptr;
   amrMediaHdl *ihdl = (amrMediaHdl *)hdl;
   
   ihdl->fileOffset = 0;   
   ihdl->end_status = MEDIA_NONE;	
   hdl->rbInfo.read = 0;
   hdl->rbInfo.write = 0;
   hdl->eof = KAL_FALSE;
   hdl->waiting = KAL_FALSE;
   hdl->current_time = hdl->start_time;

   if (amrChkFileHeader(ihdl)==KAL_FALSE )
   {
      return AST_PARSE_FILE_HEADER_FAIL;
   }

   *FirstFrameOffset=ihdl->fileOffset;
   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_STROFFSET, MEDIA_FORMAT_AMR, 0, ihdl->fileOffset );
   return AST_SUCCESS;
}




AST_Status amrASTParseFrame(void *hdlptr, kal_uint32 *CurOffset, kal_uint32 *ParseFrameNum)
{
   MHdl *hdl = hdlptr;
   amrMediaHdl *ihdl = (amrMediaHdl *)hdl;	
   AST_Status ParseResult; 
   kal_uint32 AccOffset, Remains;
   
   kal_uint8 *pbHeader;
   kal_uint32 buf_len, uOffset;

   kal_int32 ByteCnt;
   kal_uint32 uCurPos;
   ihdl->mh.GetWriteBuffer((MHdl *)ihdl, &pbHeader, &buf_len);

   ParseResult=AST_SUCCESS;
   AccOffset = *CurOffset;
   Remains = *ParseFrameNum;
   uOffset = 0;
   ByteCnt = 0;
   
   uOffset = 0;
   FSAL_GetCurPos(ihdl->pstFSAL, &uCurPos);  
   while(Remains!=0)
   {
      kal_uint32 uHeader;
      if(!ByteCnt)
      {
         if( (ByteCnt = amrGetBytesFromFile((MHdl*)ihdl, ihdl->pstFSAL, AccOffset, buf_len, pbHeader)) < 0)
         {
            ParseResult = AST_EOF;
   	     break;
         }
      }
      uHeader = (kal_uint32)*(pbHeader+uOffset);

#if defined(AMRWB_DECODE)
      if (MEDIA_FORMAT_AMR_WB == ihdl->mh.mediaType)
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
         kal_uint32  FT, FQI;
         FT = (uHeader >> 3) & 0x0F;
         FQI = (uHeader >> 2) & 0x01;
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
   return ParseResult;
}

kal_bool amrSeek( amrMediaHdl *ihdl, kal_bool cacheEnable )
{
   kal_uint32 CurFrames, CurOffset, StartFrame;

   StartFrame = (kal_uint64)ihdl->mh.start_time / FRAME_DURATION; // calculate start frame count
   CurFrames=StartFrame;

   if(cacheEnable && ihdl->AudioSeekTbl && (ihdl->AudioSeekTbl->CurrentIndex!=1))
   {
      CurOffset=AST_Seek((MHdl *)ihdl, ihdl->AudioSeekTbl, &CurFrames);
   }
   else
   {
      CurOffset=ihdl->fileOffset;
      amrASTParseFrame((MHdl *)ihdl, &CurOffset, &CurFrames);
   }
   
   ihdl->fileOffset = CurOffset;
   ihdl->lastFrameOffset = CurOffset; // last frame offset aligned frame boundary

   if (CurFrames != StartFrame)
   {
      ihdl->mh.start_time = ihdl->mh.current_time = CurOffset * FRAME_DURATION; // update start time
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_SEEK_FAIL, MEDIA_FORMAT_AMR, StartFrame, ihdl->fileOffset, ihdl->mh.start_time);
      return KAL_FALSE;
   }
   else
   {
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_SEEK_RESULT, MEDIA_FORMAT_AMR, StartFrame, ihdl->fileOffset, ihdl->mh.start_time);
      return KAL_TRUE;
   }
}

void amrMFBuildCache( MHdl *hdl, Media_Status *eLastRet, kal_uint32 *uProgress, kal_bool fLimitFrameNumber)
{
   amrMediaHdl *ihdl = (amrMediaHdl *)hdl;
   AST_Status ParseResult;
   
   if(hdl->uGetDurProgress == 0)
      *uProgress=0;
   else
      *uProgress = hdl->uGetDurProgress;
   
   ParseResult = AST_BuildTable(hdl, ihdl->AudioSeekTbl, uProgress, ihdl->uFileSize ,fLimitFrameNumber);
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
      ihdl->fileOffset = 0;
   }
   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_BUILD_CACHE, MEDIA_FORMAT_AMR, *eLastRet, *uProgress );
}

void amrMFSetCacheTbl( MHdl *hdl, kal_uint8 *ptr, kal_uint32 usize )
{
   amrMediaHdl *ihdl = (amrMediaHdl *)hdl;
   ASSERT(((uint32)ptr & 0x03) == 0 );   /* make sure 4-byte alignment */
   ihdl->AudioSeekTbl = (AudioSeekTable *)ptr;
   if(ihdl->AudioSeekTbl->CurrentIndex==0)
   {
      AST_InitTable(ihdl->AudioSeekTbl,AMR_AST_MIN_ENTRY_SIZE,usize,amrASTParseFrame,amrASTParseFileHeader);
   }
   AST_SetFrameDuration(ihdl->AudioSeekTbl, FRAME_DURATION * 1000000);

   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_SET_CACHE_TBL, MEDIA_FORMAT_AMR );
}

kal_uint32 amrMFGetCacheDur(MHdl *hdl)
{
   kal_uint32 uDur, CurFrames;
   amrMediaHdl *ihdl = (amrMediaHdl *) hdl;

   ASSERT(ihdl->AudioSeekTbl != 0);

   CurFrames=AST_GetIndexedFrames(ihdl->AudioSeekTbl);
   uDur = (kal_uint64)CurFrames*AST_GetFrameDuration(ihdl->AudioSeekTbl)/1000000;
   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_GET_DUR, MEDIA_FORMAT_AMR, uDur );
   return uDur;
}

kal_uint32 amrMFGetTotalDuration( MHdl *hdl )
{

   kal_uint32 uDur, TotalFrames;
   amrMediaHdl *ihdl = (amrMediaHdl *) hdl;

   ASSERT(ihdl->AudioSeekTbl != 0);

   FSAL_GetFileSize(ihdl->pstFSAL, &ihdl->uFileSize);   
   if(1==ihdl->AudioSeekTbl->IsFail || 1==ihdl->AudioSeekTbl->IsDone)
      TotalFrames=AST_GetIndexedFrames(ihdl->AudioSeekTbl);
   else
      TotalFrames=AST_EstimateTotalFrames(ihdl->AudioSeekTbl,ihdl->uFileSize);
   if(TotalFrames==0)
   {
      return 0;
   }
   uDur = (kal_uint64)TotalFrames*AST_GetFrameDuration(ihdl->AudioSeekTbl)/1000000;
   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_GET_TOTAL_DUR, MEDIA_FORMAT_AMR, uDur );
   return uDur;
   

}

#endif
#endif
