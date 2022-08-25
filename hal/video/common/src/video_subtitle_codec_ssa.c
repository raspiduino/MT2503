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
 *   video_subtitle_codec_ssa.c
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
 *
 ****************************************************************************/

#include "drv_features_video.h"
#if defined(__VE_VIDEO_ARCHI_V2__) && defined(__VE_SUBTITLE_SUPPORT__)


#if 0  // SSA_HEADER_PARSING_IS_NOT_NEEDED
/* under construction !*/
/* under construction !*/
#endif  // SSA_HEADER_PARSING_IS_NOT_NEEDED
#include "drv_comm.h"                       // for drv_trace1(), drv_trace8()
#include "vcodec_v2_trc.h"
#include "mpl_omx_core.h"
#include "video_types_v2.h"
#include "video_buffer_management_v2.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"                // for ilm_struct
#include "video_subtitle_codec_if.h"
#include "video_subtitle_decoder_if.h"
#include "video_subtitle_codec_ssa.h"
#include "SubtitleFont_if.h"
#include "mpl_player.h"


/*****************************************************************************
* Macro(s)
*****************************************************************************/
#define VSD_SSA_EXPECTED_MAX_SUBTITLE_SIZE      512  /* This is a randomly chosen reasonable value. */


/*****************************************************************************
* Global variable(s)
*****************************************************************************/
static void *_prSubtitleHandle;
static subtitle_fontengine_struct _rFontEngineApi;


#if 0  // SSA_HEADER_PARSING_IS_NOT_NEEDED
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
#endif  // SSA_HEADER_PARSING_IS_NOT_NEEDED
static SSA_MGR_T _rSsaMgr;


/*****************************************************************************
* Macros
*****************************************************************************/
//#ifndef SSA_DEBUG_SUBTITLE
//#define SSA_DEBUG_SUBTITLE
//#endif  // SSA_DEBUG_SUBTITLE

#if defined(SSA_DEBUG_SUBTITLE)
    #define _SSA_DUMP_RAW_DATA(u4BufferSize, pu1Buffer)                                 \
    do {                                                                                \
        VEBufferTrace(TRACE_GROUP_8, VSD_SSA_DUMP_RAW_DATA, u4BufferSize, pu1Buffer);   \
    } while (0)
#else
    #define _SSA_DUMP_RAW_DATA(u4BufferSize, pu1Buffer)     do { /* empty */ } while(0)
#endif  // defined(SSA_DEBUG_SUBTITLE)


#if 0  // SSA_HEADER_PARSING_IS_NOT_NEEDED
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif  // 0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // SSA_HEADER_PARSING_IS_NOT_NEEDED


