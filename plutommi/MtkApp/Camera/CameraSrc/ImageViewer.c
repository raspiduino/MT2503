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
 *  ImageViewer.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Image Viewer.
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
#include "MMI_features.h"

#include "GlobalConstants.h"
#include "stack_config.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "fs_func.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_lcd_config.h"
#include "gdi_include.h"
#include "gui_data_types.h"
#include "gui.h"
#include "wgui_categories.h"
#include "wgui_categories_ems.h"
#include "wgui_categories_multimedia.h"
#include "wgui_categories_util.h"
#include "MMIDataType.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "drm_def.h"
#include "DebugInitDef_Int.h"
#include "mmi_media_app_trc.h"
#include "Unicodexdcl.h"
#include "GlobalResDef.h"
#include "ImageViewCuiGprot.h"
#include "GlobalMenuItems.h"
#include "CustDataRes.h"
#include "mmi_rp_file_type_def.h"
#include "FileMgrGProt.h"
#include "ImageViewerAdvGprot.h"
#include "mmi_rp_srv_filemanager_def.h"
#include "string.h"
#include "custom_mmi_default_value.h"
#include "AlertScreen.h"
#include "stdio.h"
#include "mmi_res_range_def.h"
#include "app_mem.h"
#include "lcd_sw_inc.h"
#include "MediaCacheSrvMem.h"
#include "drm_errcode.h"
#include "FileMgrServiceResDef.h"
#include "mmi_rp_app_filemanager_def.h"
#include "CustMenuRes.h"
#include "app_ltlcom.h"
#include "MMI_media_app_trc.h"

#include "FileMgrSrvGProt.h"
#include "mmi_frm_app_launcher_gprot.h"



#ifdef __MMI_MESSAGES_EMS__
#include "MessagesExDcl.h"
#endif 

#include "lcd_sw_rnd.h" /* for LCD size */

#include "FileMgrType.h"

#include "MMI_features_camera.h"        /* features - in custom folder */

#include "med_api.h"	/* for media buffer apis */

#include "ImageViewer.h"        /* Iamge Viewer header */
#include "ImageViewerGprot.h"
#include "mmi_rp_app_imageviewer_def.h"
#ifdef __MMI_CAMCORDER__
#include "mmi_features_camcorder.h"
#include "CamcorderGprot.h"
#include "VdoPlyGprot.h"
#endif /* __MMI_CAMCORDER__ */

#ifdef __MMI_TVOUT__
#include "mdi_datatype.h"
#include "mdi_tv.h"
#endif /* __MMI_TVOUT__ */ 

#include "Drm_gprot.h"  /* DRM support */
#include "RightsMgrGProt.h"

#if defined(__MMI_SCREEN_ROTATE__)
#include "ScreenRotationGprot.h"
#endif 
#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif

#if defined(__MMI_IMAGE_VIEWER_ADV__)
#include "conversions.h"
#include "phonesetupgprots.h"
#endif

#if defined(__MMI_IMAGE_VIEWER_EX__)
#include "ImageViewerEXAppGprot.h"
#endif

#ifdef __MMI_SLIDESHOW__
#include "slideshowgprot.h"
#endif

#ifdef __MMI_PHOTOEDITOR__ 
#include "PhotoEditorGprot.h"
#endif

#ifdef __MMI_VUI_MEDIAWALL__
#include "MediaWall\vadp_mediawall.h"
#endif

/* For imgview CUI */
#include "ImageViewCui.h"
#include "FileMgrCUIGProt.h"
#include "MenuCuiGprot.h"
#include "mmi_rp_srv_filemanager_def.h"

#if defined(__MMI_IMAGE_VIEWER__) || defined(__MMI_FILE_MANAGER__)
/* CUI related variables */
mmi_id g_imgview_cui_gid;
mmi_id g_mediaview_cui_gid;
extern cui_mediaview_context_struct *g_mediaview_cui_ptr;
extern cui_imgview_context_struct *g_imgview_cui_ptr;

static S32 mmi_imgview_create_file_dir(CHAR* filepath);
static mmi_ret mmi_imgview_launch_int(mmi_event_struct *evt);

typedef struct
{
    MMI_EVT_PARAM_HEADER
    MMI_ID app_id;
} mmi_ivex_app_post_launch_event_struct;


/***************************************************************************** 
* Define
*****************************************************************************/
#if defined(__DRM_SUPPORT__)
#define MMI_IMGVIEW_DRM_ENTER_STATE(_state_)\
        do{\
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_IMGVIEW_DRM_ENTER_STATE,g_imgview_context.drm_state,_state_,__LINE__);\
        g_imgview_context.drm_state = _state_;\
        }\
        while(0)
#endif /* __DRM_SUPPORT__ */

#define IMGVIEW_POPUP_STRING_LEN   (100)

#ifdef IVAPP_DEBUG
kal_uint32 d_time;

#define TMP_TRACE(fmt) kal_prompt_trace(MOD_MMI, fmt) 
#define TMP_TRACE1(fmt, arg1) kal_prompt_trace(MOD_MMI, fmt, arg1)
#define TMP_TRACE2(fmt, arg1, arg2) kal_prompt_trace(MOD_MMI, fmt, arg1, arg2)
#define TMP_TRACE3(fmt, arg1, arg2, arg3) kal_prompt_trace(MOD_MMI, fmt, arg1, arg2, arg3)
#define TMP_TRACE_TIME(fmt) \
    do{ \
        kal_get_time(&d_time); \
        TMP_TRACE1(fmt, kal_ticks_to_milli_secs(d_time)); \
    }while(0);

#else
#define TMP_TRACE(fmt)
#define TMP_TRACE1(fmt, arg1)
#define TMP_TRACE2(fmt, arg1, arg2)
#define TMP_TRACE3(fmt, arg1, arg2, arg3)
#define TMP_TRACE_TIME(fmt)
#endif

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern BOOL r2lMMIFlag;
/***************************************************************************** 
* Global Function
*****************************************************************************/
void *mmi_imgview_asm_alloc_debug(mmi_id app_id, U32 size) {
    return mmi_frm_asm_alloc_nc_r(app_id, size);
}

void mmi_imgview_asm_free_debug(mmi_id id, void *ptr) {
    mmi_frm_asm_free_r(id, ptr);
}


/***************************************************************************** 
* Local Variable
*****************************************************************************/
imgview_context_struct g_imgview_context;
mmi_imgview_state_enum g_imgview_state;
SRV_FMGR_FILELIST_HANDLE g_imgview_fl_hdl;
S32 g_imgview_fl_idx;
/***************************************************************************** 
* Local Function
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_get_curr_path
 * DESCRIPTION
 *  Get full path of current image for single image mode, folder path for folder mode.
 *
 * PARAMETERS
 *  isIncBrowser          [IN]: if include browser folder    
 * RETURNS
 *  full path of file or folder. 
 *****************************************************************************/
