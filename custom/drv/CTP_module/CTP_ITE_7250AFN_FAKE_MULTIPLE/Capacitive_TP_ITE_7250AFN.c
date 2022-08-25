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
 *   Capacitive_TP_ITE_7250AFN.c
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "kal_release.h"
#include "dcl.h"
#include "touch_panel.h"
#include "eint.h"
#include "Capacitive_TP_ITE_7250AFN.h"
#include "Capacitive_TP_I2C.h"

extern const char gpio_ctp_i2c_sda_pin;
extern const char gpio_ctp_i2c_scl_pin;
extern const char gpio_ctp_eint_pin;
extern const char gpio_ctp_reset_pin;

static kal_bool ctp_ITE_7250AFN_get_data(TouchPanelMultipleEventStruct *tpes);

CTP_parameters_struct CTP_parameters;

kal_uint32 CTP_MULTIPLE_PICKS = 8; //ITE need read out all data in buffer
kal_uint32 CTP_DELAY_TIME = 3;

CTP_custom_information_struct  ctp_custom_information_def = 
{
	"ITE     ",
	"7250AFN ",
	"UNKNOWN ",	
};

void ctp_ITE_7250AFN_power(kal_bool ON)
{
	kal_uint8 set_sleep[]={COMMAND_BUFFER_INDEX, COMMAND_SET_POWER_MODE, 0x0, COMMAND_POWER_SLEEP_MODE};
	kal_uint8 query;
	static kal_bool power_on = KAL_TRUE;
	
	if(power_on == ON)
		return;

	if(ON == KAL_TRUE)
	{
		CTP_I2C_READ(QUERY_BUFFER_INDEX, &query, 1);
		power_on = KAL_TRUE;
	}
	else
	{
		CTP_I2C_MULTI_WRITE(set_sleep, 4);
		power_on = KAL_FALSE;
	}
}

void CTP_I2C_configure(kal_uint32 slave_addr, kal_uint32 speed)
{
	ctp_i2c_configure(slave_addr, speed);
}

kal_bool ctp_ITE_7250AFN_set_FW_data()
{
	return KAL_FALSE;
//	kal_uint8 write_FW[]={COMMAND_BUFFER_INDEX, COMMAND_WRITE_FLASH, 0x4, 0, 0, 0, 0};
//	kal_uint32 data_count,i=0;
//
//	do{
//		data_count = uart_get_data(&FW_data[0]); //firmware.bin
//		if(data_count == 0)
//		{
//			PutUARTByte(uart_port2, FW_UPDATE_ERROR);
//		}
//		if(i++>10) return KAL_FALSE;
//	}while(data_count == 0);
//	
//	for(i=0;i<data_count;i=i+4)
//	{
//		write_FW[3] = FW_data[i];
//		write_FW[4] = FW_data[i+1];
//		write_FW[5] = FW_data[i+2];
//		write_FW[6] = FW_data[i+4];
//		CTP_I2C_MULTI_WRITE(&write_FW[0], 7);
//	}
//	PutUARTByte(uart_port2, FW_UPDATE_FINISH);
//	return KAL_TRUE;
}

kal_bool ctp_ITE_7250AFN_update_FW()
{
	return KAL_FALSE;

//	kal_uint8 enter_FW[]={COMMAND_BUFFER_INDEX, COMMAND_FW_UPGRADE_MODE, COMMAND_ENTER_FW_UPGRADE, 'I', 'T', '7', '2', '6', '0', 0x55, 0xAA};
//	kal_bool bret;
//
//  UARTDCBStruct  UART_Config =
//  {
//   UART_BAUD_921600,    /* baud; */
//   len_8,               /* dataBits; */
//   sb_1,                /*stopBits; */
//   pa_none,             /* parity; */
//   fc_none,             /*flow control*/
//   0x11,                /* xonChar; */
//   0x13,                /* xoffChar; */
//   KAL_FALSE
//  };
//
//	UART_Open(uart_port2,MOD_UART2_HISR);
//	UART_SetDCBConfig(uart_port2, &UART_Config, MOD_UART2_HISR);
//
//	CTP_I2C_MULTI_WRITE(&enter_FW[0], 7);
//	PutUARTByte(uart_port2, FW_UPDATE_START);
//
//	bret = ctp_ITE_7250AFN_set_FW_data(); //firmware.bin
//	if(bret == KAL_FALSE)
//		return KAL_FALSE;
//	bret = ctp_ITE_7250AFN_set_FW_data(); //config.bin
//	return bret;
}

