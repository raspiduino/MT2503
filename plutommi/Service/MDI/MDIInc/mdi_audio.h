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
/*****************************************************************************
 *
 * Filename:
 * ---------
 * mdi_audio.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Audio interfce header file
 *
 * Author:
 * -------
 * -------
 *                      
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MDI_AUDIO_H_
#define _MDI_AUDIO_H_

/*-----------------------------------------------------------------------------
                                include files
-----------------------------------------------------------------------------*/

#include "mdi_datatype.h"
#include "MMIDataType.h"
#include "mmi_frm_gprot.h"
#include "MMI_features.h"
#include "kal_general_types.h"
#include "kal_internal_api.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_res_range_def.h"
#include "mmi_rp_srv_mdi_def.h"
#include "med_main.h"
#include "l1audio.h"
#include "aud_defs.h"
#include "fmr_config_customize.h"


/*-----------------------------------------------------------------------------
                         Audio mode, volume, output device
 ----------------------------------------------------------------------------*/
 
/* Normal Mode */
#define MDI_AUD_MODE_NORMAL             (0)
/* HeadSet (Earphone) Mode */
#define MDI_AUD_MODE_HEADSET            (1)
/* Loudspeaker Mode */
#define MDI_AUD_MODE_LOUDSPK            (2)
#define MDI_MAX_AUD_MODE_NUM            (3)

/* MMI can apply to associate volume; call tone attribute */
#define MDI_VOLUME_CTN                  (0)
/* MMI can apply to associate volume; keypad tone attribute */
#define MDI_VOLUME_KEY                  (1)
/* Microphone attribute */
#define MDI_VOLUME_MIC                  (2)
/* MMI can apply to FM radio attribute */
#define MDI_VOLUME_FMR                  (3)
/* MMI can apply to associate volume; speech sound attribute */
#define MDI_VOLUME_SPH                  (4)
/* side tone attribute */
#define MDI_VOLUME_SID                  (5)
/* MMI can apply to associate volume; As MP3, Wave,... attribute */
#define MDI_VOLUME_MEDIA                (6)
/* TV-OUT */
#define MDI_VOLUME_TVO                  (7)
/* ATV */
#define MDI_VOLUME_ATV                  (8)
/* Max volume type */
#define MDI_MAX_VOLUME_TYPE             (9)
/* Max volume level */
#define MDI_MAX_VOLUME_LEVEL            (7)

/* Tone, Keypad sound to play on audio device. */
#define MDI_DEVICE_SPEAKER              (0)
/* Microphone sound to send on audio device. */
#define MDI_DEVICE_MICROPHONE           (1)
/* Earphone, carkit */
#define MDI_DEVICE_SPEAKER2             (4)
/* Loudspeaker for free sound */
#define MDI_DEVICE_LOUDSPEAKER          (5)
/* Output from earphone and loud speaker */
#define MDI_DEVICE_SPEAKER_BOTH         (6)
/* Used to be OR bitwise with above audio output devices */
#define MDI_DEVICE_BT_HEADSET           (8)

/* Play sound for crescendo. */
#define MDI_AUDIO_PLAY_CRESCENDO        (0)
/* Play sound for infinite. */
#define MDI_AUDIO_PLAY_INFINITE         (1)
/* Play sound for once. */
#define MDI_AUDIO_PLAY_ONCE             (2)
/* Play sound for descendo. */
#define MDI_AUDIO_PLAY_DESCENDO         (3)

/* Input from mic1 */
#define MDI_INPUT_MIC1                  (0)
/* Input from mic2 */
#define MDI_INPUT_MIC2                  (1)
/* Input from FM radio */
#define MDI_INPUT_FMRR                  (2)

/* Audio time stretch speed type number */
#define MDI_AUDIO_MAX_SPEED_NUM         (5)
/* Slowest speed */
#define MDI_AUDIO_SPEED_SLOW2           (50)
/* Slow speed */
#define MDI_AUDIO_SPEED_SLOW1           (80)
/* Normal Speed */
#define MDI_AUDIO_SPEED_NORMAL          (100)
/* Fast speed */
#define MDI_AUDIO_SPEED_FAST1           (125)
/* Fastest speed */
#define MDI_AUDIO_SPEED_FAST2           (160)

/* Exclude 1st(16-level) and 2nd(Mute) bit to get actual volume level*/
#define MDI_AUD_VOL_GET_EX_LEVEL(x)     ((x) & 0x3F)
/* Is 16 Level*/
#define MDI_AUD_VOL_IS_EX_LEVEL(x)      ((x) & 0x80)
/* Is Level 0 is mute */
#define MDI_AUD_VOL_IS_MUTE_LEVEL(x)    ((x) & 0x40)

/* 16 Level*/
#define MDI_AUD_VOL_EX(x)               ((x) | 0x80)
/* 7 Level, Level 0 is mute (2nd bit on), the volume level is 0 ~ 7 */
#define MDI_AUD_VOL_MUTE(x)             ((x) | 0x40)
/* 16 Level, Level 0 is mute(1st , 2nd bit on), the volume level is total 0 ~ 16 */
#define MDI_AUD_VOL_EX_MUTE(x)          ((x) | 0xC0)
/* Audio path macro */
#define MDI_AUD_PTH_EX(x) (x)

/* 7 Level */
#define MDI_AUD_VOL_LEVEL_NORMAL        (1)
/* 7 Level + Level 0 mute */
#define MDI_AUD_VOL_LEVEL_NORMAL_MUTE   (2)
/* 16 Level */
#define MDI_AUD_VOL_LEVEL_EXTEND        (3)
/* 16 Level + Level 0 mute */
#define MDI_AUD_VOL_LEVEL_EXTEND_MUTE   (4)

#define MDI_AUD_BT_SCO_MODE_DEFAULT   (0x00)
#define MDI_AUD_BT_SCO_MODE_FM        (0x01)
#define MDI_AUD_BT_SCO_MODE_ATV       (0x02)
#ifdef __BT_DIALER_SUPPORT__
#define MDI_AUD_BT_SCO_MODE_BT_DIALER (0x04)  //Add For BT Dialer
#endif

/* The information that could be queried */
typedef enum                                    
{                                               
    MDI_AUDIO_GET_INFO_AUDIO_MODE = 0,  /* Audio mode (kal_uint8*) */
    MDI_AUDIO_GET_INFO_AUDIO_PATH,      /* Output path (kal_uint8*) */
    MDI_AUDIO_GET_INFO_AUDIO_TYPE,      /* Audio type (kal_uint8*) */
    MDI_AUDIO_GET_INFO_MEDIA_SOURCE,    /* Media source (kal_uint8*) */
    MDI_AUDIO_GET_INFO_IS_IN_CALL,      /* Is in call (kal_bool*) */
    MDI_AUDIO_GET_INFO_IS_BT_ON,        /* Is BT on (kal_bool*) */
    MDI_AUDIO_GET_INFO_IS_CAMCORDER_ON, /* Is camcorder on (kal_bool*) */
    MDI_AUDIO_GET_INFO_IS_FM_ON,        /* Is FM on (kal_bool*) */
                                                
    MDI_AUDIO_GET_INFO_LAST_ENTRY       /* Last entry */
} mdi_audio_get_info_enum;

/* Tone type */
typedef enum
{
    MDI_AUDIO_TYPE_UNKNOWN = 0,         /* Default as unknown */
    MDI_AUDIO_TYPE_PLAYER,              /* Player */
    MDI_AUDIO_TYPE_RING,                /* Ring tone */
    MDI_AUDIO_TYPE_MESSAGE,             /* Message tone */
    MDI_AUDIO_TYPE_EFFECT,              /* Effect tone */
    MDI_AUDIO_TYPE_ALERT,               /* Alert tone */
    MDI_AUDIO_TYPE_POWER_OFF,           /* Power-off tone */

    MDI_AUDIO_TYPE_LAST_ENTRY           /* Last entry */
} mdi_audio_type_enum;

/* Media source */
typedef enum
{
    MDI_AUDIO_MEDIA_SOURCE_UNKNOWN = 0, /* Unknown */
    MDI_AUDIO_MEDIA_SOURCE_MIDI,        /* MIDI/IMY */
    MDI_AUDIO_MEDIA_SOURCE_AMR,         /* AMR/WAV/3GP */
    MDI_AUDIO_MEDIA_SOURCE_MP3,         /* MP3 and the others */

    MDI_AUDIO_MEDIA_SOURCE_LAST_ENTRY   /* Last entry */
} mdi_audio_media_source_enum;

/* Reason of volume update */
typedef enum
{
    MDI_AUDIO_VOLUME_UPDATE_REASON_AUDIO_MODE_CHANGED,     /* Audio mode is changed (audio mode) */
    MDI_AUDIO_VOLUME_UPDATE_REASON_SPEECH_STATE_CHANGED,   /* Speech state is changed (TRUE: on, FALSE: off) */
    MDI_AUDIO_VOLUME_UPDATE_REASON_SPEECH_VOLUME_CHANGED,  /* Speech volume is changed (volume level) */
    MDI_AUDIO_VOLUME_UPDATE_REASON_KEYPAD_VOLUME_CHANGED,  /* Keypad volume is changed (volume level) */
    MDI_AUDIO_VOLUME_UPDATE_REASON_SCO_CONNECT,            /* SCO is connected (NULL) */
    MDI_AUDIO_VOLUME_UPDATE_REASON_SCO_DISCONNECT,         /* SCO is disconnected (NULL) */
    MDI_AUDIO_VOLUME_UPDATE_REASON_A2DP_CONNECT,           /* A2DP is connected (NULL) */
    MDI_AUDIO_VOLUME_UPDATE_REASON_A2DP_DISCONNECT,        /* A2DP is disconnected (NULL) */
    MDI_AUDIO_VOLUME_UPDATE_REASON_ATV_ON,                 /* ATV is on (NULL) */
    MDI_AUDIO_VOLUME_UPDATE_REASON_ATV_OFF,                /* ATV is off (NULL) */
    MDI_AUDIO_VOLUME_UPDATE_REASON_CAMCORDER_STATE_CHANGED,/* Camcorder state is changed (TRUE: on, FALSE:off) */
    MDI_AUDIO_VOLUME_UPDATE_REASON_FM_STATE_CHANGED,       /* FM state is changed (TRUE: on, FALSE: off) */
    MDI_AUDIO_VOLUME_UPDATE_REASON_RECORD_STATE_CHANGED,   /* Record state is changed (TRUE: on, FALSE: off) */
    MDI_AUDIO_VOLUME_UPDATE_REASON_VIDEO_PLAYBACK,         /* Video playback (media type) */
    MDI_AUDIO_VOLUME_UPDATE_REASON_MMA_PLAYBACK,           /* MMA playback (mma type) */
    
    MDI_AUDIO_VOLUME_UPDATE_REASON_LAST_ENTRY
} mdi_audio_volume_update_reason_enum;

/* Audio volume level enum for 7 level volume */
typedef enum
{
    MDI_AUD_VOL_0,      /* Volume level 0 (Not mute) */
    MDI_AUD_VOL_1,      /* Volume level 1 */
    MDI_AUD_VOL_2,      /* Volume level 2 */
    MDI_AUD_VOL_3,      /* Volume level 3 */
    MDI_AUD_VOL_4,      /* Volume level 4 */
    MDI_AUD_VOL_5,      /* Volume level 5 */
    MDI_AUD_VOL_6,      /* Volume level 6 */
    MDI_AUD_VOL_NUM     /* Total volume level */
} MDI_AUD_VOL_ENUM;

/* Audio volume level enum for 16 level volume */
typedef enum
{
    MDI_AUD_VOL_EX_0,   /* Volume level 0 (Not mute) */
    MDI_AUD_VOL_EX_1,   /* Volume level 1 */
    MDI_AUD_VOL_EX_2,   /* Volume level 2 */
    MDI_AUD_VOL_EX_3,   /* Volume level 3 */
    MDI_AUD_VOL_EX_4,   /* Volume level 4 */
    MDI_AUD_VOL_EX_5,   /* Volume level 5 */
    MDI_AUD_VOL_EX_6,   /* Volume level 6 */
    MDI_AUD_VOL_EX_7,   /* Volume level 7 */
    MDI_AUD_VOL_EX_8,   /* Volume level 8 */
    MDI_AUD_VOL_EX_9,   /* Volume level 9 */
    MDI_AUD_VOL_EX_10,  /* Volume level 10 */
    MDI_AUD_VOL_EX_11,  /* Volume level 11 */
    MDI_AUD_VOL_EX_12,  /* Volume level 12 */
    MDI_AUD_VOL_EX_13,  /* Volume level 13 */
    MDI_AUD_VOL_EX_14,  /* Volume level 14 */
    MDI_AUD_VOL_EX_15,  /* Volume level 15 */
    MDI_AUD_VOL_EX_NUM  /* Total volume level */
} MDI_AUD_VOL_EX_ENUM;

/* The minimum volume of 16 level volume + mute level (mute) */
#define MDI_AUD_VOL_EX_MUTE_MIN 0
/* The maximum volume of 16 level volume + mute level (mute) */
#define MDI_AUD_VOL_EX_MUTE_MAX 16

/*-----------------------------------------------------------------------------
                               Audio Format
 ----------------------------------------------------------------------------*/
 
