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
 *   aud_record.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file implements record functions.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

/*****************************************************************************
 * includes
 *****************************************************************************/
//#include "kal_release.h"
#include "kal_trace.h"
//#include "stack_common.h"
//#include "stack_msgs.h"
#include "app_ltlcom.h"         /* Task message communiction */
//#include "syscomp_config.h"
//#include "task_config.h"        /* Task creation */
//#include "stacklib.h"           /* Basic type for dll, evshed, stacktimer */
//#include "event_shed.h"         /* Event scheduler */
//#include "stack_timer.h"        /* Stack timer */
//#include "app_buff_alloc.h"

/* global includes */
#include "l1audio.h"
//#include "device.h"
//#include "fat_fs.h"
//#include "nvram_enums.h"
//#include "nvram_struct.h"
//#include "nvram_user_defs.h"
//#include "nvram_data_items.h"
//#include "custom_nvram_editor_data_item.h"
#include "custom_equipment.h"

/* local includes */
#include "med_global.h"
//#include "med_status.h"
#include "aud_defs.h"
#include "med_struct.h"
//#include "med_v_struct.h"
//#include "med_api.h"
#include "med_context.h"
#include "med_main.h"
#include "aud_main.h"
#include "med_utility.h"
#include "aud_recorder.h"
#include "kal_general_types.h"

#if defined(__MED_VID_DEC_MOD__)
#include "vid_main.h"
#endif /* defined(__MED_VID_DEC_MOD__) */

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif

#if defined(__MED_AUD_REC_MOD__)

/*-----------------------------------------------------------------------------
                    macros, defines, typedefs, enums
-----------------------------------------------------------------------------*/
#define _AUD_MODULE_RECORD_TRACE(x)    AUD_MODULE_RECORD_TRACE(x, __LINE__)
#define AUD_RECORD_MEM_MARGIN                (512)

/*-----------------------------------------------------------------------------
                    data declaraions
 ----------------------------------------------------------------------------*/
kal_bool g_is_paused_by_speech_evt = KAL_FALSE;

/*-----------------------------------------------------------------------------
                    function prototypes
 ----------------------------------------------------------------------------*/
static kal_int32 _aud_rec_recorder_close(void);
#ifdef __MED_VCALL_MOD__
static void aud_rec_vcall_speech_on(void);
static void aud_rec_vcall_speech_off(void);
#endif /*__MED_VCALL_MOD__*/


/*-----------------------------------------------------------------------------
                    private function declarations
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  _aud_rec_recorder_event_hdlr
 * DESCRIPTION
 *  This function is to handle recorder event when the record is termianted.
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
static kal_bool _aud_rec_recorder_event_hdlr(med_aud_recorder_t*       recorder_p,
                                             med_aud_recorder_reason_t reason,
                                             kal_int32*                file_handle_p,
                                             void*                     param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 term_reason;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Close the recorder */
    _aud_rec_recorder_close();

    /* Enter idle state */
    aud_enter_state(AUD_MEDIA_IDLE);
    
    /* Notify MMI the record is terminated */
    switch (reason)
    {
        case AUD_RECORDER_REASON_REACH_SIZE_LIMIT: /* Reach size limit */
        case AUD_RECORDER_REASON_REACH_TIME_LIMIT: /* Reach time limit */
            term_reason = MED_RES_OK;
            break;
        case AUD_RECORDER_REASON_DISK_FULL:        /* Disk full */
            term_reason = MED_RES_DISC_FULL;
            break;
        case AUD_RECORDER_REASON_NO_DISK:          /* No disk */
            term_reason = MED_RES_NO_DISC;
            break;
        case AUD_RECORDER_REASON_ERROR:            /* Something wrong */
        default:
            term_reason = MED_RES_FAIL;
            break;
    }
    
    aud_send_media_record_finish_ind(term_reason);
    
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  _aud_rec_recorder_open
 * DESCRIPTION
 *  This function is to open a recorder handle.
 * PARAMETERS
 * file_name        [IN]      File name to be recorded to.
 * format           [IN]      Record format specified by MMI.
 * quality          [IN]      Record quality.
 * is_low_priority  [IN]      Indicate if it's a low-priority record.
 * is_speech_on     [IN]      Indicate if speech is being on.
 * is_fm_record     [IN]      Indicate if it's FM recording.
 * recorder_pp      [OUT]     Recorder handle.
 * RETURNS
 *  MED_RES_OK                Successful.
 *  Others                    Failed.
 *****************************************************************************/
