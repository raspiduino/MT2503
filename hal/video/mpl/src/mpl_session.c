/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   mpl_session.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/
#include "drv_features_video.h"
#if defined(__VE_VIDEO_ARCHI_V2__)
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "kal_trace.h"
#include "stack_config.h"
#include "med_struct.h"
#include "mpl_common.h" // mpl common type definition
#include "mpl_player.h" // mpl player interface definition
#include "mpl_session.h"
#include "mpl_session_mem.h"
#include "mpl_utility.h"


/* video */
#include "video_types_v2.h"
#include "source_provider_if.h"
#include "video_decoder_component_v2.h"
#include "video_decscheduler_component_if_v2.h"
#include "va2_comp_video_renderer.h"
#include "video_buffer_management_v2.h"
#include "vcodec_v2_trc.h"
#include "video_memory_usage_v2.h"
#include "hal_custom_video.h"
#include "media_provider.h"
#include "video_fluency_if.h"

#include "visual_comm.h"

/* audio */
#include "l1audio.h"
#include "aud_main.h"
/* LCD */
#include "lcd_if.h"

#if defined(__VE_SUBTITLE_SUPPORT__)
#include "video_subtitle_codec_if.h"
#include "SubtitleFont_if.h"
#endif

#ifdef __VE_DCM_WITH_COMPRESSION__
#include "dcmgr.h"
kal_uint32 u4MPLCount;
#endif

#ifdef __VE_DCM_WITH_COMPRESSION__
#pragma arm section code = "DYNAMIC_CODE_VEDEC_ROCODE", rodata = "DYNAMIC_CODE_VEDEC_RODATA"
#endif

#define MPL_DEBUG_INFO
#define MPL_DEBUG_INFO_TRACE
#define __VE_MPL_SLIM__
#if defined(MPL_DEBUG_INFO_TRACE)
    #define MPLVP_TRACE(x, ...)             kal_trace(x, __VA_ARGS__)
#else
    #define MPLVP_TRACE(x, ...)             { /* empty */ }
#endif  // defined(MPL_DEBUG_INFO_TRACE)

#define MPL_IS_STRM_INVALID(idx) (idx == MPL_SESSION_INVALID_INDEX)
#define MPL_IS_STRM_VALID(idx) (!MPL_IS_STRM_INVALID(idx))

#define MPL_ASSERT(exp) if(!(exp)) {ASSERT(0);}
#define mpl_session_alloc_ext_mem(client, size, type) (((mpl_player_client_t*)client)->mem_alloc_func(client, size, type, 0, 0))
#define mpl_session_free_ext_mem(client, p, type) (((mpl_player_client_t*)client)->mem_free_func(client, p, type, 0, 0))

extern void AudioPP_DisableBesSoundinVideo(void);
extern void AudioPP_EnableBesSoundinVideo(void);
/*****************************************************************************
 * Private Function
 *****************************************************************************/
static mpl_session_struct *mpl_session_cntx_p[MPL_SESSION_MAX_CONTEXT] = {0,0,0};
static mpl_session_struct *_prVideoSession;
static MED_AUD_CALLBACK_FUNC_T mpl_session_med_aud_func;

/*****************************************************************************
* DESCRIPTION
*    Check whether subtitle track is enable.  Since subtitle is enable on if
*    video is enable in our design, it is taken into consideration as well.
*
*****************************************************************************/
static kal_bool _MPLVP_IS_ENABLE_SUBTITLE(mpl_session_struct *self)
{
    if (MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_SUBTITLE])
    && MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]))
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
* DESCRIPTION
*    Record every instance each time MDI contructs
*
*****************************************************************************/
static void mpl_session_set_global_context(mpl_session_struct* mpl, kal_bool init)
{
    kal_bool fgFoundError = KAL_FALSE;
    const mpl_session_struct * prSession0 = mpl_session_cntx_p[0];
    const mpl_session_struct * prSession1 = mpl_session_cntx_p[1];
    const mpl_session_struct * prSession2 = mpl_session_cntx_p[2];


    kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_SET_CONTEXT, mpl, prSession0, prSession1);

    if (init)
    {
        if (prSession0 == NULL)
        {
            mpl_session_cntx_p[0] = mpl;
        }
        else if (prSession1 == NULL)
        {
            mpl_session_cntx_p[1] = mpl;
        }
        else if (prSession2 == NULL)
        {
            mpl_session_cntx_p[2] = mpl;
        }
        else
        {
            fgFoundError = KAL_TRUE;
        }
    }
    else
    {
        if (mpl == prSession0)
        {
            mpl_session_cntx_p[0] = NULL;
        }
        else if (mpl == prSession1)
        {
            mpl_session_cntx_p[1] = NULL;
        }
        else if (mpl == prSession2)
        {
            mpl_session_cntx_p[2] = NULL;
        }
        else
        {
            fgFoundError = KAL_TRUE;
        }

        if (mpl == _prVideoSession)
        {
            _prVideoSession = NULL;
        }
    }

    if (KAL_TRUE == fgFoundError)
    {
        ASSERT(0);
    }
}

/*****************************************************************************
* DESCRIPTION
*    - Record the instance used for video
*    - The number of video instance is limited to one
*
*****************************************************************************/
static void mpl_session_set_video_context(mpl_session_struct* prSelf)
{
    /* MPL only has one video context */
    /* Assign a possible video context candicate*/
    if (prSelf->rOpenInfo.open_track & MED_VID_VISUAL_ONLY)
    {
        if (_prVideoSession != NULL)
        {
            ASSERT(0);
        }
        _prVideoSession = prSelf;
    }
}

/*****************************************************************************
* DESCRIPTION
*    Reset some parameters in the beginning
*
*****************************************************************************/
static void mpl_session_set_default(mpl_session_struct* self)
{
    kal_uint32 i = 0;
    for (; i < SOURCE_PROVIDER_PORT_MAX; i++)
    {
        self->au1StreamIdx[i] = MPL_SESSION_INVALID_INDEX;
    }

    self->u8StopTime = MPL_SESSION_INVALID_TIME;
    self->eVidQuality = VIDEO_DEC_MODE_INVALID;
}

/*****************************************************************************
* DESCRIPTION
*    MPL calls this function to notify MDI events
*
*****************************************************************************/
static void mpl_session_client_event_callback(mpl_session_struct* self, mpl_player_event_t rClientEventType, media_error_t rError)
{
    mpl_player_client_t *mpl_client = self->mpl_client;

    kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_EVENT_CALLBACK, rClientEventType, rError);
    mpl_client->on_event(mpl_client, rClientEventType, rError);
}

/*****************************************************************************
* DESCRIPTION
*     API of memory allocation for Source
*
*****************************************************************************/
void* mpl_session_player_alloc_mem(void *client, kal_uint32 size, med_mem_type_enum type)
{
    mpl_session_struct *self = (mpl_session_struct *)client;
    void *ptr;

    ptr = mpl_session_alloc_ext_mem(self->mpl_client, size, type);
    MPLVP_TRACE(TRACE_FUNC, VID_TRC_MPL_SESSION_MEM_ALLOC, ptr, size);

    return ptr;
}

/*****************************************************************************
* DESCRIPTION
*     API of memory de-allocation for Source
*
*****************************************************************************/
void mpl_session_player_free_mem(void *client, void* p, med_mem_type_enum type)
{
    mpl_session_struct *self = (mpl_session_struct *)client;

    MPLVP_TRACE(TRACE_FUNC, VID_TRC_MPL_SESSION_MEM_FREE, p);
    mpl_session_free_ext_mem(self->mpl_client, &p, type);
}

/*****************************************************************************
* DESCRIPTION
*     Pass the bitstream from Source to Audio
*
*****************************************************************************/
static VIDEO_ERROR_TYPE_T _MPLVP_SourceSendBuffer2AudioDecoder(void *pHandle, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    Media_Status eRet;
    mpl_session_struct *self = (mpl_session_struct *)pHandle;
    MHdl *mhdl_handle = self->mhdl_handle;

    if (NULL != mhdl_handle)
    {
        eRet =  mhdl_handle->EmptyThisBuffer(mhdl_handle, (void *)prBuffHeader);
        if (eRet != MEDIA_SUCCESS)
        {
            return VIDEO_ERROR_BUFF_FULL;
        }
    }
    return VIDEO_ERROR_NONE;
}

/*****************************************************************************
* DESCRIPTION
*     Return the bitstream from Audio to Source
*
*****************************************************************************/
static kal_bool mpl_session_audio_fill_this_buffer(MHdl *handle, void *prBuffHeader)
{
    mpl_session_struct *self;
    VIDEO_ERROR_TYPE_T eErr;
    VIDEO_COMPONENT_MI_TYPE_T *source_handle;

    handle->GetUserData(handle, (void **)&self);
    source_handle = self->source_handle;

    eErr = source_handle->pfnFillThisBuffer(self->source_cntx, (VIDEO_BUFFERHEADER_TYPE_T *)prBuffHeader);
    if (eErr != VIDEO_ERROR_NONE)
    {
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }
}

/*****************************************************************************
* DESCRIPTION
*     Pass the bitstream from Source to Video Decoder
*
*****************************************************************************/
static VIDEO_ERROR_TYPE_T _MPLVP_SourceSendBuffer2VideoDecoder(void *pHandle, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    mpl_session_struct *self = (mpl_session_struct *)pHandle;
    VIDEO_COMPONENT_TYPE_T *decoder_handle = self->decoder_handle;

    return decoder_handle->pfnEmptyThisBuffer(prBuffHeader);
}

/*****************************************************************************
* DESCRIPTION
*     Return the bitstream from Video Decoder to Source
*
*****************************************************************************/
static VIDEO_ERROR_TYPE_T mpl_session_video_fill_this_buffer(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    const mpl_session_struct *const self = _prVideoSession;
    VIDEO_COMPONENT_MI_TYPE_T *source_handle = self->source_handle;

    return source_handle->pfnFillThisBuffer(self->source_cntx, prBuffHeader);
}

#if defined(__VE_SUBTITLE_SUPPORT__)
/*****************************************************************************
* DESCRIPTION
*     Pass the text From Source to Subtitle Decoder
*
*****************************************************************************/
static VIDEO_ERROR_TYPE_T _MPLVP_SourceSendBuffer2SubtitleDecoder(void *pHandle, VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{

    const mpl_session_struct *self = (mpl_session_struct *)pHandle;
    VIDEO_COMPONENT_TYPE_T *prSubtitleHandle = self->prSubtitleDecoderHdlr;

    return prSubtitleHandle->pfnEmptyThisBuffer(prBuffHeader);
}
#endif
/* one for allocator, one for free */
static const MPL_SESSION_MEM_API_T mpl_session_mem_api =
{
    mpl_session_player_alloc_mem,
    mpl_session_player_free_mem
};

static const MPL_SESSION_EMPTY_BUFFER_API_T mpl_session_empty_buffer_api =
{
    _MPLVP_SourceSendBuffer2AudioDecoder,
    _MPLVP_SourceSendBuffer2VideoDecoder,
#if defined(__VE_SUBTITLE_SUPPORT__)
    _MPLVP_SourceSendBuffer2SubtitleDecoder
#else
    NULL
#endif
};

static kal_bool _MPLVP_IsStreamMode(med_mode_enum eMode)
{
    if (eMode == MED_MODE_STREAM || eMode == MED_MODE_CMMB)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
* DESCRIPTION
*     Get the array index for cutom settings according to codec type
*
*****************************************************************************/
static kal_uint32 mpl_session_get_custom_format_index(kal_uint32 codec_type)
{
    switch (codec_type)
    {
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) ||defined(__VE_MPEG4_DEC_HW_SUPPORT__))
        case MEDIA_CODEC_VID_MPEG4:
        case MEDIA_CODEC_VID_H263:
            return MPLY_CUSTOM_FORMAT_MP4;
#endif
#if defined(__VE_RV_DEC_SW_SUPPORT__)
        case MEDIA_CODEC_VID_RV_8:
        case MEDIA_CODEC_VID_RV_9:
        case MEDIA_CODEC_VID_RV_10:
            return MPLY_CUSTOM_FORMAT_RM;
#endif
#if (defined(__VE_H264_DEC_SW_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__))
        case MEDIA_CODEC_VID_H264:
            return MPLY_CUSTOM_FORMAT_H264;
#endif
#ifdef __VE_VP8_DEC_SW_SUPPORT__
        case MEDIA_CODEC_VID_VP8:
            return MPLY_CUSTOM_FORMAT_VP8;
#endif
        default:
            break;
    }
    return MPLY_CUSTOM_FORMAT_MP4;
}

/*****************************************************************************
* DESCRIPTION
*     Reset some flags in the beginning of playing
*
*****************************************************************************/
static void _MPLVP_Reset_Flags(mpl_session_struct *self)
{
    self->fgVideoBuffered = KAL_FALSE;
    self->fgAuidioBuffered = KAL_FALSE;
    self->fgRendererError = KAL_FALSE;
    self->fgVideoRunning = KAL_FALSE;
    self->fgLCDTriggered = KAL_FALSE;
    self->fgAudioUnderflow = KAL_FALSE;
    self->fgAudioReady2Play = KAL_FALSE;
    self->fgBuffered = KAL_FALSE;
    self->fgAudFinished = KAL_FALSE;
    self->fgAudError = KAL_FALSE;
}

/*****************************************************************************
* DESCRIPTION
*     Reset more flags in the beginning of seeking
*
*****************************************************************************/
static void mpl_session_reset_flag(mpl_session_struct *self)
{
    _MPLVP_Reset_Flags(self);

    self->fgCallbackedAudioTrackError = KAL_FALSE;
    self->fgCallbackedVideoTrackError = KAL_FALSE;

    self->fgVidError = KAL_FALSE;
    self->fgVidFinished = KAL_FALSE;

#if defined(__VE_SUBTITLE_SUPPORT__)
    self->fgSubtitleError = KAL_FALSE;
#endif
}

/*****************************************************************************
* DESCRIPTION
*     Select/unselect a port of Source
*
*****************************************************************************/
static media_error_t mpl_session_set_port(mpl_session_struct *prSelf, SP_PORT_TYPE_T ePort, kal_bool fgEnable)
{
    SPIF_PORT_T rSourcePort;
    VIDEO_ERROR_TYPE_T eError;
    kal_uint32 event_group;
    VIDEO_COMPONENT_MI_TYPE_T *source_handle = prSelf->source_handle;

    MPLVP_TRACE(TRACE_FUNC, VID_TRC_MPL_SOURCE_SET_PORT, ePort, fgEnable);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    rSourcePort.eType = ePort;
    rSourcePort.fgEnable= fgEnable;
    eError = source_handle->pfnSetParameter(prSelf->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_SELECT_PORT, &rSourcePort);
    switch(eError)
    {
        case VIDEO_ERROR_UNUSED_OPERATION:
        case VIDEO_ERROR_NONE:
            return MED_S_OK;
        case VIDEO_ERROR_ASYNC_OPERATION:
        {
            kal_retrieve_eg_events(prSelf->rEventID,
                    (MPL_SESSION_EG_SOURCE_PORT_DONE | MPL_SESSION_EG_SOURCE_ERROR),
                    KAL_OR_CONSUME,
                    &event_group,
                    KAL_SUSPEND);
            if (event_group & MPL_SESSION_EG_SOURCE_ERROR)
            {
                return MED_E_FAIL;
            }
            else
            {
                return MED_S_OK;
            }
        }
        //break;
        //case VIDEO_ERROR_INPUT_PARAM_ERROR
        default:
            ASSERT(0);
            return MED_E_FAIL;
    }

//    return MED_E_FAIL;
}

/*****************************************************************************
* DESCRIPTION
*     If a port is valid, select/unselect the port of Source
*
*****************************************************************************/
static media_error_t _MPLVP_ConfigPort(mpl_session_struct *prSelf, SP_PORT_TYPE_T ePort, kal_bool fgOpen)
{
    if (MPL_IS_STRM_INVALID(prSelf->au1StreamIdx[ePort]))
    {
        return MED_S_OK;
    }
    else
    {
        return mpl_session_set_port(prSelf, ePort, fgOpen);
    }
}

/*****************************************************************************
* DESCRIPTION
*    - Set seek time to Source
*    - Asynchrous operation
*
*****************************************************************************/
static media_error_t mpl_session_set_seek_time(mpl_session_struct *prSelf, SP_PORT_TYPE_T ePort, kal_uint64 *pu8SeekTime, kal_bool fgUpdateTimeOnly)
{
    VIDEO_ERROR_TYPE_T eError;
    kal_uint32 event_group;
    SPIF_SEEK_TIME_T rSeekTime;
    VIDEO_COMPONENT_MI_TYPE_T *source_handle = prSelf->source_handle;
#ifdef __VE_STREAM_SUPPORT__
    media_stream_t *pVidStream = &prSelf->vid_stream;
#endif

    if ((MPL_IS_STRM_INVALID(prSelf->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO]) && ePort == SOURCE_PROVIDER_PORT_AUDIO)
        || (MPL_IS_STRM_INVALID(prSelf->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]) && ePort == SOURCE_PROVIDER_PORT_VIDEO)
#if defined(__VE_SUBTITLE_SUPPORT__)
        || (MPL_IS_STRM_INVALID(prSelf->au1StreamIdx[SOURCE_PROVIDER_PORT_SUBTITLE]) && ePort == SOURCE_PROVIDER_PORT_SUBTITLE)
#endif
        )
    {
        return MED_S_OK;
    }

    MPLVP_TRACE(TRACE_FUNC, VID_TRC_MPL_SOURCE_SET_SEEK_TIME, ePort, (kal_uint32)(*pu8SeekTime), fgUpdateTimeOnly);

    /* set seek time */
    rSeekTime.eType = ePort;
    rSeekTime.fgOnlyUpdateTime = fgUpdateTimeOnly;
    rSeekTime.fgEndTimeSendEof = KAL_TRUE;
    rSeekTime.u8StartTime = *pu8SeekTime;
    rSeekTime.u8EndTime = (prSelf->media_scenario == MPL_PREVIEW)? (rSeekTime.u8StartTime + 1) : MPL_SESSION_INVALID_TIME;
    eError = source_handle->pfnSetParameter(prSelf->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_SEEK_TIME, &rSeekTime);
    if (eError == VIDEO_ERROR_ASYNC_OPERATION)
    {
        /* Wait until the port operation is done */
        kal_retrieve_eg_events(prSelf->rEventID, (MPL_SESSION_EG_SOURCE_SEEK_TIME_DONE | MPL_SESSION_EG_SOURCE_ERROR), KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
        if (event_group & MPL_SESSION_EG_SOURCE_ERROR)
        {
            goto FAILED_2_SET_SEEK_TIME;
        }
    }
    else// if (eError != VIDEO_ERROR_NONE)
    {
        goto FAILED_2_SET_SEEK_TIME;
    }

#ifdef __VE_STREAM_SUPPORT__
    if (KAL_TRUE == _MPLVP_IsStreamMode(prSelf->media_mode) && ePort == SOURCE_PROVIDER_PORT_VIDEO)
    {
        /* Add video header to source component */
        SourceProviderStreamingAddHeader(prSelf->source_cntx, SOURCE_PROVIDER_PORT_VIDEO, &pVidStream->dec_config);
    }
#endif

    return MED_S_OK;

FAILED_2_SET_SEEK_TIME:
    MPLVP_TRACE(TRACE_FUNC, MPLVP_FAILED_2_SET_SEEK_TIME, (kal_uint32)(*pu8SeekTime), ePort);
    return MED_E_FAIL;
}

/*****************************************************************************
* DESCRIPTION
*     Select stream of specific port of Source
*
*****************************************************************************/
static media_error_t _MPLVP_SelectStream(mpl_session_struct *self, SP_PORT_TYPE_T ePort, kal_uint8 u1Stream)
{
    media_error_t eRet = MED_S_OK;

#ifdef __VE_STREAM_SUPPORT__
    if (KAL_FALSE == _MPLVP_IsStreamMode(self->media_mode))
#endif
    {
        SPIF_STREAM_T rStream;
        VIDEO_COMPONENT_MI_TYPE_T *source_handle = self->source_handle;
        VIDEO_ERROR_TYPE_T eError;

        MPLVP_TRACE(TRACE_FUNC, VID_TRC_MPL_SOURCE_SET_STREAM, ePort, u1Stream);

        /* set seek time */
        rStream.eType = ePort;
        rStream.u1Track = u1Stream;
        eError = source_handle->pfnSetParameter(self->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_SELECT_STREAM, &rStream);
        if (eError != VIDEO_ERROR_NONE)
        {
            MPLVP_TRACE(TRACE_FUNC, MPLVP_FAILED_2_SELECT_STREAM, ePort, eError);

            eRet = MED_E_FAIL;
        }
    }
    return eRet;
}

/*****************************************************************************
* DESCRIPTION
*    - Get key frame time of specific port from Source
*    - MPL would wait for callback of result to continue
*
*****************************************************************************/
static media_error_t mpl_session_get_key_frame_time_async(mpl_session_struct *self, SP_PORT_TYPE_T ePort, kal_uint64 *pu8Time)
{
    VIDEO_ERROR_TYPE_T eError;
    SPIF_KEY_FRAME_TIME_T *prKeyTime = &self->rKeyTime;
    VIDEO_COMPONENT_MI_TYPE_T *source_handle = self->source_handle;

    prKeyTime->u8StartTime = *pu8Time;
    prKeyTime->ePort = ePort;
    prKeyTime->eDirect = SOURCE_PROVIDER_SEARCH_BACKWARD;
    eError = source_handle->pfnGetParameter(self->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_KEY_FRAME_TIME, prKeyTime);
    if (eError == VIDEO_ERROR_ASYNC_OPERATION)
    {
        return MED_S_ASYNC;
    }
    else if (eError != VIDEO_ERROR_NONE)
    {
        return MED_E_FAIL;
    }
    else
    {
        return MED_S_ASYNC;
    }
}

/*****************************************************************************
* DESCRIPTION
*    - Get key frame time of specific port from Source
*    - MPL blocks and waits for response
*
*****************************************************************************/
static media_error_t _MPLVP_GetKeyFrameTimeInternal(
    mpl_session_struct *prSelf,
    SP_PORT_TYPE_T ePort,
    kal_uint64 *pu8Time,
    kal_uint64 *pu8KeyTime)
{
    SPIF_KEY_FRAME_TIME_T rKeyTime;
    media_error_t eRet = MED_S_OK;
    kal_uint32 event_group;
    VIDEO_COMPONENT_MI_TYPE_T *source_handle = prSelf->source_handle;
    VIDEO_ERROR_TYPE_T eError;

    rKeyTime.u8StartTime = *pu8Time;
    rKeyTime.ePort = ePort;
    rKeyTime.eDirect = SOURCE_PROVIDER_SEARCH_BACKWARD;
    eError = source_handle->pfnGetParameter(prSelf->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_KEY_FRAME_TIME, &rKeyTime);
    if (eError == VIDEO_ERROR_ASYNC_OPERATION)
    {
        /* Wait until the port operation is done */
        kal_retrieve_eg_events(prSelf->rEventID, (MPL_SESSION_EG_SOURCE_KEY_FRAME_DONE | MPL_SESSION_EG_SOURCE_ERROR), KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
        if (event_group & MPL_SESSION_EG_SOURCE_ERROR)
        {
            eRet = MED_E_FAIL;
            goto GET_KEY_FRAME_END;
        }
    }
    else if (eError != VIDEO_ERROR_NONE)
    {
        eRet = MED_E_FAIL;
        goto GET_KEY_FRAME_END;
    }

    *pu8KeyTime = rKeyTime.u8KeyFrameTime;


GET_KEY_FRAME_END:
    MPLVP_TRACE(TRACE_FUNC, MPLVP_GET_KEY_FRAME_TIME, ePort, (kal_uint32)rKeyTime.u8StartTime, (kal_uint32)*pu8KeyTime, eRet);
    return eRet;
}

/*****************************************************************************
* DESCRIPTION
*    - Get key frame time of specific port from Source
*    - MPL blocks and waits for response
*    - Sort of skipping for streaming
*
*****************************************************************************/
static media_error_t mpl_session_get_key_frame_time(mpl_session_struct *prSelf, SP_PORT_TYPE_T ePort, kal_uint64 *pu8Time, kal_uint64 *pu8KeyTime)
{
    media_error_t eRet = MED_S_OK;

#ifdef __VE_STREAM_SUPPORT__
    if (KAL_TRUE == _MPLVP_IsStreamMode(prSelf->media_mode))
    {
        *pu8KeyTime = *pu8Time;
    }
    else
#endif
    {
        eRet = _MPLVP_GetKeyFrameTimeInternal(prSelf, ePort, pu8Time, pu8KeyTime);
    }

    MPLVP_TRACE(TRACE_FUNC, MPLVP_GET_KEY_FRAME_TIME, ePort, 0, (kal_uint32)*pu8KeyTime, eRet);
    return eRet;
}

/*****************************************************************************
* DESCRIPTION
*    Waiting for the result of state change of Source
*
*****************************************************************************/
static media_error_t mpl_session_wait_source_change_state(mpl_session_struct *prSelf)
{
    kal_uint32 event_group;
    media_error_t eRet = MED_S_OK;

    /* Wait until the state transition is done */
    kal_retrieve_eg_events(prSelf->rEventID,
                (MPL_SESSION_EG_SOURCE_COMPLETE | MPL_SESSION_EG_SOURCE_MEM_LACK | MPL_SESSION_EG_SOURCE_ERROR),
                KAL_OR_CONSUME,
                &event_group,
                KAL_SUSPEND);
    //if (event_group & MPL_SESSION_EG_SOURCE_MEM_LACK || event_group & MPL_SESSION_EG_SOURCE_ERROR)
    if (0 == (event_group & MPL_SESSION_EG_SOURCE_COMPLETE))
    {
        if (event_group & MPL_SESSION_EG_SOURCE_MEM_LACK)
        {
            eRet = MED_E_OUT_OF_MEMORY;
        }
        else
        {
            eRet = MED_E_FAIL;
        }
        kal_trace(TRACE_FUNC, MPLVP_FAILED_2_CHANGE_SRC_STATE, eRet);
    }

    return eRet;
}

/*****************************************************************************
* DESCRIPTION
*    Command Source to change its state
*
*****************************************************************************/
static media_error_t _MPLVP_ChangeSourceState(mpl_session_struct *self, VIDEO_STATE_TYPE_T state)
{
    media_error_t eErr;
    const VIDEO_COMPONENT_MI_TYPE_T *source_handle = self->source_handle;

    MPLVP_TRACE(TRACE_FUNC, VID_TRC_MPL_SOURCE_ENTER_STATE, state, self->state);

    if (state == VIDEO_STATE_STOP)
    {
        eErr = _MPLVP_ConfigPort(self, SOURCE_PROVIDER_PORT_AUDIO, KAL_FALSE);
        if (eErr != MED_S_OK)
        {
            return MED_E_FAIL;
        }

        eErr = _MPLVP_ConfigPort(self, SOURCE_PROVIDER_PORT_VIDEO, KAL_FALSE);
        if (eErr != MED_S_OK)
        {
            return MED_E_FAIL;
        }

#if defined(__VE_SUBTITLE_SUPPORT__)
        eErr = _MPLVP_ConfigPort(self, SOURCE_PROVIDER_PORT_SUBTITLE, KAL_FALSE);
        if (eErr != MED_S_OK)
        {
            return MED_E_FAIL;
        }
#endif
    }

    source_handle->pfnSendCommand(self->source_cntx, VIDEO_COMMAND_STATESET, state);

    /* Wait until the state transition is done */
    eErr = mpl_session_wait_source_change_state(self);
    if (eErr != MED_S_OK)
    {
        return eErr;
    }

    if (state == VIDEO_STATE_RUN)
    {
        self->fgSourceRunning = KAL_TRUE;
    }
    else
    {
        self->fgSourceRunning = KAL_FALSE;
    }

    if (state == VIDEO_STATE_IDLE)
    {
        if (MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]))
        {
            eErr = _MPLVP_SelectStream(self, SOURCE_PROVIDER_PORT_VIDEO, self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]);
            if (eErr != MED_S_OK)
            {
                return MED_E_FAIL;
            }
        }

        if (MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO]))
        {
            eErr = _MPLVP_SelectStream(self, SOURCE_PROVIDER_PORT_AUDIO, self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO]);
            if (eErr != MED_S_OK)
            {
                return MED_E_FAIL;
            }
        }

#if defined(__VE_SUBTITLE_SUPPORT__)
        if (_MPLVP_IS_ENABLE_SUBTITLE(self))
        {
            eErr = _MPLVP_SelectStream(self, SOURCE_PROVIDER_PORT_SUBTITLE, self->au1StreamIdx[SOURCE_PROVIDER_PORT_SUBTITLE]);
            if (eErr != MED_S_OK)
            {
                return MED_E_FAIL;
            }
        }
#endif

        //Clear the error message since Source should report again, if there is any, after being switched to IDLE
        kal_mem_set(self->afgSourceDelay, 0, sizeof(self->afgSourceDelay[0])*MPL_ERROR_RECORD_NUM);
    }
    return MED_S_OK;
}

