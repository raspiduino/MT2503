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
 *   video_encoder_component_v2.c
 *
 * Project:
 * --------
 *	MTK
 *
 * Description:
 * ------------
 *
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
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *
 ****************************************************************************/
#include "drv_comm.h"
#include "drv_features_video.h"
#ifdef __VE_DCM_WITH_COMPRESSION__
#include "dcmgr.h"
#pragma arm section code = "DYNAMIC_CODE_VEENC_ROCODE", rodata = "DYNAMIC_CODE_VEENC_RODATA"
#endif
#if defined(__VE_VIDEO_ARCHI_V2__)
#if defined(__VE_SUPPORT_ENCODER__)

#include "kal_release.h"      /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       /* Task message communiction */
#include "video_comm_v2.h"     /* for video_get_current_time() and video_get_duration_ms() */
#include "cache_sw.h"

#include "video_types_v2.h"
#include "video_encoder_component_v2.h"
#include "video_buffer_management_v2.h"
#include "drv_gfx_stack_switch_manager.h"
#include "video_codec_if_v2.h"
#include "video_codec_type_v2.h"
#include "kal_trace.h"
#include "vcodec_v2_trc.h"
#include "video_codec_custom_setting_v2.h"
#include "video_comm_component_v2.h"
#include "video_encoder_component_if_v2.h"
#include "stack_config.h"
#include "stack_ltlcom.h"
#include "video_dbg_v2.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "hisr_config.h"
#include "video_codec_utility_v2.h"
#include "video_encoder_auxiliary_v2.h"
#include "video_codec_custom_setting_v2.h"

#include "video_dbg_v2.h"
#include "mpl_recorder.h"
#include "video_recorder_clock_utility_if_v2.h"

#if defined(__VE_VENC_DUMP_ENCODE_INFO__)
#include "fs_type.h"
#include "fs_func.h"
#include "Fs_errcode.h"
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

//#define __DEBUG_VIDEO_ENCODER__

#if defined(__DEBUG_VIDEO_ENCODER__)
    #define _ENCODER_ASSERT() do{ASSERT(0);}while(0)
    #define _ENCODER_TRACE(stmt) do{##stmt;}while(0)
#else
    #define _ENCODER_ASSERT() do{}while(0)
    #define _ENCODER_TRACE(stmt)  do{}while(0)
#endif

extern kal_uint32 INT_SwitchStackToRun(void *stack_start, kal_uint32 stack_size, kal_func_ptr func, kal_uint32 argc, ...);
VIDEO_ERROR_TYPE_T VideoEncoderEmptyThisBuffer(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader);

#define VIDEO_ENCODER_RESEND_FULL               1
#define VIDEO_ENCODER_RESEND_ABOUT_FULL         2
#define GUARD_PATTERN_LEN 4
#define ONE_SEC_IN_MICROSEC (1000000)
//static const char _aGuardPattern[GUARD_PATTERN_LEN] = "VENC";

#include "video_codec_schedule_control.h"
void VideoEncoderPaused(kal_uint8* pu1ReadPtr);
void VideoEncoderGenBistream(void);
void VideoEncoderReleaseYUV(kal_uint8 *pu1Buff);
static void _VideoEncoderSetupCodec(void);
/******************************************************************************
* Static global variable(s)
******************************************************************************/
static VIDEO_ENCODER_MGR_T rVideoEncoderMgr;
#if defined(__VE_VIDEO_VT_SUPPORT__)
static VIDEO_ENCODER_CHASSIS_T _rChassis;
static kal_uint8 *_pu1BitBuffer;
static kal_uint32 _u4AccumulatedBitBufferSize;
#endif  // __VE_VIDEO_VT_SUPPORT__

static kal_mutexid eMutex;

static void _VENCCheckCodecReturn(VIDEO_ENCODER_CODEC_ERROR_T eErr)
{
    if (VIDEO_ENCODER_CODEC_ERROR_NONE != eErr)
    {
        VIDEO_TRACE1_G10( VENC_ADAPT_ERROR, eErr);
        ASSERT(0);
    }
}

static kal_bool _VENC_BypassCodec(VIDEO_ENCODER_MGR_T* prMgr)
{
    if ((CODEC_NONE == prMgr->eCodec) ||(CODEC_MJPG_BYPASS == prMgr->eCodec))
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

static void _VideoEncOpenCodec(VIDEO_ENCODER_MGR_T* prMgr)
{
    VIDEO_ENCODER_CODEC_ERROR_T eRet = VIDEO_ENCODER_CODEC_ERROR_NONE;

    if (KAL_FALSE == _VENC_BypassCodec(prMgr))
    {
        if (VENC_CODEC_STATE_CLOSE == prMgr->eCodecState)
        {
            _VideoEncoderSetupCodec();
            // Encoder API initialization
            eRet = prMgr->prCodecAPI->pfnOpen();
            _VENCCheckCodecReturn(eRet);
            prMgr->eCodecState = VENC_CODEC_STATE_OPEN;
        }
    }
}

static void _VideoEncCloseCodec(VIDEO_ENCODER_MGR_T* prMgr)
{
    VIDEO_ENCODER_CODEC_ERROR_T eRet = VIDEO_ENCODER_CODEC_ERROR_NONE;

    if (KAL_FALSE == _VENC_BypassCodec(prMgr))
    {
        if (  (VENC_CODEC_STATE_DEINIT == prMgr->eCodecState)
            ||(VENC_CODEC_STATE_OPEN   == prMgr->eCodecState))
        {
            eRet = prMgr->prCodecAPI->pfnClose();
            _VENCCheckCodecReturn(eRet);
            prMgr->eCodecState = VENC_CODEC_STATE_CLOSE;
        }
    }
}


static void _VideoEncDeinitCodec(VIDEO_ENCODER_MGR_T* prMgr)
{
    VIDEO_ENCODER_CODEC_ERROR_T eRet = VIDEO_ENCODER_CODEC_ERROR_NONE;

    if (KAL_FALSE == _VENC_BypassCodec(prMgr))
    {
        if (VENC_CODEC_STATE_INIT == prMgr->eCodecState)
        {
            eRet = prMgr->prCodecAPI->pfnDeInit();
            _VENCCheckCodecReturn(eRet);
            prMgr->eCodecState = VENC_CODEC_STATE_DEINIT;
        }
    }
}

static void _VideoEncInitCodec(VIDEO_ENCODER_MGR_T* prMgr)
{
    VIDEO_ENCODER_CODEC_ERROR_T eRet = VIDEO_ENCODER_CODEC_ERROR_NONE;

    if (KAL_FALSE == _VENC_BypassCodec(prMgr))
    {
        if (   (VENC_CODEC_STATE_DEINIT == prMgr->eCodecState)
            || (VENC_CODEC_STATE_OPEN   == prMgr->eCodecState))
        {
            eRet = prMgr->prCodecAPI->pfnInit();
            _VENCCheckCodecReturn(eRet);
            prMgr->eCodecState = VENC_CODEC_STATE_INIT;
        }
    }
}

static void _VideoEncGetParam(VIDEO_ENCODER_MGR_T* prMgr, VIDEO_ENCODER_PARAM_TYPE_T eType, void *pParam)
{
    VIDEO_ENCODER_CODEC_ERROR_T rCodecErr = VIDEO_ENCODER_CODEC_ERROR_NONE;

    if (KAL_FALSE == _VENC_BypassCodec(prMgr))
    {
        rCodecErr = prMgr->prCodecAPI->pfnGetParameter(eType, pParam);
        if(VIDEO_ENCODER_CODEC_ERROR == rCodecErr)
        {
            ASSERT(0);
        }
    }
}

static void _VideoEncoderSetParam2AdaptDirect(VIDEO_ENCODER_PARAM_TYPE_T eParamType, void * pu1Param)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_CODEC_ERROR_T eRet;

    eRet = _prMgr->prCodecAPI->pfnSetParameter(eParamType, pu1Param);
    switch(eRet)
    {
    case VIDEO_ENCODER_CODEC_PARAM_NOT_SUPPORT:
        VIDEO_TRACE1_G10( VENC_PARAM_NOT_SUPPORT, eParamType);
    case VIDEO_ENCODER_CODEC_ERROR_NONE:
        break;
    default:
        ASSERT(0);
        break;
    }
}

void VideoEncoderSetParam2Adapt(VIDEO_ENCODER_PARAM_TYPE_T eParamType, void * pu1Param)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_ADAPT_SETTINGS_T* prSetting = &_prMgr->rAdaptSettings;

    switch(eParamType)
    {
    case VENC_PARAM_SHORT_HEADER:
        prSetting->fgShortHeader = *(kal_bool*)(pu1Param);
        break;
    case VENC_PARAM_WIDTH:
        prSetting->u4Width = *(kal_uint32*)(pu1Param);
        break;
    case VENC_PARAM_HEIGHT:
        prSetting->u4Height = *(kal_uint32*)(pu1Param);
        break;

    case VENC_PARAM_FRAME_RATE:
        prSetting->u4FrameRate = *(kal_uint32*)(pu1Param);
        break;

    case VENC_PARAM_QUALITY:
        prSetting->eQuality = *(VIDEO_ENCODER_QUALITY_T*)(pu1Param);
        break;
    case VENC_PARAM_CODEC_TYPE:
        prSetting->eCodecType = *(VIDEO_ENCODER_CODEC_T*)(pu1Param);
        break;


#if defined(__VE_VIDEO_VT_SUPPORT__)
    case VENC_PARAM_VT_RESTART:
        prSetting->fgVTRestart = *(kal_bool*)(pu1Param);
        break;
    case VENC_PARAM_BITRATE:
        prSetting->u4Bitrate = *(kal_uint32*)(pu1Param);
        break;
    case VENC_PARAM_MAX_PKG_SIZE:
        prSetting->u4PacketSize = *(kal_uint32*)(pu1Param);
        break;
    case VENC_PARAM_GEN_HEADER_FRM_RATE:
        prSetting->u4GenHeaderFrameRate = *(kal_uint32*)(pu1Param);
        break;
#endif

#if !defined(__VE_SLIM_PROJECT__)
    case VENC_PARAM_SYNC_INTERVAL:
        prSetting->u4SyncInternal = *(kal_uint32*)(pu1Param);
        break;
    case VENC_PARAM_ROTATE:
        prSetting->eRotateAngle = *(VIDEO_CODEC_ROTATE_ANGLE_T*)(pu1Param);
        break;
#endif


    default:
        _ENCODER_ASSERT();
        break;
    }

    return;
}

static void _VideoEncoderSetupAdapt(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_ADAPT_SETTINGS_T* prSetting = &_prMgr->rAdaptSettings;

    if (KAL_FALSE == _VENC_BypassCodec(_prMgr))
    {
        prSetting->rCallbacks.pfnEncoderPaused  = VideoEncoderPaused;
        prSetting->rCallbacks.pfnGenBitstream   = VideoEncoderGenBistream;
        prSetting->rCallbacks.pfnReleaseFrame   = VideoEncoderReleaseYUV;

        _VideoEncoderSetParam2AdaptDirect(VENC_PARAM_SHORT_HEADER,          (void *)(&prSetting->fgShortHeader));
        _VideoEncoderSetParam2AdaptDirect(VENC_PARAM_WIDTH,                 (void *)(&prSetting->u4Width));
        _VideoEncoderSetParam2AdaptDirect(VENC_PARAM_HEIGHT,                (void *)(&prSetting->u4Height));
        _VideoEncoderSetParam2AdaptDirect(VENC_PARAM_FRAME_RATE,            (void *)(&prSetting->u4FrameRate));
        _VideoEncoderSetParam2AdaptDirect(VENC_PARAM_QUALITY,               (void *)(&prSetting->eQuality));
        _VideoEncoderSetParam2AdaptDirect(VENC_PARAM_CODEC_TYPE,            (void *)(&prSetting->eCodecType ));
        _VideoEncoderSetParam2AdaptDirect(VENC_PARAM_SET_CALLBACK,          (void *)(&prSetting->rCallbacks));

#if defined(__VE_VIDEO_VT_SUPPORT__)
        _VideoEncoderSetParam2AdaptDirect(VENC_PARAM_VT_RESTART,            (void *)(&prSetting->fgVTRestart));
        _VideoEncoderSetParam2AdaptDirect(VENC_PARAM_BITRATE,               (void *)(&prSetting->u4Bitrate));
        _VideoEncoderSetParam2AdaptDirect(VENC_PARAM_MAX_PKG_SIZE,          (void *)(&prSetting->u4PacketSize));
        _VideoEncoderSetParam2AdaptDirect(VENC_PARAM_GEN_HEADER_FRM_RATE,   (void *)(&prSetting->u4GenHeaderFrameRate));
#endif

#if !defined(__VE_SLIM_PROJECT__)
        _VideoEncoderSetParam2AdaptDirect(VENC_PARAM_SYNC_INTERVAL,         (void *)(&prSetting->u4SyncInternal));
        _VideoEncoderSetParam2AdaptDirect(VENC_PARAM_ROTATE,                (void *)(&prSetting->eRotateAngle ));
#endif

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
/* under construction !*/
/* under construction !*/
#endif

static void _VideoEncoderCtrlMoveItem(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    if (VENC_CLEAN_AFTER_ENCODE == _prMgr->eCleanMode)
    {
        VCodecCtrlMoveItem(VCS_ENCODER);
    }
}

static void _VideoEncoderResetScheduler(void)
{
    kal_int32 i4RemainingJobs = 0;

    i4RemainingJobs = VCodecCtrlGetContinuousItemNum(VCS_ENCODER);
    if (i4RemainingJobs > 0)
    {
        VIDEO_TRACE1_G8( VENC_REMAIN_JOBS, i4RemainingJobs);
    }

    for ( ; i4RemainingJobs > 0; i4RemainingJobs--)
    {
        _VideoEncoderCtrlMoveItem();
    }
}

/******************************************************************************
* Check the size of some data structure again their associated values defined
* in the customization header file.
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderCheckSetting(VIDEO_ENCODER_CUSTOM_SETTINGS_T *prSetting)
{
    kal_int32 i4Line = 0;  // for easier debugging

    if (sizeof(VIDEO_COMM_CMD_PARAM_T) > prSetting->u4CmdQItemSize)
    {
        i4Line = __LINE__;
    }

    if (sizeof(VIDEO_BUFFERHEADER_TYPE_T) > prSetting->u4InputQItemSize)
    {
        i4Line = __LINE__;
    }

    if (sizeof(VIDEO_BUFFERHEADER_TYPE_T) > prSetting->u4OutputQItemSize)
    {
        i4Line = __LINE__;
    }

    if (sizeof(VIDEO_YUV_HEADER_T) > prSetting->u4YuvHeaderQItemSize)
    {
        i4Line = __LINE__;
    }

    if (sizeof(kal_uint64) > prSetting->u4TimeStampQItemSize)
    {
        i4Line = __LINE__;
    }

    if (VENC_COMMAND_Q_NUM != prSetting->u4CmdQNum)
    {
        i4Line = __LINE__;
    }

    if (VIDEO_ENCODER_INPUT_BUFFER_Q_NUM != prSetting->u4InputQNum)
    {
        i4Line = __LINE__;
    }

    if (VENC_OUTPUT_BUFFER_Q_NUM != prSetting->u4OutputQNum)
    {
        i4Line = __LINE__;
    }

    if (CPU_CACHE_LINE_SIZE != prSetting->u4CacheLineSize)
    {
        i4Line = __LINE__;
    }

    if (VIDEO_ENCODER_YUV_HEADER_Q_NUM != prSetting->u4YuvHeaderQNum)
    {
        i4Line = __LINE__;
    }

    if (VENC_TIME_STAMP_Q_NUM != prSetting->u4TimeStampQNum)
    {
        i4Line = __LINE__;
    }

#if 0
#ifdef __VIDEO_VT_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // __VIDEO_VT_SUPPORT__
#endif  // 0

    if (i4Line != 0)
    {
        EXT_ASSERT(0, i4Line, 0, 0);
    }
}


/******************************************************************************
* This function returns in byte the number of continuous empty space starting
* from the current Write pointer to either the buffer end or the Read pointer
* depending on the relationship between the Read and Write pointers.
*
* Note: The caller of this function must ensure that the buffer is not full
*       when this function is called.
*
* Side effect: none
******************************************************************************/
static kal_uint32 _VideoEncoderGetContinuousEmptySize(kal_uint32 u4BufferStart,
        kal_uint32 u4BufferEnd, kal_uint32 u4RP, kal_uint32 u4WP)
{
    kal_uint32 u4ContinuousEmptySize = 0;

    if (!((u4BufferStart <= u4RP) && (u4RP < u4BufferEnd)))
    {
        ASSERT(0);
    }
    if (!((u4BufferStart <= u4WP) && (u4WP < u4BufferEnd)))
    {
        ASSERT(0);
    }

    if (u4RP <= u4WP)
    {
        u4ContinuousEmptySize = u4BufferEnd - u4WP;
    }
    else  // (u4WP < u4RP)
    {
        u4ContinuousEmptySize = u4RP - u4WP;
    }

    return u4ContinuousEmptySize;
}


/******************************************************************************
* Initialize the "bit-stream buffer manager".
*
* PS, Consider making use of "const" for the first parameter.
*
* Side effect: "bit-stream buffer manager"
******************************************************************************/
static void _VideoEncoderInitBitstreamBuffer(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_BIT_BUFFER_T *prBitBufferMgr = &_prMgr->rBitBufferMgr;
    kal_uint8* pu1BufferStart = prBitBufferMgr->pu1BufferStart;  // It shall have been set.
    kal_uint32 const u4BufferSize = prBitBufferMgr->u4BufferSize;// - GUARD_PATTERN_LEN;
    kal_uint8* pu1BufferEnd = pu1BufferStart + u4BufferSize;
    kal_bool fgBSinCache = KAL_TRUE;
    kal_uint32 u4LeftOverOf1stCluster = prBitBufferMgr->u4LeftOverOf1stCluster;
    VIDEO_MEMORY_SWITCH_T eSwitchType;
    kal_uint8* pu1HeaderBuffer = prBitBufferMgr->pu1HeaderBuffer;

    _VideoEncGetParam(_prMgr, VENC_PARAM_BITSTREAM_IN_CACHE, (void*)(&fgBSinCache));

#if defined(__VE_DYNAMIC_SWITCH_CACHEABILITY__)
    eSwitchType = (KAL_TRUE == fgBSinCache)?(VIDEO_CACHEABLE):(VIDEO_NON_CACHEABLE);
    pu1BufferStart = (kal_uint8*)VideoCommExtBufferCacheableSwitch((kal_uint32)pu1BufferStart, u4BufferSize, eSwitchType);
    pu1BufferEnd = pu1BufferStart + u4BufferSize;
#endif

    kal_mem_set((void*)prBitBufferMgr, 0, sizeof(*prBitBufferMgr));
    prBitBufferMgr->u4LeftOverOf1stCluster = u4LeftOverOf1stCluster;

    if ((pu1BufferStart == NULL) || (u4BufferSize == 0))
    {
        ASSERT(0);
        return;
    }

    prBitBufferMgr->u4BufferSize = u4BufferSize;
    prBitBufferMgr->pu1BufferStart = pu1BufferStart;
    prBitBufferMgr->pu1BufferEnd = pu1BufferEnd;
    // For recorder, IL client should set this value to have best efficiency on file writing
    // Normally (32k - 32) Bytes
    if (0 != prBitBufferMgr->u4LeftOverOf1stCluster)
    {
        prBitBufferMgr->pu1RP = prBitBufferMgr->pu1BufferEnd
                                - prBitBufferMgr->u4LeftOverOf1stCluster;
        prBitBufferMgr->pu1WP = prBitBufferMgr->pu1RP;
    }
    else
    {
        prBitBufferMgr->pu1RP = pu1BufferStart;
        prBitBufferMgr->pu1WP = pu1BufferStart;
    }
    prBitBufferMgr->pu1HeaderBuffer = pu1HeaderBuffer;

    // The following lines are not needed because kal_mem_set() is used above.
    // prBitBufferMgr->u4Zombie = 0;
    // prBitBufferMgr->u4WriteCounter = 0;
    // prBitBufferMgr->u4ReadCounter = 0;
    // prBitBufferMgr->u4ScarceCounter = 0;
    // prBitBufferMgr->fgIsBufferFull = KAL_FALSE;

    //Insert guard pattern to prevent codec write bitstream out-of-boundary
    //_VideoEncodeInsertGuardPattern(prBitBufferMgr->pu1BufferEnd + 1);

    VIDEO_TRACE2_G8( VENC_BIT_BUFFER_INIT, (kal_uint32)pu1BufferStart,
        (kal_uint32)pu1BufferEnd);
}




/******************************************************************************
* If the bit-stream buffer is full, return TRUE.  Othrewise, return FALSE.
*
* Side effect: none
******************************************************************************/
static kal_bool _VideoEncoderIsBitstreamBufferFull(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    kal_uint32 u4SavedMask;  // HISR_protection
    kal_bool fgIsBufferFull;  // HISR_protection

    u4SavedMask = SaveAndSetIRQMask();  // HISR_protection
    fgIsBufferFull = _prMgr->rBitBufferMgr.fgIsBufferFull;  // HISR_protection
    RestoreIRQMask(u4SavedMask);  // HISR_protection

    return fgIsBufferFull;
}


// HISR_protection
/******************************************************************************
* Record the peak size of the bit-stream buffer.
*
* The variable u4PeakSize is updated only in the Encoder main loop.  There is
* no need to protect it.
*
* Side effect:
******************************************************************************/
static void _VideoEncoderRecordPeakBitBufferSize(kal_uint32 u4BuffStart,
        kal_uint32 u4BuffEnd, kal_uint32 u4RP, kal_uint32 u4WP)
{
#if defined(__VE_VENC_PROFILING_BITSTREAM__)
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_BIT_BUFFER_T* const prBitBufferMgr = &_prMgr->rBitBufferMgr;
    kal_uint32 u4BuffSize, u4PeakSize, u4NewSize;

    u4PeakSize = prBitBufferMgr->u4PeakSize;
    u4BuffSize = u4BuffEnd - u4BuffStart;

    if (!((u4BuffStart <= u4RP) && (u4RP < u4BuffEnd)))
    {
        ASSERT(0);
    }
    if (!((u4BuffStart <= u4WP) && (u4WP < u4BuffEnd)))
    {
        ASSERT(0);
    }

    if (u4RP <= u4WP)
    {
        u4NewSize = u4WP - u4RP;
    }
    else  // (u4WP < u4RP)
    {
        u4NewSize = u4BuffSize - (u4RP - u4WP);
    }

    if (u4NewSize > u4PeakSize)
    {
        prBitBufferMgr->u4PeakSize = u4NewSize;
    }
#endif //(__VE_VENC_PROFILING_BITSTREAM__)
}
// HISR_protection


/******************************************************************************
* Check the pointer value passed into this function against the Read pointer of
* the bit-stream buffer.
*
* The variable u4RP is updated only in the Encoder main loop.  There is no need
* to protect it.
*
* Side effect: none
******************************************************************************/
static void _VideoEncoderCheckBitstreamRP(kal_uint8 *pu1RP)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_BIT_BUFFER_T* const prBitBufferMgr = &_prMgr->rBitBufferMgr;
    kal_uint32 u4BuffStart, u4BuffEnd, u4RP, u4Zombie;

    u4BuffStart = (kal_uint32)prBitBufferMgr->pu1BufferStart;
    u4BuffEnd = (kal_uint32)prBitBufferMgr->pu1BufferEnd;
    u4RP = (kal_uint32)prBitBufferMgr->pu1RP;

    u4Zombie = prBitBufferMgr->u4Zombie;

    if (u4RP == (kal_uint32)pu1RP)
    {
        return;
    }

    u4RP += u4Zombie;
    if (u4RP >= u4BuffEnd)
    {
        u4RP -= u4BuffEnd - u4BuffStart;
        if (u4RP == (kal_uint32)pu1RP)
        {
            return;
        }
    }

    VIDEO_TRACE2_G10( VENC_BIT_ADDR_DIFF, u4RP, (kal_uint32)pu1RP);

    ASSERT(0);
}

kal_uint32 VideoEncoderGetBitstreamBufferAvailableSize(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_BIT_BUFFER_T* const prBitBufferMgr = &_prMgr->rBitBufferMgr;
    kal_uint32 u4BuffStart, u4BuffEnd, u4RP, u4WP;
    kal_uint32 u4SavedMask;  // HISR_protection
    kal_uint32 u4ContinuousEmptySize = 0;

    u4BuffStart = (kal_uint32)prBitBufferMgr->pu1BufferStart;
    u4BuffEnd = (kal_uint32)prBitBufferMgr->pu1BufferEnd;

    u4SavedMask = SaveAndSetIRQMask();  // HISR_protection
    u4RP = (kal_uint32)prBitBufferMgr->pu1RP;
    u4WP = (kal_uint32)prBitBufferMgr->pu1WP;
    RestoreIRQMask(u4SavedMask);  // HISR_protection

    if (!((u4BuffStart <= u4RP) && (u4RP < u4BuffEnd)))
    {
        ASSERT(0);
    }
    if (!((u4BuffStart <= u4WP) && (u4WP < u4BuffEnd)))
    {
        ASSERT(0);
    }

    u4ContinuousEmptySize = _VideoEncoderGetContinuousEmptySize(u4BuffStart,u4BuffEnd, u4RP, u4WP);

    return u4ContinuousEmptySize;
}

/******************************************************************************
* The entire empty size in the bit-stream buffer is calculated and returned.
*
* Side effect:
******************************************************************************/
static void _VideoEncoderSetBitBufferState(VENC_BIT_BUFFER_STATE_T eState)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_BIT_BUFFER_T* prBitBufferMgr = &_prMgr->rBitBufferMgr;
    prBitBufferMgr->eState = eState;
    return;
}

