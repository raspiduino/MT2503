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
 * aud_vad .c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary functions of audio manager task.
 *
 * Author:
 * -------
 * 
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/******************************************************************
 * MODULE
 *    AUD_TONE
 * DESCRIPTION
 *    This module defines the tone related function for Audio Manager.
 *  
 ******************************************************************/

#ifdef __VAD_SUPPORT__

/*==== INCLUDES ==========*/

//#include "kal_release.h"
#include "kal_trace.h"
//#include "stack_common.h"
//#include "stack_msgs.h"
//#include "app_ltlcom.h" /* Task message communiction */
//#include "syscomp_config.h"
//#include "task_config.h"        /* Task creation */
//#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
//#include "event_shed.h" /* Event scheduler */
//#include "stack_timer.h"        /* Stack timer */

/* global includes */
#include "l1audio.h"
//#include "device.h"
//#include "nvram_enums.h"
//#include "nvram_struct.h"
//#include "nvram_user_defs.h"
//#include "nvram_data_items.h"
//#include "custom_nvram_editor_data_item.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
//#include "med_struct.h"
//#include "med_api.h"
#include "med_context.h"
#include "aud_main.h"
//#include "med_main.h"
#include "kal_general_types.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

/* VAD Event */
typedef struct
{
    VAD_Event                   event;          /* Event */
    void*                       param;       /* for further use */
} med_aud_vad_event_t;


/*****************************************************************************
 * FUNCTION
 *  aud_is_vad_on
 * DESCRIPTION
 *  This function is used to check whether VAD is on or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool aud_is_vad_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_bool on;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	on = VAD_IsEnable();
	AUD_VAD_FUNC_ENTRY1(AUD_VAD_STATE,on);
    return on;
}

/*****************************************************************************
 * FUNCTION
 *  aud_get_vad_level
 * DESCRIPTION
 *  This function is used to check whether VAD is on or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 aud_get_vad_level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 level;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	level = VAD_GetSensitivity();
	AUD_VAD_FUNC_ENTRY1(AUD_VAD_LEVEL,level);
    return level;
}


/*****************************************************************************
 * FUNCTION
 *  aud_set_vad_level_req_hdlr
 * DESCRIPTION
 *  This function is used to set vad detect level.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_vad_level_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_set_vad_level_req_struct *req_p = (media_set_vad_level_req_struct*) ilm_ptr->local_para_ptr;
	kal_bool result = MEDIA_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	result = VAD_SetSensitivity(req_p->level);
	AUD_VAD_FUNC_ENTRY3(AUD_VAD_SET_LEVEL,VAD_IsEnable(),result,req_p->level);
	
	if(MEDIA_SUCCESS == result)
	    aud_set_vad_result_and_event(KAL_TRUE,AUD_VAD_EVT_SET);
	else
		aud_set_vad_result_and_event(KAL_FALSE,AUD_VAD_EVT_SET);
}

/*****************************************************************************
 * FUNCTION
 *  _aud_vad_media_event_callback_hdlr
 * DESCRIPTION
 *  This function is used to handle the callback events from L1Audio.
 * PARAMETERS
 *  data_p             [IN]       Media event data.
 *  date_len           [IN]       The length of data.
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_vad_media_event_callback_hdlr(void* data_p, kal_uint16 date_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_vad_event_t* vad_event_p = (med_aud_vad_event_t*)data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_VAD_FUNC_ENTRY2(AUD_VAD_EVENT_IND,VAD_IsEnable(),vad_event_p->event);
    /* Post processing */
    switch (vad_event_p->event)
    {
        case VAD_EVENT_ACTIVE:
            /* ACTIVE ,1*/
			aud_send_vad_detect_ind(MOD_MMI,1);
            break;
			
        case VAD_EVENT_INACTIVE:
            /* INACTIVE ,0*/
			aud_send_vad_detect_ind(MOD_MMI,0);
            break;
			
        default:
            /* Invalid event, do nothing*/
            
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_vad_media_event_callback_fct
 * DESCRIPTION
 *  This function is used to receive the callback events from L1Audio.
 * PARAMETERS
 *  param       [IN]          for further use. 
 *  event        [IN]          vad event.
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_vad_media_event_callback_fct(VAD_Event event, void* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_aud_vad_event_t vad_event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	vad_event.event = event;
	vad_event.param = param;
    
    aud_util_proc_in_med_ext(MOD_L1SP,
                             aud_vad_media_event_callback_hdlr,
                             (void*)&vad_event,
                             sizeof(med_aud_vad_event_t));
}


/*****************************************************************************
 * FUNCTION
 *  aud_switch_vad_on_off_req_hdlr
 * DESCRIPTION
 *  This function is used to switch vad on/off.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_switch_vad_on_off_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_switch_vad_on_off_req_struct *req_p = (media_switch_vad_on_off_req_struct*) ilm_ptr->local_para_ptr;
	kal_bool result = MEDIA_SUCCESS;
	aud_keytone_stop();
	aud_tone_stop;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	AUD_VAD_FUNC_ENTRY2(AUD_VAD_PRE_SWITCH_ON_OFF,VAD_IsEnable(),req_p->on);
	if(req_p->on)
	{
	    if(!aud_is_vad_on()) 
	    {
		    result = VAD_Enable(aud_vad_media_event_callback_fct);
	    }
	}
	else
	{   
		if(aud_is_vad_on()) 
	    {
		    result = VAD_Disable();
	    }
	}
	AUD_VAD_FUNC_ENTRY2(AUD_VAD_SWITCH_ON_OFF,VAD_IsEnable(),result);

	if(MEDIA_SUCCESS == result)
	    aud_set_vad_result_and_event(KAL_TRUE,AUD_VAD_EVT_SET);
	else
		aud_set_vad_result_and_event(KAL_FALSE,AUD_VAD_EVT_SET);
}

#endif /* MED_NOT_PRESENT */ 

