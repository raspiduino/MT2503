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
 * wav_thumb.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   critical routines of WAV playback/recording functionality
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

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "reg_base.h"
#include "l1d_reg.h"
#include "fs_type.h"
#include "string.h"
#include "fs_func.h"
#include "fs_errcode.h"

#include "l1audio.h"
#include "audio_def.h"
#include "speech_def.h"
#include "media.h"
#include "ddload.h"
#include "wav.h"
#include "afe.h"
#include "am.h"
#include "common_def.h"

#if defined(__KARAOKE_SUPPORT__)
#include "karaoke_drv.h"
#endif
#if defined(WAV_CODEC)

#define  REAL_RESUMING_SUPPORT

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

// #define  DSP_DEBUG_DEDICATED_MODE_RECORD  // This flag is for DSP to record stereo wave in dedicated mode.

extern void wavADPCMPutData( int32 dsp_len );
extern void wavADPCMPutData_ST( int32 dsp_len );
extern void wavMSADPCMPutData( int32 dsp_len );
extern void (*MS_ADPCM_Decode)( uint16 data, uint32 position );
extern void ms_adpcm_decode_stereo( uint16 data, uint32 position );
extern void ms_adpcm_decode_mono( uint16 data, uint32 position );

extern void *audio_alloc_ext_mem_cacheable_simplified(kal_uint32 size);
extern void audio_free_ext_mem_simplified(void *ptr);

extern struct wavHeader_Struct wavHeader;
extern struct wav_Struct wav;

#if defined(REAL_RESUMING_SUPPORT)
static uint16         tmp_BlockCount[2];
static dviAdpcm_State tmp_dvi_state_ch1[2];
static dviAdpcm_State tmp_dvi_state_ch2[2];
static MS_ADPCM_STATE tmp_ms_adpcm_state[2][2];
static short          tmp_aCoeff[2][MSADPCM_EXTRA_COEFF][2];
#endif

#ifdef __MM_DCM_SUPPORT__   
#pragma arm section code = "DYNAMIC_CODE_WAVREC_ROCODE", rodata = "DYNAMIC_CODE_WAVREC_RODATA"
#endif

static void wavUpsample_Process( kal_int16 *pInBuf, kal_int16 *pOutBuf, const kal_uint32 uInSampleCnt)
{
#if defined(__CVSD_CODEC_SUPPORT__)
   kal_uint32 uInByte, uOutByte, uConsumeByte;
   uInByte = uInSampleCnt<<1;
   uOutByte = uInSampleCnt<<2;
   memcpy( (kal_uint8*)wav.pTempPcmBuf, (kal_uint8*)pInBuf, uInByte);
   ASSERT(wav.pSRC_Handle);
#if !defined(__DISABLE_BLISRC__)
   uConsumeByte = BLI_Convert( wav.pSRC_Handle, wav.pTempPcmBuf, &uInByte, pOutBuf, &uOutByte);  
#else                     
    {
        extern void apm_UpsampleMono(short *source, short *dest, short *Data, int srcLen, int upRate);
        apm_UpsampleMono(wav.pTempPcmBuf, pOutBuf, (kal_int16*)wav.pSRC_Handle, uInSampleCnt, 2);
    }
   uInByte = 0;
   uOutByte = uInSampleCnt<<2;
   uConsumeByte = uInSampleCnt<<1;
#endif
   ASSERT(uInByte==0);
   if(uOutByte!=uInSampleCnt<<2)
   {
      memset((kal_uint8*)pOutBuf, 0, uInSampleCnt<<2 );
   }
   //kal_prompt_trace(MOD_L1SP,"[WN]wavUpsample_Process, uInByte: %d, uOutByte: %d, uConsumeByte:%d, uInSampleCnt:%d", uInByte, uOutByte, uConsumeByte, uInSampleCnt);
   ASSERT(uConsumeByte == uInSampleCnt<<1);
#endif
}

static void wavUpsample_Init()
{
#if defined(__CVSD_CODEC_SUPPORT__)
   kal_uint32 uBufSize;
   kal_uint8 *pBuf;
   kal_uint32 uCurrentSpMode = L1SP_GetSpeechMode();
   if(( uCurrentSpMode == SPH_MODE_BT_EARPHONE || uCurrentSpMode == SPH_MODE_BT_CARKIT ) && wav.sample_rate == 16000 )
   {
      ASSERT(wav.pTempPcmBuf == NULL);
      wav.fNB2WB = KAL_TRUE;
#if !defined(__DISABLE_BLISRC__)
      BLI_GetMemSize(8000,1,16000,1,&uBufSize);
#else
      uBufSize = 44;
#endif
      uBufSize = ((uBufSize+3) & ~3) +  (FRAME_BUF_SIZE<<1);
      pBuf = (kal_uint8 *)audio_alloc_mem_cacheable(uBufSize);
      ASSERT(pBuf);
      wav.pTempPcmBuf = (kal_int16*) pBuf;
      pBuf += FRAME_BUF_SIZE<<1;
#if !defined(__DISABLE_BLISRC__)
      wav.pSRC_Handle = (void*)BLI_Open(8000,1,16000,1,(kal_int8*)pBuf, audio_alloc_ext_mem_cacheable_simplified);
#else
      wav.pSRC_Handle = (void*)pBuf;
#endif
      ASSERT(wav.pSRC_Handle);
   }
#endif
}

static void wavUpsample_Free()
{
#if defined(__CVSD_CODEC_SUPPORT__)
   if(wav.pTempPcmBuf)
   {
#if !defined(__DISABLE_BLISRC__)
      BLI_Close(wav.pSRC_Handle, audio_free_ext_mem_simplified);
#endif
      audio_free_mem( (void **) &wav.pTempPcmBuf ); 
      wav.pSRC_Handle = NULL;
      wav.pTempPcmBuf = NULL;
      wav.fNB2WB = KAL_FALSE;
   }
#endif
}

static bool wavRECpcmPutSample( uint16 **pbuf, uint16 data, uint16 *sample_count  )
{
   **pbuf = data;
   *pbuf = *pbuf + 1;
   *sample_count = 1;
   return true;
}

static bool wavRECalawPutSample( uint16 **pbuf, uint16 data, uint16 *sample_count  )
{
   wav.data[wav.data_count++] = data;
   if( wav.data_count == 2 ) {
      **pbuf = (uint16)linear2alaw( (int16)wav.data[0] ) |
               ((uint16)linear2alaw( (int16)wav.data[1] ) << 8);
      *pbuf = *pbuf + 1;
      wav.data_count = 0;
      *sample_count = 2;
      return true;
   }
   return false;
}

