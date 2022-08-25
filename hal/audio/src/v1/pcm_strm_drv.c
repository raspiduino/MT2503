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
 * pcm_strm.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Streaming PCM Playback and Record
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

#ifndef __L1_STANDALONE__ // avoid link error

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "audio_enum.h"
#include "reg_base.h"
#include "l1d_reg.h"
#include "string.h"
#include "kal_trace.h"

#include "l1audio.h"
#include "audio_def.h"
#include "speech_def.h"
#include "common_def.h"
#include "l1sp_trc.h"
#include "media.h"
#include "wav.h"
#include "ddload.h"
#include "am.h"
#include "speech_enh_def.h"

#if defined(MT6253)
#include "custom_EMI_release.h"
#endif

#if defined(WAV_CODEC)

#if defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00)
#define PAGE_NUM 2
#elif defined(MT6253) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
#define PAGE_NUM 1
#elif defined(MT6256_S01) || defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
#define PAGE_NUM 5
#else
#error The new chip should define DM page number
#endif

#define WAV_ABORT_STATE 0x40

#define FRAME_BUF_SIZE 160

// This flag is for DSP to record stereo PCM in dedicated mode
// #define  DSP_DEBUG_DEDICATED_MODE_RECORD


typedef struct pcmStrm_Internal {
   kal_bool         isPlayback;        // true:Playback, false:Record
   kal_bool         isStereo;
   kal_bool         dedicated_mode;
   kal_bool         is8KVoice;
   kal_int8         bitPerSample;
   kal_uint8        freqType;
   kal_uint16       sampleFreq;
   kal_uint16       dsp_last_sample_p;
   kal_uint16       dsp_last_sample;
} pcmStrmInternal;

typedef struct pcmStrm_MediaHdlInternal {
   MHdl             mh;
   pcmStrmInternal  pcmStrm;
   Media_Event      end_status;
   kal_uint32       accumulateSize;    // In sample
   kal_uint32       accumulateTime;    // In milli-second
   kal_uint16       frameDuration;

   // EOF handling
   kal_bool         decode_EOF;
   kal_int32        zeroCount;
} pcmStrmMediaHdl;

#pragma arm section code="SECONDARY_ROCODE"

#if !(defined(__WAV_DECODE_SWIP__) && !defined(MED_NOT_PRESENT))
static void pcmWriteDataSegmentByIDMA(pcmStrmMediaHdl *ihdl, int32 DSP_FreeSeg)
{
   uint16 *buf;
   uint16 dsp_last_sample = 0, dsp_last_sample_p = 0, dsp_w = 0, read_data = 0;
   int32 I;
#ifdef L1AUDIO_IDMA_ALL_ADDRESS_MODE
   volatile uint16* idmaPtr;
#endif
   dsp_w = *DSP_PCM_W;

   buf = (uint16 *)&ihdl->mh.rbInfo.rb_base[ihdl->mh.rbInfo.read];

   if (ihdl->mh.mono2stereo){
      if (ihdl->pcmStrm.bitPerSample == 16) {
	       IDMA_WriteToDSP_Duplicate(DSP_DM_ADDR(PAGE_NUM, ihdl->mh.dsp_rb_base + dsp_w), buf, DSP_FreeSeg );
         buf+=DSP_FreeSeg>>1;
         dsp_last_sample = dsp_last_sample_p = *(--buf);
         ihdl->mh.rbInfo.read += (DSP_FreeSeg);
      } else {
#ifdef L1AUDIO_IDMA_ALL_ADDRESS_MODE
         idmaPtr=DSP_DM_ADDR(PAGE_NUM, ihdl->mh.dsp_rb_base + dsp_w);
         for (I=DSP_FreeSeg; I>0; I-=4) {
            read_data = *buf++;
            dsp_last_sample = (read_data<<8) - 0x8000;
            *idmaPtr++= dsp_last_sample;
            *idmaPtr++= dsp_last_sample;
            dsp_last_sample = (read_data & 0xFF00) - 0x8000;   	
            *idmaPtr++= dsp_last_sample;
            *idmaPtr++= dsp_last_sample;
         }
#else
         read_data = *buf++;
         dsp_last_sample = (read_data<<8) - 0x8000;
         *DSP_DM_ADDR(PAGE_NUM, ihdl->mh.dsp_rb_base + dsp_w) = dsp_last_sample;
         *IDMA_SHORT_ADDR = dsp_last_sample;
         dsp_last_sample = (read_data & 0xFF00) - 0x8000;   	
         *IDMA_SHORT_ADDR = dsp_last_sample;
         *IDMA_SHORT_ADDR = dsp_last_sample;
         for (I=DSP_FreeSeg-4; I>0; I-=4) {
            read_data = *buf++;
            dsp_last_sample = (read_data<<8) - 0x8000;
            *IDMA_SHORT_ADDR = dsp_last_sample;
            *IDMA_SHORT_ADDR = dsp_last_sample;
            dsp_last_sample = (read_data & 0xFF00) - 0x8000;   	
            *IDMA_SHORT_ADDR = dsp_last_sample;
            *IDMA_SHORT_ADDR = dsp_last_sample;
         }
#endif
         dsp_last_sample_p = dsp_last_sample;
         ihdl->mh.rbInfo.read += (DSP_FreeSeg >> 1);
      }
   } else {
      if (ihdl->pcmStrm.bitPerSample == 16) {
         IDMA_WriteToDSP(DSP_DM_ADDR(PAGE_NUM, ihdl->mh.dsp_rb_base + dsp_w), buf, DSP_FreeSeg);
	       buf+=DSP_FreeSeg;
         ihdl->mh.rbInfo.read += (DSP_FreeSeg << 1);
         dsp_last_sample = *(--buf);
         dsp_last_sample_p = *(--buf);
      } else {
#ifdef L1AUDIO_IDMA_ALL_ADDRESS_MODE
         {
            idmaPtr=DSP_DM_ADDR(PAGE_NUM, ihdl->mh.dsp_rb_base + dsp_w);
            for (I=DSP_FreeSeg; I>0; I-=2) 
	     {
               read_data = *buf++;
               *idmaPtr++ = (read_data<<8) - 0x8000;
               *idmaPtr++ = (read_data & 0xFF00) - 0x8000;
	     }
         }
#else
         read_data = *buf++;
         *DSP_DM_ADDR(PAGE_NUM, ihdl->mh.dsp_rb_base + dsp_w) = (read_data<<8) - 0x8000;
         *IDMA_SHORT_ADDR = (read_data & 0xFF00) - 0x8000;
         for (I=DSP_FreeSeg-2; I>0; I-=2) 
	  {
            read_data = *buf++;
            *IDMA_SHORT_ADDR = (read_data<<8) - 0x8000;
            *IDMA_SHORT_ADDR = (read_data & 0xFF00) - 0x8000;
	  }
#endif
         ihdl->mh.rbInfo.read += (DSP_FreeSeg);
         dsp_last_sample_p = (read_data<<8) - 0x8000;
         dsp_last_sample = (read_data & 0xFF00) - 0x8000;
      }
   }
   ihdl->pcmStrm.dsp_last_sample_p = dsp_last_sample_p;
   ihdl->pcmStrm.dsp_last_sample = dsp_last_sample;
   ihdl->accumulateSize += DSP_FreeSeg;
   ihdl->mh.current_time += ((kal_uint64)DSP_FreeSeg * 1000 ) / ( ihdl->pcmStrm.sampleFreq * 2);   
}

