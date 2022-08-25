/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *   AmrDspDecoder.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   The basic functions of AMR DSP decoder.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef AMR_CODEC

#include "kal_trace.h"
#include "audio_enum.h"
#include "audio_def.h"
#include "speech_def.h"
#include "common_def.h"
#include "l1sp_trc.h"
#include "AudComUtil.h"
#include "AMR_codec.h"
#include "amr_codec_exp.h"
#include "amr_table.h"
#include "amr_drv.h"
#include "ddload.h"
#include "am.h"
#include "pcmsink.h"
#include "media.h"
#include "l1audio_sph_trc.h"

// AWB state machine
#define DSP_IDLE              0
#define DSP_INITIALIZED       1
#define DSP_PLAYING           2
#define DSP_STOP              3

extern kal_bool Is_PutPcmrutOn(void);
extern void MixerOut_Stop_Immediate(void);
extern void PcmSink_Mute(kal_bool fMute, kal_uint32 uFunction);
extern void AFE_SetHardwareMute(bool mute);
extern void AFE_SetDigitalGain( kal_uint8 aud_func, kal_uint8 level );

/*------------------------------------------------*/
/* The private functions of AMR decoder.          */
/*------------------------------------------------*/

#define AMR_NEW_PATH   (defined(MT6260)|| defined(MT6261) || defined(MT2501) || defined(MT2502))
#if defined(__DSP_CHIP_FD216__)
static void amr_write_speech_mode_to_dsp( AudComHdlInt *ihdl, kal_uint8 bTxType)
{
   AMR_DecData *pDecData = (AMR_DecData *)ihdl->pPrivateData;

#if defined(AMRWB_DECODE)
   if (MEDIA_FORMAT_AMR_WB == ihdl->mediaType) {
      /* codec mode | Tx-Type */
      *DSP_SD2_AWB_VM_0 = (pDecData->bCodecMode << 8) | bTxType;
   } else
#endif
   {
   	
#if AMR_NEW_PATH
      *AMR_PARAM2 = pDecData->bCodecMode; 
      
      if (bTxType == 0)       // TX_NO_SATA
         *DSP_SPH_3G_SD_DATA_HDR = 0xF;
      else if (bTxType == 1)  // TX_SID_FIRST
         *DSP_SPH_3G_SD_DATA_HDR = 0x6;  
      else if (bTxType == 3)  // TX_SID_UPDATE           
         *DSP_SPH_3G_SD_DATA_HDR = 0x8;
      else                    // TX_SPEECH_GOOD  (bTxType == 2)
         *DSP_SPH_3G_SD_DATA_HDR = 0;
#else
      *DSP_SD2_VM_17 = pDecData->bCodecMode;
      *DSP_SD2_VM_0 = bTxType;
#endif  
   }
}

static void amr_write_speech_data_to_dsp(AudComHdlInt *ihdl, kal_uint16 *pwData, kal_uint16 bLen)
{
   volatile kal_uint16 *pwSherifAddr;
   kal_uint8 i;
   
#if defined(AMRWB_DECODE)
   if (MEDIA_FORMAT_AMR_WB == ihdl->mediaType) {
      pwSherifAddr = DSP_SD2_AWB_VM_1;
      if (bLen>17) {
         for (i=0; i<17; i++) {
            *pwSherifAddr++ = *pwData++;
         }
         pwSherifAddr = DSP_SD2_AWB_VM_18;
         for (; i< bLen; i++) {
            *pwSherifAddr++ = *pwData++;
         }
      } else {
         for(i=0; i < bLen; i++ ) {
            *pwSherifAddr++ = *pwData++;
         }
      }
   } else
#endif
   {
#if AMR_NEW_PATH      
      pwSherifAddr =DP_3G_DL_RX_ADDR;
#else
      pwSherifAddr = DSP_SD2_VM_1;
#endif      
      for (i = 0; i < bLen; i++) {
         *pwSherifAddr++ = *pwData++;
      }
   }
}
#endif

static kal_uint32 amrCheckFrameHeader( AudComHdlInt *ihdl, kal_uint8  bFrameHeader, kal_uint8 *Tx_Type, kal_uint16 *lenSherifData, kal_uint16 *rd_bits )
{
   kal_uint8  FT;
   AMR_DecData *pDecData = (AMR_DecData *)ihdl->pPrivateData;

   FT = (bFrameHeader >> 3) & 0x0F;
  
   if (FT<=7) { /* AMR 4.75 ~ 12.2 kbps */
      pDecData->bCodecMode = FTtoSCM_AMR[FT];
      *rd_bits = lenSpeechBitsAMR[FT];
      *Tx_Type = 2;
      *lenSherifData = (*rd_bits+15)/16;
   } else if (FT==8) { /* AMR SID */
      *rd_bits = lenSpeechBitsAMR[FT];
      *Tx_Type = 3;
      *lenSherifData = 3;
   } else if (FT>=9 && FT<=14) { /* GSM/TDMA/PDC SID and 'for-future-use' mode */
      return HEADER_ERROR;
   } else if (FT==15) { /* No_Data*/
      *rd_bits = 0;
      *lenSherifData = 0;
      *Tx_Type = 0;
      return HEADER_NO_DATA_FRAME;
   }
   return HEADER_OK;
}

