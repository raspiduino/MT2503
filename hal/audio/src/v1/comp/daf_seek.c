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
 *   daf_seek.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   The member function for DAF seek
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef DAF_DECODE

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "fsal.h"
#include "l1audio.h"
#include "media.h"
#include "common_def.h"
#include "l1sp_trc.h"
#include "daf_drv.h"
#include "ast.h"
#include "mp3_dec_exp.h"

#define MUSICAM_DECODE_INTERNAL

/*------------------------------------------------*/
/* MP3 Parser SWIP.                               */
/*------------------------------------------------*/
#define HEADCHECK(head) (!( (((head & 0xfff00000) != 0xfff00000) && ((head & 0xfff80000) != 0xffe00000) ) || \
  ( ((head>>17)&3)== 3) || (((head>>17)&3)== 0) || \
  ( ((head>>12)&0xf) == 0xf) || ( ((head>>12)&0xf) == 0x0) || \
( ((head>>10)&0x3) == 0x3 )))
#define COMPARECHECK(First, New) (((First & 0xfffe0c00)==(New & 0xfffe0c00)) && (((New>>12)&0xf) != 0xf) && (((New>>12)&0xf) != 0))
#define UPDATE_PTR(ptr, end, base) ((ptr+1 == end)? ptr= base: ptr++)

#if ( defined(__DCM_WITH_COMPRESSION_AUDIO_CODEC__) || !defined(__AUDIO_COMPONENT_SUPPORT__) )
// Byterate
#ifdef MUSICAM_DECODE_INTERNAL
static const kal_uint8 V1_L2[15] =   {0,  4,  6,  7,  8, 10, 12, 14, 16, 20, 24, 28, 32, 40, 48};
#endif
static const kal_uint8 V1_L3[15] =   {0,  4,  5,  6,  7,  8, 10, 12, 14, 16, 20, 24, 28, 32, 40};
static const kal_uint8 V2_L2L3[15] = {0,  1,  2,  3,  4,  5,  6,  7,  8, 10, 12, 14, 16, 18, 20};

static const kal_uint32 SampleRateTable[3] = {44100, 48000, 32000};

static kal_uint16 MP3_GetFrameLength(kal_uint32 version, kal_uint32 layer, kal_uint32 sr_idx, kal_uint32 br_idx)
{
   const kal_uint8 *ByterateTable = NULL;
   kal_uint32 uSampleRate = 0;
   kal_uint32 uFrameSample, uFrameLength;
   
   // Check bitrate index
   if (br_idx >= 15)
      return 0;
   
   // Check version and layer
   if ((version == 0) || (version == 2)) {
#ifdef MUSICAM_DECODE_INTERNAL
      if (layer == 2) {
         ByterateTable = V2_L2L3;
         uFrameSample = 1152;
      } else
#endif      
      if (layer == 1) {
         ByterateTable = V2_L2L3;
         uFrameSample = 576;
      }
   } else if (version == 3) {
#ifdef MUSICAM_DECODE_INTERNAL
      if (layer == 2) {
         ByterateTable = V1_L2;
         uFrameSample = 1152;
      } else
#endif
      if (layer == 1) {
         ByterateTable = V1_L3;
         uFrameSample = 1152;
      }
   }
   if (ByterateTable == NULL)
      return 0;

   // Check sampling rate
   if (sr_idx >= 3) {
      return 0;
   } else {      
      uSampleRate = SampleRateTable[sr_idx];
      if (version == 2)
         uSampleRate = uSampleRate/2;
      else if (version == 0)
         uSampleRate = uSampleRate/4;
   }

   uFrameLength = (kal_uint64) uFrameSample * ByterateTable[br_idx] * 1000 / uSampleRate;

   return uFrameLength;
}

static kal_uint16 MP3_GetFrameLengthGeneralPri(kal_uint32 header, kal_uint32 br_idx)
{
   kal_uint32 version, layer, sr_idx;
   
   version = (header >> 19) & 0x3;
   layer = (header >> 17) & 0x3;
   sr_idx = (header >> 10) & 0x3;
   
   return MP3_GetFrameLength( version, layer, sr_idx, br_idx);
}