static bool wavRECulawPutSample( uint16 **pbuf, uint16 data, uint16 *sample_count  )
{
   wav.data[wav.data_count++] = data;
   if( wav.data_count == 2 ) {
      **pbuf = (uint16)linear2ulaw( (int16)wav.data[0] ) |
               ((uint16)linear2ulaw( (int16)wav.data[1] ) << 8);
      *pbuf = *pbuf + 1;
      wav.data_count = 0;
      *sample_count = 2;
      return true;
   }
   return false;
}

static bool wavRECdviPutSample( uint16 **pbuf, uint16 data, uint16 *sample_count )
{
   switch(wav.BlockCount){
      case 128:   wav.BlockCount=0;  /* Reset block counter, store block header */
      case 0:
                  dviAdpcm_Encode( data, &wav.dvi_state_ch1 );
                  **pbuf= (uint16)(int16)wav.dvi_state_ch1.valpred;
                  *pbuf = *pbuf + 1;
                  wav.BlockCount++;
                  *sample_count = 1;
                  return true;
      case 1:   /* store block header */
                  wav.data[wav.data_count++] = data;
                  **pbuf= ( uint16 )(int16)wav.dvi_state_ch1.index;
                  *pbuf = *pbuf + 1;
                  wav.BlockCount++;
                  *sample_count = 0;
                  return true;
      default:
                  wav.data[wav.data_count++] = data; /* store compressed data */
                  if( wav.data_count == 4 ) {
                     **pbuf = dviAdpcm_Encode( wav.data[0], &wav.dvi_state_ch1 ) |
                              (dviAdpcm_Encode( wav.data[1], &wav.dvi_state_ch1 ) << 4) |
                              (dviAdpcm_Encode( wav.data[2], &wav.dvi_state_ch1 ) << 8) |
                              (dviAdpcm_Encode( wav.data[3], &wav.dvi_state_ch1 ) << 12);
                     *pbuf = *pbuf + 1;
                     wav.data_count = 0;
                     wav.BlockCount++;
                     *sample_count = 4;
                     return true;
                  }
   }
   return false;
}

static void wavReadFromDSP( int16 *buf )
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
    kal_bool is_silence = Media_IsRecordSilence();
    uint32 framesize = Pseudo_SAL_PcmEx_GetBufLen(PSEUDO_SAL_PCMEX_BUF_IDLE_SE);
    uint32 silence_size;
    
    if (wav.dedicated_mode)
    {
        silence_size = FRAME_BUF_SIZE;
    }
    else if (wav.sample_rate == 16000 && !wav.fNB2WB)
    {
        silence_size = FRAME_BUF_SIZE_16K;
    }
    else
    {
        silence_size = framesize;
    }
    
    if (is_silence)
    {
        memset(buf, 0, silence_size * sizeof(kal_int16));
    }
    else if (wav.dedicated_mode)
    {   // WAV recording in TCH mode
        autTchReadFromDSP(buf, PAGE_NUM);
    }
    else
    {   // WAV recording in idle mode
        volatile uint16 *dspAddr = Pseudo_SAL_PcmEx_GetBuf(PSEUDO_SAL_PCMEX_BUF_SE);
        IDMA_ReadFromDSP((kal_uint16 *)buf, dspAddr, framesize);
    }
#else   // chip compile option
   int32 count;
   uint16 ptr_addr;

   if(wav.dedicated_mode)
   { 
      /* WAV recording in TCH mode */
      ASSERT( *DP_TCH_UL_LEN == FRAME_BUF_SIZE );   /* frame size */
      ASSERT( *DP_TCH_DL_LEN == FRAME_BUF_SIZE );   /* frame size */
      if(Media_IsRecordSilence())
      {
         memset(buf, 0, FRAME_BUF_SIZE*sizeof(kal_int16));
      }
      else
      {
         autTchReadFromDSP( buf, PAGE_NUM );
      }
   }
   else
   {  /* for WAV recording in idle mode */
      if( wav.sample_rate == 16000 && !wav.fNB2WB )
      { 
         if(Media_IsRecordSilence())
         {
            memset(buf, 0, FRAME_BUF_SIZE_16K*sizeof(kal_int16));
         }
         else
         {
#if defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6253) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) ||  defined(MT6256_S01) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H) || defined(MT6255) || defined(MT6250)
            ptr_addr = *DSP2_DM_ADDR( PAGE_NUM, DSP_PCM_16K_REC_PTR);//get address
            IDMA_ReadFromDSP((uint16*)buf, DSP2_DM_ADDR( PAGE_NUM, ptr_addr), FRAME_BUF_SIZE_16K);
#else
            ptr_addr = *DSP_DM_ADDR( PAGE_NUM, DSP_PCM_16K_REC_PTR); //get address
            IDMA_ReadFromDSP((uint16*)buf, DSP_DM_ADDR( PAGE_NUM, ptr_addr), FRAME_BUF_SIZE_16K);
#endif
         }
      }
      else
      {
         count = (int32)(*DSP_PCM_REC_LEN);
         if(Media_IsRecordSilence())
         {
#if defined(__DUAL_MIC_SUPPORT__)
            if(wav.ctrl->is_stereo)
            {
               memset(buf, 0, 2*count*sizeof(kal_int16));
            }
            else
#endif
            {
               memset(buf, 0, count*sizeof(kal_int16));
            }
         }else{
#if defined(__DUAL_MIC_SUPPORT__)
            if(wav.ctrl->is_stereo)
            {
               int16 *tempBuf = (int16 *)wav.tmp_buf_dual_mic;
               uint16 i;
               volatile uint16* ptr;
               IDMA_ReadFromDSP((uint16*)tempBuf, DSP_DM_ADDR(PAGE_NUM, *DSP_PCM_REC_ADDR), (uint32)count);
               //need interleave
               for( i = 0 ; i < FRAME_BUF_SIZE ; i++ )
               {
                  buf[i*2] = *tempBuf++;
               }
               ptr = DSP_DM_ADDR(PAGE_NUM, DUALMIC_MIC2_BUF_PTR);
               IDMA_ReadFromDSP((uint16*)tempBuf, DSP_DM_ADDR(PAGE_NUM, *ptr), (uint32)count);
               //need interleave
               for( i = 0 ; i < FRAME_BUF_SIZE ; i++ )
               {
                  buf[i*2+1] = *tempBuf++;
               }
               buf+=(uint32)count * 2;
            }
            else 
#endif
            {
               IDMA_ReadFromDSP((uint16*)buf, DSP_DM_ADDR(PAGE_NUM, *DSP_PCM_REC_ADDR), (uint32)count);
               buf+=(uint32)count;
            }
         }
      }
   }
#endif  // chip compile option
}