#if defined(AMRWB_DECODE)
static kal_int32 awbCheckFrameHeader( AudComHdlInt *ihdl, kal_uint8  bFrameHeader, kal_uint8 *Tx_Type, kal_uint16 *lenSherifData, kal_uint16 *rd_bits )
{
   kal_uint8  FT, FQI;
   AMR_DecData *pDecData = (AMR_DecData *)ihdl->pPrivateData;
   
   FT = (bFrameHeader >> 3) & 0x0F;
   FQI = (bFrameHeader >> 2) & 0x01;

   if (FT<=8) { /* AMR-WB 6.60 kbps ~ 23.85 kbps */
      *Tx_Type = 2;
      pDecData->bCodecMode = FTtoSCM_AMR_WB[FT];
      *rd_bits = lenSpeechBitsAMR_WB[FT];
      *lenSherifData = (*rd_bits+15)/16;
   } else if (FT==9) { /* AMR-WB SID */
      *Tx_Type = 3;
      *rd_bits = lenSpeechBitsAMR_WB[FT];
      *lenSherifData = 3;
   } else if (FT==14) { /* SPEECH_LOST */
      if (FQI==0) {
         *rd_bits = 0;
         *lenSherifData = 0;
         *Tx_Type = 0;
      } else {
         return HEADER_ERROR; /* undefined situation */
      }
   } else if (FT==15) { /* NO_DATA */
      *rd_bits = 0;
      *lenSherifData = 0;
      *Tx_Type = 0;
      return HEADER_NO_DATA_FRAME;
   } else { /* 'for-future-use' mode */
      return HEADER_ERROR;
   }
   return HEADER_OK;
}
#endif

#if defined(__DSP_CHIP_FD216__)
static void amr_bit_ordering_file_to_sherif(AudComHdlInt *ihdl, kal_uint8 bTxType, kal_uint8 bFrameType, kal_uint16 wLenBits)
{
   kal_uint16 i, k, p, q;
   AMR_DecData *pDecData = (AMR_DecData *)ihdl->pPrivateData;
   kal_uint16 *pInData, *pOutData;

   pInData = pDecData->Tx_ordering_buffer;
   pOutData = pDecData->Tx_data_buffer;

   k = 0;
#if defined(AMRWB_DECODE)
   if (MEDIA_FORMAT_AMR_WB == ihdl->mediaType) {
      const kal_uint16* pOrderingTable = tblAMR_WBOrder[bFrameType];
      for (i=0, p=0, q=0; i<wLenBits; i++){
         if (bTxType==2) {
            /* Speech */
            k = (kal_uint16)pOrderingTable[i];
         } else if (bTxType==3) {
            /* SID first or SID update */
            k=i;
         } else {
            ASSERT(KAL_FALSE);
         }
         pOutData[k/16] |= (pInData[q] & AMR_ord_tab[p]) ? AMR_get_tab[k%16] : 0;
         if(++p==16) { p=0; q++; }
      }
   } else
#endif
   {
      const kal_uint8* pOrderingTable = tblAMROrder[bFrameType];
      for(i=0, p=0, q=0; i<wLenBits; i++){
         if (bTxType==2) {
            /* Speech */
            k = (kal_uint16)pOrderingTable[i];
         } else if (bTxType==3) {
            /* SID first or SID update */
            k=i;
         } else {
            ASSERT(KAL_FALSE);
         }
         pOutData[k/16] |= (pInData[q] & AMR_ord_tab[p]) ? AMR_get_tab[k%16] : 0;
         if(++p==16) { p=0; q++; }
      }
   }
}

static void amr_PlaybackError(AudComHdlInt *ihdl)
{
   if(ihdl->isEOF){
   	  ihdl->data = MEDIA_END;
   	  ihdl->isDspDecodeEOF =KAL_TRUE;
   	  ihdl->endStatus = MEDIA_TERMINATED;
   	  mhdlException( ihdl->mhdl , MEDIA_END );
   }
   else{
      ihdl->endStatus = MEDIA_ERROR;
      ihdl->data = MEDIA_ERROR;
      mhdlException( ihdl->mhdl , (Media_Event)ihdl->data );
  }
}

static kal_uint16 amr_SetAndGetInitialCodecMode( AudComHdlInt *ihdl )
{
   kal_uint16 wInitialCodecMode;
   AMR_DecData *pDecData = (AMR_DecData *)ihdl->pPrivateData;

#if defined(AMRWB_DECODE)
   if (ihdl->mediaType == MEDIA_FORMAT_AMR_WB) {
      pDecData->bCodecMode = 0x20;
      wInitialCodecMode = (0x20<<2);
   } else
#endif
   {
      pDecData->bCodecMode = 0x03;
      wInitialCodecMode = (0x03<<2) | (0x03<<6);
   }
   return wInitialCodecMode;
}

#if defined(AMRWB_DECODE) || defined(AMRWB_ENCODE)
static void amr_WBStopCtrl( AudComHdlInt *ihdl, bool isPlayback )
{
   kal_uint16  I, ctl;
   volatile kal_uint16* ptr;

   ptr = ((isPlayback == true )?DSP_AWB_SD_CTRL:DSP_AWB_SE_CTRL);

   if(*ptr == DSP_PLAYING){
      ihdl->mediaStatus = COMPONENT_STATE_IDLE;
      *ptr = DSP_STOP;
      kal_trace( TRACE_STATE, L1AUDIO_STOP_STATE );
   }
   for( I = 0; ; I++ ) {
      ctl = *ptr;
      if( ctl == DSP_IDLE ){                /* DSP returns to idle state */
         kal_trace( TRACE_STATE, L1AUDIO_IDLE_STATE );
         break;
      }
      ASSERT_REBOOT( I < 20 );
      kal_sleep_task( 2 );
   }
}
#endif


static void AmrDecHisrHandler(void *hComponent)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hComponent;
   AMR_DecData *pDecData;
   Media_BufferEvent eRet;
   kal_uint8  bFrameHeader, FT, Tx_Type;
   kal_uint16 rd_bytes, lenSherifData, rd_bits;
   kal_int32  uBytesAvailable;
   
   pDecData = (AMR_DecData *)ihdl->pPrivateData;

