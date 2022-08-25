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
 *   video_subtitle_decoder.c
 *
 * Project:
 * --------
 *  MTK
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
 *
 ****************************************************************************/

#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__


#include "drv_comm.h"                       // for drv_trace1(), drv_trace8()
#include "kal_release.h"      /* Basic data type */
#include "kal_trace.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "video_types_v2.h"
#include "video_comm_component_v2.h"
#include "video_comm_v2.h"
#include "vcodec_v2_trc.h"
#include "video_buffer_management_v2.h"
#include "video_dbg_v2.h"
#include "video_codec_schedule_control.h"
#include "video_codec_type_v2.h"
#include "video_codec_mem_v2.h"
#include "video_codec_utility_v2.h"
#include "video_subtitle_decoder.h"
//#include "stack_ltlcom.h"
//#include "stack_config.h"
//#include "hisr_config.h"
//#include "stack_common.h"
//#include "stack_msgs.h"
//#include "app_ltlcom.h"       /* Task message communiction */
//#include "drv_gfx_stack_switch_manager.h"
//#include "cache_sw.h"
//#include "video_codec_custom_setting_v2.h"
//#include "video_codec_if_v2.h"
//#include "video_codec_buffer_mgr_v2.h"
//#include "video_decoder_il_if_v2.h"
//#include "video_decoder_isolation_v2.h"


#pragma arm section code="SECONDARY_ROCODE"


#ifdef __VE_SUBTITLE_SUPPORT__


/*****************************************************************************
* Macro(s)
*****************************************************************************/
#ifndef VSD_DEVELOPMENT
#define VSD_DEVELOPMENT
#endif  // VSD_DEVELOPMENT


/*****************************************************************************
* Definition of macros
*****************************************************************************/
#ifndef UNUSED
#define UNUSED(x)               ((void)(x))
#endif  // UNUSED


#if defined(__VE_SLIM_PROJECT__) && !defined(VSD_DEVELOPMENT)
    #define _VSD_ASSERT(x)                      do { /* empty */ } while (0)
    #define _VSD_ASSERT_IF_EQUAL(x, y)          do { UNUSED(x);  } while (0)
    #define _VSD_ASSERT_IF_NOT_EQUAL(x, y)      do { UNUSED(x);  } while (0)
    #define _VSD_CHECK_SIZE(x, y)               do { /* empty */ } while (0)
#else
    #define _VSD_ASSERT(x)                      ASSERT(x)

    #define _VSD_ASSERT_IF_EQUAL(x, y)                                  \
        do {                                                            \
            if ((x) == (y))                                             \
            {                                                           \
                ASSERT(0);                                              \
            }                                                           \
        } while (0)

    #define _VSD_ASSERT_IF_NOT_EQUAL(x, y)                              \
        do {                                                            \
            if ((x) != (y))                                             \
            {                                                           \
                ASSERT(0);                                              \
            }                                                           \
        } while (0)

    #define _VSD_CHECK_SIZE(x, y)                                       \
        do {                                                            \
            if (sizeof(x) != (y))                                       \
            {                                                           \
                ASSERT(0);                                              \
            }                                                           \
        } while (0)
#endif  // defined(__VE_SLIM_PROJECT__) && !defined(VSD_DEVELOPMENT)


/*****************************************************************************
* Static global variable(s)
*****************************************************************************/
static VSD_MGR_T _rVsdMgr;


/*****************************************************************************
* Function prototype(s)
*****************************************************************************/
void _VSD_FRONT_END_ProcessInput(VSD_LUMP_T *prLump);