static kal_int32 _aud_rec_recorder_open(kal_wchar*           file_name,
                                        kal_uint8            format,
                                        kal_uint8            quality,
                                        kal_bool             is_low_priority,
                                        kal_bool             is_fm_record,
                                        med_aud_recorder_t** recorder_pp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_cfg_t recorder_cfg;
    med_aud_recorder_t*    recorder_p = NULL;
    kal_int32              result = MED_RES_FAIL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    recorder_p = aud_recorder_media_construct();
#else
    recorder_p = aud_recorder_modis_construct();
#endif  /*__MTK_TARGET__*/
    
    if (recorder_p != NULL)
    {    
        /* Configure the recorder */
        recorder_cfg.file_name       = file_name;
        recorder_cfg.format          = format;
        recorder_cfg.quality         = quality;
        recorder_cfg.is_low_priority = is_low_priority;
        recorder_cfg.is_fm_record    = is_fm_record;
        recorder_cfg.cb_fct          = _aud_rec_recorder_event_hdlr;
        recorder_cfg.cb_param        = NULL;

        /* Open a recorder */
        result = recorder_p->open(recorder_p, &recorder_cfg);
        _AUD_MODULE_RECORD_TRACE(result);

        /* Remember to destroy the recorder if failed to open */
        if (result != MED_RES_OK)
        {
            recorder_p->destroy(recorder_p);
            recorder_p = NULL;
        }
    }

    /* Copy out recorder handle */
    *recorder_pp = recorder_p;
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  _aud_rec_recorder_close
 * DESCRIPTION
 *  This function is to close a recorder handle and restore input source.
 * PARAMETERS
 *  void
 * RETURNS
 *  MED_RES_OK      Successful.
 *  Others          Failed.
 *****************************************************************************/
static kal_int32 _aud_rec_recorder_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    if (aud_context_p->recorder_p)
    {
        /* Close the recorder */
        aud_context_p->recorder_p->close(aud_context_p->recorder_p);
        aud_context_p->recorder_p->destroy(aud_context_p->recorder_p);
        aud_context_p->recorder_p = NULL;

        /* Restore input source */
        L1SP_SetInputSource(aud_context_p->input_device);
    }

    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  _aud_rec_recorder_start
 * DESCRIPTION
 *  This function is to start a record.
 * PARAMETERS
 *  void
 * RETURNS
 *  MED_RES_OK      Successful.
 *  Others          Failed.
 *****************************************************************************/
static kal_int32 _aud_rec_recorder_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_recorder_speech_param_t speech_param;
    kal_int32 result = MED_RES_FAIL;

#ifdef __HD_RECORD__
    SPH_ENH_AND_FIR_SCENE scene;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    if (aud_context_p->recorder_p)
    {
        /* Update speech parameters */
        speech_param.is_speech_on = aud_context_p->speech_on;
        speech_param.rat_mode = aud_context_p->rat_mode;
        
        aud_context_p->recorder_p->set(aud_context_p->recorder_p, AUD_RECORDER_SET_SPEECH_PARAM, (void*)&speech_param, sizeof(kal_uint32));
        
        /* Start recording */

    #ifdef __HD_RECORD__
        if(aud_rec_query_record_speech_mode(&scene))
        {
        #ifndef __GAIN_TABLE_SUPPORT__
            /* Set speech mode*/
            L1SP_SetSpeechEnhanceAndFir(scene,SPH_ENH_AND_FIR_UPDATE_TYPE_ALL);
        #endif
        }
    #endif
        
        result = aud_context_p->recorder_p->record(aud_context_p->recorder_p);
        _AUD_MODULE_RECORD_TRACE(result);

        if (result == MED_RES_OK)
        {
            /* Enter record state */
            aud_enter_state(AUD_MEDIA_RECORD);
        }
        else
        {
            /* Close the recorder */
            _aud_rec_recorder_close();
            /* Notify MMI the record is terminated because of resource conflict */
            aud_send_media_record_finish_ind(MED_RES_TERMINATED);

        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  _aud_rec_recorder_stop
 * DESCRIPTION
 *  This function is to stop a recorder.
 * PARAMETERS
 *  void
 * RETURNS
 *  MED_RES_OK      Successful.
 *  Others          Failed.
 *****************************************************************************/
static kal_int32 _aud_rec_recorder_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_FAIL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (aud_context_p->recorder_p)
    {
        /* Stop recording */
        result = aud_context_p->recorder_p->stop(aud_context_p->recorder_p);
        _AUD_MODULE_RECORD_TRACE(result);

        /* Enter idle state */
        aud_enter_state(AUD_MEDIA_IDLE);
    }
            
    return result;
}


/*-----------------------------------------------------------------------------
                    public functions
 ----------------------------------------------------------------------------*/

/*****************************************************************************
 * FUNCTION
 *  aud_rec_remap_record_mode
 * DESCRIPTION
 *  This function is to remap record mode from aud_rec_quality_enum to Audio_Record_Mode
 * PARAMETERS
 *  mode        [IN]    Record mode
 * RETURNS
 *  Audio_Record_Mode
 *****************************************************************************/
static Audio_Record_Mode aud_rec_remap_record_mode(aud_rec_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Audio_Record_Mode    rec_mode = AUDIO_RECORD_MODE_IDLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Remap mode */
    switch (mode)
    {
        case AUD_REC_MODE_SPEECH:
            rec_mode = AUDIO_RECORD_MODE_SPEECH;
            break;
        case AUD_REC_MODE_FMR:
            rec_mode = AUDIO_RECORD_MODE_FM;
            break;

#ifdef __ATV_SUPPORT__
        case AUD_REC_MODE_ATV:
    #ifdef __ATV_I2S_SUPPORT__
            rec_mode = AUDIO_RECORD_MODE_I2S;
    #endif /* __ATV_I2S_SUPPORT__ */
            break;
#endif /* __ATV_SUPPORT__ */

    }

    return rec_mode;

    
}

/*****************************************************************************
 * FUNCTION
 *  aud_rec_get_record_param
 * DESCRIPTION
 *  This function is to get record parameters for a given record mode and quality.
 * PARAMETERS
 *  mode        [IN]    Record mode
 *  quality     [IN]    Record quality
 *  param_p     [OUT]   Record parameters
 * RETURNS
 *  void
 *****************************************************************************/
void aud_rec_get_record_param(aud_rec_mode_enum mode, aud_rec_quality_enum quality, aud_rec_param_struct* param_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Audio_Record_Mode    rec_mode; //= AUDIO_RECORD_MODE_IDLE;
    Audio_Record_Quality rec_quality = AUDIO_RECORD_QUALITY_HIGH;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    rec_mode = aud_rec_remap_record_mode(mode);
    
    /* Remap quality */
    switch (quality)
    {
        case AUD_REC_QUALITY_LOW:
            rec_quality = AUDIO_RECORD_QUALITY_LOW;
            break;
    }

    /* Get record parameters */
    Media_GetRecordFormat(rec_mode, rec_quality, (Audio_Record_Format*)param_p);
}


/*****************************************************************************
 * FUNCTION
 *  aud_rec_get_record_quality_param
 * DESCRIPTION
 *  This function is to get record quality param for a given format and quality.
 * PARAMETERS
 *  format          : [IN] Record mode
 *  quality         : [IN] Record quality
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
kal_uint32 aud_rec_get_record_quality_param(Media_Format format, aud_rec_quality_enum quality)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 param = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(format == MEDIA_FORMAT_AMR)
    {
        if(quality == AUD_REC_QUALITY_AUTO)
        {
            param = 0x03; /* Best quality */
        }
        /* 10: 4.75kbps ~ 3: 12.2kbps */
        else if (quality >= AUD_REC_QUALITY_AMR_4_75 && 
                 quality <= AUD_REC_QUALITY_AMR_12_2)
        {
            param = 10 - (quality - AUD_REC_QUALITY_AMR_4_75);
        }
        else
        {
            if (quality != AUD_REC_QUALITY_LOW)
            {
                param = 0x03;
            }
            else /* low priority record */
            {
                param = 0x09;
            }
        }
    }
