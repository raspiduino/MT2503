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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#if defined(__TOUCH_PANEL_CAPACITY__)
#include "kal_release.h"
//#include "pwic.h"
#include "sccb_v2.h"
#include "touch_panel.h"
#include "eint.h"
#include "capacitive_tp_focaltech_ft6206.h"
#include "drv_comm.h"
//#include "Capacitive_TP_I2C.h"
#include "I2c.h"
#include "Dcl.h"
#include "touch_panel_custom.h"
#if 1//lijunbo
#include "MMI_features.h"
#include "TimerEvents.h"
#endif

//extern const char gpio_ctp_i2c_sda_pin;
//extern const char gpio_ctp_i2c_scl_pin;
//extern const char gpio_ctp_eint_pin;
//extern const char gpio_ctp_reset_pin;

	
#if !defined(IC_MODULE_TEST)
extern kal_uint32 /*lint -e(526)*/L1I_GetTimeStamp(void);
#endif

extern kal_bool ctp_goodix_gt818_set_device_mode(ctp_device_mode_enum mode);

//kal_uint8 CTP_I2C_READ(kal_uint8 reg, kal_uint8 *value, kal_uint16 len);
kal_uint32 CTP_DELAY_TIME	= 200; //may different by each controller in SW I2C

CTP_parameters_struct CTP_parameters;
//CTP_I2C_PARAMETERS ctp_i2c_para = {CTP_I2C_LDO, CTP_I2C_LDO_VOLTAGE, CTP_SLAVE_ADDR};

CTP_custom_information_struct  ctp_custom_information_def = 
{
	"FOCAL",
	"FT5206",
	"UNKNOWN",	
};

//If controller has the register store these informations
//Read out the informations from controller through I2C
void ctp_cypress_cy8ctma340_get_information()
{
		
}


#if defined(CTP_USE_SW_I2C)

void CTP_I2C_Init(void)
{
	GPIO_ModeSetup(CTP_I2C_CLK_PIN, 0);
	GPIO_ModeSetup(CTP_I2C_DATA_PIN, 0);
	GPIO_ModeSetup(CTP_RESET_PIN, 0);
	CTP_SET_I2C_CLK_OUTPUT;
	CTP_SET_RESET_PIN_OUTPUT;
}
void CTP_I2C_POWER_ON(void)
{
}
void CTP_delay_us(kal_uint32 time)
{
	kal_uint32 i,j,k;
	for(i=0;i< time;i++)
		for(j=0;j<100;j++)
          {
            k=0;
        };
}
static void CTP_delay_ms(kal_uint16 time)
{//zhouwei add
    volatile kal_uint32 delay;
    while(time--)	
    for (delay =0;delay <5000;delay++) {} // 1ms
}
kal_uint8 CTP_I2C_send_byte(kal_uint8 send_byte)

{
	volatile signed char i;
	volatile kal_uint32 j;
	volatile kal_uint32 k=0;
	kal_uint8 ack;
	
	for (i=7;i>=0;i--)
	{	/* data bit 7~0 */
		if (send_byte & (1<<i))
		{
			CTP_SET_I2C_DATA_HIGH;

		}
		else
		{
			CTP_SET_I2C_DATA_LOW;

		}
		for(j=0;j<CTP_I2C_DELAY_FT;j++);
		CTP_SET_I2C_CLK_HIGH;
		for(j=0;j<CTP_I2C_DELAY_FT;j++);
		CTP_SET_I2C_CLK_LOW;
		for(j=0;j<CTP_I2C_DELAY_FT;j++);
	}
	
	CTP_SET_I2C_DATA_INPUT;
	CTP_SET_I2C_CLK_HIGH;
	for(j=0;j<CTP_I2C_DELAY_FT;j++);
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
    #else//zhouwei modified 2012 03 16
	for(k=0;k<CTP_ACK_COUNTER;k++)
	{
		if(CTP_GET_I2C_DATA_BIT==0)
		{
			ack=1;
			break;
		}
		else
		{
			ack=0;
		}
	}
    #endif
	CTP_SET_I2C_CLK_LOW;
	for(j=0;j<CTP_I2C_DELAY_FT;j++);
	CTP_SET_I2C_DATA_OUTPUT;
	
	//CTP_delay_us(100);//need delay can't delete
	CTP_delay_us(20);
	//dump_printf("\n\r zs2010 CTP_I2C_send_byte ack = %d\r\n",ack);
	return ack;
}	

