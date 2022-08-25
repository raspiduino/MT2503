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
 *   video_encoder_component.c
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

#ifdef __VE_VIDEO_COMMON__

#include "video_types_v2.h"
#include "video_buffer_management_v2.h"
#include "video_comm_component_v2.h"
#include "kal_general_types.h"
#include "kal_public_api.h"

#ifdef __VE_MM_DCM_SUPPORT__
#include "dcmgr.h" //DCM

#pragma arm section code = "DYNAMIC_CODE_VECOM_ROCODE", rodata = "DYNAMIC_CODE_VECOM_RODATA"
#endif

static kal_bool _VideoCommSetupPortBuffer(
    VIDEO_EXTMEM_HANDLER_T* prExtMemHdlr,
    VIDEO_PORT_BUFFER_T* prPortBuffer,
    VIDEO_PORT_CONFIG_T* prConfig)
{
    prPortBuffer->ePortType = prConfig->ePortType;
    prPortBuffer->fgSupplier = prConfig->fgSupplier;
    prPortBuffer->u4BuffSize = prConfig->u4BuffSize;
    if (prConfig->u4BuffSize != 0)
    {
        prPortBuffer->pu1Buff = (kal_uint8*)VideoGetExtBuffer(prExtMemHdlr, prConfig->u4BuffSize);
        if (0 == prPortBuffer->pu1Buff)
        {
            return KAL_FALSE;
        }
    }
    return KAL_TRUE;
}

static kal_bool _VideoCommSetupCommBuffQ(
    VIDEO_EXTMEM_HANDLER_T* prExtMemHdlr,
    VIDEO_COMM_BUFF_QUEUE_T* prQueue,
    kal_uint32 u4Size)
{
    if (u4Size > 0)
    {
        prQueue->prBuffQ
            = (VIDEO_BUFFERHEADER_TYPE_T*)VideoGetExtBuffer(prExtMemHdlr, sizeof(VIDEO_BUFFERHEADER_TYPE_T)*u4Size);
        if (0 == prQueue->prBuffQ)
        {
            return KAL_FALSE;
        }
    }
    else
    {
        prQueue->prBuffQ = NULL;
    }
    prQueue->u4ReadIdx  = 0;
    prQueue->u4WriteIdx = 0;
    prQueue->u4UsedNum  = 0;
    prQueue->u4TotalNum = u4Size;

    return KAL_TRUE;

}

VIDEO_ERROR_TYPE_T VideoCommConfigPorts(
    VIDEO_COMM_STATE_T *prCommState,
    VIDEO_COMPONENT_INIT_PORT_T* prParam)
{
    VIDEO_PORT_BUFFER_T* prPortBuffer = NULL;
    VIDEO_COMM_BUFF_QUEUE_T* prBufferQ = NULL;

    if (VIDEO_PORT_INPUT == prParam->ePort)
    {
        prPortBuffer = &prCommState->rInputBuff[prParam->u4PortIndex];
        prBufferQ = &prCommState->rInputBuffQ[prParam->u4PortIndex];
    }
    else if (VIDEO_PORT_OUTPUT == prParam->ePort)
    {
        prPortBuffer = &prCommState->rOutputBuff[prParam->u4PortIndex];
        prBufferQ = &prCommState->rOutputBuffQ[prParam->u4PortIndex];
    }
    else
    {
        ASSERT(0);
    }

    if (KAL_FALSE == _VideoCommSetupPortBuffer(prParam->prExtMemHdlr, prPortBuffer, &prParam->rConfig))
    {
        return VIDEO_ERROR_INIT_ERROR;
    }

    if (KAL_FALSE == _VideoCommSetupCommBuffQ(prParam->prExtMemHdlr, prBufferQ, prParam->u4BuffQSize))
    {
        return VIDEO_ERROR_INIT_ERROR;
    }

    return VIDEO_ERROR_NONE;
}

/* Init component with port configuration*/
VIDEO_ERROR_TYPE_T VideoCommInit(VIDEO_COMM_STATE_T *prCommState,
        VIDEO_COMPONENT_INIT_T *prConfig, kal_char *pcMutexName)
{
    VIDEO_PORT_CONFIG_T *prInput1 = prConfig->prInputPort1;
    VIDEO_PORT_CONFIG_T *prInput2 = prConfig->prInputPort2;
    VIDEO_PORT_CONFIG_T *prOutput1 = prConfig->prOutputPort1;
    VIDEO_PORT_CONFIG_T *prOutput2 = prConfig->prOutputPort2;
    kal_uint32 u4Size;

    if (prCommState->eState != VIDEO_STATE_CLOSE)
    {
        return VIDEO_ERROR_INIT_ERROR;
    }

    if (NULL == prConfig->eMutex)
    {
        ASSERT(0);
    }
    else
    {
        prCommState->eMutex = prConfig->eMutex;
    }

    /* input port 1*/
    if (prInput1 != NULL)
    {
        if (KAL_FALSE == _VideoCommSetupPortBuffer(prConfig->prExtMemHdlr, &prCommState->rInputBuff[0], prInput1))
        {
            goto VIDEO_COMM_INIT_FAILED;
        }

        if (KAL_FALSE == _VideoCommSetupCommBuffQ(prConfig->prExtMemHdlr, &prCommState->rInputBuffQ[0], prConfig->u4InputBuffQSize))
        {
            goto VIDEO_COMM_INIT_FAILED;
        }
    }

    /* input port 2*/
    if (prInput2 != NULL)
    {
        if (KAL_FALSE == _VideoCommSetupPortBuffer(prConfig->prExtMemHdlr, &prCommState->rInputBuff[1], prInput2))
        {
            goto VIDEO_COMM_INIT_FAILED;
        }

        if (KAL_FALSE == _VideoCommSetupCommBuffQ(prConfig->prExtMemHdlr, &prCommState->rInputBuffQ[1], prConfig->u4InputBuffQSize2))
        {
            goto VIDEO_COMM_INIT_FAILED;
        }
    }

    /* output port 1*/
    if (prOutput1 != NULL)
    {
        if (KAL_FALSE == _VideoCommSetupPortBuffer(prConfig->prExtMemHdlr, &prCommState->rOutputBuff[0], prOutput1))
        {
            goto VIDEO_COMM_INIT_FAILED;
        }

        if (KAL_FALSE == _VideoCommSetupCommBuffQ(prConfig->prExtMemHdlr, &prCommState->rOutputBuffQ[0], prConfig->u4OutputBuffQSize))
        {
            goto VIDEO_COMM_INIT_FAILED;
        }
    }

    /* output port 2*/
    if (prOutput2 != NULL)
    {
        if (KAL_FALSE == _VideoCommSetupPortBuffer(prConfig->prExtMemHdlr, &prCommState->rOutputBuff[1], prOutput2))
        {
            goto VIDEO_COMM_INIT_FAILED;
        }

        if (KAL_FALSE == _VideoCommSetupCommBuffQ(prConfig->prExtMemHdlr, &prCommState->rOutputBuffQ[1], prConfig->u4OutputBuffQSize2))
        {
            goto VIDEO_COMM_INIT_FAILED;
        }
    }

    //allocate cmd size
    u4Size = prConfig->u4CmdQSize;
    if (u4Size > 0)
    {
        prCommState->rCmdQ.prCmdQ = (VIDEO_COMM_CMD_PARAM_T*)VideoGetExtBuffer(prConfig->prExtMemHdlr, sizeof(VIDEO_COMM_CMD_PARAM_T)*u4Size);
        if (0 == prCommState->rCmdQ.prCmdQ)
        {
            goto VIDEO_COMM_INIT_FAILED;
        }
    }
    else
    {
        prCommState->rCmdQ.prCmdQ = NULL;
    }
    prCommState->rCmdQ.u4ReadIdx = 0;
    prCommState->rCmdQ.u4WriteIdx = 0;
    prCommState->rCmdQ.u4TotalNum = u4Size;

    prCommState->u4EntryCount = 0;
    prCommState->fgProcessing = KAL_FALSE;
    prCommState->fgCompClosing = KAL_FALSE;
    prCommState->eState = VIDEO_STATE_CLOSE;
    return VIDEO_ERROR_NONE;

VIDEO_COMM_INIT_FAILED:
    return VIDEO_ERROR_INIT_ERROR;
}

