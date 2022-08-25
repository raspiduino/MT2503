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
 *  ViewSettingCommon.c
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_FILE_MANAGER__
#include "MMIDataType.h"
#include "ViewSettingCommonProt.h"
#include "PhoneSetupGprots.h"
#include "WpssProtos.h"
#include "mmi_phnset_dispchar.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_viewsetting_def.h"
#include "FileMgrCuiGprot.h"
#include "FileMgrType.h"
#include "mmi_rp_file_type_def.h"
#include "DRM_def.h"
#include "Wgui_categories_multimedia.h"
#include "ProfilesSrvGprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "AlertScreen.h"
#include "wgui_categories_util.h"
#include "custom_events_notify.h"
#include "mdi_include.h"
#include "Asciiprot.h"
#include "IdleGprot.h"
#ifdef __DRM_SUPPORT__
#include "DRM_gprot.h"
#endif
#include "UcmSrvGprot.h"
#include "UCMGProt.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "profilessrvgprot.h"
#ifdef __MMI_IMAGE_CLIP_CUI__
#include "ImageClipCuiGprot.h"
#endif

/***************************************************************************** 
 * Local functions
 *****************************************************************************/
static U8 mmi_phnset_view_setting_cache_set_file (void *obj, const WCHAR *buffer);
static void mmi_phnset_view_setting_entry_common_file_preview_int(mmi_scrn_essential_struct *scrn_data);
static void mmi_phnset_view_setting_exit_common_file_preview_func(mmi_scrn_essential_struct *scrn_data);
static mmi_ret mmi_phnset_view_setting_common_fmgr_proc(mmi_event_struct *evt);
static WCHAR* mmi_phnset_view_setting_common_get_src_file(void);
static void mmi_phnset_view_setting_util_set_file_filter_by_struct(FMGR_FILTER *filter, const filetypes_file_type_enum *filter_struct);
static MMI_BOOL mmi_phnset_view_setting_util_is_file_type_in_struct(U16 file_type, const filetypes_file_type_enum *filter_struct);
static void mmi_phnset_view_setting_entry_waiting(void);
static void mmi_phnset_view_setting_close_waiting(void);
#ifdef __MMI_IMAGE_CLIP_CUI__
static void mmi_phnset_display_launch_image_clip_cui(mmi_id parent_id, WCHAR* file_name);
#endif /*  __MMI_IMAGE_CLIP_CUI__ */

/***************************************************************************** 
 * Config
 *****************************************************************************/

#if (!defined(__MMI_VIEW_SETTING_DISABLE_CACHE__) && !defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__) && !defined (__MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__))
const mmi_setting_display_cache_setting_object_struct g_mmi_display_wallpaper_setting = 
{
    MMI_PHNSET_TYPE_WP,
    mmi_phnset_view_setting_cache_set_file,
    mmi_phnset_wallpaper_get_default_driver,
    (mmi_setting_display_get_file_name_hdlr)mmi_phnset_wallpaper_get_default_folder,
    (mmi_setting_display_get_file_name_hdlr)mmi_phnset_wallpaper_get_default_file_prefix,
    mmi_phnset_wallpaper_set_file
};
#else
const mmi_setting_display_fmgr_setting_object_struct g_mmi_display_wallpaper_setting = 
{
    MMI_PHNSET_TYPE_WP,
    (mmi_setting_display_set_file_hdlr)mmi_phnset_wallpaper_direct_set_file
};
#endif
/* Screen lock wallpaper */
#ifdef __MMI_VUI_SCREEN_LOCK_KEY__
const mmi_setting_display_fmgr_setting_object_struct g_mmi_display_sl_wallpaper_setting = 
{
    MMI_PHNSET_TYPE_SL_WP,
    (mmi_setting_display_set_file_hdlr)mmi_phnset_wallpaper_screen_lock_direct_set_file
};
#endif /* __MMI_VUI_SCREEN_LOCK_KEY__ */

#ifdef __MMI_SUB_WALLPAPER__
const mmi_setting_display_fmgr_setting_object_struct g_mmi_display_sub_wallpaper_setting = 
{
    MMI_PHNSET_TYPE_SUB_WP,
    (mmi_setting_display_set_file_hdlr)mmi_phnset_sub_wallpaper_set_file
};
#endif /* __MMI_SUB_WALLPAPER__ */

#ifdef __MMI_SCREEN_SAVER__
#if (!defined(__MMI_VIEW_SETTING_DISABLE_CACHE__) && !defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__) && !defined (__MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__))
const mmi_setting_display_cache_setting_object_struct g_mmi_display_screen_saver_setting = 
{
    MMI_PHNSET_TYPE_SS,
    mmi_phnset_view_setting_cache_set_file,
    mmi_phnset_wallpaper_get_default_driver, /* Use the same driver as wallpaper setting */
    (mmi_setting_display_get_file_name_hdlr)mmi_phnset_wallpaper_get_default_folder, /* Use the same folder as wallpaper setting */
    (mmi_setting_display_get_file_name_hdlr)mmi_phnset_screensaver_get_default_file_prefix,
    mmi_phnset_screensaver_set_file
};
#else
const mmi_setting_display_fmgr_setting_object_struct g_mmi_display_screen_saver_setting = 
{
    MMI_PHNSET_TYPE_SS,
    mmi_phnset_screensaver_direct_set_file
};
#endif
#endif

#ifdef __MMI_POWER_ON_OFF_DISPLAY__
const mmi_setting_display_fmgr_setting_object_struct g_mmi_display_pwr_on_setting = 
{
    MMI_PHNSET_TYPE_PWRON,
    (mmi_setting_display_set_file_hdlr)mmi_phnset_pwr_on_off_set_file
};

const mmi_setting_display_fmgr_setting_object_struct g_mmi_display_pwr_off_setting = 
{
    MMI_PHNSET_TYPE_PWROFF,
    (mmi_setting_display_set_file_hdlr)mmi_phnset_pwr_on_off_set_file
};
#endif

const mmi_setting_display_fmgr_setting_object_struct* g_mmi_display_fmgr_setting_table[] =
{
    (mmi_setting_display_fmgr_setting_object_struct*)&g_mmi_display_wallpaper_setting,
#ifdef __MMI_VUI_SCREEN_LOCK_KEY__
    (mmi_setting_display_fmgr_setting_object_struct*)&g_mmi_display_sl_wallpaper_setting,
#endif
#ifdef __MMI_SUB_WALLPAPER__
	(mmi_setting_display_fmgr_setting_object_struct*)&g_mmi_display_sub_wallpaper_setting,
#endif
#ifdef __MMI_SCREEN_SAVER__
    (mmi_setting_display_fmgr_setting_object_struct*)&g_mmi_display_screen_saver_setting,
#endif
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    (mmi_setting_display_fmgr_setting_object_struct*)&g_mmi_display_pwr_on_setting,
    (mmi_setting_display_fmgr_setting_object_struct*)&g_mmi_display_pwr_off_setting,
#endif
    NULL
};

const S32 g_mmi_view_setting_limit_table[] = 
{
    FMGR_LIMIT_WALLPAPER,
#ifdef __MMI_VUI_SCREEN_LOCK_KEY__
	FMGR_LIMIT_WALLPAPER, 
#endif
#ifdef __MMI_SUB_WALLPAPER__
    FMGR_LIMIT_SUB_WALLPAPER,
#endif
    FMGR_LIMIT_SCREEN_SAVER,
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    FMGR_LIMIT_POWER_ON_OFF_DSPL,
    FMGR_LIMIT_POWER_ON_OFF_DSPL,
#endif
    NULL
};
/***************************************************************************** 
 * Local variable
 *****************************************************************************/
static mmi_proc_func g_mmi_display_setting_callback;
static void *g_mmi_display_setting_user_data;

static mmi_setting_display_fmgr_setting_object_struct *current_setting_obj;
#define MMI_DISPLAY_SETTING_GET_CURRENT_OBJ(x) (x = current_setting_obj)
#define MMI_DISPLAY_SETTING_SET_CURRENT_OBJ(x) (current_setting_obj = x)

static U32 g_phnset_view_setting_view_type;

static WCHAR *g_phnset_display_cache_temp_buffer;

static S32 g_phnset_display_cache_fmgr_job_id;
static MMI_ID_TYPE g_phnset_view_setting_error_string_id;
static WCHAR *g_phnset_view_setting_error_string_ptr;
static WCHAR *g_phnset_view_setting_src_file_name;

