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
 *  wndrv_configure.c
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  Customer configuration functions of WIFI network driver
 *
 * Author:
 * -------
 * -------
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __MTK_TARGET__
#define __WNDRV_OS_FILES_C__

#include "kal_release.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "syscomp_config.h"
#include "task_config.h"
#include "task_main_func.h"
#include "stack_ltlcom.h"

/*----------------------------*/
#include "stack_timer.h"  /* Stack timer */

/*----------------------------*/   
#include "multiboot_config.h"
#include "fctycomp_config.h"

/*----------------------------*/
#include "kal_trace.h"

/*----------------------------*/
#include "wndrv_cnst.h"
#include "wndrv_cal.h"
#include "wndrv_ft_types.h"
#include "wndrv_ft_msg.h"

#include "wndrv_supc_types.h"
#include "wndrv_supc_msg.h"


#include "wifi_common_config.h"

#include "nvram_data_items.h"

/*----------------------------*/
#if defined(WIFI_BB_MT5911)
#include "precomp.h"
/* include after precomp.h due to MP_ADAPTER */
#include "wndrv_context.h" 
#endif

/*******************************************************************************
*
*  MT5931 driver customer setting
*
*******************************************************************************/
#if defined (MT5931)
kal_int32 wifi_driver_customer_setting[] =
{
	WIFI_DEFAULT_REG_DOMAIN,                                /* 0. Country code */
	PS_FAST_PSP ,                                           /* 1. Power saving mode */
	WIFI_DEFAULT_OSC_STABLE_TIME,                           /* 2. OSC stable time */
	WNDRV_DEFAULT_WMMPS_CONFIG,                             /* 3. WMM PS config */
	WNDRV_EINT_POLARITY,                                    /* 4. WIFI EINT polarity */
	(WNDRV_DEFAULT_LOWEST_RSSI + WNDRV_DEFAULT_PATH_LOSS),  /* 5. RSSI Low threshold */
	WIFI_DEFAULT_CONNECTION_KEEP_TIME,                      /* 6. Connection keep time */
	WIFI_DEFAULT_CONNECTION_RETRY_LIMIT,                    /* 7. Connection retry limit */
	WNDRV_DEFAULT_DTIM_PERIOD,                              /* 8. Sleep Period */
	WNDRV_BT_1WIRE_MODE_T6,                                 /* 9. 1 wire mode T6 */
	WNDRV_BT_1WIRE_MODE_T8,                                 /* 10. 1 wire mode T8 */
	WNDRV_BT_1WIRE_MODE_BT_DELAY,                           /* 11. 1 wire mode BT delay */
	1,                                                      /* 12. HW custom configuration flag */
	3,														/* 13. dec power*/
	20,														/* 14. polling time*/
  WNDRV_SDIO_SEL_CARD1,                                   /* 15. SDIO card select */
	WNDRV_SDIO_CLK_FREQ_22M,                                /* 16. SDIO clock frequency */
	WNDRV_FUNC1_SDIO_BLK_SIZE_512                           /* 17. SDIO WIFI function block size */			
};

kal_uint32 WiFi_Query_Customer_Seting_Version(void)
{
    return sizeof(wifi_driver_customer_setting)/sizeof(kal_uint32);
}
#endif /* MT5931 */

/*******************************************************************************
*
*  I/O Related Functions
*
*******************************************************************************/

const unsigned char WiFi_IO_setting[5] =
{
    0xFF,    1,   // power on : GPIO pin(if use PMIC, please write 0xFF), pol
    0xFF,         // lpoclk
    0xFF          // IndicateWiFi pin(if the pin isn't connected, please write 0xFF)
};

/*******************************************************************************
* FUNCTION
*   wndrv_get_lcd_channel
*
* DESCRIPTION
*   Get LCD Channel
*
* CALLS
*   None
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
kal_uint8 wndrv_get_lcd_channel( void )
{
   /* LCD channel
      0: LCD Parallel Interface 0
      1: LCD Parallel Interface 1
      2: LCD Parallel Interface 2
   */
   return 1;
}

/*******************************************************************************
*
*  EEPROM Related Functions
*
*******************************************************************************/
kal_bool wndrv_get_eeprom_existence( void )
{                                   
   return KAL_FALSE;
}


