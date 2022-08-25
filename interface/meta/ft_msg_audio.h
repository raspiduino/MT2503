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
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   ft_msg_audio.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Messages definition of AUDIO category of FT Library
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *              HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __FT_MSG_AUDIO_H__
#define __FT_MSG_AUDIO_H__
#include "ft_msg_common.h"
#include "fs_type.h"
#include "l1audio.h"

/*******************************************************************
 * FT_L4AUD_REQ_ID related structure definition
 ******************************************************************/
#define FT_L4AUD_MAX_MELODY_FILE_NAME   MAX_MELODY_FILE_NAME
#define FT_L4AUD_MAX_MEDIA_FILE_NAME    MAX_MEDIA_FILE_NAME
#define FT_L4AUD_ERR_FILEPATH_TOO_LONG  0xFF
#define FT_L4AUD_ERR_FILEPATH_ERROR     0xFE
#define FT_L4AUD_ERR_PEER_BUF_ERROR     0xFD
#define FT_L4AUD_ERR_STILL_PLAYING      0xFC
#define FT_L4AUD_ERR_OP_NOT_SUPPORT     0xFB

/* operation */
typedef enum {
     FT_L4AUD_OP_AUDIO_QUERY_ID = 0
    ,FT_L4AUD_OP_AUDIO_PLAY
    ,FT_L4AUD_OP_AUDIO_PLAY_BY_NAME
    ,FT_L4AUD_OP_AUDIO_DEMO_IMY
    ,FT_L4AUD_OP_AUDIO_STOP
    ,FT_L4AUD_OP_AUDIO_PLAY_OVER_IND
    ,FT_L4AUD_OP_MEDIA_PLAY
    ,FT_L4AUD_OP_MEDIA_STOP
    ,FT_L4AUD_OP_MEDIA_PLAY_OVER_IND
    ,FT_L4AUD_OP_SET_VOLUME
    ,FT_L4AUD_OP_SET_ECHO
    ,FT_L4AUD_OP_SET_MODE
    ,FT_L4AUD_OP_SET_GAIN
    ,FT_L4AUD_OP_TONE_LOOP_BACK_REC
    ,FT_L4AUD_OP_SET_LOUDSPK_FIR_COEFFS
    ,FT_L4AUD_OP_SET_SPEECH_COMMON
    ,FT_L4AUD_OP_SET_LOUDSPK_MODE
    ,FT_L4AUD_OP_SET_PLAYBACK_MAX_SWING
    ,FT_L4AUD_OP_SET_MELODY_FIR
    ,FT_L4AUD_OP_SET_SPEECH_COMMON_AND_MODE
    ,FT_L4AUD_OP_PLAY_FREQ_VOL_TONE
    ,FT_L4AUD_OP_STOP_FREQ_VOL_TONE
    ,FT_L4AUD_OP_TONE_LOOP_BACK_REC_2K
    ,FT_L4AUD_OP_TONE_LOOP_BACK_REC_2K_NORMAL
    ,FT_L4AUD_OP_GET_PROFILE_SETTINGS_BY_MODE
    ,FT_L4AUD_OP_SET_PROFILE_SETTINGS_BY_MODE
    ,FT_L4AUD_OP_GET_PARAM_SETTINGS_0809
    ,FT_L4AUD_OP_SET_PARAM_SETTINGS_0809
    ,FT_L4AUD_OP_SET_OUTPUT_DEV
    ,FT_L4AUD_OP_SET_OUTPUT_VOLUME
    ,FT_L4AUD_OP_PLAY_WAVE_FILE_BY_STREAM
    ,FT_L4AUD_OP_FREE_MEMORY
    ,FT_L4AUD_OP_PLAY_CUR_MEMORY_CONTENT
    ,FT_L4AUD_OP_STOP_L1AUD_PLAYING
    ,FT_L4AUD_OP_GET_AC_FILTER_TYPE
    ,FT_L4AUD_OP_SET_AC_FILTER_COEFF
    ,FT_L4AUD_OP_GET_GAIN_TYPE_SUPPORT
    ,FT_L4AUD_OP_SET_OUTPUT_DEV_EX
    ,FT_L4AUD_OP_END   // Note: need to update ft_fnc.c for func exist query!
}FT_L4AUD_OP;

typedef enum {
    FT_L4AUD_AUDIO_PLAY_CRESCENDO = 0,
    FT_L4AUD_AUDIO_PLAY_INFINITE = 1,
    FT_L4AUD_AUDIO_PLAY_ONCE = 2,
    FT_L4AUD_AUDIO_PLAY_DESCENDO =3
}FT_L4AUD_AUDIO_PLAY_STYLE;

/* request */
typedef struct {
    kal_uint16                  audio_id;       // default system embeded audio id
    FT_L4AUD_AUDIO_PLAY_STYLE   play_style;     // play style
}ft_l4aud_play_req;

typedef struct {
    kal_uint8                   volume;         // play volume, 0 ~ 255
}ft_l4aud_set_volume_req;

