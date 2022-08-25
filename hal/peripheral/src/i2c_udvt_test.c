
#include "kal_release.h"      /* Basic data type */
#include "drv_features.h"
#include "kal_public_api.h"
#include "kal_debug.h"
#include "syscomp_config.h"
#include "stacklib.h"         /* Basic type for dll, evshed, stacktimer */
#include "kal_public_defs.h"
#include "string.h"
#include <stdlib.h>
#include "stdio.h"
#include "uart_sw.h"
#include "fat_fs.h"
#include "dma_hw.h"
#include "dma_sw.h"
#include "us_timer.h"
#include "dcl.h"
#include "dcl_i2c.h"
#include "Dcl_i2c_owner.h"
#include "reg_base.h"
#include "i2c.h"
#include "dcl.h"
 
#include "dcl_gpio.h"
#include "gpio_hw.h"
 extern  i2c_status_struct  dcl_i2c_status;
kal_bool Is_Case_Running = KAL_FALSE;

extern kal_uint8 U_GetUARTByte(UART_PORT port);

/* Below vairable are for Controlling I2C */
static DCL_HANDLE  hgI2C_PS,hgI2C_EP,hgI2C_GS,hgI2C_AMS,hgI2C_Camera; /* I2C device handle , I2C gpio handle */
static DCL_CONFIGURE_T rgConfigI2C;                 /* I2C Configuration structure */
static DCL_CTRL_DATA_T rgWriteI2cCmd; /* Structure variables to Issue I2C Read  & Write commands */ 
static kal_uint8  acgPS_WriteCmdBuffer[8];
/* Below arry hold the data read from of Pressure Sensor Registers */
static kal_uint8  acgPS_ReadBuffer[10];

/*--Macos for Pressure Sensor-- */
#define PS_SLAVE_ADDR       0xEE 

/*--Macos for EEPROM-- */
#define EP_SLAVE_ADDR       0xA0 /*  assume A0, A1 and B0 equal 0 */

/*--Macos for M-sensor AMI304-- */
#define AMS_SLAVE_ADDR       0x1E 

/*--Macos for G-Sensor MMA7660-- */
#define GS_SLAVE_ADDR       0x98 

