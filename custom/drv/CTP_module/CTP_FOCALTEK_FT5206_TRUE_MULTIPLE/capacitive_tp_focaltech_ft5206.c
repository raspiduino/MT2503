#if defined(__TOUCH_PANEL_CAPACITY__)
/**********************************************************************
*	Head files
**********************************************************************/
#include "kal_release.h"
#include "pwic.h"
#include "sccb_v2.h"
#include "touch_panel.h"
#include "eint.h"
#include "capacitive_tp_focaltech_ft5206.h"
#include "drv_comm.h"
#include "Capacitive_TP_I2C.h"
#include "I2c.h"
#include "Dcl.h"
#include "touch_panel_custom.h"

/*****************************************************
			CTP debug macro define
*****************************************************/
#define DBG_CTP
#ifdef DBG_CTP
#define ctp_dbg_print		kal_prompt_trace
#else
#define ctp_dbg_print(...)
#endif

#if !defined(IC_MODULE_TEST)
extern kal_uint32 /*lint -e(526)*/L1I_GetTimeStamp(void);
#endif

/*****************************************************
			CTP global struct and variable
*****************************************************/
/*
The variable CTP_DELAY_TIME is to indicate the I2C transmission speed.
But the speed will be modified after calling function ctp_i2c_configure()
*/
kal_uint32 CTP_DELAY_TIME	= 200;

CTP_parameters_struct CTP_parameters;

/*
This struct recorded the basic infomation of the CTP vendor and chip id
*/
CTP_custom_information_struct  ctp_custom_information_def = 
{
	"FOCAL",
	"FT5206",
	"UNKNOWN ",	
};


/*********************************************************************
 *    			I2C and CTP transmission API 
 *				Function Implement 
 *********************************************************************/
/*
Enable HW I2C power domain.
JUST for HW I2C.

CTP_I2C_LDO 			==>		HW I2C using LDO 	(see to enum PMU_LDO_BUCK_LIST_ENUM)
CTP_I2C_LDO_VOLTAGE	==>		The voltage of VIO	(see to enum PMU_VOLTAGE_ENUM)
CTP_I2C_LDO and CTP_I2C_LDO_VOLTAGE are defined in the file "touch_panel_custom.h".
The customer can modify them according to the actual hardware design
*/
void CTP_I2C_POWER_ON(void)
{
	ctp_i2c_power_on(KAL_TRUE, CTP_I2C_LDO, CTP_I2C_LDO_VOLTAGE);
}

/*
Do HW I2C initialization
JUST for HW I2C.

About "I2C CLOCK EXTENSION",  it is a feature of the Hardware I2C.
Enable I2C clock extension. It means host will hold the clk pin low until client pull the clk pin high.
To some CTP chip that need much strict I2C timing, we should enable I2C clock extension feature.
*/
void CTP_I2C_Init(void)
{
	ctp_i2c_configure(CTP_SLAVE_ADDR, 300);		//set hw i2c speed is 300K (fast mode)
	ENABLE_I2C_CLOCK_EXTENSION;					//<==Must enable i2c_clk_extension for being ensure controller timing matching with HW I2C timing

}

/*
Send bytes to ft5206 CTP IC
Example:
	data: RegisterAddress(8bit)   RegisterValue(8bit)
	len = 2
*/
kal_bool ft5206_write_bytes(kal_uint8 *data, kal_uint8 len)
{
	kal_bool temp_result; 
	kal_uint8 reg_addr;
	
	reg_addr = data[0];
	data++;

	temp_result = ctp_i2c_send(CTP_SLAVE_ADDR, reg_addr, data, len-1);

	if (KAL_FALSE == temp_result)
	{
		ctp_dbg_print(MOD_TP_TASK, "FT5206 Write bytes fail!");
		return KAL_FALSE;
	}
	else
	{
		return KAL_TRUE;
	}
}

