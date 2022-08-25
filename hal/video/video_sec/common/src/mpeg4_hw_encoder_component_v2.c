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
 *   mpeg4_hw_encoder_component_v2.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *   This file defines the adaptor of mpeg4 hw encoder
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_features_video.h"

#ifdef __VE_VIDEO_ARCHI_V2__
#ifdef __VE_MPEG4_ENC_HW_SUPPORT__

#include "video_types_v2.h"
#include "video_buffer_management_v2.h"
#include "Video_comm_v2.h"
#include "vcodec_v2_trc.h"

#include "mpeg4_hw_encoder_component_v2.h"
#include "mpeg4_hw_encore_v2.h"
#include "drv_gfx_dct_control.h"
#include "mm_power_ctrl.h"

#include "mpeg4_hw_v2.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "video_dbg_v2.h"
#include "video_codec_type_v2.h"
#include "MPEG4HWEncMem.h"
#include "video_encoder_component_v2.h"
#include "video_codec_if_v2.h"
#include "custom_video_enc_if.h"
#include "video_codec_mem_v2.h"
#include "cache_sw.h"

MPEG4_HW_ENCODER_CTRL_T rMPEG4HWEncCtrl;
MPEG4_ENC_DRIVER* rpMPEG4HWEncDriver;
//static kal_mutexid  u4EncDecMutex;
//kal_bool fgIsMPEG4HWUsed = 0;
VIDEO_MPEG4HW_USER_T _eMPEG4HWUser = VIDEO_MPEG4HW_NONE;
VIDEO_MPEG4HW_USER_T _u1MPEG4HWOccpuy = VIDEO_MPEG4HW_NONE;

/******************************************************************************
*
*
* Module internal static functions
*
*
******************************************************************************/

static void _MPEG4HWEncControlInit(void)
{
    #if 0
/* under construction !*/
/* under construction !*/
    #endif
}

static void _MPEG4HWEncControlDeInit(void)
{
    // deinit control variables
}

/******************************************************************************
*
*
* Module external functions
*
*
******************************************************************************/

void MPEG4EncCallbackYUVDone(kal_uint8* pu1Ptr)
{
    ASSERT(rMPEG4HWEncCtrl.pfYUVDone);

    drv_trace1(TRACE_GROUP_10, MPEG4HW_CALLBACK_YUV_DONE, (kal_uint32)(pu1Ptr));

    rMPEG4HWEncCtrl.pfYUVDone(pu1Ptr);
}

void MPEG4EncCallbackEncPause(kal_uint8* pu1Ptr)
{
    ASSERT(rMPEG4HWEncCtrl.pfEncPause);

    drv_trace1(TRACE_GROUP_10, MPEG4HW_CALLBACK_ENC_PAUSE, (kal_uint32)(pu1Ptr));

    rMPEG4HWEncCtrl.pfEncPause(pu1Ptr);
}

void MPEG4EncCallbackBITSDone(void)    //Tell common part to get bitstream.
{
    ASSERT(rMPEG4HWEncCtrl.pfBITSDone);

    rMPEG4HWEncCtrl.pfBITSDone();
}

/*
void MPEG4HWEncDecMutexTake(void)
{
    ASSERT(u4EncDecMutex);
    kal_take_mutex(u4EncDecMutex);
}

void MPEG4HWEncDecMutexGive(void)
{
    ASSERT(u4EncDecMutex);
    kal_give_mutex(u4EncDecMutex);
}
*/

kal_bool MPEG4HWHwResourceGet(VIDEO_MPEG4HW_USER_T eMPEG4HWUser)
{
    kal_bool   fgResult;
    kal_uint32 savedMask;

    video_dbg_trace(VIDEO_DBG_OWNER_ENCODER, VIDEO_DBG_MPEG4HW_RESOURCE_GET, video_get_current_time());
    video_dbg_trace(VIDEO_DBG_OWNER_ENCODER, VIDEO_DBG_MPEG4HW_RESOURCE_GET, eMPEG4HWUser);
    drv_trace1(TRACE_GROUP_10, MPEG4HW_RESOURCE_GET, eMPEG4HWUser);

    savedMask = SaveAndSetIRQMask();
    if (!_eMPEG4HWUser)
    {
        _eMPEG4HWUser = eMPEG4HWUser;
        fgResult = KAL_TRUE;
    }
    else
    {
        fgResult = KAL_FALSE;
    }
    RestoreIRQMask(savedMask);
    return fgResult;
}

void MPEG4HWHwResourceFree(VIDEO_MPEG4HW_USER_T eMPEG4HWUser)
{
    kal_uint32 savedMask;

    video_dbg_trace(VIDEO_DBG_OWNER_ENCODER, VIDEO_DBG_MPEG4HW_RESOURCE_FREE, video_get_current_time());
    video_dbg_trace(VIDEO_DBG_OWNER_ENCODER, VIDEO_DBG_MPEG4HW_RESOURCE_FREE, _eMPEG4HWUser);
    drv_trace1(TRACE_GROUP_10, MPEG4HW_RESOURCE_FREE, eMPEG4HWUser);

    ASSERT(_eMPEG4HWUser == eMPEG4HWUser);

    savedMask = SaveAndSetIRQMask();
    _eMPEG4HWUser = VIDEO_MPEG4HW_NONE;
    RestoreIRQMask(savedMask);
}

