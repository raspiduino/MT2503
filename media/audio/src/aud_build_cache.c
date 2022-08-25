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
 * Aud_build_cache.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes functions for audio cache building.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_V_NOT_PRESENT

/*==== INCLUDES =========*/

//#include "kal_release.h"
#include "kal_trace.h"
//#include "stack_common.h"
//#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
//#include "time.h"
/* Buffer Management */
//#include "app_buff_alloc.h"
//#include "syscomp_config.h"
//#include "task_config.h"        /* Task creation */
//#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
//#include "event_shed.h" /* Event scheduler */
//#include "stack_timer.h"        /* Stack timer */
/* for tst inject message */
//#include "tst_sap.h"

/* global includes */
//#include "l1audio.h"
//#include "device.h"
//#include "resource_audio.h"
//#include "nvram_enums.h"
//#include "nvram_struct.h"
//#include "nvram_user_defs.h"
//#include "nvram_data_items.h"
//#include "custom_nvram_editor_data_item.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_v_struct.h"
//#include "med_struct.h"
//#include "med_api.h"
#include "med_context.h"
#include "aud_main.h"
#include "med_main.h"
//#include "fat_fs.h"
#include "med_utility.h"
#include "med_v_main.h"
#include "med_v_context.h"
#include "aud_player.h"
#include "aud_player_media.h"

#include "kal_general_types.h"
#include "stack_config.h"
#include "kal_public_api.h"
#include "med_smalloc.h"
#include "kal_public_defs.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#ifndef MED_MODEM    
#include "Mmi_frm_event_flag_gprot.h"
#endif

/*-----------------------------------------------------------------------------
                    macros, defines, typedefs, enums
-----------------------------------------------------------------------------*/
#define _AUD_MODULE_BUILD_CACHE_TRACE(x, y, z)   AUD_MODULE_BUILD_CACHE_TRACE(x, y, z, __LINE__)
#define _AUD_MODULE_BUILD_CACHE2_TRACE(x, y)     AUD_MODULE_BUILD_CACHE2_TRACE(x, y, __LINE__)
#define _AUD_MODULE_BUILD_CACHE1_TRACE(x)        AUD_MODULE_BUILD_CACHE1_TRACE(x, __LINE__)

#define AUD_BUILD_CACHE_BUFFER_SIZE              (AUD_MED_BUILD_CACHE_BUF_SIZE)
#define BUILD_CACHE_LOCK      do { if (g_build_cache_mutex){kal_take_mutex(g_build_cache_mutex);}} while(0)
#define BUILD_CACHE_UNLOCK    do { if (g_build_cache_mutex){kal_give_mutex(g_build_cache_mutex);}} while(0)

typedef struct
{
    kal_uint16              counter;     /* Counter */
    kal_uint32*             progress_p;  /* Build cache prgress */
    kal_uint32              seek_pos;    /* The position to be sought to */
    medv_audio_seek_cb_fct  cb_fct;      /* Callback function */
    void*                   cb_param;    /* Callback parameter */
    
} aud_build_cache_req_struct_t;

/*-----------------------------------------------------------------------------
                    data declaraions
 ----------------------------------------------------------------------------*/
static med_aud_player_t* g_player_p = NULL; /* Player handle */
static module_type g_src_mod_id = MOD_NIL;  /* Source module ID */
static void* g_proc_buf_p = NULL;           /* Working buffer */
static kal_uint32 g_cache_duration = 0;     /* The cache duration which has been built. */
static kal_uint32 g_total_duration = 0;     /* The total duration of the file which will be updated as the build cache progresses. */
static kal_uint16 g_counter = 0;            /* A counter to indicate which round of build cache is being performed. */
static kal_bool   g_is_running = KAL_FALSE; /* A flag to indicate if the build cache is running. */
static kal_bool   g_is_seeking = KAL_FALSE; /* A flag to indicate if it's seeking */
static aud_build_cache_req_struct_t g_build_cache_req;
static kal_mutexid g_build_cache_mutex = 0;

/*-----------------------------------------------------------------------------
                    private function declarations
 ----------------------------------------------------------------------------*/

