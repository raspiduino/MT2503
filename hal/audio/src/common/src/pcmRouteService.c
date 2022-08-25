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
 *   pcmRouteService.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   To provide service for PCM Route.
 *   Get the decoded PCM from DSP, and put the processed PCM to DSP.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "string.h"
#include "reg_base.h"
#include "l1audio.h"
#include "audio_def.h"
#include "media.h"
#include "AudCom.h"
#include "OMX_Core.h"
#include "OMX_Types.h"
#include "kal_trace.h"
#include "am.h"
#include "AudComUtil.h"
#include "l1sp_trc.h"
#include "audio_sherif_bit_def.h"
#include "pcmsink.h"
#if defined(__VIBRATION_SPEAKER_SUPPORT__)   
#include "vibration_def.h"
#endif 

#define PCMRUT_MASK       0x0080
#define PCMRUT_ON         0x0081

#define PCMRUT_MAX_BUF_SIZE 8192 //4096

#define BUFFERING_NUMBER 4608
#define BUFFERING_NUMBER_AACPLUS 9216
#define PCMRUT_ENDING_MUTE_TICK  20

// The structure of PCM Route
static struct {
   // PCM Route information from DSP
   kal_uint16 bufAddr;

   kal_uint16 uBufHead1;
   kal_uint16 uBufHead2;
   kal_uint16 uBufEnd1;
   kal_uint16 uBufEnd2;

   kal_uint16 pageNum;
   kal_uint16 dataLen_put;
   kal_uint16 dataLen_get;
   kal_uint16 channelNum;
   
   // For buffering sample
   kal_uint32 bufferingSample;
   kal_bool   fPreBuffering;
   kal_bool   fFirstPut;
   kal_bool   isEOF;
   kal_bool   fMute;

   // audio ID
   void       (*pHisrCallback)( void );
   kal_uint16 uAudId;
   kal_uint16 uCurWrite;
   kal_uint16 uPcmSegment;
   kal_uint8  uIntNumberPerFrame;
   kal_bool   fIsSoundPlaying;
   kal_bool   fIsHisrEnabled;
   kal_bool   fIsAAC;
   kal_bool   fIsReadOnly;
} pcmRut;

/*---------------------------------*/
/* Implementation for application. */
/*---------------------------------*/
static struct {
   AudComHdl *pDecoder;
   AudComHdl *pSink;
   kal_uint16 *tempBuf;
} pcmRutComponent;

kal_bool Is_PutPcmrutOn(void)
{
   if(pcmRut.pHisrCallback)
   {
      return KAL_TRUE;
   }
   return KAL_FALSE;
}

kal_bool PcmRut_IsStereo2Mono(void)
{
#if defined(__BES_TS_SUPPORT__)
   if(AudioPP_TS_GetSpeed()!=0 && Media_IsDSPDec())
   {
      return KAL_TRUE;
   }
#endif
  return KAL_FALSE;
}

static kal_uint16 pcmrut_GetPcmBufferSize(void)
{
   Media_Format uFormat = Media_GetAudioFormat();
   switch(uFormat)
   {
      case MEDIA_FORMAT_AAC:
      case MEDIA_FORMAT_AAC_PLUS:
      case MEDIA_FORMAT_AAC_PLUS_V2:
         return ASP_FRAMELEN_AAC;
      case MEDIA_FORMAT_AMR:
         return ASP_FRAMELEN_AMR;
      case MEDIA_FORMAT_AMR_WB:
         return ASP_FRAMELEN_AWB ;
      default: 
         return ASP_DELM_I2SBypass;
   }
   return 0;
}

