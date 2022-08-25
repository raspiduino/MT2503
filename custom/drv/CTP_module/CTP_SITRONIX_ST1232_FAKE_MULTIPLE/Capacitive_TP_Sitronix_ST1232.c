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
 *   Capacitive_TP_Sitronix_ST1232.c
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#if defined(__TOUCH_PANEL_CAPACITY__)
#include "kal_release.h"
#include "pwic.h"
#include "sccb_v2.h"
#include "touch_panel.h"
#include "eint.h"
#include "Capacitive_TP_I2C.h"
#include "Capacitive_TP_Sitronix_ST1232.h"
#include "I2c.h"
#include "Dcl.h"
	
#if !defined(IC_MODULE_TEST)
extern kal_uint32 /*lint -e(526)*/L1I_GetTimeStamp(void);
#endif

kal_uint32 CTP_DELAY_TIME	= 200; //may different by each controller in SW I2C

CTP_parameters_struct CTP_parameters;


//#define CTP_DBG_LOG


/******************************************************************************* **********/
/*      CTP global variables														                       */
/*																						  */
/*****************************************************************************************/
CTP_parameters_struct CTP_parameters;

CTP_custom_information_struct  ctp_custom_information_def = 
{
	"Sitronix",
	"st1232",
	"UNKNOWN",	
};


/*delay for CTP uint:ms*/
void CTP_msDelay(kal_uint32 data)
{
	kal_uint32 i,j;

	while(data--)
	{
		for(i=0; i<1000; i++)
			for(j=0; j<100; j++)
				;
	}
}

/**************************************************************************************************/
/*      I2C API for capacitive touch panel															          */
/*																							          */
/**************************************************************************************************/
/*****SOFTWARE I2C PART**************************/
#ifdef SW_I2C

/*i2c delay for CTP uint:us*/
void CTP_I2C_DELAY_US(kal_uint32 ctp_delay_time)
{
	kal_uint32 i, j;

	for(i=0; i<ctp_delay_time; i++)
		for(j=0; j<100; j++)
			;
}

/*software i2c ack_bit*/
void CTP_I2C_SEND_ACK(void) 
{
	CTP_SET_I2C_DATA_LOW;
	CTP_SET_I2C_DATA_OUTPUT;

	CTP_SET_I2C_CLK_OUTPUT;
	CTP_I2C_DELAY;
	
	CTP_SET_I2C_CLK_HIGH;
	while (!CTP_GET_I2C_CLK_BIT);		//For clock stretching.
	CTP_I2C_DELAY;
	
	CTP_SET_I2C_CLK_LOW;
	CTP_I2C_DELAY;
}

/*software i2c non_ack_bit*/
void CTP_I2C_SEND_NACK(void) 
{
	CTP_SET_I2C_DATA_HIGH;
	CTP_SET_I2C_DATA_OUTPUT;
	
	CTP_SET_I2C_CLK_OUTPUT;
	CTP_I2C_DELAY;
	
	CTP_SET_I2C_CLK_HIGH;
	while(!CTP_GET_I2C_CLK_BIT);		//for clock stretching
	CTP_I2C_DELAY;
	
	CTP_SET_I2C_CLK_LOW;
	CTP_I2C_DELAY;
	
	CTP_SET_I2C_DATA_LOW;
	CTP_I2C_DELAY;
}

/*software i2c initialization*/
void CTP_I2C_Init(void)
{
	GPIO_ModeSetup(CTP_I2C_CLK_PIN, 0);
	GPIO_ModeSetup(CTP_I2C_DATA_PIN, 0);
	GPIO_ModeSetup(CTP_RESET_PIN, 0);
	CTP_SET_I2C_CLK_OUTPUT;
	CTP_SET_RESET_PIN_OUTPUT;
}

