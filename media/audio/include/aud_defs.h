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
 * Filename:
 * ---------
 * aud_defs.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary definitions of audio manager task.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _AUD_DEFS_H
#define _AUD_DEFS_H

/*-----------------------------------------------------------------------------
                    macros, defines
-----------------------------------------------------------------------------*/
/* Volume control bits */
#define _VOL_CTRL_RAW_DATA                          ((kal_uint64) (0x8000000000000000))
#define _VOL_CTRL_PURE_GAIN                         ((kal_uint64) (0x4000000000000000))
#define _VOL_CTRL_N_LEVEL                           ((kal_uint64) (0x2000000000000000))
#define _VOL_CTRL_MUTE                              ((kal_uint64) (0x1000000000000000))

/* Volume control */
#define MED_AUD_VOL_GEN_PURE_GAIN(level, gain) \
    ((kal_uint64)(level) | ((kal_uint64)(gain) << 8) | _VOL_CTRL_PURE_GAIN)
#define MED_AUD_VOL_GEN_RAW_DATA(level, data, dual_aux) \
    ((kal_uint64)(level) | ((kal_uint64)(data) << 8) | ((kal_uint64)(dual_aux & 0x0003FFFF) << 40) | _VOL_CTRL_RAW_DATA)
#define MED_AUD_VOL_GEN_N_LEVEL_DATA(level, max_gain, gain_step) \
    ((kal_uint64)(level) | ((kal_uint64)(max_gain) << 8) | ((kal_uint64)(gain_step) << 16) | _VOL_CTRL_N_LEVEL)
#define MED_AUD_VOL_SET_MUTE(volume) \
    ((kal_uint64)(volume) | _VOL_CTRL_MUTE)

/* Type-specific MACRO */
#define MED_AUD_VOL_GET_RAW_VOLUME_DATA(vol)        ((kal_uint32)((vol & 0x000000FFFFFFFF00) >> 8))
#define MED_AUD_VOL_GET_RAW_VOLUME_DUAL_AUX(vol)    ((kal_uint32)((vol & 0x03FFFF0000000000) >> 40))
#define MED_AUD_VOL_GET_RAW_VOLUME_LEVEL(vol)       ((kal_uint8) ((vol & 0x00000000000000FF)))
#define MED_AUD_VOL_GET_PURE_VOLUME_GAIN(vol)       ((kal_uint8) ((vol & 0x000000000000FF00) >> 8))
#define MED_AUD_VOL_GET_PURE_VOLUME_LEVEL(vol)      ((kal_uint8) ((vol & 0x00000000000000FF)))
#define MED_AUD_VOL_GET_N_LEVEL_MAX_GAIN(vol)       ((kal_uint8) ((vol & 0x000000000000FF00) >> 8))
#define MED_AUD_VOL_GET_N_LEVEL_GAIN_STEP(vol)      ((kal_uint8) ((vol & 0x0000000000FF0000) >> 16))
#define MED_AUD_VOL_GET_N_LEVEL_VOLUME_LEVEL(vol)   ((kal_uint8) ((vol & 0x00000000000000FF)))

/* General MACRO for pure gain, raw data and n-level data */
#define MED_AUD_VOL_GET_VOLUME_LEVEL(vol)           ((kal_uint8) ((vol & 0x00000000000000FF)))
#define MED_AUD_VOL_GET_VOLUME_CONTROL(vol)         ((kal_uint8) ((vol & 0xFF00000000000000) >> 56))
#define MED_AUD_VOL_GET_VOLUME_DATA(vol)            ((kal_uint32)((vol & 0x000000FFFFFFFF00) >> 8))

/* Query volume control */
#define MED_AUD_VOL_CTRL_IS_RAW_DATA(vol)           ((kal_uint64)(vol) & _VOL_CTRL_RAW_DATA)
#define MED_AUD_VOL_CTRL_IS_PURE_GAIN(vol)          ((kal_uint64)(vol) & _VOL_CTRL_PURE_GAIN)
#define MED_AUD_VOL_CTRL_IS_N_LEVEL(vol)            ((kal_uint64)(vol) & _VOL_CTRL_N_LEVEL)
#define MED_AUD_VOL_CTRL_IS_MUTE(vol)               ((kal_uint64)(vol) & _VOL_CTRL_MUTE)

/* Legacy volume settings */
#define AUD_MAX_VOLUME_LEVEL                        (7)
#define AUD_VOL_IS_MUTE_AT_LEVEL_0(vol)             (vol & 0x40)    /* Mute at level 0 */
#define AUD_VOL_IS_N_LEVEL_VOLUME(vol)              (vol & 0x80)    /* N-level volume */
#define AUD_VOL_IS_7_LEVEL_VOLUME(vol)              (!(vol & 0x80)) /* 7-level volume */
#define AUD_VOL_IS_MUTE(vol)                        ((vol & 0x40) && ((vol & 0x3F) == 0)) /* Mute */
#define AUD_VOL_GET_VOLUME_LEVEL(vol)               (vol & 0x3F)

/* Headers */
#define AMR_HEADER                                  "#!AMR\n"
#define AWB_HEADER                                  "#!AMR-WB\n"

