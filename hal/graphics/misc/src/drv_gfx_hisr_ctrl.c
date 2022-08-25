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
 *   drv_gfx_hisr_ctrl.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   drv_gfx_hisr_ctrl.c provides the hisr dispatcher for drv_graphics HW modules.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "intrCtrl.h"
#include "hisr_config.h"
#include "drv_gfx_hisr_ctrl.h"
#include "drv_features_g2d.h"

#if defined(__MTK_TARGET__) && (defined(G2D_HW_SHARE_WITH_GOVL_SUPPORT) || defined(__HW_G2D_SUPPORT__) || defined(__HW_GIF_SUPPORT__) \
       || defined(__JPEG_HW_SUPPORTED__) || defined(__PNG_HW_SUPPORTED) || defined(__MALI400MP_OPENGLES_HW_SUPPORT__))

//#define GFX_HISR_DBG_SUPPORT
#if defined(GFX_HISR_DBG_SUPPORT)
typedef struct
{
   GFX_HISR_DBG_ID_ENUM id;
}GFX_HISR_DBG;
kal_uint32 GFXHISR_TRACE_INDEX = 0;
#define GFXHISR_TRACE_INFO_SIZE 1024
GFX_HISR_DBG gfxhisr_trace_data[GFXHISR_TRACE_INFO_SIZE];

void gfxHisr_trace(GFX_HISR_DBG_ID_ENUM id)
{
   gfxhisr_trace_data[GFXHISR_TRACE_INDEX++].id = id;
   GFXHISR_TRACE_INDEX &= (GFXHISR_TRACE_INFO_SIZE - 1);
}
#else //GFX_HISR_DBG
void gfxHisr_trace(GFX_HISR_DBG_ID_ENUM id)
{
}

#endif


#define GFX_HISR_USER_NUMBER DRV_GFX_HISR_MODULE_MAX
typedef struct GFX_HISR_CTRL_BLCOK_T
{
  kal_bool   initialied;   /// Indicate if drv_gfx_hisr_ctrl is initialized or not
  kal_uint32 activeModule; /// Bitmap for each module
  DRV_GFX_HISR_CALLBACK_FUNC moduleCallback[GFX_HISR_USER_NUMBER]; /// callback function for each module
}GFX_HISR_CTRL_BLOCK;

static GFX_HISR_CTRL_BLOCK gfx_hisr_cnxt = {KAL_FALSE, 0, {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}}; /// gfx_hisr control block.
kal_hisrid _gfx_hisr_id; ///gfx_hisr ID


void _drv_gfx_hisr_clear_flag(DRV_GFX_HISR_MODULE_ENUM moduleID)
{
   kal_uint32 mask = SaveAndSetIRQMask();
   gfx_hisr_cnxt.activeModule &= (~(1 << moduleID));
   RestoreIRQMask(mask);
}


void drv_gfx_hisr_entry(void)
{
   kal_uint32 mask = SaveAndSetIRQMask();
   kal_uint32 activeModule = gfx_hisr_cnxt.activeModule;
   RestoreIRQMask(mask);

   gfxHisr_trace(GFX_HISR______________START);
	
   if (activeModule & (1 << DRV_GFX_MODULE_GPUGP_HISR))
   {
      /// clear relative bit before this module's IRQ been open
      _drv_gfx_hisr_clear_flag(DRV_GFX_MODULE_GPUGP_HISR);
      gfxHisr_trace(GFX_HISR___GPUGP________END);
      gfx_hisr_cnxt.moduleCallback[DRV_GFX_MODULE_GPUGP_HISR]();
   }
   else if (activeModule & (1 << DRV_GFX_MODULE_GPUPP0_HISR))
   {
      _drv_gfx_hisr_clear_flag(DRV_GFX_MODULE_GPUPP0_HISR);
      gfxHisr_trace(GFX_HISR___GPUPP0_______END);
      gfx_hisr_cnxt.moduleCallback[DRV_GFX_MODULE_GPUPP0_HISR]();
   }
   else if (activeModule & (1 << DRV_GFX_MODULE_GPUGPMMU_HISR))
   {
      _drv_gfx_hisr_clear_flag(DRV_GFX_MODULE_GPUGPMMU_HISR);
      gfxHisr_trace(GFX_HISR___GPUGPMMU_____END);
      gfx_hisr_cnxt.moduleCallback[DRV_GFX_MODULE_GPUGPMMU_HISR]();
   }
   else if (activeModule & (1 << DRV_GFX_MODULE_GPUPP0MMU_HISR))
   {
      _drv_gfx_hisr_clear_flag(DRV_GFX_MODULE_GPUPP0MMU_HISR);
      gfxHisr_trace(GFX_HISR___GPUPP0MMU____END);
      gfx_hisr_cnxt.moduleCallback[DRV_GFX_MODULE_GPUPP0MMU_HISR]();
   }     	
   else if (activeModule & (1 << DRV_GFX_HISR_MODULE_JPEG_DECODER))
   {
      //clear relative bit before this module's IRQ been open
      _drv_gfx_hisr_clear_flag(DRV_GFX_HISR_MODULE_JPEG_DECODER);
      gfxHisr_trace(GFX_HISR___JPG______DEC_END);
      gfx_hisr_cnxt.moduleCallback[DRV_GFX_HISR_MODULE_JPEG_DECODER]();
   }
   else if (activeModule & (1 << DRV_GFX_HISR_MODULE_JPEG_DECODER_IDP))
   {
      _drv_gfx_hisr_clear_flag(DRV_GFX_HISR_MODULE_JPEG_DECODER_IDP);
      gfxHisr_trace(GFX_HISR___JPG__DEC_IDP_END);
      gfx_hisr_cnxt.moduleCallback[DRV_GFX_HISR_MODULE_JPEG_DECODER_IDP]();
   }
   else if (activeModule & (1 << DRV_GFX_HISR_MODULE_JPEG_ENCODER))
   {
      _drv_gfx_hisr_clear_flag(DRV_GFX_HISR_MODULE_JPEG_ENCODER);
      gfxHisr_trace(GFX_HISR___JPG______ENC_END);
      gfx_hisr_cnxt.moduleCallback[DRV_GFX_HISR_MODULE_JPEG_ENCODER]();
   }
   else if (activeModule & (1 << DRV_GFX_HISR_MODULE_PNG_DECODER))
   {
      _drv_gfx_hisr_clear_flag(DRV_GFX_HISR_MODULE_PNG_DECODER);
      gfxHisr_trace(GFX_HISR___PNG__________END);
      gfx_hisr_cnxt.moduleCallback[DRV_GFX_HISR_MODULE_PNG_DECODER]();
   }
   else if (activeModule & (1 << DRV_GFX_HISR_MODULE_GIF_DECODER))
   {
      _drv_gfx_hisr_clear_flag(DRV_GFX_HISR_MODULE_GIF_DECODER);
      gfxHisr_trace(GFX_HISR___GIF__________END);
      gfx_hisr_cnxt.moduleCallback[DRV_GFX_HISR_MODULE_GIF_DECODER]();
   }
   else if (activeModule & (1 << DRV_GFX_HISR_MODULE_G2D))
   {
      _drv_gfx_hisr_clear_flag(DRV_GFX_HISR_MODULE_G2D);
      gfxHisr_trace(GFX_HISR___G2D__________END);
      gfx_hisr_cnxt.moduleCallback[DRV_GFX_HISR_MODULE_G2D]();
   }
   else
   {
      ASSERT(0);
   }

   gfxHisr_trace(GFX_HISR________________END);
	
}


