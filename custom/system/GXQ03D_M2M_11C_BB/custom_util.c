/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   custom_util.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides the custom utililty APIs
 *
 * Author:
 * -------
 * -------    system auto generator  V1.95 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*************************************************************************
 * Include Header Files
 *************************************************************************/
#include "kal_general_types.h"
#include "uart_sw.h"
#include "kal_trace.h"
#include "custom_FeatureConfig.h"
#include "dcl.h"
#include "custom_util.h"
#if defined(__KAL_RECORD_BOOTUP_LOG__) || defined(__KEYPAD_DEBUG_TRACE__)
#include "kbd_table.h"
#endif /* __KAL_RECORD_BOOTUP_LOG__ || __KEYPAD_DEBUG_TRACE__ */

/*************************************************************************
 * Function Declaration
 *************************************************************************/
#if !defined(__FUE__) && !defined(__UBL__)
#ifdef DRV_DEBUG
extern void dbg_print(char *fmt,...);
#endif /* DRV_DEBUG */
extern kal_uint32 INT_GetCurrentTime(void);
#endif /* !__FUE__ && !__UBL__ */

/*************************************************************************
 * Global variable declaration
 *************************************************************************/
#if defined(__KAL_RECORD_BOOTUP_LOG__) || defined(__KEYPAD_DEBUG_TRACE__)
  kal_bool is_init_log_enable; // setup in INT_setInitLogFlag
  kal_bool is_init_stage;
#if defined(__USB_BOOTUP_TRACE__)
  const UART_PORT debug_port = uart_port_usb;
#else /* __USB_BOOTUP_TRACE__ */
#if defined(DEBUG_PORT)
  const UART_PORT debug_port = DEBUG_PORT;
#else  /* DEBUG_PORT */
  const UART_PORT debug_port = uart_port1;
#endif  /* DEBUG_PORT */
#endif /* __USB_BOOTUP_TRACE__ */
#if defined(DEBUG_BAUDRATE)
  const UART_baudrate debug_baudrate = DEBUG_BAUDRATE;
#else  /* DEBUG_BAUDRATE */
  const UART_baudrate debug_baudrate = 921600;
#endif  /* DEBUG_BAUDRATE */
#else /* __USB_BOOTUP_TRACE__ || __KEYPAD_DEBUG_TRACE__ */
  const kal_bool is_init_log_enable = KAL_FALSE;
  kal_bool is_init_stage = KAL_TRUE;
  const UART_PORT debug_port = uart_port1;
  const UART_baudrate debug_baudrate = 921600;
#endif  /* __USB_BOOTUP_TRACE__ || __KEYPAD_DEBUG_TRACE__ */

/*************************************************************************
* FUNCTION
*  custom_print
*
* DESCRIPTION
*       This function implements output display through uart port for custom
*       debugging without MTK tool utility.
*
*       Notice:
*       The routine is possibly to hit race condition because of reentrant caller.
*
* PARAMETERS
*       string  -       output string
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if !defined(__FUE__) && !defined(__UBL__)
void custom_print(kal_char* string)
{
#ifdef DRV_DEBUG
    dbg_print("%s\r\n", string);
#elif defined(__TST_MODULE__) && defined(__CUSTOM_RELEASE__)
    //kal_print(string);
    kal_prompt_trace(MOD_MMI,"%s",string);
#endif /* DVR_DEBUG */
}
#endif /* !__FUE__ && !__UBL__ */


#if defined(__KAL_RECORD_BOOTUP_LOG__) || defined(__KEYPAD_DEBUG_TRACE__)
/*************************************************************************
* FUNCTION
*  custom_IsBootupTraceKeyPressed
*
* DESCRIPTION
*       This function is used to detect if the key combination is pressed.
*
*
* PARAMETERS
*       None
*
* RETURNS
*       status: does combination match
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_IsBootupTraceKeyPressed(void)
{
    /* the key combination could be customized */   
    if ( custom_InitIsKeyPressed(DEVICE_KEY_SK_LEFT) && 
         (custom_InitIsKeyPressed(DEVICE_KEY_POWER) || custom_InitIsKeyPressed(DEVICE_KEY_END)) )
    {
        return KAL_TRUE;
    }

    return KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*  custom_InitKeypadGPIO
