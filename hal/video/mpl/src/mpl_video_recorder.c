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
 * mpl_video_recorder.c
 *
 * Project:
 * --------
 * Maui
 *
 * Description:
 * ------------
 * This file implements the Media Porting Layer of video recorder.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by CQ. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 01 26 2014 tofar.huang
 * removed!
 * 	.
 *
 * 01 26 2014 tofar.huang
 * removed!
 * 	.
 *
 * 08 24 2012 pibben.tung
 * removed!
 * .
 *
 * 07 09 2012 pibben.tung
 * removed!
 * .
 *
 * 06 13 2012 pibben.tung
 * removed!
 * .
 *
 * 04 24 2012 pibben.tung
 * removed!
 * .
 *
 * 04 18 2012 pibben.tung
 * removed!
 * .
 *
 * 04 16 2012 pibben.tung
 * removed!
 * .
 *
 * 04 10 2012 pibben.tung
 * removed!
 * .
 *
 * 04 10 2012 pibben.tung
 * removed!
 * .
 *
 * 04 06 2012 pibben.tung
 * removed!
 * .
 *
 * 04 02 2012 pibben.tung
 * removed!
 * .
 *
 * 03 21 2012 leroy.lin
 * removed!
 * .
 *
 * 03 13 2012 leroy.lin
 * removed!
 * .
 *
 * 02 29 2012 leroy.lin
 * removed!
 * .
 *
 * 02 13 2012 leroy.lin
 * removed!
 * .
 *
 * 02 09 2012 pibben.tung
 * removed!
 * .
 *
 * 02 06 2012 leroy.lin
 * removed!
 * .
 *
 * 01 31 2012 leroy.lin
 * removed!
 * .
 *
 * 01 31 2012 leroy.lin
 * removed!
 * .
 *
 * 01 30 2012 leroy.lin
 * removed!
 * .
 *
 * 01 30 2012 leroy.lin
 * removed!
 * .
 *
 * 01 02 2012 leroy.lin
 * removed!
 * .
 *
 * 12 29 2011 leroy.lin
 * removed!
 * .
 *
 * 12 28 2011 leroy.lin
 * removed!
 * .
 *
 * 12 20 2011 leroy.lin
 * removed!
 * .
 *
 * 12 20 2011 leroy.lin
 * removed!
 * .
 *
 * 12 14 2011 leroy.lin
 * removed!
 * .
 *
 * 12 07 2011 leroy.lin
 * removed!
 * .
 *
 * 12 06 2011 leroy.lin
 * removed!
 * .
 *
 * 11 30 2011 leroy.lin
 * removed!
 * .
 *
 * 11 23 2011 leroy.lin
 * removed!
 * .
 *
 * 11 01 2011 leroy.lin
 * removed!
 * .
 *
 * 10 20 2011 leroy.lin
 * removed!
 * .
 *
 * 10 18 2011 leroy.lin
 * removed!
 * .
 *
 * 10 04 2011 leroy.lin
 * removed!
 * .
 *
 * 10 04 2011 leroy.lin
 * removed!
 * .
 *
 * 09 20 2011 leroy.lin
 * removed!
 * .
 *
 * 09 16 2011 leroy.lin
 * removed!
 * .
 *
 * 09 08 2011 leroy.lin
 * removed!
 * .
 *
 * 09 05 2011 leroy.lin
 * removed!
 * .
 *
 * 09 02 2011 leroy.lin
 * removed!
 * .
 *
 * 08 30 2011 leroy.lin
 * removed!
 * .
 *
 * 08 30 2011 leroy.lin
 * removed!
 * .
 *
 * 08 26 2011 leroy.lin
 * removed!
 * .
 *
 * 08 24 2011 leroy.lin
 * removed!
 * .
 *
 * 08 23 2011 leroy.lin
 * removed!
 * .
 *
 * 08 19 2011 leroy.lin
 * removed!
 * .
 *
 * 08 17 2011 leroy.lin
 * removed!
 * .
 *
 * 08 17 2011 leroy.lin
 * removed!
 * .
 *
 * 08 16 2011 leroy.lin
 * removed!
 * .
 *
 * 08 15 2011 leroy.lin
 * removed!
 * .
 *
 * 08 15 2011 leroy.lin
 * removed!
 * .
 *
 * 08 09 2011 leroy.lin
 * removed!
 * .
 *
 * 08 04 2011 leroy.lin
 * removed!
 * .
 *
 * 07 27 2011 leroy.lin
 * removed!
 * .
 *
 * 07 26 2011 leroy.lin
 * removed!
 * .
 *
 * 07 13 2011 leroy.lin
 * NULL
 * Correct control flow so that Source can have frame buffer before IDP tries to get frame buffer.
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by CQ. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#if defined(__VIDEO_ARCHI_V2__) && (defined(MP4_ENCODE) || defined(MJPG_ENCODE))

#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "stack_config.h"
#include "stack_ltlcom.h"
#include "app_ltlcom.h"         /* Task message communiction */
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"

#include "mpl_recorder.h"
#include "mm_comm_def.h"
#include "fs_type.h"
#include "fs_func.h"
#include "Fs_errcode.h"
#include "visual_comm.h"
#include "custom_video_enc_if.h"
#include "vcodec_v2_trc.h"
#include "med_struct.h"
#include "video_memory_usage_v2.h"
#include "jpeg_mem.h"
#include "cal_mem_def.h"

#include "video_recorder_clock_utility_if_v2.h"
#include "video_recorder_source_component_if_v2.h"
#include "video_encoder_component_if_v2.h"
#include "video_muxer_if_v2.h"
#include "mpl_omx_core.h"
#include "mpl_video_recorder.h"
#include "drv_features_video.h"             // for __VE_MJPEG_DIRECT_COUPLED_SENSOR__
#include "video_codec_mem_v2.h"             // for MPLVR_AVI_AUDIO_BUFFER_SIZE and MPLVR_MP4_AUDIO_BUFFER_SIZE
#include "l1audio.h"                        // for L1SP_SetSpeechEnhanceAndFir()


#if defined(__VE_AVI_ENC_SUPPORT__)
#include "med_main.h"
#endif  // defined(__VE_AVI_ENC_SUPPORT__)


#ifdef __VE_DCM_WITH_COMPRESSION__
#include "dcmgr.h"  // for DCM
#endif  // __VE_DCM_WITH_COMPRESSION__


/*****************************************************************************
* Macro(s)
*****************************************************************************/
//#ifndef MPLVR_DEVELOPMENT
//#define MPLVR_DEVELOPMENT
//#endif  // MPLVR_DEVELOPMENT


#ifdef __VE_DCM_WITH_COMPRESSION__
#pragma arm section code = "DYNAMIC_CODE_VEENC_ROCODE", rodata = "DYNAMIC_CODE_VEENC_RODATA"
#endif  // __VE_DCM_WITH_COMPRESSION__


// Make use of C99 variadic macros.
#if defined(MPLVR_DEVELOPMENT)
#define MPLVR_TRACE(x, ...)             kal_trace(x, __VA_ARGS__)
#else
#define MPLVR_TRACE(x, ...)             { /* empty */ }
#endif  // defined(MPLVR_DEVELOPMENT)


/*****************************************************************************
* Definition of macros
*****************************************************************************/
#ifndef UNUSED
#define UNUSED(x)               ((void)(x))
#endif  // UNUSED


#if defined(__VE_SLIM_PROJECT__) && !defined(MPLVR_DEVELOPMENT)
    #define _MPLVR_ASSERT(x)                    do { /* empty */ } while (0)
    #define _MPLVR_ASSERT_IF_EQUAL(x, y)        do { UNUSED(x);  } while (0)
    #define _MPLVR_ASSERT_IF_NOT_EQUAL(x, y)    do { UNUSED(x);  } while (0)
    #define _MPLVR_CHECK_SIZE(x, y)             do { /* empty */ } while (0)
#else
    #define _MPLVR_ASSERT(x)                    ASSERT(x)

    #define _MPLVR_ASSERT_IF_EQUAL(x, y)                                \
        do {                                                            \
            if ((x) == (y))                                             \
            {                                                           \
                ASSERT(0);                                              \
            }                                                           \
        } while (0)

    #define _MPLVR_ASSERT_IF_NOT_EQUAL(x, y)                            \
        do {                                                            \
            if ((x) != (y))                                             \
            {                                                           \
                ASSERT(0);                                              \
            }                                                           \
        } while (0)

    #define _MPLVR_CHECK_SIZE(x, y)                                     \
        do {                                                            \
            if (sizeof(x) != (y))                                       \
            {                                                           \
                ASSERT(0);                                              \
            }                                                           \
        } while (0)
#endif  // defined(__VE_SLIM_PROJECT__) && !defined(MPLVR_DEVELOPMENT)


#if defined(__HD_RECORD__)
    #define _MPLVR_SET_HD_AUDIO_PROPERTY()                                  \
        do {                                                                \
            L1SP_SetSpeechEnhanceAndFir(                                    \
                SPH_ENH_AND_FIR_SCENE_HD_RECORD_VIDEO_HANDSET,              \
                SPH_ENH_AND_FIR_UPDATE_TYPE_ALL);                           \
        } while (0)
#else
    #define _MPLVR_SET_HD_AUDIO_PROPERTY()      do { /* empty */ } while (0)
#endif  // defined(__HD_RECORD__)


/*****************************************************************************
* Static global variable(s)
*****************************************************************************/
static MPLVR_MANAGER_T _rMplvrMgr;


/*****************************************************************************
* Forward declaration
*****************************************************************************/
static void _MPLVR_DoStop(void);
static void _MPLVR_DoClose(void);
static void _MPLVR_MUXER_Stop(kal_bool fgSolo);
static void _MPLVR_MUXER_Close(kal_bool fgSolo);
static void _MPLVR_SetEvents(kal_uint32 u4Event);

#ifdef __VE_STREAM_SERVER_SUPPORT__
#define MPLVR_RTP_ARM_FRAME_SIZE (33)   // 20ms
#define MPLVR_RTP_AMR_THRESHOLD (MPLVR_RTP_ARM_FRAME_SIZE * 6)  // 20ms * 6 = 120ms
#define MPLVR_RTP_AMR_BUFFER_SIZE (MPLVR_RTP_ARM_FRAME_SIZE * 600)  // 20ms * 600 = 12 sec

#define MPLVR_RTP_PCM_FRAME_SIZE (16)   // 2ms
#define MPLVR_RTP_PCM_THRESHOLD (MPLVR_RTP_PCM_FRAME_SIZE * 60) // 2ms * 60 = 120ms
#define MPLVR_RTP_PCM_BUFFER_SIZE (MPLVR_RTP_PCM_FRAME_SIZE * 600)  // 2ms * 600 = 1.2 sec
static kal_bool fgEnableAMR = KAL_TRUE;
mpl_recorder_t* construct_rtp_recorder(mpl_recorder_client_t *prMplvrClient);
#endif


static VIDEO_ERROR_TYPE_T _MPLVR_ENCODER_EventHandler(VIDEO_EVENT_TYPE_T eEvent,
        kal_uint32 u4Data1, kal_uint32 u4Data2, void *pData);

const static VIDEO_CALLBACK_TYPE_T _MPLVR_ENCODER_CallbackStruct =
{
    _MPLVR_ENCODER_EventHandler, NULL
};

static VIDEO_ERROR_TYPE_T _MPLVR_MUXER_EventHandler(VIDEO_EVENT_TYPE_T eEvent,
        kal_uint32 u4Data1, kal_uint32 u4Data2, void *pData);

const static VIDEO_CALLBACK_TYPE_T _MPLVR_MUXER_CallbackStruct =
{
    _MPLVR_MUXER_EventHandler, NULL
};


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_DoStopOnError(void)
{
    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_DO_STOP_ON_ERROR, _rMplvrMgr.eState);

    switch (_rMplvrMgr.eState)
    {
    case MPLVR_STATE_RECORDING:
    case MPLVR_STATE_PAUSED:
    case MPLVR_STATE_RECORDING_AUDIO:
        _MPLVR_DoStop();
        break;

    case MPLVR_STATE_SAVING_FILE:
        _MPLVR_MUXER_Stop(KAL_TRUE);
        _MPLVR_MUXER_Close(KAL_TRUE);
        _MPLVR_DoClose();
        break;

    default:
        break;
    }
}


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // 0


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_StopAndNotifyOnError(kal_uint32 u4Param1, kal_uint32 u4Param2)
{
    mpl_recorder_event_enum_t eEvent = (mpl_recorder_event_enum_t)u4Param1;
    media_error_t eMediaError = (media_error_t)u4Param2;
    mpl_recorder_client_t * const prClient = _rMplvrMgr.prClient;

    // A log is printed in _MPLVR_DoStopOnError(). No extra log is needed here.
    _MPLVR_DoStopOnError();

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_NOTIFY_ON_ERROR, eEvent, eMediaError);
    prClient->on_event_callback((mpl_recorder_client_t*)prClient, eEvent, eMediaError);
}


/*****************************************************************************
* ---------------------------------------------------------------------------------------------------
* | FS_GetDevStatus()    |                           QueryType                                      |
* |-------------------------------------------------------------------------------------------------|
* |        | Memory Card | FS_DEVICE_PRESENCE_ENUM | FS_EXPORT_STATE_ENUM     | FS_MOUNT_STATE_ENUM |
* |-------------------------------------------------------------------------------------------------|
* | Normal | Removed     | FS_MSDC_NOT_PRESENT     | FS_NO_ERROR              | FS_MSDC_MOUNT_ERROR |
* |        | Inserted    | FS_NO_ERROR             | FS_NO_ERROR              | FS_NO_ERROR         |
* |-------------------------------------------------------------------------------------------------|
* | USB    | Removed     | FS_MSDC_NOT_PRESENT     | FS_DEVICE_EXPORTED_ERROR | FS_MSDC_MOUNT_ERROR |
* |        | Inserted    | FS_NO_ERROR             | FS_DEVICE_EXPORTED_ERROR | FS_MSDC_MOUNT_ERROR |
* ---------------------------------------------------------------------------------------------------
*****************************************************************************/
static media_error_t _MPLVR_CheckMinFreeSpace(kal_wchar *pwszWorkingPath)
{
    kal_uint64 u8FreeSpace;
    kal_wchar drive[] = L" :\\";
    FS_DiskInfo disc_info;
    media_error_t eMediaError = MED_S_OK;
    kal_int32 i4FsResult;

    drive[0] = pwszWorkingPath[0];
    i4FsResult = FS_GetDevStatus((kal_uint32)(drive[0]), FS_MOUNT_STATE_ENUM);
    if (i4FsResult != FS_NO_ERROR)  /* (i4FsResult == FS_MSDC_MOUNT_ERROR) */
    {
        i4FsResult = FS_GetDevStatus((kal_uint32)(drive[0]), FS_EXPORT_STATE_ENUM);
        if (i4FsResult != FS_NO_ERROR)  /* (i4FsResult == FS_DEVICE_EXPORTED_ERROR) */
        {
            return MED_E_MASS_STORAGE_MODE;
        }
        else
        {
            return MED_E_NO_DISC;
        }
    }

    i4FsResult = FS_GetDiskInfo(drive, &disc_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
    if (i4FsResult < 0)
    {
        return MED_E_FS_ERROR;
    }

    u8FreeSpace = (kal_uint64)disc_info.FreeClusters * disc_info.BytesPerSector
        * disc_info.SectorsPerCluster;

    // When this function is called, _rMplvrMgr.u4FrameWidth and
    // _rMplvrMgr.u4FrameHeight have already beeen set (in MPL Open).
    _rMplvrMgr.u4MinFreeSpace =
        MuxerGetMinSpaceToRecord(_rMplvrMgr.eMuxerContainerType,
        _rMplvrMgr.u4FrameWidth, _rMplvrMgr.u4FrameHeight);

    if (u8FreeSpace < _rMplvrMgr.u4MinFreeSpace)
    {
        eMediaError = MED_E_SIZE_LIMIT_LESS_THAN_MIN_SIZE;
    }

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_FREE_SPACE,
        (kal_uint32)(u8FreeSpace >> 32), (kal_uint32)u8FreeSpace,
        _rMplvrMgr.u4MinFreeSpace);

    return eMediaError;
}


/*****************************************************************************
*
*****************************************************************************/
static media_error_t _MPLVR_AllocMemFromClient(kal_uint32 u4Size,
        med_mem_type_enum eMemType, void **ppvMem)
{
    mpl_recorder_client_t * const prClient = _rMplvrMgr.prClient;
    media_error_t eMediaError = MED_S_OK ;

    _MPLVR_ASSERT_IF_EQUAL(prClient, NULL);

    *ppvMem = prClient->mpl_mem_alloc_func_t(prClient, u4Size, eMemType,
        MPLVR_FILE_NAME_ALIAS, __LINE__);
    if (*ppvMem == NULL)
    {
        kal_trace(TRACE_GROUP_10, MPLVR_TRC_FAIL_TO_ALLOC_MEMORY);
        eMediaError = MED_E_MEM_INSUFFICIENT;
    }
    else
    {
        kal_trace(TRACE_GROUP_10, MPLVR_TRC_ALLOCATE_MEMORY_FROM_CLIENT,
            (kal_uint32)eMemType, (kal_uint32)*ppvMem, u4Size);
    }

    return eMediaError;
}


/*****************************************************************************
*
*****************************************************************************/
static void _MPLVR_FreeMemToClient(void **ppvMem, med_mem_type_enum eMemType)
{
    mpl_recorder_client_t * const prClient = _rMplvrMgr.prClient;

    _MPLVR_ASSERT_IF_EQUAL(prClient, NULL);

    prClient->mpl_mem_free_func_t(prClient, ppvMem, eMemType,
        MPLVR_FILE_NAME_ALIAS, __LINE__);

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_RELEASE_MEMORY_TO_CLIENT,
        (kal_uint32)eMemType, (kal_uint32)*ppvMem);
}


/*****************************************************************************
* Context:
*****************************************************************************/
static void _MPLVR_SetParameterToComponent(VIDEO_COMPONENT_TYPE_T *prComponentHandle,
        VIDEO_PARAM_TYPE_T eParamType, void *pvParam)
{
    PFN_SET_PARAMETER_T const pfnSetParameter = prComponentHandle->pfnSetParameter;
    VIDEO_ERROR_TYPE_T eVideoError;

    MPLVR_TRACE(TRACE_GROUP_10, MPLVR_TRC_SYS_SET_PARAMETER, eParamType,
        (kal_uint32)prComponentHandle);

    eVideoError = pfnSetParameter(eParamType, pvParam);
    _MPLVR_ASSERT_IF_NOT_EQUAL(eVideoError, VIDEO_ERROR_NONE);
}


