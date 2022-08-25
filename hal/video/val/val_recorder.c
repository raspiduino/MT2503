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
*   val_recorder.c
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


#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__
#if defined(__VE_MPEG4_ENC_SUPPORT__) || defined(__VE_H264_ENC_SW_SUPPORT__)


#include "val.h"                    // Internal data structure in VAL
#include "val_recorder.h"           // Internal data structure in VAL RECORDER
#include "val_recorder_if.h"        // Public data structure in VAL RECORDER
#include "val_if.h"                 // Public interface of VAL
#include "video_recorder_if_v2.h"   // Public data structure of video recorder IL cilent
#include "video_recorder_source_component_if_v2.h"  // Public interface of recorder source component
#include "l1audio.h"                // for Media_Format
#include "drv_comm.h"               // for drv_trace0(), drv_trace1()
#include "vcodec_v2_trc.h"


/* The following files are newly added for RHR. */
// #include "kal_release.h"            // for kal_mem_set(), ASSERT()
// #include "video_types_v2.h"         // Public data structure of video recorder
#include "med_status.h"
#include "kal_public_api.h"
#include "kal_general_types.h"                  // for kal_uint32
#include "stack_config.h"
#include "custom_video_enc_if.h"



/*****************************************************************************
* Global variable(s)
*****************************************************************************/
static VAL_RECORDER_MANAGER_T _rValRecorderMgr;


/*****************************************************************************
* This function convert the Recorder error code to VAL error code.
* Side effect: *peValError
*****************************************************************************/
void _val_recorder_convert_error_code(VAL_ERROR_T *peValError,
        MEDIA_STATUS_CODE eRecorderError)
{
    // Convert eRecorderError to eValError.
    switch (eRecorderError)
    {
    case MEDIA_STATUS_OK:
        *peValError = VAL_ERR_NONE;
        break;

    case VIDEO_RESOLUTION_ERROR:
        *peValError = VAL_ERR_RECORDER_RESOLUTION_NOT_SUPPORTED;
        break;

    case VIDEO_ERROR:
        *peValError = VAL_ERR_RECORDER_GENERAL;
        break;

    case VIDEO_NO_FRAME_ENCODED:
        *peValError = VAL_ERR_RECORDER_NO_FRAME_ENCODED;
        break;

    case FSAL_ERROR:
        *peValError = VAL_ERR_RECORDER_FSAL;
        break;

    default:
        *peValError = VAL_ERR_INVALID_ERROR_CODE;
        ASSERT(0);
        break;
    }
}


/*****************************************************************************
*
*****************************************************************************/
static void _val_recorder_Callback(kal_uint8 u1Event)
{
    // FIXME: VIDEO_RECORDER_EVENT is defined, but the function prototype of
    //        the callback function of Recorder IL receives kal_uint8.
    //        It is a bad practice!!!

    if (_rValRecorderMgr.pfnCallBack != NULL)
    {
        switch (u1Event)
        {
        case VIDEO_RECORDER_EVENT_FAIL:
            _rValRecorderMgr.pfnCallBack(VAL_RECORDER_CALLBACK_ERROR_EVENT, NULL, 0);
            break;

        case VIDEO_RECORDER_EVENT_DISK_FULL:
            _rValRecorderMgr.pfnCallBack(VAL_RECORDER_CALLBACK_ERROR_DISK_FULL, NULL, 0);
            break;

        case VIDEO_RECORDER_EVENT_NO_DISK:
            _rValRecorderMgr.pfnCallBack(VAL_RECORDER_CALLBACK_ERROR_NO_DISK, NULL, 0);
            break;

        case VIDEO_RECORDER_EVENT_END_OF_FILE:
            _rValRecorderMgr.pfnCallBack(VAL_RECORDER_CALLBACK_ERROR_EOF, NULL, 0);
            break;

        case VIDEO_RECORDER_EVENT_BUSY:
            _rValRecorderMgr.pfnCallBack(VAL_RECORDER_CALLBACK_ERROR_BUSY, NULL, 0);
            break;

        default:
            ASSERT(0);
            break;
        }
    }
    else
    {
        drv_trace0(TRACE_GROUP_10, VAL_REC_NULL_CALLBACK);
    }
}