typedef struct {
    kal_uint8                   echoflag;           // echoflag true mean EchoOK
}ft_l4aud_set_echo;

typedef struct {
    kal_uint8                   modeflag;           // modeflag: normal, headset, loudspeaker
}ft_l4aud_set_mode;

typedef struct {
    kal_uint8                   type;
    kal_uint8                   gain;
}ft_l4aud_set_gain;

typedef struct {
    kal_uint16      fre;
    kal_uint8       spkgain;
    kal_uint8       micgain;
    kal_uint16      ulgain;
    kal_uint16      dlgain;
    kal_uint16      amp;
}ft_tone_loopbackrec_req;

typedef struct {
    kal_uint8       pivot;
    kal_uint32      buffer[500];
}ft_tone_loopbackrec_cnf;

typedef struct {
    kal_uint32      buffer[500];
}ft_tone_loopbackrec_cnf_2k;

typedef struct {
    kal_int16       in_fir_coeffs[45];
    kal_int16       out_fir_coeffs[45];
}ft_l4aud_set_loudspk_fir_coeffs_req;

typedef struct {
    kal_uint16 speech_common_para[12];
}ft_l4aud_set_speech_common_req;

typedef struct {
    kal_uint16 speech_loudspk_mode_para[16];  // change from 8 to 16, because at most: 16
}ft_l4aud_set_loudSpk_mode_req;

typedef struct {
    kal_uint16 Media_Playback_Maximum_Swing;
}ft_l4aud_set_playback_maximum_swing_req;

typedef struct {
    kal_int16 Melody_FIR_Output_Coeff_32k_Tbl1[25];
}ft_l4aud_set_melody_fir_output_coeffs_req;

typedef struct {
    kal_uint16 speech_common_para[12];
    kal_uint16 speech_loudspk_mode_para[16]; // change from 8 to 16, because at most: 16
}ft_l4aud_set_speech_common_and_mode_req;

typedef struct
{
    kal_uint8  m_ucVolume;
    kal_uint16 m_u2Freq;
}ft_l4aud_set_freq_vol_tone;

typedef struct
{
    kal_uint8   m_ucMode;
}ft_l4aud_get_profile_by_mode;

typedef struct
{
    kal_uint8 mode;
    kal_uint8 melody[7];
    kal_uint8 sound[7];
    kal_uint8 keytone[7];
    kal_uint8 speech[7];
    kal_uint8 mic[7];
    kal_uint8 sidetone;
    kal_uint8 max_melody_volume_gain;
    kal_uint8 melody_volume_gain_step;
    kal_uint8 tv_out_volume_gain[7];

}ft_l4aud_set_profile_by_mode;  // should be the same as audio_profile_struct

typedef struct
{
    kal_int16      speech_input_FIR_coeffs[6][45];
    kal_int16      speech_output_FIR_coeffs[6][45];
    kal_uint16     selected_FIR_output_index;
    kal_uint16     speech_common_para[12];
    kal_uint16     speech_mode_para[8][16];
    kal_uint16     speech_volume_para[3][7][4];
    kal_uint16     Media_Playback_Maximum_Swing;
    kal_int16      Melody_FIR_Coeff_Tbl[25];
    kal_int16      audio_compensation_coeff[2][45];
}ft_l4aud_set_param_0809;  // should be the same as audio_param_struct


typedef struct
{
    kal_bool    bBorrowMed;
    kal_bool    bIsStereo;
    kal_int8    i1BitPerSample;
    kal_uint16  u2SampleFreq;
    kal_bool    bForceVoice;

    kal_bool      bStop;

    kal_uint32    u4FrmIdx;
    kal_bool      bLastFrm;

    kal_uint32    offset;
    kal_uint32    u4BytesSent;

    kal_int8     i1SleepTime;
    kal_uint32   u4BufLen;
    kal_int8     buf[1600];

}ft_l4aud_play_wave_file_req_T;

typedef struct
{
    kal_bool       bStartPlay;
    kal_bool       bStopPlay;
    kal_uint32     u4FrmIdx;
    kal_uint32     offset;
    kal_uint32     u4BytesSent;
    kal_uint32     u4TargetBufSize;

}ft_l4aud_play_wave_file_cnf_T;

typedef struct
{
    kal_uint8 u1_ac_mode; // loudspeaker: 0, normal: 1
    kal_int16 i2_ac_coef[45];
}ft_l4aud_set_ac_filter_req_T;

typedef struct
{
     kal_uint8          u1_set_output_device;
     kal_uint16         u2_digital_gain;
}ft_l4aud_set_output_dev_with_dg_T;

typedef struct
{
    kal_uint32 msg_size;
    kal_uint32 msg_id;
    kal_uint32 cnf_msg_id;
    kal_uint32 finish_msg_id;
    kal_uint32 melody_offset;                                     /* this part is used in FT to replace the field in play_by_string_req */
    kal_uint8  buffer[200];                                       /* this part will be replaced by database */
} ft_l4aud_play_imy_hal_req;

