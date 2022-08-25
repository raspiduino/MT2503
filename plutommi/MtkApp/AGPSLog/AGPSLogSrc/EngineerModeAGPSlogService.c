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
 *  EngineerModeAGPSlogService.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Service part of AGPS log system.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_features.h"
#include "EngineerModeAGPSlogGprot.h"

#ifdef __AGPS_LOG_SUPPORT__
#include "EngineerModeAGPSlogProt.h"
#include "FileMgrSrvGProt.h"
#include "kal_public_defs.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "kal_public_api.h"
#include "app_datetime.h"
#include "DateTimeType.h"


/*****************************************************************************
 * Typedef
 *****************************************************************************/

typedef struct
{
    kal_char magic_pattern[EM_AGPSLOG_LOG_FILE_MAGIC_PATTERN_LENGTH];
    kal_uint8 version;
    kal_uint8 reserved[3];
} em_agpslog_file_header;

/*****************************************************************************
 * Static Declaration
 *****************************************************************************/

em_agpslog_config_struct g_em_agpslog_config = { 0 };

kal_mutexid log_lock;
#define EM_AGPSLOG_LOCK()   kal_take_mutex(log_lock)
#define EM_AGPSLOG_UNLOCK() kal_give_mutex(log_lock)

static kal_bool g_em_agpslog_enabled = KAL_FALSE;

static em_agpslog_log_buffer_struct g_em_agpslog_log_of_session[EM_AGPSLOG_MAX_CONCURRENT_SESSION_NUM];
static em_agpslog_log_buffer_struct *g_em_agpslog_active_log_p = NULL;


/*****************************************************************************
 * Global Function: Module Private
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_check_and_create_dir
 * DESCRIPTION
 *  This function checks the existence of directory. if not exist, it will
 *  create one.
 * PARAMETERS
 *  path            [IN]            Directory path
 * RETURNS
 *  KAL_TRUE if exists or successfully created.
 * RETURN VALUE LIST
 *  kal_bool
 *****************************************************************************/