/* Audio return codes */
typedef enum
{
    MDI_FORMAT_NONE          = -1,                       /* Not a supported audio type */
    MDI_FORMAT_GSM_FR        = MED_TYPE_GSM_FR,          /* 0  : GSM full rate */
    MDI_FORMAT_GSM_HR        = MED_TYPE_GSM_HR,          /* 1  : GSM half rate*/
    MDI_FORMAT_GSM_EFR       = MED_TYPE_GSM_EFR,         /* 2  : GSM enhance full rate */
    MDI_FORMAT_AMR           = MED_TYPE_AMR,             /* 3  : AMR */
    MDI_FORMAT_AMR_WB        = MED_TYPE_AMR_WB,          /* 4  : Wideband AMR */
    MDI_FORMAT_DAF           = MED_TYPE_DAF,             /* 5  : Digital audio format */
    MDI_FORMAT_AAC           = MED_TYPE_AAC,             /* 6  : AAC */
    MDI_FORMAT_PCM_8K        = MED_TYPE_PCM_8K,          /* 7  : PCM 8K data */
    MDI_FORMAT_PCM_16K       = MED_TYPE_PCM_16K,         /* 8  : PCM 17K data */
    MDI_FORMAT_G711_ALAW     = MED_TYPE_G711_ALAW,       /* 9  : G711 A-Law data */
    MDI_FORMAT_G711_ULAW     = MED_TYPE_G711_ULAW,       /* 10 : G711 Mu-law data */
    MDI_FORMAT_DVI_ADPCM     = MED_TYPE_DVI_ADPCM,       /* 11 : DVI-ADPCM data */
    MDI_FORMAT_VR            = MED_TYPE_VR,              /* 12 : Voice Recognition tag format */
    MDI_FORMAT_WAV           = MED_TYPE_WAV,             /* 13 : WAV */
    MDI_FORMAT_WAV_ALAW      = MED_TYPE_WAV_ALAW,        /* 14 : WAV A-law */
    MDI_FORMAT_WAV_ULAW      = MED_TYPE_WAV_ULAW,        /* 15 : WAV Mu-law */
    MDI_FORMAT_WAV_DVI_ADPCM = MED_TYPE_WAV_DVI_ADPCM,   /* 16 : WAV DVI-ADPCM */
    MDI_FORMAT_SMF           = MED_TYPE_SMF,             /* 17 : MIDI */
    MDI_FORMAT_IMELODY       = MED_TYPE_IMELODY,         /* 18 : IMELODY */
    MDI_FORMAT_SMF_SND       = MED_TYPE_SMF_SND,         /* 19 : MIDI sound */
    MDI_FORMAT_MMF           = MED_TYPE_MMF,             /* 20 : MMF */
    MDI_FORMAT_AU            = MED_TYPE_AU,              /* 21 : AU */
    MDI_FORMAT_AIFF          = MED_TYPE_AIFF,            /* 22 : AIFF */
    MDI_FORMAT_VRSI          = MED_TYPE_VRSI,            /* 23 : VRSI tage format */
    MDI_FORMAT_WMA           = MED_TYPE_WMA,             /* 24 : WMA */
    MDI_FORMAT_M4A           = MED_TYPE_M4A,             /* 25 : M4A */
    MDI_FORMAT_BSAC          = MED_TYPE_BSAC,            /* 31 : BSAC */
    MDI_FORMAT_MUSICAM       = MED_TYPE_MUSICAM,         /* 32 : MUSICAM */
    MDI_FORMAT_APE           = MED_TYPE_APE,             /* 42 : APE */
    MDI_FORMAT_VORBIS        = MED_TYPE_VORBIS,          /* OGG */
    MDI_FORMAT_FLAC          = MED_TYPE_FLAC,            /* FLAC */
    MDI_FORMAT_KURO          = MED_TYPE_KURO,            /* 43 : Proprierary kuro format */
    MDI_FORMAT_KURO_AAC      = MED_TYPE_KURO_AAC,        /* 44 : Proprierary kuro AAC format */
    MDI_FORMAT_RMVB          = MED_TYPE_RMVB,            /* 45 : RMVB */
    MDI_FORMAT_RM            = MED_TYPE_RM,              /* 46 : RM */
    MDI_FORMAT_RA            = MED_TYPE_RA,              /* 47 : RA */
    MDI_FORMAT_RV            = MED_TYPE_RV,              /* 48 : RV */
    MDI_FORMAT_MIDI          = MED_TYPE_MIDI,            /* 49 : JMidi */
    MDI_FORMAT_TONE          = MED_TYPE_TONE,            /* 50 : JTone */
    MDI_FORMAT_3GP           = MED_TYPE_3GP,             /* 51 : 3GP */
    MDI_FORMAT_MP4           = MED_TYPE_MP4,             /* 52 : MP4 */
    MDI_FORMAT_JPG           = MED_TYPE_JPG,             /* 53 : JPG */
    MDI_FORMAT_GIF           = MED_TYPE_GIF,             /* 54 : GIF image */
    MDI_FORMAT_MJPG          = MED_TYPE_MJPG,            /* 55 : Motion JPEG */
    MDI_FORMAT_PNG           = MED_TYPE_PNG,             /* 56 : PNG image */
    MDI_FORMAT_AVI           = MED_TYPE_AVI,             /* 57 : AVI */
    MDI_FORMAT_FLV           = MED_TYPE_FLV,             /* 59 : FLV */
    MDI_FORMAT_F4V           = MED_TYPE_F4V,             /* 60 : F4V */
    MDI_FORMAT_F4A           = MED_TYPE_F4A,             /* 63 : F4A */
    
    MDI_NO_OF_FORMAT                                     /* Total format number */
} MDI_FORMAT_ENUM;

/*-----------------------------------------------------------------------------
                              State Relative
 ----------------------------------------------------------------------------*/
 
/* Audio state enum */
typedef enum
{
    MDI_AUDIO_IDLE,                 /* Idle state */
    MDI_AUDIO_PLAY,                 /* Play state */
    MDI_AUDIO_PLAY_PAUSED,          /* Play paused state */
    MDI_AUDIO_RECORD,               /* Record state */
    MDI_AUDIO_RECORD_PAUSED,        /* Record paused state */
    MDI_AUDIO_SPEECH_ON,            /* Speech mode on state */
    MDI_AUDIO_VRSI_PROCESS,         /* VRSI processing state */
    MDI_AUDIO_TRIM,                 /* Trim state */
    MDI_NO_AUDIO_STATE              /* Total state number */
} MDI_AUDIO_STATE_ENUM;

/* Audio mode enum */
typedef enum
{
    MDI_AUDIO_PLAY_KT,              /* Play a keytone */
    MDI_AUDIO_PLAY_TONE,            /* Play a DTMF tone */
    MDI_AUDIO_PLAY_ID,              /* Play an audio resource ID */
    MDI_AUDIO_PLAY_STRING,          /* Play an audio from memory */
    MDI_AUDIO_PLAY_FILE,            /* Play an audio from file */
    MDI_AUDIO_RECORD_FILE,          /* Record audio to file */
    MDI_AUDIO_RECORD_FM_RADIO,      /* Record audio to file from FM radio */
    MDI_AUDIO_PLAY_FM_RADIO,        /* Play FM Radio */
    MDI_AUDIO_RECORD_VR_VOICE,      /* Receive voice for VR */
    MDI_AUDIO_VRSI_PLAY_TTS,        /* Play TTS for VRSI */
    MDI_AUDIO_VRSI_PLAY_TAG,        /* Play voice tag for VRSI */
    MDI_AUDIO_VRSI_RECORD,          /* Receive voice for VRSI */
    MDI_AUDIO_PLAY_TTS,             /* Play a general TTS */
    MDI_AUDIO_PLAY_IN_OTHER_TASK,   /* Play request by other task (not MMI) */
    MDI_AUDIO_PLAY_VIA_SCO,         /* Play audio via SCO */
    MDI_AUDIO_PLAY_MMA,             /* Play MMA */
    MDI_AUDIO_PLAY_ANY,             /* Play any audio */
#ifdef __BT_SPEAKER_SUPPORT__
	MDI_AUDIO_PLAY_BT_MUSIC,		/* Audio player */
#endif
    MDI_NO_AUDIO_MODE               /* Total audio mode */
} MDI_AUDIO_PLAY_MODE_ENUM;

/* Bluetooth audio path state */
typedef enum
{
    MDI_AUDIO_BT_STATE_IDLE,        /* Idle state */
    MDI_AUDIO_BT_STATE_WAIT_OPEN,   /* Wait open response state */
    MDI_AUDIO_BT_STATE_OPEN,        /* Open state */
    MDI_AUDIO_BT_STATE_WAIT_CLOSE   /* Wait close response state */
} MDI_AUDIO_BT_STATE_ENUM;

/*-----------------------------------------------------------------------------
                              Background play
 ----------------------------------------------------------------------------*/
 
/* Background play audio application enum */
typedef enum
{
#ifdef __MMI_FM_RADIO__
    MDI_BACKGROUND_APP_FMR,         /* FM radio */
#endif
#ifdef __MMI_AUDIO_PLAYER__
    MDI_BACKGROUND_APP_AUDPLY,      /* Audio player */
#endif
#ifdef __MMI_BTBOX_NOLCD__
    MDI_BACKGROUND_APP_BT_AUDPLY,
#endif
#if defined(__MMI_MEDIA_PLAYER__) || defined(__COSMOS_MUSICPLY__) || defined(__MMI_MUSIC_PLAYER_SLIM__)
    MDI_BACKGROUND_APP_MEDPLY,      /* Media player */
#endif
#ifdef __J2ME__
    MDI_BACKGROUND_APP_JAVA,        /* JAVA */
#endif
    MDI_BACKGROUND_APP_MRE,         /* For MRE applications */
#ifdef OPERA_V10_BROWSER
    MDI_BACKGROUD_APP_OPERA,
#endif
#ifdef __BT_SPEAKER_SUPPORT__
		MDI_BACKGROUND_APP_BT_MUSIC,		/* Audio player */
#endif

#if defined(__MMI_BTBOX_NOLCD__) || defined(__MMI_MEGAPHONE__)
		MDI_BACKGROUND_APP_MEGAPHONE,		/* Media player */
#endif

    /* New background application enum shall add before here */
    MDI_BACKGROUND_APP_TOTAL       /* Total background application number */
} MDI_BACKGROUND_APP;

/* Maximum number of anonymous apps that could suspend background play */
#define MDI_MAX_ANON_APP_NUM        (4)

/* Application that will suspend background enum */
typedef enum
{
    MDI_AUD_SUSPEND_BG_JAVA,        /* JAVA */
    MDI_AUD_SUSPEND_BG_UCM,         /* Unified call management */
    MDI_AUD_SUSPEND_BG_SCO_INQ,     /* BT HFP SCO link */
    MDI_AUD_SUSPEND_BG_FMGR,        /* FMGR */
    MDI_AUD_SUSPEND_BG_ASYNC_APP,   /* Suspend from non-MMI task */
#ifdef __BT_DIALER_SUPPORT__
    MDI_AUD_SUSPEND_BG_UCM_BT,      /* UCM bt */
#endif
    MDI_AUD_SUSPEND_BG_ANON_APP,    /* Anonymous apps */
    MDI_AUD_SUSPEND_BG_TOTAL = MDI_AUD_SUSPEND_BG_ANON_APP + MDI_MAX_ANON_APP_NUM /* Total application */
} MDI_AUD_SUSPEND_BG_APP;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint16 app_id;
    void *cb_hdlr;
    void *user_data;
} mmi_mdi_suspend_background_play_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 profile;
    kal_uint16 connect_id;
} mmi_mdi_bt_open_stream_req_struct;

typedef struct
{
   U16 sampleRate;
   MMI_BOOL stereo;
} mdi_fmr_audio_info_struct;

/*-----------------------------------------------------------------------------
                                    Speech
 ----------------------------------------------------------------------------*/
 
/* Speech type enum */
typedef enum
{
    MDI_AUDIO_SPEECH_APP_ID_NONE,   /* No type */
    MDI_AUDIO_SPEECH_APP_ID_GSM,    /* GSM */
    MDI_AUDIO_SPEECH_APP_ID_WCDMA,  /* WCDMA */
/* DOM-NOT_FOR_SDK-BEGIN */
    MDI_AUDIO_SPEECH_APP_ID_SIM2,   /* Phase out, use GSM for all SIM */
/* DOM-NOT_FOR_SDK-END */
    MDI_AUDIO_SPEECH_APP_ID_VOIP,   /* VoIP Call */
    MDI_AUDIO_SPEECH_APP_ID_3G324M  /* 3G324M video call */
} MDI_AUDIO_SPEECH_APP_ID_ENUM;

/* Speech event */
typedef enum
{
    MDI_AUDIO_SPH_PRE_SPEECH_ON,
    MDI_AUDIO_SPH_POST_SPEECH_ON,
    MDI_AUDIO_SPH_PRE_SPEECH_OFF,
    MDI_AUDIO_SPH_POST_SPEECH_OFF,

    MDI_AUDIO_SPH_PRE_VOIP_ENCODE_START,
    MDI_AUDIO_SPH_POST_VOIP_ENCODE_START,
    MDI_AUDIO_SPH_PRE_VOIP_ENCODE_STOP,
    MDI_AUDIO_SPH_POST_VOIP_ENCODE_STOP,
    MDI_AUDIO_SPH_PRE_VOIP_DECODE_START,
    MDI_AUDIO_SPH_POST_VOIP_DECODE_START,
    MDI_AUDIO_SPH_PRE_VOIP_DECODE_STOP,
    MDI_AUDIO_SPH_POST_VOIP_DECODE_STOP,
    MDI_AUDIO_SPH_TOTAL
} mmi_mdi_audio_speech_status_ind_enum;

/* Speech state */
typedef struct 
{
    MMI_EVT_PARAM_HEADER
    mmi_mdi_audio_speech_status_ind_enum status;
    U8 session_id;
} mmi_evt_mdi_audio_speech_ind_struct; 

typedef struct 
{
    MMI_EVT_PARAM_HEADER
    U8 pre_mode;
    U8 new_mode;
} mmi_evt_mdi_audio_mode_switch_struct; 


/*-----------------------------------------------------------------------------
                                    Record
 ----------------------------------------------------------------------------*/
 
/* Audio record quality enum */
typedef enum
{
    MDI_AUDIO_REC_QUALITY_LOW,      /* Low quality */
    MDI_AUDIO_REC_QUALITY_MED,      /* Medium quality */
    MDI_AUDIO_REC_QUALITY_HIGH,     /* High quality */
    MDI_AUDIO_REC_QUALITY_AUTO      /* Auto profile */
} MDI_AUDIO_REC_QUALITY_ENUM;