kal_uint32 uart_get_data(kal_uint8 *datePoint)
{
	return 0;
//    kal_uint8 data;
//    UINT16 CRC=0,CRC2=0;
//    UINT32 i;
//    UINT32 file_length;
//
//    // Get file size
//    file_length = 0;
//    for(i=0;i<4;i++) {
//        file_length |= (UINT32)(GetUARTByte(uart_port2)<<(24-i*8));
//    }
//    // Get bitstream
//    for(i=0;i<file_length;i++) {
//        data = GetUARTByte(uart_port2);
////       	PutUARTByte(uart_port2, data);
//        datePoint[i] = data;
//        CRC ^= data;
//    }
//    // Get CRC
//    for(i=0;i<2;i++) {
//        data = GetUARTByte(uart_port2);
//        CRC2 |= (UINT16)(data<<(8-i*8));
//    }
//
//    if (CRC2 != CRC)
//    {
//       kal_prompt_trace(MOD_TP_TASK,"\r CRC2 $d != CRC $d!!\n", CRC2, CRC);
//       return 0;
//    }
//
//    return file_length;
}

//If controller has the register store these informations
//Read out the informations from controller through I2C
void ctp_ITE_7250AFN_get_information()
{
	kal_uint8 value[32], respond[8];
	kal_uint8 read_fw_cmd[]={COMMAND_BUFFER_INDEX, COMMAND_READ_REGISTER, 0x08, COMMAND_DATA_TYPE_BYTE,0x08,0x00,0x00,0xd0};
	
	CTP_I2C_MULTI_WRITE(read_fw_cmd, 8);

	CTP_I2C_READ(COMMAND_RESPONSE_BUFFER_INDEX, &respond[0], 8);
	
	CTP_I2C_READ(POINT_BUFFER_INDEX, &value[0], 8);
	CTP_I2C_READ(POINT_BUFFER_INDEX+8, &value[8], 8);
}

