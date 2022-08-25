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
 * Filename:
 * ---------
 * custom_em.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for engineer mode.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 10 16 2013 xuejing.chen
 * removed!
 * .
 *
 * 08 29 2013 sokonisa.wei
 * removed!
 * .
 *
 * 02 18 2013 shyla.lan
 * removed!
 * .
 *
 * 02 01 2013 peter.wang
 * removed!
 * .
 *
 * 01 11 2013 peter.wang
 * removed!
 * removed!
 * .
 *
 * 01 02 2013 peter.wang
 * removed!
 * removed!
 * .
 *
 * 12 28 2012 peter.wang
 * removed!
 * .
 *
 * 11 21 2012 peter.wang
 * removed!
 * .
 *
 * 04 25 2012 pohan.chu
 * removed!
 * Fix 11B build error.
 *
 * 04 25 2012 pohan.chu
 * removed!
 * Fix 11B build error .
 *
 * 04 24 2012 pohan.chu
 * removed!
 * Integration change.
 *
 * 12 08 2011 jianhua.zhao
 * removed!
 * .
 *
 * 11 17 2011 jianhua.zhao
 * removed!
 * .
 *
 * 11 15 2011 jianhua.zhao
 * removed!
 * .
 *
 * 11 04 2011 jianhua.zhao
 * removed!
 * .
 *
 * 08 04 2011 lexel.yu
 * removed!
 * Integration change. 
 *
 * 08 02 2011 jianhua.zhao
 * removed!
 * .
 *
 * 08 02 2011 jianhua.zhao
 * removed!
 * .
 *
 * 06 02 2011 lexel.yu
 * removed!
 * Integration change. 
 *
 * 05 23 2011 jianhua.zhao
 * removed!
 * .
 *
 * 05 18 2011 jianhua.zhao
 * removed!
 * .
 *
 * 04 19 2011 pohan.chu
 * removed!
 * CUSTOM CODEC PRIORITY
 *
 * 03 03 2011 chelun.tsai
 * removed!
 * .
 *
 * 03 03 2011 jianhua.zhao
 * removed!
 * .
 *
 * 02 17 2011 xiaojian.long
 * removed!
 * Check in TDD EM BLER Statistic
 *
 * 02 16 2011 hongwei.zhang
 * removed!
 * .SRNC ID display
 *
 * 02 15 2011 cylen.yao
 * removed!
 * [HAL] MAUI custom module split
 *
 * 01 31 2011 jianhua.zhao
 * removed!
 * .
 *
 * 01 20 2011 jianhua.zhao
 * removed!
 * .
 *
 * 01 10 2011 jianhua.zhao
 * removed!
 * .
 *
 * 01 06 2011 jianhua.zhao
 * removed!
 * .
 *
 * 01 05 2011 jianhua.zhao
 * removed!
 * .
 *
 * 12 30 2010 jinxing.hu
 * removed!
 * .
 *
 * 12 28 2010 jianhua.zhao
 * removed!
 * removed!
 * .
 *
 * 12 28 2010 jianhua.zhao
 * removed!
 * .
 *
 * 12 24 2010 gordonjc.kuo
 * removed!
 * .
 *
 * 12 22 2010 jianhua.zhao
 * removed!
 * .
 *
 * 12 20 2010 jianhua.zhao
 * removed!
 * .
 *
 * 12 17 2010 jianhua.zhao
 * removed!
 * .
 *
 * 12 17 2010 jianhua.zhao
 * removed!
 * .
 *
 * 12 16 2010 jianhua.zhao
 * removed!
 * .
 *
 * 12 16 2010 jianhua.zhao
 * removed!
 * .
 *
 * 12 15 2010 lexel.yu
 * removed!
 * Integration change.
 *
 * 12 13 2010 jianhua.zhao
 * removed!
 * .
 *
 * 12 13 2010 jianhua.zhao
 * removed!
 * .
 *
 * 12 01 2010 yanfei.ding
 * removed!
 * [make c,r uas]Merge UL2 EM code backup MAUI.
 *
 * 11 30 2010 yongtuan.qiao
 * removed!
 * add TDD128 handover sequence info in EM.
 *
 * 11 30 2010 lexel.yu
 * removed!
 * <saved by Perforce>
 *
 * 11 30 2010 lexel.yu
 * removed!
 * remove swdbg_sw.h
 *
 * 11 28 2010 lexel.yu
 * removed!
 * Integration change.
 *
 * 11 27 2010 gordonjc.kuo
 * removed!
 * .
 *
 * 11 26 2010 jianhua.zhao
 * removed!
 * .
 *
 * 09 26 2010 jianhua.zhao
 * removed!
 * .
 *
 * 09 03 2010 shengkai.lin
 * removed!
 * .
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * remove compile option
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * volatile type
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Apply new EM architecture for 3G
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * add plutommi compile option
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Move secure time into custom folder.
 *
 * removed!
 * removed!
 * Add custom_config_rlc_timer() for customer can set rlc timer value, default = 3 second.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * compile error
 *
 * removed!
 * removed!
 * Let customer can configure ACM boundary, if acm is exceed the reasonable boundary, turn off ACM check and will not disconnect MO/MT call.
 *
 * removed!
 * rebase maintrunk.MAUI_MSZ on 03/17/2007 11:19:34 PM.
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Network Events notification mech. support.
 *
 * removed!
 * removed!
 * Fix MoDIS compile warning.
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * download folder name customization
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_general_types.h"
#include "lcm_if.h"
#include "kal_public_api.h"
#include "string.h"
#include "nvram_data_items.h"
#include "kal_public_defs.h"
#include "stack_common.h"
#include "Dcl.h"
#include "stack_config.h"
#include "nvram_interface.h"
#include "lcd_if.h"
#include "custom_em.h"
#include "device.h"
#include "l1audio.h"
#include "em_struct.h"
#include "dcl.h"

