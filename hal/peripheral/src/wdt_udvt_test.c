#include "kal_release.h"      /* Basic data type */
#include "drv_features.h"
#include "kal_public_api.h"
#include "kal_debug.h"
#include "kal_public_defs.h"
#include "string.h"
#include <stdlib.h>
#include "stdio.h"
#include "uart_sw.h"
#include "fat_fs.h"
#include "us_timer.h"
#include "dcl.h"
#include "dcl_gpt.h"
#include "dcl_gpt_hw.h"
#include "kal_internal_api.h"
#include "drv_comm.h"
#include "dcl_wdt.h"
#include "wdt_sw.h"
#include "wdt_hw.h"
#include "intrCtrl.h"
#include "us_timer.h"
/**********************************************/


#define TEST_CASE_INIT_INPUT_DATA 0xFFFFFFFF
#define ESCKEY (0x1b)

DCL_HANDLE wdt_handle;
kal_bool Is_Case_Running = KAL_FALSE;

extern kal_uint8 U_GetUARTByte(UART_PORT port);
void uDVT_WDT_Initialize();


void wdt_udvt_testcase1();
void wdt_udvt_testcase2();
void wdt_udvt_testcase3();
void wdt_udvt_testcase4();
void wdt_udvt_testcase5();
void wdt_udvt_testcase6();
void wdt_udvt_testcase7();
void wdt_udvt_testcase8();
void wdt_udvt_testcase9();
void wdt_udvt_testcase10();
static void wdt_dbg_input(kal_uint32 *value);
void dvt_wdt_lisr(void);


