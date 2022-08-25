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
 *   video_comm_component_v2.h
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
 *
 *
 * removed!
 * removed!
 *
 *
 *
 ****************************************************************************/
#ifndef VIDEO_COMM_COMPONENT_V2_H
#define VIDEO_COMM_COMPONENT_V2_H
#include "drv_features_video.h"
#include "video_types_v2.h"

/* The following files are newly added for RHR. */
// #include "kal_non_specific_general_types.h"
// #include "kal_release.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"


//#define VIDEO_COMM_MAX_CMD_NUM  10
//#define VIDEO_COMM_MAX_BUFF_NUM  10
#if defined(__VE_SUBTITLE_SUPPORT__)
    #define VIDEO_PORT_MAX_NUM  3
#else
    #define VIDEO_PORT_MAX_NUM  2
#endif

typedef VIDEO_ERROR_TYPE_T (*pfnProcessBuffer_t)(VIDEO_BUFFERHEADER_TYPE_T *);

typedef enum
{
    PORT_0 = 0,
    PORT_1
}VIDEO_COMM_PORT_T;


// Make sure: VIDEO_COMM_COMMAND_Q_ITEM_SIZE >= sizeof(VIDEO_COMM_CMD_PARAM_T)
#define VIDEO_COMM_COMMAND_Q_ITEM_SIZE          16
typedef struct
{
    VIDEO_COMMAND_TYPE_T eCmd;
    kal_uint32 u4Param;
} VIDEO_COMM_CMD_PARAM_T;


typedef struct
{
    VIDEO_COMM_CMD_PARAM_T *prCmdQ;
    kal_uint32 u4ReadIdx;
    kal_uint32 u4WriteIdx;
    kal_uint32 u4TotalNum;
} VIDEO_COMM_CMD_QUEUE_T;


typedef struct
{
    VIDEO_BUFFERHEADER_TYPE_T *prBuffQ;
    kal_uint32 u4ReadIdx;
    kal_uint32 u4WriteIdx;
    kal_uint32 u4UsedNum;
    kal_uint32 u4TotalNum;
} VIDEO_COMM_BUFF_QUEUE_T;


/* component internal use. keep port informations */
typedef struct
{
    VIDEO_PORT_TYPE_T ePortType;
    // kal_uint32 u4PortIndex;  // commented out by Leroy
    kal_bool fgSupplier;
    kal_uint8 *pu1Buff;         // Used as a bitstream or YUV buffer.
    kal_uint32 u4BuffSize;      // the size of the array *pu1Buff
} VIDEO_PORT_BUFFER_T;


/* component use this to query/setting port parameters */
typedef struct
{
    VIDEO_PORT_TYPE_T ePortType;
    kal_uint32 u4PortIndex;     // Port index of the current component
    kal_bool fgBufferSupplier;
    VIDEO_COMPONENT_TYPE_T *prTunnelPort;
    pfnProcessBuffer_t pfnProcessThisBuffer;
} VIDEO_PORT_PARAM_T;

typedef struct
{
    kal_mutexid  eMutex;
    VIDEO_STATE_TYPE_T eState;
    VIDEO_CALLBACK_TYPE_T *prCallback;
    VIDEO_COMPONENT_PARAM_T rInputComp[VIDEO_PORT_MAX_NUM];
    VIDEO_COMPONENT_PARAM_T rOutputComp[VIDEO_PORT_MAX_NUM];
    VIDEO_PORT_BUFFER_T rInputBuff[VIDEO_PORT_MAX_NUM];
    VIDEO_PORT_BUFFER_T rOutputBuff[VIDEO_PORT_MAX_NUM];
    VIDEO_COMM_CMD_QUEUE_T rCmdQ;
    VIDEO_COMM_BUFF_QUEUE_T rInputBuffQ[VIDEO_PORT_MAX_NUM];
    VIDEO_COMM_BUFF_QUEUE_T rOutputBuffQ[VIDEO_PORT_MAX_NUM];
    kal_uint32 u4EntryCount;
    kal_bool fgProcessing;
    kal_bool fgCompClosing;  // Indicate that component is closing.
    void *pClient;
} VIDEO_COMM_STATE_T;