/* de-init component, parameters will be reset */
VIDEO_ERROR_TYPE_T VideoCommDeInit(VIDEO_COMM_STATE_T *prCommState)
{
    kal_uint32 u4Index;

    // If state is in RUN, it can't be transfer to CLOSE
    if((prCommState->eState != VIDEO_STATE_CLOSE))
    {
        return VIDEO_ERROR_DEINIT_ERROR;
    }

    // release all resource
    for(u4Index = 0; u4Index < VIDEO_PORT_MAX_NUM; u4Index++)
    {
        kal_mem_set(&prCommState->rInputComp[u4Index], 0, sizeof(VIDEO_COMPONENT_PARAM_T));
        kal_mem_set(&prCommState->rOutputComp[u4Index], 0, sizeof(VIDEO_COMPONENT_PARAM_T));
        kal_mem_set(&prCommState->rInputBuff[u4Index], 0, sizeof(VIDEO_PORT_BUFFER_T));
        kal_mem_set(&prCommState->rOutputBuff[u4Index], 0, sizeof(VIDEO_PORT_BUFFER_T));
    }
    prCommState->prCallback = NULL;

    //prCommState->eState = VIDEO_STATE_CLOSE;

    return VIDEO_ERROR_NONE;
}

/* change component state, callback will automaticlly called when state change
     if component change is invalid, it will assert */
VIDEO_ERROR_TYPE_T VideoCommChangeState(VIDEO_COMM_STATE_T *prCommState,
        VIDEO_STATE_TYPE_T eState)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VIDEO_CALLBACK_TYPE_T *prCallback = prCommState->prCallback;

    if (eState == VIDEO_STATE_INIT)
    {
        if (prCommState->eState != VIDEO_STATE_CLOSE)
        {
            ASSERT(0);
        }
    }
    else if (eState == VIDEO_STATE_IDLE)
    {
        if ((prCommState->eState != VIDEO_STATE_INIT) &&
            (prCommState->eState != VIDEO_STATE_IDLE) &&
            (prCommState->eState != VIDEO_STATE_STOP))
        {
            ASSERT(0);
        }
    }
    else if (eState == VIDEO_STATE_RUN)
    {
        if ((prCommState->eState != VIDEO_STATE_IDLE) &&
            (prCommState->eState != VIDEO_STATE_STOP))
        {
            ASSERT(0);
        }
    }
    else if (eState == VIDEO_STATE_STOP)
    {
        if ((prCommState->eState != VIDEO_STATE_IDLE) &&
            (prCommState->eState != VIDEO_STATE_RUN) &&
            (prCommState->eState != VIDEO_STATE_STOP))
        {
            ASSERT(0);
        }
    }
    else if (eState == VIDEO_STATE_CLOSE)
    {
        if ((prCommState->eState != VIDEO_STATE_IDLE) &&
            (prCommState->eState != VIDEO_STATE_INIT) &&
            (prCommState->eState != VIDEO_STATE_STOP) &&
            (prCommState->eState != VIDEO_STATE_CLOSE))
        {
            ASSERT(0);
        }
    }
    else
    {
        ASSERT(0);
    }

    prCommState->eState = eState;
    if (prCallback->pfnEventHandler != NULL)
    {
        eError = prCallback->pfnEventHandler(VIDEO_EVENT_COMPLETE, VIDEO_COMMAND_STATESET, eState, NULL);
    }
    else if (prCallback->pfnMIEventHandler != NULL)
    {
        eError = prCallback->pfnMIEventHandler(prCommState->pClient, VIDEO_EVENT_COMPLETE, VIDEO_COMMAND_STATESET, eState, NULL);
    }
    else
    {
        ASSERT(0);
    }

    if (eError != VIDEO_ERROR_NONE)
    {
        ASSERT(0);
    }

    return VIDEO_ERROR_NONE;
}

VIDEO_ERROR_TYPE_T VideoCommSetCallbacks(VIDEO_COMM_STATE_T *prCommState,
        VIDEO_CALLBACK_TYPE_T *prCallback)
{
    prCommState->prCallback = prCallback;
    return VIDEO_ERROR_NONE;
}

VIDEO_ERROR_TYPE_T VideoMICommSetClient(VIDEO_COMM_STATE_T *prCommState, void *pClient)
{
    prCommState->pClient = pClient;
    return VIDEO_ERROR_NONE;
}

static kal_bool _VideoCommCheckSupplier(
    VIDEO_PORT_BUFFER_T* prPortBuffer,
    VIDEO_PORT_TYPE_T ePortType,
    kal_uint32 *pu4PortIndex)
{
    kal_bool fgRet = KAL_FALSE;
    kal_uint32 u4Index;

    for(u4Index = 0; u4Index < VIDEO_PORT_MAX_NUM; u4Index++)
    {
        VIDEO_PORT_BUFFER_T* prTemp = prPortBuffer + u4Index;
        if(prTemp->ePortType == ePortType)
        {
            *pu4PortIndex = u4Index;
            if(prTemp->fgSupplier == KAL_TRUE)
            {
                fgRet = KAL_TRUE;
            }
            break;
        }
    }

    if(u4Index == VIDEO_PORT_MAX_NUM)
    {
        ASSERT(0);
    }

    return fgRet;

}

