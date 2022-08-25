/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *   vid_clipper_msg_handler.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes message handle functions of video module.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef MED_NOT_PRESENT

/***************************************************************************** 
 * Include
 *****************************************************************************/
/* system includes */
#include "kal_trace.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"         /* Task message communiction */
#include "kal_general_types.h"

/* local includes */
#include "med_global.h"
#include "med_vid_clip_features.h"
#include "med_vid_clip_struct.h"
#include "med_status.h"
#include "med_main.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_utility.h"
#include "med_smalloc.h"
#include "mpl_clipper.h"
#include "vid_main.h"
#if defined(__MED_VID_CLIP_MOD__)

#ifdef __VIDCLIP_TRACE_ON__
#include "med_trc.h"

#define VID_CLIPPER_FUNC_ENTRY(X)       kal_trace(TRACE_GROUP_7, X);
#define VID_CLIPPER_STATE_TRACE(s)      kal_trace(TRACE_GROUP_7, VID_CIPPER_STATE, s);
#define VID_CLIPPER_VALUE_TRACE(x,y,z)  kal_trace(TRACE_GROUP_7, VID_CIPPER_CHECK_VALUE, x, y, z);
#else /* __VID_TRACE_ON__ */ 
#define VID_CLIPPER_FUNC_ENTRY(X)
#define VID_CLIPPER_STATE_TRACE(s)
#define VID_CLIPPER_VALUE_TRACE(x,y,z)
#endif /* __VID_TRACE_ON__ */ 


/***************************************************************************** 
 * Define
 *****************************************************************************/
extern void vid_clipper_enter_state(kal_uint8 state, kal_uint32 line);

#define VID_CLIPPER_ENTER_STATE(_s_) vid_clipper_enter_state(_s_,__LINE__)

#define VID_CLIPPER_IN_STATE(_s_) (vid_clip_context_p->state == _s_)

typedef enum
{
    VID_CLIP_EVT_OPEN   = 0x00000000,
    VID_CLIP_EVT_START  = 0x00000001,
    VID_CLIP_EVT_STOP   = 0x00000002,
    VID_CLIP_EVT_SAVE   = 0x00000004,
    VID_CLIP_EVT_CLOSE  = 0x00000008
}
vid_clip_event_enum;

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

/***************************************************************************** 
 * Variable 
 *****************************************************************************/
mpl_clipper_t *mpl_clipper_p;
alloc_mem_fun_p clipper_alloc_mem;
free_mem_fun_p clipper_free_mem;
/***************************************************************************** 
 * Local Functions 
 *****************************************************************************/

void vid_clipper_enter_state(kal_uint8 state, kal_uint32 line)
{
    VID_CLIPPER_STATE_TRACE(state);
    vid_clip_context_p->state = state;                                     
}


void vid_clipper_mpl_open_hdlr(media_error_t mplResult)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (VID_CLIPPER_IN_STATE(VID_CLIPPER_STATE_OPENING))
    {
        if (mplResult == MED_S_OK)
            VID_CLIPPER_ENTER_STATE(VID_CLIPPER_STATE_OPENED);
        else
            VID_CLIPPER_ENTER_STATE(VID_CLIPPER_STATE_READY);

        result = med_error_to_result_enum(mplResult);
        vid_send_prepare_cnf_ind(result);
    }
    
}


void vid_clipper_mpl_start_hdlr(media_error_t mplResult)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/       
    if (mplResult == MED_S_OK)
    {
        if (VID_CLIPPER_IN_STATE(VID_CLIPPER_STATE_STARTING))
            VID_CLIPPER_ENTER_STATE(VID_CLIPPER_STATE_STARTED);
    }
    else
    {
        result = med_error_to_result_enum(mplResult);
        
        mplResult = mpl_clipper_p->cancel(mpl_clipper_p);       
        if (mplResult == MED_S_ASYNC)
        {
            VID_CLIPPER_ENTER_STATE(VID_CLIPPER_STATE_ERROR_STOPPING);
        }
        else
            ASSERT(0);            
    }

    vid_set_result(result, __LINE__);
    
    VID_SET_EVENT(VID_EVT_START);
}


