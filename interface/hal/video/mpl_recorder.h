
#include "mpl_common.h"

#ifndef __MPL_RECORDER_H
#define __MPL_RECORDER_H

typedef struct mpl_recorder_t mpl_recorder_t;

/*****************************************************************************
 * Function pointer definition
 *****************************************************************************/
typedef enum
{
    MPL_UNKNOWN             = 0,
    MPL_OK                  = 1,
    MPL_BISTREAM_SHORTAGE   = 2,
    MPL_INVALID_FRAME       = 3,
    MPL_STATUS_MAX          = 0x1FFFFFFF
} MPL_BUFFER_STATUS_T;


typedef struct
{
    kal_uint8*  pu1Address;
    kal_uint32  u4Size;
    MPL_BUFFER_STATUS_T  eStatus;
    kal_uint32  u4Reserved;
} MPL_BUFFER_INFO_T;

/* to support motion sensor */
typedef enum
{
    MPL_RECORDER_ROTATION_ANGLE_CW_0              = 0,
    MPL_RECORDER_ROTATION_ANGLE_CW_90             = 1,
    MPL_RECORDER_ROTATION_ANGLE_CW_180            = 2,
    MPL_RECORDER_ROTATION_ANGLE_CW_270            = 3,
    MPL_RECORDER_ROTATION_AND_MIRROR_ANGLE_CW_0   = 4,  /* Rotation followed by horizontal mirror */
    MPL_RECORDER_ROTATION_AND_MIRROR_ANGLE_CW_90  = 5,  /* Rotation followed by horizontal mirror */
    MPL_RECORDER_ROTATION_AND_MIRROR_ANGLE_CW_180 = 6,  /* Rotation followed by horizontal mirror */
    MPL_RECORDER_ROTATION_AND_MIRROR_ANGLE_CW_270 = 7,  /* Rotation followed by horizontal mirror */
    MPL_RECORDER_ROTATION_ANGLE_MAX = 0x1FFFFFFF,
} MPL_RECORDER_ROTATION_ANGLE_T;


typedef MPL_BUFFER_INFO_T (*mpl_get_buffer_pfn_t)(void);
typedef void (*mpl_return_buffer_pfn_t)(MPL_BUFFER_INFO_T rInfo);


typedef enum
{
    MPL_RECORDER_FORMAT_MPEG4           = 0,
    MPL_RECORDER_FORMAT_H263            = 1,
    MPL_RECORDER_FORMAT_H264            = 2,
    MPL_RECORDER_FORMAT_MJPEG           = 3,
    MPL_RECORDER_FORMAT_MAX             = 0x1FFF
} mpl_recorder_format_enum_t;

typedef enum
{
    MPL_RECORDER_QUALITY_FINE           = 0,
    MPL_RECORDER_QUALITY_HIGH           = 1,
    MPL_RECORDER_QUALITY_NORMAL         = 2,
    MPL_RECORDER_QUALITY_LOW            = 3,
    MPL_RECORDER_QUALITY_MAX            = 0x1FFF
} mpl_recorder_quality_enum_t;

typedef enum
{
    MPL_RECORDER_STORAGE_PHONE          = 0,
    MPL_RECORDER_STORAGE_CARD           = 1,
    MPL_RECORDER_STORAGE_MAX            = 0x1FFF
} mpl_recorder_storage_enum_t;

typedef enum
{
    MPL_RECORDER_USER_RECORDER          = 0,
    MPL_RECORDER_USER_MATV_PAL          = 1,
    MPL_RECORDER_USER_MATV_NTSC         = 2,
    MPL_RECORDER_USER_RECORDER_H264     = 3
} mpl_recorder_user_enum_t;

typedef enum
{
    MPL_RECORDER_PARAM_TYPE_OPEN        = 0,
    MPL_RECORDER_PARAM_TYPE_START       = 1,
    MPL_RECORDER_PARAM_TYPE_SAVE        = 2,
    MPL_RECORDER_PARAM_TYPE_DISCARD     = 3,
    MPL_RECORDER_PARAM_TYPE_MAX         = 0x1FFFFFFF
} mpl_recorder_param_type_enum_t;

typedef enum
{
    MPL_RECORDER_EVENT_STOP             = 0,
    MPL_RECORDER_EVENT_SAVE             = 1,
    MPL_RECORDER_EVENT_GENERAL          = 2
} mpl_recorder_event_enum_t;


typedef enum
{
    MPL_RECORDER_SOFTWARE_ROTATOR_DISABLED  = 0,
    MPL_RECORDER_SOFTWARE_ROTATOR_ENABLED   = 1,
    MPL_RECORDER_CODEC_ROTATION_ANGLE_MAX   = 128
} mpl_recorder_rotation_t;


/* open param structure */
typedef struct
{
    kal_uint16 image_width;
    kal_uint16 image_height;

    mpl_recorder_format_enum_t format;
    mpl_recorder_quality_enum_t quality;
    mpl_recorder_storage_enum_t storage;
    mpl_recorder_user_enum_t    user;
    mpl_recorder_rotation_t eSoftwareRotator;
    kal_bool fgRecordYuv;
} mpl_recorder_open_param_t;