/* Supported file type */
const static filetypes_file_type_enum g_phnset_view_setting_support_image_type[] = 
{
    FMGR_TYPE_BMP,
    FMGR_TYPE_WBMP, 
    FMGR_TYPE_WBM, 
    FMGR_TYPE_GIF, 
#ifdef JPG_DECODE        
    FMGR_TYPE_JPG, 
    FMGR_TYPE_JPEG,     
#endif         
#if defined(GDI_USING_PNG)
    FMGR_TYPE_PNG, 
#endif
#if defined(__DRM_V02__)
    FMGR_TYPE_ODF, 
#endif
#if defined(SVG_SUPPORT) && !defined(__MMI_VUI_ENGINE__)
    FMGR_TYPE_SVG, 
#endif
#ifdef M3D_MMI_SUPPORT
    FMGR_TYPE_M3D, 
#endif        
#ifdef __MMI_SWFLASH__
    FMGR_TYPE_VIS, 
    FMGR_TYPE_IVIS, 
    FMGR_TYPE_KVIS,         
    FMGR_TYPE_MVIS,       
#endif        
    /* End of file type */
    FMGR_TYPE_UNKNOWN
};

const static filetypes_file_type_enum g_phnset_view_setting_support_image_wp_type[] = 
{
#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV__
	FMGR_TYPE_MAV,
#endif
		/* End of file type */
	FMGR_TYPE_UNKNOWN
};

/* Sub LCD support file type */
#ifdef __MMI_SUB_WALLPAPER__
const static filetypes_file_type_enum g_phnset_view_setting_support_sub_image_type[] = 
{
    FMGR_TYPE_BMP, 
    FMGR_TYPE_WBMP, 
    FMGR_TYPE_WBM, 
    FMGR_TYPE_GIF, 
#ifdef JPG_DECODE        
    FMGR_TYPE_JPG, 
    FMGR_TYPE_JPEG,     
#endif              
#if defined(GDI_USING_PNG)
    FMGR_TYPE_PNG, 
#endif
#if defined(__DRM_V02__)
    FMGR_TYPE_ODF, 
#endif
    /* End of file type */
    FMGR_TYPE_UNKNOWN
};
#endif

#if defined(__MMI_SCREENSAVER_DISPLAY_VIDEO__) || defined(__MMI_POWER_ON_OFF_DISPLAY_VIDEO__)
const static filetypes_file_type_enum g_phnset_view_setting_support_video_type[] = 
{
#if defined(__MTK_TARGET__)
#ifdef MP4_DECODE
    FMGR_TYPE_3GP, 
    FMGR_TYPE_MP4, 
    FMGR_TYPE_MPG, 
    FMGR_TYPE_3G2, 
#endif /* MP4_DECODE */ 
#ifdef MJPG_DECODE
    FMGR_TYPE_AVI, 
#endif
#ifdef __RM_DEC_SUPPORT__
    FMGR_TYPE_RV, 
    FMGR_TYPE_RM, 
    FMGR_TYPE_RMVB, 
#endif
#ifdef __FLV_FILE_FORMAT_SUPPORT__
    FMGR_TYPE_FLV, 
    FMGR_TYPE_F4V, 
#endif
#endif /* defined(__MTK_TARGET__) */         
    FMGR_TYPE_UNKNOWN
};
#endif /* defined(__MMI_SCREENSAVER_DISPLAY_VIDEO__) || defined(__MMI_POWER_ON_OFF_DISPLAY_VIDEO__) */ 

#if (defined (__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__)) || (defined (__MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__)) //Modify for VLW In pluto,  need to add compile option
/* video live wallpaper surported video type */
const static filetypes_file_type_enum g_phnset_view_setting_support_vlw_type[] = 
{
#ifdef MP4_DECODE
    FMGR_TYPE_3GP, 
    FMGR_TYPE_MP4, 
#endif /* MP4_DECODE */ 
#ifdef MJPG_DECODE
    FMGR_TYPE_AVI, 
#endif	
    FMGR_TYPE_UNKNOWN
};
#endif /* __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__ */ 


/***************************************************************************** 
 * API
 *****************************************************************************/
/***************************************************************************** 
 * Utility functions
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_view_setting_util_get_file_name_ptr
 * DESCRIPTION
 *  To find the pointer of path
 * PARAMETERS
 *  path        [IN]            
 *  a(?)        [IN/OUT]        Void *
 *  b(?)        [IN]            
 * RETURNS
 *  PS8 wallpaper name string pointer
 *****************************************************************************/
WCHAR* mmi_phnset_view_setting_util_get_file_name_ptr(const WCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 len;
    U16 deter = 0x005C; /* '\' */
    S16 *p = (S16*) path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = (U16) mmi_ucs2strlen((const CHAR*)path);
    for (; len > 0; len--)
    {
        if (*(p + len) == deter)
        {
            return (WCHAR*)(p + len + 1);
        }
    }

    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_view_setting_util_check_file_limit
 * DESCRIPTION
 *  Check file before display 
 * PARAMETERS
 *  
 * RETURNS
 *  U8
 *****************************************************************************/
static MMI_BOOL mmi_phnset_view_setting_util_check_file_limit(U32 view_type, const WCHAR* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!filename)
	{
	    return MMI_FALSE; //Null file name
	}
#ifdef __MMI_IMAGE_CLIP_CUI__
	if(cui_image_clip_is_file_format_supported((WCHAR*)filename))
	{
		return MMI_TRUE;
	}
#endif /* __MMI_IMAGE_CLIP_CUI__ */
    if (!mmi_fmgr_util_file_limit_check(g_mmi_view_setting_limit_table[view_type], (CHAR*) filename, (CHAR**)&g_phnset_view_setting_error_string_ptr))
    {
        return MMI_FALSE;
    }
	else if(srv_fmgr_types_find_group_by_filename_str(filename) == FMGR_GROUP_IMAGE)
	{
		if(!mmi_fmgr_util_file_limit_check(FMGR_LIMIT_IMAGE_VIEWER, (CHAR*) filename, (CHAR**)&g_phnset_view_setting_error_string_ptr))
		{
			return MMI_FALSE;
		}
	}
    return MMI_TRUE;
}

#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_view_setting_util_check_drm
 * DESCRIPTION
 *  Perform DRM check on input file 
 * PARAMETERS
 *  
 * RETURNS
 *  static U8
 *****************************************************************************/