/* Size of cache table */
#define AUD_CACHE_TABLE_SIZE                        (2048)

/* RDS data size */
#define FM_RDS_MAX_DATA_BUFF_SIZE                   (64)
 
/*-----------------------------------------------------------------------------
                    typedefs, enums
-----------------------------------------------------------------------------*/

/* audio type */
typedef enum
{
    AUD_TYPE_NONE = 0,                      /* 0: none */
    AUD_TYPE_SPEECH,                        /* 1: speech */
    AUD_TYPE_TONE,                          /* 2: tone */
    AUD_TYPE_KEYTONE,                       /* 3: keytone */
    AUD_TYPE_MELODY,                        /* 4: melody */
    AUD_TYPE_VM,                            /* 5: VM */
    AUD_TYPE_DAF,                           /* 6: MP3 */
    AUD_TYPE_VR,                            /* 7: VR */
    AUD_TYPE_MIC,                           /* 8: Microphone */
    AUD_TYPE_FMR,                           /* 9: FM Radio */
    AUD_TYPE_BGSND,                         /* 10: Background sound */
    AUD_TYPE_ATV                            /* 11: ATV */
} aud_type_enum;

/* volume type */
typedef enum
{
    AUD_VOLUME_CTN = 0,                     /* 0: tone */
    AUD_VOLUME_KEY,                         /* 1: keytone */
    AUD_VOLUME_MIC,                         /* 2: microphone */
    AUD_VOLUME_FMR,                         /* 3: FM Radio */
    AUD_VOLUME_SPH,                         /* 4: Speech */
    AUD_VOLUME_SID,                         /* 5: Side-tone */
    AUD_VOLUME_MEDIA,                       /* 6: Multi-Media */
    AUD_VOLUME_TVO,                         /* 7: TV-OUT */
    AUD_VOLUME_ATV,                         /* 8: ATV */
    
    AUD_MAX_VOLUME_TYPE
} aud_volume_enum;

/* Audio path */
typedef enum
{
    AUD_PATH_UNKNOWN  = 0x00,               /* Unknown */
    AUD_PATH_RECEIVER = 0x01,               /* Speaker */
    AUD_PATH_HEADSET  = 0x02,               /* Headset */
    AUD_PATH_SPEAKER  = 0x04,               /* Loud-speaker */
    AUD_PATH_DUAL     = 0x08,               /* Both headset and loud-speaker */
    AUD_PATH_BT       = 0x10                /* BT */
} aud_path_enum;

typedef enum
{
    AUD_STATE_CHANGE_SCO_CONNECT = 0,       /* SCO is connected */
    AUD_STATE_CHANGE_SCO_DISCONNECT,        /* SCO is disconnected */
    AUD_STATE_CHANGE_A2DP_CONNECT,          /* A2DP is connected */
    AUD_STATE_CHANGE_A2DP_DISCONNECT,       /* A2DP is disconnected */
    AUD_STATE_CHANGE_ATV_ON,                /* ATV is on */
    AUD_STATE_CHANGE_ATV_OFF,               /* ATV is off */
    AUD_STATE_CHANGE_TV_OUT_PLUG_IN,        /* Plug in TV-Out cable */
    AUD_STATE_CHANGE_TV_OUT_PLUG_OUT,       /* Plug out TV-Out cable */
    AUD_STATE_CHANGE_MMA_PLAYBACK_START,    /* Start MMA playback */

    AUD_STATE_CHANGE_LAST_ENTRY
} aud_state_change_reason_enum;

typedef enum
{
    AUD_SEEK_REASON_DONE = 0,               /* Seek done */
    AUD_SEEK_REASON_TERMINATED,             /* Seek terminated for some reason */
    AUD_SEEK_REASON_FAIL                    /* Seek failed */
} aud_seek_reason_enum;

/* module index */
typedef enum
{
    AUD_MODULE_IDX_AUDIO = 0,               /* 0 */
    AUD_MODULE_IDX_MEDIA,                   /* 1 */
    AUD_MODULE_IDX_MELODY,                  /* 2 */
    AUD_MODULE_IDX_MMA,                     /* 3 */
    AUD_MODULE_IDX_BUILD_CACHE,             /* 4 */
    AUD_MODULE_IDX_RECORD,                  /* 5 */
    AUD_MODULE_IDX_VM,                      /* 6 */
    AUD_MODULE_IDX_FM_RADIO,                /* 7 */
    AUD_MODULE_IDX_BT_A2DP,                 /* 8 */
    AUD_MODULE_IDX_BT_HFP,                  /* 9 */
    AUD_MODULE_IDX_VRSI,                    /* 10 */
    AUD_MODULE_IDX_VRSD,                    /* 11 */
    AUD_MODULE_IDX_TTS,                     /* 12 */
    AUD_MODULE_IDX_MODIS,                   /* 13 */
    AUD_MODULE_IDX_UTILITY                  /* 14 */
} aud_module_enum;

typedef enum
{
    AUD_VM_DIR_DL,                          /* Uplink */
    AUD_VM_DIR_UL,                          /* Downlink */
    AUD_VM_DIR_BOTH                         /* Both direction */
} aud_vm_record_dir_enum;