/******************************************************************************
* This function searches the input ports for the port with the specified
* port type "ePortType".  If such a port is found, its port index is set to
* the input arguemtn "*pu4PortIndex".
*
* Return value:
*   TRUE        if the port is a buffer supplier
*   FALSE       if the port is not a buffer supplier or the port with the
*               specified port type cannot be found
******************************************************************************/
static kal_bool VideoCommCheckInputSupplier(VIDEO_COMM_STATE_T *prCommState,
        VIDEO_PORT_TYPE_T ePortType, kal_uint32 *pu4PortIndex)
{
    return _VideoCommCheckSupplier(&prCommState->rInputBuff[0], ePortType, pu4PortIndex);
}

/******************************************************************************
* This function searches the output ports for the port with the specified
* port type "ePortType".  If such a port is found, its port index is set to
* the input arguemtn "*pu4PortIndex".
*
* Return value:
*   TRUE        if the port is a buffer supplier
*   FALSE       if the port is not a buffer supplier or the port with the
*               specified port type cannot be found
******************************************************************************/
static kal_bool VideoCommCheckOutputSupplier(VIDEO_COMM_STATE_T *prCommState,
        VIDEO_PORT_TYPE_T ePortType, kal_uint32 *pu4PortIndex)
{
    return _VideoCommCheckSupplier(&prCommState->rOutputBuff[0], ePortType, pu4PortIndex);
}

static kal_uint8* _VideoCommGetBuffer(
    VIDEO_PORT_BUFFER_T* prPortBuffer,
    VIDEO_PORT_TYPE_T ePortType,
    kal_uint32 *pu4PortIndex)
{
    kal_uint8 *pu1Buff = NULL;
    kal_uint32 u4Index;

    for(u4Index = 0; u4Index < VIDEO_PORT_MAX_NUM; u4Index++)
    {
        VIDEO_PORT_BUFFER_T* prTmp = prPortBuffer + u4Index;
        if(prTmp->ePortType == ePortType)
        {
            *pu4PortIndex = u4Index;
            pu1Buff = prTmp->pu1Buff;
            break;
        }
    }

    if(u4Index == VIDEO_PORT_MAX_NUM)
    {
        ASSERT(0);
    }

    return pu1Buff;
}

/******************************************************************************
* Get the address of the input buffer as well as the port index of the port
* type ePortType.
******************************************************************************/
static kal_uint8* VideoCommGetInputBuff(VIDEO_COMM_STATE_T *prCommState,
        VIDEO_PORT_TYPE_T ePortType, kal_uint32 *pu4PortIndex)
{
    return _VideoCommGetBuffer(&prCommState->rInputBuff[0], ePortType, pu4PortIndex);
}

/******************************************************************************
* Get the address of the output buffer as well as the port index of the port
* type ePortType.
******************************************************************************/
kal_uint8* VideoCommGetOutputBuff(VIDEO_COMM_STATE_T *prCommState,
        VIDEO_PORT_TYPE_T ePortType, kal_uint32 *pu4PortIndex)
{
    return _VideoCommGetBuffer(&prCommState->rOutputBuff[0], ePortType, pu4PortIndex);
}

static kal_uint32 _VideoCommGetPortIndex(VIDEO_PORT_BUFFER_T* prPortBuffer, VIDEO_PORT_TYPE_T ePortType)
{
    kal_uint32 u4Index;
    kal_uint32 u4PortIndex = 0;

    for (u4Index = 0; u4Index < VIDEO_PORT_MAX_NUM; u4Index++)
    {
        VIDEO_PORT_BUFFER_T* prTmp = prPortBuffer + u4Index;
        if (prTmp->ePortType == ePortType)
        {
            u4PortIndex = u4Index;
            break;
        }
    }

    if (u4Index == VIDEO_PORT_MAX_NUM)
    {
        ASSERT(0);
    }

    return u4PortIndex;
}

VIDEO_PORT_TYPE_T VideoCommGetInputPortType(VIDEO_COMM_STATE_T *prCommState, kal_uint32 u4PortIndex)
{
    return prCommState->rInputBuff[u4PortIndex].ePortType;
}

VIDEO_PORT_TYPE_T VideoCommGetOutputPortType(VIDEO_COMM_STATE_T *prCommState, kal_uint32 u4PortIndex)
{
    return prCommState->rOutputBuff[u4PortIndex].ePortType;

}
/******************************************************************************
* Get the index of the input port with the type ePortType.
*
* Return value:
*           the port index on success
******************************************************************************/
kal_uint32 VideoCommGetInputPortIndex(VIDEO_COMM_STATE_T *prCommState,
        VIDEO_PORT_TYPE_T ePortType)
{
    return _VideoCommGetPortIndex(&prCommState->rInputBuff[0], ePortType);
}

/******************************************************************************
* Get the index of the output port with the type ePortType.
*
* Return value:
*           the port index on success
******************************************************************************/
kal_uint32 VideoCommGetOutputPortIndex(VIDEO_COMM_STATE_T *prCommState,
        VIDEO_PORT_TYPE_T ePortType)
{
    return _VideoCommGetPortIndex(&prCommState->rOutputBuff[0], ePortType);
}

static void _VideoCommSetPortParam(
    void* pParam,
    VIDEO_PORT_BUFFER_T* prPortBuffer,
    VIDEO_PORT_PARAM_T* prCompBuffParam,
    VIDEO_COMPONENT_PARAM_T* prCompParam)
{
    VIDEO_PORT_PARAM_T *prSetParam;

    prSetParam = (VIDEO_PORT_PARAM_T*)pParam;
    prCompBuffParam->ePortType = prSetParam->ePortType;
    prCompBuffParam->fgBufferSupplier = _VideoCommCheckSupplier(prPortBuffer, prCompBuffParam->ePortType, &prCompBuffParam->u4PortIndex);
    if (prCompBuffParam->fgBufferSupplier != prSetParam->fgBufferSupplier)
    {
        ASSERT(0);
    }
    prCompParam->u4PortIndex = prSetParam->u4PortIndex;
    prCompParam->prComp = prSetParam->prTunnelPort;
    prCompParam->pfnProcessThisBuffer = prSetParam->pfnProcessThisBuffer;
}

/******************************************************************************
* Set the attributes of the input port with the attributed in *pParam.
******************************************************************************/
void VideoCommSetInputPortParam(VIDEO_COMM_STATE_T *prCommState, void *pParam)
{
    VIDEO_PORT_PARAM_T rCompBuffParam;
    VIDEO_COMPONENT_PARAM_T rCompParam;

    _VideoCommSetPortParam(pParam, &prCommState->rInputBuff[0],&rCompBuffParam, &rCompParam);
    VideoCommSetInputComp(prCommState, rCompBuffParam.u4PortIndex, &rCompParam);
}


