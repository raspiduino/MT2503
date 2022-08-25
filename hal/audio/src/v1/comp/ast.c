/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 *   ast.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Audio Seek Table (AST).
 *   The AST is a file-offset frame-number mapping table.
 *   AST helps accelerate the seek response time
 *
 * Author:
 * -------
 * -------
 *
 *===========================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *===========================================================
*****************************************************************************/
// kal_release.h is needed by kal_trace.h
//#include "kal_release.h"
#include "kal_trace.h"
//#include "ps_trace.h"

#include "l1sp_trc.h"
#include "ast.h"

unsigned int AST_GetFrameDuration(AudioSeekTable *ASTable)
{
   return ASTable->uFrameDuration; 
}

AST_Status AST_SetFrameDuration(AudioSeekTable *ASTable, unsigned int uFrameDuration)
{
   ASTable->uFrameDuration = uFrameDuration;
   return AST_SUCCESS;
}

AST_Status AST_InitTable(AudioSeekTable *ASTable, unsigned int MinFramePerEntry, unsigned int BufSize, 
                                   AST_Status (*ASTParseFrame)(void *hdlptr, unsigned int *CurOffset, unsigned int *ParseFrameNum), 
#if !defined(__AUDIO_COMPONENT_SUPPORT__)         
                                   AST_Status (*ASTParseFileHeader)(void *hdlptr, unsigned int *FirstFrameOffset))
#else                                                              
                                   AST_Status (*ASTParseFileHeader)(void *hdlptr, unsigned int *FirstFrameOffset, unsigned int *uFrameDur))
                                   
#endif                                  
{
   if(BufSize<sizeof(ASTable)+16)
   	return AST_FAIL;
   ASTable->MaxEntryNumbers=(BufSize-sizeof(AudioSeekTable))/8;
   ASTable->FramesPerEntry = MinFramePerEntry;
   ASTable->CurrentIndex=1;
   ASTable->IsDone=0;
   ASTable->IsFail=0;
   ASTable->IsBreak=0;
   ASTable->ASTParseFileHeader = ASTParseFileHeader;
   ASTable->ASTParseFrame = ASTParseFrame;

   ASTable->AccumulateFrames=(unsigned int *)(((unsigned char*)ASTable) + ((sizeof(AudioSeekTable) +3) & 0xFFFFFFFC)) ;
   ASTable->AccumulateOffset = (unsigned int *)ASTable->AccumulateFrames + ASTable->MaxEntryNumbers;

   ASTable->AccumulateOffset[0]=0;
   ASTable->AccumulateFrames[0]=0;
   ASTable->AccumulateOffset[1]=0;
   ASTable->AccumulateFrames[1]=0;
   ASTable->uFrameDuration = 0;

#if defined(__MTK_TARGET__)
   kal_trace( TRACE_GROUP_AST, L1AUDIO_AST_FRAME_PER_ENTRY, ASTable->FramesPerEntry);
   kal_trace( TRACE_GROUP_AST, L1AUDIO_AST_INIT, ASTable->MaxEntryNumbers, BufSize);
#endif

   return AST_SUCCESS;
}

static void AST_DoubleEntrySize(AudioSeekTable *ASTable)
{
   unsigned int i;
   unsigned int *AccOffset, *AccFrames;
   unsigned int EntryNum;
   
   AccOffset = ASTable->AccumulateOffset;
   AccFrames = ASTable->AccumulateFrames;
   EntryNum = ASTable->MaxEntryNumbers;
   for(i=1 ; i<EntryNum>>1 ; i++)
   {
      *(AccOffset+i) = *(AccOffset+(i<<1));
      *(AccFrames+i) = *(AccFrames+(i<<1));
   }

   if(EntryNum&1)
   {
      *(AccOffset+i) = *(AccOffset+(i<<1));
      *(AccFrames+i) = *(AccFrames+(i<<1));  	
   }
   else
   {
      *(AccOffset+i) = *(AccOffset+(i<<1)-1);
      *(AccFrames+i) = *(AccFrames+(i<<1)-1); 
   }

   ASTable->FramesPerEntry <<= 1;
}


void AST_UpdateTable(AudioSeekTable *ASTable, unsigned int CurOffset, unsigned int CurFrames) 
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MTK_TARGET__)
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
#endif
}