*
* DESCRIPTION
*       This function is used to initialize Keypad GPIO.
*       You should invoke it before detecting key pressed.
*
*
* PARAMETERS
*       None
*
* RETURNS
*       None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void custom_InitKeypadGPIO(void)
{
#if defined(MT6236) || defined(MT6236B) || defined(MT6251) || defined(MT6252) || defined(MT6276) || defined(MT6256) || defined(MT6255) || defined(MT6250)
#ifdef __CUST_NEW__
    kal_uint32 n;
    kal_uint32 key_press_delay_start=0;
    kal_uint32 elapsed;
    kal_uint16 key_press_delay=6554;//   26/128Hz=200ms


#define KEYPAD_GPIO_INIT(x) \
{\
    extern const kal_uint8 gpio_keypad_##x##_pin;\
    extern const kal_uint8 gpio_keypad_##x##_pin_M_DEFAULT;\
    if(gpio_keypad_ ##x##_pin != 0xFF)\
    {\
        handle = DclGPIO_Open(DCL_GPIO, gpio_keypad_##x##_pin);\
        DclGPIO_Control(handle, gpio_keypad_##x##_pin_M_DEFAULT, 0);\
        DclGPIO_Close(handle);\
    }\
}
    DCL_HANDLE handle;

    KEYPAD_GPIO_INIT(col0);
    KEYPAD_GPIO_INIT(col1);
    KEYPAD_GPIO_INIT(col2);
    KEYPAD_GPIO_INIT(col3);
    KEYPAD_GPIO_INIT(col4);
    KEYPAD_GPIO_INIT(col5);
    KEYPAD_GPIO_INIT(col6);
    KEYPAD_GPIO_INIT(col7);
    KEYPAD_GPIO_INIT(col8);
    KEYPAD_GPIO_INIT(col9);
    
    KEYPAD_GPIO_INIT(row0);
    KEYPAD_GPIO_INIT(row1);
    KEYPAD_GPIO_INIT(row2);
    KEYPAD_GPIO_INIT(row3);
    KEYPAD_GPIO_INIT(row4);
    KEYPAD_GPIO_INIT(row5);
    KEYPAD_GPIO_INIT(row6);
    KEYPAD_GPIO_INIT(row7);
    KEYPAD_GPIO_INIT(row8);
    KEYPAD_GPIO_INIT(row9);
    
    /* delay for a while */    
    key_press_delay_start=INT_GetCurrentTime();
    for(n=0; n<300000; n++)
    {
         elapsed=INT_GetCurrentTime()-key_press_delay_start;
         if(elapsed>=key_press_delay)
	           break;
    }
#endif /* __CUST_NEW__ */
#endif
}

#if !defined(__FUE__) && !defined(__UBL__)
/*************************************************************************
* FUNCTION
*  custom_InitIsKeyPressed
*
* DESCRIPTION
*       This function is used to detect if the specific key is pressed.
*
*
* PARAMETERS
*       key  -       the key to be detected
*
* RETURNS
*       status
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_InitIsKeyPressed(kal_uint8 key)
{
    HKBD_CTRL_KEY_STA_T keysta;
    DCL_HANDLE handle;
		
    keysta.key = key;
    handle = DclHKBD_Open(DCL_KBD, 0);
    DclHKBD_Control(handle,HKBD_CMD_GET_KEY_STATUS , (DCL_CTRL_DATA_T*)&keysta);
	
    if (keysta.sta)
    {
        return KAL_TRUE;
    }
	
    return KAL_FALSE;
}
#endif /* !__FUE__ && !__UBL__ */

#endif /* __KAL_RECORD_BOOTUP_LOG__ || __KEYPAD_DEBUG_TRACE__ */