/*****************************************************************************
* Context:
*****************************************************************************/
static void _MPLVR_GetParameterFromComponent(VIDEO_COMPONENT_TYPE_T *prComponentHandle,
        VIDEO_PARAM_TYPE_T eParamType, void *pvParam)
{
    PFN_SET_PARAMETER_T const pfnGetParameter = prComponentHandle->pfnGetParameter;
    VIDEO_ERROR_TYPE_T eVideoError;

    eVideoError = pfnGetParameter(eParamType, pvParam);
    _MPLVR_ASSERT_IF_NOT_EQUAL(eVideoError, VIDEO_ERROR_NONE);

    MPLVR_TRACE(TRACE_GROUP_10, MPLVR_TRC_SYS_GET_PARAMETER, eParamType,
        (kal_uint32)prComponentHandle);
}


/*****************************************************************************
* Context:
*****************************************************************************/
static void _MPLVR_FRT_Initialize(mpl_recorder_user_enum_t eMplUser)
{
    CUSTOM_VENC_ERROR_T eCustomError;
    CUSTOM_VENC_USER_T eCustomUser;

    switch (_rMplvrMgr.eMuxerContainerType)
    {
    case MUXER_CONTAINER_MP4:
        switch (eMplUser)
        {
        case MPL_RECORDER_USER_RECORDER:
            eCustomUser = CUSTOM_VENC_USER_REC_MPEG4;
            break;

        case MPL_RECORDER_USER_RECORDER_H264:
            eCustomUser = CUSTOM_VENC_USER_REC_H264;
            break;

        case MPL_RECORDER_USER_MATV_PAL:
            eCustomUser = CUSTOM_VENC_USER_MATV_MPEG4_PAL;
            break;

        case MPL_RECORDER_USER_MATV_NTSC:
            eCustomUser = CUSTOM_VENC_USER_MATV_MPEG4_NTSC;
            break;

        default:
            _MPLVR_ASSERT(0);
            break;
        }
        break;

    case MUXER_CONTAINER_AVI:
        switch (eMplUser)
        {
        case MPL_RECORDER_USER_RECORDER:
            eCustomUser = CUSTOM_VENC_USER_REC_MJPEG;
            break;

        case MPL_RECORDER_USER_MATV_PAL:
            eCustomUser = CUSTOM_VENC_USER_MATV_MJPEG_PAL;
            break;

        case MPL_RECORDER_USER_MATV_NTSC:
            eCustomUser = CUSTOM_VENC_USER_MATV_MJPEG_NTSC;
            break;

        default:
            _MPLVR_ASSERT(0);
            break;
        }
        break;
#ifdef __VE_STREAM_SERVER_SUPPORT__
        case MUXER_CONTAINER_RTP:
        switch (eMplUser)
        {
            case MPL_RECORDER_USER_RECORDER:
                eCustomUser = CUSTOM_VENC_USER_REC_MPEG4;
                break;

            case MPL_RECORDER_USER_RECORDER_H264:
                eCustomUser = CUSTOM_VENC_USER_REC_H264;
                break;
            default:
                _MPLVR_ASSERT(0);
                break;
        }
        break;
#endif

    default:
        _MPLVR_ASSERT(0);
        break;
    }

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_FRT_SET_USER, (kal_uint32)eCustomUser);

    eCustomError = CustomVenc_Ctrl(CUSTOM_VENC_OP_SET_USER, &eCustomUser,
        sizeof(eCustomUser), NULL, 0);
    if (eCustomError != CUSTOM_VENC_ERROR_NONE)
    {
        ASSERT(0);
    }
}


/*****************************************************************************
* Context:
*****************************************************************************/
static void _MPLVR_FRT_SetResolution(kal_uint32 u4Width, kal_uint32 u4Height)
{
    CUSTOM_VENC_ERROR_T eCustomError;

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_FRT_SET_RESOLUTION, u4Width, u4Height);

    eCustomError = CustomVenc_Ctrl(CUSTOM_VENC_OP_SET_WIDTH, &u4Width,
        sizeof(u4Width), NULL, 0);
    if (eCustomError != CUSTOM_VENC_ERROR_NONE)
    {
        ASSERT(0);
    }

    eCustomError = CustomVenc_Ctrl(CUSTOM_VENC_OP_SET_HEIGHT, &u4Height,
        sizeof(u4Height), NULL, 0);
    if (eCustomError != CUSTOM_VENC_ERROR_NONE)
    {
        ASSERT(0);
    }
}


/*****************************************************************************
*
* Context:
*
* Side effect: *peEncoderQuality
*****************************************************************************/
static void _MPLVR_FRT_SetQuality(mpl_recorder_quality_enum_t eMplQuality,
        VIDEO_ENCODER_QUALITY_T *peEncoderQuality)
{
    CUSTOM_VENC_QUALITY_T eCustomQuality;
    CUSTOM_VENC_ERROR_T eCustomError;

    switch (eMplQuality)
    {
    case MPL_RECORDER_QUALITY_FINE:
        eCustomQuality = CUSTOM_VENC_QUALITY_FINE;
        *peEncoderQuality = VIDEO_ENCODER_QUALITY_FINE;
        break;

    case MPL_RECORDER_QUALITY_HIGH:
        eCustomQuality = CUSTOM_VENC_QUALITY_GOOD;
        *peEncoderQuality = VIDEO_ENCODER_QUALITY_GOOD;
        break;

    case MPL_RECORDER_QUALITY_NORMAL:
        eCustomQuality = CUSTOM_VENC_QUALITY_NORMAL;
        *peEncoderQuality = VIDEO_ENCODER_QUALITY_NORMAL;
        break;

    case MPL_RECORDER_QUALITY_LOW:
        eCustomQuality = CUSTOM_VENC_QUALITY_LOW;
        *peEncoderQuality = VIDEO_ENCODER_QUALITY_LOW;
        break;

    default:
        eCustomQuality = CUSTOM_VENC_QUALITY_NORMAL;
        *peEncoderQuality = VIDEO_ENCODER_QUALITY_NORMAL;
        break;
    }

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_FRT_SET_QUALITY, (kal_uint32)eCustomQuality);

    eCustomError = CustomVenc_Ctrl(CUSTOM_VENC_OP_SET_QUALITY, &eCustomQuality,
        sizeof(eCustomQuality), NULL, 0);
    if (eCustomError != CUSTOM_VENC_ERROR_NONE)
    {
        ASSERT(0);
    }
}


/*****************************************************************************
* Context:
*****************************************************************************/
static void _MPLVR_FRT_SetStorage(mpl_recorder_storage_enum_t eMplStorage)
{
    CUSTOM_VENC_STORAGE_T eCustomStorage;
    CUSTOM_VENC_ERROR_T eCustomError;

    switch (eMplStorage)
    {
    case MPL_RECORDER_STORAGE_PHONE:
        eCustomStorage = CUSTOM_VENC_STORAGE_PHONE;
        break;

    case MPL_RECORDER_STORAGE_CARD:
        eCustomStorage = CUSTOM_VENC_STORAGE_SD;
        break;

    default:
        break;
    }

    MPLVR_TRACE(TRACE_GROUP_10, MPLVR_TRC_FRT_SET_STORAGE, (kal_uint32)eCustomStorage);

    eCustomError = CustomVenc_Ctrl(CUSTOM_VENC_OP_SET_STORAGE, &eCustomStorage,
        sizeof(eCustomStorage), NULL, 0);
    if (eCustomError != CUSTOM_VENC_ERROR_NONE)
    {
        ASSERT(0);
    }
}


/*****************************************************************************
*
* Context:
*
* Side effect: *peEncoderType
*****************************************************************************/
static void _MPLVR_FRT_SetCodecType(mpl_recorder_format_enum_t eMplFormat,
        VIDEO_ENCODER_TYPE_T *peEncoderType)
{
    CUSTOM_VENC_CODEC_T eCustomCodec;
    CUSTOM_VENC_ERROR_T eCustomError;

    switch (eMplFormat)
    {
    case MPL_RECORDER_FORMAT_MPEG4:
        eCustomCodec = CUSTOM_VENC_CODEC_MPEG4;
        *peEncoderType = VIDEO_ENCODER_MPEG4;
        break;

    case MPL_RECORDER_FORMAT_H263:
        eCustomCodec = CUSTOM_VENC_CODEC_H263;
        *peEncoderType = VIDEO_ENCODER_H263;
        break;

#if defined(__VE_H264_ENC_SW_SUPPORT__)
    case MPL_RECORDER_FORMAT_H264:
        eCustomCodec = CUSTOM_VENC_CODEC_H264;
        *peEncoderType = VIDEO_ENCODER_H264;
        break;
#endif  // defined(__VE_H264_ENC_SW_SUPPORT__)

#if defined(__VE_AVI_ENC_SUPPORT__)
    case MPL_RECORDER_FORMAT_MJPEG:
        eCustomCodec = CUSTOM_VENC_CODEC_MJPEG;
        if (_rMplvrMgr.fgDirectCoupledSensor == KAL_TRUE)
        {
            *peEncoderType = VIDEO_ENCODER_MJPEG_DIRECT_COUPLE;
        }
        else
        {
            *peEncoderType = VIDEO_ENCODER_MJPEG;
        }
        break;
#endif  // defined(__VE_AVI_ENC_SUPPORT__)

    default:
        _MPLVR_ASSERT(0);
        break;
    }

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_FRT_SET_CODEC, (kal_uint32)eCustomCodec,
        (kal_uint32)*peEncoderType);

    eCustomError = CustomVenc_Ctrl(CUSTOM_VENC_OP_SET_CODEC, &eCustomCodec,
        sizeof(eCustomCodec), NULL, 0);
    if (eCustomError != CUSTOM_VENC_ERROR_NONE)
    {
        ASSERT(0);
    }
}


/*****************************************************************************
* Context:
*****************************************************************************/
static void _MPLVR_FRT_SetSoftwareRotator(mpl_recorder_rotation_t eMplSoftwareRotator)
{
    CUSTOM_VENC_ROTATE_T eCustomSoftwareRotator;
    CUSTOM_VENC_ERROR_T eCustomError;

    switch (eMplSoftwareRotator)
    {
    case MPL_RECORDER_SOFTWARE_ROTATOR_DISABLED:
        eCustomSoftwareRotator = CUSTOM_VENC_ROTATE_NONE;
        break;

    case MPL_RECORDER_SOFTWARE_ROTATOR_ENABLED:
        eCustomSoftwareRotator = CUSTOM_VENC_ROTATE_ENABLE;
        break;

    default:
        break;
    }

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_FRT_SET_SOFTWARE_ROTATOR, (kal_uint32)eCustomSoftwareRotator);

    eCustomError = CustomVenc_Ctrl(CUSTOM_VENC_OP_SET_ROTATE, &eCustomSoftwareRotator,
        sizeof(eCustomSoftwareRotator), NULL, 0);
    if (eCustomError != CUSTOM_VENC_ERROR_NONE)
    {
        // Do not assert because not every frame rate table implementation has
        // the entry for software rotator.
        // kal_trace(TRACE_GROUP_10, MPLVR_SET_SOFTWARE_ROTATOR, (kal_uint32)eCustomError);
    }
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
static void _MPLVR_FRT_GetEncoderFrameRate(kal_uint32 *pu4EncoderFrameRate)
{
    CUSTOM_VENC_ERROR_T eCustomError;

    eCustomError = CustomVenc_Ctrl(CUSTOM_VENC_OP_GET_ENCODER_FRAME_RATE, NULL, 0,
        pu4EncoderFrameRate, sizeof(*pu4EncoderFrameRate));
    switch (eCustomError)
    {
    case CUSTOM_VENC_ERROR_USE_DEFAULT:
    case CUSTOM_VENC_ERROR_NONE:
        break;

    default:
        _MPLVR_ASSERT(0);
        break;
    }

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_FRT_GET_FRAME_RATE, *pu4EncoderFrameRate, eCustomError);
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
static void _MPLVR_FRT_GetEncoderBitRate(kal_uint32 *pu4EncoderBitRate)
{
    CUSTOM_VENC_ERROR_T eCustomError;

    eCustomError = CustomVenc_Ctrl(CUSTOM_VENC_OP_GET_BIT_RATE, NULL, 0,
        pu4EncoderBitRate, sizeof(*pu4EncoderBitRate));
    switch (eCustomError)
    {
    case CUSTOM_VENC_ERROR_USE_DEFAULT:
    case CUSTOM_VENC_ERROR_NONE:
        break;

    default:
        _MPLVR_ASSERT(0);
        break;
    }

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_FRT_GET_BIT_RATE, *pu4EncoderBitRate, eCustomError);
}


/*****************************************************************************
* Disable A/V sync interrupt and allows system to sleep.
*
* Context:
*****************************************************************************/
static void _MPLVR_EnableSleep(void)
{
    Media_A2V_EnableInterrupt(KAL_FALSE, 0);
    Media_A2V_DisableDspSleep(KAL_FALSE);  // Audio DSP and MCU in MT6250 sleep separately.
    visual_enable_sleep();
    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_SLEEP_ENABLED);
}


/*****************************************************************************
* Enable A/V sync interrupt, and disallow system to sleep.
*
* Context:
*****************************************************************************/
static void _MPLVR_DisableSleep(void)
{
    visual_disable_sleep();
    Media_A2V_DisableDspSleep(KAL_TRUE);  // Audio DSP and MCU in MT6250 sleep separately.
    Media_A2V_HookInterrupt(NULL);
    Media_A2V_SetTimeStamp(0x3FFF);
    Media_A2V_EnableInterrupt(KAL_TRUE, 0);
    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_SLEEP_DISABLED);
}


/*****************************************************************************
*
*****************************************************************************/
static void _MPLVR_MakeAsyncCall(PFN_MPLVR_REDIRECTION_T pfnProc, kal_uint32 u4Param1,
        kal_uint32 u4Param2, module_type dest)
{
    MPLVR_ASYNC_CALL_T  *prMsg = NULL;
    ilm_struct *prIlm = NULL;
    module_type src;

    prMsg = (MPLVR_ASYNC_CALL_T*)construct_local_para(sizeof(*prMsg), TD_CTRL);
    prMsg->pfnRedirect = pfnProc;
    prMsg->u4Param1 = u4Param1;
    prMsg->u4Param2 = u4Param2;

    /* Get source module ID */
    src = kal_get_active_module_id();

    prIlm = allocate_ilm(src);

    switch (dest)
    {
    case MOD_MED:
        prIlm->sap_id = MED_SAP;
        break;
/*
#ifndef MED_V_NOT_PRESENT
    case MOD_MED_V:
        prIlm->sap_id = MED_V_SAP;
        break;
#endif  // MED_V_NOT_PRESENT
*/

    default:
        ASSERT(0);
        break;
    }

    prIlm->src_mod_id = src;
    prIlm->dest_mod_id = dest;

    switch (_rMplvrMgr.eMuxerContainerType)
    {
    case MUXER_CONTAINER_MP4:
        prIlm->msg_id = (msg_type)MSG_ID_MEDIA_MP4_RECORDER_ASYNC_CALLBACK_REQ;
        break;

    case MUXER_CONTAINER_AVI:
        prIlm->msg_id = (msg_type)MSG_ID_MEDIA_AVI_RECORDER_ASYNC_CALLBACK_REQ;
        break;

#ifdef __VE_STREAM_SERVER_SUPPORT__
    case MUXER_CONTAINER_RTP:
        prIlm->msg_id = (msg_type)MSG_ID_MEDIA_RTP_RECORDER_ASYNC_CALLBACK_REQ;
        break;
#endif
    default:
        _MPLVR_ASSERT(0);
        break;
    }

    prIlm->local_para_ptr = (local_para_struct*)prMsg;
    prIlm->peer_buff_ptr = NULL;

    msg_send_ext_queue(prIlm);
}