kal_bool MPEG4HWOpen(VIDEO_MPEG4HW_USER_T eMPEG4HWUser)
{
    kal_bool   fgResult = KAL_TRUE;
    //kal_uint32 savedMask;

    ASSERT(!(_u1MPEG4HWOccpuy & eMPEG4HWUser));

    //savedMask = SaveAndSetIRQMask();

   if(_u1MPEG4HWOccpuy == VIDEO_MPEG4HW_NONE)
   {
        // occupy DCT
        if(!drv_gfx_preempt_dct(DCT_USER_MPEG4_CODEC)) { ASSERT(0); }
        // power on HW PDN
        mm_enable_power(MMPWRMGR_MP4);
        mm_enable_power(MMPWRMGR_DCT);
   }

    _u1MPEG4HWOccpuy = (VIDEO_MPEG4HW_USER_T)(_u1MPEG4HWOccpuy | eMPEG4HWUser);

    //RestoreIRQMask(savedMask);
    return fgResult;
}
kal_bool MPEG4HWClose(VIDEO_MPEG4HW_USER_T eMPEG4HWUser)
{
    kal_bool   fgResult = KAL_TRUE;
    //kal_uint32 savedMask;

    ASSERT(_u1MPEG4HWOccpuy & eMPEG4HWUser);

    //savedMask = SaveAndSetIRQMask();
    _u1MPEG4HWOccpuy = (VIDEO_MPEG4HW_USER_T)(_u1MPEG4HWOccpuy & ( eMPEG4HWUser^0xFF) );
    if(_u1MPEG4HWOccpuy == VIDEO_MPEG4HW_NONE)
    {
        // release DCT
        drv_gfx_close_dct(DCT_USER_MPEG4_CODEC);
        // power down HW PDN
        mm_disable_power(MMPWRMGR_MP4);
        mm_disable_power(MMPWRMGR_DCT);
    }

    //RestoreIRQMask(savedMask);
    return fgResult;
}
kal_bool MPEG4HWHwResourceFreeIfOccupy(VIDEO_MPEG4HW_USER_T eMPEG4HWUser)
{
    kal_bool fgResult = KAL_FALSE;
    kal_uint32 savedMask;

    if(_eMPEG4HWUser != eMPEG4HWUser)
        return fgResult;

    video_dbg_trace(VIDEO_DBG_OWNER_ENCODER, VIDEO_DBG_MPEG4HW_RESOURCE_FREE, video_get_current_time());
    video_dbg_trace(VIDEO_DBG_OWNER_ENCODER, VIDEO_DBG_MPEG4HW_RESOURCE_FREE, _eMPEG4HWUser);
    drv_trace1(TRACE_GROUP_10, MPEG4HW_RESOURCE_FREE, eMPEG4HWUser);

    ASSERT(_eMPEG4HWUser == eMPEG4HWUser);

    savedMask = SaveAndSetIRQMask();
    _eMPEG4HWUser = VIDEO_MPEG4HW_NONE;
    RestoreIRQMask(savedMask);
    fgResult = KAL_TRUE;
    return fgResult;
}

/******************************************************************************
*
*
* Module adapter functions
*
*
******************************************************************************/
VIDEO_ENCODER_CODEC_ERROR_T MPEG4HWEncSetParameter(VIDEO_ENCODER_PARAM_TYPE_T eCmd, void *pParam);

