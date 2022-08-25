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
 * media.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Audio Playback/Record general interface
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
 *
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
 *==============================================================================
 *******************************************************************************/
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "reg_base.h"
#include "l1d_reg.h"
#include "fs_type.h"
#include "kal_trace.h"
#include "string.h"
#include "fsal.h"
#include "audcoeff_default.h"
#include "ddload.h"
#include "l1audio.h"
#include "audio_def.h"
#include "speech_def.h"
#include "am.h"
#include "media.h"
#include "afe.h"
#include "audio_enum.h"
#include "l1sp_trc.h"
#include "fs_errcode.h"

#if defined(__KARAOKE_SUPPORT__)
#include "karaoke_drv.h"
#endif

#ifdef __MM_DCM_SUPPORT__ 
#include "dcmgr.h"
#endif

#if defined(__CVSD_CODEC_SUPPORT__) 
#include "bt_sco_app.h"
#endif

#if defined(__LOW_COST_SUPPORT_COMMON__)&& (defined(__BT_AUDIO_VIA_SCO__) || defined(__AUD_SW_CODEC__)) //&& !defined(__AUDIO_ULTRA_SLIM__)	
#include "blisrc_exp.h"      
kal_bool Bli_AP_flag  = KAL_FALSE; //1: AP is activate
kal_bool Bli_DRV_flag = KAL_FALSE; //1: BLISRC table exsit
#endif
#if defined( DSP_WT_SYN ) && !defined(__AUDIO_COMPONENT_SUPPORT__)
#include "dspsyn.h"
#endif

#if defined(__AUDIO_STREAMING_NON_RINGBUFFER_SUPPORT__)
#include "mpl_omx_core.h"
#endif

#if defined(__AUDIO_COMPONENT_SUPPORT__)
#include "AudComUtil.h"
#include "pcmsink.h"
#endif

const kal_uint8  SampleRateTable[] = {
   0x00, /*8000*/   0x11,/* 11025 */ 0x12,/* 12000 */
   0x20, /*16000,*/ 0x21,/* 22050,*/ 0x22,/* 24000,*/
   0x40, /*32000,*/ 0x41,/* 44100,*/ 0x42 /* 48000 */
};


#if defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00)
#define PAGE_NUM 2
#elif defined(MT6253) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
#define PAGE_NUM 1
#elif defined(MT6256_S01) || defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#define PAGE_NUM 5
#else
#error The new chip should define DM page number
#endif

#define RECORD_PRESILENCE_NUM 2  //60ms

static struct {
   mediaControl   ctrl;
   void           (*media_handler)( Media_Event event );
   kal_int32      recorded_time;
   kal_uint32     uStopTime; 
   kal_uint32     uPlaybackSampleRate;
   kal_uint16     aud_id;
   Media_CaliType calibration_type;
   Media_Format   uPlaybackFormat;
   kal_uint8      presilence;
   kal_bool       waiting;   
   kal_bool       paused;
   kal_bool       fTimeUp;      
   kal_bool       isDSPdecode;
   kal_bool       isRouteAlways;
#if defined(__KARAOKE_SUPPORT__)
   kal_bool       KaraokMode;
   Media_KaraRec_Mix_CH KaraokMode_rec_mix_ch;
   Media_Kara_opt_mode  KaraokMode_opt_type;
#endif   
#if defined(__AUDIO_RECORD_COMPONENT_SUPPORT__)
   MHdl           *hdl;
   kal_uint8      *header;
   kal_uint32     uHeaderLen;
#endif
#ifdef __MM_DCM_SUPPORT__
   kal_int32      dcm_region;
   kal_bool       fIsDcmLoad;
#endif
} media;

struct {
   kal_uint32 uCurOffset;
   kal_uint32 uResumeFrameOffset;
} audResumeInfo;

#if defined( MED_MODEM )

void PcmSink_InitDigitalGain()
{
}

void PcmSink_SetGain( kal_uint16 uGain )
{
}

kal_uint16 PcmSink_GetGain( kal_uint16 uGain )
{
   return 0;
}

void PcmSink_Mute(kal_bool fMute, kal_uint32 uFunction)
{
}

void PcmSink_TerminateSound()
{
}

#else
extern void PcmSink_TerminateSound(void);
#endif

#if defined(__CVSD_CODEC_SUPPORT__)
extern BT_SCO_APP_MODE BT_SCO_GetCurrentMode(void);
extern void BT_SCO_SpeechPath_ON(BT_SCO_APP_SPEECH_PATH uPath);
#if defined (__BT_AUDIO_VIA_SCO__)
extern kal_uint32 BT_SCO_AudioWriteSilence(kal_uint32 uSampleCount);
#endif
#endif

/* Functions for Ring Buffer Access */

/* Reset the read/write pointers and odd bye flags of ring buffer */
/* This function should be called in Media_SetBuffer to reset the media buffer */
void rb_ClearRB( void )
{
   media.ctrl.read = 0;
   media.ctrl.write = 0;
   media.ctrl.ob_flag_r = false;
   media.ctrl.ob_flag_w = false;
}

/* Return the count of data (in byte) in ring buffer */
/* Note that the data unit of return value is BYTE!!! */
int32 rb_GetByteCount( void )
{
   int32 count;
   count = (int32)media.ctrl.write - (int32)media.ctrl.read;
   if( count < 0 )
      count += media.ctrl.rb_size;
   count <<= 1;
   if( media.ctrl.ob_flag_r )
      count ++;
   if( media.ctrl.ob_flag_w )
      count ++;
   return count;
}

/* Return the remaining space (in byte) of ring buffer */
/* Note that the data unit of return value is BYTE!!! */
int32 rb_GetFreeSpace( void )
{
   int32 count;
   count = (int32)media.ctrl.read - (int32)media.ctrl.write - 1;
   if( count < 0 )
      count += (int32)media.ctrl.rb_size;
   count <<= 1;
   if( media.ctrl.ob_flag_r )
      count --;
   if( media.ctrl.ob_flag_w )
      count --;
   return count;
}

/* Get a byte from ring buffer */
bool rb_GetByte( uint8* data_8 )
{
   if( rb_GetByteCount()==0 )
      return false;     // Buffer underflow
   if( media.ctrl.ob_flag_r )
   {
      *data_8 = media.ctrl.odd_byte_r;
      media.ctrl.ob_flag_r = false;
   }
   else
   {
      // Special Case: there's only one byte in ring buffer and the byte is in odd_byte_w
      if( media.ctrl.read == media.ctrl.write )
      {
         *data_8 = media.ctrl.odd_byte_w;
         media.ctrl.ob_flag_w = false;
         return true;
      }
      *data_8 = (uint8)media.ctrl.rb_base[media.ctrl.read];
      media.ctrl.odd_byte_r = (uint8)(media.ctrl.rb_base[media.ctrl.read] >> 8);
      media.ctrl.ob_flag_r = true;
      if( ++media.ctrl.read == media.ctrl.rb_size )
         media.ctrl.read = 0;
   }
   return true;
}


/* Get a word from ring buffer */
bool rb_GetWord( uint16* data_16 )
{
   if( rb_GetByteCount() < 2 )
      return false;     // Buffer underflow
   if( media.ctrl.ob_flag_r )
   {
      // Special case: there is only one word in ring buffer...
      if( media.ctrl.read == media.ctrl.write )
      {
         *data_16 = media.ctrl.odd_byte_r | ((uint16)media.ctrl.odd_byte_w << 8);
         media.ctrl.ob_flag_r = false;
         media.ctrl.ob_flag_w = false;
         return true;
      }
      *data_16 = media.ctrl.odd_byte_r | (media.ctrl.rb_base[media.ctrl.read] << 8);
      media.ctrl.odd_byte_r = (uint8)(media.ctrl.rb_base[media.ctrl.read] >> 8);
   }
   else
      *data_16 = media.ctrl.rb_base[media.ctrl.read];
   if( ++media.ctrl.read == media.ctrl.rb_size )
      media.ctrl.read = 0;
   return true;
}

/* Get a double word from ring buffer */
bool rb_GetDWord( uint32* data_32 )
{
   if( rb_GetByteCount() < 4 )
      return false;     // Buffer underflow
   if( media.ctrl.ob_flag_r )
   {
      *data_32 = media.ctrl.odd_byte_r;
      *data_32 |= ((uint32)media.ctrl.rb_base[media.ctrl.read] << 8);
      if( ++media.ctrl.read == media.ctrl.rb_size )
         media.ctrl.read = 0;
      // Special Case: there is only one double-word in ring buffer...
      if( media.ctrl.read == media.ctrl.write )
      {
         *data_32 |= ((uint32)media.ctrl.odd_byte_w << 24);
         media.ctrl.ob_flag_r = false;
         media.ctrl.ob_flag_w = false;
         return true;
      }
      *data_32 |= ((uint32)media.ctrl.rb_base[media.ctrl.read] << 24);
      media.ctrl.odd_byte_r = (uint8)(media.ctrl.rb_base[media.ctrl.read] >> 8);
   }
   else
   {
      *data_32 = media.ctrl.rb_base[media.ctrl.read];
      if( ++media.ctrl.read == media.ctrl.rb_size )
         media.ctrl.read = 0;
      *data_32 |= ((uint32)media.ctrl.rb_base[media.ctrl.read] << 16);
   }
   if( ++media.ctrl.read == media.ctrl.rb_size )
      media.ctrl.read = 0;
   return true;
}

/* Peek the value of the incoming byte in ring buffer, without moving forward the read pointer */
bool rb_PeekByte( uint8* data_8 )
{
   if( rb_GetByteCount()==0 )
      return false;     // Buffer underflow
   if( media.ctrl.ob_flag_r )
      *data_8 = media.ctrl.odd_byte_r;
   else
   {
      // Special Case: there's only one byte in ring buffer...
      if( media.ctrl.read == media.ctrl.write )
         *data_8 = media.ctrl.odd_byte_w;
      else
         *data_8 = (uint8)media.ctrl.rb_base[media.ctrl.read];
   }
   return true;
}

/* Peek the value of the incoming word in ring buffer, without moving forward the read pointer */
bool rb_PeekWord( uint16* data_16 )
{
   if( rb_GetByteCount() < 2 )
      return false;     // Buffer underflow
   if( media.ctrl.ob_flag_r )
   {
      // Special Case: there is only one word in ring buffer
      if( media.ctrl.read == media.ctrl.write )
         *data_16 = media.ctrl.odd_byte_r | ((uint16)media.ctrl.odd_byte_w << 8);
      else
         *data_16 = media.ctrl.odd_byte_r | (media.ctrl.rb_base[media.ctrl.read] << 8);
   }
   else
      *data_16 = media.ctrl.rb_base[media.ctrl.read];
   return true;
}

/* Peek the value of the incoming double word in ring buffer, without moving forward the read pointer */
bool rb_PeekDWord( uint32* data_32 )
{
   uint32 tmp_read;
   if( rb_GetByteCount() < 4 )
      return false;     // Buffer underflow
   tmp_read = media.ctrl.read;
   if( media.ctrl.ob_flag_r )
   {
      *data_32 = media.ctrl.odd_byte_r;
      *data_32 |= ((uint32)media.ctrl.rb_base[tmp_read] << 8);
      if( ++tmp_read == media.ctrl.rb_size )
         tmp_read = 0;
      if( tmp_read == media.ctrl.write )
         *data_32 |= ((uint32)media.ctrl.odd_byte_w << 24);
      else
         *data_32 |= ((uint32)media.ctrl.rb_base[tmp_read] << 24);
   }
   else
   {
      *data_32 = media.ctrl.rb_base[tmp_read];
      if( ++tmp_read == media.ctrl.rb_size )
         tmp_read = 0;
      *data_32 |= ((uint32)media.ctrl.rb_base[tmp_read] << 16);
   }
   return true;
}

/* Skip N byte in ring buffer, return the number of bytes skipped */
uint32 rb_SkipNByte( uint32 skip_count )
{
   uint32 ret;
   if( skip_count == 0 )
      return 0;
   ret = rb_GetByteCount();
   if( ret <= skip_count )
   {
      rb_ClearRB();
      return ret;
   }
   ret = skip_count;
   if( media.ctrl.ob_flag_r )
   {
      media.ctrl.ob_flag_r = false;
      if( --skip_count == 0 )
         return 1;
   }
   media.ctrl.read += (skip_count >> 1);
   if( media.ctrl.read >= media.ctrl.rb_size )
      media.ctrl.read -= media.ctrl.rb_size;
   skip_count &= 0x01;
   if( skip_count == 0 )
      return ret;
   media.ctrl.odd_byte_r = (uint8)(media.ctrl.rb_base[media.ctrl.read] >> 8);
   media.ctrl.ob_flag_r = true;
   if( ++media.ctrl.read == media.ctrl.rb_size )
      media.ctrl.read = 0;
   return ret;
}

/* Skip N Words in ring buffer, return the number of words skipped */
uint32 rb_SkipNWord( uint32 skip_count )
{
   uint32 ret;
   if( skip_count == 0 )
      return 0;
   ret = rb_GetByteCount();
   if( (ret >> 1) <= skip_count )
   {
      if((ret & 0x01) == 0)   // If ret is even, then the ring buffer should be cleared
      {
         rb_ClearRB();
         return (ret >> 1);
      }
      else
         ret >>= 1;
   }
   else
      ret = skip_count;

   if( ret == 0 )
      return 0;
   media.ctrl.read += ret - 1;
   if( media.ctrl.read >= media.ctrl.rb_size )
      media.ctrl.read -= media.ctrl.rb_size;
   if( media.ctrl.ob_flag_r )
      media.ctrl.odd_byte_r = (uint8)(media.ctrl.rb_base[media.ctrl.read] >> 8);
   if( ++media.ctrl.read == media.ctrl.rb_size )
      media.ctrl.read = 0;
   return ret;
}

/* Get len bytes from ring buffer to buffer */
/* The return value is the actual number of bytes moved */
int rb_GetNByte( uint8 *buffer, int len )
{
   uint8 *dst_ptr;
   const uint8 *src_ptr;
   int len_to_copy, remaining;
   if( len == 0 )
      return 0;
   ASSERT( buffer != NULL );
   len_to_copy = rb_GetByteCount();
   if( len_to_copy == 0 )
      return 0;
   if( len < len_to_copy )
      len_to_copy = len;
   remaining = len_to_copy;
   dst_ptr = buffer;
   if( media.ctrl.ob_flag_r )
   {
      *dst_ptr = media.ctrl.odd_byte_r;
      media.ctrl.ob_flag_r = false;
      if( --remaining == 0 )
         return 1;
      dst_ptr++;
   }
   if( media.ctrl.write < media.ctrl.read )
   {
      len = (media.ctrl.rb_size - media.ctrl.read ) << 1;
      if( len > remaining )
         len = remaining;
      src_ptr = (uint8*)&media.ctrl.rb_base[media.ctrl.read];
      memcpy( dst_ptr, src_ptr, len & 0xFFFFFFFE );
      dst_ptr += len;
      media.ctrl.read += (len >> 1);
      if( media.ctrl.read == media.ctrl.rb_size )
         media.ctrl.read = 0;
      remaining -= len;
      if( len & 0x01 )
      {
         media.ctrl.ob_flag_r = true;
         media.ctrl.odd_byte_r = *(src_ptr+len);
         if( ++media.ctrl.read == media.ctrl.rb_size )
            media.ctrl.read = 0;
         ASSERT( remaining == 0 );
         return len_to_copy;
      }
   }
   if( remaining )
   {
      src_ptr = (uint8*)&media.ctrl.rb_base[media.ctrl.read];
      memcpy( dst_ptr, src_ptr, remaining & 0xFFFFFFFE );
      media.ctrl.read += (remaining >> 1);
      if( remaining & 0x01 )
      {
         if( media.ctrl.read == media.ctrl.write )
         {
            *(dst_ptr+remaining - 1) = media.ctrl.odd_byte_w;
            media.ctrl.ob_flag_w = false;
         }else
         {
            *(dst_ptr+remaining - 1) = *(src_ptr+remaining - 1);
            media.ctrl.ob_flag_r = true;
            media.ctrl.odd_byte_r = *(src_ptr+remaining);
            media.ctrl.read ++;
         }
      }
   }
   return len_to_copy;
}

/* Put bytes from buffer into ring buffer */
/* The return value is the actual number of bytes moved */
int rb_PutNByte( const uint8 *buffer, int len )
{
   uint8 *dst_ptr;
   const uint8 *src_ptr;
   int len_to_copy, remaining;
   if( len == 0 )
      return 0;
   ASSERT( buffer!=NULL );
   len_to_copy = rb_GetFreeSpace();
   if( len_to_copy == 0 )
      return 0;
   if( len_to_copy > len )
      len_to_copy = len;
   remaining = len_to_copy;
   src_ptr = buffer;
   if( media.ctrl.ob_flag_w )
   {
      media.ctrl.rb_base[media.ctrl.write]=media.ctrl.odd_byte_w | (uint16)*src_ptr << 8;
      media.ctrl.ob_flag_w = false;
      if( ++media.ctrl.write == media.ctrl.rb_size )
         media.ctrl.write = 0;
      if( --remaining == 0 )
         return 1;
      src_ptr++;
   }
   if( media.ctrl.write >= media.ctrl.read )
   {
      // step 1: copy from write index to the end of ring buffer
      len = (media.ctrl.rb_size - media.ctrl.write) << 1;
      if( remaining < len )
         len = remaining;
      dst_ptr = (uint8*)&(media.ctrl.rb_base[media.ctrl.write]);
      memcpy( dst_ptr, src_ptr, len & 0xFFFFFFFE );
      src_ptr += len;
      media.ctrl.write += (len >> 1);
      if( media.ctrl.write == media.ctrl.rb_size )
         media.ctrl.write = 0;
      remaining -= len;
      if( len & 0x01 )
      {
         media.ctrl.ob_flag_w = true;
         media.ctrl.odd_byte_w = *(src_ptr - 1);
         ASSERT( remaining == 0 );
         return len_to_copy;
      }
   }
   if( remaining )
   {
      dst_ptr = (uint8*)&(media.ctrl.rb_base[media.ctrl.write]);
      memcpy( dst_ptr, src_ptr, remaining & 0xFFFFFFFE );
      media.ctrl.write += (remaining >> 1);
      if( media.ctrl.write == media.ctrl.rb_size )
         media.ctrl.write = 0;
      if( remaining & 0x01 )
      {
         media.ctrl.ob_flag_w = true;
         media.ctrl.odd_byte_w = buffer[len_to_copy-1];
      }
   }
   return len_to_copy;
}

/* Put a byte into ringer buffer */
bool rb_PutByte( uint8 data_8 )
{
   if( rb_GetFreeSpace() == 0 )
      return false;     // Buffer overflow
   if( media.ctrl.ob_flag_w )
   {
      media.ctrl.ob_flag_w = false;
      media.ctrl.rb_base[media.ctrl.write] = media.ctrl.odd_byte_w | ((uint16)data_8 << 8);
      if( ++media.ctrl.write == media.ctrl.rb_size )
         media.ctrl.write = 0;
   }
   else
   {
      media.ctrl.odd_byte_w = data_8;
      media.ctrl.ob_flag_w = true;
   }
   return true;
}

/* Put a word into ring buffer */
bool rb_PutWord( uint16 data_16 )
{
   if( rb_GetFreeSpace() < 2 )
      return false;     // Buffer overflow
   if( media.ctrl.ob_flag_w )
   {
      media.ctrl.rb_base[media.ctrl.write] = media.ctrl.odd_byte_w | (data_16 << 8);
      media.ctrl.odd_byte_w = (uint8)(data_16 >> 8);
   }
   else
      media.ctrl.rb_base[media.ctrl.write] = data_16;
   if( ++media.ctrl.write == media.ctrl.rb_size )
      media.ctrl.write = 0;
   return true;
}

/* Put a double word into ring buffer */
bool rb_PutDWord( uint32 data_32 )
{
   if( rb_GetFreeSpace() < 4 )
      return false;     // Buffer overflow
   if( media.ctrl.ob_flag_w )
   {
      media.ctrl.rb_base[media.ctrl.write] = media.ctrl.odd_byte_w | ((uint16)data_32 << 8);
      if( ++media.ctrl.write == media.ctrl.rb_size )
         media.ctrl.write = 0;
      media.ctrl.rb_base[media.ctrl.write] = (uint16)(data_32 >> 8);
      media.ctrl.odd_byte_w = (uint8)(data_32 >> 24);
   }
   else
   {
      media.ctrl.rb_base[media.ctrl.write] = (uint16)data_32;
      if( ++media.ctrl.write == media.ctrl.rb_size )
         media.ctrl.write = 0;
      media.ctrl.rb_base[media.ctrl.write] = (uint16)(data_32 >> 16);
   }
   if( ++media.ctrl.write == media.ctrl.rb_size )
      media.ctrl.write = 0;
   return true;
}

/* Return media.ctrl.read */
uint32 rb_GetReadIndex( void )
{
   return media.ctrl.read;
}

/* Return media.ctrl.write */
uint32 rb_GetWriteIndex( void )
{
   return media.ctrl.write;
}

/* Return media.ctrl.rb_size */
uint32 rb_GetSize( void )
{
   return media.ctrl.rb_size << 1;
}

/* Return media.ctrl.odd_byte_r | ((uint16)media.ctrl.odd_byte_w)<<8 */
uint16 rb_GetOddByte( void )
{
   return media.ctrl.odd_byte_r | ((uint16)media.ctrl.odd_byte_w)<<8;
}

uint16 rb_GetOBFlag( void )
{
   uint16 ret=0;
   if( media.ctrl.ob_flag_r )
      ret |= 1;
   if( media.ctrl.ob_flag_w )
      ret |= 2;
   return ret;
}

/* ------------------------------------------------------------------------------ */
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
// MT6260 does not use this function
#else   // chip compile option
static void mediaDataRequest( void )
{
   if( media.waiting || media.ctrl.eof || (media.ctrl.end_status == MEDIA_END) )
      return;
   if( mediaGetFreeSpace() >= media.ctrl.rb_threshold ) {
      mediaSetEvent( MEDIA_DATA_REQUEST );
      media.waiting = true;
   }
}
#endif  // chip compile option

void mediaDataNotification( void )
{
   if( media.waiting )
      return;
   if( mediaGetDataCount() >= media.ctrl.rb_threshold) {
      mediaSetEvent( MEDIA_DATA_NOTIFICATION );
      media.waiting = true;
      //kal_prompt_trace(MOD_L1SP,"[I2S]rec data notify");
   }
}

#ifndef __L1_STANDALONE__ // avoid link error

extern kal_bool Media_IsRecordTimeUp( void );

void mediaHisr( uint16 flag )
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    (void)flag;
    
    if (   (media.ctrl.magic_no == DP_D2C_PCM_REC_INT && !Media_IsRecordTimeUp())
#if defined(__VAD_SUPPORT__)
        ||  (media.ctrl.magic_no == DP_D2C_3G_DONE_UL)
#endif
        ||  media.ctrl.magic_no == DP_D2C_VM_REC_INT)
    {
        media.recorded_time += 20;
        if (media.recorded_time <= 0)
        {
            return;
        }
        
#if VERIFY_AVSYNC
        if (media.ctrl.magic_no == DP_D2C_VM_REC_INT)
        {
            ut_avsync_record_hisr();
        }
#endif
        
#if (defined(AMRWB_ENCODE) && defined( __AMRWB_SW_ENCODE__ )) || defined(__VORBIS_ENCODE__) || defined(WAV_CODEC) || defined(AMR_CODEC) || defined(__VM_CODEC_SUPPORT__) || defined(DEDI_AMR_REC)
        switch(media.ctrl.format)
        {
#if defined(__VORBIS_ENCODE__)
            case MEDIA_FORMAT_VORBIS:
                VorbisEnc_Hisr();
                break;
#endif
#if defined(DEDI_AMR_REC) || defined(AMR_CODEC)
            case MEDIA_FORMAT_AMR:
            case MEDIA_FORMAT_AMR_TRANSMIT:
                if (media.ctrl.magic_no == DP_D2C_PCM_REC_INT)
                {
#if defined(DEDI_AMR_REC)
                    amr_DediEncRecordHisr();
#endif
                }
#if defined(__VAD_SUPPORT__) && defined(AMR_CODEC)
                else if (media.ctrl.magic_no == DP_D2C_3G_DONE_UL) {
                    amrBabyMonitorRecordHisr();
                }
#endif
                else
                {
#if defined(AMR_CODEC)
                    amrRecordHisr();
#endif
                }
                break;
#endif
#if ((defined(AMRWB_ENCODE) && defined( __AMRWB_SW_ENCODE__ )) || (defined(AMR_CODEC) && !defined( __AMRWB_SW_ENCODE__ )))
            case MEDIA_FORMAT_AMR_WB:
#if defined( __AMRWB_SW_ENCODE__ )
                awbRecordHisr();
#else
                amrRecordHisr();
#endif
                break;
#endif
#if defined(WAV_CODEC)
            case MEDIA_FORMAT_WAV:
            case MEDIA_FORMAT_WAV_ALAW:
            case MEDIA_FORMAT_WAV_ULAW:
            case MEDIA_FORMAT_WAV_DVI_ADPCM:
            case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
            case MEDIA_FORMAT_WAV_16K:
                wavRecordHisr();
                break;
            case MEDIA_FORMAT_PCM_8K:
            case MEDIA_FORMAT_PCM_16K:
            case MEDIA_FORMAT_G711_ALAW:
            case MEDIA_FORMAT_G711_ULAW:
            case MEDIA_FORMAT_DVI_ADPCM:
                pcmRecordHisr();
                break;
#endif
#if defined(__VM_CODEC_SUPPORT__)
            case MEDIA_FORMAT_GSM_HR:
            case MEDIA_FORMAT_GSM_FR:
            case MEDIA_FORMAT_GSM_EFR:
                vmRecordHisr();
                break;
#endif
            default:
                break;
        }
#endif  // if any codec exists
            
        mediaDataNotification();
    }

