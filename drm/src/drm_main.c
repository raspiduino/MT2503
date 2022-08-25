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
 * drm_main.c
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifdef __DRM_SUPPORT__
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "fs_gprot.h"
#include "fsal.h"
#include "app_mine.h"
#include "app_datetime.h"

#include "drm_def.h"
#include "drm_trace.h"
#include "drm_gprot.h"
#include "drm_prot.h"
#include "drm_util.h"
#include "drm_main.h"
#include "drm_msg.h"
#include "drm_memory.h"

/******************************************************************/
/******************************************************************/
/*                                                                */
/*                                                                */
/*                        DRM Task                                */
/*                                                                */
/*                                                                */
/******************************************************************/
/******************************************************************/
/* task */
#include "syscomp_config.h"
#include "task_config.h"

#include "app_datetime.h"

#include "task_main_func.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "drm_errcode.h"
#include "kal_trace.h"
#include "kal_active_module.h"
#include "stack_ltlcom.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "string.h"
#include "kal_internal_api.h"
#include "kal_common_defs.h"

#define DRM_MAIN_DEBUGP(x) DRM_DEBUGP(x)


/*
 * local functions
 */

#if !defined(__DRM_EXTERNAL__)
static void drmt_task_main(task_entry_struct *task_entry_ptr);
kal_bool drmt_init(task_indx_type task_indx);
static kal_bool drmt_reset(task_indx_type task_indx);
static kal_bool drmt_deinit(task_indx_type task_indx);

//#ifdef DRM_CHECK_TIME_PERIODICALLY
//static void drmt_start_base_timer(void *base_timer_p, unsigned int time_out);
//static void drmt_stop_base_timer(void *base_timer_p);
static void drmt_timer_init(void);
//#endif /* DRM_CHECK_TIME_PERIODICALLY */ /* __DRM_V02__ */
#endif /* !__DRM_EXTERNAL__ */

/*
 * local variable
 */

static kal_bool drmt_engine_init = KAL_FALSE;
static kal_eventgrpid g_drm_init_event_group = NULL;

#if !defined(__DRM_EXTERNAL__)
//static stack_timer_struct drmt_timer;
static event_scheduler *drmt_event_scheduler;


static kal_bool drmt_is_busy = KAL_FALSE;
static kal_bool drmt_is_process_database = KAL_FALSE;
kal_bool drm_verno_change = KAL_FALSE;


extern kal_mutexid g_drm_consumer_mutex;

typedef struct
{
    kal_int32 handle;
    drm_proc_enum status;
    kal_bool sd_waiting;
} drm_process_table_struct;

static kal_mutexid g_drm_process_mutex = NULL;
static drm_process_table_struct g_drm_process_tbl[DRM_MAX_FILE_HANDLE] = {0};
static void drmt_check_verno(void);
static void drmt_create_verno_file(void);
  
#ifdef __DRM_SUPPORT_SD_CALLBACK__
drm_sd_callback_struct g_drm_sd_callback[DRM_SD_CALLBACK_MAX_NUM] = {0};
#endif 
#endif /* !__DRM_EXTERNAL__ */


/*****************************************************************************
 * FUNCTION
 *  drmt_engine_is_ready
 * DESCRIPTION
 *  check DRM engine is ready or not
 * PARAMETERS
 *  void
 * RETURNS
 *  success or fail
 *****************************************************************************/