/*************************************************************************
* FUNCTION
*  wdt_udvt_main_test
*
* DESCRIPTION
*  This function is the main entry for wdt test case
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/

void wdt_udvt_main_test(task_entry_struct *task_entry_ptr)
{
	kal_uint32 input_data = TEST_CASE_INIT_INPUT_DATA;
	wdt_handle = DclWDT_Open(DCL_WDT,0);
	uDVT_WDT_Initialize();

	while(1)
	{
		if(!Is_Case_Running)
		{
			dbg_print("***********************************************************\r\n");
			dbg_print("*****************WDT UDVT Test Begin***********************\r\n");
			dbg_print("***********************************************************\r\n");
			dbg_print("        number0: choice again\r\n");
			dbg_print("        number1: Case1-- wdt timeout test:15.6ms\r\n");
			dbg_print("        number2: Case2-- wdt timeout test: 4s\r\n");
			dbg_print("        number3: Case3-- wdt timeout test: 30s\r\n");
			dbg_print("        number4: Case4-- wdt sw reset test\r\n");
			dbg_print("        number5: Case5-- wdt external reset pin polarity/duration test: positive\r\n");
			dbg_print("        number6: Case6-- wdt external reset pin polarity/duration test: nagative\r\n");
			dbg_print("        number7: Case7-- wdt enable/disable test\r\n");
			dbg_print("        number8: Case8-- wdt interrupt test\r\n");
			dbg_print("        number9: Case9-- wdt default value test\r\n");
			dbg_print("        number10: Case10-- wdt hw auto run test.\r\n");
			dbg_print("***********************************************************\r\n");

			wdt_dbg_input(&input_data);
			dbg_print("\r\n");
			
			switch (input_data)
			{
				case 1:
				{
					wdt_udvt_testcase1();//gtp1 one shot
					break;
				}
				case 2:
				{
					wdt_udvt_testcase2();//gpt1 repeat mode
					break;
				}
				case 3:
				{
					wdt_udvt_testcase3();//gpt2 oneshot
					break;
				}
				case 4:
				{
					wdt_udvt_testcase4();//gpt2 repeat mode
					break;
				}
				case 5:
				{
					wdt_udvt_testcase5();//gpt1 time up after expected time period with onshot
					break;
				}
				case 6:
				{
					wdt_udvt_testcase6();//gpt2 time up after expected time period with one shot
					break;
				}
				
				case 7:
				{
					wdt_udvt_testcase7();//gpt2 time up after expected time period with repeat
					break;
				}
				
				case 8:
				{
					wdt_udvt_testcase8();//gpt2 time up after expected time period with repeat
					break;
				}
				case 9:
				{
					wdt_udvt_testcase9();//gpt4. no lock,enable/reset  bit can start count as expected.
					break;
				}
				
				case 10:
				{
					wdt_udvt_testcase10();//gpt4. enable=1,lock=1.
					break;
				}
				
				default:
				{
					dbg_print("wrong case number,pls input case number again \r\n");
					break;
				}
			}
			
				
		}
	}
}
/*************************************************************************
* FUNCTION
*  wdt_udvt_testcase1
*
* DESCRIPTION
*  This function is for testcase 1
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/
void wdt_udvt_testcase1()
{
	kal_uint32 savedMask;
	WDT_CTRL_ENABLE_T  rEnable;
	WDT_CTRL_SET_VALUE_T rSetValue;
	rEnable.fgEnable = KAL_TRUE;
	rSetValue.u2Value = 1;
	savedMask = SaveAndSetIRQMask();
	DclWDT_Control(wdt_handle,WDT_CMD_SET_VALUE,(DCL_CTRL_DATA_T *)&rSetValue);
	DclWDT_Control(wdt_handle,WDT_CMD_RESTART,NULL);
	DclWDT_Control(wdt_handle,WDT_CMD_ENABLE,(DCL_CTRL_DATA_T *)&rEnable);
	while(1);
}

/*************************************************************************
* FUNCTION
*  wdt_udvt_testcase2
*
* DESCRIPTION
*  This function is for testcase 2
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/
void wdt_udvt_testcase2()
{
	kal_uint32 savedMask;
	WDT_CTRL_ENABLE_T  rEnable;
	WDT_CTRL_SET_VALUE_T rSetValue;
	rEnable.fgEnable = KAL_TRUE;
	rSetValue.u2Value = 255;
	savedMask = SaveAndSetIRQMask();
	DclWDT_Control(wdt_handle,WDT_CMD_SET_VALUE,(DCL_CTRL_DATA_T *)&rSetValue);
	DclWDT_Control(wdt_handle,WDT_CMD_RESTART,NULL);
	DclWDT_Control(wdt_handle,WDT_CMD_ENABLE,(DCL_CTRL_DATA_T *)&rEnable);
	while(1);

}
/*************************************************************************
* FUNCTION
*  wdt_udvt_testcase3
*
* DESCRIPTION
*  This function is for testcase 3
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/
void wdt_udvt_testcase3()
{
	kal_uint32 savedMask;
	WDT_CTRL_ENABLE_T  rEnable;
	WDT_CTRL_SET_VALUE_T rSetValue;
	rEnable.fgEnable = KAL_TRUE;
	rSetValue.u2Value = 2047;
	savedMask = SaveAndSetIRQMask();
	DclWDT_Control(wdt_handle,WDT_CMD_SET_VALUE,(DCL_CTRL_DATA_T *)&rSetValue);
	DclWDT_Control(wdt_handle,WDT_CMD_RESTART,NULL);
	DclWDT_Control(wdt_handle,WDT_CMD_ENABLE,(DCL_CTRL_DATA_T *)&rEnable);
	while(1);
}

/*************************************************************************
* FUNCTION
*  wdt_udvt_testcase4
*
* DESCRIPTION
*  This function is for testcase 4
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/
void wdt_udvt_testcase4()
{
	kal_uint32 savedMask;
	kal_uint32 input_data = TEST_CASE_INIT_INPUT_DATA;
	WDT_CTRL_ENABLE_T  rEnable;
	WDT_CTRL_SET_VALUE_T rSetValue;
	rEnable.fgEnable = KAL_TRUE;
	rSetValue.u2Value = 2048;

	
	savedMask = SaveAndSetIRQMask();
	dbg_print("Case1-- sw reset with wdt enable\r\n");
	dbg_print("Case2-- sw reset with wdt disable\r\n");
	
	wdt_dbg_input(&input_data);
	dbg_print("\r\n");
	
	switch (input_data)
	{
		case 1:
		{
			DclWDT_Control(wdt_handle,WDT_CMD_ENABLE,(DCL_CTRL_DATA_T *)&rEnable);
			DRV_WDT_WriteReg32(WDT_SWRST,WDT_SWRST_KEY); /* there is no simple command to set sw register. so we hard code */
			while(1);
			break;
		}
		case 2:
		{
			rEnable.fgEnable = KAL_FALSE;
			DclWDT_Control(wdt_handle,WDT_CMD_ENABLE,(DCL_CTRL_DATA_T *)&rEnable);
			DRV_WDT_WriteReg32(WDT_SWRST,WDT_SWRST_KEY); /* there is no simple command to set sw register. so we hard code */
			while(1);
			break;
		}
		default:
		{
			dbg_print("wrong case number , make choice again \r\n");
			return;
		}
	}
}


