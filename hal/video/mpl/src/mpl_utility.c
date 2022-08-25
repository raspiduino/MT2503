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
 * mpl_utility.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes common used functions of mpl.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#if defined(__VIDEO_ARCHI_V2__)

/*==== INCLUDES =========*/

#include "fs_type.h"
#include "fs_func.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "stack_config.h"

#include "mpl_utility.h"
#include "media_common.h"
#include "mpl_common.h" // the common defition for MPL
#include "hal_custom_video.h"
#include "med_struct.h"
#include "stack_ltlcom.h"
#include "l1audio.h"

#define MPL_POOL_LOCK  (1)

/* RM resource */
#if defined(__RM_DEC_SUPPORT__)
#define RM_MP_LOCK_PER_INSTANCE_NUM     (6)
#define RM_META_LOCK_NUM                (1)
#define RM_MP_EVENT_PER_INSTANCE_NUM    (1)
#define RM_MP_MAX_MULTIPLE_INSTANCE_NUM (2)
#define RM_MP_LOCK_COUNT  (RM_META_LOCK_NUM + RM_MP_LOCK_PER_INSTANCE_NUM * RM_MP_MAX_MULTIPLE_INSTANCE_NUM)
#define RM_MP_EVENT_COUNT (RM_MP_EVENT_PER_INSTANCE_NUM * RM_MP_MAX_MULTIPLE_INSTANCE_NUM)
#else
#define RM_MP_LOCK_COUNT  (0)    // wont compile error by pool lock
#define RM_MP_EVENT_COUNT (0)
#endif

/* MP4 resource */
#if defined(MP4_DECODE)
#define MP4_MP_LOCK_COUNT  (16) // 12 for 2 instances
#define MP4_MP_EVENT_COUNT (2)
#else
#define MP4_MP_LOCK_COUNT  (0)
#define MP4_MP_EVENT_COUNT (0)
#endif

/* AVI resource */
#if defined(MJPG_DECODE)
#define AVI_MP_LOCK_COUNT  (16) // 16 for 2 instances
#define AVI_MP_EVENT_COUNT (2)
#else
#define AVI_MP_LOCK_COUNT  (0)
#define AVI_MP_EVENT_COUNT (0)
#endif

/* Media Provider total resource */
#define MPL_MP_LOCK_COUNT (RM_MP_LOCK_COUNT + MP4_MP_LOCK_COUNT + AVI_MP_LOCK_COUNT)
#define MPL_MP_EVENT_COUNT (RM_MP_EVENT_COUNT + MP4_MP_EVENT_COUNT + AVI_MP_EVENT_COUNT)

/* MED total resource */
#define MPL_LOCK_COUNT (MPL_POOL_LOCK + MPL_MP_LOCK_COUNT)
#define MPL_EVENT_COUNT (MPL_MP_EVENT_COUNT)

/* convert to total resource */
#define MPL_RES_LOCK_COUNT (MPL_LOCK_COUNT)
#if MPL_EVENT_COUNT == 0
    #define MPL_RES_EVENT_COUNT (1)    // for compile
#else
    #define MPL_RES_EVENT_COUNT (MPL_EVENT_COUNT)
#endif

typedef struct
{
    event_scheduler *event_scheduler_ptr;

    kal_mutexid pool_lock;
    kal_mutexid locks[MPL_RES_LOCK_COUNT];
    kal_eventgrpid events[MPL_RES_EVENT_COUNT];

} mpl_utility_context_t;

typedef struct
{
    eventid event_id;
    kal_timer_func_ptr callback_func;
    void *arg;
}
mpl_timer_table_struct;

mpl_timer_table_struct mpl_timer_table[MPL_TIMER_MAX_NUM];



/*****************************************************************************
 * Declaration
 *****************************************************************************/
static mpl_utility_context_t g_mpl_utility_context;

/*****************************************************************************
 * Function
 *****************************************************************************/
static kal_mutexid mpl_get_lock_unprotected(void)
{
    kal_uint32 i;
    kal_mutexid lock = NULL;

    for (i = 0; i < ARRAY_SIZE(g_mpl_utility_context.locks); i++)
    {
        if (g_mpl_utility_context.locks[i] != NULL)
        {
            lock = g_mpl_utility_context.locks[i];
            g_mpl_utility_context.locks[i] = NULL;
            break;
        }
    }
    ASSERT(i != ARRAY_SIZE(g_mpl_utility_context.locks));

    return lock;
}

kal_mutexid mpl_get_lock(void)
{
    kal_mutexid lock = NULL;

    kal_take_mutex(g_mpl_utility_context.pool_lock);

    lock = mpl_get_lock_unprotected();

    kal_give_mutex(g_mpl_utility_context.pool_lock);

    return lock;
}