#if defined(__AUDIO_BT_FORCE_VBI_RESET__)
   AM_BT_ExecuteVBIReset();
#endif

#if defined(_DSP_INTERSHAREMEM_EN_)    
   *DP2_AUDIO_ASP_TASK4_DM_HANDSHAKE = 0; 
#endif

   // To avoid re-entry
   if ( (ihdl->endStatus == MEDIA_TERMINATED) || (ihdl->endStatus == MEDIA_ERROR) )
      return;
      
#if VERIFY_AVSYNC
   ut_avsync_play_hisr();
#endif
   
   eRet = ACU_PeekByte( (AudComHdl *)ihdl, &bFrameHeader);
   uBytesAvailable = ACU_PeekDataCount((AudComHdl *)ihdl) - 1;
   if (uBytesAvailable < 1) {
      // Write silence to DSP
      amr_write_speech_mode_to_dsp( ihdl, 0 );
      
      if (MEDIA_BUFFER_EOF == eRet) {
         // End of file
         ACU_DSPEofHandler(ihdl);
         return;
      } else if ( ACU_PeekIsEOS( (AudComHdl *)ihdl ) ) {
         // skip, let it consume the final data
         ACU_ReadDataDone( (AudComHdl *)ihdl, 0);
      } else { 
      	 if(ihdl->mhdl && !ihdl->mhdl->waiting && !ihdl->isEOF) {  	 
   	        ihdl->mhdl->isUnderflow = KAL_TRUE;
   	        ihdl->mhdl->waiting = KAL_TRUE;
   	        ihdl->data = MEDIA_BUFFER_UNDERFLOW;     
            mhdlException( ihdl->mhdl, (Media_Event)ihdl->data ); 
            return;
         }
         return;
      }
   }
   
   // Get frame type
   
#if defined(AMRWB_DECODE)
   if (MEDIA_FORMAT_AMR_WB == ihdl->mediaType) {
      kal_uint16 awbCodecType = ((*DSP_SD2_AWB_VM_0)>>8)&0xFF;
      kal_int32 ret;
      FT = (bFrameHeader >> 3) & 0x0F;
      /* If the codec mode are not right, DSP may mal-function */
      EXT_ASSERT( ( (awbCodecType >= 0x20) && (awbCodecType<=0x28) ), (*DSP_SD2_AWB_VM_0), 0, 0);

      ret = awbCheckFrameHeader( ihdl, bFrameHeader, &Tx_Type, &lenSherifData, &rd_bits );
      if (ret == HEADER_ERROR){
         amr_PlaybackError(ihdl);
         return;
      } else if (ret == HEADER_NO_DATA_FRAME){
         /* consume the header byte */
         ACU_ReadDataDone( (AudComHdl *)ihdl, 1);
         ihdl->mhdl->current_time += 20;
         
         ACU_SetResumePoint(ihdl->bsInfo.pResBuf, ihdl->bsInfo.uCurrentOffset, ihdl->bsInfo.uCurrentFrame);         
         //pDecData->resumeFrameOffset += 1;         
         ihdl->bsInfo.uCurrentOffset += 1;
         ihdl->bsInfo.uCurrentFrame++;
         amr_write_speech_mode_to_dsp(ihdl, Tx_Type);
         return;
      }
   } else
