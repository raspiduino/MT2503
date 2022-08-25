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
*  aud_trim.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio trimming handler.
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef MED_NOT_PRESENT
#ifdef __AUDIO_TRIM_SUPPORT__

/*-----------------------------------------------------------------------------
                    include files
-----------------------------------------------------------------------------*/
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"      /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"     /* Task creation */
#include "stacklib.h"        /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"      /* Event scheduler */
#include "stack_timer.h"     /* Stack timer */
#include "app_buff_alloc.h"

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
#include "fat_fs.h"
#include "drm_gprot.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_equipment.h"
#include "FSAL.h"
    
/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_utility.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_main.h"
#include "aud_main.h"

/*-----------------------------------------------------------------------------
                    macros, defines, typedefs, enums
-----------------------------------------------------------------------------*/
#define _AUD_TRIM_TRACE(x, y, z)    //AUD_TRIM_TRACE(x, y, z, __LINE__)

#define AUD_TRIM_RETURN(ret)                      \
    do{                                           \
        aud_set_result(ret);                      \
        aud_set_event(AUD_EVT_WAIT);              \
    } while(0)

typedef enum
{
    AUD_TRIM_STATE_IDLE,
    AUD_TRIM_STATE_TRIM,
    AUD_TRIM_STATE_TOTAL
} aud_trim_state_enum;

typedef struct
{
    MHdl*       mhdl_handle_p;       /* MHdl handle */
    STFSAL      fsal_handle;         /* Source file */
    kal_int32   file_output;         /* Output file */
    kal_uint32  file_length;         /* The length of output file */
    kal_bool    is_fsal_opened;      /* A flag indicates if the FSAL handle is opened */
    kal_uint8   format;              /* Format */
    kal_uint8   state;               /* State */
    module_type src_mod_id;          /* Source module ID */
} aud_trim_context_t;

/*-----------------------------------------------------------------------------
                    data declaraions
 ----------------------------------------------------------------------------*/
static kal_bool           g_is_trim_opened = KAL_FALSE;
static aud_trim_context_t g_trim_ctx;

/*-----------------------------------------------------------------------------
                    function prototypes
 ----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
                    private function declarations
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  _aud_trim_close
 * DESCRIPTION
 *  This function is to send the trimming result to the source module.
 *  trim handler.
 * PARAMETERS
 *  result      [IN]    Trimming result.
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_trim_send_result(kal_uint32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    aud_send_trim_result_ind(g_trim_ctx.src_mod_id, (kal_uint32)g_trim_ctx.mhdl_handle_p, result);
}


/*****************************************************************************
 * FUNCTION
 *  _aud_trim_event_callback_fct
 * DESCRIPTION
 *  This function is used to receive the callback events from L1Audio.
 * PARAMETERS
 *  handle_p       [IN]        MHdl handle. 
 *  event          [IN]        Play event.
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_trim_event_callback_fct(MHdl *handle_p, Media_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_trim_event_ind_struct *ind_p = (l4aud_trim_event_ind_struct*)
        construct_local_para(sizeof(l4aud_trim_event_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ind_p->handle = (kal_uint32)handle_p;
    ind_p->event  = event;

    aud_send_ilm(MOD_MED, MSG_ID_L4AUD_TRIM_EVENT_CALLBACK_IND, ind_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  _aud_trim_close
 * DESCRIPTION
 *  This function is to release all the allocated resources for the opened
 *  trim handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_trim_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status drv_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Directly return if the trim handle is not opened */
    if (!g_is_trim_opened)
    {
        return;
    }
    
    /* Close MHdl handler */
    if (g_trim_ctx.mhdl_handle_p)
    {
        /* Close MHdl handler */
        drv_result = g_trim_ctx.mhdl_handle_p->Close(g_trim_ctx.mhdl_handle_p);
        _AUD_TRIM_TRACE(drv_result, g_trim_ctx.mhdl_handle_p, -1);             
        
        g_trim_ctx.mhdl_handle_p = NULL;
    }
    
    /* Free FSAL resources */
    if (g_trim_ctx.is_fsal_opened)
    {
        /* Free buffer */
        if (g_trim_ctx.fsal_handle.bBuffering && g_trim_ctx.fsal_handle.pbBuf != NULL)
        {
            free_ctrl_buffer(g_trim_ctx.fsal_handle.pbBuf);
        }
        
        /* Close FSAL handler */
        FSAL_Close(&g_trim_ctx.fsal_handle);
        
        g_trim_ctx.is_fsal_opened = KAL_FALSE;
    }

    /* Close file output handle */
    if (g_trim_ctx.file_output >= 0)
    {
        FS_Close(g_trim_ctx.file_output);
        g_trim_ctx.file_output = -1;
    }
    
    g_is_trim_opened = KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  _aud_trim_stop
 * DESCRIPTION
 *  This function is to stop the trimming.
 * PARAMETERS
 *  void
 * RETURNS
 *  The result of stop.
 *****************************************************************************/
