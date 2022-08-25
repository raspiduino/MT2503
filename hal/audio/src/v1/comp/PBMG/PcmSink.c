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
 *   pcmsink.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   The basic functions of PCM sink component.
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
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_public_api.h"
#include "kal_trace.h"
#include "l1audio.h"
#include "audio_enum.h"
#include "audio_def.h"
#include "ddload.h"
#include "MedAdapt.h"
#include "AudCom.h"
#include "media.h"
#include "am.h"
#include "afe.h"
#include "l1sp_trc.h"
#include "OMX_Types.h"
#include "OMX_Core.h"
#include "OMX_Index.h"
#include "AudComUtil.h"
#include "pcmsink.h"
#include "speech_def.h"
#include "PostProcess.h"
#include "audlp2_drv.h"
#include "audio_sherif_bit_def.h"
#include "dcl.h"
#if defined(__KARAOKE_SUPPORT__)
#include "karaoke_drv.h"
#endif

#pragma arm section code="SECONDARY_ROCODE"

static struct  {
   MHdl            *pMedPlayHandle;
   AudComHdlInt    *pIntCompHandle;
   kal_uint32      uPlayedSamples;
   kal_uint32      uPlayedTime;
   kal_uint16      uDspBufferSize;  //word
   kal_uint16      uDspBufferBase; 
   kal_uint16      uDspBufferEnd;  //word
   kal_uint16      uSampleRate;
   kal_uint8       uChannelNumber;
   kal_bool        fIsTimeUp;
   kal_bool        fIsLowPower;
   kal_bool        fIsAllowLowPower;
   kal_bool        fIsVoicePath;
   kal_bool        fIsDSPdecode;
   Media_Format    uFormat;

   kal_uint16      uDspSoundWritePos;
   SOUND_STATE     uSoundState;
} PcmSink;

static struct  {
   kal_int32       *pSoundBuffer;
   kal_uint32      uGPT;
   kal_uint32      uDepopGPT;
   kal_uint32      uMuteFunction;
   kal_uint16      uAudId;
   kal_uint16      uSoundFrameSamples;
   kal_uint16      uDspGain;
   kal_uint16      uBtDeviceGain;
   kal_uint16      uGainStep;
   PCMSINK_STATE   uState;
   kal_uint8       uBluetoothFunction;
   kal_uint8       uPcmFunction;
   kal_bool        fBtDeviceMute;   
   kal_uint8       uDebugCounter;
} PcmSinkStatic;

#ifdef __HQA_AUDIO__

static kal_uint8 uWavOutputDevice = L1SP_BUFFER_0;
void WAV_HQASetSpOutputDevice( kal_uint8 device )
{
    uWavOutputDevice = device;            
}

#endif

#if defined (__AUDIO_ULTRA_SLIM__)
#define __PCMSINK_DEBUG__ 0
#else
#define __PCMSINK_DEBUG__ 1
#endif

#if defined(__VIBRATION_SPEAKER_SUPPORT__)
kal_int32 Vibr_Filter_Stack_Auddata[2][8]={0};
kal_int32 Vibr_Filter_Stack_Snddata[2][8]={0};
#endif

#if defined(BT_SERIAL_PLAYBACK_AUDIO_SYNC)

#define BT_CLK_MASK         0x0FFFFFFF
#define BT_CLK_UPPER_BOUND  0x10000000  // about 23.3 hours
#define BT_CLK_NORM_DIFF(t_targ, t_curr) (t_targ - t_curr)
#define BT_CLK_WRAP_DIFF(t_targ, t_curr) (BT_CLK_UPPER_BOUND + t_targ - t_curr)
#define BT_CLK_MAX_DIFF     0x001D4C00  // 10 minutes
#define BT_CLK_SLEEP_TICK   0x0000001E  // 4.6875 ms (about 2 tick for kal_sleep_task)

#define BT_CLK_BTD1_DELAY   1280    // 400 ms
#define BT_CLK_BTD2_DELAY   1280    // 400 ms

extern kal_uint32 BTIF_Get_BT_HW_Native_Clk(void);
kal_bool b_apply_bt_serial_delay = KAL_FALSE;
kal_uint32 bt_serial_start_time = 0xFFFFFFFF;
kal_uint32 bt_serial_offset     = 0xFFFFFFFF;
kal_uint32 bt_serial_channel_type = PLAYBACK_CH_NORMAL;
kal_uint32 bt_serial_silence_cnt = 0;

static kal_int32 pcmsink_Calculate_BT_Clock_Diff (kal_int32 clk_curr, kal_int32 clk_targ)
{
    kal_int32 norm_diff = BT_CLK_NORM_DIFF(clk_targ, clk_curr);
    kal_int32 wrap_diff = BT_CLK_WRAP_DIFF(clk_targ, clk_curr);
    kal_int32 diff;
    
    if (norm_diff > 0 && norm_diff < BT_CLK_MAX_DIFF)
    {
        diff = norm_diff;
    }
    else if (wrap_diff > 0 && wrap_diff < BT_CLK_MAX_DIFF)
    {
        diff = wrap_diff;
    }
    else
    {
        diff = 0;
    }
    
    return diff;
}

void Media_Set_A2DP_Stream_Start_Time(A2DP_Stream_Start_Param *p_param)
{
    b_apply_bt_serial_delay = KAL_TRUE;
    bt_serial_channel_type = p_param->channel_type;
    bt_serial_start_time = p_param->start_time;
    bt_serial_offset = p_param->offset;
    bt_serial_silence_cnt = 0;
    
    return;
}

kal_uint32 Media_Get_A2DP_Reserved_Bytes(void)
{   // 2 + 4 = sync word + start time
    return 6;
}

kal_uint32 Media_Get_A2DP_Delay_Timing(A2DP_Stream_Device device)
{
    kal_uint32 delay;
    
    if (device == A2DP_STREAM_DEVICE_BTD1)
    {
        delay = BT_CLK_BTD1_DELAY;
    }
    else // if (device == A2DP_STREAM_DEVICE_BTD2)
    {
        delay = BT_CLK_BTD2_DELAY;
    }
    
    return delay;
}

kal_uint32 Media_Add_A2DP_Next_Device_Start_Time(kal_uint8 *p_in, kal_uint8 *p_out, kal_uint32 payload_len, kal_uint32 start_time)
{
    kal_uint32 result = 0;
    
    if (payload_len >= 6)
    {
        *p_out++ = 0x33;
        *p_out++ = 0x77;
        *p_out++ = (kal_uint8)((start_time >> 24) & 0x000000FF);
        *p_out++ = (kal_uint8)((start_time >> 16) & 0x000000FF);
        *p_out++ = (kal_uint8)((start_time >>  8) & 0x000000FF);
        *p_out++ = (kal_uint8)( start_time        & 0x000000FF);
        payload_len -= 6;
        while(payload_len-- > 0)
        {
            *p_out++ = *p_in++;
        }
    }
    else
    {
        result = 1;
    }
    
    return result;
}

kal_uint32 Media_Check_A2DP_Stream(kal_uint8 *p_payload, kal_uint32 payload_len)
{
    kal_uint32 start_time = 0xFFFFFFFF;
    
    if (payload_len >= 6)
    {
        kal_uint8 header[6];
        kal_uint32 payload_idx;
        
        for (payload_idx = 0; payload_idx < 6; payload_idx++)
        {
            header[payload_idx] = *p_payload++;
        }
        
        if (header[0] == 0x33 && header[1] == 0x77)
        {
            kal_uint32 byte_0 = ((kal_uint32)header[2] << 24) & 0xFF000000;
            kal_uint32 byte_1 = ((kal_uint32)header[3] << 16) & 0x00FF0000;
            kal_uint32 byte_2 = ((kal_uint32)header[4] <<  8) & 0x0000FF00;
            kal_uint32 byte_3 =  (kal_uint32)header[5]        & 0x000000FF;
            start_time = byte_0 | byte_1 | byte_2 | byte_3;
        }
    }
    
    return start_time;
}
#else   // defined(BT_SERIAL_PLAYBACK_AUDIO_SYNC)
void Media_Set_A2DP_Stream_Start_Time(A2DP_Stream_Start_Param *p_param)
{
    return;
}

kal_uint32 Media_Get_A2DP_Reserved_Bytes(void)
{
    return 0;
}

kal_uint32 Media_Get_A2DP_Delay_Timing(A2DP_Stream_Device device)
{
    return 0;
}

kal_uint32 Media_Add_A2DP_Next_Device_Start_Time(kal_uint8 *p_in, kal_uint8 *p_out, kal_uint32 payload_len, kal_uint32 start_time)
{
    return 0;
}

kal_uint32 Media_Check_A2DP_Stream(kal_uint8 *p_payload, kal_uint32 payload_len)
{
    return 0;
}
#endif  // defined(BT_SERIAL_PLAYBACK_AUDIO_SYNC)

static void pcmsink_PrintGainForDebug()
{
#if __PCMSINK_DEBUG__	
   PcmSinkStatic.uDebugCounter++;
   PcmSinkStatic.uDebugCounter &= 0xF;
   if(PcmSinkStatic.uDebugCounter == 0)
   {
      kal_uint16 uCurGain, uTarGain, uGainStep;
      kal_bool fIsMediaMute = AFE_IsSpeakerMuted(L1SP_AUDIO);
      uCurGain = *DSP_PCM_CGAIN;
      uTarGain = *DSP_PCM_DGAIN;
      uGainStep = *DSP_PCM_GAINSTEP;
      kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_HISR_DEBUG1, DSP_PCM_CGAIN, uCurGain, DSP_PCM_DGAIN, uTarGain, DSP_PCM_GAINSTEP, uGainStep);
      kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_HISR_DEBUG2, fIsMediaMute, PcmSinkStatic.uMuteFunction, PcmSinkStatic.fBtDeviceMute, PcmSinkStatic.uBtDeviceGain);
   }
#endif   
}

static void pcmsink_ApplyGainOn16Bit(kal_int16 *pSample, kal_uint16 uGain, kal_uint32 uSampleCount)
{
   kal_int32 I, iTempSample;
   if (uGain == 0x7FFF) 
   {
      return;
   }
   for(I=uSampleCount-1; I>=0; I--) 
   {
      iTempSample = ((kal_int32)*pSample * uGain)>>15;
      *pSample++ = (kal_int16) iTempSample;
   }
}