kal_uint8 CTP_I2C_get_byte(void)
{
	volatile signed char i;
	volatile kal_uint32 j;
	kal_uint8 get_byte=0;

	CTP_SET_I2C_DATA_INPUT;
	  for (i=7;i>=0;i--)
        {       /* data bit 7~0 */
                CTP_SET_I2C_CLK_LOW;
                for(j=0;j<CTP_I2C_DELAY_FT;j++);
                CTP_SET_I2C_CLK_HIGH;
                for(j=0;j<CTP_I2C_DELAY_FT;j++);
                if (CTP_GET_I2C_DATA_BIT)
                        get_byte |= (1<<i);
        }
	/* don't care bit, 9th bit */
	
	for(j=0;j<CTP_I2C_DELAY_FT;j++);
	CTP_SET_I2C_CLK_LOW;
	for(j=0;j<CTP_I2C_DELAY_FT;j++);
	CTP_SET_I2C_DATA_OUTPUT;
	CTP_delay_us(5);
	return get_byte;
}	

kal_int8 CTP_I2C_WRITE(kal_uint8 reg, kal_uint8 value)
{
	volatile kal_uint32 j;
	
	CTP_I2C_START_BIT;       
	for(j=0;j<CTP_I2C_DELAY_FT;j++);
	if(!CTP_I2C_send_byte(CTP_WRITE))
	return(-1);
	for(j=0;j<CTP_I2C_DELAY_FT;j++);
	if(!CTP_I2C_send_byte(reg))
	return(-1);
	for(j=0;j<CTP_I2C_DELAY_FT;j++);
	if(!CTP_I2C_send_byte(value))
	return(-1);
    	for(j=0;j<CTP_I2C_DELAY_FT;j++);
       CTP_I2C_STOP_BIT;      
       return 1;

}

void CTP_BL_I2C_WRITE(data, len)
{
	kal_uint16 i;
	//i2c_write(SCCB_OWNER_TP, data, len);
}


kal_uint8 CTP_I2C_get_byte_with_ack(unsigned char uc_ack_lvl)
{
	volatile signed char i;
	volatile kal_uint32 j;
	kal_uint8 get_byte=0;

	CTP_SET_I2C_DATA_INPUT;
	for(j=0;j<CTP_I2C_DELAY_FT;j++);
	  for (i=7;i>=0;i--)
        {       /* data bit 7~0 */
                CTP_SET_I2C_CLK_LOW;
                for(j=0;j<CTP_I2C_DELAY_FT;j++);
                CTP_SET_I2C_CLK_HIGH;
                for(j=0;j<CTP_I2C_DELAY_FT;j++);
                if (CTP_GET_I2C_DATA_BIT)
                        get_byte |= (1<<i);
				for(j=0;j<CTP_I2C_DELAY_FT;j++);
        }
	/* don't care bit, 9th bit */

	for(j=0;j<CTP_I2C_DELAY_FT;j++);
	CTP_SET_I2C_CLK_LOW;
	for(j=0;j<CTP_I2C_DELAY_FT;j++);
	CTP_SET_I2C_DATA_OUTPUT;
	
	if (uc_ack_lvl == 1)
	{
	    CTP_SET_I2C_DATA_HIGH;
	}
	else
	{
	    CTP_SET_I2C_DATA_LOW;
	}
	
	for(j=0;j<CTP_I2C_DELAY_FT;j++);
	CTP_SET_I2C_CLK_HIGH;

	for(j=0;j<CTP_I2C_DELAY_FT;j++);
	CTP_SET_I2C_CLK_LOW;

	for(j=0;j<CTP_I2C_DELAY_FT;j++);
	CTP_SET_I2C_DATA_LOW;
	
	//CTP_delay_us(5);
	return get_byte;
}	