AST_Status AST_BuildTable(void *hdlptr, AudioSeekTable *ASTable, unsigned int *Progress, unsigned int FileSize, char fLimitFrameNumber)
{
   unsigned int CurIndex, CurOffset, CurFrames;
   unsigned int EntryBoundary, FirstFrameOffset;
   AST_Status ParseResult = AST_SUCCESS;
   
   // FileSize is invalid
   if(0 == FileSize)
   {
      return AST_FAIL;
   }
   
   // cache table finished
   if((100 == *Progress)||(1 == ASTable->IsDone))  
   {
      //ASTable->IsDone = 1;
      *Progress = 100;
      return AST_SUCCESS;
   }

   // first time build cache, get FirstFrameOffset
   if(0 == *Progress)
   {
#if !defined(__AUDIO_COMPONENT_SUPPORT__)
      ParseResult = ASTable->ASTParseFileHeader(hdlptr,&FirstFrameOffset);
#else
      ParseResult = ASTable->ASTParseFileHeader(hdlptr,&FirstFrameOffset, &ASTable->uFrameDuration);
#endif
      if (ParseResult != AST_SUCCESS) 
      {
        return AST_PARSE_FILE_HEADER_FAIL;
      }
      ASTable->AccumulateOffset[0] = FirstFrameOffset;
   }
   FirstFrameOffset=ASTable->AccumulateOffset[0];

   CurIndex = (unsigned int)ASTable->CurrentIndex;
   
   // Parse frames for cache
   EntryBoundary = ASTable->AccumulateFrames[CurIndex-1] + ASTable->FramesPerEntry;
   CurFrames=ASTable->AccumulateFrames[CurIndex];
   CurOffset=ASTable->AccumulateOffset[CurIndex];
   
   if(FirstFrameOffset>CurOffset)
   {
   	CurOffset = FirstFrameOffset;
   	CurFrames = 0;
   }
   	
 
   if(EntryBoundary > CurFrames)
   { 
      unsigned int ParseFrameNum = EntryBoundary-CurFrames;

#if defined LIMIT_AST_BUILD_TABLE_FRAMES 
      if(ParseFrameNum>MAX_BUILD_FRAME_NUMBER && fLimitFrameNumber)
	  	ParseFrameNum = MAX_BUILD_FRAME_NUMBER;
#endif

      ParseResult  = ASTable->ASTParseFrame(hdlptr, &CurOffset, &ParseFrameNum);
#if defined(__MTK_TARGET__)
      kal_trace( TRACE_GROUP_AST, L1AUDIO_AST_BUILD_TABLE, ParseResult, EntryBoundary-CurFrames, ParseFrameNum);
#endif
      CurFrames+=ParseFrameNum;
   }
   // update cache table
   ASTable->AccumulateOffset[CurIndex]=CurOffset;
   ASTable->AccumulateFrames[CurIndex]=CurFrames;
   if(CurFrames >= EntryBoundary)
   	CurIndex++;

   if (ParseResult == AST_EOF) 
   {
      ASTable->CurrentIndex = CurIndex; 
      ASTable->IsDone = 1;
   }
   else if (ParseResult == AST_PARSE_FRAME_FAIL)  
   {
     ASTable->CurrentIndex = CurIndex; 
     ASTable->IsFail = 1;
   }
   else if (ParseResult == AST_PARSE_FRAME_BREAK)  
   {
       ASTable->CurrentIndex = CurIndex;    
	ASTable->IsBreak = 1;
   }
   
   //update build progress
   //only AST_PARSE_FILE_HEADER_FAIL, progress =0 ; else progress is calculated and returned
   if(FileSize-FirstFrameOffset>0)
      *Progress = (unsigned __int64)(CurOffset-FirstFrameOffset)*100/(FileSize-FirstFrameOffset);
   else
      *Progress = 100;   

   if(*Progress==0  || *Progress>100) //prevent parse header again
   {
      *Progress=1;
   }
   
   //double entry size
   if(ASTable->MaxEntryNumbers==CurIndex) 
   {
      AST_DoubleEntrySize(ASTable);
      CurIndex >>= 1;
   }
   ASTable->AccumulateOffset[CurIndex]=CurOffset;
   ASTable->AccumulateFrames[CurIndex]=CurFrames;
   ASTable->CurrentIndex = CurIndex;   
   return ParseResult;
}

static void AST_BinarySearch(AudioSeekTable *ASTable, unsigned int StartFrame, unsigned int *CurFrames, unsigned int *CurOffset)
{
   unsigned int StartIndex, EndIndex;
   
   StartIndex = 0;
   EndIndex = (unsigned int)(ASTable->CurrentIndex);
   
   while((EndIndex-StartIndex)>1)
   {
      unsigned int MiddleIndex = (StartIndex+EndIndex)>>1;
      if(StartFrame>ASTable->AccumulateFrames[MiddleIndex])
      {
         StartIndex = MiddleIndex;
      }
      else
      {
         EndIndex = MiddleIndex;	
      }
   }
   
   *CurFrames=ASTable->AccumulateFrames[StartIndex];
   *CurOffset=ASTable->AccumulateOffset[StartIndex];
}