#include "cam_main.h"
#include "med_utility.h"
#define CAMERA_TEST_PATTERN_WIDTH   16
#define CAMERA_TEST_PATTERN_HEIGHT  12
#define CAMERA_TEST_UART_SIZE 256


#if (!defined(L4_NOT_PRESENT)) || defined(__TST_MODULE__)

#ifdef __TST_MODULE__
#include "tst.h"        /* TST extern functions */
#endif
#endif /* (!defined(L4_NOT_PRESENT)) || defined(__TST_MODULE__) */

typedef struct
{
    kal_uint32 freq[CUSTOM_EM_PWM_TYPE_MAX];
    kal_uint32 duty_cycle[CUSTOM_EM_PWM_TYPE_MAX];
} custom_em_pwm_param_set_struct;

typedef struct
{
    custom_em_pwm_param_set_struct custom_em_pwm_param;     /* PWM Current Setting */
    custom_em_pwm_param_set_struct custom_em_pwm_level_param[CUSTOM_EM_PWM_LEVEL_MAX];  /* PWM Level */
} custom_em_param_context_struct;

static void custom_em_gpio_writeIO(kal_uint8 data, kal_uint8 port);
static void custom_em_gpo_writeIO(kal_uint8 data,kal_uint8 port);

#ifndef __L1_STANDALONE__

kal_bool g_is_custom_em_init = KAL_FALSE;
custom_em_param_context_struct g_em_context;

extern void PWM_level(kal_uint8 level);

static kal_bool custom_em_init(kal_bool is_reset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 Ret, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(&g_em_context, 0, sizeof(custom_em_param_context_struct));
    g_is_custom_em_init = KAL_TRUE;
    return KAL_TRUE;
}

kal_uint8 custom_em_pwm_get_hw_current_level(CUSTOM_EM_PWM_TYPE type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DCL_HANDLE pwm_handle;
    DCL_CTRL_DATA_T data;
    switch (type)
    {
        case (CUSTOM_EM_PWM_TYPE_1):
        	  pwm_handle=DclPWM_Open(DCL_PWM1,MOD_UEM);
        	  DclPWM_Control(pwm_handle,PWM_CMD_GET_CURRENT_LEVEL,&data);
        	  DclPWM_Close(pwm_handle);
        	  return data.rPWMSaveData.pwm_level;
              
        case (CUSTOM_EM_PWM_TYPE_2):
            return 0;
            
        case (CUSTOM_EM_PWM_TYPE_3):
            pwm_handle=DclPWM_Open(DCL_PWM3, MOD_UEM);
        	  DclPWM_Control(pwm_handle,PWM_CMD_GET_CURRENT_LEVEL,&data);
        	  DclPWM_Close(pwm_handle);
        	  return data.rPWMSaveData.pwm_level;
        default:
            ASSERT(0);
            break;
    }
    return 0;
}

