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
 * media_avsync.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   A/V Sync Interface
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
 *
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
 *
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
 *
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
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/


/*
 * Note: A/V Sync DSP/MCU Interface exists since MT6219.
 */

#ifndef WIN32

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "reg_base.h"
#include "kal_trace.h"
#include "l1sp_trc.h"

#include "l1audio.h"
#include "audio_def.h"
#include "media.h"
#include "am.h"
#include "common_def.h"

#else

#include <stdio.h>
#include <assert.h>
#include <string.h>
#define ASSERT(x) assert(x)
#define kal_mem_cpy(a,b,c) memcpy(a,b,c)
#include "kal_general_types.h"
#include "audio_def.h"
#include "l1audio.h"
#include "am.h"

kal_uint16 a2v_int_cnt;
kal_uint16 a2v_int_enable;
kal_uint16 a2v_int_stamp;
kal_uint16 share_d2mcon;
kal_uint16 a2v_audio_frame_count;
kal_uint16 a2v_video_frame_count;
#define A2V_INT_CNT (&a2v_int_cnt)
#define A2V_INT_ENABLE (&a2v_int_enable)
#define A2V_INT_STAMP (&a2v_int_stamp)
#define SHARE_D2MCON (&share_d2mcon)
#define A2V_AUDIO_FRAME_COUNT (&a2v_audio_frame_count)
#define A2V_VIDEO_FRAME_COUNT (&a2v_video_frame_count)
#define DSP_ENA_AVSYNC_INTERRUPT 0x0020
#define kal_sleep_task

#endif /* UNIT_TEST_ON_WIN32 */



#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 

#define AVSYNC_CHECK_REENTRY 0

#define AVSYNC_STATE_IDLE 0
#define AVSYNC_STATE_INITIAL 3
#define AVSYNC_STATE_RUNNING 1
// #define AVSYNC_STATE_STOP 5
#define AVSYNC_STATE_STOP 0

struct {
   /// audio interrupt counts, 32-bit
   kal_uint32 uInterruptCount;
   /// previous audio interrupt counts that has been returned to application, 32-bit
   kal_uint32 uPrevQueryInterruptCount;
   /// playback time base, set by application, 64-bit
   kal_uint64 uPlaybackTimeBase;
   kal_uint32 uPlaybackRemainderScaleTime;
   /// audio interrupt count maintained in DSP, 16-bit
   kal_uint16 wDSPCount_Prev;
   /// audio ID        
   kal_uint16       aud_id;
   /// call-back function when a/v interrupt occurs
   void (*a2v_lisr_callback)(void);
   /// Media Format
   Media_Format format;
   // Frequency Index
   kal_uint32 uFreqIndex;
   // Frequency
   kal_uint32 uSampleUnit;
   // Speed Scale
   kal_uint32 uSpeedScale;
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   // The remainder of 1/6000 sample
   kal_uint64 uRemainder;
#else
   // The remainder of 1/60 sample
   kal_uint32 uRemainder;
#endif
#if VERIFY_AVSYNC
   /// previous audio interrupt counts, 32-bit
   kal_uint32 uPrevInterruptCount;
#endif
} media_a2v;

#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
/// msTimes from video driver
kal_uint16 msTimes_fromV = 0;
#endif

void media_a2v_increment_interrupt_count(void)
{
   kal_uint16 wDSPCount_Cur;

   wDSPCount_Cur = *DP_A2V_INT_CNT;

   if (wDSPCount_Cur < media_a2v.wDSPCount_Prev) { /* need a carry */
      /* dsp counts to 0x7FFF and return to 0 */
      media_a2v.uInterruptCount += ( (kal_uint32)(wDSPCount_Cur + 0x8000) - media_a2v.wDSPCount_Prev);
   } else {
      media_a2v.uInterruptCount += (wDSPCount_Cur - media_a2v.wDSPCount_Prev);
   }

   media_a2v.wDSPCount_Prev = wDSPCount_Cur;
}

kal_uint32 Media_A2V_GetInterruptCount(void)
{
   media_a2v_increment_interrupt_count();
   return media_a2v.uInterruptCount;
}

void AVsync_Init( void )
{
	  media_a2v.aud_id = L1Audio_GetAudioID();
}