/* ------------------------------------------------------------------------- */
kal_uint32 wndrv_get_eeprom_size( void )
{                                   
   return WIFI_DEFAULT_EEPROM_SIZE;
}


/*******************************************************************************
*
*  NVRAM Related Functions
*
*******************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0  
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(WIFI_BB_MT5911)
    #if defined( WIFI_RF_AL2236 )
/* under construction !*/
/* under construction !*/
   #else
/* under construction !*/
/* under construction !*/
    #endif
/* under construction !*/
#elif defined(WIFI_BB_MT5921) || defined(MT5931)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if ( BUILD_11A )		
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/*******************************************************************************
* FUNCTION
*   wndrv_get_led_configuration
*
* DESCRIPTION
*   Get LED and PHY configuration
*
* CALLS
*   None
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
kal_uint16 wndrv_get_led_and_phy_configure( void )
{                   
  /*  b7-b3: reserved
      b2-b0: LED Blinking mode
             000: Default mode
             001: Customized Mode 1
             010: Customized Mode 2
             011: Customized Mode 3  
             
      b15-b10: reserved
      b9 - b8: PHY mode
               00: G mode
               01: A+G mode
               10: A mode
               11: B mode
   */             
                
   return WIFI_DEFAULT_LED_AND_PHY_CONFIGURE; //0
}

/*******************************************************************************
* FUNCTION
*   wndrv_advance_led_configure
*
* DESCRIPTION
*   Get LED advance configuration
*
* CALLS
*   None
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
void wndrv_advance_led_configure (
    kal_uint32 *blinking_on_time1,
    kal_uint32 *blinking_off_time1,
    kal_uint32 *blinking_on_time2,
    kal_uint32 *blinking_off_time2
    )
{
    // when LED is no triggered, default state is off
    *blinking_on_time1 = 20;   /* LED blinking on time: 80 ms */
    *blinking_off_time1 = 6;   /* LED blinking off time: 24 ms */

    // when LED is no triggered, default state is on
    *blinking_on_time2 = 20;   /* LED blinking on time: 80 ms */
    *blinking_off_time2 = 3;   /* LED blinking off time: 12 ms */

    return;
}

/*******************************************************************************
* FUNCTION
*   wndrv_get_reg_domain
*
* DESCRIPTION
*   Get default requlatory domain
*
* CALLS
*   None
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
kal_uint16 wndrv_get_reg_domain( void )
{                   
    /* Domain is put as byte string in EEPROM.
    ** Therefore, the lower byte is the first character
    ** But, driver put the the first character in higher byte. */
   return WIFI_DEFAULT_REG_DOMAIN; //0
}	


/*******************************************************************************
* FUNCTION
*   wndrv_get_ant_mode
*
* DESCRIPTION
*   Get atenna mode
*
* CALLS
*   None
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
kal_uint16 wndrv_get_ant_mode( void )
{                   
  /*  b7-b4: reserved
      b3-b0: Antenna mode
             b3: TX Ant 1 Present
             b2: Tx Ant 0 Present
             b1: RX Ant 1 Present
             b0: RX Ant 0 Present  
             
      b15-b10: reserved
      b9 - b8: Antenna selection mode
               b9: TX main port at Ant 0
                   0: TX main port of NIC is at Ant 1
                   1: TX main port of NIC is at Ant 0
               b8: RX main port at Ant 0
                   0: RX main port of NIC is at Ant 1
                   1: RX main port of NIC is at Ant 0               
   */             	
	
   return WIFI_DEFAULT_ANT_MODE; //5
}	


/*******************************************************************************
* FUNCTION
*   wndrv_get_osc_stable_time
*
* DESCRIPTION
*   Get Oscillator Stable Time
*
* CALLS
*   None
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
kal_uint16 wndrv_get_osc_stable_time( void )
{                   
   /* unit is us. */
   //return 0x0BB8; //3000us
   return WIFI_DEFAULT_OSC_STABLE_TIME; //3000us
}