void mpl_return_lock(kal_mutexid lock)
{
    kal_uint32 i;

    kal_take_mutex(g_mpl_utility_context.pool_lock);

    for (i = 0; i < ARRAY_SIZE(g_mpl_utility_context.locks); i++)
    {
        if (g_mpl_utility_context.locks[i] == NULL)
        {
            g_mpl_utility_context.locks[i] = lock;
            break;
        }
    }
    ASSERT(i != ARRAY_SIZE(g_mpl_utility_context.locks));

    kal_give_mutex(g_mpl_utility_context.pool_lock);
}

kal_eventgrpid mpl_get_event(void)
{
    kal_uint32 i;
    kal_eventgrpid event = NULL;

    kal_take_mutex(g_mpl_utility_context.pool_lock);

    for (i = 0; i < ARRAY_SIZE(g_mpl_utility_context.events); i++)
    {
        if (g_mpl_utility_context.events[i] != NULL)
        {
            event = g_mpl_utility_context.events[i];
            g_mpl_utility_context.events[i] = NULL;
            break;
        }
    }
    ASSERT(i != ARRAY_SIZE(g_mpl_utility_context.events));

    kal_give_mutex(g_mpl_utility_context.pool_lock);

    return event;
}

void mpl_return_event(kal_eventgrpid event)
{
    kal_uint32 i;

    kal_take_mutex(g_mpl_utility_context.pool_lock);

    for (i = 0; i < ARRAY_SIZE(g_mpl_utility_context.events); i++)
    {
        if (g_mpl_utility_context.events[i] == NULL)
        {
            g_mpl_utility_context.events[i] = event;
            break;
        }
    }
    ASSERT(i != ARRAY_SIZE(g_mpl_utility_context.events));

    kal_give_mutex(g_mpl_utility_context.pool_lock);
}

/*****************************************************************************
 * FUNCTION
 *  mpl_send_async_context_ilm
 * DESCRIPTION
 *
 * PARAMETERS
 *  ilm_ptr     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mpl_send_async_context_ilm(kal_uint16 dst_mod, void (*pfn)(void* param), void* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mpl_async_callback_req_struct* prLocal;
    module_type src_mod_id;
    ilm_struct* ilm;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    prLocal = (media_mpl_async_callback_req_struct*)construct_local_para(sizeof(media_mpl_async_callback_req_struct), TD_CTRL);
    prLocal->callback = pfn;
    prLocal->param = param;

    src_mod_id = stack_get_active_module_id();

    ilm = allocate_ilm(src_mod_id);
    ilm->src_mod_id = src_mod_id;
    ilm->sap_id = MED_SAP;
    ilm->dest_mod_id = (module_type)dst_mod;

    ilm->msg_id = (msg_type) MSG_ID_MEDIA_MPL_ASYNC_CALLBACK_REQ;
    ilm->local_para_ptr = (local_para_struct*) prLocal;
    ilm->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm);

}

/*****************************************************************************
 * FUNCTION
 *  mpl_timer_expiry_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  ilm_ptr     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mpl_timer_expiry_hdlr(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Execute event's timeout handler */
    evshed_timer_handler(g_mpl_utility_context.event_scheduler_ptr);

}

/*****************************************************************************
 * FUNCTION
 *  mpl_timer_expiry_hdlr_async
 * DESCRIPTION
 *
 * PARAMETERS
 *  ilm_ptr     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mpl_timer_expiry_hdlr_async(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stack_timer_struct *stack_timer_ptr;
    media_mpl_async_callback_req_struct* prLocal;
    module_type src_mod_id;
    ilm_struct* ilm;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_timer_ptr = (stack_timer_struct*) ilm_ptr->local_para_ptr;

    if (stack_timer_ptr->timer_indx == MPL_BASE_TIMER_ID)
    {
        mpl_send_async_context_ilm(MOD_MED, mpl_timer_expiry_hdlr, (void*)NULL);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mpl_timer_expiry_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  arg     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mpl_timer_expiry_callback(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *timer_id = (kal_uint8*) arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((kal_uint32) timer_id < (kal_uint32) MPL_TIMER_MAX_NUM)
    {
        mpl_timer_table[(kal_uint32) (timer_id)].event_id = NULL;
        (mpl_timer_table[(kal_uint32) (timer_id)].callback_func) (mpl_timer_table[(kal_uint32) (timer_id)].arg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mpl_start_timer
 * DESCRIPTION
 *
 * PARAMETERS
 *  timer_id            [IN]
 *  period              [IN]
 *  timer_expiry        [IN]
 *  arg                 [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mpl_start_timer(kal_uint8 timer_id, kal_uint32 period, kal_timer_func_ptr timer_expiry, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 temp = (period * 7) >> 5;    /* ~= x 1/4.615 */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (temp == 0)
    {
        temp = 1;
    }
    mpl_timer_table[timer_id].callback_func = timer_expiry;
    mpl_timer_table[timer_id].arg = arg;
    mpl_timer_table[timer_id].event_id = evshed_set_event(
                                            g_mpl_utility_context.event_scheduler_ptr,
                                            (kal_timer_func_ptr) mpl_timer_expiry_callback,
                                            (void*)timer_id,
                                            temp /** KAL_TICKS_10_MSEC */ );
}


