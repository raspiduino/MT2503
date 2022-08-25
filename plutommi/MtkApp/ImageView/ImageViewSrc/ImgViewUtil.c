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
 *  ImgViewerUtil.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Utils of Imageviewer App.
 *
 * Author:
 * -------
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
 ****************************************************************************/

#include "MMI_features.h"
#include "GlobalResDef.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_lcd_config.h"
#include "gdi_include.h"

#include "mmi_frm_nvram_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_trc_int.h"
#include "Wgui_categories_util.h"
#include "wgui_categories_text_viewer.h"
#include "AlertScreen.h"
#include "FileMgrServiceResDef.h"
#include "mmi_rp_srv_filemanager_def.h"

#include "ImgViewerGprot.h"
#include "mmi_rp_app_imageviewer_def.h"

static U16 g_storage = MMI_MEDIA_INVALID_STORAGE;   /* default value */
static S32 mmi_imgview_create_file_dir(U16);




/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_get_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_imgview_get_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_storage == MMI_MEDIA_INVALID_STORAGE)
    {
        /* load format setting */
        ReadValueSlim(NVRAM_IMGVIEW_STORAGE, &g_storage, DS_SHORT);
        if (g_storage == MMI_MEDIA_INVALID_STORAGE)
        {
            g_storage = (U16) SRV_FMGR_PUBLIC_DRV;
            WriteValueSlim(NVRAM_IMGVIEW_STORAGE, &g_storage, DS_SHORT);
        }
    }

    return g_storage;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_set_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_imgview_set_storage(U16 drv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S32 ret = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drv != MMI_MEDIA_INVALID_STORAGE)
    {
        ret = mmi_imgview_create_file_dir(drv);
        if (ret < 0)
        {
            return ret;
        }
    }

    if (drv != g_storage)
    {
        WriteValue(NVRAM_IMGVIEW_STORAGE, &drv, DS_SHORT, &error);
    }

    g_storage = drv;

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_get_storage_file_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filepath        [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_imgview_get_storage_file_path(WCHAR *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 storage;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(filepath);
    storage = mmi_imgview_get_storage();
    ret = FS_GetDevStatus(storage, FS_MOUNT_STATE_ENUM);
    if (ret != FS_NO_ERROR)
    {
        return ret;
    }

    ret = mmi_imgview_create_file_dir(storage);
    if (ret != FS_NO_ERROR)
    {
        return ret;
    }

    kal_wsprintf(filepath, "%c:\\%w", (U8) g_storage, FMGR_DEFAULT_FOLDER_PHOTOS);
    return FS_NO_ERROR;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_create_file_dir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_imgview_create_file_dir(U16 drv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fmgrRet;
    WCHAR filepath[MMI_MEDIA_MAX_PATH_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(filepath, "%c:\\%w", (U8) drv, FMGR_DEFAULT_FOLDER_PHOTOS);
    fmgrRet = srv_fmgr_fs_create_folder(filepath);

    if (fmgrRet < FS_NO_ERROR)
    {
        return fmgrRet;
    }

    fmgrRet = FS_GetAttributes(filepath);
    if (!(fmgrRet & FS_ATTR_DIR))
    {
        return FS_FILE_EXISTS;
    }

    return FS_NO_ERROR;
}


#ifdef __MMI_AP_DCM_CAMIMGV__
#pragma arm section rodata = "DYNAMIC_CODE_CAMIMGV_RODATA",code = "DYNAMIC_CODE_CAMIMGV_ROCODE"
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_is_storage_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_imgview_is_storage_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_storage != MMI_MEDIA_INVALID_STORAGE);
}

typedef struct
{
    MMI_ID parent_id;
    const WCHAR *path;
} img_info_data_t;

/*****************************************************************************
 * FUNCTION
 *  cui_iv_convert_format_size
 * DESCRIPTION
 *  convert size format
 * PARAMETERS
 *  file_size           [IN]        
 *  buffer              [?]         
 *  buffer_length       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_iv_convert_format_size(U64 file_size, U16 *buffer, S32 buffer_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const char postfix[] = { "BKMG" };
    U64 unit = 1;
    S32 i = 0;
    U32 part_int, part_mod;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (file_size >= 1024 * unit && postfix[i] != 'G')
    {
        unit *= 1024;
        i++;
    }

    part_int = (U32) (file_size / unit);
    part_mod = (U32) (((file_size % unit) * 10) / unit);

    if (part_mod)
    {
        kal_wsprintf(buffer, "%d.%d%c", part_int, part_mod, postfix[i]);
    }
    else
    {
        kal_wsprintf(buffer, "%d%c", part_int, postfix[i]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_image_info_print_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filepath        [IN]        
 *  buffer          [?]         
 * RETURNS
 *  
 *****************************************************************************/
static S32 cui_iv_image_info_print_buffer(const WCHAR *filepath, WCHAR *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
    srv_fmgr_fileinfo_struct fileinfo;
    WCHAR *name_ptr, time_str[MAX_SUBMENU_CHARACTERS], size_str[MAX_SUBMENU_CHARACTERS];
    GDI_RESULT gdi_ret;
    S32 width;
    S32 height;
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    name_ptr = srv_fmgr_path_get_filename_ptr((WCHAR*) filepath);
    srv_fmgr_fs_path_get_fileinfo(filepath, &fileinfo);
    gdi_ret = gdi_image_get_dimension_file((CHAR*) filepath, &width, &height);

    /* Filename */
    kal_wsprintf(buffer, "%w\n", GetString(STR_ID_IMGVIEW_OPTION_IMG_INFO_FILENAME));
    str_len = kal_wstrlen(name_ptr);
    if (str_len >= MAX_SUBMENU_CHARACTERS)
    {
        kal_wstrncat(buffer, name_ptr, MAX_SUBMENU_CHARACTERS - 2);
        kal_wstrcat(buffer, L"..");
    }
    else
    {
        kal_wstrcat(buffer, name_ptr);
    }
    count++;

    /* Image dimention */
    if (gdi_ret == GDI_SUCCEED)
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
    cui_iv_convert_format_size(fileinfo.size, size_str, MAX_SUBMENU_CHARACTERS);
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


/*****************************************************************************
 * FUNCTION
 *  cui_iv_jpg_info_print_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  exif_info       [?]     
 *  buffer          [?]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 cui_iv_jpg_info_print_buffer(gdi_image_jpeg_exif_info_struct *exif_info, WCHAR *buffer)
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

#endif /* __MMI_EXIF__ */ /* #ifdef __MMI_EXIF__ */

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  cui_iv_img_info_scrn_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret cui_iv_img_info_scrn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_frm_scrn_active_evt_struct *act_evt = (mmi_frm_scrn_active_evt_struct*) evt;
            img_info_data_t *pdata = (img_info_data_t*) act_evt->user_data;
            FS_HANDLE fs_handle;
            gdi_image_jpeg_exif_info_struct exif_info;
            GDI_RESULT result = GDI_SUCCEED;
            S16 count = 0;

            MMI_ASSERT(pdata->path != NULL);

            /* check for device status */
            fs_handle = FS_Open(pdata->path, FS_READ_ONLY);
            if (fs_handle < FS_NO_ERROR)
            {
                if (mmi_frm_is_in_backward_scenario())
                {
                    mmi_frm_scrn_close_active_id();
                    break;;
                }
                else
                {
                    mmi_popup_display_simple(
                        (WCHAR*) GetString(srv_fmgr_fs_error_get_string(fs_handle)),
                        (mmi_event_notify_enum) srv_fmgr_fs_error_get_popup_type(fs_handle),
                        pdata->parent_id,
                        NULL);

                    mmi_frm_scrn_close(pdata->parent_id, SCR_ID_IMGVIEW_IMG_INFO);
                    break;
                }
            }
            else
            {
                FS_Close(fs_handle);
            }

            *((WCHAR*) subMenuData) = 0;
            /* Get basic infomation */
            count = cui_iv_image_info_print_buffer(pdata->path, (WCHAR*) subMenuData);
            /* Get exif information */
            result = gdi_image_jpeg_get_exif_info((CHAR*) pdata->path, &exif_info);
            if (result != GDI_FAILED)
            {
                S32 str_len = (kal_wstrlen((WCHAR*)subMenuData));
                WCHAR *exifBufPtr = (WCHAR*)subMenuData + (str_len + 1);
                S16 exifCount = cui_iv_jpg_info_print_buffer(&exif_info, exifBufPtr);

                if (0 < exifCount)
                {
                    *(exifBufPtr - 1) = '\n';
                }
                count += exifCount;
            }

            if (count == 0)
            {
            #ifdef __PLUTO_MMI_PACKAGE__
                kal_wstrcpy((WCHAR*) subMenuData, (const WCHAR*)GetString(STR_ID_FMGR_EXIF_NO_INFORMATION));
            #endif 
            }

            ShowCategory74Screen(
                STR_ID_IMGVIEW_OPTION_IMG_INFO,
                GetRootTitleIcon(MENU_ID_IMGVIEW_OPTION_IMG_INFORMATION),
                0,
                0,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                (PU8) subMenuData,
                MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
                act_evt->gui_buffer);
        }
            break;

        case EVT_ID_SCRN_DEINIT:
        {
            OslMfree(evt->user_data);
        }
            break;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_show_img_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_gid      [IN]        
 *  filepath        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_imgview_show_img_info(MMI_ID parent_gid, const WCHAR *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    img_info_data_t *pdata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pdata = OslMalloc(sizeof(img_info_data_t));

    pdata->parent_id = parent_gid;
    pdata->path = filepath;

    mmi_frm_scrn_create(parent_gid, SCR_ID_IMGVIEW_IMG_INFO, cui_iv_img_info_scrn_proc, pdata);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_is_image_type_printable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image_type      [IN]        
 *  method          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
extern BOOL mmi_imgview_is_image_type_printable(filetypes_file_type_enum image_type, mmi_imgview_print_method_enum method)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_init_img_filter
 * DESCRIPTION
 *
 * PARAMETERS
 *  filter          [IN]
 * RETURNS
 *
 *****************************************************************************/
extern void mmi_imgview_init_img_filter(FMGR_FILTER *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(filter);
    FMGR_FILTER_SET_IMAGE(filter);
    FMGR_FILTER_CLEAR(filter, FMGR_TYPE_ANM);
    FMGR_FILTER_CLEAR(filter, FMGR_TYPE_EMS);
    FMGR_FILTER_CLEAR(filter, FMGR_TYPE_SVG);
#if defined(__DRM_V02__)
    FMGR_FILTER_SET(filter, FMGR_TYPE_ODF);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_adjust_resize_size
 * DESCRIPTION
 *
 * PARAMETERS
 *  type        [IN]
 *  width       [IN/OUT]
 *  height      [IN/OUT]
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_imgview_adjust_resize_size(U16 type, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(type)
    {
        case GDI_IMAGE_TYPE_BMP:
        case GDI_IMAGE_TYPE_BMP_FILE:
        case GDI_IMAGE_TYPE_BMP_FILE_OFFSET:
        case GDI_IMAGE_TYPE_BMP_MEM:
        case GDI_IMAGE_TYPE_BMP_SEQUENCE:
        case GDI_IMAGE_TYPE_BMP_SEQUENCE_FILE_OFFSET:
        case GDI_IMAGE_TYPE_WBMP:
        case GDI_IMAGE_TYPE_WBMP_FILE:
        case GDI_IMAGE_TYPE_WBMP_FILE_OFFSET:
            {
                if ((*width) > GDI_MAX_RESIZE_WIDTH)
                {
                    (*height) = (*height) * GDI_MAX_RESIZE_WIDTH / (*width);
                    (*width) = GDI_MAX_RESIZE_WIDTH;
                }
            }
            break;

        default:
            break;
    }
}
#ifdef __MMI_AP_DCM_CAMIMGV__
#pragma arm section rodata,code
#endif


