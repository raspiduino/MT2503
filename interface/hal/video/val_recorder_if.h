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
*   val_recorder_if.h
*
* Project:
* --------
*	MediaTek
*
* Description:
* ------------
*
*
* Author:
* -------
 * -------
*
*=============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*-----------------------------------------------------------------------------
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
*****************************************************************************/


#ifndef VAL_RECORDER_IF_H
#define VAL_RECORDER_IF_H


#include "val_if.h"
#include "fsal.h"                               // STFSAL
#include "kal_general_types.h"                      // for kal_uint32


/*****************************************************************************
* Define the operations here.
* Please make sure the last operation is <= VAL_RECORDER_OP_MAX.
*****************************************************************************/
#define VAL_RECORDER_OP_GET_PFN_FOR_GETTING_BUFFER      (VAL_RECORDER_OP_BASE +  0)
#define VAL_RECORDER_OP_GET_PFN_FOR_RETURNING_BUFFER    (VAL_RECORDER_OP_BASE +  1)
#define VAL_RECORDER_OP_START                           (VAL_RECORDER_OP_BASE +  2)
#define VAL_RECORDER_OP_STOP                            (VAL_RECORDER_OP_BASE +  3)
#define VAL_RECORDER_OP_WAIT_STOP_DONE                  (VAL_RECORDER_OP_BASE +  4)
#define VAL_RECORDER_OP_SET_BIT_RATE                    (VAL_RECORDER_OP_BASE +  5)
#define VAL_RECORDER_OP_SET_FRAME_RATE                  (VAL_RECORDER_OP_BASE +  6)
#define VAL_RECORDER_OP_REDUCE_SPEED                    (VAL_RECORDER_OP_BASE +  7)
#define VAL_RECORDER_OP_SET_FILE_HANDLE                 (VAL_RECORDER_OP_BASE +  8)
#define VAL_RECORDER_OP_STORE_VIDEO_FILE                (VAL_RECORDER_OP_BASE +  9)
#define VAL_RECORDER_OP_STORE_META_FILE                 (VAL_RECORDER_OP_BASE + 10)
#define VAL_RECORDER_OP_GET_VIDEO_FILE_SIZE             (VAL_RECORDER_OP_BASE + 11)
#define VAL_RECORDER_OP_GET_META_FILE_SIZE              (VAL_RECORDER_OP_BASE + 12)
#define VAL_RECORDER_OP_EVALUATE_REAL_META_FILE_SIZE    (VAL_RECORDER_OP_BASE + 13)
#define VAL_RECORDER_OP_CREATE_META_FILE                (VAL_RECORDER_OP_BASE + 14)
#define VAL_RECORDER_OP_GET_META_FILE_DURATION          (VAL_RECORDER_OP_BASE + 15)
#define VAL_RECORDER_OP_GET_POS_OF_MDAT_SIZE            (VAL_RECORDER_OP_BASE + 16)
#define VAL_RECORDER_OP_GET_POS_OF_MOOV                 (VAL_RECORDER_OP_BASE + 17)
#define VAL_RECORDER_OP_SET_AUDIO_FORMAT                (VAL_RECORDER_OP_BASE + 18)
#define VAL_RECORDER_OP_GET_CURRENT_TIME                (VAL_RECORDER_OP_BASE + 19)
#define VAL_RECORDER_OP_GET_CURRENT_TIME_STAMP          (VAL_RECORDER_OP_BASE + 20)
#define VAL_RECORDER_OP_DO_VIDEO_AND_META_FILES_EXIST   (VAL_RECORDER_OP_BASE + 21)
#define VAL_RECORDER_OP_SET_RECORDING_YUV               (VAL_RECORDER_OP_BASE + 22)
#define VAL_RECORDER_OP_SET_COLOR_FORMAT                (VAL_RECORDER_OP_BASE + 23)
#define VAL_RECORDER_OP_SET_FILE_SIZE_LIMIT             (VAL_RECORDER_OP_BASE + 24)


