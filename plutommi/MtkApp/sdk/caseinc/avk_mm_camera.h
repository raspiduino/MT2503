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
 *   tst_appser_mm_camera.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   3rd Party Integration Development Environment
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef TST_APPSER_MM_CAMERA_H
#define TST_APPSER_MM_CAMERA_H
#include "mmi_features.h"
#ifdef __MAUI_SDK_TEST__
#include "mdi_camera.h"





typedef struct
{
    S32 index;

    gdi_handle base_layer_handle;
    gdi_handle play_layer_handle;
    S32 offset_x;
    S32 offset_y;
    S32 width;
    S32 height;
    U16 image_width;
    U16 image_height;
    PS8 captured_filepath;
    PU8 capture_buf_ptr;
    U32 capture_size;
    U8 zoom_ptr[128];
    U16 para_ev;
    U16 para_zoom;
    U16 para_qty;
    U16 p1[128];
    U16 p2[128];
    U16 p3[128];
    U16 p4[128];
    BOOL m_bCaptured;
#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)    
    mdi_camera_jpegs_struct m_jpegs_struct;
#endif
	void* m_pBurstShortMemoryPool;

} vs_mm_camera_context_struct;


void vs_mm_camera_preview(void);
void vs_mm_camera_preview_start(void);
void vs_mm_camera_001_capture_to_memory(void);
void vs_mm_camera_002_capture_to_file(void);
void vs_mm_camera_003_capture_layer_to_memory(void);
void vs_mm_camera_004_capture_layer_to_file(void);
void vs_mm_camera_005_capture_continuous_shot_with_quickview(void);
void vs_mm_camera_006_capture_continuous_shot(void);
void vs_mm_camera_007_capture_with_quickview(void);
void vs_mm_camera_008_capture_to_memory_burst_shot(void);




 
void vs_mm_camera_update_ev(void);
void vs_mm_camera_update_zoom(void);
void vs_mm_camera_update_image_qty(void);
void vs_mm_camera_update_image_size(void);

void vs_mm_camera_misc_screen_exit(void);
void vs_mm_camera_misc_pass(void);
void vs_mm_camera_misc_fail(void);
void vs_mm_camera_misc_manual(void);
void vs_mm_camera_misc_get_image_file_path(U16 *path, U16 *file);
void vs_mm_misc_init_camera(void);

void vs_mm_camera_capture(void);





void vs_mm_camera_entry_scr(void);

#endif 

#endif 