#define MP3_GetFrameLengthGeneralImp(x, y) MP3_GetFrameLengthGeneralPri(x, y)

#else

#define MP3_GetFrameLengthGeneralImp(x, y) MP3_GetFrameLengthGeneral(x, y)

#endif

static kal_int32 Read4Bytes(const kal_uint8 *ptr, const kal_uint8 *base, const kal_uint8 *end)
{
   kal_int32 Data32;
   
   Data32 = *ptr++;
   if(ptr == end)
      ptr = base;
   
   Data32 = (Data32<<8)|*ptr++;
   if(ptr == end)
     ptr = base;
   
   Data32 = (Data32<<8)|*ptr++;
   if(ptr == end)
     ptr = base;
   
   Data32 = (Data32<<8)|*ptr;
   
   return Data32;
}

static kal_bool NextHeadCheck(kal_uint32 arg_head, kal_uint32 firstHeader)
{
	kal_uint32 head = arg_head;
	kal_int32 masking = 0xfffe0c00;
	if((head & masking) != (firstHeader & masking))
		return KAL_FALSE;
	if( ((head>>12)&0xf) == 0xf)			/* check bit-rate */
		return KAL_FALSE;
	if( ((head>>12)&0xf) == 0x0)			/* check bit-rate */
		return KAL_FALSE;
	
	return KAL_TRUE;
}

kal_bool MP3FrmLen_GetFrmLenTableInternal(
   kal_int16 frameLengthTable[15], /* [Output] the frame length table        */
   kal_int32 *firstFHPosition,     /* [Output] If the return value is 1, it is the position of the first valid frame header (in bytes).
                                            Else, it means the size of garbage data in the input Bitstream buffer (in bytes) */
   const kal_uint8 *pBS_BUF,       /* [Input] bitstream buffer base address  */
   kal_int32  uBS_BUF_Size,        /* [Input] bitstream buffer size          */
   const kal_uint8* pBS_Read)      /* [Input] bitstream buffer read pointer  */
{
   kal_int32 FirstCandidate=-1;
   kal_int32 FrameOffset_1st = 0;
   const kal_uint8 *pBS_End = pBS_BUF+uBS_BUF_Size;
   kal_int32 uMaxCheckLen = uBS_BUF_Size;
   kal_int32 u4MarkedPossibleFirst = -1;
   kal_int32 i = 0;
   kal_int32 fh_1;
   
   do {
      fh_1 = Read4Bytes(pBS_Read, pBS_BUF, pBS_End);
        
      /******************************************
      * Step 1: Find the 2nd frame header.     *
      ******************************************/   
      
      if ( HEADCHECK(fh_1) ) {
         const kal_uint8 *pTemp_BS_Read = pBS_Read;
                     
         kal_int32 br1, uLength1;
         kal_int32 br2, uLength2, fh_2;     
         kal_int32 fh_3;
         
         br1 = ((fh_1 >> 12) & 0xf);
         
         if (FirstCandidate == -1)
            FirstCandidate = FrameOffset_1st;
      
         uLength1 = MP3_GetFrameLengthGeneralImp(fh_1, br1);

         if (uMaxCheckLen < (uLength1+8) || uLength1==0) {
            //underflow, return fail and the garbage size
            u4MarkedPossibleFirst = FrameOffset_1st;
            break;
         }

      /******************************************
      * Step 2: Check the 2nd frame header.     *
      ******************************************/

         pTemp_BS_Read += uLength1;
         if (pTemp_BS_Read >= pBS_End)
            pTemp_BS_Read-= uBS_BUF_Size;
         
         fh_2 = Read4Bytes(pTemp_BS_Read, pBS_BUF, pBS_End);
         
         for (i = 4; i >0; i--) {
            if (!NextHeadCheck(fh_2, fh_1)) {
               uLength1++;
               UPDATE_PTR(pTemp_BS_Read, pBS_End, pBS_BUF);
               fh_2 = Read4Bytes(pTemp_BS_Read, pBS_BUF, pBS_End);
            } else
               break;
         } 
         
         if (i == 0 ) {
            FirstCandidate = -1; //the 2nd header is not found.   
         } else {
      
      /******************************************
      * Step 3: Check the 3rd frame header.     *
      ******************************************/ 

            br2 = ((fh_2 >> 12) & 0xf);
            
            uLength2 = MP3_GetFrameLengthGeneralImp(fh_2, br2);
            
            if (uMaxCheckLen < (uLength1+uLength2+8)) {
               //underflow
               if((uLength1+uLength2+8) < uBS_BUF_Size)
                  u4MarkedPossibleFirst = FrameOffset_1st;
               else //The bistream buffer only can contain one frame.
                  u4MarkedPossibleFirst = -1;
               break;
            }
            
            pTemp_BS_Read += uLength2;
            if (pTemp_BS_Read >= pBS_End)
               pTemp_BS_Read-= uBS_BUF_Size;
            
            fh_3 = Read4Bytes(pTemp_BS_Read, pBS_BUF, pBS_End);
        
            for (i = 4; i >0; i--) {
               if (!NextHeadCheck(fh_3, fh_1)) {
                  uLength2++;
                  UPDATE_PTR(pTemp_BS_Read, pBS_End, pBS_BUF);
                  fh_3 = Read4Bytes(pTemp_BS_Read, pBS_BUF, pBS_End);
               } else {
                  break;
               }
            }
            if (i == 0)
               FirstCandidate = -1; //the 3rd header is not found. 
         }     
      }

      if (FirstCandidate != -1)
         break;
      else {
         FrameOffset_1st++;
         UPDATE_PTR(pBS_Read, pBS_End, pBS_BUF);
      }
   } while (--uMaxCheckLen>=4);            

   if (u4MarkedPossibleFirst != -1) {
      *firstFHPosition = u4MarkedPossibleFirst;
      return KAL_FALSE;
   }
   
   if (FirstCandidate == -1) {
      *firstFHPosition = uBS_BUF_Size;
      return KAL_FALSE;
   }
   
   *firstFHPosition = FirstCandidate;
   
   for (i=0; i<15; i++) {
      frameLengthTable[i] = MP3_GetFrameLengthGeneralImp(fh_1, i);
   } 

  return KAL_TRUE;
}

