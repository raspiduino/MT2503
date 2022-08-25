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
 *   mdi_bitstream.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
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
 *
 * removed!
 * removed!
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
 *******************************************************************************/

#ifndef _MDI_BITSTREAM_H_
#define _MDI_BITSTREAM_H_

#if defined(__BITSTREAM_API_SUPPORT__)



/***********************************************/
/* common structs & unions                     */
/***********************************************/

/* Enum of codec type of the bitstream. */
typedef enum
{
    MDI_BITSTREAM_CODEC_TYPE_NONE,  /* No type */
    MDI_BITSTREAM_CODEC_TYPE_SILENT, /* To play silence frame for video only file */
    MDI_BITSTREAM_CODEC_TYPE_AMR,   /* AMR */
    MDI_BITSTREAM_CODEC_TYPE_AMRWB, /* Wideband AMR */
    MDI_BITSTREAM_CODEC_TYPE_AAC,   /* AAC */
    MDI_BITSTREAM_CODEC_TYPE_DAF,   /* DAF */
    MDI_BITSTREAM_CODEC_TYPE_MP4A,  /* Mpeg-4 audio */
    MDI_BITSTREAM_CODEC_TYPE_MP4AG,
    MDI_BITSTREAM_CODEC_TYPE_WAV,   /* RAW data wav */
    MDI_BITSTREAM_CODEC_TYPE_ADPCM, /* compressed wav*/
    MDI_BITSTREAM_CODEC_TYPE_PCM,   /*RAW data, for input data strengh calculation*/
    MDI_BITSTREAM_CODEC_TYPE_TOTAL  /* Total codec type */
    
} mdi_bitstream_codec_type_enum;

typedef enum
{
    MDI_BITSTREAM_SAMPLE_FREQ_8000,   /* 8000  */
    MDI_BITSTREAM_SAMPLE_FREQ_11025,  /* 11025 */
    MDI_BITSTREAM_SAMPLE_FREQ_16000,  /* 16000 */
    MDI_BITSTREAM_SAMPLE_FREQ_22050,  /* 22050 */
    MDI_BITSTREAM_SAMPLE_FREQ_24000,  /* 24000 */
    MDI_BITSTREAM_SAMPLE_FREQ_32000,  /* 32000 */
    MDI_BITSTREAM_SAMPLE_FREQ_44100,  /* 44100 */
    MDI_BITSTREAM_SAMPLE_FREQ_48000,  /* 48000 */
    MDI_BITSTREAM_SAMPLE_FREQ_TOTAL   /* Total sample frequency number */
    
} mdi_bitstream_sample_freq_enum;


/* Bitstream record quality */
typedef enum
{
    MDI_BITSTREAM_RECORD_QUALITY_LOW,   /* Low quality */
    MDI_BITSTREAM_RECORD_QUALITY_MED,   /* Reserved */
    MDI_BITSTREAM_RECORD_QUALITY_HIGH,  /* High quality */
    MDI_BITSTREAM_RECORD_QUALITY_BEST,  /* Reserved */

    /* For MDI_BITSTREAM_CODEC_TYPE_AMR only */
    MDI_BITSTREAM_RECORD_AMR_4_75,      /* AMR 4.75 kbit/s */
    MDI_BITSTREAM_RECORD_AMR_5_15,      /* AMR 5.15 kbit/s */
    MDI_BITSTREAM_RECORD_AMR_5_9,       /* AMR 5.9  kbit/s */
    MDI_BITSTREAM_RECORD_AMR_6_7,       /* AMR 6.7  kbit/s */
    MDI_BITSTREAM_RECORD_AMR_7_4,       /* AMR 7.4  kbit/s */
    MDI_BITSTREAM_RECORD_AMR_7_95,      /* AMR 7.95 kbit/s */
    MDI_BITSTREAM_RECORD_AMR_10_2,      /* AMR 10.2 kbit/s */
    MDI_BITSTREAM_RECORD_AMR_12_2,      /* AMR 12.2 kbit/s */

    /* For MDI_BITSTREAM_CODEC_TYPE_AWB only */
    MDI_BITSTREAM_RECORD_AWB_6_6,       /* AWB 6.6   kbit/s */
    MDI_BITSTREAM_RECORD_AWB_8_85,      /* AWB 8.85  kbit/s */
    MDI_BITSTREAM_RECORD_AWB_12_65,     /* AWB 12.65 kbit/s */
    MDI_BITSTREAM_RECORD_AWB_14_25,     /* AWB 14.25 kbit/s */
    MDI_BITSTREAM_RECORD_AWB_15_85,     /* AWB 15.85 kbit/s */
    MDI_BITSTREAM_RECORD_AWB_18_25,     /* AWB 18.25 kbit/s */
    MDI_BITSTREAM_RECORD_AWB_19_85,     /* AWB 19.85 kbit/s */
    MDI_BITSTREAM_RECORD_AWB_23_05,     /* AWB 23.05 kbit/s */
    MDI_BITSTREAM_RECORD_AWB_23_85      /* AWB 23.85 kbit/s */
} mdi_bitstream_rec_quality_enum;

