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
 *  CamcorderGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Define Camera Extern Prototype
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _CAMCORDER_GPROT_H_
#define _CAMCORDER_GPROT_H_

#include "MMI_features.h"
#include "MMI_features_camcorder.h"
#include "gdi_include.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "lcd_sw_rnd.h"
#include "gdi_lcd_config.h"
#ifdef __MMI_CAMCORDER__
/***************************************************************************** 
* Include
*****************************************************************************/
#include "mmi_features.h"

#ifndef _CAMCORDER_FEATURES_H_
#error "mmi_features_camcorder.h should be included before CamcorderGprot.h"
#endif 

#ifndef _GDI_INCLUDE_H_
#error "gdi_include.h should be included before CamcorderGprot.h"
#endif 

/***************************************************************************** 
* Define
*****************************************************************************/
typedef void (*camco_result_callback) (MMI_BOOL result, CHAR *filepath);

typedef enum
{
    MMI_CAMERA_EXTERNAL_MODE_OFF,
    MMI_CAMERA_EXTERNAL_MODE_NORMAL,
    MMI_CAMERA_EXTERNAL_MODE_LARGEST_RESOLUTION,
    MMI_CAMERA_EXTERNAL_MODE_LCD_RESOLUTION,    
    MMI_CAMERA_EXTERNAL_MODE_COUNT
} mmi_camera_external_mode_enum;

#if defined(__MMI_CAMCO_FEATURE_CAM_BURSTSHOT_SELECT__) || defined(__MMI_CAMCO_FEATURE_CAM_AEBSHOT_SELECT__)
    #define CAMCO_CAM_MULTISHOT_BUFFER_SIZE (MMI_CAMCO_CAM_MULTISHOT_MEM_SIZE + MMI_CAMCO_CAM_CACHE_MEM_SIZE + MMI_CAMCO_CAM_CACHE_IMAGE_FILEPATH_MEM_SIZE)
#elif defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__)
    #define CAMCO_CAM_MULTISHOT_BUFFER_SIZE (MMI_CAMCO_CAM_MULTISHOT_MEM_SIZE + MMI_CAMCO_CAM_CACHE_MEM_SIZE)
#elif defined(__MMI_CAMCO_FEATURE_CAM_BESTSHOT__) 
    #define CAMCO_CAM_MULTISHOT_BUFFER_SIZE (MMI_CAMCO_CAM_MULTISHOT_MEM_SIZE)
#else 
#define CAMCO_CAM_MULTISHOT_BUFFER_SIZE 0
#endif 

#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
#define CAMCO_OVERLAY_FRAME_BUFFER_SIZE     MMI_CAMCO_OVERLAY_COLOR_IDX_BUFFER_SIZE
#else 
#define CAMCO_OVERLAY_FRAME_BUFFER_SIZE     (0)
#endif 

#if defined(MMI_CAMCO_FEATURE_ROTATE_ON)
    #ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
		#define MMI_CAMCO_APP_MEM_SIZE  (CAMCO_CAM_MULTISHOT_BUFFER_SIZE + (MMI_CAMCO_OSD_LAYER_COUNT + 1) * ((((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3))) + MMI_CAMCO_SUBLCD_OSD_LAYER_DB_BUF_SIZE)
    #else 
        #define MMI_CAMCO_APP_MEM_SIZE  (CAMCO_CAM_MULTISHOT_BUFFER_SIZE + (MMI_CAMCO_OSD_LAYER_COUNT + 1) * ((((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3))))
    #endif 

#else
    #ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
        #define MMI_CAMCO_APP_MEM_SIZE  (CAMCO_CAM_MULTISHOT_BUFFER_SIZE + (MMI_CAMCO_OSD_LAYER_COUNT ) * ((((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3))) + MMI_CAMCO_SUBLCD_OSD_LAYER_DB_BUF_SIZE)
    #else 
        #define MMI_CAMCO_APP_MEM_SIZE  (CAMCO_CAM_MULTISHOT_BUFFER_SIZE + (MMI_CAMCO_OSD_LAYER_COUNT ) * ((((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3))))
    #endif 
#endif
#define MMI_CAMCO_SCR_MEM_SIZE  CAMCO_OVERLAY_FRAME_BUFFER_SIZE

#define APPMEM_CAMCO_POOL_SIZE  (MMI_CAMCO_APP_MEM_SIZE + MMI_CAMCO_MED_STITCH_EXT_MEM_SIZE  + ((((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3))) + 256) + MMI_CAMCO_SCR_MEM_SIZE
#if defined(MMI_CAMCO_FEATURE_ROTATE_ON)
    #define MMI_CAMCO_CUI_MEM_SIZE  ((MMI_CAMCO_OSD_LAYER_COUNT + 2) * ((((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)))+256)
#else
    #define MMI_CAMCO_CUI_MEM_SIZE  ((MMI_CAMCO_OSD_LAYER_COUNT +1) * ((((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)))+ 192)
#endif
#define mmi_camera_get_max_capture_resolution mmi_camco_cam_get_max_capture_resolution
#define mmi_vdorec_get_min_external_request_size mmi_camco_rec_get_min_external_request_size
#define mmi_camera_get_error_string_by_error_enum mmi_camco_get_error_string_by_error_enum
#define mmi_camera_get_camera_banding mmi_camco_setting_get_banding
#define mmi_vdorec_lauch mmi_camco_vdorec_launch
/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern void mmi_camco_vdorec_launch(void);
extern MMI_ID_TYPE mmi_camco_get_error_string_by_error_enum(S32 err_code);
extern mmi_ret mmi_camco_notify_storage_change_hdlr(mmi_event_struct *evt);

extern void mmi_camco_init_app(void);
extern void mmi_camco_entry_app_screen(void);

extern void mmi_camco_launch(void);
extern MMI_BOOL mmi_camco_check_and_display_popup(void);

extern void mmi_camco_cam_entry_for_external_request(void (*camera_result_callback) (MMI_BOOL result, CHAR *filepath_p));

extern void mmi_camco_cam_external_request_by_mode(mmi_camera_external_mode_enum mode, camco_result_callback callback);

extern void mmi_camco_cam_get_max_capture_resolution(S32 *width_p, S32 *height_p);

extern void mmi_camco_rec_entry_for_external_request(CHAR *filepath_p,
                                                     U32 max_size,
                                                     U32 max_time_sec,
                                                     void (*result_callback) (MMI_BOOL result, CHAR *filepath));

extern U32 mmi_camco_rec_get_min_external_request_size(void);

extern MMI_ID_TYPE mmi_camco_get_error_string_by_error_enum(S32 err_code);
extern U32 mmi_camco_get_ext_memory_usage(void);
extern void mmi_camco_rec_entry_app_screen_external(void);
extern U16 mmi_camco_setting_get_banding(void);
extern void mmi_camco_set_storage(U16 storage);
extern U16 mmi_camco_get_storage(void);
#endif /* __MMI_CAMCORDER__ */ 

#endif /* _CAMCORDER_GPROT_H_ */ /* _CAMERA_GPROT_H_ */

