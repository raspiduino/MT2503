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
 *    va2_video_renderer_vp_mt6253.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    OpenMAX-like Video Renderer of Video Architecture V2.
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
 ****************************************************************************/
#ifndef __VA2_VIDEO_RENDERER_VP_MT6253_H__
#define __VA2_VIDEO_RENDERER_VP_MT6253_H__

/// \defgroup va2_video_renderer_vp_mt6253
/// \ingroup va2_video_renderer_vp
/// @{

/****************************************************************************
 * macro defnitions
 ****************************************************************************/
#if defined(MT6253T) || defined(MT6253)
#define VA2_VIDEO_RENDERER_VP_MT6253
#define APPLY_NEW_REDRAW_MECHANISM
#endif  // #if defined(MT6253T) || defined(MT6253)

#if defined(__VIDEO_ARCHI_V2__)
#if defined(VA2_VIDEO_RENDERER_VP_MT6253)

/****************************************************************************
 * include directives
 ****************************************************************************/
#include "kal_public_api.h"
/******* VA2 common *************************/
#include "video_types_v2.h"
/******* VA2 Video Renderer Component *******/
#include "va2_comp_video_renderer.h"
#include "va2_video_renderer_common.h"

/****************************************************************************
 * external function
 ****************************************************************************/
/**
 *  Get the handle of Video Renderer for MT6253 video playback
 *  @return VIDEO_COMPONENT_TYPE_T*, NULL if it fails.
 *  @param  VA2_VIDEO_RENDERER_TYPE_T e_type, Only VIDEO_RENDERER_VIDEO_PLAYBACK is allowed.
 */
extern VIDEO_COMPONENT_TYPE_T* 
va2_video_renderer_vp_mt6253_get_handle(
  VA2_VIDEO_RENDERER_TYPE_T e_type);

/**
 *  Release the handle of Video Renderer for MT6253 video playback
 *  @return VIDEO_ERROR_TYPE_T VIDEO_ERROR_NONE if OK, o.w. it fails.
 *  @param  VIDEO_COMPONENT_TYPE_T *pr_handle
 */
extern VIDEO_ERROR_TYPE_T 
va2_video_renderer_vp_mt6253_release_handle(
  VIDEO_COMPONENT_TYPE_T *pr_handle);

#endif  // #if defined(VA2_VIDEO_RENDERER_VP_MT6253)
#endif  // #if defined(__VIDEO_ARCHI_V2__)
/// @}

#endif  // #ifndef __VA2_VIDEO_RENDERER_VP_MT6253_H__