static const WCHAR* mmi_imgview_get_curr_path(U16 isIncBrowser)
{
    const WCHAR* ret = NULL;

    if(g_imgview_cui_ptr == NULL || g_imgview_cui_ptr->imgview_cui_gid == GRP_ID_INVALID){
        if(g_mediaview_cui_ptr != NULL && g_mediaview_cui_gid != GRP_ID_INVALID && isIncBrowser != 0)
            return (WCHAR*)g_mediaview_cui_ptr->folder_path;
        return NULL;
    }

    switch(g_imgview_cui_ptr->view_mode.viewmode)
    {
    case CUI_IMGVIEW_VIEWMODE_FILELIST:
        if(FS_NO_ERROR == srv_fmgr_filelist_get_filepath(g_imgview_fl_hdl, g_imgview_fl_idx, (WCHAR*)(g_imgview_cui_ptr->view_mode.buff_ptr), (SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH))
        {
            ret = (WCHAR*)(g_imgview_cui_ptr->view_mode.buff_ptr);
        }
        break;
        
    case CUI_IMGVIEW_VIEWMODE_PREFETCH:
    case CUI_IMGVIEW_VIEWMODE_FILENAME:
    case CUI_IMGVIEW_VIEWMODE_FOLDER:   //not sure for it's not implemented now.
        ret = (WCHAR*)(g_imgview_cui_ptr->view_mode.buff_ptr);
        break;
    
    default:
        break;
    }

    return ret;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_is_parent
 * DESCRIPTION
 *  check if @parent_path is parent of @check_path
 * PARAMETERS
 *  parent_path          [IN]    
 *  check_path           [IN]
 * RETURNS
 *  TRUE:   if @parent_path is parent of same as @check_path.
 *  FALSE:  otherwise.
 *****************************************************************************/
static MMI_BOOL mmi_imgview_is_parent(const WCHAR* parent_path, const WCHAR *check_path)
{
    if(parent_path == NULL || check_path == NULL)
        return MMI_FALSE;

    if(*parent_path == 0 || *check_path == 0)
        return MMI_FALSE;
    
    while(*parent_path != 0 && *check_path != 0)
    {
        if(*parent_path++ != *check_path++)
            return MMI_FALSE;
    }

    while(*parent_path == '\\')
        parent_path++;
    while(*check_path == '\\')
        check_path++;

    if(*parent_path != 0)
        return MMI_FALSE;

    if(*(check_path-1) == '\\' || *check_path == 0)
        return MMI_TRUE;

    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_fmgr_notify_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_imgview_fmgr_notify_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_RET ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    TMP_TRACE1("[IVAPP][TMP] receive fmgr notification: id=%d", event->evt_id);
    switch(event->evt_id)
    {
#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
        case EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE:
            {
                srv_fmgr_notification_set_def_storage_event_struct *fmgr_storage
                    = (srv_fmgr_notification_set_def_storage_event_struct*)event;

                if(fmgr_storage->state == SRV_FMGR_NOTIFICATION_STATE_QUERY) /* MMI_FMGR_NOTIFY_SET_STORAGE_PRE_CHK */
                {
                    if (mmi_frm_scrn_get_active_id() == SCR_ID_IMGVIEW_VIEW)
                    {
                        ret = MMI_RET_ERR;
                    }
                }
                else if(fmgr_storage->state == SRV_FMGR_NOTIFICATION_STATE_AFTER) /* MMI_FMGR_NOTIFY_SET_STORAGE */
                {
                    mmi_imgview_set_storage((U16)fmgr_storage->drv_letter);
                }
            }
            break;

#endif /* __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__ */

        case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT:
            {
                srv_fmgr_notification_format_event_struct *fmgr_format
                    = (srv_fmgr_notification_format_event_struct*)event;

                if(fmgr_format->state == SRV_FMGR_NOTIFICATION_STATE_BEFORE) /* MMI_FMGR_NOTIFY_DRV_PRE_FORMAT */
                {
                    /* get the storage value from nvram to avoid g_imgview_context.storage is not right */
                    mmi_imgview_load_setting();

                    if(fmgr_format->drv_letter == (U8)g_imgview_context.storage)
                    {
                        if(g_mediaview_cui_gid != GRP_ID_INVALID)
                        {
                            mmi_mediaview_close_view_cui(&g_mediaview_cui_gid, EVT_ID_MEDIAVIEW_CLOSE_GID);
                        }
                        else if(g_imgview_cui_ptr != NULL && g_imgview_cui_ptr->imgview_cui_gid != GRP_ID_INVALID)
                        {
                            mmi_mediaview_close_view_cui(&g_imgview_cui_ptr->imgview_cui_gid, EVT_ID_IMGVIEW_CLOSE_GID);
                        }
                    }
                }
            }
            break;

        case EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION:
            {
                srv_fmgr_notification_adv_action_event_struct *fmgr_act
                    = (srv_fmgr_notification_adv_action_event_struct*)event;

                if(fmgr_act->state == SRV_FMGR_NOTIFICATION_STATE_QUERY)
                {
                    if ((fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_MOVE) ||
                        (fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_DELETE) ||
                        (fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_RENAME))
                    {
                        /* It care the browser folder only when user modify a folder. When user modify file or files,
                         * it only care the imageViewer.
                         */
                        if(mmi_imgview_is_parent(fmgr_act->src_filepath, mmi_imgview_get_curr_path(fmgr_act->src_fileinfo.attribute & FS_ATTR_DIR)))
                        {
                            ret = MMI_RET_ERR;
                        }
                    }
                    else if(fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_DELETE_ALL)
                    {
                        if(mmi_imgview_is_parent(fmgr_act->src_filepath, mmi_imgview_get_curr_path(0)))
                        {
                            if((fmgr_act->filter == NULL) || (FMGR_FILTER_IS_SET_IMAGE((FMGR_FILTER *)fmgr_act->filter)))
                            {
                                /* delete all files, or all image files */
                                ret = MMI_RET_ERR;
                            }
                        }
                    }
                }
            }
            break;

        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
            {
                /* if entry from menu, folder browser will handle card plug out event and we will close APP */
                /* other will call cui to run imageview, then folder browser will not exsit and handle card plug out */

                /* for MAUI_02321215*********************************************************************/
                /* get the storage value from nvram to avoid g_imgview_context.storage is not right */
                S32 drv_idx;
                WCHAR drv_path[4];
                const WCHAR *p_cur_path;
                srv_fmgr_notification_dev_plug_event_struct *dev_plug
                    = (srv_fmgr_notification_dev_plug_event_struct*)event;

                mmi_imgview_load_setting();
                drv_path[1] = ':';
                drv_path[2] = '\\';
                drv_path[3] = 0;
                p_cur_path = mmi_imgview_get_curr_path(1);
                for(drv_idx = 0; drv_idx < dev_plug->count; drv_idx++)
                {
                    drv_path[0] = dev_plug->drv_letters[drv_idx];
                    TMP_TRACE2("[IVAPP][TMP] plugout %d, cur path: %d", dev_plug->drv_letters[drv_idx], p_cur_path);
                    if(p_cur_path == NULL || mmi_imgview_is_parent(drv_path, p_cur_path))
                    {
                        TMP_TRACE("[IVAPP][TMP] prepare plugout close");
                        if(g_imgview_cui_ptr != NULL && g_imgview_cui_ptr->imgview_cui_gid != GRP_ID_INVALID)
                        {
                            TMP_TRACE("[IVAPP][TMP] plugout close");
                            mmi_mediaview_close_view_cui(&g_imgview_cui_ptr->imgview_cui_gid, EVT_ID_IMGVIEW_CLOSE_GID);
                        }

                        break;
                    }
                }
            }
            break;

        default:
            break;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_print_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_imgview_print_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id option_menu_gid;
    U16 title_icon;
    U16 active_screen = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (active_screen == SCR_ID_IMGVIEW_FROM_FMGR)
        title_icon = g_imgview_context.title_icon;
    else
        title_icon = GetRootTitleIcon(MENU_ID_IMGVIEW_APP);

    option_menu_gid = cui_menu_create(
                                    g_imgview_cui_gid,
                                    CUI_MENU_SRC_TYPE_RESOURCE,
                                    CUI_MENU_TYPE_OPTION,
                                    MENU_ID_FMGR_IMG_OPTION_PRINT,
                                    MMI_TRUE,
                                    NULL);
    cui_menu_set_default_title(option_menu_gid, get_string(STR_GLOBAL_OPTIONS), get_image(title_icon));
    cui_menu_set_currlist_flags(option_menu_gid, CUI_MENU_LIST_WITH_TEXT_NUMBERED_ITEMS);

    cui_menu_run(option_menu_gid);
}


#if defined(__MMI_BPP_SUPPORT__) || defined(__MMI_PICT_BRIDGE_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_option_print_execute_forward
 * DESCRIPTION
 *   handle lsk event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_option_print_execute_forward(U16 highlight_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = FS_NO_ERROR;
    WCHAR filepath[SRV_FMGR_PATH_BUFFER_SIZE / ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_imgview_cui_ptr->view_mode.viewmode == CUI_IMGVIEW_VIEWMODE_FILELIST)
    {
        ret = srv_fmgr_filelist_get_filepath(
            g_imgview_fl_hdl,
            g_imgview_fl_idx,
            filepath,
            SRV_FMGR_PATH_BUFFER_SIZE);
    }
    else
    {
        mmi_ucs2cpy((CHAR*)filepath, (CHAR*)g_imgview_context.filepath);
    }

    if(ret == 0)
    {
        ret = srv_fmgr_types_launch_option(filepath, highlight_item);
    }

    if (ret < 0)
    {
        mmi_imgview_display_popup_sg(
            g_imgview_cui_gid,
            (UI_string_type)GetString(srv_fmgr_fs_error_get_string(ret)),
            (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(ret),
            0,
            MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_exit_view_image_hdlr
 * DESCRIPTION
 *  event hdlr: call this to exit imgview 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgview_exit_view_image_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __DRM_SUPPORT__
    mmi_imgview_consume_drm_if_need();
#endif

#ifdef __MMI_RMGR_EXTEND_RIGHTS_AFTER_EXIT_AP__
    if (mmi_rmgr_extend_rights_by_path((U16*)g_imgview_context.filepath, DRM_PERMISSION_DISPLAY, GetRootTitleIcon(MENU_ID_IMGVIEW_APP)) == 
        MMI_RMGR_STATUS_REQUEST_RIGHTS)
    {
        mmi_rmgr_request_rights_confirm();
        mmi_mediaview_close_view_cui(&g_imgview_cui_gid, EVT_ID_IMGVIEW_CLOSE_GID);
    }
    else
    {
        mmi_frm_scrn_close_active_id();
    }
#else
    mmi_frm_scrn_close_active_id(); 
#endif /* __MMI_RMGR_EXTEND_RIGHTS_AFTER_EXIT_AP__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_exit_image_screen
 * DESCRIPTION
 *  exit imgview (fmgr) screen function: should sub drm right counts.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgview_exit_image_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DRM_SUPPORT__   
    /* based on DEL SCR will do first */
    if (g_imgview_context.drm_state == IMGVIEW_DRM_STATE_CONSUME)
    {
        DRM_pause_consume(g_imgview_context.drm_id);
        MMI_IMGVIEW_DRM_ENTER_STATE(IMGVIEW_DRM_STATE_PAUSE);
    }
#endif

#if defined(__MMI_IMGVIEW_NONBLOCKING_DECODE__)
    gdi_image_nb_stop_all();
#endif
    
    g_imgview_context.result = MMI_IMGVIEW_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_view_image_hdlr_internal_leave_proc
 * DESCRIPTION
 *  Ext view screen leave proc.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_ret mmi_imgview_view_image_hdlr_internal_leave_proc(mmi_event_struct *evt)
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
        mmi_imgview_view_from_fmgr_del_scr_callback(NULL);
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_view_image_hdlr_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgview_view_image_hdlr_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL is_printable = FALSE;
    U16 str_lsk = 0;
    UI_string_type str_lsk_ptr = 0;
    srv_fmgr_fileinfo_struct file_info;
    UI_string_type err_str_ptr = NULL;
    FS_HANDLE file_handle;
    MMI_BOOL entry_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* exit previous screen */
    if (!mmi_frm_is_in_backward_scenario() && !mmi_frm_group_is_present(g_imgview_cui_gid))
    {
        mmi_frm_group_enter(g_imgview_cui_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }
    entry_ret = mmi_frm_scrn_enter(g_imgview_cui_gid, SCR_ID_IMGVIEW_FROM_FMGR, mmi_imgview_exit_image_screen, mmi_imgview_view_image_hdlr_internal, MMI_FRM_FULL_SCRN);
    if (!entry_ret)
    {
        return;
    }
    mmi_frm_scrn_close(g_imgview_cui_gid, SCR_ID_GLOBAL_DUMMY);
    mmi_frm_scrn_set_leave_proc(g_imgview_cui_gid, SCR_ID_IMGVIEW_FROM_FMGR, mmi_imgview_view_image_hdlr_internal_leave_proc);
    g_imgview_context.result = MMI_IMGVIEW_OK;
    if (g_imgview_context.filepath != NULL)
    {
        file_handle = FS_Open((PU16) g_imgview_context.filepath, FS_READ_ONLY);
        if (file_handle < 0)
        {
            if (file_handle == FS_MEDIA_CHANGED || file_handle == FS_DRIVE_NOT_FOUND)
            {
                SRV_FMGR_DRVLIST_HANDLE drvlist;
                S32 total_drv_num = 0;
            #ifdef __FS_CARD_SUPPORT__
            /* for 64+32 */
                drvlist = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ALL);
                total_drv_num = srv_fmgr_drivelist_count(drvlist);
                srv_fmgr_drivelist_destroy(drvlist);
                if (total_drv_num == 0)
                {
                    mmi_imgview_display_popup_sg(g_imgview_cui_gid, (UI_string_type)GetString(STR_GLOBAL_INSERT_MEMORY_CARD), MMI_EVENT_FAILURE, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP);
                    return;
                }
            #endif
            }
            mmi_imgview_display_popup_sg(g_imgview_cui_gid, (UI_string_type)GetString(srv_fmgr_fs_error_get_string(file_handle)), 
                (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(file_handle), 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP);
            return;
        }
        else
        {
            FS_Close(file_handle);
        }
        g_imgview_context.image_type = gdi_image_get_type_from_file(g_imgview_context.filepath);
    }
    /* check DRM rights */
    #if defined(__DRM_SUPPORT__)
    mmi_imgview_preprocess_drm_right();
    #endif

    srv_fmgr_fs_path_get_fileinfo((WCHAR*)g_imgview_context.filepath, &file_info);
    /* check if this image printable */
#if defined(__DRM_SUPPORT__)
    if ((g_imgview_context.print_support == TRUE) && 
        ((IMGVIEW_DRM_PRINT_VALID & g_imgview_context.drm_valid)!=0) && 
        mmi_imgview_print_enabler(&file_info) > 0)
#else
    if ((g_imgview_context.print_support == TRUE) && 
        mmi_imgview_print_enabler(&file_info) > 0)
#endif
    {
        is_printable = TRUE;
        str_lsk_ptr = get_string(STR_GLOBAL_PRINT);
        str_lsk = STR_GLOBAL_PRINT;
    }
    else
    {
        if (g_imgview_cui_ptr->lsk_setting.is_customized)
        {
            str_lsk_ptr = get_string(g_imgview_cui_ptr->lsk_setting.stringid);
            str_lsk = g_imgview_cui_ptr->lsk_setting.stringid;
        }
    }

#ifdef __MMI_MESSAGES_EMS__
    if (g_imgview_context.file_type == FMGR_TYPE_EMS)
    {
        ShowCategory144Screen(
            (PU8)g_imgview_context.title_str,
            g_imgview_context.title_icon,
            str_lsk,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            EMS_OBJECT_MY_PICTURE_STATE | CATEGORY144_FMGR_PREVIEW,
            1,
            NULL,
            (U16*) g_imgview_context.filepath,
            g_imgview_context.is_short,
            NULL,
            0,
            NULL);
    }
    else if (g_imgview_context.file_type == FMGR_TYPE_ANM)
    {
        ShowCategory144Screen(
            (PU8)g_imgview_context.title_str,
            g_imgview_context.title_icon,
            str_lsk,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            EMS_OBJECT_MY_ANIMATION_STATE | CATEGORY144_FMGR_PREVIEW,
            1,
            NULL,
            (U16*) g_imgview_context.filepath,
            g_imgview_context.is_short,
            NULL,
            0,
            NULL);
    }
    else
#endif /* __MMI_MESSAGES_EMS__ */ 
    {

        wgui_cat222_disable_err_msg_display();

        /* entry cat222 to decode and display a image from file */
        if (g_imgview_context.title_str == 0)
        {
            ShowCategory222Screen(
                0,                                              /* title */
                g_imgview_context.title_icon,                   /* title icon */
                str_lsk,
                0, 
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,                                /* right soft key */
                GDI_COLOR_WHITE,                                /* content BG color */
                (CHAR*) NULL,                                     /* button bar string */
                (CHAR*) g_imgview_context.filepath,                        /* image file name */
                g_imgview_context.is_short,                             /* is_short */
                mmi_imgview_cat222_decode_result_hdlr,/* result callback */
                GDI_IMAGE_SRC_FROM_FILE);
        }
        else
        {
            ShowCategory222ScreenInternal(
                    (UI_string_type)g_imgview_context.title_str,                    /* title */
                    get_image(g_imgview_context.title_icon),                   /* title icon */
                    str_lsk_ptr,
                    0,
                    get_string(STR_GLOBAL_BACK),
                    get_image(IMG_GLOBAL_BACK),                                /* right soft key */
                    GDI_COLOR_WHITE,                                /* content BG color */
                    (CHAR*) NULL,                                     /* button bar string */
                    (CHAR*) g_imgview_context.filepath,                        /* image file name */
                    g_imgview_context.is_short,                             /* is_short */
                    mmi_imgview_cat222_decode_result_hdlr,/* result callback */
                    GDI_IMAGE_SRC_FROM_FILE);                       /* result callback */
        }
    }

#if defined(__MMI_IMGVIEW_NONBLOCKING_DECODE__)
    if (!mmi_frm_is_in_backward_scenario() && mmi_frm_scrn_get_active_id() != SCR_ID_IMGVIEW_FROM_FMGR)
    {
        return;
    }
    
    if (is_printable == TRUE)
    {
        SetLeftSoftkeyFunction(mmi_imgview_print_req,KEY_EVENT_UP);

    #ifdef __MMI_IMGVIEW_CSK_ENABLE__
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_imgview_print_req,KEY_EVENT_UP);
    #endif /* __MMI_IMGVIEW_CSK_ENABLE__ */
    }
    
    if (g_imgview_cui_ptr->lsk_setting.is_customized)
    {
        SetLeftSoftkeyFunction(mmi_imgview_lsk_custmize_confirmed,KEY_EVENT_UP);
    }

    SetRightSoftkeyFunction(mmi_imgview_exit_view_image_hdlr, KEY_EVENT_UP);
#else
    if (mmi_frm_scrn_get_active_id() != SCR_ID_IMGVIEW_FROM_FMGR)
	{
		/* this case is a block case, but add last frame callback of 222, it becomes a "non-block"*/
		return;
	}
    /* popup error than exit */
    if (g_imgview_context.result < 0)
    {
    /* handle plug-out memory card scenario, if we do not return from here, user will hear a tone played by display popup */
        if (mmi_is_redrawing_bk_screens() == TRUE)
        {
            return;
        }

        if (!mmi_fmgr_util_file_limit_check(FMGR_LIMIT_IMAGE_VIEWER, g_imgview_context.filepath, (CHAR**)&err_str_ptr))
        {
            mmi_imgview_display_popup_sg(g_imgview_cui_gid, (UI_string_type)err_str_ptr, MMI_EVENT_FAILURE, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP);
            return;
        }
        else
        {
            mmi_imgview_display_popup_sg(g_imgview_cui_gid, (UI_string_type)GetString(mmi_imgview_get_error_string_by_error_enum(g_imgview_context.result)), MMI_EVENT_FAILURE, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP);
            return;
        }
    }
    else
    {
        if (is_printable == TRUE)
        {
            SetLeftSoftkeyFunction(mmi_imgview_print_req,KEY_EVENT_UP);
            
        #ifdef __MMI_IMGVIEW_CSK_ENABLE__
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_imgview_print_req,KEY_EVENT_UP);
        #endif /* __MMI_IMGVIEW_CSK_ENABLE__ */
        }
        
        if (g_imgview_cui_ptr->lsk_setting.is_customized)
        {
            SetLeftSoftkeyFunction(mmi_imgview_lsk_custmize_confirmed,KEY_EVENT_UP);
        }
        
        SetRightSoftkeyFunction(mmi_imgview_exit_view_image_hdlr, KEY_EVENT_UP);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_view_image_hdlr_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_view_image_hdlr_ext(CHAR* file_path,BOOL is_short,U16 file_type, U16 title_icon, CHAR* title_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 uni_str_len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #define MMI_IMGVIEW_MAX_TITLE_LENGTH 511

    if (title_str == 0)
    {
        g_imgview_context.title_str = 0;
    }
    else 
    {        
        uni_str_len = mmi_ucs2strlen(title_str);
        if (uni_str_len > MMI_IMGVIEW_MAX_TITLE_LENGTH)
        {
            uni_str_len = MMI_IMGVIEW_MAX_TITLE_LENGTH;
            g_imgview_context.title_str = gui_malloc((MMI_IMGVIEW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH);
            mmi_ucs2ncpy(g_imgview_context.title_str, title_str, MMI_IMGVIEW_MAX_TITLE_LENGTH);
            g_imgview_context.title_str[MMI_IMGVIEW_MAX_TITLE_LENGTH * ENCODING_LENGTH] = 0;
            g_imgview_context.title_str[MMI_IMGVIEW_MAX_TITLE_LENGTH * ENCODING_LENGTH + 1] = 0;
        }    
        else if (uni_str_len > 0)
        {
            g_imgview_context.title_str = gui_malloc((uni_str_len + 1) * ENCODING_LENGTH);
            mmi_ucs2cpy(g_imgview_context.title_str, title_str);
        }
    }    

    g_imgview_context.filepath = gui_malloc(SRV_FMGR_PATH_BUFFER_SIZE); 
    mmi_ucs2cpy((CHAR*) g_imgview_context.filepath , (CHAR*) file_path);
    g_imgview_context.is_short = MMI_FALSE;
    g_imgview_context.file_type = file_type;
    g_imgview_context.title_icon = title_icon;
    if (g_imgview_cui_ptr->lsk_setting.is_customized == MMI_TRUE)
    {
        g_imgview_context.print_support = FALSE;
    }
    else
    {
        g_imgview_context.print_support = TRUE;
    }
    mmi_imgview_view_image_hdlr_internal();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_view_one_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_view_one_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_fileinfo_struct info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_fmgr_fs_path_get_fileinfo((WCHAR*)g_imgview_cui_ptr->view_mode.buff_ptr, &info);
    mmi_imgview_view_image_hdlr_ext(
        g_imgview_cui_ptr->view_mode.buff_ptr,
        FALSE,
        info.type,
        g_imgview_cui_ptr->title_confing.title_icon,
        (CHAR*)g_imgview_cui_ptr->title_confing.title_string);
}
/* Imageviwer call imgview CUI using start */
/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_run_imgview_cui
 * DESCRIPTION
 *  Run image view CUI
 * PARAMETERS
 *  parent_gid           :  [IN]  Image view's parent group id.
 *  filelist             :  [IN]  File list.
 *  start_index          :  [IN]  Start view index.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_run_imgview_cui(mmi_id parent_gid, SRV_FMGR_FILELIST_HANDLE filelist, U32 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id imgview_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((imgview_gid = cui_imgview_create(parent_gid)) != GRP_ID_INVALID)
    {
        cui_imgview_set_mode_filelist(imgview_gid, filelist,start_index);
        cui_imgview_set_app_id(imgview_gid, mmi_mediaview_get_curr_app_id());
        cui_imgview_set_ui_direction(imgview_gid, CUI_IMGVIEW_UI_DIRECTION_VERTICAL);
        cui_imgview_set_display_cap(imgview_gid, CUI_IMGVIEW_CAP_ALL, MMI_TRUE);   
        cui_imgview_run(imgview_gid);
    }
    else
    {
        /*TODO: add trace, enter fail*/
    }
}
/* Imgview CUI using end */


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_preentry_view_screen
 * DESCRIPTION
 *  Preentry function of image viewer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_preentry_view_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imgview_run_imgview_cui(g_mediaview_cui_gid,g_imgview_fl_hdl, g_imgview_fl_idx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_enter_before_play
 * DESCRIPTION
 *  Preentry function of imageviewer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_enter_view_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 retValue;
    MMI_ID_TYPE error_str_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_imgview_state==MMI_IMGVIEW_STATE_EXIT);

    mmi_mediaview_free_filelist();
    retValue = mmi_mediaview_create_filelist();
    if (retValue == FS_NO_ERROR)
    {
        S32 file_count;
        
        file_count = srv_fmgr_filelist_count(g_imgview_fl_hdl);
        if (file_count)
        {
            g_imgview_state = MMI_IMGVIEW_STATE_READY_TO_DECODE;
        #ifdef __MMI_IMAGE_VIEWER_EX__
            mmi_ivex_preentry_view_screen();
            g_imgview_state = MMI_IMGVIEW_STATE_EXIT;
        #elif defined __MMI_IMAGE_VIEWER_ADV__
            mmi_imgadv_preentry_view_screen();
        #else 
            mmi_imgview_preentry_view_screen();
        #endif
        }
        else
        {
            mmi_imgview_display_popup_sg(g_mediaview_cui_gid, (UI_string_type)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);
        }
    }
    else
    {
        /* error handle, lock file list will always ok, should not has sorting */
        error_str_id = srv_fmgr_fs_error_get_string(retValue);
        mmi_imgview_display_popup_sg(g_mediaview_cui_gid, (UI_string_type)GetString(error_str_id), 
            (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(retValue), 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_highlight_view_detail
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_highlight_view_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imgview_enter_view_screen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_temp_dummy_screen
 * DESCRIPTION
 *  dummy imgview id
 * PARAMETERS
 *  sleep       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgview_temp_dummy_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_image_change
 * DESCRIPTION
 *  This function is called to show image.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_image_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_enter(g_imgview_cui_gid, SCR_ID_GLOBAL_DUMMY, NULL, mmi_imgview_temp_dummy_screen, MMI_FRM_FULL_SCRN);
    g_imgview_context.is_change_image = MMI_TRUE;
    mmi_frm_scrn_close(g_imgview_cui_gid, SCR_ID_IMGVIEW_VIEW);
    mmi_imgview_entry_view_detail_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_view_detail_press_up
 * DESCRIPTION
 *  press up in view detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_view_detail_press_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cur_index;
    srv_fmgr_fileinfo_struct file_info;
    S32 counter;
    S32 file_count;
    S32 srv_fmgr_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_imgview_context.is_refreshing == MMI_TRUE)
    {
        return;
    }
    
#ifdef __DRM_SUPPORT__
    mmi_imgview_consume_drm_if_need();
#endif

    cur_index = g_imgview_fl_idx;
    file_count = srv_fmgr_filelist_count(g_imgview_fl_hdl);
    counter = 0;

    if (file_count > 1)
    {
        do
        {
            /* FMGR_Revise */
            if(g_imgview_fl_idx)
                g_imgview_fl_idx--;
            else
                g_imgview_fl_idx = file_count-1;
            cui_folder_browser_set_highlight_index(mmi_mediaview_get_browse_gid(), g_imgview_fl_idx);
            srv_fmgr_ret = srv_fmgr_filelist_get_fileinfo(g_imgview_fl_hdl, g_imgview_fl_idx, &file_info);
            if(srv_fmgr_ret < 0)
            {
                if(srv_fmgr_ret == SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY)
                {
                    srv_fmgr_ret = srv_fmgr_filelist_load_file(
                        g_imgview_fl_hdl, 
                        g_imgview_fl_idx, 
                        mmi_imgview_load_file_proc, 
                        (void*)mmi_imgview_view_detail_press_up);
                    MMI_ASSERT(srv_fmgr_ret != SRV_FMGR_FILELIST_ERROR_FILE_READY);
                    g_imgview_context.is_refreshing = MMI_TRUE;
                }

                g_imgview_fl_idx = cur_index;
                return;
            }
            counter++;

            if (!(file_info.attribute & FS_ATTR_DIR))
            {
                mmi_imgview_image_change();
                return;
            }

            if (counter >= (file_count - 1))
            {
                return;
            }

        } while (1);
    }
    else if (file_count < 0)
    {
        mmi_imgview_display_popup_sg(g_imgview_cui_gid, (UI_string_type)GetString(FMGR_FS_MEDIA_CHANGED_TEXT), MMI_EVENT_FAILURE, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP);
        g_imgview_state = MMI_IMGVIEW_STATE_EXIT;
        return;
    }
    else if (file_count == 0)
    {
        mmi_imgview_display_popup_sg(g_imgview_cui_gid, (UI_string_type)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP);
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_view_detail_press_down
 * DESCRIPTION
 *  press down in view detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_view_detail_press_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cur_index;
    srv_fmgr_fileinfo_struct file_info;
    S32 counter;
    S32 file_count;
    S32 srv_fmgr_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_imgview_context.is_refreshing == MMI_TRUE)
    {
        return;
    }
    
#ifdef __DRM_SUPPORT__
    mmi_imgview_consume_drm_if_need();
#endif

    /* exit and clear previous screen for history - then enter again */
    /* FMGR_Revise */
    cur_index = g_imgview_fl_idx;
    file_count = srv_fmgr_filelist_count(g_imgview_fl_hdl);

    counter = 0;

    if (file_count > 1)
    {
        do
        {
            /* FMGR_Revise */
            g_imgview_fl_idx++;
            if(g_imgview_fl_idx == file_count)
                g_imgview_fl_idx = 0;
            cui_folder_browser_set_highlight_index(mmi_mediaview_get_browse_gid(), g_imgview_fl_idx);
            srv_fmgr_ret = srv_fmgr_filelist_get_fileinfo(g_imgview_fl_hdl, g_imgview_fl_idx, &file_info);
            if(srv_fmgr_ret < 0)
            {
                if(srv_fmgr_ret == SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY)
                {
                    srv_fmgr_ret = srv_fmgr_filelist_load_file(
                        g_imgview_fl_hdl, 
                        g_imgview_fl_idx, 
                        mmi_imgview_load_file_proc, 
                        (void*)mmi_imgview_view_detail_press_up);
                    MMI_ASSERT(srv_fmgr_ret != SRV_FMGR_FILELIST_ERROR_FILE_READY);
                    g_imgview_context.is_refreshing = MMI_TRUE;
                }

                g_imgview_fl_idx = cur_index;
                return;
            }
            counter++;

            if (!(file_info.attribute & FS_ATTR_DIR))
            {
                mmi_imgview_image_change();
                return;
            }

            if (counter >= (file_count - 1))
            {
                return;
            }

        } while (1);
    }
    else if (file_count < 0)
    {
        mmi_imgview_display_popup_sg(g_imgview_cui_gid, (UI_string_type)GetString(FMGR_FS_MEDIA_CHANGED_TEXT), MMI_EVENT_FAILURE, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP);
        g_imgview_state = MMI_IMGVIEW_STATE_EXIT;
        return;
    }
    else if (file_count == 0)
    {
        mmi_imgview_display_popup_sg(g_imgview_cui_gid, (UI_string_type)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP);
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_exit_view_detail_screen
 * DESCRIPTION
 *  exit view detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_exit_view_detail_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DRM_SUPPORT__   
    /* based on DEL SCR will do first */
    if (g_imgview_context.drm_state == IMGVIEW_DRM_STATE_CONSUME)
    {
        DRM_pause_consume(g_imgview_context.drm_id);
        MMI_IMGVIEW_DRM_ENTER_STATE(IMGVIEW_DRM_STATE_PAUSE);
    }
#endif

#if defined(__MMI_IMGVIEW_NONBLOCKING_DECODE__)
    gdi_image_nb_stop_all();
#endif

    /* free buffer */
    if (g_imgview_context.filepath != NULL)
    {
        gui_free(g_imgview_context.filepath);
        g_imgview_context.filepath = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_exit_view_detail_release
 * DESCRIPTION
 *  imgview view exit function handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgview_exit_view_detail_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __DRM_SUPPORT__
    mmi_imgview_consume_drm_if_need();
    #endif

    g_imgview_context.result = MMI_IMGVIEW_OK;

    if (g_imgview_context.is_change_image == MMI_FALSE)
    {
        g_imgview_state = MMI_IMGVIEW_STATE_EXIT;
        mmi_mediaview_free_filelist();
    }
    
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_view_detail_del_scr_callback
 * DESCRIPTION
 *  imgview view detail delete screen callback handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_imgview_view_detail_del_scr_callback(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_imgview_context.filepath != NULL)
    {
        gui_free(g_imgview_context.filepath);
        g_imgview_context.filepath = NULL;
    }

#ifdef __DRM_SUPPORT__
    mmi_imgview_consume_drm_if_need();
#endif

    if (g_imgview_context.is_change_image == MMI_FALSE)
    {
        g_imgview_context.result = MMI_IMGVIEW_OK;
        g_imgview_state = MMI_IMGVIEW_STATE_EXIT;
        mmi_mediaview_free_filelist();
    }
    
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_view_screen_leave_proc
 * DESCRIPTION
 *  Ext view screen leave proc.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_ret mmi_imgview_view_screen_leave_proc(mmi_event_struct *evt)
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
        mmi_imgview_view_detail_del_scr_callback(NULL);
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_entry_view_detail_screen
 * DESCRIPTION
 *  entry view detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_entry_view_detail_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_fileinfo_struct file_info;
    S32 total_count;
    U8 *guiBuffer;
    BOOL is_printable = FALSE;
    U16 str_lsk = 0;
    MMI_BOOL entry_ret;
    S32 srv_fl_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* exit previous screen */
    if (!mmi_frm_is_in_backward_scenario() && !mmi_frm_group_is_present(g_imgview_cui_gid))
    {
        mmi_frm_group_enter(g_imgview_cui_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }
    entry_ret = mmi_frm_scrn_enter(g_imgview_cui_gid, SCR_ID_IMGVIEW_VIEW, mmi_imgview_exit_view_detail_screen, mmi_imgview_entry_view_detail_screen, MMI_FRM_FULL_SCRN);
    if (!entry_ret)
    {
        return;
    }
    
    mmi_frm_scrn_close(g_imgview_cui_gid, SCR_ID_GLOBAL_DUMMY);
    mmi_frm_scrn_set_leave_proc(g_imgview_cui_gid, SCR_ID_IMGVIEW_VIEW, mmi_imgview_view_screen_leave_proc);

    /* check if there is small screen above IMAGEVIEWER */
    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        /* currently we clear layer as black as background of small screen. */
        gdi_layer_clear(GDI_COLOR_BLACK);    
        return;
    }

    total_count = srv_fmgr_filelist_count(g_imgview_fl_hdl);

    if (total_count == 0)
    {
        mmi_imgview_display_popup_sg(g_imgview_cui_gid, (UI_string_type)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP);
        mmi_mediaview_free_filelist();
        g_imgview_state = MMI_IMGVIEW_STATE_EXIT;
        return;

    }
    else if (total_count < 0)
    {
        mmi_imgview_display_popup_sg(g_imgview_cui_gid, (UI_string_type)GetString(FMGR_FS_MEDIA_CHANGED_TEXT), MMI_EVENT_FAILURE, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP);
        mmi_mediaview_free_filelist();
        g_imgview_state = MMI_IMGVIEW_STATE_EXIT;
        return;
    }
    g_imgview_context.is_refreshing = MMI_FALSE;
    g_imgview_context.is_change_image = MMI_FALSE;
    /* allocate string buffer */
    g_imgview_context.filepath = gui_malloc(SRV_FMGR_PATH_BUFFER_SIZE);

    /* In fact, here filepath should be ready because it is locked from fmgr */
    srv_fl_ret = srv_fmgr_filelist_get_filepath(g_imgview_fl_hdl, g_imgview_fl_idx, (WCHAR*)g_imgview_context.filepath, SRV_FMGR_PATH_BUFFER_SIZE);
    if (srv_fl_ret < 0)
    {
        mmi_str_id error_str_id;
        error_str_id = srv_fmgr_fs_error_get_string(srv_fl_ret);
        mmi_imgview_display_popup_sg(g_imgview_cui_gid, (UI_string_type)GetString(error_str_id), 
            (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(srv_fl_ret), 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP);
        return;
    }

    guiBuffer = mmi_frm_scrn_get_gui_buf(g_imgview_cui_gid, SCR_ID_IMGVIEW_VIEW);
    if (guiBuffer != NULL)
    {
        CHAR buf_filepath[SRV_FMGR_PATH_BUFFER_SIZE];
        ASSERT(buf_filepath!=NULL);
        mmi_imgview_get_storage_file_path((WCHAR*)buf_filepath);

        if (mmi_ucs2ncmp(buf_filepath, g_imgview_context.filepath, mmi_ucs2strlen(buf_filepath)) != 0)
        {
            mmi_mediaview_close_view_cui(&g_imgview_cui_gid, EVT_ID_IMGVIEW_CLOSE_GID);
            return;
        }
    }

    /* DRM permission check */
#ifdef __DRM_SUPPORT__
    mmi_imgview_preprocess_drm_right();
#endif 

    g_imgview_context.is_short = MMI_FALSE;
    g_imgview_context.image_type = gdi_image_get_type_from_file(g_imgview_context.filepath);
    srv_fmgr_fs_path_get_fileinfo((WCHAR*)g_imgview_context.filepath, &file_info);
    /* check if this image printable */
    #if defined(__DRM_SUPPORT__)
    if ((IMGVIEW_DRM_PRINT_VALID & g_imgview_context.drm_valid)!=0 && 
        mmi_imgview_print_enabler(&file_info) > 0)
    #else
    if (mmi_imgview_print_enabler(&file_info) > 0)
    #endif
    {
        is_printable = TRUE;
        str_lsk = STR_GLOBAL_PRINT;
    }

    wgui_cat222_disable_err_msg_display();

    /* entry cat222 to decode and display a image from file */
    ShowCategory222Screen(
        0,
        GetRootTitleIcon(MENU_ID_IMGVIEW_APP),    /* title */
        str_lsk,
        0,                                  /* left soft key */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                    /* right soft key */
        GDI_COLOR_WHITE,                    /* content BG color */
        (CHAR*) NULL,  /* button bar string */
        (CHAR*) g_imgview_context.filepath,   /* image file name */
        g_imgview_context.is_short,                 /* is short filename */
        mmi_imgview_cat222_decode_result_hdlr,/* result callback */
        GDI_IMAGE_SRC_FROM_FILE);                              

    if(mmi_frm_scrn_get_active_id() != SCR_ID_IMGVIEW_VIEW)
        return;

    if (is_printable)
    {
        SetLeftSoftkeyFunction(mmi_imgview_print_req,KEY_EVENT_UP);

    #ifdef __MMI_IMGVIEW_CSK_ENABLE__
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_imgview_print_req,KEY_EVENT_UP);
    #endif /* __MMI_IMGVIEW_CSK_ENABLE__ */
    }
    
    /* if less or equal to 1 image, no need to switch to next image */
    if (total_count > 1)
    {
        SetKeyHandler(mmi_imgview_view_detail_press_up, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_imgview_view_detail_press_down, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_imgview_view_detail_press_down, KEY_VOL_DOWN, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_imgview_view_detail_press_up, KEY_VOL_UP, KEY_EVENT_DOWN);
    }

    SetRightSoftkeyFunction(mmi_imgview_exit_view_detail_release, KEY_EVENT_UP);
}

/*****************************************************************************
*
* Select Prefered Storage                                                                
*
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_hint_set_storage
 * DESCRIPTION
 *  set storage's hint
 * PARAMETERS
 *  index       [IN]        
 *  a(?)        [IN]        Selection index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_hint_set_storage(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((CHAR*) hintData[(index)], 0, sizeof(hintData[(index)]));
    srv_fmgr_drv_get_name((U8)((CHAR)g_imgview_context.storage), (WCHAR*)((CHAR*)hintData[index]), (SRV_FMGR_DRV_MAX_NAME_LEN + 1) * ENCODING_LENGTH);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_highlight_set_storage
 * DESCRIPTION
 *  set storage's highlight
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_highlight_set_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imgview_entry_set_storage_screen, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_imgview_entry_set_storage_screen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_cat222_decode_result_hdlr
 * DESCRIPTION
 *  handle decode result, it is callback from cat222
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
static void mmi_imgview_cat222_decode_result_hdlr(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type err_str_ptr = NULL;
    MMI_ID scrnid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result >= 0)
    {
        g_imgview_context.result = MMI_IMGVIEW_OK;
    }
    else
    {
        g_imgview_context.result = result;
    }

#ifdef __DRM_SUPPORT__
    if (g_imgview_context.drm_handle != NULL)
    {
        if (result >= 0)
        {
            g_imgview_context.drm_id = 
                DRM_consume_rights(g_imgview_context.drm_handle, DRM_PERMISSION_DISPLAY, mmi_imgview_drm_callback_hdlr);
            MMI_IMGVIEW_DRM_ENTER_STATE(IMGVIEW_DRM_STATE_CONSUME);
        }

        DRM_close_file(g_imgview_context.drm_handle);
        g_imgview_context.drm_handle = NULL;
    }
#endif /* __DRM_SUPPORT__ */

//#if defined(__MMI_IMGVIEW_NONBLOCKING_DECODE__)

    /* handle plug-out memory card scenario, if we do not return from here, user will hear a tone played by display popup */
        if (mmi_is_redrawing_bk_screens() == TRUE)
        {
            return;
        }
    
    switch (g_imgview_cui_ptr->view_mode.viewmode)
    {
        case CUI_IMGVIEW_VIEWMODE_FILENAME:
        case CUI_IMGVIEW_VIEWMODE_PREFETCH:
            scrnid = SCR_ID_IMGVIEW_FROM_FMGR;
            break;
        case CUI_IMGVIEW_VIEWMODE_FILELIST:
        case CUI_IMGVIEW_VIEWMODE_FILENAME_ARRAY:
        case CUI_IMGVIEW_VIEWMODE_IMAGEID_ARRAY:
        case CUI_IMGVIEW_VIEWMODE_FOLDER:
            scrnid = SCR_ID_IMGVIEW_VIEW;
            break;
        default:
            MMI_ASSERT(0);
    }
    
    /* popup error than exit */
    if (g_imgview_context.result < 0 && (mmi_frm_scrn_get_active_id() == scrnid))
    {
        if (!mmi_fmgr_util_file_limit_check(FMGR_LIMIT_IMAGE_VIEWER, g_imgview_context.filepath, (CHAR**)&err_str_ptr))
        {
            mmi_imgview_display_popup_sg(g_imgview_cui_gid, (UI_string_type)err_str_ptr, MMI_EVENT_FAILURE, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP);
        }
        else
        {
            mmi_imgview_display_popup_sg(g_imgview_cui_gid, (UI_string_type)GetString(mmi_imgview_get_error_string_by_error_enum(g_imgview_context.result)), MMI_EVENT_FAILURE, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP);
        }
    }    
//#endif /* __MMI_IMGVIEW_NONBLOCKING_DECODE__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_select_drive_callback
 * DESCRIPTION
 *  entry storage screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_select_drive_callback( CHAR drv_letter )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR buf_filepath[SRV_FMGR_PATH_BUFFER_SIZE];
    S32 create_result;
    S16 error;
    MMI_ID_TYPE error_str_id;
    U16 storage_backup = g_imgview_context.storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (drv_letter != 0)
    {
        g_imgview_context.storage = (U16) drv_letter;

        /* storge setting to NVRAM */
        WriteValue(NVRAM_IMGVIEW_STORAGE, &g_imgview_context.storage, DS_SHORT, &error);

        #ifdef __MMI_CAMCORDER__
            mmi_camco_set_storage(g_imgview_context.storage);
        #ifdef __MMI_VIDEO_PLAYER__
            mmi_vdoply_set_storage(g_imgview_context.storage);
        #endif
        #endif /* __MMI_CAMCORDER__ */

        mmi_imgview_get_storage_file_path((WCHAR*)buf_filepath);
        create_result = mmi_imgview_create_file_dir(buf_filepath);
        g_imgview_context.is_storage_ready = MMI_FALSE;

        if (create_result < FS_NO_ERROR)
        {
            error_str_id = srv_fmgr_fs_error_get_string(create_result);
            mmi_imgview_display_popup_sg(g_imgview_cui_gid, (UI_string_type)GetString(error_str_id), 
                (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(create_result), 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);

            g_imgview_context.storage = storage_backup;

            /* storge setting to NVRAM */
            WriteValue(NVRAM_IMGVIEW_STORAGE, &g_imgview_context.storage, DS_SHORT, &error);

            #ifdef __MMI_CAMCORDER__
                mmi_camco_set_storage(g_imgview_context.storage);
            #ifdef __MMI_VIDEO_PLAYER__
                mmi_vdoply_set_storage(g_imgview_context.storage);
            #endif
            #endif /* __MMI_CAMCORDER__ */

            mmi_imgview_get_storage_file_path((WCHAR*)buf_filepath);
        }
        else
        {
            g_imgview_context.is_storage_ready = MMI_TRUE;
            /*mmi_imgview_display_popup_sg(g_imgview_cui_gid, (UI_string_type)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);*/
        }
        
        if (mmi_frm_group_is_present(g_mediaview_cui_gid))
        {
            cui_mediaview_set_folder_path(g_mediaview_cui_gid, (CHAR*)buf_filepath);
        }
        
        if (g_imgview_context.is_entry_browse)
        {
            cui_mediaview_set_folder_path(g_mediaview_cui_gid, (CHAR*)buf_filepath);
            cui_folder_browser_set_folder_path(g_imgview_context.fmgr_scr_id, (WCHAR*)buf_filepath);
        }
    }
    else
    {
        if (g_imgview_context.is_storage_ready == MMI_FALSE &&
            mmi_frm_group_is_present(g_mediaview_cui_gid))
        {
            mmi_mediaview_close_view_cui(&g_mediaview_cui_gid, EVT_ID_MEDIAVIEW_CLOSE_GID);
            g_imgview_context.is_storage_ready = MMI_TRUE;
        }    
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_storage_select_cb
 * DESCRIPTION
 *  entry storage screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_storage_select_cb(S32 drv_letter )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drv_letter >= 0)
    {
        mmi_imgview_select_drive_callback((CHAR)drv_letter);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_entry_set_storage_screen
 * DESCRIPTION
 *  enter set storage screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_entry_set_storage_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id fmgr_storage_selector_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((fmgr_storage_selector_gid = cui_storage_selector_create(g_mediaview_cui_gid, g_imgview_context.storage, 0)) != GRP_ID_INVALID)
    {
        cui_storage_selector_set_title(fmgr_storage_selector_gid, NULL, GetRootTitleIcon(MENU_ID_IMGVIEW_APP));
        cui_storage_selector_set_ui_style(fmgr_storage_selector_gid, CUI_FMGR_UI_STYLE_BANNER_LIST);//NEED TEST
        cui_storage_selector_run(fmgr_storage_selector_gid);
    }
    else
    {
        /*TODO: add trace, create error*/
    }
}


/*****************************************************************************
*
* Initialization and Entry of ImageViewer Application                                                                  
*
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_highlight_app
 * DESCRIPTION
 *  app hilight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_highlight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imgview_launch, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_hint_view_style
 * DESCRIPTION
 *  set storage's hint
 * PARAMETERS
 *  index       [IN]        
 *  a(?)        [IN]        Selection index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_hint_view_style(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_mediaview_style_enum view_style;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((CHAR*) hintData[(index)], 0, sizeof(hintData[(index)]));

    view_style = mmi_mediaview_get_view_style();

    if (view_style == CUI_MEDIAVIEW_STYLE_LIST)
    {
        mmi_ucs2cpy((CHAR*) hintData[index],
                    (CHAR*) GetString((U16) (STR_ID_IMGVIEW_VIEW_STYLE_LIST)));
    }
    else if (view_style == CUI_MEDIAVIEW_STYLE_MATRIX)
    {
        mmi_ucs2cpy((CHAR*) hintData[index],
                    (CHAR*) GetString((U16) (STR_ID_IMGVIEW_VIEW_STYLE_MATRIX)));
    }
    else
    {
        /* Should be wallview */
        mmi_ucs2cpy((CHAR*) hintData[index],
                    (CHAR*) GetString((U16) (STR_ID_IMGVIEW_VIEW_STYLE_MATRIX)));
    }
}


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
void mmi_mediaview_browser_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_FOLDER_BROWSER_ON_OPTION:
            {
                cui_folder_browser_on_option_event_struct *opt_evt = (cui_folder_browser_on_option_event_struct*)evt;
                
                if(opt_evt->menu_cui_evt->parent_menu_id == MENU_ID_IMGVIEW_VIEW_STYLE && 
                   opt_evt->menu_cui_evt->evt_id == EVT_ID_CUI_MENU_LIST_ENTRY)
                {
                    mmi_menu_id sub_id;
                    cui_mediaview_style_enum view_style = mmi_mediaview_get_view_style();
                                
                    if (view_style == CUI_MEDIAVIEW_STYLE_LIST)
                    {
                        sub_id = MENU_ID_IMGVIEW_VIEW_STYLE_LIST;
                    }
                    else if (view_style == CUI_MEDIAVIEW_STYLE_MATRIX)
                    {
                        sub_id = MENU_ID_IMGVIEW_VIEW_STYLE_MATRIX;
                    }
                    else
                    {
                        /* Should be wallview */
                        sub_id = MENU_ID_IMGVIEW_VIEW_STYLE_MATRIX;
                    }

                    //cui_menu_set_currlist_flags(opt_evt->menu_cui_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                    cui_menu_set_currlist_highlighted_id(opt_evt->menu_cui_id, sub_id);
                }                
            }
            break;

        case EVT_ID_CUI_FOLDER_BROWSER_ON_MENU:
            {
                cui_folder_browser_on_menu_event_struct *menu_evt = (cui_folder_browser_on_menu_event_struct*)evt;
                switch(menu_evt->menuitem_id)
                {
                    case MENU_ID_IMGVIEW_VIEW_STYLE_LIST:
                        mmi_mediaview_set_view_style(CUI_MEDIAVIEW_STYLE_LIST);
                        break;
                    case MENU_ID_IMGVIEW_VIEW_STYLE_MATRIX:
                        mmi_mediaview_set_view_style(CUI_MEDIAVIEW_STYLE_MATRIX);
                        break;
                #ifdef __MMI_IMGVIEW_FEATURE_STORAGE__
                    case MENU_ID_IMGVIEW_STORAGE:
                        mmi_imgview_entry_set_storage_screen();
                        break;
                #endif
                    default:
                        break;
                }
            }
            break;

        case EVT_ID_CUI_FOLDER_BROWSER_ON_ENTRY:
            mmi_mediaview_browse_cui_enter_callback(((mmi_group_event_struct*)evt)->sender_id);
            break;
            
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_init_app
 * DESCRIPTION
 *  init imageviwer applcation, register highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init imageviewer application entry handler */
#if defined(__MMI_SCREEN_ROTATE__)
    g_imgview_context.imgview_rotate = 0;
#endif 
    g_imgview_context.is_storage_ready = MMI_TRUE;
    g_imgview_context.result = MMI_IMGVIEW_OK;
    g_imgview_context.title_str = 0;

#ifdef __DRM_SUPPORT__
    g_imgview_context.drm_state = IMGVIEW_DRM_STATE_EXIT;
    g_imgview_context.drm_id = 0;
    g_imgview_context.drm_handle = NULL;
#endif

#ifdef __MMI_IMAGE_VIEWER_EX__
    mmi_ivex_init_app();
#elif defined  __MMI_IMAGE_VIEWER_ADV__
    mmi_imgadv_init_app();
#endif
    mmi_imgview_load_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_view_from_fmgr_del_scr_callback
 * DESCRIPTION
 *  imgview delete screen callback handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_imgview_view_from_fmgr_del_scr_callback(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_imgview_context.filepath != NULL)
    {
        gui_free(g_imgview_context.filepath);
        g_imgview_context.filepath = NULL;
    }

    if(g_imgview_context.title_str != NULL)
    {
        gui_free(g_imgview_context.title_str);
        g_imgview_context.title_str = NULL;
    }

    #ifdef __DRM_SUPPORT__
        mmi_imgview_consume_drm_if_need();
    #endif


    g_imgview_context.result = MMI_IMGVIEW_OK;
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_del_scr_callback
 * DESCRIPTION
 *  imgview delete screen callback handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_imgview_del_scr_callback(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgview_context.is_storage_ready = MMI_TRUE;
#ifdef __DRM_SUPPORT__
    mmi_imgview_consume_drm_if_need();
#endif
    
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_del_app_scr_callback
 * DESCRIPTION
 *  imgview delete screen callback handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_imgview_del_app_scr_callback(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgview_context.is_storage_ready = MMI_TRUE;
#ifdef __DRM_SUPPORT__
    mmi_imgview_consume_drm_if_need();
#endif
    
#ifdef __MMI_VUI_MEDIAWALL__
    if (g_imgview_context.memory_info.is_vapp_call)
    {
        mmi_mediaview_free_med_memory();
        mmi_mediaview_free_app_based_memory();
        g_imgview_context.memory_info.is_vapp_call = MMI_FALSE;
    }
#endif
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_change_storage_confirm_yes
 * DESCRIPTION
 *  This function is to confirm save before saving setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_change_storage_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imgview_restore_setting();
    g_imgview_context.is_storage_ready = MMI_TRUE;
    g_mediaview_cui_ptr->folder_path[0] = (CHAR)g_imgview_context.storage;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_change_storage_confirm_no
 * DESCRIPTION
 *  This function is to confirm save before saving setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_change_storage_confirm_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgview_context.is_storage_ready = MMI_FALSE;
    mmi_mediaview_close_view_cui(&g_mediaview_cui_gid, EVT_ID_MEDIAVIEW_CLOSE_GID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_change_storage_confirm
 * DESCRIPTION
 *  This function is to confirm save before saving setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_change_storage_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_drv_type_enum      storage_type_old;
    MMI_STR_ID                  query_str_id;
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    storage_type_old = (srv_fmgr_drv_type_enum)srv_fmgr_drv_get_type((U8)g_imgview_context.storage);

    if(storage_type_old >= SRV_FMGR_DRV_CARD_TYPE && storage_type_old <= SRV_FMGR_DRV_CARD_2_TYPE)
    {
        query_str_id = STR_GLOBAL_MC_REMOVED_USE_PHONE;
    }
    else if(storage_type_old >= SRV_FMGR_DRV_OTG_TYPE && storage_type_old <= SRV_FMGR_DRV_OTG_8_TYPE)
    {
        query_str_id = STR_GLOBAL_OTG_REMOVED_USE_PHONE_QUERY;
    }else
        return;

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = g_mediaview_cui_gid;
    arg.user_tag = (void*)MMI_IMGVIEW_POPUP_RESULT_PROCESS_CONFIRM_STORAGE;
    mmi_confirm_display(
        (WCHAR*)GetString(query_str_id),
        MMI_EVENT_QUERY,
        &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_launch_app
 * DESCRIPTION
 *  image viewer entry point
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_launch_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    S32 create_result;
    CHAR* error_string_ptr;
    S32 error_type= MMI_EVENT_FAILURE;
    SRV_FMGR_DRVLIST_HANDLE drvlist;
    S32 total_drv_num = 0;
    MMI_BOOL entry_ret;
    mmi_imgview_popup_result_process_enum process;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_is_in_backward_scenario())
    {
        mmi_frm_group_enter(g_mediaview_cui_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }
    entry_ret = mmi_frm_scrn_enter(g_mediaview_cui_gid, SCR_ID_IMGVIEW_APP, NULL, mmi_imgview_launch_app, MMI_FRM_FULL_SCRN);
    mmi_frm_scrn_set_leave_proc(g_mediaview_cui_gid, SCR_ID_IMGVIEW_APP, mmi_mediaview_screen_leave_proc);
    if (!entry_ret)
    {
        return;
    }

    drvlist = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ALL);
    total_drv_num = srv_fmgr_drivelist_count(drvlist);
    srv_fmgr_drivelist_destroy(drvlist);
#ifdef __FS_CARD_SUPPORT__
    /* for 64+32 */
    if (total_drv_num == 0)
    {
        error_string_ptr = GetString(STR_GLOBAL_INSERT_MEMORY_CARD);
        error_type = MMI_EVENT_FAILURE;
        process = MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP;
        goto entry_app_error_handle;
    }
#endif

    /* check if there is small screen above IMAGEVIEWER */
    ShowCategoryDummySmallScreen();
    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        return;
    }

    if (!mmi_frm_is_in_backward_scenario())
    {
        g_imgview_context.is_storage_ready = MMI_TRUE;
    }

    if (g_imgview_context.is_storage_ready == MMI_FALSE)
    {
        mmi_imgview_entry_set_storage_screen();
        return ;
    }

    if (FS_NO_ERROR == FS_GetDevStatus((U16)g_mediaview_cui_ptr->folder_path[0] ,FS_MOUNT_STATE_ENUM))
    {
        create_result = mmi_imgview_create_file_dir(g_mediaview_cui_ptr->folder_path);

        if (create_result < 0)
        {
            error_string_ptr = GetString(srv_fmgr_fs_error_get_string(create_result));
            error_type = srv_fmgr_fs_error_get_popup_type(create_result);
            process = MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE;

            goto entry_app_error_handle;
        }
    }
    else
    {
        drvlist = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE_ONLY);
        total_drv_num = srv_fmgr_drivelist_count(drvlist);
        srv_fmgr_drivelist_destroy(drvlist);

        g_imgview_context.is_storage_ready = MMI_FALSE;

        if(total_drv_num == 0)
        {
            /* for 64+32 */
            error_string_ptr = GetString(STR_GLOBAL_INSERT_MEMORY_CARD);
            error_type = MMI_EVENT_FAILURE;
            process = MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP;
        }
        else if(total_drv_num == 1)
        {
            mmi_imgview_change_storage_confirm();
            return;
        }
        else
        {
            mmi_imgview_entry_set_storage_screen();
            return;
        }
        goto entry_app_error_handle;
    }

    /* reset imageviewr */
#ifdef __MMI_IMAGE_VIEWER_EX__
    mmi_ivex_reset_app();
#elif defined  __MMI_IMAGE_VIEWER_ADV__
    mmi_imgadv_reset_app();
#endif 

    /* check if it is valid path */
    file_handle = FS_Open((PU16)g_mediaview_cui_ptr->folder_path, FS_OPEN_DIR | FS_READ_ONLY);
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
        mmi_mediaview_browse_cui_enter(g_mediaview_cui_gid,
                                                (WCHAR*)g_mediaview_cui_ptr->folder_path,
                                                MENU_ID_IMGVIEW_FILE_OPTION,
                                                MENU_ID_IMGVIEW_EMPTY_FOLDER_OPTION);
        return;
    }
    else
    {
        error_string_ptr = GetString(srv_fmgr_fs_error_get_string(file_handle));
        error_type = srv_fmgr_fs_error_get_popup_type(file_handle);
        process = MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE;
        goto entry_app_error_handle;
    }

entry_app_error_handle:

    mmi_imgview_display_popup_sg(g_mediaview_cui_gid, (UI_string_type)error_string_ptr, (mmi_event_notify_enum)error_type, 0, process);

    #if defined(__FS_CARD_SUPPORT__)
        /* for 64+32 */
        if (total_drv_num == 0 && process != MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP)
        {
            mmi_mediaview_close_view_cui(&g_mediaview_cui_gid, EVT_ID_MEDIAVIEW_CLOSE_GID);
            return;
        }
        g_imgview_context.is_storage_ready = MMI_FALSE;
    #else
        if (process != MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP)
        {
            mmi_mediaview_close_view_cui(&g_mediaview_cui_gid, EVT_ID_MEDIAVIEW_CLOSE_GID);
        }
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_display_popup_sg
 * DESCRIPTION
 *  This function shows display popup.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_display_popup_sg(mmi_id parent_gid, UI_string_type str_ptr, mmi_event_notify_enum event, U16 rotate, mmi_imgview_popup_result_process_enum process)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_popup_property_init(&arg);

    if (parent_gid == GRP_ID_INVALID)
    {
        arg.parent_id = GRP_ID_ROOT;
    }
    else
    {
        arg.parent_id = parent_gid;
        arg.user_tag = (void*)process;
    }
#if defined(__MMI_SCREEN_ROTATE__)
    
    if (g_imgview_context.imgview_rotate == 0 || g_imgview_context.imgview_rotate == 1)
    {
        arg.rotation = MMI_FRM_SCREEN_ROTATE_0;
    }
    else
    {
        arg.rotation = MMI_FRM_SCREEN_ROTATE_270;
    }
#else 
    arg.rotation = MMI_FRM_SCREEN_ROTATE_0;
#endif
    mmi_popup_display((WCHAR*)str_ptr, event, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_get_storage_file_path
 * DESCRIPTION
 *  get current active storage file path.
 * PARAMETERS
 *  filepath        [OUT]       File path
 * RETURNS
 * BOOL
 *****************************************************************************/
S32 mmi_imgview_get_storage_file_path(WCHAR *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR drv_buf[8];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imgview_load_setting();
    
    sprintf(drv_buf, "%c:\\", (U8)g_imgview_context.storage);
    mmi_asc_to_ucs2((CHAR*)filepath, drv_buf);
    mmi_ucs2cat((CHAR*) filepath, (CHAR*) MMI_IMGVIEW_STORAGE_FILEPATH_PHONE);

    return mmi_imgview_create_file_dir((CHAR*)filepath);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_group_proc
 * DESCRIPTION
 *  APP view grup proc
 * PARAMETERS
 *  evt      : [OUT] event pointer
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_imgview_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_event_struct *cui_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_ENTER:
        /* enter group ToDo1 */
            break;
        case EVT_ID_GROUP_ACTIVE:
        /* enter group ToDo2 */
            break;
        case EVT_ID_GROUP_FOCUSED:
        /* enter group ToDo3 */
            break;
        case EVT_ID_GROUP_GOBACK:
        /* gobackhistory ToDo1 */
            break;
        case EVT_ID_GROUP_INACTIVE:
        /* gobackhistory ToDo2 */
            break;
        case EVT_ID_GROUP_EXIT:
        /* gobackhistory ToDo3 */
            break;
        case EVT_ID_GROUP_DEINIT:
        /* gobackhistory ToDo4 */
            break;
        case EVT_ID_MEDIAVIEW_CLOSE_GID:
        /* closegroup ToDo1 */
            cui_evt = (mmi_group_event_struct*)evt;
            cui_mediaview_close(cui_evt->sender_id);
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_group_create
 * DESCRIPTION
 *  Create app group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_id mmi_imgview_group_create(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id temp_parent_gid;
    CHAR buf_filepath[SRV_FMGR_PATH_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imgview_get_storage_file_path((WCHAR*)buf_filepath);
    temp_parent_gid = mmi_frm_group_create(g_imgview_context.app_id, GRP_ID_AUTO_GEN, mmi_imgview_group_proc, NULL); 
    mmi_frm_group_enter(temp_parent_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    if ((g_mediaview_cui_gid = cui_mediaview_create(temp_parent_gid)) != GRP_ID_INVALID)
    {
        cui_mediaview_set_app_id(g_mediaview_cui_gid, g_imgview_context.app_id);
        cui_mediaview_set_browse_style(g_mediaview_cui_gid, CUI_MEDIAVIEW_STYLE_END);
        cui_mediaview_set_folder_path(g_mediaview_cui_gid, (CHAR*)buf_filepath);
        cui_mediaview_run(g_mediaview_cui_gid);
    }
    else
    {
        mmi_frm_group_close(temp_parent_gid);
        /*TODO: add trace*/
    }
    return g_mediaview_cui_gid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_enter_pre_check
 * DESCRIPTION
 *  Image view enter function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_imgview_enter_pre_check(MMI_ID app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID string_id = 0;
    mmi_event_notify_enum event_type = MMI_EVENT_DEFAULT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*) MMI_IMGVIEW_STORAGE_FILEPATH_PHONE))
        {
            string_id = mmi_usb_get_error_info(SRV_USB_ERROR_UNAVAILABLE, &event_type);
            /* g_mediaview_cui_gid is GRP_ID_INVALID */
            mmi_imgview_display_popup_sg(app_id, (UI_string_type)GetString(string_id), event_type, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP);
            return MMI_FALSE;
        }
        else
        {
            return MMI_TRUE;
        }
    }
    else
    {
        return MMI_TRUE;
    }
#else
    return MMI_TRUE;
#endif /* __USB_IN_NORMAL_MODE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_launch_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_imgview_launch_proc (mmi_event_struct *evt) {
	MMI_ID app_id =	GET_APP_ID(evt);
	switch (evt->evt_id)
	{
		case EVT_ID_APP_ENTER:
		{
            mmi_ivex_app_post_launch_event_struct event;
            MMI_FRM_INIT_EVENT(&event, 0);
            event.app_id = app_id;
            MMI_FRM_POST_EVENT(&event, mmi_imgview_launch_int, NULL);
			break;
		}

		case EVT_ID_APP_TOP_ACTIVE:
		{
			break;
		}

		case EVT_ID_APP_TOP_INACTIVE:
			break;

		case EVT_ID_APP_DEINIT:
			break;
	}
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_launch
 * DESCRIPTION
 *  image viewer entry point
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_launch(void) {
    if (mmi_frm_app_is_launched(APP_IMAGEVIEWER)) {
        mmi_frm_app_close(APP_IMAGEVIEWER);
    }
    mmi_frm_app_launch(APP_IMAGEVIEWER, 0, 0, mmi_imgview_launch_proc, NULL, MMI_FRM_APP_NORMAL_LAUNCH);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_launch_int
 * DESCRIPTION
 *  image viewer entry point
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_imgview_launch_int(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_imgview_enter_pre_check(((mmi_ivex_app_post_launch_event_struct*) evt)->app_id))
    {
        return MMI_RET_DONT_CARE;
    }
    g_imgview_context.is_view_app = MMI_TRUE;
    g_imgview_context.app_id = ((mmi_ivex_app_post_launch_event_struct*) evt)->app_id;
    mmi_imgview_group_create();
    return MMI_RET_DONT_CARE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_load_file_proc
 * DESCRIPTION
 *  image viewer load file proc
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_imgview_load_file_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_filelist_refresh_result_event_struct *evt = (srv_fmgr_filelist_refresh_result_event_struct*) param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() == SCR_ID_IMGVIEW_VIEW)
    {
        switch(param->evt_id) 
        {
            case EVT_ID_SRV_FMGR_FILELIST_LOAD_RESULT:
                {
                    g_imgview_context.is_refreshing = MMI_FALSE;
                    if (evt->result >= 0)
                    {
                        typedef void(*fun_ptr)(void);
                        ((fun_ptr)(evt->user_data))();
                    }
                    else
                    {
                        MMI_ID_TYPE error_str_id;
                        error_str_id = srv_fmgr_fs_error_get_string(evt->result);
                        mmi_imgview_display_popup_sg(g_imgview_cui_gid, (UI_string_type)GetString(error_str_id), 
                            (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(evt->result), 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);
                    }
                }
                break;

            default:
                break;
        }
    }

    return MMI_RET_OK;
}

#define MMI_MEDIAVIEW_CUI_APP
#ifdef __MMI_VUI_MEDIAWALL__
/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_malloc_med_memory
 * DESCRIPTION
 *  This function will malloc med memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void* mmi_mediaview_malloc_med_memory(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* malloc memory from media task */
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_MALLOC_LC);
    if (g_imgview_context.memory_info.med_mem_buf_p == NULL)
    {
        if(size > 0){
            g_imgview_context.memory_info.med_mem_buf_p = mmi_imgview_asm_alloc_debug(g_mediaview_cui_ptr->mediaview_cui_gid, size);
        }else{
            g_imgview_context.memory_info.med_mem_buf_p = NULL;
        }
        g_imgview_context.memory_info.med_mem_buf_size = size;
    }
    MMI_ASSERT(g_imgview_context.memory_info.med_mem_buf_p != NULL);
    return g_imgview_context.memory_info.med_mem_buf_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_free_med_memory
 * DESCRIPTION
 *  This function will free med memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mediaview_free_med_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* free memory used large image cache  from media task */
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_FREE_LC);
    if (g_imgview_context.memory_info.med_mem_buf_p != NULL)
    {
        mmi_imgview_asm_free_debug(g_mediaview_cui_ptr->mediaview_cui_gid, g_imgview_context.memory_info.med_mem_buf_p);
        g_imgview_context.memory_info.med_mem_buf_size = 0;
        g_imgview_context.memory_info.med_mem_buf_p = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_malloc_app_based_memory
 * DESCRIPTION
 *  allocate app based memory and create adm id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_mediaview_malloc_app_based_memory(U32 min_size, U32 max_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_CREATE_ADM);
    if (g_imgview_context.memory_info.app_mem_buf_p == NULL)
    {
        g_imgview_context.memory_info.app_mem_buf_p = mmi_imgview_asm_alloc_debug(g_mediaview_cui_ptr->mediaview_cui_gid, min_size);
        if (g_imgview_context.memory_info.app_mem_buf_p != NULL)
        {
            g_imgview_context.memory_info.app_mem_buf_size = min_size;
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_free_app_based_memory
 * DESCRIPTION
 *  free all app based memory of ivex view screen used
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mediaview_free_app_based_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_IVAPP_DESTROY_ADM);
    /* free asm */
    if (g_imgview_context.memory_info.app_mem_buf_p != NULL)
    {
        mmi_imgview_asm_free_debug(g_mediaview_cui_ptr->mediaview_cui_gid, g_imgview_context.memory_info.app_mem_buf_p);
        g_imgview_context.memory_info.app_mem_buf_p = NULL;
        g_imgview_context.memory_info.app_mem_buf_size = 0;
        applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_IVEX, KAL_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_vapp_mediawall_malloc_callback
 * DESCRIPTION
 *  free all app based memory of ivex view screen used
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mediaview_vapp_mediawall_malloc_callback(vadp_mediawall_memory_struct* mem_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mediaview_malloc_med_memory(MMI_IVEX_TOTAL_MED_MEM_POOL_SIZE);
    mem_info->app_mem_buf_p = g_imgview_context.memory_info.app_mem_buf_p;
    mem_info->app_mem_buf_size = g_imgview_context.memory_info.app_mem_buf_size;
    mem_info->med_mem_buf_p = g_imgview_context.memory_info.med_mem_buf_p;
    mem_info->med_mem_buf_size = g_imgview_context.memory_info.med_mem_buf_size;

    g_imgview_context.memory_info.is_vapp_used = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_vapp_mediawall_free_callback
 * DESCRIPTION
 *  free all app based memory of ivex view screen used
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mediaview_vapp_mediawall_free_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgview_context.memory_info.is_vapp_used)
    {
        mmi_mediaview_free_med_memory();
        g_imgview_context.memory_info.is_vapp_used = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_vapp_mediawall_is_terminate
 * DESCRIPTION
 *  free all app based memory of ivex view screen used
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_mediaview_vapp_mediawall_is_terminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_imgview_context.memory_info.is_vapp_used ? MMI_FALSE : MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_vapp_mediawall_is_caller
 * DESCRIPTION
 *  free all app based memory of ivex view screen used
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_mediaview_vapp_mediawall_is_caller(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_imgview_context.memory_info.is_vapp_call;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_vapp_mediawall_entry_prepare
 * DESCRIPTION
 *  free all app based memory of ivex view screen used
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_mediaview_vapp_mediawall_entry_prepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_success;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_success = mmi_mediaview_malloc_app_based_memory(MMI_IVEX_TOTAL_APP_BASED_MEM_POOL_SIZE, MMI_IVEX_MAX_APP_BASED_MEM_POOL_SIZE);
    if (!is_success)
    {
        return MMI_FALSE;
    }
    g_imgview_context.memory_info.is_vapp_call = MMI_TRUE;
    vapp_mediawall_set_direction(VADP_MEDIAWALL_PORTRAIT);
    vapp_mediawall_set_memory_notify_cb(mmi_mediaview_vapp_mediawall_malloc_callback, mmi_mediaview_vapp_mediawall_free_callback);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_get_app_based_memory_from_vapp_mediawall
 * DESCRIPTION
 *  free all app based memory of ivex view screen used
 * PARAMETERS
 *  size    :   [IN/OUT] buffer size
 * RETURNS
 *  void
 *****************************************************************************/
void* mmi_mediaview_get_app_based_memory_from_vapp_mediawall(U32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgview_context.memory_info.is_vapp_call &&
        (g_imgview_context.memory_info.app_mem_buf_p != NULL) &&
        (g_imgview_context.memory_info.app_mem_buf_size >= *size))
    {
        *size = g_imgview_context.memory_info.app_mem_buf_size;
        return g_imgview_context.memory_info.app_mem_buf_p;
    }
    else
    {
        MMI_ASSERT(0);
    }

    return NULL;
}


#endif
/*****************************************************************************
*
* View Style                                                             
*
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_get_view_style
 * DESCRIPTION
 *  set meidaview style
 * PARAMETERS
 *  void
 * RETURNS
 *  cui_fmgr_ui_style_enum   style
 *****************************************************************************/
cui_mediaview_style_enum mmi_mediaview_get_view_style(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nvrame_value;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_IMGVIEW_VIEW_SYTLE, &nvrame_value, DS_BYTE, &error);

    if (nvrame_value == 0xff)
    {
        nvrame_value = CUI_MEDIAVIEW_STYLE_MATRIX;
        WriteValue(NVRAM_IMGVIEW_VIEW_SYTLE, &nvrame_value, DS_BYTE, &error);
    }

    return (cui_mediaview_style_enum)nvrame_value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_set_view_style
 * DESCRIPTION
 *  set mediaview style
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mediaview_set_view_style(cui_mediaview_style_enum value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 nvram_value = (U8)value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_IMGVIEW_VIEW_SYTLE, &nvram_value, DS_BYTE, &error);
    /*mmi_imgview_display_popup_sg(g_mediaview_cui_gid, (UI_string_type)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE);*/

    /* FMGR_Revise */
    cui_folder_browser_set_ui_style(mmi_mediaview_get_browse_gid(), mmi_mediaview_transfer_style_view_to_fmgr(value));
#ifdef __MMI_VUI_MEDIAWALL__
    #if !(defined(MOTION_SENSOR_SUPPORT) && defined(__MTK_TARGET__))
    cui_folder_browser_set_option(mmi_mediaview_get_browse_gid(), CUI_FOLDER_BROWSER_OPT_USE_CSK_MASK, 
        (value == CUI_MEDIAVIEW_STYLE_MATRIX) ? CUI_FOLDER_BROWSER_OPT_USE_CSK_ON : CUI_FOLDER_BROWSER_OPT_USE_CSK_OFF);
    #endif
#endif/* __MMI_VUI_MEDIAWALL__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_transfer_style_view_to_fmgr
 * DESCRIPTION
 *  get related fmgr ui style from mediaview style
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
cui_fmgr_ui_style_enum mmi_mediaview_transfer_style_view_to_fmgr(cui_mediaview_style_enum value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fmgr_ui_style_enum ui_style;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (value == CUI_MEDIAVIEW_STYLE_LIST)
    {
        ui_style = CUI_FMGR_UI_STYLE_ICON_LIST;
    }
    else if (value == CUI_MEDIAVIEW_STYLE_MATRIX)
    {
        ui_style = CUI_FMGR_UI_STYLE_MATRIX;
    }
    else
    {
        ui_style = CUI_FMGR_UI_STYLE_MATRIX;
    }
    return ui_style;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_free_filelist
 * DESCRIPTION
 *  Free media view file list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mediaview_free_filelist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgview_fl_hdl && g_imgview_context.is_entry_browse)
    {
        if (cui_folder_browser_is_filelist_locked(mmi_mediaview_get_browse_gid()))
        {
            if(cui_folder_browser_unlock_filelist(g_imgview_context.fmgr_scr_id) < 0)
            {
                srv_fmgr_filelist_destroy(g_imgview_fl_hdl);
            }
        }
        g_imgview_fl_hdl = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_create_filelist
 * DESCRIPTION
 *  Create media view file list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_mediaview_create_filelist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_imgview_fl_hdl != 0) /*has created*/
    {
        /* should not enter here */
        ASSERT(0);
        return 0;
    }

    result = cui_folder_browser_lock_filelist((mmi_id)g_imgview_context.fmgr_scr_id, &g_imgview_fl_hdl, &g_imgview_fl_idx);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_set_curr_app_id
 * DESCRIPTION
 *  Set current run miediaview app id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mediaview_set_curr_app_id(U16 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgview_context.caller_app_id = app_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_get_curr_app_id
 * DESCRIPTION
 *  Get current run miediaview app id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_mediaview_get_curr_app_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_imgview_context.caller_app_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_screen_leave_proc
 * DESCRIPTION
 *  Media view screen leave proc.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_ret mmi_mediaview_screen_leave_proc(mmi_event_struct *evt)
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
        mmi_imgview_del_app_scr_callback(NULL);
        g_mediaview_cui_gid = GRP_ID_INVALID;
        g_imgview_context.is_view_app = MMI_FALSE;
        g_imgview_context.is_entry_browse = MMI_FALSE;
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_enter_pre_check
 * DESCRIPTION
 *  Media view enter function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_mediaview_enter_pre_check(mmi_id media_viewer_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID string_id = 0;
    mmi_event_notify_enum event_type = MMI_EVENT_DEFAULT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*)MMI_IMGVIEW_STORAGE_FILEPATH_PHONE))
        {
            string_id = mmi_usb_get_error_info(SRV_USB_ERROR_UNAVAILABLE, &event_type);
            /* g_mediaview_cui_gid is GRP_ID_INVALID */
            mmi_imgview_display_popup_sg(media_viewer_id, (UI_string_type)GetString(string_id), event_type, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP);
            return MMI_FALSE;
        }
        else
        {
            return MMI_TRUE;
        }
    }
    else
    {
        return MMI_TRUE;
    }
#else
    return MMI_TRUE;
#endif /* __USB_IN_NORMAL_MODE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_browse_cui_enter
 * DESCRIPTION
 *  Media view enter function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_mediaview_browse_cui_enter(mmi_id parent_gid, const WCHAR* folder_path, U16 opt_menu_id, U16 opt_empty_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    U32 option_flag;
    mmi_id browse_gid;
    cui_mediaview_style_enum value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Configure filter */
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_IMAGE(&filter);
#ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
    FMGR_FILTER_SET(&filter, FMGR_TYPE_MAV);
#endif
    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_ANM);
    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_EMS);
#if defined(__DRM_V02__)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
#endif

    /* Configure option flag */
    option_flag = 0;
#if defined(__FMGR_CSK_FORWARD__)
    option_flag |= CUI_FOLDER_BROWSER_OPT_FAST_FORWARD_ON;
#endif

    if ((browse_gid = cui_folder_browser_create(parent_gid, folder_path, &filter, option_flag, opt_menu_id, opt_empty_menu_id)) != GRP_ID_INVALID)
    {
        g_imgview_context.fmgr_scr_id = browse_gid;
        g_imgview_context.is_entry_browse = MMI_TRUE;
        value = mmi_mediaview_get_view_style();
        cui_folder_browser_set_title(browse_gid, STR_ID_IMGVIEW_NAME, GetRootTitleIcon(MENU_ID_IMGVIEW_APP));
        cui_folder_browser_set_ui_style(browse_gid, mmi_mediaview_transfer_style_view_to_fmgr(value));
    #ifdef __MMI_VUI_MEDIAWALL__
        #if !(defined(MOTION_SENSOR_SUPPORT) && defined(__MTK_TARGET__))
        cui_folder_browser_set_option(mmi_mediaview_get_browse_gid(), CUI_FOLDER_BROWSER_OPT_USE_CSK_MASK,
            (value == CUI_MEDIAVIEW_STYLE_MATRIX) ? CUI_FOLDER_BROWSER_OPT_USE_CSK_ON : CUI_FOLDER_BROWSER_OPT_USE_CSK_OFF);
        #endif
    #endif/* __MMI_VUI_MEDIAWALL__ */
        cui_folder_browser_run(browse_gid);
        return MMI_TRUE;
    }
    else
    {
        //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDIAVIEW_BROWSE_CUI_FAIL, parent_gid;
        mmi_mediaview_close_view_cui(&g_mediaview_cui_gid, EVT_ID_MEDIAVIEW_CLOSE_GID);
        return MMI_FALSE;
        /*TODO: add trace*/
    }

#if 0   //the code is never reached. but I'm not sure if it is necessary.
/* under construction !*/
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
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_browse_cui_enter_callback
 * DESCRIPTION
 *  Media view enter cb function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mediaview_browse_cui_enter_callback(mmi_id browse_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id view_browse_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    view_browse_gid = mmi_mediaview_get_browse_gid();

    if (view_browse_gid != browse_gid)
    {
        return;
    }
    mmi_imgview_set_rotate(0);
#ifdef __MMI_IMAGE_VIEWER_EX__
    mmi_ivex_reset_app();
#elif defined  __MMI_IMAGE_VIEWER_ADV__
    mmi_imgadv_reset_app();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_enter
 * DESCRIPTION
 *  Media view enter function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mediaview_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    S32 create_result;
    CHAR* error_string_ptr;
    S32 error_type= MMI_EVENT_FAILURE;
    MMI_BOOL entry_ret;
    mmi_imgview_popup_result_process_enum process;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_mediaview_enter_pre_check(g_mediaview_cui_gid))
    {
        return;
    }

    if (!mmi_frm_is_in_backward_scenario())
    {
        mmi_frm_group_enter(g_mediaview_cui_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }
    entry_ret = mmi_frm_scrn_enter(g_mediaview_cui_gid, SCR_ID_IMGVIEW_APP, NULL, mmi_mediaview_enter, MMI_FRM_FULL_SCRN);
    mmi_frm_scrn_set_leave_proc(g_mediaview_cui_gid, SCR_ID_IMGVIEW_APP, mmi_mediaview_screen_leave_proc);
    if (!entry_ret)
    {
        return;
    }

    /* check if there is small screen above IMAGEVIEWER */
    ShowCategoryDummySmallScreen();
    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        return;
    }

    if (FS_NO_ERROR == FS_GetDevStatus((U16)g_mediaview_cui_ptr->folder_path[0], FS_MOUNT_STATE_ENUM))
    {
        create_result = mmi_imgview_create_file_dir(g_mediaview_cui_ptr->folder_path);

        if (create_result < 0)
        {
            error_string_ptr = GetString(srv_fmgr_fs_error_get_string(create_result));
            error_type = srv_fmgr_fs_error_get_popup_type(create_result);
            process = MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE;
            goto entry_cui_error_handle;
        }
    }
    else
    {
        error_string_ptr = GetString(STR_ID_IMGVIEW_NOTIFY_NO_MEMORY_CARD);
        error_type = MMI_EVENT_FAILURE;
        process = MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP;
        goto entry_cui_error_handle;
    }

    /* reset imageviewr */
#ifdef __MMI_IMAGE_VIEWER_EX__
    mmi_ivex_reset_app();
#elif defined  __MMI_IMAGE_VIEWER_ADV__
    mmi_imgadv_reset_app();
#endif 

    /* check if it is valid path */
    file_handle = FS_Open((PU16)g_mediaview_cui_ptr->folder_path, FS_OPEN_DIR | FS_READ_ONLY);

    if (file_handle >= 0)
    {
        FS_Close(file_handle);
        mmi_mediaview_browse_cui_enter(g_mediaview_cui_gid,
                                                (WCHAR*)g_mediaview_cui_ptr->folder_path,
                                                MENU_ID_MEDIAVIEW_FILE_OPTION,
                                                MENU_ID_MEDIAVIEW_EMPTY_FOLDER_OPTION);
        return;
    }
    else
    {
        error_string_ptr = GetString(srv_fmgr_fs_error_get_string(file_handle));
        error_type = srv_fmgr_fs_error_get_popup_type(file_handle);
        process = MMI_IMGVIEW_POPUP_RESULT_PROCESS_NONE;
        goto entry_cui_error_handle;
    }

entry_cui_error_handle:

    mmi_imgview_display_popup_sg(g_mediaview_cui_gid, (UI_string_type)error_string_ptr, (mmi_event_notify_enum)error_type, 0, process);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_enter_from_cui
 * DESCRIPTION
 *  Enter media view cui group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mediaview_enter_from_cui(mmi_id media_viewer_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDIAVIEW_ENTER_FROM_CUI, media_viewer_id;
    if (!mmi_frm_is_in_backward_scenario())
    {
        /* First enter */
        g_mediaview_cui_gid = media_viewer_id;
        /* For multi-instance, it will get itself data */
        g_mediaview_cui_ptr = (cui_mediaview_context_struct*)mmi_frm_group_get_user_data(g_mediaview_cui_gid);
        if (g_mediaview_cui_gid != g_mediaview_cui_ptr->mediaview_cui_gid)
        {
            MMI_ASSERT(0);
        }
        if (g_mediaview_cui_ptr->view_style != CUI_MEDIAVIEW_STYLE_END)
        {
            mmi_mediaview_set_view_style(g_mediaview_cui_ptr->view_style);
        }
        mmi_mediaview_set_curr_app_id(g_mediaview_cui_ptr->parent_app_id);
        #ifdef __MMI_VUI_MEDIAWALL__
        if(mmi_mediaview_vapp_mediawall_entry_prepare() == MMI_FALSE)
        {
            mmi_frm_group_close(media_viewer_id);
            return;
        }
        #endif
    }
    if (g_imgview_context.is_view_app)
    {
        mmi_imgview_launch_app();
    }
    else
    {
        mmi_mediaview_enter();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_close_view_cui
 * DESCRIPTION
 *  Close view cui group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mediaview_close_view_cui(mmi_id *media_viewer_id, U16 evt_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_event_struct evt;
    mmi_group_node_struct group_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDIAVIEW_IVEX_CUI_CLOSE_BLOCK, *media_viewer_id;
    mmi_frm_group_get_info(*media_viewer_id, &group_info);

    if(group_info.state == MMI_SCENARIO_STATE_CREATE)
    {
        mmi_frm_group_close(*media_viewer_id);
    }
    else
    {
        evt.evt_id = evt_id;
        evt.sender_id = *media_viewer_id;
        evt.size = sizeof(mmi_group_event_struct);
        mmi_frm_group_post_to_parent(*media_viewer_id, &evt);
    }
    *media_viewer_id = GRP_ID_INVALID;
}


#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_create_file_dir
 * DESCRIPTION
 *  create directly from a file path (resursivly)
 * PARAMETERS
 *  filepath        [IN]        File path to create
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_imgview_create_file_dir(CHAR* filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_ret = 0;

    file_handle = FS_Open((kal_uint16*) filepath, FS_OPEN_DIR | FS_READ_ONLY);

    /* path already exist */
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
        return 0;   /* already exist , 0 measn success in FS */
    }
    else if (file_handle == FS_FAT_ALLOC_ERROR)
    {
        fs_ret = FS_FAT_ALLOC_ERROR;
        return fs_ret;
    }

#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

    /* create directory if it is not there */
    fs_ret = FS_CreateDir((PU16) filepath);

    if (fs_ret < 0)
    {
        return fs_ret;
    }

    return fs_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_restore_setting
 * DESCRIPTION
 *  restore setting
 * PARAMETERS
 *  void
 * RETURNS
 *  nil
 *****************************************************************************/
void mmi_imgview_restore_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U16 storage = (U16)SRV_FMGR_PUBLIC_DRV;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgview_context.storage = storage;
    WriteValue(NVRAM_IMGVIEW_STORAGE, &g_imgview_context.storage, DS_SHORT, &error);

/* for MAUI_02318123 BEGIN ***************************************************/
#ifdef __MMI_CAMCORDER__
    if(mmi_camco_get_storage() != storage)
    {
        mmi_camco_set_storage(storage);
    }
#ifdef __MMI_VIDEO_PLAYER__
    if(mmi_vdoply_get_storage() != storage)
    {
        mmi_vdoply_set_storage(storage);
    }
#endif
#endif
    /* for MAUI_02318123 END *****************************************************/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_load_setting
 * DESCRIPTION
 *  load setting
 * PARAMETERS
 *  void
 * RETURNS
 *  S32(?)
 *****************************************************************************/
void mmi_imgview_load_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* load format setting */
    ReadValue(NVRAM_IMGVIEW_STORAGE, &g_imgview_context.storage, DS_SHORT, &error);

    /* init if needed */
    if (g_imgview_context.storage == 0xffff)
    {
        g_imgview_context.storage = (U16)SRV_FMGR_PUBLIC_DRV;
    }
}


#if defined(__DRM_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_get_drm_result
 * DESCRIPTION
 *  get last time drm result
 * PARAMETERS
 *  void
 * RETURNS
 *  U16  MMI_IMGVIEW_OK/MMI_IMGVIEW_ERROR/MMI_IMGVIEW_ERRTYPE_DRM_INVALID
 *****************************************************************************/
S32 mmi_imgview_get_drm_result(void)
{
    return g_imgview_context.result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_start_consume
 * DESCRIPTION
 *  TO call DRM_consume_rights.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_start_consume(void)
{
    if (g_imgview_context.drm_handle != NULL)
    {
        g_imgview_context.drm_id = 
            DRM_consume_rights(g_imgview_context.drm_handle, DRM_PERMISSION_DISPLAY, mmi_imgview_drm_callback_hdlr);
        MMI_IMGVIEW_DRM_ENTER_STATE(IMGVIEW_DRM_STATE_CONSUME);

        DRM_close_file(g_imgview_context.drm_handle);
        g_imgview_context.drm_handle = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_consume_drm_if_need
 * DESCRIPTION
 *  TO actually consume drm right
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_consume_drm_if_need(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_FMGR_VIEWER_CONSUME_DRM_IF_NEED,g_imgview_context.drm_state,g_imgview_context.drm_id);
    if ((g_imgview_context.drm_state == IMGVIEW_DRM_STATE_CONSUME) || (g_imgview_context.drm_state == IMGVIEW_DRM_STATE_PAUSE))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_FMGR_VIEWER_CONSUME_DRM,g_imgview_context.drm_state,g_imgview_context.drm_id);
        DRM_stop_consume(g_imgview_context.drm_id);
        g_imgview_context.drm_id = 0;
        MMI_IMGVIEW_DRM_ENTER_STATE(IMGVIEW_DRM_STATE_EXIT);
    }
    /* add for non blocking decode */
    #if defined(__MMI_IMGVIEW_NONBLOCKING_DECODE__)
    else if (g_imgview_context.drm_state == IMGVIEW_DRM_STATE_EXIT && g_imgview_context.drm_handle != NULL)
    {
        DRM_close_file(g_imgview_context.drm_handle);
        g_imgview_context.drm_handle = NULL;
    }
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_preprocess_drm_right
 * DESCRIPTION
 *  pre-process DRM right
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgview_preprocess_drm_right(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_FMGR_VIEWER_RESUME,g_imgview_context.drm_state,g_imgview_context.drm_id,__LINE__);

    if (g_imgview_context.drm_state == IMGVIEW_DRM_STATE_EXIT)
    {
        g_imgview_context.drm_valid = mmi_imgview_process_drm_hdlr();
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_IMGVIEW_DRM_VALID, g_imgview_context.drm_valid, __LINE__);

        /* ERROR HAPPENED */
        if ((g_imgview_context.drm_valid & IMGVIEW_DRM_DRM_FILE)==0)
        {
            g_imgview_context.result = MMI_IMGVIEW_OK;
        }
        else if (((IMGVIEW_DRM_MULTI_PART & g_imgview_context.drm_valid)!=0))
        {
            /* MULTI-PART */
            g_imgview_context.result = MMI_IMGVIEW_ERRTYPE_DRM_MULTIPART; 
        }
        else if ((IMGVIEW_DRM_DISPLAY_VALID & g_imgview_context.drm_valid)==0)
        {
            /* DISPLAY PERMISSIONT DENINED */
            g_imgview_context.result = MMI_IMGVIEW_ERRTYPE_DRM_INVALID; 
        }
        else 
            g_imgview_context.result = MMI_IMGVIEW_OK;
    }
    else if (g_imgview_context.drm_state == IMGVIEW_DRM_STATE_PAUSE)
    {
        /* check print right again */
        if (DRM_get_object_method(NULL,(PU16) g_imgview_context.filepath) != DRM_METHOD_NONE)
        {
            if (!DRM_validate_permission(NULL, (PU16)g_imgview_context.filepath, DRM_PERMISSION_PRINT))
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_IMGVIEW_DRM_PRINT_INVALID,__LINE__);    
                g_imgview_context.drm_valid &= ~(IMGVIEW_DRM_PRINT_VALID);
            }
        }            

        /* if DRM State in PAUSE, Consume DRM Right */
        DRM_resume_consume(g_imgview_context.drm_id);
        g_imgview_context.result = MMI_IMGVIEW_OK;
        MMI_IMGVIEW_DRM_ENTER_STATE(IMGVIEW_DRM_STATE_CONSUME);

        DRM_close_file(g_imgview_context.drm_handle);
        g_imgview_context.drm_handle = NULL;
    }
    else
    {
        /* should not go into this section */
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_drm_callback_hdlr
 * DESCRIPTION
 *  drm right timeout hdlr
 * PARAMETERS
 *  S32  result
 *  S32  id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgview_drm_callback_hdlr(kal_int32 result, kal_int32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*****************************************************************
     * TIME OUT
     * ---------------------------------------------------------------
     * show popup and draw black bg on panel 
     *****************************************************************/
    active_screen_id = mmi_frm_scrn_get_active_id();
     
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_FMGR_VIEWER_DRM_CALLBACK_HDLR,g_imgview_context.drm_state,g_imgview_context.drm_id);
    if (active_screen_id  == SCR_ID_IMGVIEW_VIEW ||active_screen_id == SCR_ID_IMGVIEW_FROM_FMGR)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_FMGR_VIEWER_DRM_CALLBACK_IN_APP);

        if (g_imgview_context.drm_state == IMGVIEW_DRM_STATE_CONSUME || g_imgview_context.drm_state == IMGVIEW_DRM_STATE_PAUSE)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_FMGR_VIEWER_CONSUME_DRM,g_imgview_context.drm_state,g_imgview_context.drm_id);
            DRM_stop_consume(g_imgview_context.drm_id);
            g_imgview_context.drm_id = 0;
            MMI_IMGVIEW_DRM_ENTER_STATE(IMGVIEW_DRM_STATE_EXIT);
        }
        
        g_imgview_context.result = MMI_IMGVIEW_ERRTYPE_DRM_INVALID; 
        g_imgview_context.err_str_ptr = STR_GLOBAL_DRM_PROHIBITED;
        mmi_imgview_display_popup_sg(g_imgview_cui_gid, (UI_string_type)GetString(STR_GLOBAL_DRM_PROHIBITED), MMI_EVENT_FAILURE, 0, MMI_IMGVIEW_POPUP_RESULT_PROCESS_DELETE_GROUP);
    }
    else if (mmi_frm_scrn_is_present(g_imgview_cui_gid, SCR_ID_IMGVIEW_VIEW, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG) || mmi_frm_scrn_is_present(g_imgview_cui_gid, SCR_ID_IMGVIEW_FROM_FMGR, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_FMGR_VIEWER_DRM_CALLBACK_IN_HISTORY);
        if (g_imgview_context.drm_state == IMGVIEW_DRM_STATE_CONSUME || g_imgview_context.drm_state == IMGVIEW_DRM_STATE_PAUSE)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_FMGR_VIEWER_CONSUME_DRM,g_imgview_context.drm_state,g_imgview_context.drm_id);
            DRM_stop_consume(g_imgview_context.drm_id);
            g_imgview_context.drm_id = 0;
            MMI_IMGVIEW_DRM_ENTER_STATE(IMGVIEW_DRM_STATE_EXIT);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_process_drm_hdlr
 * DESCRIPTION
 *  This function check DRM right of the file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static imgview_drm_ret_enum mmi_imgview_process_drm_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    imgview_drm_ret_enum         ret = IMGVIEW_DRM_NOT_DRM_FILE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check multipart or single part first */
#ifdef __DRM_V02__    
    if (srv_fmgr_types_find_type_by_filepath((WCHAR*)g_imgview_context.filepath) == FMGR_TYPE_ODF)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_IMGVIEW_MULTIPART_ODF,__LINE__);
        ret = IMGVIEW_DRM_DRM_FILE;
        ret |= IMGVIEW_DRM_MULTI_PART;       
    }
    else
#endif
    {
        if ((g_imgview_context.drm_handle = DRM_open_file((PU16) g_imgview_context.filepath, FS_READ_ONLY, DRM_PERMISSION_DISPLAY)) >= FS_NO_ERROR)
        {
            if (DRM_get_object_method(g_imgview_context.drm_handle, NULL) == DRM_METHOD_NONE)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_IMGVIEW_NOT_DRM_FILE,g_imgview_context.drm_handle,__LINE__);
                ret = IMGVIEW_DRM_NOT_DRM_FILE;
                DRM_close_file(g_imgview_context.drm_handle);
                g_imgview_context.drm_handle = NULL;
                ret |= IMGVIEW_DRM_PRINT_VALID;
                return ret;
            }

            ret = IMGVIEW_DRM_DRM_FILE;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_IMGVIEW_DRM_FILE,g_imgview_context.drm_handle,__LINE__);

            if (DRM_validate_permission(NULL, (kal_wchar *)g_imgview_context.filepath, DRM_PERMISSION_DISPLAY))
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_IMGVIEW_DRM_DISPLAY_VALID,__LINE__);
                ret |= IMGVIEW_DRM_DISPLAY_VALID;    
                
                if (DRM_validate_permission(NULL, (kal_wchar *)g_imgview_context.filepath, DRM_PERMISSION_PRINT))
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_IMGVIEW_DRM_PRINT_VALID,__LINE__);
                    ret |= IMGVIEW_DRM_PRINT_VALID;
                }
            }
            else
            {
               MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_IMGVIEW_NO_PERMISSION,g_imgview_context.drm_handle,__LINE__);
               DRM_close_file(g_imgview_context.drm_handle);
               g_imgview_context.drm_handle = NULL;
            }
        }
        else if (g_imgview_context.drm_handle  == DRM_RESULT_NO_PERMISSION)  /* file open error but not DRM related problem */
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_IMGVIEW_NO_PERMISSION,g_imgview_context.drm_handle,__LINE__);
            g_imgview_context.drm_handle = NULL;
        }
        else if (g_imgview_context.drm_handle  <= -1)  /* file open error but not DRM related problem */
        {
            /* NOT DRM FILE */
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_IMGVIEW_NOT_DRM_FILE,g_imgview_context.drm_handle,__LINE__);
            ret = IMGVIEW_DRM_NOT_DRM_FILE;
            g_imgview_context.drm_handle = NULL;
        }
    }
    return ret;    
}
#endif /* defined(__DRM_SUPPORT__) */