#else   // chip compile option
   switch( flag ) {
   case DP_D2C_PCM_P:                     /* PCM Playback */
      break;

   case DP_D2C_PCM_R:                     /* PCM Recording */
   case DP_D2C_PCM_TCH_R:
   case DP_D2C_WAV_REC:
      if (Media_IsRecordTimeUp())
         return;
      media.recorded_time += 20;
      if(media.recorded_time <= 0) 
         return;
#if defined(__VORBIS_ENCODE__)
      if( media.ctrl.format == MEDIA_FORMAT_VORBIS )
      {
         VorbisEnc_Hisr();
      }
      else
#endif
#if defined( DEDI_AMR_REC )
      if( media.ctrl.format == MEDIA_FORMAT_AMR )
      {
         amr_DediEncRecordHisr();
      }
      else
#endif   /* DEDI_AMR_REC */
#if defined(WAV_CODEC)
      if( media.ctrl.format == MEDIA_FORMAT_WAV || media.ctrl.format == MEDIA_FORMAT_WAV_ALAW
         || media.ctrl.format == MEDIA_FORMAT_WAV_ULAW || media.ctrl.format == MEDIA_FORMAT_WAV_DVI_ADPCM
         || media.ctrl.format == MEDIA_FORMAT_WAV_DVI_ADPCM_16K || media.ctrl.format == MEDIA_FORMAT_WAV_16K)
      {
         wavRecordHisr();
      }
      else
      {
         pcmRecordHisr();
      }
#endif // #if defined(WAV_CODEC)
      {
         //Do nothing here but avoid only DEDI_AMR_REC without WAV_CODEC spoil the logic.
      }
      mediaDataNotification();
      break;

   case DP_D2C_SE_DONE:
      media.recorded_time += 20;
      if(media.recorded_time <= 0) 
         return;
#if VERIFY_AVSYNC
      ut_avsync_record_hisr();
#endif

#if defined(AMRWB_ENCODE) && defined( __AMRWB_SW_ENCODE__ )
      if ( media.ctrl.format == MEDIA_FORMAT_AMR_WB ) {
         awbRecordHisr();
      } else
#endif

#if defined(__VORBIS_ENCODE__)
      if( media.ctrl.format == MEDIA_FORMAT_VORBIS )
      {
         VorbisEnc_Hisr();
      }
      else
#endif
#if defined(WAV_CODEC)
      if ( media.ctrl.format == MEDIA_FORMAT_PCM_16K )
      {
         pcmRecordHisr();
      } 
      else if (( media.ctrl.format == MEDIA_FORMAT_WAV_DVI_ADPCM_16K ) || (media.ctrl.format == MEDIA_FORMAT_WAV_16K))
      {
         wavRecordHisr();
      } 
      else
#endif // #if defined(WAV_CODEC)

#if defined(AMR_CODEC)
      if ( (media.ctrl.format == MEDIA_FORMAT_AMR) || (media.ctrl.format == MEDIA_FORMAT_AMR_TRANSMIT)
#if !defined( __AMRWB_SW_ENCODE__ )
      	 || (media.ctrl.format == MEDIA_FORMAT_AMR_WB)
#endif
      	 ) 
      {
         amrRecordHisr();
      } 
      else
#endif
#if defined(__VM_CODEC_SUPPORT__)
      if ( media.ctrl.format == MEDIA_FORMAT_GSM_FR ||
          media.ctrl.format == MEDIA_FORMAT_GSM_HR || media.ctrl.format == MEDIA_FORMAT_GSM_EFR)
      {
         vmRecordHisr();
      } 
      else 
#endif
      {
         ASSERT(0);
      }
      mediaDataNotification();
      break;

#if defined(__VM_CODEC_SUPPORT__)
   case DP_D2C_SE_SD_DONE:                /* Voice Memo Recording */
      media.recorded_time += 20;
      if(media.recorded_time <= 0) 
         return;
#if VERIFY_AVSYNC
      ut_avsync_record_hisr();
#endif
      if ( media.ctrl.format == MEDIA_FORMAT_GSM_FR ||
          media.ctrl.format == MEDIA_FORMAT_GSM_HR || media.ctrl.format == MEDIA_FORMAT_GSM_EFR) 
      {
         vmRecordHisr();
         mediaDataNotification();
      }
      break;

   case DP_D2C_SD_DONE:                   /* Voice Memo Playback */
#if VERIFY_AVSYNC
      ut_avsync_play_hisr();
#endif
      vmPlaybackHisr();
      mediaDataRequest();
      break;
#endif
   }
#endif  // chip compile option
}
#endif

#if defined(__AUDIO_COMPONENT_SUPPORT__)

void mhdlHookPcmRut(void)
{
//#if defined( __BT_AUDIO_VIA_SCO__ ) && defined(__AUDIO_COMPONENT_SUPPORT__) 
//   if(L1SP_IsBluetoothOn())
//   {
//      return;
//   }
//#endif
#if !defined(__SMART_PHONE_MODEM__) && !defined(__L1_STANDALONE__) && defined(__AUDIO_COMPONENT_SUPPORT__) && !defined( MED_MODEM )
   if(media.isDSPdecode)
   {
   	  PcmRut_Start(0);
   }
#endif
}

void mhdlUnHookPcmRut(void)
{
	//call this function before ensure PCMRut on
#if defined(__CVSD_CODEC_SUPPORT__)
   if(L1SP_IsBluetoothOn())
   {
      return;
   }
#endif
#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   if(AFE_IsAudioLoudSpk())
   {
      return;
   }
#endif
#if !defined(__SMART_PHONE_MODEM__) && !defined(__L1_STANDALONE__) && defined(__AUDIO_COMPONENT_SUPPORT__) && !defined( MED_MODEM )
   if(media.isDSPdecode)
   {
      PcmRut_Stop();
   }
#endif
   //kal_prompt_trace(MOD_L1SP,"mhdlUnHookPcmRut");
}
#endif

kal_bool fPowerOffAudio = KAL_FALSE;

void Media_PowerOff(void)
{
   fPowerOffAudio = KAL_TRUE;
	AFE_FastCloseSpk();
}

/* ------------------------------------------------------------------------------ */
/*  Media File Playback/Recording Interface                                       */
/* ------------------------------------------------------------------------------ */
extern void AudioPP_Loudness_Registry( void );

void Media_SetOutputDevice( uint8 device )
{
   kal_bool fSwitchDevice = KAL_FALSE;
#ifdef __LINE_IN_SUPPORT__
   if(aud_is_force_use_linein_mic())  //when use linein MIC, we will set loudspeaker and should not change during using linein mic
   	return;
#endif
   if(AFE_GetOutputDevice(L1SP_AUDIO) != device)
   {
      fSwitchDevice = KAL_TRUE;
   }

#if defined(__AUDIO_COMPONENT_SUPPORT__) && !defined(MED_MODEM) && defined( __I2S_INPUT_MODE_SUPPORT__ )
    if (I2S_is_I2S_open() && fSwitchDevice)
    {
        extern void PcmSink_DepopMute(kal_uint32 uMsec);
        PcmSink_DepopMute(500); //depop for loudness
    }
#endif

   AFE_SetOutputDevice( L1SP_VOICE, device );
   AFE_SetOutputDevice( L1SP_AUDIO, device );

#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   if (AM_IsAudioPlaybackOn()!= -1 && fSwitchDevice)
   {
      VIBR_Vibration_Activate();
   }
#endif

#if APM_SUPPORT && defined( __BES_LOUDNESS_SUPPORT__ ) || defined(__BES_LOUDNESS_ON_I2S__)
   AudioPP_Loudness_Registry();
#endif

#if defined( __BES_BASS_SUPPORT__ )
   AudioPP_BassEnhance_Registry();
#endif
#if defined(AUDIO_COMPENSATION_ENABLE)
   if (AM_IsAudioPlaybackOn()!= -1 && fSwitchDevice)
      Audio_Compensation_Activate(0);
#endif
}

void  Media_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{
#if !(defined(IC_MODULE_TEST) || defined(IC_BURNIN_TEST) )
   AFE_SetOutputVolume( L1SP_VOICE, volume1, digital_gain_index );
   AFE_SetOutputVolume( L1SP_AUDIO, volume1, digital_gain_index );
#endif
}

#if defined(__GAIN_TABLE_SUPPORT__)
/* uint32 ext_amp_gain is only for dual path scenario, used for loudspk ext amp gain control.
 Earphone ext amp control is still in gain */
void  Media_SetOutputGainControl( uint32 gain, uint32 ext_amp_gain )
{
   AFE_SetOutputGainControlDualPath( L1SP_AUDIO, ext_amp_gain );
   AFE_SetOutputGainControlDualPath( L1SP_VOICE, ext_amp_gain );
   AFE_SetOutputGainControl( L1SP_VOICE, gain );
   AFE_SetOutputGainControl( L1SP_AUDIO, gain );
}
#endif

void  Media_SetLevelVolume( kal_uint8 MaxAnalogGain, kal_uint8 step, kal_uint8 level )
{
   AFE_SetLevelVolume( L1SP_VOICE, MaxAnalogGain, step,level);
   AFE_SetLevelVolume( L1SP_AUDIO, MaxAnalogGain, step,level);
}

void Media_SetBuffer( uint16 *buffer, uint32 buf_len )
{
   media.ctrl.rb_base = buffer;
   media.ctrl.rb_size = buf_len;
   rb_ClearRB();
   media.ctrl.eof     = false;
   media.ctrl.file_len = 0;
   
   Media_SetRBOffset(0);
}

void Media_GetWriteBuffer( uint16 **buffer, uint32 *buf_len )
{
   int32 count;

   if( media.ctrl.read > media.ctrl.write )
      count = (int32)media.ctrl.read - (int32)media.ctrl.write - 1;
   else if( media.ctrl.read == 0 )
      count = (int32)media.ctrl.rb_size - (int32)media.ctrl.write - 1;
   else
      count = (int32)media.ctrl.rb_size - (int32)media.ctrl.write;

   *buffer = &media.ctrl.rb_base[media.ctrl.write];
   *buf_len = (uint32)count;
}

void Media_WriteDataDone( uint32 len )
{
   media.ctrl.write += len;
   if( media.ctrl.write >= media.ctrl.rb_size )
      media.ctrl.write = 0;
   media.waiting = false;
}

void Media_WriteDataDone_NoWaiting( uint32 len )
{
   media.ctrl.write += len;
   if( media.ctrl.write >= media.ctrl.rb_size )
      media.ctrl.write = 0;
}

void Media_DataFinished( void )
{
   media.ctrl.eof = true;
}

void Media_GetReadBuffer( uint16 **buffer, uint32 *buf_len )
{
   int32 count;

   if( media.ctrl.write >= media.ctrl.read )
      count = (int32)media.ctrl.write - (int32)media.ctrl.read;
   else
      count = (int32)media.ctrl.rb_size - (int32)media.ctrl.read;

   *buffer = &media.ctrl.rb_base[media.ctrl.read];
   *buf_len = (uint32)count;
}

void Media_ReadDataDone( uint32 len )
{
   media.ctrl.read += len;
   media.ctrl.file_len += len;
   if( media.ctrl.read >= media.ctrl.rb_size )
      media.ctrl.read = 0;
   media.waiting = false;

#if defined(__AUDIO_COMPONENT_SUPPORT__)
    {
        extern void APM_SendProcess(void);
        APM_SendProcess();
    }
#endif

#if defined(__AUDIO_RECORD_COMPONENT_SUPPORT__)
   if (media.hdl) {
      MHPB_Internal *ihdl;
      AudComHdlInt *packHdl;
      
      ihdl = (MHPB_Internal *)media.hdl;
      packHdl = (AudComHdlInt *)ihdl->pNodePack->curHdl;
      ACU_SendProcessCommandl(packHdl);
   }
#endif
}

void Media_SetIsDSPDec( kal_bool type )
{
   media.isDSPdecode = type;
}

kal_bool Media_IsDSPDec(void)
{
	return media.isDSPdecode;
}

kal_bool Media_SetIsAlwaysRoute(kal_bool flag)
{
    return media.isRouteAlways = flag;
}

kal_bool Media_IsAlwaysRoute(void)
{
   return media.isRouteAlways;
}

void Media_SetAudioFormat(Media_Format format)
{
   media.uPlaybackFormat = format;
}

Media_Format Media_GetAudioFormat(void)
{
   return media.uPlaybackFormat;
}

void Media_SetSampleRate(kal_uint32 sampleRate)
{
   media.uPlaybackSampleRate = sampleRate;
}

kal_uint32 Media_GetSampleRate(void)
{
   return media.uPlaybackSampleRate;
}

kal_uint32 Media_GetSamplingRateIndex(kal_uint32 sampling_rate)
{
   kal_uint32 uFreqIndex = 0;
   switch (sampling_rate) 
   {
      case 8000:    uFreqIndex = 8; break;
      case 11025:   uFreqIndex = 7; break;
      case 12000:   uFreqIndex = 6; break;
      case 16000:   uFreqIndex = 5; break;
      case 22050:   uFreqIndex = 4; break;
      case 24000:   uFreqIndex = 3; break;
      case 32000:   uFreqIndex = 2; break;
      case 44100:   uFreqIndex = 1; break;
      case 48000:   uFreqIndex = 0; break;
   }
   return uFreqIndex;
}


void Media_SetCalibrationType(Media_CaliType calibration_type)
{
   media.calibration_type = calibration_type;
}


Media_CaliType Media_GetCalibrationType(void)
{
   return media.calibration_type;
}

void Media_AllowPostProcessingOnMidi(kal_bool fEnable)
{ 
#if defined(__AUDIO_COMPONENT_SUPPORT__) && !defined( MED_MODEM ) && defined(DSP_WT_SYN)
    kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AU_ALLOW_MIDI_AUDIOPP, fEnable);
    {
        extern void MelodyComp_SetUsage(kal_bool soundeffect);
        MelodyComp_SetUsage(!fEnable);   //true: sound effect, false: music sound
    }
#endif
}

int32 mediaGetFreeSpace( void )
{
   int32 count;

   count = (int32)media.ctrl.read - (int32)media.ctrl.write - 1;
   if( count < 0 )
      count += (int32)media.ctrl.rb_size;
   return count;
}

int32 mediaGetDataCount( void )
{
   int32 count;

   count = (int32)media.ctrl.write - (int32)media.ctrl.read;
   if( count < 0 )
      count += media.ctrl.rb_size;
   return count;
}

void mediaIncRecordTime( void )
{
   media.recorded_time += 20;
}

kal_int32 Media_GetDataCount( void )
{
   return mediaGetDataCount();
}

bool mediaIsDataConsumed( void )
{
   return media.ctrl.isDataConsumed;
}

mediaControl *mediaGetControl( void )
{
   return &media.ctrl;
}

#if defined(__AUDIO_RECORD_COMPONENT_SUPPORT__)
void Media_SetFileHeader(kal_uint8 *pHeader, kal_uint32 uLen)
{
   if (media.header == NULL)
      media.header = (kal_uint8 *)get_ctrl_buffer( uLen );
   memcpy(media.header, pHeader, uLen);
   media.uHeaderLen = uLen;
}
#endif

/* get .wav file header, return starting address pointer & header-length in byte*/
void Media_GetFileHeader( uint8 **header, uint32 *len )
{
   switch (media.ctrl.format) {
#if defined(WAV_CODEC)
      case MEDIA_FORMAT_WAV:     /* linear PCM */
      case MEDIA_FORMAT_WAV_ALAW:     /* G.711 a-law */
      case MEDIA_FORMAT_WAV_ULAW:     /* g.711 mu-law */
      case MEDIA_FORMAT_WAV_DVI_ADPCM:    /* dvi/ima adpcm */
      case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
      case MEDIA_FORMAT_WAV_16K:
#if defined(__AUDIO_RECORD_COMPONENT_SUPPORT__)
         memcpy(media.ctrl.rb_base, media.header, media.uHeaderLen);
         free_ctrl_buffer(media.header);
         media.header = NULL;
         *len = media.uHeaderLen;
#else
         wavGetFileHeader( len );
#endif
         break;
#endif
   }
   *header = (uint8 *)media.ctrl.rb_base;
}
/* ------------------------------------------------------------------------------ */

#ifdef PCM_EX_UNIT_TEST
#include "pcm4way.h"
static uint32 pcm_ex_test_on = 0;
static uint16 PCM_BUF[160];
static uint16 PCM_UL_BUF[8][160];
static uint16 PCM_DL_BUF[8][160];
static uint32 pcm_buf_rw;

void pcm4way_hisrHdl()
{
   uint32 I;
   int16 *buf1, *buf2;

   buf1 = (int16*)PCM_UL_BUF[pcm_buf_rw];
   buf2 = (int16*)PCM_BUF;
   for(I = 160; I > 0 ; I--)
      *buf2++ = (*buf1++) >> 2;
   PCM4WAY_GetFromMic((uint16*)PCM_UL_BUF[pcm_buf_rw]);
   buf1 = (int16*)PCM_UL_BUF[pcm_buf_rw];
   buf2 = (int16*)PCM_BUF;
   for(I = 160; I > 0 ; I--)
      (*buf2++) += (*buf1++) >> 2 * 3;
   PCM4WAY_PutToSE((const uint16*)PCM_BUF);

   buf1 = (int16*)PCM_DL_BUF[pcm_buf_rw];
   buf2 = (int16*)PCM_BUF;
   for(I = 160; I > 0 ; I--)
      *buf2++ = (*buf1++) >> 2;
   PCM4WAY_GetFromSD((uint16*)PCM_DL_BUF[pcm_buf_rw]);
   buf1 = (int16*)PCM_DL_BUF[pcm_buf_rw];
   buf2 = (int16*)PCM_BUF;
   for(I = 160; I > 0 ; I--)
      (*buf2++) += (*buf1++) >> 2 * 3;
   PCM4WAY_PutToSpk((const uint16*)PCM_BUF);

   pcm_buf_rw ++;
   pcm_buf_rw &= 0x7;
}

void pcm2way_hisrHdl()
{
   uint32 I;
   int16 *buf1, *buf2;

   buf1 = (int16*)PCM_UL_BUF[pcm_buf_rw];
   buf2 = (int16*)PCM_BUF;
   for(I = 160; I > 0 ; I--)
      *buf2++ = (*buf1++) >> 2;
   PCM2WAY_GetFromMic((uint16*)PCM_UL_BUF[pcm_buf_rw]);
   buf1 = (int16*)PCM_UL_BUF[pcm_buf_rw];
   buf2 = (int16*)PCM_BUF;
   for(I = 160; I > 0 ; I--)
      (*buf2++) += (*buf1++) >> 2 * 3;
   PCM2WAY_PutToSpk((const uint16*)PCM_BUF);

   pcm_buf_rw ++;
   pcm_buf_rw &= 0x7;
}

#endif

kal_bool Media_IsRecordSilence( void )
{
   if(media.presilence > RECORD_PRESILENCE_NUM)
   {
      return KAL_FALSE;
   }
   media.presilence++;
   return KAL_TRUE;
}

kal_bool Media_IsRecordTimeUp( void )
{
   if((media.uStopTime && media.recorded_time > media.uStopTime) || media.fTimeUp)
   {
      if(media.fTimeUp==KAL_FALSE)
      {
         mediaSetEvent( MEDIA_STOP_TIME_UP );
         media.fTimeUp = KAL_TRUE;
         media.waiting = KAL_TRUE;
      }
      return KAL_TRUE;
   }
   return KAL_FALSE;
}

void Media_SetRecordedStopTime( kal_uint32 uStopTime )
{
   media.uStopTime = uStopTime;
}

kal_uint32 Media_GetRecordedTime( void )
{
   if(media.recorded_time <= 0) 
      return 0;
   return media.recorded_time;      
}

kal_uint32 Media_IncRecordedTime( kal_uint32 val )
{
    media.recorded_time += val;
    return media.recorded_time;
}

void Media_SetRecordedTime( kal_uint32 val )
{
   media.recorded_time = val;
}

kal_bool Media_IsGSMMode(void)
{
   kal_uint16 uGSM_Mode;
   uGSM_Mode = *DSP_GSM_MODE;
   return (kal_bool)(uGSM_Mode == 0x01);
}

kal_bool Media_IsCSDMode(void)
{
   kal_uint16 uCsdMode, uGSM_Mode;

   uCsdMode = *DSP_TCH_S0_FLAGS;
   uGSM_Mode = *DSP_GSM_MODE;
   uCsdMode &= 0x1F;
   uGSM_Mode &= 0x01;

   if( (uCsdMode>=0x06) && (uCsdMode<=0x0B) && (uGSM_Mode == 0x01))
      return true;
   
   return false;
}

#ifndef __L1_STANDALONE__ // avoid link error


Media_Status amrRecordAppendable( Media_Format format, FS_HANDLE fs, Media_Record_File_Info *info )
{
   kal_uint8 AMR_Header[9];
   uint32 len;
   
   memset(info, 0, sizeof(Media_Record_File_Info));
   if (FS_NO_ERROR != FS_GetFileSize(fs, &info->fileSize) )
   {
      return MEDIA_READ_FAIL;
   }
   FS_Read(fs, AMR_Header, 9, &len);
#if defined(AMR_CODEC)   
   if(MEDIA_FORMAT_AMR == format)
   {
      if(memcmp(AMR_Header, "#!AMR\n", 6)==0)
      {
         return MEDIA_SUCCESS;
      }   
   }
#endif
#if defined( AMRWB_ENCODE )
#if defined( __I2S_INPUT_MODE_SUPPORT__ )
   if(I2S_is_I2S_open())
   {
      return MEDIA_READ_FAIL;      
   }
   else
#endif
   if(MEDIA_FORMAT_AMR_WB == format)
   {
      if(memcmp(AMR_Header, "#!AMR-WB\n", 9)==0)
      {
         return MEDIA_SUCCESS;
      }     
   }   
#endif
   return MEDIA_READ_FAIL;
}

Media_Status Media_RecordAppendable( Media_Format format, FS_HANDLE fs, Media_Record_File_Info *info )
{
   switch (format) {
#if defined(WAV_CODEC)
      case MEDIA_FORMAT_WAV:                /* linear PCM */
      case MEDIA_FORMAT_WAV_ALAW:           /* G.711 a-law */
      case MEDIA_FORMAT_WAV_ULAW:           /* g.711 mu-law */
      case MEDIA_FORMAT_WAV_DVI_ADPCM:      /* dvi/ima adpcm */
      case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
      case MEDIA_FORMAT_WAV_16K:
         return wavRecordAppendable( format, fs, info );
         break;
#endif
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_AMR_TRANSMIT:
      case MEDIA_FORMAT_AMR_WB:
         return amrRecordAppendable( format, fs, info );
         break;
      default:
         return MEDIA_FAIL;
   }
   
   return MEDIA_FAIL;
}

#if defined(__AUDIO_RECORD_COMPONENT_SUPPORT__)
static void CompRecHandler( MHdl *handle, Media_Event event )
{
   media.media_handler(event);
}
#endif

Media_Status Media_Record( Media_Format format, void (*media_handler)( Media_Event event ), void *param )
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MEDIA_RECORD, 0xFE, format, media_handler, param, media.waiting, media.ctrl.rb_base );
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MEDIA_RECORD, 0xFF, Media_IsCSDMode(), Media_IsGSMMode(), AM_IsSpeechOn(), AFE_IsKaraok(), AM_IsAudioPlaybackOn());
   ASSERT( media.paused == false );
   
   media.ctrl.fTransmit = KAL_FALSE;
   
   // stop tone to prevent record noise [6250 issue]
   KT_StopAndWait();
   TONE_StopAndWait();
   DTMF_MCU_StopAndWait();

#if defined(__KARAOKE_SUPPORT__)
#if !defined(__KARAOKE_DVT_TEST__)	
   if (AFE_IsKaraok())
   {
   	  if (AM_IsAudioPlaybackOn()!=-1){
   	     kal_uint32 samplerate  = Media_GetSampleRate(); 
   	     if(samplerate < 16000)
   	     {
   	        if (MEDIA_FORMAT_WAV != format)   	      	  
   	           return MEDIA_FAIL;
   	     } else {
   	        if ( (MEDIA_FORMAT_WAV != format) && (MEDIA_FORMAT_WAV_16K != format) ) 	      	  
   	           return MEDIA_FAIL;
   	     }
   	  }
   	  else
   	  	 return MEDIA_FAIL;
   }
#endif
#endif

   PcmSink_TerminateSound();
#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   VIBR_Vibration_Deactivate();
#endif   

   if( L1Audio_CheckFlag( media.aud_id ) )
      return MEDIA_REENTRY;
   if( media_handler == 0 )
      return MEDIA_NO_HANDLER;
   if( media.ctrl.rb_base == (uint16*)0 )
      return MEDIA_NOT_INITIALIZED;

   L1Audio_SetFlag( media.aud_id );/*Be careful.Before Locking SleepMode, to access DSP sherrif tasks much time. So access DSP must be after SetFlag*/   
   

#if !defined(__GAIN_TABLE_SUPPORT__)
   {
      void sub_SetMicrophoneVolume( uint8 mic_volume );
   /* For the sake of integration, 
      In 8k record, driver will decrease 10dB Microphone Volume, and Speech Enhancement in DSP will compensate it. 
      In 16k record, we has no wideband-speech-enhancement, we cannot decrease Mic-Vol when 16k record 
      Please check Media_Record and L1SP_SetMicrophoneVolume
      */   
#ifndef WB_SPE_SUPPORT        
      if((MEDIA_FORMAT_AMR_WB             == format) ||        
         (MEDIA_FORMAT_WAV_DVI_ADPCM_16K  == format) ||
         (MEDIA_FORMAT_PCM_16K            == format) ||
         (MEDIA_FORMAT_WAV_16K            == format) ||
         ((MEDIA_FORMAT_VORBIS            == format) && !AM_IsSpeechOn()))
      {
         uint8 mic_vol = L1SP_GetMicrophoneVolume();
         sub_SetMicrophoneVolume(mic_vol);           //WB record doesn't decrease by 10dB  
      }
#endif      
   }