#if defined(AMRWB_ENCODE)
    else if(format == MEDIA_FORMAT_AMR_WB)
    {
        if(quality == AUD_REC_QUALITY_AUTO)
        {
            param = 0x28; /* Best quality */
        }
        /* 0x20: 6.6kbps ~ 0x28: 23.85kbps */
        else if(quality >= AUD_REC_QUALITY_AWB_6_6 &&
                quality <= AUD_REC_QUALITY_AWB_23_85)
        {
            param = 0x20 + (quality - AUD_REC_QUALITY_AWB_6_6);
        }
        else
        {
            if(quality != AUD_REC_QUALITY_LOW)
            {
                param = 0x28;
            }
            else /* low priority record */
            {
                param = 0x20;
            }
        }
    }
#endif /*AMRWB_ENCODE*/

    return param;

}

/*****************************************************************************
 * FUNCTION
 *  aud_rec_get_estimated_record_byte_rate
 * DESCRIPTION
 *  This function is to get record byte rate for a given mode, format and quality.
 * PARAMETERS
 *  mode            : [IN] Record mode
 *  format          : [IN] Record format
 *  quality         : [IN] Record quality
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint32 aud_rec_get_estimated_record_byte_rate(aud_rec_mode_enum mode, Media_Format format, aud_rec_quality_enum quality)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void* param_p = NULL;
    Audio_Record_Mode    rec_mode;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    param_p = (void*) aud_rec_get_record_quality_param(format,quality);
    rec_mode = aud_rec_remap_record_mode(mode);


    return Media_GetRecordFormatByteRate(format,rec_mode,param_p);
    
}

#if defined(__AUD_REC_INTENSITY__)
/*****************************************************************************
 * FUNCTION
 *  aud_record_get_intensity_req_hdlr
 * DESCRIPTION
 *  This function is to get mic intensity 
 * PARAMETERS
 *  ilm_ptr   ?
 * RETURNS
 *  void
 *****************************************************************************/