typedef struct
{
    kal_uint32 msg_size;
    kal_uint32 msg_id;
    kal_uint32 cnf_msg_id;
    kal_uint8  buffer[200];                                       /* this part will be replaced by database */
} ft_l4aud_play_by_name_hal_req;

typedef struct
{
    kal_uint32 msg_size;
    kal_uint32 msg_id;
    kal_uint32 cnf_msg_id;
    kal_uint8  buffer[200];                                       /* this part will be replaced by database */
} ft_l4aud_stop_play_hal_req;

typedef struct
{
    kal_uint32 msg_size;
    kal_uint32 msg_id;
    kal_uint32 cnf_msg_id;
    kal_uint8  buffer[200];                                       /* this part will be replaced by database */
} ft_l4aud_get_audio_param_hal_req;

typedef struct
{
    kal_uint32 msg_size;
    kal_uint32 msg_id;
    kal_uint32 cnf_msg_id;
    kal_uint8  buffer[200];                                       /* this part will be replaced by database */
} ft_l4aud_set_audio_param_hal_req;

typedef struct
{
    kal_uint32 msg_size;
    kal_uint32 msg_id;
    kal_uint32 cnf_msg_id;
    kal_uint8  buffer[200];                                       /* this part will be replaced by database */
} ft_l4aud_get_audio_profile_by_mode_hal_req;

typedef struct
{
    kal_uint32 msg_size;
    kal_uint32 msg_id;
    kal_uint32 cnf_msg_id;
    kal_uint8  buffer[200];                                       /* this part will be replaced by database */
} ft_l4aud_set_audio_profile_by_mode_hal_req;

typedef struct
{
    kal_uint32 msg_size;
    kal_uint32 msg_id;
    kal_uint32 cnf_msg_id;
    kal_uint8  buffer[200];                                       /* this part will be replaced by database */
} ft_l4aud_set_volume_hal_req;

typedef union
{
    kal_uint32                  dummy;          // extend alignment to 4 bytes
    kal_uint8                   u1_set_output_device;
    kal_uint8                   u1_set_output_vol;
    ft_l4aud_play_req           play;
    ft_l4aud_set_echo           set_echo;
    ft_l4aud_set_mode           set_mode;
    ft_l4aud_set_gain           set_gain;
    ft_l4aud_set_volume_req     set_volume;
    ft_tone_loopbackrec_req     tone_loopbackrec;
    ft_l4aud_set_param_0809                   set_param_0809;
    ft_l4aud_play_imy_hal_req                 play_imy_hal;                    /* 11B HAL replacement */
    ft_l4aud_stop_play_hal_req                stop_play_by_name_hal;           /* 11B HAL replacement */
    ft_l4aud_set_freq_vol_tone                set_freq_vol_tone;
    ft_l4aud_set_volume_hal_req               set_volume_hal;                  /* 11B HAL replacement */
    ft_l4aud_get_profile_by_mode              get_profile_by_mode;
    ft_l4aud_set_profile_by_mode              set_profile_by_mode;
    ft_l4aud_set_ac_filter_req_T              set_ac_filter_req;
    ft_l4aud_play_wave_file_req_T             play_wave_req;
    ft_l4aud_play_by_name_hal_req             play_by_name_hal;                /* 11B HAL replacement */
    ft_l4aud_set_loudSpk_mode_req             set_loudSpk_mode;
    ft_l4aud_set_speech_common_req            set_speech_common;
    ft_l4aud_get_audio_param_hal_req          get_audio_param_hal;             /* 11B HAL replacement */
    ft_l4aud_set_audio_param_hal_req          set_audio_param_hal;             /* 11B HAL replacement */
    ft_l4aud_set_output_dev_with_dg_T         set_output_dev_and_dg;
    ft_l4aud_set_loudspk_fir_coeffs_req       set_loudspk_fir_coeffs;
    ft_l4aud_set_playback_maximum_swing_req   set_playback_maximum_swing;
    ft_l4aud_set_speech_common_and_mode_req   set_speech_common_and_mode;
    ft_l4aud_set_melody_fir_output_coeffs_req set_melody_fir_output_coeffs;
    ft_l4aud_get_audio_profile_by_mode_hal_req get_audio_profile_by_mode_hal;  /* 11B HAL replacement */
    ft_l4aud_set_audio_profile_by_mode_hal_req set_audio_profile_by_mode_hal;  /* 11B HAL replacement */
}ft_l4aud_request;

typedef struct {
    FT_H                        header;
    FT_L4AUD_OP                 l4aud_op;
    ft_l4aud_request            req;
}FT_L4AUD_REQ;


/* confirm */
typedef struct {
    kal_uint16                  min_ringtone_id;
    kal_uint16                  max_ringtone_id;
    kal_uint16                  min_midi_id;
    kal_uint16                  max_midi_id;
    kal_uint16                  min_sound_id;
    kal_uint16                  max_sound_id;
}ft_l4aud_query_id_cnf;

