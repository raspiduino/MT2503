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
 *   bitstream_record.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains BITSTREAM record functions.
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

/*-----------------------------------------------------------------------------
                    include files
-----------------------------------------------------------------------------*/

#ifdef WIN32
#include <stdio.h>
#endif 

/* KAL - RTOS Abstraction Layer */
#include "kal_release.h"

/* Task Message Communication */
//#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* local/peer struct */
//#include "stack_ltlcom.h"

/* Task Management */
//#include "syscomp_config.h"
//#include "task_config.h"

/* Timer Management  */
//#include "stacklib.h"
//#include "event_shed.h" /* event schedulet */
//#include "stack_timer.h"

//#include "app_buff_alloc.h"     /* buffer management API */
//#include "lcd_cqueue.h" /* circular queue */
//#include "app2soc_struct.h"     /* interface with Applications */

//#include "stack_utils.h"

#include "kal_trace.h"

#include "med_global.h"
#include "med_struct.h"
#include "med_trc.h"

#ifdef __MED_BITSTREAM_MOD__
/* global includes */
#include "l1audio.h"
//#include "device.h"
//#include "custom_equipment.h"
//#include "custom_nvram_editor_data_item.h"

#include "med_main.h"
//#include "aud_defs.h"
//#include "med_api.h"
#include "med_context.h"
//#include "med_utility.h"
#include "aud_main.h"

#include "bitstream_main.h"
#include "bitstream_api.h"

#include "kal_general_types.h"
#include "stack_config.h"
    
/*-----------------------------------------------------------------------------
                    macros, defines, typedefs, enums
-----------------------------------------------------------------------------*/
#define _BITSTREAM_RECORD_TRACE(x, y, z)    BITSTREAM_RECORD_TRACE(x, y, z, __LINE__)
#define BITSTREAM_RECORD_BUFFER_THRESHOLD   (200) /* 200 words (400 bytes) by default */


typedef enum
{
    BITSTREAM_RECORD_STATE_IDLE,
    BITSTREAM_RECORD_STATE_RECORD,
    BITSTREAM_RECORD_STATE_PAUSE,
    
    BITSTREAM_RECORD_STATE_TOTAL
} bitstream_record_state_enum;

typedef struct
{
    module_type src_id;        /* Source module ID */
    kal_int32   handle;        /* Recorder handle */
    kal_uint8   format;        /* Record format of driver */
    void*       param_p;       /* Record parameter */
    kal_uint16* ring_buffer_p; /* Ring buffer */
    kal_uint32  cb_threshold;  /* Callback threshold */
    kal_uint8   state;         /* Recorder state */
} bitstream_record_context_t;

/*-----------------------------------------------------------------------------
                    data declaraions
-----------------------------------------------------------------------------*/
static kal_bool                   g_is_recorder_opened = KAL_FALSE;
static bitstream_record_context_t g_record_ctx;

/*-----------------------------------------------------------------------------
                    function prototypes
 ----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
                    private functions
 ----------------------------------------------------------------------------*/

/*****************************************************************************
 * FUNCTION
 *  _bitstream_record_stop
 * DESCRIPTION
 *  This function is to stop bitsteam record.
 * PARAMETERS       
 *  void
 * RETURNS
 *  Driver result
 *****************************************************************************/
static void _bitstream_record_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Stop record */
    Media_Stop();

    /* Free ring buffer */
    if (g_record_ctx.ring_buffer_p != NULL)
    {
        aud_util_free_ring_buffer_ext(&g_record_ctx.ring_buffer_p);
    }

    /* Enter idle state */
    g_record_ctx.state = BITSTREAM_RECORD_STATE_IDLE;
    aud_enter_state(AUD_MEDIA_IDLE);
}


/*****************************************************************************
 * FUNCTION
 *  _bitstream_record_driver_event_callback_fct
 * DESCRIPTION
 *  This function is to handle the record events called back from L1audio driver.
 * PARAMETERS       
 *  event       [IN]        Record event.
 * RETURNS
 *  void
 *****************************************************************************/