/*******************************************************************************
* FUNCTION
*   wndrv_get_tx_power_mark_valid
*
* DESCRIPTION
*   TX Power Mark exists or not.
*
* CALLS
*   None
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
kal_bool wndrv_get_tx_power_mark_valid( void )
{                   
   return KAL_FALSE;
}		


/*******************************************************************************
* FUNCTION
*   wndrv_get_cck_tx_power_mark
*
* DESCRIPTION
*   GET CCK TX Power Mark
*
* CALLS
*   None
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
void wndrv_get_cck_tx_power_mark()
{ 
/*	                  
   gainMarkL->gain = ;
   gainMarkL->dBm = ;
   
   gainMarkM->gain = ;
   gainMarkM->dBm = ;
   
   gainMarkH->gain = ;
   gainMarkH->dBm = ;   
*/   
}		


/*******************************************************************************
* FUNCTION
*   wndrv_get_ofdm_tx_power_mark
*
* DESCRIPTION
*   GET OFDM TX Power Mark
*
* CALLS
*   None
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
void wndrv_get_odfm_tx_power_mark()
{                   
/*	
   gainMarkL->gain = ;
   gainMarkL->dBm = ;
   
   gainMarkM->gain = ;
   gainMarkM->dBm = ;
   
   gainMarkH->gain = ;
   gainMarkH->dBm = ;   
*/   
}		

/*******************************************************************************
* FUNCTION
*   wndrv_get_connection_keep_time
*
* DESCRIPTION
*   Get Connection Keep Time (Send NULL packets)
*
* CALLS
*   None
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
kal_uint16 wndrv_get_connection_keep_time ( void )
{
   /* unit is second. */
   return WIFI_DEFAULT_CONNECTION_KEEP_TIME; //20
}

/*******************************************************************************
* FUNCTION
*   wndrv_get_RSSI_update_time
*
* DESCRIPTION
*   Get Singal Strength update Time
*
* CALLS
*   None
*
* PARAMETERS
*   pRSSIQueryPeriod
*   pCheckLCD
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
void wndrv_get_RSSI_update_time ( kal_uint32 *pRSSIQueryPeriod, kal_uint8 *pCheckLCD)
{
   /* unit is second. */
   *pRSSIQueryPeriod = WIFI_DEFAULT_RSSI_UPDATE_TIME; //10
   *pCheckLCD = WIFI_DEFAULT_CHECKLCD; //TRUE
}
/*******************************************************************************
* FUNCTION
*   wndrv_get_connection_retry_limit
*
* DESCRIPTION
*   Get Connection Retry Limit
*
* CALLS
*   None
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
kal_uint32 wndrv_get_connection_retry_limit ( void )
{
   /* Retry Limit. */
   return WIFI_DEFAULT_CONNECTION_RETRY_LIMIT; //2
}

/*******************************************************************************
* FUNCTION
*   wndrv_get_lcd_channel
*
* DESCRIPTION
*   Get Sleep period
*
* CALLS
*   None
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
void wndrv_get_sleep_period ( kal_uint32 *uSleep_Time, kal_uint32 *uMax_sleep_Time )
{
    /* The times of dtim period to sleep */
    *uSleep_Time = 2;
    *uMax_sleep_Time = 600; //TU

    ASSERT(*uSleep_Time > 0);
}

