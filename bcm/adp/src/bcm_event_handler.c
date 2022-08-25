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
* bcm_event_handler.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   This file is intends for protocol event handler .
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
*
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "Device.h"
#include "kal_general_types.h"
#include "stack_msgs.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "string.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stdio.h"
#include "bcm_event_handler.h"
#include "bcm_trc.h"
#include "Bcm_btcmUtility.h"


/*****************************************************************************
 * Global Variable                                                             
 *****************************************************************************/

/*protocol event table*/
static kal_uint32 bcm_protocol_event_id_tbl[BCM_PROTOCOL_EVENT_MAX_COUNT];
static mmi_proc_func bcm_protocol_event_proc_tbl[BCM_PROTOCOL_EVENT_MAX_COUNT];
static MMI_BOOL bcm_protocol_event_multihdlr_tbl[BCM_PROTOCOL_EVENT_MAX_COUNT];

static kal_uint16 last_used_event_slot; // last slot + 1
static kal_uint16 first_empty_slot;
static module_type src_mod_id;


/*****************************************************************************
 * Extern data and function                                                             
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  bcm_protocol_event_find_slot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS VALUES
 *  void
 *****************************************************************************/
static kal_uint16 bcm_protocol_event_find_slot(bcm_protocol_event_slot_type type)
{
    kal_uint16 i;
    kal_uint16 ret = BCM_PROTOCOL_EVENT_MAX_COUNT +1;
    
    if(type == BCM_PE_USED_SLOT)
    {
        for(i = 0; i < BCM_PROTOCOL_EVENT_MAX_COUNT; i++)
        {
            if(bcm_protocol_event_id_tbl[i] != 0)
               ret = i;
        }
    }
    else if(type == BCM_PE_EMPTY_SLOT)
    {
        for(i = 0; i < BCM_PROTOCOL_EVENT_MAX_COUNT; i++)
        {
            if(bcm_protocol_event_id_tbl[i] == 0)
            {
               ret = i;
               break;
            }
        }
    }
    
    ASSERT(ret != BCM_PROTOCOL_EVENT_MAX_COUNT +1);
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  bcm_protocol_event_set_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS VALUES
 *  void
 *****************************************************************************/
static void bcm_protocol_event_set_value(kal_uint16 index, kal_uint32 eventID,
    mmi_proc_func funcPtr, MMI_BOOL isMultiHandler)
{
    bcm_protocol_event_id_tbl[index] = eventID;
    bcm_protocol_event_proc_tbl[index] = funcPtr;
    bcm_protocol_event_multihdlr_tbl[index] = isMultiHandler;
}

module_type bcm_protocol_event_get_src_mod_id(void)
{
    return src_mod_id;
}

/*****************************************************************************
 * FUNCTION
 *  bcm_protocol_event_queue_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS VALUES
 *  void
 *****************************************************************************/
void bcm_set_protocol_event_handler(kal_uint32 eventID,mmi_proc_func funcPtr,
    MMI_BOOL isMultiHandler)
{
  
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    kal_uint16 i;
    kal_uint8 found = 0;
    kal_bool multihdlr = KAL_TRUE;
    kal_bool already_set = KAL_FALSE;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    if(isMultiHandler == MMI_TRUE)
    {
        for (i = 0; i < last_used_event_slot; i++)
        {
            if(bcm_protocol_event_id_tbl[i] == eventID)
            {
                if(bcm_protocol_event_proc_tbl[i] != funcPtr)
                {
                    found ++;
                    multihdlr = multihdlr && bcm_protocol_event_multihdlr_tbl[i];
                }
                else
                {
                    already_set = KAL_TRUE;
                    break;
                }
            }
        }
        if(found != 0 && multihdlr == KAL_FALSE)
        {
            ASSERT(0);
        }
        if(!already_set)
        {
            bcm_protocol_event_set_value(first_empty_slot,eventID,funcPtr,isMultiHandler);
            if(first_empty_slot == last_used_event_slot)
            {
                first_empty_slot ++;
                last_used_event_slot ++;
            }
            else
            {
                first_empty_slot = bcm_protocol_event_find_slot(BCM_PE_EMPTY_SLOT);
            }
        }
    }
    else
    {
        for (i = 0; i < last_used_event_slot; i++)
        {
            if(bcm_protocol_event_id_tbl[i] == eventID)
            {
                if(bcm_protocol_event_proc_tbl[i] != funcPtr)
                {
                    ASSERT(0);
                }
                else
                {
                    already_set = KAL_TRUE;
                    break;
                }
            }            
        }
        
        if(!already_set)
        {
            bcm_protocol_event_set_value(first_empty_slot,eventID,funcPtr,isMultiHandler);
            if(first_empty_slot == last_used_event_slot)
            {
                first_empty_slot ++;
                last_used_event_slot ++;
            }
            else
            {
                first_empty_slot = bcm_protocol_event_find_slot(BCM_PE_EMPTY_SLOT);
            }
        }
        
        if(found != 0 && multihdlr == KAL_FALSE)
        {
            ASSERT(0);
        }
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_led_queue_add
* DESCRIPTION
*  init led queue
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void bcm_clear_protocol_event_handler(
				kal_uint32 eventID,
				mmi_proc_func funcPtr)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    kal_uint16 i;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    
    for (i = 0; i < last_used_event_slot; i++)
    {
        if(bcm_protocol_event_id_tbl[i] == eventID)
        {
            if(bcm_protocol_event_proc_tbl[i] == funcPtr)
            {
                bcm_protocol_event_set_value(i,0,NULL,KAL_FALSE);
                break;
            }
        }
    }
    if(i < first_empty_slot)
        first_empty_slot = i;
    
    if(i == last_used_event_slot - 1)
    {
        last_used_event_slot = i;
    }
}

/*****************************************************************************
* FUNCTION
*  bcm_clear_protocol_event_all
* DESCRIPTION
*  init led queue
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void bcm_clear_protocol_event_handler_all(kal_uint32 eventID)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    kal_uint16 i;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	for(i = 0; i< last_used_event_slot; i++)
	{
        if(bcm_protocol_event_id_tbl[i] == eventID)
        {
            bcm_protocol_event_set_value(i,0,NULL,KAL_FALSE);
        }
	}
    
    if(i == last_used_event_slot - 1)
    {
        last_used_event_slot = i;
    }
    
    first_empty_slot = bcm_protocol_event_find_slot(BCM_PE_EMPTY_SLOT);

}

const char* bcm_protocol_event_id_tbl_string[] = 
{
    {"MSG_ID_BT_GATTC_GROUP_START"},
    {"MSG_ID_BT_GATTC_REGISTER_CNF"},
    {"MSG_ID_BT_GATTC_DEREGISTER_REQ"},
    {"MSG_ID_BT_GATTC_DEREGISTER_CNF"},
    {"MSG_ID_BT_GATTC_SCAN_REQ"},
    {"MSG_ID_BT_GATTC_SCAN_RESULT_IND"},
    {"MSG_ID_BT_GATTC_SCAN_CNF"},
    {"MSG_ID_BT_GATTC_SCAN_CANCEL_REQ"},
    {"MSG_ID_BT_GATTC_SCAN_CANCEL_CNF"},
    {"MSG_ID_BT_GATTC_CONNECT_REQ"},
    {"MSG_ID_BT_GATTC_CONNECT_CNF"},
    {"MSG_ID_BT_GATTC_CONNECTED_IND"},
    {"MSG_ID_BT_GATTC_DISCONNECT_REQ"},
    {"MSG_ID_BT_GATTC_DISCONNECT_CNF"},
    {"MSG_ID_BT_GATTC_DISCONNECTED_IND"},
    {"MSG_ID_BT_GATTC_LISTEN_REQ"},
    {"MSG_ID_BT_GATTC_LISTEN_CNF"},
    {"MSG_ID_BT_GATTC_SET_ADV_DATA_REQ"},
    {"MSG_ID_BT_GATTC_SET_ADV_DATA_CNF"},
    {"MSG_ID_BT_GATTC_REFRESH_REQ"},
    {"MSG_ID_BT_GATTC_REFRESH_CNF"},
    {"MSG_ID_BT_GATTC_SEARCH_SERVICE_REQ"},
    {"MSG_ID_BT_GATTC_SEARCH_SERVICE_RESULT_IND"},
    {"MSG_ID_BT_GATTC_SEARCH_SERVICE_CNF"},
    {"MSG_ID_BT_GATTC_GET_INCL_SERVICE_REQ"},
    {"MSG_ID_BT_GATTC_GET_INCL_SERVICE_CNF"},
    {"MSG_ID_BT_GATTC_GET_CHAR_REQ"},
    {"MSG_ID_BT_GATTC_GET_CHAR_CNF"},
    {"MSG_ID_BT_GATTC_GET_DESCR_REQ"},
    {"MSG_ID_BT_GATTC_GET_DESCR_CNF"},
    {"MSG_ID_BT_GATTC_READ_CHAR_REQ"},
    {"MSG_ID_BT_GATTC_READ_CHAR_CNF"},
    {"MSG_ID_BT_GATTC_WRITE_CHAR_REQ"},
    {"MSG_ID_BT_GATTC_WRITE_CHAR_CNF"},
    {"MSG_ID_BT_GATTC_READ_DESCR_REQ"},
    {"MSG_ID_BT_GATTC_READ_DESCR_CNF"},
    {"MSG_ID_BT_GATTC_WRITE_DESCR_REQ"},
    {"MSG_ID_BT_GATTC_WRITE_DESCR_CNF"},
    {"MSG_ID_BT_GATTC_EXEC_WRITE_REQ"},
    {"MSG_ID_BT_GATTC_EXEC_WRITE_CNF"},
    {"MSG_ID_BT_GATTC_REGISTER_NOTIFICATION_REQ"},
    {"MSG_ID_BT_GATTC_REGISTER_NOTIFICATION_CNF"},
    {"MSG_ID_BT_GATTC_DEREGISTER_NOTIFICATION_REQ"},
    {"MSG_ID_BT_GATTC_DEREGISTER_NOTIFICATION_CNF"},
    {"MSG_ID_BT_GATTC_READ_RSSI_REQ"},
    {"MSG_ID_BT_GATTC_READ_RSSI_CNF"},
    {"MSG_ID_BT_GATTC_GET_DEVICE_TYPE_REQ"},
    {"MSG_ID_BT_GATTC_GET_DEVICE_TYPE_CNF"},
    {"MSG_ID_BT_GATTC_CONN_PARAM_UPDATE_REQ"},
    {"MSG_ID_BT_GATTC_CONN_PARAM_UPDATE_CNF"},
    {"MSG_ID_BT_GATTC_SET_ADV_PARAM_REQ"},
    {"MSG_ID_BT_GATTC_SET_ADV_PARAM_CNF"},
    {"MSG_ID_BT_GATTC_START_RESEARCH_SERVICE_IND"},
    {"MSG_ID_BT_GATTC_RESEARCH_SERVICE_IND"},
    {"MSG_ID_BT_GATTC_UPDATE_CONNECTED_INFO"},

    {"MSG_ID_BT_GATTC_NOTIFICATION_IND"}
};
/*****************************************************************************
* FUNCTION
*  mmi_frm_input_event_led_queue_remove
* DESCRIPTION
*  init led queue
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
kal_bool bcm_execute_protocol_event_handler(kal_uint32 eventID,
    void *local_param, module_type src_mod)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    kal_uint16 i;
    kal_bool ret = KAL_FALSE;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    src_mod_id = src_mod;
    for(i = 0; i< last_used_event_slot; i++)
	{
        if(bcm_protocol_event_id_tbl[i] == eventID && bcm_protocol_event_proc_tbl[i] != NULL)
        {
            ret = KAL_TRUE;
#if defined (__BLE_DEBUG_LOG__)
            {
                char testLog[128] = {0};
                sprintf(testLog, "EVENT bcm_execute_protocol_event_handler[%d/%d/%d]%s\r\n", i, BCM_PROTOCOL_EVENT_MAX_COUNT, MSG_ID_BT_GATTC_GROUP_START, bcm_protocol_event_id_tbl_string[i]);
                U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
            }
#endif /* __BLE_DEBUG_LOG__ */

            if(bcm_protocol_event_multihdlr_tbl[i] == KAL_TRUE)
            {
                if(bcm_protocol_event_proc_tbl[i](local_param) != MMI_RET_STOP_PROTOCOL)
                    break;
            }
            else
            {
                bcm_protocol_event_proc_tbl[i](local_param);
                break;
            }
        }
	}

    src_mod_id = 0;
    return ret;
}