static void pcmWriteDataByIDMA(pcmStrmMediaHdl *ihdl, int32 mbDecodeLen)
{
   int32 count, DSP_FreeLenLow, dsp_r, DSP_FreeLen;
   uint16 dsp_w;

   dsp_w = *DSP_PCM_W;

   do {
      dsp_r = (int32)*DSP_PCM_R;
   } while( dsp_r != (int32)*DSP_PCM_R );

   DSP_FreeLen = dsp_r - (int32)dsp_w - 1;
   if ( DSP_FreeLen < 0 )
      DSP_FreeLen += ihdl->mh.dsp_rb_size;

   if (ihdl->mh.mono2stereo){
      mbDecodeLen <<= 1;
      DSP_FreeLen &= 0xFFFC;
   } else {
      DSP_FreeLen &= 0xFFFE;
   }

   if ( DSP_FreeLen < mbDecodeLen )
      mbDecodeLen = DSP_FreeLen;

   if ( mbDecodeLen == 0 )
      return;

   DSP_FreeLenLow = (int32)(ihdl->mh.dsp_rb_size - dsp_w);
   if ( DSP_FreeLenLow > mbDecodeLen )
      DSP_FreeLenLow = mbDecodeLen;

   pcmWriteDataSegmentByIDMA(ihdl, DSP_FreeLenLow);
   kal_dev_trace( TRACE_FUNC, L1AUDIO_PCM_STRM_WDATA_IDMA, (dsp_w+ihdl->mh.dsp_rb_base), DSP_FreeLenLow );

   dsp_w += (uint16)DSP_FreeLenLow;
   if ( dsp_w >= ihdl->mh.dsp_rb_size )
      dsp_w = 0;

   *DSP_PCM_W = dsp_w;
   count = mbDecodeLen - DSP_FreeLenLow;

   if ( count > 0 ) {
      pcmWriteDataSegmentByIDMA(ihdl, count);
      *DSP_PCM_W = dsp_w + (uint16)count;
      kal_dev_trace( TRACE_FUNC, L1AUDIO_PCM_STRM_WDATA_IDMA, (dsp_w+ihdl->mh.dsp_rb_base), count );
   }
}

static void pcmWriteDataToDSP(pcmStrmMediaHdl *ihdl)
{
   int32 mbDataLen, mbDataLenLow, mbDataLenHigh;

   if (ihdl->pcmStrm.bitPerSample == 16) {
      mbDataLen = ihdl->mh.GetDataCount((MHdl *)ihdl) >> 1;      // in word
      mbDataLenLow = (ihdl->mh.rbInfo.rb_size - ihdl->mh.rbInfo.read) >> 1;    // in word
   } else {
      mbDataLen = ihdl->mh.GetDataCount((MHdl *)ihdl);           // decoded size in word
      mbDataLenLow = (ihdl->mh.rbInfo.rb_size - ihdl->mh.rbInfo.read);         // decoded size in word
      mbDataLenLow &= 0xFFFE;
      mbDataLen &= 0xFFFE;
   }

   if( mbDataLenLow > mbDataLen )
      mbDataLenLow = mbDataLen;
   mbDataLenHigh = mbDataLen - mbDataLenLow;

   pcmWriteDataByIDMA( ihdl, mbDataLenLow );

   ASSERT(ihdl->mh.rbInfo.read <= ihdl->mh.rbInfo.rb_size);
   if( ihdl->mh.rbInfo.read >= ihdl->mh.rbInfo.rb_size ){
      ihdl->mh.rbInfo.read = 0;
      if( mbDataLenHigh > 0 )
         pcmWriteDataByIDMA( ihdl, mbDataLenHigh );
   }
}

static void pcmStrmHisr( void *data )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)data;
   kal_int16 rb_w, rb_r_cache, tmp1;
#if defined(_DSP_INTERSHAREMEM_EN_)    
   *DP2_AUDIO_ASP_TASK4_DM_HANDSHAKE = 0; 
