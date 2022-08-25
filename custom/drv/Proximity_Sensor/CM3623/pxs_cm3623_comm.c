/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   pxs_cm3623_comm.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   CM3623 proximity sensor communication interface driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(__PXS_CM3623__)
#include "kal_release.h"
#include "pxs_cm3623.h"
#include "pxs_custom.h"
#include "drv_comm.h"
#include "dcl.h"


/******************************************************************************

USE_SW_I2C/USE_HW_I2C is decided by project, each project may use different way to communicate with PXS

******************************************************************************/




//#define SW_I2C_DELAY_USE_SYS_HW_TIMER
#define SW_I2C_DELAY_SYS_HW_COUNT  1

#if !defined(SW_I2C_DELAY_USE_SYS_HW_TIMER)

// Need to tune the polling counter for each platform due to MCU speed and EMI data rate
#define SW_I2C_DELAY_USE_MCU_POLLING
#define SW_I2C_DELAY_MCU_POLLING_COUNT   250  // On 76, 296KHz

#endif // #if !defined(SW_I2C_DELAY_USE_SYS_HW_TIMER)


static DCL_HANDLE pxs_scl_gpio_dcl_handle = DCL_HANDLE_INVALID;
static DCL_HANDLE pxs_sda_gpio_dcl_handle = DCL_HANDLE_INVALID;
static kal_uint32 pxs_sw_i2c_delay = 100;
I2C_CONFIG_T cfg;
DCL_HANDLE   h_pxs;

static kal_uint8 pxs_GPIO_ReadIO(DCL_HANDLE pin_handle)
{
	GPIO_CTRL_READ_T data;
	DCL_STATUS ret;
	ASSERT(pin_handle != DCL_HANDLE_INVALID);
	ret = DclGPIO_Control(pin_handle,GPIO_CMD_READ,(DCL_CTRL_DATA_T*)&data);
	//ASSERT(STATUS_OK == ret);
	//ASSERT(data.u1IOData<1);
	return (kal_uint8)data.u1IOData;
}




static void DELAY(kal_uint32 _x)
{
	volatile kal_uint32 _a = 0;
	#if defined(SW_I2C_DELAY_USE_SYS_HW_TIMER)
	_a = drv_get_current_time();
	while (_x > drv_get_duration_tick(_a, drv_get_current_time()))
	{
		;
	}
	#endif // #if defined(SW_I2C_DELAY_USE_SYS_HW_TIMER)
	
	#if defined(SW_I2C_DELAY_USE_MCU_POLLING)
	do{
		_a++;
	}while (_a<_x);
	#endif // #if defined(SW_I2C_DELAY_USE_MCU_POLLING)

}

static void PXS_I2C_START(void)
{
	DclGPIO_Control(pxs_sda_gpio_dcl_handle,GPIO_CMD_WRITE_LOW,0); // SDA_LOW()();
	DELAY(pxs_sw_i2c_delay);
	DclGPIO_Control(pxs_scl_gpio_dcl_handle,GPIO_CMD_WRITE_LOW,0); // SCL_LOW();
}

static void PXS_I2C_WRITE(kal_uint8 _x)
{
	kal_uint8 _a = 0x80;
	while(_a != 0)
	{
		if (_x&_a)
		{
			DclGPIO_Control(pxs_sda_gpio_dcl_handle,GPIO_CMD_WRITE_HIGH,0); // SDA_HIGH();
		}
		else
		{
			DclGPIO_Control(pxs_sda_gpio_dcl_handle,GPIO_CMD_WRITE_LOW,0); // SDA_LOW()();
		}
		DELAY(pxs_sw_i2c_delay);
		DclGPIO_Control(pxs_scl_gpio_dcl_handle,GPIO_CMD_WRITE_HIGH,0);//SCL_HIGH();
		DELAY(pxs_sw_i2c_delay);
		DclGPIO_Control(pxs_scl_gpio_dcl_handle,GPIO_CMD_WRITE_LOW,0); // SCL_LOW();
		_a = _a >> 1;
	}
}