/******************************************************************************
* Set the attributes of the output port with the attributed in *pParam.
*
******************************************************************************/
void VideoCommSetOutputPortParam(VIDEO_COMM_STATE_T *prCommState, void *pParam)
{
    VIDEO_PORT_PARAM_T rCompBuffParam;
    VIDEO_COMPONENT_PARAM_T rCompParam;

    _VideoCommSetPortParam(pParam, &prCommState->rOutputBuff[0],&rCompBuffParam, &rCompParam);
    VideoCommSetOutputComp(prCommState, rCompBuffParam.u4PortIndex, &rCompParam);
}


/******************************************************************************
* Get the input port parameter from the input argument "*pParam".
*
* Side effect: the input argument "*pParam"
******************************************************************************/
void VideoCommGetInputPortParam(VIDEO_COMM_STATE_T *prCommState, void *pParam)
{
    VIDEO_PORT_PARAM_T *prGetParam;

    prGetParam = (VIDEO_PORT_PARAM_T*)pParam;
    prGetParam->fgBufferSupplier = VideoCommCheckInputSupplier(prCommState,
        prGetParam->ePortType, &prGetParam->u4PortIndex);
}


/******************************************************************************
* Get the output port parameter from the input argument "*pParam".
*
* Side effect: the input argument "*pParam"
******************************************************************************/
void VideoCommGetOutputPortParam(VIDEO_COMM_STATE_T *prCommState, void *pParam)
{
    VIDEO_PORT_PARAM_T *prGetParam;

    prGetParam = (VIDEO_PORT_PARAM_T*)pParam;
    prGetParam->fgBufferSupplier = VideoCommCheckOutputSupplier(prCommState,
        prGetParam->ePortType, &prGetParam->u4PortIndex);
}


/******************************************************************************
*
******************************************************************************/
/* Set the input component pointer and related port index.
    The input component is which connected to input port with index "nPortIndex"*/
static void VideoCommSetInputComp(VIDEO_COMM_STATE_T *prCommState, kal_uint32 u4PortIndex,
        VIDEO_COMPONENT_PARAM_T *prCompParam)
{
    kal_mem_cpy((void*)&prCommState->rInputComp[u4PortIndex], (void*)prCompParam, sizeof(prCommState->rInputComp[u4PortIndex]));
}

/* Set the output component pointer and related port index.
    The output component is which connected to output port with index "nPortIndex"*/
static void VideoCommSetOutputComp(VIDEO_COMM_STATE_T *prCommState, kal_uint32 u4PortIndex,
        VIDEO_COMPONENT_PARAM_T *prCompParam)
{
    kal_mem_cpy((void*)&prCommState->rOutputComp[u4PortIndex], (void*)prCompParam, sizeof(prCommState->rOutputComp[u4PortIndex]));
}


/******************************************************************************
* Get the pointer to the input component with the specified port index
* u4PortIndex.
******************************************************************************/
VIDEO_COMPONENT_PARAM_T* VideoCommGetInputComp(VIDEO_COMM_STATE_T *prCommState,
        kal_uint32 u4PortIndex)
{
    return &prCommState->rInputComp[u4PortIndex];
}


/******************************************************************************
* Get the pointer to the output component with the specified port index
* u4PortIndex.
******************************************************************************/
VIDEO_COMPONENT_PARAM_T* VideoCommGetOutputComp(VIDEO_COMM_STATE_T *prCommState,
        kal_uint32 u4PortIndex)
{
    return &prCommState->rOutputComp[u4PortIndex];
}

/* Get the input component pointer and related port index.
    The input component is which connected to input port with index "nPortIndex"*/
PFN_PROCESS_BUFFER_T VideoCommGetInputProcessBufferFunc(VIDEO_COMM_STATE_T *prCommState,
        kal_uint32 u4PortIndex)
{
    return prCommState->rInputComp[u4PortIndex].pfnProcessThisBuffer;
}

/* Get the output component pointer and related port index.
    The output component is which connected to input port with index "nPortIndex"*/
PFN_PROCESS_BUFFER_T VideoCommGetOutputProcessBufferFunc(VIDEO_COMM_STATE_T *prCommState,
        kal_uint32 u4PortIndex)
{
    return prCommState->rOutputComp[u4PortIndex].pfnProcessThisBuffer;
}

kal_bool VideoCommCheckProcessing(VIDEO_COMM_STATE_T *prCommState)
{
    return prCommState->fgProcessing;
}

kal_bool VideoCommSetProcessingNew(VIDEO_COMM_STATE_T *prCommState, kal_bool fgCompClosing)
{
    kal_bool fgRet = KAL_FALSE;
    kal_uint32 u4SavedMask;

    u4SavedMask = SaveAndSetIRQMask();
    if (prCommState->fgCompClosing == KAL_TRUE)
    {
        fgRet = KAL_FALSE;
    }
    else if(prCommState->fgProcessing == KAL_FALSE)
    {
        prCommState->fgProcessing = KAL_TRUE;
        fgRet = KAL_TRUE;
    }
    RestoreIRQMask(u4SavedMask);

    if (!prCommState->fgCompClosing)
    {
        prCommState->fgCompClosing = fgCompClosing;
    }

    return fgRet;
}


/******************************************************************************
* Clear the flag fgProcessing in a critical section to indicate that the video
* component is not processing data.
******************************************************************************/
void VideoCommClrProcessing(VIDEO_COMM_STATE_T *prCommState)
{
    kal_uint32 u4SavedMask;

    u4SavedMask = SaveAndSetIRQMask();
    if (prCommState->fgProcessing == KAL_FALSE)
    {
        ASSERT(0);
    }
    prCommState->fgProcessing = KAL_FALSE;
    RestoreIRQMask(u4SavedMask);
}

/******************************************************************************
* En-queue (rather than push) a buffer header
******************************************************************************/
static kal_bool VideoCommPushQ(VIDEO_COMM_BUFF_QUEUE_T *prQ, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    const kal_uint32 u4ReadIdx = prQ->u4ReadIdx;
    const kal_uint32 u4WriteIdx = prQ->u4WriteIdx;
    const kal_uint32 u4TotalNum = prQ->u4TotalNum;
    kal_uint32 u4SavedMask;

    if (u4TotalNum == 0 || prQ->prBuffQ == NULL)
    {
        ASSERT(0);
        return KAL_FALSE;
    }

    if (((u4WriteIdx + 1) % u4TotalNum) == u4ReadIdx)
    {
        return KAL_FALSE;
    }

    u4SavedMask = SaveAndSetIRQMask();
    prQ->prBuffQ[u4WriteIdx] = *prBuffHeader;
    prQ->u4WriteIdx = (u4WriteIdx + 1) % u4TotalNum;
    prQ->u4UsedNum++;
    RestoreIRQMask(u4SavedMask);

    return KAL_TRUE;
}

