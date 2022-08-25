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
 *   video_subtitle_decoder_if.h
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
 *
 ****************************************************************************/
#ifndef VIDEO_SUBTITLE_DECODER_IF_H
#define VIDEO_SUBTITLE_DECODER_IF_H


#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__


#include "video_types_v2.h"
#include "video_buffer_management_v2.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"                // for ilm_struct
#include "video_subtitle_codec_if.h"
#include "mpl_player.h"
#include "cache_sw.h"                       // for CPU_CACHE_LINE_SIZE


/******************************************************************************
* Definitions
* The term RAW represens an uncompressed frame.
******************************************************************************/
#define VSD_LUMP_BYTES_PER_PIXEL        4       /* ARGB8888 */
#define VSD_LUMP_ONE_FRAME_SIZE         (VIDEO_SUBTITLE_RECT_MAX_WIDTH * VIDEO_SUBTITLE_RECT_MAX_HEIGHT * VSD_LUMP_BYTES_PER_PIXEL)
#define VSD_LUMP_TOTAL_MEM_SIZE         (kal_uint32)((CPU_CACHE_LINE_SIZE + VSD_LUMP_ONE_FRAME_SIZE) * VIDEO_SUBTITLE_MAX_FRAMES)
// FIXME: Use VSD_LUMP_TOTAL_MEM_SIZE to calculate memory size in Decoder header file.

#define VSD_ONE_COMMAND_SIZE            20
#define VSD_ONE_INPUT_SIZE              40
#define VSD_ONE_OUTPUT_SIZE             40

#define VSD_COMMAND_Q_LEN               5
#define VSD_INPUT_BUFFER_Q_LEN          5
#define VSD_OUTPUT_BUFFER_Q_LEN         5
#define VSD_BACK_END_RESEND_Q_LEN       5
#define VSD_FRONT_END_RESEND_Q_LEN      5


/******************************************************************************
* If the support of subtitle is turned off, memory consumption shall be 0.
******************************************************************************/
#ifdef __VE_SUBTITLE_SUPPORT__
#define VSD_TOTAL_MEM_SIZE      (VSD_LUMP_TOTAL_MEM_SIZE +                      \
                                 VSD_ONE_COMMAND_SIZE * VSD_COMMAND_Q_LEN +     \
                                 VSD_ONE_INPUT_SIZE * VSD_INPUT_BUFFER_Q_LEN +  \
                                 VSD_ONE_OUTPUT_SIZE * VSD_OUTPUT_BUFFER_Q_LEN)
#else
#define VSD_TOTAL_MEM_SIZE              0
#endif  // __VE_SUBTITLE_SUPPORT__


// ReadOrder, Layer, Name, and Effect are not supported.
typedef struct
{
    kal_uint32 u4LeftMargin;
    kal_uint32 u4RightMargin;
    kal_uint32 u4VerticalMargin;
    kal_uint32 u4StyleSize;             // Size of the string pointed to by pu1Style
    kal_uint8 *pu1Style;
    kal_uint32 u4SubtitleSize;          // Size of the string pointed to by pu1Subtitle
    kal_uint8 *pu1Subtitle;
} VSD_SSA_INFO_T;


/******************************************************************************
* Function prototypes
******************************************************************************/
extern VIDEO_COMPONENT_TYPE_T* GetVsdHandle(VIDEO_EXTMEM_HANDLER_T* prExtMemHdr);
extern VIDEO_ERROR_TYPE_T ReleaseVsdHandle(VIDEO_COMPONENT_TYPE_T *prHandle);
extern void VsdMain(ilm_struct *prIlm);


#endif  // __VE_VIDEO_ARCHI_V2__


#endif  // VIDEO_SUBTITLE_DECODER_IF_H