static kal_uint16 pcmrut_GetPcmBufferBase(void)
{
   Media_Format uFormat = Media_GetAudioFormat();
   switch(uFormat)
   {
      case MEDIA_FORMAT_AAC:
      case MEDIA_FORMAT_AAC_PLUS:
      case MEDIA_FORMAT_AAC_PLUS_V2:
         return ASP_DSP_PCM_BUFFER_BASE_AAC;
      case MEDIA_FORMAT_AMR:
         return ASP_DSP_PCM_BUFFER_BASE_AMR;
      case MEDIA_FORMAT_AMR_WB:
         return ASP_DSP_PCM_BUFFER_BASE_AWB;
      default: 
         return ASP_DSP_PCM_BUFFER_BASE_I2S;
   }
}

static void PcmRut_GetInfo( kal_uint32 *numSample_get, kal_uint32 *numSample_put)
{
   *numSample_get = pcmRut.dataLen_get;
   *numSample_put = pcmRut.dataLen_put;
}

static void PcmRut_GetData( kal_uint16 *pSampleBuf)
{
   kal_uint32 count;
   volatile uint16* idmaPtr;
   
   count = pcmRut.dataLen_get;

   if(pcmRut.fMute)
   {
      memset((kal_uint8*)pSampleBuf, 0, count<<1);
      return;
   }
      
   idmaPtr = DSP_DM_ADDR(pcmRut.pageNum, pcmRut.bufAddr);
   IDMA_ReadFromDSP((uint16 *)pSampleBuf, idmaPtr, count);
}

static void PcmRut_PutData( kal_uint16 *pSampleBuf )
{
   volatile uint16 *idmaPtr;
   kal_uint32 count;
   int i;
   if(!pcmRut.fIsReadOnly)
   {
   count = pcmRut.dataLen_put;
   idmaPtr = DSP_DM_ADDR(pcmRut.pageNum, pcmRut.bufAddr);
   
#if defined(__VIBRATION_SPEAKER_SUPPORT__)   
    if(AFE_IsAudioLoudSpk())
    {
        kal_uint32 smpl_rate_val = Media_GetSampleRate();
        kal_uint32 smpl_rate_idx = Media_GetSamplingRateIndex(smpl_rate_val);
        kal_int32 is_stereo = 1;
        kal_int32 buffer_size_in_bytes = pcmRut.dataLen_put << 1;
        Vibration_Notch_Filter_16Bit(pSampleBuf, pSampleBuf, is_stereo, buffer_size_in_bytes, (kal_int32 *)&Vibr_Filter_Stack_Auddata[0][0], (kal_uint32 *)&VIBR_NVRAM_DATA.VIBR_NVRAM_LOUD_FILTER_COEF[0][smpl_rate_idx][0]);
        Vibration_Notch_Filter_16Bit(pSampleBuf, pSampleBuf, is_stereo, buffer_size_in_bytes, (kal_int32 *)&Vibr_Filter_Stack_Auddata[1][0], (kal_uint32 *)&VIBR_NVRAM_DATA.VIBR_NVRAM_LOUD_FILTER_COEF[1][smpl_rate_idx][0]);
    }
#endif 
   
   if(PcmRut_IsStereo2Mono())
   {
      for (i=count-1; i>=0; i--)
      {
         kal_int32 temp_data = (kal_int16)*pSampleBuf++;
         temp_data += (kal_int16)*pSampleBuf++;
         *idmaPtr++ = (kal_uint16)(temp_data>>1);
      }   
   } 
   else
   {
      for (i=count-1; i>=0; i--)
      {
         *idmaPtr++ = *pSampleBuf++;
      }
   }
   }
   if (pcmRut.fFirstPut) 
   {
      PcmSink_Mute(KAL_FALSE, PCMSINK_MUTE_PCMRUT);
      pcmRut.fFirstPut = KAL_FALSE;
   }
}

static void PcmRut_PutData_Silence( void )
{
   volatile uint16 *idmaPtr;
   kal_uint32 count;
   int i;
   if(!pcmRut.fIsReadOnly)
   {
   kal_brief_trace( TRACE_GROUP_PLAYBACK_COMPONENT, PCMRUT_PUTSILENCE, pcmRut.dataLen_put, pcmRutComponent.pSink);
   
   count = pcmRut.dataLen_put;
   idmaPtr = DSP_DM_ADDR(pcmRut.pageNum, pcmRut.bufAddr);
   for (i=count-1; i>=0; i--)
      *idmaPtr++ = 0;
   }
}

