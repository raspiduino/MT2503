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
#ifndef _IMAGE_VIEWER_GPROT_H_
#define _IMAGE_VIEWER_GPROT_H_

#include "MMI_features.h"

#include "kal_general_types.h"
#include "stack_config.h"
#include "gui_data_types.h"
#include "mmi_frm_events_gprot.h"
#include "FileMgrType.h"
#include "FileMgrSrvGProt.h"
#include "MMIDataType.h"
#include "mmi_rp_file_type_def.h"

    /* reset imageviewr */
#ifdef __MMI_IMAGE_VIEWER_EX__
#include "ImageViewerEXAppGprot.h"
#if defined(__MMI_IMAGE_VIEWER__) || defined(__MMI_FILE_MANAGER__)
/************************************************************************/
/* Define, Struct, Enum                                                 */
/************************************************************************/

#define MMI_IMGVIEW_OK 0
#define MMI_IMGVIEW_ERROR -1
#define MMI_IMGVIEW_ERRTYPE_DRM_INVALID      -2
#define MMI_IMGVIEW_ERRTYPE_DRM_MULTIPART    -3

#define MMI_IMGVIEW_STORAGE_FILEPATH_PHONE            FMGR_DEFAULT_FOLDER_PHOTOS
#define MMI_IMGVIEW_STORAGE_FILEPATH_MEMORY_CARD      FMGR_DEFAULT_FOLDER_PHOTOS

typedef enum
{
    MMI_IMGVIEW_PRINT_NONE = 0,
    MMI_IMGVIEW_PRINT_PICTBRIDGE = 0x0001,
    MMI_IMGVIEW_PRINT_BPP = 0x0002,
    MMI_IMGVIEW_PRINT_ANY_METHOD = 0xFFFF
} mmi_imgview_print_method_enum;

typedef enum
{
    MMI_IMGVIEW_STATE_EXIT,
    MMI_IMGVIEW_STATE_SORTING,
    MMI_IMGVIEW_STATE_SORTING_INT,
    MMI_IMGVIEW_STATE_READY_TO_DECODE,
    MMI_IMGVIEW_STATE_DECODING,
    MMI_IMGVIEW_STATE_DECODE_FINISHED,
    MMI_IMGVIEW_STATE_DECODE_FAILED,
    MMI_IMGVIEW_STATE_ZOOMING_IN,
    MMI_IMGVIEW_STATE_ZOOMING_OUT,
    MMI_IMGVIEW_STATE_MOVING
}mmi_imgview_state_enum;

/* imageviewer pop up result type*/
typedef enum
{
    MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE = 0,
    MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP,
    MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_SCREEN,
    MMI_IMGVIEW_POPUP_RESULT_PROCESS_CONFIRM,
    MMI_IMGVIEW_POPUP_RESULT_PROCESS_CONFIRM_STORAGE,
        
    MMI_IMGVIEW_POPUP_RESULT_PROCESS_ALL
} mmi_imgview_popup_result_process_enum;


/************************************************************************/
/* Extern Variable                                                      */
/************************************************************************/
extern mmi_imgview_state_enum g_imgview_state;
extern SRV_FMGR_FILELIST_HANDLE g_imgview_fl_hdl;
extern S32 g_imgview_fl_idx;
/* Media view CUI part */
extern mmi_id g_mediaview_cui_gid;

/************************************************************************/
/* Extern Functions                                                     */
/************************************************************************/
/* storage setting */
extern void mmi_imgview_hint_set_storage(U16 index);
extern void mmi_imgview_highlight_set_storage(void);
/* view style */
extern void mmi_mediaview_enter_browse_style_screen(void);
extern void mmi_imgview_hint_view_style(U16 index);
extern void mmi_imgview_init_app(void);
extern void mmi_imgview_entry_option_screen(void);
extern void mmi_imgview_exit_from_fmgr(void *filename, int is_shot);
extern void mmi_imgview_entry_view_detail_screen(void);
extern void mmi_imgview_load_setting(void);
extern void mmi_imgview_restore_setting(void);
extern U16  mmi_imgview_get_view_style(void);
extern void mmi_imgview_select_drive_callback( CHAR drv_letter );
extern void mmi_imgview_storage_select_cb(S32 drv_letter );
extern U8 mmi_imgview_del_scr_callback(void* ptr);
extern U8 mmi_imgview_view_from_fmgr_del_scr_callback(void* ptr);
extern void mmi_imgview_view_image_hdlr_ext(CHAR* file_path,BOOL is_short,U16 file_type, U16 title_icon, CHAR* title_str);       
extern BOOL mmi_imgview_is_image_type_printable(mmi_fmgr_filetype_enum image_type,mmi_imgview_print_method_enum method);

extern S32 mmi_imgview_get_storage_file_path(WCHAR *filepath);
extern S32 mmi_imgview_set_storage(U16 storage);
extern U16 mmi_imgview_get_storage(void);
extern void mmi_imgview_set_storage_not_ready(void);
extern void mmi_imgview_set_storage_ready(void);
extern BOOL mmi_imgview_is_storage_ready(void);

