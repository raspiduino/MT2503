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
 * AlarmInterface.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements alarm interface for other AP
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
    #include "MMI_features.h"
/*****************************************************************************
* Header files
*****************************************************************************/
#include "AlarmSrvGprot.h"
#include "AlarmProt.h"
#include "AlarmDef.h"
#include "AlarmGProt.h"
#include "AlarmFrameworkProt.h"

#include "HomeScreenOp11V32Gprot.h"
#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
#endif
#endif
#include "Gpiosrvgprot.h"
    #include "MMIDataType.h"
    #include "custom_mmi_default_value.h"
    #include "stack_msgs.h"
    #include "mmi_frm_events_gprot.h"
    #include "mmi_msg_struct.h"
    #include "mmi_frm_queue_gprot.h"
    #include "app_ltlcom.h"
    #include "stack_config.h"
    #include "app_datetime.h"
    #include "mmi_frm_input_gprot.h"
    #include "Unicodexdcl.h"
    #include "MMI_common_app_trc.h"
    #include "DebugInitDef_Int.h"
    #include "kal_trace.h"
    #include "string.h"
    #include "mmi_frm_mem_gprot.h"
    #include "DateTimeType.h"
    #include "FileMgrSrvGProt.h"
    #include "fs_type.h"
    #include "mmi_frm_nvram_gprot.h"
    #include "kal_general_types.h"
    #include "ps_public_struct.h"
    #include "mmi_common_app_trc.h"
    #include "kal_public_api.h"
    #include "HomeScreenOp11V32Def.h"
    #include "mmi_rp_app_alarm_def.h"
    #include "mmi_frm_scenario_gprot.h"
	#include "mmi_rp_srv_alarm_def.h"
#include "AlarmSrvGprot.h"

/*****************************************************************************
* Typedef  
*****************************************************************************/

/*****************************************************************************
 * Define
 *****************************************************************************/

/*****************************************************************************
 * Global Variables 
 *****************************************************************************/

/*****************************************************************************
 * Local function 
 *****************************************************************************/
static U8 mmi_alm_get_active_alms(void);

#ifndef __MMI_DEV_NEW_SLIM__
/*****************************************************************************
 * FUNCTION
 *  AlmTimeEditorCallBack
 * DESCRIPTION
 *  Callback function for inline time editor.
 * PARAMETERS
 *  string_buffer       [IN/OUT]        Buffer to store the result of time
 *  hours_buffer        [IN]            Buffer to store hour string
 *  min_buffer          [IN]            Buffer to store minute string
 *  AM_PM_flag          [IN]            Flag to indicate the time format of time string
 * RETURNS
 *  void
 *****************************************************************************/