#endif
   {
      kal_uint32 ret, I;      
      /* If the codec mode are not right, DSP may mal-function */
#if AMR_NEW_PATH         
        EXT_ASSERT(((*AMR_PARAM2>=0x03) && (*AMR_PARAM2<=0x0A)), (*AMR_PARAM2), 0, 0);
#else
      EXT_ASSERT(((*DSP_SD2_VM_17>=0x03) && (*DSP_SD2_VM_17<=0x0A)), (*DSP_SD2_VM_17), 0, 0);
#endif
      for(I=0;I<32;I++) //max frame size = 32
      {
         eRet = ACU_PeekByte( (AudComHdl *)ihdl, &bFrameHeader);
         if (MEDIA_BUFFER_EOF == eRet) 
         {
         	  ACU_DSPEofHandler(ihdl);
         	  return;
         }
         uBytesAvailable = ACU_PeekDataCount((AudComHdl *)ihdl) - 1;
         FT = (bFrameHeader >> 3) & 0x0F;
         ret = amrCheckFrameHeader( ihdl, bFrameHeader, &Tx_Type, &lenSherifData, &rd_bits );
         if(ret != HEADER_ERROR)
         {
         	  break;
         }
         ACU_ReadDataDone( (AudComHdl *)ihdl, 1);
      }
      if (ret == HEADER_ERROR){
         amr_PlaybackError(ihdl);
         return;
      } else if (ret == HEADER_NO_DATA_FRAME){
         /* consume the header byte */
         ACU_ReadDataDone( (AudComHdl *)ihdl, 1);
         ihdl->mhdl->current_time += 20;
                  
         ACU_SetResumePoint(ihdl->bsInfo.pResBuf, ihdl->bsInfo.uCurrentOffset, ihdl->bsInfo.uCurrentFrame);         
         //pDecData->resumeFrameOffset += 1;
         ihdl->bsInfo.uCurrentOffset += 1;
         ihdl->bsInfo.uCurrentFrame++;
         amr_write_speech_mode_to_dsp(ihdl, Tx_Type);
         return;
      }
   }
   
   /* check buffer underflow */
   rd_bytes = (rd_bits+7)>>3;
   if (rd_bytes > uBytesAvailable) {
      amr_write_speech_mode_to_dsp( ihdl, 0 );
      if (ihdl->isEOF) {
         ACU_DSPEofHandler(ihdl);
         return;
      } else if ( ACU_PeekIsEOS( (AudComHdl *)ihdl ) ) {
         // skip, let it consume the final data
         ACU_ReadDataDone( (AudComHdl *)ihdl, 0);
      } else {
      	 if(ihdl->mhdl && !ihdl->mhdl->waiting && !ihdl->isEOF ) {  	 
   	         ihdl->mhdl->isUnderflow = KAL_TRUE;
   	         ihdl->mhdl->waiting = KAL_TRUE;
      	     ihdl->data = MEDIA_BUFFER_UNDERFLOW;
      	     mhdlException( ihdl->mhdl, (Media_Event)ihdl->data );
             return;
         }
         return;
      }
   }
   
   if(ihdl->mhdl->current_time >= ihdl->mhdl->stop_time) {
      ihdl->isDspDecodeEOF =KAL_TRUE;
      ihdl->data = MEDIA_STOP_TIME_UP;
      mhdlException( ihdl->mhdl, (Media_Event)ihdl->data );
      ihdl->endStatus = MEDIA_TERMINATED;
      return;
   }
   
   ihdl->mhdl->current_time += 20;
   
   ACU_SetResumePoint(ihdl->bsInfo.pResBuf, ihdl->bsInfo.uCurrentOffset, ihdl->bsInfo.uCurrentFrame);   
   //pDecData->resumeFrameOffset += (rd_bytes+1);
   ihdl->bsInfo.uCurrentOffset += (rd_bytes+1);
   ihdl->bsInfo.uCurrentFrame++;
   
   /* consume the header byte */
   ACU_ReadDataDone( (AudComHdl *)ihdl, 1);
   /* get speech data from ring buffer */
   ACU_GetNBytes( (AudComHdl *)ihdl, (OMX_U8 *)pDecData->Tx_ordering_buffer, rd_bytes);

   if (MEDIA_FORMAT_AMR == ihdl->mediaType && ihdl->mhdl->pStrmStruct == NULL) 
   {
      kal_uint8  bFrameHeader2; 
      eRet = ACU_PeekByte( (AudComHdl *)ihdl, &bFrameHeader2);
      if (MEDIA_BUFFER_SUCCESS == eRet) 
      {
      	 kal_uint8 Tx_Type2; kal_uint16 lenSherifData2; kal_uint16 rd_bits2; kal_uint32 ret;
         ret = amrCheckFrameHeader( ihdl, bFrameHeader2, &Tx_Type2, &lenSherifData2, &rd_bits2 );
         if(ret == HEADER_ERROR)
         {
   	        amr_write_speech_mode_to_dsp( ihdl, 0 );
            return;
         }
      }
   }
   
   /* bits re-ordering */
   kal_mem_set(pDecData->Tx_data_buffer, 0, sizeof(pDecData->Tx_data_buffer));
   amr_bit_ordering_file_to_sherif(ihdl, Tx_Type, FT, rd_bits);

   if (Tx_Type==3) {
      /* SID first or SID update */
      pDecData->Tx_data_buffer[2]&=0x00E0;
      if ((pDecData->Tx_ordering_buffer[2]&0x0010)==0) {
         /* SID first */
         Tx_Type = 1;
      }
   }

   /* write speech frame to sherif */
   amr_write_speech_mode_to_dsp(ihdl, Tx_Type);
   amr_write_speech_data_to_dsp(ihdl, pDecData->Tx_data_buffer, lenSherifData);
   
   if( !ihdl->isEOF && !ihdl->Decode_EOF)
   {
      if(ihdl->mhdl && !ihdl->mhdl->waiting)
      {
         ihdl->mhdl->waiting = KAL_TRUE;
         kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PROCESS, MTKAUD_DECODER_AMR, 0,0,0,0,0,0);
         if(ihdl->mhdl->handler)
         {
            mhdlException( ihdl->mhdl, MEDIA_DATA_REQUEST ); 
         }
      }
   } 
}

#if defined(__VAD_SUPPORT__)

#if defined(__VM_CODEC_SUPPORT__)
static kal_bool fAmrBabyMonitorDebug = KAL_FALSE;
#endif

static void amrBabyMonitor_write_speech_mode_to_dsp( AudComHdlInt *ihdl, kal_uint8 bTxType)
{
   AMR_DecData *pDecData = (AMR_DecData *)ihdl->pPrivateData;

   Pseudo_SAL_3G_Set_RxType(bTxType);
   Pseudo_SAL_3G_Upd_Dec_Cod(pDecData->bCodecMode);
}

static void amrBabyMonitor_write_speech_data_to_dsp(AudComHdlInt *ihdl, kal_uint16 *pwData, kal_uint16 bLen)
{
   volatile kal_uint16 *pwSherifAddr;
   kal_uint8 i;
   
   pwSherifAddr = DSP_SPH_3G_SD_DATA_HB;

   for (i = 0; i < bLen; i++) {
      *pwSherifAddr++ = *pwData++;
   }
   
   DP_SPH_3G_SYNC |= 2;
}