#endif

   media.media_handler = media_handler;
   media.ctrl.format = format;
   media.waiting = false;
   media.ctrl.in_speech = AM_IsSpeechOn();
   
#if defined (__BT_DIALER_SUPPORT__)
   //for BT call record 
   {
   	   kal_uint32 uCurrentSpMode = L1SP_GetSpeechMode();
   	   if(uCurrentSpMode == SPH_MODE_BT_CORDLESS)
   	   {
   	   	   media.ctrl.in_speech = KAL_TRUE; 
   	   }
   }  
#endif    
   media.ctrl.CSD_Mode = Media_IsCSDMode();
   //media.recorded_time = -40; // skip two speech frames 
   media.recorded_time = 0; // skip two speech frames 
   media.presilence = 0;
   media.fTimeUp = KAL_FALSE;

#if defined(__CVSD_CODEC_SUPPORT__) 
   if(!media.ctrl.in_speech || BT_SCO_GetCurrentMode() != BT_SCO_APP_MODE_SPEECH )
   {
      BT_SCO_Disable_All_APP();
   }
#endif
   
#if defined(__DUAL_MIC_SUPPORT__)
   if((L1Audio_GetDebugInfo(STEREO_RECORD_INFO) & 1) == 1 && format == MEDIA_FORMAT_WAV_DVI_ADPCM)
      format = MEDIA_FORMAT_WAV; // force to record raw data
#endif

#if VERIFY_AVSYNC
   ut_a2v_record_dsp_start();
#endif

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    // Reset the speech record peak value
    *DSP_PCM_FRM_PEAK_UL = 0;
#endif  // chip compile option

#if defined(__AUDIO_RECORD_COMPONENT_SUPPORT__)
   switch ( format ) {
   #if defined(__VM_CODEC_SUPPORT__)
      case MEDIA_FORMAT_GSM_FR:
      case MEDIA_FORMAT_GSM_HR:
      case MEDIA_FORMAT_GSM_EFR:
         media.hdl = VM_Rec_Open(CompRecHandler, format, param);
         break;
   #endif
   #if defined(AMR_CODEC)
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_AMR_TRANSMIT:
         media.hdl = AMR_Rec_Open(CompRecHandler, param);
         break;
   #endif
   #if defined(AMRWB_ENCODE)
      case MEDIA_FORMAT_AMR_WB:
         media.hdl = AWB_Rec_Open(CompRecHandler, param);
         break;
   #endif
   #if defined(WAV_CODEC)
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_WAV_16K:
      case MEDIA_FORMAT_WAV_ALAW:
      case MEDIA_FORMAT_WAV_ULAW:
      case MEDIA_FORMAT_WAV_DVI_ADPCM:
      case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
         media.hdl = WAV_Rec_Open(CompRecHandler, format, param);
         break;
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
         media.hdl = PCM_Rec_Open(CompRecHandler, param);
         break;
   #endif
   #if defined(__VORBIS_ENCODE__)
      case MEDIA_FORMAT_VORBIS:
         media.hdl = VORBIS_Rec_Open(CompRecHandler, param);
         break;
   #endif
      default:
         L1Audio_ClearFlag( media.aud_id );
   }

   #if defined(__CVSD_CODEC_SUPPORT__) 
   {
      kal_uint32 uCurrentSpMode = L1SP_GetSpeechMode();
      if(( uCurrentSpMode == SPH_MODE_BT_EARPHONE || uCurrentSpMode == SPH_MODE_BT_CARKIT ) && BT_SCO_GetCurrentMode() == BT_SCO_APP_MODE_DISABLE)
      {
         BT_SCO_APP_SPEECH_PATH uScoPath;
         if(media.ctrl.in_speech)
         {
            uScoPath = BT_SCO_APP_SPEECH_PATH_BOTH;
         }
         else
         {
            uScoPath = BT_SCO_APP_SPEECH_PATH_BTDL;
         }
         BT_SCO_SpeechPath_ON(uScoPath);
      }
   }
   #endif

   if(!media.ctrl.in_speech)
      ktLock();
   
   media.hdl->Record( media.hdl );
   
   return MEDIA_SUCCESS;

#else //defined(__AUDIO_RECORD_COMPONENT_SUPPORT__)
#ifdef __MM_DCM_SUPPORT__
    if (!media.fIsDcmLoad)
    {
        kal_bool flag_DCM = KAL_TRUE;
        switch (format)
        {
            case MEDIA_FORMAT_WAV:
            case MEDIA_FORMAT_WAV_ALAW:
            case MEDIA_FORMAT_WAV_ULAW:
            case MEDIA_FORMAT_WAV_DVI_ADPCM:
            case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
            case MEDIA_FORMAT_WAV_16K:
                media.dcm_region = DYNAMIC_CODE_COMPRESS_WAVREC;
                break;
            case MEDIA_FORMAT_PCM_8K:
            case MEDIA_FORMAT_PCM_16K:
            case MEDIA_FORMAT_G711_ALAW:
            case MEDIA_FORMAT_G711_ULAW:
            case MEDIA_FORMAT_DVI_ADPCM:
                media.dcm_region = DYNAMIC_CODE_COMPRESS_PCMREC;
                break;
            case MEDIA_FORMAT_AMR:
            case MEDIA_FORMAT_AMR_TRANSMIT:
                media.dcm_region = DYNAMIC_CODE_COMPRESS_AMRREC;
                break;
            default:
                flag_DCM = KAL_FALSE;
                break;
        }
      
        if (flag_DCM)
        {
            DCM_Load(media.dcm_region, 0, 0);
            media.fIsDcmLoad = KAL_TRUE;
        }
    }
#endif    	
   #if (defined(__I2S_DAF_RECORD__) || defined(__I2S_AMR_RECORD__) || defined(__I2S_WAV_RECORD__) || defined(__I2S_VORBIS_RECORD__))
   if(I2S_is_I2S_open())
   {
      #if defined(__I2S_UNIT_TEST__)
      format = MEDIA_FORMAT_WAV;
      media.ctrl.format = MEDIA_FORMAT_WAV;
      #endif
      if(MEDIA_SUCCESS != I2S_Record_Start(&media.ctrl, param ))
      {
#ifdef __MM_DCM_SUPPORT__
         if(media.fIsDcmLoad)      	
         {
         	  DCM_Unload(media.dcm_region);
            media.dcm_region = 0;
            media.fIsDcmLoad = KAL_FALSE;
         }
#endif         
         return MEDIA_UNSUPPORTED_TYPE;
      }
      media.recorded_time = 0;
      media.ctrl.is_I2S_input = true;
   }else
   #endif
   {
   
   switch( format ) {
   #if defined(__VM_CODEC_SUPPORT__)
      #if defined(__ENABLE_AUDIO_DVT__)
/** For verification of AMR encoder **/
      case MEDIA_FORMAT_GSM_FR:
      case MEDIA_FORMAT_GSM_HR:
      case MEDIA_FORMAT_GSM_EFR:
         {
            kal_uint32 bitRate;
            uint16 vmType;
            
            // Set the mode of AMR according to Debug Info
            bitRate = L1Audio_GetDebugInfo(VM_REC_DEBUG_INFO);
            switch (bitRate) {
               case 5600:
                  vmType = 1;
                  break;
               case 12200:
                  vmType = 2;
                  break;
               case 13000:
                  vmType = 0;
                  break;
               default:
                  if (format == MEDIA_FORMAT_GSM_FR) {
                     vmType = 0;
                  } else if (format == MEDIA_FORMAT_GSM_HR) {
                     vmType = 1;
                  } else {
                     vmType = 2;
                  }
            }
            vmRecord( &media.ctrl, vmType, false );
         }
         break;
      #else
      case MEDIA_FORMAT_GSM_FR:
         vmRecord( &media.ctrl, 0, false );
         break;
      case MEDIA_FORMAT_GSM_HR:
         vmRecord( &media.ctrl, 1, false );
         break;
      case MEDIA_FORMAT_GSM_EFR:
         vmRecord( &media.ctrl, 2, false );
         break;
      #endif
   #endif
         
   #if defined(AMR_CODEC)
      case MEDIA_FORMAT_AMR_TRANSMIT:
         media.ctrl.fTransmit = KAL_TRUE;
      case MEDIA_FORMAT_AMR:
      #ifdef PCM_EX_UNIT_TEST
         memset( (kal_uint8 *)PCM_UL_BUF, 0x0, 2560 );
         memset( (kal_uint8 *)PCM_DL_BUF, 0x0, 2560 );
         pcm_buf_rw = 0;
         if(media.ctrl.in_speech)
         {
            L1SP_EnableSpeechEnhancement(false);
            PCM4WAY_Start(pcm4way_hisrHdl,0);
            pcm_ex_test_on = 1;
         }
         else
         {
            PCM2WAY_Start(pcm2way_hisrHdl,2);
            pcm_ex_test_on = 2;
         }
         return MEDIA_SUCCESS;
      #endif


      #if !defined(__LOW_COST_SUPPORT_COMMON__) || defined(__ENABLE_AUDIO_DVT__)
/** For verification of AMR encoder **/
         {
            kal_uint32 bitRate;
            
            // Set the mode of AMR according to Debug Info
            bitRate = L1Audio_GetDebugInfo(AMR_REC_DEBUG_INFO);
            switch (bitRate) {
               case 4750:
                  param = (void *) 10;
                  break;
               case 5150:
                  param = (void *) 9;
                  break;
               case 5900:
                  param = (void *) 8;
                  break;
               case 6700:
                  param = (void *) 7;
                  break;
               case 7400:
                  param = (void *) 6;
                  break;
               case 7950:
                  param = (void *) 5;
                  break;
               case 10200:
                  param = (void *) 4;
                  break;
               case 12200:
                  param = (void *) 3;
                  break;
            }
         }
      #endif

      #if defined( DEDI_AMR_REC )
         if( media.ctrl.in_speech || media.ctrl.CSD_Mode )
         {
            amr_DediEncRecord(&media.ctrl, (uint32)param);
         }
         else
      #endif   /* DEDI_AMR_REC */
         {
            ASSERT(!media.ctrl.CSD_Mode);
            if( (uint32)param >= 3 && (uint32)param <= 10 )
               amrRecord( &media.ctrl, (uint16)(uint32)param );
            else
               amrRecord( &media.ctrl, 9 ); /* 0x03 - 0x0A */
         }
         break;
   #endif // #if defined(AMR_CODEC)

   #if defined(WAV_CODEC)
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_WAV_ALAW:
      case MEDIA_FORMAT_WAV_ULAW:
      case MEDIA_FORMAT_WAV_DVI_ADPCM:
      case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
      case MEDIA_FORMAT_WAV_16K:
         wavRecord( &media.ctrl, param );
         break;
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
      case MEDIA_FORMAT_G711_ALAW:
      case MEDIA_FORMAT_G711_ULAW:
      case MEDIA_FORMAT_DVI_ADPCM:
         pcmRecord( &media.ctrl );
         break;
   #endif // #if defined(WAV_CODEC)

   #if defined(AMRWB_ENCODE)
      case MEDIA_FORMAT_AMR_WB:
      #if !defined(__LOW_COST_SUPPORT_COMMON__) || defined(__ENABLE_AUDIO_DVT__)
/** For verification of AWB encoder **/
         {
            kal_uint32 bitRate;
            
            // Set the mode of AWB according to Debug Info
            bitRate  = L1Audio_GetDebugInfo(AWB_REC_DEBUG_INFO);
            switch ( bitRate ) {
               case 6600:
                  param = (void *) 0x20;
                  break;
               case 8850:
                  param = (void *) 0x21;
                  break;
               case 12650:
                  param = (void *) 0x22;
                  break;
               case 14250:
                  param = (void *) 0x23;
                  break;
               case 15850:
                  param = (void *) 0x24;
                  break;
               case 18250:
                  param = (void *) 0x25;
                  break;
               case 19850:
                  param = (void *) 0x26;
                  break;
               case 23050:
                  param = (void *) 0x27;
                  break;
               case 23850:
                  param = (void *) 0x28;
                  break;
            }
         }
      #endif

         ASSERT(!media.ctrl.in_speech);
      #if defined( __AMRWB_SW_ENCODE__ )
         if( (uint32)param >= 0x20 && (uint32)param <= 0x28 )/* 0x20 - 0x28 */
            awbEncRecord( &media.ctrl, (uint16)(uint32)param );
         else
            awbEncRecord( &media.ctrl, 0x20 ); 
      #else
         if( (uint32)param >= 0x20 && (uint32)param <= 0x28 )/* 0x20 - 0x28 */
            amrRecord( &media.ctrl, (uint16)(uint32)param );
         else
            amrRecord( &media.ctrl, 0x20 ); 
      #endif
         break;
   #endif

   #if defined(__VORBIS_ENCODE__)
      case MEDIA_FORMAT_VORBIS:
         VorbisEnc_Record( &media.ctrl );
         break;
   #endif
      default:
      	 L1Audio_ClearFlag( media.aud_id );
         return MEDIA_BAD_FORMAT;
   }
   }

   #if defined(__CVSD_CODEC_SUPPORT__) 
   {
      kal_uint32 uCurrentSpMode = L1SP_GetSpeechMode();
      if(( uCurrentSpMode == SPH_MODE_BT_EARPHONE || uCurrentSpMode == SPH_MODE_BT_CARKIT ) && BT_SCO_GetCurrentMode() == BT_SCO_APP_MODE_DISABLE)
      {
         BT_SCO_APP_SPEECH_PATH uScoPath;
         if(media.ctrl.in_speech)
         {
            uScoPath = BT_SCO_APP_SPEECH_PATH_BOTH;
         }
         else
         {
            uScoPath = BT_SCO_APP_SPEECH_PATH_BTDL;
         }
         BT_SCO_SpeechPath_ON(uScoPath);
      }
   }
   #endif

   if(!media.ctrl.in_speech)
      ktLock();
     
   return MEDIA_SUCCESS;

#endif  // #if defined(__AUDIO_RECORD_COMPONENT_SUPPORT__)

}
#endif  //#ifndef __L1_STANDALONE__

void mediaSetWaitingFlag(kal_bool flag)
{
   media.waiting = flag;
}

#ifndef __L1_STANDALONE__ // avoid link error

#if defined(__AUDIO_RECORD_COMPONENT_SUPPORT__)

static void Media_RecCommonOperation(kal_uint32 operation)
{
   if (operation == 0) {
      media.hdl->Pause(media.hdl);
   } else if (operation == 1) {
      media.hdl->Resume(media.hdl);
   } else if (operation == 2) {

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    // Reset the speech record peak value
    *DSP_PCM_FRM_PEAK_UL = 0;
#endif  // chip compile option

      media.hdl->Stop(media.hdl);
      media.hdl->Close(media.hdl);
      media.hdl = NULL;
   }
}

#else

typedef void (*RecOperation)( mediaControl *ctrl );

#if (defined(__I2S_DAF_RECORD__) || defined(__I2S_AMR_RECORD__) || defined(__I2S_WAV_RECORD__) || defined(__I2S_VORBIS_RECORD__))
static const RecOperation i2sRecFun[3] = {I2S_Record_Pause, I2S_Record_Resume, I2S_Record_Stop};
#endif

#if defined(WAV_CODEC)
static const RecOperation pcmRecFun[3] = {pcmPause, pcmResume, pcmStop};
static const RecOperation wavRecFun[3] = {wavPause, wavResume, wavStop};
#endif

#if defined(__VM_CODEC_SUPPORT__)
static const RecOperation vmRecFun[3] = {vmPause, vmResume, vmStop};
#endif

#if defined(AMR_CODEC) && defined( DEDI_AMR_REC )
static const RecOperation amrDediRecFun[3] = {amr_DediEncPause, amr_DediEncResume, amr_DediEncStop};
#endif

#if defined(AMRWB_ENCODE) && defined( __AMRWB_SW_ENCODE__ )
static const RecOperation awbRecFun[3] = {awbEncPause, awbEncResume, awbEncStop};
#endif

#if defined(AMR_CODEC) || (defined(AMRWB_ENCODE) && !defined( __AMRWB_SW_ENCODE__ ))
static const RecOperation amrRecFun[3] = {amrPause, amrResume, amrStop};
#endif

#if defined(__VORBIS_ENCODE__)
static const RecOperation vorbisRecFun[3] = {VorbisEnc_Pause, VorbisEnc_Resume, VorbisEnc_Stop};
#endif

static void Media_RecCommonOperation(kal_uint32 operation)
{
   const RecOperation *funcArray = NULL;

#if (defined(__I2S_DAF_RECORD__) || defined(__I2S_AMR_RECORD__) || defined(__I2S_WAV_RECORD__) || defined(__I2S_VORBIS_RECORD__))
   if(media.ctrl.is_I2S_input)
   {
      funcArray = i2sRecFun;
   } else
#endif
   switch( media.ctrl.format ) {
#if defined(WAV_CODEC)
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
      case MEDIA_FORMAT_G711_ALAW:
      case MEDIA_FORMAT_G711_ULAW:
      case MEDIA_FORMAT_DVI_ADPCM:
         funcArray = pcmRecFun;
         break;
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_WAV_ALAW:
      case MEDIA_FORMAT_WAV_ULAW:
      case MEDIA_FORMAT_WAV_DVI_ADPCM:
      case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
      case MEDIA_FORMAT_WAV_16K:
         funcArray = wavRecFun;
         break;
#endif //#if defined(WAV_CODEC)
         
#if defined(__VM_CODEC_SUPPORT__)
      case MEDIA_FORMAT_GSM_FR:
      case MEDIA_FORMAT_GSM_HR:
      case MEDIA_FORMAT_GSM_EFR:
         funcArray = vmRecFun;
         break;
#endif
         
#if defined(AMR_CODEC)
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_AMR_TRANSMIT:
#if defined( DEDI_AMR_REC )
         if( media.ctrl.in_speech || media.ctrl.CSD_Mode) {
            funcArray = amrDediRecFun;
         } else
#endif   /* DEDI_AMR_REC */
         {
            ASSERT(!media.ctrl.CSD_Mode);
            funcArray = amrRecFun;
         }
         break;

#if defined(AMRWB_DECODE) || defined(AMRWB_ENCODE)
      case MEDIA_FORMAT_AMR_WB:
#if defined( __AMRWB_SW_ENCODE__ )
         funcArray = awbRecFun;
#else
         funcArray = amrRecFun;
#endif
         break;
#endif
#endif //  defined(AMR_CODEC)

#if defined(__VORBIS_ENCODE__)
      case MEDIA_FORMAT_VORBIS:
         funcArray = vorbisRecFun;
         break;
#endif
      default:
         ASSERT(KAL_FALSE);
   }
   
   funcArray[operation](&media.ctrl);
}

#endif  // #if defined(__AUDIO_RECORD_COMPONENT_SUPPORT__)

Media_Status Media_Pause( void )
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MEDIA_PAUSE, 0, 0, 0, 0 ,0 ,0);
   if( !L1Audio_CheckFlag( media.aud_id ) )
      return MEDIA_FAIL;

   media.paused = true;

#if defined(__CVSD_CODEC_SUPPORT__) 
   if(!media.ctrl.in_speech || BT_SCO_GetCurrentMode() != BT_SCO_APP_MODE_SPEECH )
   {
      BT_SCO_Disable_All_APP();
   }
#endif

   Media_RecCommonOperation(0);
   if(!media.ctrl.in_speech)
      ktUnlock();
   L1Audio_ClearFlag( media.aud_id );

   return MEDIA_SUCCESS;
}

Media_Status Media_Resume( void )
{
   KT_StopAndWait();
   TONE_StopAndWait();
   DTMF_MCU_StopAndWait();
   PcmSink_TerminateSound();
#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   VIBR_Vibration_Deactivate();
#endif   

#if defined(__CVSD_CODEC_SUPPORT__) 
   if(!media.ctrl.in_speech || BT_SCO_GetCurrentMode() != BT_SCO_APP_MODE_SPEECH )
   {
      BT_SCO_Disable_All_APP();
   }
#endif
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MEDIA_RESUME, media.paused, 0, 0, 0 ,0,0);
   if( L1Audio_CheckFlag( media.aud_id ) )
      return MEDIA_FAIL;

   ASSERT( media.paused == true );
   media.paused = false;
   media.waiting = false;
   media.presilence = 0;
   media.fTimeUp = KAL_FALSE;
   
   L1Audio_SetFlag( media.aud_id );
   Media_RecCommonOperation(1);
#if defined(__CVSD_CODEC_SUPPORT__) 
   {
      kal_uint32 uCurrentSpMode = L1SP_GetSpeechMode();
      if(( uCurrentSpMode == SPH_MODE_BT_EARPHONE || uCurrentSpMode == SPH_MODE_BT_CARKIT ) && BT_SCO_GetCurrentMode() == BT_SCO_APP_MODE_DISABLE)
      {
         BT_SCO_APP_SPEECH_PATH uScoPath;
         if(media.ctrl.in_speech)
         {
            uScoPath = BT_SCO_APP_SPEECH_PATH_BOTH;
         }
         else
         {
            uScoPath = BT_SCO_APP_SPEECH_PATH_BTDL;
         }
         BT_SCO_SpeechPath_ON(uScoPath);
      }
   }
#endif

   if(!media.ctrl.in_speech)
      ktLock();
  return MEDIA_SUCCESS;
}

void Media_Stop( void )
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MEDIA_STOP, media.paused, media.waiting, media.ctrl.is_I2S_input, 0,0,0);
   
   if( media.paused == true ) {
   	  bool check;
   	  check = L1Audio_CheckFlag( media.aud_id );
      ASSERT( !check );
      L1Audio_SetFlag( media.aud_id );
      media.paused = false;
   }
   else
   {
      if( !L1Audio_CheckFlag( media.aud_id ) )
      return;  
	  
      if(!media.ctrl.in_speech)
         ktUnlock();
   }
   
   media.uStopTime = 0;
   
   if( !L1Audio_CheckFlag( media.aud_id ) )
      return;   

#if VERIFY_AVSYNC
   ut_a2v_dsp_stop();
#endif

   media.waiting = true;      /* Forbid data request */
   
   Media_RecCommonOperation(2);
#if defined(__CVSD_CODEC_SUPPORT__) 
   if(!media.ctrl.in_speech || BT_SCO_GetCurrentMode() != BT_SCO_APP_MODE_SPEECH )
   {
      BT_SCO_Disable_All_APP();
   }
#endif
#ifdef __MM_DCM_SUPPORT__
   if(media.fIsDcmLoad)
   {      	
      DCM_Unload(media.dcm_region);
      media.dcm_region = 0;
      media.fIsDcmLoad = KAL_FALSE;
   }
#endif 
   L1Audio_ClearFlag( media.aud_id );

   Media_SetRBOffset(0);

#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   VIBR_Vibration_Activate();
#endif   

}
#endif

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
void Media_Hook_Record_HISR (kal_uint16 magic_no, void *userData)
{
    media.ctrl.magic_no = magic_no;
#ifndef __L1_STANDALONE__
    L1Audio_HookHisrHandler(magic_no, mediaHisr, userData);
#endif
    return;
}

void Media_Unhook_Record_HISR (void)
{
#ifndef __L1_STANDALONE__
    L1Audio_UnhookHisrHandler(media.ctrl.magic_no);
#endif
    media.ctrl.magic_no = 0;
    return;
}
#endif  // chip compile option

Media_Status Media_Control( Media_Ctrl ctrl_no, int32 ctrl_val )
{
   switch( ctrl_no ) {
   case MEDIA_CTRL_MAX_SWING:
      return MEDIA_BAD_COMMAND;
   case MEDIA_CTRL_KEY_SHIFT:
      return MEDIA_BAD_COMMAND;
   default:
      return MEDIA_BAD_COMMAND;
   }
   return MEDIA_SUCCESS;
}


void Media_SetMelodyFilter( uint16 len, const int16 *filter )
{      
#if defined( DSP_WT_SYN ) && !defined(__AUDIO_COMPONENT_SUPPORT__)   
   int32 I;    
   int16 *dspsyn_filter;
   ASSERT( len == 25 ); 
   dspsyn_filter = DSPSYN_GetFilterPtr();            
   for( I = 0; I < 25; I++ )
      *dspsyn_filter++ = *filter++;             
#endif         
}

void Media_SetUserData(Media_Handle *hdl, void* pAppData)
{
   hdl->pApplicateData = pAppData;
}

void Media_GetUserData(Media_Handle *hdl, void** pAppData)
{
   *pAppData = hdl->pApplicateData;
}

void Media_MuteSpeaker( bool mute )
{
   kal_uint16 aud_id;
   aud_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( aud_id );		// set flag due to PcmSink_UpdateGain would set dsp sheriff	
	
   AFE_MuteSpeaker( L1SP_AUDIO, mute );
   AFE_MuteSpeaker( L1SP_VOICE, mute );
#if defined(__AUDIO_COMPONENT_SUPPORT__) && !defined( MED_MODEM )
   PcmSink_UpdateGain();
#endif
   
   L1Audio_ClearFlag( aud_id );
   L1Audio_FreeAudioID( aud_id );
}

