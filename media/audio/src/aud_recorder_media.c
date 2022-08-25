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
 * aud_recorder_media.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary functions of media recorder.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/******************************************************************
 * MODULE
 *    Media Recorder
 * DESCRIPTION
 *    This module defines related function of Media Recorder.
 *  
 ******************************************************************/

#ifndef MED_NOT_PRESENT

/*-----------------------------------------------------------------------------
                    include files
-----------------------------------------------------------------------------*/
//#include "kal_release.h"
#include "kal_trace.h"
//#include "stack_common.h"
//#include "stack_msgs.h"
//#include "app_ltlcom.h"      /* Task message communiction */
//#include "syscomp_config.h"
//#include "task_config.h"     /* Task creation */
//#include "stacklib.h"        /* Basic type for dll, evshed, stacktimer */
//#include "event_shed.h"      /* Event scheduler */
//#include "stack_timer.h"     /* Stack timer */

/* global includes */
#include "l1audio.h"
//#include "device.h"
//#include "resource_audio.h"
//#include "fat_fs.h"
//#include "drm_gprot.h"
//#include "nvram_enums.h"
//#include "nvram_struct.h"
//#include "nvram_user_defs.h"
//#include "nvram_data_items.h"
//#include "custom_nvram_editor_data_item.h"
//#include "custom_equipment.h"
//#include "FSAL.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_utility.h"
#include "med_struct.h"
//#include "med_api.h"
#include "med_context.h"
#include "med_main.h"
#include "aud_main.h"
#include "aud_recorder.h"

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "fs_errcode.h"
#include "kal_public_api.h"
#include "fs_func.h"
#include "fs_type.h"
#include "stack_config.h"
#include "string.h"
#include "med_smalloc.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#ifdef __KARAOKE_SUPPORT__
extern kal_wchar g_record_file_name[MAX_MEDIA_FILE_NAME];
#endif

#if defined(__MTK_TARGET__) && defined(__MED_AUD_REC_MOD__)
/*-----------------------------------------------------------------------------
                    macros, defines, typedefs, enums
-----------------------------------------------------------------------------*/
#define _AUD_RECORDER_MEDIA_TRACE(x, y, z)   AUD_RECORDER_MEDIA_TRACE(x, y, z, __LINE__)
#define _AUD_RECORDER_MEDIA2_TRACE(x, y)     AUD_RECORDER_MEDIA2_TRACE(x, y,  __LINE__)
#define _AUD_RECORDER_MEDIA1_TRACE(x)        AUD_RECORDER_MEDIA1_TRACE(x, __LINE__)


#define AUD_RECORDER_MEM_MARGIN              (512)
#define AUD_RECORDER_BUFFER_THRESHOLD        (200)  /* 200 words (400 bytes) by default */
#define AUD_RECORDER_RING_BUF_SIZE           (AUD_RING_BUFFER_SIZE)

/* Media Event */
typedef struct
{
    med_aud_recorder_t*           recorder_p;      /* Recorder handle */
    Media_Event                   event;           /* Event */
    kal_uint32                    time_stamp;      /* Time stamp of the callback event */
} med_aud_recorder_media_event_t;

/* Media Recorder */
typedef struct
{
    med_aud_recorder_t            itf;             /* Recorder interfaces */
    kal_uint32                    time_stamp;      /* Time stamp of the constructed recorder */
    kal_int32                     file_handle;     /* File handle */
    kal_uint32                    file_offset;     /* File offset */
    kal_uint32                    size_committed;  /* File Size committed, in KB*/
    kal_uint32                    time_limit;      /* Time limit */
    kal_uint32                    size_limit;      /* Size limit */
    kal_int16                     format;          /* Record format */
    kal_uint8                     quality;         /* Record quality */
    kal_uint8                     state;           /* Recorder state */
    kal_uint8                     rat_mode;        /* Speech rat mode */
    kal_bool                      is_speech_on;    /* Indicate if speech is being on */
    kal_bool                      is_fm_record;    /* Indicate if it's a FM recording */
    kal_bool                      is_low_priority; /* Indicate if use MED-V thread to write recorded data */
    kal_uint16*                   ring_buffer_p;   /* Ring buffer */
    med_aud_recorder_cb_fct       cb_fct;          /* Callback fucntion */
    void*                         cb_param;        /* Callback parameter */
} med_aud_recorder_media_t;

/*-----------------------------------------------------------------------------
                    data declaraions
 ----------------------------------------------------------------------------*/
static med_aud_recorder_t* g_recorder_p = NULL; /* Current recorder handle */
static kal_mutexid g_rec_mutex = 0;             /* A mutex to protect mutually exclusive section */

/*-----------------------------------------------------------------------------
                    function prototypes
 ----------------------------------------------------------------------------*/ 
static void _aud_recorder_media_free_buffer(med_aud_recorder_t* recorder_p);
static kal_uint8 _aud_recorder_media_update_header(med_aud_recorder_t* recorder_p);
static kal_bool _aud_recorder_media_is_reach_limit(med_aud_recorder_t* recorder_p, kal_uint32 buf_len);
static void _aud_recorder_media_stop_record(med_aud_recorder_t* recorder_p);

/*-----------------------------------------------------------------------------
                    private function declarations
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  _aud_recorder_media_fs_result_to_med
 * DESCRIPTION
 *  This function converts FS result to MED result.
 * PARAMETERS
 *  fs_result      [IN]        FS result.              
 * RETURNS
 *  MED result
 *****************************************************************************/
static kal_int32 _aud_recorder_media_term_reason_to_med(med_aud_recorder_reason_t result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 med_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch (result)
    {
        case AUD_RECORDER_REASON_OK:
        case AUD_RECORDER_REASON_REACH_SIZE_LIMIT:
        case AUD_RECORDER_REASON_REACH_TIME_LIMIT:
            med_result = MED_RES_OK;
            break;
        case AUD_RECORDER_REASON_DISK_FULL:
            med_result = MED_RES_DISC_FULL;
            break;
        case AUD_RECORDER_REASON_NO_DISK:
            med_result = MED_RES_NO_DISC;
            break;
        default:
            med_result = MED_RES_ERROR;
            break;
    }
    
    return med_result;
}


/*****************************************************************************
 * FUNCTION
 *  _aud_recorder_media_fs_result_to_term_reason
 * DESCRIPTION
 *  This function converts FS result to termination reason.
 * PARAMETERS
 *  fs_result      [IN]        FS result.              
 * RETURNS
 *  Termination reason.
 *****************************************************************************/
static med_aud_recorder_reason_t _aud_recorder_media_fs_result_to_term_reason(kal_int32 fs_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_reason_t term_reason;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch (fs_result)
    {
        case FS_DISK_FULL:
            term_reason = AUD_RECORDER_REASON_DISK_FULL;
            break;
        case FS_MSDC_WRITE_SECTOR_ERROR:
        case FS_MEDIA_CHANGED:
            term_reason = AUD_RECORDER_REASON_NO_DISK;
            break;
        default:
            term_reason = AUD_RECORDER_REASON_ERROR;
            break;
    }
    
    return term_reason;
}