/*****************************************************************************
 * FUNCTION
 *  _aud_build_cache_close
 * DESCRIPTION
 *  This function is to close a build cache process. All allocated resources should
 *  be freed here.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_build_cache_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Close the player */
    if (g_player_p)
    {
        g_player_p->close(g_player_p);
        g_player_p->destroy(g_player_p);
        g_player_p = NULL;
    }

    /* Free working buffer */
    if (g_proc_buf_p)
    {
        med_free_aud_mem((void**)&g_proc_buf_p);
        g_proc_buf_p = NULL;
    }

    /* Reset source module ID */
    g_src_mod_id = MOD_NIL;

    /* Turn off flag to indicate the building cache process is stopped */
    g_is_running = KAL_FALSE;

    /* Increase counter */
    g_counter ++;
}


/*****************************************************************************
 * FUNCTION
 *  _aud_build_cache_process_func
 * DESCRIPTION
 *  This function is to update build cache progress, cache duration and total
 *  duration.
 * PARAMETERS
 *  data_p      [IN]    Build cache data.
 *  data_len    [IN]    The lenght of data.
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_build_cache_process_func(void* data_p, kal_uint16 date_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    kal_uint32 progress = 0;
    aud_build_cache_req_struct_t* build_cache_req_p = (aud_build_cache_req_struct_t*)data_p;

#if  ((!defined( MED_MODEM)) && (!defined(EMPTY_MMI)))   
	kal_uint32 event = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* med_v's priority is hihger than NVRAM, to avoid mmi being blocked by nvram which is blocked by med_v build cache, 
       before build cache started, wait mmi NVRAM flag to be turned on*/
	retrive_mmi_event_flag(MMI_EVT_F_NOT_IN_NVRAM, MMI_EVENT_FLAG_AND, &event);