static void PcmRut_ApmCallback( void ) // excuted in HISR
{
   kal_uint32 numFrameSample_get;
   kal_uint32 numFrameSample_put;
   AudComHdlInt *pDecComp;
   // Get sample information
   PcmRut_GetInfo(&numFrameSample_get, &numFrameSample_put);
   
   // Handle Get Data
   if (pcmRutComponent.pDecoder) {
      OMX_BUFFERHEADERTYPE *pCurrOutput;
      kal_uint32 freeLen, freeLen2;
      
      pDecComp = (AudComHdlInt *)pcmRutComponent.pDecoder;
      pCurrOutput = ACU_GetBufferHeader(pcmRutComponent.pDecoder, 1);

      if (pCurrOutput) 
      {
         if (!pDecComp->isDspDecodeEOF)
            pCurrOutput->nFlags &= ~OMX_BUFFERFLAG_EOS;
         
         // Get free space
         freeLen = pCurrOutput->nAllocLen - (pCurrOutput->nOffset + pCurrOutput->nFilledLen);
         if (freeLen >= numFrameSample_get *2) {
            // Free buffer is enough
            PcmRut_GetData((kal_uint16 *)(pCurrOutput->pBuffer + pCurrOutput->nOffset + pCurrOutput->nFilledLen));
            ACU_WriteDataDone_ImmediateCallback((AudComHdl *)pDecComp, numFrameSample_get*2);
            kal_brief_trace( TRACE_GROUP_PLAYBACK_COMPONENT, PCMRUT_GETDATA, numFrameSample_get*2);
         } else {
            // Free buffer isn't enough
            PcmRut_GetData(pcmRutComponent.tempBuf);
            memcpy(pCurrOutput->pBuffer + pCurrOutput->nOffset + pCurrOutput->nFilledLen, (kal_uint8 *)pcmRutComponent.tempBuf, freeLen);
            ACU_WriteDataDone((AudComHdl *)pDecComp, freeLen);
            kal_brief_trace( TRACE_GROUP_PLAYBACK_COMPONENT, PCMRUT_GETDATA, freeLen);

            pCurrOutput = ACU_GetBufferHeader(pcmRutComponent.pDecoder, 1);
            if (pCurrOutput) {
               // Get free space
               freeLen2 = pCurrOutput->nAllocLen - (pCurrOutput->nOffset + pCurrOutput->nFilledLen);
               ASSERT(freeLen2 > (numFrameSample_get*2 - freeLen));
               memcpy(pCurrOutput->pBuffer + pCurrOutput->nFilledLen, ((kal_uint8 *)pcmRutComponent.tempBuf)+freeLen, (numFrameSample_get*2 - freeLen));
               ACU_WriteDataDone_ImmediateCallback((AudComHdl *)pDecComp, numFrameSample_get*2 - freeLen);
            } else {
               // Buffer overflow
            }
         }
      }
   }
   
   // Handle Put Data
   if (pcmRutComponent.pSink) {
      OMX_U8 *pReadBuf;
      OMX_U32 uReadSize8;
      AudComHdlInt *pSinkComp; 
      kal_uint32 numFrameSample;
      pSinkComp = (AudComHdlInt *)pcmRutComponent.pSink; 
      
      if(PcmRut_IsStereo2Mono())
         numFrameSample = numFrameSample_put*2;
      else
         numFrameSample = numFrameSample_put;
      
      if (pcmRut.fPreBuffering) 
      {
         kal_uint32 threshold = BUFFERING_NUMBER;
         if ( MEDIA_FORMAT_AAC_PLUS == Media_GetAudioFormat() )
            threshold = BUFFERING_NUMBER_AACPLUS;
         
         pcmRut.bufferingSample += numFrameSample_put;
         if (pcmRut.bufferingSample >= threshold) 
         {
            pcmRut.fPreBuffering = KAL_FALSE;
            pcmRut.fFirstPut = KAL_TRUE;
         }
         PcmRut_PutData_Silence();
         return;
      }

      ACU_GetReadBuffer(pcmRutComponent.pSink, &pReadBuf, &uReadSize8);
      if (!pReadBuf) 
      {
         // No data
         PcmRut_PutData_Silence();
      } 
      else 
      {
         if (uReadSize8 >= numFrameSample*2) 
         {
            // Data buffer is enough
            PcmRut_PutData((kal_uint16 *)pReadBuf);
            kal_brief_trace( TRACE_GROUP_PLAYBACK_COMPONENT, PCMRUT_PUTDATA, numFrameSample*2, 0);
            ACU_ReadDataDone(pcmRutComponent.pSink, numFrameSample*2);
            if(pSinkComp->isEOF && (!pcmRut.isEOF))
            {
               if(pSinkComp->mhdl)
               {
                  pcmRut.isEOF =KAL_TRUE; 
                  mhdlException( pSinkComp->mhdl , MEDIA_END );
               }
            }
         }
         else
         {
            // In several segment
            kal_uint32 uFreeByte, uReadSize16;
            OMX_BUFFERHEADERTYPE *pCurrInput;

            uFreeByte = numFrameSample*2;
            uReadSize16 = 0;
            
            do 
            {
               ACU_GetReadBuffer(pcmRutComponent.pSink, &pReadBuf, &uReadSize8);
               if ((pReadBuf != NULL) && (uReadSize8 != 0)) 
               {
                  // Copy to temp input buffer
                  if (uReadSize8 >= uFreeByte)
                     uReadSize8 = uFreeByte;
                  
                  memcpy(pcmRutComponent.tempBuf + uReadSize16, pReadBuf, uReadSize8);
                  uFreeByte -= uReadSize8;
                  uReadSize16 += uReadSize8/2;
                  ACU_ReadDataDone(pcmRutComponent.pSink, uReadSize8);
               }
               else if ((pReadBuf != NULL))
               {
                  ACU_ReadDataDone(pcmRutComponent.pSink, 0);
               }
               
               // Check whether Input Buffer Header is no more
               pCurrInput = ACU_GetBufferHeader(pcmRutComponent.pSink, 0);
            } while( (uFreeByte != 0) && (pCurrInput != NULL) );
            
            
            if(pSinkComp->isEOF && (!pcmRut.isEOF))
            {
               if(pSinkComp->mhdl)
               {
                  pcmRut.isEOF =KAL_TRUE; 
                  mhdlException( pSinkComp->mhdl , MEDIA_END );
               }
            }
            else
            {              
               // Add silence
               memset(pcmRutComponent.tempBuf + uReadSize16, 0, uFreeByte);
               // Write to DSP
               PcmRut_PutData(pcmRutComponent.tempBuf);
               kal_brief_trace( TRACE_GROUP_PLAYBACK_COMPONENT, PCMRUT_PUTDATA, numFrameSample*2, uFreeByte);
            }
         }
      }
   }
   else
   {
      //put silence to DSP
      PcmRut_PutData_Silence();
   }
}