#endif
   if( ihdl->end_status == MEDIA_TERMINATED )
      return;

   if( *DSP_PCM_CTRL == 0 ) {  // DSP in idle state
      ihdl->end_status = MEDIA_TERMINATED;
      kal_dev_trace( TRACE_STATE, L1AUDIO_PCM_STRM_IDLE );
      mhdlException( (MHdl*)ihdl, MEDIA_END );
      return;
   }

   if( ihdl->end_status == MEDIA_END )
      return;

   if (ihdl->decode_EOF) {
      if (ihdl->zeroCount > 0) {
         kal_int32 count;
         count = autPutSilenceToDSP2( ihdl->mh.dsp_rb_base, ihdl->mh.dsp_rb_size, ihdl->pcmStrm.dsp_last_sample_p, ihdl->pcmStrm.dsp_last_sample);
         ihdl->zeroCount -= count;
      }
      
      if (ihdl->zeroCount <= 0) {
         ihdl->end_status = MEDIA_END;
         if( *DSP_PCM_CTRL == 8) {
            *DSP_PCM_CTRL = 0x10;
            kal_dev_trace( TRACE_STATE, L1AUDIO_PCM_STRM_END );
         }
      }
      return;
   }

   if( *DSP_PCM_CTRL == 2 ) {   // DSP RingBuf initialization
      kal_dev_trace( TRACE_STATE, L1AUDIO_PCM_STRM_RUN );
      ihdl->mh.dsp_rb_base = *DSP_PCM_W;
      ihdl->mh.dsp_rb_size = *DSP_PCM_R;
      ihdl->mh.dsp_rb_end = ihdl->mh.dsp_rb_base + ihdl->mh.dsp_rb_size;
      *DSP_PCM_W = 0;
      *DSP_PCM_R = 0;
      *DSP_PCM_CTRL = 4;
   }

   do {
      rb_r_cache = (int16)*DSP_PCM_R;
   } while( rb_r_cache != (int16)*DSP_PCM_R );

   pcmWriteDataToDSP(ihdl);

   if( ((ihdl->mh.eof) && (ihdl->mh.GetDataCount((MHdl*)ihdl) <= 1)) ||
       (ihdl->mh.current_time >= ihdl->mh.stop_time)) {
      ihdl->decode_EOF = true;
      ihdl->zeroCount = autGetDSPDataCnt(ihdl->mh.dsp_rb_size); 
      //ihdl->zeroCount = wavGetDSPDataCnt(ihdl->mh.dsp_rb_size);
   }

   // fill silence, Media Buffer underflow
   rb_w = (int16)*DSP_PCM_W;
   rb_r_cache = rb_r_cache - rb_w - 1;
   if ( rb_r_cache < 0 )
      rb_r_cache += (int16)ihdl->mh.dsp_rb_size;
   rb_r_cache &= 0xFFFC;

   if (rb_r_cache)   // if MCU should fill silence to DSP...
   {
      tmp1 = (int16)ihdl->mh.dsp_rb_size - rb_w;
      kal_dev_trace( TRACE_FUNC, L1AUDIO_PCM_STRM_SILENCE, tmp1 );

      if (rb_r_cache > tmp1)
      {
         putSilence2(ihdl->mh.dsp_rb_base, ihdl->mh.dsp_rb_size, ihdl->pcmStrm.dsp_last_sample_p, ihdl->pcmStrm.dsp_last_sample, tmp1);
         //PutSilence( ihdl, tmp1 );
         rb_r_cache -= tmp1;
      }
      putSilence2(ihdl->mh.dsp_rb_base, ihdl->mh.dsp_rb_size, ihdl->pcmStrm.dsp_last_sample_p, ihdl->pcmStrm.dsp_last_sample, rb_r_cache);
      //PutSilence( ihdl, rb_r_cache );

      if(ihdl->mh.isUnderflow == KAL_FALSE && !ihdl->mh.eof && ihdl->mh.waiting)
      {
   	     ihdl->mh.isUnderflow = KAL_TRUE;
   	     mhdlException( (MHdl*)ihdl, MEDIA_BUFFER_UNDERFLOW );
         return;
      }
   }

   mhdlDataRequest((MHdl*)ihdl, ihdl->end_status);
//   ihdl->mh.current_time += ihdl->frameDuration;
}

#endif

