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
 * aud_player_media.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary functions of media player.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/******************************************************************
 * MODULE
 *    Media Player
 * DESCRIPTION
 *    This module defines related function of Media Player.
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
#include "FSAL.h"

/* local includes */
#include "med_global.h"
//#include "aud_defs.h"
#include "med_utility.h"
//#include "med_struct.h"
//#include "med_api.h"
//#include "med_context.h"
#include "med_main.h"
#include "aud_main.h"
#include "aud_player.h"
#include "aud_player_media.h"

#include "kal_general_types.h"
//#include "kurotypedef.h"
#include "kal_public_api.h"
#include "stack_config.h"
#include "med_smalloc.h"
#include "med_v_main.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#if defined(__MTK_TARGET__)
/*-----------------------------------------------------------------------------
                    macros, defines, typedefs, enums
-----------------------------------------------------------------------------*/
#define _AUD_PLAYER_MEDIA_TRACE(x, y, z)    AUD_PLAYER_MEDIA_TRACE(x, y, z, __LINE__)
#define _AUD_PLAYER_MEDIA2_TRACE(x, y)      AUD_PLAYER_MEDIA2_TRACE(x, y,  __LINE__)
#define _AUD_PLAYER_MEDIA1_TRACE(x)         AUD_PLAYER_MEDIA1_TRACE(x, __LINE__)


/* Media Event */
typedef struct
{
    MHdl*                         mhdl_handle_p;  /* L1audio handle */
    Media_Event                   event;          /* Event */
    med_aud_player_t*             player_p;       /* Player handle */
    kal_uint32                    time_stamp;     /* Time stamp of the callback event */
} med_aud_player_media_event_t;

/* Media Player */
typedef struct
{
    med_aud_player_t              itf;            /* Player interfaces */
    kal_uint32                    time_stamp;     /* Time stamp of the constructed player */
    MHdl*                         mhdl_handle_p;  /* L1audio handle */
    STFSAL                        fsal_handle;    /* file handle */
    kal_bool                      is_file_opened; /* Indicate if a file handler has been opened successfully */
    kal_uint8                     state;          /* Player state */
    med_type_enum                 media_type;     /* Media type */
    kal_uint32                    start_time;     /* Start time */
    kal_uint32                    stop_time;      /* Stop time */
    kal_uint16*                   ring_buffer_p;  /* Ring buffer */
    med_aud_player_cb_fct         cb_fct;         /* Callback when there is event arisen */
    void*                         cb_param;       /* Callback parameter */
} med_aud_player_media_t;

#ifdef __KARAOKE_SUPPORT__
extern kal_bool g_karaoke_mono;
//extern kal_uint16 g_karaoke_dl_sr;
#endif
/*-----------------------------------------------------------------------------
                    data declaraions
 ----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
                    function prototypes
 ----------------------------------------------------------------------------*/ 