void PcmRut_RegGetComponent(AudComHdl *hdl)
{
   ASSERT(pcmRutComponent.pDecoder == NULL);
   pcmRutComponent.pDecoder = hdl;
   kal_brief_trace( TRACE_GROUP_PLAYBACK_COMPONENT, PCMRUT_REG, 0, pcmRutComponent.pDecoder);
}

void PcmRut_UnregGetComponent(AudComHdl *hdl)
{
   ASSERT(pcmRutComponent.pDecoder == hdl);
   pcmRutComponent.pDecoder = NULL;
   kal_brief_trace( TRACE_GROUP_PLAYBACK_COMPONENT, PCMRUT_UNREG, 0, pcmRutComponent.pDecoder);
}

void PcmRut_RegPutComponent(AudComHdl *hdl)
{
   ASSERT(pcmRutComponent.pSink == NULL);
   pcmRutComponent.pSink = hdl;
   kal_brief_trace( TRACE_GROUP_PLAYBACK_COMPONENT, PCMRUT_REG, 1, pcmRutComponent.pSink);
}

void PcmRut_UnregPutComponent(AudComHdl *hdl)
{
   ASSERT(pcmRutComponent.pSink == hdl);
   pcmRutComponent.pSink = NULL;
   kal_brief_trace( TRACE_GROUP_PLAYBACK_COMPONENT, PCMRUT_UNREG, 1, pcmRutComponent.pSink);
}