void aud_record_get_intensity_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	media_aud_get_intensity_req_struct *msg_p = (media_aud_get_intensity_req_struct*) ilm_ptr->local_para_ptr;
    kal_uint32 intensity = 0;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*---------------------------------------------------------------*/		
	intensity = L1SP_GetFrameIntensity(msg_p->channel);
	*msg_p->p_strength = intensity;	
			
	aud_set_event(AUD_EVT_WAIT);
}
/*****************************************************************************
 * FUNCTION
 *  aud_record_get_intensity_limit_req_hdlr
 * DESCRIPTION
 *  This function is to get mic intensity limit value
 * PARAMETERS
 *  ilm_ptr   ?
 * RETURNS
 *  void
 *****************************************************************************/

void aud_record_get_intensity_limit_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	media_aud_get_intensity_limit_req_struct *msg_p = (media_aud_get_intensity_limit_req_struct*) ilm_ptr->local_para_ptr;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*---------------------------------------------------------------*/	
	L1SP_GetIntensityExtremeValues(msg_p->max_value,msg_p->min_value);
	aud_set_event(AUD_EVT_WAIT);
}

#endif/*__AUD_REC_INTENSITY__*/


/*****************************************************************************
 * FUNCTION
 *  aud_rec_start_record
 * DESCRIPTION
 *  This function is to handle a record request. For normal record, the record
 *  process starts here. For video-call, the record process will be started
 *  when speech is on.
 * PARAMETERS
 *  ilm_ptr     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 aud_rec_start_record(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_media_record_req_struct *msg_p = NULL;
    kal_bool is_low_priority;
    kal_int32 result = MED_RES_OK;
    kal_uint8 resource = AUD_RESOURCE_SND_RECORD;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (l4aud_media_record_req_struct*) ilm_ptr->local_para_ptr;

    /* Check resource */
    if (!msg_p->default_input) /* FMR record */
    {
        resource = AUD_RESOURCE_FMR_RECORD;
    }


    if (! aud_media_is_resource_available(resource))
    {
        return MED_RES_BUSY;
    }

    /* if keytone is playing, stop it */
    aud_keytone_stop();

    /* if tone is playing, stop it */
    if (aud_context_p->tone_playing)
    {
        aud_tone_stop();
    }

#if defined( __MED_MMA_MOD__)&&(!defined(__MED_SLIM_MMA__))
    /* close all mma tasks */
    aud_mma_close_all();