/* Get type of bitstream recorder */
typedef enum
{ 
    MDI_BITSTREAM_RECORD_GET_LENGTH,  /* Get the length of recorded data(U16*) */
    MDI_BITSTREAM_RECORD_GET_DATA,    /* Get recorded data(U16*) */
    MDI_BITSTREAM_RECORD_GET_STRENGTH /* Get current data strengh value */
} mdi_bitstream_record_get_type_enum;

/* Set type of bitstream recorder */
typedef enum
{ 
    MDI_BITSTREAM_RECORD_SET_PAUSE,  /* Pause bitstream record : data_p and data_len is ignored*/
    MDI_BITSTREAM_RECORD_SET_RESUME,  /* Resume bitstream record : data_p and data_len is ignored */
    MDI_BITSTREAM_RECORD_SET_CB_THRESHOLD /* Set callback threshold: default is 200 (words), pass a U32 value to data_p*/
} mdi_bitstream_record_set_type_enum;


typedef struct
{
    U32  timescale;
    	
} mdi_bitstream_audio_amr_cfg;


/* Codec config union */
typedef union
{
    mdi_bitstream_audio_amr_cfg amr;    /* AMR config */
} mdi_bitstream_codec_cfg;

/* Coniguration struct definition */
typedef struct
{ 
    U16 codec_type;                                 /* MDI_BITSTREAM_CODEC_TYPE_H264 or MDI_BITSTREAM_CODEC_TYPE_AMR */
    mdi_bitstream_codec_cfg codec_cfg;              /* Configuration to codec */
} mdi_bitstream_cfg_struct;

/* Config for audio playback struct*/
typedef struct
{ 
    mdi_bitstream_codec_type_enum codec_type;       /* Codec type */
    /* configures below are only for PCM type, otherwise, they could be ignored */
    MMI_BOOL isStereo;                              /* MMI_FALSE: mono, KAL_TRUE: stereo*/ 
    U8 bitPerSample;                                /* 8 or 16, commonly use 16 bits*/
    mdi_bitstream_sample_freq_enum sampleFreq;      /* 8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000*/
} mdi_bitstream_audio_cfg_struct;


/* Audio buffer status */
typedef struct
{
    U32 total_buf_size; /* Total buffer size */
    U32 free_buf_size;  /* Free buffer size */
    
} mdi_bitstream_audio_buffer_status;

/* Config for starting to play audio */
typedef struct
{
    U32 start_time; /* Set start time to driver */
    U8 volume;      /* Set play volume */
    U8 audio_path;  /* Set audio output path */
} mdi_bitstream_audio_start_param;

/* This structure is used to configure bit-stream recorder. 
 * The configuration could be extended later.
 *  codec_type		Codec type (mdi_bitstream_codec_type_enum). Currently, only 
 *                      MDI_BITSTREAM_CODEC_TYPE_AMR,
 *                      MDI_BITSTREAM_CODEC_TYPE_AMRWB,
 *                      MDI_BITSTREAM_CODEC_TYPE_WAV,
 *                      MDI_BITSTREAM_CODEC_TYPE_ADPCM
 *                  are supported.
 *  quality         Record quality (mdi_bitstream_rec_quality_enum).
 */
typedef struct
{ 
    U16 codec_type;  /* mdi_bitstream_codec_type_enum */
    U16 quality;     /* mdi_bitstream_rec_quality_enum */
} mdi_bitstream_record_cfg_struct;


void mdi_bitstream_init(void);

/***************************************************/
/*  Audio                                          */
/***************************************************/


/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_audio_open_handle
 * DESCRIPTION
 *  This function is to open a bitstream audio handle for playing
 * PARAMETERS
 *  handle          : [OUT] The audio handle opened and returned by MED
 *  p_cfg           : [IN] Audio playback configuration.
 *  result_callback : [IN] Callback function
 * RETURN VALUES
 *  MDI_RES_BITSTREAM_SUCCEED : Open successfully
 *****************************************************************************/
