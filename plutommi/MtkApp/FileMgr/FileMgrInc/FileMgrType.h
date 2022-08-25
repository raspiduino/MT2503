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

/*******************************************************************************
 * Filename:
 * ---------
 *  FileManagerDef.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File Manager internal prototype header.
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _FMGR_TYPE_H_
#define _FMGR_TYPE_H_

/****************************************************************************
* Include Files
*****************************************************************************/
#include "MMI_features.h"
#include "mmi_rp_file_type_def.h"

#include "kal_general_types.h"
/****************************************************************************
* Define
*****************************************************************************/

typedef filetypes_file_type_enum mmi_fmgr_filetype_enum;
typedef filetypes_group_type_enum fmgr_file_group_enum;

#define FMGR_TYPE_FOLDER_DOT    FMGR_TYPE_FOLDER

#define FMGR_FILTER_SET_AUDIO(f)        srv_fmgr_types_filter_set_group(f, FMGR_GROUP_AUDIO)
#define FMGR_FILTER_IS_SET_AUDIO(f)     srv_fmgr_types_filter_is_in_group(f, FMGR_GROUP_AUDIO)

#define FMGR_FILTER_SET_IMAGE(f)        srv_fmgr_types_filter_set_group(f, FMGR_GROUP_IMAGE)
#define FMGR_FILTER_IS_SET_IMAGE(f)     srv_fmgr_types_filter_is_in_group(f, FMGR_GROUP_IMAGE)

#define FMGR_FILTER_SET_VIDEO(f)        srv_fmgr_types_filter_set_group(f, FMGR_GROUP_VIDEO)
#define FMGR_FILTER_IS_SET_VIDEO(f)     srv_fmgr_types_filter_is_in_group(f, FMGR_GROUP_VIDEO)

#define FMGR_FILTER_SET_SWFLASH(f)      srv_fmgr_types_filter_set_group(f, FMGR_GROUP_SWFLASH)
#define FMGR_FILTER_IS_SET_SWFLASH(f)   srv_fmgr_types_filter_is_in_group(f, FMGR_GROUP_SWFLASH)

#define FMGR_FILTER_SET_STREAM(f)        srv_fmgr_types_filter_set_group(f, FMGR_GROUP_STREAM)
#define FMGR_FILTER_IS_SET_STREAM(f)     srv_fmgr_types_filter_is_in_group(f, FMGR_GROUP_STREAM)

/****************************************************************************/
/*
 *  File type defaul folder information
 */

#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define FMGR_DEFAULT_FOLDER_EBOOKS      L"Ebook\\"
#define FMGR_DEFAULT_FOLDER_PHOTOS      L"Photos\\"
#define FMGR_DEFAULT_FOLDER_RECEIVED    L"Received\\"
#endif 

#define FMGR_DEFAULT_FOLDER_PHBIMAGES   "Phbimage"
#define FMGR_DEFAULT_FILE_PHBVIDEO      L"phb_video.dat"

/* default path */
extern kal_wchar CUSTOM_AT_AUDIO_DOWNLOAD_FOLDER_NAME[];
extern kal_wchar CUSTOM_AT_IMAGE_DOWNLOAD_FOLDER_NAME[];

#define FMGR_DEFAULT_FOLDER_IMAGES      CUSTOM_AT_IMAGE_DOWNLOAD_FOLDER_NAME
#define FMGR_DEFAULT_FOLDER_AUDIO       CUSTOM_AT_AUDIO_DOWNLOAD_FOLDER_NAME
#define FMGR_DEFAULT_FOLDER_VIDEO       L"Videos\\"  
#define FMGR_DEFAULT_FOLDER_SWFLASH     L"SWFlash\\"
#define FMGR_DEFAULT_FOLDER_LANGLN      L"Englishto\\"
#define FMGR_DEFAULT_FOLDER_TEMP        L"Download\\"
#define FMGR_DEFAULT_FOLDER_THEMES      L"Themes\\"
#ifdef __MMI_OP01_BARCODEREADER__
/* under construction !*/
#else
    #define FMGR_DEFAULT_FOLDER_BARCODE     L"Data\\"
