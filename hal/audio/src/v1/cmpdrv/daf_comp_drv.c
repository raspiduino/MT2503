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
 * daf_comp_drv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   DAF playback driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifdef DAF_DECODE

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "string.h"                        
#include "fs_errcode.h" 
#include "fsal.h"
    
#include "l1audio.h"    
#include "audio_enum.h"                                   
#include "am.h"                                                                      
#include "ast.h"                                              
#include "media.h"
#include "afe.h"
#include "l1sp_trc.h"
#include "daf_drv.h"
#include "MedAdapt.h"
#include "DAF_codec.h"
#include "AudCom.h"
#include "AudComUtil.h"
#include "OMX_Index.h"
#include "postprocess.h"
#include "audio_def.h"
#include "dpmgr.h"

// If there are consecutive frame error, driver stops the playback
// The suggest value is 25.
// 0: means that we don't enable the check
#define ERROR_FRAME_THRESHOLD     0

#ifdef MUSICAM_DECODE
const uint16 DAF_BIT_RATE_TABLE_L2_V1[15]={1, 32, 48, 56, 64, 80, 96, 112,
                                            128, 160, 192, 224, 256, 320, 384};
#endif // #ifdef MUSICAM_DECODE

const uint16 DAF_BIT_RATE_TABLE_V1[15]={1, 32, 40, 48, 56, 64, 80, 96, 112,
                                            128, 160, 192, 224, 256, 320};
const uint16 DAF_BIT_RATE_TABLE_V2[15]={1, 8, 16, 24, 32, 40, 48, 56, 64, 80,
                                            96, 112, 128, 144, 160};

kal_bool dafGetBitRateIdx(uint16 wFHdrW1, uint16 wFHdrW2, int16* wBitRateIdx)
{
   kal_uint16 MPEGver;
   kal_int32  bit_rate_idx;

#ifdef MUSICAM_DECODE
   kal_uint16 layer;
   layer = (wFHdrW1>>9) & 3;
#endif // #ifdef MUSICAM_DECODE

   MPEGver = (wFHdrW1>>11) & 3;         /* check MPEG audio version ID */

#ifdef MUSICAM_DECODE
   if(layer == 1){ // Layer III
#endif // #ifdef MUSICAM_DECODE
   /* check bit rate */
   if( MPEGver == 3 ){                          /* MPEG1 */
      bit_rate_idx = (wFHdrW2 >> 4) & 0x0F;
   }else{                                    /* MPEG2, MPEG2.5 */
      bit_rate_idx = (wFHdrW2 >> 4) & 0x0F;
    }
#ifdef MUSICAM_DECODE
   }else if(layer == 2){ // Layer II
      if( MPEGver == 3 )                          /* MPEG1 */
         bit_rate_idx = (wFHdrW2 >> 4) & 0x0F;
      else
         bit_rate_idx = (wFHdrW2 >> 4) & 0x0F;
   }else{
      return false;
   }
#endif // #ifdef MUSICAM_DECODE

   *wBitRateIdx = bit_rate_idx;

   return true;
}

void dafUpdateInfo(dafMediaHdl *ihdl, uint16 wFHdrW1, uint16 wFHdrW2)
{
   kal_uint16 MPEGver;
   kal_int32  sample_rate_idx;

#ifdef MUSICAM_DECODE
   kal_uint16 layer;
   layer = (wFHdrW1>>9) & 3;
#endif // #ifdef MUSICAM_DECODE

   MPEGver = (wFHdrW1>>11) & 3;         /* check MPEG audio version ID */
   sample_rate_idx = (wFHdrW2 >> 2) & 3;    /* sampling rate frequency index */

   /* check sampling rate */
   ihdl->uSampleRate = dafGetSamplingRate(MPEGver, sample_rate_idx);

#ifdef MUSICAM_DECODE
   if(layer == 1){ // Layer III
#endif // #ifdef MUSICAM_DECODE
      /* check bit rate */
      if( MPEGver == 3 ){                          /* MPEG1 */
         ihdl->uSamplesPerFrame = 1152;
      }else{                                    /* MPEG2, MPEG2.5 */
         ihdl->uSamplesPerFrame = 576;
       }
      ihdl->uMLayer = 3;
#ifdef MUSICAM_DECODE
   }else if(layer == 2){ // Layer II
       ihdl->uSamplesPerFrame = 1152;
       ihdl->uMLayer = 2;
   }
#endif // #ifdef MUSICAM_DECODE

   ihdl->frameDur = ihdl->uSamplesPerFrame * 1000000000 / (kal_uint64) ihdl->uSampleRate;
}