static kal_uint32 pcmsink_GetFreqIndex(kal_uint32 uSampleRate)
{
   kal_uint32 uFreqIndex = 0;
   switch (uSampleRate) 
   {
      case 8000:
         uFreqIndex = 0;
         break;
      case 11025:
         uFreqIndex = 1;
         break;
      case 12000:
         uFreqIndex = 2;
         break;
      case 16000:
         uFreqIndex = 3;
         break;
      case 22050:
         uFreqIndex = 4;
         break;
      case 24000:
         uFreqIndex = 5;
         break;
      case 32000:
         uFreqIndex = 6;
         break;
      case 44100:
         uFreqIndex = 7;
         break;
      case 48000:
         uFreqIndex = 8;
         break;
   }
   return uFreqIndex;
}

void PcmSink_UpdateGain()
{
   kal_bool fAfeMute = KAL_FALSE;
   kal_uint16 aud_id;
   //fAfeMute = AFE_IsSpeakerMuted(L1SP_AUDIO);
   if(!L1Audio_IsInitiated())
   {
   	 return;
   }   
   if(!kal_if_lisr())
   {
      kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_UPDATE_GAIN, PcmSinkStatic.uMuteFunction, fAfeMute, PcmSinkStatic.uDspGain);
   }
   
   if (!kal_if_hisr() && !kal_if_lisr())
   {
   	  aud_id = L1Audio_GetAudioID();
   	  L1Audio_SetFlag( aud_id );		// set flag due to PcmSink_UpdateGain would set dsp sheriff	
   }
   
   *DSP_PCM_GAINSTEP = PcmSinkStatic.uGainStep;
   if(PcmSinkStatic.uMuteFunction || fAfeMute)
   {
      *DSP_PCM_DGAIN = 0;
   }
   else
   {
      *DSP_PCM_DGAIN = PcmSinkStatic.uDspGain;
   }
   
   if (!kal_if_hisr() && !kal_if_lisr())
   {
   	  L1Audio_ClearFlag( aud_id );
      L1Audio_FreeAudioID( aud_id );
   }
}

void PcmSink_SetGainStep(kal_uint32 uSampleRate)
{
   kal_uint32 uGainStep = (32767*1000*6) / (uSampleRate*20);
   PcmSinkStatic.uGainStep = (kal_uint16)uGainStep + 1;
}

kal_uint16 PcmSink_GetGain( kal_uint16 uGain )
{
   return PcmSinkStatic.uDspGain;
}

void PcmSink_InitDigitalGain()
{
   PcmSink_SetGainStep(48000);
   *DSP_PCM_DGAIN = PcmSinkStatic.uDspGain;
}

void PcmSink_SetGain( kal_uint16 uGain )
{
   if(!kal_if_lisr())
   {
      kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_SET_GAIN, uGain, PcmSinkStatic.uDspGain);
   }
   PcmSinkStatic.uDspGain = uGain;
   PcmSink_UpdateGain();
}

void PcmSink_Mute(kal_bool fMute, kal_uint32 uFunction)
{
   if(!kal_if_lisr())
   {
      kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_MUTE, fMute, uFunction, PcmSinkStatic.uMuteFunction);
   }
   if(fMute)
   {
      PcmSinkStatic.uMuteFunction |= uFunction;
   }
   else
   {
      PcmSinkStatic.uMuteFunction &= ~uFunction;
   }
   PcmSink_UpdateGain();
}
void PcmSink_DepopUnMute( void *data )
{
   if(PcmSinkStatic.uDepopGPT)
   {
      DclSGPT_Control(PcmSinkStatic.uDepopGPT ,SGPT_CMD_STOP, 0);
   }
   PcmSink_Mute(KAL_FALSE, PCMSINK_MUTE_DEPOP);
}
void PcmSink_DepopMute(kal_uint32 uMsec)
{
   SGPT_CTRL_START_T start;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_DEPOP_MUTE, uMsec, PcmSinkStatic.uMuteFunction, PcmSinkStatic.uState);
   if(PcmSinkStatic.uDepopGPT)
   {
      DclSGPT_Control(PcmSinkStatic.uDepopGPT ,SGPT_CMD_STOP, 0);
   }
   PcmSink_Mute(KAL_TRUE, PCMSINK_MUTE_DEPOP);
   if(PcmSinkStatic.uState != PCMSINK_STATE_IDLE)
   {
      kal_sleep_task(2);
   }
   if(PcmSinkStatic.uDepopGPT == 0)
   {
      PcmSinkStatic.uDepopGPT = DclSGPT_Open( DCL_GPT_CB ,0 );
   }
   start.u2Tick = (uMsec / 10);
   start.pfCallback = PcmSink_DepopUnMute;
   start.vPara = NULL;
   DclSGPT_Control( PcmSinkStatic.uDepopGPT, SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
}

kal_bool PcmSink_IsSoundRuning()
{
   if(PcmSinkStatic.uPcmFunction & PCM_SOUND_FUNCTIONS || PcmSinkStatic.uBluetoothFunction)
   {
      return KAL_TRUE;
   }
   return KAL_FALSE;
}

kal_bool PcmSink_IsMixerRuning()
{
   if(PcmSinkStatic.uPcmFunction & PCM_FUNC_MIXER)
   {
      return KAL_TRUE;
   }
   return KAL_FALSE;
}

kal_bool PcmSink_IsAudioRuning()
{
   if(PcmSinkStatic.uPcmFunction & PCM_FUNC_AUDIO)
   {
      return KAL_TRUE;
   }
   return KAL_FALSE;
}

kal_bool PcmSink_IsDtmfRuning()
{
   if(PcmSinkStatic.uPcmFunction & PCM_DTMF_FUNCTIONS)
   {
      return KAL_TRUE;
   }
   return KAL_FALSE;
}

kal_bool PcmSink_IsToneRuning()
{
   if(PcmSinkStatic.uPcmFunction & PCM_FUNC_TONE)
   {
      return KAL_TRUE;
   }
   return KAL_FALSE;
}

kal_bool PcmSink_IsKeytoneRuning()
{
   if(PcmSinkStatic.uPcmFunction & PCM_FUNC_KEYTONE)
   {
      return KAL_TRUE;
   }
   return KAL_FALSE;
}

kal_bool PcmSink_IsFlushed()
{
	if(PcmSinkStatic.uState == PCMSINK_STATE_FLUSHED)
	{
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

static void pcmsink_SetInterruptSample( kal_uint16 uSample )
{
   kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_SET_INTERTTUPT, uSample);
   *DP_AUDIO_DEL_CNTR_THRESHOLD = uSample;
}

static void pcmsink_SetInterruptTime( kal_uint32 uMSec )
{
   kal_uint32 uSample;
   uSample = (kal_uint32)PcmSink.uSampleRate * PcmSink.uChannelNumber * uMSec / 1000;
   pcmsink_SetInterruptSample((kal_uint16) uSample );
}

static void pcmsink_UpdateTime(kal_uint32 uConsumeSample)
{
   if(uConsumeSample)
   {
      PcmSink.uPlayedSamples += uConsumeSample;
      PcmSink.uPlayedTime = (kal_uint32)((kal_uint64)PcmSink.uPlayedSamples * 1000 / ((kal_uint32)PcmSink.uSampleRate * PcmSink.uChannelNumber));
   }
   if(PcmSink.pMedPlayHandle)
   {
      PcmSink.pMedPlayHandle->current_time = PcmSink.pMedPlayHandle->start_time + PcmSink.uPlayedTime;
   }
}

void pcmsink_ReadFromDSP_16to32(kal_int32 *pDst, volatile kal_int16 *pSrc, const kal_uint32 uLength)
{
   kal_int32 I;
   for( I = uLength-1; I >= 0; I-- )   
   {
       *pDst++ = *pSrc++;
   }
}

static void pcmsink_DspGetWriteBuffer(kal_uint16 *uWrite, kal_uint32 *uLen)
{
   kal_uint32 uCurrRead, uCurrWrite, uDspWriteLen;
   uCurrRead  = (kal_uint32)*DSP_PCM_R;
   uCurrWrite = (kal_uint32)*DSP_PCM_W;
   if(PcmSink.fIsVoicePath)
   {
      uCurrRead += PcmSink.uDspBufferBase;
      uCurrWrite += PcmSink.uDspBufferBase;
   }
   if(uCurrRead > uCurrWrite)
   {
      uDspWriteLen = uCurrRead - uCurrWrite - 1;
   }
   else
   {
      uDspWriteLen = PcmSink.uDspBufferBase + PcmSink.uDspBufferSize - uCurrWrite;
      if(uCurrRead == PcmSink.uDspBufferBase)
      {
         uDspWriteLen--;
      }
   }
   *uLen = uDspWriteLen & ~0x1;
   *uWrite = (kal_uint16)uCurrWrite;
   kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_DSP_WRITE_BUF, uCurrRead, uCurrWrite, *uLen);
}

static kal_uint32 pcmsink_DspGetDataCount()
{
   kal_uint32 uCurrRead, uCurrWrite, uDataCount;
   uCurrRead  = (kal_uint32)*DSP_PCM_R;
   uCurrWrite = (kal_uint32)*DSP_PCM_W;
   if(PcmSink.fIsVoicePath)
   {
      uCurrRead += PcmSink.uDspBufferBase;
      uCurrWrite += PcmSink.uDspBufferBase;
   }
   if(uCurrWrite>=uCurrRead)
   {
      uDataCount = uCurrWrite - uCurrRead;
   }
   else
   {
      uDataCount = PcmSink.uDspBufferSize + uCurrWrite - uCurrRead;
   }
   kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_DSP_DATA_COUNT, uCurrRead, uCurrWrite, uDataCount, PcmSink.uDspSoundWritePos);
   return uDataCount;
}