static void pcmReadDataSegment(pcmStrmMediaHdl *ihdl)
{
   int16 *buf = (int16 *)&ihdl->mh.rbInfo.rb_base[ihdl->mh.rbInfo.write];

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
    if (ihdl->pcmStrm.dedicated_mode)
    {   // WAV recording in TCH mode
        uint32 UL_frm_size = Pseudo_SAL_PcmEx_GetBufLen(PSEUDO_SAL_PCMEX_BUF_SE);
        uint32 DL_frm_size = Pseudo_SAL_PcmEx_GetBufLen(PSEUDO_SAL_PCMEX_BUF_SD);
        ASSERT(UL_frm_size == FRAME_BUF_SIZE);  // Check uplink frame size
        ASSERT(DL_frm_size == FRAME_BUF_SIZE);  // Check uplink frame size

#ifdef DSP_DEBUG_DEDICATED_MODE_RECORD
        {   // Read uplink data to L channel
            volatile uint16 *dspAddr = Pseudo_SAL_PcmEx_GetBuf(PSEUDO_SAL_PCMEX_BUF_SE);
            IDMA_ReadFromDSP_Skip_1((kal_uint16 *)(buf + 0), dspAddr, UL_frm_size);
        }
        
        {   // Read downlink data to R channel
            volatile uint16 *dspAddr = Pseudo_SAL_PcmEx_GetBuf(PSEUDO_SAL_PCMEX_BUF_SD);
            IDMA_ReadFromDSP_Skip_1((kal_uint16 *)(buf + 1), dspAddr, DL_frm_size);
        }
#else   // not debug mode

        // Read from uplink
        {
            volatile uint16 *dspAddr = Pseudo_SAL_PcmEx_GetBuf(PSEUDO_SAL_PCMEX_BUF_SE);
            IDMA_ReadFromDSP((kal_uint16 *)buf, dspAddr, UL_frm_size);
        }
    
#ifndef BOUNDED
#define BOUNDED(in,up,lo) ((in) > (up) ? (up) : (in) < (lo) ? (lo) : (in))
#endif

        // Add back to downlink
#ifdef L1AUDIO_IDMA_ALL_ADDRESS_MODE
        {   // all address mode
            volatile uint16 *dspAddr = Pseudo_SAL_PcmEx_GetBuf(PSEUDO_SAL_PCMEX_BUF_SD);
            int32 I;
            int32 tmp;
        
            for (I = DL_frm_size; I > 0; I--)
            {
                tmp = *buf + (int32)(int16)*dspAddr++;
                *buf++ = (int16)BOUNDED(tmp, 32767, -32768);
            }
        }
#else
        {   //  short mode
            volatile uint16 *dspAddr = Pseudo_SAL_PcmEx_GetBuf(PSEUDO_SAL_PCMEX_BUF_SD);
            int32 I;
            int32 tmp = (int32)*dspAddr;    // Dummy read for short mode
            
            for (I = DL_frm_size; I > 0; I--)
            {
                tmp = *buf + (int32)(int16)*IDMA_SHORT_ADDR;
                *buf++ = (int16)BOUNDED(tmp, 32767, -32768);
            }
        }
#endif //L1AUDIO_IDMA_ALL_ADDRESS_MODE

#endif  // debug mode or not
    }
    else
    {
        uint32 framesize         = Pseudo_SAL_PcmEx_GetBufLen(PSEUDO_SAL_PCMEX_BUF_SE);
        volatile uint16 *dspAddr = Pseudo_SAL_PcmEx_GetBuf   (PSEUDO_SAL_PCMEX_BUF_SE);
        IDMA_ReadFromDSP((kal_uint16 *)buf, dspAddr, framesize);
        buf += framesize;
    }
#else   // chip compile option
   if (ihdl->pcmStrm.dedicated_mode){    // WAV recording in TCH mode
      int32 first_data_block_len, second_data_block_len;
      int32 I, tmp;
      ASSERT( *DP_TCH_UL_LEN == FRAME_BUF_SIZE );   // uplink frame size
      ASSERT( *DP_TCH_DL_LEN == FRAME_BUF_SIZE );   // downlink frame size

#ifdef DSP_DEBUG_DEDICATED_MODE_RECORD
      // Uplink
      first_data_block_len = (int16)*DP_TCH_UL_BUF_LEN - ((int16)*DP_TCH_UL_PTR - (int16)*DP_TCH_UL_BUF_ADDR0);
      if ( first_data_block_len < FRAME_BUF_SIZE ) {
         second_data_block_len = FRAME_BUF_SIZE - first_data_block_len;
      } else {
         first_data_block_len = FRAME_BUF_SIZE;
         second_data_block_len = 0;
      }

      IDMA_ReadFromDSP_Skip_1((uint16*)buf, DSP_DM_ADDR(PAGE_NUM, *DP_TCH_UL_PTR), (uint32)first_data_block_len);
      buf+=(uint32) first_data_block_len<<1;
      
      if ( second_data_block_len > 0 ) {
         IDMA_ReadFromDSP_Skip_1((uint16*)buf, DSP_DM_ADDR(PAGE_NUM, *DP_TCH_UL_BUF_ADDR0), (uint32)second_data_block_len);
         buf+=(uint32) second_data_block_len<<1;
       }
      
      // Downlink
      buf -= ((FRAME_BUF_SIZE << 1) - 1);
      first_data_block_len = (int16)*DP_TCH_DL_BUF_LEN - ((int16)*DP_TCH_DL_PTR - (int16)*DP_TCH_DL_BUF_ADDR0);
      if ( first_data_block_len < FRAME_BUF_SIZE ) {
         second_data_block_len = FRAME_BUF_SIZE - first_data_block_len;
      } else {
         first_data_block_len = FRAME_BUF_SIZE;
         second_data_block_len = 0;
      }

      IDMA_ReadFromDSP_Skip_1((uint16*)buf, DSP_DM_ADDR(PAGE_NUM, *DP_TCH_DL_PTR), (uint32)first_data_block_len);
      buf+=(uint32) first_data_block_len<<1;     

      if ( second_data_block_len > 0 ) {
         IDMA_ReadFromDSP_Skip_1((uint16*)buf, DSP_DM_ADDR(PAGE_NUM, *DP_TCH_DL_BUF_ADDR0), (uint32)second_data_block_len);
         buf+=(uint32) second_data_block_len<<1;
      }
#else
      // handle uplink data
      first_data_block_len = (int16)*DP_TCH_UL_BUF_LEN - ((int16)*DP_TCH_UL_PTR - (int16)*DP_TCH_UL_BUF_ADDR0);
      if ( first_data_block_len < FRAME_BUF_SIZE ) {
         second_data_block_len = FRAME_BUF_SIZE - first_data_block_len;
      } else {
         first_data_block_len = FRAME_BUF_SIZE;
         second_data_block_len = 0;
      }

      IDMA_ReadFromDSP((uint16*)buf, DSP_DM_ADDR(PAGE_NUM, *DP_TCH_UL_PTR), (uint32)first_data_block_len);
      buf+=(uint32)first_data_block_len;
      if (second_data_block_len > 0 ) {
         IDMA_ReadFromDSP((uint16*)buf, DSP_DM_ADDR(PAGE_NUM, *DP_TCH_UL_BUF_ADDR0), (uint32)second_data_block_len);
         buf+=(uint32)second_data_block_len;		 
    }

      // handle downlink data
      buf -= FRAME_BUF_SIZE;
      first_data_block_len = (int16)*DP_TCH_DL_BUF_LEN - ((int16)*DP_TCH_DL_PTR - (int16)*DP_TCH_DL_BUF_ADDR0);
      if ( first_data_block_len < FRAME_BUF_SIZE ) {
         second_data_block_len = FRAME_BUF_SIZE - first_data_block_len;
      } else {
         first_data_block_len = FRAME_BUF_SIZE;
         second_data_block_len = 0;
      }

      // Mix Uplink and Download
#ifdef L1AUDIO_IDMA_ALL_ADDRESS_MODE
      {
         volatile uint16 *idmaPtr;
         idmaPtr=DSP_DM_ADDR(PAGE_NUM, *DP_TCH_DL_PTR);
         for ( I = first_data_block_len; I > 0; I-- )
	  {
            tmp = *buf + (int32)(int16)*idmaPtr++;
            *buf++ = (int16)(( tmp > 32767 )? 32767: (tmp < -32768)? -32768:tmp);
         }
         if ( second_data_block_len > 0 )
	  {
	     idmaPtr=DSP_DM_ADDR(PAGE_NUM, *DP_TCH_DL_BUF_ADDR0);
            for ( I = second_data_block_len; I > 0; I-- )
	     {
               tmp = *buf + (int32)(int16)*idmaPtr++;
               *buf++ = (int16)(( tmp > 32767 )? 32767: (tmp < -32768)? -32768:tmp);
            }
         }
      }
#else
      tmp = *DSP_DM_ADDR(PAGE_NUM, *DP_TCH_DL_PTR);
      for ( I = first_data_block_len; I > 0; I-- ) {
         tmp = *buf + (int32)(int16)*IDMA_SHORT_ADDR;
         *buf++ = (int16)(( tmp > 32767 )? 32767: (tmp < -32768)? -32768:tmp);
      }
      if ( second_data_block_len > 0 ) {
         tmp = *DSP_DM_ADDR(PAGE_NUM, *DP_TCH_DL_BUF_ADDR0);
         for ( I = second_data_block_len; I > 0; I-- ) {
            tmp = *buf + (int32)(int16)*IDMA_SHORT_ADDR;
            *buf++ = (int16)(( tmp > 32767 )? 32767: (tmp < -32768)? -32768:tmp);
         }
      }
#endif //L1AUDIO_IDMA_ALL_ADDRESS_MODE	

#endif
   } else {
      int32 count = (int32)(*DSP_PCM_REC_LEN);
      IDMA_ReadFromDSP((uint16*)buf, DSP_DM_ADDR(PAGE_NUM, *DSP_PCM_REC_ADDR), (uint32)count);
      buf+=(uint32)count;  
   }

#endif  // chip compile option

   // Update media buffer write pointer
   {
      MHdl *hdl = (MHdl *) ihdl;
#ifdef DSP_DEBUG_DEDICATED_MODE_RECORD
      if (ihdl->pcmStrm.dedicated_mode) {
         hdl->WriteDataDone(hdl, (FRAME_BUF_SIZE << 2));
      } else {
         hdl->WriteDataDone(hdl, (FRAME_BUF_SIZE << 1));
      }
#else
      hdl->WriteDataDone(hdl, (FRAME_BUF_SIZE << 1));
#endif
      hdl->waiting = KAL_FALSE;
   }
}

