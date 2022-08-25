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
 *   DafParser.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   The parser of DAF.
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

#include "kal_general_types.h"
#include "kal_trace.h"
#include "fsal.h"
#include "string.h"
#include "audio_enum.h"
#include "l1audio.h"
#include "AudCom.h"
#include "MedAdapt.h"
#include "ast.h"
#include "OMX_Types.h"
#include "OMX_Core.h"
#include "OMX_Index.h"
#include "l1sp_trc.h"
#include "AudComUtil.h"
#include "DAF_codec.h"
#include "media.h"

/*------------------------------------------------*/
/* The private functions for DAF seek.            */
/*------------------------------------------------*/
kal_int32 DafGetFrmLenTable(AudComHdlInt *ihdl, kal_uint8 *pbBuf, kal_int32 *u1stFHoffset)
{
   DAF_ParData *pParData = (DAF_ParData *)ihdl->pPrivateData;
   kal_int32 uTblResult;
   kal_uint32 uBufLen, uOrigFileOffset;
   OMX_ERRORTYPE eResult;

   uBufLen = MAX_FRAME_CHECK_LEN;
   uOrigFileOffset = pParData->uOffset;
   eResult = ACU_GetBytesFromFile(pParData->stFile.pstFSAL, &uOrigFileOffset, &uBufLen, pbBuf);

   if (OMX_ErrorNone != eResult) {
      // Read Error
      return KAL_FALSE;
   } else if (uBufLen <= 4) {
      return KAL_FALSE;
   }

   uTblResult = MP3FrmLen_GetFrmLenTableInternal((kal_int16 *)pParData->wFrameSizeTbl, u1stFHoffset, pbBuf, uBufLen, pbBuf);

   if (uTblResult) {
      pParData->uOffset = uOrigFileOffset + (*u1stFHoffset);
      return KAL_TRUE;
   } else {
      pParData->uOffset += uBufLen;
      return KAL_FALSE;
   }
}

kal_bool DafReachNextFrame(AudComHdl *hdl, kal_uint16 *wFHdrW1, kal_uint16 *wFHdrW2, kal_int32 UpdateFlag)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   DAF_ParData *pParData = (DAF_ParData *)ihdl->pPrivateData;
   kal_int32 uTblResult, u1stFHoffset, uOrigFileOffset;
   kal_uint8 *pbBuf;
   kal_int32 uLoopCount = 0;
   kal_bool result;

   // Prepare the bitstream
   uOrigFileOffset = pParData->uOffset;
   pbBuf = (kal_uint8*)audio_alloc_mem( MAX_FRAME_CHECK_LEN );
   ASSERT(pbBuf != NULL);

   do {
      uLoopCount++;
      uTblResult = DafGetFrmLenTable(ihdl, pbBuf, &u1stFHoffset);
   } while((!uTblResult) && (uLoopCount<4));

   if (uTblResult) {
      kal_uint8 *ptr = pbBuf + u1stFHoffset;
      kal_uint32 uIdx;

      pParData->wHeader1 = *wFHdrW1 = (kal_uint16)ptr[0] | ((kal_uint16)ptr[1] << 8);
      pParData->wHeader2 = *wFHdrW2 = (kal_uint16)ptr[2] | ((kal_uint16)ptr[3] << 8);

      uIdx = ((kal_int32)wFHdrW2 >> 4) & (0x0000000f);

      if (UpdateFlag)
         pParData->wExistFrmSizeTbl[uIdx] = pParData->wFrameSizeTbl[uIdx];

      kal_trace( TRACE_INFO, DAF_L1AUDIO_FIRSTWORD_POSITION, pParData->uOffset);

      result = KAL_TRUE;
   } else {
      pParData->uOffset = uOrigFileOffset;
      result = KAL_FALSE;
   }

   audio_free_mem( (void **) &pbBuf );

   return result;
}