static void AmrBabyMonitorDecHisrHandler(void *hComponent)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hComponent;
   AMR_DecData *pDecData;
   Media_BufferEvent eRet;
   kal_uint8  bFrameHeader, FT, Tx_Type;
   kal_uint16 rd_bytes, lenSherifData, rd_bits;
   kal_int32  uBytesAvailable;
   
   pDecData = (AMR_DecData *)ihdl->pPrivateData;

   // To avoid re-entry
   if ( (ihdl->endStatus == MEDIA_TERMINATED) || (ihdl->endStatus == MEDIA_ERROR) )
      return;
   
   eRet = ACU_PeekByte( (AudComHdl *)ihdl, &bFrameHeader);
   uBytesAvailable = ACU_PeekDataCount((AudComHdl *)ihdl) - 1;
   if (uBytesAvailable < 1) {
      // Write silence to DSP
      amrBabyMonitor_write_speech_mode_to_dsp( ihdl, 0 );
      
      if (MEDIA_BUFFER_EOF == eRet) {
         // End of file
         ACU_DSPEofHandler(ihdl);
         return;
      } else if ( ACU_PeekIsEOS( (AudComHdl *)ihdl ) ) {
         // skip, let it consume the final data
         ACU_ReadDataDone( (AudComHdl *)ihdl, 0);
      } else { 
      	 if(ihdl->mhdl && !ihdl->mhdl->waiting && !ihdl->isEOF) {  	 
   	        ihdl->mhdl->isUnderflow = KAL_TRUE;
   	        ihdl->mhdl->waiting = KAL_TRUE;
   	        ihdl->data = MEDIA_BUFFER_UNDERFLOW;     
            mhdlException( ihdl->mhdl, (Media_Event)ihdl->data ); 
            return;
         }
         return;
      }
   }
   
   // Get frame type
   {
      kal_uint32 ret, I;      

      for(I=0;I<32;I++) //max frame size = 32
      {
         eRet = ACU_PeekByte( (AudComHdl *)ihdl, &bFrameHeader);
         if (MEDIA_BUFFER_EOF == eRet) 
         {
         	  ACU_DSPEofHandler(ihdl);
         	  return;
         }
         uBytesAvailable = ACU_PeekDataCount((AudComHdl *)ihdl) - 1;
         FT = (bFrameHeader >> 3) & 0x0F;
         ret = amrCheckFrameHeader( ihdl, bFrameHeader, &Tx_Type, &lenSherifData, &rd_bits );
         if(ret != HEADER_ERROR)
         {
         	  break;
         }
         ACU_ReadDataDone( (AudComHdl *)ihdl, 1);
      }
      if (ret == HEADER_ERROR){
         amr_PlaybackError(ihdl);
         return;
      } else if (ret == HEADER_NO_DATA_FRAME){
         /* consume the header byte */
         ACU_ReadDataDone( (AudComHdl *)ihdl, 1);
         ihdl->mhdl->current_time += 20;
                  
         ACU_SetResumePoint(ihdl->bsInfo.pResBuf, ihdl->bsInfo.uCurrentOffset, ihdl->bsInfo.uCurrentFrame);         
         //pDecData->resumeFrameOffset += 1;
         ihdl->bsInfo.uCurrentOffset += 1;
         ihdl->bsInfo.uCurrentFrame++;
         amrBabyMonitor_write_speech_mode_to_dsp(ihdl, Tx_Type);
         return;
      }
   }
   
   /* check buffer underflow */
   rd_bytes = (rd_bits+7)>>3;
   if (rd_bytes > uBytesAvailable) {
      amrBabyMonitor_write_speech_mode_to_dsp( ihdl, 0 );
      if (ihdl->isEOF) {
         ACU_DSPEofHandler(ihdl);
         return;
      } else if ( ACU_PeekIsEOS( (AudComHdl *)ihdl ) ) {
         // skip, let it consume the final data
         ACU_ReadDataDone( (AudComHdl *)ihdl, 0);
      } else {
      	 if(ihdl->mhdl && !ihdl->mhdl->waiting && !ihdl->isEOF ) {  	 
   	         ihdl->mhdl->isUnderflow = KAL_TRUE;
   	         ihdl->mhdl->waiting = KAL_TRUE;
      	     ihdl->data = MEDIA_BUFFER_UNDERFLOW;
      	     mhdlException( ihdl->mhdl, (Media_Event)ihdl->data );
             return;
         }
         return;
      }
   }
   
   if(ihdl->mhdl->current_time >= ihdl->mhdl->stop_time) {
      ihdl->isDspDecodeEOF =KAL_TRUE;
      ihdl->data = MEDIA_STOP_TIME_UP;
      mhdlException( ihdl->mhdl, (Media_Event)ihdl->data );
      ihdl->endStatus = MEDIA_TERMINATED;
      return;
   }
   
   ihdl->mhdl->current_time += 20;
   
   ACU_SetResumePoint(ihdl->bsInfo.pResBuf, ihdl->bsInfo.uCurrentOffset, ihdl->bsInfo.uCurrentFrame);   
   //pDecData->resumeFrameOffset += (rd_bytes+1);
   ihdl->bsInfo.uCurrentOffset += (rd_bytes+1);
   ihdl->bsInfo.uCurrentFrame++;
   
   /* consume the header byte */
   ACU_ReadDataDone( (AudComHdl *)ihdl, 1);
   /* get speech data from ring buffer */
   ACU_GetNBytes( (AudComHdl *)ihdl, (OMX_U8 *)pDecData->Tx_ordering_buffer, rd_bytes);

   if (MEDIA_FORMAT_AMR == ihdl->mediaType && ihdl->mhdl->pStrmStruct == NULL) 
   {
      kal_uint8  bFrameHeader2; 
      eRet = ACU_PeekByte( (AudComHdl *)ihdl, &bFrameHeader2);
      if (MEDIA_BUFFER_SUCCESS == eRet) 
      {
      	 kal_uint8 Tx_Type2; kal_uint16 lenSherifData2; kal_uint16 rd_bits2; kal_uint32 ret;
         ret = amrCheckFrameHeader( ihdl, bFrameHeader2, &Tx_Type2, &lenSherifData2, &rd_bits2 );
         if(ret == HEADER_ERROR)
         {
   	        amrBabyMonitor_write_speech_mode_to_dsp( ihdl, 0 );
            return;
         }
      }
   }
   
   /* bits re-ordering */
   kal_mem_set(pDecData->Tx_data_buffer, 0, sizeof(pDecData->Tx_data_buffer));
   amr_bit_ordering_file_to_sherif(ihdl, Tx_Type, FT, rd_bits);

   if (Tx_Type==3) {
      /* SID first or SID update */
      pDecData->Tx_data_buffer[2]&=0x00E0;
      if ((pDecData->Tx_ordering_buffer[2]&0x0010)==0) {
         /* SID first */
         Tx_Type = 1;
      }
   }

   /* write speech frame to sherif */
   amrBabyMonitor_write_speech_mode_to_dsp(ihdl, Tx_Type);
   amrBabyMonitor_write_speech_data_to_dsp(ihdl, pDecData->Tx_data_buffer, lenSherifData);
   
   if( !ihdl->isEOF && !ihdl->Decode_EOF)
   {
      if(ihdl->mhdl && !ihdl->mhdl->waiting)
      {
         ihdl->mhdl->waiting = KAL_TRUE;
         kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PROCESS, MTKAUD_DECODER_AMR, 0,0,0,0,0,0);
         if(ihdl->mhdl->handler)
         {
            mhdlException( ihdl->mhdl, MEDIA_DATA_REQUEST ); 
         }
      }
   } 
}
#endif