/*-------------------------------*/
/* Basic Service of PCM Routing. */
/*-------------------------------*/

static void PcmRut_Hisr( void *data )
{
   kal_bool fIsSoundPlaying;
   kal_uint32 uNoDecodeSD = 0;

   if(!Media_IsDSPDec())
   {
      return;
   }

#if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__AUDIO_DSP_LOWPOWER_V2__)
   AUDLP_SetClkSwitch_26M(KAL_FALSE);
#endif

#if defined( __I2S_INPUT_MODE_SUPPORT__ )
   pcmRut.fIsReadOnly = (!APM_IsRWtaskRuning() && !Media_IsAlwaysRoute());
#endif
   if(pcmRut.fIsAAC && !(*DP2_AUDIO_ASP_COMMON_FLAG_1 & AUD_BIT_COMFLG1_Initialized))
   {
      kal_dev_trace( TRACE_GROUP_AUD_PLAYBACK, PCMRUT_HISR_INVALID);
      pcmRut.fIsSoundPlaying = KAL_FALSE;
      return;
   }

   pcmRut.channelNum = ((*PCMRUT_BUF_LENGTH) >> 15) & 0x0001;
   pcmRut.dataLen_get = (*PCMRUT_BUF_LENGTH) & 0x3FFF;
   pcmRut.bufAddr = (*PCMRUT_BUF_ADDR) & 0x3FFF;   
   pcmRut.pageNum = (*PCMRUT_BUF_PAGENUM) & 0x000F;

   if(pcmRut.uIntNumberPerFrame != 1)
   {
      ASSERT(pcmRut.uIntNumberPerFrame);
      uNoDecodeSD = *DP2_AUDIO_ASP_COMMON_FLAG_2 & AUD_BIT_COMFLG2_Routine_SD;
   }
   if(!uNoDecodeSD && pcmRut.pHisrCallback)
   {
      pcmRut.pHisrCallback();
   }

   if(PcmRut_IsStereo2Mono())
   {
      pcmRut.dataLen_put = (*PCMRUT_BUF_LENGTH_I) & 0x3FFF;
   } 
   else
   {
      pcmRut.dataLen_put = pcmRut.dataLen_get;
   }
   if(pcmRut.uIntNumberPerFrame)
   {
      pcmRut.uPcmSegment = pcmRut.dataLen_put / pcmRut.uIntNumberPerFrame;
   }

   pcmRut.uBufHead1 = pcmrut_GetPcmBufferBase();
   pcmRut.uBufHead2 = pcmRut.uBufHead1 + pcmrut_GetPcmBufferSize();
   pcmRut.uBufEnd1  = pcmRut.uBufHead1 + pcmRut.dataLen_put;
   pcmRut.uBufEnd2  = pcmRut.uBufHead2 + pcmRut.dataLen_put;

   fIsSoundPlaying = PcmSink_IsSoundRuning();
   if(!pcmRut.fIsSoundPlaying && fIsSoundPlaying)
   {
      pcmRut.uCurWrite = (*DSP_PCM_R); //first sound
      kal_dev_trace( TRACE_GROUP_AUD_PLAYBACK, PCMRUT_HISR_1, pcmRut.uBufHead1, pcmRut.uBufHead2, pcmRut.dataLen_put, pcmRut.uIntNumberPerFrame, pcmRut.uPcmSegment);
   }
   pcmRut.fIsSoundPlaying = fIsSoundPlaying;

   if(pcmRut.uIntNumberPerFrame == 1)
   {
      pcmRut.uCurWrite = pcmRut.bufAddr;
   }
   else
   {   
      if(pcmRut.uCurWrite < pcmRut.uBufEnd1)
      {
         pcmRut.uCurWrite += pcmRut.uPcmSegment;
         if(pcmRut.uCurWrite >= pcmRut.uBufEnd1)
         {
            pcmRut.uCurWrite = pcmRut.uBufHead2 + (pcmRut.uCurWrite - pcmRut.uBufEnd1);
         }
      }
      else
      {
         pcmRut.uCurWrite += pcmRut.uPcmSegment;
         if(pcmRut.uCurWrite >= pcmRut.uBufEnd2)
         {
            pcmRut.uCurWrite = pcmRut.uBufHead1 + (pcmRut.uCurWrite - pcmRut.uBufEnd2);
         }
      }
   }
   kal_dev_trace( TRACE_GROUP_AUD_PLAYBACK, PCMRUT_HISR_2, pcmRut.fIsSoundPlaying, uNoDecodeSD, *DSP_PCM_R, pcmRut.uCurWrite, pcmRut.uPcmSegment);
   PcmSink_MixSoundToDsp();
#if defined(_DSP_INTERSHAREMEM_EN_)    
   *DP2_AUDIO_ASP_TASK4_DM_HANDSHAKE = 0; 
#endif
#if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__AUDIO_DSP_LOWPOWER_V2__)
   AUDLP_SetClkSwitch_26M(KAL_TRUE);
#endif
}