static void pcmReadDataFromDSP(pcmStrmMediaHdl *ihdl)
{
   int32 dspRecLen, count;
   MHdl *hdl = (MHdl *) ihdl;

   count = hdl->GetFreeSpace(hdl);  // In byte
   count = (count >> 1);            // In word


   // Check the remaind media buffer size
   if (ihdl->pcmStrm.dedicated_mode){
#ifdef DSP_DEBUG_DEDICATED_MODE_RECORD
      if ( count < (FRAME_BUF_SIZE << 1) ) {
         kal_dev_trace( TRACE_STATE, L1AUDIO_PCM_STRM_BUF_OVFLOW ); // buffer overflow
         return;
      }
#else
      if ( count < FRAME_BUF_SIZE ) {
         kal_dev_trace( TRACE_STATE, L1AUDIO_PCM_STRM_BUF_OVFLOW ); // buffer overflow
         return;
      }
#endif
   } else {

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
        dspRecLen = (int32)Pseudo_SAL_PcmEx_GetBufLen(PSEUDO_SAL_PCMEX_BUF_SE);

#ifndef UPPER_BOUND
#define UPPER_BOUND(in,up)  ((in) > (up) ? (up) : (in))
#endif

        count = UPPER_BOUND(count, dspRecLen);
#else   // chip compile option
      dspRecLen = (int32)(*DSP_PCM_REC_LEN);
      if( dspRecLen < count )
         count = dspRecLen;
#endif  // chip compile option

      if ( count < FRAME_BUF_SIZE ) {
         kal_dev_trace( TRACE_STATE, L1AUDIO_PCM_STRM_BUF_OVFLOW ); // buffer overflow
         return;
      }
   }

   pcmReadDataSegment(ihdl);
}

static void pcmStrmRecHisr( void *data )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)data;
#if defined(_DSP_INTERSHAREMEM_EN_)    
   *DP2_AUDIO_ASP_TASK4_DM_HANDSHAKE = 0; 
#endif
   if(ihdl->mh.state != WAV_STATE_RECORDING)
      return;

   if ( ihdl->end_status == MEDIA_TERMINATED )
      return;

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
// MT6260 does not support state machine PCM record control
#else   // chip compile option
   if ( !ihdl->pcmStrm.dedicated_mode ) {
      if( *DSP_PCM_REC_CTRL == 0 ) {           // DSP in idle state
         ihdl->end_status = MEDIA_TERMINATED;
         mhdlException( (MHdl*)ihdl, MEDIA_END );
         kal_dev_trace( TRACE_STATE, L1AUDIO_PCM_STRM_IDLE ); // buffer underflow
         return;
      }
   }
#endif  // chip compile option

   pcmReadDataFromDSP(ihdl);
   mhdlDataNotification((MHdl*)ihdl);
}

#pragma arm section

static void pcmStrmRecOpenDevice( pcmStrmMediaHdl *ihdl )
{
    MHdl *hdl = (MHdl *)ihdl;
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
    mhdlHookInit(hdl, DP_D2C_PCM_REC_INT, pcmStrmRecHisr);
#else   // chip compile option
    if (ihdl->pcmStrm.dedicated_mode)
    {
        mhdlHookInit(hdl, DP_D2C_PCM_TCH_R, pcmStrmRecHisr);
    }
    else
    {
#if defined(MT6229) || defined(MT6225) || defined(MT6268T) || defined(MT6268H) || defined(MT6235) || defined(MT6238) || defined(MT6235B) || defined(MT6239) || defined(MT6268A) || defined(MT6268) || defined(MT6253T) || defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252) || defined(MT6236) || defined(MT6236B) || defined(MT6256) || defined(MT6251) || defined(MT6255) || defined(MT6250)
        mhdlHookInit(hdl, DP_D2C_WAV_REC, pcmStrmRecHisr);
#else
        mhdlHookInit(hdl, DP_D2C_PCM_R, pcmStrmRecHisr);
#endif
    }
#endif  // chip compile option

    ihdl->end_status = MEDIA_NONE;
    mhdlDisallowSleep((MHdl*)ihdl);
    AM_Force_VBI_END_IN_TASK();

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
// MT6260 does not support state machine PCM record control
    AM_PCM8K_RecordOn();
#else   // chip compile option
    if (ihdl->pcmStrm.dedicated_mode)
    {   // PCM recording in TCH mode
        AM_PCM8K_RecordOn();
    }
    else
    {
        *DSP_PCM_REC_CTRL  = 0x200;
        AM_PCM8K_RecordOn();
        {
            uint16 I = 0;
            do
            {
                if (*DSP_PCM_REC_CTRL == 0x400)
                {
                    break;
                }
                ASSERT_REBOOT(I < 20);
                kal_sleep_task(2);
                I++;
            } while (1);
        }
    }
#endif  // chip compile option
}

static void pcmStrmRecCloseDevice( MHdl *hdl )
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
// MT6260 does not support state machine PCM record control
#else   // chip compile option
    {
        uint16 I = 0;
        do
        {
            uint16 ctl = *DSP_PCM_REC_CTRL;
            if (ctl == 0)
            {   // DSP returns to idle state
                break;
            }
            
            if (ctl == 0x400)
            {   // give ABORT command to the DSP
                *DSP_PCM_REC_CTRL = 0x800;
            }
            
            ASSERT_REBOOT(I < 20);
            kal_sleep_task(2);
            I++;
        } while(1);
    }
#endif  // chip compile option
   AM_PCM8K_RecordOff( true );
   mhdlAllowSleep( hdl );
   
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
    mhdlHookFinalize(DP_D2C_PCM_REC_INT);
#else   // chip compile option
    {
        pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;
        if (ihdl->pcmStrm.dedicated_mode)
        {
            mhdlHookFinalize(DP_D2C_PCM_TCH_R);
        }
        else
        {
#if defined(MT6229) || defined(MT6225) || defined(MT6268T) || defined(MT6268H) || defined(MT6235) || defined(MT6238) || defined(MT6235B) || defined(MT6239) || defined(MT6268A) || defined(MT6268) || defined(MT6253T) || defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6236) || defined(MT6236B) || defined(MT6252) || defined(MT6252H) || defined(MT6256) || defined(MT6251) || defined(MT6255) || defined(MT6250)
            mhdlHookFinalize(DP_D2C_WAV_REC);
#else
            mhdlHookFinalize(DP_D2C_PCM_R);
#endif
        }
    }
#endif  // chip compile option
}

