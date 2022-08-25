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
 * aud_vm.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes voice memo related functions of audio manager task.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/******************************************************************
 * MODULE
 *    AUD_VM
 * DESCRIPTION
 *    This module defines the voice memo related function for Audio Manager.
 *  
 ******************************************************************/

#ifndef MED_NOT_PRESENT

/*****************************************************************************
 * includes
 *****************************************************************************/
#include "med_global.h"

#ifdef __VM_CODEC_SUPPORT__
#if defined(VM_SUPPORT) && defined(VM_LOG)

#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"     /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"    /* Task creation */
#include "stacklib.h"       /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"     /* Event scheduler */
#include "stack_timer.h"    /* Stack timer */

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"

/* for FAT FS */
#include "fat_fs.h"
#include "rtc_sw.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "aud_main.h"
#include "aud_recorder.h"


#include "med_main.h"
#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

/*-----------------------------------------------------------------------------
                    macros, defines, typedefs, enums
-----------------------------------------------------------------------------*/
#define _AUD_MODULE_VM_TRACE(x, y, z)        AUD_MODULE_VM_TRACE(x, y, z, __LINE__)
#define MAX_VM_FILE_NO                       (2)
#define MAX_VM_DIR_LEN                       (20)
#define MAX_VM_LOG_LEN                       (200*1024) /* 200K */
#define VM_PATH                              L"Audio"

/*-----------------------------------------------------------------------------
                    data declaraions
 ----------------------------------------------------------------------------*/
static kal_uint8 g_vm_idx = 0;
static kal_uint8 g_vm_type = MEDIA_FORMAT_GSM_EFR;
static kal_wchar g_vm_dir[MAX_VM_DIR_LEN] = { 0 };

/*-----------------------------------------------------------------------------
                    private function declarations
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  _aud_vm_get_record_file_name
 * DESCRIPTION
 *  This function is used to get the file name to be recorded to and delete 
 *  the LRU recorded file.
 * PARAMETERS
 *  file_name       [OUT]   The file name to be recorded to.
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_vm_get_record_file_name(kal_wchar* file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 record_idx;   /* The index of the file to be recorded to */
    kal_uint8 delete_idx;   /* The index of the file to be deleted */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* The recording sequence is 0 -> 1 -> ... -> MAX_VM_FILE_NO -> 0
     * When a recording is started, the next index will be retrieved as
     * the file name to be recoreded to and the file name which is least 
     * recently used (LRU) will be deleted.
     */
    g_vm_idx = (g_vm_idx + 1) % (MAX_VM_FILE_NO + 1);
    record_idx = g_vm_idx;
    delete_idx = (g_vm_idx + 1) % (MAX_VM_FILE_NO + 1);
    
    _AUD_MODULE_VM_TRACE(record_idx, delete_idx, -1);
    
    /* Delete the LRU file */
    kal_wsprintf(file_name, "%w\\log%d.vm", g_vm_dir, delete_idx);
    FS_Delete(file_name);

    /* Specify the file name to be recorded to */
    kal_wsprintf(file_name, "%w\\log%d.vm", g_vm_dir, record_idx);
    FS_Delete(file_name); /* Delete the file if it exists already */
}


/*****************************************************************************
 * FUNCTION
 *  _aud_vm_recorder_event_hdlr
 * DESCRIPTION
 *  This function is to handle recorder event when the record is terminated.
 * PARAMETERS
 * recorder_p       [IN]      Recorder handle.
 * reason           [IN]      Termination reason.
 * file_handle_p    [IN]      File handle.
 * param            [IN]      Callback paramter which is remained unaltered when
 *                            opening the recorder.
 * RETURNS
 *  KAL_TRUE                  Continue the recording if reaching size or time limit.
 *  KAL_FALSE                 Terminate the recording.
 *****************************************************************************/
static kal_bool _aud_vm_recorder_event_hdlr(med_aud_recorder_t*       recorder_p,
                                            med_aud_recorder_reason_t reason,
                                            kal_int32*                file_handle_p,
                                            void*                     param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar  file_name[MAX_VM_DIR_LEN];
    kal_int32  file_handle;
    kal_uint32 file_flag = FS_CREATE_ALWAYS | FS_READ_WRITE | FS_OPEN_SHARED | FS_NOBUSY_CHECK_MODE; /* Disable Busy Check Mode For Record */
    kal_bool   b_continue = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (reason)
    {
        case AUD_RECORDER_REASON_REACH_SIZE_LIMIT: /* Reach size limit */
        {
            /* Close current file handle first */
            FS_Close(*file_handle_p);

            /* Get the next file handle to be recorded to */
            _aud_vm_get_record_file_name(file_name);

            file_handle = FS_Open(file_name, file_flag);
            _AUD_MODULE_VM_TRACE(file_handle, *file_handle_p, -1);

            if (file_handle >= 0)
            {
                /* Replace file handle with the new opened one */
                *file_handle_p = file_handle;

                /* Continue the record */
                b_continue = KAL_TRUE;
            }
            else
            {
                /* Termineate the record */
                b_continue = KAL_FALSE;
            }
            break;
        }
        case AUD_RECORDER_REASON_REACH_TIME_LIMIT: /* Reach time limit */
            break;
        /* The recording is terminated */
        case AUD_RECORDER_REASON_DISK_FULL:
        case AUD_RECORDER_REASON_NO_DISK:
        case AUD_RECORDER_REASON_ERROR:
        default:
        {
            /* Close the recorder */
            recorder_p->close(recorder_p);
            recorder_p->destroy(recorder_p);
            aud_context_p->recorder_p = NULL;

            /* Enter idle state */
            aud_enter_state(AUD_VM_IDLE);
            
            break;
        }
    }
    
    return b_continue;
}