static void _bitstream_record_driver_event_callback_fct(Media_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bitstream_record_driver_event_ind_struct *ind_p = (media_bitstream_record_driver_event_ind_struct*)
        construct_local_para(sizeof(media_bitstream_record_driver_event_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p->handle = g_record_ctx.handle;
    ind_p->event = (kal_uint8)event;

    bitstream_send_msg(MOD_L1SP, MOD_MED, MSG_ID_MEDIA_BITSTREAM_RECORD_DRIVER_EVENT_IND, ind_p);
}


/*-----------------------------------------------------------------------------
                    public functions
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  bitstream_record_driver_event_ind_hdlr
 * DESCRIPTION
 *  This function is to handle the callback event from L1audio driver.
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void bitstream_record_driver_event_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bitstream_record_driver_event_ind_struct *msg_p = (media_bitstream_record_driver_event_ind_struct*) ilm_ptr->local_para_ptr;
    media_bitstream_record_callback_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    _BITSTREAM_RECORD_TRACE(msg_p->event, msg_p->handle, g_record_ctx.state);
    
    if ((g_record_ctx.handle == msg_p->handle) &&
        (g_record_ctx.state == BITSTREAM_RECORD_STATE_RECORD))
    {
        /* Notify MMI with record event */
        ind_p = (media_bitstream_record_callback_ind_struct*)
                        construct_local_para(sizeof(media_bitstream_record_callback_ind_struct), TD_CTRL);
        
        ind_p->handle = msg_p->handle;
        ind_p->event = msg_p->event;

        bitstream_send_msg(MOD_MED, g_record_ctx.src_id, MSG_ID_MEDIA_BITSTREAM_RECORD_CALLBACK_IND, ind_p);

        /* Stop recording if something wrong */
        if (msg_p->event == MEDIA_ERROR)
        {
            _bitstream_record_stop();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  bitstream_record_open_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void bitstream_record_open_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bitstream_record_open_req_struct *msg_p = (media_bitstream_record_open_req_struct*) ilm_ptr->local_para_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* We support only one bitsream recorder */
    if (g_is_recorder_opened == KAL_TRUE)
    {
        BITSTREAM_RETURN(MED_RES_BUSY);  
    }

    /* Determine record format & parameter */
    switch (msg_p->codec_type)
    {
#ifdef WAV_CODEC
        case MED_TYPE_WAV:
            g_record_ctx.format = MEDIA_FORMAT_WAV;
            g_record_ctx.param_p = NULL;
            break;

        case MED_TYPE_WAV_DVI_ADPCM:
            g_record_ctx.format = MEDIA_FORMAT_WAV_DVI_ADPCM;
            g_record_ctx.param_p = NULL;
            break;

        case MED_TYPE_PCM_8K:
            g_record_ctx.format = MEDIA_FORMAT_PCM_8K;
            g_record_ctx.param_p = NULL;
            break;
#endif /*WAV_CODEC*/

            
        case MED_TYPE_AMR:
            g_record_ctx.format = MEDIA_FORMAT_AMR;
        
            if (msg_p->quality >= AUD_REC_QUALITY_AMR_4_75 && 
                msg_p->quality <= AUD_REC_QUALITY_AMR_12_2)
            {
                g_record_ctx.param_p = (void*)(10 - (msg_p->quality - AUD_REC_QUALITY_AMR_4_75)); /* 10: 4.75kbps ~ 3: 12.2kbps */
            }
            else
            {
                if (msg_p->quality != AUD_REC_QUALITY_LOW)
                {
                    g_record_ctx.param_p = (void*)0x03;
                }
                else /* low priority record */
                {
                    g_record_ctx.param_p = (void*)0x09;
                }
            }
            
            break;
            
    #if defined(AMRWB_ENCODE)
        case MED_TYPE_AMR_WB:
            g_record_ctx.format = MEDIA_FORMAT_AMR_WB;

            if (msg_p->quality != AUD_REC_QUALITY_LOW)
            {
                g_record_ctx.param_p = (void*)0x28;
            }
            else /* low priority record */
            {
                g_record_ctx.param_p = (void*)0x20;
            }

            break;
    #endif /* AMRWB_ENCODE */
    
        default:
            BITSTREAM_RETURN(MED_RES_BITSTREAM_UNSUPPORTED_CODEC);
    }

    /* Turn on the flag indicating the recorder is being opened */
    g_is_recorder_opened = KAL_TRUE;

    /* Update recorder data */
    g_record_ctx.src_id = ilm_ptr->src_mod_id;
    g_record_ctx.handle++;
    g_record_ctx.ring_buffer_p = NULL;
    g_record_ctx.state = BITSTREAM_RECORD_STATE_IDLE;
    g_record_ctx.cb_threshold = BITSTREAM_RECORD_BUFFER_THRESHOLD;

    _BITSTREAM_RECORD_TRACE(g_record_ctx.handle, g_record_ctx.format, g_record_ctx.param_p);
    
    /* Copy out recorder handle */
    *msg_p->handle_p = g_record_ctx.handle;

    BITSTREAM_RETURN(MED_RES_OK);
}


/*****************************************************************************
 * FUNCTION
 *  bitstream_record_close_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void bitstream_record_close_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Stop record if it's in record or pause state */
    if (g_record_ctx.state != BITSTREAM_RECORD_STATE_IDLE)
    {
        _bitstream_record_stop();
    }

    /* Turn on the flag indicating the recorder is closed */
    g_is_recorder_opened = KAL_FALSE;

    BITSTREAM_RETURN(MED_RES_OK);
}


/*****************************************************************************
 * FUNCTION
 *  bitstream_record_start_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void bitstream_record_start_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status drv_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check if the recorder is in idle state */
    if (g_record_ctx.state != BITSTREAM_RECORD_STATE_IDLE)
    {
        BITSTREAM_RETURN(MED_RES_FAIL);
    }

    /* Allocate ring buffer */
    aud_util_alloc_ring_buffer_ext(AUD_RING_BUFFER_SIZE, &g_record_ctx.ring_buffer_p);
    Media_SetBuffer(g_record_ctx.ring_buffer_p, AUD_RING_BUFFER_LEN);

    /* Set record buffer callback threshold */
    Media_SetRBThreshold(g_record_ctx.cb_threshold);

    /* Start to record */
    drv_result = Media_Record((Media_Format)g_record_ctx.format, _bitstream_record_driver_event_callback_fct, g_record_ctx.param_p);
    _BITSTREAM_RECORD_TRACE(drv_result, -1, -1);

    if (drv_result == MEDIA_SUCCESS)
    {
        /* Enter record state */
        g_record_ctx.state = BITSTREAM_RECORD_STATE_RECORD;
        aud_enter_state(AUD_MEDIA_RECORD);
    }
    else if (g_record_ctx.ring_buffer_p != NULL)
    {
        aud_util_free_ring_buffer_ext(&g_record_ctx.ring_buffer_p);
    }

    BITSTREAM_RETURN(aud_get_res(drv_result)); /* Convert driver result to med result */
}