/* ------------------------------------------------------------------------------ */
void mediaHandler( void *data )     /* This function works in L1Audio Task */
{
   Media_Event event = (Media_Event)(int32)data;

   if( event == MEDIA_TERMINATED || !L1Audio_CheckFlag( media.aud_id ))      /* MEDIA_TERMINATED is no longer used */
      return;
   if( event == MEDIA_END || event == MEDIA_ERROR ) {
      L1Audio_ClearFlag( media.aud_id );
      media.waiting = false;
   }
   media.media_handler( event );
}
/* ------------------------------------------------------------------------------ */
#if defined(WAV_CODEC) || defined(AAC_PLUS_PS_DECODE) || defined(AWB_PLUS_DECODE)
kal_semid  WAVsema;
#endif

void mediaInit( uint16 aud_id )
{
#if defined(WAV_CODEC) || defined(AAC_PLUS_PS_DECODE) || defined(AWB_PLUS_DECODE)
   WAVsema = kal_create_sem( "wav_sema", 1 );
#endif
   media.aud_id = aud_id;
   L1Audio_SetEventHandler( media.aud_id, mediaHandler );

#if defined( __VORBIS_ENCODE__ )
   VorbisEnc_Init( L1Audio_GetAudioID() );
#endif
#if defined( DEDI_AMR_REC )
   amr_DediEncInit( L1Audio_GetAudioID() );
#endif   /* DEDI_AMR_REC */
#if defined(WAV_CODEC)
   wavInit( L1Audio_GetAudioID() );
#endif

#if defined( DSP_WT_SYN ) && !defined(__AUDIO_COMPONENT_SUPPORT__)
   DSPSYN_Init();
   JSmf_Init();
   JImy_Init();
#if defined(WAV_CODEC)
   JWav_Init( &media.ctrl );
#endif
   Media_SetMelodyFilter( 25, Melody_FIR );
#endif

   media.ctrl.rb_threshold = MEDIA_RB_DEFAULT_THRESHOLD;
   media.ctrl.max_swing = (int32)Media_Playback_Maximum_Swing >> 3;
   media.ctrl.key_shift = 0;
   media.ctrl.level = 100;
   media.ctrl.rb_base = (uint16*)0;
   media.uStopTime = 0;
   media.fTimeUp = KAL_FALSE;
   media.isDSPdecode = KAL_FALSE;
   media.uPlaybackSampleRate = 0;
#ifdef __MM_DCM_SUPPORT__   
   media.fIsDcmLoad = KAL_FALSE;
   media.dcm_region = 0;
#endif   
   media.calibration_type = 0;

#if defined(__KARAOKE_SUPPORT__)
   media.KaraokMode = KAL_FALSE;
   media.KaraokMode_opt_type   = MEDIA_KARAPLAY_MIX_NONE;
   media.KaraokMode_rec_mix_ch = MEDIA_KARAREC_MIX_NONE;
#endif
}

/* If the event is MEDIA_END or MEDIA_ERROR, make sure DSP has been stopped
   before calling this function. Refer to the function: mediaHandler */
void mediaSetEvent( Media_Event event )
{
   L1Audio_SetEvent( media.aud_id, (void *)event );
}

void Media_SetRBThreshold( uint16 threshold )
{
   media.ctrl.rb_threshold = threshold;
}

void Media_SetRBOffset( kal_uint32 uOffset )
{
   ASSERT( uOffset < media.ctrl.rb_size);

   media.ctrl.uOffset = uOffset;
}

#ifndef __L1_STANDALONE__ // avoid link error

#if defined(AAC_DECODE)

#define AAC_ADTS_LENGTH 7
static const kal_uint8 AAC_Header[AAC_ADTS_LENGTH] = { 0xFF, 0xF9, 0x40, 0x20, 0x00, 0x1F, 0xFC };

#endif

#if defined(__AUDIO_STREAMING_NON_RINGBUFFER_SUPPORT__)

#if defined(AAC_DECODE)
static void aacPutBits(unsigned char *in, unsigned int *bitcnt, int data, int data_length)
{
   int t,count;

   ASSERT(data_length>0 && data_length<=16);

   t = *bitcnt;

   if( (t & 0x7)== 0)
   {
      in[t>>3] = 0;
   }
   
   if( (t & 0x7) + data_length  <= 8)
   {
      in[(t>>3)] |= (data << (8-((t&0x7) + data_length)));
   }
   else
   {
      count = (t&7) + data_length;
      in[(t>>3)] |= (data >> (data_length - 8 + (t&7)));
      count -= 8;
      if(count > 8) 
      {
         in[(t>>3)+1] = (unsigned char)((data >> (count-8))&0xFF);
         in[(t>>3)+2] = (unsigned char)((data << (16-count))&0xFF);
      }
      else
      {
         in[(t>>3)+1] = (unsigned char)((data << (8-count))&0xFF);
      }
   }
   *bitcnt += data_length;
}

static void aacUpdateFrameLen(kal_uint8 *pBuf, kal_uint32 uLength)
{
   kal_uint8 uChar1, uChar2, uChar3;
   uChar1 = (kal_uint8)((uLength >> 11) & 0x03);
   uChar2 = (kal_uint8)((uLength >> 3)  & 0xFF);
   uChar3 = (kal_uint8)((uLength << 5)  & 0xE0);
   pBuf[0] = (pBuf[0] & ~0x03) | uChar1;
   pBuf[1] = (pBuf[1] & ~0xFF) | uChar2;
   pBuf[2] = (pBuf[2] & ~0xE0) | uChar3;
}

static void aacUpdateADTSHeader(kal_uint8 *pHeader, kal_uint32 uFrameLen)
{
   aacUpdateFrameLen(&pHeader[3], uFrameLen+AAC_ADTS_LENGTH);
}

static void aacInitADTSHeader(kal_uint8 *pHeader, kal_uint32 uSR, kal_uint32 uCh)
{
   kal_uint32 uSRIdx = 0, uBitCnt = 0;
   memcpy(pHeader, AAC_Header, 7);

   switch (uSR)
   {
      case  8000:  uSRIdx = 11;  break;
      case 11025:  uSRIdx = 10;  break;
      case 12000:  uSRIdx = 9;   break;
      case 16000:  uSRIdx = 8;   break;
      case 22050:  uSRIdx = 7;   break;
      case 24000:  uSRIdx = 6;   break;
      case 32000:  uSRIdx = 5;   break;
      case 44100:  uSRIdx = 4;   break;
      case 48000:  uSRIdx = 3;   break;     
      case 64000:  uSRIdx = 2;   break;     
      case 88200:  uSRIdx = 1;   break;     
      case 96000:  uSRIdx = 0;   break;     
      default:
         ASSERT(0);   // Unknown
   }
   
   uBitCnt = 18;
   aacPutBits(pHeader, &uBitCnt, uSRIdx, 4);      // Reserve sample_frequency_index
   uBitCnt = 23;
   aacPutBits(pHeader, &uBitCnt, uCh, 3);      // Reserve Channel_configuration
}
#endif //defined(AAC_DECODE)

static kal_uint32 Media_GetFrameDuration(Media_Format format, kal_uint32 uSampleRate)
{
   switch (format) 
   {
#if defined(AMR_CODEC) || defined(AMRWB_DECODE)
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_AMR_TRANSMIT:
      case MEDIA_FORMAT_AMR_WB:
      case MEDIA_FORMAT_MP4_AMR:
      case MEDIA_FORMAT_MP4_AMR_WB:
         return (20*1000);
#endif
#if defined(WAV_CODEC)
      case MEDIA_FORMAT_PCM:
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
      case MEDIA_FORMAT_WAV:
         return 10*1000;
#endif
#if defined(__DRA_DECODE_SUPPORT__)
      case MEDIA_FORMAT_DRA:
#endif
#if defined(AAC_DECODE)
      case MEDIA_FORMAT_AAC:
      case MEDIA_FORMAT_MP4_AAC:
      case MEDIA_FORMAT_AAC_PLUS:
      case MEDIA_FORMAT_AAC_PLUS_V2:
         return 1024*1000*1000 / uSampleRate;
#endif
#if defined(DAF_DECODE)
      case MEDIA_FORMAT_DAF:
         return 1152*1000*1000 / uSampleRate;

#endif
#if defined(MUSICAM_DECODE)
      case MEDIA_FORMAT_MUSICAM:
         return 576*1000*1000 / uSampleRate;
#endif
      default:
         ASSERT(0);
   }
   return 0;
}

static kal_bool AudBufQ_IsDataReady( Media_Format uFormat, kal_uint32 uFrameNum, kal_uint32 uBistreamLen)
{
   switch (uFormat) 
   {
#if defined(AMR_CODEC) || defined(AMRWB_DECODE)
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_AMR_TRANSMIT:
      case MEDIA_FORMAT_AMR_WB:
      case MEDIA_FORMAT_MP4_AMR:
      case MEDIA_FORMAT_MP4_AMR_WB:
         if( uBistreamLen > 1024)
         {
            return KAL_TRUE;
         }
         break;
#endif
#if defined(AAC_DECODE)
      case MEDIA_FORMAT_AAC:
      case MEDIA_FORMAT_MP4_AAC:
      case MEDIA_FORMAT_AAC_PLUS:
      case MEDIA_FORMAT_AAC_PLUS_V2: 
         if(uFrameNum > 60)
         {
            return KAL_TRUE;
         }
#endif
      default:
         if( uBistreamLen > VIDEO_READY_THRESHOLD)
         {
            return KAL_TRUE;
         }
         break;
   }
   return KAL_FALSE;
}

static kal_bool AudBufQ_IsEmpty(AudStrmStruct *pStrmStruct)
{
   ASSERT(pStrmStruct->uQueueWrite >= pStrmStruct->uQueueRead);
   if(pStrmStruct->uQueueRead == pStrmStruct->uQueueWrite)
   {
      return KAL_TRUE;
   }
   return KAL_FALSE;
}

static kal_bool AudBufQ_IsFull(AudStrmStruct *pStrmStruct)
{
   ASSERT(pStrmStruct->uQueueWrite >= pStrmStruct->uQueueRead);
   ASSERT(pStrmStruct->uQueueRead >= pStrmStruct->uQueueReturn);

   if(pStrmStruct->uQueueWrite - pStrmStruct->uQueueRead == AUDSTRM_BUFQSIZE)
   {
      return KAL_TRUE;
   }
   else if(pStrmStruct->uQueueWrite - pStrmStruct->uQueueReturn == AUDSTRM_BUFQSIZE)
   {
      return KAL_TRUE;
   }
   return KAL_FALSE;
}

static Media_Status AudBufQ_Enqueue(MHdl *hdl, AudStrmStruct *pStrmStruct, void *pBufferHeader)
{
   kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MPL_ENQUEUE, pStrmStruct->uQueueWrite, pStrmStruct->uQueueRead,pStrmStruct->uQueueReturn, pBufferHeader,0,0,0);
   if(AudBufQ_IsFull(pStrmStruct))
   {
      return MEDIA_FAIL;
   }
   pStrmStruct->pBufferQ[pStrmStruct->uQueueWrite & AUDSTRM_BUFMASK] = pBufferHeader;
   pStrmStruct->uQueueWrite++;
   return MEDIA_SUCCESS;
}

static void AudBufQ_ReturnBuffer(MHdl *hdl, AudStrmStruct *pStrmStruct)
{
   kal_bool fResult = KAL_FALSE;
   while(pStrmStruct->uQueueReturn < pStrmStruct->uQueueRead)
   {
      void *pBufferHeader = pStrmStruct->pBufferQ[pStrmStruct->uQueueReturn & AUDSTRM_BUFMASK];
      fResult = pStrmStruct->EmptyBufferDone(hdl, pBufferHeader);
      kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MPL_EMPTY_BUFFER_DONE, pStrmStruct->uQueueWrite, pStrmStruct->uQueueRead, pStrmStruct->uQueueReturn, pBufferHeader, fResult,0);
      if(fResult)
      {
         pStrmStruct->uQueueReturn++;
      }
      else
      {
         break;
      }
   }
}

void AudBufQ_BufferEOF(MHdl *hdl, AudStrmStruct *pStrmStruct)
{
   pStrmStruct->fEOF = KAL_TRUE;
   hdl->DataFinished(hdl);
   pStrmStruct->uQueueRead++;
   if(pStrmStruct->fIsReady2Play == KAL_FALSE)
   {
      pStrmStruct->fIsReady2Play = KAL_TRUE;
      mhdlException(hdl, MEDIA_READY_TO_PLAY);
   }
   return;
}

void AudBufQ_GetReadBuffer(MHdl *hdl, AudStrmStruct *pStrmStruct, kal_uint8 **pBuf, kal_uint32 *uLen)
{
   VIDEO_BUFFERHEADER_TYPE_T *pCurBuffer = NULL;
   *pBuf = NULL;
   *uLen = 0;

   if(AudBufQ_IsEmpty(pStrmStruct) && pStrmStruct->uSilenceTimeToBeFilled==0)
   {
      //buffer underflow
      return;
   }

   if(!AudBufQ_IsEmpty(pStrmStruct)) 
   {
      pCurBuffer = pStrmStruct->pBufferQ[pStrmStruct->uQueueRead & AUDSTRM_BUFMASK];
      //EOF
      if(pCurBuffer->eFlags == VIDEO_BUFFERFLAG_EOF)
      {
         AudBufQ_BufferEOF(hdl, pStrmStruct);
         return;
      }
   }

   if(pCurBuffer && !pStrmStruct->fFillingFrame && !pStrmStruct->fFillingHeader)
   {
      //start a new buffer
      if(!pStrmStruct->fNotFirstBuffer)
      {
         pStrmStruct->fNotFirstBuffer = KAL_TRUE;
      }
      else
      {
         kal_uint32 uTimeStampDiff = pCurBuffer->u8TimeStamp - pStrmStruct->uPrevTimeStamp;
         kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MPL_TIME_STAMP_INFO, pCurBuffer->u8TimeStamp,pStrmStruct->uPrevTimeStamp,pStrmStruct->uSilenceTimeToBeFilled,pStrmStruct->uSilenceTimePerFrame,pStrmStruct->fPreBufValid,pStrmStruct->uQueueRead);
         if(pStrmStruct->fOnlyOneFrameInBuffer)
         {
            if(uTimeStampDiff > pStrmStruct->uSilenceTimeUpperThreshold)
            {
               //Add Silence for silence buffer or timestamp diff
               pStrmStruct->uSilenceTimeToBeFilled += uTimeStampDiff;
               if(pStrmStruct->fPreBufValid)
               {
                  //previous frame is a real frame
                  pStrmStruct->uSilenceTimeToBeFilled -= pStrmStruct->uSilenceTimePerFrame;
               }
            }
         }
         else if(!pStrmStruct->fPreBufValid)
         {
            //Add Silence for silence buffer
            pStrmStruct->uSilenceTimeToBeFilled += uTimeStampDiff;
         }
      }
      pStrmStruct->uPrevTimeStamp = pCurBuffer->u8TimeStamp;
      
      if(pCurBuffer->u4BuffSize==0)
      {
         //silence frame
         pStrmStruct->fPreBufValid = KAL_FALSE;
         pStrmStruct->uQueueRead++;
         pCurBuffer = NULL;
      }
      else
      {
         //non-silence
         pStrmStruct->fPreBufValid = KAL_TRUE;
      }
   }

   //fill silence
   if(!pStrmStruct->fFillingFrame && !pStrmStruct->fFillingHeader && pStrmStruct->uSilenceTimePerFrame)
   {
      if(pStrmStruct->uSilenceTimeToBeFilled >= pStrmStruct->uSilenceTimePerFrame)
      {
         //fill silence
         //header is included
         *pBuf = pStrmStruct->pSilenceFrame + pStrmStruct->uRead;
         *uLen = pStrmStruct->uSilenceLength - pStrmStruct->uRead;
         pStrmStruct->fFillingSilence = KAL_TRUE;
         kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MPL_FILL_SILENCE,*uLen,pStrmStruct->uRead,pStrmStruct->uSilenceTimeToBeFilled, pStrmStruct->uSilenceTimePerFrame, 0,0);
      }
   }

   //fill header
   if(!pStrmStruct->fFillingFrame && !pStrmStruct->fFillingSilence && pCurBuffer && pStrmStruct->uHeaderLength)
   {
      if(pStrmStruct->uRead==0 &&& pStrmStruct->UpdateHeader)
      {
         pStrmStruct->UpdateHeader(pStrmStruct->pFrameHeader, pCurBuffer->u4BuffSize);
      }
      *pBuf = pStrmStruct->pFrameHeader+pStrmStruct->uRead;
      *uLen = pStrmStruct->uHeaderLength - pStrmStruct->uRead;
      pStrmStruct->fFillingHeader = KAL_TRUE;
      kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MPL_FILL_HEADER,*uLen,pStrmStruct->uRead,0,0,0,0);
   }

   //fill frame
   if(!pStrmStruct->fFillingSilence && !pStrmStruct->fFillingHeader && pCurBuffer)
   {
      //fill real frame
      ASSERT(pCurBuffer->u4BuffSize > pStrmStruct->uRead);
      *pBuf = pCurBuffer->pu1Buffer + pStrmStruct->uRead;
      *uLen = pCurBuffer->u4BuffSize - pStrmStruct->uRead;
      pStrmStruct->fFillingFrame = KAL_TRUE;
      kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MPL_FILL_FRAME,*uLen,pStrmStruct->uRead,pStrmStruct->uQueueWrite, pStrmStruct->uQueueRead, pStrmStruct->uQueueReturn,0);
   }
}

void AudBufQ_ReadDataDone(MHdl *hdl, AudStrmStruct *pStrmStruct, kal_uint32 uLen)
{
   VIDEO_BUFFERHEADER_TYPE_T *pCurBuffer = pStrmStruct->pBufferQ[pStrmStruct->uQueueRead & AUDSTRM_BUFMASK];
   if(uLen==0)
   {
      return;
   }
   pStrmStruct->uBistreamLen += uLen;

   if(pStrmStruct->fFillingHeader)
   {
      //fill header
      pStrmStruct->uRead += uLen;
      ASSERT(pStrmStruct->uHeaderLength >= pStrmStruct->uRead);
      if(pStrmStruct->uHeaderLength == pStrmStruct->uRead )
      {
         pStrmStruct->uRead = 0;
         pStrmStruct->fFillingFrame = KAL_TRUE; // after header, needs frame
         pStrmStruct->uFrameNum++;
         pStrmStruct->fFillingHeader = KAL_FALSE;
      }
   }
   else if(pStrmStruct->fFillingSilence)
   {
      //fill silence
      pStrmStruct->uRead += uLen;
      ASSERT(pStrmStruct->uSilenceLength >= pStrmStruct->uRead);
      if(pStrmStruct->uSilenceLength == pStrmStruct->uRead )
      {
         //one silence frame is filled. 
         pStrmStruct->uRead = 0;
         pStrmStruct->uSilenceTimeToBeFilled-=pStrmStruct->uSilenceTimePerFrame;
         pStrmStruct->fFillingSilence = KAL_FALSE;
      }
   }
   else if(pStrmStruct->fFillingFrame)
   {
      //fill real frame
      pStrmStruct->uRead += uLen;
      ASSERT(pCurBuffer->u4BuffSize >= pStrmStruct->uRead);
      if(pStrmStruct->uRead == pCurBuffer->u4BuffSize)
      {
         //one frame is filled. 
         pStrmStruct->uQueueRead++;
         pStrmStruct->uRead = 0;
         pStrmStruct->fFillingFrame = KAL_FALSE;
      }
   }
   else
   {
      ASSERT(0);
   }
   kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MPL_READ_DATA_DONE, pStrmStruct->uFrameNum, pStrmStruct->uBistreamLen,uLen,pStrmStruct->uSilenceTimeToBeFilled,pStrmStruct->uRead,0);
}

kal_uint32 AudBufQ_AutoFillBuffer(MHdl *hdl, AudStrmStruct *pStrmStruct, kal_uint8 *pDst, kal_uint32 uDstLen, kal_bool fPCMByte2Word)
{
   kal_uint32 uEmptyLen=0, uDataLen=0;
   kal_uint8 *pSrc;
   uEmptyLen = uDstLen;
   while(1)
   {
      if(uEmptyLen == 0)
      {
         break;
      }
      AudBufQ_GetReadBuffer(hdl, pStrmStruct, &pSrc, &uDataLen);
      if(uDataLen==0 || pSrc==NULL)
      {
         break;
      }
      if(uDataLen > uEmptyLen)
      {
         uDataLen = uEmptyLen;
      }
      memcpy(pDst, pSrc, uDataLen);   
      pDst+=uDataLen;
      uEmptyLen -= uDataLen;
      AudBufQ_ReadDataDone(hdl, pStrmStruct, uDataLen);
   }
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MPL_AUDIO_FILL_BUFFER,uDstLen,uEmptyLen,pStrmStruct->uQueueWrite, pStrmStruct->uQueueRead, pStrmStruct->uQueueReturn,0);
   return uDstLen - uEmptyLen;
}

void AudBufQ_MoveDataToRingBuffer( void *data )
{
   //This function should be called in Audio Task to prevent race condition
   MHdl *hdl = (MHdl *)data;
   AudStrmStruct *pStrmStruct = hdl->pStrmStruct;
   ASSERT(pStrmStruct);
   AudBufQ_ReturnBuffer(hdl, pStrmStruct);
   if(pStrmStruct->fEOF)
   {
      hdl->DataFinished(hdl);
   }
   if(hdl->mediaType == MEDIA_FORMAT_VORBIS)
   {
      if(!pStrmStruct->fIsReady2Play)
	   {
	      VIDEO_BUFFERHEADER_TYPE_T CurBuffer;
         CurBuffer.pu1Buffer = 0;
         CurBuffer.u4BuffSize = 0;
         CurBuffer.u8TimeStamp= 123456789;
         CurBuffer.eFlags = VIDEO_BUFFERFLAG_TRIGGER_AUDIO;
         CurBuffer.u4InputPort = 0;
         CurBuffer.u4OutputPort = 0;
         CurBuffer.pPrivateData = 0;
         pStrmStruct->EmptyBufferDone(hdl, &CurBuffer); // to trigger provider send data before start. 
         if(pStrmStruct->uQueueWrite == 15)
         {
            pStrmStruct->fIsReady2Play = KAL_TRUE;
            mhdlException(hdl, MEDIA_READY_TO_PLAY);
         }
      }
      return;
   }
   while(1)
   {
      kal_uint8 *pBuf;
      kal_uint32 uLen;
      hdl->GetWriteBuffer(hdl, &pBuf, &uLen);
      uLen = AudBufQ_AutoFillBuffer(hdl, pStrmStruct, pBuf, uLen, KAL_FALSE);
      if(uLen==0)
      {
         break;
      }
      hdl->WriteDataDone(hdl, uLen);
   }   
   AudBufQ_ReturnBuffer(hdl, pStrmStruct);
   if(pStrmStruct->fIsReady2Play == KAL_FALSE)
   {
      if(AudBufQ_IsDataReady(hdl->mediaType, pStrmStruct->uFrameNum, pStrmStruct->uBistreamLen) || hdl->eof)
      {
         pStrmStruct->fIsReady2Play = KAL_TRUE;
         mhdlException(hdl, MEDIA_READY_TO_PLAY);
      }
   }
}

void mhdlRefillAndUpdateVideoBuffer( MHdl *hdl )
{
   AudStrmStruct *pStrmStruct = hdl->pStrmStruct;
   if(pStrmStruct && pStrmStruct->fGetID)
   {
      L1Audio_SetEvent( pStrmStruct->uAud_ID, hdl );
   }
}