/*****************************************************************************
* DESCRIPTION
*    Command a component to change its state
*
*****************************************************************************/
static void _MPLVP_ChangeOneComponentState(
    mpl_session_struct *prSelf,
    VIDEO_COMPONENT_TYPE_T* prCompHdl,
    VIDEO_STATE_TYPE_T state,
    mpl_session_comp_eg_enum eWaitEvent)
{
    kal_uint32 event_group;
    prCompHdl->pfnSendCommand(VIDEO_COMMAND_STATESET, state);
    kal_retrieve_eg_events(prSelf->rEventID, eWaitEvent, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
}

/*****************************************************************************
* DESCRIPTION
*    Command all component to change their state from the front to the end
*
*****************************************************************************/
static void _MPLVP_ChangeStateFromFront2End(mpl_session_struct *self, VIDEO_STATE_TYPE_T state, kal_bool fgSwitchSubtitleDecoder)
{
    VIDEO_COMPONENT_TYPE_T *decoder_handle = self->decoder_handle;
    VIDEO_COMPONENT_TYPE_T *scheduler_handle = self->scheduler_handle;
    VIDEO_COMPONENT_TYPE_T *render_handle = self->render_handle;

    _MPLVP_ChangeOneComponentState(self, decoder_handle, state, MPL_SESSION_EG_DECODER_COMPLETE);
#if defined(__VE_SUBTITLE_SUPPORT__)
    {
        VIDEO_COMPONENT_TYPE_T *prSubtitleHandle = self->prSubtitleDecoderHdlr;
        if (_MPLVP_IS_ENABLE_SUBTITLE(self)
            && (KAL_TRUE == fgSwitchSubtitleDecoder))
        {
            _MPLVP_ChangeOneComponentState(self, prSubtitleHandle, state, MPL_SESSION_EG_SUBTITLEDECODER_COMPLETE);
        }
    }
#endif
    _MPLVP_ChangeOneComponentState(self, scheduler_handle, state, MPL_SESSION_EG_SCHEDULER_COMPLETE);
    _MPLVP_ChangeOneComponentState(self, render_handle, state, MPL_SESSION_EG_RENDER_COMPLETE);
}

/*****************************************************************************
* DESCRIPTION
*    Command all component to change their state from the end to the front
*
*****************************************************************************/
static void _MPLVP_ChangeStateFromEnd2Front(mpl_session_struct *self, VIDEO_STATE_TYPE_T state, kal_bool fgSwitchSubtitleDecoder)
{
    VIDEO_COMPONENT_TYPE_T *decoder_handle = self->decoder_handle;
    VIDEO_COMPONENT_TYPE_T *scheduler_handle = self->scheduler_handle;
    VIDEO_COMPONENT_TYPE_T *render_handle = self->render_handle;

    _MPLVP_ChangeOneComponentState(self, render_handle, state, MPL_SESSION_EG_RENDER_COMPLETE);
    _MPLVP_ChangeOneComponentState(self, scheduler_handle, state, MPL_SESSION_EG_SCHEDULER_COMPLETE);
#if defined(__VE_SUBTITLE_SUPPORT__)
    {
        VIDEO_COMPONENT_TYPE_T *prSubtitleHandle = self->prSubtitleDecoderHdlr;
        if (_MPLVP_IS_ENABLE_SUBTITLE(self)
            && (KAL_TRUE == fgSwitchSubtitleDecoder))
        {
            _MPLVP_ChangeOneComponentState(self, prSubtitleHandle, state, MPL_SESSION_EG_SUBTITLEDECODER_COMPLETE);
        }
    }
#endif
    _MPLVP_ChangeOneComponentState(self, decoder_handle, state, MPL_SESSION_EG_DECODER_COMPLETE);
}

/*****************************************************************************
* DESCRIPTION
*    Command all component to change their state
*
*****************************************************************************/
static void _MPLVP_ChangeComponentState(mpl_session_struct *self, VIDEO_STATE_TYPE_T state, kal_bool fgSwitchSubtitleDecoder)
{
    if (MPL_IS_STRM_INVALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]))
    {
        return;
    }

    switch (state)
    {
        case VIDEO_STATE_INIT:
        case VIDEO_STATE_STOP:
        case VIDEO_STATE_IDLE:
        case VIDEO_STATE_CLOSE:
            _MPLVP_ChangeStateFromFront2End(self, state, fgSwitchSubtitleDecoder);
            break;
        case VIDEO_STATE_RUN:
            _MPLVP_ChangeStateFromEnd2Front(self, state, fgSwitchSubtitleDecoder);
            break;
        default:
            break;
    }

    kal_trace(TRACE_FUNC, VID_TRC_MPL_VIDEO_ENTER_STATE, self->state, state);

    if (state == VIDEO_STATE_RUN)
    {
        /* Set flag: components in video path have be in RUN state. This is for error handling. */
        self->fgVideoRunning = KAL_TRUE;
    }
    else
    {
        self->fgVideoRunning = KAL_FALSE;
    }
}

/*****************************************************************************
* DESCRIPTION
*    Enable/disable the clock of Scheduler
*
*****************************************************************************/
static void _MPLVP_ConfigClock(mpl_session_struct *prSelf, kal_bool fgEnable)
{
    const VIDEO_COMPONENT_TYPE_T *scheduler_handle = prSelf->scheduler_handle;

    kal_take_mutex(prSelf->rMutexID);
    scheduler_handle->pfnSetParameter(VIDEO_PARAM_CLOCK_ENABLE, &fgEnable);
    prSelf->fgClockEnabled = fgEnable;
    kal_give_mutex(prSelf->rMutexID);
}

/*****************************************************************************
* DESCRIPTION
*    - Reset recover events of Scheduler
*    - Notify the end of buffering state (Speedy algorithm may apply from now
*      on)
*    - Unset Bypass mode so that Renderer starts to show video frame
*
*****************************************************************************/
static void mpl_session_start_avsync(mpl_session_struct *self)
{
    VIDEO_COMPONENT_TYPE_T *scheduler_handle = self->scheduler_handle;

    /* Ask clock to start to do AV sync. Must put after Media_A2V_SetFreq() */
    _MPLVP_ConfigClock(self, KAL_TRUE);
    scheduler_handle->pfnSetParameter(VIDEO_PARAM_RECOVER_RESET0, NULL);
    scheduler_handle->pfnSetParameter(VIDEO_PARAM_RECOVER_RESET1, NULL);

    if (KAL_TRUE == self->fgDecoderStartBuffering)
    {
        self->decoder_handle->pfnSetParameter(VIDEO_PARAM_BUFFERING_DONE, NULL);
        self->fgDecoderStartBuffering = KAL_FALSE;
    }

    mpl_session_set_render_bypass_in_running_state(self, KAL_FALSE);
}

/*****************************************************************************
* DESCRIPTION
*    Close Source
*
*****************************************************************************/
static media_error_t mpl_session_close_source(mpl_session_struct *self)
{
    media_error_t eErr;

    /* Chage source to close */
    eErr = _MPLVP_ChangeSourceState(self, VIDEO_STATE_CLOSE);
    if (eErr != MED_S_OK)
    {
        return MED_E_FAIL;
    }

    if (NULL != self->source_cntx)
    {
    #if !defined(__STREAM_SERVER_SUPPORT__)
        ReleaseSourceProviderHandle(self->source_cntx);
    #endif
        self->source_handle = NULL;
        self->source_cntx = NULL;
    }

    return MED_S_OK;
}

/*****************************************************************************
* DESCRIPTION
*    Get current time from either Scheduler or Audio.  Scheduler has highest
*    priority when video path is on
*
*****************************************************************************/
static kal_uint64 _MPLVP_GetCurrentTime(mpl_session_struct *self)
{
    VIDEO_COMPONENT_TYPE_T *scheduler_handle = self->scheduler_handle;
    MHdl *mhdl_handle = self->mhdl_handle;
    kal_uint64 play_time;

    if (scheduler_handle)
    {
        scheduler_handle->pfnGetParameter(VIDEO_PARAM_CURR_TIME, &play_time);
        return MPL_SESSION_COMPTIME_TO_TIME(play_time);
    }
    else if (mhdl_handle)
    {
        return mhdl_handle->GetCurrentTime(self->mhdl_handle);
    }
    else
    {
        return 0;
    }
}

/*****************************************************************************
* DESCRIPTION
*    - Close Audio each time user/app stops playing.
*    - Get the current time before closing for APP, who would query the time
*      for resuming playing later
*
*****************************************************************************/
static void mpl_session_close_audio(mpl_session_struct *self)
{
    MHdl *mhdl_handle = self->mhdl_handle;

    if (NULL != mhdl_handle)
    {
        mhdl_handle->Stop(mhdl_handle);

        if (self->play_audio && !self->fgAudFinished)
        {
            self->current_time = _MPLVP_GetCurrentTime(self);
            kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_AUDIO_STOP_TIME, (kal_uint32)self->current_time);
        }

        /* Close aud_stretch before close audio_handle */
#ifdef __VE_BES_TS_SUPPORT__
        mpl_session_med_aud_func.pfn_aud_stretch_close();
#endif

        AudioPP_EnableBesSoundinVideo();

        mhdl_handle->Close(mhdl_handle);
        self->mhdl_handle = NULL;
    }

}

/*****************************************************************************
* DESCRIPTION
*    Prepare for video seeking
*    - Set seek time to Source
*    - Select video port of Source
*    - Flush Decoder if necessary
*
*****************************************************************************/
static media_error_t mpl_session_seek_video_path(mpl_session_struct *prSelf, kal_uint64 u8SeekTime, kal_bool fgUpdateTimeOnly)
{
    media_error_t eErr;
    const VIDEO_COMPONENT_TYPE_T *decoder_handle = prSelf->decoder_handle;
    VIDEO_ERROR_TYPE_T eError;

    /* source: disable video port*/
    eErr = _MPLVP_ConfigPort(prSelf, SOURCE_PROVIDER_PORT_VIDEO, KAL_FALSE);
    if (eErr != MED_S_OK)
    {
        return MED_E_FAIL;
    }

    if (KAL_FALSE == fgUpdateTimeOnly)
    {
        // decoder: flush frames
        eError = decoder_handle->pfnSetParameter(VIDEO_PARAM_FLUSH_FRM, NULL);
        stack_change_priority_by_module_ID(MOD_VCODEC_V2, TASK_PRIORITY_VFILE-1);
        if (eError == VIDEO_ERROR_ASYNC_OPERATION)
        {
            kal_uint32 event_group;

            kal_retrieve_eg_events(prSelf->rEventID, MPL_SESSION_EG_DECODER_FLSH_DONE, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
        }
        stack_change_priority_by_module_ID(MOD_VCODEC_V2, TASK_PRIORITY_VCODEC_V2_LOW);

        eError = decoder_handle->pfnSetParameter(VIDEO_PARAM_START_BUFFERING, NULL);
        if (eError == VIDEO_ERROR_NONE)
        {
            prSelf->fgDecoderStartBuffering = KAL_TRUE;
        }
    }

    // source: video port seek
    eErr = mpl_session_set_seek_time(prSelf, SOURCE_PROVIDER_PORT_VIDEO, &u8SeekTime, fgUpdateTimeOnly);
    if (eErr != MED_S_OK)
    {
        return MED_E_FAIL;
    }

    /* source: enable video port*/
    eErr = _MPLVP_ConfigPort(prSelf, SOURCE_PROVIDER_PORT_VIDEO, KAL_TRUE);
    if (eErr != MED_S_OK)
    {
        return MED_E_FAIL;
    }

    return MED_S_OK;
}

#if defined(__VE_SUBTITLE_SUPPORT__)
/*****************************************************************************
* DESCRIPTION
*    Prepare for video seeking
*    - Set seek time to Source
*    - Select subtitle port of Source
*
*****************************************************************************/
static media_error_t _MPLVP_SeekSubtitle(mpl_session_struct *self, kal_uint64 u8SeekTime)
{
    media_error_t eErr;

    eErr = _MPLVP_ConfigPort(self, SOURCE_PROVIDER_PORT_SUBTITLE, KAL_FALSE);
    if (eErr != MED_S_OK)
    {
        return MED_E_FAIL;
    }

    eErr = mpl_session_set_seek_time(self, SOURCE_PROVIDER_PORT_SUBTITLE, &u8SeekTime, KAL_FALSE);
    if (eErr != MED_S_OK)
    {
        return MED_E_FAIL;
    }

    return MED_S_OK;
}
#endif

/*****************************************************************************
* DESCRIPTION
*    - Disable the clock of Scheduler
*    - Get the current time before closing for APP, who would query the time
*      for resuming playing later
*    - Command all component to STOP state
*
*****************************************************************************/
static media_error_t mpl_session_stop_video(mpl_session_struct *self)
{
    if (MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO])
        && (self->fgVideoRunning == KAL_TRUE))
    {
        /* Need to set clock enable as false before change clock state to STOP */
        _MPLVP_ConfigClock(self, KAL_FALSE);

        /* Get current time for play usage: audio play time */
        if (!self->play_audio || self->fgAudFinished)
        {
            self->current_time = mpl_session_get_play_time(self);
        }

        /* stop video */
        _MPLVP_ChangeComponentState(self, VIDEO_STATE_STOP, KAL_TRUE);
    }
    return MED_S_OK;
}

/*****************************************************************************
* DESCRIPTION
*    - Raise the priority of Source once video is off
*    - Stop video path
*    - Clear the buffer of Source
*
*****************************************************************************/
static media_error_t mpl_session_stop_video_path(mpl_session_struct *prSelf)
{
    media_error_t eErr;
    VIDEO_COMPONENT_MI_TYPE_T *source_handle = prSelf->source_handle;
    VIDEO_ERROR_TYPE_T eError;

    /* disable video port */
    eErr = _MPLVP_ConfigPort(prSelf, SOURCE_PROVIDER_PORT_VIDEO, KAL_FALSE);
    if (eErr != MED_S_OK)
    {
        return MED_E_FAIL;
    }

    eError = source_handle->pfnSetParameter(prSelf->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_CHANGE_HIGH_TASK_PRIORITY, NULL);
    if (eError != VIDEO_ERROR_NONE)
    {
        kal_trace(TRACE_FUNC, MPLVP_FAILED_2_CHANGE_SOURCE_PRIORITY, eError);
        return MED_E_FAIL;
    }

    mpl_session_stop_video(prSelf);

    // Command Source clear buffer after video path has stopped
    // This set parameter can only be used in video streaming
    {
        SP_PORT_TYPE_T ePort = SOURCE_PROVIDER_PORT_VIDEO;
        kal_uint32 u4EventGroup;

        eError = source_handle->pfnSetParameter(prSelf->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_FREE_STREAM_BUFFER, &ePort);
        if (eErr == VIDEO_ERROR_ASYNC_OPERATION)
        {
            kal_retrieve_eg_events(prSelf->rEventID,
                            (MPL_SESSION_EG_SOURCE_FREE_MEM| MPL_SESSION_EG_SOURCE_ERROR),
                            KAL_OR_CONSUME,
                            &u4EventGroup,
                            KAL_SUSPEND);
            if (u4EventGroup & MPL_SESSION_EG_SOURCE_ERROR)
            {
                return MED_E_FAIL;
            }
        }
        else
        {
            return MED_E_FAIL;
        }
    }

    return MED_S_OK;
}

/*****************************************************************************
* DESCRIPTION
*    Stop all components, including Source and Audio
*
*****************************************************************************/
static media_error_t mpl_session_stop_internal(mpl_session_struct *self)
{
    media_error_t eErr;

    kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_STOP, self->state);

    /* stop source */
    if (self->fgSourceRunning == KAL_TRUE)
    {
        eErr = _MPLVP_ChangeSourceState(self, VIDEO_STATE_STOP);
        if (eErr != MED_S_OK)
        {
            return MED_E_FAIL;
        }
    }

    /* close audio */
    mpl_session_close_audio(self);

    /* stop video path */
    mpl_session_stop_video(self);

    self->state = MPL_STATE_READY;

    return MED_S_OK;
}

/*****************************************************************************
* DESCRIPTION
*    Stop and play to resync AV
*
*****************************************************************************/
static media_error_t mpl_session_av_resync(mpl_session_struct *self)
{
    media_error_t ret;
    VIDEO_COMPONENT_TYPE_T *render_handle = self->render_handle;
    kal_bool fgHappened = KAL_TRUE;

    /* Stop play first */
    mpl_session_stop_internal(self);

    /* Notify renderer that auto pause / resume happened. In the case, MMI doesn't know that.*/
    /* For LCM scanline rotation */
    render_handle->pfnSetParameter(VIDEO_CONFIG_RENDERER_BYPASS_HW_LAYER_SRC_RECT, &fgHappened);

    /* Play again */
    ret = mpl_session_play_internal(self, KAL_TRUE);

    return ret;
}

/*****************************************************************************
* DESCRIPTION
*    Get key frame time for jumping
*
*****************************************************************************/
static media_error_t _MPLVP_GetJumpTimeofVideo(mpl_session_struct *self, kal_uint64* pu8JumpTime)
{
    kal_uint64 end_time;
    SPIF_VIDEO_STREAM_INFO_T *prVideoStream = &self->rVideoStream;
    media_error_t eErr;

    end_time = self->u8Time4QueryKeyFrame;

    // there's no duration at streaming
    if (KAL_FALSE == _MPLVP_IsStreamMode(self->media_mode))
    {
        if(end_time > prVideoStream->u8Duration)
        {
            end_time = prVideoStream->u8Duration;
        }
    }

    // get kay frame time base on end_time
    eErr = _MPLVP_GetKeyFrameTimeInternal(self, SOURCE_PROVIDER_PORT_VIDEO, &end_time, pu8JumpTime);

    return eErr;
}

/*****************************************************************************
* DESCRIPTION
*    Automatically do seek to jump to next I frame to bring video close to au-
*    dio
*
*****************************************************************************/
static media_error_t mpl_session_av_jump(mpl_session_struct *self)
{
    kal_uint64 key_time;
    media_error_t eErr = MED_S_OK;

    key_time = self->u8JumpTime;

    {
        kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_JUMP, self->u4JumpCount++);

        {
            kal_bool fgJumpToI = KAL_TRUE;
            VFC_IOCtrl(VFC_OP_MPL_NOTIFY_JUMP_I, &fgJumpToI, NULL, NULL); // Notify fluency-control that Jump-to-I occurred.
        }

        /* start to jump */
        eErr = mpl_session_seek_video_path(self, key_time, KAL_FALSE);
        if (eErr != MED_S_OK)
        {
            return MED_E_FAIL;
        }
    }

    return MED_S_OK;
}

static void mpl_session_event_hdlr_internal(mpl_session_struct *self);
static media_error_t mpl_session_init_source_comp_param(mpl_session_struct *self);

/*****************************************************************************
* DESCRIPTION
*    Process Source event in MED when there is only audio
*
*****************************************************************************/
static void _MPLVP_SourceAudioOnlyEventHdlr(void *param)
{
    MPLVP_SourceEventIND_T *prMsg = (MPLVP_SourceEventIND_T *)param;
    mpl_session_struct *self = prMsg->prSelf;
    mpl_session_evt_enum eSourceEvent = prMsg->eEvent;
    mpl_session_state_enum eState = self->state;
    media_error_t eErr;

    free_ctrl_buffer(param);

    kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_SOURCE_EVENT, eState, eSourceEvent);

    switch(eSourceEvent)
    {
        case MPL_SESSION_EVT_SOURCE_OPENED:
            eErr = mpl_session_init_source_comp_param(self);
            if (eErr != MED_S_OK)
            {
                /* open failed */
                mpl_session_close_source(self);
                mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_OPEN, MED_E_FAIL);
            }
            break;

        case MPL_SESSION_EVT_SOURCE_ERROR:
            break;

#if defined(__VE_PGDL_SUPPORT__)
        case MPL_SESSION_EVT_SOURCE_AUDIO_UNDERFLOW:
            {
                mpl_session_stop_internal(self);
                mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_PLAY, MED_E_PDL_AUDIO_UNDERFLOW);
            }
            break;
#endif

        default:
            MPL_ASSERT(0);
            break;
    }

    mpl_session_event_hdlr_internal(self);
}


/*****************************************************************************
* DESCRIPTION
*    Pass the Source event to MED when there is only audio
*
*****************************************************************************/
static void _MPLVP_SourceEventCallback(mpl_session_struct *prSelf, mpl_session_evt_enum eEvent)
{
    MPLVP_SourceEventIND_T *prIND = NULL;

    prIND  = (MPLVP_SourceEventIND_T*)get_ctrl_buffer(sizeof(MPLVP_SourceEventIND_T));

    prIND->prSelf = prSelf;
    prIND->eEvent = eEvent;

    mpl_send_async_context_ilm(MOD_MED, _MPLVP_SourceAudioOnlyEventHdlr, (void*)prIND);
}

static void mpl_session_video_event_hdlr(void *param);

/*****************************************************************************
* DESCRIPTION
*    Pass Source event to MED when there is video
*
*****************************************************************************/
static void _MPLVP_Send2VideoEventHdlr(mpl_session_struct * prSelf, mpl_session_evt_enum event)
{
    mpl_session_vid_event_ind_struct *ind_p = NULL;

    ind_p = (mpl_session_vid_event_ind_struct*)
        get_ctrl_buffer(sizeof(mpl_session_vid_event_ind_struct));

    ind_p->event = event;
    ind_p->session_id = prSelf->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO];
    ind_p->pu1MyMPL = (kal_uint8*)prSelf;

    mpl_send_async_context_ilm(MOD_MED, mpl_session_video_event_hdlr, (void*)ind_p);
}

/*****************************************************************************
* DESCRIPTION
*    Select the event handler for Source dependes on video is on or off
*
*****************************************************************************/
 static void _MPLVP_SourceCallback(mpl_session_struct *self, mpl_session_evt_enum eEvent)
 {
    if (self == _prVideoSession)
    {
        _MPLVP_Send2VideoEventHdlr(self, eEvent);
    }
    else
    {
        _MPLVP_SourceEventCallback(self, eEvent);
    }
}

#if defined(__VE_SUBTITLE_SUPPORT__)
/*****************************************************************************
* DESCRIPTION
*    Process Subtitle Decoder event and pass to MED when necessary
*
*****************************************************************************/
static VIDEO_ERROR_TYPE_T _MPL_SubTitleDecoderCallback(
                            VIDEO_EVENT_TYPE_T event,
                            kal_uint32 data1,
                            kal_uint32 data2,
                            void* data_ptr)
{
    mpl_session_struct *prSelf = _prVideoSession;

    switch(event)
    {
        case VIDEO_EVENT_COMPLETE:
            if(data1 == VIDEO_COMMAND_STATESET)
            {
                kal_set_eg_events(prSelf->rEventID, MPL_SESSION_EG_SUBTITLEDECODER_COMPLETE, KAL_OR);
            }
            break;
        case VIDEO_EVENT_ERROR:
            mpl_session_video_event_callback(MPL_SESSION_EVT_SUBTITLEDECODER_ERROR);
            break;
        default:
            break;
    }

    return VIDEO_ERROR_NONE;
}
#endif

/*****************************************************************************
* DESCRIPTION
*    Force Renderer starts to redarws in short time by pretending the fps is
*    super low
*
*****************************************************************************/
static void _MPLVP_ActivateRendererRedraw(mpl_session_struct * self)
{
      const kal_uint32 u4Period = 20000;

      self->render_handle->pfnSetParameter(VIDEO_CONFIG_RENDERER_SOURCE_FRAME_PERIOD, (void*) &u4Period);
}

/*****************************************************************************
* DESCRIPTION
*    Process Scheduler event and pass to MED when necessary
*
*****************************************************************************/
static VIDEO_ERROR_TYPE_T mpl_session_scheduler_callback(
                            VIDEO_EVENT_TYPE_T event,
                            kal_uint32 data1,
                            kal_uint32 data2,
                            void* data_ptr)
{
    mpl_session_struct *prSelf = _prVideoSession;

#ifdef MPL_DEBUG_INFO
    MPL_ASSERT(prSelf);
#endif

    switch(event)
    {
        case VIDEO_EVENT_COMPLETE:
            if(data1 == VIDEO_COMMAND_STATESET)
            {
                kal_set_eg_events(prSelf->rEventID, MPL_SESSION_EG_SCHEDULER_COMPLETE, KAL_OR);
            }
            else if(data1 == VIDEO_COMMAND_NOTIFY)
            {
                _MPLVP_ActivateRendererRedraw(prSelf);
                mpl_session_video_event_callback(MPL_SESSION_EVT_SCHEDULER_COMPLETE);
            }
            break;
        case VIDEO_EVENT_EXPECTED_BUF_NUM_RDY:
            mpl_session_video_event_callback(MPL_SESSION_EVT_CLOCK_EXPECTED_BUF_NUM_RDY);
            break;
        case VIDEO_EVENT_START:
            // TODO: to be removed
            break;
        case VIDEO_EVENT_RECOVER_JUMPI:
            {
                // Scheduler callbacks the number with us, stored the number as ms
                prSelf->u8JumpTime = *(kal_uint64*)data2 / 1000;
                mpl_session_video_event_callback(MPL_SESSION_EVT_SCHEDULER_RECOVER_JUMP_TO_I);
            }
            break;
        case VIDEO_EVENT_RECOVER_STOPAUDIO:
            mpl_session_video_event_callback(MPL_SESSION_EVT_SCHEDULER_RECOVER_STOP_AUDIO);
            break;
        case VIDEO_EVENT_GET_JUMPTIME:
            {
                // Scheduler callbacks the number with us, stored the number as ms
                prSelf->u8Time4QueryKeyFrame = *(kal_uint64*)data2 / 1000;
                mpl_session_video_event_callback(MPL_SESSION_EVT_GET_AUDIO_TIME_2_SCHDULER);
            }
            break;
#if defined(__VE_STOPTIME_SUPPORT__)
        case VIDEO_EVENT_STOP:
            mpl_session_video_event_callback(MPL_SESSION_EVT_CLOCK_STOP);
            break;
#endif

        default:
            break;
    }

    return VIDEO_ERROR_NONE;
}


/*****************************************************************************
* DESCRIPTION
*    Process Renderer event and pass to MED when necessary
*
*****************************************************************************/
static VIDEO_ERROR_TYPE_T mpl_session_render_callback(
                            VIDEO_EVENT_TYPE_T event,
                            kal_uint32 data1,
                            kal_uint32 data2,
                            void* data_ptr)
{
    mpl_session_struct *prSelf = _prVideoSession;

#ifdef MPL_DEBUG_INFO
    MPL_ASSERT(prSelf);
#endif

    switch(event)
    {
        case VIDEO_EVENT_COMPLETE:
            kal_set_eg_events(prSelf->rEventID, MPL_SESSION_EG_RENDER_COMPLETE, KAL_OR);
            break;
        case VIDEO_EVENT_ERROR:
            mpl_session_video_event_callback(MPL_SESSION_EVT_RENDER_ERROR);
            break;
        default:
            break;
    }

    return VIDEO_ERROR_NONE;
}

/*****************************************************************************
* DESCRIPTION
*    Transfer the codec type from Source to the one Decoder recognizes
*
*****************************************************************************/
static VIDEO_DECODER_CODEC_T mpl_session_codec_type_to_decoder_type(
                media_codec_type_t codec_type)
{
    VIDEO_DECODER_CODEC_T type = VIDEO_CODEC_UNKNOWN;

    switch (codec_type)
    {
        case MEDIA_CODEC_VID_RV_9:
        case MEDIA_CODEC_VID_RV_10:
            type = VIDEO_CODEC_RV9_10;
            break;
        case MEDIA_CODEC_VID_MPEG4:
            type = VIDEO_CODEC_MPEG4;
            break;
        case MEDIA_CODEC_VID_H263:
            type = VIDEO_CODEC_H263;
            break;
        case MEDIA_CODEC_VID_H264:
            type = VIDEO_CODEC_H264;
            break;
        case MEDIA_CODEC_VID_MJPG:
            type = VIDEO_CODEC_MJPEG;
            break;
        case MEDIA_CODEC_VID_VP8:
            type = VIDEO_CODEC_VP8;
            break;
        default:
            break;
    }
    return type;
}

/*****************************************************************************
* DESCRIPTION
*    Transfer the MDI specified scenario to the one of Decoder
*
*****************************************************************************/
static VIDEO_DECODER_SCENARIO_T mpl_session_media_scenario_to_decoder_scenario(
                mpl_scenario_enum media_scenario
                #ifdef __VE_KMV_SUPPORT__
                ,med_type_enum media_type
                #endif
                )
{
    VIDEO_DECODER_SCENARIO_T scenario = VIDEO_SCENARIO_UNKNOWN;

    switch (media_scenario)
    {
        case MPL_DECODER:
        case MPL_MPEG4_DECODER:
        case MPL_DECODER_N_SUBTITLE:
            #ifdef __VE_KMV_SUPPORT__
            if (media_type == MED_TYPE_KMV)
            {
                scenario = VIDEO_SCENARIO_KMV;                
            }
            else
            #endif
            {
                scenario = VIDEO_SCENARIO_PLAYER;
            }
            break;
        case MPL_QVGA:
            scenario = VIDEO_SCENARIO_QVGA;
            break;
        case MPL_PREVIEW:
            #ifdef __VE_KMV_SUPPORT__
            if (media_type == MED_TYPE_KMV)
            {
                scenario = VIDEO_SCENARIO_PREVIEW_KMV;                
            }
            else
            #endif
            {            
                scenario = VIDEO_SCENARIO_PREVIEW;
            }
            break;
        case MPL_CIF:
            scenario = VIDEO_SCENARIO_CIF;
            break;
        case MPL_UPTO_QVGA:
            scenario = VIDEO_SCENARIO_UPTOQVGA;
            break;
        case MPL_UPTO_CIF:
            scenario = VIDEO_SCENARIO_UPTOCIF;
            break;
        case MPL_QVGA_MPEG4SP:
            scenario = VIDEO_SCENARIO_QVGA_MPEG4SP;
            break;
        default:
            break;
    }
    return scenario;
}

#if defined(__VE_SUBTITLE_SUPPORT__)
/*****************************************************************************
* DESCRIPTION
*    Setup Subtitle Decoder
*
*****************************************************************************/
static void _MPLVP_SetupSubtitleDecoder(mpl_session_struct *self, mpl_player_play_t* prPlayParam)
{
    const VIDEO_COMPONENT_TYPE_T *prSubtitleHandle = self->prSubtitleDecoderHdlr;

    {
        VSD_RESOLUTION_T rResolution;
        rResolution.u4Height = prPlayParam->subtitle_height;
        rResolution.u4Width = prPlayParam->subtitle_width;
        prSubtitleHandle->pfnSetParameter(VIDEO_PARAM_VSD_RESOLUTION, (void*)(&rResolution));
    }

    {
        const VSD_ENCODING_T eEncoding = VSD_ENCODING_UTF8;
        prSubtitleHandle->pfnSetParameter(VIDEO_PARAM_VSD_FONT_ENCODING, (void*)(&eEncoding));
    }

    {
        kal_uint32 u4FontSize;
        u4FontSize = self->u4FontSize;
        prSubtitleHandle->pfnSetParameter(VIDEO_PARAM_VSD_FONT_SIZE, (void*)(&u4FontSize));
    }

    {
        VSD_FONT_STYLES_T rFontStyle;
        rFontStyle.fgBold = KAL_FALSE;
        rFontStyle.fgItalic = KAL_FALSE;
        rFontStyle.fgOutline = KAL_FALSE;
        rFontStyle.fgShadow = KAL_TRUE;
        rFontStyle.fgStrikeOut = KAL_FALSE;
        rFontStyle.fgUnderline = KAL_FALSE;
        prSubtitleHandle->pfnSetParameter(VIDEO_PARAM_VSD_FONT_STYLES, (void*)(&rFontStyle));
    }

    {
        VSD_COLORS_T rColor;
        rColor.u4BackColor = 0x00000000;
        rColor.u4PriColor = 0xFFFFFFFF;
        prSubtitleHandle->pfnSetParameter(VIDEO_PARAM_VSD_COLORS, (void*)(&rColor));
    }

    {
        VSD_ALIGNMENT_T rAlignment;
        rAlignment.eHorizontalAlignment = VSD_HORIZONTAL_ALIGNMENT_CENTER;
        rAlignment.eVerticalAlignment = VSD_VERTICAL_ALIGNMENT_MID;
        prSubtitleHandle->pfnSetParameter(VIDEO_PARAM_VSD_ALIGNMENT, (void*)(&rAlignment));
    }

    {
        VSD_CODEC_T eCodec;
        switch(self->rSubtitleInfo.eCodecType)
        {
        case MEDIA_CODEC_SUB_UTF8:
            eCodec = VSD_CODEC_UTF8;
        break;
        case MEDIA_CODEC_SUB_SSA:
            eCodec = VSD_CODEC_SSA_ASS;
        break;
        default:
            ASSERT(0);
            break;
        }
        prSubtitleHandle->pfnSetParameter(VIDEO_PARAM_VSD_CODEC, (void*)(&eCodec));
    }

    {
        prSubtitleHandle->pfnSetParameter(VIDEO_PARAM_VSD_FONT_ENGINE_API, (void*)(&self->rFontEngineApi));
    }
}
#endif

