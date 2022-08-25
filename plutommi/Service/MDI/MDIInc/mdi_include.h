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
 *   mdi_inculde.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   MDI command interface prototype
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
#ifndef MDI_INCLUDE
#define MDI_INCLUDE

#ifndef _FMGR_TYPE_H_
#include "filemgrtype.h"
#endif
#include "MMIDataType.h"
#include "gdi_datatype.h"
#include "stack_config.h"
#include "mmi_rp_file_type_def.h"
#include "kal_general_types.h"
#include "mdi_datatype.h"
#include "mmi_frm_events_gprot.h"
#include "drv_sw_features_mdp.h"
#include "drv_sw_features_video.h"
#ifndef _GDI_INCLUDE_H_
#include "gdi_include.h"
#endif
/***************************************************************************** 
* Define
*****************************************************************************/
#define MDI_ASSERT(expr)                \
    do {                                \
        if (!(expr)) { ASSERT(0); }     \
    } while (0)

/* MDI_DEVICE_TYPE */
#define MDI_DEVICE_AUDIO      0x0001
#define MDI_DEVICE_CAMER      0x0002
#define MDI_DEVICE_VIDEO      0x0004
#define MDI_DEVICE_ALL        0x0007

#define __MDI_RESIZER_LIMITATION_EVEN_WIDTH_HEIGHT__


#if defined(USE_UYVY422_BETWEEN_MDP_LCD)
#define __MDI_DISPLAY_YUYV422_SUPPORT__
#define __MDI_DISPLAY_ONLY_YUYV422_SUPPORT__
#endif

#if defined(MDP_SUPPORT_RGB565_FMT)
#define __MDI_DISPLAY_RGB565_SUPPORT__
#endif

#if defined(VA2_RENDERER_VP_RENDER_DISPLAY_BUFFER_RGB888)
#define __MDI_DISPLAY_RGB888_SUPPORT__
#endif

#if defined(VA2_RENDER_MODE_TOUCH_FROM_INSIDE_SUPPORTED)
#define __MDI_DISPLAY_FIT_INSIDE_SUPPORT__
#endif

#if defined(VA2_RENDER_MODE_TOUCH_FROM_OUTSIDE_SUPPORTED)
#define __MDI_DISPLAY_FIT_OUTSIDE_SUPPORT__
#endif

#define MDI_CAMERA_MAX_HW_LAYER_SIZE DRV_MDP_CAMERA_PREVIEW_MAX_HW_LAYER_SIZE
#define MDI_VDOREC_MAX_HW_LAYER_SIZE DRV_MDP_VIDEO_PREVIEW_MAX_HW_LAYER_SIZE
#define MDI_VDOPLY_MAX_HW_LAYER_SIZE DRV_MDP_VIDEO_PLAYBACK_MAX_HW_LAYER_SIZE

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef U16 MDI_DEVICE_TYPE;

typedef enum
{
    MDI_NAMING_TYPE_DDMMYY_HHMM,
    MDI_NAMING_TYPE_COUNT
}mdi_naming_type_enum;

typedef enum MultimediaTypeEnum
{
    MDI_MULTIMEDIA_NULL,    
    MDI_MULTIMEDIA_CAMERA,      // Camera preview 
    MDI_MULTIMEDIA_VIDEO,       // Video player (CMMB MTV)
    MDI_MULTIMEDIA_RRECORD,     // Recorder
    MDI_MULTIMEDIA_MATV,        // mATV
    MDI_MULTIMEDIA_VIDEOPHONE,   // Video phone call
    MDI_MULTIMEDIA_SUBTITLE      // MKV subtitle
}mdi_multimedia_scenario_enum;

/***************************************************************************** 
* Struct 
*****************************************************************************/

typedef struct
{
    mmi_id app_id;
    S16 offset_x;
    S16 offset_y;
    U16 width;
    U16 height;
    gdi_color_format color_format;              // for substitle only, other types will be set automatically
    mdi_multimedia_scenario_enum scenario_id;
}mdi_util_create_hw_layer_in_struct;


typedef struct
{
    U8* buffer;
    S32 buffer_size; 
    S16 offset_x;
    S16 offset_y;
    U16 width;
    U16 height;
    gdi_color_format color_format;              // for substitle only, other types will be set automatically
    mdi_multimedia_scenario_enum scenario_id;
}mdi_util_create_hw_layer_extmemory_in_struct;