/*software i2c wait for ack_bit*/
kal_bool CTP_WaitAck(void)
{
	kal_uint8 ack;

	CTP_SET_I2C_DATA_INPUT;
	CTP_I2C_DELAY;

	CTP_SET_I2C_CLK_HIGH;
	while (!CTP_GET_I2C_CLK_BIT);		//For clock stretching.
	CTP_I2C_DELAY;

	ack = CTP_GET_I2C_DATA_BIT;
	CTP_I2C_DELAY;
	
	CTP_SET_I2C_CLK_LOW;
	CTP_I2C_DELAY;

	CTP_SET_I2C_DATA_OUTPUT;

	if(0 == ack)
		return KAL_TRUE;

	return KAL_FALSE;
}

/*SW I2C ctp transfy byte function*/
kal_bool CTP_TxByte(kal_uint8 data)
{

	volatile kal_int8 i;
	volatile kal_uint16 ack_cnt = 0;
	
	CTP_SET_I2C_DATA_OUTPUT;			// set data pin output
	
	for(i=7; i>=0; i--)		//data bit 7~0
	{
		if(data&(1<<i))
		{
			CTP_SET_I2C_DATA_HIGH;
		}
		else
		{
			CTP_SET_I2C_DATA_LOW;
		}
		CTP_I2C_DELAY;
		
		CTP_SET_I2C_CLK_HIGH;
		while (!CTP_GET_I2C_CLK_BIT);		//For clock stretching.
		CTP_I2C_DELAY;
		CTP_SET_I2C_CLK_LOW;
		CTP_I2C_DELAY;
	}

	return CTP_WaitAck();

}

/*SW I2C ctp recieve byte function*/
void CTP_Rx_Byte(kal_uint8 *data, kal_bool ack)
{

	kal_int8 i;
	kal_uint8 get_byte = 0;

	for(i=7; i>=0; i--)
	{
		CTP_SET_I2C_DATA_INPUT;				// set data pin input
		CTP_I2C_DELAY;
		
		CTP_SET_I2C_CLK_HIGH;
		while (!CTP_GET_I2C_CLK_BIT);		//For clock stretching.
		CTP_I2C_DELAY;

		if(CTP_GET_I2C_DATA_BIT)
			get_byte |= (1<<i);
		
		CTP_SET_I2C_CLK_LOW;
		CTP_I2C_DELAY;
	}

	*data = get_byte;
	
	if(ack == KAL_TRUE)
	{
		CTP_I2C_SEND_ACK();
	}
	else
	{
		CTP_I2C_SEND_NACK();
	}
	
}

/*SW I2C  ctp write function*/
kal_bool CTP_I2C_WRITE(kal_uint8 *data, kal_uint8 len)
{
	volatile kal_uint8 i;

	CTP_I2C_START_BIT;
	CTP_I2C_DELAY;

	if(!CTP_TxByte(CTP_WRITE_ID))				// send ctp_write_id
		return KAL_FALSE;

	for(i=0; i<len; i++)
	{
		if(!CTP_TxByte(data[i]))						// send value
			return KAL_FALSE;
	}

	CTP_I2C_STOP_BIT;
	
	return KAL_TRUE;

}


/*SW I2C  ctp read function*/
kal_bool CTP_I2C_READ(kal_uint8 reg_addr, kal_uint8 *value, kal_uint16 len) 	//reg_addr is not used,just for matching hw_i2c api style!!
{

	kal_uint8 get_byte = 0;
	volatile kal_uint8 i;
	
	CTP_I2C_START_BIT;       
	CTP_I2C_DELAY;

	if(!CTP_TxByte(CTP_READ_ID))					
		return KAL_FALSE;
	
	for(i=0; i<len; i++)
	{	
		if(i<(len-1))
			CTP_Rx_Byte(&value[i], KAL_TRUE);
		else
			CTP_Rx_Byte(&value[i], KAL_FALSE);
	}
	
    CTP_I2C_STOP_BIT;
	
    return KAL_TRUE;

}

/*SW I2C ctp set address function*/
void CTP_SET_ADDRESS(kal_uint8 addr)
{
	kal_uint8 data[1];

	data[0] = addr;

	if(!CTP_I2C_WRITE(data, 1))
		kal_prompt_trace(MOD_TP_TASK, "CTP SET ADDRESS:%d FAILED!", addr);
}