VIDEO_ENCODER_CODEC_ERROR_T MPEG4HWEncOpen(void)
{
    VIDEO_ENCODER_CODEC_ERROR_T eRet = VIDEO_ENCODER_CODEC_ERROR_NONE;
    MPEG4_ENCORE_SCENARIO eScenario;
    kal_bool fgrCacheable;
    MPEG4_ENCORE_MEM_INFO *rMPEG4Mem = &rMPEG4HWEncCtrl.rMPEG4Mem;

    kal_mem_set(rMPEG4Mem, 0, sizeof(MPEG4_ENCORE_MEM_INFO));

    rpMPEG4HWEncDriver = GetMPEG4HWEncDriverHandle();

    ASSERT(rMPEG4HWEncCtrl.eScenario!=VIDEO_ENCODER_SCENARIO_NONE);

    switch(rMPEG4HWEncCtrl.eScenario)
    {
    case VIDEO_ENCODER_SCENARIO_ENCODER:
        eScenario = MPEG4_ENCORE_SCENARIO_REC;
        rpMPEG4HWEncDriver->set_param(MPEG4_ENCORE_PARAM_SCENARIO, (void *)&eScenario);
        rMPEG4Mem->int_mem_size = ENC_MAX_INT_MEMORY(ENC_MAX_FRAME_WIDTH, ENC_MAX_FRAME_HEIGHT)+8;
        rMPEG4Mem->ext_mem_size = ENC_MAX_EXT_MEMORY(ENC_MAX_FRAME_WIDTH, ENC_MAX_FRAME_HEIGHT)+8;
        rMPEG4Mem->res_mem_size = ENC_MAX_RESUME_BUFFER_SIZE;
        break;
    case VIDEO_ENCODER_SCENARIO_VT:
        eScenario = MPEG4_ENCORE_SCENARIO_VT;
        rpMPEG4HWEncDriver->set_param(MPEG4_ENCORE_PARAM_SCENARIO, (void *)&eScenario);
        rMPEG4Mem->int_mem_size = ENC_MAX_INT_MEMORY(ENC_MAX_FRAME_WIDTH_VT, ENC_MAX_FRAME_HEIGHT_VT)+8;
        rMPEG4Mem->ext_mem_size = ENC_MAX_EXT_MEMORY(ENC_MAX_FRAME_WIDTH_VT, ENC_MAX_FRAME_HEIGHT_VT)+8;
        rMPEG4Mem->res_mem_size = ENC_MAX_RESUME_BUFFER_SIZE_VT;
        break;
    default :
        ASSERT(0);
        break;
    }

    rMPEG4Mem->int_mem_addr = (kal_uint8 *)VideoEncoderGetIntMem(rMPEG4Mem->int_mem_size);
    ASSERT(rMPEG4Mem->int_mem_addr);
    rMPEG4Mem->int_mem_addr = (kal_uint8 *)(((kal_uint32)rMPEG4Mem->int_mem_addr + 7) & 0xfffffff8);

    rMPEG4Mem->ext_mem_addr = (kal_uint8 *)VideoEncoderMallocAligned(rMPEG4Mem->ext_mem_size);
    ASSERT(rMPEG4Mem->ext_mem_addr);
    rMPEG4Mem->ext_mem_addr = (kal_uint8 *)(((kal_uint32)rMPEG4Mem->ext_mem_addr + 7) & 0xfffffff8);
    fgrCacheable = VideoCommIsExtBufferCacheable((kal_uint32)rMPEG4Mem->ext_mem_addr, rMPEG4Mem->ext_mem_size);
    if(fgrCacheable)
    {
        rMPEG4Mem->ext_mem_addr = (kal_uint8*)VideoCommExtBufferCacheableSwitchAlignMemory(
            (kal_uint32)rMPEG4Mem->ext_mem_addr, rMPEG4Mem->ext_mem_size, VIDEO_NON_CACHEABLE);
    }

    rMPEG4Mem->res_mem_addr = (kal_uint8 *)VideoEncoderMallocAligned(rMPEG4Mem->res_mem_size);
    ASSERT(rMPEG4Mem->res_mem_addr);
    fgrCacheable = VideoCommIsExtBufferCacheable((kal_uint32)rMPEG4Mem->res_mem_addr, rMPEG4Mem->res_mem_size);
    if(fgrCacheable)
    {
        rMPEG4Mem->res_mem_addr = (kal_uint8*)VideoCommExtBufferCacheableSwitchAlignMemory(
            (kal_uint32)rMPEG4Mem->res_mem_addr, rMPEG4Mem->res_mem_size, VIDEO_NON_CACHEABLE);
    }

    rpMPEG4HWEncDriver->open(rMPEG4Mem);

    drv_trace2(TRACE_GROUP_10, MPEG4HWENC_OPEN, rMPEG4Mem->int_mem_size, rMPEG4Mem->ext_mem_size);

    return eRet;
}


VIDEO_ENCODER_CODEC_ERROR_T MPEG4HWEncInit(void)
{
    CUSTOM_VENC_ERROR_T ret;
    kal_uint32 u4val;

    _MPEG4HWEncControlInit();

    ASSERT(rpMPEG4HWEncDriver);
    ASSERT(rMPEG4HWEncCtrl.u4FrameRate);

    ret = CustomVenc_Ctrl(CUSTOM_VENC_OP_GET_BIT_RATE, NULL, 0, &u4val, sizeof(kal_uint32));
    ASSERT(ret == CUSTOM_VENC_ERROR_NONE);
    MPEG4HWEncSetParameter(VENC_PARAM_BITRATE, &u4val);

    rpMPEG4HWEncDriver->init();

    drv_trace0(TRACE_GROUP_10, MPEG4HWENC_INIT);

    return VIDEO_ENCODER_CODEC_ERROR_NONE;
}


VIDEO_ENCODER_CODEC_ERROR_T MPEG4HWEncGetParameter(VIDEO_ENCODER_PARAM_TYPE_T eCmd, void* pParam)
{
    VIDEO_ENCODER_CODEC_ERROR_T eRet = VIDEO_ENCODER_CODEC_ERROR_NONE;
    VIDEO_ENC_MEMORY_T *prMemorySize;

    switch(eCmd)
    {
    case VENC_PARAM_MEMORY_REQUIREMENT:
        prMemorySize = (VIDEO_ENC_MEMORY_T*)pParam;
        switch(rMPEG4HWEncCtrl.eScenario)
        {
        case VIDEO_ENCODER_SCENARIO_ENCODER:
            prMemorySize->u4ExternalSize = ENC_MAX_EXT_MEMORY(ENC_MAX_FRAME_WIDTH, ENC_MAX_FRAME_HEIGHT) + ENC_MAX_RESUME_BUFFER_SIZE + CPU_CACHE_LINE_SIZE_MINE;
            prMemorySize->u4InternalSize = ENC_MAX_INT_MEMORY(ENC_MAX_FRAME_WIDTH, ENC_MAX_FRAME_HEIGHT);
            break;

        case VIDEO_ENCODER_SCENARIO_VT:
            prMemorySize->u4ExternalSize = ENC_MAX_EXT_MEMORY(ENC_MAX_FRAME_WIDTH_VT, ENC_MAX_FRAME_HEIGHT_VT) + ENC_MAX_RESUME_BUFFER_SIZE_VT + CPU_CACHE_LINE_SIZE_MINE;
            prMemorySize->u4InternalSize = ENC_MAX_INT_MEMORY(ENC_MAX_FRAME_WIDTH_VT, ENC_MAX_FRAME_HEIGHT_VT);
            break;

        default:
            ASSERT(0);
            break;
        }
        break;

    case VENC_PARAM_BITSTREAM_IN_CACHE:
        *(kal_bool*)pParam = KAL_FALSE;
        break;

    case VENC_PARAM_FRM_BUFFER_ALIGNMENT:
        *(kal_uint32*)pParam = ENC_YUV_BUFFER_ALIGNED_BYTES;
        break;

    case VENC_PARAM_HOLD_RES_TILL_RELEASE_FRM:
        switch(rMPEG4HWEncCtrl.eScenario)
        {
        case VIDEO_ENCODER_SCENARIO_ENCODER:
            *(kal_bool*)pParam = KAL_FALSE;
            break;
        case VIDEO_ENCODER_SCENARIO_VT:
            *(kal_bool*)pParam = KAL_TRUE;
            break;

        default:
            ASSERT(0);
            break;

        }
        break;

    case VENC_PARAM_IS_BLOCKBASED_YUV:
        *(kal_bool*)pParam = KAL_TRUE;
        break;

    default:
        //ASSERT(0);
        eRet = VIDEO_ENCODER_CODEC_PARAM_NOT_SUPPORT;
        break;
    }

    drv_trace2(TRACE_GROUP_10, MPEG4HWENC_GET_PARAM, eCmd, *(kal_uint32*)pParam);

    return eRet;
}


