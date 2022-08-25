//#include "gpt_IT_test.h"

#include "kal_release.h"      /* Basic data type */
#include "drv_features.h"
#include "kal_public_api.h"
#include "kal_debug.h"
//#include "syscomp_config.h"
//#include "stacklib.h"         /* Basic type for dll, evshed, stacktimer */
#include "kal_public_defs.h"
#include "string.h"
#include <stdlib.h>
#include "stdio.h"
#include "uart_sw.h"
#include "fat_fs.h"
//#include "dma_hw.h"
//#include "dma_sw.h"
#include "us_timer.h"
#include "dcl.h"
#include "dcl_gpt.h"
#include "dcl_gpt_hw.h"


/*********************************************/
//#include "stack_config.h"
//#include "task_main_func.h"
//#include "stack_ltlcom.h"
//#include "hisr_config.h"
#include "kal_internal_api.h"
//#include "stack_common.h"
//#include "stack_msgs.h"
//#include "app_ltlcom.h"
//#include "tst_ltlcom.h"
//#include "task_config.h"
//#include "event_shed.h"
//#include "stack_timer.h"
#include "drv_comm.h"
//#include "L1d_reg.h"/* required for slow Idle mode */
//#include "config_hw.h"

/**********************************************/

#define TEST_CASE_INIT_INPUT_DATA 0xFFFFFFFF
#define ESCKEY (0x1b)
#define GPT_ONE_SHOT_COUNT_DOWN_VAL 50
#define GPT_REPEAT_COUNT_DOWN_VAL 150  //150 is enough for dbg_print
#define GPT_HW_DELAY_TIME 120
#define GPT_POLLING_COUNT_VAL 200


DCL_HANDLE hGPT_Handle1,hGPT_Handle2,hGPT_Handle3;
kal_uint32 time_start,time_now;
kal_uint32 gpt4_start_time,gpt4_now_time;
kal_bool Is_Case_Running = KAL_FALSE;

typedef enum {
	GPT1_ONE_SHOT,
	GPT1_REPEAT,
	GPT2_ONE_SHOT,
	GPT2_REPEAT,
	GPT1_EXACT_TIME,
	GPT1_EXACT_TIME_REPEAT,
	GPT2_EXACT_TIME,
	GPT2_EXACT_TIME_REPEAT,
	GPT_TEST_NONE,
}GPT_TEST_MODE_STRUCT;
GPT_TEST_MODE_STRUCT Test_Mode = GPT_TEST_NONE;
extern kal_uint8 U_GetUARTByte(UART_PORT port);

extern void gpt_udvt_main_test();
void uDVT_GPT_Initialize();
void uDVT_GPT_TestCase_ONESHOT_REPEAT(DCL_EVENT gptEvent);
void uDVT_GPT_EXACT_TIME_CallBack(DCL_EVENT gptEvent);
void uDVT_GPT_EXACT_TIME_REPEAT_CallBack(DCL_EVENT gptEvent);
void uDVT_GPT_TestCase9_CallBack(DCL_EVENT gptEvent);

void gpt_udvt_testcase1();
void gpt_udvt_testcase2();
void gpt_udvt_testcase3();
void gpt_udvt_testcase4();
void gpt_udvt_testcase5();
void gpt_udvt_testcase6();
void gpt_udvt_testcase7();
void gpt_udvt_testcase8();
void gpt_udvt_testcase9();
void gpt_udvt_testcase10();
void gpt_udvt_testcase11();
void gpt_udvt_testcase12();
static void gpt_dbg_input(kal_uint32 *value);