kal_uint32 dafGetSamplingRate(kal_uint32 MPEGver, kal_uint32 srIdx)
{
   kal_uint32 samplingRate;

   /* sampling rate */
   if( MPEGver == 3 && srIdx == 0 )         /* MPEG1, 44100 */
      samplingRate = 44100;
   else if( MPEGver == 3 && srIdx == 1 )    /* MPEG1, 48000 */
      samplingRate = 48000;
   else if( MPEGver == 3 && srIdx == 2 )    /* MPEG1, 32000 */
      samplingRate = 32000;
   else if( MPEGver == 2 && srIdx == 0 )    /* MPEG2, 22050 */
      samplingRate = 22050;
   else if( MPEGver == 2 && srIdx == 1 )    /* MPEG2, 24000 */
      samplingRate = 24000;
   else if( MPEGver == 2 && srIdx == 2 )    /* MPEG2, 16000 */
      samplingRate = 16000;
   else if( MPEGver == 0 && srIdx == 0 )    /* MPEG2.5, 11025 */
      samplingRate = 11025;
   else if( MPEGver == 0 && srIdx == 1 )    /* MPEG2.5, 12000 */
      samplingRate = 12000;
   else if( MPEGver == 0 && srIdx== 2 )    /* MPEG2.5, 8000 */
      samplingRate = 8000;
   else
      samplingRate = 0;
   
   return samplingRate;
}

static void DafUpdateInfo(AudComHdlInt *ihdl, uint16 wFHdrW1, uint16 wFHdrW2)
{
   DAF_ParData *pParData = (DAF_ParData *)ihdl->pPrivateData;
   kal_uint16 MPEGver;
   kal_int32  sample_rate_idx;

#ifdef MUSICAM_DECODE
   kal_uint16 layer;
   layer = (wFHdrW1>>9) & 3;
#endif // #ifdef MUSICAM_DECODE

   MPEGver = (wFHdrW1>>11) & 3;         /* check MPEG audio version ID */
   sample_rate_idx = (wFHdrW2 >> 2) & 3;    /* sampling rate frequency index */

   /* check sampling rate */
   pParData->uSampleRate = dafGetSamplingRate(MPEGver, sample_rate_idx);

#ifdef MUSICAM_DECODE
   if (layer == 1) {
      // Layer III
#endif // #ifdef MUSICAM_DECODE
      if ( MPEGver == 3 ) {
         /* MPEG1 */
         pParData->uSamplesPerFrame = 1152;
      } else {
         /* MPEG2, MPEG2.5 */
         pParData->uSamplesPerFrame = 576;
      }
#ifdef MUSICAM_DECODE
   } else if (layer == 2) {
      // Layer II
      pParData->uSamplesPerFrame = 1152;
   }
#endif // #ifdef MUSICAM_DECODE

   pParData->frameDur = pParData->uSamplesPerFrame * 1000000000 / (kal_uint64) pParData->uSampleRate;
   
   {
      MHPB_Internal *pPBhdl = (MHPB_Internal *) ihdl->mhdl;
      
      pPBhdl->frameDur = pParData->frameDur;
   }
}

AST_Status DafParseHeader(void *ptrhdl, kal_uint32 *FirstFrameOffset, kal_uint32 *uFrameDur)
{
   MHPB_Internal *phdl = (MHPB_Internal *)ptrhdl;
   AudComHdl *hdl = phdl->NodeArray[0].curHdl;
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   DAF_ParData *pParData = (DAF_ParData *)ihdl->pPrivateData;

   kal_uint16 data1, data2;
   kal_uint32 ver;

   pParData->uOffset = 0;
   ACU_SkipID3Tag(pParData->stFile.pstFSAL, &pParData->uOffset, pParData->pTempBuf);

   if ( DafReachNextFrame(hdl, &data1, &data2, 0) == KAL_FALSE )
   {
      return AST_PARSE_FILE_HEADER_FAIL;
   }
   DafUpdateInfo(ihdl, data1, data2);
   
   ver = (data1>>11) & 3;  /* to get MPEG version */
   data1 = (data1>>9) & 3; /* to get Layer # */

#ifdef MUSICAM_DECODE
   /* Check MPEG version & Layer */
   if ( (ver == 0x01) || ((data1 != 0x01) && (data1 != 0x02)) )
#else
   /* Check MPEG version & Layer III */
   if ( ver == 0x01 || data1 != 0x01 )
#endif
      return AST_PARSE_FILE_HEADER_FAIL;

   data1 = (data2 >> 2) & 3;

   /* invalid sampling rate */
   if (data1 == 3)
      return AST_PARSE_FILE_HEADER_FAIL;

   *FirstFrameOffset = pParData->uOffset;
   *uFrameDur = pParData->frameDur;
   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_STROFFSET, ihdl->mediaType, 0, pParData->uOffset );

   return AST_SUCCESS;
}

