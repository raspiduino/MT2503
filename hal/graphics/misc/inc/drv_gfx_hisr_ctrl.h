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
 *   drv_gfx_hisr_ctrl.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Graphics HISR control
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __DRV_GFX_HISR_CTRL_H__
#define __DRV_GFX_HISR_CTRL_H__

typedef void (*DRV_GFX_HISR_CALLBACK_FUNC)(void);

typedef enum
{
  DRV_GFX_HISR_MODULE_JPEG_DECODER = 0,
  DRV_GFX_HISR_MODULE_JPEG_DECODER_IDP,
  DRV_GFX_HISR_MODULE_JPEG_ENCODER,
  DRV_GFX_HISR_MODULE_PNG_DECODER,
  DRV_GFX_HISR_MODULE_GIF_DECODER,
  DRV_GFX_HISR_MODULE_G2D,
  
  DRV_GFX_MODULE_GPUGP_HISR,
  DRV_GFX_MODULE_GPUPP0_HISR,
  DRV_GFX_MODULE_GPUGPMMU_HISR,
  DRV_GFX_MODULE_GPUPP0MMU_HISR,  
  
  DRV_GFX_HISR_MODULE_MAX
} DRV_GFX_HISR_MODULE_ENUM;

typedef enum
{
  DRV_GFX_HISR_STATUS_OK = 0,
  DRV_GFX_HISR_STATUS_ERR,
}GFX_HISR_STATUS_ENUM;


typedef enum
{
   GFX_HISR___JPG______IDP_DEC = 1,
   GFX_HISR___JPG__________DEC,
   GFX_HISR___JPG__________ENC,
   GFX_HISR___PNG__________DEC,
   GFX_HISR___GIF__________DEC,
   GFX_HISR___G2D__________DEC,
   GFX_HISR___GPUGP________START,
   GFX_HISR___GPUPP0_______START,
   GFX_HISR___GPUGPMMU_____START,
   GFX_HISR___GPUPP0MMU____START,
  

   GFX_HISR___JPG______DEC_END,
   GFX_HISR___JPG__DEC_IDP_END,
   GFX_HISR___JPG______ENC_END,
   GFX_HISR___PNG__________END,
   GFX_HISR___GIF__________END,
   GFX_HISR___G2D__________END,
   GFX_HISR___GPUGP________END,
   GFX_HISR___GPUPP0_______END,
   GFX_HISR___GPUGPMMU_____END,
   GFX_HISR___GPUPP0MMU____END,

   GFX_HISR___JPG_________HISR,
   GFX_HISR___PNG_________HISR,
   GFX_HISR___GIF_________HISR,
   GFX_HISR___G2D_________HISR,
   GFX_HISR___GPUGP_______HISR,
   GFX_HISR___GPUPP0______HISR,
   GFX_HISR___GPUGPMMU____HISR,
   GFX_HISR___GPUPP0MMU___HISR,
	
   GFX_HISR______________START,
   GFX_HISR________________END,
   GFX_HISR________________RSD
}GFX_HISR_DBG_ID_ENUM;

GFX_HISR_STATUS_ENUM drv_gfx_hisr_hook_callback(DRV_GFX_HISR_MODULE_ENUM moduleID, DRV_GFX_HISR_CALLBACK_FUNC callbackFunc);
GFX_HISR_STATUS_ENUM drv_gfx_hisr_activate(DRV_GFX_HISR_MODULE_ENUM moduleID);
void drv_gfx_hisr_entry(void);
//void drv_gfx_hisr_init(void);
void gfxHisr_trace(GFX_HISR_DBG_ID_ENUM id);

#endif //__DRV_GFX_HISR_CTRL_H__
