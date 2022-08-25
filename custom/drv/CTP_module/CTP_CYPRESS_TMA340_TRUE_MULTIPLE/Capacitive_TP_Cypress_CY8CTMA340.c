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
 *   Capacitive_TP_Cypress_CY8CTMA340.c
 *
 *
 * Description:
 * ------------
 *   Capacitive Touch Panel I2C read/write Driver
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "kal_release.h"
#include "dcl.h"
#include "touch_panel.h"
#include "eint.h"
#include "Capacitive_TP_Cypress_CY8CTMA340.h"
#include "Capacitive_TP_I2C.h"
#include "us_timer.h"
#include "Capacitive_TP_trc.h"
	
#if !defined(IC_MODULE_TEST)
extern kal_uint32 /*lint -e(526)*/L1I_GetTimeStamp(void);
#endif

kal_uint32 CTP_DELAY_TIME	= 3;//400;
kal_uint32 CTP_HW_I2C_SPEED	= 400;

CTP_parameters_struct CTP_parameters;
extern const char gpio_ctp_power_enable_pin;
extern const char gpio_ctp_reset_pin;
extern const char gpio_ctp_eint_pin;
extern const char gpio_ctp_i2c_sda_pin;
extern const char gpio_ctp_i2c_scl_pin;

extern kal_bool ctp_cypress_upgrader(void);

DCL_HANDLE ctp_gpio_power_handle;
DCL_HANDLE ctp_gpio_eint_handle;
DCL_HANDLE ctp_gpio_reset_handle;

kal_uint32 ctp_delay_count = 3;
CTP_custom_information_struct  ctp_custom_information_def = 
{
	"CYPRESS ",
	"8CTMA340",
	"UNKNOWN ",	
};


kal_bool CTP_I2C_write_byte(kal_uint8 ucBufferIndex, kal_uint8 pucData)
{
	return ctp_i2c_send(CTP_SLAVE_ADDR,ucBufferIndex,&pucData,1);
}


#define CTP_I2C_read(a,b,c) ctp_i2c_receive(CTP_SLAVE_ADDR,a,b,c)

