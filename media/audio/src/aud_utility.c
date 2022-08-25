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
 * aud_utility.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes common used functions of audio manager task.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

/*-----------------------------------------------------------------------------
                    include files
-----------------------------------------------------------------------------*/

//#include "kal_release.h"
#include "kal_trace.h"
//#include "stack_common.h"
//#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
/* Buffer Management */
//#include "app_buff_alloc.h"
//#include "syscomp_config.h"
//#include "task_config.h"        /* Task creation */
//#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
//#include "event_shed.h" /* Event scheduler */
//#include "stack_timer.h"        /* Stack timer */
/* for tst inject message */
#include "tst_sap.h"

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
//#include "nvram_enums.h"
//#include "nvram_struct.h"
//#include "nvram_user_defs.h"
//#include "nvram_data_items.h"
//#include "custom_nvram_editor_data_item.h"
//#include "drm_gprot.h"

/* local includes */
#include "med_global.h"
//#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "aud_main.h"
#include "med_main.h"
//#include "fat_fs.h"
#include "med_utility.h"
#include "mpl_player.h"
#include "mpl_parser.h"
#include "aud_player.h"
#include "aud_player_media.h"

#include "kal_general_types.h"
#include "fs_type.h"
#include "kal_public_api.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "string.h"
#include "med_trc.h"
#include "stack_config.h"

extern kal_int16 med_get_media_type(kal_wchar *file_name);
extern const device_tones_struct *mtk_resource_tones[];

/*-----------------------------------------------------------------------------
                    macros, defines, typedefs, enums
-----------------------------------------------------------------------------*/
#define _AUD_MODULE_UTILITY2_TRACE(x, y)    AUD_MODULE_UTILITY2_TRACE(x, y, __LINE__)
#define _AUD_MODULE_UTILITY1_TRACE(x)       AUD_MODULE_UTILITY1_TRACE(x, __LINE__)

/*-----------------------------------------------------------------------------
                    data declaraions
 ----------------------------------------------------------------------------*/
/* MED audio resource variable */
device_tones_struct **resource_tones = (device_tones_struct **) mtk_resource_tones;

