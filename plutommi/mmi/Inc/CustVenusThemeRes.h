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
 *  CustVenusThemeRes.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  External data type or function prototype for Venus theme
 *
 * Author:
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef __CUST_VENUS_THEME_RES_H__
#define __CUST_VENUS_THEME_RES_H__

#include "MMIDataType.h"

typedef struct
{
    S32 number;             /* number of system themes */
    U8** data_array_ptr;    /* pointer to system data array */
} mmi_res_theme_system_strcut;

/* data structure of theme font style */
typedef struct
{
    U8 size;        /* size: please refer to VfxFontDescSizeEnum of VfxFontDesc */
    U8 attribute;   /* attribute: please refer to font attribute flags define of VfxFontDesc */
    U8 effect;      /* effect: please refer to VfxFontDescEffectEnum of VfxFontDesc */
} mmi_res_theme_font_style_struct;

/* return value of Venus theme API */
typedef enum
{
    MMI_RES_THEME_RET_NO_ERROR = 0,                 /* No error */
    MMI_RES_THEME_RET_INVALID = -1,                 /* The theme is invalid, cannot apply */
    MMI_RES_THEME_BUF_NOT_ENOUGH = -2,              /* Buffer is not enought, cannot apply */
    MMI_RES_THEME_RET_PROJECT_NOT_MATCH = 1,        /* The project is not matched, but can still apply */
    MMI_RES_THEME_RET_VERSION_NOT_MATCH = 2,        /* The version is not matched, but can still apply */
    MMI_RES_THEME_RET_RESOLUTION_NOT_MATCH = 3,     /* The LCD resolution is not matched, but can still apply */

    MMI_RES_THEME_RET_END_OF_ENUM
} mmi_res_theme_ret_enum;

/* theme priority enum */
typedef enum
{
    MMI_RES_THEME_PRIORITY_HIGHT = 1,               /* Highest theme priority */
    MMI_RES_THEME_PRIORITY_MEDIUM = 128,            /* Medium theme priority */
    MMI_RES_THEME_PRIORITY_LOW = 250,               /* Lowest theme priority */
} mmi_res_theme_priority_enum;