/*****************************************************************************
 * FUNCTION
 *  bitstream_record_stop_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void bitstream_record_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_record_ctx.state == BITSTREAM_RECORD_STATE_IDLE)
    {
        BITSTREAM_RETURN(MED_RES_FAIL);
    }

    /* Stop record */
    _bitstream_record_stop();

    /* No need to notify the client to read remaining recorded data */
    
    BITSTREAM_RETURN(MED_RES_OK); /* Convert driver result to med result */
}


/*****************************************************************************
 * FUNCTION
 *  bitstream_record_set_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void bitstream_record_set_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bitstream_record_set_req_struct *msg_p = (media_bitstream_record_set_req_struct*) ilm_ptr->local_para_ptr;
    Media_Status drv_result = MEDIA_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (msg_p->set_type)
    {
        case BITSTREAM_RECORD_SET_PAUSE:
            /* Check if it's in record state */
            if (g_record_ctx.state == BITSTREAM_RECORD_STATE_RECORD)
            {
                drv_result = Media_Pause();
                _BITSTREAM_RECORD_TRACE(drv_result, -1, -1);
                
                if (drv_result == MEDIA_SUCCESS)
                {
                    /* Enter pause state */
                    g_record_ctx.state = BITSTREAM_RECORD_STATE_PAUSE;
                    aud_enter_state(AUD_MEDIA_RECORD_PAUSED);
                }
            }
            
            break;
            
        case BITSTREAM_RECORD_SET_RESUME:
            /* Check if it's in paused state */
            if (g_record_ctx.state == BITSTREAM_RECORD_STATE_PAUSE)
            {
                drv_result = Media_Resume();
                _BITSTREAM_RECORD_TRACE(drv_result, -1, -1);

                if (drv_result == MEDIA_SUCCESS)
                {
                    /* Enter record state */
                    g_record_ctx.state = BITSTREAM_RECORD_STATE_RECORD;
                    aud_enter_state(AUD_MEDIA_RECORD);
                }
            }
            
            break;

        case BITSTREAM_RECORD_SET_CB_THRESHOLD:
            /* set callback threshold */
            g_record_ctx.cb_threshold = *((kal_uint32*)(msg_p->data_p));

            if(g_record_ctx.cb_threshold > (AUD_RING_BUFFER_LEN/2))
            {
               g_record_ctx.cb_threshold = (AUD_RING_BUFFER_LEN/2);
            }

            if (g_record_ctx.state == BITSTREAM_RECORD_STATE_RECORD)
            {
                Media_SetRBThreshold(g_record_ctx.cb_threshold);
            }

            drv_result = MEDIA_SUCCESS;

            break;
            
        default:
            drv_result = MEDIA_UNSUPPORTED_OPERATION;
            break;
    }
    
    BITSTREAM_RETURN(aud_get_res(drv_result)); /* Convert driver result to med result */
}


