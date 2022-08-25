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
 *  ImageViewerCommon.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Image Viewer Common Api
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#include "GlobalConstants.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "fs_func.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "gui_data_types.h"
#include "gui_typedef.h"
#include "gui.h"        /* Gui functions */
#include "wgui_categories_text_viewer.h"
#include "wgui_categories_util.h"
#include "MMIDataType.h"
#include "mmi_rp_file_type_def.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "Unicodexdcl.h"
#include "GlobalResDef.h"
#include "CustDataRes.h"
#include "drm_def.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mmi_media_app_trc.h"
#include "AlertScreen.h"
#include "GlobalMenuItems.h"
#include "CustMenuRes.h"
#include "string.h"
#include "FileMgrServiceResDef.h"

#include "FileMgrSrvGProt.h"
#include "FileMgrType.h"
#include "FileMgrServiceHdlr.h"

#if defined(__MMI_BPP_SUPPORT__)
#if 1 /* BPP split */
#include "BppCuiGprot.h"
#else
/* under construction !*/
#endif /* BPP split */
#include "phonesetupgprots.h"
#include "conversions.h"
#endif

#ifdef __MMI_BT_SUPPORT__
#include "BTMMIScrGprots.h"
#endif

#include "MMI_features_camera.h"        /* features - in custom folder */
#include "ImageViewerGprot.h"
#include "mmi_rp_app_imageviewer_def.h"
#include "Drm_gprot.h"  /* DRM support */
#include "RightsMgrGProt.h"

#if defined(__MMI_SCREEN_ROTATE__)
#include "ScreenRotationGprot.h"
#endif

#ifdef __MMI_SNS_PHOTO_UPLOAD__
#include "SnsAppGprot.h"
#endif

#if defined(__MMI_IMAGE_VIEWER__) || defined(__MMI_FILE_MANAGER__)

#define MMI_IMGVIEW_END_OF_IAMGE_TYPE -1
#if defined(__MMI_PICT_BRIDGE_SUPPORT__)
const S32 g_imgview_print_pictbridge_table[] =
{
    FMGR_TYPE_JPG,
    FMGR_TYPE_JPEG,

    /* MUST ADD */
    MMI_IMGVIEW_END_OF_IAMGE_TYPE
};
#endif /* defined(__MMI_PICT_BRIDGE_SUPPORT__) */

#if defined(__MMI_BPP_SUPPORT__)
#if 0 /* BPP split */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else

static const S32 g_imgview_print_bpp_table[] =
{
    FMGR_TYPE_BMP,
    FMGR_TYPE_JPG,
    FMGR_TYPE_JPEG,
    FMGR_TYPE_GIF,
    FMGR_TYPE_PNG,
    FMGR_TYPE_WBMP,
    FMGR_TYPE_WBM,
    FMGR_TYPE_SVG,

    /* MUST ADD */
    MMI_IMGVIEW_END_OF_IAMGE_TYPE
};
#endif /* BPP split */
#if 0 /* BPP split */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* BPP split */
static void mmi_imgview_drm_print_callback_hdlr(kal_int32 result, kal_int32 id);
#endif /* defined(__MMI_BPP_SUPPORT__) */


static void mmi_imgview_enter_fmgr_print_option_screen(void);
static U8 mmi_imgview_del_confirm_print_scr_callback(void* ptr);
static void mmi_imgview_confirm_print_screen(void);

typedef struct
{
    CHAR* filepath;
    U16 title_icon;
    U16 ui_rotate;

    U16 image_type;
    #if defined(__MMI_BPP_SUPPORT__)
    BOOL is_short;
    MMI_BOOL is_first;/* if the first preview, that is to say no zoom in*/
    U8 *bpp_caption;
    U8 *bpp_filepath;
    U32 file_size;
    S32 image_width;/*pixel*/
    S32 image_height;
    S32 image_area_width;/*mm in paper*/
    S32 image_area_height;
    S32 keep_previous_width;/*mm in paper for zoom*/
    S32 keep_previous_height;
    GDI_RESULT error_ret;
    #endif
    mmi_id parent_gid;
    MMI_ID gid;

}mmi_imgview_print_req_struct;