/* Record profile */
typedef enum {
    MDI_AUDIO_REC_MODE_IDLE,        /* Idle record */
    MDI_AUDIO_REC_MODE_SPEECH,      /* In-call record */
    MDI_AUDIO_REC_MODE_FMR,         /* FMR record */
    MDI_AUDIO_REC_MODE_ATV          /* ATV record */
} MDI_AUDIO_REC_MODE_ENUM;

typedef struct {
   MDI_FORMAT_ENUM format;          /* Media format */
   kal_uint32      byte_rate;       /* Byte per second */
   kal_wchar       file_ext[5];     /* File extension */
} mdi_audio_rec_param_struct;

/*-----------------------------------------------------------------------------
                                     MMA
 ----------------------------------------------------------------------------*/

/* Parameters */
typedef enum {
    MDI_MMA_PARAM_SET_ASYNC_MODE = AUD_MMA_PARAM_SET_ASYNC_MODE,   /* set async mode for playback, stop action */
    MDI_MMA_PARAM_TOTAL
} MDI_MMA_PARAM_ENUM;


typedef struct
{
    U16               app_id;       /* App ID. This is required for RM playback. Don't care for other formats */
    void*             file_name;    /* File name. NULL if using string data */
    void*             data;         /* String data. NULL if using file name */
    U32               data_len;     /* The length of string data. Don't care if using file name */
    U8                mdi_format;   /* The format of string data. Don't care if using file name */
    U8                repeats;      /* Repate times */
    U8                output_path;  /* Output path. Use MDI_DEVICE_SPEAKER2 for default setting */
    MMI_BOOL          is_pdl;       /* Progressive download. Supported on file name playback only */
    mdi_mma_callback  callback;     /* Callback function */
    void*             user_data;    /* User data */
    mdi_handle*       handle_p;     /* MMA handle. 0 if failed to open */
} mdi_mma_open_struct;

/*-----------------------------------------------------------------------------
                                  Audio Clipper
 ----------------------------------------------------------------------------*/
 
/* Audio clipper get */
typedef enum
{ 
    MDI_TRIM_GET_CURRENT_TIME,      /* Get current time of trimming (kal_uint32*) */

    MDI_TRIM_GET_LAST_ENTRY
} MDI_TRIM_GET_TYPE_ENUM;

/* Audio clipper set */
typedef enum
{ 
    MDI_TRIM_SET_START_TIME,        /* Set start time (kal_uint32) */
    MDI_TRIM_SET_STOP_TIME,         /* Set stop time (kal_uint32) */
    MDI_TRIM_SET_CACHE_TABLE,       /* Set build cache table (kal_uint8*) */

    MDI_TRIM_SET_LAST_ENTRY
} MDI_AUD_TRIM_SET_TYPE_ENUM;

/*-----------------------------------------------------------------------------
                                    FMR
 ----------------------------------------------------------------------------*/

#ifdef __MMI_FM_RADIO__
#define MDI_FMR_MIN_FREQ                   FM_RADIO_MIN_FREQ //(875)
#define MDI_FMR_MAX_FREQ                   FM_RADIO_MAX_FREQ //(1080)
#define MDI_FMR_BANDWIDTH                  (MDI_FMR_MAX_FREQ - MDI_FMR_MIN_FREQ + 1)

#define MDI_FMR_SEEK_SAPCE                 (100)

typedef enum
{
    MDI_FMR_STATE_IDLE = 0,  /* Idle */
    MDI_FMR_STATE_SCAN,      /* Scanning */
    MDI_FMR_STATE_SEEK       /* Seeking */
} mdi_fmr_state_enum;


/* Seek stop criteria */
typedef enum
{
    MDI_FMR_SEEK_STOP_AT_BOUNDARY,         /* Seeking will be stopped at min/max boundary */
    MDI_FMR_SEEK_STOP_AT_FULL_CIRCLE       /* Seeking will be stopped when coming full circle */
} mdi_fmr_seek_stop_enum;

/* Sorting method */
typedef enum
{
    MDI_FMR_SORTING_BY_FREQ,               /* Sorting scanned channels by frequency */
    MDI_FMR_SORTING_BY_SIGNAL_LEVEL        /* Sorting scanned channels by signal level */
} mdi_fmr_sorting_enum;

/* Callback reason */
typedef enum
{
    MDI_FMR_CB_REASON_DONE,                /* Scan/seek is done (callback data: the number of channels that have been scanned */
    MDI_FMR_CB_REASON_PROCESS,             /* Scan/seek is processing (callback data: processing frequence) */
    MDI_FMR_CB_REASON_ABORT                /* Scan/seek is aborted for some reason (callback data: NULL) */
} mdi_fmr_cb_reason_enum;

/* Callback functions */
typedef void (*mdi_fmr_scan_cb_fct)(
            mdi_fmr_cb_reason_enum result, /* Callback reason */
            void* cb_data,                 /* Callback data (depends on callback reason, reference to mdi_fmr_cb_reason_enum) */
            void* user_data);              /* User data */

typedef void (*mdi_fmr_seek_cb_fct)(
            mdi_fmr_cb_reason_enum result, /* Callback reason */
            U16 stop_freq,                 /* Stop frequence of the seek */
            MMI_BOOL is_valid,             /* Indicate if the stop frequence is valid */
            void* user_data);              /* User data */

/* Scan request */
typedef struct
{
    U8                    sorting;         /* Sorting method (mdi_fmr_sorting_enum) */
    U8                    max_channel;     /* The maximum number of channels to be scanned */
    U16*                  channel_list;    /* The list containing the scanned channels. Note that caller should provide buffer to store up to maximum channels. */
    mdi_fmr_scan_cb_fct   callback;        /* Callback function */
    void*                 user_data;       /* User data */
    
} mdi_fmr_scan_req_struct;

/* Seek request */
typedef struct
{
    U16                   start_freq;      /* Start frequency */
    MMI_BOOL              is_step_up;      /* Is step up? */
    U8                    stop_criteria;   /* Stop criteria (mdi_fmr_seek_stop_enum) */
    mdi_fmr_seek_cb_fct   callback;        /* Callback function */
    void*                 user_data;       /* User data */
    
} mdi_fmr_seek_req_struct;

typedef struct
{
    U8                    sorting;
    U8                    max_channel;
    U16*                  channel_list;
    mdi_fmr_scan_cb_fct   callback;
    void*                 user_data;
} mdi_fmr_scan_hdlr_struct;

typedef struct
{
    U16                   start_freq;
    U16                   stop_freq;
    MMI_BOOL              is_step_up;
    mdi_fmr_seek_cb_fct   callback;
    void*                 user_data;
} mdi_fmr_seek_hdlr_struct;

#ifdef __FM_RADIO_RDS_SUPPORT__
typedef enum
{
    MDI_RDS_FLAG_IS_TP				= 0x0001, /* Program is a traffic program */
    MDI_RDS_FLAG_IS_TA				= 0x0002, /* Program broadcasts a traffic ann. */
    MDI_RDS_FLAG_IS_MUSIC			= 0x0004, /* Program broadcasts music */
    MDI_RDS_FLAG_IS_STEREO			= 0x0008, /* Program is transmitted in stereo */
    MDI_RDS_FLAG_IS_ARTIFICIAL_HEAD	= 0x0010, /* Program is an artificial head recording */
    MDI_RDS_FLAG_IS_COMPRESSED		= 0x0020, /* Program content is compressed */
    MDI_RDS_FLAG_IS_DYNAMIC_PTY		= 0x0040, /* Program type can change  */
    MDI_RDS_FLAG_TEXT_AB			= 0x0080, /* If this flag changes state, a new radio text string begins */
    MDI_RDS_INVALID_FLAG
} MDI_AUDIO_RDS_FLAG;


typedef enum
{
    MDI_RDS_EVENT_FLAGS			    = 0x0001,
    MDI_RDS_EVENT_PI_CODE			= 0x0002,
    MDI_RDS_EVENT_PTY_CODE		    = 0x0004,
    MDI_RDS_EVENT_PROGRAMNAME	    = 0x0008,
    MDI_RDS_EVENT_LOCDATETIME		= 0x0010,
    MDI_RDS_EVENT_UTCDATETIME		= 0x0020,
    MDI_RDS_EVENT_LAST_RADIOTEXT	= 0x0040,
    MDI_RDS_EVENT_AF				= 0x0080,
    MDI_RDS_EVENT_AF_LIST			= 0x0100,
    MDI_RDS_EVENT_AFON_LIST		    = 0x0200,
    MDI_RDS_EVENT_TAON				= 0x0400,
    MDI_RDS_EVENT_TAON_OFF		    = 0x0800,
    MDI_RDS_EVENT_RDS		        = 0x2000,
    MDI_RDS_EVENT_NO_RDS		    = 0x4000,
    MDI_RDS_EVENT_RDS_TMER		    = 0x8000,
    MDI_RDS_INVALID_EVENT
} MDI_AUDIO_RDS_EVENT;

typedef struct 
{
    U16 freq;
    U16 data[FM_RDS_MAX_DATA_BUFF_SIZE];
    U16 data_len;
    U16 flag;
    U16 event;
}mdi_rds_event_struct;
#endif /* __FM_RADIO_RDS_SUPPORT__ */ 

#endif /* __MMI_FM_RADIO__*/

/*-----------------------------------------------------------------------------
                                   Internal Use
 ----------------------------------------------------------------------------*/
 
/* DOM-NOT_FOR_SDK-BEGIN */

#ifdef __GENERAL_TTS__
/*
*  TTS defines
*/
/* English */
#define	MDI_TTS_LANG_ENG                (0x1)
/* Taiwan-accent Chinese */
#define	MDI_TTS_LANG_TWN                (0x2)
/* Mandarin */
#define	MDI_TTS_LANG_MDN                (0x4)

/* General Purpose TTS */
#define	MDI_TTS_TYPE_GENERAL            (0x1)
/* Dictionary */
#define	MDI_TTS_TYPE_DIC                (0x2)
/* Name */
#define	MDI_TTS_TYPE_NAME               (0x4)
/* GPS, traffic guiding */
#define	MDI_TTS_TYPE_GPS                (0x8)
/* Weather report */
#define	MDI_TTS_TYPE_WEATHER            (0x10)
/* Stock report */
#define	MDI_TTS_TYPE_STOCK              (0x20)

/* Male */
#define	MDI_TTS_GENDER_MALE             (0x1)
/* Female */
#define	MDI_TTS_GENDER_FEMALE           (0x2)
/* Boy */
#define	MDI_TTS_GENDER_BOY              (0x4)
/* Girl */
#define	MDI_TTS_GENDER_GIRL             (0x8)

/* TTS attribute enum */
typedef enum
{
    MDI_TTS_ATTR_INPUT_CODEPAGE,    /* Input code page, e.g. GBK */
    MDI_TTS_ATTR_TEXT_SCOPE,        /* Text scope, e.g. number */
    MDI_TTS_ATTR_INPUT_MODE,        /* Input mode, e.g. from fixed buffer, from callback */
    MDI_TTS_ATTR_PROGRESS_CALLBACK, /* Progress callback entry */
    MDI_TTS_ATTR_READ_DIGIT,        /* How to read digit, e.g. read as number, read as value  */
    MDI_TTS_ATTR_CHINESE_NUMBER_1,  /* How to read number "1" in Chinese */
    MDI_TTS_ATTR_PHONEME_WATCH,     /* How to watch phoneme, e.g. Chinese Pin-Yin */
    MDI_TTS_ATTR_WATCH_CALLBACK,    /* Watch callback entry */
    MDI_TTS_ATTR_SPEAK_STYLE,       /* Speak style */
    MDI_TTS_ATTR_TOTAL
}MDI_TTS_ATTR_ENUM;

/* General TTS input text type enum */
typedef enum
{
    MDI_TTS_STR_TEXT,               /* Regard input as normal text */
    MDI_TTS_STR_PHN_SBL,            /* Regard input as phonetic symbol */
    MDI_TTS_STR_CHAR                /* Regard input as character set */
} MDI_AUD_TTS_STR_TYPE;

/* General TTS data structure */
typedef struct {
    U16 *text_string;               /* Data string pointer */
    U16 str_type;                   /* String Type */
    U16 lang;                       /* Language */
    U16 app_type;                   /* Application Type */
    U16 gander;                     /* Gender */
    U16 app_id;                     /* App ID */
    U8 volume;                      /* Volume, from 0~6 */
    U8 path;                        /* Audio Path */
    U8 pitch;                       /* Audio Pitch, from 0~100 */
    U8 speed;                       /* Audio Speed, from 0~100 */
    mdi_ext_callback callback;      /* Callback function */
    void *user_data;                /* User data */
} mdi_audio_tts_struct;

/* GBK (default) */
#define MDI_TTS_VALUE_CODEPAGE_GBK      (936)
/* Big5 */
#define MDI_TTS_VALUE_CODEPAGE_BIG5     (950)
/* UTF-16 little-endian */
#define MDI_TTS_VALUE_CODEPAGE_UTF16LE  (1200)
/* UTF-16 big-endian */
#define MDI_TTS_VALUE_CODEPAGE_UTF16BE  (1201)
#endif /*__GENERAL_TTS__*/

/* MDI Audio Mutex */
#if defined(__J2ME__)
#define MDI_AUDIO_LOCK          mdi_audio_mutex_lock(basename(__FILE__),__LINE__)
#define MDI_AUDIO_LOCK_NO_WAIT  mdi_audio_mutex_lock_no_wait(basename(__FILE__),__LINE__)
#define MDI_AUDIO_UNLOCK        mdi_audio_mutex_unlock(basename(__FILE__),__LINE__)
#else
#define MDI_AUDIO_LOCK
#define MDI_AUDIO_LOCK_NO_WAIT
#define MDI_AUDIO_UNLOCK
#endif /*#if defined(__J2ME__)*/

/* DOM-NOT_FOR_SDK-END */