/*****************************************************************************
*
*****************************************************************************/
static void _MPLVR_AsyncCallDispatcher(ilm_struct *prIlm)
{
    MPLVR_ASYNC_CALL_T *req_p = (MPLVR_ASYNC_CALL_T*)prIlm->local_para_ptr;

    req_p->pfnRedirect(req_p->u4Param1, req_p->u4Param2);
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_StopAndNotify(mpl_recorder_event_enum_t eEvent,
        media_error_t eMediaError)
{
    kal_bool fgReportError = KAL_FALSE;

    MPLVR_TRACE(TRACE_GROUP_10, MPLVR_TRC_SYS_CALLBACK_ON_ERROR, eMediaError);

    if (_rMplvrMgr.fgSynchronousCall)
    {
        _rMplvrMgr.eSynchronousMediaError = eMediaError;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // 0
        return;
    }

    switch (eEvent)
    {
    case MPL_RECORDER_EVENT_SAVE:
        if (_rMplvrMgr.fgErrorOfSaveCommandReported == KAL_FALSE)
        {
            _rMplvrMgr.fgErrorOfSaveCommandReported = KAL_TRUE;
            fgReportError = KAL_TRUE;
        }
        break;

    case MPL_RECORDER_EVENT_GENERAL:
        if (_rMplvrMgr.fgGeneralErrorReported == KAL_FALSE)
        {
            _rMplvrMgr.fgGeneralErrorReported = KAL_TRUE;
            fgReportError = KAL_TRUE;
        }
        break;

    default:
        _MPLVR_ASSERT(0);
        break;
    }

    if (fgReportError == KAL_TRUE)
    {
        _MPLVR_MakeAsyncCall(_MPLVR_StopAndNotifyOnError, eEvent,
            eMediaError, MOD_MED);
    }
}


/******************************************************************************
* The first and second arguments are the handles to the front-end and back-end
* components respectively.
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_SetupTunnel(VIDEO_COMPONENT_TYPE_T *prFrontEndHandle,
        VIDEO_COMPONENT_TYPE_T *prBackEndHandle)
{
    const VIDEO_PORT_TYPE_T ePortType = VIDEO_PORT_VIDEO_DATA;
    VIDEO_ERROR_TYPE_T eVideoError;

    eVideoError = VideoSetupTunnel(prFrontEndHandle, prBackEndHandle, ePortType);
    if (eVideoError != VIDEO_ERROR_NONE)
    {
        ASSERT(0);
    }
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_VIDEO_ChangeState(VIDEO_COMPONENT_TYPE_T *prComponentHandle,
        VIDEO_STATE_TYPE_T eState)
{
    PFN_SEND_COMMAND_T pfnSendCommand;
    VIDEO_ERROR_TYPE_T eVideoError;

    pfnSendCommand = prComponentHandle->pfnSendCommand;
    eVideoError = pfnSendCommand(VIDEO_COMMAND_STATESET, eState);
    _MPLVR_ASSERT_IF_NOT_EQUAL(eVideoError, VIDEO_ERROR_NONE);
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_VIDEO_WaitForStateChange(VIDEO_COMPONENT_TYPE_T *prComponentHandle,
        VIDEO_STATE_TYPE_T eState, kal_uint32 u4RequestedEvents,
        kal_uint32 u4MaskOfErrorEvent)
{
    kal_uint32 u4EventGroup;

    _MPLVR_VIDEO_ChangeState(prComponentHandle, eState);

    kal_retrieve_eg_events(_rMplvrMgr.eEvent, u4RequestedEvents,
        KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    _MPLVR_ASSERT_IF_NOT_EQUAL((u4EventGroup & u4MaskOfErrorEvent), 0);
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_VIDEO_InitComponentMemory(VIDEO_SCENARIO_T eScenario,
        kal_uint32 u4ExtMemAddr, kal_uint32 u4ExtMemSize)
{
    _rMplvrMgr.prExtMemInfo = VideoInitExtBuffer(u4ExtMemAddr, u4ExtMemSize, eScenario);

    if (eScenario == VIDEO_SCENARIO_ENCODE)
    {
        kal_uint32 u4IntMemAddr = 0, u4IntMemSize = 0;
        _rMplvrMgr.prIntMemInfo = VideoInitIntBuffer(u4IntMemAddr, u4IntMemSize, eScenario);
    }
}

/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_ENCODER_Open(VIDEO_ENCODER_TYPE_T eEncoderType)
{
    PFN_SET_CALLBACK_T pfnSetCallbacks;
    VIDEO_ERROR_TYPE_T eVideoError;

    _rMplvrMgr.prEncoderHandle = GetVideoEncoderHandle(eEncoderType,
        _rMplvrMgr.prExtMemInfo, _rMplvrMgr.prIntMemInfo);
    _MPLVR_ASSERT_IF_EQUAL(_rMplvrMgr.prEncoderHandle, NULL);

    // When a component finishes state change, it will call bcak to notify
    // completion of the change.  Therefore, a call back function must be set
    // before any state change.  A better way is to pass call-back function to
    // the "GetHandle()" function.
    pfnSetCallbacks = _rMplvrMgr.prEncoderHandle->pfnSetCallbacks;
    eVideoError = pfnSetCallbacks((VIDEO_CALLBACK_TYPE_T*)&_MPLVR_ENCODER_CallbackStruct);
    _MPLVR_ASSERT_IF_NOT_EQUAL(eVideoError, VIDEO_ERROR_NONE);
}


/******************************************************************************
* FIXME: Always set rotation angle to 0.
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_ENCODER_SetRotationAngle(void)
{
#if 0
/* under construction !*/
/* under construction !*/
#endif  // 0
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_ENCODER_SetLeftOver(void)
{
    kal_uint32 u4LeftoverOfFirstThreshold =
        MuxerGetLeftOverOfVideoBitstream(_rMplvrMgr.eMuxerContainerType);

    _MPLVR_SetParameterToComponent(_rMplvrMgr.prEncoderHandle,
        VIDEO_PARAM_ENCODER_LEFTOVER_OF_FIRST_THRESHOLD, &u4LeftoverOfFirstThreshold);
}


/******************************************************************************
* This function is used to limit the number of YUV frames in lower resolutions
* than CIF in order to save some RAM for other applications.  The number of YUV
* frames are consistent for all resolutions.
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_ENCODER_SetFrameBufferLimit(void)
{
    kal_bool    fgLimitFrameBuffer = KAL_TRUE;

    _MPLVR_SetParameterToComponent(_rMplvrMgr.prEncoderHandle,
        VIDEO_PARAM_ENCODER_LIMIT_FRM_BUFF, &fgLimitFrameBuffer);
}

/*****************************************************************************
*
* Context:
*****************************************************************************/
static void _MPLVR_ENCODER_SetFrameRate(kal_uint32 u4EncoderFrameRate)
{
    _rMplvrMgr.u4EncoderFrameRate = u4EncoderFrameRate;

    _MPLVR_SetParameterToComponent(_rMplvrMgr.prEncoderHandle,
        VIDEO_PARAM_ENCODER_FRAME_RATE, &u4EncoderFrameRate);
}

#if defined(__VE_TIME_LAPSE_VIDEO_RECORDER__)
/*****************************************************************************
*
* Context:
*****************************************************************************/
static void _MPLVR_ENCODER_SetTimeLapse(kal_uint32 u4TLCaptureDuration, kal_uint32 u4TLFrameRate)
{
    _MPLVR_SetParameterToComponent(_rMplvrMgr.prEncoderHandle,
        VIDEO_PARAM_ENCODER_SET_TIME_LAPSE_CAPTURE_FRAME_DURATION, &u4TLCaptureDuration); // in microsecond

    _MPLVR_SetParameterToComponent(_rMplvrMgr.prEncoderHandle,
        VIDEO_PARAM_ENCODER_SET_TIME_LAPSE_FRAME_RATE, &u4TLFrameRate);
}
#endif

/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static media_error_t _MPLVR_ENCODER_SetResolution(void)
{
    PFN_SET_PARAMETER_T const pfnSetParameter = _rMplvrMgr.prEncoderHandle->pfnSetParameter;
    VENC_RESOLUTION_T rEncoderResolution;
    VIDEO_ERROR_TYPE_T eVideoError;

    rEncoderResolution.u4EncodeWidth = _rMplvrMgr.u4FrameWidth;
    rEncoderResolution.u4EncodeHeight = _rMplvrMgr.u4FrameHeight;
    eVideoError = pfnSetParameter(VIDEO_PARAM_ENCODER_RESOLUTION, &rEncoderResolution);
    if (eVideoError == VIDEO_ERROR_ENCODER_RESOLUTION_ERROR)
    {
        // Width and height have been printed in _MPLVR_FRT_SetResolution().
        // It is not necessary to print them again here.
        kal_trace(TRACE_GROUP_10, MPLVR_TRC_VIDEO_INVALID_RESOLUTION);
        return MED_E_INVALID_RESOLUTION;
    }
    else
    {
        _MPLVR_ASSERT_IF_NOT_EQUAL(eVideoError, VIDEO_ERROR_NONE);
    }

    return MED_S_OK;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static media_error_t _MPLVR_ENCODER_SetProperties(kal_uint32 u4EncoderFrameRate,
        VIDEO_ENCODER_QUALITY_T eEncoderQuality)
{
    media_error_t eMediaError;

    eMediaError = _MPLVR_ENCODER_SetResolution();
    if (eMediaError != MED_S_OK)
    {
        return eMediaError;
    }

    _MPLVR_SetParameterToComponent(_rMplvrMgr.prEncoderHandle,
        VIDEO_PARAM_ENCODER_QUALITY, &eEncoderQuality);

    _MPLVR_ENCODER_SetRotationAngle();
    _MPLVR_ENCODER_SetLeftOver();
    _MPLVR_ENCODER_SetFrameBufferLimit();
    _MPLVR_ENCODER_SetFrameRate(u4EncoderFrameRate);

    return MED_S_OK;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_MUXER_ReleaseHandle(void)
{
    if (_rMplvrMgr.prMuxerHandle != NULL)
    {
        VIDEO_ERROR_TYPE_T eVideoError = VIDEO_ERROR_NONE;
        eVideoError = ReleaseMuxerHandle(_rMplvrMgr.prMuxerHandle);
        _MPLVR_ASSERT_IF_NOT_EQUAL(eVideoError, VIDEO_ERROR_NONE);
        _rMplvrMgr.prMuxerHandle = NULL;
    }
}


/******************************************************************************
* The flag fgSolo means whether Muxer is running by itself.  If it is in solo
* mode, there is no need to setup tunnel and Muxer is opened for file creation.
*
* Context:
*
* Side effect:
******************************************************************************/
static media_error_t _MPLVR_MUXER_SetupMemory(void)
{
    media_error_t eMediaError = MED_S_OK ;
    MUXER_CONTAINER_TYPE_T eMuxerContainerType = _rMplvrMgr.eMuxerContainerType;
    const kal_uint32 u4MuxerMemSize = GetMuxerMemorySize(eMuxerContainerType, MUXER_SCENARIO_CREATE_FILE);
    void *pvMem;

    eMediaError = _MPLVR_AllocMemFromClient(u4MuxerMemSize, MED_MEM_CACHE, &pvMem);
    if (eMediaError != MED_S_OK)
    {
        return eMediaError;
    }

    _rMplvrMgr.pu1MuxerMemAddr = pvMem;
    _rMplvrMgr.u4MuxerMemSize = u4MuxerMemSize;

    _MPLVR_VIDEO_InitComponentMemory(VIDEO_SCENARIO_MERGE_FILE, (kal_uint32)pvMem, u4MuxerMemSize);

    return eMediaError;
}


/*****************************************************************************
* Context:
*****************************************************************************/
static media_error_t _MPLVR_MUXER_ReleaseMemory(void)
{
    void **ppvAddress;

    if (_rMplvrMgr.pu1MuxerMemAddr)
    {
        ppvAddress = (void**)&_rMplvrMgr.pu1MuxerMemAddr;
        _MPLVR_FreeMemToClient(ppvAddress, MED_MEM_CACHE);
        _rMplvrMgr.pu1MuxerMemAddr = NULL;
        _rMplvrMgr.u4MuxerMemSize = 0;
    }

    return MED_S_OK;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_MUXER_Stop(kal_bool fgSolo)
{
    kal_trace(TRACE_GROUP_10, MPLVR_TRC_MUXER_STOP, _rMplvrMgr.eMuxerState);

    switch (_rMplvrMgr.eMuxerState)
    {
    case MPLVR_MUXER_STATE_OPENED:
        /* Do nothing. */
        // FIXME: Change state to STOPPED???
        break;

    case MPLVR_MUXER_STATE_RUNNING:
        _MPLVR_VIDEO_WaitForStateChange(_rMplvrMgr.prMuxerHandle,
            VIDEO_STATE_STOP, MPLVR_EVENT_MUXER_ALL, MPLVR_EVENT_MUXER_ERROR);
        _rMplvrMgr.eMuxerState = MPLVR_MUXER_STATE_STOPPED;
        break;

    case MPLVR_MUXER_STATE_STOPPED:
        break;

    default:
        ASSERT(0);
        break;
    }
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
__inline static void _MPLVR_MUXER_Start(void)
{
    kal_trace(TRACE_GROUP_10, MPLVR_TRC_MUXER_START, _rMplvrMgr.eMuxerState);

    switch (_rMplvrMgr.eMuxerState)
    {
    case MPLVR_MUXER_STATE_OPENED:
    case MPLVR_MUXER_STATE_STOPPED:
        _MPLVR_VIDEO_WaitForStateChange(_rMplvrMgr.prMuxerHandle,
            VIDEO_STATE_RUN, MPLVR_EVENT_MUXER_ALL, MPLVR_EVENT_MUXER_ERROR);
        _rMplvrMgr.eMuxerState = MPLVR_MUXER_STATE_RUNNING;
        break;

    case MPLVR_MUXER_STATE_RUNNING:
        /* When audio is stopped, the remaining audio data needs to be sent to
         * Muxer while Muxer is still in RUNNING state. However, the CR
         * [MAUI_03086101] makes three API synchronous which has the
         * consequence that the remaining audo data is sent to STOPPED Muxer.
         * The solution is to set Muxer to RUNNING when audio is stopped.
         * This may introduce a new path which sets Muxer to RUNNING when it is
         * already in that state.
         */
        break;

    default:
        ASSERT(0);
        break;
    }
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_MUXER_Close(kal_bool fgSolo)
{
    kal_trace(TRACE_GROUP_10, MPLVR_TRC_MUXER_CLOSE, _rMplvrMgr.eMuxerState);

    switch (_rMplvrMgr.eMuxerState)
    {
    case MPLVR_MUXER_STATE_CLOSED:
        /* Do nothing. */
        break;

    case MPLVR_MUXER_STATE_OPENED:
    case MPLVR_MUXER_STATE_STOPPED:
        _MPLVR_VIDEO_WaitForStateChange(_rMplvrMgr.prMuxerHandle,
            VIDEO_STATE_CLOSE, MPLVR_EVENT_MUXER_ALL, MPLVR_EVENT_MUXER_ERROR);
        _MPLVR_MUXER_ReleaseHandle();
        if (fgSolo == KAL_TRUE)
        {
            VideoDeInitExtBuffer(_rMplvrMgr.prExtMemInfo);
            _MPLVR_MUXER_ReleaseMemory();
        }
        _rMplvrMgr.eMuxerState = MPLVR_MUXER_STATE_CLOSED;
        break;

    default:
        ASSERT(0);
        break;
    }
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static VIDEO_ERROR_TYPE_T _MPLVR_AUDIO_FillThisBuffer(VIDEO_BUFFERHEADER_TYPE_T *prBufferHeader)
{
    kal_uint32 u4DataAddr, u4DataSize, u4DataInTwoByte;

    _MPLVR_ASSERT_IF_EQUAL(prBufferHeader, NULL);

    u4DataAddr = (kal_uint32)prBufferHeader->pu1Buffer;
    u4DataSize = prBufferHeader->u4BuffSize;
    kal_trace(TRACE_GROUP_10, MPLVR_TRC_AUDIO_RETURN_BUFFER, u4DataAddr, u4DataSize);

    u4DataInTwoByte = u4DataSize >> 1;
    Media_ReadDataDone(u4DataInTwoByte);

    return VIDEO_ERROR_NONE;
}


/******************************************************************************
*
* Context: MED
*
* Side effect:
******************************************************************************/
static void _MPLVR_MUXER_CloseFileMerge(void)
{
    switch (_rMplvrMgr.eState)
    {
    case MPLVR_STATE_SAVING_FILE:
        _MPLVR_MUXER_Stop(KAL_TRUE);
        _MPLVR_MUXER_Close(KAL_TRUE);
        _MPLVR_DoClose();
        break;

    default:
        break;
    }
}


/******************************************************************************
* FIXME: Use a better name for this function.
*
* Context: MED
*
* Side effect:
******************************************************************************/
static void _MPLVR_MUXER_CloseFileMergeAsync(kal_uint32 u4Param1, kal_uint32 u4Param2)
{
    mpl_recorder_client_t * const prClient = _rMplvrMgr.prClient;
    mpl_recorder_event_enum_t eMplEvent = (mpl_recorder_event_enum_t)u4Param1;
    media_error_t eMediaError = (media_error_t)u4Param2;

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_NOTIFY_UPPER_LAYER,
        eMplEvent, eMediaError);

    _MPLVR_MUXER_CloseFileMerge();
    prClient->on_event_callback((mpl_recorder_client_t*)prClient, eMplEvent, eMediaError);
}


/******************************************************************************
*
* Context: MED
*
* Side effect:
******************************************************************************/
static void _MPLVR_MUXER_AbortFileMergeAsync(kal_uint32 u4Param1, kal_uint32 u4Param2)
{
    mpl_recorder_event_enum_t eMplEvent = (mpl_recorder_event_enum_t)u4Param1;
    media_error_t eMediaError = (media_error_t)u4Param2;

    // Muxer will be stopped in _MPLVR_MUXER_CloseFileMerge(), and at least
    // a log will be printed.  This log can be omitted.
    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_ABORT_FILE_MERGE, eMplEvent, eMediaError);

    _MPLVR_MUXER_CloseFileMerge();
}


/******************************************************************************
*
*
* Context: Muxer
*
* Side effect:
******************************************************************************/
static void _MPLVR_MUXER_CallbackFromAbort(mpl_recorder_event_enum_t eMplEvent,
        media_error_t eMediaError)
{
    // Strickly speaking, the next log belongs to Muxer rather than System.
    // However, it is more useful to know the SYS state than Muxer state.
    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_ABORT_SAVING_CALLBACK,
        _rMplvrMgr.eState, eMediaError);

    _rMplvrMgr.eMediaErrorFromAbortCallback = eMediaError;

    // MED is waiting for events, and it is safe to make asynchronous call
    // before setting an event.
    _MPLVR_MakeAsyncCall(_MPLVR_MUXER_AbortFileMergeAsync, eMplEvent,
        eMediaError, MOD_MED);

    kal_set_eg_events(_rMplvrMgr.eEvent, MPLVR_EVENT_MUXER_ABORT, KAL_OR);
}


/******************************************************************************
* At the creation of a MP4/AVI recorder, _rMplvrMgr (including
* _rMplvrMgr.eMediaErrorFromAbortCallback) was cleared to 0 which is MED_S_OK.
*
* Context: MED
*
* Side effect:
******************************************************************************/
static media_error_t _MPLVR_MUXER_WaitForCallbackFromAbort(void)
{
    kal_uint32 u4EventGroup;
    media_error_t eMediaError;

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_ABORT_MUXER);
    MuxerSetAbortSaving();

    kal_retrieve_eg_events(_rMplvrMgr.eEvent, MPLVR_EVENT_MUXER_ABORT,
        KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
#if 1
    UNUSED(u4EventGroup);
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // 1
    eMediaError = _rMplvrMgr.eMediaErrorFromAbortCallback;

    return eMediaError;
}


/******************************************************************************
* The flag fgSolo means whether Muxer is running by itself.  If it is in solo
* mode, there is no need to setup tunnel and Muxer is opened for file creation.
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_MUXER_Open(kal_bool fgSolo)
{
    MUXER_CONTAINER_TYPE_T eMuxerContainerType = _rMplvrMgr.eMuxerContainerType;
    PFN_SET_CALLBACK_T pfnSetCallbacks;
    VIDEO_ERROR_TYPE_T eVideoError;
    MUXER_SCENARIO_T eMuxerScenario;

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_MUXER_OPEN, _rMplvrMgr.eMuxerState);

    if (_rMplvrMgr.eMuxerState != MPLVR_MUXER_STATE_CLOSED)
    {
        ASSERT(0);
    }

    if (fgSolo == KAL_TRUE)
    {
        media_error_t eMediaError = MED_S_OK ;
        eMediaError = _MPLVR_MUXER_SetupMemory();
        if (eMediaError != MED_S_OK)
        {
            return;
        }
    }

    _rMplvrMgr.prMuxerHandle = GetMuxerHandle(_rMplvrMgr.prExtMemInfo);
    _MPLVR_ASSERT_IF_EQUAL(_rMplvrMgr.prMuxerHandle, NULL);

    // When a component finishes state change, it will call bcak to notify
    // completion of the change.  Therefore, a call back function must be set
    // before any state change.  A better way is to pass call-back function to
    // the "GetHandle()" function.
    pfnSetCallbacks = _rMplvrMgr.prMuxerHandle->pfnSetCallbacks;
    eVideoError = pfnSetCallbacks((VIDEO_CALLBACK_TYPE_T*)&_MPLVR_MUXER_CallbackStruct);
    _MPLVR_ASSERT_IF_NOT_EQUAL(eVideoError, VIDEO_ERROR_NONE);

    _MPLVR_VIDEO_WaitForStateChange(_rMplvrMgr.prMuxerHandle,
        VIDEO_STATE_INIT, MPLVR_EVENT_MUXER_ALL, MPLVR_EVENT_MUXER_ERROR);
    _MPLVR_VIDEO_WaitForStateChange(_rMplvrMgr.prMuxerHandle,
        VIDEO_STATE_IDLE, MPLVR_EVENT_MUXER_ALL, MPLVR_EVENT_MUXER_ERROR);

    if (fgSolo == KAL_TRUE)
    {
        eMuxerScenario = MUXER_SCENARIO_CREATE_FILE;
    }
    else
    {
        eMuxerScenario = MUXER_SCENARIO_RECORD;
        _MPLVR_SetupTunnel(_rMplvrMgr.prEncoderHandle, _rMplvrMgr.prMuxerHandle);
    }

    _MPLVR_SetParameterToComponent(_rMplvrMgr.prMuxerHandle,
        MUXER_SET_CONTAINER_TYPE, (void*)&eMuxerContainerType);
    _MPLVR_SetParameterToComponent(_rMplvrMgr.prMuxerHandle,
        MUXER_SET_SCENARIO, (void*)&eMuxerScenario);

    _rMplvrMgr.eMuxerState = MPLVR_MUXER_STATE_OPENED;
}


/*****************************************************************************
* Context:
*
* Side effect: _rMplvrMgr.fgRecordAudio
*****************************************************************************/
static void _MPLVR_MUXER_SetAudioProperties(kal_bool fgRecordAudio)
{
    MUXER_AUDIO_CONFIG_T rAudioProperties;

    kal_mem_set((void*)&rAudioProperties, 0, sizeof(rAudioProperties));

    if (fgRecordAudio == KAL_TRUE)
    {
        _rMplvrMgr.fgRecordAudio = KAL_TRUE;
        rAudioProperties.fgRecordAudio = KAL_TRUE;
    }
    else
    {
        _rMplvrMgr.fgRecordAudio = KAL_FALSE;
        // rAudioProperties.fgRecordAudio = KAL_FALSE;  // Redundant because of kal_mem_set().
    }
    rAudioProperties.eAudioFormat = _rMplvrMgr.eAudioFormat;
    rAudioProperties.u4AudioFrameSize = _rMplvrMgr.u4AudioFrameSize;
    rAudioProperties.u4AudioFrameDuration = _rMplvrMgr.u4AudioFrameDuration;
    rAudioProperties.u4AudioBitRate = _rMplvrMgr.u4AudioBitRate;
    rAudioProperties.u4AudioSampleRate = _rMplvrMgr.u4AudioSampleRate;
    rAudioProperties.u4AudioChannelNum = _rMplvrMgr.u4AudioChannelNum;
    rAudioProperties.u4AudioBitPerSample = _rMplvrMgr.u4AudioBitPerSample;

    _MPLVR_SetParameterToComponent(_rMplvrMgr.prMuxerHandle,
        MUXER_SET_AUDIO_CONFIG, (void*)&rAudioProperties);
}


/*****************************************************************************
* It is not necessary set "Stop Time" to Muxer any more.
*
* Context:
*****************************************************************************/
static void _MPLVR_MUXER_SetVideoProperties(void)
{
    MUXER_VIDEO_CONFIG_T rVideoProperties;

    kal_mem_set((void*)&rVideoProperties, 0, sizeof(rVideoProperties));
    rVideoProperties.u4VideoFrameRate = _rMplvrMgr.u4EncoderFrameRate;
    rVideoProperties.u4VideoBitRate = _rMplvrMgr.u4EncoderBitRate;

#ifdef __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__
    rVideoProperties.fgHorizontallyMirror = KAL_FALSE;
    switch (_rMplvrMgr.ePlaybackRotationAngle)
    {
    case MPL_RECORDER_ROTATION_ANGLE_CW_0:
        rVideoProperties.eRotateAngle = MUXER_ROTATE_0_CW;
        break;

    case MPL_RECORDER_ROTATION_ANGLE_CW_180:
        rVideoProperties.eRotateAngle = MUXER_ROTATE_180_CW;
        break;

    case MPL_RECORDER_ROTATION_ANGLE_CW_90:
        rVideoProperties.eRotateAngle = MUXER_ROTATE_90_CW;
        break;

    case MPL_RECORDER_ROTATION_ANGLE_CW_270:
        rVideoProperties.eRotateAngle = MUXER_ROTATE_270_CW;
        break;

    case MPL_RECORDER_ROTATION_AND_MIRROR_ANGLE_CW_0:
        rVideoProperties.eRotateAngle = MUXER_ROTATE_0_CW;
        rVideoProperties.fgHorizontallyMirror = KAL_TRUE;
        break;

    case MPL_RECORDER_ROTATION_AND_MIRROR_ANGLE_CW_180:
        rVideoProperties.eRotateAngle = MUXER_ROTATE_180_CW;
        rVideoProperties.fgHorizontallyMirror = KAL_TRUE;
        break;

    case MPL_RECORDER_ROTATION_AND_MIRROR_ANGLE_CW_90:
        rVideoProperties.eRotateAngle = MUXER_ROTATE_90_CW;
        rVideoProperties.fgHorizontallyMirror = KAL_TRUE;
        break;

    case MPL_RECORDER_ROTATION_AND_MIRROR_ANGLE_CW_270:
        rVideoProperties.eRotateAngle = MUXER_ROTATE_270_CW;
        rVideoProperties.fgHorizontallyMirror = KAL_TRUE;
        break;

    default:
        _MPLVR_ASSERT(0);
        break;
    }
#else
    rVideoProperties.fgHorizontallyMirror = KAL_FALSE;
    rVideoProperties.eRotateAngle = MUXER_ROTATE_0_CW;
#endif  // __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__

#if !defined(__VE_SLIM_PROJECT__)
    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_ROTATION,
        rVideoProperties.eRotateAngle, rVideoProperties.fgHorizontallyMirror);
#endif  // !defined(__VE_SLIM_PROJECT__)

    rVideoProperties.u4FrameWidth = _rMplvrMgr.u4FrameWidth;
    rVideoProperties.u4FrameHeight = _rMplvrMgr.u4FrameHeight;
    rVideoProperties.eEncoderType = _rMplvrMgr.eEncoderType;

    _MPLVR_SetParameterToComponent(_rMplvrMgr.prMuxerHandle,
        MUXER_SET_VIDEO_CONFIG, (void*)&rVideoProperties);
}


/*****************************************************************************
* Context:
*****************************************************************************/
static void _MPLVR_MUXER_SetContainerProperties(kal_wchar *pwszWorkingPath,
        kal_uint64 *pu8FileSizeLimit, kal_uint64 *pu8TimeLimit)
{
    kal_uint32 u4TimeLimit;

    _MPLVR_SetParameterToComponent(_rMplvrMgr.prMuxerHandle,
        MUXER_SET_WORKING_PATH, (void*)pwszWorkingPath);

    _MPLVR_SetParameterToComponent(_rMplvrMgr.prMuxerHandle,
        MUXER_SET_SIZE_LIMIT, (void*)pu8FileSizeLimit);

    // Convert time unit from milli-second to micro-second.
    u4TimeLimit = (kal_uint32)(VIDEO_ANYBASE_TO_ANYBASE(*pu8TimeLimit,
        MPLVR_TIME_SCALE_MILLISECOND, MPLVR_TIME_SCALE_MICROSECOND));
    _MPLVR_SetParameterToComponent(_rMplvrMgr.prMuxerHandle,
        MUXER_SET_TIME_LIMIT, (void*)&u4TimeLimit);
}


/*****************************************************************************
*
*****************************************************************************/
static void _MPLVR_MUXER_CreateFinalFile(kal_wchar *pwszWorkingPath,
        kal_wchar *pwszFilePath)
{
    switch (_rMplvrMgr.eMuxerState)
    {
    case MPLVR_MUXER_STATE_CLOSED:
        _MPLVR_MUXER_Open(KAL_TRUE);
        _MPLVR_SetParameterToComponent(_rMplvrMgr.prMuxerHandle,
            MUXER_SET_WORKING_PATH, (void*)pwszWorkingPath);
        _MPLVR_SetParameterToComponent(_rMplvrMgr.prMuxerHandle,
            MUXER_SET_FILE_NAME_PATH, (void*)pwszFilePath);

        _MPLVR_VIDEO_WaitForStateChange(_rMplvrMgr.prMuxerHandle,
            VIDEO_STATE_RUN, MPLVR_EVENT_MUXER_ALL, MPLVR_EVENT_MUXER_ERROR);
        _rMplvrMgr.eMuxerState = MPLVR_MUXER_STATE_RUNNING;
        break;

    default:
        ASSERT(0);
        break;
    }
}



/*****************************************************************************
*
*****************************************************************************/
static void _MPLVR_MUXER_DeleteTemporaryFiles(kal_wchar *pwszWorkingPath)
{
    MuxerDeleteTempFile(_rMplvrMgr.eMuxerContainerType, pwszWorkingPath);
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_MUXER_IsThereUnfinishedFiles(mpl_recorder_is_unsaved_file_param_t *prUnfinished)
{
    prUnfinished->is_unsaved_file =
        MuxerIsTempFileExisted(_rMplvrMgr.eMuxerContainerType, prUnfinished->working_path);
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static _MPLVR_MUXER_GetCurrentFileSize(kal_uint64 *pu8FinalFileSize)
{
    if (_rMplvrMgr.eMuxerState == MPLVR_MUXER_STATE_RUNNING)
    {
        _MPLVR_GetParameterFromComponent(_rMplvrMgr.prMuxerHandle,
            MUXER_GET_CURRENT_FILE_SIZE, (void*)pu8FinalFileSize);
    }
    else
    {
        *pu8FinalFileSize = 0;
    }
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_MUXER_GetReservedDiskSpace(kal_uint32 *pu4ReservedSize)
{
    _rMplvrMgr.u4MinFreeSpace =
        MuxerGetMinSpaceToRecord(_rMplvrMgr.eMuxerContainerType,
        _rMplvrMgr.u4FrameWidth, _rMplvrMgr.u4FrameHeight);

    *pu4ReservedSize = _rMplvrMgr.u4MinFreeSpace;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static VIDEO_ERROR_TYPE_T _MPLVR_SOURCE_EventHandler(VIDEO_EVENT_TYPE_T eEvent,
        kal_uint32 u4Data1, kal_uint32 u4Data2, void *pData)
{
    VIDEO_ERROR_TYPE_T eVideoError = VIDEO_ERROR_NONE;

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SOURCE_EVENT, eEvent, u4Data1, u4Data2, (kal_uint32)pData);

    switch (eEvent)
    {
    case VIDEO_EVENT_COMPLETE:
        _MPLVR_ASSERT_IF_NOT_EQUAL(u4Data1, VIDEO_COMMAND_STATESET);
        _MPLVR_SetEvents(MPLVR_EVENT_SOURCE_COMPLETE);
        break;

    default:
        _MPLVR_ASSERT(0);
        break;
    }

    return eVideoError;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
const static VIDEO_CALLBACK_TYPE_T _MPLVR_SOURCE_CallbackStruct =
{
    _MPLVR_SOURCE_EventHandler, NULL
};


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_SOURCE_Open(void)
{
    PFN_SET_CALLBACK_T pfnSetCallbacks;
    VIDEO_ERROR_TYPE_T eVideoError;

    if (_rMplvrMgr.fgDirectCoupledSensor == KAL_FALSE)
    {
        _rMplvrMgr.prSourceHandle = GetVideoRecorderSourceHandle(VIDEO_RECORDER_SOURCE_COMM, _rMplvrMgr.prExtMemInfo);
        _MPLVR_ASSERT_IF_EQUAL(_rMplvrMgr.prSourceHandle, NULL);

        // When a component finishes state change, it will call bcak to notify
        // completion of the change.  Therefore, a call back function must be set
        // before any state change.  A better way is to pass call-back function to
        // the "GetHandle()" function.
        pfnSetCallbacks = _rMplvrMgr.prSourceHandle->pfnSetCallbacks;
        eVideoError = pfnSetCallbacks((VIDEO_CALLBACK_TYPE_T*)&_MPLVR_SOURCE_CallbackStruct);
        _MPLVR_ASSERT_IF_NOT_EQUAL(eVideoError, VIDEO_ERROR_NONE);
    }
}


/*****************************************************************************
* This is for configuring Clock utilities.
*****************************************************************************/
static media_error_t _MPLVR_VRCLK_SetAudioFormat(Media_Format eAudioFormat)
{
    kal_bool fgUseAudioClock = KAL_TRUE;

    VRCLK_SetClockProperties(fgUseAudioClock, eAudioFormat);

    return MED_S_OK;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_VIDEO_WaitForEvent(kal_uint32 u4RequestedEvents,
        kal_uint32 u4MaskOfErrorEvent)
{
    kal_uint32 u4EventGroup;

    kal_retrieve_eg_events(_rMplvrMgr.eEvent, u4RequestedEvents,
        KAL_OR_CONSUME, &u4EventGroup, KAL_SUSPEND);
    _MPLVR_ASSERT_IF_NOT_EQUAL((u4EventGroup & u4MaskOfErrorEvent), 0);
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_VIDEO_ReleaseSourceHandle(void)
{
    if ((_rMplvrMgr.prSourceHandle != NULL) &&
        (_rMplvrMgr.fgDirectCoupledSensor == KAL_FALSE))
    {
        VIDEO_ERROR_TYPE_T eVideoError = VIDEO_ERROR_NONE;
        eVideoError = ReleaseVideoRecorderSourceHandle(_rMplvrMgr.prSourceHandle);
        _MPLVR_ASSERT_IF_NOT_EQUAL(eVideoError, VIDEO_ERROR_NONE);
        _rMplvrMgr.prSourceHandle = NULL;
    }
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_VIDEO_ReleaseEncoderHandle(void)
{
    VIDEO_COMPONENT_TYPE_T *prComponentHandle = _rMplvrMgr.prEncoderHandle;

    if (prComponentHandle != NULL)
    {
        VIDEO_ERROR_TYPE_T eVideoError = VIDEO_ERROR_NONE;

        eVideoError = ReleaseVideoEncoderHandle(prComponentHandle);
        _MPLVR_ASSERT_IF_NOT_EQUAL(eVideoError, VIDEO_ERROR_NONE);
        _rMplvrMgr.prEncoderHandle = NULL;
    }
}


/*****************************************************************************
* Convert time unit from microsecond to millisecond.
* Return time value in millisecond.
*
*****************************************************************************/
static media_error_t _MPLVR_VIDEO_GetRecordingTime(kal_uint64 *pu8VideoTime)
{
    VRCLK_GetCurrentTime(pu8VideoTime);

    *pu8VideoTime = VIDEO_ANYBASE_TO_ANYBASE(*pu8VideoTime,
        MPLVR_TIME_SCALE_MICROSECOND, MPLVR_TIME_SCALE_MILLISECOND);

    return MED_S_OK;
}


/******************************************************************************
* Allocate memory for video components.
*
* Context:
*
* Side effect:
******************************************************************************/
static media_error_t _MPLVR_VIDEO_SetupMemory(VIDEO_ENCODER_TYPE_T eEncoderType,
        kal_uint32 u4FrameWidth, kal_uint32 u4FrameHeight)
{
    media_error_t eMediaError = MED_S_OK ;
    kal_uint32  u4ExtMemSize = 0;
    void *pvMem;

    // Because _MPLVR_AllocMemFromClient() will always print a message, it is
    // not necessary to print a message here.
    MPLVR_TRACE(TRACE_GROUP_10, MPLVR_TRC_VIDEO_SETUP_MEMORY, _rMplvrMgr.eVideoState);

    u4ExtMemSize = GetVideoEncoderExtMemSize(eEncoderType, u4FrameWidth, u4FrameHeight);
    eMediaError = _MPLVR_AllocMemFromClient(u4ExtMemSize, MED_MEM_CACHE, &pvMem);
    if (eMediaError != MED_S_OK)
    {
        return eMediaError;
    }

    _rMplvrMgr.pu1VideoExtMemAddr = (kal_uint8*)pvMem;
    _rMplvrMgr.u4VideoExtMemSize = u4ExtMemSize;

    _MPLVR_VIDEO_InitComponentMemory(VIDEO_SCENARIO_ENCODE, (kal_uint32)pvMem, u4ExtMemSize);

    return eMediaError;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_VIDEO_ReleaseMemory(void)
{
    void **ppvAddress;

    // Because _MPLVR_FreeMemToClient() will always print a message, it is
    // not necessary to print a message here.
    MPLVR_TRACE(TRACE_GROUP_10, MPLVR_TRC_VIDEO_RELEASE_MEMORY, _rMplvrMgr.eVideoState);

    if (_rMplvrMgr.pu1VideoExtMemAddr != NULL)
    {
        ppvAddress = (void**)&_rMplvrMgr.pu1VideoExtMemAddr;
        _MPLVR_FreeMemToClient(ppvAddress, MED_MEM_CACHE);
        _rMplvrMgr.pu1VideoExtMemAddr = NULL;
        _rMplvrMgr.u4VideoExtMemSize = 0;
    }
}


/*****************************************************************************
* Set the global variables realted to video.
* Open video path.  Setup tunnels.
*
* Context:
*****************************************************************************/
static media_error_t _MPLVR_VIDEO_Open(VIDEO_ENCODER_TYPE_T eEncoderType,
        kal_bool fgRecordYuv, VIDEO_ENCODER_QUALITY_T eEncoderQuality,
        kal_uint32 u4EncoderFrameRate, kal_uint32 u4EncoderBitRate,
        kal_uint32 u4FrameWidth, kal_uint32 u4FrameHeight)
{
    media_error_t eMediaError = MED_S_OK ;

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_VIDEO_OPEN, _rMplvrMgr.eVideoState);

    if (_rMplvrMgr.eVideoState != MPLVR_VIDEO_STATE_CLOSED)
    {
        ASSERT(0);
    }

    _rMplvrMgr.eEncoderType = eEncoderType;
    _rMplvrMgr.fgRecordYuv = fgRecordYuv;
    _rMplvrMgr.u4EncoderFrameRate = u4EncoderFrameRate;  // This line can be commented out.
    _rMplvrMgr.u4EncoderBitRate = u4EncoderBitRate;
    _rMplvrMgr.u4FrameHeight = u4FrameHeight;
    _rMplvrMgr.u4FrameWidth = u4FrameWidth;

    eMediaError = _MPLVR_VIDEO_SetupMemory(eEncoderType, u4FrameWidth, u4FrameHeight);
    if (eMediaError != MED_S_OK)
    {
        return eMediaError;
    }

    // Reset clock utility, and set audio format to it.
    VRCLK_ResetAll();
    _MPLVR_VRCLK_SetAudioFormat(_rMplvrMgr.eAudioFormat);

    _MPLVR_SOURCE_Open();
    if (fgRecordYuv)
    {
        _MPLVR_ENCODER_Open(VIDEO_ENCODER_RECORD_YUV);
    }
    else
    {
        _MPLVR_ENCODER_Open(eEncoderType);
    }

    // Set MPL to OPENED state so that whenever there is an error before the end
    // of this function, MPL can release the handles of Source and/or Encoder.
    _rMplvrMgr.eVideoState = MPLVR_VIDEO_STATE_OPENED;

    /************************************************/
    /******* Source <---> Encoder <---> Muxer *******/
    /************************************************/
    if (_rMplvrMgr.fgDirectCoupledSensor == KAL_FALSE)
    {
        _MPLVR_SetupTunnel(_rMplvrMgr.prSourceHandle, _rMplvrMgr.prEncoderHandle);
    }

    eMediaError = _MPLVR_ENCODER_SetProperties(u4EncoderFrameRate, eEncoderQuality);
    if (eMediaError != MED_S_OK)
    {
        return eMediaError;
    }

    // Video path has been opened by now.  The "GetHandle" functions in each
    // module do not implicitly invoke init function automatically.  Thus,
    // it does no harm if handle is not released on error.
    _MPLVR_VIDEO_WaitForStateChange(_rMplvrMgr.prEncoderHandle,
        VIDEO_STATE_INIT, MPLVR_EVENT_ENCODER_ALL, MPLVR_EVENT_ENCODER_ERROR);
    _MPLVR_VIDEO_WaitForStateChange(_rMplvrMgr.prEncoderHandle,
        VIDEO_STATE_IDLE, MPLVR_EVENT_ENCODER_ALL, MPLVR_EVENT_ENCODER_ERROR);

    if (_rMplvrMgr.fgDirectCoupledSensor == KAL_FALSE)
    {
        _MPLVR_VIDEO_WaitForStateChange(_rMplvrMgr.prSourceHandle,
            VIDEO_STATE_INIT, MPLVR_EVENT_SOURCE_ALL, MPLVR_EVENT_SOURCE_ERROR);
        _MPLVR_VIDEO_WaitForStateChange(_rMplvrMgr.prSourceHandle,
            VIDEO_STATE_IDLE, MPLVR_EVENT_SOURCE_ALL, MPLVR_EVENT_SOURCE_ERROR);
    }

    _rMplvrMgr.eVideoState = MPLVR_VIDEO_STATE_IDLE;

    return eMediaError;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_VIDEO_Close(void)
{
    kal_trace(TRACE_GROUP_10, MPLVR_TRC_VIDEO_CLOSE, _rMplvrMgr.eVideoState);

    switch (_rMplvrMgr.eVideoState)
    {
    case MPLVR_VIDEO_STATE_CLOSED:
        /* Do nothing. */
        break;

    case MPLVR_VIDEO_STATE_OPENED:
        _MPLVR_VIDEO_ReleaseSourceHandle();
        _MPLVR_VIDEO_ReleaseEncoderHandle();
         VideoDeInitExtBuffer(_rMplvrMgr.prExtMemInfo);
         VideoDeInitIntBuffer(_rMplvrMgr.prIntMemInfo, VIDEO_SCENARIO_ENCODE);
        _MPLVR_VIDEO_ReleaseMemory();
        _rMplvrMgr.eVideoState = MPLVR_VIDEO_STATE_CLOSED;
        break;

    case MPLVR_VIDEO_STATE_IDLE:
    case MPLVR_VIDEO_STATE_STOPPED:
        if (_rMplvrMgr.fgDirectCoupledSensor == KAL_FALSE)
        {
            _MPLVR_VIDEO_WaitForStateChange(_rMplvrMgr.prSourceHandle,
                VIDEO_STATE_CLOSE, MPLVR_EVENT_SOURCE_ALL, MPLVR_EVENT_SOURCE_ERROR);
        }
        _MPLVR_VIDEO_WaitForStateChange(_rMplvrMgr.prEncoderHandle,
            VIDEO_STATE_CLOSE, MPLVR_EVENT_ENCODER_ALL, MPLVR_EVENT_ENCODER_ERROR);
        _MPLVR_VIDEO_ReleaseSourceHandle();
        _MPLVR_VIDEO_ReleaseEncoderHandle();
         VideoDeInitExtBuffer(_rMplvrMgr.prExtMemInfo);
         VideoDeInitIntBuffer(_rMplvrMgr.prIntMemInfo, VIDEO_SCENARIO_ENCODE);
        _MPLVR_VIDEO_ReleaseMemory();
        _rMplvrMgr.eVideoState = MPLVR_VIDEO_STATE_CLOSED;
        break;

    default:
        ASSERT(0);
        break;
    }
}


/******************************************************************************
* Set all related components to the RUN state, and wait for their completion.
* Finally, set "itself" (the Recorder component) to the RUN state.
*
* Context: xxx
*
* Side effect: xxx
******************************************************************************/
static void _MPLVR_VIDEO_Start(void)
{
    kal_trace(TRACE_GROUP_10, MPLVR_TRC_VIDEO_START, _rMplvrMgr.eVideoState);

    switch (_rMplvrMgr.eVideoState)
    {
    case MPLVR_VIDEO_STATE_IDLE:
    case MPLVR_VIDEO_STATE_STOPPED:
        VRCLK_StartClock();
        _MPLVR_VIDEO_WaitForStateChange(_rMplvrMgr.prEncoderHandle,
            VIDEO_STATE_RUN, MPLVR_EVENT_ENCODER_ALL, MPLVR_EVENT_ENCODER_ERROR);
        if (_rMplvrMgr.fgDirectCoupledSensor == KAL_FALSE)
        {
            _MPLVR_VIDEO_WaitForStateChange(_rMplvrMgr.prSourceHandle,
                VIDEO_STATE_RUN, MPLVR_EVENT_SOURCE_ALL, MPLVR_EVENT_SOURCE_ERROR);
        }
        _rMplvrMgr.eVideoState = MPLVR_VIDEO_STATE_RUNNING;
        break;

    default:
        ASSERT(0);
        break;
    }
}


/******************************************************************************
* Set "itself" (the Recorder component) to the STOP state first.  Then, set
* all related components to the STOP state, and does not wait for their
* completion.
*
* Context: xxx
*
* Side effect: xxx
******************************************************************************/
static void _MPLVR_VIDEO_SendStopCommand(void)
{
    kal_trace(TRACE_GROUP_10, MPLVR_TRC_VIDEO_SEND_STOP_COMMAND, _rMplvrMgr.eVideoState);

    switch (_rMplvrMgr.eVideoState)
    {
    case MPLVR_VIDEO_STATE_CLOSED:
    case MPLVR_VIDEO_STATE_IDLE:
    case MPLVR_VIDEO_STATE_STOPPED:
        break;

    case MPLVR_VIDEO_STATE_RUNNING:
        if (_rMplvrMgr.fgDirectCoupledSensor == KAL_FALSE)
        {
            _MPLVR_VIDEO_ChangeState(_rMplvrMgr.prSourceHandle, VIDEO_STATE_STOP);
        }
        VRCLK_StopClock();
        _MPLVR_VIDEO_ChangeState(_rMplvrMgr.prEncoderHandle, VIDEO_STATE_STOP);
        break;

    default:
        ASSERT(0);
        break;
    }
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static media_error_t _MPLVR_VIDEO_WaitUntilStopped(void)
{
    kal_trace(TRACE_GROUP_10, MPLVR_TRC_VIDEO_WAIT_UNTIL_STOPPED, _rMplvrMgr.eVideoState);

    switch (_rMplvrMgr.eVideoState)
    {
    case MPLVR_VIDEO_STATE_CLOSED:
        /* Do nothing. */
        break;

    case MPLVR_VIDEO_STATE_IDLE:
        /* Do nothing. */
        break;

    case MPLVR_VIDEO_STATE_RUNNING:
        if (_rMplvrMgr.fgDirectCoupledSensor == KAL_FALSE)
        {
            _MPLVR_VIDEO_WaitForEvent(MPLVR_EVENT_SOURCE_ALL, MPLVR_EVENT_SOURCE_ERROR);
        }
        _MPLVR_VIDEO_WaitForEvent(MPLVR_EVENT_ENCODER_ALL, MPLVR_EVENT_ENCODER_ERROR);
        _rMplvrMgr.eVideoState = MPLVR_VIDEO_STATE_STOPPED;
        break;

    case MPLVR_VIDEO_STATE_STOPPED:
        /* Do nothing. */
        break;

    default:
        ASSERT(0);
        break;
    }

    return MED_S_OK;
}


/*****************************************************************************
* Stop video recording but not audio recording.
*****************************************************************************/
static void _MPLVR_VIDEO_Stop(void)
{
    kal_trace(TRACE_GROUP_10, MPLVR_TRC_VIDEO_STOP, _rMplvrMgr.eVideoState);
    _MPLVR_VIDEO_SendStopCommand();
    _MPLVR_VIDEO_WaitUntilStopped();
}


/*****************************************************************************
* The return value of Media_GetRecordedTime() is in milli-second.
* It is time indicating the length of recorded audio data, and not the audio
* clock.  The granularity of audio data and audio clock are in frame (for AMR)
* and in ms respectively.  Audio clock will always be greater than or equal to
* the time of recorded audio data.
*
* The parameter used in Media_A2V_GetRecInterruptTimeScale() is in consistent
* with that used in the Clock utilities (or Recorder Clock component).
*
* It is important that audio begin to generate data (or event silence) as soon
* as audio clock begins to count.  Otherwise, time stamps may not increase
* monolithicly when users performs "Pause/Resume" operations.
*
* By the way, audio clock shall be better renamed as "recorder clock" to avoid
* confusion.
*****************************************************************************/
static kal_uint32 _MPLVR_AUDIO_GetTimeStampFromData(kal_uint32 *pu4AccuAudioDataTime)
{
    kal_uint64 u8CurrentTime = 0;
    kal_uint32 u4TimeStamp = 0, u4AudioTimeScale = 0;

    u4TimeStamp = Media_GetRecordedTime();
    if (*pu4AccuAudioDataTime + u4TimeStamp < *pu4AccuAudioDataTime)
    {
        ASSERT(0);
    }
    // There is no need to accumulated audio data time if Media_Pause() is used.
    // *pu4AccuAudioDataTime += u4TimeStamp;
    // u4TimeStamp = *pu4AccuAudioDataTime;
    *pu4AccuAudioDataTime = u4TimeStamp;

    // The next two statements are mainly for debugging purpose.
    _MPLVR_VIDEO_GetRecordingTime(&u8CurrentTime);

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_PRINT_TIME_INFO, u4TimeStamp,
        (kal_uint32)u8CurrentTime);

    // Convert acculumated time of audio data from millisecond to time scale 8000.
    u4AudioTimeScale = Media_A2V_GetRecInterruptTimeScale(MEDIA_FORMAT_AMR,
        MPLVR_AUDIO_SAMPLING_RATE_8000);
    u4TimeStamp = (kal_uint32)VIDEO_ANYBASE_TO_ANYBASE(u4TimeStamp,
        MPLVR_TIME_SCALE_MILLISECOND, u4AudioTimeScale);

    return u4TimeStamp;
}


/*****************************************************************************
* Context:
*****************************************************************************/
static void _MPLVR_AUDIO_GetReadBuffer(kal_uint8 **ppu1AddrToSend,
        kal_uint32 *pu4SizeToSend)
{
    kal_uint16 *pu2AddrToSend;
    kal_uint32 u4SizeToSendInTwoByte;

    Media_GetReadBuffer(&pu2AddrToSend, &u4SizeToSendInTwoByte);

    *ppu1AddrToSend = (kal_uint8*)pu2AddrToSend;
    *pu4SizeToSend = u4SizeToSendInTwoByte << 1;

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_AUDIO_QUERIED_DATA,
        (kal_uint32)_rMplvrMgr.eAudioState, (kal_uint32)*ppu1AddrToSend,
        *pu4SizeToSend);
}


/*****************************************************************************
* Context:
*****************************************************************************/
static void _MPLVR_AUDIO_DoSendDataToMuxer(kal_uint8 *pu1AddrToSend,
        kal_uint32 u4SizeToSend)
{
    VIDEO_ERROR_TYPE_T eVideoError;

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_AUDIO_SEND_TO_MUXER,
        (kal_uint32)pu1AddrToSend, u4SizeToSend);

    eVideoError = FillMuxerAudioBuffer(pu1AddrToSend, u4SizeToSend);
    if (eVideoError != VIDEO_ERROR_NONE)
    {
        ASSERT(0);
    }

    _rMplvrMgr.pu1LastAudioAddr = pu1AddrToSend;
    _rMplvrMgr.u4LastAudioSize = u4SizeToSend;
}


/*****************************************************************************
* Context:
*****************************************************************************/
static void _MPLVR_AUDIO_SendDataToMuxer(void)
{
    kal_uint8 * const pu1LastAudioAddr = _rMplvrMgr.pu1LastAudioAddr;
    kal_uint8 * const pu1BufferEnd = _rMplvrMgr.pu1AudioMemAddr + _rMplvrMgr.u4AudioMemSize;
    const kal_uint32 u4Threshold = _rMplvrMgr.u4AudioDataThresholdInTwoByte << 1;
    kal_uint8 *pu1AddrToSend;
    kal_uint32 u4SizeToSend;

    kal_take_mutex(_rMplvrMgr.eMutex);
    _MPLVR_AUDIO_GetReadBuffer(&pu1AddrToSend, &u4SizeToSend);
    if ((u4SizeToSend == 0) || (pu1LastAudioAddr == pu1AddrToSend))
    {
        // This implies that there is no more than one audio chunk in Muxer.
        kal_give_mutex(_rMplvrMgr.eMutex);
        return;
    }

	// Send data as a u4Threshold chunk of data, or when the end of buffer is reached.
    if (u4SizeToSend >= u4Threshold)
    {
        u4SizeToSend = u4Threshold;
    }
    else
    {
        if (pu1AddrToSend + u4SizeToSend == pu1BufferEnd)
        {
            u4SizeToSend = u4SizeToSend;
        }
        else if (pu1AddrToSend + u4SizeToSend < pu1BufferEnd)
        {
            u4SizeToSend = 0;
        }
        else
        {
            ASSERT(0);
        }
    }

    if (u4SizeToSend > 0)
    {
        _MPLVR_AUDIO_DoSendDataToMuxer(pu1AddrToSend, u4SizeToSend);
    }
    kal_give_mutex(_rMplvrMgr.eMutex);
}


/*****************************************************************************
* Context:
*****************************************************************************/
static media_error_t _MPLVR_AUDIO_SetupMemory(kal_uint32 u4AudioBufferSize)
{
    media_error_t eMediaError;
	kal_uint32 u4AudioDataThreshold = u4AudioBufferSize >> 1;  // half the buffer size
    kal_uint32 u4AudioHeaderSize, u4AudioLeftover, u4AudioBufferOffset;
    void *pvMem;
#ifdef __VE_STREAM_SERVER_SUPPORT__
    if (_rMplvrMgr.eMuxerContainerType == MUXER_CONTAINER_RTP)
    {
        if (fgEnableAMR == KAL_TRUE)
        {
            u4AudioDataThreshold = MPLVR_RTP_AMR_THRESHOLD;
        }
        else
        {
            u4AudioDataThreshold = MPLVR_RTP_PCM_THRESHOLD;
        }
    }
#endif

    eMediaError = _MPLVR_AllocMemFromClient(u4AudioBufferSize, MED_MEM_AUD_RINGBUFF, &pvMem);
    if (eMediaError != MED_S_OK)
    {
        return eMediaError;
    }

    u4AudioHeaderSize = MuxerGetHeaderSizeOfAudioFile(_rMplvrMgr.eMuxerContainerType);
    if ((u4AudioHeaderSize >= u4AudioDataThreshold) ||
        (u4AudioHeaderSize % 2 != 0))  // Make sure u4AudioBufferOffset will be 2-byte aligned.
    {
        ASSERT(0);
    }

    u4AudioLeftover = u4AudioDataThreshold - u4AudioHeaderSize;
    u4AudioBufferOffset = u4AudioBufferSize - u4AudioLeftover;

    _rMplvrMgr.pu1AudioMemAddr = pvMem;
    _rMplvrMgr.u4AudioMemSize = u4AudioBufferSize;
    _rMplvrMgr.u4AudioDataThresholdInTwoByte = u4AudioDataThreshold >> 1;

    Media_SetBuffer((kal_uint16*)pvMem, u4AudioBufferSize >> 1);  // The buffer size must be in 16-bit word.

    // Adjust ring buffer offset so that audio data can be written into disk
    // in a more efficient way.
    _rMplvrMgr.u4LastAudioSize = 0;
    _rMplvrMgr.pu1LastAudioAddr = NULL;
    Media_SetRBOffset(u4AudioBufferOffset >> 1);  // The offset must be in 16-bit word.

    Media_SetRBThreshold(u4AudioDataThreshold >> 1);  // The threshold must be in 16-bit word.

    return MED_S_OK;
}


/*****************************************************************************
* Context:
*****************************************************************************/
static media_error_t _MPLVR_AUDIO_ReleaseMemory(void)
{
    void **ppvAddress;

    if (_rMplvrMgr.pu1AudioMemAddr)
    {
        ppvAddress = (void**)&_rMplvrMgr.pu1AudioMemAddr;
        _MPLVR_FreeMemToClient(ppvAddress, MED_MEM_AUD_RINGBUFF);
        _rMplvrMgr.pu1AudioMemAddr = NULL;
        _rMplvrMgr.u4AudioMemSize = 0;
    }

    return MED_S_OK;
}


/*****************************************************************************
* Be careful do not pass the address of any local variable to other function
* which may be invoked asynchronously.
*****************************************************************************/
static void _MPLVR_AUDIO_Callback(Media_Event event)
{
    switch (event)
    {
    case MEDIA_DATA_NOTIFICATION:
        _MPLVR_AUDIO_SendDataToMuxer();
        break;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // 0

    default:
        kal_trace(TRACE_GROUP_10, MPLVR_TRC_AUDIO_CALLBACK_WARNING, event);
        break;
    }
}


/*****************************************************************************
* Set the global variables related to audio, and allocate memory.
*
* FIXME: GetAudioInfo(eAudioFormat, &_rMplvrMgr.u4AudioFrameSize, &_rMplvrMgr.u4AudioBitRate);
*        May need to ask Muxer for buffer (threshold) size.
*
* Context:
*****************************************************************************/
static media_error_t _MPLVR_AUDIO_Open(mpl_recorder_format_enum_t eMplvrFormat)
{
    media_error_t eMediaError = MED_S_OK;
    kal_uint32 u4AudioBufferSize = 0;

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_AUDIO_OPEN, _rMplvrMgr.eAudioState);

    if (_rMplvrMgr.eAudioState != MPLVR_AUDIO_STATE_CLOSED)
    {
        ASSERT(0);
    }

    // Clear the time implied by the amount of audio data.
    _rMplvrMgr.u4AccuAudioDataTime = 0;

    _rMplvrMgr.u4AudioSampleRate = 8000;
    _rMplvrMgr.u4AudioChannelNum = 1;
    _rMplvrMgr.u4AudioBitPerSample = 16;

    switch (eMplvrFormat)
    {
    case MPL_RECORDER_FORMAT_MPEG4:
    case MPL_RECORDER_FORMAT_H263:
    case MPL_RECORDER_FORMAT_H264:
		{

#ifdef __VE_STREAM_SERVER_SUPPORT__
            if (_rMplvrMgr.eMuxerContainerType == MUXER_CONTAINER_RTP)
            {
                if (fgEnableAMR == KAL_TRUE)
                {
                    _rMplvrMgr.eAudioFormat = MEDIA_FORMAT_AMR_TRANSMIT;
                    _rMplvrMgr.u4AudioFrameDuration = 20;   // ms
                    _rMplvrMgr.u4AudioFrameSize = 33;   // bytes
                    _rMplvrMgr.u4AudioBitRate = 12800;
                }
                else
                {
                    _rMplvrMgr.eAudioFormat = MEDIA_FORMAT_G711_ALAW;
                    //_rMplvrMgr.eAudioFormat = MEDIA_FORMAT_G711_ULAW;
                    _rMplvrMgr.u4AudioFrameDuration = 2;    // 1 sample = 0.125ms = 1bytes
                    _rMplvrMgr.u4AudioFrameSize = 16;   // bytes
                    _rMplvrMgr.u4AudioBitRate = 64000;
                }
            }
            else
#endif		
            {
                _rMplvrMgr.eAudioFormat = MEDIA_FORMAT_AMR;
                _rMplvrMgr.u4AudioFrameDuration = 20;
                _rMplvrMgr.u4AudioFrameSize = 32;
                _rMplvrMgr.u4AudioBitRate = 12800;
            }
        }
#ifdef __VE_STREAM_SERVER_SUPPORT__
        if (_rMplvrMgr.eMuxerContainerType == MUXER_CONTAINER_RTP)
        {
            if (fgEnableAMR == KAL_TRUE)
            {
                u4AudioBufferSize = MPLVR_RTP_AMR_BUFFER_SIZE;
            }
            else
            {
                u4AudioBufferSize = MPLVR_RTP_PCM_BUFFER_SIZE;
            }
        }
        else
#endif
        {
            u4AudioBufferSize = MPLVR_MP4_AUDIO_BUFFER_SIZE;
            _MPLVR_ASSERT_IF_NOT_EQUAL(_rMplvrMgr.eMuxerContainerType, MUXER_CONTAINER_MP4);	
        }
        break;

    case MPL_RECORDER_FORMAT_MJPEG:
        _rMplvrMgr.eAudioFormat = MEDIA_FORMAT_PCM_8K;
        _rMplvrMgr.u4AudioFrameDuration = 2;
        _rMplvrMgr.u4AudioFrameSize = 32;
        _rMplvrMgr.u4AudioBitRate = 128000;
        _MPLVR_ASSERT_IF_NOT_EQUAL(_rMplvrMgr.eMuxerContainerType, MUXER_CONTAINER_AVI);
        u4AudioBufferSize = MPLVR_AVI_AUDIO_BUFFER_SIZE;
        break;

    default:
        _MPLVR_ASSERT(0);
        break;
    }

    if (u4AudioBufferSize % 2 != 0)
    {
        ASSERT(0);
    }

    eMediaError = _MPLVR_AUDIO_SetupMemory(u4AudioBufferSize);
    if (eMediaError != MED_S_OK)
    {
        // The function _MPLVR_AUDIO_SetupMemory() will print a log on error.
        // No need to print anything here.
    }

    _rMplvrMgr.eAudioState = MPLVR_AUDIO_STATE_OPENED;

    return eMediaError;
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
static void _MPLVR_AUDIO_Close(void)
{
    kal_trace(TRACE_GROUP_10, MPLVR_TRC_AUDIO_CLOSE, _rMplvrMgr.eAudioState);

    switch (_rMplvrMgr.eAudioState)
    {
    case MPLVR_AUDIO_STATE_CLOSED:
        /* Do nothing. */
        break;

    case MPLVR_AUDIO_STATE_OPENED:
    case MPLVR_AUDIO_STATE_STOPPED:
        _MPLVR_AUDIO_ReleaseMemory();
        break;

    default:
        ASSERT(0);
        break;
    }

    _rMplvrMgr.eAudioState = MPLVR_AUDIO_STATE_CLOSED;
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
static media_error_t _MPLVR_AUDIO_Start(void)
{
    Media_Status aud_status;
    media_error_t eMediaError = MED_S_OK ;
    PFN_AUDIO_CALLBACK_T pfnAudioCallback;
    const Media_Format eAudioFormat = _rMplvrMgr.eAudioFormat;
    const kal_uint32 u4AudioTime = _rMplvrMgr.u4AccuAudioDataTime;
    kal_uint32 u4AudioSubformat = 0;

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_AUDIO_START, _rMplvrMgr.eAudioState);

    switch (eAudioFormat)
    {
    case MEDIA_FORMAT_AMR:
	case MEDIA_FORMAT_AMR_TRANSMIT:
        u4AudioSubformat = MPLVR_AUDIO_AMR_TYPE;
        break;

    case MEDIA_FORMAT_PCM_8K:
    case MEDIA_FORMAT_G711_ALAW:
    case MEDIA_FORMAT_G711_ULAW:
        u4AudioSubformat = MPLVR_AUDIO_PCM_TYPE;
        break;

    default:
        _MPLVR_ASSERT(0);
        break;
    }

    pfnAudioCallback = _MPLVR_AUDIO_Callback;

    switch (_rMplvrMgr.eAudioState)
    {
    case MPLVR_AUDIO_STATE_OPENED:
        _MPLVR_ASSERT_IF_NOT_EQUAL(u4AudioTime, 0);
        _MPLVR_SET_HD_AUDIO_PROPERTY();
        Media_A2V_SetInterruptCount(u4AudioTime);
        aud_status = Media_Record(eAudioFormat, pfnAudioCallback, (void*)u4AudioSubformat);
        if (aud_status != MEDIA_SUCCESS)
        {
            kal_trace(TRACE_GROUP_10, MPLVR_TRC_AUDIO_FAIL_TO_START_ENCODING, aud_status);
            eMediaError = MED_E_AUDIO_ERROR;
        }
        else
        {
            _rMplvrMgr.eAudioState = MPLVR_AUDIO_STATE_RUNNING;
            eMediaError = MED_S_OK;
        }
        break;

    default:
        ASSERT(0);
        break;
    }

    return eMediaError;
}


/*****************************************************************************
*
*****************************************************************************/
static void _MPLVR_AUDIO_Stop(void)
{
    kal_uint32 u4Loop = 0;

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_AUDIO_STOP, _rMplvrMgr.eAudioState);

    /* When audio is stopped, the remaining audio data needs to be sent to
     * Muxer while Muxer is still in RUNNING state. However, the CR
     * [MAUI_03086101] makes three API synchronous which has the
     * consequence that the remaining audo data is sent to STOPPED Muxer.
     * The solution is to set Muxer to RUNNING when audio is stopped.
     * This may introduce a new path which sets Muxer to RUNNING when it is
     * already in that state.
     */
    _MPLVR_MUXER_Start();

    switch (_rMplvrMgr.eAudioState)
    {
    case MPLVR_AUDIO_STATE_OPENED:  // FIXME: Consider changing state to STOPPED.
    case MPLVR_AUDIO_STATE_STOPPED:
        break;

    case MPLVR_AUDIO_STATE_RUNNING:
    case MPLVR_AUDIO_STATE_PAUSED:
        Media_Stop();
        _rMplvrMgr.eAudioState = MPLVR_AUDIO_STATE_STOPPED;

#ifdef __VE_STREAM_SERVER_SUPPORT__
        if (_rMplvrMgr.eMuxerContainerType != MUXER_CONTAINER_RTP)
#endif
		{
	        // Busy waiting until Muxer consumes all audio data.
	        while (1)
	        {
	            kal_uint8 *pu1AddrToSend;
	            kal_uint32 u4SizeToSend;

	            kal_take_mutex(_rMplvrMgr.eMutex);
	            _MPLVR_AUDIO_GetReadBuffer(&pu1AddrToSend, &u4SizeToSend);
	            if (u4SizeToSend == 0)
	            {
	                kal_give_mutex(_rMplvrMgr.eMutex);
	                break;
	            }
	            if (_rMplvrMgr.pu1LastAudioAddr == pu1AddrToSend)
	            {
	                kal_give_mutex(_rMplvrMgr.eMutex);
	                kal_sleep_task(1);  // Sleep for one tick.
	                continue;
	            }
	            _MPLVR_AUDIO_DoSendDataToMuxer(pu1AddrToSend, u4SizeToSend);
	            kal_give_mutex(_rMplvrMgr.eMutex);
	            u4Loop++;
	        }
		}
        kal_trace(TRACE_GROUP_10, MPLVR_TRC_AUDIO_REMAINING_DATA_SENT, u4Loop);
        break;

    default:
        ASSERT(0);
        break;
    }
}


/*****************************************************************************
*
*****************************************************************************/
static void _MPLVR_AUDIO_Pause(void)
{
    kal_trace(TRACE_GROUP_10, MPLVR_TRC_AUDIO_PAUSE, _rMplvrMgr.eAudioState);

    switch (_rMplvrMgr.eAudioState)
    {
    case MPLVR_AUDIO_STATE_RUNNING:
        Media_Pause();
        _rMplvrMgr.eAudioState = MPLVR_AUDIO_STATE_PAUSED;
        break;

    default:
        ASSERT(0);
        break;
    }
}


/*****************************************************************************
*
*****************************************************************************/
static void _MPLVR_AUDIO_Resume(void)
{
    kal_uint32 u4AudioTime;

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_AUDIO_RESUME, _rMplvrMgr.eAudioState);

    switch (_rMplvrMgr.eAudioState)
    {
    case MPLVR_AUDIO_STATE_PAUSED:
        // The next line is not necessary if Media_Pause() and Media_Resume() are used in pair.
        u4AudioTime = _MPLVR_AUDIO_GetTimeStampFromData(&_rMplvrMgr.u4AccuAudioDataTime);
        Media_A2V_SetInterruptCount(u4AudioTime);
        Media_Resume();  // FIXME: Process error here.
        _rMplvrMgr.eAudioState = MPLVR_AUDIO_STATE_RUNNING;
        break;

    default:
        ASSERT(0);
        break;
    }
}


/*****************************************************************************
* Context:
*****************************************************************************/
static void _MPLVR_CreateEvent(void)
{
    if (_rMplvrMgr.eEvent == NULL)
    {
        _rMplvrMgr.eEvent = kal_create_event_group("MPLVR_EVT");
    }
}


/*****************************************************************************
*
*****************************************************************************/
static kal_bool _MPLVR_HasBackSlash(kal_wchar *file_name)
{
#if !defined(__VE_SLIM_PROJECT__)
    kal_wchar *pwszFileNamePath;

    pwszFileNamePath = file_name + kal_wstrlen(file_name);
    while (pwszFileNamePath > file_name)
    {
        if (*pwszFileNamePath == L'\\')
        {
            return KAL_TRUE;
        }
        pwszFileNamePath--;
    }
    return KAL_FALSE;
#else
    return KAL_TRUE;
#endif  // !defined(__VE_SLIM_PROJECT__)
}


/*****************************************************************************
* Start video recording.
*****************************************************************************/
static media_error_t _MPLVR_DoOpen(mpl_recorder_open_param_t *open_struct)
{
    media_error_t eMediaError = MED_S_OK ;
    VIDEO_ERROR_TYPE_T eVideoError = VIDEO_ERROR_NONE;
    kal_uint32 u4EncoderFrameRate, u4EncoderBitRate;
    VIDEO_ENCODER_TYPE_T eEncoderType = VIDEO_ENCODER_MPEG4;
    VIDEO_ENCODER_QUALITY_T eEncoderQuality;
    kal_uint32 u4FrameWidth = open_struct->image_width;
    kal_uint32 u4FrameHeight = open_struct->image_height;
    kal_bool fgRecordYuv = open_struct->fgRecordYuv;

    // Do not report errors multiple times for a recording session.
    // Otherwise, the queue in the upper-layer software may overflow.
    _rMplvrMgr.fgErrorOfSaveCommandReported = KAL_FALSE;
    _rMplvrMgr.fgErrorOfStopCommandReported = KAL_FALSE;
    _rMplvrMgr.fgGeneralErrorReported = KAL_FALSE;

    _rMplvrMgr.eMutex = VideoGetMutex(MUTEX_USER_VIDEO_RECORDERMPL);

    // Setup frame rate table and convert some enumerators.
    // The user of frame rate tables must be set before any property can
    // be set into any of those tables.
    _MPLVR_FRT_Initialize(open_struct->user);
    _MPLVR_FRT_SetResolution(u4FrameWidth, u4FrameHeight);
    _MPLVR_FRT_SetQuality(open_struct->quality, &eEncoderQuality);
    _MPLVR_FRT_SetStorage(open_struct->storage);
    _MPLVR_FRT_SetCodecType(open_struct->format, &eEncoderType);
    _MPLVR_FRT_SetSoftwareRotator(open_struct->eSoftwareRotator);

    #if 1 //[MAUI_03208340] Frame Rate Table user may be changed after opening for menu generation
    _rMplvrMgr.u4user = open_struct->user;
    _rMplvrMgr.u4imagewidth = u4FrameWidth;
    _rMplvrMgr.u4imageheight = u4FrameHeight;
    _rMplvrMgr.u4quality = open_struct->quality;
    _rMplvrMgr.u4storage = open_struct->storage;
    _rMplvrMgr.u4format = open_struct->format;
    _rMplvrMgr.u4eSoftwareRotator = open_struct->eSoftwareRotator;
    #endif

    _MPLVR_FRT_GetEncoderFrameRate(&u4EncoderFrameRate);
    _MPLVR_FRT_GetEncoderBitRate(&u4EncoderBitRate);

    eMediaError = _MPLVR_AUDIO_Open(open_struct->format);
    if (eMediaError != MED_S_OK)
    {
        // The function _MPLVR_AUDIO_Open() will print a log on error.
        // No need to print anything here.
        return eMediaError;
    }

    eMediaError = _MPLVR_VIDEO_Open(eEncoderType, fgRecordYuv, eEncoderQuality,
        u4EncoderFrameRate, u4EncoderBitRate, u4FrameWidth, u4FrameHeight);
    if (eMediaError != MED_S_OK)
    {
        // The function _MPLVR_VIDEO_Open() will print a log on error.
        // No need to print anything here.
        return eMediaError;
    }

    _MPLVR_MUXER_Open(KAL_FALSE);

    // The FillThisBuffer() which is used to return audio data to MPL by Muxer
    // must be set after Muxer's handle has been obtained.
    eVideoError = VideoConfigComp(_rMplvrMgr.prMuxerHandle, KAL_TRUE,
        VIDEO_PORT_AUDIO_DATA, _MPLVR_AUDIO_FillThisBuffer);
	if (eVideoError != VIDEO_ERROR_NONE)
	{
        kal_trace(TRACE_GROUP_10, MPLVR_TRC_ERROR_SET_AUDIO_FILL_BUFFER, eVideoError);
		return MED_E_ERROR;
	}

    _rMplvrMgr.eState = MPLVR_STATE_OPENED;

    return eMediaError;
}


/*****************************************************************************
* Start video recording.
*****************************************************************************/
static media_error_t _MPLVR_DoStart(mpl_recorder_record_param_t *start_struct)
{
    kal_uint64 u8TimeLimit;
    media_error_t eMediaError = MED_S_OK;
    VIDEO_ENCODER_QUALITY_T eEncoderQuality;
    VIDEO_ENCODER_TYPE_T eEncoderType = VIDEO_ENCODER_MPEG4;

#ifdef __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__
    // Input image may be rotated by requests from motion sensor.
    // MPL receives orientation change right before video recording is started.
    if (start_struct->u4ImageWidth * start_struct->u4ImageHeight !=
        _rMplvrMgr.u4FrameWidth * _rMplvrMgr.u4FrameHeight)
    {
        ASSERT(0);
    }
    _rMplvrMgr.ePlaybackRotationAngle = start_struct->ePlaybackRotationAngle;
    _rMplvrMgr.u4FrameWidth = start_struct->u4ImageWidth;
    _rMplvrMgr.u4FrameHeight = start_struct->u4ImageHeight;
#endif  // __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__

#if 1 //[MAUI_03208340] Frame Rate Table user may be changed after opening for menu generation
    // Setup frame rate table and convert some enumerators.
    // The user of frame rate tables must be set before any property can
    // be set into any of those tables.
    _MPLVR_FRT_Initialize((mpl_recorder_user_enum_t)_rMplvrMgr.u4user);
    _MPLVR_FRT_SetResolution(_rMplvrMgr.u4imagewidth, _rMplvrMgr.u4imageheight);
    _MPLVR_FRT_SetQuality((mpl_recorder_quality_enum_t)_rMplvrMgr.u4quality, &eEncoderQuality);
    _MPLVR_FRT_SetStorage((mpl_recorder_storage_enum_t)_rMplvrMgr.u4storage);
    _MPLVR_FRT_SetCodecType((mpl_recorder_format_enum_t)_rMplvrMgr.u4format, &eEncoderType);
    _MPLVR_FRT_SetSoftwareRotator((mpl_recorder_rotation_t)_rMplvrMgr.u4eSoftwareRotator);
#endif

#ifdef __VE_STREAM_SERVER_SUPPORT__
    if (_rMplvrMgr.eMuxerContainerType != MUXER_CONTAINER_RTP)
#endif		
	{
    	eMediaError = _MPLVR_CheckMinFreeSpace(start_struct->working_path);
    	if (eMediaError != MED_S_OK)
    	{
        	kal_trace(TRACE_GROUP_10, MPLVR_TRC_DOSTART_MEDIA_ERROR, eMediaError);
        	return eMediaError;
    	}
	}


#ifdef __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__
    // Set resolution to Encoder again because orientation may be changed by motion sensor.
    eMediaError = _MPLVR_ENCODER_SetResolution();
    if (eMediaError != MED_S_OK)
    {
        return eMediaError;
    }
#endif  // __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__

    _MPLVR_MUXER_SetAudioProperties(start_struct->record_audio);
    _MPLVR_MUXER_SetVideoProperties();
    _MPLVR_MUXER_SetContainerProperties(start_struct->working_path,
        &start_struct->record_file_size_limit, &start_struct->record_time_limit);

    // Convert time unit from milli-second to micro-second.
    u8TimeLimit = VIDEO_ANYBASE_TO_ANYBASE(start_struct->record_time_limit,
        MPLVR_TIME_SCALE_MILLISECOND, MPLVR_TIME_SCALE_MICROSECOND);
    _MPLVR_SetParameterToComponent(_rMplvrMgr.prEncoderHandle,
        VIDEO_PARAM_ENCODER_SET_TIME_LIMIT, (void*)&u8TimeLimit);

#if defined(__VE_TIME_LAPSE_VIDEO_RECORDER__)
    _MPLVR_ENCODER_SetTimeLapse(_rMplvrMgr.u4EncodeOneofNSecond, _rMplvrMgr.u4PlaybackFps);
    _MPLVR_SetParameterToComponent(_rMplvrMgr.prMuxerHandle,
        MUXER_SET_TIME_LAPSE_FRAME_RATE, (void*)(&_rMplvrMgr.u4PlaybackFps));
#endif

#ifdef __VE_STREAM_SERVER_SUPPORT__
	_MPLVR_SetParameterToComponent(_rMplvrMgr.prMuxerHandle,
		MUXER_SET_VIDEO_RTP_HANDLE, (void*)(&_rMplvrMgr.u1VideoRTPHandle));
	_MPLVR_SetParameterToComponent(_rMplvrMgr.prMuxerHandle,
		MUXER_SET_AUDIO_RTP_HANDLE, (void*)(&_rMplvrMgr.u1AudioRTPHandle));
#endif

    _MPLVR_DisableSleep();

    // Make sure Muxer is running before any data is generated.
    _MPLVR_MUXER_Start();

    eMediaError = _MPLVR_AUDIO_Start();
    if (eMediaError != MED_S_OK)
    {
        // The function _MPLVR_AUDIO_Start() will print a log on error.
        // No need to print anything here.
        return eMediaError;
    }

    _MPLVR_VIDEO_Start();

    _rMplvrMgr.eState = MPLVR_STATE_RECORDING;

    return eMediaError;
}


/*****************************************************************************
* Stop audio and video recording.
* 1. Stop Source and Encoder, and wait for their completion later.
* 2. Stop Audio path.
* 3. Flush audio data to Muxer.
* 4. Stop Muxer, and wait for its completion.
*
* Context: MED
*****************************************************************************/
static void _MPLVR_DoStop(void)
{
#ifdef __VE_STREAM_SERVER_SUPPORT__
    if (_rMplvrMgr.eMuxerContainerType == MUXER_CONTAINER_RTP)
    {
        _MPLVR_SetParameterToComponent(_rMplvrMgr.prMuxerHandle,
            MUXER_SET_RTP_INSTANT_STOP, (void*)NULL);        
    }
#endif

    _MPLVR_VIDEO_SendStopCommand();

    _MPLVR_AUDIO_Stop();

    _MPLVR_VIDEO_WaitUntilStopped();

    _MPLVR_MUXER_Stop(KAL_FALSE);

    _MPLVR_EnableSleep();

    _rMplvrMgr.eState = MPLVR_STATE_STOPPED;
}


/*****************************************************************************
* Stop audio and video recording.
* 1. Stop Source and Encoder, and wait for their completion later.
* 2. Pause Audio path.
* 3. Flush audio data to Muxer.
* 4. Stop Muxer, and wait for its completion.
*
*****************************************************************************/
static media_error_t _MPLVR_DoPause(void)
{
    media_error_t eMediaError = MED_S_OK ;

    _MPLVR_VIDEO_SendStopCommand();

    _MPLVR_AUDIO_Pause();

    _MPLVR_VIDEO_WaitUntilStopped();

    _MPLVR_MUXER_Stop(KAL_FALSE);

    _MPLVR_EnableSleep();

    _rMplvrMgr.eState = MPLVR_STATE_PAUSED;

    return eMediaError;
}


/*****************************************************************************
* Start video recording.
*****************************************************************************/
static media_error_t _MPLVR_DoResume(void)
{
    media_error_t eMediaError = MED_S_OK ;

    _MPLVR_DisableSleep();

    // Make sure Muxer is running before any data is generated.
    _MPLVR_MUXER_Start();

    _MPLVR_AUDIO_Resume();  // FIXME: This function may return error.

    _MPLVR_VIDEO_Start();

    _rMplvrMgr.eState = MPLVR_STATE_RECORDING;

    return eMediaError;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_DoClose(void)
{
    _MPLVR_AUDIO_Close();

    // The memory of Muxer running in non-solo mode is allocated from the
    // Encoder component, i.e. the Video module.  It is important that the
    // memory of the Video module is released after Muxer is closed.
    _MPLVR_MUXER_Close(KAL_FALSE);

    _MPLVR_VIDEO_Close();

    VideoFreeMutex(MUTEX_USER_VIDEO_RECORDERMPL, _rMplvrMgr.eMutex);
    _rMplvrMgr.eState = MPLVR_STATE_CLOSED;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_DoPauseVideo(void)
{
    _MPLVR_VIDEO_Stop();
    _rMplvrMgr.eState = MPLVR_STATE_RECORDING_AUDIO;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _MPLVR_DoResumeVideo(void)
{
    _MPLVR_VIDEO_Start();
    _rMplvrMgr.eState = MPLVR_STATE_RECORDING;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static media_error_t _MPLVR_DoCreateFile(mpl_recorder_save_param_t *prParam)
{
    _MPLVR_MUXER_CreateFinalFile(prParam->working_path, prParam->file_path);
    _rMplvrMgr.eState = MPLVR_STATE_SAVING_FILE;

    return MED_S_ASYNC;
}


/*****************************************************************************
* The Open operation mainly prepares the visual path.  After this function
* returns, IDP will begin to get frame buffer from the Source component.
* Therefore, it is important that frame buffer has been prepared.  In other
* words, frame width and height must be known to the Encoder component.
*
* Context: MED
*****************************************************************************/
static media_error_t MPLVR_Open(mpl_recorder_t *prInterface,
        mpl_recorder_open_param_t *open_struct)
{
    media_error_t eMediaError = MED_S_OK ;

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_OPEN, _rMplvrMgr.eState);

    switch (_rMplvrMgr.eState)
    {
    case MPLVR_STATE_CLOSED:
        eMediaError = _MPLVR_DoOpen(open_struct);
        if (eMediaError != MED_S_OK)
        {
            _MPLVR_DoClose();
        }
        break;

    default:
        ASSERT(0);
        break;
    }

    return eMediaError;
}


/*****************************************************************************
* Muxer may delete temporary files before video recording is started, and this
* is not MPL's business.
*
* Context: MED
*****************************************************************************/
static media_error_t MPLVR_Start(mpl_recorder_t *prInterface,
        mpl_recorder_record_param_t *start_struct)
{
    media_error_t eMediaError = MED_S_OK ;

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_START, _rMplvrMgr.eState);

    if (_MPLVR_HasBackSlash(start_struct->working_path) == KAL_FALSE)
    {
        return MED_E_INVALID_PARAM;
    }

    switch (_rMplvrMgr.eState)
    {
    case MPLVR_STATE_OPENED:
        eMediaError = _MPLVR_DoStart(start_struct);
        if (eMediaError != MED_S_OK)
        {
            _MPLVR_DoStop();
        }
        break;

    default:
        eMediaError = MED_E_BUSY;
        break;
    }

    return eMediaError;
}


/*****************************************************************************
* This is a synchronous API.
*
* Context: MED
*****************************************************************************/
static media_error_t MPLVR_Stop(mpl_recorder_t *prInterface)
{
    media_error_t eMediaError = MED_S_OK;

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_STOP, _rMplvrMgr.eState);

    _rMplvrMgr.fgSynchronousCall = KAL_TRUE;
    _rMplvrMgr.eSynchronousMediaError = MED_S_OK;

    switch (_rMplvrMgr.eState)
    {
    case MPLVR_STATE_RECORDING:
    case MPLVR_STATE_PAUSED:
    case MPLVR_STATE_RECORDING_AUDIO:
        _MPLVR_DoStop();
        /* fall through */
    case MPLVR_STATE_STOPPED:
        eMediaError = _rMplvrMgr.eSynchronousMediaError;
        if (eMediaError != MED_S_OK)
        {
            _MPLVR_DoStopOnError();
        }
        break;

    default:
        eMediaError = MED_E_FAIL;
        break;
    }

    _rMplvrMgr.fgSynchronousCall = KAL_FALSE;
    return eMediaError;
}


/*****************************************************************************
* This is a synchronous API.
*
* Context: MED
*****************************************************************************/
static media_error_t MPLVR_Pause(mpl_recorder_t *prInterface)
{
    media_error_t eMediaError = MED_S_OK;

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_PAUSE, _rMplvrMgr.eState);

    _rMplvrMgr.fgSynchronousCall = KAL_TRUE;
    _rMplvrMgr.eSynchronousMediaError = MED_S_OK;

    switch (_rMplvrMgr.eState)
    {
    case MPLVR_STATE_RECORDING:
        eMediaError = _MPLVR_DoPause();
#if 0  // _MPLVR_DoPause() always returns MED_S_OK in current implementation.
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // 0
        eMediaError = _rMplvrMgr.eSynchronousMediaError;
        if (eMediaError != MED_S_OK)
        {
            _MPLVR_DoStopOnError();
        }
        break;

    default:
        eMediaError = MED_E_BUSY;
        break;
    }

    _rMplvrMgr.fgSynchronousCall = KAL_FALSE;
    return eMediaError;
}


/*****************************************************************************
*
* Context: MED
*****************************************************************************/
static media_error_t MPLVR_Resume(mpl_recorder_t *prInterface)
{
    media_error_t eMediaError = MED_S_OK;

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_RESUME, _rMplvrMgr.eState);

    switch (_rMplvrMgr.eState)
    {
    case MPLVR_STATE_PAUSED:
        eMediaError = _MPLVR_DoResume();
#if 0  // _MPLVR_DoResume() always returns MED_S_OK in current implementation.
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // 0
        break;

    default:
        eMediaError = MED_E_BUSY;
        break;
    }

    return eMediaError;
}


/*****************************************************************************
* Context:
*****************************************************************************/
static media_error_t MPLVR_PauseVisualEncoding(mpl_recorder_t *prInterface)
{
    media_error_t eMediaError = MED_S_OK;

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_PAUSE_VISUAL_ENCODING, _rMplvrMgr.eState);

    switch (_rMplvrMgr.eState)
    {
    case MPLVR_STATE_RECORDING:
        _MPLVR_DoPauseVideo();
        break;

    default:
        eMediaError = MED_E_FAIL;
        break;
    }

    return eMediaError;
}


/*****************************************************************************
* Context:
*****************************************************************************/
static media_error_t MPLVR_ResumeVisualEncoding(mpl_recorder_t *prInterface)
{
    media_error_t eMediaError = MED_S_OK;

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_RESUME_VISUAL_ENCODING, _rMplvrMgr.eState);

    switch (_rMplvrMgr.eState)
    {
    case MPLVR_STATE_RECORDING_AUDIO:
        _MPLVR_DoResumeVideo();
        break;

    default:
        eMediaError = MED_E_FAIL;
        break;
    }

    return eMediaError;
}


/*****************************************************************************
* Context: MED
*****************************************************************************/
static media_error_t MPLVR_SetParameter(mpl_recorder_t *prInterface,
        mpl_recorder_param_enum_t eParam, void *value, kal_int32 size)
{
    kal_uint32 u4EncoderFrameRate;

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_SET_PARAM, _rMplvrMgr.eState, (kal_uint32)eParam);

    switch (eParam)
    {
    case MPL_RECORDER_PARAM_SET_FRAME_RATE:
        u4EncoderFrameRate = (kal_uint32)value;
        _MPLVR_ENCODER_SetFrameRate(u4EncoderFrameRate);
        break;

    #ifdef __VE_TIME_LAPSE_VIDEO_RECORDER__
    case MPL_RECORDER_PARAM_TIME_LAPSE_ENCODE_ONE_OF_N_SEC:
        _rMplvrMgr.u4EncodeOneofNSecond = (kal_uint32)value*1000;
        break;

    case MPL_RECORDER_PARAM_TIME_LAPSE_SET_PLAYBACK_FPS:
        _rMplvrMgr.u4PlaybackFps = (kal_uint32)value;
        break;
    #endif

#ifdef __VE_STREAM_SERVER_SUPPORT__
	case MPL_RECORDER_PARAM_SET_VIDEO_RTP_HANDLE:
		_rMplvrMgr.u1VideoRTPHandle = (kal_uint8)value;
		break;
	case MPL_RECORDER_PARAM_SET_AUDIO_RTP_HANDLE:
		_rMplvrMgr.u1AudioRTPHandle = (kal_uint8)value;
		break;	
#endif

    default:
        ASSERT(0);
        break;
    }

    return MED_S_OK;
}


/*****************************************************************************
* Context: MMI (for MPL_RECORDER_PARAM_IS_UNFINISHED_FILE)
*          MED (for others)
*****************************************************************************/
static media_error_t MPLVR_GetParameter(mpl_recorder_t *prInterface,
        mpl_recorder_param_enum_t eParam, void *value, kal_int32 size)
{
    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_GET_PARAM, _rMplvrMgr.eState, (kal_uint32)eParam);

    switch (eParam)
    {
    case MPL_RECORDER_PARAM_RECORDED_SIZE:
        {
            kal_uint64 *pu8FinalFileSize;
            pu8FinalFileSize = (kal_uint64*)value;
            _MPLVR_MUXER_GetCurrentFileSize(pu8FinalFileSize);
        }
        break;

    case MPL_RECORDER_PARAM_RECORDED_TIME:
        {
            kal_uint64 *pu8RecordTime;
#if 0  // Upper layer software does not pass the correct size to this function.
/* under construction !*/
#endif  // 0
            pu8RecordTime = (kal_uint64*)value;
            VRCLK_GetCurrentTime(pu8RecordTime);
            *pu8RecordTime = VIDEO_ANYBASE_TO_ANYBASE(*pu8RecordTime,
                MPLVR_TIME_SCALE_MICROSECOND, MPLVR_TIME_SCALE_MILLISECOND);
        }
        break;

    case MPL_RECORDER_PARAM_GET_BUFFER_PFN:
        {
            mpl_get_buffer_pfn_t *ppfnGetSourceBuffer;
            _MPLVR_CHECK_SIZE(mpl_get_buffer_pfn_t, size);
            ppfnGetSourceBuffer = (mpl_get_buffer_pfn_t*)value;
            if (_rMplvrMgr.fgDirectCoupledSensor == KAL_TRUE)
            {
                *ppfnGetSourceBuffer = VENC_GetBistreamBuffer;
            }
            else
            {
                *ppfnGetSourceBuffer = VideoRecorderGetSourceBuffer;
            }
        }
        break;

    case MPL_RECORDER_PARAM_RETURN_BUFFER_PFN:
        {
            mpl_return_buffer_pfn_t *ppfnReturnSourceBuffer;
            _MPLVR_CHECK_SIZE(mpl_return_buffer_pfn_t, size);
            ppfnReturnSourceBuffer = (mpl_return_buffer_pfn_t*)value;
            if (_rMplvrMgr.fgDirectCoupledSensor == KAL_TRUE)
            {
                *ppfnReturnSourceBuffer = VENC_ReturnBistreamBuffer;
            }
            else
            {
                *ppfnReturnSourceBuffer = VideoRecorderCompleteSourceBuffer;
            }
        }
        break;

    case MPL_RECORDER_PARAM_IS_UNFINISHED_FILE:
        {
            mpl_recorder_is_unsaved_file_param_t *prUnfinished;
            _MPLVR_CHECK_SIZE(mpl_recorder_is_unsaved_file_param_t, size);
            prUnfinished = (mpl_recorder_is_unsaved_file_param_t*)value;
            if (_MPLVR_HasBackSlash(prUnfinished->working_path) == KAL_FALSE)
            {
                return MED_E_INVALID_PARAM;
            }
            _MPLVR_MUXER_IsThereUnfinishedFiles(prUnfinished);
        }
        break;

    case MPL_RECORDER_PARAM_GET_RESERVED_DISK_SIZE:
        // To make more precise estimation, it is suggested that the upper-layer
        // software passs working path into MPL for cluster size evaluation.
        _MPLVR_MUXER_GetReservedDiskSpace((kal_uint32*)value);
        break;

    #ifdef __VE_TIME_LAPSE_VIDEO_RECORDER__
    case MPL_RECORDER_PARAM_TIME_LAPSE_GET_ENCODED_FRAME_NUM:
        {
        kal_uint32 *pu4EncodedFrameNum = (kal_uint32*)value;

        *pu4EncodedFrameNum = 0; // To get encoded frame number from encoder
        if (_rMplvrMgr.eVideoState == MPLVR_VIDEO_STATE_RUNNING)
        {
            _MPLVR_GetParameterFromComponent(_rMplvrMgr.prEncoderHandle,
                VIDEO_PARAM_ENCODER_GET_TIME_LAPSE_ENCODED_FRAME_COUNT, (void*)pu4EncodedFrameNum);
        }
        }
        break;
    #endif


    default:
        ASSERT(0);
        break;
    }

    return MED_S_OK;
}


/*****************************************************************************
* Context: MED
*****************************************************************************/
static media_error_t MPLVR_Save(mpl_recorder_t *prInterface,
        mpl_recorder_save_param_t *prParam)
{
    media_error_t eMediaError = MED_S_OK;

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_SAVE, _rMplvrMgr.eState);

    _MPLVR_ASSERT_IF_EQUAL(prParam->file_path, NULL);
    _MPLVR_ASSERT_IF_EQUAL(prParam->working_path, NULL);

    if ((_MPLVR_HasBackSlash(prParam->working_path) == KAL_FALSE) ||
        (_MPLVR_HasBackSlash(prParam->file_path) == KAL_FALSE))
    {
        return MED_E_INVALID_PARAM;
    }

    switch (_rMplvrMgr.eState)
    {
    case MPLVR_STATE_CLOSED:
        eMediaError = _MPLVR_DoCreateFile(prParam);
        // Muxer is closed (eState = CLOSED) when MPL receives the completion
        // of file merge in Muxer callback.
        break;

    default:
        ASSERT(0);
        break;
    }

    return eMediaError;
}


/*****************************************************************************
* Context:
*****************************************************************************/
static media_error_t MPLVR_AbortSaving(mpl_recorder_t *prInterface)
{
    media_error_t eMediaError = MED_E_FAIL;

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_ABORT_SAVING, _rMplvrMgr.eState);

    switch (_rMplvrMgr.eState)
    {
    case MPLVR_STATE_SAVING_FILE:
        eMediaError = _MPLVR_MUXER_WaitForCallbackFromAbort();
        break;

    default:
        kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_WARNING_WRONG_STATE);
        // eMediaError = MED_E_WRONG_STATE;  // If MDI can handle this error, consider to use it.
        break;
    }

    return eMediaError;
}


