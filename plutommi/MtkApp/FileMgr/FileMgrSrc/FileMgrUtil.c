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
 *
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#define _FMGR_INTERNAL_SOURCE_C_
/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_features.h"
#if defined (__MMI_FILE_MANAGER__)
#include "FileMgrGProt.h"
#include "FileMgrProt.h"

#include "fmt_struct.h"

#include "Conversions.h"        /* for convert native name */

#include "FileMgrFSData.h"
#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
#include "MainMenuDef.h"
#endif

#include "FileMgrSrvGProt.h"
#include "FileMgrSrvIProt.h"

#include "GlobalConstants.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "Unicodexdcl.h"
#include "fs_errcode.h"
#include "kal_public_api.h"
#include "mmi_rp_file_type_def.h"
#include "wgui_categories_list.h"
#include "mmi_frm_mem_gprot.h"
#include "string.h"
#include "FileMgrType.h"
#include "CustMenuRes.h"
#include "mmi_rp_app_filemanager_def.h"
#include "fs_type.h"
#include "custom_mmi_default_value.h"
#include "fs_func.h"
#include "wgui_categories_util.h"
    
#define FMGR_MAX_FILE_LEN           (MAX_SUBMENU_CHARACTERS)

extern void mmi_fmgr_general_option_handler(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo);
extern void mmi_fmgri_table_do_enabler_for_service(mmi_menu_id menu_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo);

void mmi_fmgr_util_init(void)
{
    srv_fmgr_set_option_handler(mmi_fmgr_general_option_handler, mmi_fmgri_table_do_enabler_for_service);
}

#define WRAPPED


S32 fmgr_main_check_free_space(S8 drv, U32 size_required)
{
    return srv_fmgr_drv_check_free_size((U8)drv, size_required);
}

U16 mmi_fmgri_serv_get_drive_string_id(srv_fmgr_drv_type_enum drv_type)
{
    return srv_fmgr_drv_get_string(srv_fmgr_drv_get_letter_by_type(drv_type));
}

void mmi_fmgr_util_hide_menuid_for_2nd_card(U16 option_menu_id, const S8* path)
{
#ifdef __FS_CARD2_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_fmgri_is_drv_card_2_type_by_path(path))
    {
        mmi_frm_hide_menu_item(option_menu_id);
    }
#endif    
}

S32 mmi_fmgri_get_forward_option(S8* filepath, const FMGR_FILE_INFO_STRUCT* fileinfo, U16 app_id, MMI_BOOL is_send)
{
    S32 fs_ret;

    if(is_send)
        fs_ret = srv_fmgr_types_get_send_option_menu(FMGR_TYPE_ALL, (WCHAR*)filepath);
    else
        fs_ret = srv_fmgr_types_get_use_option_menu(FMGR_TYPE_ALL, (WCHAR*)filepath);
    
    FMGR_TRACE3(TRC_MMI_FMGR_2C55A502774C461EAC5CF369B443E62B,
        "[MMIFMGR] > Util > mmi_fmgr_get_forward_option > app_id=%d, is_send=%d, result=%d\n",
        app_id, is_send, fs_ret);
    
    return fs_ret;
}

S32 mmi_fmgri_fsdata_get_msdc_name(const U16* path, U16* name_buffer, S32 name_buf_size)
{
    if (mmi_wcslen(path) != 3)   /* only accept "X:\" */
        return FS_PARAM_ERROR;

    return srv_fmgr_drv_get_name((U8)path[0], name_buffer, name_buf_size);
}

void mmi_fmgr_init_drive(void)
{
    srv_fmgr_drv_init();
}

PS8 mmi_fmgri_fsdata_get_drive_leading_pattern(srv_fmgr_drv_type_enum index)
{
    return (S8*)srv_fmgr_drv_get_path_by_type(index);
}

//static S32 g_fmgr_adp_req_id = 0;

static mmi_ret fmgr_adp_async_proc_func(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_copy_rsp_strcut rsp;
    srv_fmgr_async_done_event_struct   *adv_action;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
    case EVT_ID_SRV_FMGR_ASYNC_DONE:
        adv_action = (srv_fmgr_async_done_event_struct*)param;
        kal_mem_set(&rsp, 0, sizeof(rsp));
        rsp.result = adv_action->result;
        rsp.callback = param->user_data;
        ((PsFuncPtr)param->user_data)(&rsp);
        break;
    }
    return MMI_RET_OK;
}

S32 mmi_fmgr_util_send_format_req(U8 drive_letter, U32 level, PsFuncPtr callback)
{
    S32 fs_ret = srv_fmgr_async_format(drive_letter, 0, fmgr_adp_async_proc_func, (void*)callback);
    if(fs_ret < 0)
        return fs_ret;
    
    //g_fmgr_adp_req_id = fs_ret;
    return 0;
}

