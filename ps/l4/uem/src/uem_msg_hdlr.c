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
 * UEM_MSG_HDLR.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for message handler.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "kal_public_api.h"
#include "nvram_struct.h"
//#include "uart_sw.h"
#include "ps_public_struct.h"
#include "nvram_enums.h"

#include "stack_ltlcom.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "kal_trace.h"

#include "drvsignals.h"
#include "bmt.h"
#include "device.h"
//#include "keypad_sw.h"

#include "nvram_data_items.h"
#include "nvram_editor_data_item.h"

#include "custom_hw_default.h"
#include "custom_hw_default.h"

#include "l4c2uem_struct.h"
#include "l4c_common_enum.h"
#include "l4c_eq_msg.h"

#include "med_struct.h"


#include "uem_context.h"
#include "uem_at_cmd.h"
#include "uem_main.h"
#include "uem_utility.h"
#include "uem_msg_hdlr.h"
#include "uem_trc.h"
#include "uem_proc_cmd.h"
#include "uem_proc_msg.h"
#if defined(__GPS_TRACK__)
#include "ell_os.h"
#endif /* __GPS_TRACK__ */

/***************************************************************************** 
* Extern Function
*****************************************************************************/
extern kal_bool Kbd_GetKeyData(kbd_data *keydata);
extern void Modify_PowerOn_Type(kal_uint8 powen_type);
extern kal_uint32 MMIGetGDIShowFullScreenTime(void);

/***************************************************************************** 
* Local Funcations 
*****************************************************************************/
static void uem_get_adc_all_channel_timeout_hdlr(void *ptr);
#ifdef __TC01__
/* under construction !*/
#endif

/******************************************************************************/
/*******************   External Functions *************************************/
/******************************************************************************/
/*****************************************************************************
*   Function 
*      uemdrv_keypad_ind_hdlr
*   DESCRIPTION
*      The function is used to detect the user pressed or released keypad. 
*      The Driver will callback the function that the keypad is pressed or released and 
*      given the pressed or released key code value.
*   PARAMETERS
*      local_para_ptr   IN
*      peer_buff_ptr      IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_keypad_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_keypad_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uemdrv_keypad_detect_ind();

    return;
}

/***************************************************************************** 
*   Function 
*      uemdrv_power_on_ind_hdlr
*   DESCRIPTION
*      The function is used to keypad power on.
*   PARAMETERS
*      local_para_ptr   IN
*      peer_buff_ptr      IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_power_on_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_power_on_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drvuem_power_on_ind_struct *param_poweron = (drvuem_power_on_ind_struct*) local_para_ptr;
#ifdef PLUTO_MMI    
    kal_uint32 estimate_time;
#endif    
    kal_uint32 poweron_logo_remainder_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param_poweron->power_on)
    {
        case PWRKEYPWRON:   /* Keypad power on */
        {
            kal_trace(TRACE_FUNC, FUNC_UEM_KEYPAD_POWER_ON_IND);
        #ifdef __MTK_TARGET__
            /* set power on flag here to prevent misjudgement of charger-power-on during the key-press timer */
            uem_set_poweron_mode(POWER_ON_KEYPAD);
        #ifdef PLUTO_MMI
            {
                //extern void MMICheckDiskDisplayWithoutBackLight(void);
                //MMICheckDiskDisplayWithoutBackLight();
            }
            /* estimate GDI init time to make LOGO show-out faster */
        #if !defined(__IOT__)
            estimate_time = MMIGetGDIShowFullScreenTime();
			kal_trace(TRACE_FUNC, FUNC_UEM_KEYPAD_ESTIMATE_TIME,estimate_time);
            if (param_poweron->poweron_time_left > estimate_time)
            {
                poweron_logo_remainder_time = param_poweron->poweron_time_left - estimate_time;
                uem_poweron_timer_start((kal_uint32)poweron_logo_remainder_time);
            }
            else
            {
                /* if GDI init time is long enough, skip start power-on timer */
                uem_poweron_timer_expiry_hdlr(NULL);
            }
        #else
            uem_poweron_timer_expiry_hdlr(NULL);
        #endif
        #else
            poweron_logo_remainder_time = param_poweron->poweron_time_left;
            uem_poweron_timer_start(poweron_logo_remainder_time);          
            #if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)
            #if !defined(EXTERNAL_MMI)
            {
                extern void MMICheckDiskDisplay(void);
                MMICheckDiskDisplay();
            }
            #endif
            #endif
        #endif /* PLUTO_MMI */
        #else /* __MTK_TARGET__ */ 
            uemdrv_keypad_power_on_ind();
    #endif /* __MTK_TARGET__ */ 
            break;
        }
        case PRECHRPWRON:   /* Precharge Power On */
        {
            uem_set_poweron_mode(POWER_ON_PRECHARGE);
            uemdrv_prechr_power_on_ind();
            break;
        }
        case CHRPWRON:  /* Charger power on */
        {
            /*
             * postpone the power on procedure when get MSG_ID_DRVUEM_PMIC_IND
             * * to avoid fast plug-in/out
             */
            uem_set_poweron_mode(POWER_ON_CHARGER_IN);
            break;
        }
    #ifdef __USB_ENABLE__   /* New_USB_Mode */
        case USBPWRON:      /* USB Power on */
        case USBPWRON_WDT:  /* Mass Storage Mode abnormal reset */
        {
            /* postpone the power on procedure when get MSG_ID_DRVUEM_PMIC_IND
               to avoid fast plug-in/out */
            uemdrv_usb_power_on_ind();
            
            /* update the latest status */
            FLAG_SET_ON(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_USB); 
            /* Set the prev state */
            FLAG_SET_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_USB);

            break;
        }
    #endif /* __USB_ENABLE__ */ 
        case RTCPWRON:  /* Alarm power on */
        {
            uem_bmt_struct bmt_status;

            kal_trace(TRACE_FUNC, FUNC_UEM_ALARM_POWER_ON_IND);
            uem_set_poweron_mode(POWER_ON_ALARM);
            //Modify_PowerOn_Type(PWRKEYPWRON);
            uem_drv_set_power_on_mode(PWRKEYPWRON);

            uem_get_bat_status(&bmt_status);
            l4cuem_power_on_ind(POWER_ON_ALARM, uem_vbat_level_convert(bmt_status.volt));
            break;
        }
        case ABNRESET:  /* Abnormal Reset */
        {
            uemdrv_exception_power_on_ind();
            break;
        }
        case WDTRESET:  /* ??? */
        case UNKNOWN_PWRON:
        default:
            ASSERT(0);
            break;
    }
}