/*****************************************************************************
* Define the data structures associated with the operations defined above.
*****************************************************************************/
typedef enum {
    VAL_RECORDER_CALLBACK_ERROR_EVENT,
    VAL_RECORDER_CALLBACK_ERROR_NO_DISK,
    VAL_RECORDER_CALLBACK_ERROR_DISK_FULL,
    VAL_RECORDER_CALLBACK_ERROR_EOF,
    VAL_RECORDER_CALLBACK_ERROR_BUSY
} VAL_RECORDER_CALLBACK_T;


/*****************************************************************************
* Callback function for VAL RECORDER
*****************************************************************************/
typedef void (*PFN_VAL_RECORDER_CALLBACK_T)(VAL_RECORDER_CALLBACK_T eType,
        void *pvData, kal_uint32 u4DataLen);


/*****************************************************************************
* Opeation: VAL_RECORDER_OP_GET_PFN_FOR_GETTING_BUFFER
* Input: None
* Output: PFN_VAL_RECORDER_GET_BUFFER_T
*****************************************************************************/


/*****************************************************************************
* Opeation: VAL_RECORDER_OP_GET_PFN_FOR_RETURNING_BUFFER
* Input: None
* Output: PFN_VAL_RECORDER_COMPLETE_BUFFER_T
*****************************************************************************/


/*****************************************************************************
* Redirect from VAL_Open() to video_recorder_init_v2().
* Input: a data structure of data type VAL_RECORDER_INIT_T
* Output: None
*****************************************************************************/
/*****************************************************************************
* Redirect from VAL_Open() to video_recorder_init_file_writer_v2().
* Input: a data structure of data type VAL_RECORDER_INIT_T
* Output: None
*****************************************************************************/
typedef enum
{
    VAL_RECORDER_QUALITY_LOW,
    VAL_RECORDER_QUALITY_NORMAL,
    VAL_RECORDER_QUALITY_GOOD,
    VAL_RECORDER_QUALITY_FINE,
    VAL_RECORDER_QUALITY_CUSTOM,
    VAL_RECORDER_QUALITY_MAX = 128          // Unused enumerator marks the one-byte watermark.
} VAL_RECORDER_QUALITY_T;

typedef enum
{
    VAL_RECORDER_CODEC_MPEG4,
    VAL_RECORDER_CODEC_H263,
    VAL_RECORDER_CODEC_MJPEG,
    VAL_RECORDER_CODEC_H264,
    VAL_RECORDER_CODEC_MAX = 128          // Unused enumerator marks the one-byte watermark.
} VAL_RECORDER_CODEC_T;

typedef enum
{
    VAL_RECORDER_STORAGE_PHONE,
    VAL_RECORDER_STORAGE_SD,
    VAL_RECORDER_STORAGE_MAX = 128          // Unused enumerator marks the one-byte watermark.
} VAL_RECORDER_STORAGE_T;

typedef enum {
    VAL_RECORDER_FUNCTION_VIDEO_RECORDING,
    VAL_RECORDER_FUNCTION_FILE_MERGE,
    VAL_RECORDER_FUNCTION_MAX = 128         // Unused enumerator marks the one-byte watermark.
} VAL_RECORDER_FUNCTION_T;

typedef enum {
    VAL_RECORDER_ROTATION_ANGLE_0 = 0,
    VAL_RECORDER_ROTATION_ANGLE_90,
    VAL_RECORDER_ROTATION_ANGLE_180,
    VAL_RECORDER_ROTATION_ANGLE_270,
    VAL_RECORDER_ROTATION_ANGLE_MAX = 128   // Unused enumerator marks the one-byte watermark.
} VAL_RECORDER_ROTATION_ANGLE_T;

typedef enum {
    VAL_RECORDER_SOFTWARE_ROTATOR_DISABLED = 0,
    VAL_RECORDER_SOFTWARE_ROTATOR_ENABLED,
    VAL_RECORDER_SOFTWARE_ROTATOR_MAX = 128
} VAL_RECORDER_SOFTWARE_ROTATOR_T;