/******************************************************************************
* De-queue (rather than pop) a buffer header
******************************************************************************/
static kal_bool VideoCommPopQ(VIDEO_COMM_BUFF_QUEUE_T *prQ, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    const kal_uint32 u4ReadIdx = prQ->u4ReadIdx;
    const kal_uint32 u4WriteIdx = prQ->u4WriteIdx;
    const kal_uint32 u4TotalNum = prQ->u4TotalNum;
    kal_uint32 u4SavedMask;

    if (prQ->prBuffQ == NULL)
    {
        ASSERT(0);
        return KAL_FALSE;
    }

    if (u4ReadIdx == u4WriteIdx)
    {
        return KAL_FALSE;
    }

    u4SavedMask = SaveAndSetIRQMask();
    *prBuffHeader = prQ->prBuffQ[u4ReadIdx];
    prQ->u4ReadIdx = (u4ReadIdx + 1) % u4TotalNum;
    prQ->u4UsedNum--;
    RestoreIRQMask(u4SavedMask);

    return KAL_TRUE;
}

/******************************************************************************
*
******************************************************************************/
void VideoCommClrQ(VIDEO_COMM_BUFF_QUEUE_T *prQ)
{
    kal_uint32 u4SavedMask;

    if (prQ->prBuffQ == NULL)
    {
        ASSERT(0);
        return;
    }

    u4SavedMask = SaveAndSetIRQMask();

    prQ->u4WriteIdx = 0;
    prQ->u4ReadIdx = 0;
    prQ->u4UsedNum= 0;

    RestoreIRQMask(u4SavedMask);
}