kal_bool custom_em_pwm_get_level_value(
            CUSTOM_EM_PWM_TYPE type,
            CUSTOM_EM_PWM_LEVEL level,
            kal_uint16 *freq,
            kal_uint8 *duty_cycle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    if (level >= CUSTOM_EM_PWM_LEVEL_MAX || type >= CUSTOM_EM_PWM_TYPE_MAX)
    {
        return KAL_FALSE;
    }

    *freq = g_em_context.custom_em_pwm_level_param[level].freq[type];
    *duty_cycle = g_em_context.custom_em_pwm_level_param[level].duty_cycle[type];

    return KAL_TRUE;
}

void custom_em_pwm_set_level(CUSTOM_EM_PWM_TYPE type, kal_uint8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case (CUSTOM_EM_PWM_TYPE_1):
            PWM_level(level);
            break;
        case (CUSTOM_EM_PWM_TYPE_2):
            break;
        case (CUSTOM_EM_PWM_TYPE_3):
            PWM3_level(level);
            break;
        default:
            ASSERT(0);
            break;
    }

}

kal_bool custom_em_pwm_set_level_value(
            CUSTOM_EM_PWM_TYPE type,
            CUSTOM_EM_PWM_LEVEL level,
            kal_uint16 freq,
            kal_uint8 duty_cycle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    if (level >= CUSTOM_EM_PWM_LEVEL_MAX || type >= CUSTOM_EM_PWM_TYPE_MAX)
    {
        return KAL_FALSE;
    }

    g_em_context.custom_em_pwm_level_param[level].freq[type] = freq;
    g_em_context.custom_em_pwm_level_param[level].duty_cycle[type] = duty_cycle;


    return KAL_TRUE;

}