void VideoEncoderAllocateBitstreamBuffer(
    kal_uint8** ppu1StartAddr,
    kal_uint8** ppu1EndAddr,
    kal_uint8** ppu1WriteAddr,
    kal_uint8** ppu1ReadAddr,
    kal_uint32* pu4BufferLength
    )
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_BIT_BUFFER_T* const prBitBufferMgr = &_prMgr->rBitBufferMgr;
    kal_uint32 u4BuffStart, u4BuffEnd, u4RP, u4WP;
    kal_uint32 u4SavedMask;  // HISR_protection
    kal_uint32 u4ContinuousEmptySize = 0;
    kal_bool fgIsBufferFull = prBitBufferMgr->fgIsBufferFull;

    if (VENC_BITBUFF_BITSTREAM == prBitBufferMgr->eState)
    {
        u4BuffStart = (kal_uint32)prBitBufferMgr->pu1BufferStart;
        u4BuffEnd = (kal_uint32)prBitBufferMgr->pu1BufferEnd;

        u4SavedMask = SaveAndSetIRQMask();  // HISR_protection
        u4RP = (kal_uint32)prBitBufferMgr->pu1RP;
        u4WP = (kal_uint32)prBitBufferMgr->pu1WP;

        RestoreIRQMask(u4SavedMask);  // HISR_protection

        if (!((u4BuffStart <= u4RP) && (u4RP < u4BuffEnd)))
        {
            ASSERT(0);
        }
        if (!((u4BuffStart <= u4WP) && (u4WP < u4BuffEnd)))
        {
            ASSERT(0);
        }

        u4ContinuousEmptySize = _VideoEncoderGetContinuousEmptySize(u4BuffStart,u4BuffEnd, u4RP, u4WP);

        *ppu1StartAddr      =   prBitBufferMgr->pu1BufferStart;
        *ppu1EndAddr        =   prBitBufferMgr->pu1BufferEnd;
        *ppu1WriteAddr      =   (kal_uint8*)u4WP;
        *ppu1ReadAddr       =   (kal_uint8*)u4RP;
        *pu4BufferLength    =   prBitBufferMgr->u4BufferSize;
    }
    else if (VENC_BITBUFF_HEADER== prBitBufferMgr->eState)
    {
        *ppu1StartAddr      =   prBitBufferMgr->pu1HeaderBuffer;
        *ppu1EndAddr        =   prBitBufferMgr->pu1HeaderBuffer + (HEADER_BUFFER_SIZE - 1);
        *ppu1WriteAddr      =   *ppu1StartAddr;
        *ppu1ReadAddr       =   *ppu1StartAddr;
        *pu4BufferLength    =   (HEADER_BUFFER_SIZE - 1);
    }
    else
    {
        ASSERT(0);
    }

    VIDEO_TRACE4_G9( VENC_BIT_BUFFER_ALLOCATE, (kal_uint32)(*ppu1ReadAddr), (kal_uint32)(*ppu1WriteAddr),  (u4ContinuousEmptySize), fgIsBufferFull);
}

void VideoEncoderQueryBitstreamNewWP
(
    kal_uint8  *pu1WP,       //the newWP ready to write to, which would contain data we assumed
    kal_uint8 **ppu1NextWP,
    kal_uint32 *pu4AvialbleLength
)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_BIT_BUFFER_T* const prBitBufferMgr = &_prMgr->rBitBufferMgr;
    kal_uint32 u4BuffStart, u4BuffEnd, u4RP, u4WP;
    kal_uint32 u4SavedMask;  // HISR_protection
    kal_uint32 u4NewWP = (kal_uint32)pu1WP;
    kal_bool fgIsBufferFull;  // HISR_protection
    kal_uint32 u4ContinuousEmptySize = 0;

    u4BuffStart = (kal_uint32)prBitBufferMgr->pu1BufferStart;
    u4BuffEnd = (kal_uint32)prBitBufferMgr->pu1BufferEnd;

    u4SavedMask = SaveAndSetIRQMask();  // HISR_protection
    u4RP = (kal_uint32)prBitBufferMgr->pu1RP;
    u4WP = (kal_uint32)prBitBufferMgr->pu1WP;
    fgIsBufferFull = prBitBufferMgr->fgIsBufferFull;  // HISR_protection
    RestoreIRQMask(u4SavedMask);  // HISR_protection

    if (!((u4BuffStart <= u4NewWP) && (u4NewWP <= u4BuffEnd)))
    {
        ASSERT(0);
    }

    // assumed a data is written, return the next new WP
    {
        if (u4RP == u4WP)
        {
            if (fgIsBufferFull == KAL_TRUE)  // HISR_protection
            {
                ASSERT(0);
                return;
            }

            // Make sure: ((u4WP <= u4NewWP) && (u4NewWP <= u4BuffEnd))
            if ((u4NewWP < u4WP) || (u4BuffEnd < u4NewWP))
            {
                ASSERT(0);
                return;
            }
        }
        else if (u4RP < u4WP)
        {
            // Make sure: ((u4WP < u4NewWP) && (u4NewWP <= u4BuffEnd))
            if ((u4NewWP <= u4WP) || (u4BuffEnd < u4NewWP))
            {
                ASSERT(0);
                return;
            }
        }
        else  // (WP < RP)
        {
            // Make sure: ((u4WP < u4NewWP) && (u4NewWP <= u4RP))
            if ((u4NewWP <= u4WP) || (u4RP < u4NewWP))
            {
                ASSERT(0);
                return;
            }
        }
    }

    if (u4NewWP == u4BuffEnd)
    {
        u4NewWP = u4BuffStart;
    }

    VIDEO_TRACE4_G9( VENC_BIT_BUFFER_QUERY_WP,
        u4RP, u4WP, u4NewWP, (kal_uint32)fgIsBufferFull);

    *ppu1NextWP = (kal_uint8*)(u4NewWP);

    u4BuffStart = (kal_uint32)prBitBufferMgr->pu1BufferStart;
    u4BuffEnd = (kal_uint32)prBitBufferMgr->pu1BufferEnd;

    u4SavedMask = SaveAndSetIRQMask();  // HISR_protection
    u4RP = (kal_uint32)prBitBufferMgr->pu1RP;
    u4WP = (kal_uint32)(*ppu1NextWP);
    if (u4RP == u4WP)
    {
        fgIsBufferFull = KAL_TRUE;
    }
    RestoreIRQMask(u4SavedMask);  // HISR_protection

    if (!((u4BuffStart <= u4RP) && (u4RP < u4BuffEnd)))
    {
        ASSERT(0);
    }
    if (!((u4BuffStart <= u4WP) && (u4WP < u4BuffEnd)))
    {
        ASSERT(0);
    }

    if (fgIsBufferFull == KAL_TRUE)
    {
        u4ContinuousEmptySize = 0;
    }
    else
    {
        u4ContinuousEmptySize = _VideoEncoderGetContinuousEmptySize(u4BuffStart,
               u4BuffEnd, u4RP, u4WP);
    }

    // When contiunous emptysize equals buffersize, meaning that the RP == WP and they are both at the beginning of the buffer
    // Assumed that our buffer is not empty at this time, return available length == 0
    if (u4ContinuousEmptySize == prBitBufferMgr->u4BufferSize)
    {
        u4ContinuousEmptySize = 0;
    }

    *pu4AvialbleLength = u4ContinuousEmptySize;

    VIDEO_TRACE2_G9( VENC_BIT_BUFFER_FREE_SIZE, (*pu4AvialbleLength), fgIsBufferFull);

}

/******************************************************************************
* Update the Write pointer of the bit-stream buffer.
* This function allows the new WP to be the same as the original WP.
*
* Side effect:
******************************************************************************/
void VideoEncoderUpdateBitstreamWP(kal_uint8 *pu1WP, kal_int32 is_slice_contained)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_BIT_BUFFER_T* const prBitBufferMgr = &_prMgr->rBitBufferMgr;
    kal_uint32 u4BuffStart, u4BuffEnd, u4RP, u4WP, u4Zombie, u4WriteCounter;
    kal_uint32 u4SavedMask;  // HISR_protection
    kal_uint32 u4NewWP = (kal_uint32)pu1WP;
    const kal_int32 NO_DATA_WRITTEN = 0;
    kal_bool fgIsBufferFull, fgUpdateZombie = KAL_FALSE;  // HISR_protection

    // ignore the bitstream update for header buffer
    if (VENC_BITBUFF_HEADER== prBitBufferMgr->eState)
    {
        kal_uint32  u4BufferEnd = (kal_uint32)(prBitBufferMgr->pu1HeaderBuffer + (HEADER_BUFFER_SIZE - 1));
        if (!(u4NewWP <= u4BufferEnd))
        {
            ASSERT(0);
        }
        return;
    }

    u4BuffStart = (kal_uint32)prBitBufferMgr->pu1BufferStart;
    u4BuffEnd = (kal_uint32)prBitBufferMgr->pu1BufferEnd;

    u4SavedMask = SaveAndSetIRQMask();  // HISR_protection
    u4RP = (kal_uint32)prBitBufferMgr->pu1RP;
    u4WP = (kal_uint32)prBitBufferMgr->pu1WP;
    fgIsBufferFull = prBitBufferMgr->fgIsBufferFull;  // HISR_protection
    u4Zombie = prBitBufferMgr->u4Zombie;
    RestoreIRQMask(u4SavedMask);  // HISR_protection

    if (!((u4BuffStart <= u4NewWP) && (u4NewWP <= u4BuffEnd)))
    {
        ASSERT(0);
    }

    if (is_slice_contained == NO_DATA_WRITTEN)
    {
        if (u4RP == u4WP)  // The buffer was empty.
        {
            if (u4NewWP == u4WP)
            {
                // FIXME (Leroy): also print u4Zombie
                VIDEO_TRACE4_G9( VENC_BIT_BUFFER_UPDATE_WP, u4RP, u4WP,
                    u4NewWP, (kal_uint32)fgIsBufferFull);  // HISR_protection
                return;
            }

            if (fgIsBufferFull == KAL_TRUE)     // HISR_protection
            {
                ASSERT(0);
                return;
            }
            if (u4Zombie == 0)
            {
                u4Zombie = u4BuffEnd - u4WP;    // HISR_protection
                fgUpdateZombie = KAL_TRUE;      // HISR_protection
            }
            else
            {
                // Two or more zombies are not allowed.
                ASSERT(0);
                return;
            }
        }
        else if (u4RP < u4WP)
        {
            // Make sure: ((u4WP < u4NewWP) && (u4NewWP <= u4BuffEnd))
            if ((u4NewWP <= u4WP) || (u4BuffEnd < u4NewWP))
            {
                ASSERT(0);
                return;
            }

            if (u4Zombie == 0)
            {
                if (u4NewWP != u4BuffEnd)
                {
                    ASSERT(0);
                    return;
                }
                u4Zombie = u4BuffEnd - u4WP;    // HISR_protection
                fgUpdateZombie = KAL_TRUE;      // HISR_protection
            }
            else
            {
                // Two or more zombies are not allowed.
                ASSERT(0);
                return;
            }
        }
        else  // (WP < RP)
        {
            // Do not update WP in such case!
            // Set the flag fgIsBufferFull to avoid the same case occurring repeatedly.
            // Do not update "u4Zombie" here.

            // Make sure: ((u4WP < u4NewWP) && (u4NewWP <= u4RP))
            if ((u4NewWP <= u4WP) || (u4RP < u4NewWP))
            {
                ASSERT(0);
                return;
            }

            fgIsBufferFull = KAL_TRUE;  // HISR_protection
#if defined(__VE_VENC_PROFILING_BITSTREAM__)
            prBitBufferMgr->u4ScarceCounter++;
#endif //(__VE_VENC_PROFILING_BITSTREAM__)
            u4NewWP = u4WP;  // Do not move WP to avoid bubble(s) in the buffer.
        }
        u4WriteCounter = 0;
    }
    else
    {
        if (u4RP == u4WP)
        {
            if (fgIsBufferFull == KAL_TRUE)  // HISR_protection
            {
                ASSERT(0);
                return;
            }

            // Make sure: ((u4WP <= u4NewWP) && (u4NewWP <= u4BuffEnd))
            if ((u4NewWP < u4WP) || (u4BuffEnd < u4NewWP))
            {
                ASSERT(0);
                return;
            }
        }
        else if (u4RP < u4WP)
        {
            // Make sure: ((u4WP < u4NewWP) && (u4NewWP <= u4BuffEnd))
            if ((u4NewWP <= u4WP) || (u4BuffEnd < u4NewWP))
            {
                ASSERT(0);
                return;
            }
        }
        else  // (WP < RP)
        {
            // Make sure: ((u4WP < u4NewWP) && (u4NewWP <= u4RP))
            if ((u4NewWP <= u4WP) || (u4RP < u4NewWP))
            {
                ASSERT(0);
                return;
            }
        }
        u4WriteCounter = u4NewWP - u4WP;
    }

    if (u4NewWP == u4BuffEnd)
    {
        u4NewWP = u4BuffStart;
        VIDEO_TRACE0_G9( VENC_BIT_BUFFER_UPDATE_WP_TO_END);
    }

    if (((u4NewWP == u4RP) && (u4WriteCounter != 0)) ||
        ((u4NewWP == u4RP) && (u4RP != u4WP)))
    {
        fgIsBufferFull = KAL_TRUE;  // HISR_protection
#if defined(__VE_VENC_PROFILING_BITSTREAM__)
        prBitBufferMgr->u4ScarceCounter++;
#endif //(__VE_VENC_PROFILING_BITSTREAM__)
    }

    u4SavedMask = SaveAndSetIRQMask();  // HISR_protection
    prBitBufferMgr->fgIsBufferFull = fgIsBufferFull;  // HISR_protection
    if (fgUpdateZombie == KAL_TRUE)             // HISR_protection
    {                                           // HISR_protection
        prBitBufferMgr->u4Zombie = u4Zombie;    // HISR_protection
    }                                           // HISR_protection
    prBitBufferMgr->pu1WP = (kal_uint8*)u4NewWP;       // Update WP
    RestoreIRQMask(u4SavedMask);  // HISR_protection

#if defined(__VE_VENC_PROFILING_BITSTREAM__)
    prBitBufferMgr->u4WriteCounter += u4WriteCounter;  // for debugging
#endif //(__VE_VENC_PROFILING_BITSTREAM__)

    // FIXME (Leroy): also print u4Zombie
    VIDEO_TRACE4_G9( VENC_BIT_BUFFER_UPDATE_WP,
        u4RP, u4WP, u4NewWP, (kal_uint32)fgIsBufferFull);  // HISR_protection
}


/******************************************************************************
* After the specified number (u4ConsumedByte) of bytes has been read, this
* function will be invoked to adjust the Read pointer to a new position.
* Care must be taken to ensure that the new Read pointer is within the valid
* range.
*
* Side effect:
******************************************************************************/
void VideoEncoderUpdateBitstreamRP(kal_uint8* pu1Buffer, kal_uint32 u4UpdateLen)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_BIT_BUFFER_T* const prBitBufferMgr = &_prMgr->rBitBufferMgr;
    kal_uint32 u4BuffStart, u4BuffEnd, u4RP, u4WP, u4NewRP, u4BuffSize, u4Zombie;
    kal_uint32 u4SavedMask;  // HISR_protection
    kal_bool fgIsBufferFull, fgUpdateZombie = KAL_FALSE;  // HISR_protection

    _VideoEncoderCheckBitstreamRP(pu1Buffer);

    // ignore the bitstream update for header buffer
    if (VENC_BITBUFF_HEADER== prBitBufferMgr->eState)
    {
        return;
    }

    u4BuffStart = (kal_uint32)prBitBufferMgr->pu1BufferStart;
    u4BuffEnd = (kal_uint32)prBitBufferMgr->pu1BufferEnd;

    u4SavedMask = SaveAndSetIRQMask();  // HISR_protection
    u4RP = (kal_uint32)prBitBufferMgr->pu1RP;
    u4WP = (kal_uint32)prBitBufferMgr->pu1WP;
    u4Zombie = prBitBufferMgr->u4Zombie;
    fgIsBufferFull = prBitBufferMgr->fgIsBufferFull;  // HISR_protection
    RestoreIRQMask(u4SavedMask);  // HISR_protection

    u4BuffSize = u4BuffEnd - u4BuffStart;

    _VideoEncoderRecordPeakBitBufferSize(u4BuffStart, u4BuffEnd, u4RP, u4WP);  // for debugging, HISR_protection

    u4NewRP = u4RP + u4UpdateLen;  // The range of u4NewRP is checked below.

    if (u4UpdateLen == 0)
    {
        ASSERT(0);
        return;
    }

    if (u4RP == u4WP)  // The buffer was full.
    {
        if (fgIsBufferFull == KAL_FALSE)
        {
            ASSERT(0);
            return;
        }

        if (u4Zombie != 0)
        {
            if ((u4NewRP + u4Zombie) >= u4BuffEnd)
            {
                u4NewRP += u4Zombie;
                u4NewRP -= u4BuffSize;
                u4Zombie = 0;               // HISR_protection
                fgUpdateZombie = KAL_TRUE;  // HISR_protection

                VIDEO_TRACE2_G9( VENC_BIT_BUFFER_RESET_ZOMBIE, u4Zombie, __LINE__);
            }
        }
        else
        {
            if (u4NewRP >= u4BuffEnd)
            {
                u4NewRP -= u4BuffSize;
            }
        }

        // Make sure: (u4BuffStart <= u4NewRP) && (u4NewRP < u4BuffEnd)
        if ((u4NewRP < u4BuffStart) || (u4BuffEnd <= u4NewRP))
        {
            ASSERT(0);
            return;
        }
    }
    else if (u4RP < u4WP)
    {
        // Make sure: (u4RP < u4NewRP) && (u4NewRP <= u4WP)
        if ((u4NewRP <= u4RP) || (u4WP < u4NewRP))
        {
            ASSERT(0);
            return;
        }
    }
    else  // (WP < RP)
    {
        if (u4Zombie != 0)
        {
            if ((u4NewRP + u4Zombie) >= u4BuffEnd)
            {
                u4NewRP += u4Zombie;
                u4NewRP -= u4BuffSize;
                u4Zombie = 0;               // HISR_protection
                fgUpdateZombie = KAL_TRUE;  // HISR_protection

                VIDEO_TRACE2_G9( VENC_BIT_BUFFER_RESET_ZOMBIE, u4Zombie, __LINE__);
            }
        }
        else
        {
            if (u4NewRP >= u4BuffEnd)
            {
                u4NewRP -= u4BuffSize;
            }
        }

        // Make sure: ((u4RP < u4NewRP) && (u4NewRP < u4BuffEnd)) ||
        //            ((u4BuffStart <= u4NewRP) && (u4NewRP <= u4WP))
        if ((u4NewRP < u4BuffStart) || (u4NewRP >= u4BuffEnd) ||
            ((u4WP < u4NewRP) && (u4NewRP <= u4RP)))
        {
            ASSERT(0);
            return;
        }
    }

    u4SavedMask = SaveAndSetIRQMask();          // HISR_protection
    prBitBufferMgr->pu1RP = (kal_uint8*)u4NewRP;    // Update RP
    prBitBufferMgr->fgIsBufferFull = KAL_FALSE;
    if (fgUpdateZombie == KAL_TRUE)             // HISR_protection
    {                                           // HISR_protection
        prBitBufferMgr->u4Zombie = u4Zombie;    // HISR_protection
    }                                           // HISR_protection
    RestoreIRQMask(u4SavedMask);                // HISR_protection

#if defined(__VE_VENC_PROFILING_BITSTREAM__)
    prBitBufferMgr->u4ReadCounter += u4UpdateLen;   // for debugging
#endif //(__VE_VENC_PROFILING_BITSTREAM__)

    // FIXME (Leroy): also print u4Zombie
    VIDEO_TRACE4_G9( VENC_BIT_BUFFER_UPDATE_RP, u4RP, u4WP, u4UpdateLen, u4NewRP);
}


/******************************************************************************
*
* Side effect:
******************************************************************************/
static void _VideoEncoderBitstreamSetFullFlag(kal_bool fgFull)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    _prMgr->rBitBufferMgr.fgIsBufferFull = fgFull;  // FIXME (Leroy): Need protection.
}

#if defined(__VE_VIDEO_VT_SUPPORT__)
/******************************************************************************
* Init the chassis manager.
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderInitChassisMgr(void)
{
#if defined(__VE_VIDEO_VT_SUPPORT__)
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_CHASSIS_MGR_T *prChassisMgr = &_prMgr->rChassisMgr;
    kal_uint32 u4BufferSize = prChassisMgr->u4BufferSize;

    prChassisMgr->prChassisRp = prChassisMgr->prChassisStart;
    prChassisMgr->prChassisWp = prChassisMgr->prChassisStart;
    prChassisMgr->u4UsedChassis = 0;
    prChassisMgr->u4BufferSize = u4BufferSize;

    kal_mem_set((void*)prChassisMgr->prChassisStart, 0, prChassisMgr->u4BufferSize);
#endif  // __VE_VIDEO_VT_SUPPORT__
}


/******************************************************************************
* De-init the chassis manager.
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderDeInitChassisMgr(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_CHASSIS_MGR_T *prChassisMgr = &_prMgr->rChassisMgr;
    kal_mem_set((void*)prChassisMgr, 0, sizeof(*prChassisMgr));

}


/******************************************************************************
* Insert a chassis into the chassis manager.
*
* Return value: the address of the item where the input data is written to.
*
* Context:
*
* Side effect:
******************************************************************************/
static VIDEO_ENCODER_CHASSIS_T* _VideoEncoderInsertChassis(VIDEO_ENCODER_CHASSIS_T *prSrcChassis)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_CHASSIS_MGR_T *prChassisMgr = &_prMgr->rChassisMgr;
    VIDEO_ENCODER_CHASSIS_T *prChassisRet, *prChassisWp;
    kal_uint32 u4Idx;

    if ((prChassisMgr->u4UsedChassis + 1) == prChassisMgr->u4MaxChassis)
    {
        ASSERT(0);
        return NULL;
    }

    prChassisRet = prChassisMgr->prChassisWp;
    if (prChassisRet->eChassisStatus != VIDEO_ENCODER_CHASSIS_FREE)
    {
        ASSERT(0);
        return NULL;
    }

    for (u4Idx = 0; u4Idx < prSrcChassis->u4NumOfPkts; u4Idx++)
    {
        prChassisRet->arPktInfo[u4Idx] = prSrcChassis->arPktInfo[u4Idx];
    }
    prChassisRet->u4NumOfPkts = prSrcChassis->u4NumOfPkts;
    prChassisRet->parPktInfo = prChassisRet->arPktInfo;
    prChassisRet->eChassisStatus = VIDEO_ENCODER_CHASSIS_IN_USE;

    prChassisMgr->u4UsedChassis++;  // Bookkeeping

    // Update WP
    prChassisWp = prChassisRet + 1;
    if (prChassisWp >= prChassisMgr->prChassisEnd)
    {
        prChassisWp = prChassisMgr->prChassisStart;
    }
    prChassisMgr->prChassisWp = prChassisWp;

    VIDEO_TRACE4_G8( VENC_CHASSIS_INSERT, (kal_uint32)prChassisRet,
        prChassisRet->u4NumOfPkts, (kal_uint32)prChassisRet->parPktInfo,
        prChassisMgr->u4UsedChassis);

    return prChassisRet;
}


