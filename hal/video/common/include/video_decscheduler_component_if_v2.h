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
 *  video_decscheduler_component_if_v2.h
 *
 * Project:
 * --------
 *	MAUI - Video Architecture 2
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
 *
 *
 ****************************************************************************/

#ifndef VIDEO_DECSCHEDULER_COMPONENT_IF_V2_H
#define VIDEO_DECSCHEDULER_COMPONENT_IF_V2_H

#include "video_types_v2.h"

#include "video_buffer_management_v2.h"

#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__

#define VIDEO_DECSCHEDULER_INPUT_QUEUE_SIZE        10
#define VIDEO_DECSCHEDULER_OUTPUT_QUEUE_SIZE       10
#define VIDEO_DECSCHEDULER_MGR_LEN 1024

#define V2SCH_EXT_MEM_SIZE (VIDEO_DECSCHEDULER_INPUT_QUEUE_SIZE *VIDEO_COMM_INPUT_Q_ITEM_SIZE +     \
                                         VIDEO_DECSCHEDULER_OUTPUT_QUEUE_SIZE * VIDEO_COMM_OUTPUT_Q_ITEM_SIZE + VIDEO_DECSCHEDULER_MGR_LEN + 512)

//////////////////////////////////////////////////////////
//    Internal Functions
//////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////
//    External Functions
//////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////
//              Component functions
//////////////////////////////////////////////////////////

extern VIDEO_COMPONENT_TYPE_T* GetVideoDecSchedulerHandle(VIDEO_SCHEDULER_TYPE_T rType, VIDEO_EXTMEM_HANDLER_T* prExtMemHdr);
extern VIDEO_ERROR_TYPE_T ReleaseVideoDecSchedulerHandle(VIDEO_COMPONENT_TYPE_T *prHandle);


#endif /* __VE_VIDEO_ARCHI_V2__ */
#endif //VIDEO_DECSCHEDULER_COMPONENT_IF_V2_H
