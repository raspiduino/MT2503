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
 *   video_render_component_v2.h
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
 ****************************************************************************/
#ifndef VIDEO_RENDER_COMPONENT_V2_H
#define VIDEO_RENDER_COMPONENT_V2_H
#ifdef __VIDEO_ARCHI_V2__
#include "video_types_v2.h"
#include "video_comm_component_v2.h"

extern VIDEO_COMPONENT_TYPE_T* GetVideoRenderHandle(VIDEO_RENDER_TYPE_T eType);
extern VIDEO_ERROR_TYPE_T ReleaseVideoRenderHandle(VIDEO_COMPONENT_TYPE_T *prHandle);

typedef enum
{
    VIDEO_RENDER_MODE_NONE,
    VIDEO_RENDER_MODE_SW,
    VIDEO_RENDER_MODE_HW
}VIDEO_RENDER_MODE_T;

typedef struct
{
    kal_uint32  u4VideoWidth;
    kal_uint32  u4VideoHeight;
    
}VIDEO_RENDER_CONFIG_DATA_T;

typedef struct
{
    VIDEO_COMM_STATE_T rCommState;
    kal_timerid eTimerID;
    kal_uint32 u4TimerTick;

    kal_uint8 u1GPTHandle;
    
    VIDEO_RENDER_MODE_T eMode;
    kal_bool fgEnableDisplay;
    VIDEO_BUFFERHEADER_TYPE_T rDisplayBuff;
    VIDEO_BUFFERHEADER_TYPE_T rNextDisplayBuff;

    VIDEO_RENDER_CONFIG_DATA_T rConfigData;

    kal_uint32 u4ReEntryProtect;
}VIDEO_RENDER_TEST_STATE_T;

extern VIDEO_COMPONENT_TYPE_T rVideoRenderTestComp;
#endif /*__VIDEO_ARCHI_V2__*/
#endif /* VIDEO_REDNER_COMPONENT_V2_H */ 