static void pcmsink_DspWriteDataDone(kal_uint32 uLen)
{
   kal_uint16 uCurrWrite = *DSP_PCM_W;
   if(PcmSink.fIsVoicePath)
   {
      uCurrWrite += PcmSink.uDspBufferBase;
   }
   uCurrWrite += uLen;
   if(uCurrWrite >= PcmSink.uDspBufferBase + PcmSink.uDspBufferSize)
   {
      uCurrWrite = PcmSink.uDspBufferBase;
   }
   if(PcmSink.fIsVoicePath)
   {
      uCurrWrite -= PcmSink.uDspBufferBase;
   }
   *DSP_PCM_W = uCurrWrite;
   kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_DSP_WRITE_DONE, uCurrWrite, uLen);
}

void pcmsink_WriteToDSP_32to16(volatile kal_int16 *pDst16, kal_int32 *pSrc32, kal_int16 *pSrc16, const kal_uint32 uLength, const kal_bool fWriteZeroToDsp)
{
   kal_int32 I, iSample;
   if(fWriteZeroToDsp)
   {
      for( I = uLength-1; I >= 0; I-- )  
      {
         iSample = *pSrc32++;
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
      for( I = uLength-1; I >= 0; I-- )  
      {
         iSample = *pSrc32++;
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

static void pcmsink_DspSound_AddFromTone(kal_uint32 uSpace)
{
   kal_uint32 uToneCnt, I;
   kal_int16 *pTone;
   kal_int32 *pDst = PcmSinkStatic.pSoundBuffer;
   kal_uint32 uRemains = uSpace>>1;
   while(uRemains)
   {
      DTMF_MCU_GetReadBuffer(&pTone, &uToneCnt);
      if(uToneCnt > uRemains)
      {
         uToneCnt = uRemains;
      }
#if defined(__ENABLE_TONE_MIX_AUDIO__) // have no this option current
      {
         kal_int32 iToneSample;
         for(I=0;I<uToneCnt;I++)
         {
            iToneSample = (kal_int32)*pTone++;
            *pDst = *pDst + iToneSample; 
            pDst++;
            *pDst = *pDst + iToneSample; 
            pDst++;
         }
      }
#else
      for(I=0;I<uToneCnt;I++)
      {
         *pDst++ = (kal_int32)*pTone;
         *pDst++ = (kal_int32)*pTone++;
      }
#endif
      DTMF_MCU_ReadDataDone(uToneCnt);
      uRemains -= uToneCnt;
   }
}

static void pcmsink_DspSound_AddFromMixer(const kal_uint32 uSpace)
{
#if defined(__AUDIO_MIXER_SUPPORT__) 
   PcmMixer_MixSample(PcmSinkStatic.pSoundBuffer, uSpace);
#endif
}

static void pcmsink_DspSound_AddFromVoice(kal_int16 *src ,kal_uint32 uSpace)
{
#if defined(__KARAOKE_SUPPORT__)
   Karaoke_Play_MixSample(src ,uSpace);
#endif 
}

static void pcmsink_DspSound_GetWriteBuffer(kal_uint16 *uWrite, kal_uint32 *uLen)
{
   kal_uint32 uCurrWrite;
   uCurrWrite = (kal_uint32)*DSP_PCM_W;
   if(uCurrWrite >= PcmSink.uDspSoundWritePos)
   {
      *uLen = uCurrWrite - PcmSink.uDspSoundWritePos;
   }
   else
   {
      *uLen = PcmSink.uDspBufferEnd - PcmSink.uDspSoundWritePos;
   }
   *uWrite = PcmSink.uDspSoundWritePos;
}

static void pcmsink_DspSound_WriteDataDone(const kal_uint32 uLen)
{
   kal_uint16 uCurrWrite = PcmSink.uDspSoundWritePos + uLen;
   ASSERT(uCurrWrite <= PcmSink.uDspBufferEnd);
   if(uCurrWrite == PcmSink.uDspBufferEnd)
   {
      uCurrWrite = PcmSink.uDspBufferBase;
   }
   PcmSink.uDspSoundWritePos = uCurrWrite;
}

static kal_uint32 pcmsink_DspSound_GetFreeSpace()
{
   kal_uint32 uCurrWrite, uSpace;
   uCurrWrite = (kal_uint32)*DSP_PCM_W;
   if(uCurrWrite >= PcmSink.uDspSoundWritePos)
   {
      uSpace = uCurrWrite - PcmSink.uDspSoundWritePos;
   }
   else
   {
      uSpace = uCurrWrite + PcmSink.uDspBufferSize - PcmSink.uDspSoundWritePos;
   }
   return uSpace;
}

static kal_uint32 pcmsink_DspSound_GetCurrentSoundData()
{
   kal_uint32 uData, uCurrRead;
   uCurrRead = (kal_uint32)*DSP_PCM_R;
   if(uCurrRead < PcmSink.uDspSoundWritePos)
   {
      uData = PcmSink.uDspSoundWritePos - uCurrRead;
   }
   else
   {
      uData = PcmSink.uDspBufferSize + PcmSink.uDspSoundWritePos - uCurrRead;
   }
   return uData;
}

static void pcmsink_DspSound_GetPcmFromDSP(const kal_uint32 uDstLen)
{
   kal_uint32 uSrcLen, uCopiedLen = 0;
   kal_uint16 uDspReadPos;
   kal_int32 *pDst;
   volatile uint16 *pIdmaPtr;
   pDst = PcmSinkStatic.pSoundBuffer;
   pcmsink_DspSound_GetWriteBuffer(&uDspReadPos, &uSrcLen); //same pos as write
   pIdmaPtr = DSP_DM_ADDR(PCM_PLAYBACK_DSP_PAGE_NUM, uDspReadPos);
   if(uSrcLen > uDstLen - uCopiedLen)
   {
      uSrcLen = uDstLen - uCopiedLen;
   }
   pcmsink_ReadFromDSP_16to32(pDst, pIdmaPtr, uSrcLen);
   pDst+=uSrcLen;
   uCopiedLen += uSrcLen;
   if(uCopiedLen != uDstLen)
   {
      pIdmaPtr = DSP_DM_ADDR(PCM_PLAYBACK_DSP_PAGE_NUM, PcmSink.uDspBufferBase);
      uSrcLen = uDstLen - uCopiedLen;
      pcmsink_ReadFromDSP_16to32(pDst, pIdmaPtr, uSrcLen);
   }

}

static void pcmsink_DspSound_PutPcmToDSP(const kal_uint32 uSrcLen, const kal_bool fWriteZeroToDsp)
{
   kal_uint32 uDspLen, uCopiedLen = 0;
   kal_uint16 uDspWritePos;
   kal_int32 *pSrc32;
   kal_int16 *pSrc16;
   volatile uint16 *pIdmaPtr;
   pSrc32 = PcmSinkStatic.pSoundBuffer;
   pSrc16 = (kal_int16*)PcmSinkStatic.pSoundBuffer;
   while(uCopiedLen != uSrcLen)
   {
      pcmsink_DspSound_GetWriteBuffer(&uDspWritePos, &uDspLen);
      pIdmaPtr = DSP_DM_ADDR(PCM_PLAYBACK_DSP_PAGE_NUM, uDspWritePos);
      if(uDspLen > uSrcLen - uCopiedLen)
      {
         uDspLen = uSrcLen - uCopiedLen;
      }
      pcmsink_WriteToDSP_32to16(pIdmaPtr, pSrc32, pSrc16, uDspLen, fWriteZeroToDsp);
      pcmsink_DspSound_WriteDataDone(uDspLen);
      pSrc32+=uDspLen;
      pSrc16+=uDspLen;
      uCopiedLen += uDspLen;
   }
}


static kal_uint32 pcmsink_Hisr_SoundData()
{
   kal_int32 fWriteZeroToDsp = KAL_FALSE;
   kal_uint32 uToneDataCount=0, uMixerDataCount=0, uSpace=0, uCurrentAudioData=0, uNextHisrSamples = 0, uDspSpace=0, uValidAudioData = 0, uDspData = 0;
   if(PcmSink.fIsDSPdecode)
   {
      uDspSpace = uSpace = PcmRut_DspGetFreeSpace();
      ASSERT(uSpace <= PcmSinkStatic.uSoundFrameSamples);
   }
   else
   {
      uCurrentAudioData = pcmsink_DspGetDataCount();
      uNextHisrSamples = PCMSINK_MIN_HISR_SAMPLES;
      if(uCurrentAudioData < PcmSinkStatic.uSoundFrameSamples) //underflow
      {  
         return uNextHisrSamples;
      }
      else if(uCurrentAudioData > (PcmSinkStatic.uSoundFrameSamples<<1))
      {
         uNextHisrSamples = PcmSinkStatic.uSoundFrameSamples;
      }
      if(PcmSink.uDspSoundWritePos == 0)
      {  //first time init
         PcmSink.uDspSoundWritePos = *DSP_PCM_R + PcmSinkStatic.uSoundFrameSamples;
         if(PcmSink.uDspSoundWritePos > PcmSink.uDspBufferEnd )
         {
            PcmSink.uDspSoundWritePos -= PcmSink.uDspBufferSize; 
         }
      }
      else if(PcmSinkStatic.uPcmFunction & PCM_SOUND_FUNCTIONS)
      {
         uDspData = pcmsink_DspSound_GetCurrentSoundData();
         if( uDspData * 500 > PCM_SOUND_FILLDATA_THRESHOLD * PcmSink.uSampleRate )
         {
            return 0;
         }
      }
      uDspSpace = uSpace  = pcmsink_DspSound_GetFreeSpace();
      if(uSpace > PcmSinkStatic.uSoundFrameSamples)
      {
         uSpace = PcmSinkStatic.uSoundFrameSamples;
      }
   }
   uValidAudioData = uSpace;
#if defined(__AUDIO_MIXER_SUPPORT__) 
   if(PcmSinkStatic.uPcmFunction & PCM_FUNC_MIXER)
   {
      uMixerDataCount = PcmMixer_GetDataCount();
      if(uSpace > uMixerDataCount)
      {
         uSpace = uMixerDataCount;
      }
   }
#endif
   if(PcmSinkStatic.uPcmFunction & PCM_DTMF_FUNCTIONS)
   {
      uToneDataCount = DTMF_MCU_GetDataCount();
      if(uSpace > uToneDataCount << 1)
      {  //mono2stereo
         uSpace = uToneDataCount << 1;
      }
   }
   kal_dev_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_HISR_SOUND, uDspSpace, uToneDataCount << 1, uMixerDataCount);
   //SLA_CustomLogging("SN1",SA_start);
   if(PcmSink.fIsDSPdecode)
   {
      PcmRut_GetPcmFromDSP(PcmSinkStatic.pSoundBuffer, uSpace);
   }
   else
   {
      pcmsink_DspSound_GetPcmFromDSP(uSpace);
   }
   //SLA_CustomLogging("SN1",SA_stop);
#if defined(__AUDIO_MIXER_SUPPORT__) 
   if(PcmSinkStatic.uPcmFunction & PCM_FUNC_MIXER)
   {
      //SLA_CustomLogging("SN3",SA_start);
      pcmsink_DspSound_AddFromMixer(uSpace);
      //SLA_CustomLogging("SN3",SA_stop);
      PcmMixer_DataRequestCallback();
   }
#endif
#if defined(__VIBRATION_SPEAKER_SUPPORT__)   
   if(AFE_IsAudioLoudSpk() && (!PcmSinkStatic.uBluetoothFunction))
   {
      kal_uint32 smpl_rate_idx = Media_GetSamplingRateIndex(PcmSink.uSampleRate);
      Vibration_Notch_Filter(PcmSinkStatic.pSoundBuffer, PcmSinkStatic.pSoundBuffer, 1, uSpace << 2, (kal_int32 *)&Vibr_Filter_Stack_Snddata[0][0], (kal_uint32 *)&VIBR_NVRAM_DATA.VIBR_NVRAM_LOUD_FILTER_COEF[0][smpl_rate_idx][0]);
      Vibration_Notch_Filter(PcmSinkStatic.pSoundBuffer, PcmSinkStatic.pSoundBuffer, 1, uSpace << 2, (kal_int32 *)&Vibr_Filter_Stack_Snddata[1][0], (kal_uint32 *)&VIBR_NVRAM_DATA.VIBR_NVRAM_LOUD_FILTER_COEF[1][smpl_rate_idx][0]);
   }
#endif   
   if(PcmSinkStatic.uPcmFunction & PCM_DTMF_FUNCTIONS)
   {
      //SLA_CustomLogging("SN2",SA_start);
      pcmsink_DspSound_AddFromTone(uSpace);
      //SLA_CustomLogging("SN2",SA_stop);
      DTMF_MCU_DataRequestCallback();
   }
   if(0 == AFE_GetOutputDevice(L1SP_AUDIO) && 0 == (PcmSinkStatic.uPcmFunction & PCM_DTMF_FUNCTIONS))
   {
      fWriteZeroToDsp = KAL_TRUE;
   }

   if(PcmSink.fIsDSPdecode)
   {
      PcmRut_PutPcmToDSP(PcmSinkStatic.pSoundBuffer, (kal_int16*)PcmSinkStatic.pSoundBuffer, uSpace, fWriteZeroToDsp);
   }
   else
   {
      pcmsink_DspSound_PutPcmToDSP(uSpace, fWriteZeroToDsp);
   }

#if defined(__BT_AUDIO_VIA_SCO__) || defined(__BT_A2DP_PROFILE__)
   if(PcmSinkStatic.uBluetoothFunction)
   {
      kal_bool fMono2Stereo = KAL_FALSE;
      kal_uint32 uSamples = 0;

      //SLA_CustomLogging("SN4",SA_start);
      if(!(PcmSinkStatic.uPcmFunction & PCM_FUNC_AUDIO) && uSpace==0)
      {
         memset(PcmSinkStatic.pSoundBuffer, 0, sizeof(kal_int16)*uValidAudioData);
         uSpace = uValidAudioData;  // fill silence to BT
      }
      else if(PcmSinkStatic.fBtDeviceMute || PcmSinkStatic.uMuteFunction )
      {
         memset(PcmSinkStatic.pSoundBuffer, 0, sizeof(kal_int16)*uSpace);
      }
      else
      {
         pcmsink_ApplyGainOn16Bit((kal_int16*)PcmSinkStatic.pSoundBuffer, PcmSinkStatic.uBtDeviceGain, uSpace);
      }
      uSamples = uSpace;
      if(PcmRut_IsStereo2Mono())
      {
         uSamples >>= 1; 
         fMono2Stereo = KAL_TRUE;
      }
#if defined(__BT_AUDIO_VIA_SCO__)
      if(PcmSinkStatic.uBluetoothFunction & PCMSINK_BT_SCO)
      {
#if defined(__CVSD_CODEC_SUPPORT__) 
         BT_SCO_AudioWriteData((kal_int16*)PcmSinkStatic.pSoundBuffer, uSamples, fMono2Stereo);
#else
         AVB_WriteData((kal_int16*)PcmSinkStatic.pSoundBuffer, uSamples, fMono2Stereo);
#endif
      }
#endif           
#if defined(__BT_A2DP_PROFILE__)
      if(PcmSinkStatic.uBluetoothFunction & PCMSINK_BT_SBC)
      {
         SBC_WriteData((kal_int16*)PcmSinkStatic.pSoundBuffer, uSamples, fMono2Stereo);
      }
#endif
      //SLA_CustomLogging("SN4",SA_stop);
   }
#endif
   return uNextHisrSamples;
}

//------------------------------------------------------
//8k speech path, for HQA and META mode only.
//------------------------------------------------------

static void pcmsink_Speech_Dsp_Open()
{
   kal_int32 I;
   PcmSinkStatic.uState = PCMSINK_STATE_RUNNING;
   AM_PCM8K_PlaybackOn();
   *DSP_PCM_CTRL = WAV_DSP_STATE_INIT;
   for (I = 0; ; I++) 
   {
      if((*DSP_PCM_CTRL == WAV_DSP_STATE_RUNING)) 
      {
         break;
      }
      ASSERT( I < 40 );
      kal_sleep_task( 2 );
   }
}

static void pcmsink_Speech_Dsp_Close()
{
   kal_int32 I;
   for (I = 0; ; I++) 
   {
      if (*DSP_PCM_CTRL == WAV_DSP_STATE_IDLE)
      {
         break;
      }
      else if(*DSP_PCM_CTRL == WAV_DSP_STATE_RUNING)
      {
         *DSP_PCM_CTRL = WAV_DSP_STATE_ABORT;
      }
      ASSERT( I < 40 );
      kal_sleep_task( 2 );
   }
   AM_PCM8K_PlaybackOff( KAL_TRUE );
}

static void pcmsink_Speech_Dsp_Init()
{
   if(*DSP_PCM_CTRL == WAV_DSP_STATE_READY) 
   {
      PcmSink.uDspBufferBase = *DSP_PCM_W;
      PcmSink.uDspBufferSize = *DSP_PCM_R;
      PcmSink.uDspBufferEnd  = PcmSink.uDspBufferBase + PcmSink.uDspBufferSize;
      *DSP_PCM_W = 0;
      *DSP_PCM_R = 0;
      *DSP_PCM_CTRL = WAV_DSP_STATE_START;
   }
}

static void pcmsink_Speech_Dsp_Terminate()
{
   if( *DSP_PCM_CTRL == WAV_DSP_STATE_RUNING)
   {
      *DSP_PCM_CTRL = WAV_DSP_STATE_STOP;
   }
}

static void pcmsink_Audio_Dsp_Init()
{
   if(PcmSinkStatic.uState == PCMSINK_STATE_INIT) 
   {
      #if defined(__KARAOKE_SUPPORT__)      
      if(Media_IsKaraoke())
      {
                             
         switch (PcmSink.uSampleRate)                          
         {                                             
         	  case  8000: PcmSink.uDspBufferSize =  480;  break;
             case 11025: PcmSink.uDspBufferSize =  660;  break;
             case 12000: PcmSink.uDspBufferSize =  720;  break;
             case 16000: PcmSink.uDspBufferSize =  960;  break;
             case 22050: PcmSink.uDspBufferSize = 1320;  break;
             case 24000: PcmSink.uDspBufferSize = 1440;  break;
             case 32000: PcmSink.uDspBufferSize = 1920;  break;
             case 44100: PcmSink.uDspBufferSize = 2688;  break;
             case 48000: PcmSink.uDspBufferSize = 2880;  break;
         }
      } 
      else                                            
      #endif  
      {
      	 PcmSink.uDspBufferSize = ASP_FRAMELEN_PCM; 
      }                                                                                                                                                                     
      
      PcmSink.uDspBufferBase = ASP_DSP_PCM_BUFFER_BASE_PCM;
      PcmSink.uDspBufferEnd  = PcmSink.uDspBufferBase + PcmSink.uDspBufferSize;
      *DSP_PCM_W = PcmSink.uDspBufferBase;
      *DSP_PCM_R = PcmSink.uDspBufferBase;
#if defined(__VIBRATION_SPEAKER_SUPPORT__)      
      if(PcmSinkStatic.uPcmFunction & PCM_FUNC_VIB)
      {
      	 volatile uint16 *pIdmaPtr;
      	 kal_uint32 I=0;
      	 pIdmaPtr = DSP_DM_ADDR(PCM_PLAYBACK_DSP_PAGE_NUM, PcmSink.uDspBufferBase);
      	 for(I=0;I<ASP_FRAMELEN_PCM;I++)
         {
            *pIdmaPtr++ = 0;
         }
      }
#endif          
      PcmSinkStatic.uState = PCMSINK_STATE_RUNNING;
   }
}

static kal_uint32 pcmsink_WriteDataToDsp(kal_uint16 *pSrc16, kal_uint32 uSrcWord, kal_bool fMono2Stereo, kal_uint32 channel_type)
{
    volatile uint16 *pIdmaPtr;
    kal_uint32 uDspWord=0, uUseWord=0;
    kal_uint16 uDspWritePos=0;
    if (uSrcWord==0)
    {
        return 0;
    }
    pcmsink_DspGetWriteBuffer(&uDspWritePos, &uDspWord);
    pIdmaPtr = DSP_DM_ADDR(PCM_PLAYBACK_DSP_PAGE_NUM, uDspWritePos);
    
    if (fMono2Stereo)
    {
        if (uDspWord > uSrcWord << 1)
        {
            uDspWord = uSrcWord << 1;
        }
    }
    else
    {
        if (uDspWord > uSrcWord)
        {
            uDspWord = uSrcWord;
        }
    }
    
#if defined(__KARAOKE_SUPPORT__)
    if(Media_IsKaraoke() && Karaoke_Is_AECStart())
    {
        extern kal_int32 Karaoke_Play_GetDataCount();
        kal_int32 ULdata_count = 0;
        ULdata_count = Karaoke_Play_GetDataCount();
        if(ULdata_count < (uDspWord>>1))
        {
        	 uDspWord = ULdata_count <<1;
        }        
    }    
    uDspWord &= 0xFFFFFFFE; // force to process even data count
#endif    
    
#if defined(__VIBRATION_SPEAKER_SUPPORT__)
    if (AFE_IsAudioLoudSpk())
    {
        kal_uint32 smpl_rate_val = Media_GetSampleRate();
        kal_uint32 smpl_rate_idx = Media_GetSamplingRateIndex(smpl_rate_val);
        kal_int32 is_stereo = (kal_int32)(fMono2Stereo ? KAL_FALSE : KAL_TRUE);
        kal_int32 buffer_size_in_bytes =  fMono2Stereo ? uDspWord : uDspWord << 1;
        Vibration_Notch_Filter_16Bit(pSrc16, pSrc16, is_stereo, buffer_size_in_bytes, (kal_int32 *)&Vibr_Filter_Stack_Auddata[0][0], (kal_uint32 *)&VIBR_NVRAM_DATA.VIBR_NVRAM_LOUD_FILTER_COEF[0][smpl_rate_idx][0]);
        Vibration_Notch_Filter_16Bit(pSrc16, pSrc16, is_stereo, buffer_size_in_bytes, (kal_int32 *)&Vibr_Filter_Stack_Auddata[1][0], (kal_uint32 *)&VIBR_NVRAM_DATA.VIBR_NVRAM_LOUD_FILTER_COEF[1][smpl_rate_idx][0]);
    }
#endif 
    
    if (fMono2Stereo)
    {
#if defined(__KARAOKE_SUPPORT__)
        if (Media_IsKaraoke())
        {
            pcmsink_DspSound_AddFromVoice((kal_int16 *)pSrc16 ,uDspWord>>1);	
            Karaoke_Ref_WriteData((kal_int16 *)pSrc16, uDspWord>>1);
        }
#endif
        IDMA_WriteToDSP_Duplicate(pIdmaPtr, pSrc16, uDspWord);
        uUseWord = uDspWord>>1;
    }
    else
    {
#if defined(__KARAOKE_SUPPORT__)
        if (Media_IsKaraoke())
        {
            pcmsink_DspSound_AddFromVoice((kal_int16 *)pSrc16 ,uDspWord);
            Karaoke_Ref_WriteData((kal_int16 *)pSrc16, uDspWord);
        }
#endif 
        
#if defined(BT_SERIAL_PLAYBACK_AUDIO_SYNC)
        if (channel_type == PLAYBACK_CH_LEFT || channel_type == PLAYBACK_CH_RIGHT)
        {
            kal_int32 smpl_cnt = uDspWord >> 1;
            kal_uint16 *p_in;
            kal_uint16 *p_ou;
            
            if (channel_type == PLAYBACK_CH_LEFT)
            {
                p_in = pSrc16 + 0;
                p_ou = pSrc16 + 1;
            }
            else
            {
                p_in = pSrc16 + 1;
                p_ou = pSrc16 + 0;
            }
            
            while (smpl_cnt-- > 0)
            {
                *p_ou = *p_in;
                p_ou += 2;
                p_in += 2;
            }
        }
#endif  // defined(BT_SERIAL_PLAYBACK_AUDIO_SYNC)
        
        IDMA_WriteToDSP(pIdmaPtr, pSrc16, uDspWord);
        
        uUseWord = uDspWord;
    }
    
    pcmsink_DspWriteDataDone(uDspWord);
    return uUseWord;
}

static kal_uint32 pcmsink_WriteSilenceToDsp()
{
   volatile uint16 *pIdmaPtr;
   kal_uint32 uDspWord=0, uUseWord=0, I, J;
   kal_uint16 uDspWritePos=0;
   for(J=0;J<2;J++)
   {
      pcmsink_DspGetWriteBuffer(&uDspWritePos, &uDspWord);
      pIdmaPtr = DSP_DM_ADDR(PCM_PLAYBACK_DSP_PAGE_NUM, uDspWritePos);
      for(I=0;I<uDspWord;I++)
      {
         *pIdmaPtr++ = 0;
      }
      pcmsink_DspWriteDataDone(uDspWord);
      uUseWord += uDspWord;
   }
   return uUseWord;
}

static kal_uint32 pcmsink_PutData(AudComHdlInt *pIntCompHandle, kal_bool fMono2Stereo)
{
    kal_uint32 uSrcByte, uSrcWord, uUsedWord, uRealDataCount=0;
   kal_uint32 uTotalPutWord=0;
   kal_uint8 *pSrcBuf;
   kal_bool fFillData = (PcmSinkStatic.uPcmFunction & PCM_FUNC_AUDIO) && pIntCompHandle;
   if( fFillData )
   {
      while(1)
      {
         ACU_GetReadBuffer( (AudComHdl *)pIntCompHandle, &pSrcBuf, &uSrcByte);
            uSrcWord = uSrcByte>>1;
#if defined(BT_SERIAL_PLAYBACK_AUDIO_SYNC)
            uUsedWord = pcmsink_WriteDataToDsp((kal_uint16 *)pSrcBuf, uSrcWord, fMono2Stereo, bt_serial_channel_type);
#else   // defined(BT_SERIAL_PLAYBACK_AUDIO_SYNC)
            uUsedWord = pcmsink_WriteDataToDsp((kal_uint16 *)pSrcBuf, uSrcWord, fMono2Stereo, PLAYBACK_CH_NORMAL);
#endif  // defined(BT_SERIAL_PLAYBACK_AUDIO_SYNC)
         uTotalPutWord += uUsedWord;
         ACU_ReadDataDone( (AudComHdl *)pIntCompHandle, uUsedWord<<1);
         if(uUsedWord == 0)
         {
            break;
         }
      }
      uRealDataCount = uTotalPutWord;
   }
   else // fill silence
   {
      uTotalPutWord = pcmsink_WriteSilenceToDsp();
   }
   kal_dev_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_HISR_MOVE_DATA, fFillData, uTotalPutWord, pIntCompHandle->isEOF, PcmSink.fIsTimeUp);
   return uRealDataCount ;
}

static void pcmsink_Hisr_AudioData()
{
   kal_bool fIsDspUnderflow = KAL_FALSE;
   kal_uint32 uDspCurrentSampleCount;
   AudComHdlInt *pIntCompHandle = PcmSink.pIntCompHandle;

   if(PcmSink.fIsVoicePath)
   {
      pcmsink_Speech_Dsp_Init();
      if(*DSP_PCM_CTRL != WAV_DSP_STATE_RUNING)
      {
         return;
      }
   }
   
   if(PcmSink.fIsLowPower)
   {
      AUDLP_StartTimer();
   }

   if( PcmSinkStatic.uState != PCMSINK_STATE_RUNNING && PcmSinkStatic.uState != PCMSINK_STATE_ENDING )
   {
      if(PcmSinkStatic.uPcmFunction & PCM_SOUND_FUNCTIONS)
      {
         pcmsink_PutData(NULL, KAL_FALSE); // fill silence when sound is playing
      }
      return;
   }

   if(PcmSinkStatic.uState == PCMSINK_STATE_RUNNING)
   {
      kal_uint32 uMovedToDspWord = pcmsink_PutData(pIntCompHandle, (PcmSink.uChannelNumber==1));
      pcmsink_UpdateTime(uMovedToDspWord);
      if( (pIntCompHandle && pIntCompHandle->isEOF) || PcmSink.fIsTimeUp)
      {
         PcmSinkStatic.uState = PCMSINK_STATE_ENDING;
         if(PcmSink.fIsVoicePath)
         {
           pcmsink_Speech_Dsp_Terminate();
         }
      }
   }

   uDspCurrentSampleCount = pcmsink_DspGetDataCount();
   if(uDspCurrentSampleCount < PcmSinkStatic.uSoundFrameSamples)  //dsp will not play if the data is less than 12 sample
   {
      kal_dev_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_HISR_UNDERFLOW, PcmSinkStatic.uState, uDspCurrentSampleCount);
      fIsDspUnderflow = KAL_TRUE;
   }

   if(PcmSinkStatic.uState == PCMSINK_STATE_ENDING && fIsDspUnderflow)
   {
      PcmSinkStatic.uState = PCMSINK_STATE_FLUSHED;
      if(PcmSinkStatic.uPcmFunction & PCM_SOUND_FUNCTIONS)
      {
         pcmsink_PutData(NULL, KAL_FALSE); // fill silence when sound is playing
      }
      if(!(PcmSinkStatic.uPcmFunction & PCM_SOUND_FUNCTIONS))
      {
         PcmSink_Mute(KAL_TRUE, PCMSINK_MUTE_PCMSINK); // no soun playing. ramp down
      }
      kal_dev_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_HISR_ENDING, PcmSinkStatic.uState, PcmSink.fIsTimeUp);
      if(pIntCompHandle && PcmSink.pMedPlayHandle)
      {
         if(PcmSink.fIsTimeUp)
         { 
            mhdlException(PcmSink.pMedPlayHandle, MEDIA_STOP_TIME_UP);
         }
         else
         {
            mhdlException(PcmSink.pMedPlayHandle, MEDIA_END);
         }
      }
      return;
   }

   kal_dev_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_HISR_OUT, PcmSinkStatic.uState, PcmSink.pMedPlayHandle, PcmSink.pMedPlayHandle->isUnderflow, PcmSink.pMedPlayHandle->waiting, fIsDspUnderflow);
   if(pIntCompHandle && PcmSinkStatic.uState == PCMSINK_STATE_RUNNING && PcmSink.pMedPlayHandle && PcmSink.pMedPlayHandle)
   {
      if(!PcmSink.pMedPlayHandle->waiting)
      {
         PcmSink.pMedPlayHandle->waiting = KAL_TRUE;
         if(fIsDspUnderflow)
         {
            PcmSink.pMedPlayHandle->isUnderflow = KAL_TRUE;
            mhdlException(PcmSink.pMedPlayHandle, MEDIA_BUFFER_UNDERFLOW ); 
         }
         else
         {
            mhdlException(PcmSink.pMedPlayHandle, MEDIA_DATA_REQUEST ); 
         }
      }
   }
   if(fIsDspUnderflow)
   {
      if(PcmSinkStatic.uPcmFunction & PCM_SOUND_FUNCTIONS)
      {
         pcmsink_PutData(NULL, KAL_FALSE); // fill silence when sound is playing
      }
   }
}