kal_bool dafIsFakeSyncWord(kal_uint16 w1, kal_uint16 w2)
{
#ifdef MUSICAM_DECODE_INTERNAL
      if( !(((w1 & 0x1800) != 0x0800) && (((w1 & 0xE6FF) == 0xE2FF) || ((w1 & 0xE6FF) == 0xE4FF))
         && ((w2 & 0x00F0) != 0x00F0) && ((w2 & 0x00F0) != 0x0) && ((w2 & 0x000C) != 0x000C)))
      {
#else
      if( !(((w1 & 0x1800) != 0x0800) && ((w1 & 0xE6FF) == 0xE2FF)
         && ((w2 & 0x00F0) != 0x00F0) && ((w2 & 0x00F0) != 0x0) && ((w2 & 0x000C) != 0x000C)))
      {
#endif
         return KAL_TRUE;
      }
      return KAL_FALSE;
}

kal_int32 GetMP3FrmLenTable(dafMediaHdl *ihdl, kal_uint8 *pbBuf, kal_int32 *u1stFHoffset)
{
   kal_int32 uResult;
   kal_int32 uMaxCheckLen = autGetBytesFromFileNoEnd((MHdl*)ihdl, ihdl->pstFSAL, ihdl->fileOffset, MAX_FRAME_CHECK_LEN, pbBuf);
   
   if( uMaxCheckLen <= 4) 
   {
      return KAL_FALSE;
   }

   uResult = MP3FrmLen_GetFrmLenTableInternal((kal_int16 *)ihdl->wFrameSizeTbl, u1stFHoffset, pbBuf, uMaxCheckLen, pbBuf);
   
   if(uResult) 
   {
      ihdl->fileOffset += *u1stFHoffset; 	   	
      return KAL_TRUE;
   }

   if(*u1stFHoffset == 0)
   {
      ihdl->fileOffset += uMaxCheckLen; 	 
   }
   else
   {
      ihdl->fileOffset += *u1stFHoffset; 	 
   }
   return KAL_FALSE;
}

kal_bool dafReachNextFrame(dafMediaHdl *ihdl, kal_uint16 *wFHdrW1, kal_uint16 *wFHdrW2, kal_int32 UpdateFlag)
{
   kal_int32 uResult, u1stFHoffset, uIdx, uOrigFileOffset;
   kal_uint8 *pbBuf;
   kal_int32 uLoopCount = 0;
   kal_uint32 uUseMedMem = 0;

#if defined(MED_LOW)
   if(ihdl->mh.rbInfo.rb_size >= MAX_FRAME_CHECK_LEN && !ihdl->isStreaming)
   {
      pbBuf = (kal_uint8*)ihdl->mh.rbInfo.rb_base;
   }
   else
#endif
   {
      pbBuf = (kal_uint8*)audio_alloc_mem( MAX_FRAME_CHECK_LEN ); 
      if(pbBuf==NULL)
      {
         return KAL_FALSE;
      }
      uUseMedMem = 1;
   }

   uOrigFileOffset = ihdl->fileOffset;  
   
   do
   {
      uLoopCount++;
      uResult = GetMP3FrmLenTable(ihdl, pbBuf, &u1stFHoffset);
   }while((!uResult)&&(uLoopCount<4));
   
   if(uResult) 
   {
      kal_uint8 *ptr = pbBuf + u1stFHoffset;
      ihdl->wHeader1 = *wFHdrW1 = (kal_uint16)ptr[0] | ((kal_uint16)ptr[1] << 8);
      ihdl->wHeader2 = *wFHdrW2 = (kal_uint16)ptr[2] | ((kal_uint16)ptr[3] << 8);
      uIdx = ((kal_int32)wFHdrW2 >> 4) & (0x0000000f);
      if(UpdateFlag)
      {
         ihdl->wExistFrmSizeTbl[uIdx] = ihdl->wFrameSizeTbl[uIdx];
      }
      if(uUseMedMem)
      {
         audio_free_mem( (void **) &pbBuf );  
      }
      kal_trace( TRACE_INFO, DAF_L1AUDIO_FIRSTWORD_POSITION, ihdl->fileOffset);
      return KAL_TRUE;
   }
   if(uUseMedMem)
   {
      audio_free_mem( (void **) &pbBuf );  
   }
   ihdl->fileOffset = uOrigFileOffset;
   return KAL_FALSE;
}

AST_Status dafASTParseFrame(void *hdlptr, kal_uint32 *CurOffset, kal_uint32 *ParseFrameNum)
{
   MHdl *hdl = hdlptr;
   dafMediaHdl *ihdl = (dafMediaHdl *)hdl;	
   AST_Status ParseResult; 
   kal_uint32 AccOffset;
   kal_uint32 Remains, uOffset;
   kal_int32 ByteCnt;
   kal_uint32 buf_len;
   kal_uint8  *pbHeader;
   kal_uint32 wMaxChkLen;
   kal_uint32 uErrorCnt ; // allow max. 4096 continuous error bytes in sequence
   kal_uint32 uCurPos;
  
   hdl->GetWriteBuffer(hdl, &pbHeader, &buf_len);
  
   ParseResult=AST_SUCCESS;
   AccOffset = *CurOffset;
   
   uErrorCnt=0;
   Remains=*ParseFrameNum;
   uOffset = 0;
   ByteCnt = 0;
   wMaxChkLen = 0;

   FSAL_GetCurPos(ihdl->pstFSAL, &uCurPos);
   
   while(Remains!=0)
   {
      kal_uint16 w1, w2;
      kal_int16 wBitRateIdx;
      if(!ByteCnt)
      {
      	  ByteCnt=autGetBytesFromFileNoEnd((MHdl*)ihdl, ihdl->pstFSAL, AccOffset, buf_len, pbHeader);
	  if( (ByteCnt < 5) || (wMaxChkLen >= ByteCnt) )
         {
            //kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_END, MEDIA_FORMAT_DAF, ihdl->AudioSeekTbl->total_frame);
	          ParseResult = AST_EOF;
	       break;
         }
      }
		 
      w1 = (uint16)pbHeader[0+uOffset] | ((uint16)pbHeader[1+uOffset] << 8);
      w2 = (uint16)pbHeader[2+uOffset] | ((uint16)pbHeader[3+uOffset] << 8);
      if ( dafIsFakeSyncWord(w1, w2) ) {
         if((uOffset+3) < ByteCnt)
         {
            uOffset++;
            uErrorCnt++;
            continue;
         }
         if(uErrorCnt < MAX_CONTINUOUS_ERROR_LEN)
	  {
            AccOffset+=uOffset;
	     ByteCnt = 0;
	     uOffset = 0;
            continue;
         }
	  AccOffset+=uOffset;
	  ParseResult = AST_PARSE_FRAME_FAIL;
         break;
      }
      if( false == dafGetBitRateIdx(w1, w2, &wBitRateIdx) )
      {
         uOffset++;
         uErrorCnt++;
         continue;
      }
      // search next MPEG frame header by Frame Length Calculation Method
      // case 1 : search at most 3 bytes
     if( ihdl->wExistFrmSizeTbl[wBitRateIdx] != 0 )
     {
        if((uOffset+ihdl->wExistFrmSizeTbl[wBitRateIdx]+5) >= ByteCnt)
        {
           wMaxChkLen = (kal_uint32)ihdl->wExistFrmSizeTbl[wBitRateIdx]+5;
           AccOffset+=uOffset;
	    ByteCnt = 0;
	    uOffset = 0;
	    continue;
        }
        uOffset += ihdl->wExistFrmSizeTbl[wBitRateIdx] - 1;
        {
           kal_uint32 uCount;
           kal_bool fValid = false;
           for(uCount=0; uCount<6; uCount++)
	    {
              w1 = (uint16)pbHeader[0+uCount+uOffset] | ((uint16)pbHeader[1+uCount+uOffset] << 8);
              w2 = (uint16)pbHeader[2+uCount+uOffset] | ((uint16)pbHeader[3+uCount+uOffset] << 8);
              if(((ihdl->wHeader1&0xFEFF) != (w1&0xFEFF)) || ((ihdl->wHeader2 & 0x000C) != (w2 & 0x000C)))
                 continue;  // check sync. word, layer, version and sample rate
              
              if ( dafIsFakeSyncWord(w1, w2) ) {
                        // Failed
              } else {
                 // valid
                 uOffset += uCount;
                 fValid = true;
#ifdef DEBUG_DUMP_LOG
                 {
                    kal_uint16 wFrameSize;
                    wFrameSize = ihdl->wExistFrmSizeTbl[wBitRateIdx] + uCount;
                    if(dafDebugCnt < DAF_CHECKSUM_MAX_SIZE)
                       dafFrameSizeInfo[dafFrameSizeCnt++] = wFrameSize;
                  }
#endif // #ifdef DAF_DEBUG_ENABLE
                  break;
               }
            }//for(uCount=0; uCount<6; uCount++)...
            if(fValid == false)
	     {
               uOffset++;
               uErrorCnt++;
               continue;
            }
	  }
      }//case1 end
      else
      { // case 2 : search at most 6 bytes
         if((kal_uint32)(uOffset+ihdl->wFrameSizeTbl[wBitRateIdx]+8) >= ByteCnt)
	  {
            wMaxChkLen = (kal_uint32)ihdl->wFrameSizeTbl[wBitRateIdx]+8;
            AccOffset+=uOffset;
	     ByteCnt = 0;
	     uOffset = 0;
            continue;
         }
         uOffset += ihdl->wFrameSizeTbl[wBitRateIdx];
         {
            kal_uint32 uCount;
            kal_bool fValid = false;
            for(uCount=0; uCount<6; uCount++)
	     {
               w1 = (uint16)pbHeader[0+uCount+uOffset] | ((uint16)pbHeader[1+uCount+uOffset] << 8);
               w2 = (uint16)pbHeader[2+uCount+uOffset] | ((uint16)pbHeader[3+uCount+uOffset] << 8);
               if(((ihdl->wHeader1&0xFEFF) != (w1&0xFEFF)) || ((ihdl->wHeader2 & 0x000C) != (w2 & 0x000C)))
                  continue;  // check sync. word, layer, version and sample rate
               
               if ( dafIsFakeSyncWord(w1, w2) ) {
               
               } else {
                  // valid
                  uOffset += uCount;
                  fValid = true;
                  ihdl->wExistFrmSizeTbl[wBitRateIdx] = ihdl->wFrameSizeTbl[wBitRateIdx]+uCount;
#ifdef DEBUG_DUMP_LOG
                  {
                     kal_uint16 wFrameSize;
                     wFrameSize = ihdl->wFrameSizeTbl[wBitRateIdx] + uCount;
                     if(dafDebugCnt < DAF_CHECKSUM_MAX_SIZE)
                        dafFrameSizeInfo[dafFrameSizeCnt++] = wFrameSize;
                  }
#endif // #ifdef DAF_DEBUG_ENABLE
                  break;
		 }
            }// for(uCount=0; uCount<6; uCount++)...
            if(fValid == false)
	     {
               if(ihdl->wFSTblIdx == 2)
	        {
                  uOffset++;
                  uErrorCnt++;
                  continue;
               }
               uOffset -= ihdl->wFrameSizeTbl[wBitRateIdx];
               ihdl->wFSTblIdx++;
               continue;
            }
         }
      }//case2 end
      
      // one frame is successively parsed
      uErrorCnt = 0;
      Remains --;

   }

   *ParseFrameNum-=Remains;
   AccOffset+=uOffset;
   *CurOffset=AccOffset;
   FSAL_Seek( ihdl->pstFSAL, uCurPos);
   return ParseResult;
   
}

AST_Status dafASTParseFileHeader(void *hdlptr, kal_uint32 *FirstFrameOffset)
{
   kal_uint16 data1, data2;
   kal_uint32 ver;
   MHdl *hdl = hdlptr;
   dafMediaHdl *ihdl = (dafMediaHdl *)hdl;


   ihdl->fileOffset = 0;
   ihdl->end_status = MEDIA_NONE;
   hdl->rbInfo.read = 0;
   hdl->rbInfo.write = 0;
   hdl->eof = KAL_FALSE;
   hdl->waiting = KAL_FALSE;
   hdl->current_time = hdl->start_time;
   
   autSkipID3Tag( hdl, ihdl->pstFSAL, &ihdl->fileOffset, &ihdl->buf[0] );	

   if ( dafReachNextFrame(ihdl, &data1, &data2, 0) == KAL_FALSE )
   {
         return AST_PARSE_FILE_HEADER_FAIL;
   }
   dafUpdateInfo(ihdl, data1, data2);
   AST_SetFrameDuration(ihdl->AudioSeekTbl, ihdl->frameDur);

   ver = (data1>>11) & 3;  /* to get MPEG version */
   data1 = (data1>>9) & 3; /* to get Layer # */

#ifdef MUSICAM_DECODE_INTERNAL
   if( (ver == 0x01) || ((data1 != 0x01) && (data1 != 0x02)) ) /* Check MPEG version & Layer */
#else
   if( ver == 0x01 || data1 != 0x01 )  /* Check MPEG version & Layer III */
#endif // #ifdef MUSICAM_DECODE_INTERNAL
      return AST_PARSE_FILE_HEADER_FAIL;

   data1 = (data2 >> 2) & 3;

   if(data1 == 3)   /* invalid sampling rate */
      return AST_PARSE_FILE_HEADER_FAIL;


   *FirstFrameOffset=ihdl->fileOffset;
   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_STROFFSET, hdl->mediaType, 0, ihdl->fileOffset );
   return AST_SUCCESS;
}