unsigned int AST_Seek(void *hdlptr, AudioSeekTable *ASTable, unsigned int *SeekFrame)
{   
   unsigned int CurFrames, CurOffset;
   unsigned int StartFrame, CurIndex;

   StartFrame = *SeekFrame;
   CurIndex = (unsigned int)ASTable->CurrentIndex;

   if(StartFrame==0)
   {
      //start from beginning
      return ASTable->AccumulateOffset[0];
   }
   else if((StartFrame==ASTable->AccumulateFrames[CurIndex])
 	   &&(ASTable->AccumulateOffset[CurIndex]>ASTable->AccumulateOffset[CurIndex-1]))
   {
      //pause then resume
      return ASTable->AccumulateOffset[CurIndex];
   }
   else if(StartFrame<=ASTable->AccumulateFrames[CurIndex-1])
   {
      //the frame is indexed
      AST_BinarySearch(ASTable, StartFrame, &CurFrames, &CurOffset);
   }
   else
   {
      //the frame is not indexed
      CurFrames=ASTable->AccumulateFrames[CurIndex-1];
      CurOffset=ASTable->AccumulateOffset[CurIndex-1];
   }

   //linear search
   if(CurFrames < StartFrame)
   { 
      unsigned int ParseFrameNum = StartFrame-CurFrames;
      ASTable->ASTParseFrame(hdlptr, &CurOffset, &ParseFrameNum);
      CurFrames+=ParseFrameNum;
   }

#if defined(__MTK_TARGET__)
   kal_trace( TRACE_GROUP_AST, L1AUDIO_AST_SEEK, *SeekFrame, CurFrames, CurOffset);
#endif

   *SeekFrame=CurFrames;
   return CurOffset;
}

unsigned int AST_GetIndexedFrames(AudioSeekTable *ASTable)
{   
   unsigned int CurIndex, CurFrames;
 
   CurIndex=ASTable->CurrentIndex;

   if((CurIndex==0)||(CurIndex>ASTable->MaxEntryNumbers))
   {
      return 0;	
   }
   
   if(CurIndex==ASTable->MaxEntryNumbers || ASTable->AccumulateOffset[CurIndex]<ASTable->AccumulateOffset[CurIndex-1])
   {
      CurFrames = ASTable->AccumulateFrames[CurIndex-1];
   }
   else
   {
      CurFrames = ASTable->AccumulateFrames[CurIndex];
   }
#if defined(__MTK_TARGET__)
   kal_trace( TRACE_GROUP_AST, L1AUDIO_AST_GET_INDEXED_FRAME, CurFrames);
#endif
   return CurFrames;
}

unsigned int AST_EstimateTotalFrames(AudioSeekTable *ASTable, unsigned int FileSize)
{   
   unsigned int CurIndex, CurFrames, CurOffset, FirstFrameOffset;
   unsigned int TotalFrame;
   CurIndex=ASTable->CurrentIndex;

   if((CurIndex==0)||(CurIndex>ASTable->MaxEntryNumbers))
   {
      return 0;	
   }

   if(CurIndex==ASTable->MaxEntryNumbers || ASTable->AccumulateOffset[CurIndex]<ASTable->AccumulateOffset[CurIndex-1])
   {
      CurFrames = ASTable->AccumulateFrames[CurIndex-1];
      CurOffset = ASTable->AccumulateOffset[CurIndex-1];
   }
   else
   {
      CurFrames = ASTable->AccumulateFrames[CurIndex];
      CurOffset = ASTable->AccumulateOffset[CurIndex];
   }

   FirstFrameOffset = ASTable->AccumulateOffset[0];

   if((FileSize<=FirstFrameOffset)||(CurOffset<=FirstFrameOffset))
   {
      return 0;
   }

   CurOffset-=FirstFrameOffset;
   FileSize-=FirstFrameOffset;

   TotalFrame= (unsigned __int64)CurFrames*FileSize/CurOffset;
   
#if defined(__MTK_TARGET__)
   kal_trace( TRACE_GROUP_AST, L1AUDIO_AST_GET_TOTAL_FRAME, TotalFrame);
#endif

   return TotalFrame;
}
     