/*
Read bytes from FT5206 CTP IC

reg_addr	: Register Address
value	: The pointer of data to be read
len		: The length of the data to be read
*/
kal_bool ft5206_read_bytes(kal_uint8 reg_addr, kal_uint8 *value, kal_uint16 len) 
{
	kal_bool temp_result;
	
	temp_result = ctp_i2c_receive(CTP_SLAVE_ADDR, reg_addr, value, len);
	
	if (KAL_FALSE == temp_result)
	{
		ctp_dbg_print(MOD_TP_TASK, "FT5206 Read bytes fail!");		
		return KAL_FALSE;
	}
	else
	{
		return KAL_TRUE;
	}
}


/***************************************************************
*    			     FT5206 CTP driver API 
*				Function Implement 
***************************************************************/
/*
FT5206 CTP initialization

In the initialization, we should do:
1. Enable VIO power domain and config the slaver address and i2c speed
2. Config EINT debounce time and sensitivity
*/
kal_bool ctp_focaltech_ft5206_init(void)
{
	kal_uint8 lvalue;
	kal_uint8 write_data[2];
	kal_bool temp_result = KAL_TRUE;

	CTP_I2C_POWER_ON();
	CTP_I2C_Init();

	kal_sleep_task(1);

	/*
	The following writing 0x0B to Register 0x00 action is MAYBE not possible.
	*/
	write_data[0] = HST_MODE_ADDR;
	write_data[1] =	0x0B;	//soft reset
	temp_result = ft5206_write_bytes(write_data, 2);

	if (KAL_FALSE == temp_result)
	{
		ctp_dbg_print(MOD_TP_TASK, "write HST_MODE_ADDR 0x0B fail!");
	}

	temp_result = ft5206_read_bytes(HST_MODE_ADDR, &lvalue, 1);

	if (KAL_FALSE == temp_result)
	{
		ctp_dbg_print(MOD_TP_TASK, "read HST_MODE_ADDR fail!");
	}

	/*
	config EINT debounce time and sensitivity
	MUST set 0 to EINT debounce
	*/
    EINT_Set_HW_Debounce(custom_eint_get_channel(touch_panel_eint_chann), 0);
    EINT_SW_Debounce_Modify(custom_eint_get_channel(touch_panel_eint_chann),0);
	EINT_Set_Sensitivity(custom_eint_get_channel(touch_panel_eint_chann), EDGE_SENSITIVE);
    
    if (KAL_FALSE == temp_result)
    {
    	ctp_dbg_print(MOD_TP_TASK, "ctp_cypress_cy8ctma340_init failed!");

		return KAL_FALSE;
    }
	else
	{
		ctp_dbg_print(MOD_TP_TASK, "ctp_cypress_cy8ctma340_init succeed! HST_MODE_ADDR=%x", lvalue);

		return KAL_TRUE;
	}
}


/*
Upper layer will call this function to enable/disable CTP power.
If FOCUS the POWRE CONSUME, it is suggested to implement it!
*/
kal_bool ctp_focaltech_ft5206_power_on(kal_bool enable)
{
	//_TODO:  Implement this funciton by customer
}


/*
If needed, uppder layer will call this function to swicth CTP mode.

By now, Maybe this function has not been used by upper layer.
If you want to implement this function, you can see the sample code in the function body.
*/
kal_bool ctp_focaltech_ft5206_device_mode(ctp_device_mode_enum mode)
{

	//_TODO:  if needed, add this function to switch decive work mode
	//_TODO: Implement this function by customer

	if(mode == CTP_ACTIVE_MODE)
	{
		#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	    #endif
	}
	else if(mode == CTP_IDLE_MODE)
	{
		
	}
	else if(mode == CTP_SLEEP_MODE)
	{
		
	}
	
	return KAL_TRUE;
}


/*
The following function is JUST used in timer trigger mode. 
Now we use interrupt mode to get data. So this function is not used.

ATTENTION: DO NOT delete this function!!
This function is one member of the CTP function pointer struct.
*/
Touch_Panel_PenState_enum ctp_focaltech_ft5206_hisr(void)
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
#endif
}