typedef enum
{
    FT_L4AUD_AC_FILTER_DSP_FIR = 0
    ,FT_L4AUD_AC_FILTER_HW_FIR
    ,FT_L4AUD_AC_FILTER_DSP_IIR
    ,FT_L4AUD_AC_FILTER_UNKNOWN = 100
}ft_l4aud_ac_filter_type_E;

typedef struct
{
     kal_uint8  u1_filter_type;
}ft_l4aud_get_ac_filter_type_cnf_T;

typedef struct
{
    kal_uint8 mode;
    kal_uint8 melody[7];
    kal_uint8 sound[7];
    kal_uint8 keytone[7];
    kal_uint8 speech[7];
    kal_uint8 mic[7];
    kal_uint8 sidetone;
    kal_uint8 max_melody_volume_gain;
    kal_uint8 melody_volume_gain_step;
    kal_uint8 tv_out_volume_gain[7];

}ft_l4aud_get_profile_by_mode_cnf;  // should be the same as audio_profile_struct in interface\media\med_struct.h

typedef struct
{
    kal_uint16 m_u2FailReason;
}ft_l4aud_set_profile_by_mode_cnf;

typedef struct
{
    kal_int16      speech_input_FIR_coeffs[6][45];
    kal_int16      speech_output_FIR_coeffs[6][45];
    kal_uint16     selected_FIR_output_index;
    kal_uint16     speech_common_para[12];
    kal_uint16     speech_mode_para[8][16];
    kal_uint16     speech_volume_para[3][7][4];
    kal_uint16     Media_Playback_Maximum_Swing;
    kal_int16      Melody_FIR_Coeff_Tbl[25];
    kal_int16      audio_compensation_coeff[2][45];
}ft_l4aud_get_param_cnf_0809;  // must the same as audio_param_struct in med_struct.h

typedef struct
{
    kal_uint16  m_u2FailReason;
}ft_l4aud_set_param_cnf;
typedef union {
    ft_l4aud_query_id_cnf       query_id;
    ft_tone_loopbackrec_cnf     tone_loopbackrec_cnf;
    ft_tone_loopbackrec_cnf_2k      tone_loopbackrec_cnf_2k;
    ft_l4aud_get_profile_by_mode_cnf      get_profile_cnf;
    ft_l4aud_set_profile_by_mode_cnf      set_profile_cnf;
    ft_l4aud_get_param_cnf_0809           get_param_cnf_0809;
    ft_l4aud_set_param_cnf                set_param_cnf;
    ft_l4aud_play_wave_file_cnf_T         play_wave_cnf;
    ft_l4aud_get_ac_filter_type_cnf_T       get_ac_filter_cnf;
    kal_uint32                  dummy;          // extend alignment to 4 bytes
}ft_l4aud_confirm;

typedef struct {
    FT_H                        header;
    FT_L4AUD_OP                 l4aud_op;
    kal_uint8                   status;
    ft_l4aud_confirm            cnf;
}FT_L4AUD_CNF;
/*******************************************************************
 * FT_L4AUD_REQ_EX_ID related structure definition
 ******************************************************************/
typedef enum
{
     FT_L4AUD_EX_OP_GET_DL_CAPABILITY = 0
    ,FT_L4AUD_EX_OP_SET_ACF_IIR
    ,FT_L4AUD_EX_OP_GET_GAIN_TABLE_INFO
    ,FT_L4AUD_EX_OP_GET_PGA_GAIN_MAP
    ,FT_L4AUD_EX_OP_GET_EXT_PGA_GAIN_MAP
    ,FT_L4AUD_EX_OP_GET_GAIN_TABLE_STRING_INFO
    ,FT_L4AUD_EX_OP_GET_SPEECH_MODE_TABLE_INFO
    ,FT_L4AUD_EX_OP_GET_EXT_PGA_GAIN_MAP_EX
    ,FT_L4AUD_EX_OP_SET_ACF_IIR_EX
    ,FT_L4AUD_EX_OP_SET_ACF_EX
    ,FT_L4AUD_EX_OP_START_RECORDING
    ,FT_L4AUD_EX_OP_STOP_RECORDING
    ,FT_L4AUD_EX_OP_QUERY_RECORDING
    ,FT_L4AUD_EX_OP_START_ECHO_LOOP
    ,FT_L4AUD_EX_OP_STOP_ECHO_LOOP
    ,FT_L4AUD_EX_OP_QUERY_ECHO_LOOP
    ,FT_L4AUD_EX_OP_QUERY_ECHO_LOOP_DATA_RATE
    ,FT_L4AUD_EX_OP_QUERY_SPEECH_CAPABILITY
    /* HD speech recording */
    ,FT_L4AUD_EX_OP_SP_QUERY_PARAMS_OF_SPEECH_ENHANCEMENT_MODE     /**< \brief query the speech enhancement mode/category/length for each speech enhancement mode/category name, return data in local parameter */
    ,FT_L4AUD_EX_OP_SP_QUERY_SPEECH_ENHANCEMENT_MODE_NAME          /**< \brief query the name of speech enhancement mode, return data in peer buffer */
    ,FT_L4AUD_EX_OP_SP_QUERY_SPEECH_ENHANCEMENT_CATEGORY_NAME      /**< \brief query the name of speech enhancement category, return data in peer buffer */
    ,FT_L4AUD_EX_OP_SP_QUERY_CATEGORY_OF_SPEECH_ENHANCEMENT_MODE   /**< \brief query the category of each speech enhancement mode, return data in peer buffer */
    ,FT_L4AUD_EX_OP_SP_QUERY_PARAMS_OF_SPEECH_FIR_MODE             /**< \brief query the number of speech fir mode for each band */
    /* audio flexible EQ */
    ,FT_L4AUD_EX_OP_AUDIO_QUERY_FLEXIBLE_EQ_BAND_NUM               /**< \brief query the number of flexible EQ bands */
    ,FT_L4AUD_EX_OP_AUDIO_SET_FLEXIBLE_EQ_MAGNITUDE                /**< \brief set the magnitude of flexible EQ bands */
    ,FT_L4AUD_EX_OP_AUDIO_SET_FLEXIBLE_EQ_INIT_PARAM               /**< \brief set the init parameter of flexible EQ */
    ,FT_L4AUD_EX_OP_AUDIO_SET_FLEXIBLE_EQ_ON_OFF
    ,FT_L4AUD_EX_OP_AUDIO_QUERY_BESLOUDNESS_VERSION    
    ,FT_L4AUD_EX_OP_END
}FT_L4AUD_EX_OP;