/***
 * Set DP_A2V_INT_ENABLE to transit state to AVSYNC_STATE_RUNNING
 * Do this before turning on VBI interrupt.
 */
void media_a2v_start_dsp(void)
{
      *DP_A2V_INT_ENABLE = AVSYNC_STATE_INITIAL;
}

/***
 * Set DP_A2V_INT_ENABLE to transit state to AVSYNC_STATE_IDLE
 * Do this after turning off VBI interrupt.
 */
void media_a2v_stop_dsp(void)
{
      *DP_A2V_INT_ENABLE = AVSYNC_STATE_STOP;
}

kal_uint32 Media_A2V_GetFreq(void)
{
   kal_uint32 uSampleRate = 0;
   if(AM_IsAVsyncOn())
   {
      switch (media_a2v.uFreqIndex) 
      {
         case 0xa:
            uSampleRate = 8000;
            break;
         case 0x9:
            uSampleRate = 11025;
            break;
         case 0x8:
            uSampleRate = 12000;
            break;         
         case 0x7:
            uSampleRate = 16000;
            break;  
         case 0x6:
            uSampleRate = 22050;
            break;           
         case 0x5:
            uSampleRate = 24000;
            break;  
         case 0x4:
            uSampleRate = 32000;
            break;  
         case 0x3:
            uSampleRate = 44100;
            break;  
         case 0x2:
         case 0x1:
         case 0x0:
            uSampleRate = 48000;
            break;           
         default:
            break;
      }
   }
   return uSampleRate;
}


/***
 * Enable or disable A2V interrupt.
 */
void Media_A2V_EnableInterrupt(kal_bool bFlag, kal_uint32 start_count)
{
#if !(VERIFY_AVSYNC)   
   PcmSink_TerminateSound();
#endif	   
   if (KAL_TRUE==bFlag) {
#if (__AM_DSP_IN_TASK__)
      media_a2v_stop_dsp();
#endif   
      AM_AVSync_On();
      media_a2v.uInterruptCount = start_count;
      media_a2v.uPrevQueryInterruptCount = start_count;
#if VERIFY_AVSYNC
      media_a2v.uPrevInterruptCount = start_count;
#endif
      media_a2v.wDSPCount_Prev = 0;
      /* Do a  stop first in order to make sure DSP initialize A2V related registers */
#if (!__AM_DSP_IN_TASK__)
      media_a2v_stop_dsp();
#endif
      *DP_A2V_INT_CNT = 0;
   } else if (KAL_FALSE==bFlag) {
      media_a2v_stop_dsp();
      AM_AVSync_Off();
      #if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
      msTimes_fromV = 0;
      #endif
   } else {
      ASSERT(KAL_FALSE);
   }
}

/***
 * For MPEG4 encoding: set the interrupt count to the previous paused point to resume encoding
 */
void Media_A2V_SetInterruptCount(kal_uint32 uInterruptCount)
{
   media_a2v.uInterruptCount = uInterruptCount;
}

/***
 * Set the time stamp for displaying the next video frame to DSP.
 */
void Media_A2V_HookInterrupt(void (*a2v_lisr)(void))
{
   media_a2v.a2v_lisr_callback = a2v_lisr;
   
   if (media_a2v.format == 0)
      media_a2v.format = MEDIA_FORMAT_DAF;
}

void Media_A2V_DisableDspSleep(kal_bool disable)
{
#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
   if(disable)
   {      	      	     
   	   if (!L1Audio_CheckFlag( media_a2v.aud_id ))
             L1Audio_SetFlag( media_a2v.aud_id ); // disable sleep mode 

   }
   else
   {   
   	   if (L1Audio_CheckFlag( media_a2v.aud_id ))
            L1Audio_ClearFlag( media_a2v.aud_id ); //enable sleep mode     
   }
#endif
}

/***
 * Set the time stamp for displaying the next video frame to DSP.
 */
void Media_A2V_SetTimeStamp(kal_uint16 wTimeStamp)
{
   *DP_A2V_INT_STAMP = wTimeStamp;
}

/***
 * Get the number of decoded audio frame from DSP
 */
kal_uint16 Media_A2V_GetAudioFrameCount(void)
{
   return *DP_A2V_AUDIO_FRAME_COUNT;
}