static kal_int32 _aud_trim_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status drv_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    drv_result = g_trim_ctx.mhdl_handle_p->Stop(g_trim_ctx.mhdl_handle_p);
    _AUD_TRIM_TRACE(drv_result, g_trim_ctx.mhdl_handle_p, -1);

    if (drv_result == MEDIA_SUCCESS)
    {
        /* Enter IDLE state */
        g_trim_ctx.state = AUD_TRIM_STATE_IDLE;
    }

    /* Free working buffer */
    aud_util_free_ring_buffer();

    return aud_get_res(drv_result);
}

/*-----------------------------------------------------------------------------
                    public function declarations
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  aud_trim_open_req_hdlr
 * DESCRIPTION
 *  This function is used to open a trimming handler.
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void aud_trim_open_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32                  file_len = 0;
    FSAL_Status                 fsal_result;
    kal_uint8*                  fsal_buf_p = NULL;
    media_open_func_ptr         open_fct = NULL;
    kal_int32                   result = MED_RES_FAIL;
    l4aud_trim_open_req_struct* msg_p = (l4aud_trim_open_req_struct*) ilm_ptr->local_para_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg_p->file_name_in && msg_p->file_name_out && msg_p->handle_p);
    
    /* Check if trimming handler is already opened. Currently, we only support one instance. */
    if (g_is_trim_opened)
    {
        result = MED_RES_BUSY;
        goto aud_trim_open_failed;
    }

    /* Initialize context */
    g_is_trim_opened = KAL_TRUE;
    memset(&g_trim_ctx, 0, sizeof(aud_trim_context_t));
    g_trim_ctx.file_output = -1;
    g_trim_ctx.src_mod_id = ilm_ptr->src_mod_id;

    /* Select a MHdl open function per media format */
    g_trim_ctx.format = med_get_media_type(msg_p->file_name_in);

    switch (g_trim_ctx.format)
    {
    #ifdef DAF_DECODE
        case MED_TYPE_DAF:
    #endif /* DAF_DECODE */
            open_fct = DAF_Open;
            break;
        default:
            /* Unsupport format */
            ASSERT(0);
    }

    if (open_fct)
    {
        /* Create a FSAL handler */
        if ((fsal_result = FSAL_Open(&g_trim_ctx.fsal_handle, msg_p->file_name_in, FSAL_READ_SHARED)) != FSAL_OK)
        {
            result = MED_RES_OPEN_FILE_FAIL;
            goto aud_trim_open_failed;
        }

        g_trim_ctx.is_fsal_opened = KAL_TRUE;
        
        fsal_buf_p = (kal_uint8*) get_ctrl_buffer(sizeof(kal_uint8) * AUD_PROC_BUF_SIZE);
        FSAL_SetBuffer(&g_trim_ctx.fsal_handle, AUD_PROC_BUF_SIZE, fsal_buf_p);

        /* Open a MHdl handler */
        g_trim_ctx.mhdl_handle_p = open_fct(_aud_trim_event_callback_fct, &g_trim_ctx.fsal_handle, NULL);
        _AUD_TRIM_TRACE(g_trim_ctx.mhdl_handle_p, g_trim_ctx.format, fsal_buf_p);

        if (g_trim_ctx.mhdl_handle_p == NULL)
        {
            result = MED_RES_BAD_FORMAT;
            goto aud_trim_open_failed;
        }

        /* Create output file handle */
        g_trim_ctx.file_output = FS_Open(msg_p->file_name_out, FS_READ_WRITE | FS_OPEN_SHARED | FS_NOBUSY_CHECK_MODE);
    
        if (g_trim_ctx.file_output >= 0) /* File already exists */
        {
            /* Check if the size of file is 0 because MMI may create the file to be trimmed to in advance */
            FS_GetFileSize(g_trim_ctx.file_output, &file_len);
            
            if (file_len != 0)
            {
                /* Seek to the beginning of the file to overwrite all the data */
                FS_Seek(g_trim_ctx.file_output, 0, FS_FILE_BEGIN);
            }
        }
        else /* File does not exist */
        {
            /* Create a new file */
            g_trim_ctx.file_output = FS_Open(msg_p->file_name_out, FS_CREATE | FS_READ_WRITE | FS_OPEN_SHARED | FS_NOBUSY_CHECK_MODE);
        }

        _AUD_TRIM_TRACE(g_trim_ctx.file_output, file_len, -1);

        if (g_trim_ctx.file_output < 0)
        {
            result = MED_RES_OPEN_FILE_FAIL;
            goto aud_trim_open_failed;
        }
    }

    /* Open successful */
    *msg_p->handle_p = (kal_uint32)g_trim_ctx.mhdl_handle_p;
    AUD_TRIM_RETURN(MED_RES_OK);
    return;