void VideoCommClrAllQ(VIDEO_COMM_STATE_T *prCommState)
{
    kal_uint32 u4SavedMask;
    kal_uint32 i = 0;

    u4SavedMask = SaveAndSetIRQMask();

    if (prCommState->u4EntryCount != 0)
    {
        EXT_ASSERT(0, prCommState->u4EntryCount, 0, 0);
    }

    prCommState->rCmdQ.u4WriteIdx = 0;
    prCommState->rCmdQ.u4ReadIdx = 0;

    for (;i < VIDEO_PORT_MAX_NUM; i++)
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


/******************************************************************************
* En-queue (rather than push) a command in the command queue of *prCommState.
* Store the command and its associated parameter in *peCmd and *pu4Param
* respectively.
*
* Note: The term "Push" in the function name is a misnomer.
*
* Side effect: the command queue, *peCmd, *pu4Param, and *pfgEmpty
*
* Return value:
*       KAL_TRUE if a command can be retrieved from the command queue.
*       KAL_FALSE if the command queue is full.
******************************************************************************/
kal_bool VideoCommPushCommand(VIDEO_COMM_STATE_T *prCommState,
        VIDEO_COMMAND_TYPE_T eCmd, kal_uint32 u4Param)
{
    kal_uint32 u4ReadIdx, u4WriteIdx, u4TotalNum;
    kal_uint32 u4SavedMask;

    u4SavedMask = SaveAndSetIRQMask();
    prCommState->u4EntryCount++;
    RestoreIRQMask(u4SavedMask);

    kal_take_mutex(prCommState->eMutex);

    u4ReadIdx = prCommState->rCmdQ.u4ReadIdx;
    u4WriteIdx = prCommState->rCmdQ.u4WriteIdx;
    u4TotalNum = prCommState->rCmdQ.u4TotalNum;

    if (u4TotalNum == 0)
    {
        ASSERT(0);
        return KAL_FALSE;
    }

    if (((u4WriteIdx + 1) % u4TotalNum) == u4ReadIdx)
    {
        kal_give_mutex(prCommState->eMutex);
        u4SavedMask = SaveAndSetIRQMask();
        prCommState->u4EntryCount--;
        RestoreIRQMask(u4SavedMask);
        return KAL_FALSE;
    }

    prCommState->rCmdQ.prCmdQ[u4WriteIdx].eCmd = eCmd;
    prCommState->rCmdQ.prCmdQ[u4WriteIdx].u4Param = u4Param;
    prCommState->rCmdQ.u4WriteIdx = (u4WriteIdx + 1) % u4TotalNum;

    kal_give_mutex(prCommState->eMutex);

    u4SavedMask = SaveAndSetIRQMask();
    prCommState->u4EntryCount--;
    RestoreIRQMask(u4SavedMask);

    return KAL_TRUE;
}


/******************************************************************************
* De-queue (rather than pop) a command in the command queue of *prCommState.
* Store the command and its associated parameter in *peCmd and *pu4Param
* respectively.
*
* Note: The term "Pop" in the function name is a misnomer.
*
* Side effect: the command queue, *peCmd, and *pu4Param
*
* Return value:
*       KAL_TRUE if a command can be retrieved from the command queue.
*       KAL_FALSE if the command queue is empty.
******************************************************************************/
kal_bool VideoCommPopCommand(VIDEO_COMM_STATE_T *prCommState,
        VIDEO_COMMAND_TYPE_T *peCmd, kal_uint32 *pu4Param)
{
    kal_uint32 u4ReadIdx, u4WriteIdx, u4TotalNum;
    kal_uint32 u4SavedMask;

    u4SavedMask = SaveAndSetIRQMask();
    prCommState->u4EntryCount++;
    RestoreIRQMask(u4SavedMask);

    kal_take_mutex(prCommState->eMutex);

    u4ReadIdx = prCommState->rCmdQ.u4ReadIdx;
    u4WriteIdx = prCommState->rCmdQ.u4WriteIdx;
    u4TotalNum = prCommState->rCmdQ.u4TotalNum;

    if (u4ReadIdx == u4WriteIdx)
    {
        kal_give_mutex(prCommState->eMutex);

        u4SavedMask = SaveAndSetIRQMask();
        prCommState->u4EntryCount--;
        RestoreIRQMask(u4SavedMask);

        return KAL_FALSE;
    }

    *peCmd = prCommState->rCmdQ.prCmdQ[u4ReadIdx].eCmd;
    *pu4Param = prCommState->rCmdQ.prCmdQ[u4ReadIdx].u4Param;
    prCommState->rCmdQ.u4ReadIdx = (u4ReadIdx + 1) % u4TotalNum;

    kal_give_mutex(prCommState->eMutex);

    u4SavedMask = SaveAndSetIRQMask();
    prCommState->u4EntryCount--;
    RestoreIRQMask(u4SavedMask);

    return KAL_TRUE;
}

static kal_bool _VideoCommPushCommBuffer(
    VIDEO_COMM_BUFF_QUEUE_T* prQueue,
    VIDEO_COMM_STATE_T *prCommState,
    VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    kal_bool fgErr;

    if (VIDEO_STATE_CLOSE == VideoCommGetState(prCommState))
    {
        ASSERT(0);
    }

    fgErr = VideoCommPushQ(prQueue, prBuffHeader);

    return fgErr;
}

static VIDEO_COMM_BUFF_QUEUE_T* _VideCommGetInputBuffQ(VIDEO_COMM_STATE_T *prCommState, kal_uint32 u4PortIdx)
{
    VIDEO_COMM_BUFF_QUEUE_T* prTmp = NULL;

    if (u4PortIdx >= VIDEO_PORT_MAX_NUM)
    {
        ASSERT(0);
    }
    return &prCommState->rInputBuffQ[u4PortIdx];
}

static VIDEO_COMM_BUFF_QUEUE_T* _VideCommGetOutputBuffQ(VIDEO_COMM_STATE_T *prCommState, kal_uint32 u4PortIdx)
{
    VIDEO_COMM_BUFF_QUEUE_T* prTmp = NULL;

    if (u4PortIdx >= VIDEO_PORT_MAX_NUM)
    {
        ASSERT(0);
    }
    return &prCommState->rOutputBuffQ[u4PortIdx];
}

/******************************************************************************
* En-queue (rather than push) a buffer header into the input queue of
* *prCommState.
*
* Note: The term "Push" in the function name is a misnomer.
*
* Side effect: the input queue, *prBuffHeader, *pfgEmpty
*
* Return value:
*       KAL_TRUE if a buffer header can be inserted into the input queue.
*       KAL_FALSE if the input queue is full.
******************************************************************************/
kal_bool VideoCommPushInputBuffExt(
    VIDEO_COMM_STATE_T *prCommState,
    VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader,
    kal_uint32 u4PortIdx)
{
    VIDEO_COMM_BUFF_QUEUE_T* prTmp = _VideCommGetInputBuffQ(prCommState, u4PortIdx);

    return _VideoCommPushCommBuffer(prTmp, prCommState, prBuffHeader);
}

/******************************************************************************
* En-queue (rather than push) a buffer header into the input queue of
* *prCommState.
*
* Note: The term "Push" in the function name is a misnomer.
*
* Side effect: the input queue, *prBuffHeader, *pfgEmpty
*
* Return value:
*       KAL_TRUE if a buffer header can be inserted into the input queue.
*       KAL_FALSE if the input queue is full.
******************************************************************************/
kal_bool VideoCommPushInputBuff(VIDEO_COMM_STATE_T *prCommState,
        VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    return VideoCommPushInputBuffExt(prCommState, prBuffHeader, 0);
}

static kal_bool _VideoCommGetBuffData(
    const VIDEO_COMM_BUFF_QUEUE_T* prBuffQueue,
    VIDEO_COMM_STATE_T *prCommState,
    VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    const kal_uint32 u4ReadIdx = prBuffQueue->u4ReadIdx;
    const kal_uint32 u4WriteIdx = prBuffQueue->u4WriteIdx;
    kal_uint32 u4SavedMask;

    u4SavedMask = SaveAndSetIRQMask();
    prCommState->u4EntryCount++;
    RestoreIRQMask(u4SavedMask);

    if (u4ReadIdx == u4WriteIdx)
    {
        u4SavedMask = SaveAndSetIRQMask();
        prCommState->u4EntryCount--;
        RestoreIRQMask(u4SavedMask);
        return KAL_FALSE;
    }

    *prBuffHeader = prBuffQueue->prBuffQ[u4ReadIdx];

    u4SavedMask = SaveAndSetIRQMask();
    prCommState->u4EntryCount--;
    RestoreIRQMask(u4SavedMask);
    return KAL_TRUE;
}

kal_bool VideoCommGetOutputBuffDataExt(
    VIDEO_COMM_STATE_T *prCommState,
    VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader,
    kal_uint32 u4PortIdx)
{
    const VIDEO_COMM_BUFF_QUEUE_T* prBuffQueue = _VideCommGetOutputBuffQ(prCommState, u4PortIdx);

    return _VideoCommGetBuffData(prBuffQueue, prCommState, prBuffHeader);
}

kal_bool VideoCommGetInputBuffDataExt(
    VIDEO_COMM_STATE_T *prCommState,
    VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader,
    kal_uint32 u4PortIdx)
{
    const VIDEO_COMM_BUFF_QUEUE_T* prBuffQueue = _VideCommGetInputBuffQ(prCommState, u4PortIdx);

    return _VideoCommGetBuffData(prBuffQueue, prCommState, prBuffHeader);
}

/******************************************************************************
*  Query a buffer header in the input queue of
* *prCommState, and store the buffer header in *prBuffHeader.
*
* Side effect: the input queue, *prBuffHeader
*
* Return value:
*       KAL_TRUE if a buffer header can be retrieved from the input queue.
*       KAL_FALSE if the input queue is empty.
******************************************************************************/
kal_bool VideoCommGetInputBuffData(VIDEO_COMM_STATE_T *prCommState, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    return VideoCommGetInputBuffDataExt(prCommState, prBuffHeader, 0);
}

/******************************************************************************
* Update the read index
*
* Side effect: the input queue, *prBuffHeader
*
* Return value:
*       KAL_TRUE if a buffer header can be retrieved from the input queue.
*       KAL_FALSE if the input queue is empty.
******************************************************************************/
kal_bool VideoCommConsumeInputBuffData(VIDEO_COMM_STATE_T *prCommState)
{
    const kal_uint32 u4ReadIdx = prCommState->rInputBuffQ[0].u4ReadIdx;
    const kal_uint32 u4WriteIdx = prCommState->rInputBuffQ[0].u4WriteIdx;
    const kal_uint32 u4TotalNum = prCommState->rInputBuffQ[0].u4TotalNum;
    kal_uint32 u4SavedMask;

    u4SavedMask = SaveAndSetIRQMask();
    prCommState->u4EntryCount++;

    if (u4ReadIdx == u4WriteIdx)
    {
        prCommState->u4EntryCount--;
        RestoreIRQMask(u4SavedMask);
        return KAL_FALSE;
    }

    prCommState->rInputBuffQ[0].u4ReadIdx = (u4ReadIdx + 1) % u4TotalNum;
    prCommState->rInputBuffQ[0].u4UsedNum--;
    prCommState->u4EntryCount--;
    RestoreIRQMask(u4SavedMask);

    return KAL_TRUE;
}

kal_bool VideoCommPopInputBuffExt(
    VIDEO_COMM_STATE_T *prCommState,
    VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader,
    kal_uint32 u4PortIdx)
{
    VIDEO_COMM_BUFF_QUEUE_T* prTmp = _VideCommGetInputBuffQ(prCommState, u4PortIdx);

    return VideoCommPopQ(prTmp, prBuffHeader);
}

/******************************************************************************
* De-queue (rather than pop) a buffer header in the input queue of
* *prCommState, and store the buffer header in *prBuffHeader.
*
* Note: The term "Pop" in the function name is a misnomer.
*
* Side effect: the input queue, *prBuffHeader
*
* Return value:
*       KAL_TRUE if a buffer header can be retrieved from the input queue.
*       KAL_FALSE if the input queue is empty.
******************************************************************************/
kal_bool VideoCommPopInputBuff(VIDEO_COMM_STATE_T *prCommState, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    return VideoCommPopInputBuffExt(prCommState, prBuffHeader, 0);
}

/******************************************************************************
* Query the number of entries in the input queue of *prCommState.
*
* Return value:
*       the number of entries in the input queue of *prCommState.
******************************************************************************/
kal_uint32 VideoCommQueryInputBuff(VIDEO_COMM_STATE_T *prCommState)
{
    const kal_uint32 u4TotalNum = prCommState->rInputBuffQ[0].u4TotalNum;
    kal_uint32 u4SavedMask, u4UsedNum;

    u4SavedMask = SaveAndSetIRQMask();
    prCommState->u4EntryCount++;
    u4UsedNum = prCommState->rInputBuffQ[0].u4UsedNum;
    prCommState->u4EntryCount--;
    RestoreIRQMask(u4SavedMask);

    if (u4UsedNum > u4TotalNum)
    {
        EXT_ASSERT(0, u4TotalNum, u4UsedNum, 0);
    }

    return u4UsedNum;
}

kal_bool VideoCommPushOutputBuffExt(
    VIDEO_COMM_STATE_T *prCommState,
    VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader,
    kal_uint32 u4PortIdx)
{
    VIDEO_COMM_BUFF_QUEUE_T* prTmp = _VideCommGetOutputBuffQ(prCommState, u4PortIdx);

    return _VideoCommPushCommBuffer(prTmp, prCommState, prBuffHeader);
}

/******************************************************************************
* En-queue (rather than push) a buffer header into the command queue of
* *prCommState.
*
* Note: The term "Push" in the function name is a misnomer.
*
* Side effect: the output queue, *prBuffHeader, *pfgEmpty
*
* Return value:
*       KAL_TRUE if a buffer header can be inserted into the command queue.
*       KAL_FALSE if the command queue is full.
******************************************************************************/
kal_bool VideoCommPushOutputBuff(VIDEO_COMM_STATE_T *prCommState,
        VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    return VideoCommPushOutputBuffExt(prCommState, prBuffHeader, 0);
}

kal_bool VideoCommPopOutputBuffExt(
    VIDEO_COMM_STATE_T *prCommState,
    VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader,
    kal_uint32 u4PortIdx)
{
    VIDEO_COMM_BUFF_QUEUE_T* prTmp = _VideCommGetOutputBuffQ(prCommState, u4PortIdx);

    return VideoCommPopQ(prTmp, prBuffHeader);
}

/******************************************************************************
* De-queue (rather than pop) a buffer header in the output queue of
* *prCommState, and store the buffer header in *prBuffHeader.
*
* Note: The term "Pop" in the function name is a misnomer.
*
* Side effect: the output queue, *prBuffHeader
*
* Return value:
*       KAL_TRUE if a buffer header can be retrieved from the output queue.
*       KAL_FALSE if the output queue is empty.
******************************************************************************/
kal_bool VideoCommPopOutputBuff(VIDEO_COMM_STATE_T *prCommState,
        VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    return VideoCommPopOutputBuffExt(prCommState, prBuffHeader, 0);
}

static kal_uint32 _VideoCommQueryOutputBuffer(
    VIDEO_COMM_STATE_T *prCommState,
    VIDEO_COMM_BUFF_QUEUE_T* p4CommBuffQ)
{
    const kal_uint32 u4TotalNum = p4CommBuffQ->u4TotalNum;
    kal_uint32 u4SavedMask, u4UsedNum;

    u4SavedMask = SaveAndSetIRQMask();
    prCommState->u4EntryCount++;
    u4UsedNum = p4CommBuffQ->u4UsedNum;
    prCommState->u4EntryCount--;
    RestoreIRQMask(u4SavedMask);

    if (u4UsedNum > u4TotalNum)
    {
        EXT_ASSERT(0, u4TotalNum, u4UsedNum, 0);
    }

    return u4UsedNum;
}

kal_uint32 VideoCommQueryOutputBuffExt(VIDEO_COMM_STATE_T *prCommState, kal_uint32 u4PortIdx)
{
    VIDEO_COMM_BUFF_QUEUE_T* prTmp = _VideCommGetOutputBuffQ(prCommState, u4PortIdx);

    return _VideoCommQueryOutputBuffer(prCommState, prTmp);
}

/******************************************************************************
* Query the number of entries in the input queue of *prCommState.
*
* Return value:
*       the number of entries in the input queue of *prCommState.
******************************************************************************/
kal_uint32 VideoCommQueryOutputBuff(VIDEO_COMM_STATE_T *prCommState)
{
    return VideoCommQueryOutputBuffExt(prCommState, 0);
}

/* setup tunnel between component "pInputComp" and "pOutputComp" with port type "nPortType"*/
VIDEO_ERROR_TYPE_T VideoSetupTunnel(VIDEO_COMPONENT_TYPE_T *prInputComp,
        VIDEO_COMPONENT_TYPE_T *prOutputComp, VIDEO_PORT_TYPE_T ePortType)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VIDEO_PORT_PARAM_T rInputCompParam, rOutputCompParam;
    kal_uint32 u4InputCompPortIndex, u4OutputCompPortIndex;

    rInputCompParam.ePortType = ePortType;
    rOutputCompParam.ePortType = ePortType;
    eError = prInputComp->pfnGetParameter(VIDEO_PARAM_OUTPUT_BUFFER_PARAM, (void*)&rInputCompParam);
    eError = prOutputComp->pfnGetParameter(VIDEO_PARAM_INPUT_BUFFER_PARAM, (void*)&rOutputCompParam);
    u4InputCompPortIndex = rInputCompParam.u4PortIndex;
    u4OutputCompPortIndex = rOutputCompParam.u4PortIndex;

    rInputCompParam.ePortType = ePortType;
    rInputCompParam.u4PortIndex = u4OutputCompPortIndex;
    rInputCompParam.prTunnelPort = prOutputComp;
    rInputCompParam.pfnProcessThisBuffer = prOutputComp->pfnEmptyThisBuffer;
    rOutputCompParam.ePortType = ePortType;
    rOutputCompParam.u4PortIndex = u4InputCompPortIndex;
    rOutputCompParam.prTunnelPort = prInputComp;
    rOutputCompParam.pfnProcessThisBuffer = prInputComp->pfnFillThisBuffer;

    if (rOutputCompParam.fgBufferSupplier == KAL_TRUE)
    {
        rInputCompParam.fgBufferSupplier = KAL_FALSE;
        rOutputCompParam.fgBufferSupplier = KAL_TRUE;
    }
    else if (rInputCompParam.fgBufferSupplier == KAL_TRUE)
    {
        rInputCompParam.fgBufferSupplier = KAL_TRUE;
        rOutputCompParam.fgBufferSupplier = KAL_FALSE;
    }
    else
    {
        return VIDEO_ERROR_INIT_ERROR;
    }

    eError = prInputComp->pfnSetParameter(VIDEO_PARAM_OUTPUT_BUFFER_PARAM, (void*)&rInputCompParam);
    if(eError != VIDEO_ERROR_NONE)
    {
        return VIDEO_ERROR_INIT_ERROR;
    }
    eError = prOutputComp->pfnSetParameter(VIDEO_PARAM_INPUT_BUFFER_PARAM, (void*)&rOutputCompParam);
    if(eError != VIDEO_ERROR_NONE)
    {
        return VIDEO_ERROR_INIT_ERROR;
    }

    return eError;
}

