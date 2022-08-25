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
 *  ImageViewer.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  ImageViewer's header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _IMAGE_VIEWER_H_
#define _IMAGE_VIEWER_H_

#include "MMI_features.h"
#include "FileMgrCuiGprot.h"
#include "ImageViewCuiGprot.h"

#ifdef __MMI_IMAGE_VIEWER_EX__
#include "ImageViewerEXAppGprot.h"
#endif


#if defined(__MMI_IMAGE_VIEWER__) || defined(__MMI_FILE_MANAGER__)

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "fs_type.h"

/************************************************************************/
/* Define, Struct, Enum                                                 */
/************************************************************************/
#if defined(__MMI_NONBLOCKING_DECODE__)
#define __MMI_IMGVIEW_NONBLOCKING_DECODE__
#endif

#if (!defined(__MMI_FTE_SUPPORT__))
#ifndef __MMI_IMGVIEW_CSK_ENABLE__
#define __MMI_IMGVIEW_CSK_ENABLE__
#endif /* __MMI_IMGVIEW_CSK_ENABLE__ */
#else
#ifdef __MMI_IMGVIEW_CSK_ENABLE__
#undef __MMI_IMGVIEW_CSK_ENABLE__
#endif /* __MMI_IMGVIEW_CSK_ENABLE__ */
#endif

#define MMI_IMGVIEW_OK                      0
#define MMI_IMGVIEW_ERROR                   -1
#define MMI_IMGVIEW_ERRTYPE_DRM_INVALID     -2
#define MMI_IMGVIEW_ERRTYPE_DRM_MULTIPART   -3

#define MMI_IMGVIEW_STORAGE_FILEPATH_PHONE            FMGR_DEFAULT_FOLDER_PHOTOS
#define MMI_IMGVIEW_STORAGE_FILEPATH_MEMORY_CARD      FMGR_DEFAULT_FOLDER_PHOTOS

#ifdef __DRM_SUPPORT__
typedef enum
{
    IMGVIEW_DRM_STATE_EXIT = 0,
    IMGVIEW_DRM_STATE_CONSUME,    
    IMGVIEW_DRM_STATE_PAUSE,

    IMGVIEW_DRM_STATE_TOTAL_COUNT
}imgview_drm_state_enum;
typedef enum
{
    IMGVIEW_DRM_NOT_DRM_FILE = 0,
    IMGVIEW_DRM_DRM_FILE = 0x00000001,
    IMGVIEW_DRM_DISPLAY_VALID = 0x00000010,
    IMGVIEW_DRM_PRINT_VALID   = 0x00000100,
    IMGVIEW_DRM_MULTI_PART   = 0x00001000,
    IMGVIEW_DRM_MIMETYPE_NON_IMAGE= 0x00010000
  
}imgview_drm_ret_enum;
#endif /* __DRM_SUPPORT__ */

typedef struct
{
    void* app_mem_buf_p;
    S32 app_mem_buf_size;
    void* med_mem_buf_p;
    S32 med_mem_buf_size;
    MMI_BOOL is_vapp_call;
    MMI_BOOL is_vapp_used;
} mmi_imgview_memory_struct;

typedef struct
{
    CHAR *filepath;
    CHAR *title_str;
    U16 storage;
    BOOL is_storage_path_changed;
    MMI_BOOL is_storage_ready;
    U16 imgview_rotate;
    MMI_BOOL is_change_image;
    U32 drv_inline_list_p;
    #if defined(__MMI_BPP_SUPPORT__)
    U8                          *bpp_caption;
    U8                          *bpp_filepath;
    U32                         file_size;
    #endif
    U16 file_type;
    MMI_BOOL is_short;
    U16 image_type;
    U16 title_icon;

    BOOL print_support;
    U16                         err_str_ptr;
    GDI_RESULT                  result;
    mmi_id      fmgr_scr_id;
    mmi_id      app_id;
    MMI_BOOL   is_entry_browse;
#ifdef __DRM_SUPPORT__
    imgview_drm_state_enum      drm_state;
    U32                         drm_id;
    imgview_drm_ret_enum        drm_valid;
    FS_HANDLE                   drm_handle;
#endif
    U16 caller_app_id;
    U16 is_view_app;
    mmi_imgview_memory_struct memory_info;

    /* when get infomation from filelist, it may return file not ready,
     * so need to load the file manually */
    MMI_BOOL                    is_refreshing;  
} imgview_context_struct;

typedef enum
{
    IMGVIEW_VIEW_STYLE_LIST,
    IMGVIEW_VIEW_STYLE_MATRIX,
    IMGVIEW_VIEW_STYLE_WALLVIEW
} imgview_view_style_enum;

/*********** Storage ***********/
typedef enum
{
    MMI_IMGVIEW_STORAGE_PHONE,
    MMI_IMGVIEW_STORAGE_MEMORY_CARD,
    MMI_IMGVIEW_STORAGE_TOTAL
} mmi_imgview_storage;

static void mmi_imgview_exit_view_detail_screen(void);
static void mmi_imgview_view_detail_press_up(void);
static void mmi_imgview_view_detail_press_down(void);
static void mmi_imgview_exit_view_detail_release(void);
static void mmi_imgview_entry_set_storage_screen(void);
static cui_mediaview_style_enum mmi_mediaview_get_view_style(void);
static void mmi_mediaview_set_view_style(cui_mediaview_style_enum value);
/*static cui_mediaview_style_enum mmi_mediaview_transfer_style_fmgr_to_view(cui_fmgr_ui_style_enum value);*/
static cui_fmgr_ui_style_enum mmi_mediaview_transfer_style_view_to_fmgr(cui_mediaview_style_enum value);
static MMI_ID_TYPE mmi_imgview_get_error_string_by_error_enum(S32 err_code);
static mmi_ret mmi_imgview_load_file_proc(mmi_event_struct *param);

/* image util funtion */
#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
#endif
static void mmi_imgview_view_image_hdlr_internal(void);
static void mmi_imgview_exit_view_image_hdlr(void);
static void mmi_imgview_exit_image_screen(void);
static void mmi_imgview_cat222_decode_result_hdlr(GDI_RESULT result);
static void mmi_imgview_print_req(void);
#if defined(__DRM_SUPPORT__)
static void mmi_imgview_drm_callback_hdlr(kal_int32 result, kal_int32 id);
static imgview_drm_ret_enum mmi_imgview_process_drm_hdlr(void);
static void mmi_imgview_preprocess_drm_right(void);
#endif /* defined(__DRM_SUPPORT__) */
static void mmi_imgview_lsk_custmize_confirmed(void);
/* Media view cui part */
static MMI_BOOL mmi_mediaview_browse_cui_enter(mmi_id parent_gid, const WCHAR* folder_path, U16 opt_menu_id, U16 opt_empty_menu_id);
static S32 mmi_mediaview_create_filelist(void);
static mmi_ret mmi_mediaview_screen_leave_proc(mmi_event_struct *evt);
#endif /* __MMI_IMAGE_VIEWER__ */ 
#endif /* _IMAGE_VIEWER_H_ */ 

