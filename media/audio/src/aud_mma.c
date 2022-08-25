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
 *   aud_mma.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is to handle all messages for Multiple Access Interface. 
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/* system includes */
//#include "kal_release.h"
#include "kal_trace.h"
//#include "stack_common.h"
//#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
//#include "syscomp_config.h"
//#include "task_config.h"        /* Task creation */
//#include "app_buff_alloc.h"     /* Declaration of buffer management API */
//#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
//#include "event_shed.h" /* Event scheduler */
//#include "stack_timer.h"        /* Stack timer */
//#include "app_buff_alloc.h"

/* global includes */
#include "l1audio.h"
//#include "device.h"
//#include "custom_equipment.h"
//#include "resource_audio.h"
//#include "nvram_enums.h"
//#include "nvram_struct.h"
//#include "nvram_user_defs.h"
//#include "nvram_data_items.h"
//#include "custom_nvram_editor_data_item.h"
//#include "fat_fs.h"     /* for FAT FS */
//#include "drm_gprot.h"  /* DRM_REPLACE */
#include "FSAL.h"
//#include "MP4_Parser.h"

/* local includes */
#include "med_global.h"
#include "med_main.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "aud_main.h"
#include "med_main.h"
#include "med_utility.h"
#include "aud_player.h"
#include "aud_player_mma.h"
#include "aud_player_media.h"
#include "med_v_main.h"

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "string.h"
#include "med_smalloc.h"
#include "kal_public_defs.h"

#if defined(__MED_VID_DEC_MOD__)
#include "vid_main.h"
#endif /* defined(__MED_VID_DEC_MOD__) */

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#if defined(__DRM_V02__)
#include "Drm_gprot.h"
#endif

#ifdef __MED_MMA_MOD__

#ifdef __MED_IMY_EVENT__
extern void aud_melody_event_hdlr(med_aud_player_t* player_p, Media_Event e_event);
#endif

extern kal_int16 med_get_media_type_from_mma_type(kal_uint8 mma_type);

/*-----------------------------------------------------------------------------
                    macros, defines, typedefs, enums
-----------------------------------------------------------------------------*/
#define _AUD_MODULE_MMA_TRACE(x, y, z)   AUD_MODULE_MMA_TRACE(x, y, z, __LINE__)
#define _AUD_MODULE_MMA2_TRACE(x, y)     AUD_MODULE_MMA2_TRACE(x, y, __LINE__)

#define MMA_TO_MED(t)                    med_get_media_type_from_mma_type(t)
#define MMA_NO_OF_PLAYER                 (MMA_MAX_NUM+1) /* Max MMA players + 1 single player */
#define MMA_SINGLE_PLAYER_IDX            (0) /* MMA single player index */

typedef Media_Status(*mma_get_meta_func) (kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param);
typedef Media_Status(*mma_get_desc_func) (STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param);

typedef struct
{
    STFSAL     fsal_handle;          /* FSAL handle */
    kal_bool   is_progressive_dl;    /* Play a progressive download file */
    kal_bool   is_dl_finish;         /* Is progressive download finish */
    kal_bool   is_fsal_opened;       /* Indicate if FSAL is opened */
    kal_bool   is_building_cache;    /* Indicate if it's building cache */
    kal_uint8  media_end_play_count; /* To prevent data not played after download finish */
    kal_uint32 underflow_offset;     /* The driver offset when progressive dl underflow for fast restore */
    kal_uint32 underflow_time;       /* The play time when progressive dl underflow */
    kal_uint32 underflow_file_size;  /* The file size when progressive dl underflow to calculate download percentage */
    kal_uint32 bit_rate;             /* Bit rate of a progressive download file */
    kal_wchar* file_name;            /* Store file name for auto build cache */
    void*      cache_table;          /* Cache table */
}
aud_mma_single_player_struct;

typedef struct
{
    kal_bool   used;                 /* Indicate if the player is being used */
    kal_uint8  state;                /* Player state */
    kal_uint8  output_path;          /* Output path */
    kal_bool   async_mode;           /* Async whie play and stop action */
    kal_int16  format;               /* Media format */
    kal_int32  handle;               /* Player handle */
    kal_int32  cb_func;              /* Callback function */
}
aud_mma_multiple_player_struct;

/*-----------------------------------------------------------------------------
                    data declaraions
 ----------------------------------------------------------------------------*/

static aud_mma_single_player_struct g_mma_single_player;
#ifdef __MED_MMA_MOD__
static aud_mma_multiple_player_struct g_mma_multiple_player[MMA_NO_OF_PLAYER];
#endif /* __MED_MMA_MOD__ */ 


/*-----------------------------------------------------------------------------
                    function prototypes
 ----------------------------------------------------------------------------*/
static void _aud_mma_player_event_hdlr(med_aud_player_t* aud_player_p, Media_Event event, void* param);
static kal_int8 _aud_mma_get_free_player_idx_by_type(kal_uint8 media_type);
static kal_int8 _aud_mma_get_player_idx_by_handle(kal_int32 handle);
static aud_mma_multiple_player_struct* _aud_mma_get_multiple_player_handle(kal_int32 handle);


/*-----------------------------------------------------------------------------
                    private function declarations
 ----------------------------------------------------------------------------*/
 
#ifndef __MTK_TARGET__ /* Redirect to MoDIS function */

/*****************************************************************************
 * FUNCTION
 *  _aud_mma_open_modis_player
 * DESCRIPTION
 *  This function is to open a MoDIS player which could play multiple audio
 *  resources concurrently.
 * PARAMETERS
 *  file_path       [IN]         The file to be opened. NULL if opening from
 *                               data string.
 *  data_p          [IN]         Data string.
 *  data_len        [IN]         The length of data string.
 *  format          [IN]         Media format.
 *  repeat          [IN]         Repeat times.
 *  cb_func         [IN]         Client callback function.
 *  handle_p        [OUT]        Returned MMA player handle.
 * RETURNS
 *  MED_RES_OK                   Successful.
 *  Others                       Failed.
 *****************************************************************************/