static void amrOpenDeviceCommon( kal_uint16 wCodecMode, kal_uint32 playType )
{
#if defined(__VAD_SUPPORT__)
   AM_BabyMonitor_PlaybackOn(0x3);
   
#if defined(__VM_CODEC_SUPPORT__)
   // Debug
   {
      kal_uint32 module_id = MOD_L1AUDIO_SPH_SRV;
      kal_uint32 voc_pattern = TVCI_CREATE_FILE;
      kal_uint32 *voc_ptr = &voc_pattern;
      
      if (!tst_trace_check_ps_filter_off(TRACE_GROUP_VOC, &module_id, 0x2)) {
         fAmrBabyMonitorDebug = KAL_TRUE;
         tst_vc_response(TVCI_VM_LOGGING, (const kal_uint8*)voc_ptr, 4);
         vmRecord(NULL, 0, 1);
      }
   }
#endif

   return;
#endif

#if AMR_AWB_AUDIO_PATH_SUPPORT
   {
      kal_uint16 control = wCodecMode ;
      kal_uint32 vm_control  = (playType<<16) | control;
      kal_uint16 sc_mode = 0, sd_mode = 0;
      kal_uint16 codec_mode = 0;
      kal_uint16 amr_sd_mode = (control&0x3C) >> 2;
#if defined(AMRWB_DECODE)      
      kal_uint16 awb_sd_mode = (control&0xFC) >> 2;
#endif       
      kal_uint16 samplingrate = 0;

      if( ((0x03<=amr_sd_mode) && (0x0A>=amr_sd_mode)))
      { // AMR
         Media_SetSampleRate(8000);
         Media_SetAudioFormat(MEDIA_FORMAT_AMR);
#if defined(AUDIO_AMR_RUNS_SPPECH_PATH_ON)
         DSP_DynamicDownload( DDID_NONE );   // remove AMRSBCDDID_AMRSBC
#else
         DSP_DynamicDownload( DDID_AMRSBC );
#endif         
         codec_mode = ASP_TYPE_AMR;
         sc_mode = (vm_control>>2) & 0xF;
         sd_mode = (vm_control>>6) & 0xF;
         samplingrate = ASP_FS_8K;
#if defined(__AUDIO_BT_FORCE_VBI_RESET__)
         AM_BT_Force_VBI_Reset(KAL_TRUE);
#endif
      }
#if defined(AMRWB_DECODE)
      else if ((0x20<=awb_sd_mode) && (0x28>=awb_sd_mode))
      {  // AWB
         Media_SetSampleRate(16000);
         Media_SetAudioFormat(MEDIA_FORMAT_AMR_WB);
         DSP_DynamicDownload(DDID_AWBDEC);
         codec_mode = ASP_TYPE_AWBDEC;
         sc_mode = (vm_control>>2) & 0xFF;
         sd_mode = 0;
         samplingrate = ASP_FS_16K;
      }
#endif
      if( sc_mode == 0 )
         sc_mode = sd_mode;
      if( sd_mode == 0 )
         sd_mode = sc_mode;

      *AMR_AWB_AUDIO_PATH_CTRL = 0x40;
      if( sc_mode > 2){
#if AMR_NEW_PATH       
       *AMR_PARAM1 = 0x622;
#else
       *AMR_PARAM1 = 0x1622;
#endif       
      }else{
          *AMR_PARAM1 = 0x2622;
      }
#if !AMR_NEW_PATH   
      *AMR_PARAM2 = sd_mode | (sc_mode << 8);
#endif 
      *DSP_AUDIO_FLEXI_CTRL = (FLEXI_VBI_ENABLE | FLEXI_SD_ENABLE);
      AM_AudioPlaybackOn( codec_mode, samplingrate);
   }
#else 
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
// MT6260 does not support VM playback
#else 
    AM_VMPlaybackOn( wCodecMode, playType);
#endif
#endif
}