static U8 mmi_phnset_view_setting_util_check_drm(const WCHAR* file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 res_type;
    U8 permission;
    FS_HANDLE handle;
    MMI_BOOL is_perm = MMI_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res_type = srv_fmgr_types_find_group_by_filename_str((WCHAR*)file_name);
    
    if (res_type == FMGR_GROUP_IMAGE)
    {
        permission = DRM_PERMISSION_DISPLAY;
    }
    else if (res_type == FMGR_GROUP_VIDEO)
    {
        permission = DRM_PERMISSION_PLAY;
    }
    else 
    {
        permission = DRM_PERMISSION_NONE;
    }
    
    if (permission != DRM_PERMISSION_NONE)
    {
        handle = DRM_open_file((PU16)file_name, FS_READ_ONLY, permission);
        
        if (handle >= FS_NO_ERROR)
        {
            is_perm = (MMI_BOOL)DRM_validate_forward_rule(handle, permission);
            DRM_close_file(handle);
        }
    }
    
    if (!is_perm)
    {
        g_phnset_view_setting_error_string_id = STR_GLOBAL_DRM_PROHIBITED;
        return PHNSET_WP_SS_SET_DRM_CHECK_FAIL;
    }    
    return PHNSET_WP_SS_SET_NO_ERROR;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_view_setting_util_get_error_string
 * DESCRIPTION
 *  Get the error string 
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_ID
 *****************************************************************************/
MMI_ID mmi_phnset_view_setting_util_get_error_string(U8 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (error_code)
	{
	case PHNSET_WP_SS_SET_DISK_SIZE_NOT_ENOUGH:
		return STR_GLOBAL_NOT_ENOUGH_MEMORY;

    case PHNSET_WP_SS_SET_PREPARE_FOLDER_FAIL:
    case PHNSET_WP_SS_SET_PREPARE_FILE_FAIL:
    case PHNSET_WP_SS_SET_GET_DISK_INFO_FAIL:
        return STR_GLOBAL_FAILED_TO_SAVE;
        
	default:
		break;
	}
    return STR_GLOBAL_UNSUPPORTED_FORMAT;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_wallpaper_set_file_filter
 * DESCRIPTION
 *  Set file filter for wallpaper, screen saver, power on/off  display. 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_view_setting_util_set_file_filter(FMGR_FILTER *filter, phnset_wpss_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set filter for video file */    
    switch (type)
	{
    case MMI_PHNSET_TYPE_SS:
#if defined(__MMI_SCREENSAVER_DISPLAY_VIDEO__)        
        mmi_phnset_view_setting_util_set_file_filter_by_struct(filter, g_phnset_view_setting_support_video_type);
#endif
        break;

	case MMI_PHNSET_TYPE_WP:
#ifdef __MMI_VUI_SCREEN_LOCK_KEY__
	case MMI_PHNSET_TYPE_SL_WP:
#endif
#if (defined (__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__)) || (defined (__MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__))   //Modify for VLW in Pluto, need to add compile option 
        if(mmi_factory_get_favorite_type(mmi_idle_get_cfg_table()) != MMI_IDLE_TYPE_CLASSIC)
        {
		    mmi_phnset_view_setting_util_set_file_filter_by_struct(filter, g_phnset_view_setting_support_vlw_type);
	    }
#endif 
#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV__
		mmi_phnset_view_setting_util_set_file_filter_by_struct(filter, g_phnset_view_setting_support_image_wp_type);
#endif
		break;
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    case MMI_PHNSET_TYPE_PWRON:
    case MMI_PHNSET_TYPE_PWROFF:
#if defined(__MMI_POWER_ON_OFF_DISPLAY_VIDEO__)
        mmi_phnset_view_setting_util_set_file_filter_by_struct(filter, g_phnset_view_setting_support_video_type);
#endif
        break;        
#endif /* __MMI_POWER_ON_OFF_DISPLAY__ */ 

#ifdef __MMI_SUB_WALLPAPER__
    case MMI_PHNSET_TYPE_SUB_WP:
        mmi_phnset_view_setting_util_set_file_filter_by_struct(filter, g_phnset_view_setting_support_sub_image_type);
        return;
#endif

	default:
		break;
	}

    /* Set filter for image file */
    mmi_phnset_view_setting_util_set_file_filter_by_struct(filter, g_phnset_view_setting_support_image_type);    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_disp_set_file_filter_from_support_struct
 * DESCRIPTION
 *  Set file filter from structure 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_view_setting_util_set_file_filter_by_struct(FMGR_FILTER *filter, const filetypes_file_type_enum *filter_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!filter || !filter_struct)
	{
	    return;
	}
    for (i = 0; filter_struct[i] != FMGR_TYPE_UNKNOWN; i++)
	{
        FMGR_FILTER_SET(filter, filter_struct[i]); 		
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_view_setting_util_check_file_type
 * DESCRIPTION
 *  Check if the input file type is supported 
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_phnset_view_setting_util_check_file_type(U16 file_type, phnset_wpss_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
	{
	case MMI_PHNSET_TYPE_SS:
#if defined(__MMI_SCREENSAVER_DISPLAY_VIDEO__)
        result = mmi_phnset_view_setting_util_is_file_type_in_struct(file_type, g_phnset_view_setting_support_video_type);
#endif
        break;     

#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    case MMI_PHNSET_TYPE_PWRON:
    case MMI_PHNSET_TYPE_PWROFF:
#if defined(__MMI_POWER_ON_OFF_DISPLAY_VIDEO__)
        result = mmi_phnset_view_setting_util_is_file_type_in_struct(file_type, g_phnset_view_setting_support_video_type);
#endif
    	break;
#endif /* __MMI_POWER_ON_OFF_DISPLAY__ */ 

	case MMI_PHNSET_TYPE_WP:	
#ifdef __MMI_VUI_SCREEN_LOCK_KEY__
	case MMI_PHNSET_TYPE_SL_WP:
#endif
#if (defined (__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__)) || (defined (__MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__)) /*video wallpaper feature */ //add for VLW in pluto, need to add compile option
		result = mmi_phnset_view_setting_util_is_file_type_in_struct(file_type, g_phnset_view_setting_support_vlw_type);
#endif /* __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__ */
#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV__
		if(!result)
		{
			result = mmi_phnset_view_setting_util_is_file_type_in_struct(file_type, g_phnset_view_setting_support_image_wp_type);
		}
#endif /* __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV__ */
		break;

#ifdef __MMI_SUB_WALLPAPER__
	case MMI_PHNSET_TYPE_SUB_WP:
		result = mmi_phnset_view_setting_util_is_file_type_in_struct(file_type, g_phnset_view_setting_support_sub_image_type);
		break;
#endif /* __MMI_SUB_WALLPAPER__ */
	default:
		break;
	}
    if (result)
	{
	    return result;
	}
    result = mmi_phnset_view_setting_util_is_file_type_in_struct(file_type, g_phnset_view_setting_support_image_type);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_display_is_file_type_support_in_struct
 * DESCRIPTION
 *  Check if this file type is in the input structure 
 * PARAMETERS
 *  
 * RETURNS
 *  static MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_phnset_view_setting_util_is_file_type_in_struct(U16 file_type, const filetypes_file_type_enum *filter_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!filter_struct)
	{
	    return MMI_FALSE;
	}
    for (i = 0; filter_struct[i] != FMGR_TYPE_UNKNOWN; i++)
	{
        if (file_type == filter_struct[i])		
    	{
    	    return MMI_TRUE;
    	}
	}
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_view_setting_cache_util_del_file
 * DESCRIPTION
 *  phone setup delete file function
 * PARAMETERS
 *  void
 * RETURNS
 *  file_path
 *****************************************************************************/
S32 mmi_phnset_view_setting_cache_util_del_file(const WCHAR* file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 attr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    attr = FS_GetAttributes((const WCHAR*) file_path);
    if (attr & FS_ATTR_READ_ONLY)
    {
        FS_SetAttributes((const WCHAR*) file_path, (U8) (attr & ~(FS_ATTR_READ_ONLY)));
    }
    return FS_Delete((const WCHAR*)file_path);
}

static void mmi_phnset_view_setting_cache_free_buf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phnset_view_setting_src_file_name)
    {
        OslMfree(g_phnset_view_setting_src_file_name);
        g_phnset_view_setting_src_file_name = NULL;
    }
    if (g_phnset_display_cache_temp_buffer)
	{
	    OslMfree(g_phnset_display_cache_temp_buffer);
        g_phnset_display_cache_temp_buffer = NULL;
	}
}
#if (!defined(__MMI_VIEW_SETTING_DISABLE_CACHE__) && !defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__) && !defined (__MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__))
/***************************************************************************** 
 * Cache setting utility functions
 *****************************************************************************/
void mmi_phnset_view_setting_cache_util_get_default_folder(WCHAR *buffer, U8 buffer_len, CHAR driver_letter, const CHAR *default_folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR path_ascii[MMI_SETTING_DISPLAY_CACHE_USER_FILE_NAME_LEN];
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(buffer, 0, buffer_len);
    if (driver_letter > 0)
    {
        /* Create Path */
        memset(path_ascii, 0x00, MMI_SETTING_DISPLAY_CACHE_USER_FILE_NAME_LEN);
        sprintf(path_ascii, "%c:\\%s", (CHAR)driver_letter, default_folder);
        if (AsciiStrlen(path_ascii) > buffer_len)
    	{
            ASSERT(0);
    	    return;
    	}            
        mmi_asc_to_ucs2((CHAR*)buffer, path_ascii);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_get_postfix
 * DESCRIPTION
 *  get postfix of ucs2 in Buffer
 * PARAMETERS
 *  U8 * postfix
 *  U8 * inBuffer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_view_setting_cache_util_get_postfix(WCHAR *postfix, WCHAR *inBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *ext = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((inBuffer == NULL) || (postfix == NULL))
    {
        return;
    }

    /* search the '.' from end of file_name */
    {
        U8 *pos = (U8 *) inBuffer;
        
        while (1)
        {
            if ((*pos == 0) && (*(pos+1) == 0))
                break;

            if (*pos == L'.')
            {
                ext = (WCHAR*)(pos + 2);
            }
            pos += 2;
        }
    }
    
    if (ext)
    {
        mmi_wcscpy(postfix, ext);
    }
    else
    {
        mmi_wcscpy(postfix, L"");
    }
}

static U8 mmi_phnset_view_setting_cache_util_prepare_folder(const WCHAR* folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;
    S32 result = FS_NO_ERROR; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (folder[0] != 0x00)
    {        
        fh = FS_Open((U16*) folder, FS_OPEN_DIR | FS_READ_ONLY);
        
        /* Folder Exists */
        if (fh > 0)
        {
            S32 folder_attribute = FS_GetAttributes((U16*) folder);
            if (!(folder_attribute & FS_ATTR_DIR) || !(folder_attribute & FS_ATTR_HIDDEN))
            {
                FS_SetAttributes((U16*) folder, FS_ATTR_DIR | FS_ATTR_HIDDEN);        	
            }
            FS_Close(fh);
        }
        /* Folder Does Not Exist */
        else
        {
            result = FS_CreateDir((U16*) folder);
            /* Create Success */
            if (result == FS_NO_ERROR)
            {
                FS_SetAttributes((U16*) folder, FS_ATTR_DIR | FS_ATTR_HIDDEN);
            }
            else
            {
                MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_WALLPAPER_TRACE_024, result);
                return PHNSET_WP_SS_SET_PREPARE_FOLDER_FAIL;
            }
        }
    } 
    else
    {
        return PHNSET_WP_SS_SET_PREPARE_FOLDER_FAIL;
    }
    return PHNSET_WP_SS_SET_NO_ERROR;
}

static void mmi_phnset_view_setting_cache_util_del_old_file(const WCHAR* folder, const WCHAR* file_prefix)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
    FS_HANDLE file_hnd;    
    FS_DOSDirEntry file_info;
    WCHAR filename[MMI_SETTING_DISPLAY_CACHE_USER_FILE_NAME_LEN];    
	WCHAR search_path[MMI_SETTING_DISPLAY_CACHE_USER_FILE_NAME_LEN];
    WCHAR full_filename[MMI_SETTING_DISPLAY_CACHE_USER_FILE_NAME_LEN];    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_WALLPAPER_TRACE_043);

	kal_wsprintf(search_path, "%w*", file_prefix);
    file_hnd = FS_FindFirst(
                search_path,
                0,
                0,
                &file_info,
                (WCHAR*)filename,
                MMI_SETTING_DISPLAY_CACHE_USER_FILE_NAME_LEN * sizeof(WCHAR));    

    if (file_hnd >= 0)
    {
        do
    	{
			S32 attribute = FS_GetAttributes(full_filename);

			kal_wsprintf(full_filename, "%w\\%w", folder, filename);

			// Delete temp file            
            if (attribute & FS_ATTR_READ_ONLY)
            {
                FS_SetAttributes(full_filename, (U8) (attribute & ~(FS_ATTR_READ_ONLY)));
            }
            if(FS_Delete(full_filename) < FS_NO_ERROR)
            {
               return;
            }       
        }
        while (FS_FindNext(file_hnd, &file_info, (U16*)search_path, (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH) == FS_NO_ERROR);
    }
    FS_FindClose(file_hnd);
}

U8 mmi_phnset_view_setting_cache_util_prepare_cache_file(const WCHAR* full_prefix, const WCHAR* src_file_name, WCHAR *buffer, U32 buff_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR postfix[SRV_FMGR_PATH_MAX_FILE_EXT_LEN];
    WCHAR search_file[MMI_SETTING_DISPLAY_CACHE_USER_FILE_NAME_LEN];
    FS_HANDLE fh;
    U8 index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phnset_view_setting_cache_util_get_postfix(postfix, (WCHAR*)src_file_name);

    kal_wsprintf(search_file, "%w%2d.%w", full_prefix, index, postfix);
    
    index++;
    while(1)
    {
        /* delete exist file with same name */
        fh = FS_Open((U16 *)search_file, FS_READ_ONLY);

        if (fh >= FS_NO_ERROR)
        {
            S32 ret_del;

            FS_Close(fh);
            ret_del = mmi_phnset_view_setting_cache_util_del_file(search_file);

            MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_WALLPAPER_TRACE_036, ret_del);

            if (ret_del != 0)
        	{
                kal_wsprintf(search_file, "%w%2d.%w", full_prefix, index, postfix);
                index++;
                continue;
        	}
        }
        else if ((fh != FS_FILE_NOT_FOUND) && (fh != FS_PATH_NOT_FOUND))
        {
            MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_WALLPAPER_TRACE_037, fh);
            return PHNSET_WP_SS_SET_PREPARE_FILE_FAIL;
        }

        mmi_wcscpy(buffer, search_file);
        break;
    }
    
    return PHNSET_WP_SS_SET_NO_ERROR;
}

U8 mmi_phnset_view_setting_cache_util_check_driver_space(S16 driver, const WCHAR *src_file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;
    FS_DiskInfo disk_info;    
    U32 new_file_len = 0;   /* size of new file */
    U64 disk_free_space;
    U64 disk_total_space;
    WCHAR file_path[MMI_SETTING_DISPLAY_CACHE_USER_FILE_NAME_LEN];    
    S32 fs_ret;  
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* open current file and get file size */
    fh = FS_Open( src_file_name, FS_READ_ONLY);

    if(fh >= 0)
    {
        FS_GetFileSize(fh, &new_file_len);
        FS_Close(fh);

        MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_WALLPAPER_TRACE_025, new_file_len);
        if(new_file_len == 0)
        {
            mmi_phnset_view_setting_cache_util_del_file(src_file_name);
        }
    }

    /* check device status */
    disk_free_space = 0;
    disk_total_space = 0;

    kal_wsprintf(file_path, "%c:\\", driver);
    
    fs_ret = FS_GetDiskInfo((PU16) file_path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

    if (fs_ret >= 0)
    {
        disk_free_space = disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
        disk_total_space = disk_info.TotalClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
        MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_WALLPAPER_TRACE_026, disk_free_space);
        MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_WALLPAPER_TRACE_027, disk_total_space);
        if (new_file_len >= disk_free_space)
        {
            return PHNSET_WP_SS_SET_DISK_SIZE_NOT_ENOUGH;
        }
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_WALLPAPER_TRACE_028);
        return PHNSET_WP_SS_SET_GET_DISK_INFO_FAIL;
    }    

    return PHNSET_WP_SS_SET_NO_ERROR;    
}