static Media_Status mhdlSetParameter(MHdl *hdl, Audio_Param_Type uType, void *pParam)
{
   AudStrmStruct *pStrmStruct = hdl->pStrmStruct;
   switch (uType) 
   {
      case AUDPARAM_RESET_BUFFER:
      {
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MPL_SET_PARAMETER, AUDPARAM_RESET_BUFFER,hdl, hdl->pStrmStruct, 0,0,0);
         if(hdl->pStrmStruct == NULL)
         {
            hdl->pStrmStruct = (void *)audio_alloc_mem_cacheable(sizeof(AudStrmStruct));
            pStrmStruct = hdl->pStrmStruct;
            ASSERT(hdl->pStrmStruct);
         }
         pStrmStruct->uQueueRead = 0;
         pStrmStruct->uQueueWrite = 0;
         pStrmStruct->uQueueReturn = 0;
         pStrmStruct->uRead = 0;
         pStrmStruct->uSilenceTimePerFrame = 0;
         pStrmStruct->uSilenceTimeUpperThreshold = 0;
         pStrmStruct->uFrameNum = 0;
         pStrmStruct->uBistreamLen = 0;
         pStrmStruct->fIsReady2Play = KAL_FALSE;
         pStrmStruct->fFillingSilence = KAL_FALSE;
         pStrmStruct->fFillingFrame = KAL_FALSE;
         pStrmStruct->fFillingHeader = KAL_FALSE;
         pStrmStruct->fEOF = KAL_FALSE;
         pStrmStruct->fPreBufValid = KAL_FALSE;
         pStrmStruct->uPrevTimeStamp = KAL_FALSE;
         pStrmStruct->fNotFirstBuffer = KAL_FALSE;
         pStrmStruct->fOnlyOneFrameInBuffer = KAL_FALSE;
         break;
      }
      case AUDPARAM_SET_EMPTY_BUFFER_DONE_CALLBACK:
      {
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MPL_SET_PARAMETER, AUDPARAM_SET_EMPTY_BUFFER_DONE_CALLBACK, hdl, pParam, hdl->rbInfo.rb_base,0,0);
         ASSERT(pStrmStruct);
         pStrmStruct->EmptyBufferDone = pParam;
         if(hdl->rbInfo.rb_base == NULL)
         {
            hdl->SetBufferInternal(hdl, VIDEO_TEMP_RINGBUF_SIZE);
         }
         if(pStrmStruct->fGetID == KAL_FALSE)
         {
            pStrmStruct->fGetID = KAL_TRUE;
            pStrmStruct->uAud_ID = L1Audio_GetAudioID();
            L1Audio_SetEventHandler( pStrmStruct->uAud_ID, AudBufQ_MoveDataToRingBuffer );
         }
         break;
      }  
      case AUDPARAM_SET_SILENCE_INFO:
      {
         Audio_Stream_Info *pInfo = (Audio_Stream_Info*)pParam;
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MPL_SET_PARAMETER, AUDPARAM_SET_SILENCE_INFO, hdl, pInfo->uFormat, pInfo->uChannelNum, pInfo->uSampleRate, pInfo->uFrameDur);
         Media_GetSilenceLength(pInfo->uFormat , pInfo->uChannelNum, pInfo->uSampleRate, pInfo->uSubFrameNum, &pStrmStruct->uSilenceLength);
         if(pStrmStruct->uSilenceLength)
         {
            pStrmStruct->pSilenceFrame = (kal_uint8 *)audio_alloc_mem_cacheable(pStrmStruct->uSilenceLength);
            ASSERT(pStrmStruct->pSilenceFrame);
            if(MEDIA_SUCCESS != Media_GetSilencePattern(pInfo->uFormat , pInfo->uChannelNum, pInfo->uSampleRate, pInfo->uSubFrameNum, pStrmStruct->pSilenceFrame))
            {
               return MEDIA_UNSUPPORTED_TYPE;
            }
            if(pInfo->uFrameDur) //us
            {
               pStrmStruct->uSilenceTimePerFrame = pInfo->uFrameDur;
            }
            else
            {
               pStrmStruct->uSilenceTimePerFrame = Media_GetFrameDuration(pInfo->uFormat, pInfo->uSampleRate);
            }
         }
         pStrmStruct->uSilenceTimeUpperThreshold = pStrmStruct->uSilenceTimePerFrame + (pStrmStruct->uSilenceTimePerFrame / 10);
         break;
      }
      case AUDPARAM_SET_HEADER_INFO:
      { 
         //currently, only support AAC ADTS header
         AudStrmStruct *pStrmStruct = hdl->pStrmStruct;
         Audio_Stream_Info *pInfo = (Audio_Stream_Info*)pParam;
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MPL_SET_PARAMETER, AUDPARAM_SET_HEADER_INFO, hdl, pInfo->uFormat, pInfo->uChannelNum, pInfo->uSampleRate, pInfo->uFrameDur);
#if defined(AAC_DECODE)
         if(pInfo->uFormat == MEDIA_FORMAT_AAC || pInfo->uFormat == MEDIA_FORMAT_AAC_PLUS || 
            pInfo->uFormat == MEDIA_FORMAT_AAC_PLUS_V2 || pInfo->uFormat == MEDIA_FORMAT_MP4_AAC)
         {
            pStrmStruct->uHeaderLength = AAC_ADTS_LENGTH;
            pStrmStruct->UpdateHeader = aacUpdateADTSHeader;
            pStrmStruct->pFrameHeader = (kal_uint8 *)audio_alloc_mem_cacheable(AAC_ADTS_LENGTH);
            ASSERT(pStrmStruct->pFrameHeader);
            aacInitADTSHeader(pStrmStruct->pFrameHeader, pInfo->uSampleRate, pInfo->uChannelNum);
         }
#endif
         break;
      }
      case AUDPARAM_AUTO_FILL_SILENCE_BY_TIMESTAMP:
      { 
         AudStrmStruct *pStrmStruct = hdl->pStrmStruct;
#if defined(AAC_DECODE)
         //currently, only support AAC ADTS header
         if(pStrmStruct->UpdateHeader && pStrmStruct->pFrameHeader)
         {
            pStrmStruct->fOnlyOneFrameInBuffer = KAL_TRUE;
         }
#endif
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MPL_SET_PARAMETER, AUDPARAM_AUTO_FILL_SILENCE_BY_TIMESTAMP, hdl, pStrmStruct->fOnlyOneFrameInBuffer, pStrmStruct->pFrameHeader, pStrmStruct->UpdateHeader, 0);
         break;
      }
      default:
      {
         ASSERT(0);
      }
   }
   return MEDIA_SUCCESS;
}

static Media_Status mhdlEmptyThisBuffer(MHdl *hdl, void *pBufferHeader)
{
   Media_Status uStatus;
   AudStrmStruct *pStrmStruct = hdl->pStrmStruct;
   if(pStrmStruct == NULL)
   {
      return MEDIA_FAIL;
   }
   ASSERT(pStrmStruct->EmptyBufferDone);
   if(pBufferHeader)
   {
      VIDEO_BUFFERHEADER_TYPE_T *pCurBuffer = pBufferHeader;
      pCurBuffer = pBufferHeader;
      if(pCurBuffer->eFlags & VIDEO_BUFFERFLAG_TRIGGER_AUDIO)
      {
         uStatus = MEDIA_SUCCESS;
      }
      else
      {
         uStatus = AudBufQ_Enqueue(hdl, pStrmStruct, pBufferHeader);
         if(hdl->mediaType == MEDIA_FORMAT_VORBIS && !pStrmStruct->fIsReady2Play && pCurBuffer->eFlags == VIDEO_BUFFERFLAG_EOF)
         {
            pStrmStruct->fIsReady2Play = KAL_TRUE;
            mhdlException(hdl, MEDIA_READY_TO_PLAY);
         }
      }
      kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MPL_EMPTY_THIS_BUFFER,uStatus,pCurBuffer->u4BuffSize,(kal_uint32)pCurBuffer->u8TimeStamp,pCurBuffer->pu1Buffer,pCurBuffer->eFlags,0);
   }   
   else
   {
      uStatus = MEDIA_FAIL;
   }
   mhdlRefillAndUpdateVideoBuffer(hdl);
   return uStatus;
}

#else
static Media_Status mhdlEmptyThisBuffer(MHdl *hdl, void *pBufferHeader){ return MEDIA_FAIL; }
static Media_Status mhdlSetParameter(MHdl *hdl, Audio_Param_Type uType, void *pParam){ return MEDIA_FAIL; }
#endif
// Audio Framewrok Revise

//interface for audiohdl
void rbGetWriteBuffer( AUD_RB_INFO *rb, kal_uint8 **buffer, kal_uint32 *buf_len )// in bytes
{
   int32 count;

   if( rb->read > rb->write )
      count = rb->read - rb->write - 1;
   else if( rb->read == 0 )
      count = rb->rb_size - rb->write - 1;
   else
      count = rb->rb_size - rb->write;

   ASSERT( count>=0 );
   *buffer = (uint8 *)&rb->rb_base[rb->write];
   *buf_len = count;
}

void rbGetReadBuffer( AUD_RB_INFO *rb, kal_uint8 **buffer, kal_uint32 *buf_len )// in bytes
{
   int32 count;

   if( rb->write >= rb->read )
      count = rb->write - rb->read;
   else
      count = rb->rb_size - rb->read;

   ASSERT( count>=0 );
   *buffer = (uint8 *)&rb->rb_base[rb->read];
   *buf_len = count;
}

void rbReadDataDone( AUD_RB_INFO *rb, kal_uint32 len ) // in bytes
{
   rb->read += len;

   ASSERT(rb->read <= rb->rb_size);
   if( rb->read == rb->rb_size )
      rb->read = 0;

   kal_brief_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_READ_BYTE, len );
}


void rbWriteDataDone( AUD_RB_INFO *rb, kal_uint32 len ) // in bytes
{
   rb->write += len;

   ASSERT(rb->write <= rb->rb_size);
   if( rb->write == rb->rb_size )
      rb->write = 0;
}

int32 rbGetFreeSpace( AUD_RB_INFO *rb )
{
   int32 count;

   count = rb->read - rb->write - 1;
   if( count < 0 )
      count += rb->rb_size;
   return count; // free size in byte
}

int32 rbGetDataCount( AUD_RB_INFO *rb )
{
   return rb->rb_size - rbGetFreeSpace(rb) - 1;
}
//interface for audiohdl end

static void mhdlSetBuffer( MHdl *hdl, kal_uint8 *buffer, kal_uint32 buf_len )
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_SET_BUFFER, buffer, buf_len, hdl->isAllocRingBuffer,hdl,0,0);
   if(hdl->isAllocRingBuffer == KAL_TRUE)
   {
      hdl->FreeBufferInternal(hdl);  
   }
   hdl->rbInfo.rb_base = buffer;
   hdl->rbInfo.rb_size = buf_len;
   hdl->rbInfo.write = 0;
   hdl->rbInfo.read = 0;
   hdl->eof = false;
   hdl->waiting = false;
}

static void mhdlGetWriteBuffer( MHdl *hdl, kal_uint8 **buffer, kal_uint32 *buf_len )// in bytes
{
   rbGetWriteBuffer(&hdl->rbInfo, buffer, buf_len);
}

static void mhdlGetReadBuffer( MHdl *hdl, kal_uint8 **buffer, kal_uint32 *buf_len )// in bytes
{
   rbGetReadBuffer(&hdl->rbInfo, buffer, buf_len);
}

static Media_Status mhdlSetLevel( MHdl *hdl, kal_uint8 level )
{
   ASSERT( level <= 100 );
   hdl->volume_level = level;
   AFE_SetDigitalGain( L1SP_AUDIO, level );
   AFE_SetDigitalGain( L1SP_VOICE, level );
   return MEDIA_SUCCESS;
}

static void mhdlWriteDataDone( MHdl *hdl, kal_uint32 len ) // in bytes
{
   kal_brief_trace (TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_WRITE_DATA_DONE, hdl, len,0,0,0,0);
   rbWriteDataDone(&hdl->rbInfo, len);
}

static void mhdlReadDataDone( MHdl *hdl, kal_uint32 len ) // in bytes
{
   rbReadDataDone(&hdl->rbInfo, len);
#if defined(__AUDIO_TRIM_SUPPORT__)   
   if(hdl->isTrim)
      hdl->Trim(hdl);
#endif   	
}

static void mhdlDataFinished( MHdl *hdl )
{
   kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_DATA_FINISH, hdl, hdl->mediaType,0,0,0,0);
   hdl->eof = true;
   
#if defined(__AUDIO_COMPONENT_SUPPORT__)    
    {
        extern void APM_SendProcess(void);
        APM_SendProcess();
    }
#endif   
}

static void mhdlFinishWriteData( MHdl *hdl )
{
#if !defined(__SMART_PHONE_MODEM__) && !defined(__L1_STANDALONE__) && !defined(MED_MODEM)
   {
      MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
      AudComHdl *pParHdl = ihdl->NodeArray[0].curHdl;
      
      if (hdl->state == COMPONENT_STATE_PLAY)
         ACU_SendProcessCommandl((AudComHdlInt *)pParHdl);
   }
#endif

   hdl->waiting = KAL_FALSE;
   hdl->isUnderflow = KAL_FALSE;  
   hdl->bReadingData = KAL_FALSE;   
}

static void mhdlResetMediaBuf( MHdl *hdl )
{
   hdl->rbInfo.write = 0;
   hdl->rbInfo.read = 0;
   hdl->eof = KAL_FALSE;
   hdl->waiting = KAL_FALSE;
   hdl->isUnderflow = KAL_FALSE;   

}
static kal_uint8 mhdlGetLevel( MHdl *hdl )
{
   return hdl->volume_level;
}

static Media_Status mhdlSetStartTime( MHdl *hdl, kal_uint32 msStartTime )
{
   hdl->start_time = msStartTime;
   hdl->current_time = msStartTime;
   hdl->uSeekProgress = 0;
   hdl->uCurSeekFrm = 0;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_SET_START_TIME, hdl->mediaType, msStartTime,0,0,0,0);
   return MEDIA_SUCCESS;
}

static Media_Status mhdlSetStopTime( MHdl *hdl, kal_uint32 msStopTime )
{
   hdl->stop_time = msStopTime;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_SET_STOP_TIME, hdl->mediaType, msStopTime,0,0,0,0);
   return MEDIA_SUCCESS;
}

static void mhdlSetStoreFlag( MHdl *hdl, kal_bool fStoreLastFileOffset )
{
   hdl->fStoreFileOffset = fStoreLastFileOffset;
}

static void mhdlStoreFileOffset(MHdl *hdl)
{
   audResumeInfo.uResumeFrameOffset = audResumeInfo.uCurOffset;
}

static kal_uint32 mhdlGetFileOffset(MHdl *hdl)
{
   return 0;
}

static void mhdlSetFileOffset( MHdl *hdl, kal_uint32 uCurOffset)
{
   audResumeInfo.uResumeFrameOffset = uCurOffset;
}

static kal_uint32 mhdlGetCurrentTime( MHdl *hdl )
{
   kal_uint32 uTSTime = 0;
   hdl->fStoreFileOffset = false;

#if defined(__BES_TS_SUPPORT__) && defined(__AUDIO_COMPONENT_SUPPORT__) 
   if(!Media_IsDSPDec())  
      uTSTime = AudioDrain_GetCurrentTimeFromTS();
#endif 
   
   kal_brief_trace ( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_CURRENT_TIME, hdl->mediaType, hdl->current_time, hdl->start_time, uTSTime,0,0,0);

   if(uTSTime)
   {
      hdl->current_time = hdl->start_time+uTSTime;
   }

   if (hdl->current_time < hdl->start_time)
      return hdl->start_time;
   else
      return hdl->current_time;
}

static kal_uint32 mhdlGetTotalDuration( MHdl *hdl )
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_TOTAL_DUR_NONAST, hdl, hdl->mediaType, hdl->uTotalDuration,0,0,0);
   return hdl->uTotalDuration;
}

static int32 mhdlGetFreeSpace( MHdl *hdl )
{
   return rbGetFreeSpace(&hdl->rbInfo);
}

static int32 mhdlGetDataCount( MHdl *hdl )
{
   return hdl->rbInfo.rb_size - mhdlGetFreeSpace(hdl) - 1;
}

void mhdlCallbackTask( void *data )
{
   MHdl *hdl = (MHdl *)data;
   Media_Event uEvent = (Media_Event)hdl->data;
   hdl->handler( hdl, uEvent );
}

//----------------------------------------------------------------------------
// AUDLP_Check_LowPower_Status() would be referenced by other modules always,
// so should be kept here even __AUDIO_DSP_LOWPOWER_V2__ is not defined
//----------------------------------------------------------------------------
#if !defined(__AUDIO_DSP_LOWPOWER_V2__)
kal_bool AUDLP_Check_LowPower_Status(void)
{
   return KAL_FALSE;
}
#endif

#if defined(__CACHED_BASE_DSP__)
   extern int cachesys_dydl_apply(unsigned int mem_type, unsigned int dydl_entry);
   extern int cachesys_addr_conv(unsigned int mem_type, unsigned int page, unsigned int addr, void *emi_addr);

#if defined(AUDLP_DEBUG_ENABLE)
#define PCM_DEBUG_ARRAY_SIZE 3096
static kal_uint32 audio_debug_index_v1 = 0xA5A5;
static kal_uint32 audio_debug_index_v2 = 0x5A5A;
static kal_uint32 PCM_debug_total_count = 0;
       kal_uint32 audio_debug_flag1  = 0;
       kal_uint32 audio_debug_flag2 = 0;
       kal_uint32 audio_debug_address = 0;
static kal_uint16 PCM_debug_array[PCM_DEBUG_ARRAY_SIZE];
static kal_uint16 PCM_debug_array_index = 0;
static kal_uint16 audio_debug_checksum = 0;
static kal_uint16 audio_debug_checksum_count = 0;
static kal_uint16 audio_debug_end = 0;
#endif

/*=========================================== 
   Fucntion :
   Note     :  In Cached-DSP, we can write data to DSP DM mapping external memory
               by MCU EMI, this way won't go through IDMA and won't affect DSP cache.
               But DSP need to invalid cache when it wants to read data in this area.
  =========================================== */
void Cache_MCUCopyToDSP_External_DM(const kal_uint16 *SourceAddr,
                               kal_uint32 wDataLen,
                               kal_uint16 PageNum,
                               kal_uint16 DestDSPaddr,
                               kal_uint8 duplicated)
{
   int hr;
   kal_uint32 EMI_Addr;
   if( cachesys_addr_conv(2, PageNum, DestDSPaddr, &EMI_Addr) < 0)
      ASSERT( false );
      
   if( emisec_disable() < 0)
      ASSERT( false );

   {
      kal_uint16 *pEMI_Addr = (kal_uint16 *)EMI_Addr;
      kal_int32 i;

#if defined(AUDLP_DEBUG_ENABLE)
      if((audio_debug_flag2) && (EMI_Addr == audio_debug_address))
      {
      	 kal_uint32 wDataLen_cut;
         if (wDataLen > 32)
            wDataLen_cut = 32;
         else
            wDataLen_cut = wDataLen;
         
         wDataLen  -= wDataLen_cut;
         pEMI_Addr += wDataLen_cut;
      }
#endif
      if (duplicated)
      {
         for(i=wDataLen; i>0;i-=2)
         {
            *pEMI_Addr++ = *SourceAddr;
            *pEMI_Addr++ = *SourceAddr++;
         }
      }else{
         for(i=wDataLen; i>0;i-=1)
         {
            kal_uint16 t1;
         	  t1 = *SourceAddr++;
#if defined(AUDLP_DEBUG_ENABLE)
         	  if(audio_debug_flag1)
         	  {
            	  if(PCM_debug_total_count & 1)
            	     t1 = audio_debug_index_v1;
            	  else
            	     t1 = audio_debug_index_v2;
            }
#endif
            *pEMI_Addr++ = t1;
            
#if defined(AUDLP_DEBUG_ENABLE)
            audio_debug_checksum ^= t1;
            audio_debug_checksum_count++;
            PCM_debug_total_count++;
            if (audio_debug_checksum_count == 576)
            {
               if (PCM_debug_array_index < PCM_DEBUG_ARRAY_SIZE)
               {
                  PCM_debug_array[PCM_debug_array_index] = audio_debug_checksum;
                  PCM_debug_array_index ++;
               }
               else
               {
                  audio_debug_end = 1;
               }
               audio_debug_checksum_count = 0;
               audio_debug_checksum = 0;
            }
#endif
         }
      }
   }
   if( emisec_enable() < 0)
      ASSERT( false );
}
#endif //__CACHED_BASE_DSP__


#if APM_SUPPORT
static void mhdlEndHandler( void *data, Media_Event event )
{
    MHdl *hdl;
    
    hdl = (MHdl *) data;
    hdl->data = (uint32)event;
    L1Audio_SetEvent( hdl->aud_id, hdl );
}
#endif

void mhdlException( MHdl *hdl, Media_Event event )
{
   kal_brief_trace (TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MHDL_EXCEPTION, hdl->mediaType, hdl,event,0,0,0);
   ASSERT(hdl);
#if defined(__AUDIO_COMPONENT_SUPPORT__) && !defined(MED_MODEM)
   hdl->data = (uint32)event;
   ACU_SendMediaEvent(hdl);
#else
#if APM_SUPPORT
   if ((event==MEDIA_END || event == MEDIA_STOP_TIME_UP)&&(!hdl->isTrim)) 
   {
      APM_NOTIFY_MEDIA_END(mhdlEndHandler, (void *)hdl, true, event);
   }
   else
#endif
   {
      hdl->data = (uint32)event;
      L1Audio_SetEvent( hdl->aud_id, hdl );
   }
#endif
}

void mhdlAllowSleep( MHdl *hdl )
{
   if(L1Audio_CheckFlag( hdl->aud_id ))                 //Dior add
      L1Audio_ClearFlag( hdl->aud_id );
   ktUnlock();
}

void mhdlDisallowSleep( MHdl *hdl )
{
   if(!L1Audio_CheckFlag( hdl->aud_id ))                 //Dior add
      L1Audio_SetFlag( hdl->aud_id ); // disable sleep mode
   ktLock();
}

#if defined(__AUDIO_COMPONENT_SUPPORT__)
void mhdlAllowSleep_Id( kal_uint32 aud_id )
{
   if (L1Audio_CheckFlag( aud_id ))
      L1Audio_ClearFlag( aud_id );
   ktUnlock();
}

void mhdlDisallowSleep_Id( kal_uint32 aud_id )
{
   if (!L1Audio_CheckFlag( aud_id ))
      L1Audio_SetFlag( aud_id ); // disable sleep mode
   ktLock();
}

void mhdlSetFlag_MD2G_Id(kal_uint32 aud_id)
{
    extern void L1Audio_SetFlag_MD2G(uint16 audio_id);
    L1Audio_SetFlag_MD2G(aud_id);
    ktLock();
}

void mhdlClearFlag_MD2G_Id(kal_uint32 aud_id)
{
    extern void L1Audio_ClearFlag_MD2G(uint16 audio_id);
    L1Audio_ClearFlag_MD2G(aud_id);
    ktUnlock();
}

#endif

static void mhdlDataRequestInternal( MHdl *hdl, Media_Event end_status, Media_Event event)
{
   kal_uint32 data_count;
   kal_uint32 free_space;

   kal_brief_trace ( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_DATA_REQUEST, hdl->waiting, hdl->eof, hdl->DataRequestThreshold, hdl->GetFreeSpace(hdl),0,0,0,0);

#if defined(__AUDIO_STREAMING_NON_RINGBUFFER_SUPPORT__)
   mhdlRefillAndUpdateVideoBuffer( hdl );
#endif
   if (hdl->waiting)
   {
      return;
   }
   
   if (end_status != MEDIA_UPDATE_DUR)
   {
      if ( hdl->eof || (end_status == MEDIA_END) )
         return;
   }

   data_count = hdl->GetDataCount(hdl);
   free_space = hdl->GetFreeSpace(hdl);

   if(  (hdl->DataRequestMode==MEDIA_FREE_SPACE_MODE && (free_space > hdl->DataRequestThreshold))
      ||(data_count<MEDIA_MIN_DATA_THRESHOLD))
   {
      mhdlException( hdl, event );
      hdl->waiting = true;
   }
   else if(hdl->DataRequestMode==MEDIA_DATA_COMSUME_MODE)
   {
      if(hdl->rbInfo.read > hdl->LastRingBufferRead)
      {
         if(hdl->rbInfo.read - hdl->LastRingBufferRead > hdl->DataRequestThreshold)
         {
            mhdlException( hdl, event );
            hdl->waiting = true;
            hdl->LastRingBufferRead = hdl->rbInfo.read; 
         }
      }
      else 
      {
         if(hdl->rbInfo.read + hdl->rbInfo.rb_size - hdl->LastRingBufferRead > hdl->DataRequestThreshold)
         {
            mhdlException( hdl, event );
            hdl->waiting = true;
            hdl->LastRingBufferRead = hdl->rbInfo.read; 
         }
      }
   }
}

void mhdlDataRequest( MHdl *hdl, Media_Event end_status)
{
   mhdlDataRequestInternal(hdl, end_status, MEDIA_DATA_REQUEST);
}

void mhdlDataRequestNone( MHdl *hdl, Media_Event end_status)
{
   mhdlDataRequestInternal(hdl, end_status, MEDIA_NONE);
}

void mhdlDataNotification( MHdl *hdl )
{
   if( hdl->waiting )
      return;
#if defined(__AUDIO_TRIM_SUPPORT__)
   if( hdl->isTrim)
      mhdlException( hdl, MEDIA_DATA_NOTIFICATION );
   else
#endif    
   if( hdl->GetDataCount(hdl) >= (MEDIA_RB_DEFAULT_THRESHOLD << 2) ) {
      mhdlException( hdl, MEDIA_DATA_NOTIFICATION );
      hdl->waiting = true;
   }
}

static void mhdlSetUserData( MHdl *hdl, void* pAppData)
{
   hdl->pApplicateData = pAppData;
}

static void mhdlGetUserData( MHdl *hdl, void** pAppData)
{
   *pAppData = hdl->pApplicateData;
}

static Media_Status mhdlReachValidRegion( MHdl *hdl )
{
   return MEDIA_SUCCESS;
}

static void mhdlBuildCache( MHdl *hdl, Media_Status *eLastRet, kal_uint32 *uProgress, kal_bool fLimitFrameNumber)
{
	*eLastRet = MEDIA_SUCCESS;
	*uProgress=100;
}

static void mhdlSetCacheTbl( MHdl *hdl, kal_uint8 *ptr, kal_uint32 usize )
{
}

static kal_uint32 mhdlGetCacheDur(MHdl *hdl)
{
   return hdl->uTotalDuration;
}

static void mhdlSetDataRequestThreshold(MHdl *hdl, Media_Buffer_Mode mode, kal_uint32 threshold, void* param)
{
   hdl->DataRequestThreshold = threshold;
   hdl->DataRequestMode = mode;
}

static Media_Status mhdlTrim( MHdl *hdl )
{
   return MEDIA_FAIL;
}

static void mhdlSetBufferInternal(MHdl *hdl , kal_uint32 uSize)
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_SET_BUFFER_INTERNAL, hdl, hdl->rbInfo.rb_base, hdl->isAllocRingBuffer,uSize,0,0);
   if(hdl->rbInfo.rb_base == NULL)
   {
      hdl->rbInfo.rb_base = (kal_uint8 *)audio_alloc_mem_cacheable( uSize * sizeof(kal_uint8) );
      ASSERT(hdl->rbInfo.rb_base);
      hdl->rbInfo.rb_size = uSize;
      hdl->isAllocRingBuffer = KAL_TRUE;
      mhdlResetMediaBuf(hdl);
   }
}

static void mhdlFreeBufferInternal(MHdl *hdl)
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_FREE_BUFFER_INTERNAL, hdl, hdl->rbInfo.rb_base, hdl->isAllocRingBuffer,0,0,0);
   if(hdl->isAllocRingBuffer)
   {
      ASSERT(hdl->rbInfo.rb_base);
      audio_free_mem( (void **) &hdl->rbInfo.rb_base ); 
      hdl->rbInfo.rb_base = NULL;
      hdl->rbInfo.rb_size = 0;
      hdl->isAllocRingBuffer = KAL_FALSE;
   }
}