void _drv_gfx_hisr_init(void)
{
   kal_uint32 mask = SaveAndSetIRQMask();
   //if (gfx_hisr_cnxt.initialied)
   //{
   //  RestoreIRQMask(mask);
   //  return;
   //}
   gfx_hisr_cnxt.initialied = KAL_TRUE;
   RestoreIRQMask(mask);

   /// create the hisr for graphics modules. Use new HISR management.
   _gfx_hisr_id = kal_init_hisr(GFXHISR);
}



GFX_HISR_STATUS_ENUM
drv_gfx_hisr_hook_callback(DRV_GFX_HISR_MODULE_ENUM moduleID, DRV_GFX_HISR_CALLBACK_FUNC callbackFunc)
{
   kal_uint32 mask = SaveAndSetIRQMask();
   if (!gfx_hisr_cnxt.initialied)
   {
      RestoreIRQMask(mask);
      _drv_gfx_hisr_init();
   }
   else
   {
      RestoreIRQMask(mask);
   }

   if ((moduleID >= DRV_GFX_HISR_MODULE_MAX) || (!callbackFunc))
   {
      ASSERT(0); //return DRV_GFX_HISR_STATUS_ERR;
   }

   gfx_hisr_cnxt.moduleCallback[moduleID] = callbackFunc;

   return DRV_GFX_HISR_STATUS_OK;
}



/*
**
*/
GFX_HISR_STATUS_ENUM
drv_gfx_hisr_activate(DRV_GFX_HISR_MODULE_ENUM moduleID)
{
   kal_uint32 temp;
   kal_uint32 mask;

   if (moduleID >= DRV_GFX_HISR_MODULE_MAX)
   {
      return DRV_GFX_HISR_STATUS_ERR;//ASSERT(0);
   }
   temp = 1 << moduleID;

   mask = SaveAndSetIRQMask();
   if (gfx_hisr_cnxt.activeModule & temp)
   {
      //Something wrong here! ISR reentry.
      ASSERT(0);
   }
   gfx_hisr_cnxt.activeModule |= temp;
   RestoreIRQMask(mask);

   kal_activate_hisr(_gfx_hisr_id);
   return DRV_GFX_HISR_STATUS_OK;
}

#else

GFX_HISR_STATUS_ENUM
drv_gfx_hisr_hook_callback(DRV_GFX_HISR_MODULE_ENUM moduleID, DRV_GFX_HISR_CALLBACK_FUNC callbackFunc)
{
   return DRV_GFX_HISR_STATUS_OK;
}

GFX_HISR_STATUS_ENUM
drv_gfx_hisr_activate(DRV_GFX_HISR_MODULE_ENUM moduleID)
{
  return DRV_GFX_HISR_STATUS_OK;
}

void drv_gfx_hisr_entry(void)
{

}
#endif //defined(__MTK_TARGET__) 