/* theme handle */
typedef U32 mmi_res_theme_handle;

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_res_init_theme
 * DESCRIPTION
 *  initialize theme resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_res_init_theme(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_theme_count
 * DESCRIPTION
 *  get number of themes
 * PARAMETERS
 *  void
 * RETURNS
 *  number of themes
 *****************************************************************************/
extern S32 mmi_res_get_theme_count(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_set_system_theme
 * DESCRIPTION
 *  set one systeme theme as active
 * PARAMETERS
 *  index   [IN] index of the theme
 * RETURNS
 *  whether setting successfully or not
 *****************************************************************************/
extern MMI_BOOL mmi_res_set_system_theme(U8 index);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_set_otf_theme
 * DESCRIPTION
 *  set OTF theme structure
 * PARAMETERS
 *  void
 * RETURNS
 *  whether set successfully
 *****************************************************************************/
extern MMI_BOOL mmi_res_set_otf_theme(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_set_priority_theme
 * DESCRIPTION
 *  activate one theme with priority (sub-theme)
 * PARAMETERS
 *  index       [IN] index of the priority theme
 *  priority    [IN] priority of the theme, 1 is the highest, 250 is the lowest, otherers are reserved
 *  handle      [OUT] theme handle, can use the handle to close the theme
 * RETURNS
 *  mmi_res_theme_ret_enum
 *****************************************************************************/
extern mmi_res_theme_ret_enum mmi_res_set_priority_theme (U8 index, U8 priority, mmi_res_theme_handle *handle);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_is_theme_image
 * DESCRIPTION
 *  check whether the image is in theme
 * PARAMETERS
 *  id      [IN] resource ID
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mmi_res_is_theme_image(U16 id);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_theme_image
 * DESCRIPTION
 *  get image data from theme
 * PARAMETERS
 *  id      [IN] resource ID
 * RETURNS
 *  image data
 *****************************************************************************/
extern S8* mmi_res_get_theme_image(U16 id);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_theme_color
 * DESCRIPTION
 *  get color data from theme
 * PARAMETERS
 *  id      [IN] resource ID
 * RETURNS
 *  color
 *****************************************************************************/
extern S32 mmi_res_get_theme_color(U16 id);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_theme_font_style
 * DESCRIPTION
 *  get font data from theme
 * PARAMETERS
 *  id      [IN] resource ID
 * RETURNS
 *  font data
 *****************************************************************************/
extern mmi_res_theme_font_style_struct mmi_res_get_theme_font_style(U16 id);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_theme_integer
 * DESCRIPTION
 *  get integer data from theme
 * PARAMETERS
 *  id      [IN] resource ID
 * RETURNS
 *  integer data
 *****************************************************************************/
extern S32 mmi_res_get_theme_integer(U16 id);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_theme_audio
 * DESCRIPTION
 *  get audio data from theme
 * PARAMETERS
 *  id      [IN] resource ID
 * RETURNS
 *  audio data
 *****************************************************************************/
extern S8* mmi_res_get_theme_audio(U16 id);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_theme_binary
 * DESCRIPTION
 *  get binary data from theme
 * PARAMETERS
 *  id      [IN] resource ID
 * RETURNS
 *  binary data
 *****************************************************************************/
extern S8* mmi_res_get_theme_binary(U16 id);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_sys_theme_thumbnail
 * DESCRIPTION
 *  get thumbnail from theme
 * PARAMETERS
 *  index   [IN] index of the theme
 * RETURNS
 *  pointer to the thumbnail
 *****************************************************************************/
extern S8* mmi_res_get_sys_theme_thumbnail(U8 index);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_sys_theme_perview
 * DESCRIPTION
 *  get preview image from theme
 * PARAMETERS
 *  index   [IN] index of the theme
 * RETURNS
 *  pointer to the preview image
 *****************************************************************************/
extern S8* mmi_res_get_sys_theme_preview(U8 index);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_pri_theme_thumbnail
 * DESCRIPTION
 *  get thumbnail from priority theme
 * PARAMETERS
 *  data    [IN] data of the theme
 * RETURNS
 *  pointer to the thumbnail
 *****************************************************************************/
extern S8* mmi_res_get_pri_theme_thumbnail(U8* data);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_pri_theme_preview
 * DESCRIPTION
 *  get preview image from priority theme
 * PARAMETERS
 *  data    [IN] data of the theme
 * RETURNS
 *  pointer to the preview image
 *****************************************************************************/
extern S8* mmi_res_get_pri_theme_preview(U8* data);

#if defined(__NFB_THIRD_ROM_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_sys_theme_thumbnail_from_thirdrom
 * DESCRIPTION
 *  get theme thumbnail from third rom
 * PARAMETERS
 *  index    [IN] index of the theme
 *  buf       [OUT] buffer to store the thumbnail image
 *  buf_length  [IN] buffer length
 * RETURNS
 *  mmi_res_theme_ret_enum
 *****************************************************************************/
extern mmi_res_theme_ret_enum mmi_res_get_sys_theme_thumbnail_from_thirdrom(U8 index, S8* buf, S32 buf_length);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_sys_theme_preview_from_thirdrom
 * DESCRIPTION
 *  get theme preview from third rom
 * PARAMETERS
 *  index    [IN] index of the theme
 *  buf       [OUT] buffer to store the preview image
 *  buf_length  [IN] buffer length
 * RETURNS
 *  mmi_res_theme_ret_enum
 *****************************************************************************/
extern mmi_res_theme_ret_enum mmi_res_get_sys_theme_preview_from_thirdrom(U8 index, S8* buf, S32 buf_length);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_pri_theme_thumbnail_from_thirdrom
 * DESCRIPTION
 *  get thumbnail of priority theme from third rom
 * PARAMETERS
 *  index    [IN] index of the priority theme
 *  buf       [OUT] buffer to store the thumbnail image
 *  buf_length  [IN] buffer length
 * RETURNS
 *  mmi_res_theme_ret_enum
 *****************************************************************************/
extern mmi_res_theme_ret_enum mmi_res_get_pri_theme_thumbnail_from_thirdrom(U8 index, S8* buf, S32 buf_length);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_pri_theme_preview_from_thirdrom
 * DESCRIPTION
 *  get preview image of priority theme from third rom
 * PARAMETERS
 *  index    [IN] index of the priority theme
 *  buf       [OUT] buffer to store the preview image
 *  buf_length  [IN] buffer length
 * RETURNS
 *  mmi_res_theme_ret_enum
 *****************************************************************************/
extern mmi_res_theme_ret_enum mmi_res_get_pri_theme_preview_from_thirdrom(U8 index, S8* buf, S32 buf_length);
#endif /* defined(__NFB_THIRD_ROM_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_res_is_dlt_theme_valid
 * DESCRIPTION
 *  check whether the DLT theme file is valid
 * PARAMETERS
 *  filename    [IN] DLT theme filename
 * RETURNS
 *  mmi_res_theme_ret_enum
 *****************************************************************************/
extern mmi_res_theme_ret_enum mmi_res_is_dlt_theme_valid (const WCHAR* filename);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_set_dlt_theme
 * DESCRIPTION
 *  activate one downloadable theme
 * PARAMETERS
 *  filename    [IN] DLT theme filename
 * RETURNS
 *  mmi_res_theme_ret_enum
 *****************************************************************************/
extern mmi_res_theme_ret_enum mmi_res_set_dlt_theme (const WCHAR* filename);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_set_dlt_priority_theme
 * DESCRIPTION
 *  activate one downloadable theme with priority (sub-theme)
 * PARAMETERS
 *  filename    [IN] DLT theme filename
 *  priority    [IN] priority of the theme, 1 is the highest, 250 is the lowest, otherers are reserved
 *  handle      [OUT] theme handle, can use the handle to close the theme
 * RETURNS
 *  mmi_res_theme_ret_enum
 *****************************************************************************/
extern mmi_res_theme_ret_enum mmi_res_set_dlt_priority_theme (const WCHAR* filename, U8 priority, mmi_res_theme_handle *handle);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_app_icon_count
 * DESCRIPTION
 *  get number of app icon themes
 * PARAMETERS
 *  void
 * RETURNS
 *  number of app icon themes
 *****************************************************************************/
extern S32 mmi_res_get_app_icon_count(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_app_icon_data
 * DESCRIPTION
 *  get app icon theme data
 * PARAMETERS
 *  index   [IN] index of the app icon theme
 * RETURNS
 *  pointer to app icon data
 *****************************************************************************/
extern U8* mmi_res_get_app_icon_data(S32 index);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_close_curr_theme
 * DESCRIPTION
 *  close active theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_res_close_curr_theme (void);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_close_priority_theme
 * DESCRIPTION
 *  close priority theme
 * PARAMETERS
 *  handle      [OUT] handle of the theme
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_res_close_priority_theme(mmi_res_theme_handle handle);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_dlt_theme_thumbnail
 * DESCRIPTION
 *  get thumbnail from theme
 * PARAMETERS
 *  filename    [IN] DLT theme filename
 *  buf         [OUT] buffer to store the thumbnail
 *  buf_length  [IN] buffer length
 * RETURNS
 *  mmi_res_theme_ret_enum
 *****************************************************************************/
extern mmi_res_theme_ret_enum mmi_res_get_dlt_theme_thumbnail(const WCHAR* filename, S8* buf, S32 buf_length);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_dlt_theme_preview
 * DESCRIPTION
 *  get preview from theme
 * PARAMETERS
 *  filename    [IN] DLT theme filename
 *  buf         [OUT] buffer to store the preview image
 *  buf_length  [IN] buffer length
 * RETURNS
 *  mmi_res_theme_ret_enum
 *****************************************************************************/
extern mmi_res_theme_ret_enum mmi_res_get_dlt_theme_preview(const WCHAR* filename, S8* buf, S32 buf_length);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_venus_theme_cache_init
 * DESCRIPTION
 *  initial the theme cache pool
 * PARAMETERS
 *  buffer      [IN] start address of the theme cache pool
 *  size        [OUT] size of the theme cache pool
 * RETURNS
 *  if this operation was succeeded
 *****************************************************************************/
extern MMI_BOOL mmi_res_venus_theme_cache_init(U8 * buffer, U32 size);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_venus_theme_cache_refresh_start
 * DESCRIPTION
 *  start refresh cache
 * PARAMETERS
 * RETURNS
 *  if this operation was succeeded
 *****************************************************************************/
extern MMI_BOOL mmi_res_venus_theme_cache_refresh_start(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_venus_theme_cache_refresh_require
 * DESCRIPTION
 *  start refresh cache
 * PARAMETERS
 *  id          [IN] required res id
 * RETURNS
 *  if this operation was succeeded
 *****************************************************************************/
extern MMI_BOOL mmi_res_venus_theme_cache_refresh_require(U16 id);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_venus_theme_cache_refresh_end
 * DESCRIPTION
 *  end refresh cache
 * PARAMETERS
 * RETURNS
 *  if this operation was succeeded
 *****************************************************************************/
extern MMI_BOOL mmi_res_venus_theme_cache_refresh_end(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_res_venus_theme_cache_get
 * DESCRIPTION
 *  get the cache theme image
 * PARAMETERS
 * RETURNS
 *  address of the image data
 *****************************************************************************/
extern U8 * mmi_res_venus_theme_cache_get(U16 id);

#ifdef __cplusplus
}
#endif

#endif /* __CUST_VENUS_THEME_RES_H__ */