kal_bool ctp_ITE_7250AFN_init(void)
{
	DCL_HANDLE eint_handle, reset_handle;

	CTP_I2C_configure(CTP_SLAVE_ADDR, CTP_DELAY_TIME);
	ctp_ITE_7250AFN_power(KAL_TRUE);

	
	eint_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_eint_pin);
	reset_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_reset_pin);
	DclGPIO_Control(reset_handle, GPIO_CMD_SET_MODE_0, NULL);
	DclGPIO_Control(reset_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	DclGPIO_Control(reset_handle, GPIO_CMD_WRITE_LOW, NULL);

	DclGPIO_Control(eint_handle, GPIO_CMD_SET_MODE_0, NULL);
	DclGPIO_Control(eint_handle, GPIO_CMD_ENABLE_PULL, NULL);
	DclGPIO_Control(eint_handle, GPIO_CMD_SET_PULL_HIGH, NULL);
	DclGPIO_Control(eint_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	DclGPIO_Control(eint_handle, GPIO_CMD_WRITE_LOW, NULL);	
	kal_sleep_task(5);
	DclGPIO_Control(eint_handle, GPIO_CMD_SET_MODE_1, NULL);
	DclGPIO_Control(eint_handle, GPIO_CMD_SET_DIR_IN, NULL);
	DclGPIO_Control(reset_handle, GPIO_CMD_WRITE_HIGH, NULL);

	EINT_Set_Sensitivity(custom_eint_get_channel(touch_panel_eint_chann), LEVEL_SENSITIVE);

	//CTP_I2C_WRITE(COMMAND_SET_POINT_THRESHOLD, threshold);
       
	return KAL_TRUE;
}

Touch_Panel_PenState_enum ctp_ITE_7250AFN_hisr(void)
{
	kal_uint8 query, count=0;
	kal_uint8 point[14];

	do{
	CTP_I2C_READ(QUERY_BUFFER_INDEX, &query, 1);
		count++;
		if(count >= 0xF)
		{
		return UP;
		}
	}while(query & 0x1); //busy
	
	CTP_I2C_READ(POINT_BUFFER_INDEX, point, 14);
	if((query & 0x88) && (point[0] & POINT_BUFFER_POINT_INFO_MASK))
	{
		return DOWN;
	}
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

kal_bool ctp_ITE_7250AFN_device_mode(ctp_device_mode_enum set_device_mode)
{
	return KAL_TRUE;
}

kal_bool ctp_ITE_7250AFN_parameters(CTP_parameters_struct *para, kal_uint32 get_para, kal_uint32 set_para)
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
		result &= KAL_FALSE; //not implement
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

kal_bool ctp_ITE_7250AFN_check_busy(kal_uint8 *query_info)
{
	kal_uint32 count = 0;
	do{
		CTP_I2C_READ(QUERY_BUFFER_INDEX, query_info, 1);
		count++;
		if(count >= 0xF)
		{
			return KAL_TRUE;
		}
	}while(*query_info & 0x1); //busy	
	return KAL_FALSE;
}

kal_bool ctp_ITE_7250AFN_get_data(TouchPanelMultipleEventStruct *tpes)
{
	kal_uint8 query_info[1];
	kal_uint8 point_info[14];
	kal_uint32 model = 0;
	kal_uint32 count = 0, p1_count = 0, p2_count = 0;
	kal_uint8 tp_eint;
	kal_uint32 uscnti1, uscnti2;
	kal_bool busy;

	
	tp_eint = custom_eint_get_channel(touch_panel_eint_chann);

	EINT_Mask(tp_eint);
	ASSERT(tpes);
		
	tpes->padding = CTP_PATTERN;
	tpes->model = 0;
	
	tpes->points[0].x = tpes->points[0].y = tpes->points[0].z = 0;
	tpes->points[1].x = tpes->points[1].y = tpes->points[1].z = 0;
	
	busy = ctp_ITE_7250AFN_check_busy(query_info);
	if(busy)
	{
		EINT_UnMask(tp_eint);
		return KAL_FALSE;
	}
		
	do{
		CTP_I2C_READ(POINT_BUFFER_INDEX, point_info, 14);
  	
		if(point_info[0] & POINT_BUFFER_FORMAT_MASK)
		{
			busy = ctp_ITE_7250AFN_check_busy(query_info);
			if(busy)
			{
				EINT_UnMask(tp_eint);
				return KAL_FALSE;
			}
			continue;
		}
  	
		if(point_info[0] & POINT_BUFFER_POINT_INFO_0)
		{
			tpes->points[0].x += point_info[2] + ((point_info[3]&0x0F) << 8);
			tpes->points[0].y += point_info[4] + ((point_info[3]&0xF0) << 4);
			tpes->points[0].z += point_info[5] & 0xF;
			model |= 0x1;
			p1_count++;
		}
		if(point_info[0] & POINT_BUFFER_POINT_INFO_1)
		{
			tpes->points[1].x += point_info[6] + ((point_info[7]&0x0F) << 8);
			tpes->points[1].y += point_info[8] + ((point_info[7]&0xF0) << 4);
			tpes->points[1].z += point_info[9] & 0xF;
			model |= 0x2;
			p2_count++;
		}
		if( (p1_count > CTP_MULTIPLE_PICKS) || (p2_count > CTP_MULTIPLE_PICKS))
			break;
//		currently ITE not support 3 points
		busy = ctp_ITE_7250AFN_check_busy(query_info);
		if(busy)
		{
			EINT_UnMask(tp_eint);
			return KAL_FALSE;
		}
	}while(query_info[0] & QUERY_BUFFER_NEW_POINT_INFO);

	if(p1_count != 0)
	{
		tpes->points[0].x /= p1_count;
		tpes->points[0].y /= p1_count;
		tpes->points[0].z /= p1_count;
	}
	if(p2_count != 0)
	{
		tpes->points[1].x /= p2_count;
		tpes->points[1].y /= p2_count;
		tpes->points[1].z /= p2_count;
	}
	if(model == 2) //only point 2 have valid value
	{
		tpes->points[0].x = tpes->points[1].x;
		tpes->points[0].y = tpes->points[1].y;
		tpes->points[0].z = tpes->points[1].z;
		tpes->model = 1;
	}
	else
	{
		tpes->model = (kal_uint16)((model>2)?2:model);
	}
	EINT_UnMask(tp_eint);
	
	if(model)
		return KAL_TRUE;
	else
		return KAL_FALSE;
}

CTP_custom_information_struct *ctp_Get_Data(void) 
{
	return (&ctp_custom_information_def);
}

CTP_customize_function_struct ctp_custom_func=
{
	//ctp_Get_Data,
	ctp_ITE_7250AFN_init,
	ctp_ITE_7250AFN_device_mode,
	ctp_ITE_7250AFN_hisr,
	ctp_ITE_7250AFN_get_data,
	ctp_ITE_7250AFN_parameters,
	ctp_ITE_7250AFN_power
};

CTP_customize_function_struct *ctp_GetFunc(void)
{
	return (&ctp_custom_func);  
}