#define FT_L4AUD_GAIN_TABLE_FRAME_SIZE 1800

#define FT_L4AUD_VOL_TYPE_TONE 0
#define FT_L4AUD_VOL_TYPE_KT   1 // keytone
#define FT_L4AUD_VOL_TYPE_MIC  2 // microphone
#define FT_L4AUD_VOL_TYPE_FMR  3  // FM Radio
#define FT_L4AUD_VOL_TYPE_SPH  4  // speech
#define FT_L4AUD_VOL_TYPE_SID  5   // side tne
#define FT_L4AUD_VOL_TYPE_MEDIA 6  // media
#define FT_L4AUD_VOL_TYPE_TVOUT 7  // TV-out

#define FT_L4AUD_PATH_UNKNOWN   0x00
#define FT_L4AUD_PATH_RECEIVER  0x01
#define FT_L4AUD_PATH_HEADSET   0x02
#define FT_L4AUD_PATH_SPEAKER   0x04
#define FT_L4AUD_PATH_DUAL      0x08
#define FT_L4AUD_PATH_BT        0x10

#define FT_L4AUD_PGA_BUF_AUDIO   0
#define FT_L4AUD_PGA_BUF_VOICE   1
#define FT_L4AUD_PGA_BUF_UNKNOWN 2
#define FT_L4AUD_PGA_BUF_MIC     3

#define FT_L4AUD_GAIN_TABLE_UNKNOWN   -1
#define FT_L4AUD_GAIN_TABLE_PURE       0
#define FT_L4AUD_GAIN_TABLE_RAW        1
#define FT_L4AUD_GAIN_TABLE_N_LEVEL    2

typedef struct
{
    kal_uint8 u1VolType;
    kal_uint8 u1PathType;
    kal_uint16 u2SIdx; //start index: from 0
    kal_uint16 u2EIdx; // end index
    kal_bool  b_digital_gain_support;
    kal_int8  i1BufType;
    kal_uint8  u1ExtAmpType; //0/L1SP_EXT_DAC_BUF0(0x40)/L1SP_EXT_DAC_BUF1(0x80)
    kal_int8   i1GainTableType;  //kal_uint8  u1Dummy;
    kal_uint16 u2BufLevel;
    kal_uint16 u2ExtAmpCtrlPointNum;
}ft_l4aud_ex_gain_table_info_T;
typedef struct
{
    kal_int8   i1BufType;
    kal_uint16  u2BufLevel;
}ft_l4aud_get_pga_gain_map_T;
typedef struct
{
    kal_uint8  u1ExtDac;
    kal_uint16 u2CtrlPoint;
}ft_l4aud_get_ext_amp_map_T;
typedef struct
{
   kal_uint32    iir_coeff_int[4][6][3];
   kal_uint32    hsf_coeff_int[9][4];
}ft_l4aud_ex_set_acf_to_target_req_T;
typedef struct
{
    /// format (Media_Fromat)
    kal_uint32   fmt;
    /// param (0: narrow-band, 0xB: wide-band)
    kal_uint16   param;
    /// requested time (ms)
    kal_uint32   requested_time;
    // microphone volume
    kal_uint8   inputVolume;
}ft_l4aud_ex_recording_request_T;
typedef struct
{
    /// format (PCM2WAY format)
    kal_uint32   format;
    kal_int16    playDrive;
    kal_int16    recordDrive;
    kal_uint8    outputDevice;
    kal_uint8    outputVolume;
    kal_uint8    inputDevice;
    kal_uint8    inputVolume;
    kal_uint8    sidetoneVolume;
}ft_l4aud_ex_echoloop_request_T;
typedef struct
{
    /// isWideBand  : 0 is narrow band (8k), >0 is wide band(16k)
    kal_uint8 isWideBand;    
    /// isOutputFir : 0 is for input FIR, >0 is for output FIR
    kal_uint8 isOutputFir;
}ft_l4aud_ex_query_speech_fir_request_T;
typedef union
{
    kal_uint32                      dummy;
    kal_int8                        flexibleEqOn; /**< \brief the indicator that the flexible EQ is turn on/off(1: on, 0: off) */
    kal_uint32                      pcm2WayFormat;
    ft_l4aud_get_ext_amp_map_T      m_rExtAmpQuery;
    ft_l4aud_get_pga_gain_map_T     m_rPgaGainQuery;
    ft_l4aud_ex_echoloop_request_T  m_rEchoLoopParam;
    ft_l4aud_ex_recording_request_T m_rRecordingParam;
    ft_l4aud_ex_query_speech_fir_request_T m_rQuerySpeechFirReq;   
}ft_l4aud_ex_request;