/***************************************************************************** 
 * Cache setting 
 *****************************************************************************/
static mmi_ret mmi_phnset_view_setting_cache_set_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 setting_result = PHNSET_WP_SS_SET_NO_ERROR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param->evt_id == EVT_ID_SRV_FMGR_ASYNC_DONE)
	{
        srv_fmgr_async_done_event_struct *done_event = (srv_fmgr_async_done_event_struct*)param;
        MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_WALLPAPER_TRACE_041, done_event->result);
        mmi_phnset_view_setting_close_waiting();
        if (done_event->result >= 0)
        {
            mmi_setting_display_cache_setting_object_struct *obj;
			obj = (mmi_setting_display_cache_setting_object_struct*)current_setting_obj;
            obj->cache_set_file(obj, mmi_phnset_view_setting_common_get_src_file(), g_phnset_display_cache_temp_buffer);
            setting_result = PHNSET_WP_SS_SET_NO_ERROR;
            mmi_phnset_view_setting_notify_result(MMI_TRUE, setting_result);
        }
        else
        {
			mmi_phnset_view_setting_cache_util_del_file((const unsigned short *)g_phnset_display_cache_temp_buffer);
               
            g_phnset_view_setting_error_string_id = (MMI_ID_TYPE)srv_fmgr_fs_error_get_string(done_event->result);
            setting_result = PHNSET_WP_SS_SET_COPY_FILE_FAIL;        
            mmi_phnset_view_setting_notify_result(MMI_FALSE, setting_result);
        }

        mmi_phnset_view_setting_cache_free_buf();
	}
    return MMI_RET_OK;
}