typedef struct {
    VAL_RECORDER_FUNCTION_T eFunction;  // It specifies whether the function is video recording or file merge.
    // Internal memory is managed by ME2, and it is obtained through mm_intmem_get().
    kal_uint32 u4ExtMemoryAddr;
    kal_uint32 u4ExtMemorySize;
    kal_uint32 u4FrameWidth;
    kal_uint32 u4FrameHeight;
    kal_uint32 u4Bitrate;
    // kal_uint32 u4SyncInterval;       // Encoder adaptation layer will query codec for I-frame interval.
    PFN_VAL_RECORDER_CALLBACK_T pfnCallBack;
    VAL_RECORDER_QUALITY_T eQuality;    // VAL_RECORDER_QUALITY_T ---> VIDEO_RECORDER_QUALITY_T
    VAL_RECORDER_ROTATION_ANGLE_T eRotationAngle;
    VAL_RECORDER_SOFTWARE_ROTATOR_T eSoftwareRotator;
    VAL_RECORDER_CODEC_T eCodec;
    VAL_RECORDER_STORAGE_T eStorage;
} VAL_RECORDER_INIT_T;


/*****************************************************************************
* For use with VAL_RECORDER_OP_START.
* Redirect to video_recorder_start_v2().
* Input: None
* Output: None
*****************************************************************************/


/*****************************************************************************
* For use with VAL_RECORDER_OP_STOP.
* Redirect to video_recorder_stop_v2().
* Input: None
* Output: None
*****************************************************************************/


/*****************************************************************************
* For use with VAL_RECORDER_OP_WAIT_STOP_DONE.
* Redirect to video_recorder_wait_stop_done_v2().
* Input: None
* Output: None
*****************************************************************************/


/*****************************************************************************
* For use with VAL_RECORDER_OP_SET_BIT_RATE.
* Redirect to video_recorder_set_bitrate_v2().
* Input: bit rate of data type kal_uint32
* Output: None
*****************************************************************************/


/*****************************************************************************
* For use with VAL_RECORDER_OP_SET_FRAME_RATE.
* Redirect to video_recorder_set_framerate_v2().
* Input: frame rate of data type kal_uint32
* Output: None
*****************************************************************************/


/*****************************************************************************
* For use with VAL_RECORDER_OP_REDUCE_SPEED.
* Redirect to video_recorder_reduce_speed_v2().
* Input: a variable of data type kal_uint32 indicating the time in milli-second
*        the Encoder component shall sleep.
* Output: None
*****************************************************************************/


/*****************************************************************************
* For use with VAL_RECORDER_OP_SET_FILE_HANDLE.
* Redirect to video_recorder_set_file_handles_v2().
* Input: a data structure of data type VAL_RECORDER_OUTPUT_FILES_T
* Output: None
*****************************************************************************/
typedef struct
{
    STFSAL *prVideoFile;
    STFSAL *prMetaFile;
    STFSAL *prTempMetaFile;
} VAL_RECORDER_OUTPUT_FILES_T;


/*****************************************************************************
* For use with VAL_RECORDER_OP_STORE_VIDEO_FILE.
* Redirect to video_recorder_store_video_file_v2().
* Input: None
* Output: None
*****************************************************************************/


/*****************************************************************************
* For use with VAL_RECORDER_OP_STORE_META_FILE.
* Redirect to video_recorder_store_meta_file_v2().
* Input: None
* Output: None
*****************************************************************************/


/*****************************************************************************
* For use with VAL_RECORDER_OP_GET_VIDEO_FILE_SIZE.
* Redirect to video_recorder_get_bitstream_file_size_v2().
* Input: None
* Output: video file size of data type kal_uint32
*****************************************************************************/


/*****************************************************************************
* For use with VAL_RECORDER_OP_GET_META_FILE_SIZE.
* Redirect to video_recorder_get_meta_file_size_v2().
* Input: None
* Output: meta file size of data type kal_uint32
*****************************************************************************/