static kal_bool em_agpslog_check_and_create_dir(const WCHAR* path)
{
#ifndef __EM_AGPSLOG_DEBUG_ON_VC__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE dir_hdlr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dir_hdlr = FS_Open(path, FS_OPEN_DIR | FS_READ_ONLY);
    if (dir_hdlr == FS_FILE_NOT_FOUND || dir_hdlr == FS_PATH_NOT_FOUND)
    {
        /* Directory does not exist, create it. */
        if (FS_CreateDir(path) != FS_NO_ERROR)
        {
            return KAL_FALSE;
        }
    }
    else if (dir_hdlr > 0)
    {
         FS_Close(dir_hdlr);
    }
#endif

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_init_directories
 * DESCRIPTION
 *  Initialize necessary directories of AGPS log.
 * PARAMETERS
 *  void
 * RETURNS
 *  KAL_TRUE if all directory exist or successfully created.
 * RETURN VALUE LIST
 *  kal_bool
 *****************************************************************************/
kal_bool em_agpslog_init_directories(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    /* Check & create home dir */
    if (!em_agpslog_check_and_create_dir(g_em_agpslog_config.home_dir))
    {
        return KAL_FALSE;
    }

    /* Check & create log dir */
    if (!em_agpslog_check_and_create_dir(g_em_agpslog_config.log_dir))
    {
        return KAL_FALSE;
    }

    /* Check & create template dir */
    if (!em_agpslog_check_and_create_dir(g_em_agpslog_config.template_dir))
    {
        return KAL_FALSE;
    }

    /* Check & create export dir */
    if (!em_agpslog_check_and_create_dir(g_em_agpslog_config.export_dir))
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_init_config
 * DESCRIPTION
 *  Initialize g_em_agpslog_config.
 * PARAMETERS
 *  void
 * RETURNS
 *  KAL_TRUE if initialized successfully.
 * RETURN VALUE LIST
 *  kal_bool
 *****************************************************************************/
static kal_bool em_agpslog_init_config(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char log_drive_letter = 'Z' ;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* get drive letter of log */
    log_drive_letter = SRV_FMGR_PUBLIC_DRV;

    kal_wsprintf(g_em_agpslog_config.home_dir, "%c:\\%w", log_drive_letter, EM_AGPSLOG_DEFAULT_HOME_DIR);
    kal_wsprintf(g_em_agpslog_config.log_dir, "%w%w", g_em_agpslog_config.home_dir, EM_AGPSLOG_DEFAULT_LOG_DIRNAME);
    kal_wsprintf(g_em_agpslog_config.template_dir, "%w%w", g_em_agpslog_config.home_dir, EM_AGPSLOG_DEFAULT_TEMPLATE_DIRNAME);
    kal_wsprintf(g_em_agpslog_config.export_dir, "%w%w", g_em_agpslog_config.home_dir, EM_AGPSLOG_DEFAULT_EXPORT_DIRNAME);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_init
 * DESCRIPTION
 *  Initialize AGPS log system.
 *  Be sure to call this function before any log operations.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void em_agpslog_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_em_agpslog_config.inited_magic == EM_AGPSLOG_CONFIG_INITED_MAGIC)
    {
        return;
    }
    
    log_lock = kal_create_mutex("AGPSlog mutex");

    for (i = 0; i < EM_AGPSLOG_MAX_CONCURRENT_SESSION_NUM; i++)
    {
        g_em_agpslog_log_of_session[i].session_id = 0;
        g_em_agpslog_log_of_session[i].buffer = NULL;
    }

    /* AGPS log can work only after all inits successed */
    g_em_agpslog_config.inited_magic = 0;
    if (em_agpslog_init_config())
    {
        g_em_agpslog_config.inited_magic = EM_AGPSLOG_CONFIG_INITED_MAGIC;
    }

    g_em_agpslog_active_log_p = NULL;

    em_agpslog_set_enabled(KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_set_enabled
 * DESCRIPTION
 *  Set enabled param of AGPS log.
 * PARAMETERS
 *  enabled      [IN] KAL_TRUE to activate log
 * RETURNS
 *  void
 *****************************************************************************/
void em_agpslog_set_enabled(const kal_bool enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EM_AGPSLOG_LOCK();
    g_em_agpslog_enabled = enabled;
    EM_AGPSLOG_UNLOCK();
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_get_enabled
 * DESCRIPTION
 *  Is AGPS log activated?
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool em_agpslog_get_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool enabled;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EM_AGPSLOG_LOCK();
    enabled = g_em_agpslog_enabled;
    EM_AGPSLOG_UNLOCK();

    return enabled;
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_write_magic_pattern
 * DESCRIPTION
 *  Write the magic pattern(number) of raw log file to f_hdlr
 * PARAMETERS
 *  f_hdlr      [IN] Log file
 * RETURNS
 *  void
 *****************************************************************************/
static void em_agpslog_write_log_file_header(FS_HANDLE f_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 magic_pattern[] = EM_AGPSLOG_LOG_FILE_MAGIC_PATTERN;
    em_agpslog_file_header file_header;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_mem_cpy(file_header.magic_pattern, magic_pattern, sizeof(magic_pattern));
    file_header.version = EM_AGPSLOG_VERSION;
    kal_mem_set(file_header.reserved, 0, sizeof(file_header.reserved));

    FS_Write(
        f_hdlr,
        &file_header,
        sizeof(file_header),
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_read_log_file_header
 * DESCRIPTION
 *
 * PARAMETERS
 *  f_hdlr      [IN] Log file
 *  version     [OUT] Version info of log file
 * RETURNS
 *  void
 *****************************************************************************/
em_agpslog_log_file_status_enum em_agpslog_read_log_file_header(
    FS_HANDLE f_hdlr,
    kal_uint16 *version)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 magic_pattern[] = EM_AGPSLOG_LOG_FILE_MAGIC_PATTERN;
    em_agpslog_file_header file_header;
    kal_int32 cmp_result;
    UINT n_read;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FS_Read(f_hdlr, &file_header, sizeof(file_header), &n_read);

    if (n_read != sizeof(file_header))
    {
        return EM_AGPSLOG_LOG_FILE_STATUS_INVALID_FILE;
    }

    cmp_result = kal_mem_cmp(file_header.magic_pattern, magic_pattern, sizeof(magic_pattern));
    
    if (cmp_result != 0)
    {
        return EM_AGPSLOG_LOG_FILE_STATUS_INVALID_HEADER;
    }

    *version = file_header.version;

    if (file_header.version != EM_AGPSLOG_VERSION)
    {
        return EM_AGPSLOG_LOG_FILE_STATUS_UNSUPPORTED_VERSION;
    }

    return EM_AGPSLOG_LOG_FILE_STATUS_GOOD;
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_get_log_file_handler
 * DESCRIPTION
 *  Generate log file name and open it.
 * PARAMETERS
 *  session_id      [IN] Session ID
 * RETURNS
 *  FS_HANDLE: log file; < 0 if failed.
 *****************************************************************************/
static FS_HANDLE em_agpslog_get_log_file_handler(const kal_uint32 session_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE f_hdlr;
    applib_time_struct time;
    WCHAR w_file_path[EM_AGPSLOG_MAX_PATH_LENGTH];
    kal_char file_name[EM_AGPSLOG_MAX_FILENAME_LENGTH];
    kal_char* file_name_tail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* filename generation */
    file_name_tail = file_name;
    GetDateTime(&time);
    em_agpslog_itoa(file_name_tail, time.nYear, 0);
    file_name_tail += em_agpslog_strlen(file_name_tail);
    em_agpslog_itoa(file_name_tail, time.nMonth, 2);
    file_name_tail += 2;
    em_agpslog_itoa(file_name_tail, time.nDay, 2);
    file_name_tail += 2;
    em_agpslog_strcpy(file_name_tail, "_");
    file_name_tail++;
    em_agpslog_itoa(file_name_tail, time.nHour, 2);
    file_name_tail += 2;
    em_agpslog_itoa(file_name_tail, time.nMin, 2);
    file_name_tail += 2;
    em_agpslog_itoa(file_name_tail, time.nSec, 2);
    file_name_tail += 2;
    em_agpslog_strcpy(file_name_tail, "_");
    file_name_tail++;
    em_agpslog_itoa(file_name_tail, session_id, 0);

#ifdef __EM_AGPSLOG_DEBUG_ON_VC__
    mmi_asc_to_ucs2((S8*)w_file_path, (S8*)file_name);
#else
    kal_wsprintf(w_file_path, "%w%s", g_em_agpslog_config.log_dir, file_name);
#endif

    f_hdlr = FS_Open(w_file_path, FS_CREATE | FS_READ_WRITE);

    return f_hdlr;
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_start_session
 * DESCRIPTION
 *  Start a session log. Allocate resource for the log.
 * PARAMETERS
 *  session_id      [IN] Session ID
 * RETURNS
 *  KAL_TRUE if resource allocation succeed.
 *****************************************************************************/
kal_bool em_agpslog_start_session(const kal_uint32 session_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    em_agpslog_log_buffer_struct *log_buffer_p;
    FS_HANDLE f_hdlr;
    kal_bool result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = KAL_FALSE;
    log_buffer_p = NULL;

    EM_AGPSLOG_LOCK();

    if (!g_em_agpslog_enabled)
    {
        result = KAL_FALSE;
        goto em_agpslog_start_session_return;
    }

    if (g_em_agpslog_config.inited_magic != EM_AGPSLOG_CONFIG_INITED_MAGIC)
    {
        result = KAL_FALSE;
        goto em_agpslog_start_session_return;
    }

    if (!em_agpslog_init_directories())
    {
        result = KAL_FALSE;
        goto em_agpslog_start_session_return;
    }

    for (i = 0; i < EM_AGPSLOG_MAX_CONCURRENT_SESSION_NUM; i++)
    {
        if (g_em_agpslog_log_of_session[i].buffer != NULL &&
        g_em_agpslog_log_of_session[i].session_id == session_id)
        {
            result = KAL_TRUE;
            goto em_agpslog_start_session_return;
        }
    }

    for (i = 0; i < EM_AGPSLOG_MAX_CONCURRENT_SESSION_NUM; i++)
    {
        if (g_em_agpslog_log_of_session[i].buffer == NULL)
        {
            log_buffer_p = &(g_em_agpslog_log_of_session[i]);
            break;
        }
    }

    /* No resource available */
    if (log_buffer_p == NULL)
    {
        result = KAL_FALSE;
        goto em_agpslog_start_session_return;
    }

    f_hdlr = em_agpslog_get_log_file_handler(session_id);

    if (f_hdlr <= 0)
    {
        result = KAL_FALSE;
        goto em_agpslog_start_session_return;
    }

    log_buffer_p->session_id = session_id;
    log_buffer_p->buffer = (kal_uint8*)get_ctrl_buffer(EM_AGPSLOG_LOG_BUFFER_SIZE);
    log_buffer_p->size = EM_AGPSLOG_LOG_BUFFER_SIZE;
    log_buffer_p->tail_index = 0;
    log_buffer_p->log_file = f_hdlr;
    
    if (g_em_agpslog_active_log_p == NULL)
    {
        g_em_agpslog_active_log_p = log_buffer_p;
    }

    em_agpslog_write_log_file_header(log_buffer_p->log_file);

    result = KAL_TRUE;

em_agpslog_start_session_return:

    EM_AGPSLOG_UNLOCK();
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_end_session
 * DESCRIPTION
 *  Terminate a session log. Free resource and flush buffered logs into file.
 * PARAMETERS
 *  session_id      [IN] Session ID
 * RETURNS
 *  void
 *****************************************************************************/
void em_agpslog_end_session(const kal_uint32 session_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    em_agpslog_log_buffer_struct *log_buffer_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    log_buffer_p = NULL;

    EM_AGPSLOG_LOCK();

    for (i = 0; i < EM_AGPSLOG_MAX_CONCURRENT_SESSION_NUM; i++)
    {
        if (g_em_agpslog_log_of_session[i].buffer != NULL &&
            g_em_agpslog_log_of_session[i].session_id == session_id)
        {
            log_buffer_p = &(g_em_agpslog_log_of_session[i]);
            break;
        }
    }

    if (log_buffer_p != NULL)
    {
        em_agpslog_flush_buffer(log_buffer_p);

        free_ctrl_buffer(log_buffer_p->buffer);
        log_buffer_p->session_id = 0x7fff;
        log_buffer_p->buffer = NULL;
        log_buffer_p->size = 0;

        FS_Close(log_buffer_p->log_file);
        log_buffer_p->log_file = 0;
    }

    if (log_buffer_p == g_em_agpslog_active_log_p)
    {
        g_em_agpslog_active_log_p = NULL;
    }

    EM_AGPSLOG_UNLOCK();
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_set_active_session
 * DESCRIPTION
 *  Set session log for the active session.
 * PARAMETERS
 *  session_id      [IN] Session ID
 * RETURNS
 *  KAL_TRUE if the session log is available.
 *****************************************************************************/
kal_bool em_agpslog_set_active_session(const kal_uint32 session_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    kal_bool result;
    em_agpslog_log_buffer_struct *log_buffer_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = KAL_FALSE;
    log_buffer_p = NULL;

    EM_AGPSLOG_LOCK();

    g_em_agpslog_active_log_p = NULL;

    for (i = 0; i < EM_AGPSLOG_MAX_CONCURRENT_SESSION_NUM; i++)
    {
        if (g_em_agpslog_log_of_session[i].buffer != NULL &&
            g_em_agpslog_log_of_session[i].session_id == session_id)
        {
            g_em_agpslog_active_log_p = &(g_em_agpslog_log_of_session[i]);
            result = KAL_TRUE;
            break;
        }
    }

    EM_AGPSLOG_UNLOCK();

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_write_to_active
 * DESCRIPTION
 *  Write raw log data into the log of the active session.
 * PARAMETERS
 *  session_id      [IN] Session ID
 * RETURNS
 *  KAL_TRUE if the session log is available.
 *****************************************************************************/
static void em_agpslog_write_to_active(
    em_agpslog_type_enum log_type,
    const kal_uint8 *data,
    kal_uint32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EM_AGPSLOG_LOCK();

    if (g_em_agpslog_enabled && g_em_agpslog_active_log_p != NULL)
    {
        em_agpslog_write(g_em_agpslog_active_log_p, log_type, data, length);
    }

    EM_AGPSLOG_UNLOCK();
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_void
 * DESCRIPTION
 *  <<< For internal use, user do NOT call this function directly! >>>
 *  Write a log with empty data into the log of the active session.
 * PARAMETERS
 *  log_type      [IN] em_agpslog_type_enum
 * RETURNS
 *  void
 *****************************************************************************/
void em_agpslog_void(const em_agpslog_type_enum log_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    em_agpslog_write_to_active(log_type, NULL, 0);
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_u8
 * DESCRIPTION
 *  <<< For internal use, user do NOT call this function directly! >>>
 *  Write a log of kal_uint8 into the log of the active session.
 * PARAMETERS
 *  log_type     [IN] em_agpslog_type_enum
 *  val          [IN] value
 * RETURNS
 *  void
 *****************************************************************************/
void em_agpslog_u8(const em_agpslog_type_enum log_type, const kal_uint8 val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 data[1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data[0] = val;
    em_agpslog_write_to_active(log_type, data, sizeof(data));
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_u8_u8
 * DESCRIPTION
 *  <<< For internal use, user do NOT call this function directly! >>>
 *  Write a log of 2 kal_uint8s into the log of the active session.
 * PARAMETERS
 *  log_type     [IN] em_agpslog_type_enum
 *  v1           [IN] value 1
 *  v2           [IN] value 2
 * RETURNS
 *  void
 *****************************************************************************/
void em_agpslog_u8_u8(const em_agpslog_type_enum log_type, const kal_uint8 v1, const kal_uint8 v2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 data[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data[0] = v1;
    data[1] = v2;
    em_agpslog_write_to_active(log_type, data, sizeof(data));
}

/*****************************************************************************
 * FUNCTION
 *  em_agpslog_u16
 * DESCRIPTION
 *  <<< For internal use, user do NOT call this function directly! >>>
 *  Write a log of kal_uint16 into the log of the active session.
 * PARAMETERS
 *  log_type     [IN] em_agpslog_type_enum
 *  val          [IN] value
 * RETURNS
 *  void
 *****************************************************************************/
void em_agpslog_u16(const em_agpslog_type_enum log_type, const kal_uint16 val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 data[1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data[0] = val;
    em_agpslog_write_to_active(log_type, (kal_uint8*)data, sizeof(data));
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_u16
 * DESCRIPTION
 *  <<< For internal use, user do NOT call this function directly! >>>
 *  Write a log of 2 kal_uint16s into the log of the active session.
 * PARAMETERS
 *  log_type     [IN] em_agpslog_type_enum
 *  v1           [IN] value 1
 *  v2           [IN] value 2
 * RETURNS
 *  void
 *****************************************************************************/
void em_agpslog_u16_u16(
    const em_agpslog_type_enum log_type,
    const kal_uint16 v1,
    const kal_uint16 v2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 data[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data[0] = v1;
    data[1] = v2;
    em_agpslog_write_to_active(log_type, (kal_uint8*)data, sizeof(data));
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_float
 * DESCRIPTION
 *  <<< For internal use, user do NOT call this function directly! >>>
 *  Write a log of float into the log of the active session.
 * PARAMETERS
 *  log_type     [IN] em_agpslog_type_enum
 *  val          [IN] value
 * RETURNS
 *  void
 *****************************************************************************/
void em_agpslog_float(const em_agpslog_type_enum log_type, const float val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float data[1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data[0] = val;
    em_agpslog_write_to_active(log_type, (kal_uint8*)data, sizeof(data));
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_mmi_date_time
 * DESCRIPTION
 *  Write data/time into the log of the active session.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void em_agpslog_mmi_date_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetDateTime(&time);
    em_agpslog_write_to_active(EM_AGPSLOG_MMI_DATE_TIME, (kal_uint8*)(&time), sizeof(time));
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_supl_version
 * DESCRIPTION
 *  Write SUPL version into the log of the active session.
 * PARAMETERS
 *  major       [IN]
 *  minor       [IN]
 *  serv_ind    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void em_agpslog_supl_version(
    const kal_uint8 major,
    const kal_uint8 minor,
    const kal_uint8 serv_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 data[3];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data[0] = major;
    data[1] = minor;
    data[2] = serv_ind;
    em_agpslog_write_to_active(EM_AGPSLOG_SUPL_VERSION, (kal_uint8*)data, sizeof(data));
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_supl_session_id
 * DESCRIPTION
 *  Write SUPL session ID into the log of the active session.
 * PARAMETERS
 *  session_id     [IN]  In C-style string. I.e., in ascii code and tailed
 *                       with '\0'.
 * RETURNS
 *  void
 *****************************************************************************/
void em_agpslog_supl_session_id(const kal_char *session_id) /* C-style string */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 data_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_length = em_agpslog_strlen(session_id) + 1;
    em_agpslog_write_to_active(EM_AGPSLOG_SUPL_SESSION_ID,
        (kal_uint8*)session_id,
        data_length);
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_supl_SLP
 * DESCRIPTION
 *  Write SUPL SLP address into the log of the active session.
 * PARAMETERS
 *  ip_addr         [IN] IP address.
 *                       For example, 140.113.215.74 should be
 *                       [0] = 140, [1]=113, [2]=215, [3]=74, and addr_len = 4
 *  addr_len        [IN] Length of IP, 4 for IPv4
 *  port            [IN] Port number
 * RETURNS
 *  void
 *****************************************************************************/
void em_agpslog_supl_SLP(
    const kal_uint8 *ip_addr, /* NOT a string, refer to the comment above */
    const kal_uint8 addr_len,
    const kal_uint16 port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    em_agpslog_network_address_struct network_addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    network_addr.addr_len = addr_len;
    network_addr.port = port;
    kal_mem_cpy(network_addr.ip, ip_addr, addr_len);

    em_agpslog_write_to_active(
        EM_AGPSLOG_SUPL_SLP_ADDRESS,
        (kal_uint8*)(&network_addr),
        sizeof(network_addr)-sizeof(network_addr.ip)+addr_len);
}


/*****************************************************************************
 * FUNCTION
 *  em_agpslog_gps_position_result
 * DESCRIPTION
 *  Write GPS position result and date/time into the log of the active session.
 * PARAMETERS
 *  longitude   [IN]
 *  latitude    [IN]
 *  altitude    [IN]
 *  velocity    [IN]
 *  direction   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void em_agpslog_gps_position_result(
    const float longitude,
    const float latitude,
    const float altitude,
    const float velocity,
    const float direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    em_agpslog_position_result_struct pos_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pos_result.longitude = longitude;
    pos_result.latitude = latitude;
    pos_result.altitude = altitude;
    pos_result.velocity = velocity;
    pos_result.direction = direction;
    GetDateTime(&(pos_result.time));

    em_agpslog_write_to_active(
        EM_AGPSLOG_GPS_POSITION_RESULT,
        (kal_uint8*)&pos_result,
        sizeof(pos_result));
}

#endif /* __AGPS_LOG_SUPPORT__ */