/******************************************************************************
* Return an used chassis.
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderReturnUsedChassis(VIDEO_ENCODER_CHASSIS_T *prUsedFramePtk)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_CHASSIS_MGR_T *prChassisMgr = &_prMgr->rChassisMgr;
    VIDEO_ENCODER_CHASSIS_T *prChassisRp = prChassisMgr->prChassisRp;

    if (prChassisMgr->u4UsedChassis == 0)
    {
        ASSERT(0);
        return;
    }

    if (prUsedFramePtk->parPktInfo != prUsedFramePtk->arPktInfo)
    {
        ASSERT(0);
        return;
    }

    if (prUsedFramePtk->eChassisStatus != VIDEO_ENCODER_CHASSIS_IN_USE)
    {
        ASSERT(0);
        return;
    }

    if (prChassisRp != prUsedFramePtk)
    {
        ASSERT(0);
        return;
    }

    // Update RP
    prChassisRp++;
    if (prChassisRp >= prChassisMgr->prChassisEnd)
    {
        prChassisRp = prChassisMgr->prChassisStart;
    }
    kal_mem_set((void*)prUsedFramePtk, 0, sizeof(*prUsedFramePtk));
    prChassisMgr->prChassisRp = prChassisRp;
    prChassisMgr->u4UsedChassis--;  // Bookkeeping

    VIDEO_TRACE2_G8( VENC_CHASSIS_RETURN, (kal_uint32)prUsedFramePtk,
        prChassisMgr->u4UsedChassis);
}
#endif  // __VIDEO_VT_SUPPORT__


/******************************************************************************
* Init the YUV queue.
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderInitYuvQueue(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VENC_RING_BUFFER_MGR_T* prMgr = &_prMgr->rYUVHeaderQ;

    VideoCoreInitRingBuffer(&prMgr->rBufferMgr,
                            prMgr->pu1BufferAddr,
                            VIDEO_ENCODER_YUV_HEADER_Q_NUM,
                            sizeof(VIDEO_YUV_HEADER_T));
    _prMgr->rRingBuffers.parYUVHeaderPool= (VENC_YUV_HEADER_POOL_T*)prMgr->pu1BufferAddr;
}


/******************************************************************************
* Is the YUV queue empty?
*
* Context:
*
* Side effect: none
******************************************************************************/
static kal_bool _VideoEncoderIsYuvQueueEmpty(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_CORE_RING_BUFFER_MGR_T* prMgr = &_prMgr->rYUVHeaderQ.rBufferMgr;

    return  VideoCoreIsRingBufferEmpty(prMgr);
}

static kal_bool _VideoEncoderIsQueueFull(VIDEO_CORE_RING_BUFFER_MGR_T * const prBufferMgr, const kal_uint32 u4EntriesLeft)
{
    kal_uint32   u4MaxItemNum =  VideoCoreRingGetBufferMaxNum(prBufferMgr);
    kal_uint32   u4UsedItemNum = VideoCoreRingBufferUsedNum(prBufferMgr);

    // return buffer full when there's still one avialble item for...some reason~
    if (u4UsedItemNum >= (u4MaxItemNum - u4EntriesLeft))
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/******************************************************************************
* Is the YUV queue full?
*
* Context:
*
* Side effect:
******************************************************************************/
static kal_bool _VideoEncoderIsYuvQueueFull(void)
{
    return _VideoEncoderIsQueueFull(&rVideoEncoderMgr.rYUVHeaderQ.rBufferMgr, 1);
}


/******************************************************************************
* Return TRUE if the YUV at head is not used.  Otherwise, return FALSE.
*
* Context:
*
* Side effect:
******************************************************************************/
static kal_bool _VideoEncoderIsFirstYuvNotUsed(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_CORE_RING_BUFFER_MGR_T* prMgr = &_prMgr->rYUVHeaderQ.rBufferMgr;
    VIDEO_YUV_HEADER_T * prRP =  (VIDEO_YUV_HEADER_T *)VideoCoreGetHeadofRingBufferAddr(prMgr);

    if (_VideoEncoderIsYuvQueueEmpty() == KAL_TRUE)
    {
        return KAL_FALSE;
    }

    if (prRP->fgInUse == KAL_TRUE)
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}


/******************************************************************************
*
*
* Context:
*
* Side effect:
******************************************************************************/
static kal_bool _VideoEncoderFirstFrameNotReceived(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_CORE_RING_BUFFER_MGR_T* prMgr = &_prMgr->rYUVHeaderQ.rBufferMgr;
    VIDEO_YUV_HEADER_T *prEnd = (VIDEO_YUV_HEADER_T *)VideoCoreRingGetBufferEnd(prMgr);
    VIDEO_YUV_HEADER_T *prFirstFrm = (VIDEO_YUV_HEADER_T *)VideoCoreRingGetBufferStart(prMgr);
    kal_uint64  u8MinTime = 0xFFFFFFFFFFFFFFFF;
    kal_bool    fgFoundFrm = KAL_FALSE;

    if (_VideoEncoderIsYuvQueueEmpty() == KAL_TRUE)
    {
        return KAL_FALSE;
    }

    do
    {
        if ((prFirstFrm->fgReceived == KAL_FALSE) && (prFirstFrm->fgInUse == KAL_TRUE))
        {
            if (prFirstFrm->rBuffHeader.u8TimeStamp <u8MinTime)
            {
                u8MinTime = prFirstFrm->rBuffHeader.u8TimeStamp;
                *prBuffHeader = prFirstFrm->rBuffHeader;
                fgFoundFrm = KAL_TRUE;
            }
        }
        prFirstFrm++;
    }while(prFirstFrm != prEnd);

    // Do it again to check the prEnd
    if ((prFirstFrm->fgReceived == KAL_FALSE) && (prFirstFrm->fgInUse == KAL_TRUE))
    {
        if (prFirstFrm->rBuffHeader.u8TimeStamp <u8MinTime)
        {
            u8MinTime = prFirstFrm->rBuffHeader.u8TimeStamp;
            *prBuffHeader = prFirstFrm->rBuffHeader;
            fgFoundFrm = KAL_TRUE;
        }
    }

    return fgFoundFrm;

}

/******************************************************************************
* En-queue an item into the tail of the YUV queue.
*
* Context:
*
* Side effect:
******************************************************************************/
static kal_bool _VideoEncoderEnqueueYuvInfo(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_CORE_RING_BUFFER_MGR_T* prMgr = &_prMgr->rYUVHeaderQ.rBufferMgr;
    VIDEO_YUV_HEADER_T *prWP = (VIDEO_YUV_HEADER_T *)VideoCoreGetNextTailofRingBufferAddr(prMgr);

    if (_VideoEncoderIsYuvQueueFull() == KAL_TRUE)
    {
        ASSERT(0);
        return KAL_FALSE;
    }

    if (prWP->fgInUse == KAL_TRUE)
    {
        ASSERT(0);
    }

    prWP->rBuffHeader   = *prBuffHeader;    // Store buffer header.
    prWP->fgInUse       = KAL_TRUE;         // Set fgInUse to TRUE by default.
    prWP->fgReceived    = KAL_FALSE;

    if (KAL_FALSE == VideoCoreAddTailofRingBuffer(prMgr))
    {
        ASSERT(0);
    }

    VIDEO_TRACE1_G8( VENC_YUV_ENQUEUE_USED, (kal_uint32)(prBuffHeader->pu1Buffer));

    return KAL_TRUE;
}


/******************************************************************************
* En-queue an item into the head of the YUV queue.
*
* Context:
*
* Side effect:
******************************************************************************/
static kal_bool _VideoEncoderEnqueueYuvInfoAtHead(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_CORE_RING_BUFFER_MGR_T* prMgr = &_prMgr->rYUVHeaderQ.rBufferMgr;
    VIDEO_YUV_HEADER_T *prRP = (VIDEO_YUV_HEADER_T *)VideoCoreGetNextHeadofRingBufferAddr(prMgr);

    if (_VideoEncoderIsYuvQueueFull() == KAL_TRUE)
    {
        ASSERT(0);
        return KAL_FALSE;
    }

    if (KAL_TRUE == prRP->fgInUse)
    {
        ASSERT(0);
    }

    if (KAL_FALSE == prRP->fgReceived)
    {
        ASSERT(0);
    }

    prRP->rBuffHeader = *prBuffHeader;  // Store buffer header.

    if (KAL_FALSE == VideoCoreAddHeadofRingBuffer(prMgr))
    {
        ASSERT(0);
    }

    VIDEO_TRACE1_G8( VENC_YUV_ENQUEUE_UNUSED, (kal_uint32)(prBuffHeader->pu1Buffer));
    return KAL_TRUE;
}

static kal_bool _VideoEncoderIsCodecRecieveLastYUV(VIDEO_CORE_RING_BUFFER_MGR_T* prMgr)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    kal_uint32 u4InfoNum = VideoCoreRingBufferUsedNum(prMgr);
    VIDEO_YUV_HEADER_T *prRP = (VIDEO_YUV_HEADER_T *)VideoCoreGetHeadofRingBufferAddr(prMgr);

    if (u4InfoNum != 1)
    {
        if ((u4InfoNum == 2)&&(_prMgr->fgRdy2FlushCodec == KAL_TRUE))
        {
            return KAL_TRUE;
        }
        else
        {
            return KAL_FALSE;
        }
    }
    else
    {
        if (prRP->fgReceived == KAL_TRUE)
        {
            return KAL_TRUE;
        }
        else
        {
            return KAL_FALSE;
        }
    }
}

/******************************************************************************
* De-queue an item (at the head of the YUV queue) from the YUV queue.
*
* Context:
*
* Side effect:
******************************************************************************/
static kal_bool _VideoEncoderDequeueYuvInfo(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_CORE_RING_BUFFER_MGR_T* prMgr = &_prMgr->rYUVHeaderQ.rBufferMgr;
    VIDEO_YUV_HEADER_T *prRP = (VIDEO_YUV_HEADER_T *)VideoCoreGetHeadofRingBufferAddr(prMgr);

    if (_VideoEncoderIsYuvQueueEmpty() == KAL_TRUE)
    {
        return KAL_FALSE;
    }

    if (KAL_TRUE == prRP->fgInUse)
    {
        return KAL_FALSE;
    }

    if (KAL_FALSE == prRP->fgReceived)
    {
        ASSERT(0);
    }

    *prBuffHeader = prRP->rBuffHeader;

    if (KAL_FALSE == VideoCoreConsumeHeadofRingBuffer(prMgr))
    {
        ASSERT(0);
    }
    kal_mem_set((void*)prRP, 0, sizeof(*prRP));
    VIDEO_TRACE1_G8( VENC_YUV_DEQUEUE, (kal_uint32)(prBuffHeader->pu1Buffer));

    return KAL_TRUE;
}


/******************************************************************************
*
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderSetReceivedFlag(kal_uint8* pu1Buffer)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_CORE_RING_BUFFER_MGR_T* prMgr = &_prMgr->rYUVHeaderQ.rBufferMgr;
    VIDEO_YUV_HEADER_T *prEnd = (VIDEO_YUV_HEADER_T *)VideoCoreRingGetBufferEnd(prMgr);
    VIDEO_YUV_HEADER_T *prFirstFrm = (VIDEO_YUV_HEADER_T *)VideoCoreRingGetBufferStart(prMgr);
    kal_bool    fgFound = KAL_FALSE;

    if (_VideoEncoderIsYuvQueueEmpty() == KAL_TRUE)
    {
        ASSERT(0);  // FIXME (Leroy): log here
        return;
    }

    do
    {
        if (prFirstFrm->rBuffHeader.pu1Buffer == pu1Buffer)
        {
            if (prFirstFrm->fgReceived == KAL_FALSE)
            {
                fgFound = KAL_TRUE;
                break;
            }
            else
            {
                ASSERT(0);
            }
        }

        prFirstFrm++;
    }while(prFirstFrm != prEnd);

    //Check the prEnd
    if (KAL_FALSE == fgFound)
    {
        if (prFirstFrm->rBuffHeader.pu1Buffer == pu1Buffer)
        {
            if (prFirstFrm->fgReceived == KAL_FALSE)
            {
                fgFound = KAL_TRUE;
            }
            else
            {
                ASSERT(0);
            }
        }
    }

    if (KAL_TRUE == fgFound)
    {
        prFirstFrm->fgReceived = KAL_TRUE;
    }
    else
    {
        //All frames should be found
        ASSERT(0);
    }
}

/******************************************************************************
* Clear the fgInUse flag at the first used YUV header in the YUV queue.
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderClearInUseFlagAtFirstUsedYuv(
        VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader,
        kal_uint8 *pu1Buff)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_CORE_RING_BUFFER_MGR_T* prMgr = &_prMgr->rYUVHeaderQ.rBufferMgr;
    VIDEO_YUV_HEADER_T *prRP, *prStart, *prEnd;
    kal_uint32   u4QSize = VideoCoreRingGetBufferMaxNum(prMgr);

    prRP    = (VIDEO_YUV_HEADER_T *)VideoCoreGetHeadofRingBufferAddr(prMgr);
    //prWP    = (VIDEO_YUV_HEADER_T *)VideoCoreGetTailofRingBufferAddr(prMgr);
    prStart = (VIDEO_YUV_HEADER_T *)VideoCoreRingGetBufferStart(prMgr);
    prEnd   = (VIDEO_YUV_HEADER_T *)VideoCoreRingGetBufferEnd(prMgr);

    do
    {
        if (!((prStart <= prRP) && (prRP <= prEnd)))
        {
            ASSERT(0);
        }
        if ((prRP->fgInUse == KAL_TRUE) && (prRP->rBuffHeader.pu1Buffer == pu1Buff))
        {
            prRP->fgInUse = KAL_FALSE;  // Set the first used YUV frame to be unused.
            *prBuffHeader = prRP->rBuffHeader;  // Get buffer header.
            return;
        }

        prRP++;
        if (prRP == (prEnd + 1))
        {
            prRP = prStart;
        }
        u4QSize--;
    }while (0 != u4QSize);

    ASSERT(0);
}


/******************************************************************************
* Init the Time Stamp queue.
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderInitTimeStampQueue(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VENC_RING_BUFFER_MGR_T* prMgr = &_prMgr->rTimeStampQ;

    VideoCoreInitRingBuffer(&prMgr->rBufferMgr, prMgr->pu1BufferAddr,
                            VENC_TIME_STAMP_Q_NUM,
                            VENC_TIME_STAMP_Q_ITEM_SIZE);
    _prMgr->rRingBuffers.parTimeStampPool = (VENC_TIME_STAMP_POOL_T*)prMgr->pu1BufferAddr;
}

/******************************************************************************
* Is the Time Stamp queue full?
*
* Context:
*
* Side effect:
******************************************************************************/
static kal_bool _VideoEncoderIsTimeStampQueueFull(void)
{
    return _VideoEncoderIsQueueFull(&rVideoEncoderMgr.rTimeStampQ.rBufferMgr, 1);
}


/******************************************************************************
* Read (get) the time stamp pointed by the Read pointer.
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderGetTimeStamp(kal_uint64 *pu8TimeStamp)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    kal_uint64 *pu8RP = (kal_uint64 *)VideoCoreGetHeadofRingBufferAddr(&_prMgr->rTimeStampQ.rBufferMgr);

    if (NULL == pu8RP)
    {
        //ASSERT(0);  // FIXME (Leroy): log here
        _ENCODER_TRACE(VIDEO_TRACE0_G10(VENC_TIMESTAMP_QUEUE_IS_EMPTY));
    }
    else
    {
        *pu8TimeStamp = *pu8RP;  // Get time stamp.
    }
}


/******************************************************************************
* En-queue an item into the tail of the Time Stamp queue.
*
* Context:
*
* Side effect:
******************************************************************************/
static kal_bool _VideoEncoderEnqueueTimeStamp(kal_uint64 *pu8TimeStamp)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    if (KAL_FALSE == VideoCoreInsertToTailofRingBuffer(&_prMgr->rTimeStampQ.rBufferMgr, (kal_uint8 *)pu8TimeStamp))
    {
        ASSERT(0);
    }

    VIDEO_TRACE1_G8( VENC_TIMESTAMP_ENQUEUE, (kal_uint32)(*pu8TimeStamp));
    return KAL_TRUE;
}


/******************************************************************************
* De-queue an item (at the head of the queue) from the Time Stamp queue.
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderDequeueTimeStamp(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    kal_uint64 u8RP;

    if (KAL_FALSE == VideoCoreRemoveFromHeadofRingBufferAddr(&_prMgr->rTimeStampQ.rBufferMgr, (kal_uint8*)(&u8RP)))
    {
        ASSERT(0);
    }
    else
    {
        VIDEO_TRACE1_G8( VENC_TIMESTAMP_DEQUEUE, (kal_uint32)(&u8RP));
    }
}

/******************************************************************************
* Calculate the min/max/average encoding time.
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderStoreEncodingTime(kal_uint32 u4EncodingTime)
{
#if defined(__VE_VENC_PROFILING_CODEC__)
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    if (u4EncodingTime == 0)
    {
        return;
    }

    _prMgr->u4AccumEncodingTime += u4EncodingTime;

    if (_prMgr->u4MinEncodingTime == 0)
    {
        _prMgr->u4MinEncodingTime = u4EncodingTime;
    }
    else if (u4EncodingTime < _prMgr->u4MinEncodingTime)
    {
        _prMgr->u4MinEncodingTime = u4EncodingTime;
    }

    if (_prMgr->u4MaxEncodingTime == 0)
    {
        _prMgr->u4MaxEncodingTime = u4EncodingTime;
    }
    else if (u4EncodingTime > _prMgr->u4MaxEncodingTime)
    {
        _prMgr->u4MaxEncodingTime = u4EncodingTime;
    }

    /* Do not calculate the average encoding time here.  Make the calculation
     * before the encoder component enters STOP state to save some MIPS. */
#endif //(__VE_VENC_PROFILING_CODEC__)
}

#if defined(__VE_VENC_DUMP_ENCODE_INFO__)
static int kal_char_strlen(const char *str)
{
   char *temp=(char *)str;
   int len=0;

   while ( *temp!='\0' )
   {
      temp+=1;
      len+=1;
   }

   return len;
}
#endif

/******************************************************************************
* Calculate the min/max/average encoding time.
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderLogStatusInfo(void)
{
#if defined(__VE_VENC_PROFILING_CODEC__) || defined(__VE_VENC_PROFILING_BITSTREAM__)
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
#endif

#if defined(__VE_VENC_PROFILING_CODEC__)
    if (_prMgr->u4AccumEncodedFrames != 0)
    {
        _prMgr->u4AvgEncodingTime =
            _prMgr->u4AccumEncodingTime / _prMgr->u4AccumEncodedFrames;
    }
    else
    {
        _prMgr->u4AvgEncodingTime = 0;
    }

    VIDEO_TRACE4_G8( VENC_ENCODING_TIME,
        _prMgr->u4MinEncodingTime,
        _prMgr->u4AvgEncodingTime,
        _prMgr->u4MaxEncodingTime, __LINE__);

#endif //(__VE_VENC_PROFILING_CODEC__)

#if defined(__VE_VENC_PROFILING_BITSTREAM__)
    VIDEO_TRACE1_G8( VENC_BIT_BUFFER_PEAK_SIZE,
        _prMgr->rBitBufferMgr.u4PeakSize);
#endif //(__VE_VENC_PROFILING_BITSTREAM__)

#if defined(__VE_VENC_DUMP_ENCODE_INFO__)
    {
        kal_uint8 szDst[256];
        kal_uint32 Written;
        FS_HANDLE rHandle = FS_Open((kal_wchar*) L"D:\\Bitstream.txt", FS_READ_WRITE | FS_CREATE);
        sprintf(szDst, "Encode Time: %d(%d~%d), Bitstream Size: %d\r\n",
            _prMgr->u4AvgEncodingTime,
            _prMgr->u4MinEncodingTime,
            _prMgr->u4MaxEncodingTime,
            _prMgr->rBitBufferMgr.u4PeakSize);

        FS_Seek(rHandle, 0, FS_FILE_END);
        FS_Write(rHandle, szDst, kal_char_strlen(szDst), &Written);
        FS_Close(rHandle);
    }
#endif
}


/******************************************************************************
* Initialize the encoder's working memory with ADM.
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderInitCodecMemory(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_WORKING_MEM_T* pMgr = &_prMgr->rWorkingMem;
    pMgr->rCodecMemAdmId = kal_adm_create(  (void*)pMgr->pu1StartAddr,
                                            pMgr->rCodecMemory.u4ExternalSize,
                                            NULL, KAL_TRUE);
}


/******************************************************************************
* De-initialize the encoder's working memory with ADM.
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderDeInitCodecMemory(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_WORKING_MEM_T* pMgr = &_prMgr->rWorkingMem;

    if (NULL != pMgr->rCodecMemAdmId)
    {
        kal_adm_delete(pMgr->rCodecMemAdmId);
        pMgr->rCodecMemAdmId = NULL;
    }
}


/******************************************************************************
* Initialize the queue manager specified by the parameter.  Link each atom in
* the atom pool in series.
*
* Context:
*
* Side effect: data structure pointed to by the input argument
******************************************************************************/
static void _VideoEncoderInitResendQ(VENC_RING_BUFFER_MGR_T *prMgr)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VideoCoreInitRingBuffer(&prMgr->rBufferMgr, prMgr->pu1BufferAddr, VIDEO_ENCODER_RESEND_Q_NUM, sizeof(VIDEO_BUFFERHEADER_TYPE_T));
    _prMgr->rRingBuffers.parResendPool = (VENC_RESEND_Q_POOL_T*)prMgr->pu1BufferAddr;
    _prMgr->fgInitResendQ = KAL_TRUE;
}


/******************************************************************************
* De-initialize the queue manager specified by the parameter.
*
* Context:
*
* Side effect: data structure pointed to by the input argument
******************************************************************************/
static void _VideoEncoderDeInitResendQ(VENC_RING_BUFFER_MGR_T *prResendQ)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;

    if (KAL_TRUE == _prMgr->fgInitResendQ)
    {
        VideoCoreDeInitRingBuffer(&prResendQ->rBufferMgr);
        _prMgr->fgInitResendQ = KAL_FALSE;
    }
}

/******************************************************************************
* Is the specified Resend queue full?
*
* Context:
*
* Side effect: none
******************************************************************************/
static kal_bool _VideoEncoderIsResendQFull(
    VENC_RING_BUFFER_MGR_T *prResendQ,
    kal_uint32 u4EntriesLeft)
{
    return _VideoEncoderIsQueueFull(&prResendQ->rBufferMgr, u4EntriesLeft);
}


/******************************************************************************
* Copy the data pointed to by prBuffHeader to the atom at the head of the
* Resend queue.
*
* Context:
*
* Side effect: the queue manager (data pointed to by prResendQ)
******************************************************************************/
static void _VideoEncoderInsertToResendQHead(
    VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader,
    VENC_RING_BUFFER_MGR_T *prResendQ)
{
    VIDEO_CORE_RING_BUFFER_MGR_T* prMgr = &prResendQ->rBufferMgr;

    if (KAL_FALSE == VideoCoreInsertToHeadofRingBuffer(prMgr, (kal_uint8 *)prBuffHeader))
    {
        ASSERT(0);
    }
}


/******************************************************************************
* Copy the data pointed to by prBuffHeader to the atom at the tail of the
* Resend queue.
*
* Context:
*
* Side effect: the queue manager (data pointed to by prResendQ)
******************************************************************************/
static void _VideoEncoderInsertToResendQTail(
    VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader,
    VENC_RING_BUFFER_MGR_T *prResendQ)
{
    VIDEO_CORE_RING_BUFFER_MGR_T* prMgr = &prResendQ->rBufferMgr;

    if (KAL_FALSE == VideoCoreInsertToTailofRingBuffer(prMgr, (kal_uint8 *)prBuffHeader))
    {
        ASSERT(0);
    }
}