aud_trim_open_failed:
    /* Open failed */
    _aud_trim_close();
    *msg_p->handle_p = (kal_uint32)0;
    AUD_TRIM_RETURN(result);
}


/*****************************************************************************
 * FUNCTION
 *  aud_trim_close_req_hdlr
 * DESCRIPTION
 *  This function is used to close a trimming handler.
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void aud_trim_close_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_trim_close_req_struct* msg_p = (l4aud_trim_close_req_struct*) ilm_ptr->local_para_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Make sure it's not in trimming state */
    ASSERT(g_trim_ctx.state == AUD_TRIM_STATE_IDLE);
    
    _aud_trim_close();

    AUD_TRIM_RETURN(MED_RES_OK);
}


/*****************************************************************************
 * FUNCTION
 *  aud_trim_event_callback_hdlr
 * DESCRIPTION
 *  This function is used to handle the callback events from L1Audio.
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void aud_trim_event_callback_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8*                   buf_p = NULL;
    kal_uint32                   buf_len; /* 2 bytes per unit */
    kal_uint32                   len;     /* 1 byte per unit */
    kal_int32                    fs_result = FS_NO_ERROR;
    kal_int32                    med_result = MED_RES_OK;
    l4aud_trim_event_ind_struct* ind_p = (l4aud_trim_event_ind_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Validate event */
    if ((ind_p->handle != (kal_uint32)g_trim_ctx.mhdl_handle_p) ||
        (g_trim_ctx.state != AUD_TRIM_STATE_TRIM))
    {
        _AUD_TRIM_TRACE(ind_p->handle, g_trim_ctx.mhdl_handle_p, g_trim_ctx.state);
        return;
    }

    _AUD_TRIM_TRACE(ind_p->handle, ind_p->event, -1);

    switch (ind_p->event)
    {
        case MEDIA_DATA_NOTIFICATION:
        {
            /* Get read buffer from L1Audio */
            g_trim_ctx.mhdl_handle_p->GetReadBuffer(g_trim_ctx.mhdl_handle_p, &buf_p, &buf_len);
            
            if (buf_len > 0)
            {
                ASSERT(buf_p != NULL);
                
                /* Write to file system */
                fs_result = FS_Write(g_trim_ctx.file_output,
                                     buf_p,
                                     buf_len,
                                     &len);
                _AUD_TRIM_TRACE(fs_result, buf_len, len);

                if (fs_result == FS_NO_ERROR)
                {
                    /* Update file offset */
                    g_trim_ctx.file_length += len;
                    
                    _AUD_TRIM_TRACE(g_trim_ctx.file_output, g_trim_ctx.file_length, -1);

                    /* Sleep MED for a moment such that MMI may have chance to cancel the trimming */
                    kal_sleep_task(2);
                    
                    /* Notify L1Audio how many bytes are read. L1audio will fire another MEDIA_DATA_NOTIFICATION
                     * event if there is more data to be trimmed.
                     */
                    g_trim_ctx.mhdl_handle_p->ReadDataDone(g_trim_ctx.mhdl_handle_p, buf_len);
                }
                else
                {
                    /* Stop the trimming */
                    _aud_trim_stop();

                    /* Notify MMI with failure reason */
                    switch (fs_result)
                    {
                        case FS_DISK_FULL:
                            med_result = MED_RES_DISC_FULL;
                            break;
                        case FS_MSDC_WRITE_SECTOR_ERROR:
                        case FS_MEDIA_CHANGED:
                            med_result = MED_RES_NO_DISC;
                            break;
                        default:
                            med_result = MED_RES_ERROR;
                            break;
                    }

                    _aud_trim_send_result( med_result);
                }
            }
            
            break;
        }
        case MEDIA_END:
            /* End of trimming */
            _aud_trim_send_result(MED_RES_END_OF_FILE);
            break;
        default:
            /* Something wrong? */
            _aud_trim_send_result(MED_RES_ERROR);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_trim_start_req_hdlr
 * DESCRIPTION
 *  This function is used to start a trimming.
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void aud_trim_start_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status drv_result;
    l4aud_trim_start_req_struct* msg_p = (l4aud_trim_start_req_struct*) ilm_ptr->local_para_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    /* Validate handle */
    if (msg_p->handle != (kal_uint32)g_trim_ctx.mhdl_handle_p)
    {
        AUD_TRIM_RETURN(MED_RES_INVALID_HANDLE);
    }

    /* Set working buffer */
    aud_util_alloc_ring_buffer();
    g_trim_ctx.mhdl_handle_p->SetBuffer(g_trim_ctx.mhdl_handle_p, (kal_uint8*) aud_context_p->ring_buf, AUD_RING_BUFFER_SIZE);
        
    drv_result = g_trim_ctx.mhdl_handle_p->Trim(g_trim_ctx.mhdl_handle_p);
    _AUD_TRIM_TRACE(drv_result, g_trim_ctx.mhdl_handle_p, -1);

    if (drv_result == MEDIA_SUCCESS)
    {
        /* Enter TRIM state */
        g_trim_ctx.state = AUD_TRIM_STATE_TRIM;
    }
    else
    {
        /* Free working buffer */
        aud_util_free_ring_buffer();
    }
    
    AUD_TRIM_RETURN(aud_get_res(drv_result));
}


/*****************************************************************************
 * FUNCTION
 *  aud_trim_stop_req_hdlr
 * DESCRIPTION
 *  This function is used to stop a trimming.
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void aud_trim_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    l4aud_trim_stop_req_struct* msg_p = (l4aud_trim_stop_req_struct*) ilm_ptr->local_para_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    /* Validate handle */
    if (msg_p->handle != (kal_uint32)g_trim_ctx.mhdl_handle_p)
    {
        AUD_TRIM_RETURN(MED_RES_INVALID_HANDLE);
    }

    result = _aud_trim_stop();

    AUD_TRIM_RETURN(result);
}


