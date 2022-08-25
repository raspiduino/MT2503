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
 * amr_drv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   AMR/AMR-WB playback driver
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

#if defined(AMR_CODEC)

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "fsal.h"
#include "string.h"
#include "kal_trace.h"
#include "fs_errcode.h"
#include "amr_codec_exp.h"
#include "l1audio.h"
#include "audio_enum.h"
#include "audio_def.h"
#include "media.h"
#include "l1sp_trc.h"
#include "ast.h"
#include "am.h"
#include "MedAdapt.h"
#include "amr_codec.h"

#if defined(AMRWB_DECODE)
#include "awb_codec_exp.h"
#endif

Media_Status AMR_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  )
{
   kal_uint32 file_size=0, byteRate=0, uOffset=0;
   Media_Format uMediaType;

   FSAL_GetFileSize( pstFSAL, &file_size);
   memset(contentInfo, 0, sizeof(audInfoStruct));

   uMediaType = amrChkFileHeader(pstFSAL, &uOffset);
   if(uMediaType != MEDIA_FORMAT_AMR && uMediaType != MEDIA_FORMAT_AMR_WB)
   {
      kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_DESCINFO, MEDIA_FORMAT_AMR, MEDIA_BAD_FORMAT);
      return MEDIA_BAD_FORMAT;
   }

#if defined(AMRWB_DECODE)
   if (MEDIA_FORMAT_AMR_WB == uMediaType ) 
   { 
      contentInfo->sampleRate = 16000;
      file_size -= 9;
   }
   else
#endif
   if (MEDIA_FORMAT_AMR == uMediaType ) 
   { 
      contentInfo->sampleRate = 8000;
      file_size -= 6;
   }

   byteRate = amrGetByteRate(pstFSAL , uMediaType, uOffset);
   contentInfo->bitRate = byteRate*8;
   if (byteRate)
   {
      contentInfo->time = (kal_uint64) file_size * 1000 / (kal_uint64) byteRate;   
   }

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_TOTAL_DUR_META, contentInfo->time);
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_DESCINFO, MEDIA_FORMAT_AMR, MEDIA_SUCCESS);
   return MEDIA_SUCCESS;
}

/*
Media_Status AMR_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param )
{
   return autGetMetaData( filename, pbBuf, uSize, contentInfo, param, AMR_GetContentDescInfo );
}
*/

void amrMedSetCacheTbl( MHdl *hdl, kal_uint8 *ptr, kal_uint32 usize )
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   /* make sure 4-byte alignment */
   ASSERT(((uint32)ptr & 0x03) == 0 );
   ihdl->AudioSeekTbl = (AudioSeekTable *)ptr;

   if(ihdl->AudioSeekTbl->CurrentIndex==0)
   {
      AST_InitTable(ihdl->AudioSeekTbl,AMR_AST_MIN_ENTRY_SIZE,usize,amrParseFrame,amrParseFileHeader);
   }
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_SET_AST, hdl, ptr, usize);
}


static Media_Status amrMedPlay( MHdl *hdl )
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   OMX_ERRORTYPE uStatus = OMX_ErrorNone;
   kal_uint32 uChannelNum = 1;
#if defined(__AUDIO_NOT_SUPPORTED__)
   return MEDIA_FAIL;
#endif
   PcmSink_TerminateSound();

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY, hdl->mediaType, hdl->state, 0,0,0,0,0);
   hdl->eof = KAL_FALSE;
   hdl->waiting = KAL_FALSE;
   hdl->isUnderflow = KAL_FALSE;   
   ihdl->endflag = KAL_FALSE;    
     
   {
      // Start component
      AMR_FrameInfo Par_prarm;
      mhdlRefillAndUpdateVideoBuffer(hdl); //call this function, if video eof, hdl->eof will be set. 
      hdl->state = COMPONENT_STATE_PLAY;

      uStatus = ihdl->ParNode.curHdl->Start(ihdl->ParNode.curHdl);
      if(OMX_ErrorContentEndOfFile == uStatus || (OMX_ErrorNone != uStatus && hdl->eof) )
      {
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 0,MEDIA_SEEK_EOF,0,0,0,0);
         return MEDIA_SEEK_EOF;
      }
      else if(OMX_ErrorNone != uStatus)
      {
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 1,MEDIA_ERROR,0,0,0,0);
         return MEDIA_FAIL;
      }

      if(OMX_ErrorNone != ihdl->ParNode.curHdl->SetParameter(ihdl->ParNode.curHdl, OMX_IndexParamAudioAmr, &Par_prarm))
      {
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 2,MEDIA_ERROR,0,0,0,0);
         return MEDIA_FAIL;
      }

      if(OMX_ErrorNone != ihdl->DecNode.curHdl->SetParameter(ihdl->DecNode.curHdl, OMX_IndexParamAudioAmr, &Par_prarm))
      {
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 3,MEDIA_ERROR,0,0,0,0);
         return MEDIA_FAIL;
      }

      if(OMX_ErrorNone != ihdl->DecNode.curHdl->Start(ihdl->DecNode.curHdl))
      {
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 4,MEDIA_ERROR,0,0,0,0);
         return MEDIA_FAIL;
      }