/*****************************************************************************
* DESCRIPTION
*    Get the av-resync threshold according to scenario and set to VFC
*
*****************************************************************************/
static void _MPLVP_SetResyncThreshold2VFC(mpl_session_struct *prSelf, kal_uint32 u4Index)
{
    kal_uint64 tolerance;

#ifdef __VE_STREAM_SUPPORT__
    if (prSelf->media_mode == MED_MODE_STREAM)
    {
        tolerance = mply_custom_get_cust((mply_custom_format_enum)u4Index, CUS_IDX_STREAMING_AVRESYNC);
    }
    #if defined(__VE_STREAM_CMMB_SUPPORT__)
    else if (prSelf->media_mode == MED_MODE_CMMB)
    {
        tolerance = mply_custom_get_cust((mply_custom_format_enum)u4Index, CUS_IDX_CMMB_AVRESYNC);
    }
    #endif
    else
#endif
    {
        tolerance = mply_custom_get_cust((mply_custom_format_enum)u4Index, CUS_IDX_AVRESYNC);
    }
    tolerance = MPL_SESSION_TIME_TO_COMPTIME(tolerance);
    VFC_IOCtrl(VFC_OP_MPL_SET_STOP_AUDIO_THRE, &tolerance, NULL, NULL);
}

/*****************************************************************************
* DESCRIPTION
*    - Setup VFC
*    - Set some parameters to Decoder
*
*****************************************************************************/
static media_error_t mpl_session_init_video_comp_param(mpl_session_struct *self)
{
    kal_uint64 tolerance;
    kal_uint32 format_index = 0;
    VIDEO_COMPONENT_TYPE_T *decoder_handle = self->decoder_handle;
    SPIF_VIDEO_STREAM_INFO_T *prVideoStream = &self->rVideoStream;

    format_index = mpl_session_get_custom_format_index(prVideoStream->eCodecType);

#ifdef __VE_STREAM_SUPPORT__
    if (self->media_mode == MED_MODE_STREAM)
    {
        tolerance = mply_custom_get_cust((mply_custom_format_enum)format_index, CUS_IDX_STREAMING_JUMP2I);
    }
    #if defined(__VE_STREAM_CMMB_SUPPORT__)
    else if (self->media_mode == MED_MODE_CMMB)
    {
        tolerance = mply_custom_get_cust((mply_custom_format_enum)format_index, CUS_IDX_CMMB_JUMP2I);
    }
    #endif
    else
#endif
    {
        tolerance = mply_custom_get_cust((mply_custom_format_enum)format_index, CUS_IDX_JUMP2I);
    }
    tolerance = MPL_SESSION_TIME_TO_COMPTIME(tolerance);
    VFC_IOCtrl(VFC_OP_MPL_SET_JUMP_TO_I_THRE, &tolerance, NULL, NULL);

    _MPLVP_SetResyncThreshold2VFC(self, format_index);

#ifdef __VE_STREAM_SUPPORT__
    if (self->media_mode == MED_MODE_STREAM)
    {
        tolerance = mply_custom_get_cust((mply_custom_format_enum)format_index, CUS_IDX_STREAMING_FIND_KEYFRAME);
    }
    #if defined(__VE_STREAM_CMMB_SUPPORT__)
    else if (self->media_mode == MED_MODE_CMMB)
    {
        tolerance = mply_custom_get_cust((mply_custom_format_enum)format_index, CUS_IDX_CMMB_FIND_KEYFRAME);
    }
    #endif
    else
#endif
    {
        tolerance = mply_custom_get_cust((mply_custom_format_enum)format_index, CUS_IDX_FIND_KEYFRAME);
    }
    tolerance = MPL_SESSION_TIME_TO_COMPTIME(tolerance);
    VFC_IOCtrl(VFC_OP_MPL_SET_JUMP_RANGE, &tolerance, NULL, NULL);

#ifdef __VE_STREAM_SUPPORT__
    if (self->media_mode == MED_MODE_STREAM)
    {
        tolerance = mply_custom_get_cust((mply_custom_format_enum)format_index, CUS_IDX_STREAMING_MAX_TIME2JUMP);
    }
    #if defined(__VE_STREAM_CMMB_SUPPORT__)
    else if (self->media_mode == MED_MODE_CMMB)
    {
        tolerance = mply_custom_get_cust((mply_custom_format_enum)format_index, CUS_IDX_CMMB_MAX_TIME2JUMP);
    }
    #endif
    else
#endif
    {
        tolerance = mply_custom_get_cust((mply_custom_format_enum)format_index, CUS_IDX_MAX_TIME2JUMP);
    }
    tolerance = MPL_SESSION_TIME_TO_COMPTIME(tolerance);
    VFC_IOCtrl(VFC_OP_MPL_SET_MAX_AV_TOLERANCE, &tolerance, NULL, NULL);

    // Set total video duration to CCU
    {
        kal_uint64 u8TotalDuration ;

#ifdef __VE_STREAM_SUPPORT__
        if (KAL_TRUE == _MPLVP_IsStreamMode(self->media_mode))
        {
            //Set a big duration to VFC so that it can correctly do jumping I at streaming
            u8TotalDuration = (kal_uint64)(-1);
        }
        else
#endif
        {
            u8TotalDuration = prVideoStream->u8Duration*1000; // milli-second to micro-second
        }
        VFC_IOCtrl(VFC_OP_MPL_SET_VIDEO_DURATION, &(u8TotalDuration), NULL, NULL);
    }

    /* Decoder parameter */
    // TODO:  is it needed for slim project
    decoder_handle->pfnSetParameter(VIDEO_PARAM_FRAMERATE, &prVideoStream->u4Fps);
    VFC_IOCtrl(VFC_OP_MPL_SET_CONTAINER_FRAMERATE, &prVideoStream->u4Fps, NULL, NULL);
    decoder_handle->pfnSetParameter(VIDEO_PARAM_BITRATE, &prVideoStream->u4AvgBitrate);
    VFC_IOCtrl(VFC_OP_MPL_SET_CONTAINER_BITRATE, &prVideoStream->u4AvgBitrate, NULL, NULL);
#ifdef __VE_PRIRATE_3D_FORMAT__
    if (self->fg3DAnaglyph)
    {
        decoder_handle->pfnSetParameter(VIDEO_PARAM_DECRYPTION_MODE, NULL);
    }

    if (self->eVidQuality != VIDEO_DEC_MODE_INVALID)
    {
        decoder_handle->pfnSetParameter(VIDEO_PARAM_SET_DECODE_MODE, (void *)&self->eVidQuality);
    }
#endif

#if defined(__VE_ENABLE_FORCE_SLEEP__)
    if (self->elapse_ticks != 0 && self->sleep_ticks != 0)
    {
        decoder_handle->pfnSetParameter(VIDEO_PARAM_ELAPSE_TICKS_BEFORE_SLEEP, &self->elapse_ticks);
        decoder_handle->pfnSetParameter(VIDEO_PARAM_SLEEP_TICKS, &self->sleep_ticks);
    }
#endif

    return MED_S_OK;
}

/*****************************************************************************
* DESCRIPTION
*    Decide the type of getting handle from Renderer by chip and scenario
*
*****************************************************************************/
static VA2_VIDEO_RENDERER_TYPE_T _MPLVP_DecideRendererType(mpl_session_struct *prSelf, SPIF_VIDEO_STREAM_INFO_T *prVideoStream)
{
#ifdef MT6256
    if (prSelf->media_scenario == MPL_PREVIEW)
    {
        return (prVideoStream->eCodecType == MEDIA_CODEC_VID_MJPG)? VIDEO_RENDERER_MJPG_THUMBNAIL : VIDEO_RENDERER_VIDEO_THUMBNAIL;
    }
    else
    {
        if (prVideoStream->eCodecType == MEDIA_CODEC_VID_MJPG)
        {
#if defined(__VE_SUBTITLE_SUPPORT__)
            if (_MPLVP_IS_ENABLE_SUBTITLE(prSelf))
            {
                return VIDEO_RENDERER_MJPG_SUBTITLE_PLAYBACK;
            }
            else
#endif
            {
                return VIDEO_RENDERER_MJPG_PLAYBACK;
            }
        }
        else
        {
#if defined(__VE_SUBTITLE_SUPPORT__)
            if (_MPLVP_IS_ENABLE_SUBTITLE(prSelf))
            {
                return VIDEO_RENDERER_VIDEO_SUBTITLE_PLAYBACK;
            }
            else
#endif
            {
                return VIDEO_RENDERER_VIDEO_PLAYBACK;
            }
        }
    }
    #else
    if (prSelf->media_scenario == MPL_PREVIEW)
    {
        return VIDEO_RENDERER_VIDEO_THUMBNAIL;
    }
    else
    {
#if defined(__VE_SUBTITLE_SUPPORT__)
        if (_MPLVP_IS_ENABLE_SUBTITLE(prSelf))
        {
            return VIDEO_RENDERER_VIDEO_SUBTITLE_PLAYBACK;
        }
        else
#endif
        {
            return VIDEO_RENDERER_VIDEO_PLAYBACK;
        }
    }
    #endif
}

static VIDEO_ERROR_TYPE_T mpl_session_decoder_callback(
                            VIDEO_EVENT_TYPE_T event,
                            kal_uint32 data1,
                            kal_uint32 data2,
                            void* data_ptr);

/*****************************************************************************
* DESCRIPTION
*    - Allocate memory from ASM/MED pool here
*    - Get handlers from all components
*    - Connect the components
*    - Initialize VFC here
*    - Command all components to INIT and then IDLE
*
*****************************************************************************/
static media_error_t mpl_session_init_video_comp(mpl_session_struct *self)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VIDEO_DECODER_CODEC_T decoder_type;
    VIDEO_DECODER_SCENARIO_T eScenario;
    VIDEO_COMPONENT_TYPE_T *decoder_handle;
#if defined(__VE_SUBTITLE_SUPPORT__)
    VIDEO_COMPONENT_TYPE_T *prSubtitleHandle;
#endif
    VIDEO_COMPONENT_TYPE_T *scheduler_handle;
    VIDEO_COMPONENT_TYPE_T *render_handle;
    kal_uint32 u4MemSize;
    SPIF_VIDEO_STREAM_INFO_T *prVideoStream = &self->rVideoStream;
    VA2_VIDEO_RENDERER_TYPE_T eRendererType;
    media_error_t eError = MED_S_OK;

    switch (self->media_scenario)
    {
        case MPL_DECODER:
            u4MemSize = VIDEO_V2_DEC_EXT_MEMORY;
            break;
        case MPL_QVGA:
            u4MemSize = VIDEO_V2_QVGA_DEC_EXT_MEMORY;
            break;
        case MPL_PREVIEW:
            u4MemSize = VIDEO_V2_PREVIEW_DEC_EXT_MEMORY;
            break;
        case MPL_CIF:
            u4MemSize = VIDEO_V2_CIF_DEC_EXT_MEMORY;
            break;
#if (defined(__VE_MPEG4_DEC_SW_SUPPORT__) || defined(__VE_MPEG4_DEC_HW_SUPPORT__))
        case MPL_MPEG4_DECODER:
            u4MemSize = VIDEO_V2_DEC_MPEG4_EXT_MEMORY;
            break;
#endif
        case MPL_DECODER_N_SUBTITLE:
            u4MemSize = VIDEO_V2_DEC_N_SUBTITLE_EXT_MEMORY;
            break;
        case MPL_UPTO_QVGA:
            u4MemSize = VIDEO_V2_UPTOQVGA_DEC_EXT_MEMORY;
            break;
        case MPL_UPTO_CIF:
            u4MemSize = VIDEO_V2_UPTOCIF_DEC_EXT_MEMORY;
            break;
        case MPL_QVGA_MPEG4SP:
            u4MemSize = VIDEO_V2_QVGA_MPEG4SP_DEC_EXT_MEMORY;
            break;
        default:
            return MED_E_INVALID_PARAM;
    }

    kal_trace(TRACE_FUNC, MPLVP_ALLOCATING_MEM, u4MemSize);
    self->extmem_start_address = (kal_uint32) mpl_session_alloc_ext_mem(self->mpl_client, u4MemSize, MED_MEM_NONCACHE);
    if (self->extmem_start_address == NULL)
    {
        kal_trace(TRACE_FUNC, MPLVP_FAILED_2_ALLOC_MEM, u4MemSize);
        return MED_E_OUT_OF_MEMORY;
    }

    self->ext_handle = VideoInitExtBuffer(self->extmem_start_address, u4MemSize, VIDEO_SCENARIO_DECODE);
    self->int_handle = VideoInitIntBuffer(self->intmem_start_address, 0, VIDEO_SCENARIO_DECODE);

    decoder_type = mpl_session_codec_type_to_decoder_type(prVideoStream->eCodecType);
    eScenario = mpl_session_media_scenario_to_decoder_scenario(self->media_scenario
                                                               #ifdef __VE_KMV_SUPPORT__
                                                               ,self->media_type
                                                               #endif
                                                               );
    if ((VIDEO_CODEC_UNKNOWN == decoder_type)
    || (VIDEO_SCENARIO_UNKNOWN == eScenario))
    {
        eError = MED_E_FAIL;
        goto ERROR_N_EXIT_VIDEO_INIT;
    }

    {
        VIDEO_DECODER_HDLR_INFO_T rDecoderConfig;
		VIDEO_CONTAINER_INFO_T rContainerInfo;
        VIDEO_DECODER_COMPONENT_TYPE_T rTmp;
        VIDEO_DECODER_ERROR_TYPE_T eDecoderErr = VIDEO_DECODER_ERROR_NONE;

        rDecoderConfig.eCodec = decoder_type;
        rDecoderConfig.eScenario = eScenario;
        rContainerInfo.u4ContainerHeight = self->rVideoStream.u4Height;
        rContainerInfo.u4ContainerWidth = self->rVideoStream.u4Width;
        rDecoderConfig.prContainerInfo = &rContainerInfo;
        rDecoderConfig.prExtMemHdr = self->ext_handle;
        rDecoderConfig.prIntMexHdr = self->int_handle;
        rTmp = GetVideoDecoderHandle(&rDecoderConfig);
        eDecoderErr = rTmp.eErrorType;
        decoder_handle = self->decoder_handle = rTmp.pComponent;

        if (VIDEO_DECODER_ERROR_NONE != eDecoderErr)
        {
            kal_trace(TRACE_FUNC, VID_TRC_MPLVP_DECODER_OPEN_FAILED, eDecoderErr);

            VideoDeInitExtBuffer(self->ext_handle);
            VideoDeInitIntBuffer(self->int_handle, VIDEO_SCENARIO_DECODE);
            self->ext_handle = NULL;
            self->int_handle = NULL;
            if (VIDEO_DECODER_ERROR_INSUFFICIENT_MEMORY == eDecoderErr)
            {
                eError = MED_E_OUT_OF_MEMORY;
            }
            else
            {
                eError = MED_E_FAIL;
            }
            goto ERROR_N_EXIT_VIDEO_INIT;
        }
    }
    self->decoder_callback.pfnEventHandler = mpl_session_decoder_callback;
    decoder_handle->pfnSetCallbacks(&self->decoder_callback);

    // if VFC was initialized before decoder, remember to deinit VFC when failed to get decoder handler
    VFC_IOCtrl(VFC_OP_MPL_INIT_VFC, self->ext_handle, NULL, NULL);
    VFC_IOCtrl(VFC_OP_MPL_SET_SCENARIO, (void*)&self->media_scenario, NULL, NULL);

#if defined(__VE_SUBTITLE_SUPPORT__)
    if (_MPLVP_IS_ENABLE_SUBTITLE(self))
    {
        /* subtitle decoder */
        prSubtitleHandle = self->prSubtitleDecoderHdlr = GetVsdHandle(self->ext_handle);
        self->pfnSubtitleDecoderCallback.pfnEventHandler = _MPL_SubTitleDecoderCallback;
        prSubtitleHandle->pfnSetCallbacks(&self->pfnSubtitleDecoderCallback);
    }
#endif

    /* scheduler handle */
    scheduler_handle = self->scheduler_handle = GetVideoDecSchedulerHandle(VIDEO_SCHEDULER_COMM, self->ext_handle);
    self->scheduler_callback.pfnEventHandler = mpl_session_scheduler_callback;
    scheduler_handle->pfnSetCallbacks(&self->scheduler_callback);

    /* render handle */
    eRendererType = _MPLVP_DecideRendererType(self, prVideoStream);

    render_handle = self->render_handle = GetVideoRendererHandle(eRendererType, self->ext_handle, self->int_handle);
    if (NULL == render_handle)
    {
        ReleaseVideoDecoderHandle(self->decoder_handle);
        self->decoder_handle = NULL;
        ReleaseVideoDecSchedulerHandle(self->scheduler_handle);
        self->scheduler_handle = NULL;
        VFC_IOCtrl(VFC_OP_MPL_DEINIT_VFC, NULL, NULL, NULL);
        eError = MED_E_FAIL;
        goto ERROR_N_EXIT_VIDEO_INIT;
    }

    self->render_callback.pfnEventHandler = mpl_session_render_callback;
    render_handle->pfnSetCallbacks(&self->render_callback);

    _MPLVP_ChangeComponentState(self, VIDEO_STATE_INIT, KAL_TRUE);

    /***************************************************
    *          1            2              3
    *  Source ---> Decoder ---> Scheduler --> Renderer
    *         |                     ^     -->
    *         |                     |      6
    *         --> Subtitle Decoder --
    *         4                     5
    ***************************************************/

    // 1. Source <- Decoder (bitstream)
    VideoConfigComp(
            self->decoder_handle,
            KAL_TRUE,
            VIDEO_PORT_VIDEO_DATA,
            mpl_session_video_fill_this_buffer);

    // 2. Decoder <-> Scheduler (video frame)
    VideoSetupTunnel(self->decoder_handle, self->scheduler_handle, VIDEO_PORT_VIDEO_DATA);

    // 3. Scheduler <-> Renderer (video frame)
    VideoSetupTunnel(self->scheduler_handle, self->render_handle, VIDEO_PORT_VIDEO_DATA);

#if defined(__VE_SUBTITLE_SUPPORT__)
    if (_MPLVP_IS_ENABLE_SUBTITLE(self))
    {
        // 4. Source <- Subtitle Decoder (text)
        VideoConfigComp(
                self->prSubtitleDecoderHdlr,
                KAL_TRUE,
                VIDEO_PORT_SUBTITLE,
                mpl_session_video_fill_this_buffer);

        // 5. Subtitle Decoder <-> Scheduler (Subtitle frame)
        VideoSetupTunnel(self->prSubtitleDecoderHdlr, self->scheduler_handle, VIDEO_PORT_SUBTITLE);

        // 6. Scheduler <-> Renderer (Subtitle frame)
        VideoSetupTunnel(self->scheduler_handle, self->render_handle, VIDEO_PORT_SUBTITLE);
    }
#endif

    _MPLVP_ChangeComponentState(self, VIDEO_STATE_IDLE, KAL_TRUE);

    return MED_S_OK;

ERROR_N_EXIT_VIDEO_INIT:
    mpl_session_free_ext_mem(self->mpl_client, (void **)&self->extmem_start_address, MED_MEM_NONCACHE);
    self->extmem_start_address = NULL;
    return eError;
}

/*****************************************************************************
* DESCRIPTION
*    - Setup Source in the begining
*    - Setup video path if MPL is not under MPL_INFO scenario and the file has
*      video track
*
*****************************************************************************/
static media_error_t mpl_session_init_source_comp_param(mpl_session_struct *self)
{
    SPIF_STREAM_INFO_T rStreamInfo;
    SPIF_VIDEO_STREAM_INFO_T *prVideoInfo;
    SPIF_AUDIO_STREAM_INFO_T *prAudioInfo = NULL;

    SP_CAPABILITY_T rCap;
    media_error_t eErr;
    VIDEO_COMPONENT_MI_TYPE_T *source_handle = self->source_handle;
    SPIF_DRM_INFO_T rDRMINFO;

    source_handle->pfnSetParameter(self->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_EMPTY_FUNC, (void*)&mpl_session_empty_buffer_api);

    if (KAL_FALSE == _MPLVP_IsStreamMode(self->media_mode))
    {
        /* video: query stream info */
        source_handle->pfnGetParameter(self->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_VID_STREAM_INFO, &rStreamInfo);
        if (rStreamInfo.fgSupport == KAL_TRUE)
        {
            prVideoInfo = (SPIF_VIDEO_STREAM_INFO_T*)rStreamInfo.pvStreamInfo;

#ifdef __VE_PRIRATE_3D_FORMAT__
            {
                mpl_player_track_info_t *prVidTrackInfo = &self->rVidTrackInfo;
                mpl_player_video_track_info_t *prVidTrackInfoArray = self->rVidTrackInfoArray;
                kal_uint32 u4TrackNum = rStreamInfo.u4Num;
                kal_uint32 i;

                /* Get 3D track info */
                /* pack into mpl track info struct */
                prVidTrackInfo->u4Num = u4TrackNum;
                prVidTrackInfo->pvTrackInfo = prVidTrackInfoArray;

                for (i = 0; i < u4TrackNum; i++)
                {
                    prVidTrackInfoArray[i].u4TrackIndex = prVideoInfo[i].u4StreamIndex;
                    if (prVideoInfo[i].eProperty == SOURCE_PROVIDER_TRACK_PRIVATE_3D)
                    {
                        prVidTrackInfoArray[i].eVidTrackType = MPL_VIDEO_3D;
                    }
                    else if (prVideoInfo[i].eProperty == SOURCE_PROVIDER_TRACK_NORMAL)
                    {
                        prVidTrackInfoArray[i].eVidTrackType = MPL_VIDEO_2D_NORMAL;
                    }
                    kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_GET_VID_TRACK, prVidTrackInfoArray[i].u4TrackIndex, prVidTrackInfoArray[i].eVidTrackType);
                }
            }
#endif

            /* 2D track as default */
            self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO] = prVideoInfo->u4StreamIndex;
            self->rVideoStream = *prVideoInfo;

            /* get video context index here */
            /* self->rOpenInfo should be assigned before calling this function */
            mpl_session_set_video_context(self);
        }

        /* audio: query stream info */
        source_handle->pfnGetParameter(self->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_AUD_STREAM_INFO, &rStreamInfo);
        if (rStreamInfo.fgSupport == KAL_TRUE)
        {
            prAudioInfo = (SPIF_AUDIO_STREAM_INFO_T*)rStreamInfo.pvStreamInfo;
            self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO] = prAudioInfo->u4StreamIndex;
            self->rAudioStream = *prAudioInfo;

        }
#if defined(__VE_SUBTITLE_SUPPORT__)
        source_handle->pfnGetParameter(self->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_SUBT_STREAM_INFO, &rStreamInfo);
        if (rStreamInfo.fgSupport == KAL_TRUE)
        {
            SPIF_SUBTITLE_STREAM_INFO_T *prSubtitleInfo;

            prSubtitleInfo = (SPIF_SUBTITLE_STREAM_INFO_T*)rStreamInfo.pvStreamInfo;
            self->au1StreamIdx[SOURCE_PROVIDER_PORT_SUBTITLE]= prSubtitleInfo->u4StreamIndex;
            self->rSubtitleInfo = *prSubtitleInfo;
        }
#endif
        // TODO:  Get from source component
        /* Get file system handle for DRM */
        source_handle->pfnGetParameter(self->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_DRM_FSAL, &rDRMINFO);
        self->fs_handle = (void *)rDRMINFO.file_handle;

        source_handle->pfnGetParameter(self->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_CAPABILITY, &rCap);
        self->fgSeekable = (rCap & SOURCE_PROVIDER_SEEK)? KAL_TRUE : KAL_FALSE;

#if defined(__VE_PARSE_TRANSFORMATION_INFO__)
        source_handle->pfnGetParameter(self->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_TRANSFORMATION_INFO, &self->rTransformInfo);
#endif
    }
    else
    {
        self->fgSeekable = KAL_TRUE;
        prAudioInfo = &self->rAudioStream;
    }

    /* check is a valid file (with aud / vid stream) */
    if (MPL_IS_STRM_INVALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO])
        && (MED_VID_AUDIO_ONLY == self->rOpenInfo.open_track))
    {
        kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_FAIL_NO_REQUIRED_TRACK);
        return MED_E_NO_REQUIRED_TRACK;
    }
    else if (MPL_IS_STRM_INVALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO])
         && MPL_IS_STRM_INVALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]))
    {
        kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_FAIL_UNSUPPORTED_FORMAT);
        return MED_E_UNSUPPORTED_FORMAT;
    }

    /* Config audio A/V sync */
    if (MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO]))
    {
        Media_A2V_SetFreq(prAudioInfo->u4SampleRate);
    }

    if (self->media_scenario == MPL_INFO)
    {
        return MED_S_OK;
    }

    /* Init source component */
    eErr = _MPLVP_ChangeSourceState(self, VIDEO_STATE_IDLE);
    if (eErr != MED_S_OK)
    {
        return eErr;
    }

    /* Init video components */
    if (MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]))
    {
        eErr = mpl_session_init_video_comp(self);
        if (eErr != MED_S_OK)
        {
            self->fgVidPathInitFail = KAL_TRUE;
            return eErr;
        }
        mpl_session_init_video_comp_param(self);

        /* callback to VID: opened*/
        if (KAL_FALSE == _MPLVP_IsStreamMode(self->media_mode))
        {
            mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_OPEN, MED_S_OK);
        }
    }
    else
    {
        if (_MPLVP_IS_ENABLE_SUBTITLE(self))
        {
            media_error_t eErr;

            eErr = _MPLVP_ConfigPort(self, SOURCE_PROVIDER_PORT_SUBTITLE, KAL_FALSE);
            if (eErr != MED_S_OK)
            {
                return eErr;
            }
        }

        if (KAL_FALSE == _MPLVP_IsStreamMode(self->media_mode))
        {
            mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_OPEN, MED_E_MP4_NO_VIDEO_TRACK);
        }
    }

    return MED_S_OK;
}

static VIDEO_ERROR_TYPE_T mpl_session_source_callback(
                            void *context,
                            VIDEO_EVENT_TYPE_T event,
                            kal_uint32 data1,
                            kal_uint32 data2,
                            void* data_ptr);