kal_int8 CTP_I2C_READ(kal_uint8 reg, kal_uint8 *value, kal_uint16 len) 
{

	volatile kal_uint32 j;
    kal_uint8 get_byte = 0;
	kal_uint16 i;
	
    CTP_I2C_START_BIT;       
	for(j=0;j<CTP_I2C_DELAY_FT;j++);
	if(!CTP_I2C_send_byte(CTP_WRITE))
	return(-1);
	for(j=0;j<CTP_I2C_DELAY_FT;j++);
	if(!CTP_I2C_send_byte(reg))
	return(-1);
	for(j=0;j<CTP_I2C_DELAY_FT;j++);

       CTP_I2C_STOP_BIT;
	for(j=0;j<CTP_I2C_DELAY_FT;j++);
	CTP_I2C_START_BIT;       
	if(!CTP_I2C_send_byte(CTP_READ))
	return(-1);

	if (len <= 1)
    {
        //*value =CTP_I2C_get_byte();
        *value =CTP_I2C_get_byte_with_ack(1);
		for(j=0;j<CTP_I2C_DELAY_FT;j++);
    }
	else
	{
	    for (i = 0; i< len - 1; i++)
	    {
	        *value++ =CTP_I2C_get_byte_with_ack(0);
	    }
		*value =CTP_I2C_get_byte_with_ack(1);
	}
       CTP_I2C_STOP_BIT;
 	 
       return 1;
}

#else  /*  USE HW I2C */
/*HW I2C power on (using camera_digital)*/
void CTP_I2C_POWER_ON(void)
{
	/*
	pmu_set_vcam_d_sel(VCAM_D_SEL_2_8);		//<==neen set VDD = 2.8V
	pmu_set_vcam_d_en(KAL_TRUE);
	kal_sleep_task(1);
	*/
	ctp_i2c_power_on(1,CTP_I2C_LDO, CTP_I2C_LDO_VOLTAGE);
}

/*HW I2C initialization*/
void CTP_I2C_Init(void)
{
	/*
	sccb_config_struct para;
	
	para.sccb_mode = SCCB_HW_8BIT;
	para.get_handle_wait = KAL_TRUE;
	para.slave_address = (kal_uint8)(CTP_SLAVE_ADDR<<1);
	para.delay_len = 0x100;
	para.transaction_mode = SCCB_TRANSACTION_FAST_MODE;
	para.Fast_Mode_Speed = 100;
	*/
	

	ctp_i2c_configure(CTP_SLAVE_ADDR, 300);

	ENABLE_I2C_CLOCK_EXTENSION;		//<==Must enable i2c_clk_extension for being ensure controller timing matching with HW I2C timing

}

/*HW I2C ctp set address function*/
kal_bool CTP_SET_ADDRESS(kal_uint8 addr)
{
	/*
	kal_uint8 reg_address[1];

	reg_address[0] = addr;
	*/
	
	if(ctp_i2c_send_byte(addr))
	{
		kal_prompt_trace(MOD_TP_TASK, "CTP set address failed!");
		return KAL_FALSE;
	}
	else
	{
		return KAL_TRUE;
	}
}

/*HW I2C ctp write function*/
kal_bool CTP_I2C_WRITE(kal_uint8 *data, kal_uint8 len)
{
	kal_uint8 reg_addr;

	reg_addr = data[0];
	
	if(ctp_i2c_send(CTP_SLAVE_ADDR, reg_addr, data, len)==KAL_FALSE)
	{
		kal_prompt_trace(MOD_TP_TASK, "write reg_con_addr error!");
		return KAL_FALSE;
	}
	else
		return KAL_TRUE;
}

/*HW I2C ctp read function*/
kal_bool CTP_I2C_READ(kal_uint8 reg_addr, kal_uint8 *value, kal_uint16 len) 
{
	if(ctp_i2c_receive(CTP_SLAVE_ADDR, reg_addr, value, len)==KAL_FALSE)
	{
		kal_prompt_trace(MOD_TP_TASK, "read:%d error!");		
		return KAL_FALSE;
	}
	return KAL_TRUE;
}