void PcmSink_AllocSoundBuffer()
{
   if( PcmSinkStatic.pSoundBuffer == NULL )
   {
      if(PcmSink.fIsDSPdecode)
      {
         PcmSinkStatic.uSoundFrameSamples = 4096;//2048; //worst case aac 48K and ts
      }
      else
      {
         PcmSinkStatic.uSoundFrameSamples = (kal_uint16)(PcmSink.uSampleRate * 2 * PCM_SOUND_BUFFER_PERIOD / 1000);
         PcmSinkStatic.uSoundFrameSamples = PcmSinkStatic.uSoundFrameSamples & (~1);
      }
      PcmSinkStatic.pSoundBuffer   = (kal_int32 *)audio_alloc_mem_cacheable(PcmSinkStatic.uSoundFrameSamples * 4);  
      ASSERT(PcmSinkStatic.pSoundBuffer);
   }
}

void PcmSink_FreeSoundBuffer()
{
   if(PcmSinkStatic.pSoundBuffer)
   {
      audio_free_mem( (void **) &PcmSinkStatic.pSoundBuffer);
      PcmSinkStatic.pSoundBuffer = NULL;
   }
}

static void pcmsink_Hisr( void *pData )
{

   kal_dev_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_HISR_IN, PcmSinkStatic.uState, PcmSinkStatic.uPcmFunction, PcmSinkStatic.uBluetoothFunction,(kal_uint16)*DP2_AUDIO_ASP_D2M_COUNT);