kal_bool drmt_engine_is_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drmt_engine_init;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_check_engine_ready
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void drmt_check_engine_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 event_group;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!drmt_engine_init)
    {
    #ifdef __DRM_EXTERNAL__
        drmt_engine_init = KAL_TRUE;
    #else
        DRM_DEBUG(
            "[DRM] engine is not ready -- %d",
            (TRACE_GROUP_GENERAL, DRM_CHECK_ENGINE_READY, stack_get_active_module_id()));
        kal_retrieve_eg_events(g_drm_init_event_group, 1, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  drmt_init
 * DESCRIPTION
 *  This is init() function of drmt module.
 *  This function initialize all the context variables required for drmt module
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  True if succeed.
 *****************************************************************************/
kal_bool drmt_init(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fsal_fsop_func_type callback = 
    {
        DRM_open_file,
        DRM_close_file,
        DRM_read_file,
        DRM_seek_large_file,
        DRM_file_size,
        DRM_file_pos,
        DRM_set_seek_hint
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    drmt_mem_init();
#ifdef __DRM_SEC_CLK_NITZ__
	drm_stime_init();
#endif /*__DRM_SEC_CLK_NITZ__*/
#if !defined(__DRM_EXTERNAL__)
    g_drm_init_event_group = kal_create_event_group("DrmInit");
#ifdef DRM_CHECK_TIME_PERIODICALLY
    g_drm_consumer_mutex = kal_create_mutex("DrmConsumer");
#endif
    drmt_timer_init();

    g_drm_process_mutex = kal_create_mutex("DrmProcess");
#endif /* !__DRM_EXTERNAL__ */

    FSAL_SetFSOperations(&callback);

    return KAL_TRUE;
}


#if !defined(__DRM_EXTERNAL__)


/*****************************************************************************
 * FUNCTION
 *  drmt_task_main
 * DESCRIPTION
 *  DRM task
 * PARAMETERS
 *  task_entry_ptr      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void drmt_task_main(task_entry_struct *task_entry_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;
    kal_uint32 my_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_my_task_index(&my_index);
    stack_set_active_module_id(my_index, MOD_DRMT);

    /* Check verno here, if verno is not correct, we delete all folder before
       init engine */
    drmt_check_verno();

    /* initial drm engine, we should do as less as thing in this function
       or blocking too many DRM_open_file */
    drm_core_init_engine();

    /* unblock all DRM_open_file before engine initialized */
    drmt_engine_init = KAL_TRUE;
    kal_set_eg_events(g_drm_init_event_group, 1, KAL_OR);

    /* do other initial */
    drm_core_init();

    /* if verno is changed , create verno file */
    if (drm_verno_change)
    {
        drmt_create_verno_file();
    }

    /* check cid database */
    if (DRM_RESULT_OK == drmt_sdb_check(DRM_CID_DB_FILEPATH))
    {
        drmt_sdb_backup(DRM_CID_DB_FILEPATH, DRM_CID_DB_BACKUP_FILEPATH);
    }
    else
    {
        drmt_sdb_restore(DRM_CID_DB_FILEPATH, DRM_CID_DB_BACKUP_FILEPATH);
    }

    while (1)
    {
        receive_msg_ext_q_for_stack(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
        stack_set_active_module_id(my_index, MOD_DRMT);

        drmt_msg_handler(&current_ilm, KAL_FALSE);
        free_ilm(&current_ilm);
    }
}


/*****************************************************************************
 * FUNCTION
 *  drmt_reset
 * DESCRIPTION
 *  This is reset() function of drmt module.
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool drmt_reset(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_deinit
 * DESCRIPTION
 *  This is deinit() function of drmt module.
 *  This function finalize all the context variables required for drmt module
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  True if succeed.
 *****************************************************************************/
static kal_bool drmt_deinit(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_TRUE;
}


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
    static const comptask_handler_struct drmt_handler_info = 
    {
        drmt_task_main, /* task entry function */
        drmt_init,      /* task initialization function */
        NULL,           /* task configuration function */
        drmt_reset,     /* task reset handler */
        drmt_deinit,    /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*) & drmt_handler_info;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_check_verno
 * DESCRIPTION
 *  DRM task
 * PARAMETERS
 *  void
 *  task_entry_ptr      [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
static void drmt_check_verno(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle_v;
    kal_char *coded_verno = drm_core_release_verno();
    kal_int32 ret;
    kal_uint32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle_v = FS_OpenHint(DRM_VERNO_REC, FS_READ_ONLY, DRM_get_open_hint(DRM_VERNO_REC));
    if (handle_v < FS_NO_ERROR)
    {
        drm_verno_change = KAL_TRUE;
        DRM_DEBUG(
            "[DRM] version check fail: fs_errcode = %d",
            (TRACE_GROUP_ERROR, DRM_0D483A63EA462D5165DB60CEF2935C68, handle_v));
    }
    else
    {
        kal_char *verno = NULL;
        kal_uint32 size;

        ret = FS_GetFileSize(handle_v, &size);
        verno = (kal_char*) get_ctrl_buffer(size + 2);
        memset(verno, 0x00, size + 2);
        ret = FS_Read(handle_v, verno, size, &len);
        FS_Close(handle_v);

        if (ret >= FS_NO_ERROR)
        {

            if (len != strlen(coded_verno) || strncmp(verno, coded_verno, len) != 0)
            {
                drm_verno_change = KAL_TRUE;
                DRM_DEBUG(
                    "[DRM] version check fail: version change",
                    (TRACE_GROUP_GENERAL, DRM_D9E6C54BFD7BF0C3765D0616565600A4, 0, 0, 0));

            }
        }
        free_ctrl_buffer(verno);
    }

    if (drm_verno_change)
    {
        FS_XDelete(DRM_PATH, FS_DIR_TYPE | FS_FILE_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
        FS_CreateDir(DRM_PATH);
    }
}


/*****************************************************************************
 * FUNCTION
 *  drmt_create_verno_file
 * DESCRIPTION
 *  DRM task
 * PARAMETERS
 *  void
 *  task_entry_ptr      [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
static void drmt_create_verno_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    kal_uint32 len;
    FS_HANDLE handle_v;
    kal_char *coded_verno = drm_core_release_verno();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle_v = FS_Open(DRM_VERNO_REC, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (handle_v >= FS_NO_ERROR)
    {
        ret = FS_Write(handle_v, (void*)coded_verno, strlen(coded_verno), &len);
        if (ret < FS_NO_ERROR)
        {
            DRM_DEBUG(
                "[DRM] version create fail: file status of verno = %d",
                (TRACE_GROUP_ERROR, DRM_DC8C1EA787C00E0334AD16D3E6095C5A, ret, 0, 0));
        }
    }
    else
    {
        DRM_DEBUG(
            "[DRM] version create fail: file status of verno = %d",
            (TRACE_GROUP_ERROR, DRM_DC8C1EA787C00E0334AD16D3E6095C5A, handle_v, 0, 0));
    }

    FS_Close(handle_v);
}


/*****************************************************************************
 * FUNCTION
 *  drmt_msg_handler
 * DESCRIPTION
 *  handle all the message sent to drm task
 * PARAMETERS
 *  current_ilm         [IN]        Message
 *  drm_is_blocking     [IN]        This message is blocking message or not.
 * RETURNS
 *  handle or not
 *****************************************************************************/
kal_bool drmt_msg_handler(ilm_struct *current_ilm, kal_bool drm_is_blocking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (current_ilm->msg_id)
    {
        case MSG_ID_DRMT_INSTALL_OBJECT_REQ:
        {
            drmt_install_object_cnf_struct *cnf;

            drmt_install_object_req_struct *req = (drmt_install_object_req_struct*) current_ilm->local_para_ptr;

            cnf = (drmt_install_object_cnf_struct*) construct_local_para(
                                                        sizeof(drmt_install_object_cnf_struct),
                                                        TD_RESET);

            if (drm_is_blocking)
            {
                cnf->result = DRM_RESULT_BUSY;
            }
            else
            {
                drmt_async_set_current_serial(req->serial);

                if (req->mime_type == MIME_SUBTYPE_ROAP_PDU || req->mime_type == MIME_SUBTYPE_ROAP_TRIGGER)
                {
                    drmt_engine_set_busy(KAL_TRUE);
                }

                cnf->result = drm_core_install_object(
                                req->serial,
                                req->mime_type,
                                req->src_path,
                                req->src_need_kept,
                                req->dest_path,
                                req->dest_buffer_len_in_byte,
                                &cnf->mime_type);

                drmt_engine_set_busy(KAL_FALSE);

                drmt_async_set_current_serial(0);
            }

            drmt_async_set_status(req->serial, DRM_PROC_ENCRYPT_FINISHED);

            cnf->serial = req->serial;
            cnf->callback = req->callback;

            drm_send_msg(
                stack_get_active_module_id(),
                current_ilm->src_mod_id,
                MSG_ID_DRMT_INSTALL_OBJECT_CNF,
                (void*)cnf,
                NULL);
            break;
        }
        case MSG_ID_DRMT_PROCESS_DATABASE_REQ:
        {
            drmt_process_database_req_struct *req = (drmt_process_database_req_struct*) current_ilm->local_para_ptr;
            drmt_process_database_cnf_struct *cnf =
                (drmt_process_database_cnf_struct*) construct_local_para(
                                                        sizeof(drmt_process_database_cnf_struct),
                                                        TD_RESET);

            if (drm_is_blocking)
            {
                cnf->result = DRM_RESULT_BUSY;
            }
            else
            {
                drmt_async_set_current_serial(req->serial);
                cnf->result = drm_core_process_db(req->serial, req->type, req->index, req->path);
                drmt_async_set_current_serial(0);
            }
            drmt_async_set_status(req->serial, DRM_PROC_ENCRYPT_FINISHED);

            cnf->callback = req->callback;
            cnf->serial = req->serial;

            drm_send_msg(
                stack_get_active_module_id(),
                current_ilm->src_mod_id,
                MSG_ID_DRMT_PROCESS_DATABASE_CNF,
                (void*)cnf,
                NULL);
            break;
        }
        case MSG_ID_DRMT_PARSE_DM_REQ:
        {
            drmt_parse_dm_cnf_struct *cnf =
                (drmt_parse_dm_cnf_struct*) construct_local_para(sizeof(drmt_parse_dm_cnf_struct), TD_RESET);
            drmt_parse_dm_req_struct *req = (drmt_parse_dm_req_struct*) current_ilm->local_para_ptr;

            if (drm_is_blocking)
            {
                cnf->result = DRM_RESULT_BUSY;
            }
            else
            {
                drmt_async_set_current_serial(req->serial);
                cnf->result = drm_core_parse_drm_message(
                                req->serial,
                                req->src_path,
                                req->seed,
                                req->seed_len,
                                req->info);
                drmt_async_set_current_serial(0);
            }

            drmt_async_set_status(req->serial, DRM_PROC_ENCRYPT_FINISHED);

            cnf->serial = req->serial;
            cnf->info = req->info;
            cnf->callback = req->callback;

            drm_send_msg(
                stack_get_active_module_id(),
                current_ilm->src_mod_id,
                MSG_ID_DRMT_PARSE_DM_CNF,
                (void*)cnf,
                NULL);
            break;
        }
        case MSG_ID_DRMT_ENCODE_DRM_MESSAGE_REQ:
        {
            drmt_encode_drm_message_cnf_struct *cnf;
            drmt_encode_drm_message_req_struct *req =
                (drmt_encode_drm_message_req_struct*) current_ilm->local_para_ptr;

            cnf =
                (drmt_encode_drm_message_cnf_struct*) construct_local_para(
                                                        sizeof(drmt_encode_drm_message_cnf_struct),
                                                        TD_RESET);

            if (drm_is_blocking)
            {
                cnf->result = DRM_RESULT_BUSY;
            }
            else
            {
                drmt_async_set_current_serial(req->serial);
                cnf->result = drm_core_encode_drm_message(req->serial, req->src_path, req->dest_path, req->offset);
                drmt_async_set_current_serial(0);
            }

            drmt_async_set_status(req->serial, DRM_PROC_ENCRYPT_FINISHED);

            cnf->serial = req->serial;
            cnf->callback = req->callback;

            drm_send_msg(
                stack_get_active_module_id(),
                current_ilm->src_mod_id,
                MSG_ID_DRMT_ENCODE_DRM_MESSAGE_CNF,
                (void*)cnf,
                NULL);
            break;
        }
        case MSG_ID_DRMT_GET_RO_NUM_REQ:
        {
            drmt_get_ro_num_req_struct *req = (drmt_get_ro_num_req_struct*) current_ilm->local_para_ptr;
            drmt_get_ro_num_cnf_struct *cnf =
                (drmt_get_ro_num_cnf_struct*) construct_local_para(sizeof(drmt_get_ro_num_cnf_struct), TD_RESET);

            if (drm_is_blocking)
            {
                cnf->result = DRM_RESULT_BUSY;
            }
            else
            {
                drmt_async_set_current_serial(req->serial);
                cnf->result = drm_core_get_ro_num(req->serial, req->count_flag);
                drmt_async_set_current_serial(0);
            }

            drmt_async_set_status(req->serial, DRM_PROC_ENCRYPT_FINISHED);

            cnf->serial = req->serial;
            cnf->callback = req->callback;
            drm_send_msg(
                stack_get_active_module_id(),
                current_ilm->src_mod_id,
                MSG_ID_DRMT_GET_RO_NUM_CNF,
                (void*)cnf,
                NULL);
            break;
        }

    #ifdef __DRM_SUPPORT_SCAN_DISK__
        case MSG_ID_DRMT_SCAN_DISK_REQ:
        {
            kal_int32 result;
            drmt_scan_disk_req_struct *req = (drmt_scan_disk_req_struct*) current_ilm->local_para_ptr;
            static kal_bool is_scanning = KAL_FALSE;

            drmt_async_set_current_serial(req->serial);
            if (is_scanning && current_ilm->src_mod_id != MOD_DRMT)
            {
                result = DRM_RESULT_BUSY;
            }
            else
            {
                is_scanning = KAL_TRUE;
                result = drmt_scan_disk(req->serial, req->type, req->path);
            }
            drmt_async_set_current_serial(0);

            if (result != DRM_PROC_ENCRYPT_BUSY)
            {
                drmt_scan_disk_cnf_struct *cnf =
                    (drmt_scan_disk_cnf_struct*) construct_local_para(sizeof(drmt_scan_disk_cnf_struct), TD_RESET);

                cnf->serial = req->serial;
                cnf->callback = req->callback;
                drmt_async_set_status(req->serial, DRM_PROC_ENCRYPT_FINISHED);
                drm_send_msg(stack_get_active_module_id(), req->source, MSG_ID_DRMT_SCAN_DISK_CNF, (void*)cnf, NULL);
                is_scanning = KAL_FALSE;
            }
            else
            {
                hold_local_para(current_ilm->local_para_ptr);
                drm_send_msg(stack_get_active_module_id(), MOD_DRMT, MSG_ID_DRMT_SCAN_DISK_REQ, (void*)req, NULL);
            }

            break;
        }
    #endif /* __DRM_SUPPORT_SCAN_DISK__ */ 

    #ifdef __DRM_V02__
        case MSG_ID_DRMT_ACTIVATE_REQ:
        {
            drmt_activate_req_struct *req = (drmt_activate_req_struct*) current_ilm->local_para_ptr;
            drmt_activate_cnf_struct *cnf =
                (drmt_activate_cnf_struct*) construct_local_para(sizeof(drmt_activate_cnf_struct), TD_RESET);

            if (drm_is_blocking)
            {
                cnf->result = DRM_RESULT_BUSY;
            }
            else
            {
                drmt_async_set_current_serial(req->serial);
                if (req->is_file_handle)
                {
                    cnf->result = drm_core_activate_file_by_handle(req->serial, (FS_HANDLE) req->file_handle);
                }
                else
                {
                    cnf->result = drm_core_activate_file(req->serial, req->permission, (kal_wchar*) req->filepath);
                }
                drmt_async_set_current_serial(0);
            }

            drmt_async_set_status(req->serial, DRM_PROC_ENCRYPT_FINISHED);

            cnf->serial = req->serial;
            cnf->callback = req->callback;
            drm_send_msg(
                stack_get_active_module_id(),
                current_ilm->src_mod_id,
                MSG_ID_DRMT_ACTIVATE_CNF,
                (void*)cnf,
                NULL);
            break;
        }
    #endif /* __DRM_V02__ */ 
        case MSG_ID_TIMER_EXPIRY:
        {
            drmt_evshed_expiry_hdlr((void*)current_ilm->local_para_ptr, (void*)current_ilm->peer_buff_ptr);
            break;
        }
    #ifdef __DRM_SUPPORT_SD_CALLBACK__
        case MSG_ID_DRMT_REGISTER_SD_CALLBACK_REQ:
        {
            void *timer_id;
            kal_uint8 *serial = drmt_mem_alloc(sizeof(kal_uint8));
            drmt_register_sd_callback_ind_struct *reg_ind =
                (drmt_register_sd_callback_ind_struct*) current_ilm->local_para_ptr;

            *serial = reg_ind->serial;
            
            if (reg_ind->timer != 0)
            {
                timer_id = drmt_start_timer(reg_ind->timer, (void*)serial, drmt_sd_callback_timer_expiry);
                DRM_DEBUG("[SD] Start timer, id = %d", (TRACE_GROUP_GENERAL, DRM_SD_CB_START_TIMER, timer_id));
                drmt_sd_callback_insert_timer_id(reg_ind->serial, timer_id);
            }
            
            drm_send_msg(
                stack_get_active_module_id(),
                current_ilm->src_mod_id,
                MSG_ID_DRMT_REGISTER_SD_CALLBACK_CNF,
                NULL,
                NULL);
            break;
        }

    #endif /* __DRM_SUPPORT_SD_CALLBACK__ */ 
        default:
            result = drm_core_msg_handler(current_ilm, KAL_FALSE);
    }

    return result;
}



//#ifdef DRM_CHECK_TIME_PERIODICALLY


/*****************************************************************************
 * FUNCTION
 *  drmt_timer_init
 * DESCRIPTION
 *  Create timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void drmt_timer_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //stack_init_timer(&drmt_timer, "drmt Timer", MOD_DRMT);

    /* Create an Event Scheduler */
    /*drmt_event_scheduler = (event_scheduler*) new_evshed(
                                                &drmt_timer,
                                                drmt_start_base_timer,
                                                drmt_stop_base_timer,
                                                0,
                                                (malloc_fp_t) kal_evshed_get_mem,
                                                kal_evshed_free_mem,
                                                254);*/
    drmt_event_scheduler = (event_scheduler*) evshed_create(
                                                "drmt Timer", 
                                                MOD_DRMT,
                                                0, 
                                                254);

}


/*****************************************************************************
 * FUNCTION
 *  drmt_start_base_timer
 * DESCRIPTION
 *  Restart base timer
 * PARAMETERS
 *  base_timer_p        [?]         [?]
 *  time_out            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
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
#endif

/*****************************************************************************
 * FUNCTION
 *  drmt_stop_base_timer
 * DESCRIPTION
 *  Stop base timer
 * PARAMETERS
 *  base_timer_p        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
//static void drmt_stop_base_timer(void *base_timer_p)
//{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    stack_stop_timer((stack_timer_struct*) base_timer_p);
//}


/*****************************************************************************
 * FUNCTION
 *  drmt_start_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  time_in_millisec        [IN]        
 *  arg                     [?]         [?]
 *  callback                [IN]        
 *  consumer(?)             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *drmt_start_timer(kal_uint32 time_in_millisec, void *arg, kal_timer_func_ptr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    eventid evid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evid = evshed_set_event(
            (event_scheduler*) drmt_event_scheduler,
            (kal_timer_func_ptr) callback,
            (void*)arg,
            (time_in_millisec / 10) * KAL_TICKS_10_MSEC);
    EXT_ASSERT(evid, 0, 0, 0);

    return (void*)evid;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_stop_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void drmt_stop_timer(void *id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id != NULL)
    {
        DRM_DEBUG("[DRM] stop timer %d", (TRACE_GROUP_GENERAL, DRM_9EBD9C2DFB6FBE9E9D123CBB85204291, id));
        evshed_cancel_event((event_scheduler*) drmt_event_scheduler, (eventid*) &id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  drmt_evshed_expiry_hdlr
 * DESCRIPTION
 *  Handling event scheduler action
 * PARAMETERS
 *  local_para_ptr      [?]     [?]     [?]
 *  peer_buff_ptr       [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void drmt_evshed_expiry_hdlr(void *local_para_ptr, void *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stack_timer_struct *stack_timer_ptr;
    kal_uint16 msg_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_DEBUG("[DRM] timer expired", (TRACE_GROUP_GENERAL, DRM_A6AFDA4FF413E41DEFF856D2B767E3CC));
    evshed_timer_handler(drmt_event_scheduler);
}

//#endif /* DRM_CHECK_TIME_PERIODICALLY */ /* __DRM_V02__ */


/*****************************************************************************
 * FUNCTION
 *  drmt_peek_next_msg
 * DESCRIPTION
 *  This routine implements to peek message in queue without removing the message
 * PARAMETERS
 *  void
 * RETURNS
 *  >=0 , how many message in queue
 *****************************************************************************/
kal_int32 drmt_peek_next_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_msgq_info msgq_info;
    kal_int32 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (kal_get_queue_info(task_info_g[INDX_DRMT].task_ext_qid, &msgq_info) == KAL_TRUE)
    {
        result = msgq_info.pending_msgs;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_get_next_msg
 * DESCRIPTION
 *  This API let us to wait one or more expected message until we receive it.
 *  We will try to handle other message in this API too. This function can
 *  be used in blocking API.
 * PARAMETERS
 *  current_msg_handler     [IN]        The expected message handler
 *  wait_forever            [IN]        Blocking waiting or not
 *  abort_msg_received      [IN]        Have we receive the abort message
 *  abort_skip              [IN]        Do not stop waiting the message if receive abort message
 * RETURNS
 *  KAL_FALSE   not get the expected message
 *  KAL_TRUE    get the expected message
 *****************************************************************************/
kal_bool drmt_get_next_msg(
            kal_bool(*current_msg_handler) (ilm_struct *ilm_ptr),
            kal_bool wait_forever,
            kal_bool *abort_msg_received,
            kal_bool abort_skip)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (abort_msg_received != NULL)
    {
        *abort_msg_received = KAL_FALSE;
    }

    do
    {
        kal_status status = KAL_Q_EMPTY;
        kal_uint16 msg_size;

        if (wait_forever)
        {
            status = kal_deque_msg(task_info_g[INDX_DRMT].task_ext_qid, (void*)&current_ilm, &msg_size, KAL_INFINITE_WAIT);
        }
        else
        {
            status = kal_deque_msg(task_info_g[INDX_DRMT].task_ext_qid, (void*)&current_ilm, &msg_size, KAL_NO_WAIT);
        }

        if (status == KAL_SUCCESS)
        {
            /* User can handle abort req in the msg handler or outside */
            if (current_msg_handler && current_msg_handler(&current_ilm) == KAL_TRUE)
            {
                free_ilm(&current_ilm);
                return KAL_TRUE;
            }
            else if (current_ilm.msg_id == MSG_ID_DRMT_ABORT_REQ)
            {
                if (abort_msg_received)
                {
                    *abort_msg_received = KAL_TRUE;
                }

                free_ilm(&current_ilm);

                if (abort_skip)
                {
                    continue;
                }
                else
                {
                    return KAL_FALSE;
                }
            }
            else
            {
                /* we handle other general message here */
                drmt_msg_handler(&current_ilm, KAL_TRUE);
                free_ilm(&current_ilm);
            }
        }
        else if (status == KAL_Q_EMPTY)
        {
            if (!wait_forever || current_msg_handler == NULL)
            {
                return KAL_FALSE;
            }
            /* Sleep for a while, and polling again. */
            kal_sleep_task(10);
        }
        else
        {
            ASSERT(0);
        }
    } while (wait_forever && current_msg_handler);

    return KAL_FALSE;

}

#define DRM_SDB_MANAGEMENT


/*****************************************************************************
 * FUNCTION
 *  drmt_sdb_check_pattern
 * DESCRIPTION
 * PARAMETERS
 *  entry       [?]     
 * RETURNS
 *****************************************************************************/
kal_bool drmt_sdb_check_pattern(drm_sdb_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (entry->header != DRM_SDB_HEADER_PATTERN)
    {
        return KAL_FALSE;
    }

    if (entry->footer != DRM_SDB_FOOTER_PATTERN)
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_sdb_compare
 * DESCRIPTION
 *  compare this two item
 * PARAMETERS
 *  data            [IN]        Original data
 *  data_len        [IN]        Original data length
 *  entry           [IN]        The entry requires to validate
 * RETURNS
 *  KAL_TRUE:   validate successful
 *  KAL_FALSE:  validate fail
 *****************************************************************************/
kal_bool drmt_sdb_compare(kal_uint8 *data, kal_uint16 data_len, drm_sdb_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (entry->data_len != data_len)
    {
        return KAL_FALSE;
    }

    for (i = data_len - 1; i >= 0; i--)
    {
        if (entry->data[i] != data[i])
        {
            return KAL_FALSE;
        }
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_sdb_writeF
 * DESCRIPTION
 *  write an entry into the handle
 * PARAMETERS
 *  handle      [IN]        The database handle
 *  entry       [IN]        Entry
 * RETURNS
 *  drm_proc_enum
 *****************************************************************************/
kal_int32 drmt_sdb_writeF(kal_int32 handle, drm_sdb_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = DRM_RESULT_NOT_SUPPORT;
    kal_uint32 write_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_NO_ERROR > (result = FS_Write(handle, &entry->header, sizeof(entry->header), &write_size)))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 1, 1, result));
        return result;
    }
    else if (write_size != sizeof(entry->header))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 1, 2, DRM_RESULT_TRUNCATED));
        return DRM_RESULT_TRUNCATED;
    }

    if (FS_NO_ERROR > (result = FS_Write(handle, &entry->attr, sizeof(entry->attr), &write_size)))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 1, 3, result));
        return result;
    }
    else if (write_size != sizeof(entry->attr))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 1, 4, DRM_RESULT_TRUNCATED));
        return DRM_RESULT_TRUNCATED;
    }

    if (FS_NO_ERROR > (result = FS_Write(handle, &entry->data_len, sizeof(entry->data_len), &write_size)))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 1, 5, result));
        return result;
    }
    else if (write_size != sizeof(entry->data_len))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 1, 6, DRM_RESULT_TRUNCATED));
        return DRM_RESULT_TRUNCATED;
    }

    if (FS_NO_ERROR > (result = FS_Write(handle, entry->data, entry->data_len, &write_size)))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 1, 7, result));
        return result;
    }
    else if (write_size != entry->data_len)
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 1, 8, DRM_RESULT_TRUNCATED));
        return DRM_RESULT_TRUNCATED;
    }

    if (FS_NO_ERROR > (result = FS_Write(handle, &entry->footer, sizeof(entry->footer), &write_size)))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 1, 9, result));
        return result;
    }
    else if (write_size != sizeof(entry->footer))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 1, 10, DRM_RESULT_TRUNCATED));
        return DRM_RESULT_TRUNCATED;
    }

    return DRM_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  drmt_sdb_readF
 * DESCRIPTION
 *  read an entry from the database
 * PARAMETERS
 *  handle      [IN]        Database handle
 *  entry       [IN]        Buffer to save entry
 * RETURNS
 *  drm_proc_enum
 *****************************************************************************/