/***
 * Get the number of D2M interrupts for displaying a video frame
 */
kal_uint16 Media_A2V_GetVideoFrameCount(void)
{
   return *DP_A2V_VIDEO_FRAME_COUNT;
}

/***
 * This function will be called from L1SP_D2C_LISR in l1sp.c when a/v sync interrupt occurs
 */
void Media_A2V_LISR(void)
{
#if AVSYNC_CHECK_REENTRY
   static kal_uint32 uReentry = 0;

   ASSERT(uReentry==0);
   if (uReentry!=0)
      return;
   uReentry = 1;
#endif

   if (media_a2v.a2v_lisr_callback!=NULL)
      media_a2v.a2v_lisr_callback();
   media_a2v_increment_interrupt_count();

#if VERIFY_AVSYNC
   /* check timing correctness */
   {
      if (media_a2v.uPrevInterruptCount > 0) {
         kal_uint32 uDeltaInterruptCount = media_a2v.uInterruptCount - media_a2v.uPrevInterruptCount;
         kal_uint32 uTargetInterruptCount = (*DP_A2V_INT_STAMP);
         kal_uint32 uDiff = uDeltaInterruptCount > uTargetInterruptCount ?
            uDeltaInterruptCount - uTargetInterruptCount : uTargetInterruptCount - uDeltaInterruptCount;
       
      }
      media_a2v.uPrevInterruptCount = media_a2v.uInterruptCount;
   }
#endif

#if AVSYNC_CHECK_REENTRY
   uReentry = 0;
#endif
}

/*
 * bSamplingFreqIndex: The one defined in 14496-3.
 */
kal_uint32 Media_A2V_GetPlaybackInterruptTimeScale(Media_Format eFormat, kal_uint8 bSamplingFreqIndex)
{
   (void) eFormat;

   switch( bSamplingFreqIndex ) {
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
      case 0x03:
         return 8000; /* 48000/6 */
      case 0x06:
         return 4000; /* 24000/6 */
      case 0x09:
         return 2000; /* 12000/6 */
      case 0x04:
         return 7350; /* 44100/6 */
      case 0x07:
         return 3675; /* 22050/6 */
      case 0x0a:
         return 1837; /* 11025/6 */
      case 0x05:
         return 5333; /* 32000/6 */
      case 0x08:
         return 2666; /* 16000/6 */
      case 0x0b:
         return 1333; /* 8000/6 */
      default:
         return 1333; /* amr silence frame*/
#else
      case 0x03:
      case 0x06:
      case 0x09:
         return 8000; /* 48000/6 */
      case 0x04:
      case 0x07:
      case 0x0a:
         return 7350; /* 44100/6 */
      case 0x05:
      case 0x08:
      case 0x0b:
         return 5333; /* 32000/6 */
      default:
         return 5333; /* amr silence frame*/
#endif
   }
}

kal_uint32 Media_A2V_GetRecInterruptTimeScale(Media_Format eFormat, kal_uint8 bSamplingFreqIndex)
{
   switch (eFormat) {
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_AMR_TRANSMIT:
      case MEDIA_FORMAT_AMR_WB:
      case MEDIA_FORMAT_MP4_AMR:
      case MEDIA_FORMAT_MP4_AMR_WB:
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
      case MEDIA_FORMAT_G711_ALAW:
      case MEDIA_FORMAT_G711_ULAW:
#if defined( __I2S_INPUT_MODE_SUPPORT__ )      
         if(I2S_is_I2S_open())
            return (Media_I2S_INPUT_MODE_SR/6)*2;
         else
#endif 
         return 8000;
      default:
         return 0;
   }
   return 0;
}

kal_uint32 Media_A2V_GetRecInterruptTimeScaleFxdPnt(Media_Format eFormat, kal_uint8 bSamplingFreqIndex)
{
   switch (eFormat) {
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_AMR_TRANSMIT:
      case MEDIA_FORMAT_AMR_WB:
      case MEDIA_FORMAT_MP4_AMR:
      case MEDIA_FORMAT_MP4_AMR_WB:
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
      case MEDIA_FORMAT_G711_ALAW:
      case MEDIA_FORMAT_G711_ULAW:
#if defined( __I2S_INPUT_MODE_SUPPORT__ )      
         if(I2S_is_I2S_open())
            return (Media_I2S_INPUT_MODE_SR/6)*2*1024;
         else
#endif 
         return 8192000;

      default:
         return 0;
   }
   return 0;
}