/*****************************************************************************
 * FUNCTION
 *  aud_trim_set_param_req_hdlr
 * DESCRIPTION
 *  This is a general function to set the settings of a trimming handler.
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void aud_trim_set_param_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status drv_result = MEDIA_FAIL;
    l4aud_trim_set_param_req_struct *msg_p = (l4aud_trim_set_param_req_struct*) ilm_ptr->local_para_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Validate handle */
    if (msg_p->handle != (kal_uint32)g_trim_ctx.mhdl_handle_p)
    {
        AUD_TRIM_RETURN(MED_RES_INVALID_HANDLE);
    }

    switch (msg_p->set_type)
    {
        case AUD_TRIM_SET_START_TIME:
            drv_result = g_trim_ctx.mhdl_handle_p->SetStartTime(g_trim_ctx.mhdl_handle_p, (kal_uint32)msg_p->data_p);
            break;
        case AUD_TRIM_SET_STOP_TIME:
            drv_result = g_trim_ctx.mhdl_handle_p->SetStopTime(g_trim_ctx.mhdl_handle_p, (kal_uint32)msg_p->data_p);
            break;
        case AUD_TRIM_SET_CACHE_TABLE:
            g_trim_ctx.mhdl_handle_p->SetCacheTbl(g_trim_ctx.mhdl_handle_p, (kal_uint8*)msg_p->data_p, NULL);
            drv_result = MEDIA_SUCCESS;
            break;
        default:
            drv_result = MEDIA_UNSUPPORTED_OPERATION;
            break;
    }

    _AUD_TRIM_TRACE(drv_result, msg_p->set_type, (kal_uint32)msg_p->data_p);
    
    AUD_TRIM_RETURN(aud_get_res(drv_result));
}


/*****************************************************************************
 * FUNCTION
 *  aud_trim_get_param_req_hdlr
 * DESCRIPTION
 *  This is a general function to get the settings of a trimming handler.
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void aud_trim_get_param_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status drv_result = MEDIA_FAIL;
    l4aud_trim_get_param_req_struct *msg_p = (l4aud_trim_get_param_req_struct*) ilm_ptr->local_para_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    /* Validate handle */
    if (msg_p->handle != (kal_uint32)g_trim_ctx.mhdl_handle_p)
    {
        AUD_TRIM_RETURN(MED_RES_INVALID_HANDLE);
    }

    switch (msg_p->get_type)
    {
        case AUD_TRIM_GET_CURRENT_TIME:
            *((kal_uint32*)msg_p->data_p) = g_trim_ctx.mhdl_handle_p->GetCurrentTime(g_trim_ctx.mhdl_handle_p);
            *((kal_uint16*)msg_p->data_len_p) = sizeof(kal_uint32);
            drv_result = MEDIA_SUCCESS;
            break;
        default:
            drv_result = MEDIA_UNSUPPORTED_OPERATION;
            break;
    }

    _AUD_TRIM_TRACE(drv_result, msg_p->get_type, *((kal_uint32*)msg_p->data_p));
    
    AUD_TRIM_RETURN(aud_get_res(drv_result));
}

#endif /* __AUDIO_TRIM_SUPPORT__ */
#endif /* MED_NOT_PRESENT */ 