void ctp_cypress_cy8ctma340_power(kal_bool ON)
{
	static kal_bool power_status = KAL_FALSE;
	kal_bool sleep, wakeup;
	
	if(ON == power_status) //do not turn on/off pmu ldo again.
		return;
	power_status = ON;
	
	if(gpio_ctp_power_enable_pin != 0xFF)
	{
		DclGPIO_Control(ctp_gpio_power_handle, GPIO_CMD_SET_MODE_0, NULL);
		DclGPIO_Control(ctp_gpio_power_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	}
	if(gpio_ctp_reset_pin != 0xFF)
	{
		DclGPIO_Control(ctp_gpio_reset_handle, GPIO_CMD_SET_MODE_0, NULL);
		DclGPIO_Control(ctp_gpio_reset_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	}
	if(ON)
	{
		wakeup = CTP_I2C_write_byte(HST_MODE_ADDR, HST_MODE_NORMAL); //toggle the controller.
		if(gpio_ctp_power_enable_pin != 0xFF)
			DclGPIO_Control(ctp_gpio_power_handle, GPIO_CMD_WRITE_HIGH, NULL);
		ctp_i2c_udelay(1000);
		if(gpio_ctp_reset_pin != 0xFF)
			DclGPIO_Control(ctp_gpio_reset_handle, GPIO_CMD_WRITE_LOW, NULL);
		ctp_i2c_udelay(10000);
		if(gpio_ctp_reset_pin != 0xFF)
			DclGPIO_Control(ctp_gpio_reset_handle, GPIO_CMD_WRITE_HIGH, NULL);
		drv_trace2(TRACE_GROUP_10, CTP_CAPACITIVE_POWER, ON, wakeup);
	}
	else
	{
		sleep = CTP_I2C_write_byte(HST_MODE_ADDR, HST_MODE_DEEP_SLEEP); //toggle the controller.
		drv_trace2(TRACE_GROUP_10, CTP_CAPACITIVE_POWER, ON, sleep);
		if(!sleep)
		{
			if(gpio_ctp_power_enable_pin != 0xFF)
				DclGPIO_Control(ctp_gpio_power_handle, GPIO_CMD_WRITE_LOW, NULL);
			drv_trace0(TRACE_GROUP_10, CTP_CAPACITIVE_POWER_DOWN);
		}
	}
	ctp_i2c_power_on(ON, CTP_I2C_LDO, 0);
}

void ctp_cypress_cy8ctma340_enter_system_mode()
{
	if((gpio_ctp_reset_pin != 0xFF) && (gpio_ctp_eint_pin != 0xFF))
	{
		ctp_i2c_configure(CTP_SLAVE_ADDR, 50);
	
		DclGPIO_Control(ctp_gpio_eint_handle, GPIO_CMD_SET_MODE_0, NULL);
		DclGPIO_Control(ctp_gpio_eint_handle, GPIO_CMD_WRITE_LOW, NULL);
		DclGPIO_Control(ctp_gpio_eint_handle, GPIO_CMD_SET_DIR_OUT, NULL);
		DclGPIO_Control(ctp_gpio_eint_handle, GPIO_CMD_ENABLE_PULL, NULL);
		DclGPIO_Control(ctp_gpio_eint_handle, GPIO_CMD_SET_PULL_HIGH, NULL);
	
		ctp_i2c_udelay(100000);
		CTP_I2C_write_byte(HST_MODE_ADDR, HST_MODE_RESET); //system information mode
		ctp_i2c_udelay(200000);

		CTP_I2C_write_byte(HST_MODE_ADDR, HST_MODE_SYSTEM_INFORMATION); //system information mode
		ctp_i2c_udelay(200000);
	}
}

void ctp_cypress_cy8ctma340_exit_system_mode()
{
	if((gpio_ctp_reset_pin != 0xFF) && (gpio_ctp_eint_pin != 0xFF))
	{
		CTP_I2C_write_byte(HST_MODE_ADDR, HST_MODE_NORMAL); //normal operation mode
		ctp_i2c_udelay(200000);
		DclGPIO_Control(ctp_gpio_eint_handle, GPIO_CMD_WRITE_HIGH, NULL);
		DclGPIO_Control(ctp_gpio_eint_handle, GPIO_CMD_SET_MODE_1, NULL);
		DclGPIO_Control(ctp_gpio_eint_handle, GPIO_CMD_SET_DIR_IN, NULL);
		DclGPIO_Control(ctp_gpio_eint_handle, GPIO_CMD_ENABLE_PULL, NULL);
		DclGPIO_Control(ctp_gpio_eint_handle, GPIO_CMD_SET_PULL_HIGH, NULL);
		if(gpio_ctp_i2c_sda_pin != 0xFF) //SW I2C
			ctp_i2c_configure(CTP_SLAVE_ADDR, CTP_DELAY_TIME);
		else //HW I2C
			ctp_i2c_configure(CTP_SLAVE_ADDR, CTP_HW_I2C_SPEED);
	}
}

//If controller has the register store these informations
//Read out the informations from controller through I2C
void ctp_cypress_cy8ctma340_get_information()
{
	kal_uint8 value[4];
	kal_bool i2c_ret;

	i2c_ret = CTP_I2C_read(CID_0, value, 3);
	kal_prompt_trace(MOD_TP_TASK, "ctp_cypress_cy8ctma340_get_information i2c_ret=%d CID_0=%x CID_1=%x CID_2=%x", i2c_ret,  value[0], value[1], value[2]);
	i2c_ret = CTP_I2C_read(UID_0, value, 4);
	kal_prompt_trace(MOD_TP_TASK, "ctp_cypress_cy8ctma340_get_information i2c_ret=%d UID_0=%x UID_1=%x UID_2=%x UID_3=%x", i2c_ret,  value[0], value[1], value[2], value[3]);
	i2c_ret = CTP_I2C_read(UID_4, value, 4);
	kal_prompt_trace(MOD_TP_TASK, "ctp_cypress_cy8ctma340_get_information i2c_ret=%d UID_4=%x UID_5=%x UID_6=%x UID_7=%x", i2c_ret,  value[0], value[1], value[2], value[3]);
	i2c_ret = CTP_I2C_read(BL_VERH, value, 4);
	kal_prompt_trace(MOD_TP_TASK, "ctp_cypress_cy8ctma340_get_information i2c_ret=%d BL_VERH=%x BL_VERL=%x TTS_VERH=%x TTS_VERL=%x", i2c_ret,  value[0], value[1], value[2], value[3]);
	i2c_ret = CTP_I2C_read(APP_IDH, value, 4);
	kal_prompt_trace(MOD_TP_TASK, "ctp_cypress_cy8ctma340_get_information i2c_ret=%d APP_IDH=%x APP_IDL=%x APP_VERH=%x APP_VERL=%x", i2c_ret,  value[0], value[1], value[2], value[3]);
}

void ctp_cypress_cy8ctma340_set_active_timeout(kal_uint32 timeout, kal_uint32 refresh)
{
	CTP_I2C_write_byte(ACT_INTRVL_ADDR, refresh); //active report interval
	ctp_i2c_udelay(200); //delay ~200us for write data
	CTP_I2C_write_byte(TCH_TMOUT_ADDR, timeout); //set active timeout
}
kal_bool ctp_cypress_cy8ctma340_init(void)
{
	if(gpio_ctp_power_enable_pin != 0xFF)
		ctp_gpio_power_handle   = DclGPIO_Open(DCL_GPIO, gpio_ctp_power_enable_pin);

	if(gpio_ctp_eint_pin != 0xFF)
		ctp_gpio_eint_handle    = DclGPIO_Open(DCL_GPIO, gpio_ctp_eint_pin);

	if(gpio_ctp_reset_pin != 0xFF)
		ctp_gpio_reset_handle   = DclGPIO_Open(DCL_GPIO, gpio_ctp_reset_pin);

	if(gpio_ctp_i2c_sda_pin != 0xFF) //SW I2C
		ctp_i2c_configure(CTP_SLAVE_ADDR, CTP_DELAY_TIME);
	else //HW I2C
		ctp_i2c_configure(CTP_SLAVE_ADDR, CTP_HW_I2C_SPEED);
		
	ctp_cypress_cy8ctma340_power(KAL_TRUE);
	
	ctp_cypress_cy8ctma340_enter_system_mode();
	ctp_cypress_cy8ctma340_set_active_timeout(0xFF, 20); //20ms refresh period
	ctp_cypress_cy8ctma340_exit_system_mode();


	CTP_I2C_write_byte(HST_MODE_ADDR, HST_MODE_NORMAL); //normal operation mode
	
	EINT_Set_Sensitivity(custom_eint_get_channel(touch_panel_eint_chann), EDGE_SENSITIVE);
	
	return KAL_TRUE;
}

Touch_Panel_PenState_enum ctp_cypress_cy8ctma340_hisr(void)
{
	kal_uint8 lvalue;
	kal_bool i2c_ret;

	
	i2c_ret = CTP_I2C_read(TT_STAT_ADDR, &lvalue, 1);
	if(i2c_ret == KAL_FALSE)
		return UP;
		

	if(lvalue & TT_STAT_NUMBER_TOUCH)
		return DOWN;
	else
		return UP;
}

kal_bool ctp_reset(void)
{
	return KAL_TRUE;
}

kal_bool ctp_get_version(CTP_custom_information_struct  *version)
{
//Vendor ID 
//Product ID
//Firmware version
	return KAL_TRUE;
}

//kal_bool ctp_get_current_status(CTP_status_struct *status,ctp_status_enum ctp_status)
//{
//Interrupt(?)
//Detection points count / gesture
//}

//kal_bool ctp_cypress_cy8ctma340_device_mode(CTP_device_mode_struct *mode, device_mode_enum get_set_device_mode)
//{
//}

kal_bool ctp_cypress_cy8ctma340_parameters(CTP_parameters_struct *para, kal_uint32 get_para, kal_uint32 set_para)
{
	kal_bool result = KAL_TRUE;
	
	if(get_para & set_para) //get and set the same parameter in the same time.
		ASSERT(0);
	
	if(set_para & CTP_PARA_RESOLUTION)
	{
		result &= KAL_FALSE; //not implement
	}
	if(set_para & CTP_PARA_THRESHOLD)
	{
		result &= KAL_FALSE; //not implement
	}
	if(set_para & CTP_PARA_REPORT_INTVAL)
	{
//		CTP_I2C_write_byte(HST_MODE_ADDR, HST_MODE_SYSTEM_INFORMATION); //system information mode
//		CTP_I2C_write_byte(ACT_INTRVL_ADDR, para->Report_interval); //system information mode
//		CTP_I2C_write_byte(HST_MODE_ADDR, HST_MODE_NORMAL); //normal operation mode
		result &= KAL_TRUE;
	}
	if(set_para & CTP_PARA_IDLE_INTVAL)
	{
		result &= KAL_FALSE; //not implement
	}
	if(set_para & CTP_PARA_SLEEP_INTVAL)
	{
		result &= KAL_FALSE; //not implement
	}
	
	if(get_para & CTP_PARA_RESOLUTION)
	{
		result &= KAL_FALSE; //not implement
	}
	if(get_para & CTP_PARA_THRESHOLD)
	{
		result &= KAL_FALSE; //not implement
	}
	if(get_para & CTP_PARA_REPORT_INTVAL)//write only, not support read
	{
		result = KAL_TRUE;
	}
	if(get_para & CTP_PARA_IDLE_INTVAL)
	{
		result &= KAL_FALSE; //not implement
	}
	if(get_para & CTP_PARA_SLEEP_INTVAL)
	{
		result &= KAL_FALSE; //not implement
	}
			
	return result;
}

kal_bool ctp_read_one_point(kal_uint32 x_base, TP_SINGLE_EVENT_T *event)
{
	kal_uint8 value[5];
	kal_bool i2c_ret;

	i2c_ret = CTP_I2C_read(x_base, value, 5);
	if(i2c_ret == KAL_FALSE)
		return KAL_FALSE;
	event->x = (value[0] << 8) | value[1];
	event->y = (value[2] << 8) | value[3];
	event->z = value[4];
	return KAL_TRUE;
}

kal_bool ctp_read_all_point(TouchPanelMultipleEventStruct *tpes, kal_uint32 points)
{
	kal_uint32 i=0;
	kal_uint32 x_base[] = {TOUCH1_XH_ADDR, TOUCH2_XH_ADDR, TOUCH3_XH_ADDR, TOUCH4_XH_ADDR};
	TP_SINGLE_EVENT_T get_one_point;
	
	
	ASSERT(tpes);
	if((points<1) || (points>5))
		return KAL_FALSE;
		
	for(i=0;i<points;i++)
	{
		ctp_read_one_point(x_base[i], &get_one_point);
		tpes->points[i].x = get_one_point.x;
		tpes->points[i].y = get_one_point.y;
		tpes->points[i].z = get_one_point.z;
	}	
	return KAL_TRUE;
}

void ctp_cypress_cy8ctma340_toggle(void)
{
	static kal_bool data_read_toggle = KAL_TRUE;
    	if(data_read_toggle)
	{
		CTP_I2C_write_byte(HST_MODE_ADDR, HST_MODE_NORMAL | HST_MODE_DATA_READ_TOGGLE); //toggle the controller.
	}
	else
	{
		CTP_I2C_write_byte(HST_MODE_ADDR, HST_MODE_NORMAL); //toggle the controller.
	}
	data_read_toggle = data_read_toggle?KAL_FALSE:KAL_TRUE;
}

kal_bool ctp_cypress_cy8ctma340_get_data(TouchPanelMultipleEventStruct *tpes)
{
	kal_bool i2c_ret;
	kal_uint8 reg[2];
	kal_uint32 model = 0;

	ASSERT(tpes);
		
	tpes->time_stamp = (kal_uint16)L1I_GetTimeStamp();
	tpes->padding = CTP_PATTERN;
	
	i2c_ret = CTP_I2C_read(TT_MODE_ADDR, reg, 2);
	if(i2c_ret == KAL_FALSE)
	{
		ctp_cypress_cy8ctma340_toggle();
		return KAL_FALSE;
	}	
	if(reg[0] & TT_MODE_BUFFER_INVALID)
	{
		drv_trace0(TRACE_GROUP_10, CTP_CAPACITIVE_GET_DATA_INVALID);
		ctp_cypress_cy8ctma340_toggle();
		return KAL_FALSE;
	}

	model = (kal_uint32)(reg[1] & TT_STAT_NUMBER_TOUCH);
		
	drv_trace1(TRACE_GROUP_10, CTP_CAPACITIVE_MODEL, model);
	if(model > 4) //cypress only support 4 fingers
	{
		ctp_cypress_cy8ctma340_toggle();
		return KAL_FALSE;
	}

	tpes->model = (kal_uint16)model;  //read out all touch points coordinates.
	if(model == 0)
	{
		ctp_cypress_cy8ctma340_toggle();
		return KAL_FALSE;
	}

	ctp_read_all_point(tpes, model);
	ctp_cypress_cy8ctma340_toggle();
	return KAL_TRUE;
}

kal_bool ctp_cypress_cy8ctma340_set_device_mode(ctp_device_mode_enum mode)
{
	kal_uint32 ctp_update;
	
	if(mode == CTP_FIRMWARE_UPDATE)
	{
		ctp_cypress_cy8ctma340_enter_system_mode();
		ctp_cypress_cy8ctma340_get_information();
		ctp_cypress_cy8ctma340_exit_system_mode();
		
		ctp_cypress_cy8ctma340_power(KAL_TRUE);
		ctp_update = ctp_cypress_upgrader();
		if(ctp_update == 0)
		{
			ctp_cypress_cy8ctma340_power(KAL_FALSE);
			ctp_i2c_udelay(10000);
			ctp_cypress_cy8ctma340_power(KAL_TRUE);
			CTP_I2C_write_byte(HST_MODE_ADDR, HST_MODE_NORMAL); //normal operation mode
		}
	}
	else if(mode == CTP_ACTIVE_MODE)
	{
		CTP_I2C_write_byte(HST_MODE_ADDR, HST_MODE_NORMAL); //toggle the controller.
	}
	else if(mode == CTP_IDLE_MODE)
	{
		CTP_I2C_write_byte(HST_MODE_ADDR, HST_MODE_LOW_POWER); //toggle the controller.
	}
	else if(mode == CTP_SLEEP_MODE)
	{
		CTP_I2C_write_byte(HST_MODE_ADDR, HST_MODE_DEEP_SLEEP); //toggle the controller.
	}
	return KAL_FALSE;
}

CTP_custom_information_struct *ctp_Get_Data(void) 
{
	return (&ctp_custom_information_def);
}

CTP_customize_function_struct ctp_custom_func=
{
	ctp_cypress_cy8ctma340_init,
	ctp_cypress_cy8ctma340_set_device_mode,
	ctp_cypress_cy8ctma340_hisr,
	ctp_cypress_cy8ctma340_get_data,
	ctp_cypress_cy8ctma340_parameters,
	ctp_cypress_cy8ctma340_power
};

CTP_customize_function_struct *ctp_GetFunc(void)
{
	return (&ctp_custom_func);  
}