VIDEO_ENCODER_CODEC_ERROR_T MPEG4HWEncSetParameter(VIDEO_ENCODER_PARAM_TYPE_T eCmd, void *pParam)
{
    VIDEO_ENCODER_CODEC_ERROR_T eRet = VIDEO_ENCODER_CODEC_ERROR_NONE;

    ASSERT(rpMPEG4HWEncDriver);

    switch(eCmd)
    {
    case VENC_PARAM_WIDTH:
        rpMPEG4HWEncDriver->set_param(MPEG4_ENCORE_PARAM_WIDTH, pParam);
        drv_trace2(TRACE_GROUP_10, MPEG4HWENC_SET_PARAM, eCmd, *(kal_uint32*)pParam);
        break;

    case VENC_PARAM_HEIGHT:
        rpMPEG4HWEncDriver->set_param(MPEG4_ENCORE_PARAM_HEIGHT, pParam);
        drv_trace2(TRACE_GROUP_10, MPEG4HWENC_SET_PARAM, eCmd, *(kal_uint32*)pParam);
        break;

    case VENC_PARAM_BITRATE:
        rpMPEG4HWEncDriver->set_param(MPEG4_ENCORE_PARAM_BITRATE, pParam);
        drv_trace2(TRACE_GROUP_10, MPEG4HWENC_SET_PARAM, eCmd, *(kal_uint32*)pParam);
        break;

    case VENC_PARAM_FRAME_RATE:
        rMPEG4HWEncCtrl.u4FrameRate = *(kal_uint32*)(pParam);
        rpMPEG4HWEncDriver->set_param(MPEG4_ENCORE_PARAM_FRAME_RATE, pParam);
        drv_trace2(TRACE_GROUP_10, MPEG4HWENC_SET_PARAM, eCmd, *(kal_uint32*)pParam);
        break;

    case VENC_PARAM_GEN_HEADER_FRM_RATE:
        rMPEG4HWEncCtrl.u4GenHeaderFrameRate = *(kal_uint32*)(pParam);
        rpMPEG4HWEncDriver->set_param(MPEG4_ENCORE_TIME_INCREMENT, pParam);
        drv_trace2(TRACE_GROUP_10, MPEG4HWENC_SET_PARAM, eCmd, *(kal_uint32*)pParam);
        break;

    case VENC_PARAM_SYNC_INTERVAL:
        if(!*(kal_uint32*)(pParam))
            *(kal_uint32*)(pParam) = ENC_DEFAULT_INTRA_PERIOD;
        rpMPEG4HWEncDriver->set_param(MPEG4_ENCORE_SYNC_INTERVAL, pParam);
        drv_trace2(TRACE_GROUP_10, MPEG4HWENC_SET_PARAM, eCmd, *(kal_uint32*)pParam);
        break;

    case VENC_PARAM_MAX_PKG_SIZE:
        rMPEG4HWEncCtrl.u4MaxPktSize = *(kal_uint32*)(pParam);
        rpMPEG4HWEncDriver->set_param(MPEG4_ENCORE_PARAM_MAX_PKG_SIZE, pParam);
        drv_trace2(TRACE_GROUP_10, MPEG4HWENC_SET_PARAM, eCmd, *(kal_uint32*)pParam);
        break;

    case VENC_PARAM_SHORT_HEADER:
        rpMPEG4HWEncDriver->set_param(MPEG4_ENCORE_PARAM_SHORT_HEADER, pParam);
        drv_trace2(TRACE_GROUP_10, MPEG4HWENC_SET_PARAM, eCmd, *(kal_bool*)pParam);
        break;

    case VENC_PARAM_FORCE_ENCODE_I:
        rpMPEG4HWEncDriver->set_param(MPEG4_ENCORE_FORCE_ENCODE_I, pParam);
        drv_trace2(TRACE_GROUP_10, MPEG4HWENC_SET_PARAM, eCmd, *(kal_uint32*)pParam);
        break;

    case VENC_PARAM_QUALITY:
        rMPEG4HWEncCtrl.eQuality = *(VIDEO_ENCODER_QUALITY_T*)(pParam);
        drv_trace2(TRACE_GROUP_10, MPEG4HWENC_SET_PARAM_QUALITY, eCmd, rMPEG4HWEncCtrl.eQuality);
        break;

    case VENC_PARAM_SCENARIO:
        {
        MPEG4_ENCORE_SCENARIO eScenario;
        rMPEG4HWEncCtrl.eScenario = *(VIDEO_ENCODER_SCENARIO_T*)(pParam);
        drv_trace2(TRACE_GROUP_10, MPEG4HWENC_SET_PARAM_SCENARIO, eCmd, rMPEG4HWEncCtrl.eScenario);
        switch(rMPEG4HWEncCtrl.eScenario)
        {
        case VIDEO_ENCODER_SCENARIO_ENCODER:
            eScenario = MPEG4_ENCORE_SCENARIO_REC;
            rpMPEG4HWEncDriver->set_param(MPEG4_ENCORE_PARAM_SCENARIO, (void *)&eScenario);
            break;

        case VIDEO_ENCODER_SCENARIO_VT:
            eScenario = MPEG4_ENCORE_SCENARIO_VT;
            rpMPEG4HWEncDriver->set_param(MPEG4_ENCORE_PARAM_SCENARIO, (void *)&eScenario);
            break;

        default:
            ASSERT(0);
            break;
        }
        break;
        }

    case VENC_PARAM_CODEC_TYPE:
	{
	kal_bool fgShortHeader = KAL_FALSE;			
        rMPEG4HWEncCtrl.eCodecType = *(VIDEO_ENCODER_CODEC_T*)(pParam);
	if(rMPEG4HWEncCtrl.eCodecType == ENCODER_CODEC_TYPE_H263)
	{
            fgShortHeader = KAL_TRUE;
	}
	else if(rMPEG4HWEncCtrl.eCodecType == ENCODER_CODEC_TYPE_MPEG4)
	{

	}
	else
	{
		    ASSERT(0);
	}		
        rpMPEG4HWEncDriver->set_param(MPEG4_ENCORE_PARAM_SHORT_HEADER, &fgShortHeader);						
			
        drv_trace2(TRACE_GROUP_10, MPEG4HWENC_SET_PARAM_CODEC_TYPE, eCmd, rMPEG4HWEncCtrl.eCodecType);
        break;
    	}

    case VENC_PARAM_ROTATE:
        eRet = VIDEO_ENCODER_CODEC_PARAM_NOT_SUPPORT;
        break;

#if 1
    case VENC_PARAM_SET_CALLBACK:
        {
        VIDEO_ENCODER_ADAPT_CALLBACK_T* prCallbacks = (VIDEO_ENCODER_ADAPT_CALLBACK_T*)(pParam);
        ASSERT(prCallbacks->pfnReleaseFrame);
        ASSERT(prCallbacks->pfnEncoderPaused);
        ASSERT(prCallbacks->pfnGenBitstream);
        rMPEG4HWEncCtrl.pfYUVDone  = prCallbacks->pfnReleaseFrame;
        rMPEG4HWEncCtrl.pfEncPause = prCallbacks->pfnEncoderPaused;
        rMPEG4HWEncCtrl.pfBITSDone = prCallbacks->pfnGenBitstream;
        drv_trace2(TRACE_GROUP_10, MPEG4HWENC_SET_PARAM, eCmd, 1);
        }
        break;
#else
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

    default:
        eRet = VIDEO_ENCODER_CODEC_PARAM_NOT_SUPPORT;
        break;
    }

    return eRet;
}


