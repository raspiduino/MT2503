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
 *   Capacitive_TP_Novatek_NT11001.c
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
#include "Capacitive_TP_Novatek_NT11001.h"
#include "Capacitive_TP_I2C.h"

#include "touch_panel_custom.h"

#if !defined(IC_MODULE_TEST)
extern kal_uint32 /*lint -e(526)*/L1I_GetTimeStamp(void);
#endif
kal_uint32 CTP_DELAY_TIME	= 200; //may different by each controller in SW I2C

CTP_parameters_struct CTP_parameters;

//kal_uint32 CTP_SLAVE_ADDR	=	0x02; //Novatek addr 0x01 << 1
//CTP_I2C_PARAMETERS ctp_i2c_para = {CTP_I2C_LDO, CTP_I2C_LDO_VOLTAGE, CTP_SLAVE_ADDR};

kal_uint32 ctp_delay_count = 3;
CTP_custom_information_struct  ctp_custom_information_def = 
{
	"NOVATEK",
	"NT1101",
	"UNKNOWN",	
};

void CTP_I2C_write_byte(kal_uint8 ucBufferIndex, kal_uint8 pucData)
{
	ctp_i2c_send(CTP_SLAVE_ADDR,ucBufferIndex,&pucData,1);
}

#define CTP_I2C_READ(a,b,c) ctp_i2c_receive(CTP_SLAVE_ADDR,a,b,c)

//If controller has the register store these informations
//Read out the informations from controller through I2C
void ctp_novatek_nt11001_get_information()
{
	;
}

kal_bool ctp_set_idle_mode(kal_bool enable)
{
	kal_uint8 value;
	kal_uint8 i,data = 0;

	if(enable)
		value = 0xDA;
	else
		value = 0x7A;
	//while(1)
	CTP_I2C_write_byte(NOVATEK_OPRE_2, value);
	for( i = 0;i<100;i++); // delay for read
	//while(1)
	CTP_I2C_READ(NOVATEK_OPRE_2,&data,1);	//test write ok?
	kal_prompt_trace(MOD_TP_TASK, "ctp set idle mode :NOVATEK_OPRE_2 =%d", data);
	return KAL_TRUE;	
}
//set interrupt mode bit[3]: 0: Edge trigger  1: Level trigger
kal_bool ctp_set_interupt_mode(kal_bool flag)
{
	kal_uint8 value;
	kal_uint8 i,data = 0;

	if(flag)
		value = 0x10;  //EDGE
	else
		value = 0x18;  //LEVEL
	//while(1)
	CTP_I2C_write_byte(NOVATEK_OPRE_1, value);
	for( i = 0;i<100;i++); // delay for read
	//while(1)
	CTP_I2C_READ(NOVATEK_OPRE_1,&data,1);	//test write ok?
	kal_prompt_trace(MOD_TP_TASK, "ctp set interrupt mode :NOVATEK_OPRE_1 =%d", data);
	return KAL_TRUE;	
}

kal_bool ctp_novatek_nt11001_parameters(CTP_parameters_struct *para, kal_uint32 get_para, kal_uint32 set_para)
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
		if (para->threshold > 0x07)
			return KAL_FALSE;
		else
			{
				CTP_I2C_write_byte(NOVATEK_OPRE_3, ( para->threshold )<< 3); // set Threshold
				result &= KAL_TRUE;
			}
	}
	if(set_para & CTP_PARA_REPORT_INTVAL)
	{
		result &= KAL_FALSE; //not implement
	}
	if(set_para & CTP_PARA_IDLE_INTVAL)
	{
		if (para->Idle_time_interval> 0x07)
			return KAL_FALSE;
		else
			{
				para->Idle_time_interval = (para->Idle_time_interval << 4) | (0x18 & (~IDLE_TIME_MASK));
				CTP_I2C_write_byte(NOVATEK_OPRE_1, para->Idle_time_interval); //set idle time : Sensor full funing time after finger leave
				result &= KAL_TRUE; //not implement
			}
		
	}
	if(set_para & CTP_PARA_SLEEP_INTVAL)
	{
		if (para->sleep_time_interval> 0x07)
			return KAL_FALSE;
		else
			{
				CTP_I2C_write_byte(NOVATEK_OPRE_1, para->sleep_time_interval); //set Doze mode to Deel Sleeo  time 
				result &= KAL_TRUE; //not implement
			}
	}
			
	return result;
}

kal_bool ctp_novatek_nt11001_set_device_mode(ctp_device_mode_enum mode)
{
 return KAL_TRUE;
}