/*-----------------------------------------------------------------------------
                    public functions
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  aud_vm_init
 * DESCRIPTION
 *  This function is used to init aud_vm module
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void aud_vm_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 drv_letter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Get VM dir */
    drv_letter = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_I_SYSTEM | FS_DRIVE_V_NORMAL);
    kal_wsprintf(g_vm_dir, "%c:\\%w", drv_letter, VM_PATH);

    /* Determine VM type */
#ifdef VOICE_RECOGNITION_TEST
    g_vm_type = MEDIA_FORMAT_PCM_8K;
#else 
    g_vm_type = MEDIA_FORMAT_GSM_EFR;
#endif

    return;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_start_logging
 * DESCRIPTION
 *  Start VM logging.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_start_logging(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_cfg_t recorder_cfg;
    med_aud_recorder_t*    recorder_p = NULL;
    kal_wchar              file_name[MAX_VM_DIR_LEN];
    kal_int32              result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MTK_TARGET__

    /* Construct a recorder */
    recorder_p = aud_recorder_media_construct();

    if (recorder_p != NULL)
    {
        /* Get the file name to be recorded to */
        _aud_vm_get_record_file_name(file_name);
        
        /* Configure the recorder */
        recorder_cfg.file_name       = file_name;
        recorder_cfg.format          = g_vm_type;
        recorder_cfg.quality         = 0; /* Don't care */
        recorder_cfg.is_low_priority = KAL_FALSE;
        recorder_cfg.is_speech_on    = aud_context_p->speech_on;
        recorder_cfg.is_fm_record    = KAL_FALSE;
        recorder_cfg.cb_fct          = _aud_vm_recorder_event_hdlr;
        recorder_cfg.cb_param        = NULL;

        /* Open a recorder */
        result = recorder_p->open(recorder_p, &recorder_cfg);
        _AUD_MODULE_VM_TRACE(result, recorder_p, -1);

        if (result == MED_RES_OK)
        {
            /* Update recorder handle */
            aud_context_p->recorder_p = recorder_p;
            
            /* Set maximum record size */
            recorder_p->set(recorder_p,
                            AUD_RECORDER_SET_SIZE_LIMIT,
                            (void*)MAX_VM_LOG_LEN,
                            sizeof(kal_uint32));

            /* Start recording */
            result = recorder_p->record(recorder_p);
            _AUD_MODULE_VM_TRACE(result, recorder_p, -1);

            if (result == MED_RES_OK)
            {
                /* Enter VM-record state */
                aud_enter_state(AUD_VM_RECORD);
            }
            else
            {
                /* Close recorder handle */
                recorder_p->close(recorder_p);
                recorder_p->destroy(recorder_p);
                aud_context_p->recorder_p = NULL;
            }
        }
        else /* Open failed */
        {
            /* Remember to destroy the recorder if failed to open */
            recorder_p->destroy(recorder_p);
        }
    }
    
#endif  /*__MTK_TARGET__*/
}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_stop_logging
 * DESCRIPTION
 *  Stop VM logging.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_stop_logging(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    med_aud_recorder_t* recorder_p = aud_context_p->recorder_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MTK_TARGET__

    if ((aud_context_p->state == AUD_VM_RECORD) && (recorder_p != NULL))
    {
        /* Stop record */
        result = recorder_p->stop(recorder_p);
        _AUD_MODULE_VM_TRACE(result, recorder_p, -1);

        /* Close recorder handle */
        recorder_p->close(recorder_p);
        recorder_p->destroy(recorder_p);
        aud_context_p->recorder_p = NULL;
        
        /* Enter idle state */
        aud_enter_state(AUD_VM_IDLE);
    }
    
#endif  /*__MTK_TARGET__*/    
}

#endif /* defined(VM_SUPPORT) && defined(VM_LOG) */ 

#endif /*__VM_CODEC_SUPPORT__*/

#endif /* MED_NOT_PRESENT */ 