extern void mmi_imgview_set_rotate(U16 rotate_value);
extern U16 mmi_imgview_get_rotate(void);
extern void mmi_imgview_service_print_req(CHAR* filepath, U16 title_icon, MMI_BOOL display_warning, U16 ui_rotate, U16 image_type);
extern S32 mmi_imgview_print_enabler(const srv_fmgr_fileinfo_struct* fileinfo);
#if defined(__MMI_BPP_SUPPORT__)
extern void mmi_imgview_cancel_printing(void);
extern void mmi_imgview_deinitial_printing(void);
extern void mmi_imgview_bpp_print_file(CHAR* filepath,BOOL is_short);
#endif
#if defined(__MMI_BPP_SUPPORT__) || defined(__MMI_PICT_BRIDGE_SUPPORT__)
extern void mmi_imgview_option_print_execute_forward(U16 highlight_item);
#endif
#if defined(__DRM_SUPPORT__)
extern void mmi_imgview_start_consume(void);
extern S32 mmi_imgview_get_drm_result(void);
extern void mmi_imgview_consume_drm_if_need(void);
#endif
#if defined(__MMI_SLIDESHOW__)
extern void mmi_imgview_highlight_entry_slideshow(void);
extern void mmi_imgview_entry_slideshow(void);
#endif
#if defined(__MMI_PHOTOEDITOR__)
extern void mmi_imgview_highlight_entry_photoeditor(void);
extern void mmi_imgview_entry_photoeditor(void);
#endif
extern mmi_id mmi_mediaview_get_browse_gid(void);
extern void mmi_mediaview_reset_browse_gid(void);
extern void mmi_imgview_app_reset(void);
extern void mmi_imgview_enter_view_from_cui(mmi_id image_viewer_id);
extern void mmi_imgview_display_popup_sg(mmi_id parent_gid, UI_string_type str_ptr, mmi_event_notify_enum event, U16 rotate, mmi_imgview_popup_result_process_enum process);
extern void mmi_mediaview_close_view_cui(mmi_id *media_viewer_id, U16 evt_id);
extern U16 mmi_mediaview_get_curr_app_id(void);
extern void mmi_mediaview_free_filelist(void);
extern void mmi_mediaview_enter_from_cui(mmi_id media_viewer_id);
extern void mmi_imgview_enter_view_screen(void);
extern void mmi_mediaview_browse_cui_enter_callback(mmi_id browse_gid);
extern void mmi_imgview_change_storage_confirm_yes(void);
extern void mmi_imgview_change_storage_confirm_no(void);
extern S32 mmi_imgview_get_highlight_idx(void);
#ifdef __MMI_VUI_MEDIAWALL__
extern void mmi_mediaview_free_med_memory(void);
extern void mmi_mediaview_free_app_based_memory(void);
extern MMI_BOOL mmi_mediaview_vapp_mediawall_is_terminate(void);
extern void* mmi_mediaview_get_app_based_memory_from_vapp_mediawall(U32 *size);
extern MMI_BOOL mmi_mediaview_vapp_mediawall_is_caller(void);
#endif

/*****************************************************************************
 * FUNCTION
 *    mmi_imgview_launch
 * DESCRIPTION
 *  launch image viewer application to view an all image filelist.
 * PARAMETERS
 *
 * RETURNS
 *  MMI_ID.
 *****************************************************************************/
extern void mmi_imgview_launch(void);


/*****************************************************************************
 * FUNCTION
 *    mmi_imgview_simple_launch
 * DESCRIPTION
 *  simple wrapper for cui.
 * PARAMETERS
 *
 * RETURNS
 *  MMI_ID.
 *****************************************************************************/
extern void mmi_imgview_simple_launch(PS8 file_path, U16 string, U16 icon);


/*****************************************************************************
 * FUNCTION
 *    mmi_imgview_close
 * DESCRIPTION
 *  close application of image viewer.
 * PARAMETERS
 *  image_viewer_id: [IN] parent id.
 * RETURNS
 *  None.
 *****************************************************************************/
extern void mmi_imgview_close(mmi_id image_viewer_id);


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_browser_cui_proc
 * DESCRIPTION
 *  handle event comes from browser cui
 * PARAMETERS
 *  evt                 [IN]        event struct
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_mediaview_browser_cui_proc(mmi_event_struct *evt);


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_sap_send_msg
 * DESCRIPTION
 *  send message
 * PARAMETERS
 *  src:    [IN] src module.
 *  dst:    [IN] dst module.
 *  msg_id: [IN] message id.
 *  local_param_ptr:    [IN] message body.
 * RETURNS
 *  None.
 *****************************************************************************/
extern void mmi_imgview_sap_send_msg(module_type src, module_type dst, U32 msg_id, void *local_param_ptr);

#endif /* __MMI_IMAGE_VIEWER__ */ 

#ifdef __MMI_SNS_PHOTO_UPLOAD__
extern MMI_BOOL mmi_imgview_sns_photo_upload_check(const WCHAR* filepath);
#endif /* __MMI_SNS_PHOTO_UPLOAD__ */

#else 
#include "ImgViewerGprot.h"
#endif	/*__MMI_IMAGE_VIEWER_EX__*/


#endif /* _IMAGE_VIEWER_GPROT_H_*/ 