/*****************************************************************************
*   Function 
*      uemdrv_rtc_period_ind_hdlr
*   DESCRIPTION
*      The function is used to detect the RTC period time with one minute timer. 
*      The Driver will callback the function that the RTC within the specific time to 
*      generate RTC alarm interrupt.
*   PARAMETERS
*      local_para_ptr   IN
*      peer_buff_ptr      IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_rtc_period_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_rtc_period_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    RTC_Primitive *msg_ptr = (RTC_Primitive*) local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEMRTC_PERIOD_IND);

    switch (msg_ptr->rtc_ind)
    {
        case RTC_TC_IND:
            uemdrv_rtc_period_ind();
            break;
        case RTC_AL_IND:
            uemdrv_alarm_detect_ind();
            break;
        default:
            break;
    }
    return;
}

/*****************************************************************************
*   Function 
*      uemdrv_pmic_ind_hdlr
*   DESCRIPTION
*      The function is used to notify the battery status from PMIC driver.
*   PARAMETERS
*      local_para_ptr   IN
*      peer_buff_ptr      IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_pmic_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_pmic_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    uem_bmt_struct bmt_status;
    drvuem_pmic_ind_struct *msg_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_PMIC_IND);

    msg_ptr = (drvuem_pmic_ind_struct*) local_para_ptr;

    uem_get_bat_status(&bmt_status);

    bmt_status.status = uem_battery_status_convert((kal_uint8) msg_ptr->status);

    uem_set_bat_status(bmt_status);
    uemdrv_pmic_ind(bmt_status.status);

    return;
}

/*****************************************************************************
*   Function 
*      uembmt_adc_measure_done_cnf_hdlr
*   DESCRIPTION
*      The ADC of bmt task measure the result of voltage and ADC.
*   PARAMETERS
*      local_para_ptr   IN
*      peer_buff_ptr      IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uembmt_adc_measure_done_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uembmt_adc_measure_done_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    uem_bmt_struct bmt_status;
    bmt_adc_measure_done_conf_struct *msg_ptr = (bmt_adc_measure_done_conf_struct*) local_para_ptr;
    static kal_bool first_time_ind = KAL_TRUE;
#if defined(__CLASSAB_VOLUME_PROTECTION__) || defined(__CLASSK_CP_SUPPORT__)
    static kal_uint32 cur_eval = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CLASSAB_VOLUME_PROTECTION__
    kal_trace(TRACE_FUNC, FUNC_UEM_ADC_MEASURE_DONE_CNF_HDLR, cur_eval);
    if (msg_ptr->adc_handle == g_uem_cntx_p->adc_med_sche_id)
    {
        kal_trace(TRACE_FUNC, FUNC_UEM_CUR_VOL, msg_ptr->volt);
        if ((msg_ptr->volt >= 3500000) && (msg_ptr->volt <= 3700000))
        {
            if(cur_eval != ADC_MED_QUICK_EVAL_PERIOD)
            {
                uem_send_msg_to_bmt(
                    MSG_ID_BMT_ADC_MODIFY_PARAMETERS_REQ,
                    (kal_uint32) (g_uem_cntx_p->adc_med_sche_id),
                    (kal_uint32) (ADC_MED_QUICK_EVAL_COUNT),
                    (kal_uint32) (ADC_MED_QUICK_EVAL_PERIOD));
                cur_eval = ADC_MED_QUICK_EVAL_PERIOD;
            }
        }
        else if (cur_eval != ADC_MED_NORMAL_EVAL_PERIOD)
        {
            uem_send_msg_to_bmt(
                MSG_ID_BMT_ADC_MODIFY_PARAMETERS_REQ,
                (kal_uint32) (g_uem_cntx_p->adc_med_sche_id),
                (kal_uint32) (ADC_MED_NORMAL_EVAL_COUNT),
                (kal_uint32) (ADC_MED_NORMAL_EVAL_PERIOD));
            cur_eval = ADC_MED_NORMAL_EVAL_PERIOD;
        }

        uem_send_msg_to_aud(MSG_ID_L4AUD_BATTERY_VOLTAGE_IND, msg_ptr->volt);
        return;
    }
#endif
#ifdef __CLASSK_CP_SUPPORT__
		kal_trace(TRACE_FUNC, FUNC_UEM_ADC_MEASURE_DONE_CNF_HDLR, cur_eval);
		if (msg_ptr->adc_handle == g_uem_cntx_p->adc_med_sche_id)
		{
			kal_trace(TRACE_FUNC, FUNC_UEM_CUR_VOL, msg_ptr->volt);
			if((g_uem_cntx_p->aud_vol_flag) && (msg_ptr->volt <= 4200000))
        {
            if(cur_eval != ADC_MED_QUICK_EVAL_PERIOD)
            {
                uem_send_msg_to_bmt(
                    MSG_ID_BMT_ADC_MODIFY_PARAMETERS_REQ,
                    (kal_uint32) (g_uem_cntx_p->adc_med_sche_id),
                    (kal_uint32) (ADC_MED_QUICK_EVAL_COUNT),
                    (kal_uint32) (ADC_MED_QUICK_EVAL_PERIOD));
                cur_eval = ADC_MED_QUICK_EVAL_PERIOD;
            }
        }
        else if (cur_eval != ADC_MED_NORMAL_EVAL_PERIOD)
        {
            uem_send_msg_to_bmt(
                MSG_ID_BMT_ADC_MODIFY_PARAMETERS_REQ,
                (kal_uint32) (g_uem_cntx_p->adc_med_sche_id),
                (kal_uint32) (ADC_MED_NORMAL_EVAL_COUNT),
                (kal_uint32) (ADC_MED_NORMAL_EVAL_PERIOD));
            cur_eval = ADC_MED_NORMAL_EVAL_PERIOD;
        }

        uem_send_msg_to_aud(MSG_ID_L4AUD_BATTERY_VOLTAGE_IND, msg_ptr->volt);
        return;
    }
#endif

    if ((kal_int32)msg_ptr->adc_handle != (kal_int32)g_uem_cntx_p->adc_sche_id)
        return;
    
    bmt_status.status = PMIC_VBAT_STATUS;
    bmt_status.adc = msg_ptr->adc_value;
    bmt_status.volt = msg_ptr->volt;

    /* store the data in SRAM */
    uem_set_bat_status(bmt_status);

    /* First time is used for Power on to quickly response the status,
       After second time is used for normal time caculator */
    if (first_time_ind)
    {
        g_uem_cntx_p->bmt_status.disp_level = uem_vbat_level_convert(bmt_status.volt);
        g_uem_cntx_p->bmt_status.last_level = g_uem_cntx_p->bmt_status.disp_level;
        g_uem_cntx_p->bmt_status.hit_count = 0;

        l4cuem_battery_status_ind(PMIC_VBAT_STATUS, g_uem_cntx_p->bmt_status.disp_level);
        uem_send_msg_to_bmt(
            MSG_ID_BMT_ADC_MODIFY_PARAMETERS_REQ,
            (kal_uint32) (g_uem_cntx_p->adc_sche_id),
            (kal_uint32) (ADC_IDLE_EVAL_COUNT),
            (kal_uint32) (ADC_IDLE_EVAL_PERIOD));

        first_time_ind = KAL_FALSE;
    }
    else
    {
        /* notify the message to L4C */
        uemdrv_pmic_ind(PMIC_VBAT_STATUS);
    }
	    #if defined(__GPS_TRACK__)
    {
        static kal_bool flag = KAL_TRUE;
        if(flag && bmt_status.volt > 0)
        {
            kal_uint8 vbat_level;
            flag = KAL_FALSE;
            vbat_level = custom_cfg_vbat_level_regulator(
                bmt_status.volt,
                &(g_uem_cntx_p->bmt_status.last_level),
                &(g_uem_cntx_p->bmt_status.disp_level),
                &(g_uem_cntx_p->bmt_status.hit_count));
            OTA_LOGD(L_DRV, L_V7, "status:%d, volt:%d, vbat_level:%d, adc:%.6f", bmt_status.status, bmt_status.volt, vbat_level, bmt_status.adc);
            OTA_track_drv_charge_batter_status_msg_send(MOD_MMI, PMIC_VBAT_STATUS, vbat_level, bmt_status.volt);
        }
    }