/*************************************************************************
* FUNCTION
*  gpt_udvt_main_test
*
* DESCRIPTION
*  This function is the main entry for gpt test case
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/

void gpt_udvt_main_test()
{
	
	kal_uint32 input_data = TEST_CASE_INIT_INPUT_DATA;
	uDVT_GPT_Initialize();

	while(1)
	{
		if(!Is_Case_Running)
		{
			dbg_print("***********************************************************\r\n");
			dbg_print("*****************GPT UDVT Test Begin***********************\r\n");
			dbg_print("***********************************************************\r\n");
			dbg_print("        number0: choice again\r\n");
			dbg_print("        number1: Case1-- gtp1 one shot\r\n");
			dbg_print("        number2: Case2-- gpt1 repeat mode\r\n");
			dbg_print("        number3: Case3-- gtp2 one shot\r\n");
			dbg_print("        number4: Case4-- gpt2 repeat mode\r\n");
			dbg_print("        number5: Case5-- gpt1 time out accuracy in oneshot mode\r\n");
			dbg_print("        number6: Case6-- gpt2 time out accuracy in oneshot mode\r\n");
			dbg_print("        number7: Case7-- gpt1 time out accuracy in repeat mode\r\n");
			dbg_print("        number8: Case8-- gpt2 time out accuracy in repeat mode\r\n");
			dbg_print("        number9: Case9-- gpt4,no lock,enable/reset bit test\r\n");
			dbg_print("        number10: Case10-- gpt4. enable=1,lock=1.\r\n");
			dbg_print("        number11: Case11-- check gpt4 counter is accuracy with 32k/gpt1\r\n");
			dbg_print("        number12: Case12-- gpt3 check if continuously increasly.\r\n");
			dbg_print("***********************************************************\r\n");

			gpt_dbg_input(&input_data);
			dbg_print("\r\n");
			
			switch (input_data)
			{
				case 1:
				{
					gpt_udvt_testcase1();//gtp1 one shot
					break;
				}
				case 2:
				{
					gpt_udvt_testcase2();//gpt1 repeat mode
					break;
				}
				case 3:
				{
					gpt_udvt_testcase3();//gpt2 oneshot
					break;
				}
				case 4:
				{
					gpt_udvt_testcase4();//gpt2 repeat mode
					break;
				}
				case 5:
				{
					gpt_udvt_testcase5();//gpt1 time up after expected time period with onshot
					break;
				}
				case 6:
				{
					gpt_udvt_testcase6();//gpt2 time up after expected time period with one shot
					break;
				}
				
				case 7:
				{
					gpt_udvt_testcase7();//gpt2 time up after expected time period with repeat
					break;
				}
				
				case 8:
				{
					gpt_udvt_testcase8();//gpt2 time up after expected time period with repeat
					break;
				}
				case 9:
				{
					gpt_udvt_testcase9();//gpt4. no lock,enable/reset  bit can start count as expected.
					break;
				}
				
				case 10:
				{
					gpt_udvt_testcase10();//gpt4. enable=1,lock=1.
					break;
				}
				case 11:
				{
					gpt_udvt_testcase11();//check gpt4 counter is accuracy with 32k/gpt1
					break;
				}
				case 12:
				{
					gpt_udvt_testcase12();//gpt3 check if continuously increasly.
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
*  gpt_udvt_testcase1
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
void gpt_udvt_testcase1()
{

	HGPT_CTRL_RESET_T	prReset;
	HGPT_CTRL_CLK_T   prClock;

	dbg_print("---now,start gpt test case 1---\r\n");
	Is_Case_Running = KAL_TRUE;
	Test_Mode = GPT1_ONE_SHOT;
	if (STATUS_OK != DclHGPT_RegisterCallback(hGPT_Handle1,
											  EVENT_HGPT_TIMEOUT,
											  uDVT_GPT_TestCase_ONESHOT_REPEAT))
	{
		dbg_print("Error:GPT-1 Reg Callback funtion failed\r\n");
	}
	prReset.u2CountValue = GPT_ONE_SHOT_COUNT_DOWN_VAL;
	prReset.fgAutoReload = KAL_FALSE;
	if (STATUS_OK != DclHGPT_Control(hGPT_Handle1,HGPT_CMD_RESET,(HGPT_CTRL *)&prReset))
	{
		dbg_print("Error: GPT-1 RESET command failed\r\n");
	}
	
	prClock.u4Clock = CLK_16K;
	if (STATUS_OK != DclHGPT_Control(hGPT_Handle1,HGPT_CMD_CLK,(HGPT_CTRL *)&prClock))
	{
		dbg_print("Error: GPT-1 SET clock command failed\r\n ");
	}

	if(STATUS_OK != DclHGPT_Control(hGPT_Handle1,HGPT_CMD_START,0))
	{
		dbg_print("Error: GPT-1 SET start command failed\r\n");
	}

}

/*************************************************************************
* FUNCTION
*  gpt_udvt_testcase2
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
void gpt_udvt_testcase2()
{
		HGPT_CTRL_RESET_T	prReset;
		HGPT_CTRL_CLK_T   prClock;

		dbg_print("---now,start gpt test case 2---\r\n");
		Is_Case_Running = KAL_TRUE;
		Test_Mode = GPT1_REPEAT;
		if (STATUS_OK != DclHGPT_RegisterCallback(hGPT_Handle1,
												  EVENT_HGPT_TIMEOUT,
												  uDVT_GPT_TestCase_ONESHOT_REPEAT))
		{
			dbg_print("Error:GPT-1 Reg Callback funtion failed\r\n");
		}
		prReset.u2CountValue = GPT_REPEAT_COUNT_DOWN_VAL;
		prReset.fgAutoReload = KAL_TRUE;
		if (STATUS_OK != DclHGPT_Control(hGPT_Handle1,HGPT_CMD_RESET,(HGPT_CTRL*)&prReset))
		{
			dbg_print("Error: GPT-1 RESET command failed\r\n");
		}
		
		prClock.u4Clock = CLK_16K;
		if (STATUS_OK != DclHGPT_Control(hGPT_Handle1,HGPT_CMD_CLK,(HGPT_CTRL *)&prClock))
		{
			dbg_print("Error: GPT-1 SET clock command failed \r\n");
		}
	
		if(STATUS_OK != DclHGPT_Control(hGPT_Handle1,HGPT_CMD_START,0))
		{
			dbg_print("Error: GPT-1 SET start command failed \r\n");
		}
}
/*************************************************************************
* FUNCTION
*  gpt_udvt_testcase3
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
void gpt_udvt_testcase3()
{

	HGPT_CTRL_RESET_T	prReset;
	HGPT_CTRL_CLK_T   prClock;

	dbg_print("---now,start gpt test case 3---\r\n");
	Is_Case_Running = KAL_TRUE;
	Test_Mode = GPT2_ONE_SHOT;
	if (STATUS_OK != DclHGPT_RegisterCallback(hGPT_Handle2,
											  EVENT_HGPT_TIMEOUT,
											  uDVT_GPT_TestCase_ONESHOT_REPEAT))
	{
		dbg_print("Error:GPT-1 Reg Callback funtion failed\r\n");
	}
	prReset.u2CountValue = GPT_ONE_SHOT_COUNT_DOWN_VAL;
	prReset.fgAutoReload = KAL_FALSE;
	if (STATUS_OK != DclHGPT_Control(hGPT_Handle2,HGPT_CMD_RESET,(HGPT_CTRL *)&prReset))
	{
		dbg_print("Error: GPT-1 RESET command failed\r\n");
	}
	
	prClock.u4Clock = CLK_16K;
	if (STATUS_OK != DclHGPT_Control(hGPT_Handle2,HGPT_CMD_CLK,(HGPT_CTRL *)&prClock))
	{
		dbg_print("Error: GPT-1 SET clock command failed\r\n ");
	}

	if(STATUS_OK != DclHGPT_Control(hGPT_Handle2,HGPT_CMD_START,0))
	{
		dbg_print("Error: GPT-1 SET start command failed\r\n");
	}
}

/*************************************************************************
* FUNCTION
*  gpt_udvt_testcase4
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
void gpt_udvt_testcase4()
{
		HGPT_CTRL_RESET_T	prReset;
		HGPT_CTRL_CLK_T   prClock;

		dbg_print("---now,start gpt test case 4---\r\n");
		Is_Case_Running = KAL_TRUE;
		Test_Mode = GPT2_REPEAT;
		if (STATUS_OK != DclHGPT_RegisterCallback(hGPT_Handle2,
												  EVENT_HGPT_TIMEOUT,
												  uDVT_GPT_TestCase_ONESHOT_REPEAT))
		{
			dbg_print("Error:GPT-1 Reg Callback funtion failed\r\n");
		}
		prReset.u2CountValue = GPT_REPEAT_COUNT_DOWN_VAL;
		prReset.fgAutoReload = KAL_TRUE;
		if (STATUS_OK != DclHGPT_Control(hGPT_Handle2,HGPT_CMD_RESET,(HGPT_CTRL*)&prReset))
		{
			dbg_print("Error: GPT-1 RESET command failed\r\n");
		}
		
		prClock.u4Clock = CLK_16K;
		if (STATUS_OK != DclHGPT_Control(hGPT_Handle2,HGPT_CMD_CLK,(HGPT_CTRL *)&prClock))
		{
			dbg_print("Error: GPT-1 SET clock command failed \r\n");
		}
	
		if(STATUS_OK != DclHGPT_Control(hGPT_Handle1,HGPT_CMD_START,0))
		{
			dbg_print("Error: GPT-1 SET start command failed \r\n");
		}
}

/*************************************************************************
* FUNCTION
*  gpt_udvt_testcase5
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
void gpt_udvt_testcase5()
{
		HGPT_CTRL_RESET_T	prReset;
		HGPT_CTRL_CLK_T   prClock;

		dbg_print("---now,start gpt test case 5---\r\n");
		Is_Case_Running = KAL_TRUE;
		Test_Mode = GPT1_EXACT_TIME;
		if (STATUS_OK != DclHGPT_RegisterCallback(hGPT_Handle1,
												  EVENT_HGPT_TIMEOUT,
												  uDVT_GPT_EXACT_TIME_CallBack))
		{
			dbg_print("Error:GPT-1 Reg Callback funtion failed\r\n");
		}
		prReset.u2CountValue = GPT_ONE_SHOT_COUNT_DOWN_VAL;
		prReset.fgAutoReload = KAL_FALSE;
		if (STATUS_OK != DclHGPT_Control(hGPT_Handle1,HGPT_CMD_RESET,(HGPT_CTRL*)&prReset))
		{
			dbg_print("Error: GPT-1 RESET command failed\r\n");
		}
		
		prClock.u4Clock = CLK_16K;
		if (STATUS_OK != DclHGPT_Control(hGPT_Handle1,HGPT_CMD_CLK,(HGPT_CTRL *)&prClock))
		{
			dbg_print("Error: GPT-1 SET clock command failed \r\n");
		}
	
		if(STATUS_OK != DclHGPT_Control(hGPT_Handle1,HGPT_CMD_START,0))
		{
			dbg_print("Error: GPT-1 SET start command failed \r\n");
		}
		time_start = drv_get_current_time();
}


/*************************************************************************
* FUNCTION
*  gpt_udvt_testcase6
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
void gpt_udvt_testcase6()
{
		HGPT_CTRL_RESET_T	prReset;
		HGPT_CTRL_CLK_T   prClock;

		dbg_print("---now,start gpt test case 6---\r\n");
		Is_Case_Running = KAL_TRUE;
		Test_Mode = GPT2_EXACT_TIME;
		if (STATUS_OK != DclHGPT_RegisterCallback(hGPT_Handle2,
												  EVENT_HGPT_TIMEOUT,
												  uDVT_GPT_EXACT_TIME_CallBack))
		{
			dbg_print("Error:GPT-2 Reg Callback funtion failed\r\n");
		}
		prReset.u2CountValue = GPT_ONE_SHOT_COUNT_DOWN_VAL;
		prReset.fgAutoReload = KAL_FALSE;
		if (STATUS_OK != DclHGPT_Control(hGPT_Handle2,HGPT_CMD_RESET,(HGPT_CTRL*)&prReset))
		{
			dbg_print("Error: GPT-2 RESET command failed\r\n");
		}
		
		prClock.u4Clock = CLK_16K;
		if (STATUS_OK != DclHGPT_Control(hGPT_Handle2,HGPT_CMD_CLK,(HGPT_CTRL *)&prClock))
		{
			dbg_print("Error: GPT-2 SET clock command failed \r\n");
		}
	
		if(STATUS_OK != DclHGPT_Control(hGPT_Handle2,HGPT_CMD_START,0))
		{
			dbg_print("Error: GPT-2 SET start command failed \r\n");
		}
		time_start = drv_get_current_time();
}
/*************************************************************************
* FUNCTION
*  gpt_udvt_testcase7
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
void gpt_udvt_testcase7()
{
		HGPT_CTRL_RESET_T	prReset;
		HGPT_CTRL_CLK_T   prClock;

		dbg_print("---now,start gpt test case 7---\r\n");
		Is_Case_Running = KAL_TRUE;
		Test_Mode = GPT1_EXACT_TIME_REPEAT;
		if (STATUS_OK != DclHGPT_RegisterCallback(hGPT_Handle1,
												  EVENT_HGPT_TIMEOUT,
												  uDVT_GPT_EXACT_TIME_REPEAT_CallBack))
		{
			dbg_print("Error:GPT-2 Reg Callback funtion failed\r\n");
		}
		prReset.u2CountValue = GPT_REPEAT_COUNT_DOWN_VAL;
		prReset.fgAutoReload = KAL_TRUE;
		if (STATUS_OK != DclHGPT_Control(hGPT_Handle1,HGPT_CMD_RESET,(HGPT_CTRL*)&prReset))
		{
			dbg_print("Error: GPT-2 RESET command failed\r\n");
		}
		
		prClock.u4Clock = CLK_16K;
		if (STATUS_OK != DclHGPT_Control(hGPT_Handle1,HGPT_CMD_CLK,(HGPT_CTRL *)&prClock))
		{
			dbg_print("Error: GPT-2 SET clock command failed \r\n");
		}
	
		if(STATUS_OK != DclHGPT_Control(hGPT_Handle1,HGPT_CMD_START,0))
		{
			dbg_print("Error: GPT-2 SET start command failed \r\n");
		}
		time_start = drv_get_current_time();
}


/*************************************************************************
* FUNCTION
*  gpt_udvt_testcase8
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
void gpt_udvt_testcase8()
{
		HGPT_CTRL_RESET_T	prReset;
		HGPT_CTRL_CLK_T   prClock;

		dbg_print("---now,start gpt test case 8 ---\r\n");
		Is_Case_Running = KAL_TRUE;
		Test_Mode = GPT2_EXACT_TIME_REPEAT;
		if (STATUS_OK != DclHGPT_RegisterCallback(hGPT_Handle2,
												  EVENT_HGPT_TIMEOUT,
												  uDVT_GPT_EXACT_TIME_REPEAT_CallBack))
		{
			dbg_print("Error:GPT-2 Reg Callback funtion failed\r\n");
		}
		prReset.u2CountValue = GPT_REPEAT_COUNT_DOWN_VAL;
		prReset.fgAutoReload = KAL_TRUE;
		if (STATUS_OK != DclHGPT_Control(hGPT_Handle2,HGPT_CMD_RESET,(HGPT_CTRL*)&prReset))
		{
			dbg_print("Error: GPT-2 RESET command failed\r\n");
		}
		
		prClock.u4Clock = CLK_16K;
		if (STATUS_OK != DclHGPT_Control(hGPT_Handle2,HGPT_CMD_CLK,(HGPT_CTRL *)&prClock))
		{
			dbg_print("Error: GPT-2 SET clock command failed \r\n");
		}
	
		if(STATUS_OK != DclHGPT_Control(hGPT_Handle2,HGPT_CMD_START,0))
		{
			dbg_print("Error: GPT-2 SET start command failed \r\n");
		}
		time_start = drv_get_current_time();
}


/*************************************************************************
* FUNCTION
*  gpt_udvt_testcase9
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
void gpt_udvt_testcase9()
{
	kal_uint32 i;

	dbg_print("---now,start gpt test case 9---\r\n");
	Is_Case_Running = KAL_TRUE;
	*((volatile kal_uint32 *)(GPT_base + 0x0028)) = 0x00;//no lock,disable gpt4
	ust_busy_wait(GPT_HW_DELAY_TIME);
	*((volatile kal_uint32 *)(GPT_base + 0x0028)) = 0x01;//no lock,enable gpt4
	for(i = 0; i < GPT_POLLING_COUNT_VAL; i++)
	{
		dbg_print("GPT4 Register Count Is : %d \r\n",*((volatile kal_uint32 *)(GPT_base + 0x002C)));
	}
	
	*((volatile kal_uint32 *)(GPT_base + 0x0028)) = 0x00;//no lock,disable gpt4
	dbg_print("gpt4 is disabbd\r\n");
	ust_busy_wait(GPT_HW_DELAY_TIME);
	dbg_print("gpt4 is enabled\r\n");
	*((volatile kal_uint32 *)(GPT_base + 0x0028)) = 0x01;//no lock,enable gpt4
	for(i = 0; i < GPT_POLLING_COUNT_VAL; i++)
	{
		dbg_print("GPT4 Register Count Is : %d \r\n",*((volatile kal_uint32 *)(GPT_base + 0x002C)));
	}
	Is_Case_Running = KAL_FALSE;
}
/*************************************************************************
* FUNCTION
*  gpt_udvt_testcase10
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
void gpt_udvt_testcase10()
{
	kal_uint32 i;

	dbg_print("---now,start gpt test case 10---\r\n");
	Is_Case_Running = KAL_TRUE;
	*((volatile kal_uint32 *)(GPT_base + 0x0028)) = 0x00;//no lock,disable gpt4
	ust_busy_wait(GPT_HW_DELAY_TIME);
	*((volatile kal_uint32 *)(GPT_base + 0x0028)) = 0x01;//no lock,enable gpt4
	for(i = 0; i < GPT_POLLING_COUNT_VAL; i++)
	{
		dbg_print("GPT4 Register Count Is : %d \r\n",*((volatile kal_uint32 *)(GPT_base + 0x002C)));
	}
	
	dbg_print("gpt4 is locked\r\n");
	*((volatile kal_uint32 *)(GPT_base + 0x0028)) = 0x03;//lock,enable gpt4.note: once it is locked, it can not be unlocked until hw reset.
	for(i = 0; i < GPT_POLLING_COUNT_VAL; i++)
	{
		dbg_print("GPT4 Register Count Is : %d \r\n",*((volatile kal_uint32 *)(GPT_base + 0x002C)));
	}
	dbg_print("now ,try to stop gpt4 when it locked\r\n");
	*((volatile kal_uint32 *)(GPT_base + 0x0028)) = 0x02;//lock,disable gpt4
	
	for(i = 0; i < GPT_POLLING_COUNT_VAL; i++)
	{
		dbg_print("GPT4 Register Count Is : %d \r\n",*((volatile kal_uint32 *)(GPT_base + 0x002C)));
	}
	dbg_print("now ,unlock gpt4 and start it\r\n");
	*((volatile kal_uint32 *)(GPT_base + 0x0028)) = 0x00;//no lock,disable gpt4
	ust_busy_wait(GPT_HW_DELAY_TIME);
	*((volatile kal_uint32 *)(GPT_base + 0x0028)) = 0x01;//no lock,enable gpt4
	//*((volatile kal_uint32 *)(GPT_base + 0x0028)) = 0x01;//lock,enable gpt4
	for(i = 0; i < GPT_POLLING_COUNT_VAL; i++)
	{
		dbg_print("GPT4 Register Count Is : %d \r\n",*((volatile kal_uint32 *)(GPT_base + 0x002C)));
	}
	
	Is_Case_Running = KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*  gpt_udvt_testcase11
*
* DESCRIPTION
*  This function is for testcase 11
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
*************************************************************************/
void gpt_udvt_testcase11()
{
	HGPT_CTRL_RESET_T	prReset;
	HGPT_CTRL_CLK_T   prClock;

	dbg_print("---now,start gpt test case 11--- \r\n");
	Is_Case_Running = KAL_TRUE;
	*((volatile kal_uint32 *)(GPT_base + 0x0028)) = 0x01;//no lock,enable gpt4

	if (STATUS_OK != DclHGPT_RegisterCallback(hGPT_Handle1,
											  EVENT_HGPT_TIMEOUT,
											  uDVT_GPT_TestCase9_CallBack))
	{
		dbg_print("Error:GPT-1 Reg Callback funtion failed\r\n");
	}
	prClock.u4Clock = CLK_16K;
	if (STATUS_OK != DclHGPT_Control(hGPT_Handle1,HGPT_CMD_CLK,(HGPT_CTRL *)&prClock))
	{
		dbg_print("Error: GPT-1 SET clock command failed\r\n ");
	}

	prReset.u2CountValue = 32768; // 2s
	prReset.fgAutoReload = KAL_FALSE;
	if (STATUS_OK != DclHGPT_Control(hGPT_Handle1,HGPT_CMD_RESET,(HGPT_CTRL*)&prReset))
	{
		dbg_print("Error: GPT-1 RESET command failed\r\n");
	}
	
	if(STATUS_OK != DclHGPT_Control(hGPT_Handle1,HGPT_CMD_START,0))
	{
		dbg_print("Error: GPT-1 SET start command failed\r\n");
	}
	gpt4_start_time = *((volatile kal_uint32 *)(GPT_base + 0x002C));
}