typedef struct
{
    FT_H                   header;
    FT_L4AUD_EX_OP         l4aud_op;
    ft_l4aud_ex_request    req;
}FT_L4AUD_EX_REQ;

typedef struct
{
    kal_uint8           m_u1LastFrm;
    kal_uint8           m_u1CarriedNum;
    kal_uint16          m_u2AccuNum;
}ft_l4aud_gain_table_frm_info_T;
typedef struct
{
    kal_uint8 u1TotalLevel;
    kal_uint8 u1BitNum;
}ft_l4aud_ext_amp_map_info_T;
typedef struct
{
    // requested time (ms)
    kal_uint32 requested_time;
    // recorded offset (ms)
    kal_uint32 offset;
}ft_l4aud_ex_query_recording_T;
typedef struct
{
    kal_uint8 u1SpeechModeNum;
    kal_uint8 u1SpeechModeParaMaxNum;
}ft_l4aud_ex_speech_mode_table_info_T;
typedef struct
{
    /// total number of samples
    kal_uint32 totalSamples;
    /// progress
    kal_uint32 progress;
    /// stop flag
    kal_int32 stop;
}ft_l4aud_ex_query_echoloop_T;
typedef struct
{
    // bytes per second
    kal_uint32 playingRate;
    // bytes per second
    kal_uint32 recordingRate;
}ft_l4aud_ex_query_echoloop_pcm2way_rate_T;

typedef struct
{
    kal_int16  numberOfSpeechEnhancementMode;     /**< \brief the number of speech enhancement mode */
    kal_uint16 bufferLengthOfEachModeName;        /**< \brief buffer length of each speech enhancement mode name */
    kal_int16  numberOfSpeechEnhancementCategory; /**< \brief the number of categories for speech enhancement */
    kal_uint16 bufferLengthOfEachCategoryName;    /**< \brief buffer length of each speech enhancement category name */
}ft_l4aud_ex_query_speech_enhancement_params_t;

typedef struct
{
    kal_int16  numberOfAllFIRMode;                /**< \brief the number of speech FIR mode */  
}ft_l4aud_ex_query_speech_fir_params_t;

typedef struct
{
    kal_int16 numberOfSpeechEnhancementMode;  /**< \brief the number of speech enhancement mode */
    kal_uint16 bufferLengthOfEachName;        /**< \brief buffer length of each speech enhancement mode name */
}ft_l4aud_ex_query_speech_enhancement_mode_name_hdr_t;

typedef struct
{
    kal_int16 numberOfSpeechEnhancementCategory;  /**< \brief the number of speech enhancement catory */
    kal_uint16 bufferLengthOfEachName;            /**< \brief buffer length of each speech enhancement category name */
}ft_l4aud_ex_query_speech_enhancement_category_name_hdr_t;

typedef union
{
    kal_uint32                                dummy; /**< for backward compatiblity purpose, DO NOT REMOVE this field */
    kal_int16                                 numberOfSpeechEnhancementMode;     /**< \brief the number of speech enhancement mode */
    kal_int16                                 numberOfFlexibleEqBands; /**< \brief the number of flexible EQ bands */
    kal_int32                                 m_StatusCode;
    kal_uint32                                speechCapability;
    kal_uint32                                versionOfBesLoudness;    
    ft_l4aud_ext_amp_map_info_T               m_rExtAmpInfo;
    ft_l4aud_ex_query_echoloop_T              m_rQueryEcholoopStatus;
    ft_l4aud_ex_query_recording_T             m_rQueryStatus;
    ft_l4aud_gain_table_frm_info_T            m_rFrmInfo;
    ft_l4aud_ex_speech_mode_table_info_T      m_rSpModTblInfo;
    ft_l4aud_ex_query_echoloop_pcm2way_rate_T m_rQueryEcholoopPcm2WayRate;
    ft_l4aud_ex_query_speech_enhancement_params_t            paramsOfSpeechEnhancement;    /**< \brief parameters for speech enhancement */
    ft_l4aud_ex_query_speech_enhancement_mode_name_hdr_t     speechEnhancementModeNameHdr; /**< \brief header of the query result for speech enhancement mode name */
    ft_l4aud_ex_query_speech_enhancement_category_name_hdr_t speechEnahcnementCategoryNameHdr; /**< \brief header of the query result for speech enhancement category name */
    ft_l4aud_ex_query_speech_fir_params_t                    paramsOfSpeechFir;            /**< \brief parameters for speech fir */
}ft_l4aud_ex_confirm;