#else	//#ifndef SW_I2C (using HW_I2C)
/*****HARDWARE I2C**************************/

/*HW I2C power on (using camera_digital)*/
void CTP_I2C_POWER_ON(void)
{
	/*
	pmu_set_vcam_d_sel(VCAM_D_SEL_2_8);		//<==neen set VDD = 2.8V
	pmu_set_vcam_d_en(KAL_TRUE);
	kal_sleep_task(1);
	*/
	ctp_i2c_power_on(KAL_TRUE, CTP_I2C_LDO, CTP_I2C_LDO_VOLTAGE);
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
	
	ctp_i2c_configure(CTP_SLAVE_ADDR ,200);

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

	data++;
	
	if(ctp_i2c_send(CTP_SLAVE_ADDR, reg_addr, data, len-1)==KAL_FALSE)
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
		kal_prompt_trace(MOD_TP_TASK, "read:%d error!", reg_addr);		
		return KAL_FALSE;
	}
	return KAL_TRUE;
}

#endif	//SW_I2C

/**************************************************************************************************/
/*      Update firmware API part																		   */
/*																								   */
/*       	Functions below are used to update firmware for Cap touch panel								          */
/**************************************************************************************************/
#ifdef FW_UPDATE
/*
kal_bool st1232_jump_to_isp(void)
{
	kal_uint8 i;
	kal_uint8 signature[8] = {0x53,0x54,0x58,0x5F,0x46,0x57,0x55,0x50};
	kal_uint8 temp_buff[2];

	temp_buff[0] = 0x00;

	for(i=0; i<8; i++)
	{
		temp_buff[1] = signature[i];

		if(CTP_I2C_WRITE(temp_buff, 2)==KAL_FALSE)
		{
			kal_prompt_trace(MOD_TP_TASK, "Failed!!!!!!! Jump to isp failed! write %d failed!", signature[i]);
			return KAL_FALSE;
		}
	}

	kal_prompt_trace(MOD_TP_TASK, "Jump to isp OK!");
	CTP_msDelay(120);								//not less than 100ms

	return KAL_TRUE;
}

kal_bool st1232_isp_reset(void)
{
	kal_uint8 data[8] = {0};

	data[0] = STX_ISP_RESET;

	if(CTP_I2C_WRITE(data ,8)==KAL_TRUE)
	{
		kal_prompt_trace(MOD_TP_TASK, "reset isp OK!");
		CTP_msDelay(240);							//not less than 200ms
		return KAL_TRUE;
	}
	else
	{
		kal_prompt_trace(MOD_TP_TASK, "Failed!!!!!Reset isp failed!");
		return KAL_FALSE;
	}
}

kal_bool st1232_isp_erase(kal_uint8 page_num)	//page_num: 0~31
{
	kal_uint8 data[8] = {0};
	kal_uint8 feedback_value[8] = {0};

	if(page_num<0||page_num>31)
		ASSERT(0);

	data[0] = STX_ISP_ERASE;
	data[1] = 0x00;				//this byte is reserved!
	data[2] = page_num;

	if(CTP_I2C_WRITE(data, 8)==KAL_FALSE)
	{
		kal_prompt_trace(MOD_TP_TASK, "Failed!!!!!!!erase page%d failed!", page_num);
		return KAL_FALSE;
	}

	// why not need delay for waiting erase complete??
	if((CTP_I2C_READ(feedback_value, 8)==KAL_FALSE)||(feedback_value[0]!=STX_ISP_READY))
	{
		kal_prompt_trace(MOD_TP_TASK, "Failed!!!! When erase page%d, get ready failed!", page_num);
		return KAL_FALSE;
	}
	
	kal_prompt_trace(MOD_TP_TASK, "erase page%d OK!", page_num);
	return KAL_TRUE;
}

kal_uint16 st1232_isp_cksum(kal_uint8* page_buf)
{
	kal_uint16 cksum = 0;
	kal_uint16 i;

	if(page_buf == NULL)
		ASSERT(0);

	for(i=0; i<ST1232_ISP_PAGE_SIZE; i++)
	{
		cksum += (kal_uint16) page_buf[i];
	}

	return cksum;	
}

kal_bool st1232_isp_read_page(kal_uint8* page_buf, kal_uint8 page_num)	  //page_num: 0~31
{
	kal_uint8 data[8] = {0};
	kal_uint16 r_len = 0;
	kal_uint8* temp_page_buf;
	
	temp_page_buf = page_buf;

	if(page_buf==NULL||temp_page_buf==NULL)
		ASSERT(0);

	if(page_num<0||page_num>31)
		ASSERT(0);


	data[0] = STX_ISP_READ_FLASH;
	data[2] = page_num;

	if(CTP_I2C_WRITE(data, 8)==KAL_FALSE)
	{
		kal_prompt_trace(MOD_TP_TASK, "Failed!!!! send read %d page command failed!", page_num);
		return KAL_FALSE;
	}

	while(r_len<ST1232_ISP_PAGE_SIZE)
	{
		if(CTP_I2C_READ((temp_page_buf+r_len), 8)==KAL_FALSE)
		{
			kal_prompt_trace(MOD_TP_TASK, "Failed!!!!Read %d page %d ~ %d byte failed!", page_num, r_len, r_len+7);
			return KAL_FALSE;
		}
		r_len += 8;
	}

	return KAL_TRUE;
}

kal_bool st1232_isp_write_page(kal_uint8* page_buf, kal_uint8 page_num)			//page_num: 0~31
{
	kal_uint8 data[8] = {0};
	kal_uint16 w_len = 0;
	kal_uint16 cksum = 0;
	kal_uint8 len = 0;
	kal_uint8* temp_page_buf;
	kal_uint8 feedback_value[8] = {0};

	temp_page_buf = page_buf;

	if(page_buf==NULL||temp_page_buf==NULL)
		ASSERT(0);

	if(page_num<0||page_num>31)
		ASSERT(0);

	if(st1232_isp_erase(page_num)==KAL_FALSE)
		return KAL_FALSE;

	cksum = st1232_isp_cksum(page_buf);

	data[0] = STX_ISP_WRITE_FLASH;
	data[2] = page_num;
	data[4] = (cksum&0xFF);
	data[5] = ((cksum&0xFF)>>8);

	if(CTP_I2C_WRITE(data, 8)==KAL_FALSE)
	{
		kal_prompt_trace(MOD_TP_TASK, "Failed!!!!!send write %d page command failed!", page_num);
		return KAL_FALSE;
	}

	data[0] = STX_ISP_SEND_DATA;
	
	for(w_len=ST1232_ISP_PAGE_SIZE; w_len>0; w_len-=7)
	{
		len = (w_len<7) ? w_len : 7;

		if(CTP_I2C_WRITE(temp_page_buf, len)==KAL_FALSE)
		{
			kal_prompt_trace(MOD_TP_TASK, "Failed!!! write %d page %d ~ %d byte failed!", page_num, ST1232_ISP_PAGE_SIZE-w_len, ST1232_ISP_PAGE_SIZE-w_len+6);
			return KAL_FALSE;
		}
		temp_page_buf += 7;	
	}

	if((CTP_I2C_READ(feedback_value, 8)==KAL_FALSE)||(feedback_value[0]!=STX_ISP_READY))
	{
		kal_prompt_trace(MOD_TP_TASK, "Failed!!!!When write %d page, get ready failed!", page_num);
		return KAL_FALSE;
	}
	
	return KAL_TRUE;
}

*/

