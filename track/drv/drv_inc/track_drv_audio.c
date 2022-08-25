#if 1//defined(__MED_AUD_FS_ACCESS__)
/******************************************************************************
 * track_drv_audio.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        MP3ÎÄ¼þ²¥·Å
 *
 * modification history
 * --------------------
 * v1.0   2018-04-30,  Liujw create this file
 *
 ******************************************************************************/
#include "track_cust.h"
#include "c_vector.h"
#define VS_MM_BUFFER_SIZE        (128)
#if 0
typedef S32 mdi_result;
typedef S32 mdi_handle;
typedef S32 mdi_result;
#define VS_MM_AUDIO_BUILD_CACHE_SIZE (2*1024)           /* audio build cache size */
#define VS_MM_AUDIO_FRM_RDS_PS_NAME_SIZE 10
#define VS_MM_AUDIO_FRM_RDS_RT_SIZE      64  
#endif

WCHAR avk_framework_testfile_path[20]={0};

#ifdef __UCS2_ENCODING
typedef	U16					UI_character_type;
#else
typedef U8					UI_character_type;
#endif

typedef UI_character_type*	UI_string_type;
typedef enum
{
    STREAM_STATE_IDLE,
    STREAM_STATE_PLAY
}vs_mm_stream_state_enum;

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
/* Define the audio play style. */
#if 0
typedef enum {
	DEVICE_AUDIO_PLAY_CRESCENDO  = 0 ,	/* Play sound for crescendo. */
	DEVICE_AUDIO_PLAY_INFINITE		 ,	/* Play sound for infinite. */
	DEVICE_AUDIO_PLAY_ONCE			 ,	/* Play sound for once. */
	DEVICE_AUDIO_PLAY_DESCENDO		   /* Play sound for descendo. */
}audio_play_style_enum;
#endif
/* Tone type */
typedef enum
{
	MDI_AUDIO_TYPE_UNKNOWN = 0, 		/* Default as unknown */
	MDI_AUDIO_TYPE_PLAYER,				/* Player */
	MDI_AUDIO_TYPE_RING,				/* Ring tone */
	MDI_AUDIO_TYPE_MESSAGE, 			/* Message tone */
	MDI_AUDIO_TYPE_EFFECT,				/* Effect tone */
	MDI_AUDIO_TYPE_ALERT,				/* Alert tone */
	MDI_AUDIO_TYPE_POWER_OFF,			/* Power-off tone */

	MDI_AUDIO_TYPE_LAST_ENTRY			/* Last entry */
} mdi_audio_type_enum;
/* volume type */
#if 0
typedef enum
{
	AUD_VOLUME_CTN = 0, 					/* 0: tone */
	AUD_VOLUME_KEY, 						/* 1: keytone */
	AUD_VOLUME_MIC, 						/* 2: microphone */
	AUD_VOLUME_FMR, 						/* 3: FM Radio */
	AUD_VOLUME_SPH, 						/* 4: Speech */
	AUD_VOLUME_SID, 						/* 5: Side-tone */
	AUD_VOLUME_MEDIA,						/* 6: Multi-Media */
	AUD_VOLUME_TVO, 						/* 7: TV-OUT */
	AUD_VOLUME_ATV, 						/* 8: ATV */
	
	AUD_MAX_VOLUME_TYPE
} aud_volume_enum;
#endif
/* this shall be sync with aud_defs.h, backward compatible */
#if 0
typedef enum
{
    MED_RES_OK = 0,                 /* 0 */
    MED_RES_FAIL,                   /* 1 */
    MED_RES_BUSY,                   /* 2 */
    MED_RES_DISC_FULL,              /* 3 */
    MED_RES_OPEN_FILE_FAIL,         /* 4 */
    MED_RES_END_OF_FILE,            /* 5 */
    MED_RES_TERMINATED,             /* 6 */
    MED_RES_BAD_FORMAT,             /* 7 */
    MED_RES_INVALID_FORMAT,         /* 8 */
    MED_RES_ERROR,                  /* 9 */
    MED_RES_NO_DISC,                /* 10 */
    MED_RES_NOT_ENOUGH_SPACE,       /* 11 */
    MED_RES_INVALID_HANDLE,         /* 12 */
    MED_RES_NO_HANDLE,              /* 13 */
    MED_RES_RESUME,                 /* 14 */
    MED_RES_BLOCKED,                /* 15 */
    MED_RES_MEM_INSUFFICIENT,       /* 16 */
    MED_RES_BUFFER_INSUFFICIENT,    /* 17 */
    MED_RES_FILE_EXIST,             /* 18 */
    MED_RES_WRITE_PROTECTION,       /* 19 */
    MED_RES_PARAM_ERROR,            /* 20 */
    /* MP4,AAC */
    MED_RES_UNSUPPORTED_CHANNEL,    /* 21 */
    MED_RES_UNSUPPORTED_FREQ,
    MED_RES_UNSUPPORTED_TYPE,
    MED_RES_UNSUPPORTED_OPERATION,
    MED_RES_PARSER_ERROR,
    MED_RES_VIDEO_ERROR,
    MED_RES_AUDIO_ERROR,
    MED_RES_FSAL_ERROR,
    MED_RES_MP4_PRODUCER_ERROR,
    MED_RES_MP4_SAMPLEDATA_ERROR,
    MED_RES_MP4_NO_VIDEO_TRACK,
    MED_RES_MP4_NO_AUDIO_TRACK,
    /* VR */
    MED_RES_ID_MISMATCH,            /* 33 */
    MED_RES_ID_EXIST,
    MED_RES_TRAINING_CONTINUE,
    MED_RES_NO_SOUND,
    MED_RES_TOO_SIMILAR,
    MED_RES_TOO_DIFFERENT,
    MED_RES_NO_MATCH,
    MED_RES_SPEAK_TOO_LONG,
    MED_RES_SPEAK_TOO_SHORT,
    /* MP4,AAC */
    MED_RES_AUDIO_END,              /* 42 */
    MED_RES_VIDEO_END,
    MED_RES_VIDEO_IMAGE_TOO_LARGE,
    MED_RES_VIDEO_FILE_TOO_LARGE,
    MED_RES_VIDEO_FRAME_RATE_TOO_HIGH,
    MED_RES_VIDEO_SEEK_PARTIAL_DONE,
    /* VRSI */
    MED_RES_VRSI_OK,                /* 48 */
    MED_RES_VRSI_ERR_UNINITIALIZED,
    MED_RES_VRSI_ERR_BUSY,
    MED_RES_VRSI_ERR_MEM_INSUFFICIENT,
    MED_RES_VRSI_ERR_DATA_ERROR,
    MED_RES_VRSI_ERR_LIBRARY_CORRUPT,
    MED_RES_VRSI_ERR_BAD_GRAMMAR,
    MED_RES_VRSI_ERR_LANG_NOT_SUPPORT,
    MED_RES_VRSI_ERR_NO_MATCH_TAG,
    MED_RES_VRSI_ERR_TTS_TOO_LONG,
    MED_RES_VRSI_ERR_SESSION,
    MED_RES_VRSI_ERR_NO_SOUND,
    MED_RES_VRSI_ERR_CMD_TRN_FAIL,
    MED_RES_VRSI_ERR_CMD_RCG_FAIL,
    MED_RES_VRSI_ERR_DGT_RCG_FAIL,
    MED_RES_VRSI_ERR_DGT_ADP_FAIL,
    MED_RES_VRSI_ERR_UNKNOWN,       /* 64 */
    /* FM Record */
    MED_RES_STOP_FM_RECORD,         /* 65 */
    /* Audio Post Process */
    MED_RES_UNSUPPORTED_SPEED,      /* 66 */
    /* A2DP */
    MED_RES_A2DP_CLOSE,
    MED_RES_A2DP_DISCOVER_SEP_FAIL,
    MED_RES_A2DP_GET_SEP_CAP_FAIL,
    MED_RES_A2DP_NO_MATCH_CAP,
    MED_RES_A2DP_CONFIG_STREAM_FAIL,
    MED_RES_A2DP_RECONFIG_STREAM_FAIL,
    MED_RES_A2DP_OPEN_STREAM_FAIL,
    MED_RES_A2DP_START_STREAM_FAIL,
    MED_RES_A2DP_PAUSE_STREAM_FAIL,  /* 75 */
    /* HFP */
    MED_RES_HFP_CLOSE,
    /* Image */
    MED_RES_IMG_DECODE_TIME_OUT,
    MED_RES_ROOT_DIR_FULL,

    /* Barcode Reader */
    MED_RES_BR_IMAGE_ERROR,         /* 79 */
    MED_RES_BR_MODULE_ERROR,
    MED_RES_BR_OUT_OF_MEMORY,
    MED_RES_BR_OVER_VERSION,
    MED_RES_BR_DECODE_TIMEOUT,
    MED_RES_BR_ERROR_BARCODE_TYPE,

    /* Video - pdl */
    MED_RES_PDL_AUDIO_UNDERFLOW,    /* 85 */
    MED_RES_PDL_VIDEO_UNDERFLOW,

    /* Streaming */
    MED_RES_STREAM_BEARER_DISCONNECTED,     /* 87 */
    MED_RES_STREAM_INVALID_SDP,
    MED_RES_STREAM_RTSP_SET_CHANNEL_FAIL,
    MED_RES_STREAM_RTSP_REQUEST_FAIL,       /* 90 */
    MED_RES_STREAM_RTSP_REQUEST_FORBIDDEN,
    MED_RES_STREAM_PLAY_FINISH,
    MED_RES_STREAM_BUFFER_UNDERFLOW,
    MED_RES_STREAM_BUFFER_OVERFLOW,
    MED_RES_STREAM_INVALID_RESOLUTION,
    MED_RES_STREAM_INVALID_PARAMETER,
    MED_RES_STREAM_STOP_TIMEOUT,
    MED_RES_STREAM_UNSUPPORTED_CODEC,
    MED_RES_STREAM_INVALID_MEDIA,

    MED_RES_VDOEDT_ENCODE_FAIL,     /* 100 */
    MED_RES_DECODER_NOT_SUPPORT,
    MED_RES_REACH_STOP_TIME,
    MED_RES_VRSI_ERR_EVALUATE_LIMIT,  /* 103 */
    MED_RES_IMGAE_ENCODED_SIZE_LARGER_THAN_EXPECTATION, /* 104 */
    MED_RES_VIDEO_UNSUPPORT_DECODE_SIZE,
    MED_RES_VIDEO_ALREADY_STOPPED,
    MED_RES_STREAM_UNSUPPORTED_BANDWIDTH,

    /* bitstream */
    MED_RES_BITSTREAM_FAILED,
    MED_RES_BITSTREAM_UNSUPPORTED_CODEC,
    MED_RES_BITSTREAM_INVALID_RESOLUTION,
    MED_RES_BITSTREAM_MEMORY_INSUFFICIENT,
    MED_RES_BITSTREAM_BUFFER_OVERFLOW,
    MED_RES_BITSTREAM_BUFFER_UNDERFLOW,
    MED_RES_BITSTREAM_INVALID_FORMAT,
    MED_RES_BITSTREAM_RECOVER,                /* 115 */

    /* audio extension */
    MED_RES_AUD_DEMO_END,                     /* 116 */
    MED_RES_AUD_DUR_UPDATED,                  /* 117 */

    MED_RES_BITSTREAM_BUFFER_NOT_AVAILABLE,   /* 118 */

    /* disk io error */
    MED_RES_DISK_IO_ERROR,                    /* 119 */

    MED_RES_BITSTREAM_INVALID_PARAMETER,
    MED_RES_BITSTREAM_NOT_SUPPORTED,          /* 121 */

    MED_RES_OK_ASYNC,
    MED_RES_PLAY_FINISH,
    MED_RES_STOP_TIME_REACHED,
    MED_RES_PLAY_STOPPED,
    MED_RES_PDL_BUFFER_INSUFFICIENT,
    MED_RES_MJPG_SKIP_FRAME,                  /* 127 */
    MED_RES_NO_REQUIRED_TRACK,
    
    MED_RES_STREAM_REC_DUR_TOO_SHORT,         /* 129 */
    MED_RES_VIDEO_NO_FRAME_ENCODED,    
    MED_RES_OVER_LIMIT,  /* 131 */
    MED_RES_UPGRADE_NONE,
    MED_RES_UPGRADE_NEED,
    MED_RES_UPGRADE_MANDATORY,
    MED_RES_VIDEO_TRACK_ERROR, /* 135 */
    MED_RES_AUDIO_TRACK_ERROR,
    MED_NO_OF_RES
}
med_result_enum;
#endif
/* Audio 9000 */
//#define MDI_AUDIO_SUCCESS               0