/*****************************************************************************
 * FUNCTION
 *  aud_audio_out_dev_convert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  speaker_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 aud_audio_out_dev_convert(kal_uint8 speaker_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 audio_device_out = L1SP_SPEAKER1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (speaker_id)
    {
        case AUDIO_DEVICE_SPEAKER2:
            audio_device_out = L1SP_SPEAKER2;
            break;
        case AUDIO_DEVICE_LOUDSPEAKER:
            audio_device_out = L1SP_LOUD_SPEAKER;
            break;
        case AUDIO_DEVICE_SPEAKER_BOTH:
            audio_device_out = L1SP_LOUD_SPEAKER | L1SP_SPEAKER2;
            break;
        case AUDIO_DEVICE_BUZZER:
            audio_device_out = L1SP_LOUD_SPEAKER;
            break;
        default:
            break;
    }

    return audio_device_out;
}


/*****************************************************************************
 * FUNCTION
 *  aud_get_res
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 aud_get_res(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
        case MEDIA_SUCCESS:
            return MED_RES_OK;
        case MEDIA_FAIL:
            return MED_RES_FAIL;
        case MEDIA_BAD_FORMAT:
        case MEDIA_BAD_PARAMETER:
            return MED_RES_BAD_FORMAT;
        case MEDIA_BAD_COMMAND:
        case MEDIA_REENTRY:
            return MED_RES_BUSY;
        case MEDIA_NO_HANDLER:
            return MED_RES_NO_HANDLE;
        case MEDIA_UNSUPPORTED_CHANNEL:
            return MED_RES_UNSUPPORTED_CHANNEL;
        case MEDIA_UNSUPPORTED_FREQ:
            return MED_RES_UNSUPPORTED_FREQ;
        case MEDIA_UNSUPPORTED_TYPE:
            return MED_RES_UNSUPPORTED_TYPE;
        case MEDIA_UNSUPPORTED_OPERATION:
            return MED_RES_UNSUPPORTED_OPERATION;
        case MEDIA_SEEK_EOF:
            return MED_RES_END_OF_FILE;
        default:
            return MED_RES_FAIL;

    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_check_disc_space
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dir_name        [?]         
 *  free_byte       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 aud_check_disc_space(kal_wchar *dir_name, kal_int32 free_byte)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    FS_DiskInfo disc_info;
    kal_wchar dir[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(dir, 0, 8);
    kal_mem_cpy(dir, dir_name, 6);
    /* check the available free space */
    result = FS_GetDiskInfo((kal_wchar*) dir, &disc_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

#ifdef __MTK_TARGET__
    if (result > 0 && result & (FS_DI_BASIC_INFO | FS_DI_FREE_SPACE))
#else /* __MTK_TARGET__ */ 
    if (result >= 0)
#endif /* __MTK_TARGET__ */ 
    {
        if ((disc_info.FreeClusters * disc_info.SectorsPerCluster * disc_info.BytesPerSector) < free_byte)
        {
            return MED_RES_DISC_FULL;
        }
        else
        {
            return MED_RES_OK;
        }
    }
    else
    {
        return MED_RES_NO_DISC;
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_create_full_path_folder
 * DESCRIPTION
 *  check or make dir along the assigned path
 * PARAMETERS
 *  filepath        [?]     
 * RETURNS
 *  int
 *****************************************************************************/
int aud_create_full_path_folder(kal_uint16 *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 *filepath_p = filepath;
    kal_int32 fs_ret = FS_FILE_EXISTS;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_handle = FS_Open(filepath, FS_OPEN_DIR | FS_READ_ONLY);

    /* path already exist */
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
        return FS_FILE_EXISTS;
    }

    /* skip drive, i.e. "C:\" */
    while (*filepath_p != L'\\')
    {
        if (*filepath_p != 0)
        {
            filepath_p++;
        }
        else
        {
            return FS_INVALID_FILENAME;
        }
    }

    while (*(filepath_p++))
    {
        if (*filepath_p == L'\\')
        {
            *filepath_p = 0;
            file_handle = FS_Open(filepath, FS_OPEN_DIR | FS_READ_ONLY);
            /* check if path exists */
            if (file_handle < 0)
            {
                /* create dir */
                fs_ret = FS_CreateDir(filepath);
                *filepath_p = L'\\';
                if (fs_ret != FS_NO_ERROR)
                {
                    break;
                }
            }
            else
            {
                FS_Close(file_handle);
                *filepath_p = L'\\';
            }
        }
    }

    return fs_ret;
}

#ifdef TST_HANDLER


/*****************************************************************************
 * FUNCTION
 *  aud_tst_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_tst_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tst_module_string_inject_struct *tst_inject = (tst_module_string_inject_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (tst_inject->index)
    {
        case 0:  /* Force stop recording */
        {
			media_aud_stop_record(kal_get_active_module_id(), 0);
			
            break;
        }

		#if defined(__ATA_SUPPORT__)
        case 99: /* L1audio handler */
        {
			#ifdef __MTK_TARGET__
            extern void ATA_Audio_handler(kal_char *string);
            ATA_Audio_handler((kal_char *)tst_inject->string);
			#endif
			
            break;
        }
		#endif

        default:
            break;
    }

}

#endif /* TST_HANDLER */

#ifdef __RICH_AUDIO_PROFILE__

static med_aud_player_t* g_player_cache_p = NULL; /* Player handle for building cache */

