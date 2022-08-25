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
 *
 * Filename:
 * ---------
 * fmr_main.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implements layer1 speech component task 
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*************************************************************************
* Include Statements
 *************************************************************************/
#include "stack_msgs.h"
#include "app_ltlcom.h"       /* Task message communiction */

#include "syscomp_config.h"
#include "task_config.h"      /* Task creation */
#include "kal_general_types.h"
#include "stack_config.h"
#include "kal_public_api.h"
//#include "kal_internal_api.h"
#include "stack_ltlcom.h"
#include "kal_public_defs.h"
#include "fmr_main.h"



/*************************************************************************
* Function declaration
 *************************************************************************/
kal_bool fmradio_create(comptask_handler_struct **handle);
static void fmradio_task_main(task_entry_struct * task_entry_ptr);
#if defined(__FM_RADIO_RDS_SUPPORT__) || defined(MT5192FM) || defined(__CLASSK_CP_SUPPORT__)|| (FM_ESD_RECOVERY == 1)
fm_timer_table_struct fm_timer_table[MAX_NUM_OF_FM_TIMER];
fm_context_struct fm_context;
fm_context_struct *fm_context_p = &fm_context;
//static void fm_start_base_timer(void *base_timer_ptr, kal_uint32 time_out);
//static void fm_stop_base_timer(void *base_timer_ptr);
static void fm_timer_expiry(ilm_struct *ilm_ptr);
static void fm_timer_expiry_callback(void *arg);
#endif
kal_bool FM_TASK_INIT_OK = KAL_FALSE;

/*****************************************************************************
 * FUNCTION
 *  fm_task_init
 * DESCRIPTION
 *  Init GPS task
 * PARAMETERS
 *  task_indx       [IN]    task index             
 * RETURNS
 *  KAL_BOOL
 *****************************************************************************/
#if defined(__FM_RADIO_RDS_SUPPORT__) || defined(MT5192FM) || defined(__CLASSK_CP_SUPPORT__)|| (FM_ESD_RECOVERY == 1)
kal_bool fm_task_init(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fm_context_p->fm_state = FM_POWEROFF_STATE; 
    /* start base timer */
    /*stack_init_timer(&fm_context_p->base_timer, "FMR Base Timer", MOD_FMR);

    fm_context_p->event_scheduler_ptr = new_evshed(
                                            &fm_context_p->base_timer,
                                            fm_start_base_timer,
                                            fm_stop_base_timer,
                                            0,
                                            kal_evshed_get_mem,
                                            kal_evshed_free_mem,
                                            0);*/
	fm_context_p->event_scheduler_ptr = evshed_create("FMR Base Timer", MOD_FMR, 0 , 0);
    FM_TASK_INIT_OK = KAL_TRUE;

    return KAL_TRUE;
}
#endif
/*************************************************************************
* FUNCTION
*  fmr_create
*
* DESCRIPTION
*  This function implements l1sp entity's create handler.
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool fmradio_create(comptask_handler_struct **handle)
{
   static const comptask_handler_struct fmr_handler_info =
   {
      fmradio_task_main,     /* task entry function */
#if defined(__FM_RADIO_RDS_SUPPORT__) || defined(MT5192FM) || defined(__CLASSK_CP_SUPPORT__)|| (FM_ESD_RECOVERY == 1)
      fm_task_init,          /* task initialization function */
#else
      NULL,          /* task initialization function */
#endif
      NULL,          /* task configuration function */
      NULL,          /* task reset handler */
      NULL           /* task termination handler */
   };

   *handle = (comptask_handler_struct *)&fmr_handler_info;
   return KAL_TRUE;
}
#if defined(__FM_RADIO_RDS_SUPPORT__) || defined(MT5192FM) || defined(__CLASSK_CP_SUPPORT__) || (FM_ESD_RECOVERY == 1)
#if 0
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
#endif
/*****************************************************************************
 * FUNCTION
 *  fm_timer_expiry
 * DESCRIPTION
 * 
 * PARAMETERS
 *  ilm_ptr                
 * RETURNS
 *  void
 *****************************************************************************/
static void fm_timer_expiry(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    //if (stack_is_time_out_valid(&fm_context_p->base_timer))
    //{
        evshed_timer_handler(fm_context_p->event_scheduler_ptr);
    //}
    //stack_process_time_out(&fm_context_p->base_timer);

}
/*****************************************************************************
 * FUNCTION
 *  fm_timer_expiry_callback
 * DESCRIPTION
 *  timer exiry callback
 * PARAMETERS
 *  arg     [IN]   callback function parameter   
 * RETURNS
 *  void
 *****************************************************************************/
