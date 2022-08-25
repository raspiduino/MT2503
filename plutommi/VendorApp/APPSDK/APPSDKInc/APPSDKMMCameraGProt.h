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
 *  SDKMMCamera.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Camera interfce header file
 *
 * Author:
 * -------
 * -------
 *                      
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _SDKMMCAMERA_H_
#define _SDKMMCAMERA_H_

#include "MMI_features.h"

#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)

#include "mdi_datatype.h"
#include "mdi_include.h"
#include "Mdi_camera.h"

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
/* power on/off camera module */
extern MDI_RESULT mdi_camera_power_on(U16 app_id);
extern MDI_RESULT mdi_camera_power_off(void);

/* start/stop  preview */
extern MDI_RESULT mdi_camera_preview_start(
                    mdi_camera_preview_struct *preview_p,
                    mdi_camera_setting_struct *setting_p,
                    void* user_data);

extern MDI_RESULT mdi_camera_preview_stop(void);

/* capture */
extern MDI_RESULT mdi_camera_capture_to_memory(U8 **buf_pp, U32 *captured_size, S8 *file_name);

extern void mdi_camera_update_para_ev(U16 cam_para);
extern void mdi_camera_update_para_zoom(U16 cam_para);
extern void mdi_camera_update_para_image_qty(U16 cam_para);
extern void mdi_camera_update_para_image_size(U16 image_width, U16 image_height);
extern U16 mdi_camera_get_para_ev(void);
extern U16 mdi_camera_get_para_zoom(void);
extern U16 mdi_camera_get_para_banding(void);
extern U16 mdi_camera_get_para_effect(void);
extern U16 mdi_camera_get_para_wb(void);
extern U16 mdi_camera_get_para_sharpness(void);
extern U16 mdi_camera_get_para_saturation(void);
extern U16 mdi_camera_get_para_contrast(void);
extern U16 mdi_camera_get_para_hue(void);
extern U16 mdi_camera_get_para_night(void);
extern U16 mdi_camera_get_para_image_qty(void);
extern void mdi_camera_get_para_image_size(U16* image_width_ptr, U16* image_height_ptr);
extern U16 mdi_camera_get_para_flash(void);
extern U16 mdi_camera_get_para_iso(void);
extern U16 mdi_camera_get_para_ae_meter(void);
extern U16 mdi_camera_get_para_dsc_mode(void);
extern U16 mdi_camera_get_para_af_mode(void);
extern BOOL mdi_camera_is_camera_avaliable(void);
extern U16 mdi_camera_get_max_zoom_factor(S32 image_width, S32 image_height);

extern void mdi_camera_load_default_setting(mdi_camera_setting_struct *camera_setting_data);
extern S32 mdi_camera_save_captured_image(void);

#endif /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */ 
#endif /* _SDKMMCAMERA_H_ */