/*****************************************************************************
* Context:
*****************************************************************************/
static media_error_t MPLVR_Discard(mpl_recorder_t *prInterface,
        mpl_recorder_discard_param_t *prParam)
{
    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_DISCARD, _rMplvrMgr.eState);

    if (_MPLVR_HasBackSlash(prParam->working_path) == KAL_FALSE)
    {
        return MED_E_INVALID_PARAM;
    }

    switch (_rMplvrMgr.eState)
    {
    case MPLVR_STATE_OPENED:
    case MPLVR_STATE_CLOSED:
        _MPLVR_MUXER_DeleteTemporaryFiles(prParam->working_path);
        break;

    default:
        ASSERT(0);
        break;
    }

    return MED_S_OK;
}


/*****************************************************************************
* This is a synchronous API.
*
* Context: MED
*****************************************************************************/
static media_error_t MPLVR_Close(mpl_recorder_t *prInterface)
{
    media_error_t eMediaError = MED_S_OK;

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_CLOSE, _rMplvrMgr.eState);

    _rMplvrMgr.fgSynchronousCall = KAL_TRUE;
    _rMplvrMgr.eSynchronousMediaError = MED_S_OK;

    switch (_rMplvrMgr.eState)
    {
    case MPLVR_STATE_CLOSED:
        /* The MMI of AVI recorder will contruct a recorder, query for
         * something, and then close the recorder without opening it. */
        break;

    case MPLVR_STATE_OPENED:
    case MPLVR_STATE_STOPPED:
        _MPLVR_DoClose();
        eMediaError = _rMplvrMgr.eSynchronousMediaError;
        if (eMediaError != MED_S_OK)
        {
            _MPLVR_DoStopOnError();
        }
        break;

#if 0  // FIXME
/* under construction !*/
/* under construction !*/
#endif  // 0

    default:
        ASSERT(0);
        break;
    }

    _rMplvrMgr.fgSynchronousCall = KAL_FALSE;
    return eMediaError;
}


