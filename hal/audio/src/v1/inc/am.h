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
 *  am.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Audio Manager Header
 *
 * Author:
 * -------
 * -------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef AM_H
#define AM_H

#include "common_def.h"
#include "l1audio.h"

#define  ASP_TYPE_VOICE       0
#define  ASP_TYPE_PCM_HI      1
#define  ASP_TYPE_DAF         3
#define  ASP_TYPE_I2SBypass   5
#define  ASP_TYPE_AAC         32
#define  ASP_TYPE_AAC_SBR_ARM 34
#define  ASP_TYPE_AWBDEC      64
#define  ASP_TYPE_AMR         1024
#define  ASP_TYPE_IPS         16

#define  ASP_DELM_PCM_HIGFS     576
#define  ASP_DELM_PCM_MEDFS     288
#define  ASP_DELM_PCM_LOWFS     144
#define  ASP_DELM_AAC           2048
#define  ASP_DELM_AMR           320
#define  ASP_DELM_AWBDEC        640
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) || defined(__AUDIO_NOT_SUPPORTED__)
#define  ASP_DELM_I2SBypass     1020 // the number should be should be 6*N 
#else
#error ASP_DELM_I2SBypass not defined!!
#endif

#define  ASP_FRAMELEN_AMR          ASP_DELM_AMR
#define  ASP_FRAMELEN_AWB          ASP_DELM_AWBDEC
#define  ASP_FRAMELEN_AAC          ASP_DELM_AAC
#define  ASP_FRAMELEN_I2S          ASP_DELM_I2SBypass 

#if defined(MT6255) || defined(__AUDIO_NOT_SUPPORTED__)
#define  ASP_FRAMELEN_PCM     0x1D00
#elif defined(MT6250) 
#define  ASP_FRAMELEN_PCM     0x2ACE
#elif defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#define  ASP_FRAMELEN_PCM     0x2000
#else
#error ASP_FRAMELEN_PCM not defined!!
#endif

#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) || defined(__AUDIO_NOT_SUPPORTED__)

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#define  ASP_DSP_PCM_BUFFER_BASE_PCM 0x0
#else
#define  ASP_DSP_PCM_BUFFER_BASE_PCM 0x0500
#endif

#define  ASP_DSP_PCM_BUFFER_BASE_AMR 0x1400
#define  ASP_DSP_PCM_BUFFER_BASE_AWB 0x0C00
#define  ASP_DSP_PCM_BUFFER_BASE_AAC 0x0
#define  ASP_DSP_PCM_BUFFER_BASE_I2S 0x0 
#else
#error ASP_DSP_PCM_BUFFER_BASE_PCM not defined!!
#endif

#define  ASP_FS_8K            0x00
#define  ASP_FS_11K           0x11
#define  ASP_FS_12K           0x12
#define  ASP_FS_16K           0x20
#define  ASP_FS_22K           0x21
#define  ASP_FS_24K           0x22
#define  ASP_FS_32K           0x40
#define  ASP_FS_44K           0x41
#define  ASP_FS_48K           0x42

#define  FLEXI_VBI_ENABLE     0x0001
#define  FLEXI_SE_ENABLE      0x0002
#define  FLEXI_SD_ENABLE      0x0004

#define DL_PATH         0
#define UL_PATH         1
#define DL_UL_BOTH_PATH 2

typedef enum{
   AM_RECORD_NONE = 0, 
   AM_RECORD_8K,
   AM_RECORD_16K
}AM_RECORD_FORMAT; 

void     AM_Init( void );
bool     AM_AudioManager( bool handover,uint16 speech_mode, int8 sub_channel );
void     AM_AudioManager_OS_Tick( void );
void     AM_FlushQFunction( void );
void     AM_FillSilencePattern( volatile uint16 *addr, uint16 info, uint16 speech_mode );
uint16   AM_GetSpeechPatternLength( uint8 speech_mode );
void     AM_GetSilencePattern(kal_uint32 mode, kal_uint16 *pData);
bool     AM_CodecMode_IsLegal(uint8 codec_mode);
void     AM_SpeechOn(uint32 rat_mode);
void     AM_SpeechOff( void );
bool     AM_IsSpeechOn( void );
void     AM_AfeOn(kal_uint32 afe_mode);
void     AM_AfeOff( void );
bool     AM_IsAfeOn( void );
bool     AM_IsAmInSpeechState( void );
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
// MT6260 does not support DAI process
#else   // chip compile option
void     AM_SetDAIMode ( uint8 mode );
bool     AM_IsDAIMode( void );
#endif  // chip compile option
void     AM_WriteFirCoeffs( const int16 *in_coeff, const int16 *out_coeff );
void     AM_GetFirCoeffs(kal_int16 **in_coeff, kal_int16 **out_coeff);
void     AM_VMRecordOn( uint16 speech_mode );
void     AM_VMRecordOff( void );
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
// MT6260 does not support VM playback
#else   // chip compile option
void     AM_VMPlaybackOn( uint16 control, uint32 style );
void     AM_VMPlaybackOff( uint32 style );
void     AM_VMWriteParameter(uint16 sc_mode, uint16 sd_mode, bool isReset);
#endif  // chip compile option
void     AM_MelodyOn( void );
void     AM_MelodyOff( void );
void     AM_KeyToneOn( void );
void     AM_KeyToneOff( void );
void     AM_ToneOn( void );
void     AM_ToneOff( void );
void     AM_PCM8K_PlaybackOn( void );
void     AM_PCM8K_PlaybackOff( bool wait );
void     AM_PCM16K_PlaybackOn( void );       /* PCM16K is for MT6205B only */
void     AM_PCM16K_PlaybackOff( bool wait );