/*
This function is a INTERNAL FUNCTION in CTP driver.
By now, it has not been used~
If needed, implement it by yourselves.
But NO implement is OK~
*/
kal_bool ctp_focaltech_ft5206_get_version(CTP_custom_information_struct  *version)
{
	return KAL_TRUE;
}

/*
This function is used to get parameter from CTP IC or set parameter to CTP IC.

By now, Maybe this function has not been used by upper layer.
ATTENTION: If need to implement it, DO NOT get and set the same parameter in the same time
*/
kal_bool ctp_focaltech_ft5206_parameters(CTP_parameters_struct *para, kal_uint32 get_para, kal_uint32 set_para)
{
	//_TODO: not implement. if needed,  please add them.
	//_TODO: Implement this function by customer


	kal_bool result = KAL_TRUE;
	
	/*this function can NOT	 get and set the same parameter in the same time*/
	if (get_para & set_para)
	{
		ASSERT(0);
	}
	
	if (set_para & CTP_PARA_RESOLUTION)
	{
		result &= KAL_FALSE; 
	}
	else if (set_para & CTP_PARA_THRESHOLD)
	{
		result &= KAL_FALSE; 
	}
	else if (set_para & CTP_PARA_REPORT_INTVAL)
	{
		result &= KAL_TRUE;
	}
	else if (set_para & CTP_PARA_IDLE_INTVAL)
	{
		result &= KAL_FALSE;
	}
	else if (set_para & CTP_PARA_SLEEP_INTVAL)
	{
		result &= KAL_FALSE;
	}
	
	if (get_para & CTP_PARA_RESOLUTION)
	{
		result &= KAL_FALSE;
	}
	else if (get_para & CTP_PARA_THRESHOLD)
	{
		result &= KAL_FALSE;
	}
	else if (get_para & CTP_PARA_REPORT_INTVAL)
	{
		result = KAL_TRUE;
	}
	else if (get_para & CTP_PARA_IDLE_INTVAL)
	{
		result &= KAL_FALSE;
	}
	else if (get_para & CTP_PARA_SLEEP_INTVAL)
	{
		result &= KAL_FALSE;
	}
			
	return result;
}

/*
This function is a INTERNAL FUNCTION in the CTP driver.
It ONLY can be used to read the coordination value of one point 
and JUST be called by ft5206_read_all_point() function.
*/
kal_bool ft5206_read_one_point(kal_uint32 x_base, TP_SINGLE_EVENT_T *event)
{
	kal_bool temp_result;
    kal_uint8 values[4] = {0};
	
	temp_result = ft5206_read_bytes(x_base, values, 4);

	if (KAL_FALSE == temp_result)
	{
		ctp_dbg_print(MOD_TP_TASK, "ctp_read_one_point fail!");

		return KAL_FALSE;
	}
	else
	{
		ctp_dbg_print(MOD_TP_TASK, "ctp_read_one_point 0x%x, 0x%x, 0x%x, 0x%x", values[0], values[1], values[2], values[3]);
		event->x =   (((kal_uint16)(values[0]&0x0f))<<8) | values[1];
		event->y =   (((kal_uint16)(values[2]&0x0f))<<8) | values[3];
		ctp_dbg_print(MOD_TP_TASK, "ctp_read_one_point x=%d y=%d",  event->x, event->y);

		return KAL_TRUE;
	}
}

/*
This fucntion is a INTERNAL FUNCTION in the CTP driver.

It ONLY can be used to read the coordination values of all points that are pressed now 
and JUST be called by ctp_focaltech_ft5206_get_data() function.
*/
kal_bool ft5206_read_all_point(TouchPanelMultipleEventStruct *tpes, kal_uint32 points)
{
	kal_bool temp_result;
	kal_uint32 i = 0;
	kal_uint32 x_base[] = {	TOUCH1_XH_ADDR,
							TOUCH2_XH_ADDR, 
							TOUCH3_XH_ADDR, 
							TOUCH4_XH_ADDR};
	TP_SINGLE_EVENT_T get_one_point;
	
	ctp_dbg_print(MOD_TP_TASK, "ctp_read_all_point points=%d", points);
	
	ASSERT(tpes);

	/*By now we ONLY can support FIVE points at most*/
	if (points > 5)	
	{
		return KAL_FALSE;
	}
	
	for (i=0; i<points; i++)
	{
		temp_result = ft5206_read_one_point(x_base[i], &get_one_point);

		if (KAL_FALSE == temp_result)
		{
			ctp_dbg_print(MOD_TP_TASK, "read %d point failed!");

			return KAL_FALSE;
		}
		else
		{
			tpes->points[i].x = get_one_point.x;
			tpes->points[i].y = get_one_point.y;
			ctp_dbg_print(MOD_TP_TASK, "piont[%d], x:%d, y:%d", i, get_one_point.x, get_one_point.y);
		}
	}
	
	return KAL_TRUE;
}