kal_bool dafSeek(dafMediaHdl *ihdl, kal_bool fCacheEnable)
{   
   kal_uint32 CurFrames, CurOffset, StartFrame;

   ASSERT(ihdl->frameDur != 0); // memory corrupted
   StartFrame = (kal_uint64)ihdl->mh.start_time * 1000000 / ihdl->frameDur; // calculate start frame count
   CurFrames=StartFrame;

   if(fCacheEnable && ihdl->AudioSeekTbl && (ihdl->AudioSeekTbl->CurrentIndex!=1) )
   {
      CurOffset=AST_Seek((MHdl *)ihdl, ihdl->AudioSeekTbl, &CurFrames);
   }
   else
   {
      CurOffset=ihdl->fileOffset;
      dafASTParseFrame((MHdl *)ihdl, &CurOffset, &CurFrames);
   }

   ihdl->fileOffset = CurOffset;
   ihdl->resumeFrameOffset = CurOffset; // last frame offset aligned frame boundary
   audResumeInfo.uCurOffset = ihdl->resumeFrameOffset;
  
   if (CurFrames != StartFrame)
   {
      ihdl->mh.start_time = ihdl->mh.current_time = (kal_uint64)CurFrames * ihdl->frameDur / 1000000; // update start time
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_SEEK_FAIL, MEDIA_FORMAT_DAF, StartFrame, ihdl->fileOffset, ihdl->mh.start_time);
      return KAL_FALSE;
   }
   else
   {
       kal_trace( TRACE_GROUP_CACHE, L1AUDIO_SEEK_RESULT, MEDIA_FORMAT_DAF, StartFrame, ihdl->fileOffset, ihdl->mh.start_time);
       return KAL_TRUE;
   }
}