#endif
#define FMGR_DEFAULT_FOLDER_MMSBOX      L"MMSBox\\"
#define FMGR_DEFAULT_FOLDER_ROOT        L"\\"

/****************************************************************************/
/*
 *  File type limit infomrmation
 */
/* file limit */
#include "drv_gfx_codec_limitation.h"

#ifndef __COSMOS_MMI__
//#define FMGR_LIMIT_IMAGE_VIEWER         g_fmgr_image_viewer_limit_arry
//#define FMGR_LIMIT_SCREEN_SAVER         g_fmgr_screensaver_limit_arry
//#define FMGR_LIMIT_WALLPAPER            g_fmgr_wallpaper_limit_arry
#define FMGR_LIMIT_IMAGE_VIEWER         GFX_USER_IMAGE_VIEWER
#define FMGR_LIMIT_SCREEN_SAVER         GFX_USER_SCREEN_SAVER
#define FMGR_LIMIT_WALLPAPER            GFX_USER_WALLPAPER

#ifdef __MMI_SUB_WALLPAPER__
//#define FMGR_LIMIT_SUB_WALLPAPER        g_fmgr_sub_wallpaper_limit_arry
#define FMGR_LIMIT_SUB_WALLPAPER        GFX_USER_SUB_WALLPAPER
#endif 
//#define FMGR_LIMIT_POWER_ON_OFF_DSPL    g_fmgr_power_on_off_disp_limit_arry
//#define FMGR_LIMIT_CALLER_PICTURE       g_fmgr_caller_picture_limit_arry
//#define FMGR_LIMIT_CALLER_VIDEO         g_fmgr_caller_video_limit_arry
//#define FMGR_LIMIT_MMS_CATEGORY         g_fmgr_mms_category_limit_arry
#define FMGR_LIMIT_POWER_ON_OFF_DSPL    GFX_USER_POWER_ON_OFF_DISPLAY
#define FMGR_LIMIT_CALLER_PICTURE       GFX_USER_CALLER_PICTURE
#define FMGR_LIMIT_CALLER_VIDEO         GFX_USER_CALLER_VIDEO
#define FMGR_LIMIT_MMS_CATEGORY         GFX_USER_MMS_CATEGORY

#ifdef __MMI_VIDEO_TELEPHONY__
//#define FMGR_LIMIT_VT_IMG       g_fmgr_vt_img_limit_arry
#define FMGR_LIMIT_VT_IMG       GFX_USER_VT_IMAGE
#endif /*__MMI_VIDEO_TELEPHONY__*/
#else
//#define FMGR_LIMIT_IMAGE_VIEWER (NULL)
//#define FMGR_LIMIT_SCREEN_SAVER (NULL)
//#define FMGR_LIMIT_WALLPAPER (NULL)
#define FMGR_LIMIT_IMAGE_VIEWER (GFX_USER_NONE)
#define FMGR_LIMIT_SCREEN_SAVER (GFX_USER_NONE)
#define FMGR_LIMIT_WALLPAPER (GFX_USER_NONE)

#ifdef __MMI_SUB_WALLPAPER__
//#define FMGR_LIMIT_SUB_WALLPAPER (NULL)
#define FMGR_LIMIT_SUB_WALLPAPER (GFX_USER_NONE)
#endif 
//#define FMGR_LIMIT_POWER_ON_OFF_DSPL (NULL)
//#define FMGR_LIMIT_CALLER_PICTURE (NULL)
//#define FMGR_LIMIT_CALLER_VIDEO (NULL)
//#define FMGR_LIMIT_MMS_CATEGORY (NULL)
#define FMGR_LIMIT_POWER_ON_OFF_DSPL (GFX_USER_NONE)
#define FMGR_LIMIT_CALLER_PICTURE (GFX_USER_NONE)
#define FMGR_LIMIT_CALLER_VIDEO (GFX_USER_NONE)
#define FMGR_LIMIT_MMS_CATEGORY (GFX_USER_NONE)