#endif /* __GPS_TRACK__ */

}

/***************************************************************************** 
*   Function 
*      uemdrv_aux_id_hdlr
*   DESCRIPTION
*      The function is responsed detect the accessory plug in.
*      PARAMETERS
*      local_para_ptr   IN
*      peer_buff_ptr      IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_aux_id_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_aux_id_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aux_id_struct *p_aux_id_struct = (aux_id_struct*) local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (p_aux_id_struct->aux_id)
    {
        case AUX_ID_PLUGOUT:
        {
            uemdrv_gpio_detect_ind(EXT_DEV_NONE);
            break;
        }
        case AUX_ID_EARPHONE:
        {
            uemdrv_gpio_detect_ind(EXT_DEV_EARPHONE);
            break;
        }
        #ifdef __LINE_IN_SUPPORT__
        case AUX_ID_LINEIN_PLUGIN:
        {
            uemdrv_gpio_detect_ind(EXT_DEV_LINEIN_PLUGIN);
            break;
        }
        case AUX_ID_LINEIN_PLUGOUT:
        {
            uemdrv_gpio_detect_ind(EXT_DEV_LINEIN_PLUGOUT);
            break;
        }
        #endif  //__LINE_IN_SUPPORT__
        #ifdef __BT_NFC_TAG_SUPPORT__
        case NFC_TAG_PAIRING:
        {
            uemdrv_gpio_detect_ind(EXT_DEV_NFC_TAG_PAIRING);
            break;
        }
        #endif  //__BT_NFC_TAG_SUPPORT__
        case AUX_ID_KEY_PRESS:
            uemdrv_gpio_detect_ind(EXT_DEV_KEY_1);
            break;
        case AUX_ID_KEY_RELEASE:
            uemdrv_gpio_detect_ind(EXT_DEV_KEY_2);
            break;
        case AUX_ID_UART:
            uemdrv_gpio_detect_ind(EXT_DEV_UART);
            break;
        case AUX_ID_CLAM_OPEN:
            uemdrv_gpio_detect_ind(EXT_DEV_CLAM_OPEN);
//            FLAG_SET_ON(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_CLAM);
            break;
        case AUX_ID_CLAM_CLOSE:
            uemdrv_gpio_detect_ind(EXT_DEV_CLAM_CLOSE);
//            FLAG_SET_OFF(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_CLAM);
            break;
    #ifdef PLUTO_MMI
        case AUX_ID_TVOUT:
            uem_send_msg_to_aud(MSG_ID_MEDIA_TVO_AV_CABLE_DETECT_IND, 1 /* plug-in */ );
            break;
        case AUX_ID_TVOUT_OUT:
            uem_send_msg_to_aud(MSG_ID_MEDIA_TVO_AV_CABLE_DETECT_IND, 0 /* plug-out */ );
            break;
    #endif /* PLUTO_MMI */ 
        case AUX_ID_DETECTION_DONE:
            uemdrv_gpio_detect_ind(EXT_DEV_AUX_DETECT_DONE);
            break;
        case AUX_ID_TRANSMITTER_HOLD_ON:
            uemdrv_gpio_detect_ind(EXT_DEV_TRANSMITTER_HOLD_ON);
            break;
        case AUX_ID_TRANSMITTER_PUT_DOWN:
            uemdrv_gpio_detect_ind(EXT_DEV_TRANSMITTER_PUT_DOWN);
            break;
        default:
            break;
    }
}