VIDEO_ERROR_TYPE_T VideoConfigComp(VIDEO_COMPONENT_TYPE_T *prComp, kal_bool fgInput,
        VIDEO_PORT_TYPE_T ePortType, PFN_PROCESS_BUFFER_T pfnProcessThisBuffer)
{
    VIDEO_ERROR_TYPE_T eError;
    VIDEO_PORT_PARAM_T rConfigCompParam;

    rConfigCompParam.ePortType = ePortType;
    if(fgInput == KAL_TRUE)
    {
        eError = prComp->pfnGetParameter(VIDEO_PARAM_INPUT_BUFFER_PARAM, (void*)&rConfigCompParam);
    }
    else
    {
        eError = prComp->pfnGetParameter(VIDEO_PARAM_OUTPUT_BUFFER_PARAM, (void*)&rConfigCompParam);
    }

    // TODO: it a fixed number for port index, should be matched with source component
    if (ePortType == VIDEO_PORT_AUDIO_DATA)
    {
        rConfigCompParam.u4PortIndex = 0;
    }
    else if (ePortType == VIDEO_PORT_VIDEO_DATA)
    {
        rConfigCompParam.u4PortIndex = 1;
    }

    rConfigCompParam.prTunnelPort = NULL;
    rConfigCompParam.pfnProcessThisBuffer = pfnProcessThisBuffer;

    if(fgInput == KAL_TRUE)
    {
        eError = prComp->pfnSetParameter(VIDEO_PARAM_INPUT_BUFFER_PARAM, (void*)&rConfigCompParam);
    }
    else
    {
        eError = prComp->pfnSetParameter(VIDEO_PARAM_OUTPUT_BUFFER_PARAM, (void*)&rConfigCompParam);
    }

    if(eError != VIDEO_ERROR_NONE)
    {
        return VIDEO_ERROR_INIT_ERROR;
    }

    return eError;
}