static void wavDataEncode( void *data ) /* This function works in L1Audio Task */
{
   int32 I, count, write_count;
   uint16 *rb_addr, *rb_end, sample_count, *SCptr, *ptr, frame_len;

   (void)data;
   SCptr = &sample_count;
   rb_end   = &wav.ctrl->rb_base[wav.ctrl->rb_size];
   rb_addr  = &wav.ctrl->rb_base[wav.ctrl->write];

   if( wav.ctrl->end_status == MEDIA_TERMINATED) {
      if( (wav.ctrl->format==MEDIA_FORMAT_WAV_DVI_ADPCM || wav.ctrl->format==MEDIA_FORMAT_WAV_DVI_ADPCM_16K )
         && wav.BlockCount != 128 && wav.state == WAV_STATE_IDLE) {
         write_count = 0;
         if (wav.BlockCount == 0) {
            count = 505;
         } else if (wav.BlockCount == 1) {
            count = 504;
         } else {
            count = 128 - wav.BlockCount;     /* zero padding the latest block */
            count <<= 2;
            count -= wav.data_count;
         }
         
         for( I = count; I > 0; I-- ) {
            if( wav.PutSample( &rb_addr, 0 , SCptr) ) {
               write_count++;
               wavHeader.wRiffLength+=2;
               wavHeader.wDataLength+=2;
               wavHeader.wSamplesWritten += sample_count;
               if( rb_addr == rb_end )
                  rb_addr = &wav.ctrl->rb_base[0];
            }
         }
         wav.ctrl->write += write_count;
         if( wav.ctrl->write >= wav.ctrl->rb_size )
            wav.ctrl->write -= wav.ctrl->rb_size;
      }
      return;
   }

#ifdef   DSP_DEBUG_DEDICATED_MODE_RECORD
   while( (uint8)(wav.tmp_w - wav.tmp_r) > 0 ) {
      write_count = 0;
      ptr = wav.tmp_buf[wav.tmp_r&FRAME_BUF_MASK];
      if( FRAME_BUF_SIZE * 2 <= mediaGetFreeSpace() ) {
         for( I = FRAME_BUF_SIZE * 2; I > 0; I-- ) {  /* writing to MB */
            if( wav.PutSample( &rb_addr, *ptr++, SCptr) ) 
            {
               write_count++;
               wavHeader.wRiffLength+=2;
               wavHeader.wDataLength+=2;
               wavHeader.wSamplesWritten += sample_count;
               if( rb_addr == rb_end )
                  rb_addr = &wav.ctrl->rb_base[0];
            }
         }
         wav.ctrl->write += write_count;
         if( wav.ctrl->write >= wav.ctrl->rb_size )
            wav.ctrl->write -= wav.ctrl->rb_size;
      }
      wav.tmp_r++;
   }
#else    // DSP_DEBUG_DEDICATED_MODE_RECORD
   while( (uint8)(wav.tmp_w - wav.tmp_r) > 0 ) {
      write_count = 0;
      ptr = wav.tmp_buf[wav.tmp_r&FRAME_BUF_MASK];
      if ( wav.sample_rate == 16000 )
         frame_len = FRAME_BUF_SIZE_16K;
      else
         frame_len = FRAME_BUF_SIZE;
#if defined(__DUAL_MIC_SUPPORT__)
         if(wav.ctrl->is_stereo)
            frame_len = frame_len*2;
#endif
      if( frame_len <= mediaGetFreeSpace() ) 
      {
#if defined(__KARAOKE_SUPPORT__)
        if(Media_IsKaraoke())
        {
            // put UL data to temp buf and do SRC for playback usage
            Karaoke_Play_SRC_UL2DL(ptr, frame_len);
            Karaoke_Rec_Mix_DL2UL(ptr, frame_len);
        }
#endif
      	
        if(wav.fNB2WB)
        {
           wavUpsample_Process( (kal_int16*)ptr, (kal_int16*)ptr, FRAME_BUF_SIZE);
        }
        for( I = frame_len; I > 0; I-- ) 
        {  /* writing to MB */
            if( wav.PutSample( &rb_addr, *ptr++, SCptr) ) 
            {
               write_count++;
               wavHeader.wRiffLength+=2;
               wavHeader.wDataLength+=2;
               wavHeader.wSamplesWritten += sample_count;
               if( rb_addr == rb_end )
                  rb_addr = &wav.ctrl->rb_base[0];
            }
         }
         wav.ctrl->write += write_count;
         if( wav.ctrl->write >= wav.ctrl->rb_size )
            wav.ctrl->write -= wav.ctrl->rb_size;
      }
      wav.tmp_r++;
   }
#endif   // DSP_DEBUG_DEDICATED_MODE_RECORD
}

static bool wavGetDWord(uint8 *pBuf, uint32 *readPos, uint32 len, uint32 *data32)
{
   uint32 readPosCache;
   uint8 *pTemp;
   
   readPosCache = *readPos;
   pTemp = pBuf + readPosCache;
   
   // Check the length
   if (len < readPosCache+4)
      return false;

   *data32 = pTemp[0] | (pTemp[1]<<8) | (pTemp[2]<<16) | (pTemp[3]<<24);
   *readPos = readPosCache + 4;
   return true;
}

static bool wavGetWord(uint8 *pBuf, uint32 *readPos, uint32 len, uint16 *data16)
{
   uint32 readPosCache;
   uint8 *pTemp;
   
   readPosCache = *readPos;
   pTemp = pBuf + readPosCache;
   
   // Check the length
   if (len < readPosCache+2)
      return false;

   *data16 = pTemp[0] | (pTemp[1]<<8);
   *readPos = readPosCache + 2;
   return true;
}
#ifdef __MM_DCM_SUPPORT__ 
#pragma arm section code, rodata
#endif