static void AmrDec_OpenDevice(AudComHdlInt *ihdl)
{
   AMR_DecData *pDecData = (AMR_DecData *)ihdl->pPrivateData;
   kal_uint16 wCodecMode;

#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   VIBR_Vibration_Deactivate();
#endif
   
   mhdlDisallowSleep_Id(ihdl->aud_id);
   
   ClearDSPAudioCommonFlag();
   
   ihdl->endStatus = MEDIA_NONE; // Clear for streaming case
   ihdl->dsp_rb_base = 0;
   
   wCodecMode = amr_SetAndGetInitialCodecMode( ihdl );

   // Hook Hisr Handler
#if defined(__VAD_SUPPORT__)
   L1Audio_HookHisrHandler( DP_D2C_3G_DONE_DL, AmrBabyMonitorDecHisrHandler, (void *)ihdl );
#else
   amr_write_speech_mode_to_dsp( ihdl, 0 );
   L1Audio_HookHisrHandler( DP_D2C_SD_DONE, AmrDecHisrHandler, (void *)ihdl );
#endif

   // Stop DSP activity
   KT_StopAndWait();
   TONE_StopAndWait();    

#if !defined(__VAD_SUPPORT__)
   // Hook PCM Route
   PcmRut_RegGetComponent( (AudComHdl *)ihdl );
   MH_RegPutComponent( (AudComHdl *)ihdl );
#endif

   Media_SetIsDSPDec(KAL_TRUE);

#if !defined(__VAD_SUPPORT__)
#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   Media_SetIsAlwaysRoute(KAL_TRUE);
   PcmRut_Start(0);
#endif

   APM_Hook_PcmRut();
#endif
   
   amrOpenDeviceCommon (wCodecMode , pDecData->vm);
 
#if defined(AMRWB_DECODE) 
   if (MEDIA_FORMAT_AMR_WB == ihdl->mediaType ){
      kal_uint32 I;
      kal_uint16 ctl;
      volatile kal_uint16* ptr;

      *DSP_AWB_SD_CTRL = DSP_INITIALIZED;
      ptr = DSP_AWB_SD_CTRL;
      for( I = 0; ; I++ ) {
         ctl = *ptr;
         if( ctl == DSP_PLAYING ){                /* DSP returns to idle state */
            kal_trace( TRACE_STATE, L1AUDIO_RUNNING_STATE );
            break;
         }
         ASSERT_REBOOT( I < 20 );
         kal_sleep_task( 2 );
      }
   }
#endif

#if AMR_AWB_AUDIO_PATH_SUPPORT
   {
      kal_uint32 uCnt;
      for( uCnt = 0; ; uCnt++ ) {
         if( *AMR_AWB_AUDIO_PATH_CTRL == 0 ){
            break;
         }
         ASSERT_REBOOT( uCnt < 20 );
         kal_sleep_task( 2 );
      }
   }
#endif // AMR_AWB_AUDIO_PATH_SUPPORT
   
}

static void AmrDec_CloseDevice(AudComHdlInt *ihdl)
{   
#if defined(AMRWB_DECODE)
   if(MEDIA_FORMAT_AMR_WB == ihdl->mediaType)
      amr_WBStopCtrl( ihdl, true );
#endif

#if defined(__AUDIO_BT_FORCE_VBI_RESET__)
   AM_BT_Force_VBI_Reset(KAL_FALSE);
#endif

#if defined(__VAD_SUPPORT__)

  #if defined(__VM_CODEC_SUPPORT__)
   if (fAmrBabyMonitorDebug)
   {
      kal_uint32 voc_pattern = TVCI_CLOSE_FILE;
      kal_uint32 *voc_ptr = &voc_pattern;
      
      vmStop(NULL);
      tst_vc_response(TVCI_VM_LOGGING, (const kal_uint8*)voc_ptr, 4);
      fAmrBabyMonitorDebug = KAL_FALSE;
   }
  #endif
   AM_BabyMonitor_PlaybackOff();

#else
#if AMR_AWB_AUDIO_PATH_SUPPORT
   AM_AudioPlaybackOff( true );
   *DSP_AUDIO_FLEXI_CTRL = 0;
#else 
  #if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
// MT6260 does not support VM playback
  #else  
   { 
      AMR_DecData *pDecData = (AMR_DecData *)ihdl->pPrivateData;
      AM_VMPlaybackOff(pDecData->vm);
   }
  #endif 
#endif // AMR_AWB_AUDIO_PATH_SUPPORT
#endif // defined(__VAD_SUPPORT__)
 
#if !defined(__VAD_SUPPORT__)
   // Unhook PCM Route
   if(Is_PutPcmrutOn())
      PcmRut_Stop();
   PcmRut_UnregGetComponent( (AudComHdl *)ihdl );
   MH_UnregPutComponent( (AudComHdl *)ihdl );
#endif
   
#if defined(__BES_TS_SUPPORT__)
   //clear dsp decode flag when playback off
   if(AudioPP_TS_GetSpeed()!=0)
      AudioPP_TS_ClearDSPreg();
#endif

   //Clear DSP decode flag when close device
   Media_SetIsDSPDec(KAL_FALSE);

#if !defined(__VAD_SUPPORT__)
#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   Media_SetIsAlwaysRoute(KAL_FALSE);
#endif
#endif

   mhdlAllowSleep_Id( ihdl->aud_id );
   
#if defined(__VAD_SUPPORT__)
   L1Audio_UnhookHisrHandler(DP_D2C_3G_DONE_DL);
#else
   L1Audio_UnhookHisrHandler(DP_D2C_SD_DONE);
#endif
   
#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   if(!VIBR_IsPlayingDummy())
   {
      VIBR_Vibration_Activate();
   }
#endif //__VIBRATION_SPEAKER_SUPPORT__    
}
#endif