/*************************************************************************
* FUNCTION
*  wdt_udvt_testcase5
*
* DESCRIPTION
*  This function is for testcase 5
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/
void wdt_udvt_testcase5()
{
	kal_uint32 savedMask;
	kal_uint32 input_data = TEST_CASE_INIT_INPUT_DATA;
	WDT_CTRL_ENABLE_T  rEnable;
	WDT_CTRL_SET_VALUE_T rSetValue;
	WDT_CTRL_SET_EXT_POL_T rPol;
	WDT_CTRL_IRQ_T rIRQ;
	rEnable.fgEnable = KAL_TRUE;
	rSetValue.u2Value = 255; /* 4s*/
	rPol.fgIOHigh = KAL_TRUE;
	rIRQ.fgEnable = KAL_TRUE;

	
	//savedMask = SaveAndSetIRQMask();
	dbg_print("Case1-- extern pin with reset mode and timeout\r\n");
	dbg_print("Case2-- extern pin with interrupt mode and timeout\r\n");
	dbg_print("Case3-- extern pin with reset mode and sw reset\r\n");
	dbg_print("Case4-- extern pin with interrupt mode and sw reset\r\n");
	
	wdt_dbg_input(&input_data);
	dbg_print("\r\n");
	
	switch (input_data)
	{
		case 1:
		{
			rIRQ.fgEnable = KAL_FALSE;
			DclWDT_Control(wdt_handle,WDT_CMD_IRQ,(DCL_CTRL_DATA_T *)&rIRQ);
			ust_busy_wait(35);/*wdt mode register must have 32k delay*/
			DclWDT_Control(wdt_handle,WDT_CMD_SET_EXT_POL,(DCL_CTRL_DATA_T *)&rPol);
			ust_busy_wait(35);/*wdt mode register must have 32k delay*/
			DclWDT_Control(wdt_handle,WDT_CMD_SET_VALUE,(DCL_CTRL_DATA_T *)&rSetValue);
			DclWDT_Control(wdt_handle,WDT_CMD_RESTART,NULL);
			DclWDT_Control(wdt_handle,WDT_CMD_ENABLE,(DCL_CTRL_DATA_T *)&rEnable);
			while(1);
			break;
		}
		case 2:
		{
			rIRQ.fgEnable = KAL_TRUE;
			
			IRQSensitivity(IRQ_WDT_CODE,EDGE_SENSITIVE);
			IRQ_Register_LISR(IRQ_WDT_CODE,dvt_wdt_lisr,"wdt lisr");
			IRQUnmask(IRQ_WDT_CODE);
			DclWDT_Control(wdt_handle,WDT_CMD_IRQ,(DCL_CTRL_DATA_T *)&rIRQ);
			ust_busy_wait(35);/*wdt mode register must have 32k delay*/
			DclWDT_Control(wdt_handle,WDT_CMD_SET_EXT_POL,(DCL_CTRL_DATA_T *)&rPol);
			ust_busy_wait(35);
			DclWDT_Control(wdt_handle,WDT_CMD_SET_VALUE,(DCL_CTRL_DATA_T *)&rSetValue);
			DclWDT_Control(wdt_handle,WDT_CMD_RESTART,NULL);
			DclWDT_Control(wdt_handle,WDT_CMD_ENABLE,(DCL_CTRL_DATA_T *)&rEnable);
			//RestoreIRQMask(savedMask);
			while(1);
			break;
		}
		case 3:
		{
			rIRQ.fgEnable = KAL_FALSE;
			DclWDT_Control(wdt_handle,WDT_CMD_IRQ,(DCL_CTRL_DATA_T *)&rIRQ);
			ust_busy_wait(35);/*wdt mode register must have 32k delay*/
			DclWDT_Control(wdt_handle,WDT_CMD_SET_EXT_POL,(DCL_CTRL_DATA_T *)&rPol);
			DRV_WDT_WriteReg32(WDT_SWRST,WDT_SWRST_KEY); /* there is no simple command to set sw register. so we hard code */
			while(1);
			break;
		}
		case 4:
		{
			rIRQ.fgEnable = KAL_TRUE;
			IRQSensitivity(IRQ_WDT_CODE,EDGE_SENSITIVE);
			IRQ_Register_LISR(IRQ_WDT_CODE,dvt_wdt_lisr,"wdt lisr");
			IRQUnmask(IRQ_WDT_CODE);
			DclWDT_Control(wdt_handle,WDT_CMD_IRQ,(DCL_CTRL_DATA_T *)&rIRQ);
			ust_busy_wait(35);/*wdt mode register must have 32k delay*/
			DclWDT_Control(wdt_handle,WDT_CMD_SET_EXT_POL,(DCL_CTRL_DATA_T *)&rPol);
			DRV_WDT_WriteReg32(WDT_SWRST,WDT_SWRST_KEY); /* there is no simple command to set sw register. so we hard code */
			//RestoreIRQMask(savedMask);
			while(1);
			break;
		}
		default:
		{
			dbg_print("wrong case number , make choice again \r\n");
			return;
		}
	}
	
	rEnable.fgEnable = KAL_FALSE;
	DclWDT_Control(wdt_handle,WDT_CMD_ENABLE,(DCL_CTRL_DATA_T *)&rEnable);
}