#endif
#ifdef WIN32
kal_uint32 EINT_Set_Sensitivity(kal_uint8 eintno, kal_bool sens)
{}

#endif

kal_uint8 tp_chip_choose_t=0;
extern CTP_customize_function_struct /*lint -e(526)*/*ctp_GetFunc_gt818(void);//lijunbo
extern CTP_customize_function_struct /*lint -e(526)*/*mstar_ctp_GetFunc(void);
#ifndef WIN32
//extern CTP_customize_function_struct *ctp_fun_ptr;
#endif
kal_bool ctp_focaltech_ft5206_init(void)
{
	kal_uint8 lvalue;
	kal_uint8 write_data[2];
	DCL_HANDLE eint_handle, reset_handle;

	CTP_SET_RESET_PIN_HIGH;//new added zhouwei
	
	CTP_I2C_POWER_ON();
	CTP_I2C_Init();

	//CTP_I2C_READ(HST_MODE_ADDR, lvalue, 8);
	kal_sleep_task(1);
	//ctp_cypress_cy8ctma340_get_information();
	write_data[0]=HST_MODE_ADDR;
	write_data[1]=0X0B;
	//CTP_I2C_WRITE(0x0B, 2); //soft reset //mtk
	CTP_I2C_WRITE(0x00, 0X00); //soft reset
	//CTP_I2C_READ(HST_MODE_ADDR, &lvalue, 1);
    

	EINT_Set_HW_Debounce(custom_eint_get_channel(touch_panel_eint_chann), 2);
	EINT_SW_Debounce_Modify(custom_eint_get_channel(touch_panel_eint_chann),0);
	EINT_Set_Sensitivity(custom_eint_get_channel(touch_panel_eint_chann), EDGE_SENSITIVE);

	//¼æÈÝCTP zhouwei
	CTP_I2C_WRITE(0x80, 0x1e); 
	CTP_I2C_READ(0x80, &lvalue, 1);
	kal_prompt_trace(MOD_TP_TASK, "ctp_cypress_cy8ctma340_init address[0x80]=%x ", lvalue);

	CTP_I2C_READ(0xa3, &lvalue, 1);
	if(lvalue==0x55)
	{
		tp_chip_choose_t=1;//FT5206
		kal_prompt_trace(MOD_TP_TASK, "now is FT5206 ctp ");
	}
	else
	{
		kal_prompt_trace(MOD_TP_TASK, "gt818 or mstar ctp ");
		tp_chip_choose_t=2;
		#ifdef __TYD_USE_MSTAR_CTP__
//		ctp_fun_ptr = mstar_ctp_GetFunc();
		#else
#ifndef WIN32
//		ctp_fun_ptr = ctp_GetFunc_gt818();
#endif
		#endif
#ifndef WIN32
//		ctp_fun_ptr->ctp_init();
#endif
	}
	//END

	return KAL_TRUE;
}

void ctp_focaltech_ft5206_device_enter_sleep(void)
{
		CTP_I2C_WRITE(0xA5, 3); 
}

void ctp_focaltech_ft5206_device_exit_sleep(void)
{
	CTP_delay_us(50);
	CTP_SET_RESET_PIN_LOW;
	CTP_delay_us(50);
	ctp_focaltech_ft5206_init();
}