static U8 mmi_phnset_view_setting_cache_set_file (void *obj, const WCHAR *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 drive;
    U8 process_result;
    WCHAR folder[MMI_SETTING_DISPLAY_CACHE_USER_FILE_NAME_LEN];
    WCHAR prefix[MMI_SETTING_DISPLAY_CACHE_USER_FILE_NAME_LEN];
    mmi_setting_display_cache_setting_object_struct *cache_obj = (mmi_setting_display_cache_setting_object_struct*)obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_WALLPAPER_TRACE_022);

    cache_obj->get_default_folder((void*)obj, folder, MMI_SETTING_DISPLAY_CACHE_USER_FILE_NAME_LEN);

    process_result = mmi_phnset_view_setting_cache_util_prepare_folder(folder);
    if( process_result != PHNSET_WP_SS_SET_NO_ERROR)
    {
        return process_result;
    }

    cache_obj->get_default_file_prefix((void*)obj, prefix, MMI_SETTING_DISPLAY_CACHE_USER_FILE_NAME_LEN);
        
    mmi_phnset_view_setting_cache_util_del_old_file(folder, prefix);

    /* disk free space is OK or old file size more */
    MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_WALLPAPER_TRACE_029);
    
    if (g_phnset_display_cache_temp_buffer)
	{
	    OslMfree(g_phnset_display_cache_temp_buffer);
	}
    g_phnset_display_cache_temp_buffer = OslMalloc(sizeof(WCHAR) * MMI_SETTING_DISPLAY_CACHE_USER_FILE_NAME_LEN);

    process_result = mmi_phnset_view_setting_cache_util_prepare_cache_file(prefix, mmi_phnset_view_setting_common_get_src_file(), g_phnset_display_cache_temp_buffer, MMI_SETTING_DISPLAY_CACHE_USER_FILE_NAME_LEN);
    if(process_result != PHNSET_WP_SS_SET_NO_ERROR)
    {
        return process_result;
    }

    drive = cache_obj->get_default_driver(obj);

    process_result = mmi_phnset_view_setting_cache_util_check_driver_space(drive, mmi_phnset_view_setting_common_get_src_file());    
    if(process_result != PHNSET_WP_SS_SET_NO_ERROR)
    {
        return process_result;
    }

    /* use FMT to copy a file */
    g_phnset_display_cache_fmgr_job_id = srv_fmgr_async_copy(
        (WCHAR*)buffer,
        (WCHAR*)g_phnset_display_cache_temp_buffer,
        SRV_FMGR_ASYNC_FLAG_PRIORITY_FG,
        mmi_phnset_view_setting_cache_set_proc,
        NULL);

    /* If FS error, g_phnset_display_cache_fmgr_job_id < 0 */
    if(g_phnset_display_cache_fmgr_job_id < 0)
    {
        g_phnset_view_setting_error_string_id = srv_fmgr_fs_error_get_string(g_phnset_display_cache_fmgr_job_id);
        return PHNSET_WP_SS_SET_COPY_FILE_FAIL;
    }

    mmi_phnset_view_setting_entry_waiting();

    return PHNSET_WP_SS_SET_NO_ERROR;
}
#endif /*  (!defined(__MMI_VIEW_SETTING_DISABLE_CACHE__) && !defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__)) */
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_view_setting_set_by_file
 * DESCRIPTION
 *  Set the view to the input file 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_view_setting_set_by_file(U8 view_type, const WCHAR* file_name, mmi_proc_func callback, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U8 error_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_display_setting_callback = callback;
    g_mmi_display_setting_user_data = user_data;
    g_phnset_view_setting_view_type = view_type;
    
    while (1)
	{
        if (g_mmi_display_fmgr_setting_table[i] == NULL)
    	{
    	    mmi_phnset_view_setting_notify_result(MMI_FALSE, PHNSET_WP_SS_UNSUPPORT_TYPE);
            return;
    	}
        if (g_mmi_display_fmgr_setting_table[i]->display_type == view_type)
        {
            break;
        }
		i++;
	}
    
    MMI_DISPLAY_SETTING_SET_CURRENT_OBJ((mmi_setting_display_fmgr_setting_object_struct*)g_mmi_display_fmgr_setting_table[i]);
    
    error_code = g_mmi_display_fmgr_setting_table[i]->set_file((void*)g_mmi_display_fmgr_setting_table[i], file_name);

#if (!defined(__MMI_VIEW_SETTING_DISABLE_CACHE__) && !defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__) && defined (__MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__))
    if(error_code != PHNSET_WP_SS_SET_NO_ERROR)
    {
        mmi_phnset_view_setting_notify_result(MMI_FALSE, error_code);
    }
#endif /* (!defined(__MMI_VIEW_SETTING_DISABLE_CACHE__) && !defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__)) */

}

void mmi_phnset_view_setting_notify_result(MMI_BOOL result, U8 error_code) 
{
    mmi_setting_display_setting_event_struct evt;
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SETTING_DISPLAY_SETTING_DONE);
    evt.result = result;
    evt.error_code = error_code;
    evt.user_data = g_mmi_display_setting_user_data;
	(*g_mmi_display_setting_callback)((mmi_event_struct*)&evt);
    g_mmi_display_setting_callback = NULL;
    g_mmi_display_setting_user_data = NULL;
}

/***************************************************************************** 
 * Common view function
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_view_setting_common_play_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phnset_view_setting_common_play_callback(S32 result, MMI_BOOL is_video)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_PHNSET_WPSS_PLAY_CALLBACK, result);

    if (result >= 0)
    {
        return;
    }
    else
    {
        mmi_event_notify_enum error_popup_type;
        MMI_ID_TYPE popup_string_id;
        if (is_video)
    	{
            popup_string_id = mdi_util_get_mdi_error_info(result, &error_popup_type);            	
        }
        else
        {
            error_popup_type = MMI_EVENT_FAILURE;
            popup_string_id = STR_GLOBAL_UNSUPPORTED_FORMAT;
        }

        mmi_popup_display_simple_ext(popup_string_id, error_popup_type, GRP_ID_ROOT, NULL);

        if (mmi_frm_scrn_is_present(GRP_ID_VIEW_SETTING_FILE_COMMON_PREVIEW, SCR_ID_VIEW_SETTING_COMMON_FILE_PREVIEW, MMI_FRM_NODE_ALL_FLAG))
        {
            mmi_frm_scrn_close(GRP_ID_VIEW_SETTING_FILE_COMMON_PREVIEW, SCR_ID_VIEW_SETTING_COMMON_FILE_PREVIEW);
        }
        
        /* Close wallpaper system view screen */
#ifndef __MMI_MAINLCD_96X64__        
        if (mmi_frm_scrn_is_present(GRP_ID_WALLPAPER_SYSTEM_SUB, SCR_WALLPAPER_VIEW, MMI_FRM_NODE_ALL_FLAG))
    	{
            mmi_frm_scrn_close(GRP_ID_WALLPAPER_SYSTEM_SUB, SCR_WALLPAPER_VIEW);
    	}            
        if (mmi_frm_scrn_is_present(GRP_ID_WALLPAPER_SYSTEM_SUB, SCR_WALLPAPER_VIEW_2, MMI_FRM_NODE_ALL_FLAG))
    	{
            mmi_frm_scrn_close(GRP_ID_WALLPAPER_SYSTEM_SUB, SCR_WALLPAPER_VIEW_2);
    	}                        
#endif        
        /* Close screen saver system view screen */
#ifdef __MMI_SCREEN_SAVER__        
        if (mmi_frm_scrn_is_present(GRP_ID_SCREENSAVER_SYSTEM, SCR_SCREENSAVER_VIEW, MMI_FRM_NODE_ALL_FLAG))
    	{
            mmi_frm_scrn_close(GRP_ID_SCREENSAVER_SYSTEM, SCR_SCREENSAVER_VIEW);
    	}            
        if (mmi_frm_scrn_is_present(GRP_ID_SCREENSAVER_SYSTEM, SCR_SCREENSAVER_VIEW_2, MMI_FRM_NODE_ALL_FLAG))
    	{
            mmi_frm_scrn_close(GRP_ID_SCREENSAVER_SYSTEM, SCR_SCREENSAVER_VIEW_2);
    	}              
#endif        