void mhdlInitEx( MHdl *hdl, uint32 hisrMagic, void hisrHdlr( void *data ) )
{
   ASSERT(hdl);

   memset(hdl, 0, sizeof(MHdl));
   hdl->stop_time = 0xFFFFFFFF;

   hdl->SetBufferInternal = mhdlSetBufferInternal;
   hdl->FreeBufferInternal = mhdlFreeBufferInternal;
   hdl->SetBuffer = mhdlSetBuffer;
   hdl->GetWriteBuffer = mhdlGetWriteBuffer;
   hdl->GetReadBuffer = mhdlGetReadBuffer;
   hdl->WriteDataDone = mhdlWriteDataDone;
   hdl->FinishWriteData = mhdlFinishWriteData;
   hdl->ResetMediaBuf = mhdlResetMediaBuf;
   hdl->ReadDataDone = mhdlReadDataDone;
   hdl->DataFinished = mhdlDataFinished;
   hdl->GetFreeSpace = mhdlGetFreeSpace;
   hdl->GetDataCount = mhdlGetDataCount;
   hdl->SetLevel = mhdlSetLevel;
   hdl->GetLevel = mhdlGetLevel;
   hdl->SetStartTime = mhdlSetStartTime;
   hdl->SetStopTime = mhdlSetStopTime;
   hdl->GetCurrentTime = mhdlGetCurrentTime;
   hdl->GetTotalDuration = mhdlGetTotalDuration;
   hdl->SetStoreFlag = mhdlSetStoreFlag;
   hdl->StoreFileOffset = mhdlStoreFileOffset;
   hdl->GetFileOffset = mhdlGetFileOffset;
   hdl->SetFileOffset = mhdlSetFileOffset;
   hdl->ReachValidRegion = mhdlReachValidRegion;
   hdl->SetUserData = mhdlSetUserData;
   hdl->GetUserData = mhdlGetUserData;
   hdl->BuildCache  = mhdlBuildCache;
   hdl->SetCacheTbl = mhdlSetCacheTbl;
   hdl->GetCacheDuration = mhdlGetCacheDur;
   hdl->SetDataRequestThreshold = mhdlSetDataRequestThreshold;
   hdl->DataRequestThreshold = MEDIA_RB_DEFAULT_THRESHOLD << 2;
   hdl->DataRequestMode = MEDIA_FREE_SPACE_MODE;
   hdl->Trim = mhdlTrim;
   hdl->EmptyThisBuffer = mhdlEmptyThisBuffer;
   hdl->SetParameter = mhdlSetParameter;
}

void mhdlInit( MHdl *hdl, uint32 hisrMagic, void hisrHdlr( void *data ) )
{
   mhdlInitEx( hdl, hisrMagic, hisrHdlr );

   if(0xFFFF != hisrMagic){
      mhdlSetLevel( hdl, 100 );
      hdl->aud_id = L1Audio_GetAudioID();
      L1Audio_SetEventHandler( hdl->aud_id, mhdlCallbackTask );
   }
}

//for pcm strm case in component-based only
#if defined(__AUDIO_COMPONENT_SUPPORT__)
void mhdlFinalize_PCM (MHdl *hdl, uint32 hisrMagic){
   if(0xFFFF != hisrMagic)
   {
      mhdlSetLevel( hdl, 100 );
      L1Audio_FreeAudioID( hdl->aud_id );
   }	
}
#endif  

void mhdlFinalize( MHdl *hdl, uint32 hisrMagic )
{
#if !defined(__AUDIO_COMPONENT_SUPPORT__)
   if(0xFFFF != hisrMagic)
   {
      mhdlSetLevel( hdl, 100 );
      L1Audio_FreeAudioID( hdl->aud_id );
   }
#endif   
#if defined(__AUDIO_STREAMING_NON_RINGBUFFER_SUPPORT__)
   hdl->FreeBufferInternal(hdl);
   if(hdl->pStrmStruct)
   {
      AudStrmStruct *pStrmStruct = (AudStrmStruct *)hdl->pStrmStruct;
      if(pStrmStruct->fGetID)
      {
         L1Audio_FreeAudioID( pStrmStruct->uAud_ID );
         pStrmStruct->fGetID = KAL_FALSE;
      }
      if(pStrmStruct->pSilenceFrame)
      {
         audio_free_mem( (void **) &pStrmStruct->pSilenceFrame);
         pStrmStruct->pSilenceFrame = NULL;
      }
      if(pStrmStruct->pFrameHeader)
      {
         audio_free_mem( (void **) &pStrmStruct->pFrameHeader);
         pStrmStruct->pFrameHeader = NULL;
      }
      audio_free_mem( (void **) &hdl->pStrmStruct);
      hdl->pStrmStruct = NULL;  
   }
#endif

}

void mhdlHookInit( MHdl *hdl, uint32 hisrMagic, void hisrHdlr( void *data ) )
{
#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   VIBR_Vibration_Deactivate();
#endif
   PcmSink_TerminateSound();
   if(0xFFFF != hisrMagic)
   {
      L1Audio_HookHisrHandler( hisrMagic, hisrHdlr, (void*)hdl );
   }
}

void mhdlHookFinalize( uint32 hisrMagic )
{
   if(0xFFFF != hisrMagic){
      L1Audio_UnhookHisrHandler( hisrMagic );
   }
}

void autMoveDataForAlign( MHdl *hdl ) //for aacmfplaystrm / dafmfplaystrm
{
   int32 dataCount, I;
   uint8 *dest, *src;

   if ( 0 == (hdl->rbInfo.read & 0x1) )
      return;

   dataCount = hdl->GetDataCount( hdl );
   if (hdl->rbInfo.read <= hdl->rbInfo.write) {
      dest = hdl->rbInfo.rb_base;
      src = hdl->rbInfo.rb_base + hdl->rbInfo.read;
      for (I = dataCount-1; I>=0; I--) {
         *dest++ = *src++;
      }
      
      // Update read pointer
      hdl->rbInfo.read = 0;
   } else {
      int32 segment = hdl->rbInfo.rb_size - hdl->rbInfo.read;
      
      // First segment
      dest = hdl->rbInfo.rb_base + hdl->rbInfo.read - 1;
      src = hdl->rbInfo.rb_base + hdl->rbInfo.read;
      for (I = segment-1; I>=0; I--) {
         *dest++ = *src++;
      }
      
      // The last byte of ring buffer
      *dest = hdl->rbInfo.rb_base[0];
      
      // Seconf segment
      dest = hdl->rbInfo.rb_base;
      src = hdl->rbInfo.rb_base + 1;
      for (I = hdl->rbInfo.write-2; I>=0; I--) {
         *dest++ = *src++;
      }
      
      // Update read pointer
      hdl->rbInfo.read -= 1;
   }
   
   // Update write pointer
   hdl->rbInfo.write = hdl->rbInfo.read + dataCount;
   if (hdl->rbInfo.write >= hdl->rbInfo.rb_size)
      hdl->rbInfo.write -= hdl->rbInfo.rb_size;
}

kal_uint8 autGetBitsFromBuf(kal_uint8 *pBuf, kal_uint32 *puBitCnt, kal_uint32 uBitLen)
{
	static kal_uint8 bCurByte;
	kal_uint8 bMask;
	kal_uint32 uCurBitPos;
	kal_uint8 bValue;

   ASSERT(puBitCnt!=NULL);
	ASSERT(uBitLen>=1 && uBitLen<=8);

	uCurBitPos = *puBitCnt % 8;

	if(uCurBitPos==0) {
	   bCurByte = pBuf[*puBitCnt/8];
	}

	*puBitCnt += uBitLen;

	if(uCurBitPos+uBitLen<=8) {
		bMask = (unsigned char)((1 << (8-uCurBitPos)) - 1);
		bValue = (unsigned char)((bCurByte&bMask) >> (8-(uCurBitPos+uBitLen)));
	} else {
		bMask = (unsigned char)((1 << (8-uCurBitPos)) - 1);
		bValue = (unsigned char)((bCurByte&bMask) << (uBitLen-(8-uCurBitPos)));
		bCurByte = pBuf[*puBitCnt/8];
		bValue |= bCurByte>>(16-uBitLen-uCurBitPos);
	}
	return bValue;
}

void autGetFileSize(MHdl *hdl, STFSAL *pstFSAL, kal_uint32 *fileLen)
{
   FSAL_GetFileSize(pstFSAL, fileLen);
   (void) hdl;
}

static kal_int32 autGetBytesFromFileGeneral(MHdl *hdl, STFSAL *pstFSAL, kal_uint32 fileOffset, kal_uint32 num_bytes, kal_uint8 *ptr, kal_uint32 method)
{
   kal_uint32 file_size, data_size;
   {
      autGetFileSize(hdl, pstFSAL, &file_size);
      data_size = file_size - fileOffset;
      
      if(data_size <= num_bytes){  // EOF
         num_bytes = data_size;
         if (method == 0)
            hdl->DataFinished(hdl);
      }
      
      FSAL_Seek( pstFSAL, fileOffset);
      if(FSAL_Read_Bytes( pstFSAL, ptr, num_bytes) != FSAL_OK)
         return -1; // Playback should be terminated
   }

   return num_bytes;
}

kal_int32 autGetBytesFromFile(MHdl *hdl, STFSAL *pstFSAL, kal_uint32 fileOffset, kal_uint32 num_bytes, kal_uint8 *ptr)
{
   return autGetBytesFromFileGeneral(hdl, pstFSAL, fileOffset, num_bytes, ptr, 0);
}

kal_int32 autGetBytesFromFileNoEnd(MHdl *hdl, STFSAL *pstFSAL, kal_uint32 fileOffset, kal_uint32 num_bytes, kal_uint8 *ptr)
{
   return autGetBytesFromFileGeneral(hdl, pstFSAL, fileOffset, num_bytes, ptr, 1);
}

kal_int32 autGetBytes(MHdl *hdl, STFSAL *pstFSAL, kal_uint32 uLen, kal_uint8 *pbBuf)
{
   kal_uint32 uDataSize, uFileSize, uCurPos;

   if(uLen == 0) return 0;
   FSAL_GetCurPos(pstFSAL, &uCurPos);
   autGetFileSize(hdl, pstFSAL, &uFileSize);
   uDataSize = uFileSize - uCurPos;

   if(uDataSize <= uLen){
      uLen = uDataSize;
      hdl->DataFinished(hdl);
   }
   if(uLen == 0) return 0;

   if(FSAL_Read_Bytes( pstFSAL, pbBuf, uLen) != FSAL_OK)
      return -1;

   return uLen;
}

void autSkipID3Tag( MHdl *hdl, STFSAL *pstFSAL, kal_uint32 *fileOffset, kal_uint8 *ptr )
{
   kal_uint32 num_bytes, file_size, tagsize;
   file_size = 0;

   while(1){
      tagsize = 0;
      num_bytes = autGetBytesFromFileNoEnd(hdl, pstFSAL, *fileOffset, ID3V2_HEADER_LEN, ptr);
      if(num_bytes != ID3V2_HEADER_LEN) return;
      
      if (kal_mem_cmp(ptr, "ID3", 3) == 0)
	   {
         tagsize = (ptr[6] << 21) | (ptr[7] << 14) |
               (ptr[8] <<  7) | (ptr[9] <<  0);
      
         autGetFileSize(hdl, pstFSAL, &file_size);
         if(file_size >= (tagsize + 10)){ // Don't skip ID3 tag if tagsize is invalid
            *fileOffset += (tagsize+10);            
         }else{
             return;
          }
         
      }else
         return;
   }
}

#if !defined(__AUDIO_COMPONENT_SUPPORT__)
/* return dspDataConsume in word */
static kal_int32 autWriteDataByIDMA( MHdl *hdl, volatile kal_uint16 *dspWritePtr, volatile kal_uint16 *dspReadPtr, kal_uint32 pageNum, kal_int32 mblenInWord, AUD_RB_INFO* srcRB )
{
   volatile uint16 *idmaPtr;
   kal_int32 count, DSP_FreeLenLow, DSP_R, DSP_FreeLen;
   kal_uint16 DSP_W;
   const kal_uint16 *buf;
   DSP_W = *dspWritePtr;

   buf = (uint16 *)&srcRB->rb_base[srcRB->read];

   do {
      DSP_R = (int32)*dspReadPtr;
   } while( DSP_R != (int32)*dspReadPtr );

   DSP_FreeLen = DSP_R - (int32)DSP_W - 1;
   if( DSP_FreeLen < 0 )
      DSP_FreeLen += hdl->dsp_rb_size;

   if(hdl->mono2stereo){
      mblenInWord <<= 1;
      if(DSP_FreeLen <= 1)
         return 0;
      DSP_FreeLen &= 0xFFFE;
   }

   if( DSP_FreeLen < mblenInWord )
      mblenInWord = DSP_FreeLen;

   if( mblenInWord == 0 )
      return 0;

   switch (hdl->mediaType) {
#if defined(WAV_CODEC)
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_AIFF:
      case MEDIA_FORMAT_AU:
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
      case MEDIA_FORMAT_G711_ALAW:
      case MEDIA_FORMAT_G711_ULAW:
      case MEDIA_FORMAT_DVI_ADPCM:
      case MEDIA_FORMAT_COOK:
      case MEDIA_FORMAT_APE:
      case MEDIA_FORMAT_VORBIS:
         DSP_FreeLenLow = (int32)(hdl->dsp_rb_size - DSP_W);
         break;
#endif // #if defined(WAV_CODEC)
      default:
         DSP_FreeLenLow = (int32)(hdl->dsp_rb_end - DSP_W);
   }

   if( DSP_FreeLenLow > mblenInWord )
      DSP_FreeLenLow = mblenInWord;

   switch (hdl->mediaType) {
#if defined(WAV_CODEC)
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_AIFF:
      case MEDIA_FORMAT_AU:
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
      case MEDIA_FORMAT_G711_ALAW:
      case MEDIA_FORMAT_G711_ULAW:
      case MEDIA_FORMAT_DVI_ADPCM:
      case MEDIA_FORMAT_COOK:
      case MEDIA_FORMAT_APE:
      case MEDIA_FORMAT_VORBIS:
      	 idmaPtr=DSP_DM_ADDR(pageNum, (DSP_W+hdl->dsp_rb_base) );
         kal_dev_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_WRITE_DSP_FIRST_SEGMENT, (DSP_W+hdl->dsp_rb_base), DSP_FreeLenLow);
         break;
#endif // #if defined(WAV_CODEC)
      case MEDIA_FORMAT_WMA:
      case MEDIA_FORMAT_MUSICAM:
         idmaPtr=DSP_DM_ADDR(pageNum, DSP_W);
         kal_dev_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_WRITE_DSP_FIRST_SEGMENT, DSP_W, DSP_FreeLenLow);
         break;
      case MEDIA_FORMAT_DAF:
         idmaPtr=DSP_PM_ADDR(pageNum, DSP_W);
         kal_dev_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_WRITE_DSP_FIRST_SEGMENT, DSP_W, DSP_FreeLenLow);
         break;
      default:
         idmaPtr=DSP_PM_ADDR(pageNum, DSP_W);
         kal_dev_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_WRITE_DSP_FIRST_SEGMENT, DSP_W, DSP_FreeLenLow);
   }

   if(hdl->mono2stereo)
   {
      IDMA_WriteToDSP_Duplicate(idmaPtr, (uint16*)buf, DSP_FreeLenLow);
      buf+=DSP_FreeLenLow>>1;
   }
   else
   {
      IDMA_WriteToDSP(idmaPtr, (uint16*)buf, DSP_FreeLenLow);
      buf+=DSP_FreeLenLow;
   }

   DSP_W += (uint16)DSP_FreeLenLow;

   switch (hdl->mediaType) {
#if defined(WAV_CODEC)
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_AIFF:
      case MEDIA_FORMAT_AU:
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
      case MEDIA_FORMAT_G711_ALAW:
      case MEDIA_FORMAT_G711_ULAW:
      case MEDIA_FORMAT_DVI_ADPCM:
      case MEDIA_FORMAT_COOK:
      case MEDIA_FORMAT_APE:
      case MEDIA_FORMAT_VORBIS:
         if( DSP_W >= hdl->dsp_rb_size )
            DSP_W = 0;
         break;
#endif
      default:
         if( DSP_W >= hdl->dsp_rb_end )
            DSP_W = hdl->dsp_rb_base;
   }

   *dspWritePtr = DSP_W;

   count = mblenInWord - DSP_FreeLenLow;

   if( count > 0 ) {
       switch (hdl->mediaType) {
#if defined(WAV_CODEC)
         case MEDIA_FORMAT_WAV:
         case MEDIA_FORMAT_AIFF:
         case MEDIA_FORMAT_AU:
         case MEDIA_FORMAT_PCM_8K:
         case MEDIA_FORMAT_PCM_16K:
         case MEDIA_FORMAT_G711_ALAW:
         case MEDIA_FORMAT_G711_ULAW:
         case MEDIA_FORMAT_DVI_ADPCM:
         case MEDIA_FORMAT_COOK:
         case MEDIA_FORMAT_APE:
         case MEDIA_FORMAT_VORBIS:
     			  idmaPtr=DSP_DM_ADDR(pageNum, (DSP_W+hdl->dsp_rb_base));
            kal_dev_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_WRITE_DSP_SECOND_SEGMENT, (DSP_W+hdl->dsp_rb_base), count);
            break;
#endif
         case MEDIA_FORMAT_WMA:
         case MEDIA_FORMAT_MUSICAM:
            idmaPtr=DSP_DM_ADDR(pageNum, DSP_W);
            kal_dev_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_WRITE_DSP_SECOND_SEGMENT, DSP_W, count);
            break;
         case MEDIA_FORMAT_DAF:
            idmaPtr=DSP_PM_ADDR(pageNum, DSP_W);
            kal_dev_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_WRITE_DSP_SECOND_SEGMENT, DSP_W, count);
            break;
         default:
            idmaPtr=DSP_PM_ADDR(pageNum, DSP_W);
            kal_dev_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_WRITE_DSP_SECOND_SEGMENT, DSP_W, count);
      }

      if(hdl->mono2stereo)
      {
         IDMA_WriteToDSP_Duplicate(idmaPtr, (uint16*)buf, count);
         buf+=count>>1;
      }
      else
      {
         IDMA_WriteToDSP(idmaPtr, (uint16*)buf, count);
         buf+=count;
      }

      *dspWritePtr = DSP_W + (uint16)count;
   }
   
   if(hdl->mono2stereo)
      return (mblenInWord>>1);
   else
      return mblenInWord;
}

// Dior modify for MT6256 (DAF_DSP_BS_DMPATH)
kal_uint32 autWriteDataFromRBToDSP( MHdl *hdl, kal_uint16 *dspWritePtr, kal_uint16 *dspReadPtr, kal_uint32 pageNum,
   void(*incTime)( MHdl *handle, uint32 num_bytes ), AUD_RB_INFO* srcRB , kal_bool bAllowBuffNotFull)
{
   kal_int32 mbDataLen, mbDataLenLow, mbDataLenHigh;
#if (defined(__BT_A2DP_PROFILE__) && defined(DAF_DECODE)) && !defined(__LOW_COST_SUPPORT_COMMON__)
   SSHdl *my_ss_handle = hdl->ss_handle;
#endif
   kal_uint32 writedatalength = 0;

   mbDataLen = rbGetDataCount(srcRB) >> 1; // in word
   mbDataLenLow = (srcRB->rb_size - srcRB->read) >> 1; // in word
   if( mbDataLenLow > mbDataLen )
      mbDataLenLow = mbDataLen;
   mbDataLenHigh = mbDataLen - mbDataLenLow;
   mbDataLenLow = autWriteDataByIDMA( hdl, dspWritePtr, dspReadPtr, pageNum, mbDataLenLow, srcRB );
   kal_dev_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_WRITE_MCU_FIRST_SEGMENT, srcRB->read, mbDataLenLow);
   mbDataLenLow <<= 1; // in Byte
   writedatalength += mbDataLenLow;

   incTime(hdl, mbDataLenLow);
#if (defined(__BT_A2DP_PROFILE__) && defined(DAF_DECODE)) && !defined(__LOW_COST_SUPPORT_COMMON__) 
   if( is_SSHdl_valid(my_ss_handle) )
      my_ss_handle->PutData(my_ss_handle, &srcRB->rb_base[srcRB->read], mbDataLenLow);
#endif
   srcRB->read += mbDataLenLow;

   if( srcRB->read >= srcRB->rb_size ){
      srcRB->read = 0;
      if( mbDataLenHigh > 0 ) {
         mbDataLenHigh = autWriteDataByIDMA( hdl, dspWritePtr, dspReadPtr, pageNum, mbDataLenHigh, srcRB  );
         kal_dev_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_WRITE_MCU_SECOND_SEGMENT, srcRB->read, mbDataLenHigh);
         mbDataLenHigh <<= 1; // in Byte
         writedatalength += mbDataLenHigh;
         incTime(hdl, mbDataLenHigh);
#if (defined(__BT_A2DP_PROFILE__) && defined(DAF_DECODE)) && !defined(__LOW_COST_SUPPORT_COMMON__)
         if( is_SSHdl_valid(my_ss_handle) )
            my_ss_handle->PutData(my_ss_handle, &srcRB->rb_base[srcRB->read], mbDataLenHigh);
#endif
         srcRB->read += mbDataLenHigh;
      }
   }
   return writedatalength;
}



void autWriteDataToDSP( MHdl *hdl, kal_uint16 *dspWritePtr, kal_uint16 *dspReadPtr, kal_uint32 pageNum,
   void(*incTime)( MHdl *handle, uint32 num_bytes ))
{

   autWriteDataFromRBToDSP(hdl, dspWritePtr, dspReadPtr, pageNum, incTime, &hdl->rbInfo, KAL_FALSE);
}

#endif

//interface for audiohdl
Media_Status autPutRing2LinearBuf( kal_uint8 *dstbuf, AUD_RB_INFO *srcRB, kal_uint32 frame_len)
{
   kal_uint32 segment;
   kal_uint8 *srcbuf;

//   if(rbGetDataCount(srcRB)<(kal_int32)frame_len)
//      return MEDIA_READ_FAIL;
   
   rbGetReadBuffer(srcRB, &srcbuf, &segment);   
   if(segment>=frame_len)
   	  segment = frame_len;
   memcpy(dstbuf, srcbuf, segment*sizeof(kal_uint8));
   rbReadDataDone(srcRB, segment);
   frame_len-=segment;
   if(frame_len==0)
      return MEDIA_SUCCESS;

   dstbuf += segment;
   rbGetReadBuffer(srcRB, &srcbuf, &segment);
   ASSERT(segment>=frame_len);

   memcpy(dstbuf, srcbuf, frame_len*sizeof(kal_uint8));
   rbReadDataDone(srcRB, frame_len);
   
   return MEDIA_SUCCESS;
}

kal_uint8 rbGetByte(AUD_RB_INFO *srcRB)
{
   kal_uint32 segment;
   kal_uint8 *srcbuf;
   kal_uint8 data;
   rbGetReadBuffer(srcRB, &srcbuf, &segment);
   ASSERT(segment>0);
   data = *srcbuf;
   rbReadDataDone(srcRB, 1);
   return data;
}


void putSilence2(kal_uint16 dsp_rb_base, kal_int32 dsp_rb_size, kal_int16 dsp_last_sample_L, kal_int16 dsp_last_sample_R, kal_int32 dsp_len) //working in HISR
{
   kal_uint16 dsp_w = *DSP_PCM_W;

   if (dsp_len <= 0)
      return;
   
   dsp_len &= ~0x1;
   
   /* data transferring via IDMA */
   IDMA_FillToDSP2(DSP_DM_ADDR(PAGE_NUM, dsp_rb_base + dsp_w), dsp_last_sample_L, dsp_last_sample_R, dsp_len);
#if defined(__CVSD_CODEC_SUPPORT__) && defined (__BT_AUDIO_VIA_SCO__)
   BT_SCO_AudioWriteSilence(dsp_len);
#endif
   dsp_w += dsp_len;
   if (dsp_w == dsp_rb_size)
      dsp_w = 0;
   
   /* Update DSP writing pointer */
   *DSP_PCM_W = dsp_w;
}


kal_int32 autPutSilenceToDSP2(kal_uint16 dsp_rb_base, kal_int32 dsp_rb_size, kal_int16 dsp_last_sample_L, kal_int16 dsp_last_sample_R) //working in HISR
{
   kal_int16 rb_w, rb_r_cache, tmp;
   
   do {
      rb_r_cache = (int16)*DSP_PCM_R;
   } while (rb_r_cache != (int16)*DSP_PCM_R);
   
   rb_w = (int16)*DSP_PCM_W;
   rb_r_cache = rb_r_cache - rb_w - 1;
   if (rb_r_cache < 0)
      rb_r_cache += (int16)dsp_rb_size;
   
   tmp = (int16)dsp_rb_size - rb_w;
   if (tmp > rb_r_cache)
      tmp = rb_r_cache;
   
   rb_r_cache &= ~0x1;
   tmp &= ~0x1;
      
   putSilence2( dsp_rb_base, dsp_rb_size, dsp_last_sample_L, dsp_last_sample_R, tmp );
   putSilence2( dsp_rb_base, dsp_rb_size, dsp_last_sample_L, dsp_last_sample_R, rb_r_cache - tmp );

   return rb_r_cache;
}

/* Count the number of remained samples in DSP buffer */
kal_int32 autGetDSPDataCnt( kal_int32 dsp_rb_size ) //working in HISR
{
   kal_int32 cnt;
   kal_int32 rb_w, rb_r;

   rb_w = (kal_int32)*DSP_PCM_W;

   do {
      rb_r = (kal_int32)*DSP_PCM_R;
   } while (rb_r != (kal_int32)*DSP_PCM_R);

   cnt = rb_w - rb_r;
   if (cnt < 0)
      cnt += dsp_rb_size;
   
   return cnt;
}