//#define MDI_AUDIO_FAIL                  -9001
//#define MDI_AUDIO_BUSY                  -9002
//#define MDI_AUDIO_DISC_FULL             -9003
//#define MDI_AUDIO_OPEN_FILE_FAIL        -9004
//#define MDI_AUDIO_END_OF_FILE           -9005
//#define MDI_AUDIO_TERMINATED            -9006   /* Only used in MMI */
//#define MDI_AUDIO_BAD_FORMAT            -9007   /* Error from aud driver */
//#define MDI_AUDIO_INVALID_FORMAT        -9008   /* Error from MED */
//#define MDI_AUDIO_ERROR                 -9009
//#define MDI_AUDIO_NO_DISC               -9010
//#define MDI_AUDIO_NO_SPACE              -9011   /* MED audio not used */
//#define MDI_AUDIO_INVALID_HANDLE        -9012   /* MMI not used */
//#define MDI_AUDIO_NO_HANDLE             -9013   /* MMI not used */
//#define MDI_AUDIO_RESUME                -9014   /* Only used in MMI */
//#define MDI_AUDIO_BLOCKED               -9015   /* Only used in MMI */
//#define MDI_AUDIO_MEM_INSUFFICIENT      -9016
//#define MDI_AUDIO_BUFFER_INSUFFICIENT   -9017
//#define MDI_AUDIO_FILE_EXIST            -9018   /* MMI not used */
//#define MDI_AUDIO_WRITE_PROTECTION      -9019
//#define MDI_AUDIO_PARAM_ERROR           -9020
//#define MDI_AUDIO_UNSUPPORTED_CHANNEL   -9021
//#define MDI_AUDIO_UNSUPPORTED_FREQ      -9022
//#define MDI_AUDIO_UNSUPPORTED_TYPE      -9023
//#define MDI_AUDIO_UNSUPPORTED_OPERATION -9024
//#define MDI_AUDIO_PARSER_ERROR          -9025