/*************************************************************************
* FUNCTION
*  gpt_udvt_testcase12
*
* DESCRIPTION
*  This function is for testcase 12
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
void gpt_udvt_testcase12()
{
	kal_uint32 i;

	dbg_print("---now,start gpt test case 12---\r\n");
	Is_Case_Running = KAL_TRUE;
	*((volatile kal_uint32 *)(GPT_base + 0x001C)) = 0x01;//enable gpt3
	for(i = 0; i < GPT_POLLING_COUNT_VAL; i++)
	{
		dbg_print("GPT3 Register Count Is : %d \r\n",*((volatile kal_uint32 *)(GPT_base + 0x0020)));
	}
	
	Is_Case_Running = KAL_FALSE;
	
}

/*************************************************************************
* FUNCTION
*  uDVT_GPT_Initialize
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
void uDVT_GPT_Initialize()
{
            if (STATUS_OK != DclHGPT_Initialize())
            {
                dbg_print("Error: GPT Initialization Failed\r\n");
            }
            /* Open Hanle for GPT-1 */
            hGPT_Handle1 = DclHGPT_Open(GPT1, FLAGS_NONE);
            if (hGPT_Handle1 == DCL_HANDLE_INVALID)
            {
                dbg_print("Error: GPT-1 handle invalid\r\n");
            }
            /* Open Hanle for GPT-2 */
            hGPT_Handle2 = DclHGPT_Open(GPT2, FLAGS_NONE);
            if (hGPT_Handle2 == DCL_HANDLE_INVALID)
            {
                dbg_print("Error: GPT-2 handle invalid\r\n");
            }

            /* Iinitialize Free running timer */
            if (STATUS_OK != DclFGPT_Initialize())
            {
                dbg_print("Error: GPT Initialization Failed\r\n");
            }

            /* Opend handle for FGPT */
            hGPT_Handle3 = DclFGPT_Open(DCL_GPT_FreeRUN3, FLAGS_NONE);
            if (hGPT_Handle3 == DCL_HANDLE_INVALID)
            {
                dbg_print(" Error: GPT-3 handle invalid\r\n");
            }


            dbg_print("*** Initialization Done ***\r\n");


}