mmi_imgview_print_req_struct g_mmi_imgview_print_cntx;
extern mmi_imgview_state_enum g_imgview_state;
extern SRV_FMGR_FILELIST_HANDLE g_imgview_fl_hdl;
extern S32 g_imgview_fl_idx;


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_service_print_req
 * DESCRIPTION
 *  imageviewer print service, it can be only used by image viewer, not extern API for other APP.
 * PARAMETERS
 *  CHAR* filename
 *  U16 title_icon
 *  MMI_BOOL display warning screen or not
 *  U16 ui rotate for warning screen.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_service_print_req(CHAR* filepath, U16 title_icon, MMI_BOOL display_warning, U16 ui_rotate, U16 image_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_imgview_print_cntx.filepath == NULL)
        g_mmi_imgview_print_cntx.filepath = gui_malloc(SRV_FMGR_PATH_BUFFER_SIZE);

    mmi_ucs2cpy(g_mmi_imgview_print_cntx.filepath,filepath);

    g_mmi_imgview_print_cntx.title_icon = title_icon;
    g_mmi_imgview_print_cntx.ui_rotate = ui_rotate;
    g_mmi_imgview_print_cntx.image_type = image_type;
    if (display_warning == MMI_FALSE)
    {
    #if defined(__MMI_PICT_BRIDGE_SUPPORT__) || defined(__MMI_BPP_SUPPORT__)
        mmi_fmgr_image_print_by_imgviewer(g_mmi_imgview_print_cntx.filepath, g_mmi_imgview_print_cntx.title_icon);
    #endif
        gui_free(g_mmi_imgview_print_cntx.filepath);
        g_mmi_imgview_print_cntx.filepath = NULL;
    }
    else
    {
        mmi_imgview_confirm_print_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_del_confirm_print_scr_callback
 * DESCRIPTION
 *  imgview delete screen callback handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_imgview_del_confirm_print_scr_callback(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_imgview_print_cntx.filepath != NULL)
    {
        gui_free(g_mmi_imgview_print_cntx.filepath);
        g_mmi_imgview_print_cntx.filepath = NULL;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_confirm_print_scr_leave_proc
 * DESCRIPTION
 *  Image view print confirm screen leave proc.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static mmi_ret mmi_imgview_confirm_print_scr_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
    case EVT_ID_SCRN_GOBACK:
        break;
    case EVT_ID_SCRN_DELETE_REQ:
        break;
    case EVT_ID_SCRN_DEINIT:
        mmi_imgview_del_confirm_print_scr_callback(NULL);
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_confirm_print_screen
 * DESCRIPTION
 *  imgview delete screen callback handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgview_confirm_print_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* buffer;
    S32 buffersize;
    MMI_BOOL entry_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_imgview_print_cntx.parent_gid = mmi_frm_group_get_active_id();
    entry_ret = mmi_frm_scrn_enter(g_mmi_imgview_print_cntx.parent_gid, SCR_ID_IMGVIEW_CONFIRM_PRINT_SCREEN, NULL, mmi_imgview_confirm_print_screen, MMI_FRM_FULL_SCRN);
    if (!entry_ret)
    {
        return;
    }
    mmi_frm_scrn_set_leave_proc(g_mmi_imgview_print_cntx.parent_gid, SCR_ID_IMGVIEW_CONFIRM_PRINT_SCREEN, mmi_imgview_confirm_print_scr_leave_proc);

#if defined(__MMI_SCREEN_ROTATE__)
    //mmi_frm_screen_rotate(g_mmi_imgview_print_cntx.ui_rotate);
#endif
    buffer = GetString(STR_ID_IMGVIEW_CONFIRM_PRINT);
    buffersize = mmi_ucs2strlen(buffer);

    ShowCategory74Screen(
        STR_GLOBAL_PRINT,
        g_mmi_imgview_print_cntx.title_icon,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8)buffer,
        buffersize,
        NULL);

    /* PRINT */
    SetLeftSoftkeyFunction(mmi_imgview_enter_fmgr_print_option_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_enter_fmgr_print_option_screen
 * DESCRIPTION
 *  BPP print callback function, called by bpp to give event of print job
 * PARAMETERS
 *  mmi_bpp_xhtml_rsp_enum rsp_code Response Code
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgview_enter_fmgr_print_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PICT_BRIDGE_SUPPORT__) || defined(__MMI_BPP_SUPPORT__)
    mmi_fmgr_image_print_by_imgviewer(g_mmi_imgview_print_cntx.filepath, g_mmi_imgview_print_cntx.title_icon);
#endif
    gui_free(g_mmi_imgview_print_cntx.filepath);
    g_mmi_imgview_print_cntx.filepath = NULL;

    mmi_frm_scrn_close(g_mmi_imgview_print_cntx.parent_gid, SCR_ID_IMGVIEW_CONFIRM_PRINT_SCREEN);
}


#if defined(__MMI_BPP_SUPPORT__)
#if 0 /* BPP split */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* BPP split */

#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_drm_print_callback_hdlr
 * DESCRIPTION
 *  drm right timeout hdlr
 * PARAMETERS
 *  S32  result
 *  S32  id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgview_drm_print_callback_hdlr(kal_int32 result, kal_int32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* dummy api */

}
#endif