static void dafGetInfo(kal_uint16 wFHdrW1, kal_uint16 wFHdrW2, audInfoStruct *contentInfo)
{
   kal_uint16 MPEGver;
   kal_int32  srIdx;

#ifdef MUSICAM_DECODE
   kal_uint16 layer;
   layer = (wFHdrW1>>9) & 3;
#endif // #ifdef MUSICAM_DECODE

   MPEGver = (wFHdrW1>>11) & 3;         /* check MPEG audio version ID */
   srIdx = (wFHdrW2 >> 2) & 3;          /* sampling rate frequency index */

   /* sampling rate */
   contentInfo->sampleRate = dafGetSamplingRate( MPEGver, srIdx);

   /* bit rate */
   if( MPEGver == 3 ){                          /* MPEG1 */
      contentInfo->bitRate = DAF_BIT_RATE_TABLE_V1[(wFHdrW2 >> 4) & 0x0F] * 1000;

#ifdef MUSICAM_DECODE
   }else{                                    /* MPEG2, MPEG2.5 */
      contentInfo->bitRate = DAF_BIT_RATE_TABLE_V2[(wFHdrW2 >> 4) & 0x0F] * 1000;
    }

   /* bit rate */
   if( MPEGver == 3 ){                          /* MPEG1 */
      if(layer == 1) // Layer III
         contentInfo->bitRate = DAF_BIT_RATE_TABLE_V1[(wFHdrW2 >> 4) & 0x0F] * 1000;
      else
         contentInfo->bitRate = DAF_BIT_RATE_TABLE_L2_V1[(wFHdrW2 >> 4) & 0x0F] * 1000;
#endif // #ifdef MUSICAM_DECODE

   }else{                                    /* MPEG2, MPEG2.5 */
      contentInfo->bitRate = DAF_BIT_RATE_TABLE_V2[(wFHdrW2 >> 4) & 0x0F] * 1000;
    }

   contentInfo->details.DAF.bit_rate_index = (kal_uint8)((wFHdrW2 >> 4) & 0x0F);
   contentInfo->details.DAF.CRC = (kal_uint8)((wFHdrW1>>8) & 1);
   contentInfo->details.DAF.channel_mode = (kal_uint8)((wFHdrW2 >> 14) & 0x3);
   if(((wFHdrW2 >> 14) & 0x3) == 0x03) // stereo indicator
      contentInfo->stereo = false;
   else
      contentInfo->stereo = true;
}

static kal_uint32 dafGetDur( dafMediaHdl* ihdl, uint32 bitRate )
{
   kal_uint32 file_size, time;
   FSAL_GetFileSize(ihdl->pstFSAL, &file_size);
   
   if (file_size >= ihdl->uID3V2Size)
      file_size -= ihdl->uID3V2Size;
   else
      file_size = 0;
   
   if(bitRate)
      time = (kal_uint64)file_size * 8000 / (kal_uint64)bitRate;
   else
      time = 0;

   return time;
}
#if defined XING_SUPPORT
static int ExtractI4(unsigned char *buf)
{
   int x;
   // big endian extract
   x = buf[0];
   x <<= 8;
   x |= buf[1];
   x <<= 8;
   x |= buf[2];
   x <<= 8;
   x |= buf[3];

   return x;
}