#endif		//ifdef FW_UPDATE

/**************************************************************************************************/
/*      Cap touch panel  API part																		   */
/*																							          */
/**************************************************************************************************/

/**************************************************************************************************/
/*		Ctp config API part																		          */
/*																								   */
/*			Functions below are used to set config for Cap touch panel 								   	   */
/**************************************************************************************************/

/*ctp SetResolution function*/
kal_bool ctp_SetResolution(kal_uint16 x_res, kal_uint16 y_res)
{
	kal_uint8 ResValue[4];
	kal_uint8 set_cnt = 0;
	
	ResValue[0] = 0x04;
	ResValue[1] = (x_res&0xf00)>>4|(y_res&0xf00)>>8;
	ResValue[2] = x_res&0xff;
	ResValue[3] = y_res&0xff;

	kal_prompt_trace(MOD_TP_TASK, " res1:%d, res2:%d, res3:%d", ResValue[1], ResValue[2], ResValue[3]);
	
	while(set_cnt<10)
	{
		if(CTP_I2C_WRITE(ResValue, 4) == KAL_TRUE)
			return KAL_TRUE;
		set_cnt++;
	}
	
	kal_prompt_trace(MOD_TP_TASK, "set resolution failed! x_res:%d, y_res:%d", x_res, y_res);
	return KAL_FALSE;
}