/*****************************************************************************
* DESCRIPTION
*    Get Source handle and command it to INIT state
*
*****************************************************************************/
static media_error_t mpl_session_init_source_comp(mpl_session_struct *self, mpl_player_open_t* open_struct)
{
    SPIF_MEDIA_INFO_T rSourceMediaInfo;
    VIDEO_COMPONENT_MI_TYPE_T *source_handle;
    VIDEO_ERROR_TYPE_T eError;
#if defined(__VE_PGDL_SUPPORT_YOUTUBE__)
    kal_bool fgYTSFile = KAL_FALSE;
#endif
#if defined(__VE_MOT_DECRYPTION__)
    kal_bool fgMOTFile = KAL_FALSE;
#endif

#ifdef __VE_KMV_SUPPORT__
    kal_bool fgKMVFile = KAL_FALSE;
#endif

    kal_mem_set(&rSourceMediaInfo, 0, sizeof(rSourceMediaInfo));

#ifdef __VE_FLV_FILE_FORMAT_SUPPORT__
    if (open_struct->media_type == MED_TYPE_F4V)
    {
        kal_bool validate;

        validate = ValidateF4VFormat(open_struct->data);
        if(validate == KAL_TRUE)
        {
            open_struct->media_type = MED_TYPE_F4V;
        }
        validate = ValidateFLVFormat(open_struct->data);
        if(validate == KAL_TRUE)
        {
            open_struct->media_type = MED_TYPE_FLV;
        }
    }
#endif

    switch(open_struct->media_type)
    {
#ifdef __M3GPMP4_FILE_FORMAT_SUPPORT__
        case MED_TYPE_MP4:
        case MED_TYPE_3GP:
        case MED_TYPE_F4V:
            rSourceMediaInfo.eFileType = SOURCE_PROVIDER_MP4;
            break;
#endif

#if defined(__VE_MOT_DECRYPTION__)
        case MED_TYPE_MOT:
            {
                rSourceMediaInfo.eFileType
                    = SourceProviderContainerType(  MED_MODE_MOT_FILE,
                                                    (kal_uint8*)open_struct->data,
                                                    open_struct->data_size);
                fgMOTFile = KAL_TRUE;
            }
            break;
#endif


#ifdef __VE_KMV_SUPPORT__
	   case MED_TYPE_KMV:
		   rSourceMediaInfo.eFileType = SOURCE_PROVIDER_MP4;
		   fgKMVFile = KAL_TRUE;
		   break;
#endif


#if defined(__MJPEG_DEC_SUPPORT__) || defined(__MJPEG_ENC_SUPPORT__)
        case MED_TYPE_MJPG:
            rSourceMediaInfo.eFileType = SOURCE_PROVIDER_AVI;
            break;
#endif

#ifdef __FLV_FILE_FORMAT_SUPPORT__
        case MED_TYPE_FLV:
        case MED_TYPE_F4A:
            rSourceMediaInfo.eFileType = SOURCE_PROVIDER_FLV;
            break;
#endif

#ifdef __VE_SP_RM__
        case MED_TYPE_RMVB:
        case MED_TYPE_RV:
        case MED_TYPE_RA:
        case MED_TYPE_RM:
            rSourceMediaInfo.eFileType = SOURCE_PROVIDER_RM;
            break;
#endif

#ifdef __VE_MKV_FILE_FORMAT_SUPPORT__
        case MED_TYPE_MKV:
            rSourceMediaInfo.eFileType = SOURCE_PROVIDER_MKV;
            break;
#endif

#ifdef __VE_PGDL_SUPPORT_YOUTUBE__
        case MED_TYPE_YTS:
            {
                rSourceMediaInfo.eFileType = SOURCE_PROVIDER_MP4;
                fgYTSFile = KAL_TRUE;
            }
            break;
#endif
        default:
            return MED_E_NOT_SUPPORTED;
    }

    rSourceMediaInfo.pvHandle = self;
    if (self->media_scenario == MPL_PREVIEW)
    {
        rSourceMediaInfo.eTrack = SOURCE_PROVIDER_TRACK_VIDEO;
    }
    else if (self->media_scenario == MPL_INFO)
    {
            rSourceMediaInfo.eTrack |= SOURCE_PROVIDER_TRACK_META;
            rSourceMediaInfo.eTrack |= SOURCE_PROVIDER_TRACK_AUDIO;
            rSourceMediaInfo.eTrack |= SOURCE_PROVIDER_TRACK_VIDEO;
#if defined(__VE_SUBTITLE_SUPPORT__)
            rSourceMediaInfo.eTrack |= SOURCE_PROVIDER_TRACK_SUBTITLE;
#endif
    }
    else
    {
        if (open_struct->open_track & MED_VID_AUDIO_ONLY)
        {
            rSourceMediaInfo.eTrack |= SOURCE_PROVIDER_TRACK_AUDIO;
        }

        if (open_struct->open_track & MED_VID_VISUAL_ONLY)
        {
            rSourceMediaInfo.eTrack |= SOURCE_PROVIDER_TRACK_VIDEO;
        }

#if defined(__VE_SUBTITLE_SUPPORT__)
        if (open_struct->open_track & MED_VID_SUBTITLE)
        {
            rSourceMediaInfo.eTrack |= SOURCE_PROVIDER_TRACK_SUBTITLE;
        }
#endif
    }

#ifdef __VE_PGDL_SUPPORT_YOUTUBE__
    if (KAL_TRUE == fgYTSFile)
    {
        med_mode_enum eTmp;
        switch(self->media_mode)
        {
            case MED_MODE_PDL_FILE:
                eTmp = MED_MODE_PDL_YTS_FILE;
                break;
            case MED_MODE_FILE:
            case MED_MODE_ARRAY:
            case MED_MODE_BUFFER:
                eTmp = MED_MODE_YTS_FILE;
                break;
            default:
                return MED_E_NOT_SUPPORTED;
        }
        rSourceMediaInfo.eOpenType = eTmp;
    }
    else
#endif
#if defined(__VE_MOT_DECRYPTION__)
    if (KAL_TRUE == fgMOTFile)
    {
        if (self->media_scenario == MPL_PREVIEW)
        {
            rSourceMediaInfo.eOpenType = MED_MODE_MOT_PREVIEW;
        }
        else
        {
            rSourceMediaInfo.eOpenType = MED_MODE_MOT_FILE;
        }
    }
    else
#endif

#ifdef __VE_KMV_SUPPORT__
    if (KAL_TRUE == fgKMVFile)
    {
        if (self->media_scenario == MPL_PREVIEW)
        {
            rSourceMediaInfo.eOpenType = MED_MODE_KMV_PREVIEW;
        }
        else
        {
            rSourceMediaInfo.eOpenType = MED_MODE_KMV_FILE;
        }
    }
	else
#endif
    {
        rSourceMediaInfo.eOpenType = (self->media_scenario == MPL_PREVIEW)? MED_MODE_PREVIEW : self->media_mode;
    }
    rSourceMediaInfo.pu1Data = (kal_uint8*)open_struct->data;
    rSourceMediaInfo.u4Size= open_struct->data_size;
    rSourceMediaInfo.prAPI = (MPL_SESSION_MEM_API_T *)&mpl_session_mem_api;

    eError = GetSourceProviderHandle(&rSourceMediaInfo, &self->source_cntx, &self->source_handle);
    if (eError != VIDEO_ERROR_NONE)
    {
        /* If source componet get handle failed, it should release resource by itself. */
        MPLVP_TRACE(TRACE_FUNC, MPLVP_FAILED_2_GET_DEC_HANDLE, eError);
        if (eError == VIDEO_ERROR_NO_MEMORY)
        {
            return MED_E_OUT_OF_MEMORY;
        }
        else
        {
            return MED_E_FAIL;
        }
    }

    /* Source component opened */
    source_handle = self->source_handle;

    /* Get callback function */
    self->source_callback.pfnMIEventHandler = mpl_session_source_callback;
    source_handle->pfnSetCallbacks(self->source_cntx, &self->source_callback);

    /* Init Source Component */
    // Wait for complete notification on event handler
    source_handle->pfnSendCommand(self->source_cntx, VIDEO_COMMAND_STATESET, VIDEO_STATE_INIT);

    return MED_S_OK;
}

/*****************************************************************************
* DESCRIPTION
*    Adjust play speed for Audio
*
*****************************************************************************/
kal_uint16 mpl_session_get_accurate_play_speed(mpl_session_struct* self, kal_uint16 org_speed)
{
    kal_int16 speed;

    speed = org_speed;

    if (MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO]))
    {
        if (org_speed >= 125 && org_speed <= 130)
        {
            switch (self->aud_format)
            {
            case MEDIA_FORMAT_AAC:
                speed = 128;
                break;
            case MEDIA_FORMAT_AMR:
                speed = 125;
                break;
            }
        }
    }

    if (org_speed >= 75 && org_speed <= 80)
    {
        speed =  80;
    }
    else if (org_speed >= 150 && org_speed <= 160)
    {
        speed = 160;
    }

    return speed;
}

/*****************************************************************************
* DESCRIPTION
*    Fill up the structure of silence information to setup Audio later
*
*****************************************************************************/
void mpl_session_get_audio_silence_info(mpl_session_struct* self, Audio_Stream_Info *prAudioInfo)
{
    SPIF_AUDIO_STREAM_INFO_T *prAudioStream = &self->rAudioStream;

    prAudioInfo->uFormat = self->aud_format;
    prAudioInfo->uChannelNum = prAudioStream->u2Channels;
    prAudioInfo->uSampleRate = prAudioStream->u4SampleRate;
    prAudioInfo->uSubFrameNum = 0;
    prAudioInfo->uFrameDur = prAudioStream->u4FrameDuration;
}

/*****************************************************************************
* DESCRIPTION
*    Initialize Audio
*
*****************************************************************************/
static media_error_t mpl_session_init_audio(mpl_session_struct *self)
{
    MHdl *mhdl_handle;
    Media_Format aud_format;
    SPIF_AUDIO_STREAM_INFO_T *prAudioStream = &self->rAudioStream;
    SPIF_VIDEO_STREAM_INFO_T *prVideoStream = &self->rVideoStream;


    self->aud_format = aud_format = (Media_Format)mpl_get_media_format_from_codec_type(prAudioStream->eCodecType);

    switch (aud_format)
    {
#if defined(AAC_DECODE)
    case MEDIA_FORMAT_AAC:
    case MEDIA_FORMAT_AAC_PLUS:
        {
            kal_uint64 tolerance;
            kal_bool report_error;
            kal_uint32 format_index;

            /* insist av-sync */
            if (MPL_IS_STRM_INVALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]))
            {
                tolerance = 0;
            }
            else
            {
                format_index = mpl_session_get_custom_format_index(prVideoStream->eCodecType);
#if defined(__VE_STREAM_SUPPORT__)
                if (self->media_mode == MED_MODE_STREAM)
                {
                    tolerance = mply_custom_get_cust((mply_custom_format_enum)format_index, CUS_IDX_STREAMING_AVRESYNC);
                }
#if defined(__VE_STREAM_CMMB_SUPPORT__)
                else if (self->media_mode == MED_MODE_CMMB)
                {
                    tolerance = mply_custom_get_cust((mply_custom_format_enum)format_index, CUS_IDX_CMMB_AVRESYNC);
                }
#endif
                else
#endif
                {
                    tolerance = mply_custom_get_cust((mply_custom_format_enum)format_index, CUS_IDX_AVRESYNC);
                }
            }
            report_error = (tolerance == 0) ? KAL_TRUE : KAL_FALSE;

            self->mhdl_handle = AAC_Open(mpl_session_audio_event_callback, NULL, (void *)report_error);
        }
        break;
#endif /*AAC_DECODE*/

#if defined(__COOK_DECODE__)
    case MEDIA_FORMAT_COOK:
        {
            Media_COOK_Param cook_param;
            SPIF_AUDIO_RA_INFO *prAudioRA;

            prAudioRA = &prAudioStream->uCodec.rAudioRA;

            cook_param.nSamples = prAudioRA->u4Samples;
            cook_param.nChannels = prAudioStream->u2Channels;
            cook_param.nRegions = prAudioRA->u4Regions;
            cook_param.nFrameBits = prAudioRA->u4BitPerFrame;
            cook_param.sampRate = prAudioStream->u4SampleRate;
            cook_param.cplStart = prAudioRA->u4CplStart;
            cook_param.cplQbits = prAudioRA->u4CplQBits;

            self->mhdl_handle = COOK_Open(mpl_session_audio_event_callback, NULL, &cook_param);
        }
        break;
#endif /* __COOK_DECODE__ */

#ifdef AMR_CODEC
    case MEDIA_FORMAT_AMR:
#ifdef AMRWB_DECODE
    case MEDIA_FORMAT_AMR_WB:
#endif /* AMRWB_DECODE */
        {
            Media_VM_PCM_Param vpFormat;

            vpFormat.mediaType = aud_format;
            vpFormat.vmParam = (kal_uint32)MEDIA_VMP_AS_RINGTONE;
            self->mhdl_handle = AMR_Open(mpl_session_audio_event_callback, NULL, &vpFormat);
        }
        break;
#endif /* AMR_DECODE */

#ifdef DAF_DECODE
    case MEDIA_FORMAT_DAF:
#ifdef MUSICAM_DECODE
    case MED_TYPE_MUSICAM:
#endif
        {
            Media_Ext_DAF_strm daf_strm;

            daf_strm.channel_num = prAudioStream->u2Channels;
            daf_strm.sample_rate = prAudioStream->u4SampleRate;
            self->mhdl_handle = DAF_Open(mpl_session_audio_event_callback, NULL, &daf_strm);
        }
        break;
#endif

#if defined(WAV_CODEC)
    case MEDIA_FORMAT_PCM_8K:
        {
            Media_PCM_Stream_Param sFormat;

            sFormat.isStereo = (prAudioStream->u2Channels == 2) ? KAL_TRUE : KAL_FALSE;
            sFormat.bitPerSample = prAudioStream->u2BitsPerSample;
            sFormat.sampleFreq = prAudioStream->u4SampleRate;
            sFormat.forceVoice = KAL_FALSE;
            self->mhdl_handle = PCM_Strm_Open(mpl_session_audio_event_callback, &sFormat);
        }
        break;
#endif

#if defined(__DRA_DECODE_SUPPORT__)
    case MEDIA_FORMAT_DRA:
        self->mhdl_handle = DRA_Open(mpl_session_audio_event_callback, NULL, NULL);
        break;
#endif /* __DRA_DECODE_SUPPORT__ */

#if defined(__VORBIS_DECODE__)
    case MEDIA_FORMAT_VORBIS:
        self->mhdl_handle = VORBIS_Strm_Open(mpl_session_audio_event_callback, NULL, NULL);
        break;
#endif
    default:
        return MED_E_FAIL;
        //break;
    }

    //MPL_ASSERT(self->mhdl_handle);

    /* Here we have an audio handle */
    mhdl_handle = self->mhdl_handle;

    mhdl_handle->SetUserData(mhdl_handle, self);

    /* Reset Buffer */
    mhdl_handle->SetParameter(mhdl_handle, AUDPARAM_RESET_BUFFER,  NULL);

    /* set callback function */
    mhdl_handle->SetParameter(mhdl_handle, AUDPARAM_SET_EMPTY_BUFFER_DONE_CALLBACK,  (void *)mpl_session_audio_fill_this_buffer);

    {
        Audio_Stream_Info rAudioInfo;
        /* Set silence info */
        mpl_session_get_audio_silence_info(self, &rAudioInfo);

        mhdl_handle->SetParameter(mhdl_handle, AUDPARAM_SET_SILENCE_INFO,  &rAudioInfo);

        /* This tells audio driver to add frame header per frames, ex: mp4 + aac */
        if (prAudioStream->fgAddHeader || self->fgAudAddHeader /*streaming case */)
        {
            mhdl_handle->SetParameter(mhdl_handle, AUDPARAM_SET_HEADER_INFO,  &rAudioInfo);
            if (KAL_TRUE == _MPLVP_IsStreamMode(self->media_mode))
            {
                mhdl_handle->SetParameter(mhdl_handle, AUDPARAM_AUTO_FILL_SILENCE_BY_TIMESTAMP, NULL);
            }
        }
    }

    mhdl_handle->SetStartTime(mhdl_handle, self->current_time);
    if (MPL_IS_STRM_INVALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]))
    {
        mhdl_handle->SetStopTime(mhdl_handle, self->u8StopTime);
    }

#ifdef __VE_BES_TS_SUPPORT__
    if (self->play_speed != 100)
    {
        mpl_session_med_aud_func.pfn_aud_stretch_set_speed(self->play_speed);
    }
#endif /* __VE_BES_TS_SUPPORT__ */

    AudioPP_DisableBesSoundinVideo();

    return MED_S_OK;
}


/*****************************************************************************
* DESCRIPTION
*    - Update playtime during playing
*    - Return the current time recorded by MPL
*
*****************************************************************************/
static media_time_t mpl_session_get_play_time(mpl_session_struct *self)
{
    if (self->state == MPL_STATE_PLAYING)
    {
        self->current_time = _MPLVP_GetCurrentTime(self);
    }

    kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_CUR_TIME, (kal_uint32)self->current_time);

    return self->current_time;
}

/*****************************************************************************
* DESCRIPTION
*    Setup bypass mode of Renderer
*
*****************************************************************************/
static void _MPLVP_SetBypassModeOfRenderer(mpl_session_struct *self, kal_bool fgBypass)
{
    VIDEO_COMPONENT_TYPE_T *prRenderer = self->render_handle;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    eError = prRenderer->pfnSetParameter(VIDEO_PARAM_RENDERER_BYPASS, (void*) &fgBypass);
    if (VIDEO_ERROR_NONE != eError)
    {
        ASSERT(0);
    }
}

/*****************************************************************************
* DESCRIPTION
*    Set all parameters to Renderer
*
*****************************************************************************/
static void mpl_session_set_render_param(
    mpl_session_struct *self,
    mpl_session_video_config_t *prVideoConfig)
{
    VIDEO_COMPONENT_TYPE_T *rh = self->render_handle;
    mpl_session_video_config_t *cfg = prVideoConfig;


    {
        VA2_FRAME_SIZE_T rDisplaySize;

        rDisplaySize.u4_width = cfg->display_width;
        rDisplaySize.u4_height = cfg->display_height;
        rh->pfnSetParameter(VIDEO_PARAM_RENDERER_DST_FB_SIZE, (void*) &rDisplaySize);
        rh->pfnSetParameter(VIDEO_CONFIG_RENDERER_RESIZE_DST_SIZE, (void*) &rDisplaySize);
    }

    {
        va2_video_renderer_dst_fb_t rDisplayFrameBuffer;

        rDisplayFrameBuffer.u2_index = 0;
        rDisplayFrameBuffer.r_fb_addr.u4_fb_addr_plane0 = (kal_uint32)cfg->image_buffer_p;
        rDisplayFrameBuffer.r_fb_addr.u4_fb_addr_plane1 = 0;
        rDisplayFrameBuffer.r_fb_addr.u4_fb_addr_plane2 = 0;
        rh->pfnSetParameter(VIDEO_PARAM_RENDERER_DST_FB_ADDR, (void*) &rDisplayFrameBuffer);
    }

    {
        va2_video_renderer_post_process_config_t rPPCondfig;

        rPPCondfig.b_brightness = KAL_TRUE;
        rPPCondfig.b_contrast = KAL_TRUE;
        rPPCondfig.u1_brightness = cfg->brightness;
        rPPCondfig.u1_contrast = cfg->contrast;
        rh->pfnSetParameter(VIDEO_CONFIG_RENDERER_POST_PROCESS, (void*) &rPPCondfig);
    }

    {
        kal_uint32 u4Period, u4FPS;

        u4FPS = self->rVideoStream.u4Fps;
        u4Period = (u4FPS == 0) ? 0xFFFFFFFF: (100000 / u4FPS);
        rh->pfnSetParameter(VIDEO_CONFIG_RENDERER_SOURCE_FRAME_PERIOD, (void*) &u4Period);
    }

    {
        kal_bool fgDisableDCc;

        fgDisableDCc = (cfg->force_lcd_hw_trigger) ? KAL_TRUE : KAL_FALSE;
        rh->pfnSetParameter(VIDEO_PARAM_RENDERER_DISABLE_DC_MODE, (void*) &fgDisableDCc);
    }

#ifdef __CONTOUR_IMPROVEMENT_SUPPORT__
    {
        kal_uint32 predict_time;
        VIDEO_COMPONENT_TYPE_T *decoder_handle = self->decoder_handle;

        /* Get prediction time from decoder */
        /* This may be removed, need to dicuss with renderer */

        decoder_handle->pfnGetParameter(VIDEO_PARAM_QUERY_PREDICATION_TIME, &predict_time);
        /* Set prediction time */
        rh->pfnSetParameter(VIDEO_CONFIG_RENDERER_DECODE_TIME, (void*)&predict_time);
    }
#endif /* __CONTOUR_IMPROVEMENT_SUPPORT__ */

    {
        VA2_VIDEO_RENDERER_COLOR_FORMAT_T eColor;
        va2_video_renderer_rotate_flip_t rRFConfig;
        VA2_VIDEO_RENDERER_RENDER_MODE_T eRendererMode;

        switch (cfg->image_data_format)
        {
            case IMG_COLOR_FMT_PACKET_YUYV422:
                eColor = VIDEO_RENDERER_COLOR_PACKED_UYVY422;
                break;
            case IMG_COLOR_FMT_RGB888:
                eColor = VIDEO_RENDERER_COLOR_RGB888;
                break;
            case IMG_COLOR_FMT_RGB565:
            default:
                eColor = VIDEO_RENDERER_COLOR_RGB565;
                break;
        }
        rh->pfnSetParameter(VIDEO_PARAM_RENDERER_DST_COLOR_FORMAT, (void*) &eColor);


        rRFConfig.u2_cw_rotate_angle = cfg->idp_rotate;

        rRFConfig.b_flip = KAL_FALSE;
        rh->pfnSetParameter(VIDEO_PARAM_RENDERER_ROTATE_FLIP, (void*) &rRFConfig);

        switch (cfg->frame_mode)
        {
            case MED_VID_FRAME_FIT_OUTSIDE:
                eRendererMode = VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_OUTSIDE;
                break;
            case MED_VID_FRAME_FIT_INSIDE:
                eRendererMode = VIDEO_RENDERER_RENDER_MODE_TOUCH_WINDOW_FROM_INSIDE;
                break;
            case MED_VID_FRAME_STRETCH:
            default:
                eRendererMode = VIDEO_RENDERER_RENDER_MODE_STRETCH_TO_WINDOW;
                break;
        }
        rh->pfnSetParameter(VIDEO_PARAM_RENDERER_SEMI_AUTO_RENDER_MODE, (void*) &eRendererMode);

        eColor = VIDEO_RENDERER_COLOR_YUV420;
        rh->pfnSetParameter(VIDEO_CONFIG_RENDERER_SRC_COLOR_FORMAT, (void*) &eColor);
    }

    {
        va2_video_renderer_display_surface_t rSurface;

        rSurface.dspl_element_handle = cfg->layer_element;
        rSurface.dspl_ctx_handle = cfg->blt_ctx;
        rSurface.dspl_dev_handle = cfg->blt_dev;
        rh->pfnSetParameter(VIDEO_PARAM_RENDERER_DISPLAY_SURFACE, (void*) &rSurface);
    }

    rh->pfnSetParameter(VIDEO_PARAM_RENDERER_TRIGGER_DISPLAY, (void*) &cfg->fgRendererVisible);


#if defined(__VE_PARSE_TRANSFORMATION_INFO__)
    {
        va2_video_renderer_rotate_flip_t rTmp;

        rTmp.b_flip = (kal_bool)self->rTransformInfo.u1HorizontalMirror;
        rTmp.u2_cw_rotate_angle = self->rTransformInfo.u2Rotation;
        rh->pfnSetParameter(VIDEO_PARAM_RENDERER_VIDEO_FRAME_ROTATE_FLIP, (void*)(&rTmp));
    }
#endif

#if defined(__VE_3D_SIDE_BY_SIDE__)
    {
        VA2_VIDEO_RENDERER_3D_MODE_T eTmp = VIDEO_RENDERER_3D_MODE_NONE;

        switch(prVideoConfig->e3DMode)
        {

        case MPL_RENDERER_3D_MODE_SIDE_BY_SIDE:
            eTmp = VIDEO_RENDERER_3D_MODE_SIDE_BY_SIDE;
            break;
        //case MPL_RENDERER_3D_MODE_TOP_DOWN:
            //eTmp = VIDEO_RENDERER_3D_MODE_TOP_DOWN;
            //break;
        case MPL_RENDERER_3D_MODE_OFF:
        default:
            if (KAL_TRUE == self->fg3DSidebySide)
            {
                eTmp = VIDEO_RENDERER_3D_MODE_SIDE_BY_SIDE;
            }
            else
            {
                eTmp = VIDEO_RENDERER_3D_MODE_NONE;
            }
            break;
        }
        rh->pfnSetParameter(VIDEO_PARAM_RENDERER_3D_MODE, (void*) &eTmp);
    }
#endif
#if defined(__VE_SUBTITLE_SUPPORT__)
    {
        va2_video_renderer_dst_fb_t rTmp;

        rTmp.u2_index = 0;
        rTmp.r_fb_addr.u4_fb_addr_plane0 = (kal_uint32)cfg->subtitle_image_buffer_p;
        rTmp.r_fb_addr.u4_fb_addr_plane1 = 0;
        rTmp.r_fb_addr.u4_fb_addr_plane2 = 0;
        rh->pfnSetParameter(VIDEO_PARAM_RENDERER_SUBTITLE_DST_FB_ADDR, (void*) &rTmp);
    }

    {
        va2_video_renderer_display_surface_t rTmp;

        rTmp.dspl_element_handle = cfg->subtitle_layer_element;
        rTmp.dspl_ctx_handle = cfg->subtitle_blt_ctx;
        rTmp.dspl_dev_handle = cfg->subtitle_blt_dev;
        rh->pfnSetParameter(VIDEO_PARAM_RENDERER_SUBTITLE_DISPLAY_SURFACE, (void*) &rTmp);
    }

    if (NULL != cfg->subtitle_image_buffer_p)
    {
        {
            VA2_VIDEO_RENDERER_COLOR_FORMAT_T eTmp = VIDEO_RENDERER_COLOR_ARGB8888;

            rh->pfnSetParameter(VIDEO_PARAM_RENDERER_SUBTITLE_DST_COLOR_FORMAT, (void*) &eTmp);
        }

        {
            VA2_FRAME_SIZE_T rTmp;

            rTmp.u4_width = cfg->subtitle_width;
            rTmp.u4_height = cfg->subtitle_height;
            rh->pfnSetParameter(VIDEO_PARAM_RENDERER_SUBTITLE_DST_FB_SIZE, (void*) &rTmp);
            rh->pfnSetParameter(VIDEO_CONFIG_RENDERER_SUBTITLE_RESIZE_DST_SIZE, (void*) &rTmp);
        }
    }
#endif
}

/*****************************************************************************
* DESCRIPTION
*    Prepare to setup Renderer
*
*****************************************************************************/
static media_error_t _MPLVP_ConfigRenderer(
                            mpl_session_struct *mpl,
                            mpl_player_play_t* play_struct)
{
    mpl_session_struct *self = mpl;
    mpl_session_video_config_t rVideoConfig;

    if (MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]))
    {
        /* Prepare configuration */
        rVideoConfig.brightness = self->brightness;
        rVideoConfig.contrast = self->contrast;
        rVideoConfig.display_width = play_struct->display_width;
        rVideoConfig.display_height = play_struct->display_height;
        rVideoConfig.image_buffer_p = play_struct->image_buffer_p;
        rVideoConfig.image_data_format = play_struct->image_data_format;
        rVideoConfig.idp_rotate = play_struct->idp_rotate;
        rVideoConfig.display_device = play_struct->display_device;
        rVideoConfig.force_lcd_hw_trigger = play_struct->force_lcd_hw_trigger;
        rVideoConfig.layer_element = play_struct->layer_element;
        rVideoConfig.blt_ctx = play_struct->blt_ctx;
        rVideoConfig.blt_dev = play_struct->blt_dev;

        #if defined(__VE_3D_SIDE_BY_SIDE__)
        rVideoConfig.e3DMode = play_struct->e3DMode;
        #endif

#if defined(__VE_SUBTITLE_SUPPORT__)
        rVideoConfig.subtitle_image_buffer_p = play_struct->subtitle_image_buffer_p;
        rVideoConfig.subtitle_layer_element = play_struct->subtitle_layer_element;
        rVideoConfig.subtitle_blt_ctx = play_struct->subtitle_blt_ctx;
        rVideoConfig.subtitle_blt_dev = play_struct->subtitle_blt_dev;
        rVideoConfig.subtitle_width = play_struct->subtitle_width;
        rVideoConfig.subtitle_height = play_struct->subtitle_height;
#endif

        // TODO: add frame mode in play  struct
        rVideoConfig.frame_mode = play_struct->frame_mode;

        if (rVideoConfig.display_device == MED_DISPLAY_NONE)
        {
            rVideoConfig.fgRendererVisible = KAL_FALSE;
        }
        else
        {
            rVideoConfig.fgRendererVisible = KAL_TRUE;
        }
        mpl_session_set_render_param(self, &rVideoConfig);
    }
    return MED_S_OK;
}

/*****************************************************************************
* DESCRIPTION
*    Configure bypass mode of Renderer
*
*****************************************************************************/
static void mpl_session_set_render_bypass_in_running_state(mpl_session_struct *prSelf, kal_bool bypass)
{
    VIDEO_COMPONENT_TYPE_T *render_handle = prSelf->render_handle;

    if (prSelf->fgRendererError == KAL_FALSE)
    {
        _MPLVP_ChangeOneComponentState(prSelf, render_handle, VIDEO_STATE_STOP, MPL_SESSION_EG_RENDER_COMPLETE);

        _MPLVP_SetBypassModeOfRenderer(prSelf, bypass);

        if (MPL_STATE_PLAYING == prSelf->state)
        {
            _MPLVP_ConfigRenderer(prSelf, &prSelf->rPlayInfo);
        }

        /* if renderer is paused, keep it in stop state*/
        if (KAL_FALSE == prSelf->fgRendererPaused)
        {
            _MPLVP_ChangeOneComponentState(prSelf, render_handle, VIDEO_STATE_RUN, MPL_SESSION_EG_RENDER_COMPLETE);
        }
    }
}

/*****************************************************************************
* DESCRIPTION
*    Decide whether to flush all frame and do the seek.  It should be useful
*    for files coded as only one I in the very begining.
*
*    However we shut it now since the control was not well designed and has
*    too many potential issues
*
*****************************************************************************/
static media_error_t mpl_session_decide_seek_method(
                            mpl_session_struct *mpl,
                            kal_uint64 *pu8SeekTime,
                            kal_bool* fgUpdateTimeOnly)
{
    mpl_session_struct *self = mpl;

    /* Update time only == KAL_TRUE:
       1) streaming case
       2) seek time and current have the same I frame
    */

#ifdef __VE_STREAM_SUPPORT__
    /* For streaming scenario: only update seek time infomation */
    if (KAL_TRUE == _MPLVP_IsStreamMode(self->media_mode))
    {
        *fgUpdateTimeOnly = KAL_TRUE;
    }
    else
#endif
    {
    #if 1
        *fgUpdateTimeOnly = KAL_FALSE;
    #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    }

    return MED_S_OK;
}

/*****************************************************************************
* DESCRIPTION
*    Enable video clock of Scheduler through setting audio off.  Scheduler wo-
*    uld return video clock when MPL queries after.
*
*****************************************************************************/
static void _MPLVP_EnableVideoClock(mpl_session_struct *prSelf)
{
    kal_bool fgClock = KAL_FALSE;
    const VIDEO_COMPONENT_TYPE_T *prSchedulerComp = prSelf->scheduler_handle;

    _MPLVP_ConfigClock(prSelf, KAL_FALSE);
    prSchedulerComp->pfnSetParameter(VIDEO_PARAM_AUDIO_ON, &fgClock);
    _MPLVP_ConfigClock(prSelf, KAL_TRUE);
}

/*****************************************************************************
* DESCRIPTION
*    Check whether the file is 3D SBS from Source and Decoder
*
*****************************************************************************/
static void _MPLVP_Check3DSidebySide(mpl_session_struct *self)
{
#if defined(__VE_3D_SIDE_BY_SIDE__)
    if (MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]))
    {
        self->decoder_handle->pfnGetParameter(VIDEO_PARAM_GET_SBSFLAG, (void*)&self->fg3DSidebySide);
        if (KAL_FALSE == self->fg3DSidebySide)
        {
            self->source_handle->pfnGetParameter(self->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_3D_SBS, (void*)&self->fg3DSidebySide);
        }

        if (KAL_TRUE == self->fg3DSidebySide)
        {
            self->eVidQuality = VIDEO_DEC_MODE_BEST_QUALITY;
            self->decoder_handle->pfnSetParameter(VIDEO_PARAM_SET_DECODE_MODE, (void*)&self->eVidQuality);
        }
    }
#endif
}