kal_uint32 PcmRut_DspGetFreeSpace()
{
   if(PcmRut_IsStereo2Mono())
   {
      return (pcmRut.uPcmSegment<<1);
   }
   return pcmRut.uPcmSegment;
}

void PcmRut_GetPcmFromDSP(kal_uint32 *pDst32, kal_uint32 uSpace)
{
   volatile kal_int16 *pSrc16;
   kal_int32 I, uSrcWord;
   kal_uint32 uNextBuf;
   kal_bool fDspMono = PcmRut_IsStereo2Mono();
   if(fDspMono)
   {
      uSpace >>= 1;
   }

   if(pcmRut.uCurWrite < pcmRut.uBufEnd1)
   {
      uSrcWord = pcmRut.uBufEnd1 - pcmRut.uCurWrite;
      uNextBuf = pcmRut.uBufHead2;
   }
   else
   {
      uSrcWord = pcmRut.uBufEnd2 - pcmRut.uCurWrite;
      uNextBuf = pcmRut.uBufHead1;
   }

   if(uSrcWord > uSpace)
   {
      uSrcWord = uSpace;
   }

   pSrc16 = DSP_DM_ADDR(pcmRut.pageNum, pcmRut.uCurWrite);
   if(fDspMono)
   {
      for( I = uSrcWord-1; I >= 0; I-- )   
      {
         *pDst32++ = *pSrc16;
         *pDst32++ = *pSrc16++;
      }
   }
   else
   {
      for( I = uSrcWord-1; I >= 0; I-- )   
      {
         *pDst32++ = *pSrc16++;
      }
   }
   if(uSrcWord == uSpace)
   {
      return;
   }
   uSrcWord = uSpace - uSrcWord;
   pSrc16 = DSP_DM_ADDR(pcmRut.pageNum, uNextBuf);
   if(fDspMono)
   {
      for( I = uSrcWord-1; I >= 0; I-- )   
      {
         *pDst32++ = *pSrc16;
         *pDst32++ = *pSrc16++;
      }
   }
   else
   {
      for( I = uSrcWord-1; I >= 0; I-- )   
      {
         *pDst32++ = *pSrc16++;
      }
   }
}