/*************************************************************************
* FUNCTION
*  wdt_udvt_testcase6
*
* DESCRIPTION
*  This function is for testcase 6
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/
void wdt_udvt_testcase6()
{
	kal_uint32 savedMask;
	kal_uint32 input_data = TEST_CASE_INIT_INPUT_DATA;
	WDT_CTRL_ENABLE_T  rEnable;
	WDT_CTRL_SET_VALUE_T rSetValue;
	WDT_CTRL_SET_EXT_POL_T rPol;
	WDT_CTRL_IRQ_T rIRQ;
	rEnable.fgEnable = KAL_TRUE;
	rSetValue.u2Value = 255; /* 4s*/
	rPol.fgIOHigh = KAL_FALSE;
	rIRQ.fgEnable = KAL_TRUE;

	
	//savedMask = SaveAndSetIRQMask();
	dbg_print("Case1-- extern pin with reset mode and timeout\r\n");
	dbg_print("Case2-- extern pin with interrupt mode and timeout\r\n");
	dbg_print("Case3-- extern pin with reset mode and sw reset\r\n");
	dbg_print("Case4-- extern pin with interrupt mode and sw reset\r\n");
	
	wdt_dbg_input(&input_data);
	dbg_print("\r\n");
	
	switch (input_data)
	{
		case 1:
		{
			rIRQ.fgEnable = KAL_FALSE;
			DclWDT_Control(wdt_handle,WDT_CMD_IRQ,(DCL_CTRL_DATA_T *)&rIRQ);
			ust_busy_wait(35);/*wdt mode register must have 32k delay*/
			DclWDT_Control(wdt_handle,WDT_CMD_SET_EXT_POL,(DCL_CTRL_DATA_T *)&rPol);
			ust_busy_wait(35);/*wdt mode register must have 32k delay*/
			DclWDT_Control(wdt_handle,WDT_CMD_SET_VALUE,(DCL_CTRL_DATA_T *)&rSetValue);
			DclWDT_Control(wdt_handle,WDT_CMD_RESTART,NULL);
			DclWDT_Control(wdt_handle,WDT_CMD_ENABLE,(DCL_CTRL_DATA_T *)&rEnable);
			while(1);
			break;
		}
		case 2:
		{
			rIRQ.fgEnable = KAL_TRUE;
			IRQSensitivity(IRQ_WDT_CODE,EDGE_SENSITIVE);
			IRQ_Register_LISR(IRQ_WDT_CODE,dvt_wdt_lisr,"wdt lisr");
			IRQUnmask(IRQ_WDT_CODE);
			DclWDT_Control(wdt_handle,WDT_CMD_IRQ,(DCL_CTRL_DATA_T *)&rIRQ);
			ust_busy_wait(35);/*wdt mode register must have 32k delay*/
			DclWDT_Control(wdt_handle,WDT_CMD_SET_EXT_POL,(DCL_CTRL_DATA_T *)&rPol);
			ust_busy_wait(35);/*wdt mode register must have 32k delay*/
			DclWDT_Control(wdt_handle,WDT_CMD_SET_VALUE,(DCL_CTRL_DATA_T *)&rSetValue);
			DclWDT_Control(wdt_handle,WDT_CMD_RESTART,NULL);
			DclWDT_Control(wdt_handle,WDT_CMD_ENABLE,(DCL_CTRL_DATA_T *)&rEnable);
			//RestoreIRQMask(savedMask);
			while(1);
			break;
		}
		case 3:
		{
			rIRQ.fgEnable = KAL_FALSE;
			DclWDT_Control(wdt_handle,WDT_CMD_IRQ,(DCL_CTRL_DATA_T *)&rIRQ);
			ust_busy_wait(35);/*wdt mode register must have 32k delay*/
			DclWDT_Control(wdt_handle,WDT_CMD_SET_EXT_POL,(DCL_CTRL_DATA_T *)&rPol);
			DRV_WDT_WriteReg32(WDT_SWRST,WDT_SWRST_KEY); /* there is no simple command to set sw register. so we hard code */
			while(1);
			break;
		}
		case 4:
		{
			rIRQ.fgEnable = KAL_TRUE;
			IRQSensitivity(IRQ_WDT_CODE,EDGE_SENSITIVE);
			IRQ_Register_LISR(IRQ_WDT_CODE,dvt_wdt_lisr,"wdt lisr");
			IRQUnmask(IRQ_WDT_CODE);
			DclWDT_Control(wdt_handle,WDT_CMD_IRQ,(DCL_CTRL_DATA_T *)&rIRQ);
			ust_busy_wait(35);/*wdt mode register must have 32k delay*/
			DclWDT_Control(wdt_handle,WDT_CMD_SET_EXT_POL,(DCL_CTRL_DATA_T *)&rPol);
			DRV_WDT_WriteReg32(WDT_SWRST,WDT_SWRST_KEY); /* there is no simple command to set sw register. so we hard code */
			//RestoreIRQMask(savedMask);
			while(1);
			break;
		}
		default:
		{
			dbg_print("wrong case number , make choice again \r\n");
			return;
		}
	}
	
	rEnable.fgEnable = KAL_FALSE;
	DclWDT_Control(wdt_handle,WDT_CMD_ENABLE,(DCL_CTRL_DATA_T *)&rEnable);
}