uint32   AM_GetRecordFormat( void );
void     AM_PCM8K_RecordOn( void );
void     AM_PCM8K_RecordOff( bool wait );
void     AM_PCM16K_RecordOn( void );         /*PCM16K recording support 6219 and latter version*/
void     AM_PCM16K_RecordOff( bool wait );
void     AM_AudioPlaybackOn( uint16 asp_type, uint16 asp_fs );
void     AM_AudioPlaybackOff( bool wait );
int16    AM_IsAudioPlaybackOn( void );
bool     AM_IsVMPlaybackOn( void );
void     AM_VRRecordOn( uint32 trainPhase );
void     AM_VRRecordOff( uint32 trainPhase );
void     AM_MuteULSpeech( bool mute );
bool     AM_IsULSpeechMuted( void );
void     AM_PCM_EX_On( uint32 type );
void     AM_PCM_EX_Off( uint32 type );
bool     AM_IsVoIPOn( void );
bool     AM_IsConflictState( void );
bool     AM_IsKeyToneOn( void );
bool     AM_IsToneOn( void );
bool     AM_IsVoiceOn( void );
bool     AM_IsAVsyncOn( void );

// Bluetooth earphone control functions
void     AM_BluetoothOn( uint8 bt_mode);
void     AM_BluetoothOff( void );
bool     AM_IsBluetoothOn( void );
bool     AM_IsBTCordlessMode( void );

// Bluetooth cordkess mode control functions
void     AM_BTCordlessOn( void );
void     AM_BTCordlessOff( void );

// Sound effect control functions
void     AM_SND_PlaybackOn( void );
void     AM_SND_PlaybackOff( bool wait );

// Audio Post Process control functions
void     AM_SetPostProcessCtrl( uint16 ppMask, uint16 ppCtrl );
void     AM_ClearPostProcessCtrl( uint16 ppMask );

// Functions for modem loopback test 
void     AM_SetLoopBackTest( bool enable );
bool     AM_IsLoopBackTest( void );

void     AM_EnableToneLoopBackFlag( kal_bool param );

// InterRAT
void     AM_InterRAT_W2G( void );
void     AM_InterRAT_G2W( void );

// AV Sync
void     AM_AVSync_On( void );
void     AM_AVSync_Off( void );

//block filter run time switch function, used in sp_enhance.c
void     AM_SwitchCompFilter( kal_uint16 par );
//block filter turn on/off
void     AM_TurnOnBlockFilter( void );
void     AM_TurnOffBlockFilter( void );

void     AM_Force_VBI_END_IN_TASK( void );
void     AM_SetSRCCtrl( void );

void     AM_BT_Force_VBI_Reset(kal_bool enable);
kal_bool AM_IsBTForceVBIReset(void);
void     AM_BT_ExecuteVBIReset(void);

bool     AM_IsFWEOn( void );
void     AM_SetFWE(bool on);

#if defined(MT6256) || defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
void     AM_DSP_SetSRCCtrl(uint32 data);
#endif

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
void     AM_VM_EPL_RecordOn(void);
void     AM_VM_EPL_RecordOff(void);
#endif  // chip compile option

// Get DL or UL Path
kal_uint8 AM_GetDLULPath(void);
// PCMNWAY function inside AM 
typedef enum {
    AM_PCMEX_TYPE_DEDICATION = 0,   // under call
    AM_PCMEX_TYPE_IDLE_WO_ENH,      // without call, voice path, no enhancement
    AM_PCMEX_TYPE_IDLE,             // without call, speech quality like, with enhancement
    AM_PCMEX_TYPE_DACA_DEDICATION,  // data card under call (speech on)
    AM_PCMEX_TYPE_DACA_IDLE_WO_ENH, // data card without call, voice path, no enhancement 
    AM_PCMEX_TYPE_DACA_IDLE,        // data card without call, speech quality like, with enhancement
    AM_PCMEX_TYPE_UNDEF = 0xffff,
} AM_PCMEX_TYPE;

extern void l1sp_updateSpeAppMask(uint16 updateFlags, bool enable);
extern void SetSpeechEnhancement(bool ec);

#if defined(__PCM_CLOCK_SWITCH_SUPPORT__)
void AM_PCMClockOn (void);
void AM_PCMClockOff (void);
#endif  // defined(__PCM_CLOCK_SWITCH_SUPPORT__)

#endif


