/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *    drv_gfx_stack_switch_manager.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   driver graphics stack switch manager header
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __DRV_GFX_STACK_SWITCH_MANAGER_H__
#define __DRV_GFX_STACK_SWITCH_MANAGER_H__

/// #include "kal_non_specific_general_types.h"
#include "kal_general_types.h"
#include "drv_features.h"



#define INFINITE_STACK_SIZE         0xFFFFFFF0

#define STACK_SIZE_MASK             0xFFFFFFF0

#define STACK_USER_ID_JPEG          4
#define STACK_USER_ID_GIF           5
#define STACK_USER_ID_PNG           6
#define STACK_USER_ID_BMP           7
#define STACK_USER_ID_M3D           8
#define STACK_USER_ID_SW_VIDEO      9
#define STACK_USER_ID_VRT_TASK      10
#define STACK_USER_ID_SW_IPP        11
#define STACK_USER_ID_FE            12

/// Notice:
/// The least significant 4 bits of DRV_GFX_STACK_POOL_SIZE must be zero such that we can assign the stack user id byte for each user.

#if defined(DRV_GRAPHICS_STACK_SWITCH_TO_INT_RAM) || defined(DRV_GRAPHICS_STACK_SWITCH_TO_TCM)

#define DRM_STACK_SIZE              (INFINITE_STACK_SIZE)
/// -------------------------------------------------------------
#define JPEG_STACK_SIZE             (STACK_USER_ID_JPEG + 0xCE0)
#define JPEG_DRM_STACK_SIZE         (STACK_USER_ID_JPEG + INFINITE_STACK_SIZE)
#define JPEG_FILE_STACK_SIZE        (STACK_USER_ID_JPEG + 0xCE0)
/// -------------------------------------------------------------
#define GIF_STACK_SIZE              (STACK_USER_ID_GIF + 0xCE0)
#define GIF_DRM_STACK_SIZE          (STACK_USER_ID_GIF + INFINITE_STACK_SIZE)
#define GIF_FILE_STACK_SIZE         (STACK_USER_ID_GIF + 0xCE0)
/// -------------------------------------------------------------
#define PNG_STACK_SIZE              (STACK_USER_ID_PNG + 0xCE0)
#define PNG_DRM_STACK_SIZE          (STACK_USER_ID_PNG + INFINITE_STACK_SIZE)
#define PNG_FILE_STACK_SIZE         (STACK_USER_ID_PNG + 0xCE0)
/// -------------------------------------------------------------
#define BMP_STACK_SIZE              (STACK_USER_ID_BMP + 0xCE0)
#define BMP_DRM_STACK_SIZE          (STACK_USER_ID_BMP + INFINITE_STACK_SIZE)
#define BMP_FILE_STACK_SIZE         (STACK_USER_ID_BMP + 0xCE0)
/// -------------------------------------------------------------
#define M3D_STACK_SIZE              (STACK_USER_ID_M3D + INFINITE_STACK_SIZE)
#define M3D_DRM_STACK_SIZE          (STACK_USER_ID_M3D + INFINITE_STACK_SIZE)
#define M3D_FILE_STACK_SIZE         (STACK_USER_ID_M3D + INFINITE_STACK_SIZE)
/// -------------------------------------------------------------
#define SW_VIDEO_STACK_SIZE         (STACK_USER_ID_SW_VIDEO + 0xCE0)
/// -------------------------------------------------------------
#define VRT_TASK_STACK_SIZE         (STACK_USER_ID_VRT_TASK + 0xCE0)
/// -------------------------------------------------------------
#define SW_IPP_TASK_STACK_SIZE      (STACK_USER_ID_SW_IPP + 0xCE0)
/// -------------------------------------------------------------
#define FE_STACK_SIZE               (STACK_USER_ID_FE + 0xCE0)
/// -------------------------------------------------------------
#define DRV_GFX_STACK_POOL_SIZE     (0xCE0 + 0x10)



/// 6235 TCM stack dedicated for SW Video
#elif defined(DRV_GRAPHICS_STACK_SWITCH_TO_TCM_6235)