static MMI_ID_TYPE mmi_imgview_get_error_string_by_error_enum(S32 err_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE string_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (err_code)
    {
        case GDI_JPEG_ERR_IMAGE_TOO_LARGE:
#ifdef __PLUTO_MMI_PACKAGE__
            string_id = STR_ID_FMGR_FILE_LIMIT_IMAGE_TOO_LARGE;
#endif
            break;
        case GDI_JPEG_ERR_DECODE_TIME_OUT:
#ifdef __PLUTO_MMI_PACKAGE__            
            string_id = STR_ID_FMGR_SYSTEM_BUSY_TO_DECODE;
#endif
            break;
        case GDI_IMAGE_ERR_INVALID_IMG_TYPE:
            string_id = STR_GLOBAL_INVALID_FORMAT;
            break;
        case GDI_IMAGE_ERR_UNSUPPORTED_FORMAT:
            string_id = STR_GLOBAL_UNSUPPORTED_FORMAT;
            break;
        default:
            string_id = STR_GLOBAL_INVALID_FORMAT;
            break;
    }

    return string_id;
}

S32 mmi_imgview_set_storage(U16 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR buf_filepath[SRV_FMGR_PATH_BUFFER_SIZE];
    S16 error;
    S32 ret = FS_NO_ERROR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgview_context.storage != storage)
    {
        g_imgview_context.storage = storage;
        WriteValue(NVRAM_IMGVIEW_STORAGE, &g_imgview_context.storage, DS_SHORT, &error);    
        ret = mmi_imgview_get_storage_file_path((WCHAR*)buf_filepath);
        if(ret < 0 )
            return ret;
            
        if (g_imgview_context.is_entry_browse)
        {
            cui_mediaview_set_folder_path(g_mediaview_cui_gid, (CHAR*)buf_filepath);
            cui_folder_browser_set_folder_path(g_imgview_context.fmgr_scr_id, (WCHAR*)buf_filepath);
        }

    /* for MAUI_02318123 BEGIN ***************************************************/
    #ifdef __MMI_CAMCORDER__
        if(mmi_camco_get_storage() != storage)
        {
            mmi_camco_set_storage(storage);
        }
    #ifdef __MMI_VIDEO_PLAYER__
        if(mmi_vdoply_get_storage() != storage)
        {
            mmi_vdoply_set_storage(storage);
        }
    #endif
    #endif
    /* for MAUI_02318123 END *****************************************************/
    }
    
    return ret;
}