void AlmTimeEditorCallBack(U8 *string_buffer, U8 *hours_buffer, U8 *min_buffer, U8 *AM_PM_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((CHAR*) string_buffer, (CHAR*) hours_buffer);
    mmi_ucs2cat((CHAR*) string_buffer, (CHAR*) L":");
    mmi_ucs2cat((CHAR*) string_buffer, (CHAR*) min_buffer);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  AlmIsAnyAlarmActivated
 * DESCRIPTION
 *  To check if there is any activated alarm.
 * PARAMETERS
 *  void
 * RETURNS
 *  0 if no activated alarm; otherwise 0.
 *****************************************************************************/
U8 AlmIsAnyAlarmActivated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_alm_active_alms() != 0)
    {
        return 1;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_set_alarm_state
 * DESCRIPTION
 *  This function is used to set the alarm state
 * PARAMETERS
 *  index        :[out] Alarm index, start from 0, if index is error, it will assert.
 *  state        :[IN]  1 -> turn on, 0 -> turn off
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_set_alarm_state(U8 index, U8 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_alm_node_type *node;
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index < NUM_OF_ALM);

    MMI_ALM_TRACE2(MMI_ALM_SET_STATE, index, state);
    
	node = srv_alm_read(index);

    node->State = state;
    node->Snooze = 0;

    srv_alm_write(index, node);

    if (node->State == SET_STATE)
    {
        AlmActivateIndicator();
    }
    else
    {
        if (srv_alm_active_alms() == 0)
        {
            AlmDeactivateIndicator();
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_get_next_alarm
 * DESCRIPTION
 *  This function is used to get the next alarm.
 * PARAMETERS
 *  time    :[OUT] next alarm time.
 *  soonze  :[IN]  whether care about soonze alarm
 * RETURNS
 *  MMI_BOOL    MMI_FALSE means there is no next alarm
 *****************************************************************************/
MMI_BOOL mmi_alm_get_next_alarm(MYTIME *time, MMI_BOOL snooze)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;
    U8 i;
    MYTIME nextTime;
	srv_alm_node_type *node;
	S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(time != NULL);
	if(!snooze)
	{
		for(i = 0; i < NUM_OF_ALM; i++)
		{
		    node = srv_alm_read(i);
			if(node->Snooze != 0 || node->State != 1)
			{
			    continue;
			}
		    ret = srv_reminder_search(SRV_REMINDER_TYPE_ALM, &nextTime, i);
            if(ret == SRV_REMINDER_RET_FAIL)
			{
				continue;
		    }
			
			count++;
			if(count == 1)
			{
			    memcpy(time, &nextTime, sizeof(MYTIME));
			}
			else
			{
				ret = CompareTime(*time, nextTime, NULL);
				if (ret == DT_TIME_GREATER)
			    {
			        memcpy(time, &nextTime, sizeof(MYTIME));
			    }
			}
		}
	}
    else
    {
		for(i = 0; i < NUM_OF_ALM; i++)
		{
		    node = srv_alm_read(i);
			if(node->State != 1)
			{
			    continue;
			}	
		    ret = srv_reminder_search(SRV_REMINDER_TYPE_ALM, &nextTime, i);
			if(ret == SRV_REMINDER_RET_FAIL)
			{
				continue;
		    }
			
			count++;
			if(count == 1)
			{
			    memcpy(time, &nextTime, sizeof(MYTIME));
			}
			else
			{
				ret = CompareTime(*time, nextTime, NULL);
				if (ret == DT_TIME_GREATER)
			    {
			        memcpy(time, &nextTime, sizeof(MYTIME));
			    }
			}

		}
    }
	if(count)
	{
		return MMI_TRUE;
	}
	else
	{
		return MMI_FALSE;
	}
}

#if 0
#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_alm_entry_alm_eidt_screen
 * DESCRIPTION
 *  This function is entry alarm edit screen.
 * PARAMETERS
 *  U8      [IN]:   Alarm index from side info
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_entry_alm_eidt_screen(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index < NUM_OF_ALM);
    
    mmi_frm_group_close(GRP_ID_ALM_EDITOR);
    
    g_alm_cntx.CurrHiliteAlarm = index;
    AlmPrepareInlineScreen();
}

#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_ALM_CUSTOMIZE_TONE__
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
		#ifndef __MMI_DEV_NEW_SLIM__
/* under construction !*/
		#else
/* under construction !*/
		#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_ALM_CUSTOMIZE_TONE__ */
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
#endif

#ifdef __MMI_ALM_CUSTOMIZE_TONE__
/*****************************************************************************
 * FUNCTION
 *  mmi_alm_notify_hdlr
 * DESCRIPTION
 *  This function is to handle all the notification manager's events
 *  
 * PARAMETERS
 *  mmi_event_struct    [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/ 
#ifndef __MMI_ALARM_SLIM2__
mmi_ret mmi_alm_notify_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	srv_fmgr_notification_adv_action_event_struct *fmgr_adv;
	srv_fmgr_notification_format_event_struct *format_evt;
	MMI_BOOL found;
	alm_nvram_struct *node;
	U8 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	MMI_ALM_TRACE0(MMI_ALM_FMGR_NOTIFY);
    switch(evt->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT:
        {
            format_evt = (srv_fmgr_notification_format_event_struct*)evt;
	
			for (i = 0; i < NUM_OF_ALM; i++)
			{
				node = srv_alm_read(i);	
				if ((node->AudioOptionValue == ALARM_TONE_FILE) &&
					(format_evt->drv_letter == node->tone_path[0]))
				{
					MMI_ALM_TRACE1(MMI_ALM_FMGR_NOTIFY_RESET, i);
			#ifndef __MMI_DEV_NEW_SLIM__
					node->AudioOptionValue = mmi_alm_default_ring_id();
			#else
					node->AudioOptionValue = ALARM_DEFAULT_RING_ID;
			#endif
					node->AudioOption = ALM_AUDIO_OPTIONS_TONE;
					node->tone_path[0] = 0;
					node->tone_path[1] = 0;
	
					srv_alm_write(i, node);
				}
			}

            break;
        }
        case EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION:
        {
			fmgr_adv = (srv_fmgr_notification_adv_action_event_struct*)evt;  
	if(fmgr_adv->state != SRV_FMGR_NOTIFICATION_STATE_AFTER || 
	   fmgr_adv->action == SRV_FMGR_NOTIFICATION_ACTION_COPY ||
	   fmgr_adv->action == SRV_FMGR_NOTIFICATION_ACTION_CREATE_FOLDER)
	{
		return MMI_RET_OK;
	}
	
	if(fmgr_adv->result < 0)
	{
		return MMI_RET_OK;
	}
	
	MMI_ALM_TRACE1(MMI_ALM_FMGR_NOTIFY_FOLDER, (fmgr_adv->src_fileinfo.attribute & FS_ATTR_DIR));
	
	for (i = 0; i < NUM_OF_ALM; i++)
	{
				node = srv_alm_read(i);	
		if (node->AudioOptionValue == ALARM_TONE_FILE)
		{
			found = MMI_FALSE;		
			if (!(fmgr_adv->src_fileinfo.attribute & FS_ATTR_DIR))
			{
						if (fmgr_adv->src_filepath != NULL &&
							mmi_ucs2cmp((const CHAR *)node->tone_path, (const CHAR *)fmgr_adv->src_filepath) == 0)
				{
					found = MMI_TRUE;
				}
			}
			else
			{
				if (mmi_ucs2str((const CHAR *)node->tone_path, (const CHAR *)fmgr_adv->src_filepath) != NULL)
				{
					found = MMI_TRUE;
				}
			}
			
			MMI_ALM_TRACE1(MMI_ALM_FMGR_NOTIFY_RESET, i);

			if (found)
			{
		#ifndef __MMI_DEV_NEW_SLIM__
				node->AudioOptionValue = mmi_alm_default_ring_id();
		#else
				node->AudioOptionValue = ALARM_DEFAULT_RING_ID;
		#endif
				node->AudioOption = ALM_AUDIO_OPTIONS_TONE;
				node->tone_path[0] = 0;
				node->tone_path[1] = 0;

						srv_alm_write(i, node);
			}
		}
	}
	
			break;
        }
		
		default:
			break;
		
	}

	
	return MMI_OK;
}
#endif
#endif /* __MMI_ALM_CUSTOMIZE_TONE__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_clam_evt_hdlr
 * DESCRIPTION
 *  This function is to clam event
 *  
 * PARAMETERS
 *  mmi_event_struct    [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/ 
mmi_ret mmi_alm_clam_evt_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	if (evt->evt_id == EVT_ID_GPIO_CLAM_CLOSE)
	{
		AlmSnoozeHandler();
	}
	else if (evt->evt_id == EVT_ID_GPIO_CLAM_OPEN)
	{
		mmi_alm_stop_tone();
	}

	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_srv_alm_op_hdlr
 * DESCRIPTION
 *  This function is alarm srv add/delete/edit event handler
 *  
 * PARAMETERS
 *  mmi_event_struct    [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/ 
mmi_ret mmi_alm_srv_alm_op_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	srv_alm_op_evt_struct *op_evt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	if (evt->evt_id == EVT_ID_SRV_ALM_OP)
	{
		op_evt_p = (srv_alm_op_evt_struct *)evt;
		switch(op_evt_p->operation)
		{
		    case SRV_ALM_OP_ADD:
			{
			    AlmActivateIndicator();
		#if 0
	        #if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/* under construction !*/
	        #endif
	        #endif
				break;
		    }
			
			case SRV_ALM_OP_DELETE:
			{
				if (g_alm_cntx.active_alm_idx == op_evt_p->index)
			    {
					AlmStopHandler();
			    }

			    if (srv_alm_active_alms() == 0)
			    {
			        AlmDeactivateIndicator();
			    }
				break;
			}
	#ifndef __MMI_DEV_NEW_SLIM__		
			default:
			{
				break;
			}
	#endif
		}
	}
	return MMI_RET_OK;
}