/*****************************************************************************
* DESCRIPTION
*    The general event handler were seperated into one parts in DCM and the o-
*    ther outside DCM. This is the one in DCM.
*
*****************************************************************************/
static void _MPLVP_EventHdlrinDCM(mpl_session_struct *self)
{
    Media_Status eAudioRet;
    mpl_session_state_enum eState = self->state;
    MHdl *mhdl_handle = self->mhdl_handle;

    kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_EVENT_INTERNAL_HANDLE, eState,
                self->fgAudFinished,
                self->fgVidFinished,
                self->fgAudError,
                self->fgVidError,
                self->fgSubtitleError,
                self->fgAuidioBuffered,
                self->fgVideoBuffered
    );

    /* buffering handle */
    switch(eState)
    {
        case MPL_STATE_OPENING:
            /* Only happens in PGDL feature */
            if (self->fgVidError && self->fgAudError)
            {
                self->state = MPL_STATE_CLOSED;

                mpl_session_close_source(self);

                /* Notify MDI that open failed. */
                mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_OPEN, MED_E_FAIL);
            }
            break;
        case MPL_STATE_PRE_SEEKING:
            if (self->fgVidError == KAL_TRUE)
            {
                self->state = MPL_STATE_READY;
                mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_SEEK, MED_E_FAIL);
            }
            break;
        case MPL_STATE_SEEKING:
#ifdef __VE_STREAM_SUPPORT__
            // TODO: need to refinement
            /* Considerate audio bufferring status in stream case */
            if (KAL_TRUE == _MPLVP_IsStreamMode(self->media_mode) && MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO]))
            {
                if (!(self->fgAudFinished == KAL_TRUE || (self->fgAuidioBuffered == KAL_TRUE)))
                {
                    return;
                }
                else if (MPL_IS_STRM_INVALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]))
                {
                    /* there is no video, but audio is bufferred */
                    mpl_session_stop_internal(self);
                    mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_SEEK, MED_S_OK);
                    return;
                }
            }
#endif

            /* Error handle first*/
            if (self->fgVidFinished == KAL_TRUE || self->fgVidError == KAL_TRUE || (self->fgVideoBuffered == KAL_TRUE))
            {
                /* In seeking, if error and buffer done occurs, need to stop player directly */
                mpl_session_stop_internal(self);

                _MPLVP_Check3DSidebySide(self);

                if (self->fgVidError && MPL_IS_STRM_INVALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO]))
                {
                    self->fgVidError = KAL_FALSE;
                    mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_SEEK, MED_E_FAIL);
                }
                else /* if (self->fgVidFinished || MPL_IS_FLAG_SET(MPL_FLAG_IS_VID_BUFFERED)) */
                {
                    /* there is an audio stream, treat it as seek done */
                    /* seek done */
                    mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_SEEK, MED_S_OK);
                }
            }
            break;
        case MPL_STATE_PLAYING:
            /* check buffering condition */
            if (!self->fgBuffered)
            {
                /* In case that " not buffered", if there is error or finished event happened, consider it as buffered */
                if (self->fgVidError || self->fgVidFinished)
                {
                    self->fgVideoBuffered = KAL_TRUE;
                }

                if (self->fgAudError || self->fgAudFinished)
                {
                    self->fgAuidioBuffered = KAL_TRUE;
                }
            }

            /* callback track error to upper layer if there is audio stream and audio has no error */
            if (self->fgVidError && !self->fgAudError && MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO]))
            {
                if (KAL_FALSE == self->fgCallbackedVideoTrackError)
                {
                    self->fgCallbackedVideoTrackError = KAL_TRUE;
                    mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_PLAY, MED_E_VIDEO_TRACK_ERROR);
                }
            }
            else if (self->fgAudError && !self->fgVidError && MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]))
            {
                if (KAL_FALSE == self->fgCallbackedAudioTrackError)
                {
                    self->fgCallbackedAudioTrackError = KAL_TRUE;
                    mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_PLAY, MED_E_AUDIO_TRACK_ERROR);
                }
            }

#if defined(__VE_SUBTITLE_SUPPORT__)
            if (KAL_TRUE == self->fgSubtitleError)
            {
                media_error_t eErr;

                eErr = _MPLVP_ConfigPort(self, SOURCE_PROVIDER_PORT_SUBTITLE, KAL_FALSE);
                if (eErr != MED_S_OK)
                {
                    mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_PLAY, MED_E_FAIL);
                    return;
                }

                //if (_MPLVP_IS_ENABLE_SUBTITLE(self))
                {
                    VIDEO_COMPONENT_TYPE_T *prSubtitleHandle = self->prSubtitleDecoderHdlr;

                    _MPLVP_ChangeOneComponentState(self, prSubtitleHandle, VIDEO_STATE_STOP, MPL_SESSION_EG_SUBTITLEDECODER_COMPLETE);
                }
            }
#endif
            /* Error handle first*/
            if ((self->fgVidError && (MPL_IS_STRM_INVALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO]) || !self->play_audio)) ||
                (self->fgAudError && MPL_IS_STRM_INVALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO])) ||
                (self->fgVidError && self->fgAudError))
            {
                self->fgAudError = KAL_FALSE;
                self->fgVidError = KAL_FALSE;

                mpl_session_stop_internal(self);

                mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_PLAY, MED_E_FAIL);
                return;
            }
            /* Play finish */
            else if ((self->fgVidFinished && (MPL_IS_STRM_INVALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO]) || !self->play_audio)) ||
                     (self->fgAudFinished && MPL_IS_STRM_INVALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO])) ||
                     (self->fgVidFinished && self->fgAudFinished))
            {
                mpl_session_stop_internal(self);
                //if (0 == (self->afgSourceDelay[MPL_AUDIO_IDX] + self->afgSourceDelay[MPL_VIDEO_IDX] + self->afgSourceDelay[MPL_SUBTITLE_IDX]))
                if (((self->afgSourceDelay[MPL_VIDEO_IDX] == KAL_TRUE) && (MPL_IS_STRM_INVALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO]) || !self->play_audio)) ||
                     ((self->afgSourceDelay[MPL_AUDIO_IDX] == KAL_TRUE) && MPL_IS_STRM_INVALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO])) ||
                     ((self->afgSourceDelay[MPL_VIDEO_IDX] == KAL_TRUE) && (self->afgSourceDelay[MPL_AUDIO_IDX] == KAL_TRUE)))
                {
                    mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_PLAY, MED_E_FAIL);
                }
                else
                {
                    mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_PLAY, MED_S_PLAY_FINISH);                    
                }
            }
            /* Buffering */
            else if (((self->fgVideoBuffered == KAL_TRUE) && (MPL_IS_STRM_INVALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO]) || !self->play_audio)) ||
                     ((self->fgAuidioBuffered == KAL_TRUE) && MPL_IS_STRM_INVALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO])) ||
                     ((self->fgVideoBuffered == KAL_TRUE) && (self->fgAuidioBuffered == KAL_TRUE)))
            {
                if (!self->fgBuffered)
                {
                    self->fgBuffered = KAL_TRUE;

                    /* clean buffer status */
                    self->fgAuidioBuffered = KAL_FALSE;
                    self->fgVideoBuffered = KAL_FALSE;

                    /* Buffering done */

                    if (MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]))
                    {
                        mpl_session_start_avsync(self);
                    }

                    if (KAL_FALSE == self->fgAudError)
                    {
                        if (MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO])
                        && (1 == self->play_audio))
                        {
                            /* Start audio */
                        #if defined(__BTMTK__) && defined(__VE_BT_A2DP_SUPPORT__)
                            mpl_session_med_aud_func.pfn_aud_bt_a2dp_open_codec(self->aud_format);
                        #endif
                            eAudioRet = mhdl_handle->Play(mhdl_handle);
                            kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_CALL_AUD_PLAY, eAudioRet);

                            if (eAudioRet != MEDIA_SUCCESS)
                            {
                                if (eAudioRet == MEDIA_SEEK_EOF)
                                {
                                    mpl_session_audio_event_callback_from_mpl(self, MEDIA_END);
                                    self->fgAudFinished = KAL_TRUE;
                                }
                                else
                                {
                                    mpl_session_audio_event_callback_from_mpl(self, MEDIA_ERROR);
                                    self->fgAudError = KAL_TRUE;
                                }

                                if (MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]))
                                {
                                    _MPLVP_EnableVideoClock(self);
                                }
                            }
                        }
                    }
                    else
                    {
                        if (MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]))
                        {
                            _MPLVP_EnableVideoClock(self);
                        }
                    }
                }
            }
            break;
        default:
            break;
    }
}

/*****************************************************************************
* DESCRIPTION
*    The video event handler were seperated into one parts in DCM and the o-
*    ther outside DCM. This is the one in DCM.
*
*****************************************************************************/
static void _MPLVP_VideoEventHdlrinDCM(mpl_session_struct *self, kal_uint32 u4Event)
{
    kal_uint32 event = u4Event;
    mpl_session_evt_enum eVidEvent;
    mpl_session_state_enum eState;
    media_error_t eErr;
#ifdef __VE_STREAM_SUPPORT__
    VIDEO_ERROR_TYPE_T eError;
#endif

    eVidEvent = (mpl_session_evt_enum)event;
    eState = self->state;
    kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_VIDEO_EVENT, eState, eVidEvent);

    switch(eVidEvent)
    {
#ifdef __VE_STREAM_SUPPORT__
        case MPL_SESSION_EVT_STREAMING_RESEND_EOS:
            kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_NOTIFY_EOS_INTERNAL, self->eStreamingEOSPort, self->state);
            eError = SourceProviderStreamingAddEof(self->source_cntx, self->eStreamingEOSPort, 0);
            if (eError == VIDEO_ERROR_BUFF_FULL)
            {
                //MPL_ASSERT(0);
                kal_set_timer(self->rTimerID, (kal_timer_func_ptr)_mpl_session_live_resend_eos_hdlr, (void*)self,  (1000 * 7) >> 5, 0);
            }
            break;
#endif
        case MPL_SESSION_EVT_SOURCE_OPENED:
            eErr = mpl_session_init_source_comp_param(self);
            if (eErr != MED_S_OK)
            {
                /* open failed */
                mpl_session_close_source(self);
                mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_OPEN, MED_E_FAIL);
            }
            break;

        case MPL_SESSION_EVT_SOURCE_PRE_SEEK_DOME:
            if (self->state == MPL_STATE_PRE_SEEKING)
            {
                self->state = MPL_STATE_SEEKING;
                //self->rSeekInfo.time = self->rKeyTime.u8KeyFrameTime;
                eErr = mpl_session_seek_internal(self, &self->rSeekInfo);
                if (eErr == MED_S_ASYNC)
                {
                    return;
                }
                else if (eErr == MED_S_OK)
                {
                    self->fgVideoBuffered = KAL_TRUE;
                }
                else
                {
                    mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_SEEK, MED_E_FAIL);
                    return;
                }
            }
            break;

        case MPL_SESSION_EVT_CLOCK_EXPECTED_BUF_NUM_RDY:
            self->fgVideoBuffered = KAL_TRUE;
            break;

        case MPL_SESSION_EVT_SCHEDULER_COMPLETE:
            self->fgVidFinished = KAL_TRUE;
            break;

        case MPL_SESSION_EVT_SCHEDULER_RECOVER_JUMP_TO_I:
        case MPL_SESSION_EVT_SCHEDULER_RECOVER_STOP_AUDIO:
            {
#ifdef __VE_PGDL_SUPPORT__
                if (self->media_mode == MED_MODE_PDL_FILE)
                {
                    return;
                }
#endif
                if ((self->state == MPL_STATE_PLAYING)
                && (KAL_FALSE == self->fgVidFinished)
                && (KAL_FALSE == self->fgVidError)
                && (1 == self->play_audio))
                {
                    if (eVidEvent == MPL_SESSION_EVT_SCHEDULER_RECOVER_JUMP_TO_I)
                    {
                        eErr = mpl_session_av_jump(self);
                        if (eErr != MED_S_OK)
                        {
                            self->fgVidError = KAL_TRUE;
                            self->fgAudError = KAL_TRUE;
                        }
                    }
                    else if (MPL_SESSION_EVT_SCHEDULER_RECOVER_STOP_AUDIO)
                    {
                        mpl_session_av_resync(self);
                    }
                }
            }
            break;
        case MPL_SESSION_EVT_DECODER_COMPLETE:
            // TODO:
            break;

#if defined(__VE_STOPTIME_SUPPORT__)
        case MPL_SESSION_EVT_CLOCK_STOP:
            mpl_session_stop_internal(self);
            self->u8StopTime = MPL_SESSION_INVALID_TIME;
            mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_PLAY, MED_E_STOP_TIME_REACHED);
            break;
#endif
        case MPL_SESSION_EVT_SOURCE_ERROR:
			if (MPL_STATE_PRE_SEEKING == self->state)
			{
				self->fgVidError = KAL_TRUE;
			}
            break;
        case MPL_SESSION_EVT_RENDER_ERROR:
        case MPL_SESSION_EVT_DECODER_RESOLUTION_NOT_SUPPORT:
        case MPL_SESSION_EVT_SUBTITLEDECODER_ERROR:
            /* disable video port*/
            {
                eErr = _MPLVP_ConfigPort(self, SOURCE_PROVIDER_PORT_VIDEO, KAL_FALSE);
                if (eErr != MED_S_OK)
                {
                    mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_PLAY, MED_E_FAIL);
                    return;
                }
            }

            if ((eVidEvent == MPL_SESSION_EVT_RENDER_ERROR)
            && (self->fgVideoRunning == KAL_TRUE)
            && (self->fgRendererError == KAL_FALSE)
            )
            {
                mpl_session_set_render_bypass_in_running_state(self, KAL_TRUE);
                self->fgRendererError = KAL_TRUE;
            }

            self->fgVidError = KAL_TRUE;
            self->fgVidFinished = KAL_TRUE;
            break;
        case MPL_SESSION_EVT_GET_AUDIO_TIME_2_SCHDULER:
            if (KAL_FALSE == self->fgVidError)
            {
                VFC_GET_KEYFRAME_TIME_T rTmp;

                if (MED_S_OK == _MPLVP_GetJumpTimeofVideo(self, &rTmp.u8KeyframeTime))
                {
                    // Gets the time with ms from Provider, transform it to us to Scheduler
                    rTmp.u8KeyframeTime *= 1000;
                    rTmp.fgSuccess = KAL_TRUE;
                }
                else
                {
                    rTmp.fgSuccess = KAL_FALSE;
                }

                if (VIDEO_ERROR_NONE != self->scheduler_handle->pfnSetParameter(VIDEO_PARAM_JUMP_TIMESTAMP, &rTmp))
                {
                    ASSERT(0);
                }
            }
            break;
        case MPL_SESSION_EVT_DECODER_RETRY_FAILED:
            {
                self->fgVidError = KAL_TRUE;
            }
            break;
#if defined(__VE_PGDL_SUPPORT__)
        case MPL_SESSION_EVT_SOURCE_AUDIO_UNDERFLOW:
            {
                mpl_session_stop_internal(self);
                mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_PLAY, MED_E_PDL_AUDIO_UNDERFLOW);
            }
            break;
        case MPL_SESSION_EVT_SOURCE_VIDEO_UNDERFLOW:
            {
                mpl_session_stop_internal(self);
                mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_PLAY, MED_E_PDL_VIDEO_UNDERFLOW);
            }
            break;
#endif
        default:
            MPL_ASSERT(0);
            break;
    }

    mpl_session_event_hdlr_internal(self);
}

/*****************************************************************************
* DESCRIPTION
*    Send the event to MED to process, with the MPL instance dealing video
*
*****************************************************************************/
static void mpl_session_video_event_callback(mpl_session_evt_enum eEvent)
{
    _MPLVP_Send2VideoEventHdlr(_prVideoSession, eEvent);
}

/*****************************************************************************
* DESCRIPTION
*    The audio event handler were seperated into one parts in DCM and the o-
*    ther outside DCM. This is the one in DCM.
*
*****************************************************************************/
static void _MPLVP_AudioEventHdlrinDCM(mpl_session_struct *self, kal_uint8 u1Event)
{
    media_error_t eErr;
    Media_Event eAudEvent;
    MHdl *mhdl_handle;
    kal_uint32 event = u1Event;

    mhdl_handle = self->mhdl_handle;

    /*********************************************
     * Audio Handing
     *********************************************/
    if (self->fgMPLCallbacked == KAL_FALSE)
    {
        if (!mhdl_handle)
        {
            return;
        }

        eAudEvent = mhdl_handle->Process(mhdl_handle, (Media_Event)event);
        /* Ignore data request event in new design (W1144MP)*/
        if (eAudEvent == MEDIA_DATA_REQUEST)
        {
            return;
        }
    }
    else
    {
        eAudEvent = (Media_Event)event;
    }

    kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_AUDIO_EVENT, self->state, event, self->fgMPLCallbacked);

    /* reset flags */
    self->fgMPLCallbacked = KAL_FALSE;

    switch(eAudEvent)
    {
#if defined(__VE_STOPTIME_SUPPORT__)
        case MEDIA_STOP_TIME_UP:
            if (MPL_IS_STRM_INVALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]))
            {
                mpl_session_stop_internal(self);
                mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_PLAY, MED_E_STOP_TIME_REACHED);
            }
            break;
#endif
        case MEDIA_READY_TO_PLAY:
            self->fgAuidioBuffered = KAL_TRUE;
            break;
        case MEDIA_BUFFER_UNDERFLOW:
            // TODO: check return code

            if (self->fgAudioUnderflow == KAL_FALSE)
            {
                self->fgAudioUnderflow = KAL_TRUE;
#ifdef __VE_STREAM_SUPPORT__
                if (KAL_TRUE == _MPLVP_IsStreamMode(self->media_mode))
                {
                    mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_PLAY, MED_E_STREAM_BUFFER_UNDERFLOW);
                }
#endif

#ifdef __VE_PGDL_SUPPORT__
                if (self->media_mode == MED_MODE_PDL_FILE)
                {
                    mpl_session_stop_internal(self);
                    mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_PLAY, MED_E_PDL_AUDIO_UNDERFLOW);
                }
#endif
            }
            break;
        case MEDIA_END:
            self->fgAudFinished = KAL_TRUE;
            break;
        case MEDIA_ERROR:
        case MEDIA_DECODER_UNSUPPORT:

            /* disable audio port*/
            /* Don't need to stop audio, keep A/V sync running */
            eErr = _MPLVP_ConfigPort(self, SOURCE_PROVIDER_PORT_AUDIO, KAL_FALSE);
            if (eErr != MED_S_OK)
            {
                mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_PLAY, MED_E_FAIL);
            }

            self->fgAudError = KAL_TRUE;
            self->fgAudFinished = KAL_TRUE;
            break;
        case MEDIA_DATA_REQUEST:
        case MEDIA_NONE:
            break;
        default:
            MPL_ASSERT(0);
            break;
    }
    mpl_session_event_hdlr_internal(self);
}

static void mpl_session_audio_event_hdlr(void *param);
/*****************************************************************************
* DESCRIPTION
*    Audio callbacks and MPL passes the evet to MED to process accordingly
*
*****************************************************************************/
static void mpl_session_audio_event_callback(MHdl *handle, Media_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mpl_session_aud_event_ind_struct *ind_p = NULL;
    mpl_session_struct *self;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    handle->GetUserData(handle, (void **)&self);

    ind_p = (mpl_session_aud_event_ind_struct*)
        get_ctrl_buffer(sizeof(mpl_session_aud_event_ind_struct));

    ind_p->user_data = self;
    ind_p->event = event;
    ind_p->session_id = self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO];

    mpl_send_async_context_ilm(MOD_MED, mpl_session_audio_event_hdlr, (void*)ind_p);
}

/*****************************************************************************
* DESCRIPTION
*    MPL passes the event to MED to process accordingly
*
*****************************************************************************/
static void mpl_session_audio_event_callback_from_mpl(mpl_session_struct *self, Media_Event event)
{
    mpl_session_aud_event_ind_struct *ind_p = NULL;


    self->fgMPLCallbacked = KAL_TRUE;

    ind_p = (mpl_session_aud_event_ind_struct*)
        get_ctrl_buffer(sizeof(mpl_session_aud_event_ind_struct));

    ind_p->user_data = self;
    ind_p->event = event;
    ind_p->session_id = self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO];

    mpl_send_async_context_ilm(MOD_MED, mpl_session_audio_event_hdlr, (void*)ind_p);
}

/*****************************************************************************
* DESCRIPTION
*    MDI calls this function to open MPL.
*    - Besides PGDL MDI_VIDEO would use this function asynchronously, others
*      do synchronously such as MDI_AUDIO and MDI_STREAMING.
*    - Under streaming mode, MPL would not initialise source and other compon-
*      here; otherwise MPL does.
*
*****************************************************************************/
static media_error_t mpl_session_open(
                            mpl_player_t* mpl,
                            mpl_player_open_t* open_struct)
{
    mpl_session_struct *self = SELF(mpl, mpl_session_struct, mpl);
    media_error_t eRet = MED_S_OK;

    kal_trace(TRACE_FUNC, MPLVP_OPEN, (mpl_scenario_enum)open_struct->scenario_id, self);

    if (self->state != MPL_STATE_CLOSED)
    {
        eRet = MED_E_WRONG_STATE;
        goto OPEN_EXIT;
    }

    self->rOpenInfo = *open_struct;
    self->rFontEngineApi = *(open_struct->rExternalAPI.prFontEngineApi);
    self->pfnIsLCCSupported = open_struct->rExternalAPI.pfnIsLCCSupported;

    self->fgCloseAudBTA2DPforOpen = self->rOpenInfo.fgCloseAudBTA2DPforOpen;

    /* Assign scenario */
    self->media_scenario = (mpl_scenario_enum)open_struct->scenario_id;
    self->media_mode = (med_mode_enum)open_struct->media_mode;
    self->media_type = (med_type_enum) open_struct->media_type;

    /* make array mode equal to buffer mode */
    if (self->media_mode == MED_MODE_ARRAY)
    {
        self->rOpenInfo.media_mode = self->media_mode = MED_MODE_BUFFER;
    }

    if (self->media_mode != MED_MODE_ARRAY && self->media_mode != MED_MODE_BUFFER)
    {
        self->rOpenInfo.data_size = kal_wstrlen(open_struct->data);
    }


#ifdef __VE_STREAM_SUPPORT__
    /* For streaming scenario: open source component in live prepare function */
    if (KAL_TRUE == _MPLVP_IsStreamMode(open_struct->media_mode))
    {
		self->eVidQuality = VIDEO_DEC_MODE_BEST_QUALITY;
        return MED_S_OK;
    }
#endif

    /* Open source component first */
    eRet = mpl_session_init_source_comp(self, &self->rOpenInfo);
    if (eRet != MED_S_OK)
    {
        goto OPEN_EXIT;
    }

#ifdef __VE_PGDL_SUPPORT__
    /* For streaming scenario: open source component in live prepare function */
    if (open_struct->media_mode == MED_MODE_PDL_FILE)
    {
        self->state = MPL_STATE_OPENING;
        eRet = MED_S_ASYNC;
        goto OPEN_EXIT;
    }
    else
#endif
    {
        /* Wait until the init operation is done */
        eRet = mpl_session_wait_source_change_state(self);
        if (eRet != MED_S_OK)
        {
            mpl_session_close_source(self);
            goto OPEN_EXIT;
        }

        self->state = MPL_STATE_READY;
    }

    eRet = mpl_session_init_source_comp_param(self);
    if (eRet != MED_S_OK)
    {
        /* Open video path failed */
        /* Close source*/
        mpl_session_close_source(self);
        goto OPEN_EXIT;
    }

OPEN_EXIT:
    kal_trace(TRACE_FUNC, MPLVP_OPEN_END, eRet, self);
    return eRet;
}

/*****************************************************************************
* DESCRIPTION
*    This is the internal implementation of seeking function.  We seeks for v-
*    ideo only.  Subtitle and audio do not require to do seeking.
*    Note that there was an acceleration for IPPP files but it is turned off
*    now and needs better design than it was. (mpl_session_decide_seek_method)
*
*****************************************************************************/
static media_error_t mpl_session_seek_internal(
                            mpl_session_struct *self,
                            mpl_player_seek_t* seek_struct)
{
    media_error_t eErr;
    kal_uint64 u8ClockTime, u8AlignedAudioFrameTime;
    VIDEO_COMPONENT_TYPE_T *scheduler_handle = self->scheduler_handle;
    kal_bool fgUpdateTimeOnly;

    kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_SEEK_INTERNAL, self->state, seek_struct->time, seek_struct->seek_track);

    /* Note: Local playback seek does not need audio frame */
    /* Align seek time to audio frame time */
    /* This is a must because MMI will update time bar after seek() by calling get play time */
    /* If it is not sync to play() function, the time bar will jump back. */
    if (MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO]))
    {
        eErr = mpl_session_get_key_frame_time(self, SOURCE_PROVIDER_PORT_AUDIO, &seek_struct->time, &u8AlignedAudioFrameTime);
        if (eErr != MED_S_OK)
        {
            self->fgAudError = KAL_TRUE;
            u8AlignedAudioFrameTime = seek_struct->time;
        }
    }
    else
    {
        //self->current_time = seek_struct->time;
        u8AlignedAudioFrameTime = seek_struct->time;
    }

#ifdef __VE_STREAM_SUPPORT__
    /* Initialize LastTime info which is used in streaming source */
    self->u8AudLastTime = u8AlignedAudioFrameTime;
#endif

    /* Seek enhancement: */
    /* If there is no video stream, return seek done directly */
    /* If seek to the current time, return seek done directly */
    if (MPL_IS_STRM_INVALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]))
    {
        /* Assign to current time */
        //self->current_time = u8AlignedAudioFrameTime;
#ifdef __VE_STREAM_SUPPORT__
        /* Before returning, check audio status */
        /* if there is an audio stream, need to wait for audio bufferring in streaming case. */
        if (KAL_TRUE == _MPLVP_IsStreamMode(self->media_mode)
        && MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO]))
        {
            self->state = MPL_STATE_SEEKING;
            return MED_S_ASYNC;
        }
#endif
        return MED_S_OK;
    }

    /* Initialize flag */
    mpl_session_reset_flag(self);

    /******************************
     * Decide seek method
     ******************************/
    mpl_session_decide_seek_method(self, &u8AlignedAudioFrameTime, &fgUpdateTimeOnly);
    /* After seek mothed decided, update current time to seek time */
    //self->current_time = u8AlignedAudioFrameTime;

    /* Reset components */
    if (KAL_FALSE == fgUpdateTimeOnly)
    {
        /* temp solution */

        eErr = _MPLVP_ChangeSourceState(self, VIDEO_STATE_IDLE);
        if (eErr != MED_S_OK)
        {
            return eErr;
        }

        _MPLVP_ChangeComponentState(self, VIDEO_STATE_IDLE, KAL_TRUE);

        eErr = mpl_session_init_video_comp_param(self);
        if (eErr != MED_S_OK)
        {
            return MED_E_FAIL;
        }
    }

    /******************************
     * Begin seeking
     ******************************/
     if (1 == seek_struct->stop_on_decode_errors)
     {
        const kal_uint32 u4RetryNumber = 10;
        self->decoder_handle->pfnSetParameter(VIDEO_PARAM_HEADER_RETRY, (void*)&u4RetryNumber);
     }

    /* set seek time to scheduler */
    u8ClockTime = MPL_SESSION_TIME_TO_COMPTIME(self->current_time);
    scheduler_handle->pfnSetParameter(VIDEO_PARAM_AV_TIMEBASE, &u8ClockTime);
    scheduler_handle->pfnSetParameter(VIDEO_PARAM_START_TIME, &u8ClockTime);

    /* set seek time to decoder for KMV speed-up */
	self->decoder_handle->pfnSetParameter(VIDEO_PARAM_SET_START_TIME, &u8ClockTime);

    /* set renderer to bypass mode */
    _MPLVP_SetBypassModeOfRenderer(self, KAL_TRUE);

    _MPLVP_ChangeComponentState(self, VIDEO_STATE_RUN, KAL_FALSE);

#ifdef __VE_STREAM_SUPPORT__
    /* For streaming scenario: also set seek time to source component here
       This is due to audio bitstream data is delivered into source component before play()
       If we set audio seek time in play(), the received audio bitstream data will be flushed.
       PS: In play() function, don't need to set audio seek time while streming scenario.
    */
    if (KAL_TRUE == _MPLVP_IsStreamMode(self->media_mode))
    {
        eErr = mpl_session_set_seek_time(self, SOURCE_PROVIDER_PORT_AUDIO, &u8AlignedAudioFrameTime, KAL_TRUE);
        if (eErr != MED_S_OK)
        {
            return MED_E_FAIL;
        }
    }
#endif

    // source: video port seek
    eErr = mpl_session_seek_video_path(self, u8AlignedAudioFrameTime, fgUpdateTimeOnly);
    if (eErr != MED_S_OK)
    {
        /* Error hanlde stop video path */
        mpl_session_stop_video(self);
        self->fgVidError = KAL_TRUE;
        self->fgVidFinished = KAL_TRUE;
        return MED_S_OK;
    }

#if defined(__VE_SUBTITLE_SUPPORT__)
    if (_MPLVP_IS_ENABLE_SUBTITLE(self))
    {
        eErr = _MPLVP_SeekSubtitle(self, u8AlignedAudioFrameTime);
        if (eErr != MED_S_OK)
        {
            return MED_E_FAIL;
        }
    }
#endif

    eErr = _MPLVP_ChangeSourceState(self, VIDEO_STATE_RUN);
    if (eErr != MED_S_OK)
    {
        mpl_session_stop_video(self);
        return MED_E_FAIL;
    }

    self->fgForceSeeking = KAL_TRUE;
    self->state = MPL_STATE_SEEKING;

    return MED_S_ASYNC;
}