/*ctp SetIdleMode function*/
kal_bool ctp_SetIdleMode(kal_bool flag)
{
	kal_uint8 idlevalue[2];
	kal_uint8 set_cnt = 0;

	idlevalue[0] = REG_CON_ADDR;

	if(KAL_TRUE == flag)
		idlevalue[1] = IDLE_ENABLE;
	else
		idlevalue[1] = IDLE_DISABLE;
	
	
	while(set_cnt<10)
	{
		if(CTP_I2C_WRITE(idlevalue, 2) == KAL_TRUE)
			return KAL_TRUE;

		set_cnt++;
	}
	kal_prompt_trace(MOD_TP_TASK, "set idlemode = %d failed!", flag);
	return KAL_FALSE;
}

/*ctp SetIdleTimeOut function*/
kal_bool ctp_SetIdleTimeOut(kal_int8 idle_time)
{	
	kal_uint8 IdleTime[2];
	kal_uint8 set_cnt = 0;

	IdleTime[0] = REG_IDLE_ADDR;
	IdleTime[1] = idle_time;
	
	while(set_cnt<10)
	{
		if(CTP_I2C_WRITE(IdleTime, 2) == KAL_TRUE)
			return KAL_TRUE;
		set_cnt++;
	}
	kal_prompt_trace(MOD_TP_TASK, "set idletime = %d failed!", idle_time);
	return KAL_FALSE;
}


kal_bool ctp_sitronix_st1232_power_on(kal_bool power_flag)
{
	if(KAL_TRUE == power_flag)
	{
		//not implement
	}
	else
	{
		//not implement
	}

	return KAL_TRUE;
}

/*capacity tp initialization*/
kal_bool ctp_sitronix_st1232_init(void)
{	
	kal_uint8 i, j;
	kal_uint8 InitValue[2];
	kal_uint8* temp;

#if CTP_DBG_LOG
	kal_prompt_trace(MOD_TP_TASK, "enter ctp_sitronix_st1232_init,first!!");
#endif
	
	CTP_I2C_POWER_ON();
	CTP_I2C_Init();

	ctp_SetResolution(DEFAULT_RES_X, DEFAULT_RES_Y);

	/*Init cap touch panel*/
	ctp_SetIdleMode(KAL_TRUE);					//enable idle mode
	CTP_msDelay(10);
	ctp_SetIdleTimeOut(DEFAULT_IDLE_TIMEOUT);	//set idle timeout
	CTP_msDelay(10);

	/*set eint*/
	EINT_Set_Sensitivity(custom_eint_get_channel(touch_panel_eint_chann), LEVEL_SENSITIVE);
	
	return KAL_TRUE;
}