/*
 * Fixed-point version of Media_A2V_GetAudioInterruptTimeScale.
 * The fraction part is 10 bits
 */
kal_uint32 Media_A2V_GetPlaybackInterruptTimeScaleFxdPnt(Media_Format eFormat, kal_uint8 bSamplingFreqIndex)
{
   (void)eFormat;
   
   switch( bSamplingFreqIndex ) {
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)              	
      case 0x03:
         return 8192000; /* 48000/6 */
      case 0x06:
         return 4096000; /* 24000/6 */
      case 0x09:
         return 2048000; /* 12000/6 */
      case 0x04:
         return 7526400; /* 44100/6 */
      case 0x07:
         return 3763200; /* 22050/6 */
      case 0x0a:
         return 1881600; /* 11025/6 */
      case 0x05:
         return 5461333; /* 32000/6 */
      case 0x08:
         return 2730667; /* 16000/6 */
      case 0x0b:
         return 1365333; /* 8000/6 */
      default:
         return 1365333; /* amr silence frame*/
#else
      case 0x03:
      case 0x06:
      case 0x09:
         return 8192000; /* 48000/6 */
      case 0x04:
      case 0x07:
      case 0x0a:
         return 7526400; /* 44100/6 */
      case 0x05:
      case 0x08:
      case 0x0b:
         return 5461333; /* 32000/6 */

      default:
         return 5461333; /* amr silence frame*/
#endif
   }
}

/*
 * This function returns the inherent delay time between the time DSP starts to count
 * audio interrupt and the time the first audio sample is sent to DAC.
 *
 * The return value is in unit of audio interrupt time scale.
 *
 * Refer to am.c to sync the value of DP_DEL_PCM_W, DP_MARGIN_PCM_W, DP_ASP_DEL_W, DP_ASP_DEL_M.
 */
kal_uint32 Media_A2V_GetAudioPlaybackDelay(Media_Format eFormat)
{
// move to Media_A2V_AddFirstFrameInterruptDelay()

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   return 0;
}

/*
 * This function returns the inherent delay time between the time DSP starts to count
 * audio interrupt and the time the first audio sample is received from ADC.
 *
 * The return value is in unit of audio interrupt time scale.
 *
 * Refer to am.c to sync the value of DP_DEL_PCM_R.
 */
kal_uint32 Media_A2V_GetAudioRecordDelay(Media_Format eFormat)
{
#if defined( __I2S_INPUT_MODE_SUPPORT__ )      
   if(I2S_is_I2S_open())
      return 0;
#endif 
   switch (eFormat) {
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_MP4_AMR:
      case MEDIA_FORMAT_AMR_TRANSMIT:
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_G711_ALAW:
      case MEDIA_FORMAT_G711_ULAW:
         return 0x20 + 160;
      case MEDIA_FORMAT_AMR_WB:
      case MEDIA_FORMAT_MP4_AMR_WB:
      case MEDIA_FORMAT_PCM_16K:
         return 0x20 + 160;
      default:
         ASSERT(KAL_FALSE);
   }
   return 0;
}

/*
   Get audio playback time in mili-second.
*/

//#if defined(MP4_DECODE)

Media_Status Media_A2V_Audio_GetPlayTime
(kal_uint64 *puMiliSecond, kal_uint64 uAudioSeekPointTime, kal_uint32 speed_scale, kal_uint8 bAudioSamplingFreqIndex, Media_Format eFormat)
{
   kal_uint32 uAudioInterruptCount;
   kal_uint32 uAudioInterruptTimeScale;

   if(!puMiliSecond)
      return MEDIA_FAIL;

   uAudioInterruptTimeScale = Media_A2V_GetPlaybackInterruptTimeScale( eFormat, bAudioSamplingFreqIndex );
   if(!uAudioInterruptTimeScale)
      return MEDIA_FAIL;   	
   
   uAudioInterruptCount = Media_A2V_GetInterruptCount();
   *puMiliSecond = uAudioSeekPointTime + uAudioInterruptCount * speed_scale * 10 / uAudioInterruptTimeScale;

   kal_trace(TRACE_FUNC, L1AUDIO_AVSYNC_MP4_AUDIO_GETPLAYTIME, (int)uAudioInterruptCount , (int)(uAudioSeekPointTime), (int)*puMiliSecond);
   return MEDIA_SUCCESS;
}