kal_int32 drmt_sdb_readF(kal_int32 handle, drm_sdb_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = DRM_RESULT_NOT_SUPPORT;
    kal_uint32 read_size = 0;
    kal_uint32 offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(entry, 0, sizeof(drm_sdb_struct));

    if (FS_NO_ERROR > (result = FS_GetFilePosition(handle, &offset)))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 2, 1, result));
        goto error;
    }

    if (FS_NO_ERROR > (result = FS_Read(handle, &entry->header, sizeof(entry->header), &read_size)))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 2, 2, result));
        goto error;
    }
    else if (read_size != sizeof(entry->header))
    {
        result = DRM_RESULT_EOF;
        goto error;
    }

    if (FS_NO_ERROR > (result = FS_Read(handle, &entry->attr, sizeof(entry->attr), &read_size)))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 2, 3, result));
        goto error;
    }
    else if (read_size != sizeof(entry->attr))
    {
        result = DRM_RESULT_EOF;
        goto error;
    }

    if (FS_NO_ERROR > (result = FS_Read(handle, &entry->data_len, sizeof(entry->data_len), &read_size)))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 2, 4, result));
        goto error;
    }
    else if (read_size != sizeof(entry->data_len))
    {
        result = DRM_RESULT_EOF;
        goto error;
    }

    if (entry->data_len > 1024)
    {
        result = DRM_RESULT_NO_MEMORY;
        goto error;
    }

    entry->data = drmt_mem_alloc(entry->data_len);

    if (FS_NO_ERROR > (result = FS_Read(handle, entry->data, entry->data_len, &read_size)))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 2, 5, result));
        goto error;
    }
    else if (read_size != entry->data_len)
    {
        result = DRM_RESULT_EOF;
        goto error;
    }

    if (FS_NO_ERROR > (result = FS_Read(handle, &entry->footer, sizeof(entry->footer), &read_size)))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 2, 6, result));
        goto error;
    }
    else if (read_size != sizeof(entry->footer))
    {
        result = DRM_RESULT_EOF;
        goto error;
    }

    return offset;

  error:

    if (entry->data)
    {
        drmt_mem_free(entry->data);
        entry->data = NULL;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_sdb_searchF
 * DESCRIPTION
 *  search an entry in a database
 * PARAMETERS
 *  handle              [IN]        Database handle
 *  data                [IN]        Data
 *  data_len            [IN]        
 *  attr                [IN]        Attribute
 *  compare_func        [IN]        Compare function
 *  datalen(?)          [IN]        Length of data
 * RETURNS
 *  drm_proc_enum
 *****************************************************************************/
kal_int32 drmt_sdb_searchF(
            kal_int32 handle,
            kal_uint8 *data,
            kal_uint16 data_len,
            kal_int16 attr,
            kal_bool(*compare_func) (kal_uint8 *, kal_uint16, drm_sdb_struct*))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = DRM_RESULT_DATA_NOT_FOUND;
    drm_sdb_struct entry;
    kal_int32 offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (1)
    {
        if (DRM_RESULT_OK > (offset = result = drmt_sdb_readF(handle, &entry)))
        {
            if (result == DRM_RESULT_EOF)
            {
                result = DRM_RESULT_DATA_NOT_FOUND;
            }

            DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 3, 1, result));

            return result;
        }

        if (KAL_FALSE == drmt_sdb_check_pattern(&entry))
        {
            drmt_mem_free(entry.data);
            continue;
        }

        if ((entry.attr & attr) == 0)
        {
            drmt_mem_free(entry.data);
            continue;
        }

        if (!compare_func)
        {
            compare_func = drmt_sdb_compare;
        }

        if (!compare_func(data, data_len, &entry))
        {
            drmt_mem_free(entry.data);
            continue;
        }
        else
        {
            drmt_mem_free(entry.data);
            return offset;
        }
    }

    return DRM_RESULT_DATA_NOT_FOUND;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_sdb_deleteH
 * DESCRIPTION
 *  delete one entry in the database via file handle directly
 * PARAMETERS
 *  handle      [IN]        Database file handle
 *  offset      [IN]        Offset
 *  attr        [IN]        Attribute
 * RETURNS
 *  drm_proc_enum
 *****************************************************************************/