/******************************************************************************
* Copy the data at the head atom of the Resend queue to the address pointed to
* by prBuffHeader.
*
* Context:
*
* Side effect: the queue manager (data pointed to by prResendQ), and *prBuffHeader
******************************************************************************/
static kal_bool _VideoEncoderGetResendAtom(
    VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader,
    VENC_RING_BUFFER_MGR_T *prResendQ)
{
    VIDEO_CORE_RING_BUFFER_MGR_T* prMgr = &prResendQ->rBufferMgr;
    //VIDEO_BUFFERHEADER_TYPE_T rAtom;

    if (KAL_TRUE == VideoCoreRemoveFromHeadofRingBufferAddr(prMgr, (kal_uint8*)(prBuffHeader)))
    {
        //kal_mem_cpy((void*)prBuffHeader, (void*)(&rAtom), sizeof(*prBuffHeader));
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

static void _VENC_InitResource(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    _prMgr->rTimerID = VideoGetTimer(TIMER_USER_ENCODER);
    _prMgr->rFillMutex = VideoGetMutex(MUTEX_USER_ENCODER);
}

static void _VENC_DeinitResource(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;

    VideoFreeMutex(MUTEX_USER_ENCODER, _prMgr->rFillMutex);
    VideoFreeTimer(TIMER_USER_ENCODER, _prMgr->rTimerID);
}
/******************************************************************************
* Initialize the "encoder component manager".
*
* Context:
*
* Side effect: "encoder component manager"
******************************************************************************/
static void _VideoEncoderInitEncoderManager(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;

    _prMgr->eIntState = VIDEO_ENCODER_INT_STATE_INIT;
    _prMgr->fgGenerateHeader = KAL_FALSE;
    _prMgr->u4SceneChangeWriteIndex = 0;
    kal_mem_set((void*)_prMgr->afgSceneChange, 0, sizeof(_prMgr->afgSceneChange));
#if defined(__VE_VENC_PROFILING_VT__)
    _prMgr->u4EncodedFrameNum     =   0;
    _prMgr->u4TimePassed          =   0;
    _prMgr->u4ProfileStartTime    =   0;
    _prMgr->u4EncodedBits         =   0;
#endif //__VE_VENC_PROFILING_VT__
    _prMgr->u4InputQueueNumber    =   0;
    _prMgr->u4OutputQueueNumber   =   0;
#if defined(__VE_VENC_PROFILING_CODEC__)
    _prMgr->u4AccumEncodingTime   =   0;
    _prMgr->u4AccumEncodedFrames  =   0;
    _prMgr->u4MinEncodingTime     =   0;
    _prMgr->u4MaxEncodingTime     =   0;
    _prMgr->u4AvgEncodingTime     =   0;
#endif //__VE_VENC_PROFILING_CODEC__
    _prMgr->u4CleanCnt            =   0;
    _prMgr->u4CodecConfig         =   0;

    _prMgr->fgRdy2FlushCodec      =   KAL_FALSE;
    _prMgr->fgSourceNotifyStop    =   KAL_FALSE;
    _prMgr->fgPauseResume         =   KAL_FALSE;
    _prMgr->fgClosingEncoder      =   KAL_FALSE;
    _prMgr->fgStopInstantly       =   KAL_FALSE;
    _prMgr->fgSetupCodec          =   KAL_FALSE;
    _prMgr->fgLimitFrmBuff        =   KAL_FALSE;
    _prMgr->eCleanMode    =   VENC_CLEAN_AFTER_ENCODE;
    _prMgr->fgFlushedCodec        =   KAL_FALSE;
    _prMgr->fgInitResendQ         =   KAL_FALSE;
    _prMgr->fgCompClosed          =   KAL_FALSE;

    //kal_mem_set((void*)&prEncoderMgr->rWorkingMem, 0, sizeof(prEncoderMgr->rWorkingMem));

    _prMgr->fgStartWakeUpTimer = KAL_FALSE;

#if defined(__VE_TIME_LAPSE_VIDEO_RECORDER__)
    _prMgr->u8TLCaptureFrameTime = 0;
    _prMgr->u4TLCaptureFrameDuration = 0;
    _prMgr->u8TLEncodedFrameTime = 0;
    _prMgr->u4TLEncodedFrameDuration = 0;
#endif

#if defined(__VE_VIDEO_VT_SUPPORT__)
    _u4AccumulatedBitBufferSize = 0;
    _pu1BitBuffer = NULL;
#endif  // __VE_VIDEO_VT_SUPPORT__
}


/******************************************************************************
* De-initialize the "encoder component manager".
*
* Context:
*
* Side effect: "encoder component manager"
******************************************************************************/
static VIDEO_ERROR_TYPE_T _VideoEncoderDeInitEncoderManager(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VENC_RING_BUFFER_MGR_T *prOutResendQ = &_prMgr->rOutResendQ;


    _VideoEncoderDeInitResendQ(prOutResendQ);
#if defined(__VE_VIDEO_VT_SUPPORT__)
    _VideoEncoderDeInitChassisMgr();
#endif  // __VE_VIDEO_VT_SUPPORT__

    _VideoEncoderDeInitCodecMemory();

    return VIDEO_ERROR_NONE;
}


/******************************************************************************
* Are the errors rErrorToBeChecked and eError the same?
*
* Context: This function runs in the caller's context.
*
* Side effect: none
******************************************************************************/
static kal_bool _VideoEncoderCheckError(VIDEO_ERROR_TYPE_T rErrorToBeChecked,
        VIDEO_ERROR_TYPE_T eError)
{
    if (rErrorToBeChecked == eError)
    {
        return KAL_TRUE;
    }
    else if (rErrorToBeChecked != VIDEO_ERROR_NONE)
    {
        ASSERT(0);
    }
    return KAL_FALSE;
}


/******************************************************************************
* Send an ILM to the destination module MOD_VCODEC_V2.
* The source module is chosen according to the value of u4Param1.
*
* Context: This function runs in the context of the caller task rather than the
*          context of the encoder component.
*
* Side effect:
******************************************************************************/
static void _VideoEncoderSendMessage(kal_uint32 u4Message, kal_uint32 u4Param1,
        kal_uint32 u4Param2)
{
    VIDEO_ENCODER_IND_T *prMsg = NULL;
    ilm_struct *prIlm = NULL;
    module_type eActiveModuleId = stack_get_active_module_id();

    prMsg = (VIDEO_ENCODER_IND_T*) construct_local_para(sizeof(VIDEO_ENCODER_IND_T), TD_CTRL);
    prMsg->u4Param1 = u4Param1;
    prMsg->u4Param2 = u4Param2;

    prIlm = allocate_ilm(eActiveModuleId);
    prIlm->src_mod_id = eActiveModuleId;

    prIlm->dest_mod_id = MOD_VCODEC_V2;
    prIlm->sap_id = MED_SAP;

    prIlm->msg_id = (msg_type) u4Message;
    prIlm->local_para_ptr = (local_para_struct*) prMsg;
    prIlm->peer_buff_ptr = NULL;

    msg_send_ext_queue(prIlm);
}


/******************************************************************************
* Wake up the encoder component.
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderWakeUp(VIDEO_ENCODER_MESSAGE_T eMsgType,
        kal_uint32 u4Param2)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_COMM_STATE_T* const prCommState = &_prMgr->rCommState;
    kal_bool fgSendMsg = KAL_FALSE;

    fgSendMsg = VideoCommSetProcessing(prCommState);
    if (fgSendMsg == KAL_TRUE)
    {
        _VideoEncoderSendMessage(MSG_ID_ENCODER_DATA_IND, eMsgType, u4Param2);
    }
}

static void _VideoEncoderClkWakeUp(void* pu1Void)
{
    _VideoEncoderWakeUp(MSG_WAKEUP, 0);
}


/******************************************************************************
* xxx
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderDebugQueueLength(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    kal_char au1LoggingName[] = "EI_";

    au1LoggingName[sizeof(au1LoggingName) - 2] = '0' + _prMgr->u4InputQueueNumber;
    VideoLabelLogging(au1LoggingName);

    au1LoggingName[1] = 'O';
    au1LoggingName[sizeof(au1LoggingName) - 2] = '0' + _prMgr->u4OutputQueueNumber;
    VideoLabelLogging(au1LoggingName);
}

/*************************************************
*
*   Bistream buffer management for bypass mode
*
*************************************************/
#if defined(__VE_MJPEG_ENC_BYPASS__)
static kal_uint32 _VENC_SaturatedAddOne(
    kal_uint32 u4Augend,
    kal_uint32 u4UpperBound)
{
    const kal_uint32 u4Addend = 1;
    kal_uint32 u4Tmp = u4Augend + u4Addend;

    return (u4Tmp > u4UpperBound)?(0): (u4Tmp);
}

static kal_uint32 _VENC_SaturatedSubtractOne(
    kal_uint32 u4Minuend,
    kal_uint32 u4UpperBound)
{
    const kal_uint32 u4Subtrahend = 1;
    kal_uint32 u4Tmp = u4Minuend - u4Subtrahend;

    if (u4Minuend >= u4Subtrahend)
    {
        return u4Tmp;
    }
    else
    {
        return u4UpperBound;
    }
}

static void _VENC_DirectCouple_AllocateMemoryForBistreamCtrl(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    BISTREAM_BUFFER_CTRL_T* prCtrl = &_prMgr->rBistreamBufferCtrl;
    VIDEO_ENCODER_CUSTOM_SETTINGS_T* prCustomSetting = &_prMgr->rCustomSettings;

    prCtrl->pu1StartAddress =
        (kal_uint8*)VideoGetExtCacheBuffer(_prMgr->prExtMemHdlr, prCustomSetting->u4BypassModeTotalBitstreamSize);

    prCtrl->parBufferPool =
        (BISTREAM_BUFFER_UNIT_T*)VideoGetExtBuffer(_prMgr->prExtMemHdlr, prCustomSetting->u4BypassModeBistreamNum * sizeof(BISTREAM_BUFFER_UNIT_T));

    prCtrl->pu1DummyBuffer =
        (kal_uint8*)VideoGetExtBuffer(_prMgr->prExtMemHdlr, VENC_DUMMY_BUFFER_SIZE);
}

static void _VENC_DirectCouple_SetupBistreamCtrl(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_CUSTOM_SETTINGS_T* prCustomSetting = &_prMgr->rCustomSettings;
    BISTREAM_BUFFER_CTRL_T* prCtrl = &_prMgr->rBistreamBufferCtrl;
    kal_uint8*  pu1TempStart = prCtrl->pu1StartAddress;
    BISTREAM_BUFFER_UNIT_T* prTempUnit = prCtrl->parBufferPool;
    kal_uint8*  pu1TempDummy = prCtrl->pu1DummyBuffer;
    kal_uint32 i;

    kal_mem_set((void*)prCtrl, 0, sizeof(*prCtrl));
    // The following codes are removed due to kal_mem_set above
    /*
    prCtrl->u4AvailableIdx      =   0;
    prCtrl->u4EncodingIdx       =   0;
    prCtrl->u4Ready2WriteIdx    =   0;
    prCtrl->u4NextWritedIdx     =   0;
    */
    prCtrl->pu1StartAddress = pu1TempStart;
    prCtrl->parBufferPool = prTempUnit;
    prCtrl->pu1DummyBuffer = pu1TempDummy;

    prCtrl->pu1DummyBuffer =
        (kal_uint8*)VideoCommExtBufferCacheableSwitchAlignMemory((kal_uint32)prCtrl->pu1DummyBuffer,
                                                        prCustomSetting->u4BypassModeOneBistreamSize,
                                                        VIDEO_NON_CACHEABLE);
    prCtrl->pu1StartAddress =
        (kal_uint8*)VideoCommExtBufferCacheableSwitchAlignMemory((kal_uint32)prCtrl->pu1StartAddress,
                                                        prCustomSetting->u4BypassModeTotalBitstreamSize,
                                                        VIDEO_NON_CACHEABLE);

    pu1TempStart = prCtrl->pu1StartAddress;
    i = prCustomSetting->u4BypassModeBistreamNum;

#if !defined(__VE_SLIM_PROJECT__)
    if (i > (VIDEO_ENCODER_INPUT_BUFFER_Q_NUM - 1))
    {
        // Error check: avoid potential buffer full case
        VIDEO_TRACE4_G9( VENC_YUV_IS_TOO_LARGE, KAL_TRUE, i, VIDEO_ENCODER_INPUT_BUFFER_Q_NUM - 1, 0);
    }
#endif

    do{
        BISTREAM_BUFFER_UNIT_T* prUnit = prCtrl->parBufferPool + (prCustomSetting->u4BypassModeBistreamNum - i);

        prUnit->eStatus = BS_AVAILABLE;
        prUnit->pu1Addr = (kal_uint8*)((((kal_uint32)pu1TempStart + 7)>>3)<<3);
        pu1TempStart += prCustomSetting->u4BypassModeOneBistreamAlignedSize;
    }while(--i != 0);
}

static void _VENC_DirectCouple_ChangeStatus(BISTREAM_BUFFER_UNIT_T* prUnit, BISTREAM_BUFFER_UNIT_STATUS_T  eStatus)
{
    BISTREAM_BUFFER_CTRL_T* prCtrl = &rVideoEncoderMgr.rBistreamBufferCtrl;
    BISTREAM_BUFFER_UNIT_STATUS_T eOriginal = prUnit->eStatus;

    prUnit->eStatus = eStatus;
    if ((BS_AVAILABLE == eOriginal)&&(BS_ENCODING == prUnit->eStatus))
    {
        prCtrl->u4EncodingNum++;
    }
    else if ((BS_ENCODING == eOriginal)&&(BS_ENCODING != prUnit->eStatus))
    {
        prCtrl->u4EncodingNum--;
    }
    VIDEO_TRACE4_G10(VENC_DC_CHANGE_BS_STATE, (kal_uint32)prUnit->pu1Addr, eOriginal, prUnit->eStatus, 0);
}

static void _VENC_DirectCouple_GetDummyBuffer(BISTREAM_BUFFER_T * prBuff)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    BISTREAM_BUFFER_CTRL_T* prCtrl = &_prMgr->rBistreamBufferCtrl;
    VIDEO_ENCODER_CUSTOM_SETTINGS_T* prCustomSetting = &_prMgr->rCustomSettings;

    kal_mem_set((void*)prBuff, 0, sizeof(*prBuff));
    prBuff->pu1StartAddress =   prCtrl->pu1DummyBuffer;//(kal_uint8*)&prCtrl->u4DummyBuffer;
    prBuff->u4BufferSize    =   prCustomSetting->u4BypassModeOneBistreamSize;//sizeof(prCtrl->u4DummyBuffer);

    VIDEO_TRACE1_G10(VENC_DC_GET_DUMMY_BS, (kal_uint32)prBuff->pu1StartAddress);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

static void _VENC_DirectCouple_GetAvailableBistream(BISTREAM_BUFFER_T * prBuff)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_CUSTOM_SETTINGS_T* prCustomSetting = &_prMgr->rCustomSettings;
    BISTREAM_BUFFER_CTRL_T* prCtrl = &_prMgr->rBistreamBufferCtrl;
    BISTREAM_BUFFER_UNIT_T* prUnit = prCtrl->parBufferPool + prCtrl->u4AvailableIdx;//&prCtrl->arBufferPool[prCtrl->u4AvailableIdx];

    kal_mem_set((void*)prBuff, 0, sizeof(*prBuff));
    if (BS_AVAILABLE == prUnit->eStatus)
    {
        prBuff->pu1StartAddress =   prUnit->pu1Addr;
        prBuff->u4BufferSize    =   prCustomSetting->u4BypassModeOneBistreamSize - 8;

        _VENC_DirectCouple_ChangeStatus(prUnit, BS_ENCODING);

        prCtrl->u4AvailableIdx = _VENC_SaturatedAddOne(prCtrl->u4AvailableIdx, (prCustomSetting->u4BypassModeBistreamNum - 1));

        VIDEO_TRACE2_G10(VENC_DC_GET_AVAILABLE_BS, (kal_uint32)prBuff->pu1StartAddress, prBuff->u4BufferSize);
    }
    else
    {
        #if 1
        _VENC_DirectCouple_GetDummyBuffer(prBuff);
        #else
/* under construction !*/
/* under construction !*/
        #endif
    }
}

static void _VENC_DirectCouple_SetBistreamReady2Write(kal_uint8* pu1Buff)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_CUSTOM_SETTINGS_T* prCustomSetting = &_prMgr->rCustomSettings;
    BISTREAM_BUFFER_CTRL_T* prCtrl = &_prMgr->rBistreamBufferCtrl;
    BISTREAM_BUFFER_UNIT_T* prUnit = prCtrl->parBufferPool + prCtrl->u4EncodingIdx;//&prCtrl->arBufferPool[prCtrl->u4EncodingIdx];

    if ((BS_ENCODING != prUnit->eStatus)||
        (pu1Buff != prUnit->pu1Addr))
    {
        ASSERT(0);
    }

    _VENC_DirectCouple_ChangeStatus(prUnit, BS_READY2WRITE);

    prCtrl->u4EncodingIdx = _VENC_SaturatedAddOne(prCtrl->u4EncodingIdx, (prCustomSetting->u4BypassModeBistreamNum - 1));
}

static void _VENC_DirectCouple_SetBistreamWriting(kal_uint8* pu1Buff)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_CUSTOM_SETTINGS_T* prCustomSetting = &_prMgr->rCustomSettings;
    BISTREAM_BUFFER_CTRL_T* prCtrl = &_prMgr->rBistreamBufferCtrl;
    BISTREAM_BUFFER_UNIT_T* prUnit = prCtrl->parBufferPool + prCtrl->u4Ready2WriteIdx;//&prCtrl->arBufferPool[prCtrl->u4Ready2WriteIdx];

    if ((BS_READY2WRITE != prUnit->eStatus)||
        (pu1Buff != prUnit->pu1Addr))
    {
        ASSERT(0);
    }

    _VENC_DirectCouple_ChangeStatus(prUnit, BS_WRITING);

    prCtrl->u4Ready2WriteIdx = _VENC_SaturatedAddOne(prCtrl->u4Ready2WriteIdx, (prCustomSetting->u4BypassModeBistreamNum - 1));
}

static void _VENC_DirectCouple_SetBistreamAvailable(kal_uint8* pu1Buff)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_CUSTOM_SETTINGS_T* prCustomSetting = &_prMgr->rCustomSettings;
    BISTREAM_BUFFER_CTRL_T* prCtrl = &_prMgr->rBistreamBufferCtrl;
    BISTREAM_BUFFER_UNIT_T* prUnit = prCtrl->parBufferPool + prCtrl->u4NextWritedIdx;//&prCtrl->arBufferPool[prCtrl->u4NextWritedIdx];

    if ((BS_WRITING != prUnit->eStatus)||
        (pu1Buff != prUnit->pu1Addr))
    {
        ASSERT(0);
    }

    _VENC_DirectCouple_ChangeStatus(prUnit, BS_AVAILABLE);

    prCtrl->u4NextWritedIdx = _VENC_SaturatedAddOne(prCtrl->u4NextWritedIdx, (prCustomSetting->u4BypassModeBistreamNum - 1));
}

static kal_bool _VENC_DirectCouple_IsAnyBistreamStillEncoding(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    BISTREAM_BUFFER_CTRL_T* prCtrl = &_prMgr->rBistreamBufferCtrl;

    return (0 == prCtrl->u4EncodingNum)?(KAL_TRUE):(KAL_FALSE);
}
#endif //__VE_MJPEG_ENC_BYPASS__

MPL_BUFFER_INFO_T VENC_GetBistreamBuffer(void)
{
    MPL_BUFFER_INFO_T   rInfo;
#if defined(__VE_MJPEG_ENC_BYPASS__)
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_COMM_STATE_T* const prCommState = &_prMgr->rCommState;
    BISTREAM_BUFFER_T   rBufferInfo;

    kal_mem_set((void*)&rInfo, 0, sizeof(rInfo));
    if ((VIDEO_STATE_RUN == VideoCommGetState(prCommState))&&
        (_prMgr->eIntState != VIDEO_ENCODER_INT_STATE_STOPPING))
    {
        _VENC_DirectCouple_GetAvailableBistream(&rBufferInfo);
    }
    else
    {
        _VENC_DirectCouple_GetDummyBuffer(&rBufferInfo);
    }

    rInfo.pu1Address = rBufferInfo.pu1StartAddress;
    rInfo.u4Size     = rBufferInfo.u4BufferSize;

    return  rInfo;
#else
    kal_mem_set((void*)&rInfo, 0, sizeof(rInfo));
    return rInfo;
#endif //__VE_MJPEG_ENC_BYPASS__
}

void VENC_ReturnBistreamBuffer(MPL_BUFFER_INFO_T rBuff)
{
#if defined(__VE_MJPEG_ENC_BYPASS__)
    VIDEO_COMM_STATE_T* const prCommState = &rVideoEncoderMgr.rCommState;
    kal_uint32 u4InputPort = VideoCommGetInputPortIndex(prCommState, VIDEO_PORT_VIDEO_DATA);
    VIDEO_COMPONENT_PARAM_T *prCompParam = VideoCommGetInputComp(prCommState, u4InputPort);
    kal_uint32 u4TunnelOutputPort = prCompParam->u4PortIndex;
    BISTREAM_BUFFER_CTRL_T* prCtrl = &rVideoEncoderMgr.rBistreamBufferCtrl;

    // Does this function be called in task?
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    VIDEO_TRACE2_G10(VENC_DC_RETURN_BS, (kal_uint32)rBuff.pu1Address, rBuff.u4Size);

    if (prCtrl->pu1DummyBuffer == rBuff.pu1Address)
    {
        return;
    }

    if (MPL_OK == rBuff.eStatus)
    {
        VIDEO_BUFFERHEADER_TYPE_T rBufferHeader;

        kal_mem_set((void*)&rBufferHeader, 0, sizeof(rBufferHeader));

        rBufferHeader.eFlags = VIDEO_BUFFERFLAG_SYNCFRAME;
        rBufferHeader.eFlags |= VIDEO_BUFFERFLAG_END_OF_FRAME;
        rBufferHeader.pu1Buffer = rBuff.pu1Address;
        rBufferHeader.u4BuffSize = rBuff.u4Size;
        rBufferHeader.u4InputPort = u4InputPort;
        rBufferHeader.u4OutputPort = u4TunnelOutputPort;
        VRCLK_GetCurrentTime(&rBufferHeader.u8TimeStamp);

        _VENC_DirectCouple_SetBistreamReady2Write(rBuff.pu1Address);

        VideoEncoderEmptyThisBuffer(&rBufferHeader);
    }
    else
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    {
        ASSERT(0);
    }

#endif //__VE_MJPEG_ENC_BYPASS__
}

/******************************************************************************
*
*
* Context:
*
* Side effect:
******************************************************************************/
static kal_uint32 _VideoEncoderAllocateMemoryForCodec(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENC_MEMORY_T* prCodecMemory = &_prMgr->rWorkingMem.rCodecMemory;

    if (CODEC_NONE == _prMgr->eCodec)
    {
        return 0;
    }
    else if (NULL == _prMgr->rWorkingMem.pu1StartAddr)
    {
        prCodecMemory->u4Width = _prMgr->rAdaptSettings.u4Width;
        prCodecMemory->u4Height = _prMgr->rAdaptSettings.u4Height;
        // Query codec for the required memory size.
        // The width and height shall have been set by now.
        _VideoEncGetParam(_prMgr, VENC_PARAM_MEMORY_REQUIREMENT, (void*)(prCodecMemory));
        VIDEO_TRACE1_G10( VENC_MEMORY_SETTING_CODEC, prCodecMemory->u4ExternalSize);

        prCodecMemory->u4ExternalSize += VENC_WORKING_MEM_ADM_OVERHEAD;
        _prMgr->rWorkingMem.pu1StartAddr =
            (kal_uint8*)VideoGetExtCacheBuffer(_prMgr->prExtMemHdlr, prCodecMemory->u4ExternalSize);
    }

    return prCodecMemory->u4ExternalSize;

}