/*****************************************************************************
*   Function 
*      uemnvm_write_data_cnf_hdlr
*   DESCRIPTION
*      The function is responsed from NVRAM for writing data success or not.
*      PARAMETERS
*      local_para_ptr   IN
*      peer_buff_ptr      IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemnvm_write_data_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uemnvm_write_data_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_write_cnf_struct *parm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_WRITE_DATA_CNF);

    parm_ptr = (nvram_write_cnf_struct*) local_para_ptr;

    switch (parm_ptr->file_idx)
    {
        case NVRAM_EF_UEM_RMI_DATA_LID:
        case NVRAM_EF_CUST_HW_LEVEL_TBL_LID:
        {
            g_uem_cntx_p->cause_id = parm_ptr->result;
            /* restore the function id in UEM message from NVRAM */
            g_uem_cntx_p->func_id = parm_ptr->access_id;
            break;
        }
        case NVRAM_EF_PORT_SETTING_LID:
        {
        #ifdef __AT_ESWM_SUPPORT__
            if (l4cuem_at_get_ef_port_setting_mode() != L4CUEM_EF_PORT_NULL)
            {
                l4cuem_at_ef_port_setting_write_cnf_hdlr((void*)parm_ptr);
                return;
            }
        #endif
        
        #if defined(__SMART_PHONE_MODEM__) && defined(__MTK_TARGET__)
            uem_ccci_em_uart_port_setting_hdlr(UEM_CCCI_EM_UART_PORT_WRITE, (void*)parm_ptr);
        #endif
            return;
         //   break;
        }
        default:
            break;
    }

    /* error case */
    switch ((g_uem_cntx_p->func_id))
    {
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
    #endif
        case CGCI_SET + 10:
            uem_send_msg_to_l4c(MSG_ID_L4CUEM_SET_AUDIO_PROFILE_CNF, NULL);
            break;
        case CGCI_SET + 11:
            uem_send_msg_to_l4c(MSG_ID_L4CUEM_SET_HW_LEVEL_CNF, NULL);
            break;
        default:
            break;
    }
}