kal_bool ctp_novatek_nt11001_init(void)
{
	kal_uint8 temp;
	kal_uint8 version;
	ctp_i2c_power_on(1,CTP_I2C_LDO, CTP_I2C_LDO_VOLTAGE);

	ctp_i2c_configure(CTP_SLAVE_ADDR, 200);
		
	//CTP_I2C_READ(HST_MODE_ADDR, lvalue, 8);
	CTP_I2C_READ(NOVATEK_SW_VERSION, &version, 1);
	
	
	kal_prompt_trace(MOD_TP_TASK," NOVATEK firmware version is %x", version);
	

	ctp_novatek_nt11001_get_information();

	//1,enable idle mode	
		temp = ctp_set_idle_mode(KAL_TRUE);		

	//2,set idle timer
	//CTP_para.Idle_time_interval = 1; //3s
	//temp = ctp_novatek_nt11001_parameters(&CTP_para, 0, CTP_PARA_IDLE_INTVAL);
	
	//3,set threshold
	//CTP_para.threshold= 1; //3s
	//temp = ctp_novatek_nt11001_parameters(&CTP_para, 0, CTP_PARA_THRESHOLD);

	//4, set interrupt mode
	temp = ctp_set_interupt_mode(KAL_FALSE);
	
	EINT_Set_Sensitivity(custom_eint_get_channel(touch_panel_eint_chann), LEVEL_SENSITIVE);
	
	return KAL_TRUE;
}


kal_bool ctp_set_sleep()
{
	kal_uint8 value;

	value = 0x5A;
	
	CTP_I2C_write_byte(NOVATEK_OPRE_2, value);

	return KAL_TRUE;	
}

kal_bool ctp_wakeup()
{
	kal_uint8 value;

	value = 0x7A;
	
	CTP_I2C_write_byte(NOVATEK_OPRE_2, value);

	return KAL_TRUE;	
}