/*****************************************************************************
*
* Context:
*****************************************************************************/
static void _VideoCommClearInputAndOutputQ(VIDEO_COMM_STATE_T *prCommState)
{
    kal_uint32 u4SavedMask;
    kal_uint32 i = 0;

    u4SavedMask = SaveAndSetIRQMask();

    if (prCommState->u4EntryCount != 0)
    {
        EXT_ASSERT(0, prCommState->u4EntryCount, 0, 0);
    }

    for (; i < VIDEO_PORT_MAX_NUM; i++)
    {
        prCommState->rInputBuffQ[i].u4WriteIdx = 0;
        prCommState->rInputBuffQ[i].u4ReadIdx = 0;
        prCommState->rInputBuffQ[i].u4UsedNum= 0;

        prCommState->rOutputBuffQ[i].u4WriteIdx = 0;
        prCommState->rOutputBuffQ[i].u4ReadIdx = 0;
        prCommState->rOutputBuffQ[i].u4UsedNum= 0;
    }

    RestoreIRQMask(u4SavedMask);
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
static void _VideoCommClearOutputQ(VIDEO_COMM_STATE_T *prCommState)
{
    kal_uint32 u4SavedMask;
    kal_uint32 i = 0;

    u4SavedMask = SaveAndSetIRQMask();

    if (prCommState->u4EntryCount != 0)
    {
        EXT_ASSERT(0, prCommState->u4EntryCount, 0, 0);
    }

    for (; i < VIDEO_PORT_MAX_NUM; i++)
    {
        prCommState->rOutputBuffQ[i].u4WriteIdx = 0;
        prCommState->rOutputBuffQ[i].u4ReadIdx = 0;
        prCommState->rOutputBuffQ[i].u4UsedNum= 0;
    }

    RestoreIRQMask(u4SavedMask);
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
static VIDEO_ERROR_TYPE_T _VSD_CODEC_Open(void)
{
    VSD_CODEC_API_T* const prCodecApi = _rVsdMgr.prCodecApi;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VSD_CODEC_INIT_T rInitStruct;

    _VSD_ASSERT_IF_EQUAL(prCodecApi, NULL);
    eError = prCodecApi->pfnOpen();
    if (eError != VIDEO_ERROR_NONE)
    {
        ASSERT(0);
        return eError;
    }

    kal_mem_set((void*)&rInitStruct, 0, sizeof(rInitStruct));  // FIXME: Does init() need to have parameter???
    eError = prCodecApi->pfnInit(&rInitStruct);
    if (eError != VIDEO_ERROR_NONE)
    {
        ASSERT(0);
        return eError;
    }

    return eError;
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
static VIDEO_ERROR_TYPE_T _VSD_CODEC_SetPrperties(void)
{
    VSD_CODEC_API_T* const prCodecApi = _rVsdMgr.prCodecApi;
    PFN_VSD_SET_PARAM_T pfnSetParam;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VSD_RESOLUTION_T rResolution;


    _VSD_ASSERT_IF_EQUAL(prCodecApi, NULL);
    pfnSetParam = prCodecApi->pfnSetParam;
    _VSD_ASSERT_IF_EQUAL(pfnSetParam, NULL);

    rResolution.u4Width = _rVsdMgr.u4Width;
    rResolution.u4Height = _rVsdMgr.u4Height;
    eError = pfnSetParam(VSD_CODEC_OP_RESOLUTION, (void*)&rResolution);
    if (eError != VIDEO_ERROR_NONE)
    {
        return eError;
    }

    eError = pfnSetParam(VSD_CODEC_OP_FONT_ENCODING, (void*)&_rVsdMgr.eEncoding);
    if (eError != VIDEO_ERROR_NONE)
    {
        return eError;
    }

    eError = pfnSetParam(VSD_CODEC_OP_FONT_SIZE, (void*)&_rVsdMgr.u4FontSize);
    if (eError != VIDEO_ERROR_NONE)
    {
        return eError;
    }

    eError = pfnSetParam(VSD_CODEC_OP_FONT_STYLES, (void*)&_rVsdMgr.rFontStyles);
    if (eError != VIDEO_ERROR_NONE)
    {
        return eError;
    }

    eError = pfnSetParam(VSD_CODEC_OP_COLORS, (void*)&_rVsdMgr.rColors);
    if (eError != VIDEO_ERROR_NONE)
    {
        return eError;
    }

    eError = pfnSetParam(VSD_CODEC_OP_ALIGNMENT, (void*)&_rVsdMgr.rAlignment);
    if (eError != VIDEO_ERROR_NONE)
    {
        return eError;
    }

    eError = pfnSetParam(VSD_CODEC_OP_FONT_ENGINE_API, (void*)&_rVsdMgr.rFontEngineApi);
    if (eError != VIDEO_ERROR_NONE)
    {
        return eError;
    }

    return eError;
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
static void _VSD_DeinitMemory(void)
{
    // VSD_MGR_T* const prVsdMgr =&_rVsdMgr;
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
static void _VSD_SendMessage(kal_uint32 u4Message, VSD_MESSAGE_T eMsgType)
{
    VSD_MSG_IND_T *prMsg = NULL;
    ilm_struct *prIlm = NULL;
    module_type eActiveModuleId = stack_get_active_module_id();

    prMsg = (VSD_MSG_IND_T*)construct_local_para(sizeof(*prMsg), TD_CTRL);
    prMsg->u4Param1 = (kal_uint32)eMsgType;
    prMsg->u4Param2 = 0;

    prIlm = allocate_ilm(eActiveModuleId);
    prIlm->src_mod_id = eActiveModuleId;

    prIlm->dest_mod_id = MOD_VCODEC;
    prIlm->sap_id = MED_SAP;  // FIXME!!!

    prIlm->msg_id = (msg_type)u4Message;
    prIlm->local_para_ptr = (local_para_struct*)prMsg;
    prIlm->peer_buff_ptr = NULL;

    msg_send_ext_queue(prIlm);

    drv_trace1(TRACE_GROUP_10, VSD_SEND_MSG, (kal_uint32)eMsgType);
}


/******************************************************************************
*
* Context:
******************************************************************************/
static void _VSD_WakeUp(VSD_MESSAGE_T eMsgType)
{
    kal_bool fgSendMsg = KAL_FALSE;

    fgSendMsg = VideoCommSetProcessing(&_rVsdMgr.rCommState);
    if (fgSendMsg == KAL_TRUE)
    {
        _VSD_SendMessage(MSG_ID_VSD_DATA_IND, eMsgType);
    }
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
static kal_bool _VSD_SendBufferHeader(VSD_PORT_T ePort, VIDEO_BUFFERHEADER_TYPE_T *prBufferHeader)
{
    const VIDEO_PORT_TYPE_T ePortType = VIDEO_PORT_SUBTITLE;
    PFN_PROCESS_BUFFER_T pfnProcessBuffer = NULL;
    kal_uint32 u4PortIndex;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_bool fgSuccess = KAL_FALSE;

    switch (ePort)
    {
    case VSD_PORT_FRONT_END_OUTPUT:
        u4PortIndex = VideoCommGetInputPortIndex(&_rVsdMgr.rCommState, ePortType);
        pfnProcessBuffer = VideoCommGetInputProcessBufferFunc(&_rVsdMgr.rCommState, u4PortIndex);
        drv_trace0(TRACE_GROUP_10, VSD_PREPARE_TO_SEND_TO_FRONT_END);
        break;

    case VSD_PORT_BACK_END_OUTPUT:
        u4PortIndex = VideoCommGetOutputPortIndex(&_rVsdMgr.rCommState, ePortType);
        pfnProcessBuffer = VideoCommGetOutputProcessBufferFunc(&_rVsdMgr.rCommState, u4PortIndex);
        drv_trace0(TRACE_GROUP_10, VSD_PREPARE_TO_SEND_TO_BACK_END);
        break;

    default:
        ASSERT(0);
        break;
    }
    drv_trace2(TRACE_GROUP_10, VSD_IN_OUT_BUFFER_INFO,
        (kal_uint32)(prBufferHeader->pu1Buffer),
        (kal_uint32)(prBufferHeader->u8TimeStamp));

    // video_dbg_trace(VIDEO_DBG_OWNER_VSD, VIDEO_DBG_VSD_SEND_BUFFER, (kal_uint32)(prBufferHeader->pu1Buffer));
    // video_dbg_trace(VIDEO_DBG_OWNER_VSD, VIDEO_DBG_VSD_SEND_TIME, (kal_uint32)(prBufferHeader->u8TimeStamp));
    eError = pfnProcessBuffer(prBufferHeader);
    switch (eError)
    {
    case VIDEO_ERROR_NONE:
        fgSuccess = KAL_TRUE;
        drv_trace0(TRACE_GROUP_10, VSD_SEND_SEND_RESULT_OK);
        break;

    case VIDEO_ERROR_BUFF_FULL:
        // fgSuccess = KAL_FALSE;
        drv_trace0(TRACE_GROUP_10, VSD_SEND_SEND_RESULT_BUFFER_FULL);
        break;

    default:
        ASSERT(0);
        break;
    }

    return fgSuccess;
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
static void _VSD_SetRendererPrivateData(VIDEO_BUFFERHEADER_TYPE_T *prFrameHeader)
{
    VA2_VIDEO_FRAME_T* const prVaPrivateData = (VA2_VIDEO_FRAME_T*)(prFrameHeader->pPrivateData);

    kal_mem_set((void*)prVaPrivateData, 0, sizeof(*prVaPrivateData));

    prVaPrivateData->r_fb_addr.u4_fb_addr_plane0 = (kal_uint32)(prFrameHeader->pu1Buffer);
    // prVaPrivateData->r_fb_addr.u4_fb_addr_plane1 = 0;
    // prVaPrivateData->r_fb_addr.u4_fb_addr_plane2 = 0;

    prVaPrivateData->r_fb_size.u4_width = _rVsdMgr.u4Width;
    prVaPrivateData->r_fb_size.u4_height = _rVsdMgr.u4Height;

    // prVaPrivateData->r_clip_window.b_clip_enable = KAL_FALSE;
    // prVaPrivateData->r_clip_window.u4_clip_top = 0;
    // prVaPrivateData->r_clip_window.u4_clip_left = 0;
    // prVaPrivateData->r_clip_window.u4_clip_bottom = 0;
    // prVaPrivateData->r_clip_window.u4_clip_right = 0;

    prVaPrivateData->eFrameColorFmt = VIDEO_RENDERER_COLOR_ARGB8888;

    // Clear "prVaPrivateData->r_dithering_info" to zero.

    // prVaPrivateData->pv_extra = NULL;

    drv_trace0(TRACE_GROUP_10, VSD_SET_RENDERER_PRIVATE_DATA);
}


/*****************************************************************************
*
* Context: VCODEC
*****************************************************************************/
static void _VSD_LUMP_ClearLump(void)
{
    kal_uint8 *pu1FrameBufferStart = _rVsdMgr.rLumpMgr.pu1FrameBufferStart;

    drv_trace0(TRACE_GROUP_10, VSD_CLEAR_LUMP_MGR);
    kal_mem_set((void*)&_rVsdMgr.rLumpMgr, 0, sizeof(_rVsdMgr.rLumpMgr));
    _rVsdMgr.rLumpMgr.pu1FrameBufferStart = pu1FrameBufferStart;
}


/*****************************************************************************
* Width and height must be set before this function is called.
*
* FIXME: VSD_LUMP_TOTAL_MEM_SIZE, VIDEO_SUBTITLE_MAX_FRAMES
*
* Context:
*****************************************************************************/
static VIDEO_ERROR_TYPE_T _VSD_LUMP_InitMemory(void)
{
    VSD_LUMP_T* const prLump = _rVsdMgr.rLumpMgr.arLump;
    const kal_uint32 u4FrameSize = _rVsdMgr.u4Width * _rVsdMgr.u4Height * VSD_LUMP_BYTES_PER_PIXEL;
    kal_uint32 u4Index, u4AlignedFrameSize;
    kal_uint8 *pu1FrameBufferStart = _rVsdMgr.rLumpMgr.pu1FrameBufferStart;

    drv_trace0(TRACE_GROUP_10, VSD_LUMP_INIT_MEMORY);

    u4AlignedFrameSize = ROUND_UP_TO_POWER_OF_TWO(u4FrameSize, CPU_CACHE_LINE_SIZE_MINE);

    for (u4Index = 0; u4Index < VIDEO_SUBTITLE_MAX_FRAMES; u4Index++)
    {
        kal_uint8 *pu1Buffer;
        pu1Buffer = pu1FrameBufferStart + (u4AlignedFrameSize * u4Index);
        pu1Buffer = (kal_uint8*)VideoCommExtBufferCacheableSwitch((kal_uint32)pu1Buffer, u4AlignedFrameSize, VIDEO_NON_CACHEABLE);
        prLump[u4Index].pu1Buffer = pu1Buffer;
        kal_mem_set((void*)&(prLump[u4Index].rFrameHeader), 0, sizeof(prLump[u4Index].rFrameHeader));
    }

    if (u4Index == 0) { ASSERT(0); }
    _rVsdMgr.rLumpMgr.u4TotalNum = u4Index;
    _rVsdMgr.u4FrameSize = u4FrameSize;

    return VIDEO_ERROR_NONE;
}


/*****************************************************************************
* The term "to lease" means a lump is "to be used" by the front-end module.
* The front-end module is the Source component.
*
* Context: VCODEC
*****************************************************************************/
static kal_bool _VSD_LUMP_GetLumpToLease(VSD_LUMP_T **pprLump)
{
    VSD_LUMP_MGR_T* const prLumpMgr = &_rVsdMgr.rLumpMgr;
    VSD_LUMP_T* const prLumpStart = prLumpMgr->arLump;
    kal_uint32 u4TotalNum = prLumpMgr->u4TotalNum;
    kal_uint32 u4GetIdx = prLumpMgr->u4GetIdx;

    // *pprLump = NULL;
    if (u4TotalNum > prLumpMgr->u4UsedNum)
    {
        if (prLumpStart[u4GetIdx].eFlag == VSD_LUMP_STATUS_FREE)
        {
            *pprLump = prLumpStart + u4GetIdx;
            drv_trace2(TRACE_GROUP_10, VSD_LUMP_GET_LUMP, u4GetIdx, prLumpMgr->u4RetIdx);
            u4GetIdx = (u4GetIdx + 1) % u4TotalNum;
            prLumpMgr->u4GetIdx = u4GetIdx;
            prLumpMgr->u4UsedNum++;
            return KAL_TRUE;
        }
    }

    return KAL_FALSE;
}


/*****************************************************************************
* The term "to bail out" means a lump is "to be displayed" by Render.
*
* Context: VCODEC
*****************************************************************************/
static kal_bool _VSD_LUMP_GetLumpToBailOut(VSD_LUMP_T **pprLump)
{
    VSD_LUMP_MGR_T* const prLumpMgr = &_rVsdMgr.rLumpMgr;
    VSD_LUMP_T* const prLumpStart = prLumpMgr->arLump;
    kal_uint32 u4TotalNum = prLumpMgr->u4TotalNum;
    kal_uint32 u4UsedNum = prLumpMgr->u4UsedNum;
    kal_uint32 u4RetIdx = prLumpMgr->u4RetIdx;
    kal_uint32 u4LoopCount;

    // *pprLump = NULL;
    for (u4LoopCount = 0; u4LoopCount < u4UsedNum; u4LoopCount++)
    {
        if (prLumpStart[u4RetIdx].eFlag == VSD_LUMP_STATUS_LEASED)
        {
            *pprLump = prLumpStart + u4RetIdx;
            return KAL_TRUE;
        }
        u4RetIdx = (u4RetIdx + 1) % u4TotalNum;
    }

    return KAL_FALSE;
}


/*****************************************************************************
* The term "to free" means no module is using it and it can be reused.
*
* Context: VCODEC
*****************************************************************************/
static kal_bool _VSD_LUMP_GetLumpToFree(VSD_LUMP_T **pprLump)
{
    VSD_LUMP_MGR_T* const prLumpMgr = &_rVsdMgr.rLumpMgr;
    VSD_LUMP_T* const prLumpStart = prLumpMgr->arLump;
    kal_uint32 u4RetIdx = prLumpMgr->u4RetIdx;

    if (prLumpStart[u4RetIdx].eFlag == VSD_LUMP_STATUS_CEASED)
    {
        *pprLump = prLumpStart + u4RetIdx;
        return KAL_TRUE;
    }
    else
    {
        // *pprLump = NULL;
        return KAL_FALSE;
    }
}


/*****************************************************************************
* The term "to cease" means a lump is "to be freed" later.  In other words, a
* lump is ceased if Render has finished using it.
*
* Context: VCODEC
*****************************************************************************/
static void _VSD_LUMP_CeaseLump(VIDEO_BUFFERHEADER_TYPE_T *prFrameHeader)
{
    VSD_LUMP_MGR_T* const prLumpMgr = &_rVsdMgr.rLumpMgr;
    VSD_LUMP_T* const prLumpStart = prLumpMgr->arLump;
    const kal_uint32 u4TotalNum = prLumpMgr->u4TotalNum;
    kal_uint32 u4UsedNum = prLumpMgr->u4UsedNum;
    kal_uint32 u4RetIdx = prLumpMgr->u4RetIdx;
    kal_uint32 u4LoopCount;
    VSD_LUMP_T *prLump;

    if (prLumpMgr->u4UsedNum == 0) { ASSERT(0); }

    for (u4LoopCount = 0; u4LoopCount < u4UsedNum; u4LoopCount++)
    {
        prLump = prLumpStart + u4RetIdx;
        if (prLump->pu1Buffer == prFrameHeader->pu1Buffer)
        {
            if (prLump->eFlag != VSD_LUMP_STATUS_BAILED_OUT ||
                &prLump->rVaPrivateData != prFrameHeader->pPrivateData)
            {
                ASSERT(0);
            }
            drv_trace1(TRACE_GROUP_10, VSD_LUMP_SET_CEASED, u4RetIdx);
            prLump->eFlag = VSD_LUMP_STATUS_CEASED;
            break;
        }
        u4RetIdx = (u4RetIdx + 1) % u4TotalNum;
    }

#ifdef VSD_DEVELOPMENT
    if (u4LoopCount > VIDEO_SUBTITLE_MAX_FRAMES) { ASSERT(0); }
#endif  // VSD_DEVELOPMENT
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
static void _VSD_LUMP_SetupFrameHeader(VSD_LUMP_T *prLump)
{
    const kal_uint32 u4OutputPort = VideoCommGetOutputPortIndex(&_rVsdMgr.rCommState, VIDEO_PORT_SUBTITLE);
    VIDEO_COMPONENT_PARAM_T* const prComParam = VideoCommGetOutputComp(&_rVsdMgr.rCommState, u4OutputPort);
    const kal_uint32 u4TunneledInputPort = prComParam->u4PortIndex;
    VIDEO_BUFFERHEADER_TYPE_T *prBitHeader = &prLump->rBitHeader;
    VIDEO_BUFFERHEADER_TYPE_T *prFrameHeader = &prLump->rFrameHeader;

    switch (prBitHeader->eFlags)
    {
    case VIDEO_BUFFERFLAG_PARAMETERSET:
    case VIDEO_BUFFERFLAG_EOF:
    case VIDEO_BUFFERFLAG_SILENT:
        prFrameHeader->eFlags = VIDEO_BUFFERFLAG_SILENT;
        break;

    case VIDEO_BUFFERFLAG_SYNCFRAME:
        prFrameHeader->eFlags = prBitHeader->eFlags;
        break;

    default:
        ASSERT(0);
        break;
    }
    prFrameHeader->pPrivateData = (void*)&prLump->rVaPrivateData;
    prFrameHeader->pu1Buffer = prLump->pu1Buffer;  // FIXME: prLump->pu1Buffer can be eliminated by rewriting code.
    prFrameHeader->u8TimeStamp = prBitHeader->u8TimeStamp;
    prFrameHeader->u4BuffSize = _rVsdMgr.u4FrameSize;
    prFrameHeader->u4InputPort = u4TunneledInputPort;
    prFrameHeader->u4OutputPort = u4OutputPort;

#ifdef VSD_DEVELOPMENT
    drv_trace2(TRACE_GROUP_10, VSD_DEBUG_FRAME_INFO,
        (kal_uint32)prFrameHeader->pu1Buffer,
        (kal_uint32)prFrameHeader->u8TimeStamp);
#endif  // VSD_DEVELOPMENT
}


/*****************************************************************************
*
* Side effect:
*
* Context: VCODEC
*****************************************************************************/
__inline static void _VSD_LUMP_SetStatus(VSD_LUMP_T *prLump,
        VSD_LUMP_STATUS_T eStatus)
{
    prLump->eFlag = eStatus;
}


/*****************************************************************************
* Move prLumpMgr->u4RetIdx until it is not VSD_LUMP_STATUS_CEASED.
*
* Side effect: u4RetIdx
*
* Context:
*****************************************************************************/
__inline static void _VSD_LUMP_UpdateReturnIndex(void)
{
    VSD_LUMP_MGR_T* const prLumpMgr = &_rVsdMgr.rLumpMgr;
    VSD_LUMP_T* const prLumpStart = prLumpMgr->arLump;
    const kal_uint32 u4TotalNum = prLumpMgr->u4TotalNum;
    kal_uint32 u4UsedNum = prLumpMgr->u4UsedNum;
    kal_uint32 u4RetIdx = prLumpMgr->u4RetIdx;
    kal_uint32 u4LoopCount;
    VSD_LUMP_T *prLump;

    for (u4LoopCount = 0; u4LoopCount < u4UsedNum; u4LoopCount++)
    {
        prLump = prLumpStart + u4RetIdx;
        if (prLump->eFlag != VSD_LUMP_STATUS_FREE)
        {
            break;
        }
        // IMPORTANT!!! Do not clear prLump->pu1Buffer!!!
        kal_mem_set((void*)&prLump->rBitHeader, 0, sizeof(prLump->rBitHeader));
        kal_mem_set((void*)&prLump->rFrameHeader, 0, sizeof(prLump->rFrameHeader));
        kal_mem_set((void*)&prLump->rVaPrivateData, 0, sizeof(prLump->rVaPrivateData));
        _VSD_ASSERT_IF_EQUAL(prLumpMgr->u4UsedNum, 0);
        prLumpMgr->u4UsedNum--;
        u4RetIdx = (u4RetIdx + 1) % u4TotalNum;
    }

    prLumpMgr->u4RetIdx = u4RetIdx;
    drv_trace2(TRACE_GROUP_10, VSD_LUMP_UPDATE_RET_IDX, u4RetIdx, prLumpMgr->u4GetIdx);
}


/*****************************************************************************
*
* Context: VCODEC
*****************************************************************************/
static void _VSD_LUMP_Redraw(void)
{
    VSD_LUMP_MGR_T* const prLumpMgr = &_rVsdMgr.rLumpMgr;
    VSD_LUMP_T* const prLumpStart = prLumpMgr->arLump;
    VSD_LUMP_T *prLump;
    kal_uint32 u4TotalNum = prLumpMgr->u4TotalNum;
    kal_uint32 u4UsedNum = prLumpMgr->u4UsedNum;
    kal_uint32 u4RetIdx = prLumpMgr->u4RetIdx;
    kal_uint32 u4LoopCount;

    // It is important to clear the entries in the back-end queue.
    _VideoCommClearOutputQ(&_rVsdMgr.rCommState);

    for (u4LoopCount = 0; u4LoopCount < u4UsedNum; u4LoopCount++)
    {
        prLump = prLumpStart + u4RetIdx;
        drv_trace4(TRACE_GROUP_10, VSD_LUMP_REDRAW_STATE_INFO, u4RetIdx,
            prLumpMgr->u4GetIdx, (kal_uint32)(prLump->eFlag),
            (kal_uint32)(prLump->rBitHeader.u8TimeStamp));
        switch (prLump->eFlag)
        {
        case VSD_LUMP_STATUS_FREE:
        case VSD_LUMP_STATUS_CEASED:
            drv_trace0(TRACE_GROUP_10, VSD_LUMP_REDRAW_STATE_IGNORED);
            break;

        case VSD_LUMP_STATUS_LEASED:
        case VSD_LUMP_STATUS_BAILED_OUT:
            if (prLump->rBitHeader.u8TimeStamp >= _rVsdMgr.u8PartialResetTimeStamp)
            {
                drv_trace0(TRACE_GROUP_10, VSD_LUMP_REDRAW_STATE_REDRAWN);
                _VSD_FRONT_END_ProcessInput(prLump);
                _VSD_LUMP_SetStatus(prLump, VSD_LUMP_STATUS_LEASED);
            }
            else
            {
                drv_trace0(TRACE_GROUP_10, VSD_LUMP_REDRAW_STATE_CEASED);
                _VSD_LUMP_SetStatus(prLump, VSD_LUMP_STATUS_CEASED);
            }
            break;

        default:
            break;
        }
        u4RetIdx = (u4RetIdx + 1) % u4TotalNum;
    }
}


/*****************************************************************************
* Returns TRUE if there is at least one item in the back-end input queue.
*
* Context:
*****************************************************************************/
__inline static kal_bool _VSD_BACK_END_HasInput(void)
{
    VIDEO_COMM_STATE_T *prCommState = &_rVsdMgr.rCommState;

    if (VideoCommQueryOutputBuff(prCommState) > 0)
    {
        return KAL_TRUE;
    }

    return KAL_FALSE;
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
__inline static void _VSD_BACK_END_GetInput(VIDEO_BUFFERHEADER_TYPE_T *prFrameHeader)
{
    VIDEO_COMM_STATE_T *prCommState = &_rVsdMgr.rCommState;
    kal_bool fgSuccess;

    fgSuccess = VideoCommPopOutputBuff(prCommState, prFrameHeader);
    if (!fgSuccess)
    {
        ASSERT(0);
    }
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
static void _VSD_BACK_END_ProcessInput(VIDEO_BUFFERHEADER_TYPE_T *prFrameHeader)
{
    drv_trace4(TRACE_GROUP_10, VSD_PROCESS_BACK_END_INPUT,
        (kal_uint32)(prFrameHeader->pu1Buffer),
        (kal_uint32)(prFrameHeader->pPrivateData),
        (kal_uint32)(prFrameHeader->u8TimeStamp), prFrameHeader->eFlags);

    _VSD_LUMP_CeaseLump(prFrameHeader);
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
__inline static kal_bool _VSD_BACK_END_Send(VIDEO_BUFFERHEADER_TYPE_T *prBufferHeader)
{
    return _VSD_SendBufferHeader(VSD_PORT_BACK_END_OUTPUT, prBufferHeader);
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
static kal_bool _VSD_FRONT_END_HasInput(void)
{
    VIDEO_COMM_STATE_T *prCommState = &_rVsdMgr.rCommState;

    return (VideoCommQueryInputBuff(prCommState) > 0) ? KAL_TRUE : KAL_FALSE;
}


/*****************************************************************************
*
* Context: VCODEC
*****************************************************************************/
static void _VSD_FRONT_END_GetInput(VIDEO_BUFFERHEADER_TYPE_T *prBitHeader)
{
    VIDEO_COMM_STATE_T *prCommState = &_rVsdMgr.rCommState;
    kal_bool fgSuccess;

    fgSuccess = VideoCommPopInputBuff(prCommState, prBitHeader);
    if (!fgSuccess)
    {
        ASSERT(0);
    }
}


/*****************************************************************************
* Append RAW Lump to Back-End Resend Queue.
*
* Context: VCODEC
*****************************************************************************/
static void _VSD_FRONT_END_ProcessInput(VSD_LUMP_T *prLump)
{
    VSD_CODEC_API_T* const prCodecApi = _rVsdMgr.prCodecApi;
    VIDEO_BUFFERHEADER_TYPE_T *prBitHeader = &prLump->rBitHeader;
    VIDEO_BUFFERHEADER_TYPE_T *prFrameHeader = &prLump->rFrameHeader;
    VIDEO_ERROR_TYPE_T eError;

    drv_trace4(TRACE_GROUP_10, VSD_PROCESS_FRONT_END_INPUT,
        (kal_uint32)(prBitHeader->pu1Buffer),
        (kal_uint32)(prBitHeader->u8TimeStamp),
        prBitHeader->u4BuffSize, prBitHeader->eFlags);

    _VSD_LUMP_SetupFrameHeader(prLump);

    // Set Render private data.
    _VSD_SetRendererPrivateData(prFrameHeader);

    if (prFrameHeader->eFlags != VIDEO_BUFFERFLAG_SILENT)
    {
        eError = prCodecApi->pfnProcessData(prBitHeader, prFrameHeader);
        if (eError != VIDEO_ERROR_NONE)
        {
            ASSERT(0);
        }
    }
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
__inline static kal_bool _VSD_FRONT_END_Send(VIDEO_BUFFERHEADER_TYPE_T *prBufferHeader)
{
    return _VSD_SendBufferHeader(VSD_PORT_FRONT_END_OUTPUT, prBufferHeader);
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
static kal_bool _VSD_FRONT_END_IsReceiverFull(void)
{
    kal_uint32 u4SavedMask;
    kal_bool fgIsFrontEndReceiverFull;

    u4SavedMask = SaveAndSetIRQMask();
    fgIsFrontEndReceiverFull = _rVsdMgr.fgIsFrontEndReceiverFull;
    RestoreIRQMask(u4SavedMask);

    return fgIsFrontEndReceiverFull;
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
static kal_bool _VSD_BACK_END_IsReceiverFull(void)
{
    kal_uint32 u4SavedMask;
    kal_bool fgIsBackEndReceiverFull;

    u4SavedMask = SaveAndSetIRQMask();
    fgIsBackEndReceiverFull = _rVsdMgr.fgIsBackEndReceiverFull;
    RestoreIRQMask(u4SavedMask);

    return fgIsBackEndReceiverFull;
}


/*****************************************************************************
* Because there is no function for querying the command queue, a parameter is
* used in this function to store the command in the command queue.
*
* Side effect: a command may be popped out of the command queue.
*
* Context:
*****************************************************************************/
static VSD_ACTION_T _VSD_DecideAction(kal_uint32 *pu4Cmd, VSD_LUMP_T **pprLump)
{
    VIDEO_COMMAND_TYPE_T eType;
    VIDEO_STATE_TYPE_T eVideoState = VideoCommGetState(&_rVsdMgr.rCommState);
    VSD_ACTION_T eAction = VSD_ACTION_NONE;

    // Set lump pointer to NULL so that it does not need to be set in each
    // GetLumpXXX function.
    *pprLump = NULL;

    if (VideoCommPopCommand(&_rVsdMgr.rCommState, &eType, pu4Cmd))
    {
        if (eType != VIDEO_COMMAND_STATESET)
        {
            ASSERT(0);
        }
        eAction = VSD_ACTION_COMMAND;
    }
    else if (eVideoState == VIDEO_STATE_RUN)
    {
        if (_VSD_BACK_END_HasInput())  // Has back-end input?
        {
            eAction = VSD_ACTION_PROCESS_BACK_END;
        }
        else if (_VSD_FRONT_END_IsReceiverFull() == KAL_FALSE &&
            _VSD_LUMP_GetLumpToFree(pprLump) == KAL_TRUE)  // Send to front-end?
        {
            eAction = VSD_ACTION_SEND_TO_FRONT_END;
        }
        else if (_VSD_BACK_END_IsReceiverFull() == KAL_FALSE &&
            _VSD_LUMP_GetLumpToBailOut(pprLump) == KAL_TRUE)  // Send to back-end?
        {
            eAction = VSD_ACTION_SEND_TO_BACK_END;
        }
        else if (_VSD_FRONT_END_HasInput() &&
            _VSD_LUMP_GetLumpToLease(pprLump) == KAL_TRUE)  // Has front-end input and resource?
        {
            eAction = VSD_ACTION_PROCESS_FRONT_END;
        }
        else
        {
            eAction = VSD_ACTION_NONE;
        }
    }

    drv_trace1(TRACE_GROUP_10, VSD_DECIDE_ACTION, eAction);

    return eAction;
}


/*****************************************************************************
* Most of the global data structure needs to be cleared here.
*
* FIXME: The function of resetting or cleaning the global data structure is
*        not well written.  These operations are better to be collected into
*        a few functions rather than scattering around the source code.
*        I do not have enough time to do this for now.
*
* Context: VCODEC
*****************************************************************************/
static void _VSD_ResetAll(void)
{
    _rVsdMgr.u8PartialResetTimeStamp = 0;
    // _rVsdMgr.eVsdCodec = VSD_CODEC_UNKNOWN;
    // _rVsdMgr.prCodecApi = NULL;
    // _rVsdMgr.rFontEngineApi;

    _rVsdMgr.u4Width = 0;
    _rVsdMgr.u4Height = 0;
    _rVsdMgr.u4FrameSize = 0;

    //_rVsdMgr.u4FontSize;
    // _rVsdMgr.rColors;
    //_rVsdMgr.eEncoding;
    //_rVsdMgr.rAlignment;
    //_rVsdMgr.rFontStyles;

    _rVsdMgr.fgClosing =  KAL_FALSE;
    _rVsdMgr.fgIsFrontEndReceiverFull =  KAL_FALSE;
    _rVsdMgr.fgIsBackEndReceiverFull =  KAL_FALSE;
    _rVsdMgr.fgGotPartialReset =  KAL_FALSE;
    _rVsdMgr.fgGotResetQueues =  KAL_FALSE;
    _rVsdMgr.fgNoMoreInput =  KAL_FALSE;

    _VideoCommClearInputAndOutputQ(&_rVsdMgr.rCommState);
    _VSD_LUMP_ClearLump();
    _VSD_LUMP_InitMemory();
}


/*****************************************************************************
*
* Context: VCODEC
*****************************************************************************/
static void _VSD_ResetQueues(void)
{
    VIDEO_CALLBACK_TYPE_T *pfnCallback;

    _VideoCommClearInputAndOutputQ(&_rVsdMgr.rCommState);           // 1. Clear front-end and back-end input queues.
    _VSD_LUMP_InitMemory();                                         // 2. Clear lump queue.
    pfnCallback = VideoCommGetCallback(&_rVsdMgr.rCommState);
    pfnCallback->pfnEventHandler(VIDEO_EVENT_VSD_RESET_Q_DONE, 0, 0, NULL);  // 3. Callback MPL.
    _rVsdMgr.fgNoMoreInput = KAL_FALSE;  // FIXME: race condition
}


/*****************************************************************************
*
* Context: VCODEC
*****************************************************************************/
static kal_bool _VSD_ProcessCommand(kal_uint32 u4Cmd)
{
    const VIDEO_STATE_TYPE_T eCommand = (VIDEO_STATE_TYPE_T)u4Cmd;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_bool fgClosing = KAL_FALSE;

    drv_trace1(TRACE_GROUP_10, VSD_PROCESS_COMMAND, eCommand);

    switch (eCommand)
    {
    case VIDEO_STATE_CLOSE:
        fgClosing = KAL_TRUE;
        break;

    case VIDEO_STATE_INIT:
        VideoCommChangeState(&_rVsdMgr.rCommState, VIDEO_STATE_INIT);
        break;

    case VIDEO_STATE_IDLE:
        _VSD_ResetAll();
        VideoCommChangeState(&_rVsdMgr.rCommState, VIDEO_STATE_IDLE);
        break;

    case VIDEO_STATE_RUN:
        // Set properties to codec before any drawing operation is performed.
        eError = _VSD_CODEC_SetPrperties();
        if (eError != VIDEO_ERROR_NONE)
        {
            // _VSD_CODEC_Close()
        }
        switch (_rVsdMgr.rCommState.eState)
        {
        case VIDEO_STATE_IDLE:
            _VSD_LUMP_ClearLump();
            eError = _VSD_LUMP_InitMemory();
            if (eError != VIDEO_ERROR_NONE)
            {
                fgClosing = KAL_TRUE;
                // FIXME: Invoke a callback function, and throw the error code to it.
            }
            eError = _VSD_CODEC_Open();
            if (eError != VIDEO_ERROR_NONE)
            {
                // _VSD_CODEC_Close()
            }
            break;

        case VIDEO_STATE_STOP:
            if (_rVsdMgr.fgGotResetQueues)
            {
                _VSD_ResetQueues();
                _rVsdMgr.fgGotResetQueues = KAL_FALSE;
            }
            if (_rVsdMgr.fgGotPartialReset)
            {
                eError = _VSD_LUMP_InitMemory();
                if (eError != VIDEO_ERROR_NONE)
                {
                    fgClosing = KAL_TRUE;
                    // FIXME: Invoke a callback function, and throw the error code to it.
                }
                _VSD_LUMP_Redraw();
                _rVsdMgr.fgGotPartialReset = KAL_FALSE;
            }
            // The next "if" block is for the path "INIT --> IDLE --> STOP --> RUN".
            if (_rVsdMgr.u4FrameSize == 0)
            {
                eError = _VSD_LUMP_InitMemory();
                if (eError != VIDEO_ERROR_NONE)
                {
                    fgClosing = KAL_TRUE;
                    // FIXME: Invoke a callback function, and throw the error code to it.
                }
            }
            break;

        default:
            ASSERT(0);
            break;
        }
        VideoCommChangeState(&_rVsdMgr.rCommState, VIDEO_STATE_RUN);
        break;

    case VIDEO_STATE_STOP:
        VideoCommChangeState(&_rVsdMgr.rCommState, VIDEO_STATE_STOP);
        break;

    default:
        ASSERT(0);
        break;
    }

    return fgClosing;
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
static void _VSD_MainLoop(ilm_struct *prIlm)
{
    VSD_ACTION_T eAction;
    VIDEO_STATE_TYPE_T eVideoState;
    VSD_LUMP_T *prLump;
    kal_uint32 u4Cmd;
    kal_bool fgContinue = KAL_TRUE;

    VideoCommClrProcessing(&_rVsdMgr.rCommState);

    while (1)
    {
        eAction = _VSD_DecideAction(&u4Cmd, &prLump);
        switch (eAction)
        {
        case VSD_ACTION_COMMAND:
            _rVsdMgr.fgClosing = _VSD_ProcessCommand(u4Cmd);
            fgContinue = _rVsdMgr.fgClosing ? KAL_FALSE : KAL_TRUE;
            break;

        case VSD_ACTION_PROCESS_BACK_END:
            {
                VIDEO_BUFFERHEADER_TYPE_T rFrameHeader;
                // kal_mem_set((void*)&rFrameHeader, 0, sizeof(rFrameHeader));
                _VSD_BACK_END_GetInput(&rFrameHeader);
                _VSD_BACK_END_ProcessInput(&rFrameHeader);
            }
            break;

        case VSD_ACTION_PROCESS_FRONT_END:
            {
                _VSD_FRONT_END_GetInput(&prLump->rBitHeader);
                _VSD_FRONT_END_ProcessInput(prLump);
                _VSD_LUMP_SetStatus(prLump, VSD_LUMP_STATUS_LEASED);
            }
            break;

        case VSD_ACTION_SEND_TO_FRONT_END:
            {
                kal_bool fgFrontEndSuccess;

                fgFrontEndSuccess = _VSD_FRONT_END_Send(&prLump->rBitHeader);
                if (fgFrontEndSuccess)
                {
                    _VSD_LUMP_SetStatus(prLump, VSD_LUMP_STATUS_FREE);
                    _VSD_LUMP_UpdateReturnIndex();
                }
                else
                {
                    kal_uint32 u4SavedMask;
                    u4SavedMask = SaveAndSetIRQMask();
                    _rVsdMgr.fgIsFrontEndReceiverFull = KAL_TRUE;
                    RestoreIRQMask(u4SavedMask);
                }
            }
            break;

        case VSD_ACTION_SEND_TO_BACK_END:
            {
                kal_bool fgBackEndSuccess;

                fgBackEndSuccess = _VSD_BACK_END_Send(&prLump->rFrameHeader);
                if (fgBackEndSuccess)
                {
                    _VSD_LUMP_SetStatus(prLump, VSD_LUMP_STATUS_BAILED_OUT);
                }
                else
                {
                    kal_uint32 u4SavedMask;
                    u4SavedMask = SaveAndSetIRQMask();
                    _rVsdMgr.fgIsBackEndReceiverFull = KAL_TRUE;
                    RestoreIRQMask(u4SavedMask);
                }
            }
            break;

        case VSD_ACTION_NONE:
            fgContinue = KAL_FALSE;
            break;

        default:
            ASSERT(0);
            break;
        }

        eVideoState = VideoCommGetState(&_rVsdMgr.rCommState);
        switch (eVideoState)
        {
        case VIDEO_STATE_STOP:
            fgContinue = KAL_FALSE;
            break;

        default:
            // fgContinue = KAL_FALSE;
            break;
        }

        if (fgContinue == KAL_FALSE)
        {
            break;  // Break out of while(1).
        }
    }

    if (_rVsdMgr.fgClosing == KAL_TRUE)
    {
        // Checking "(VideoCommCheckProcessing(&_rVsdMgr.rCommState) == KAL_FALSE)"???
        VideoCommChangeState(&_rVsdMgr.rCommState, VIDEO_STATE_CLOSE);
    }
}

/*****************************************************************************
*
* Context:
*****************************************************************************/
static VIDEO_ERROR_TYPE_T _VSD_Init(void)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VIDEO_EXTMEM_HANDLER_T *prExtMemInfo;
    kal_mutexid eMutex = VideoGetMutex(MUTEX_USER_SUBTITLE_DECODER);
    VIDEO_PORT_CONFIG_T rInputPort;
    VIDEO_PORT_CONFIG_T rOutputPort;
    VIDEO_COMPONENT_INIT_T rInitConfig;

    // FIXME: Make sure (VIDEO_SUBTITLE_MAX_FRAMES < VSD_INPUT_BUFFER_Q_LEN)

    // Do not clear prExtMemInfo, and eMutex!!!
    prExtMemInfo = _rVsdMgr.prExtMemInfo;
    kal_mem_set((void*)&_rVsdMgr, 0, sizeof(_rVsdMgr));
    _rVsdMgr.rCommState.eMutex = eMutex;
    _rVsdMgr.prExtMemInfo = prExtMemInfo;

    kal_mem_set((void*)&rInputPort, 0, sizeof(rInputPort));
    rInputPort.ePortType = VIDEO_PORT_SUBTITLE;

    kal_mem_set((void*)&rOutputPort, 0, sizeof(rOutputPort));
    rOutputPort.ePortType = VIDEO_PORT_SUBTITLE;
    rOutputPort.fgSupplier = KAL_TRUE;

    kal_mem_set((void*)&rInitConfig, 0, sizeof(rInitConfig));
    rInitConfig.prInputPort1 = &rInputPort;
    rInitConfig.prOutputPort1 = &rOutputPort;
    rInitConfig.u4CmdQSize = VSD_COMMAND_Q_LEN;
    rInitConfig.u4InputBuffQSize = VSD_INPUT_BUFFER_Q_LEN;
    rInitConfig.u4OutputBuffQSize = VSD_OUTPUT_BUFFER_Q_LEN;
    rInitConfig.prExtMemHdlr = _rVsdMgr.prExtMemInfo;
    rInitConfig.eMutex = eMutex;

    eError = VideoCommInit(&_rVsdMgr.rCommState, &rInitConfig, "VSD");
    if (eError != VIDEO_ERROR_NONE)
    {
        drv_trace1(TRACE_GROUP_10, VSD_ERROR_COMMON_INIT, eError);
        return eError;
    }

    // Lump buffer can be obtained only once, but it needs to be sliced
    // whenever the rectangle of subtitle changes size.
    {
        kal_uint32 u4LumpBufferSize;
        kal_uint8 *pu1FrameBufferStart;

        // FIXME: Does the address returned by VideoGetExtBuffer() is always aligned to cache line boundary???
        u4LumpBufferSize = ROUND_UP_TO_POWER_OF_TWO(VSD_LUMP_TOTAL_MEM_SIZE, 4);
        pu1FrameBufferStart = (kal_uint8*)VideoGetExtBuffer(_rVsdMgr.prExtMemInfo, u4LumpBufferSize);
        if (pu1FrameBufferStart == NULL) { ASSERT(0); }
        _rVsdMgr.rLumpMgr.pu1FrameBufferStart = pu1FrameBufferStart;
    }

    drv_trace1(TRACE_GROUP_10, VSD_INIT, eError);

    return eError;
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
static VIDEO_ERROR_TYPE_T _VSD_SendCommand(VIDEO_COMMAND_TYPE_T rCmd, kal_uint32 u4Param)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_bool fgRet = KAL_FALSE;

    fgRet = VideoCommPushCommand(&_rVsdMgr.rCommState, rCmd, u4Param);
    if (fgRet == KAL_FALSE)
    {
        eError = VIDEO_ERROR_BUFF_FULL;
    }

    _VSD_WakeUp(VSD_MESSAGE_COMMAND);

    return eError;
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
static VIDEO_ERROR_TYPE_T _VSD_GetParameter(VIDEO_PARAM_TYPE_T eCmd, void *pParam)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    switch (eCmd)
    {
    case VIDEO_PARAM_INPUT_BUFFER_PARAM:
        VideoCommGetInputPortParam(&_rVsdMgr.rCommState, pParam);
        break;

    case VIDEO_PARAM_OUTPUT_BUFFER_PARAM:
        VideoCommGetOutputPortParam(&_rVsdMgr.rCommState, pParam);
        break;

    default:
        // eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
        ASSERT(0);
        break;
    }

    drv_trace2(TRACE_GROUP_10, VSD_GET_PARAM, eCmd, eError);

    return eError;
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
static VIDEO_ERROR_TYPE_T _VSD_SetParameter(VIDEO_PARAM_TYPE_T eCmd, void *pvParam)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VIDEO_STATE_TYPE_T eVideoState;

    eVideoState = VideoCommGetState(&_rVsdMgr.rCommState);
    if (eVideoState == VIDEO_STATE_RUN)
    {
        ASSERT(0);
    }

    drv_trace2(TRACE_GROUP_10, VSD_SET_PARAM, eCmd, eVideoState);

    switch (eCmd)
    {
    case VIDEO_PARAM_OUTPUT_BUFFER_PARAM:
        VideoCommSetOutputPortParam(&_rVsdMgr.rCommState, pvParam);
        break;

    case VIDEO_PARAM_INPUT_BUFFER_PARAM:
        VideoCommSetInputPortParam(&_rVsdMgr.rCommState, pvParam);
        break;

    case VIDEO_PARAM_VSD_CODEC:
        {
            VSD_CODEC_T eVsdCodec;
            eVsdCodec = *(VSD_CODEC_T*)pvParam;
            _rVsdMgr.eVsdCodec = eVsdCodec;
            _rVsdMgr.prCodecApi = GetVsdCodecApi(eVsdCodec);
            _VSD_ASSERT_IF_EQUAL(_rVsdMgr.prCodecApi, NULL);
        }
        break;

    case VIDEO_PARAM_VSD_FONT_ENGINE_API:
        {
            subtitle_fontengine_struct *prFontEngineApi = (subtitle_fontengine_struct*)pvParam;
            _rVsdMgr.rFontEngineApi = *prFontEngineApi;
        }
        break;

    case VIDEO_PARAM_VSD_RESOLUTION:
        {
            VSD_RESOLUTION_T *prResolution = (VSD_RESOLUTION_T*)pvParam;
            _rVsdMgr.u4Width = prResolution->u4Width;
            _rVsdMgr.u4Height = prResolution->u4Height;
            if (prResolution->u4Width > VIDEO_SUBTITLE_RECT_MAX_WIDTH ||
                prResolution->u4Height > VIDEO_SUBTITLE_RECT_MAX_HEIGHT)
            {
                ASSERT(0);
            }
            drv_trace2(TRACE_GROUP_10, VSD_SET_PARAM_RESOLUTION,
                prResolution->u4Width, prResolution->u4Height);
        }
        break;

    case VIDEO_PARAM_VSD_FONT_ENCODING:
        {
            VSD_ENCODING_T *peEncoding = (VSD_ENCODING_T*)pvParam;
            _rVsdMgr.eEncoding = *peEncoding;
        }
        break;

    case VIDEO_PARAM_VSD_FONT_SIZE:
        {
            kal_uint32 *pu4FontSize = (kal_uint32*)pvParam;
            _rVsdMgr.u4FontSize = *pu4FontSize;
            drv_trace1(TRACE_GROUP_10, VSD_SET_PARAM_FONT_SIZE, *pu4FontSize);
        }
        break;

    case VIDEO_PARAM_VSD_FONT_STYLES:
        {
            /* bold, italic, underline, strikeout, outline, shadow */
            VSD_FONT_STYLES_T *prFontStyles = (VSD_FONT_STYLES_T*)pvParam;
            _rVsdMgr.rFontStyles = *prFontStyles;
        }
        break;

    case VIDEO_PARAM_VSD_COLORS:
        {
            /* primary color, background color, alpha level */
            VSD_COLORS_T *prColors = (VSD_COLORS_T*)pvParam;
            _rVsdMgr.rColors = *prColors;
        }
        break;

    case VIDEO_PARAM_VSD_ALIGNMENT:
        {
            /* horizontal, vertical */
            VSD_ALIGNMENT_T *prAlignment = (VSD_ALIGNMENT_T*)pvParam;
            _rVsdMgr.rAlignment = *prAlignment;
        }
        break;

#if 0  // Display location is set to Render by MPL.
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // 0

    case VIDEO_PARAM_VSD_PARTIAL_RESET:
        {
            kal_uint64 *pu8TimeStamp = (kal_uint64*)pvParam;
            _rVsdMgr.u8PartialResetTimeStamp = *pu8TimeStamp;
            _rVsdMgr.fgGotPartialReset = KAL_TRUE;
            _VSD_WakeUp(VSD_MESSAGE_WAKE_UP);
        }
        break;

    case VIDEO_PARAM_VSD_RESET_QUEUES:
        {
            _rVsdMgr.fgGotResetQueues = KAL_TRUE;
            _rVsdMgr.fgNoMoreInput = KAL_TRUE;
            _VSD_WakeUp(VSD_MESSAGE_WAKE_UP);
        }
        break;

    default:
        eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
        ASSERT(0);
        break;
    }

    return eError;
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
static VIDEO_ERROR_TYPE_T _VSD_UseBuffer(kal_uint8* pBuff, kal_uint32 u4Size)
{
    ASSERT(0);
    return VIDEO_ERROR_NONE;
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
static VIDEO_ERROR_TYPE_T _VSD_EmptyThisBuffer(VIDEO_BUFFERHEADER_TYPE_T *prBitHeader)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // 0
    kal_bool fgRet;

    if (_rVsdMgr.fgNoMoreInput == KAL_TRUE)
    {
        ASSERT(0);
    }

    if (_rVsdMgr.fgClosing == KAL_TRUE)
    {
        return VIDEO_ERROR_BUFF_FULL;
    }

#if 0  // FIXME: My front-end module will set u4OutputPort to 2 which seems to be incorrect.
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // 0

    fgRet = VideoCommPushInputBuff(&_rVsdMgr.rCommState, prBitHeader);
    if (fgRet == KAL_FALSE)
    {
        drv_trace2(TRACE_GROUP_10, VSD_EMPTY_BUFFER_WITH_FULL_BUFFER,
            (kal_uint32)(prBitHeader->pu1Buffer),
            (kal_uint32)(prBitHeader->u8TimeStamp));
        eError = VIDEO_ERROR_BUFF_FULL;
    }
    else
    {
        kal_uint32 u4SavedMask;
        u4SavedMask = SaveAndSetIRQMask();
        _rVsdMgr.fgIsFrontEndReceiverFull = KAL_FALSE;
        RestoreIRQMask(u4SavedMask);
    }

    _VSD_WakeUp(VSD_MESSAGE_EMPTY_BUFFER);

    if (eError == VIDEO_ERROR_BUFF_FULL)
    {
        return eError;
    }

    // video_dbg_trace(VIDEO_DBG_OWNER_VSD, VIDEO_DBG_VSD_EMPTY_BUFFER,
    //     (kal_uint32)(prBitHeader->pu1Buffer));
    // video_dbg_trace(VIDEO_DBG_OWNER_VSD, VIDEO_DBG_VSD_EMPTY_TIME,
    //     (kal_uint32)(prBitHeader->u8TimeStamp));
    drv_trace2(TRACE_GROUP_10, VSD_EMPTY_BUFFER,
        (kal_uint32)(prBitHeader->pu1Buffer),
        (kal_uint32)(prBitHeader->u8TimeStamp));

    return eError;
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
static VIDEO_ERROR_TYPE_T _VSD_FillThisBuffer(VIDEO_BUFFERHEADER_TYPE_T *prFrameHeader)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    const kal_uint32 u4OutputPortIndex = VideoCommGetOutputPortIndex(&_rVsdMgr.rCommState, VIDEO_PORT_SUBTITLE);
    VIDEO_COMPONENT_PARAM_T* const prComParam = VideoCommGetOutputComp(&_rVsdMgr.rCommState, u4OutputPortIndex);
    const kal_uint32 u4TunneledInputPort = prComParam->u4PortIndex;
    kal_bool fgRet;

    if (_rVsdMgr.fgNoMoreInput == KAL_TRUE)
    {
        ASSERT(0);
    }

    if (_rVsdMgr.fgClosing == KAL_TRUE)
    {
        return VIDEO_ERROR_BUFF_FULL;
    }

    if ((prFrameHeader->u4InputPort != u4OutputPortIndex) ||
        (prFrameHeader->u4OutputPort != u4TunneledInputPort))
    {
        ASSERT(0);
        return VIDEO_ERROR_INPUT_PARAM_ERROR;
    }

    fgRet = VideoCommPushOutputBuff(&_rVsdMgr.rCommState, prFrameHeader);
    if (fgRet == KAL_FALSE)
    {
        drv_trace0(TRACE_GROUP_10, VSD_FILL_BUFFER_WITH_FULL_BUFFER);
        eError = VIDEO_ERROR_BUFF_FULL;  // FIXME: Return???
    }
    else
    {
        kal_uint32 u4SavedMask;
        u4SavedMask = SaveAndSetIRQMask();
        _rVsdMgr.fgIsBackEndReceiverFull = KAL_FALSE;
        RestoreIRQMask(u4SavedMask);
    }

    _VSD_WakeUp(VSD_MESSAGE_FILL_BUFFER);

    if (eError == VIDEO_ERROR_BUFF_FULL)
    {
        return eError;
    }

    // video_dbg_trace(VIDEO_DBG_OWNER_VSD, VIDEO_DBG_VSD_FILL_BUFFER, (kal_uint32)(prFrameHeader->pu1Buffer));
    // video_dbg_trace(VIDEO_DBG_OWNER_VSD, VIDEO_DBG_VSD_FILL_TIME, (kal_uint32)(prFrameHeader->u8TimeStamp));
    drv_trace2(TRACE_GROUP_10, VSD_FILL_BUFFER,
        (kal_uint32)(prFrameHeader->pu1Buffer),
        (kal_uint32)(prFrameHeader->u8TimeStamp));

    return eError;
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
static VIDEO_ERROR_TYPE_T _VSD_SetCallbacks(VIDEO_CALLBACK_TYPE_T *prCallback)
{
    VIDEO_ERROR_TYPE_T eError;

    eError = VideoCommSetCallbacks(&_rVsdMgr.rCommState, prCallback);

    if (eError != VIDEO_ERROR_NONE) { ASSERT(0); }  // FIXME: This may be commented out.

    return eError;
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
static VIDEO_ERROR_TYPE_T _VSD_DeInit(void)
{
    VIDEO_ERROR_TYPE_T eError;
    VSD_CODEC_API_T* const prCodecApi = _rVsdMgr.prCodecApi;

    if (prCodecApi != NULL)
    {
        eError = prCodecApi->pfnDeInit();
        if (eError != VIDEO_ERROR_NONE)
        {
            drv_trace1(TRACE_GROUP_10, VSD_DEINIT_ERROR, eError);
            return eError;
        }

        eError = prCodecApi->pfnClose();
        if (eError != VIDEO_ERROR_NONE)
        {
            drv_trace1(TRACE_GROUP_10, VSD_DEINIT_ERROR, eError);
            return eError;
        }
    }

    _VSD_DeinitMemory();

    eError = VideoCommDeInit(&_rVsdMgr.rCommState);

    VideoFreeMutex(MUTEX_USER_SUBTITLE_DECODER, _rVsdMgr.rCommState.eMutex);

    drv_trace1(TRACE_GROUP_10, VSD_DEINIT, eError);

    return eError;
}


/*****************************************************************************
*
*****************************************************************************/
const static VIDEO_COMPONENT_TYPE_T _rVsdComponent =
{
    /* The compiler does not compliant to the C99 standard! @_@ */
    /*.pfnInit            =*/ _VSD_Init,
    /*.pfnSendCommand     =*/ _VSD_SendCommand,
    /*.pfnGetParameter    =*/ _VSD_GetParameter,
    /*.pfnSetParameter    =*/ _VSD_SetParameter,
    /*.pfnUseBuffer       =*/ _VSD_UseBuffer,  // FIXME: Replace this with NULL.
    /*.pfnEmptyThisBuffer =*/ _VSD_EmptyThisBuffer,
    /*.pfnFillThisBuffer  =*/ _VSD_FillThisBuffer,
    /*.pfnSetCallbacks    =*/ _VSD_SetCallbacks,
    /*.pfnDeInit          =*/ _VSD_DeInit
};


/*****************************************************************************
*
* Context:
*****************************************************************************/
VIDEO_COMPONENT_TYPE_T* GetVsdHandle(VIDEO_EXTMEM_HANDLER_T *prExtMemInfo)
{
    VIDEO_COMPONENT_TYPE_T *_prVsdComponent = (VIDEO_COMPONENT_TYPE_T*)&_rVsdComponent;
    VIDEO_ERROR_TYPE_T eError;

    _rVsdMgr.prExtMemInfo = prExtMemInfo;

    eError = _prVsdComponent->pfnInit();
    if (eError != VIDEO_ERROR_NONE)
    {
        _prVsdComponent = NULL;
    }

    drv_trace1(TRACE_GROUP_10, VSD_GET_HANDLE, eError);

    return _prVsdComponent;
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
VIDEO_ERROR_TYPE_T ReleaseVsdHandle(VIDEO_COMPONENT_TYPE_T *prVsdComponent)
{
    const VSD_CODEC_T eVsdCodec = _rVsdMgr.eVsdCodec;
    VIDEO_ERROR_TYPE_T eError;

    if (prVsdComponent != &_rVsdComponent)
    {
        drv_trace0(TRACE_GROUP_10, VSD_RELEASE_HANDLE_UNKNOWN_HANDLE);
        return VIDEO_ERROR_INPUT_PARAM_ERROR;
    }

    if (_rVsdMgr.prCodecApi != NULL)
    {
        eError = ReleaseVsdCodecApi(eVsdCodec, _rVsdMgr.prCodecApi);
        if (eError !=  VIDEO_ERROR_NONE) { ASSERT(0); }
    }

    eError = prVsdComponent->pfnDeInit();
    if (eError !=  VIDEO_ERROR_NONE)
    {
        drv_trace1(TRACE_GROUP_10, VSD_RELEASE_HANDLE_ERROR_DEINIT, eError);
    }

    drv_trace2(TRACE_GROUP_10, VSD_RELEASE_HANDLE, eVsdCodec, eError);

    return eError;
}


/*****************************************************************************
*
* Context:
*****************************************************************************/
void VsdMain(ilm_struct *prIlm)
{
    _VSD_MainLoop(prIlm);
}


#else

/*****************************************************************************
* Context:
*****************************************************************************/
VIDEO_COMPONENT_TYPE_T* GetVsdHandle(VIDEO_EXTMEM_HANDLER_T *prExtMemInfo)
{
    return NULL;
}


/*****************************************************************************
* Context:
*****************************************************************************/
VIDEO_ERROR_TYPE_T ReleaseVsdHandle(VIDEO_COMPONENT_TYPE_T *prVsdComponent)
{
    return VIDEO_ERROR_NONE;
}

/*****************************************************************************
* Context:
*****************************************************************************/
void VsdMain(ilm_struct *prIlm)
{
    /* Empty */
}

#endif  // defined(__VE_SUBTITLE_SUPPORT__)


#endif  // defined(__VE_VIDEO_ARCHI_V2__)

#pragma arm section code

