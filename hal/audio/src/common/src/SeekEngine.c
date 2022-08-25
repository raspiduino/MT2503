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
 *   The header file for basic audio component
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

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "fsal.h"
#include "kal_trace.h"
#include "audio_enum.h"
#include "l1audio.h"
#include "AudCom.h"
#include "l1sp_trc.h"
#include "ast.h"
#include "daf_drv.h"
#include "DAF_codec.h"
#include "MedAdapt.h"
#include "AudComUtil.h"

void AudAstBuildCache( MHdl *hdl, Media_Status *eLastRet, kal_uint32 *uProgress, kal_bool fLimitFrameNumber)
{
   MHPB_Internal *pHdl = (MHPB_Internal *)hdl;
   AST_Status ParseResult;

   if (pHdl->uGetDurProgress == 0) {
      *uProgress=0;
   } else {
      *uProgress = pHdl->uGetDurProgress;
   }
   
   ParseResult = AST_BuildTable(hdl, pHdl->AudioSeekTbl, uProgress, pHdl->uFileSize ,fLimitFrameNumber);

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

   pHdl->uGetDurProgress = *uProgress;
   if( 100 == pHdl->uGetDurProgress )
   {
      *eLastRet = MEDIA_SUCCESS;
      hdl->start_time = 0;
      pHdl->uOffset = 0;
   }
   
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_BUILD_AST, hdl, *uProgress, ParseResult);
}


void DafAstSetCacheTbl( MHdl *hdl, kal_uint8 *ptr, void *param )
{
   MHPB_Internal *pHdl = (MHPB_Internal *)hdl;
   
   /* make sure 4-byte alignment */
   ASSERT(((uint32)ptr & 0x03) == 0 );

   pHdl->AudioSeekTbl = (AudioSeekTable *)ptr;

   if (pHdl->AudioSeekTbl->CurrentIndex == 0) {
      AST_InitTable(pHdl->AudioSeekTbl, DAF_AST_MIN_ENTRY_SIZE, 2048, pHdl->ParseFrame, pHdl->ParseHeader);
   }

   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_SET_CACHE_TBL, MEDIA_FORMAT_DAF );
}


kal_uint32 AudAstGetCacheDur(MHdl *hdl)
{
   kal_uint32 uDur, CurFrames;
   MHPB_Internal *pHdl = (MHPB_Internal *)hdl;
   
   ASSERT(pHdl->AudioSeekTbl != 0);
   
   CurFrames=AST_GetIndexedFrames(pHdl->AudioSeekTbl);
   uDur = (kal_uint64)CurFrames*AST_GetFrameDuration(pHdl->AudioSeekTbl)/1000000;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_AST_DUR, uDur, hdl, CurFrames, AST_GetFrameDuration(pHdl->AudioSeekTbl),0,0);
   return uDur;
}


kal_uint32 AudAstGetTotalDuration( MHdl *hdl )
{
   kal_uint32 uDur, TotalFrames;
   MHPB_Internal *pHdl = (MHPB_Internal *)hdl;
   
   ASSERT(pHdl->AudioSeekTbl != 0);

   FSAL_GetFileSize(pHdl->pstFSAL, &pHdl->uFileSize);
   if(1==pHdl->AudioSeekTbl->IsFail || 1==pHdl->AudioSeekTbl->IsDone)
   {
      TotalFrames=AST_GetIndexedFrames(pHdl->AudioSeekTbl);
   }
   else
   {
      TotalFrames=AST_EstimateTotalFrames(pHdl->AudioSeekTbl,pHdl->uFileSize);
   }
   
   if(TotalFrames==0)
   {
      uDur = 0;
   }
   else
   {
      uDur = (kal_uint64)TotalFrames*AST_GetFrameDuration(pHdl->AudioSeekTbl)/1000000;
   }
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_TOTAL_DUR_AST, uDur, hdl, TotalFrames, AST_GetFrameDuration(pHdl->AudioSeekTbl),0,0);
   return uDur;
}


kal_bool DafSeek(AudComHdl *hdl, kal_bool fCacheEnable)
{   
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   DAF_ParData *pParData = (DAF_ParData *)ihdl->pPrivateData;
   MHPB_Internal *pPBhdl = (MHPB_Internal *)ihdl->mhdl;
   kal_uint32 CurFrames, CurOffset, StartFrame;

   ASSERT(pPBhdl->frameDur != 0); // memory corrupted
   StartFrame = ((kal_uint64)pPBhdl->mh.start_time * 1000000 / pPBhdl->frameDur); // calculate start frame count
   
   if ((kal_uint64)pPBhdl->mh.start_time * 1000000 - (StartFrame *pPBhdl->frameDur)){
      StartFrame += 1;
   }
   CurFrames = StartFrame;

   if ( fCacheEnable && pPBhdl->AudioSeekTbl && (pPBhdl->AudioSeekTbl->CurrentIndex!=1) ) {
      CurOffset = AST_Seek(ihdl->mhdl, pPBhdl->AudioSeekTbl, &CurFrames);
   } else {
      CurOffset = pParData->uOffset;
      pPBhdl->ParseFrame(ihdl->mhdl, &CurOffset, &CurFrames);
   }

   pParData->uOffset = CurOffset;
  
   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_SEEK_RESULT, MEDIA_FORMAT_DAF, StartFrame,CurFrames, pParData->uOffset, pPBhdl->mh.start_time);
   if (CurFrames != StartFrame) 
   {
      return KAL_FALSE;
   } 
   else 
   {
      return KAL_TRUE;
   }
}

void DafSeekWithResume( AudComHdl *hdl )
{   
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   DAF_ParData *pParData = (DAF_ParData *)ihdl->pPrivateData;
   MHPB_Internal *pPBhdl = (MHPB_Internal *)ihdl->mhdl;
   kal_uint32 uResumeFrame, uPauseFrame, uJumpFrame;

   if(pPBhdl->frameDur==0)
   {
      return;
   }
   uResumeFrame = (kal_uint64)pPBhdl->mh.start_time * 1000000 / pPBhdl->frameDur;

   ACU_GetResumePoint(&pParData->ResBuf, &pParData->uOffset, &uPauseFrame);

   if(uPauseFrame<uResumeFrame)
   {
      uJumpFrame = uResumeFrame - uPauseFrame;
      pPBhdl->ParseFrame(ihdl->mhdl, &pParData->uOffset, &uJumpFrame);
      uPauseFrame += uJumpFrame;
   }
   pPBhdl->mh.start_time = (kal_uint32)((kal_uint64)uPauseFrame * pPBhdl->frameDur / 1000000); // update start time 

}