kal_uint8 TYD_GET_CTP_IC_ID(void)
{//zhouwei add 2012 03 28
	#ifdef __TYD_USE_MSTAR_CTP__ 
	return 0;
	#endif
	return tp_chip_choose_t;
}
void ctp_enter_sleep(void)
{//zhouwei add for ctp enter sleep mode
	if(tp_chip_choose_t==2)
	{
		#ifdef __TYD_USE_MSTAR_CTP__ 
		;
		#else//GOODIX
		ctp_goodix_gt818_set_device_mode(CTP_SLEEP_MODE);;
		#endif
		kal_prompt_trace(MOD_ENG, "Other ctp_enter_sleep ");
	}
	else//FT5206
	{
		CTP_delay_ms(10);
		CTP_I2C_WRITE(0xA5, 3);
		CTP_delay_ms(10);
		kal_prompt_trace(MOD_ENG, "FT5206 ctp_enter_sleep ");
	}
	kal_prompt_trace(MOD_ENG, "ctp_enter_sleep ");
}
void ctp_exit_sleep(void)
{//zhouwei add for ctp exit sleep mode
	if(tp_chip_choose_t==2)
	{
		#ifdef __TYD_USE_MSTAR_CTP__ 
		;
		#else//GOODIX
		ctp_goodix_gt818_set_device_mode(CTP_ACTIVE_MODE);
		#endif
	}
	else//FT5206
	{
		GPIO_ModeSetup(CTP_I2C_CLK_PIN, 0);
		GPIO_ModeSetup(CTP_I2C_DATA_PIN, 0);
		GPIO_ModeSetup(CTP_RESET_PIN, 0);
		CTP_SET_I2C_CLK_OUTPUT;
		CTP_SET_RESET_PIN_OUTPUT;
		
		CTP_SET_RESET_PIN_LOW;
		CTP_delay_ms(15);
		CTP_SET_RESET_PIN_HIGH;
		CTP_delay_ms(10);
	}
	
	kal_prompt_trace(MOD_ENG, "ctp_exit_sleep ");
}

void ctp_focaltech_ft5206_device_hold_reset(void)
{
	EINT_Mask(6);
	CTP_I2C_WRITE(0xA5, 3); 
	kal_sleep_task(5); 
	CTP_SET_RESET_PIN_LOW;
	kal_sleep_task(1);
	CTP_SET_RESET_PIN_HIGH;
	EINT_UnMask(6);
}


kal_bool ctp_focaltech_ft5206_device_mode(ctp_device_mode_enum mode)
{
	kal_uint8 write_data[2];

	if(mode == CTP_ACTIVE_MODE)
	{
	     write_data[0]=HST_MODE_ADDR;
		 write_data[1]=HST_MODE_NORMAL;
		CTP_I2C_WRITE(0x1B, 2); //toggle the controller.
	}
	else if(mode == CTP_IDLE_MODE)
	{
		//CTP_I2C_WRITE(HST_MODE_ADDR, HST_MODE_LOW_POWER); //toggle the controller.
	}
	else if(mode == CTP_SLEEP_MODE)
	{
		//CTP_I2C_WRITE(HST_MODE_ADDR, HST_MODE_DEEP_SLEEP); //toggle the controller.
	}
	return KAL_FALSE;
}



Touch_Panel_PenState_enum ctp_focaltech_ft5206_hisr(void)
{
	kal_uint8 lvalue;
	
	CTP_I2C_READ(TD_STAT_ADDR, &lvalue, 1);
    kal_prompt_trace(MOD_TP_TASK, "ctp_cypress_cy8ctma340_hisr TT_STAT_ADDR=%x ", lvalue);
	if((lvalue>0)&&(lvalue < TD_STAT_NUMBER_TOUCH))
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

kal_bool ctp_ft5206_get_chip_id(void)
{
	kal_uint8 lvalue;

	kal_bool ret;
       kal_uint8 i,j;
   
       i=0;
       lvalue=0;
	
	ctp_focaltech_ft5206_init();

	// ret=KAL_FALSE;
   do{
   	 	ret=CTP_I2C_READ(0xa3, &lvalue, 1);
		i++;
   	}
   while((i>4)||(lvalue==0x55));  
	
	kal_prompt_trace(MOD_TP_TASK, "ctp_ft5206_get_chip_id lijunbo address[0xa3]=%x ", lvalue);

	if(lvalue==0x55)
	{
		return KAL_TRUE;
	}
	else
	{
		return KAL_FALSE;
	}
	
}

kal_bool ctp_focaltech_ft5206_parameters(CTP_parameters_struct *para, kal_uint32 get_para, kal_uint32 set_para)
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
		//CTP_I2C_WRITE(HST_MODE_ADDR, HST_MODE_SYSTEM_INFORMATION); //system information mode
		//CTP_I2C_WRITE(ACT_INTRVL_ADDR, para->Report_interval); //system information mode
		//CTP_I2C_WRITE(HST_MODE_ADDR, HST_MODE_NORMAL); //normal operation mode
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

    kal_uint8 values[4];
    kal_uint16 temp_y;
	CTP_I2C_READ(x_base, values, 4);
	event->x =   (((kal_uint16)(values[0]&0x0f))<<8) | values[1];
	event->y =   (((kal_uint16)(values[2]&0x0f))<<8) | values[3];

	kal_prompt_trace(MOD_TP_TASK, "ctp_read_one_point v0=0x%x v1=0x%x, v2=0x%x, v3=0x%x", 
		values[0], values[1], values[2], values[3]);
	kal_prompt_trace(MOD_TP_TASK, "ctp_read_one_point x=%d y=%d",  event->x, event->y);

	return KAL_TRUE;
}