void custom_em_pwm_start(CUSTOM_EM_PWM_TYPE type, kal_uint32 freq, kal_uint32 duty)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DCL_HANDLE pwm_handle;
    PWM_CMD_CONFIG_OLD_T old_config;
    ALERTER_CONFIGURE_T  alerter_config;
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    switch (type)
    {
        case (CUSTOM_EM_PWM_TYPE_1):
            pwm_handle=DclPWM_Open(DCL_PWM1,MOD_UEM);
            old_config.freq=freq;
            old_config.duty=duty;
            DclPWM_Control(pwm_handle,PWM_CMD_CONFIG_OLD,(DCL_CTRL_DATA_T*)&old_config);
            DclPWM_Control(pwm_handle,PWM_CMD_START,0);
            DclPWM_Close(pwm_handle);
            break;

        case (CUSTOM_EM_PWM_TYPE_2):
            break;

        case (CUSTOM_EM_PWM_TYPE_3):
            pwm_handle=DclPWM_Open(DCL_PWM3,MOD_UEM);
            old_config.freq=freq;
            old_config.duty=duty;
            DclPWM_Control(pwm_handle,PWM_CMD_CONFIG_OLD,(DCL_CTRL_DATA_T*)&old_config);
            DclPWM_Control(pwm_handle,PWM_CMD_START,0);
            DclPWM_Close(pwm_handle);
            break;

        default:
            ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_pwm_stop
 * DESCRIPTION
 *
 * PARAMETERS
 *  type        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_pwm_stop(CUSTOM_EM_PWM_TYPE type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DCL_HANDLE pwm_handle;
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    switch (type)
    {
        case (CUSTOM_EM_PWM_TYPE_1):
            pwm_handle=DclPWM_Open(DCL_PWM1,MOD_UEM);
            DclPWM_Control(pwm_handle,PWM_CMD_STOP,0);
            DclPWM_Close(pwm_handle);
            break;

        case (CUSTOM_EM_PWM_TYPE_2):
            break;

        case (CUSTOM_EM_PWM_TYPE_3):
            pwm_handle=DclPWM_Open(DCL_PWM3,MOD_UEM);
            DclPWM_Control(pwm_handle,PWM_CMD_STOP,0);
            DclPWM_Close(pwm_handle);
            break;

        default:
            ASSERT(0);
            break;
    }
}

void custom_em_pwm_get_value(kal_uint16 *freq, kal_uint8 *duty_cycle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    kal_mem_cpy(freq, g_em_context.custom_em_pwm_param.freq, sizeof(g_em_context.custom_em_pwm_param.freq));
    kal_mem_cpy(
        duty_cycle,
        g_em_context.custom_em_pwm_param.duty_cycle,
        sizeof(g_em_context.custom_em_pwm_param.duty_cycle));
}


/*****************************************************************************
 * FUNCTION
 *  custom_em_pwm_set_value
 * DESCRIPTION
 *
 * PARAMETERS
 *  freq            [?]
 *  duty_cycle      [?]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_pwm_set_value(kal_uint16 *freq, kal_uint8 *duty_cycle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_is_custom_em_init != KAL_TRUE)
    {
        custom_em_init(KAL_FALSE);
    }

    kal_mem_cpy(g_em_context.custom_em_pwm_param.freq, freq, sizeof(g_em_context.custom_em_pwm_param.freq));
    kal_mem_cpy(
        g_em_context.custom_em_pwm_param.duty_cycle,
        duty_cycle,
        sizeof(g_em_context.custom_em_pwm_param.duty_cycle));
}

/*****************************************************************************
 * FUNCTION
 *  custom_em_gpio_start
 * DESCRIPTION
 *
 * PARAMETERS
 *  port        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_gpio_start(kal_uint8 port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    custom_em_gpio_writeIO(1, port);
}

/*****************************************************************************
 * FUNCTION
 *  custom_em_gpio_stop
 * DESCRIPTION
 *
 * PARAMETERS
 *  port        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_gpio_stop(kal_uint8 port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    custom_em_gpio_writeIO(0, port);
}

/*****************************************************************************
 * FUNCTION
 *  custom_em_gpo_writeio
 * DESCRIPTION
 *
 * PARAMETERS
 *  data        [IN]
 *  port        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_gpo_writeio(kal_int8 data, kal_int8 port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    custom_em_gpo_writeIO(data, port);
}


#endif /* __L1_STANDALONE__ */

static kal_uint8 CTI_UART_PORT = 0;
static UART_baudrate CTI_BAUD_RATE = 0;

kal_bool High_Speed_SIM = KAL_FALSE;
kal_uint8 UART_POWER_SETTING = 0;

kal_uint8 g_usb_cdrom_config;

#ifdef __TST_MODULE__
extern UART_PORT TST_PORT;
extern UART_baudrate TST_BAUDRATE;

extern UART_PORT TST_PORT_L1;
extern UART_baudrate TST_BAUDRATE_L1;

#if defined(__DSP_FCORE4__)	
  extern UART_PORT TST_PORT_DSP;
  extern UART_baudrate TST_BAUDRATE_DSP;
#endif	//#if defined(__DSP_FCORE4__)		

/* This macro can be located at the makefile */
#ifdef __TST_WRITE_TO_FILE__
extern kal_uint8 TST_OUTPUT_MODE;
#endif

#ifndef L4_NOT_PRESENT
extern UART_PORT PS_UART_PORT;
extern UART_baudrate PS_BAUDRATE;
#endif /* L4_NOT_PRESENT */
#endif /* __TST_MODULE__ */
extern kal_uint8 SWDBG_Profile;
extern kal_uint32 BytesPerCluster;  /* will be set to exact value in nvram_get_disk_file_info */

#if defined(__USB_LOGGING__)
/* under construction !*/
#endif

extern void UART_TurnOnPower(UART_PORT port, kal_bool enable);
static kal_bool custom_em_is_uart_used(UART_PORT port);

#ifndef __MAUI_BASIC__

static void custom_em_uart_turnon_power(UART_PORT port, kal_bool on);


/*****************************************************************************
 * FUNCTION
 *  nvram_config_com_port
 * DESCRIPTION
 *  To init COM port setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif

void custom_em_nvram_config_com_port(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *buffer = NULL;
    kal_bool result;
#if defined(__BOOT_FOR_USBAT__) && defined(__MTK_TARGET__)
    kal_bool for_usbat = KAL_FALSE;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    buffer = (kal_uint8*) get_ctrl_buffer(NVRAM_EF_PORT_SETTING_SIZE);

    if (buffer)
    {
        port_setting_struct *port_setting;

        result = nvram_external_read_data(NVRAM_EF_PORT_SETTING_LID, 1, buffer, NVRAM_EF_PORT_SETTING_SIZE);

        /* Ok, now config UART/IrCOMM ports for L4 and TST, and filters to TST */
        if (result)
        {
        #if defined(__BOOT_FOR_USBAT__) && defined(__MTK_TARGET__)
            for_usbat = INT_IsBootForUSBAT();
        #endif
            
            
            port_setting = (port_setting_struct*) buffer;

        #ifdef __TST_MODULE__

        #ifdef __IRDA_SUPPORT__
            if ( (uart_port_irda == (UART_PORT) port_setting->tst_port_ps) ||
                 (uart_port_irda == (UART_PORT) port_setting->tst_port_l1))
            {
                init_ircomm_module();
                IRDA_Open();
            }
        #endif /* __IRDA_SUPPORT__ */
        
        #if defined(__BOOT_FOR_USBAT__) && defined(__MTK_TARGET__)
            if (for_usbat)
            {
                TST_PORT = (UART_PORT) uart_port1;
                TST_PORT_L1 = (UART_PORT) uart_port1;
            }
            else
        #endif
            {
            TST_PORT = (UART_PORT) port_setting->tst_port_ps;
            TST_PORT_L1 = (UART_PORT) port_setting->tst_port_l1;
            }
        
            TST_BAUDRATE = port_setting->tst_baudrate_ps;
            TST_BAUDRATE_L1 = port_setting->tst_baudrate_l1;

        #ifndef L4_NOT_PRESENT
            #if defined(__BOOT_FOR_USBAT__) && defined(__MTK_TARGET__)
                if (for_usbat)
                {
                    PS_UART_PORT = (UART_PORT) uart_port_usb;
                }
                else
            #endif
                {
                PS_UART_PORT = (UART_PORT) port_setting->ps_port;
                }
            PS_BAUDRATE = port_setting->ps_baudrate;
            
        #endif /* L4_NOT_PRESENT */
                		                		
        #if defined(__DSP_FCORE4__)	
            TST_PORT_DSP = (UART_PORT) port_setting->tst_port_dsp;
            TST_BAUDRATE_DSP = port_setting->tst_baud_rate_dsp;
        #endif	//#if defined(__DSP_FCORE4__)	
        
        #endif /* __TST_MODULE__ */

            High_Speed_SIM = port_setting->High_Speed_SIM_Enabled;

            if (High_Speed_SIM)
            {
                // remove
            }

            SWDBG_Profile = port_setting->swdbg;
            UART_POWER_SETTING = port_setting->uart_power_setting;
            CTI_UART_PORT = port_setting->cti_uart_port;
            CTI_BAUD_RATE = port_setting->cti_baudrate;

        #ifdef __TST_WRITE_TO_FILE__
            TST_OUTPUT_MODE = port_setting->tst_output_mode;
        #endif
        
        #if defined(__USB_LOGGING__)
/* under construction !*/
        #endif
            
        #ifdef __MTK_TARGET__
        #ifndef __L1_STANDALONE__
            /* To determine if in META mode */
            if (FACTORY_BOOT != stack_query_boot_mode())
            {
                kal_bool enable;

                if (custom_em_is_uart_used(uart_port1))
                {
                    custom_em_uart_turnon_power(uart_port1, KAL_TRUE);
                }
                else
                {
                    custom_em_uart_turnon_power(uart_port1, KAL_FALSE);
                }
            #ifndef __SMART_PHONE_MODEM__
                if (custom_em_is_uart_used(uart_port2))
                {
                    custom_em_uart_turnon_power(uart_port2, KAL_TRUE);
                }
                else
                {
                    custom_em_uart_turnon_power(uart_port2, KAL_FALSE);
                }
           
                if (custom_em_is_uart_used(uart_port3))
                {
                    custom_em_uart_turnon_power(uart_port3, KAL_TRUE); 
                }
                else
                {
                    custom_em_uart_turnon_power(uart_port3, KAL_FALSE);
                }
            #endif
            }
            else    /* In META Mode, Turn on every UART power */
        #endif /* __L1_STANDALONE__ */
            {
            #ifndef __SMART_PHONE_MODEM__
                custom_em_uart_turnon_power(uart_port1, KAL_TRUE);
                custom_em_uart_turnon_power(uart_port2, KAL_TRUE);
                custom_em_uart_turnon_power(uart_port3, KAL_TRUE);
            #endif
            }
        #endif /* __MTK_TARGET__ */

            g_usb_cdrom_config = port_setting->usb_cdrom_config;
        }

        free_ctrl_buffer(buffer);
    }

    buffer = NULL;