/*-----------------------------------------------------------------------------
                    private function declarations
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  _aud_player_media_event_callback_hdlr
 * DESCRIPTION
 *  This function is used to handle the callback events from L1Audio.
 * PARAMETERS
 *  data_p             [IN]       Media event data.
 *  date_len           [IN]       The length of data.
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_player_media_event_callback_hdlr(void* data_p, kal_uint16 date_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_media_t*       self_p;
    med_aud_player_media_event_t* media_event_p = (med_aud_player_media_event_t*)data_p;
    MHdl*                         mhdl_handle_p;
    Media_Event                   event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(media_event_p->player_p, med_aud_player_media_t, itf);
    mhdl_handle_p = media_event_p->mhdl_handle_p;
    
    /* Validate event */
    if (self_p->state != AUD_MEDIA_PLAY ||
        self_p->mhdl_handle_p != media_event_p->mhdl_handle_p ||
        self_p->time_stamp != media_event_p->time_stamp)
    {
        _AUD_PLAYER_MEDIA1_TRACE(self_p->state);
        return;
    }
    
    /* Process media data */
    event = mhdl_handle_p->Process(mhdl_handle_p, (Media_Event) media_event_p->event);
    _AUD_PLAYER_MEDIA2_TRACE(event, media_event_p->event);

    /* Post processing */
    switch (event)
    {
        case MEDIA_NONE:
            /* Do nothing */
            break;
        /*
        case MEDIA_UPDATE_DUR:
        case MEDIA_END:        
        case MEDIA_STOP_TIME_UP:
        case MEDIA_ERROR:
        case MEDIA_DECODER_UNSUPPORT:
        */
        default:
            /* Callback event to player handler */
            if (self_p->cb_fct)
            {
                self_p->cb_fct(media_event_p->player_p, event, self_p->cb_param);
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  _aud_player_media_event_callback_fct
 * DESCRIPTION
 *  This function is used to receive the callback events from L1Audio.
 * PARAMETERS
 *  handle_p       [IN]        MHdl handle. 
 *  event          [IN]        Play event.
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_player_media_event_callback_fct(MHdl *handle_p, Media_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_media_event_t media_event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Get player handle from attached user data */
    handle_p->GetUserData(handle_p, (void**)&media_event.player_p);
    
    media_event.mhdl_handle_p = handle_p;
    media_event.event = event;
    media_event.time_stamp = PTHIS(media_event.player_p, med_aud_player_media_t, itf)->time_stamp;
    
    aud_util_proc_in_med_ext(MOD_L1SP,
                             _aud_player_media_event_callback_hdlr,
                             (void*)&media_event,
                             sizeof(med_aud_player_media_event_t));
}


/*****************************************************************************
 * FUNCTION
 *  _aud_player_media_get_content_desc
 * DESCRIPTION
 *  This function is used to get content description of the media content.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static kal_int32 _aud_player_media_get_content_desc(med_aud_player_t* player_p, audInfoStruct* desc_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_media_t*  self_p;
    media_get_info_func_ptr  content_desc_fct = NULL;
    Media_Status             drv_result;
    void*                    param_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(player_p, med_aud_player_media_t, itf);
    
    /* Get context description handler */
    switch (self_p->media_type)
    {
    #ifdef DAF_DECODE
        case MED_TYPE_DAF:
    #ifdef MUSICAM_DECODE
        case MED_TYPE_MUSICAM:
    #endif
            content_desc_fct = DAF_GetContentDescInfo;
            break;
    #endif /* DAF_DECODE */
    #ifdef AMR_DECODE
        case MED_TYPE_AMR:
        case MED_TYPE_AMR_WB:
            content_desc_fct = AMR_GetContentDescInfo;
            break;
    #endif /* AMR_DECODE */
    #ifdef WAV_CODEC
        case MED_TYPE_WAV:
        case MED_TYPE_WAV_DVI_ADPCM:
            content_desc_fct = WAV_GetContentDescInfo;
            break;
    #endif /*WAV_CODEC*/
    #ifdef AIFF_DECODE
        case MED_TYPE_AIFF:
            content_desc_fct = AIFF_GetContentDescInfo;
            break;
    #endif /* AIFF_DECODE */
    #ifdef AU_DECODE
        case MED_TYPE_AU:
            content_desc_fct = AU_GetContentDescInfo;
            break;
    #endif /* AU_DECODE */
    #ifdef AAC_DECODE
        case MED_TYPE_AAC:
        case MED_TYPE_BSAC:
            content_desc_fct = AAC_GetContentDescInfo;
            break;
    #endif /* AAC_DECODE */

    #ifdef WMA_DECODE
        case MED_TYPE_WMA:
            content_desc_fct = WMA_GetContentDescInfo;
            break;
    #endif /* WMA_DECODE */
    #ifdef WAV_CODEC
        case MED_TYPE_PCM_8K:
        case MED_TYPE_PCM_16K:
            content_desc_fct = PCM_GetContentDescInfo;
            break;
    #endif /*WAV_CODEC*/
    #ifdef __VM_CODEC_SUPPORT__
        case MED_TYPE_GSM_EFR:
            content_desc_fct = VM_GetContentDescInfo;
            break;
    #endif /*__VM_CODEC_SUPPORT__*/
    #ifdef __APE_DECODE__
        case MED_TYPE_APE:
            content_desc_fct = APE_GetContentDescInfo;
            break;
    #endif /* __APE_DECODE__ */
    #ifdef __VORBIS_DECODE__
        case MED_TYPE_VORBIS:
            content_desc_fct = VORBIS_GetContentDescInfo;
            break;
    #endif /*__OGG_DECODE__*/
    #ifdef __FLAC_DECODE__
        case MED_TYPE_FLAC:
            content_desc_fct = FLAC_GetContentDescInfo;
            break;
    #endif


        default:
            break;
    }

    /* Set parameter for special types */
    switch (self_p->media_type)
    {
    #ifdef __VM_CODEC_SUPPORT__
        case MED_TYPE_GSM_EFR:
            param_p = (void*)self_p->media_type;
            break;
    #endif /*__VM_CODEC_SUPPORT__*/
    #ifdef WAV_CODEC
        case MED_TYPE_PCM_8K:
        case MED_TYPE_PCM_16K:
            param_p = (void*)self_p->media_type;
            break;
    #endif /*WAV_CODEC*/       
        default:
            break;   
    }
    
    /* Get content description */
    if (content_desc_fct != NULL)
    {
        drv_result = content_desc_fct(&self_p->fsal_handle, desc_p, param_p);  
		#ifdef __KARAOKE_SUPPORT__
		if(desc_p->stereo==KAL_FALSE) //wxw
		{
			g_karaoke_mono=KAL_TRUE;
		}
		else
		{
			g_karaoke_mono=KAL_FALSE;
		}
/*		if(0 == desc_p->sampleRate)
			desc_p->time = 0;
		else
    		g_karaoke_dl_sr = desc_p->sampleRate;
*/
		#endif
    }
    else
    {
        drv_result = MEDIA_UNSUPPORTED_OPERATION;
    }
    
    return aud_get_res(drv_result);
}

/*****************************************************************************
 * FUNCTION
 *  aud_player_media_close
 * DESCRIPTION
 *  This function is used to close an Media player.
 * PARAMETERS
 *  player_p      [IN]        Player handle.              
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_media_close(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_media_t* self_p;
    Media_Status            drv_result = MEDIA_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(player_p, med_aud_player_media_t, itf);
    
    /* Free player resources */
    if (self_p->mhdl_handle_p)
    {
        /* Close MHdl handler */
        drv_result = self_p->mhdl_handle_p->Close(self_p->mhdl_handle_p);
        _AUD_PLAYER_MEDIA1_TRACE(drv_result);
        
        self_p->mhdl_handle_p = NULL;
    }
    
    /* Free FSAL resources */
    if (self_p->is_file_opened)
    {
        /* Free buffer */
        if (self_p->fsal_handle.bBuffering && self_p->fsal_handle.pbBuf != NULL)
        {
        #if defined(AUD_PROC_USE_EXT_MEM)
            AUD_PLAYER_FREE_AUD_MEM(self_p->fsal_handle.pbBuf);
        #else
            AUD_PLAYER_FREE_CTRL_BUF(self_p->fsal_handle.pbBuf);
        #endif
        }
        
        /* Close FSAL handler */
        FSAL_Close(&self_p->fsal_handle);
        
        self_p->is_file_opened = KAL_FALSE;
    }

    return aud_get_res(drv_result);
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_media_open
 * DESCRIPTION
 *  This function is used to open an Media player.
 * PARAMETERS
 *  player_p      [IN]        Player handle.
 *  cfg_p         [IN]        Player configuration.  
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_media_open(med_aud_player_t* player_p, med_aud_player_cfg_t* cfg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_media_t* self_p;
    kal_int32               med_result;
    kal_bool                is_file;
    media_open_func_ptr     open_fct = NULL;
    Media_VM_PCM_Param      vp_param;
    void*                   param_p = NULL;
    kal_uint8*              fsal_buf_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(player_p, med_aud_player_media_t, itf);

    /* Open from file */
    if (cfg_p->file_name != NULL)
    {
        if (FSAL_Open(&self_p->fsal_handle, cfg_p->file_name, FSAL_READ_SHARED) != FSAL_OK)
        {
            return MED_RES_OPEN_FILE_FAIL;
        }
        
        #ifdef __KARAOKE_SUPPORT__
		if(aud_get_karaoke_mode() == MEDIA_KARAPLAY_PLAY_REC_MIX || aud_get_karaoke_mode() == MEDIA_KARAPLAY_REC_MIX_ONLY)
			_aud_recorder_karaoke_keep_src_path(cfg_p->file_name);
        #endif
        /* Determine media type per file extension */
        self_p->media_type = (med_type_enum)med_get_media_type(cfg_p->file_name);
        is_file = KAL_TRUE;
    }
    /* Open from buffer */
    else if (cfg_p->data_p != NULL)
    {
        FSAL_Direct_SetRamFileSize(&self_p->fsal_handle, cfg_p->data_len);
        if (FSAL_Open(&self_p->fsal_handle, cfg_p->data_p, FSAL_ROMFILE) != FSAL_OK)
        {
            return MED_RES_OPEN_FILE_FAIL;
        }
        
        /* Save media type */
        self_p->media_type = (med_type_enum)cfg_p->format;
        is_file = KAL_FALSE;        
    }
    else
    {
        return MED_RES_PARAM_ERROR;
    }
    
    self_p->is_file_opened = KAL_TRUE;

    /*------------------- Get open function per media format -----------------*/
    switch (self_p->media_type)
    {
    #ifdef __VM_CODEC_SUPPORT__
        case MED_TYPE_GSM_FR:
        case MED_TYPE_GSM_HR:
        case MED_TYPE_GSM_EFR:
        case MED_TYPE_VR:
            vp_param.mediaType = (Media_Format) self_p->media_type;
            vp_param.vmParam = (kal_uint32) MEDIA_VMP_AS_RINGTONE;
            param_p = &vp_param;
            open_fct = VM_Open;
            break;
    #endif /*__VM_CODEC_SUPPORT__*/

    #ifdef WAV_CODEC
        case MED_TYPE_PCM_8K:
        case MED_TYPE_PCM_16K:
        case MED_TYPE_G711_ALAW:
        case MED_TYPE_G711_ULAW:
        case MED_TYPE_DVI_ADPCM:
            vp_param.mediaType = (Media_Format) self_p->media_type;
            vp_param.vmParam = 0;
            param_p = &vp_param;
            open_fct = PCM_Open;
            break;
    #endif /* WAV_CODEC */

    #ifdef AMR_DECODE
        case MED_TYPE_AMR:
    #ifdef AMRWB_DECODE
        case MED_TYPE_AMR_WB:
    #endif /* AMRWB_DECODE */
            vp_param.mediaType = (Media_Format) self_p->media_type;
            vp_param.vmParam = (kal_uint32) MEDIA_VMP_AS_RINGTONE;
            param_p = &vp_param;
            open_fct = AMR_Open;
            break;
    #endif /* AMR_DECODE */
    #ifdef DAF_DECODE
        case MED_TYPE_DAF:
    #ifdef MUSICAM_DECODE
        case MED_TYPE_MUSICAM:
    #endif
            open_fct = DAF_Open;
            break;
    #endif /* DAF_DECODE */ 
    #ifdef WAV_CODEC
        case MED_TYPE_WAV:
        case MED_TYPE_WAV_ALAW:
        case MED_TYPE_WAV_ULAW:
        case MED_TYPE_WAV_DVI_ADPCM:
            open_fct = WAV_Open;
            break;
    #endif /* WAV_CODEC */
    #ifdef AU_DECODE
        case MED_TYPE_AU:
            open_fct = AU_Open;
            break;
    #endif /* AU_DECODE */
    #ifdef AIFF_DECODE
        case MED_TYPE_AIFF:
            open_fct = AIFF_Open;
            break;
    #endif /* AIFF_DECODE */
    #ifdef WMA_DECODE
        case MED_TYPE_WMA:
            open_fct = WMA_Open;
            break;
    #endif /* WMA_DECODE */ 
    #ifdef AAC_DECODE
        case MED_TYPE_AAC:
            open_fct = AAC_Open;
            break;
    #endif /* AAC_DECODE */ 
    #if defined(BSAC_DECODE)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* BSAC_DECODE */

    #ifdef __APE_DECODE__
        case MED_TYPE_APE:
            open_fct = APE_Open;
            break;
    #endif /* __APE_DECODE__ */
    #ifdef __VORBIS_DECODE__
        case MED_TYPE_VORBIS:
            open_fct = VORBIS_Open;
            break;
    #endif /*__OGG_DECODE__*/
    #ifdef __FLAC_DECODE__
        case MED_TYPE_FLAC:
            open_fct = FLAC_Open;
            break;
    #endif

        default:
            med_result = MED_RES_INVALID_FORMAT;
            goto media_open_failed;
    }
    
    /*-------------------------- Setup buffers  -----------------------------*/
    /* Set Buffer to increase read performance */
    if (is_file)
    {
    #if defined(AUD_PROC_USE_EXT_MEM)
        if(cfg_p->cb_fct)
        {
            fsal_buf_p = (kal_uint8*) med_alloc_aud_mem(sizeof(kal_uint8) * AUD_PROC_BUF_SIZE);
        }
        else
        {
            /* if it is for build cache, then alloc memory from topmost to avoid memory fragementation */
            fsal_buf_p = (kal_uint8*) med_alloc_aud_mem_topmost(sizeof(kal_uint8) * AUD_PROC_BUF_SIZE);
        }
    #else
        fsal_buf_p = (kal_uint8*) get_ctrl_buffer(sizeof(kal_uint8) * AUD_PROC_BUF_SIZE);
    #endif

        FSAL_SetBuffer(&self_p->fsal_handle, AUD_PROC_BUF_SIZE, fsal_buf_p);
    }
    /* No need to set buffer for ROM file */
    else
    {
        FSAL_SetBuffer(&self_p->fsal_handle, 0, NULL);
    }

    /* Open a handler */
    if (cfg_p->cb_fct)
    {
        self_p->mhdl_handle_p = open_fct(_aud_player_media_event_callback_fct, &self_p->fsal_handle, param_p);
    }
    else
    {
        /* In case the client doesn't need to received callback events, we should not need to hook callback
         * function to l1audio. This is important especially when two MHdl handlers are possible to be opened
         * concurrently. e.g. Building cache. If we hook callback functions to two MHdl handlers, l1audio will 
         * not be able to distinguish which handler is being played and may fail to callback to correct handler.
         */
        self_p->mhdl_handle_p = open_fct(NULL, &self_p->fsal_handle, param_p);
    }

    if (self_p->mhdl_handle_p == NULL)
    {
        med_result = MED_RES_BAD_FORMAT;
        goto media_open_failed;
    }
    
    _AUD_PLAYER_MEDIA_TRACE(player_p, self_p->media_type, self_p->mhdl_handle_p);
    
    /* Attach user data to MHdl handle */
    self_p->mhdl_handle_p->SetUserData(self_p->mhdl_handle_p, (void*)player_p);
    
    /*------------------------ Setup private data ---------------------------*/
    self_p->state      = AUD_MEDIA_IDLE;
    self_p->start_time = 0;
    self_p->stop_time  = 0;
    self_p->cb_fct     = cfg_p->cb_fct;
    self_p->cb_param   = cfg_p->cb_param;
    
    return MED_RES_OK;

    /*------------------------ Error handling -------------------------------*/
media_open_failed:
    /* Close the media player */
    _aud_player_media_close(player_p);
    
    return med_result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_media_play
 * DESCRIPTION
 *  This function is used to start Media playback.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_media_play(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_media_t* self_p;
    Media_Status            drv_result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(player_p, med_aud_player_media_t, itf);

    /* Directly return if the player is not in idle state */
    if (self_p->state != AUD_MEDIA_IDLE)
    {
        return MED_RES_FAIL;
    }

    /* Allocate ring buffer */
    
    aud_util_alloc_ring_buffer_ext(AUD_RING_BUFFER_SIZE, &self_p->ring_buffer_p);
    self_p->mhdl_handle_p->SetBuffer(self_p->mhdl_handle_p, (kal_uint8*)self_p->ring_buffer_p, AUD_RING_BUFFER_SIZE);

    /* Begin to play */
    drv_result = self_p->mhdl_handle_p->Play(self_p->mhdl_handle_p);
    _AUD_PLAYER_MEDIA1_TRACE(drv_result);

    if (drv_result == MEDIA_SUCCESS)
    {
        /* enter AUD_MEDIA_PLAY state */
	#ifdef __KARAOKE_SUPPORT__
    if(aud_get_karaoke_mode() == MEDIA_KARAPLAY_PLAY_REC_MIX || aud_get_karaoke_mode() == MEDIA_KARAPLAY_REC_MIX_ONLY)
	    _aud_recorder_karaoke_record();
	#endif
        self_p->state = AUD_MEDIA_PLAY;
    }
    else
    {
        /* Free ring buffer if failed to play */
        AUD_PLAYER_FREE_RING_BUF(self_p->ring_buffer_p);
    }
    
    return aud_get_res(drv_result);
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_media_stop
 * DESCRIPTION
 *  This function is used to stop Media playback.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_media_stop(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_media_t* self_p;
    Media_Status drv_result = MEDIA_NO_HANDLER;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(player_p, med_aud_player_media_t, itf);
#ifdef __KARAOKE_SUPPORT__
    _aud_recorder_karaoke_stop();
    g_karaoke_mono=KAL_FALSE;
	#ifdef __KARAOKE_NEED_KEEP_SRC_PATH__
	aud_karaoke_remix_turn_off();
	#endif
#endif
	
    drv_result = self_p->mhdl_handle_p->Stop(self_p->mhdl_handle_p);  
    _AUD_PLAYER_MEDIA1_TRACE(drv_result);
    
    if (drv_result == MEDIA_SUCCESS)
    {
        /* enter AUD_MEDIA_IDLE state */
        self_p->state = AUD_MEDIA_IDLE;
    }

    /* Free ring buffer */
    AUD_PLAYER_FREE_RING_BUF(self_p->ring_buffer_p);
    
    return aud_get_res(drv_result);
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_media_pause
 * DESCRIPTION
 *  This function is used to pause Media playback.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_media_pause(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_media_t* self_p;
    Media_Status            drv_result = MEDIA_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(player_p, med_aud_player_media_t, itf);
    
    /* Pause the play */
    drv_result = self_p->mhdl_handle_p->Pause(self_p->mhdl_handle_p);
    _AUD_PLAYER_MEDIA1_TRACE(drv_result);
    
    if (drv_result == MEDIA_SUCCESS)
    {
        /* enter AUD_MEDIA_PLAY_PAUSED state */
        self_p->state = AUD_MEDIA_PLAY_PAUSED;
    }
    
    return aud_get_res(drv_result);
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_media_resume
 * DESCRIPTION
 *  This function is used to resume Media playback.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_media_resume(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_media_t* self_p;
    Media_Status            drv_result = MEDIA_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(player_p, med_aud_player_media_t, itf);
    
    drv_result = self_p->mhdl_handle_p->Resume(self_p->mhdl_handle_p);
    _AUD_PLAYER_MEDIA1_TRACE(drv_result);
    
    if (drv_result == MEDIA_SUCCESS)
    {
        /* enter AUD_MEDIA_PLAY state */
        self_p->state = AUD_MEDIA_PLAY;
    }
    
    return aud_get_res(drv_result);
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_media_set
 * DESCRIPTION
 *  This function is used to set parameters to a Media player.
 * PARAMETERS
 *  player_p      [IN]        Player handle.
 *  set_type      [IN]        Set command.
 *  data_p        [IN]        The data relative to the command.
 *  date_len      [IN]        The length of the data.
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_media_set(med_aud_player_t*    player_p,
                                       med_aud_player_set_t set_type,
                                       void*                data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_media_t* self_p;
    Media_Status            drv_result = MEDIA_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(player_p, med_aud_player_media_t, itf);

    _AUD_PLAYER_MEDIA2_TRACE(set_type, (kal_uint32)data_p);
    
    switch (set_type)
    {
        case AUD_PLAYER_SET_CACHE_TABLE:
        {
            self_p->mhdl_handle_p->SetCacheTbl(self_p->mhdl_handle_p, (kal_uint8*)((med_aud_player_set_cache_t*)data_p)->cache_p, (kal_uint32)((med_aud_player_set_cache_t*)data_p)->cache_size);
            break;   
        }
        case AUD_PLAYER_SET_BUFFER:
        {
            self_p->mhdl_handle_p->SetBuffer(self_p->mhdl_handle_p, (kal_uint8*)((med_aud_player_set_buffer_t*)data_p)->buffer_p, (kal_uint32)((med_aud_player_set_buffer_t*)data_p)->buffer_size);
            break;
        }
        case AUD_PLAYER_SET_START_TIME:
        {
            kal_uint32 start_time = (kal_uint32)data_p;
            
            drv_result = self_p->mhdl_handle_p->SetStartTime(self_p->mhdl_handle_p, start_time);
            
            if (drv_result == MEDIA_SUCCESS)
            {
                self_p->start_time = start_time;
            }
            
            break;
        }
        case AUD_PLAYER_SET_STOP_TIME:
        {
            kal_uint32 stop_time = (kal_uint32)data_p;
            
            drv_result = self_p->mhdl_handle_p->SetStopTime(self_p->mhdl_handle_p, stop_time);
            
            if (drv_result == MEDIA_SUCCESS)
            {
                self_p->stop_time = stop_time;
            }
            
            break;
        }
        case AUD_PLAYER_SET_STORE_FLAG:
        {
            self_p->mhdl_handle_p->SetStoreFlag(self_p->mhdl_handle_p, (kal_bool)(kal_uint32)data_p);
            break;   
        }
        case AUD_PLAYER_SET_FILE_OFFSET:
        {
            self_p->mhdl_handle_p->SetFileOffset(self_p->mhdl_handle_p, (kal_uint32)data_p);
            break;   
        }
        case AUD_PLAYER_SET_LEVEL:
        {
            self_p->mhdl_handle_p->SetLevel(self_p->mhdl_handle_p, (kal_uint8)(kal_uint32)data_p);
            break;
        }
        
        /* Unsupported commands */
        default:
            drv_result = MEDIA_UNSUPPORTED_OPERATION;
            break;
    }
    
    return aud_get_res(drv_result);
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_media_get
 * DESCRIPTION
 *  This function is used to get parameters from a Media player.
 * PARAMETERS
 *  player_p      [IN]        Player handle.
 *  get_type      [IN]        Get command.
 *  data_p        [OUT]       The data relative to the command.
 *  data_len      [IN]        Indicats the length of the data buffer.
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_media_get(med_aud_player_t*    player_p,
                                       med_aud_player_get_t get_type,
                                       void*                data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_media_t* self_p;
    Media_Status            drv_result;
    kal_int32               med_result = MED_RES_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(player_p, med_aud_player_media_t, itf);
    
    switch (get_type)
    {
        case AUD_PLAYER_GET_START_TIME:
        {
            {
                *((kal_uint32*)data_p) = self_p->start_time;
            }
            
            break;
        }
        case AUD_PLAYER_GET_STOP_TIME:
        {
            {
                *((kal_uint32*)data_p) = self_p->stop_time;
            }
            
            break;
        }              
        case AUD_PLAYER_GET_CURRENT_TIME:
        case AUD_PLAYER_GET_LAST_TIME:
        {
            {
                *((kal_uint32*)data_p) = self_p->mhdl_handle_p->GetCurrentTime(self_p->mhdl_handle_p);
            }
            
            break;
        }
        case AUD_PLAYER_GET_DURATION:
        {
            {
                *((kal_uint32*)data_p) = self_p->mhdl_handle_p->GetTotalDuration(self_p->mhdl_handle_p);
            }
            
            break;
        }
        case AUD_PLAYER_GET_LAST_OFFSET:
        {
            {
                *((kal_uint32*)data_p) = self_p->mhdl_handle_p->GetFileOffset(self_p->mhdl_handle_p);
            }
            
            break;
        }

        case AUD_PLAYER_GET_CONTENT_DESC:
        {
            {
                med_result = _aud_player_media_get_content_desc(player_p, (audInfoStruct*)data_p);  
            }
            
            break;
        }

        case AUD_PLAYER_GET_MHDL_HANDLE:
        {
            {
                *((MHdl**)data_p) = self_p->mhdl_handle_p;
            }

            break;
        }

        /* Media player specific commands */
    #ifndef MED_V_NOT_PRESENT
        case MEDIA_PLAYER_GET_BUILD_CACHE_PROGRESS:
        {
            {
                self_p->mhdl_handle_p->BuildCache(self_p->mhdl_handle_p, &drv_result, (kal_uint32*)data_p, (kal_bool)(!aud_build_cache_is_seeking()));
                med_result = aud_get_res(drv_result);

            }
            
            break;
        }
        case MEDIA_PLAYER_GET_BUILD_CACHE_DURATION:
        {
            {
                *((kal_uint32*)data_p) = self_p->mhdl_handle_p->GetCacheDuration(self_p->mhdl_handle_p);
            }
            
            break;
        }
    #endif /* #ifndef MED_V_NOT_PRESENT */
    
    #ifdef __MED_MMA_MOD__
        case MEDIA_PLAYER_GET_IS_REACH_VALID_REGION:
        {
            {
                /* Allocate working buffer if required */
                if (self_p->ring_buffer_p == NULL)
                {
                    aud_util_alloc_ring_buffer_ext(AUD_RING_BUFFER_SIZE, &self_p->ring_buffer_p);
                    self_p->mhdl_handle_p->SetBuffer(self_p->mhdl_handle_p, (kal_uint8*)self_p->ring_buffer_p, AUD_RING_BUFFER_SIZE);

                    /* Check if reach valid region */
                    drv_result = self_p->mhdl_handle_p->ReachValidRegion(self_p->mhdl_handle_p);

                    /* Remember to free the temp working buffer */
                    AUD_PLAYER_FREE_RING_BUF(self_p->ring_buffer_p);
                }
                else /* MMI may get download percentage when pause a playback. In this case, we should not re-allocate ring buffer */
                {
                    /* Check if reach valid region */
                    drv_result = self_p->mhdl_handle_p->ReachValidRegion(self_p->mhdl_handle_p);
                }

                if (drv_result == MEDIA_FILE_INCOMPLETE)
                {
                    *((kal_uint32*)data_p) = KAL_FALSE;
                }
                else
                {
                    *((kal_uint32*)data_p) = KAL_TRUE;
                }

            }
            
            break;
        }
    #endif /* __MED_MMA_MOD__ */
        
        /* Unsupported commands */
        default:
            med_result = MED_RES_UNSUPPORTED_OPERATION;
            break;
    }

    _AUD_PLAYER_MEDIA_TRACE(get_type, med_result, *((kal_uint32*)data_p));
    
    return med_result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_player_media_destroy
 * DESCRIPTION
 *  This function is used to destroy a Media player. Once called, all the 
 *  allocated interfaces of the player will be freed.
 * PARAMETERS
 *  player_p      [IN]        Player handle. 
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 _aud_player_media_destroy(med_aud_player_t* player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_media_t* self_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_p = PTHIS(player_p, med_aud_player_media_t, itf);
    
    AUD_PLAYER_FREE_AUD_MEM(self_p);
    
    return MED_RES_OK;
}
#endif /* __MTK_TARGET__ */

/*-----------------------------------------------------------------------------
                    public functions
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  aud_player_media_construct
 * DESCRIPTION
 *  This function is used to construct a Media player.
 * PARAMETERS
 *  void
 * RETURNS
 *  Player handle.
 *****************************************************************************/
med_aud_player_t* aud_player_media_construct(void)
{
#if defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_media_t* self_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // Allow tone play when open audio, shall add memory if memory fragement happened in the future
    //DTMF_MCU_StopAndWait();
    //KT_StopAndWait();
    //TONE_StopAndWait();
    /* alloc from topmost to avoid memory fragementation for build cache case */
    self_p = (med_aud_player_media_t*) med_alloc_aud_mem_topmost(sizeof(med_aud_player_media_t));
    MED_ASSERT(self_p != NULL);

    kal_mem_set(self_p, 0, sizeof(*self_p));

    self_p->itf.open     = _aud_player_media_open;
    self_p->itf.close    = _aud_player_media_close;
    self_p->itf.play     = _aud_player_media_play;
    self_p->itf.stop     = _aud_player_media_stop;
    self_p->itf.pause    = _aud_player_media_pause;
    self_p->itf.resume   = _aud_player_media_resume;
    self_p->itf.set      = _aud_player_media_set;
    self_p->itf.get      = _aud_player_media_get;
    self_p->itf.destroy  = _aud_player_media_destroy;

    kal_get_time(&self_p->time_stamp);

    return &self_p->itf;
#else
    return NULL;
#endif /* __MTK_TARGET__ */
}

#endif /* MED_NOT_PRESENT */ 