static void fm_timer_expiry_callback(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *timer_id = (kal_uint8*) arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((kal_uint32) timer_id < (kal_uint32) MAX_NUM_OF_FM_TIMER)
    {
        fm_timer_table[(kal_uint32) (timer_id)].event_id = NULL;
        (fm_timer_table[(kal_uint32) (timer_id)].callback_func) (fm_timer_table[(kal_uint32) (timer_id)].arg);
    }
}
/*****************************************************************************
 * FUNCTION
 *  fm_start_timer
 * DESCRIPTION
 *  start timer
 * PARAMETERS
 *  timer_id            [IN]      timer id  
 *  period              [IN]       period 
 *  timer_expiry        [IN]    delay time in ticks    
 *  arg                 [IN]      callback function parameter      
 * RETURNS
 *  void
 *****************************************************************************/
void fm_start_timer(kal_uint8 timer_id, kal_uint32 period, kal_timer_func_ptr timer_expiry, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 temp = period * 13 / 60 + 1;    /* ~= x 1/4.615 */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    fm_timer_table[timer_id].callback_func = timer_expiry;
    fm_timer_table[timer_id].arg = arg;
    fm_timer_table[timer_id].event_id = evshed_set_event(
                                            fm_context_p->event_scheduler_ptr,
                                            (kal_timer_func_ptr) fm_timer_expiry_callback,
                                            (void*)timer_id,
                                            temp /** KAL_TICKS_10_MSEC */ );
}


/*****************************************************************************
 * FUNCTION
 *  fm_stop_timer
 * DESCRIPTION
 *  stop timer
 * PARAMETERS
 *  timer_id        [IN]    timer id    
 * RETURNS
 *  void
 *****************************************************************************/
void fm_stop_timer(kal_uint8 timer_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fm_timer_table[timer_id].event_id != NULL)
    {
        evshed_cancel_event(fm_context_p->event_scheduler_ptr, &(fm_timer_table[timer_id].event_id));
        fm_timer_table[timer_id].event_id = NULL;
    }
}
#endif
/*****************************************************************************
 * FUNCTION
 *  fmradio_task_main
 * DESCRIPTION
 *  stop timer
 * PARAMETERS
 *  timer_id        [IN]    timer id    
 * RETURNS
 *  void
 *****************************************************************************/
static void fmradio_task_main(task_entry_struct * task_entry_ptr)
{
   ilm_struct current_ilm;
   kal_uint32 my_index;     

   kal_get_my_task_index(&my_index);     
   stack_set_active_module_id(my_index, MOD_FMR);
#if (defined(FM_RADIO_ENABLE))
   #ifdef __MTK_TARGET__      
   FMR_Init();
   #endif
#endif
#if (defined(MT6250FM))
#if !defined(IC_MODULE_TEST)/*don't need in SLT*/
	FMDrv_SetRCCal();
#endif
#endif
   while(1)
   {
      receive_msg_ext_q_for_stack(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
      
      switch(current_ilm.msg_id)
      {
#if defined(__FM_RADIO_RDS_SUPPORT__) || defined(MT5192FM) || defined(__CLASSK_CP_SUPPORT__)|| (FM_ESD_RECOVERY == 1)

	   case MSG_ID_TIMER_EXPIRY:
	        fm_timer_expiry(&current_ilm);
	   break;
#endif
#if defined(__FM_RADIO_RDS_SUPPORT__)
	   case MSG_ID_FMR_RDS_IND:
	        FMR_EINTChk();
               FMR_RDS_ChkEvent(NULL);
	   break;
#endif
      	   case MSG_ID_FMR_START:
          break;
	   case MSG_ID_FMR_HWSEARCH_IND:
	   	#ifdef FM_RADIO_ENABLE
	   	FMR_ChkSearchStop();
	   	#endif
	   break;
#if defined(__FM_RADIO_RDS_SUPPORT__)
#if (defined(MT6616) && defined(FM_INTERFACE_HCI)) 
          case MSG_ID_UART_READY_TO_READ_IND :
		FMR_HCI_Event_Hdlr(1);     
              break;
          case MSG_ID_UART_READY_TO_WRITE_IND :
		FMR_HCI_Event_Hdlr(0);
		break;
#endif			  
#endif
#if (defined(MT6626))
       /*case MSG_ID_BT_FORCE_RESET_START:
	   	    FMR_BT_Do_Chip_Force_Reset();
	   break;*/

	   case MSG_ID_BT_FORCE_RESET_END:
	   	    FMR_BT_Do_Chip_Force_Reset_Done();
       break;
#endif
	   default:
	   break;
      }
      free_ilm(&current_ilm);	  
   }   
}
