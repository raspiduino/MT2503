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
*   val.c
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
*****************************************************************************/


#include "drv_features_video.h"
#if defined(__VE_AVI_ENC_SUPPORT__)

#include "val_if.h"         // Public interface of VAL
/*****************************************************************************
* For linking with "hal/peripheral/src/drv_comm.c".
*****************************************************************************/
VAL_ERROR_T VAL_Init(void)
{
    return VAL_ERR_NONE;
}

#else

#include "val.h"            // Internal data structure in VAL
#include "val_player.h"     // Internal data structure in VAL PLAYER
#include "val_recorder.h"   // Internal data structure in VAL RECORDER
#include "val_clipper.h"    // Internal data structure in VAL VIDEO CLIPPER
//#include "val_vt.h"         // Internal data structure in VAL VT
#include "val_if.h"         // Public interface of VAL
#include "kal_general_types.h"                  // for kal_uint32
#include "stack_config.h"
#include "kal_public_api.h"
#include "drv_features.h"
#include "drv_comm.h"                       // for drv_trace0(), drv_trace1()
#include "vcodec_v2_trc.h"


// The header files above are needed for the "#else" block below.
#ifdef __VE_VIDEO_ARCHI_V2__


/*****************************************************************************
* Global variable(s)
*****************************************************************************/
static VAL_MANAGER_T _rValMgr;


/*****************************************************************************
* Return TRUE if it is necessary to check VAL state. It is the default behavior.
* Otherwise, return FALSE.
*
*****************************************************************************/
static kal_bool _val_CheckState(VAL_SCENARIO_T eScenario, kal_uint32 u4Operation)
{
    kal_bool fgRet = KAL_TRUE;

#if defined(__VE_MPEG4_ENC_SUPPORT__) || defined(__VE_H264_ENC_SW_SUPPORT__)
    if (eScenario == VAL_SCENARIO_RECORDER)
    {
        switch (u4Operation)
        {
        case VAL_RECORDER_OP_SET_AUDIO_FORMAT:
        // case VAL_RECORDER_OP_GET_CURRENT_TIME:
        // case VAL_RECORDER_OP_GET_CURRENT_TIME_STAMP:  // Not used any more! [MAUI_02976426]
        case VAL_RECORDER_OP_DO_VIDEO_AND_META_FILES_EXIST:
            fgRet = KAL_FALSE;
            break;
        }
    }
#endif  // defined(__VE_MPEG4_ENC_SUPPORT__) || defined(__VE_H264_ENC_SW_SUPPORT__)

    return fgRet;
}