/*ctp hisr*/
Touch_Panel_PenState_enum ctp_sitronix_st1232_hisr(void)
{						//check only one point whether down or up!!   later to modify!!

	kal_uint8 lvalue[8];
	kal_uint8 res[3];
	kal_uint8 fingers;

#ifdef SW_I2C 
	CTP_SET_ADDRESS(0x10);										//haoran modify for test hw_i2c
#endif


	CTP_I2C_READ(0x10,lvalue, 8);								//haoran modify for test hw_i2c
	
#if CTP_DBG_LOG
	kal_prompt_trace(MOD_TP_TASK, "in hisr 0x10 VALUE:%d, %d, %d, %d, %d, %d, %d, %d", lvalue[0], lvalue[1], lvalue[2], lvalue[3], lvalue[4], lvalue[5], lvalue[6], lvalue[7]);
#endif

	fingers = lvalue[0]&0x07;

	if(fingers!=0)
	{
		kal_prompt_trace(MOD_TP_TASK, "TOUCH! FINGERS:%d", fingers);
		return DOWN;
	}
	else
	{
		kal_prompt_trace(MOD_TP_TASK, "NO TOUCH!  FINGERS:%d", fingers);
		return UP;
	}
}

/*ctp reset*/					//not implement
kal_bool ctp_reset(void)
{	
	ctp_SetResolution(2048,2048);
	return KAL_TRUE;
}
/*ctp_get_version*/			//not implement
kal_bool ctp_get_version(CTP_custom_information_struct  *version)
{
	return KAL_TRUE;
}

/*************************************************************************************
* FUNCTION
*	ctp_sitronix_st1232_parameters
*
* DESCRIPTION
*	This function is to get or set parameters for capacitve touch panel
*
* CALLS
*
* PARAMETERS
*	
*
* RETURNS
*	KAL_TRUE	
*	KAL_FALSE	
*
*************************************************************************************/

kal_bool ctp_sitronix_st1232_parameters(CTP_parameters_struct *para, kal_uint32 get_para, kal_uint32 set_para)
{
	kal_bool result = KAL_TRUE;
	kal_uint8 lvalue;

	return KAL_TRUE;
		
	if(get_para & set_para)		//not allow get and set the same parameter in the same time
		ASSERT(0);
	
	if(set_para & RESOLUTION_PARA)
	{
		result &= KAL_FALSE;	//not implement!	in touch_panel.h the struct CTP_parameters_struct is not OK, the size resolution is too small
	}
	if(set_para & THRESHOLD_PARA)
	{
		lvalue = (kal_uint8)(para->threshold&0xff);
		
		result &= KAL_TRUE;
	}
	if(set_para & IDLE_INTERVAL_PARA)
	{
		lvalue = (kal_uint8)(para->Idle_time_interval&0xff);
		
		result &= KAL_TRUE;
	}
	if(set_para & SLEEP_INTERVAL_PARA)
	{
		result &= KAL_FALSE;	//not implement
	}

	if(get_para & RESOLUTION_PARA)
	{
		result &= KAL_FALSE;
	}
	if(get_para &= THRESHOLD_PARA)
	{
		
		para->threshold = 0;
		para->threshold |= lvalue;
		result &= KAL_TRUE;
	}
	if(get_para & IDLE_INTERVAL_PARA)
	{
		
		para->Idle_time_interval = 0;
		para->Idle_time_interval |= lvalue;
		result &= KAL_TRUE;
	}
	if(get_para & SLEEP_INTERVAL_PARA)
	{
		result &= KAL_FALSE;	//not implement
	}

	return result;
}

/*************************************************************************************
* FUNCTION
*	ctp_sitronix_st1232_get_data
*
* DESCRIPTION
*   	Capacitve touch panel start timer to poll for get the coordinate of the point 
*	This function is to get x, y, z coordinate from ctp controller
*
* CALLS
*
* PARAMETERS
*	The pointer of TouchPanelMultipleEventStruct
*		model  			single/dual/triple/four/five/all gesture
*		padding			0xAA (for check the structure)
*		time_stamp
*		pionts[5]			most support 5 pioints
*
* RETURNS
*	KAL_TRUE	valid data, and store in point[]
*	KAL_FALSE	invalid data
*
*************************************************************************************/