/*****************************************************************************
* DESCRIPTION
*    The interface of seeking API for MDI.
*    Note that under some condition the seeking would be done in blocking way
*    for backward compatibility.
*    For the APP calls blocking seeking are suggested to turn stop_on_decode_-
*    errors so it would not be blocked too long due to decoding errors.
*
*****************************************************************************/
static media_error_t mpl_session_seek(
                            mpl_player_t* mpl,
                            mpl_player_seek_t* seek_struct)
{
    mpl_session_struct *self = SELF(mpl, mpl_session_struct, mpl);
    media_error_t eRet = MED_S_OK;

    kal_trace(TRACE_FUNC, MPLVP_SEEK, self->state, seek_struct->time, seek_struct->seek_track, seek_struct->stop_on_decode_errors ,self);
    if (self->state != MPL_STATE_READY)
    {
        eRet = MED_E_WRONG_STATE;
        goto SEEK_EXIT;
    }

    self->rSeekInfo = *seek_struct;
    self->current_time = seek_struct->time;

    /* Note: Local playback seek does not need audio frame */

    /* Align seek time to audio frame time */
    /* This is a must because MMI will update time bar after seek() by calling get play time */
    /* If it is not sync to play() function, the time bar will jump back. */
    if ((self->media_mode == MED_MODE_FILE )
        && (self->rOpenInfo.open_track != MED_VID_AUDIO_ONLY)
        && (KAL_FALSE == seek_struct->stop_on_decode_errors)
        && (seek_struct->time != 0))
    {
        self->state = MPL_STATE_PRE_SEEKING;
        if (MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO]))
        {
            eRet = mpl_session_get_key_frame_time_async(self, SOURCE_PROVIDER_PORT_AUDIO, &seek_struct->time);
            goto SEEK_EXIT;
        }
        else if (MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]))
        {
            eRet = mpl_session_get_key_frame_time_async(self, SOURCE_PROVIDER_PORT_VIDEO, &seek_struct->time);
            goto SEEK_EXIT;
        }
    }

    eRet = mpl_session_seek_internal(self, &self->rSeekInfo);

SEEK_EXIT:
    kal_trace(TRACE_FUNC, MPLVP_SEEK_END, eRet, self);
    return eRet;
}

/*****************************************************************************
* DESCRIPTION
*    Command Source to abort current jobs of a specific port
*
*****************************************************************************/
static void _MPLVP_Waiting4Abort(mpl_session_struct *prSelf,SP_PORT_TYPE_T ePortType)
{
    SPIF_PORT_INFO_T rTmp;
    VIDEO_COMPONENT_MI_TYPE_T *prSourceComp = prSelf->source_handle;
    kal_uint32 u4EventGroup = 0;

    kal_mem_set(&rTmp, 0, sizeof(rTmp));
    rTmp.eType = ePortType;
    prSourceComp->pfnGetParameter(prSelf->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_PORT_INFO, (void*)&rTmp);

    if (rTmp.u4ControlFlag != 0)
    {
        prSourceComp->pfnSetParameter(prSelf->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_ABORT_PROCESS, &ePortType);
    }

    if (rTmp.u4ControlFlag & SOURCE_PROVIDER_FLAG_OUTPUT_PORT)
    {
        kal_retrieve_eg_events(prSelf->rEventID,
                                (MPL_SESSION_EG_SOURCE_PORT_DONE | MPL_SESSION_EG_SOURCE_ERROR),
                                KAL_OR_CONSUME,
                                &u4EventGroup,
                                KAL_SUSPEND);
    }
    if (rTmp.u4ControlFlag & SOURCE_PROVIDER_FLAG_SEEK_TIME)
    {
        kal_retrieve_eg_events(prSelf->rEventID,
                                (MPL_SESSION_EG_SOURCE_SEEK_TIME_DONE | MPL_SESSION_EG_SOURCE_ERROR),
                                KAL_OR_CONSUME,
                                &u4EventGroup,
                                KAL_SUSPEND);
    }
    if (rTmp.u4ControlFlag &  SOURCE_PROVIDER_FLAG_GET_KEY_FRAME_TIME)
    {
        kal_retrieve_eg_events(prSelf->rEventID,
                                (MPL_SESSION_EG_SOURCE_KEY_FRAME_DONE | MPL_SESSION_EG_SOURCE_ERROR),
                                KAL_OR_CONSUME,
                                &u4EventGroup,
                                KAL_SUSPEND);
    }
}

/*****************************************************************************
* DESCRIPTION
*    The interface to stop seeking for MDI.
*
*    This function commands all component to stop and returns.  Note that aud-
*    io driver are closed here.
*
*****************************************************************************/
static media_error_t mpl_session_stop_seek(mpl_player_t* mpl)
{
    mpl_session_struct *self = SELF(mpl, mpl_session_struct, mpl);
    media_error_t eRet = MED_S_OK;

    kal_trace(TRACE_FUNC, MPLVP_STOP_SEEK, self->state, self);
    if (self->state != MPL_STATE_SEEKING && self->state != MPL_STATE_PRE_SEEKING)
    {
        eRet = MED_E_WRONG_STATE;
        goto STOP_SEEK_END;
    }

    kal_take_mutex(self->rMutexID);
    if ((self->media_mode == MED_MODE_FILE)
    && (self->state == MPL_STATE_PRE_SEEKING))
    {
        self->state = MPL_STATE_READY;

        kal_give_mutex(self->rMutexID);

        _MPLVP_Waiting4Abort(self, SOURCE_PROVIDER_PORT_AUDIO);
        _MPLVP_Waiting4Abort(self, SOURCE_PROVIDER_PORT_VIDEO);
#if defined(__VE_SUBTITLE_SUPPORT__)
        _MPLVP_Waiting4Abort(self, SOURCE_PROVIDER_PORT_SUBTITLE);
#endif
    }
    else
    {
        kal_give_mutex(self->rMutexID);
    }

    mpl_session_stop_internal(self);

STOP_SEEK_END:
    kal_trace(TRACE_FUNC, MPLVP_STOP_SEEK_END, eRet, self);
    return eRet;
}

/*****************************************************************************
* DESCRIPTION
*    Internal implementation of playing function
*    - Turning on audio/video/subtitle ports of Source to make data flowing.
*    - Initailize audio driver
*    - Before leaving this function, Renderer has to be set to RUN state at
*      least once to trigger LCD
*
*****************************************************************************/
static media_error_t mpl_session_play_internal(mpl_session_struct *self, kal_bool close_bt_codec)
{
    kal_uint64 u8AudioTime, u8ClockTime;
    kal_bool fgAudioEnable;
    media_error_t eErr;
    VIDEO_COMPONENT_TYPE_T *scheduler_handle = self->scheduler_handle;
    VIDEO_COMPONENT_TYPE_T *render_handle = self->render_handle;

    kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_PLAY_INTERNAL, self->state);

    /* Initialize flag */
    _MPLVP_Reset_Flags(self);

    _MPLVP_ConfigRenderer(self, &self->rPlayInfo);

    // TODO: play speed setting, ask about WN

#ifdef __VE_BES_TS_SUPPORT__
    self->play_speed = mpl_session_get_accurate_play_speed(self, self->play_speed);
    if ((self->play_speed <= 160)
     && (self->play_speed >= 50)
     && AudioPP_TS_IsSupport(self->aud_format, NULL))
    {
        self->fgSupportTimeStretch = KAL_TRUE;
    }
    else
    {
        self->fgSupportTimeStretch = KAL_FALSE;
    }

    kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_VAL, self->fgSupportTimeStretch, __LINE__);
#endif /* __VE_BES_TS_SUPPORT__ */


    /* BT codec */
#if defined(__BTMTK__) && defined(__VE_BT_A2DP_SUPPORT__)
    if (((KAL_TRUE == close_bt_codec) && (1 == self->play_audio))
    || (KAL_TRUE == self->fgCloseAudBTA2DPforOpen))
    {
        mpl_session_med_aud_func.pfn_aud_bt_a2dp_close_codec_for_open();
        self->fgCloseAudBTA2DPforOpen = KAL_FALSE;
    }
#endif /* defined(__BTMTK__) && defined(__VE_BT_A2DP_SUPPORT__) */


    /* Cofing Audio */
    if (MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO]))
    {
        if (!(self->play_speed == 100 || (self->fgSupportTimeStretch == KAL_TRUE)))
        {
            kal_trace(TRACE_FUNC, MPLVP_FAILED_2_PLAY_FOR_PLAYSPEED, self->play_speed);
            return MED_E_FAIL;
        }

        /* Pure-Audio, must play audio stream */
        if (!self->play_audio && MPL_IS_STRM_INVALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]))
        {
            return MED_E_FAIL;
        }

        if (0 != self->play_audio)
        {
            /* Get audio frame start time */
            eErr = mpl_session_get_key_frame_time(self, SOURCE_PROVIDER_PORT_AUDIO, &self->current_time, &u8AudioTime);
            if (eErr != MED_S_OK)
            {
                self->fgAudError = KAL_TRUE;
                self->fgAudFinished = KAL_TRUE;
            }

            /* For streaming scenario: also set seek time to source component here
               This is due to audio bitstream data is delivered into source component before play()
               If we set audio seek time in play(), the received audio bitstream data will be flushed.
               PS: In seek() function, need to set audio seek time while streming scenario.
            */
            if (KAL_FALSE == self->fgAudError)
            {
                if (KAL_FALSE == _MPLVP_IsStreamMode(self->media_mode))
                {
                    eErr = mpl_session_set_seek_time(self, SOURCE_PROVIDER_PORT_AUDIO, &self->current_time, KAL_FALSE);
                    if (eErr != MED_S_OK)
                    {
                        return MED_E_FAIL;
                    }
                }

                eErr = _MPLVP_ConfigPort(self, SOURCE_PROVIDER_PORT_AUDIO, KAL_TRUE);
                if (eErr != MED_S_OK)
                {
                    return MED_E_FAIL;
                }

                mpl_session_med_aud_func.pfn_aud_get_active_device_path_by_mode(self->audio_path, mpl_session_med_aud_func.pfn_aud_melody_set_output_device);
                if (MED_E_FAIL == mpl_session_init_audio(self))
                {
                    self->fgAudError = KAL_TRUE;
                    self->fgAudFinished = KAL_TRUE;
                }
            }
        }

    }
    else
    {
        self->play_audio = 0;
    }

    /* Config video */
    if (MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]))
    {
#if defined(__VE_SUBTITLE_SUPPORT__)
        VIDEO_BUFFERHEADER_TYPE_T rSubtitleBufferHeader;
#endif

        /* dont' need to set video seek time to source again. */
        eErr = _MPLVP_ConfigPort(self, SOURCE_PROVIDER_PORT_VIDEO, KAL_TRUE);
        if (eErr != MED_S_OK)
        {
            return MED_E_FAIL;
        }

        {
            SPIF_PORT_INFO_T rTmp;
            VIDEO_COMPONENT_MI_TYPE_T *prSourceComp = self->source_handle;

            kal_mem_set(&rTmp, 0, sizeof(rTmp));
            rTmp.eType = SOURCE_PROVIDER_PORT_VIDEO;
            prSourceComp->pfnGetParameter(self->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_PORT_INFO, (void*)&rTmp);

            if (KAL_TRUE == rTmp.fgParserError)
            {
                self->fgVidError = KAL_TRUE;
                if (MPL_IS_STRM_INVALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO]))
                {
                    return MED_E_FAIL;
                }
            }
        }

        /* Set audio start time to clock */
        u8ClockTime = MPL_SESSION_TIME_TO_COMPTIME(self->current_time);
        scheduler_handle->pfnSetParameter(VIDEO_PARAM_AV_TIMEBASE, &u8ClockTime);
        if (self->fgSeekable)
        {
            scheduler_handle->pfnSetParameter(VIDEO_PARAM_START_TIME, &u8ClockTime);
        }
#if defined(__VE_STOPTIME_SUPPORT__)
        u8ClockTime = MPL_SESSION_TIME_TO_COMPTIME(self->u8StopTime);
        scheduler_handle->pfnSetParameter(VIDEO_PARAM_STOP_TIME, &u8ClockTime);
#endif

        fgAudioEnable = (self->play_audio && (MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO])))? KAL_TRUE : KAL_FALSE;
        scheduler_handle->pfnSetParameter(VIDEO_PARAM_AUDIO_ON, &fgAudioEnable);
        scheduler_handle->pfnSetParameter(VIDEO_PARAM_PLAY_SPEED, &self->play_speed);

#if defined(__VE_SUBTITLE_SUPPORT__)
        //Flush subtitle before switching Renderer to RUN to avoid renderering old subtitles when switching normal/full screen
        if (_MPLVP_IS_ENABLE_SUBTITLE(self))
        {
            if (KAL_TRUE == self->fgFlushSubtitle)
            {
                kal_uint32 u4Tmp = 1; //means flush subtitle data only; 0 would include video

                render_handle->pfnGetParameter(VIDEO_PARAM_RENDERER_SUBTITLE_CURRENT_BUFFER_HEADER, (void*)&rSubtitleBufferHeader);
                render_handle->pfnSetParameter(VIDEO_PARAM_RENDERER_PORT_FLUSH, (void*)&u4Tmp);
            }
        }
#endif

        //Make sure lcd is updated successfully by Renderer
        _MPLVP_SetBypassModeOfRenderer(self, KAL_FALSE);
        _MPLVP_ChangeOneComponentState(self, render_handle, VIDEO_STATE_RUN, MPL_SESSION_EG_RENDER_COMPLETE);
        _MPLVP_ChangeOneComponentState(self, render_handle, VIDEO_STATE_STOP, MPL_SESSION_EG_RENDER_COMPLETE);
        _MPLVP_ConfigRenderer(self, &self->rPlayInfo);
        _MPLVP_SetBypassModeOfRenderer(self, KAL_TRUE);
        //

#if defined(__VE_SUBTITLE_SUPPORT__)
        if (_MPLVP_IS_ENABLE_SUBTITLE(self))
        {
        	if (KAL_TRUE == self->fgFlushSubtitle)
        	{
                VIDEO_PORT_TYPE_T eFlushType = VIDEO_PORT_SUBTITLE;
                kal_uint64 u8SubtitleTime = 0;
                VIDEO_COMPONENT_TYPE_T *prSubtitleHandle = self->prSubtitleDecoderHdlr;

                scheduler_handle->pfnSetParameter(VIDEO_PARAM_RESET_QUEUE, (void*)&eFlushType);

                u8SubtitleTime = rSubtitleBufferHeader.u8TimeStamp;
                prSubtitleHandle->pfnSetParameter(VIDEO_PARAM_VSD_PARTIAL_RESET, &u8SubtitleTime);
                self->fgFlushSubtitle = KAL_FALSE;
            }
            _MPLVP_SetupSubtitleDecoder(self, &self->rPlayInfo);
        }
#endif

        _MPLVP_ChangeComponentState(self, VIDEO_STATE_RUN, KAL_TRUE);

        /* Set flag: lcd was upated by renderer and make sure that trigger lcd is true, bypass is false*/
        self->fgLCDTriggered = KAL_TRUE;

    }

#if defined(__VE_SUBTITLE_SUPPORT__)
    if (_MPLVP_IS_ENABLE_SUBTITLE(self)
    && (self->rPlayInfo.subtitle_image_buffer_p != NULL))
	{
	    eErr = _MPLVP_ConfigPort(self, SOURCE_PROVIDER_PORT_SUBTITLE, KAL_TRUE);
	    if (eErr != MED_S_OK)
	    {
	        return MED_E_FAIL;
	    }
	}
#endif

    eErr = _MPLVP_ChangeSourceState(self, VIDEO_STATE_RUN);
    if (eErr != MED_S_OK)
    {
        return MED_E_FAIL;
    }

    if ((KAL_TRUE == self->fgAudError)
    && (KAL_TRUE == self->fgVidError))
    {
    	  return MED_E_FAIL;
    }
    else
    {
        self->state = MPL_STATE_PLAYING;
        return MED_S_OK;
    }
}

/*****************************************************************************
* DESCRIPTION
*    The interface of playing for MDI.
*
*    Calling internal function to play and stop automatically when finding er-
*    rors
*
*****************************************************************************/
static media_error_t mpl_session_play(
                            mpl_player_t* mpl,
                            mpl_player_play_t* play_struct)
{
    mpl_session_struct *self = SELF(mpl, mpl_session_struct, mpl);
    media_error_t eRet = MED_S_OK;

    kal_trace(TRACE_FUNC, MPLVP_PLAY, self->state, play_struct->play_audio, self);

    if (self->state != MPL_STATE_READY)
    {
        eRet = MED_E_WRONG_STATE;
        goto PLAY_END;
    }

    /* Set video parameter to player */
    if ((self->rPlayInfo.subtitle_width != play_struct->subtitle_width)
    ||(self->rPlayInfo.subtitle_height != play_struct->subtitle_height))
    {
    	self->fgFlushSubtitle = KAL_TRUE;
    }

    self->rPlayInfo = *play_struct;

    /* Set audio parameter to player */
    self->play_audio = play_struct->play_audio;
    self->audio_path = play_struct->audio_path;
    self->play_speed = play_struct->play_speed;

    eRet = mpl_session_play_internal(self, KAL_FALSE);
    if (eRet != MED_S_OK)
    {
        mpl_session_stop_internal(self);
    }

PLAY_END:
    kal_trace(TRACE_FUNC, MPLVP_PLAY_END, eRet, self);
    return eRet;
}


/*****************************************************************************
* DESCRIPTION
*    The interface for stopping playing for MDI.
*
*    Calling internal function to command all components to STOP and close au-
*    dio driver.
*
*****************************************************************************/
static media_error_t mpl_session_stop_play(mpl_player_t* mpl)
{
    mpl_session_struct *self = SELF(mpl, mpl_session_struct, mpl);
    media_error_t eRet = MED_S_OK;

    kal_trace(TRACE_FUNC, MPLVP_STOP_PLAY, self->state, self);
    if (self->state != MPL_STATE_PLAYING)
    {
        eRet = MED_E_WRONG_STATE;
        goto STOP_PLAY_END;
    }

    mpl_session_stop_internal(self);

STOP_PLAY_END:
    kal_trace(TRACE_FUNC, MPLVP_STOP_PLAY_END, eRet, self);
    return eRet;
}


/*****************************************************************************
* DESCRIPTION
*    The interface for pausing updating video screen for MDI.
*
*    This function commands Renderer to STOP state so that it would no update
*    video screen anymore.
*
*****************************************************************************/
static media_error_t mpl_session_pause_visual_update(mpl_player_t* mpl)
{
    mpl_session_struct *self = SELF(mpl, mpl_session_struct, mpl);
    VIDEO_COMPONENT_TYPE_T *render_handle = self->render_handle;
    media_error_t eRet = MED_S_OK;

    kal_trace(TRACE_FUNC, MPLVP_PAUSE_VISUAL, self->state, self->fgVidError, self);

    if (self->state != MPL_STATE_PLAYING ||MPL_IS_STRM_INVALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]))
    {
        eRet = MED_S_FALSE;
        goto PAUSE_VISUAL_EXIT;
    }

    /* Change render state to stop */
    if (self->fgVideoRunning == KAL_TRUE)
    {
        self->fgRendererPaused = KAL_TRUE;
        _MPLVP_ChangeOneComponentState(self, render_handle, VIDEO_STATE_STOP, MPL_SESSION_EG_RENDER_COMPLETE);
    }

PAUSE_VISUAL_EXIT:
    kal_trace(TRACE_FUNC, MPLVP_PAUSE_VISUAL_END, eRet, self);
    return eRet;
}


/*****************************************************************************
* DESCRIPTION
*    The interface to resuming updating video screen for MDI.
*
*    This function resumes Renderer and sets new parameters according to MDI.
*    On the other hand subtitle path needs to be reset since the renderering
*    parameters may be changed by MDI.
*    Due to the video/subtitle path are drawed by different modules (renderer/
*    subtitle decoder), the two pathes are handled in different ways
*
*****************************************************************************/
static media_error_t mpl_session_resume_visual_update(mpl_player_t* mpl, mpl_player_play_t* prPlayStruct)
{
    mpl_session_struct *self = SELF(mpl, mpl_session_struct, mpl);
    VIDEO_COMPONENT_TYPE_T *render_handle = self->render_handle;
    media_error_t eRet = MED_S_OK;

    kal_trace(TRACE_FUNC, MPLVP_RESUME_VISUAL, self->state, (med_frame_enum)prPlayStruct->frame_mode, self);
    if (self->state != MPL_STATE_PLAYING
    || MPL_IS_STRM_INVALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]))
    {
        eRet = MED_S_FALSE;
        goto RESUME_VISUAL_EXIT;
    }

    self->fgRendererError = KAL_FALSE;
    if ((self->rPlayInfo.subtitle_width != prPlayStruct->subtitle_width)
    ||(self->rPlayInfo.subtitle_height != prPlayStruct->subtitle_height))
    {
    	self->fgFlushSubtitle = KAL_TRUE;
    }
    self->rPlayInfo = *prPlayStruct;
    _MPLVP_ConfigRenderer(self, &self->rPlayInfo);

    {
        kal_bool fgBypass = self->fgRendererError;
        _MPLVP_SetBypassModeOfRenderer(self, fgBypass);
    }

#if defined(__VE_SUBTITLE_SUPPORT__)
    if (_MPLVP_IS_ENABLE_SUBTITLE(self))
    {
        VIDEO_COMPONENT_TYPE_T *scheduler_handle = self->scheduler_handle;
        VIDEO_COMPONENT_TYPE_T *render_handle = self->render_handle;
        VIDEO_COMPONENT_TYPE_T *prSubtitleHandle = self->prSubtitleDecoderHdlr;
        kal_uint64 u8SubtitleTime = 0;
        VIDEO_BUFFERHEADER_TYPE_T rSubtitleBufferHeader;
        kal_uint32 u4Tmp = 1; //means flush subtitle data only; 0 would include video
        VIDEO_PORT_TYPE_T eFlushType = VIDEO_PORT_SUBTITLE;

        if (KAL_TRUE == self->fgFlushSubtitle)
        {
            _MPLVP_ChangeOneComponentState(self, prSubtitleHandle, VIDEO_STATE_STOP, MPL_SESSION_EG_SUBTITLEDECODER_COMPLETE);

            render_handle->pfnGetParameter(VIDEO_PARAM_RENDERER_SUBTITLE_CURRENT_BUFFER_HEADER, (void*)&rSubtitleBufferHeader);
            render_handle->pfnSetParameter(VIDEO_PARAM_RENDERER_PORT_FLUSH, (void*)&u4Tmp);
            scheduler_handle->pfnSetParameter(VIDEO_PARAM_RESET_QUEUE, (void*)&eFlushType);

            {
                u8SubtitleTime = rSubtitleBufferHeader.u8TimeStamp;
                prSubtitleHandle->pfnSetParameter(VIDEO_PARAM_VSD_PARTIAL_RESET, &u8SubtitleTime);
                _MPLVP_SetupSubtitleDecoder(self, prPlayStruct);
            }

            _MPLVP_ChangeOneComponentState(self, render_handle, VIDEO_STATE_RUN, MPL_SESSION_EG_RENDER_COMPLETE);

            _MPLVP_ChangeOneComponentState(self, prSubtitleHandle, VIDEO_STATE_RUN, MPL_SESSION_EG_SUBTITLEDECODER_COMPLETE);

            self->fgFlushSubtitle = KAL_FALSE;
        }
        else
       	{
       		_MPLVP_ChangeOneComponentState(self, render_handle, VIDEO_STATE_RUN, MPL_SESSION_EG_RENDER_COMPLETE);
       	}
    }
    else
#endif
    {
        _MPLVP_ChangeOneComponentState(self, render_handle, VIDEO_STATE_RUN, MPL_SESSION_EG_RENDER_COMPLETE);
    }

RESUME_VISUAL_EXIT:
    self->fgRendererPaused = KAL_FALSE;
    kal_trace(TRACE_FUNC, MPLVP_RESUME_VISUAL_END, eRet, self);
    return eRet;
}

/*****************************************************************************
* DESCRIPTION
*    The interface for getting current video frame for MDI.
*
*    This function retrieves video frame from Renderer to MDI.  Although subt-
*    itle buffer are brought in, MPL would not let subtitle decoder draw on it
*    under current design.
*
*    Note that sometimes APP would show error and stop playing when finding e-
*    rrors on this function.  It is always suggested to ignore such error and
*    let the file playing.
*
*****************************************************************************/
static media_error_t mpl_session_get_frame(
                        mpl_player_t* mpl, mpl_player_get_frame_t* frame_struct)
{
    mpl_session_struct *self = SELF(mpl, mpl_session_struct, mpl);
    VIDEO_COMPONENT_TYPE_T *render_handle = self->render_handle;
    kal_uint32 dummy_addr = NULL;
    media_error_t eRet = MED_S_OK;

    kal_trace(TRACE_FUNC, MPLVP_GET_FRAME, self->state, (med_frame_enum)frame_struct->frame_mode, self);
    if (MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]))
    {
        mpl_session_video_config_t rVideoConfig;

        kal_mem_set(&rVideoConfig, 0, sizeof(rVideoConfig));

        rVideoConfig.brightness = self->brightness;
        rVideoConfig.contrast = self->contrast;
        rVideoConfig.display_width = frame_struct->display_width;
        rVideoConfig.display_height = frame_struct->display_height;
        rVideoConfig.image_buffer_p = frame_struct->image_buffer_p;
        rVideoConfig.image_data_format = frame_struct->image_data_format;
        rVideoConfig.idp_rotate = frame_struct->idp_rotate;
        rVideoConfig.frame_mode = frame_struct->frame_mode;
        #if defined(__VE_3D_SIDE_BY_SIDE__)
        rVideoConfig.e3DMode = frame_struct->e3DMode;
        #endif

#if defined(__VE_SUBTITLE_SUPPORT__)
        rVideoConfig.subtitle_image_buffer_p = frame_struct->subtitle_image_buffer_p;
        rVideoConfig.subtitle_width = frame_struct->subtitle_width;
        rVideoConfig.subtitle_height = frame_struct->subtitle_height;
#endif

        rVideoConfig.idp_rotate = 0;
        rVideoConfig.fgRendererVisible = KAL_FALSE;
        mpl_session_set_render_param(self, &rVideoConfig);

        {
            kal_bool fgCurr = KAL_FALSE;
            render_handle->pfnSetParameter(VIDEO_PARAM_RENDERER_KEEP_CURR_PTR,(void*) &fgCurr);
        }

        {
            VIDEO_ERROR_TYPE_T eErr = VIDEO_ERROR_NONE;

            /* The second parameter is useless. Render will copy frame to lcd_buffer1 directly */
            eErr = render_handle->pfnGetParameter(VIDEO_PARAM_RENDERER_RENDER_DISPLAY_BUFFER, (void*) &dummy_addr);
            if (eErr != VIDEO_ERROR_NONE)
            {
                eRet = MED_E_OVER_LIMIT;
            }
        }
        goto GET_FRM_EXIT;
    }
    else
    {
        eRet = MED_E_FAIL;
        goto GET_FRM_EXIT;
    }

GET_FRM_EXIT:
    kal_trace(TRACE_FUNC, MPLVP_GET_FRAME_END, eRet, self);
    return eRet;
}


/*****************************************************************************
* DESCRIPTION
*    The interface for getting media info for MDI.
*
*    This function returns the information that MPL previously gets from Sour-
*    ce.  The width/height would be updated through Decoder if there are no s-
*    uch information in files
*
*****************************************************************************/
static media_error_t mpl_session_get_media_info(
                            mpl_player_t* mpl,
                            mpl_player_get_media_info_t *prMediaInfo)
{
    mpl_session_struct *self = SELF(mpl, mpl_session_struct, mpl);
    SPIF_VIDEO_STREAM_INFO_T *prVideoStream = &self->rVideoStream;
    SPIF_AUDIO_STREAM_INFO_T *prAudioStream = &self->rAudioStream;
    VIDEO_COMPONENT_TYPE_T *decoder_handle = self->decoder_handle;
    VIDEO_QUERY_FRAME_SIZE_TYPE_T frame_size;
    media_error_t eRet = MED_S_OK;

    if (self->state == MPL_STATE_CLOSED || self->state == MPL_STATE_OPENING)
    {
        eRet = MED_E_WRONG_STATE;
        goto GET_MEDIA_INFO_EXIT;
    }

    kal_mem_set(prMediaInfo, 0, sizeof(*prMediaInfo));

    prMediaInfo->track_info = MED_NO_TRACK;
    prMediaInfo->aud_format = MEDIA_FORMAT_UNKNOWN;

    /* Video information */
    if (MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]))
    {
        prMediaInfo->vid_duration = prVideoStream->u8Duration;
        prMediaInfo->track_info |= MED_VISUAL_TRACK;

        /* Update from player */
        if (prVideoStream->u4Width == 0 || prVideoStream->u4Height == 0)
        {
            if (NULL != decoder_handle)
            {
                decoder_handle->pfnGetParameter(VIDEO_PARAM_QUERY_RESOLUTION, &frame_size);
            }
            prVideoStream->u4Width = frame_size.u4Width;
            prVideoStream->u4Height = frame_size.u4Height;
        }

        prMediaInfo->width = prVideoStream->u4Width;
        prMediaInfo->height = prVideoStream->u4Height;
    }

    /* Audio information */
    if (MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO]))
    {
        prMediaInfo->audio_channel_num = (kal_uint32)prAudioStream->u2Channels;
        prMediaInfo->audio_sampling_rate = prAudioStream->u4SampleRate;
        prMediaInfo->aud_duration = prAudioStream->u8Duration;
        prMediaInfo->track_info |= MED_AUDIO_TRACK;

        prMediaInfo->aud_format = self->aud_format;
    }

    /* Total Duration */
    if (prMediaInfo->vid_duration > prMediaInfo->aud_duration)
    {
        prMediaInfo->duration = prMediaInfo->vid_duration;
    }
    else
    {
        prMediaInfo->duration = prMediaInfo->aud_duration;
    }

    // TODO: Get file handle from source
    /* FS handle */
    prMediaInfo->file_handle = (kal_uint32)self->fs_handle;

GET_MEDIA_INFO_EXIT:
    kal_trace(TRACE_FUNC, MPLVP_GET_MEDIA_INFO_END,
        prMediaInfo->width,
        prMediaInfo->height,
        (kal_uint32)prMediaInfo->vid_duration,
        (kal_uint32)prMediaInfo->aud_duration,
        eRet,
        self);

    return eRet;
}