Media_Status wavParseRecordFile( uint8 *pBuf, uint32 len, Media_Record_File_Info *info )
{
   uint32 readPos;
   uint32 dummy_32, riffSize, fmtSize, avgByteRate, headerSize = 0;
   uint16 dummy_16, audioFormat, blockAlign, bitPerSample;
   kal_bool is_I2S = info->is_I2S;
   kal_uint16 wav_sampling_rate;
   wav_sampling_rate = Media_I2S_INPUT_MODE_SR;
   if (len < 44)
      return MEDIA_BAD_FORMAT;

   readPos = 0;
   // 1: Check RIFF (0~3)
   wavGetDWord(pBuf, &readPos, len, &dummy_32);
   if (dummy_32 != 0x46464952) {
      return MEDIA_BAD_FORMAT;
   }

   // 2 : Get RIFF size (4~7)
   wavGetDWord(pBuf, &readPos, len, &riffSize);
   
   // 3: Check WAVE (8~11)
   wavGetDWord(pBuf, &readPos, len, &dummy_32);
   if (dummy_32 != 0x45564157) {
      return MEDIA_BAD_FORMAT;
   }
   
   // 4: Check fmt (12~15)
   wavGetDWord(pBuf, &readPos, len, &dummy_32);
   if (dummy_32 != 0x20746D66) {
      return MEDIA_BAD_FORMAT;
   }
   
   // 5: fmt size (16~19)
   wavGetDWord(pBuf, &readPos, len, &fmtSize);
   if (fmtSize < 16) {
      return MEDIA_BAD_FORMAT;
   }

   // 6: Audio Format (20~21)
   wavGetWord(pBuf, &readPos, len, &audioFormat);
   
   // 7: Number of Channel (22~23)
   wavGetWord(pBuf, &readPos, len, &dummy_16);
   info->channel = dummy_16;
   if (dummy_16 != 1)
      return MEDIA_UNSUPPORTED_CHANNEL;
   
   // 8: Sample Rate (24~27)
   wavGetDWord(pBuf, &readPos, len, &dummy_32);
   info->sampleFreq = dummy_32;
   if ( ( 0 == is_I2S ) && (dummy_32 != 8000) && (dummy_32 != 16000) ) 
      return MEDIA_UNSUPPORTED_FREQ;
   else if( ( 1 == is_I2S ) && (dummy_32 != wav_sampling_rate) )
      return MEDIA_UNSUPPORTED_FREQ;
   
   // 9: Average Byte Rate(28~31), Block Align (32~33), Bit Per Sample (34~35)
   wavGetDWord(pBuf, &readPos, len, &avgByteRate);
   wavGetWord(pBuf, &readPos, len, &blockAlign);
   wavGetWord(pBuf, &readPos, len, &bitPerSample);
   
   // 10: Process each kind of audio format
   switch (audioFormat) {
      case 0x0001:   // Linear PCM
         if (fmtSize != 16) {
            return MEDIA_BAD_FORMAT;
         }
         if (( 0 == is_I2S ) && (info->sampleFreq != 8000) && (info->sampleFreq != 16000) ) {
             return MEDIA_UNSUPPORTED_FREQ;
         }
         else if (( 1 == is_I2S ) && (info->sampleFreq != wav_sampling_rate)) {
             return MEDIA_UNSUPPORTED_FREQ;
         }
         if ( ( 0 == is_I2S ) && ( ((avgByteRate != 16000) && (avgByteRate != 32000)) || (blockAlign != 2) || (bitPerSample != 16)) ) {
            return MEDIA_UNSUPPORTED_TYPE;
         }
         else if ( ( 1 == is_I2S ) && ((avgByteRate != wav_sampling_rate*2) || (blockAlign != 2) || (bitPerSample != 16)) ) {
             return MEDIA_UNSUPPORTED_FREQ;
         } 
         info->format = MEDIA_FORMAT_WAV;
         info->sampleCount = (info->fileSize - 44)>>1;
         headerSize = 44;
         break;
      
      case 0x0006:   // A law
      case 0x0007:   // U Law
         if (is_I2S)
            return MEDIA_BAD_FORMAT;
         if (len < 58) {
            return MEDIA_BAD_FORMAT;
         }
         if (fmtSize != 18) {
            return MEDIA_BAD_FORMAT;
         }
         if (info->sampleFreq != 8000) {
             return MEDIA_UNSUPPORTED_FREQ;
         }
         if ( (avgByteRate != 8000) || (blockAlign != 1) || (bitPerSample != 8) ) {
            return MEDIA_UNSUPPORTED_TYPE;
         }
         
         // Ext Size
         wavGetWord(pBuf, &readPos, len, &dummy_16);
         if (dummy_16 != 0)
            return MEDIA_BAD_FORMAT;
         // fact
         wavGetDWord(pBuf, &readPos, len, &dummy_32);
         if (dummy_32 != 0x74636166) {
            return MEDIA_BAD_FORMAT;
         }
         // fact size
         wavGetDWord(pBuf, &readPos, len, &dummy_32);
         if (dummy_32 != 0x4) {
            return MEDIA_BAD_FORMAT;
         }
         // sampleWritten
         wavGetDWord(pBuf, &readPos, len, &info->sampleCount);
         
         if (audioFormat == 0x0006)
            info->format = MEDIA_FORMAT_WAV_ALAW;
         else
            info->format = MEDIA_FORMAT_WAV_ULAW;
         headerSize = 58;
         break;
      
      case 0x0011:   // DVI-ADPCM
         if (len < 60) {
            return MEDIA_BAD_FORMAT;
         }
         if (fmtSize != 20) {
            return MEDIA_BAD_FORMAT;
         }
         if ( (blockAlign != 256) || (bitPerSample != 4) ) {
            return MEDIA_UNSUPPORTED_TYPE;
         }
         
         // Ext Size
         wavGetWord(pBuf, &readPos, len, &dummy_16);
         if (dummy_16 != 2)
            return MEDIA_BAD_FORMAT;
         // Sample Per Block
         wavGetWord(pBuf, &readPos, len, &dummy_16);
         if (dummy_16 != 505)
            return MEDIA_UNSUPPORTED_TYPE;
         // fact
         wavGetDWord(pBuf, &readPos, len, &dummy_32);
         if (dummy_32 != 0x74636166) {
            return MEDIA_BAD_FORMAT;
         }
         // fact size
         wavGetDWord(pBuf, &readPos, len, &dummy_32);
         if (dummy_32 != 0x4) {
            return MEDIA_BAD_FORMAT;
         }
         // sampleWritten
         wavGetDWord(pBuf, &readPos, len, &info->sampleCount);
         
         if ((info->sampleCount % 505) != 0)
            return MEDIA_UNSUPPORTED_TYPE;
         
         if (info->sampleFreq == 8000 && is_I2S == 0) {
            if (avgByteRate != 4055) {
               return MEDIA_UNSUPPORTED_TYPE;
            }
            info->format = MEDIA_FORMAT_WAV_DVI_ADPCM;
         } else if (info->sampleFreq == 16000 && is_I2S == 0) {
            if (avgByteRate != 8110) {
               return MEDIA_UNSUPPORTED_TYPE;
            }
            info->format = MEDIA_FORMAT_WAV_DVI_ADPCM_16K;
         } else if (info->sampleFreq == wav_sampling_rate && is_I2S == 1) {
            if (avgByteRate != wav_sampling_rate*256/505) {
               return MEDIA_UNSUPPORTED_TYPE;
            }
            info->format = MEDIA_FORMAT_WAV_DVI_ADPCM;
         } else {
             return MEDIA_UNSUPPORTED_FREQ;
         }
         headerSize = 60;
         break;
      default:
         return MEDIA_UNSUPPORTED_TYPE;
   }
   
   // 11: Check data
   wavGetDWord(pBuf, &readPos, len, &dummy_32);
   if (dummy_32 != 0x61746164) {
      return MEDIA_BAD_FORMAT;
   }
   
   // 12: Get data size
   wavGetDWord(pBuf, &readPos, len, &info->dataSize);
   if ( (info->dataSize + headerSize) != info->fileSize )
      return MEDIA_FAIL;

   if ( (info->format == MEDIA_FORMAT_WAV_DVI_ADPCM) || (info->format == MEDIA_FORMAT_WAV_DVI_ADPCM_16K) ) {
      if ( (info->dataSize & 0xFF) != 0 )
         return MEDIA_UNSUPPORTED_TYPE;
   }

   return MEDIA_SUCCESS;
}