#ifdef __MMI_POWER_ON_OFF_DISPLAY__
        if (mmi_frm_scrn_is_present(GRP_ID_POWER_ON_OFF_SYSTEM, SCR_ID_PHNSET_POWER_OFF_SYSTEM_VIEW, MMI_FRM_NODE_ALL_FLAG))
    	{
            mmi_frm_scrn_close(GRP_ID_POWER_ON_OFF_SYSTEM, SCR_ID_PHNSET_POWER_OFF_SYSTEM_VIEW);
    	}            
        if (mmi_frm_scrn_is_present(GRP_ID_POWER_ON_OFF_SYSTEM, SCR_ID_PHNSET_POWER_OFF_SYSTEM_VIEW_2, MMI_FRM_NODE_ALL_FLAG))
    	{
            mmi_frm_scrn_close(GRP_ID_POWER_ON_OFF_SYSTEM, SCR_ID_PHNSET_POWER_OFF_SYSTEM_VIEW_2);
    	}   
        if (mmi_frm_scrn_is_present(GRP_ID_POWER_ON_OFF_SYSTEM, SCR_ID_PHNSET_POWER_ON_SYSTEM_VIEW, MMI_FRM_NODE_ALL_FLAG))
    	{
            mmi_frm_scrn_close(GRP_ID_POWER_ON_OFF_SYSTEM, SCR_ID_PHNSET_POWER_ON_SYSTEM_VIEW);
    	}            
        if (mmi_frm_scrn_is_present(GRP_ID_POWER_ON_OFF_SYSTEM, SCR_ID_PHNSET_POWER_ON_SYSTEM_VIEW_2, MMI_FRM_NODE_ALL_FLAG))
    	{
            mmi_frm_scrn_close(GRP_ID_POWER_ON_OFF_SYSTEM, SCR_ID_PHNSET_POWER_ON_SYSTEM_VIEW_2);
    	}               
#endif        

        DisableLeftSoftkey(STR_GLOBAL_OK, NULL);
        DisableRightSoftkey(STR_GLOBAL_BACK, NULL);
    #ifdef __MMI_FILE_MANAGER__
        mmi_phnset_view_setting_cache_free_buf();
    #endif /* __MMI_FILE_MANAGER__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_view_setting_common_image_play_callback
 * DESCRIPTION
 *  Play callback for image display 
 * PARAMETERS
 *  result    :    [IN] GDI error code
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_view_setting_common_image_play_callback(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phnset_view_setting_common_play_callback(result, MMI_FALSE);
    }

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_view_setting_common_video_play_callback
 * DESCRIPTION
 *  Video play callback function for wallpaper and screen saver 
 * PARAMETERS
 *  result    : [IN]    MDI error code
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_view_setting_common_video_play_callback(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phnset_view_setting_common_play_callback(result, MMI_TRUE);    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_view_setting_entry_common_file_preview
 * DESCRIPTION
 *  This function is to preview user define wallpaper/screensaver
 *  Following Function:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_view_setting_entry_common_file_preview(MMI_ID parent_gid, WCHAR* file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        if(mmi_phnset_entry_group_check_ex(parent_gid,GRP_ID_VIEW_SETTING_FILE_COMMON_PREVIEW))
            return;

    mmi_frm_group_create_ex(
                         parent_gid,
                         GRP_ID_VIEW_SETTING_FILE_COMMON_PREVIEW,
                         mmi_phnset_view_setting_common_fmgr_proc,
                         NULL,
                         MMI_FRM_NODE_SMART_CLOSE_FLAG);                        
#ifdef __MMI_IMAGE_CLIP_CUI__
	if(cui_image_clip_is_file_format_supported(file_name))
	{
		mmi_phnset_display_launch_image_clip_cui(GRP_ID_VIEW_SETTING_FILE_COMMON_PREVIEW, file_name);
	}
	else
#endif
	{
        mmi_frm_scrn_first_enter(
            GRP_ID_VIEW_SETTING_FILE_COMMON_PREVIEW,
            SCR_ID_VIEW_SETTING_COMMON_FILE_PREVIEW,
            (FuncPtr)mmi_phnset_view_setting_entry_common_file_preview_int,
            file_name);
    }
}

static mmi_ret mmi_phnset_view_setting_waiting_popup_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_RET_PROHIBIT_SCRN_ENTER;
}

static void mmi_phnset_view_setting_entry_waiting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_WALLPAPER_TRACE_038);

    mmi_frm_scrn_enter(
        GRP_ID_VIEW_SETTING_FILE_COMMON_PREVIEW,
        SCR_ID_VIEW_SETTING_COMMON_WAITING_POPUP,
        NULL,
        mmi_phnset_view_setting_entry_waiting,
        MMI_FRM_FULL_SCRN);
    
    ShowCategory63Screen(
        (PU8) GetString(STR_GLOBAL_PLEASE_WAIT),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    mmi_frm_scrn_set_leave_proc(GRP_ID_VIEW_SETTING_FILE_COMMON_PREVIEW, SCR_ID_VIEW_SETTING_COMMON_WAITING_POPUP, mmi_phnset_view_setting_waiting_popup_leave_proc);

//    SetKeyHandler(MMI_dummy_function, KEY_END, KEY_EVENT_DOWN);
}

static void mmi_phnset_view_setting_close_waiting(void)
{
    if (mmi_frm_scrn_is_present(GRP_ID_VIEW_SETTING_FILE_COMMON_PREVIEW, SCR_ID_VIEW_SETTING_COMMON_WAITING_POPUP, MMI_FRM_NODE_ALL_FLAG))
	{
        mmi_frm_scrn_set_leave_proc(GRP_ID_VIEW_SETTING_FILE_COMMON_PREVIEW, SCR_ID_VIEW_SETTING_COMMON_WAITING_POPUP, NULL);
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_view_setting_confirm_to_set
 * DESCRIPTION
 *  check device status and storage before copy image or video file to root
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_view_setting_confirm_to_set(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phnset_view_setting_set_by_file(
        g_phnset_view_setting_view_type, 
        mmi_phnset_view_setting_common_get_src_file(),
        mmi_phnset_view_setting_common_fmgr_proc,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_view_setting_entry_common_file_preview_int
 * DESCRIPTION
 *  Internal entry function of WallPaper, Screen Saver and Power on off Display user defined resource preview screen 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_view_setting_entry_common_file_preview_int(mmi_scrn_essential_struct *scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MTK_TARGET__)
#if defined(__MMI_SCREENSAVER_DISPLAY_VIDEO__) || defined(__MMI_POWER_ON_OFF_DISPLAY_VIDEO__) || defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__) || defined (__MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__)
    U8 *gui_buffer; // Only used by video display category
    MMI_BOOL vol_is_on = MMI_FALSE;
	#ifndef __MMI_POWER_ON_OFF_MUTE__
	srv_prof_audio_id audio_id;   
	#endif
#endif
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_frm_scrn_enter(
        scrn_data->group_id,
        scrn_data->scrn_id,
        (FuncPtr)mmi_phnset_view_setting_exit_common_file_preview_func,
        (FuncPtr)mmi_phnset_view_setting_entry_common_file_preview_int,
        MMI_FRM_FULL_SCRN) 
        || scrn_data->user_data == NULL)
    {
        return;
    }
   


    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#if defined(__MTK_TARGET__)
#if defined(__MMI_SCREENSAVER_DISPLAY_VIDEO__) || defined(__MMI_POWER_ON_OFF_DISPLAY_VIDEO__) || defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__) || defined (__MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__)   
    gui_buffer = mmi_frm_scrn_get_gui_buf(scrn_data->group_id, scrn_data->scrn_id);
    if (srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) != SRV_PROF_RET_PROFILE_ACTIVATED)
	{
	    vol_is_on = MMI_TRUE;
	}
#ifdef __MMI_POWER_ON_OFF_DISPLAY_VIDEO__	
#ifndef __MMI_POWER_ON_OFF_MUTE__
	if (g_phnset_cntx_p->wpss_type == MMI_PHNSET_TYPE_PWRON || g_phnset_cntx_p->wpss_type == MMI_PHNSET_TYPE_PWROFF)
	{
		srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_POWER_ON_TONE + g_phnset_cntx_p->wpss_type - MMI_PHNSET_TYPE_PWRON, &audio_id);
		if(audio_id == SRV_PROF_TONE_NONE)
		{
			vol_is_on = MMI_FALSE;
		}
	}
#endif /* __MMI_POWER_ON_OFF_MUTE__ */
#endif /* __MMI_POWER_ON_OFF_DISPLAY_VIDEO__ */

#if defined(__MMI_SCREENSAVER_DISPLAY_VIDEO__) || defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__) || defined (__MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__)
    if (g_phnset_view_setting_view_type == MMI_PHNSET_TYPE_SS ||
		g_phnset_view_setting_view_type == MMI_PHNSET_TYPE_WP
		#ifdef __MMI_VUI_SCREEN_LOCK_KEY__
		|| g_phnset_view_setting_view_type == MMI_PHNSET_TYPE_SL_WP
		#endif
		)
	{
        /* Do not play audio when the preview is for screen saver */
	    vol_is_on = MMI_FALSE;
	}
#endif    
    if (srv_fmgr_types_find_group_by_filename_str((WCHAR*)scrn_data->user_data) == FMGR_GROUP_VIDEO)
    {
		mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGH_SCRN);
    #ifdef __DRM_SUPPORT__
        wgui_catvdo_set_drm_flag(WGUI_CATVDO_DRM_DISABLE_CONSUME_ALL);
    #endif /* __DRM_SUPPORT__ */
	if (g_phnset_view_setting_view_type == MMI_PHNSET_TYPE_WP
		#ifdef __MMI_VUI_SCREEN_LOCK_KEY__
		|| g_phnset_view_setting_view_type == MMI_PHNSET_TYPE_SL_WP
		#endif
		)
	{
		wgui_cat225_set_preview_vlw_scenario();/* notify vdo current wallpaper file is preview */
	}

#ifdef __MMI_BACKGROUND_CALL__
	if (srv_ucm_is_background_call() && vol_is_on)
	{
		mmi_ucm_app_entry_error_message();
		if (mmi_frm_scrn_is_present(GRP_ID_VIEW_SETTING_FILE_COMMON_PREVIEW, SCR_ID_VIEW_SETTING_COMMON_FILE_PREVIEW, MMI_FRM_NODE_ALL_FLAG))
		{
			mmi_frm_scrn_close(GRP_ID_VIEW_SETTING_FILE_COMMON_PREVIEW, SCR_ID_VIEW_SETTING_COMMON_FILE_PREVIEW);
		}
		return;
	}
#endif /* __MMI_BACKGROUND_CALL__ */

        ShowCategory225Screen(
            STR_GLOBAL_PLAY,            /* title_str */
            IMG_SCR_SETTING_CAPTION,    /* title_icon */
            STR_GLOBAL_OK,              /* lsk_str */
            IMG_GLOBAL_OK,              /* lsk_icon */
            STR_GLOBAL_BACK,            /* rsk_str */
            IMG_GLOBAL_BACK,            /* rsk_icon */
            0,                          /* video_id */
            (CHAR*)scrn_data->user_data,  /* video_filename */
            0,                          /* repeat_count */
            TRUE,                       /* is_visual_update */
            vol_is_on,                  /* is_play_audio */
            TRUE,                       /* is_lcd_no_sleep */
            GDI_COLOR_WHITE,            /* bg_color */
            mmi_phnset_view_setting_common_video_play_callback,
            gui_buffer);
    }
    else