/*****************************************************************************
 * FUNCTION
 *  aud_util_build_cache_start
 * DESCRIPTION
 *  start the process of build cache
 * PARAMETERS
 *  filename     [IN]
 *  cache_p      [IN]
 *  cache_size   [IN]
 *  file_buf     [IN]
 *  file_buf_size[IN]
 *  proc_buf     [IN]
 *  proc_buf_size[IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool aud_util_build_cache_start( kal_wchar *filename, 
    void* cache_p, kal_int32 cache_size, 
    void *file_buf, kal_int32 file_buf_size, 
    void *proc_buf, kal_int32 proc_buf_size )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    kal_int32 result = MED_RES_FAIL;
    med_aud_player_cfg_t player_cfg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MTK_TARGET__

    MED_ASSERT(g_player_cache_p == NULL);

    /* Reset cache table */
    memset(cache_p, 0, cache_size);

    /* Construct a media player */
    g_player_cache_p = aud_player_media_construct();

    if (g_player_cache_p != NULL)
    {
        /* Configure the player */
        player_cfg.file_name   = filename;
        player_cfg.data_p      = NULL;
        player_cfg.data_len    = 0;
        player_cfg.format      = 0; /* Don't care */
        player_cfg.repeat      = 0; /* Don't care */
        player_cfg.audio_path  = 0; /* Don't care */
        player_cfg.fast_pass   = KAL_FALSE;
        player_cfg.cb_fct      = NULL; /* DO NOT hook callback */
        player_cfg.cb_param    = NULL; /* Don't care since no callback */
        
        /* Open a player */
        result = g_player_cache_p->open(g_player_cache_p, &player_cfg);
        _AUD_MODULE_UTILITY1_TRACE(result);

        if (result == MED_RES_OK) /* Open successful */
        {
            /* Set cache table & working buffer */
        
            med_aud_player_set_cache_t set_cache;
            med_aud_player_set_buffer_t set_buf;                

            set_cache.cache_p = cache_p;
            set_cache.cache_size = cache_size;
            result = g_player_cache_p->set(g_player_cache_p, AUD_PLAYER_SET_CACHE_TABLE, (void*)&set_cache);//, (kal_uint32)cache_size);
            _AUD_MODULE_UTILITY1_TRACE(result);

            set_buf.buffer_p = proc_buf;
            set_buf.buffer_size = proc_buf_size;
            result = g_player_cache_p->set(g_player_cache_p, AUD_PLAYER_SET_BUFFER, (void*)&set_buf);//, proc_buf_size);
            _AUD_MODULE_UTILITY1_TRACE(result);
        }
        else /* Open failed */
        {
            /* Close the player */
            g_player_cache_p->close(g_player_cache_p);
            g_player_cache_p->destroy(g_player_cache_p);
            g_player_cache_p = NULL;
        }
    }