VIDEO_ENCODER_CODEC_ERROR_T MPEG4HWEncGenerateHeader(void)
{
    VIDEO_ENCODER_CODEC_ERROR_T eRet = VIDEO_ENCODER_CODEC_ERROR_NONE;
    kal_uint8* pu1StartAddr;
    kal_uint8* pu1EndAddr;
    kal_uint8* pu1WritePtr;
    kal_uint8* pu1ReadAddr;
//    kal_uint8* pu1NextWritePtr;
    kal_uint32 u4AvailLen, u4BuffLen;
    kal_uint32 u4WriteLen;
//    kal_uint32 u4NextAvailLen;
    kal_bool   fgResult;

    ASSERT(rpMPEG4HWEncDriver);

    VideoEncoderAllocateBitstreamBuffer(&pu1StartAddr, &pu1EndAddr, &pu1WritePtr, &pu1ReadAddr, &u4BuffLen);
    if ((kal_uint32)pu1ReadAddr <= (kal_uint32)pu1WritePtr)
    {
        u4AvailLen = (kal_uint32)pu1EndAddr - (kal_uint32)pu1WritePtr;
    }
    else  // (u4WP < u4RP)
    {
        u4AvailLen = (kal_uint32)pu1ReadAddr - (kal_uint32)pu1WritePtr;
    }

#if 1 // Currently VOS should always get enough buffer size.
    ASSERT (u4AvailLen > ENC_MAX_VOS_SIZE);
#else
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

    fgResult = rpMPEG4HWEncDriver->gen_vos(pu1WritePtr, u4AvailLen, &u4WriteLen);

    if(fgResult)
    {
        VideoEncoderUpdateBitstreamWP((pu1WritePtr+u4WriteLen), 1);
        MPEG4EncCallbackBITSDone();
    }
    else
    {
        eRet = VIDEO_ENCODER_CODEC_ERROR;
    }

    drv_trace0(TRACE_GROUP_10, MPEG4HWENC_GEN_HEADER);

    return eRet;
}