typedef enum
{
    AUD_RES_OK,                             /* OK */
    AUD_RES_FAIL,                           /* General Fail */
    AUD_RES_BUSY,                           /* system busy */
    AUD_RES_DISC_FULL,                      /* Memory full */
    AUD_RES_OPEN_FILE_FAIL,                 /* open file fail */
    AUD_RES_END_OF_FILE,
    AUD_RES_TERMINATED,
    AUD_RES_BAD_FORMAT,
    AUD_RES_INVALID_FORMAT,
    AUD_RES_ERROR,
    AUD_RES_NO_DISC,
    AUD_RES_NOT_ENOUGH_SPACE,
    AUD_RES_RESUME,
    AUD_RES_BLOCKED
} aud_res_enum;

/* this enum has to sync with Media_Format in l1audio.h */
typedef enum
{
    MEDIA_FORMAT_NONE = -1,
    MEDIA_GSM_FR,                           /* 0 */
    MEDIA_GSM_HR,                           /* 1 */
    MEDIA_GSM_EFR,                          /* 2 */
    MEDIA_AMR,                              /* 3 */
    MEDIA_AMR_WB,                           /* 4 */
    MEDIA_DAF,                              /* 5 */
    MEDIA_AAC,                              /* 6 */
    MEDIA_PCM_8K,                           /* 7 */
    MEDIA_PCM_16K,                          /* 8 */
    MEDIA_G711_ALAW,                        /* 9 */
    MEDIA_G711_ULAW,                        /* 10 */
    MEDIA_DVI_ADPCM,                        /* 11 */
    MEDIA_VR,                               /* 12 */
    MEDIA_WAV,                              /* 13 */
    MEDIA_WAV_ALAW,                         /* 14 */
    MEDIA_WAV_ULAW,                         /* 15 */
    MEDIA_WAV_DVI_ADPCM,                    /* 16 */
    MEDIA_SMF,                              /* 17 */
    MEDIA_IMELODY,                          /* 18 */
    MEDIA_SMF_SND,                          /* 19 */
    MEDIA_SMAF,                             /* 20 */
    MEDIA_3GP,                              /* 21 */
    /*Add format from l1audio.h*/
    MEDIA_VOIPEVL = 27,                     /* 27 (MEDIA_FORMAT_VOIPEVL) */
    MEDIA_VORBIS = 45,                      /* 45 (MEDIA_FORMAT_VORBIS) */
    NUM_OF_MEDIA_FORMAT
} media_format_enum;

/* Audio resources */
typedef enum
{
    AUD_RESOURCE_PLAYER,                   /* Player */
    AUD_RESOURCE_FMR_RECORD,               /* FRM record */
    AUD_RESOURCE_SND_RECORD,               /* Sound record */
    AUD_RESOURCE_SCO,                      /* SCO */
    AUD_RESOURCE_MMA,                      /* MMA */
    AUD_RESOURCE_AUDIO                     /* Audio resource */
} aud_resource_enum;

typedef enum
{
    AUD_MEDIA_PLAY_MODE_NONE,
    AUD_VM_PLAY_AS_RING,
    AUD_VM_PLAY_AS_MEMO,
    AUD_MEDIA_PLAY_AS_RING,
    AUD_MEDIA_PLAY_AS_SONG,
    NUM_OF_MEDIA_PLAY_MODE
}
aud_media_play_mode_enum;

typedef enum
{
    AUD_MEDIA_QUERY_SEEKABLE,
    AUD_MEDIA_QUERY_PAUSABLE,
    NUM_OF_MEDIA_QUERY_MODE
}
aud_media_query_abilty_enum;

typedef enum
{
    AUD_ID,
    AUD_FILE,
    AUD_STRING,
    AUD_FM_RADIO,
    AUD_TTS,
    AUD_UNKNOWN_SOURCE_TYPE
}
aud_source_type_enum;

typedef enum
{
    AUD_MMA_PARAM_SET_ASYNC_MODE,
    AUD_MMA_PARAM_TOTAL
}aud_mma_param_enum;

/* Audio CTM */
typedef enum
{
    AUD_CTM_DIRECT_MODE,
    AUD_CTM_BAUDOT_MODE,
    AUD_CTM_HCO_MODE,
    AUD_CTM_VCO_MODE
} aud_ctm_interface_enum;

/* Audio clipper */
typedef enum
{ 
    AUD_TRIM_GET_CURRENT_TIME,   /* Get current time of trimming (kal_uint32*) */

    AUD_TRIM_GET_LAST_ENTRY
} aud_trim_get_type_enum;

typedef enum
{ 
    AUD_TRIM_SET_START_TIME,     /* Set start time (kal_uint32) */
    AUD_TRIM_SET_STOP_TIME,      /* Set stop time (kal_uint32) */
    AUD_TRIM_SET_CACHE_TABLE,    /* Set build cache table (kal_uint8*) */

    AUD_TRIM_SET_LAST_ENTRY
} aud_trim_set_type_enum;

#endif /* _AUD_DEFS_H */