kal_bool ctp_sitronix_st1232_get_data(TouchPanelMultipleEventStruct *tpes)
{
	kal_uint8 value[8];
	kal_uint8 i;
	kal_uint16 model =0;

	ASSERT(tpes);		//tpes == NULL  assert!

	kal_prompt_trace(MOD_TP_TASK, "start_get_data");			//haoran add for dbg
	
	tpes->time_stamp = (kal_uint16)L1I_GetTimeStamp();
	tpes->padding = CTP_PATTERN;

	/*read 8 byte data*/
#ifdef SW_I2C
	CTP_SET_ADDRESS(0x10);
#endif
	

	CTP_I2C_READ(0x10, value, 8);

	/*check single touch or double touch*/
	model = value[0];
	
	tpes->model = model;

#if CTP_DBG_LOG
	kal_prompt_trace(MOD_TP_TASK, "get_data 0x10 VALUE:%d, %d, %d, %d, %d, %d, %d, %d", value[0], value[1], value[2], value[3], value[4], value[5], value[6], value[7]);
	kal_prompt_trace(MOD_TP_TASK, "model:%d", model);
#endif

	/*not store data for 0 point or more than 2 points*/
	if(model == 0 || model > 2)				
		return KAL_FALSE;

	if(model==1)
	{
		if(value[2]&0x80)
		{
			tpes->points[0].x = (value[2]&0x70)<<4|value[3];
			tpes->points[0].y = (value[2]&0x07)<<8|value[4];
			tpes->points[0].z = 0;									//z coord  is reserved!~!
		}
		if(value[5]&0x80)
		{
			tpes->points[0].x = (value[5]&0x70)<<4|value[6];
			tpes->points[0].y = (value[5]&0x07)<<8|value[7];
			tpes->points[0].z = 0;									//z coord  is reserved!~!
		}
		
	}
	else		
	{
		for(i=0; i<model; i++)
		{
			tpes->points[i].x = (value[2+3*i]&0x70)<<4|value[3+3*i];
			tpes->points[i].y = (value[2+3*i]&0x07)<<8|value[4+3*i];
			tpes->points[i].z = 0;									//z coord  is reserved!~!

			//kal_prompt_trace(MOD_TP_TASK, "model:%d, points[%d].x:%d, points[%d].y:%d", model, i, tpes->points[i].x, i, tpes->points[i].y);
		}
	}
	
	
	return KAL_TRUE;
}

kal_bool ctp_sitronix_st1232_set_device_mode(ctp_device_mode_enum dwMode)
{
	kal_uint8 RegCtrlValue[2], DevCtrlValue;


	CTP_SET_ADDRESS(REG_CON_ADDR);
	//CTP_I2C_READ(&DevCtrlValue, 1);					//haoran modify for test hw_i2c
	
	switch(dwMode)
	{
		case CTP_ACTIVE_MODE:
			DevCtrlValue &= ~0x02;
			break;
		case CTP_SLEEP_MODE:
			DevCtrlValue |= 0x02;
			break;
		case CTP_IDLE_MODE:
			DevCtrlValue |= 0x04;
			break;
		case CTP_GESTURE_DETECTION_MODE:
			DevCtrlValue |= 0x08;
			break;
		default:
			break;
	}
	
	RegCtrlValue[0] = REG_CON_ADDR;
	RegCtrlValue[1] = DevCtrlValue;
	
	CTP_I2C_WRITE(RegCtrlValue, 2);

	return KAL_TRUE;
}

CTP_custom_information_struct *ctp_Get_Data(void)
{
	return (&ctp_custom_information_def);
}

CTP_customize_function_struct ctp_custom_func=
{
	ctp_sitronix_st1232_init,
    ctp_sitronix_st1232_set_device_mode,
	ctp_sitronix_st1232_hisr,
	ctp_sitronix_st1232_get_data,
	ctp_sitronix_st1232_parameters,
	ctp_sitronix_st1232_power_on,
};

CTP_customize_function_struct *ctp_GetFunc(void)
{
	return (&ctp_custom_func);  
}

#endif		//#if defined(TOUCH_PANEL_CAPACITY)
