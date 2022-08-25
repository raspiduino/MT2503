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
 *   video_OAL_v2.h
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
 ****************************************************************************/
 #ifndef VIDEO_OAL_V2_H
#define VIDEO_OAL_V2_H

#include "vcodec_if.h"
#include "vcodec_log.h"

extern void VideoQueryMemType(void *pBuffer_VA, unsigned int u4Size, VCODEC_MEMORY_TYPE_T *peMemType);
extern void VideoQueryPhysicalAddr(void *pBuffer_VA, void **pBufferOut_PA);
extern int VideoSwitchMemType(void *pBuffer_VA, unsigned int u4Size, VCODEC_MEMORY_TYPE_T eMemType, void **pBufferOut_VA);
extern void VideoFlushCachedBuffer(void *pBuffer_VA, unsigned int u4Size);
extern void VideoInvalidateCachedBuffer(void *pBuffer_VA, unsigned int u4Size);
extern void VideoMemSet(void *pBuffer_VA, char cValue, unsigned int u4Length);
extern void VideoMemCopy(void *pvDest , const void *pvSrc, unsigned int u4Length);
extern void VideoAssertFail(char *ptr, int i4Line, int i4Arg);
extern void VideoFlushCachedBufferAll(void);
extern void VideoInvalidateCachedBufferAll(void);
extern void VideoFlushInvalidateCacheBufferAll(void);
extern void VideoTraceLog0(VCODEC_LOG_GROUP_T eGroup, VCODEC_LOG_INDEX_T eIndex);
extern void VideoTraceLog1(VCODEC_LOG_GROUP_T eGroup, VCODEC_LOG_INDEX_T eIndex, UINT64 arg);
extern void VideoTraceLog2(VCODEC_LOG_GROUP_T eGroup, VCODEC_LOG_INDEX_T eIndex, UINT64 arg1, UINT64 arg2);
extern void VideoTraceLog4(VCODEC_LOG_GROUP_T eGroup, VCODEC_LOG_INDEX_T eIndex, UINT64 arg1, UINT64 arg2, UINT64 arg3, UINT64 arg4);
extern void VideoTraceLog8(VCODEC_LOG_GROUP_T eGroup, VCODEC_LOG_INDEX_T eIndex, UINT64 arg1, UINT64 arg2, UINT64 arg3, UINT64 arg4, UINT64 arg5, UINT64 arg6, UINT64 arg7, UINT64 arg8);

#endif /* VIDEO_OAL_V2_H */
