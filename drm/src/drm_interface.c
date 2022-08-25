/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * drm_interface.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for DRM service, wrapper layer.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "fs_type.h"
#include "drm_gprot.h"

/* kal_release/fs_type/fat_fs.h MUST be out of __DRM_SUPPORT for non-DRM projects */

#define MAX_OPEN_HINT_SIZE 5
/* frequency : MMI > GDC > WAP > DRMT */
static FS_FileOpenHint open_hint[MAX_OPEN_HINT_SIZE] = {0};
static module_type open_hint_module[MAX_OPEN_HINT_SIZE] = 
{
#if defined(__DRM_SUPPORT__)
    MOD_DRMT,
#endif 
#ifdef WAP_SUPPORT
    MOD_WAP,
#endif    
#ifdef PLUTO_MMI
  #ifdef __LCD_SUPPORT__
    MOD_GDC,
  #endif 
#endif 
#ifdef __MMI_FMI__
    MOD_MMI,
#endif    
    MOD_MED
};

static kal_wchar *open_hint_file_path[MAX_OPEN_HINT_SIZE];

#ifdef __DRM_SUPPORT__
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "app_datetime.h"
#include "app_mine.h"
#include "app_str.h"

#include "drm_trace.h"
#include "drm_def.h"
#include "drm_prot.h"
#include "drm_util.h"
#include "drm_main.h"
#include "drm_msg.h"
#include "drm_memory.h"
#include "stack_config.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "drm_errcode.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "kal_internal_api.h"
#include "string.h"

#define DRM_INTERFACE_DEBUG(x, y) DRM_DEBUG(x,y)
#define DRM_INTERFACE_DEBUGP(x) DRM_DEBUGP(x)

/*
 * global variable
 */

// #define DRM_CHECK_RIGHT_ISSUER_IN_FORWARD_RULE

/*
 * local function
 */

#if !defined(__DRM_EXTERNAL__)
/*****************************************************************************
 * FUNCTION
 *  DRM_install_object
 * DESCRIPTION
 *  generic DRM message/content handler
 * PARAMETERS
 *  content_type                [IN]            HTTP content type, with null terminator
 *  src_path                    [IN]            Source file to intall
 *  src_need_kept               [IN]            To keep source file
 *  dest_path                   [IN/OUT]        Path to put encoded result
 *  dest_buffer_len_in_byte     [IN]            Buffer size of dest_path, to avoid memory corruption
 *  serial                      [OUT]           A serial number of this install job
 *  mime_type                   [IN]            
 *  callback                    [IN]            Callback after finish to install; must be given if is_async is true
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 DRM_install_object(
            kal_uint8 *content_type,
            kal_wchar *src_path,
            kal_bool src_need_kept,
            kal_wchar *dest_path,
            kal_uint32 dest_buffer_len_in_byte,
            kal_uint8 *serial,
            applib_mime_type_struct **mime_type,
            drm_install_object_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    kal_int32 subtype;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_INTERFACE_DEBUG("DRM_install_object", (TRACE_FUNC, DRM_API_INSTALL));

    ASSERT(serial);

    if ((content_type == NULL) ||
        (serial == NULL) ||
        (src_path == NULL) ||
        (dest_path && kal_wstrncmp(dest_path, L"\\\\.\\", 4) == 0) ||
        (dest_path && (dest_buffer_len_in_byte == 0 || (dest_buffer_len_in_byte < (kal_uint32)(kal_wstrlen(dest_path) + 1) * 2))))
    {
        DRM_INTERFACE_DEBUG("DRM_RESULT_INVALID_PARA", (TRACE_GROUP_9, DRM_ITF_9FF0DD4F811194AD49B061928BE0E764));
        return DRM_RESULT_INVALID_PARA;
    }

    subtype = mime_to_int((char*)content_type);
    if (subtype == MIME_SUBTYPE_DRM_MESSAGE || (subtype == MIME_SUBTYPE_DRM_CONTENT && dest_path && src_path[0] != dest_path[0]))
    {
        FS_HANDLE input;
        kal_uint32 size = 0;

        ASSERT(dest_path != NULL);

        /* parse input file */
        input = FS_OpenHint(src_path, FS_READ_ONLY | FS_OPEN_SHARED, DRM_get_open_hint(src_path));
        if (input < FS_NO_ERROR)
        {
            return input;
        }

        FS_GetFileSize(input, &size);

        if ((kal_wstrncmp(src_path, L"\\\\.\\", 4) != 0))
        {
            result = drm_check_free_space(dest_path[0], size);
        }
        else
        {
            result = drm_check_free_space(DRM_DEFAULT_APP_PATH[0], size);
        }

        FS_Close(input);

        if (result == KAL_FALSE)
        {
            DRM_INTERFACE_DEBUG("FS_DISK_FULL", (TRACE_GROUP_9, DRM_API_RSP_NO_DISK));
            return FS_DISK_FULL;
        }
    }

    *serial = drmt_async_get_serial();

    if (callback)
    {
        drmt_install_object_req_struct *req = NULL;

        req = (drmt_install_object_req_struct*) construct_local_para(sizeof(drmt_install_object_req_struct), TD_RESET);

        req->mime_type = subtype;
        app_ucs2_strncpy((kal_int8*)req->src_path, (kal_int8*)src_path, DRM_MAX_PATH_LENGTH -1);
        req->src_need_kept = src_need_kept;
        req->dest_path = dest_path;
        req->dest_buffer_len_in_byte = dest_buffer_len_in_byte;
        req->serial = *serial;
        req->callback = callback;

        /*
         * process encode drm message first, we would cancel any busy request in drm task
         * ex: backup/sweep, register, join domain, any roap message
         */

        if (drmt_engine_is_busy())
        {
            DRM_async_cancel_current_process();
        }

        drm_send_msg(stack_get_active_module_id(), MOD_DRMT, MSG_ID_DRMT_INSTALL_OBJECT_REQ, (void*)req, NULL);

        result = DRM_PROC_ENCRYPT_BUSY;
        return result;
    }

    /* cannot use drm right object during database backup or sweep */
    if (drmt_engine_is_process_database())
    {
        DRM_INTERFACE_DEBUG(
            "[DRM] validate fail by g_drm_is_process_database",
            (TRACE_GROUP_ERROR, DRM_PROC_F1271A584DB6AA8B8674A41EA5EC63FF));
        result = DRM_RESULT_DB_LOCKED;
    }
    else
    {
        result = drm_core_install_object(
                    *serial,
                    subtype,
                    src_path,
                    src_need_kept,
                    dest_path,
                    dest_buffer_len_in_byte,
                    mime_type);
    }

    drmt_async_set_status(*serial, DRM_PROC_ENCRYPT_FINISHED);

    drmt_async_free_serial(*serial);
    return result;
}

#ifdef __DRM_SUPPORT_SD_CALLBACK__


/*****************************************************************************
 * FUNCTION
 *  DRM_register_sd_callback
 * DESCRIPTION
 *  register sd file with timer, callback will be executed when timer expired or rights arrive.
 * PARAMETERS
 *  file_path       [IN]        File path of sd file
 *  timer           [IN]        Millisecond
 *  para            [IN]        Parameter of callback function
 *  callback        [IN]        Callback function when timer expired (TRUE: done/FALSE:rather wait for ever)
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 DRM_register_sd_callback(
            kal_wchar *file_path,
            kal_uint32 timer,
            void *para,
            drm_sd_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE input;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    input = DRM_open_file((WCHAR*) file_path, FS_READ_ONLY, DRM_PERMISSION_NONE);

    if (input >= FS_NO_ERROR)
    {
        result = DRM_register_sd_callback_by_handle(input, timer, para, callback);
        DRM_close_file(input);
        return result;
    }
    return input;
}

/*****************************************************************************
 * FUNCTION
 *  DRM_register_sd_callback
 * DESCRIPTION
 *  register sd file with timer, callback will be executed when timer expired or rights arrive.
 * PARAMETERS
 *  file_path       [IN]        File path of sd file
 *  timer           [IN]        Millisecond
 *  para            [IN]        Parameter of callback function
 *  callback        [IN]        Callback function when timer expired
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 DRM_register_sd_callback_by_handle(
            FS_HANDLE input,
            kal_uint32 timer,
            void *para,
            drm_sd_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check callback function */
    if (callback == NULL)
    {
        return DRM_RESULT_INVALID_PARA;
    }

    result = drmt_sd_callback_register(input, timer, para, callback);
    DRM_DEBUG("[SD] register result = %d", (TRACE_GROUP_GENERAL, DRM_SD_CB_REGISTER_RESULT, result));

    if (result >= 0)
    {

        drmt_register_sd_callback_ind_struct *ind = NULL;

        ind =
            (drmt_register_sd_callback_ind_struct*) construct_local_para(
                                                        sizeof(drmt_register_sd_callback_ind_struct),
                                                        TD_RESET);

        ind->serial = result;
        if (timer == DRM_DEFAULT_UNLIMITED_WAIT)
        {
            timer = 0;
        }
        else if (timer == 0)
        {
            timer = DRM_DEFAULT_WAIT;
        }
        ind->timer = timer * 1000;
       
        drm_send_msg(
                stack_get_active_module_id(),
                MOD_DRMT,
                MSG_ID_DRMT_REGISTER_SD_CALLBACK_REQ,
                (void*)ind,
                NULL);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  DRM_cancel_sd_callback
 * DESCRIPTION
 *  cancel the registration
 * PARAMETERS
 *  serial              [IN]        
 *  file_path(?)        [IN]        File path of sd file
 *  para(?)             [IN]        Parameter of callback function
 *  timer(?)            [IN]        Millisecond
 *  callback(?)         [IN]        Callback function when timer expired
 * RETURNS
 *  kal_int32(?)
 *****************************************************************************/
void DRM_cancel_sd_callback(kal_uint8 serial)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (serial < DRM_SD_CALLBACK_MAX_NUM)
    {
        drmt_sd_callback_clear_entry(serial);
    }

    /* cancel timer */
}