/******************************************************************************
*
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderAllocateMemoryForYuv(kal_uint32 u4YuvBufferSize)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_YUV_BUFFER_T* const prYuvBufferMgr = &_prMgr->rYuvBufferMgr;
    kal_uint32 u4MinBufferSize, u4YuvBufferAddr;
    VIDEO_ENCODER_CUSTOM_SETTINGS_T* prCustomSettings = &_prMgr->rCustomSettings;

    // Calculate the buffer size of a single YUV frame, round it up, and then
    // multiply it with the minimal number of frames.
    u4MinBufferSize = (_prMgr->u4SourceWidth * _prMgr->u4SourceHeight * 3)>>1;
    u4MinBufferSize = ROUND_UP_TO_POWER_OF_TWO(u4MinBufferSize, CPU_CACHE_LINE_SIZE);
    u4MinBufferSize *= prCustomSettings->u4MinFrmNum;

    if (u4YuvBufferSize < u4MinBufferSize)
    {
        // Codec may have requested more memory than it is allowed to have.
        // This leaves the remaining buffer less than the minimal YUV buffer size.
        ASSERT(0);
        return;
    }

    u4YuvBufferSize = ROUND_UP_TO_POWER_OF_TWO((u4YuvBufferSize - CPU_CACHE_LINE_SIZE), CPU_CACHE_LINE_SIZE);
    prYuvBufferMgr->u4BufferSize = u4YuvBufferSize;

    // Because the YUV buffer is used by the camera hardware, set it to
    // non-cacheable to ensure data consistency.
    u4YuvBufferAddr = VideoGetExtCacheBuffer(_prMgr->prExtMemHdlr, u4YuvBufferSize);
    u4YuvBufferAddr = VideoCommExtBufferCacheableSwitch(u4YuvBufferAddr, u4YuvBufferSize, VIDEO_NON_CACHEABLE);
    prYuvBufferMgr->pu1BufferStart = (kal_uint8*)u4YuvBufferAddr;

    // FIXME: You may want to set the buffer pointer in the input port.

    return;
}

static void _VideoEncoderAllocateResendQ(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;

    _prMgr->rOutResendQ.pu1BufferAddr =
        (kal_uint8*)VideoGetExtBuffer(_prMgr->prExtMemHdlr, VIDEO_ENCODER_RESEND_Q_NUM*sizeof(VIDEO_BUFFERHEADER_TYPE_T));
}

/******************************************************************************
*
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderAllocateMemoryForBitstream(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_BIT_BUFFER_T* const prBitBufferMgr = &_prMgr->rBitBufferMgr;
    VIDEO_ENCODER_CUSTOM_SETTINGS_T* prCustomSettings = &_prMgr->rCustomSettings;

    prBitBufferMgr->u4BufferSize = prCustomSettings->u4BitBufferSize;
    prBitBufferMgr->u4BufferSize = ROUND_UP_TO_POWER_OF_TWO(prBitBufferMgr->u4BufferSize, 4);

    //prBitBufferMgr->u4BufferSize += GUARD_PATTERN_LEN;
    prBitBufferMgr->pu1BufferStart = (kal_uint8*)VideoGetExtBuffer(_prMgr->prExtMemHdlr, prBitBufferMgr->u4BufferSize);
    prBitBufferMgr->pu1HeaderBuffer = (kal_uint8*)VideoGetExtBuffer(_prMgr->prExtMemHdlr, HEADER_BUFFER_SIZE);
}


/******************************************************************************
*
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderAllocateMemoryForYuvHeader(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VENC_RING_BUFFER_MGR_T* prMgr = &_prMgr->rYUVHeaderQ;

    prMgr->pu1BufferAddr = (kal_uint8*)VideoGetExtBuffer(_prMgr->prExtMemHdlr, _prMgr->rCustomSettings.u4YuvHeaderQSize);
}


/******************************************************************************
*
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderAllocateMemoryForTimeStamp(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;

    _prMgr->rTimeStampQ.pu1BufferAddr =
        (kal_uint8*)VideoGetExtBuffer(_prMgr->prExtMemHdlr, _prMgr->rCustomSettings.u4TimeStampQSize);
}



/******************************************************************************
*
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderAllocateMemoryForChassis(void)
{
#if defined(__VE_VIDEO_VT_SUPPORT__)
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_CHASSIS_MGR_T *prChassisMgr = &_prMgr->rChassisMgr;
    kal_uint32 u4BufferSize;

    prChassisMgr->u4MaxChassis = _prMgr->rCustomSettings.u4ChassisNum;
    u4BufferSize = prChassisMgr->u4MaxChassis * (_prMgr->rCustomSettings.u4ChassisItemSize);
    prChassisMgr->u4BufferSize = u4BufferSize;

    prChassisMgr->prChassisStart = (VIDEO_ENCODER_CHASSIS_T*)VideoGetExtBuffer(_prMgr->prExtMemHdlr, u4BufferSize);
    prChassisMgr->prChassisEnd = prChassisMgr->prChassisStart + prChassisMgr->u4MaxChassis;
#endif  // __VE_VIDEO_VT_SUPPORT__
}



/******************************************************************************
*
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderAllocateMemory(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    kal_uint32 u4QueriedWorkingMemorySize = 0;
    kal_uint32 u4WorkingMemorySize = 0;// = rVideoEncoderMgr.rCustomSettings.u4CodecWorkingMemorySize;
    kal_uint32 u4YuvBufferSize = 0 ;// = rVideoEncoderMgr.rCustomSettings.u4MaxYuvBufferSize;
    kal_uint32 u4FrmeNum = 0;
    VIDEO_ENCODER_CUSTOM_SETTINGS_T* prCustomSettings = &_prMgr->rCustomSettings;

#if defined(__VE_MJPEG_ENC_BYPASS__)
    if (VIDEO_ENCODER_SCENARIO_BYPASS == _prMgr->eEncoderScenario)
    {
        _VENC_DirectCouple_AllocateMemoryForBistreamCtrl();
    }
    else
#endif //__VE_MJPEG_ENC_BYPASS__
    {
        u4WorkingMemorySize = VENC_WORKING_MEM_ADM_OVERHEAD + prCustomSettings->u4CodecMemorySize;//GetCustomCodecMemorySize(prMgr);
        u4FrmeNum = prCustomSettings->u4FrmNum;
        if (KAL_TRUE == _prMgr->fgLimitFrmBuff)
        {
            u4YuvBufferSize = VENC_YUV_BUFFER_SIZE_CAL( _prMgr->u4SourceWidth,
                                                    _prMgr->u4SourceHeight,
                                                    u4FrmeNum);
        }
        else
        {
            u4YuvBufferSize = prCustomSettings->u4MaxYuvBufferSize;
        }

        VideoSetExtCacheBuffer( _prMgr->prExtMemHdlr,
                                (u4YuvBufferSize + u4WorkingMemorySize));

        u4QueriedWorkingMemorySize = _VideoEncoderAllocateMemoryForCodec();
        if (u4QueriedWorkingMemorySize > prCustomSettings->u4CodecMemorySize)
        {
            ASSERT(0);
        }

        if (VIDEO_ENCODER_SCENARIO_ENCODER == _prMgr->eEncoderScenario)
        {
            u4YuvBufferSize += prCustomSettings->u4CodecMemorySize - u4QueriedWorkingMemorySize;
        }
        _VideoEncoderAllocateMemoryForYuv(u4YuvBufferSize);
        _VideoEncoderAllocateMemoryForBitstream();
        _VideoEncoderAllocateMemoryForYuvHeader();
        _VideoEncoderAllocateMemoryForTimeStamp();
        _VideoEncoderAllocateMemoryForChassis();
    }

    _VideoEncoderAllocateResendQ();
}


/******************************************************************************
*
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderSetupCodec(void)
{
    _VideoEncoderInitCodecMemory();
}


/******************************************************************************
*
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderSetupYuv(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_YUV_BUFFER_T* const prYuvBufferMgr = &_prMgr->rYuvBufferMgr;
    VIDEO_COMM_STATE_T* const prCommState = &_prMgr->rCommState;
    VIDEO_COMPONENT_PARAM_T *prComponent = NULL;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_uint8 *pu1BuffStart = prYuvBufferMgr->pu1BufferStart;
    const kal_uint8 u1Alignment = 4;
    kal_uint32 u4SourceWidth = _prMgr->u4SourceWidth;
    kal_uint32 u4SourceHeight = _prMgr->u4SourceHeight;
    kal_uint32 u4FrameMemSize = prYuvBufferMgr->u4FrameMemSize;
    kal_uint32 u4Frames, u4Index, u4PortIndex;
    kal_uint8 *pu1CurAddr;
    kal_uint32 u4AlignReq = 1;

    VIDEO_ENCODER_CUSTOM_SETTINGS_T* prCustomSettings = &rVideoEncoderMgr.rCustomSettings;

    // Query the alignment requirement of frame buffer from adaptor
    // if adaptor returns not_support, default value is 1
    _VideoEncGetParam(_prMgr, VENC_PARAM_FRM_BUFFER_ALIGNMENT, (void*)(&u4AlignReq));

    if (pu1BuffStart == NULL)
    {
        ASSERT(0);
        return;
    }

    // FIXME: Check for alignment or align to the correct boundary???
    // Align the starting address of the YUV buffer.
    pu1BuffStart = (kal_uint8*)ROUND_UP_TO_POWER_OF_TWO(pu1BuffStart, (0x1 << u1Alignment));

    // Because the input source (camera) stores each frame in the YUV
    // 420 format, the required buffer size for each frame is 1.5 times
    // of its frame size (width * height).  If the input format is
    // RGB565, then the buffer size will be 2 times of its frame size.
    u4SourceWidth = ROUND_UP_TO_POWER_OF_TWO(u4SourceWidth, 16);
    u4SourceHeight = ROUND_UP_TO_POWER_OF_TWO(u4SourceHeight, 16);
    u4FrameMemSize = u4SourceWidth * u4SourceHeight * 3 / 2;
    u4FrameMemSize = ROUND_UP_TO_POWER_OF_TWO(u4FrameMemSize, CPU_CACHE_LINE_SIZE);
    prYuvBufferMgr->u4FrameMemSize = u4FrameMemSize;

    // Set the total number of frames.
    u4Frames = prYuvBufferMgr->u4BufferSize / u4FrameMemSize;
    prYuvBufferMgr->u4TotalNum = (u4Frames < VIDEO_ENCODER_MAX_YUV_BUF_NUM) ?
        u4Frames : VIDEO_ENCODER_MAX_YUV_BUF_NUM;

    // Check if the total frame number is smaller than encoder needed
    if (prCustomSettings->u4MinFrmNum > prYuvBufferMgr->u4TotalNum)
    {
        ASSERT(0);
    }

    u4PortIndex = VideoCommGetInputPortIndex(prCommState, VIDEO_PORT_VIDEO_DATA);
    prComponent = VideoCommGetInputComp(prCommState, u4PortIndex);
    if ((prComponent == NULL) || (prComponent->prComp == NULL) ||
        (prComponent->prComp->pfnUseBuffer == NULL))
    {
        ASSERT(0);
        return;
    }

    if (KAL_FALSE == _prMgr->fgInitFrameBuffer)
    {
#if !defined(__VE_SLIM_PROJECT__)
        kal_uint32 u4QueueSize = (VIDEO_ENCODER_INPUT_BUFFER_Q_NUM - 1) + (VIDEO_ENCODER_YUV_HEADER_Q_NUM - 1);
        if ((prYuvBufferMgr->u4TotalNum - 1) > (u4QueueSize))
        {
            // Error check: avoid potential buffer full case
            VIDEO_TRACE4_G9( VENC_YUV_IS_TOO_LARGE, KAL_FALSE, prYuvBufferMgr->u4TotalNum, u4QueueSize, 0);
        }
#endif
        pu1CurAddr = pu1BuffStart;
        pu1CurAddr = (kal_uint8*)((((kal_uint32)pu1CurAddr + (u4AlignReq - 1))/u4AlignReq)*u4AlignReq);
        for (u4Index = 0; u4Index < prYuvBufferMgr->u4TotalNum; u4Index++)
        {
            prYuvBufferMgr->pau1Buff[u4Index] = pu1CurAddr;

            //Set YUV to black, supposed YUV420
            kal_mem_set((void*)pu1CurAddr, 0, ((u4FrameMemSize << 1) / 3));
            kal_mem_set((void*)(pu1CurAddr + ((u4FrameMemSize << 1) / 3)), 128, (u4FrameMemSize / 3));

            eError = prComponent->prComp->pfnUseBuffer(pu1CurAddr, u4FrameMemSize);
            if (eError != VIDEO_ERROR_NONE)
            {
                ASSERT(0);
            }

            pu1CurAddr += u4FrameMemSize;
            pu1CurAddr = (kal_uint8*)((((kal_uint32)(pu1CurAddr) + (u4AlignReq - 1))/u4AlignReq)*u4AlignReq);
        }

        // Inform Source component of the end of UseBuffer().
        eError = prComponent->prComp->pfnUseBuffer(prYuvBufferMgr->pau1Buff[0],
            VIDEO_ENCODER_SET_FRONT_END_TO_IDLE);
        // Do not check eError against VIDEO_ERROR_NONE only.
        _prMgr->fgInitFrameBuffer = KAL_TRUE;
    }

    return;
}


/******************************************************************************
*
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderSetupBitstream(void)
{
    // There is no need to switch bit-stream buffer to non-cacheable.
    _VideoEncoderInitBitstreamBuffer();
    // _VideoEncoderBitstreamSetFullFlag(KAL_FALSE);
}


/******************************************************************************
*
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoEncoderSetupMemory(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VENC_RING_BUFFER_MGR_T *prOutResendQ = &_prMgr->rOutResendQ;

#if defined(__VE_MJPEG_ENC_BYPASS__)
    if (VIDEO_ENCODER_SCENARIO_BYPASS == _prMgr->eEncoderScenario)
    {
        _VENC_DirectCouple_SetupBistreamCtrl();
    }
    else
#endif //__VE_MJPEG_ENC_BYPASS__
    {
        _VideoEncoderSetupYuv();
        _VideoEncoderSetupBitstream();
        _VideoEncoderInitYuvQueue();
        _VideoEncoderInitTimeStampQueue();
#if defined(__VE_VIDEO_VT_SUPPORT__)
        _VideoEncoderInitChassisMgr();
#endif
    }

    _VideoEncoderInitResendQ(prOutResendQ);

    return;
}


/******************************************************************************
* This function set/change the state of the encoder component.
*
* Context: This function runs in the context of the encoder component.
*
* Side effect:
******************************************************************************/
static kal_bool _VideoEncoderSetStateHdlr(kal_uint32 u4Param)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_COMM_STATE_T* const prCommState = &_prMgr->rCommState;
    kal_bool fgRet = KAL_FALSE;

    switch (u4Param)
    {
    case VIDEO_STATE_CLOSE:
        // VideoCommChangeState(prCommState, VIDEO_STATE_CLOSE);
        VCodecFlushItem(VCS_ENCODER);
        fgRet = KAL_TRUE;
        break;

    case VIDEO_STATE_IDLE:
        if (prCommState->eState == VIDEO_STATE_INIT)
        {
            _VideoEncoderAllocateMemory();
            _VideoEncoderSetupMemory();
            // Encoder API initialization
            _VideoEncOpenCodec(_prMgr);
        }
        else if (prCommState->eState == VIDEO_STATE_STOP)
        {
            _VideoEncDeinitCodec(_prMgr);
            _VideoEncoderInitEncoderManager();
            _VideoEncoderSetupMemory();
            _VideoEncoderSetupAdapt();
            _VideoEncInitCodec(_prMgr);
        }
        else
        {
            ASSERT(0);  // FIMXE (Leroy): Print some log.
            return fgRet;
        }
        VideoCommClrAllQ(&_prMgr->rCommState);
        VCodecFlushItem(VCS_ENCODER);
        _prMgr->eIntState = VIDEO_ENCODER_INT_STATE_INIT;
        VideoCommChangeState(prCommState, VIDEO_STATE_IDLE);
        break;

    // No INIT message will be sent because VideoCommInit() wil be called
    // directly to enter the INIT state.
    case VIDEO_STATE_INIT:
        VideoCommChangeState(prCommState, VIDEO_STATE_INIT);
        break;

    case VIDEO_STATE_RUN:
#if defined(__VE_POSTPONE_CODEC_SETTING__)
        if (CODEC_NONE == _prMgr->eCodec)
        {
            ASSERT(0);
        }

        if (KAL_TRUE == _prMgr->fgSetupCodec)
        {
            if (VENC_CODEC_STATE_CLOSE == _prMgr->eCodecState)
            {
                kal_uint32 u4QueriedSize = 0;
                VIDEO_ENCODER_CUSTOM_SETTINGS_T* prCustomSettings = &_prMgr->rCustomSettings;

                u4QueriedSize = _VideoEncoderAllocateMemoryForCodec();
                if (u4QueriedSize > prCustomSettings->u4CodecMemorySize)
                {
                    ASSERT(0);
                }
            }
            _VideoEncOpenCodec(_prMgr);
            _VideoEncoderSetupBitstream();
            _prMgr->fgSetupCodec = KAL_FALSE;
        }
#endif
        _prMgr->fgPauseResume = KAL_TRUE;
        _prMgr->eIntState = VIDEO_ENCODER_INT_STATE_INIT;
        _prMgr->fgSourceNotifyStop = KAL_FALSE;

#if defined(__VE_VENC_PROFILING_VT__)
        _prMgr->u4ProfileStartTime = video_get_current_time();
#endif
        VideoCommChangeState(prCommState, VIDEO_STATE_RUN);
        break;

    case VIDEO_STATE_STOP:
        switch(_prMgr->eIntState)
        {
        case VIDEO_ENCODER_INT_STATE_INIT:
            if (KAL_TRUE == _prMgr->fgStopInstantly)
            {
                _prMgr->eIntState = VIDEO_ENCODER_INT_STATE_STOPPED;
                _prMgr->fgStopInstantly = KAL_FALSE;
                VideoCommChangeState(prCommState, VIDEO_STATE_STOP);
            }
            else
            {
                _prMgr->eIntState = VIDEO_ENCODER_INT_STATE_STOPPING;
            }
            break;
        case VIDEO_ENCODER_INT_STATE_STOPPING:
            _prMgr->eIntState = VIDEO_ENCODER_INT_STATE_STOPPED;
            VideoCommChangeState(prCommState, VIDEO_STATE_STOP);
            break;
        default:
            ASSERT(0);
            break;
        }
        break;

    default:
        _ENCODER_ASSERT();
        break;
    }

    return fgRet;
}

static kal_bool _VENC_HandleErrorWhenSendingBackEndFail(
    VIDEO_ERROR_TYPE_T eError,
    VIDEO_BUFFERHEADER_TYPE_T *prBufferFromResendQ,
    VIDEO_BUFFERHEADER_TYPE_T *prSendingBuffer,
    kal_bool    fgSendOutput
    )
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VENC_RING_BUFFER_MGR_T *prResendQ = &_prMgr->rOutResendQ;

    if (_VideoEncoderCheckError(eError, VIDEO_ERROR_BUFF_FULL))
    {
        if (NULL != prBufferFromResendQ)
        {
            _VideoEncoderInsertToResendQHead(prBufferFromResendQ, prResendQ);
        }
        if (fgSendOutput == KAL_TRUE)
        {
            _VideoEncoderInsertToResendQTail(prSendingBuffer, prResendQ);
        }

        VIDEO_TRACE4_G8( VENC_SEND_BUFFER_FAIL,
            (kal_uint32)(prBufferFromResendQ->pu1Buffer),
            prBufferFromResendQ->u8TimeStamp, BUFFER_PORT_OUTPUT,
            VideoCoreRingBufferUsedNum(&prResendQ->rBufferMgr));

        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }
}

static VIDEO_ERROR_TYPE_T _VideoEncoderSendBuffer(VIDEO_BUFFERHEADER_TYPE_T* prBuffer)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_COMM_STATE_T* const prCommState = &_prMgr->rCommState;
    kal_uint32 u4FunctionStartTime, u4FunctionTime;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    PFN_PROCESS_BUFFER_T pfnOperation = NULL;
    kal_uint32 u4PortIndex = 0;

    u4PortIndex = VideoCommGetOutputPortIndex(prCommState, VIDEO_PORT_VIDEO_DATA);
    pfnOperation = VideoCommGetOutputProcessBufferFunc(prCommState, u4PortIndex);

    u4FunctionStartTime = video_get_current_time();
    eError = pfnOperation(prBuffer);
    u4FunctionTime = video_get_duration_ms(u4FunctionStartTime);

    VIDEO_TRACE4_G10( VENC_SEND2BACKEND,
        (kal_uint32)(prBuffer->pu1Buffer),
        prBuffer->u8TimeStamp,
        prBuffer->u4BuffSize,
        u4FunctionTime);

    return eError;
}

/******************************************************************************
* If there are elements in the output resent
* queue, send them out first and then send the data *prBuffHeader.
* If the receiver cannot receive the data, insert *prBuffHeader into the
* input/output resent queue.
*
* Context: This function runs in the context of the encoder component.
*
* Side effect: perhaps the input/output queue
******************************************************************************/
static kal_bool _VideoEncoderSendToBackEnd(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader,
        kal_bool fgSendOutput)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_BUFFERHEADER_TYPE_T rResentBufferHeader;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VENC_RING_BUFFER_MGR_T *prResendQ = &_prMgr->rOutResendQ;
    kal_bool fgRet = KAL_TRUE;


    if (KAL_TRUE == _VideoEncoderGetResendAtom(&rResentBufferHeader, prResendQ))
    {
        while (1)
        {
            eError = _VideoEncoderSendBuffer(&rResentBufferHeader);

            fgRet = _VENC_HandleErrorWhenSendingBackEndFail(eError, &rResentBufferHeader, prBuffHeader, fgSendOutput);
            if (KAL_FALSE == fgRet)
            {
                break;
            }
            #if defined(__VE_ENC_DUMP_BITSTREAM__)
            if (VIDEO_ERROR_NONE == eError)
            {
                VEBufferTrace(TRACE_GROUP_7, VENC_STORE_BITSTREAM, rResentBufferHeader.u4BuffSize, rResentBufferHeader.pu1Buffer);
            }
            #endif

            if (KAL_FALSE == _VideoEncoderGetResendAtom(&rResentBufferHeader, prResendQ))
            {
                if (fgSendOutput == KAL_TRUE)
                {
                    eError = _VideoEncoderSendBuffer(prBuffHeader);

                    fgRet = _VENC_HandleErrorWhenSendingBackEndFail(eError, NULL, prBuffHeader, KAL_TRUE);
                    #if defined(__VE_ENC_DUMP_BITSTREAM__)
                    if (VIDEO_ERROR_NONE == eError)
                    {
                        VEBufferTrace(TRACE_GROUP_7, VENC_STORE_BITSTREAM, prBuffHeader->u4BuffSize, prBuffHeader->pu1Buffer);
                    }
                    #endif
                }
                break;
            }
        }
    }
    else
    {
        if (fgSendOutput == KAL_TRUE)
        {
            eError = _VideoEncoderSendBuffer(prBuffHeader);

            fgRet = _VENC_HandleErrorWhenSendingBackEndFail(eError, NULL, prBuffHeader, KAL_TRUE);
            #if defined(__VE_ENC_DUMP_BITSTREAM__)
            if (VIDEO_ERROR_NONE == eError)
            {
                VEBufferTrace(TRACE_GROUP_7, VENC_STORE_BITSTREAM, prBuffHeader->u4BuffSize, prBuffHeader->pu1Buffer);
            }
            #endif
        }
    }

    return fgRet;
}


/******************************************************************************
* If there are elements in the YUV
* queue, send them out first and then send the data *prBuffHeader.
* If the receiver cannot receive the data, insert *prBuffHeader into the
* input/output resent queue.
*
* Context: This function runs in the context of the encoder component.
*
* Side effect: perhaps the input/output queue
******************************************************************************/
static kal_bool _VideoEncoderSendToFrontEnd(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_BUFFERHEADER_TYPE_T rBuffHeader;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    PFN_PROCESS_BUFFER_T pfnOperation = NULL;
    VIDEO_COMM_STATE_T* const prCommState = &_prMgr->rCommState;
    kal_uint32 u4StartTime, u4DurationTime, u4PortIndex = 0;
    kal_bool fgRet = KAL_TRUE;

    u4PortIndex = VideoCommGetInputPortIndex(prCommState, VIDEO_PORT_VIDEO_DATA);
    pfnOperation = VideoCommGetInputProcessBufferFunc(prCommState, u4PortIndex);

    while (_VideoEncoderDequeueYuvInfo(&rBuffHeader) == KAL_TRUE)
    {
        u4StartTime = video_get_current_time();
        eError = pfnOperation(&rBuffHeader);
        u4DurationTime = video_get_duration_ms(u4StartTime);

        VIDEO_TRACE4_G10( VENC_SEND2FRONTEND,
            (kal_uint32)(rBuffHeader.pu1Buffer),
            (kal_uint32)(rBuffHeader.u8TimeStamp),
            rBuffHeader.u4BuffSize,
            u4DurationTime);

        if (_VideoEncoderCheckError(eError, VIDEO_ERROR_BUFF_FULL))
        {
            _VideoEncoderEnqueueYuvInfoAtHead(&rBuffHeader);

            VIDEO_TRACE4_G8( VENC_SEND_BUFFER_FAIL,
                (kal_uint32)(rBuffHeader.pu1Buffer),
                (kal_uint32)(rBuffHeader.u8TimeStamp), BUFFER_PORT_INPUT,
                VideoCoreRingBufferUsedNum(&_prMgr->rYUVHeaderQ.rBufferMgr));

            fgRet = KAL_FALSE;
            break;
        }
    }

    return fgRet;
}


/******************************************************************************
* Retrieve a buffer header from the output buffer queue.
*
* Context: This function runs in the context of the encoder component.
*
* Side effect: the output buffer queue
******************************************************************************/
static kal_bool _VideoEncoderPopOutputBuff(VIDEO_ENCODER_MGR_T *prEncoderMGR,
        VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader, VIDEO_ENCODER_ACTION_T *pAction,
        kal_bool *pfgCheckFlag)
{
    VIDEO_COMM_STATE_T* const prCommState = &prEncoderMGR->rCommState;

    if (VideoCommPopOutputBuff(prCommState, prBuffHeader))
    {
        *pAction = ACTION_OUTPUT_BUFFER;
        prEncoderMGR->u4OutputQueueNumber--;
        *pfgCheckFlag = KAL_TRUE;
        return KAL_TRUE;
    }
    else
    {
        *pAction = ACTION_NONE;
        *pfgCheckFlag = KAL_FALSE;
        return KAL_FALSE;
    }
}
#define BYTE_TO_BITS    8

