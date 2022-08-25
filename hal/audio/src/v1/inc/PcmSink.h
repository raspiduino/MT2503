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
 *   pcmsink.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   The header file of DAF codec.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef PCM_SINK_DOT_H
#define PCM_SINK_DOT_H

#include "AudCom.h"
#include "SST_sla.h"

#if __BT_MAX_LINK_NUM__ == 2
#define BT_SERIAL_PLAYBACK_AUDIO_SYNC
#endif

typedef enum {
  PCMSINK_STATE_IDLE = 0,
  PCMSINK_STATE_INIT,
  PCMSINK_STATE_RUNNING,
  PCMSINK_STATE_ENDING,
  PCMSINK_STATE_FLUSHED,
} PCMSINK_STATE;

typedef enum {
  SOUND_IDLE = 0,
  SOUND_INIT,
  SOUND_RUNING,
} SOUND_STATE;

#define PCM_SOUND_INTERRUPT_PERIOD (20) //ms
#define PCM_SOUND_DELAY_OFF_MS (3000) //ms

#define PCM_FUNC_AUDIO    (1<<0)
#define PCM_FUNC_MIXER    (1<<1)
#define PCM_FUNC_TONE     (1<<2)
#define PCM_FUNC_KEYTONE  (1<<3)
#define PCM_FUNC_VIB      (1<<4)


#define PCMSINK_BT_SCO (1<<0)
#define PCMSINK_BT_SBC (1<<1)

#define PCM_SOUND_FUNCTIONS (PCM_FUNC_MIXER | PCM_FUNC_TONE | PCM_FUNC_KEYTONE | PCM_FUNC_VIB)
#define PCM_DTMF_FUNCTIONS (PCM_FUNC_TONE | PCM_FUNC_KEYTONE)

#define PCMSINK_DEFAULT_GAIN_STEP  200
#define PCM_SOUND_BUFFER_PERIOD  20 //msec
#define PCM_SOUND_FILLDATA_THRESHOLD  40 //msec
#define PCMSINK_MIN_HISR_SAMPLES 50 //sample

#define WAV_DSP_STATE_IDLE    0x0
#define WAV_DSP_STATE_INIT    0x1
#define WAV_DSP_STATE_READY   0x2
#define WAV_DSP_STATE_START   0x4
#define WAV_DSP_STATE_RUNING  0x8
#define WAV_DSP_STATE_STOP    0x10 
#define WAV_DSP_STATE_ABORT   0x40 

#define WAV_DSP_AUDIO_STATE_IDLE    0x0
#define WAV_DSP_AUDIO_STATE_RUNNING 0x2

#define PCMSINK_MUTE_MEDIA   (1<<0)
#define PCMSINK_MUTE_PCMSINK (1<<1)
#define PCMSINK_MUTE_PCMRUT  (1<<2)
#define PCMSINK_MUTE_I2S     (1<<3)
#define PCMSINK_MUTE_DEPOP   (1<<4)
#define PCMSINK_MUTE_TONE    (1<<5)

#if defined(MT6256) || defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#define PCM_PLAYBACK_DSP_PAGE_NUM 5
#else
#error The new chip should define DM page number
#endif

extern kal_bool Is_PutPcmrutOn(void);
extern const kal_uint8 SampleRateTable[];
extern void mhdlCallbackTask( void *data );

typedef struct {
   kal_uint16      uSampleRate;
   kal_uint8       uChannelNumber;
   kal_bool        fIsVoicePath;
} PCM_SinkData;

extern kal_bool AFE_IsSpeakerMuted( kal_uint8 aud_func);
extern kal_uint8 AFE_GetOutputDevice( kal_uint8 aud_func );

extern void DTMF_MCU_GetReadBuffer(kal_int16 **pBuf_16b, kal_uint32 *uDataWord);
extern void DTMF_MCU_ReadDataDone(kal_uint32 uDataWord);
extern kal_uint32 DTMF_MCU_GetDataCount(void);
extern void DTMF_MCU_DataRequestCallback(void);
extern void DTMF_MCU_StopAndWait(void);

extern void PcmMixer_MixSample(kal_int32 *pMixBuffer, const kal_uint32 uSampleCount);
extern kal_uint32 PcmMixer_GetDataCount(void);
extern void PcmMixer_DataRequestCallback(void);

extern kal_uint32 PcmRut_DspGetFreeSpace(void);
extern kal_bool PcmRut_IsStereo2Mono(void);
extern void PcmRut_GetPcmFromDSP(kal_uint32 *pDst32, kal_uint32 uSpace);
extern void PcmRut_PutPcmToDSP(kal_int32 *pSrc32, kal_int16 *pSrc16, kal_uint32 uLength, const kal_bool fWriteZeroToDsp);
extern void PcmRut_TurnOnPcmRouteInterrupt(void);
extern void PcmRut_TurnOffPcmRouteInterrupt(void);

extern kal_uint32 AVB_WriteData(kal_uint16 *pSrc16, kal_uint32 uSrcWord, kal_bool fMono2Stereo);
extern kal_uint32 SBC_WriteData(kal_uint16 *pSrc16, kal_uint32 uSrcWord, kal_bool fMono2Stereo);
extern kal_bool SBC_IsOn(void);

#if defined(__AUDIO_DSP_LOWPOWER_V2__)
extern kal_bool AUDLP_Check_LowPower_Status(void);
#endif

#endif

