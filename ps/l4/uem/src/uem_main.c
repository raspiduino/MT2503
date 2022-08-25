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
 * UEM_MAIN.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for main process.
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/***************************************************************************** 
* Include
*****************************************************************************/
#include "kal_general_types.h"
#include "stack_config.h"
#include "kal_public_api.h"
#include "nvram_data_items.h"

#include "stack_msgs.h"
#include "app_ltlcom.h"

//#include "rtc_sw.h"
#include "med_struct.h"

#include "custom_hw_default.h"
#include "custom_uem.h"

#include "device.h"
#include "uem_context.h"
#include "uem_msg_hdlr.h"
#include "uem_msg_hdlr.h"
#include "uem_utility.h"
#include "uem_proc_cmd.h"

#if defined(__SMART_PHONE_MODEM__) && defined(__MTK_TARGET__)
#include "Ccci.h"
#endif

#include "task_config.h"

/* UEM unit test usage */      
#if defined(TST_INJECTED_EVENT) || defined(__TINY_SYS_AP__)
#include "stdarg.h"      
#include "drvsignals.h"      
#include "tst_sap.h"      
#endif /* TST_INJECTED_EVENT */       

#include "dcl.h"
/***************************************************************************** 
* Extern Functions
*****************************************************************************/
extern void custom_init_hardware_level(void *hw_level_struct);

#if defined(DCM_ENABLE)
extern kal_uint8 DCM_GetHandle( void );
#endif

#if defined(__SMART_PHONE_MODEM__) && defined(__MTK_TARGET__)
extern void uem_ccci_ack_callback(CCCI_BUFF_T *buff_p);
#endif

#if defined(__TINY_SYS_AP__)
extern void csd_get_tst_string_inject(kal_uint8	cmdindex);
#endif
/***************************************************************************** 
* Local Functions Declaration
*****************************************************************************/
static kal_bool uem_init_hardware_data(void);
static void uem_set_longpress_time(kal_uint32 ticks);
static void uem_set_repeat_time(kal_uint32 ticks);
static void uem_set_ctp_init_update_firmware(void);

static void uem_tst_handler(ilm_struct *ilm_ptr);

/***************************************************************************** 
* Global Variables Declaration
*****************************************************************************/
uem_context_struct *g_uem_cntx_p;

kal_uint8 uem_L4c_module_id = 255;
#if defined(DCM_ENABLE)
kal_uint8 uem_dcm_handle;
#endif 

/***************************************************************************** 
* Local Variables Declaration
*****************************************************************************/
static uem_context_struct uem_g_data;