kal_int32 drmt_sdb_deleteH(kal_int32 handle, kal_int32 offset, kal_int16 attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = DRM_RESULT_OK;
    kal_uint32 write_size;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FS_Seek(handle, offset + sizeof(kal_uint16), FS_FILE_BEGIN); /* kal_uint16 --> drm_sdb_struct.header */

    if (FS_NO_ERROR > (result = FS_Write(handle, &attr, sizeof(attr), &write_size)))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 4, 3, result));
    }
    else if (write_size != sizeof(attr))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 4, 4, DRM_RESULT_TRUNCATED));
        result = DRM_RESULT_TRUNCATED;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_sdb_delete
 * DESCRIPTION
 *  delete one entry in the database. only set the attribute to DRM_SDB_ATTR_DELETED
 * PARAMETERS
 *  db_path             [IN]        Database path
 *  data                [?]         
 *  data_len            [IN]        Length of data
 *  compare_func        [IN]        Compare function, to check if the data is the one you want to delete
 * RETURNS
 *  drm_proc_enum
 *****************************************************************************/
kal_int32 drmt_sdb_delete(
            kal_wchar *db_path,
            kal_uint8 *data,
            kal_uint16 data_len,
            kal_bool(*compare_func) (kal_uint8 *, kal_uint16, drm_sdb_struct*))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 handle;
    kal_int32 result = DRM_RESULT_OK;
    kal_int32 offset = 0;
    kal_int16 attr = DRM_SDB_ATTR_DELETED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_NO_ERROR > (handle = result = FS_OpenHint(db_path, FS_READ_WRITE, DRM_get_open_hint(db_path))))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 4, 1, result));
        goto Error;
    }

    if (DRM_RESULT_OK > (result = offset = drmt_sdb_searchF(handle, data, data_len, DRM_SDB_ATTR_VALID, compare_func)))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 4, 2, result));
        goto Error;
    }

    result = drmt_sdb_deleteH(handle, offset, attr);

  Error:

    if (handle > 0)
    {
        FS_Close(handle);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_sdb_addH
 * DESCRIPTION
 *  add an new entry into database via file handle directly
 * PARAMETERS
 *  handle          [IN]        Database file handle
 *  data            [IN]        Data
 *  data_len        [IN]        Data_len
 *  attr            [IN]        Attribute
 * RETURNS
 *  >=0, the entry position
 *  <0, fail, refer to drm_proc_enum
 *****************************************************************************/
kal_int32 drmt_sdb_addH(kal_int32 handle, kal_uint8 *data, kal_uint16 data_len, kal_int16 attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = DRM_RESULT_NOT_SUPPORT;
    drm_sdb_struct entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_NO_ERROR > (result = FS_Seek(handle, 0, FS_FILE_END)))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 5, 2, result));
        goto Error;
    }

    entry.header = DRM_SDB_HEADER_PATTERN;
    entry.attr = attr;
    entry.data_len = data_len;
    entry.data = data;
    entry.footer = DRM_SDB_FOOTER_PATTERN;

    if (DRM_RESULT_OK > (result = drmt_sdb_writeF(handle, &entry)))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 5, 3, result));
        goto Error;
    }

  Error:

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_sdb_add
 * DESCRIPTION
 *  add an new entry into database
 * PARAMETERS
 *  db_path         [IN]        Database path
 *  data            [IN]        Data
 *  data_len        [IN]        Data_len
 *  attr            [IN]        Attribute
 * RETURNS
 *  >=0, the entry position
 *  <0, fail, refer to drm_proc_enum
 *****************************************************************************/