/*************************************************************************
* FUNCTION
*  uDVT_GPT_TestCase_ONESHOT_REPEAT
*
* DESCRIPTION
*  This is for test case1,case2,case3 and case4 to test one shot mode and repeat mode
*  
*  
*
* PARAMETERS
*  GPT TIEMOUT EVENT
*
* RETURNS
*  None
*
*************************************************************************/
void uDVT_GPT_TestCase_ONESHOT_REPEAT(DCL_EVENT gptEvent)
{
	//kal_uint8 i;
	DCL_UINT32 handle = 0;
	static kal_uint8 temp_count = 0;
	HGPT_CTRL_RESET_T	prReset;
	HGPT_CTRL_CLK_T   prClock;
	kal_uint8 temp_clk = 0;
	static kal_uint8 success_count = 0;
		dbg_print("\r\n");
	if(Test_Mode == GPT1_ONE_SHOT)
		{
		handle = hGPT_Handle1;
		dbg_print("gpt1 prescal test oneshot mode success times: %d  \r\n",success_count++);
		}
	else if(Test_Mode == GPT1_REPEAT)
		{
		handle = hGPT_Handle1;
		dbg_print("gpt1 prescal test repeat mode success times: %d  \r\n",success_count++);
		}
	else if(Test_Mode == GPT2_ONE_SHOT)
		{
		handle = hGPT_Handle2;
		dbg_print("gpt2 prescal test oneshot mode success times: %d  \r\n",success_count++);
		}
	else if(Test_Mode == GPT2_REPEAT)
		{
		handle = hGPT_Handle2;
		dbg_print("gpt2 prescal test repeat mode success times: %d  \r\n",success_count++);
		}
	else
		{
		dbg_print("error,no test  \r\n");
		}
		switch(temp_count)
		{
			case 0:
			{
				temp_clk = CLK_16K;
				
				break;
			}
			
			case 1:
			{
				temp_clk = CLK_8K;
				
				break;
			}
			
			case 2:
			{
				temp_clk = CLK_4K;
				
				break;
			}
			case 3:
			{
				temp_clk = CLK_2K;
				
				break;
			}
			case 4:
			{
				temp_clk = CLK_1K;
				
				break;
			}
			case 5:
			{
				temp_clk = CLK_500;
				
				break;
			}
			case 6:
			{
				temp_clk = CLK_250;
				
				break;
			}
			case 7:
			{
				temp_clk = CLK_125;
				
				break;
			}
			default:
			{
				break;
			}
			
		}
if(Test_Mode == GPT1_ONE_SHOT || Test_Mode == GPT2_ONE_SHOT)
{
		if(temp_count != 8)
		{
			prClock.u4Clock = temp_clk;
			if (STATUS_OK != DclHGPT_Control(handle,HGPT_CMD_CLK,(HGPT_CTRL *)&prClock))
			{
				dbg_print("Error: GPT-1 SET clock command failed \r\n");
			}
			
			if(STATUS_OK != DclHGPT_Control(handle,HGPT_CMD_START,0))
			{
				dbg_print("Error: GPT-1 SET start command failed \r\n");
			}
			temp_count++;
		}
		else
		{
			success_count = 0;
			temp_count = 0;
			Is_Case_Running = KAL_FALSE;
			Test_Mode = GPT_TEST_NONE;
		}
}
else if(Test_Mode == GPT1_REPEAT || Test_Mode == GPT2_REPEAT)
{
	
	if(STATUS_OK != DclHGPT_Control(hGPT_Handle1,HGPT_CMD_STOP,0))
	{
		dbg_print("Error: GPT-1 SET start command failed \r\n");
	}
	ust_busy_wait(GPT_HW_DELAY_TIME);
	
	if(temp_count != 8)
	{
		prReset.u2CountValue = GPT_REPEAT_COUNT_DOWN_VAL;
		prReset.fgAutoReload = KAL_TRUE;
		if (STATUS_OK != DclHGPT_Control(hGPT_Handle1,HGPT_CMD_RESET,(HGPT_CTRL*)&prReset))
		{
			dbg_print("Error: GPT-1 RESET command failed\r\n");
		}
		prClock.u4Clock = temp_clk;
		if (STATUS_OK != DclHGPT_Control(hGPT_Handle1,HGPT_CMD_CLK,(HGPT_CTRL *)&prClock))
		{
			dbg_print("Error: GPT-1 SET clock command failed \r\n");
		}
		
		if(STATUS_OK != DclHGPT_Control(hGPT_Handle1,HGPT_CMD_START,0))
		{
			dbg_print("Error: GPT-1 SET start command failed \r\n");
		}
		temp_count++;
	}
	else
	{
		Is_Case_Running = KAL_FALSE;
		Test_Mode = GPT_TEST_NONE;
		success_count = 0;
		temp_count = 0;
	}
}
	
}