#endif /* __MTK_TARGET__ */

    return (result == MED_RES_OK) ? KAL_TRUE : KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_util_build_cache_stop
 * DESCRIPTION
 *  stop the process of build cache
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_util_build_cache_stop( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_player_cache_p != NULL)
    {
        g_player_cache_p->close(g_player_cache_p);
        g_player_cache_p->destroy(g_player_cache_p);
        g_player_cache_p = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_util_build_cache_process
 * DESCRIPTION
 *  do the process of build cache incrementally
 * PARAMETERS
 *  progress_p     [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool aud_util_build_cache_process( kal_uint32 *progress_p )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_FAIL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

#ifdef __MTK_TARGET__

    /* Build cache */
	result = g_player_cache_p->get(g_player_cache_p, (med_aud_player_get_t)MEDIA_PLAYER_GET_BUILD_CACHE_PROGRESS, progress_p);
    _AUD_MODULE_UTILITY2_TRACE(result, *progress_p);

    if (result != MED_RES_OK)
    {
        aud_util_build_cache_stop();
    }
    
#endif /* __MTK_TARGET__ */

    return (result == MED_RES_OK) ? KAL_TRUE : KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_util_build_cache_get_duration
 * DESCRIPTION
 *  get the total duration from the process of build cache
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
kal_uint32 aud_util_build_cache_get_duration( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_FAIL;
    kal_uint32 duration = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     

#ifdef __MTK_TARGET__

    /* Get duration */
    result = g_player_cache_p->get(g_player_cache_p, AUD_PLAYER_GET_DURATION, &duration);
    _AUD_MODULE_UTILITY2_TRACE(result, duration);
        
#endif /* __MTK_TARGET__ */

    return duration;
}

#endif /* __RICH_AUDIO_PROFILE__ */

/*****************************************************************************
 * FUNCTION
 *  aud_util_alloc_ring_buffer_w_log
 * DESCRIPTION
 *  This function allocates an external memory for audio ring buffer.
 * PARAMETERS
 *  file        [IN]       File name what allocates the ring buffer.
 *  line        [IN]       The line number of the file where allocates the ring buffer.
 *  size        [IN]       The size to be allocated in bytes.
 *  pp_mem      [IN/OUT]   Pointer to the pointer where the memory will be allocated to.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_util_alloc_ring_buffer_w_log(char* file, long line, kal_int32 size, kal_uint16** pp_mem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    kal_print_string_trace(MOD_MED, TRACE_INFO, "[MED] allocate ring buffer, file: %s, line: %d, size: %d", file, line, size);

    MED_ASSERT(*pp_mem == NULL);
    
    if (*pp_mem == NULL)
    {
        *pp_mem = (kal_uint16*)med_alloc_aud_mem(size);
        MED_ASSERT(*pp_mem != NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_util_free_ring_buffer_w_log
 * DESCRIPTION
 *  This function frees the allocated ring buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_util_free_ring_buffer_w_log(char* file, long line, kal_uint16** pp_mem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_print_string_trace(MOD_MED, TRACE_INFO, "[MED] free ring buffer, file: %s, line: %d", file, line);

    if (*pp_mem)
    {
        med_free_aud_mem((void**)pp_mem);
        *pp_mem = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_util_alloc_aud_mem
 * DESCRIPTION
 *  This function is to allocate memory from audio memory pool.
 * PARAMETERS
 *  size        [IN]        Memory size to be allocated.
 *  file_p      [IN]        File name.
 *  line        [IN]        Line number in the file.
 * RETURNS
 *  Allocated memory address
 *****************************************************************************/
void* aud_util_alloc_aud_mem(kal_uint32 size, char* file_p, long line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    return med_alloc_ext_mem_ext(size, MED_EXT_MEMORY_TYPE_AUDIO_NONCACHEABLE, file_p, line);
}


/*****************************************************************************
 * FUNCTION
 *  aud_util_alloc_aud_cacheable_mem
 * DESCRIPTION
 *  This function is to allocate cacheable memory from audio memory pool.
 * PARAMETERS
 *  void
 * RETURNS
 *  Allocated memory address
 *****************************************************************************/
void* aud_util_alloc_aud_cacheable_mem(kal_uint32 size, char* file_p, long line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    return med_alloc_ext_mem_ext(size, MED_EXT_MEMORY_TYPE_AUDIO_CACHEABLE, file_p, line);
}

/*****************************************************************************
 * FUNCTION
 *  aud_util_alloc_aud_toppest_cacheable_mem
 * DESCRIPTION
 *  This function is to allocate cacheable memory in toppest direction from audio memory pool.
 * PARAMETERS
 *  size        [IN]        Memory size to be allocated.
 *  file_p      [IN]        File name.
 *  line        [IN]        Line number in the file.
 * RETURNS
 *  Allocated memory address
 *****************************************************************************/
void* aud_util_alloc_aud_toppest_cacheable_mem(kal_uint32 size, char* file_p, long line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    return med_alloc_ext_mem_ext(size, MED_EXT_MEMORY_TYPE_TOPPEST_AUDIO_CACHEABLE, file_p, line);
}

/*****************************************************************************
 * FUNCTION
 *  aud_util_free_aud_mem
 * DESCRIPTION
 *  This function is to free audio memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  Allocated memory address
 *****************************************************************************/
void aud_util_free_aud_mem(void** mem_p, char* file_p, long line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    med_free_aud_mem_ext(mem_p, file_p, line);
}


/*****************************************************************************
 * FUNCTION
 *  aud_util_in_proc_call_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_util_in_proc_call_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_in_proc_call_req_struct *msg_p = (media_in_proc_call_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->func(msg_p->func_arg1, msg_p->func_arg2);
}


/*****************************************************************************
 * FUNCTION
 *  aud_util_in_proc_call_ext_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_util_in_proc_call_ext_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_in_proc_call_ext_req_struct *msg_p = (media_in_proc_call_ext_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->pf_func((void*)msg_p->pui1_data, msg_p->ui2_data_len);
}


/*****************************************************************************
 * FUNCTION
 *  aud_util_proc_in_med
 * DESCRIPTION
 *  This function is to process a given function by using MED thread.
 * PARAMETERS
 *  src_mod_id      [IN]         The source module who issues this request.
 *  func            [IN]         The callback function to be executed in MED
 *                               thread.
 *  func_arg1       [IN]         The first argument which will be brought back
 *                               in the callback function.
 *  func_arg2       [IN]         The second argument which will be brought back
 *                               in the callback function.
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
void aud_util_proc_in_med(module_type src_mod_id, media_in_proc_call_type func, kal_uint32 func_arg1, void* func_arg2)
{
   aud_send_in_proc_call_req(src_mod_id, func, func_arg1, func_arg2);
}


/*****************************************************************************
 * FUNCTION
 *  aud_util_proc_in_med_ext
 * DESCRIPTION
 *  This function is to process a given function by using MED thread.
 * PARAMETERS
 *  src_mod_id      [IN]         The source module who issues this request.
 *  func            [IN]         The callback function to be executed in MED
 *                               thread.
 *  pv_data         [IN]         The data for the asynchronous process.
 *  data_len        [IN]         The length of the data.
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
void aud_util_proc_in_med_ext(module_type src_mod_id, media_in_proc_call_ext_type pf_func, void* pv_data, kal_uint16 ui2_data_len)
{
   aud_send_in_proc_call_ext_req(src_mod_id, pf_func, pv_data, ui2_data_len);
}


/*****************************************************************************
 * FUNCTION
 *  aud_util_proc_in_med_v
 * DESCRIPTION
 *  This function is to process a given function by using MED-V thread.
 * PARAMETERS
 *  src_mod_id      [IN]         The source module who issues this request.
 *  func            [IN]         The callback function to be executed in MED-V
 *                               thread.
 *  func_arg1       [IN]         The first argument which will be brought back
 *                               in the callback function.
 *  func_arg2       [IN]         The second argument which will be brought back
 *                               in the callback function.
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
void aud_util_proc_in_med_v(module_type src_mod_id, media_in_proc_call_type func, kal_uint32 func_arg1, void* func_arg2)
{
#ifndef MED_V_NOT_PRESENT
   aud_send_in_proc_call_req2(src_mod_id, func, func_arg1, func_arg2);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  aud_util_proc_in_med_v_ext
 * DESCRIPTION
 *  This function is to process a given function by using MED-V thread.
 * PARAMETERS
 *  src_mod_id      [IN]         The source module who issues this request.
 *  func            [IN]         The callback function to be executed in MED-V
 *                               thread.
 *  pv_data         [IN]         The data for the asynchronous process.
 *  data_len        [IN]         The length of the data.
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
void aud_util_proc_in_med_v_ext(module_type src_mod_id, media_in_proc_call_ext_type pf_func, void* pv_data, kal_uint16 ui2_data_len)
{
#ifndef MED_V_NOT_PRESENT
   aud_send_in_proc_call_ext_req2(src_mod_id, pf_func, pv_data, ui2_data_len);
#endif
}

#ifdef __MED_MPL_PLAYER__

static kal_uint16 g_app_id = 0;

/*****************************************************************************
 * FUNCTION
 *  MPL_AllocMem
 * DESCRIPTION
 *  This function is used to allocate memory for MPL content description.
 * PARAMETERS
 *  size          [IN]          Memory size
 *  type          [IN]          Memory type
 *  file          [IN]          File name       
 *  line          [IN]          The line number in the file
 * RETURNS
 *  Memory address
 *****************************************************************************/
static void* MPL_AllocMem(kal_uint32 size, med_mem_type_enum type, char* file, long line)
{
    void* mem_p = NULL;

    switch (type)
    {
        case MED_MEM_NONCACHE:
        {
            mem_p = med_alloc_mem(g_app_id, size, file, line);
            break;
        }

        case MED_MEM_CACHE:
        {
            mem_p = med_alloc_mem_cacheable(g_app_id, size, file, line);
            break;
        }

        default:
            break;
    }

    return mem_p;

}

/*****************************************************************************
 * FUNCTION
 *  RM_FreeMem
 * DESCRIPTION
 *  This function is used to free memory for RM content description.
 * PARAMETERS
 *  mem_p         [IN]          Memory pointer
 *  type          [IN]          Memory type
 *  file          [IN]          File name       
 *  line          [IN]          The line number in the file
 * RETURNS
 *  void
 *****************************************************************************/
static void MPL_FreeMem(void** mem_p, med_mem_type_enum type, char* file, long line)
{
    switch (type)
    {
        case MED_MEM_NONCACHE:
        case MED_MEM_CACHE:
            med_free_mem(g_app_id, mem_p, file, line);
            break;
        default:
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  MPL_AllocMem_Aud
 * DESCRIPTION
 *  This function is used to allocate memory for MPL content description.
 *  from med audio memory pool
 * PARAMETERS
 *  size          [IN]          Memory size
 *  type          [IN]          Memory type
 *  file          [IN]          File name       
 *  line          [IN]          The line number in the file
 * RETURNS
 *  Memory address
 *****************************************************************************/
static void* MPL_AllocMem_Aud(kal_uint32 size, med_mem_type_enum type, char* file, long line)
{
    void* mem_p = NULL;

    switch (type)
    {
        case MED_MEM_NONCACHE:
        {
            mem_p = med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_AUDIO_NONCACHEABLE,file,line);
            break;
        }

        case MED_MEM_CACHE:
        {
            mem_p = med_alloc_ext_mem_ext(size,MED_EXT_MEMORY_TYPE_AUDIO_CACHEABLE,file,line);
            break;
        }

        default:
            break;
    }
    
    return mem_p;

}

/*****************************************************************************
 * FUNCTION
 *  MPL_FreeMem_Aud
 * DESCRIPTION
 *  This function is used to free memory for MPL content description
 *  from med audio memory pool
 * PARAMETERS
 *  mem_p         [IN]          Memory pointer
 *  type          [IN]          Memory type
 *  file          [IN]          File name       
 *  line          [IN]          The line number in the file
 * RETURNS
 *  void
 *****************************************************************************/
static void MPL_FreeMem_Aud(void** mem_p, med_mem_type_enum type, char* file, long line)
{
    switch (type)
    {
        case MED_MEM_NONCACHE:
        case MED_MEM_CACHE:
            med_free_aud_mem_ext(mem_p, file, line);
            break;
        default:
            break;
    }
}

#if defined(__RM_DEC_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  RM_GetContentDescInfo
 * DESCRIPTION
 *  This function is used to get the content description of a RM file.
 * PARAMETERS
 *  pstFSAL         [IN]         FSAL handle.
 *  contentInfo     [OUT]        Content information.
 *  param           [IN]         app_id.
 * RETURNS
 *  Media_Status
 *****************************************************************************/
Media_Status RM_GetContentDescInfo(STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param)
{
    g_app_id = (kal_uint16)param;

    return MPL_GetContentDescInfo(MED_TYPE_RM, pstFSAL, contentInfo, MPL_AllocMem, MPL_FreeMem);
}
#endif /* __RM_DEC_SUPPORT__ */


#ifdef __FLV_FILE_FORMAT_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  FLV_GetContentDescInfo
 * DESCRIPTION
 *  This function is used to get the content description of a FLV file.
 * PARAMETERS
 *  pstFSAL         [IN]         FSAL handle.
 *  contentInfo     [OUT]        Content information.
 *  param           [IN]         app_id.
 * RETURNS
 *  Media_Status
 *****************************************************************************/
Media_Status FLV_GetContentDescInfo(STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param)
{
    g_app_id = (kal_uint16)param;

    return MPL_GetContentDescInfo(MED_TYPE_FLV, pstFSAL, contentInfo, MPL_AllocMem, MPL_FreeMem);
}
#endif /* __FLV_FILE_FORMAT_SUPPORT__ */


#if defined(MED_PURE_AUDIO) || defined(M4A_DECODE)
/*****************************************************************************
 * FUNCTION
 *  MP4S_GetContentDescInfo
 * DESCRIPTION
 *  This function is used to get the content description of a MP4/3GP/M4A file.
 *  MP4 Series
 * PARAMETERS
 *  pstFSAL         [IN]         FSAL handle.
 *  contentInfo     [OUT]        Content information.
 *  param           [IN]         app_id.
 * RETURNS
 *  Media_Status
 *****************************************************************************/
Media_Status MP4S_GetContentDescInfo(STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param)
{
    g_app_id = (kal_uint16)param;

    return MPL_GetContentDescInfo(MED_TYPE_MP4, pstFSAL, contentInfo, MPL_AllocMem_Aud, MPL_FreeMem_Aud);
}
#endif /*MED_PURE_AUDIO || M4A_DECODE*/
#endif /*__MED_MPL_PLAYER__*/

#endif /* MED_NOT_PRESENT */ 