#endif

    /* Check if the counter matches with current counter */
    if ((g_player_p != NULL) && 
        (g_is_running == KAL_TRUE) &&
        (g_counter == build_cache_req_p->counter))
    {
        /* Lock build cache to prevent the build cache buffer from being freed when it's in use */
        BUILD_CACHE_LOCK;
        
        /* Update build cache progress */
        result = g_player_p->get(g_player_p, (med_aud_player_get_t)MEDIA_PLAYER_GET_BUILD_CACHE_PROGRESS, &progress);
        _AUD_MODULE_BUILD_CACHE2_TRACE(result, progress);

        if (result == MED_RES_OK)
        {
            /* Update progress */
            if (build_cache_req_p->progress_p)
            {
                *build_cache_req_p->progress_p = progress;
            }
            
            /* Update cache duration and total duration */
            result = g_player_p->get(g_player_p, (med_aud_player_get_t)MEDIA_PLAYER_GET_BUILD_CACHE_DURATION, &g_cache_duration);
            _AUD_MODULE_BUILD_CACHE2_TRACE(result, g_cache_duration);
            result = g_player_p->get(g_player_p, AUD_PLAYER_GET_DURATION, &g_total_duration);
            _AUD_MODULE_BUILD_CACHE2_TRACE(result, g_total_duration);
            
            /* Unlock build cache when there is no access to the build cache buffer */
            BUILD_CACHE_UNLOCK;

            /* Check if reach the position to be sought to */
            if ((g_is_seeking) &&
                (g_cache_duration >= build_cache_req_p->seek_pos))
            {
                /* Seek done */
                if (build_cache_req_p->cb_fct)
                {
                    build_cache_req_p->cb_fct(AUD_SEEK_REASON_DONE, build_cache_req_p->cb_param);
                    _AUD_MODULE_BUILD_CACHE_TRACE(build_cache_req_p->seek_pos, g_cache_duration, g_total_duration);
                }

                g_is_seeking = KAL_FALSE;

                /* Close build cache handler */
                _aud_build_cache_close();

                return;
            }

            /* Check build cache progress */
            if (progress < 100)
            {
                if (g_is_running)
                {
                    /* To prevent med_v from keeping running. The lower priority
                     * task may have opportunity to do thier job.
                     */
                #if !defined(LOW_COST_SUPPORT)
                    kal_sleep_task(2);
                #else
                    if(g_is_seeking)
                    {
                        kal_sleep_task(2);
                    }
                    else
                    {
                        kal_sleep_task(20);
                    }
                #endif

                    /* Continue build cache processes */
                    aud_util_proc_in_med_v_ext(MOD_MED_V,
                                               _aud_build_cache_process_func,
                                               (void*)build_cache_req_p,
                                               sizeof(aud_build_cache_req_struct_t));
                }
            }
            else /* Build cache is completed */
            {
                /* Notify client the seeking/build cache is done */
                if (build_cache_req_p->cb_fct)
                {
                    build_cache_req_p->cb_fct(AUD_SEEK_REASON_DONE, build_cache_req_p->cb_param);
                    _AUD_MODULE_BUILD_CACHE_TRACE(build_cache_req_p->seek_pos, g_cache_duration, g_total_duration);
                }

                /* Reset seeking flag */
                g_is_seeking = KAL_FALSE;
                
                /* Send update duration indicator to MMI */
                aud_send_update_duration_ind(g_total_duration);

                /* Close build cache handler */
                _aud_build_cache_close();
            }
        }
        else /* Build cache failed */
        {
            /* Remember to unlock the build cache if failed */
            BUILD_CACHE_UNLOCK;
            
            if (g_src_mod_id == MOD_MMI) /* If this is a building cache request from MMI */
            {
                /* Notify MMI the build cache process is failed */
                aud_send_build_cache_fail_ind();
            }

            /* Failed to seek */
            if (g_is_seeking)
            {
                if (build_cache_req_p->cb_fct)
                {
                    build_cache_req_p->cb_fct(AUD_SEEK_REASON_FAIL, build_cache_req_p->cb_param);
                }

                g_is_seeking = KAL_FALSE;
            }

            /* Close build cache handler */
            _aud_build_cache_close();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  _aud_build_cache_start
 * DESCRIPTION
 *  This function is to start a building cache process
 * PARAMETERS
 *  file_name     [IN]      The file to be built.
 *  cache_p       [IN]      Cache data.
 *  cache_size    [IN]      The size of cache data.
 *  proc_buf_p    [IN]      FS buffer.
 *  proc_buf_size [IN]      The size of FS buffer.
 *  seek_pos      [IN]      The position to seek to.
 *  cb_fct        [IN]      Callback function.
 *  cb_param      [IN]      Callback parameter.
 *  progress_p    [OUT]     Build cache progress.
 * RETURNS
 *  MED_RES_OK      Successfully.
 *  Others          Failed.
 *****************************************************************************/
static kal_int32 _aud_build_cache_start(kal_wchar*              file_name,
                                        void*                   cache_p,
                                        kal_int32               cache_size,
                                        void*                   proc_buf_p,
                                        kal_int32               proc_buf_size,
                                        kal_uint32              seek_pos,
                                        medv_audio_seek_cb_fct  cb_fct,
                                        void*                   cb_param,
                                        kal_uint32*             progress_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_OK;
    med_aud_player_cfg_t player_cfg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Create build cache mutex */
    if (g_build_cache_mutex == 0)
    {
        g_build_cache_mutex = kal_create_mutex("build_cache_mutex");
    }

    if (g_player_p == NULL)
    {
        /* Construct a media player */
        g_player_p = aud_player_media_construct();

        if (g_player_p != NULL)
        {
            /* Configure the player */
            player_cfg.file_name   = file_name;
            player_cfg.data_p      = NULL;
            player_cfg.data_len    = 0;
            player_cfg.format      = 0; /* Don't care */
            player_cfg.repeat      = 0; /* Don't care */
            player_cfg.audio_path  = 0; /* Don't care */
            player_cfg.fast_pass   = KAL_FALSE;
            player_cfg.cb_fct      = NULL; /* DO NOT hook callback */
            player_cfg.cb_param    = NULL; /* Don't care since no callback */
            
            /* Open a player */
            result = g_player_p->open(g_player_p, &player_cfg);
            _AUD_MODULE_BUILD_CACHE1_TRACE(result);

            if (result == MED_RES_OK) /* Open successful */
            {
                /* Set cache table */
                med_aud_player_set_cache_t set_cache;
                med_aud_player_set_buffer_t set_buf;
                set_cache.cache_p = cache_p;
                set_cache.cache_size = cache_size;
                result = g_player_p->set(g_player_p, AUD_PLAYER_SET_CACHE_TABLE, (void*)&set_cache);
                _AUD_MODULE_BUILD_CACHE1_TRACE(result);

                if (proc_buf_p != NULL)
                {
                    /* Use input buffer */
                    set_buf.buffer_p = proc_buf_p;
                    set_buf.buffer_size = proc_buf_size;
                }
                else
                {
                    kal_uint32 mem_size;
                        
                    /* Allocate buffer from topmost to avoid memory fragementation */
                    if(AUD_IN_STATE(AUD_MEDIA_IDLE)
                #if defined( __MED_MMA_MOD__)&&(!defined (__MED_SLIM_MMA__))
                       && !aud_mma_is_playing(AUD_MMA_CHECK_MODE_SINGLE)
                #endif
                    )
                    {
                        mem_size = AUD_MED_BUILD_CACHE_NORMAL_BUF_SIZE;
                    }
                    else
                    {
                        mem_size = AUD_MED_BUILD_CACHE_BUF_SIZE;
                    }
                    
                    g_proc_buf_p = (void*)med_alloc_aud_mem_topmost(mem_size);
                    MED_ASSERT(g_proc_buf_p != NULL);
                    set_buf.buffer_p = g_proc_buf_p;
                    set_buf.buffer_size = mem_size;
                }
                
                result = g_player_p->set(g_player_p, AUD_PLAYER_SET_BUFFER, (void*)&set_buf);
               _AUD_MODULE_BUILD_CACHE1_TRACE(result);

            }
            else /* Open failed */
            {
                /* Close the player */
                g_player_p->close(g_player_p);
                g_player_p->destroy(g_player_p);
                g_player_p = NULL;
            }
        }
    }
    
    /* Start building cache */
    if (g_player_p && (!g_is_running))
    {
        g_build_cache_req.counter    = g_counter;
        g_build_cache_req.progress_p = progress_p;
        g_build_cache_req.seek_pos   = seek_pos;
        g_build_cache_req.cb_fct     = cb_fct;
        g_build_cache_req.cb_param   = cb_param;
            
        aud_util_proc_in_med_v_ext(MOD_MED_V,
                                   _aud_build_cache_process_func,
                                   (void*)&g_build_cache_req,
                                   sizeof(aud_build_cache_req_struct_t));

        /* Turn on flag indicating the building cache process is running */
        g_is_running = KAL_TRUE;
    }

    return result;
}


/*-----------------------------------------------------------------------------
                    public functions
 ----------------------------------------------------------------------------*/

/*****************************************************************************
 * FUNCTION
 *  aud_build_cache_is_seeking
 * DESCRIPTION
 *  This function is to query if it is seeking action now
 *  stopped.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool aud_build_cache_is_seeking(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_is_seeking;
}

/*****************************************************************************
 * FUNCTION
 *  aud_build_cache_stop
 * DESCRIPTION
 *  This function is to singal that the building cache process is already
 *  stopped.
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
void aud_build_cache_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BUILD_CACHE_LOCK;


    /* Notify client the seeking process is terminated */
    if (g_is_seeking)
    {
        if (g_build_cache_req.cb_fct)
        {
            g_build_cache_req.cb_fct(AUD_SEEK_REASON_TERMINATED, g_build_cache_req.cb_param);
        }

        g_is_seeking = KAL_FALSE;
    }
    
    /* Turn off flag to indicate the building cache process is stopped */
    g_is_running = KAL_FALSE;

    /* Increase counter */
    g_counter ++;

    BUILD_CACHE_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  aud_build_cache_start_seek_req_hdlr
 * DESCRIPTION
 *  This function is to start seeking.
 * PARAMETERS
 *  ilm_ptr     [IN]    Seeking parameter.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_build_cache_start_seek_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_audio_start_seek_req_struct *msg_p = (media_audio_start_seek_req_struct*)ilm_ptr->local_para_ptr;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MTK_TARGET__
    if (aud_media_is_build_cache_required(msg_p->file_name) && (msg_p->seek_pos > 0))
    {
        /* Stop last build cache process */
        aud_build_cache_stop();

        /* Close build cache handler if source module is unmatched */
        if (g_src_mod_id != ilm_ptr->src_mod_id)
        {
            _aud_build_cache_close();
        }
    
        /* Keep source module ID */
        g_src_mod_id = ilm_ptr->src_mod_id;
        
        /* Start seeking */
        result = _aud_build_cache_start(msg_p->file_name,
                                        msg_p->cache_p,
                                        msg_p->cache_size,
                                        msg_p->proc_buf_p,
                                        msg_p->proc_buf_size,
                                        msg_p->seek_pos,
                                        msg_p->cb_fct,
                                        msg_p->cb_param,
                                        NULL);

        if (result == MED_RES_OK)
        {
            g_is_seeking = KAL_TRUE;
        }
        else
        {
            /* Notify client that the seeking is failed */
            if (msg_p->cb_fct)
            {
                msg_p->cb_fct(AUD_SEEK_REASON_FAIL, msg_p->cb_param);
            }
        }
    }
    else
#endif /* __MTK_TARGET__ */
    {
        /* Notify client that the seeking is done */
        if (msg_p->cb_fct)
        {
            msg_p->cb_fct(AUD_SEEK_REASON_DONE, msg_p->cb_param);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_build_cache_stop_seek_req_hdlr
 * DESCRIPTION
 *  This function is to stop seeking.
 * PARAMETERS
 *  ilm_ptr     [IN]    No used.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_build_cache_stop_seek_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    if (g_is_seeking)
    {
        /* Stop last build cache process */
        aud_build_cache_stop();

        if (g_src_mod_id == ilm_ptr->src_mod_id)
        {
            _aud_build_cache_close();
        }

        g_is_seeking = KAL_FALSE;
    }
#endif /* __MTK_TARGET__*/

    AUD_CACHE_SET_EVENT(AUD_CACHE_EVT_STOP_SEEK);
}


/*****************************************************************************
 * FUNCTION
 *  aud_build_cache_async_start_req_hdlr
 * DESCRIPTION
 *  This function is used to start seeking in asynchrons manner.
 * PARAMETERS
 *  ilm_ptr     [IN]    Asynchronous seeking parameters.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_build_cache_async_start_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_audio_cache_async_req_struct *msg_p = (media_visual_audio_cache_async_req_struct*)ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MTK_TARGET__
    /* Stop last build cache process */
    aud_build_cache_stop();

    /* Close build cache handler. This is important because clients may use different cache table. */
    _aud_build_cache_close();

    /* Keep source module ID */
    g_src_mod_id = ilm_ptr->src_mod_id;
    
    /* Start building cache */
    _aud_build_cache_start(msg_p->file_name,
                           msg_p->cache_p,
                           msg_p->cache_size,
                           NULL,
                           0,
                           0,
                           msg_p->cb_fct,
                           msg_p->cb_param,
                           NULL);
#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  aud_build_cache_async_close_req_hdlr
 * DESCRIPTION
 *  This function is to handle a request to close building cache in asynchrons
 *  manner.
 * PARAMETERS
 *  ilm_ptr     [IN]    No used.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_build_cache_async_close_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MTK_TARGET__
    if (g_src_mod_id == ilm_ptr->src_mod_id)
    {
        _aud_build_cache_close();
    }
#endif /* __MTK_TARGET__*/
}


/*****************************************************************************
 * FUNCTION
 *  aud_build_cache_start_req_hdlr
 * DESCRIPTION
 *  This function is to handle a request to start building cache.
 * PARAMETERS
 *  ilm_ptr     [IN]    Build cache parameters.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_build_cache_start_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_audio_cache_req_struct *msg_p = (media_visual_audio_cache_req_struct*)ilm_ptr->local_para_ptr;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MTK_TARGET__
    /* Stop last build cache process */
    aud_build_cache_stop();

    /* Close build cache handler if source module is unmatched */
    if (g_src_mod_id != ilm_ptr->src_mod_id)
    {
        _aud_build_cache_close();
    }

    /* Keep source module ID */
    g_src_mod_id = ilm_ptr->src_mod_id;
    
    /* Start building cache */
    result = _aud_build_cache_start(msg_p->filename,
                                    msg_p->cache_p,
                                    msg_p->cache_size,
                                    msg_p->proc_buf_p,
                                    msg_p->proc_buf_size,
                                    0,
                                    NULL,
                                    NULL,
                                    msg_p->build_cache_progress);

    if (result != MED_RES_OK)
    {
        /* Notify MMI the build cache process is failed */
        aud_send_build_cache_fail_ind();
    }
#endif /* __MTK_TARGET__ */

    AUD_CACHE_SET_EVENT(AUD_CACHE_EVT_START);
}


/*****************************************************************************
 * FUNCTION
 *  aud_build_cache_stop_req_hdlr
 * DESCRIPTION
 *  This function is to handle a request to stop building cache.
 * PARAMETERS
 *  ilm_ptr     [IN]    No used.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_build_cache_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__    
    aud_build_cache_stop();
#endif /* __MTK_TARGET__*/

    AUD_CACHE_SET_EVENT(AUD_CACHE_EVT_STOP);
}