/* record param structure */
typedef struct
{
    kal_wchar *working_path;
    kal_uint64 record_time_limit;
    kal_uint64 record_file_size_limit;
    kal_bool record_audio;
    kal_uint32 u4ImageWidth;                               /* to support motion sensor */
    kal_uint32 u4ImageHeight;                              /* to support motion sensor */
    MPL_RECORDER_ROTATION_ANGLE_T ePlaybackRotationAngle;  /* to support motion sensor */
} mpl_recorder_record_param_t;


/* record param structure */
typedef struct
{
    kal_wchar *working_path;
    kal_wchar *file_path;
} mpl_recorder_save_param_t;

/* discard param */
typedef struct
{
    kal_wchar *working_path;
} mpl_recorder_discard_param_t;


/* is_unsaved param */
typedef struct
{
    kal_wchar *working_path;
    kal_bool is_unsaved_file;
} mpl_recorder_is_unsaved_file_param_t;


typedef enum
{
    MPL_RECORDER_PARAM_IS_UNFINISHED_FILE       = 0,
    MPL_RECORDER_PARAM_RECORDED_SIZE            = 1,
    MPL_RECORDER_PARAM_RECORDED_TIME            = 2,
    MPL_RECORDER_PARAM_GET_BUFFER_PFN           = 3,
    MPL_RECORDER_PARAM_RETURN_BUFFER_PFN        = 4,
    MPL_RECORDER_PARAM_GET_FRAME_RATE           = 5,
    MPL_RECORDER_PARAM_SET_FRAME_RATE           = 6,
    MPL_RECORDER_PARAM_GET_RESERVED_DISK_SIZE   = 7,  // Video recorder needs to reserve some disk size for successful file merge.
    MPL_RECORDER_PARAM_TIME_LAPSE_ENCODE_ONE_OF_N_SEC    = 8,  // unit of mini second
    MPL_RECORDER_PARAM_TIME_LAPSE_SET_PLAYBACK_FPS       = 9,  // in terms of fps * 10
    MPL_RECORDER_PARAM_TIME_LAPSE_GET_ENCODED_FRAME_NUM = 10, //
    MPL_RECORDER_PARAM_SET_VIDEO_RTP_HANDLE = 11,
    MPL_RECORDER_PARAM_SET_AUDIO_RTP_HANDLE = 12,
    MPL_RECORDER_PARAM_MAX                      = 0x1FFFFFFF
} mpl_recorder_param_enum_t;


typedef struct mpl_recorder_client_t mpl_recorder_client_t;

struct mpl_recorder_client_t
{
    /* Memory allcator and free api. */
    void* (*mpl_mem_alloc_func_t)(
         mpl_recorder_client_t *client,
         kal_int32 size,
         med_mem_type_enum type,
         char* file_p,
         long line_p);
    void (*mpl_mem_free_func_t)(
         mpl_recorder_client_t *client,
         void** p,
         med_mem_type_enum type,
         char* file_p,
         long line_p);

    /* On event callback. */
    void (*on_event_callback)(mpl_recorder_client_t *client, mpl_recorder_event_enum_t event_id, media_error_t result);
};

struct mpl_recorder_t
{
    media_error_t  (*open)        (mpl_recorder_t *itf, mpl_recorder_open_param_t* open_struct);
    media_error_t  (*start)       (mpl_recorder_t *itf, mpl_recorder_record_param_t* start_struct);
    media_error_t  (*stop)        (mpl_recorder_t *itf);
    media_error_t  (*pause)       (mpl_recorder_t *itf);
    media_error_t  (*resume)      (mpl_recorder_t *itf);
    media_error_t  (*pause_video_encode)       (mpl_recorder_t *itf);
    media_error_t  (*resume_video_encode)      (mpl_recorder_t *itf);
    media_error_t  (*set_param)   (mpl_recorder_t *itf, mpl_recorder_param_enum_t param,
                                   void* value, kal_int32 size);
    media_error_t  (*get_param)   (mpl_recorder_t *itf, mpl_recorder_param_enum_t param,
                                   void* value, kal_int32 size);
    media_error_t  (*save)        (mpl_recorder_t *itf, mpl_recorder_save_param_t* param);
    media_error_t  (*abort_saving)   (mpl_recorder_t *itf);
    media_error_t  (*discard)     (mpl_recorder_t *itf, mpl_recorder_discard_param_t* param);
    media_error_t  (*close)       (mpl_recorder_t *itf);
    media_error_t  (*get_default)  (mpl_recorder_t *itf, mpl_recorder_param_type_enum_t param_type,
                                   void* param_struct, kal_int32 size);
    void (*destroy)(mpl_recorder_t* itf); /* Destroy interface: To destroy the player itself. */
};

mpl_recorder_t* construct_mp4_recorder(mpl_recorder_client_t* mpl_recorder_client);
mpl_recorder_t* construct_avi_recorder(mpl_recorder_client_t* mpl_recorder_client);
mpl_recorder_t* construct_rtp_recorder(mpl_recorder_client_t *prMplvrClient);


// The next two functions are mainly used to fix build warning.  They are called when an
// asynchronous call is made.
extern void avi_recorder_main(ilm_struct *prIlm);
extern void mp4_recorder_main(ilm_struct *prIlm);
extern void rtp_recorder_main(ilm_struct *prIlm);

#endif /* __MPL_RECORDER_H */
