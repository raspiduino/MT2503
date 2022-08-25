/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  CubeAppImgview.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Cube Image View  Header File
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_3D_CUBE_APP_IMGVIEW__

#define MMI_CUBE_IMGVIEW_LAYER_INDEX_ERROR (-1)
#define MMI_CUBE_IMGVIEW_CURR_DECODE_NONE (-1)

typedef void (*mmi_cube_imgview_sort_callback) (void *user_data, S32 file_count, S32 sort_state);
typedef void (*mmi_cube_imgview_file_decode_callback) (void *user_data, S32 index, void *memory_addr, S32 result,
                                                       S32 mode);

typedef enum
{
    MMI_CUBE_IMGVIEW_FILE_DECODE_OVER,
    MMI_CUBE_IMGVIEW_FILE_DECODE_ERROR,
    MMI_CUBE_IMGVIEW_FILE_DECODE_DOING,

    MMI_CUBE_IMGVIEW_FILE_DECODE_ALL
} mmi_cube_imgview_file_decode_result_enum;

typedef enum
{
    MMI_CUBE_IMGVIEW_SORT_STATE_IDLE = 0,
    MMI_CUBE_IMGVIEW_SORT_STATE_DOING,
    MMI_CUBE_IMGVIEW_SORT_STATE_OVER,
    MMI_CUBE_IMGVIEW_SORT_STATE_INVALID,

    MMI_CUBE_IMGVIEW_SORT_STATE_ALL
} mmi_cube_imgview_sort_state_enum;

typedef enum
{
    MMI_CUBE_IMGVIEW_MEMORY_SOURCE_UNKNOWN = 0,
    MMI_CUBE_IMGVIEW_MEMORY_SOURCE_APP_MEM,
    MMI_CUBE_IMGVIEW_MEMORY_SOURCE_SCRN_MEM,
    MMI_CUBE_IMGVIEW_MEMORY_SOURCE_GDI_MEM,

    MMI_CUBE_IMGVIEW_MEMORY_SOURCE_ALL
} mmi_cube_imgview_memory_source_enum;

typedef enum
{
    MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_IDLE,
    MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_WAITING_FOR_DECODE,
    MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODING,
    MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_OVER,
    MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_OVER_BUT_BLUR,
    MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_ERROR,

    MMI_CUBE_IMGVIEW_CACHE_LAYER_STATE_ALL
} mmi_cube_imgview_cache_layer_state_enum;

typedef enum
{
    MMI_CUBE_IMGVIEW_MODE_UNKNOWN = 0,
    MMI_CUBE_IMGVIEW_MODE_NAVIGATION,
    MMI_CUBE_IMGVIEW_MODE_VIEW,
    MMI_CUBE_IMGVIEW_MODE_TURN_TO_BACK,
    MMI_CUBE_IMGVIEW_MODE_TURN_TO_FRONT,
    MMI_CUBE_IMGVIEW_MODE_TURN_TO_BLUR,

    MMI_CUBE_IMGVIEW_MODE_ALL
} mmi_cube_imgview_mode_enum;

typedef struct
{
    mmi_cube_imgview_cache_layer_state_enum state;
    S32 index;
    gdi_handle handle;
    void *mem_addr;
    void *mem_addr2;
    mmi_cube_imgview_memory_source_enum memory_source;
    mmi_cube_imgview_mode_enum mode;
    S32 real_offset_x;
    S32 real_offset_y;
    S32 real_width;
    S32 real_height;
    MMI_BOOL is_using;
    S32 draw_source;
} mmi_cube_imgview_file_layer_struct;

typedef struct
{
    void *user_data;
    mmi_cube_imgview_sort_callback sort_callback;
    mmi_cube_imgview_sort_state_enum sort_state;
    fmgr_filelist_handle fl;
    U16 file_path[(SRV_FMGR_PATH_MAX_LEN+1)];
    U16 folder_path[(SRV_FMGR_PATH_MAX_LEN+1)];
    U16 file_name[FMGR_MAX_FILE_LEN + 1];
    mmi_cube_imgview_file_layer_struct layers[MMI_VAPP_CUBE_IMGVIEW_LAYER_COUNT];
    S32 curr_decode_index;
    S32 curr_decode_mode;
    mmi_cube_imgview_file_decode_callback decode_cb;
    void *decode_user_data;

    /* cache related */
    S32 cache_focus_index;
    srv_handle cache_handle;
    /* PS32 cache_handle; */
    void *cache_run_buffer;
    S32 cache_run_buffer_size;
    void *cache_db_buffer;
    S32 cache_db_buffer_size;
    void *cache_small_buffer;
    S32 cache_small_buffer_size;
    S32 cache_small_image_width;
    S32 cache_small_image_height;
    void *cache_large_buffer;
    S32 cache_large_buffer_size;
    S32 cache_large_image_width;
    S32 cache_large_image_height;
    MMI_BOOL is_small_image_dec_pause;
    MMI_BOOL is_large_image_dec_pause;
    S8 curr_drv;
} mmi_cube_imgview_cntx_struct;

extern S32 mmi_cube_imgview_get_file_count(void);
extern S32 mmi_cube_imgview_get_sort_state(void);
extern S32 mmi_cube_imgview_create_file_list(
            void *user_date,
            PU16 path,
            FMGR_FILTER filter,
            U16 sort_type,
            mmi_cube_imgview_sort_callback sort_callback);
extern S32 mmi_cube_imgview_get_file_list(void);
extern void mmi_cube_imgview_free_file_list(void);
extern PU16 mmi_cube_imgview_get_file_path(S32 index);
extern void *mmi_cube_imgview_get_file_layer_memory(
                S32 idnex,
                S32 target_width,
                S32 target_height,
                S32 mode,
                PS32 result);
extern void mmi_cube_imgview_free_file_layer_memory(S32 index, S32 mode);
extern void mmi_cube_imgview_get_file_layer_real_size(
                S32 index,
                PS32 offset_x,
                PS32 offset_y,
                PS32 width,
                PS32 height,
                S32 mode);
extern void mmi_cube_imgview_set_small_image(S32 image_width, S32 image_height);
extern void mmi_cube_imgview_set_large_image(S32 image_width, S32 image_height);
extern void mmi_cube_imgview_create_cache(void);
extern void mmi_cube_imgview_close_cache(void);
extern void mmi_cube_imgview_register_decode_cb(void *user_data, mmi_cube_imgview_file_decode_callback cb);
extern void mmi_cube_imgview_get_layer_info(gdi_handle handle, PS32 width, PS32 height);
extern void mmi_cube_imgview_change_to_navigation_mode(S32 index);
extern void mmi_cube_imgview_change_to_view_mode(S32 index);
extern void mmi_cube_imgview_focus_change(S32 index, S32 mode);
extern void mmi_cube_imgview_resume_cache(void);
extern void mmi_cube_imgview_pause_cache(void);
extern void mmi_cube_imgview_pause_navigation_mode_decode(void);
extern void mmi_cube_imgview_resume_navigation_mode_decode(void);
extern U16 mmi_cube_imgview_get_forbid_item_info(void);

#endif /* __MMI_VUI_3D_CUBE_APP_IMGVIEW__ */ 