static void PcmRut_PutPcmToDSPInternal(kal_int32 *pSrc32, kal_int16 *pSrc16, kal_uint32 uDstWord, kal_uint32 uStep, kal_uint16 uCurrWrite, const kal_bool fWriteZeroToDsp)
{
   kal_int32 I, iSample;
   volatile kal_int16 *pDst16;
   pDst16 = DSP_DM_ADDR(pcmRut.pageNum, uCurrWrite);
   if(fWriteZeroToDsp)
   {
      for( I = uDstWord-1; I >= 0; I--)  
      {
         iSample = *pSrc32;
         pSrc32 += uStep;
         if(iSample > 32767)
         {
            iSample = 32767;
         }
         else if(iSample < -32768)
         {
            iSample = -32768;
         }
         *pDst16++ = 0;
         *pSrc16++ = (kal_int16)iSample;
      }
   }
   else
   {
      for( I = uDstWord-1; I >= 0; I--)  
      {
         iSample = *pSrc32;
         pSrc32 += uStep;
         if(iSample > 32767)
         {
            iSample = 32767;
         }
         else if(iSample < -32768)
         {
            iSample = -32768;
         }
         *pDst16++ = (kal_int16)iSample;
         *pSrc16++ = (kal_int16)iSample;
      }
   }
}

void PcmRut_PutPcmToDSP(kal_int32 *pSrc32, kal_int16 *pSrc16, kal_uint32 uLength, const kal_bool fWriteZeroToDsp)
{
   volatile kal_int16 *pDst16;
   kal_int32 I, iSample, uDstWord;
   kal_uint32 uNextBuf, uStep;

   uStep = 1;
   if(PcmRut_IsStereo2Mono())
   {
      uStep=2;
      uLength>>=1;
   }
   if(pcmRut.uCurWrite < pcmRut.uBufEnd1)
   {
      uDstWord = pcmRut.uBufEnd1 - pcmRut.uCurWrite;
      uNextBuf = pcmRut.uBufHead2;
   }
   else
   {
      uDstWord = pcmRut.uBufEnd2 - pcmRut.uCurWrite;
      uNextBuf = pcmRut.uBufHead1;
   }
   if(uDstWord > uLength)
   {
      uDstWord = uLength;
   }
   PcmRut_PutPcmToDSPInternal(pSrc32, pSrc16, uDstWord, uStep, pcmRut.uCurWrite, fWriteZeroToDsp);
   pSrc32 += uDstWord>>(uStep-1);
   pSrc16 += uDstWord;
   if(uDstWord == uLength)
   {
      return;
   }
   uDstWord = uLength - uDstWord;
   PcmRut_PutPcmToDSPInternal(pSrc32, pSrc16, uDstWord, uStep, uNextBuf, fWriteZeroToDsp);
}

void PcmRut_SetInterruptNumberPerFrame(kal_uint8 uNumber)
{
   pcmRut.fIsSoundPlaying = KAL_FALSE;
   if(uNumber != pcmRut.uIntNumberPerFrame)
   {
      pcmRut.uIntNumberPerFrame = uNumber;
   }
}

void PcmRut_TurnOnPcmRouteInterrupt()
{
   Media_Format uFormat = Media_GetAudioFormat();
   if(uFormat == MEDIA_FORMAT_AAC || uFormat == MEDIA_FORMAT_AAC_PLUS || uFormat == MEDIA_FORMAT_AAC_PLUS_V2)
   {
      pcmRut.fIsAAC = KAL_TRUE;
   }
   else
   {
      pcmRut.fIsAAC = KAL_FALSE;
   }
   if(pcmRut.fIsHisrEnabled == KAL_FALSE)
   {
      pcmRut.fIsSoundPlaying = KAL_FALSE;
      AM_SetPostProcessCtrl( PCMRUT_MASK, PCMRUT_ON);
      L1Audio_HookHisrHandler(DP_D2C_PCM_RUT, PcmRut_Hisr, 0);
      pcmRut.fIsHisrEnabled = KAL_TRUE;
   }
}