static kal_uint8 PXS_I2C_GET_ACK_LEVEL(kal_uint32 _d)
{
	kal_uint8 ret;
	DclGPIO_Control(pxs_sda_gpio_dcl_handle,GPIO_CMD_SET_DIR_IN,0); // SDA_INPUT();
	DELAY(pxs_sw_i2c_delay);
	DclGPIO_Control(pxs_scl_gpio_dcl_handle,GPIO_CMD_WRITE_HIGH,0);//SCL_HIGH();
	DELAY(_d);
	ret = pxs_GPIO_ReadIO(pxs_sda_gpio_dcl_handle);
	DclGPIO_Control(pxs_scl_gpio_dcl_handle,GPIO_CMD_WRITE_LOW,0); // SCL_LOW();
	DclGPIO_Control(pxs_sda_gpio_dcl_handle,GPIO_CMD_SET_DIR_OUT,0); // SDA_OUTPUT();
	return ret;
}

static void PXS_I2C_SET_ACK(void)
{
	DclGPIO_Control(pxs_sda_gpio_dcl_handle,GPIO_CMD_SET_DIR_OUT,0); // SDA_OUTPUT();
	DclGPIO_Control(pxs_sda_gpio_dcl_handle,GPIO_CMD_WRITE_LOW,0); // SDA_LOW()();
	DELAY(pxs_sw_i2c_delay);
	DclGPIO_Control(pxs_scl_gpio_dcl_handle,GPIO_CMD_WRITE_HIGH,0);//SCL_HIGH();
	DELAY(pxs_sw_i2c_delay);
	DclGPIO_Control(pxs_scl_gpio_dcl_handle,GPIO_CMD_WRITE_LOW,0); // SCL_LOW();
}

static void PXS_I2C_READ(kal_uint8 *_x)
{
	kal_uint8 _a = 0x80;
	*_x = 0;
	DclGPIO_Control(pxs_sda_gpio_dcl_handle,GPIO_CMD_SET_DIR_IN,0); // SDA_INPUT();
	while(_a != 0)
	{
		DELAY(pxs_sw_i2c_delay);
		DclGPIO_Control(pxs_scl_gpio_dcl_handle,GPIO_CMD_WRITE_HIGH,0);//SCL_HIGH();
		DELAY(pxs_sw_i2c_delay);
		if (pxs_GPIO_ReadIO(pxs_sda_gpio_dcl_handle))
		{
			*_x |= _a;
		}
		DclGPIO_Control(pxs_scl_gpio_dcl_handle,GPIO_CMD_WRITE_LOW,0); // SCL_LOW();
		_a = _a >> 1;
	}
}

static void PXS_I2C_STOP(void)
{
	DclGPIO_Control(pxs_sda_gpio_dcl_handle,GPIO_CMD_WRITE_LOW,0); // SDA_LOW()();
	DELAY(pxs_sw_i2c_delay);
	DclGPIO_Control(pxs_scl_gpio_dcl_handle,GPIO_CMD_WRITE_HIGH,0);//SCL_HIGH();
	DELAY(pxs_sw_i2c_delay);
	DclGPIO_Control(pxs_sda_gpio_dcl_handle,GPIO_CMD_WRITE_HIGH,0); // SDA_HIGH();
}