#if AMR_DSP_COMP
//data from PCM route = stereo      
      uChannelNum = 2;
#endif
      if( OMX_ErrorNone != AudioDrain_Start(ihdl, Par_prarm.uSampleRate, uChannelNum))
      {
         if(ihdl->mh.eof)
         {
            kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 5,MEDIA_SEEK_EOF,0,0,0,0);
            return MEDIA_SEEK_EOF;
         }
         else
         {
            kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 6,MEDIA_ERROR,0,0,0,0);
            return MEDIA_FAIL;
         }
      }
   }
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_SUCCESS, hdl->mediaType, hdl->state, 0,0,0,0,0);
   return MEDIA_SUCCESS;
}

static Media_Event amrMedProcess( MHdl *hdl, Media_Event event )
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PROCESS, hdl->mediaType, hdl, event, hdl->state, hdl->eof,0,0,0);
   switch(event) {
      case MEDIA_READY_TO_PLAY:
         return event;
      case MEDIA_END:
      case MEDIA_STOP_TIME_UP:
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
      {
         kal_uint32 I;
         if(ihdl->pstFSAL)
         {
            OMX_ERRORTYPE result;
            
            for (I=0; I<AMRDEC_PARSER_BUFNUM; I++)
            {
               result = AmrPar_Process_Internal(ihdl->ParNode.curHdl);
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
      }
      default:
         ASSERT(0);
   }
   return event;
}


static const MHPB_CompList AmrDecFuncArray[2] = {
   {AmrPar_GetMemSize, AmrPar_Init, AMRDEC_PARSER_BUFSIZE, AMRDEC_PARSER_BUFNUM},
   {AmrDec_GetMemSize, AmrDec_Init, AMRDEC_DECODER_BUFSIZE, AMRDEC_DECODER_BUFNUM}
};

MHdl *AMR_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param)
{
   MHdl *hdl;
   Media_VM_PCM_Param *amr_param = (Media_VM_PCM_Param *) param;
   
   if (handler == NULL) 
   {
      MHPB_CompList const *pArray[1] = {NULL};
      
      hdl = MH_Component_List_Open(handler, pstFSAL, pArray);
   } else {
      hdl = MH_Component_Open(handler, pstFSAL, &AmrDecFuncArray[0], &AmrDecFuncArray[1]);
   }

   hdl->mediaType = MEDIA_FORMAT_AMR;
   if(amr_param->mediaType == MEDIA_FORMAT_AMR_WB || amr_param->mediaType == MEDIA_FORMAT_MP4_AMR_WB)
   {
      hdl->mediaType = MEDIA_FORMAT_AMR_WB;
   }
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_OPEN, hdl->mediaType, hdl, handler,0,0,0,0);

   hdl->Play    = amrMedPlay;
   hdl->Process = amrMedProcess;

   hdl->SetCacheTbl      = amrMedSetCacheTbl;
   hdl->BuildCache       = AudAstBuildCache;
   hdl->GetCacheDuration = AudAstGetCacheDur;
   hdl->GetTotalDuration = AudAstGetTotalDuration;

   if (handler != NULL) {
#if defined (AMR_DSP_COMP)
      {
      	 AMR_FrameInfo DecParm;
      	 MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
      	 
      	 DecParm.vm = amr_param->vmParam;
         ihdl->DecNode.curHdl->SetParameter(ihdl->DecNode.curHdl, OMX_IndexParamMediaTekAudioVm, &DecParm);
      }
#endif
   }

   return hdl;
}

#endif   // #if defined(AMR_CODEC)