void dafMFBuildCache( MHdl *hdl, Media_Status *eLastRet, kal_uint32 *uProgress, kal_bool fLimitFrameNumber)
{
   dafMediaHdl *ihdl = (dafMediaHdl *)hdl;
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
   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_BUILD_CACHE, hdl->mediaType, *eLastRet, *uProgress );
}

void dafMFSetCacheTbl( MHdl *hdl, kal_uint8 *ptr, kal_uint32 usize )
{
   dafMediaHdl *ihdl = (dafMediaHdl *)hdl;
   ASSERT(((uint32)ptr & 0x03) == 0 );   /* make sure 4-byte alignment */

   ihdl->AudioSeekTbl = (AudioSeekTable *)ptr;

   if(ihdl->AudioSeekTbl->CurrentIndex==0)
   {
      AST_InitTable(ihdl->AudioSeekTbl,DAF_AST_MIN_ENTRY_SIZE,usize,dafASTParseFrame,dafASTParseFileHeader);
   }
#ifdef DEBUG_DUMP_LOG
   if(dafFrameSizeCnt == 0xFFFFFFFF)
   {
      dafFrameSizeCnt = 0;
   }
#endif // #ifdef DAF_DEBUG_ENABLE
   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_SET_CACHE_TBL, hdl->mediaType );
}