/*******************************************************
*Function name: cm3623_comm_init
*function: cm3623 I2C init ,for HW/SW i2c,only for cm3623
*in param:  
*out param: 
*******************************************************/
kal_bool cm3623_comm_init(void)
{
   	DCL_STATUS status;

    if ( 0xFF == gpio_pxs_i2c_scl_pin )   // for default device is use HW I2C
    {
				 h_pxs = DclSI2C_Open(DCL_I2C, DCL_I2C_OWNER_PS);
		
				 cfg.eOwner = DCL_I2C_OWNER_PS;
		     cfg.fgGetHandleWait = KAL_TRUE;
		     cfg.u1SlaveAddress = 0xB0;
		     cfg.u1DelayLen = 0;
		     cfg.eTransactionMode = DCL_I2C_TRANSACTION_FAST_MODE;
		     cfg.u4FastModeSpeed = 400;
		     cfg.u4HSModeSpeed = 0;
		     cfg.fgEnableDMA = KAL_FALSE;

		     status = DclSI2C_Configure(h_pxs, (DCL_CONFIGURE_T *)&cfg); 

		    if ( STATUS_OK != status )
		    {
		        kal_prompt_trace(MOD_BMT,"cm3623_init:Configure I2C error = %x",status);
		        return KAL_FALSE;
		    }
		    else
		    { 
		        return KAL_TRUE;
		    }
		
    }
	  else  // if on drv_tool has defined gpio var, use SW I2C.
	  {
		    pxs_scl_gpio_dcl_handle = DclGPIO_Open(DCL_GPIO,CM3623_SCL);
		    pxs_sda_gpio_dcl_handle = DclGPIO_Open(DCL_GPIO,CM3623_SDA);

		    #if defined(SW_I2C_DELAY_USE_SYS_HW_TIMER)
		    pxs_sw_i2c_delay = SW_I2C_DELAY_SYS_HW_COUNT;
		    #endif // #if defined(SW_I2C_DELAY_USE_SYS_HW_TIMER)
		
		    #if defined(SW_I2C_DELAY_USE_MCU_POLLING)
		    pxs_sw_i2c_delay = SW_I2C_DELAY_MCU_POLLING_COUNT;
		    #endif // #if defined(SW_I2C_DELAY_USE_MCU_POLLING)
		

		    DclGPIO_Control(pxs_scl_gpio_dcl_handle,GPIO_CMD_WRITE_HIGH,0);//SCL_HIGH();
		    DclGPIO_Control(pxs_sda_gpio_dcl_handle,GPIO_CMD_WRITE_HIGH,0); // SDA_HIGH();
		    DclGPIO_Control(pxs_scl_gpio_dcl_handle,GPIO_CMD_SET_DIR_OUT,0); // SCL_OUTPUT();
		    DclGPIO_Control(pxs_sda_gpio_dcl_handle,GPIO_CMD_SET_DIR_OUT,0); // SDA_OUTPUT();	

		    return KAL_TRUE;
	  }
}

/*******************************************************
*Function name: cm3623_reg_write
*function: cm3623 I2C write,for HW/SW i2c,only for cm3623
*in param:  kal_uint8 addr: device reg address
*           kal_uint8 val: var use for data
*out param: 
*******************************************************/
kal_bool cm3623_reg_write(kal_uint8 addr, kal_uint8 val)
{
	  
	  I2C_CTRL_CONT_WRITE_T write;
	  DCL_STATUS status = STATUS_OK;	
	  kal_uint8 write_buf[9] = {0};
	  kal_uint8 ack;
	  kal_bool ret = KAL_TRUE;

    if ( 0xFF == gpio_pxs_i2c_scl_pin )   // for default device is use HW I2C
    {

		    cfg.eOwner = DCL_I2C_OWNER_PS;
		    cfg.fgGetHandleWait = KAL_TRUE;
		    cfg.u1SlaveAddress = addr;
		    cfg.u1DelayLen = 0;
		    cfg.eTransactionMode = DCL_I2C_TRANSACTION_FAST_MODE;
		    cfg.u4FastModeSpeed = 400;
		    cfg.u4HSModeSpeed = 0;
		    cfg.fgEnableDMA = KAL_FALSE;

		    status = DclSI2C_Configure(h_pxs, (DCL_CONFIGURE_T *)&cfg);	
		    
		    if ( STATUS_OK != status )
		    {
		        kal_prompt_trace(MOD_BMT,"cm3623_reg_write:Configure I2C error = %x",status);
		        return KAL_FALSE;
		    }	    
		    
		    write_buf[0] = val;

		    write.pu1Data = write_buf;
		    write.u4DataLen = 1;
		    write.u4TransferNum = 1;
		    status = DclSI2C_Control(h_pxs, I2C_CMD_CONT_WRITE, (DCL_CTRL_DATA_T *)&write);
		
		    if( STATUS_OK != status )
		    {
		        kal_prompt_trace(MOD_BMT,"cm3623_reg_write:I2C write error = %x",status);
			      return KAL_FALSE;    
		    }

		    return KAL_TRUE;
		
    }//end if for HW I2C
    else  // for SW I2C
    {
		    PXS_I2C_START();
		    PXS_I2C_WRITE(addr);
		    ack = PXS_I2C_GET_ACK_LEVEL(pxs_sw_i2c_delay);
		
		    if (ack == 1)
		    {
			     ret = KAL_FALSE;
		    }

		    PXS_I2C_WRITE(val);
		
		    ack = PXS_I2C_GET_ACK_LEVEL(pxs_sw_i2c_delay);
		
		    if (KAL_TRUE == ret)
		    {
			     if (ack == 1)
			     {
				     //PXS_I2C_STOP();
				     //return KAL_FALSE;
				     ret = KAL_FALSE;
			     }
		    }

		    PXS_I2C_STOP();
		
		    return ret;        
    }
}