Touch_Panel_PenState_enum ctp_novatek_nt11001_hisr(void)
{
	kal_uint8 lvalue[6] = {0};
	
	CTP_I2C_READ(0x00, lvalue, 6);
	
	kal_prompt_trace(MOD_TP_TASK, "ctp_read_one_point event=%d, xh=%d, xl=%d,yh=%d, yl=%d", lvalue[0], lvalue[1], lvalue[2], lvalue[3],lvalue[4]);
	//when 0x00~0x04 register are all 0x00, up state ;else down state, maybe move,Rotate,Zoom in/out etc depend register 0x00.
	if( ((lvalue[0] & 0xFF) == 0 ) && ((lvalue[1] & 0xFF) == 0 )&&((lvalue[2] & 0xFF) == 0 )&&((lvalue[3] & 0xFF) == 0 )&&((lvalue[4] & 0xFF) == 0 ))
		return UP;
	else
		return DOWN;
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


kal_bool ctp_read_data(TP_SINGLE_EVENT_T *event)
{
	kal_uint8 lvalue[6] = {0};

	//CTP_I2C_POWER_ON();

	CTP_I2C_READ(0x00, lvalue, 6);
	
	switch(lvalue[0])
		{
			case 0x10: //Move
				//event->event = PEN_DOWN;
				event->x = (lvalue[1]<<8)|lvalue[2];
				event->y = (lvalue[3]<<8)|lvalue[4];
				kal_prompt_trace(MOD_TP_TASK, "ctp_read_one_point event=%d, x = %d, y = %d", lvalue[0], event->x, event->y);
				break;
				
			case 0x40: //Rotate
				if(lvalue[1] == 0x01) //CW
				{
					kal_prompt_trace(MOD_TP_TASK, "ctp_read_one_point event0=%d,event1=%d", lvalue[0], lvalue[1]);
				}
				else if(lvalue[1] == 0x81) //CCW
					{
						kal_prompt_trace(MOD_TP_TASK, "ctp_read_one_point event0=%d,event1=%d", lvalue[0], lvalue[1]);
					}
					break;

			case 0x11:
				//event->event = lvalue[0];
				event->x = (lvalue[1]<<8)|lvalue[2];
				event->y = (lvalue[3]<<8)|lvalue[4];
				
				if(lvalue[1] == 0x01) //Slide right
					{
						kal_prompt_trace(MOD_TP_TASK, "ctp_read_one_point event0=%d,event1=%d", lvalue[0], lvalue[1]);
					}
				else if(lvalue[1] == 0x81) //Slide left
					{
						kal_prompt_trace(MOD_TP_TASK, "ctp_read_one_point event0=%d,event1=%d", lvalue[0], lvalue[1]);
					}
				else if(lvalue[1] == 0x09) //Slide up
					{
						kal_prompt_trace(MOD_TP_TASK, "ctp_read_one_point event0=%d,event1=%d", lvalue[0], lvalue[1]);
					}
				else if(lvalue[1] == 0x89) //Slide Down
					{
						kal_prompt_trace(MOD_TP_TASK, "ctp_read_one_point event0=%d,event1=%d", lvalue[0], lvalue[1]);
					}
				break;

			case 0x12:
			case 0x13:
				//event->event = PEN_DOWN;
				event->x = (lvalue[1]<<8)|lvalue[2];
				event->y = (lvalue[3]<<8)|lvalue[4];
				kal_prompt_trace(MOD_TP_TASK, "ctp_read_one_point event=%d, x = %d, y = %d", lvalue[0], event->x, event->y);
				break;

			case 0x20:
				if(lvalue[1] == 0x01) //Zoom In
					{
						kal_prompt_trace(MOD_TP_TASK, "ctp_read_one_point event0=%d,event1=%d", lvalue[0], lvalue[1]);
					}
				else if(lvalue[1] == 0x81) //Zoom Out
					{
						kal_prompt_trace(MOD_TP_TASK, "ctp_read_one_point event0=%d,event1=%d", lvalue[0], lvalue[1]);
					}
				break;
				
			default:
				
				kal_prompt_trace(MOD_TP_TASK, "ctp_read_one_point event=%d, x = %d, y = %d", lvalue[0], event->x, event->y);;
				
		}
	
	return KAL_TRUE;
}
/*
kal_bool ctp_read_all_point(TouchPanelCapacitiveEventStruct *tpes, kal_uint32 points)
{
	kal_uint32 i=0;
	kal_uint32 x_base[] = {TOUCH1_XH_ADDR, TOUCH2_XH_ADDR, TOUCH3_XH_ADDR, TOUCH4_XH_ADDR};
	TP_SINGLE_EVENT_T get_one_point;
	
	kal_prompt_trace(MOD_TP_TASK, "ctp_read_all_point points=%d", points);
	
	ASSERT(tpes);
	if((points<1) || (points>5))
		return KAL_FALSE;
		
	for(i=0;i<points;i++)
	{
		ctp_read_one_point(x_base[i], &get_one_point);
		tpes->points[i].x = get_one_point.x;
		tpes->points[i].y = get_one_point.y;
		tpes->points[i].z = get_one_point.z;
		kal_prompt_trace(MOD_TP_TASK, "ctp_read_all_point point%d x=%d y=%d z=%d", i+1, get_one_point.x, get_one_point.y, get_one_point.z);
	}	
	return KAL_TRUE;
}
*/
kal_bool ctp_novatek_nt11001_get_data(TouchPanelMultipleEventStruct *tpes)
{
	kal_uint8 lvalue;
	//kal_uint32 counter = 0, model = 0;
	TP_SINGLE_EVENT_T get_data;
	
	ASSERT(tpes);
		
	ctp_i2c_power_on(1,CTP_I2C_LDO, CTP_I2C_LDO_VOLTAGE);

	tpes->time_stamp = (kal_uint16)L1I_GetTimeStamp();
	tpes->padding = CTP_PATTERN;
	tpes->model = 1; //only one finger
	CTP_I2C_READ(0x00, &lvalue, 1);

	if(lvalue != 0x00)
		{
			tpes->model = 1; //only one finger
			ctp_read_data(&(tpes->points[0]));
			return KAL_TRUE;
		}
	else
		{
			tpes->model = 0;
			return KAL_FALSE;
		}	
	
}

CTP_custom_information_struct *ctp_Get_Data(void) 
{
	return (&ctp_custom_information_def);
}

CTP_customize_function_struct ctp_custom_func=
{
	//ctp_novatek_nt11001_device_mode,
	//ctp_Get_Data,
	ctp_novatek_nt11001_init,
	ctp_novatek_nt11001_set_device_mode,
	ctp_novatek_nt11001_hisr,
	ctp_novatek_nt11001_get_data,
	ctp_novatek_nt11001_parameters
};

CTP_customize_function_struct *ctp_GetFunc(void)
{
	return (&ctp_custom_func);  
}
#endif //#if defined(__TOUCH_PANEL_CAPACITY__)
