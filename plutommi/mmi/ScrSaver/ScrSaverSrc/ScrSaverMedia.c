/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  ScrSaverMedia.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the media screen saver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_SCREEN_SAVER__)
#include "WPSSProtos.h"
#include "DRM_gprot.h"
#include "mdi_datatype.h"
#include "FileMgrGprot.h"
#include "FileMgrSrvGProt.h"
#include "drm_errcode.h"
#include "MMIDataType.h"
#include "mmi_phnset_dispchar.h"
#include "mmi_rp_file_type_def.h"
#include "kal_general_types.h"
#include "fs_type.h"
#include "AlertScreen.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "mmi_frm_events_gprot.h"
#include "drm_def.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "ScrSaverMedia.h"
#include "fs_errcode.h"
#include "wgui_categories_multimedia.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories.h"
#include "gdi_include.h"
#include "ScrSaverObject.h"
#include "FileMgrType.h"
#include "mmi_rp_app_scr_saver_def.h"
#include "wgui_categories_list.h"
#include "ScrSaverGprot.h"
#include "ScrSaverMain.h"
#include "mdi_include.h"

/****************************************************************************
 * Global context
 ****************************************************************************/

#if defined(__DRM_SUPPORT__)
/*
 * Singleton only because DRM callback does not support user_data.
 */
static S32 g_mmi_ssv_media_consumer = DRM_RESULT_INVALID;
#endif /* defined(__DRM_SUPPORT__) */


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_media_convert_type_to_fmgr
 * DESCRIPTION
 *  This function converts the type from phone setting to the file manager.
 * PARAMETERS
 *  type            : [IN]          Type of phone setting
 * RETURNS
 *  Type of file manager.
 *****************************************************************************/
static U16 mmi_ssv_media_convert_type_to_fmgr(U16 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case PHNSET_TYPE_DISP_IMAGE:
            return FMGR_GROUP_IMAGE;
            break;

        case PHNSET_TYPE_DISP_VIDEO:
            return FMGR_GROUP_VIDEO;
            break;

        default:
            break;
    }

    return FMGR_GROUP_UNKNOWN;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_media_get_setting
 * DESCRIPTION
 *  This function gets the setting of the screen saver.
 * PARAMETERS
 *  res_type            : [IN]      Resource type
 *  res_id              : [IN]      Resource id
 *  res_filename        : [IN]      Resource filename
 * RETURNS
 *  On success, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_ssv_media_get_setting(
    U16 *res_type,
    U16 *res_id,
    PS8 *res_filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 id, type;
    PS8 filename;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PhnsetGetCurScrSvr(&id);

    switch (id)
    {
        case 0xFF:
            return MMI_FALSE;
            break;

    #if defined(__MMI_FILE_MANAGER__)
        case 0x00:
        case 0x01:
            id = 0x00;

            filename = PhnsetGetCurScrSvrFileName();
            type = srv_fmgr_types_find_group_by_filename_str((WCHAR*)filename);
            break;
    #endif /* defined(__MMI_FILE_MANAGER__) */

        default:
            filename = NULL;
            type = PhnsetGetDisplayType(id);
            type = mmi_ssv_media_convert_type_to_fmgr(type);
            break;
    }

    if (res_type)
    {
        *res_type = type;
    }

    if (res_id)
    {
        *res_id = id;
    }

    if (res_filename)
    {
        *res_filename = filename;
    }

    return MMI_TRUE;
}