U16 mmi_imgview_get_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_imgview_context.storage;
}


void mmi_imgview_set_storage_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_imgview_context.is_storage_ready = MMI_TRUE;
}


void mmi_imgview_set_storage_not_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_imgview_context.is_storage_ready = MMI_FALSE;
}


BOOL mmi_imgview_is_storage_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_imgview_context.is_storage_ready;    
}


void mmi_imgview_set_rotate(U16 rotate_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_imgview_context.imgview_rotate = rotate_value;
}


U16 mmi_imgview_get_rotate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_imgview_context.imgview_rotate;
}


S32 mmi_imgview_get_highlight_idx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_imgview_fl_idx;
}


#if defined(__MMI_SLIDESHOW__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_entry_slideshow
 * DESCRIPTION
 *  entry slideshow application from imageviewer/filemanager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern U16 mmi_fmgri_fsdata_get_sort_option(void);
void mmi_imgview_entry_slideshow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const WCHAR *filepath_p;
    srv_fmgr_fileinfo_struct info;
    U16 sort_type;
    S32 fl_idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /**** Get File Info ****/
    filepath_p = srv_fmgr_types_query_fileinfo(&info);
    sort_type = mmi_fmgri_fsdata_get_sort_option();
    fl_idx = cui_folder_browser_get_highlight_index(mmi_mediaview_get_browse_gid());
    /* entry slideshow */
    mmi_slideshow_entry_from_other_app((CHAR*)filepath_p,fl_idx,MMI_SLIDESHOW_BROWSE_TYPE_IMAGE, sort_type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_highlight_entry_slideshow
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_highlight_entry_slideshow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imgview_entry_slideshow, KEY_EVENT_UP);
}
#endif /* __MMI_SLIDESHOW__ */