static kal_int32 _aud_mma_open_modis_player(kal_wchar* file_name,
                                            kal_uint8* data_p,
                                            kal_int32  data_len,
                                            kal_int16  format,
                                            kal_int16  repeat,
                                            kal_int32  cb_func,
                                            kal_int32* handle_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_FAIL;
    kal_int8 free_player_idx;
    aud_mma_multiple_player_struct* player_p = NULL;
    med_aud_player_t* modis_player_p = NULL;
    med_aud_player_cfg_t modis_player_cfg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (file_name != NULL) /* Single player */
    {
        player_p = &(g_mma_multiple_player[MMA_SINGLE_PLAYER_IDX]);
    }
    else
    {
        switch (format)
        {
            /* Multiple player */
            case MED_TYPE_SMF:
            case MED_TYPE_IMELODY:
        #ifdef JTONE_SUPPORT
            case MED_TYPE_TONE:
        #endif
        #ifdef WAV_CODEC
            case MED_TYPE_WAV:
        #endif
            {
                free_player_idx = _aud_mma_get_free_player_idx_by_type((kal_uint8)format);

                if (free_player_idx == -1)
                {
                    return MED_RES_BUSY;
                }

                player_p = &(g_mma_multiple_player[free_player_idx]);
                break;
            }
            /* Single player with data */
            default:
                player_p = &(g_mma_multiple_player[MMA_SINGLE_PLAYER_IDX]);
                break;
        }
    }

    /* Check if the player is being used */
    if (player_p->used)
    {
        result = MED_RES_BUSY;
    }

    /* Construct a MoDIS player */
    modis_player_p = aud_player_modis_construct();

    if (modis_player_p != NULL)
    {    
        /* Configure the player */
        modis_player_cfg.file_name   = file_name;
        modis_player_cfg.data_p      = data_p;
        modis_player_cfg.data_len    = data_len;
        modis_player_cfg.format      = 0; /* don't care */
        modis_player_cfg.repeat      = 0; /* don't care */
        modis_player_cfg.audio_path  = 0; /* don't care */
        modis_player_cfg.fast_pass   = KAL_FALSE;
        modis_player_cfg.cb_fct      = _aud_mma_player_event_hdlr;
        modis_player_cfg.cb_param    = (void*)format;
        
        /* Open a player */
        result = modis_player_p->open(modis_player_p, &modis_player_cfg);

        if (result == MED_RES_OK) /* Open successful */
        {
            player_p->handle  = (kal_int32)modis_player_p;
            player_p->cb_func = cb_func;
            player_p->used    = KAL_TRUE;
            player_p->state   = AUD_MEDIA_IDLE;
            player_p->format  = format;
        }
        else /* Open failed */
        {
            /* Destroy the player */
            modis_player_p->destroy(modis_player_p);
            modis_player_p = NULL;
        }
    }
    
    /* Copy out player handler */
    *handle_p = (kal_uint32)modis_player_p;
    
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  _aud_mma_play_modis_req
 * DESCRIPTION
 *  This function is to play a MoDIS player.
 * PARAMETERS
 *  handle      [IN]    Player handle
 * RETURNS
 *
 *****************************************************************************/
static kal_int32 _aud_mma_play_modis_req(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_mma_multiple_player_struct* player_p;
    med_aud_player_t* modis_player_p;
    kal_int32 result = MED_RES_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Validate handle */
    player_p = _aud_mma_get_multiple_player_handle(handle);
    
    modis_player_p = (med_aud_player_t*) handle;

    /* Check state */
    if (player_p->state == AUD_MEDIA_IDLE)
    {
        /* Play the MoDIS player */
        result = modis_player_p->play(modis_player_p);

        if (result == MED_RES_OK)
        {
            player_p->state = AUD_MEDIA_PLAY;
        }
    }
    
    return result;
}

#endif /* #ifndef __MTK_TARGET__ */

/*****************************************************************************
 * FUNCTION
 *  _aud_mma_close_single_fsal
 * DESCRIPTION
 *  This function is to release resources of FSAL and close the FSAL handle.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_mma_close_single_fsal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_mma_single_player.is_fsal_opened)
    {
        if (g_mma_single_player.fsal_handle.bBuffering && g_mma_single_player.fsal_handle.pbBuf != NULL)
        {
        #if defined(AUD_PROC_USE_EXT_MEM)
            med_free_aud_mem((void**)&g_mma_single_player.fsal_handle.pbBuf);
        #else
            free_ctrl_buffer((void*)g_mma_single_player.fsal_handle.pbBuf);
        #endif
        }

        FSAL_Close(&g_mma_single_player.fsal_handle);
        memset(&g_mma_single_player.fsal_handle, 0, sizeof(STFSAL));

        if (g_mma_single_player.file_name)
        {
            med_free_aud_mem((void**)&g_mma_single_player.file_name);
        }

        g_mma_single_player.is_fsal_opened = KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  _aud_mma_get_free_player_idx_by_type
 * DESCRIPTION
 *  This function gets a free player index for a given media type.
 * PARAMETERS
 *  media_type      [IN]      Media type.  
 * RETURNS
 *  >= 0                      Successful.
 *  -1                        Failed.
 *****************************************************************************/
static kal_int8 _aud_mma_get_free_player_idx_by_type(kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_mma_multiple_player_struct *player_p;
    kal_uint8 i, count;
    kal_uint8 concurrent = 1;
    kal_int8 free_idx = -1;
    Media_Format media_format = (Media_Format)media_type ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Count MMA players with the given media type */
    count = 0;
    
    for (i = 1; i < MMA_NO_OF_PLAYER; i ++)
    {
        player_p = &(g_mma_multiple_player[i]);
        
        if (player_p->used && player_p->format == media_type)
        {
            count++;
        }
    }

    /* Get max concurrent */
    if(media_type == MED_TYPE_MIDI)
    {
        media_format = MEDIA_FORMAT_SMF;        
    }

    Media_GetMMACapability(media_format, &concurrent);

    /* More concurrent is allowed */
    if (count < concurrent)
    {
        /* Find the first empty MMA slot */
        for (i = 1; i < MMA_NO_OF_PLAYER; i ++)
        {
            player_p = &(g_mma_multiple_player[i]);
            
            if (! player_p->used)
            {
                free_idx = i;
                break;
            }
        }
    }
    
    return free_idx;
}


/*****************************************************************************
 * FUNCTION
 *  _aud_mma_get_player_idx_by_handle
 * DESCRIPTION
 *  This function is to get the player index of a given media type and handle.
 * PARAMETERS
 *  handle          [IN]        Player handle.
 * RETURNS
 *  >= 0                        Player index.
 *  -1                          Invalid handle.
 *****************************************************************************/
static kal_int8 _aud_mma_get_player_idx_by_handle(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 i;
    aud_mma_multiple_player_struct *player_p;
    kal_int8 player_idx = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Check Single Player */
    player_p = &(g_mma_multiple_player[MMA_SINGLE_PLAYER_IDX]);
    if (player_p->used && player_p->handle == handle)
    {
        player_idx = MMA_SINGLE_PLAYER_IDX;
    }
    /* If not a single player, it may be one of the multiple players */
    else
    {
        for (i = 1; i < MMA_NO_OF_PLAYER; i ++)
        {
            player_p = &(g_mma_multiple_player[i]);

            if (player_p->used && player_p->handle == handle)
            {
                player_idx = i;
                break;
            }
        }
    }

    MED_ASSERT(player_idx != -1);
    
    return player_idx;
}

/*****************************************************************************
 * FUNCTION
 *  _aud_mma_get_multiple_player_handle
 * DESCRIPTION
 *  This function is to get the multiple player handle by player handle.
 * PARAMETERS
 *  handle          [IN]        Player handle.
 * RETURNS
 *  aud_mma_multiple_player_struct*
 *****************************************************************************/
static aud_mma_multiple_player_struct* _aud_mma_get_multiple_player_handle(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 player_idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    player_idx = _aud_mma_get_player_idx_by_handle(handle);
    return &(g_mma_multiple_player[player_idx]);
    
}


/*****************************************************************************
 * FUNCTION
 *  _aud_mma_is_single_player
 * DESCRIPTION
 *  This function is to check if a given handle is a single player.
 * PARAMETERS
 *  handle      [IN]        Player handle.
 * RETURNS
 *  KAL_TRUE                Single player.
 *  KAL_FALSE               Multiple player.
 *****************************************************************************/
static kal_bool _aud_mma_is_single_player(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_mma_multiple_player_struct *player_p;
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    player_p = &(g_mma_multiple_player[MMA_SINGLE_PLAYER_IDX]);

    if (player_p->used && player_p->handle == handle)
    {
        result = KAL_TRUE;
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  _aud_mma_pdl_get_information
 * DESCRIPTION
 *  This function is to set common information of mma pdl
 * PARAMETERS
 *  aud_player_p           [IN]    Player handler
 * RETURNS
 *****************************************************************************/
static void _aud_mma_pdl_get_information(med_aud_player_t* aud_player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    aud_player_p->get(aud_player_p, AUD_PLAYER_GET_CURRENT_TIME, (void*)&g_mma_single_player.underflow_time);//, sizeof(kal_uint32));
    aud_player_p->get(aud_player_p, AUD_PLAYER_GET_LAST_OFFSET, (void*)&g_mma_single_player.underflow_offset);//, sizeof(kal_uint32));
}


/*****************************************************************************
 * FUNCTION
 *  _aud_mma_player_event_hdlr
 * DESCRIPTION
 *  This function is called back by player when end-of-play or something error.
 *  This function should notify MMI with interested events, e.g. play error,
 *  play end, etc. Also note that this function is executed by using MED thread,
 *  i.e. no context switch is requried.
 * PARAMETERS
 *  player_p           [IN]    Player handler
 *  event              [IN]    Media event
 *  param              [IN]    User data (the pv_callback_param of med_aud_player_cfg_t)
 * RETURNS
 *****************************************************************************/
static void _aud_mma_player_event_hdlr(med_aud_player_t* aud_player_p, Media_Event event, void* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 media_type = (kal_uint8)(kal_uint32)param;
    aud_mma_multiple_player_struct *player_p;
    med_handler cb_func;
    kal_uint32 fsal_file_size = 0;
    kal_int32 result;
    kal_bool is_underflow = KAL_FALSE;
    kal_bool is_single = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Validate handle */
    player_p = _aud_mma_get_multiple_player_handle((kal_uint32)aud_player_p);


    /* Check player state */
    if (!player_p->used || (player_p->state != AUD_MEDIA_PLAY))
    {
        return;
    }
    
    is_single = _aud_mma_is_single_player((kal_uint32)aud_player_p);

    _AUD_MODULE_MMA_TRACE(event, aud_player_p, media_type);

    cb_func = (med_handler) player_p->cb_func;

    switch (event)
    {
        case MEDIA_NONE:
        case MEDIA_BUFFER_UNDERFLOW:
            /* Do nothing */
            break;
        case MEDIA_UPDATE_DUR:
            /* Notify client with duration updated event */

            if (cb_func)
            {
                cb_func(player_p->handle, MED_RES_AUD_DUR_UPDATED);
            }
            break;
        case MEDIA_REPEATED: /* play repeated */
        #ifdef __MED_IMY_EVENT__
            /* Special handling for IMY */
            if (media_type == MED_TYPE_IMELODY ||
                media_type == MED_TYPE_SMF)
            {
                /* Stop melody driver */
                aud_melody_stop_driver();
            }
        #endif
            break;

    #ifdef __MED_IMY_EVENT__
        case MEDIA_EXTENDED_EVENT:
        case MEDIA_LED_ON:
        case MEDIA_LED_OFF:
        case MEDIA_VIBRATOR_ON:
        case MEDIA_VIBRATOR_OFF:
        case MEDIA_BACKLIGHT_ON:
        case MEDIA_BACKLIGHT_OFF:
            /* Call melody event handler */
            aud_melody_event_hdlr(aud_player_p, event);
            break;
    #endif

        default:
        {
            _AUD_MODULE_MMA2_TRACE(g_mma_single_player.is_progressive_dl, g_mma_single_player.is_dl_finish);

            /* Progressive download */
            if (is_single && g_mma_single_player.is_progressive_dl)
            {
                /* Write data finish while playing but encounter MEDIA_END immediately.
                   There is still a short period of data not played*/        
                if (g_mma_single_player.is_dl_finish)
                {
                    _aud_mma_pdl_get_information(aud_player_p);
                    FSAL_GetFileSize(&g_mma_single_player.fsal_handle, &fsal_file_size);

                    _AUD_MODULE_MMA_TRACE(g_mma_single_player.underflow_time, g_mma_single_player.underflow_offset, fsal_file_size);
                    
                    /* Try to play the last part of file */
                    if ((g_mma_single_player.underflow_offset > 0) &&
                        (g_mma_single_player.underflow_offset < fsal_file_size) &&
                        (g_mma_single_player.media_end_play_count == 0) &&
                        (player_p->state == AUD_MEDIA_PLAY))
                    {
                        /* Stop the player first */
                        aud_player_p->stop(aud_player_p);

                        /* Update start time and file offset */
                        aud_player_p->set(aud_player_p, AUD_PLAYER_SET_STORE_FLAG, (void*)KAL_TRUE);//, sizeof(kal_bool));
                        aud_player_p->set(aud_player_p, AUD_PLAYER_SET_START_TIME, (void*)g_mma_single_player.underflow_time);//, sizeof(kal_uint32));
                        aud_player_p->set(aud_player_p, AUD_PLAYER_SET_FILE_OFFSET, (void*)g_mma_single_player.underflow_offset);//, sizeof(kal_uint32));

                        result = aud_player_p->play(aud_player_p);

                        _AUD_MODULE_MMA_TRACE(result, aud_player_p, g_mma_single_player.media_end_play_count);

                        /* Only try to play the last part once, if the second time the played file offset 
                           is still not the same as actual file size, then return MEDIA_END */
                        g_mma_single_player.media_end_play_count ++; 
                        
                        if (result == MED_RES_OK)
                        {
                            player_p->state = AUD_MEDIA_PLAY;
                            return;
                        }
                    }
                }
                /* Progressive download underflow */
                else
                {
                    /* Keep file offset in driver for fast restore.(MP3,AAC Only. Other format will use current time) */
                     _aud_mma_pdl_get_information(aud_player_p);
                    FSAL_GetFileSize(&g_mma_single_player.fsal_handle, &g_mma_single_player.underflow_file_size);

                    _AUD_MODULE_MMA_TRACE(g_mma_single_player.underflow_time, g_mma_single_player.underflow_offset, g_mma_single_player.underflow_file_size);
                    
                    /* Progressive download is not finished yet, but playback already reaches EOF. */
                    is_underflow = KAL_TRUE;
                }
            }

            /* Stop the player */
            aud_player_p->stop(aud_player_p);

        #ifdef __MED_IMY_EVENT__
            if (media_type == MED_TYPE_IMELODY ||
                media_type == MED_TYPE_SMF)
            {
                /* Stop melody driver */
                aud_melody_stop_driver();
            }
        #endif

            /* Update player state */
            if (is_underflow)
            {
                player_p->state = AUD_MEDIA_UNDERFLOW;
            }
            else
            {
                player_p->state = AUD_MEDIA_IDLE;
            }

            /* Callback event to client */
            
            if (cb_func)
            {
                kal_int32 cb_event = MED_RES_ERROR;

                switch (event)
                {
                    case MEDIA_END:
                        if (is_underflow)
                        {
                            cb_event = MED_RES_BUFFER_INSUFFICIENT;
                        }
                        else
                        {
                            cb_event = MED_RES_END_OF_FILE;
                        }
                        break;
                    case MEDIA_STOP_TIME_UP:
                        cb_event = MED_RES_END_OF_FILE;
                        break;
                    case MEDIA_DECODER_UNSUPPORT:
                        cb_event = MED_RES_DECODER_NOT_SUPPORT;
                        break;
                }

                cb_func(player_p->handle, cb_event);
            
            }
            
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  _aud_mma_open_mma_player
 * DESCRIPTION
 *  This function is to open an MMA player which could play multiple audio
 *  resources concurrently.
 * PARAMETERS
 *  file_path       [IN]         The file to be opened. NULL if opening from
 *                               data string.
 *  data_p          [IN]         Data string.
 *  data_len        [IN]         The length of data string.
 *  format          [IN]         Media format.
 *  repeat          [IN]         Repeat times.
 *  fast_mode       [IN]         Specify if fast pass mode should be applied.
 *  cb_func         [IN]         Client callback function.
 *  handle_p        [OUT]        Returned MMA player handle.
 * RETURNS
 *  MED_RES_OK                   Successful.
 *  Others                       Failed.
 *****************************************************************************/
static kal_int32 _aud_mma_open_mma_player(kal_wchar* file_name,
                                          kal_uint8* data_p,
                                          kal_int32  data_len,
                                          kal_int16  format,
                                          kal_int16  repeat,
                                          kal_bool   fast_pass,
                                          kal_int32  cb_func,
                                          kal_int32* handle_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_FAIL;
    kal_int8 free_player_idx;
    aud_mma_multiple_player_struct* player_p = NULL;
    med_aud_player_t* mma_player_p = NULL;
    med_aud_player_cfg_t mma_player_cfg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (file_name != NULL) /* Single player */
    {
        player_p = &(g_mma_multiple_player[MMA_SINGLE_PLAYER_IDX]);

        if (player_p->used)
        { 
            return MED_RES_BUSY;
        }
    }
    else /* Multiple player */
    {
        free_player_idx = _aud_mma_get_free_player_idx_by_type((kal_uint8)format);

        if (free_player_idx == -1)
        {
            return MED_RES_BUSY;
        }

        player_p = &(g_mma_multiple_player[free_player_idx]);
    }

    /* Construct an MMA player */
    mma_player_p = aud_player_mma_construct();

    if (mma_player_p != NULL)
    {    
        /* Configure the player */
        mma_player_cfg.file_name   = file_name;
        mma_player_cfg.data_p      = data_p;
        mma_player_cfg.data_len    = data_len;
        mma_player_cfg.format      = (kal_uint8)format;
        mma_player_cfg.repeat      = repeat;
        mma_player_cfg.audio_path  = 0; /* don't care */
        mma_player_cfg.fast_pass   = fast_pass;
        mma_player_cfg.cb_fct      = _aud_mma_player_event_hdlr;
        mma_player_cfg.cb_param    = (void*)format;
        
        /* Open a player */
        result = mma_player_p->open(mma_player_p, &mma_player_cfg);

        if (result == MED_RES_OK) /* Open successful */
        {
            player_p->handle  = (kal_int32)mma_player_p;
            player_p->cb_func = cb_func;
            player_p->used    = KAL_TRUE;
            player_p->state   = AUD_MEDIA_IDLE;
            player_p->format  = format;
        }
        else /* Open failed */
        {
            /* Destroy the player */
            mma_player_p->destroy(mma_player_p);
            mma_player_p = NULL;
        }
    }

    /* Copy out player handler */
    *handle_p = (kal_uint32)mma_player_p;
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  _aud_mma_open_media_player
 * DESCRIPTION
 *  This function is to open a Media Player for single playback.
 * PARAMETERS
 *  file_path       [IN]         The file to be opened. NULL if opening from
 *                               data string.
 *  data_p          [IN]         Data string.
 *  data_len        [IN]         The length of data string.
 *  format          [IN]         Media format.
 *  repeat          [IN]         Repeat times.
 *  cb_func         [IN]         Client callback function.
 *  handle_p        [OUT]        Returned Media Player handle.
 * RETURNS
 *  MED_RES_OK                   Successful.
 *  Others                       Failed.
 *****************************************************************************/
static kal_int32 _aud_mma_open_media_player(kal_wchar* file_name,
                                            kal_uint8* data_p,
                                            kal_int32  data_len,
                                            kal_int16  format,
                                            kal_int16  repeat,
                                            kal_int32  cb_func,
                                            kal_int32* handle_p)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_FAIL;
    aud_mma_multiple_player_struct* player_p = NULL;
    med_aud_player_t* media_player_p = NULL;
    med_aud_player_cfg_t media_player_cfg;
    kal_uint8* fsal_buf_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    player_p = &(g_mma_multiple_player[MMA_SINGLE_PLAYER_IDX]);

    if (player_p->used)
    {
        return MED_RES_BUSY;
    }

    /* Open from file */
    if (file_name != NULL)
    {
        /* Open a FSAL handle for progressive download usage */
        if (FSAL_Open(&g_mma_single_player.fsal_handle, file_name, FSAL_READ_SHARED) != FSAL_OK)
        {
            return MED_RES_OPEN_FILE_FAIL;
        }

    #if defined(AUD_PROC_USE_EXT_MEM)
        fsal_buf_p = (kal_uint8*) med_alloc_aud_mem(sizeof(kal_uint8) * AUD_PROC_BUF_SIZE);
    #else 
        fsal_buf_p = (kal_uint8*) get_ctrl_buffer(sizeof(kal_uint8) * AUD_PROC_BUF_SIZE);
    #endif 

        FSAL_SetBuffer(&g_mma_single_player.fsal_handle, AUD_PROC_BUF_SIZE, fsal_buf_p);

        /* Store file name for auto build cache */
        g_mma_single_player.file_name = (kal_wchar*) med_alloc_aud_mem(sizeof(kal_wchar) * (kal_wstrlen(file_name) + 1));

        if (g_mma_single_player.file_name)
        {
            kal_wstrcpy(g_mma_single_player.file_name, file_name);
        }

        g_mma_single_player.is_fsal_opened = KAL_TRUE;
    }

    /* Construct a player */
    media_player_p = aud_player_media_construct();
    
    if (media_player_p != NULL)
    {    
        /* Configure the player */
        media_player_cfg.file_name   = file_name;
        media_player_cfg.data_p      = data_p;
        media_player_cfg.data_len    = data_len;
        media_player_cfg.format      = (kal_uint8)format;
        media_player_cfg.repeat      = 0; /* don't care */
        media_player_cfg.audio_path  = 0; /* don't care */
        media_player_cfg.fast_pass   = KAL_FALSE;
        media_player_cfg.cb_fct      = _aud_mma_player_event_hdlr;
        media_player_cfg.cb_param    = (void*)format;
        
        /* Open a player */
        result = media_player_p->open(media_player_p, &media_player_cfg);

        if (result == MED_RES_OK) /* Open successful */
        {
            player_p->handle  = (kal_int32)media_player_p;
            player_p->cb_func = cb_func;
            player_p->used    = KAL_TRUE;
            player_p->format  = format;
            
            if (g_mma_single_player.is_progressive_dl)
            {
                /* Put the player into underflow state if it's a progressive download.
                 * This is to prevent audio resource from being preempted by other applications.
                 */
                player_p->state = AUD_MEDIA_UNDERFLOW;
            }
            else
            {
                player_p->state = AUD_MEDIA_IDLE;
            }
        }
        else /* Open failed */
        {
            /* Destroy the player */
            media_player_p->destroy(media_player_p);
            media_player_p = NULL;
        }
    }
    
    /* Copy out player handler */
    *handle_p = (kal_uint32)media_player_p;
    
    return result;

}


#if defined(__MED_MPL_PLAYER__)
/*****************************************************************************
 * FUNCTION
 *  _aud_mma_open_mpl_player
 * DESCRIPTION
 *  This function is to open a MPL player.
 * PARAMETERS
 * app_id           [IN]      App ID. Currently used by RM player only.
 * file_name        [IN]      File name. If not NULL, the pui1_data will be ignored.
 * data_p           [IN]      Media data. If ws_file_name is NULL, this pointer must not be NULL.
 * data_len         [IN]      The length of media data. Valid only if pui1_data is not NULL.
 * format           [IN]      Media format.
 * repeats          [IN]      Repeat times.
 * aud_path         [IN]      Audio Path
 * cb_func          [IN]      Callback function.
 * handle_p         [OUT]     Player handle.
 * RETURNS
 *  MED_RES_OK                Successful.
 *  Others                    Failed.
 *****************************************************************************/
static kal_int32 _aud_mma_open_mpl_player(kal_uint16 app_id,
                                         kal_wchar* file_name,
                                         kal_uint8* data_p,
                                         kal_uint32 data_len,
                                         kal_int16  format,
                                         kal_int16  repeats,
                                         kal_uint8  aud_path,
                                         kal_int32  cb_func,
                                         kal_int32* handle_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_mma_multiple_player_struct* player_p;
    med_aud_player_cfg_t mpl_player_cfg;
    med_aud_player_t* mpl_player_p = NULL;
    kal_int32 result = MED_RES_FAIL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    player_p = &(g_mma_multiple_player[MMA_SINGLE_PLAYER_IDX]);

    if (player_p->used)
    {
        return MED_RES_BUSY;
    }
    
    /* Construct a player */
    mpl_player_p = aud_player_mpl_construct();
    
    if (mpl_player_p != NULL)
    {    
        /* Configure the player */
        mpl_player_cfg.app_id     = app_id;
        mpl_player_cfg.file_name  = file_name;
        mpl_player_cfg.data_p     = data_p;
        mpl_player_cfg.data_len   = data_len;
        mpl_player_cfg.format     = (kal_uint8)format;
        mpl_player_cfg.repeat     = 0; /* don't care */
        mpl_player_cfg.fast_pass  = KAL_FALSE;
        mpl_player_cfg.audio_path = aud_path;
        mpl_player_cfg.cb_fct     = _aud_mma_player_event_hdlr;
        mpl_player_cfg.cb_param   = (void*)format;

        /* Open a player */
        result = mpl_player_p->open(mpl_player_p, &mpl_player_cfg);

        if (result == MED_RES_OK) /* Open successful */
        {
            player_p->handle  = (kal_int32)mpl_player_p;
            player_p->cb_func = cb_func;
            player_p->used    = KAL_TRUE;
            player_p->format  = format;
            player_p->state   = AUD_MEDIA_IDLE;
        }
        else /* Open failed */
        {
            /* Destroy the player */
            mpl_player_p->destroy(mpl_player_p);
            mpl_player_p = NULL;
        }
    }

    /* Copy out player handler */
    *handle_p = (kal_int32)mpl_player_p;
    
    return result;
}
#endif /* defined(__MED_MPL_PLAYER__) */


/*****************************************************************************
 * FUNCTION
 *  _aud_mma_play_multiple_req
 * DESCRIPTION
 *  This function is to play a multiple player.
 * PARAMETERS
 *  handle          [IN]        Player handle.
 *  media_type      [IN]        Media type.
 * RETURNS
 *  MES_RES_OK                  Successful.
 *  Others                      Failed.
 *****************************************************************************/
static kal_int32 _aud_mma_play_multiple_req(kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_mma_multiple_player_struct* player_p;
    med_aud_player_t* mma_player_p;
    kal_int32 result = MED_RES_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Validate handle */
    player_p = _aud_mma_get_multiple_player_handle(handle);

    mma_player_p = (med_aud_player_t*) handle;

    /* Check state */
    if (player_p->state == AUD_MEDIA_IDLE)
    {
        /* Play the MMA player */
        result = mma_player_p->play(mma_player_p);

        if (result == MED_RES_OK)
        {
            player_p->state = AUD_MEDIA_PLAY;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  _aud_mma_build_cache_cb_fct
 * DESCRIPTION
 *  This function is to notify the mma client to update duration when build
 *  cache is done.
 * PARAMETERS
 *  reason          [IN]        Notify reason
 *  param           [IN]        Private data
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_mma_build_cache_cb_fct(kal_uint8 reason, void* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_mma_multiple_player_struct* player_p = NULL;
    med_handler cb_func;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    _AUD_MODULE_MMA2_TRACE(reason, param);
    
    if (reason == AUD_SEEK_REASON_DONE)
    {
        player_p = &(g_mma_multiple_player[MMA_SINGLE_PLAYER_IDX]);

        if (player_p->used && (player_p->handle == (kal_int32)param))
        {
            /* Notify client with duration updated event */
            cb_func = (med_handler) player_p->cb_func;

            if (cb_func)
            {
                cb_func(player_p->handle, MED_RES_AUD_DUR_UPDATED);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  _aud_mma_play_single_req
 * DESCRIPTION
 *  This function is to play a single player.
 * PARAMETERS
 *  handle          [IN]        Player handle.
 * RETURNS
 *  MES_RES_OK                  Successful.
 *  Others                      Failed.
 *****************************************************************************/
static kal_int32 _aud_mma_play_single_req(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_mma_multiple_player_struct *player_p;
    med_aud_player_t* aud_player_p;
    kal_uint32 fsal_file_size;
    kal_int32 result = MED_RES_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Validate handle */
    player_p = _aud_mma_get_multiple_player_handle(handle);

    aud_player_p = (med_aud_player_t*) handle;

    /* Check player state */
    if ((player_p->state != AUD_MEDIA_IDLE) && (player_p->state != AUD_MEDIA_UNDERFLOW))
    {
        return MED_RES_FAIL;
    }

    switch (player_p->format)
    {
        case MED_TYPE_SMF:
        case MED_TYPE_IMELODY:
        #if defined(__MED_BT_A2DP_MOD__) && defined(__BTMTK__)
            aud_bt_a2dp_open_codec((kal_int32)player_p->format);
        #endif
        
            result = aud_player_p->play(aud_player_p);
            
            break;

        #ifdef __VM_CODEC_SUPPORT__
            case MED_TYPE_GSM_FR:
            case MED_TYPE_GSM_HR:
            case MED_TYPE_GSM_EFR:
            case MED_TYPE_VR:
        #endif /*__VM_CODEC_SUPPORT__*/

        #ifdef WAV_CODEC
            case MED_TYPE_PCM_8K:
            case MED_TYPE_PCM_16K:
            case MED_TYPE_G711_ALAW:
            case MED_TYPE_G711_ULAW:
            case MED_TYPE_DVI_ADPCM:
            case MED_TYPE_WAV:
            case MED_TYPE_WAV_ALAW:
            case MED_TYPE_WAV_ULAW:
            case MED_TYPE_WAV_DVI_ADPCM:
        #endif /* WAV_CODEC */
        
        #ifdef DAF_DECODE
            case MED_TYPE_DAF:
        #ifdef MUSICAM_DECODE
            case MED_TYPE_MUSICAM:
        #endif /* MUSICAM_DECODE */
        #endif /* DAF_DECODE */
            
        #ifdef AMR_DECODE
            case MED_TYPE_AMR:
        #ifdef AMRWB_DECODE
            case MED_TYPE_AMR_WB:
        #endif /* AMRWB_DECODE */
        #endif /* AMR_DECODE */
        
        #ifdef AIFF_DECODE
            case MED_TYPE_AIFF:
        #endif /* AIFF_DECODE */
        
        #ifdef AU_DECODE
            case MED_TYPE_AU:
        #endif /* AU_DECODE */ 
        
        #ifdef AAC_DECODE
            case MED_TYPE_AAC:
        #endif /* AAC_DECODE */
        
        #ifdef BSAC_DECODE
/* under construction !*/
        #endif /* BSAC_DECODE */
        
        #ifdef WMA_DECODE
            case MED_TYPE_WMA:
        #endif /* WMA_DECODE */
        
        #ifdef M4A_DECODE
            case MED_TYPE_M4A:
        #endif /* M4A_DECODE */

        #if defined(MED_PURE_AUDIO) //|| defined(MP4_DECODE)
            case MED_TYPE_3GP:
            case MED_TYPE_MP4:
        #endif /* MED_PURE_AUDIO || MP4_DECODE */

        #ifdef __RM_DEC_SUPPORT__
            case MED_TYPE_RA:
            case MED_TYPE_RM:
            case MED_TYPE_RMVB:
            case MED_TYPE_RV:
        #endif /* __RM_DEC_SUPPORT */
        #ifdef __FLV_FILE_FORMAT_SUPPORT__
            case MED_TYPE_FLV:
            case MED_TYPE_F4V:
            case MED_TYPE_F4A:
        #endif /*__FLV_FILE_FORMAT_SUPPORT__*/
            
        #ifdef __APE_DECODE__
            case MED_TYPE_APE:
        #endif /* __APE_DECODE__ */
        #ifdef __VORBIS_DECODE__
            case MED_TYPE_VORBIS:
        #endif /*__VORBIS_DECODE__*/
        #ifdef __FLAC_DECODE__
            case MED_TYPE_FLAC:
        #endif
            {
                /* Continue play from underflow position */
                if (player_p->state == AUD_MEDIA_UNDERFLOW)
                {
                    FSAL_GetFileSize(&g_mma_single_player.fsal_handle, &fsal_file_size);

                    if (g_mma_single_player.underflow_file_size < fsal_file_size)
                    {
                        /* Use file offset directly to fast restore. (MP3,AAC Only. Other format will use current time)*/
                        aud_player_p->set(aud_player_p, AUD_PLAYER_SET_STORE_FLAG, (void*)KAL_TRUE);//, sizeof(kal_bool));
                        aud_player_p->set(aud_player_p, AUD_PLAYER_SET_START_TIME, (void*)g_mma_single_player.underflow_time);//, sizeof(kal_uint32));
                        aud_player_p->set(aud_player_p, AUD_PLAYER_SET_FILE_OFFSET, (void*)g_mma_single_player.underflow_offset);//, sizeof(kal_uint32));
                    }
                    else
                    {
                        return MED_RES_BUFFER_INSUFFICIENT;
                    }
                }

            #if defined(__MED_BT_A2DP_MOD__) && defined(__BTMTK__)
                aud_bt_a2dp_open_codec((kal_int32)player_p->format);
            #endif
            
                result = aud_player_p->play(aud_player_p);

                break;
            }
            default:
                ASSERT(0);
                break;
    }

    _AUD_MODULE_MMA2_TRACE(g_mma_single_player.is_progressive_dl, g_mma_single_player.is_dl_finish);

    if (result == MED_RES_OK)
    {
        player_p->state = AUD_MEDIA_PLAY;

        /* DO NOT auto build cache for low cost project because the build cache process requires
         * both CPU and memory resource. With limited resources, to auto build cache may dramatically
         * drag down the performance [MAUI_02862998].
         */
    #if !defined(MED_V_NOT_PRESENT) && defined(__MTK_TARGET__)
        if (g_mma_single_player.file_name && g_mma_single_player.cache_table)
        {
            if (aud_media_is_build_cache_required(g_mma_single_player.file_name))
            {
                /* Start build cache in non-blocking way */
                media_aud_start_build_cache_in_async(kal_get_active_module_id(),
                                                     g_mma_single_player.file_name,
                                                     g_mma_single_player.cache_table,
                                                     AUD_CACHE_TABLE_SIZE,
                                                     _aud_mma_build_cache_cb_fct,
                                                     (void*)handle);

                g_mma_single_player.is_building_cache = KAL_TRUE;
            }
        }
    #endif /* ! MED_V_NOT_PRESENT && __MTK_TARGET__ */
    }
    else
    {
        /* Seek exceed end of file when progressive download not finish */
        if((result == MED_RES_END_OF_FILE) && g_mma_single_player.is_progressive_dl && !g_mma_single_player.is_dl_finish)
        {
            player_p->state = AUD_MEDIA_UNDERFLOW;        

            /* Keep file offset in driver for fast restore.(MP3,AAC Only. Other format will use current time) */
            _aud_mma_pdl_get_information(aud_player_p);
            FSAL_GetFileSize(&g_mma_single_player.fsal_handle, &g_mma_single_player.underflow_file_size);

            return MED_RES_BUFFER_INSUFFICIENT;
        }
    }
    
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  _aud_mma_close_and_destory_player
 * DESCRIPTION
 *  This function helps to close and destory
 * PARAMETERS
 *  aud_player_p       [IN]     player to close and destory
 * RETURNS
 *  kal_int32       result of close action
 *****************************************************************************/
static kal_int32 _aud_mma_close_and_destory_player(med_aud_player_t* aud_player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    result = aud_player_p->close(aud_player_p);
    aud_player_p->destroy(aud_player_p);

    return result;

}

/*****************************************************************************
 * FUNCTION
 *  _aud_mma_set_result_and_event
 * DESCRIPTION
 *  This function helps to set result and event
 * PARAMETERS
 *  result       [IN]
 *  event        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void _aud_mma_set_result_and_event(kal_int32 result, kal_uint32 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    mma_set_result(result);
    MMA_SET_EVENT(event);

}

/*****************************************************************************
 * FUNCTION
 *  _aud_mma_check_is_resurce_available_and_set_event
 * DESCRIPTION
 *  This function helps to check if resource available and set result / event
 * PARAMETERS
 *  aud_player_p       [IN]     player to close and destory
 * RETURNS
 *  kal_bool       result of resource check
 *****************************************************************************/
static kal_bool _aud_mma_check_is_resurce_available_and_set_event(kal_uint32 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    if (! aud_media_is_resource_available(AUD_RESOURCE_AUDIO))
    {
        _aud_mma_set_result_and_event(MED_RES_BUSY,event);
        return KAL_FALSE;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  _aud_mma_get_default_bitrate
 * DESCRIPTION
 *  This function gets default bitrate for a given media format.
 * PARAMETERS
 *  media_format       [IN]     Media format
 * RETURNS
 *  Default bitrate for the given media format.
 *****************************************************************************/
static kal_uint32 _aud_mma_get_default_bitrate(kal_int16 media_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 default_bitrate = 0;
    
    switch (media_format)
    {
        case MED_TYPE_SMF:     /* midi */
        case MED_TYPE_TONE:    /* tone */
        case MED_TYPE_IMELODY: /* imy */ 
            default_bitrate = 0;
            break;
        case MED_TYPE_WAV:     /* wav */ /* 8K~96K per second */
            default_bitrate = 50000;
            break;
        case MED_TYPE_AMR:     /* amr */
            default_bitrate = 1550;
            break;
        case MED_TYPE_DAF:     /* mp3 */
            default_bitrate = 40000;
            break;
        case MED_TYPE_AAC:     /* aac */
        case MED_TYPE_WMA:     /* wma */
        case MED_TYPE_MUSICAM: /* mp2: need confirm */
        case MED_TYPE_M4A:     /* m4a: need confirm */
        case MED_TYPE_AIFF:    /* aiff: need confirm */
            default_bitrate = 36000;
            break;
        case MED_TYPE_AU:      /* au */
            default_bitrate = 8192;
            break;
        case MED_TYPE_RMVB:    /* rmvb */
        case MED_TYPE_RM:      /* rm */
        case MED_TYPE_RA:      /* ra */
        case MED_TYPE_RV:      /* rv */
            default_bitrate = 36000;
            break;
        case MED_TYPE_FLV:     /* flv */
        case MED_TYPE_F4V:     /* f4v */
        case MED_TYPE_F4A:     /* f4a */
            default_bitrate = 36000;
            break;

        default:
            default_bitrate = 0;
            break;
    }

    return default_bitrate;
}

     
/*****************************************************************************
 * FUNCTION
 *  _aud_mma_get_bit_rate
 * DESCRIPTION
 *  This function is to get bit-rate for a given file.
 * PARAMETERS
 *  file_name       [IN]     File name.
 * RETURNS
 *  Bitrate of the given file.
 *****************************************************************************/
static kal_uint32 _aud_mma_get_bit_rate(kal_wchar *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16            media_format;
    kal_int32            result;
    med_aud_player_t*    media_player_p = NULL;
    med_aud_player_cfg_t media_player_cfg = {0};
    audInfoStruct*       aud_info_p;
    kal_uint32           bit_rate = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* get MED type */
    media_format = med_get_media_type(file_name);

    /* Invalid format */
    if (media_format == MED_TYPE_NONE)
    {
        return 0;
    }

    /* Construct a temporary player to get content info */
    media_player_p = aud_player_media_construct();
    
    if (media_player_p != NULL)
    {    
        /* Configure the player */
        media_player_cfg.file_name   = file_name;
        
        /* Open a player */
        result = media_player_p->open(media_player_p, &media_player_cfg);

        if (result == MED_RES_OK) /* Open successful */
        {
            /* Allocate buffer for content description */
            aud_info_p = (audInfoStruct*) get_ctrl_buffer(sizeof(audInfoStruct));

            {
                /* Get duration from content descriptor */
                result = media_player_p->get(media_player_p, AUD_PLAYER_GET_CONTENT_DESC, aud_info_p);//, sizeof(audInfoStruct));

                if (result == MED_RES_OK)
                {
                    bit_rate = aud_info_p->bitRate;
                }

                /* Remember to free the buffer */
                free_ctrl_buffer(aud_info_p);
            }

            _AUD_MODULE_MMA2_TRACE(bit_rate, media_player_p);

            /* Remember to close the temporary player */
            _aud_mma_close_and_destory_player(media_player_p);
            
        }
    }
    
    /* Use default bitrate if there is no bit-rate information */
    if (bit_rate == 0)
    {
        bit_rate = _aud_mma_get_default_bitrate(media_format);
    }

    return bit_rate;
}


/*****************************************************************************
 * FUNCTION
 *  _aud_mma_terminate_player
 * DESCRIPTION
 *  This function is to terminate an MMA player.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
static void _aud_mma_terminate_player(aud_mma_multiple_player_struct *player_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_player_t* aud_player_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (player_p->used)
    {

        aud_player_p = (med_aud_player_t*)player_p->handle;

        /* Stop/close/destory the player */
        aud_player_p->stop(aud_player_p);
        _aud_mma_close_and_destory_player(aud_player_p);

    #ifdef __MED_IMY_EVENT__
        /* Special handling for IMY */
        if (player_p->format == MED_TYPE_IMELODY ||
            player_p->format == MED_TYPE_SMF)
        {
            aud_melody_stop_driver();
        }
    #endif

        /* Sepcial handing for single player */
        if (_aud_mma_is_single_player(player_p->handle))
        {
            /* Close FSAL handle for progressive download */
            _aud_mma_close_single_fsal();

        #if !defined(MED_V_NOT_PRESENT) && defined(__MTK_TARGET__)
            if (g_mma_single_player.is_building_cache)
            {
                /* Stop previous build cache process */
                aud_build_cache_stop();
            
                /* Close build cache in non-blocking way */
                media_aud_close_build_cache_in_async(kal_get_active_module_id());
            
                g_mma_single_player.is_building_cache = KAL_FALSE;
            }
        #endif

            /* Reset cache table */
            g_mma_single_player.cache_table = NULL;
        }

        /* Notify client the player is terminated */
        if (player_p->cb_func)
        {
            ((med_handler)player_p->cb_func)(player_p->handle, MED_RES_TERMINATED);
        }
        
        /* Reset player */
        player_p->handle  = NULL;
        player_p->cb_func = NULL;
        player_p->used    = KAL_FALSE;
        player_p->format  = MED_TYPE_NONE;
    }
}

/*-----------------------------------------------------------------------------
                    public function declarations
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  aud_mma_startup
 * DESCRIPTION
 *  This function is the startup of the MMA module. Variables should be initiated
 *  here.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool aud_mma_startup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(&g_mma_single_player, 0, sizeof(aud_mma_single_player_struct));
    kal_mem_set(g_mma_multiple_player, 0, sizeof(aud_mma_multiple_player_struct) * MMA_NO_OF_PLAYER);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_is_playing
 * DESCRIPTION
 *  This function is to check if there is any MMA player(s) being played.
 * PARAMETERS
 *  mode    [IN]    Check mode
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool aud_mma_is_playing(aud_mma_check_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    kal_bool is_playing;
    aud_mma_multiple_player_struct *player_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    is_playing = KAL_FALSE;

    if (mode == AUD_MMA_CHECK_MODE_ALL) /* Check if any mma player is being used */
    { 
        for (i = 0; i < MMA_NO_OF_PLAYER; i ++)
        {
            player_p = &(g_mma_multiple_player[i]);

		#ifndef __AUDIO_ULTRA_SLIM__
            if (player_p->used && (player_p->state == AUD_MEDIA_PLAY || player_p->state == AUD_MEDIA_UNDERFLOW))
		#else
			if(player_p->used)
		#endif
            {
                is_playing = KAL_TRUE;
                break;
            }
        }
    }
    else if (mode == AUD_MMA_CHECK_MODE_SINGLE) /* Check if mma single player is being used */
    {
        player_p = &(g_mma_multiple_player[MMA_SINGLE_PLAYER_IDX]);

        if (player_p->used && (player_p->state == AUD_MEDIA_PLAY || player_p->state == AUD_MEDIA_UNDERFLOW))
        {
            is_playing = KAL_TRUE;
        }
    }

    return is_playing;
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_is_async_mode
 * DESCRIPTION
 *  This function is to check if current handle uses async mode
 * PARAMETERS
 *  hanlde      [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool aud_mma_is_async_mode(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_mma_multiple_player_struct *player_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    player_p = _aud_mma_get_multiple_player_handle(handle);

    return player_p->async_mode;
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_close_all
 * DESCRIPTION
 *  This function is to close all the MMA playbacks, includes any single and 
 *  multiple players.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_close_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    aud_mma_multiple_player_struct *player_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMA_NO_OF_PLAYER; i ++)
    {
        player_p = &(g_mma_multiple_player[i]);
        _aud_mma_terminate_player(player_p);
    }
}

/*****************************************************************************
 * FUNCTION
 *  aud_send_mma_open_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]
 *  handle      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_send_mma_open_cnf(module_type dest_mod, kal_uint8 result, kal_int32 handle, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_open_async_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_p = (media_mma_open_async_cnf_struct*) construct_local_para(sizeof(media_mma_open_async_cnf_struct), TD_CTRL);

    cnf_p->result = result;
    cnf_p->handle = handle;
    cnf_p->user_data = user_data;

    aud_send_ilm(dest_mod, MSG_ID_MEDIA_MMA_AYNC_OPEN_CNF, cnf_p, NULL);

}



/*****************************************************************************
 * FUNCTION
 *  aud_mma_open_req_hdlr
 * DESCRIPTION
 *  This function is to open a single or a multiple MMA handle.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 *  aysnc       [IN]     boolean to indicate if blocking or not
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_open_req_hdlr(ilm_struct *ilm_ptr, kal_bool async_open)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_mma_multiple_player_struct *player_p;
    media_mma_open_req_struct *req_p;
    media_mma_open_async_req_struct *req_async_p = NULL;

    kal_int32 handler;
    kal_wchar* file_path;
    kal_uint8 *data;
    kal_int32 size;
    kal_uint16 app_id;
    kal_int16 repeats;
    kal_uint8 media_type;
    kal_bool progressive_dl;
    kal_uint8 output_path;

    kal_uint8 result = MED_RES_OK;
    kal_int32 handle = 0;
    kal_uint8 i;
    kal_bool is_multiple_player = KAL_FALSE;
    kal_int16 med_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!async_open)
    {
        req_p = (media_mma_open_req_struct*) ilm_ptr->local_para_ptr;
        media_type = req_p->media_type;
        file_path = req_p->file_path;
        data = req_p->data;
        size = req_p->size;
        handler = req_p->handler;
        repeats = req_p->repeats;
        progressive_dl = req_p->progressive_dl;
        app_id = req_p->app_id;
        output_path = req_p->output_path;
    }
    else
    {
        req_async_p = (media_mma_open_async_req_struct*) ilm_ptr->local_para_ptr;
        media_type = req_async_p->media_type;
        file_path = req_async_p->file_path;
        data = req_async_p->data;
        size = req_async_p->size;
        handler = req_async_p->handler;
        repeats = req_async_p->repeats;
        progressive_dl = req_async_p->progressive_dl;
        app_id = req_async_p->app_id;
        output_path = req_async_p->output_path;
    }

    med_type = MMA_TO_MED(media_type);

    if(!_aud_mma_check_is_resurce_available_and_set_event(MMA_EVT_OPEN))
    {
        if(!async_open)
        {
            mma_set_handle(NULL);
        }
        else
        {
            aud_send_mma_open_cnf(ilm_ptr->src_mod_id, MED_RES_BUSY, NULL, req_async_p->user_data);
        }
        return;
    }
    
    /* stop playing tasks before open any multiple play task */
    if (AUD_IN_STATE(AUD_MEDIA_PLAY) || AUD_IN_STATE(AUD_MEDIA_PLAY_PAUSED))
    {
        aud_stop_unfinished_process();
    }

    /* Besides tone sequence, need either data or file path when open */
    if (med_type != MED_TYPE_TONE)
    {
        MED_ASSERT((data != NULL && file_path == NULL) || (data == NULL && file_path != NULL));
    }

#ifdef __MTK_TARGET__
    /* MMA single player & multiple players are exclusive */
    if (file_path == NULL)
    {
        switch (med_type)
        {
            /* Multiple player */
            case MED_TYPE_SMF:
            case MED_TYPE_IMELODY:
        #ifdef JTONE_SUPPORT
            case MED_TYPE_TONE:
        #endif
        #ifdef WAV_CODEC
            case MED_TYPE_WAV:
        #endif
                is_multiple_player = KAL_TRUE;
                break;

            default:
                break;
        }
    }

    if (is_multiple_player)
    {
        /* Terminate single player */
        player_p = &(g_mma_multiple_player[MMA_SINGLE_PLAYER_IDX]);
        _aud_mma_terminate_player(player_p);
    }
    else
    {
        /* Terminate multiple players */
        for (i = 1; i < MMA_NO_OF_PLAYER; i ++)
        {
            player_p = &(g_mma_multiple_player[i]);
            _aud_mma_terminate_player(player_p);
        }
    }

    /*
     * Open a file
     */
    if (file_path != NULL)
    {
        media_type = med_get_media_type(file_path);

        /* All files are single player but use different interface */
        switch (media_type)
        {
            case MED_TYPE_SMF:
            case MED_TYPE_IMELODY:
            {
                /* Streaming not support for MIDI, IMY */
                if (progressive_dl)
                {
                    result = MED_RES_INVALID_FORMAT;
                }
                else
                {
                    g_mma_single_player.is_progressive_dl = KAL_FALSE;
                    
                    result = _aud_mma_open_mma_player(file_path,
                                                      NULL,
                                                      0,
                                                      media_type,
                                                      repeats,
                                                      KAL_FALSE,
                                                      handler,
                                                      &handle);
                }
                
                break;
            }
    #ifdef __MED_MPL_PLAYER__
        #if defined(MED_PURE_AUDIO) //|| defined(MP4_DECODE)
            case MED_TYPE_3GP:
            case MED_TYPE_MP4:
        #endif
        #ifdef __RM_DEC_SUPPORT__
            case MED_TYPE_RA:
            case MED_TYPE_RM:
            case MED_TYPE_RMVB:
            case MED_TYPE_RV:
        #endif /*__RM_DEC_SUPPORT__*/

        #ifdef M4A_DECODE
            case MED_TYPE_M4A:
        #endif /* M4A_DECODE */

        #ifdef __FLV_FILE_FORMAT_SUPPORT__
            case MED_TYPE_FLV:
            case MED_TYPE_F4V:
            case MED_TYPE_F4A:
        #endif /*__FLV_FILE_FORMAT_SUPPORT__*/        
            {
                if (progressive_dl)
                {
                    result = MED_RES_INVALID_FORMAT;
                }
                else
                {
                    g_mma_single_player.is_progressive_dl = KAL_FALSE;

                    /* Open a RM player */
                    result = _aud_mma_open_mpl_player(app_id,
                                                     file_path,
                                                     NULL,
                                                     0,
                                                     media_type,
                                                     repeats,
                                                     output_path,
                                                     handler,
                                                     &handle);
                }
                
                break;
            }
    #endif /* __MED_MPL_PLAYER__ */

        #ifdef __VM_CODEC_SUPPORT__
            case MED_TYPE_GSM_FR:
            case MED_TYPE_GSM_HR:
            case MED_TYPE_GSM_EFR:
            case MED_TYPE_VR:
        #endif /*__VM_CODEC_SUPPORT__*/

        #ifdef WAV_CODEC
            case MED_TYPE_PCM_8K:
            case MED_TYPE_PCM_16K:
            case MED_TYPE_G711_ALAW:
            case MED_TYPE_G711_ULAW:
            case MED_TYPE_DVI_ADPCM:
            case MED_TYPE_WAV:
            case MED_TYPE_WAV_ALAW:
            case MED_TYPE_WAV_ULAW:
            case MED_TYPE_WAV_DVI_ADPCM:
        #endif /* WAV_CODEC */
        
        #ifdef DAF_DECODE
            case MED_TYPE_DAF:
        #ifdef MUSICAM_DECODE
            case MED_TYPE_MUSICAM:
        #endif /* MUSICAM_DECODE */
        #endif /* DAF_DECODE */
            
        #ifdef AMR_DECODE
            case MED_TYPE_AMR:
        #ifdef AMRWB_DECODE
            case MED_TYPE_AMR_WB:
        #endif /* AMRWB_DECODE */
        #endif /* AMR_DECODE */
        
        #ifdef AIFF_DECODE
            case MED_TYPE_AIFF:
        #endif /* AIFF_DECODE */
        
        #ifdef AU_DECODE
            case MED_TYPE_AU:
        #endif /* AU_DECODE */ 
        
        #ifdef AAC_DECODE
            case MED_TYPE_AAC:
        #endif /* AAC_DECODE */
        
        #ifdef WMA_DECODE
            case MED_TYPE_WMA:
        #endif /* WMA_DECODE */

        #ifdef __APE_DECODE__
            case MED_TYPE_APE:
        #endif /* __APE_DECODE__ */
        #ifdef __VORBIS_DECODE__
            case MED_TYPE_VORBIS:
        #endif /*__VORBIS_DECODE__*/
        #ifdef __FLAC_DECODE__
            case MED_TYPE_FLAC:
        #endif


            {
                if (progressive_dl)
                {
                    g_mma_single_player.is_progressive_dl = KAL_TRUE;
                    g_mma_single_player.is_dl_finish = KAL_FALSE;                    
                    g_mma_single_player.underflow_offset = 0;
                    g_mma_single_player.underflow_time = 0;
                    g_mma_single_player.underflow_file_size = 0;
                    g_mma_single_player.bit_rate = _aud_mma_get_bit_rate(file_path);
                    g_mma_single_player.media_end_play_count = 0;
                }
                else
                {
                    g_mma_single_player.is_progressive_dl = KAL_FALSE;
                }

                result = _aud_mma_open_media_player(file_path,
                                                    NULL,
                                                    0,
                                                    media_type,
                                                    repeats,
                                                    handler,
                                                    &handle);
                break;
            }
            default:
                /* Not support type */
                result = MED_RES_INVALID_FORMAT;
                break;
        }
    }
    /*
     * Open data stream
     */
    else
    {
        /* Streaming not support for data type */
        if (progressive_dl)
        {
            result = MED_RES_INVALID_FORMAT;
        }
        else
        {
            switch (med_type)
            {
                /* Multiple player */
                case MED_TYPE_SMF:
                case MED_TYPE_IMELODY:
            #ifdef JTONE_SUPPORT
                case MED_TYPE_TONE:
            #endif
            #ifdef WAV_CODEC
                case MED_TYPE_WAV:
            #endif
                {
                    result = _aud_mma_open_mma_player(NULL,
                                                      data,
                                                      size,
                                                      med_type,
                                                      repeats,
                                                      KAL_FALSE,
                                                      handler,
                                                      &handle);
                    break;
                }

        #ifdef __MED_MPL_PLAYER__
            #if defined(MED_PURE_AUDIO) //|| defined(MP4_DECODE)
                case MED_TYPE_3GP:
                case MED_TYPE_MP4:
            #endif
            #ifdef __RM_DEC_SUPPORT__
                case MED_TYPE_RA:
                case MED_TYPE_RM:
                case MED_TYPE_RMVB:
                case MED_TYPE_RV:
            #endif /* __RM_DEC_SUPPORT__ */

            #ifdef M4A_DECODE
                case MED_TYPE_M4A:
            #endif /* M4A_DECODE */

            #ifdef __FLV_FILE_FORMAT_SUPPORT__
                case MED_TYPE_FLV:
                case MED_TYPE_F4V:
                case MED_TYPE_F4A:
            #endif /*__FLV_FILE_FORMAT_SUPPORT__*/
                {
                    g_mma_single_player.is_progressive_dl = KAL_FALSE;
                    
                    /* Open a RM player */
                    result = _aud_mma_open_mpl_player(app_id,
                                                     NULL,
                                                     data,
                                                     size,
                                                     med_type,
                                                     repeats,
                                                     output_path,
                                                     handler,
                                                     &handle);
                    break;
                }
        #endif /* __MED_MPL_PLAYER__ */

            #ifdef __VM_CODEC_SUPPORT__
                case MED_TYPE_GSM_FR:
                case MED_TYPE_GSM_HR:
                case MED_TYPE_GSM_EFR:
                case MED_TYPE_VR:
            #endif /*__VM_CODEC_SUPPORT__*/

            #ifdef WAV_CODEC
                case MED_TYPE_PCM_8K:
                case MED_TYPE_PCM_16K:
                case MED_TYPE_G711_ALAW:
                case MED_TYPE_G711_ULAW:
                case MED_TYPE_DVI_ADPCM:
                case MED_TYPE_WAV_ALAW:
                case MED_TYPE_WAV_ULAW:
                case MED_TYPE_WAV_DVI_ADPCM:
            #endif /* WAV_CODEC */
        
            #ifdef DAF_DECODE
                case MED_TYPE_DAF:
            #ifdef MUSICAM_DECODE
                case MED_TYPE_MUSICAM:
            #endif /* MUSICAM_DECODE */
            #endif /* DAF_DECODE */
                
            #ifdef AMR_DECODE
                case MED_TYPE_AMR:
            #ifdef AMRWB_DECODE
                case MED_TYPE_AMR_WB:
            #endif /* AMRWB_DECODE */
            #endif /* AMR_DECODE */
            
            #ifdef AIFF_DECODE
                case MED_TYPE_AIFF:
            #endif /* AIFF_DECODE */
            
            #ifdef AU_DECODE
                case MED_TYPE_AU:
            #endif /* AU_DECODE */ 
            
            #ifdef AAC_DECODE
                case MED_TYPE_AAC:
            #endif /* AAC_DECODE */
            
            #ifdef WMA_DECODE
                case MED_TYPE_WMA:
            #endif /* WMA_DECODE */

            #ifdef __APE_DECODE__
                case MED_TYPE_APE:
            #endif /* __APE_DECODE__ */

            #ifdef __VORBIS_DECODE__
                case MED_TYPE_VORBIS:
            #endif /*__VORBIS_DECODE__*/
            #ifdef __FLAC_DECODE__
                case MED_TYPE_FLAC:
            #endif

                {
                    g_mma_single_player.is_progressive_dl = KAL_FALSE;
                    
                    result = _aud_mma_open_media_player(NULL,
                                                        data,
                                                        size,
                                                        med_type,
                                                        repeats,
                                                        handler,
                                                        &handle);
                    break;
                }

                default:
                    /* Not support type */
                    result = MED_RES_INVALID_FORMAT;
                    break;
            }
        }
    }

#else /* __MTK_TARGET__ */
    /* Redirect to MoDIS function */

    /* Not support progressive download in MoDIS */
    if (progressive_dl)
    {
        result = MED_RES_INVALID_FORMAT;
    }
    else
    {
        g_mma_single_player.is_progressive_dl = KAL_FALSE;
    
        result = _aud_mma_open_modis_player(file_path,
                                            data,
                                            size,
                                            med_type,
                                            repeats,
                                            handler,
                                            &handle);
    }
                    
#endif /* __MTK_TARGET__ */

    /* Keep output path setting */
    if (handle != 0)
    {
        player_p = _aud_mma_get_multiple_player_handle(handle);

        player_p->output_path = output_path;
    }

    if(!async_open)
    {
        _aud_mma_set_result_and_event(result,MMA_EVT_OPEN);
        mma_set_handle(handle);
    }
    else
    {
        aud_send_mma_open_cnf(ilm_ptr->src_mod_id, result, handle, req_async_p->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_set_cache_table_req_hdlr
 * DESCRIPTION
 *  This function is to set cache table for a single player.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_set_cache_table_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_cache_table_req_struct *req_p;
    kal_int32 result = MED_RES_FAIL;
    kal_bool is_single;
    med_aud_player_t* aud_player_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_set_cache_table_req_struct*) ilm_ptr->local_para_ptr;
    
    is_single = _aud_mma_is_single_player(req_p->handle);

    if (is_single)
    {
        med_aud_player_set_cache_t set_cache;
        aud_player_p = (med_aud_player_t*) req_p->handle;

        set_cache.cache_p = (void*)req_p->cache_tbl;
        set_cache.cache_size = AUD_CACHE_TABLE_SIZE;

        result = aud_player_p->set(aud_player_p, AUD_PLAYER_SET_CACHE_TABLE, (void*)&set_cache);//, AUD_CACHE_TABLE_SIZE);

        g_mma_single_player.cache_table = req_p->cache_tbl;
    }

    _aud_mma_set_result_and_event(result,MMA_EVT_WAIT);

}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_close_req_hdlr
 * DESCRIPTION
 *  This function is to close a media handle.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_close_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_close_req_struct *req_p;
    kal_int32 result = MED_RES_FAIL;
    aud_mma_multiple_player_struct* player_p;
    med_aud_player_t* aud_player_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_close_req_struct*) ilm_ptr->local_para_ptr;

    /* Validate handle */
    player_p = _aud_mma_get_multiple_player_handle(req_p->handle);


    aud_player_p = (med_aud_player_t*) req_p->handle;

    /* Close and destory player */
    result = _aud_mma_close_and_destory_player(aud_player_p);

#ifdef __MED_IMY_EVENT__    
    /* Special handling for IMY */
    if (player_p->format == MED_TYPE_IMELODY ||
        player_p->format == MED_TYPE_SMF)
    {
        aud_melody_stop_driver();
    }
#endif
    
    if (_aud_mma_is_single_player(req_p->handle))
    {
        /* Close FSAL handle for progressive download */
        _aud_mma_close_single_fsal();

    #if !defined(MED_V_NOT_PRESENT) && defined(__MTK_TARGET__)
        if (g_mma_single_player.is_building_cache)
        {
            /* Stop previous build cache process */
            aud_build_cache_stop();

            /* Close build cache in non-blocking way */
            media_aud_close_build_cache_in_async(kal_get_active_module_id());

            g_mma_single_player.is_building_cache = KAL_FALSE;
        }
    #endif

        /* Reset cache table */
        g_mma_single_player.cache_table = NULL;
    }

    /* Reset player data */
    player_p->used = KAL_FALSE;
    player_p->handle = NULL;
    player_p->cb_func = NULL;
    player_p->format = MED_TYPE_NONE;

    _aud_mma_set_result_and_event(result,MMA_EVT_CLOSE);
}

/*****************************************************************************
 * FUNCTION
 *  aud_mma_set_param_req_hdlr
 * DESCRIPTION
 *  This function is to set paramter to a specific handle
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_set_param_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_param_req_struct *req_p;
    aud_mma_multiple_player_struct* player_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_set_param_req_struct*) ilm_ptr->local_para_ptr;

    /* Update output path setting */
    player_p = _aud_mma_get_multiple_player_handle(req_p->handle);
    

    switch(req_p->param_type)
    {
        case AUD_MMA_PARAM_SET_ASYNC_MODE:
        {
            player_p->async_mode = *((kal_bool*)(req_p->param_value));
            break;
        }

        default:
            break;
    }

    return;

}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_build_BLISRC_table_req_hdlr
 * DESCRIPTION
 *  This function is to build BLISRC table to speed up mixed sampling rate playback
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_build_BLISRC_table_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_build_BLISRC_table_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_build_BLISRC_table_req_struct*) ilm_ptr->local_para_ptr;

    Media_SetBLISRC(req_p->turn_on);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_play_req_hdlr
 * DESCRIPTION
 *  This function is to play the media.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_play_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_play_req_struct *req_p;
    kal_int32 result = MED_RES_FAIL;
    kal_bool is_single;
    aud_mma_multiple_player_struct* player_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_play_req_struct*) ilm_ptr->local_para_ptr;

    /* Update output path setting */
    player_p = _aud_mma_get_multiple_player_handle(req_p->handle);


    if (! aud_media_is_resource_available(AUD_RESOURCE_AUDIO))
    {
        if(!player_p->async_mode)
        {
            _aud_mma_set_result_and_event(MED_RES_BUSY,MMA_EVT_PLAY);
        }
        else
        {
            if (player_p->cb_func)
            {
                ((med_handler)player_p->cb_func)(player_p->handle, MED_RES_BUSY);
            }
        }

        return;
    }

    /* Use current melody output path */
    if (player_p->output_path == AUDIO_DEVICE_SPEAKER)
    {
        aud_get_active_device_path_by_mode(aud_context_p->melody_output_device, aud_melody_set_output_device);
    }
    else /* Use output path specified in open request */
    {
        aud_get_active_device_path_by_mode(player_p->output_path, aud_melody_set_output_device);
    }
    
#ifdef __MTK_TARGET__
    is_single = _aud_mma_is_single_player(req_p->handle);

    if (is_single)
    {
        result = _aud_mma_play_single_req(req_p->handle);
    }
    else
    {
        result = _aud_mma_play_multiple_req(req_p->handle, MMA_TO_MED(req_p->media_type));
    }
#else /*__MTK_TARGET__*/

    result = _aud_mma_play_modis_req(req_p->handle);

#endif /*__MTK_TARGET__*/

    if(!player_p->async_mode)
    {
        _aud_mma_set_result_and_event(result,MMA_EVT_PLAY);
    }
    else
    {
        if (player_p->cb_func && result != MED_RES_OK)
        {
            ((med_handler)player_p->cb_func)(player_p->handle, MED_RES_FAIL);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_stop_req_hdlr
 * DESCRIPTION
 *  This function is to stop the media.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_stop_req_struct *req_p;
    kal_int32 result = MED_RES_FAIL;
    aud_mma_multiple_player_struct* player_p;
    med_aud_player_t* aud_player_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_stop_req_struct*) ilm_ptr->local_para_ptr;

    /* Validate handle */
    player_p = _aud_mma_get_multiple_player_handle(req_p->handle);


    if (! aud_media_is_resource_available(AUD_RESOURCE_AUDIO))
    {
        if(!player_p->async_mode)
        {
            _aud_mma_set_result_and_event(MED_RES_BUSY,MMA_EVT_STOP);
        }

        return;
    }

    aud_player_p = (med_aud_player_t*) req_p->handle;

    /* Stop player */
    result = aud_player_p->stop(aud_player_p);

    if (result == MED_RES_OK)
    {
        player_p->state = AUD_MEDIA_IDLE;
    }

#if !defined(MED_V_NOT_PRESENT) && defined(__MTK_TARGET__)
    if (_aud_mma_is_single_player(req_p->handle))
    {
        if (g_mma_single_player.is_building_cache)
        {
            /* Stop previous build cache process */
            aud_build_cache_stop();

            /* Close build cache in non-blocking way */
            media_aud_close_build_cache_in_async(kal_get_active_module_id());

            g_mma_single_player.is_building_cache = KAL_FALSE;
        }
    }
#endif /* ! MED_V_NOT_PRESENT && __MTK_TARGET__ */

    if(!player_p->async_mode)
    {
        _aud_mma_set_result_and_event(result,MMA_EVT_STOP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_pause_req_hdlr
 * DESCRIPTION
 *  This function is to pause the media.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_pause_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_pause_req_struct *req_p;
    kal_int32 result = MED_RES_UNSUPPORTED_OPERATION;
    aud_mma_multiple_player_struct* player_p;
    med_aud_player_t* aud_player_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(!_aud_mma_check_is_resurce_available_and_set_event(MMA_EVT_PAUSE))
    {
        return;
    }


    req_p = (media_mma_pause_req_struct*) ilm_ptr->local_para_ptr;

    player_p = _aud_mma_get_multiple_player_handle(req_p->handle);

    aud_player_p = (med_aud_player_t*) req_p->handle;

    _AUD_MODULE_MMA2_TRACE(player_p->state, player_p->handle);

    if (player_p->state == AUD_MEDIA_PLAY)
    {
    #ifdef __MED_IMY_EVENT__
        /* Special handler for IMY */
        if (player_p->format == MED_TYPE_IMELODY ||
            player_p->format == MED_TYPE_SMF)
        {
            aud_store_driver_status();
            aud_melody_stop_driver();
        }
    #endif
                
        /* Pause player */
        result = aud_player_p->pause(aud_player_p);

        if (result == MED_RES_OK) /* Pause successful */
        {
            player_p->state = AUD_MEDIA_PLAY_PAUSED;
        }
        else if (result == MED_RES_UNSUPPORTED_OPERATION) /* Some formats do not support PAUSE function, e.g AAC-ADIF */
        {
            /* Do nothing because player state is not changed */
        }
        else /* Pause failed */
        {
            /* Stop the player */
            aud_player_p->stop(aud_player_p);
            
            player_p->state = AUD_MEDIA_IDLE;
        }
    }

    _aud_mma_set_result_and_event(result,MMA_EVT_PAUSE);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_resume_req_hdlr
 * DESCRIPTION
 *  This function is to resume the media.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_resume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_resume_req_struct *req_p;
    kal_int32 result = MED_RES_FAIL;
    aud_mma_multiple_player_struct* player_p;
    med_aud_player_t* aud_player_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(!_aud_mma_check_is_resurce_available_and_set_event(MMA_EVT_RESUME))
    {
        return;
    }


    req_p = (media_mma_resume_req_struct*) ilm_ptr->local_para_ptr;

    /* No output path setting for mma now, use default setting */
    aud_get_active_device_path_by_mode(aud_context_p->melody_output_device, aud_melody_set_output_device);

    /* Validate handle */
    player_p = _aud_mma_get_multiple_player_handle(req_p->handle);

    aud_player_p = (med_aud_player_t*) req_p->handle;

    _AUD_MODULE_MMA2_TRACE(player_p->state, player_p->handle);

    if (player_p->state == AUD_MEDIA_PLAY_PAUSED)
    {
    #if defined(__MED_BT_A2DP_MOD__) && defined(__BTMTK__)
        if (_aud_mma_is_single_player(req_p->handle))
        {
            aud_bt_a2dp_open_codec((kal_int32)player_p->format);
        }
    #endif /* __MED_BT_A2DP_MOD__ && __BTMTK__ */
            
        /* Resume player */
        result = aud_player_p->resume(aud_player_p);

        if (result == MED_RES_OK) /* Resume successful */
        {
#ifdef __MED_IMY_EVENT__
            /* Special handler for IMY */
            if (player_p->format == MED_TYPE_IMELODY ||
                player_p->format == MED_TYPE_SMF)
            {
                aud_restore_driver_status();
            }
#endif
            
            player_p->state = AUD_MEDIA_PLAY;
        }
        else /* Resume failed */
        {
            /* Stop the player */
            aud_player_p->stop(aud_player_p);
            
            player_p->state = AUD_MEDIA_IDLE;
        }
    }
    else if (player_p->state == AUD_MEDIA_IDLE)
    {
        /* Player already stopped by driver, but MMI/JAVA still send out request */
        result = MED_RES_OK;
    }

    _aud_mma_set_result_and_event(result,MMA_EVT_RESUME);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_get_audio_info_req_hdlr
 * DESCRIPTION
 *  This function is to get audio info for a given file or data string.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_get_audio_info_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_audio_info_req_struct *req_p;
    //mma_get_meta_func get_meta_func = NULL;
    media_get_info_func_ptr get_desc_func = NULL;
    audInfoStruct *audio_info_p;
    kal_int32 result = MED_RES_OK;
    kal_int16 media_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    req_p = (media_mma_get_audio_info_req_struct*) ilm_ptr->local_para_ptr;

    if (req_p->file_path != NULL)
    {
        media_type = med_get_media_type(req_p->file_path);
    }
    else
    {
        media_type = MMA_TO_MED(req_p->media_type);
    }

    MED_ASSERT(req_p->audio_info != NULL);
    audio_info_p = (audInfoStruct*) req_p->audio_info;    

    get_desc_func = (media_get_info_func_ptr) aud_media_get_desc_func_pointer(media_type);


    if (get_desc_func != NULL)
    {
        FSAL_Status eFSALStatus;
        STFSAL *pstFSAL = 0;
        void* param ;        

        pstFSAL = (STFSAL*)get_ctrl_buffer( sizeof(STFSAL) );

        {
            memset(pstFSAL, 0, sizeof(STFSAL));
            
            if(NULL != req_p->file_path)
            {      
               eFSALStatus = FSAL_Open(pstFSAL, (void*)req_p->file_path, FSAL_READ);
            }
            else
            {
                ASSERT(req_p->data != 0);
                ASSERT(req_p->data_len != 0);
                FSAL_Direct_SetRamFileSize(pstFSAL, req_p->data_len);
                eFSALStatus = FSAL_Open(pstFSAL, req_p->data, FSAL_ROMFILE);
                ASSERT(eFSALStatus == FSAL_OK);
            }


            if(eFSALStatus != FSAL_OK)
            {
               result = MED_RES_FAIL;
            }  
            else
            {
                switch(media_type)
                { 
                #if defined(__RM_DEC_SUPPORT__)
                    case MED_TYPE_RA:
                    case MED_TYPE_RM:
                    case MED_TYPE_RMVB:
                    case MED_TYPE_RV:
                        param = (void*) req_p->app_id;
                        break;
                #endif /* __RM_DEC_SUPPORT__ */
                    
                #ifdef __FLV_FILE_FORMAT_SUPPORT__
                    case MED_TYPE_FLV:
                    case MED_TYPE_F4V:
                    case MED_TYPE_F4A:
                        param = (void*) req_p->app_id;
                    break;
                #endif /*__FLV_FILE_FORMAT_SUPPORT__*/  

                    default:
                        param = (void*)0;
                }

                if(get_desc_func(pstFSAL, audio_info_p, param ) != MEDIA_SUCCESS)
                {
                    result = MED_RES_FAIL;
                }

                if(NULL != req_p->file_path)
                {
                   FSAL_Close(pstFSAL);
                }
                
            }

            free_ctrl_buffer(pstFSAL);

        }

    }
    else
    {
        result = MED_RES_INVALID_FORMAT;
        memset(audio_info_p, 0, sizeof(audInfoStruct));
    }

    _aud_mma_set_result_and_event(result,MMA_EVT_GET_AUD_INFO);
}



/*****************************************************************************
 * FUNCTION
 *  aud_mma_get_duration_req_hdlr
 * DESCRIPTION
 *  This function is to get the duration of the media.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_get_duration_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_duration_req_struct *req_p;
    aud_mma_multiple_player_struct* player_p;
    med_aud_player_t* aud_player_p;
    kal_int32 result;
    kal_int32 duration = 0;
    audInfoStruct* aud_info_p = NULL;
    /* media player type shall use conetent desc, others can use GET duratioon. 
       Casue if media player files (XXX_Open) is not played yet, GET duration will return 0 */
    kal_bool is_get_duration_from_content_desc = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_get_duration_req_struct*) ilm_ptr->local_para_ptr;

    /* Validate player */
    player_p = _aud_mma_get_multiple_player_handle(req_p->handle);

    aud_player_p = (med_aud_player_t*) req_p->handle;

#ifdef __MTK_TARGET__

    switch (player_p->format)
    {
        case MED_TYPE_SMF:
        case MED_TYPE_IMELODY:
    #ifdef JTONE_SUPPORT
        case MED_TYPE_TONE:
    #endif /* JTONE_SUPPORT */
            is_get_duration_from_content_desc = KAL_FALSE;
            break;
            
    #ifdef WAV_CODEC
        case MED_TYPE_WAV:
            if (_aud_mma_is_single_player(req_p->handle))
            {
                is_get_duration_from_content_desc = KAL_TRUE;
            }
            else
            {
                is_get_duration_from_content_desc = KAL_FALSE;
            }
            break;
    #endif /* WAV_CODEC */

    #ifdef __VM_CODEC_SUPPORT__
        case MED_TYPE_GSM_FR:
        case MED_TYPE_GSM_HR:
        case MED_TYPE_GSM_EFR:
        case MED_TYPE_VR:
    #endif /*__VM_CODEC_SUPPORT__*/

    #ifdef WAV_CODEC
        case MED_TYPE_PCM_8K:
        case MED_TYPE_PCM_16K:
        case MED_TYPE_G711_ALAW:
        case MED_TYPE_G711_ULAW:
        case MED_TYPE_DVI_ADPCM:
        case MED_TYPE_WAV_ALAW:
        case MED_TYPE_WAV_ULAW:
        case MED_TYPE_WAV_DVI_ADPCM:
    #endif /* WAV_CODEC */
    
    #ifdef DAF_DECODE
        case MED_TYPE_DAF:
    #ifdef MUSICAM_DECODE
        case MED_TYPE_MUSICAM:
    #endif       
    #endif /* DAF_DECODE */

    #ifdef AMR_DECODE
        case MED_TYPE_AMR:
    #endif /* AMR_DECODE */
    
    #ifdef AMRWB_DECODE
        case MED_TYPE_AMR_WB:   
    #endif

    #ifdef AIFF_DECODE
        case MED_TYPE_AIFF:
    #endif /* AIFF_DECODE */
    
    #ifdef AU_DECODE
        case MED_TYPE_AU:
    #endif /* AU_DECODE */
    
    #ifdef AAC_DECODE
        case MED_TYPE_AAC:       
    #endif /* AAC_DECODE */

    #ifdef WMA_DECODE
        case MED_TYPE_WMA:
    #endif /* WMA_DECODE */

    #ifdef __APE_DECODE__
        case MED_TYPE_APE:
    #endif /* __APE_DECODE__ */

    #ifdef __VORBIS_DECODE__
        case MED_TYPE_VORBIS:
    #endif /*__VORBIS_DECODE__*/    
    #ifdef __FLAC_DECODE__
        case MED_TYPE_FLAC:
    #endif
            is_get_duration_from_content_desc = KAL_TRUE;
            break;

    #if defined(MED_PURE_AUDIO) //|| defined(MP4_DECODE)
        case MED_TYPE_MP4:
        case MED_TYPE_3GP:
            is_get_duration_from_content_desc = KAL_FALSE;
            break;
    #endif /* MED_PURE_AUDIO */

    #ifdef __RM_DEC_SUPPORT__
        case MED_TYPE_RA:
        case MED_TYPE_RM:
        case MED_TYPE_RMVB:
        case MED_TYPE_RV:
            is_get_duration_from_content_desc = KAL_FALSE;
            break;
    #endif /* __RM_DEC_SUPPORT */
            
    #ifdef M4A_DECODE
        case MED_TYPE_M4A:
            is_get_duration_from_content_desc = KAL_FALSE;
            break;
    #endif /* M4A_DECODE */

    #ifdef __FLV_FILE_FORMAT_SUPPORT__
            case MED_TYPE_FLV:
            case MED_TYPE_F4V:
            case MED_TYPE_F4A:
                is_get_duration_from_content_desc = KAL_FALSE;
            break;
    #endif /*__FLV_FILE_FORMAT_SUPPORT__*/

        default:
            ASSERT(0);
            break;
    }
    
    if (is_get_duration_from_content_desc && (!req_p->use_default_handle))
    {
        /* Allocate buffer for content description */
        aud_info_p = (audInfoStruct*) get_ctrl_buffer(sizeof(audInfoStruct));

        {
            /* Get duration from content description */
            result = aud_player_p->get(aud_player_p, AUD_PLAYER_GET_CONTENT_DESC, aud_info_p);//, sizeof(audInfoStruct));

            if (result == MED_RES_OK)
            {
                duration = aud_info_p->time;
            }

            /* Remember to free the buffer */
            free_ctrl_buffer(aud_info_p);
        }
    }
    else
    {
        /* Get duration from player */
        result = aud_player_p->get(aud_player_p, AUD_PLAYER_GET_DURATION, &duration);//, sizeof(kal_uint32));
    }
    
#else /*__MTK_TARGET__*/

    /* MoDIS */
    result = aud_player_p->get(aud_player_p, AUD_PLAYER_GET_DURATION, &duration); //, sizeof(kal_uint32));

#endif /*__MTK_TARGET__*/

    _aud_mma_set_result_and_event(duration,MMA_EVT_GET_DURATION);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_get_current_time_req_hdlr
 * DESCRIPTION
 *  This function is to get current time of the media which is being played.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_get_current_time_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_current_time_req_struct *req_p;
    kal_int32 curr_time = 0;
    med_aud_player_t* aud_player_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_get_current_time_req_struct*) ilm_ptr->local_para_ptr;
    
    /* Validate handle */
    aud_player_p = (med_aud_player_t*) req_p->handle;

    /* Get current time */
    aud_player_p->get(aud_player_p, AUD_PLAYER_GET_CURRENT_TIME, &curr_time);//, sizeof(kal_uint32));

    _aud_mma_set_result_and_event(curr_time,MMA_EVT_GET_CURR_TIME);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_set_start_time_req_hdlr
 * DESCRIPTION
 *  This function is to set the start time of the media.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_set_start_time_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_start_time_req_struct *req_p;
    kal_int32 result;
    aud_mma_multiple_player_struct* player_p;
    med_aud_player_t* aud_player_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_set_start_time_req_struct*) ilm_ptr->local_para_ptr;
    
    /* Validate handle */
    aud_player_p = (med_aud_player_t*) req_p->handle;

    /* Set start time */
    result = aud_player_p->set(aud_player_p, AUD_PLAYER_SET_START_TIME, (void*)req_p->start_time);//, sizeof(kal_uint32));

    /* We have to check if the start time is less than the time of underflow. 
     * If so, we have to reset player state to seek from the beginning because
     * the last time/offset stored when underflow is not applicable any more.
     */
    if (_aud_mma_is_single_player(req_p->handle))
    {
        player_p = &(g_mma_multiple_player[MMA_SINGLE_PLAYER_IDX]);

        if (player_p->state == AUD_MEDIA_UNDERFLOW)
        {
            if (req_p->start_time < g_mma_single_player.underflow_time)
            {
                aud_player_p->set(aud_player_p, AUD_PLAYER_SET_STORE_FLAG, (void*)KAL_FALSE);//, sizeof(kal_bool));
                player_p->state = AUD_MEDIA_IDLE;
            }
        }
    }

    _aud_mma_set_result_and_event(result,MMA_EVT_SET_START_TIME);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_set_stop_time_req_hdlr
 * DESCRIPTION
 *  This function is to set the stop time of the media.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_set_stop_time_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_stop_time_req_struct *req_p;
    kal_int32 result;
    med_aud_player_t* aud_player_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_set_stop_time_req_struct*) ilm_ptr->local_para_ptr;
    
    /* Validate handle */
    aud_player_p = (med_aud_player_t*) req_p->handle;

    /* Set stop time */
    result = aud_player_p->set(aud_player_p, AUD_PLAYER_SET_STOP_TIME, (void*)req_p->stop_time);//, sizeof(kal_uint32));

    _aud_mma_set_result_and_event(result,MMA_EVT_SET_STOP_TIME);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_get_volume_req_hdlr
 * DESCRIPTION
 *  This function is to get digital gain of the media.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_get_volume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_volume_req_struct *req_p;
    kal_uint8 volume = 0;
    med_aud_player_t* aud_player_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_get_volume_req_struct*) ilm_ptr->local_para_ptr;
    
    /* Validate handle */
    aud_player_p = (med_aud_player_t*) req_p->handle;
    
    /* Get volume level */
    aud_player_p->get(aud_player_p, AUD_PLAYER_GET_LEVEL, (void*)&volume);//, sizeof(kal_uint8));

    _aud_mma_set_result_and_event((kal_int32)volume,MMA_EVT_GET_VOLUME);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_set_volume_req_hdlr
 * DESCRIPTION
 *  This function is to set the digital gain of the media.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_set_volume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_volume_req_struct *req_p;
    kal_int32 result;
    med_aud_player_t* aud_player_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_set_volume_req_struct*) ilm_ptr->local_para_ptr;
    
    /* Validate handle */
    aud_player_p = (med_aud_player_t*) req_p->handle;
    
    /* Set volume level */
    result = aud_player_p->set(aud_player_p, AUD_PLAYER_SET_LEVEL, (void*)req_p->volume);//, sizeof(kal_uint8));

    _aud_mma_set_result_and_event(result,MMA_EVT_SET_VOLUME);
}


#ifdef __MED_MMA_EXTRA_CTRL__
/*****************************************************************************
 * FUNCTION
 *  aud_mma_set_rate_req_hdlr
 * DESCRIPTION
 *  This function is to set the rate of the media.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_set_rate_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_rate_req_struct *req_p;
    kal_int32 result;
    med_aud_player_t* aud_player_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_set_rate_req_struct*) ilm_ptr->local_para_ptr;
    
    /* Validate handle */
    aud_player_p = (med_aud_player_t*) req_p->handle;
    
    /* Set rate */
    result = aud_player_p->set(aud_player_p, MMA_PLAYER_SET_RATE, (void*)req_p->rate);//, sizeof(kal_int32));

    _aud_mma_set_result_and_event(result,MMA_EVT_SET_RATE);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_set_tempo_req_hdlr
 * DESCRIPTION
 *  This function is to set the tempo of the media.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_set_tempo_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_tempo_req_struct *req_p;
    kal_int32 result;
    med_aud_player_t* aud_player_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_set_tempo_req_struct*) ilm_ptr->local_para_ptr;
    
    /* Validate handle */
    aud_player_p = (med_aud_player_t*) req_p->handle;
    
    /* Set tempo */
    result = aud_player_p->set(aud_player_p, MMA_PLAYER_SET_TEMPO, (void*)req_p->tempo);//, sizeof(kal_int32));

    _aud_mma_set_result_and_event(result,MMA_EVT_SET_TEMPO);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_set_pitch_req_hdlr
 * DESCRIPTION
 *  This function is to set the pitch of the media.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_set_pitch_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_pitch_req_struct *req_p;
    kal_int32 result;
    med_aud_player_t* aud_player_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_set_pitch_req_struct*) ilm_ptr->local_para_ptr;
    
    /* Validate handle */
    aud_player_p = (med_aud_player_t*) req_p->handle;
    
    /* Set pitch */
    result = aud_player_p->set(aud_player_p, MMA_PLAYER_SET_PITCH, (void*)req_p->pitch);//, sizeof(kal_int32));

    _aud_mma_set_result_and_event(result,MMA_EVT_SET_PITCH);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_send_long_msg_req_hdlr
 * DESCRIPTION
 *  This function is to send long msg of the media.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_send_long_msg_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_send_long_msg_req_struct *req_p;
    kal_int32 result;
    med_aud_player_t* aud_player_p;
    med_aud_player_mma_set_long_msg_t long_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!_aud_mma_check_is_resurce_available_and_set_event(MMA_EVT_SEND_LONG_MSG))
    {
        return;
    }


    req_p = (media_mma_send_long_msg_req_struct*) ilm_ptr->local_para_ptr;
    
    /* Validate handle */
    aud_player_p = (med_aud_player_t*) req_p->handle;
    
    /* Set long message */
    long_msg.buf_p = req_p->buf;
    long_msg.len = req_p->len;

    result = aud_player_p->set(aud_player_p, MMA_PLAYER_SET_LONG_MSG, (void*)&long_msg);//, sizeof(med_aud_player_mma_set_long_msg_t));

    _aud_mma_set_result_and_event(result,MMA_EVT_SEND_LONG_MSG);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_send_short_msg_req_hdlr
 * DESCRIPTION
 *  This function is to send short msg of the media.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_send_short_msg_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_send_short_msg_req_struct *req_p;
    kal_int32 result;
    med_aud_player_t* aud_player_p;
    med_aud_player_mma_set_short_msg_t short_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!_aud_mma_check_is_resurce_available_and_set_event(MMA_EVT_SEND_SHORT_MSG))
    {
        return;
    }


    req_p = (media_mma_send_short_msg_req_struct*) ilm_ptr->local_para_ptr;
    
    /* Validate handle */
    aud_player_p = (med_aud_player_t*) req_p->handle;
    
    /* Set short message */
    short_msg.type = req_p->type;
    short_msg.data1 = req_p->data1;
    short_msg.data2 = req_p->data2;

    result = aud_player_p->set(aud_player_p, MMA_PLAYER_SET_SHORT_MSG, (void*)&short_msg);//, sizeof(med_aud_player_mma_set_short_msg_t));

    _aud_mma_set_result_and_event(result,MMA_EVT_SEND_SHORT_MSG);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_open_device_req_hdlr
 * DESCRIPTION
 *  This function is to open a JMidi player, which could play user-specified
 *  data.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_open_device_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_open_device_req_struct *req_p;
    aud_mma_multiple_player_struct *player_p;
    kal_int32 result = MED_RES_FAIL;
    kal_int32 handle = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(!_aud_mma_check_is_resurce_available_and_set_event(MMA_EVT_OPEN_DEVICE))
    {
        mma_set_handle(NULL);
        return;
    }

    /* Stop audio */
    if (AUD_IN_STATE(AUD_MEDIA_PLAY) || AUD_IN_STATE(AUD_MEDIA_PLAY_PAUSED))
    {
        aud_stop_unfinished_process();
    }

    /* Terminate single player */
    player_p = &(g_mma_multiple_player[MMA_SINGLE_PLAYER_IDX]);
    _aud_mma_terminate_player(player_p);

    req_p = (media_mma_open_device_req_struct*) ilm_ptr->local_para_ptr;

    if (MMA_TO_MED(req_p->media_type) == MED_TYPE_SMF)
    {
        /* Open a JMidi player */
        result = _aud_mma_open_mma_player(NULL,
                                          req_p->data,
                                          req_p->size,
                                          MED_TYPE_MIDI,
                                          req_p->repeats,
                                          req_p->fast_pass,
                                          req_p->handler,
                                          &handle);

        if(result == MED_RES_OK)
        {
            player_p = _aud_mma_get_multiple_player_handle(handle);
            player_p->state = AUD_MEDIA_PLAY;
        }

    }

    mma_set_handle(handle);
    _aud_mma_set_result_and_event(result,MMA_EVT_OPEN_DEVICE);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_close_device_req_hdlr
 * DESCRIPTION
 *  This function is to close a JMidi player.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_close_device_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_close_device_req_struct *req_p;
    kal_int32 result = MED_RES_FAIL;
    aud_mma_multiple_player_struct* player_p;
    med_aud_player_t* aud_player_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_close_device_req_struct*) ilm_ptr->local_para_ptr;

    /* Validate handle */
    player_p = _aud_mma_get_multiple_player_handle(req_p->handle);

    aud_player_p = (med_aud_player_t*) req_p->handle;

    /* Close and destory MMA/Media player */
    result = _aud_mma_close_and_destory_player(aud_player_p);

    /* Reset player data */
    player_p->used   = KAL_FALSE;
    player_p->handle = NULL;
    player_p->format = MED_TYPE_NONE;
    player_p->state = AUD_MEDIA_PLAY;

    _aud_mma_set_result_and_event(result,MMA_EVT_CLOSE_DEVICE);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_set_channel_volume_req_hdlr
 * DESCRIPTION
 *  This function is to set channel volume of the media.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_set_channel_volume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_channel_volume_req_struct *req_p;
    kal_int32 result;
    med_aud_player_t* aud_player_p;
    med_aud_player_mma_set_channel_volume_t channel_volume;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_set_channel_volume_req_struct*) ilm_ptr->local_para_ptr;
    
    /* Validate handle */
    aud_player_p = (med_aud_player_t*) req_p->handle;
    
    /* Set channel volume */
    channel_volume.channel = req_p->channel;
    channel_volume.level = req_p->level;

    result = aud_player_p->set(aud_player_p, MMA_PLAYER_SET_CHANNEL_VOLUME, (void*)&channel_volume);//, sizeof(med_aud_player_mma_set_channel_volume_t));

    _aud_mma_set_result_and_event(result,MMA_EVT_SET_CHANNEL_VOLUME);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_set_program_req_hdlr
 * DESCRIPTION
 *  This function is to set program of the media.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_set_program_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_program_req_struct *req_p;
    kal_int32 result;
    med_aud_player_t* aud_player_p;
    med_aud_player_mma_set_program_t program;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_set_program_req_struct*) ilm_ptr->local_para_ptr;
    
    /* Validate handle */
    aud_player_p = (med_aud_player_t*) req_p->handle;
    
    /* Set program */
    program.channel = req_p->channel;
    program.bank = req_p->bank;
    program.program = req_p->program;

    result = aud_player_p->set(aud_player_p, MMA_PLAYER_SET_PROGRAM, (void*)&program);//, sizeof(med_aud_player_mma_set_program_t));

    _aud_mma_set_result_and_event(result,MMA_EVT_SET_PROGRAM);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_set_data_req_hdlr
 * DESCRIPTION
 *  This function is to set data of the media.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_set_data_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_data_req_struct *req_p;
    kal_int32 result;
    med_aud_player_t* aud_player_p;
    med_aud_player_mma_set_data_t data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_set_data_req_struct*) ilm_ptr->local_para_ptr;
    
    /* Validate handle */
    aud_player_p = (med_aud_player_t*) req_p->handle;
    
    /* Set data */
    data.data_p = req_p->data;
    data.size = req_p->size;
    data.repeats = req_p->repeats;

    result = aud_player_p->set(aud_player_p, MMA_PLAYER_SET_DATA, (void*)&data);//, sizeof(med_aud_player_mma_set_data_t));

    _aud_mma_set_result_and_event(result,MMA_EVT_SET_DATA);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_get_channel_volume_req_hdlr
 * DESCRIPTION
 *  This function is to get channel volume.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_get_channel_volume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_channel_volume_req_struct *req_p;
    med_aud_player_t* aud_player_p;
    med_aud_player_mma_get_channel_volume_t channel_volume;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_get_channel_volume_req_struct*) ilm_ptr->local_para_ptr;
    
    /* Validate handle */
    aud_player_p = (med_aud_player_t*) req_p->handle;
    
    /* Get channel volume */
    channel_volume.channel = req_p->channel;
    channel_volume.volume_p = req_p->volume_p;

    aud_player_p->get(aud_player_p, MMA_PLAYER_GET_CHANNEL_VOLUME, (void*)&channel_volume);//, sizeof(med_aud_player_mma_get_channel_volume_t));
    
    MMA_SET_EVENT(MMA_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_get_pitch_req_hdlr
 * DESCRIPTION
 *  This function is to get pitch.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_get_pitch_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_pitch_req_struct *req_p;
    med_aud_player_t* aud_player_p;
    kal_int32 pitch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_get_pitch_req_struct*) ilm_ptr->local_para_ptr;
    
    /* Validate handle */
    aud_player_p = (med_aud_player_t*) req_p->handle;
    
    /* Get pitch */
    aud_player_p->get(aud_player_p, MMA_PLAYER_GET_PITCH, (void*)&pitch);//, sizeof(kal_int32));

    *req_p->pitch_p = pitch;
    
    MMA_SET_EVENT(MMA_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_get_rate_range_req_hdlr
 * DESCRIPTION
 *  This function is to get the range of rate.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_get_rate_range_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_rate_range_req_struct *req_p;
    kal_int16 med_type;
    kal_int32 max_rate = 0;
    kal_int32 min_rate = 0;
    Media_Format med_format = 0 ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_get_rate_range_req_struct*) ilm_ptr->local_para_ptr;

    med_type = MMA_TO_MED(req_p->media_type);

    med_format = (Media_Format)med_type;
    
    switch (med_type)
    {
        case MED_TYPE_SMF:
        case MED_TYPE_MIDI:
            med_format = MEDIA_FORMAT_SMF;
            //Media_GetMaxMinRate(MEDIA_FORMAT_SMF, &max_rate, &min_rate);
            break;
    #ifdef JTONE_SUPPORT
        case MED_TYPE_TONE:
            med_format = MEDIA_FORMAT_JTS;
            //Media_GetMaxMinRate(MEDIA_FORMAT_JTS, &max_rate, &min_rate);
            break;
    #endif /* JTONE_SUPPORT */
    }

    Media_GetMaxMinRate(med_format, &max_rate, &min_rate);

    *req_p->max_rate_p = max_rate;
    *req_p->min_rate_p = min_rate;
    
    MMA_SET_EVENT(MMA_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_get_rate_req_hdlr
 * DESCRIPTION
 *  This function is to get rate.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_get_rate_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_rate_req_struct *req_p;
    med_aud_player_t* aud_player_p;
    kal_int32 rate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_get_rate_req_struct*) ilm_ptr->local_para_ptr;
    
    /* Validate handle */
    aud_player_p = (med_aud_player_t*) req_p->handle;
    
    /* Get rate */
    aud_player_p->get(aud_player_p, MMA_PLAYER_GET_RATE, (void*)&rate);//, sizeof(kal_int32));

    *req_p->rate_p = rate;
    
    MMA_SET_EVENT(MMA_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_get_tempo_req_hdlr
 * DESCRIPTION
 *  This function is to get rate.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_get_tempo_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_tempo_req_struct *req_p;
    med_aud_player_t* aud_player_p;
    kal_int32 tempo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_get_tempo_req_struct*) ilm_ptr->local_para_ptr;
    
    /* Validate handle */
    aud_player_p = (med_aud_player_t*) req_p->handle;
    
    /* Get tempo */
    aud_player_p->get(aud_player_p, MMA_PLAYER_GET_TEMPO, (void*)&tempo);//, sizeof(kal_int32));

    *req_p->tempo_p = tempo;
    
    MMA_SET_EVENT(MMA_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_get_program_req_hdlr
 * DESCRIPTION
 *  This function is to get program.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_get_program_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_program_req_struct *req_p;
    med_aud_player_t* aud_player_p;
    med_aud_player_mma_get_program_t program;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_get_program_req_struct*) ilm_ptr->local_para_ptr;
    
    /* Validate handle */
    aud_player_p = (med_aud_player_t*) req_p->handle;
    
    /* Get program */
    program.channel = req_p->channel;
    program.bank_p = req_p->bank_p;
    program.program_p = req_p->program_p;

    aud_player_p->get(aud_player_p, MMA_PLAYER_GET_PROGRAM, (void*)&program);//, sizeof(med_aud_player_mma_get_program_t));
    
    MMA_SET_EVENT(MMA_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_get_bank_list_req_hdlr
 * DESCRIPTION
 *  This function is to get bank list.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_get_bank_list_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_bank_list_req_struct *req_p;
    med_aud_player_t* aud_player_p;
    med_aud_player_mma_get_bank_list_t bank;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_get_bank_list_req_struct*) ilm_ptr->local_para_ptr;
    
    /* Validate handle */
    aud_player_p = (med_aud_player_t*) req_p->handle;
    
    /* Get bank list */
    bank.custom = req_p->custom;
    bank.buf_p = req_p->buf_p;
    bank.len_p = req_p->len_p;

    aud_player_p->get(aud_player_p, MMA_PLAYER_GET_BANK_LIST, (void*)&bank);//, sizeof(med_aud_player_mma_get_bank_list_t));
    
    MMA_SET_EVENT(MMA_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_get_program_list_req_hdlr
 * DESCRIPTION
 *  This function is to get program list.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_get_program_list_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_program_list_req_struct *req_p;
    med_aud_player_t* aud_player_p;
    med_aud_player_mma_get_program_list_t program;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_get_program_list_req_struct*) ilm_ptr->local_para_ptr;
    
    /* Validate handle */
    aud_player_p = (med_aud_player_t*) req_p->handle;
    
    /* Get program list */
    program.bank = req_p->bank;
    program.buf_p = req_p->buf_p;
    program.len_p = req_p->len_p;

    aud_player_p->get(aud_player_p, MMA_PLAYER_GET_PROGRAM_LIST, (void*)&program);//, sizeof(med_aud_player_mma_get_program_list_t));
    
    MMA_SET_EVENT(MMA_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_get_program_name_req_hdlr
 * DESCRIPTION
 *  This function is to get program name.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_get_program_name_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_program_name_req_struct *req_p;
    med_aud_player_t* aud_player_p;
    med_aud_player_mma_get_program_name_t program;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_get_program_name_req_struct*) ilm_ptr->local_para_ptr;
    
    /* Validate handle */
    aud_player_p = (med_aud_player_t*) req_p->handle;
    
    /* Get program name */
    program.bank = req_p->bank;
    program.program = req_p->program;
    program.name_p = req_p->name_p;

    aud_player_p->get(aud_player_p, MMA_PLAYER_GET_PROGRAM_NAME, (void*)&program);//, sizeof(med_aud_player_mma_get_program_name_t));
    
    MMA_SET_EVENT(MMA_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_get_key_name_req_hdlr
 * DESCRIPTION
 *  This function is to get key name.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_get_key_name_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_key_name_req_struct *req_p;
    med_aud_player_t* aud_player_p;
    med_aud_player_mma_get_key_name_t key;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_get_key_name_req_struct*) ilm_ptr->local_para_ptr;
    
    /* Validate handle */
    aud_player_p = (med_aud_player_t*) req_p->handle;
    
    /* Get program name */
    key.bank = req_p->bank;
    key.program = req_p->program;
    key.key = req_p->key;
    key.name_p = req_p->name_p;

    aud_player_p->get(aud_player_p, MMA_PLAYER_GET_KEY_NAME, (void*)&key);//, sizeof(med_aud_player_mma_get_key_name_t));
    
    MMA_SET_EVENT(MMA_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_get_is_bank_support_req_hdlr
 * DESCRIPTION
 *  This function is to check if bank is supported.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_get_is_bank_support_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_is_bank_support_req_struct *req_p;
    med_aud_player_t* aud_player_p;
    kal_bool is_bank_support = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_get_is_bank_support_req_struct*) ilm_ptr->local_para_ptr;
    
    /* Validate handle */
    aud_player_p = (med_aud_player_t*) req_p->handle;
    
    /* Check if bank is supported */
    aud_player_p->get(aud_player_p, MMA_PLAYER_GET_IS_BANK_SUPPORT, (void*)&is_bank_support);//, sizeof(kal_bool));

    *req_p->is_bank_support_p = is_bank_support;
    
    MMA_SET_EVENT(MMA_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_get_is_sp_midi_req_hdlr
 * DESCRIPTION
 *  This function is to check if it's SP MIDI.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_get_is_sp_midi_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_is_sp_midi_req_struct *req_p;
    med_aud_player_t* aud_player_p;
    kal_bool is_sp_midi = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_get_is_sp_midi_req_struct*) ilm_ptr->local_para_ptr;
    
    /* Validate handle */
    aud_player_p = (med_aud_player_t*) req_p->handle;
    
    /* Check if it's SP MIDI */
    aud_player_p->get(aud_player_p, MMA_PLAYER_GET_IS_SP_MIDI, (void*)&is_sp_midi);//, sizeof(kal_bool));

    *req_p->is_sp_midi_p = is_sp_midi;
    
    MMA_SET_EVENT(MMA_EVT_WAIT);
}