Media_Status wavRecordAppendable( Media_Format format, FS_HANDLE fs, Media_Record_File_Info *info )
{
   uint8 *pBuf;
   Media_Status status;
   uint32 len;
   kal_bool is_I2S;
#if defined(__I2S_WAV_RECORD__)
   if( I2S_is_I2S_open() )
      is_I2S = (kal_bool)1;
   else
#endif
      is_I2S = (kal_bool)0;
   // To initialize info
   memset(info, 0, sizeof(Media_Record_File_Info));

   // Get the file size
   if (FS_NO_ERROR != FS_GetFileSize(fs, &info->fileSize) )
      return MEDIA_READ_FAIL;

   // To get the enough wav header which is supported by MediaTek
   pBuf = (uint8*)get_ctrl_buffer( 60*sizeof(uint8) );
   memset(pBuf, 0, 60*sizeof(uint8));

   if ( FS_NO_ERROR != FS_Read(fs, pBuf, 60, &len) ) 
   {
      status = MEDIA_READ_FAIL;
   }
   else
   {
      // Parse the wav header
      info->is_I2S = is_I2S;
      status = wavParseRecordFile(pBuf, len, info);
   }

   free_ctrl_buffer( pBuf );
   
   // Compare the file information and wav format
   if (status == MEDIA_SUCCESS)
   {
      // Type mismatch
      if (format != info->format)
         return MEDIA_FAIL;
   }
   
   return status;
}

#ifdef __MM_DCM_SUPPORT__   
#pragma arm section code = "DYNAMIC_CODE_WAVREC_ROCODE", rodata = "DYNAMIC_CODE_WAVREC_RODATA"
#endif
void wavRecordHisr( void )
{
#if defined(_DSP_INTERSHAREMEM_EN_)    
   *DP2_AUDIO_ASP_TASK4_DM_HANDSHAKE = 0; 
#endif
   if(wav.state != WAV_STATE_RECORDING)
      return;

   if( wav.ctrl->end_status == MEDIA_TERMINATED) {
      if( (wav.ctrl->format==MEDIA_FORMAT_WAV_DVI_ADPCM  || wav.ctrl->format==MEDIA_FORMAT_WAV_DVI_ADPCM_16K )
         && wav.BlockCount != 128 && wav.state == WAV_STATE_IDLE){
         L1Audio_SetEvent( wav.aud_id, (void *)0 );        /* zero padding */
      }
      return;
   }

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
// MT6260 does not support state machine PCM record control
#else   // chip compile option
   if((!wav.dedicated_mode && wav.sample_rate != 16000) || wav.fNB2WB ){
      if( *DSP_PCM_REC_CTRL == 0 ) {   /* DSP returns to idle state */
         return;
      }
   }
#endif  // chip compile option

   if( (uint8)(wav.tmp_w - wav.tmp_r) < FRAME_BUF_NO )
   {
      wavReadFromDSP((int16 *)wav.tmp_buf[wav.tmp_w&FRAME_BUF_MASK] );
      wav.tmp_w++;
      L1Audio_SetEvent( wav.aud_id, (void *)0 ); /* Activate the encoder runing in l1audio task */
   }
}

void wavInternalRecord( void )
{
   wav.state = WAV_STATE_RECORDING;
   wav.ctrl->end_status = MEDIA_NONE;

#if defined(__I2S_WAV_RECORD__)
   if(I2S_is_I2S_open())
      return;
#endif


#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
// MT6260 does not support state machine PCM record control
    if (!wav.dedicated_mode && wav.sample_rate == 16000 && !wav.fNB2WB)
    {
        Media_Hook_Record_HISR (DP_D2C_VM_REC_INT, NULL);
        AM_PCM16K_RecordOn();
    }
    else
    {
        Media_Hook_Record_HISR (DP_D2C_PCM_REC_INT, NULL);
        AM_PCM8K_RecordOn();
    }
#else   // chip compile option
   if(wav.dedicated_mode )
   { /* WAV recording in TCH mode */
      AM_PCM8K_RecordOn();
   }
   else
   {
      if ( wav.sample_rate == 16000 && !wav.fNB2WB)
         AM_PCM16K_RecordOn();
      else
      {
         uint16 I;
         *DSP_PCM_REC_CTRL  = 0x200;
         AM_PCM8K_RecordOn();
         for( I = 0; ; I++ ) {
            if( *DSP_PCM_REC_CTRL == 0x400 )
               break;
            ASSERT_REBOOT( I < 20 );
            kal_sleep_task( 2 );
         }
      }
   }
#endif  // chip compile option
}