#if defined(__MMI_PHOTOEDITOR__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_entry_photoeditor
 * DESCRIPTION
 *  entry slideshow application from imageviewer/filemanager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_entry_photoeditor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const WCHAR *filepath_p;
    srv_fmgr_fileinfo_struct info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /**** Get File Info ****/
    filepath_p = srv_fmgr_types_query_fileinfo(&info);
    /* entry photoeditor */
    mmi_phoedt_entry_from_fmgr((WCHAR*)filepath_p);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_highlight_entry_photoeditor
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_highlight_entry_photoeditor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imgview_entry_photoeditor, KEY_EVENT_UP);
}
#endif /* __MMI_PHOTOEDITOR__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_get_browse_gid
 * DESCRIPTION
 *  Get browse group id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_id mmi_mediaview_get_browse_gid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgview_context.is_entry_browse == MMI_TRUE)
    {
        return g_imgview_context.fmgr_scr_id;
    }
    else
    {
        return GRP_ID_INVALID;
    }
    }


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_reset_browse_gid
 * DESCRIPTION
 *  Get browse group id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mediaview_reset_browse_gid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgview_context.fmgr_scr_id = GRP_ID_INVALID;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_check_printable
 * DESCRIPTION
 *  Get browse group id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_mediaview_check_printable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BPP_SUPPORT__) || defined(__MMI_PICT_BRIDGE_SUPPORT__)
    /* PRINT 
     *  
     */
    mmi_frm_unhide_child_menu_items(MENU_ID_FMGR_IMG_OPTION_PRINT);
    //mmi_fmgr_option_img_print_enabler(MENU_ID_FMGR_IMG_OPTION_PRINT, fileinfo);
    if(0 == GetNumOfChild_Ext(MENU_ID_FMGR_IMG_OPTION_PRINT))
    {
        mmi_frm_hide_menu_item(MENU_ID_FMGR_IMG_OPTION_PRINT);
    }