/*****************************************************************************
 * FUNCTION
 *  aud_recorder_media_close
 * DESCRIPTION
 *  This function is used to close a Media recorder.
 * PARAMETERS
 *  recorder_p      [IN]        Recorder handle.              
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_recorder_media_close(med_aud_recorder_t* recorder_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_media_t* self_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(recorder_p, med_aud_recorder_media_t, itf);
    
    /* Close file handle */
    if (self_p->file_handle >= 0)
    {
        FS_Close(self_p->file_handle);
        self_p->file_handle = -1;
    }

    g_recorder_p = NULL;

    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  _aud_recorder_media_free_buffer
 * DESCRIPTION
 *  This function is used to free working buffer of a Media recorder.
 * PARAMETERS
 *  recorder_p      [IN]        Recorder handle.              
 * RETURNS
 *  
 *****************************************************************************/
static void _aud_recorder_media_free_buffer(med_aud_recorder_t* recorder_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_media_t* self_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(recorder_p, med_aud_recorder_media_t, itf);
    
    /* Free ring buffer */
    if (self_p->ring_buffer_p)
    {
        AUD_RECORDER_FREE_RING_BUF(self_p->ring_buffer_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  _aud_recorder_media_update_header
 * DESCRIPTION
 *  This function is to update the header when end-of-record.
 * PARAMETERS
 *  recorder_p      [IN]        Recorder handle
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
static kal_uint8 _aud_recorder_media_update_header(med_aud_recorder_t* recorder_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_media_t* self_p;
    kal_uint32                len;
    kal_int32                 result;
    kal_uint8*                header_p;
    kal_uint32                header_len; /* 1 byte per unit */
    kal_uint32                data_len;   /* data length in header */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(recorder_p, med_aud_recorder_media_t, itf);
    
    if (self_p->format == MEDIA_WAV ||
        self_p->format == MEDIA_WAV_ALAW ||
        self_p->format == MEDIA_WAV_ULAW ||
        self_p->format == MEDIA_WAV_DVI_ADPCM)
    {
        /* There are 8 bytes file header */
        Media_GetFileHeader(&header_p, &header_len);
        
        data_len = (kal_uint32) * (header_p + 4);
        data_len += (((kal_uint32) * (header_p + 5)) << 8);
        data_len += (((kal_uint32) * (header_p + 6)) << 16);
        data_len += (((kal_uint32) * (header_p + 7)) << 24);
        
        /* Check if the file size is consistent with recorded size */
        result = FS_GetFileSize(self_p->file_handle, &len);
        _AUD_RECORDER_MEDIA_TRACE(result, header_len, len);

        /*
        if (result == FS_NO_ERROR)
        {
            _AUD_RECORDER_MEDIA_TRACE(data_len + 8, self_p->file_offset, len);
            ASSERT(data_len + 8 == self_p->file_offset);
        }
        */
        
        /* Overwrite file header */
        if (header_len > 0)
        {
            FS_Seek(self_p->file_handle, 0, FS_FILE_BEGIN);
            result = FS_Write(self_p->file_handle, header_p, header_len, &len);
            _AUD_RECORDER_MEDIA1_TRACE(result);
            
            if (result != FS_NO_ERROR || len != header_len)
            {
                return MED_RES_FAIL;
            }
        }
        else
        {
            return MED_RES_FAIL;
        }
    }
    else if (self_p->format == MEDIA_AMR || 
             self_p->format == MEDIA_AMR_WB)
    {
        /* Append null data 0x7c if not record anything. 1 byte for 20ms, put 5 bytes here.*/
        if (self_p->file_offset == 0)
        {
            kal_uint8 null_data[5] = {0x7c,0x7c,0x7c,0x7c,0x7c};
            result = FS_Write(self_p->file_handle, &null_data, 5, &len);
            _AUD_RECORDER_MEDIA2_TRACE(result, len);
            
            if (result != FS_NO_ERROR || len != 5)
            {
                return MED_RES_FAIL;
            }
        }
    }

    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  _aud_recorder_media_stop_record
 * DESCRIPTION
 *  This function is to stop record process. We have to guarantee that the speech
 *  state is consistent during a record session. Othewise, we will get assertion
 *  in L1audio.
 * PARAMETERS
 * RETURNS
 *  none
 *****************************************************************************/
static void _aud_recorder_media_stop_record(med_aud_recorder_t* recorder_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_media_t* self_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(recorder_p, med_aud_recorder_media_t, itf);
    
    if (self_p->is_speech_on) /* Start recording in dedicated mode (speech on) */
    {
        if (! L1SP_IsSpeechOn()) /* Speech is being off */
        {
            /* State inconsistent. We have to turn on speech before stopping 
             * the recording (otherwise, we will get assertion). Then, we should
             * restore speech state to off.
             */
            L1SP_Speech_On(self_p->rat_mode);
            Media_Stop();
            L1SP_Speech_Off();
        }
        else
        {
            /* State consistent. Stop the recording directly. */
            Media_Stop();
        }
    }
    else /* Start recording in idle mode (speech off) */
    {
        /* The speech could never be on after starting a recording in idle mode.
         * Hence, we could stop the recording directly.
         */
        Media_Stop();
    }
}


/*****************************************************************************
 * FUNCTION
 *  _aud_recorder_media_terminate
 * DESCRIPTION
 *  This function is to handle the case when there is something wrong during
 *  recording. E.g. reach limit, media error, disk full, ...
 * PARAMETERS
 *  recorder_p       [IN]       Recorder handle
 *  term_reason      [IN]       Terminate reason
 * RETURNS
 *  none
 *****************************************************************************/
static void _aud_recorder_media_terminate(med_aud_recorder_t* recorder_p, med_aud_recorder_reason_t term_reason)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_media_t* self_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(recorder_p, med_aud_recorder_media_t, itf);

    _AUD_RECORDER_MEDIA2_TRACE(term_reason, self_p->file_offset);
    
    /* Stop record process */
    _aud_recorder_media_stop_record(recorder_p);

    /* Update header, free buffer and close the recorder */
    _aud_recorder_media_update_header(recorder_p);
    _aud_recorder_media_free_buffer(recorder_p);
    _aud_recorder_media_close(recorder_p);

    /* Notify MMI the record is terminated */
    if (self_p->cb_fct)
    {
        self_p->cb_fct(recorder_p, term_reason, NULL, self_p->cb_param);
    }

    /* Enter idle state */
    self_p->state = AUD_MEDIA_IDLE;
}


/*****************************************************************************
 * FUNCTION
 *  _aud_recorder_media_write_to_file
 * DESCRIPTION
 *  This function is to read data buffer from L1Audio and write to file system.
 *  Note that since both MED and MED-V may concurrently access to this fucntion,
 *  we have to use a mutex to protect the mutually exclusive section.
 * PARAMETERS
 *  recorder_p       [IN]       Recorder handle.
 *  written_len      [OUT]      The length that has just written.
 * RETURNS
 *  FS_NO_ERROR      Successful.
 *  FS_DISK_FULL     Disk full failure.
 *  Others           Other failure.
 *****************************************************************************/
static med_aud_recorder_reason_t _aud_recorder_media_write_to_file(med_aud_recorder_t* recorder_p, kal_uint32 *written_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_media_t* self_p;
    kal_uint16*               buf_p;
    kal_uint32                buf_len; /* 2 bytes per unit */
    kal_uint32                len;     /* 1 byte per unit */
    kal_int32                 fs_result = FS_NO_ERROR;
    med_aud_recorder_reason_t result = AUD_RECORDER_REASON_OK;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(recorder_p, med_aud_recorder_media_t, itf);

    /* Mutually exclusive section starts */
    kal_take_mutex(g_rec_mutex);

    /* Get read buffer from L1Audio */
    Media_GetReadBuffer(&buf_p, &buf_len);
    
    if (buf_len > 0)
    {

        /* Check if total record data exceeds time or size limit */
        if (_aud_recorder_media_is_reach_limit(recorder_p, buf_len))
        {
            result = AUD_RECORDER_REASON_REACH_SIZE_LIMIT;
        }
        else
        {
            /* Write to file system */
            fs_result = FS_Write(self_p->file_handle,
                                 buf_p,
                                 buf_len * 2,
                                 &len);
            _AUD_RECORDER_MEDIA_TRACE(fs_result, buf_len, len);
            
            /* Update file offset */
            self_p->file_offset += len;
            *written_len = len;

            if(self_p->file_offset/1024 > self_p->size_committed)
            {
            	FS_Commit(self_p->file_handle);
                self_p->size_committed = self_p->file_offset/1024;
            }

            _AUD_RECORDER_MEDIA2_TRACE(self_p->file_offset, self_p->size_committed);
            
            /* Notify L1Audio how many bytes are read */
            Media_ReadDataDone(len >> 1);
        }
    }
    else
    {
        *written_len = 0;
    }

    /* Mutually exclusive section ends */
    kal_give_mutex(g_rec_mutex);

    if(fs_result != FS_NO_ERROR)
    {
        result = _aud_recorder_media_fs_result_to_term_reason(fs_result);
    }

    return result;

}

/*****************************************************************************
 * FUNCTION
 *  _aud_recorder_media_write_to_file_with_error_handle
 * DESCRIPTION
 *  This function is to write data and handle error cases
 * PARAMETERS
 *  media_event_p       [IN]       media event handler
 *
 * RETURNS
 * AUD_RECORDER_REASON_OK : write data correctly
 * !AUD_RECORDER_REASON_OK : wrtie data fail and already terminate
 *****************************************************************************/
static med_aud_recorder_reason_t _aud_recorder_media_write_to_file_with_error_handle(med_aud_recorder_media_event_t* media_event_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_media_t*       self_p;
    kal_uint32                      written_len;
    med_aud_recorder_reason_t       result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    self_p = PTHIS(media_event_p->recorder_p, med_aud_recorder_media_t, itf);

    /* Write buffer data to file system */
    result = _aud_recorder_media_write_to_file(media_event_p->recorder_p, &written_len);

    _AUD_RECORDER_MEDIA2_TRACE(result, written_len);

    if(result != AUD_RECORDER_REASON_OK)
    {
        /* If there is something wrong, we should terminate the record. */
        if (result == AUD_RECORDER_REASON_DISK_FULL || result == AUD_RECORDER_REASON_NO_DISK || result == AUD_RECORDER_REASON_ERROR)
        {
            /* Truncate previously written data */
            if (written_len > 0)
            {
                FS_Seek(self_p->file_handle, (int)-written_len, FS_FILE_CURRENT);
                FS_Truncate(self_p->file_handle);
            }
        }

        /* Terminate the record */
        _aud_recorder_media_terminate(media_event_p->recorder_p,result);
    }

    return result;

}


/*****************************************************************************
 * FUNCTION
 *  _aud_recorder_media_is_reach_limit
 * DESCRIPTION
 *  This function is to check if record has reached size or time limit.
 * PARAMETERS
 *  recorder_p       [IN]       Recorder handle.
 *  buf_len          [IN]       The lenght of record buffer (2 bytes per unit).
 * RETURNS
 *  KAL_TRUE         Reach limit.
 *  KAL_FALSE        Not reach limit yet.
 *****************************************************************************/
static kal_bool _aud_recorder_media_is_reach_limit(med_aud_recorder_t* recorder_p, kal_uint32 buf_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_media_t* self_p;
    kal_uint32                size;
    kal_int32                 result;
#if defined(VM_SUPPORT) && defined(VM_LOG)    
    kal_bool                  is_continue_record = KAL_FALSE;
#endif /* #if defined(VM_SUPPORT) && defined(VM_LOG) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(recorder_p, med_aud_recorder_media_t, itf);
    
    /* Check if total record data exceeds size limit */
    if (self_p->size_limit > 0)
    {
        result = FS_GetFileSize(self_p->file_handle, &size);
        _AUD_RECORDER_MEDIA_TRACE(result, size, self_p->size_limit);

        if ((result == FS_NO_ERROR) && ((size + buf_len * 2) > self_p->size_limit))
        {
        #if defined(VM_SUPPORT) && defined(VM_LOG)
            /* Notify client the recording has reached size limit */
            if (self_p->cb_fct)
            {
                is_continue_record = self_p->cb_fct(recorder_p,
                                                    AUD_RECORDER_REASON_REACH_SIZE_LIMIT,
                                                    &self_p->file_handle,
                                                    self_p->cb_param);

                return (is_continue_record) ? KAL_FALSE : KAL_TRUE;
            }
        #endif /* #if defined(VM_SUPPORT) && defined(VM_LOG) */

            return KAL_TRUE;
        }
    }

    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  _aud_recorder_media_time_limit_hdlr
 * DESCRIPTION
 *  This function is to handle the time limit reached case. We have to read the 
 *  ring buffer twice to make sure all the lasting data are written into file.
 * PARAMETERS
 *  data_p             [IN]       Media event data.
 *  date_len           [IN]       The length of data.
 * RETURNS
 *  none
 *****************************************************************************/
static void _aud_recorder_media_time_limit_hdlr(void* data_p, kal_uint16 date_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_media_event_t* media_event_p = (med_aud_recorder_media_event_t*)data_p;
    med_aud_recorder_media_t*       self_p;
    kal_uint8                       write_loop;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(media_event_p->recorder_p, med_aud_recorder_media_t, itf);
    
    if ((g_recorder_p == media_event_p->recorder_p) &&
        (self_p->time_stamp == media_event_p->time_stamp) &&
        (self_p->state == AUD_MEDIA_RECORD))
    {
        for (write_loop = 0; write_loop < 2; write_loop ++) 
        {
            if(_aud_recorder_media_write_to_file_with_error_handle(media_event_p) != AUD_RECORDER_REASON_OK)
            {
                return ;
            }
        }

        _aud_recorder_media_terminate(media_event_p->recorder_p, AUD_RECORDER_REASON_REACH_TIME_LIMIT);

    }

}

/*****************************************************************************
 * FUNCTION
 *  _aud_recorder_media_read_data_fct
 * DESCRIPTION
 *  This function is to read recorded from L1Audio and write to the file system.
 *  Note that this function may be executed by using MED or MED-V thread (see
 *  _aud_rec_read_data_ind_hdlr).
 * PARAMETERS
 *  data_p             [IN]       Media event data.
 *  date_len           [IN]       The length of data.
 * RETURNS
 *  none
 *****************************************************************************/
static void _aud_recorder_media_read_data_fct(void* data_p, kal_uint16 date_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_media_event_t* media_event_p = (med_aud_recorder_media_event_t*)data_p;
    med_aud_recorder_media_t*       self_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(media_event_p->recorder_p, med_aud_recorder_media_t, itf);
    
    if ((g_recorder_p == media_event_p->recorder_p) &&
        (self_p->time_stamp == media_event_p->time_stamp) &&
        (self_p->state == AUD_MEDIA_RECORD))
    {
        /* Write buffer data to file system */
        _aud_recorder_media_write_to_file_with_error_handle(media_event_p);

    }
}


/*****************************************************************************
 * FUNCTION
 *  _aud_recorder_media_event_callback_hdlr
 * DESCRIPTION
 *  This function is used to handle the callback events from L1Audio.
 * PARAMETERS
 *  data_p             [IN]       Media event data.
 *  date_len           [IN]       The length of data.
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_recorder_media_event_callback_hdlr(void* data_p, kal_uint16 date_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_media_event_t* media_event_p = (med_aud_recorder_media_event_t*)data_p;
    med_aud_recorder_media_t*       self_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(media_event_p->recorder_p, med_aud_recorder_media_t, itf);

    _AUD_RECORDER_MEDIA2_TRACE(media_event_p->event, self_p->state);
    
    if ((g_recorder_p == media_event_p->recorder_p) &&
        (self_p->time_stamp == media_event_p->time_stamp) &&
        (self_p->state == AUD_MEDIA_RECORD))
    {
        switch (media_event_p->event)
        {
            case MEDIA_DATA_NOTIFICATION:
            #if !defined(MED_V_NOT_PRESENT)
                if (self_p->is_low_priority)
                {
                    /* Read data by using MED-V thread */
                    aud_util_proc_in_med_v_ext(MOD_MED,
                                               _aud_recorder_media_read_data_fct,
                                               (void*)media_event_p,
                                               sizeof(med_aud_recorder_media_event_t));
                }
                else
            #endif /* #if !defined(MED_V_NOT_PRESENT) */
                {
                    /* Read data by using MED thread. Note that MED thread will
                     * be blocked during writing data to file system. If this is
                     * not acceptable for performance issues or some other reason,
                     * consider to modify the conditions for g_low_priority_record.
                     */
                    _aud_recorder_media_read_data_fct((void*)media_event_p,
                                                      sizeof(med_aud_recorder_media_event_t));
                }
                break;

            case MEDIA_ERROR:
                /* Terminate the record */
                _aud_recorder_media_terminate(media_event_p->recorder_p, AUD_RECORDER_REASON_ERROR);
                break;

            case MEDIA_STOP_TIME_UP:
            {   
            #if !defined(MED_V_NOT_PRESENT)
                if (self_p->is_low_priority)
                {
                    /* Read data by using MED-V thread */
                    aud_util_proc_in_med_v_ext(MOD_MED,
                                               _aud_recorder_media_time_limit_hdlr,
                                               (void*)media_event_p,
                                               sizeof(med_aud_recorder_media_event_t));
                }
                else
            #endif /* #if !defined(MED_V_NOT_PRESENT) */
                {
                    _aud_recorder_media_time_limit_hdlr((void*)media_event_p,
                                                         sizeof(med_aud_recorder_media_event_t));
                }
                break;
            }

            default:
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  _aud_recorder_media_event_callback_fct
 * DESCRIPTION
 *  This function will be called by L1Audio when there is an event arisen 
 *  during recording. A read data indicator MEDIA_DATA_NOTIFICATION will be
 *  arisen when the recorded data in ring buffer is ready to be read back. We
 *  have to write the recorded data to file system by using MED/MED-V thread
 *  depend on if it's a low priority recording.
 *  
 * PARAMETERS
 *  event       [IN]        Callback event.
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_recorder_media_event_callback_fct(Media_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_media_event_t media_event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    _AUD_RECORDER_MEDIA2_TRACE(event, g_recorder_p);
    
    if ((event == MEDIA_TERMINATED) || (g_recorder_p == NULL))
    {
        return;
    }
    
    media_event.recorder_p = g_recorder_p;
    media_event.event      = event;
    media_event.time_stamp = PTHIS(g_recorder_p, med_aud_recorder_media_t, itf)->time_stamp;
    
    /* Process the event in MED thread */
    aud_util_proc_in_med_ext(MOD_L1SP,
                             _aud_recorder_media_event_callback_hdlr,
                             (void*)&media_event,
                             sizeof(med_aud_recorder_media_event_t));
}


/*****************************************************************************
 * FUNCTION
 *  _aud_recorder_media_get_record_format
 * DESCRIPTION
 *  This function is to get record format. Note that the record format may
 *  be overwritten when the record is started.
 * PARAMETERS
 *  file_name       [IN]    The file name to be recorded to.
 *  input_format    [IN]    The record format specified by MMI.
 * RETURNS
 *  media_format_enum
 *****************************************************************************/
static kal_int16 _aud_recorder_media_get_record_format(kal_wchar* file_name, kal_uint8 input_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 media_type;
    kal_int16 record_format;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Get file foramt per file extension */
    media_type = med_get_media_type(file_name);

    /* Remapping media format to record format */
    switch (media_type)
    {
    #ifdef __VM_CODEC_SUPPORT__
        case MED_TYPE_GSM_EFR:       record_format = MEDIA_GSM_EFR;       break;
        case MED_TYPE_VR:            record_format = MEDIA_VR;            break;
    #endif /*__VM_CODEC_SUPPORT__*/
        case MED_TYPE_AMR:           record_format = MEDIA_AMR;           break;
    #if defined(AMRWB_ENCODE)
        case MED_TYPE_AMR_WB:        record_format = MEDIA_AMR_WB;        break;
    #endif
    #if defined(__DAF_ENCODE__)
        case MED_TYPE_DAF:           record_format = MEDIA_DAF;           break;
    #endif
        case MED_TYPE_PCM_8K:        record_format = MEDIA_PCM_8K;        break;
        case MED_TYPE_DVI_ADPCM:     record_format = MEDIA_DVI_ADPCM;     break;
        case MED_TYPE_WAV:           record_format = MEDIA_WAV;           break;
    #if defined(__VORBIS_ENCODE__)
        case MED_TYPE_VORBIS:        record_format = MEDIA_VORBIS;        break;
    #endif
        default:                     record_format = MEDIA_FORMAT_NONE;   break;
    }   

    /* Overwrite format */
    if (record_format == MEDIA_FORMAT_NONE)
    {
        /* Use input format instead */
        if (input_format != (kal_uint8)MEDIA_FORMAT_NONE)
        {
            record_format = (kal_int16)input_format;
        }
    }
    else if (record_format == MEDIA_WAV)
    {
        if (input_format != MEDIA_WAV)
        {
            record_format = MEDIA_WAV_DVI_ADPCM;
        }
    }
#ifdef __VM_CODEC_SUPPORT__
    else if (record_format == MEDIA_GSM_EFR)
    {
        if (input_format == MEDIA_GSM_FR)
        {
            record_format = MEDIA_GSM_FR;
        }
    }
#endif /*__VM_CODEC_SUPPORT__*/

    return record_format;
}


/*****************************************************************************
 * FUNCTION
 *  aud_recorder_media_open
 * DESCRIPTION
 *  This function is used to open an Media recorder.
 * PARAMETERS
 *  recorder_p      [IN]        Recorder handle.
 *  cfg_p           [IN]        Recorder configuration.  
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_recorder_media_open(med_aud_recorder_t* recorder_p, med_aud_recorder_cfg_t* cfg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_media_t* self_p;
    kal_int32                 result;
    kal_uint32                file_flag = FS_READ_WRITE | FS_OPEN_SHARED | FS_NOBUSY_CHECK_MODE; /* Disable Busy Check Mode For Record */
    kal_uint32                len;
    kal_uint8*                header_p;
    kal_uint16                header_size;
    kal_bool                  is_file_empty = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(recorder_p, med_aud_recorder_media_t, itf);
    
    self_p->file_handle = FS_Open(cfg_p->file_name, file_flag);
    
    if (self_p->file_handle >= 0) /* File already exists */
    {
        /* Check if the size of file is 0 because MMI may create the file to be recorded to in advance */
        FS_GetFileSize(self_p->file_handle, &len);
        
        if (len == 0)
        {
            /* Turn on file-empty flag if file size is 0 */
            is_file_empty = KAL_TRUE;
        }
        
    }
    else /* File does not exist */
    {
        /* Create a new file */
        self_p->file_handle = FS_Open(cfg_p->file_name, FS_CREATE | file_flag);

        is_file_empty = KAL_TRUE;

    }

    _AUD_RECORDER_MEDIA2_TRACE(self_p->file_handle, is_file_empty);
    
    if (self_p->file_handle >= 0)
    {
        /* Get record format */
        self_p->format = _aud_recorder_media_get_record_format(cfg_p->file_name, cfg_p->format);
        _AUD_RECORDER_MEDIA2_TRACE(self_p->format, cfg_p->format);

        if (self_p->format == MEDIA_FORMAT_NONE)
        {
            return MED_RES_INVALID_FORMAT;
        }
        
        /* Add header for AMR/AWB when recording to an empty file */
        if (self_p->format == MEDIA_AMR ||
            self_p->format == MEDIA_AMR_WB)
        {
            if (is_file_empty)
            {
                if (self_p->format == MEDIA_AMR)
                {
                    header_p = (kal_uint8*) AMR_HEADER;
                    header_size = strlen(AMR_HEADER);
                }
                else
                {
                    header_p = (kal_uint8*) AWB_HEADER;
                    header_size = strlen(AWB_HEADER);
                }

                result = FS_Write(self_p->file_handle, header_p, header_size, &len);
                _AUD_RECORDER_MEDIA_TRACE(result, header_size, len);

                if ((result != FS_NO_ERROR) || (len != header_size))
                {
                    med_aud_recorder_reason_t term_result ;

                    FS_Close(self_p->file_handle);
                    self_p->file_handle = -1;

                    term_result = _aud_recorder_media_fs_result_to_term_reason(result);
                    return _aud_recorder_media_term_reason_to_med(term_result);
                }
            }
        }
    }
    else
    {
        switch (self_p->file_handle)
        {
            case FS_WRITE_PROTECTION:
                return MED_RES_WRITE_PROTECTION;
            case FS_DISK_FULL:
                return MED_RES_DISC_FULL;
            default:
                return MED_RES_OPEN_FILE_FAIL;
        }
    }

    /* Store current recorder handle */
    g_recorder_p = recorder_p;
    
    /* Create mutex if required */
    if (g_rec_mutex == 0)
    {
        g_rec_mutex = kal_create_mutex("aud_record_mutex");
    }

    _AUD_RECORDER_MEDIA2_TRACE(recorder_p, self_p->format);
    
    /*------------------------ Setup private data ---------------------------*/
    self_p->state           = AUD_MEDIA_IDLE;
    self_p->time_limit      = 0;
    self_p->size_limit      = 0;
    self_p->quality         = cfg_p->quality;
    self_p->is_low_priority = cfg_p->is_low_priority;
    self_p->is_fm_record    = cfg_p->is_fm_record;
    self_p->cb_fct          = cfg_p->cb_fct;
    self_p->cb_param        = cfg_p->cb_param;
    
    _AUD_RECORDER_MEDIA_TRACE(self_p->is_low_priority, self_p->is_fm_record, self_p->quality);
    
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  aud_recorder_media_record
 * DESCRIPTION
 *  This function is used to start Media record.
 * PARAMETERS
 *  recorder_p      [IN]        Recorder handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_recorder_media_record(med_aud_recorder_t* recorder_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_media_t* self_p;
    kal_uint32                len;
    Media_Format              media_format; /* L1audio format */
    void*                     param_p = NULL;
    Media_Record_File_Info    append_info;
    Media_Status              result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(recorder_p, med_aud_recorder_media_t, itf);

    _AUD_RECORDER_MEDIA2_TRACE(self_p->state, self_p->format);

    /* Directly return if the recorder is not in idle state */
    if (self_p->state != AUD_MEDIA_IDLE)
    {
        return MED_RES_FAIL;
    }
    
    /*---------------------- Allocate buffers ------------------------*/
    /* Allocate ring buffer */
#if __VM_CODEC_SUPPORT__
    /* enlarge the ring buffer to 12K for VM record case to avoid data dropping */
    if(self_p->format == MEDIA_FORMAT_GSM_FR ||
       self_p->format == MEDIA_FORMAT_GSM_HR ||
       self_p->format == MEDIA_FORMAT_GSM_EFR )
    {
        aud_util_alloc_ring_buffer_ext(AUD_MED_VM_EXT_MEM_SIZE, &self_p->ring_buffer_p);
        Media_SetBuffer(self_p->ring_buffer_p, AUD_MED_VM_EXT_MEM_SIZE >> 1);
    }
    else
#endif
    {
        aud_util_alloc_ring_buffer_ext(AUD_RECORDER_RING_BUF_SIZE, &self_p->ring_buffer_p);
        Media_SetBuffer(self_p->ring_buffer_p, AUD_RECORDER_RING_BUF_SIZE >> 1);
    }

    /*-------------- Determine media format & parameter -------------------*/
    if (self_p->format == MEDIA_WAV_DVI_ADPCM)
    {
    #if defined(__FMRADIO_I2S_SUPPORT__)
        if (self_p->is_fm_record)
        {
            /* We don't support ADPCM 16K format when recording FM via I2S.
             * L1audio will auto detect the sampling rate (could be 32K, 44K or 48K).
             */
            media_format = MEDIA_FORMAT_WAV_DVI_ADPCM;
        }
        else
    #endif /* __FMRADIO_I2S_SUPPORT__ */
        {
            /* Sound recorder could still support ADPCM 16K format */
            if((self_p->quality != AUD_REC_QUALITY_LOW) && (self_p->is_speech_on != KAL_TRUE))
            {
                /* Can not record 16K wave while in call*/
                media_format = MEDIA_FORMAT_WAV_DVI_ADPCM_16K;
            }
            else
            {
                media_format = MEDIA_FORMAT_WAV_DVI_ADPCM;
            }
        }
    }
#if defined(AMRWB_ENCODE)
    else if (self_p->format == MEDIA_AMR_WB)
    {
        media_format = MEDIA_FORMAT_AMR_WB;
    }
#endif /*AMRWB_ENCODE*/
#if defined(__DAF_ENCODE__)
    else if (self_p->format == MEDIA_DAF)
    {
        media_format = MEDIA_FORMAT_DAF;
    }
#endif /* __DAF_ENCODE__ */
    else
    {
        media_format = (Media_Format)self_p->format;
    }

     param_p = (void*) aud_rec_get_record_quality_param((Media_Format)self_p->format,(aud_rec_quality_enum)self_p->quality);
    
    /*------------------------- Check if it is appendable ------------------*/
    if ((FS_GetFileSize(self_p->file_handle, &len) == FS_NO_ERROR) && (len > 0))
    {
        FS_Seek(self_p->file_handle, (int)0, FS_FILE_BEGIN);
        result = Media_RecordAppendable(media_format, self_p->file_handle, &append_info);
        FS_Seek(self_p->file_handle, (int)0, FS_FILE_END);

        if (result != MEDIA_SUCCESS)
        {
            goto media_record_failed;
        }

        if (self_p->format == MEDIA_WAV_DVI_ADPCM || 
            self_p->format == MEDIA_WAV)
        {
            /* Use append info as parameters */
            param_p = (void*)&append_info;
        }
    }
    
    /*------------------------- Start recording ----------------------------*/
    /* Set record buffer callback threshold */
    Media_SetRBThreshold(AUD_RECORDER_BUFFER_THRESHOLD);
    
    /* Begin to record */
    if(self_p->time_limit >0 )
    {
        Media_SetRecordedStopTime(self_p->time_limit * 1000);
    }
    result = Media_Record(media_format, _aud_recorder_media_event_callback_fct, param_p);

    if (result == MEDIA_SUCCESS)
    {
        /* Enter AUD_MEDIA_RECORD state */
        self_p->state = AUD_MEDIA_RECORD;
    }
    else
    {
        goto media_record_failed;
    }
    
    /* Update file offset */
    if ((FS_GetFileSize(self_p->file_handle, &len) == FS_NO_ERROR) && (len > 0))
    {
        self_p->file_offset = len;
    }
    else
    {
        self_p->file_offset = 0;
    }

    self_p->size_committed = 0;

    /* Seek to end of file for appending data */
    FS_Seek(self_p->file_handle, 0, FS_FILE_END);

    return aud_get_res(result);

media_record_failed:

    /* Free buffer */
    _aud_recorder_media_free_buffer(recorder_p);
    
    return aud_get_res(result);
}


/*****************************************************************************
 * FUNCTION
 *  aud_recorder_media_stop
 * DESCRIPTION
 *  This function is used to stop Media record.
 * PARAMETERS
 *  recorder_p      [IN]        Recorder handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_recorder_media_stop(med_aud_recorder_t* recorder_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_media_t* self_p;
    kal_uint32                written_len;
    kal_uint8                 write_loop;
    med_aud_recorder_reason_t result;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(recorder_p, med_aud_recorder_media_t, itf);

    /* Directly return if the recorder is already in idle state */
    if (self_p->state == AUD_MEDIA_IDLE)
    {
        return MED_RES_OK;
    }
    
    /* Stop record process */
    _aud_recorder_media_stop_record(recorder_p);

    /* Write the remaining data to file system. Note that we have to consider the
     * case that the recording buffer crosses the ring buffer boundary. Hence, we
     * should write buffer data to file system twice when stopping a record. 
     */
    for (write_loop = 0; write_loop < 2; write_loop ++)
    {
        result = _aud_recorder_media_write_to_file(recorder_p, &written_len);

        if (result != AUD_RECORDER_REASON_OK)
        {
            break;
        }
    }

    /* Update header */
    _aud_recorder_media_update_header(recorder_p);

    /* Free buffer */
    _aud_recorder_media_free_buffer(recorder_p);
    
    /* enter AUD_MEDIA_IDLE state */
    self_p->state = AUD_MEDIA_IDLE;

    return _aud_recorder_media_term_reason_to_med(result);
}


/*****************************************************************************
 * FUNCTION
 *  aud_recorder_media_pause
 * DESCRIPTION
 *  This function is used to pause Media playback.
 * PARAMETERS
 *  recorder_p      [IN]        Recorder handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_recorder_media_pause(med_aud_recorder_t* recorder_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_media_t* self_p;
    kal_int32                 drv_result;
    kal_uint32                written_len;
    med_aud_recorder_reason_t result;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(recorder_p, med_aud_recorder_media_t, itf);

    /* Directly return if the recorder is not in record state */
    if (self_p->state != AUD_MEDIA_RECORD)
    {
        return MED_RES_FAIL;
    }
    
    /* Pause record */
    drv_result = Media_Pause();
    _AUD_RECORDER_MEDIA1_TRACE(drv_result);

    /* Write remaining data to file */
    result = _aud_recorder_media_write_to_file(recorder_p, &written_len);
    _AUD_RECORDER_MEDIA1_TRACE(result);


    if (result == AUD_RECORDER_REASON_OK)
    {
        /* Enter record-paused state */
        self_p->state = AUD_MEDIA_RECORD_PAUSED;
    }
    else
    {
        /* Terminate the record if failed to write data to file system */
        _aud_recorder_media_terminate(recorder_p, result);
    }

    return _aud_recorder_media_term_reason_to_med(result);

}


/*****************************************************************************
 * FUNCTION
 *  aud_recorder_media_resume
 * DESCRIPTION
 *  This function is used to resume Media playback.
 * PARAMETERS
 *  recorder_p      [IN]        Recorder handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_recorder_media_resume(med_aud_recorder_t* recorder_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_media_t* self_p;
    kal_int32                 drv_result;
    kal_int32                 med_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(recorder_p, med_aud_recorder_media_t, itf);

    /* Directly return if the recorder is not in record-paused state */
    if (self_p->state != AUD_MEDIA_RECORD_PAUSED)
    {
        return MED_RES_FAIL;
    }
    
    /* Resume record */
    drv_result = Media_Resume();
    _AUD_RECORDER_MEDIA1_TRACE(drv_result);

    med_result = aud_get_res(drv_result);

    if (med_result == MED_RES_OK)
    {
        /* Enter record state */
        self_p->state = AUD_MEDIA_RECORD;
    }
    else
    {
        /* Terminate the record */
        _aud_recorder_media_terminate(recorder_p, AUD_RECORDER_REASON_ERROR);
    }

    return med_result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_recorder_media_set
 * DESCRIPTION
 *  This function is used to set parameters to a Media recorder.
 * PARAMETERS
 *  recorder_p      [IN]        Recorder handle.
 *  set_type        [IN]        Set command.
 *  data_p          [IN]        The data relative to the command.
 *  date_len        [IN]        The length of the data.
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_recorder_media_set(med_aud_recorder_t*    recorder_p,
                                         med_aud_recorder_set_t set_type,
                                         void*                  data_p,
                                         kal_uint32             data_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_media_t* self_p;
    kal_int32                 result = MED_RES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(recorder_p, med_aud_recorder_media_t, itf);

    _AUD_RECORDER_MEDIA2_TRACE(set_type, (kal_uint32)data_p);
    
    switch (set_type)
    {
        case AUD_RECORDER_SET_SIZE_LIMIT:
            self_p->size_limit = (kal_uint32)data_p;
            break;
            
        case AUD_RECORDER_SET_TIME_LIMIT:
            self_p->time_limit = (kal_uint32)data_p;
            break;

        case AUD_RECORDER_SET_SPEECH_PARAM:
        {
            med_aud_recorder_speech_param_t* speech_param_p = (med_aud_recorder_speech_param_t*)data_p;
            
            self_p->is_speech_on = speech_param_p->is_speech_on;
            self_p->rat_mode = speech_param_p->rat_mode;
            break;
        }
            
        /* Unsupported commands */
        default:
            result = MED_RES_UNSUPPORTED_OPERATION;
            break;
    }
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_recorder_media_get
 * DESCRIPTION
 *  This function is used to get parameters from a Media recorder.
 * PARAMETERS
 *  recorder_p      [IN]        Recorder handle.
 *  get_type        [IN]        Get command.
 *  data_p          [OUT]       The data relative to the command.
 *  data_len        [IN]        Indicats the length of the data buffer.
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_recorder_media_get(med_aud_recorder_t*    recorder_p,
                                         med_aud_recorder_get_t get_type,
                                         void*                  data_p,
                                         kal_uint32             data_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(recorder_p != NULL && data_p != NULL);
    
    switch (get_type)
    {
        case AUD_RECORDER_GET_RECORD_TIME:
        {
            if (data_len >= sizeof(kal_uint32))
            {
                *((kal_uint32*)data_p) = Media_GetRecordedTime();
            }
            
            break;
        }

    #ifdef __HD_RECORD__
        case AUD_RECORDER_GET_IS_FM_RECORD:
        {
            med_aud_recorder_media_t* self_p;
            self_p = PTHIS(recorder_p, med_aud_recorder_media_t, itf);
            *((kal_bool*)data_p) = self_p->is_fm_record;
            result = MED_RES_OK;
            break;
        }
    #endif 
 
        /* Unsupported commands */
        default:
            result = MED_RES_UNSUPPORTED_OPERATION;
            break;
    }

    _AUD_RECORDER_MEDIA_TRACE(get_type, result, *((kal_uint32*)data_p));
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_recorder_media_destroy
 * DESCRIPTION
 *  This function is used to destroy a Media recorder. Once called, all the 
 *  allocated interfaces of the recorder will be freed.
 * PARAMETERS
 *  recorder_p      [IN]        Recorder handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_recorder_media_destroy(med_aud_recorder_t* recorder_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_media_t* self_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(recorder_p, med_aud_recorder_media_t, itf);
    
    AUD_RECORDER_FREE_AUD_MEM(self_p);
    
    return MED_RES_OK;
}

#endif /* __MTK_TARGET__ && __MED_AUD_REC_MOD__ */

/*-----------------------------------------------------------------------------
                    public functions
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  aud_recorder_media_construct
 * DESCRIPTION
 *  This function is used to construct a Media Recorder.
 * PARAMETERS
 *  void
 * RETURNS
 *  Recorder handle.
 *****************************************************************************/
med_aud_recorder_t* aud_recorder_media_construct(void)
{
#if defined(__MTK_TARGET__) && defined(__MED_AUD_REC_MOD__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_media_t* self_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = (med_aud_recorder_media_t*) med_alloc_aud_mem(sizeof(med_aud_recorder_media_t));
    MED_ASSERT(self_p != NULL);

    kal_mem_set(self_p, 0, sizeof(*self_p));

    self_p->itf.open     = _aud_recorder_media_open;
    self_p->itf.close    = _aud_recorder_media_close;
    self_p->itf.record   = _aud_recorder_media_record;
    self_p->itf.stop     = _aud_recorder_media_stop;
    self_p->itf.pause    = _aud_recorder_media_pause;
    self_p->itf.resume   = _aud_recorder_media_resume;
    self_p->itf.set      = _aud_recorder_media_set;
    self_p->itf.get      = _aud_recorder_media_get;
    self_p->itf.destroy  = _aud_recorder_media_destroy;

    kal_get_time(&self_p->time_stamp);
    
    return &self_p->itf;
#else
    return NULL;
#endif /* __MTK_TARGET__ && __MED_AUD_REC_MOD__ */
}

#ifdef __KARAOKE_SUPPORT__

STFSAL fmedKaraoke;
kal_uint16 *Karaoke_Buffer = NULL;	
kal_bool g_karaoke_state=KAL_FALSE;
kal_bool g_karaoke_mono=KAL_FALSE;//wxw  

#ifdef  __KARAOKE_NEED_KEEP_SRC_PATH__
#define FILE_PATH_MAX_LEN (259)

kal_wchar src_path[FILE_PATH_MAX_LEN+1+1]={0};
#endif

void _aud_recorder_karaoke_callback(Media_Event event);
void _aud_recorder_karaoke_write_file(Media_Event event);
kal_bool _aud_recorder_karaoke_open(void);
void _aud_recorder_karaoke_setchannel(kal_uint8 channel_type);
void _aud_recorder_karaoke_setmode(kal_bool mode);
void _aud_recorder_karaoke_record(void);
void _aud_recorder_karaoke_close(void);
void _aud_recorder_karaoke_stop();


#ifdef  __KARAOKE_NEED_KEEP_SRC_PATH__
void _aud_recorder_karaoke_keep_src_path(kal_wchar* file_path)
{
    memcpy((kal_char*)src_path,(kal_char*)file_path,sizeof(kal_wchar)*(FILE_PATH_MAX_LEN+1+1));
}
#endif

void _aud_recorder_karaoke_callback(Media_Event event)
{
   
	
    aud_send_in_proc_call_req(MOD_L1SP, _aud_recorder_karaoke_write_file, (Media_Event)event, NULL);
	
   
}

void _aud_recorder_karaoke_write_file(Media_Event event)
{
    kal_uint16* pwBuf;
    kal_uint32 uBufLenInTwoByteWord;

	if(g_karaoke_state==KAL_FALSE)
			return;
  
    switch (event){
        case MEDIA_TERMINATED:
            kal_prompt_trace(MOD_L1SP, "record_callback->MEDIA_TERMINATED");                          
            break;
        case MEDIA_DATA_NOTIFICATION:
        {
			FSAL_Status ret=FSAL_OK;
            Media_GetReadBuffer(&pwBuf, &uBufLenInTwoByteWord);
            Media_ReadDataDone(uBufLenInTwoByteWord);

            ret = FSAL_Write( &fmedKaraoke, (kal_uint8 *) pwBuf, sizeof(kal_int16)* uBufLenInTwoByteWord); 
			if(ret != FSAL_OK)
			{
				_aud_recorder_karaoke_stop();
				aud_send_audio_play_finish_ind((kal_uint8)AUD_RECORDER_REASON_DISK_FULL, aud_context_p->identifier);
				aud_stop_unfinished_audio();
			}
            
            kal_prompt_trace(MOD_L1SP, "uBufLenInTwoByteWord = %d, ret = %d", uBufLenInTwoByteWord,ret);
            break;
        }
    }
}


kal_bool _aud_recorder_karaoke_open(void)
{
	kal_prompt_trace(MOD_ENG, "[Karaoke]  open record file : %s", g_record_file_name);
					   
	if (FSAL_OK != FSAL_Open(&fmedKaraoke, g_record_file_name, FSAL_WRITE))
	{
		kal_prompt_trace(MOD_ENG, "[pcmdump] Cannot open record file : %s", g_record_file_name);
		return KAL_FALSE;
	}
	else
	{
		return KAL_TRUE;
	}
	kal_prompt_trace(MOD_ENG,"[karaoke]_aud_recorder_karaoke_open");
}

void _aud_recorder_karaoke_setchannel(kal_uint8 channel_type)
{
	Media_SetKaraRecMixChannel(channel_type);

}

void _aud_recorder_karaoke_setmode(kal_bool mode)
{
	Media_SetKaraoke(mode);
}

void _aud_record_karaoke_set_digigain(kal_uint16 numer,kal_uint16 denom)
{

	//Media_set_karaoke_digitalgain(numer,denom);


}
void _aud_recorder_karaoke_record(void)
{
	//kal_uint16* 				  ring_buffer_p;   /* Ring buffer */
	kal_uint32 sr=0;
	if(g_karaoke_state==KAL_TRUE)
		return;

	if(_aud_recorder_karaoke_open()==KAL_FALSE)
		return;
	
	//_aud_recorder_karaoke_setchannel(2);
	_aud_record_karaoke_set_digigain(5,8);
	kal_prompt_trace(MOD_ENG,"[karaoke]_aud_recorder_karaoke_record");

	aud_util_alloc_ring_buffer_ext(AUD_RING_BUFFER_SIZE<<1, &Karaoke_Buffer);
	Media_SetBuffer(Karaoke_Buffer, AUD_RING_BUFFER_SIZE );
	
	Media_SetRBThreshold(400); 
	sr = Media_GetSampleRate();
	if(sr < 16000)
		Media_Record(MEDIA_FORMAT_WAV, _aud_recorder_karaoke_callback,NULL); 
	else
	    Media_Record(MEDIA_FORMAT_WAV_16K, _aud_recorder_karaoke_callback,NULL); 
	kal_prompt_trace(MOD_ENG,"karaoke_record state:%d",g_karaoke_state);
	g_karaoke_state=KAL_TRUE;

}

void _aud_recorder_karaoke_close(void)
{

	if (Karaoke_Buffer)
	{
		AUD_RECORDER_FREE_RING_BUF(Karaoke_Buffer);
	}
	if(g_karaoke_state==KAL_FALSE)
		return;
	g_karaoke_state=KAL_FALSE;
	kal_prompt_trace(MOD_ENG,"karaoke_close state:%d",g_karaoke_state);

}

void _aud_recorder_karaoke_stop()
{
	
	
		kal_uint32				  len;
		kal_int32				 result;
		kal_uint8*				 header_p;
		kal_uint32				 header_len; /* 1 byte per unit */
		kal_uint32				 data_len;	 /* data length in header */
		kal_prompt_trace(MOD_ENG, "Autorec: Karaoke_Stop state:%d",g_karaoke_state);
		if(g_karaoke_state==KAL_FALSE)
			return;
		Media_Stop();//stop record audio
		
		Media_GetFileHeader(&header_p, &header_len);
			
		data_len = (kal_uint32) * (header_p + 4);
		data_len += (((kal_uint32) * (header_p + 5)) << 8);
		data_len += (((kal_uint32) * (header_p + 6)) << 16);
		data_len += (((kal_uint32) * (header_p + 7)) << 24);
			
		/* Check if the file size is consistent with recorded size */
		result = FSAL_GetFileSize(&fmedKaraoke, &len);
		   
		FSAL_Seek(&fmedKaraoke, 0);
		result = FSAL_Write(&fmedKaraoke, header_p, header_len );	
		
        #ifdef  __KARAOKE_NEED_KEEP_SRC_PATH__
		FSAL_Seek(&fmedKaraoke, len);
		result = FSAL_Write(&fmedKaraoke, "SRC ", 4);
		result = FSAL_Write(&fmedKaraoke, "0802", 4);
		result = FSAL_Write(&fmedKaraoke, (kal_char*)src_path, sizeof(kal_wchar)*(FILE_PATH_MAX_LEN+1));
        #endif
	    FSAL_Close( &fmedKaraoke ); 
	
		
	  // return;	 
	
	_aud_recorder_karaoke_close();


}

#endif  /*#if defined(__KARAOKE_SUPPORT__)*/
#endif /* MED_NOT_PRESENT */ 