#define VideoCommGetState(pCommState)       (pCommState)->eState
#define VideoCommGetCallback(pCommState)    (pCommState)->prCallback

#ifdef __VE_VIDEO_COMMON__
VIDEO_ERROR_TYPE_T VideoCommInit(VIDEO_COMM_STATE_T *prCommState, VIDEO_COMPONENT_INIT_T *prConfig, kal_char *pcMutextName);
VIDEO_ERROR_TYPE_T VideoCommDeInit(VIDEO_COMM_STATE_T *prCommState);
VIDEO_ERROR_TYPE_T VideoCommChangeState(VIDEO_COMM_STATE_T *prCommState, VIDEO_STATE_TYPE_T eState);
VIDEO_ERROR_TYPE_T VideoCommSetCallbacks(VIDEO_COMM_STATE_T *prCommState, VIDEO_CALLBACK_TYPE_T *prCallback);
kal_bool VideoCommCheckInputSupplier(VIDEO_COMM_STATE_T *prCommState, VIDEO_PORT_TYPE_T ePortType, kal_uint32 *pu4PortIndex);
kal_bool VideoCommCheckOutputSupplier(VIDEO_COMM_STATE_T *prCommState, VIDEO_PORT_TYPE_T ePortType, kal_uint32 *pu4PortIndex);
kal_uint8* VideoCommGetInputBuff(VIDEO_COMM_STATE_T *prCommState, VIDEO_PORT_TYPE_T ePortType, kal_uint32 *pu4PortIndex);
kal_uint8* VideoCommGetOutputBuff(VIDEO_COMM_STATE_T *prCommState, VIDEO_PORT_TYPE_T ePortType, kal_uint32 *pu4PortIndex);
kal_uint32 VideoCommGetInputPortIndex(VIDEO_COMM_STATE_T *prCommState, VIDEO_PORT_TYPE_T ePortType);
kal_uint32 VideoCommGetOutputPortIndex(VIDEO_COMM_STATE_T *prCommState, VIDEO_PORT_TYPE_T ePortType);
void VideoCommGetInputPortParam(VIDEO_COMM_STATE_T *prCommState, void *pParam);
void VideoCommGetOutputPortParam(VIDEO_COMM_STATE_T *prCommState, void *pParam);
void VideoCommSetInputPortParam(VIDEO_COMM_STATE_T *prCommState, void *pParam);
void VideoCommSetOutputPortParam(VIDEO_COMM_STATE_T *prCommState, void *pParam);
void VideoCommSetInputComp(VIDEO_COMM_STATE_T *prCommState, kal_uint32 u4PortIndex, VIDEO_COMPONENT_PARAM_T *prCompParam);
VIDEO_COMPONENT_PARAM_T* VideoCommGetInputComp(VIDEO_COMM_STATE_T *prCommState, kal_uint32 u4PortIndex);
pfnProcessBuffer_t VideoCommGetInputProcessBufferFunc(VIDEO_COMM_STATE_T *prCommState, kal_uint32 u4PortIndex);
void VideoCommSetOutputComp(VIDEO_COMM_STATE_T *prCommState, kal_uint32 u4PortIndex, VIDEO_COMPONENT_PARAM_T *prCompParam);
VIDEO_COMPONENT_PARAM_T* VideoCommGetOutputComp(VIDEO_COMM_STATE_T *prCommState, kal_uint32 u4PortIndex);
pfnProcessBuffer_t VideoCommGetOutputProcessBufferFunc(VIDEO_COMM_STATE_T *prCommState, kal_uint32 u4PortIndex);
kal_bool VideoCommSetProcessing(VIDEO_COMM_STATE_T *prCommState);
kal_bool VideoCommSetProcessingNew(VIDEO_COMM_STATE_T *prCommState, kal_bool fgCompClosing);
kal_bool VideoCommCheckProcessing(VIDEO_COMM_STATE_T *prCommState);
void VideoCommClrProcessing(VIDEO_COMM_STATE_T *prCommState);
void VideoCommClrQ(VIDEO_COMM_BUFF_QUEUE_T *prQ);
void VideoCommClrAllQ(VIDEO_COMM_STATE_T *prCommState);
kal_bool VideoCommPushCommand(VIDEO_COMM_STATE_T *prCommState, VIDEO_COMMAND_TYPE_T eCmd, kal_uint32 u4Param);
kal_bool VideoCommPopCommand(VIDEO_COMM_STATE_T *prCommState, VIDEO_COMMAND_TYPE_T *peCmd, kal_uint32 *pu4Param);
kal_bool VideoCommPushInputBuff(VIDEO_COMM_STATE_T *prCommState, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader);
kal_bool VideoCommPushInputBuffExt(VIDEO_COMM_STATE_T *prCommState, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader, kal_uint32 u4PortIdx);
kal_bool VideoCommGetInputBuffData(VIDEO_COMM_STATE_T *prCommState, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader);
kal_bool VideoCommGetInputBuffDataExt(VIDEO_COMM_STATE_T *prCommState, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader, kal_uint32 u4PortIdx);
kal_bool VideoCommGetOutputBuffDataExt(VIDEO_COMM_STATE_T *prCommState, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader, kal_uint32 u4PortIdx);
kal_bool VideoCommConsumeInputBuffData(VIDEO_COMM_STATE_T *prCommState);
kal_bool VideoCommPopInputBuff(VIDEO_COMM_STATE_T *prCommState, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader);
kal_bool VideoCommPopInputBuffExt(VIDEO_COMM_STATE_T *prCommState, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader, kal_uint32 u4PortIdx);
kal_uint32 VideoCommQueryInputBuff(VIDEO_COMM_STATE_T *prCommState);
kal_bool VideoCommPushOutputBuff(VIDEO_COMM_STATE_T *prCommState, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader);
kal_bool VideoCommPopOutputBuff(VIDEO_COMM_STATE_T *prCommState, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader);
kal_bool VideoCommPushOutputBuffExt(VIDEO_COMM_STATE_T *prCommState, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader, kal_uint32 u4PortIdx);
kal_bool VideoCommPopOutputBuffExt(VIDEO_COMM_STATE_T *prCommState, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader, kal_uint32 u4PortIdx);
kal_uint32 VideoCommQueryOutputBuff(VIDEO_COMM_STATE_T *prCommState);
kal_uint32 VideoCommQueryOutputBuffExt(VIDEO_COMM_STATE_T *prCommState, kal_uint32 u4PortIdx);
VIDEO_ERROR_TYPE_T VideoSetupTunnel(VIDEO_COMPONENT_TYPE_T *prInputComp, VIDEO_COMPONENT_TYPE_T *prOutputComp, VIDEO_PORT_TYPE_T ePortType);
VIDEO_ERROR_TYPE_T VideoConfigComp(VIDEO_COMPONENT_TYPE_T *prComp, kal_bool fgInput, VIDEO_PORT_TYPE_T ePortType, pfnProcessBuffer_t pfnProcessThisBuffer);
VIDEO_ERROR_TYPE_T VideoMIConfigComp(VIDEO_COMPONENT_MI_TYPE_T *prComp, void *pHandle, kal_bool fgInput, VIDEO_PORT_TYPE_T ePortType, PFN_PROCESS_BUFFER_T pfnProcessThisBuffer);
VIDEO_ERROR_TYPE_T VideoMICommSetClient(VIDEO_COMM_STATE_T *prCommState, void *pClient);
kal_uint32 VideoCommGetInputBuffQUsedNum(VIDEO_COMM_STATE_T *prCommState, kal_uint32 u4PortIdx);
kal_uint32 VideoCommGetOutputBuffQUsedNum(VIDEO_COMM_STATE_T *prCommState, kal_uint32 u4PortIdx);
VIDEO_ERROR_TYPE_T VideoCommConfigPorts(VIDEO_COMM_STATE_T *prCommState, VIDEO_COMPONENT_INIT_PORT_T* prParam);
VIDEO_PORT_TYPE_T VideoCommGetOutputPortType(VIDEO_COMM_STATE_T *prCommState, kal_uint32 u4PortIndex);
VIDEO_PORT_TYPE_T VideoCommGetInputPortType(VIDEO_COMM_STATE_T *prCommState, kal_uint32 u4PortIndex);
#endif /*__VE_VIDEO_COMMON__*/
#endif /* VIDEO_COMM_COMPONENT_V2_H */