#if (!defined(L4_NOT_PRESENT)) || defined(__TST_MODULE__)
    /* If L4 or TST exist */

    buffer = (kal_uint8*) get_ctrl_buffer(NVRAM_EF_TST_FILTER_SIZE);

    if (buffer != NULL)
    {
        result = nvram_external_read_data(NVRAM_EF_TST_FILTER_LID, 1, buffer, NVRAM_EF_TST_FILTER_SIZE);

        /* Ok, now config UART/IrCOMM ports for L4 and TST, and filters to TST */
        if (result)
        {
        #ifdef __TST_MODULE__
            tst_init_filters((kal_char*) buffer, NVRAM_EF_TST_FILTER_SIZE);
        #endif
        }

        free_ctrl_buffer(buffer);
    }
    #if defined(__TST_MODULE__) && defined(__MTK_TARGET__)

    //Shengkai: check if we need to enable the spare ram logging mechanism
    buffer = (kal_uint8*) get_ctrl_buffer(NVRAM_EF_TST_CONFIG_SIZE);

    if (buffer != NULL)
    {
        result = nvram_external_read_data(NVRAM_EF_TST_CONFIG_LID, 1, buffer, NVRAM_EF_TST_CONFIG_SIZE);

        if (result)
        {
			extern kal_uint8 tst_meta_mode_trace_nvram_enable_flag;
			extern kal_bool tst_is_auto_memory_dump;
			tst_meta_mode_trace_nvram_enable_flag = ((tst_config_struct_t *)buffer)->meta_mode_trace_enable;
			if(tst_meta_mode_trace_nvram_enable_flag != 1 && tst_meta_mode_trace_nvram_enable_flag != 2)
				tst_meta_mode_trace_nvram_enable_flag = 0;			
			if(tst_meta_mode_trace_nvram_enable_flag == 2)
				tst_is_auto_memory_dump = KAL_TRUE;        
        }

        free_ctrl_buffer(buffer);
    }
    #endif //    #if defined(__TST_MODULE__) && defined(__MTK_TARGET__)    