kal_int32 drmt_sdb_add(kal_wchar *db_path, kal_uint8 *data, kal_uint16 data_len, kal_int16 attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 handle = FS_ERROR_RESERVED;
    kal_int32 result = DRM_RESULT_NOT_SUPPORT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_NO_ERROR > (handle = result = FS_OpenHint(db_path, FS_READ_WRITE | FS_CREATE, DRM_get_open_hint(db_path))))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 5, 1, result));
        goto Error;
    }

    result = drmt_sdb_addH(handle, data, data_len, attr);

  Error:

    if (handle > 0)
    {
        FS_Close(handle);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_sdb_search
 * DESCRIPTION
 *  search an entry in a database
 * PARAMETERS
 *  db_path             [?]         
 *  data                [IN]        Data
 *  data_len            [IN]        
 *  compare_func        [IN]        The compare function
 *  handle(?)           [IN]        Database handle
 *  datalen(?)          [IN]        Length of data
 * RETURNS
 *  >=0 offset in database
 *  < 0, fail, drm_proc_enum
 *****************************************************************************/
kal_int32 drmt_sdb_search(
            kal_wchar *db_path,
            kal_uint8 *data,
            kal_uint16 data_len,
            kal_bool(*compare_func) (kal_uint8 *, kal_uint16, drm_sdb_struct*))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 handle, result = DRM_RESULT_DATA_NOT_FOUND;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_NO_ERROR > (handle = result = FS_OpenHint(db_path, FS_READ_WRITE | FS_CREATE, DRM_get_open_hint(db_path))))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 6, 1, result));
        goto Error;
    }

    if (DRM_RESULT_OK > (result = drmt_sdb_searchF(handle, data, data_len, DRM_SDB_ATTR_VALID, compare_func)))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 6, 2, result));
        goto Error;
    }

    FS_Close(handle);

    return result;

  Error:

    if (handle > 0)
    {
        FS_Close(handle);
    }

    return KAL_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  drmt_sdb_restore
 * DESCRIPTION
 *  restore the backup database
 * PARAMETERS
 *  db_path         [IN]        Current database path
 *  backup_path     [IN]        Restore the backup database
 * RETURNS
 *  drm_proc_enum
 *****************************************************************************/
kal_int32 drmt_sdb_restore(kal_wchar *db_path, kal_wchar *backup_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = FS_Move(backup_path, db_path, FS_MOVE_COPY | FS_MOVE_OVERWRITE, NULL, NULL, 0);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_sdb_backup
 * DESCRIPTION
 *  backup the database
 * PARAMETERS
 *  db_path         [IN]        Current database
 *  backup_path     [IN]        Backup database file path
 * RETURNS
 *  drm_proc_enum
 *****************************************************************************/
kal_int32 drmt_sdb_backup(kal_wchar *db_path, kal_wchar *backup_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = FS_Move(db_path, backup_path, FS_MOVE_COPY | FS_MOVE_OVERWRITE, NULL, NULL, 0);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_sdb_check
 * DESCRIPTION
 *  check the database and do backup or restore the database when there is any problem
 * PARAMETERS
 *  db_path     [IN]        Current database
 * RETURNS
 *  drm_proc_enum
 *****************************************************************************/
kal_int32 drmt_sdb_check(kal_wchar *db_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 handle = 0;
    kal_int32 result = DRM_RESULT_DATA_NOT_FOUND;
    drm_sdb_struct entry = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_NO_ERROR > (handle = result = FS_OpenHint(db_path, FS_READ_ONLY, DRM_get_open_hint(db_path))))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 7, 1, result));
        goto Error;
    }

    while (1)
    {
        if (DRM_RESULT_OK > (result = drmt_sdb_readF(handle, &entry)))
        {
            if (result == DRM_RESULT_EOF)
            {
                break;
            }
            DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 7, 2, result));
            goto Error;
        }

        if (KAL_FALSE == drmt_sdb_check_pattern(&entry))
        {
            result = DRM_RESULT_INVALID_FORMAT;
            DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 7, 3, result));
            goto Error;
        }

        drmt_mem_free(entry.data);
        entry.data = NULL;
    }

    result = DRM_RESULT_OK;

  Error:

    if (handle > 0)
    {
        FS_Close(handle);
    }

    if (entry.data)
    {
        drmt_mem_free(entry.data);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_sdb_sweep
 * DESCRIPTION
 *  check the database and fix it if need
 * PARAMETERS
 *  db_path         [IN]        Current database
 *  backup_path     [IN]        Backup database
 * RETURNS
 *  drm_proc_enum
 *****************************************************************************/
kal_int32 drmt_sdb_sweep(kal_wchar *db_path, kal_wchar *backup_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 handle_src = 0, handle_dst = 0;
    kal_int32 result = DRM_RESULT_DATA_NOT_FOUND;
    drm_sdb_struct entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check database before sweep */
    memset(&entry, 0, sizeof(drm_sdb_struct));
	if (DRM_RESULT_OK == drmt_sdb_check(db_path))
    {
        if (DRM_RESULT_OK > (result = drmt_sdb_backup(db_path, backup_path)))
        {
            DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 8, 1, result));
            goto Error;
        }
    }
    else
    {
        if (DRM_RESULT_OK > (result = drmt_sdb_restore(db_path, backup_path)))
        {
            DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 8, 2, result));
            goto Error;
        }
    }

    if (FS_NO_ERROR > (handle_src = result = FS_OpenHint(backup_path, FS_READ_ONLY, DRM_get_open_hint(backup_path))))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 8, 3, result));
        goto Error;
    }

    if (FS_NO_ERROR > (handle_dst = result = FS_Open(db_path, FS_CREATE_ALWAYS)))
    {
        DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 8, 4, result));
        goto Error;
    }

    while (1)
    {
        if (DRM_RESULT_OK > (result = drmt_sdb_readF(handle_src, &entry)))
        {
            if (result == DRM_RESULT_EOF)
            {
                break;
            }
            DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 8, 5, result));
            goto Error;
        }

        if (entry.attr & DRM_SDB_ATTR_VALID == 0)
        {
            drmt_mem_free(entry.data);
            entry.data = NULL;
            continue;
        }

        if (DRM_RESULT_OK > (result = drmt_sdb_writeF(handle_dst, &entry)))
        {
            DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 8, 6, result));
            goto Error;
        }
        drmt_mem_free(entry.data);
        entry.data = NULL;
    }

    FS_Close(handle_src);
    FS_Close(handle_dst);

    if (DRM_RESULT_OK == drmt_sdb_check(db_path))
    {
        if (DRM_RESULT_OK > (result = drmt_sdb_backup(db_path, backup_path)))
        {
            DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 8, 7, result));
            goto Error;
        }
    }
    else
    {
        if (DRM_RESULT_OK > (result = drmt_sdb_restore(db_path, backup_path)))
        {
            DRM_DEBUG("[DRM] DB FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SDB_FAIL, 8, 8, result));
            goto Error;
        }
    }

    return DRM_RESULT_OK;

  Error:

    if (entry.data)
    {
        drmt_mem_free(entry.data);
        entry.data = NULL;
    }

    if (handle_src > 0)
    {
        FS_Close(handle_src);
    }
    if (handle_dst > 0)
    {
        FS_Close(handle_dst);
    }

    if (DRM_RESULT_OK > drmt_sdb_restore(db_path, backup_path))
    {
        ASSERT(0);
    }

    return result;
}

#define DRM_ASYNC_PROCESS_HANDLE_API

static kal_uint8 current_serial = 0;