#if defined(__MMI_FILE_MANAGER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_media_display_file_error
 * DESCRIPTION
 *  This function displays the file error popup.
 * PARAMETERS
 *  is_prohibited       : [IN]      Is prohibited by DRM
 *  fs_handle           : [IN]      File handle
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ssv_media_display_file_error(
                MMI_BOOL is_prohibited,
                FS_HANDLE fs_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PhnsetRstScrSvrDefault();

    if (is_prohibited)
    {
        mmi_popup_display_simple(
            (WCHAR *)get_string(STR_GLOBAL_DRM_PROHIBITED),
            MMI_EVENT_FAILURE,
            GRP_ID_ROOT,
            NULL);
    }
    else
    {
        mmi_popup_display_simple(
            (WCHAR *)get_string(srv_fmgr_fs_error_get_string(fs_handle)),
            MMI_EVENT_FAILURE,
            GRP_ID_ROOT,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_media_stop_drm_right
 * DESCRIPTION
 *  This function stops DRM right.
 * PARAMETERS
 *  result          : [IN]          Result
 *  id              : [IN]          Id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ssv_media_stop_drm_right(S32 result, S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__DRM_SUPPORT__)
    if (g_mmi_ssv_media_consumer >= DRM_RESULT_OK)
    {
        DRM_stop_consume(g_mmi_ssv_media_consumer);
        g_mmi_ssv_media_consumer = DRM_RESULT_INVALID;
    }
#endif /* defined(__DRM_SUPPORT__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_media_get_permission
 * DESCRIPTION
 *  This function gets the permission.
 * PARAMETERS
 *  type            : [IN]      Type of resource
 * RETURNS
 *  Permission.
 *****************************************************************************/
static U8 mmi_ssv_media_get_permission(U16 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 permission = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case FMGR_GROUP_IMAGE:
            permission = DRM_PERMISSION_DISPLAY;
            break;

        case FMGR_GROUP_VIDEO:
            permission = DRM_PERMISSION_PLAY;
            break;

        default:
            MMI_ASSERT(0);
            break;
    }

    return permission;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_media_check_file
 * DESCRIPTION
 *  This function checks if it is ok to play the media file.
 * PARAMETERS
 *  obj                 : [IN]          Object
 *  fs_handle           : [OUT]         File handle
 *  is_prohibited       : [OUT]         Is prohibited by DRM
 * RETURNS
 *  On ok, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_ssv_media_check_file(
    mmi_ssv_media_struct *obj,
    FS_HANDLE *fs_handle,
    MMI_BOOL *is_prohibited)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 permission;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(fs_handle && is_prohibited);

    *is_prohibited = MMI_FALSE;

    /*
     * Check if file can be opened.
     */
    permission = mmi_ssv_media_get_permission(obj->res_type);

    *fs_handle = DRM_open_file(
                    (kal_wchar *)obj->res_filename,
                    FS_READ_ONLY,
                    permission);

    if (*fs_handle < FS_NO_ERROR)
    {
        return MMI_FALSE;
    }

#if defined(__DRM_SUPPORT__)
    /*
     * Check if DRM right is granted.
     */
    if (!DRM_validate_forward_rule(*fs_handle, permission))
    {
        *is_prohibited = MMI_TRUE;
        DRM_close_file(*fs_handle);

        return MMI_FALSE;
    }

    /*
     * Success. Can consume the DRM right.
     */
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
    if (obj->res_type == FMGR_GROUP_VIDEO)
    {
        wgui_catvdo_set_drm_flag(WGUI_CATVDO_DRM_DISABLE_CONSUME_TIME_LIMIT_STOP);
    }
    else
#endif /* defined(__MMI_VIDEO_PLAY_SUPPORT__) */
    {
        g_mmi_ssv_media_consumer = DRM_consume_rights(
                                    *fs_handle,
                                    permission,
                                    mmi_ssv_media_stop_drm_right);
    }
#endif /* defined(__DRM_SUPPORT__) */

    DRM_close_file(*fs_handle);

    return MMI_TRUE;
}
#endif /* defined(__MMI_FILE_MANAGER__) */


#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_media_play_video_callback
 * DESCRIPTION
 *  This function is the callback of playing video.
 * PARAMETERS
 *  result              : [IN]          Result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ssv_media_play_video_callback(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_notify_enum type = MMI_EVENT_DEFAULT;
    MMI_ID_TYPE string_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_SSV_LOG((TRC_MMI_SSV_VIDEO_PLAY_CALL_BACK_HDLR, result));
    
    if (result < 0)
    {
        string_id = mdi_util_get_mdi_error_info(result, &type);
        PhnsetScreenSaverBadFileCallBack(string_id);
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_media_exit
 * DESCRIPTION
 *  This function exits the screen saver.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ssv_media_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FILE_MANAGER__)
    mmi_ssv_media_stop_drm_right(0, 0);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_media_enter
 * DESCRIPTION
 *  This function enters the screen saver.
 * PARAMETERS
 *  param           : [IN]          Screen parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ssv_media_enter(mmi_scrn_essential_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ssv_media_struct *p;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(param && param->user_data);

    ret = mmi_frm_scrn_enter(
            param->group_id,
            param->scrn_id,
            mmi_ssv_media_exit,
            NULL,
            MMI_FRM_FULL_SCRN);

    if (!ret)
    {
        return;
    }

    p = (mmi_ssv_media_struct *)param->user_data;

    switch (p->res_type)
    {
        case FMGR_GROUP_IMAGE:
            ShowCategory166Screen(
                p->res_id,
                p->res_filename,
                NULL);
            break;

    #if defined(__MMI_VIDEO_PLAY_SUPPORT__)
        case FMGR_GROUP_VIDEO:
            ShowCategory224Screen(
                p->res_id,                          /* video id */
                p->res_filename,                    /* filename */
                0,                                  /* repeat_count. 0 means infinite */
                MMI_TRUE,                           /* is_visaul_update */
                MMI_FALSE,                          /* is_play_audio */
                MMI_FALSE,                          /* is_lcd_no_sleep. Need sleep-in. */
                GDI_COLOR_BLACK,                    /* bg_color */
                mmi_ssv_media_play_video_callback,  /* play_finish_callback(S16) */
                NULL);                              /* gui_buffer */
            break;
    #endif /* defined(__MMI_VIDEO_PLAY_SUPPORT__) */

        default:
            MMI_ASSERT(0);
            break;
    }

    mmi_ssv_obj_set_handler((mmi_ssv_obj_struct *)p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_media_pre_run
 * DESCRIPTION
 *  This function checks if it is ok to display the screen saver.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  On ok, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_ssv_media_pre_run(mmi_ssv_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ssv_media_struct *p;
    MMI_BOOL is_prohibited, ret;
    FS_HANDLE fs_handle;
    PS8 dummy;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    p = (mmi_ssv_media_struct *)obj;

    /*
     * Check if setting is a valid image screen saver.
     */
    ret = mmi_ssv_media_get_setting(&p->res_type, &p->res_id, &p->res_filename);
    if (!ret)
    {
        PhnsetScreenSaverBadFileCallBack(0);
        return MMI_FALSE;
    }

    /*
     * Check if category supports this type.
     */
    if (p->res_type != FMGR_GROUP_IMAGE &&
    #if defined(__MMI_VIDEO_PLAY_SUPPORT__)
        p->res_type != FMGR_GROUP_VIDEO &&
    #endif
        MMI_TRUE)
    {
        PhnsetScreenSaverBadFileCallBack(0);
        return MMI_FALSE;
    }

#if defined(__MMI_FILE_MANAGER__)
    /*
     * Check file limitation.
     */
    if (p->res_filename)
    {
        ret = (MMI_BOOL)mmi_fmgr_util_file_limit_check(
                            FMGR_LIMIT_SCREEN_SAVER,
                            p->res_filename,
                            &dummy);

        if (!ret)
        {
            PhnsetScreenSaverBadFileCallBack(0);
            return MMI_FALSE;
        }

        /*
         * Check if file can be opened.
         */
        ret = mmi_ssv_media_check_file(p, &fs_handle, &is_prohibited);
        if (!ret)
        {
            mmi_ssv_media_display_file_error(is_prohibited, fs_handle);
            return MMI_FALSE;
        }
    }
#endif /* defined(__MMI_FILE_MANAGER__) */

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_media_on_run
 * DESCRIPTION
 *  This function runs the screen saver.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ssv_media_on_run(mmi_ssv_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ssv_obj_on_run(obj);

    if (!mmi_ssv_media_pre_run(obj))
    {
        mmi_ssv_obj_emit_close_req(obj);
        return;
    }

    mmi_frm_group_enter(obj->this_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(
        obj->this_gid,
        SCR_ID_SSV_MAIN,
        (FuncPtr)mmi_ssv_media_enter,
        obj);
}


#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_media_on_backlight_changed
 * DESCRIPTION
 *  This function handles the backlight changed event.
 * PARAMETERS
 *  obj             : [IN]          Object
 *  is_light        : [IN]          Is backlight on or off
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ssv_media_on_backlight_changed(
    mmi_ssv_obj_struct *obj,
    MMI_BOOL is_light)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ssv_media_struct *p;
    mmi_scenario_state_enum state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ssv_obj_on_backlight_changed(obj, is_light);

    p = (mmi_ssv_media_struct *)obj;

    state = mmi_frm_scrn_get_state(p->this_gid, SCR_ID_SSV_MAIN);

    if ((p->res_type != FMGR_GROUP_VIDEO) ||
        (state != MMI_SCENARIO_STATE_ACTIVE))
    {
        return;
    }

    if (is_light)
    {
        ResumeCategory224Video();
    }
    else
    {
        PauseCategory224Video();
    }
}
#endif /* defined(__MMI_VIDEO_PLAY_SUPPORT__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_media_on_init
 * DESCRIPTION
 *  This function initializes the object.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssv_media_on_init(mmi_ssv_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ssv_media_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ssv_obj_on_init(obj);

    p = (mmi_ssv_media_struct *)obj;

    /* Member variable. */
    p->type = MMI_SCR_SAVER_TYPE_MEDIA;

    /* Member function. */
    p->on_run = mmi_ssv_media_on_run;

#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
    p->on_backlight_changed = mmi_ssv_media_on_backlight_changed;
#endif
}
#endif /* defined(__MMI_SCREEN_SAVER__) */