static int GetXingHeader(XHEADDATA *Xing,  kal_uint8 *data_buf)
{
   int i, head_f;
   int id, mode, sr_idx;
   static const int samplerate_table[4] = { 44100, 48000, 32000, 99999 };

   Xing->flags = 0;     

   id       = (data_buf[1] >> 3) & 1;
   sr_idx   = (data_buf[2] >> 2) & 3;
   mode     = (data_buf[3] >> 6) & 3;

   
   if( id ) {        
       if( mode != 3 )   data_buf+= 36;
       else              data_buf+= 21;
   }
   else {      
       if( mode != 3 )   data_buf+= 21;
       else              data_buf+= 13;
   }

   if( data_buf[0] != 'X' ) return 0;    
   if( data_buf[1] != 'i' ) return 0;    
   if( data_buf[2] != 'n' ) return 0;
   if( data_buf[3] != 'g' ) return 0;
   data_buf+=4;

   Xing->h_id = id;
   Xing->samprate = samplerate_table[sr_idx];
   if( id == 0 ) 
   	  Xing->samprate >>= 1;

   head_f = Xing->flags = ExtractI4(data_buf); 
   data_buf+=4;      

   if( head_f & FRAMES_FLAG ) {
   	   Xing->frames= ExtractI4(data_buf); 
   	   data_buf+=4;
   }
   if( head_f & BYTES_FLAG )  {
   	   Xing->bytes = ExtractI4(data_buf); 
   	   data_buf+=4;
   }

   if( head_f & TOC_FLAG ) {
       if( Xing->toc != NULL ) {
           for(i=0;i<100;i++) { 
               Xing->toc[i] = data_buf[i];
           }
       }
       data_buf+=100;
   }
   
   Xing->vbr_scale = -1;
   if( head_f & VBR_SCALE_FLAG )  {
   	   Xing->vbr_scale = ExtractI4(data_buf); 
   	   data_buf+=4;
   }
   
   return 1;       // success
}
#endif // #if defined XING_SUPPORT
Media_Status DAF_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  )
{
   dafMediaHdl *ihdl;
   kal_uint16 headerFstWd, headerSndWd;

   ihdl = (dafMediaHdl *)audio_alloc_mem( sizeof(dafMediaHdl) );
   if(ihdl==NULL)
   {
      return MEDIA_FAIL;
   }
   mhdlInitEx( ( MHdl *)ihdl, 0xFFFF , NULL );
   ihdl->pstFSAL = pstFSAL;

   memset(contentInfo, 0, sizeof(audInfoStruct));

   autSkipID3Tag((MHdl *) ihdl, ihdl->pstFSAL, &ihdl->fileOffset, &ihdl->buf[0] );
   ihdl->uID3V2Size = ihdl->fileOffset;

   if ( dafReachNextFrame(ihdl, &headerFstWd, &headerSndWd, 0) == KAL_FALSE ){
      audio_free_mem( (void **) &ihdl );  
      return MEDIA_BAD_FORMAT;
   }

   dafUpdateInfo(ihdl, headerFstWd, headerSndWd);
#if defined XING_SUPPORT
   if(autGetBytesFromFileNoEnd((MHdl*)ihdl, ihdl->pstFSAL, ihdl->fileOffset, 512, &ihdl->buf[0]) == 512){
		ihdl->fXing = (kal_bool) GetXingHeader(&ihdl->stXing,  &ihdl->buf[0]);
	}
#endif // #if defined XING_SUPPORT
   dafGetInfo(headerFstWd, headerSndWd, contentInfo);
#if defined XING_SUPPORT
   if(ihdl->fXing && ihdl->stXing.frames){
      if((contentInfo->sampleRate == 44100) || (contentInfo->sampleRate == 48000) || (contentInfo->sampleRate == 32000))
         contentInfo->time = (kal_int64)ihdl->stXing.frames * 1152000 / contentInfo->sampleRate;
      else
         contentInfo->time = (kal_int64)ihdl->stXing.frames * 576000 / contentInfo->sampleRate;
   }else
#endif // #if defined XING_SUPPORT
      contentInfo->time = dafGetDur(ihdl, contentInfo->bitRate);

   audio_free_mem( (void **) &ihdl );  
   kal_trace( TRACE_FUNC, L1AUDIO_CONTENT, MEDIA_FORMAT_DAF );

   return MEDIA_SUCCESS;
}

// For component

static Media_Status DafMedReachValidRegion( MHdl *hdl )
{
   kal_uint32 uFirstFrameOffset, uFrameDur;
   if(AST_SUCCESS != DafParseHeader(hdl, &uFirstFrameOffset, &uFrameDur))
   {
      return MEDIA_FILE_INCOMPLETE;
   }
   return MEDIA_SUCCESS;
}

static Media_Event dafMedProcess( MHdl *hdl, Media_Event event )
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   AudComHdl *pParHdl = ihdl->NodeArray[0].curHdl;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PROCESS, hdl->mediaType, hdl, event, hdl->state, hdl->eof,0,0,0);
   
   switch(event) {
      case MEDIA_READY_TO_PLAY:
         return event;
      case MEDIA_END:
      case MEDIA_STOP_TIME_UP:
         Media_A2V_NOTIFY_MEDIA_END(GenCompStop, hdl);
         break;
      case MEDIA_ERROR:
         GenCompStop(hdl);
         break;
      case MEDIA_DATA_REQUEST:
      case MEDIA_BUFFER_UNDERFLOW:
      {
         kal_uint32 I;
         OMX_ERRORTYPE result;
            
         if (ihdl->pstFSAL) 
         {
            OMX_BUFFERHEADERTYPE *pBufHdr;
            AudComHdlInt *iParHdl = (AudComHdlInt *)pParHdl;
               
            do 
            {
               result = DafPar_Process_Internal(pParHdl);
               if (result != OMX_ErrorNone) 
               {
                  return MEDIA_READ_ERROR;
               }
               pBufHdr = ACU_GetBufferHeader(pParHdl, 1);
            } while ((pBufHdr != NULL) && !(iParHdl->isEOF));
         }
         else
         {
            ACU_SendProcessCommandl((AudComHdlInt *)pParHdl);
         }
         if(!(hdl->pStrmStruct== NULL && ihdl->pstFSAL==NULL))
         {
            hdl->FinishWriteData(hdl);
         }
         if (ihdl->pstFSAL) 
         {
            return MEDIA_NONE;
         }
         break;
      }
      default:
         // should never reach here
         ASSERT(0);
   }
   
   return event;
}