/*****************************************************************************
*   Function 
*      uemnvm_read_data_cnf_hdlr
*   DESCRIPTION
*      The function is responsed from NVRAM for reading data success or not.
*      PARAMETERS
*      local_para_ptr   IN
*      peer_buff_ptr      IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemnvm_read_data_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uemnvm_read_data_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_read_cnf_struct *parm_ptr = NULL;
    kal_uint16 pdu_len;
    kal_uint8 *pdu_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_READ_DATA_CNF);

    parm_ptr = (nvram_read_cnf_struct*) local_para_ptr;
    pdu_ptr = get_pdu_ptr(peer_buff_ptr, &pdu_len);

    switch (parm_ptr->file_idx)
    {
        case NVRAM_EF_UEM_RMI_DATA_LID:
        {
            if (parm_ptr->length != sizeof(uem_context_rmi_struct))
            {
                /* error reading length */
                kal_trace(TRACE_ERROR, ERROR_UEM_NVRAM_DATA_LEN, sizeof(uem_context_rmi_struct), parm_ptr->length);
                return;
            }
            kal_mem_cpy(&(g_uem_cntx_p->rmi_data), (uem_context_rmi_struct*) pdu_ptr, sizeof(uem_context_rmi_struct));
            if (g_uem_cntx_p->state == UEM_STATE_STARTUP)
            {
                uem_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_CUST_HW_LEVEL_TBL_LID, 0, 0);
            }
            break;
        }
        case NVRAM_EF_CUST_HW_LEVEL_TBL_LID:
        {
            if (parm_ptr->length != sizeof(custom_hw_level_struct))
            {
                /* error reading length */
                kal_trace(TRACE_ERROR, ERROR_UEM_NVRAM_DATA_LEN, sizeof(custom_hw_level_struct), parm_ptr->length);
                return;
            }
            uem_init_hardware_level((void*)pdu_ptr);

            if (g_uem_cntx_p->state == UEM_STATE_STARTUP)
            {
                uem_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_UEM_MANUFACTURE_DATA_LID, 0, 0);
            }
            break;
        }
        case NVRAM_EF_UEM_MANUFACTURE_DATA_LID:
        {
            if (parm_ptr->length != sizeof(uem_context_manufacture_struct))
            {
                /* error reading length */
                kal_trace(
                    TRACE_ERROR,
                    ERROR_UEM_NVRAM_DATA_LEN,
                    sizeof(uem_context_manufacture_struct),
                    parm_ptr->length);
                return;
            }
            kal_mem_cpy(
                &(g_uem_cntx_p->manufacture_data),
                (uem_context_manufacture_struct*) pdu_ptr,
                sizeof(uem_context_manufacture_struct));

            /* when the last block EF nvram is reading ready, we will start to init HW environment */
            if (g_uem_cntx_p->state == UEM_STATE_STARTUP)
            {
            #if !defined(MED_NOT_PRESENT)    
                g_uem_cntx_p->cause_id = parm_ptr->result;
                uem_send_msg_to_aud(MSG_ID_MED_STARTUP_REQ);
            #else
                uemaud_startup_cnf_hdlr(NULL, NULL);
            #endif /* MED_NOT_PRESENT */
            }
            break;
        }
        case NVRAM_EF_PORT_SETTING_LID:
        {
            if (parm_ptr->length != sizeof(port_setting_struct))
            {
                ASSERT(0);
            }
        #ifdef __AT_ESWM_SUPPORT__
            if (l4cuem_at_get_ef_port_setting_mode() != L4CUEM_EF_PORT_NULL)
            {
                l4cuem_at_ef_port_setting_read_cnf_hdlr((void*)pdu_ptr);
                break;
            }
        #endif
        
        #if defined(__SMART_PHONE_MODEM__) && defined(__MTK_TARGET__)
            uem_ccci_em_uart_port_setting_hdlr(UEM_CCCI_EM_UART_PORT_READ, (void*)pdu_ptr);
        #endif
            break;
        }
        case NVRAM_EF_CAL_FLAG_LID:
        {
            nvram_cal_flag_struct *info = (nvram_cal_flag_struct*)pdu_ptr;
            
            l4c_eq_get_calibration_flag_rsp(info->u1CalAllFlag);
            break;
        }
    #ifdef __TC01__
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
            default:
            break;
    }
}

#ifdef __TC01__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
*   Function 
*      ueml4c_set_profile_req_hdlr
*   DESCRIPTION
*      The function request from L4C the profile.
*      PARAMETERS
*      local_para_ptr   IN
*      peer_buff_ptr      IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ueml4c_set_profile_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void ueml4c_set_profile_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
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
#endif
}

/*****************************************************************************
*  Function 
*     uemaud_startup_cnf_hdlr
*  DESCRIPTION
*     UEM <-- AUD/MED startup       
*  PARAMETERS
*     local_para_ptr IN
*     peer_buff_ptr  IN   
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemaud_startup_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uemaud_startup_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* send confirm back to L4C */
    uem_send_msg_to_l4c(MSG_ID_L4CUEM_STARTUP_CNF, NULL);

    uem_startup_finish();
}

/*****************************************************************************
*   Function 
*      ueml4c_startup_req_hdlr
*   DESCRIPTION
*      The function request from L4C the profile.
*      PARAMETERS
*      local_para_ptr   IN
*      peer_buff_ptr      IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ueml4c_startup_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void ueml4c_startup_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_STARTUP_REQ);

    uem_startup_process();
}

/***************************************************************************** 
*   Function 
*      uemsat_language_req_hdlr
*   DESCRIPTION
*      The function is to handle the language request.
*      PARAMETERS
*      local_para_ptr   IN
*      peer_buff_ptr      IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemsat_language_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uemsat_language_req_hdlr(kal_uint32 src_mod_id, local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_LANGUAGE_REQ);

    uem_send_msg_to_sat(src_mod_id, MSG_ID_SAT_LANGUAGE_CNF, NULL);
}

/*****************************************************************************
*   Function 
*      uemsat_current_time_req_hdlr
*   DESCRIPTION
*      The function to handle the current time request handle.
*      PARAMETERS
*      local_para_ptr   IN
*      peer_buff_ptr      IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemsat_current_time_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uemsat_current_time_req_hdlr(kal_uint32 src_mod_id, local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_CURRENT_TIME_REQ);

    uem_send_msg_to_sat(src_mod_id, MSG_ID_SAT_CURRENT_TIME_CNF, NULL);
}

/*****************************************************************************
*  Function 
*     uemaud_play_finish_ind_hdlr
*  DESCRIPTION
*     ...
*  PARAMETERS
*     local_para_ptr IN
*     peer_buff_ptr  IN   
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemaud_play_finish_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uemaud_play_finish_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(MED_NOT_PRESENT)
    media_aud_play_finish_ind_struct *aud_fin_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_fin_struct = (media_aud_play_finish_ind_struct*) local_para_ptr;

    uemdrv_audio_play_finish_ind(aud_fin_struct->result, aud_fin_struct->identifier);
#endif /* MED_NOT_PRESENT */
}