VIDEO_ENCODER_CODEC_ERROR_T MPEG4HWEncEncodeOneUnit(VIDEO_BUFFERHEADER_TYPE_T *prBufferHeader)
{
    VIDEO_ENCODER_CODEC_ERROR_T eRet = VIDEO_ENCODER_CODEC_ERROR_NONE;
//    kal_uint8* pu1Buffer;
    kal_uint8* pu1StartAddr;
    kal_uint8* pu1EndAddr;
    kal_uint8* pu1WritePtr;
    kal_uint8* pu1ReadAddr;
    kal_uint8* pu1NextWritePtr;
    kal_uint32 u4AvailLen, u4BuffLen;
    kal_uint32 u4NextAvailLen;
    kal_uint8* pu1Addr;

    ASSERT(rpMPEG4HWEncDriver);

    if(prBufferHeader)
        video_dbg_trace(VIDEO_DBG_OWNER_ENCODER, VIDEO_DBG_HWENCV2_ENCODEONEUNIT, (kal_uint32) prBufferHeader->pu1Buffer);

    if(!prBufferHeader && !rMPEG4HWEncCtrl.pu1YUV)
        return VIDEO_ENCODER_CODEC_ERROR_NONE;

    if(!mpeg4_encore_check_encoder_status() ||
       !mepg4_encore_check_bits_buffer_status())
    {
        //return VIDEO_ENCODER_CODEC_PAUSE_ENCODE; //hw in use
        ASSERT(0);
    }

    VideoEncoderAllocateBitstreamBuffer(&pu1StartAddr, &pu1EndAddr, &pu1WritePtr, &pu1ReadAddr, &u4BuffLen);
    ASSERT(KAL_FALSE == VideoCommIsExtBufferCacheable((kal_uint32)pu1StartAddr, ROUND_UP_TO_POWER_OF_TWO(u4BuffLen,CPU_CACHE_LINE_SIZE)));

    if ((kal_uint32)pu1ReadAddr <= (kal_uint32)pu1WritePtr)
    {
        u4AvailLen = (kal_uint32)pu1EndAddr - (kal_uint32)pu1WritePtr;
        pu1Addr = pu1EndAddr;
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
#endif
    }
    else  // (u4WP < u4RP)
    {
        u4AvailLen = (kal_uint32)pu1ReadAddr - (kal_uint32)pu1WritePtr;
        pu1Addr = pu1ReadAddr;
    }
    VideoEncoderQueryBitstreamNewWP((pu1WritePtr+u4AvailLen), &pu1NextWritePtr, &u4NextAvailLen);

    if( (rMPEG4HWEncCtrl.eScenario == VIDEO_ENCODER_SCENARIO_VT && u4AvailLen <ENC_MIN_BUF_SIZE_VT) ||
        (rMPEG4HWEncCtrl.eScenario == VIDEO_ENCODER_SCENARIO_ENCODER && u4AvailLen < ENC_MAX_VOP_SIZE) )
    {
        // next free buffer is not continuous
        if (pu1NextWritePtr != pu1WritePtr+1)
        {
            VideoEncoderUpdateBitstreamWP((pu1WritePtr+u4AvailLen), 0);
        }

        VideoEncoderAllocateBitstreamBuffer(&pu1StartAddr, &pu1EndAddr, &pu1WritePtr, &pu1ReadAddr, &u4BuffLen);
        if ((kal_uint32)pu1ReadAddr <= (kal_uint32)pu1WritePtr)
        {
            u4AvailLen = (kal_uint32)pu1EndAddr - (kal_uint32)pu1WritePtr;
            pu1Addr = pu1EndAddr;
        }
        else  // (u4WP < u4RP)
        {
            u4AvailLen = (kal_uint32)pu1ReadAddr - (kal_uint32)pu1WritePtr;
            pu1Addr = pu1ReadAddr;
        }

       if( (rMPEG4HWEncCtrl.eScenario == VIDEO_ENCODER_SCENARIO_VT && u4AvailLen <ENC_MIN_BUF_SIZE_VT) ||
           (rMPEG4HWEncCtrl.eScenario == VIDEO_ENCODER_SCENARIO_ENCODER && u4AvailLen < ENC_MAX_VOP_SIZE) )
       {
            MPEG4EncCallbackEncPause(pu1StartAddr);
            drv_trace1(TRACE_GROUP_10, MPEG4HWENC_ENCODE_BUF_NOT_ENOUGH, u4AvailLen);
            return VIDEO_ENCODER_CODEC_BS_BUFFER_NOT_ENOUGH;
       }
    }

    rMPEG4HWEncCtrl.pu1Buffer = prBufferHeader->pu1Buffer;
    rMPEG4HWEncCtrl.u8TimeStamp = prBufferHeader->u8TimeStamp;
    rMPEG4HWEncCtrl.pu1YUV = 0;

    drv_trace2(TRACE_GROUP_10, MPEG4HWENC_ENCODE, (kal_uint32)(rMPEG4HWEncCtrl.pu1Buffer), rMPEG4HWEncCtrl.u8TimeStamp);

    rpMPEG4HWEncDriver->encode( rMPEG4HWEncCtrl.pu1Buffer, rMPEG4HWEncCtrl.u8TimeStamp, pu1WritePtr, pu1Addr);

    return eRet;
}