kal_int8 autGetSampleRateIdx( kal_uint32 SampleRate )
{
   switch( SampleRate / 1000 )
   {
      case 7:  case 8 : return 0;
      case 10: case 11: return 1;
      case 12:          return 2;
      case 15: case 16: return 3;
      case 21: case 22: return 4;
      case 23: case 24: return 5;
      case 31: case 32: return 6;
      case 43: case 44: return 7;
      case 47: case 48: return 8;
      default:
      	 ASSERT(0);   // The sample rate is not supported by ASP.
         //return -1;   
   }
}

#endif // #ifndef __L1_STANDALONE__
/* ------------------------------------------------------------------------------ */

// Add uplink data to downlink with saturation
void autTchReadFromDSP( int16 *buf, kal_uint32 pageNum )
{
#ifndef __L1_STANDALONE__

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    {   // Read from uplink
        uint32 framesize         = Pseudo_SAL_PcmEx_GetBufLen(PSEUDO_SAL_PCMEX_BUF_SE);
        volatile uint16 *dspAddr = Pseudo_SAL_PcmEx_GetBuf   (PSEUDO_SAL_PCMEX_BUF_SE);
        IDMA_ReadFromDSP((kal_uint16 *)buf, dspAddr, framesize);
    }
    
#ifndef BOUNDED
#define BOUNDED(in,up,lo) ((in) > (up) ? (up) : (in) < (lo) ? (lo) : (in))
#endif

    // Add back to downlink
#ifdef L1AUDIO_IDMA_ALL_ADDRESS_MODE
    {   // all address mode
        uint32 framesize         = Pseudo_SAL_PcmEx_GetBufLen(PSEUDO_SAL_PCMEX_BUF_SD);
        volatile uint16 *dspAddr = Pseudo_SAL_PcmEx_GetBuf   (PSEUDO_SAL_PCMEX_BUF_SD);
        int32 I;
        int32 tmp;

        for (I = framesize; I > 0; I--)
        {
            tmp = *buf + (int32)(int16)*dspAddr++;
            *buf++ = (int16)BOUNDED(tmp, 32767, -32768);
        }
    }
#else
    {   //  short mode
        uint32 framesize         = Pseudo_SAL_PcmEx_GetBufLen(PSEUDO_SAL_PCMEX_BUF_SD);
        volatile uint16 *dspAddr = Pseudo_SAL_PcmEx_GetBuf   (PSEUDO_SAL_PCMEX_BUF_SD);
        int32 I;
        int32 tmp = (int32)*dspAddr;    // Dummy read for short mode
        
        for (I = framesize; I > 0; I--)
        {
            tmp = *buf + (int32)(int16)*IDMA_SHORT_ADDR;
            *buf++ = (int16)BOUNDED(tmp, 32767, -32768);
        }
    }
#endif //L1AUDIO_IDMA_ALL_ADDRESS_MODE

#else   // chip compile option

#ifdef L1AUDIO_IDMA_ALL_ADDRESS_MODE
   volatile uint16* idmaPtr;
#endif //L1AUDIO_IDMA_ALL_ADDRESS_MODE

   int32 first_data_block_len, second_data_block_len;
   int32 I, tmp;

   first_data_block_len = (int16)*DP_TCH_UL_BUF_LEN - ((int16)*DP_TCH_UL_PTR - (int16)*DP_TCH_UL_BUF_ADDR0);
   if( first_data_block_len < FRAME_BUF_SIZE )
      second_data_block_len = FRAME_BUF_SIZE - first_data_block_len;
   else {
      first_data_block_len = FRAME_BUF_SIZE;
      second_data_block_len = 0;
   }
   
   IDMA_ReadFromDSP((uint16*)buf, DSP_DM_ADDR(pageNum, *DP_TCH_UL_PTR), first_data_block_len);
   buf+=first_data_block_len;
   if( (I = second_data_block_len) > 0 ){
      IDMA_ReadFromDSP((uint16*)buf, DSP_DM_ADDR(pageNum, *DP_TCH_UL_BUF_ADDR0), second_data_block_len);
      buf+=second_data_block_len;
   }
   
   /* handle downlink data */
   buf -= FRAME_BUF_SIZE;
   first_data_block_len = (int16)*DP_TCH_DL_BUF_LEN - ((int16)*DP_TCH_DL_PTR - (int16)*DP_TCH_DL_BUF_ADDR0);
   if( first_data_block_len < FRAME_BUF_SIZE )
      second_data_block_len = FRAME_BUF_SIZE - first_data_block_len;
   else {
      first_data_block_len = FRAME_BUF_SIZE;
      second_data_block_len = 0;
   }
   
#ifdef L1AUDIO_IDMA_ALL_ADDRESS_MODE

   idmaPtr=DSP_DM_ADDR(pageNum, *DP_TCH_DL_PTR);
   for( I = first_data_block_len; I > 0; I-- ){
      tmp = *buf + (int32)(int16)*idmaPtr++;
      *buf++ = (int16)(( tmp > 32767 )? 32767: (tmp<-32768)?-32768:tmp);
   }
   if( (I = second_data_block_len) > 0 ){
      idmaPtr = DSP_DM_ADDR(pageNum, *DP_TCH_DL_BUF_ADDR0);
      for ( ; I > 0; I-- ){
         tmp = *buf + (int32)(int16)*idmaPtr++;
         *buf++ = (int16)(( tmp > 32767 )? 32767: (tmp<-32768)?-32768:tmp);
      }
   }


#else //L1AUDIO_IDMA_ALL_ADDRESS_MODE
   tmp = *DSP_DM_ADDR(pageNum, *DP_TCH_DL_PTR);  /* Read downlink data */
   for( I = first_data_block_len; I > 0; I-- ){
      tmp = *buf + (int32)(int16)*IDMA_SHORT_ADDR;
      *buf++ = (int16)(( tmp > 32767 )? 32767: (tmp<-32768)?-32768:tmp);
   }
   if( (I = second_data_block_len) > 0 ){
      tmp = *DSP_DM_ADDR(pageNum, *DP_TCH_DL_BUF_ADDR0);
      for ( ; I > 0; I-- ){
         tmp = *buf + (int32)(int16)*IDMA_SHORT_ADDR;
         *buf++ = (int16)(( tmp > 32767 )? 32767: (tmp<-32768)?-32768:tmp);
      }
   }
#endif //L1AUDIO_IDMA_ALL_ADDRESS_MODE

#endif  // chip compile option

#endif // #ifndef __L1_STANDALONE__
}

void Media_EnableHardwareMuteSleep(kal_bool enable)
{
#if HW_MUTE_SUPPORT_PLATFORM
   AFE_EnableHardwareMuteSleep(enable);
#endif
}

//---------------------------------------------

#if defined(AMR_CODEC)
static const kal_uint8 AMR_FileHeader[6] = { 0x23, 0x21, 0x41, 0x4D, 0x52, 0x0A};
#endif
#if defined(AMRWB_DECODE)
static const kal_uint8 AWB_FileHeader[9] = { 0x23, 0x21, 0x41, 0x4D, 0x52, 0x2D, 0x57, 0x42, 0x0A};
#endif


Media_Status Media_GetSilenceFormat(
   Media_Format uFormat,
   kal_uint32 *uChannelNum,
   kal_uint32 *uSampleRate,
   kal_uint8 *pBuf, 
   kal_uint32 uBufLen
)
{
   switch (uFormat) 
   {
#if defined(AMR_CODEC)
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_AMR_TRANSMIT:
      case MEDIA_FORMAT_MP4_AMR:
      {
         *uSampleRate = 8000;
         *uChannelNum = 1;
         break;
      }
#endif
#if defined(AMRWB_DECODE)
      case MEDIA_FORMAT_AMR_WB:
      case MEDIA_FORMAT_MP4_AMR_WB:
      {
         *uSampleRate = 16000;
         *uChannelNum = 1;
         break;
      }
#endif
#if defined(__DRA_DECODE_SUPPORT__)
      case MEDIA_FORMAT_DRA:
      {
         kal_uint32 uSampleRateIndex;
         
         uSampleRateIndex = ((pBuf[3] & 0x7)<<1) | (pBuf[4]>>7);
         if (uSampleRateIndex == 6)
            *uSampleRate = 32000;
         else if (uSampleRateIndex == 7)
            *uSampleRate = 44100;
         else if (uSampleRateIndex == 8)
            *uSampleRate = 48000;
         else
            *uSampleRate = 0;
         
         if (pBuf[4] & 0x1)
            *uChannelNum = 2;
         else
            *uChannelNum = 1;
      }
      break;
#endif
#if defined(AAC_DECODE)
      case MEDIA_FORMAT_AAC:
      case MEDIA_FORMAT_MP4_AAC:
      case MEDIA_FORMAT_AAC_PLUS:
      case MEDIA_FORMAT_AAC_PLUS_V2:
#if !defined(__AUDIO_COMPONENT_SUPPORT__)
      {
         STFSAL *pstFSAL;
         if(uBufLen==0)
         {
            return MEDIA_FAIL;
         }
         pstFSAL = (STFSAL*)get_ctrl_buffer( sizeof(STFSAL) );
         if (pstFSAL == NULL)
         {
            return MEDIA_FAIL;
         }
         FSAL_Direct_SetRamFileSize(pstFSAL, uBufLen);
         {
            FSAL_Status eFSALStatus = FSAL_Open(pstFSAL, pBuf, FSAL_ROMFILE);
            ASSERT( FSAL_OK == eFSALStatus);
         }
         AAC_GetMediaFormat_Detail(pstFSAL, uChannelNum, uSampleRate);
         free_ctrl_buffer(pstFSAL);
         break;
      }
#else
      {
         if(uBufLen==0)
         {
            return MEDIA_FAIL;
         }
         AAC_GetMediaFormat_Detail_v2(pBuf, uBufLen, uChannelNum, uSampleRate);
         break;
      }
#endif
#endif
      default:
         return MEDIA_FAIL;
   }
   return MEDIA_SUCCESS;
}

Media_Status Media_GetFileHeaderLength(
   Media_Format format,
   kal_uint32 channelNum,
   kal_uint32 freq,
   kal_uint32 subframeNum,
   kal_uint32 *len
)
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_HEADER, format, channelNum, freq, subframeNum,0,0,0,0);
   *len = 0;
   switch (format) 
   {
#if defined(AMR_CODEC)
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_MP4_AMR:
         *len = 6;
         break;
#endif
#if defined(AMRWB_DECODE)
      case MEDIA_FORMAT_AMR_WB:
      case MEDIA_FORMAT_MP4_AMR_WB:
         *len = 9;
         break;
#endif
      default:
         break;
   }
   return MEDIA_SUCCESS;
}

Media_Status Media_GetFileHeaderPattern(Media_Format format, kal_uint32 channelNum, kal_uint32 freq, kal_uint32 subframeNum, kal_uint8 *pattern)
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_HEADER, format, channelNum, freq, subframeNum,0,0,0,0);
   switch (format) 
   {
#if defined(AMR_CODEC)
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_MP4_AMR:
         memcpy(pattern, AMR_FileHeader, 6);
         break;
#endif
#if defined(AMRWB_DECODE)
      case MEDIA_FORMAT_AMR_WB:
      case MEDIA_FORMAT_MP4_AMR_WB:
         memcpy(pattern, AWB_FileHeader, 9);
         break;
#endif
      default:
         break;
   }
   return MEDIA_SUCCESS;
}

Media_Status Media_GetSilenceLength(Media_Format format, kal_uint32 channelNum, kal_uint32 freq, kal_uint32 subframeNum, kal_uint32 *len)
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_SILENCE, format, channelNum, freq, subframeNum,0,0,0,0);
   *len = 0;
   switch (format) 
   {
#if defined(__COOK_DECODE__)
      case MEDIA_FORMAT_COOK:
         *len = 4;
         break;
#endif
#if defined(AMR_CODEC) || defined(AMRWB_DECODE)
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_AMR_TRANSMIT:
      case MEDIA_FORMAT_AMR_WB:
      case MEDIA_FORMAT_MP4_AMR:
      case MEDIA_FORMAT_MP4_AMR_WB:
         *len = 1;
         break;
#endif
#if defined(__DRA_DECODE_SUPPORT__)
      case MEDIA_FORMAT_DRA:
         if (( freq == 32000 || freq == 44100 || freq == 48000 ) && (channelNum == 2))
         {
            *len = 8;
         }
         break;
#endif
#if defined(WAV_CODEC)
      case MEDIA_FORMAT_PCM:
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
      case MEDIA_FORMAT_WAV:
         *len = freq*channelNum*2/100;
         break;
#endif
#if defined(AAC_DECODE)
      case MEDIA_FORMAT_AAC:
      case MEDIA_FORMAT_MP4_AAC:
         *len = 16;
         break;
      case MEDIA_FORMAT_AAC_PLUS:
         if (channelNum == 1)
         {
            *len = 29;
         }
         else
         {
            *len = 39;
         }
         break;
      case MEDIA_FORMAT_AAC_PLUS_V2:
         *len = 33;
         break;
#endif
      default:
         *len = 0;
   }
   return MEDIA_SUCCESS;
}

#if defined(AAC_DECODE)

static const kal_uint8 AAC_Mono_SilData[9] = { 0x01, 0x40, 0x20, 0x07, 0xF6, 0x00, 0x00, 0x00, 0x00 };
static const kal_uint8 AAC_Stereo_SilData[9] = { 0x21, 0x00, 0x49, 0x90, 0x02, 0x19, 0x00, 0x23, 0x80 };
static const kal_uint8 AAC_Plus_Mono_SilData[22] = {
   0x00, 0xD0, 0x30, 0x83, 0xE2, 0x5B, 0x66, 0x25, 
   0x77, 0xC4, 0x5A, 0xB7, 0x14, 0x05, 0xD0, 0x40, 
   0x00, 0x00, 0x00, 0x03, 0x80, 0x38
};
static const kal_uint8 AAC_Plus_Stereo_SilData[32] = {
   0x21, 0x19, 0x53, 0x40, 0x7C, 0xCB, 0x6C, 0xA4, 
   0xA1, 0x08, 0x9A, 0x03, 0xE6, 0x5B, 0x65, 0x25, 
   0x08, 0x45, 0xB3, 0x75, 0x60, 0x5D, 0x42, 0x00, 
   0x00, 0x00, 0x01, 0xC6, 0x00, 0x0C, 0x03, 0x80
};
static const kal_uint8 AAC_PS_Mono_SilData[26] = {
   0x00, 0xD0, 0x33, 0x03, 0xE7, 0x5B, 0x88, 0x39, 0x7C, 0xFF, 
   0xFC, 0x5B, 0x77, 0x78, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 
   0x01, 0xC2, 0x54, 0x10, 0x00, 0x38
};

Media_Status  Media_GetSilencePattern_AAC(Media_Format format, kal_uint32 channelNum, kal_uint32 freq, kal_uint32 subframeNum, kal_uint8 *pattern)
{
   kal_uint32 freqIndex = 0;
   kal_uint32 silLen = 0;
   switch (freq) 
   {
      case 8000:
         freqIndex = 11;
         break;
      case 11025:
         freqIndex = 10;
         break;
      case 12000:
         freqIndex = 9;
         break;
      case 16000:
         freqIndex = 8;
         break;
      case 22050:
         freqIndex = 7;
         break;
      case 24000:
         freqIndex = 6;
         break;
      case 32000:
         freqIndex = 5;
         break;
      case 44100:
         freqIndex = 4;
         break;
      case 48000:
         freqIndex = 3;
         break;
      default:
         return MEDIA_UNSUPPORTED_FREQ;
   }

   memcpy(pattern, AAC_Header, 7);

   switch (format) 
   {
      case MEDIA_FORMAT_AAC:
      case MEDIA_FORMAT_MP4_AAC:
         silLen = 16;
         if (channelNum == 1)
         {
            memcpy(pattern+7, AAC_Mono_SilData, 9);
         } 
         else
         {
            memcpy(pattern+7, AAC_Stereo_SilData, 9);
         }
         break;
      case MEDIA_FORMAT_AAC_PLUS:
         if (channelNum == 1) 
         {
            silLen = 29;
            memcpy(pattern+7, AAC_Plus_Mono_SilData, 22);
         }
         else
         {
            silLen = 39;
            memcpy(pattern+7, AAC_Plus_Stereo_SilData, 32);
         }
         break;
      case MEDIA_FORMAT_AAC_PLUS_V2:
         {
            silLen = 33;
            memcpy(pattern+7, AAC_PS_Mono_SilData, 26);
         }
         break;
      default:
         return MEDIA_UNSUPPORTED_TYPE;
   }
   
   // Update AAC ADTS header
   pattern[2] |= (freqIndex<<2);
   pattern[3] |= (channelNum<<6) | (silLen>>11);
   pattern[4] = (silLen>>3)&0xFF;
   pattern[5] |= (silLen & 0x07) << 5;
   return MEDIA_SUCCESS;
}
#endif

#if defined(__DRA_DECODE_SUPPORT__)

#if 0 // file
/* under construction !*/
#else // streaming
static const kal_uint8 DRA_SilData[8] = { 0x7F, 0xFF, 0x00, 0x58, 0x03, 0xA0, 0x00, 0x1F};
#endif

Media_Status Media_GetSilencePattern_DRA(Media_Format format, kal_uint32 channelNum, kal_uint32 freq, kal_uint32 subframeNum, kal_uint8 *pattern)
{
   kal_uint32 ufreqIndex = 0;
   memcpy(pattern, DRA_SilData, 8);
   if (channelNum == 2)
   {
      pattern[4] |= 0x10;
   }
   else
   {
      return MEDIA_UNSUPPORTED_CHANNEL;
   }
         
   if (freq == 32000)
   {
      pattern[3] |= 0x3;
   }
   else if (freq == 44100)
   {
      pattern[3] |= 0x3;
      pattern[4] |= 0x80;
   }
   else if (freq == 48000)
   {
      pattern[3] |= 0x4;
   }   
   else
   {
      return MEDIA_UNSUPPORTED_FREQ;
   } 
   return MEDIA_SUCCESS;
}
#endif

Media_Status  Media_GetSilencePattern(Media_Format format, kal_uint32 channelNum, kal_uint32 freq, kal_uint32 subframeNum, kal_uint8 *pattern)
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_SILENCE_PATTERN, format, channelNum, freq, subframeNum,pattern,0);
   switch (format) 
   {
#if defined(__COOK_DECODE__)
      case MEDIA_FORMAT_COOK:
         pattern[0] = 0xFF; pattern[1] = 0x25; pattern[2] = 0x37; pattern[3] = 0xFF;  
         break;
#endif
#if defined(AMR_CODEC) || defined(AMRWB_DECODE)
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_AMR_TRANSMIT:
      case MEDIA_FORMAT_AMR_WB:
      case MEDIA_FORMAT_MP4_AMR:
      case MEDIA_FORMAT_MP4_AMR_WB:
         pattern[0] = 0x7C;
         break;
#endif
#if defined(__DRA_DECODE_SUPPORT__)
      case MEDIA_FORMAT_DRA:
         return Media_GetSilencePattern_DRA(format,channelNum,freq,subframeNum,pattern);
#endif
#if defined(WAV_CODEC)
      case MEDIA_FORMAT_PCM:
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
      case MEDIA_FORMAT_WAV:
         memset(pattern, 0, freq*channelNum*2/100);
         break;
#endif
#if defined(AAC_DECODE)
      case MEDIA_FORMAT_AAC:
      case MEDIA_FORMAT_MP4_AAC:
      case MEDIA_FORMAT_AAC_PLUS:
      case MEDIA_FORMAT_AAC_PLUS_V2:
         return Media_GetSilencePattern_AAC(format,channelNum,freq,subframeNum,pattern);
#endif
      default:
         return MEDIA_UNSUPPORTED_TYPE;
   }
   return MEDIA_SUCCESS;
}


kal_bool Media_IsFormatSupported(Media_Format uFormat, kal_uint32 channelNum, kal_uint32 freq)
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_IS_FORMAT_SUPPORT, uFormat, channelNum, freq, 0,0,0);
   switch( uFormat ) 
   {
      case MEDIA_FORMAT_UNKNOWN:
         break;
#if defined(AMR_CODEC)
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_AMR_TRANSMIT:
      case MEDIA_FORMAT_MP4_AMR:
      {
         if(channelNum == 1 && freq == 8000)
         {
            return KAL_TRUE;
         }
      }
#endif
#if defined(AMRWB_DECODE)
      case MEDIA_FORMAT_AMR_WB:
      case MEDIA_FORMAT_MP4_AMR_WB:    
      {
         if(channelNum == 1 && freq == 16000)
         {
            return KAL_TRUE;
         }
      }          
#endif
#if defined(AAC_DECODE)      
      case MEDIA_FORMAT_AAC:
      case MEDIA_FORMAT_AAC_PLUS:
      case MEDIA_FORMAT_AAC_PLUS_V2:
      case MEDIA_FORMAT_MP4_AAC: 
      {
         if((channelNum == 1 || channelNum == 2)&& 
            (   freq == 8000  || freq == 11025 || freq == 12000 
             || freq == 16000 || freq == 22050 || freq == 24000 
             || freq == 32000 || freq == 44100 || freq == 48000 
             || freq == 64000 || freq == 88200 || freq == 96000))
         {
            return KAL_TRUE;
         }
      }
#endif
#if defined(__DRA_DECODE_SUPPORT__)
      case MEDIA_FORMAT_DRA:
#endif
#if defined(__COOK_DECODE__)
      case MEDIA_FORMAT_COOK:
#endif
#if defined(DAF_DECODE)
      case MEDIA_FORMAT_DAF:
#endif
#ifdef MUSICAM_DECODE
      case MEDIA_FORMAT_MUSICAM:
#endif
#if defined(WAV_CODEC)
      case MEDIA_FORMAT_PCM:
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:      
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_WAV_16K:
#endif
      {
         if((channelNum == 1 || channelNum == 2)&& 
            (   freq == 8000  || freq == 11025 || freq == 12000 
             || freq == 16000 || freq == 22050 || freq == 24000 
             || freq == 32000 || freq == 44100 || freq == 48000))
         {
            return KAL_TRUE;
         }
      }
      default:
         break;
   }
   return KAL_FALSE;
}


kal_uint32 Media_GetPlaybackPrebufferFrameNum(Media_Format uFormat)
{
#if (!defined(MT6268)&&!defined(MT6236)&&!defined(MT6236B)) 
   switch( uFormat ) 
   {
      case MEDIA_FORMAT_AAC:
      case MEDIA_FORMAT_AAC_PLUS:      	
      case MEDIA_FORMAT_AAC_PLUS_V2:       	
      case MEDIA_FORMAT_MP4_AAC:         	
        return 260;
        
      default:
        break;
   }
#endif
   return 60;
}

kal_bool Media_IsSeekable(STFSAL *pstFSAL, Media_Format uFormat)
{
   
   kal_uint32 uFileSize = 0;
   FSAL_GetFileSize(pstFSAL, &uFileSize);
   
   if( uFileSize >= MAX_SEEKABLE_FILESIZE){
   	  return KAL_FALSE;
   }
   
   switch( uFormat ) 
   {
#if defined(AAC_DECODE)
      case MEDIA_FORMAT_AAC:
      case MEDIA_FORMAT_AAC_PLUS:      	
      case MEDIA_FORMAT_AAC_PLUS_V2:       	
      case MEDIA_FORMAT_MP4_AAC:    
         if(AAC_IsADIF(pstFSAL))
         {
            return KAL_FALSE;
         }
         else
         {
            return KAL_TRUE;
         }        
#endif
#if defined(__APE_DECODE__)
      case MEDIA_FORMAT_APE:    
         return APE_IsSeekable(pstFSAL);
#endif
#if defined(__VM_CODEC_SUPPORT__)
      case MEDIA_FORMAT_GSM_FR:
      case MEDIA_FORMAT_GSM_HR:
      case MEDIA_FORMAT_GSM_EFR:
#endif
      case MEDIA_FORMAT_UNKNOWN: 
#if defined(MIDFILE_PLAY_SUPPORT)
      case MEDIA_FORMAT_SMF: 
#endif
         return KAL_FALSE;
        
      default:
         break;
   }
   return KAL_TRUE;
}

kal_bool Media_IsPauseable(STFSAL *pstFSAL, Media_Format uFormat)
{
   if(uFormat == MEDIA_FORMAT_SMF)
   {
      return KAL_TRUE;
   }
   else
   {
      return Media_IsSeekable(pstFSAL, uFormat);
   }
}

kal_uint32 Media_GetAudioPlaybackRingBufferMinSize(Media_Format uFormat)
{
#if defined(MT6276) 
   switch( uFormat ) 
   {
      case MEDIA_FORMAT_GSM_FR:
      case MEDIA_FORMAT_GSM_HR:
      case MEDIA_FORMAT_GSM_EFR:
         return 8192;
      default:
         return 0;
   }
#else
   switch( uFormat ) 
   {
      case MEDIA_FORMAT_DAF:
      case MEDIA_FORMAT_MUSICAM:
         return 4608;
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_WAV_16K:
      case MEDIA_FORMAT_PCM:
         return 4096; //3760
      default:
         return 2048;
   }
#endif
}

const kal_uint16 awb_byte_rate[9]={824,1106, 1581,1781,1981,2281,2481,2881,2981};
const kal_uint16 amr_byte_rate[8]={1660,1387,1081,1006,911,802,700,646};