#if defined(__VE_VENC_PROFILING_VT__)
static void _VideoEncoderVTProfileSub(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;

    VIDEO_TRACE4_G9( VENC_ENC_RATE,
        (kal_uint32)(_prMgr->u4EncodedFrameNum),
        (kal_uint32)(_prMgr->u4TimePassed),
        (kal_uint32)(_prMgr->u4EncodedBits),
        (kal_uint32)(_prMgr->u4ProfileStartTime));

    _prMgr->u4EncodedFrameNum  =   0;
    _prMgr->u4EncodedBits      =   0;
    _prMgr->u4TimePassed       %=  1000;
}
#endif //__VE_VENC_PROFILING_VT__

static void _VideoEncoderVTAddFrameNBit(kal_uint32 u4AddEncoded, kal_uint32 u4AddBits)
{
#if defined(__VE_VENC_PROFILING_VT__)
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;

    _prMgr->u4EncodedFrameNum  +=  u4AddEncoded;
    _prMgr->u4EncodedBits      +=  u4AddBits;
#endif
}

static void _VideoEncoderVTProfile(kal_bool fgForceDumpLog)
{
#if defined(__VE_VENC_PROFILING_VT__)
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;

    _prMgr->u4TimePassed += video_get_duration_ms(_prMgr->u4ProfileStartTime);
    _prMgr->u4ProfileStartTime = video_get_current_time();

    if (_prMgr->u4TimePassed >= 1000)
    {
        //1 second has passed
        _VideoEncoderVTProfileSub();
    }
    else
    {
        if (KAL_TRUE == fgForceDumpLog)
        {
            _VideoEncoderVTProfileSub();
        }
        else
        {
        }
    }
#endif
}

/******************************************************************************
* Perform the following operations in the specified order.
* (1) If the bit-stream buffer has no free space, return ACTION_NONE.
* (2) If the output Resend queue is full, return ACTION_RESEND_BITSTREAM.
* (3) If the input Resend queue is full, return ACTION_RETURN_YUV.
* (4) If the bit-stream buffer does not have enough space, return ACTION_NONE.
* (5) If there is at least one buffer header in the input buffer queue, retrieve
*     a buffer header and return ACTION_INPUT_BUFFER.
* (6) If none of the above is performed, return ACTION_NONE.
*
* Context: This function runs in the context of the encoder component.
*
* Side effect: the input buffer queue
******************************************************************************/
static void _VideoEncoderPopInputBuff(VIDEO_ENCODER_MGR_T *_prMgr,
        VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader, VIDEO_ENCODER_ACTION_T *pAction,
        kal_bool *pfgCheckFlag)
{
    VIDEO_COMM_STATE_T* const prCommState = &_prMgr->rCommState;

    *pfgCheckFlag = KAL_FALSE;

    if (_VideoEncoderIsResendQFull(&_prMgr->rOutResendQ,
        VIDEO_ENCODER_RESEND_ABOUT_FULL))
    {
        *pAction = ACTION_RESEND_BITSTREAM;
        VIDEO_TRACE0_G10( VENC_OUTPUT_RESENT_FULL);
        return;
    }

#if defined(__VE_MJPEG_ENC_BYPASS__)
    if (VIDEO_ENCODER_SCENARIO_BYPASS == _prMgr->eEncoderScenario)
    {
    }
    else
#endif
    {
        if (KAL_TRUE == _VideoEncoderIsFirstYuvNotUsed())
        {
            // The first YUV will not be used any more.
            *pAction = ACTION_RETURN_YUV;
            return;
        }

        if (KAL_TRUE == _VideoEncoderIsBitstreamBufferFull())
        {
            // Bitstream buffer is full.
            *pAction = ACTION_NONE;
            return;
        }


        // Pop an item out of the input header buffer queue only when the YUV
        // queue and the time-stamp queue have at least one free slot in each
        // of them
        if ((_VideoEncoderIsTimeStampQueueFull() == KAL_TRUE) ||
            (_VideoEncoderIsYuvQueueFull() == KAL_TRUE))
        {
            *pAction = ACTION_NONE;
            return;
        }

        if (_VideoEncoderFirstFrameNotReceived(prBuffHeader) == KAL_TRUE)
        {
            *pAction = ACTION_ENCODE_OLD_FRAME;
            return;
        }
    }

    // FIXME (Leroy): Pop an item from the input header buffer queue only
    //                when the YUV queue has at least one free slot.
    if (VideoCommPopInputBuff(prCommState, prBuffHeader))
    {
        *pAction = ACTION_INPUT_BUFFER;
        _prMgr->u4InputQueueNumber--;
        *pfgCheckFlag = KAL_TRUE;
    }
    else
    {
        *pAction = ACTION_NONE;
    }
    return;
}


/******************************************************************************
* Context: This function runs in the context of the encoder component.
*
* Side effect:
******************************************************************************/
static void _VideoEncoderGetBitstream2Send(kal_bool *pfgSendResult)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_PRIVATE_OUTPUT_T rPrivateOutput;
    VIDEO_ENCODER_CODEC_ERROR_T eCodecError = VIDEO_ENCODER_CODEC_ERROR_NONE;
    VIDEO_BUFFERHEADER_TYPE_T rOutBufferHeader;
    kal_uint32 u4OutputPortIndex = 0;
    VIDEO_PORT_TYPE_T ePortType = VIDEO_PORT_VIDEO_DATA;
    VIDEO_COMM_STATE_T* const prCommState = &_prMgr->rCommState;

    *pfgSendResult = KAL_TRUE;
    while (1)
    {
        kal_uint8 *pu1Buffer;
        VIDEO_COMPONENT_PARAM_T *prCompParam = NULL;

        kal_mem_set((void*)&rOutBufferHeader, 0, sizeof(rOutBufferHeader));

#if defined(__VE_VIDEO_VT_SUPPORT__)
        if (_prMgr->eEncoderScenario == VIDEO_ENCODER_SCENARIO_VT)
        {
            _rChassis.parPktInfo = _rChassis.arPktInfo;
            rPrivateOutput.prChassis = &_rChassis;
        }
#endif  // __VE_VIDEO_VT_SUPPORT__

        // kal_mem_set((void*)&rPrivateOutput, 0, sizeof(rPrivateOutput));
        rPrivateOutput.fgEndOfFrame = KAL_FALSE;

        // Check whether resend queue is almost full
        if (_VideoEncoderIsResendQFull(&_prMgr->rOutResendQ,
            VIDEO_ENCODER_RESEND_ABOUT_FULL))
        {
            *pfgSendResult = KAL_FALSE;
            VIDEO_TRACE0_G10( VENC_OUTPUT_RESENT_FULL);
            break;
        }


        // Get the coded bit stream from the adaptation layer.
        eCodecError = _prMgr->prCodecAPI->pfnGetNextBitstream(&pu1Buffer, &rPrivateOutput);
        VIDEO_TRACE2_G9( VENC_GET_BITSTREAM, (kal_uint32)pu1Buffer, rPrivateOutput.u4BitstreamLength);

        if (eCodecError != VIDEO_ENCODER_CODEC_ERROR_NONE)
        {
            ASSERT(0);
        }

        if (pu1Buffer == NULL)
        {
            if (rPrivateOutput.eFrameType == VIDEO_CODEC_HEADER)
            {
                // if pu1Buffer == NULL and VIDEO_CODEC_HEADER
                // bitstream length should be 0
                if (rPrivateOutput.u4BitstreamLength != 0)
                {
                    ASSERT(0);
                }
                break;
            }
            else
            {
                if (rPrivateOutput.fgEndOfFrame == KAL_TRUE)
                {
                    // This one is for YUV recorder, which has no bitstream to output but still have to dequeue timestamp
                    // to make Encoder Component running normally
                    _VideoEncoderDequeueTimeStamp();
                }
                else
                {
                    // since adaptation should return frame-based bitstrream, fgEndOfFrame should never be KAL_FALSE
                    //ASSERT(0);
                }
                break;
            }
        }

        _VideoEncoderGetTimeStamp(&rOutBufferHeader.u8TimeStamp);
        if (rPrivateOutput.fgEndOfFrame == KAL_TRUE)
        {
            _VideoEncoderDequeueTimeStamp();
            rOutBufferHeader.eFlags |= VIDEO_BUFFERFLAG_END_OF_FRAME;
        }

#if defined(__VE_ENABLE_CODEC_ADJUST_TIME__)
        if (KAL_TRUE == rPrivateOutput.fgUpdateTimeStamp)
        {
            rOutBufferHeader.u8TimeStamp = rPrivateOutput.u8TimeStamp;
        }
#endif

#if defined(__VE_VIDEO_VT_SUPPORT__)
        if (_prMgr->eEncoderScenario == VIDEO_ENCODER_SCENARIO_VT)
        {
            // Collect the info for a whole frame/chassis.
            if (_pu1BitBuffer == NULL)
            {
                _pu1BitBuffer = pu1Buffer;
            }
            _u4AccumulatedBitBufferSize += rPrivateOutput.u4BitstreamLength;
            _VideoEncoderVTAddFrameNBit(0, rPrivateOutput.u4BitstreamLength*BYTE_TO_BITS);
            _VideoEncoderVTProfile(KAL_FALSE);

            //drv_trace2(TRACE_GROUP_9, VENC_DEBUG_EACH_QUERY,
            //    (kal_uint32)pu1Buffer, rPrivateOutput.u4BitstreamLength);

            if ((rPrivateOutput.fgEndOfFrame == KAL_TRUE) ||
                (rPrivateOutput.eFrameType == VIDEO_CODEC_HEADER))
            {
                rPrivateOutput.prChassis = _VideoEncoderInsertChassis(rPrivateOutput.prChassis);
                rOutBufferHeader.pPrivateData = (void*)rPrivateOutput.prChassis;
                kal_mem_set((void*)&_rChassis, 0, sizeof(_rChassis));

                pu1Buffer = _pu1BitBuffer;
                _pu1BitBuffer = NULL;

                rPrivateOutput.u4BitstreamLength = _u4AccumulatedBitBufferSize;
                _u4AccumulatedBitBufferSize = 0;

                // FIXME (Leroy): Print some info here.
                //drv_trace2(TRACE_GROUP_9, VENC_DEBUG_ACCUMULATED,
                //    (kal_uint32)pu1Buffer, rPrivateOutput.u4BitstreamLength);

                //drv_trace4(TRACE_GROUP_9, VENC_DEBUG_BIT_BUFFER_INTO,
                //    (kal_uint32)rVideoEncoderMgr.rBitBufferMgr.pu1RP,
                //    (kal_uint32)rVideoEncoderMgr.rBitBufferMgr.pu1WP,
                //    (kal_uint32)rVideoEncoderMgr.rBitBufferMgr.pu1EarlyEnd, 0);
            }
            else
            {
                continue;
            }
        }
#endif  // __VE_VIDEO_VT_SUPPORT__

        u4OutputPortIndex = VideoCommGetOutputPortIndex(prCommState, ePortType);
        prCompParam = VideoCommGetOutputComp(prCommState, u4OutputPortIndex);
        rOutBufferHeader.u4InputPort = prCompParam->u4PortIndex;
        rOutBufferHeader.u4OutputPort = u4OutputPortIndex;
        rOutBufferHeader.pu1Buffer = pu1Buffer;
        rOutBufferHeader.u4BuffSize = rPrivateOutput.u4BitstreamLength;

        if (rPrivateOutput.eFrameType == VIDEO_CODEC_FRAMETYPE_I)
        {
            rOutBufferHeader.eFlags |= VIDEO_BUFFERFLAG_SYNCFRAME;
        }
        else if (rPrivateOutput.eFrameType == VIDEO_CODEC_HEADER)
        {
            rOutBufferHeader.eFlags |= VIDEO_BUFFERFLAG_PARAMETERSET;
#if defined(__VE_H264_ENC_SW_SUPPORT__)
            if (VIDEO_ENCODER_SCENARIO_ENCODER == _prMgr->eEncoderScenario)
            {
                rOutBufferHeader.pPrivateData = (void*)(_prMgr->u4CodecConfig);
            }
#endif
        }
        else
        {
            rOutBufferHeader.eFlags |= VIDEO_BUFFERFLAG_NONE;
        }

        if (!(rOutBufferHeader.eFlags & VIDEO_BUFFERFLAG_PARAMETERSET))
        {
            if (rOutBufferHeader.pu1Buffer + rOutBufferHeader.u4BuffSize <=  _prMgr->rBitBufferMgr.pu1BufferEnd)
            {
                *pfgSendResult = _VideoEncoderSendToBackEnd(&rOutBufferHeader, KAL_TRUE);
            }
            else
            {
                if (_prMgr->eEncoderScenario != VIDEO_ENCODER_SCENARIO_VT)
                {
                    kal_uint32 u4BitLengthFromHead = rOutBufferHeader.u4BuffSize - (_prMgr->rBitBufferMgr.pu1BufferEnd - rOutBufferHeader.pu1Buffer);
                    kal_bool fgEndOfFrame = (rOutBufferHeader.eFlags & VIDEO_BUFFERFLAG_END_OF_FRAME)?(KAL_TRUE):(KAL_FALSE);

                    if (KAL_TRUE == fgEndOfFrame)
                    {
                        rOutBufferHeader.eFlags &= ~VIDEO_BUFFERFLAG_END_OF_FRAME;
                    }
                    rOutBufferHeader.u4BuffSize -= u4BitLengthFromHead;
                    *pfgSendResult = _VideoEncoderSendToBackEnd(&rOutBufferHeader, KAL_TRUE);

                    if (KAL_TRUE == fgEndOfFrame)
                    {
                        rOutBufferHeader.eFlags |= VIDEO_BUFFERFLAG_END_OF_FRAME;
                    }
                    rOutBufferHeader.pu1Buffer = _prMgr->rBitBufferMgr.pu1BufferStart;
                    rOutBufferHeader.u4BuffSize = u4BitLengthFromHead;
                    *pfgSendResult = _VideoEncoderSendToBackEnd(&rOutBufferHeader, KAL_TRUE);
                }
                else
                {
                    *pfgSendResult = _VideoEncoderSendToBackEnd(&rOutBufferHeader, KAL_TRUE);
                }
                //Check guard pattern
                //_VideoEncoderCheckGuardPattern(rVideoEncoderMgr.rBitBufferMgr.pu1BufferEnd + 1);
            }
        }
        else
        {
            *pfgSendResult = _VideoEncoderSendToBackEnd(&rOutBufferHeader, KAL_TRUE);
        }
    }

    return;
}

static void _VideoEncoderCleanItem(VIDEO_BUFFERHEADER_TYPE_T *prBufferHeader, VENC_CLEAN_TIME_T eCleanTime)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;

    if (VENC_CLEAN_AT_ENCODE_DONE == _prMgr->eCleanMode)
    {
        if (AT_ENCODE_DONE == eCleanTime)
        {
            //rVideoEncoderMgr.fgHWEncoderPaused  = KAL_FALSE;
            _prMgr->u4CleanCnt++;
            kal_mem_cpy((void*)&_prMgr->rDummyBufferHeader, (void*)prBufferHeader, sizeof(VIDEO_BUFFERHEADER_TYPE_T));
            //VCodecCtrlCleanItem(VCS_ENCODER, prBufferHeader);
        }
    }
    else if (VENC_CLEAN_AFTER_ENCODE == _prMgr->eCleanMode)
    {
        if (AFTER_ENCODE == eCleanTime)
        {
            VCodecCtrlCleanItem(VCS_ENCODER, prBufferHeader);
        }
    }
    else
    {
        _ENCODER_ASSERT();
    }
}

static void _VideoEncoderRetriggerEncoder(VIDEO_ENCODER_ACTION_T eAction)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    kal_uint32 u4EncodeStartTime, u4EncodeTime;
    VIDEO_ENCODER_CODEC_ERROR_T eCodecError;

    if (KAL_TRUE == _prMgr->fgGenerateHeader)
    {
        VIDEO_TRACE4_G10( VENC_ENCODE_ONE_UINT,
                    (kal_uint32)0,
                    (kal_uint32)0,
                    __LINE__, eAction);

        u4EncodeStartTime = video_get_current_time();
        VIDEO_START_LOGGING("EN2");
        eCodecError = _prMgr->prCodecAPI->pfnEncodeOneUnit(NULL);
        VIDEO_STOP_LOGGING("EN2");
        u4EncodeTime = video_get_duration_ms(u4EncodeStartTime);
        _VideoEncoderStoreEncodingTime(u4EncodeTime);
        VIDEO_TRACE1_G10( VENC_ENCODE_PROFILE, u4EncodeTime);

        if(VIDEO_ENCODER_CODEC_PARAM_NOT_SUPPORT == eCodecError)
        {
            ASSERT(0);
        }
    }
}

static VIDEO_ENCODER_ACTION_T _VENC_DecideAction(
    VIDEO_BUFFERHEADER_TYPE_T* prBufferHeader,
    VIDEO_COMMAND_TYPE_T* peType,
    kal_uint32* pu4Param)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_ACTION_T eAction;
    VIDEO_COMM_STATE_T* const prCommState = &_prMgr->rCommState;
    kal_bool fgCheckFlag;

    // Don't need to memset
#if !defined(__VE_SLIM_PROJECT__)
    kal_mem_set((void*)prBufferHeader, 0, sizeof(*prBufferHeader));
#endif

    if (VideoCommPopCommand(prCommState, peType, pu4Param))
    {
        return ACTION_COMMAND;
    }
    else if (VideoCommGetState(prCommState) == VIDEO_STATE_RUN)
    {
        if (!_VideoEncoderPopOutputBuff(_prMgr,
                                prBufferHeader, &eAction, &fgCheckFlag))
        {
            _VideoEncoderPopInputBuff(_prMgr,
                                prBufferHeader, &eAction, &fgCheckFlag);
        }

        return eAction;
    }
    else
    {
        // No command is found, and the codec is not in the RUN state.
        return ACTION_NONE;
    }
}

static kal_bool _VENC_IsReachTimeLimit(kal_uint64 u8Time)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;

    if ((_prMgr->u8TimeLimit != 0) &&
        (u8Time >= _prMgr->u8TimeLimit))
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

static void _VENC_Callback2IL(VIDEO_EVENT_TYPE_T eEvent)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ERROR_TYPE_T eRet;
    VIDEO_CALLBACK_TYPE_T *prCallback;

    prCallback = VideoCommGetCallback(&_prMgr->rCommState);
    eRet = prCallback->pfnEventHandler(eEvent, VIDEO_COMMAND_NOTIFY, NULL, NULL);
    if (VIDEO_ERROR_NONE != eRet)
    {
        ASSERT(0);
    }
}

static void _VENC_UpdateStatusAfterCodecReceivedFrame(VIDEO_BUFFERHEADER_TYPE_T * prBufferHeader)
{
    _VideoEncoderSetReceivedFlag(prBufferHeader->pu1Buffer);
    _VideoEncoderCleanItem(prBufferHeader, AFTER_ENCODE);
}

static void _VideoEncoderWakeupTimer(kal_bool fgSendInputBufferResult, kal_bool fgSendOutputBufferResult)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    kal_uint16 u2TimeOutTick = 10;
    if (_prMgr->fgStartWakeUpTimer == KAL_FALSE)
    //if (rVideoDecoderMgr.u4InputCommonQueueNumber | rVideoDecoderMgr.u4OutputCommonQueueNumber)
    {
       kal_set_timer(_prMgr->rTimerID, _VideoEncoderClkWakeUp, NULL, u2TimeOutTick, 0);
       _prMgr->fgStartWakeUpTimer = KAL_TRUE;
       VIDEO_TRACE2_G10( VENC_ACTIVATE_TIMER, (kal_uint32)fgSendInputBufferResult, (kal_uint32)fgSendOutputBufferResult);
    }
}

