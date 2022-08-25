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
 *   video_codec_schedule_control.h
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
 *
 ****************************************************************************/
#ifndef VIDEO_CODEC_SCHEDULE_CONTROL_H
#define VIDEO_CODEC_SCHEDULE_CONTROL_H

#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__

#include "video_types_v2.h"
#include "kal_general_types.h"
#include "video_codec_utility_v2.h"
#include "video_codec_mem_v2.h"  // for decode inpue queue size
#include "video_encoder_component_if_v2.h"  // for encode inpu queue size and inner yuv header queue size

#define _VCS_DEBUG_

typedef enum
{
    VCS_NONE = 0,
    VCS_ENCODER,
    VCS_DECODER,
    VCS_TASK_MEMBER_MAX
} VCODEC_SCHEDULE_TASK_MEMBER_T;


typedef enum
{
    VCS_SCENARIO_NONE = 0,
    VCS_ENCODER_ONLY,
    VCS_DECODER_ONLY,
    VCS_CODEC_BOTH,
    VCS_SCENARIO_MAX
} VCODEC_SCHEDULE_SCENARIO_T;


typedef enum
{
    VCS_TASKQUEUE_EMPTY = 0,
    VCS_TASKQUEUE_NOT_EXPECTED_TARGET,
    VCS_TASKQUEUE_EXPECTED_TARGET,
    VCS_TASKQUEUE_MAX
} VCODEC_SCHEDULE_TASKQUEUE_T;


typedef void (*PFN_VCODEC_INTERNAL_ADD_ITEM_T)(VCODEC_SCHEDULE_TASK_MEMBER_T, VIDEO_BUFFERHEADER_TYPE_T *);
typedef void (*PFN_VCODEC_INTERNAL_CLEAN_ITEM_T)(VCODEC_SCHEDULE_TASK_MEMBER_T, VIDEO_BUFFERHEADER_TYPE_T *);
typedef VCODEC_SCHEDULE_TASKQUEUE_T (*PFN_VCODEC_INTERNAL_GET_TASK_CTRL_T)(VCODEC_SCHEDULE_TASK_MEMBER_T);
typedef kal_int32 (*PFN_VCODEC_INTERNAL_GET_CONTINUOUS_ITEM_NUMBER_T)(VCODEC_SCHEDULE_TASK_MEMBER_T);
typedef void (*PFN_VCODEC_INTERNAL_FLUSH_ITEM_T)(VCODEC_SCHEDULE_TASK_MEMBER_T);
typedef void (*PFN_VCODEC_WAKEUP_T) (void *);


//#define VCS_ENCODE_FRAME_RATE 30
//#define VCS_DECODE_FRAME_RATE 30
#define  VCodecScheduleCtrlRingbufferSize VIDEO_ENCODER_INPUT_BUFFER_Q_NUM + VIDEO_ENCODER_YUV_HEADER_Q_NUM + VIDEO_DECODER_INPUT_BUFFER_Q_LEN + 1//VCS_ENCODE_FRAME_RATE + VCS_DECODE_FRAME_RATE + 1



typedef struct
{
    // data members
    kal_bool fgInitRingBuffer;
    VCODEC_SCHEDULE_SCENARIO_T eScenario;

    // function members
    PFN_VCODEC_INTERNAL_ADD_ITEM_T pfnAddItem;
    PFN_VCODEC_INTERNAL_CLEAN_ITEM_T pfnCleanItem;
    PFN_VCODEC_INTERNAL_GET_TASK_CTRL_T pfnGetTaskCtrl;
    PFN_VCODEC_INTERNAL_GET_CONTINUOUS_ITEM_NUMBER_T pfnGetContItemNum;
    PFN_VCODEC_INTERNAL_FLUSH_ITEM_T pfnFlushItem;
    PFN_VCODEC_WAKEUP_T pfnWakeupDEC;
    PFN_VCODEC_WAKEUP_T pfnWakeupENC;

    // Ring buffer management
#if 0
/* under construction !*/
#else
    VIDEO_CORE_RING_BUFFER_MGR_T rBufferMgr;
#endif
    VCODEC_SCHEDULE_TASK_MEMBER_T arBuffer[VCodecScheduleCtrlRingbufferSize];
    VCODEC_SCHEDULE_TASK_MEMBER_T eFlushItem;

    //Debug INof
#ifdef _VCS_DEBUG_
    kal_uint64 arTimeStamp[2][VCodecScheduleCtrlRingbufferSize];
    kal_uint8 *apu1Buffer[2][VCodecScheduleCtrlRingbufferSize];
    kal_uint32 uRead[2];
    kal_uint32 uWrite[2];
    VCODEC_SCHEDULE_TASK_MEMBER_T eLastItem;
#endif

    kal_int32 i4Item[VCS_TASK_MEMBER_MAX];
} VCODEC_SCHEDULE_CTRL_T;


#ifdef __VE_VCODEC_TASK_CONTROL__

extern void VCodecCtrlRegister(VCODEC_SCHEDULE_TASK_MEMBER_T eMember, PFN_VCODEC_WAKEUP_T pfn);
extern void VCodecCtrlDeRegister(VCODEC_SCHEDULE_TASK_MEMBER_T eMember);

extern void VCodecCtrlAddItem(VCODEC_SCHEDULE_TASK_MEMBER_T eTaskMember, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader);
extern void VCodecCtrlCleanItem(VCODEC_SCHEDULE_TASK_MEMBER_T eTaskMember, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader);
extern void VCodecCtrlMoveItem(VCODEC_SCHEDULE_TASK_MEMBER_T eTaskMember);
extern void VCodecFlushItem(VCODEC_SCHEDULE_TASK_MEMBER_T eTaskMember);
extern kal_int32 VCodecCtrlGetContinuousItemNum(VCODEC_SCHEDULE_TASK_MEMBER_T eTaskMember);
extern VCODEC_SCHEDULE_TASKQUEUE_T VCodecCtrlGetTaskControl(VCODEC_SCHEDULE_TASK_MEMBER_T eTaskMember);

#else
#define VCodecCtrlRegister(eMember, pfn) do{}while(0);
#define VCodecCtrlDeRegister(eMember) do{}while(0);
#define VCodecCtrlAddItem(eTaskMember, prBuffHeader) do{}while(0);
#define VCodecCtrlCleanItem(eTaskMember, prBuffHeader) do{}while(0);
#define VCodecCtrlMoveItem(eTaskMember) do{}while(0);
#define VCodecFlushItem(eTaskMember) do{}while(0);
#define VCodecCtrlGetContinuousItemNum(eTaskMember) 0
#define VCodecCtrlGetTaskControl(eTaskMember) VCS_TASKQUEUE_EXPECTED_TARGET
#endif

#endif /* __VE_VIDEO_ARCHI_V2__ */
#endif /* VIDEO_CODEC_SCHEDULE_CONTROL_H */