/*******************************************************************************
* FUNCTION
*   wndrv_get_LDO_state
*
* DESCRIPTION
*   Get LDO's state
*
* CALLS
*   None
*
* PARAMETERS
*   None
*
* RETURNS
*   TRUE or FALSE
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
kal_uint32 wndrv_get_LDO_state ( void )
{                   
   return WIFI_DEFAULT_LDO_STATE; // 0, BIT0 is 1: RF LDO always ON
                                  //    BIT0 is 0: RF LDO contorl by RADIO_CTL
}

/*******************************************************************************
* FUNCTION
*   wndrv_get_ALC_enable
*
* DESCRIPTION
*   Get ALC enable state
*
* CALLS
*   None
*
* PARAMETERS
*   None
*
* RETURNS
*   TRUE or FALSE
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
kal_bool wndrv_get_ALC_enable ( void )
{                   
   return (kal_bool)WIFI_DEFAULT_ALC_ENABLE; //0, 1: ALC enable
                                   //   0: ALC disable
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
//20081117 add by saker
#if defined(WIFI_BB_MT5921) || defined(MT5931)

kal_uint32 wndrv_get_PS_mode( void )
{

    //return PS_MAX_PSP;
    return PS_VOIP_OPTIMIZED_FAST_PSP;

}


/*******************************************************************************
* FUNCTION
*   wndrv_get_LNA_enable
*
* DESCRIPTION
*   Get LNA enable state
*
* CALLS
*   None
*
* PARAMETERS
*   None
*
* RETURNS
*   TRUE or FALSE
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
kal_bool wndrv_get_LNA_enable ( void )
{                   
   return (kal_bool)WIFI_DEFAULT_LNA_ENABLE; //0, 1: LNA enable
                                   //   0: LNA disable
}

/*******************************************************************************
* FUNCTION
*   wndrv_get_slow_clk_cfg
*
* DESCRIPTION
*   Get Xtal Trim value
*
* CALLS
*   None
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
kal_uint8 wndrv_get_slow_clk_cfg ( void )
{                   
   return WIFI_DEFAULT_SLOW_CLK_CFG; 
                                 
}
/*******************************************************************************
* FUNCTION
*   wndrv_get_daisy_chain 
*
* DESCRIPTION
*   Get daisy chain
*
* CALLS
*   None
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
kal_uint8 wndrv_get_daisy_chain ( void )
{                   
   return WIFI_DEFAULT_DAISY_CHAIN; 
                                 
}

/*******************************************************************************
* FUNCTION
*   wndrv_get_eint_polarity 
*
* DESCRIPTION
*   Set EINT polarity
*
* CALLS
*   None
*
* PARAMETERS
*   None
*
* RETURNS
*   0/1
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
kal_bool wndrv_get_eint_polarity (void)
{
    return (kal_bool)WNDRV_EINT_POLARITY;
}

kal_uint8 wndrv_set_lcd_driving_current (void)
{
    return WNDRV_SET_LCD_DRIVING_CURRENT;
}

/*******************************************************************************
* FUNCTION
*   wndrv_get_eint_selection 
*
* DESCRIPTION
*   Set EINT Ouput selection
*
* CALLS
*   None
*
* PARAMETERS
*   None
*
* RETURNS
*   0 : use default EINT 1: use GPIO2 to be EINT
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
kal_bool wndrv_get_eint_selection( void )
{
    return (kal_bool)WNDRV_DEFAULT_EINT_SELECTION; /* 0 : use default EINT 1: use GPIO2 to be EINT */
}

/*******************************************************************************
* FUNCTION
*   wndrv_get_led_setting 
*
* DESCRIPTION
*   Set LED control
*
* CALLS
*   None
*
* PARAMETERS
*   None
*
* RETURNS
*   0 : use default EINT 1: use GPIO2 to be EINT
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
kal_uint32 wndrv_get_led_setting( void )
{
    return (WNDRV_DEFAULT_LED_SETTING << 16)+((WNDRV_DEFAULT_LED_ON_TIME/4) << 8) + (WNDRV_DEFAULT_LED_OFF_TIME/4);
}

/*******************************************************************************
* FUNCTION
*   wndrv_get_wmmps_config
*
* DESCRIPTION
*   Config WMM-PS feature
*
* CALLS
*   None
*
* PARAMETERS
*   None
*
* RETURNS
*   0 : Disable WMM-PS (Default) 1: Enable WMM-PS
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
kal_bool wndrv_get_wmmps_config( void )
{
    return (kal_bool)WNDRV_DEFAULT_WMMPS_CONFIG;
}

kal_bool wndrv_get_TPCFF_enable (void)
{
    return (kal_bool)WIFI_DEFAULT_TPCFF_ENABLE;	//0, 1: TPCFF disable or enable
}

kal_uint16 wndrv_get_NVRAM_EF_WNDRV_TPCFF_LID(void)
{
    if(wndrv_get_TPCFF_enable())
        return (kal_uint16) NVRAM_EF_WNDRV_TPCFF_LID;
    else
        return (kal_uint16) 0xFFFF;
}

kal_int8 wndrv_get_rssi_low_threshold(void)
{
    kal_int8 ucRequiredRssi = WNDRV_DEFAULT_LOWEST_RSSI;
    kal_int8 ucPathLoss = WNDRV_DEFAULT_PATH_LOSS;
    return (ucRequiredRssi + ucPathLoss);
}
#endif  //#if defined(WIFI_BB_MT5921) || defined(MT5931)

#endif //#ifdef __MTK_TARGET__