/// -------------------------------------------------------------
#define JPEG_STACK_SIZE             (STACK_USER_ID_JPEG + INFINITE_STACK_SIZE)
#define JPEG_DRM_STACK_SIZE         (STACK_USER_ID_JPEG + INFINITE_STACK_SIZE)
#define JPEG_FILE_STACK_SIZE        (STACK_USER_ID_JPEG + INFINITE_STACK_SIZE)
/// -------------------------------------------------------------
#define GIF_STACK_SIZE              (STACK_USER_ID_GIF + INFINITE_STACK_SIZE)
#define GIF_DRM_STACK_SIZE          (STACK_USER_ID_GIF + INFINITE_STACK_SIZE)
#define GIF_FILE_STACK_SIZE         (STACK_USER_ID_GIF + INFINITE_STACK_SIZE)
/// -------------------------------------------------------------
#define PNG_STACK_SIZE              (STACK_USER_ID_PNG + INFINITE_STACK_SIZE)
#define PNG_DRM_STACK_SIZE          (STACK_USER_ID_PNG + INFINITE_STACK_SIZE)
#define PNG_FILE_STACK_SIZE         (STACK_USER_ID_PNG + INFINITE_STACK_SIZE)
/// -------------------------------------------------------------
#define BMP_STACK_SIZE              (STACK_USER_ID_BMP + INFINITE_STACK_SIZE)
#define BMP_DRM_STACK_SIZE          (STACK_USER_ID_BMP + INFINITE_STACK_SIZE)
#define BMP_FILE_STACK_SIZE         (STACK_USER_ID_BMP + INFINITE_STACK_SIZE)
/// -------------------------------------------------------------
#define M3D_STACK_SIZE              (STACK_USER_ID_M3D + INFINITE_STACK_SIZE)
#define M3D_DRM_STACK_SIZE          (STACK_USER_ID_M3D + INFINITE_STACK_SIZE)
#define M3D_FILE_STACK_SIZE         (STACK_USER_ID_M3D + INFINITE_STACK_SIZE)
/// -------------------------------------------------------------
#define SW_VIDEO_STACK_SIZE         (STACK_USER_ID_SW_VIDEO + 4080)
/// -------------------------------------------------------------
#define VRT_TASK_STACK_SIZE         (STACK_USER_ID_VRT_TASK + INFINITE_STACK_SIZE)
/// -------------------------------------------------------------
#define SW_IPP_TASK_STACK_SIZE      (STACK_USER_ID_SW_IPP + INFINITE_STACK_SIZE)
/// -------------------------------------------------------------
#define FE_STACK_SIZE               (STACK_USER_ID_FE + INFINITE_STACK_SIZE)
/// -------------------------------------------------------------
#define DRV_GFX_STACK_POOL_SIZE     (4080 + 0x10)



#elif defined(DRV_GRAPHICS_STACK_SWITCH_TO_CACHEABLE_EXT_RAM)

#define DRM_STACK_SIZE              (6 * 1024)
/// -------------------------------------------------------------
#define JPEG_STACK_SIZE             (STACK_USER_ID_JPEG + 3 * 1024)
#define JPEG_DRM_STACK_SIZE         (STACK_USER_ID_JPEG + JPEG_STACK_SIZE + DRM_STACK_SIZE)
#define JPEG_FILE_STACK_SIZE        (STACK_USER_ID_JPEG + 3 * 1024)
/// -------------------------------------------------------------
#define GIF_STACK_SIZE              (STACK_USER_ID_GIF + 3 * 1024)
#define GIF_DRM_STACK_SIZE          (STACK_USER_ID_GIF + GIF_STACK_SIZE + DRM_STACK_SIZE)
#define GIF_FILE_STACK_SIZE         (STACK_USER_ID_GIF + 3 * 1024)
/// -------------------------------------------------------------
#define PNG_STACK_SIZE              (STACK_USER_ID_PNG + 3 * 1024)
#define PNG_DRM_STACK_SIZE          (STACK_USER_ID_PNG + PNG_STACK_SIZE + DRM_STACK_SIZE)
#define PNG_FILE_STACK_SIZE         (STACK_USER_ID_PNG + 3 * 1024)
/// -------------------------------------------------------------
#define BMP_STACK_SIZE              (STACK_USER_ID_BMP + 3 * 1024)
#define BMP_DRM_STACK_SIZE          (STACK_USER_ID_BMP + BMP_STACK_SIZE + DRM_STACK_SIZE)
#define BMP_FILE_STACK_SIZE         (STACK_USER_ID_BMP + 3 * 1024)
/// -------------------------------------------------------------
#define M3D_STACK_SIZE              (STACK_USER_ID_M3D + 3 * 1024)
#define M3D_DRM_STACK_SIZE          (STACK_USER_ID_M3D + M3D_STACK_SIZE + DRM_STACK_SIZE)
#define M3D_FILE_STACK_SIZE         (STACK_USER_ID_M3D + 3 * 1024)
/// -------------------------------------------------------------
#define SW_VIDEO_STACK_SIZE         (STACK_USER_ID_SW_VIDEO + INFINITE_STACK_SIZE)
/// -------------------------------------------------------------
#define VRT_TASK_STACK_SIZE         (STACK_USER_ID_VRT_TASK + INFINITE_STACK_SIZE)
/// -------------------------------------------------------------
#define SW_IPP_TASK_STACK_SIZE      (STACK_USER_ID_SW_IPP + 3 * 1024)
/// -------------------------------------------------------------
#define FE_STACK_SIZE               (STACK_USER_ID_FE + 3 * 1024)
/// -------------------------------------------------------------
#define DRV_GFX_STACK_POOL_SIZE     (9 * 1024 + 0x10)