kal_uint32 dafMFGetCacheDur(MHdl *hdl)
{
   kal_uint32 uDur, CurFrames;
   dafMediaHdl *ihdl = (dafMediaHdl *) hdl;

   //ASSERT(ihdl->frameDur != 0);
   ASSERT(ihdl->AudioSeekTbl != 0);

   CurFrames=AST_GetIndexedFrames(ihdl->AudioSeekTbl);
   uDur = (kal_uint64)CurFrames*AST_GetFrameDuration(ihdl->AudioSeekTbl)/1000000;
   return uDur;
}

kal_uint32 dafMFGetTotalDuration( MHdl *hdl )
{
   kal_uint32 uDur, TotalFrames;
   dafMediaHdl *ihdl = (dafMediaHdl *) hdl;

   //ASSERT(ihdl->frameDur != 0);
   ASSERT(ihdl->AudioSeekTbl != 0);

   autGetFileSize(hdl, ihdl->pstFSAL, &ihdl->uFileSize);
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
      return 0;
   }
   uDur = (kal_uint64)TotalFrames*AST_GetFrameDuration(ihdl->AudioSeekTbl)/1000000;
   if (uDur < ihdl->mh.current_time)
         uDur = ihdl->mh.current_time;
   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_GET_TOTAL_DUR, hdl->mediaType, uDur );
   return uDur;
}

#endif