kal_uint32 Media_GetRecordFormatByteRate( Media_Format uFormat, Audio_Record_Mode uMode, void *param )
{
   kal_uint32 uByteRate = 16000;
   kal_uint32 uParam = (uint32)param;
   switch( uFormat ) 
   {
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_AMR_TRANSMIT:
      {
         if( uParam>=0x3 && uParam<=0xA )
         {
            uByteRate = amr_byte_rate[uParam-0x3];
         }
         else
         {
            uByteRate = amr_byte_rate[0];
         }
         break;
      }
      case MEDIA_FORMAT_AMR_WB:
      {
         if( uParam>=0x20 && uParam<=0x28 )
         {
            uByteRate = awb_byte_rate[uParam-0x20];
         }
         else
         {
            uByteRate = awb_byte_rate[8];
         }
         break;
      }
      case MEDIA_FORMAT_WAV:
         uByteRate = 16000;
         #if defined(__I2S_WAV_RECORD__)
         { 
             if(I2S_is_I2S_open())
             {
             	  uByteRate = 64000;
             }
         }
         #endif
         break;
      case MEDIA_FORMAT_WAV_16K:
         uByteRate = 32000;
         break;
      case MEDIA_FORMAT_WAV_ALAW:
      case MEDIA_FORMAT_WAV_ULAW:
      case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
         uByteRate = 8110;
         break;
      case MEDIA_FORMAT_WAV_DVI_ADPCM:
         uByteRate = uByteRate = 4055;
         break;
      case MEDIA_FORMAT_VORBIS:
         uByteRate = uByteRate = 5000;
         break;
      case MEDIA_FORMAT_DAF:
         uByteRate = uByteRate = 16000;
         break;
   }

#if defined( __FMRADIO_I2S_SUPPORT__ )
   if( uMode == AUDIO_RECORD_MODE_I2S || uMode == AUDIO_RECORD_MODE_FM )
#else
   if( uMode == AUDIO_RECORD_MODE_I2S )
#endif   
   {
      switch( uFormat ) 
      {
         case MEDIA_FORMAT_WAV:
         case MEDIA_FORMAT_WAV_ALAW:
         case MEDIA_FORMAT_WAV_ULAW:
         case MEDIA_FORMAT_WAV_DVI_ADPCM:
         case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
            uByteRate  = Media_I2S_INPUT_MODE_SR*2/4;
            break;
         case MEDIA_FORMAT_VORBIS:
            uByteRate = 16000;
         default:
            break;
      }
   }
   return uByteRate;
}


Media_Status  Media_GetRecordFormat( Audio_Record_Mode uMode, Audio_Record_Quality uQuality, Audio_Record_Format *pFormatStruct )
{
   pFormatStruct->uFormat = MEDIA_FORMAT_UNKNOWN;
   pFormatStruct->uByteRate = 0;

   switch( uMode ) 
   {
      case AUDIO_RECORD_MODE_SPEECH:
      {
         if(uQuality == AUDIO_RECORD_QUALITY_HIGH)
         {
            pFormatStruct->uFormat = AUDIO_RECORD_SPEECH_MODE_HIGH;
         }
         else
         {
            pFormatStruct->uFormat = AUDIO_RECORD_SPEECH_MODE_LOW;
         }
         break;   
      }
      case AUDIO_RECORD_MODE_FM:
      {
         if(uQuality == AUDIO_RECORD_QUALITY_HIGH)
         {
            pFormatStruct->uFormat = AUDIO_RECORD_FM_MODE_HIGH;
         }
         else
         {
            pFormatStruct->uFormat = AUDIO_RECORD_FM_MODE_LOW;
         }
         break;   
      }
      case AUDIO_RECORD_MODE_IDLE:
      {
         if(uQuality == AUDIO_RECORD_QUALITY_HIGH)
         {
            pFormatStruct->uFormat = AUDIO_RECORD_IDLE_MODE_HIGH;
         }
         else
         {
            pFormatStruct->uFormat = AUDIO_RECORD_IDLE_MODE_LOW;
         }
         break;   
      }
      case AUDIO_RECORD_MODE_I2S:
      {
         if(uQuality == AUDIO_RECORD_QUALITY_HIGH)
         {
            pFormatStruct->uFormat = AUDIO_RECORD_I2S_MODE_HIGH;
         }
         else
         {
            pFormatStruct->uFormat = AUDIO_RECORD_I2S_MODE_LOW;
         }
         break;   
      }
      default:
         break;
   }

   pFormatStruct->uByteRate = pFormatStruct->uByteRate = Media_GetRecordFormatByteRate( pFormatStruct->uFormat, uMode, NULL);
   switch( pFormatStruct->uFormat ) 
   {
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_AMR_TRANSMIT:
         kal_wstrcpy(pFormatStruct->pFileExtension, L".amr");
         break;
      case MEDIA_FORMAT_AMR_WB:
         kal_wstrcpy(pFormatStruct->pFileExtension, L".awb");
         break;
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_WAV_ALAW:
      case MEDIA_FORMAT_WAV_ULAW:
      case MEDIA_FORMAT_WAV_DVI_ADPCM:
      case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
      case MEDIA_FORMAT_WAV_16K:
         kal_wstrcpy(pFormatStruct->pFileExtension, L".wav");
         break;
      case MEDIA_FORMAT_VORBIS:
         kal_wstrcpy(pFormatStruct->pFileExtension, L".ogg");
         break;
      default:
         return MEDIA_FAIL;
   }
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_RECORD_FORMAT, uMode, uQuality, pFormatStruct->uFormat, pFormatStruct->uByteRate,0,0);
   return MEDIA_SUCCESS;
}


//-------------------------------------------
kal_bool Media_IsPlaybackOn( void )
{
   if ( -1 != AM_IsAudioPlaybackOn() )
      return KAL_TRUE;
   if ( AM_IsVMPlaybackOn() )
      return KAL_TRUE;

   return KAL_FALSE;
}

//-------------------------------------------

Media_Format MP4_Audio_Type_To_Media_Format(MP4_Audio_Type eAudioType)
{
   Media_Format eAudioFormat = (Media_Format)0;

   switch(eAudioType) {
      case MP4_AUDIO_AAC:
         eAudioFormat = MEDIA_FORMAT_MP4_AAC;
         break;
      case MP4_AUDIO_AMR:
         eAudioFormat = MEDIA_FORMAT_MP4_AMR;
         break;
      case MP4_AUDIO_AMR_WB:
         eAudioFormat = MEDIA_FORMAT_MP4_AMR_WB;
         break;
      case MP4_AUDIO_BSAC:
         eAudioFormat = MEDIA_FORMAT_MP4_BSAC;
         break;
      case MP4_AUDIO_NONE:
         eAudioFormat = MEDIA_FORMAT_MP4_AMR;
         break;
   }
   return eAudioFormat;
}

void Media_GetMaxMinRate(Media_Format eFormat, kal_int32* max, kal_int32* min)
{
   switch(eFormat){
      case MEDIA_FORMAT_SMF:
      case MEDIA_FORMAT_JTS:
         *max = 400*1000;
         *min =  25*1000;
         break;
      default:
         *max = 160*1000;
         *min =  50*1000;
         break;
   }
}

void Media_GetMMACapability(Media_Format eFormat, kal_uint8* concurrent)
{
   switch(eFormat){
      case MEDIA_FORMAT_SMF:
         *concurrent = MAX_MMA_PLAYERS_SMF;
         break;
      case MEDIA_FORMAT_IMELODY:
         *concurrent = MAX_MMA_PLAYERS_IMY;
         break;
      case MEDIA_FORMAT_JTS:
         *concurrent = MAX_MMA_PLAYERS_JTS;
         break;
      case MEDIA_FORMAT_WAV:
         *concurrent = MAX_MMA_PLAYERS_WAV;
         break;    
      default:
         *concurrent = MAX_MMA_PLAYERS_AUD;
         break;
   }
}

Media_Status Media_FastPassMode(void* hdl, Media_Format eFormat){return (Media_Status)0;}

#if !defined(DAF_DECODE)

typedef struct mh_internal {
   MHdl             mh;
} dafMediaHdl;

// Dummy function
kal_bool dafGetBitRateIdx(uint16 wFHdrW1, uint16 wFHdrW2, int16* wBitRateIdx)
{
   return true;
}

void dafUpdateInfo(dafMediaHdl *ihdl, uint16 wFHdrW1, uint16 wFHdrW2)
{

}

int MP3FrmLen_GetFrmLenTable(
   short frameLengthTable[45],
   int* firstFHPosition,
   const unsigned char* pBS_BUF,
   int  uBS_BUF_Size,
   const unsigned char* pBS_Read) 
{
   return 0;
}

#endif

int my_log2(const unsigned int number, const unsigned int number_mantissa_size, const unsigned int log_mantissa_size)
{
   // cpower is chosen so that ((2^(cpower+1))-1)^2 will fit in an unsigned int
   unsigned int cpower = ((sizeof(unsigned int)*8)/2)-1;
   unsigned int one = 1 << cpower;
   unsigned int two = 2 << cpower;
   int l;
   unsigned int n;
   unsigned int mantissa_bit;

   // zero will mess up the algorithm below
   if ( number == 0 )
      return 0;

   l = cpower - number_mantissa_size; // number is actually number/(2^number_mantissa_size), so number_mantissa_size is subtracted from the log (it is done at the beginning to circumvent having to shift number_mantissa_size)
   n = number;

   // make sure one <= n < two (and administrer any shifts in l, l becomes floor(log(number)))
   while(n < one)
   {
      n <<= 1;
      --l;
   }
   while(n >= two)
   {
      n >>= 1;
      ++l;
   }

   // now calculate some binary digits
   for( mantissa_bit = 0; mantissa_bit < log_mantissa_size; ++mantissa_bit)
   {
      l <<= 1u;		// make room for an extra bit (shifting a negative signed integer works perfectly!)
      n *= n;			// n_new = n_old^2 = (2^0.yxxx)^2 = 2^y.xxx
      n >>= cpower;	// normalize n to keep n from getting too large
      if ( n >= two )
      {	// apparently y (see the comment behind n *= n) was 1
         l |= 1;	// set the LSB to 1
         n >>= 1;	// divide by two, subtracting 1 from 1.xxx (n/2 = (2^-1)(2^1.xxx) = 2^0.xxx) to prepare for the next step
      }
   }
   
   return l;
}

void ClearDSPAudioCommonFlag(void){
#if defined(MT6256) || defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   *DP2_AUDIO_ASP_COMMON_FLAG_1 = 0;
#else

#endif
}

#if defined(__DUAL_MIC_SUPPORT__)
/**
@deprecated
*/
kal_uint32 Media_GetRecordDataRate(Media_Format format, void *param)
{
	switch(format)
	{
		case MEDIA_FORMAT_GSM_FR:
			 return (L1Audio_GetDebugInfo(STEREO_RECORD_INFO) & 1) ? 128000  : 64000;
	    case MEDIA_FORMAT_GSM_HR:
			 return (L1Audio_GetDebugInfo(STEREO_RECORD_INFO) & 1) ? 64000  : 32000;
   		default:
   			return 0;
	}	
}
#endif


//FIXME:
/**
	@return: mapping to "Media_Speech_Feature" to indicate the feature existing. 
*/
kal_uint32 Media_GetSpeechFeatureCapability(void)

{
	uint32 features = MEDIA_SPEECH_FEATURE_NONE;
	
#if defined(__DUAL_MIC_SUPPORT__) //DMNR in NB
	features |= MEDIA_SPEECH_FEATURE_NB_DMNR; 
	
#if defined(__AMRWB_LINK_SUPPORT__) //DMNR in WB
	features |= MEDIA_SPEECH_FEATURE_WB_DMNR; 
#endif //__AMRWB_LINK_SUPPORT__  (inside __DUAL_MIC_SUPPORT__)
#endif //__DUAL_MIC_SUPPORT__

#if defined(__AMRWB_LINK_SUPPORT__) //Speech phone call is WB
	features |= MEDIA_SPEECH_FEATURE_WB_LINK_SUPPORT;
#endif

#if defined(__HD_RECORD__)
	features |= MEDIA_SPEECH_FEATURE_HD_RECORD;

#if defined(__STEREO_RECORD__)
	features |= MEDIA_SPEECH_FEATURE_STEREO_RECORD;

#endif //__STEREO_RECORD__ (inside __HD_RECORD__)
#endif //__HD_RECORD__

	return features;
}


kal_bool Media_SetKaraoke(kal_bool enable)
{
#if defined(__KARAOKE_SUPPORT__)
   kal_uint16 aud_id;
   aud_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( aud_id );
   if(enable)
   {
   	  KT_StopAndWait();
      TONE_StopAndWait();
   	  PcmSink_TerminateSound();
   	  Karaoke_Init();
   	  AudioPP_DisableBesSound();
      if (AM_IsAudioPlaybackOn()!=-1)
      {
      	  L1Audio_ClearFlag( aud_id );
          L1Audio_FreeAudioID( aud_id );
      	  return KAL_FALSE;
      }
      else{
         AFE_SetKaraoke(KAL_TRUE);
         *DP_DEBUG_ASSERT_CTRL |= 0x0008;
#if defined(MT6261) || defined(MT2501) || defined(MT2502)         
         *DSP_SPH_8K_DIS_VBI_CTRL |= 0x0001;
#endif
         media.KaraokMode = KAL_TRUE;
         L1Audio_ClearFlag( aud_id );
         L1Audio_FreeAudioID( aud_id );
         return KAL_TRUE;
      }
   }
   else
   {
   	  AFE_SetKaraoke(KAL_FALSE);
   	  *DP_DEBUG_ASSERT_CTRL &= ~0x0008; 
#if defined(MT6261) || defined(MT2501) || defined(MT2502)    	  
   	  *DSP_SPH_8K_DIS_VBI_CTRL &= ~0x0001;
#endif   	  
   	  media.KaraokMode = KAL_FALSE; 
   	  AudioPP_EnableBesSound();
   	  L1Audio_ClearFlag( aud_id );
      L1Audio_FreeAudioID( aud_id );   	  
   	  return KAL_TRUE;  
   }          	
#else           	
   // do not support Karaoke mode
   return KAL_FALSE;
#endif   
}

kal_bool Media_IsKaraoke(void) 
{
#if defined(__KARAOKE_SUPPORT__)
   return media.KaraokMode;
#else
   return KAL_FALSE;
#endif
}


void Media_SetKaraRecMixChannel(Media_KaraRec_Mix_CH channel)
{
#if defined(__KARAOKE_SUPPORT__)
   media.KaraokMode_rec_mix_ch = channel;
#endif   
}


Media_KaraRec_Mix_CH Media_GetKaraRecMixChannel(void)
{
#if defined(__KARAOKE_SUPPORT__)
   return media.KaraokMode_rec_mix_ch;
#endif   
}


void Media_SetKaraOperationMode(Media_Kara_opt_mode mode)
{
#if defined(__KARAOKE_SUPPORT__)
   media.KaraokMode_opt_type = mode;
#endif   
}


Media_Kara_opt_mode Media_GetKaraOperationMode(void)
{
#if defined(__KARAOKE_SUPPORT__)
   return media.KaraokMode_opt_type;
#endif 	
}

void Media_SetChargePump(kal_bool enable, Media_VCP_DS_Module module)
{
#if defined(__CLASSK_CP_SUPPORT__)
   AFE_SetChargePump(enable, module);
#endif	
}


kal_bool Media_IsChargePump(void) 
{
#if defined(__CLASSK_CP_SUPPORT__)	
   return AFE_IsCPEnable();
#else
   return KAL_FALSE;
#endif    
}

void Media_SetBLISRC(kal_bool enable)
{
#if defined(__LOW_COST_SUPPORT_COMMON__)&& (defined(__BT_AUDIO_VIA_SCO__) || defined(__AUD_SW_CODEC__)) //&& !defined(__AUDIO_ULTRA_SLIM__)	
	if(enable)
	{
     if(!Bli_AP_flag) //avoid re-entry
     {
		    //Just re-build table
		    Bli_AP_flag  = KAL_TRUE;
		    Bli_DRV_flag = KAL_TRUE;
		    BLI_Open(0, 0, 0, 0, 0, audio_alloc_ext_mem_cacheable_simplified);
		 }
	}
	else
	{ 
		 if(Bli_AP_flag) //avoid re-entry
		 {
		    //Fake hdl for free table
		    BLI_Close((void*)0x1, audio_free_ext_mem_simplified);
		    Bli_AP_flag  = KAL_FALSE;
		    Bli_DRV_flag = KAL_FALSE;
		 } 
	}	
#endif
}

#if defined(__PCM_CLOCK_SWITCH_SUPPORT__) || defined(__AUDIO_AT_CMD__)
/*************************************************************\
|                                                             |
| Defines                                                     |
|                                                             |
\*************************************************************/
#if defined(MT6260)
#define REG_PCM_CLK_GPIO_DIR        (*(volatile kal_uint16 *)(0xA0020030))
#define REG_PCM_CLK_GPIO_PULLEN     (*(volatile kal_uint16 *)(0xA0020130))
#define REG_PCM_CLK_GPIO_MODE       (*(volatile kal_uint32 *)(0xA0020C60))
#define PCM_CLK_GPIO_DIR_MASK       0xFFFF
#define PCM_CLK_GPIO_DIR_SETTING    0xFFDF
#define PCM_CLK_GPIO_PULLEN_SETTING 0x0000
#define PCM_CLK_GPIO_MODE_MASK      0x000FF0FF
#define PCM_CLK_GPIO_MODE_SETTING   0x44400400
#elif defined(MT6261) || defined(MT2501) || defined(MT2502)
#define REG_PCM_CLK_GPIO_DIR        (*(volatile kal_uint16 *)(0xA0020010))
#define REG_PCM_CLK_GPIO_PULLEN     0
#define REG_PCM_CLK_GPIO_MODE       (*(volatile kal_uint32 *)(0xA0020C40))
#define PCM_CLK_GPIO_DIR_MASK       0xFFE1
#define PCM_CLK_GPIO_DIR_SETTING    0x001A
#define PCM_CLK_GPIO_PULLEN_SETTING 0x0000
#define PCM_CLK_GPIO_MODE_MASK      0xFFF0000F
#define PCM_CLK_GPIO_MODE_SETTING   0x00044440
#else
#define REG_PCM_CLK_GPIO_DIR        0
#define REG_PCM_CLK_GPIO_PULLEN     0
#define REG_PCM_CLK_GPIO_MODE       0
#define PCM_CLK_GPIO_DIR_MASK       0
#define PCM_CLK_GPIO_DIR_SETTING    0
#define PCM_CLK_GPIO_PULLEN_SETTING 0
#define PCM_CLK_GPIO_MODE_MASK      0
#define PCM_CLK_GPIO_MODE_SETTING   0
#endif

/*************************************************************\
|                                                             |
| Static Variables                                            |
|                                                             |
\*************************************************************/
static struct {
    kal_bool b_enable;
    kal_bool b_activate;
    kal_uint16 gpio_dir;
    kal_uint16 gpio_pullen;
    kal_uint32 gpio_mode;
    kal_uint32 aud_id;
} pcm_clk;

/*************************************************************\
|                                                             |
| Private Interface                                           |
|                                                             |
\*************************************************************/
static void PCM_CLK_GPIO_Switch(kal_bool b_PCM_GPIO_on)
{
    if (b_PCM_GPIO_on)
    {
        pcm_clk.gpio_dir    = REG_PCM_CLK_GPIO_DIR;
        pcm_clk.gpio_pullen = REG_PCM_CLK_GPIO_PULLEN;
        pcm_clk.gpio_mode   = REG_PCM_CLK_GPIO_MODE;
        REG_PCM_CLK_GPIO_DIR    = (pcm_clk.gpio_dir & PCM_CLK_GPIO_DIR_MASK) | PCM_CLK_GPIO_DIR_SETTING;
#if defined(MT6260)
        REG_PCM_CLK_GPIO_PULLEN = PCM_CLK_GPIO_PULLEN_SETTING;
#endif
        REG_PCM_CLK_GPIO_MODE   = (pcm_clk.gpio_mode & PCM_CLK_GPIO_MODE_MASK) | PCM_CLK_GPIO_MODE_SETTING;
        kal_trace(TRACE_GROUP_PCM_CLK, PCM_CLK_TRACE_GPIO_ON, REG_PCM_CLK_GPIO_DIR, REG_PCM_CLK_GPIO_PULLEN, REG_PCM_CLK_GPIO_MODE);
    }
    else
    {
        REG_PCM_CLK_GPIO_DIR    = pcm_clk.gpio_dir;
#if defined(MT6260)
        REG_PCM_CLK_GPIO_PULLEN = pcm_clk.gpio_pullen;
#endif
        REG_PCM_CLK_GPIO_MODE   = pcm_clk.gpio_mode;
        kal_trace(TRACE_GROUP_PCM_CLK, PCM_CLK_TRACE_GPIO_OFF, REG_PCM_CLK_GPIO_DIR, REG_PCM_CLK_GPIO_PULLEN, REG_PCM_CLK_GPIO_MODE);
    }
    
    return;
}

/*************************************************************\
|                                                             |
| Public Interface                                            |
|                                                             |
\*************************************************************/
void PCM_CLK_Init (void)
{
    kal_trace(TRACE_GROUP_PCM_CLK, PCM_CLK_TRACE_INIT);
    
    pcm_clk.b_enable    = KAL_FALSE;
    pcm_clk.b_activate  = KAL_FALSE;
    pcm_clk.gpio_dir    = 0;
    pcm_clk.gpio_pullen = 0;
    pcm_clk.gpio_mode   = 0;
    pcm_clk.aud_id      = 0;
    
    return;
}

kal_bool PCM_CLK_Is_Enabled (void)
{
    kal_trace(TRACE_GROUP_PCM_CLK, PCM_CLK_TRACE_IS_ENABLED, pcm_clk.b_enable);
    
    return pcm_clk.b_enable;
}

void PCM_CLK_Activate (void)
{
    if (!pcm_clk.b_activate)
    {
        kal_trace(TRACE_GROUP_PCM_CLK, PCM_CLK_TRACE_ACTIVATING);
        
        PCM_CLK_GPIO_Switch(KAL_TRUE);
        AM_PCMClockOn();
        pcm_clk.b_activate = KAL_TRUE;
    }
    else
    {
        kal_trace(TRACE_GROUP_PCM_CLK, PCM_CLK_TRACE_ACTIVATED);
    }
    
    return;
}

void PCM_CLK_Deactivate (void)
{
    if (pcm_clk.b_activate)
    {
        kal_trace(TRACE_GROUP_PCM_CLK, PCM_CLK_TRACE_DEACTIVATING);
        
        AM_PCMClockOff();
        PCM_CLK_GPIO_Switch(KAL_FALSE);
        pcm_clk.b_activate = KAL_FALSE;
    }
    else
    {
        kal_trace(TRACE_GROUP_PCM_CLK, PCM_CLK_TRACE_DEACTIVATED);
    }
    
    return;
}

#endif  // defined(__PCM_CLOCK_SWITCH_SUPPORT__)

#if defined(__PCM_CLOCK_SWITCH_SUPPORT__) || defined(__AUDIO_AT_CMD__)
void pmu_vmc_enable(kal_bool enable)
{
  DCL_HANDLE handle;
  PMU_CTRL_LDO_BUCK_SET_EN val;
  
  val.enable=enable;
  val.mod=VMC;
  
  handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
  DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
  DclPMU_Close(handle);
}
#endif

Media_Status Media_PCM_Clock_Enable (kal_bool b_enable)
{
#if defined(__PCM_CLOCK_SWITCH_SUPPORT__) || defined(__AUDIO_AT_CMD__)
    if (b_enable != pcm_clk.b_enable)
    {
        kal_trace(TRACE_GROUP_PCM_CLK, PCM_CLK_TRACE_ENABLE_CHANGE, b_enable);
        
        if (b_enable)
        {   // Turn on PCM clock
            pmu_vmc_enable(KAL_TRUE);
            pcm_clk.aud_id = L1Audio_GetAudioID();
            L1Audio_SetFlag(pcm_clk.aud_id);
            PCM_CLK_Activate();
        }
        else
        {   // Turn off PCM clock
            PCM_CLK_Deactivate();
            L1Audio_ClearFlag(pcm_clk.aud_id);
            L1Audio_FreeAudioID(pcm_clk.aud_id);
            pmu_vmc_enable(KAL_FALSE);
        }
        
        pcm_clk.b_enable = b_enable;
    }
    else
    {
        kal_trace(TRACE_GROUP_PCM_CLK, PCM_CLK_TRACE_ENABLE_BYPASS, b_enable);
    }
    return MEDIA_SUCCESS;
#else   // defined(__PCM_CLOCK_SWITCH_SUPPORT__)
    kal_trace(TRACE_GROUP_PCM_CLK, PCM_CLK_TRACE_ENABLE_NOT_SUPPORT, b_enable);
    return MEDIA_FAIL;
#endif  // defined(__PCM_CLOCK_SWITCH_SUPPORT__)
}

//  bt_mode
//  0: normal mode
//  1: BT cordless mode
//  2: BT earphone mode
Media_Status Media_PCM_Interface_Enable (kal_uint8 type)
{
#if defined(__PCM_INTERFACE_SUPPORT__)	
    if (type == 2) 
    {
       unsigned short Speech_Para[16] = DEFAULT_SPEECH_BT_EARPHONE_MODE_PARA; 
       L1SP_SetSpeechMode(SPH_MODE_BT_EARPHONE, Speech_Para); 
    }
    else if (type == 1)
    {
       unsigned short Speech_Para[16] = DEFAULT_SPEECH_BT_CORDLESS_MODE_PARA;
       L1SP_SetSpeechMode(SPH_MODE_BT_CORDLESS, Speech_Para); 
    }
    else if (type == 0)
    {
    	 unsigned short Speech_Para[16] = DEFAULT_SPEECH_NORMAL_MODE_PARA;
    	 L1SP_SetSpeechMode(SPH_MODE_NORMAL, Speech_Para);
    }	
    return MEDIA_SUCCESS;
#else
    return MEDIA_FAIL; 
#endif
}