static MMI_RET imgview_print_proc(mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_BT_PRINT_COMPLETE)
    {
#ifdef __DRM_SUPPORT__
        evt_bt_print_complete_struct *data =
            (evt_bt_print_complete_struct *)evt;

        if (data->result)
        {
            U16 *path = (U16 *)g_mmi_imgview_print_cntx.bpp_filepath;
            if (DRM_get_object_method(0, path) != DRM_METHOD_NONE)
            {
                if (DRM_validate_permission(0, path, DRM_PERMISSION_PRINT))
                {
                    U32 drm_id = 0;
                    FS_HANDLE handle;

                    handle = DRM_open_file(path, FS_READ_ONLY, DRM_PERMISSION_PRINT);
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGADV_BPP_FILE_HANDLE, handle);
                    MMI_ASSERT(handle >= FS_NO_ERROR);

                    drm_id = DRM_consume_rights(
                                handle,
                                DRM_PERMISSION_PRINT,
                                mmi_imgview_drm_print_callback_hdlr);
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IMGADV_BPP_CONSUME_DRM_ID, drm_id);

                    DRM_stop_consume(drm_id);
                    DRM_close_file(handle);

#ifdef __MMI_RMGR_EXTEND_RIGHTS_AFTER_EXIT_AP__
                    if (MMI_RMGR_STATUS_REQUEST_RIGHTS == mmi_rmgr_extend_rights_by_path(path, DRM_PERMISSION_PRINT, 0))
                    {
                        mmi_rmgr_set_ro_bound_path(path);
                        mmi_rmgr_request_rights_confirm();
                    }
#endif /* __MMI_RMGR_EXTEND_RIGHTS_AFTER_EXIT_AP__ */
                }
            }
        }
#endif /* __DRM_SUPPORT__ */

        mmi_frm_group_close(g_mmi_imgview_print_cntx.gid);

        if(g_mmi_imgview_print_cntx.bpp_filepath)
        {
            OslMfree(g_mmi_imgview_print_cntx.bpp_filepath);
            g_mmi_imgview_print_cntx.bpp_filepath = NULL;
        }
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_bpp_print_file
 * DESCRIPTION
 *  external BPP print function, forward to BPP Engine
 * PARAMETERS
 *  filepath IN filepath of printed file
 *  is_short IN one property of filepath
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_bpp_print_file(CHAR* filepath,BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle;
    GDI_RESULT                  result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mmi_imgview_print_cntx.error_ret = GDI_SUCCEED;
    /* get image type from filepath */
    g_mmi_imgview_print_cntx.image_type = gdi_image_get_type_from_file(filepath);
    switch(g_mmi_imgview_print_cntx.image_type)
    {
        case GDI_IMAGE_TYPE_JPG :
        case GDI_IMAGE_TYPE_JPG_FILE :
        case GDI_IMAGE_TYPE_GIF :
        case GDI_IMAGE_TYPE_GIF_FILE :
        case GDI_IMAGE_TYPE_BMP :
        case GDI_IMAGE_TYPE_BMP_FILE :
        case GDI_IMAGE_TYPE_PNG :
        case GDI_IMAGE_TYPE_PNG_FILE:
        case GDI_IMAGE_TYPE_WBMP :
        case GDI_IMAGE_TYPE_WBMP_FILE:
        case GDI_IMAGE_TYPE_SVG :
        case GDI_IMAGE_TYPE_SVG_FILE:
            break;
        default:
            mmi_popup_display(
                (WCHAR *)GetString(STR_ID_IMGVIEW_PRINT_NOT_SUPPORT),
                MMI_EVENT_FAILURE,
                NULL);
            return;
    }

    result = gdi_image_get_dimension_file((CHAR*)filepath, (S32*) &g_mmi_imgview_print_cntx.image_width, (S32*)&g_mmi_imgview_print_cntx.image_height);
    if (((g_mmi_imgview_print_cntx.image_width <= 0) || (g_mmi_imgview_print_cntx.image_height <= 0)) ||
        result < 0)
    {
        mmi_popup_display(
            (WCHAR *)GetString(STR_ID_IMGVIEW_PRINT_NOT_SUPPORT),
            MMI_EVENT_FAILURE,
            NULL);
        return;
    }

#if 1 /* BPP split */
    fs_handle = DRM_open_file((U16*)filepath, FS_READ_ONLY, DRM_PERMISSION_PRINT);

    if (fs_handle < 0)
    {
        mmi_popup_display(
            (WCHAR *)GetString(srv_fmgr_fs_error_get_string(fs_handle)),
            (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(fs_handle),
            NULL);

        if (fs_handle == FS_PATH_NOT_FOUND || fs_handle == FS_ACCESS_DENIED)
        {
            if (mmi_frm_group_is_present(g_mmi_imgview_print_cntx.parent_gid))
            {
                mmi_frm_group_close(g_mmi_imgview_print_cntx.parent_gid);
            }
            if (mmi_frm_group_is_present(g_mediaview_cui_gid))
            {
                mmi_frm_group_close(g_mediaview_cui_gid);
            }
        }
        return;
    }

#ifdef __DRM_SUPPORT__
    if(!DRM_validate_permission(fs_handle, NULL, DRM_PERMISSION_PRINT))
    {
        mmi_popup_display(
            (WCHAR *)GetString(STR_GLOBAL_DRM_PROHIBITED),
            MMI_EVENT_FAILURE,
            NULL);

        DRM_close_file(fs_handle);

        return;
    }
#endif

    DRM_file_size(fs_handle, (kal_uint32*) &(g_mmi_imgview_print_cntx.file_size));
    DRM_close_file(fs_handle);

    g_mmi_imgview_print_cntx.bpp_filepath = gui_malloc(SRV_FMGR_PATH_BUFFER_SIZE);

    mmi_ucs2cpy((CHAR*) g_mmi_imgview_print_cntx.bpp_filepath , (CHAR*) filepath);

    {
        bt_print_data_struct data;
        MMI_ID gid = mmi_frm_group_create(
                            GRP_ID_ROOT,
                            GRP_ID_AUTO_GEN,
                            (mmi_proc_func)imgview_print_proc,
                            NULL);

        data.content_type = BT_PRINT_CONTENT_IMAGE;
        data.type = BT_PRINT_DATA_FILE;
        data.u.file = (WCHAR *)g_mmi_imgview_print_cntx.bpp_filepath;
        data.size = g_mmi_imgview_print_cntx.file_size;
        data.more = MMI_FALSE;
        mmi_frm_group_enter(gid, MMI_FRM_NODE_NONE_FLAG);

        if (!cui_bt_printing_launch(gid, BT_PRINT_IMAGE, &data, 0))
        {
            mmi_frm_group_close(gid);
            gui_free(g_mmi_imgview_print_cntx.bpp_filepath);
        }
        g_mmi_imgview_print_cntx.gid = gid;
    }
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if defined(__DRM_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else /* defined(__DRM_SUPPORT__) */
/* under construction !*/
    #endif /* defined(__DRM_SUPPORT__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* BPP split */
}

#endif /* __MMI_BPP_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_print_enabler
 * DESCRIPTION
 *  image viewer function to check if the send menu items(like "BT", "BBP") could be used.
 *  if the item could not be used, then hide the item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_imgview_print_enabler(const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	#if defined(__MMI_PICT_BRIDGE_SUPPORT__) || defined(__MMI_BPP_SUPPORT__)
    mmi_fmgr_filetype_enum type;
	#endif
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //type = srv_fmgr_types_get_main_type(&(fileinfo->type));
   	#if defined(__MMI_PICT_BRIDGE_SUPPORT__) || defined(__MMI_BPP_SUPPORT__)
    type = (mmi_fmgr_filetype_enum)fileinfo->type;
	#endif
    /* handle PRINT_PICTBRIDGE / PRINT_BLUETOOTH */

#if defined(__MMI_PICT_BRIDGE_SUPPORT__)
    /* PRINT_PICTBRIDGE
     */
    if (!mmi_imgview_is_image_type_printable(type, MMI_IMGVIEW_PRINT_PICTBRIDGE))
    {
        mmi_frm_hide_menu_item(MENU_ID_FMGR_PRINT_PICTBRIGE);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_FMGR_PRINT_PICTBRIGE);
        count++;
    }
#endif

#if defined(__MMI_BPP_SUPPORT__)
    /* PRINT_BLUETOOTH
     *  only support when not in Flight mode
     */
    if (!mmi_bt_is_to_display_bt_menu() ||
        !mmi_imgview_is_image_type_printable(type, MMI_IMGVIEW_PRINT_BPP))
    {
        mmi_frm_hide_menu_item(MENU_ID_FMGR_PRINT_BLUETOOTH);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_FMGR_PRINT_BLUETOOTH);
        count++;
    }
#endif

    return count;
}