extern MDI_RESULT mdi_bitstream_audio_open_handle(
        MDI_HANDLE* p_handle,
        mdi_bitstream_audio_cfg_struct* p_cfg,
        void (*result_callback)(MDI_HANDLE handle, MDI_RESULT result));


/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_audio_close
 * DESCRIPTION
 *  This function is to close a bitstream audio handle
 * PARAMETERS
 *  handle          : [IN] The audio handle to be closed.
 * RETURN VALUES
 *  MDI_RES_BITSTREAM_SUCCEED : Close successfully.
 *****************************************************************************/
extern MDI_RESULT mdi_bitstream_audio_close(MDI_HANDLE handle);


/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_audio_get_buffer_status
 * DESCRIPTION
 *  This function is to get current bitstream ring buffer status
 * PARAMETERS
 *  handle      : [IN] The audio handle
 *  p_status    : [OUT] Buffer status
 * RETURN VALUES
 *  MDI_RES_BITSTREAM_SUCCEED : Get successfully.
 *****************************************************************************/
extern MDI_RESULT mdi_bitstream_audio_get_buffer_status(MDI_HANDLE handle, mdi_bitstream_audio_buffer_status* p_status);


/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_audio_put_data
 * DESCRIPTION
 *  This function is to put audio data into media ring buffer
 * PARAMETERS
 *  handle      : [IN] The audio handle
 *  p_buffer    : [IN] Buffer pointer for input data
 *  buffer_size : [IN] Buffer size for input data
 *  p_used_size : [OUT] The actual filled buffer size
 * RETURN VALUES
 *  MDI_RES_BITSTREAM_SUCCEED : Put successfully.
 *****************************************************************************/
extern MDI_RESULT mdi_bitstream_audio_put_data(MDI_HANDLE handle, U8* p_buffer, U32 buffer_size, U32* p_used_size);


/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_audio_put_frame
 * DESCRIPTION
 *  This function is to put a complete audio frame into media ring buffer.
 *  If the buffer is not enough, the entire frame will not be put into buffer.
 * PARAMETERS
 *  handle      : [IN] The audio handle
 *  p_buffer    : [IN] Buffer pointer for input data
 *  buffer_size : [IN] Buffer size for input data
 *  timestape   : [IN] Timestamp for audio frame
 * RETURN VALUES
 *  MDI_RES_BITSTREAM_SUCCEED : Put successfully.
 *****************************************************************************/
extern MDI_RESULT mdi_bitstream_audio_put_frame(MDI_HANDLE handle, U8* p_buffer, U32 buffer_size, U32 timestamp);


/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_audio_start
 * DESCRIPTION
 *  This function is to start play data in audio bitstream buffer
 * PARAMETERS
 *  handle  : [IN] The audio handle
 *  p_para  : [IN] Configuration for play
 * RETURN VALUES
 *  MDI_RES_BITSTREAM_SUCCEED : Start successfully.
 *****************************************************************************/
extern MDI_RESULT mdi_bitstream_audio_start(MDI_HANDLE handle, mdi_bitstream_audio_start_param* p_para);


/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_audio_stop
 * DESCRIPTION
 *  This function is to stop bitstream audio playback
 * PARAMETERS
 *  handle          : [IN] The audio handle
 * RETURN VALUES
 *  MDI_RES_BITSTREAM_SUCCEED : Stop successfully.
 *****************************************************************************/
extern MDI_RESULT mdi_bitstream_audio_stop(MDI_HANDLE handle);


/*****************************************************************************
* FUNCTION
*  mdi_bitstream_audio_finished
* DESCRIPTION
*  This function is to inform that all data is put, EOF
* PARAMETERS
*  handle          : [IN] The audio handle  
* RETURNS           
*  MDI_RES_BITSTREAM_SUCCEED : finished successfully.
*****************************************************************************/
extern MDI_RESULT mdi_bitstream_audio_finished(MDI_HANDLE handle);


/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_audio_get_play_time
 * DESCRIPTION
 *  This function is to get current play time, accumulation from start_time given in start request.
 * PARAMETERS
 *  handle              : [IN] The audio handle
 *  p_ms_current_time   : [OUT] Current play time
 * RETURN VALUES
 *  MDI_RES_BITSTREAM_SUCCEED : Get successfully.
 *****************************************************************************/
