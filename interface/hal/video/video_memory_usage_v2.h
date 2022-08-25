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
 *   video_memory_usage_v2.h
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
 ****************************************************************************/

#ifndef VIDEO_MEMORY_USAGE_V2_H
#define VIDEO_MEMORY_USAGE_V2_H

#include "video_memory_usage_internal_v2.h"

/*******************************************************
*
*   Decide the total external memory needed by
*   decoder component
*
*******************************************************/

#define VIDEO_V2_DEC_EXT_MEMORY  (__VE_VIDEO_V2_DEC_EXT_MEMORY__)

#define VIDEO_V2_DEC_N_SUBTITLE_EXT_MEMORY  (__VE_VIDEO_V2_DEC_N_SUBTITLE_EXT_MEMORY__)

// QVGA
#define VIDEO_V2_QVGA_DEC_EXT_MEMORY  (__VE_VIDEO_V2_QVGA_DEC_EXT_MEMORY__)

// QVGAMPEG4SP
#define VIDEO_V2_QVGA_MPEG4SP_DEC_EXT_MEMORY  (__VE_VIDEO_V2_QVGA_MPEG4SP_DEC_EXT_MEMORY__)

// QCIF
#define VIDEO_V2_QCIF_DEC_EXT_MEMORY  (__VE_VIDEO_V2_QCIF_DEC_EXT_MEMORY__)

// VGA
#define VIDEO_V2_VGA_DEC_EXT_MEMORY  (__VE_VIDEO_V2_VGA_DEC_EXT_MEMORY__)

// CIF
#define VIDEO_V2_CIF_DEC_EXT_MEMORY  (__VE_VIDEO_V2_CIF_DEC_EXT_MEMORY__)

// preview
#define VIDEO_V2_PREVIEW_DEC_EXT_MEMORY  (__VE_VIDEO_V2_PREVIEW_DEC_EXT_MEMORY__)

// Live wall paper
#define VIDEO_V2_DEC_MPEG4_EXT_MEMORY  (__VE_VIDEO_V2_DEC_MPEG4_EXT_MEMORY__)

// UPTO-QVGA
#define VIDEO_V2_UPTOQVGA_DEC_EXT_MEMORY  (__VE_VIDEO_V2_UPTOQVGA_DEC_EXT_MEMORY__)

// UPTO-CIF
#define VIDEO_V2_UPTOCIF_DEC_EXT_MEMORY  (__VE_VIDEO_V2_UPTOCIF_DEC_EXT_MEMORY__)

/*******************************************************
*
*   Calculate the total external memory needed in
*   video recorder
*
*******************************************************/

#define VIDEO_V2_ENC_EXT_MEMORY     (__VE_VIDEO_V2_ENC_EXT_MEMORY__)
#define VIDEO_V2_ENC_CIF_EXT_MEMORY (__VE_VIDEO_V2_ENC_CIF_EXT_MEMORY__)

// AVI writer is special case that no adidtional overhead is needed since it retrieves memory from other pool
#define VIDEO_V2_AVI_FW_EXT_MEMORY  (__VE_VIDEO_V2_AVI_FW_EXT_MEMORY__)

// MP4 writer
#define VIDEO_V2_MP4_FW_EXT_MEMORY  (__VE_VIDEO_V2_MP4_FW_EXT_MEMORY__)

// The next line defines the amount of external memory used by File Writer.
#define VIDEO_V2_ENC_FW_EXT_MEMORY  (__VE_VIDEO_V2_ENC_FW_EXT_MEMORY__)

/*******************************************************
*
*   Calculate the total external memory needed for VT
*
*******************************************************/
#define VIDEO_V2_VT_EXT_MEMORY    (__VE_VIDEO_V2_VT_EXT_MEMORY__)

/*******************************************************
*
*   Calculate the total external memory needed for Video CLipper
*
*******************************************************/

#define VIDEO_V2_VIDEO_CLIPPER_EXT_MEMORY (__VE_VIDEO_V2_VIDEO_CLIPPER_EXT_MEMORY__)

#endif /* VIDEO_MEMORY_USAGE_V2_H */