/*****************************************************************************
*  Function 
*     uemaud_playbyname_req_hdlr
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemaud_playbyname_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id              [IN]        
 *  local_para_ptr      [?]         
 *  peer_buff_ptr       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void uemaud_playbyname_req_hdlr(msg_type msg_id, local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    msg_type new_msg_id = MSG_ID_INVALID_TYPE;
    kal_uint8 res = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_id)
    {
        case MSG_ID_L4CUEM_AUDIO_PLAY_BY_NAME_REQ:
            new_msg_id = MSG_ID_MEDIA_AUD_PLAY_BY_FILE_REQ;
            break;
        case MSG_ID_L4CUEM_AUDIO_STOP_BY_NAME_REQ:
            new_msg_id = MSG_ID_MEDIA_AUD_STOP_REQ;
            break;
        default:
            res = KAL_FALSE;
            break;
    }

    if (res == KAL_FALSE)
    {
        return;
    }

    uem_send_msg_to_aud(new_msg_id, local_para_ptr);
}

/*****************************************************************************
*  Function 
*     ueml4c_playbyname_cnf_hdlr
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ueml4c_playbyname_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id              [IN]        
 *  local_para_ptr      [?]         
 *  peer_buff_ptr       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void ueml4c_playbyname_cnf_hdlr(msg_type msg_id, local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    msg_type new_msg_id = MSG_ID_INVALID_TYPE;
    kal_uint8 res = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_id)
    {
        case MSG_ID_MEDIA_AUD_PLAY_BY_FILE_CNF:
            new_msg_id = MSG_ID_L4CUEM_AUDIO_PLAY_BY_NAME_CNF;
            break;
        case MSG_ID_MEDIA_AUD_STOP_CNF:
            new_msg_id = MSG_ID_L4CUEM_AUDIO_STOP_BY_NAME_CNF;
            break;
        default:
            res = KAL_FALSE;
            break;
    }

    if (res == KAL_FALSE)
    {
        return;
    }

    uem_send_msg_to_l4c(new_msg_id, local_para_ptr);
}

/*****************************************************************************
*  Function 
*     uemaud_playbystring_req_hdlr
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemaud_playbystring_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id              [IN]        
 *  local_para_ptr      [?]         
 *  peer_buff_ptr       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void uemaud_playbystring_req_hdlr(msg_type msg_id, local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    msg_type new_msg_id = MSG_ID_INVALID_TYPE;
    kal_uint8 res = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_id)
    {
        case MSG_ID_L4CUEM_AUDIO_PLAY_BY_STRING_REQ:
            new_msg_id = MSG_ID_MEDIA_AUD_PLAY_BY_STRING_REQ;
            break;
        case MSG_ID_L4CUEM_AUDIO_STOP_BY_STRING_REQ:
            new_msg_id = MSG_ID_MEDIA_AUD_STOP_BY_STRING_REQ;
            break;
        default:
            res = KAL_FALSE;
            break;
    }

    if (res == KAL_FALSE)
    {
        return;
    }

    uem_send_msg_to_aud(new_msg_id, local_para_ptr);
}

/*****************************************************************************
*  Function 
*     ueml4c_playbystring_cnf_hdlr
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ueml4c_playbystring_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id              [IN]        
 *  local_para_ptr      [?]         
 *  peer_buff_ptr       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void ueml4c_playbystring_cnf_hdlr(msg_type msg_id, local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    msg_type new_msg_id = MSG_ID_INVALID_TYPE;
    kal_uint8 res = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_id)
    {
        case MSG_ID_MEDIA_AUD_PLAY_BY_STRING_CNF:
            new_msg_id = MSG_ID_L4CUEM_AUDIO_PLAY_BY_STRING_CNF;
            break;
        case MSG_ID_MEDIA_AUD_STOP_BY_STRING_CNF:
            new_msg_id = MSG_ID_L4CUEM_AUDIO_STOP_BY_STRING_CNF;
            break;
        default:
            res = KAL_FALSE;
            break;
    }

    if (res == KAL_FALSE)
    {
        return;
    }

    uem_send_msg_to_l4c(new_msg_id, local_para_ptr);
}


/*****************************************************************************
*  Function 
*     uemsys_timer_expiry_hdlr
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemsys_timer_expiry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uemsys_timer_expiry_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   /* stack_timer_struct *stack_timer_ptr;
    kal_uint16 msg_len = 0;*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //stack_timer_ptr = (stack_timer_struct*) get_local_para_ptr(local_para_ptr, &msg_len);
    
    evshed_timer_handler(event_scheduler_uem_ptr);
     
}

/*****************************************************************************
*  Function 
*     ueml4c_get_audio_param_req_hdlr
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ueml4c_get_audio_param_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void ueml4c_get_audio_param_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to call l4c/rmmic function handler */
    l4cuem_get_audio_param_cnf_hdlr(local_para_ptr, peer_buff_ptr);
}
#if defined(__AMRWB_LINK_SUPPORT__)
void ueml4c_get_audio_wb_param_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    l4cuem_get_audio_wb_param_cnf_hdlr(local_para_ptr, peer_buff_ptr);
}


void ueml4c_set_audio_wb_param_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    l4cuem_set_audio_wb_param_cnf_hdlr(local_para_ptr, peer_buff_ptr);
}
#endif
/*****************************************************************************
*  Function 
*     ueml4c_get_audio_profile_cnf_hdlr
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ueml4c_get_audio_profile_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void ueml4c_get_audio_profile_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to call l4c/rmmic function handler */
    l4cuem_get_audio_profile_cnf_hdlr(local_para_ptr, peer_buff_ptr);

}

/*****************************************************************************
*  Function 
*     uemaux_all_channel_conf_hdlr
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemaux_all_channel_conf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uemaux_all_channel_conf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    adc_all_channel_struct *ach = (adc_all_channel_struct*) local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (uem_adc_on == 1)
    {
        l4cuem_get_adc_all_channel_ind(ach->vbat, ach->bat_temp, ach->vaux, ach->charge_current, ach->vcharger);

        uem_start_timer(ADC_EVENT_TIMER, uem_get_adc_all_channel_timeout_hdlr, 1000);   /* 1 Sec */
    }
}