#endif
    return MMI_TRUE;
}


#define MMI_IMGVIEW_CUI_APP
/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_lsk_custmize_confirmed
 * DESCRIPTION
 *  Left softkey pressed to confirm the operation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_lsk_custmize_confirmed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_event_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VIEW_ADV_CUI_LSK_CONFIRM, g_imgadv_cui_gid;
    evt.evt_id = EVT_ID_IMGVIEW_FILE_SELECT;
    evt.sender_id = g_imgview_cui_gid;
    evt.size = sizeof(mmi_group_event_struct);
    mmi_frm_group_post_to_parent(g_imgview_cui_gid, &evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_set_fl_and_start_idx
 * DESCRIPTION
 *  Set filelist and start index for APP runing
 * PARAMETERS
 *  filelist           :   [IN] caller filelist.
 *  start_index        :   [IN] start index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_set_fl_and_start_idx(SRV_FMGR_FILELIST_HANDLE filelist, U32 start_index, U32 total_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VIEW_FL_IDX,g_imgview_fl_hdl,g_imgview_fl_idx,filelist,start_index);
    g_imgview_fl_hdl = filelist;
    g_imgview_fl_idx = start_index;
}


#define MMI_IMGVIEW_CUI
extern void cui_imgview_set_filelist_config_fun(mmi_id image_viewer_id, void(*filelist_config)(SRV_FMGR_FILELIST_HANDLE filelist, U32 start_index, U32 total_count));
extern void cui_imgview_set_enter_view_fun(mmi_id image_viewer_id, void(*enter_view_screen)(void));
extern void cui_imgview_enter_before_play(mmi_id image_viewer_id);
/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_app_reset
 * DESCRIPTION
 *  Reset app variable
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_app_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgview_cui_gid = GRP_ID_INVALID;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mediaview_app_reset
 * DESCRIPTION
 *  Reset app variable
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mediaview_app_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mediaview_cui_gid = GRP_ID_INVALID;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_enter_view_from_cui
 * DESCRIPTION
 *  View entrance for cui
 * PARAMETERS
 *  image_viewer_id  :   [IN]  Image view group id.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_enter_view_from_cui(mmi_id image_viewer_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 total_count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgview_cui_gid = image_viewer_id;
    /* For multi-instance, it will get itself data */
    g_imgview_cui_ptr = (cui_imgview_context_struct*)mmi_frm_group_get_user_data(g_imgview_cui_gid);
    
    if (g_imgview_cui_gid != g_imgview_cui_ptr->imgview_cui_gid)
    {
        MMI_ASSERT(0);
    }

    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VIEW_FROM_CUI,g_imgadv_cui_gid,g_imgview_cui_ptr->view_mode.viewmode);
    switch (g_imgview_cui_ptr->view_mode.viewmode)
    {
        case CUI_IMGVIEW_VIEWMODE_FILENAME:
            mmi_imgview_view_one_image();
            break;
        case CUI_IMGVIEW_VIEWMODE_PREFETCH:
            break;
        case CUI_IMGVIEW_VIEWMODE_FILELIST:
            total_count = srv_fmgr_filelist_count(g_imgview_cui_ptr->view_mode.filelist);
            mmi_imgview_set_fl_and_start_idx(g_imgview_cui_ptr->view_mode.filelist, g_imgview_cui_ptr->view_mode.start_index, total_count);
            mmi_imgview_entry_view_detail_screen();
            break;
        case CUI_IMGVIEW_VIEWMODE_FILENAME_ARRAY:
            break;
        case CUI_IMGVIEW_VIEWMODE_IMAGEID_ARRAY:
            break;
        case CUI_IMGVIEW_VIEWMODE_FOLDER:
            break;
        default:
            MMI_ASSERT(0);
            break;
    }
}


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
extern void mmi_imgview_sap_send_msg(module_type src, module_type dst, U32 msg_id, void *local_param_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_send5(src, dst, MMI_MMI_SAP, (msg_type)msg_id, (local_para_struct*)local_param_ptr);
}