#if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__AUDIO_DSP_LOWPOWER_V2__)
   AUDLP_SetClkSwitch_26M(KAL_FALSE);
#endif

#if VERIFY_AVSYNC
   ut_avsync_play_hisr();
#endif

#if defined(_DSP_INTERSHAREMEM_EN_)    
   *DP2_AUDIO_ASP_TASK4_DM_HANDSHAKE = 0; 
#endif

   pcmsink_PrintGainForDebug();
   //SLA_CustomLogging("AU0",SA_start);
   pcmsink_Hisr_AudioData();
   //SLA_CustomLogging("AU0",SA_stop);

   if(!PcmSink.fIsVoicePath)
   {
      if((PcmSinkStatic.uPcmFunction & PCM_SOUND_FUNCTIONS || PcmSinkStatic.uBluetoothFunction || PcmSinkStatic.uPcmFunction == 0)&& PcmSinkStatic.pSoundBuffer) //sound
      {   
         pcmsink_Hisr_SoundData();
         pcmsink_SetInterruptTime(PCM_SOUND_INTERRUPT_PERIOD-2);
      }
      else
      {
         kal_uint32 uBufferTime = pcmsink_DspGetDataCount() * 1000 / (PcmSink.uSampleRate << 1);
         if(Media_IsKaraoke())
         {
            pcmsink_SetInterruptTime(PCM_SOUND_INTERRUPT_PERIOD);   
         }
         else
         {
            if(uBufferTime < (PCM_SOUND_INTERRUPT_PERIOD+20))
            {
               pcmsink_SetInterruptTime(PCM_SOUND_INTERRUPT_PERIOD);
            }
            else
            {
               pcmsink_SetInterruptTime(uBufferTime - PCM_SOUND_INTERRUPT_PERIOD);
            }
         }  
         PcmSink.uDspSoundWritePos = 0;
      }
   }