static Media_Event pcmStrmRecMFProcess( MHdl *hdl, Media_Event event )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;
   ASSERT(ihdl != NULL);

   kal_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_PROCESS, MEDIA_FORMAT_PCM_8K );

   switch(event)
   {
      case MEDIA_BUFFER_UNDERFLOW:
         return event;
      case MEDIA_END:
         if ( hdl->state == WAV_STATE_RECORDING )
            pcmStrmRecCloseDevice( hdl );
         hdl->state = WAV_STATE_IDLE;
         return event;
      case MEDIA_DATA_NOTIFICATION:
         return MEDIA_DATA_NOTIFICATION;
      default:
         ASSERT(0);    // should never reach here
   }
   return MEDIA_NONE;  // no use (only for compile)
}

static Media_Status pcmStrmMFRecord( MHdl *hdl )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;

   hdl->eof = KAL_FALSE;
   hdl->waiting = KAL_FALSE;
   ihdl->end_status = MEDIA_NONE;

   // Check buffer size
   ihdl->mh.rbInfo.rb_size = (FRAME_BUF_SIZE * 2) * (ihdl->mh.rbInfo.rb_size / (FRAME_BUF_SIZE * 2));
   if (ihdl->mh.rbInfo.rb_size == 0)
      return MEDIA_FAIL;

   ihdl->mh.state = WAV_STATE_RECORDING;
   pcmStrmRecOpenDevice(ihdl);
   kal_trace( TRACE_FUNC, L1AUDIO_RECORD, MEDIA_FORMAT_PCM_8K );

   return MEDIA_SUCCESS;
}

static Media_Status pcmStrmRecMFResume( MHdl *hdl )
{
   Media_Status result;
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;
   hdl->LastRingBufferRead = 0;

   result = pcmStrmMFRecord(hdl);

   kal_trace( TRACE_FUNC, L1AUDIO_RESUME, MEDIA_FORMAT_PCM_8K );

   return result;
}

static Media_Status pcmStrmRecMFPause( MHdl *hdl )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;

   ASSERT( hdl->state == WAV_STATE_RECORDING );

   ihdl->end_status = MEDIA_TERMINATED;
   pcmStrmRecCloseDevice( hdl );

   hdl->state = WAV_STATE_PLAY_PAUSE;

   kal_trace( TRACE_FUNC, L1AUDIO_PAUSE, MEDIA_FORMAT_PCM_8K );

   return MEDIA_SUCCESS;
}

static Media_Status pcmStrmRecMFStop( MHdl *hdl )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;

   if( hdl->state == WAV_STATE_RECORD_PAUSE || hdl->state == WAV_STATE_IDLE )
      return MEDIA_SUCCESS;

   ihdl->end_status = MEDIA_TERMINATED;
   pcmStrmRecCloseDevice( hdl );

   hdl->state = WAV_STATE_IDLE;
   kal_trace( TRACE_FUNC, L1AUDIO_STOP, MEDIA_FORMAT_PCM_8K );
   return MEDIA_SUCCESS;
}

static Media_Status pcmStrmRecMFClose( MHdl *hdl )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;

   ASSERT( hdl != 0 && hdl->state != WAV_STATE_RECORDING);

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
#if defined(__AUDIO_COMPONENT_SUPPORT__)
    mhdlFinalize_PCM(hdl, DP_D2C_PCM_REC_INT);
#endif
    mhdlFinalize(hdl, DP_D2C_PCM_REC_INT);
#else   // chip compile option
   if (ihdl->pcmStrm.dedicated_mode) 
   {
#if defined(__AUDIO_COMPONENT_SUPPORT__)
      mhdlFinalize_PCM( hdl, DP_D2C_PCM_TCH_R );
#endif
      mhdlFinalize( hdl, DP_D2C_PCM_TCH_R );
   }
   else
   {
#if defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6253) || defined(MT6236) || defined(MT6236B) || defined(MT6256) || defined(MT6251) || defined(MT6252) || defined(MT6252H) || defined(MT6255) || defined(MT6250)
#if defined(__AUDIO_COMPONENT_SUPPORT__)
      mhdlFinalize_PCM( hdl, DP_D2C_WAV_REC );
#endif
      mhdlFinalize( hdl, DP_D2C_WAV_REC );
#else
#if defined(__AUDIO_COMPONENT_SUPPORT__)
      mhdlFinalize_PCM( hdl, DP_D2C_PCM_R );
#endif
      mhdlFinalize( hdl, DP_D2C_PCM_R );
#endif
   }
#endif  // chip compile option

   L1SP_DisableStrmPcmSPE();
   free_ctrl_buffer( hdl );
   kal_trace( TRACE_FUNC, L1AUDIO_CLOSE, MEDIA_FORMAT_PCM_8K );
   return MEDIA_SUCCESS;
}

/* For playback*/

#if defined(__WAV_DECODE_SWIP__) && !defined(MED_NOT_PRESENT)
extern MHdl *PCM_Strm_Open_cilent(void(*handler)( MHdl *handle, Media_Event event ), void *param);

MHdl *PCM_Strm_Open(void(*handler)( MHdl *handle, Media_Event event ), void *param)
{
   return PCM_Strm_Open_cilent(handler, param);
}

#else

static void pcmStrmOpenDevice( pcmStrmMediaHdl *ihdl )
{
   uint16 I;
   MHdl *hdl = (MHdl *)ihdl;
   mhdlHookInit( hdl, DP_D2C_PCM_P, pcmStrmHisr );
   ihdl->end_status = MEDIA_NONE;
   ihdl->mh.dsp_rb_base = 0;
   mhdlDisallowSleep( (MHdl*)ihdl );
   
   KT_StopAndWait();
   TONE_StopAndWait();
   AM_Force_VBI_END_IN_TASK();
   
   ASSERT_REBOOT(*DSP_PCM_CTRL == 0);

   *DSP_PCM_MS |= 0x0001;
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
      *DSP_AUDIO_FLEXI_CTRL |= (FLEXI_VBI_ENABLE | FLEXI_SD_ENABLE);
#endif   
   
   if ( ihdl->pcmStrm.is8KVoice && L1SP_CheckStrmPcmSPE()) {
   	  // for Meta taste function.
   	  DSP_DynamicDownload( DDID_NOISE_REDUCTION );
      AM_PCM8K_PlaybackOn();
   	  SetSpeechEnhancement(true);
   } else if ( ihdl->pcmStrm.is8KVoice ) {
      AM_PCM8K_PlaybackOn();
   } else {
#if defined( DSP_WT_SYN ) && !defined(__AUDIO_COMPONENT_SUPPORT__)
      DSP_DynamicDownload( DDID_WAVETABLE );
#endif
      AM_AudioPlaybackOn( ASP_TYPE_PCM_HI, ihdl->pcmStrm.freqType );
   }

   *DSP_PCM_CTRL = 1;
   kal_trace( TRACE_STATE, L1AUDIO_INIT_STATE );
   for ( I = 0; ; I++ ) {
      if ( *DSP_PCM_CTRL == 8 || ihdl->end_status == MEDIA_END )
         break;
      ASSERT_REBOOT( I < 40 );
      kal_sleep_task( 2 );
   }
}

