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
 *    va2_video_renderer_vp.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    OpenMAX-like Video Renderer of Video Architecture V2.
 *    This contains the common part of Video Renderer for Video Playback. 
 *    This file contains a factory method to return handles of VR.VP based on HW platforms.
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
/// \ingroup va2_video_renderer_vp
/// @{
#ifdef __VIDEO_ARCHI_V2__

/****************************************************************************
 * internal options
 ****************************************************************************/

/****************************************************************************
 * include directives
 ****************************************************************************/
#include "kal_public_api.h"
/******* VA2 common *************************/
#include "video_types_v2.h"
//#include "video_comm_component_v2.h" // unnecessary for now...
//#include "video_buffer_management_v2.h" // unnecessary for now...
/******* VA2 Video Renderer Component *******/
#include "va2_comp_video_renderer.h"
#include "va2_video_renderer_common.h"
#include "va2_video_renderer_vp.h"
#include "va2_video_renderer_vp_mt6236.h"
#include "va2_video_renderer_vp_mt6235.h"
#include "va2_video_renderer_vp_mt6253.h"
#include "va2_video_renderer_vp_mt6252.h"
#include "va2_video_renderer_vp_mt6268.h"
#include "va2_video_renderer_vp_mt6276.h"
/******* driver common **********************/
//#include "drv_features.h" // unnecessary for now...
//#include "drv_comm.h" // unnecessary for now...

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_RENDER_ROCODE", rodata = "DYNAMIC_CODE_RENDER_ROCODE"
#endif

/****************************************************************************
 * external function bodies
 ****************************************************************************/
VIDEO_COMPONENT_TYPE_T* 
va2_video_renderer_vp_get_handle(
  VA2_VIDEO_RENDERER_TYPE_T e_type)
{
#if defined(__MTK_TARGET__)

#if defined(VA2_VIDEO_RENDERER_VP_MT6236)
  return va2_video_renderer_vp_mt6236_get_handle(e_type);
#elif defined(VA2_VIDEO_RENDERER_VP_MT6276)
  return va2_video_renderer_vp_mt6276_get_handle(e_type);
#elif defined(VA2_VIDEO_RENDERER_VP_MT6253)
  return va2_video_renderer_vp_mt6253_get_handle(e_type);
#elif defined(VA2_VIDEO_RENDERER_VP_MT6252)
  return va2_video_renderer_vp_mt6252_get_handle(e_type);
#elif defined(VA2_VIDEO_RENDERER_VP_MT6268)
  return va2_video_renderer_vp_mt6268_get_handle(e_type);
#elif defined(VA2_VIDEO_RENDERER_VP_MT6235)
  return va2_video_renderer_vp_mt6235_get_handle(e_type);
#else   // options for VR.VP implementation
  return NULL;
#endif  // options for VR.VP implementation

#else   // #if defined(__MTK_TARGET__)
  return NULL;
#endif  // #if defined(__MTK_TARGET__)
}

VIDEO_ERROR_TYPE_T 
va2_video_renderer_vp_release_handle(
  VIDEO_COMPONENT_TYPE_T *pr_handle)
{
#if defined(__MTK_TARGET__)

#if defined(VA2_VIDEO_RENDERER_VP_MT6236)
  return va2_video_renderer_vp_mt6236_release_handle(pr_handle);
#elif defined(VA2_VIDEO_RENDERER_VP_MT6276)
  return va2_video_renderer_vp_mt6276_release_handle(pr_handle);
#elif defined(VA2_VIDEO_RENDERER_VP_MT6253)
  return va2_video_renderer_vp_mt6253_release_handle(pr_handle);
#elif defined(VA2_VIDEO_RENDERER_VP_MT6252)
  return va2_video_renderer_vp_mt6252_release_handle(pr_handle);
#elif defined(VA2_VIDEO_RENDERER_VP_MT6268)
  return va2_video_renderer_vp_mt6268_release_handle(pr_handle);
#elif defined(VA2_VIDEO_RENDERER_VP_MT6235)
  return va2_video_renderer_vp_mt6235_release_handle(pr_handle);
#else   // options for VR.VP implementation
  return VIDEO_ERROR_DEINIT_ERROR;
#endif  // options for VR.VP implementation
  
#else   // #if defined(__MTK_TARGET__)
  return VIDEO_ERROR_DEINIT_ERROR;
#endif  // #if defined(__MTK_TARGET__)
}

#if defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

#endif	// #ifdef __VIDEO_ARCHI_V2__
/// @}