void vid_clipper_mpl_save_hdlr(media_error_t mplResult)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (mplResult == MED_S_OK)
    {
        if (VID_CLIPPER_IN_STATE(VID_CLIPPER_STATE_STARTED))
            VID_CLIPPER_ENTER_STATE(VID_CLIPPER_STATE_STOPPED);
    }
    else
    {
        result = med_error_to_result_enum(mplResult);
        
        mplResult = mpl_clipper_p->cancel(mpl_clipper_p);
        if (mplResult == MED_S_ASYNC)
        {
            VID_CLIPPER_ENTER_STATE(VID_CLIPPER_STATE_ERROR_STOPPING);
        }
        else
            ASSERT(0);
    }
    
    vid_send_clip_finish_ind(result);
}


void vid_clipper_mpl_stop_hdlr(media_error_t mplResult)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_OK;
    kal_bool is_wait_stop_event = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mplResult != MED_S_OK)
        ASSERT(0);
    
    if (VID_CLIPPER_IN_STATE(VID_CLIPPER_STATE_STOPPING) || 
        VID_CLIPPER_IN_STATE(VID_CLIPPER_STATE_ERROR_STOPPING))
    {
        if (VID_CLIPPER_IN_STATE(VID_CLIPPER_STATE_STOPPING))
            is_wait_stop_event = KAL_TRUE;
        
        VID_CLIPPER_ENTER_STATE(VID_CLIPPER_STATE_STOPPED);
    }
    result = med_error_to_result_enum(mplResult);   

    if (is_wait_stop_event)
    {
        /*  Avoiding setting result in abort stopping state. 
         *  Otherwise, MDI will not get the correct start req error code 
         */
         
        vid_set_result(result, __LINE__);
        VID_SET_EVENT(VID_EVT_STOP);
    }
}


void vid_clipper_mpl_close_hdlr(media_error_t mplResult)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/       
    if (VID_CLIPPER_IN_STATE(VID_CLIPPER_STATE_CLOSING))
    {
        VID_CLIPPER_ENTER_STATE(VID_CLIPPER_STATE_IDLE);
        if (mpl_clipper_p)
        {
            mpl_clipper_p->destroy(mpl_clipper_p);
            mpl_clipper_p = NULL;
            clipper_alloc_mem = NULL;
            clipper_free_mem = NULL;
        }
    }

    result = med_error_to_result_enum(mplResult);
    vid_set_result(result, __LINE__);
    
    VID_SET_EVENT(VID_EVT_CLOSE);
}


void* vid_clipper_mpl_mem_alloc_cb(mpl_clipper_client_t *prClient, kal_uint32 u4Size, med_mem_type_enum eType, char* pau1File, long u4Line)
{
    void* mem_p = NULL;
    
    if (clipper_alloc_mem)
    {
        if (eType == MED_MEM_NONCACHE)
            mem_p = clipper_alloc_mem((kal_uint8)MED_EXT_MEMORY_TYPE_NONCACHEABLE, u4Size, pau1File, u4Line);
        else if(eType == MED_MEM_CACHE)
            mem_p = clipper_alloc_mem((kal_uint8)MED_EXT_MEMORY_TYPE_CACHEABLE, u4Size, pau1File, u4Line);
    }
    else
        ASSERT(0);

    return mem_p;
}


void vid_clipper_mpl_mem_free_cb(mpl_clipper_client_t *prClient, void** p, med_mem_type_enum eType, char* pau1File, long u4Line)
{
    if (clipper_free_mem)
        clipper_free_mem((kal_uint8)eType, p, pau1File, u4Line);
    else
        ASSERT(0);
}


void vid_clipper_mpl_event_cb(mpl_clipper_client_t *client_p, mpl_clipper_event_t event, media_error_t result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 med_event = 0; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event == MPL_CLIPPER_EVENT_OPEN)
        med_event = VID_CLIP_EVT_OPEN;
    else if (event == MPL_CLIPPER_EVENT_START)
        med_event = VID_CLIP_EVT_START;
    else if (event == MPL_CLIPPER_EVENT_SAVE)
        med_event = VID_CLIP_EVT_SAVE;
    else if (event == MPL_CLIPPER_EVENT_STOP)
        med_event = VID_CLIP_EVT_STOP;
    else if (event == MPL_CLIPPER_EVENT_CLOSE)
        med_event = VID_CLIP_EVT_CLOSE;
    else
        ASSERT(0);
    
    vid_send_clip_event_ind(med_event, (kal_int32)result);

}