typedef struct
{
    S16 offset_x;
    S16 offset_y;
    U16 width;
    U16 height;
    mdi_multimedia_scenario_enum scenario_id;
}mdi_util_create_hw_layer_intmemory_in_struct;


typedef struct
{
    S32 result; 
    S16 offset_x;
    S16 offset_y;
    U16 width;
    U16 height;   
}mdi_util_create_hw_layer_out_struct;

typedef struct
{
    MMI_BOOL    is_allocated;
    mmi_id      app_id;
    gdi_handle  layer_handle;
    mdi_multimedia_scenario_enum scenario_id;
}mdi_hw_layer_struct;


/***************************************************************************** 
* Typedef 
*****************************************************************************/
/* 
 * This function is used for multiple tasks to get owner shipof multimedia device,
 * such as audio, camera and video, etc.
 * The previous action on this device will be forced to terminate.
 */
extern void mdi_switch_device_ownership(module_type mod_id, MDI_DEVICE_TYPE device);
extern BOOL mdi_check_device_ownership(void);
extern void mdi_get_ucs2_filename(PS8 p_filename, S32 length, PS8 p_filepath,mdi_naming_type_enum type, mmi_fmgr_filetype_enum ext);

/* get blt data for video camera display - internal by MDI modules */
extern void mdi_calc_blt_para(
                gdi_handle disp_layer_handle, 
                U16 lcd_rotate, 
                gdi_handle lcd_handle,   
                MMI_BOOL is_tvout,
                mdi_blt_para_struct *blt_data_p);

#if 0
/* under construction !*/
/* under construction !*/
#endif
extern void mdi_util_rotate_osd_for_hw_rotator(gdi_handle src_handle, gdi_handle dst_handle);
extern void mdi_util_rotate_osd_partial_region_for_hw_rotator(
                gdi_handle src_handle, 
                S32 offset_x, 
                S32 offset_y, 
                S32 width, 
                S32 height, 
                gdi_handle dst_handle);
extern void mdi_util_rotate_layer_partial_region(
                gdi_handle src_handle, 
                S32 offset_x, 
                S32 offset_y, 
                S32 width, 
                S32 height, 
                gdi_handle dst_handle,
                U8 rotate_angle);

/* message dispatcher, for other task to use MDI library, add to its message handler */
extern MMI_BOOL mdi_message_dispatcher(void *ilm_ptr);
extern MMI_BOOL mdi_util_convert_color_format(gdi_handle layer_handle, U32 src_format, U32 dst_format);
extern void mdi_util_show_not_available_in_call_hint(gdi_handle layer_handle, S32 offset_x, S32 offset_y, S32 width, S32 height);
extern MMI_ID_TYPE mdi_util_get_mdi_error_info(MDI_RESULT error_code, mmi_event_notify_enum* popup_type);

extern gdi_handle mdi_util_hw_layer_create(mdi_util_create_hw_layer_in_struct* in_p, mdi_util_create_hw_layer_out_struct* out_p);
extern gdi_handle mdi_util_hw_layer_create_with_extmemory(mdi_util_create_hw_layer_extmemory_in_struct* in_p, mdi_util_create_hw_layer_out_struct* out_p);
extern gdi_handle mdi_util_hw_layer_create_with_intmemory(mdi_util_create_hw_layer_intmemory_in_struct* in_p, mdi_util_create_hw_layer_out_struct* out_p);

extern void mdi_util_hw_layer_free(gdi_handle layer_handle);
extern GDI_RESULT mdi_util_hw_layer_switch_to_sw_layer(gdi_handle layer_handle);
extern MDI_RESULT mdi_util_hw_layer_get_content(gdi_handle layer_handle, U8 *dst_buff_p, U32 dst_buff_size);
extern U8 mdi_util_remapping_layer_rotate_to_cal_rotate(U8 layer_rotate);
extern void *mdi_util_alloc_mem(U16 app_id, kal_uint8 mem_type, kal_uint32 mem_size, char* file_p, long line_p);
extern void mdi_util_free_mem(U16 app_id, kal_uint8 mem_type, void **mem_addr, char* file_p, long line_p);
extern void mdi_init(void);

#endif /* MDI_INCLUDE */ 