static kal_bool DafGetBitRateIdx(uint16 wFHdrW1, uint16 wFHdrW2, int16 *wBitRateIdx)
{
   kal_int32  bit_rate_idx;

#ifdef MUSICAM_DECODE
   kal_uint16 layer;
   layer = (wFHdrW1>>9) & 3;
#endif

#ifdef MUSICAM_DECODE
   if ((layer == 1) || (layer == 2)) {
      bit_rate_idx = (wFHdrW2 >> 4) & 0x0F;
   } else {
      return false;
   }
#else
   bit_rate_idx = (wFHdrW2 >> 4) & 0x0F;
#endif

   *wBitRateIdx = bit_rate_idx;

   return true;
}

AST_Status DafParseFrame(void *hdlptr, kal_uint32 *CurOffset, kal_uint32 *ParseFrameNum)
{
   
   MHPB_Internal *phdl = (MHPB_Internal *)hdlptr;
   AudComHdl *ptrhdl = phdl->NodeArray[0].curHdl;
   AudComHdlInt *ihdl = (AudComHdlInt *)ptrhdl;
   DAF_ParData *pParData = (DAF_ParData *)ihdl->pPrivateData;
   MHdl *hdl = &phdl->mh; 
   AST_Status ParseResult;
   kal_uint32 AccOffset;
   kal_uint32 Remains, uOffset;//, preOffset;
   kal_int32 ByteCnt;
   kal_uint32 buf_len;
   kal_uint8  *pbHeader;
   kal_uint32 wMaxChkLen;
   kal_uint32 uErrorCnt ; // allow max. 4096 continuous error bytes in sequence
   //kal_uint32 uCurPos;

   if(hdl->rbInfo.rb_base == NULL)
   {
      buf_len = SEEK_TABLE_BS_BUFFER_LEN;
      pbHeader = (kal_uint8 *)audio_alloc_mem_cacheable(buf_len);
      ASSERT(pbHeader);
   }
   else
   {
      hdl->GetWriteBuffer(hdl, &pbHeader, &buf_len );
   }

   ParseResult = AST_SUCCESS;
   AccOffset = *CurOffset;

   uErrorCnt = 0;
   Remains = *ParseFrameNum;
   uOffset = 0;
   //preOffset = 0;
   ByteCnt = 0;
   wMaxChkLen = 0;

   //FSAL_GetCurPos(pParData->pstFSAL, &uCurPos);

   while (Remains != 0) {
      kal_uint16 w1, w2;
      kal_int16 wBitRateIdx;
      if (!ByteCnt) {
         kal_uint32 tempbuf_len = buf_len;// - preOffset;
         OMX_ERRORTYPE eResult;

         eResult = ACU_GetBytesFromFile(pParData->stFile.pstFSAL, &AccOffset, &tempbuf_len, pbHeader);
         ByteCnt = tempbuf_len;
         if ( (eResult != OMX_ErrorNone) || (ByteCnt < 5) || (wMaxChkLen >= ByteCnt) ) {
               ParseResult = AST_EOF;
         break;
         }
      }

      w1 = (uint16)pbHeader[0+uOffset] | ((uint16)pbHeader[1+uOffset] << 8);
      w2 = (uint16)pbHeader[2+uOffset] | ((uint16)pbHeader[3+uOffset] << 8);
      if ( dafIsFakeSyncWord(w1, w2) ) {
         if ( (uOffset+3) < ByteCnt ) {
            uOffset++;
            uErrorCnt++;
            continue;
         }
         if (uErrorCnt < MAX_CONTINUOUS_ERROR_LEN) {
            AccOffset+=uOffset;
            //AccOffset+=buf_len;
            //preOffset = buf_len - uOffset;
            ByteCnt = 0;
            //memcpy((kal_uint8*)pbHeader ,(kal_uint8*)pbHeader+uOffset ,preOffset*sizeof(kal_uint8));
            uOffset = 0;
            continue;
         }
         AccOffset+=uOffset;
         ParseResult = AST_PARSE_FRAME_FAIL;
         break;
      }
      if( false == DafGetBitRateIdx(w1, w2, &wBitRateIdx) ) {
         uOffset++;
         uErrorCnt++;
         continue;
      }
      // search next MPEG frame header by Frame Length Calculation Method
      // case 1 : search at most 3 bytes
      if ( pParData->wExistFrmSizeTbl[wBitRateIdx] != 0 ) {
         if ((uOffset + pParData->wExistFrmSizeTbl[wBitRateIdx] + 5) >= ByteCnt) {
            wMaxChkLen = (kal_uint32)pParData->wExistFrmSizeTbl[wBitRateIdx]+5;
            AccOffset+=uOffset;
            //AccOffset+=buf_len;
            //preOffset = buf_len - uOffset;
            ByteCnt = 0;
            //memcpy((kal_uint8*)pbHeader ,(kal_uint8*)pbHeader+uOffset ,preOffset*sizeof(kal_uint8));
            uOffset = 0;
            continue;
         }
         uOffset += pParData->wExistFrmSizeTbl[wBitRateIdx] - 1;

         {
            kal_uint32 uCount;
            kal_bool fValid = false;
            for(uCount=0; uCount<6; uCount++) {
               w1 = (uint16)pbHeader[0+uCount+uOffset] | ((uint16)pbHeader[1+uCount+uOffset] << 8);
               w2 = (uint16)pbHeader[2+uCount+uOffset] | ((uint16)pbHeader[3+uCount+uOffset] << 8);
               if(((pParData->wHeader1&0xFEFF) != (w1&0xFEFF)) || ((pParData->wHeader2 & 0x000C) != (w2 & 0x000C)))
                  continue;  // check sync. word, layer, version and sample rate
               if ( dafIsFakeSyncWord(w1, w2) ) {
                  // Failed
               } else {
                  // valid
                  uOffset += uCount;
                  fValid = true;
                  break;
               }
            }//for(uCount=0; uCount<6; uCount++)...
            if (fValid == false) {
               uOffset++;
               uErrorCnt++;
               continue;
            }
         }
      } else {
         // case 2 : search at most 6 bytes
         if ((kal_uint32)(uOffset + pParData->wFrameSizeTbl[wBitRateIdx] + 8) >= ByteCnt) {
            wMaxChkLen = (kal_uint32)pParData->wFrameSizeTbl[wBitRateIdx]+8;
            AccOffset+=uOffset;
            //AccOffset+=buf_len;
            //preOffset = buf_len - uOffset;
            ByteCnt = 0;
            //memcpy((kal_uint8*)pbHeader ,(kal_uint8*)pbHeader+uOffset ,preOffset*sizeof(kal_uint8));
            uOffset = 0;
            continue;
         }
         uOffset += pParData->wFrameSizeTbl[wBitRateIdx];

         {
            kal_uint32 uCount;
            kal_bool fValid = false;
            for (uCount=0; uCount<6; uCount++) {
               w1 = (uint16)pbHeader[0+uCount+uOffset] | ((uint16)pbHeader[1+uCount+uOffset] << 8);
               w2 = (uint16)pbHeader[2+uCount+uOffset] | ((uint16)pbHeader[3+uCount+uOffset] << 8);
               if (((pParData->wHeader1&0xFEFF) != (w1&0xFEFF)) || ((pParData->wHeader2 & 0x000C) != (w2 & 0x000C)))
                  continue;  // check sync. word, layer, version and sample rate
               if ( dafIsFakeSyncWord(w1, w2) ) {
                  // Failed
               } else {
                  // valid
                  uOffset += uCount;
                  fValid = true;
                  pParData->wExistFrmSizeTbl[wBitRateIdx] = pParData->wFrameSizeTbl[wBitRateIdx]+uCount;
                  break;
               }
            }// for(uCount=0; uCount<6; uCount++)...

            if (fValid == false) {
               if(pParData->wFSTblIdx == 2) {
                  uOffset++;
                  uErrorCnt++;
                  continue;
               }
               uOffset -= pParData->wFrameSizeTbl[wBitRateIdx];
               pParData->wFSTblIdx++;
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
   //FSAL_Seek( pParData->pstFSAL, uCurPos);
   if(hdl->rbInfo.rb_base == NULL)
   {
      audio_free_mem( (void **) &pbHeader);
   }
   return ParseResult;
}

/*------------------------------------------------*/
/* The private member functions of DAF parser.    */
/*------------------------------------------------*/
static void DafPar_ReleaseFileHandle(AudComHdlInt *ihdl, kal_uint32 isStreaming) {
   MHdl *medHdl = (MHdl *)ihdl->mhdl;
   DAF_ParData *pParData = (DAF_ParData *)ihdl->pPrivateData;
   
   if (isStreaming) {  
      medHdl->rbInfo.read = pParData->uOffset;
      free_ctrl_buffer(pParData->pstFSAL);
      pParData->pstFSAL = NULL;
      pParData->stFile.pstFSAL = NULL;
   }
}

static void dafPar_ErrorReport(AudComHdlInt *ihdl, kal_uint32 isStreaming)
{
   ihdl->callbacks->EventHandler( (AudComHdl *)ihdl, ihdl->pFWData, OMX_EventError, 0, 0, (void *)0);
   //mhdlException( ihdl->mhdl, MEDIA_ERROR );
   DafPar_ReleaseFileHandle(ihdl, isStreaming);
}

static Media_Status dafFakeData(AudComHdl *hdl)
{  
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   DAF_ParData *pParData = (DAF_ParData *)ihdl->pPrivateData;
   kal_uint32 uChannelNum, uSamplingRate;
   
   uSamplingRate = pParData->strmInfo.sample_rate;
   uChannelNum = pParData->strmInfo.channel_num;
   
   if (!(uChannelNum==1 || uChannelNum==2))
      return MEDIA_BAD_FORMAT;   
        
   if ((uSamplingRate==8000 ) || (uSamplingRate==11025) || (uSamplingRate==12000)) {
      
   } else if ((uSamplingRate==16000) || (uSamplingRate==22050) || (uSamplingRate==24000)) {
      
   } else if ((uSamplingRate==32000) || (uSamplingRate==44100) || (uSamplingRate==48000)) {

   } else {
      return MEDIA_BAD_FORMAT;  
   }
   
   return MEDIA_SUCCESS;
}

static OMX_ERRORTYPE DafPar_Start(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   DAF_ParData *pParData = (DAF_ParData *)ihdl->pPrivateData;
   MHPB_Internal *pPBhdl = (MHPB_Internal *)ihdl->mhdl;
   MHdl *medHdl = (MHdl *)ihdl->mhdl;
   kal_int32 uTblResult, offset;
   kal_uint8 *pbBuf;
   kal_uint32 uBufLen, uOffset, uOriOffset, uFrameDur;
   OMX_ERRORTYPE eResult;
   AST_Status astResult;
   kal_uint32 isStreaming = 0;
   
   ihdl->endStatus = MEDIA_NONE;
   pParData->uOffset = pParData->uHdrOffset = 0;
   ihdl->isEOF = ihdl->Decode_EOF = false;
   
   if (NULL == pParData->pstFSAL) {
      FSAL_Status eFSALStatus;
      if(medHdl->rbInfo.write==0)
      {
         return OMX_ErrorUndefined;
      }
      isStreaming = 1;
      pParData->pstFSAL = (STFSAL*)get_ctrl_buffer( sizeof(STFSAL) );
      pParData->stFile.pstFSAL = pParData->pstFSAL;
      if (pParData->pstFSAL == NULL)
         return OMX_ErrorUndefined;
   
      FSAL_Direct_SetRamFileSize(pParData->pstFSAL, medHdl->rbInfo.write);
      eFSALStatus = FSAL_Open(pParData->pstFSAL, medHdl->rbInfo.rb_base, FSAL_ROMFILE);
      ASSERT(eFSALStatus == FSAL_OK);
   }
   
   astResult = DafParseHeader( medHdl, &uOffset, &uFrameDur);
   if (astResult != AST_SUCCESS) {
      // The string is wrong or unsupport
      if (isStreaming) {
        
         if (medHdl->rbInfo.write < MAX_FRAME_CHECK_LEN) {  
      	    if (MEDIA_SUCCESS != dafFakeData(hdl)) {
               dafPar_ErrorReport(ihdl, isStreaming);
               return OMX_ErrorUndefined;
            }
         } else {
            dafPar_ErrorReport(ihdl, isStreaming);
            return OMX_ErrorUndefined;
         }
      } else {
         dafPar_ErrorReport(ihdl, isStreaming);
         return OMX_ErrorUndefined;
      }
   }
   pParData->uHdrOffset = uOffset;

   // Seek operation
   {
      pPBhdl->frameDur = pParData->frameDur;
      pPBhdl->uOffset = pParData->uOffset;
   }
   
   if (isStreaming) {
      // do nothing
   } else if (ihdl->mhdl->bIsPause && pPBhdl->AudioSeekTbl==NULL) {
      DafSeekWithResume(hdl);
      ihdl->mhdl->bIsPause = KAL_FALSE;
   } else {
      if(!DafSeek(hdl, true))
      {  
         return OMX_ErrorContentEndOfFile;
      }
   }
   
   // Prepare the bitstream
   uOriOffset = uOffset = pParData->uOffset;
   pbBuf = (kal_uint8*)audio_alloc_mem( MAX_FRAME_CHECK_LEN );
   uBufLen = MAX_FRAME_CHECK_LEN;
   eResult = ACU_GetBytesFromFile(pParData->stFile.pstFSAL, &uOffset, &uBufLen, pbBuf);
   // Read Error
   if (OMX_ErrorNone != eResult) {
      audio_free_mem( (void **) &pbBuf );
      return eResult;
   }

   // check the validation of bitstream
   offset = 0;
   uTblResult = MP3FrmLen_GetFrmLenTableInternal((kal_int16 *)pParData->wFrameSizeTbl, &offset, pbBuf, uBufLen, pbBuf);
   audio_free_mem( (void **) &pbBuf );
   if (!uTblResult && !isStreaming) {
      // The string is wrong or unsupport
      ihdl->callbacks->EventHandler(hdl, ihdl->pFWData, OMX_EventError, 0, 0, (void *)0);
      return OMX_ErrorUndefined;
   }
   pParData->uOffset = uOriOffset + offset;

   DafPar_ReleaseFileHandle(ihdl, isStreaming);

   //for resume
   ihdl->bsInfo.uFrameDur = uFrameDur; 
   if(uFrameDur)
   {
      ihdl->bsInfo.uCurrentFrame = (kal_uint32)((kal_uint64)pPBhdl->mh.start_time  * 1000000 / uFrameDur);
   }
   ihdl->bsInfo.uCurrentOffset = pParData->uOffset; 
   ihdl->bsInfo.pResBuf = &pParData->ResBuf; 

   ihdl->mediaStatus = COMPONENT_STATE_PLAY;
   if(pParData->pstFSAL)
   {
      kal_uint32 I;
      kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_START_TIME_OFFSET, MTKAUD_PARSER_DAF, medHdl->start_time, pParData->uOffset,0,0,0,0);
      for (I=0; I<MP3DEC_PARSER_BUFNUM; I++) 
      {
         DafPar_Process_Internal(hdl);
      }
   }
   else
   {
      ACU_SendProcessCommandl( (AudComHdlInt *)hdl );
   }
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE DafPar_Deinit(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   DAF_ParData *pParData = (DAF_ParData *)ihdl->pPrivateData;

   ACU_FlushBufferQueue(hdl);

   // Close file
   if (!pParData->fMedSet)
      FSAL_Close(pParData->stFile.pstFSAL);

   kal_trace( TRACE_FUNC, L1AUDIO_CLOSE, ihdl->mediaType );

   return OMX_ErrorNone;
}

OMX_ERRORTYPE DafPar_Process_Internal(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   DAF_ParData *pParData = (DAF_ParData *)ihdl->pPrivateData;

   if (ihdl->endStatus == MEDIA_TERMINATED)
      return OMX_ErrorNone;

   {
      OMX_BUFFERHEADERTYPE *pBufHdr;
      pBufHdr = ACU_GetBufferHeader(hdl, 1);
      if(pBufHdr)
      {
         pBufHdr->pOutputPortPrivate = &ihdl->bsInfo;
      }
   }
   
   if (pParData->stFile.pstFSAL) {
      OMX_ERRORTYPE result;
      
      result = ACU_FileRead(hdl, pParData->stFile.pstFSAL, &pParData->uOffset);
      
      if (ihdl->isEOF) {
         ihdl->endStatus = MEDIA_TERMINATED;
      }
      
      return result;
   } 
   else 
   {
      MHdl *medhdl = (MHdl *)ihdl->mhdl;  
      kal_uint8 *pBuf;
      kal_uint32 bsLen, i;
      for(i=0;i<2;i++)
      {
         medhdl->GetReadBuffer(medhdl, &pBuf, &bsLen);
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PAR_OK, MTKAUD_PARSER_DAF, ihdl->mhdl->eof, bsLen,pBuf,0,0,0);
         if((ihdl->mhdl->eof||bsLen) && pBuf)
         {
            ACU_PutToBuffer_Threshold(hdl, pBuf, &bsLen, MP3DEC_PARSER_BUFSIZE/8);
            medhdl->ReadDataDone(medhdl, bsLen);
            if(ihdl->isEOF)
            {
               kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_EOF, MTKAUD_PARSER_DAF, 0,0,0,0,0);
            }
         }
      }
   }
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE DafPar_Process(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   DAF_ParData *pParData = (DAF_ParData *)ihdl->pPrivateData;
   MHdl *pMedHdl = (MHdl *)ihdl->mhdl;

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PROCESS, MTKAUD_PARSER_DAF, pMedHdl->waiting, ihdl->Decode_EOF,0,0,0,0);
   if (ihdl->Decode_EOF)
   {
      return OMX_ErrorNone;
   }
   if(pParData->pstFSAL == NULL)
   {
      mhdlRefillAndUpdateVideoBuffer(pMedHdl);
      DafPar_Process_Internal(hdl);
   }
   if(!pMedHdl->waiting && pMedHdl->pStrmStruct==NULL )
   {
      pMedHdl->waiting = KAL_TRUE;
      pMedHdl->handler( pMedHdl, MEDIA_DATA_REQUEST );
   }
   return OMX_ErrorNone;
}


static OMX_ERRORTYPE DafPar_SetParameter(AudComHdl *hdl, OMX_INDEXTYPE index, OMX_PTR pStruct)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   DAF_ParData *pParData = (DAF_ParData *)ihdl->pPrivateData;

   switch (index) {
      case OMX_IndexParamMedFileHandle:
         {
            AcuFileParam *pParam = (AcuFileParam *)pStruct;
         
            pParData->pstFSAL = pParam->pstFSAL;
            pParData->stFile.pstFSAL = pParam->pstFSAL;
            pParData->stFile.pFileInfo = pParam->pFileInfo;
         }
         break;
      case OMX_IndexParamMediaTekSetDafStrmInfo:
         {
            Media_Ext_DAF_strm *daf_param = (Media_Ext_DAF_strm *) pStruct;
            pParData->strmInfo.sample_rate = daf_param->sample_rate;
            pParData->strmInfo.channel_num = daf_param->channel_num;
         }
         break;
      default:
         return OMX_ErrorNotImplemented;
   }

   return OMX_ErrorNone;
}

/*------------------------------------------------*/
/* The public functions of DAF parser.            */
/*------------------------------------------------*/
OMX_U32 DafPar_GetMemSize( void )
{
   OMX_U32 uTempSize, uReqSizeTotal;

   uReqSizeTotal = 0;

   // The memory size for AudComHdlInt
   uTempSize = (sizeof(AudComHdlInt) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;

   // The memory for DAF private data
   uTempSize = (sizeof(DAF_ParData) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;

   return uReqSizeTotal;

}


OMX_ERRORTYPE DafPar_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
)
{
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
   ihdl->mediaType = MEDIA_FORMAT_DAF;

   // Initialize the audio handler as default setting
   ACU_InitHdl(*pHandle, pFWData, pCallback);

   // Overwrite the member functions
   ihdl->basic.Start = DafPar_Start;
   ihdl->basic.Stop = ACU_ParGenStop;
   ihdl->basic.Deinit = DafPar_Deinit;
   ihdl->basic.Process = DafPar_Process;
   ihdl->basic.SetParameter = DafPar_SetParameter;

   // Open file
   {
      // Special case for MED use to set FSAL by SetParameter
      DAF_ParData *pParData = (DAF_ParData *)ihdl->pPrivateData;

      pParData->fMedSet = true;
   }

   return OMX_ErrorNone;
}

#endif
