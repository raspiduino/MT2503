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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   bitstream_main.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains BITSTREAM main procedures.
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifdef WIN32
#include <stdio.h>
#endif 

/* KAL - RTOS Abstraction Layer */
#include "kal_release.h"

/* Task Message Communication */
//#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* local/peer struct */
//#include "stack_ltlcom.h"

/* Task Management */
//#include "syscomp_config.h"
//#include "task_config.h"

/* Timer Management  */
//#include "stacklib.h"
//#include "event_shed.h" /* event schedulet */
//#include "stack_timer.h"

//#include "app_buff_alloc.h"     /* buffer management API */
//#include "lcd_cqueue.h" /* circular queue */
//#include "app2soc_struct.h"     /* interface with Applications */

//#include "stack_utils.h"

//#include "kal_trace.h"

#include "med_global.h"
//#include "med_struct.h"

#ifdef __MED_BITSTREAM_MOD__

#include "bitstream_main.h"

#include "kal_general_types.h"

/* 
 * Global variables
 */
bitstream_context_struct bitstream_cntx;
bitstream_context_struct *bitstream_cntx_p = &bitstream_cntx;

/*****************************************************************************
 * FUNCTION
 *  bitstream_init
 * DESCRIPTION
 *  initiation function for bitstream
 * PARAMETERS
 *  void
 * RETURNS
 * TRUE
 *****************************************************************************/
kal_bool bitstream_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_mem_set(bitstream_cntx_p, 0, sizeof(bitstream_context_struct));
    bitstream_cntx_p->bs_event = kal_create_event_group("bitstream_events");

    bitstream_audio_init();

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  bitstream_main
 * DESCRIPTION
 *  Main ilm handler for BITSTREAM
 * PARAMETERS
 *  ilm_ptr     [IN]        Ilm pointer
 * RETURNS
 *  void
 *****************************************************************************/
void bitstream_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_MEDIA_BITSTREAM_AUDIO_OPEN_REQ:
            bitstream_audio_open_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_BITSTREAM_AUDIO_CLOSE_REQ:
            bitstream_audio_close_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_BITSTREAM_AUDIO_GET_BUFFER_STATUS_REQ:
            bitstream_audio_get_buffer_status_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_BITSTREAM_AUDIO_PUT_DATA_REQ:
            bitstream_audio_put_data_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_BITSTREAM_AUDIO_PUT_FRAME_REQ:
            bitstream_audio_put_frame_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_BITSTREAM_AUDIO_START_REQ:
            bitstream_audio_start_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_BITSTREAM_AUDIO_STOP_REQ:
            bitstream_audio_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_BITSTREAM_AUDIO_FINISHED_REQ:
            bitstream_audio_finished_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_BITSTREAM_AUDIO_GET_PLAY_TIME_REQ:
            bitstream_audio_get_play_time_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_BITSTREAM_AUDIO_DRIVER_EVENT_IND:
            bitstream_audio_driver_event_ind_hdlr(ilm_ptr);
            break;
        /* Bitstream record */
        case MSG_ID_MEDIA_BITSTREAM_RECORD_OPEN_REQ:
            bitstream_record_open_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_BITSTREAM_RECORD_CLOSE_REQ:
            bitstream_record_close_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_BITSTREAM_RECORD_START_REQ:
            bitstream_record_start_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_BITSTREAM_RECORD_STOP_REQ:
            bitstream_record_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_BITSTREAM_RECORD_SET_REQ:
            bitstream_record_set_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_BITSTREAM_RECORD_GET_REQ:
            bitstream_record_get_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_BITSTREAM_RECORD_DRIVER_EVENT_IND:
            bitstream_record_driver_event_ind_hdlr(ilm_ptr);
            break;
        default:
            ASSERT(0);
    }
}

#endif /* __MED_BITSTREAM_MOD__ */