/*****************************************************************************
 * FUNCTION
 *  DRM_has_valid_rights
 * DESCRIPTION
 *  Check if valid rights exist
 * PARAMETERS
 *  file_path(?)        [IN]        File path
 * RETURNS
 *  kal_bool(?)
 *****************************************************************************/
kal_bool DRM_has_valid_rights(kal_wchar *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 permission, i = DRM_PERMISSION_PLAY;
    FS_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    handle = DRM_open_file(file_path, FS_READ_ONLY, DRM_PERMISSION_NONE);

    if (handle >= FS_NO_ERROR)
    {
        permission = drm_get_permission_ext(DRM_get_content_type_entry(handle));
       
        while(i <= DRM_PERMISSION_PRINT)
        {
            if ((permission & i) && DRM_validate_permission(handle, file_path, i))
            {
                DRM_close_file(handle);
                return KAL_TRUE;
            }        
            i = (1 << i);
        }
        DRM_close_file(handle);
    }
    return KAL_FALSE;
}
    
#else  /* __DRM_SUPPORT_SD_CALLBACK__ */ 

/*****************************************************************************
 * FUNCTION
 *  DRM_register_sd_callback
 * DESCRIPTION
 *  register sd file with timer, callback will be executed when timer expired or rights arrive.
 * PARAMETERS
 *  file_path       [IN]        File path of sd file
 *  timer           [IN]        Millisecond
 *  para            [IN]        Parameter of callback function
 *  callback        [IN]        Callback function when timer expired
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 DRM_register_sd_callback(
            kal_wchar *file_path,
            kal_uint32 timer,
            void *para,
            drm_sd_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    
    return NULL;

}

/*****************************************************************************
 * FUNCTION
 *  DRM_cancel_sd_callback
 * DESCRIPTION
 *  cancel the registration
 * PARAMETERS
 *  serial              [IN]        
 *  file_path(?)        [IN]        File path of sd file
 *  para(?)             [IN]        Parameter of callback function
 *  timer(?)            [IN]        Millisecond
 *  callback(?)         [IN]        Callback function when timer expired
 * RETURNS
 *  kal_int32(?)
 *****************************************************************************/
void DRM_cancel_sd_callback(kal_uint8 serial)
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
 *  DRM_has_valid_rights
 * DESCRIPTION
 *  Check if valid rights exist
 * PARAMETERS
 *  file_path(?)        [IN]        File path
 * RETURNS
 *  kal_bool(?)
 *****************************************************************************/
kal_bool DRM_has_valid_rights(kal_wchar *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    return KAL_TRUE;
}

#endif /* __DRM_SUPPORT_SD_CALLBACK__ */ 


/*****************************************************************************
 * FUNCTION
 *  DRM_delete_ro_by_seed
 * DESCRIPTION
 * PARAMETERS
 *  seed            [?]         
 *  seed_len        [IN]        
 * RETURNS
 *****************************************************************************/