/*-----------------------------------------------------------------------------
                             Audio Playback
 ----------------------------------------------------------------------------*/
 
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_id
 * DESCRIPTION
 *  This function is to play audio id.
 * PARAMETERS
 *  audio_id        : [IN] Audio resource id
 *  play_style      : [IN] Play style
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS   : Starts to play successfully
 *  MDI_AUDIO_BUSY      : The audio resource is occupied by recording
 *  MDI_AUDIO_FAIL      : Play resource fail
 *****************************************************************************/
extern mdi_result mdi_audio_play_id(U16 audio_id, U8 play_style);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_id_with_vol_path
 * DESCRIPTION
 *  This function is to play audio id along with volume and output path.
 * PARAMETERS
 *  audio_id        : [IN] Audio resource id
 *  play_style      : [IN] Play style
 *  volume          : [IN] Audio volume
 *  path            : [IN] Audio output path
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS   : Starts to play successfully
 *  MDI_AUDIO_BUSY      : The audio resource is occupied by recording
 *  MDI_AUDIO_FAIL      : Play resource fail
 *****************************************************************************/
extern mdi_result mdi_audio_play_id_with_vol_path(
                    U16 audio_id,
                    U8 play_style,
                    U8 volume,
                    U8 path);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_string
 * DESCRIPTION
 *  This function is to play audio string.
 * PARAMETERS
 *  audio_data      : [IN] Buffer pointer for audio data
 *  len             : [IN] Audio data length
 *  format          : [IN] Audio data format
 *  play_style      : [IN] Play style
 *  handler         : [IN] Callback handler
 *  user_data       : [IN] User data
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS       : Starts to play successfully
 *  MDI_AUDIO_BUSY          : The audio resource is occupied by recording
 *  MDI_AUDIO_FAIL          : Play audio buffer data fail
 *  MDI_AUDIO_BAD_FORMAT    : Driver can not decode audio buffer
 *****************************************************************************/
extern mdi_result mdi_audio_play_string(
                    void *audio_data,
                    U32 len,
                    U8 format,
                    U8 play_style,
                    mdi_ext_callback handler,
                    void *user_data);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_string_with_vol_path
 * DESCRIPTION
 *  This function is to play audio string along with volume and output path.
 * PARAMETERS
 *  audio_data      : [IN] Buffer pointer for audio data
 *  len             : [IN] Audio data length
 *  format          : [IN] Audio data format
 *  play_style      : [IN] Play style
 *  handler         : [IN] Callback handler
 *  user_data       : [IN] User data
 *  volume          : [IN] Audio volume
 *  path            : [IN] Audio output path
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS       : Starts to play successfully
 *  MDI_AUDIO_BUSY          : The audio resource is occupied by recording
 *  MDI_AUDIO_FAIL          : Play audio buffer data fail
 *  MDI_AUDIO_BAD_FORMAT    : Driver can not decode audio buffer
 *****************************************************************************/
extern mdi_result mdi_audio_play_string_with_vol_path(
                    void *audio_data,
                    U32 len,
                    U8 format,
                    U8 play_style,
                    mdi_ext_callback handler,
                    void *user_data,
                    U8 volume,
                    U8 path);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_string_portion_with_vol_path
 * DESCRIPTION
 *  This function is to play partial audio string along with volume and output path.
 * PARAMETERS
 *  audio_data      : [IN] Buffer pointer for audio data
 *  len             : [IN] Audio data length
 *  start_offset    : [IN] Start time offset (in ms)
 *  end_offset      : [IN] End time offset (in ms)
 *  format          : [IN] Audio data format
 *  play_style      : [IN] Play style
 *  handler         : [IN] Callback handler
 *  user_data       : [IN] User data
 *  volume          : [IN] Audio volume
 *  path            : [IN] Audio output path
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS       : Starts to play successfully
 *  MDI_AUDIO_BUSY          : The audio resource is occupied by recording
 *  MDI_AUDIO_FAIL          : Play audio buffer data fail
 *  MDI_AUDIO_BAD_FORMAT    : Driver can not decode audio buffer
 *****************************************************************************/
extern mdi_result mdi_audio_play_string_portion_with_vol_path(
       			    void *audio_data,
		            U32 len,
		            U8 format,
					U32 start_offset,
					U32 end_offset,
		            U8 play_style,
		            mdi_ext_callback handler,
		            void *user_data,
		            U8 volume,
		            U8 path);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_string_with_vol_path_non_block
 * DESCRIPTION
 *  This function is to play audio string along with volume and output path.
 *  The function will not block waiting for MED event, usually used for very quick and short sound play.
 * PARAMETERS
 *  audio_data      : [IN] Buffer pointer for audio data
 *  len             : [IN] Audio data length
 *  format          : [IN] Audio data format
 *  play_style      : [IN] Play style
 *  handler         : [IN] Callback handler
 *  user_data       : [IN] User data
 *  volume          : [IN] Audio volume
 *  path            : [IN] Audio output path
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS       : Starts to play successfully
 *  MDI_AUDIO_BUSY          : The audio resource is occupied by recording
 *  MDI_AUDIO_FAIL          : Play audio buffer data fail
 *  MDI_AUDIO_BAD_FORMAT    : Driver can not decode audio buffer
 *****************************************************************************/
extern mdi_result mdi_audio_play_string_with_vol_path_non_block(
                    void *audio_data,
                    U32 len,
                    U8 format,
                    U8 play_style,
                    mdi_ext_callback handler,
                    void *user_data,
                    U8 volume,
                    U8 path);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_file
 * DESCRIPTION
 *  This function is to play audio file.
 * PARAMETERS
 *  file_name       : [IN] Full file path and name
 *  play_style      : [IN] Play style
 *  cache_p         : [IN] Data cache buffer pointer to enhance seek speed for VBR files
 *  handler         : [IN] Callback handler
 *  user_data       : [IN] User data
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS           : Starts to play successfully
 *  MDI_AUDIO_FAIL              : Play audio buffer data fail
 *  MDI_AUDIO_BUSY              : The audio resource is occupied by recording
 *  MDI_AUDIO_OPEN_FILE_FAIL    : Open file fail
 *  MDI_AUDIO_END_OF_FILE       : Play till end of file
 *  MDI_AUDIO_BAD_FORMAT        : Driver can not decode audio buffer
 *  MDI_AUDIO_INVALID_FORMAT    : Not support format
 *  MDI_AUDIO_MEM_INSUFFICIENT  : Memory not enough to play
 *  MDI_AUDIO_DRM_PROHIBIT      : DRM protect and prohibit to play
 *****************************************************************************/
extern mdi_result mdi_audio_play_file(void *file_name, U8 play_style, void *cache_p, mdi_ext_callback handler, void *user_data);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_file_with_vol_path
 * DESCRIPTION
 *  This function is to play audio file along with volume and output path.
 * PARAMETERS
 *  file_name       : [IN] Full file path and name
 *  play_style      : [IN] Play style
 *  cache_p         : [IN] Data cache buffer pointer to enhance seek speed for VBR files
 *  handler         : [IN] Callback handler
 *  user_data       : [IN] User data
 *  volume          : [IN] Audio volume
 *  path            : [IN] Audio output path
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS           : Starts to play successfully
 *  MDI_AUDIO_FAIL              : Play audio buffer data fail
 *  MDI_AUDIO_BUSY              : The audio resource is occupied by recording
 *  MDI_AUDIO_OPEN_FILE_FAIL    : Open file fail
 *  MDI_AUDIO_END_OF_FILE       : Play till end of file
 *  MDI_AUDIO_BAD_FORMAT        : Driver can not decode audio buffer
 *  MDI_AUDIO_INVALID_FORMAT    : Not support format
 *  MDI_AUDIO_MEM_INSUFFICIENT  : Memory not enough to play
 *  MDI_AUDIO_DRM_PROHIBIT      : DRM protect and prohibit to play
 *****************************************************************************/
extern mdi_result mdi_audio_play_file_with_vol_path(
                    void *file_name,
                    U8 play_style,
                    void *cache_p,
                    mdi_ext_callback handler,
                    void *user_data,
                    U8 volume,
                    U8 path);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_file_portion_with_vol_path
 * DESCRIPTION
 *  This function is to play audio file portion with volume and output path.
 * PARAMETERS
 *  file_name       : [IN] Full file path and name
 *  start_offset    : [IN] Start time offset (in ms)
 *  end_offset      : [IN] End time offset (in ms)
 *  play_style      : [IN] Play style
 *  cache_p         : [IN] Data cache buffer pointer to enhance seek speed for VBR files
 *  handler         : [IN] Callback handler
 *  user_data       : [IN] User data
 *  volume          : [IN] Audio volume
 *  path            : [IN] Audio output path
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS           : Starts to play successfully
 *  MDI_AUDIO_FAIL              : Play audio buffer data fail
 *  MDI_AUDIO_BUSY              : The audio resource is occupied by recording
 *  MDI_AUDIO_OPEN_FILE_FAIL    : Open file fail
 *  MDI_AUDIO_END_OF_FILE       : Play till end of file
 *  MDI_AUDIO_BAD_FORMAT        : Driver can not decode audio buffer
 *  MDI_AUDIO_INVALID_FORMAT    : Not support format
 *  MDI_AUDIO_MEM_INSUFFICIENT  : Memory not enough to play
 *  MDI_AUDIO_DRM_PROHIBIT      : DRM protect and prohibit to play
 *****************************************************************************/
extern mdi_result mdi_audio_play_file_portion_with_vol_path(
                    void *file_name,
                    U32 start_offset,
                    U32 end_offset,
                    U8 play_style,
                    void *cache_p,
                    mdi_ext_callback handler,
                    void *user_data,
                    U8 volume,
                    U8 path);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_id
 * DESCRIPTION
 *  This function is to stop audio id.
 * PARAMETERS
 *  audio_id    : [IN] Audio id
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS       : Stops successfully
 *****************************************************************************/
extern mdi_result mdi_audio_stop_id(U16 audio_id);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_string
 * DESCRIPTION
 *  This function is to stop audio string.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS       : Stops successfully
 *****************************************************************************/