extern MDI_RESULT mdi_bitstream_audio_get_play_time(MDI_HANDLE handle, U32* p_ms_current_time);


/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_audio_get_open_handle_count
 * DESCRIPTION
 *  This function is to get total number of bitstream handle
 * PARAMETERS
 *  void
 * RETURNS
 *  U16 : Number of total opened bitstream audio handle
 *****************************************************************************/
extern U16 mdi_bitstream_audio_get_open_handle_count(void);



/*****************************************************************************/
/*  Bitstream Record                                                         */
/*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_record_open
 * DESCRIPTION
 *  This function is to open a record handle for bit-stream record.
 * PARAMETERS
 *  handle_p        [OUT]       Recorder handle.
 *  cfg_p           [IN]        Recorder configuration.
 *  callback        [IN]        Callback function to handle record event.
 * RETURNS
 *  MDI_RES_BITSTREAM_SUCCEED   Successful.
 *  Others                      Failed.
 *****************************************************************************/
extern MDI_RESULT mdi_bitstream_record_open(
        MDI_HANDLE* handle_p,
        mdi_bitstream_record_cfg_struct* cfg_p,
        void (*callback)(MDI_HANDLE handle, MDI_RESULT result));

/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_record_close
 * DESCRIPTION
 *  This function is to close a bit-stream record handle.
 * PARAMETERS
 *  handle_p        [IN]        Recorder handle.
 * RETURNS
 *  MDI_RES_BITSTREAM_SUCCEED   Successful.
 *  Others                      Failed.
 *****************************************************************************/
extern MDI_RESULT mdi_bitstream_record_close(MDI_HANDLE handle);

/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_record_start
 * DESCRIPTION
 *  This function is to start bit-stream record process.
 * PARAMETERS
 *  handle_p        [IN]        Recorder handle.
 * RETURNS
 *  MDI_RES_BITSTREAM_SUCCEED   Successful.
 *  Others                      Failed.
 *****************************************************************************/
extern MDI_RESULT mdi_bitstream_record_start(MDI_HANDLE handle);

/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_record_stop
 * DESCRIPTION
 *  This function is to stop bit-stream record process.
 * PARAMETERS
 *  handle_p        [IN]        Recorder handle.
 * RETURNS
 *  MDI_RES_BITSTREAM_SUCCEED   Successful.
 *  Others                      Failed.
 *****************************************************************************/
extern MDI_RESULT mdi_bitstream_record_stop(MDI_HANDLE handle);

/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_record_get
 * DESCRIPTION
 *  This function is a general get function to get information in the 
 *  bit-stream recorder.
 * PARAMETERS
 *  handle          [IN]        Recorder handle.
 *  get_type        [IN]        The information to be got.
 *  data_p          [OUT]       Data buffer. The information will be stored to
 *                              the data buffer.
 *  data_len_p      [IN/OUT]    When input, it indicates the length of data buffer. 
 *                              When output, it indicates the length of data that
 *                              is retrieved.
 * RETURNS
 *  MDI_RES_BITSTREAM_SUCCEED   Successful.
 *  Others                      Failed.
 *****************************************************************************/
extern MDI_RESULT mdi_bitstream_record_get(
        MDI_HANDLE handle,
        mdi_bitstream_record_get_type_enum get_type,
        void* data_p,
        U16* data_len_p);

/*****************************************************************************
 * FUNCTION
 *  mdi_bitstream_record_set
 * DESCRIPTION
 *  This function is a general set function to parameter of the bit-stream recorder.
 * PARAMETERS
 *  handle          [IN]        Recorder handle.
 *  set_type        [IN]        The type of the parameter to be set.
 *  data_p          [IN]        Data buffer. The data in the data buffer will be
 *                              set to bit-stream recorder.
 *  data_len        [IN]        The length of data. Note that the length of data
 *                              should be equal to the length of the parameter to
 *                              be set.
 * RETURNS
 *  MDI_RES_BITSTREAM_SUCCEED   Successful.
 *  Others                      Failed.
 *****************************************************************************/
extern MDI_RESULT mdi_bitstream_record_set(
        MDI_HANDLE handle,
        mdi_bitstream_record_set_type_enum set_type,
        void* data_p,
        U16 data_len);

#endif /*__BITSTREAM_API_SUPPORT__*/
#endif /* _MDI_BITSTREAM_H_*/ 