/*****************************************************************************
 * FUNCTION
 *  bitstream_record_get_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void bitstream_record_get_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bitstream_record_get_req_struct *msg_p = (media_bitstream_record_get_req_struct*) ilm_ptr->local_para_ptr;
    kal_uint16*  record_data_p; /* Recorded data */
    kal_uint32   record_len;    /* 2 bytes per unit */
    kal_uint32   buffer_len;    /* The length of application buffer. 2 bytes per unit */
    kal_uint32   copy_len;      /* The length of recorded data which should be copied to application buffer */
    Media_Status drv_result = MEDIA_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (msg_p->get_type)
    {
        case BITSTREAM_RECORD_GET_LENGTH:
            Media_GetReadBuffer(&record_data_p, &record_len);
            *((kal_uint16*)msg_p->data_len_p) = (kal_uint16)record_len;
            break;
            
        case BITSTREAM_RECORD_GET_DATA:
            Media_GetReadBuffer(&record_data_p, &record_len);

            /* Determine copy length */
            buffer_len = (kal_uint32)(*((kal_uint16*)msg_p->data_len_p));

            if (record_len > buffer_len)
            {
                /* Recorded data is more than the buffer application provides.
                 * We should copy partial of recorded data to application buffer.
                 */
                copy_len = buffer_len;
            }
            else
            {
                /* Recorded data is less than the buffer application provides.  
                 * We could copy all the recorded data to application buffer.
                 */
                copy_len = record_len;
            }

            /* Copy-out recorded data to application buffer */
            kal_mem_cpy(msg_p->data_p, (void*)record_data_p, sizeof(kal_uint16) * copy_len);

            /* Update the length of data */
            *((kal_uint16*)msg_p->data_len_p) = (kal_uint16)copy_len;

            /* Notify L1Audio the length of data that has been read */
            Media_ReadDataDone(copy_len);
            
            break;

        case BITSTREAM_RECORD_GET_STRENGTH:
        {
            if (g_record_ctx.state == BITSTREAM_RECORD_STATE_RECORD)
            {
                kal_uint32 strength =  L1SP_GetFrameIntensity(FIRST_MIC);
                *((kal_uint32*)msg_p->data_p) = strength;
            }
            else
            {
                drv_result = MEDIA_UNSUPPORTED_OPERATION;
            }
            break;
        }

        default:
            drv_result = MEDIA_UNSUPPORTED_OPERATION;
            break;
    }
    
    BITSTREAM_RETURN(aud_get_res(drv_result)); /* Convert driver result to med result */
}

#endif /* __MED_BITSTREAM_MOD__ */