#if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__AUDIO_DSP_LOWPOWER_V2__)
   AUDLP_SetClkSwitch_26M(KAL_TRUE);
#endif
}

static void pcmsink_OpenDevice()
{
   kal_uint32 uMovedToDspWord;
   PcmSinkStatic.uState = PCMSINK_STATE_INIT;
   PcmSinkStatic.uAudId = L1Audio_GetAudioID();
   L1Audio_HookHisrHandler( DP_D2C_PCM_P, pcmsink_Hisr, NULL );
   L1Audio_SetEventHandler( PcmSinkStatic.uAudId, mhdlCallbackTask );
   KT_StopAndWait();
   TONE_StopAndWait();
#if VERIFY_AVSYNC
   ut_a2v_play_dsp_start();
#endif
  
   Media_SetAudioFormat(PcmSink.uFormat); 

#if defined(__VIBRATION_SPEAKER_SUPPORT__)  
   memset(Vibr_Filter_Stack_Auddata,0,sizeof(kal_int32)*2*8);
   memset(Vibr_Filter_Stack_Snddata,0,sizeof(kal_int32)*2*8);   
#endif 
   if(PcmSink.fIsAllowLowPower)
   {  //currently, only mp3 format has lowpower
      AUDLP_Mode(KAL_TRUE, 1);
   }

   if(AUDLP_Check_LowPower_Status())
   {
      mhdlSetFlag_MD2G_Id( PcmSinkStatic.uAudId );
      AUDLP_Set_ClkSwitchMode(KAL_TRUE);
      AUDLP_SW_Trigger_Event_Setting(KAL_TRUE);
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
      //for MT6260, after set MD2G CPD, should set MD2G 26Mhz to avoid the problem that CPD meets MPLL/EPLL bug
      AUDLP_SetClkSwitch_26M(KAL_TRUE);
#endif
   }
   else
   {
      mhdlDisallowSleep_Id(PcmSinkStatic.uAudId);
   }

   ClearDSPAudioCommonFlag();
   
   if(AUDLP_Check_LowPower_Status())
   {
      PcmSink.fIsLowPower = KAL_TRUE;
      AUDLP_SetPCMPlay_LargerBuffer(KAL_TRUE);
      AUDLP_SetTimerPeriod((kal_uint32)PcmSink.uSampleRate);
   }

#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
      *DSP_AUDIO_FLEXI_CTRL |= (FLEXI_VBI_ENABLE | FLEXI_SD_ENABLE);  //for 16K speech record
#endif

#if defined(__HQA_AUDIO__)
   if( PcmSink.uSampleRate == 8000 && PcmSink.uChannelNumber == 1)
   {
      PcmSink.fIsVoicePath = KAL_TRUE;
      Media_SetOutputDevice(uWavOutputDevice);
   }
#endif

   PcmSink.uDspSoundWritePos = 0;
   DSP_DynamicDownload( DDID_AudioHeader );
   if(PcmSink.fIsVoicePath)
   {
      pcmsink_Speech_Dsp_Open();
   }
   else
   {
      pcmsink_Audio_Dsp_Init();
#if defined(__AUDIO_MIXER_SUPPORT__)       
      uMovedToDspWord = pcmsink_PutData(PcmSink.pIntCompHandle, (PcmSink.uChannelNumber==1));
#endif      
      pcmsink_UpdateTime(uMovedToDspWord);
      pcmsink_SetInterruptSample(0);
      AM_AudioPlaybackOn( ASP_TYPE_PCM_HI, SampleRateTable[autGetSampleRateIdx(PcmSink.uSampleRate)] );
   }
}

static void pcmsink_CloseDevice()
{
   PcmSink_Mute(KAL_TRUE, PCMSINK_MUTE_PCMSINK);
#if defined(__KARAOKE_SUPPORT__)
   if(Media_IsKaraoke())
   {
   	  Karaoke_Play_Mix_DeInit();
   	  Media_Stop(); 
      ASSERT(!AM_GetRecordFormat());
      Karaoke_Play_Free();
   }   
#endif   

   *DSP_PCM_CTRL = WAV_DSP_AUDIO_STATE_IDLE;
   if(PcmSink.fIsVoicePath)
   {
      pcmsink_Speech_Dsp_Close();
   }
   else
   {
      AM_AudioPlaybackOff( KAL_TRUE );
   }
   if(PcmSink.pMedPlayHandle)
   {
      PcmSink.pMedPlayHandle->GetCurrentTime(PcmSink.pMedPlayHandle);
      PcmSink.pMedPlayHandle->rbInfo.param = NULL;
   }
   
   *DSP_AUDIO_FLEXI_CTRL &= ~( FLEXI_VBI_ENABLE | FLEXI_SD_ENABLE );
   L1Audio_UnhookHisrHandler( DP_D2C_PCM_P );

   PcmSink_Mute(KAL_FALSE, PCMSINK_MUTE_PCMSINK);

   if(PcmSink.fIsLowPower == KAL_TRUE)
   {   
#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
      AUDLP_SetClkSwitch_26M(KAL_FALSE);
      AUDLP_SW_Trigger_Event_Setting(KAL_FALSE);
      AUDLP_Set_ClkSwitchMode(KAL_FALSE);
#endif
      AUDLP_SetPCMPlay_LargerBuffer(KAL_FALSE);
      AUDLP_Mode(KAL_FALSE, 1);
      PcmSink.fIsLowPower = KAL_FALSE;
      PcmSink.fIsAllowLowPower = KAL_FALSE;
      mhdlClearFlag_MD2G_Id(PcmSinkStatic.uAudId);
   }
   else
   {
      mhdlAllowSleep_Id(PcmSinkStatic.uAudId);
   }
#if VERIFY_AVSYNC
   ut_a2v_dsp_stop();
#endif

   //PcmSinkStatic.uBluetoothFunction = 0;
   PcmSinkStatic.uState = PCMSINK_STATE_IDLE;
   L1Audio_FreeAudioID(PcmSinkStatic.uAudId);

#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   if(!VIBR_IsPlayingDummy())
   {
      VIBR_Vibration_Activate();
   }
#endif //__VIBRATION_SPEAKER_SUPPORT__   
}