/*****************************************************************************
 * FUNCTION
 *  drmt_async_set_current_serial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  serial      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void drmt_async_set_current_serial(kal_uint8 serial)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_serial = serial;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_async_get_current_serial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 drmt_async_get_current_serial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return current_serial;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_async_get_serial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 drmt_async_get_serial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_int32 handle, i;
    kal_uint8 serial = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(g_drm_process_mutex);

    for (i = 0; i < DRM_MAX_FILE_HANDLE; i++)
    {
        if (g_drm_process_tbl[i].status == DRM_PROC_ENCRYPT_READY)
        {
            g_drm_process_tbl[i].status = DRM_PROC_ENCRYPT_BUSY;
            break;
        }
    }

    EXT_ASSERT(i < DRM_MAX_FILE_HANDLE, 0, 0, 0);

    DRM_DEBUG("[DRM] handle number %d", (TRACE_GROUP_GENERAL, DRM_PROC_42E2ADC654B2973692BFFB2C07E71417, i));

    handle = drm_core_async_get_handle();

    if (handle < DRM_RESULT_OK)
    {
        EXT_ASSERT(0, 0, 0, 0);
        g_drm_process_tbl[i].status = 0;
        serial = 0;
    }
    else
    {
        g_drm_process_tbl[i].handle = handle;
        serial = i + 1;
    }
    kal_give_mutex(g_drm_process_mutex);
    return serial;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_async_free_serial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  serial      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool drmt_async_free_serial(kal_uint8 serial)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (serial > DRM_MAX_FILE_HANDLE || serial == 0)
    {
        return KAL_FALSE;
    }

    kal_take_mutex(g_drm_process_mutex);
    if (g_drm_process_tbl[serial - 1].status == DRM_PROC_ENCRYPT_FINISHED)
    {
        drm_core_async_free_handle(g_drm_process_tbl[serial - 1].handle);
        memset(&g_drm_process_tbl[serial - 1], 0, sizeof(drm_process_table_struct));
        result = KAL_TRUE;
    }
    else
    {
        result = KAL_FALSE;
    }
    kal_give_mutex(g_drm_process_mutex);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_async_cancel_process
 * DESCRIPTION
 *  
 * PARAMETERS
 *  serial      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drmt_async_cancel_process(kal_uint8 serial)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_int32 result = DRM_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (serial > DRM_MAX_FILE_HANDLE || serial == 0)
    {
        return DRM_RESULT_INVALID_PARA;
    }

    kal_take_mutex(g_drm_process_mutex);

    if (g_drm_process_tbl[serial - 1].status == DRM_PROC_ENCRYPT_BUSY)
    {
        g_drm_process_tbl[serial - 1].status = DRM_PROC_ENCRYPT_CANCELING;

        result = drm_core_async_cancel_handle(g_drm_process_tbl[serial - 1].handle);

        if (result != DRM_RESULT_OK)
        {
            g_drm_process_tbl[serial - 1].status = DRM_PROC_ENCRYPT_BUSY;
        }
    }
    else
    {
        result = DRM_RESULT_INVALID_PARA;
    }

    kal_give_mutex(g_drm_process_mutex);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_async_set_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  serial      [IN]        
 *  status      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool drmt_async_set_status(kal_uint8 serial, drm_proc_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (serial > DRM_MAX_FILE_HANDLE || serial == 0)
    {
        return KAL_FALSE;
    }

    kal_take_mutex(g_drm_process_mutex);
    g_drm_process_tbl[serial - 1].status = status;
    kal_give_mutex(g_drm_process_mutex);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_async_get_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  serial      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drmt_async_get_status(kal_uint8 serial)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    drm_proc_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (serial > DRM_MAX_FILE_HANDLE || serial == 0)
    {
        return 0;
    }

    kal_take_mutex(g_drm_process_mutex);
    status = g_drm_process_tbl[serial - 1].status;
    kal_give_mutex(g_drm_process_mutex);

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_async_get_operate_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  serial      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drmt_async_get_operate_handle(kal_uint8 serial)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (serial > DRM_MAX_FILE_HANDLE || serial == 0)
    {
        return 0;
    }

    kal_take_mutex(g_drm_process_mutex);
    handle = g_drm_process_tbl[serial - 1].handle;
    kal_give_mutex(g_drm_process_mutex);

    return handle;
}

#ifdef __DRM_SUPPORT_SD_CALLBACK__


/*****************************************************************************
 * FUNCTION
 *  drmt_sd_callback_register
 * DESCRIPTION
 *  register sd expiry callback function
 * PARAMETERS
 *  input           [IN]        Sd file handle
 *  timer           [IN]        Timer to expiry
 *  para            [IN]        Parameter of callback function
 *  callback        [IN]        Callback function for expiry sd
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drmt_sd_callback_register(FS_HANDLE input, kal_uint32 timer, void *para, drm_sd_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0, old_index = i;
    kal_uint32 ts;
    kal_char *cid = NULL;
    applib_time_struct cur_time, expire_time, inc_time;
    kal_int32 buf_size, old_ts = g_drm_sd_callback[0].timestamp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((i < DRM_SD_CALLBACK_MAX_NUM) && (g_drm_sd_callback[i].timer_id != NULL))
    {
        /* find oldest entry */
        if (old_ts > g_drm_sd_callback[i].timestamp)
        {
            old_ts = g_drm_sd_callback[i].timestamp;
            old_index = i;
        }
        i++;
    }

    /* callback table is full */
    if (i >= DRM_SD_CALLBACK_MAX_NUM)
    {
        drmt_sd_expiry_ind_struct *ind = NULL;
        DRM_DEBUG("[SD] Table Full", (TRACE_GROUP_GENERAL, DRM_SD_CB_TABLE_FULL, i));

        i = old_index;

        /* execute replaced callback function */
        ind = (drmt_sd_expiry_ind_struct*) construct_local_para(sizeof(drmt_sd_expiry_ind_struct), TD_RESET);

        ind->callback = g_drm_sd_callback[i].callback;
        ind->para = g_drm_sd_callback[i].para;
        ind->type = DRM_SD_EXPIRY_RECORD_REPLACE;

        drm_send_msg(MOD_DRMT, g_drm_sd_callback[i].src_mod, MSG_ID_DRMT_SD_EXPIRY_IND, (void*)ind, NULL);

        drmt_sd_callback_clear_entry(i);
    }

    /* 1. parse cid */
    buf_size = DRM_get_meta_size(input, DRM_META_CONTENTURI);
    if (buf_size > DRM_RESULT_OK)
    {
        cid = drmt_mem_alloc(buf_size);
        DRM_get_meta_data(input, DRM_META_CONTENTURI, cid, buf_size);
    }
    
    if (cid == NULL)
    {
        return DRM_RESULT_INVALID_FORMAT;
    }

    /* 2. calculate timer */
    if (timer == DRM_DEFAULT_UNLIMITED_WAIT)
    {
        memset(&expire_time, 0, sizeof(applib_time_struct));
    }
    else
    {
        applib_dt_get_rtc_time(&cur_time);
        applib_dt_utc_sec_2_mytime(applib_dt_mytime_2_utc_sec(&cur_time, KAL_FALSE)+ timer, &expire_time, KAL_FALSE);
    }

    /* 3. convert timestamp */
    ts = applib_dt_mytime_2_utc_sec(&cur_time, KAL_FALSE);

    /* insert new entry */
    g_drm_sd_callback[i].cid = cid;
    memcpy(&g_drm_sd_callback[i].timer, &expire_time, sizeof(applib_time_struct));
    g_drm_sd_callback[i].para = para;
    g_drm_sd_callback[i].timestamp = ts;
    g_drm_sd_callback[i].callback = callback;
    g_drm_sd_callback[i].src_mod = stack_get_active_module_id();

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_sd_callback_timer_expiry
 * DESCRIPTION
 *  callback function for seperate delievery file expiry
 * PARAMETERS
 *  serial          [?]         
 *  index(?)        [IN]        The expired entry
 * RETURNS
 *  void
 *****************************************************************************/
void drmt_sd_callback_timer_expiry(void *serial)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct cur_time;
    kal_uint8 index = *((kal_uint8*)serial), i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check expiry time */
    applib_dt_get_rtc_time(&cur_time);
    drmt_sd_callback_exec_cb(index, (kal_uint8) DRM_SD_EXPIRY_TIMEOUT);
    drmt_mem_free(serial);
    
    for (i = 0; i < DRM_SD_CALLBACK_MAX_NUM; i++)
    {
        if (i != index && 
            applib_dt_is_valid(&(g_drm_sd_callback[i].timer)) &&
            applib_dt_compare_time(&cur_time, &(g_drm_sd_callback[i].timer), NULL) != DT_TIME_LESS)
        {
            drmt_sd_callback_exec_cb(i, (kal_uint8) DRM_SD_EXPIRY_TIMEOUT);
        }
    }
    /* drmt_mem_free(index); */
}


/*****************************************************************************
 * FUNCTION
 *  drmt_sd_callback_update
 * DESCRIPTION
 *  update data of sd callback table
 * PARAMETERS
 *  serial          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void drmt_sd_callback_update(kal_uint8 serial)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (serial < DRM_SD_CALLBACK_MAX_NUM)
    {
        if (g_drm_sd_callback[serial].timer_id != NULL)
        {
            DRM_DEBUG("[SD] Clear serial = %d", (TRACE_GROUP_GENERAL, DRM_SD_CB_UPDATE, serial));

            memset(&g_drm_sd_callback[serial].timer, 0, sizeof(applib_time_struct));

            g_drm_sd_callback[serial].timer_id = NULL;
                
            return;
        }
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  drmt_sd_callback_clear_entry
 * DESCRIPTION
 *  clear data of sd callback table
 * PARAMETERS
 *  serial          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void drmt_sd_callback_clear_entry(kal_uint8 serial)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_DEBUG("[SD] Clear serial = %d", (TRACE_GROUP_GENERAL, DRM_SD_CB_CLEAR_ENTRY, serial));
    if (serial < DRM_SD_CALLBACK_MAX_NUM)
    {
        if (g_drm_sd_callback[serial].timer_id != NULL)
        {
            DRM_DEBUG("[SD] Stop timer, id = %d", (TRACE_GROUP_GENERAL, DRM_SD_CB_STOP_TIMER, g_drm_sd_callback[serial].timer_id));
        }
        memset(&(g_drm_sd_callback[serial]), 0, sizeof(drm_sd_callback_struct));
        drmt_mem_free(g_drm_sd_callback[serial].cid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  drmt_sd_callback_rights_arrive
 * DESCRIPTION
 *  Rights arrives and execute all mapped callback function
 * PARAMETERS
 *  serial          [IN]    serial in sd table
 *  cid             [IN]    cid of RO
 * RETURNS
 *  void
 *****************************************************************************/
void drmt_sd_callback_rights_arrive(kal_uint8 serial, kal_char *cid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    kal_char *dcf_cid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_DEBUG(("[SD] Rights Arrive"), (TRACE_INFO, DRM_SD_CB_RIGHTS_ARRIVE));
    for (i = 0; i < DRM_SD_CALLBACK_MAX_NUM; i++)
    {
        if (g_drm_sd_callback[i].cid != NULL)
        {
            if (strncmp(g_drm_sd_callback[i].cid, "MTK_FLDCF_cid", 10) == 0)
            {
                dcf_cid = g_drm_sd_callback[i].cid + 10;
            }
            else
            {
                dcf_cid = g_drm_sd_callback[i].cid;
            }
            if  (strcmp(dcf_cid, cid) == 0)
            {
                kal_take_mutex(g_drm_process_mutex);
                g_drm_process_tbl[serial - 1].sd_waiting = KAL_TRUE;
                kal_give_mutex(g_drm_process_mutex);

                drmt_sd_callback_exec_cb(i, DRM_SD_EXPIRY_RIGHTS_ARRIVE);
            }
        }
    }
}


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
kal_bool drmt_sd_callback_status(kal_uint8 serial)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool sd_waiting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (serial > DRM_MAX_FILE_HANDLE || serial == 0)
    {
        return 0;
    }

    kal_take_mutex(g_drm_process_mutex);
    sd_waiting = g_drm_process_tbl[serial - 1].sd_waiting;
    kal_give_mutex(g_drm_process_mutex);

    return sd_waiting;

}


/*****************************************************************************
 * FUNCTION
 *  drmt_sd_callback_exec_cb
 * DESCRIPTION
 *  Send sd expiry msg to execute callback function
 * PARAMETERS
 *  serial          [IN]        
 *  type            [IN]        
 *  index(?)        [IN]        The expired entry
 * RETURNS
 *  void
 *****************************************************************************/