void wavRecord( mediaControl *ctrl, void *param )
{
   uint16 I, frame_len;
   wav.ctrl = ctrl;

   wav.BlockCount = 0;
   wav.data_count  = 0;

   if (param != NULL) {
      Media_Record_File_Info *info;
      
      info = (Media_Record_File_Info *)param;
      wavHeader.wSamplesWritten = info->sampleCount;
      wavHeader.wDataLength = info->dataSize;
      wav.ctrl->file_len = (info->fileSize >> 1);
   } else {
      wavHeader.wSamplesWritten = 0;
      wavHeader.wDataLength = 0;
   }

#if defined(__I2S_WAV_RECORD__)
   if(!I2S_is_I2S_open())
#endif
   {
#ifdef   DSP_DEBUG_DEDICATED_MODE_RECORD
      ASSERT(ctrl->rb_size > FRAME_BUF_SIZE * FRAME_BUF_NO * 4);
      ctrl->rb_size -= FRAME_BUF_SIZE * FRAME_BUF_NO * 2; /* Get temp buffer */
      for( I = 0; I < FRAME_BUF_NO; I++ )
         wav.tmp_buf[I] = &ctrl->rb_base[ctrl->rb_size + FRAME_BUF_SIZE*I*2];
#else    // DSP_DEBUG_DEDICATED_MODE_RECORD
      if (( ctrl->format == MEDIA_FORMAT_WAV_DVI_ADPCM_16K ) || (ctrl->format == MEDIA_FORMAT_WAV_16K))
         frame_len = FRAME_BUF_SIZE_16K;
      else
      {
#if defined(__DUAL_MIC_SUPPORT__)
         if((L1Audio_GetDebugInfo(STEREO_RECORD_INFO) & 1) == 1 && ( wav.ctrl->format == MEDIA_FORMAT_WAV || wav.ctrl->format == MEDIA_FORMAT_WAV_DVI_ADPCM )){
            wav.ctrl->format = MEDIA_FORMAT_WAV;
            wav.ctrl->is_stereo = KAL_TRUE;
         }
         else
            wav.ctrl->is_stereo = KAL_FALSE;
#endif
#if defined(__DUAL_MIC_SUPPORT__)
         if( wav.ctrl->is_stereo ){
            frame_len = FRAME_BUF_SIZE*2;
            wav.tmp_buf_dual_mic = &ctrl->rb_base[ctrl->rb_size + frame_len*FRAME_BUF_NO];
         }
         else
#endif
         frame_len = FRAME_BUF_SIZE;
      }
#if defined(__DUAL_MIC_SUPPORT__)
      ASSERT(ctrl->rb_size > frame_len * FRAME_BUF_NO * 2 + frame_len );
      ctrl->rb_size -= (frame_len * FRAME_BUF_NO + frame_len); /* Get temp buffer */
#else
      ASSERT(ctrl->rb_size > frame_len * FRAME_BUF_NO * 2);
      ctrl->rb_size -= frame_len * FRAME_BUF_NO; /* Get temp buffer */
#endif
      for( I = 0; I < FRAME_BUF_NO; I++ )
         wav.tmp_buf[I] = &ctrl->rb_base[ctrl->rb_size + frame_len*I];
#endif   // DSP_DEBUG_DEDICATED_MODE_RECORD
      wav.tmp_r = 0;
      wav.tmp_w = 0;
   }
#ifdef   DSP_DEBUG_DEDICATED_MODE_RECORD
   wav.ctrl->format = MEDIA_FORMAT_WAV;
#endif   // DSP_DEBUG_DEDICATED_MODE_RECORD

   {
      uint32 writeOffset = 0;
      wav.sample_rate = 8000;
      switch(wav.ctrl->format){
         case MEDIA_FORMAT_PCM_8K:
            wav.PutSample = wavRECpcmPutSample;
            wav.data_size = 1;
            wavHeader.wRiffLength=0;
            writeOffset = 0;
            break;
         case MEDIA_FORMAT_WAV_16K:
            wav.sample_rate = 16000;
         case MEDIA_FORMAT_WAV:
            wav.PutSample = wavRECpcmPutSample;
            wav.data_size = 1;
            wavHeader.wRiffLength=36;
            writeOffset = 22;
            break;
         case MEDIA_FORMAT_WAV_ALAW:
         case MEDIA_FORMAT_WAV_ULAW:
            wav.PutSample = (wav.ctrl->format == MEDIA_FORMAT_WAV_ALAW)? wavRECalawPutSample:wavRECulawPutSample;
            wav.data_size = 2;
            wavHeader.wRiffLength=50;
            writeOffset = 29;
            break;
         case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
            wav.sample_rate = 16000;
         case MEDIA_FORMAT_WAV_DVI_ADPCM:
            wav.PutSample = wavRECdviPutSample;
            wav.data_size = 4;
            wavHeader.wRiffLength=52;
            writeOffset = 30;
            dviAdpcm_Init( &wav.dvi_state_ch1 );
      }
      if (param == NULL) {
         wav.ctrl->write += writeOffset;
      } else {
         Media_Record_File_Info *info;
      
         info = (Media_Record_File_Info *)param;
         wavHeader.wRiffLength = info->fileSize-8;
      }
   }
   wav.dedicated_mode = AM_IsSpeechOn();
#if defined (__BT_DIALER_SUPPORT__)
   {
      kal_uint32 uCurrentSpMode = L1SP_GetSpeechMode();
      
      if(uCurrentSpMode == SPH_MODE_BT_CORDLESS)
   	   {
   	   	   wav.dedicated_mode = KAL_TRUE; 
   	   }
   }
#endif
   if(!wav.dedicated_mode)
   {
      wavUpsample_Init();
   }
   wavInternalRecord();
}
#ifdef __MM_DCM_SUPPORT__ 
#pragma arm section code, rodata
#endif

#if defined(REAL_RESUMING_SUPPORT)
void wavSetAdpcmState(bool realResume, uint32 mode)
{
   if(realResume)
   {
      wav.BlockCount = tmp_BlockCount[mode];
      wav.dvi_state_ch1.index = tmp_dvi_state_ch1[mode].index;
      wav.dvi_state_ch2.index = tmp_dvi_state_ch2[mode].index;
      wav.dvi_state_ch1.valpred = tmp_dvi_state_ch1[mode].valpred;
      wav.dvi_state_ch2.valpred = tmp_dvi_state_ch2[mode].valpred;

      memcpy(wav.ms_adpcm_state, tmp_ms_adpcm_state[mode], 2*sizeof(MS_ADPCM_STATE));
      memcpy(wav.aCoeff, tmp_aCoeff[1], 20*sizeof(short));

   } else
    {
      wav.BlockCount = 0;  /* reset counter */
    }
}

void wavGetAdpcmState(uint32 mode)
{
    tmp_BlockCount[mode] = wav.BlockCount;
    tmp_dvi_state_ch1[mode].index = wav.dvi_state_ch1.index;
    tmp_dvi_state_ch2[mode].index = wav.dvi_state_ch2.index;
    tmp_dvi_state_ch1[mode].valpred = wav.dvi_state_ch1.valpred;
    tmp_dvi_state_ch2[mode].valpred = wav.dvi_state_ch2.valpred;

    memcpy(tmp_ms_adpcm_state[mode], wav.ms_adpcm_state, 2*sizeof(MS_ADPCM_STATE));
    memcpy(tmp_aCoeff[mode], wav.aCoeff, 20*sizeof(short));
}

void wavCopyAdpcmState(uint32 src_mode, uint32 dst_mode)
{
    tmp_BlockCount[dst_mode] = tmp_BlockCount[src_mode];
    memcpy( &tmp_dvi_state_ch1[dst_mode], &tmp_dvi_state_ch1[src_mode], sizeof(dviAdpcm_State) );
    memcpy( &tmp_dvi_state_ch2[dst_mode], &tmp_dvi_state_ch2[src_mode], sizeof(dviAdpcm_State) );
    memcpy( tmp_ms_adpcm_state[dst_mode], tmp_ms_adpcm_state[src_mode], sizeof(MS_ADPCM_STATE) );
    memcpy(tmp_aCoeff[dst_mode], tmp_aCoeff[src_mode], 20*sizeof(short));
}
#endif

