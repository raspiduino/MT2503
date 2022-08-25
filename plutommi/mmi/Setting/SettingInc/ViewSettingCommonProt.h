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
 *  ViewSettingCommonProt.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VIEW_SETTING_COMMON_PROT_H__
#define __VIEW_SETTING_COMMON_PROT_H__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "FileMgrSrvGprot.h"
#include "WpSSProtos.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(__IOT__)
#ifndef RESOURCE_BASE_APP_VIEWSETTING
#define RESOURCE_BASE_APP_VIEWSETTING (0)
#endif
#endif
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef struct
{
    WCHAR file_name[(SRV_FMGR_PATH_MAX_LEN + 1)];
} mmi_setting_display_common_file_nvram_struct;

#define MMI_SETTING_DISPLAY_CACHE_USER_FILE_NAME_LEN (28) /* D:\Settings\UserWp1.jpg */
typedef struct
{
    WCHAR file_name[(SRV_FMGR_PATH_MAX_LEN + 1)];
    CHAR cache_file_name[MMI_SETTING_DISPLAY_CACHE_USER_FILE_NAME_LEN];
} mmi_setting_display_cache_file_nvram_struct;

typedef void (*mmi_setting_display_void_hdlr) (void* obj);
typedef CHAR (*mmi_setting_display_get_driver_hdlr) (void *obj);
typedef void (*mmi_setting_display_get_file_name_hdlr) (void *obj, WCHAR *buffer, U16 buffer_len);
typedef U8 (*mmi_setting_display_set_file_hdlr) (void *obj, const WCHAR *user_file_name);
typedef void (*mmi_setting_display_cache_set_file_hdlr) (void *obj, const WCHAR *user_file_name, const WCHAR* cache_file_name);

typedef struct
{
    phnset_wpss_type_enum display_type;
    mmi_setting_display_set_file_hdlr set_file;   /* Direct setting method will save the file directly */
} mmi_setting_display_fmgr_setting_object_struct;

typedef struct
{
    phnset_wpss_type_enum display_type;
    mmi_setting_display_set_file_hdlr set_file;      
    /* Cache setting method */
    mmi_setting_display_get_driver_hdlr get_default_driver;
    mmi_setting_display_get_file_name_hdlr get_default_folder;
    mmi_setting_display_get_file_name_hdlr get_default_file_prefix;
    mmi_setting_display_cache_set_file_hdlr cache_set_file;
} mmi_setting_display_cache_setting_object_struct;

typedef enum
{
    EVT_ID_SETTING_DISPLAY_SETTING_DONE = GET_RESOURCE_BASE(APP_VIEWSETTING),

    EVT_ID_SETTING_DISPLAY_SETTING_EVENT_ENUM_TOTAL    
} mmi_setting_display_setting_event_enum;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    MMI_BOOL result;
    U8 error_code;
} mmi_setting_display_setting_event_struct;

/***************************************************************************** 
 * API
 *****************************************************************************/
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
extern void mmi_phnset_view_setting_set_by_file(U8 view_type, const WCHAR* file_name, mmi_proc_func callback, void* user_data);
/* This function should be called after the set by file is finished */
extern void mmi_phnset_view_setting_notify_result(MMI_BOOL result, U8 error_code);
extern void mmi_phnset_view_setting_common_entry_fmgr(MMI_ID parent_gid, U32 view_type);
extern void mmi_phnset_view_setting_common_forward_from_fmgr(U32 view_type, const WCHAR *path, filetypes_file_type_enum type);

extern void mmi_phnset_view_setting_confirm_to_set(void); /* will be phased out later */


/* Common setting Utility */
extern WCHAR* mmi_phnset_view_setting_util_get_file_name_ptr(const WCHAR* path);
extern void mmi_phnset_view_setting_common_image_play_callback(S32 result);
extern void mmi_phnset_view_setting_common_video_play_callback(S32 result);

/* Cache setting Utility */
extern void mmi_phnset_view_setting_cache_util_get_default_folder(WCHAR *buffer, U8 buffer_len, CHAR driver_letter, const CHAR *default_folder);
extern S32 mmi_phnset_view_setting_cache_util_del_file(const WCHAR* file_path);
extern void mmi_phnset_view_setting_cache_util_get_postfix(WCHAR *postfix, WCHAR *inBuffer);
extern U8 mmi_phnset_view_setting_cache_util_prepare_cache_file(const WCHAR* full_prefix, const WCHAR* src_file_name, WCHAR *buffer, U32 buff_len);
extern U8 mmi_phnset_view_setting_cache_util_check_driver_space(S16 driver, const WCHAR *src_file_name);
extern MMI_BOOL mmi_phnset_view_setting_util_check_file_type(U16 file_type, phnset_wpss_type_enum type);


#endif /* __VIEW_SETTING_COMMON_PROT_H__ */