/*****************************************************************************
* Context: MED
*****************************************************************************/
static media_error_t MPLVR_InitParameter(mpl_recorder_t *prInterface,
        mpl_recorder_param_type_enum_t eParamType, void *prParam, kal_int32 u4Size)
{
    // MPLVR_MANAGER_T *self = PTHIS(prInterface, MPLVR_MANAGER_T, prInterface);
    mpl_recorder_record_param_t *record_param_p;

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_INIT_PARAM, _rMplvrMgr.eState);

    _MPLVR_ASSERT_IF_EQUAL(prParam, NULL);

    switch (eParamType)
    {
    case MPL_RECORDER_PARAM_TYPE_OPEN:
        _MPLVR_CHECK_SIZE(mpl_recorder_open_param_t, u4Size);
        kal_mem_set(prParam, 0, u4Size);
        // mpl_recorder_open_param_t *open_param_p;
        // The following statements are redundant because of the memset() above.
        // open_param_p = (mpl_recorder_open_param_t*)prParam;
        // open_param_p->format = MPL_RECORDER_FORMAT_MPEG4;
        // open_param_p->quality = MPL_RECORDER_QUALITY_FINE;
        // open_param_p->storage = MPL_RECORDER_STORAGE_PHONE;
        // open_param_p->user = MPL_RECORDER_USER_RECORDER;
        // open_param_p->fgRecordYuv = KAL_FALSE;
        break;

    case MPL_RECORDER_PARAM_TYPE_START:
        _MPLVR_CHECK_SIZE(mpl_recorder_record_param_t, u4Size);
        kal_mem_set(prParam, 0, u4Size);
        record_param_p = (mpl_recorder_record_param_t*)prParam;
        record_param_p->record_audio = KAL_TRUE;
#ifdef __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__
        // record_param_p->ePlaybackRotationAngle = MPL_RECORDER_ROTATION_ANGLE_CW_0;
        record_param_p->u4ImageWidth = _rMplvrMgr.u4FrameWidth;
        record_param_p->u4ImageHeight = _rMplvrMgr.u4FrameHeight;
#endif  // __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__
        break;

    case MPL_RECORDER_PARAM_TYPE_SAVE:
        _MPLVR_CHECK_SIZE(mpl_recorder_save_param_t, u4Size);
        kal_mem_set(prParam, 0, u4Size);
        break;

    case MPL_RECORDER_PARAM_TYPE_DISCARD:
        _MPLVR_CHECK_SIZE(mpl_recorder_discard_param_t, u4Size);
        kal_mem_set(prParam, 0, u4Size);
        break;

    default:
        _MPLVR_ASSERT(0);
        break;
    }

    return MED_S_OK;
}