/*****************************************************************************
 * FUNCTION
 *  mpl_stop_timer
 * DESCRIPTION
 *
 * PARAMETERS
 *  timer_id        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mpl_stop_timer(kal_uint8 timer_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mpl_timer_table[timer_id].event_id != NULL)
    {
        evshed_cancel_event(g_mpl_utility_context.event_scheduler_ptr, &(mpl_timer_table[timer_id].event_id));
        mpl_timer_table[timer_id].event_id = NULL;
    }

}

/*****************************************************************************
 * FUNCTION
 *  mpl_utility_init
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_bool mpl_utility_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    kal_char lock_name[16];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mpl_utility_context.event_scheduler_ptr = evshed_create("MPL event timer", MOD_VFILE, 0, 0);

    for (i = 0; i < MPL_TIMER_MAX_NUM; i++)
    {
        mpl_timer_table[i].event_id = NULL;
    }

    /* init lock pool */
    for (i = 0; i < ARRAY_SIZE(g_mpl_utility_context.locks); i++)
    {
        sprintf(lock_name, "MPLLK%d", i);
        g_mpl_utility_context.locks[i] = kal_create_mutex(lock_name);
    }

    /* init event pool */
    for (i = 0; i < ARRAY_SIZE(g_mpl_utility_context.events); i++)
    {
        sprintf(lock_name, "MPLEV%d", i);
        g_mpl_utility_context.events[i] = kal_create_event_group(lock_name);
    }

    /* shared lock for lock pool */
    g_mpl_utility_context.pool_lock = mpl_get_lock_unprotected();

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mpl_get_vid_custom_format_index
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint32 mpl_get_vid_custom_format_index(kal_uint32 codec_type)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (codec_type)
    {
        case MEDIA_CODEC_VID_MPEG4:
        case MEDIA_CODEC_VID_H263:
        case MEDIA_CODEC_VID_H264:
            return MPLY_CUSTOM_FORMAT_MP4;
            //break;
        case MEDIA_CODEC_VID_RV_8:
        case MEDIA_CODEC_VID_RV_9:
        case MEDIA_CODEC_VID_RV_10:
            return MPLY_CUSTOM_FORMAT_RM;
            //break;
        default:
            break;
    }
    return MPLY_CUSTOM_FORMAT_MP4;
}

/*****************************************************************************
 * FUNCTION
 *  mpl_get_media_format_from_codec_type
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint16 mpl_get_media_format_from_codec_type(kal_uint16 codec_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Format format = MEDIA_FORMAT_UNKNOWN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (codec_type)
    {
        case MEDIA_CODEC_AUD_RA_8_LBR:
            format = MEDIA_FORMAT_COOK;
            break;
        case MEDIA_CODEC_AUD_AAC:
            format = MEDIA_FORMAT_AAC;
            break;
        case MEDIA_CODEC_AUD_HE_AAC:
            format = MEDIA_FORMAT_AAC_PLUS;
            break;
        case MEDIA_CODEC_AUD_AMR:
            format = MEDIA_FORMAT_AMR;
            break;
        case MEDIA_CODEC_AUD_AMR_WB:
            format = MEDIA_FORMAT_AMR_WB;
            break;
        case MEDIA_CODEC_AUD_BSAC:
            format = MEDIA_FORMAT_BSAC;
            break;
        case MEDIA_CODEC_AUD_PCM:
            format = MEDIA_FORMAT_PCM_8K;
            break;
        case MEDIA_CODEC_AUD_MPEGLAYER3:
            format = MEDIA_FORMAT_DAF;
            break;
        case MEDIA_CODEC_AUD_MPEG:
            format = MEDIA_FORMAT_MUSICAM;
            break;
        case MEDIA_CODEC_AUD_DRA:
            format = MEDIA_FORMAT_DRA;
            break;
        case MEDIA_CODEC_AUD_VORBIS:
            format = MEDIA_FORMAT_VORBIS;
            break;
        /* decoder does not support. Provider should fill it out */
        case MEDIA_CODEC_AUD_RA_VOICE:
        case MEDIA_CODEC_AUD_RA_8_HBR:
        default:
            ASSERT(0);
    }
    return format;
}

#endif /* defined (__VIDEO_ARCHI_V2__) */