void PcmRut_TurnOffPcmRouteInterrupt()
{
   AudComHdlInt *pDecComp;
   pcmRut.fIsSoundPlaying = KAL_FALSE;
   if(pcmRut.pHisrCallback || PcmSink_IsSoundRuning())
   {
      return;
   }
   if(pcmRut.fIsHisrEnabled)
   {
      AM_ClearPostProcessCtrl( PCMRUT_MASK );
      L1Audio_UnhookHisrHandler( DP_D2C_PCM_RUT );
      pcmRut.fIsHisrEnabled = KAL_FALSE;
      pcmRut.fIsAAC = KAL_FALSE;
      pcmRut.fIsReadOnly = KAL_FALSE;
   }
   // to avoid eof, but pHisrCallback is released and no one callback media_end
   if (pcmRutComponent.pDecoder)
   {
   	   pDecComp = (AudComHdlInt *)pcmRutComponent.pDecoder;
   	   if(pDecComp->isEOF && (!pcmRut.isEOF))
       {
          if(pDecComp->mhdl)
          {
             pcmRut.isEOF =KAL_TRUE; 
             mhdlException( pDecComp->mhdl , MEDIA_END );
          }
       }
   }
}

void PcmRut_Start( void (*PcmRutHisrHandler)(void) )
{   
   kal_trace( TRACE_GROUP_PLAYBACK_COMPONENT, PCMRUT_START, pcmRut.pHisrCallback);
#if defined( __I2S_INPUT_MODE_SUPPORT__ )
   pcmRut.fIsReadOnly = (!APM_IsRWtaskRuning() && !Media_IsAlwaysRoute());
#endif
   if (pcmRut.pHisrCallback == NULL) 
   {
      //current used PcmRut_HookedHisrHander
      pcmRutComponent.tempBuf = (kal_uint16 *)audio_alloc_mem_cacheable(PCMRUT_MAX_BUF_SIZE * sizeof(kal_uint16)); 
      pcmRut.pHisrCallback = PcmRut_ApmCallback;
      pcmRut.bufferingSample = 0;
      pcmRut.fPreBuffering = KAL_TRUE;
      pcmRut.isEOF = KAL_FALSE;
      pcmRut.uAudId = L1Audio_GetAudioID();
      L1Audio_SetFlag(pcmRut.uAudId);
      if(!pcmRut.fIsReadOnly)
      {
         PcmSink_Mute(KAL_TRUE, PCMSINK_MUTE_PCMRUT);
      }
      if (pcmRutComponent.pSink && !Media_IsAlwaysRoute() )
      {
         MH_FlushPostProcess(pcmRutComponent.pSink);
      }
      PcmRut_TurnOnPcmRouteInterrupt();
   }   
}

void PcmRut_Stop( void )
{   
   kal_trace( TRACE_GROUP_PLAYBACK_COMPONENT, PCMRUT_STOP, pcmRut.pHisrCallback);
   if(pcmRut.pHisrCallback) 
   {
      if( -1!= AM_IsAudioPlaybackOn() && !pcmRut.fIsReadOnly)
      {
         PcmSink_Mute(KAL_TRUE, PCMSINK_MUTE_PCMRUT);
         kal_sleep_task(PCMRUT_ENDING_MUTE_TICK);
      }
      PcmSink_Mute(KAL_FALSE, PCMSINK_MUTE_PCMRUT);      
      L1Audio_ClearFlag( pcmRut.uAudId );
      L1Audio_FreeAudioID( pcmRut.uAudId );
      pcmRut.pHisrCallback = NULL;
      PcmRut_TurnOffPcmRouteInterrupt();
      audio_free_mem( (void **) &pcmRutComponent.tempBuf);
      if (pcmRutComponent.pSink && !Media_IsAlwaysRoute() )
      {
         MH_FlushPostProcess(pcmRutComponent.pSink);
      }
   }
}

void PcmRut_MuteDSP( kal_bool fMute )
{
   pcmRut.fMute = fMute;
}