#endif /* __MED_MMA_MOD__ */

    if (!(aud_context_p->state == AUD_MEDIA_RECORD ||
          aud_context_p->state == AUD_MEDIA_RECORD_PAUSED ||
          aud_context_p->state == AUD_MEDIA_WAIT_RECORD ||
          aud_context_p->state == AUD_VM_RECORD))
    {
        aud_stop_unfinished_process();
    }

    switch (aud_context_p->state)
    {
        case AUD_MEDIA_IDLE:
        {
            /* Check if there is enough space margin for recording */
            if ((result = aud_check_disc_space(msg_p->file_name, AUD_RECORD_MEM_MARGIN)) != MED_RES_OK)
            {
                return result;
            }
            
            /* Determine if we should use low priority record. If low priority record 
             * is applied, we will use MED-V thread to write data to file system - this 
             * could prevent MED thread from being blocked when writing data to file 
             * system. This also implies that if the MED thread doesn't have expected 
             * performance during record, we have to change the conditions for low 
             * priority record.
             */
        #if !defined(MED_V_NOT_PRESENT) && defined(__VOIP__)
            if ((msg_p->format == MEDIA_VOIPEVL) || AM_IsVoIPOn())
            {
                is_low_priority = KAL_TRUE;
            }
            else
        #endif /* #ifndef MED_V_NOT_PRESENT */
            {
                is_low_priority = KAL_FALSE;
            }

            /* Open a recorder handle */
            result = _aud_rec_recorder_open(msg_p->file_name,
                                            msg_p->format,
                                            msg_p->quality,
                                            is_low_priority,
                                            (kal_bool)(! msg_p->default_input),
                                            &aud_context_p->recorder_p);
            _AUD_MODULE_RECORD_TRACE(result);

            if ((result == MED_RES_OK) && (aud_context_p->recorder_p != NULL))
            {
                /* Set maximum record size and time */
                aud_context_p->recorder_p->set(aud_context_p->recorder_p, AUD_RECORDER_SET_SIZE_LIMIT, (void*)msg_p->size_limit, sizeof(kal_uint32));
                aud_context_p->recorder_p->set(aud_context_p->recorder_p, AUD_RECORDER_SET_TIME_LIMIT, (void*)msg_p->time_limit, sizeof(kal_uint32));

                /* Set input device of record. If the default input is not applied, it is FM record.
                 * Note that we have to restore input source when record is stopped.
                 */
                if (! msg_p->default_input)
                {
                    L1SP_SetInputSource(custom_cfg_hw_aud_input_path(msg_p->input_source));
                }

                /* If it is 3G324M, the recording will be started when speech is on. */
            #ifdef __MED_VCALL_MOD__
                if ((aud_context_p->rat_mode == RAT_3G324M_MODE) && !aud_context_p->speech_on)
                {
                    /* Enter wait-record state first. The recording will be started when speech is on. */
                    aud_enter_state(AUD_MEDIA_WAIT_RECORD);
                }
                else
            #endif /*__MED_VCALL_MOD__*/
                {
                    /* Start record */
                    result = _aud_rec_recorder_start();
                }
            }

            break;
        }
        default:
            result = MED_RES_BUSY;
            break;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_rec_stop_record
 * DESCRIPTION
 *  This function is to handle the request to stop the record.
 * PARAMETERS
 *  is_stop_unfinish        [IN]    Indicate if it's to stop unfinished record
 * RETURNS
 *  The result of stop record.
 *****************************************************************************/
kal_int32 aud_rec_stop_record(kal_bool is_stop_unfinished)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    _AUD_MODULE_RECORD_TRACE(aud_context_p->state);

    switch (aud_context_p->state)
    {
    #ifdef VM_LOG
        case AUD_VM_RECORD:
        {
            /* Stop VM logging */
            aud_vm_stop_logging();
            break;
        }
    #endif /* VM_LOG */
        case AUD_MEDIA_RECORD:
        case AUD_MEDIA_RECORD_PAUSED:
    #ifdef __MED_VCALL_MOD__
        case AUD_MEDIA_WAIT_RECORD:
    #endif /*__MED_VCALL_MOD__*/
        {
            /* Stop recorder */
            _aud_rec_recorder_stop();
            
            /* Close recorder */
            _aud_rec_recorder_close();

            if (is_stop_unfinished)
            {
                /* Notify MMI the record is terminated because of resource conflict */
                aud_send_media_record_finish_ind(MED_RES_TERMINATED);
            }

            break;
        }

        default:
            break;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_rec_pause_record
 * DESCRIPTION
 *  This function is to handle the request to pause the record.
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 aud_rec_pause_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_FAIL;
    kal_uint8 aud_state = AUD_MEDIA_IDLE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (aud_context_p->recorder_p)
    {
        /* Pause recording */
        result = aud_context_p->recorder_p->pause(aud_context_p->recorder_p);
        _AUD_MODULE_RECORD_TRACE(result);

        if (result == MED_RES_OK)
        {
            /* Validate the recorder here again because the recorder could be
             * terminated if reaching record limit.
             */
            if (aud_context_p->recorder_p)
            {
                /* Enter record-paused state */
                aud_state = AUD_MEDIA_RECORD_PAUSED;
            }
        }
    }

    aud_enter_state(aud_state);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_rec_resume_record
 * DESCRIPTION
 *  This function is to handle the request to resume the record.
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 aud_rec_resume_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_FAIL;
    med_aud_recorder_speech_param_t speech_param;
    kal_uint8 aud_state = AUD_MEDIA_IDLE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (aud_context_p->recorder_p)
    {
        /* Update speech parameters */
        speech_param.is_speech_on = aud_context_p->speech_on;
        speech_param.rat_mode = aud_context_p->rat_mode;
                        
        aud_context_p->recorder_p->set(aud_context_p->recorder_p, AUD_RECORDER_SET_SPEECH_PARAM, (void*)&speech_param, sizeof(kal_uint32));
                        
        /* Resume recording */
        result = aud_context_p->recorder_p->resume(aud_context_p->recorder_p);
        _AUD_MODULE_RECORD_TRACE(result);
        
        if (result == MED_RES_OK)
        {
            /* Enter record state */
            aud_state = AUD_MEDIA_RECORD;
        }

    }

    aud_enter_state(aud_state);

    return result;
}



/*****************************************************************************
 * FUNCTION
 *  aud_rec_speech_event
 * DESCRIPTION
 *  This function is called by the speech module before and after the speech
 *  state is changed. Note that it's important to keep the speech state consistent
 *  during a record. In other words, if it's recording, we should pause the record
 *  before turning on the speech and resume the record after the speech in on. This
 *  process should also be applied when speech is going to be off.
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void aud_rec_speech_event_nfy(aud_speech_event_enum event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* 0:do noting ,1: stop record before speech change 2: restart record after speech change */
    kal_uint8 stop_record = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event)
    {
        case AUD_SPEECH_EVENT_PRE_ON:   /* Before speech is on */
            if (aud_context_p->state == AUD_MEDIA_RECORD)
            {
                /* Stop record */
                stop_record = 1;
            }
            break;
            
        case AUD_SPEECH_EVENT_POST_ON:  /* After speech is on */            
        #ifdef __MED_VCALL_MOD__
            aud_rec_vcall_speech_on();
        #endif /* __MED_VCALL_MOD__ */

            if (g_is_paused_by_speech_evt)
            {
                /* Restart record */
                stop_record = 2;
            }
            break;
        
        case AUD_SPEECH_EVENT_PRE_OFF:  /* Before speech is off */           
        #ifdef __MED_VCALL_MOD__
            aud_rec_vcall_speech_off();
        #endif /* __MED_VCALL_MOD__ */

            if (aud_context_p->state == AUD_MEDIA_RECORD)
            {
                /* Stop record */
                stop_record = 1;
            }
            break;
        
        case AUD_SPEECH_EVENT_POST_OFF: /* After speech is off */
            if (g_is_paused_by_speech_evt)
            {
                /* Restart record */
                stop_record = 2;
            }
            break;
            
        default:
            break;
    }

    if(stop_record == 1)
    {
        _aud_rec_recorder_stop();
        g_is_paused_by_speech_evt = KAL_TRUE;
    }
    else if(stop_record == 2)
    {
        _aud_rec_recorder_start();
        g_is_paused_by_speech_evt = KAL_FALSE;
    }


}