typedef struct
{
    kal_int16  i2MaxGain;
    kal_uint16 u2Step;
    kal_uint16 u2TotalLevel;
}ft_l4aud_ex_dl_buf_info_T;

typedef struct
{
     kal_uint32                u4_dl_buf_type_by_mode[4]; //0:handset, 1:headset, 2: handsfree, 3: bt earphone
     ft_l4aud_ex_dl_buf_info_T buf_info[2]; // 0: audio buffer, 1: voice buffer
     kal_bool                  b_digital_gain_support;
     // always add new parameters at the end for backward compability

}ft_l4aud_ex_dl_cap_info_cnf_T; // stored in peer buffer
typedef struct  {
    FT_H                         header;
    FT_L4AUD_EX_OP               l4aud_op;
    kal_uint8                    status;
    ft_l4aud_ex_confirm          cnf;
}FT_L4AUD_EX_CNF;

/******************************************
 * Dual-Mic NR calibration (recording)
 *****************************************/
typedef struct
{
    FS_HANDLE     m_FsHandle;
    kal_int32     m_StatusCode;
    kal_uint32    m_TimeOffset;
    kal_uint32    m_RequestedTime;
    kal_bool      m_IsRunning;
    Media_Format  m_Format;
    WCHAR*        m_FilePath;
}FT_AudioRecording_T;
typedef enum
{
    FT_RECORDING_NORMAL = 0
    ,FT_RECORDING_DONE
    ,FT_RECORDING_FS_OPEN_FAILED
    ,FT_RECORDING_FS_CLOSE_FAILED
    ,FT_RECORDING_FS_CREATE_PATH_FAILED
    ,FT_RECORDING_FS_WRITE_FAILED
    ,FT_RECORDING_FS_GET_DRIVE_FAILED
    ,FT_RECORDING_APPDEND_INFO_FAILED
    ,FT_RECORDING_CASCADED_START
    ,FT_RECORDING_CASCADED_STOP
    ,FT_RECORDING_MEDIA_RECORD_FAILED
    ,FT_RECORDING_ALLOCATE_PCM_BUFFER_FAILED
    ,FT_RECORDING_INSUFFICIENT_FS_SPACE
}ft_audio_recording_context_status;

/*****************************************************************************
 *                         D A T A   T Y P E S (Ring Buffer)
 ****************************************************************************/
typedef struct FtPcmRingBufferStruct FT_PCMRB;
struct FtPcmRingBufferStruct
{
   kal_int16            *buffer;
   kal_int32            read;
   kal_int32            write;
   kal_int32            size;
};
kal_bool FT_PCMRB_Init( FT_PCMRB *rb, kal_int16 *buffer, kal_int32 buffer_size );
kal_int32 FT_PCMRB_GetFreeSpace( FT_PCMRB *rb );
kal_int32 FT_PCMRB_GetDataCount( FT_PCMRB *rb );
void FT_PCMRB_Write( FT_PCMRB *dest_rb, kal_int16 *src_buffer, kal_int32 size );
void FT_PCMRB_Read( FT_PCMRB *src_rb, kal_int16 *dest_buffer, kal_int32 size );
void FT_PCMRB_GetWriteBlock( FT_PCMRB *dest_rb, kal_int16 **write_ptr, kal_int32 *write_cnt );
void FT_PCMRB_GetReadBlock( FT_PCMRB *src_rb, kal_int16 **read_ptr, kal_int32 *read_cnt );
void FT_PCMRB_ShiftWritePointer( FT_PCMRB *rb, kal_int32 shamt );
void FT_PCMRB_ShiftReadPointer( FT_PCMRB *rb, kal_int32 shamt );
/******************************************
 * Dual-Mic NR calibration (echo testing)
 *****************************************/
