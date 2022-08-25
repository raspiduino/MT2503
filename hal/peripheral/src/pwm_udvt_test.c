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
#include "dcl_pwm.h"
#include "pwm_sw.h"
#include "intrCtrl.h"
#include "us_timer.h"
/**********************************************/


#define TEST_CASE_INIT_INPUT_DATA 0xFFFFFFFF
#define ESCKEY (0x1b)

DCL_HANDLE pwm_handle;
kal_bool Is_Case_Running = KAL_FALSE;

extern kal_uint8 U_GetUARTByte(UART_PORT port);
void uDVT_PWM_Initialize();


void pwm_udvt_testcase1();
void pwm_udvt_testcase2();
void pwm_udvt_testcase3();
void pwm_udvt_testcase4();
void pwm_udvt_testcase5();
void pwm_udvt_testcase6();
void pwm_udvt_testcase7();
void pwm_udvt_testcase8();
void pwm_udvt_testcase9();
void pwm_udvt_testcase10();
static void pwm_dbg_input(kal_uint32 *value);


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

void pwm_udvt_main_test(task_entry_struct *task_entry_ptr)
{
	kal_uint32 input_data = TEST_CASE_INIT_INPUT_DATA;
	uDVT_PWM_Initialize();

	while(1)
	{
		if(!Is_Case_Running)
		{
			dbg_print("***********************************************************\r\n");
			dbg_print("*****************PWM UDVT Test Begin***********************\r\n");
			dbg_print("***********************************************************\r\n");
			dbg_print("        number0: choice again\r\n");
			dbg_print("        number1: Case1-- PWM1 waveform at 32k test\r\n");
			dbg_print("        number2: Case2-- PWM1 waveform at 13M test\r\n");
			dbg_print("        number3: Case3-- PWM2 waveform at 32k test\r\n");
			dbg_print("        number4: Case4-- PWM2 waveform at 13M test\r\n");
			dbg_print("        number5: Case5-- PWM3 waveform at 32k test\r\n");
			dbg_print("        number6: Case6-- PWM3 waveform at 13M test\r\n");
			dbg_print("        number7: Case7-- PWM4 waveform at 32k test\r\n");
			dbg_print("        number8: Case8-- PWM4 waveform at 13M test\r\n");
			dbg_print("        number9: Case9-- PWM start/stop  test\r\n");
			dbg_print("***********************************************************\r\n");

			pwm_dbg_input(&input_data);
			dbg_print("\r\n");
			
			switch (input_data)
			{
				case 1:
				{
					pwm_udvt_testcase1();
					break;
				}
				case 2:
				{
					pwm_udvt_testcase2();
					break;
				}
				case 3:
				{
					pwm_udvt_testcase3();
					break;
				}
				case 4:
				{
					pwm_udvt_testcase4();
					break;
				}
				case 5:
				{
					pwm_udvt_testcase5();
					break;
				}
				case 6:
				{
					pwm_udvt_testcase6();
					break;
				}
				
				case 7:
				{
					pwm_udvt_testcase7();
					break;
				}
				
				case 8:
				{
					pwm_udvt_testcase8();
					break;
				}
				case 9:
				{
					pwm_udvt_testcase9();
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
void pwm_udvt_testcase1()
{
	kal_uint32 input_data = TEST_CASE_INIT_INPUT_DATA;

	
	dbg_print("1:32k,div=0,freq=32k,duty=0 \r\n");
	dbg_print("2:32k,div=0,freq=1k,duty=20 \r\n");
	dbg_print("3:32k,div=2,freq=500,duty=50 \r\n");
	dbg_print("4:32k,div=4,freq=200,duty=80 \r\n");
	dbg_print("5:32k,div=8,freq=100,duty=100 \r\n");
	
	pwm_dbg_input(&input_data);
	dbg_print("\r\n");
	
	switch (input_data)
	{
		case 1:
		{
			PWM_Init(1,pwmclk_32k,pwmclk_1MHZ); /* pwm1,32k,1div */
			PWM_Configure(32000,0,1); /* freq,duty,channel */
			PWM_Start(1);
			break;
		}
		case 2:
		{
			PWM_Init(1,pwmclk_32k,pwmclk_1MHZ); /* pwm1,32k,1div */
			PWM_Configure(1000,20,1); /* freq,duty,channel */
			PWM_Start(1);
			break;
		}
		case 3:
		{
			PWM_Init(1,pwmclk_32k,pwmclk_2MHZ); /* pwm1,32k,1div */
			PWM_Configure(500,50,1); /* freq,duty,channel */
			PWM_Start(1);
			break;
		}
		case 4:
		{
			PWM_Init(1,pwmclk_32k,pwmclk_4MHZ); /* pwm1,32k,4div */
			PWM_Configure(200,80,1); /* freq,duty,channel */
			PWM_Start(1);
			break;
		}
		case 5:
		{
			PWM_Init(1,pwmclk_32k,pwmclk_8MHZ); /* pwm1,32k,4div */
			PWM_Configure(100,100,1); /* freq,duty,channel */
			PWM_Start(1);
			break;
		}
		default:
		{
			dbg_print("wrong case number,choice again!!! \r\n");
			return;
		}
	}
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
void pwm_udvt_testcase2()
{
	kal_uint32 input_data = TEST_CASE_INIT_INPUT_DATA;

	
	dbg_print("1:13M,div=0,freq=100k,duty=0 \r\n");
	dbg_print("2:13M,div=0,freq=20k,duty=20 \r\n");
	dbg_print("3:13M,div=2,freq=500,duty=50 \r\n");
	dbg_print("4:13M,div=4,freq=200,duty=80 \r\n");
	dbg_print("5:13M,div=8,freq=100,duty=100 \r\n");
	
	pwm_dbg_input(&input_data);
	dbg_print("\r\n");
	
	switch (input_data)
	{
		case 1:
		{
			PWM_Init(1,pwmclk_13M,pwmclk_1MHZ); /* pwm1,13M,1div */
			PWM_Configure(100000,0,1); /* freq,duty,channel */
			PWM_Start(1);
			break;
		}
		case 2:
		{
			PWM_Init(1,pwmclk_13M,pwmclk_1MHZ); /* pwm1,13M,1div */
			PWM_Configure(20000,20,1); /* freq,duty,channel */
			PWM_Start(1);
			break;
		}
		case 3:
		{
			PWM_Init(1,pwmclk_13M,pwmclk_2MHZ); /* pwm1,13M,1div */
			PWM_Configure(500,50,1); /* freq,duty,channel */
			PWM_Start(1);
			break;
		}
		case 4:
		{
			PWM_Init(1,pwmclk_13M,pwmclk_4MHZ); /* pwm1,13M,4div */
			PWM_Configure(200,80,1); /* freq,duty,channel */
			PWM_Start(1);
			break;
		}
		case 5:
		{
			PWM_Init(1,pwmclk_13M,pwmclk_8MHZ); /* pwm1,13M,4div */
			PWM_Configure(100,100,1); /* freq,duty,channel */
			PWM_Start(1);
			break;
		}
		default:
		{
			dbg_print("wrong case number,choice again!!! \r\n");
			return;
		}
	}
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
void pwm_udvt_testcase3()
{
	kal_uint32 input_data = TEST_CASE_INIT_INPUT_DATA;

	
	dbg_print("1:32k,div=0,freq=32k,duty=0 \r\n");
	dbg_print("2:32k,div=0,freq=1k,duty=50 \r\n");
	dbg_print("3:32k,div=2,freq=500,duty=50 \r\n");
	dbg_print("4:32k,div=4,freq=200,duty=100 \r\n");
	dbg_print("5:32k,div=8,freq=100,duty=100 \r\n");
	
	pwm_dbg_input(&input_data);
	dbg_print("\r\n");
	
	switch (input_data)
	{
		case 1:
		{
			PWM_Init(2,pwmclk_32k,pwmclk_1MHZ); /* pwm2,32k,1div */
			PWM_Configure(32000,0,2); /* freq,duty,channel */
			PWM_Start(2);
			break;
		}
		case 2:
		{
			PWM_Init(2,pwmclk_32k,pwmclk_1MHZ); /* pwm2,32k,1div */
			PWM_Configure(1000,50,2); /* freq,duty,channel */
			PWM_Start(2);
			break;
		}
		case 3:
		{
			PWM_Init(2,pwmclk_32k,pwmclk_2MHZ); /* pwm2,32k,1div */
			PWM_Configure(500,50,2); /* freq,duty,channel */
			PWM_Start(2);
			break;
		}
		case 4:
		{
			PWM_Init(2,pwmclk_32k,pwmclk_4MHZ); /* pwm2,32k,4div */
			PWM_Configure(200,100,2); /* freq,duty,channel */
			PWM_Start(2);
			break;
		}
		case 5:
		{
			PWM_Init(2,pwmclk_32k,pwmclk_8MHZ); /* pwm2,32k,4div */
			PWM_Configure(100,100,2); /* freq,duty,channel */
			PWM_Start(2);
			break;
		}
		default:
		{
			dbg_print("wrong case number,choice again!!! \r\n");
			return;
		}
	}
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
void pwm_udvt_testcase4()
{
	kal_uint32 input_data = TEST_CASE_INIT_INPUT_DATA;

	
	dbg_print("1:13M,div=0,freq=100k,duty=0 \r\n");
	dbg_print("2:13M,div=0,freq=20k,duty=50 \r\n");
	dbg_print("3:13M,div=2,freq=500,duty=50 \r\n");
	dbg_print("4:13M,div=4,freq=200,duty=100 \r\n");
	dbg_print("5:13M,div=8,freq=100,duty=100 \r\n");
	
	pwm_dbg_input(&input_data);
	dbg_print("\r\n");
	
	switch (input_data)
	{
		case 1:
		{
			PWM_Init(2,pwmclk_13M,pwmclk_1MHZ); /* pwm2,13M,1div */
			PWM_Configure(100000,0,2); /* freq,duty,channel */
			PWM_Start(2);
			break;
		}
		case 2:
		{
			PWM_Init(2,pwmclk_13M,pwmclk_1MHZ); /* pwm2,13M,1div */
			PWM_Configure(20000,50,2); /* freq,duty,channel */
			PWM_Start(2);
			break;
		}
		case 3:
		{
			PWM_Init(2,pwmclk_13M,pwmclk_2MHZ); /* pwm2,13M,1div */
			PWM_Configure(500,50,2); /* freq,duty,channel */
			PWM_Start(2);
			break;
		}
		case 4:
		{
			PWM_Init(2,pwmclk_13M,pwmclk_4MHZ); /* pwm2,13M,4div */
			PWM_Configure(200,100,2); /* freq,duty,channel */
			PWM_Start(2);
			break;
		}
		case 5:
		{
			PWM_Init(2,pwmclk_13M,pwmclk_8MHZ); /* pwm2,13M,4div */
			PWM_Configure(100,100,2); /* freq,duty,channel */
			PWM_Start(2);
			break;
		}
		default:
		{
			dbg_print("wrong case number,choice again!!! \r\n");
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
void pwm_udvt_testcase5()
{
	kal_uint32 input_data = TEST_CASE_INIT_INPUT_DATA;

	
	dbg_print("1:32k,div=0,freq=32k,duty=0 \r\n");
	dbg_print("2:32k,div=0,freq=1k,duty=20 \r\n");
	dbg_print("3:32k,div=2,freq=500,duty=50 \r\n");
	dbg_print("4:32k,div=4,freq=200,duty=80 \r\n");
	dbg_print("5:32k,div=8,freq=100,duty=100 \r\n");
	
	pwm_dbg_input(&input_data);
	dbg_print("\r\n");
	
	switch (input_data)
	{
		case 1:
		{
			PWM_Init(3,pwmclk_32k,pwmclk_1MHZ); /* pwm3,32k,1div */
			PWM_Configure(32000,0,3); /* freq,duty,channel */
			PWM_Start(3);
			break;
		}
		case 2:
		{
			PWM_Init(3,pwmclk_32k,pwmclk_1MHZ); /* pwm3,32k,1div */
			PWM_Configure(1000,20,3); /* freq,duty,channel */
			PWM_Start(3);
			break;
		}
		case 3:
		{
			PWM_Init(3,pwmclk_32k,pwmclk_2MHZ); /* pwm3,32k,1div */
			PWM_Configure(500,50,3); /* freq,duty,channel */
			PWM_Start(3);
			break;
		}
		case 4:
		{
			PWM_Init(3,pwmclk_32k,pwmclk_4MHZ); /* pwm3,32k,4div */
			PWM_Configure(200,80,3); /* freq,duty,channel */
			PWM_Start(3);
			break;
		}
		case 5:
		{
			PWM_Init(3,pwmclk_32k,pwmclk_8MHZ); /* pwm3,32k,4div */
			PWM_Configure(100,100,3); /* freq,duty,channel */
			PWM_Start(3);
			break;
		}
		default:
		{
			dbg_print("wrong case number,choice again!!! \r\n");
			return;
		}
	}
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
void pwm_udvt_testcase6()
{
	kal_uint32 input_data = TEST_CASE_INIT_INPUT_DATA;

	
	dbg_print("1:13M,div=0,freq=100k,duty=0 \r\n");
	dbg_print("2:13M,div=0,freq=20k,duty=20 \r\n");
	dbg_print("3:13M,div=2,freq=500,duty=50 \r\n");
	dbg_print("4:13M,div=4,freq=200,duty=80 \r\n");
	dbg_print("5:13M,div=8,freq=100,duty=100 \r\n");
	
	pwm_dbg_input(&input_data);
	dbg_print("\r\n");
	
	switch (input_data)
	{
		case 1:
		{
			PWM_Init(3,pwmclk_13M,pwmclk_1MHZ); /* pwm3,13M,1div */
			PWM_Configure(100000,0,3); /* freq,duty,channel */
			PWM_Start(3);
			break;
		}
		case 2:
		{
			PWM_Init(3,pwmclk_13M,pwmclk_1MHZ); /* pwm3,13M,1div */
			PWM_Configure(20000,20,3); /* freq,duty,channel */
			PWM_Start(3);
			break;
		}
		case 3:
		{
			PWM_Init(3,pwmclk_13M,pwmclk_2MHZ); /* pwm3,13M,1div */
			PWM_Configure(500,50,3); /* freq,duty,channel */
			PWM_Start(3);
			break;
		}
		case 4:
		{
			PWM_Init(3,pwmclk_13M,pwmclk_4MHZ); /* pwm3,13M,4div */
			PWM_Configure(200,80,3); /* freq,duty,channel */
			PWM_Start(3);
			break;
		}
		case 5:
		{
			PWM_Init(3,pwmclk_13M,pwmclk_8MHZ); /* pwm3,13M,4div */
			PWM_Configure(100,100,3); /* freq,duty,channel */
			PWM_Start(3);
			break;
		}
		default:
		{
			dbg_print("wrong case number,choice again!!! \r\n");
			return;
		}
	}
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
void pwm_udvt_testcase7()
{
	kal_uint32 input_data = TEST_CASE_INIT_INPUT_DATA;

	
	dbg_print("1:32k,div=0,freq=32k,duty=0 \r\n");
	dbg_print("2:32k,div=0,freq=1k,duty=20 \r\n");
	dbg_print("3:32k,div=2,freq=500,duty=50 \r\n");
	dbg_print("4:32k,div=4,freq=200,duty=80 \r\n");
	dbg_print("5:32k,div=8,freq=100,duty=100 \r\n");
	
	pwm_dbg_input(&input_data);
	dbg_print("\r\n");
	
	switch (input_data)
	{
		case 1:
		{
			PWM_Init(4,pwmclk_32k,pwmclk_1MHZ); /* pwm4,32k,1div */
			PWM_Configure(32000,0,4); /* freq,duty,channel */
			PWM_Start(4);
			break;
		}
		case 2:
		{
			PWM_Init(4,pwmclk_32k,pwmclk_1MHZ); /* pwm4,32k,1div */
			PWM_Configure(1000,20,4); /* freq,duty,channel */
			PWM_Start(4);
			break;
		}
		case 3:
		{
			PWM_Init(4,pwmclk_32k,pwmclk_2MHZ); /* pwm4,32k,1div */
			PWM_Configure(500,50,4); /* freq,duty,channel */
			PWM_Start(4);
			break;
		}
		case 4:
		{
			PWM_Init(4,pwmclk_32k,pwmclk_4MHZ); /* pwm4,32k,4div */
			PWM_Configure(200,80,4); /* freq,duty,channel */
			PWM_Start(4);
			break;
		}
		case 5:
		{
			PWM_Init(4,pwmclk_32k,pwmclk_8MHZ); /* pwm4,32k,4div */
			PWM_Configure(100,100,4); /* freq,duty,channel */
			PWM_Start(4);
			break;
		}
		default:
		{
			dbg_print("wrong case number,choice again!!! \r\n");
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
void pwm_udvt_testcase8()
{
	kal_uint32 input_data = TEST_CASE_INIT_INPUT_DATA;

	
	dbg_print("1:13M,div=0,freq=100k,duty=0 \r\n");
	dbg_print("2:13M,div=0,freq=20k,duty=20 \r\n");
	dbg_print("3:13M,div=2,freq=500,duty=50 \r\n");
	dbg_print("4:13M,div=4,freq=200,duty=80 \r\n");
	dbg_print("5:13M,div=8,freq=100,duty=100 \r\n");
	
	pwm_dbg_input(&input_data);
	dbg_print("\r\n");
	
	switch (input_data)
	{
		case 1:
		{
			PWM_Init(4,pwmclk_13M,pwmclk_1MHZ); /* pwm4,13M,1div */
			PWM_Configure(100000,0,4); /* freq,duty,channel */
			PWM_Start(4);
			break;
		}
		case 2:
		{
			PWM_Init(4,pwmclk_13M,pwmclk_1MHZ); /* pwm4,13M,1div */
			PWM_Configure(20000,20,4); /* freq,duty,channel */
			PWM_Start(4);
			break;
		}
		case 3:
		{
			PWM_Init(4,pwmclk_13M,pwmclk_2MHZ); /* pwm4,13M,1div */
			PWM_Configure(500,50,4); /* freq,duty,channel */
			PWM_Start(4);
			break;
		}
		case 4:
		{
			PWM_Init(4,pwmclk_13M,pwmclk_4MHZ); /* pwm4,13M,4div */
			PWM_Configure(200,80,4); /* freq,duty,channel */
			PWM_Start(4);
			break;
		}
		case 5:
		{
			PWM_Init(4,pwmclk_13M,pwmclk_8MHZ); /* pwm4,13M,4div */
			PWM_Configure(100,100,4); /* freq,duty,channel */
			PWM_Start(4);
			break;
		}
		default:
		{
			dbg_print("wrong case number,choice again!!! \r\n");
			return;
		}
	}
}


void pwm_udvt_testcase9()
{
	kal_uint32 input_data = TEST_CASE_INIT_INPUT_DATA;
	dbg_print("1:PWM2 start/stop test \r\n");
	dbg_print("2:PWM3 start/stop test \r\n");
	dbg_print("3:PWM1 start/stop test \r\n");
	dbg_print("4:PWM4 start/stop test \r\n");

	
	pwm_dbg_input(&input_data);
	dbg_print("\r\n");
	
	switch (input_data)
	{
		case 1:
		{
			PWM_Init(2,pwmclk_32k,pwmclk_2MHZ); /* pwm2,32k,1div */
			PWM_Configure(500,50,2); /* freq,duty,channel */
			PWM_Start(2);
			ust_busy_wait(1000);
			PWM_Stop(2);
			ust_busy_wait(1000);
			PWM_Start(2);
			ust_busy_wait(1000);
			PWM_Stop(2);
			
			ust_busy_wait(1000);
			PWM_Start(2);

			
			break;
		}
		case 2:
		{
			PWM_Init(3,pwmclk_13M,pwmclk_2MHZ); /* pwm3,13M,1div */
			PWM_Configure(500,50,3); /* freq,duty,channel */
			PWM_Start(3);
			ust_busy_wait(1000);
			PWM_Stop(3);
			ust_busy_wait(1000);
			PWM_Start(3);
			ust_busy_wait(1000);
			PWM_Stop(3);
			ust_busy_wait(1000);
			PWM_Start(3);
			break;
		}
		
		case 3:
		{
			PWM_Init(1,pwmclk_13M,pwmclk_2MHZ); /* pwm3,13M,1div */
			PWM_Configure(500,50,1); /* freq,duty,channel */
			PWM_Start(1);
			ust_busy_wait(1000);
			PWM_Stop(1);
			ust_busy_wait(1000);
			PWM_Start(1);
			ust_busy_wait(1000);
			PWM_Stop(1);
			ust_busy_wait(1000);
			PWM_Start(1);
			break;
		}
		case 4:
		{
			PWM_Init(4,pwmclk_13M,pwmclk_2MHZ); /* pwm3,13M,1div */
			PWM_Configure(500,50,4); /* freq,duty,channel */
			PWM_Start(4);
			ust_busy_wait(1000);
			PWM_Stop(4);
			ust_busy_wait(1000);
			PWM_Start(4);
			ust_busy_wait(1000);
			PWM_Stop(4);
			ust_busy_wait(1000);
			PWM_Start(4);
			break;
		}
		default:
		{
			dbg_print("wrong case number,choice again!!! \r\n");
			return;
		}
	}
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
void uDVT_PWM_Initialize()
{
	DRV_WriteReg32(0xA0020c08,0x0F00); /* GPIO2 mode4=PWM0 */ /*set*/
	DRV_WriteReg32(0xA0020c04,0x0400); /* GPIO2 mode4=PWM0 */ /*clr*/
	DRV_WriteReg32(0xA0020c08,0xF000); /* GPIO3 mode4=PWM4 */ /*set*/
	DRV_WriteReg32(0xA0020c04,0x4000); /* GPIO3 mode4=PWM4 */ /*clr*/

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
void pwm_dbg_input(kal_uint32 *value)
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