static void pcmsink_DelayOff_Excute(kal_uint32 arg1, void* arg2)
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_DELAYOFF_EXCUTE, PcmSinkStatic.uPcmFunction, PcmSinkStatic.uState );
   if(PcmSink.fIsDSPdecode)
   {
      return;
   }
   if(PcmSinkStatic.uPcmFunction == 0 && PcmSinkStatic.uState != PCMSINK_STATE_IDLE) 
   {
      pcmsink_CloseDevice();
   }
}

static void pcmsink_DelayOff_TimeUp( void *data )
{
   L1Audio_InProcCall(pcmsink_DelayOff_Excute, NULL, NULL);
}

static void pcmsink_DelayOff_Begin(kal_bool fStopNow)
{
   SGPT_CTRL_START_T start;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_DELAYOFF_BEGIN, PcmSinkStatic.uPcmFunction, PcmSinkStatic.uState );
#if defined ( __BT_AUDIO_VIA_SCO__ ) 
   if(L1SP_IsBluetoothOn())
   {
      fStopNow = KAL_TRUE;
   }
#endif
#if defined(__BT_A2DP_PROFILE__)
   if(SBC_IsOn())
   {
      fStopNow = KAL_TRUE;
   }
#endif
#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   {
      if(VIBR_IsPlayingDummy())
      {
         fStopNow = KAL_TRUE;
      }
   }
#endif
#if defined(__KARAOKE_SUPPORT__)
   if(Media_IsKaraoke())
   {
      fStopNow = KAL_TRUE;
   }   
#endif 
   if(fStopNow)
   {
      pcmsink_DelayOff_Excute(NULL, NULL);
      return;
   }
   if(PcmSinkStatic.uGPT == 0)
   {
      PcmSinkStatic.uGPT = DclSGPT_Open( DCL_GPT_CB ,0 );
   }
   else
   {
      DclSGPT_Control( PcmSinkStatic.uGPT, SGPT_CMD_STOP,0);
   }
   start.u2Tick = (PCM_SOUND_DELAY_OFF_MS / 10);
   start.pfCallback = pcmsink_DelayOff_TimeUp;
   start.vPara = NULL;
   DclSGPT_Control( PcmSinkStatic.uGPT, SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
}

void PcmSink_TerminateSound()
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_STOP_IMMEDIATE, PcmSinkStatic.uPcmFunction, PcmSinkStatic.uState );
   DTMF_MCU_StopAndWait();
   PcmSinkStatic.uPcmFunction &= ~PCM_SOUND_FUNCTIONS;
#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   if(VIBR_IsPlayingDummy())
   {
      PcmSinkStatic.uPcmFunction |= PCM_FUNC_VIB;
   }
#endif   
   pcmsink_DelayOff_Excute(NULL, NULL);
}

void PcmSink_StartBT(kal_uint32 uFunction)
{
   kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_START_BT, PcmSinkStatic.uBluetoothFunction, uFunction);
   PcmSinkStatic.uBluetoothFunction |= uFunction;
   if(Media_IsDSPDec())
   {
      PcmRut_TurnOnPcmRouteInterrupt();
   }
}

void PcmSink_StopBT(kal_uint32 uFunction)
{
   kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_STOP_BT, PcmSinkStatic.uBluetoothFunction, uFunction);
   PcmSinkStatic.uBluetoothFunction &= ~uFunction;
   if(PcmSinkStatic.uBluetoothFunction == 0 && (PcmSinkStatic.uPcmFunction & PCM_SOUND_FUNCTIONS))
   {
      PcmRut_TurnOffPcmRouteInterrupt();
   }
}

void PcmSink_StopSound(kal_uint32 uType)
{
   PcmSinkStatic.uPcmFunction &= ~uType;
   if(PcmSinkStatic.uPcmFunction == 0)
   {
      PcmSink_Mute(KAL_TRUE, PCMSINK_MUTE_PCMSINK);
   }
   if(uType & PCM_FUNC_TONE)
   {
      AFE_TurnOffSpeaker( L1SP_TONE );
   }
   if(uType & PCM_FUNC_KEYTONE)
   {
      AFE_TurnOffSpeaker( L1SP_KEYTONE );
   }
   if(PcmSinkStatic.uPcmFunction == 0) 
   {
      AFE_TurnOffSpeaker( L1SP_AUDIO );
   }
   else if(PcmSinkStatic.uPcmFunction & ~PCM_DTMF_FUNCTIONS)
   {
      AFE_TurnOnSpeaker( L1SP_AUDIO );
   }
   if(PcmSinkStatic.uBluetoothFunction == 0 && (PcmSinkStatic.uPcmFunction & PCM_SOUND_FUNCTIONS)==0)
   {
      PcmRut_TurnOffPcmRouteInterrupt();
   }
   pcmsink_DelayOff_Begin(KAL_FALSE);
}

kal_bool PcmSink_StartSound(kal_uint32 uType, kal_uint32 uSampleRate, kal_uint32 uChannelNumber)
{
   if(PcmSink.fIsVoicePath)
   {
      return KAL_FALSE;
   }
   PcmSinkStatic.uPcmFunction |= uType;
   PcmSink_Mute(KAL_FALSE, PCMSINK_MUTE_PCMSINK);
   if(PcmSinkStatic.uState == PCMSINK_STATE_FLUSHED || PcmSinkStatic.uState == PCMSINK_STATE_ENDING || PcmSinkStatic.uState == PCMSINK_STATE_RUNNING )
   {
      if(Media_IsDSPDec())
      {
         PcmRut_TurnOnPcmRouteInterrupt();
      }
      else
      {
         pcmsink_SetInterruptTime(PCM_SOUND_INTERRUPT_PERIOD-2);
      }
      ASSERT(PcmSink.uSampleRate == uSampleRate);
      if(uType == PCM_FUNC_TONE)
      {
         AFE_TurnOffSpeaker( L1SP_AUDIO );
         AFE_TurnOnSpeaker( L1SP_TONE );
      }
      else if(uType == PCM_FUNC_KEYTONE )
      {
         AFE_TurnOffSpeaker( L1SP_AUDIO );
         AFE_TurnOnSpeaker( L1SP_KEYTONE );
      }
      else if(PcmSinkStatic.uPcmFunction & ~PCM_DTMF_FUNCTIONS)
      {
         AFE_TurnOnSpeaker( L1SP_AUDIO );
      }
      return KAL_TRUE;
   }
   else if(PcmSinkStatic.uState == PCMSINK_STATE_IDLE)
   {
      PcmSink.uSampleRate    = uSampleRate;
      PcmSink.uChannelNumber = uChannelNumber;
      PcmSink.fIsVoicePath   = KAL_FALSE;
      PcmSink.uFormat        = MEDIA_FORMAT_UNKNOWN;
   }
   else
   {
      ASSERT(0);
   }
   PcmSink_AllocSoundBuffer();
   PcmSink.pIntCompHandle = NULL;
   Media_SetSampleRate(PcmSink.uSampleRate);
   pcmsink_OpenDevice( NULL );
   return KAL_TRUE;
}

static OMX_ERRORTYPE pcmsink_Start_Audio(AudComHdl *pCompHandle)
{
   AudComHdlInt *pIntCompHandle = (AudComHdlInt *)pCompHandle;
   PCM_SinkData *pSinkData = (PCM_SinkData *)pIntCompHandle->pPrivateData;
   kal_bool fIsDspDecode;
   kal_uint32 uSaveMask;
   fIsDspDecode = Media_IsDSPDec();
   PcmSink_Mute(KAL_FALSE, PCMSINK_MUTE_PCMSINK);
   if(PcmSinkStatic.uState != PCMSINK_STATE_IDLE)
   {  //sound is playing
      PcmSink_TerminateSound();
   }
#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   VIBR_Vibration_Deactivate();
#endif 
   memset(&PcmSink, 0, sizeof(PcmSink));
   uSaveMask = SaveAndSetIRQMask();
   pIntCompHandle->isEOF  = KAL_FALSE;
   PcmSink.uSampleRate    = pSinkData->uSampleRate;
   PcmSink.uChannelNumber = pSinkData->uChannelNumber;
   PcmSink.fIsVoicePath   = pSinkData->fIsVoicePath;
   PcmSink.uFormat        = MEDIA_FORMAT_UNKNOWN;
   PcmSink.pIntCompHandle = pIntCompHandle;
   PcmSink.fIsDSPdecode   = fIsDspDecode;
   if(pIntCompHandle->mhdl)
   { 
      MHPB_Internal *pCilentHandle =(MHPB_Internal *)pIntCompHandle->mhdl;
      PcmSink.pMedPlayHandle = (MHdl *)pCilentHandle;
      PcmSink.uFormat = PcmSink.pMedPlayHandle->mediaType;
      if(((PcmSink.uFormat == MEDIA_FORMAT_DAF && pCilentHandle->pstFSAL) || PcmSink.uFormat == MEDIA_FORMAT_A2DP)&& (!Media_IsKaraoke()))
      {
         PcmSink.fIsAllowLowPower = KAL_TRUE;
      }
   }
   RestoreIRQMask(uSaveMask);

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_START_IN, PcmSinkStatic.uState, PcmSink.uSampleRate, PcmSink.uChannelNumber);
   Media_SetSampleRate(PcmSink.uSampleRate);  
   PcmSink_AllocSoundBuffer();
#if defined(__KARAOKE_SUPPORT__)
   if(Media_IsKaraoke())
   {
     Karaoke_Play_Alloc();
   }
#endif
   PcmSinkStatic.uPcmFunction |= PCM_FUNC_AUDIO;