/*****************************************************************************
 * FUNCTION
 *  vid_clipper_open_req_hdlr
 * DESCRIPTION
 *  This function is to handle clipper start operation.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_clipper_open_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mpl_clipper_client_t mpl_clipper_client;
    media_vid_clip_open_req_struct *req_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_clip_context_p->src_mod = ilm_ptr->src_mod_id;
    req_p = (media_vid_clip_open_req_struct*) ilm_ptr->local_para_ptr;
    
    if (VID_CLIPPER_IN_STATE(VID_CLIPPER_STATE_IDLE))
    {
        clipper_alloc_mem = req_p->alloc_mem;
        clipper_free_mem = req_p->free_mem;
        
        mpl_clipper_client.on_event = vid_clipper_mpl_event_cb;
        mpl_clipper_client.mem_alloc_func = vid_clipper_mpl_mem_alloc_cb;
        mpl_clipper_client.mem_free_func = vid_clipper_mpl_mem_free_cb;

        mpl_clipper_p = construct_media_clipper(&mpl_clipper_client);

        if (mpl_clipper_p)
        {
            vid_set_result(MED_RES_OK, __LINE__);
            VID_CLIPPER_ENTER_STATE(VID_CLIPPER_STATE_READY);
        }
        else
            vid_set_result(MED_RES_FAIL, __LINE__);
    }      
    else
    {
        vid_set_result(MED_RES_FAIL, __LINE__);
    }
    VID_SET_EVENT(VID_EVT_OPEN);
}



/*****************************************************************************
 * FUNCTION
 *  vid_clipper_start_req_hdlr
 * DESCRIPTION
 *  This function is to handle clipper start operation.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_clipper_prepare_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_clip_prepare_req_struct *req_p;
    mpl_clipper_open_t OpenStruct;
    kal_int32 result = MED_RES_FAIL;
    media_error_t mplResult;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_clip_context_p->src_mod = ilm_ptr->src_mod_id;
    req_p = (media_vid_clip_prepare_req_struct*) ilm_ptr->local_para_ptr;

    if (VID_CLIPPER_IN_STATE(VID_CLIPPER_STATE_READY))
    {
        mplResult = mpl_clipper_p->get_default(mpl_clipper_p, MPL_CLIPPER_OPEN_PARAM, &OpenStruct, sizeof(mpl_clipper_open_t));
        
        OpenStruct.pau2SrcPath = (kal_wchar*)req_p->src_filepath;
        OpenStruct.pau2DstPath = (kal_wchar*)req_p->dst_filepath;
        OpenStruct.pau2WorkingPath = (kal_wchar*)req_p->work_filepath;
        OpenStruct.u4StartTime = req_p->start_time; //ms
        OpenStruct.u4EndTime = req_p->end_time; //ms  

        mplResult = mpl_clipper_p->open(mpl_clipper_p, &OpenStruct);

        if (mplResult == MED_S_ASYNC)
        {
            result = MED_RES_OK;
            VID_CLIPPER_ENTER_STATE(VID_CLIPPER_STATE_OPENING);
        }
        else
        {
            result = med_error_to_result_enum(mplResult);
        }
    }

    vid_set_result(result, __LINE__);
    VID_SET_EVENT(VID_EVT_BLOCK);
    
}




/*****************************************************************************
 * FUNCTION
 *  vid_clipper_start_req_hdlr
 * DESCRIPTION
 *  This function is to handle clipper start operation.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_clipper_start_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_FAIL;
    media_error_t mplResult;
    media_vid_clip_start_req_struct *req_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (VID_CLIPPER_IN_STATE(VID_CLIPPER_STATE_OPENED))
    {
        vid_clip_context_p->src_mod = ilm_ptr->src_mod_id;
        req_p = (media_vid_clip_start_req_struct*) ilm_ptr->local_para_ptr;

        vid_clip_context_p->seq_num = req_p->seq_num;
        
        mplResult = mpl_clipper_p->start(mpl_clipper_p);

        if (mplResult == MED_S_ASYNC)
        {
            result = MED_RES_OK;
            VID_CLIPPER_ENTER_STATE(VID_CLIPPER_STATE_STARTING);
        }
        else
            result = med_error_to_result_enum(mplResult);
    }

    vid_set_result(result, __LINE__);
    
    if (result != MED_RES_OK)
        VID_SET_EVENT(VID_EVT_START);
    
}


/*****************************************************************************
 * FUNCTION
 *  vid_clipper_stop_req_hdlr
 * DESCRIPTION
 *  This function is to handle clipper stop operation.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_clipper_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_FAIL;
    media_error_t mplResult;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (VID_CLIPPER_IN_STATE(VID_CLIPPER_STATE_STARTED))
    {
        mplResult = mpl_clipper_p->cancel(mpl_clipper_p);
        
        if (mplResult == MED_S_ASYNC)
        {
            result = MED_RES_OK;
            VID_CLIPPER_ENTER_STATE(VID_CLIPPER_STATE_STOPPING);
        }
        else
            result = med_error_to_result_enum(mplResult);
    }

    vid_set_result(result, __LINE__);
    
    if (result != MED_RES_OK)
        VID_SET_EVENT(VID_EVT_STOP);   
    
}


/*****************************************************************************
 * FUNCTION
 *  vid_clipper_close_req_hdlr
 * DESCRIPTION
 *  This function is to handle clipper stop operation.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_clipper_close_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_FAIL;
    media_error_t mplResult;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (VID_CLIPPER_IN_STATE(VID_CLIPPER_STATE_STOPPED) || 
        VID_CLIPPER_IN_STATE(VID_CLIPPER_STATE_OPENING) || 
        VID_CLIPPER_IN_STATE(VID_CLIPPER_STATE_OPENED))
    {
        mplResult = mpl_clipper_p->close(mpl_clipper_p);

        if (mplResult == MED_S_ASYNC)
        {
            result = MED_RES_OK;
            VID_CLIPPER_ENTER_STATE(VID_CLIPPER_STATE_CLOSING);
        }
        else
            result = med_error_to_result_enum(mplResult);
    }
    else if (VID_CLIPPER_IN_STATE(VID_CLIPPER_STATE_READY))
    {
        VID_CLIPPER_ENTER_STATE(VID_CLIPPER_STATE_IDLE);
        if (mpl_clipper_p)
        {
            mpl_clipper_p->destroy(mpl_clipper_p);
            mpl_clipper_p = NULL;
            clipper_alloc_mem = NULL;
            clipper_free_mem = NULL;
        }

        vid_set_result(MED_RES_OK, __LINE__);
        VID_SET_EVENT(VID_EVT_CLOSE);
        return;
    }

    vid_set_result(result, __LINE__);
    
    if (result != MED_RES_OK)
        VID_SET_EVENT(VID_EVT_CLOSE);  
}


/*****************************************************************************
 * FUNCTION
 *  vid_clipper_get_param_req_hdlr
 * DESCRIPTION
 *  This function is to handle clipper get parmeter operation.
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_clipper_get_param_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_clip_get_param_req_struct *req_p;
    kal_int32 result = MED_RES_FAIL;
    media_error_t mplResult;
    kal_int32 value;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_vid_clip_get_param_req_struct*) ilm_ptr->local_para_ptr;

    if (mpl_clipper_p)
    {    
        if (req_p->param_id == MPL_CLIPPER_PARAM_CURR_PROGRESS)
        {
            mplResult = mpl_clipper_p->get_param(mpl_clipper_p, MPL_CLIPPER_PARAM_CURR_PROGRESS, (void*)&value);
            *req_p->value = value;
        }
    }

    VID_SET_EVENT(VID_EVT_BLOCK);
}


/*****************************************************************************
 * FUNCTION
 *  vid_clipper_event_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void vid_clipper_event_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_clip_event_ind_struct *req_p;
    media_error_t mplResult;
    kal_uint32 event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_vid_clip_event_ind_struct*) ilm_ptr->local_para_ptr;
    mplResult = (media_error_t)req_p->cause;
    event = req_p->event;
    
    if (event == VID_CLIP_EVT_OPEN)
        vid_clipper_mpl_open_hdlr(mplResult);
    else if (event == VID_CLIP_EVT_START)
        vid_clipper_mpl_start_hdlr(mplResult);
    else if (event == VID_CLIP_EVT_STOP)
        vid_clipper_mpl_stop_hdlr(mplResult);
    else if (event == VID_CLIP_EVT_SAVE)
        vid_clipper_mpl_save_hdlr(mplResult);    
    else if (event == VID_CLIP_EVT_CLOSE)
        vid_clipper_mpl_close_hdlr(mplResult);
    
}

#endif /* __MED_VID_CLIP_MOD__ */
#endif /* MED_NOT_PRESENT */