static Media_Status DafMedPlay( MHdl *hdl )
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   SinkParam Sink_param;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY, hdl->mediaType, hdl->state, hdl->GetDataCount(hdl),0,0,0,0);
#if defined(__AUDIO_NOT_SUPPORTED__)
   return MEDIA_FAIL;
#endif
   PcmSink_TerminateSound();
   // Change status
   hdl->eof = KAL_FALSE;
   hdl->waiting = KAL_FALSE;
   ihdl->endflag = KAL_FALSE;

   KT_StopAndWait();
   TONE_StopAndWait();

   mhdlRefillAndUpdateVideoBuffer(hdl); //call this function, if video eof, hdl->eof will be set. 
   hdl->state = COMPONENT_STATE_PLAY;
   
   // Load code
   ihdl->region = DPMGR_MP3;
   DPMGR_Load(DPMGR_MP3);
   
   if (OMX_ErrorNone != ihdl->ParNode.curHdl->Start(ihdl->ParNode.curHdl)) {
      // Unload code
      DPMGR_Unload(DPMGR_MP3);
      ihdl->region = DPMGR_NOT_MATCH;
      
      if(ihdl->mh.eof || ihdl->mh.start_time)
      {
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 0,MEDIA_SEEK_EOF,0,0,0,0);
         return MEDIA_SEEK_EOF;
      }
      else
      {
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 1,MEDIA_FAIL,0,0,0,0);
         return MEDIA_FAIL;
      }
   }

   Media_SetAudioFormat(MEDIA_FORMAT_DAF);

   ihdl->DecNode.curHdl->Start(ihdl->DecNode.curHdl);
   ihdl->DecNode.curHdl->SetParameter(ihdl->DecNode.curHdl, OMX_IndexParamMediaTekPcmSink, &Sink_param);

   if ( OMX_ErrorNone != AudioDrain_Start(ihdl, Sink_param.uSamplingFreq, Sink_param.uChannelNum)) {
      if (ihdl->mh.eof) {
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 6,MEDIA_SEEK_EOF,0,0,0,0);
         return MEDIA_SEEK_EOF;
      } else {
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 7,MEDIA_FAIL,0,0,0,0);
         return MEDIA_FAIL;
      }
   }

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_SUCCESS, hdl->mediaType, hdl->state, hdl->GetDataCount(hdl),0,0,0,0);
   return MEDIA_SUCCESS;
}


static const MHPB_CompList DafDecFuncArray[2] = {
   {DafPar_GetMemSize, DafPar_Init, MP3DEC_PARSER_BUFSIZE, MP3DEC_PARSER_BUFNUM},
   {DafDec_GetMemSize, DafDec_Init, MP3DEC_DECODER_BUFSIZE, MP3DEC_DECODER_BUFNUM}
};
static const MHPB_CompList DafParOnlyFunc = {
   DafPar_GetMemSize, DafPar_Init, MP3DEC_PARSER_BUFSIZE, 0
};

MHdl *DAF_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param)
{
   MHdl *hdl;
   
   if (handler == NULL) {
      MHPB_CompList const *pArray[2] = {&DafParOnlyFunc, NULL};
      
      hdl = MH_Component_List_Open(handler, pstFSAL, pArray);
   } else {
      // Load code
      DPMGR_Load(DPMGR_MP3);
      
      hdl = MH_Component_Open(handler, pstFSAL, &DafDecFuncArray[0], &DafDecFuncArray[1]);
      
      // Unload code
      DPMGR_Unload(DPMGR_MP3);
   }
   
   hdl->mediaType = MEDIA_FORMAT_DAF;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_OPEN, hdl->mediaType, hdl, handler,0,0,0,0);

   
   hdl->Process          = dafMedProcess;
   hdl->BuildCache       = AudAstBuildCache;
   hdl->GetCacheDuration = AudAstGetCacheDur;
   hdl->SetCacheTbl      = DafAstSetCacheTbl;
   hdl->GetTotalDuration = AudAstGetTotalDuration;
   hdl->ReachValidRegion = DafMedReachValidRegion;
   hdl->Play = DafMedPlay;
   
   // Set Parameter to component
   {
      MHPB_Internal *ihdl;
      AcuFileParam parseInfo;
      
      ihdl = (MHPB_Internal *)hdl;
      
      // For streaming parser
      if (pstFSAL == NULL) {
         ihdl->NodeArray[0].curHdl->SetParameter(ihdl->NodeArray[0].curHdl, OMX_IndexParamMediaTekSetDafStrmInfo, (OMX_PTR)param);
      }
      
      ihdl->ParseFrame = DafParseFrame;
      ihdl->ParseHeader = DafParseHeader;
   }
   
   return hdl;
}

#endif // DAF_DECODE