#ifdef __VE_DCM_WITH_COMPRESSION__
#pragma arm section code, rodata
#endif  // __VE_DCM_WITH_COMPRESSION__

/******************************************************************************
*
* Context: Caller's context. (Component callback function)
*
* Side effect:
******************************************************************************/
static void _MPLVR_SetEvents(kal_uint32 u4Event)
{
    kal_set_eg_events(_rMplvrMgr.eEvent, u4Event, KAL_OR);
}

/******************************************************************************
*
* Context: Encoder component context
*
* Side effect:
******************************************************************************/
static VIDEO_ERROR_TYPE_T _MPLVR_ENCODER_EventHandler(VIDEO_EVENT_TYPE_T eEvent,
        kal_uint32 u4Data1, kal_uint32 u4Data2, void *pData)
{
    kal_trace(TRACE_GROUP_10, MPLVR_TRC_ENCODER_EVENT, eEvent, u4Data1, u4Data2, (kal_uint32)pData);

    switch (eEvent)
    {
    case VIDEO_EVENT_COMPLETE:
        _MPLVR_ASSERT_IF_NOT_EQUAL(u4Data1, VIDEO_COMMAND_STATESET);
        _MPLVR_SetEvents(MPLVR_EVENT_ENCODER_COMPLETE);
        break;

    case VIDEO_EVENT_REACH_TIME_LIMIT:
        _MPLVR_StopAndNotify(MPL_RECORDER_EVENT_GENERAL, MED_E_STOP_TIME_REACHED);
        break;

    default:
        _MPLVR_ASSERT(0);
        break;
    }

    return VIDEO_ERROR_NONE;
}