/*************************************************************************
* FUNCTION
*  wdt_udvt_testcase7
*
* DESCRIPTION
*  This function is for testcase 7
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/
void wdt_udvt_testcase7()
{
	kal_uint32 savedMask;
	kal_uint32 input_data = TEST_CASE_INIT_INPUT_DATA;
	WDT_CTRL_ENABLE_T  rEnable;
	WDT_CTRL_SET_VALUE_T rSetValue;
	rEnable.fgEnable = KAL_TRUE;
	rSetValue.u2Value = 255;

	
	savedMask = SaveAndSetIRQMask();
	dbg_print("Case1-- wdt enalbe test\r\n");
	dbg_print("Case2-- wdt disable test\r\n");
	
	wdt_dbg_input(&input_data);
	dbg_print("\r\n");
	
	switch (input_data)
	{
		case 1:
		{
			DclWDT_Control(wdt_handle,WDT_CMD_SET_VALUE,(DCL_CTRL_DATA_T *)&rSetValue);
			DclWDT_Control(wdt_handle,WDT_CMD_RESTART,NULL);
			DclWDT_Control(wdt_handle,WDT_CMD_ENABLE,(DCL_CTRL_DATA_T *)&rEnable);
			while(1);
			break;
		}
		case 2:
		{
			DclWDT_Control(wdt_handle,WDT_CMD_SET_VALUE,(DCL_CTRL_DATA_T *)&rSetValue);
			DclWDT_Control(wdt_handle,WDT_CMD_RESTART,NULL);
			DclWDT_Control(wdt_handle,WDT_CMD_ENABLE,(DCL_CTRL_DATA_T *)&rEnable);
			
			rEnable.fgEnable = KAL_FALSE;
			ust_busy_wait(35);/*wdt mode register must have 32k delay*/
			DclWDT_Control(wdt_handle,WDT_CMD_ENABLE,(DCL_CTRL_DATA_T *)&rEnable);
			while(1);
			break;
		}
		default:
		{
			dbg_print("wrong case number , make choice again \r\n");
			return;
		}
	}
}