S32 mmi_fmgri_fsdata_is_empty_folder(S8* filepath, FMGR_FILTER *filter_type)
{
    S32 ret = srv_fmgr_fs_path_is_not_empty((WCHAR*)filepath, filter_type);
    if(ret < 0)
        return ret;
    return ret == 1 ? 0 : 1;
}

#define WRAPPER

static FuncPtr fmgr_util_get_menu_handler(mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr old_hdlr, new_hdlr; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    new_hdlr = mmi_frm_get_hilite_hdlr(menu_id);
    if(new_hdlr)
    {
        old_hdlr = get_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
        new_hdlr();
        new_hdlr = get_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
        set_softkey_function(old_hdlr, KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
        if(new_hdlr == old_hdlr)
            new_hdlr = NULL;
    }
    return new_hdlr;

}

void mmi_fmgr_general_option_handler(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT *file_info = NULL;
    FuncPtr handler;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    handler = fmgr_util_get_menu_handler(item_id);
    if(handler)
    {
        file_info = OslMalloc(sizeof(FMGR_FILE_INFO_STRUCT));
        memset(file_info, 0, sizeof(FMGR_FILE_INFO_STRUCT));
        mmi_fmgr_get_file_info_by_path((S8*)filepath, file_info);
        mmi_fmgri_query_result_setup((S8*)filepath, file_info, 0);
        handler();
        mmi_fmgri_query_result_clear();
        OslMfree(file_info);
    }
}


#define NEED_PHASEDOUT



void mmi_fmgr_copy_new_file_path_after_app_move(S8* new_file_path)
{
}


S32 mmi_fmgr_get_file_info_by_path(S8* filepath, FMGR_FILE_INFO_STRUCT *file_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_FMGR_FILEINFO_HANDLE fileinfo_hdl;
    S32 fs_ret;
    WCHAR* file_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_ASSERT(filepath);

    fs_ret = srv_fmgr_fileinfo_create((WCHAR *)filepath, &fileinfo_hdl);
    if (fs_ret < 0)
    {
        return fs_ret;
    }

    memset(file_info, 0, sizeof(FMGR_FILE_INFO_STRUCT));
    FMGR_FILTER_INIT(&(file_info->file_type));
    FMGR_FILTER_SET(&file_info->file_type, srv_fmgr_fileinfo_get_type(fileinfo_hdl));
    file_info->attribute = srv_fmgr_fileinfo_get_attribute(fileinfo_hdl);
    file_info->file_size = srv_fmgr_fileinfo_get_size(fileinfo_hdl);
    srv_fmgr_fileinfo_get_datetime(fileinfo_hdl, &(file_info->time));

    file_name = OslMalloc((SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH);
    memset(file_name, 0, (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH);
    srv_fmgr_fileinfo_get_name(fileinfo_hdl, (WCHAR *)file_name, (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH);
    mmi_ucs2cpy((S8*)file_info->file_name, (S8*) file_name);
    mmi_ucs2cpy((S8*)file_info->file_ext, (S8*)srv_fmgr_types_get_extension_ucs2(srv_fmgr_types_find_type_by_filename_str(file_name)));

    OslMfree(file_name);
    srv_fmgr_fileinfo_destroy(fileinfo_hdl);

    return 0;
}


S32 mmi_fmgri_get_file_option(S8* file_path, S8 need_convert, U32 flag, U16 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmgr_filetype_enum type;
    U16 opt_menu, child_menu;
    S32 i, count, result;
    FMGR_FILE_INFO_STRUCT file_info;
    S8 *buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    opt_menu = count = 0;
    do {
        if (need_convert)
        {
            buffer = mmi_fmgri_get_and_lock_buffer();
            result = mmi_fmgri_fsdata_convert_filename((S8*)file_path, buffer);
            if (result < 0)
            {
                break;
            }
            else if (result == 0)
            {
                mmi_fmgri_free_and_unlock_buffer(buffer);
                buffer = NULL;
            }
            else
            {
                file_path = buffer;
            }
        }
        else
        {
            buffer = NULL;
        }

        result = mmi_fmgr_get_file_info_by_path(file_path, &file_info);
        if (result < 0)
        {
            break;
        }

        type = srv_fmgr_types_get_main_type(&file_info.file_type);
        result = srv_fmgr_types_get_option_menu(type, (WCHAR *)file_path, 0);
        if (result <= 0)
        {
            return result;
        }
        opt_menu = result;

        /* Prepare option menu */
        mmi_fmgri_prepare_option(NULL, opt_menu, &file_info);

        /* Clear path buffer */
        if (buffer)
        {
            mmi_fmgri_free_and_unlock_buffer(buffer);
            buffer = NULL;
            file_path = NULL;
        }

        /* Only keep main option + 2 forward option */
        count = GetNumOfChild(opt_menu);
        for ( i = 1; i < count; i++)
        {
            child_menu = GetSeqItemId(opt_menu, (U16)i);
            if (child_menu != MENU_ID_FMGR_GEN_OPTION_FORWARD_USE &&
                child_menu != MENU_ID_FMGR_GEN_OPTION_FORWARD_SEND)
            {
                mmi_frm_hide_menu_item(child_menu);
            }
        }

        count = GetNumOfChild_Ext(opt_menu);
        
        result = 1;
    }while(0);

    if (buffer)
    {
        mmi_fmgri_free_and_unlock_buffer(buffer);
    }

    /* Output trace here */
    FMGR_TRACE3(TRC_MMI_FMGR_16652FFB6915448AAF796E59D62BA3E6,
        "[MMIFMGR] > Service > fmgr_da_get_option > result=%d, menu=%d, count=%d\n",
        result, opt_menu, count);
    
    if (result < 0)
    {
        opt_menu = 0;
        count = 0;
    }
    else if (!count)
    {
        opt_menu = 0;
    }
    
    return opt_menu;
}


void mmi_fmgri_fsdata_convert_fsentry(FMGR_FILE_INFO_STRUCT *info, FS_DOSDirEntry* fs_entry, S8* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8              buf_file_name[(FMGR_MAX_FILE_LEN+1) * ENCODING_LENGTH];
    S8              *ext;
    U16             type;

    mmi_ucs2ncpy(buf_file_name, filename, FMGR_MAX_FILE_LEN);

    info->is_short = (fs_entry->NTReserved == FS_SFN_MATCH) ? MMI_TRUE : MMI_FALSE;

    /* extension */
    if (fs_entry->Attributes & FS_ATTR_DIR)
    {
        FMGR_FILTER_SET(&(info->file_type), FMGR_TYPE_FOLDER);
    }
    else
    {
        ext = (S8*)srv_fmgr_path_get_extension_ptr((WCHAR*)buf_file_name);
        if(ext)
        {
#ifndef __MMI_SHOW_FILE_EXT__
            /* add '.' to extension */
            info->file_ext[0] = '.';
            mmi_ucs2ncpy(info->file_ext+2, ext, SRV_FMGR_PATH_MAX_FILE_EXT_LEN-1);
#else 
            mmi_ucs2ncpy(info->file_ext, ext, SRV_FMGR_PATH_MAX_FILE_EXT_LEN-1);
#endif 
            type = srv_fmgr_types_find_type_by_extension_str((const WCHAR*)ext);
            FMGR_FILTER_SET(&(info->file_type), type);
        }
        else
        {
            FMGR_FILTER_SET(&(info->file_type), FMGR_TYPE_UNKNOWN);
        }
    }

    /* filename */
#ifndef __MMI_SHOW_FILE_EXT__
    /* remove extension */
    if (!(fs_entry->Attributes & FS_ATTR_DIR))
    {
        U16* ext;
        ext = (U16*)srv_fmgr_path_get_extension_ptr((WCHAR*)buf_file_name);
        if(ext)
            *(ext-1) = 0;
    }
#endif 
    mmi_ucs2cpy(info->file_name, buf_file_name);

    info->index = 0;
    info->attribute = fs_entry->Attributes;
    info->time.nYear = fs_entry->DateTime.Year1980 + 1980;
    info->time.nMonth = fs_entry->DateTime.Month;
    info->time.nDay = fs_entry->DateTime.Day;
    info->time.nHour = fs_entry->DateTime.Hour;
    info->time.nMin = fs_entry->DateTime.Minute;
    info->time.nSec = fs_entry->DateTime.Second2;
    info->file_size = fs_entry->FileSize;
    info->flag = 0;
}

/* mick todo */
S32 mmi_fmgri_fsdata_convert_filename(S8* original_path, S8* new_filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE   fh;
    S32         fs_ret, pos;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    fh = -1;
    do {
        /* check if the filename > 40 */
        pos = srv_fmgr_path_get_filename_pos((WCHAR*)original_path)*2;
        if(!pos)
        {
            fs_ret = FS_INVALID_FILENAME;
            break;
        }

        if(mmi_ucs2strlen(original_path + pos) <= FMGR_MAX_FILE_LEN)
        {
            fs_ret = 0;
            break;
        }
        
        /* try to open file */
        fh = FS_Open((WCHAR*)original_path, FS_READ_ONLY | FS_OPEN_SHARED);
        if(fh < 0)
        {
            fs_ret = fh;
            break;
        }

        /* copy folder to destination */
        pos /= 2;
        mmi_ucs2ncpy(new_filepath, original_path, pos);

        fs_ret = FS_MakeFileName(fh, 0, (WCHAR*)new_filepath + pos, 260 - pos);
        if(fs_ret < 0)
            break;

        fs_ret = 1;

    } while(0);

    if(fh >= 0)
        FS_Close(fh);

    FMGR_TRACE1(TRC_MMI_FMGR_845AE337816049CDA0ADEF684DC39E9A,
        "[MMIFMGR] > FSData > mmi_fmgri_fsdata_convert_filename > result=%d\n",
        fs_ret);

    return fs_ret;    
}
#endif  /* (__MMI_FILE_MANAGER__) */