/*****************************************************************************
*
*****************************************************************************/
VAL_ERROR_T VAL_Init(void)
{
    if (_rValMgr.eState != VAL_STATE_DEINIT)
    {
        kal_uint32 u4OpenedScenarios = VAL_SCENARIO_GET_OPENED_SCENARIOS(_rValMgr.rOpenedScenarios);
        drv_trace2(TRACE_GROUP_10, VAL_INIT_TWICE, _rValMgr.eState, u4OpenedScenarios);
        return VAL_ERR_ALREADY_INITED;
    }

    kal_mem_set(&_rValMgr, 0, sizeof(_rValMgr));
    // To do: Set variables in _rValMgr here.
    // _rValMgr.rOpenedScenarios.u1Player = 0;
    // _rValMgr.rOpenedScenarios.u1Recorder = 0;
    // _rValMgr.rOpenedScenarios.u1Clipper = 0;
    // _rValMgr.rOpenedScenarios.u1VT = 0;

    drv_trace0(TRACE_GROUP_10, VAL_INIT_DONE);
    _rValMgr.eState = VAL_STATE_INIT;

    return VAL_ERR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
VAL_ERROR_T VAL_DeInit(void)
{
    if (_rValMgr.eState != VAL_STATE_CLOSE)
    {
        // All scenarios need to be closed before VAL manager can enter the CLOSE state.
        kal_uint32 u4OpenedScenarios = VAL_SCENARIO_GET_OPENED_SCENARIOS(_rValMgr.rOpenedScenarios);
        drv_trace2(TRACE_GROUP_10, VAL_DEINIT_NOT_CLOSED, _rValMgr.eState, u4OpenedScenarios);
        return VAL_ERR_NOT_CLOSED;
    }

    // To do: Clear variables related to memory management.
    // Do not clear variables unless they are used in memory management.

    drv_trace0(TRACE_GROUP_10, VAL_DEINIT_DONE);
    _rValMgr.eState = VAL_STATE_DEINIT;

    return VAL_ERR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
VAL_ERROR_T VAL_Open(VAL_SCENARIO_T eScenario, void *pvInput,
        kal_uint32 u4InputLen)
{
    kal_uint32 u4OpenedScenarios = 0;
    VAL_ERROR_T eValError = VAL_ERR_NONE;

    drv_trace1(TRACE_GROUP_10, VAL_OPEN_BEGIN, eScenario);

    if ((_rValMgr.eState != VAL_STATE_INIT) && (_rValMgr.eState != VAL_STATE_CLOSE))
    {
        drv_trace1(TRACE_GROUP_10, VAL_OPEN_WRONG_STATE, _rValMgr.eState);
        return VAL_ERR_NOT_INITED;
    }

    switch (eScenario)
    {
    case VAL_SCENARIO_PLAYER:
        if (VAL_SCENARIO_PLAYER_IS_OPENED(_rValMgr.rOpenedScenarios))
        {
            u4OpenedScenarios = VAL_SCENARIO_GET_OPENED_SCENARIOS(_rValMgr.rOpenedScenarios);
            drv_trace1(TRACE_GROUP_10, VAL_OPEN_PLAYER_OPENED, u4OpenedScenarios);
            return VAL_ERR_PLAYER_ALREADY_OPENED;
        }
        eValError = VAL_PLAYER_Open(pvInput, u4InputLen);
        VAL_SCENARIO_OPEN_PLAYER(_rValMgr.rOpenedScenarios);
        break;

#if defined(__VE_MPEG4_ENC_SUPPORT__) || defined(__VE_H264_ENC_SW_SUPPORT__)
    case VAL_SCENARIO_RECORDER:
        if (VAL_SCENARIO_RECORDER_IS_OPENED(_rValMgr.rOpenedScenarios))
        {
            u4OpenedScenarios = VAL_SCENARIO_GET_OPENED_SCENARIOS(_rValMgr.rOpenedScenarios);
            drv_trace1(TRACE_GROUP_10, VAL_OPEN_RECORDER_OPENED, u4OpenedScenarios);
            return VAL_ERR_RECORDER_ALREADY_OPENED;
        }
        eValError = VAL_RECORDER_Open(pvInput, u4InputLen);
        VAL_SCENARIO_OPEN_RECORDER(_rValMgr.rOpenedScenarios);
        break;
#endif  // defined(__VE_MPEG4_ENC_SUPPORT__) || defined(__VE_H264_ENC_SW_SUPPORT__)

    case VAL_SCENARIO_VIDEO_CLIPPER:
        if (VAL_SCENARIO_CLIPPER_IS_OPENED(_rValMgr.rOpenedScenarios))
        {
            u4OpenedScenarios = VAL_SCENARIO_GET_OPENED_SCENARIOS(_rValMgr.rOpenedScenarios);
            drv_trace1(TRACE_GROUP_10, VAL_OPEN_CLIPPER_OPENED, u4OpenedScenarios);
            return VAL_ERR_CLIPPER_ALREADY_OPENED;
        }
        eValError = VAL_CLIPPER_Open(pvInput, u4InputLen);
        VAL_SCENARIO_OPEN_CLIPPER(_rValMgr.rOpenedScenarios);
        break;

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
#endif  // __VE_VIDEO_VT_SUPPORT__

    default:
        drv_trace1(TRACE_GROUP_10, VAL_OPEN_INVALID_SCENARIO, eScenario);
        eValError = VAL_ERR_INVALID_PARAMETER;
        ASSERT(0);
        break;
    }

    drv_trace0(TRACE_GROUP_10, VAL_OPEN_CHANGE_STAGE);
    _rValMgr.eState = VAL_STATE_OPEN;

    drv_trace0(TRACE_GROUP_10, VAL_OPEN_DONE);

    return eValError;
}


/*****************************************************************************
*
*****************************************************************************/
VAL_ERROR_T VAL_Ctrl(VAL_SCENARIO_T eScenario, kal_uint32 u4Operation,
        void *pvInput, kal_uint32 u4InputLen, void *pvOutput,
        kal_uint32 u4OutputLen, kal_uint32 *pu4RealOutputLen)
{
    kal_uint32 u4OpenedScenarios = 0;
    VAL_ERROR_T eValError = VAL_ERR_NONE;
    kal_bool fgCheckState;

    drv_trace1(TRACE_GROUP_10, VAL_CTRL_BEGIN, eScenario);

    fgCheckState = _val_CheckState(eScenario, u4Operation);
    if (fgCheckState)
    {
        if (_rValMgr.eState != VAL_STATE_OPEN)
        {
            drv_trace1(TRACE_GROUP_10, VAL_CTRL_WRONG_STATE, _rValMgr.eState);
            return VAL_ERR_NOT_OPENED;
        }
    }

    switch (eScenario)
    {
    case VAL_SCENARIO_PLAYER:
        if (fgCheckState && VAL_SCENARIO_PLAYER_IS_NOT_OPENED(_rValMgr.rOpenedScenarios))
        {
            u4OpenedScenarios = VAL_SCENARIO_GET_OPENED_SCENARIOS(_rValMgr.rOpenedScenarios);
            drv_trace1(TRACE_GROUP_10, VAL_CTRL_PLAYER_NOT_OPENED, u4OpenedScenarios);
            return VAL_ERR_PLAYER_NOT_OPENED;
        }
        if (u4Operation > VAL_PLAYER_OP_MAX)
        {
            drv_trace1(TRACE_GROUP_10, VAL_CTRL_PLAYER_UNKNOWN_OP, u4Operation);
            return VAL_ERR_INVALID_PARAMETER;
        }
        eValError = VAL_PLAYER_Ctrl(u4Operation, pvInput, u4InputLen, pvOutput, u4OutputLen, pu4RealOutputLen);
        break;

#if defined(__VE_MPEG4_ENC_SUPPORT__) || defined(__VE_H264_ENC_SW_SUPPORT__)
    case VAL_SCENARIO_RECORDER:
        if (fgCheckState && VAL_SCENARIO_RECORDER_IS_NOT_OPENED(_rValMgr.rOpenedScenarios))
        {
            u4OpenedScenarios = VAL_SCENARIO_GET_OPENED_SCENARIOS(_rValMgr.rOpenedScenarios);
            drv_trace1(TRACE_GROUP_10, VAL_CTRL_RECORDER_NOT_OPENED, u4OpenedScenarios);
            return VAL_ERR_RECORDER_NOT_OPENED;
        }
        if (u4Operation > VAL_RECORDER_OP_MAX)
        {
            drv_trace1(TRACE_GROUP_10, VAL_CTRL_RECORDER_UNKNOWN_OP, u4Operation);
            return VAL_ERR_INVALID_PARAMETER;
        }
        eValError = VAL_RECORDER_Ctrl(u4Operation, pvInput, u4InputLen, pvOutput, u4OutputLen, pu4RealOutputLen);
        break;
#endif  // defined(__VE_MPEG4_ENC_SUPPORT__) || defined(__VE_H264_ENC_SW_SUPPORT__)

    case VAL_SCENARIO_VIDEO_CLIPPER:
        if (fgCheckState && VAL_SCENARIO_CLIPPER_IS_NOT_OPENED(_rValMgr.rOpenedScenarios))
        {
            u4OpenedScenarios = VAL_SCENARIO_GET_OPENED_SCENARIOS(_rValMgr.rOpenedScenarios);
            drv_trace1(TRACE_GROUP_10, VAL_CTRL_CLIPPER_NOT_OPENED, u4OpenedScenarios);
            return VAL_ERR_CLIPPER_NOT_OPENED;
        }
        if (u4Operation > VAL_CLIPPER_OP_MAX)
        {
            drv_trace1(TRACE_GROUP_10, VAL_CTRL_CLIPPER_UNKNOWN_OP, u4Operation);
            return VAL_ERR_INVALID_PARAMETER;
        }
        eValError = VAL_CLIPPER_Ctrl(u4Operation, pvInput, u4InputLen, pvOutput, u4OutputLen, pu4RealOutputLen);
        break;

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
#endif  // __VE_VIDEO_VT_SUPPORT__

    default:
        drv_trace1(TRACE_GROUP_10, VAL_CTRL_INVALID_SCENARIO, eScenario);
        eValError = VAL_ERR_INVALID_PARAMETER;
        ASSERT(0);
        break;
    }

    drv_trace0(TRACE_GROUP_10, VAL_CTRL_DONE);

    return eValError;
}


/*****************************************************************************
*
*****************************************************************************/
VAL_ERROR_T VAL_Close(VAL_SCENARIO_T eScenario, void *pvInput,
        kal_uint32 u4InputLen)
{
    kal_uint32 u4OpenedScenarios = 0;
    VAL_ERROR_T eValError = VAL_ERR_NONE;

    drv_trace1(TRACE_GROUP_10, VAL_CLOSE_BEGIN, eScenario);

    if (_rValMgr.eState != VAL_STATE_OPEN)
    {
        drv_trace1(TRACE_GROUP_10, VAL_CLOSE_WRONG_STATE, _rValMgr.eState);
        return VAL_ERR_NOT_OPENED;
    }

    switch (eScenario)
    {
    case VAL_SCENARIO_PLAYER:
        if (VAL_SCENARIO_PLAYER_IS_NOT_OPENED(_rValMgr.rOpenedScenarios))
        {
            u4OpenedScenarios = VAL_SCENARIO_GET_OPENED_SCENARIOS(_rValMgr.rOpenedScenarios);
            drv_trace1(TRACE_GROUP_10, VAL_CLOSE_PLAYER_NOT_OPENED, u4OpenedScenarios);
            return VAL_ERR_PLAYER_NOT_OPENED;
        }
        eValError = VAL_PLAYER_Close(pvInput, u4InputLen);
        VAL_SCENARIO_CLOSE_PLAYER(_rValMgr.rOpenedScenarios);
        break;

#if defined(__VE_MPEG4_ENC_SUPPORT__) || defined(__VE_H264_ENC_SW_SUPPORT__)
    case VAL_SCENARIO_RECORDER:
        if (VAL_SCENARIO_RECORDER_IS_NOT_OPENED(_rValMgr.rOpenedScenarios))
        {
            u4OpenedScenarios = VAL_SCENARIO_GET_OPENED_SCENARIOS(_rValMgr.rOpenedScenarios);
            drv_trace1(TRACE_GROUP_10, VAL_CLOSE_RECORDER_NOT_OPENED, u4OpenedScenarios);
            return VAL_ERR_RECORDER_NOT_OPENED;
        }
        eValError = VAL_RECORDER_Close(pvInput, u4InputLen);
        VAL_SCENARIO_CLOSE_RECORDER(_rValMgr.rOpenedScenarios);
        break;
#endif  // defined(__VE_MPEG4_ENC_SUPPORT__) || defined(__VE_H264_ENC_SW_SUPPORT__)

    case VAL_SCENARIO_VIDEO_CLIPPER:
        if (VAL_SCENARIO_CLIPPER_IS_NOT_OPENED(_rValMgr.rOpenedScenarios))
        {
            u4OpenedScenarios = VAL_SCENARIO_GET_OPENED_SCENARIOS(_rValMgr.rOpenedScenarios);
            drv_trace1(TRACE_GROUP_10, VAL_CLOSE_CLIPPER_NOT_OPENED, u4OpenedScenarios);
            return VAL_ERR_CLIPPER_NOT_OPENED;
        }
        eValError = VAL_CLIPPER_Close(pvInput, u4InputLen);
        VAL_SCENARIO_CLOSE_CLIPPER(_rValMgr.rOpenedScenarios);
        break;

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
#endif  // __VE_VIDEO_VT_SUPPORT__

    default:
        drv_trace1(TRACE_GROUP_10, VAL_CLOSE_INVALID_SCENARIO, eScenario);
        eValError = VAL_ERR_INVALID_PARAMETER;
        ASSERT(0);
        break;
    }

    if (VAL_SCENARIO_NONE_IS_OPENED(_rValMgr.rOpenedScenarios))
    {
        drv_trace0(TRACE_GROUP_10, VAL_CLOSE_DONE);
        _rValMgr.eState = VAL_STATE_CLOSE;
    }

    u4OpenedScenarios = VAL_SCENARIO_GET_OPENED_SCENARIOS(_rValMgr.rOpenedScenarios);
    drv_trace1(TRACE_GROUP_10, VAL_CLOSE_SCENARIOS_STILL_OPEN, u4OpenedScenarios);

    return eValError;
}


#else

#include "val_if.h"         // Public interface of VAL
#include "kal_public_api.h"


/*****************************************************************************
*
*****************************************************************************/
VAL_ERROR_T VAL_Init(void)
{
    return VAL_ERR_NO_V2_ARCHITECTURE;
}


/*****************************************************************************
*
*****************************************************************************/
VAL_ERROR_T VAL_DeInit(void)
{
    return VAL_ERR_NO_V2_ARCHITECTURE;
}


/*****************************************************************************
*
*****************************************************************************/
VAL_ERROR_T VAL_Open(VAL_SCENARIO_T eScenario, void *pvInput,
        kal_uint32 u4InputLen)
{
    return VAL_ERR_NO_V2_ARCHITECTURE;
}


/*****************************************************************************
*
*****************************************************************************/
VAL_ERROR_T VAL_Ctrl(VAL_SCENARIO_T eScenario, kal_uint32 u4Operation,
        void *pvInput, kal_uint32 u4InputLen, void *pvOutput,
        kal_uint32 u4OutputLen, kal_uint32 *pu4RealOutputLen)
{
    return VAL_ERR_NO_V2_ARCHITECTURE;
}


/*****************************************************************************
*
*****************************************************************************/
VAL_ERROR_T VAL_Close(VAL_SCENARIO_T eScenario, void *pvInput,
        kal_uint32 u4InputLen)
{
    return VAL_ERR_NO_V2_ARCHITECTURE;
}


#endif  // __VE_VIDEO_ARCHI_V2__
#endif  // defined(__VE_AVI_ENC_SUPPORT__)