static void pcmStrmCloseDevice( MHdl *hdl )
{
   uint16 I, ctl;
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;
   
   for ( I = 0; ; I++ ) {
      ctl = *DSP_PCM_CTRL;
      if ( ctl == 0 )                // DSP returns to idle state
         break;
      if ( ctl == 8 ) {
         *DSP_PCM_CTRL = WAV_ABORT_STATE;       // give ABORT command to the DSP
         kal_trace( TRACE_STATE, L1AUDIO_STOP_STATE );
      }
      ASSERT_REBOOT( I < 40 );
      kal_sleep_task( 2 );
   }
   kal_trace( TRACE_STATE, L1AUDIO_IDLE_STATE );

   if ( ihdl->pcmStrm.is8KVoice && L1SP_CheckStrmPcmSPE() ) {
   	  SetSpeechEnhancement(false);
      AM_PCM8K_PlaybackOff( true );
   }
   else if ( ihdl->pcmStrm.is8KVoice ) {
      AM_PCM8K_PlaybackOff( true );
   }
   else {
      AM_AudioPlaybackOff( true );
   }

   mhdlAllowSleep( hdl );
   if( hdl->handler != NULL )
      mhdlHookFinalize( DP_D2C_PCM_P );
 
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   *DSP_AUDIO_FLEXI_CTRL &= ~( FLEXI_VBI_ENABLE | FLEXI_SD_ENABLE );
#endif
   
   (void) ihdl;  // To avoid warning
}

static Media_Event pcmStrmMFProcess( MHdl *hdl, Media_Event event )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;
   ASSERT(ihdl != NULL);

   kal_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_PROCESS, MEDIA_FORMAT_PCM_8K );

   switch(event)
   {
      case MEDIA_END:
         AFE_SetHardwareMute(true);
         if ( hdl->state == WAV_STATE_PLAYING )
            pcmStrmCloseDevice( hdl );
         hdl->state = WAV_STATE_IDLE;
         return event;
      case MEDIA_DATA_REQUEST:
      case MEDIA_BUFFER_UNDERFLOW:
         if(hdl->pStrmStruct)
         {
            hdl->FinishWriteData(hdl);
         }
      case MEDIA_READY_TO_PLAY:
         return event;
      default:
         ASSERT(0);    // should never reach here
   }
   return MEDIA_NONE;  // no use (only for compile)
}

static Media_Status pcmStrmMFPlay( MHdl *hdl )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   hdl->current_time = hdl->start_time;
   hdl->eof = KAL_FALSE;
   hdl->waiting = KAL_FALSE;
   ihdl->end_status = MEDIA_NONE;
   ihdl->decode_EOF = false;
   ihdl->zeroCount = 0;
   hdl->isUnderflow = KAL_FALSE;
   hdl->LastRingBufferRead = 0;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PCM_STRM_FORMAT, ihdl->pcmStrm.sampleFreq, ihdl->pcmStrm.bitPerSample,(kal_uint32)ihdl->pcmStrm.isStereo+1,0,0,0);
   mhdlRefillAndUpdateVideoBuffer(hdl); //call this function, if video eof, hdl->eof will be set. 

   switch( ihdl->pcmStrm.sampleFreq / 1000 ){   // update sample rate index of control table
      case 8:
         ihdl->pcmStrm.freqType = 0x00;
         ihdl->frameDuration    = 10;
         break;
      case 16:
         ihdl->pcmStrm.freqType = 0x20;
         ihdl->frameDuration    = 10;
         break;
      case 11:
         ihdl->pcmStrm.freqType = 0x11;
         ihdl->frameDuration    = 40;
         break;
      case 12:
         ihdl->pcmStrm.freqType = 0x12;
         ihdl->frameDuration    = 10;
         break;
      case 22:
         ihdl->pcmStrm.freqType = 0x21;
         ihdl->frameDuration    = 20;
         break;
      case 24:
         ihdl->pcmStrm.freqType = 0x22;
         ihdl->frameDuration    = 10;
         break;
      case 32:
         ihdl->pcmStrm.freqType = 0x40;
         ihdl->frameDuration    = 10;
         break;
      case 44:
         ihdl->pcmStrm.freqType = 0x41;
         ihdl->frameDuration    = 10;
         break;
      case 48:
         ihdl->pcmStrm.freqType = 0x42;
         ihdl->frameDuration    = 10;
         break;
      default: 
         return MEDIA_UNSUPPORTED_FREQ;
   }

#if defined(MT6251)
   // Due to loading issue, MT6223 doesn't support 44.1 kHz and 48 kHz
   if (ihdl->pcmStrm.sampleFreq >= 17000)
      return MEDIA_UNSUPPORTED_TYPE;
#endif
#if (defined(MT6253) && defined(__EMI_CLK_52MHZ__)) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
   // Due to loading issue, MT6253D doesn't support 44.1 kHz and 48 kHz
   if (ihdl->pcmStrm.sampleFreq >= 33000)
      return MEDIA_UNSUPPORTED_TYPE;
#endif

   if ( (ihdl->pcmStrm.bitPerSample != 8) && (ihdl->pcmStrm.bitPerSample != 16) )
      return MEDIA_BAD_PARAMETER;

   // Check whether we force mono to stereo
   if (ihdl->pcmStrm.isStereo)
      hdl->mono2stereo = false;
   else
      hdl->mono2stereo = true;
   if (ihdl->pcmStrm.is8KVoice)
      hdl->mono2stereo = false;

#if defined(CYBERON_DIC_TTS) || defined(IFLY_TTS) || defined(SINOVOICE_TTS) || defined(VRSI_ENABLE)
   // In order to reduce the loading of AvBT,
   // we force TTS/VRSI to be voice (not throught AvBT)
   if ( (ihdl->pcmStrm.freqType == 0x00) && (ihdl->pcmStrm.isStereo == false) ) {
#if defined(CYBERON_DIC_TTS) || defined(IFLY_TTS) || defined(SINOVOICE_TTS)
      if (ttsIsEnable()) {
         hdl->mono2stereo = false;
         ihdl->pcmStrm.is8KVoice = true;
      }
#endif
#if defined(VRSI_ENABLE)
      if (vrsiIsPlaying()) {
         hdl->mono2stereo = false;
         ihdl->pcmStrm.is8KVoice = true;
      }
#endif
   }