/*****************************************************************************
* After the open brace has been found, find the left-most closing brace.
* This function does not handle nested curly braces.  It simply search for the
* inner-most pair of braces.
*****************************************************************************/
static kal_bool _SSA_HasCurlyBraces(VSD_SSA_INFO_T *prSsaInfo,
        kal_uint32 *pu4OpenBraceIdx, kal_uint32 *pu4ClosingBraceIdx)
{
    #define SSA_OPEN_CURLY_BRACE_CHAR               '{'
    #define SSA_CLOSING_CURLY_BRACE_CHAR            '}'
    kal_uint8 *pu1Subtitle = prSsaInfo->pu1Subtitle;
    kal_uint32 u4SubtitleSize = prSsaInfo->u4SubtitleSize;
    kal_uint32 u4Idx;
    kal_bool fgOpenBraceFound = KAL_FALSE;
    // kal_bool fgClosingBraceFound = KAL_FALSE;
    kal_bool fgBracePairFound = KAL_FALSE;

    for (u4Idx = 0; u4Idx < u4SubtitleSize; u4Idx++)
    {
        if (pu1Subtitle[u4Idx] == SSA_OPEN_CURLY_BRACE_CHAR)
        {
            fgOpenBraceFound = KAL_TRUE;
            *pu4OpenBraceIdx = u4Idx;
        }
        else if (pu1Subtitle[u4Idx] == SSA_CLOSING_CURLY_BRACE_CHAR)
        {
            if (fgOpenBraceFound == KAL_TRUE)
            {
                // fgClosingBraceFound = KAL_TRUE;
                fgBracePairFound = KAL_TRUE;
                *pu4ClosingBraceIdx = u4Idx;
                break;  // Break out of "for" loop.
            }
        }
        else
        {
            /* Do nothing. */
        }
    }

    if (fgBracePairFound == KAL_TRUE)
    {
        if (*pu4OpenBraceIdx >= *pu4ClosingBraceIdx ||
            *pu4OpenBraceIdx >= u4SubtitleSize ||
            *pu4ClosingBraceIdx >= u4SubtitleSize)
        {
            ASSERT(0);
        }
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
* Side effect: the array pointed to by pu1Subtitle, pu4SubtitleSize
*****************************************************************************/
static void _SSA_RemoveCurlyBraces(VSD_SSA_INFO_T *prSsaInfo,
        kal_uint32 u4OpenBraceIdx, kal_uint32 u4ClosingBraceIdx)
{
    kal_uint8 *pu1Subtitle = prSsaInfo->pu1Subtitle;
    kal_uint32 u4SubtitleSize = prSsaInfo->u4SubtitleSize;
    kal_uint32 u4LengthOfBraces = u4ClosingBraceIdx - u4OpenBraceIdx + 1;

    if (u4SubtitleSize < u4LengthOfBraces) { ASSERT(0); }
    drv_trace2(TRACE_GROUP_9, VSD_SSA_REMOVE_CURLY_BRACES,
        u4SubtitleSize, u4LengthOfBraces);

    u4ClosingBraceIdx++;  // Point to the character following the char '}'.
    while (u4ClosingBraceIdx < u4SubtitleSize)
    {
        pu1Subtitle[u4OpenBraceIdx++] = pu1Subtitle[u4ClosingBraceIdx++];
    }

    u4SubtitleSize -= u4LengthOfBraces;
    prSsaInfo->u4SubtitleSize = u4SubtitleSize;
}


/*****************************************************************************
*
*****************************************************************************/
static void _SSA_RemoveOverride(VSD_SSA_INFO_T *prSsaInfo)
{
    kal_uint32 u4OpenBraceIdx = 0, u4ClosingBraceIdx = 0;

    while (_SSA_HasCurlyBraces(prSsaInfo, &u4OpenBraceIdx, &u4ClosingBraceIdx) == KAL_TRUE)
    {
        drv_trace2(TRACE_GROUP_9, VSD_SSA_INDEX_OF_BRACES, u4OpenBraceIdx, u4ClosingBraceIdx);
        _SSA_RemoveCurlyBraces(prSsaInfo, u4OpenBraceIdx, u4ClosingBraceIdx);
    }
}


/*****************************************************************************
* Replace each '\n' and '\N' with a character sequence '0x0D 0x0A'.
*****************************************************************************/
static void _SSA_ReplaceBackslashN(VSD_SSA_INFO_T *prSsaInfo)
{
    kal_uint8 *pu1Subtitle = prSsaInfo->pu1Subtitle;
    kal_uint32 u4SubtitleSize = prSsaInfo->u4SubtitleSize;
    kal_uint32 u4Idx, u4NextIdx;

    for (u4Idx = 0; u4Idx < u4SubtitleSize; u4Idx++)
    {
        if (pu1Subtitle[u4Idx] == '\\')
        {
            u4NextIdx = u4Idx + 1;
            if (u4NextIdx < u4SubtitleSize)
            {
                if (pu1Subtitle[u4NextIdx] == 'n' ||
                    pu1Subtitle[u4NextIdx] == 'N')
                {
                    pu1Subtitle[u4Idx] = (kal_uint8)0x0D;
                    pu1Subtitle[u4NextIdx] = (kal_uint8)0x0A;
                    drv_trace2(TRACE_GROUP_9, VSD_SSA_INDEX_OF_BACKSLASH_N, u4Idx, u4NextIdx);
                }
            }
        }
    }
}


#if 0  // SSA_HEADER_PARSING_IS_NOT_NEEDED
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
/* under construction !*/
/* under construction !*/
#endif  // SSA_HEADER_PARSING_IS_NOT_NEEDED


/*****************************************************************************
* 1. Extract "style name".
* 2. Match extracted "style name" to the table of style names.
* 3. Extract subtitle text.
* 4. Convert "new line / carriage return" to "carriage return".
* 5. Call font engine API to draw subtitle text.
*****************************************************************************/
static void _SSA_EVENT_DrawText(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader,
        VIDEO_BUFFERHEADER_TYPE_T *prDestBuffHeader)
{
#if 0  // SSA_HEADER_PARSING_IS_NOT_NEEDED
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
#else
    SSA_DEFAULT_STYLE_T* const prDefaultStyle = &_rSsaMgr.rDefaultStyle;
    kal_uint32 *pu4Buffer = (kal_uint32*)(prDestBuffHeader->pu1Buffer);
    kal_uint32 u4BufferSize = prDestBuffHeader->u4BuffSize;
    kal_uint32 u4Offset, u4MaxOffset;
    kal_uint32 u4FontColor = 0xFFFFFFFF;
    kal_uint32 u4FontSize = prDefaultStyle->u4FontSize;
    SUBTITLE_OP_T eOp;
    SUBTITLE_ENCODING_T eEncoding = SUBTITLE_ENCODING_UTF8;
    SUBTITLE_HORIZONTAL_ALIGNMENT_T eHAlignment = SUBTITLE_HORIZONTAL_ALIGNMENT_CENTER;
    SUBTITLE_VERTICAL_ALIGNMENT_T eVAlignment = SUBTITLE_VERTICAL_ALIGNMENT_TOP;
    SUBTITLE_STYLE_T eStyle = SUBTITLE_STYLE_BORDER;            // FIXME
    SUBTITLE_FONT_EFFECT_T eFontEffect = SUBTITLE_EFFECT_NONE;  // FIXME
    SUBTITLE_BOUNDARY_RECT_T rBoundaryRect;

    switch (prDefaultStyle->eEncoding)
    {
    case VSD_ENCODING_UTF8:
        eEncoding = SUBTITLE_ENCODING_UTF8;
        break;

    default:
        ASSERT(0);
        break;
    }

    switch (prDefaultStyle->eHorizontalAlignment)
    {
    case VSD_HORIZONTAL_ALIGNMENT_LEFT:
        eHAlignment = SUBTITLE_HORIZONTAL_ALIGNMENT_LEFT;
        break;

    case VSD_HORIZONTAL_ALIGNMENT_RIGHT:
        eHAlignment = SUBTITLE_HORIZONTAL_ALIGNMENT_RIGHT;
        break;

    case VSD_HORIZONTAL_ALIGNMENT_CENTER:
        eHAlignment = SUBTITLE_HORIZONTAL_ALIGNMENT_CENTER;
        break;

    default:
        ASSERT(0);
        break;
    }

    switch (prDefaultStyle->eVerticalAlignment)
    {
    case VSD_VERTICAL_ALIGNMENT_TOP:
        eVAlignment = SUBTITLE_VERTICAL_ALIGNMENT_TOP;
        break;

    case VSD_VERTICAL_ALIGNMENT_MID:
        eVAlignment = SUBTITLE_VERTICAL_ALIGNMENT_CENTER;
        break;

    case VSD_VERTICAL_ALIGNMENT_BOTTOM:
        eVAlignment = SUBTITLE_VERTICAL_ALIGNMENT_BOTTOM;
        break;

    default:
        ASSERT(0);
        break;
    }

    // Set frame buffer to transparent color.
    if ((kal_uint32)pu4Buffer % 4 != 0) { ASSERT(0); }
    if (u4BufferSize % 4 != 0) { ASSERT(0); }
    u4MaxOffset = u4BufferSize / 4;
    for (u4Offset = 0; u4Offset < u4MaxOffset; u4Offset++)
    {
        pu4Buffer[u4Offset] = 0x00000000;
    }

    eOp = SUBTITLE_OP_ENCODING;
    _rFontEngineApi.pfnSetProp((void*)_prSubtitleHandle, eOp, (void*)&eEncoding, sizeof(eEncoding));

    eOp = SUBTITLE_OP_HORIZONTAL_ALIGNMENT;
    _rFontEngineApi.pfnSetProp((void*)_prSubtitleHandle, eOp, (void*)&eHAlignment, sizeof(eHAlignment));

    eOp = SUBTITLE_OP_VERTICAL_ALIGNMENT;
    _rFontEngineApi.pfnSetProp((void*)_prSubtitleHandle, eOp, (void*)&eVAlignment, sizeof(eVAlignment));

    eOp = SUBTITLE_OP_FONT_COLOR;
    _rFontEngineApi.pfnSetProp((void*)_prSubtitleHandle, eOp, (void*)&u4FontColor, sizeof(u4FontColor));

    if (u4FontSize < 10 || u4FontSize > 40) { ASSERT(0); }
    eOp = SUBTITLE_OP_FONT_SIZE;
    _rFontEngineApi.pfnSetProp((void*)_prSubtitleHandle, eOp, (void*)&u4FontSize, sizeof(u4FontSize));

    eOp = SUBTITLE_OP_FONT_STYLE;
    _rFontEngineApi.pfnSetProp((void*)_prSubtitleHandle, eOp, (void*)&eStyle, sizeof(eStyle));

    eOp = SUBTITLE_OP_FONT_EFFECT;
    _rFontEngineApi.pfnSetProp((void*)_prSubtitleHandle, eOp, (void*)&eFontEffect, sizeof(eFontEffect));

    eOp = SUBTITLE_OP_STRING;

    if (_rSsaMgr.eCodec == VSD_CODEC_UTF8 || _rSsaMgr.eCodec == VSD_CODEC_SRT)
    {
        _rFontEngineApi.pfnSetProp((void*)_prSubtitleHandle, eOp, (void*)(prBuffHeader->pu1Buffer), prBuffHeader->u4BuffSize);
        drv_trace2(TRACE_GROUP_9, VSD_SSA_SUBTITLE_INFO,
            (kal_uint32)(prBuffHeader->u8TimeStamp),
            prBuffHeader->u4BuffSize);
        _SSA_DUMP_RAW_DATA(prBuffHeader->u4BuffSize, prBuffHeader->pu1Buffer);
    }
    else if (_rSsaMgr.eCodec == VSD_CODEC_SSA_ASS)
    {
        SPIF_DECODE_PAYLOAD_T *prPayload = prBuffHeader->pPrivateData;
        VSD_SSA_INFO_T *prSsaInfo = prPayload->pu1PayloadAddress;

        if (prSsaInfo->u4SubtitleSize > VSD_SSA_EXPECTED_MAX_SUBTITLE_SIZE)
        {
            drv_trace2(TRACE_GROUP_9, VSD_SSA_EXCEED_MAX_SUBTITLE_LEN,
                (kal_uint32)(prBuffHeader->u8TimeStamp),
                prSsaInfo->u4SubtitleSize);
        }
        else
        {
            drv_trace2(TRACE_GROUP_9, VSD_SSA_SUBTITLE_INFO,
                (kal_uint32)(prBuffHeader->u8TimeStamp),
                prSsaInfo->u4SubtitleSize);
            _SSA_DUMP_RAW_DATA(prSsaInfo->u4SubtitleSize, prSsaInfo->pu1Subtitle);
            _SSA_RemoveOverride(prSsaInfo);
            _SSA_ReplaceBackslashN(prSsaInfo);
        }
        drv_trace2(TRACE_GROUP_9, VSD_SSA_SUBTITLE_INFO,
            (kal_uint32)(prBuffHeader->u8TimeStamp),
            prSsaInfo->u4SubtitleSize);
        _SSA_DUMP_RAW_DATA(prSsaInfo->u4SubtitleSize, prSsaInfo->pu1Subtitle);
        _rFontEngineApi.pfnSetProp((void*)_prSubtitleHandle, eOp, (void*)(prSsaInfo->pu1Subtitle), prSsaInfo->u4SubtitleSize);
    }
    else
    {
        // FIXME: Print a log here.
    }

    eOp = SUBTITLE_OP_BOUNDARY_RECT;
    rBoundaryRect.u4Height = _rSsaMgr.u4Height;
    rBoundaryRect.u4Width = _rSsaMgr.u4Width;
    rBoundaryRect.pu1Buffer = prDestBuffHeader->pu1Buffer;
    rBoundaryRect.u4BufferSize = prDestBuffHeader->u4BuffSize;
    _rFontEngineApi.pfnSetProp((void*)_prSubtitleHandle, eOp, (void*)&rBoundaryRect, sizeof(rBoundaryRect));

    _rFontEngineApi.pfnDraw((void*)_prSubtitleHandle);
    drv_trace0(TRACE_GROUP_10, VSD_SSA_DRAW_SUBTITLE_TEXT);
#endif  // SSA_HEADER_PARSING_IS_NOT_NEEDED
}


/*****************************************************************************
*
*****************************************************************************/
static VIDEO_ERROR_TYPE_T _SSA_Open(void)
{
    return VIDEO_ERROR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
static VIDEO_ERROR_TYPE_T _SSA_Init(VSD_CODEC_INIT_T *pvInitStruct)
{
    memset((void*)&_rSsaMgr, 0, sizeof(_rSsaMgr));
#if 0  // SSA_HEADER_PARSING_IS_NOT_NEEDED
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // SSA_HEADER_PARSING_IS_NOT_NEEDED

    return VIDEO_ERROR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
static VIDEO_ERROR_TYPE_T _SSA_GetParam(VSD_CODEC_OP_T eOp, void *pvParam)
{
    return VIDEO_ERROR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
static VIDEO_ERROR_TYPE_T _SSA_SetParam(VSD_CODEC_OP_T eOp, void *pvParam)
{
    SSA_DEFAULT_STYLE_T* const prDefaultStyle = &_rSsaMgr.rDefaultStyle;

    switch (eOp)
    {
    case VSD_CODEC_OP_RESOLUTION:
        {
            VSD_RESOLUTION_T *prResolution = (VSD_RESOLUTION_T*)pvParam;
            _rSsaMgr.u4Width = prResolution->u4Width;
            _rSsaMgr.u4Height = prResolution->u4Height;
            drv_trace2(TRACE_GROUP_10, VSD_SSA_SET_RESOLUTION, prResolution->u4Width, prResolution->u4Height);
        }
        break;

    case VSD_CODEC_OP_FONT_ENCODING:
        {
            VSD_ENCODING_T *peEncoding = (VSD_ENCODING_T*)pvParam;
            prDefaultStyle->eEncoding = *peEncoding;
        }
        break;

    case VSD_CODEC_OP_FONT_SIZE:
        {
            kal_uint32 *pu4FontSize = (kal_uint32*)pvParam;
            prDefaultStyle->u4FontSize = *pu4FontSize;
            drv_trace1(TRACE_GROUP_10, VSD_SSA_SET_FONT_SIZE, prDefaultStyle->u4FontSize);
        }
        break;

    case VSD_CODEC_OP_COLORS:
        {
            VSD_COLORS_T *prColors = (VSD_COLORS_T*)pvParam;
            prDefaultStyle->u4PriColor = prColors->u4PriColor;
            prDefaultStyle->u4BackColor = prColors->u4BackColor;
            // prDefaultStyle->u4AlphaLevel = prColors->u4AlphaLevel;
        }
        break;

#if 0  // Display location is set to Render by MPL.
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // 0

    case VSD_CODEC_OP_ALIGNMENT:
        {
            VSD_ALIGNMENT_T *prAlignment = (VSD_ALIGNMENT_T*)pvParam;
            prDefaultStyle->eHorizontalAlignment = prAlignment->eHorizontalAlignment;
            prDefaultStyle->eVerticalAlignment = prAlignment->eVerticalAlignment;
        }
        break;

    case VSD_CODEC_OP_FONT_STYLES:
        {
            VSD_FONT_STYLES_T *prFontStyles = (VSD_FONT_STYLES_T*)pvParam;
            prDefaultStyle->fgBold = prFontStyles->fgBold;
            prDefaultStyle->fgItalic = prFontStyles->fgItalic;
            prDefaultStyle->fgUnderline = prFontStyles->fgUnderline;
            prDefaultStyle->fgStrikeOut = prFontStyles->fgStrikeOut;
            prDefaultStyle->fgOutline = prFontStyles->fgOutline;
            prDefaultStyle->fgShadow = prFontStyles->fgShadow;
        }
        break;

    case VSD_CODEC_OP_FONT_ENGINE_API:
        {
            subtitle_fontengine_struct *prFontEngineApi = (subtitle_fontengine_struct*)pvParam;
            _rFontEngineApi = *prFontEngineApi;
            _rFontEngineApi.pfnOpen((void**)&_prSubtitleHandle);
            _rFontEngineApi.pfnInit((void*)_prSubtitleHandle, NULL, 0);
        }
        break;

    default:
        break;
    }

    return VIDEO_ERROR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
static VIDEO_ERROR_TYPE_T _SSA_ProcessData(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader,
        VIDEO_BUFFERHEADER_TYPE_T *prDestBuffHeader)
{
    if (prBuffHeader->eFlags == VIDEO_BUFFERFLAG_PARAMETERSET)
    {
        // Process SSA/ASS header.
        drv_trace2(TRACE_GROUP_10, VSD_SSA_PROCESS_HEADER,
            (kal_uint32)(prBuffHeader->pu1Buffer), prBuffHeader->u4BuffSize);
#if 0  // SSA_HEADER_PARSING_IS_NOT_NEEDED
/* under construction !*/
/* under construction !*/
#endif  // SSA_HEADER_PARSING_IS_NOT_NEEDED
    }
    else
    {
        drv_trace2(TRACE_GROUP_10, VSD_SSA_PROCESS_SUBTITLE,
            (kal_uint32)(prBuffHeader->pu1Buffer), prBuffHeader->u4BuffSize);
        _SSA_EVENT_DrawText(prBuffHeader, prDestBuffHeader);
    }

    return VIDEO_ERROR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
static VIDEO_ERROR_TYPE_T _SSA_DeInit(void)
{
    if (_rFontEngineApi.pfnDeinit != NULL)
    {
        _rFontEngineApi.pfnDeinit((void*)_prSubtitleHandle, NULL, 0);
    }
    if (_rFontEngineApi.pfnClose != NULL)
    {
        _rFontEngineApi.pfnClose((void**)&_prSubtitleHandle);
    }

    return VIDEO_ERROR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
static VIDEO_ERROR_TYPE_T _SSA_Close(void)
{
    return VIDEO_ERROR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
const static VSD_CODEC_API_T _rSsaApi =
{
    /* The compiler does not compliant to the C99 standard! @_@ */
    /*.pfnOpen        =*/ _SSA_Open,
    /*.pfnInit        =*/ _SSA_Init,
    /*.pfnGetParam    =*/ _SSA_GetParam,
    /*.pfnSetParam    =*/ _SSA_SetParam,
    /*.pfnProcessData =*/ _SSA_ProcessData,
    /*.pfnDeInit      =*/ _SSA_DeInit,
    /*.pfnClose       =*/ _SSA_Close
};


/*****************************************************************************
*
*****************************************************************************/
VSD_CODEC_API_T* GetVsdSsaCodecApi(VSD_CODEC_T eVsdCodec)
{
    VSD_CODEC_API_T *prSsaApi = (VSD_CODEC_API_T*)&_rSsaApi;

    _rSsaMgr.eCodec = eVsdCodec;
    /*
    VIDEO_ERROR_TYPE_T eError;
    VSD_CODEC_INIT_T rInitStruct;

    _rSsaMgr.prExtMemInfo = prExtMemInfo;

    eError = prSsaApi->pfnOpen();
    if (eError != VIDEO_ERROR_NONE)
    {
        prSsaApi = NULL;
    }
    else
    {
        kal_mem_set((void*)&rInitStruct, 0, sizeof(rInitStruct));  // FIXME: Does init() need to have parameter???
        eError = prSsaApi->pfnInit(&rInitStruct);
        if (eError != VIDEO_ERROR_NONE)
        {
            prSsaApi = NULL;
        }
    }
    */

    return prSsaApi;
}


/*****************************************************************************
*
*****************************************************************************/
VIDEO_ERROR_TYPE_T ReleaseVsdSsaCodecApi(VSD_CODEC_API_T *prHandle)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    /*
    if (prHandle == NULL)
    {
        ASSERT(0);
    }
    else
    {
        eError = prHandle->pfnDeInit();
        if (eError == VIDEO_ERROR_NONE)
        {
            eError = prHandle->pfnClose();
        }
    }
    */
    return eError;
}


#endif  // defined(__VE_VIDEO_ARCHI_V2__) && defined(__VE_SUBTITLE_SUPPORT__)

