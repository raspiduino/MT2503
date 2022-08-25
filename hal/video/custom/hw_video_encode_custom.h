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
 *   hw_video_encode_custom_v2.h
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
 ****************************************************************************/

#ifndef HW_VIDEO_ENC0DE_CUSTOM_H
#define HW_VIDEO_ENC0DE_CUSTOM_H

#include "drv_comm.h"
#ifdef __VIDEO_ARCHI_V2__
#include "drv_features_video.h"
#include "video_codec_custom_type.h"
#include "hal_custom_video_if.h"

#ifdef __MPEG4_ENC_HW_SUPPORT__
#include "MPEG4HWEncMem.h"
#endif

/***********************************************************************
*
*   Custom settings of
*   - The numbers of frame buffer
*   - Maximum resolution supported
*
***********************************************************************/

/******************************************************************************
* Setting for MT6268 series
******************************************************************************/
#if (defined(MT6268))
    #ifdef __MPEG4_ENC_HW_SUPPORT__
        /* This is the maximum resolution supported by the encoder. */
        //#define MPEG4_HW_ENC_SUPPORT_RESOLUTION        RESOLUTION_720x576
        #define MPEG4_HW_ENC_MAX_WIDTH         720
        #define MPEG4_HW_ENC_MAX_HEIGHT        480
        #define MPEG4_HW_ENC_WORKING_MEM_SIZE  ENC_EXT_WORK_MEMORY
    #endif  // __MPEG4_ENC_HW_SUPPORT__
#endif  // (defined(MT6268))

/******************************************************************************
* Settings of video call
******************************************************************************/

#ifdef __VIDEO_VT_SUPPORT__
    #ifdef __MPEG4_ENC_HW_SUPPORT__
        #define MPEG4_ENC_VT_MAX_WIDTH         176
        #define MPEG4_ENC_VT_MAX_HEIGHT        144
        #define MPEG4_ENC_VT_WORKING_MEM_SIZE ENC_MAX_EXT_MEMORY(MPEG4_ENC_VT_MAX_WIDTH, MPEG4_ENC_VT_MAX_HEIGHT)+ENC_MAX_RESUME_BUFFER_SIZE
    #endif
#endif //__VIDEO_VT_SUPPORT__

/******************************************************************************
* Replace with custom setting
******************************************************************************/

#endif /* __VIDEO_ARCHI_V2__ */
#endif /* HW_VIDEO_ENC0DE_CUSTOM_H */