#ifdef __MED_VCALL_MOD__
/*****************************************************************************
 * FUNCTION
 *  aud_rec_vcall_speech_on
 * DESCRIPTION
 *  This function is invoked by speech module when speech is on.
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_rec_vcall_speech_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 result;
    med_aud_recorder_speech_param_t speech_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_REC_VCALL_SPEECH_ON);

    if (aud_context_p->rat_mode == RAT_3G324M_MODE)
    {
        switch (aud_context_p->state)
        {
            case AUD_MEDIA_WAIT_RECORD:
            {
            #ifdef __HD_RECORD__
                SPH_ENH_AND_FIR_SCENE scene;
            #endif

                /* Update speech parameters */
                speech_param.is_speech_on = aud_context_p->speech_on;
                speech_param.rat_mode = aud_context_p->rat_mode;
                    
                aud_context_p->recorder_p->set(aud_context_p->recorder_p, AUD_RECORDER_SET_SPEECH_PARAM, (void*)&speech_param, sizeof(kal_uint32));

            #ifdef __HD_RECORD__
                if(aud_rec_query_record_speech_mode(&scene))
                {
                #ifndef __GAIN_TABLE_SUPPORT__
                    /* Set speech mode*/
                    L1SP_SetSpeechEnhanceAndFir(scene,SPH_ENH_AND_FIR_UPDATE_TYPE_ALL);
                #endif
                }
            #endif

                /* Start recording */
                result = aud_context_p->recorder_p->record(aud_context_p->recorder_p);
                _AUD_MODULE_RECORD_TRACE(result);

                if (result == MED_RES_OK)
                {
                    /* Enter record state */
                    aud_enter_state(AUD_MEDIA_RECORD); 
                }
                else
                {
                    /* Close the recorder */
                    _aud_rec_recorder_close();
                    
                    /* Notify MMI the record is terminated */
                    aud_send_media_record_finish_ind(result);

                    /* Enter idle state */
                    aud_enter_state(AUD_MEDIA_IDLE);
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
 *  aud_rec_vcall_speech_off
 * DESCRIPTION
 *  This function is invoked by speech module when speech is off.
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_rec_vcall_speech_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_REC_VCALL_SPEECH_OFF);

    if (aud_context_p->rat_mode == RAT_3G324M_MODE)
    {
        switch (aud_context_p->state)
        {
            case AUD_MEDIA_RECORD:
                /* Stop recording */
                result = aud_context_p->recorder_p->stop(aud_context_p->recorder_p);
                _AUD_MODULE_RECORD_TRACE(result);

                if (result == MED_RES_OK)
                {
                    /* Enter wait-record state */
                    aud_enter_state(AUD_MEDIA_WAIT_RECORD);
                }
                else
                {
                    /* Close the recorder */
                    _aud_rec_recorder_close();
                    
                    /* Notify MMI the record is terminated */
                    aud_send_media_record_finish_ind(result);

                    /* Enter idle state */
                    aud_enter_state(AUD_MEDIA_IDLE);
                }
                
                break;
            default:
                break;
        }
    }
}