/// no stack switching
#else
/// -------------------------------------------------------------
#define JPEG_STACK_SIZE             (STACK_USER_ID_JPEG + INFINITE_STACK_SIZE)
#define JPEG_DRM_STACK_SIZE         (STACK_USER_ID_JPEG + INFINITE_STACK_SIZE)
#define JPEG_FILE_STACK_SIZE        (STACK_USER_ID_JPEG + INFINITE_STACK_SIZE)
/// -------------------------------------------------------------
#define GIF_STACK_SIZE              (STACK_USER_ID_GIF + INFINITE_STACK_SIZE)
#define GIF_DRM_STACK_SIZE          (STACK_USER_ID_GIF + INFINITE_STACK_SIZE)
#define GIF_FILE_STACK_SIZE         (STACK_USER_ID_GIF + INFINITE_STACK_SIZE)
/// -------------------------------------------------------------
#define PNG_STACK_SIZE              (STACK_USER_ID_PNG + INFINITE_STACK_SIZE)
#define PNG_DRM_STACK_SIZE          (STACK_USER_ID_PNG + INFINITE_STACK_SIZE)
#define PNG_FILE_STACK_SIZE         (STACK_USER_ID_PNG + INFINITE_STACK_SIZE)
/// -------------------------------------------------------------
#define BMP_STACK_SIZE              (STACK_USER_ID_BMP + INFINITE_STACK_SIZE)
#define BMP_DRM_STACK_SIZE          (STACK_USER_ID_BMP + INFINITE_STACK_SIZE)
#define BMP_FILE_STACK_SIZE         (STACK_USER_ID_BMP + INFINITE_STACK_SIZE)
/// -------------------------------------------------------------
#define M3D_STACK_SIZE              (STACK_USER_ID_M3D + INFINITE_STACK_SIZE)
#define M3D_DRM_STACK_SIZE          (STACK_USER_ID_M3D + INFINITE_STACK_SIZE)
#define M3D_FILE_STACK_SIZE         (STACK_USER_ID_M3D + INFINITE_STACK_SIZE)
/// -------------------------------------------------------------
#define SW_VIDEO_STACK_SIZE         (STACK_USER_ID_SW_VIDEO + INFINITE_STACK_SIZE)
/// -------------------------------------------------------------
#define VRT_TASK_STACK_SIZE         (STACK_USER_ID_VRT_TASK + INFINITE_STACK_SIZE)
/// -------------------------------------------------------------
#define SW_IPP_TASK_STACK_SIZE      (STACK_USER_ID_SW_IPP + INFINITE_STACK_SIZE)
/// -------------------------------------------------------------
#define FE_STACK_SIZE               (STACK_USER_ID_FE + INFINITE_STACK_SIZE)
/// -------------------------------------------------------------
#define DRV_GFX_STACK_POOL_SIZE     (1) // dummy

#endif



/*****************************************************************************
 * drv_gfx_stkmgr_get_stack
 *
 * @remarks get dedicated stack memory space
 *
 * @param stk_size the desired stack size
 *
 * @return NULL pointer if allocation fails
 * @return non NULL stack pointer if allocation successes
 *****************************************************************************/
#if defined(STK_MGR_DEBUG)
   extern void *drv_gfx_stkmgr_get_stack_internal(kal_uint32 stk_size, kal_char* file, kal_uint32 line);
   #define drv_gfx_stkmgr_get_stack(x) drv_gfx_stkmgr_get_stack_internal((x), __FILE__, __LINE__)
#else
   extern void *drv_gfx_stkmgr_get_stack_internal(kal_uint32 stk_size);
   #define drv_gfx_stkmgr_get_stack(x) drv_gfx_stkmgr_get_stack_internal(x)
#endif


/*****************************************************************************
 * drv_gfx_stkmgr_return_stack
 *
 * @remarks return dedicated stack space pointed by stack pointer
 *
 * @param stk_ptr the stack pointer
 *
 *****************************************************************************/
#if defined(STK_MGR_DEBUG)
   extern void drv_gfx_stkmgr_release_stack_internal(void *stk_ptr, kal_char* file, kal_uint32 line);
   #define drv_gfx_stkmgr_release_stack(x) drv_gfx_stkmgr_release_stack_internal((x), __FILE__, __LINE__)
#else
   extern void drv_gfx_stkmgr_release_stack_internal(void *stk_ptr);
   #define drv_gfx_stkmgr_release_stack(x) drv_gfx_stkmgr_release_stack_internal(x)
#endif


/**
 * @brief            Set the stack user filter.
 * @param stk_size   the stack size of for the specified stack user; it will be used to distinguish different stack users.
 * @return           If success, return 1; otherwise return 0
 * @remarks          stk_size must be the macro defined in drv_gfx_stack_switch_manager.h
 */
kal_int32 drv_gfx_stkmgr_set_user_filter(kal_uint32 stk_size);



/**
 * @brief            Unset the stack user filter.
 * @param stk_size   the stack size of for the specified stack user; it will be used to distinguish different stack users.
 * @return           If success, return 1; otherwise return 0
 * @remarks          stk_size must be the macro defined in drv_gfx_stack_switch_manager.h
 */
kal_int32 drv_gfx_stkmgr_unset_user_filter(kal_uint32 stk_size);


#endif   // #ifndef __DRV_GFX_STACK_SWITCH_MANAGER_H__