kal_bool ctp_read_all_point(TouchPanelMultipleEventStruct *tpes, kal_uint32 points)
{
	kal_uint32 i=0;
	kal_uint32 x_base[] = {TOUCH1_XH_ADDR, TOUCH2_XH_ADDR, TOUCH3_XH_ADDR, TOUCH4_XH_ADDR};
	TP_SINGLE_EVENT_T get_one_point;
	kal_uint16 temp_x=0, temp_y=0;
	
	kal_prompt_trace(MOD_TP_TASK, "ctp_read_all_point points=%d", points);
	
	ASSERT(tpes);
	if((points<1) || (points>5))
		return KAL_FALSE;
		
	for(i=0;i<points;i++)
	{
		ctp_read_one_point(x_base[i], &get_one_point);
		// wxh 
		tpes->points[i].x = 239 - get_one_point.x;
		tpes->points[i].y = 239 - get_one_point.y;
		
		//tpes->points[i].x = get_one_point.x;
		//tpes->points[i].y = get_one_point.y;
	}	
	return KAL_TRUE;
}

kal_bool ctp_focaltech_ft5206_get_data(TouchPanelMultipleEventStruct *tpes)
{
	kal_uint8 lvalue;
	kal_uint32 counter = 0, model = 0;
	
	ASSERT(tpes);
		
	//CTP_I2C_POWER_ON();

	tpes->time_stamp = (kal_uint16)L1I_GetTimeStamp();
	tpes->padding = CTP_PATTERN;
	
	//CTP_I2C_WRITE(HST_MODE_ADDR, HST_MODE_NORMAL); //operation mode

	do{ //make sure data in buffer is valid
		CTP_I2C_READ(TD_STAT_ADDR, &lvalue, 1);
		if(counter++ == 0x30)//zhouwei if(counter++ == 0xFF/*FFFFFF*/)
			return KAL_FALSE;
	}while(lvalue & TT_MODE_BUFFER_INVALID); 

	CTP_I2C_READ(TD_STAT_ADDR, &lvalue, 1); //read out the count of touch points.
	model = (kal_uint32)(lvalue & TD_STAT_NUMBER_TOUCH);
	kal_prompt_trace(MOD_TP_TASK, "ctp_get_data model=%d", model);
		
	tpes->model = (kal_uint16)model;  //read out all touch points coordinates.

	if((model == 0) || (model > 5))
		return KAL_FALSE;

	ctp_read_all_point(tpes, model);
	return KAL_TRUE;
}

static kal_uint32 ctp_focaltech_ft5206_command(kal_uint32 cmd, void* p1, void* p2)
{
    return KAL_TRUE;
}
static void ctp_focaltech_ft5206_power(kal_bool ON)
{
    return ;
}

CTP_custom_information_struct *ctp_Get_Data(void) 
{
	return (&ctp_custom_information_def);
}

CTP_customize_function_struct ctp_custom_func_ft5206=
{
	ctp_focaltech_ft5206_init,
	ctp_focaltech_ft5206_device_mode,
	ctp_focaltech_ft5206_hisr,
	ctp_focaltech_ft5206_get_data,
	ctp_focaltech_ft5206_parameters,
	ctp_focaltech_ft5206_power,
    ctp_focaltech_ft5206_command
};

CTP_customize_function_struct *ctp_GetFunc(void)
{
	return (&ctp_custom_func_ft5206);  
}

#endif //#if defined(__TOUCH_PANEL_CAPACITY__)