/*****************************************************************************
* DESCRIPTION
*    This function retrieves buffer status from Source for APP to update prog-
*    ress bar.
*
*    Note that the function may take time depending on file characteristics.
*
*****************************************************************************/
static media_error_t _MPLVP_GetBufferStatus_Internal(mpl_player_t* mpl, mpl_player_streaming_buffer_status_t* prStatus)
{
    mpl_session_struct *self = SELF(mpl, mpl_session_struct, mpl);
    VIDEO_COMPONENT_MI_TYPE_T *source_handle = self->source_handle;
    SPIF_STREAMING_BUF_INFO_T rBuffInfo;
    kal_uint32 u4StreamIdx = prStatus->u4StreamIdx;

    if (u4StreamIdx == self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO])
    {
        rBuffInfo.ePort = SOURCE_PROVIDER_PORT_AUDIO;
    }
    else if (u4StreamIdx == self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO])
    {
        rBuffInfo.ePort = SOURCE_PROVIDER_PORT_VIDEO;
    }
    else
    {
        return MED_E_FAIL;
    }

    source_handle->pfnGetParameter(self->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_STREAMING_BUF, &rBuffInfo);

    prStatus->u4Free = rBuffInfo.u4FreeBuf;
    prStatus->u4Total = rBuffInfo.u4TotalBuf;
    prStatus->fgBufferHigh = rBuffInfo.fgBufferHigh;

    kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_GET_BUFF_STATUS, u4StreamIdx, rBuffInfo.u4FreeBuf, rBuffInfo.u4TotalBuf);

    return MED_S_OK;
}


/*****************************************************************************
* DESCRIPTION
*    The interface for getting information from MPL for MDI.
*
*****************************************************************************/
#define _LCC_SUPPORTED 1
static media_error_t mpl_session_get_param(
    mpl_player_t* mpl,
    mpl_player_param_enum param,
    void *value)
{
    media_error_t eRet = MED_S_OK;
    mpl_session_struct *self = SELF(mpl, mpl_session_struct, mpl);
    VIDEO_COMPONENT_MI_TYPE_T *source_handle = self->source_handle;

    if (self->state == MPL_STATE_CLOSED || self->state == MPL_STATE_OPENING)
    {
        eRet = MED_E_WRONG_STATE;
        goto GET_PARAM_END;
    }

    switch(param)
    {
        case MPL_PARAM_FILE_HANDLE:
            (*(kal_uint32*)value) = (kal_uint32)self->fs_handle;
            break;

        case MPL_PARAM_CURRENT_PLAY_TIME:
            (*(kal_uint64*)value) = (kal_uint64)mpl_session_get_play_time(self);
            break;

        case MPL_PARAM_DUMMY_AUD_PLAYING:
            {
                (*(kal_bool*)value) = KAL_FALSE;
            }
            break;

        case MPL_PARAM_AUD_PLAYING:
            if (self->mhdl_handle && self->play_audio)
            {
                (*(kal_bool*)value) = KAL_TRUE;
            }
            else
            {
                (*(kal_bool*)value) = KAL_FALSE;
            }
            break;

        case MPL_PARAM_IS_SEEKABLE:
            (*(kal_bool*)value) = self->fgSeekable;
            break;

        case MPL_PARAM_IS_LCD_UPDATED:
            (*(kal_bool*)value) = self->fgLCDTriggered;
            break;

#ifdef __VE_JAVA_ENABLED__
        case MPL_PARAM_TIME_TO_FRAME:
            {
                mpl_player_param_time_and_frame_mapping_t *prTimeFrame;
                SPIF_FRAME_TIME_T rSPTimeFrame;

                prTimeFrame = (mpl_player_param_time_and_frame_mapping_t *)value;
                rSPTimeFrame.ePort = SOURCE_PROVIDER_PORT_VIDEO;
                rSPTimeFrame.u8FrameTime = prTimeFrame->time;
                source_handle->pfnGetParameter(self->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_TIME_TO_FRAME, &rSPTimeFrame);
                prTimeFrame->frame = rSPTimeFrame.u4Frame;
            }
            break;

        case MPL_PARAM_FRAME_TO_TIME:
            {
                mpl_player_param_time_and_frame_mapping_t *prTimeFrame;
                SPIF_FRAME_TIME_T rSPTimeFrame;

                prTimeFrame = (mpl_player_param_time_and_frame_mapping_t *)value;
                rSPTimeFrame.ePort = SOURCE_PROVIDER_PORT_VIDEO;
                rSPTimeFrame.u4Frame = prTimeFrame->frame;
                source_handle->pfnGetParameter(self->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_FRAME_TO_TIME, &rSPTimeFrame);
                prTimeFrame->time = rSPTimeFrame.u8FrameTime;
            }
            break;
#endif

#ifdef __VE_PRIRATE_3D_FORMAT__
        case MPL_PARAM_VID_TRACK:
            {
                mpl_player_track_info_t *pTrack = (mpl_player_track_info_t*)value;
                mpl_player_track_info_t *prVidTrackInfo = &self->rVidTrackInfo;

                pTrack->u4Num = prVidTrackInfo->u4Num;
                pTrack->pvTrackInfo = prVidTrackInfo->pvTrackInfo;
            }
            break;
#endif
        case MPL_PARAM_GET_STREAMING_BUFFER_STATUS:
            {
                eRet = _MPLVP_GetBufferStatus_Internal(mpl, value);
            }
            break;

        case MPL_PARAM_GET_SUBTITLE_TRACKS:
            {
                mpl_player_track_info_t *pTrack = (mpl_player_track_info_t*)value;

#if defined(__VE_SUBTITLE_SUPPORT__)
                SPIF_STREAM_INFO_T rStreamInfo;
                mpl_player_subtitle_track_info_t *prTrackInfo = self->arSubtitleTrackInfo;
                SPIF_SUBTITLE_STREAM_INFO_T* prSubtitleInfo = NULL;

                if (NULL == self->pfnIsLCCSupported)
                {
                    pTrack->u4Num = 0;
                    eRet = MED_E_INVALID_PARAM;
                    goto GET_PARAM_END;
                }

                source_handle->pfnGetParameter(self->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_SUBT_STREAM_INFO, &rStreamInfo);

                if (KAL_TRUE == rStreamInfo.fgSupport)
                {
                    kal_uint32 u4Loop = rStreamInfo.u4Num;
                    kal_uint32 u4RecordedTrack = 0;


                    prSubtitleInfo = (SPIF_SUBTITLE_STREAM_INFO_T*)rStreamInfo.pvStreamInfo;

                    pTrack->pvTrackInfo = prTrackInfo;

                    while(u4Loop != 0)
                    {
                        if (u4RecordedTrack == MPL_SESSION_MAX_SUBTITLE_TRACK_NUM)
                        {
                            break;
                        }

                        if (_LCC_SUPPORTED == self->pfnIsLCCSupported(prSubtitleInfo->u4Language))
                        {
                            prTrackInfo->u4Language = prSubtitleInfo->u4Language;
                            prTrackInfo->u4TrackIndex = prSubtitleInfo->u4StreamIndex;
                            prTrackInfo++;
                            u4RecordedTrack++;
                        }
                        prSubtitleInfo++;
                        u4Loop--;
                    }
                    pTrack->u4Num = u4RecordedTrack;
                }
                else
#endif
                {
                    pTrack->u4Num = 0;
                    pTrack->pvTrackInfo = NULL;
                }
            }
            break;

        case MPL_PARAM_GET_KEYFRAME_TIME:
            {
                mpl_player_param_query_keyframe_time_t* pTmp = (mpl_player_param_query_keyframe_time_t*)value;

                eRet = mpl_session_get_key_frame_time(self, SOURCE_PROVIDER_PORT_VIDEO, &pTmp->u8Time_IN, &pTmp->u8KeyFrameTime_OUT);
            }
            break;

        case MPL_PARAM_IS_PROPRIETARY_FORMAT:
#if defined(__VE_VIDEO_CLIPPER_SUPPORT__)
            {
                source_handle->pfnGetParameter(self->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_MTK_FILE, value);
            }
#else
            {
                kal_bool* pfgtmp = (kal_bool*)(value);
                *pfgtmp = KAL_FALSE;
            }
#endif
            break;

        default:
            eRet = MED_E_INVALID_PARAM;
            goto GET_PARAM_END;
    }

GET_PARAM_END:
    kal_trace(TRACE_FUNC, MPLVP_GET_PARAM_END, eRet, param, self);
    return eRet;
}


/*****************************************************************************
* DESCRIPTION
*    The interface for setting parameters to MPL for MDI
*
*****************************************************************************/
static media_error_t mpl_session_set_param(
    mpl_player_t* mpl,
    mpl_player_param_enum param,
    void *value)
{
    media_error_t eRet = MED_S_OK;
    mpl_session_struct *self = SELF(mpl, mpl_session_struct, mpl);
    MHdl *mhdl_handle = self->mhdl_handle;
    const VIDEO_COMPONENT_TYPE_T *prRenderer = self->render_handle;
    const kal_uint8 u1VideoStreamIdx = self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO];

    switch(param)
    {
        case MPL_PARAM_AUD_VOLUME:
            if (NULL != mhdl_handle)
            {
                mhdl_handle->SetLevel(mhdl_handle, (*(kal_uint8*)value));
            }
            break;

        case MPL_PARAM_BRIGHTNESS:
            if (MPL_IS_STRM_VALID(u1VideoStreamIdx))
            {
                va2_video_renderer_post_process_config_t ipp;

                ipp.b_brightness = KAL_TRUE;
                ipp.b_contrast = KAL_FALSE;
                ipp.u1_brightness = (*(kal_uint8*) value);
                if (NULL != prRenderer)
                {
                    prRenderer->pfnSetParameter(VIDEO_CONFIG_RENDERER_POST_PROCESS, (void*) &ipp);
                    self->brightness = (*(kal_uint8*) value);
                }
                else
                {
                    eRet =  MED_S_FALSE;
                }
            }
            break;

        case MPL_PARAM_CONTRAST:
            if (MPL_IS_STRM_VALID(u1VideoStreamIdx))
            {
                va2_video_renderer_post_process_config_t ipp;

                ipp.b_brightness = KAL_FALSE;
                ipp.b_contrast = KAL_TRUE;
                ipp.u1_contrast = (*(kal_uint8*) value);
                if (NULL != prRenderer)
                {
                    prRenderer->pfnSetParameter(VIDEO_CONFIG_RENDERER_POST_PROCESS, (void*) &ipp);
                    self->contrast = (*(kal_uint8*) value);
                }
                else
                {
                    eRet =  MED_S_FALSE;
                }
            }
            break;

#ifdef __VE_STREAM_SUPPORT__
        case MPL_PARAM_AUD_ADD_HEADER:
            self->fgAudAddHeader = (*(kal_bool*) value);
            break;

        case MPL_PARAM_AUD_TIME_DIFF:
            self->u4AudDeltaTime = (*(kal_uint32*) value);
            kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_AUD_TIME_DIFF, self->u4AudDeltaTime);
            break;
#endif

#if defined(__VE_STOPTIME_SUPPORT__)
        case MPL_PARAM_STOP_TIME:
            self->u8StopTime = (*(kal_uint64*)value);
            if (MPL_IS_STRM_INVALID(u1VideoStreamIdx))
            {
                if (NULL != mhdl_handle)
                {
                    mhdl_handle->SetStopTime(mhdl_handle, self->u8StopTime);
                }
            }
            else
            {
                VIDEO_COMPONENT_TYPE_T *scheduler_handle = self->scheduler_handle;
                kal_uint64 u8ClockTime = 0;

                 if (NULL != scheduler_handle)
                {
                    u8ClockTime = MPL_SESSION_TIME_TO_COMPTIME(self->u8StopTime);
                    scheduler_handle->pfnSetParameter(VIDEO_PARAM_STOP_TIME, &u8ClockTime);
                }
                else
                {
                    eRet =  MED_S_FALSE;
                }
            }
            break;
#endif

#if defined(__VE_ENABLE_FORCE_SLEEP__)
        case MPL_PARAM_SLEEP_TIME:
            {
                mpl_player_param_sleep_time_t *prSleepTime;

                prSleepTime = (mpl_player_param_sleep_time_t*) param;
                self->elapse_ticks = prSleepTime->elapse_ticks;
                self->sleep_ticks = prSleepTime->sleep_ticks;
            }
            break;
#endif

#ifdef __VE_PRIRATE_3D_FORMAT__
        case MPL_PARAM_VID_TRACK:
        {
            kal_uint32 u4TrackIndex;
            mpl_video_track_type_enum eTrackType = MPL_VIDEO_2D_NORMAL;
            mpl_player_video_track_info_t *prVidTrackInfoArray = self->rVidTrackInfoArray;
            kal_uint32 i, u4TrackNum;
            VIDEO_COMPONENT_MI_TYPE_T *source_handle = self->source_handle;
            SPIF_STREAM_INFO_T rStreamInfo;
            SPIF_VIDEO_STREAM_INFO_T *prVideoInfo;

                u4TrackIndex = (*(kal_uint32*)value);
                u4TrackNum = self->rVidTrackInfo.u4Num;

                for (i = 0; i < u4TrackNum; i++)
                {
                    if (prVidTrackInfoArray[i].u4TrackIndex == u4TrackIndex)
                    {
                        eTrackType = prVidTrackInfoArray[i].eVidTrackType;
                        break;
                    }
                }

                kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_SET_VID_TRACK, u4TrackIndex, eTrackType);

                /* Update track info */
                /* video: query stream info */
                source_handle->pfnGetParameter(self->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_VID_STREAM_INFO, &rStreamInfo);
                if (rStreamInfo.fgSupport == KAL_TRUE)
                {
                    kal_uint32 u4TrackNum = rStreamInfo.u4Num;
                    kal_uint32 i;

                    prVideoInfo = (SPIF_VIDEO_STREAM_INFO_T*)rStreamInfo.pvStreamInfo;

                    /* Get 3D track info */
                    /* pack into mpl track info struct */
                    for (i = 0; i < u4TrackNum; i++)
                    {
                        if (u4TrackIndex == prVideoInfo[i].u4StreamIndex)
                        {
                            break;
                        }
                    }

                    self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO] = u4TrackIndex;
                    self->rVideoStream = prVideoInfo[i];
                }

                if (eTrackType == MPL_VIDEO_3D)
                {
                    self->fg3DAnaglyph = KAL_TRUE;
                    self->eVidQuality = VIDEO_DEC_MODE_BEST_QUALITY;
                }
            }
            break;
#endif

        case MPL_PARAM_SET_SUBTITLE_TRACKS:
            {
#if defined(__VE_SUBTITLE_SUPPORT__)
                kal_uint32 u4TrackIdx = (*(kal_uint32*)value);
                SPIF_STREAM_INFO_T rStreamInfo;
                SPIF_SUBTITLE_STREAM_INFO_T* prSubtitleInfo = NULL;
                kal_bool fgSetIdx = KAL_FALSE;

                self->source_handle->pfnGetParameter(self->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_SUBT_STREAM_INFO, &rStreamInfo);

                if (KAL_TRUE == rStreamInfo.fgSupport)
                {
                    kal_uint32 i = 0;

                    prSubtitleInfo = (SPIF_SUBTITLE_STREAM_INFO_T*)rStreamInfo.pvStreamInfo;

                    for(i = 0; i < rStreamInfo.u4Num; i++)
                    {
                        if (u4TrackIdx == prSubtitleInfo->u4StreamIndex)
                        {
                            self->au1StreamIdx[SOURCE_PROVIDER_PORT_SUBTITLE] = (kal_uint8)u4TrackIdx;
                            self->rSubtitleInfo = *prSubtitleInfo;
                            fgSetIdx = KAL_TRUE;
                            break;
                        }
                        prSubtitleInfo++;
                    }
                }

                if (KAL_FALSE == fgSetIdx)
                {
                    ASSERT(0);
                }
#endif
            }
            break;

        case MPL_PARAM_SET_FONT_SIZE:
            {
                self->u4FontSize = *(kal_uint8*)value;
            }
            break;

        default:
            eRet = MED_E_INVALID_PARAM;
            goto SET_PARAM_END;
    }

SET_PARAM_END:
    kal_trace(TRACE_FUNC, MPLVP_SET_PARAM_END, eRet, param, self);
    return eRet;
}


/*****************************************************************************
* DESCRIPTION
*    The interface for getting META information for MDI
*
*****************************************************************************/
static media_error_t mpl_session_get_meta(mpl_player_t* mpl, mpl_player_get_meta_t *prMeta)
{
    const mpl_session_struct *self = SELF(mpl, mpl_session_struct, mpl);
    const VIDEO_COMPONENT_MI_TYPE_T *source_handle = self->source_handle;
    SPIF_META_DATA_T rMetaData;

    if ((self->state == MPL_STATE_CLOSED) || (self->state == MPL_STATE_OPENING))
    {
        return MED_E_WRONG_STATE;
    }

    kal_mem_set(&rMetaData, 0, sizeof(rMetaData));
    rMetaData.u2TitleLen        = prMeta->title_desc_len;
    rMetaData.pu2Title          = prMeta->title_desc_ptr;
    rMetaData.u2ArtistLen       = prMeta->artist_desc_len;
    rMetaData.pu2Artist         = prMeta->artist_desc_ptr;
    rMetaData.u2AuthorLen       = prMeta->author_desc_len;
    rMetaData.pu2Author         = prMeta->author_desc_ptr;
    rMetaData.u2AlbumLen        = prMeta->album_desc_len;
    rMetaData.pu2Album          = prMeta->album_desc_ptr;
    rMetaData.u2CopyrightLen    = prMeta->copyright_desc_len;
    rMetaData.pu2Copyright      = prMeta->copyright_desc_ptr;
    rMetaData.u2DateLen         = prMeta->date_desc_len;
    rMetaData.pu2Date           = prMeta->date_desc_ptr;

    source_handle->pfnGetParameter(self->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_METADATA_INFO, &rMetaData);

    return MED_S_OK;
}


#if defined(__VE_MOT_CATEGORY__)
/*****************************************************************************
* DESCRIPTION
*    The interface for gettting META information of MOT for MDI
*
*****************************************************************************/
static media_error_t mpl_session_get_mot_meta(mpl_player_t* mpl, mpl_player_get_mot_meta_t *prMeta)
{
    const mpl_session_struct *prSelf = SELF(mpl, mpl_session_struct, mpl);
    const VIDEO_COMPONENT_MI_TYPE_T *source_handle = prSelf->source_handle;
    SPIF_META_DATA_T rMetaData;

    if (prSelf->state == MPL_STATE_CLOSED || prSelf->state == MPL_STATE_OPENING)
    {
        return MED_E_WRONG_STATE;
    }

    kal_mem_set(&rMetaData, 0, sizeof(rMetaData));
    rMetaData.u2TitleLen        = prMeta->title_desc_len;
    rMetaData.pu2Title          = prMeta->title_desc_ptr;
    rMetaData.u2ArtistLen       = prMeta->artist_desc_len;
    rMetaData.pu2Artist         = prMeta->artist_desc_ptr;
    rMetaData.u2DateLen         = prMeta->date_desc_len;
    rMetaData.pu2Date           = prMeta->date_desc_ptr;
    rMetaData.u4AnnotationLen   = prMeta->annotation_desc_len;
    rMetaData.pu2Annotation     = prMeta->annotation_desc_ptr;
    rMetaData.u2TypeLen         = prMeta->type_desc_len;
    rMetaData.pu2Type           = prMeta->type_desc_ptr;
    rMetaData.u4ThumbnailDataAllocatedLen   = prMeta->thumbnail_data_allocated_len;
    rMetaData.pu1ThumbnailData              = prMeta->thumbnail_data_ptr;

    source_handle->pfnGetParameter(prSelf->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_METADATA_INFO, &rMetaData);

    prMeta->thumbnail_type = (mpl_thumbnail_type_enum)rMetaData.eThumbnailType;
    prMeta->thumbnail_data_usaged_len = rMetaData.u4ThumbnailDataUsagedLen;

    return MED_S_OK;
}
#endif


/*****************************************************************************
* DESCRIPTION
*    The interface for gettting control functions for MDI
*
*    The control function includes
*    - mpl_session_get_buffer_percent
*    - mpl_session_get_max_time
*
*****************************************************************************/
static media_error_t mpl_session_get_control(
                            mpl_player_t* mpl,
                            mpl_player_control_t control_id,
                            void** control)
{
#if defined(__VE_PGDL_SUPPORT__) || defined(__VE_STREAM_SUPPORT__)
    mpl_session_struct *self = SELF(mpl, mpl_session_struct, mpl);
#endif

    *control = NULL;

    switch (control_id)
    {
#if defined(__VE_PGDL_SUPPORT__) || defined(__VE_STREAM_SUPPORT__)
        case PLAYER_CONTROL_DL:
            *control = &self->dl_control;
            return MED_S_OK;
#endif /* __VE_PGDL_SUPPORT__ || __VE_STREAM_SUPPORT__ */

        default:
            break;
    }
    return MED_E_FAIL;
}

/*****************************************************************************
* DESCRIPTION
*    This is an internal function to close video path and free the memory all-
*    ocated from MDI as well.
*
*****************************************************************************/
static media_error_t mpl_session_close_video_internal(mpl_session_struct *self)
{
    if (self->media_scenario == MPL_INFO)
    {
        return MED_S_OK;
    }

    /* Chage state to close */
    if (MPL_IS_STRM_VALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]) && !self->fgVidPathInitFail)
    {
        _MPLVP_ChangeComponentState(self, VIDEO_STATE_CLOSE, KAL_TRUE);

        /* Release component handle */
        if (NULL != self->decoder_handle)
        {
            ReleaseVideoDecoderHandle(self->decoder_handle);
            self->decoder_handle = NULL;
        }
        if (NULL != self->scheduler_handle)
        {
            ReleaseVideoDecSchedulerHandle(self->scheduler_handle);
            self->scheduler_handle = NULL;
        }
        if (NULL != self->render_handle)
        {
            ReleaseVideoRendererHandle(self->render_handle);
            self->render_handle = NULL;
        }

        self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO] = MPL_SESSION_INVALID_INDEX;
    }

#if defined(__VE_SUBTITLE_SUPPORT__)
    if (NULL != self->prSubtitleDecoderHdlr)
    {
        ReleaseVsdHandle(self->prSubtitleDecoderHdlr);
        self->prSubtitleDecoderHdlr = NULL;
    }
#endif

    if (NULL != self->ext_handle)
    {
        VideoDeInitExtBuffer(self->ext_handle);
        self->ext_handle = NULL;
    }

    if (NULL != self->int_handle)
    {
        VideoDeInitIntBuffer(self->int_handle, VIDEO_SCENARIO_DECODE);
        self->int_handle = NULL;
    }

    if (NULL != self->extmem_start_address)
    {
        mpl_session_free_ext_mem(self->mpl_client, (void **)&self->extmem_start_address, MED_MEM_NONCACHE);
        self->extmem_start_address = NULL;
    }

    return MED_S_OK;
}

/*****************************************************************************
* DESCRIPTION
*    The interface for closing video path for MDI.
*
*    Usually used by Streaming APP to switch the placback to background.
*
*****************************************************************************/
static media_error_t mpl_session_release_visual(mpl_player_t* mpl)
{
    mpl_session_struct *self = SELF(mpl, mpl_session_struct, mpl);

    kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_RELEASE_VISUAL, self->state);

    if (self->state != MPL_STATE_PLAYING)
    {
        return MED_E_WRONG_STATE;
    }

    if (MPL_IS_STRM_INVALID(self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]))
    {
        return MED_S_FALSE;
    }

    //mpl_session_stop_internal(self);
    /* stop video path */
    mpl_session_stop_video_path(self);
    mpl_session_close_video_internal(self);

    // TODO: check with Gary about release visual memory only

    return MED_S_OK;
}

/*****************************************************************************
* DESCRIPTION
*    The interface for closing MPL for MDI.
*
*    Note that when MPL stays opening state, means that Source is initializi-
*    ng, MPL would force Source closing quickly.
*
*****************************************************************************/
static media_error_t mpl_session_close(mpl_player_t* mpl)
{
    mpl_session_struct *self = SELF(mpl, mpl_session_struct, mpl);
    VIDEO_COMPONENT_MI_TYPE_T *source_handle = self->source_handle;
    media_error_t eErr;

    kal_trace(TRACE_FUNC, MPLVP_CLOSE, self->state, self);

    /* For streaming: seek done, and then close directly */
    if (self->state == MPL_STATE_CLOSED)
    {
        goto CLOSE_END;
    }

    VFC_IOCtrl(VFC_OP_MPL_DEINIT_VFC, NULL, NULL, NULL);

    kal_take_mutex(self->rMutexID);
    if (self->state == MPL_STATE_OPENING)
    {
        self->state = MPL_STATE_CLOSEING;
        kal_give_mutex(self->rMutexID);

        source_handle->pfnSetParameter(self->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_QUICK_CLOSE, NULL);
        /* Wait until the init operation is done */
        eErr = mpl_session_wait_source_change_state(self);
        if (eErr != MED_S_OK)
        {
            mpl_session_close_source(self);
            goto CLOSE_END;
        }
    }
    else
    {
        kal_give_mutex(self->rMutexID);
    }

    // There is chance that seek_internal might run after stop_seek(),
    // we should stop all the components in this case
    if (self->state == MPL_STATE_SEEKING)
    {
        _MPLVP_ChangeComponentState(self, VIDEO_STATE_STOP, KAL_TRUE);
        eErr = _MPLVP_ChangeSourceState(self, VIDEO_STATE_STOP);
        if (eErr != MED_S_OK)
        {
            ASSERT(0);
        }
    }

    /* Close video path */
    mpl_session_close_video_internal(self);

    /* Chage source to close */
    mpl_session_close_source(self);

    self->state = MPL_STATE_CLOSED;

CLOSE_END:
    eErr = MED_S_OK;
    kal_trace(TRACE_FUNC, MPLVP_CLOSE_END, eErr, self);
    return eErr;
}


/*****************************************************************************
* DESCRIPTION
*    The interface for initializing the strucutures of each API for MDI.
*
*    This function exists mainly for backward compatibility that old MDI acco-
*    mpany with new HAL.
*
*****************************************************************************/
static media_error_t mpl_session_get_default(mpl_player_t* mpl, mpl_player_param_type_enum param_id, void* default_param)
{
    switch (param_id)
    {
        case MPL_OPEN_PARAM:
            kal_mem_set((mpl_player_open_t*)default_param, 0, sizeof(mpl_player_open_t));
            break;
        case MPL_SEEK_PARAM:
            kal_mem_set((mpl_player_seek_t*)default_param, 0, sizeof(mpl_player_seek_t));
            break;
        case MPL_GET_FRAME_PARAM:
            kal_mem_set((mpl_player_get_frame_t*)default_param, 0, sizeof(mpl_player_get_frame_t));
            break;
        case MPL_PLAY_PARAM:
            kal_mem_set((mpl_player_play_t*)default_param, 0, sizeof(mpl_player_play_t));
            break;
        case MPL_GET_MOT_META:
            kal_mem_set((mpl_player_get_mot_meta_t*)default_param, 0, sizeof(mpl_player_get_mot_meta_t));
            break;
        default:
            break;
    }

    return MED_S_OK;
}

/*****************************************************************************
* DESCRIPTION
*    This function handles the Decoder callback and it is put in DCM.
*
*****************************************************************************/
static void _MPLVP_DecoderCallbackinDCM(
    VIDEO_EVENT_TYPE_T event,
    kal_uint32 data1,
    kal_uint32 data2,
    void* data_ptr)
{
    mpl_session_struct *prSelf = _prVideoSession;

    switch(event)
    {
        case VIDEO_EVENT_ERROR:
        case VIDEO_EVENT_RESOLUTION_NOT_SUPPORT:
            mpl_session_video_event_callback(MPL_SESSION_EVT_DECODER_RESOLUTION_NOT_SUPPORT);
            break;
        case VIDEO_EVENT_FLUSH_DONE:
            kal_set_eg_events(prSelf->rEventID, MPL_SESSION_EG_DECODER_FLSH_DONE, KAL_OR);
            break;
        case VIDEO_EVENT_EXCEED_MAX_RETRY:
            prSelf->fgDecoderRetryFailed = KAL_TRUE;
            mpl_session_video_event_callback(MPL_SESSION_EVT_DECODER_RETRY_FAILED);
            break;
        default:
            break;
    }
}