/*****************************************************************************
 * FUNCTION
 *  aud_build_cache_close_req_hdlr
 * DESCRIPTION
 *  This function is to handle a request to close building cache.
 * PARAMETERS
 *  ilm_ptr     [IN]    No used.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_build_cache_close_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MTK_TARGET__
    if (g_src_mod_id == ilm_ptr->src_mod_id)
    {
        _aud_build_cache_close();
    }
#endif /* __MTK_TARGET__*/

    AUD_CACHE_SET_EVENT(AUD_CACHE_EVT_CLOSE);
}


/*****************************************************************************
 * FUNCTION
 *  aud_build_cache_reset_req_hdlr
 * DESCRIPTION
 *  This function is to handle a request to reset building cache parameters.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_build_cache_reset_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Since the context of cable table is reset. It's important to stop
     * the build cache process. Otherwise, data abort may arise.
     */
    _aud_build_cache_close();
    
    /* Reset duration */
    g_cache_duration = 0;
    g_total_duration = 0;

    AUD_CACHE_SET_EVENT(AUD_CACHE_EVT_RESET);
}


/*****************************************************************************
 * FUNCTION
 *  medv_audio_get_cache_duration
 * DESCRIPTION
 *  This function is used to get the duration of build cache. The duration should
 *  be less than or equal to total duration.
 * PARAMETERS
 *  duration      [OUT]     Build cache duration.
 * RETURNS
 *  TRUE        Have cache duration.
 *  FALSE       Don't have cache duration.
 *****************************************************************************/