/*
   Get video playback time in mili-second.
*/

Media_Status Media_A2V_Video_GetPlayTime
(kal_uint64 *puMiliSecond, kal_uint32 speed_scale, kal_uint8 bAudioSamplingFreqIndex, Media_Format eFormat)
{
   kal_uint32 uCurrentInterruptCount;
   kal_uint32 uAudioInterruptTimeScale;
   kal_uint64 uPrevPlaybackTime, uDeltaTime, uScaleTime;

   if(!puMiliSecond)
      return MEDIA_FAIL;

   uAudioInterruptTimeScale = Media_A2V_GetPlaybackInterruptTimeScale( eFormat, bAudioSamplingFreqIndex );
   if(!uAudioInterruptTimeScale)
      return MEDIA_FAIL;   	
   
   uCurrentInterruptCount = Media_A2V_GetInterruptCount();
   uPrevPlaybackTime = media_a2v.uPlaybackTimeBase;

   if( uCurrentInterruptCount < media_a2v.uPrevQueryInterruptCount )
      media_a2v.uPrevQueryInterruptCount = uCurrentInterruptCount;

   uScaleTime = (uCurrentInterruptCount - media_a2v.uPrevQueryInterruptCount) * speed_scale * 10;
   uScaleTime += media_a2v.uPlaybackRemainderScaleTime;
   uDeltaTime = uScaleTime / uAudioInterruptTimeScale;
   media_a2v.uPlaybackRemainderScaleTime = uScaleTime - (uDeltaTime * uAudioInterruptTimeScale);
   
   media_a2v.uPlaybackTimeBase = uPrevPlaybackTime + uDeltaTime;
    
   *puMiliSecond = media_a2v.uPlaybackTimeBase;

   kal_trace(TRACE_FUNC, L1AUDIO_AVSYNC_MP4_VIDEO_GETPLAYTIME,(int)media_a2v.uPrevQueryInterruptCount ,(int)uCurrentInterruptCount ,(int)uPrevPlaybackTime ,(int)*puMiliSecond);
   media_a2v.uPrevQueryInterruptCount = uCurrentInterruptCount;
   return MEDIA_SUCCESS;
}
//#endif // #if defined(MP4_DECODE)

/*
   Set the playback timer base to the given time.
   The playback time will be accumulated based on the timer base.
   Playback timer should only be set when AV sync is not activated yet.
*/

void Media_A2V_SetPlaybackTimerBase
(kal_uint32 uPlaybackTimeBase, kal_bool bResetPreviousInterruptCount)
{
   kal_trace(TRACE_FUNC, L1AUDIO_AVSYNC_MP4_SETPLAYBACKTIMERBASE, (int)media_a2v.uPlaybackTimeBase, (int)uPlaybackTimeBase);
   media_a2v.uPlaybackTimeBase = uPlaybackTimeBase;
   media_a2v.uPlaybackRemainderScaleTime = 0;
   media_a2v.uRemainder = 0;
   if (bResetPreviousInterruptCount)
   {
      media_a2v.uPrevQueryInterruptCount = 0;
      Media_A2V_SetInterruptCount(0);
      if( *DP_A2V_INT_ENABLE != AVSYNC_STATE_RUNNING )
      {
         media_a2v.wDSPCount_Prev = 0; 
         *DP_A2V_INT_CNT = 0;
      }
   }
}

/***
 * Convert sampling frequency to sampling frequency index.
 * Refer to 14496-3 Subpart 4
 */
