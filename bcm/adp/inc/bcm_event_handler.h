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
 * comm_post_event.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for post Events.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef BCM_EVENT_HANDLER_H
#define BCM_EVENT_HANDLER_H

#include "bcmadp.h"
#include "comm_post_event.h"


/***************************************************************************** 
* Define
*****************************************************************************/
#define BCM_PROTOCOL_EVENT_MAX_COUNT (128 + 30)

#define MMI_RET_STOP_PROTOCOL  1

	 
/***************************************************************************** 
* Typedef 
*****************************************************************************/

typedef enum
{
    BCM_PE_USED_SLOT,
    BCM_PE_EMPTY_SLOT
}bcm_protocol_event_slot_type;

typedef mmi_proc_func  PsFuncPtr;

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

extern void bcm_set_protocol_event(kal_uint32 eventID,mmi_proc_func funcPtr,MMI_BOOL isMultiHandler);

extern void bcm_clear_protocol_event_handler(kal_uint32 eventID,mmi_proc_func funcPtr);

extern void bcm_clear_protocol_event_handler_all(kal_uint32 eventID);

extern kal_bool bcm_execute_protocol_event_handler(kal_uint32 eventID,void *local_param, module_type src_mod);

#define SetProtocolEventHandler(_arg0, _arg1)  bcm_set_protocol_event_handler(_arg1, (mmi_proc_func)_arg0, MMI_FALSE)
#define mmi_frm_set_protocol_event_handler     bcm_set_protocol_event_handler
#define ClearProtocolEventHandler(event)       bcm_clear_protocol_event_handler(event,NULL)     
#define mmi_frm_clear_protocol_event_handler   bcm_clear_protocol_event_handler


extern mmi_proc_func bcm_get_protocol_event_handler(
				kal_uint32 eventID);


#endif /* COMM_POST_EVENT_H */ 