/*****************************************************************************
* DESCRIPTION
*    This function handles the Source callback and is put in DCM.
*
*****************************************************************************/
static void _MPLVP_SourceCallbackinDCM(
                            void *context,
                            VIDEO_EVENT_TYPE_T event,
                            kal_uint32 data1,
                            kal_uint32 data2,
                            void* data_ptr)
{
    mpl_session_struct *prSelf = (mpl_session_struct*)context;

    switch(event)
    {
        case VIDEO_EVENT_SET_PORT:
            /* data2: kal_false => error, kal_true: OK */
            if ((kal_bool)data2)
            {
                kal_set_eg_events(prSelf->rEventID, MPL_SESSION_EG_SOURCE_PORT_DONE, KAL_OR);
            }
            else
            {
                kal_set_eg_events(prSelf->rEventID, MPL_SESSION_EG_SOURCE_ERROR, KAL_OR);
            }
            break;
        case VIDEO_EVENT_SEEK_TIME:
            /* data2: kal_false => error, kal_true: OK */
            if ((kal_bool)data2)
            {
                kal_set_eg_events(prSelf->rEventID, MPL_SESSION_EG_SOURCE_SEEK_TIME_DONE, KAL_OR);
            }
            else
            {
                kal_set_eg_events(prSelf->rEventID, MPL_SESSION_EG_SOURCE_ERROR, KAL_OR);
            }
            break;
        case VIDEO_EVENT_GET_KEY_FRAME_TIME:
            /* data2: kal_false => error, kal_true: OK */
            kal_take_mutex(prSelf->rMutexID);
            if (prSelf->state == MPL_STATE_PRE_SEEKING)
            {
                if ((kal_bool)data2)
                {
                    _MPLVP_Send2VideoEventHdlr(prSelf, MPL_SESSION_EVT_SOURCE_PRE_SEEK_DOME);
                }
                else
                {
                    _MPLVP_Send2VideoEventHdlr(prSelf, MPL_SESSION_EVT_SOURCE_ERROR);
                }
            }
            else
            {
                if ((kal_bool)data2)
                {
                    kal_set_eg_events(prSelf->rEventID, MPL_SESSION_EG_SOURCE_KEY_FRAME_DONE, KAL_OR);
                }
                else
                {
                    kal_set_eg_events(prSelf->rEventID, MPL_SESSION_EG_SOURCE_ERROR, KAL_OR);
                }
            }
            kal_give_mutex(prSelf->rMutexID);
            break;
        case VIDEO_EVENT_MEM_LACK:
            kal_set_eg_events(prSelf->rEventID, MPL_SESSION_EG_SOURCE_MEM_LACK, KAL_OR);
            break;
        case VIDEO_EVENT_ERROR:
        case VIDEO_EVENT_TIMEOUT:
            kal_take_mutex(prSelf->rMutexID);
            prSelf->fgVidError = KAL_TRUE;
            prSelf->fgAudError = KAL_TRUE;
            prSelf->fgSubtitleError = KAL_TRUE;
            if (prSelf->state == MPL_STATE_OPENING)
            {
                _MPLVP_SourceCallback(prSelf, MPL_SESSION_EVT_SOURCE_ERROR);
            }
            else
            {
                kal_set_eg_events(prSelf->rEventID, MPL_SESSION_EG_SOURCE_ERROR, KAL_OR);
            }
            kal_give_mutex(prSelf->rMutexID);
            break;
        case VIDEO_EVENT_PARSER_ERROR:
            {
                kal_take_mutex(prSelf->rMutexID);
                if (prSelf->state == MPL_STATE_OPENING)
                {
                    _MPLVP_SourceCallback(prSelf, MPL_SESSION_EVT_SOURCE_ERROR);
                }
                else
                {
                    switch(data2)
                    {
                    case SOURCE_PROVIDER_PORT_VIDEO:
                        prSelf->fgVidError = KAL_TRUE;
                        prSelf->fgVidFinished = KAL_TRUE;
                        break;
                    case SOURCE_PROVIDER_PORT_AUDIO:
                        prSelf->fgAudError = KAL_TRUE;
                        prSelf->fgAudFinished = KAL_TRUE;
                        break;
#if defined(__VE_SUBTITLE_SUPPORT__)
                    case SOURCE_PROVIDER_PORT_SUBTITLE:
                        prSelf->fgSubtitleError = KAL_TRUE;
                        break;
#endif
                    default:
                        ASSERT(0);
                        break;
                    }

                    _MPLVP_SourceCallback(prSelf, MPL_SESSION_EVT_SOURCE_ERROR);
                }
                kal_give_mutex(prSelf->rMutexID);
            }
            break;
        case VIDEO_EVENT_PARSER_DELAY_ERROR:
            {
                kal_uint32 u4Idx = 0;
                switch(data2)
                {
                case SOURCE_PROVIDER_PORT_VIDEO:
                    u4Idx = MPL_VIDEO_IDX;
                    break;
                case SOURCE_PROVIDER_PORT_AUDIO:
                    u4Idx = MPL_AUDIO_IDX;
                    break;
#if defined(__VE_SUBTITLE_SUPPORT__)
                case SOURCE_PROVIDER_PORT_SUBTITLE:
                    u4Idx = MPL_SUBTITLE_IDX;
                    break;
#endif
                default:
                    break;
                }
                prSelf->afgSourceDelay[u4Idx] = KAL_TRUE;
            }
            break;
#if defined(__VE_PGDL_SUPPORT__)
        case VIDEO_EVENT_PARSER_PGDL_UNDERFLOW:
            {
                switch(data2)
                {
                case SOURCE_PROVIDER_PORT_VIDEO:
                    _MPLVP_SourceCallback(prSelf, MPL_SESSION_EVT_SOURCE_VIDEO_UNDERFLOW);
                    break;
                case SOURCE_PROVIDER_PORT_AUDIO:
                    _MPLVP_SourceCallback(prSelf, MPL_SESSION_EVT_SOURCE_AUDIO_UNDERFLOW);
                    break;
                }
            }
            break;
        case VIDEO_EVENT_QUERY_FRAME_BUFFER_DONE:
            kal_set_eg_events(prSelf->rEventID, MPL_SESSION_EG_SOURCE_QUERY_FRM_DONE, KAL_OR);
            break;
#endif
        default:
            MPL_ASSERT(0);
            break;
    }
}

#ifdef __VE_DCM_WITH_COMPRESSION__
#pragma arm section code, rodata
#endif

#if defined(__VE_PGDL_SUPPORT__)
/*****************************************************************************
* DESCRIPTION
*    The interface for gettting avaialble time for playing for MDI.
*
*    This function might take some time.  For enabling cache mechanism and av-
*    oid race condition, the querying function of Source is done asynchronous-
*    ly.
*
*    The calculation of available time under different condition is weird...b-
*    ut it is okay to let it stay what it is now.
*
*****************************************************************************/
static void mpl_session_get_avail_time(
                mpl_session_struct *self,
                media_time_t *pAvailTime,
                media_time_t *pDuration)
{
    media_time_t aud_dur = 0, vid_dur = 0, avail_aud, avail_vid;
    SPIF_VIDEO_STREAM_INFO_T *prVideoInfo = &self->rVideoStream;
    SPIF_AUDIO_STREAM_INFO_T *prAudioInfo = &self->rAudioStream;
    VIDEO_COMPONENT_MI_TYPE_T *source_handle = self->source_handle;
    SPIF_BUF_STATUS_T rBuffStatus;
    SPIF_BUF_INFO_T rPGDLBuffInfo;
    kal_uint32 u4Event = 0;

    vid_dur = prVideoInfo->u8Duration;
    aud_dur = prAudioInfo->u8Duration;
    *pDuration = (vid_dur > aud_dur) ? vid_dur : aud_dur;

    /* get buffer status from source */
    rBuffStatus.start_time = self->current_time;
    rBuffStatus.prBufStatus = &rPGDLBuffInfo;

    kal_trace(TRACE_FUNC, MPLVP_QUERY_FRAME_BUFFER, (kal_uint32)rBuffStatus.start_time);
    source_handle->pfnGetParameter(self->source_cntx, VIDEO_PARAM_SOURCE_PROVIDER_QUERY_FRAME_BUF, &rBuffStatus);
    kal_retrieve_eg_events(self->rEventID, MPL_SESSION_EG_SOURCE_QUERY_FRM_DONE, KAL_OR_CONSUME, &u4Event, KAL_SUSPEND);

    avail_aud = rPGDLBuffInfo.u8AudioAvailDur;
    avail_vid = rPGDLBuffInfo.u8VideoAvailDur;

    /* Live streaming. No duration */
    if (aud_dur == 0 && vid_dur == 0)
    {
        *pAvailTime = (avail_aud > avail_vid) ? avail_vid : avail_aud;
    }
    /* A & V finish downloading */
    else if (avail_aud >= aud_dur && avail_vid >= vid_dur)
    {
        *pAvailTime = (vid_dur > aud_dur) ? vid_dur : aud_dur;
    }
    /* No A | A finish downloading */
    else if ( aud_dur == 0 || avail_aud >= aud_dur)
    {
        *pAvailTime = avail_vid;
    }
    /* No V | V finish downloading */
    else if (vid_dur == 0 || avail_vid >= vid_dur)
    {
        *pAvailTime = avail_aud;
    }
    /* A & V are downloading */
    else if (avail_aud < avail_vid)
    {
        *pAvailTime = avail_aud;
    }
    else
    {
        *pAvailTime = avail_vid;
    }
    kal_trace(TRACE_FUNC, MPLVP_QUERY_FRAME_BUFFER_END, (kal_uint32)avail_aud, (kal_uint32)avail_vid, (kal_uint32)*pAvailTime);
}

/*****************************************************************************
* DESCRIPTION
*    The interface for getting the download percentage for MDI.
*
*    It is the same as getting available time but returning in percent, taking
*    time as well.
*
*****************************************************************************/
static media_error_t mpl_session_get_buffer_percent(mpl_player_ctrl_dl_t* dl, kal_uint32* percent)
{
    mpl_session_struct *self = SELF(dl, mpl_session_struct, dl_control);
    media_time_t remain_time, dur, avail_time, need_time, diff;
    kal_uint32 buff_percent;
    media_time_t pre_buffer_time;
    //kal_trace(TRACE_FUNC, VID_TRC_mpl_session_GET_BUFFER_PERCENT, (kal_uint32)self->current_time, self->state);

    if (KAL_TRUE == _MPLVP_IsStreamMode(self->media_mode) && self->fgBuffSupplier == KAL_FALSE)
    {
        MPL_ASSERT(0);
    }

    /* get availble time */
    mpl_session_get_avail_time(self, &avail_time, &dur);

    /* PDL: Finish downloading */
    if (self->media_mode == MED_MODE_PDL_FILE && dur != 0 && avail_time >= dur)
    {
        *percent = 100;
        //kal_trace(TRACE_FUNC, VID_TRC_mpl_session_PERCENT, *percent, __LINE__);

        return MED_S_OK;
    }

    /* remain time */
    if (avail_time > self->current_time)
    {
        remain_time = avail_time - self->current_time;
    }
    else
    {
        remain_time = 0;
    }

    pre_buffer_time = MPL_SESSION_BUFFER_TIME_FOR_PLAY;

    /* need time. dur == 0 (live streaming) */
    if (dur >= self->current_time && dur != 0)
    {
        diff = dur - self->current_time;
        need_time = (diff < pre_buffer_time) ? diff : pre_buffer_time;
    }
    else
    {
        need_time = pre_buffer_time;
    }

    if (remain_time >= need_time || need_time == 0)
    {
        buff_percent = 100;
    }
    else
    {
        buff_percent = (kal_uint32)(100 * remain_time / need_time);
    }

    {
        *percent = buff_percent;
    }

    kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_PERCENT, *percent);

    return MED_S_OK;
}


/*****************************************************************************
* DESCRIPTION
*    The interface for gettting the maximum time for MDI.
*
*    It is again the same as getting available time...
*
*****************************************************************************/
static media_error_t mpl_session_get_max_time(mpl_player_ctrl_dl_t* dl, kal_uint64 *max_time)
{
    mpl_session_struct *self = SELF(dl, mpl_session_struct, dl_control);
    media_time_t dur, avail_time;

    //kal_trace(TRACE_FUNC, VID_TRC_mpl_session_GET_MAX_TIME, self->state);

    if( (self->state == MPL_STATE_CLOSED)
      ||(self->state == MPL_STATE_OPENING))
    {
        return MED_E_WRONG_STATE;
    }

    if (KAL_TRUE == _MPLVP_IsStreamMode(self->media_mode) && self->fgBuffSupplier == KAL_FALSE)
    {
        MPL_ASSERT(0);
    }

    mpl_session_get_avail_time(self, &avail_time, &dur);

    /* Assign value */
    *max_time = (avail_time > dur) ? dur : avail_time;



    return MED_S_OK;
}
#endif

#if defined(__VE_STREAM_SUPPORT__)
/*****************************************************************************
* DESCRIPTION
*    The interface function for adding video stream for MDI.
*
*    MDI Streaming calls this function to inform MPL that there is video track
*
*****************************************************************************/
static media_error_t mpl_session_live_add_video_stream(mpl_player_t* mpl, media_stream_t* prStream, kal_uint32* pu4Stream_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mpl_session_struct *self = SELF(mpl, mpl_session_struct, mpl);
    SPIF_VIDEO_STREAM_INFO_T *prVideoStream = &self->rVideoStream;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_ADD_VIDEO_STREAM, self->state);

    /* Add stream */
    prVideoStream->eCodecType = prStream->dec_config.codec;
    prVideoStream->u4Height = prStream->info.video.height;
    prVideoStream->u4Width = prStream->info.video.width;
    prVideoStream->u4Fps = prStream->info.video.fps;
    prVideoStream->u4AvgBitrate= prStream->info.video.avg_bitrate;

    self->vid_stream = *prStream;
    self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO] = *pu4Stream_index;

    mpl_session_set_video_context(self);

    return MED_S_OK;
}

/*****************************************************************************
* DESCRIPTION
*    The interface function for adding audio stream for MDI.
*
*    MDI Streaming calls this functino to inform MPL thay there is audio track
*
*****************************************************************************/
static media_error_t mpl_session_live_add_audio_stream(mpl_player_t* mpl, media_stream_t* prStream, kal_uint32* pu4Stream_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mpl_session_struct *self = SELF(mpl, mpl_session_struct, mpl);
    SPIF_AUDIO_STREAM_INFO_T *prAudioStream = &self->rAudioStream;
    media_audio_info_t *prAudioInfo = &prStream->info.audio;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_ADD_AUDIO_STREAM, self->state);
    /* Add stream */
    prAudioStream->eCodecType = prStream->dec_config.codec;
    prAudioStream->u2Channels= prAudioInfo->channels;
    prAudioStream->u4SampleRate= prAudioInfo->sample_rate;
    prAudioStream->u2BitsPerSample = prAudioInfo->bits_per_sample;
    //prAudioStream->u4FrameDuration = prStream->duration; cook only
    //prAudioStream->fgAddHeader = KAL_TRUE; Streaming owner need to tell mpl by set parameter.

    self->aud_stream = *prStream;
    self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO] = *pu4Stream_index;
    return MED_S_OK;
}

/*****************************************************************************
* DESCRIPTION
*    The interface for requesting MPL preparing for live mode for MDI
*
*    This function initialize Source in Streaming mode.
*
*****************************************************************************/
static media_error_t mpl_session_live_prepare(mpl_player_t* mpl)
{
    mpl_session_struct *prSelf = SELF(mpl, mpl_session_struct, mpl);
    mpl_player_open_t *prOpenInfo = &prSelf->rOpenInfo;
    media_error_t eErr;
    kal_uint32 event_group;

    kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_PREPARE, prSelf->state, prSelf->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO], prSelf->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO]);
    if (MPL_IS_STRM_VALID(prSelf->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]) && MPL_IS_STRM_VALID(prSelf->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO]))
    {
        prOpenInfo->open_track = MED_VID_BOTH;
    }
    else if (MPL_IS_STRM_VALID(prSelf->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO]))
    {
        prOpenInfo->open_track = MED_VID_VISUAL_ONLY;
    }
    else if (MPL_IS_STRM_VALID(prSelf->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO]))
    {
        prOpenInfo->open_track = MED_VID_AUDIO_ONLY;
    }

    eErr = mpl_session_init_source_comp(prSelf, &prSelf->rOpenInfo);
    if (eErr != MED_S_OK)
    {
        return eErr;
    }
    else
    {
        /* Wait until the init operation is done */
        kal_retrieve_eg_events(prSelf->rEventID, MPL_SESSION_EG_SOURCE_COMPLETE, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
        prSelf->state = MPL_STATE_READY;
    }

    eErr = mpl_session_init_source_comp_param(prSelf);
    if (eErr != MED_S_OK)
    {
        return eErr;
    }

    return MED_S_OK;
}

/*****************************************************************************
* DESCRIPTION
*    The interface for pushing bitstreams to MPL for MDI.
*
*    MPL would directly send the bitstreamto Source component.  In the meanwh-
*    ile, Source would notify MDI the buffer status through MPL with the retu-
*    rning value.
*
*****************************************************************************/
static media_error_t mpl_session_live_deliver(mpl_player_t* mpl, kal_uint32 stream_index, media_data_t* media_data)
{
    mpl_session_struct *self = SELF(mpl, mpl_session_struct, mpl);
    SPIF_STREAMING_SILENT_INFO_T rStreamSilenceInfo;
    VIDEO_ERROR_TYPE_T eError;
    mpl_session_state_enum state = self->state;

    kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_DELIVER, stream_index, (kal_uint32)media_data->decode_time, (kal_uint32)media_data->size, self->state);

    if (stream_index == self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO])
    {
        rStreamSilenceInfo.u8LastTime = self->u8AudLastTime;
        rStreamSilenceInfo.u4PredictionLength = self->u4AudDeltaTime;
        eError = SourceProviderStreamingAddData(self->source_cntx, SOURCE_PROVIDER_PORT_AUDIO, media_data, &rStreamSilenceInfo);

    }
    else if (stream_index == self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO])
    {
        eError = SourceProviderStreamingAddData(self->source_cntx, SOURCE_PROVIDER_PORT_VIDEO, media_data, NULL);
    }
    else
    {
        return MED_E_FAIL;
    }

    if (eError == VIDEO_ERROR_BUFF_HIGH)
    {
        /* special handling for buffering */
        if (state == MPL_STATE_PLAYING)
        {
            mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_PLAY, MED_E_STREAM_BUFFER_HIGH);
        }
        else
        {
            mpl_session_client_event_callback(self, MPL_PLAYER_EVENT_SEEK, MED_E_STREAM_BUFFER_HIGH);
        }
    }
    else if (eError != VIDEO_ERROR_NONE)
    {
        if (stream_index == self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO])
        {
             self->u8AudLastTime = rStreamSilenceInfo.u8LastTime;
        }
        return MED_E_FAIL;
    }

    if (stream_index == self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO])
    {
        /* Update last time, used for silence frame */
        self->u8AudLastTime = media_data->decode_time;

        self->u4AudFrameSize += media_data->size;

        /* Ask for query audio driver in value of 4K criteria */
        if (self->state == MPL_STATE_SEEKING && self->u4AudFrameSize >= (4*1024))
        {
            if (self->fgAudioReady2Play == KAL_FALSE)
            {
                self->fgAudioReady2Play = KAL_TRUE;
                mpl_session_audio_event_callback_from_mpl(self, MEDIA_READY_TO_PLAY);
            }
        }
    }

    return MED_S_OK;
}

/*****************************************************************************
* DESCRIPTION
*    The interface for gettting buffer status in live mode for MDI
*
*    Note that the function may take time depending on file characteristics.
*
*****************************************************************************/
static media_error_t mpl_session_live_get_buff_status(mpl_player_t* mpl, kal_uint32 u4StreamIdx, kal_uint32 *pu4Free, kal_uint32 *pu4Total)
{
    mpl_player_streaming_buffer_status_t rStatus;

    kal_mem_set(&rStatus, 0, sizeof(rStatus));
    rStatus.u4StreamIdx = u4StreamIdx;
    if (MED_S_OK == _MPLVP_GetBufferStatus_Internal(mpl, &rStatus))
    {
        *pu4Free = rStatus.u4Free;
        *pu4Total = rStatus.u4Total;
        return MED_S_OK;
    }
    else
    {
        return MED_E_FAIL;
    }
}

/*****************************************************************************
* DESCRIPTION
*    This function is used to resend EOS to Source
*
*****************************************************************************/
static void _mpl_session_live_resend_eos_hdlr(void *param)
{
    mpl_session_video_event_callback(MPL_SESSION_EVT_STREAMING_RESEND_EOS);
}

/*****************************************************************************
* DESCRIPTION
*    The interface for notifying MPL the end of stream for MDI
*
*    MPL would send EOF to Source in this function
*
*****************************************************************************/
static media_error_t mpl_session_live_notify_eos(mpl_player_t* mpl, kal_uint32 stream_index)
{
    mpl_session_struct *self = SELF(mpl, mpl_session_struct, mpl);
    SP_PORT_TYPE_T ePort;
    VIDEO_ERROR_TYPE_T eError;

    kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_NOTIFY_EOS, stream_index, self->state);

    if (stream_index == self->au1StreamIdx[SOURCE_PROVIDER_PORT_AUDIO])
    {
        ePort = SOURCE_PROVIDER_PORT_AUDIO;

        /* Notify eos event in seeking state by mpl itself */
        if (self->state == MPL_STATE_SEEKING)
        {
            mpl_session_audio_event_callback_from_mpl(self, MEDIA_READY_TO_PLAY);
        }
    }
    else if (stream_index == self->au1StreamIdx[SOURCE_PROVIDER_PORT_VIDEO])
    {
        ePort = SOURCE_PROVIDER_PORT_VIDEO;
    }
    else
    {
        return MED_E_FAIL;
    }

    eError = SourceProviderStreamingAddEof(self->source_cntx, ePort, 0);
    if (eError == VIDEO_ERROR_BUFF_FULL)
    {
        self->eStreamingEOSPort = ePort;
        kal_set_timer(self->rTimerID, (kal_timer_func_ptr)_mpl_session_live_resend_eos_hdlr, (void*)self,  (1000 * 7) >> 5, 0);
    }

    return MED_S_OK;
}
#endif

/*****************************************************************************
* DESCRIPTION
*    This function is used to check whether the MPL is still active
*
*****************************************************************************/
static kal_bool _MPLVP_IsValidContext(mpl_session_struct* prSelf)
{
    kal_uint32 i;
    for(i = MPL_SESSION_MAX_CONTEXT; i != 0; i--)
    {
        if (prSelf == mpl_session_cntx_p[i - 1])
        {
            return KAL_TRUE;
        }
    }

    return KAL_FALSE;
}

/*****************************************************************************
* DESCRIPTION
*    The general event handler were seperated into one parts in DCM and the o-
*    ther outside DCM. This is the one outside DCM.
*
*****************************************************************************/
static void mpl_session_event_hdlr_internal(mpl_session_struct *self)
{
    if (KAL_FALSE == _MPLVP_IsValidContext(self))
    {
        return;
    }
    _MPLVP_EventHdlrinDCM(self);
}

/*****************************************************************************
* DESCRIPTION
*    The video event handler were seperated into one parts in DCM and the o-
*    ther outside DCM. This is the one outside DCM.
*
*****************************************************************************/
static void mpl_session_video_event_hdlr(void *param)
{
    mpl_session_vid_event_ind_struct *msg_p;
    mpl_session_struct *self;
    kal_uint32 event;

    /* process ilm message */
    msg_p = (mpl_session_vid_event_ind_struct*)param;
    self = (mpl_session_struct *)msg_p->pu1MyMPL;
    event = msg_p->event;
    free_ctrl_buffer(param);

    if (KAL_FALSE == _MPLVP_IsValidContext(self))
    {
        return;
    }

    _MPLVP_VideoEventHdlrinDCM(self, event);
}

/*****************************************************************************
* DESCRIPTION
*    The audio event handler were seperated into one parts in DCM and the o-
*    ther outside DCM. This is the one outside DCM.
*
*****************************************************************************/
static void mpl_session_audio_event_hdlr(void *param)
{
    mpl_session_aud_event_ind_struct *msg_p;
    mpl_session_struct *self;
    kal_uint32 event;

    msg_p = (mpl_session_aud_event_ind_struct*)param;
    self = (mpl_session_struct *) msg_p->user_data;
    event = msg_p->event;
    free_ctrl_buffer(param);

    if (KAL_FALSE == _MPLVP_IsValidContext(self))
    {
        return;
    }

    _MPLVP_AudioEventHdlrinDCM(self, event);
}

/*****************************************************************************
* DESCRIPTION
*    The interface for querying the capability of MPL for MDI.
*
*****************************************************************************/
media_error_t* query_mpl_player_capability(mpl_player_capability_t* capability)
{
    capability->b_IsBitstreamMemInternal = KAL_FALSE;

    return MED_S_OK;
}

/*****************************************************************************
* DESCRIPTION
*    This function handles the Source callback and is put outside DCM.
*
*****************************************************************************/
static VIDEO_ERROR_TYPE_T mpl_session_source_callback(
                            void *context,
                            VIDEO_EVENT_TYPE_T event,
                            kal_uint32 data1,
                            kal_uint32 data2,
                            void* data_ptr)
{
    mpl_session_struct *prSelf = (mpl_session_struct*)context;

    kal_trace(TRACE_FUNC, VID_TRC_MPL_SESSION_SRC_CALLBACK, event, data1, data2, prSelf->state);

    switch(event)
    {
        case VIDEO_EVENT_COMPLETE:
            if(data1 == VIDEO_COMMAND_STATESET)
            {
                kal_take_mutex(prSelf->rMutexID);
                if (prSelf->state == MPL_STATE_OPENING)
                {
                    _MPLVP_SourceCallback(prSelf, MPL_SESSION_EVT_SOURCE_OPENED);
                    prSelf->state = MPL_STATE_READY;
                }
                else
                {
                    kal_set_eg_events(prSelf->rEventID, MPL_SESSION_EG_SOURCE_COMPLETE, KAL_OR);
                }
                kal_give_mutex(prSelf->rMutexID);
            }
            break;
        default:
            _MPLVP_SourceCallbackinDCM(context, event, data1, data2, data_ptr);
            break;
    }

    return VIDEO_ERROR_NONE;
}

/*****************************************************************************
* DESCRIPTION
*    This function handles the Decoder callback and it is put outside DCM.
*
*****************************************************************************/
static VIDEO_ERROR_TYPE_T mpl_session_decoder_callback(
                            VIDEO_EVENT_TYPE_T event,
                            kal_uint32 data1,
                            kal_uint32 data2,
                            void* data_ptr)
{
    mpl_session_struct *prSelf = _prVideoSession;

    //kal_trace(TRACE_FUNC, VID_TRC_MEDIA_PLAYER_DECODER_CALLBACK, event, data1, self->state);

    switch(event)
    {
        case VIDEO_EVENT_COMPLETE:
            if(data1 == VIDEO_COMMAND_STATESET)
            {
                kal_set_eg_events(prSelf->rEventID, MPL_SESSION_EG_DECODER_COMPLETE, KAL_OR);
            }
            else if(data1 == VIDEO_COMMAND_NOTIFY)
            {
                mpl_session_video_event_callback(MPL_SESSION_EVT_DECODER_COMPLETE);
            }
            break;
        default:
            _MPLVP_DecoderCallbackinDCM(event, data1, data2, data_ptr);
            break;
    }

    return VIDEO_ERROR_NONE;
}

/*****************************************************************************
* DESCRIPTION
*    The interface for setting callback function for audio for MDI.
*
*****************************************************************************/
void mpl_session_set_med_audio_callback(MED_AUD_CALLBACK_FUNC_T *pfn)
{
    mpl_session_med_aud_func = *pfn;
}

#ifdef __VE_DCM_WITH_COMPRESSION__
/*****************************************************************************
* DESCRIPTION
*    Load DCM when the first time a MPL launched
*
*****************************************************************************/
static void _MPLVP_LoadDCM(void)
{
    if (0 == u4MPLCount)
    {
        VideoDCMLoad(DYNAMIC_CODE_COMPRESS_VEDEC);
    }
    u4MPLCount++;
}

/*****************************************************************************
* DESCRIPTION
*    Unload DCM when no MPL alive anymore
*
*****************************************************************************/
static void _MPLVP_UnloadDCM(void)
{
    u4MPLCount--;
    if (0 == u4MPLCount)
    {
        VideoDCMUnLoad(DYNAMIC_CODE_COMPRESS_VEDEC);
    }
}
#endif

/*****************************************************************************
* DESCRIPTION
*    The interface for destroying an active MPL for MDI
*
*    Note that the memory for storing context is freed here
*
*****************************************************************************/
static void mpl_session_destroy(mpl_player_t* mpl)
{
    mpl_session_struct *prSelf = SELF(mpl, mpl_session_struct, mpl);

    /* For Debug Use */
    mpl_session_set_global_context(prSelf, KAL_FALSE);
    VideoFreeTimer(TIMER_USER_PLAYERMPL, prSelf->rTimerID);
    VideoFreeMutex(MUTEX_USER_PLAYERMPL, prSelf->rMutexID);
    VideoFreeEventGroup(EVG_USER_MPL_PLAYER, prSelf->rEventID);

    mpl_session_free_ext_mem(prSelf->mpl_client, (void**)&prSelf, MED_MEM_NONCACHE);

#ifdef __VE_DCM_WITH_COMPRESSION__
    _MPLVP_UnloadDCM();
#endif
}

const static mpl_player_t _rMPLVPAPI =
{
    mpl_session_open, //open
    mpl_session_play, //play
    mpl_session_stop_play, //stop_play
    mpl_session_seek, //seek
    mpl_session_stop_seek, //stop_seek
    mpl_session_get_frame, //get_frame
    mpl_session_get_param, //get_param
    mpl_session_set_param, //set_param
    mpl_session_get_meta, //get_meta
    mpl_session_get_media_info, //get_media_info
    NULL, //get_thumbnail
    mpl_session_get_control, //get_control
    mpl_session_close, //close
    mpl_session_resume_visual_update, //resume_visual_update
    mpl_session_pause_visual_update, //pause_visual_update
    mpl_session_release_visual, //release_visual
#if defined(__VE_STREAM_SUPPORT__)
    mpl_session_live_add_video_stream, //add_video_stream
    mpl_session_live_add_audio_stream, //add_audio_stream
    mpl_session_live_prepare, //prepare
    mpl_session_live_deliver, //deliver
    mpl_session_live_get_buff_status, //get_buff_status
    mpl_session_live_notify_eos, //notify_eos
#else
    NULL, //add_video_stream
    NULL, //add_audio_stream
    NULL, //prepare
    NULL, //deliver
    NULL, //get_buff_status
    NULL, //notify_eos
#endif
    mpl_session_get_default, //get_default
    mpl_session_destroy, //destroy
#if defined(__VE_MOT_CATEGORY__)
    mpl_session_get_mot_meta //get_mot_meta
#else
    NULL
#endif
};

#if defined(__VE_PGDL_SUPPORT__)
static const mpl_player_ctrl_dl_t _rMPLVPDownLoadCtrl =
{
    mpl_session_get_buffer_percent,
    mpl_session_get_max_time
};
#endif

/*****************************************************************************
* DESCRIPTION
*    The interface for constructing a MPL for MDI
*
*    Note the MDI brings in mem_alloc/mem_free function here since MPL needs
*    to allocate memory for storing context
*
*****************************************************************************/
mpl_player_t* construct_media_session(mpl_player_client_t* client)
{
    mpl_session_struct* prSelf;
    mpl_player_capability_t capability;

    prSelf = (mpl_session_struct*)mpl_session_alloc_ext_mem(client, sizeof(*prSelf), MED_MEM_NONCACHE);
    if (NULL == prSelf)
    {
        return NULL;
    }

#ifdef __VE_DCM_WITH_COMPRESSION__
    _MPLVP_LoadDCM();
#endif

    /* Initialize parameter */
    kal_mem_set(prSelf, 0, sizeof(*prSelf));

    // TODO: need to have a compile option?
    query_mpl_player_capability(&capability);
    prSelf->fgBuffSupplier = capability.b_IsBitstreamMemInternal;

    prSelf->mpl_client = client;

    /* Assign exported function */
    prSelf->mpl = _rMPLVPAPI;
    prSelf->state = MPL_STATE_CLOSED;
    prSelf->u4FontSize = 16;
#if defined(__VE_PGDL_SUPPORT__)
    prSelf->dl_control = _rMPLVPDownLoadCtrl;
#endif /* defined(__VE_PGDL_SUPPORT__) || defined(__VE_STREAM_SUPPORT__) */

    /* For Debug Use */
    mpl_session_set_global_context(prSelf, KAL_TRUE);
    mpl_session_set_default(prSelf);
    prSelf->rTimerID = VideoGetTimer(TIMER_USER_PLAYERMPL);
    prSelf->rMutexID = VideoGetMutex(MUTEX_USER_PLAYERMPL);

    prSelf->rEventID = VideoGetEventGroup(EVG_USER_MPL_PLAYER);

    return &prSelf->mpl;
}
#endif /* defined (__VE_VIDEO_ARCHI_V2__) */