kal_int32 DRM_delete_ro_by_seed(kal_uint8 *seed, kal_int32 seed_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_delete_ro_by_seed(seed, seed_len);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_parse_drm_message
 * DESCRIPTION
 *  Parse the drm message. Save the RO into database, and return the information
 *  of drm message back. AP can use the plaintext directly after they get the
 *  plaintext offset. We also do not delete the source file in this API.
 * PARAMETERS
 *  src_path        [IN]        The src_path
 *  seed            [?]         Into drm agent.
 *  seed_len        [IN]        Seed length.
 *  serial          [OUT]       Serial number
 *  info            [OUT]       The drm message information would save into this structure.
 *  callback        [IN]        Async when this parameter is not NULL.
 * RETURNS
 *  drm_proc_enum
 *****************************************************************************/
kal_int32 DRM_parse_drm_message(
            kal_wchar *src_path,
            kal_uint8 *seed,
            kal_int32 seed_len,
            kal_int32 *serial,
            drm_message_info_struct *info,
            drm_parse_dm_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    kal_uint8 handle = drmt_async_get_serial();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_INTERFACE_DEBUG("DRM_parse_drm_message", (TRACE_FUNC, DRM_API_PARSE_DM));
    
    if (serial)
    {
        *serial = handle;
    }

    if (callback)
    {
        drmt_parse_dm_req_struct *req = NULL;

        req = (drmt_parse_dm_req_struct*) construct_local_para(sizeof(drmt_parse_dm_req_struct), TD_RESET);

        req->serial = handle;
        req->seed = seed;
        req->seed_len = seed_len;
        req->callback = callback;
        req->info = (drm_message_info_struct*) drmt_mem_alloc(sizeof(drm_message_info_struct));
        app_ucs2_strncpy((kal_int8*) req->src_path, (kal_int8*) src_path, DRM_MAX_PATH_LENGTH -1);

        if (!drmt_engine_is_busy())
        {
            drm_send_msg(stack_get_active_module_id(), MOD_DRMT, MSG_ID_DRMT_PARSE_DM_REQ, (void*)req, NULL);
        }
        else
        {
            drm_send_msg(stack_get_active_module_id(), MOD_MMI, MSG_ID_DRMT_PARSE_DM_REQ, (void*)req, NULL);
        }
        result = DRM_PROC_ENCRYPT_BUSY;
        return result;
    }

    /* cannot use drm right object during database backup or sweep */
    if (drmt_engine_is_process_database())
    {
        DRM_INTERFACE_DEBUG(
            "[DRM] validate fail by g_drm_is_process_database",
            (TRACE_GROUP_ERROR, DRM_PROC_F1271A584DB6AA8B8674A41EA5EC63FF));

        result = DRM_RESULT_DB_LOCKED;
    }
    else
    {
        result = drm_core_parse_drm_message(handle, src_path, seed, seed_len, info);
    }
    drmt_async_set_status(handle, DRM_PROC_ENCRYPT_FINISHED);
    drmt_async_free_serial(handle);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  DRM_predict_encoded_size
 * DESCRIPTION
 *  Predict size of DCF file before encoding
 * PARAMETERS
 *  src_path            [IN]        
 *  serial(?)           [OUT]       
 *  dest_path(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 DRM_predict_encoded_size(kal_wchar *src_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_predict_encoded_size(src_path);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_encode_drm_message
 * DESCRIPTION
 *  Encode DRM message into DCF format
 * PARAMETERS
 *  src_path        [IN]        
 *  dest_path       [IN]        
 *  offset          [IN]        
 *  serial          [OUT]       
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 DRM_encode_drm_message(
            kal_wchar *src_path,
            kal_wchar *dest_path,
            kal_uint32 offset,
            kal_uint8 *serial,
            drm_general_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    kal_uint8 handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((src_path == NULL) || (dest_path == NULL) || (dest_path && kal_wstrncmp(dest_path, L"\\\\.\\", 4) == 0))
    {
        DRM_INTERFACE_DEBUG("DRM_RESULT_INVALID_PARA", (TRACE_GROUP_9, DRM_ITF_9FF0DD4F811194AD49B061928BE0E764));
        return DRM_RESULT_INVALID_PARA;
    }

    handle = drmt_async_get_serial();

    if (serial)
    {
        *serial = handle;
    }

    if (callback)
    {
        drmt_encode_drm_message_req_struct *req = NULL;

        req =
            (drmt_encode_drm_message_req_struct*) construct_local_para(
                                                    sizeof(drmt_encode_drm_message_req_struct),
                                                    TD_RESET);

        req->serial = handle;
        req->callback = callback;
        req->offset = offset;

        app_ucs2_strncpy((kal_int8*) req->src_path, (kal_int8*) src_path, DRM_MAX_PATH_LENGTH - 1);
        app_ucs2_strncpy((kal_int8*) req->dest_path, (kal_int8*) dest_path, DRM_MAX_PATH_LENGTH - 1);

        /*
         * process encode drm message first, we would cancel any busy request in drm task
         * ex: backup/sweep, register, join domain, any roap message
         */

        if (drmt_engine_is_busy())
        {
            DRM_async_cancel_current_process();
        }

        drm_send_msg(stack_get_active_module_id(), MOD_DRMT, MSG_ID_DRMT_ENCODE_DRM_MESSAGE_REQ, (void*)req, NULL);

        result = DRM_PROC_ENCRYPT_BUSY;
        return result;
    }

    /* cannot use drm right object during database backup or sweep */
    if (drmt_engine_is_process_database())
    {
        DRM_INTERFACE_DEBUG(
            "[DRM] validate fail by g_drm_is_process_database",
            (TRACE_GROUP_ERROR, DRM_PROC_F1271A584DB6AA8B8674A41EA5EC63FF));

        result = DRM_RESULT_DB_LOCKED;
    }
    else
    {
        result = drm_core_encode_drm_message(handle, src_path, dest_path, offset);
    }

    drmt_async_set_status(handle, DRM_PROC_ENCRYPT_FINISHED);

    drmt_async_free_serial(handle);

    return result;

}


/*****************************************************************************
 * FUNCTION
 *  DRM_async_cancel_process
 * DESCRIPTION
 *  
 * PARAMETERS
 *  serial      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool DRM_async_cancel_process(kal_uint8 serial)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_abort_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!serial || (serial && DRM_RESULT_OK == drmt_async_cancel_process(serial)))
    {
        msg = (drmt_abort_req_struct*) construct_local_para(sizeof(drmt_abort_req_struct), TD_RESET);

        drm_send_msg(stack_get_active_module_id(), MOD_DRMT, MSG_ID_DRMT_ABORT_REQ, (void*)msg, NULL);

        return KAL_TRUE;
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  DRM_async_cancel_current_process
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  serial(?)       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool DRM_async_cancel_current_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DRM_async_cancel_process(drmt_async_get_current_serial());
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  DRM_activate_file
 * DESCRIPTION
 * PARAMETERS
 *  file_path       [?]         [?]         [?]
 *  permission      [IN]        
 *  serial          [?]         [?]         [?]
 *  callback        [IN]        
 * RETURNS
 *****************************************************************************/
drm_proc_enum DRM_activate_file(
                kal_wchar *file_path,
                kal_uint8 permission,
                kal_uint8 *serial,
                drm_general_callback callback)
{
#ifdef __DRM_V02__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_activate_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_INTERFACE_DEBUG("DRM_activate_file", (TRACE_GROUP_9, DRM_ITF_11701758220F424D0F4A7A0D6C878692));

    req = (drmt_activate_req_struct*) construct_local_para(sizeof(drmt_activate_req_struct), TD_RESET);
    req->serial = drmt_async_get_serial();

    if (serial)
    {
        *serial = req->serial;
    }
    req->permission = permission;
    req->callback = callback;
    req->is_file_handle = KAL_FALSE;
    kal_wstrncpy((kal_wchar*) req->filepath, (kal_wchar*) file_path, DRM_MAX_PATH_LENGTH - 1);

    if (!drmt_engine_is_busy())
    {
        drm_send_msg(stack_get_active_module_id(), MOD_DRMT, MSG_ID_DRMT_ACTIVATE_REQ, (void*)req, NULL);
    }
    else
    {
        drm_send_msg(stack_get_active_module_id(), MOD_MMI, MSG_ID_DRMT_ACTIVATE_REQ, (void*)req, NULL);
    }

    return DRM_PROC_ENCRYPT_BUSY;
#else /* __DRM_V02__ */ 
    return DRM_RESULT_NOT_SUPPORT;
#endif /* __DRM_V02__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  DRM_activate_file_by_handle
 * DESCRIPTION
 * PARAMETERS
 *  handle          [IN]        
 *  serial          [?]         [?]         [?]
 *  callback        [IN]        
 *  file_path       [?]         [?](?)
 * RETURNS
 *****************************************************************************/
drm_proc_enum DRM_activate_file_by_handle(FS_HANDLE handle, kal_uint8 *serial, drm_general_callback callback)
{
#ifdef __DRM_V02__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_activate_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_INTERFACE_DEBUG("DRM_activate_file", (TRACE_GROUP_9, DRM_ITF_11701758220F424D0F4A7A0D6C878692));

    req = (drmt_activate_req_struct*) construct_local_para(sizeof(drmt_activate_req_struct), TD_RESET);
    req->serial = drmt_async_get_serial();

    if (serial)
    {
        *serial = req->serial;
    }
    req->callback = callback;
    req->is_file_handle = KAL_TRUE;
    req->file_handle = handle;

    if (!drmt_engine_is_busy())
    {
        drm_send_msg(stack_get_active_module_id(), MOD_DRMT, MSG_ID_DRMT_ACTIVATE_REQ, (void*)req, NULL);
    }
    else
    {
        drm_send_msg(stack_get_active_module_id(), MOD_MMI, MSG_ID_DRMT_ACTIVATE_REQ, (void*)req, NULL);
    }

    return DRM_PROC_ENCRYPT_BUSY;
#else /* __DRM_V02__ */ 
    return DRM_RESULT_NOT_SUPPORT;
#endif /* __DRM_V02__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  DRM_process_database
 * DESCRIPTION
 *  parse downloaded content to identify DRM content and populate rights information
 * PARAMETERS
 *  type                [IN]        
 *  index               [IN]        
 *  path                [?]         
 *  serial              [?]         
 *  callback            [IN]        
 *  file_path(?)        [IN]        
 *  mime_type(?)        [IN]        
 *  temp_use(?)         [IN]        
 * RETURNS
 *****************************************************************************/
kal_int32 DRM_process_database(
            kal_uint8 type,
            kal_int32 index,
            kal_wchar *path,
            kal_uint8 *serial,
            drm_general_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_process_database_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!drmt_engine_is_ready())
    {
        return DRM_RESULT_NOT_SUPPORT;
    }

    if (DRM_consume_table_is_in_use())
    {
        return DRM_RESULT_DB_LOCKED;
    }

    ASSERT(callback);

    req = (drmt_process_database_req_struct*) construct_local_para(sizeof(drmt_process_database_req_struct), TD_RESET);

    req->type = type;
    req->index = index;
    req->callback = callback;
    req->serial = drmt_async_get_serial();

    if (path)
    {
        app_ucs2_strncpy((kal_int8*)req->path, (kal_int8*)path, DRM_MAX_PATH_LENGTH -1);
    }
    else
    {
        req->path[0] = '\0';
    }

    if (!drmt_engine_is_busy())
    {
        drm_send_msg(stack_get_active_module_id(), MOD_DRMT, MSG_ID_DRMT_PROCESS_DATABASE_REQ, req, NULL);
    }
    else
    {
        drm_send_msg(stack_get_active_module_id(), MOD_MMI, MSG_ID_DRMT_PROCESS_DATABASE_REQ, req, NULL);
    }

    if (serial)
    {
        *serial = req->serial;
    }

    return DRM_PROC_ENCRYPT_BUSY;
}

#ifdef __DRM_SUPPORT_SCAN_DISK__


/*****************************************************************************
 * FUNCTION
 *  DRM_scan_disk
 * DESCRIPTION
 *  Scan whole disk and try to find all dcf file
 * PARAMETERS
 *  type            [IN]            Search type
 *  path            [IN]            Root path
 *  serial          [IN/OUT]        Serial number
 *  callback        [IN]            Callback function
 * RETURNS
 *  drm_proc_enum
 *****************************************************************************/
kal_int32 DRM_scan_disk(kal_uint8 type, kal_wchar *path, kal_uint8 *serial, drm_general_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_scan_disk_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!drmt_engine_is_ready())
    {
        return DRM_RESULT_NOT_SUPPORT;
    }

    req = (drmt_scan_disk_req_struct*) construct_local_para(sizeof(drmt_scan_disk_req_struct), TD_RESET);

    req->type = type;
    req->callback = callback;
    req->serial = drmt_async_get_serial();
    req->source = stack_get_active_module_id();

    if (path)
    {
        app_ucs2_strncpy((kal_int8*) req->path, (kal_int8*) path, 15);
    }

    drm_send_msg(stack_get_active_module_id(), MOD_DRMT, MSG_ID_DRMT_SCAN_DISK_REQ, req, NULL);

    if (serial)
    {
        *serial = req->serial;
    }
    return DRM_PROC_ENCRYPT_BUSY;
}
#endif /* __DRM_SUPPORT_SCAN_DISK__ */ 


#endif /* !__DRM_EXTERNAL__ */
/*****************************************************************************
 * FUNCTION
 *  DRM_open_file
 * DESCRIPTION
 *  open file, if file is a DRM content, retreive rights information. otherwise simply open file.
 * PARAMETERS
 *  file_path       [IN]        
 *  flags           [IN]        
 *  permission      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
FS_HANDLE DRM_open_file(kal_wchar *file_path, kal_uint32 flags, kal_uint8 permission)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drmt_check_engine_ready();

    return drm_core_open_file_aux(file_path, flags, permission, KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_close_file
 * DESCRIPTION
 *  close file, if file is a DRM content, deinit rights information. otherwise simply close file.
 * PARAMETERS
 *  object      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 DRM_close_file(FS_HANDLE object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_close_file(object);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_read_file
 * DESCRIPTION
 *  read data from file, if file is a DRM content, decrypt or seek to the right location before read
 * PARAMETERS
 *  source      [IN]        
 *  buffer      [IN]        
 *  size        [IN]        
 *  length      [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 DRM_read_file(FS_HANDLE source, void *buffer, kal_uint32 size, kal_uint32 *length)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_read_file(source, buffer, size, length);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_seek_file
 * DESCRIPTION
 *  seek file, if file is a DRM content, decrypt or seek to the right location for it
 * PARAMETERS
 *  source      [IN]        
 *  offset      [IN]        
 *  ref         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 DRM_seek_file(FS_HANDLE source, kal_int32 offset, kal_uint8 ref)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_seek_file(source, offset, ref);
}

kal_int64 DRM_seek_large_file(FS_HANDLE source, kal_int64 offset, kal_uint8 ref)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_seek_large_file(source, offset, ref);
}
/*****************************************************************************
 * FUNCTION
 *  DRM_set_seek_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  HintNum     [IN]        
 *  Hint        [?]         [?]         [?]
 *  source(?)       [IN](?)(?)
 *  ref(?)          [IN](?)(?)
 *  offset(?)       [IN](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 DRM_set_seek_hint(FS_HANDLE handle, UINT HintNum, FS_FileLocationHint *Hint)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_set_seek_hint(handle, HintNum, Hint);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_file_size
 * DESCRIPTION
 *  get file size, if file is a DRM content, decrypt and remove header size
 * PARAMETERS
 *  source      [IN]        
 *  size        [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 DRM_file_size(FS_HANDLE source, kal_uint32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_file_size(source, size);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_file_pos
 * DESCRIPTION
 *  get file position, if file is a DRM content, decrypt and change file postition information by removing header
 * PARAMETERS
 *  source      [IN]        
 *  pos         [OUT]       
 * RETURNS
 *  zero for success            (1.0)
 *  negative for error code     (1.0/2.0)
 *  positive for content number (2.0)
 *****************************************************************************/
kal_int32 DRM_file_pos(FS_HANDLE source, kal_uint32 *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_file_pos(source, pos);
}

/*****************************************************************************
 * FUNCTION
 *  DRM_get_object_method
 * DESCRIPTION
 *  get DRM method of a DRM content
 * PARAMETERS
 *  input       [IN]        
 *  path        [?]         [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 DRM_get_object_method(FS_HANDLE input, kal_wchar *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 method = DRM_METHOD_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_MEM_START_EVAL
    if (path)
    {
        input = drm_core_open_file(path, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_NONE);
        if (input < FS_NO_ERROR)
        {
            return DRM_METHOD_NONE;
        }

        method = drm_core_get_object_method(input);
        drm_core_close_file(input);
        return method;
    }
    else
    {
        return drm_core_get_object_method(input);
    }
    DRM_MEM_END_EVAL
}



/*****************************************************************************
 * FUNCTION
 *  DRM_get_meta_size
 * DESCRIPTION
 *  To get meta data size in DCF
 * PARAMETERS
 *  input       [IN]        File handle of the DCF
 *  meta_id     [IN]        Meta data id to query
 * RETURNS
 *  > 0 : size
 *  DRM_RESULT_DATA_NOT_FOUND: no such meta data
 *  DRM_RESULT_NON_DRM: the given file is not a DRM content
 *  otherwise: File System error code
 *****************************************************************************/
kal_int32 DRM_get_meta_size(FS_HANDLE input, drm_meta_enum meta_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_MEM_START_EVAL
    result = drm_core_get_meta_size(input, meta_id);
    DRM_MEM_END_EVAL
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  DRM_get_meta_data
 * DESCRIPTION
 *  To get meta data in DCF, in "UTF8" format
 * PARAMETERS
 *  input       [IN]        File handle of the DCF
 *  meta_id     [IN]        Meta data id to query
 *  buffer      [IN]        Buffer to keep meta data
 *  size        [IN]        Will be copied into buffer
 * RETURNS
 *  success: DRM_RESULT_OK
 *  DRM_RESULT_INVALID_PARA: negative error code
 *  DRM_RESULT_DATA_NOT_FOUND: no such meta data
 *  DRM_RESULT_NON_DRM: the given file is not a DRM content
 *  otherwise: File System error code
 *****************************************************************************/
kal_int32 DRM_get_meta_data(FS_HANDLE input, drm_meta_enum meta_id, kal_char *buffer, kal_int32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_MEM_START_EVAL
    result = drm_core_get_meta_data(input, meta_id, buffer, size);
    DRM_MEM_END_EVAL
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  DRM_get_content_ext
 * DESCRIPTION
 *  get content extension name of a DRM file
 * PARAMETERS
 *  handle      [IN]        
 *  path        [?]         [?]         [?]
 *  input(?)        [IN](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_char *DRM_get_content_ext(FS_HANDLE handle, kal_wchar *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mime_type_struct *entry;
    kal_char *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_MEM_START_EVAL

    if (path)
    {
        handle = drm_core_open_file(path, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_NONE);
        if (handle < FS_NO_ERROR)
        {
            return NULL;
        }
    }

    if (drm_core_get_content_type(handle, &entry) == DRM_RESULT_OK)
    {
        result = entry->file_ext;
    }
    else
    {
        result = NULL;
    }

    if (path)
    {
        drm_core_close_file(handle);
    }
    DRM_MEM_END_EVAL

    return result;
}


#if !defined(__DRM_EXTERNAL__)


/*****************************************************************************
 * FUNCTION
 *  DRM_get_content_type_entry
 * DESCRIPTION
 *  get extension file name of a file path
 * PARAMETERS
 *  handle      [IN]        
 *  path        [?]         [?](?)
 *  input(?)        [IN](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
applib_mime_type_struct *DRM_get_content_type_entry(FS_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mime_type_struct *entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_MEM_START_EVAL
    if (drm_core_get_content_type(handle, &entry) == DRM_RESULT_OK)
    {
        return entry;
    }
    else
    {
        return NULL;
    }
    DRM_MEM_END_EVAL
}

/*****************************************************************************
 * FUNCTION
 *  DRM_get_content_type
 * DESCRIPTION
 *  get content type of a DRM file
 * PARAMETERS
 *  handle      [IN]        
 *  path        [?]         [?]         [?]
 *  input(?)        [IN](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 *DRM_get_content_type(FS_HANDLE handle, kal_wchar *path)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mime_type_struct *entry;
    kal_uint8 *result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_MEM_START_EVAL

    if (path)
    {
        handle = drm_core_open_file(path, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_NONE);
        if (handle < FS_NO_ERROR)
        {
            return NULL;
        }
    }

    if (drm_core_get_content_type(handle, &entry) == DRM_RESULT_OK)
    {
        result = (kal_uint8*) entry->mime_string;
    }
    else
    {
        result = NULL;
    }

    if (path)
    {
        drm_core_close_file(handle);
    }
    DRM_MEM_END_EVAL

    return result;

}


/*****************************************************************************
 * FUNCTION
 *  DRM_get_rights_issuer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input       [IN]        
 *  buffer      [?]         [?]         [?]
 *  size        [?]         [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 DRM_get_rights_issuer(FS_HANDLE input, kal_char *buffer, kal_uint32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_MEM_START_EVAL
    result = drm_core_get_rights_issuer(input, buffer, size);
    DRM_MEM_END_EVAL

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  DRM_get_constraint
 * DESCRIPTION
 *  get corresponding permission type for content of specific mime type
 * PARAMETERS
 *  handle              [IN]        
 *  path                [?]         
 *  permission          [IN]        
 *  cons                [?]         
 *  mime_string(?)      [IN]        
 *  mime_type(?)        [IN]        
 * RETURNS
 *  permission      [IN]
 *  cons            [?]         [?]
 * RETURNS
 *****************************************************************************/
kal_int32 DRM_get_constraint(FS_HANDLE handle, kal_wchar *path, kal_uint8 permission, drm_constraint_struct *cons)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_MEM_START_EVAL
    if (path)
    {
        handle = drm_core_open_file(path, FS_READ_ONLY | FS_OPEN_SHARED, permission);
        if (handle < FS_NO_ERROR)
        {
            return handle;
        }
    }

    result = drm_core_get_constraint(handle, permission, cons);

    if (path)
    {
        drm_core_close_file(handle);
    }
    DRM_MEM_END_EVAL

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  DRM_get_start_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *       
 * RETURNS
 *  permission      [IN]
 *  cons            [?]         [?]
 * RETURNS
 *****************************************************************************/
kal_int32 DRM_get_start_time(FS_HANDLE handle, kal_wchar *path, kal_uint8 permission, applib_time_struct *start_time)
{
    drm_constraint_struct cons;

	memset(start_time, 0, sizeof(applib_time_struct));

    DRM_get_constraint(handle, path, permission, &cons);
	if(cons.status == DRM_STATUS_RIGHTS_PRESENT)
	{
		if(cons.type & DRM_CONSTRAINT_DATETIME)
			{
				if(cons.start_time > 0)
					{
					   applib_dt_utc_sec_2_mytime(cons.start_time, start_time, KAL_FALSE);
					   return DRM_RESULT_OK;
					}
			}
	}

	return DRM_RESULT_INVALID;
}

/*****************************************************************************
 * FUNCTION
 *  DRM_get_end_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *       
 * RETURNS
 *  permission      [IN]
 *  cons            [?]         [?]
 * RETURNS
 *****************************************************************************/

kal_int32 DRM_get_end_time(FS_HANDLE handle, kal_wchar *path, kal_uint8 permission, applib_time_struct *end_time)
{
    drm_constraint_struct cons;
	kal_int32 result;
	memset(end_time, 0, sizeof(applib_time_struct));
    result = DRM_get_constraint(handle, path, permission, &cons);
	if(cons.status == DRM_STATUS_RIGHTS_PRESENT)
	{
		if(cons.type & DRM_CONSTRAINT_DATETIME || DRM_STATUS_RIGHTS_IN_FUTURE)
			{
				if(cons.end_time> 0)
					{
					   applib_dt_utc_sec_2_mytime(cons.end_time, end_time, KAL_FALSE);
					   return DRM_RESULT_OK;
					}
			}
	}

	return DRM_RESULT_INVALID;
}

/*****************************************************************************
 * FUNCTION
 *  DRM_get_interval
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  permission      [IN]
 *  cons            [?]         [?]
 * RETURNS
 *****************************************************************************/

kal_int32 DRM_get_interval(FS_HANDLE handle, kal_wchar *path, kal_uint8 permission, kal_int32 *interval)
{
    drm_constraint_struct cons;
	kal_int32 result;
	*interval = 0;
    result = DRM_get_constraint(handle, path, permission, &cons);
	if(cons.status == DRM_STATUS_RIGHTS_PRESENT)
	{
		if(cons.type & DRM_CONSTRAINT_INTERVAL)
			{
				if(cons.interval> 0)
					{
					   *interval = cons.interval;
					   return DRM_RESULT_OK;
					}
			}
	}

	return DRM_RESULT_INVALID;
}

/*****************************************************************************
 * FUNCTION
 *  DRM_get_left_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *       
 * RETURNS
 *  permission      [IN]
 *  cons            [?]         [?]
 * RETURNS
 *****************************************************************************/

kal_int32 DRM_get_left_count(FS_HANDLE handle, kal_wchar *path, kal_uint8 permission, kal_int64 *left_count)
{
    drm_constraint_struct cons;
	kal_int32 result;
	*left_count = 0;
    result = DRM_get_constraint(handle, path, permission, &cons);
	if(cons.status == DRM_STATUS_RIGHTS_PRESENT)
	{
		if(cons.type & DRM_CONSTRAINT_COUNT)
			{
				if(cons.total_count> 0)
					{
					   *left_count = cons.used_count;
					   return DRM_RESULT_OK;
					}
			}
	}

	return DRM_RESULT_INVALID;
}

/*****************************************************************************
 * FUNCTION
 *  DRM_get_total_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  permission      [IN]
 *  cons            [?]         [?]
 * RETURNS
 *****************************************************************************/

kal_int32 DRM_get_total_count(FS_HANDLE handle, kal_wchar *path, kal_uint8 permission, kal_int64 *total_count)
{
    drm_constraint_struct cons;
	kal_int32 result;
	*total_count = 0;
    result = DRM_get_constraint(handle, path, permission, &cons);
	if(cons.status == DRM_STATUS_RIGHTS_PRESENT)
	{
		if(cons.type & DRM_CONSTRAINT_COUNT)
			{
				if(cons.total_count> 0)
					{
					   *total_count = cons.total_count;
					   return DRM_RESULT_OK;
					}
			}
	}

	return DRM_RESULT_INVALID;
}

/*****************************************************************************
 * FUNCTION
 *  DRM_is_drm_file
 * DESCRIPTION
 * PARAMETERS
 *  handle              [IN]        
 *  path                [?]         [?]         [?]
 *  permission(?)       [IN]        
 *  cons            [?]         [?](?)
 * RETURNS
 *****************************************************************************/
kal_bool DRM_is_drm_file(FS_HANDLE handle, kal_wchar *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (DRM_get_object_method(handle, path) != DRM_METHOD_NONE)
    {
        return KAL_TRUE;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  DRM_get_secure_time
 * DESCRIPTION
 *  To get secure time
 * PARAMETERS
 *  time        [?]     [?]
 * RETURNS
 *  number
 *****************************************************************************/
kal_bool DRM_get_secure_time(applib_time_struct *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_get_stime(time);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_register_file
 * DESCRIPTION
 * PARAMETERS
 *  file_path       [?]         
 *  handle(?)       [IN]        
 *  path        [?]         [?](?)
 * RETURNS
 *****************************************************************************/
kal_int32 DRM_register_file(kal_wchar *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = drm_core_register_file(file_path);
    return result;
}

#ifdef __DRM_V02__


/*****************************************************************************
 * FUNCTION
 *  DRM_is_archive_object
 * DESCRIPTION
 * PARAMETERS
 *  handle      [IN]        
 *  path        [?]         [?]         [?]
 * RETURNS
 *****************************************************************************/
kal_bool DRM_is_archive_object(FS_HANDLE handle, kal_wchar *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path)
    {

        kal_wchar *sepa = kal_wstrrchr(path, (kal_int32) '\\');

        if (sepa && app_ucs2_strnicmp((kal_int8*) (sepa - 4), (kal_int8*) L".odf\\", 5) != 0)
        {
            handle = drm_core_open_file(path, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_NONE);
            if (handle < FS_NO_ERROR)
            {
                return KAL_FALSE;
            }
            drm_core_close_file(handle);
            return KAL_TRUE;
        }
        else
        {
            return KAL_FALSE;
        }
    }

    result = drm_core_is_archive_object(handle);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  DRM_is_archive
 * DESCRIPTION
 * PARAMETERS
 *  handle      [IN]        
 *  path        [?]         [?]         [?]
 * RETURNS
 *****************************************************************************/
kal_bool DRM_is_archive(FS_HANDLE handle, kal_wchar *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path)
    {
        handle = drm_core_open_file(path, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_NONE);
        if (handle < FS_NO_ERROR)
        {
            return KAL_FALSE;
        }
    }

    result = drm_core_is_archive(handle);

    if (path)
    {
        drm_core_close_file(handle);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  DRM_get_find_cntx
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void *DRM_get_find_cntx(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_get_find_cntx();
}


/*****************************************************************************
 * FUNCTION
 *  DRM_find_firstN
 * DESCRIPTION
 *  
 * PARAMETERS
 *  find_cntx           [?]         [?]         [?]
 *  file_path           [?]         [?]         [?]
 *  PatternArray        [?]         [?]         [?]
 *  PatternNum          [IN]        
 *  FileInfo            [?]         [?]         [?]
 *  FileName            [?]         [?]         [?]
 *  MaxLen              [IN]        
 *  EntryIndex          [IN]        
 *  object(?)           [IN](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
FS_HANDLE DRM_find_firstN(
            void *find_cntx,
            kal_wchar *file_path,
            FS_Pattern_Struct *PatternArray,
            kal_uint32 PatternNum,
            drm_file_info_struct *FileInfo,
            kal_wchar *FileName,
            kal_uint32 MaxLen,
            kal_int32 EntryIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_find_firstN(find_cntx, file_path, PatternArray, PatternNum, FileInfo, FileName, MaxLen, EntryIndex);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_find_nextN
 * DESCRIPTION
 *  
 * PARAMETERS
 *  find_cntx       [?]         [?]         [?]
 *  handle          [IN]        
 *  FileInfo        [?]         [?]         [?]
 *  FileName        [?]         [?]         [?]
 *  MaxLen          [IN]        
 *  distance        [IN]        
 *  object(?)       [IN](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 DRM_find_nextN(
            void *find_cntx,
            FS_HANDLE handle,
            drm_file_info_struct *FileInfo,
            kal_wchar *FileName,
            kal_uint32 MaxLen,
            kal_int32 distance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_find_nextN(find_cntx, handle, FileInfo, FileName, MaxLen, distance);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_find_close
 * DESCRIPTION
 *  close file, if file is a DRM content, deinit rights information. otherwise simply close file.
 * PARAMETERS
 *  find_cntx       [?]         [?]
 *  handle          [IN]        
 *  object(?)       [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 DRM_find_close(void *find_cntx, FS_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_find_close(find_cntx, handle);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_toggle_tracking
 * DESCRIPTION
 *  1. To turn on or off transation tracking
 *  2. To get current status
 * PARAMETERS
 *  to_get      [IN]        
 * RETURNS
 *  1. to_get == FALSE -> turn on/off transation tracking
 *  2. to_get == TRUE  -> return current status
 *****************************************************************************/
kal_bool DRM_toggle_tracking(kal_bool to_get)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_toggle_tracking(to_get);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_get_domain_num
 * DESCRIPTION
 *  To get total doamin that DRM Agent in
 * PARAMETERS
 *  void
 * RETURNS
 *  number
 *****************************************************************************/
kal_int32 DRM_get_domain_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_get_domain_num();
}


/*****************************************************************************
 * FUNCTION
 *  DRM_get_trust_state
 * DESCRIPTION
 *  To get total doamin that DRM Agent in
 * PARAMETERS
 *  void
 * RETURNS
 *  number
 *****************************************************************************/
kal_bool DRM_get_trust_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_get_trust_state();
}


/*****************************************************************************
 * FUNCTION
 *  DRM_import_certificate
 * DESCRIPTION
 * PARAMETERS
 *  path        [?]     [?]     [?]
 * RETURNS
 *****************************************************************************/
kal_int32 DRM_import_certificate(kal_wchar *path)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_import_cer(path);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_update_local_time
 * DESCRIPTION
 * PARAMETERS
 *  old_time        [?]         
 *  new_time        [?]         
 *  reliable        [IN]        
 *  path        [?]     [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void DRM_update_local_time(applib_time_struct *old_time, applib_time_struct *new_time, kal_bool reliable)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drm_core_update_local_time(old_time, new_time, reliable);
}

#define DRM_INTERFACE_WHITELIST


/*****************************************************************************
 * FUNCTION
 *  DRM_init_whitelist
 * DESCRIPTION
 *  To init white list
 * PARAMETERS
 *  void
 * RETURNS
 *  success or not
 *****************************************************************************/
kal_int32 DRM_init_whitelist(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_init_whitelist();
}


/*****************************************************************************
 * FUNCTION
 *  DRM_get_whitelist
 * DESCRIPTION
 *  To get white list
 * PARAMETERS
 *  list_buffer     [IN]        Buffer to show whitelist
 *  index           [OUT]       Index of saved whitelist
 * RETURNS
 *  is dcf or not
 *****************************************************************************/
kal_bool DRM_get_whitelist(kal_char *list_buffer, kal_uint8 index)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_get_whitelist(list_buffer, index);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_add_whitelist
 * DESCRIPTION
 *  To add white list
 * PARAMETERS
 *  list_buffer     [IN]        Buffer to show whitelist
 *  index(?)        [OUT]       Index of saved whitelist
 * RETURNS
 *  is dcf or not
 *****************************************************************************/
kal_int32 DRM_add_whitelist(kal_char *list_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_add_whitelist(list_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_del_whitelist
 * DESCRIPTION
 *  To delete white list
 * PARAMETERS
 *  list_buffer     [IN]        Buffer to show whitelist
 *  index(?)        [OUT]       Index of saved whitelist
 * RETURNS
 *  is dcf or not
 *****************************************************************************/
kal_bool DRM_del_whitelist(kal_char *list_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_del_whitelist(list_buffer);

}


/*****************************************************************************
 * FUNCTION
 *  DRM_free_whitelist
 * DESCRIPTION
 *  To free white list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DRM_free_whitelist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drm_core_free_whitelist();
}

#endif /* __DRM_V02__ */ 


/*****************************************************************************
 * FUNCTION
 *  DRM_get_ro_num
 * DESCRIPTION
 *  To get rights objects number
 * PARAMETERS
 *  serial          [?]         
 *  callback        [IN]        
 * RETURNS
 *  Number of RO; -1 means error
 *****************************************************************************/
kal_int32 DRM_get_ro_num(kal_uint8 *serial, drm_general_callback callback, drm_proc_db_ro_count_flag_enum flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 handle;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = drmt_async_get_serial();

    if (serial)
    {
        *serial = handle;
    }

    if (callback)
    {
        drmt_get_ro_num_req_struct *req = NULL;

        req = (drmt_get_ro_num_req_struct*) construct_local_para(sizeof(drmt_get_ro_num_req_struct), TD_RESET);

        req->serial = handle;
        req->callback = callback;
	req->count_flag = flag;

        if (!drmt_engine_is_busy())
        {
            drm_send_msg(stack_get_active_module_id(), MOD_DRMT, MSG_ID_DRMT_GET_RO_NUM_REQ, (void*)req, NULL);
        }
        else
        {
            drm_send_msg(stack_get_active_module_id(), MOD_MMI, MSG_ID_DRMT_GET_RO_NUM_REQ, (void*)req, NULL);
        }
        result = DRM_PROC_ENCRYPT_BUSY;
        return result;
    }

    result = drm_core_get_ro_num(handle, flag);

    drmt_async_set_status(handle, DRM_PROC_ENCRYPT_FINISHED);
    drmt_async_free_serial(handle);

    return result;

}


/*****************************************************************************
 * FUNCTION
 *  DRM_get_ro_list
 * DESCRIPTION
 *  To get rights objects list
 * PARAMETERS
 *  index       [IN]        Index of ro list
 *  alias       [OUT]       Alias string of the specific ro
 *  size        [IN]        
 * RETURNS
 *  is dcf or not
 *****************************************************************************/
kal_int32 DRM_get_ro_list(kal_int32 index, kal_char *alias, kal_uint32 size, drm_proc_db_ro_count_flag_enum flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_get_ro(index, alias, size, flag);
}

#ifdef __DRM_V02__


/*****************************************************************************
 * FUNCTION
 *  DRM_get_ro_shareability
 * DESCRIPTION
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *****************************************************************************/
kal_bool DRM_get_ro_shareability(kal_int32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_is_ro_shareable(index);
}

#endif /* __DRM_V02__ */ 


/*****************************************************************************
 * FUNCTION
 *  DRM_free_ro_list
 * DESCRIPTION
 *  To free rights objects list
 * PARAMETERS
 *  data        [?]     [?]
 * RETURNS
 *  is dcf or not
 *****************************************************************************/
void DRM_free_ro_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drm_core_free_ro_list();
}

#ifdef __DRM_V02__


/*****************************************************************************
 * FUNCTION
 *  DRM_get_ro_dbsize
 * DESCRIPTION
 *  To free rights objects detail
 * PARAMETERS
 *  max     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 DRM_get_ro_dbsize(kal_int32 *max)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_get_ro_dbsize(max);
}
#endif /* __DRM_V02__ */ 


/*****************************************************************************
 * FUNCTION
 *  DRM_get_version
 * DESCRIPTION
 *  To get DRM Agent Version
 * PARAMETERS
 *  void
 * RETURNS
 *  [bit 8~15] Major Version (0 to 255)
 *  [bit 0~7]  Minor Version (0 to 255)
 *****************************************************************************/
kal_int32 DRM_get_version(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__DRM_V02__)
    return 0x00020000;
#elif defined(__DRM_V01__)
    return 0x00010000;
#endif 
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  DRM_get_limit_type
 * DESCRIPTION
 *  To keep delta time in rights object.
 * PARAMETERS
 *  handle          [IN]        
 *  permission      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint32 DRM_get_limit_type(FS_HANDLE handle, kal_uint8 permission)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drm_constraint_struct cons;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drm_core_get_constraint(handle, permission, &cons);

    return cons.type;
}


/*****************************************************************************
 * FUNCTION
 *  DRM_app_parse_drm_message_hdlr
 * DESCRIPTION
 *  To
 * PARAMETERS
 *  local_para_ptr      [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void DRM_app_parse_drm_message_hdlr(void *local_para_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_parse_dm_cnf_struct *cnf = (drmt_parse_dm_cnf_struct*) local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cnf->callback)
    {
        if (cnf->result < DRM_RESULT_OK)
        {
            cnf->callback(cnf->serial, cnf->result, NULL);
        }
        else
        {
            cnf->callback(cnf->serial, cnf->result, cnf->info);
        }
        drmt_mem_free(cnf->info);
    }
    drmt_async_set_status(cnf->serial, DRM_PROC_ENCRYPT_FINISHED);
    drmt_async_free_serial(cnf->serial);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_app_install_obj_hdlr
 * DESCRIPTION
 *  To
 * PARAMETERS
 *  local_para_ptr      [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void DRM_app_install_obj_hdlr(void *local_para_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_install_object_cnf_struct *cnf = (drmt_install_object_cnf_struct*) local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_INTERFACE_DEBUG("[DRM] app_install_obj_hdlr", (TRACE_GROUP_9, DRM_ITF_F7230E172E65A6BA608EAA6BE334BC12));

    if (cnf->callback)
    {
        if (cnf->result < DRM_RESULT_OK)
        {
            cnf->callback(cnf->serial, cnf->result, NULL);
        }
        else
        {
            cnf->callback(cnf->serial, cnf->result, cnf->mime_type);
        }
    }
    drmt_async_set_status(cnf->serial, DRM_PROC_ENCRYPT_FINISHED);
    drmt_async_free_serial(cnf->serial);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_app_encode_drm_message_hdlr
 * DESCRIPTION
 *  To
 * PARAMETERS
 *  local_para_ptr      [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void DRM_app_encode_drm_message_hdlr(void *local_para_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_encode_drm_message_cnf_struct *cnf = (drmt_encode_drm_message_cnf_struct*) local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //    DRM_INTERFACE_DEBUG("[DRM] app_encode_drm_message_hdlr",
    //            (TRACE_GROUP_9, DRM_ITF_F7230E172E65A6BA608EAA6BE334BC12));

    if (cnf->callback)
    {
        cnf->callback(cnf->serial, cnf->result);
    }
    drmt_async_set_status(cnf->serial, DRM_PROC_ENCRYPT_FINISHED);
    drmt_async_free_serial(cnf->serial);

}

#ifdef __DRM_V02__


/*****************************************************************************
 * FUNCTION
 *  DRM_app_ro_expiry_hdlr
 * DESCRIPTION
 *  To
 * PARAMETERS
 *  local_para_ptr      [?]     [?]
 *  time(?)             [IN](?)
 *  reliable(?)         [IN]        System (not user) modification or not.(?)
 * RETURNS
 *  void
 *****************************************************************************/
void DRM_app_ro_expiry_hdlr(void *local_para_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_ro_expiry_ind_struct *rsp = (drmt_ro_expiry_ind_struct*) local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp->callback && rsp->id >= 0)
    {
        if (drmt_consume_is_cb_executed(rsp->id))
        {
            DRM_INTERFACE_DEBUG(
                "[DRM] ro_expiry_hdlr cb executed",
                (TRACE_GROUP_9, DRM_ITF_D3609124D70935F282C63B9D34449EC8));
            drmt_clean_consume(rsp->id);
        }
        else
        {
            DRM_INTERFACE_DEBUG("[DRM] ro_expiry_hdlr", (TRACE_GROUP_9, DRM_ITF_8FB627CFA22FB559DFAB176F5D21E1FD));
            drmt_consume_set_cb_executed(rsp->id);
            rsp->callback(rsp->result, rsp->id);
        }
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  DRM_app_activate_hdlr
 * DESCRIPTION
 *  To
 * PARAMETERS
 *  local_para_ptr      [?]     [?]     [?]
 *  time(?)             [IN](?)(?)
 *  reliable(?)         [IN]        System (not user) modification or not.(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void DRM_app_activate_hdlr(void *local_para_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_activate_cnf_struct *cnf = (drmt_activate_cnf_struct*) local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_INTERFACE_DEBUG("[DRM] app_activate_hdlr", (TRACE_GROUP_9, DRM_ITF_B5BAEE0DF7509F4F33FF69BB43157617));

    if (cnf->callback)
    {
        cnf->callback(cnf->serial, cnf->result);
    }
    drmt_async_set_status(cnf->serial, DRM_PROC_ENCRYPT_FINISHED);
    drmt_async_free_serial(cnf->serial);
}
#endif /* __DRM_V02__ */ 


/*****************************************************************************
 * FUNCTION
 *  DRM_app_process_database_hdlr
 * DESCRIPTION
 * PARAMETERS
 *  local_para_ptr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void DRM_app_process_database_hdlr(void *local_para_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_process_database_cnf_struct *cnf = (drmt_process_database_cnf_struct*) local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cnf->callback)
    {
        cnf->callback(cnf->serial, cnf->result);
    }
    drmt_async_set_status(cnf->serial, DRM_PROC_ENCRYPT_FINISHED);
    drmt_async_free_serial(cnf->serial);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_app_get_ro_num_hdlr
 * DESCRIPTION
 * PARAMETERS
 *  local_para_ptr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void DRM_app_get_ro_num_hdlr(void *local_para_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_get_ro_num_cnf_struct *cnf = (drmt_get_ro_num_cnf_struct*) local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cnf->callback)
    {
        cnf->callback(cnf->serial, cnf->result);
    }
    drmt_async_set_status(cnf->serial, DRM_PROC_ENCRYPT_FINISHED);
    drmt_async_free_serial(cnf->serial);
}

#ifdef __DRM_SUPPORT_SCAN_DISK__


/*****************************************************************************
 * FUNCTION
 *  DRM_app_scan_disk_hdlr
 * DESCRIPTION
 *  scan disk handler
 * PARAMETERS
 *  local_para_ptr      [IN]        Confirm message
 * RETURNS
 *  void
 *****************************************************************************/
void DRM_app_scan_disk_hdlr(void *local_para_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_scan_disk_cnf_struct *cnf = (drmt_scan_disk_cnf_struct*) local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cnf->callback)
    {
        cnf->callback(cnf->serial, cnf->result);
    }
    drmt_async_set_status(cnf->serial, DRM_PROC_ENCRYPT_FINISHED);
    drmt_async_free_serial(cnf->serial);
}

#endif /* __DRM_SUPPORT_SCAN_DISK__ */ 
#ifdef __DRM_SUPPORT_SD_CALLBACK__


/*****************************************************************************
 * FUNCTION
 *  DRM_sd_callback_status
 * DESCRIPTION
 *  To get SD registration status by passing serial
 * PARAMETERS
 *  serial      [IN]        
 * RETURNS
 *  someone waiting or not
 *****************************************************************************/
kal_bool DRM_sd_callback_status(kal_uint8 serial)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drmt_sd_callback_status(serial);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_app_sd_expiry_hdlr
 * DESCRIPTION
 *  separate delivery expiry handler
 * PARAMETERS
 *  local_para_ptr      [IN]        Confirm message
 * RETURNS
 *  void
 *****************************************************************************/
void DRM_app_sd_expiry_hdlr(void *local_para_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_sd_expiry_ind_struct *ind = (drmt_sd_expiry_ind_struct*) local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ind->callback)
    {
        if (ind->callback(ind->para, ind->type))
        {
            drmt_sd_callback_clear_entry(ind->serial);
        }
        else
        {
            drmt_sd_callback_update(ind->serial);
        }
    }
}
#endif /* __DRM_SUPPORT_SD_CALLBACK__ */ 


/*****************************************************************************
 * FUNCTION
 *  DRM_app_common_hdlr
 * DESCRIPTION
 *  To
 * PARAMETERS
 *  ilm     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool DRM_app_common_hdlr(void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = (ilm_struct*) ilm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_DRMT_INSTALL_OBJECT_CNF:
            DRM_app_install_obj_hdlr((void*)ilm_ptr->local_para_ptr);
            return KAL_TRUE;
        case MSG_ID_DRMT_PARSE_DM_CNF:
            DRM_app_parse_drm_message_hdlr((void*)ilm_ptr->local_para_ptr);
            return KAL_TRUE;
        case MSG_ID_DRMT_ENCODE_DRM_MESSAGE_CNF:
            DRM_app_encode_drm_message_hdlr((void*)ilm_ptr->local_para_ptr);
            return KAL_TRUE;
    #ifdef __DRM_V02__
        case MSG_ID_DRMT_RO_EXPIRY_IND:
            DRM_app_ro_expiry_hdlr((void*)ilm_ptr->local_para_ptr);
            return KAL_TRUE;
        case MSG_ID_DRMT_ACTIVATE_CNF:
            DRM_app_activate_hdlr((void*)ilm_ptr->local_para_ptr);
            return KAL_TRUE;
    #endif /* __DRM_V02__ */ 
        case MSG_ID_DRMT_PROCESS_DATABASE_CNF:
            DRM_app_process_database_hdlr((void*)ilm_ptr->local_para_ptr);
            return KAL_TRUE;
        case MSG_ID_DRMT_GET_RO_NUM_CNF:
            DRM_app_get_ro_num_hdlr((void*)ilm_ptr->local_para_ptr);
            return KAL_TRUE;
    #ifdef __DRM_SUPPORT_SCAN_DISK__
        case MSG_ID_DRMT_SCAN_DISK_CNF:
            DRM_app_scan_disk_hdlr((void*)ilm_ptr->local_para_ptr);
            return KAL_TRUE;
    #endif /* __DRM_SUPPORT_SCAN_DISK__ */ 
    #ifdef __DRM_SUPPORT_SD_CALLBACK__
        case MSG_ID_DRMT_SD_EXPIRY_IND:
            DRM_app_sd_expiry_hdlr((void*)ilm_ptr->local_para_ptr);
            return KAL_TRUE;
    #endif /* __DRM_SUPPORT_SD_CALLBACK__ */ 
        default:
            return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  DRM_slave_common_hdlr
 * DESCRIPTION
 * PARAMETERS
 *  MsgStruct       [?]         
 *  mod_src         [IN]        
 *  ilm_p           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void DRM_slave_common_hdlr(void *MsgStruct, int mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drmt_msg_handler((ilm_struct*) ilm_p, KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_get_object_method_by_ref
 * DESCRIPTION
 *  get DRM method of a DRM content
 * PARAMETERS
 *  ro_index        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 DRM_get_object_method_by_ref(kal_int32 ro_index, drm_proc_db_ro_count_flag_enum flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_get_object_method_by_ref(ro_index, flag);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_get_constraint_by_ref
 * DESCRIPTION
 * PARAMETERS
 *  ro_index        [IN]        
 *  permission      [IN]        
 *  cons            [OUT]       
 * RETURNS
 *****************************************************************************/
kal_int32 DRM_get_constraint_by_ref(kal_int32 ro_index, kal_uint8 permission, drm_constraint_struct *cons)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_get_constraint_by_ref(ro_index, permission, cons);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_free_ro_detail
 * DESCRIPTION
 *  To free rights objects detail
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DRM_free_ro_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drm_core_free_ro_detail();
}

#if defined(__DRM_V02__) && defined(__DRM_PDCF__)


/*****************************************************************************
 * FUNCTION
 *  DRM_construct_pdcf
 * DESCRIPTION
 *  To construct a pdcf handle, this handle is used to control the whole
 *  decrypt scenario
 * PARAMETERS
 *  file_handle     [IN]        The file_handle, could be 0 in streaming case
 *  box(?)          [IN]        The mdri box, could be NULL in streaming case
 * RETURNS
 *  drm_proc_enum
 *****************************************************************************/
/*************************
 *  Important api usage flow -- local file playback:
 *
 *  fh1 = DRM_open_file( file_path, DRM_PERMISSION_PLAY );
 *  MED_parse_3gpp( fh1 box, kms1, kms2); (use DRM_read_file and DRM_seek_file to parse)
 *
 *  ph1 = DRM_construct_pdcf( fh1, box);
 *  th1 = DRM_init_track_by_kms( ph1, 0, DRM_PERMISSION_PLAY, kms1);
 *  th2 = DRM_init_track_by_kms( ph1, 1, DRM_PERMISSION_PLAY, kms2);
 *
 *  DRM_consume_right( fh1 );
 *  while(1)
 *  {
 *
 *      DRM_read_file( fh1, buffer1, &size1 );
 *      DRM_read_file( fh1, buffer2, &size2 );
 *      DRM_decode_track( th1, buffer1, &size1);
 *      DRM_decode_track( th2, buffer2, &size2);
 *  }
 *  DRM_stop_consume( fh1 );
 *
 *  DRM_destruct_pdcf( ph1 );
 *  DRM_close_file(file_path);
 *
 ***************************************************/
/*************************
 *  Important api usage flow -- streaming playback:
 *
 *  MED_parse_sdp(meta1, meta2);
 *
 *  ph1 = DRM_construct_pdcf( 0, NULL);
 *  th1 = DRM_init_track_by_kms( ph1, 0, DRM_PERMISSION_PLAY, meta1);
 *  th2 = DRM_init_track_by_kms( ph1, 0, DRM_PERMISSION_PLAY, meta2);
 *
 *  DRM_consume_right( ph1 );
 *  while(1)
 *  {
 *      socket_receive_data( buffer1, &size1 );
 *      socket_receive_data( buffer2, &size2 );
 *      DRM_decode_track( th1, buffer1, &size1);
 *      DRM_decode_track( th2, buffer2, &size2);
 *  }
 *  DRM_stop_consume( ph1 );
 *
 *  DRM_destruct_pdcf( ph1 );
 *
 ***************************************************/
kal_int32 DRM_construct_pdcf(kal_int32 file_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* bsci_initPdcf */
    return drm_core_construct_pdcf(file_handle);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_init_track_by_kms
 * DESCRIPTION
 *  Ininital track decoder via key management system
 * PARAMETERS
 *  pdcf_handle     [IN]        Return by DRM_construct_pdcf
 *  trackID         [IN]        0~n-1, should inital sequencely or assert
 *  permission      [IN]        DRM_PERMISSION_PLAY
 *  kms             [IN]        Drm key management system
 * RETURNS
 *  drm_proc_enum
 *****************************************************************************/
/* local playback use */
kal_int32 DRM_init_track_by_kms(
            kal_int32 pdcf_handle,
            kal_int32 trackID,
            kal_uint8 permission,
            drm_track_kms_struct *kms)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_init_track_by_kms(pdcf_handle, trackID, permission, kms);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_init_track_by_meta
 * DESCRIPTION
 *  Ininital track decoder via key management system
 * PARAMETERS
 *  pdcf_handle     [IN]        Return by DRM_construct_pdcf
 *  trackID         [IN]        0~n-1, should inital sequencely or assert
 *  permission      [IN]        DRM_PERMISSION_PLAY
 *  meta            [IN]        Meta data
 * RETURNS
 *  drm_proc_enum
 *****************************************************************************/
/* streaming use */
kal_int32 DRM_init_track_by_meta(
            kal_int32 pdcf_handle,
            kal_int32 trackID,
            kal_uint8 permission,
            drm_track_meta_struct *meta)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_init_track_by_meta(pdcf_handle, trackID, permission, meta);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_destruct_pdcf
 * DESCRIPTION
 *  destruct pdcf handle
 * PARAMETERS
 *  pdcf_handle     [IN]        Return by DRM_construct_pdcf
 * RETURNS
 *****************************************************************************/
kal_int32 DRM_destruct_pdcf(kal_int32 pdcf_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_destruct_pdcf(pdcf_handle);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_decode_track
 * DESCRIPTION
 *  decode the pdcf data
 * PARAMETERS
 *  track_handle        [IN]            Return by DRM_init_track_by_meta or DRM_init_track_by_kms
 *  src                 [IN]            The buffer try to decode, includes the au header
 *  srcSize             [IN]            The buffer size
 *  out                 [OUT]           The buffer we put the resource, can be same as src
 *  outSize             [IN/OUT]        The buffer size, and we output the final size.
 *  is_streaming        [IN]            
 * RETURNS
 *  drm_proc_enum
 *****************************************************************************/
kal_int32 DRM_decode_track(
            kal_int32 track_handle,
            kal_uint8 *src,
            kal_uint32 srcSize,
            kal_uint8 *out,
            kal_uint32 *outSize,
            kal_bool is_streaming)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_decode_track(track_handle, src, srcSize, out, outSize, is_streaming);
}

#endif /* defined(__DRM_V02__) && defined(__DRM_PDCF__) */ 


#endif /* !__DRM_EXTERNAL__ */


#else /* __DRM_SUPPORT__ */ 
#include "syscomp_config.h"


/*****************************************************************************
 * FUNCTION
 *  DRM_open_file
 * DESCRIPTION
 *  open file, if file is a DRM content, retreive rights information. otherwise simply open file.
 * PARAMETERS
 *  file_path       [IN]        
 *  flags           [IN]        
 *  permission      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
FS_HANDLE DRM_open_file(kal_wchar *file_path, kal_uint32 flags, kal_uint8 permission)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return FS_OpenHint(file_path, flags, DRM_get_open_hint(file_path));
}


/*****************************************************************************
 * FUNCTION
 *  DRM_close_file
 * DESCRIPTION
 *  close file, if file is a DRM content, deinit rights information. otherwise simply close file.
 * PARAMETERS
 *  object      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 DRM_close_file(FS_HANDLE object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return FS_Close(object);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_read_file
 * DESCRIPTION
 *  read data from file, if file is a DRM content, decrypt or seek to the right location before read
 * PARAMETERS
 *  source      [IN]        
 *  buffer      [IN]        
 *  size        [IN]        
 *  length      [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 DRM_read_file(FS_HANDLE source, void *buffer, kal_uint32 size, kal_uint32 *length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return FS_Read(source, buffer, size, length);
}


/*****************************************************************************
 * FUNCTION
 *  DRM_seek_file
 * DESCRIPTION
 *  seek file, if file is a DRM content, decrypt or seek to the right location for it
 * PARAMETERS
 *  source      [IN]        
 *  offset      [IN]        
 *  ref         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 DRM_seek_file(FS_HANDLE source, kal_int32 offset, kal_uint8 ref)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return FS_Seek(source, offset, ref);
}

/*****************************************************************************
 * FUNCTION
 *  DRM_seek_file
 * DESCRIPTION
 *  seek file, if file is a DRM content, decrypt or seek to the right location for it
 * PARAMETERS
 *  source      [IN]        
 *  offset      [IN]        
 *  ref         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int64 DRM_seek_large_file(FS_HANDLE source, kal_int64 offset, kal_uint8 ref)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return FS_SeekLargeFile(source, offset, ref);
}

#ifndef __LOW_COST_SUPPORT_ULC__    /* FS do not support this function on low cost project */
/*****************************************************************************
 * FUNCTION
 *  DRM_set_seek_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  HintNum     [IN]        
 *  Hint        [?]         [?]         [?]
 *  source(?)       [IN](?)(?)
 *  ref(?)          [IN](?)(?)
 *  offset(?)       [IN](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 DRM_set_seek_hint(FS_HANDLE handle, UINT HintNum, FS_FileLocationHint *Hint)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return FS_SetSeekHint(handle, HintNum, Hint);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  DRM_file_size
 * DESCRIPTION
 *  get file size, if file is a DRM content, decrypt and remove header size
 * PARAMETERS
 *  source      [IN]        
 *  size        [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 DRM_file_size(FS_HANDLE source, kal_uint32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return FS_GetFileSize(source, size);
}

//#ifndef __LOW_COST_SUPPORT_ULC__    /* We do not support this function on low cost project */
/*****************************************************************************
 * FUNCTION
 *  DRM_file_pos
 * DESCRIPTION
 *  get file position, if file is a DRM content, decrypt and change file postition information by removing header
 * PARAMETERS
 *  source      [IN]        
 *  pos         [OUT]       
 * RETURNS
 *  zero for success            (1.0)
 *  negative for error code     (1.0/2.0)
 *  positive for content number (2.0)
 *****************************************************************************/
kal_int32 DRM_file_pos(FS_HANDLE source, kal_uint32 *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return FS_GetFilePosition(source, pos);
}
//#endif

/*****************************************************************************
 * FUNCTION
 *  drmt_create
 * DESCRIPTION
 *  DRM task create function
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  success or fail
 *****************************************************************************/
kal_bool drmt_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  DRM_get_content_type
 * DESCRIPTION
 *  Dummy function
 * PARAMETERS
 *  handle      [IN]        
 *  path        [?]         [?]         [?]
 *  input(?)        [IN](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 *DRM_get_content_type(FS_HANDLE handle, kal_wchar *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return NULL;
}

#endif /* __DRM_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  DRM_get_open_hint
 * DESCRIPTION
 *  open file, if file is a DRM content, retreive rights information. otherwise simply open file.
 * PARAMETERS
 *  file_path           [IN]        
 *  flags(?)            [IN]        
 *  permission(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
FS_FileOpenHint *DRM_get_open_hint(kal_wchar *file_path)
{
#if defined(__DRM_SUPPORT__) && defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module = stack_get_active_module_id();
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = MAX_OPEN_HINT_SIZE - 1; i >= 0; i--)
    {
        if (open_hint_module[i] == module)
        {
            if (open_hint_file_path[i])
            {
                if (app_ucs2_wcscmp(file_path, open_hint_file_path[i]) != 0)
                {
                    memset(&open_hint[i], 0, sizeof(FS_FileOpenHint));
                    //                    drmt_mem_free(open_hint_file_path[i]);
                    //                  open_hint_file_path[i] = drmt_mem_alloc((app_ucs2_wcslen(file_path)+1) * 2);
                    app_ucs2_wcsncpy(open_hint_file_path[i], file_path, DRM_MAX_PATH_LENGTH - 1);
                }
            }
            else
            {
                /* open_hint_file_path[i] = drmt_mem_alloc((app_ucs2_wcslen(file_path)+1) * 2); */
                open_hint_file_path[i] = drmt_mem_alloc(DRM_MAX_PATH_LENGTH * 2);
                app_ucs2_wcsncpy(open_hint_file_path[i], file_path, DRM_MAX_PATH_LENGTH - 1);
            }

            return &open_hint[i];
        }
    }
#endif /* defined(__DRM_SUPPORT__) && defined(__MTK_TARGET__) */ 
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  DRM_clean_open_hint
 * DESCRIPTION
 *  Clear all open hint
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DRM_clean_open_hint(void)
{
#if defined(__DRM_SUPPORT__) && defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = MAX_OPEN_HINT_SIZE - 1; i >= 0; i--)
    {
        if (open_hint_file_path[i])
        {
            open_hint_file_path[i][0] = '\0';
        }
    }
#endif /* defined(__DRM_SUPPORT__) && defined(__MTK_TARGET__) */ 
}