/******************************************************************************
*
*
* Context:
*
* Side effect:
******************************************************************************/
static VIDEO_ERROR_TYPE_T _MPLVR_MUXER_EventHandler(VIDEO_EVENT_TYPE_T eEvent,
        kal_uint32 u4Data1, kal_uint32 u4Data2, void *pData)
{
    VIDEO_ERROR_TYPE_T eVideoError = VIDEO_ERROR_NONE;
    mpl_recorder_event_enum_t eMplEvent;

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_MUXER_EVENT, eEvent, u4Data1, u4Data2, (kal_uint32)pData);

    if (_rMplvrMgr.eState == MPLVR_STATE_SAVING_FILE)
    {
        eMplEvent = MPL_RECORDER_EVENT_SAVE;
    }
    else
    {
        eMplEvent = MPL_RECORDER_EVENT_GENERAL;
    }

    switch (eEvent)
    {
    case VIDEO_EVENT_COMPLETE:
        _MPLVR_ASSERT_IF_NOT_EQUAL(u4Data1, VIDEO_COMMAND_STATESET);
        _MPLVR_SetEvents(MPLVR_EVENT_MUXER_COMPLETE);
        break;

    case VIDEO_EVENT_MUXER_FILE_CREATED:
        _MPLVR_MakeAsyncCall(_MPLVR_MUXER_CloseFileMergeAsync, eMplEvent, MED_S_OK, MOD_MED);
        break;

    case VIDEO_EVENT_MUXER_ABORT_SAVING_FAIL:
        _MPLVR_MUXER_CallbackFromAbort(eMplEvent, MED_E_FAIL);
        break;

    case VIDEO_EVENT_MUXER_ABORT_SAVING_DONE:
        _MPLVR_MUXER_CallbackFromAbort(eMplEvent, MED_S_OK);
        break;

    case VIDEO_EVENT_MUXER_REACH_SIZE_LIMIT:
        _MPLVR_StopAndNotify(eMplEvent, MED_E_END_OF_FILE);
        break;

    case VIDEO_EVENT_ERROR:
        _MPLVR_StopAndNotify(eMplEvent, MED_E_ERROR);
        break;

    case VIDEO_EVENT_NO_VIDEO_FRAME_ENCODED:
        _MPLVR_StopAndNotify(eMplEvent, MED_E_VIDEO_NO_FRAME_ENCODED);
        break;

    case VIDEO_EVENT_NO_DISK:
        _MPLVR_StopAndNotify(eMplEvent, MED_E_NO_DISC);
        break;

    case VIDEO_EVENT_DISK_IS_FULL:
        _MPLVR_StopAndNotify(eMplEvent, MED_E_DISC_FULL);
        break;

    default:
        _MPLVR_ASSERT(0);
        break;
    }

    return eVideoError;
}