#endif /* defined(__MMI_SCREENSAVER_DISPLAY_VIDEO__) || defined(__MMI_POWER_ON_OFF_DISPLAY_VIDEO__) */ 
#endif /* defined(__MTK_TARGET__) */  
    {
		wgui_cat222_disable_err_msg_display();
		ShowCategory222Screen(
			STR_GLOBAL_VIEW,
			IMG_SCR_SETTING_CAPTION,
			STR_GLOBAL_OK,
			IMG_GLOBAL_OK,
			STR_GLOBAL_BACK,
			IMG_GLOBAL_BACK,
			GDI_COLOR_WHITE,
			NULL,
			(CHAR*) scrn_data->user_data,
			FALSE,
		    mmi_phnset_view_setting_common_image_play_callback,
			GDI_IMAGE_SRC_FROM_FILE);
    }

    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_phnset_view_setting_confirm_to_set, KEY_EVENT_UP);      
    SetCenterSoftkeyFunction(mmi_phnset_view_setting_confirm_to_set, KEY_EVENT_UP);      
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_view_setting_exit_common_file_preview_func
 * DESCRIPTION
 *  This function is exit function for IdleScreenDisplay->Wallpaper->User Define
 *  Following Function:
 * PARAMETERS
 *  path            [?]             
 *  is_short        [IN]            
 *  a(?)            [IN/OUT]        Void
 *  b(?)            [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phnset_view_setting_exit_common_file_preview_func(mmi_scrn_essential_struct *scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
#if defined(__MTK_TARGET__)
#if defined(__MMI_SCREENSAVER_DISPLAY_VIDEO__) || defined(__MMI_POWER_ON_OFF_DISPLAY_VIDEO__) || defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__) || defined (__MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__)    
	if (srv_fmgr_types_find_group_by_filename_str((WCHAR*)scrn_data->user_data) == FMGR_GROUP_VIDEO)
	{
		
		mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGH_SCRN);
	}
#endif
#endif
}