/*************************************************************************
* FUNCTION
*  uDVT_GPT_EXACT_TIME_CallBack
*
* DESCRIPTION
*  This function is for test case5 and case6 to test gpt1 and gpt2's
*  timing accuracy
*  
*
* PARAMETERS
* GPT TIMEOUT EVENT
*
* RETURNS
*  None
*
*************************************************************************/

void uDVT_GPT_EXACT_TIME_CallBack(DCL_EVENT gptEvent)
{
	kal_uint32 time_passed;
	static kal_uint8 Is_First_Time = KAL_TRUE;
	HGPT_CTRL_RESET_T	prReset;
	HGPT_CTRL_CLK_T   prClock;
	DCL_UINT32 handle = 0;
	time_now = drv_get_current_time();
	if(time_now >= time_start)
	{
		time_passed = time_now - time_start;
	}
	else
	{
		time_passed = 0xFFFFFFFF - time_start + time_now;
	}
	if(Test_Mode == GPT1_EXACT_TIME)
	{
		if(Is_First_Time == KAL_TRUE)
			dbg_print("gpt1 time passed = %d,and the expected time is %d \r\n",time_passed,2*GPT_ONE_SHOT_COUNT_DOWN_VAL);
		else
			dbg_print("gpt1 time passed = %d,and the expected time is %d \r\n",time_passed,8*GPT_ONE_SHOT_COUNT_DOWN_VAL);
		handle = hGPT_Handle1;
	}
	else if(Test_Mode == GPT2_EXACT_TIME)
	{
		if(Is_First_Time == KAL_TRUE)
			dbg_print("gpt2 time passed = %d,and the expected time is %d \r\n",time_passed,2*GPT_ONE_SHOT_COUNT_DOWN_VAL);
		else
			dbg_print("gpt2 time passed = %d,and the expected time is %d \r\n",time_passed,8*GPT_ONE_SHOT_COUNT_DOWN_VAL);
		handle = hGPT_Handle2;
	}
	else
	{
		dbg_print("error ,no test \r\n");
	}
	if(Is_First_Time == KAL_TRUE)
	{
		Is_First_Time = KAL_FALSE;
		prReset.u2CountValue = GPT_ONE_SHOT_COUNT_DOWN_VAL;
		prReset.fgAutoReload = KAL_FALSE;
		if (STATUS_OK != DclHGPT_Control(handle,HGPT_CMD_RESET,(HGPT_CTRL*)&prReset))
		{
			dbg_print("Error: GPT-1 RESET command failed\r\n");
		}
		
		prClock.u4Clock = CLK_4K;
		if (STATUS_OK != DclHGPT_Control(handle,HGPT_CMD_CLK,(HGPT_CTRL *)&prClock))
		{
			dbg_print("Error: GPT-1 SET clock command failed \r\n");
		}
	
		if(STATUS_OK != DclHGPT_Control(handle,HGPT_CMD_START,0))
		{
			dbg_print("Error: GPT-1 SET start command failed \r\n");
		}
		time_start = drv_get_current_time();
	}
	else
	{
		Is_First_Time = KAL_TRUE;
		Is_Case_Running = KAL_FALSE;
	}
	
}
/*************************************************************************
* FUNCTION
*  uDVT_GPT_TestCase9_CallBack
*
* DESCRIPTION
* This function is for test case9 to test gpt4 timing function whether accurate or not
* 
*  
*
* PARAMETERS
*  GPT TIMEOUT EVENT
*
* RETURNS
*  None
*
*************************************************************************/