#if defined(BT_SERIAL_PLAYBACK_AUDIO_SYNC)
    if (b_apply_bt_serial_delay)
    {
        kal_uint32 bt_clk = BTIF_Get_BT_HW_Native_Clk();
        kal_uint32 master_clk = (bt_clk + bt_serial_offset) & BT_CLK_MASK;
        
        if (master_clk < BT_CLK_UPPER_BOUND && bt_serial_start_time < BT_CLK_UPPER_BOUND)
        {
            kal_int32 clk_curr = (kal_int32)master_clk;
            kal_int32 clk_targ = (kal_int32)bt_serial_start_time;
            kal_int32 diff = pcmsink_Calculate_BT_Clock_Diff (clk_curr, clk_targ);
            kal_int32 timeout_cnt;
            
            timeout_cnt = 500;  // about 2.3 sec (= 500 x 4.615 ms)
            
            while (diff > BT_CLK_SLEEP_TICK)
            {
                kal_sleep_task(1);
                bt_clk = BTIF_Get_BT_HW_Native_Clk();
                master_clk = (bt_clk + bt_serial_offset) & BT_CLK_MASK;
                clk_curr = (kal_int32)master_clk;
                diff = pcmsink_Calculate_BT_Clock_Diff (clk_curr, clk_targ);
                if (--timeout_cnt <= 0)
                {
                    break;
                }
            }
            
            timeout_cnt = 1000; // Experimental value to avoid infinite loop
            
            while (diff > 0)
            {
                bt_clk = BTIF_Get_BT_HW_Native_Clk();
                master_clk = (bt_clk + bt_serial_offset) & BT_CLK_MASK;
                clk_curr = (kal_int32)master_clk;
                diff = pcmsink_Calculate_BT_Clock_Diff (clk_curr, clk_targ);
                if (--timeout_cnt <= 0)
                {
                    break;
                }
            }
        }
    }
#endif  // defined(BT_SERIAL_PLAYBACK_AUDIO_SYNC)

   if(!PcmSink.fIsDSPdecode && PcmSinkStatic.uState != PCMSINK_STATE_RUNNING)
   {
      PcmSink.pIntCompHandle = pIntCompHandle;
      pcmsink_OpenDevice();
   }
   else
   {
      PcmSinkStatic.uState = PCMSINK_STATE_RUNNING;
      if(PcmSinkStatic.uBluetoothFunction)
      {
         PcmRut_TurnOnPcmRouteInterrupt();
      }
   }
#if defined(__KARAOKE_SUPPORT__)
   if(Media_IsKaraoke())
   {
   	 	  Karaoke_Play_Mix_Init();
   }
#endif   
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_START_OUT, PcmSinkStatic.uState, PcmSink.uFormat, PcmSink.fIsDSPdecode);
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE pcmsink_Stop_Audio(AudComHdl *pCompHandle)
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_STOP_IN, PcmSinkStatic.uState);
   if( PcmSinkStatic.uState == PCMSINK_STATE_IDLE )
   {
      return;
   }
   PcmSink_Mute(KAL_TRUE, PCMSINK_MUTE_PCMSINK);
   DTMF_MCU_StopAndWait();
   kal_sleep_task(5); //wait to ramp down
   PcmSinkStatic.uPcmFunction &= ~PCM_FUNC_AUDIO;
   if(!PcmSink.fIsDSPdecode)
   {
      pcmsink_DelayOff_Begin(KAL_TRUE); //stop immediate
      PcmSink.uPlayedSamples = 0;
      PcmSink.uPlayedTime = 0;
   }   
   else
   {
      PcmSink_StopSound(PCM_SOUND_FUNCTIONS);
      PcmSinkStatic.uState = PCMSINK_STATE_IDLE;
      PcmSink.fIsDSPdecode = KAL_FALSE;
   }
   PcmSink.pIntCompHandle = NULL;
   PcmSink.pMedPlayHandle = NULL;
   
#if defined(BT_SERIAL_PLAYBACK_AUDIO_SYNC)
    if (b_apply_bt_serial_delay)
    {
        b_apply_bt_serial_delay = KAL_FALSE;
        bt_serial_channel_type = PLAYBACK_CH_NORMAL;
        bt_serial_start_time = 0xFFFFFFFF;
        bt_serial_offset = 0xFFFFFFFF;
        bt_serial_silence_cnt = 0;
    }
#endif  // defined(BT_SERIAL_PLAYBACK_AUDIO_SYNC)

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_STOP_OUT, PcmSinkStatic.uState);
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE pcmsink_SetParameter(AudComHdl *pCompHandle, OMX_INDEXTYPE uIndex, OMX_PTR pStruct)
{
   AudComHdlInt *pIntCompHandle = (AudComHdlInt *)pCompHandle;
   PCM_SinkData *pSinkData = (PCM_SinkData *)pIntCompHandle->pPrivateData;
   switch (uIndex) 
   {
      case OMX_IndexParamMediaTekSetPCMInfo:
      case OMX_IndexParamMediaTekPcmSink:
         {
            SinkParam *pParam = (SinkParam *)pStruct;
            if(OMX_ErrorNone != AudioDrain_Check_SR_CH(pParam->uSamplingFreq,pParam->uChannelNum))
            { 
               return OMX_ErrorBadParameter;
            }
            pSinkData->uSampleRate = pParam->uSamplingFreq;
            pSinkData->uChannelNumber = pParam->uChannelNum;
         }
         break;
      case OMX_IndexParamMediaTekPcmSinkVoice:
            pSinkData->fIsVoicePath = KAL_TRUE;
         break;
      default:
         return OMX_ErrorNotImplemented;
   }

   return OMX_ErrorNone;
}

void PcmSink_MixSoundToDsp()
{
   pcmsink_PrintGainForDebug();
   if(PcmSinkStatic.uPcmFunction & PCM_SOUND_FUNCTIONS || ( PcmSinkStatic.uBluetoothFunction && PcmSinkStatic.uPcmFunction ))
   {
      pcmsink_Hisr_SoundData();
   }
}

kal_uint32 PcmSink_GetCurrentTime()
{
   return PcmSink.uPlayedTime;
}

void PcmSink_GetCurrentPcmInfo(kal_uint16 *uSampleRate, kal_uint8 *uChannelNumber)
{
   if(PcmSinkStatic.uState != PCMSINK_STATE_IDLE)
   {
      *uSampleRate = PcmSink.uSampleRate;
      *uChannelNumber = PcmSink.uChannelNumber;
   }
   else
   {
      *uSampleRate = 0;
      *uChannelNumber = 0;
   }
}

kal_uint32 PcmSink_GetMemSize( void )
{
   kal_uint32 uTempSize=0, uReqSizeTotal=0;

   uTempSize = (sizeof(AudComHdlInt) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;

   uTempSize = (sizeof(PCM_SinkData) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   return uReqSizeTotal;
}

OMX_ERRORTYPE PcmSink_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback,
   OMX_U32        uSamplingRate,
   OMX_U32        uChannelNum
)
{
   PcmSinkGen_Init(pHandle, pBuffer, pFWData, pCallback);
   return OMX_ErrorNone;
}

OMX_ERRORTYPE PcmSinkGen_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
)
{
   OMX_U32 uBufSize;
   AudComHdlInt *pIntCompHandle;
   kal_uint8 *pBuffer8;
   
   *pHandle = NULL;
   
   // The buffer address should be 4 bytes aligned
   ASSERT( (((kal_uint32)pBuffer) & 0x3) == 0);
   
   // Empty the memory
   uBufSize = PcmSink_GetMemSize();
   memset(pBuffer, 0, uBufSize);
   
   // Assign and distribute the memory
   *pHandle = pBuffer;
   pBuffer8 = (kal_uint8 *)pBuffer;
   pIntCompHandle = (AudComHdlInt *)pBuffer;
   pBuffer8 += (sizeof(AudComHdlInt) + 3) & ~0x3;
   pIntCompHandle->pPrivateData = (void *)pBuffer8;
   
   // Initialize the audio handler as default setting
   ACU_InitHdl(*pHandle, pFWData, pCallback);
   
   // Overwrite the member functions
   pIntCompHandle->basic.Start        = pcmsink_Start_Audio;
   pIntCompHandle->basic.Stop         = pcmsink_Stop_Audio;
   pIntCompHandle->basic.SetParameter = pcmsink_SetParameter;
   pIntCompHandle->basic.Deinit       = ACU_GenDeinit;
   return OMX_ErrorNone;
}

kal_bool PcmRender_IsRunning()
{
   return (PcmSinkStatic.uState != PCMSINK_STATE_IDLE);
}

void BT_SetLevelVolume( kal_uint8 uCurStep, kal_uint8 uTotalStep )
{
   #define DIGIGAIN_NEGATIVE_ONE_DB 29204
   kal_uint32 uDigitalGain = 0x7FFF;
   if(uCurStep >= uTotalStep)  //MAX value
   {
      uDigitalGain = 0x7FFF; 
   }
   else if(uCurStep == 0)
   {
      uDigitalGain = 0;
   }
   else
   {
      kal_uint32 uDpPerStep = 1;
      kal_uint32 uNegativeDp = 1;
      kal_int32 I;
      if(uTotalStep<8)
      {
         uDpPerStep = 3;
      }
      else if(uTotalStep<17)
      {
         uDpPerStep = 2;       
      }
      uNegativeDp = uDpPerStep * (uTotalStep - uCurStep);
      for(I=0;I<uNegativeDp;I++)
      {
         uDigitalGain = (uDigitalGain * DIGIGAIN_NEGATIVE_ONE_DB) >> 15;
      }
   }

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_BT_VOLUME, uCurStep, uTotalStep, uDigitalGain);
   PcmSinkStatic.uBtDeviceGain = uDigitalGain;
}

void BT_MuteSpeaker( kal_bool fMute )
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_SINK_BT_MUTE, fMute);
   PcmSinkStatic.fBtDeviceMute = fMute;
#if defined(__CVSD_CODEC_SUPPORT__) 
   BT_SCO_Mute(fMute);
#endif
}

void SBC_SetLevelVolume( kal_uint8 uCurStep, kal_uint8 uTotalStep )
{
   BT_SetLevelVolume( uCurStep, uTotalStep );
}
void SBC_MuteSpeaker( kal_bool fMute )
{
   BT_MuteSpeaker( fMute );
}

#pragma arm section 