/*************************************************************************
* FUNCTION
*  wdt_udvt_testcase8
*
* DESCRIPTION
*  This function is for testcase 8
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/
void wdt_udvt_testcase8()
{
	kal_uint32 savedMask;
	WDT_CTRL_ENABLE_T  rEnable;
	WDT_CTRL_SET_VALUE_T rSetValue;
	WDT_CTRL_IRQ_T rIRQ;
	rEnable.fgEnable = KAL_TRUE;
	rSetValue.u2Value = 255;
	rIRQ.fgEnable = KAL_TRUE;
	//savedMask = SaveAndSetIRQMask();
	IRQSensitivity(IRQ_WDT_CODE,EDGE_SENSITIVE);
	IRQ_Register_LISR(IRQ_WDT_CODE,dvt_wdt_lisr,"wdt lisr");
	IRQUnmask(IRQ_WDT_CODE);
	DclWDT_Control(wdt_handle,WDT_CMD_IRQ,(DCL_CTRL_DATA_T *)&rIRQ);
	ust_busy_wait(35);/*wdt mode register must have 32k delay*/
	DclWDT_Control(wdt_handle,WDT_CMD_SET_VALUE,(DCL_CTRL_DATA_T *)&rSetValue);
	DclWDT_Control(wdt_handle,WDT_CMD_RESTART,NULL);
	DclWDT_Control(wdt_handle,WDT_CMD_ENABLE,(DCL_CTRL_DATA_T *)&rEnable);
	
	//RestoreIRQMask(savedMask);
	while(1);
}



/*************************************************************************
* FUNCTION
*  wdt_udvt_testcase9
*
* DESCRIPTION
*  This function is for testcase 9
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/
void wdt_udvt_testcase9()
{
	kal_uint32 savedMask;
	
	dbg_print("Note, You must confirm no code modify RGU register. and no init is doing\r\n");
	dbg_print("The test method is use CVD/TR32, change the cmm, not disable wdt. \r\n");
	dbg_print("Then, see the defautl value according CVD/TR32, and wait wdt timeout \r\n");
	//savedMask = SaveAndSetIRQMask();
	//while(1);
	
}
/*************************************************************************
* FUNCTION
*  wdt_udvt_testcase10
*
* DESCRIPTION
* This function is for testcase 10
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/
void wdt_udvt_testcase10()
{
	kal_uint32 savedMask;
	
	dbg_print("Note, You must confirm no code modify RGU register. and no init is doing\r\n");
	dbg_print("This can only test by TR32/CVD according set register directly\r\n");
	dbg_print("When set hw auto run, we will see CPU reset every 30s\r\n");
	
	dbg_print("Or, there is another method: chang wdt_init function, add while(1)\r\n because no one will change WDT_MODE before wdt_init \r\n");
	dbg_print("and you can see bootrom log every 30s\r\n");
	dbg_print("test timeout and sw reset both\r\n");
	//WDT_Enable_HW_AutoRestart(KAL_TRUE);
	//savedMask = SaveAndSetIRQMask();
	//while(1);
	
}

void dvt_wdt_lisr(void)
{
	WDT_CTRL_IRQ_T rIRQ;
	rIRQ.fgEnable = KAL_FALSE;
	DclWDT_Control(wdt_handle,WDT_CMD_IRQ,(DCL_CTRL_DATA_T *)&rIRQ);
	dbg_print("This is wdt lisr,will reset...\r\n");
	ust_busy_wait(4000);
	DRV_WDT_WriteReg32(WDT_SWRST,WDT_SWRST_KEY); /* there is no simple command to set sw register. so we hard code */
}


/*************************************************************************
* FUNCTION
*  uDVT_WDT_Initialize
*
* DESCRIPTION
*  This function is the initial function, just to get the handle,and init hw gpt.
*  
*  
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/
void uDVT_WDT_Initialize()
{
	
	WDT_CTRL_ENABLE_T  rEnable;
	rEnable.fgEnable = KAL_FALSE;
	DclWDT_Control(wdt_handle,WDT_CMD_ENABLE,(DCL_CTRL_DATA_T *)&rEnable);
}


/*************************************************************************
* FUNCTION
*  wdt_dbg_input
*
* DESCRIPTION
*  this function recieves data from hyper terminal.
*  
*  
*
* PARAMETERS
*  input data
*
* RETURNS
*  None
*
*************************************************************************/
void wdt_dbg_input(kal_uint32 *value)
{
    //kal_uint32 result = 0;
    kal_uint8 str[30], input, offset;

    offset = 0;

    while (1)
    {
        input = U_GetUARTByte(uart_port1);

        if (input == 0x0d || input == 0x0a)
            break;

        if (input == ESCKEY)
            return;

        str[offset++] = input;
        dbg_print("%c", input);
    }

    str[offset] = 0;

    dbg_print("\r\n");
    sscanf(str, "%d", value);
}