/*****************************************************************************
*
* Image Viewer View Large Image
*
*****************************************************************************/
BOOL mmi_imgview_is_image_type_printable(filetypes_file_type_enum image_type, mmi_imgview_print_method_enum method)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL is_printable = FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ( method & MMI_IMGVIEW_PRINT_ANY_METHOD )
    {
        if (method & MMI_IMGVIEW_PRINT_PICTBRIDGE)
        {
            #if defined(__MMI_PICT_BRIDGE_SUPPORT__)
            U16 i = 0;
            while (g_imgview_print_pictbridge_table[i] != MMI_IMGVIEW_END_OF_IAMGE_TYPE)
            {
                if (g_imgview_print_pictbridge_table[i] == image_type)
                {
                    is_printable = TRUE;
                    break;
                }
                i++;
            }
            #endif
        }

    #ifdef __MMI_BT_SUPPORT__
        if ((method & MMI_IMGVIEW_PRINT_BPP) && mmi_bt_is_to_display_bt_menu())
    #else
        if (method & MMI_IMGVIEW_PRINT_BPP)
    #endif
        {
            #if defined(__MMI_BPP_SUPPORT__)
            U16 i = 0;
            while (g_imgview_print_bpp_table[i] != MMI_IMGVIEW_END_OF_IAMGE_TYPE)
            {
                if (g_imgview_print_bpp_table[i] == image_type)
                {
                    is_printable = TRUE;
                    break;
                }
                i++;
            }
            #endif
        }
    }
    return is_printable;
}