void drmt_sd_callback_exec_cb(kal_uint8 serial, kal_uint8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drmt_sd_expiry_ind_struct *ind = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind = (drmt_sd_expiry_ind_struct*) construct_local_para(sizeof(drmt_sd_expiry_ind_struct), TD_RESET);

    ind->serial = serial;
    ind->callback = g_drm_sd_callback[serial].callback;
    ind->para = g_drm_sd_callback[serial].para;
    ind->type = type;

    DRM_DEBUG("[SD] execute callback = %d", (TRACE_GROUP_GENERAL, DRM_SD_CB_EXECUTE, serial));

    if (g_drm_sd_callback[serial].timer_id)
    {
        drmt_stop_timer(g_drm_sd_callback[serial].timer_id);
	  g_drm_sd_callback[serial].timer_id = NULL;
    }

    if (g_drm_sd_callback[serial].src_mod)
        drm_send_msg(MOD_DRMT, g_drm_sd_callback[serial].src_mod, MSG_ID_DRMT_SD_EXPIRY_IND, (void*)ind, NULL);
    
}

/*****************************************************************************
 * FUNCTION
 *  drmt_sd_callback_insert_timer_id
 * DESCRIPTION
 *  Send sd expiry msg to execute callback function
 * PARAMETERS
 *  serial          [IN]        
 *  type            [IN]        
 *  index(?)        [IN]        The expired entry
 * RETURNS
 *  void
 *****************************************************************************/
void drmt_sd_callback_insert_timer_id(kal_uint8 serial, void *timer_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_DEBUG("[SD] Insert tiemr id = %d, serial = %d", (TRACE_GROUP_GENERAL, DRM_SD_CB_INSERT_TIMER, timer_id, serial));
    if (serial < DRM_SD_CALLBACK_MAX_NUM)
    {
        g_drm_sd_callback[serial].timer_id = timer_id;
    }
    /* todo: else */
}
#endif /* __DRM_SUPPORT_SD_CALLBACK__ */ 

#ifdef __DRM_SUPPORT_SCAN_DISK__

#define DRM_SCAN_ATTR_LEVEL_PATH DRM_SDB_ATTR_RESERVED

static kal_wchar *scan_parent_path = NULL;
static kal_uint16 scan_parent_path_size = 0;
static kal_uint32 scan_parent_offset = 0;
static kal_uint32 scan_current_offset = 0;
static kal_int32 scan_queue_handle = 0;


/*****************************************************************************
 * FUNCTION
 *  drmt_scan_enqueue
 * DESCRIPTION
 *  add a file path into queue
 * PARAMETERS
 *  file_path           [IN]        File path
 *  level_path          [IN]        
 *  first_child(?)      [IN]        If this is the first child or not.
 * RETURNS
 *  >=0 offset
 *  < 0, fail, drm_proc_enum
 *****************************************************************************/