kal_bool medv_audio_get_cache_duration(kal_uint32 *duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cache_duration > 0)
    {
        *duration = g_cache_duration;
        return KAL_TRUE ;
    }
    else
    {
        return KAL_FALSE ;
    }
}


/*****************************************************************************
 * FUNCTION
 *  medv_audio_get_total_duration
 * DESCRIPTION
 *  This function is used to get the total duration of the file being played.
 *  The duration should be more exact as building cache.
 * PARAMETERS
 *  duration      [OUT]     Total duration.
 * RETURNS
 *  TRUE        Have total duration.
 *  FALSE       Don't have total duration.
 *****************************************************************************/
kal_bool medv_audio_get_total_duration(kal_uint32 *duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_total_duration > 0)
    {
        *duration = g_total_duration;
        return KAL_TRUE ;
    }
    else
    {
        return KAL_FALSE ;
    }
}


/*****************************************************************************
 * FUNCTION
 *  medv_run_low_priority_api
 * DESCRIPTION
 *  This function is to run low priority api by using MED-V task. Note that 
 *  we could use aud_util_proc_in_med_v API instead.
 * PARAMETERS
 *  ilm_ptr
 * RETURNS
 *  void
 *****************************************************************************/
void medv_run_low_priority_api(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_run_low_priority_process_struct *msg_p = (media_visual_run_low_priority_process_struct*)ilm_ptr->local_para_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(msg_p->func_p != NULL)
    {
        msg_p->func_p();
    }
    aud_send_run_low_priority_in_medv_cnf(ilm_ptr->src_mod_id);
}


#endif /* MED_V_NOT_PRESENT */ 