static kal_uint32 Media_A2V_ConvertFreqIndex(kal_uint32 uSamplingFreq)
{
   kal_uint32 uSamplingFreqIndex;
   
   if (uSamplingFreq>=92017) uSamplingFreqIndex = 0x0;
   else if (uSamplingFreq>=75132) uSamplingFreqIndex = 0x1;
   else if (uSamplingFreq>=55426) uSamplingFreqIndex = 0x2;
   else if (uSamplingFreq>=46009) uSamplingFreqIndex = 0x3;
   else if (uSamplingFreq>=37566) uSamplingFreqIndex = 0x4;
   else if (uSamplingFreq>=27713) uSamplingFreqIndex = 0x5;
   else if (uSamplingFreq>=23004) uSamplingFreqIndex = 0x6;
   else if (uSamplingFreq>=18783) uSamplingFreqIndex = 0x7;
   else if (uSamplingFreq>=13856) uSamplingFreqIndex = 0x8;
   else if (uSamplingFreq>=11502) uSamplingFreqIndex = 0x9;
   else if (uSamplingFreq>=9391) uSamplingFreqIndex = 0xa;
   else uSamplingFreqIndex = 0xb;
   
   return uSamplingFreqIndex;
}

void Media_A2V_SetMediaFormat(Media_Format format)
{
   media_a2v.format = format;
}

void Media_A2V_SetFreq(kal_uint32 uSamplingFreq)
{
   kal_uint32 freqIndex;
   
   freqIndex = Media_A2V_ConvertFreqIndex(uSamplingFreq);
   media_a2v.uFreqIndex = freqIndex;

   switch (freqIndex) {
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 

      case 0x03:
      	 media_a2v.uSampleUnit = 48000;
         break;
      case 0x06:
      	 media_a2v.uSampleUnit = 24000;
         break;
      case 0x09:
         media_a2v.uSampleUnit = 12000;
         break;
      case 0x04:
      	 media_a2v.uSampleUnit = 44100;
         break;
      case 0x07:
      	 media_a2v.uSampleUnit = 22050;
         break;
      case 0x0a:
         media_a2v.uSampleUnit = 11025;
         break;
      case 0x05:
      	 media_a2v.uSampleUnit = 32000;
         break;
      case 0x08:
      	 media_a2v.uSampleUnit = 16000;
         break;
      case 0x0b:
         media_a2v.uSampleUnit = 8000;
         break;
      default:
#if AMR_AWB_AUDIO_PATH_SUPPORT
         media_a2v.uSampleUnit = 32000;
         media_a2v.uFreqIndex = 0x05;
#else
         media_a2v.uSampleUnit = 48000;
         media_a2v.uFreqIndex = 0x03;
#endif
         break;

#else
      case 0x03:
      case 0x06:
      case 0x09:
         media_a2v.uSampleUnit = 480;
         break;
      case 0x04:
      case 0x07:
      case 0x0a:
         media_a2v.uSampleUnit = 441;
         break;
      case 0x05:
      case 0x08:
      case 0x0b:
         media_a2v.uSampleUnit = 320;
         break;
      default:
#if AMR_AWB_AUDIO_PATH_SUPPORT
         media_a2v.uSampleUnit = 320;
         media_a2v.uFreqIndex = 0x05;
#else
         media_a2v.uSampleUnit = 480;
         media_a2v.uFreqIndex = 0x03;
#endif
         break;
#endif
   };
}

void Media_A2V_SetSpeedScale(kal_uint32 speed_scale)
{
   media_a2v.uSpeedScale = speed_scale;
}

/*
 *   remainderSample for 0 ~ 59
 */
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
void Media_A2V_SetInterruptTime(kal_uint16 msTime)
{
   kal_uint64 totalSampleBasems, timeStamp;
   msTimes_fromV = msTime;
   totalSampleBasems = msTime*media_a2v.uSampleUnit + media_a2v.uRemainder;
   timeStamp = totalSampleBasems / 6000;
   if (timeStamp > 32767)
      timeStamp = 32767;
   media_a2v.uRemainder = totalSampleBasems - (timeStamp*6000);
   
   *DP_A2V_INT_STAMP = (kal_uint32)timeStamp;
}
#else
void Media_A2V_SetInterruptTime(kal_uint16 msTime)
{
   kal_uint32 totalSampleBase10ms, timeStamp;
   
   totalSampleBase10ms = msTime*media_a2v.uSampleUnit + media_a2v.uRemainder;
   timeStamp = totalSampleBase10ms / 60;
   if (timeStamp > 32767)
      timeStamp = 32767;
   media_a2v.uRemainder = totalSampleBase10ms - (timeStamp*60);
   
   *DP_A2V_INT_STAMP = timeStamp;
}
#endif