VIDEO_ENCODER_CODEC_ERROR_T MPEG4HWEncDeInit(void)
{
    VIDEO_ENCODER_CODEC_ERROR_T eRet = VIDEO_ENCODER_CODEC_ERROR_NONE;

    _MPEG4HWEncControlDeInit();

    drv_trace0(TRACE_GROUP_10, MPEG4HWENC_DEINIT);

    return eRet;
}


VIDEO_ENCODER_CODEC_ERROR_T MPEG4HWEncClose(void)
{
    VIDEO_ENCODER_CODEC_ERROR_T eRet = VIDEO_ENCODER_CODEC_ERROR_NONE;
    MPEG4_ENCORE_MEM_INFO *rMPEG4Mem = &rMPEG4HWEncCtrl.rMPEG4Mem;

    ASSERT(rpMPEG4HWEncDriver);

    rpMPEG4HWEncDriver->close();

    VideoEncoderFreeAligned(rMPEG4Mem->ext_mem_addr);
    VideoEncoderFreeAligned(rMPEG4Mem->res_mem_addr);

    drv_trace0(TRACE_GROUP_10, MPEG4HWENC_CLOSE);

    return eRet;
}


VIDEO_ENCODER_CODEC_ERROR_T
MPEG4HWEncGetNextBitstream(kal_uint8 **ppu1BitstreamAddr, VIDEO_ENCODER_PRIVATE_OUTPUT_T *prPrivateOutput)
{
    VIDEO_ENCODER_CODEC_ERROR_T eRet = VIDEO_ENCODER_CODEC_ERROR_NONE;
    MPEG4_ENCORE_FRAME_INFO* eFrameInfo = mpeg4_encore_get_frame_info();

    if(eFrameInfo->took_away)
    {
        *ppu1BitstreamAddr = NULL;
        prPrivateOutput->u4BitstreamLength = 0;
        drv_trace1(TRACE_GROUP_10, MPEG4HW_GET_BITS_NONE, __LINE__);
        return eRet;
    }

    if(eFrameInfo->drop)
    {
        *ppu1BitstreamAddr = NULL;
        prPrivateOutput->u4BitstreamLength = 0;
        prPrivateOutput->fgEndOfFrame = KAL_TRUE;
        prPrivateOutput->eFrameType = VIDEO_CODEC_FRM_DROPPED;
        eFrameInfo->took_away = KAL_TRUE;
        drv_trace1(TRACE_GROUP_10, MPEG4HW_GET_BITS_NONE, __LINE__);
        return eRet;
    }

    switch(eFrameInfo->bits_type)
    {
        case MPEG4_ENCORE_I_VOP:
            prPrivateOutput->eFrameType = VIDEO_CODEC_FRAMETYPE_I;
            break;

        case MPEG4_ENCORE_P_VOP:
            prPrivateOutput->eFrameType = VIDEO_CODEC_FRAMETYPE_P;
            break;

        case MPEG4_ENCORE_B_VOP:
            prPrivateOutput->eFrameType = VIDEO_CODEC_FRAMETYPE_B;
            break;

        case MPEG4_ENCORE_HEADER:
            prPrivateOutput->eFrameType = VIDEO_CODEC_HEADER;

            *ppu1BitstreamAddr = eFrameInfo->start_ptr;
            prPrivateOutput->u4BitstreamLength = eFrameInfo->total_len;
            prPrivateOutput->fgEndOfFrame = KAL_FALSE;

            eFrameInfo->took_away = KAL_TRUE;

#ifdef __VE_VIDEO_VT_SUPPORT__
            if (rMPEG4HWEncCtrl.eScenario != VIDEO_ENCODER_SCENARIO_VT)
            {
            return VIDEO_ENCODER_CODEC_ERROR_NONE;
            }
#endif
            break;

        default:
            ASSERT(0);
    }

    if (rMPEG4HWEncCtrl.eScenario == VIDEO_ENCODER_SCENARIO_ENCODER)
    {
        *ppu1BitstreamAddr = (kal_uint8*) (eFrameInfo->pkt_info[eFrameInfo->took_idx].u4Addr);
        prPrivateOutput->u4BitstreamLength = eFrameInfo->pkt_info[eFrameInfo->took_idx].u4Size;
        eFrameInfo->took_idx++;

        drv_trace4(TRACE_GROUP_10, MPEG4HW_GET_BITS, eFrameInfo->took_idx, (kal_uint32)*ppu1BitstreamAddr, prPrivateOutput->u4BitstreamLength, 0);

        if(eFrameInfo->took_idx == eFrameInfo->pkt_num)
        {
            eFrameInfo->took_away = KAL_TRUE;
            prPrivateOutput->fgEndOfFrame = KAL_TRUE;
        }
    }

    #ifdef __VE_VIDEO_VT_SUPPORT__
    else if (rMPEG4HWEncCtrl.eScenario == VIDEO_ENCODER_SCENARIO_VT)
    {
        VIDEO_ENCODER_PACKET_INFO_T *parPktInfo;
        kal_int32  i4Fcode;
        kal_uint32 u4Idx, u4BitsIdx, u4PktNum, u4TotalLen, u4MaxPktSize;
        kal_uint8* pu1Addr, *pu1LastAddr;

        parPktInfo = prPrivateOutput->prChassis->parPktInfo;
        ASSERT(parPktInfo);
        u4MaxPktSize = rMPEG4HWEncCtrl.u4MaxPktSize;
        i4Fcode = eFrameInfo->fcode;

        *ppu1BitstreamAddr = pu1Addr = eFrameInfo->start_ptr;
        prPrivateOutput->u4BitstreamLength = u4TotalLen = eFrameInfo->total_len;

        switch(rMPEG4HWEncCtrl.eCodecType)
        {
        case ENCODER_CODEC_TYPE_H263:
            u4PktNum = u4TotalLen/u4MaxPktSize;
            u4PktNum = (u4TotalLen%u4MaxPktSize) ? (u4PktNum+1) : (u4PktNum);
            ASSERT(u4PktNum<=VIDEO_ENCODER_MAX_PKTS_IN_A_CHASSIS);
            prPrivateOutput->prChassis->u4NumOfPkts = u4PktNum;

            for(u4Idx=0; u4Idx<u4PktNum; u4Idx++)
            {
                parPktInfo[u4Idx].u4Addr = (kal_uint32) (pu1Addr+u4MaxPktSize*u4Idx);
                parPktInfo[u4Idx].u4Size = (kal_uint32) (u4MaxPktSize);
            }
        	break;

        case ENCODER_CODEC_TYPE_MPEG4:

            pu1LastAddr = pu1Addr;
            u4Idx = 0;
            parPktInfo[u4Idx].u4Addr = (kal_uint32)pu1Addr;

            for(u4BitsIdx=0; u4BitsIdx<u4TotalLen && u4Idx < VIDEO_ENCODER_MAX_PKTS_IN_A_CHASSIS; u4BitsIdx++)
            {
                if((pu1Addr[u4BitsIdx] == 0x0) && (pu1Addr[u4BitsIdx+1] == 0x0) && ((pu1Addr[u4BitsIdx+2] >>(8-i4Fcode)) !=0))
                {
                    parPktInfo[u4Idx+1].u4Addr = (kal_uint32)(pu1Addr+u4BitsIdx);
                    parPktInfo[u4Idx].u4Size   = (kal_uint32)(pu1Addr+u4BitsIdx-pu1LastAddr);
                    pu1LastAddr = pu1Addr+u4BitsIdx;
                    u4Idx++;
                }
            }

            parPktInfo[u4Idx].u4Size = (kal_uint32)(pu1Addr+u4TotalLen-pu1LastAddr);
            prPrivateOutput->prChassis->u4NumOfPkts = u4Idx+1;

            break;

        default:
            ASSERT(0);
            break;
        }

        eFrameInfo->took_away = KAL_TRUE;
        if(eFrameInfo->bits_type != MPEG4_ENCORE_HEADER)
        {
            prPrivateOutput->fgEndOfFrame = KAL_TRUE;
        }
    }
    #endif

    return eRet;
}