/*****************************************************************************
*  Function 
*     ueml4c_set_audio_profile_req_hdlr
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ueml4c_set_audio_profile_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void ueml4c_set_audio_profile_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_send_msg_to_aud(MSG_ID_MEDIA_AUD_SET_AUDIO_PROFILE_REQ, (kal_uint32) local_para_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  ueml4c_get_audio_mute_status_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void ueml4c_get_audio_mute_status_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_send_msg_to_aud(MSG_ID_GET_MEDIA_MUTE_STATUS_REQ, (kal_uint32) local_para_ptr);
}


/*****************************************************************************
*  Function 
*     ueml4c_set_audio_param_req_hdlr
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ueml4c_set_audio_param_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void ueml4c_set_audio_param_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_send_msg_to_aud(MSG_ID_MEDIA_AUD_SET_AUDIO_PARAM_REQ, (kal_uint32) local_para_ptr);
}

/*****************************************************************************
*  Function 
*     ueml4c_get_volume_cnf_hdlr
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ueml4c_get_volume_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void ueml4c_get_volume_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to call l4c/rmmic function handler */
    l4cuem_get_volume_cnf_hdlr(local_para_ptr, peer_buff_ptr);

}

/*****************************************************************************
*  Function 
*     ueml4c_get_gain_cnf_hdlr
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ueml4c_get_gain_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void ueml4c_get_gain_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to call l4c/rmmic function handler */
    l4cuem_get_gain_cnf_hdlr(local_para_ptr, peer_buff_ptr);

}

/*****************************************************************************
*  Function 
*     ueml4c_set_hw_level_req_hdlr
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ueml4c_set_hw_level_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void ueml4c_set_hw_level_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;
    l4cuem_set_hw_level_req_struct *hw_level = (l4cuem_set_hw_level_req_struct*) local_para_ptr;
    custom_hw_level_struct cust_hw_level;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uem_cntx_p->src_id = hw_level->src_id;
    if (hw_level)
    {
        kal_mem_set(&cust_hw_level, 0, sizeof(custom_hw_level_struct));
        for (i = 0; i < PWM_MAX_LEVEL; i++)
        {
            cust_hw_level.PWM1[i][0] = hw_level->PWM1_freq_Level_Info[i];
            cust_hw_level.PWM1[i][1] = hw_level->PWM1_duty_Level_Info[i];

            cust_hw_level.PWM2[i][0] = hw_level->PWM2_freq_Level_Info[i];
            cust_hw_level.PWM2[i][1] = hw_level->PWM2_duty_Level_Info[i];

            cust_hw_level.PWM3[i][0] = hw_level->PWM3_freq_Level_Info[i];
            cust_hw_level.PWM3[i][1] = hw_level->PWM3_duty_Level_Info[i];

            PWM1_Level_Info[i][0] = hw_level->PWM1_freq_Level_Info[i];
            PWM1_Level_Info[i][1] = hw_level->PWM1_duty_Level_Info[i];

            PWM2_Level_Info[i][0] = hw_level->PWM2_freq_Level_Info[i];
            PWM2_Level_Info[i][1] = hw_level->PWM2_duty_Level_Info[i];

            Alter_Level_Info[i][0] = hw_level->PWM3_freq_Level_Info[i];
            Alter_Level_Info[i][1] = hw_level->PWM3_duty_Level_Info[i];

        }

        for (i = 0; i < LCD_CONTRAST_MAX_LEVEL; i++)
        {
            cust_hw_level.MainLCD_Contrast[i] = hw_level->MainLCD_Contrast_Level_Info[i];
            MainLCD_Contrast_Level_Info[i] = hw_level->MainLCD_Contrast_Level_Info[i];

        #ifdef DUAL_LCD
            cust_hw_level.SubLCD_Contrast[i] = hw_level->SubLCD_Contrast_Level_Info[i];
            SubLCD_Contrast_Level_Info[i] = hw_level->SubLCD_Contrast_Level_Info[i];
        #endif /* DUAL_LCD */ 
        }

        for (i = 0; i < LCD_PARAM_MAX_LEVEL; i++)
        {
            cust_hw_level.MainLCD_Bias[i] = hw_level->MainLCD_Bias_Level_Info[i];
            cust_hw_level.MainLCD_Linerate[i] = hw_level->MainLCD_Linerate_Level_Info[i];
            cust_hw_level.MainLCD_Temp[i] = hw_level->MainLCD_Temp_Level_Info[i];

            MainLCD_Bias_Level_Info[i] = hw_level->MainLCD_Bias_Level_Info[i];
            MainLCD_Linerate_Level_Info[i] = hw_level->MainLCD_Linerate_Level_Info[i];
            MainLCD_Temp_Level_Info[i] = hw_level->MainLCD_Temp_Level_Info[i];

        #ifdef DUAL_LCD
            cust_hw_level.SubLCD_Bias[i] = hw_level->SubLCD_Bias_Level_Info[i];
            cust_hw_level.SubLCD_Linerate[i] = hw_level->SubLCD_Linerate_Level_Info[i];
            cust_hw_level.SubLCD_Temp[i] = hw_level->SubLCD_Temp_Level_Info[i];

            SubLCD_Bias_Level_Info[i] = hw_level->SubLCD_Bias_Level_Info[i];
            SubLCD_Linerate_Level_Info[i] = hw_level->SubLCD_Linerate_Level_Info[i];
            SubLCD_Temp_Level_Info[i] = hw_level->SubLCD_Temp_Level_Info[i];
        #endif /* DUAL_LCD */ 
        }

        for (i = 0; i < BATTERY_MAX_LEVEL; i++)
        {
            cust_hw_level.BatteryLevel[i] = hw_level->Battery_Level_Info[i];
            Battery_Level_Info[i] = hw_level->Battery_Level_Info[i];
        }