void Media_A2V_AddFirstFrameInterruptDelay(kal_uint16 asp_type)
{
   kal_uint32 delay_cnt=0, timeStamp=0;

#if VERIFY_AVSYNC
   return;
#endif

   switch( asp_type ){
      case ASP_TYPE_AMR:
      case ASP_TYPE_AWBDEC:
         delay_cnt = 0x20 + 0x96;
         break;
      case ASP_TYPE_AAC:
      case ASP_TYPE_AAC_SBR_ARM:
         delay_cnt = 0x20 + (2040/2)/6;
         break;
      default:
         return;
   }
   timeStamp = *DP_A2V_INT_STAMP + delay_cnt;
   if (timeStamp > 32767)
      timeStamp = 32767;
   *DP_A2V_INT_STAMP = (kal_uint16)timeStamp;
}

Media_Status Media_A2V_Audio_GetPlayTime_S( kal_uint64 *puMiliSecond, kal_uint64 uAudioSeekPointTime )
{
   return Media_A2V_Audio_GetPlayTime(puMiliSecond, uAudioSeekPointTime, media_a2v.uSpeedScale, media_a2v.uFreqIndex, media_a2v.format);
}

Media_Status Media_A2V_Video_GetPlayTime_S(kal_uint64 *puMiliSecond)
{
   return Media_A2V_Video_GetPlayTime(puMiliSecond, media_a2v.uSpeedScale, media_a2v.uFreqIndex, media_a2v.format);
}

void Media_A2V_REMOVE_MEDIA_END_CALLBACK(Media_Status (*CloseDevice)(MHdl *data))
{
//dummy function
}

void Media_A2V_NOTIFY_MEDIA_END(void (*CloseDevice)(void *data), void *data)
{
      CloseDevice(data);
}


/***
 * Verify the correctness of the Media_A2V series APIs.
 */

#if defined(UNIT_TEST_ON_WIN32) && defined(UNIT_TEST_MEDIA_AVSYNC)
void callback(void)
{
   printf("callbacked\n");
}

int main(int argc, char** argv)
{

   media_a2v.uInterruptCount = 0;
   media_a2v.wDSPCount_Prev = 0;
   *DP_A2V_INT_CNT = 0;
   ASSERT(Media_A2V_GetInterruptCount()==0);

   *DP_A2V_INT_CNT = 1;
   ASSERT(Media_A2V_GetInterruptCount()==1);

   *DP_A2V_INT_CNT = 0xFFFF;
   ASSERT(Media_A2V_GetInterruptCount()==0xFFFF);

   *DP_A2V_INT_CNT = 0x0;
   ASSERT(Media_A2V_GetInterruptCount()==0x10000);

   *DP_A2V_INT_CNT = 0x6000;
   ASSERT(Media_A2V_GetInterruptCount()==0x16000);

   *DP_A2V_INT_CNT = 0x8000;
   media_a2v_Hisr();
   *DP_A2V_INT_CNT = 0xA000;
   media_a2v_Hisr();
   *DP_A2V_INT_CNT = 0x2000;
   ASSERT(Media_A2V_GetInterruptCount()==0x22000);

   Media_A2V_HookInterrupt(callback);
   media_a2v_Hisr();

   return 0;
}
#endif

/***
 * Verify the correctness of DSP.
 */

#if VERIFY_AVSYNC

#define BUF_SIZE 16384
kal_uint32 uTick[BUF_SIZE];
kal_uint32 uOSTick[BUF_SIZE];
kal_uint32 uCount[BUF_SIZE];
kal_uint32 uAudioFrameCount[BUF_SIZE];
kal_uint32 uVideoFrameCount[BUF_SIZE];
volatile kal_uint32 uIndex;

kal_uint32 uTickPlay[BUF_SIZE];
kal_uint32 uINTCNTPlay[BUF_SIZE];
kal_uint32 uIndexTickPlay;

kal_uint32 uTickRecord[BUF_SIZE];
kal_uint32 uINTCNTRecord[BUF_SIZE];
kal_uint32 uIndexTickRecord;