#endif

   pcmStrmOpenDevice(ihdl);
   ihdl->mh.state = WAV_STATE_PLAYING;
   kal_trace( TRACE_FUNC, L1AUDIO_PLAY_STREAM, MEDIA_FORMAT_PCM_8K );

   return MEDIA_SUCCESS;
}

static Media_Status pcmStrmMFResume( MHdl *hdl )
{
   Media_Status result;
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;
   hdl->LastRingBufferRead = 0;

   result = pcmStrmMFPlay(hdl);

   kal_trace( TRACE_FUNC, L1AUDIO_RESUME, MEDIA_FORMAT_PCM_8K );

   return result;
}

static Media_Status pcmStrmMFPause( MHdl *hdl )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;

   ASSERT( hdl->state == WAV_STATE_PLAYING );

   ihdl->end_status = MEDIA_TERMINATED;
   AFE_SetHardwareMute(true);
   pcmStrmCloseDevice( hdl );
   hdl->state = WAV_STATE_PLAY_PAUSE;

   kal_trace( TRACE_FUNC, L1AUDIO_PAUSE, MEDIA_FORMAT_PCM_8K );

   return MEDIA_SUCCESS;
}

static Media_Status pcmStrmMFStop( MHdl *hdl )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;

   if( hdl->state == WAV_STATE_PLAY_PAUSE || hdl->state == WAV_STATE_IDLE )
      return MEDIA_SUCCESS;

   AFE_SetHardwareMute(true);
   ihdl->end_status = MEDIA_TERMINATED;
   pcmStrmCloseDevice( hdl );

   hdl->state = WAV_STATE_IDLE;
   kal_trace( TRACE_FUNC, L1AUDIO_STOP, MEDIA_FORMAT_PCM_8K );
   return MEDIA_SUCCESS;
}

static Media_Status pcmStrmMFClose( MHdl *hdl )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;

   ASSERT( hdl != 0 && hdl->state != WAV_STATE_PLAYING);
   if( hdl->handler != NULL ){
#if defined(__AUDIO_COMPONENT_SUPPORT__)
      mhdlFinalize_PCM( hdl, DP_D2C_PCM_P );
#endif   	  
      mhdlFinalize( hdl, DP_D2C_PCM_P );
   }
   L1SP_DisableStrmPcmSPE();
   free_ctrl_buffer( hdl );
   kal_trace( TRACE_FUNC, L1AUDIO_CLOSE, MEDIA_FORMAT_PCM_8K );
   return MEDIA_SUCCESS;
}

MHdl *PCM_Strm_Open(void(*handler)( MHdl *handle, Media_Event event ), void *param)
{
   MHdl *hdl;
   pcmStrmMediaHdl *ihdl;
   Media_PCM_Stream_Param *pcm_param = (Media_PCM_Stream_Param *) param;

   ihdl = (pcmStrmMediaHdl*)get_ctrl_buffer( sizeof(pcmStrmMediaHdl) );
   memset(ihdl, 0, sizeof(pcmStrmMediaHdl));
   hdl = (MHdl *) ihdl;

   if( handler != NULL )
      mhdlInit( hdl, DP_D2C_PCM_P, pcmStrmHisr );
   else
      mhdlInitEx( hdl, DP_D2C_PCM_P, pcmStrmHisr );

   hdl->handler   = handler;
   hdl->state     = WAV_STATE_IDLE;
   ihdl->pcmStrm.isPlayback    = true;
   ihdl->pcmStrm.isStereo      = pcm_param->isStereo;
   ihdl->pcmStrm.bitPerSample  = pcm_param->bitPerSample;
   ihdl->pcmStrm.sampleFreq    = pcm_param->sampleFreq;
   ihdl->pcmStrm.is8KVoice     = pcm_param->forceVoice;
   if(pcm_param->forceVoice == true) {
   	  L1SP_EnableStrmPcmSPE();
   }

   hdl->Close     = pcmStrmMFClose;
   hdl->Pause     = pcmStrmMFPause;
   hdl->Stop      = pcmStrmMFStop;
   hdl->Process   = pcmStrmMFProcess;
   hdl->Play      = pcmStrmMFPlay;
   hdl->Resume    = pcmStrmMFResume;

   kal_trace( TRACE_FUNC, L1AUDIO_OPEN_STREAM, MEDIA_FORMAT_PCM_8K );

   return hdl;
}
#endif

MHdl *PCM_Strm_Rec_Open(void(*handler)( MHdl *handle, Media_Event event ), void *param)
{
   MHdl *hdl;
   pcmStrmMediaHdl *ihdl;

   ihdl = (pcmStrmMediaHdl*)get_ctrl_buffer( sizeof(pcmStrmMediaHdl) );
   memset(ihdl, 0, sizeof(pcmStrmMediaHdl));
   hdl = (MHdl *) ihdl;

   ihdl->pcmStrm.dedicated_mode = AM_IsSpeechOn();

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
    mhdlInit(hdl, DP_D2C_PCM_REC_INT, pcmStrmRecHisr);
#else   // chip compile option
   if (ihdl->pcmStrm.dedicated_mode) {
     mhdlInit( hdl, DP_D2C_PCM_TCH_R, pcmStrmRecHisr );
   } else {
#if defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6253) || defined(MT6236) || defined(MT6236B) || defined(MT6256) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H) || defined(MT6255) || defined(MT6250)
      mhdlInit( hdl, DP_D2C_WAV_REC, pcmStrmRecHisr );
#else
      mhdlInit( hdl, DP_D2C_PCM_R, pcmStrmRecHisr );
#endif
   }
#endif  // chip compile option

   hdl->handler   = handler;
   hdl->state     = WAV_STATE_IDLE;
   ihdl->pcmStrm.isPlayback    = false;

   hdl->Close     = pcmStrmRecMFClose;
   hdl->Pause     = pcmStrmRecMFPause;
   hdl->Stop      = pcmStrmRecMFStop;
   hdl->Process   = pcmStrmRecMFProcess;
   hdl->Record    = pcmStrmMFRecord;
   hdl->Resume    = pcmStrmRecMFResume;

   kal_trace( TRACE_FUNC, L1AUDIO_OPEN_STREAM, MEDIA_FORMAT_PCM_8K );

   return hdl;
}

#endif   //#if defined(WAV_CODEC)
#endif