/*****************************************************************************
* For use with VAL_RECORDER_OP_EVALUATE_REAL_META_FILE_SIZE.
* Redirect to video_recorder_evaluate_real_meta_file_size_v2().
* Input: None
* Output: evaluated size of the real meta file which if of data type kal_uint32
*****************************************************************************/


/*****************************************************************************
* Redirect from VAL_Close() to video_recorder_close_file_writer_v2().
* Input: a data structure of data type VAL_RECORDER_CLOSE_T
* Output: None
*****************************************************************************/
typedef struct {
    VAL_RECORDER_FUNCTION_T eFunction;  // It specifies whether the function is video recording or file merge.
} VAL_RECORDER_CLOSE_T;


/*****************************************************************************
* For use with VAL_RECORDER_OP_CREATE_META_FILE.
* Redirect to video_recorder_create_meta_file_v2().
* Input: None
* Output: None
*****************************************************************************/


/*****************************************************************************
* For use with VAL_RECORDER_OP_GET_META_FILE_DURATION.
* Redirect to video_recorder_get_meta_file_duration_v2().
* Input: None
* Output: None
*****************************************************************************/


/*****************************************************************************
* For use with VAL_RECORDER_OP_GET_POS_OF_MDAT_SIZE.
* Redirect to video_recorder_get_mdatsz_pos_v2().
* Input: a pointer to kal_uint32 for storing the position information
* Output: a pointer to kal_uint32 for storing the position information
*****************************************************************************/


/*****************************************************************************
* For use with VAL_RECORDER_OP_GET_POS_OF_MOOV.
* Redirect to video_recorder_get_moov_pos_v2().
* Input: a data structure of data type VAL_RECORDER_MOOV_INFO_T
* Output: None
*****************************************************************************/
typedef struct
{
    kal_uint32 u4Pos;
    kal_uint32 u4Size;
} VAL_RECORDER_MOOV_INFO_T;


/*****************************************************************************
* For use with VAL_RECORDER_OP_SET_AUDIO_FORMAT.
* Redirect to video_recorder_set_audioformat_v2().
* Input: audio format of data type Media_Format
* Output: None
*****************************************************************************/


/*****************************************************************************
* For use with VAL_RECORDER_OP_GET_CURRENT_TIME.
* Redirect to video_recorder_get_current_time_v2().
* Input: None
* Output: current time of data type kal_uint64
*****************************************************************************/


/*****************************************************************************
* For use with VAL_RECORDER_OP_GET_CURRENT_TIME_STAMP.
* Redirect to video_recorder_get_current_time_stamp_v2().
* Input: None
* Output: current time stamp of data type kal_uint64
*****************************************************************************/


/*****************************************************************************
* For use with VAL_RECORDER_OP_DO_VIDEO_AND_META_FILES_EXIST.
* Input: a data structure of data type VAL_RECORDER_OUTPUT_FILES_T.
*        Only the prVideoFile and prTempMetaFile are used.
* Output: None
*****************************************************************************/


/*****************************************************************************
* For use with VAL_RECORDER_OP_SET_COLOR_FORMAT.
* Input: a data structure of data type VAL_RECORDER_COLOR_FORMAT_T.
* Output: None
*****************************************************************************/
typedef enum
{
    VAL_RECORDER_COLOR_FORMAT_YUV_420,      // Default.  Set to 0 on purpose.
    VAL_RECORDER_COLOR_FORMAT_YUV_422,
    VAL_RECORDER_COLOR_FORMAT_RGB_565,
    VAL_RECORDER_COLOR_FORMAT_RGB_888,
    VAL_RECORDER_COLOR_FORMAT_MAX = 128     // Unused enumerator marks the one-byte watermark.
} VAL_RECORDER_COLOR_FORMAT_T;


/*****************************************************************************
* For use with VAL_RECORDER_OP_SET_FILE_SIZE_LIMIT.
* Redirect to video_recorder_set_file_size_limit_v2().
* Input: file size limit of data type kal_uint64
* Output: None
*****************************************************************************/


#endif  // VAL_RECORDER_IF_H

