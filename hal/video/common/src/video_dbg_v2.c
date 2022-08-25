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
 *   video_dbg_v2.c
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
#ifdef __VE_VIDEO_ARCHI_V2__

#include "video_dbg_v2.h"

/* The following files are newly added for RHR. */
// #include "kal_release.h"      /* Basic data type */
// #include "stack_common.h"
// #include "stack_msgs.h"
// #include "app_ltlcom.h"       /* Task message communiction */
// #include "tst_ltlcom.h"
// #include "syscomp_config.h"
// #include "task_config.h"      /* Task creation */
// #include "stacklib.h"         /* Basic type for dll, evshed, stacktimer */
// #include "event_shed.h"       /* Event scheduler */
// #include "stack_timer.h"      /* Stack timer */
// #include "video_types_v2.h"
// #include "kal_non_specific_general_types.h"
#include "SST_sla.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"

extern kal_uint32 SaveAndSetIRQMask(void);
extern void RestoreIRQMask(kal_uint32);
extern kal_bool INT_QueryExceptionStatus(void);

#ifndef __VE_SLIM_PROJECT__
static VIDEO_ERROR_ARRAY_T rVideoAssert;
#endif
static VIDEO_DBG_ARRAY_T rVideoDbg;

#ifndef __VE_SLIM_PROJECT__
void video_warning(VIDEO_DBG_OWNER_T eOwner, kal_uint32 u4Line)
{
    VIDEO_ERROR_STRUCT_T *prError = NULL;

    switch(eOwner)
    {
    case VIDEO_DBG_OWNER_FILEREADER:
    case VIDEO_DBG_OWNER_FILEWRITER:
        prError = &rVideoAssert.rFileError;
        break;
    case VIDEO_DBG_OWNER_DECODER:
    case VIDEO_DBG_OWNER_ENCODER:
        prError = &rVideoAssert.rCodecError;
        break;
    case VIDEO_DBG_OWNER_ENCSRC:
        prError = &rVideoAssert.rEncSrcError;
        break;
    case VIDEO_DBG_OWNER_CONTROL:
        prError = &rVideoAssert.rControlError;
        break;
    default:
        EXT_ASSERT(0, eOwner, u4Line, 0);
        break;
    }

    if (prError)
    {
        prError->au4ErrorLine[prError->u4ErrorIndex] = u4Line;
        prError->u4ErrorIndex = (prError->u4ErrorIndex+1)%MAX_VIDEO_ERROR_LINE;
    }
}
#endif

void video_dbg_trace(VIDEO_DBG_OWNER_T eOwner, VIDEO_DBG_ID_T eID, kal_uint32 u4Param)
{
    kal_uint16 u2Index;
    kal_uint32 u4IRQMask;
    VIDEO_DBG_STRUCT_T *prDbg = NULL;
    kal_uint32 u4DbgIndex;

    switch(eOwner)
    {
#ifndef __VE_SLIM_PROJECT__    
    case VIDEO_DBG_OWNER_FILEREADER:
    case VIDEO_DBG_OWNER_FILEWRITER:
    case VIDEO_DBG_OWNER_CONTROL:
    case VIDEO_DBG_OWNER_RMPROVIDER:
        prDbg = &rVideoDbg.rCtrlFileDbg;
        break;
    case VIDEO_DBG_OWNER_DECODER:
    case VIDEO_DBG_OWNER_ENCODER:
        prDbg = &rVideoDbg.rCodecDbg;
        break;
#endif		
    case VIDEO_DBG_OWNER_DECSCHEDULER:
    case VIDEO_DBG_OWNER_ENCSRC:
        prDbg = &rVideoDbg.rSchClkSrcDbg;
        break;
    default:
        break;
    }

    if (!prDbg)
    {
        return;
    }

    u4IRQMask=SaveAndSetIRQMask();
    if(rVideoDbg.u2Index == 0)
    {
        rVideoDbg.u2Index = (rVideoDbg.u2Index+1)&0xffff;
    }
    u2Index = rVideoDbg.u2Index;
    rVideoDbg.u2Index = (rVideoDbg.u2Index+1)&0xffff;
    u4DbgIndex = prDbg->u4DbgIndex;
    prDbg->u4DbgIndex = (prDbg->u4DbgIndex+1)%MAX_VIDEO_DBG_ENTRY;

    RestoreIRQMask(u4IRQMask);

    prDbg->arDbgData[u4DbgIndex].eTag = eID;
    prDbg->arDbgData[u4DbgIndex].u2Index= u2Index;
    prDbg->arDbgData[u4DbgIndex].u4Param = u4Param;

}

/* Empty function for legacy interface adaptation */
void VIDEO_DbgInfo(kal_uint32 * data1, kal_uint32 * data2, kal_uint32 * data3, kal_uint32 * data4,
                   kal_uint32 * data_index)
{
    return;
}

void VideoStartLogging(kal_char *pcCustomJob)
{
#if defined(__MTK_TARGET__) && defined(__MTK_INTERNAL__)
/* under construction !*/
#endif
}

void VideoStopLogging(kal_char *pcCustomJob)
{
#if defined(__MTK_TARGET__) && defined(__MTK_INTERNAL__)
/* under construction !*/
#endif
}

void VideoLabelLogging(kal_char *pcCustomJob)
{
#if defined(__MTK_TARGET__) && defined(__MTK_INTERNAL__)
/* under construction !*/
#endif
}

#define MAX_PS_BUFFER_SIZE 512

void VEBufferTrace(trace_class_enum eTrcClass, kal_uint32 u4MsgIdx, const char *pcArgType, kal_uint32 u4BuffSize, kal_uint8* pu1Buff)
{
    kal_uint32  u4BuffSizeToWrite = u4BuffSize;

    if (INT_QueryExceptionStatus())
    {
        return;
    }
    if(kal_if_lisr() == KAL_TRUE)
    {
        return;
    }

    while(u4BuffSizeToWrite > MAX_PS_BUFFER_SIZE)
    {
        kal_buffer_trace(eTrcClass, u4MsgIdx, pcArgType, MAX_PS_BUFFER_SIZE, pu1Buff + u4BuffSize - u4BuffSizeToWrite);
        u4BuffSizeToWrite -= MAX_PS_BUFFER_SIZE;
    }

    if (u4BuffSizeToWrite > 0)
    {
        kal_buffer_trace(eTrcClass, u4MsgIdx, pcArgType, u4BuffSizeToWrite, pu1Buff + u4BuffSize - u4BuffSizeToWrite);
    }
}

#endif /* __VE_VIDEO_ARCHI_V2__ */