/*
 * simple app
 */

#define APP_IMAGEVIEWER_SIMPLE (APP_IMAGEVIEWER)
typedef struct {
    MMI_ID app_id;
    WCHAR file_path[SRV_FMGR_PATH_BUFFER_SIZE];
    U16 string;
    U16 icon;
} mmi_imageviewer_simple_app_context;

static mmi_imageviewer_simple_app_context g_simple_app_context;

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_image_view_group_proc
 * DESCRIPTION
 *  FMGR image view process
 * PARAMETERS
 *  evt      : [OUT] event pointer
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_fmgr_image_view_simple_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_ENTER:
        /* enter group ToDo1 */
            break;
        case EVT_ID_GROUP_ACTIVE:
        /* enter group ToDo2 */
            break;
        case EVT_ID_GROUP_FOCUSED:
        /* enter group ToDo3 */
            break;
        case EVT_ID_GROUP_GOBACK:
        /* gobackhistory ToDo1 */
            break;
        case EVT_ID_GROUP_INACTIVE:
        /* gobackhistory ToDo2 */
            break;
        case EVT_ID_GROUP_EXIT:
        /* gobackhistory ToDo3 */
            break;
        case EVT_ID_GROUP_DEINIT:
        /* gobackhistory ToDo4 */
            break;
        case EVT_ID_IMGVIEW_CLOSE_GID:
        /* closegroup ToDo1 */
        {
            mmi_group_event_struct *cui_evt = (mmi_group_event_struct*)evt;
            cui_imgview_close(cui_evt->sender_id);
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
}