typedef kal_uint32                          META_ECHO_LOOP_STATUS;
typedef kal_uint32                          META_ECHO_LOOP_EVENT;
typedef void (*META_ECHO_LOOP_CALLBACK)( void *host_data, META_ECHO_LOOP_EVENT event );
typedef struct
{
    kal_uint32                dir;
    FT_PCMRB                  rb;
    META_ECHO_LOOP_CALLBACK   callback;
    void                      *host_data;
}MetaEchoLoopHandleStruct;
typedef enum
{
    FT_ECHO_LOOP_NORMAL = 0
    ,FT_ECHO_LOOP_NOT_SUPPORTED
    ,FT_ECHO_LOOP_CANNOT_GET_DRV
    ,FT_ECHO_LOOP_ALLOCATE_ILM_FAILED
    ,FT_ECHO_LOOP_RUNNING
    ,FT_ECHO_LOOP_ALLOCATE_2WAY_BUFFER_FAILED
    ,FT_ECHO_LOOP_OPEN_SPEAK_FILE_FAILED
    ,FT_ECHO_LOOP_OPEN_RECORD_FILE_FAILED
}ft_audio_echo_loop_context_status;
typedef struct
{
    ft_l4aud_ex_echoloop_request_T echoloopParameters;
    kal_bool                       recordingOnly;
    const kal_int8*                fileName;
    kal_uint32                     requestedTime;
    kal_uint32                     pcm2wayType;
}FT_DUALMIC_CONTROL_T;
typedef MetaEchoLoopHandleStruct META_ECHO_LOOP_HANDLE;
META_ECHO_LOOP_HANDLE *FtEchoLoop_GetHandle ( kal_uint32 dir, kal_uint8 *buffer, kal_int32 buffer_size );
kal_int32 FtStartDualMicControl(const FT_DUALMIC_CONTROL_T* param);
kal_int32 FtStartDualMicEchoTestPreSetting(const ft_l4aud_ex_echoloop_request_T *request );
kal_int32 FtStartDualMicEchoTest(ft_l4aud_ex_echoloop_request_T *request);
kal_int32 FtStopDualMicEchoTest(void* event);
void FtQueryDualMicEchoTest(FT_L4AUD_EX_CNF *l4aud_ex_cnf);
typedef struct
{
    char                 riff_chunk[4];
    unsigned int         riff_size;
    char                 riff_type[4];
    char                 fmt_chunk[4];
    unsigned int         fmt_size;
    short                fmt_codec;
    short                channels;
    unsigned int         fs;
    unsigned int         bytes_per_sec;
    short                block_align;
    short                bits_per_sample;
    char                 data_chunk[4];
    unsigned int         data_size;
} FT_WAV_HEADER_T;
typedef struct 
{
   META_ECHO_LOOP_HANDLE   *echo_loop_handle;
   FS_HANDLE               fAutoRec;
   kal_uint32              sample_consume;
   kal_uint16              *pAutoRecBuffer;
   kal_uint16              indicator;
   /// PCM2WAY buffer (UL)
   kal_int16               *mic_buffer;
   kal_wchar               filename[40];
   kal_bool                waiting;
} FT_AUTO_RECORD_T;

typedef struct 
{
   META_ECHO_LOOP_HANDLE   *echo_loop_handle;
   FS_HANDLE               fAutoSpeak;
   kal_uint32              sample_elapsed;
   kal_uint16              *pAutoSpeakBuffer;
   kal_uint16              indicator;
   /// PCM2WAY buffer (DL)
   kal_int16               *spk_buffer;
   kal_wchar               filename[40];
   kal_bool                waiting;
   FT_WAV_HEADER_T         stWavHdr;
} FT_AUTO_SPEAK_T;
kal_int32 FtFreePcm2WayBuffer( FT_AUTO_RECORD_T* auto_record, FT_AUTO_SPEAK_T* auto_speak );
kal_int32 FtGetPcm2WayBuffer( FT_AUTO_RECORD_T* auto_record, FT_AUTO_SPEAK_T* auto_speak );
void FtAutoSpeakCallback( void *host_data, META_ECHO_LOOP_EVENT event );
void FtAutoSpeakGetDataFromFileToRB(kal_uint32 arg1, void *arg2);
kal_int32 FtAutoSpeakOpenFile( FT_AUTO_SPEAK_T* auto_speak );
void FtAutoRecCallback( void *host_data, META_ECHO_LOOP_EVENT event );
void FtAutoRecGetDataFromRBToFile( kal_uint32 arg1, void *arg2 );
kal_int32 FtAutoRecOpenFile( FT_AUTO_RECORD_T* auto_record );
kal_int32 FtAutoRecWriteFileHeader(void);
kal_int32 FtWriteInitParameter(void);
void FtDualMicRecordingInHisr( void );
void FtDualMicEchoTestLoopbackInHisr( void );
void FtDualMicRecordHandler( FT_AUTO_RECORD_T* autoRecord, kal_uint32 frameSize);
void FtDualMicSpeakHandler( FT_AUTO_SPEAK_T* autoSpeak, kal_uint32 frameSize);
void FtSendDualMicEchoTestStarted(void);
/**********************************************************
 * The L1SP is variable defined by in/out buffer/path in
 * custom/audio/audcoeff.c, the FT lib has to convert the
 * in/out between PC side and target side
 *********************************************************/
#define FT_L1SP_MICROPHONE1  0
#define FT_L1SP_MICROPHONE2  1
#define FT_L1SP_SPEAKER1     2
#define FT_L1SP_SPEAKER2     3
#define FT_L1SP_LOUD_SPEAKER 4
#endif // #ifndef __FT_MSG_AUDIO_H__