const VIDEO_ENCODER_CODEC_API_T rMPEG4HWEncAdapt =
{
    MPEG4HWEncOpen,
    MPEG4HWEncInit,
    MPEG4HWEncGetParameter,
    MPEG4HWEncSetParameter,
    MPEG4HWEncGenerateHeader,
    MPEG4HWEncEncodeOneUnit,
    MPEG4HWEncDeInit,
    MPEG4HWEncClose,
    MPEG4HWEncGetNextBitstream
};

//extern kal_uint16 L1_ASSERT_BYPASS;

VIDEO_ENCODER_CODEC_API_T* GetMPEG4HWEncAdapt(VIDEO_ENCODER_SCENARIO_T eScenario)
{
    // init control variables
    rMPEG4HWEncCtrl.eScenario  = eScenario;
    rMPEG4HWEncCtrl.eQuality   = VIDEO_ENCODER_QUALITY_NONE;
    rMPEG4HWEncCtrl.eCodecType = ENCODER_CODEC_TYPE_NONE;
    rMPEG4HWEncCtrl.u4MaxPktSize = 0;
    rMPEG4HWEncCtrl.u4FrameRate = 0;
    rMPEG4HWEncCtrl.u4GenHeaderFrameRate = 0;

//    L1_ASSERT_BYPASS = 0x3;

    return (VIDEO_ENCODER_CODEC_API_T*)&rMPEG4HWEncAdapt;
}


kal_bool MPEG4HWGenStreamHeader(
    kal_uint8* pu1Buffer,
    kal_uint32 u4BufferSize,
    kal_uint32 u4TimeIncrResolution,
    kal_uint32* pu4EncodedSize
    )
{
    MP4HwEncVT_VOS_PAR  rVOSSetting;
    kal_uint32  u4VOSSize = 0;
    kal_bool rRet;

    rVOSSetting.vop_time_increment_resolution = u4TimeIncrResolution;
    rVOSSetting.width = 176;
    rVOSSetting.height = 144;

    rRet = mpeg4_encore_gen_vos_VT(pu1Buffer, u4BufferSize, &rVOSSetting, &u4VOSSize);
    *pu4EncodedSize = u4VOSSize;

    return rRet;
}


#endif /* __VE_MPEG4_ENC_HW_SUPPORT__ */
#endif /* __VE_VIDEO_ARCHI_V2__ */