/*******************************************************
*Function name: cm3623_reg_read
*function: cm3623 I2C read,for HW/SW i2c,only for cm3623
*in param:  kal_uint8 addr: device reg address
*out param: kal_uint8 *val: var use for data
*******************************************************/
kal_bool cm3623_reg_read(kal_uint8 addr, kal_uint8 *val)
{
    //for Hw I2C
	  kal_uint8 ucRet = 0;
    I2C_CTRL_CONT_READ_T read;
	  DCL_STATUS status;
    //for SW I2c
	  kal_uint8 tmp;
	  kal_uint8 ack;
	  kal_bool ret = KAL_TRUE;

    if ( 0xFF == gpio_pxs_i2c_scl_pin )   // for default device is use HW I2C
    {
		    cfg.eOwner = DCL_I2C_OWNER_PS;
		    cfg.fgGetHandleWait = KAL_TRUE;
		    cfg.u1SlaveAddress = addr;
		    cfg.u1DelayLen = 0;
		    cfg.eTransactionMode = DCL_I2C_TRANSACTION_FAST_MODE;
		    cfg.u4FastModeSpeed = 400;
		    cfg.u4HSModeSpeed = 0;
		    cfg.fgEnableDMA = KAL_FALSE;

		    status = DclSI2C_Configure(h_pxs, (DCL_CONFIGURE_T *)&cfg);		

		    if ( STATUS_OK != status )
		    {
		        kal_prompt_trace(MOD_BMT,"cm3623_reg_read:Configure I2C error = %x",status);
		        return KAL_FALSE;
		    }

		    read.pu1Data = &ucRet;
		    read.u4DataLen = 1;
		    read.u4TransferNum = 1;
		    status = DclSI2C_Control(h_pxs, I2C_CMD_CONT_READ, (DCL_CTRL_DATA_T *)&read);
		
		    *val = ucRet;
		
	      kal_prompt_trace(MOD_BMT,"cm3623_reg_read = %x %d",ucRet,status);

		    if ( STATUS_OK != status )
		    {
		        kal_prompt_trace(MOD_BMT,"cm3623_reg_read:I2C read error = %x",status);
		        return KAL_FALSE;
		    }
	      else
	     {
		        return KAL_TRUE;
	     }
    }//end if for HW I2C
    else    // for SW I2c
    {
	     PXS_I2C_START();
		   PXS_I2C_WRITE((addr|1));
		
		   ack = PXS_I2C_GET_ACK_LEVEL(pxs_sw_i2c_delay);
		
		   if (ack == 1)
		   {
			     ret = KAL_FALSE;
		   }

		   PXS_I2C_READ(&tmp);
		   PXS_I2C_SET_ACK();

		   PXS_I2C_STOP();

		   *val = tmp;
		   return ret;
    }
}






#endif // #if defined(__PXS_CM3623__)