extern mdi_result mdi_audio_stop_string(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_file
 * DESCRIPTION
 *  This function is to stop audio file.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS       : Stops successfully
 *****************************************************************************/
extern mdi_result mdi_audio_stop_file(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_all
 * DESCRIPTION
 *  This function is to stop all audio id, string, file, FM radio, VR, TTS, ...
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS       : Stops successfully
 *****************************************************************************/
extern mdi_result mdi_audio_stop_all(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_pause
 * DESCRIPTION
 *  This function is to pause audio play/record.
 * PARAMETERS
 *  handler         : [IN] Callback handler
 *  user_data       : [IN] User data
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS               : Pause successfully
 *  MDI_AUDIO_UNSUPPORTED_OPERATION : Do not support pause function, will continue play
 *  MDI_AUDIO_DISC_FULL             : For record pause, disk is full while pause
 *  MDI_AUDIO_FAIL                  : Pause fail
 *****************************************************************************/
extern mdi_result mdi_audio_pause(mdi_ext_callback handler, void *user_data);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_resume
 * DESCRIPTION
 *  This function is to resume audio play/record.
 * PARAMETERS
 *  handler         : [IN] Callback handler  
 *  user_data       : [IN] User data
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS   : Resume successfully
 *  MDI_AUDIO_FAIL      : Resume fail
 *****************************************************************************/
extern mdi_result mdi_audio_resume(mdi_ext_callback handler, void *user_data);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_regisiter_auto_update_duration_handler
 * DESCRIPTION
 *  This function is to regisiter auto update time duration
 * PARAMETERS
 * duration_p     : [OUT] Total duration
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_regisiter_auto_update_duration_handler(void(*handler)(U32 duration));
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_duration
 * DESCRIPTION
 *  This function is to get the duration of a audio file.
 * PARAMETERS
 *  file_name       : [IN]  Full file path
 *  time_p          : [OUT] Duration in milliseconds
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_get_duration(void *file_name, U32 *time_p);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_mp4_duration
 * DESCRIPTION
 *  This function is to get the total duration of a mp4 file, it will return longer
 *  time in audio or video track.
 * PARAMETERS
 *  file_name       : [IN]  Full file path
 *  time_p          : [OUT] Duration in milliseconds
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_get_mp4_duration(void *file_name, U32 *time_p);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_duration_by_string
 * DESCRIPTION
 *  This function is to get the duration of a audio file.
 * PARAMETERS
 *  audio_data  : [IN]  Audio data pointer
 *  len         : [IN]  Data length
 *  format      : [IN]  Data format
 *  time_p      : [OUT] Duration in milliseconds
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_get_duration_by_string(kal_uint8 *audio_data, U32 len, U8 format, U32 *time_p);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_progress_time
 * DESCRIPTION
 *  This function is to get the progress of file playing
 * PARAMETERS
 *  progress_time_p : [IN] Current time
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_get_progress_time(U32 *progress_time_p);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_progress_time
 * DESCRIPTION
 *  This function is to seek file playing offset when it's playing a file.
 * PARAMETERS
 *  progress        [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_set_progress_time(U32 progress);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_midi_size_limit
 * DESCRIPTION
 *  This function is to get the MED buffer size for playing midi or imelody
 * PARAMETERS
 *  void
 * RETURNS
 *  Size of MED buffer
 *****************************************************************************/
extern U32 mdi_audio_get_midi_size_limit(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_size_limit
 * DESCRIPTION
 *  This function is to get the MED buffer size for a given media type. Currently,
 *  the type could be either MDI_FORMAT_SMF or MDI_FORMAT_IMELODY
 * PARAMETERS
 *  void
 * RETURNS
 *  Size of MED buffer
 *****************************************************************************/
extern U32 mdi_audio_get_size_limit(U8 type);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_start_seek
 * DESCRIPTION
 *  This function is to seek to a given start time
 * PARAMETERS
 *  file_name   : [IN] File name
 *  cache_table : [IN] Cache table
 *  table_size  : [IN] Size of cache table
 *  start_time  : [IN] Start time
 *  cb_fct      : [IN] Callback function
 *  cb_data     : [IN] Client data which will be brought back in the callback
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_start_seek(void* file_name, void* cache_table, U32 table_size, U32 start_time, mdi_seek_callback cb_fct, void* cb_data);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_seek
 * DESCRIPTION
 *  This function is to stop the seeking process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_stop_seek(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_start_calc_spectrum
 * DESCRIPTION
 *  This function is to start to calculate the audio spectrum tops & vals.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_start_calc_spectrum(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_calc_spectrum
 * DESCRIPTION
 *  This function is to stop calculating the audio spectrum tops & vals.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_stop_calc_spectrum(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_spectrum
 * DESCRIPTION
 *  This function is to get the audio spectrum tops & vals.
 * PARAMETERS
 *  top_p      : [IN] Spectrum tops
 *  val_p      : [IN] Spectrum values
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_get_spectrum(U8 *top_p, U8 *val_p);

/*-----------------------------------------------------------------------------
                              Audio Record
 ----------------------------------------------------------------------------*/
 
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_record_time
 * DESCRIPTION
 *  This function is to get current record time.
 * PARAMETERS
 *  void
 * RETURNS
 *  Total record time (in milliseconds)
 *****************************************************************************/
extern U32 mdi_audio_get_record_time(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_record_intensity
 * DESCRIPTION
 *  This function is to get mic intensity when record.
 * PARAMETERS
 *  channel   :[IN]  first mic or second mic
 * RETURNS
 *  strength: 
 *****************************************************************************/

extern U32 mdi_audio_get_record_intensity(U32 channel);

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_record_intensity_limit
 * DESCRIPTION
 *  This function is to get mic intensity limit max min value when record.
 * PARAMETERS
 *  max_value   :[IN]  the point of max_value of mic
 *  min_value   :[IN]  the point of min_value of mic
 * RETURNS
 *  succes or fail: 
 *****************************************************************************/

extern void mdi_audio_get_record_intensity_limit(U32* max_value,U32* min_value);

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_record_param
 * DESCRIPTION
 *  This function is to get record parameters for a given record profile.
 * PARAMETERS
 *  mode            : [IN] Record mode
 *  quality         : [IN] Record quality (MDI_AUDIO_REC_QUALITY_ENUM)
 *  param_p         : [OUT] Record parameter
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_get_record_param(
                    MDI_AUDIO_REC_MODE_ENUM mode,
                    MDI_AUDIO_REC_QUALITY_ENUM quality,
                    mdi_audio_rec_param_struct* param_p);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_estimated_record_byte_rate
 * DESCRIPTION
 *  This function is to get record byte rate for a given mode, format and quality.
 * PARAMETERS
 *  mode            : [IN] Record mode
 *  format          : [IN] Record format
 *  quality         : [IN] Record quality (MDI_AUDIO_REC_QUALITY_ENUM)
 * RETURNS
 *  void
 *****************************************************************************/
extern kal_uint32 mdi_audio_get_estimated_record_byte_rate(
                    MDI_AUDIO_REC_MODE_ENUM mode,
                    MDI_FORMAT_ENUM format,
                    MDI_AUDIO_REC_QUALITY_ENUM quality);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_start_record
 * DESCRIPTION
 *  This function is to start audio record.
 * PARAMETERS
 *  file_name       : [IN] Full file path and name
 *  format          : [IN] Record format
 *  handler         : [IN] Callback function
 *  user_data       : [IN] User data
 * RETURNS
 *  Refer to mdi_audio_start_record_with_limit()
 *****************************************************************************/
extern mdi_result mdi_audio_start_record(void *file_name, U8 format, U8 quality, mdi_ext_callback handler, void *user_data);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_start_record_with_limit
 * DESCRIPTION
 *  This function is to start audio record with time or size limited
 * PARAMETERS
 *  file_name       : [IN] Full file path and name
 *  format          : [IN] Record format
 *  handler         : [IN] Callback function
 *  size_limit      : [IN] Max record size in byte.   0: Unlimited
 *  time_limit      : [IN] Max record time in second. 0: Unlimited
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS           : Start record successfully
 *  MDI_AUDIO_FAIL              : Start record fail
 *  MDI_AUDIO_DISC_FULL         : Disk full
 *  MDI_AUDIO_OPEN_FILE_FAIL    : Can not open record file
 *  MDI_AUDIO_BAD_FORMAT        : Not support format (check by MED)
 *  MED_RES_INVALID_FORMAT      : Not support format (check by Driver)
 *  MDI_AUDIO_WRITE_PROTECTION  : Card has write protection
 *****************************************************************************/
extern mdi_result mdi_audio_start_record_with_limit(
                    void *file_name,
                    U8 format,
                    U8 quality,
                    mdi_ext_callback handler,
                    void* user_data,
                    U32 size_limit,
                    U32 time_limit);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_record
 * DESCRIPTION
 *  This function is to stop audio record.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS   : Stop successfully
 *****************************************************************************/
extern mdi_result mdi_audio_stop_record(void);

/*-----------------------------------------------------------------------------
                              Background Play
 ----------------------------------------------------------------------------*/
 
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_resume_background_play
 * DESCRIPTION
 *  This function is to resume background play.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_resume_background_play(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_suspend_background_play
 * DESCRIPTION
 *  This function is to suspend background play.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_suspend_background_play(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_terminate_background_play
 * DESCRIPTION
 *  This function is to terminate background play. Note that all the background
 *  handlers will be cleared.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_terminate_background_play(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_resume_background_play_by_app
 * DESCRIPTION
 *  This function is to resume background play by an application
 * PARAMETERS
 *  app_id      : [IN] Application id in MDI_AUD_SUSPEND_BG_APP
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_APP app_id);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_suspend_background_play_by_app
 * DESCRIPTION
 *  This function is to suspend background play by application.
 *  If the application does not call resume, the background play will keep suspended
 * PARAMETERS
 *  app_id      : [IN] Application id in MDI_AUD_SUSPEND_BG_APP
 * RETURNS
 *  The handle of the application will be returned. Application should use the 
 *  handle to resume background play.
 *****************************************************************************/
extern U8 mdi_audio_suspend_background_play_by_app(MDI_AUD_SUSPEND_BG_APP app_id);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_suspend_background_play_by_app_async
 * DESCRIPTION
 *  This function is to suspend background play by application.
 *  It is called by non-MMI task, and will send a message to MMI task to suspend
 * PARAMETERS
 *  app_id      : [IN] Use MDI_AUD_SUSPEND_BF_ASYNC_APP
 *  cb_hdlr     : [IN] Callback handler, will be called from MMI task
 *  user_data   : [IN] User data
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_suspend_background_play_by_app_async(MDI_AUD_SUSPEND_BG_APP app_id, mdi_ext_callback cb_hdlr, void *user_data);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_background_handler
 * DESCRIPTION
 *  This function is to set background play timeout handler.
 *  Besides POC, the latest register callback will be called first.
 *
 * PARAMETERS
 *  app_level   : [IN] Application in MDI_BACKGROUND_APP
 *  handler     : [IN] Callback handler
 *  user_data   : [IN] User data
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS   : Set successfully
 *  MDI_AUDIO_FAIL      : Set fail
 *****************************************************************************/
extern mdi_result mdi_audio_set_background_handler(U8 app_level, mdi_bg_callback handler, void *user_data);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_clear_background_handler
 * DESCRIPTION
 *  This function is to reset background play timeout handler.
 * PARAMETERS
 *  app_level   : [IN] Application in MDI_BACKGROUND_APP
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS   : Clear successfully
 *  MDI_AUDIO_FAIL      : Clear fail
 *****************************************************************************/
extern mdi_result mdi_audio_clear_background_handler(U8 app_level);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_clear_other_background_handler
 * DESCRIPTION
 *  This function is to clear other application's background handler except current application
 * PARAMETERS
 *  app_level   : [IN] Application in MDI_BACKGROUND_APP
 * RETURNS
 *  MDI_AUDIO_SUCCESS   : Clear successfully
 *****************************************************************************/
extern mdi_result mdi_audio_clear_other_background_handler(U8 app_level);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_background_callback_order
 * DESCRIPTION
 *  This function is to get application sequence in the callback stack
 * PARAMETERS
 *  app_level   : [IN] Application in MDI_BACKGROUND_APP
 * RETURNS
 *  The position in the callback stack
 *****************************************************************************/
extern S32 mdi_audio_get_background_callback_order(U8 app_level);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_background_callback_register_app_num
 * DESCRIPTION
 *  This function is to get total callback number in the stack
 * PARAMETERS
 *  void
 * RETURNS
 *  Total callback number
 *****************************************************************************/
extern U8 mdi_audio_get_background_callback_register_app_num(void);

/*-----------------------------------------------------------------------------
                              Interrupt Handler
 ----------------------------------------------------------------------------*/
 
 /*****************************************************************************
 * FUNCTION
 *  mdi_audio_register_interrupt_callback
 * DESCRIPTION
 *  Register mdi audio interrupt callback. Application will receive callback
 *  when mdi audio recive a new play request or stop requst. Note that currently
 *  only one instance is supported. Hence, the client has to clear the interrupt
 *  hanlder if not uses it anymore.
 * PARAMETERS
 *  app_level   : [IN] Application in MDI_BACKGROUND_APP
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_register_interrupt_callback(mdi_ext_callback handler, void* user_data);
 /*****************************************************************************
 * FUNCTION
 *  mdi_audio_clear_interrupt_callback
 * DESCRIPTION
 *  Clear interrupt callback handler
 * PARAMETERS
 *  void
 * RETURNS
 *  The position in the callback stack
 *****************************************************************************/
extern void mdi_audio_clear_interrupt_callback(void);

/*-----------------------------------------------------------------------------
                              Volume Control
 ----------------------------------------------------------------------------*/
 
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_volume
 * DESCRIPTION
 *  This function is to set the volume with the given type and volume.
 * PARAMETERS
 *  type        [IN] : Audio type
 *  volume      [IN] : Volume
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_set_volume(U8 type, U8 volume);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_incr_volume
 * DESCRIPTION
 *  This function is used to increase the volume.
 * PARAMETERS
 *  volume      [IN] : Volume
 * RETURNS
 *  volume after increasing
 *****************************************************************************/
extern U8 mdi_audio_incr_volume(U8 volume);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_decr_volume
 * DESCRIPTION
 *  This function is used to decrease the volume.
 * PARAMETERS
 *  volume      [IN] : Volume
 * RETURNS
 *  volume after decreasing.
 *****************************************************************************/
extern U8 mdi_audio_decr_volume(U8 volume);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_mic_volume
 * DESCRIPTION
 *  This function is used to update the volume of microphone.
 * PARAMETERS
 *  volume      [IN] : Volume
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_set_mic_volume(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_mute
 * DESCRIPTION
 *  This function is to set mute on the given volume type.
 * PARAMETERS
 *  vol_type        [IN] : Audio type
 *  mute            [IN] : Mute on/off
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_set_mute(U8 vol_type, MMI_BOOL mute);

/*-----------------------------------------------------------------------------
                                     BT
 ----------------------------------------------------------------------------*/
 
#ifdef __BT_SPK_VOL_CONTROL__
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bt_register_volume_sync_callback
 * DESCRIPTION
 *  This function is to register volume value callback from BT headset
 * PARAMETERS
 *   app_id         : [IN] Use APPLICATION_DEPLOY enum in MMIDataType.h
 *   volume_type    : [IN] 16-level or 7-level volume (MDI_AUD_VOL_LEVEL_NORMAL ~ MDI_AUD_VOL_LEVEL_EXTEND_MUTE)
 *   callback       : [IN] Return true if application is running
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_bt_register_volume_sync_callback(U32 app_id, U8 volume_lvl_type, MMI_BOOL (*callback)(U8 volume, MMI_BOOL is_mute));
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_clear_volume_sync_callback
 * DESCRIPTION
 *  This function is to clear volume value callback from BT headset
 * PARAMETERS
 *   app_id         : [IN] Use APPLICATION_DEPLOY enum in MMIDataType.h
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_bt_clear_volume_sync_callback(U32 app_id);
#endif /* __BT_SPK_VOL_CONTROL__ */

/*-----------------------------------------------------------------------------
                              State Control
 ----------------------------------------------------------------------------*/
 
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_headset_mode_output_path
 * DESCRIPTION
 *  This function is to set headset mode output path.
 * PARAMETERS
 *  device      : [IN] Output device
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_set_headset_mode_output_path(unsigned char device);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vib_spk_calibration
 * DESCRIPTION
 *  This function is to set vibrator current sensor
 * PARAMETERS
 *  handler      : [IN] 
 * RETURN VALUES
 *  void  
 *****************************************************************************/
extern void mdi_audio_vib_spk_calibration(mdi_callback handler);

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_vibrator_enabled
 * DESCRIPTION
 *  This function is to set vibrator enabled
 * PARAMETERS
 *  enable      : [IN] Enable/disable the vibrator
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS   : Set successfully
 *****************************************************************************/
extern mdi_result mdi_audio_set_vibrator_enabled(MMI_BOOL enable);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_state
 * DESCRIPTION
 *  This function is to get the audio state.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_AUDIO_IDLE          : Idle state
 *  MDI_AUDIO_PLAY          : Play state
 *  MDI_AUDIO_PLAY_PAUSED   : Play paused state
 *  MDI_AUDIO_RECORD        : Record state
 *  MDI_AUDIO_RECORD_PAUSED : Record paused state
 *****************************************************************************/
extern mdi_state mdi_audio_get_state(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_audio_mode
 * DESCRIPTION
 *  This function is to get the audio mode (normal, headset, loudspk).
 * PARAMETERS
 *  void
 * RETURNS
 *  AUD_MODE_NORMAL     : Normal Mode
 *  AUD_MODE_HEADSET    : HeadSet (Earphone) Mode
 *  AUD_MODE_LOUDSPK    : Loudspeaker Mode
 *****************************************************************************/
extern U8 mdi_audio_get_audio_mode(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_audio_mode
 * DESCRIPTION
 *  This function is to set the audio mode (normal, headset, loudspk).
 * PARAMETERS
 *  mode        [IN] : Audio mode
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_set_audio_mode(U8 mode);

/*-----------------------------------------------------------------------------
                              Query functions
 ----------------------------------------------------------------------------*/
 
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_background_play_suspended
 * DESCRIPTION
 *  This function is to check if background play suspended.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mdi_audio_is_background_play_suspended(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_idle
 * DESCRIPTION
 *  This function is to check if audio is in idle state.
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mdi_audio_is_idle(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_idle
 * DESCRIPTION
 *  This function is to check if audio is playing in specific audio mode
 * PARAMETERS
 *  audio_mode [IN] : Mode in MDI_AUDIO_PLAY_MODE_ENUM
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mdi_audio_is_playing(U16 audio_mode);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_recording
 * DESCRIPTION
 *  This function is to check if it's recording
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mdi_audio_is_recording(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_resource_available
 * DESCRIPTION
 *  This function is to check if the resource for a given play mode is available.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE    The resource of the play mode is available.
 *  FALSE   The resource of the play mode is being occupied.
 *****************************************************************************/
extern MMI_BOOL mdi_audio_is_resource_available(MDI_AUDIO_PLAY_MODE_ENUM play_mode, void* param);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_speech_mode
 * DESCRIPTION
 *  This function is to check is in speech mode
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mdi_audio_is_speech_mode(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_pure_audio
 * DESCRIPTION
 *  This function is to check if a file is pure audio file
 * PARAMETERS
 *  file_name      : [IN] File name
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mdi_audio_is_pure_audio(void *file_name);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_seekable
 * DESCRIPTION
 *  This function is to check if a aac file seekable. (AAC ADIF is not seekable)
 * PARAMETERS
 *  file_name      : [IN] File name
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mdi_audio_is_aac_file_seekable(void *file_name);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_file_seekable
 * DESCRIPTION
 *  This function is to check if a file is seekable. (AAC-ADIF/MIDI file playback
 *  are not seekable)
 * PARAMETERS
 *  file_name      : [IN] File name
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mdi_audio_is_file_seekable(void *file_name);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_file_pausable
 * DESCRIPTION
 *  This function is to check if a file is pausable. (AAC-ADIF is not pausable)
 * PARAMETERS
 *  file_name      : [IN] File name
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mdi_audio_is_file_pausable(void *file_name);

/*-----------------------------------------------------------------------------
                              Build Cache
 ----------------------------------------------------------------------------*/
 
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_start_build_cache
 * DESCRIPTION
 *  This function is to start build cache
 * PARAMETERS
 *  filename        : [IN] Full file path
 *  cache_p         : [IN] Cache buffer pointer
 *  cache_size      : [IN] Cache buffer size
 *  file_buf_p      : [IN] File cache buffer pointer
 *  file_buf_size   : [IN] File cache size
 *  proc_buf_p      : [IN] Driver process buffer pointer
 *  proc_buf_size   : [IN] Driver process buffer size
 *  handler         : [IN] Call back hanlder when build cache fail
 *  build_cache_progress    : [OUT] Process percentage
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_start_build_cache(
                    kal_wchar *filename,
                    U8 *cache_p, 
                    U32 cache_size,
                    U8 *file_buf_p,
                    U32 file_buf_size,
                    U8 *proc_buf_p,
                    U32 proc_buf_size,
                    void (*handler)(void*),
                    U32 *build_cache_progress);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_build_cache
 * DESCRIPTION
 *  This function is to stop build cache
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_stop_build_cache(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_close_build_cache
 * DESCRIPTION
 *  This function is to close build cache
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_close_build_cache(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_reset_build_cache_variables
 * DESCRIPTION
 *  This function is to reset build cache variables
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_reset_build_cache_variables(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_build_cache_get_cache_duration
 * DESCRIPTION
 *  This function is to get current cached duration
 * PARAMETERS
 * duration_p     : [OUT] Duration
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mdi_audio_build_cache_get_cache_duration(kal_uint32 *duration_p);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_reset_build_cache_variables
 * DESCRIPTION
 *  This function is to get total duration from build cache
 * PARAMETERS
 * duration_p     : [OUT] Duration
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mdi_audio_build_cache_get_total_duration(kal_uint32 *duration_p);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_duration_need_build_cache
 * DESCRIPTION
 *  This function is to check if we need to build cache to get precise duration
 * PARAMETERS
 *  filename     : [IN] Fule file path
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mdi_audio_is_duration_need_build_cache(void *filename);

/*-----------------------------------------------------------------------------
                                   MMA
 ----------------------------------------------------------------------------*/
 
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_open
 * DESCRIPTION
 *  This function is to open an MMA handle for a given file name or string data
 * PARAMETERS
 *  mma_open     : [IN] MMA Open structure
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_mma_open(mdi_mma_open_struct* mma_open);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_open_file
 * DESCRIPTION
 *  This function is to open file with mma interface
 * PARAMETERS
 *  app_id       : [IN] App id
 *  file_name    : [IN] Fule file path
 *  repeats      : [IN] Repeat times
 *  is_pdl       : [IN] Is progressive download
 *  callback     : [IN] Callback function
 *  user_data    : [IN] Private data which will be brought back in the callback 
 * RETURNS
 *  mdi_handle, handle of the player
 *****************************************************************************/
extern mdi_handle mdi_audio_mma_open_file(U16 app_id, void *file_name, U8 repeats, MMI_BOOL is_pdl, mdi_mma_callback callback, void* user_data);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_open_string
 * DESCRIPTION
 *  This function is to open audio buffer with mma interface
 * PARAMETERS
 *  app_id       : [IN] App id
 *  audio_data   : [IN] Data pointer
 *  len          : [IN] Data length
 *  mdi_format   : [IN] Format
 *  repeats      : [IN] Repeat times
 *  callback     : [IN] Callback function
 *  user_data    : [IN] Private data which will be brought back in the callback
 * RETURNS
 *  mdi_handle, handle of the player
 *****************************************************************************/
extern mdi_handle mdi_audio_mma_open_string(U16 app_id, void *audio_data, U32 len, U8 mdi_format, U8 repeats, mdi_mma_callback callback, void* user_data);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_set_cache_table
 * DESCRIPTION
 *  This function is to set cache table to driver for faster seek in VBR file
 * PARAMETERS
 *  handle      : [IN] Player handle
 *  cache_tbl   : [IN] Cache table buffer
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_mma_set_cache_table(mdi_handle handle, U8 *cache_tbl);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_set_param
 * DESCRIPTION
 *  This function is to set paramters to current handle after open success
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
extern mdi_result mdi_audio_mma_set_param(mdi_handle handle, MDI_MMA_PARAM_ENUM param_type, void* param_value);

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_play
 * DESCRIPTION
 *  This function is to start player
 * PARAMETERS
 *  handle      : [IN] Player handle
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_mma_play(mdi_handle handle);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_pause
 * DESCRIPTION
 *  This function is to pause player
 * PARAMETERS
 *  handle      : [IN] Player handle
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_mma_pause(mdi_handle handle);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_resume
 * DESCRIPTION
 *  This function is to resume player
 * PARAMETERS
 *  handle      : [IN] Player handle
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_mma_resume(mdi_handle handle);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_stop
 * DESCRIPTION
 *  This function is to stop player
 * PARAMETERS
 *  handle      : [IN] Player handle
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_mma_stop(mdi_handle handle);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_close
 * DESCRIPTION
 *  This function is to close player
 * PARAMETERS
 *  handle      : [IN] Player handle
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_mma_close(mdi_handle handle);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_is_idle
 * DESCRIPTION
 *  This function is to check if all mma player is idle
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
extern kal_bool mdi_audio_mma_is_idle(void);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_build_BLSI_table
 * DESCRIPTION
 *  This function is to zip / unzip BLSISRC talbe, this could speed up mixed 
 *  sampling rate audio playback.
 *  Turn on/off shall be called in pair
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool mdi_audio_mma_build_BLSI_table(MMI_BOOL turn_on);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_is_open
 * DESCRIPTION
 *  This function is to check if any mma player is open
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
extern kal_bool mdi_audio_mma_is_open(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_set_start_time
 * DESCRIPTION
 *  This function is to set start time
 * PARAMETERS
 *  handle      : [IN] Player handle
 *  start_time  : [IN] Start time
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_mma_set_start_time(mdi_handle handle, U32 start_time);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_get_current_time
 * DESCRIPTION
 *  This function is to get current playing time
 * PARAMETERS
 *  handle        : [IN] Player handle
 *  current_time  : [OUT] Current time
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_mma_get_current_time(mdi_handle handle, U32 *current_time);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_get_estimated_duration
 * DESCRIPTION
 *  This function is to get estimated duration before playing. Note that we have to
 *  get estimated duration before issuing play request. Otherwise, we may run out of
 *  resources in some cases.
 * PARAMETERS
 *  handle        : [IN] Player handle
 *  duration      : [OUT] Duration
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_mma_get_estimated_duration(mdi_handle handle, U32 *duration);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_get_updated_duration
 * DESCRIPTION
 *  This function is to get updated duration when receiving the MDI_AUDIO_DUR_UPDATED
 *  notification.
 * PARAMETERS
 *  handle        : [IN] Player handle
 *  duration      : [OUT] Duration
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_mma_get_updated_duration(mdi_handle handle, U32 *duration);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_pdl_write_data_ind
 * DESCRIPTION
 *  This function is to inform MED if the PDL is download finish
 * PARAMETERS
 *  handle      : [IN] Player handle
 *  is_finish   : [IN] Is download finish
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_mma_pdl_write_data_ind(mdi_handle handle, MMI_BOOL is_finish);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_pdl_get_buf_percent
 * DESCRIPTION
 *  This function is to get current pdl buffering status
 * PARAMETERS
 *  handle      : [IN] Player handle
 *  percent     : [OUT] Percentage
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_mma_pdl_get_buf_percent(mdi_handle handle, U32 cache_sec, U32* percent);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_get_audio_info
 * DESCRIPTION
 *  This function is to get audio info for a given file or stream buffer.
 * PARAMETERS
 *  app_id      : [IN] App id
 *  file_name   : [IN] The file name to be parsed. NULL if using stream buffer.
 *  media_type  : [IN] Media type (MMA_TYPE_XXX) of the stream buffer. Don't care if using file.
 *  data        : [IN] Stream data. NULL if using file.
 *  data_len    : [IN] The length of stream data. 0 if using file.
 *  audio_info  : [OUT] Audio info
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_mma_get_audio_info(kal_uint16 app_id, kal_wchar* file_name, kal_uint8 media_type, kal_uint8* data, kal_uint32 data_len, audInfoStruct *audio_info);

/*-----------------------------------------------------------------------------
                                    FMR
 ----------------------------------------------------------------------------*/
 
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_power_on_with_path
 * DESCRIPTION
 *  This function is to turn on FM radio with specific output path
 * PARAMETERS
 *  path        : [IN] FM output path
 *  handler     : [IN] Callback handler
 *  user_data   : [IN] User data
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_fmr_power_on_with_path(U8 path, mdi_ext_callback handler, void *user_data);
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_power_off
 * DESCRIPTION
 *  This function is to turn off FM radio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_fmr_power_off(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_fmr
 * DESCRIPTION
 *  This function is to stop FM radio playing/recording
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS       : Stops successfully
 *****************************************************************************/
extern mdi_result mdi_audio_stop_fmr(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_fm_on
 * DESCRIPTION
 *  This function is to check if FMR is being on.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mdi_audio_is_fm_on(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_set_freq
 * DESCRIPTION
 *  This function is to set the frequency of FM radio.
 * PARAMETERS
 *  freq        : [IN] FM frequency
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_fmr_set_freq(U16 freq);
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_set_output_path
 * DESCRIPTION
 *  This function is to set the output path of FM radio.
 * PARAMETERS
 *  path        : [IN] Output path of FM radio
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_fmr_set_output_path(U8 path);
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_set_antenna
 * DESCRIPTION
 *  This function is to set the antenna of FM radio.
 * PARAMETERS
 *  is_short_antenna  : [IN] Indicate if the short antenna should be used
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_fmr_set_antenna(MMI_BOOL is_short_antenna);
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_mute
 * DESCRIPTION
 *  This function is to mute the FM radio
 * PARAMETERS
 *  mute        : [IN] Mute on or off
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_fmr_mute(U8 mute);

#ifdef __MMI_FM_VIA_A2DP__

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_mute
 * DESCRIPTION
 *  This function is to mute the FM radio
 * PARAMETERS
 *  audio_info  : [OUT] audio_info ptr
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_fmr_get_audio_info(mdi_fmr_audio_info_struct *audio_info);
/* DOM-NOT_FOR_SDK-END */

#endif


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_check_is_valid_stop
 * DESCRIPTION
 *  This function is to check if a frequency is valid stop
 * PARAMETERS
 *  freq                : [IN] FM frequency
 *  is_step_up          : [IN] Step up or down
 *  callback_func       : [IN] Callback function
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_check_is_valid_stop(U16 freq, MMI_BOOL is_step_up, void (*callback_func) (MMI_BOOL is_valid));
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_cancel_checking_is_valid_stop
 * DESCRIPTION
 *  This function is to cancel check valid stop
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_fmr_cancel_checking_is_valid_stop(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_get_signal_level
 * DESCRIPTION
 *  This function is to get the signal level of a frequency
 * PARAMETERS
 *  freq                : [IN] FM frequency
 *  is_step_up          : [IN] Step up or down
 *  callback_func       : [IN] Callback function
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_get_signal_level(U16 freq, MMI_BOOL is_step_up, void (*callback_func) (U8 sig_lvl));
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_cancel_getting_signal_level
 * DESCRIPTION
 *  This fuction is to cancel get signal level request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_fmr_cancel_getting_signal_level(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_evaluate_threshold
 * DESCRIPTION
 *  This function is to re-evaluate valid channel threshould
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_fmr_evaluate_threshold(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_set_channel
 * DESCRIPTION
 *  This API is to set mono or stereo channel
 * PARAMETERS
 *  is_mono     : [IN] Is mono channel
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_fmr_set_channel(MMI_BOOL is_mono);
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_freq_seek_start
 * DESCRIPTION
 *   Start to seek
 * PARAMETERS
 *  start_freq      : [IN]    start frequency
 *  is_step_up      : [IN]    seek direction
 *  is_preset       : [IN]    it will not wrap around if it is preset auto search
 *  space           : [IN]    minimum space between two frequency. 200: 200KHz, 100: 100KHz
 *  callback_func   : [IN]    callback function when found a valid freq or user abortion
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_fmr_freq_seek_start(U16 start_freq, MMI_BOOL is_step_up, MMI_BOOL is_preset, S16 space,
                                    void (*callback_func) (U16 stop_freq, U8 signal_level, MMI_BOOL is_valid)) ;
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_freq_seek_abort
 * DESCRIPTION
 *  Abort FM Radio seek.
 *  After abortion, it will call the callback function register in mdi_fmr_freq_seek_start.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_fmr_freq_seek_abort(void);

#ifdef __MMI_FM_RADIO__
#ifndef __PLUTO_MMI_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_scan_start
 * DESCRIPTION
 *  This is a general function to perform a scan request, the MDI will use
 *  HW scan, HW search or SW scan per the capabilities of the platform.
 * PARAMETERS
 *  scan_req              : [IN]    Scan request
 * RETURNS
 *  MDI_AUDIO_SUCCESS     : Successful
 *  MDI_AUDIO_FAIL        : Failed for some reason
 *  MDI_AUDIO_BUSY        : The FMR is not in idle state
 *  MDI_AUDIO_PARAM_ERROR : Bad parameters
 *****************************************************************************/
extern S32 mdi_fmr_scan_start(mdi_fmr_scan_req_struct *scan_req);

/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_scan_abort
 * DESCRIPTION
 *  This function is to abort a scan request.
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_AUDIO_SUCCESS     : Successful
 *  MDI_AUDIO_FAIL        : Failed for some reason
 *****************************************************************************/
extern S32 mdi_fmr_scan_abort(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_seek_start
 * DESCRIPTION
 *  This is a general function to perform seek request, the MDI will use HW
 *  search or SW search per the capabilities of the platform.
 * PARAMETERS
 *  seek_req              : [IN]    Seek request
 * RETURNS
 *  MDI_AUDIO_SUCCESS     : Successful
 *  MDI_AUDIO_FAIL        : Failed for some reason
 *  MDI_AUDIO_BUSY        : The FMR is not in idle state
 *  MDI_AUDIO_PARAM_ERROR : Bad parameters
 *****************************************************************************/
extern S32 mdi_fmr_seek_start(mdi_fmr_seek_req_struct *seek_req);

/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_seek_abort
 * DESCRIPTION
 *  This function is to abort a seek request.
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_AUDIO_SUCCESS     : Successful
 *  MDI_AUDIO_FAIL        : Failed for some reason
 *****************************************************************************/
extern S32 mdi_fmr_seek_abort(void);

#endif /*__PLUTO_MMI_PACKAGE__*/
#endif /*__MMI_FM_RADIO__*/


/*-----------------------------------------------------------------------------
                                 FMR Record
 ----------------------------------------------------------------------------*/
 
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_start_record
 * DESCRIPTION
 *  This function is to start record for FM radio
 * PARAMETERS
 *  file_name       : [IN] Full filename
 *  format          : [IN] Record format
 *  quality         : [IN] Record quality
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_fmr_start_record(void *file_name, U8 format, U8 quality);
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_stop_record
 * DESCRIPTION
 *  This function is to stop FM recording and call back to MMI.
 *  After calling this function, FM radio will still playing.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern mdi_result mdi_fmr_stop_record(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_pause_record
 * DESCRIPTION
 *  This function is to pause FM radio record
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_fmr_pause_record(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_resume_record
 * DESCRIPTION
 *  This function is to resume FM radio record
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_fmr_resume_record(void);

/*-----------------------------------------------------------------------------
                                  FMR RDS
 ----------------------------------------------------------------------------*/
 
#ifdef __FM_RADIO_RDS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_rds_enable
 * DESCRIPTION
 *  This function is to send RDS enable request
 * PARAMETERS
 *  callback     : [IN]     Callback function
 *  af_enable    : [IN]     Enable/disable alternative program
 *  tp_enable    : [IN]     Enable/disable traffic program
 *  user_data    : [IN]     User data
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_fmr_rds_enable(void (*callback)(mdi_rds_event_struct* buffer, void* user_data), 
                         MMI_BOOL af_enable,
                         MMI_BOOL tp_enable,
                         void* user_data);
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_rds_af_tp_setting 
 * DESCRIPTION
 *  This function is to send RDS parameters update request
 * PARAMETERS
 *  af_enable    : [IN]     Enable/disable alternative program
 *  tp_enable    : [IN]     Enable/disable traffic program
 * RETURNS
 *  void
 *****************************************************************************/
extern mdi_result mdi_fmr_rds_af_tp_setting(MMI_BOOL af_enable, MMI_BOOL tp_enable);
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_rds_disable
 * DESCRIPTION
 *  This function is to send RDS disable request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_fmr_rds_disable(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_rds_poll_rds_event_rds
 * DESCRIPTION
 *  This function is to Poll for RDS log on getting RDS_EVENT_RDS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern mdi_result mdi_fmr_rds_poll_rds_event_rds(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_rds_set_buffer
 * DESCRIPTION
 *  This function is to set the buffer for RDS data retrieval
 * PARAMETERS
 *  RT_Data      : [IN] 
 *  PS_Data      : [IN] 
 *  AF_Data      : [IN] 
 *  TP_Data      : [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_fmr_rds_set_buffer(U16 *RT_Data, U16 *PS_Data, U16 *AF_Data, U16 *TP_Data);
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_rds_reset_buffer
 * DESCRIPTION
 *  This function is to reset the buffer of RDS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_fmr_rds_reset_buffer(void);
#endif /* __FM_RADIO_RDS_SUPPORT__ */

/*-----------------------------------------------------------------------------
                                    Speech
 ----------------------------------------------------------------------------*/
 
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_session_start
 * DESCRIPTION
 *  start speech session (for All apps)
 * PARAMETERS
 *  speech_type_id       : [IN] Application ID in MDI_AUDIO_SPEECH_APP_ID_ENUM
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_session_start(MDI_AUDIO_SPEECH_APP_ID_ENUM speech_type_id);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_session_stop
 * DESCRIPTION
 *  stop speech session (for All apps)
 * PARAMETERS
 *  speech_type_id       : [IN] Application ID in MDI_AUDIO_SPEECH_APP_ID_ENUM
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_session_stop(MDI_AUDIO_SPEECH_APP_ID_ENUM speech_type_id);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_get_app_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_AUDIO_SPEECH_APP_ID_ENUM
 *****************************************************************************/
MDI_AUDIO_SPEECH_APP_ID_ENUM mdi_audio_speech_get_app_id(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_set_app_id
 * DESCRIPTION
 *  This function is to change the current application ID
 * PARAMETERS
 *  speech_type_id       : [IN] Application ID in MDI_AUDIO_SPEECH_APP_ID_ENUM
 * RETURNS
 *  mdi_result
 *****************************************************************************/
void mdi_audio_speech_set_app_id(MDI_AUDIO_SPEECH_APP_ID_ENUM speech_type_id);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_codec_start
 * DESCRIPTION
 *  This function is to turn on speech codec
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_codec_start(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_codec_stop
 * DESCRIPTION
 *  This function is to turn off speech codec
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_codec_stop(void);

/*-----------------------------------------------------------------------------
                                  Gain Table
 ----------------------------------------------------------------------------*/
 
/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef __GAIN_TABLE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_update_volume
 * DESCRIPTION
 *  This function is to update the volume for a given reason
 * PARAMETERS
 *  reason       : [IN] The reason to update volume
 *  param_p      : [IN] Hint data
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_update_volume(mdi_audio_volume_update_reason_enum reason, void* param_p);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_info
 * DESCRIPTION
 *  This function is to get the information in MDI audio
 * PARAMETERS
 *  get_type     : [IN]     The information to be queried
 *  data_p       : [OUT]    Data buffer
 *  data_len_p   : [IN/OUT] The length of data buffer when in. The length of data that have retrieved when out.
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_get_info(mdi_audio_get_info_enum get_type, void* data_p, kal_uint16* data_len_p);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_audio_type
 * DESCRIPTION
 *  This function is to set the audio type before issuing a play request. Note
 *  that this function call is required if the playback needs to have specific
 *  volume setting.
 * PARAMETERS
 *  audio_type   : [IN] The audio type of a play request
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_set_audio_type(mdi_audio_type_enum audio_type);
#endif /* __GAIN_TABLE_SUPPORT__ */
/* DOM-NOT_FOR_SDK-END */

/*-----------------------------------------------------------------------------
                                 Audio Clipper
 ----------------------------------------------------------------------------*/
 
/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef __AUDIO_TRIM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_trim_open
 * DESCRIPTION
 *  This function opens a trimming handler.
 * PARAMETERS
 *  file_name_in    : [IN]   The source file of the trimming
 *  file_name_out   : [IN]   The file to be trimmed to
 *  cb_hdlr         : [IN]   Trim event handler
 *  user_data       : [IN]   User data
 *  handle_p        : [OUT]  Trim handle
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_trim_open(kal_wchar* file_name_in, kal_wchar* file_name_out, mdi_aud_trim_callback cb_hdlr, void* user_data, kal_uint32* handle_p);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_trim_close
 * DESCRIPTION
 *  This function closes a trimming handler.
 * PARAMETERS
 *  handle          : [IN]   Trim handle
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_trim_close(kal_uint32 handle);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_trim_start
 * DESCRIPTION
 *  This function starts the trimming.
 * PARAMETERS
 *  handle          : [IN]   Trim handle
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_trim_start(kal_uint32 handle);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_trim_stop
 * DESCRIPTION
 *  This function stops the trimming.
 * PARAMETERS
 *  handle          : [IN]   Trim handle
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_trim_stop(kal_uint32 handle);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_trim_set_param
 * DESCRIPTION
 *  This function sets parameters of the trimming.
 * PARAMETERS
 *  handle          : [IN]   Trim handle
 *  set_type        : [IN]   The type to be set.
 *  data_p          : [IN]   The data to be set.
 *  data_len        : [IN]   The length of the data.
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_trim_set_param(kal_int32 handle, kal_uint8 set_type, void* data_p, kal_uint16 data_len);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_trim_get_param
 * DESCRIPTION
 *  This function gets parameters of the trimming.
 * PARAMETERS
 *  handle          : [IN]     Trim handle
 *  get_type        : [IN]     The type to be get.
 *  data_p          : [OUT]    The data to be get.
 *  data_len        : [IN/OUT] The length of the data.
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_trim_get_param(kal_int32 handle, kal_uint8 get_type, void* data_p, kal_uint16* data_len_p);
#endif /* __AUDIO_TRIM_SUPPORT__ */
/* DOM-NOT_FOR_SDK-END */

/*-----------------------------------------------------------------------------
                              Audio Post-Processing
 ----------------------------------------------------------------------------*/
 
#if defined(__BES_TS_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stretch_check_string_format
 * DESCRIPTION
 *  This function is to check if a given audio data supports time stretch.
 * PARAMETERS
 *  audio_data      : [IN]    Audio data
 *  len             : [IN]    Audio data length
 *  format          : [IN]    Audio data format
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_stretch_check_string_format(void *audio_data, U32 len, U16 format);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stretch_check_file_format
 * DESCRIPTION
 *  This function is to check if a given audio file supports time stretch.
 * PARAMETERS
 *  file_name       : [IN]    File name
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_stretch_check_file_format(void *file_name);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stretch_check_file_format
 * DESCRIPTION
 *  This function is to set audio time stretch speed.
 * PARAMETERS
 *  speech          : [IN]    Time stretch speed
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_stretch_set_speed(U16 speed);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stretch_close
 * DESCRIPTION
 *  This function is to close audio time stretch.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern void mdi_audio_stretch_close(void);
#endif /* #if defined(__BES_TS_SUPPORT__) */

#if defined(__BES_LIVE_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_reverb_set_mode
 * DESCRIPTION
 *  This function is to set the reverb mode.
 * PARAMETERS
 *  mode          : [IN]    Reverb mode
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_reverb_set_mode(U16 mode);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_reverb_turn_on
 * DESCRIPTION
 *  This function is to turn on reverb effect.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_reverb_turn_on(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_reverb_turn_off
 * DESCRIPTION
 *  This function is to turn off reverb effect.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_reverb_turn_off(void);
#endif /* #if defined(__BES_LIVE_SUPPORT__) */

#if defined(__BES_SURROUND_LSPK__) || defined(__BES_SURROUND_EARP__)
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_surround_turn_on
 * DESCRIPTION
 *  This function is to turn on surround effect.
 * PARAMETERS
 *  mode          : [IN]    Surround mode
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_surround_turn_on(U8 mode);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_surround_turn_off
 * DESCRIPTION
 *  This function is to turn off surround effect.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_surround_turn_off(void);
#endif /* #if defined(__BES_SURROUND_LSPK__) || defined(__BES_SURROUND_EARP__) */

#if defined(__BES_EQ_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_eq_set_magnitude
 * DESCRIPTION
 *  This function is to set equalizer magnitude.
 * PARAMETERS
 *  magnitude      : [IN]    Magnitude table
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_eq_set_magnitude(S8 *magnitude);

/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_eq_transfer_magnitude
 * DESCRIPTION
 *  This function is to transfer equalizer magnitude between dirver's bands number,
 *  The size of the array shall be either NVRAM_EF_AUDIO_EQUALIZER_BAND_NUM or bar_num
    and mmi bar number
 * PARAMETERS
 *  magnitude_in     [IN]     magnitude table pointer for input
 *  magnitude_out    [OUT]    magnitude table pointer for output
 *  bar_num          [IN]     mmi bar number
 *  to_bar_num       [IN]     a boolean to indicate transfer to bar num or to band num
 *                            MMI_TRUE : to bar, 
 *                            MMI_FALSE: to band                            
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_eq_transfer_magnitude(S8 *magnitude_in, S8 *magnitude_out, U32 bar_num, MMI_BOOL to_bar_num);
#endif /*__MMI_EDITABLE_AUDIO_EQUALIZER__*/
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_eq_turn_on
 * DESCRIPTION
 *  This function is to turn on EQ.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_eq_turn_on(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_eq_turn_off
 * DESCRIPTION
 *  This function is to turn off EQ.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_eq_turn_off(void);
#endif /* #if defined(__BES_EQ_SUPPORT__) */

#if defined(__BES_BASS_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bass_enhance_turn_on
 * DESCRIPTION
 *  This function is to turn on bass.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_bass_enhance_turn_on(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bass_enhance_turn_off
 * DESCRIPTION
 *  This function is to turn off bass.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_bass_enhance_turn_off(void);
#endif /*#if defined(__BES_BASS_SUPPORT__)*/

#if defined(__BES_LOUDNESS_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_loudness_turn_on
 * DESCRIPTION
 *  This function is to turn on loudness.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_loudness_turn_on(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_loudness_turn_off
 * DESCRIPTION
 *  This function is to turn off loudness.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_loudness_turn_off(void);
#endif /*#if defined(__BES_LOUDNESS_SUPPORT__)*/

/*-----------------------------------------------------------------------------
                                  DRM
 ----------------------------------------------------------------------------*/
 
#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_drm_disable_consume_count
 * DESCRIPTION
 *  This function is to disable DRM right consume when play file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_drm_disable_consume_count(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_drm_disable_consume_all
 * DESCRIPTION
 *  This function is to disable DRM right consume, including "Time" and "Count"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_drm_disable_consume_all(void);
#endif /*__DRM_SUPPORT__*/

/*-----------------------------------------------------------------------------
                                  Internal Use
 ----------------------------------------------------------------------------*/
 
/* DOM-NOT_FOR_SDK-BEGIN */

#ifdef VRSI_ENABLE
extern void mdi_audio_vrsi_trn_prompt_req_hdlr(void *inMsg);
extern void mdi_audio_vrsi_trn_result_ind(void *inMsg);
extern void mdi_audio_vrsi_rcg_prompt_req_hdlr(void *inMsg);
extern void mdi_audio_vrsi_rcg_result_ind(void *inMsg);
extern void mdi_audio_vrsi_err_ind(void *inMsg);
extern mdi_result mdi_audio_vrsi_init(U16 app_id, mdi_ext_callback handler, void *user_data);
extern U32 mdi_audio_vrsi_new_session_id(void);
extern void mdi_audio_vrsi_stop(U32 session_id);
extern void mdi_audio_vrsi_close(void);
extern void mdi_audio_vrsi_play_tag_finish_ind(void *inMsg);
extern mdi_result mdi_audio_vrsi_play_tag(U32 session_id, U8 *grammar, U16 tag_id, U8 volume, U8 output_path);
extern void mdi_audio_vrsi_play_tts_finish_ind(void *inMsg);
extern mdi_result mdi_audio_vrsi_play_TTS(U32 session_id, U16 *text, U8 volume, U8 output_path, U8 lang);
extern void mdi_audio_vrsi_register_record(void);
extern void mdi_audio_vrsi_unregister_record(void);
#endif /* VRSI_ENABLE */ 

#ifdef VR_ENABLE
extern mdi_result mdi_audio_play_voice_tag(
                    U8 mode,
                    U8 lang,
                    U8 group_id,
                    U16 word_id,
                    mdi_ext_callback handler,
                    void *user_data);
extern mdi_result mdi_audio_start_vr_voice_record(
                    U32 session_id,
                    U8 seq_no,
                    mdi_ext_callback handler,
                    void *user_data);
extern mdi_result mdi_audio_stop_vr_voice_record(void);
extern U32 mdi_audio_vr_rcg_session_id(void);
extern U32 mdi_audio_vr_trn_session_id(void);
extern U16 mdi_audio_vr_rcg_result_id_length(void);
extern U16 *mdi_audio_vr_rcg_result_id_array(void);
extern void mdi_audio_vr_rcg_result_ind(void *inMsg);
extern void mdi_audio_vr_trn_result_ind(void *inMsg);
extern void mdi_audio_vr_abort(void);
#endif /* VR_ENABLE */

/* General purpose TTS */
#ifdef __GENERAL_TTS__
extern mdi_result mdi_audio_tts_set_attr(U32 attr_id, U32 attr_value);
extern mdi_result mdi_audio_tts_play(mdi_audio_tts_struct tts_param);
extern mdi_result mdi_audio_tts_stop(void);
extern mdi_result mdi_audio_tts_pause(void);
extern mdi_result mdi_audio_tts_resume(void);
#endif /*__GENERAL_TTS__*/

#if defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS)
extern void mdi_audio_play_text_event_handler(mdi_result result, void *user_data);
extern mdi_result mdi_audio_play_text_with_vol_path(
                    U8 *words,
                    S32 len,
                    S32 msecs,
                    mdi_ext_callback handler,
                    void* user_data,
                    U8 volume,
                    U8 path);
#endif /* defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS) */ 

#if defined(BGSND_ENABLE)
extern MMI_BOOL mdi_audio_snd_is_idle(void);
extern mdi_result mdi_audio_snd_check_string_format(void *audio_data, U32 len);
extern mdi_result mdi_audio_snd_check_file_format(void *file_name);
extern mdi_result mdi_audio_snd_play_string_with_vol_path(
                    void *audio_data,
                    U32 len,
                    U16 repeat,
                    mdi_ext_callback handler,
                    void *user_data,
                    U8 volume,
                    U8 path);
extern mdi_result mdi_audio_snd_play_string_with_vol_path_type(
            void *audio_data,
            U32 len,
            U16 repeat,
            U8 format,
            mdi_ext_callback handler,
            void* user_data,
            U8 volume,
            U8 path);
extern mdi_result mdi_audio_snd_play_file_with_vol_path(
                    void *file_name,
                    U16 repeat,
                    mdi_ext_callback handler,
                    void *user_data,
                    U8 volume,
                    U8 path);
extern void mdi_audio_snd_play_finish_ind(void *inMsg);
extern mdi_result mdi_audio_snd_stop(void);
extern mdi_result mdi_audio_snd_set_volume(U8 volume);
#endif /* defined(BGSND_ENABLE) */ 

/* BT */
#ifdef __BT_SPK_VOL_CONTROL__
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_sync_volume_from_bt
 * DESCRIPTION
 *  This function is to synchronize current application volume to BT headset
 * PARAMETERS
 *   bt_volume      : [IN] Bluetooth volume from 0 ~ 15
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_sync_volume_from_bt(U8 bt_volume);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_volume_to_bt
 * DESCRIPTION
 *  This function is to set volume to bluetooth, use the following mapping
 *  7-Level -> 16 Level Mapping 
 *    0 ->    0
 *    1 ->    2
 *    2 ->    5
 *    3 ->    7
 *    4 ->   10
 *    5 ->   13
 *    6 ->   15
 *
 * PARAMETERS
 *   volume     : [IN] 7-level or 16-level volume from application
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_set_volume_to_bt(U8 volume);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bt_get_volume_level_from_type
 * DESCRIPTION
 *  7-Level <- 16 Level Mapping 
 *    0 <-    0
 *    1 <-    1   2   3
 *    2 <-    4   5   6
 *    3 <-    7   8   9
 *    4 <-   10  11  12
 *    5 <-   13  14
 *    6 <-   15
 * PARAMETERS
 *   bt_volume: bluetooth volume from 0 ~ 15
 * RETURNS
 *  void
 *****************************************************************************/
extern U8 mdi_audio_bt_get_volume_level_from_type(U8 bt_volume, U8 volume_lvl_type);
#endif /* __BT_SPK_VOL_CONTROL__ */

extern void mdi_audio_bt_init(U8 profile, mdi_bt_callback open_handler, mdi_bt_callback close_handler);
extern U8 mdi_audio_bt_get_stream_status(U8 profile);
extern void mdi_audio_bt_close_stream_ind(void *msg);
extern void mdi_audio_bt_close_stream_cnf(void *msg);
extern void mdi_audio_bt_open_stream_ind(void *msg);
extern void mdi_audio_bt_open_stream_cnf(void *msg);
extern void mdi_audio_bt_open_stream_req(void *msg);
extern MMI_BOOL mdi_audio_bt_open_stream(U8 profile, U16 connect_id);
extern MMI_BOOL mdi_audio_bt_close_stream(U8 profile);
extern MMI_BOOL mdi_audio_bt_is_stream_open(U8 profile);
extern void mdi_audio_bt_hfp_turn_on(void);
extern void mdi_audio_bt_hfp_turn_off(void);

/******************************************************************
* FUNCTION
*    mdi_audio_set_sco_mode
* DESCRIPTION
*    This function is to pre-set sco mode so that we can connect normal Cordless SCO
* PARAMETERS
*    MDI_AUD_BT_SCO_MODE_DEFAULT: Normal SCO
*    MDI_AUD_BT_SCO_MODE_FM: SCO for FM
*    MDI_AUD_BT_SCO_MODE_ATV: SCO for ATV
*    MDI_AUD_BT_SCO_MODE_BT_DIALER: SCO for BT Dialer
* RETURNS
*    void
*  
******************************************************************/
extern void mdi_audio_set_sco_mode(U8 mode);

extern MMI_BOOL mdi_audio_bt_is_a2dp_codec_open(void);

#ifdef __VOICE_CHANGER_SUPPORT__
extern kal_bool mdi_audio_set_voice_changer_mode(SPH_VOICE_CHANGER_MODE mode);
extern SPH_VOICE_CHANGER_MODE mdi_audio_get_voice_changer_mode(void);
#endif

#ifdef __LINE_IN_SUPPORT__
extern void mdi_audio_enable_bt_box_linein(kal_bool on);
extern void mdi_audio_force_use_linein_mic(kal_bool force_use);
#endif

extern void mdi_audio_enable_megaphone(kal_bool on);


#ifdef __KARAOKE_SUPPORT__
extern Media_Kara_opt_mode mdi_audio_get_karaoke_mode();
extern void mdi_audio_set_karaoke_mode(Media_Kara_opt_mode mode, void *file_name);
extern void mdi_audio_set_karaoke_channel(Media_KaraRec_Mix_CH channel);
extern void mdi_audio_set_karaoke_digitgain(kal_uint16 unum,kal_uint16 uden);
#ifdef __KARAOKE_NEED_KEEP_SRC_PATH__
extern kal_int32 mdi_audio_karaoke_remix_turn_on(kal_wchar* filename, kal_uint32 msRecordStartTime, kal_uint32 msAudioSeekTime);
extern void mdi_audio_karaoke_remix_turn_off(void);
extern void mdi_audio_karaoke_set_remix_mode(Media_KaraRec_Mix_CH ch_mode);
extern void mdi_audio_karaoke_set_remix_audio_gain(kal_uint16 audio_gain);
extern void mdi_audio_karaoke_set_remix_voice_gain(kal_uint16 voice_gain);
#endif

#endif


/* Speech */
mdi_result mdi_audio_speech_encode_start(kal_int8 rtp_handle);
mdi_result mdi_audio_speech_encode_stop(kal_int8 rtp_handle);
mdi_result mdi_audio_speech_decode_start(kal_int8 rtp_handle);
mdi_result mdi_audio_speech_decode_stop(kal_int8 rtp_handle);
mdi_result mdi_audio_speech_mixer_add(kal_int8 rtp_handle);
mdi_result mdi_audio_speech_mixer_remove(kal_int8 rtp_handle);
mdi_result mdi_audio_speech_dtmf_start(kal_int8 rtp_handle, kal_uint8 code, kal_uint8 type);
mdi_result mdi_audio_speech_dtmf_stop(kal_int8 rtp_handle);

#if defined(__KEY_TONE_DETECTION__)
extern mdi_result mdi_audio_start_keytone_detect(void (*callback)(S16 key_ascii));
extern void mdi_audio_stop_keytone_detect(void);
#endif /*__KEY_TONE_DETECTION__*/

/* J2ME */
#if defined(__J2ME__)
extern MMI_BOOL mdi_audio_is_able_to_use_by_other_task(void);
extern void mdi_audio_start_use_by_other_task(mdi_ext_callback handler, void *user_data);
extern void mdi_audio_stop_use_by_other_task(void);
extern void mdi_audio_terminate_use_by_other_task(void);
#endif /*#if defined(__J2ME__)*/

/* Store/Restore */
extern mdi_result mdi_audio_store_file(mdi_handle audio_handle);
extern mdi_result mdi_audio_restore_file_with_vol_path(
                    void *file_name,
                    U8 play_style,
                    void *cache_p,
                    mdi_ext_callback handler,
                    void* user_data,
                    U8 volume,
                    U8 path);

/* Mutex */
extern MMI_BOOL mdi_audio_mutex_lock_no_wait(CHAR* file_p, U32 line_p);
extern void mdi_audio_mutex_lock(CHAR* file_p, U32 line_p);
extern void mdi_audio_mutex_unlock(CHAR* file_p, U32 line_p);

/* Misc */
extern void mdi_audio_set_hw_mute(MMI_BOOL set_mute);
extern void mdi_audio_set_pseudo_play_file_callback(mdi_ext_callback callback, void *user_data);
extern MMI_ID_TYPE mdi_audio_get_error_info(MDI_RESULT error_code, mmi_event_notify_enum* popup_type);
extern mdi_result mdi_audio_mma_get_duration_by_handle(mdi_handle handle, U32* duration);
extern void mdi_audio_set_dual_mic_nr(MMI_BOOL is_enable);
extern void mdi_audio_init(void);
extern void mdi_audio_init_event_hdlrs(void);
extern void mdi_audio_start_background_timer(void);
extern void mdi_audio_stop_background_timer(void);
extern MMI_BOOL mdi_audio_message_dispatcher(void *ilm_ptr);
extern void mdi_audio_fmr_rds_event_hdlr(void *inMsg);

/* DOM-NOT_FOR_SDK-END */

#endif /* _MDI_AUDIO_H_ */ 