//#define MDI_AUDIO_AUDIO_ERROR           -9027
//#define MDI_AUDIO_MP4_NO_AUDIO_TRACK    -9032
//#define MDI_AUDIO_STOP_FM_RECORD        -9065   /* Only used in MMI */
//#define MDI_AUDIO_UNSUPPORTED_SPEED     -9066
//#define MDI_AUDIO_DECODER_NOT_SUPPORT   -9101
//#define MDI_AUDIO_DEMO_END              -9116
//#define MDI_AUDIO_DUR_UPDATED           -9117
//#define MDI_AUDIO_HFP_SCO_CONNECTED     -9200   /* Only used in MMI */
//#define MDI_AUDIO_DRM_PROHIBIT          -9201   /* Only used in MMI */
//#define MDI_AUDIO_DRM_TIMEOUT           -9202   /* Only used in MMI */
//#define MDI_AUDIO_A2DP_CONNECTED        -9203   /* Only used in MMI */

typedef struct
{
    kal_uint8 src_id;
    kal_wchar *file_name_p;
    kal_uint8 play_style;
    kal_uint64 volume;
    kal_uint8 output_path;
    kal_uint16 identifier;
    /* set both start_offset and end_offset to 0 for backward compatible */
    kal_uint32 start_offset;    /* 0 : file begining */
    kal_uint32 end_offset;      /* 0 or file data len-1: file end */
    void *cache_p;
}
aud_play_file_struct;
#endif/*__MED_AUD_FS_ACCESS__*/