/*****************************************************************************
* Context: MED
*****************************************************************************/
void MPLVR_Destroy(mpl_recorder_t *prInterface)
{
    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_DESTROY, _rMplvrMgr.eState);
    _MPLVR_ASSERT_IF_EQUAL(prInterface, NULL);

#ifdef __VE_DCM_WITH_COMPRESSION__
    if (_rMplvrMgr.fgInDCM == KAL_TRUE)
    {
        VideoDCMUnLoad(DYNAMIC_CODE_COMPRESS_VEENC);  /* Unload DCM with compression */
        _rMplvrMgr.fgInDCM = KAL_FALSE;
    }
    else
    {
        ASSERT(0);
    }
#endif  // __VE_DCM_WITH_COMPRESSION__
}


/*****************************************************************************
* API function table
*****************************************************************************/
const static mpl_recorder_t _rMplApi =
{
    /*.open                 =*/ MPLVR_Open,
    /*.start                =*/ MPLVR_Start,
    /*.stop                 =*/ MPLVR_Stop,
    /*.pause                =*/ MPLVR_Pause,
    /*.resume               =*/ MPLVR_Resume,
    /*.pause_video_encode   =*/ MPLVR_PauseVisualEncoding,
    /*.resume_video_encode  =*/ MPLVR_ResumeVisualEncoding,
    /*.set_param            =*/ MPLVR_SetParameter,
    /*.get_param            =*/ MPLVR_GetParameter,
    /*.save                 =*/ MPLVR_Save,
    /*.abort_saving         =*/ MPLVR_AbortSaving,
    /*.discard              =*/ MPLVR_Discard,
    /*.close                =*/ MPLVR_Close,
    /*.get_default          =*/ MPLVR_InitParameter,
    /*.destroy              =*/ MPLVR_Destroy
};


/*****************************************************************************
* Caller must retain the data structure of *prMplvrClient until MPL video
* recorder is closed.  Otherwiese, MPL needs to keep a copy of the structure.
* Context:
*****************************************************************************/
static void _MPLVR_ConstructRecorder(mpl_recorder_client_t *prMplvrClient)
{
    kal_eventgrpid eEvent;

#ifdef __VE_DCM_WITH_COMPRESSION__
    kal_bool fgInDCM;
    if (_rMplvrMgr.fgInDCM == KAL_FALSE)
    {
        VideoDCMLoad(DYNAMIC_CODE_COMPRESS_VEENC);  /* Load DCM with compression */
        _rMplvrMgr.fgInDCM = KAL_TRUE;
    }
    else
    {
        ASSERT(0);
    }
#endif  // __VE_DCM_WITH_COMPRESSION__

    kal_trace(TRACE_GROUP_10, MPLVR_TRC_SYS_CONSTRUCT, _rMplvrMgr.eState);

    _MPLVR_CreateEvent();

#ifdef __VE_DCM_WITH_COMPRESSION__
    fgInDCM = _rMplvrMgr.fgInDCM;
#endif  // __VE_DCM_WITH_COMPRESSION__
    eEvent = _rMplvrMgr.eEvent;     // backup
    kal_mem_set((void*)&_rMplvrMgr, 0, sizeof(_rMplvrMgr));
    _rMplvrMgr.eEvent = eEvent;     // restore
#ifdef __VE_DCM_WITH_COMPRESSION__
    _rMplvrMgr.fgInDCM = fgInDCM;
#endif  // __VE_DCM_WITH_COMPRESSION__

    // _rMplvrMgr.eState = MPLVR_STATE_CLOSED;  // Not needed because of mem_set().
    _rMplvrMgr.prClient = prMplvrClient;

    _rMplvrMgr.prInterface = (mpl_recorder_t*)&_rMplApi;
}


/*****************************************************************************
* Context: MED
*****************************************************************************/
mpl_recorder_t* construct_mp4_recorder(mpl_recorder_client_t *prMplvrClient)
{
    _MPLVR_ConstructRecorder(prMplvrClient);

    _rMplvrMgr.eMuxerContainerType = MUXER_CONTAINER_MP4;
    _rMplvrMgr.fgDirectCoupledSensor = KAL_FALSE;

    return _rMplvrMgr.prInterface;
}


/*****************************************************************************
* Context: MED
*****************************************************************************/
mpl_recorder_t* construct_avi_recorder(mpl_recorder_client_t *prMplvrClient)
{
    _MPLVR_ConstructRecorder(prMplvrClient);

    _rMplvrMgr.eMuxerContainerType = MUXER_CONTAINER_AVI;
#if defined(__VE_MJPEG_DIRECT_COUPLED_SENSOR__)
    _rMplvrMgr.fgDirectCoupledSensor = KAL_TRUE;
#else
    _rMplvrMgr.fgDirectCoupledSensor = KAL_FALSE;
#endif  // defined(__VE_MJPEG_DIRECT_COUPLED_SENSOR__)

    return _rMplvrMgr.prInterface;
}

/*****************************************************************************
* Context: MED
*****************************************************************************/
#ifdef __VE_STREAM_SERVER_SUPPORT__
mpl_recorder_t* construct_rtp_recorder(mpl_recorder_client_t *prMplvrClient)
{
    _MPLVR_ConstructRecorder(prMplvrClient);

    _rMplvrMgr.eMuxerContainerType = MUXER_CONTAINER_RTP;
    return _rMplvrMgr.prInterface;
}
#endif

/*****************************************************************************
* med_task_main() ---> med_main() ---> vid_main() --->
* mp4_recorder_timeout_hdlr() ---> mp4_recorder_check_record_limit_cyclic()
*
* Context: MED
*****************************************************************************/
void mp4_recorder_main(ilm_struct *prIlm)
{
    MPLVR_TRACE(TRACE_GROUP_10, MPLVR_TRC_MP4_MAIN);

    switch (prIlm->msg_id)
    {
        case MSG_ID_MEDIA_MP4_RECORDER_ASYNC_CALLBACK_REQ:
            _MPLVR_AsyncCallDispatcher(prIlm);
            break;
    }
}


/*****************************************************************************
*
*****************************************************************************/
void avi_recorder_main(ilm_struct *prIlm)
{
    MPLVR_TRACE(TRACE_GROUP_10, MPLVR_TRC_AVI_MAIN);

    switch(prIlm->msg_id)
    {
        case MSG_ID_MEDIA_AVI_RECORDER_ASYNC_CALLBACK_REQ:
            _MPLVR_AsyncCallDispatcher(prIlm);
            break;
    }
}

/*****************************************************************************
*
*****************************************************************************/
#ifdef __VE_STREAM_SERVER_SUPPORT__
void rtp_recorder_main(ilm_struct *prIlm)
{
    switch(prIlm->msg_id)
    {
        case MSG_ID_MEDIA_RTP_RECORDER_ASYNC_CALLBACK_REQ:
            _MPLVR_AsyncCallDispatcher(prIlm);
            break;
    }
}
#endif

#endif /* #if defined(__VIDEO_ARCHI_V2__) && (defined(MP4_ENCODE) || defined(MJPG_ENCODE)) */