void uDVT_GPT_EXACT_TIME_REPEAT_CallBack(DCL_EVENT gptEvent)
{
	kal_uint32 time_passed;
	//static kal_uint8 Is_First_Time = KAL_TRUE;
	//HGPT_CTRL_RESET_T	prReset;
	//HGPT_CTRL_CLK_T   prClock;
	DCL_UINT32 handle = 0;
	static kal_uint8 repeat_count = 0;
	time_now = drv_get_current_time();
	if(time_now >= time_start)
	{
		time_passed = time_now - time_start;
	}
	else
	{
		time_passed = 0xFFFFFFFF - time_start + time_now;
	}
	repeat_count++;
	if(repeat_count < 3)
	{
		time_start = drv_get_current_time();// must put here , because dbg_print cost many time
	}
	
	if(Test_Mode == GPT1_EXACT_TIME_REPEAT)
	{
		dbg_print("gpt1 time passed = %d,and the expected time is %d \r\n",time_passed,2*GPT_REPEAT_COUNT_DOWN_VAL);
		handle = hGPT_Handle1;
	}
	else if(Test_Mode == GPT2_EXACT_TIME_REPEAT)
	{
		dbg_print("gpt2 time passed = %d,and the expected time is %d \r\n",time_passed,2*GPT_REPEAT_COUNT_DOWN_VAL);
		handle = hGPT_Handle2;
	}
	else
	{
		dbg_print("error ,no test \r\n");
	}
	
	if(repeat_count >= 3)
	{
		repeat_count = 0;
		Is_Case_Running = KAL_FALSE;
		if(STATUS_OK != DclHGPT_Control(handle,HGPT_CMD_STOP,0))
		{
			dbg_print("Error: GPT-1 SET start command failed \r\n");
		}
	}
	
}


/*************************************************************************
* FUNCTION
*  uDVT_GPT_TestCase9_CallBack
*
* DESCRIPTION
* This function is for test case9 to test gpt4 timing function whether accurate or not
* 
*  
*
* PARAMETERS
*  GPT TIMEOUT EVENT
*
* RETURNS
*  None
*
*************************************************************************/
void uDVT_GPT_TestCase9_CallBack(DCL_EVENT gptEvent)
{
	kal_uint32 time_passed;

	gpt4_now_time = *((volatile kal_uint32 *)(GPT_base + 0x002C));
	if(gpt4_now_time >= gpt4_start_time)
	{
		time_passed = gpt4_now_time - gpt4_start_time;
	}
	else
	{
		time_passed = 0xFFFFFFFF - gpt4_start_time + gpt4_now_time;
	}
	
	dbg_print("gpt4 time passed = %d,and the expected time is 52000000 ",time_passed);
	Is_Case_Running = KAL_FALSE;
}


/*************************************************************************
* FUNCTION
*  gpt_dbg_input
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
void gpt_dbg_input(kal_uint32 *value)
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