#endif /* __MED_MMA_EXTRA_CTRL__ */

/*****************************************************************************
 * FUNCTION
 *  aud_mma_pdl_write_data_ind_req_hdlr
 * DESCRIPTION
 *  This function is to notify the MMA when the progressive download is finished.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_pdl_write_data_ind_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_pdl_write_data_ind_req_struct *req_p;
    kal_int8 player_idx;
    aud_mma_multiple_player_struct *player_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_pdl_write_data_ind_req_struct*) ilm_ptr->local_para_ptr;

    /* Validate handle */
    player_idx = _aud_mma_get_player_idx_by_handle(req_p->handle);
    MED_ASSERT(player_idx == MMA_SINGLE_PLAYER_IDX && g_mma_single_player.is_progressive_dl);
    
    player_p = &(g_mma_multiple_player[MMA_SINGLE_PLAYER_IDX]);


    _AUD_MODULE_MMA2_TRACE(req_p->is_finish, player_p->state);

    /* Update download-finished flag */
    if (req_p->is_finish)
    {
        g_mma_single_player.is_dl_finish = KAL_TRUE;
    }

    _aud_mma_set_result_and_event(MED_RES_OK,MMA_EVT_WRITE_DATA_IND);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_pdl_get_buf_percent_req_hdlr
 * DESCRIPTION
 *  This function is get the percentage of the progressive download.
 * PARAMETERS
 *  ilm_ptr     [IN]     ILM.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_pdl_get_buf_percent_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_pdl_get_buf_percent_req_struct *req_p;
    aud_mma_multiple_player_struct *player_p;
    med_aud_player_t* aud_player_p;
    kal_int8 player_idx;
    kal_uint32 current_time;
    kal_uint32 current_file_offset = 0;
    kal_uint32 download_file_size, required_cache_size;
    kal_bool is_reach_valid_region = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_pdl_get_buf_percent_req_struct*) ilm_ptr->local_para_ptr;

    /* Validate handle */
    player_idx = _aud_mma_get_player_idx_by_handle(req_p->handle);

    MED_ASSERT(player_idx == MMA_SINGLE_PLAYER_IDX && g_mma_single_player.is_progressive_dl);

    player_p = &(g_mma_multiple_player[MMA_SINGLE_PLAYER_IDX]);
    aud_player_p = (med_aud_player_t*) req_p->handle;

    _AUD_MODULE_MMA_TRACE(player_p->state, g_mma_single_player.is_dl_finish, g_mma_single_player.bit_rate);
    
    /* Check state */
    if (player_p->state == AUD_MEDIA_PLAY)
    {
        _aud_mma_set_result_and_event(MED_RES_FAIL,MMA_EVT_GET_PDL_PERCENT);
        return;
    }

    /* Check if download is finished */
    if (g_mma_single_player.is_dl_finish)
    {
        *req_p->percent = 100;
        _aud_mma_set_result_and_event(MED_RES_OK,MMA_EVT_GET_PDL_PERCENT);
        return;
    }

    /* Check current file offset */
    if (player_p->state == AUD_MEDIA_UNDERFLOW)
    {
        current_file_offset = g_mma_single_player.underflow_file_size;
    }
    else if (player_p->state == AUD_MEDIA_IDLE ||
             player_p->state == AUD_MEDIA_PLAY_PAUSED)
    {
        aud_player_p->get(aud_player_p, AUD_PLAYER_GET_CURRENT_TIME, &current_time);//, sizeof(kal_uint32));
        
        current_file_offset = ((g_mma_single_player.bit_rate * current_time) / 8) / 1000;
    }
    else
    {
        ASSERT(0);
    }

    /* Get current file size */
    if (FSAL_GetFileSize(&g_mma_single_player.fsal_handle, &download_file_size) != FSAL_OK)
    {
        _aud_mma_set_result_and_event(MED_RES_FAIL,MMA_EVT_GET_PDL_PERCENT);
        return;
    }

    /* Count required buffer size */
    required_cache_size = g_mma_single_player.bit_rate * req_p->cache_sec / 8;
    
    /* To prevent driver from reading the EOF during progressive download, 
       the required cache size has to be greater or equal to the size of
       the ring buffer. Otherwise, we may encounter a short pause during
       progressive download - which will lead to bad user experience.
    */
    if (required_cache_size < MED_RING_BUFFER_SIZE)
    {
        required_cache_size = MED_RING_BUFFER_SIZE;
    }

    _AUD_MODULE_MMA_TRACE(download_file_size, current_file_offset, required_cache_size);

    /* Count percentage */
    if(download_file_size >= (current_file_offset + required_cache_size))
    {
        /* If the header size is larger than current downloaded size, the 
           playback will fail due to bad file format. To prevent this, we
           have to guarantee that all the header has been downloaded before
           entering ready-to-play state.
        */
        aud_player_p->get(aud_player_p, (med_aud_player_get_t) MEDIA_PLAYER_GET_IS_REACH_VALID_REGION, (void*)&is_reach_valid_region);//, sizeof(kal_bool));
        
        if (! is_reach_valid_region)
        {
            /* If not reach valid region, we have to let MMI wait. */
            *req_p->percent = 99;
        }
        else
        {
        #ifdef __MTK_TARGET__
        #if defined(AAC_DECODE)
            if ((player_p->format == MED_TYPE_AAC) && (AAC_IsADIF(&g_mma_single_player.fsal_handle)))
            {
                /* Since we don't support seek function for AAC-ADIF format,
                   we have to let MMI finish the download before starting
                   the playback - This is to prevent replay from the beginning
                   when the playback is faster than the download.
                */
                *req_p->percent = 90;
            }
            else
        #endif /*AAC_DECODE*/
        #endif /* __MTK_TARGET__ */
            {
                *req_p->percent = 100;
            }
        }
    }
    else if(download_file_size > current_file_offset)
    {
        *req_p->percent = (download_file_size - current_file_offset) * 100 / required_cache_size;
    }
    else
    {
        *req_p->percent = 0;
    }

    _aud_mma_set_result_and_event(MED_RES_OK,MMA_EVT_GET_PDL_PERCENT);
}


#endif /* __MED_MMA_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