/******************************************************************************
* Context: This function runs in the context of the encoder component.
*
* Side effect:
******************************************************************************/
static void _VideoEncoderDataHdlr(ilm_struct *prIlm)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_COMM_STATE_T* const prCommState = &_prMgr->rCommState;
    VIDEO_ENCODER_CODEC_API_T* prCodecAPI = NULL;

    if (_prMgr->fgStartWakeUpTimer == KAL_TRUE)
    {
        kal_cancel_timer(_prMgr->rTimerID);
        _prMgr->fgStartWakeUpTimer = KAL_FALSE;
    }

    VideoCommClrProcessing(prCommState);

    do {
        // If fgCheckFlag is TRUE, a buffer header is retrieved from the input or output buffer.
        // Each of the following assignment operations is executed at each iteration of the loop.
        kal_bool fgSendOutputBufferResult = KAL_TRUE;
        kal_bool fgSendInputBufferResult = KAL_TRUE;
        kal_uint32 u4Param;
        VIDEO_ENCODER_ACTION_T eAction = ACTION_NONE;
        VIDEO_COMMAND_TYPE_T eType = VIDEO_COMMAND_MAX;
        VIDEO_BUFFERHEADER_TYPE_T rBufferHeader, rOutBufferHeader;
        VCODEC_SCHEDULE_TASKQUEUE_T eTaskControl = VCS_TASKQUEUE_EXPECTED_TARGET;

        prCodecAPI = _prMgr->prCodecAPI;

#if !defined(__VE_SLIM_PROJECT__)
        kal_mem_set((void*)&rOutBufferHeader, 0, sizeof(rOutBufferHeader));
#endif
        eAction = _VENC_DecideAction(&rBufferHeader, &eType, &u4Param);

        _VideoEncoderDebugQueueLength();

        while(0 != _prMgr->u4CleanCnt)
        {
            if (!(_prMgr->u4CleanCnt <= 1))
            {
                ASSERT(0);
            }
            _prMgr->u4CleanCnt--;
            VCodecCtrlCleanItem(VCS_ENCODER, &_prMgr->rDummyBufferHeader);
        }

        // Note: eAction may be changed in _VideoEncoderPopOutputBuff() or
        //       _VideoEncoderPopInputBuff().
        if (eAction == ACTION_NONE)
        {
#if defined(__VE_MJPEG_ENC_BYPASS__)
            if (VIDEO_ENCODER_SCENARIO_BYPASS == _prMgr->eEncoderScenario)
            {
            }
            else
#endif
            {
                _VideoEncoderResetScheduler();

                if (_prMgr->fgGenerateHeader == KAL_TRUE)
                {
                    _VideoEncoderGetBitstream2Send(&fgSendOutputBufferResult);

                    if (KAL_TRUE == _prMgr->fgTriggerEncoder)
                    {
                        _VideoEncoderRetriggerEncoder(eAction);

                        _prMgr->fgTriggerEncoder = KAL_FALSE;
                        _VideoEncoderGetBitstream2Send(&fgSendOutputBufferResult);
                    }
                }

                if (VIDEO_ENCODER_INT_STATE_STOPPING == _prMgr->eIntState)
                {
                    if (KAL_TRUE == _prMgr->fgSourceNotifyStop)
                    {
                        if(0 == _prMgr->u4InputQueueNumber)
                        {
                            if (KAL_TRUE == _VideoEncoderIsCodecRecieveLastYUV(&_prMgr->rYUVHeaderQ.rBufferMgr))
                            {
                                kal_bool fgFlush = KAL_TRUE;

                                //kal_prompt_trace(MOD_VIDEO, "[DBG]Set VENC_PARAM_FLUSH_CODEC 2/ %d, source eof = %d", fgFlush, _prMgr->fgSourceNotifyStop);
                                _VideoEncoderSetParam2AdaptDirect(VENC_PARAM_FLUSH_CODEC, (void*)(&fgFlush));
                                _prMgr->fgFlushedCodec = KAL_TRUE;
                            }
                        }
                    }
                    else
                    {
                        _VideoEncoderWakeupTimer(KAL_FALSE, KAL_FALSE);
                    }

                    _VideoEncoderRetriggerEncoder(eAction);
                }
            }

            VIDEO_TRACE4_G10( VENC_STATUS,
                _prMgr->u4InputQueueNumber,
                _prMgr->u4OutputQueueNumber,
                VideoCoreRingBufferUsedNum(&_prMgr->rOutResendQ.rBufferMgr),
                (kal_uint32)_VideoEncoderIsBitstreamBufferFull());
            break;
        }

        switch (eAction)
        {
            kal_uint32 u4EncodeStartTime, u4EncodeTime;
            VIDEO_ENCODER_CODEC_ERROR_T eCodecError;
            kal_bool fgReachTimeLimit;

        case ACTION_COMMAND:
            VIDEO_TRACE2_G10( VENC_COMMAND, eType, u4Param);

            if (eType != VIDEO_COMMAND_STATESET)
            {
                // Duplicate with VideoEncoderSendCommand
                _ENCODER_ASSERT();  // VIDEO_COMMAND_NOTIFY would also be asserted
            }

            _prMgr->fgClosingEncoder = _VideoEncoderSetStateHdlr(u4Param);
            break;

        case ACTION_OUTPUT_BUFFER:
            // FIXME: Wrap the following statements in a function named
            //        _VideoEncoderProcessBackEndRequest().
            VIDEO_TRACE2_G8( VENC_PROCESS_OUTPUT,
                (kal_uint32)(rBufferHeader.pu1Buffer), rBufferHeader.u4BuffSize);

#if defined(__VE_MJPEG_ENC_BYPASS__)
            if (VIDEO_ENCODER_SCENARIO_BYPASS == _prMgr->eEncoderScenario)
            {
                _VENC_DirectCouple_SetBistreamAvailable(rBufferHeader.pu1Buffer);
            }
            else
#endif //__VE_MJPEG_ENC_BYPASS__
            {
                // Move bit-stream RP forward.
                if (!(rBufferHeader.eFlags & VIDEO_BUFFERFLAG_PARAMETERSET))
                {
                    VideoEncoderUpdateBitstreamRP(rBufferHeader.pu1Buffer, rBufferHeader.u4BuffSize);

                }

                // When a bit-stream buffer is returned from the back-end component,
                // it implies that the component has space for receiving header info.
                // KAL_FALSE in the function means that rOutBufferHeader is dummy data.
                fgSendOutputBufferResult = _VideoEncoderSendToBackEnd(&rOutBufferHeader,
                    KAL_FALSE);

                // Trigger the encoder codec to re-encode.
                //if (0 != rVideoEncoderMgr.u1CodecTriggerRefCnt)
                //if (KAL_TRUE == rVideoEncoderMgr.fgTriggerEncoder)
                {
                    _VideoEncoderRetriggerEncoder(eAction);
                    _prMgr->fgTriggerEncoder = KAL_FALSE;
                    _VideoEncoderGetBitstream2Send(&fgSendOutputBufferResult);
                }
            }
            break;

        case ACTION_RESEND_BITSTREAM:
            // Call _VideoEncoderSendToBackEnd() to flush the output Resend queue.
            // KAL_FALSE in the function means that rOutBufferHeader is dummy data.
            fgSendOutputBufferResult =
                _VideoEncoderSendToBackEnd(&rOutBufferHeader, KAL_FALSE);
            break;

        case ACTION_ENCODE_OLD_FRAME:
            eTaskControl = VCodecCtrlGetTaskControl(VCS_ENCODER);
            if (VCS_TASKQUEUE_NOT_EXPECTED_TARGET == eTaskControl)
            {
                _VideoEncoderWakeUp(MSG_WAKEUP, 0);
                break;
            }

            if (_prMgr->fgGenerateHeader == KAL_FALSE)
            {
                kal_bool fgEnable = KAL_FALSE;

                _VideoEncoderSetupAdapt();
                _VideoEncInitCodec(_prMgr);

                _VideoEncGetParam(_prMgr, VENC_PARAM_HOLD_RES_TILL_RELEASE_FRM, (void*)(&fgEnable));
                _prMgr->eCleanMode =
                    (KAL_TRUE == fgEnable)? (VENC_CLEAN_AT_ENCODE_DONE): (VENC_CLEAN_AFTER_ENCODE);

                // Buffer for header would be different than bitstream
                // Switch the buffer for storing header
                _VideoEncoderSetBitBufferState(VENC_BITBUFF_HEADER);
                eCodecError = prCodecAPI->pfnGenerateHeader();
                if (VIDEO_ENCODER_CODEC_ERROR_NONE != eCodecError)
                {
                    ASSERT(0);
                }

#if defined(__VE_H264_ENC_SW_SUPPORT__)
                _prMgr->u4CodecConfig = 0;
                _VideoEncGetParam(_prMgr, VENC_PARAM_GET_CODEC_CONFIG, (void*)(&_prMgr->u4CodecConfig));
#endif

                _VideoEncoderGetBitstream2Send(&fgSendOutputBufferResult);
                _prMgr->fgGenerateHeader = KAL_TRUE;
            }

            // Encode an unit
            if ((rBufferHeader.eFlags & VIDEO_BUFFERFLAG_EXCEED_TIME_LIMIT)
              ||(rBufferHeader.eFlags & VIDEO_BUFFERFLAG_INVALID_FRAME))
            {
                _VENC_UpdateStatusAfterCodecReceivedFrame(&rBufferHeader);
                VideoEncoderReleaseYUV(rBufferHeader.pu1Buffer);
            }
            else
            {
                VIDEO_TRACE4_G10( VENC_ENCODE_ONE_UINT,
                    (kal_uint32)rBufferHeader.pu1Buffer,
                    (kal_uint32)rBufferHeader.u8TimeStamp,
                    __LINE__, eAction);
                if(KAL_TRUE == *(kal_bool*)rBufferHeader.pPrivateData)
                {
                    kal_bool fgForce = KAL_TRUE;
                    _VideoEncoderSetParam2AdaptDirect(VENC_PARAM_FORCE_ENCODE_I, (void*)(&fgForce));
                }
                u4EncodeStartTime = video_get_current_time();
                // Switch the buffer for storing bitstream
                _VideoEncoderSetBitBufferState(VENC_BITBUFF_BITSTREAM);
                VIDEO_START_LOGGING("EN0");
                #if defined(__SELF_TEST__)
                VIDEO_START_LOGGING("CPY");
                {
                    kal_uint32 u4YSize = rVideoEncoderMgr.u4SourceWidth * rVideoEncoderMgr.u4SourceHeight;
                    kal_mem_set(rBufferHeader.pu1Buffer, 127, u4YSize);
                    kal_mem_set(rBufferHeader.pu1Buffer + u4YSize, 0, (u4YSize>>1));
                    kal_mem_set(rBufferHeader.pu1Buffer + (u4YSize + (u4YSize>>1)), 0, (u4YSize>>1));
                }
                VIDEO_STOP_LOGGING("CPY");
                #endif
                eCodecError = prCodecAPI->pfnEncodeOneUnit(&rBufferHeader);
                VIDEO_STOP_LOGGING("EN0");
                u4EncodeTime = video_get_duration_ms(u4EncodeStartTime);

                _VideoEncoderStoreEncodingTime(u4EncodeTime);
                switch(eCodecError)
                {
                case VIDEO_ENCODER_CODEC_BS_BUFFER_NOT_ENOUGH:
                    _VideoEncoderBitstreamSetFullFlag(KAL_TRUE);
                    VIDEO_LABEL_LOGGING("DP0");
                    VIDEO_TRACE1_G8( VENC_REMAIN_JOBS, 0);
                    _VideoEncoderCtrlMoveItem();
                    break;
                case VIDEO_ENCODER_CODEC_ERROR_NONE:
                    VIDEO_TRACE1_G10( VENC_ENCODE_PROFILE, u4EncodeTime);
                    _VENC_UpdateStatusAfterCodecReceivedFrame(&rBufferHeader);
#if defined(__VE_VENC_PROFILING_CODEC__)
                    _prMgr->u4AccumEncodedFrames++;
#endif //(__VE_VENC_PROFILING_CODEC__)
                    break;
                default:
                    ASSERT(0);
                    break;
                }
            }

            _VideoEncoderGetBitstream2Send(&fgSendOutputBufferResult);
            fgSendInputBufferResult = _VideoEncoderSendToFrontEnd();
            break;

        case ACTION_INPUT_BUFFER:
            fgReachTimeLimit = _VENC_IsReachTimeLimit(rBufferHeader.u8TimeStamp);

#if defined(__VE_TIME_LAPSE_VIDEO_RECORDER__)
            // Time lapse is enabled
            if (KAL_TRUE == fgReachTimeLimit)
            {
                // Do nothing
            }
            else if (_prMgr->u4TLCaptureFrameDuration != 0)
            {
                if (rBufferHeader.u8TimeStamp >= _prMgr->u8TLCaptureFrameTime)
                {

                    VIDEO_TRACE8_G10( VENC_TIME_LAPSE_CAPTURE,
                                      _prMgr->u4TLCaptureFrameDuration,
                                      ONE_SEC_IN_MICROSEC/_prMgr->u4TLEncodedFrameDuration,
                                      rBufferHeader.u8TimeStamp >> 32, rBufferHeader.u8TimeStamp & 0xFFFFFFFF, _prMgr->u8TLCaptureFrameTime >> 32, _prMgr->u8TLCaptureFrameTime & 0xFFFFFFFF, 0, 0);

                    _prMgr->u8TLCaptureFrameTime = (rBufferHeader.u8TimeStamp / ONE_SEC_IN_MICROSEC) * ONE_SEC_IN_MICROSEC + _prMgr->u4TLCaptureFrameDuration;

                    // Update time
                    rBufferHeader.u8TimeStamp = _prMgr->u8TLEncodedFrameTime;
                    _prMgr->u8TLEncodedFrameTime += _prMgr->u4TLEncodedFrameDuration;
                }
                else
                {
                    rBufferHeader.eFlags |= VIDEO_BUFFERFLAG_INVALID_FRAME;
                }
            }
#endif

#if defined(__VE_MJPEG_ENC_BYPASS__)
            if (VIDEO_ENCODER_SCENARIO_BYPASS == _prMgr->eEncoderScenario)
            {
                kal_uint32 u4OutputPortIndex = VideoCommGetOutputPortIndex(prCommState, VIDEO_PORT_VIDEO_DATA);
                VIDEO_COMPONENT_PARAM_T *prCompParam = VideoCommGetOutputComp(prCommState, u4OutputPortIndex);

                _VENC_DirectCouple_SetBistreamWriting(rBufferHeader.pu1Buffer);

                if (KAL_TRUE == fgReachTimeLimit)
                {
                    rBufferHeader.eFlags |= VIDEO_BUFFERFLAG_EXCEED_TIME_LIMIT;
                    _VENC_Callback2IL(VIDEO_EVENT_REACH_TIME_LIMIT);

                    // the bitstream has to be set available again
                    _VENC_DirectCouple_SetBistreamAvailable(rBufferHeader.pu1Buffer);
                }
#if defined(__VE_TIME_LAPSE_VIDEO_RECORDER__)
                else if (rBufferHeader.eFlags & VIDEO_BUFFERFLAG_INVALID_FRAME)
                {
                    _VENC_DirectCouple_SetBistreamAvailable(rBufferHeader.pu1Buffer);
                }
#endif
                else
                {
                    kal_mem_cpy((void*)&rOutBufferHeader, (void*)&rBufferHeader, sizeof(rOutBufferHeader));
                    rOutBufferHeader.u4InputPort = prCompParam->u4PortIndex;
                    rOutBufferHeader.u4OutputPort = u4OutputPortIndex;

                    _VideoEncoderSendToBackEnd(&rOutBufferHeader, KAL_TRUE);
                }
            }
            else
#endif  //__VE_MJPEG_ENC_BYPASS__
            {
                if (KAL_TRUE == fgReachTimeLimit)
                {
                    _prMgr->fgRdy2FlushCodec = KAL_TRUE;
                    rBufferHeader.eFlags |= VIDEO_BUFFERFLAG_EXCEED_TIME_LIMIT;
                    _VENC_Callback2IL(VIDEO_EVENT_REACH_TIME_LIMIT);
                }
                else if (rBufferHeader.eFlags & VIDEO_BUFFERFLAG_INVALID_FRAME)
                {
                    // Do Nothing
                }
                else
                {
                    _VideoEncoderEnqueueTimeStamp(&rBufferHeader.u8TimeStamp);
                }
                _VideoEncoderEnqueueYuvInfo(&rBufferHeader);
            }
            break;

        case ACTION_RETURN_YUV:
            fgSendInputBufferResult = _VideoEncoderSendToFrontEnd();
            break;

        default:
            _ENCODER_ASSERT();
            break;
        }


        if (KAL_TRUE == _prMgr->fgClosingEncoder )
        {
            break;
        }

        // The state may be changed in _VideoEncoderSetStateHdlr().  Thus, the
        // next "if" block cannot be moved to the start of the enclosing "switch".
        if (VideoCommGetState(prCommState) == VIDEO_STATE_STOP)
        {
            break;
        }

        if ((fgSendInputBufferResult == KAL_FALSE) ||
            (fgSendOutputBufferResult == KAL_FALSE))
        {
            // Stop when input or output component's buffer is full.
            _VideoEncoderWakeupTimer(fgSendInputBufferResult, fgSendOutputBufferResult);
            _VideoEncoderResetScheduler();
            break;
        }
        if (VCS_TASKQUEUE_EXPECTED_TARGET != eTaskControl)
        {
            break;
        }
    } while(1);

    // If the YUV queue is empty and the STOP command has been sent, then enter the STOP state.
#if defined(__VE_MJPEG_ENC_BYPASS__)
    if (VIDEO_ENCODER_SCENARIO_BYPASS == _prMgr->eEncoderScenario)
    {
        if (VIDEO_ENCODER_INT_STATE_STOPPING == _prMgr->eIntState)
        {
            if (KAL_TRUE == _VENC_DirectCouple_IsAnyBistreamStillEncoding())
            {
                _VideoEncoderSetStateHdlr(VIDEO_STATE_STOP);
            }
            else
            {
                _VideoEncoderWakeUp(MSG_WAKEUP, 0);
            }
        }
    }
    else
#endif //__VE_MJPEG_ENC_BYPASS__
    {
        if ((_prMgr->eIntState == VIDEO_ENCODER_INT_STATE_STOPPING)
         && (_prMgr->fgSourceNotifyStop == KAL_TRUE))
        {
            if ((_VideoEncoderIsYuvQueueEmpty() == KAL_TRUE) &&
                (VideoCommQueryInputBuff(&_prMgr->rCommState) == 0))
            {
                // FIXME: What about the remaining data in the bit-stream buffer?
                if (_prMgr->fgGenerateHeader == KAL_TRUE)
                {
                    kal_bool fgResultOfSendingToBackEnd;
                    _VideoEncoderGetBitstream2Send(&fgResultOfSendingToBackEnd);
                    if (fgResultOfSendingToBackEnd == KAL_FALSE)
                    {
                        // ASSERT(0);  // Print some information here.
                    }
                }
                _VideoEncoderLogStatusInfo();
                _VideoEncoderSetStateHdlr(VIDEO_STATE_STOP);
            }
        }
    }

    if (_prMgr->fgClosingEncoder == KAL_TRUE)
    {
        if (VideoCommCheckProcessing(&_prMgr->rCommState) == KAL_FALSE)
        {
            _VideoEncoderVTProfile(KAL_TRUE);
            _prMgr->fgCompClosed = KAL_TRUE;
            //VideoCommChangeState(&_prMgr->rCommState, VIDEO_STATE_CLOSE);
        }
    }
}

static void _VENCProfileSensorRate(void)
{
#if defined(__VE_VENC_PROFILING_SENSOR__)
    VIDEO_ENCODER_MGR_T * pMgr = &rVideoEncoderMgr;

    // Log the status of input frame rate
    if (pMgr->u4PreviousRcvTime > 0)
    {
        pMgr->u4TotalRcvTimeInMS += video_get_duration_ms(pMgr->u4PreviousRcvTime);

        if (pMgr->u4TotalRcvTimeInMS >= 1000)
        {
            VIDEO_TRACE4_G10( VENC_EMPTY_INTERNAL,
                                        pMgr->u4TotalRcvFrameNum*1000/pMgr->u4TotalRcvTimeInMS,
                                        pMgr->u4TotalRcvTimeInMS,
                                        pMgr->u4TotalRcvFrameNum, 0);

            pMgr->u4TotalRcvTimeInMS = 0;
            pMgr->u4TotalRcvFrameNum = 0;
        }
    }

    pMgr->u4PreviousRcvTime = video_get_current_time();
    pMgr->u4TotalRcvFrameNum ++;
#endif //__VE_VENC_PROFILING_SENSOR__
}

/********************************************************
*
*   Component interfaces
*
********************************************************/


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
VIDEO_ERROR_TYPE_T VideoEncoderInit(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VIDEO_PORT_CONFIG_T rInputPort, rOutputPort;
    VIDEO_COMPONENT_INIT_T rInitConfig;

    // Common API initialization
    rInputPort.ePortType    = VIDEO_PORT_VIDEO_DATA;
    rInputPort.fgSupplier   = KAL_TRUE;
    rInputPort.u4BuffSize   = 0;

    rOutputPort.ePortType   = VIDEO_PORT_VIDEO_DATA;
    rOutputPort.fgSupplier  = KAL_TRUE;
    rOutputPort.u4BuffSize  = 0;

    kal_mem_set(&rInitConfig, 0, sizeof(rInitConfig));
    rInitConfig.prInputPort1        = &rInputPort;
    rInitConfig.prInputPort2        = NULL;
    rInitConfig.prOutputPort1       = &rOutputPort;
    rInitConfig.prOutputPort2       = NULL;
    rInitConfig.u4CmdQSize          = VENC_COMMAND_Q_NUM;
    rInitConfig.u4InputBuffQSize    = VIDEO_ENCODER_INPUT_BUFFER_Q_NUM;
    rInitConfig.u4OutputBuffQSize   = VENC_OUTPUT_BUFFER_Q_NUM;
    rInitConfig.prExtMemHdlr        = _prMgr->prExtMemHdlr;

	rInitConfig.eMutex = eMutex = VideoGetMutex(MUTEX_USER_ENCODER_V2COMMON);

    // Setup connection and allocate buffers.
    eError = VideoCommInit(&_prMgr->rCommState, &rInitConfig, "ENCODER");
    if (eError != VIDEO_ERROR_NONE)
    {
        return eError;
    }

    // Encoder driver initilization
    kal_mem_set((void*)&_prMgr->rWorkingMem, 0, sizeof(_prMgr->rWorkingMem));
    _prMgr->eCodecState = VENC_CODEC_STATE_CLOSE;
    _VideoEncoderInitEncoderManager();
    _VENC_InitResource();

    // Only reset at the first beginning
    _VideoEncoderDeInitCodecMemory();

    VIDEO_TRACE1_G10( VENC_COMMON_INIT, eError);

    return eError;
}


/******************************************************************************
* Context: This function runs in the context of the caller task rather than the
*          context of the encoder component.
*
* Side effect:
******************************************************************************/
VIDEO_ERROR_TYPE_T VideoEncoderSendCommand(VIDEO_COMMAND_TYPE_T rCmd, kal_uint32 u4Param)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_COMM_STATE_T* const prCommState = &_prMgr->rCommState;

    if (rCmd == VIDEO_COMMAND_STATESET)
    {
        kal_bool fgRet = KAL_FALSE;

        fgRet = VideoCommPushCommand(prCommState, rCmd, u4Param);
        if (fgRet == KAL_FALSE)
        {
            // error handling
            return VIDEO_ERROR_BUFF_FULL;
        }
        _VideoEncoderWakeUp(MSG_COMMAND, 0);
    }
    else
    {
        ASSERT(0);
    }
    return VIDEO_ERROR_NONE;
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
VIDEO_ERROR_TYPE_T VideoEncoderGetParameter(VIDEO_PARAM_TYPE_T eCmd, void *pvParam)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_COMM_STATE_T* const prCommState = &_prMgr->rCommState;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    switch (eCmd)
    {
    case VIDEO_PARAM_INPUT_BUFFER_PARAM:
        VideoCommGetInputPortParam(prCommState, pvParam);
        break;

    case VIDEO_PARAM_OUTPUT_BUFFER_PARAM:
        VideoCommGetOutputPortParam(prCommState, pvParam);
        break;

#if defined(__VE_VIDEO_VT_SUPPORT__)
    case VIDEO_PARAM_ENCODER_IS_BLOCKBASED_YUV:
        {
            kal_bool* pfgBlcokedBased = (kal_bool*)pvParam;
            *pfgBlcokedBased = VideoEncoderIsYUVBlockedBased();
        }
        break;
#endif
    case VIDEO_PARAM_ENCODER_GET_STATE:
        {
            VIDEO_STATE_TYPE_T* peState = (VIDEO_STATE_TYPE_T*)pvParam;
            *peState = VideoCommGetState(prCommState);
        }
        break;
#if defined(__VE_TIME_LAPSE_VIDEO_RECORDER__)
    case VIDEO_PARAM_ENCODER_GET_TIME_LAPSE_ENCODED_FRAME_COUNT:
        {
            kal_uint32* pu4EncodedFrameCount = (kal_uint32*)pvParam;
            if (_prMgr->u4TLEncodedFrameDuration > 0)
            {
                *pu4EncodedFrameCount = _prMgr->u8TLEncodedFrameTime / _prMgr->u4TLEncodedFrameDuration;
            }
            else
            {
                *pu4EncodedFrameCount = 0;
            }
        }
        break;
#endif
    default:
        ASSERT(0);
        break;
    }

    VIDEO_TRACE2_G10( VENC_GET_PARAM, eCmd, eError);
    return eError;
}

static void _VENC_CheckResolution(kal_uint32 u4Width, kal_uint32 u4Height)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    if (!((CODEC_MJPEG == _prMgr->eCodec)||(CODEC_MJPG_BYPASS == _prMgr->eCodec)))
    {
        if ((u4Width & 0xF) != 0 || (u4Height & 0xF) != 0)
        {
            ASSERT(0);
        }
    }
}