/*
This function is used to get the raw data of the fingures that are pressed.
When CTP IC send intterupt signal to BB chip, this function will be called in the interrupt handler function.

ATTENTION: Becasue this function is called in the interrupt handler function, it MUST NOT run too long.
That will block the entire system.
If blocking too long, it generally will cause system crash *....*
*/
kal_bool ctp_focaltech_ft5206_get_data(TouchPanelMultipleEventStruct *tpes)
{
	kal_bool temp_result;
	kal_uint8 lvalue;
	kal_uint32 counter = 0;
	kal_uint32 model = 0;
	
	ASSERT(tpes);

	tpes->time_stamp = (kal_uint16)L1I_GetTimeStamp();
	tpes->padding = CTP_PATTERN;

	/*Using while loop to poll the CTP status.
	   We have to wait for CTP being ready, then get the coordination of the all points.
	*/
	do
	{ 
		temp_result = ft5206_read_bytes(TD_STAT_ADDR, &lvalue, 1);
		/*
		Here the value "0x30" is JUST a CAUTIOUS experience value. 
		ATTENTION: If here waiting too long, it will block the system!!!
		If in hand writing zone, writing is not continuous.
		Please modify this value to a little bigger one.
		It is strongly suggested that this value is not more than 0xFF!
		*/
		if (counter++ == 0x30)
		{
			return KAL_FALSE;
		}
	} while(lvalue & TT_MODE_BUFFER_INVALID); 
	
	model = (kal_uint32)(lvalue & TD_STAT_NUMBER_TOUCH);
	ctp_dbg_print(MOD_TP_TASK, "ctp_get_data model=%d", model);
		
	tpes->model = (kal_uint16)model;

	/*
	0 fingure meas UP EVENT, so return FALSE;
	And now we only support FIVE fingures at most, so if more than 5 fingures also return FALSE 
	*/	
	if ((model == 0)||(model > 5))
	{
		return KAL_FALSE;
	}
	
	temp_result = ft5206_read_all_point(tpes, model);

	if (KAL_FALSE == temp_result)
	{
		ctp_dbg_print(MOD_TP_TASK, "read all points failed!");

		return KAL_FALSE;
	}
	
	return KAL_TRUE;
}

/*
JUST return CTP information.
Not Need to modify it!
*/
CTP_custom_information_struct *ctp_Get_Data(void) 
{
	return (&ctp_custom_information_def);
}

/*
This structure is to initialize function pointer to CTP driver.
NOT all function MUST BE implemented in this struct, 
JUST doing function declaration is OK!!

But the following TWO functions MUST BE implemented:
ctp_focalteck_ft5206_init
ctp_focalteck_ft5206_get_data

Other functions should be implemented by customer for better performance.
*/
CTP_customize_function_struct ctp_custom_func=
{
	ctp_focaltech_ft5206_init,
	ctp_focaltech_ft5206_device_mode,
	ctp_focaltech_ft5206_hisr,
	ctp_focaltech_ft5206_get_data,
	ctp_focaltech_ft5206_parameters,
	ctp_focaltech_ft5206_power_on
};

/*
Upper layer use this hook to get CTP driver function
*/
CTP_customize_function_struct *ctp_GetFunc(void)
{
	return (&ctp_custom_func);  
}
#endif //#if defined(__TOUCH_PANEL_CAPACITY__)