static void mmi_phnset_view_setting_display_error_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phnset_view_setting_error_string_id)
    {
		mmi_popup_display_simple_ext(g_phnset_view_setting_error_string_id, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
    }
    else if (*g_phnset_view_setting_error_string_ptr)
    {
       mmi_popup_display_simple((WCHAR*)g_phnset_view_setting_error_string_ptr, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
    }
    else        
    {
#ifndef __MMI_MAINLCD_96X64__
		mmi_popup_display_simple_ext(STR_WP_IDLE_WP_DECODE_ERR, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
#endif
    }
    g_phnset_view_setting_error_string_id = 0;
    g_phnset_view_setting_error_string_ptr = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_view_setting_pre_check_file
 * DESCRIPTION
 *  This function is call back function for IdleScreenDisplay->Wallpaper->User Define
 *  Following Function:
 * PARAMETERS
 *  path            [?]             
 *  is_short        [IN]            
 *  a(?)            [IN/OUT]        Void
 *  b(?)            [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_phnset_view_setting_pre_check_file(void *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!path)
    {
        return MMI_FALSE;
    }
    
    if(!mmi_phnset_view_setting_util_check_file_limit(g_phnset_view_setting_view_type, path)
#ifdef __DRM_SUPPORT__        
        || mmi_phnset_view_setting_util_check_drm(path)!= PHNSET_WP_SS_SET_NO_ERROR
#endif /* __DRM_SUPPORT__ */
        )
    {
        return MMI_FALSE;
    }


    return MMI_TRUE;
}

static void mmi_phnset_view_setting_common_set_src_file(const WCHAR* file_name)
{
    ASSERT(g_phnset_view_setting_src_file_name == NULL);
   
    g_phnset_view_setting_src_file_name = OslMalloc(SRV_FMGR_PATH_BUFFER_SIZE);
    mmi_ucs2cpy((CHAR*)g_phnset_view_setting_src_file_name, (const CHAR*)file_name);
}

static WCHAR* mmi_phnset_view_setting_common_get_src_file(void)
{
    return g_phnset_view_setting_src_file_name;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_view_setting_common_fmgr_proc
 * DESCRIPTION
 *  Proc function for file manager cui used in wallpaper screen saver and power
 *  on off display 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phnset_view_setting_common_fmgr_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //FMGR_FILE_INFO_STRUCT file_info;
    srv_fmgr_fileinfo_struct file_info;
    static WCHAR *file_path_buf_ptr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    case EVT_ID_GROUP_DEINIT:
    case EVT_ID_GROUP_DELETE_REQ:
    case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:        
        mmi_phnset_view_setting_cache_free_buf();
        if (file_path_buf_ptr)
    	{
            OslMfree(file_path_buf_ptr);
            file_path_buf_ptr = NULL;
    	}        
    	break;
    case EVT_ID_CUI_FILE_SELECTOR_RESULT:
    {
        cui_file_selector_result_event_struct *fmgr_result_evt = (cui_file_selector_result_event_struct*)evt;
        if (fmgr_result_evt->result <= 0)
    	{
    	    cui_file_selector_close(fmgr_result_evt->sender_id);
    	}
        else
        {
            file_path_buf_ptr = (WCHAR*)OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR));
            
            cui_file_selector_get_selected_filepath(
                mmi_frm_group_get_active_id(),
                &file_info,
                (WCHAR*)file_path_buf_ptr,
                (SRV_FMGR_PATH_MAX_LEN + 1) * 2);
              
            if (mmi_phnset_view_setting_pre_check_file((void*)file_path_buf_ptr))
            {
                mmi_phnset_view_setting_common_set_src_file(file_path_buf_ptr);
                mmi_phnset_view_setting_entry_common_file_preview(GRP_ID_VIEW_SETTING_COMMON_FMGR, mmi_phnset_view_setting_common_get_src_file());
            }
            else
            {
                mmi_phnset_view_setting_display_error_popup();
            }
        }
        if (file_path_buf_ptr)
    	{
		    OslMfree(file_path_buf_ptr);
		    file_path_buf_ptr = NULL;
        } 
        break;
    }
    case EVT_ID_SETTING_DISPLAY_SETTING_DONE:
    {
	    mmi_setting_display_setting_event_struct *result_evt = (mmi_setting_display_setting_event_struct*)evt;
        if (result_evt->result == MMI_TRUE)
    	{
    	    mmi_frm_group_close(GRP_ID_VIEW_SETTING_FILE_COMMON_PREVIEW);
    	    mmi_frm_group_close(GRP_ID_VIEW_SETTING_COMMON_FMGR);
    	}
        else
        {
            mmi_popup_display_simple_ext(
                mmi_phnset_view_setting_util_get_error_string(result_evt->error_code), 
                MMI_EVENT_FAILURE, 
                GRP_ID_ROOT, 
                NULL);

    	    mmi_frm_group_close(GRP_ID_VIEW_SETTING_FILE_COMMON_PREVIEW);
        }
		break;
    }
	#ifdef __MMI_IMAGE_CLIP_CUI__
	
	case EVT_ID_CUI_IMAGE_CLIP_RESULT_SUCCESS:
	{
		cui_image_clip_evt_struct *event = (cui_image_clip_evt_struct*)evt;
		mmi_phnset_view_setting_cache_free_buf();
		
		if (!mmi_fmgr_util_file_limit_check(g_mmi_view_setting_limit_table[g_phnset_view_setting_view_type], (CHAR*)event->save_file_path, (CHAR**)&g_phnset_view_setting_error_string_ptr))
		{
			mmi_phnset_view_setting_display_error_popup();
		}
		else
		{
		    mmi_phnset_view_setting_common_set_src_file(event->save_file_path);
		    mmi_phnset_view_setting_confirm_to_set();
		}
		break;
	}
	
	case EVT_ID_CUI_IMAGE_CLIP_CLOSE_REQUEST:
	{
		cui_image_clip_evt_struct *event = (cui_image_clip_evt_struct*)evt;
		cui_image_clip_close(event->sender_id);
		break;
    }
		
	#endif /* __MMI_IMAGE_CLIP_CUI__ */
	
    default:
        break;    	
    }
    return MMI_RET_OK;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_view_setting_common_entry_fmgr
 * DESCRIPTION
 *  This function is Entry function for Setting->Phonesetup->IdleScreenDisplay->Wallpaper (->Fix) -> User Define
 *  Follow functions:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        Void
 *  b(?)        [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_view_setting_common_entry_fmgr(MMI_ID parent_gid, U32 view_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FILE_MANAGER__)
    FMGR_FILTER filter;
    MMI_ID fmgrcui_id;
#endif    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_FILE_MANAGER__) 
    
    if(mmi_phnset_entry_group_check_ex(parent_gid,GRP_ID_VIEW_SETTING_COMMON_FMGR))
        return;
    mmi_frm_group_create_ex(
        parent_gid,
        GRP_ID_VIEW_SETTING_COMMON_FMGR,
        mmi_phnset_view_setting_common_fmgr_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    FMGR_FILTER_INIT(&filter);

    g_phnset_view_setting_view_type = view_type;
    mmi_phnset_view_setting_util_set_file_filter(&filter, (phnset_wpss_type_enum)g_phnset_view_setting_view_type);

    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);

    fmgrcui_id = cui_file_selector_create(
        GRP_ID_VIEW_SETTING_COMMON_FMGR,
        L"root",
        &filter,
        CUI_FILE_SELECTOR_STYLE_FILE_ONLY,
        CUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_ALL | CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON);
    cui_file_selector_set_title(
        fmgrcui_id,
        0,
        MAIN_MENU_TITLE_SETTINGS_ICON);

    cui_file_selector_run(fmgrcui_id);

#endif /* defined(__MMI_FILE_MANAGER__) */ 

}

static mmi_ret mmi_phnset_view_setting_forward_from_fmgr_int(mmi_event_struct *param)
{
	mmi_phnset_view_setting_entry_common_file_preview(GRP_ID_ROOT, mmi_phnset_view_setting_common_get_src_file());
	return MMI_RET_OK;
}

void mmi_phnset_view_setting_common_forward_from_fmgr(U32 view_type, const WCHAR *path, filetypes_file_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_PHNSET_WP_FWFROM_FMGR, path, 1);

    if (!mmi_phnset_view_setting_util_check_file_type(type, (phnset_wpss_type_enum)view_type))
	{
		mmi_popup_display_simple((WCHAR*) GetString(STR_GLOBAL_UNSUPPORTED_FORMAT), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
        return;	    
	}
    if (path)
    {

        /* file limitation check - limitation is define in file manager util */
        if (!mmi_phnset_view_setting_util_check_file_limit(view_type, path))
        {
            mmi_phnset_view_setting_display_error_popup();
            return;
        }

        /* Prevent memory leck, after buffer is free, set pointer to NULL */
        if (mmi_phnset_view_setting_common_get_src_file())
		{
			mmi_popup_display_simple_ext(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
			return;
		}
        
        mmi_phnset_view_setting_common_set_src_file(path);

        g_phnset_view_setting_view_type = view_type;

        /* Use post event handler the preview screen to avoid stack overflow Cong Zhou 10/06/01*/
        MMI_FRM_INIT_EVENT(&evt, 0);
        mmi_frm_post_event(&evt, mmi_phnset_view_setting_forward_from_fmgr_int, NULL);
    }
    else
    {
		mmi_popup_display_simple_ext(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_view_setting_common_dev_plug_out_hdlr
 * DESCRIPTION
 *  FMGR notification handler for wallpaper, screensaver and power on off display 
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_phnset_view_setting_common_dev_plug_out_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp;
    WCHAR *file_name;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FILE_MANAGER__
    if (param->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT)
    {
        if (!mmi_frm_scrn_is_present(GRP_ID_VIEW_SETTING_FILE_COMMON_PREVIEW, SCR_ID_VIEW_SETTING_COMMON_FILE_PREVIEW, MMI_FRM_NODE_ALL_FLAG))
        {
            MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_WALLPAPER_TRACE_002);
            return MMI_RET_OK;
        }
        file_name = mmi_phnset_view_setting_common_get_src_file();
        
        temp = FS_GetDevStatus((U8)file_name[0], FS_MOUNT_STATE_ENUM);
        MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_WALLPAPER_TRACE_003, temp);

        /* verify device status of preview file is OK */
        /* when preview a file in flash and plug out memory card, return directly */
        if (temp == FS_NO_ERROR)
        {
            MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_WALLPAPER_TRACE_005);
            return MMI_RET_OK;
        }
        
        temp = FS_GetDevStatus(FS_DEVICE_TYPE_CARD, FS_MOUNT_STATE_ENUM);
        MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_WALLPAPER_TRACE_004, temp);

        mmi_phnset_view_setting_close_waiting();
        mmi_frm_group_close(GRP_ID_VIEW_SETTING_FILE_COMMON_PREVIEW);
    }
#endif /* __MMI_FILE_MANAGER__ */
    return MMI_RET_OK;    
}

#ifdef __MMI_IMAGE_CLIP_CUI__
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_display_launch_image_clip_cui
 * DESCRIPTION
 *  FMGR notification handler for wallpaper, screensaver and power on off display 
 *  launch image clipper cui
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static void mmi_phnset_display_launch_image_clip_cui(mmi_id parent_id, WCHAR* file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_id;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	cui_id = cui_image_clip_create(parent_id, file_name, NULL);
	
	cui_image_clip_set_dest_size(cui_id, LCD_WIDTH, LCD_HEIGHT);
	
	cui_image_clip_run(cui_id);
}

#endif /* __MMI_IMAGE_CLIP_CUI__ */
#endif /* __MMI_FILE_MANAGER__ */
