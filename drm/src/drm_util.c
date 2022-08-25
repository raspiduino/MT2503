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
 * drm_util.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifdef __DRM_SUPPORT__
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "app_mine.h"
#include "app_str.h"

#include "drm_def.h"
#include "drm_main.h"
#include "drm_util.h"
#include "FileMgrSrvGProt.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "stack_ltlcom.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "drm_errcode.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "kal_active_module.h"
#include "nvram_interface.h"
#include "kal_public_api.h"
#include "kal_trace.h"


#if !defined(__DRM_EXTERNAL__)

kal_wchar *drm_get_extension(kal_wchar *file_path) ;

/*****************************************************************************
 * FUNCTION
 *  drm_send_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_id              [IN]        
 *  dst_id              [IN]        
 *  msg_id              [IN]        
 *  local_para_ptr      [?]         [?]         [?]
 *  peer_buff_ptr       [?]         [?]         [?]
 *  ilm_id(?)           [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void drm_send_msg(kal_int32 src_id, kal_int32 dst_id, kal_int32 msg_id, void *local_para_ptr, void *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    sap_type sap_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (dst_id)
    {
        case MOD_WPS:
            sap_id = DRMT_WAP_SAP;
            break;
        case MOD_MMI:
            sap_id = DRMT_MMI_SAP;
            break;
        case MOD_DRMT:
            sap_id = DRMT_APP_SAP;
            break;
        case MOD_NVRAM:
            sap_id = PS_NVRAM_SAP;
            break;
        default:
            sap_id = INVALID_SAP;
            break;
    }   /* switch (dst_id) */

    ilm_ptr = allocate_ilm(src_id);
    ilm_ptr->src_mod_id = src_id;
    ilm_ptr->dest_mod_id = dst_id;
    ilm_ptr->sap_id = sap_id;
    ilm_ptr->msg_id = msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_para_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buff_ptr;

    if (dst_id == MOD_DRMT)
    {
        if (msg_id == MSG_ID_DRMT_PROCESS_DATABASE_REQ || msg_id == MSG_ID_DRMT_GET_RO_NUM_REQ)
        {
            drmt_engine_set_busy(KAL_TRUE);
        }

        if (msg_id == MSG_ID_DRMT_PROCESS_DATABASE_REQ)
        {
            drmt_engine_set_process_database(KAL_TRUE);
        }
    }
    else if (src_id == MOD_DRMT)
    {
        if (msg_id == MSG_ID_DRMT_PROCESS_DATABASE_CNF || msg_id == MSG_ID_DRMT_GET_RO_NUM_CNF)
        {
            drmt_engine_set_busy(KAL_FALSE);
        }
        if (msg_id == MSG_ID_DRMT_PROCESS_DATABASE_CNF)
        {
            drmt_engine_set_process_database(KAL_FALSE);
        }
    }

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  drm_replace_file_extension_secure
 * DESCRIPTION
 *  replace extension file name according to its mime type
 * PARAMETERS
 *  buf                 [?]         
 *  buf_size            [IN]        
 *  entry               [?]         
 *  path(?)             [IN]        
 *  mime_type(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool drm_replace_file_extension_secure(kal_wchar *buf, kal_int32 buf_size, applib_mime_type_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *ptr;
    kal_char *ext = NULL;
    kal_int32 ext_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buf == NULL)
    {
        return KAL_FALSE;
    }

    if (buf_size == 0)
    {
        buf_size = app_ucs2_strlen((kal_int8*) buf) * 2 + 2;
    }

    ptr = drm_get_extension(buf);

    if (ptr == NULL)
    {
        ext_len++;  /* . */
    }

    if (entry == NULL)
    {
        ext = NULL;
        ext_len += 3;   /* tmp */
    }
    else
    {
        ext = entry->file_ext;
        ext_len += strlen(ext);
    }

    if ((app_ucs2_strlen((kal_int8*) buf) - app_ucs2_strlen((kal_int8*) ptr) + ext_len + 1) * 2 > buf_size)
    {
        return KAL_FALSE;
    }

    if (ptr == NULL)
    {
        ptr = buf + app_ucs2_strlen((kal_int8*) buf);
        app_asc_str_to_ucs2_str((kal_int8*) ptr++, (kal_int8*) ".");
    }

    if (entry != NULL && ext)
    {
        app_asc_str_to_ucs2_str((kal_int8*) ptr, (kal_int8*) ext);
    }
    else
    {
        app_asc_str_to_ucs2_str((kal_int8*) ptr, (kal_int8*) "tmp");
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drm_replace_file_extension
 * DESCRIPTION
 *  replace extension file name according to its mime type
 * PARAMETERS
 *  path            [IN]        
 *  mime_type       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void drm_replace_file_extension(kal_wchar *path, kal_uint32 mime_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *ptr;
    kal_char *ext = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mime_type != 0xFF)
    {
        ext = (kal_char*) mime_to_ext(int_to_mime(mime_type));
    }
        
    ptr = drm_get_extension(path);
    if (ptr == NULL)
    {
        /* WARNING: This might cause memory corruption */
        ptr = path + app_ucs2_strlen((kal_int8*) path);
        if (ext && strlen(ext))
        {
            app_asc_str_to_ucs2_str((kal_int8*) ptr++, (kal_int8*)".");
        }
    }

    if (ext && strlen(ext))
    {
        if (mime_type == 0xFF)
        {
            app_asc_str_to_ucs2_str((kal_int8*) ptr, (kal_int8*)"tmp");
        }
        else
        {
            app_asc_str_to_ucs2_str((kal_int8*) ptr, (kal_int8*)ext);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  drm_get_line
 * DESCRIPTION
 *  read a line (ended with CRLF) from file
 * PARAMETERS
 *  strOutput       [IN]        
 *  length          [IN]        
 *  fh              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 drm_get_line(kal_char *strOutput, kal_uint32 length, FS_HANDLE fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char strCRLF[4];
    kal_char *currCursor;
    kal_uint32 strLen = 0;
    kal_uint32 nBytes = 0;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(strCRLF, "%c%c", 0x0d, 0x0a);
    memset(strOutput, 0, length);

    result = FS_Read(fh, strOutput, length - 1, &nBytes);
    if (result >= FS_NO_ERROR)
    {
        if (nBytes == 0)
            /* EOF */
        {
            return DRM_RESULT_EOF;
        }
    }
    else
    {
        return result;
    }

    if ((currCursor = strstr(strOutput, strCRLF)) != NULL)  /* find out first CRLF */
    {
        strLen = (int)(currCursor - strOutput);
        strOutput[strLen] = 0;

        FS_Seek(fh, (strLen - nBytes + 2), FS_FILE_CURRENT);
        nBytes = strLen;
    }
    else    /* CRLF not found, read until CRLF */
    {
        sprintf(strCRLF, "%c", 0x0a);

        if ((currCursor = strstr(strOutput, strCRLF)) != NULL)  /* find out first CRLF */
        {
            strLen = (int)(currCursor - strOutput);
            strOutput[strLen] = 0;

            FS_Seek(fh, (strLen - nBytes + 1), FS_FILE_CURRENT);
            nBytes = strLen;
        }
        else
        {
            strOutput[nBytes] = 0;
        }
    }

    return nBytes;
}


/*****************************************************************************
 * FUNCTION
 *  drm_is_version_change
 * DESCRIPTION
 *  to indicate version change status
 * PARAMETERS
 *  void
 * RETURNS
 *  KAL_TRUE: changed
 *  KAL_FALSE: no
 *****************************************************************************/
kal_bool drm_is_version_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_verno_change;
}


/*****************************************************************************
 * FUNCTION
 *  drm_get_error_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  error       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drm_get_error_string(int error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = (kal_int32) srv_fmgr_fs_error_get_string(error);
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  drm_check_free_space
 * DESCRIPTION
 *  check if have enought space to save file
 * PARAMETERS
 *  drv             [IN]        Check which storage
 *  need_space      [IN]        How many space we need.
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
kal_bool drm_check_free_space(kal_int32 drv, kal_uint64 need_space)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 fs_ret;
    FS_DiskInfo disk_info;
    kal_uint16 path[4];
    kal_uint64 disk_free_space = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drv < 0)
    {
        return KAL_FALSE;
    }

    path[0] = drv;
    path[1] = ':';
    path[2] = '\\';
    path[3] = 0;

    fs_ret = FS_GetDiskInfo((const WCHAR*)path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
    if (fs_ret >= 0)
    {
        disk_free_space = (kal_uint64) disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
        if (disk_free_space < need_space)
        {
            return KAL_FALSE;
        }
        else
        {
            return KAL_TRUE;
        }
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  drm_read_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lid         [IN]        
 *  rec         [IN]        
 *  amount      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void drm_read_nvram(nvram_lid_enum lid, kal_uint16 rec, kal_uint16 amount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_read_req_struct *read_req =
        (nvram_read_req_struct*) construct_local_para(sizeof(nvram_read_req_struct), TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    read_req->file_idx = lid;
    read_req->para = rec;
    read_req->rec_amount = amount;

    drm_send_msg(stack_get_active_module_id(), MOD_NVRAM, MSG_ID_NVRAM_READ_REQ, (void*)read_req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  drm_write_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lid         [IN]        
 *  rec         [IN]        
 *  data        [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void drm_write_nvram(nvram_lid_enum lid, kal_uint16 rec, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_write_req_struct *write_req;
    peer_buff_struct *data_stream;
    kal_uint16 pdu_len, total;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_get_info((kal_uint8) lid, &total, &pdu_len);

    write_req = (nvram_write_req_struct*) construct_local_para(sizeof(nvram_write_req_struct), TD_RESET);
    data_stream = construct_peer_buff(pdu_len, 0, 0, TD_RESET);

    write_req->file_idx = lid;
    write_req->para = rec;

    kal_mem_cpy(get_pdu_ptr(data_stream, &pdu_len), data, pdu_len);

    drm_send_msg(
        stack_get_active_module_id(),
        MOD_NVRAM,
        MSG_ID_NVRAM_WRITE_REQ,
        (void*)write_req,
        (void*)data_stream);
}


/*****************************************************************************
 * FUNCTION
 *  drm_get_permission_ext
 * DESCRIPTION
 *  get corresponding permission type for content of specific mime type
 * PARAMETERS
 *  entry               [?]         
 *  mime_string(?)      [IN]        
 *  mime_type(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 drm_get_permission_ext(applib_mime_type_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (entry == NULL)
    {
        return DRM_PERMISSION_NONE;
    }
    switch (entry->mime_type)
    {
        case MIME_TYPE_IMAGE:
            return DRM_PERMISSION_DISPLAY;

        case MIME_TYPE_AUDIO:
        case MIME_TYPE_VIDEO:
            return DRM_PERMISSION_PLAY;

        case MIME_TYPE_APPLICATION:
            if (entry->mime_subtype == MIME_SUBTYPE_JAD || entry->mime_subtype == MIME_SUBTYPE_JAR)
            {
                return DRM_PERMISSION_EXECUTE;
            }
            else
            {
                break;
            }
        default:
            break;
    }
    return DRM_PERMISSION_NONE;

}


/*****************************************************************************
 * FUNCTION
 *  drm_get_permission_by_path
 * DESCRIPTION
 *  get corresponding permission type for content of specific mime type
 * PARAMETERS
 *  filepath            [?]         
 *  mime_string(?)      [IN]        
 *  mime_type(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 drm_get_permission_by_path(kal_wchar *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mime_type_struct *entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry = applib_mime_get_file_type((kal_wchar*) filepath);

    return drm_get_permission_ext(entry);
}


/*****************************************************************************
 * FUNCTION
 *  drm_get_permission
 * DESCRIPTION
 *  get corresponding permission type for content of specific mime type
 * PARAMETERS
 *  mime_string     [IN]        
 *  mime_type       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 drm_get_permission(kal_uint8 *mime_string, kal_uint32 mime_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mime_type_struct *entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry = applib_mime_type_look_up((kal_char*) mime_string, NULL, 0, mime_type);

    return drm_get_permission_ext(entry);
}


/*****************************************************************************
 * FUNCTION
 *  toLower
 * DESCRIPTION
 *  convert ASCII string to lower case
 * PARAMETERS
 *  str     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void toLower(kal_uint8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = str;
    while (*ptr != 0)
    {
        if ((*ptr >= 'A') && (*ptr <= 'Z'))
        {
            *ptr += 'a' - 'A';
        }
        ptr++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mime_to_int
 * DESCRIPTION
 *  This function is called to map mime type string to int
 * PARAMETERS
 *  mime        [IN]        Pointer to the mime type string
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 mime_to_int(const char *mime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mime_type_struct *entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry = applib_mime_type_look_up((kal_char*) mime, NULL, 0, 0);
    if (entry != NULL)
    {
        return entry->mime_subtype;
    }
    else
    {
        return -1;
    }

#if 0
#ifdef OBIGO_SUPPORT
/* under construction !*/
#else /* OBIGO_SUPPORT */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* OBIGO_SUPPORT */ 
#endif /* 0 */ 
}


/*****************************************************************************
 * FUNCTION
 *  int_to_mime
 * DESCRIPTION
 *  This function is called to map mime type value to string
 * PARAMETERS
 *  mime_value      [IN]        Mime type value
 * RETURNS
 *  void
 *****************************************************************************/
const char *int_to_mime(kal_int32 mime_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mime_type_struct *entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry = applib_mime_type_look_up(NULL, NULL, 0, mime_value);
    if (entry != NULL)
    {
        return entry->mime_string;
    }
    else
    {
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mime_to_ext
 * DESCRIPTION
 *  This function is called to map mime type string to ext file name
 * PARAMETERS
 *  mime        [IN]        Mime type string
 * RETURNS
 *  void
 *****************************************************************************/
const char *mime_to_ext(const char *mime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mime_type_struct *entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry = applib_mime_type_look_up((kal_char*) mime, NULL, 0, 0);
    if (entry != NULL)
    {
        return entry->file_ext;
    }
    else
    {
        return NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  drm_get_extension
 * DESCRIPTION
 *  get extension file name of a file path
 * PARAMETERS
 *  file_path       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_wchar *drm_get_extension(kal_wchar *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 length, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = app_ucs2_strlen((const kal_int8*)file_path);

    for (i = length - 1; i >= 0; i--)
    {
        if (file_path[i] == '.')
        {
            return &file_path[i + 1];
        }
    }
    return NULL;
}
/*****************************************************************************
 * FUNCTION
 *  drm_trace
 * DESCRIPTION
 *  print message to console or catcher log
 * PARAMETERS
 *  ival            [IN]        The trace class
 *  arg_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void drm_trace(trace_class_enum ival, const char *arg_type, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    va_list MyList;
    char buffer[256];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* DRM_TRACE_MUTEX_BEGIN; */

   if (kal_disable_trace(MOD_DRMT, TRACE_FUNC + ival))
    {
        return;
    }


    kal_take_mutex(mmi_mutex_trace);

    va_start(MyList, arg_type);
    _vsnprintf(buffer, 255, arg_type, MyList);
    va_end(MyList);

#if 0   /* ndef __MTK_TARGET__ */
/* under construction !*/
/* under construction !*/
#else /* 0 */ /* __MTK_TARGET__ */
    kal_wap_trace(MOD_DRMT, TRACE_FUNC + ival, buffer);
#endif /* 0 */ /* __MTK_TARGET__ */

    kal_give_mutex(mmi_mutex_trace);

    /* DRM_TRACE_MUTEX_END; */
}
#endif /* !__DRM_EXTERNAL__ */

#endif /* __DRM_SUPPORT__ */ 