/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
VIDEO_ERROR_TYPE_T VideoEncoderSetParameter(VIDEO_PARAM_TYPE_T eCmd, void *pvParam)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_COMM_STATE_T* const prCommState = &_prMgr->rCommState;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VIDEO_ENCODER_CODEC_ERROR_T eSetParamResult = VIDEO_ENCODER_CODEC_ERROR_NONE;
    kal_uint32 *pu4Param;

    pu4Param = (kal_uint32*)pvParam;
    VIDEO_TRACE4_G10( VENC_SET_PARAM, eCmd, (kal_uint32)pu4Param, *pu4Param, eError);

    if (VideoCommGetState(prCommState) == VIDEO_STATE_RUN)
    {
        switch(eCmd)
        {
#if defined(__VE_VIDEO_VT_SUPPORT__)
        case VIDEO_PARAM_ENCODER_STOP_INSTANTLY:
            _prMgr->fgStopInstantly    =   *(kal_bool*)(pvParam);
            eSetParamResult = VIDEO_ENCODER_CODEC_ERROR_NONE;
            break;

        case VIDEO_PARAM_ENCODER_ENCODE_I:
            _VideoEncoderSetParam2AdaptDirect(VENC_PARAM_FORCE_ENCODE_I, pvParam);
            break;
#endif
        default:
            ASSERT(0);
            break;
        }
    }
    else
    {
        switch (eCmd)
        {
        case VIDEO_PARAM_INPUT_BUFFER_PARAM:
            VideoCommSetInputPortParam(prCommState, pvParam);
            break;

        case VIDEO_PARAM_OUTPUT_BUFFER_PARAM:
            VideoCommSetOutputPortParam(prCommState, pvParam);
            break;

        case VIDEO_PARAM_ENCODER_LEFTOVER_OF_FIRST_THRESHOLD:
            _prMgr->rBitBufferMgr.u4LeftOverOf1stCluster = *(kal_uint32*)pvParam;
            break;

        case VIDEO_PARAM_ENCODER_RESOLUTION:
            {
                VENC_RESOLUTION_T* prTmp = (VENC_RESOLUTION_T*)pvParam;

                _prMgr->u4SourceWidth = prTmp->u4EncodeWidth;
                _prMgr->u4SourceHeight = prTmp->u4EncodeHeight;

                if (((kal_uint64)_prMgr->u4SourceWidth * _prMgr->u4SourceHeight)
                    > ((kal_uint64)_prMgr->rCustomSettings.u4MaxWidth * _prMgr->rCustomSettings.u4MaxHeight))
                {
                    return VIDEO_ERROR_ENCODER_RESOLUTION_ERROR;
                }
                else
                {
                    _VENC_CheckResolution(_prMgr->u4SourceWidth, _prMgr->u4SourceHeight);
                    VideoEncoderSetParam2Adapt(VENC_PARAM_WIDTH, &_prMgr->u4SourceWidth);
                    VideoEncoderSetParam2Adapt(VENC_PARAM_HEIGHT, &_prMgr->u4SourceHeight);
                }
            }
            break;

        case VIDEO_PARAM_ENCODER_QUALITY:
             VideoEncoderSetParam2Adapt(VENC_PARAM_QUALITY, pvParam);
            break;

        case VIDEO_PARAM_ENCODER_FRAME_RATE:
            VideoEncoderSetParam2Adapt(VENC_PARAM_FRAME_RATE, pvParam);
            break;

#if defined(MT6268)
/*
        case VIDEO_PARAM_ENCODER_CHANGE_PRIORITY:
            stack_change_priority_by_module_ID(MOD_VCODEC_V2, *(kal_uint32*)pvParam);
            VIDEO_START_LOGGING("VEP");
            break;

        case VIDEO_PARAM_ENCODER_RESTORE_PRIORITY:
            stack_change_priority_by_module_ID(MOD_VCODEC_V2, TASK_PRIORITY_VCODEC_V2);
            VIDEO_STOP_LOGGING("VEP");
            break;
*/
#endif
        case VIDEO_PARAM_ENCODER_LIMIT_FRM_BUFF:
            _prMgr->fgLimitFrmBuff = *(kal_bool*)(pvParam);
            break;

        case VIDEO_PARAM_ENCODER_SET_TIME_LIMIT:
            _prMgr->u8TimeLimit = *(kal_uint64*)(pvParam);
            break;

#if defined(__VE_VIDEO_VT_SUPPORT__)
        case VIDEO_PARAM_ENCODER_VT_RESTART:
            VideoEncoderSetParam2Adapt(VENC_PARAM_VT_RESTART, pvParam);
            break;
        case VIDEO_PARAM_ENCODER_ENCODE_I:
            _VideoEncoderSetParam2AdaptDirect(VENC_PARAM_FORCE_ENCODE_I, pvParam);
            break;
        case VIDEO_PARAM_ENCODER_BITRATE:
            VideoEncoderSetParam2Adapt(VENC_PARAM_BITRATE, pvParam);
            break;
        case VIDEO_PARAM_ENCODER_MAX_PKG_SIZE:
            VideoEncoderSetParam2Adapt(VENC_PARAM_MAX_PKG_SIZE, pvParam);
            break;
        case VIDEO_PARAM_ENCODER_GEN_HEADER_FRM_RATE:
            VideoEncoderSetParam2Adapt(VENC_PARAM_GEN_HEADER_FRM_RATE, pvParam);
            break;
        case VIDEO_PARAM_ENCODER_SET_UPLINK_CALLBACK:
            _prMgr->rAdaptSettings.rCallbacks.pfnGetLinkInfo = *(PFN_VCALL_GET_UPLINKINFO_T*)(pvParam);
            break;
#if defined(__VE_POSTPONE_CODEC_SETTING__)
        case VIDEO_PARAM_ENCODER_SETUP_CODEC:
            {
                VIDEO_ENCODER_TYPE_T eCodecType = *(VIDEO_ENCODER_TYPE_T*)(pvParam);

                _prMgr->fgSetupCodec = KAL_TRUE;

                if (KAL_FALSE == VideoEncoderSetCodecNScenario(eCodecType, _prMgr))
                {
                    ASSERT(0);
                }
            }
            break;
#endif
#endif
#if !defined(__VE_SLIM_PROJECT__)
        case VIDEO_PARAM_ENCODER_SYNC_INTERVAL:
            VideoEncoderSetParam2Adapt(VENC_PARAM_SYNC_INTERVAL, pvParam);
            break;
        case VIDEO_PARAM_ENCODER_ROTATE:
            {
                VIDEO_CODEC_ROTATE_ANGLE_T eRotate = VIDEO_CODEC_ROTATE_0;
                switch(*(VIDEO_ENCODER_ROTATE_ANGLE_T*)pvParam)
                {
                case VENC_ROTATE_90:
                    eRotate = VIDEO_CODEC_ROTATE_90;
                    break;
                case VENC_ROTATE_180:
                    eRotate = VIDEO_CODEC_ROTATE_180;
                    break;
                case VENC_ROTATE_270:
                    eRotate = VIDEO_CODEC_ROTATE_270;
                    break;
                case VENC_ROTATE_0:
                    eRotate = VIDEO_CODEC_ROTATE_0;
                default:
                    break;
                }
                VideoEncoderSetParam2Adapt(VENC_PARAM_ROTATE, (void*)(&eRotate));
            }
            break;
#endif

#if defined(__VE_TIME_LAPSE_VIDEO_RECORDER__)
        case VIDEO_PARAM_ENCODER_SET_TIME_LAPSE_CAPTURE_FRAME_DURATION:
            {
                _prMgr->u4TLCaptureFrameDuration = (*(kal_uint32*)(pvParam));
            }
            break;
        case VIDEO_PARAM_ENCODER_SET_TIME_LAPSE_FRAME_RATE:
            {
                kal_uint32 u4FrameRate = *(kal_uint32*)(pvParam);
                if (u4FrameRate != 0)
                {
                    _prMgr->u4TLEncodedFrameDuration = ONE_SEC_IN_MICROSEC / (u4FrameRate / 10);
                }
            }
            break;
#endif
        default:
            ASSERT(0);
            break;
        }
    }

    if (eSetParamResult != VIDEO_ENCODER_CODEC_ERROR_NONE)
    {
        eError = VIDEO_ERROR_ENCODER_ERROR;
    }

    return eError;
}


/******************************************************************************
* This function is not used for now.
*
* Context:
*
* Side effect: none
******************************************************************************/
VIDEO_ERROR_TYPE_T VideoEncoderUseBuffer(kal_uint8* pBuff, kal_uint32 u4Size)
{
    return VIDEO_ERROR_ENCODER_ERROR;
}


/******************************************************************************
* This function is called by the camera HISR.  It inserts a buffer header into
* the input buffer queue.  Send an message to the encoder component if the
* operation is allowed.
*
* Context: This function runs in the context of camera's HISR (MOD_VISUAL_HISR).
*
* Side effect: the input buffer queue, and the fgProcessing flag in common state.
******************************************************************************/
VIDEO_ERROR_TYPE_T VideoEncoderEmptyThisBuffer(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    VIDEO_ENCODER_MGR_T * _prMgr = &rVideoEncoderMgr;
    VIDEO_COMM_STATE_T* const prCommState = &_prMgr->rCommState;
    kal_uint32 u4InputPort = VideoCommGetInputPortIndex(prCommState, VIDEO_PORT_VIDEO_DATA);
    VIDEO_COMPONENT_PARAM_T *prCompParam = VideoCommGetInputComp(prCommState, u4InputPort);
    kal_uint32 u4TunnelOutputPort = prCompParam->u4PortIndex;


    if (VIDEO_BUFFERFLAG_EOF & prBuffHeader->eFlags)
    {
        //kal_prompt_trace(MOD_VIDEO, "[DBG] Get Source EOF");
        _prMgr->fgSourceNotifyStop = KAL_TRUE;
        _VideoEncoderWakeUp(MSG_EMPTYBUFFER, 0);
        return VIDEO_ERROR_NONE;
    }

#if defined(__VE_MJPEG_ENC_BYPASS__)
    if (VIDEO_ENCODER_SCENARIO_BYPASS == _prMgr->eEncoderScenario)
    {
        if (_prMgr->fgClosingEncoder == KAL_TRUE)
        {
            goto BUFFER_FULL;
        }
    }
    else
#endif
    {
        if ((_prMgr->fgClosingEncoder == KAL_TRUE) ||
            (KAL_TRUE == _prMgr->fgSourceNotifyStop) ||
            (_prMgr->eIntState == VIDEO_ENCODER_INT_STATE_STOPPED))
        {
            goto BUFFER_FULL;
        }
    }

    if ((prBuffHeader->u4InputPort == u4InputPort) &&
        (prBuffHeader->u4OutputPort == u4TunnelOutputPort))
    {
        kal_bool fgRet = KAL_FALSE;
        kal_uint32 u4WriteIndex = _prMgr->u4SceneChangeWriteIndex;

        _prMgr->afgSceneChange[u4WriteIndex] = _prMgr->fgPauseResume;
        prBuffHeader->pPrivateData = (void*)(&_prMgr->afgSceneChange[u4WriteIndex]);

        fgRet = VideoCommPushInputBuff(prCommState, prBuffHeader);
        if (fgRet == KAL_FALSE)
        {
            _VideoEncoderWakeUp(MSG_EMPTYBUFFER, 0);
            goto BUFFER_FULL;
        }

        _prMgr->u4SceneChangeWriteIndex = (u4WriteIndex + 1) % (VIDEO_ENCODER_INPUT_BUFFER_Q_NUM);
        _prMgr->fgPauseResume = KAL_FALSE;

        VIDEO_TRACE2_G8( VENC_GET_INPUT,
            (kal_uint32)(prBuffHeader->pu1Buffer),
            (kal_uint32)prBuffHeader->u8TimeStamp);

        _VENCProfileSensorRate();

        VCodecCtrlAddItem(VCS_ENCODER, prBuffHeader);

        _prMgr->u4InputQueueNumber++;
        _VideoEncoderWakeUp(MSG_EMPTYBUFFER, 0);
    }
    else
    {
          ASSERT(0);
    }

    return VIDEO_ERROR_NONE;

BUFFER_FULL:
    VIDEO_TRACE1_G10(VENC_RETURN_FULL, (kal_uint32)prBuffHeader->pu1Buffer);
    return VIDEO_ERROR_BUFF_FULL;
}


/******************************************************************************
* This function is called by the file writer to notify the encoder component
* of a FillBuffer request.  It inserts a buffer header into the output buffer
* queue.  Send a message to the encoder component if the operation is allowed.
*
* Context: This function runs in the context of the file writer.
*
* Leroy: Who will process the message MSG_EMPTYBUFFER and MSG_FILLBUFFER?
*
* Side effect: the output buffer queue, and the fgProcessing flag in common state.
******************************************************************************/
VIDEO_ERROR_TYPE_T VideoEncoderFillThisBuffer(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_COMM_STATE_T* const prCommState = &_prMgr->rCommState;
    kal_uint32 u4OutputPortIndex = VideoCommGetOutputPortIndex(prCommState, VIDEO_PORT_VIDEO_DATA);
    VIDEO_COMPONENT_PARAM_T *prCompParam = VideoCommGetOutputComp(prCommState, u4OutputPortIndex);
    kal_uint32 u4TunneInputPort = prCompParam->u4PortIndex;
    VIDEO_ERROR_TYPE_T eRet = VIDEO_ERROR_NONE;

    kal_take_mutex(_prMgr->rFillMutex);

    if (_prMgr->fgClosingEncoder == KAL_TRUE)
    {
        eRet  = VIDEO_ERROR_BUFF_FULL;
        goto EXIT_FUNC;
    }

    if ((prBuffHeader->u4InputPort == u4TunneInputPort) &&
        (prBuffHeader->u4OutputPort == u4OutputPortIndex))
    {
        kal_bool fgRet = KAL_FALSE;


        fgRet = VideoCommPushOutputBuff(prCommState, prBuffHeader);
        if (fgRet == KAL_FALSE)
        {
            // Error handling
            VIDEO_TRACE0_G10( VENC_FILL);

            eRet = VIDEO_ERROR_BUFF_FULL;
            goto EXIT_FUNC;
        }

#if defined(__VE_VIDEO_VT_SUPPORT__)
        if (_prMgr->eEncoderScenario == VIDEO_ENCODER_SCENARIO_VT)
        {
            _VideoEncoderReturnUsedChassis((VIDEO_ENCODER_CHASSIS_T*)prBuffHeader->pPrivateData);
        }
#endif  // __VE_VIDEO_VT_SUPPORT__

        _prMgr->u4OutputQueueNumber++;

        _VideoEncoderWakeUp(MSG_FILLBUFFER, 0);

        // FIXME (Leroy):
        // if (rVideoEncoderMgr.fgRetryDeInit == TRUE)
        //     called VideoEncoderDeInit();
    }
    else
    {
        ASSERT(0);
    }

EXIT_FUNC:
    kal_give_mutex(_prMgr->rFillMutex);
    return eRet;
}


/******************************************************************************
* Register the callback function into the encoder component.
*
* Context: This function runs in the context of the caller task rather than the
*          context of the encoder component.
*
* Side effect:
******************************************************************************/
VIDEO_ERROR_TYPE_T VideoEncoderSetCallbacks(VIDEO_CALLBACK_TYPE_T *prCallback)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    eError = VideoCommSetCallbacks(&_prMgr->rCommState, prCallback);

    return eError;
}


/******************************************************************************
*
* Context: This function runs in the context of the caller task rather than the
*          context of the encoder component.
*
* Side effect:
******************************************************************************/
VIDEO_ERROR_TYPE_T VideoEncoderDeInit(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    // CODEC de-initialization
    _VideoEncDeinitCodec(_prMgr);
    _VideoEncCloseCodec(_prMgr);

    // Decoder driver de-initilization
    _VideoEncoderDeInitEncoderManager();
    _VENC_DeinitResource();

	VideoFreeMutex(MUTEX_USER_ENCODER_V2COMMON, eMutex);

    // Common API de-initialization
    eError = VideoCommDeInit(&_prMgr->rCommState);

    VIDEO_TRACE1_G10( VENC_COMMON_DEINIT, eError);
    return eError;
}


/******************************************************************************
* This is a list of functions implemented for the encoder component.
******************************************************************************/
static const VIDEO_COMPONENT_TYPE_T _rVideoEncoderComp =
{
    VideoEncoderInit,
    VideoEncoderSendCommand,
    VideoEncoderGetParameter,
    VideoEncoderSetParameter,
    NULL,
    VideoEncoderEmptyThisBuffer,
    VideoEncoderFillThisBuffer,
    VideoEncoderSetCallbacks,
    VideoEncoderDeInit
};


/********************************************************
*
*   APIs provided
*
********************************************************/


/******************************************************************************
*
* Context: This function runs in the context of the caller task rather than the
*          context of the encoder component.
*
* Side effect:
******************************************************************************/
VIDEO_COMPONENT_TYPE_T* GetVideoEncoderHandle(
    VIDEO_ENCODER_TYPE_T eType,
    VIDEO_EXTMEM_HANDLER_T* prExtMemHdlr,
    VIDEO_INTMEM_HANDLER_T* prIntMemHdlr
    )
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_COMPONENT_TYPE_T *prVideoEncoderComp = NULL;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VIDEO_ENCODER_CUSTOM_SETTINGS_T* prCustomSettings = &_prMgr->rCustomSettings;

    _prMgr->fgInitFrameBuffer = KAL_FALSE;
    _prMgr->prExtMemHdlr   = prExtMemHdlr;
    _prMgr->prIntMemHdlr   = prIntMemHdlr;

#if defined(__VE_STKMGR_USER_FILTER_ENABLE__)
    drv_gfx_stkmgr_set_user_filter(SW_VIDEO_STACK_SIZE);
#endif

    prVideoEncoderComp = (VIDEO_COMPONENT_TYPE_T*)&_rVideoEncoderComp;

    if (KAL_FALSE == VideoEncoderSetCodecNScenario(eType, _prMgr))
    {
        ASSERT(0);
        return prVideoEncoderComp;
    }


    // Set the scenario in the codec adaptation layer.
    if (KAL_FALSE == _VENC_BypassCodec(_prMgr))
    {
        if (_prMgr->prCodecAPI == NULL)
        {
            VIDEO_TRACE1_G10( VENC_NULL_POINTER, __LINE__);
            return prVideoEncoderComp;
        }
    }

    VideoEncoderGetSetting(prCustomSettings, eType);

#if !defined(__VE_SLIM_PROJECT__)
    _VideoEncoderCheckSetting(&_prMgr->rCustomSettings);
#endif

    // Call the init function of the Encoder component.
    if (prVideoEncoderComp != NULL)
    {
        eError = prVideoEncoderComp->pfnInit();
        if (eError != VIDEO_ERROR_NONE)
        {
            prVideoEncoderComp = NULL;
        }
    }

    VCodecCtrlRegister(VCS_ENCODER, VideoEncoderWakeUp);

    VIDEO_TRACE2_G10( VENC_GET_HDLR, eType, eError);

    return prVideoEncoderComp;
}


/******************************************************************************
* Note: This function does not perform the operation of releasing handlers.
*       Instead, it performs the de-initialization operation.
*
* Context: This function runs in the context of the caller task rather than the
*          context of the encoder component.
*
* Side effect:
******************************************************************************/
VIDEO_ERROR_TYPE_T ReleaseVideoEncoderHandle(VIDEO_COMPONENT_TYPE_T *prHandle)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    if (prHandle == NULL)
    {
        ASSERT(0);
        return VIDEO_ERROR_DEINIT_ERROR;
    }

    eError = prHandle->pfnDeInit();

    VCodecCtrlDeRegister(VCS_ENCODER);

    VIDEO_TRACE1_G10( VENC_RELEASE_HDLR, eError);

#if defined(__VE_STKMGR_USER_FILTER_ENABLE__)
    drv_gfx_stkmgr_unset_user_filter(SW_VIDEO_STACK_SIZE);
#endif

    return eError;
}


/******************************************************************************
* xxx
*
* Context: This function runs in the context of the encoder component.
*
* Side effect:
******************************************************************************/
void VideoEncoderMain(ilm_struct *prIlm)
{
    _VideoEncoderDataHdlr(prIlm);
}

void* VideoEncoderMallocCacheLineAlign(kal_uint32 u4Size, kal_bool fgCacheable)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_WORKING_MEM_T* pMgr = &_prMgr->rWorkingMem;
    kal_uint32 u4MemSize = 0;
    void *pVoid;

    //Make sure all the allocation chche line aligned
    u4MemSize = ROUND_UP_TO_POWER_OF_TWO(u4Size, CPU_CACHE_LINE_SIZE);


    if (fgCacheable == KAL_TRUE)
    {
        pVoid =  kal_adm_alloc_cacheable(pMgr->rCodecMemAdmId, u4MemSize, CPU_CACHE_LINE_SIZE);
    }
    else
    {
        pVoid =  kal_adm_alloc_nc_align(pMgr->rCodecMemAdmId, u4MemSize, CPU_CACHE_LINE_SIZE);
    }

    VIDEO_TRACE4_G10( VENC_ADAPT_MALLOC, (kal_uint32)pVoid, u4MemSize, u4Size, fgCacheable);

    return (void*)(pVoid);
}

void VideoEncoderFreeCacheLineAlign(void *pVoid)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
    VIDEO_ENCODER_WORKING_MEM_T* pMgr = &_prMgr->rWorkingMem;

    VIDEO_TRACE1_G10( VENC_ADAPT_FREE, (kal_uint32)pVoid);

    if (NULL != pVoid)
    {
        kal_adm_free(pMgr->rCodecMemAdmId, (kal_uint8*)pVoid);
    }
}

void VideoEncoderFreeAligned(void* pVoid)
{
    VideoEncoderFreeCacheLineAlign(pVoid);
}
/******************************************************************************
* xxx
*
* Context: This function runs in the context of the caller task rather than the
*          context of the encoder component.
*
* Side effect:
******************************************************************************/
void* VideoEncoderMallocAligned(kal_uint32 u4Size)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;

    return VideoEncoderMallocCacheLineAlign(u4Size, _prMgr->rWorkingMem.fgBSinCache);
}


/******************************************************************************
* xxx
*
* Context: This function runs in the context of the caller task rather than the
*          context of the encoder component.
*
* Side effect:
******************************************************************************/
void *VideoEncoderMemSet(void *pVoid, kal_int32 u4Value, kal_uint32 u4Size)
{
    void *pDest = NULL;

    if (pVoid != NULL)
    {
        pDest = kal_mem_set(pVoid, u4Value, u4Size);
    }
    return pDest;
}


/******************************************************************************
* xxx
*
* Context:
*
* Side effect:
******************************************************************************/
void VideoEncoderMemCopy(void *pDest, void *pSrc, kal_uint32 u4Size)
{
    kal_mem_cpy(pDest, pSrc, u4Size);
}


/******************************************************************************
* xxx
*
* Context: This function runs in the context of the caller task rather than the
*          context of the encoder component.
*
* Side effect:
******************************************************************************/
void VideoEncoderReleaseYUV(kal_uint8 *pu1Buff)
{
    VIDEO_BUFFERHEADER_TYPE_T rBuffHeader;
    VIDEO_BUFFERHEADER_TYPE_T rDummyBufferHeader;

    // Verify the correctness of the YUV buffer address.  It is a defined
    // protocol that the Encoder will release YUV buffer in sequence.
    _VideoEncoderClearInUseFlagAtFirstUsedYuv(&rBuffHeader, pu1Buff);

    VIDEO_TRACE4_G9( VENC_YUV_RELEASE,
        (kal_uint32)(rBuffHeader.pu1Buffer),
        (kal_uint32)(rBuffHeader.u8TimeStamp),
        (kal_uint32)(rBuffHeader.u4BuffSize),
        (0));

    _VideoEncoderVTAddFrameNBit(1, 0);
    _VideoEncoderVTProfile(KAL_FALSE);

    kal_mem_set((void*)(&rDummyBufferHeader), 0, sizeof(rDummyBufferHeader));
    rDummyBufferHeader.pu1Buffer = pu1Buff;
    rDummyBufferHeader.u8TimeStamp = 0;
    _VideoEncoderCleanItem(&rDummyBufferHeader, AT_ENCODE_DONE);

    // Send an external message to the Encoder Component to avoid possible lock-up.
    _VideoEncoderWakeUp(MSG_WAKEUP, 0);
}


/******************************************************************************
* xxx
*
* Context:
*
* Side effect:
******************************************************************************/
void VideoEncoderWakeUp(void* pvParam)
{
    _VideoEncoderWakeUp(MSG_WAKEUP, 0);
}

kal_bool VideoEncoderGenStreamHeader(VIDEO_ENCODER_GEN_HEADER_PARAM_T* prSetting)
{
#if defined(__VE_VIDEO_VT_SUPPORT__)
    kal_uint32 u4HeaderSize = 0;

    #if defined(__VE_MPEG4_ENC_SW_SUPPORT__)
    switch(prSetting->eType)
    {
        case VIDEO_ENCODER_MPEG4_VT:
            if (KAL_TRUE == VideoAdapterGenStreamHeader(VADP_CODEC_MPEG4, prSetting->pu1Buffer, prSetting->u4BufferSize, prSetting->u4TimeIncrResolution, &u4HeaderSize))
            {
                *prSetting->pu4EncodedSize = u4HeaderSize;
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
        //break;
        default:
            //EXT_ASSERT(0, prSetting->eType, prSetting->u4BufferSize, prSetting->u4TimeIncrResolution);
            return KAL_FALSE;
        //break;
    };
    #elif defined(__VE_MPEG4_ENC_HW_SUPPORT__)
    switch(prSetting->eType)
    {
        case VIDEO_ENCODER_MPEG4_VT:
            if (KAL_TRUE == MPEG4HWGenStreamHeader(prSetting->pu1Buffer, prSetting->u4BufferSize, prSetting->u4TimeIncrResolution, &u4HeaderSize))
            {
                *prSetting->pu4EncodedSize = u4HeaderSize;
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
        break;
        default:
            return KAL_FALSE;
    };
    #else
    return KAL_FALSE;
    #endif
#else
    return KAL_FALSE;
#endif //__VE_VIDEO_VT_SUPPORT__
}
void VideoEncoderPaused(kal_uint8* pu1ReadPtr)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;

    _prMgr->fgTriggerEncoder = KAL_TRUE;
}

void VideoEncoderGenBistream(void)
{
    _VideoEncoderWakeUp(MSG_WAKEUP, 0);
}

kal_uint32 VideoEncoderGetIntMem(kal_uint32 u4ReqSize)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;

    return VideoGetIntBuffer(_prMgr->prIntMemHdlr, u4ReqSize);
}

void VideoEncoderFreeIntMem(kal_uint8* pu1FreeAddr, kal_uint32 u4FreeSize)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;

    VideoFreeIntBuffer(_prMgr->prIntMemHdlr, pu1FreeAddr, u4FreeSize);
}

void VideoEncoderResetIntMem(void)
{
    VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;

    VideoResetIntBuffer(_prMgr->prIntMemHdlr);
}

#ifdef __VE_DCM_WITH_COMPRESSION__
#pragma arm section code, rodata
#endif

void VideoEncoderMainNonDCM(ilm_struct *prIlm)
{
    // Process Decoder normal jobs
    VideoEncoderMain(prIlm);

    // Check if we should close Encoder
    // Split 'normal jobs' and 'close' to avoid DCM page fault issues
    {
        VIDEO_ENCODER_MGR_T* const _prMgr =  &rVideoEncoderMgr;
        if (KAL_TRUE == _prMgr->fgCompClosed)
        {
            VideoCommChangeState(&_prMgr->rCommState, VIDEO_STATE_CLOSE);
        }
    }
}

#endif /*(__VE_SUPPORT_ENCODER__)*/
#endif /* __VE_VIDEO_ARCHI_V2__*/