#endif /*__MED_VCALL_MOD__*/

#ifdef __HD_RECORD__
/*****************************************************************************
 * FUNCTION
 *  aud_rec_query_record_speech_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 * scene  [OUT]  output the scenario with this param
 * RETURNS
 *  kal_bool
 *  KAL_TRUE: apply record mode. Scene is the mode to use
 *  KAL_FALSE: do not apply record mode. Scene is meaningless in this case 
 *****************************************************************************/
kal_bool aud_rec_query_record_speech_mode(SPH_ENH_AND_FIR_SCENE * scene)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_fm_record = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(aud_context_p->speech_on || aud_context_p->recorder_p == NULL)
    {
        return KAL_FALSE;
    }

    aud_context_p->recorder_p->get(aud_context_p->recorder_p, AUD_RECORDER_GET_IS_FM_RECORD, (void*)&is_fm_record, sizeof(kal_bool));

    if(is_fm_record)
    {
        *scene = SPH_ENH_AND_FIR_SCENE_NORMAL;
    }
    else
    {
    #ifdef __MED_BT_HFP_MOD__
        if(aud_bt_hfp_is_speech_path_on())
        {
            *scene = SPH_ENH_AND_FIR_SCENE_HD_RECORD_VOICE_BT;
        }
        else 
    #endif /*__MED_BT_HFP_MOD__*/
        if(aud_context_p->audio_mode == AUD_MODE_HEADSET)
        {
            *scene = SPH_ENH_AND_FIR_SCENE_HD_RECORD_VOICE_HEADSET;
        }
        else
        {
            *scene = SPH_ENH_AND_FIR_SCENE_HD_RECORD_VOICE_HANDSET;
        }
    }

    return KAL_TRUE;

}
#endif /* __HD_RECORD__ */

#endif /*__MED_AUD_REC_MOD__*/
#endif /* MED_NOT_PRESENT */



