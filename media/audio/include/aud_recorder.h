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
*  aud_recorder.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio Recorder definitions
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

 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*==============================================================================
*******************************************************************************/
#ifndef MED_NOT_PRESENT

#ifndef __MED_AUD_RECORDER__
#define __MED_AUD_RECORDER__

/*-----------------------------------------------------------------------------
                    include files
-----------------------------------------------------------------------------*/
#include "med_utility.h"
#include "aud_main.h"
#include "kal_general_types.h"

/*-----------------------------------------------------------------------------
                    macros, defines, typedefs, enums
 ----------------------------------------------------------------------------*/
#define OFFSET_OF(s,m) ((int)&(((s*)0)->m))
#define PTHIS(p, structure, member) ((structure*)(((int)p) - OFFSET_OF(structure, member)))

/* Memory utility */
#define AUD_RECORDER_FREE_CTRL_BUF(p)                                \
    do {                                                             \
        if (p) { free_ctrl_buffer(p); }                              \
    } while (0)
    
#define AUD_RECORDER_FREE_AUD_MEM(p)                                 \
    do {                                                             \
        if (p) { med_free_aud_mem((void**)&p); };                    \
    } while (0)

#define AUD_RECORDER_FREE_EXT_MEM(p)                                 \
    do {                                                             \
        if (p) { med_free_ext_mem((void**)&p); };                    \
    } while (0)

#define AUD_RECORDER_FREE_INT_MEM(p)                                 \
    do {                                                             \
        if (p) { med_free_int_mem((void**)&p); };                    \
    } while (0)
    
#define AUD_RECORDER_FREE_RING_BUF(p)                                \
    do {                                                             \
        if (p) { aud_util_free_ring_buffer_ext((kal_uint16**)&p); }; \
    } while (0)

/* Recorder index */
enum
{
    AUD_RECORDER_IDX_MEDIA = 0,
    AUD_RECORDER_IDX_MODIS
};

/* Termination reason */
typedef enum
{
    AUD_RECORDER_REASON_OK = 0,                   /* OK */
    AUD_RECORDER_REASON_REACH_SIZE_LIMIT,         /* Reach size limit */
    AUD_RECORDER_REASON_REACH_TIME_LIMIT,         /* Reach time limit */
    AUD_RECORDER_REASON_DISK_FULL,                /* Disk full */
    AUD_RECORDER_REASON_NO_DISK,                  /* No disk */
    AUD_RECORDER_REASON_ERROR                     /* Something wrong */
} med_aud_recorder_reason_t;

/* Set commands of Audio Recorder */              
typedef enum                                    
{                                               
    AUD_RECORDER_SET_SIZE_LIMIT = 0,              /* Set size limit (kal_uint32) */
    AUD_RECORDER_SET_TIME_LIMIT,                  /* Set time limit (kal_uint32) */
    AUD_RECORDER_SET_SPEECH_PARAM,                /* Set speech parameters (med_aud_recorder_speech_param_t*) */
                                                
    AUD_RECORDER_SET_LAST_ENTRY                   /* Recorder-specific commands could be put beyond here */
} med_aud_recorder_set_t;                         
                                                
/* Get commands of Audio Recorder */              
typedef enum                                    
{                                               
    AUD_RECORDER_GET_RECORD_TIME = 0,             /* Get recorded time (kal_uint32*) */
    AUD_RECORDER_GET_IS_FM_RECORD,                /* Get is fm record (kal_bool)*/
                                                
    AUD_RECORDER_GET_LAST_ENTRY                   /* Recorder-specific commands could be put beyond here */
} med_aud_recorder_get_t;

/*-----------------------------------------------------------------------------
                    structure definitions
 ----------------------------------------------------------------------------*/
typedef struct med_aud_recorder_t med_aud_recorder_t;

/* The function will be called when the recording is terminated for one reason 
 * or another. The client may have some handling in the callback such as notify
 * MMI the record is terminated for some reason and simply return FALSE.
 * 
 * In a more compilicated scenario, the client may wish to open another file 
 * to record or delete a file which has been recorded. To fulfill this requirement,
 * the callback function provides two alternatives:
 *
 * 1. If returning FALSE, the recording will be terminated. If returning TRUE,
 *    we continue the recording. Note that this is applicable only when the recording
 *    is termianted because of reaching size or time limit. For other termination 
 *    reasons, the recording will be terminated unconditionally even if returning TRUE.
 *    
 * 2. The pointer of current file handle which is being recorded to is passed as a
 *    parameter in the callback function. The client may open another file handle to
 *    be recorded to.
 * 
 * This mechanism could be useful when the client wants to write recorded data to 
 * another file seamlessly (such as the requirements from VM log).
 */
typedef kal_bool (*med_aud_recorder_cb_fct) (med_aud_recorder_t* recorder_p,   /* Recorder handle */
                                             med_aud_recorder_reason_t reason, /* Terminated reason */
                                             kal_int32* file_handle_p,         /* File handle. Client may overwrite the handle if required */
                                             void* param);                     /* Callback parameter specified by the client */

typedef struct
{
    kal_bool                is_speech_on;       /* Indicate if speech is being on */
    kal_uint8               rat_mode;           /* Speech rat mode */
} med_aud_recorder_speech_param_t;

/* Configuration of Audio Recorder */
typedef struct
{
    kal_wchar*              file_name;          /* The file to be recorded to */
    kal_uint8               format;             /* Record format */
    kal_uint8               quality;            /* Record quality */
    kal_bool                is_low_priority;    /* Indicate if it's a low-priority record */
    kal_bool                is_fm_record;       /* Indicate if it's a FM recording */
    med_aud_recorder_cb_fct cb_fct;             /* Callback function to handle recorder events */
    void*                   cb_param;           /* User data that will remain unaltered in the callback */
} med_aud_recorder_cfg_t;

/* Audio Recorder interfaces */
struct med_aud_recorder_t
{
    kal_int32 (*open)       (med_aud_recorder_t* recorder_p, med_aud_recorder_cfg_t* cfg_p); /* Open a recorder */
    kal_int32 (*close)      (med_aud_recorder_t* recorder_p); /* Close a recorder */
    kal_int32 (*record)     (med_aud_recorder_t* recorder_p); /* Start record */
    kal_int32 (*stop)       (med_aud_recorder_t* recorder_p); /* Stop record */
    kal_int32 (*pause)      (med_aud_recorder_t* recorder_p); /* Pause record */
    kal_int32 (*resume)     (med_aud_recorder_t* recorder_p); /* Resume record */
    kal_int32 (*set)        (med_aud_recorder_t* recorder_p, med_aud_recorder_set_t set_type, void* data_p, kal_uint32 data_len); /* General get function */
    kal_int32 (*get)        (med_aud_recorder_t* recorder_p, med_aud_recorder_get_t get_type, void* data_p, kal_uint32 data_len); /* General set function */
    kal_int32 (*destroy)    (med_aud_recorder_t* recorder_p); /* Destroy recorder interfaces */
};


/*-----------------------------------------------------------------------------
                    Exported API's
 ----------------------------------------------------------------------------*/
extern med_aud_recorder_t* aud_recorder_media_construct(void);
extern med_aud_recorder_t* aud_recorder_modis_construct(void);

#endif /* __MED_AUD_RECORDER__ */
#endif /* MED_NOT_PRESENT */

