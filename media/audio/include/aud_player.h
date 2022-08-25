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
*  aud_player.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio Player definitions
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#ifndef MED_NOT_PRESENT

#ifndef __MED_AUD_PLAYER__
#define __MED_AUD_PLAYER__

/*-----------------------------------------------------------------------------
                    include files
-----------------------------------------------------------------------------*/
#include "kal_public_api.h"
#include "med_utility.h"
#include "aud_main.h"
#include "l1audio.h"
#include "kal_general_types.h"

/*-----------------------------------------------------------------------------
                    macros, defines, typedefs, enums
 ----------------------------------------------------------------------------*/
#define OFFSET_OF(s,m) ((int)&(((s*)0)->m))
#define PTHIS(p, structure, member) ((structure*)(((int)p) - OFFSET_OF(structure, member)))

/* Memory utility */
#define AUD_PLAYER_FREE_CTRL_BUF(p)                                  \
    do {                                                             \
        if (p) { free_ctrl_buffer(p); }                              \
    } while (0)
    
#define AUD_PLAYER_FREE_AUD_MEM(p)                                   \
    do {                                                             \
        if (p) { med_free_aud_mem((void**)&p); };                    \
    } while (0)

#define AUD_PLAYER_FREE_RING_BUF(p)                                  \
    do {                                                             \
        if (p) { aud_util_free_ring_buffer_ext((kal_uint16**)&p); }; \
    } while (0)

/* Player index */
enum
{
    AUD_PLAYER_IDX_MEDIA = 0,
    AUD_PLAYER_IDX_MP4,
    AUD_PLAYER_IDX_MMA,
    AUD_PLAYER_IDX_RM,
    AUD_PLAYER_IDX_MODIS
};

/* Private commands offset of each player */
enum
{
    AUD_PLAYER_CMD_OFFSET_MEDIA = 20,
    AUD_PLAYER_CMD_OFFSET_MP4   = 40,
    AUD_PLAYER_CMD_OFFSET_MMA   = 60,
    AUD_PLAYER_CMD_OFFSET_RM    = 80,
    AUD_PLAYER_CMD_OFFSET_MODIS = 100
};

/* Set commands of Audio Player */              
typedef enum                                    
{                                               
    AUD_PLAYER_SET_CACHE_TABLE = 0,             /* Set cache table. If set, driver will update seek hint when playing the media (void*) */
    AUD_PLAYER_SET_BUFFER,                      /* Set working buffer. Used only in building cache (kal_uint8*) */
    AUD_PLAYER_SET_START_TIME,                  /* Set start time (kal_uint32) */
    AUD_PLAYER_SET_STOP_TIME,                   /* Set stop time (kal_uint32) */
    AUD_PLAYER_SET_LEVEL,                       /* Set digital gain level (kal_uint8) */
    AUD_PLAYER_SET_STORE_FLAG,                  /* Set store flag (kal_bool) */
    AUD_PLAYER_SET_FILE_OFFSET,                 /* Set file offsef (kal_uint32) */
                                                
    AUD_PLAYER_SET_LAST_ENTRY                   /* Player-specific commands could be put beyond here */
} med_aud_player_set_t;                         
                                                
/* Get commands of Audio Player */              
typedef enum                                    
{                                               
    AUD_PLAYER_GET_START_TIME = 0,              /* Get start time (kal_uint32*) */
    AUD_PLAYER_GET_STOP_TIME,                   /* Get stop time (kal_uint32*) */
    AUD_PLAYER_GET_CURRENT_TIME,                /* Get current time (kal_uint32*) */
    AUD_PLAYER_GET_DURATION,                    /* Get duration (kal_uint32*) */
    AUD_PLAYER_GET_LEVEL,                       /* Get digtial gain level (kal_uint8*) */
    AUD_PLAYER_GET_LAST_TIME,                   /* Get last time. May be used for restore (kal_uint32*) */
    AUD_PLAYER_GET_LAST_OFFSET,                 /* Get last file offset. May be used for restore (kal_uint32*) */
    AUD_PLAYER_GET_CONTENT_DESC,                /* Get context description (audInfoStruct*) */
    AUD_PLAYER_GET_MHDL_HANDLE,                 /* Get MHdl handle (MHdl**) */
                                                
    AUD_PLAYER_GET_LAST_ENTRY                   /* Player-specific commands could be put beyond here */
} med_aud_player_get_t;

/*-----------------------------------------------------------------------------
                    structure definitions
 ----------------------------------------------------------------------------*/
typedef struct med_aud_player_t med_aud_player_t;
/* Callback function for handling playback events */
typedef void (*med_aud_player_cb_fct) (med_aud_player_t* player_p, Media_Event event, void* param);

/* Configuration of Audio Player */
typedef struct
{
    kal_uint16              app_id;             /* App id. Currently used by RM player only */
    kal_wchar*              file_name;          /* File name */
    kal_uint8*              data_p;             /* Media Data */
    kal_uint32              data_len;           /* Media Data length. Valid only if pui1_data is not NULL */
    kal_uint8               format;             /* Media format */  
    kal_uint8               repeat;             /* Specify repeat times. Currently, only MMA player supported repeat
                                                 * setting. Other players could just ignore this parameter. The client 
                                                 * will be responsbile for replaying the content if required. */                                      
    kal_uint8               audio_path;         /* Specify audio path for audio output. Currently, only RM player uses this parameter. 
                                                 * Other players could just ignore this parameter. The client will be
                                                 * responsbile for setting audio path before playback. */
    kal_bool                fast_pass;          /* Specify if the fast pass mode should be applied. In fast pass mode, the APM will be
                                                 * disabled and hence could speed up the response time of a playback. */
    med_aud_player_cb_fct   cb_fct;             /* Callback function to handle player events */
    void*                   cb_param;           /* User data that will remain unaltered in the callback */
} med_aud_player_cfg_t;

/* Audio Player interfaces */
struct med_aud_player_t
{
    kal_int32 (*open)       (med_aud_player_t* player_p, med_aud_player_cfg_t* cfg_p); /* Open a player */
    kal_int32 (*close)      (med_aud_player_t* player_p); /* Close a player */
    kal_int32 (*play)       (med_aud_player_t* player_p); /* Play from start time to end time */
    kal_int32 (*stop)       (med_aud_player_t* player_p); /* Stop the play */
    kal_int32 (*pause)      (med_aud_player_t* player_p); /* Pause the play */
    kal_int32 (*resume)     (med_aud_player_t* player_p); /* Resume the play */
    kal_int32 (*set)        (med_aud_player_t* player_p, med_aud_player_set_t set_type, void* data_p); /* General get function */
    kal_int32 (*get)        (med_aud_player_t* player_p, med_aud_player_get_t get_type, void* data_p); /* General set function */
    kal_int32 (*destroy)    (med_aud_player_t* player_p); /* Destroy player interfaces */
};

typedef struct 
{
    void* cache_p;
    kal_int32 cache_size;
} med_aud_player_set_cache_t;

typedef struct
{
    void* buffer_p;
    kal_int32 buffer_size;
} med_aud_player_set_buffer_t;


/*-----------------------------------------------------------------------------
                    Exported API's
 ----------------------------------------------------------------------------*/
extern med_aud_player_t* aud_player_media_construct(void);
extern med_aud_player_t* aud_player_mma_construct(void);
extern med_aud_player_t* aud_player_mpl_construct(void);
extern med_aud_player_t* aud_player_modis_construct(void);

#endif /* __MED_AUD_PLAYER__ */
#endif /* MED_NOT_PRESENT */