#endif /* (!defined(L4_NOT_PRESENT)) || defined(__TST_MODULE__) */
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif

static kal_bool custom_em_is_uart_used(UART_PORT port)
{
#if (!defined(L4_NOT_PRESENT)) || defined(__TST_MODULE__)  
    if (TST_PORT == port ||
        TST_PORT_L1 == port 
    #ifndef L4_NOT_PRESENT
        || PS_UART_PORT == port
    #endif 
    #if defined(__DSP_FCORE4__)
        || TST_PORT_DSP == port 
    #endif
        )
    {
        return KAL_TRUE;
    }
    else
#endif  //#if (!defined(L4_NOT_PRESENT)) || defined(__TST_MODULE__)      
    {
        return KAL_FALSE;
    }
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

/*****************************************************************************
 * FUNCTION
 *  custom_em_get_usb_cdrom_config
 * DESCRIPTION
 *  To get USB CDROM configure value
 * PARAMETERS
 *  void
 * RETURNS
 *  0 for CDROM, 1 for COM
 *****************************************************************************/
kal_uint8 custom_em_get_usb_cdrom_config(void)
{
    return g_usb_cdrom_config;
}

/*****************************************************************************
 * FUNCTION
 *  custom_em_set_usb_cdrom_config
 * DESCRIPTION
 *  To set USB CDROM configure value
 * PARAMETERS
 *  value
 * RETURNS
 *  void
 *****************************************************************************/
void custom_em_set_usb_cdrom_config(kal_uint8 cdrom_config)
{
    g_usb_cdrom_config = cdrom_config;
}

#endif /* #ifndef __MAUI_BASIC__*/

/*****************************************************************************
 * FUNCTION
 *  nvram_get_cti
 * DESCRIPTION
 *  To get CTI_UART_PORT
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8   [OUT]   CTI
 *****************************************************************************/
void nvram_get_cti(kal_uint8 *port, kal_uint32 *baudrate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    *port = CTI_UART_PORT;
    *baudrate = (kal_uint32) CTI_BAUD_RATE;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_get_tst
 * DESCRIPTION
 *  To get TST_UART_PORT
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8   [OUT]   CTI
 *****************************************************************************/
void nvram_get_tst(kal_uint8 *port, kal_uint32 *baudrate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
#ifdef __TST_MODULE__
    *port = TST_PORT;
    *baudrate = (kal_uint32) TST_BAUDRATE;
#endif
    return;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_get_tst
 * DESCRIPTION
 *  To get nvram_get_tst_l1
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8   [OUT]   CTI
 *****************************************************************************/
void nvram_get_tst_l1(kal_uint8 *port, kal_uint32 *baudrate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
#ifdef __TST_MODULE__
    *port = TST_PORT_L1;
    *baudrate = (kal_uint32) TST_BAUDRATE_L1;
#endif
    return;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_get_tst
 * DESCRIPTION
 *  To get TST_UART_PORT
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8   [OUT]   CTI
 *****************************************************************************/
void nvram_get_tst_dsp(kal_uint8 *port, kal_uint32 *baudrate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
#if defined(__TST_MODULE__)
	#if defined(__DSP_FCORE4__)	
    *port = TST_PORT_DSP;
    *baudrate = (kal_uint32) TST_BAUDRATE_DSP;
  #else	//#if defined(__DSP_FCORE4__)	
  	*port = uart_port_null;
    *baudrate = 115200;
  #endif	//#if defined(__DSP_FCORE4__)	
#endif
    return;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_get_ps
 * DESCRIPTION
 *  To get PS_UART_PORT
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8   [OUT]   CTI
 *****************************************************************************/
void nvram_get_ps(kal_uint8 *port, kal_uint32 *baudrate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
#ifdef __TST_MODULE__
#ifndef L4_NOT_PRESENT
    *port = PS_UART_PORT;
    *baudrate = (kal_uint32) PS_BAUDRATE;
#else
    *port = NULL;
    *baudrate = (kal_uint32) NULL;
#endif /* L4_NOT_PRESENT */
#endif
    return;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_get_swdbg
 * DESCRIPTION
 *  To get SWDBG_Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8   [OUT]   swdbg_profile
 *****************************************************************************/
void nvram_get_swdbg(kal_uint8 *swdbg_profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    *swdbg_profile = SWDBG_Profile;
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif

void custom_em_uart_turnon_power(UART_PORT port, kal_bool on)
{
    DCL_HANDLE handle;
    UART_CTRL_POWERON_T data;
    
    handle = DclSerialPort_Open(port, 0);
    data.bFlag_Poweron = on;
    DclSerialPort_Control(handle, UART_CMD_POWER_ON, (DCL_CTRL_DATA_T*)&data);
    
    DclSerialPort_Close(handle);
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

static void custom_em_gpio_writeIO(kal_uint8 data, kal_uint8 port)
{
	DCL_HANDLE handle;
    
	handle=DclGPIO_Open(DCL_GPIO, port);	

    if(0 == data)
		DclGPIO_Control(handle,GPIO_CMD_WRITE_LOW,0);
	else if(1 == data)
		DclGPIO_Control(handle,GPIO_CMD_WRITE_HIGH,0);
	
	DclGPIO_Close(handle);	
}

static void custom_em_gpo_writeIO(kal_uint8 data,kal_uint8 port)
{
	DCL_HANDLE handle;
    
	handle=DclGPIO_Open(DCL_GPO,port);	

    if(0 == data)
		DclGPIO_Control(handle,GPO_CMD_WRITE_LOW,0);
	else if(1 == data)
		DclGPIO_Control(handle,GPO_CMD_WRITE_HIGH,0);

	DclGPIO_Close(handle);
}

#if defined(__MTK_TARGET__)
#if ((defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__)) && defined(ISP_SUPPORT))
kal_bool custom_em_test_camera_req(kal_uint8 type,kal_uint8 ratio)
{
    kal_bool result=KAL_FALSE;
    kal_uint32 sensor_id=0;
    char buffer[128+1];
    char buff[20];
    kal_uint32 cameral_size;
    kal_uint8 *p_cameral;
    kal_uint8  buffer_ex[CAMERA_TEST_UART_SIZE+1];
    kal_uint32  count;
    kal_uint32 data_len;
    MM_ERROR_CODE_ENUM ret;
    kal_uint32 curr_tick;
    kal_uint32 prev_tick;

//    kal_prompt_trace(MOD_ATCI, "custom_em_test_camera_req type: %d,%d",type,ratio);

    if (type== 0) /* Get Sensor Id */
    {
        ret=CATSInit(0);
        if(MM_ERROR_NONE !=ret)
        {
           return KAL_FALSE;

        }
        CATSFeatureCtrl(CATS_FEATURE_GET_SENSOR_ID, NULL, &sensor_id);

        CATSDeinit();

        sprintf(buffer, "+ECMFP:%d",sensor_id);
        rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);

        result=KAL_TRUE;
    }
    else if (type==1||type==2)
    {
        cats_frame_buff_st test_pattern={0};
        cats_compare_result_st comp_result = {0};
        ret=CATSInit(0);
        if(MM_ERROR_NONE !=ret)
        {
            return KAL_FALSE;
        }
        CATSFeatureCtrl(CATS_FEATURE_GET_PATTERN_FORMAT, NULL, &(test_pattern.color_format));
        test_pattern.frame_width = CAMERA_TEST_PATTERN_WIDTH;
        test_pattern.frame_height = CAMERA_TEST_PATTERN_HEIGHT;

        test_pattern.frame_buffer_size = test_pattern.frame_width * test_pattern.frame_height * 2;
        test_pattern.frame_buffer = (kal_uint32) med_alloc_asm_mem(0, test_pattern.frame_buffer_size);
        if (NULL == test_pattern.frame_buffer)
        {
            CATSDeinit();

            return KAL_FALSE;
        }

        ret = CATSFeatureCtrl(CATS_FEATURE_GET_TEST_PATTERN, &test_pattern, NULL);
        if(MM_ERROR_NONE ==ret)
        {
            if (type==1)
            {
                p_cameral = (kal_uint8*)test_pattern.frame_buffer;
                cameral_size = test_pattern.frame_buffer_size;
                sprintf (buff, "size : %d,%d,%d,%d\r\n",CAMERA_TEST_PATTERN_WIDTH,CAMERA_TEST_PATTERN_HEIGHT, cameral_size, CAMERA_TEST_UART_SIZE);
                rmmi_write_to_uart((kal_uint8*)buff, strlen(buff), KAL_TRUE);

                count=0;
                kal_get_time(&curr_tick);//for test
                prev_tick=curr_tick;
                while (cameral_size >0 )
                {
                    sprintf (buffer, "\r\n+ECMFP:%d",count);
                    rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);

                    if(cameral_size>CAMERA_TEST_UART_SIZE)
                    {
                        data_len=CAMERA_TEST_UART_SIZE;
                        memcpy (buffer_ex, p_cameral, data_len*sizeof(kal_uint8));
                        buffer_ex[CAMERA_TEST_UART_SIZE] = '\0';
                        rmmi_write_to_uart((kal_uint8 *)buffer_ex, data_len, KAL_TRUE);

                        p_cameral += CAMERA_TEST_UART_SIZE;
                        cameral_size -= CAMERA_TEST_UART_SIZE;
                    }
                    else        //each +EIMG or +EMDY print at most 64 bytes
                    {
                        data_len=cameral_size;
                        memcpy (buffer_ex, p_cameral, data_len*sizeof(kal_uint8));
                        buffer_ex[data_len] = '\0';
                        rmmi_write_to_uart((kal_uint8*)buffer_ex,data_len, KAL_TRUE);

                        cameral_size = 0;
                    }
                    count++;
                    kal_sleep_task(2);
                }
                kal_get_time(&curr_tick);
                sprintf (buffer, "\r\n+ECMFP:LASTLAST! Total%d ticks",curr_tick-prev_tick);
                rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);

                result=KAL_TRUE;
            }  // get fix pattern to PC
            else if(type == 2)// compare by self
            {
                test_pattern.err_ratio_threshold=ratio;
                ret = CATSFeatureCtrl(CATS_FEATURE_COMPARE_TEST_PATTERN, &test_pattern, &comp_result);
//                kal_prompt_trace(MOD_ATCI,"[Compare] ret = %d, err_ratio = %d, err_pattern_cnt=%d, pattern_size=%d", \
                    ret, comp_result.err_ratio, comp_result.err_pattern_cnt, comp_result.pattern_size); // ????Error Ratio, Error Byte Count???????Bytes???????
                sprintf(buffer, "+ECMFP:%d,%d,%d,%d",ret, comp_result.err_ratio, comp_result.err_pattern_cnt, comp_result.pattern_size);
                rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
                if (MM_ERROR_NONE == ret)
                {
                    result=KAL_TRUE;/* Successeed, the pattern from sensor is same with stored pattern. */
                }
                else
                {
                    result=KAL_FALSE;/* Compare the test pattern failed. */
                }
            }
        }
        else
        {
            result=KAL_FALSE;
        }
        CATSDeinit();

        med_free_asm_mem(0, (void **)&test_pattern.frame_buffer);
    }

//   kal_prompt_trace(MOD_ATCI, "custom_em_test_camera_req result:%d",result);
   return result;
}
#endif
#endif  /* #if defined(__MTK_TARGET__) */