static mmi_ret mmi_imgview_simple_launch_int(mmi_event_struct *evt)
{
    mmi_id temp_parent_gid;
    mmi_id imgview_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_parent_gid = mmi_frm_group_create(g_simple_app_context.app_id, GRP_ID_AUTO_GEN, mmi_fmgr_image_view_simple_group_proc, NULL); 
    mmi_frm_group_enter(temp_parent_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    if ((imgview_gid = cui_imgview_create(temp_parent_gid)) != GRP_ID_INVALID)
    {
        cui_imgview_set_mode_filename(imgview_gid, (CHAR *) g_simple_app_context.file_path);
        cui_imgview_set_app_id(imgview_gid, g_simple_app_context.app_id);
        cui_imgview_set_title(imgview_gid, NULL, g_simple_app_context.icon);
        cui_imgview_set_ui_direction(imgview_gid, CUI_IMGVIEW_UI_DIRECTION_VERTICAL);
        cui_imgview_set_display_cap(imgview_gid, CUI_IMGVIEW_CAP_ALL, MMI_TRUE);
        cui_imgview_set_display_cap(imgview_gid, CUI_IMGVIEW_CAP_COUNTER, MMI_FALSE);   
        cui_imgview_set_display_cap(imgview_gid, CUI_IMGVIEW_CAP_SLIDESHOW, MMI_FALSE);   
        cui_imgview_set_display_cap(imgview_gid, CUI_IMGVIEW_CAP_TITLE, MMI_FALSE);   
        cui_imgview_set_display_cap(imgview_gid, CUI_IMGVIEW_CAP_DB, MMI_FALSE);   
        cui_imgview_run(imgview_gid);
    }
    else
    {
        mmi_frm_group_close(temp_parent_gid);
    }

    return MMI_RET_DONT_CARE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_simple_launch_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_imgview_simple_launch_proc (mmi_event_struct *evt) {
	MMI_ID app_id =	GET_APP_ID(evt);
	switch (evt->evt_id)
	{
		case EVT_ID_APP_ENTER:
		{
            mmi_ivex_app_post_launch_event_struct event;
            MMI_FRM_INIT_EVENT(&event, 0);
            event.app_id = app_id;
            MMI_FRM_POST_EVENT(&event, mmi_imgview_simple_launch_int, NULL);
			break;
		}

		case EVT_ID_APP_TOP_ACTIVE:
		{
			break;
		}

		case EVT_ID_APP_TOP_INACTIVE:
			break;

		case EVT_ID_APP_DEINIT:
			break;
	}
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_launch
 * DESCRIPTION
 *  image viewer entry point
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_simple_launch(PS8 file_path, U16 string, U16 icon) {
    if (mmi_frm_app_is_launched(APP_IMAGEVIEWER_SIMPLE)) {
        mmi_frm_app_close(APP_IMAGEVIEWER_SIMPLE);
    }
    g_simple_app_context.app_id = APP_IMAGEVIEWER_SIMPLE;
    g_simple_app_context.string = string;
    g_simple_app_context.icon = icon;
    mmi_ucs2cpy((CHAR*) g_simple_app_context.file_path, (CHAR*) file_path);
    mmi_frm_app_launch(APP_IMAGEVIEWER_SIMPLE, 0, 0, mmi_imgview_simple_launch_proc, NULL, MMI_FRM_APP_NORMAL_LAUNCH);
}


#endif /* __MMI_IMAGE_VIEWER__ */ 