#define ESCKEY (0x1b)
extern void i2c_udvt_main_test(task_entry_struct *task_entry_ptr);
void uDVT_i2c_Initialize();
void i2c_udvt_testcase1();
void i2c_udvt_testcase2();
void i2c_udvt_testcase3();
void i2c_udvt_testcase4();
void i2c_udvt_testcase5();
void i2c_udvt_testcase6();
void i2c_udvt_testcase7();
void i2c_udvt_testcase8();
void i2c_udvt_testcase9();
void i2c_udvt_testcase10();
void ms_test_delay(kal_uint32 delay_ms);
void i2c_dbg_input(kal_uint32 *value);
void i2c_udvt_main_test(task_entry_struct *task_entry_ptr)
{
	
	kal_uint32 input_data = 0xFFFFFFFF;
	uDVT_i2c_Initialize();

	while(1)
	{
	
	if(!Is_Case_Running)
		{
		dbg_print("****************************************************\r\n");
		dbg_print("*****************I2C UDVT Test Begin******************\r\n");
		dbg_print("****************************************************\r\n");
		dbg_print("        number0: choice again\r\n");
		dbg_print("        number1: Case1-- repeat start with direction change\r\n");
		dbg_print("        number2: Case2-- i2c timing test\r\n");
		dbg_print("        number3: Case3-- continuous read/write test\r\n");
		dbg_print("        number4: Case4-- timeout test\r\n");
		dbg_print("        number5: Case5-- busbusy test\r\n");
		dbg_print("        number6: Case6-- multislave test\r\n");
		dbg_print("        number7: Case7-- clock stretching test\r\n");
		dbg_print("        number8: Case8-- Temp:gpio test\r\n");
		dbg_print("****************************************************\r\n");

		i2c_dbg_input(&input_data);

		if(input_data == 0)
		{
			continue;
		}
		
		switch (input_data)
		{
			case 1:
			{
				i2c_udvt_testcase1();//repeat start with direction change test
				break;
			}
			case 2:
			{
				i2c_udvt_testcase2();//i2c timing test
				break;
			}
			case 3:
			{
				i2c_udvt_testcase3();//continuous read/write test
				break;
			}
			case 4:
			{
				i2c_udvt_testcase4();//timeout test
				break;
			}
			case 5:
			{
				i2c_udvt_testcase5();//busbusy test
				break;
			}
			case 6:
			{
				i2c_udvt_testcase6();//multislave test
				break;
			}
			case 7:
			{
				i2c_udvt_testcase7();//clock stretching test
				break;
			}
			
			case 8:
			{
				i2c_udvt_testcase8();//clock stretching test
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

void i2c_udvt_testcase1()
{
	DCL_CTRL_DATA_T rI2dWriteNRead;    /* I2C Write&Read Structure variable for Read&Write Operation */
	//kal_bool DMA_Enable=DCL_FALSE;
		
	Is_Case_Running = KAL_TRUE;		
	
	dbg_print("...repeat start with direction change test begin...\r\n");
			
/**********************************************************************************************/
	dbg_print("first,single write test...\r\n");
	/*Fill the I2C configuration structure	*/
	rgConfigI2C.rI2CCofig.eOwner				= DCL_I2C_OWNER_GS; 	 
	rgConfigI2C.rI2CCofig.u1SlaveAddress	= GS_SLAVE_ADDR;
	rgConfigI2C.rI2CCofig.eTransactionMode = DCL_I2C_TRANSACTION_FAST_MODE; 	 
	rgConfigI2C.rI2CCofig.u4FastModeSpeed = 300;
	rgConfigI2C.rI2CCofig.u4HSModeSpeed   = 1000;  
	rgConfigI2C.rI2CCofig.u1DelayLen		  = 0;
	rgConfigI2C.rI2CCofig.fgEnableDMA = DCL_FALSE;
	/* Configure the I2C */
	if (STATUS_OK !=DclSI2C_Configure(hgI2C_GS, (DCL_CONFIGURE_T *) &rgConfigI2C))
	{
		dbg_print("Error:I2C Module Configuration for PS failed\r\n");
	}
	
	/* Fill the single Write Structure */
	acgPS_WriteCmdBuffer[0] = 0x07;
	acgPS_WriteCmdBuffer[1] = 0xA0;
	rgWriteI2cCmd.rSingleWrite.pu1Data	  = acgPS_WriteCmdBuffer;	
	rgWriteI2cCmd.rSingleWrite.u4DataLen = 2;
	/* Issue the Single Write Command*/
	if (STATUS_OK !=DclSI2C_Control(hgI2C_GS, 
									I2C_CMD_SINGLE_WRITE, 
									(DCL_CTRL_DATA_T * )&rgWriteI2cCmd))
	{
		dbg_print("Failure: Error:single write test\r\n");
	}
	else
	{
		dbg_print("Success: single write test ... \r\n");
	}
/***********************************************************************************************/			
	dbg_print("then,repeat test with fast mode speed...\r\n");
	
	/* Fill the Write&Read Structure */
	acgPS_WriteCmdBuffer[0] = 0x07;
	rI2dWriteNRead.rWriteAndRead.pu1OutData = acgPS_WriteCmdBuffer; /* temperature Register address*/
	rI2dWriteNRead.rWriteAndRead.u4OutDataLen = 1;
	acgPS_ReadBuffer[0] =0;
	rI2dWriteNRead.rWriteAndRead.pu1InData = &acgPS_ReadBuffer[0];
	rI2dWriteNRead.rWriteAndRead.u4InDataLen =1; 
	/* Issue Write&Read command */
	if (STATUS_OK !=DclSI2C_Control(hgI2C_GS, 
														 I2C_CMD_WRITE_AND_READ, 
														 (DCL_CTRL_DATA_T * )&rI2dWriteNRead))
	{
		dbg_print("Failure: repeat start with fast speed mode\r\n");
	}
	else
	{
		dbg_print("Success: repeat start with fast speed mode ... ^^ \r\n");
	}
/**********************************************************************************************************/
	dbg_print("finally, repeat start with high speed test...\r\n");
	/*Fill the I2C configuration structure	*/
	rgConfigI2C.rI2CCofig.eOwner				= DCL_I2C_OWNER_GS; 	 
	rgConfigI2C.rI2CCofig.u1SlaveAddress	= GS_SLAVE_ADDR;
	rgConfigI2C.rI2CCofig.eTransactionMode = DCL_I2C_TRANSACTION_HIGH_SPEED_MODE; 	 
	rgConfigI2C.rI2CCofig.u4FastModeSpeed = 300;
	rgConfigI2C.rI2CCofig.u4HSModeSpeed   = 1000;  
	rgConfigI2C.rI2CCofig.u1DelayLen		  = 0;
	rgConfigI2C.rI2CCofig.fgEnableDMA = DCL_FALSE;
	/* Configure the I2C */
	if (STATUS_OK !=DclSI2C_Configure(hgI2C_GS, (DCL_CONFIGURE_T *) &rgConfigI2C))
	{
		dbg_print("Error:I2C Module Configuration for PS failed\r\n");
	}
	
	/* Fill the Write&Read Structure */
	acgPS_WriteCmdBuffer[0] = 0x07;
	rI2dWriteNRead.rWriteAndRead.pu1OutData = acgPS_WriteCmdBuffer; /* temperature Register address*/
	rI2dWriteNRead.rWriteAndRead.u4OutDataLen = 1;
	acgPS_ReadBuffer[0] =0;
	rI2dWriteNRead.rWriteAndRead.pu1InData = &acgPS_ReadBuffer[0];
	rI2dWriteNRead.rWriteAndRead.u4InDataLen =1; 
	/* Issue Write&Read command */
	if (STATUS_OK !=DclSI2C_Control(hgI2C_GS, 
														 I2C_CMD_WRITE_AND_READ, 
														 (DCL_CTRL_DATA_T * )&rI2dWriteNRead))
	{
		dbg_print("Failure: repeat start with high speed mode\r\n");
	}
	else
	{
		dbg_print("Success: repeat start with high speed mode ... ^^ \r\n");
	}
/**************************************************************************************************************/
	Is_Case_Running = KAL_FALSE;		
}

void i2c_udvt_testcase2()
{
	
	//DCL_CTRL_DATA_T rI2dWriteNRead;    /* I2C Write&Read Structure variable for Read&Write Operation */
	//kal_bool DMA_Enable=DCL_FALSE;
	
	Is_Case_Running = KAL_TRUE;		
			
	dbg_print("...I2c timing test begin...\r\n");
	
/********************************************************************************************/
	dbg_print("first,set speed to 150...\r\n");
	/*Fill the I2C configuration structure	*/
	rgConfigI2C.rI2CCofig.eOwner				= DCL_I2C_OWNER_GS; 	 
	rgConfigI2C.rI2CCofig.u1SlaveAddress	= GS_SLAVE_ADDR;
	rgConfigI2C.rI2CCofig.eTransactionMode = DCL_I2C_TRANSACTION_FAST_MODE; 	 
	rgConfigI2C.rI2CCofig.u4FastModeSpeed = 150;
	rgConfigI2C.rI2CCofig.u4HSModeSpeed   = 1000;  
	rgConfigI2C.rI2CCofig.u1DelayLen		  = 0;
	rgConfigI2C.rI2CCofig.fgEnableDMA = DCL_FALSE;
	/* Configure the I2C */
	if (STATUS_OK !=DclSI2C_Configure(hgI2C_GS, (DCL_CONFIGURE_T *) &rgConfigI2C))
	{
		dbg_print("Error:I2C Module Configuration for PS failed\r\n");
	}
	
	/* Fill the single Write Structure */
	acgPS_WriteCmdBuffer[0] = 0x07;
	acgPS_WriteCmdBuffer[1] = 0xA0;
	rgWriteI2cCmd.rSingleWrite.pu1Data	  = acgPS_WriteCmdBuffer;	
	rgWriteI2cCmd.rSingleWrite.u4DataLen = 2;
	/* Issue the Single Write Command*/
	if (STATUS_OK !=DclSI2C_Control(hgI2C_GS, 
									I2C_CMD_SINGLE_WRITE, 
									(DCL_CTRL_DATA_T * )&rgWriteI2cCmd))
	{
		dbg_print("Error:I2C Module: Single Write failed\r\n");
	}
	else
	{
		dbg_print("Success: I2C Timing test with speed 150K...  ^^ \r\n");
	}
/*******************************************************************************************/
	dbg_print("then,set speed to 400...\r\n");
	/*Fill the I2C configuration structure	*/
	rgConfigI2C.rI2CCofig.eOwner				= DCL_I2C_OWNER_GS; 	 
	rgConfigI2C.rI2CCofig.u1SlaveAddress	= GS_SLAVE_ADDR;
	rgConfigI2C.rI2CCofig.eTransactionMode = DCL_I2C_TRANSACTION_FAST_MODE; 	 
	rgConfigI2C.rI2CCofig.u4FastModeSpeed = 400;
	rgConfigI2C.rI2CCofig.u4HSModeSpeed   = 1000;  
	rgConfigI2C.rI2CCofig.u1DelayLen		  = 0;
	rgConfigI2C.rI2CCofig.fgEnableDMA = DCL_FALSE;
	/* Configure the I2C */
	if (STATUS_OK !=DclSI2C_Configure(hgI2C_GS, (DCL_CONFIGURE_T *) &rgConfigI2C))
	{
		dbg_print("Error:I2C Module Configuration for PS failed\r\n");
	}
	
	/* Fill the single Write Structure */
	acgPS_WriteCmdBuffer[0] = 0x07;
	acgPS_WriteCmdBuffer[1] = 0xA0;
	rgWriteI2cCmd.rSingleWrite.pu1Data	  = acgPS_WriteCmdBuffer;	
	rgWriteI2cCmd.rSingleWrite.u4DataLen = 2;
	/* Issue the Single Write Command*/
	if (STATUS_OK !=DclSI2C_Control(hgI2C_GS, 
									I2C_CMD_SINGLE_WRITE, 
									(DCL_CTRL_DATA_T * )&rgWriteI2cCmd))
	{
		dbg_print("Failure:I2C Timing test with speed 400K\r\n");
	}
	else
	{
		dbg_print("Success: I2C Timing test with speed 400K...  ^^ \r\n");
	}
/*****************************************************************************************/
/*******************************************************************************************/
	dbg_print("finally,high speed test...\r\n");
	/*Fill the I2C configuration structure	*/
	rgConfigI2C.rI2CCofig.eOwner				= DCL_I2C_OWNER_GS; 	 
	rgConfigI2C.rI2CCofig.u1SlaveAddress	= GS_SLAVE_ADDR;
	rgConfigI2C.rI2CCofig.eTransactionMode = DCL_I2C_TRANSACTION_HIGH_SPEED_MODE; 	 
	rgConfigI2C.rI2CCofig.u4FastModeSpeed = 400;
	rgConfigI2C.rI2CCofig.u4HSModeSpeed   = 1000;  
	rgConfigI2C.rI2CCofig.u1DelayLen		  = 0;
	rgConfigI2C.rI2CCofig.fgEnableDMA = DCL_FALSE;
	/* Configure the I2C */
	if (STATUS_OK !=DclSI2C_Configure(hgI2C_GS, (DCL_CONFIGURE_T *) &rgConfigI2C))
	{
		dbg_print("Error:I2C Module Configuration for PS failed\r\n");
	}
	
	/* Fill the single Write Structure */
	acgPS_WriteCmdBuffer[0] = 0x07;
	acgPS_WriteCmdBuffer[1] = 0xA0;
	rgWriteI2cCmd.rSingleWrite.pu1Data	  = acgPS_WriteCmdBuffer;	
	rgWriteI2cCmd.rSingleWrite.u4DataLen = 2;
	/* Issue the Single Write Command*/
	if (STATUS_OK !=DclSI2C_Control(hgI2C_GS, 
									I2C_CMD_SINGLE_WRITE, 
									(DCL_CTRL_DATA_T * )&rgWriteI2cCmd))
	{
		dbg_print("Failure:I2C Timing test with high speed \r\n");
	}
	else
	{
		dbg_print("Success: I2C Timing test with high speed ...	^^ \r\n");
	}
/*****************************************************************************************/
	Is_Case_Running = KAL_FALSE; 	
	
	
}


void i2c_udvt_testcase3()
{
    DCL_CTRL_DATA_T rI2cContWrite;  /* Variable for I2C continous read operation */	
	//DCL_CTRL_DATA_T rI2dWriteNRead;    /* I2C Write&Read Structure variable for Read&Write Operation */
	//DCL_BOOL DMA_Enable=DCL_FALSE;
			
	Is_Case_Running = KAL_TRUE;	
	
	dbg_print("...continuous read/write test begin...\r\n");
/********************************************************************************************/	

	dbg_print("fisrt, fast mode test\r\n");
	/*Fill the I2C configuration structure	*/
	rgConfigI2C.rI2CCofig.eOwner				= DCL_I2C_OWNER_GS; 	 
	rgConfigI2C.rI2CCofig.u1SlaveAddress	= GS_SLAVE_ADDR;
	rgConfigI2C.rI2CCofig.eTransactionMode = DCL_I2C_TRANSACTION_FAST_MODE; 	 
	rgConfigI2C.rI2CCofig.u4FastModeSpeed = 100;
	rgConfigI2C.rI2CCofig.u4HSModeSpeed   = 1000;  
	rgConfigI2C.rI2CCofig.u1DelayLen		  = 0;
	rgConfigI2C.rI2CCofig.fgEnableDMA = DCL_FALSE;
	/* Configure the I2C */
	if (STATUS_OK !=DclSI2C_Configure(hgI2C_GS, (DCL_CONFIGURE_T *) &rgConfigI2C))
	{
		dbg_print("Error:I2C Module Configuration for PS failed\r\n");
	}
	
	acgPS_WriteCmdBuffer[0] = 0x07;
	acgPS_WriteCmdBuffer[1] = 0xA0;

	/* Fill the i2C single write structure */
	rI2cContWrite.rContWrite.pu1Data = acgPS_WriteCmdBuffer; /* Address of buffer */
	rI2cContWrite.rContWrite.u4DataLen = 1; 
	rI2cContWrite.rContWrite.u4TransferNum = 2;
	/* Issue the Read command */
	if (STATUS_OK !=DclSI2C_Control(hgI2C_GS, 
														I2C_CMD_CONT_WRITE, 
														(DCL_CTRL_DATA_T * )&rI2cContWrite))
	{
		 dbg_print("Failure: continuous read/write with fast speed\r\n");
	}	
	else
	{
		dbg_print("Success: continuous read/write with fast speed...^^ \r\n");
	}
/********************************************************************************************************/
	
	dbg_print("finally, high speed mode test\r\n");
	/*Fill the I2C configuration structure	*/
	rgConfigI2C.rI2CCofig.eOwner				= DCL_I2C_OWNER_GS; 	 
	rgConfigI2C.rI2CCofig.u1SlaveAddress	= GS_SLAVE_ADDR;
	rgConfigI2C.rI2CCofig.eTransactionMode = DCL_I2C_TRANSACTION_HIGH_SPEED_MODE; 	 
	rgConfigI2C.rI2CCofig.u4FastModeSpeed = 100;
	rgConfigI2C.rI2CCofig.u4HSModeSpeed   = 1000;  
	rgConfigI2C.rI2CCofig.u1DelayLen		  = 0;
	rgConfigI2C.rI2CCofig.fgEnableDMA = DCL_FALSE;
	/* Configure the I2C */
	if (STATUS_OK !=DclSI2C_Configure(hgI2C_GS, (DCL_CONFIGURE_T *) &rgConfigI2C))
	{
		dbg_print("Error:I2C Module Configuration for PS failed\r\n");
	}
	
	acgPS_WriteCmdBuffer[0] = 0x07;
	acgPS_WriteCmdBuffer[1] = 0xA0;

	/* Fill the i2C single write structure */
	rI2cContWrite.rContWrite.pu1Data = acgPS_WriteCmdBuffer; /* Address of buffer */
	rI2cContWrite.rContWrite.u4DataLen = 1; 
	rI2cContWrite.rContWrite.u4TransferNum = 2;
	/* Issue the Read command */
	if (STATUS_OK !=DclSI2C_Control(hgI2C_GS, 
														I2C_CMD_CONT_WRITE, 
														(DCL_CTRL_DATA_T * )&rI2cContWrite))
	{
		 dbg_print("Failure: continuous read/write with high speed\r\n");
	}	
	else
	{
		dbg_print("Success: continuous read/write with high speed...^^ \r\n");
	}
/********************************************************************************************************/

	
	Is_Case_Running = KAL_FALSE;	

}

void i2c_udvt_testcase4()
{
	kal_uint8 temp_ReadBuffer;
	
	DCL_CTRL_DATA_T rI2dWriteNRead;    /* I2C Write&Read Structure variable for Read&Write Operation */
	//kal_uint16 sta;
	//kal_uint32 savedMask;
	Is_Case_Running = KAL_TRUE;	

	
	dbg_print("...timeout test begin...\r\n");
/*************************************************************************************************/
	rgConfigI2C.rI2CCofig.eOwner= DCL_I2C_OWNER_GS; 	 
	rgConfigI2C.rI2CCofig.u1SlaveAddress = GS_SLAVE_ADDR;

	rgConfigI2C.rI2CCofig.eTransactionMode = DCL_I2C_TRANSACTION_FAST_MODE;
	rgConfigI2C.rI2CCofig.u4FastModeSpeed = 100;			 
	rgConfigI2C.rI2CCofig.u4HSModeSpeed = 1000;  
	rgConfigI2C.rI2CCofig.u1DelayLen		= 0;
	rgConfigI2C.rI2CCofig.fgEnableDMA	   = DCL_FALSE;
	/* Configure I2C */
	if (STATUS_OK !=DclSI2C_Configure(hgI2C_GS, (DCL_CONFIGURE_T *) &rgConfigI2C))
	{
		dbg_print("Error:I2C Module Configuration for PS failed\r\n");
	}	
						
	DRV_I2C_SetBits16(REG_I2C_INT_MASK,0x10);//unmask timeout interrupt
	DRV_I2C_SetBits16(REG_I2C_CONTROL,0x100);//ENABLE_I2C_TIMEOUT;
	DRV_I2C_WriteReg16(REG_I2C_TIMEOUT_TIMING,1000);//
	DRV_I2C_SetBits16(REG_I2C_INT_STA,0x10);//clear time out status.
	SET_I2C_SCL_WIRED_AND_MODE;
	SET_I2C_SDA_WIRED_AND_MODE;
	DRV_I2C_SetBits16(REG_I2C_IO_CONFIG, 0x4);
	ENABLE_I2C_CLOCK_EXTENSION;
	acgPS_WriteCmdBuffer[0] = 0xB2;
	rI2dWriteNRead.rWriteAndRead.pu1OutData = acgPS_WriteCmdBuffer; 
	rI2dWriteNRead.rWriteAndRead.u4OutDataLen=1;
	temp_ReadBuffer=0;
	rI2dWriteNRead.rWriteAndRead.pu1InData= &temp_ReadBuffer;
	rI2dWriteNRead.rWriteAndRead.u4InDataLen=1;
	
	if (STATUS_ERROR_TIMEOUT != DclSI2C_Control(hgI2C_GS, I2C_CMD_WRITE_AND_READ, (DCL_CTRL_DATA_T * )&rI2dWriteNRead))
	{
		dbg_print("Failure: timeout test\r\n");
	}
	else
	{
		dbg_print("Success: timeout test... ^^ \r\n"); 	
	}
/********************************************************************************************************/	
	
	Is_Case_Running = KAL_FALSE;	
}
void i2c_udvt_testcase5()
{
	
	kal_uint32 savedMask;
	kal_uint16 sta;
	
	//DCL_CTRL_DATA_T rI2dWriteNRead;    /* I2C Write&Read Structure variable for Read&Write Operation */

	
	Is_Case_Running = KAL_TRUE;	
	dbg_print("...busbusy test begin...\r\n");
/*********************************************************************************************************/
	 /* Fill the I2C configuration structure */
	rgConfigI2C.rI2CCofig.eOwner= DCL_I2C_OWNER_GS; 	 
	rgConfigI2C.rI2CCofig.u1SlaveAddress = GS_SLAVE_ADDR;
	rgConfigI2C.rI2CCofig.eTransactionMode = DCL_I2C_TRANSACTION_FAST_MODE;
	rgConfigI2C.rI2CCofig.u4FastModeSpeed = 100;
	rgConfigI2C.rI2CCofig.u4HSModeSpeed = 1000;  
	rgConfigI2C.rI2CCofig.u1DelayLen =0;
	rgConfigI2C.rI2CCofig.fgEnableDMA = DCL_FALSE;
	 /* Configure the I2C */
	if (STATUS_OK !=DclSI2C_Configure(hgI2C_GS, (DCL_CONFIGURE_T *) &rgConfigI2C))
	{
		dbg_print("Error:I2C Module Configuration for PS failed");
	}
	
   acgPS_WriteCmdBuffer[0] = 0x07;
   acgPS_ReadBuffer[0]=0;
   dcl_i2c_status.read_buffer=acgPS_ReadBuffer;

	*((volatile unsigned int *) (I2C_base + 0x44))=6;
	*((volatile unsigned int *) (I2C_base + 0x40))=7;

	ENABLE_I2C_BUS_BUSY_RESET;
	savedMask=dcl_i2c_wait_transaction_complete_and_lock(DCL_I2C_OWNER_GS);
	dcl_i2c_hw_cfg (DCL_I2C_OWNER_GS, I2C_TRANSACTION_WRITE_AND_READ, acgPS_WriteCmdBuffer, 1, acgPS_ReadBuffer, 1, 2);
	RestoreIRQMask(savedMask);
	
	sta = DRV_I2C_ReadReg16(REG_I2C_DBG_STA); 
	while((sta & 0x80) == 0) //wait until bus_busy==1
	{
		sta = DRV_I2C_ReadReg16(REG_I2C_DBG_STA);
	}
	
	RESET_I2C; // software reset
	sta = DRV_I2C_ReadReg16(REG_I2C_DBG_STA); 
	if((sta & 0x80) == 0)
		dbg_print("success test\r\n");
	else
	{
		dbg_print("Error:I2C Module: Soft reset bus_busy failed\r\n");
	}

	///soft reset may be influence the interrupt status register, result in interrupt can't be trigger.
	// so here we use delay instead of interrupt or polling.
	ms_test_delay(5);

	
	dcl_i2c_status.state=I2C_READY_STATE;
	
	DISABLE_I2C_BUS_BUSY_DET;
	DISABLE_I2C_BUS_BUSY_RESET;
	
	dbg_print("Success: busbusy test... ^^ \r\n");
/*******************************************************************************************/	
	Is_Case_Running = KAL_FALSE;	


}

void i2c_udvt_testcase6()
{
	DCL_CTRL_DATA_T rI2dWriteNRead;    /* I2C Write&Read Structure variable for Read&Write Operation */ 
	//kal_uint16 SensorId;
	//kal_uint32	outputRegVal , tmpLevel,OutputFreq;
	
		
	Is_Case_Running = KAL_TRUE;	
	dbg_print("...multislave test begin...\r\n");
/**************************************************************************************************/
	dbg_print("now,coufigure PS...\r\n");
	 /* Fill the I2C configuration structure */
	rgConfigI2C.rI2CCofig.eOwner= DCL_I2C_OWNER_PS; 	 
	rgConfigI2C.rI2CCofig.u1SlaveAddress = PS_SLAVE_ADDR;
	rgConfigI2C.rI2CCofig.eTransactionMode = DCL_I2C_TRANSACTION_FAST_MODE;
	rgConfigI2C.rI2CCofig.u4FastModeSpeed = 100;
	rgConfigI2C.rI2CCofig.u1DelayLen =0;
	rgConfigI2C.rI2CCofig.fgEnableDMA = DCL_FALSE;
	 /* Configure the I2C */
	if (STATUS_OK !=DclSI2C_Configure(hgI2C_PS, (DCL_CONFIGURE_T *) &rgConfigI2C))
	{
		dbg_print("Error:I2C Module Configuration for PS failed\r\n");
	}
	
	dbg_print("now,coufigure EEPROM...\r\n");
	// Configure slave device EEPROM 24FC1025
	
	rgConfigI2C.rI2CCofig.eOwner= DCL_I2C_OWNER_EP; 	 
	rgConfigI2C.rI2CCofig.u1SlaveAddress = EP_SLAVE_ADDR;
	rgConfigI2C.rI2CCofig.eTransactionMode = DCL_I2C_TRANSACTION_FAST_MODE;
	rgConfigI2C.rI2CCofig.u4FastModeSpeed = 100;
	rgConfigI2C.rI2CCofig.u4HSModeSpeed = 1000;
	rgConfigI2C.rI2CCofig.u1DelayLen		= 0;
	rgConfigI2C.rI2CCofig.fgEnableDMA	   = DCL_FALSE;
	// Configure I2C 
	if (STATUS_OK !=DclSI2C_Configure(hgI2C_EP, (DCL_CONFIGURE_T *) &rgConfigI2C))
	{
		dbg_print("Error:I2C Module Configuration for EP failed\r\n");
	}

	dbg_print("now,coufigure M-sensor...\r\n");
	/* Configure slave device M-sensor AMI304*/
	
	rgConfigI2C.rI2CCofig.eOwner= DCL_I2C_OWNER_AMS;	 
	rgConfigI2C.rI2CCofig.u1SlaveAddress = AMS_SLAVE_ADDR;
	rgConfigI2C.rI2CCofig.eTransactionMode = DCL_I2C_TRANSACTION_FAST_MODE;
	rgConfigI2C.rI2CCofig.u4FastModeSpeed = 100;		 
	rgConfigI2C.rI2CCofig.u1DelayLen		= 0;
	rgConfigI2C.rI2CCofig.fgEnableDMA	   = DCL_FALSE;
	/* Configure I2C */
	if (STATUS_OK !=DclSI2C_Configure(hgI2C_AMS, (DCL_CONFIGURE_T *) &rgConfigI2C))
	{
		dbg_print("Error:I2C Module Configuration for AMS failed\r\n");
	}	

	dbg_print("now,coufigure GS...\r\n");
	// Configure slave device G-Sensor MMA7660
	
	rgConfigI2C.rI2CCofig.eOwner= DCL_I2C_OWNER_GS; 	 
	rgConfigI2C.rI2CCofig.u1SlaveAddress = GS_SLAVE_ADDR;
	rgConfigI2C.rI2CCofig.eTransactionMode = DCL_I2C_TRANSACTION_FAST_MODE;
	rgConfigI2C.rI2CCofig.u4FastModeSpeed = 100;	  
	rgConfigI2C.rI2CCofig.u1DelayLen		= 0;
	rgConfigI2C.rI2CCofig.fgEnableDMA	   = DCL_FALSE;
	// Configure I2C 
	if (STATUS_OK !=DclSI2C_Configure(hgI2C_GS, (DCL_CONFIGURE_T *) &rgConfigI2C))
	{
		dbg_print("Error:I2C Module Configuration for GS failed\r\n");
	}	

   dbg_print("configure all success...\r\n");

   /********************************************************************************************/
   
   dbg_print("now, write GS...\r\n");
   //read parameter AC1, the value is 16bit pressure sensor
   acgPS_WriteCmdBuffer[0] = 0x07;
   rI2dWriteNRead.rWriteAndRead.pu1OutData = acgPS_WriteCmdBuffer; /* temperature Register address*/
   rI2dWriteNRead.rWriteAndRead.u4OutDataLen =1;
   acgPS_ReadBuffer[0] =0;
   rI2dWriteNRead.rWriteAndRead.pu1InData = acgPS_ReadBuffer;
   rI2dWriteNRead.rWriteAndRead.u4InDataLen =1;   
   /* Issue Write&Read command */
   if (STATUS_OK !=DclSI2C_Control(hgI2C_GS, 
													   I2C_CMD_WRITE_AND_READ, 
													   (DCL_CTRL_DATA_T * )&rI2dWriteNRead))
   {
	   dbg_print("Failure: write GS\r\n");
   }
	else
	{
		dbg_print("Success: write GS ... ^^\r\n");
	}

/***************************************************************************************************/
	dbg_print("now, write EEPROM...\r\n");
	//write and read EEPROM data at address 0 

	acgPS_WriteCmdBuffer[0]=0;
	acgPS_WriteCmdBuffer[1]=0;
	acgPS_WriteCmdBuffer[2]=0x5a;
	
	rgWriteI2cCmd.rSingleWrite.pu1Data = acgPS_WriteCmdBuffer;	
	rgWriteI2cCmd.rSingleWrite.u4DataLen = 3;		
	if (STATUS_OK !=DclSI2C_Control(hgI2C_EP, I2C_CMD_SINGLE_WRITE, (DCL_CTRL_DATA_T * )&rgWriteI2cCmd))
	{
		dbg_print("Error:I2C Module: Write EEPROM failed\r\n");
	}
	ms_test_delay(50); 	
	
	acgPS_ReadBuffer[0]=0;	
	rI2dWriteNRead.rWriteAndRead.pu1OutData   = acgPS_WriteCmdBuffer;
	rI2dWriteNRead.rWriteAndRead.u4OutDataLen = 2;
	rI2dWriteNRead.rWriteAndRead.pu1InData	  = acgPS_ReadBuffer;
	rI2dWriteNRead.rWriteAndRead.u4InDataLen  = 1;
	if (STATUS_OK !=DclSI2C_Control(hgI2C_EP, 
														I2C_CMD_WRITE_AND_READ, 
														(DCL_CTRL_DATA_T * )&rI2dWriteNRead))
	{
		dbg_print("Error:I2C Module: Write & Read EEPROM failed\r\n");
	}
	else
	{
		dbg_print("Success: write EEPROM ... ^^\r\n");
	}

/*******************************************************************************************************/
	dbg_print("now, GS again...\r\n");
	// write and read device reg 0x1D of G-Sensor mma7660
	acgPS_WriteCmdBuffer[0] = 0x07;
	acgPS_WriteCmdBuffer[1] = 0xA0;
	rgWriteI2cCmd.rSingleWrite.pu1Data = acgPS_WriteCmdBuffer;
	rgWriteI2cCmd.rSingleWrite.u4DataLen = 2;
	
	// Issue the Single Write Command
	 if (STATUS_OK !=DclSI2C_Control(hgI2C_GS, 
														 I2C_CMD_SINGLE_WRITE, 
														 (DCL_CTRL_DATA_T * )&rgWriteI2cCmd))
	 {
		 dbg_print("Error:I2C Module: Write MMA7660 failed\r\n");
	 }
	
	acgPS_WriteCmdBuffer[0]=0x07;
	rI2dWriteNRead.rWriteAndRead.pu1OutData   = acgPS_WriteCmdBuffer;
	rI2dWriteNRead.rWriteAndRead.u4OutDataLen = 1;
	acgPS_ReadBuffer[0]=0;
	rI2dWriteNRead.rWriteAndRead.pu1InData	  = acgPS_ReadBuffer;
	rI2dWriteNRead.rWriteAndRead.u4InDataLen  = 1;

	if (STATUS_OK !=DclSI2C_Control(hgI2C_GS, 
														 I2C_CMD_WRITE_AND_READ, 
														 (DCL_CTRL_DATA_T * )&rI2dWriteNRead))
	{
		 dbg_print("Error:I2C Module: read MMA7660 failed\r\n");
	}			
	// check if the result is 0xA0.
	if(acgPS_ReadBuffer[0] != 0xA0)
	{
		dbg_print("Error:I2C Module: read MMA7660 is not same with write data\r\n");
	}	
	else
	{
		dbg_print("Success: GS success again... ^^\r\n");
	}


/**************************************************************************************************************/
	dbg_print("Success: multislave test success ^^ \r\n");
	Is_Case_Running = KAL_FALSE;	

		
}

void i2c_udvt_testcase7()
{
	kal_uint8 temp_ReadBuffer;
	
	DCL_CTRL_DATA_T rI2dWriteNRead;    /* I2C Write&Read Structure variable for Read&Write Operation */
	//kal_uint16 sta;
	//kal_uint32 savedMask;

	
	Is_Case_Running = KAL_TRUE;	
	dbg_print("...clock stretching test begin...\r\n");
	
/***************************************************************************************************/	
	rgConfigI2C.rI2CCofig.eOwner= DCL_I2C_OWNER_GS; 	 
	rgConfigI2C.rI2CCofig.u1SlaveAddress = GS_SLAVE_ADDR;
	
	rgConfigI2C.rI2CCofig.eTransactionMode = DCL_I2C_TRANSACTION_FAST_MODE;
	rgConfigI2C.rI2CCofig.u4FastModeSpeed = 100;			 
	rgConfigI2C.rI2CCofig.u4HSModeSpeed = 1000;  
	rgConfigI2C.rI2CCofig.u1DelayLen		= 0;
	rgConfigI2C.rI2CCofig.fgEnableDMA	   = DCL_FALSE;
	/* Configure I2C */
	if (STATUS_OK !=DclSI2C_Configure(hgI2C_GS, (DCL_CONFIGURE_T *) &rgConfigI2C))
	{
		dbg_print("Error:I2C Module Configuration for PS failed\r\n");
	}	
						
	//DRV_I2C_SetBits16(REG_I2C_INT_MASK,0x10);//unmask timeout interrupt
	//DRV_I2C_SetBits16(REG_I2C_CONTROL,0x100);//ENABLE_I2C_TIMEOUT;
	//DRV_I2C_WriteReg16(REG_I2C_TIMEOUT_TIMING,1000);//
	//DRV_I2C_SetBits16(REG_I2C_INT_STA,0x10);//clear time out status.
	SET_I2C_SCL_WIRED_AND_MODE;
	SET_I2C_SDA_WIRED_AND_MODE;
	DRV_I2C_SetBits16(REG_I2C_IO_CONFIG, 0x4);
	ENABLE_I2C_CLOCK_EXTENSION;
	acgPS_WriteCmdBuffer[0] = 0x07;
	rI2dWriteNRead.rWriteAndRead.pu1OutData = acgPS_WriteCmdBuffer; 
	rI2dWriteNRead.rWriteAndRead.u4OutDataLen=1;
	temp_ReadBuffer=0;
	rI2dWriteNRead.rWriteAndRead.pu1InData= &temp_ReadBuffer;
	rI2dWriteNRead.rWriteAndRead.u4InDataLen=1;
	
	if (STATUS_ERROR_TIMEOUT != DclSI2C_Control(hgI2C_GS, I2C_CMD_WRITE_AND_READ, (DCL_CTRL_DATA_T * )&rI2dWriteNRead))
	{
		dbg_print("Failure: clock stretching test\r\n");
	}
	else
	{
		dbg_print("Success: clock stretching test... ^^ \r\n"); 			
	}
/**************************************************************************************************************************/	
	Is_Case_Running = KAL_FALSE;	
}

void i2c_udvt_testcase8()
{
}
void i2c_udvt_testcase9()
{
}
void i2c_udvt_testcase10()
{
}




void uDVT_i2c_Initialize()
{
	//set gpio2/3 to I2C mode 
	//use driver tool to set i2c mode
	 //(*(volatile kal_uint16 *)(0xA0071D00)) &= ~(0xF << 12);
	 //(*(volatile kal_uint16 *)(0xA0071D00)) |= (0x1 << 12);//gpio 55
	 //(*(volatile kal_uint16 *)(0xA0071E00)) &= ~(0xF << 0);
	 //(*(volatile kal_uint16 *)(0xA0071E00)) |= (0x1 << 0);//gpio56
	hgI2C_EP = DclSI2C_Open(DCL_I2C, DCL_I2C_OWNER_EP);
	ASSERT(hgI2C_EP != NULL);	
    hgI2C_PS = DclSI2C_Open(DCL_I2C, DCL_I2C_OWNER_PS);
	ASSERT(hgI2C_PS != NULL);		
    hgI2C_GS = DclSI2C_Open(DCL_I2C, DCL_I2C_OWNER_GS);
	ASSERT(hgI2C_GS != NULL);
	hgI2C_AMS = DclSI2C_Open(DCL_I2C, DCL_I2C_OWNER_AMS);
	ASSERT(hgI2C_AMS != NULL);
	hgI2C_Camera= DclSI2C_Open(DCL_I2C, DCL_I2C_OWNER_CAMERA);
	ASSERT(hgI2C_Camera!= NULL);

}

void ms_test_delay(kal_uint32 delay_ms)
{
	volatile kal_uint32 i;
	kal_uint32 delay_count;

#if defined(DRV_I2C_CLOCK_RATE_15_360_MHZ)
	delay_count = delay_ms * 15360;
#elif defined(DRV_I2C_CLOCK_RATE_3_000_MHZ)
	delay_count = delay_ms * 3000;

#else // #if defined(DRV_I2C_CLOCK_RATE_13_000_MHZ)
	delay_count = delay_ms * 13000;

#endif // #if defined(DRV_I2C_CLOCK_RATE_15_360_MHZ)

	
	
	for (i=0;i<delay_count;i++)
	{
		;
	}

}

void i2c_dbg_input(kal_uint32 *value)
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