/*****************************************************************************
*
* Image Viewer menu items which inserted to fmgr option
*
*****************************************************************************/
static WCHAR* g_imgviewer_img_info_filepath = NULL;
static MMI_ID g_imgviewer_img_info_parent_gid = GRP_ID_INVALID;
static void mmi_imgview_entry_img_info_screen(void);
static mmi_ret mmi_imgview_img_info_screen_leave_proc(mmi_event_struct *para);
static void mmi_imgview_img_info_handler(const WCHAR* filepath, MMI_ID parent_gid);
static void mmi_imgview_img_info_enabler(const WCHAR* filepath);

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_file_type_enabler
 * DESCRIPTION
 *  for fmgr option item "image information"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_file_type_enabler(mmi_menu_id item_id, const WCHAR* filepath,
                                          const srv_fmgr_fileinfo_struct* fileinfo)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(item_id)
    {
    case MENU_ID_IMGVIEW_OPTION_IMG_INFORMATION:
        mmi_imgview_img_info_enabler(filepath);
        break;

    default:
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_file_type_handler
 * DESCRIPTION
 *  for fmgr option item "image information"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_file_type_handler(mmi_menu_id item_id, const WCHAR* filepath,
                                          const srv_fmgr_fileinfo_struct* fileinfo)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(item_id)
    {
    case MENU_ID_IMGVIEW_OPTION_IMG_INFORMATION:
        mmi_imgview_img_info_handler(filepath, GRP_ID_ROOT);
        break;

    default:
        break;
    }
}


static void mmi_imgview_img_info_enabler(const WCHAR* filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER file_type;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&file_type);
    ret = srv_fmgr_types_find_type_by_filepath(filepath);
    if(ret >= 0)
    {
        FMGR_FILTER_SET(&file_type, ret);
        ret = 0;

        if(FMGR_FILTER_IS_SET_IMAGE(&file_type) == MMI_FALSE)
        {
            mmi_frm_hide_menu_item(MENU_ID_IMGVIEW_OPTION_IMG_INFORMATION);
        }
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_IMGVIEW_OPTION_IMG_INFORMATION);
    }
}

static void mmi_imgview_img_info_handler(const WCHAR* filepath, MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgviewer_img_info_filepath = OslMalloc((mmi_ucs2strlen((CHAR*)filepath) + 1) * ENCODING_LENGTH);

    mmi_ucs2cpy((CHAR*)g_imgviewer_img_info_filepath, (CHAR*)filepath);

    g_imgviewer_img_info_parent_gid = parent_gid;

    mmi_imgview_entry_img_info_screen();
}