kal_int32 drmt_scan_enqueue(kal_wchar *file_path, kal_bool level_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 path_len = 0;
    kal_int16 attr = 0;
    kal_int32 result = DRM_RESULT_OK;

#ifndef __MTK_TARGET__
    kal_char buf[261];
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (level_path)
    {
        attr = DRM_SDB_ATTR_VALID | DRM_SCAN_ATTR_LEVEL_PATH;
    }
    else
    {
        attr = DRM_SDB_ATTR_VALID;
    }

    path_len = app_ucs2_strlen((kal_int8*) file_path);

    if (path_len > DRM_MAX_PATH_LENGTH)
    {
        ASSERT(0);
        return DRM_RESULT_SIZE_TOO_BIG;
    }

#ifndef __MTK_TARGET__
    kal_dchar2char(file_path, buf);
    if (level_path)
    {
        DRM_MAIN_DEBUGP((TRACE_GROUP_GENERAL, "\n[DRM] Scan enqueue level path, %s", buf));
    }
    else
    {
        /* DRM_MAIN_DEBUGP((TRACE_GROUP_GENERAL,"\n[DRM] Scan enqueue path, %s",buf)); */
    }
#endif /* __MTK_TARGET__ */ 
    result = drmt_sdb_addH(scan_queue_handle, (kal_uint8*) file_path, (kal_uint16) ((path_len + 1) << 1), attr);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_scan_dequeue
 * DESCRIPTION
 *  get the first entry in the queue
 * PARAMETERS
 *  file_path       [IN]        The file_path entry
 * RETURNS
 *  >=0 , offset of the entry in the queue file.
 *  < 0, drm_proc_enum
 *****************************************************************************/
kal_int32 drmt_scan_dequeue(kal_wchar *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = DRM_RESULT_DATA_NOT_FOUND;
    kal_int32 offset = 0;
    drm_sdb_struct entry;

#ifndef __MTK_TARGET__
    kal_char buf[261];
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EXT_ASSERT(file_path, 0, 0, 0);

  Start:

    /* seek to next item */
    FS_Seek(scan_queue_handle, scan_current_offset, FS_FILE_BEGIN);

    /* Load data */
    while (1)
    {
        if (DRM_RESULT_OK > (offset = result = drmt_sdb_readF(scan_queue_handle, &entry)))
        {
            if (result == DRM_RESULT_EOF)
            {
                result = DRM_RESULT_DATA_NOT_FOUND;
            }
            return result;
        }

        if (KAL_FALSE == drmt_sdb_check_pattern(&entry))
        {
            drmt_mem_free(entry.data);
            continue;
        }

        if ((entry.attr & DRM_SDB_ATTR_VALID) == 0)
        {
            drmt_mem_free(entry.data);
            continue;
        }

        if ((entry.data_len > DRM_MAX_PATH_LENGTH * 2))
        {
            ASSERT(0);
            drmt_mem_free(entry.data);
            continue;
        }

        /* len(parent) + "\" + len(child) + "\0" <= DRM_MAX_PATH_LENGTH
           scan_parent_path_size = len(parent) * 2 + 2
           entry.data_len = len(child) * 2 + 2
           => entry.data_len + scan_parent_path_size = len(parent) * 2 + len(child) * 2 + 4
                <= DRM_MAX_PATH_LENGTH */

        if (entry.data_len + scan_parent_path_size > DRM_MAX_PATH_LENGTH  * 2)
        {
            drmt_mem_free(entry.data);
            continue;
        }

        break;
    }

    /* check if it is a level path */
    if ((entry.attr & DRM_SCAN_ATTR_LEVEL_PATH) != 0)
    {
        /* delete old parent path */

        if (scan_parent_path)
        {
        #ifndef __MTK_TARGET__
            kal_dchar2char(scan_parent_path, buf);
            DRM_MAIN_DEBUGP((TRACE_GROUP_GENERAL, "\n[DRM] Scan dequeue delete level path, %s", buf));
        #endif /* __MTK_TARGET__ */ 
            drmt_sdb_deleteH(scan_queue_handle, scan_parent_offset, DRM_SDB_ATTR_DELETED | DRM_SCAN_ATTR_LEVEL_PATH);

            /* free old parent path */
            drmt_mem_free(scan_parent_path);
        }

        scan_parent_path = (kal_wchar*) entry.data;
        scan_parent_path_size = entry.data_len;
        scan_parent_offset = offset;
        scan_current_offset = offset + sizeof(entry.header) + sizeof(entry.footer) + sizeof(entry.attr) +
            sizeof(entry.data_len) + entry.data_len;

    #ifndef __MTK_TARGET__
        kal_dchar2char(scan_parent_path, buf);
        DRM_MAIN_DEBUGP((TRACE_GROUP_GENERAL, "\n[DRM] Scan dequeue change level path, %s, %d", buf,
                         scan_parent_offset));
    #endif /* __MTK_TARGET__ */ 
        goto Start;
    }

    drmt_sdb_deleteH(scan_queue_handle, offset, DRM_SDB_ATTR_DELETED);

    scan_current_offset = offset + sizeof(entry.header) + sizeof(entry.footer) + sizeof(entry.attr) +
        sizeof(entry.data_len) + entry.data_len;

    if (scan_parent_path)
    {
        /* special case, add 3 for *.* */
        kal_wsprintf(file_path, "%w\\%w", scan_parent_path, (kal_wchar*) entry.data);
        drmt_mem_free(entry.data);
    }
    else
    {
        kal_wsprintf(file_path, "%w", (kal_wchar*) entry.data);
        drmt_mem_free(entry.data);
    }

#ifndef __MTK_TARGET__
    kal_dchar2char(file_path, buf);
    DRM_MAIN_DEBUGP((TRACE_GROUP_GENERAL, "\n[DRM] Scan dequeue path, %s", buf));
#endif /* 1 */ 

    return DRM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_scan_sweep_queue
 * DESCRIPTION
 *  sweep the queue
 * PARAMETERS
 *  void
 * RETURNS
 *  drm_proc_enum
 *****************************************************************************/
kal_int32 drmt_scan_sweep_queue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drmt_sdb_sweep(DRM_SCAN_QUEUE_FILEPATH, DRM_SCAN_QUEUE_BACKUP_FILEPATH);
}


/*****************************************************************************
 * FUNCTION
 *  drmt_scan_init_queue
 * DESCRIPTION
 *  initial the queue
 * PARAMETERS
 *  reset_queue     [IN]        Delete the queue file or not
 * RETURNS
 *  drm_proc_enum
 *****************************************************************************/
kal_int32 drmt_scan_init_queue(kal_bool reset_queue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (reset_queue)
    {
        FS_Delete(DRM_SCAN_QUEUE_FILEPATH);
    }

    scan_parent_path = NULL;
    scan_parent_path_size = 0;
    scan_parent_offset = 0;
    scan_current_offset = 0;
    scan_queue_handle = 0;

    if (FS_NO_ERROR >
        (scan_queue_handle = result = FS_OpenHint(DRM_SCAN_QUEUE_FILEPATH, FS_READ_WRITE | FS_CREATE, DRM_get_open_hint(DRM_SCAN_QUEUE_FILEPATH))))
    {
        DRM_DEBUG("[DRM] Scan FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SCAN_FAIL, 4, 1, result));

        return result;
    }

    return DRM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_scan_deinit_queue
 * DESCRIPTION
 *  deinit all the data
 * PARAMETERS
 *  reset_queue     [IN]        Clean the queue or not.
 * RETURNS
 *  drm_proc_enum
 *****************************************************************************/
kal_int32 drmt_scan_deinit_queue(kal_bool reset_queue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scan_parent_path)
    {
        drmt_mem_free(scan_parent_path);
    }

    if (scan_queue_handle)
    {
        FS_Close(scan_queue_handle);
    }

    if (reset_queue)
    {
        FS_Delete(DRM_SCAN_QUEUE_FILEPATH);
    }

    scan_parent_path = NULL;
    scan_parent_path_size = 0;
    scan_parent_offset = 0;
    scan_current_offset = 0;
    scan_queue_handle = 0;

    return DRM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_scan_register_file
 * DESCRIPTION
 *  register file
 * PARAMETERS
 *  parent      [IN]        Parent
 *  child       [IN]        Child
 * RETURNS
 *  drm_proc_enum
 *****************************************************************************/
kal_int32 drmt_scan_register_file(kal_wchar *parent, kal_wchar *child)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *full_path;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (app_ucs2_strlen((kal_int8*)parent) + app_ucs2_strlen((kal_int8*)child) + 1 >= DRM_MAX_PATH_LENGTH )
    {
        return DRM_RESULT_INVALID_PARA;
    }

    full_path = (kal_wchar*) drmt_mem_alloc(DRM_MAX_PATH_LENGTH * 2);

    kal_wsprintf(full_path, "%w\\%w", parent, child);

#ifndef __MTK_TARGET__
{
    kal_char buf[261];
    kal_dchar2char(full_path, buf);
    DRM_MAIN_DEBUGP((TRACE_GROUP_GENERAL,"\n[DRM] Register, %s",buf));
}
#endif /* __MTK_TARGET__ */ 

    result = DRM_register_file(full_path);

    drmt_mem_free(full_path);

    return DRM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_scan_disk
 * DESCRIPTION
 *  deinit all the data
 * PARAMETERS
 *  serial              [IN]        
 *  type                [IN]        
 *  path                [?]         
 *  reset_queue(?)      [IN]        Clean the queue or not.
 * RETURNS
 *  drm_proc_enum
 *****************************************************************************/
kal_int32 drmt_scan_disk(kal_uint8 serial, kal_uint8 type, kal_wchar *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = DRM_RESULT_OK;
    kal_wchar *parent = NULL;
    kal_wchar *child = NULL;
    kal_int32 phandle = 0;
    FS_DOSDirEntry file_info;
    kal_bool first_child = KAL_TRUE;
    kal_wchar *tmp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    DRM_MEM_START_EVAL

    DRM_DEBUG("[DRM] Scan Start",(TRACE_GROUP_GENERAL,DRM_SCAN_START));

    /* have root path, we need to clean the queue */
    if (path && path[0]!= 0)
    {
        if (DRM_RESULT_OK > (result = drmt_scan_init_queue(KAL_TRUE)))
        {
            DRM_DEBUG("[DRM] Scan FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SCAN_FAIL, 6, 1, result));
            goto Error;
        }

        if (path[0] == '*') /* scan whole filesystem */
        {
            kal_uint16 tmp[4] = L"C:";
            kal_int32 drv = 0;

            do
            {
                if (drv == 0)
                {
                    drv = FS_PUBLIC_DRV;
                }
                else if (drv == FS_PUBLIC_DRV)
                {
                    drv = FS_CARD_DRV;
                }
                else if (drv == FS_CARD_DRV)
                {
                    drv = FS_CARD2_DRV;
                }
                else if (drv == FS_CARD2_DRV)
                {
                    break;
                }

                if (drv < 0)
                {
                    break;
                }

                tmp[0] = drv;
                if (DRM_RESULT_OK > (result = drmt_scan_enqueue(tmp, KAL_FALSE)))
                {
                    DRM_DEBUG("[DRM] Scan FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SCAN_FAIL, 6, 9, result));
                    goto Error;
                }

            } while (1);
        }
        else
        {
            if (DRM_RESULT_OK > (result = drmt_scan_enqueue(path, KAL_FALSE)))
            {
                DRM_DEBUG("[DRM] Scan FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SCAN_FAIL, 6, 2, result));
                goto Error;
            }
        }
    }
    else
    {
        if (DRM_RESULT_OK > (result = drmt_scan_init_queue(KAL_FALSE)))
        {
            DRM_DEBUG("[DRM] Scan FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SCAN_FAIL, 6, 3, result));
            goto Error;
        }
    }

    child = (kal_wchar*) drmt_mem_alloc(DRM_MAX_PATH_LENGTH << 1);
    parent = (kal_wchar*) drmt_mem_alloc((DRM_MAX_PATH_LENGTH + 3) << 1);

    while (1)
    {
        kal_int32 count = 0;

        /* Check if cancelled */
        if (drmt_async_get_status(serial) == DRM_PROC_ENCRYPT_CANCELING)
        {
            result = DRM_RESULT_CANCELED;
            DRM_DEBUG("[DRM] Scan FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SCAN_FAIL, 6, 4, result));
            break;
        }

        /* Check if there is more task in queue */
        if (drmt_peek_next_msg() > 0)
        {
            result = DRM_PROC_ENCRYPT_BUSY;
            DRM_DEBUG("[DRM] Scan FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SCAN_FAIL, 6, 5, result));
            break;
        }

        if (DRM_RESULT_OK > (result = drmt_scan_dequeue(parent)))
        {
            if (result == DRM_RESULT_DATA_NOT_FOUND)
            {
                DRM_DEBUG("[DRM] Scan Finished", (TRACE_GROUP_ERROR, DRM_SCAN_SUCCESS));

                result = DRM_RESULT_OK;
            }
            else
            {
                DRM_DEBUG("[DRM] Scan FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SCAN_FAIL, 6, 6, result));
            }
            break;
        }

        kal_wstrcat(parent, L"\\*");

        phandle = result = FS_FindFirst(
                            parent,
                            0,
                            (FS_ATTR_HIDDEN | FS_ATTR_SYSTEM | FS_ATTR_VOLUME),
                            &file_info,
                            child,
                            DRM_MAX_PATH_LENGTH << 1);

        if (result < FS_NO_ERROR)
        {
            phandle = 0;
            continue;
        }

        tmp = kal_wstrrchr(parent, '\\');
        *tmp = 0;

        first_child = KAL_TRUE;

        do
        {
            if (kal_wstrcmp(child, L".") == 0 || kal_wstrcmp(child, L"..") == 0)
            {
                continue;
            }

            /* length too long */
            if (app_ucs2_strlen((kal_int8*)parent) + app_ucs2_strlen((kal_int8*)child) + 1 >= DRM_MAX_PATH_LENGTH )
            {
                continue;
            }

            count++;
            if ((count & 0x1F) == 0)
            {
                /* Check if cancelled */
                if (drmt_async_get_status(serial) == DRM_PROC_ENCRYPT_CANCELING)
                {
                    /* we may skip some folder here */
                    break;
                }

                /* Check if there is more task in queue */
                if (drmt_peek_next_msg() > 0)
                {
                    break;
                }

                kal_sleep_task(1);
            }

            /* check if child is a folder or not */
            if (file_info.Attributes & FS_ATTR_DIR)
            {
                if (first_child)
                {
                    if (DRM_RESULT_OK > (result = drmt_scan_enqueue(parent, KAL_TRUE)))
                    {
                        DRM_DEBUG(
                            "[DRM] Scan FAIL, f=%d , p=%d, r = %d",
                            (TRACE_GROUP_ERROR, DRM_SCAN_FAIL, 6, 7, result));
                        goto Error;
                    }
                }

                if (DRM_RESULT_OK > (result = drmt_scan_enqueue(child, KAL_FALSE)))
                {
                    DRM_DEBUG("[DRM] Scan FAIL, f=%d , p=%d, r = %d", (TRACE_GROUP_ERROR, DRM_SCAN_FAIL, 6, 8, result));
                    goto Error;
                }
                first_child = KAL_FALSE;
            }
            else
            {
                drmt_scan_register_file(parent, child);
            }
        } while (FS_FindNext(phandle, &file_info, child, DRM_MAX_PATH_LENGTH << 1) == FS_NO_ERROR);

        FS_FindClose(phandle);
        phandle = 0;
    }

  Error:
    if (parent)
    {
        drmt_mem_free(parent);
    }

    if (child)
    {
        drmt_mem_free(child);
    }

    if (result == DRM_PROC_ENCRYPT_BUSY || result == DRM_RESULT_CANCELED)
    {
        drmt_scan_deinit_queue(KAL_FALSE);
    }
    else
    {
        drmt_scan_deinit_queue(KAL_TRUE);
    }

    if (phandle)
    {
        FS_FindClose(phandle);
    }

    DRM_MEM_END_EVAL

    return result;
}


#endif /* __DRM_SUPPORT_SCAN_DISK__ */ 


/*****************************************************************************
 * FUNCTION
 *  drmt_engine_is_process_database
 * DESCRIPTION
 *  DRM task create function
 * PARAMETERS
 *  void
 *  handle(?)       [IN]        
 * RETURNS
 *  success or fail
 *****************************************************************************/
kal_bool drmt_engine_is_process_database(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drmt_is_process_database;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_engine_set_process_database
 * DESCRIPTION
 *  set drm task is processing database or not.
 * PARAMETERS
 *  is_process_database     [IN]        
 *  is_busy(?)              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void drmt_engine_set_process_database(kal_bool is_process_database)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drmt_is_process_database = is_process_database;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_engine_is_busy
 * DESCRIPTION
 *  DRM task create function
 * PARAMETERS
 *  void
 *  handle(?)       [IN]        
 * RETURNS
 *  success or fail
 *****************************************************************************/
kal_bool drmt_engine_is_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drmt_is_busy;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_engine_set_busy
 * DESCRIPTION
 *  set drm task busy or not
 * PARAMETERS
 *  is_busy     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void drmt_engine_set_busy(kal_bool is_busy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drmt_is_busy = is_busy;
}

#endif /* !__DRM_EXTERNAL__ */

#endif /* __DRM_SUPPORT__ */ 