/*------------------------------------------------*/
/* The private member functions of AMR decoder.   */
/*------------------------------------------------*/

static OMX_ERRORTYPE AmrDec_Start(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   AMR_DecData *pDecData = (AMR_DecData *)ihdl->pPrivateData;
   
   ihdl->isEOF = KAL_FALSE;
   ihdl->Decode_EOF = KAL_FALSE;
   ihdl->isDspDecodeEOF =KAL_FALSE;
   ihdl->isEOFSet = KAL_FALSE; 
   
   if(ihdl->mhdl){
   	  ihdl->mhdl->isUnderflow = KAL_FALSE;
   }   

   PcmSink_TerminateSound();
   
   if (ihdl->mediaStatus == COMPONENT_STATE_PLAY) {
      return OMX_ErrorIncorrectStateOperation;
   }

#if VERIFY_AVSYNC
   ut_a2v_play_dsp_start();
#endif
   
   if (pDecData->bWideBand) 
      ihdl->mediaType = MEDIA_FORMAT_AMR_WB;   
   
   ACU_LoadResumeInfo(hdl);
   AmrDec_OpenDevice(ihdl);
   
   ihdl->mediaStatus = COMPONENT_STATE_PLAY;
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE AmrDec_Stop(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   
   if (ihdl->mediaStatus == COMPONENT_STATE_PLAY) {
   	  ihdl->bsInfo.pResBuf = NULL;
      ihdl->mediaStatus = COMPONENT_STATE_IDLE;
      ihdl->endStatus = MEDIA_TERMINATED;
   } else {
      // Avoid re-entrance
      return OMX_ErrorNone;
   }

   PcmSink_Mute(KAL_TRUE, PCMSINK_MUTE_PCMSINK);
   
   if(!Is_PutPcmrutOn()){
      AFE_SetHardwareMute(true);
   }

#if VERIFY_AVSYNC
   ut_a2v_dsp_stop();
#endif
      
   AmrDec_CloseDevice(ihdl);
   kal_trace( TRACE_FUNC, L1AUDIO_STOP, ihdl->mediaType );

   return OMX_ErrorNone;
}


static OMX_ERRORTYPE AmrDec_Deinit(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   
   ACU_FlushBufferQueue(hdl);
   L1Audio_FreeAudioID( ihdl->aud_id );
   
   kal_trace( TRACE_FUNC, L1AUDIO_CLOSE, ihdl->mediaType );
   
   return OMX_ErrorNone;
}


/*------------------------------------------------*/
/* The public functions of AMR decoder.           */
/*------------------------------------------------*/
static OMX_ERRORTYPE AmrDec_SetParameter(AudComHdl *hdl, OMX_INDEXTYPE index, OMX_PTR pStruct)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   AMR_DecData *pDecData = (AMR_DecData *)ihdl->pPrivateData;
   switch (index) 
   {
      case OMX_IndexParamAudioAmr:
         {
            AMR_FrameInfo *pParam = (AMR_FrameInfo *)pStruct;
            pDecData->bWideBand = pParam->bIsWideBand;
         }
         break;
      case OMX_IndexParamMediaTekAudioVm:
      	 {
      	 	  AMR_FrameInfo *pParam = (AMR_FrameInfo *)pStruct;
      	 	  pDecData->vm = pParam ->vm;
      	 }
      default:
         return OMX_ErrorNotImplemented;
   }
   return OMX_ErrorNone;
}


OMX_U32 AmrDec_GetMemSize( void )
{
   OMX_U32 uTempSize, uReqSizeTotal;
   uReqSizeTotal = 0;
   
   // The memory size for AudComHdlInt
   uTempSize = (sizeof(AudComHdlInt) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   
   // The memory for AMR private data
   uTempSize = (sizeof(AMR_DecData) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   
   return uReqSizeTotal;
}

OMX_ERRORTYPE AmrDec_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
)
{
   OMX_U32 uBufSize;
   AudComHdlInt *ihdl;
   kal_uint8 *pBuffer8;
   
   *pHandle = NULL;
   
   // The buffer address should be 4 bytes aligned
   ASSERT( (((kal_uint32)pBuffer) & 0x3) == 0);
   
   // Empty the memory
   uBufSize = AmrDec_GetMemSize();
   memset(pBuffer, 0, uBufSize);
   
   // Assign and distribute the memory
   *pHandle = pBuffer;
   pBuffer8 = (kal_uint8 *)pBuffer;
   ihdl = (AudComHdlInt *)pBuffer;
   pBuffer8 += (sizeof(AudComHdlInt) + 3) & ~0x3;
   ihdl->pPrivateData = (void *)pBuffer8;
   pBuffer8 += (sizeof(AMR_DecData) + 3) & ~0x3;
     
   ihdl->mediaType = MEDIA_FORMAT_AMR;
   
   // Initialize the audio handler as default setting
   ACU_InitHdl(*pHandle, pFWData, pCallback);
   
   // Overwrite the member functions
   ihdl->basic.Start = AmrDec_Start;
   ihdl->basic.Stop = AmrDec_Stop;
   ihdl->basic.Deinit = AmrDec_Deinit;
   ihdl->basic.SetParameter = AmrDec_SetParameter;
   ihdl->basic.Process      = ACU_DSPDecoderProcess; 

   // Obtain l1audio service
   // KH: should re-organize
   AFE_SetDigitalGain( L1SP_AUDIO, 100 );
   AFE_SetDigitalGain( L1SP_VOICE, 100 );
   ihdl->aud_id = L1Audio_GetAudioID();
   L1Audio_SetEventHandler( ihdl->aud_id, mhdlCallbackTask );

   return OMX_ErrorNone;
}

#endif