/*****************************************************************************
*
*****************************************************************************/
static void _val_recorder_SetFrameRateTableProperties(const VAL_RECORDER_INIT_T *prInitData)
{
    CUSTOM_VENC_ERROR_T eError;
    kal_uint32 u4Width = prInitData->u4FrameWidth;
    kal_uint32 u4Height = prInitData->u4FrameHeight;
    VAL_RECORDER_QUALITY_T eValQuality = prInitData->eQuality;
    VAL_RECORDER_CODEC_T eValCodec = prInitData->eCodec;
    VAL_RECORDER_STORAGE_T eValStorage = prInitData->eStorage;
    VAL_RECORDER_SOFTWARE_ROTATOR_T eSoftwareRotator = prInitData->eSoftwareRotator;
    CUSTOM_VENC_QUALITY_T eCustomQuality;
    CUSTOM_VENC_CODEC_T eCustomCodec;
    CUSTOM_VENC_STORAGE_T eCustomStorage;
    CUSTOM_VENC_ROTATE_T eCustomSoftwareRotator;

    eError = CustomVenc_Ctrl(CUSTOM_VENC_OP_SET_WIDTH, &u4Width, sizeof(u4Width), NULL, 0);
    if (eError != CUSTOM_VENC_ERROR_NONE)
    {
        ASSERT(0);
    }

    eError = CustomVenc_Ctrl(CUSTOM_VENC_OP_SET_HEIGHT, &u4Height, sizeof(u4Height), NULL, 0);
    if (eError != CUSTOM_VENC_ERROR_NONE)
    {
        ASSERT(0);
    }

    // Set quality.
    // FIXME: What about CUSTOM_VENC_QUALITY_ALL?
    switch (eValQuality)
    {
    case VAL_RECORDER_QUALITY_LOW:
        eCustomQuality = CUSTOM_VENC_QUALITY_LOW;
        break;

    case VAL_RECORDER_QUALITY_NORMAL:
        eCustomQuality = CUSTOM_VENC_QUALITY_NORMAL;
        break;

    case VAL_RECORDER_QUALITY_GOOD:
        eCustomQuality = CUSTOM_VENC_QUALITY_GOOD;
        break;

    case VAL_RECORDER_QUALITY_FINE:
        eCustomQuality = CUSTOM_VENC_QUALITY_FINE;
        break;

    case VAL_RECORDER_QUALITY_CUSTOM:
        // FIXME (2011/01/28): Remove VAL_RECORDER_QUALITY_CUSTOM.
        //                     Georg told me that CUSTOM setting is not used on feature phone.
        ASSERT(0);
        break;

    default:
        break;
    }
    eError = CustomVenc_Ctrl(CUSTOM_VENC_OP_SET_QUALITY, &eCustomQuality, sizeof(eCustomQuality), NULL, 0);
    if (eError != CUSTOM_VENC_ERROR_NONE)
    {
        ASSERT(0);
    }

    // Set codec.
    // FIXME: What about CUSTOM_VENC_CODEC_ALL?
    switch (eValCodec)
    {
    case VAL_RECORDER_CODEC_H263:
        eCustomCodec = CUSTOM_VENC_CODEC_H263;
        break;

#if defined(__VE_H264_ENC_SW_SUPPORT__)
    case VAL_RECORDER_CODEC_H264:
        eCustomCodec = CUSTOM_VENC_CODEC_H264;
        break;
#endif  // defined(__VE_H264_ENC_SW_SUPPORT__)

    case VAL_RECORDER_CODEC_MPEG4:
        eCustomCodec = CUSTOM_VENC_CODEC_MPEG4;
        break;

    case VAL_RECORDER_CODEC_MJPEG:
        eCustomCodec = CUSTOM_VENC_CODEC_MJPEG;
        break;

    default:
        break;
    }
    eError = CustomVenc_Ctrl(CUSTOM_VENC_OP_SET_CODEC, &eCustomCodec, sizeof(eCustomCodec), NULL, 0);
    if (eError != CUSTOM_VENC_ERROR_NONE)
    {
        ASSERT(0);
    }

    // Set storage.
    // FIXME: What about CUSTOM_VENC_STORAGE_ALL?
    switch (eValStorage)
    {
    case VAL_RECORDER_STORAGE_PHONE:
        eCustomStorage = CUSTOM_VENC_STORAGE_PHONE;
        break;

    case VAL_RECORDER_STORAGE_SD:
        eCustomStorage = CUSTOM_VENC_STORAGE_SD;
        break;

    default:
        break;
    }
    eError = CustomVenc_Ctrl(CUSTOM_VENC_OP_SET_STORAGE, &eCustomStorage, sizeof(eCustomStorage), NULL, 0);
    if (eError != CUSTOM_VENC_ERROR_NONE)
    {
        ASSERT(0);
    }

    switch (eSoftwareRotator)
    {
    case VAL_RECORDER_SOFTWARE_ROTATOR_DISABLED:
        eCustomSoftwareRotator = CUSTOM_VENC_ROTATE_NONE;
        break;

    case VAL_RECORDER_SOFTWARE_ROTATOR_ENABLED:
        eCustomSoftwareRotator = CUSTOM_VENC_ROTATE_ENABLE;
        break;

    default:
        break;
    }
    eError = CustomVenc_Ctrl(CUSTOM_VENC_OP_SET_ROTATE, &eCustomSoftwareRotator, sizeof(eCustomSoftwareRotator), NULL, 0);
    if (eError != CUSTOM_VENC_ERROR_NONE)
    {
        drv_trace1(TRACE_GROUP_10, VAL_REC_CANNOT_SET_SOFTWARE_ROTATOR, (kal_uint32)eError);
        // ASSERT(0);
    }
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_InitRecorder(VAL_RECORDER_INIT_T *prInitData)
{
    VIDEO_RECORD_INIT_STRUCT_T rInitVideoRecorder;
    MEDIA_STATUS_CODE eRecorderError;
    VAL_ERROR_T eValError = VAL_ERR_NONE;
    VAL_RECORDER_CODEC_T eValCodec = prInitData->eCodec;

    kal_mem_set(&rInitVideoRecorder, 0, sizeof(rInitVideoRecorder));
    rInitVideoRecorder.u4Bitrate = prInitData->u4Bitrate;
    rInitVideoRecorder.u4FrameWidth = prInitData->u4FrameWidth;
    rInitVideoRecorder.u4FrameHeight = prInitData->u4FrameHeight;
    // rInitVideoRecorder.u4SyncInterval = prInitData->u4SyncInterval;
    // rInitVideoRecorder.u4IntMemStartAddr = prInitData->u4IntMemoryAddr;
    // rInitVideoRecorder.u4IntMemStartSize = prInitData->u4IntMemorySize;
    rInitVideoRecorder.u4ExtMemStartAddr = prInitData->u4ExtMemoryAddr;
    rInitVideoRecorder.u4ExtMemStartSize = prInitData->u4ExtMemorySize;

    _rValRecorderMgr.pfnCallBack = prInitData->pfnCallBack;
    rInitVideoRecorder.pfnCallback = (PFN_CALLBACK_T)_val_recorder_Callback;

    switch (prInitData->eQuality)
    {
    case VAL_RECORDER_QUALITY_LOW:
        rInitVideoRecorder.eQuality = VIDEO_RECORDER_QUALITY_LOW;
        break;

    case VAL_RECORDER_QUALITY_NORMAL:
        rInitVideoRecorder.eQuality = VIDEO_RECORDER_QUALITY_NORMAL;
        break;

    case VAL_RECORDER_QUALITY_GOOD:
        rInitVideoRecorder.eQuality = VIDEO_RECORDER_QUALITY_GOOD;
        break;

    case VAL_RECORDER_QUALITY_FINE:
        rInitVideoRecorder.eQuality = VIDEO_RECORDER_QUALITY_FINE;
        break;

    case VAL_RECORDER_QUALITY_CUSTOM:
        rInitVideoRecorder.eQuality = VIDEO_RECORDER_QUALITY_CUSTOM;
        break;

    default:
        eValError = VAL_ERR_INVALID_PARAMETER;
        ASSERT(0);
        return eValError;
    }

    switch (prInitData->eRotationAngle)
    {
    case VAL_RECORDER_ROTATION_ANGLE_0:
        rInitVideoRecorder.eRotationAngle = VIDEO_RECORDER_ROTATION_ANGLE_0;
        break;

    case VAL_RECORDER_ROTATION_ANGLE_90:
        rInitVideoRecorder.eRotationAngle = VIDEO_RECORDER_ROTATION_ANGLE_90;
        break;

    case VAL_RECORDER_ROTATION_ANGLE_180:
        rInitVideoRecorder.eRotationAngle = VIDEO_RECORDER_ROTATION_ANGLE_180;
        break;

    case VAL_RECORDER_ROTATION_ANGLE_270:
        rInitVideoRecorder.eRotationAngle = VIDEO_RECORDER_ROTATION_ANGLE_270;
        break;

    default:
        eValError = VAL_ERR_INVALID_PARAMETER;
        ASSERT(0);
        return eValError;
    }

    switch (eValCodec)
    {
    case VAL_RECORDER_CODEC_MPEG4:
        rInitVideoRecorder.eCodec = VIDEO_RECORDER_CODEC_MPEG4;
        break;

    case VAL_RECORDER_CODEC_H263:
        rInitVideoRecorder.eCodec = VIDEO_RECORDER_CODEC_H263;
        break;

    case VAL_RECORDER_CODEC_H264:
        rInitVideoRecorder.eCodec = VIDEO_RECORDER_CODEC_H264;
        break;

    case VAL_RECORDER_CODEC_MJPEG:
        rInitVideoRecorder.eCodec = VIDEO_RECORDER_CODEC_MJPEG;
        break;

    default:
        eValError = VAL_ERR_INVALID_PARAMETER;
        ASSERT(0);
        return eValError;
    }


    eRecorderError = video_recorder_init_v2(&rInitVideoRecorder);
    _val_recorder_convert_error_code(&eValError, eRecorderError);

    return eValError;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_InitFileMerge(VAL_RECORDER_INIT_T *prInitData)
{
    VIDEO_RECORD_INIT_FILEWRITER_STRUCT_T rInitFileMerge;
    MEDIA_STATUS_CODE eFileMergeError;
    VAL_ERROR_T eValError = VAL_ERR_NONE;

    kal_mem_set(&rInitFileMerge, 0, sizeof(rInitFileMerge));
    // rInitFileMerge.u4IntMemStartAddr = prInitData->u4IntMemoryAddr;
    // rInitFileMerge.u4IntMemStartSize = prInitData->u4IntMemorySize;
    rInitFileMerge.u4ExtMemStartAddr = prInitData->u4ExtMemoryAddr;
    rInitFileMerge.u4ExtMemStartSize = prInitData->u4ExtMemorySize;

    eFileMergeError = video_recorder_init_file_writer_v2(&rInitFileMerge);
    _val_recorder_convert_error_code(&eValError, eFileMergeError);

    return eValError;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_CloseRecorder(VAL_RECORDER_CLOSE_T *prInitData)
{
    MEDIA_STATUS_CODE eRecorderError;
    VAL_ERROR_T eValError = VAL_ERR_NONE;

    eRecorderError = video_recorder_close_v2();
    _val_recorder_convert_error_code(&eValError, eRecorderError);

    return eValError;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_CloseFileMerge(VAL_RECORDER_CLOSE_T *prInitData)
{
    MEDIA_STATUS_CODE eFileMergeError;
    VAL_ERROR_T eValError = VAL_ERR_NONE;

    eFileMergeError = video_recorder_close_file_writer_v2();
    _val_recorder_convert_error_code(&eValError, eFileMergeError);

    return eValError;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_GetPfnForGettingBuffer(void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    PFN_VAL_RECORDER_GET_BUFFER_T *ppfnGetBuffer;

    if ((pvOutput == NULL) || (pu4RealOutputLen == NULL))
    {
        ASSERT(0);
    }
    if (u4OutputLen < sizeof(*ppfnGetBuffer))
    {
        ASSERT(0);
    }

    ppfnGetBuffer = (PFN_VAL_RECORDER_GET_BUFFER_T*)pvOutput;
    *ppfnGetBuffer = VideoRecorderGetSourceBuffer;
    _rValRecorderMgr.pfnGetBuffer = VideoRecorderGetSourceBuffer;
    *pu4RealOutputLen = sizeof(*ppfnGetBuffer);
    drv_trace2(TRACE_GROUP_10, VAL_REC_GET_BUFFER, (kal_uint32)pvOutput, (kal_uint32)*ppfnGetBuffer);

    return VAL_ERR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_GetPfnForReturningBuffer(void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    PFN_VAL_RECORDER_COMPLETE_BUFFER_T *pfnReturnBuffer;

    if ((pvOutput == NULL) || (pu4RealOutputLen == NULL))
    {
        ASSERT(0);
    }
    if (u4OutputLen < sizeof(*pfnReturnBuffer))
    {
        ASSERT(0);
    }

    pfnReturnBuffer = (PFN_VAL_RECORDER_COMPLETE_BUFFER_T*)pvOutput;
    *pfnReturnBuffer = VideoRecorderCompleteSourceBuffer;
    _rValRecorderMgr.pfnReturnBuffer = VideoRecorderCompleteSourceBuffer;
    *pu4RealOutputLen = sizeof(*pfnReturnBuffer);
    drv_trace2(TRACE_GROUP_10, VAL_REC_RETURN_BUFFER, (kal_uint32)pvOutput, (kal_uint32)*pfnReturnBuffer);

    return VAL_ERR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_Start(void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    MEDIA_STATUS_CODE eRecorderError;
    VAL_ERROR_T eValError = VAL_ERR_NONE;

    eRecorderError = video_recorder_start_v2();
    _val_recorder_convert_error_code(&eValError, eRecorderError);

    return eValError;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_Stop(void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    MEDIA_STATUS_CODE eRecorderError;
    VAL_ERROR_T eValError = VAL_ERR_NONE;

    eRecorderError = video_recorder_stop_v2();
    _val_recorder_convert_error_code(&eValError, eRecorderError);

    return eValError;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_WaitStopDone(void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    MEDIA_STATUS_CODE eRecorderError;
    VAL_ERROR_T eValError = VAL_ERR_NONE;

    eRecorderError = video_recorder_wait_stop_done_v2();
    _val_recorder_convert_error_code(&eValError, eRecorderError);

    return eValError;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_SetBitRate(void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    kal_uint32 *pu4BitRate;

    if ((pvInput == NULL) || (sizeof(*pu4BitRate) != u4InputLen))
    {
        ASSERT(0);
    }
    pu4BitRate = (kal_uint32*)pvInput;
    video_recorder_set_bitrate_v2(*pu4BitRate);

    return VAL_ERR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_SetFrameRate(void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    kal_uint32 *pu4FrameRate;

    if ((pvInput == NULL) || (sizeof(*pu4FrameRate) != u4InputLen))
    {
        ASSERT(0);
    }
    pu4FrameRate = (kal_uint32*)pvInput;
    video_recorder_set_framerate_v2(*pu4FrameRate);

    return VAL_ERR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_ReduceSpeed(void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    kal_uint32 *pu4SleepTimeInMilliSecond;

    if ((pvInput == NULL) || (sizeof(*pu4SleepTimeInMilliSecond) != u4InputLen))
    {
        ASSERT(0);
    }
    pu4SleepTimeInMilliSecond = (kal_uint32*)pvInput;
    video_recorder_reduce_speed_v2(*pu4SleepTimeInMilliSecond);

    return VAL_ERR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_SetFileHandle(void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    VAL_RECORDER_OUTPUT_FILES_T *prOutputFiles;
    MEDIA_STATUS_CODE eRecorderError;
    VAL_ERROR_T eValError = VAL_ERR_NONE;

    if ((pvInput == NULL) || (sizeof(*prOutputFiles) != u4InputLen))
    {
        ASSERT(0);
    }
    prOutputFiles = (VAL_RECORDER_OUTPUT_FILES_T*)pvInput;
    eRecorderError = video_recorder_set_file_handles_v2(prOutputFiles->prVideoFile,
        prOutputFiles->prTempMetaFile, prOutputFiles->prMetaFile);
    _val_recorder_convert_error_code(&eValError, eRecorderError);

    return eValError;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_StoreVideoFile(void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    MEDIA_STATUS_CODE eRecorderError;
    VAL_ERROR_T eValError = VAL_ERR_NONE;

    eRecorderError = video_recorder_store_video_file_v2();
    _val_recorder_convert_error_code(&eValError, eRecorderError);

    return eValError;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_StoreMetaFile(void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    MEDIA_STATUS_CODE eRecorderError;
    VAL_ERROR_T eValError = VAL_ERR_NONE;

    eRecorderError = video_recorder_store_meta_file_v2();
    _val_recorder_convert_error_code(&eValError, eRecorderError);

    return eValError;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_GetVideoFileSize(void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    kal_uint32 *pu4VideoFileSize;

    if ((pvOutput == NULL) || (pu4RealOutputLen == NULL))
    {
        ASSERT(0);
    }
    if (u4OutputLen < sizeof(*pu4VideoFileSize))
    {
        ASSERT(0);
    }

    pu4VideoFileSize = (kal_uint32*)pvOutput;
    *pu4VideoFileSize = video_recorder_get_bitstream_file_size_v2();
    *pu4RealOutputLen = sizeof(*pu4VideoFileSize);
    drv_trace2(TRACE_GROUP_10, VAL_REC_GET_VIDEO_FILE_SIZE, (kal_uint32)pvOutput, *pu4VideoFileSize);

    return VAL_ERR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_GetMetaFileSize(void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    kal_uint32 *pu4MetaFileSize;

    if ((pvOutput == NULL) || (pu4RealOutputLen == NULL))
    {
        ASSERT(0);
    }
    if (u4OutputLen < sizeof(*pu4MetaFileSize))
    {
        ASSERT(0);
    }

    pu4MetaFileSize = (kal_uint32*)pvOutput;
    *pu4MetaFileSize = video_recorder_get_meta_file_size_v2();
    *pu4RealOutputLen = sizeof(*pu4MetaFileSize);
    drv_trace2(TRACE_GROUP_10, VAL_REC_GET_META_FILE_SIZE, (kal_uint32)pvOutput, *pu4MetaFileSize);

    return VAL_ERR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_EvaluateRealMetaFileSize(void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    kal_uint32 *pu4EvaluatedSize;

    if ((pvOutput == NULL) || (pu4RealOutputLen == NULL))
    {
        ASSERT(0);
    }
    if (u4OutputLen < sizeof(*pu4EvaluatedSize))
    {
        ASSERT(0);
    }

    pu4EvaluatedSize = (kal_uint32*)pvOutput;
    *pu4EvaluatedSize = video_recorder_evaluate_real_meta_file_size_v2();
    *pu4RealOutputLen = sizeof(*pu4EvaluatedSize);
    drv_trace2(TRACE_GROUP_10, VAL_REC_EVALUATE_META_FILE_SIZE, (kal_uint32)pvOutput, *pu4EvaluatedSize);

    return VAL_ERR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_CreateMetaFile(void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    MEDIA_STATUS_CODE eRecorderError;
    VAL_ERROR_T eValError = VAL_ERR_NONE;

    eRecorderError = video_recorder_create_meta_file_v2();
    _val_recorder_convert_error_code(&eValError, eRecorderError);

    return eValError;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_GetMetaFileDuration(void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    kal_uint32 *pu4MetaFileDuration;

    if ((pvOutput == NULL) || (pu4RealOutputLen == NULL))
    {
        ASSERT(0);
    }
    if (u4OutputLen < sizeof(*pu4MetaFileDuration))
    {
        ASSERT(0);
    }

    pu4MetaFileDuration = (kal_uint32*)pvOutput;
    *pu4MetaFileDuration = video_recorder_get_meta_file_duration_v2();
    *pu4RealOutputLen = sizeof(*pu4MetaFileDuration);
    drv_trace2(TRACE_GROUP_10, VAL_REC_GET_META_FILE_DURATION, (kal_uint32)pvOutput, *pu4MetaFileDuration);

    return VAL_ERR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_GetPosOfMdatSize(void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    kal_uint32 *pu4PosOfMdatSize;
    MEDIA_STATUS_CODE eRecorderError;
    VAL_ERROR_T eValError = VAL_ERR_NONE;

    if ((pvOutput == NULL) || (pu4RealOutputLen == NULL))
    {
        ASSERT(0);
    }
    if (u4OutputLen < sizeof(*pu4PosOfMdatSize))
    {
        ASSERT(0);
    }

    pu4PosOfMdatSize = (kal_uint32*)pvOutput;
    eRecorderError = video_recorder_get_mdatsz_pos_v2(pu4PosOfMdatSize);
    *pu4RealOutputLen = sizeof(*pu4PosOfMdatSize);
    _val_recorder_convert_error_code(&eValError, eRecorderError);
    drv_trace2(TRACE_GROUP_10, VAL_REC_GET_POS_OF_MDAT_SIZE, (kal_uint32)pvOutput, *pu4PosOfMdatSize);

    return eValError;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_GetPosOfMoov(void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    VAL_RECORDER_MOOV_INFO_T *prMoovInfo;
    MEDIA_STATUS_CODE eRecorderError;
    VAL_ERROR_T eValError = VAL_ERR_NONE;

    if ((pvOutput == NULL) || (pu4RealOutputLen == NULL))
    {
        ASSERT(0);
    }
    if (u4OutputLen < sizeof(*prMoovInfo))
    {
        ASSERT(0);
    }

    prMoovInfo = (VAL_RECORDER_MOOV_INFO_T*)pvOutput;
    eRecorderError = video_recorder_get_moov_pos_v2(&prMoovInfo->u4Pos, &prMoovInfo->u4Size);
    *pu4RealOutputLen = sizeof(*prMoovInfo);
    _val_recorder_convert_error_code(&eValError, eRecorderError);
    drv_trace4(TRACE_GROUP_10, VAL_REC_GET_POS_OF_MOOV, (kal_uint32)pvOutput,
        prMoovInfo->u4Pos, prMoovInfo->u4Size, 0);

    return eValError;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_SetAudioFormat(void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    Media_Format *peAudioFormat;

    if ((pvInput == NULL) || (sizeof(*peAudioFormat) != u4InputLen))
    {
        ASSERT(0);
    }
    peAudioFormat = (Media_Format*)pvInput;
    video_recorder_set_audioformat_v2(*peAudioFormat);

    return VAL_ERR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_GetCurrentTime(void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    kal_uint64 *pu8CurrentTime;

    if ((pvOutput == NULL) || (pu4RealOutputLen == NULL))
    {
        ASSERT(0);
    }
    if (u4OutputLen < sizeof(*pu8CurrentTime))
    {
        ASSERT(0);
    }

    pu8CurrentTime = (kal_uint64*)pvOutput;
    *pu8CurrentTime = video_recorder_get_current_time_v2();
    *pu4RealOutputLen = sizeof(*pu8CurrentTime);
    drv_trace4(TRACE_GROUP_10, VAL_REC_GET_CURRENT_TIME, (kal_uint32)pvOutput,
        ((*pu8CurrentTime >> 32) & 0xFFFFFFFF), (*pu8CurrentTime & 0xFFFFFFFF), 0);

    return VAL_ERR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_DoVideoAndMetaFilesExist(void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    VAL_RECORDER_OUTPUT_FILES_T *prOutputFiles;
    MEDIA_STATUS_CODE eRecorderError;
    VAL_ERROR_T eValError = VAL_ERR_NONE;

    if ((pvInput == NULL) || (sizeof(*prOutputFiles) != u4InputLen))
    {
        ASSERT(0);
    }
    prOutputFiles = (VAL_RECORDER_OUTPUT_FILES_T*)pvInput;
    eRecorderError = video_recorder_check_meta_file_available_v2(prOutputFiles->prVideoFile,
        prOutputFiles->prTempMetaFile);
    _val_recorder_convert_error_code(&eValError, eRecorderError);

    return eValError;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_SetRecordingYuv(void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    kal_bool *pfgRecordingYuv;

    if ((pvInput == NULL) || (sizeof(*pfgRecordingYuv) != u4InputLen))
    {
        ASSERT(0);
    }
    pfgRecordingYuv = (kal_bool*)pvInput;
    video_recorder_set_record_YUV(*pfgRecordingYuv);

    return VAL_ERR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
static VAL_ERROR_T _val_recorder_SetColorFormat(void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    VAL_RECORDER_COLOR_FORMAT_T *peValColorFormat;
    VIDEO_RECORD_COLOR_FORMAT_T eColorFormat;
    MEDIA_STATUS_CODE eRecorderError;
    VAL_ERROR_T eValError = VAL_ERR_NONE;

    if ((pvInput == NULL) || (sizeof(*peValColorFormat) != u4InputLen))
    {
        ASSERT(0);
    }
    peValColorFormat = (VAL_RECORDER_COLOR_FORMAT_T*)pvInput;
    switch (*peValColorFormat)
    {
    case VAL_RECORDER_COLOR_FORMAT_YUV_420:
        eColorFormat = VIDEO_RECORD_COLOR_FORMAT_YUV_420;
        break;

    case VAL_RECORDER_COLOR_FORMAT_YUV_422:
        eColorFormat = VIDEO_RECORD_COLOR_FORMAT_YUV_422;
        break;

    case VAL_RECORDER_COLOR_FORMAT_RGB_565:
        eColorFormat = VIDEO_RECORD_COLOR_FORMAT_RGB_565;
        break;

    case VAL_RECORDER_COLOR_FORMAT_RGB_888:
        eColorFormat = VIDEO_RECORD_COLOR_FORMAT_RGB_888;
        break;

    default:
        eValError = VAL_ERR_INVALID_PARAMETER;
        ASSERT(0);
        return eValError;
    }

    eRecorderError = video_recorder_set_color_format(&eColorFormat);
    _val_recorder_convert_error_code(&eValError, eRecorderError);

    return eValError;
}


/*****************************************************************************
* Set file size limit.
*****************************************************************************/
static VAL_ERROR_T _val_recorder_SetFileSizeLimit(void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    kal_uint64 *pu8Limit;
    MEDIA_STATUS_CODE eRecorderError;
    VAL_ERROR_T eValError = VAL_ERR_NONE;

    if ((pvInput == NULL) || (sizeof(*pu8Limit) != u4InputLen))
    {
        ASSERT(0);
    }
    pu8Limit = (kal_uint64*)pvInput;
    eRecorderError = video_recorder_set_file_size_limit_v2(pu8Limit);
    _val_recorder_convert_error_code(&eValError, eRecorderError);

    return eValError;
}


/*****************************************************************************
*
*****************************************************************************/
VAL_ERROR_T VAL_RECORDER_Init(void)
{
    kal_mem_set(&_rValRecorderMgr, 0, sizeof(_rValRecorderMgr));

    return VAL_ERR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
VAL_ERROR_T VAL_RECORDER_DeInit(void)
{
    return VAL_ERR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
VAL_ERROR_T VAL_RECORDER_Open(void *pvInput, kal_uint32 u4InputLen)
{
    VAL_RECORDER_INIT_T *prInitData;
    VAL_ERROR_T eValError = VAL_ERR_NONE;

    drv_trace0(TRACE_GROUP_10, VAL_REC_OPEN_BEGIN);

    if ((pvInput == NULL) || (sizeof(*prInitData) != u4InputLen))
    {
        ASSERT(0);
    }

    prInitData = (VAL_RECORDER_INIT_T*)pvInput;
    switch (prInitData->eFunction)
    {
    case VAL_RECORDER_FUNCTION_VIDEO_RECORDING:
        _val_recorder_SetFrameRateTableProperties(prInitData);
        eValError = _val_recorder_InitRecorder(prInitData);
        break;

    case VAL_RECORDER_FUNCTION_FILE_MERGE:
        eValError = _val_recorder_InitFileMerge(prInitData);
        break;

    default:
        eValError = VAL_ERR_INVALID_PARAMETER;
        ASSERT(0);
        break;
    }

    drv_trace0(TRACE_GROUP_10, VAL_REC_OPEN_END);

    return eValError;
}


/*****************************************************************************
*
*****************************************************************************/
VAL_ERROR_T VAL_RECORDER_Ctrl(kal_uint32 u4Operation, void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    VAL_ERROR_T eValError = VAL_ERR_NONE;

    drv_trace0(TRACE_GROUP_10, VAL_REC_CTRL_BEGIN);

    if ((u4Operation < VAL_RECORDER_OP_BASE) || (VAL_RECORDER_OP_MAX < u4Operation))
    {
        drv_trace1(TRACE_GROUP_10, VAL_REC_CTRL_INVALID_OP, u4Operation);
        return VAL_ERR_INVALID_PARAMETER;
    }

    switch (u4Operation)
    {
    case VAL_RECORDER_OP_GET_PFN_FOR_GETTING_BUFFER:
        eValError = _val_recorder_GetPfnForGettingBuffer(pvInput, u4InputLen, pvOutput,
            u4OutputLen, pu4RealOutputLen);
        break;

    case VAL_RECORDER_OP_GET_PFN_FOR_RETURNING_BUFFER:
        eValError = _val_recorder_GetPfnForReturningBuffer(pvInput, u4InputLen, pvOutput,
            u4OutputLen, pu4RealOutputLen);
        break;

    case VAL_RECORDER_OP_START:
        eValError = _val_recorder_Start(pvInput, u4InputLen, pvOutput,
            u4OutputLen, pu4RealOutputLen);
        break;

    case VAL_RECORDER_OP_STOP:
        eValError = _val_recorder_Stop(pvInput, u4InputLen, pvOutput,
            u4OutputLen, pu4RealOutputLen);
        break;

    case VAL_RECORDER_OP_WAIT_STOP_DONE:
        eValError = _val_recorder_WaitStopDone(pvInput, u4InputLen, pvOutput,
            u4OutputLen, pu4RealOutputLen);
        break;

    case VAL_RECORDER_OP_SET_BIT_RATE:
        eValError = _val_recorder_SetBitRate(pvInput, u4InputLen, pvOutput,
            u4OutputLen, pu4RealOutputLen);
        break;

    case VAL_RECORDER_OP_SET_FRAME_RATE:
        eValError = _val_recorder_SetFrameRate(pvInput, u4InputLen, pvOutput,
            u4OutputLen, pu4RealOutputLen);
        break;

    case VAL_RECORDER_OP_REDUCE_SPEED:
        eValError = _val_recorder_ReduceSpeed(pvInput, u4InputLen, pvOutput,
            u4OutputLen, pu4RealOutputLen);
        break;

    case VAL_RECORDER_OP_SET_FILE_HANDLE:
        eValError = _val_recorder_SetFileHandle(pvInput, u4InputLen, pvOutput,
            u4OutputLen, pu4RealOutputLen);
        break;

    case VAL_RECORDER_OP_STORE_VIDEO_FILE:
        eValError = _val_recorder_StoreVideoFile(pvInput, u4InputLen, pvOutput,
            u4OutputLen, pu4RealOutputLen);
        break;

    case VAL_RECORDER_OP_STORE_META_FILE:
        eValError = _val_recorder_StoreMetaFile(pvInput, u4InputLen, pvOutput,
            u4OutputLen, pu4RealOutputLen);
        break;

    case VAL_RECORDER_OP_GET_VIDEO_FILE_SIZE:
        eValError = _val_recorder_GetVideoFileSize(pvInput, u4InputLen, pvOutput,
            u4OutputLen, pu4RealOutputLen);
        break;

    case VAL_RECORDER_OP_GET_META_FILE_SIZE:
        eValError = _val_recorder_GetMetaFileSize(pvInput, u4InputLen, pvOutput,
            u4OutputLen, pu4RealOutputLen);
        break;

    case VAL_RECORDER_OP_EVALUATE_REAL_META_FILE_SIZE:
        eValError = _val_recorder_EvaluateRealMetaFileSize(pvInput, u4InputLen, pvOutput,
            u4OutputLen, pu4RealOutputLen);
        break;

    case VAL_RECORDER_OP_CREATE_META_FILE:
        eValError = _val_recorder_CreateMetaFile(pvInput, u4InputLen, pvOutput,
            u4OutputLen, pu4RealOutputLen);
        break;

    case VAL_RECORDER_OP_GET_META_FILE_DURATION:
        eValError = _val_recorder_GetMetaFileDuration(pvInput, u4InputLen, pvOutput,
            u4OutputLen, pu4RealOutputLen);
        break;

    case VAL_RECORDER_OP_GET_POS_OF_MDAT_SIZE:
        eValError = _val_recorder_GetPosOfMdatSize(pvInput, u4InputLen, pvOutput,
            u4OutputLen, pu4RealOutputLen);
        break;

    case VAL_RECORDER_OP_GET_POS_OF_MOOV:
        eValError = _val_recorder_GetPosOfMoov(pvInput, u4InputLen, pvOutput,
            u4OutputLen, pu4RealOutputLen);
        break;

    case VAL_RECORDER_OP_SET_AUDIO_FORMAT:
        eValError = _val_recorder_SetAudioFormat(pvInput, u4InputLen, pvOutput,
            u4OutputLen, pu4RealOutputLen);
        break;

    case VAL_RECORDER_OP_GET_CURRENT_TIME:
        eValError = _val_recorder_GetCurrentTime(pvInput, u4InputLen, pvOutput,
            u4OutputLen, pu4RealOutputLen);
        break;

    case VAL_RECORDER_OP_GET_CURRENT_TIME_STAMP:  // Not used any more! [MAUI_02976426]
        ASSERT(0);
        break;

    case VAL_RECORDER_OP_DO_VIDEO_AND_META_FILES_EXIST:
        eValError = _val_recorder_DoVideoAndMetaFilesExist(pvInput, u4InputLen, pvOutput,
            u4OutputLen, pu4RealOutputLen);
        break;

    case VAL_RECORDER_OP_SET_RECORDING_YUV:
        eValError = _val_recorder_SetRecordingYuv(pvInput, u4InputLen, pvOutput,
            u4OutputLen, pu4RealOutputLen);
        break;

    case VAL_RECORDER_OP_SET_COLOR_FORMAT:
        eValError = _val_recorder_SetColorFormat(pvInput, u4InputLen, pvOutput,
            u4OutputLen, pu4RealOutputLen);
        break;

    case VAL_RECORDER_OP_SET_FILE_SIZE_LIMIT:
        eValError = _val_recorder_SetFileSizeLimit(pvInput, u4InputLen, pvOutput,
                u4OutputLen, pu4RealOutputLen);
        break;

    default:
        eValError = VAL_ERR_INVALID_PARAMETER;
        ASSERT(0);
        break;
    }

    drv_trace0(TRACE_GROUP_10, VAL_REC_CTRL_END);

    return eValError;
}


/*****************************************************************************
*
*****************************************************************************/
VAL_ERROR_T VAL_RECORDER_Close(void *pvInput, kal_uint32 u4InputLen)
{
    VAL_RECORDER_CLOSE_T *prCloseData;
    VAL_ERROR_T eValError = VAL_ERR_NONE;

    drv_trace0(TRACE_GROUP_10, VAL_REC_CLOSE_BEGIN);

    if ((pvInput == NULL) || (sizeof(*prCloseData) != u4InputLen))
    {
        ASSERT(0);
    }

    prCloseData = (VAL_RECORDER_CLOSE_T*)pvInput;
    switch (prCloseData->eFunction)
    {
    case VAL_RECORDER_FUNCTION_VIDEO_RECORDING:
        eValError = _val_recorder_CloseRecorder(prCloseData);
        break;

    case VAL_RECORDER_FUNCTION_FILE_MERGE:
        eValError = _val_recorder_CloseFileMerge(prCloseData);
        break;

    default:
        eValError = VAL_ERR_INVALID_PARAMETER;
        ASSERT(0);
        break;
    }

    drv_trace0(TRACE_GROUP_10, VAL_REC_CLOSE_END);

    return eValError;
}


#endif  // defined(__VE_MPEG4_ENC_SUPPORT__) || defined(__VE_H264_ENC_SW_SUPPORT__)
#endif  // __VE_VIDEO_ARCHI_V2__