kal_uint32 VideoCommGetInputBuffQUsedNum(VIDEO_COMM_STATE_T *prCommState, kal_uint32 u4PortIdx)
{
    VIDEO_COMM_BUFF_QUEUE_T* prTmp = _VideCommGetInputBuffQ(prCommState, u4PortIdx);
    return prTmp->u4UsedNum;
}

kal_uint32 VideoCommGetOutputBuffQUsedNum(VIDEO_COMM_STATE_T *prCommState, kal_uint32 u4PortIdx)
{
    VIDEO_COMM_BUFF_QUEUE_T* prTmp = _VideCommGetOutputBuffQ(prCommState, u4PortIdx);
    return prTmp->u4UsedNum;
}

#ifdef __VE_MM_DCM_SUPPORT__
#pragma arm section code, rodata
#endif

/******************************************************************************
* Multiple instance common
******************************************************************************/
// TODO: Should discuss with Gary, pass prComp issue.
VIDEO_ERROR_TYPE_T VideoMIConfigComp(VIDEO_COMPONENT_MI_TYPE_T *prComp, void *pHandle, kal_bool fgInput,
        VIDEO_PORT_TYPE_T ePortType, PFN_PROCESS_BUFFER_T pfnProcessThisBuffer)
{
    VIDEO_ERROR_TYPE_T eError;
    VIDEO_PORT_PARAM_T rConfigCompParam;

    rConfigCompParam.ePortType = ePortType;
    if(fgInput == KAL_TRUE)
    {
        eError = prComp->pfnGetParameter(pHandle, VIDEO_PARAM_INPUT_BUFFER_PARAM, (void*)&rConfigCompParam);
    }
    else
    {
        eError = prComp->pfnGetParameter(pHandle, VIDEO_PARAM_OUTPUT_BUFFER_PARAM, (void*)&rConfigCompParam);
    }

    // TODO: it a fixed number for port index, should be matched with source component
    if (ePortType == VIDEO_PORT_AUDIO_DATA)
    {
        rConfigCompParam.u4PortIndex = 0;
    }
    else if (ePortType == VIDEO_PORT_VIDEO_DATA)
    {
        rConfigCompParam.u4PortIndex = 1;
    }

    rConfigCompParam.prTunnelPort = NULL;
    rConfigCompParam.pfnProcessThisBuffer = pfnProcessThisBuffer;

    if(fgInput == KAL_TRUE)
    {
        eError = prComp->pfnSetParameter(pHandle, VIDEO_PARAM_INPUT_BUFFER_PARAM, (void*)&rConfigCompParam);
    }
    else
    {
        eError = prComp->pfnSetParameter(pHandle, VIDEO_PARAM_OUTPUT_BUFFER_PARAM, (void*)&rConfigCompParam);
    }

    if(eError != VIDEO_ERROR_NONE)
    {
        return VIDEO_ERROR_INIT_ERROR;
    }

    return eError;
}

#pragma arm section code = "SECONDARY_ROCODE"
kal_bool VideoCommSetProcessing(VIDEO_COMM_STATE_T *prCommState)
{
    kal_bool fgRet = KAL_FALSE;
    kal_uint32 u4SavedMask;

    u4SavedMask = SaveAndSetIRQMask();
    if (prCommState->fgProcessing == KAL_FALSE)
    {
        prCommState->fgProcessing = KAL_TRUE;
        fgRet = KAL_TRUE;
    }
    RestoreIRQMask(u4SavedMask);

    return fgRet;
}
#pragma arm section code

#endif /* __VE_VIDEO_COMMON__ */