#ifdef __MM_DCM_SUPPORT__   
#pragma arm section code = "DYNAMIC_CODE_WAVREC_ROCODE", rodata = "DYNAMIC_CODE_WAVREC_RODATA"
#endif
void wavRecordTurnOffDSP(void)
{
#if defined(__I2S_WAV_RECORD__)
   if(wav.ctrl->is_I2S_input)
      return;
#endif
   
   if (wav.sample_rate == 16000 && !wav.fNB2WB )
   {
      AM_PCM16K_RecordOff( true );
   }
   else
   {
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
// MT6260 does not support state machine PCM record control
      AM_PCM8K_RecordOff( true );
#else   // chip compile option
      {
         uint16 I, ctl;
         for( I = 0; ; I++ ) {
            ctl = *DSP_PCM_REC_CTRL;
            if( ctl == 0 )                /* DSP returns to idle state */
               break;
            if( ctl == 0x400 )
               *DSP_PCM_REC_CTRL = 0x800;  /* give ABORT command to the DSP */
            ASSERT_REBOOT( I < 20 );
            kal_sleep_task( 2 );
         }
         AM_PCM8K_RecordOff( true );
      }
#endif  // chip compile option
   }

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   Media_Unhook_Record_HISR();
#endif  // chip compile option
}


void wavStop( mediaControl *ctrl )
{
   (void) ctrl;
   
   wav.ctrl->end_status = MEDIA_TERMINATED;
   if(wav.state == WAV_STATE_IDLE)
   {
      wavUpsample_Free();
      return;
   }
   switch(wav.state) {
      case WAV_STATE_RECORDING:
      case WAV_STATE_RECORD_PAUSE:
         wavRecordTurnOffDSP();
         break;
      default:
         ASSERT(KAL_FALSE);
   }
   wav.state = WAV_STATE_IDLE;  /* return to idle state */

   if ( (wav.ctrl->format==MEDIA_FORMAT_WAV_DVI_ADPCM  || wav.ctrl->format==MEDIA_FORMAT_WAV_DVI_ADPCM_16K )
      && wav.BlockCount != 128){
      L1Audio_SetEvent( wav.aud_id, (void *)0 );        /* zero padding */
   }
   wavUpsample_Free();
}


void wavPause(mediaControl *mctrl)
{
   wav.ctrl->end_status = MEDIA_TERMINATED;
   switch(wav.state) {
      case WAV_STATE_RECORDING:
         wavRecordTurnOffDSP();
         wav.state = WAV_STATE_RECORD_PAUSE;
         break;
      default:
         ASSERT(KAL_FALSE);
   }
}

void wavResume(mediaControl *mctrl)
{
   switch(wav.state) {
      case WAV_STATE_RECORD_PAUSE:
         wav.state = WAV_STATE_RECORDING;
         wavInternalRecord();
         break;
      default:
         ASSERT(KAL_FALSE);
   }
}

#ifdef __MM_DCM_SUPPORT__ 
#pragma arm section code, rodata
#endif

void wavPlayTurnOffDSP(void)
{
   uint16 I, ctl;
   for( I = 0; ; I++ ) {
      ctl = *DSP_PCM_CTRL;
      if( ctl == 0 )                /* DSP returns to idle state */
         break;
      if( ctl == 8 )
         *DSP_PCM_CTRL = WAV_ABORT_STATE;       /* give ABORT command to the DSP */
      ASSERT_REBOOT( I < 40 );
      kal_sleep_task( 2 );
   }

   if (wav.ctrl->is_8KVoice)
      AM_PCM8K_PlaybackOff( true );
   else
      AM_AudioPlaybackOff( true );
}


void wavGetFileHeader( uint32 *len )
{
   rb_ClearRB();
   rb_PutDWord( 0x46464952 );/* RIFF , 0*/

   if((wavHeader.wRiffLength+8) == (wav.ctrl->file_len<<1)){
      rb_PutDWord(wavHeader.wRiffLength);   /* file size , 2*/
   }else{
       rb_PutDWord((wav.ctrl->file_len<<1)-8);   /* file size , 2*/
       wavHeader.wDataLength -= (wavHeader.wRiffLength+8)-(wav.ctrl->file_len<<1);
       if( wav.ctrl->format == MEDIA_FORMAT_WAV_DVI_ADPCM || wav.ctrl->format == MEDIA_FORMAT_WAV_DVI_ADPCM_16K )
          wavHeader.wSamplesWritten = (wavHeader.wDataLength>>8)*505;
       else
          wavHeader.wSamplesWritten = wavHeader.wDataLength;
    }

   rb_PutDWord( 0x45564157 );  /* WAVE , 4 */
   rb_PutDWord( 0x20746D66 );   /* fmt , 6 */

   switch (wav.ctrl->format) {
      case MEDIA_FORMAT_WAV:     /* linear PCM */
      case MEDIA_FORMAT_WAV_16K:
         rb_PutDWord(16);   /* wavHeader.wFmtSize , 8 */
         rb_PutWord(0x01); /*wavHeader.wFormatTag, 10 */
#ifdef   DSP_DEBUG_DEDICATED_MODE_RECORD
         rb_PutWord(2); /*wavHeader.wChannels , 11 */
#elif defined (__I2S_UNIT_TEST__)
         if(I2S_is_I2S_open())
            rb_PutWord(2); /*wavHeader.wChannels , 11 */
         else
            rb_PutWord(1); /*wavHeader.wChannels , 11 */
#elif defined(__DUAL_MIC_SUPPORT__)
         if((L1Audio_GetDebugInfo(STEREO_RECORD_INFO) & 1) == 1 ){
            rb_PutWord(2); /*wavHeader.wChannels , 11 */
         }
         else{
            rb_PutWord(1); /*wavHeader.wChannels , 11 */
         }
#else    // DSP_DEBUG_DEDICATED_MODE_RECORD
         rb_PutWord(1); /*wavHeader.wChannels , 11 */
#endif   // DSP_DEBUG_DEDICATED_MODE_RECORD
         rb_PutDWord(wav.sample_rate); /* wavHeader.wSamplesPerSecond, 12 */
#ifdef __I2S_UNIT_TEST__
         rb_PutDWord(wav.sample_rate*2*2); /*wavHeader.wAvgBytesPerSec, 14 */ //stereo LPCM
#else 
         rb_PutDWord(wav.sample_rate*2); /*wavHeader.wAvgBytesPerSec, 14 */
#endif    
         rb_PutWord(2);   /* wavHeader.wBlockAlign, 16 */
         rb_PutWord(16);  /*wavHeader.wBitsPerSample, 17 */
         rb_PutDWord( 0x61746164 );   /* data , 18 */
         rb_PutDWord(wavHeader.wDataLength);   /* data cksize, 20 */
         *len = (uint32)44;   /* Byte pre unit */
         //wav.ctrl->write+=22;
         break;
      case MEDIA_FORMAT_WAV_ALAW:     /* G.711 a-law */
      case MEDIA_FORMAT_WAV_ULAW:     /* g.711 mu-law */
         rb_PutDWord(18);   /* wavHeader.wFmtSize , 8 */
         rb_PutWord((wav.ctrl->format==MEDIA_FORMAT_WAV_ALAW)?0x06:0x07); /*wavHeader.wFormatTag, 10 */
         rb_PutWord(1); /*wavHeader.wChannels , 11 */
         rb_PutDWord(wav.sample_rate); /* wavHeader.wSamplesPerSecond, 12 */
         rb_PutDWord(wav.sample_rate); /*wavHeader.wAvgBytesPerSec, 14 */
         rb_PutWord(1);   /* wavHeader.wBlockAlign, 16 */
         rb_PutWord(8);  /*wavHeader.wBitsPerSample, 17 */
         rb_PutWord(0);  /*wavHeader.wExtSize, 18 */
         rb_PutDWord( 0x74636166 );   /* fact , 19 */
         rb_PutDWord(4);   /* wavHeader.wFactSize, 21 */
         rb_PutDWord(wavHeader.wSamplesWritten); // 23
         rb_PutDWord(0x61746164);/* data, 25 */
         rb_PutDWord(wavHeader.wDataLength);   /* data cksize, 27 */
         *len = (uint32)58;
         //wav.ctrl->write+=29;
         break;
      case MEDIA_FORMAT_WAV_DVI_ADPCM:    /* dvi/ima adpcm */
      case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
         rb_PutDWord(20);   /* wavHeader.wFmtSize , 8 */
         rb_PutWord(0x11); /*wavHeader.wFormatTag, 10 */
         rb_PutWord(1); /*wavHeader.wChannels , 11 */
         rb_PutDWord(wav.sample_rate);/* wavHeader.wSamplesPerSecond, 12 */
         rb_PutDWord(wav.sample_rate*256/505); /*wavHeader.wAvgBytesPerSec, 14 */
         rb_PutWord(256);   /* wavHeader.wBlockAlign, 16 */
         rb_PutWord(4);  /*wavHeader.wBitsPerSample, 17 */
         rb_PutWord(2);  /*wavHeader.wExtSize, 18 */
         rb_PutWord(505);  /* wavHeader.wSamplesPerBlock, 19 */
         rb_PutDWord( 0x74636166 );   /* data , 20 */
         rb_PutDWord(4);   /* wavHeader.wFactSize, 22 */
         rb_PutDWord(wavHeader.wSamplesWritten); // 24
         rb_PutDWord(0x61746164);/* data, 26 */
         rb_PutDWord(wavHeader.wDataLength);   /* data cksize, 28 */
         *len = (uint32)60;
         //wav.ctrl->write+=30;
         break;
      default:
         *len = (uint32) 0;
   }
}