kal_uint32 uTimeStamp;

//#include "tc_defs.h"
//extern UNSIGNED TMD_System_Clock;

kal_uint32 visual_get_current_time(void)
{
#if (defined(MT6235) || defined(MT6235B) || defined(MT6253) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H) )
	return ( (*(volatile kal_uint32 *)(0x80200230)));
#elif defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00)
  return ( (*(volatile kal_uint32 *)(0x84060230)));
#else
	return 0;
#endif
}

/**
 * When verification, this function is to be inserted in mediaHisr of media.c
   at each audio type before playback hisr.
 */
void ut_avsync_play_hisr(void)
{
   if (uIndexTickPlay < BUF_SIZE) {
      kal_get_time(&uTickPlay[uIndexTickPlay]);
      uINTCNTPlay[uIndexTickPlay] = Media_A2V_GetInterruptCount();
      uIndexTickPlay++;
   }
}

/**
 * When verification, this function is to be inserted in mediaHisr of media.c
   at each audio type before record hisr.
 */
void ut_avsync_record_hisr(void)
{
   if (uIndexTickRecord < BUF_SIZE) {
      kal_get_time(&uTickRecord[uIndexTickRecord]);
      uINTCNTRecord[uIndexTickRecord] = Media_A2V_GetInterruptCount();
      uIndexTickRecord++;
   }
}

/**
 * When verification, this function is the called back function for
 * servicing A/V sync interupts.
 */
static void ut_avsync_lisr(void)
{
   if (uIndex < BUF_SIZE) {
      static kal_uint32 uPrevTick;
      kal_uint32 uCurrentTick = visual_get_current_time();
      uTick[uIndex] = uCurrentTick;
      kal_get_time(&uOSTick[uIndex]);
      uCount[uIndex] = Media_A2V_GetInterruptCount();
      uAudioFrameCount[uIndex] = Media_A2V_GetAudioFrameCount();
      uVideoFrameCount[uIndex] = Media_A2V_GetVideoFrameCount();
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
      uIndex++;
      uPrevTick = uCurrentTick;
   }
}

/**
 * For verifying A/V Sync when playback
 */
void ut_a2v_play_dsp_start(void) {
   uIndex = 0;
   uIndexTickPlay = 0;
   kal_mem_set(uTick, 0, BUF_SIZE * sizeof(kal_uint32));
   kal_mem_set(uCount, 0, BUF_SIZE * sizeof(kal_uint32));
   kal_mem_set(uAudioFrameCount, 0, BUF_SIZE * sizeof(kal_uint32));
   kal_mem_set(uVideoFrameCount, 0, BUF_SIZE * sizeof(kal_uint32));
   kal_mem_set(uTickPlay, 0, BUF_SIZE * sizeof(kal_uint32));
   kal_mem_set(uINTCNTPlay, 0, BUF_SIZE * sizeof(kal_uint32));

   Media_A2V_HookInterrupt(ut_avsync_lisr);
   Media_A2V_EnableInterrupt(KAL_TRUE, 0);
   uTimeStamp = 110;
   /*
    * 240: 30ms for AMR
    * 220: 29.93 ms for 44100Hz audio
    */
   Media_A2V_SetTimeStamp(uTimeStamp);
}

/**
 * For verifying A/V Sync when recording
 */
void ut_a2v_record_dsp_start()
{
   uIndexTickRecord = 0;
   kal_mem_set(uTickRecord, 0, BUF_SIZE * sizeof(kal_uint32));
   kal_mem_set(uINTCNTRecord, 0, BUF_SIZE * sizeof(kal_uint32));

   Media_A2V_HookInterrupt((void*)NULL);
   Media_A2V_EnableInterrupt(KAL_TRUE, 0);
   Media_A2V_SetTimeStamp(0xFFFF);
}

/**
 * For verifying A/V Sync
 */
void ut_a2v_dsp_stop(void) {
   kal_uint32 uStopTime;
   Media_A2V_EnableInterrupt(KAL_FALSE, 0);
   kal_get_time(&uStopTime);
   /* after stop time, ut_avsync_lisr should not be triggered */
}

#endif /* VERIFY_AVSYNC */

#endif 