static S32 mmi_imgview_jpg_info_print_buffer(gdi_image_jpeg_exif_info_struct* exif_info, WCHAR *buffer)
{
    S32 count = 0;

#ifdef __MMI_EXIF__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define EXIF_STR_ID_START   STR_ID_FMGR_EXIF_MAKE
#define EXIF_STR_ID_END   STR_ID_FMGR_EXIF_NO_INFORMATION
#define EXIF_COUNT  (EXIF_STR_ID_END - EXIF_STR_ID_START)

    U8 *data_array[EXIF_COUNT];
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init array */
#define PRINT_EXIF_INFO(__a__,__A__)   data_array[(__A__) - EXIF_STR_ID_START] = exif_info->##__a__

    memset(data_array, 0, sizeof(data_array));
#ifdef __PLUTO_MMI_PACKAGE__
#ifdef __MMI_EXIF_MAKE__
    PRINT_EXIF_INFO(make, STR_ID_FMGR_EXIF_MAKE);
#endif
#ifdef __MMI_EXIF_MODEL__
    PRINT_EXIF_INFO(model, STR_ID_FMGR_EXIF_MODEL);
#endif
#ifdef __MMI_EXIF_ORIENTATION__
    PRINT_EXIF_INFO(orientation, STR_ID_FMGR_EXIF_ORIENTATION);
#endif
#ifdef __MMI_EXIF_X_RESOLUTION__
    PRINT_EXIF_INFO(x_resolution, STR_ID_FMGR_EXIF_X_RESOLUTION);
#endif
#ifdef __MMI_EXIF_Y_RESOLUTION__
    PRINT_EXIF_INFO(y_resolution, STR_ID_FMGR_EXIF_Y_RESOLUTION);
#endif
#ifdef __MMI_EXIF_RESOLUTION_UNIT__
    PRINT_EXIF_INFO(resolution_unit, STR_ID_FMGR_EXIF_RESOLUTION_UNIT);
#endif
#ifdef __MMI_EXIF_SOFTWARE__
    PRINT_EXIF_INFO(software, STR_ID_FMGR_EXIF_SOFTWARE);
#endif
#ifdef __MMI_EXIF_DATE_TIME__
    PRINT_EXIF_INFO(date_time, STR_ID_FMGR_EXIF_DATE_TIME);
#endif
#ifdef __MMI_EXIF_YCBCR_POSITIONING__
    PRINT_EXIF_INFO(ycbcr_positioning, STR_ID_FMGR_EXIF_YCBCR_POSITIONING);
#endif
#ifdef __MMI_EXIF_EXIF_IFD__
    PRINT_EXIF_INFO(exif_ifd, STR_ID_FMGR_EXIF_EXIF_IFD);
#endif
#ifdef __MMI_EXIF_EXPOSURE_TIME__
    PRINT_EXIF_INFO(exposure_time, STR_ID_FMGR_EXIF_EXPOSURE_TIME);
#endif
#ifdef __MMI_EXIF_FNUMBER__
    PRINT_EXIF_INFO(fnumber, STR_ID_FMGR_EXIF_FNUMBER);
#endif
#ifdef __MMI_EXIF_EXPOSURE_PROGRAM__
    PRINT_EXIF_INFO(exposure_program, STR_ID_FMGR_EXIF_EXPOSURE_PROGRAM);
#endif
#ifdef __MMI_EXIF_ISO_SPEED_RATINGS__
    PRINT_EXIF_INFO(iso_speed_ratings, STR_ID_FMGR_EXIF_ISO_SPEED_RATINGS);
#endif
#ifdef __MMI_EXIF_EXIF_VERSION__
    PRINT_EXIF_INFO(exif_version, STR_ID_FMGR_EXIF_EXIF_VERSION);
#endif
#ifdef __MMI_EXIF_DATE_TIME_ORIGINAL__
    PRINT_EXIF_INFO(date_time_original, STR_ID_FMGR_EXIF_DATE_TIME_ORIGINAL);
#endif
#ifdef __MMI_EXIF_DATE_TIME_DIGITIZED__
    PRINT_EXIF_INFO(date_time_digitized, STR_ID_FMGR_EXIF_DATE_TIME_DIGITIZED);
#endif
#ifdef __MMI_EXIF_COMPONENTS_CONFIG__
    PRINT_EXIF_INFO(components_config, STR_ID_FMGR_EXIF_COMPONENTS_CONFIG);
#endif
#ifdef __MMI_EXIF_EXPOSURE_BIAS_VALUE__
    PRINT_EXIF_INFO(exposure_bias_value, STR_ID_FMGR_EXIF_EXPOSURE_BIAS_VALUE);
#endif
#ifdef __MMI_EXIF_METERING_MODE__
    PRINT_EXIF_INFO(metering_mode, STR_ID_FMGR_EXIF_METERING_MODE);
#endif
#ifdef __MMI_EXIF_LIGHT_SOURCE__
    PRINT_EXIF_INFO(light_source, STR_ID_FMGR_EXIF_LIGHT_SOURCE);
#endif
#ifdef __MMI_EXIF_FLASH__
    PRINT_EXIF_INFO(flash, STR_ID_FMGR_EXIF_FLASH);
#endif
#ifdef __MMI_EXIF_MAKER_NOTE__
    PRINT_EXIF_INFO(maker_note, STR_ID_FMGR_EXIF_MAKER_NOTE);
#endif
#ifdef __MMI_EXIF_FLASHPIX_VERSION__
    PRINT_EXIF_INFO(flashpix_version, STR_ID_FMGR_EXIF_FLASHPIX_VERSION);
#endif
#ifdef __MMI_EXIF_COLOR_SPACE__
    PRINT_EXIF_INFO(color_space, STR_ID_FMGR_EXIF_COLOR_SPACE);
#endif
#ifdef __MMI_EXIF_EXPOSURE_MODE__
    PRINT_EXIF_INFO(exposure_mode, STR_ID_FMGR_EXIF_EXPOSURE_MODE);
#endif
#ifdef __MMI_EXIF_DIGITAL_ZOOM_RATIO__
    PRINT_EXIF_INFO(digital_zoom_ratio, STR_ID_FMGR_EXIF_DIGITAL_ZOOM_RATIO);
#endif
#ifdef __MMI_EXIF_SCENE_CAPTURE_TYPE__
    PRINT_EXIF_INFO(scene_capture_type, STR_ID_FMGR_EXIF_SCENE_CAPTURE_TYPE);
#endif
#endif /* __PLUTO_MMI_PACKAGE__ */
    for (i = 0; i < EXIF_COUNT; i++)
    {
        if (data_array[i] && *data_array[i] != '\0')
        {
            kal_wsprintf((WCHAR*) buffer, "%w\n%s\n", (WCHAR*) GetString(STR_ID_FMGR_EXIF_MAKE + i), data_array[i]);
            buffer += kal_wstrlen(buffer);
            count++;
        }
    }

    if (count > 0)
    {
        /* to cut the last "\n" */
        *(buffer - 1) = 0;
    }

#endif /* __MMI_EXIF__ */

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_convert_format_size
 * DESCRIPTION
 *  convert size format
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_convert_format_size(U64 file_size, U16* buffer, S32 buffer_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const char postfix[] = {"BKMG"};
    U64 unit = 1;
    S32 i = 0;
    U32 part_int, part_mod;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(file_size >= 1024*unit && postfix[i] != 'G')
    {
        unit *= 1024;
        i++;
    }

    part_int = (U32)( file_size / unit );
    part_mod = (U32)( ((file_size % unit)*10)/unit );

    if(part_mod)
    {
        kal_wsprintf(buffer, "%d.%d%c", part_int, part_mod, postfix[i]);
    }
    else
    {
        kal_wsprintf(buffer, "%d%c", part_int, postfix[i]);
    }
}


static S32 mmi_imgview_image_info_print_buffer(WCHAR *filepath, WCHAR *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32                      str_len;
    srv_fmgr_fileinfo_struct fileinfo;
    WCHAR *name_ptr, *type_ptr, time_str[MAX_SUBMENU_CHARACTERS], size_str[MAX_SUBMENU_CHARACTERS];
    GDI_RESULT               gdi_ret;
    S32                      width;
    S32                      height;
    S32                      count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    name_ptr = srv_fmgr_path_get_filename_ptr(filepath);
    srv_fmgr_fs_path_get_fileinfo(filepath, &fileinfo);
    gdi_ret = gdi_image_get_dimension_file((CHAR*)filepath, &width, &height);
    type_ptr = srv_fmgr_path_get_extension_ptr(filepath);

    /* Filename */
    kal_wsprintf(buffer, "%w\n", GetString(STR_ID_IMGVIEW_OPTION_IMG_INFO_FILENAME));
    str_len = kal_wstrlen(name_ptr);
    if(str_len >= MAX_SUBMENU_CHARACTERS)
    {
        kal_wstrncat(buffer, name_ptr, MAX_SUBMENU_CHARACTERS - 2);
        kal_wstrcat(buffer, L"..");
    }
    else
    {
        kal_wstrcat(buffer, name_ptr);
    }
    count++;

    /* Image type */
    if (type_ptr)
    {
        str_len = kal_wstrlen(buffer);
        mmi_wcsupr(type_ptr);
        kal_wsprintf(
            buffer + str_len,
            "\n%w\n%w",
            GetString(STR_ID_IMGVIEW_OPTION_IMG_INFO_TYPE),
            type_ptr);
        count++;
    }

    /* Image dimention */
    if(gdi_ret == GDI_SUCCEED)
    {
        str_len = kal_wstrlen(buffer);
        kal_wsprintf(
            buffer + str_len,
            "\n%w\n%dx%d",
            GetString(STR_ID_IMGVIEW_OPTION_IMG_INFO_RESOLUTION),
            width,
            height);
        count++;
    }

    /* File size and date */
    str_len = kal_wstrlen(buffer);
    date_string(&fileinfo.created_datetime, time_str, DT_IDLE_SCREEN);
    mmi_imgview_convert_format_size(fileinfo.size, size_str, MAX_SUBMENU_CHARACTERS);
    kal_wsprintf(
        buffer + str_len,
        "\n%w\n%w\n%w\n%w",
        (WCHAR*) GetString(STR_ID_IMGVIEW_OPTION_IMG_INFO_SIZE),
        size_str,
        (WCHAR*) GetString(STR_ID_IMGVIEW_OPTION_IMG_INFO_CREATE_TIME),
        time_str);
    count += 2;

    return count;
}

static mmi_ret mmi_imgview_img_info_screen_leave_proc(mmi_event_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(para->evt_id == EVT_ID_SCRN_DEINIT)
    {
        MMI_ASSERT(g_imgviewer_img_info_filepath != NULL);

        OslMfree(g_imgviewer_img_info_filepath);
        g_imgviewer_img_info_filepath = NULL;
    }
    return MMI_RET_OK;
}


static void mmi_imgview_entry_img_info_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8                              *guiBuffer;
    gdi_image_jpeg_exif_info_struct exif_info;
    GDI_RESULT                      result = GDI_SUCCEED;
    S16                             count = 0;
    FS_HANDLE                       fs_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_frm_scrn_enter(
            g_imgviewer_img_info_parent_gid,
            SCR_ID_IMGVIEW_IMG_INFO,
            NULL,
            mmi_imgview_entry_img_info_screen,
            MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    MMI_ASSERT(g_imgviewer_img_info_filepath != NULL);

    mmi_frm_scrn_set_leave_proc(g_imgviewer_img_info_parent_gid, SCR_ID_IMGVIEW_IMG_INFO, mmi_imgview_img_info_screen_leave_proc);

    /* check for device status */
    fs_handle = FS_Open(g_imgviewer_img_info_filepath, FS_READ_ONLY);
    if(fs_handle < FS_NO_ERROR)
    {
        if(mmi_frm_is_in_backward_scenario())
        {
            mmi_frm_scrn_close_active_id();
            return;
        }
        else
        {
            mmi_popup_display_simple(
                (WCHAR*)GetString(srv_fmgr_fs_error_get_string(fs_handle)),
                (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(fs_handle),
                g_imgviewer_img_info_parent_gid,
                NULL);

            mmi_frm_scrn_close(g_imgviewer_img_info_parent_gid, SCR_ID_IMGVIEW_IMG_INFO);
            return;
        }
    }
    else
    {
        FS_Close(fs_handle);
    }

    mmi_ucs2cpy((CHAR*) subMenuData, (const CHAR*) L"");
    /* Get basic infomation */
    count = mmi_imgview_image_info_print_buffer((WCHAR*)g_imgviewer_img_info_filepath, (WCHAR*)subMenuData);
    /* Get exif information */
    result = gdi_image_jpeg_get_exif_info((CHAR*)g_imgviewer_img_info_filepath, &exif_info);
    if (result != GDI_FAILED)
    {
        S32 str_len = (kal_wstrlen((WCHAR*)subMenuData));
        WCHAR *exifBufPtr = (WCHAR*)subMenuData + (str_len + 1);
        S16 exifCount = mmi_imgview_jpg_info_print_buffer(&exif_info, exifBufPtr);

        if (0 < exifCount)
        {
            *(exifBufPtr - 1) = '\n';
        }
        count += exifCount;
    }

    if (count == 0)
    {
    #ifdef __PLUTO_MMI_PACKAGE__
        mmi_ucs2cat((CHAR*) subMenuData, (CHAR*) GetString(STR_ID_FMGR_EXIF_NO_INFORMATION));
    #endif
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    ShowCategory74Screen(
        STR_ID_IMGVIEW_OPTION_IMG_INFO,
        GetRootTitleIcon(MENU_ID_IMGVIEW_OPTION_IMG_INFORMATION),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) subMenuData,
        MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


extern void mmi_imgview_show_img_info(const WCHAR* filepath, MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imgview_img_info_handler(filepath, parent_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_view_handler
 * DESCRIPTION
 *  for fmgr option item "view"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_imgview_view_handler(mmi_menu_id item_id, const WCHAR* filepath,
                                          const srv_fmgr_fileinfo_struct* fileinfo)

{
    if(item_id == MENU_ID_IMGVIEW_OPTION_IMG_VIEW){
        mmi_imgview_simple_launch((PS8)filepath, STRING_ID_NULL, IMAGE_ID_NULL);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_view_enabler
 * DESCRIPTION
 *  for fmgr option item "view"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_imgview_view_enabler(mmi_menu_id item_id, const WCHAR* filepath,
                                          const srv_fmgr_fileinfo_struct* fileinfo)

{
    FMGR_FILTER file_type;
    S32 ret;

    if(item_id == MENU_ID_IMGVIEW_OPTION_IMG_VIEW){
        FMGR_FILTER_INIT(&file_type);
        ret = srv_fmgr_types_find_type_by_filepath(filepath);
        if(ret >= 0)
        {
            FMGR_FILTER_SET(&file_type, ret);

        }

        if(FMGR_FILTER_IS_SET_IMAGE(&file_type) == MMI_FALSE)
        {
            mmi_frm_hide_menu_item(item_id);
        }

    }
}


#ifdef __MMI_SNS_PHOTO_UPLOAD__
/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_sns_photo_upload_enabler
 * DESCRIPTION
 *  for fmgr option item "send->to sns"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_imgview_sns_photo_upload_enabler(mmi_menu_id item_id, const WCHAR* filepath,
                                          const srv_fmgr_fileinfo_struct* fileinfo)

{
    FMGR_FILTER file_type;
    S32 ret;

    if(item_id == MENU_ID_FMGR_FWD_SNS_PHOTO_UPLOAD){
        FMGR_FILTER_INIT(&file_type);
        ret = srv_fmgr_types_find_type_by_filepath(filepath);
        if(ret >= 0)
        {
            FMGR_FILTER_SET(&file_type, ret);

            if(FMGR_FILTER_IS_SET_IMAGE(&file_type) == MMI_FALSE)
            {
                mmi_frm_hide_menu_item(MENU_ID_FMGR_FWD_SNS_PHOTO_UPLOAD);
            }
        }
        else
        {
            mmi_frm_hide_menu_item(MENU_ID_FMGR_FWD_SNS_PHOTO_UPLOAD);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_sns_photo_upload_handler
 * DESCRIPTION
 *  for fmgr option item "send->to sns"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_imgview_sns_photo_upload_handler(mmi_menu_id item_id, const WCHAR* filepath,
                                          const srv_fmgr_fileinfo_struct* fileinfo)

{
    if(item_id == MENU_ID_FMGR_FWD_SNS_PHOTO_UPLOAD){

        mmi_sns_upload_photo_from_imageviewer(GRP_ID_ROOT, (WCHAR*)filepath);
    }
}
#endif /* __MMI_SNS_PHOTO_UPLOAD__ */
#endif /* __MMI_IMAGE_VIEWER__ */