/*****************************************************************************
****************************************************************************** 
* External Funcations 
******************************************************************************
******************************************************************************/
/*****************************************************************************
*   Function 
*      uem_main
*   DESCRIPTION
*      main function of UEM module
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uem_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UEM_FN_ENTRY_LOG(MOD_UEM, FUNC_UEM_MAIN);

    switch (ilm_ptr->msg_id)
    {
            /* DRIVER_EVENTS: */
        case MSG_ID_DRVUEM_KEYPAD_IND:
            uemdrv_keypad_ind_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_DRVUEM_RTC_PERIOD_IND:
            uemdrv_rtc_period_ind_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_AUX_ID:
            uemdrv_aux_id_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;

    #ifdef __USB_ENABLE__
        case MSG_ID_DRVUEM_USBDETECT_IND:
            uemdrv_usb_detect_ind_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_DRVUEM_USBCFG_CNF:
            uemdrv_usb_config_cnf_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
    #endif /* __USB_ENABLE__ */ 

            /* BMT_EVENTS: */
        case MSG_ID_DRVUEM_POWER_ON_IND:
            uemdrv_power_on_ind_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_DRVUEM_PMIC_IND:
            uemdrv_pmic_ind_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_BMT_ADC_MEASURE_DONE_CONF:
            uembmt_adc_measure_done_cnf_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_ADC_ALL_CHANNEL_CONF:
            uemaux_all_channel_conf_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_BMT_LEAVE_PRECHARGE_IND:
            uemdrv_bmt_leave_precharge_ind(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;

            /* L4C_EVENTS: */
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        case MSG_ID_L4CUEM_STARTUP_REQ:
            ueml4c_startup_req_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_L4CUEM_SET_HW_LEVEL_REQ:
            ueml4c_set_hw_level_req_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;

            /* SYSTEM_EVENTS: */
        case MSG_ID_TIMER_EXPIRY:
            uemsys_timer_expiry_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;

            /* NVRAM_EVENTS: */
        case MSG_ID_NVRAM_READ_CNF:
            uemnvm_read_data_cnf_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_NVRAM_WRITE_CNF:
            uemnvm_write_data_cnf_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;

            /* SAT_EVENTS: */
        case MSG_ID_SAT_LANGUAGE_REQ:
            uemsat_language_req_hdlr(ilm_ptr->src_mod_id, ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_SAT_CURRENT_TIME_REQ:
            uemsat_current_time_req_hdlr(ilm_ptr->src_mod_id, ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;

            /* AUD_MED_EVENTS: */
        case MSG_ID_MED_STARTUP_CNF:
            uemaud_startup_cnf_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_MEDIA_AUD_PLAY_FINISH_IND:
            uemaud_play_finish_ind_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_L4CUEM_AUDIO_PLAY_BY_NAME_REQ:
        case MSG_ID_L4CUEM_AUDIO_STOP_BY_NAME_REQ:
            uemaud_playbyname_req_hdlr(ilm_ptr->msg_id, ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_MEDIA_AUD_PLAY_BY_FILE_CNF:
        case MSG_ID_MEDIA_AUD_STOP_CNF:
            ueml4c_playbyname_cnf_hdlr(ilm_ptr->msg_id, ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_L4CUEM_AUDIO_PLAY_BY_STRING_REQ:
        case MSG_ID_L4CUEM_AUDIO_STOP_BY_STRING_REQ:
            uemaud_playbystring_req_hdlr(ilm_ptr->msg_id, ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_MEDIA_AUD_PLAY_BY_STRING_CNF:
        case MSG_ID_MEDIA_AUD_STOP_BY_STRING_CNF:
            ueml4c_playbystring_cnf_hdlr(ilm_ptr->msg_id, ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;

        case MSG_ID_L4CUEM_SET_AUDIO_PROFILE_REQ:
            ueml4c_set_audio_profile_req_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SET_AUDIO_PROFILE_CNF:
            uem_send_msg_to_l4c(MSG_ID_L4CUEM_SET_AUDIO_PROFILE_CNF, ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_L4CUEM_SET_AUDIO_PARAM_REQ:
            ueml4c_set_audio_param_req_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SET_AUDIO_PARAM_CNF:
            uem_send_msg_to_l4c(MSG_ID_L4CUEM_SET_AUDIO_PARAM_CNF, ilm_ptr->local_para_ptr);
            break;

        case MSG_ID_MEDIA_AUD_GET_AUDIO_PARAM_CNF:
            ueml4c_get_audio_param_cnf_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;

		case MSG_ID_L4CUEM_GET_AUDIO_MUTE_STATUS_REQ:
			uem_L4c_module_id = ilm_ptr->src_mod_id;
			ueml4c_get_audio_mute_status_req_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
			
#if defined(__AMRWB_LINK_SUPPORT__)
        case MSG_ID_MEDIA_AUD_GET_AUDIO_WB_INPUT_FIR_PARAM_CNF:
        case MSG_ID_MEDIA_AUD_GET_AUDIO_WB_OUTPUT_FIR_PARAM_CNF:
        case MSG_ID_MEDIA_AUD_GET_AUDIO_WB_MODE_PARAM_CNF:
            ueml4c_get_audio_wb_param_cnf_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SET_AUDIO_WB_INPUT_FIR_PARAM_CNF:
        case MSG_ID_MEDIA_AUD_SET_AUDIO_WB_OUTPUT_FIR_PARAM_CNF:
        case MSG_ID_MEDIA_AUD_SET_AUDIO_WB_MODE_PARAM_CNF:
            ueml4c_set_audio_wb_param_cnf_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
#endif
        case MSG_ID_MEDIA_AUD_GET_AUDIO_PROFILE_CNF:
            ueml4c_get_audio_profile_cnf_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;

        case MSG_ID_MEDIA_AUD_GET_VOLUME_CNF:
            ueml4c_get_volume_cnf_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_GET_MEDIA_MUTE_STATUS_CNF:
            //ueml4c_get_media_mute_status_cnf_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            uem_send_msg_to_l4c(MSG_ID_L4CUEM_GET_AUDIO_MUTE_STATUS_CNF, ilm_ptr->local_para_ptr);
            break;
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        case MSG_ID_L4CL1_EM_RF_TEST_GSM_POWER_SCAN_CNF:
            uemdrv_rf_test_gsm_powerscan_cnf_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;

    #if defined(__SMART_PHONE_MODEM__) && defined(__MTK_TARGET__)
        case MSG_ID_DRVUEM_CCCI_EM_REQ_IND:
            uemdrv_ccci_em_req_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
    #endif /* #if defined(__SMART_PHONE_MODEM__)*/
            /* TST_EVENTS: */
        case MSG_ID_TST_INJECT_STRING:
            uem_tst_handler(ilm_ptr);
            break;
    #ifndef FMT_NOT_PRESENT
        /* New FMT msg*/
        case MSG_ID_MMI_FMT_CALCULATE_DONE:
            uemfmt_calc_done_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
    #endif /* New FMT msg*/
	#ifdef __CLASSK_CP_SUPPORT__
       case MSG_ID_L4AUD_CLASSK_STATE_IND:
            uemaud_state_judge_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
    #endif
        default:
            break;
    }

    UEM_FN_EXIT_LOG(MOD_UEM, FUNC_UEM_MAIN);

    return;
}

/*****************************************************************************
*   Function 
*      uem_init
*   DESCRIPTION
*      init function
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif
kal_bool uem_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret_val = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uem_cntx_p = &uem_g_data;

    /* initial UEM */
    if (g_uem_cntx_p != NULL)
    {
        g_uem_cntx_p->ext_dev_status = EXT_DEV_NONE;
        g_uem_cntx_p->bmt_status.status = PMIC_VBAT_STATUS;
        g_uem_cntx_p->bmt_status.volt = 0;
        g_uem_cntx_p->bmt_status.adc = 0;
        g_uem_cntx_p->bmt_status.disp_level = 0;
        g_uem_cntx_p->bmt_status.last_level = 0;
        g_uem_cntx_p->bmt_status.hit_count = 0;
        g_uem_cntx_p->power_on_mode = POWER_ON_UNINIT;
        g_uem_cntx_p->adc_sche_id = DCL_HANDLE_INVALID;
    #if defined(__CLASSAB_VOLUME_PROTECTION__) || defined(__CLASSK_CP_SUPPORT__)
        g_uem_cntx_p->adc_med_sche_id = DCL_HANDLE_INVALID;
    #endif
        g_uem_cntx_p->incall_state = UEM_CALL_UNKNOW;

        g_uem_cntx_p->acc_prev_state = 0;
        g_uem_cntx_p->acc_latest_state = 0;
        g_uem_cntx_p->acc_progress = 0;

    #ifdef __USB_ENABLE__
        g_uem_cntx_p->usb_msg_src_id = 0;
    #endif 

    #ifndef PLUTO_MMI
        g_uem_cntx_p->usb_out_suspend = 1;
    #endif
	#ifdef __CLASSK_CP_SUPPORT__
        g_uem_cntx_p->aud_vol_flag = 0;
    #endif

#ifdef __SEND_STOP_BEFORE_RF_TEST_REQ__

	    g_uem_cntx_p->is_rf_test_running = UEM_RF_TEST_NOT_RUNNING;
#endif
        uem_timer_init();

    #ifdef __MTK_TARGET__
    #if defined(DCM_ENABLE)
        uem_dcm_handle = DCM_GetHandle();
    #endif 
    #endif /* __MTK_TARGET__ */ 

        uem_set_state(UEM_STATE_INIT);
    }
    else
    {
        ret_val = KAL_FALSE;
    }

#if defined(__SMART_PHONE_MODEM__) && defined(__MTK_TARGET__)
   {
      kal_int32 ret;

      /* Initialize the channel for receving message from AP to Modem */
      //ret = ccci_init(CCCI_UEM_CHANNEL, uem_ccci_ack_callback);
      ret = ccci_owner_init(CCCI_UEM_CHANNEL, task_info_g[mod_task_g[MOD_UEM]].task_id, uem_ccci_ack_callback);
      if (ret != CCCI_SUCCESS) {
          ASSERT(0);
      }

      /* Initialize the channel for sendinf message from Modem to AP. Callback is dummy function */
      //ret = ccci_init(CCCI_UEM_ACK_CHANNEL, uem_ccci_ack_callback);
      ret = ccci_owner_init(CCCI_UEM_ACK_CHANNEL, task_info_g[mod_task_g[MOD_UEM]].task_id, uem_ccci_ack_callback);
      if (ret != CCCI_SUCCESS) {
          ASSERT(0);
      }
   }
#endif

#ifdef __VIBRATION_SPEAKER_SUPPORT__
    custom_uem_set_spkvib_func(uem_gpio_spkvib_enable);
#endif

    /* read UEM data */
    return ret_val;
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

/*****************************************************************************
*   Function 
*      uem_reset
*   DESCRIPTION
*      reset function
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool uem_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret_val = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //uem_init();

    return ret_val;
}

/*****************************************************************************
*   Function 
*      uem_deinit
*   DESCRIPTION
*      deinit function
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool uem_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_set_state(UEM_STATE_UNINIT);
    return KAL_TRUE;
}

/*****************************************************************************
*   Function 
*      uem_startup_process
*   DESCRIPTION
*      The function is to start initial NVRAM while there is power on.
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_startup_process
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool uem_startup_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret_val = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_set_state(UEM_STATE_STARTUP);
    uem_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_UEM_RMI_DATA_LID, 0, 0);

    return ret_val;
}

/*****************************************************************************
*   Function 
*      uem_startup_finish
*   DESCRIPTION
*      The function is to finish initial NVRAM while there is power on.
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_startup_finish
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool uem_startup_finish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret_val = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_init_hardware_data();
    uem_set_state(UEM_STATE_READY);

    ret_val = KAL_TRUE;

    return ret_val;
}

/*****************************************************************************
*   Function 
*      uem_init_hardware_level
*   DESCRIPTION
*      when the last block EF nvram is reading ready, we will start to init HW environment
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_init_hardware_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hw_level        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uem_init_hardware_level(void *hw_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    custom_init_hardware_level((void*)hw_level);
}

/***************************************************************************** 
****************************************************************************** 
* Local Funcations 
******************************************************************************
******************************************************************************/
/*****************************************************************************
*   Function 
*      uem_init_hardware_data
*   DESCRIPTION
*      when the last block EF nvram is reading ready, we will start to init HW environment
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/

static void uem_set_ctp_init_update_firmware(void)
{
#if defined(__TOUCH_PANEL_CAPACITY__)
	DCL_HANDLE handle;
	STS_CTRL_SET_DEVICE_T set_device;
	handle=DclSTS_Open(DCL_TS,0);
	set_device.mode = DCL_CTP_FIRMWARE_UPDATE;
	DclSTS_Control(handle,STS_CMD_SET_DEVICE,(DCL_CTRL_DATA_T *)&set_device);
	DclSTS_Close(handle);
#endif /*#if defined(__TOUCH_PANEL_CAPACITY__)*/  
}

/*****************************************************************************
 * FUNCTION
 *  uem_init_hardware_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool uem_init_hardware_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret_val = KAL_TRUE;
    ADC_CTRL_CREATE_OBJECT_T  adc_create;
    ADC_CTRL_GET_PHYSICAL_CHANNEL_T adc_ch;
    DCL_STATUS adc_status;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* when the last block EF nvram is reading ready, we will start to init HW environment */
    /* The audio init responsbility is change to MMI */
    /* initial RTC: Clock for one minute period, Alarm for no change */
    uem_rtc_config(uem_rtc_alarm_format_convert(DEVICE_AL_EN_NoChange), uem_rtc_clock_format_convert(DEVICE_TC_EN_ChkM));

    /* initial audio */
    l4cuem_set_mute_req(AUDIO_DEVICE_SPEAKER, KAL_FALSE);
    l4cuem_set_mute_req(AUDIO_DEVICE_MICROPHONE, KAL_FALSE);

#ifdef __MTK_TARGET__
    /* Initial ADC valur  */
    if (g_uem_cntx_p->adc_sche_id == DCL_HANDLE_INVALID)
    {
        g_uem_cntx_p->adc_sche_id = DclSADC_Open(DCL_ADC, FLAGS_NONE);
        if(g_uem_cntx_p->adc_sche_id == DCL_HANDLE_INVALID)
            ASSERT( KAL_FALSE );

        adc_ch.u2AdcName = DCL_VBAT_ADC_CHANNEL;
        adc_status = DclSADC_Control( g_uem_cntx_p->adc_sche_id, ADC_CMD_GET_CHANNEL, (DCL_CTRL_DATA_T *)&adc_ch);
        if(adc_status != STATUS_OK)
            ASSERT( KAL_FALSE );
      
        adc_create.u4Period = ADC_BOOTUP_EVAL_PERIOD;      // Measurement period (Uint is in Tick)
        adc_create.u4Sapid = NULL;                         // Sap id
        adc_create.u1OwnerId = MOD_UEM;                    // Indicate the module to for ADC driver to notify the result
        adc_create.u1AdcChannel = adc_ch.u1AdcPhyCh;       // To be measured physical ADC channel
        adc_create.u1EvaluateCount = ADC_BOOTUP_EVAL_COUNT;// Measurement count
        adc_create.fgSendPrimitive = KAL_TRUE;             // Whether to send message to owner module or NOT

        adc_status = DclSADC_Control(g_uem_cntx_p->adc_sche_id, ADC_CMD_CREATE_OBJECT, (DCL_CTRL_DATA_T *)&adc_create);
        if(adc_status != STATUS_OK)
            ASSERT( KAL_FALSE );

        /* send to the BMT task to register the callback message */
        uem_send_msg_to_bmt(MSG_ID_BMT_ADC_ADD_ITEM_REQ, g_uem_cntx_p->adc_sche_id);
    }
#if defined(__CLASSAB_VOLUME_PROTECTION__) || defined(__CLASSK_CP_SUPPORT__)
    if (g_uem_cntx_p->adc_med_sche_id == DCL_HANDLE_INVALID)
    {
        g_uem_cntx_p->adc_med_sche_id = DclSADC_Open(DCL_ADC, FLAGS_NONE);
        if(g_uem_cntx_p->adc_med_sche_id == DCL_HANDLE_INVALID)
            ASSERT( KAL_FALSE );

        adc_ch.u2AdcName = DCL_VBAT_ADC_CHANNEL;
        adc_status = DclSADC_Control( g_uem_cntx_p->adc_med_sche_id, ADC_CMD_GET_CHANNEL, (DCL_CTRL_DATA_T *)&adc_ch);
        if(adc_status != STATUS_OK)
            ASSERT( KAL_FALSE );
      
        adc_create.u4Period = ADC_BOOTUP_EVAL_PERIOD;      // Measurement period (Uint is in Tick)
        adc_create.u4Sapid = NULL;                         // Sap id
        adc_create.u1OwnerId = MOD_UEM;                    // Indicate the module to for ADC driver to notify the result
        adc_create.u1AdcChannel = adc_ch.u1AdcPhyCh;       // To be measured physical ADC channel
        adc_create.u1EvaluateCount = ADC_BOOTUP_EVAL_COUNT;// Measurement count
        adc_create.fgSendPrimitive = KAL_TRUE;             // Whether to send message to owner module or NOT

        adc_status = DclSADC_Control(g_uem_cntx_p->adc_med_sche_id, ADC_CMD_CREATE_OBJECT, (DCL_CTRL_DATA_T *)&adc_create);
        if(adc_status != STATUS_OK)
            ASSERT( KAL_FALSE );
        /* send to the BMT task to register the callback message */
        uem_send_msg_to_bmt(MSG_ID_BMT_ADC_ADD_ITEM_REQ, g_uem_cntx_p->adc_med_sche_id);
    }
#endif

    /* Initial Keypad longpress/repeattime value */
    uem_set_longpress_time(KPD_LONGPRESS_PERIOD);   /* ticks, in unit 10ms */
    uem_set_repeat_time(KPD_REPEAT_PERIOD);         /* ticks, in unit 10ms */
	uem_set_ctp_init_update_firmware();		
#endif /* __MTK_TARGET__ */ 

    return ret_val;
}

/***************************************************************************** 
****************************************************************************** 
* UEM Unit Test Usage
******************************************************************************
******************************************************************************/
#ifdef TST_INJECTED_EVENT
/*****************************************************************************
*   Function 
*      uem_send_bmtmsg_to_uem
*   DESCRIPTION
*      send message to UEM itself for test.
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_send_bmtmsg_to_uem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_name        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_send_bmtmsg_to_uem(kal_uint32 msg_name, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 cause;
    va_list varpars;
    drvuem_pmic_ind_struct *pmic_ind_struct;
    bmt_adc_measure_done_conf_struct *bmd_adc_done;
    bmt_adc_measure_done_conf_struct *ilm_bmd_adc_done;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_name)
    {
        case MSG_ID_BMT_ADC_MEASURE_DONE_CONF:
        {
            va_start(varpars, msg_name);
            bmd_adc_done = (bmt_adc_measure_done_conf_struct*) va_arg(varpars, kal_uint32);
            va_end(varpars);

            ilm_ptr = allocate_ilm(MOD_BMT);
            ilm_ptr->msg_id = (kal_uint16) MSG_ID_BMT_ADC_MEASURE_DONE_CONF;
            ilm_ptr->peer_buff_ptr = NULL;
            ilm_bmd_adc_done =
                bmt_adc_measure_done_conf_struct*) construct_local_para(
                                                    sizeof(bmt_adc_measure_done_conf_struct),
                                                    TD_CTRL);
            ilm_bmd_adc_done->adc_handle = bmd_adc_done->adc_handle;
            ilm_bmd_adc_done->adc_value = bmd_adc_done->adc_value;
            ilm_bmd_adc_done->volt = bmd_adc_done->volt;

            ilm_ptr->local_para_ptr = (local_para_struct*) ilm_bmd_adc_done;
            break;
        }
        case MSG_ID_DRVUEM_PMIC_IND:
        {
            va_start(varpars, msg_name);
            cause = (kal_uint32) va_arg(varpars, kal_uint32);
            va_end(varpars);

            ilm_ptr = allocate_ilm(MOD_BMT);
            ilm_ptr->msg_id = (kal_uint16) MSG_ID_DRVUEM_PMIC_IND;
            ilm_ptr->peer_buff_ptr = NULL;
            pmic_ind_struct = (drvuem_pmic_ind_struct*) construct_local_para(sizeof(drvuem_pmic_ind_struct), TD_CTRL);
            pmic_ind_struct->status = (BMT_CHR_STAT) cause;

            ilm_ptr->local_para_ptr = (local_para_struct*) pmic_ind_struct;
            break;
        }
    }
    SEND_ILM(MOD_BMT, MOD_UEM, DRIVER_PS_SAP, ilm_ptr);
    return;
}

#endif /* TST_INJECTED_EVENT */ 
/*****************************************************************************
*   Function 
*      uem_tst_handler
*   DESCRIPTION
*      TST event handler
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_tst_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void uem_tst_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #if defined(TST_INJECTED_EVENT)

    kal_uint32 msg_name;
    BMT_CHR_STAT cause;
    bmt_adc_measure_done_conf_struct bmd_adc_done;
    kal_uint8 param;
    tst_module_string_inject_struct *tst_inject = (tst_module_string_inject_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strcmp((kal_char*) tst_inject->string, "bmt") == 0)
    {
        /* PMIC_CHARGER_IN,     Charger plug in, BMT_CHARGER_IN */
        msg_name = MSG_ID_DRVUEM_PMIC_IND;
        uem_send_bmtmsg_to_uem(msg_name, tst_inject->index);
    }
    else if (strcmp((kal_char*) tst_inject->string, "chgr_bat") == 0)
    {
        /* PMIC_VBAT_STATUS,     Notify the battery voltage, BMT_VBAT_STATUS */
        msg_name = MSG_ID_BMT_ADC_MEASURE_DONE_CONF;
        bmd_adc_done.adc_handle = g_uem_cntx_p->adc_sche_id;
        bmd_adc_done.volt = (kal_uint32) tst_inject->index * 100000;
        bmd_adc_done.adc_value = 0.0;
        uem_send_bmtmsg_to_uem(msg_name, &bmd_adc_done);
    }
    else if (strcmp((kal_char*) tst_inject->string, "gpio_ledlcd") == 0)
    {
        if (tst_inject->index == 0)
        {
            param = LED_LIGHT_LEVEL0;
        }
        else
        {
            param = LED_LIGHT_LEVEL5;
        }

        l4cuem_gpio_set_level_req(GPIO_DEV_LED_MAINLCD, param);
    }
    else if (strcmp((kal_char*) tst_inject->string, "gpio_keyled") == 0)
    {
        if (tst_inject->index == 0)
        {
            param = LED_LIGHT_LEVEL0;
        }
        else
        {
            param = LED_LIGHT_LEVEL5;
        }

        l4cuem_gpio_set_level_req(GPIO_DEV_LED_KEY, param);
    }
    else if (strcmp((kal_char*) tst_inject->string, "gpio_statusled") == 0)
    {
        if (tst_inject->index == 0)
        {
            l4cuem_gpio_set_level_req(GPIO_DEV_LED_STATUS_1, 1);
        }
        else if (tst_inject->index == 1)
        {
            l4cuem_gpio_set_level_req(GPIO_DEV_LED_STATUS_1, 0);
        }
        else if (tst_inject->index == 2)
        {
            l4cuem_gpio_set_level_req(GPIO_DEV_LED_STATUS_2, 1);
        }
        else if (tst_inject->index == 3)
        {
            l4cuem_gpio_set_level_req(GPIO_DEV_LED_STATUS_2, 0);
        }
        else if (tst_inject->index == 4)
        {
            l4cuem_gpio_set_level_req(GPIO_DEV_LED_STATUS_3, 1);
        }
        else if (tst_inject->index == 5)
        {
            l4cuem_gpio_set_level_req(GPIO_DEV_LED_STATUS_3, 0);
        }
    }
    else if (strcmp((kal_char*) tst_inject->string, "gpio_vib") == 0)
    {
        if (tst_inject->index == 0)
        {
            param = VIBRATOR_OFF;
        }
        else
        {
            param = VIBRATOR_ON;
        }

        l4cuem_gpio_set_level_req(GPIO_DEV_VIBRATOR, param);
    }
    else if (strcmp((kal_char*) tst_inject->string, "gpio_sublcd") == 0)
    {
        if (tst_inject->index == 0)
        {
            param = LED_LIGHT_LEVEL0;
        }
        else
        {
            param = LED_LIGHT_LEVEL5;
        }

        l4cuem_gpio_set_level_req(GPIO_DEV_LED_SUBLCD, param);
    }
    else if (strcmp((kal_char*) tst_inject->string, "gpio_flash") == 0)
    {
        if (tst_inject->index == 0)
        {
            param = LED_LIGHT_LEVEL0;
        }
        else
        {
            param = LED_LIGHT_LEVEL5;
        }

        l4cuem_gpio_set_level_req(GPIO_DEV_FLASHLIGHT, param);
    }
    else if (strcmp((kal_char*) tst_inject->string, "vol") == 0)
    {
        l4cuem_audio_set_volume_req(0, tst_inject->index);
        l4cuem_audio_set_volume_req(1, tst_inject->index);
        l4cuem_audio_set_volume_req(2, tst_inject->index);
        l4cuem_audio_set_volume_req(3, tst_inject->index);
        l4cuem_audio_set_volume_req(4, tst_inject->index);
        l4cuem_audio_set_volume_req(5, tst_inject->index);
        l4cuem_audio_set_volume_req(6, tst_inject->index);
        l4cuem_audio_set_volume_req(7, tst_inject->index);
    }
    else if (strcmp((kal_char*) tst_inject->string, "pattern") == 0)
    {
        switch (tst_inject->index)
        {
            case 0:
                l4cuem_pattern_play_req(VIB_PATTERN_1, PLAY_REPEAT);
                break;
            case 1:
                l4cuem_pattern_play_req(VIB_PATTERN_2, PLAY_REPEAT);
                break;
            case 2:
                l4cuem_pattern_play_req(LED_POWER_ON, PLAY_REPEAT);
                break;
            case 3:
                l4cuem_pattern_play_req(LED_POWER_OFF, PLAY_REPEAT);
                break;
            case 4:
                l4cuem_pattern_play_req(LED_Caller1, PLAY_REPEAT);
                break;
            case 5:
                l4cuem_pattern_play_req(LCD_PATTERN_1, PLAY_REPEAT);
                break;
            case 6:
                l4cuem_pattern_play_req(LCD_PATTERN_2, PLAY_REPEAT);
                break;
        }
    }
    else if (strcmp((kal_char*) tst_inject->string, "clam") == 0)
    {
        if (tst_inject->index == 0)
        {
            l4cuem_gpio_detect_ind(EXT_DEV_CLAM_OPEN, 1);
        }
        else
        {
            l4cuem_gpio_detect_ind(EXT_DEV_CLAM_OPEN, 1);
        }
    }
    else if (strcmp((kal_char*) tst_inject->string, "usbdetect") == 0)
    {
        /* PMIC_VBAT_STATUS,     Notify the battery voltage, BMT_VBAT_STATUS */
        if (tst_inject->index == 0)
        {
            uem_send_msg_to_uem(MSG_ID_DRVUEM_USBDETECT_IND, (kal_uint32) 0);
        }
        else
        {
            uem_send_msg_to_uem(MSG_ID_DRVUEM_USBCFG_CNF, (kal_uint32) 0, (kal_uint32) 1, (kal_uint32) 0);
        }
    }
#endif /* TST_INJECTED_EVENT */
#if defined(__TINY_SYS_AP__)
{
    tst_module_string_inject_struct *tst_inject = (tst_module_string_inject_struct*) ilm_ptr->local_para_ptr;

    if (strcmp((kal_char*) tst_inject->string, "tinylog") == 0)
    {
        csd_get_tst_string_inject(tst_inject->index);
    }
 }
#endif /* __TINY_SYS_AP__ */     
}

static void uem_set_longpress_time(kal_uint32 ticks)
{
    DCL_CTRL_DATA_T time;
	DCL_HANDLE handler;

	time.rKBDCtrTime.u4Tick = ticks; 
	handler  = DclSKBD_Open(DCL_KBD, MOD_UEM);

    DclSKBD_Control(handler,KBD_CMD_SET_LONG_PRESS_TIME , (DCL_CTRL_DATA_T*)&time);
    DclSKBD_Close(handler);
}

static void uem_set_repeat_time(kal_uint32 ticks)
{
    DCL_CTRL_DATA_T time ;
    DCL_HANDLE handler;
    
	time.rKBDCtrTime.u4Tick = ticks; 
	handler  = DclSKBD_Open(DCL_KBD, MOD_UEM);

    DclSKBD_Control(handler, KBD_CMD_SET_REPEAT_PRESS_TIME , (DCL_CTRL_DATA_T*)&time);
    DclSKBD_Close(handler);
}