#ifdef __MMI_VIDEO_TELEPHONY__
//#define FMGR_LIMIT_VT_IMG (NULL)
#define FMGR_LIMIT_VT_IMG (GFX_USER_NONE)
#endif /*__MMI_VIDEO_TELEPHONY__*/
#endif

//extern const int g_fmgr_image_viewer_limit_arry[];
//extern const int g_fmgr_wallpaper_limit_arry[];
//extern const int g_fmgr_sub_wallpaper_limit_arry[];
//extern const int g_fmgr_screensaver_limit_arry[];
//extern const int g_fmgr_power_on_off_disp_limit_arry[];
//extern const int g_fmgr_caller_picture_limit_arry[];
//#ifdef __MMI_VIDEO_TELEPHONY__
//extern const int g_fmgr_vt_img_limit_arry[];
//#endif /*__MMI_VIDEO_TELEPHONY__*/
//extern const int g_fmgr_caller_video_limit_arry[];
//extern const int g_fmgr_mms_category_limit_arry[];


/****************************************************************************/
/*
 *  File type temp filename
 */
/* temp filename */
#define FMGR_TEMP_FILE_IRDA                  L"~received.tmp"
#define FMGR_TEMP_FILE_JAVA                  L"~java.tmp"
#define FMGR_TEMP_FILE_VCARD                 L"~vcard.tmp"
#define FMGR_TEMP_FILE_VCALENDAR             L"~vcalendar.tmp"
#define FMGR_TEMP_FILE_CAMERA                L"~camera.jpg"
#define FMGR_TEMP_FILE_MELODY                L"~rngc.imy"
#define FMGR_TEMP_FILE_EMAIL_NEW             L"~email.tmp"
#define FMGR_TEMP_FILE_EMAIL_SMTP            L"~smtp.tmp"
#define FMGR_TEMP_FILE_VIDEO_AUD             L"~video_aud.tmp"
#define FMGR_TEMP_FILE_VIDEO_AUD_SAMPLE      L"~video_aud_sample.tmp"
#define FMGR_TEMP_FILE_VIDEO_AUD_REAL        L"~video_aud_real.tmp"
#define FMGR_TEMP_FILE_VIDEO_VISUAL          L"~video_aud.tmp"
#define FMGR_TEMP_FILE_VIDEO_VISUAL_SAMPLE   L"~video_aud_sample.tmp"
#define FMGR_TEMP_FILE_VIDEO_VISUAL_REAL     L"~video_aud_real.tmp"
#define FMGR_TEMP_FILE_SWFLASH               L"~swflash.tmp"

/****************************************************************************/
/*
 * Notice. This enum must be sync with the size with the LID size in nvram_common_defs.h.
 * They must be wrapped with same compile options.
 *
 * "\mcu\custom\common\PLUTO_MMI\nvram_common_defs.h"
 */

typedef enum
{
#if defined (__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)
    FMGR_PATH_ID_CAMERA,
#endif

#if defined(__MMI_VIDEO_PLAYER__) || (defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__))
    FMGR_PATH_ID_VIDEO,
#endif 

#ifdef __MMI_PHOTOEDITOR__
    FMGR_PATH_ID_PHOTO_EDITOR,
#endif

#ifdef __MMI_SLIDESHOW__
    FMGR_PATH_ID_SLIDE_SHOW_AUDIO,
    FMGR_PATH_ID_SLIDE_SHOW_PLAY,
#endif

#ifdef __MMI_VIDEO_STREAM__
    FMGR_PATH_ID_VIDEO_STREAM,
#endif 

#ifdef __MMI_VIDEO_EDITOR__
    FMGR_PATH_ID_VIDEO_EDITOR,
#endif

#if defined(__MMI_IMAGE_VIEWER__) || defined(__MMI_FILE_MANAGER__)
    FMGR_PATH_ID_IMAGE_VIEWER,
#endif
    /* number of id */
    FMGR_PATH_ID_COUNT
} FMGR_PATH_ID_ENUM;


/****************************************************************************
* Global variable
*****************************************************************************/


/****************************************************************************
* Global Function
*****************************************************************************/


#endif /* _FMGR_TABLE_H_ */