void wavUpdateLevel( void )
{
   AFE_SetDigitalGain( L1SP_AUDIO, wav.ctrl->level );
}

void wavInit( uint16 aud_id )
{
   wav.aud_id = aud_id;
   wav.state = WAV_STATE_IDLE;  /* idle state */
   L1Audio_SetEventHandler( wav.aud_id, wavDataEncode );
}

#if defined(__I2S_WAV_RECORD__)

#ifdef __MM_DCM_SUPPORT__   
#pragma arm section code = "DYNAMIC_CODE_WAVREC_ROCODE", rodata = "DYNAMIC_CODE_WAVREC_RODATA"
#endif
static kal_uint32 wav_i2s_GetMemSize()
{
   return 0;
}

static void wav_i2s_Free(void *hdl)
{
   ASSERT( wav.state == WAV_STATE_RECORDING );
   wav.state = WAV_STATE_IDLE;
}

static void* wav_i2s_Init(void *pEncBuf)
{
   ASSERT( wav.state == WAV_STATE_IDLE );
   wav.state = WAV_STATE_RECORDING;
   return (kal_uint8*)0xFF; //MAUI_03154766
}

static kal_uint32 wav_i2s_process(void *hdl, kal_int16 *inBuf, kal_uint32 inBufLen, kal_uint8 *outBuf, kal_uint32 *outBufLen, kal_bool flush_encoder)
{
   kal_uint32 inDataCnt = inBufLen;      //word
   kal_uint32 outFreeSpace = *outBufLen; //Byte
   
   if(wav.state != WAV_STATE_RECORDING)
      return 0;
   
   outFreeSpace &= 0xFFFFFFFE;

   if( wav.ctrl->format!=MEDIA_FORMAT_WAV_DVI_ADPCM && wav.ctrl->format!=MEDIA_FORMAT_WAV_DVI_ADPCM_16K )
   {
      while(inDataCnt && outFreeSpace)
      {
         kal_uint16 sample_count;
         if(wav.PutSample( (kal_uint16**)&outBuf, *inBuf++, &sample_count)) 
         {
            outFreeSpace-=2;
            wavHeader.wRiffLength+=2;
            wavHeader.wDataLength+=2;
            wavHeader.wSamplesWritten += sample_count;
         }
         inDataCnt--;
      }
   }
   else
   {
      while((inDataCnt>=505)&&(outFreeSpace >= 256))
      {
         kal_int32 I;
         for( I=505-1 ; I>=0 ; I--)
         {
            kal_uint16 sample_count;
            if( wav.PutSample( (kal_uint16**)&outBuf, *inBuf++, &sample_count) ) 
            { 
               outFreeSpace-=2;
               wavHeader.wRiffLength+=2;
               wavHeader.wDataLength+=2;
               wavHeader.wSamplesWritten += sample_count;
            }
            inDataCnt--;
         }
      }
   }
   *outBufLen = *outBufLen - outFreeSpace;
   return (inBufLen - inDataCnt);

}

void wav_I2S_Record(mediaControl *ctrl, kal_uint32 *param, Audio_Encode_Interface *AEI, kal_uint32 sample_rate)
{
   ASSERT(wav.state != WAV_STATE_RECORDING);
   AEI->Process    = wav_i2s_process;
   AEI->Init       = wav_i2s_Init;
   AEI->Free       = wav_i2s_Free;
   AEI->GetMemSize = wav_i2s_GetMemSize;
   wavRecord( ctrl, param );
   wav.sample_rate = sample_rate;
   wav.state = WAV_STATE_IDLE;
}

#ifdef __MM_DCM_SUPPORT__ 
#pragma arm section code, rodata
#endif

#endif    //  #if defined( __I2S_WAV_RECORD__ )
#endif    //  #if !defined(WAV_CODEC)