#ifdef __MULTI_LEVEL_BACKLIGHT_SUPPORT__
        for (i = 0; i < PWM_MAX_BACKLIGHT_LEVEL; i++)
        {
            cust_hw_level.BacklightLevel[i][0] = hw_level->bl_PWM_freq_Level_Info[i];
            cust_hw_level.BacklightLevel[i][1] = hw_level->bl_PWM_duty_Level_Info[i];
        }
#endif

        if (uem_get_state() == UEM_STATE_READY)
        {
            g_uem_cntx_p->func_id = CGCI_SET + 11;
            uem_send_msg_to_nvram(
                MSG_ID_NVRAM_WRITE_REQ,
                NVRAM_EF_CUST_HW_LEVEL_TBL_LID,
                &cust_hw_level,
                sizeof(custom_hw_level_struct));
        }
        else
        {
            g_uem_cntx_p->cause_id = NVRAM_IO_ERRNO_UNINIT;
            uem_send_msg_to_l4c(MSG_ID_L4CUEM_SET_HW_LEVEL_CNF, NULL);
        }
    }
}

#ifdef __USB_ENABLE__
/*****************************************************************************
*  Function 
*     uemdrv_usb_detect_ind_hdlr
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_usb_detect_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_usb_detect_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drvuem_usbdetect_ind_struct *usbdetect_ind_struct = (drvuem_usbdetect_ind_struct*) local_para_ptr;
    kal_uint8 action_4_upper_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    action_4_upper_layer = uem2l4_usb_detect_action_convert(usbdetect_ind_struct->action);
    uemdrv_usb_detect_ind(action_4_upper_layer);
    return;
}

/*****************************************************************************
*  Function 
*     uemdrv_usb_config_cnf_hdlr
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_usb_config_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_usb_config_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drvuem_usbcfg_cnf_struct *usbcfg_cnf_struct = (drvuem_usbcfg_cnf_struct*) local_para_ptr;
    kal_uint8 usb_action_4_upper_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    usb_action_4_upper_layer = uem2l4_usb_config_action_convert(usbcfg_cnf_struct->mode);
    uemdrv_usb_config_cnf(usb_action_4_upper_layer, usbcfg_cnf_struct->result, usbcfg_cnf_struct->reserved);
    return;
}
#endif /* __USB_ENABLE__ */ 

/*****************************************************************************
*  Function 
*     uemdrv_bmt_leave_precharge_ind
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_bmt_leave_precharge_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_bmt_leave_precharge_ind(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    l4cuem_leave_precharge_ind();
}

/*****************************************************************************
 * FUNCTION
 *  uemdrv_rf_test_gsm_powerscan_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_rf_test_gsm_powerscan_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    rf_test_gsm_power_scan_struct *rf_pwr_scan = (rf_test_gsm_power_scan_struct*) local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__SMART_PHONE_MODEM__) && defined(__MTK_TARGET__)
    uem_ccci_em_gsm_power_scan_hdlr(rf_pwr_scan->arfcn_out, rf_pwr_scan->power);
#else
    uemdrv_rf_test_gsm_powerscan_callback(rf_pwr_scan->arfcn_out, rf_pwr_scan->power);
#endif
}


/******************************************************************************/
/*******************   Local Functions *************************************/
/******************************************************************************/
/*****************************************************************************
*  Function 
*     uem_get_adc_all_channel_timeout_hdlr
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_get_adc_all_channel_timeout_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uem_get_adc_all_channel_timeout_hdlr(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_adc_timer_id = 0;
    uem_send_msg_to_aux(MSG_ID_READ_ALL_ADC_CHANNEL_REQ);
}


#if defined(__SMART_PHONE_MODEM__) && defined(__MTK_TARGET__)
/*****************************************************************************
 * FUNCTION
 *  uemdrv_ccci_em_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_ccci_em_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    uem_ccci_em_req_struct *req = (uem_ccci_em_req_struct*) local_para_ptr;
    kal_uint16 event_type;
    kal_uint16 param_1;
    kal_uint32 param_2;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEMDRV_CCCI_EM_REQ_HDLR);
    
    event_type = (kal_uint16)req->buff_id;
    param_1 = (kal_uint16)((req->buff_id)>>16);    
    param_2 = (kal_uint32)req->reserved;

    kal_trace(TRACE_INFO, FUNC_UEMDRV_CCCI_EM_REQ_HDLR_INFO, event_type, param_1, param_2);
    
    uem_ccci_em_req_hdlr(event_type, param_1, param_2);

}
#endif /* __SMART_PHONE_MODEM__ */

#ifndef FMT_NOT_PRESENT
/* New FMT msg*/
void uemfmt_calc_done_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
#ifdef __USB_ENABLE__
    uemdrv_usb_detect_ind(DEVUSB_DETECT_ACTION_MS_EXIT_DONE);
#endif
}
#endif

#ifdef __CLASSK_CP_SUPPORT__
void uemaud_state_judge_hdlr(local_para_struct * local_para_ptr,peer_buff_struct * peer_buff_ptr)
{
    l4audio_classk_state_ind_struct *req = (l4audio_classk_state_ind_struct*)  local_para_ptr;
    kal_bool state = KAL_FALSE;
    state = req->classk_state;
    
    if (state == KAL_TRUE)
    {
        g_uem_cntx_p->aud_vol_flag = 1;
    }
    else
    {
        g_uem_cntx_p->aud_vol_flag = 0; 
    }
}
#endif

