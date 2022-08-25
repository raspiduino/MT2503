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
 *    dcl_i2c.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines DCL (Driver Common Layer) of the I2C driver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_features.h"
#include "drv_comm.h"
#include "dcl.h"
#include "kal_general_types.h"
#include "dcl_i2c_owner.h"
#include "i2c.h"
#include "i2c2.h"
#include "kal_public_api.h"

#if defined(DRV_I2C_DUAL_I2C)
#if (!defined(DRV_I2C_OFF) && defined(DCL_I2C_INTERFACE))

// Global variable for DCL I2C API usage
#define DCL_I2C_DEV_MAGIC_NUM		(0x50000000)
#define DCL_I2C2_DEV_MAGIC_NUM		(0x60000000)

#define MAX_DCL_I2C_HANDLE			DCL_I2C_NUM_OF_OWNER


extern i2c_handle_struct i2c_handle[DCL_I2C_NUM_OF_OWNER];
extern i2c_status_struct dcl_i2c_status;
extern i2c_status_struct dcl_i2c2_status;



/*==============add for common dcl layer===============*/
extern DEV_Operations i2c_dev_operations = {DclSI2CExtra_Open,
                                            DclSI2C_ReadData,
                                            DclSI2C_WriteData,
                                            DclSI2C_Control,
                                            NULL,
                                            NULL,
                                            DclSI2C_Close};
/*======================================================*/



DCL_STATUS _ConvertDclReturnStatus(I2C_TRANSACTION_RESULT result)
{
    if (result == I2C_TRANSACTION_COMPLETE)
    {
        return STATUS_OK;
    }
    else
    {
        if (result == I2C_TRANSACTION_IS_BUSY)
            return STATUS_DEVICE_IS_BUSY;
        else if (result == I2C_TRANSACTION_ACKERR)
            return STATUS_ACKERR;
        else if (result == I2C_TRANSACTION_HS_NACKERR)
            return STATUS_HS_NACKERR;
        else
            return STATUS_FAIL;
    }

    //return STATUS_OK;
}


/*************************************************************************
* FUNCTION
*  DclSI2C_Initialize
*
* DESCRIPTION
*  This function is to initialize S/W I2C module
*
* PARAMETERS
*  None
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
DCL_STATUS DclSI2C_Initialize(void)
{
	i2c_init();
	i2c2_init();

	return STATUS_OK;
}

/*************************************************************************
* FUNCTION
*  DclSI2C_Open
*
* DESCRIPTION
*  This function is to open the I2C module and return a handle
*
* PARAMETERS
*  dev: only valid for DCL_I2C
*  flags: no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  DCL_HANDLE_INVALID: Open failed
*  Other value: A valid handle
*
*************************************************************************/

DCL_HANDLE DclSI2C_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	kal_uint32 i2c_owner = flags & 0xFF;  //*/ DCL_I2C_OWNER should be transfered through the low 8bit of flags /*//
	
	if (i2c_handle[i2c_owner].i2c_config.Fast_Mode_Speed)  //*/ when system init or called DclSI2C_Close(), config->Fast_Mode_Speed == 0 /*// 
	{
		return DCL_HANDLE_OCCUPIED;		//*/ This Handle has been opened /*//
	}
			
	i2c_handle[i2c_owner].i2c_config.Fast_Mode_Speed = 1;
		
	if(dev == DCL_I2C){ 
		return (DCL_I2C_DEV_MAGIC_NUM | i2c_owner);}
	else if(dev == DCL_I2C2){
		return (DCL_I2C2_DEV_MAGIC_NUM | i2c_owner);}
	else{
		return DCL_HANDLE_INVALID;}
}

DCL_HANDLE DclSI2CExtra_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	DCL_HANDLE handle;
	kal_uint8 i;
	for(i = DCL_I2C_USER_DEV1; i <= DCL_I2C_USER_DEV10;i++)
	{
		handle = DclSI2C_Open(dev,i);
		if(DCL_HANDLE_OCCUPIED != handle)
		{
			return handle;
		}
	}
	return DCL_HANDLE_INVALID;
}

/*************************************************************************
* FUNCTION
*  DclSI2C_ReadData
*
* DESCRIPTION
*  This function is not supported for the I2C module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclSI2C_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_BUFF_LEN *returned_len, DCL_OPTIONS options)
{

	I2C_CTRL_SINGLE_READ_T prSingleRead;
	DCL_STATUS ret_status;
	prSingleRead.pu1Data = buff;
	prSingleRead.u4DataLen = buf_len;
	ret_status = DclSI2C_Control(handle, I2C_CMD_SINGLE_READ, (DCL_CTRL_DATA_T *)&prSingleRead);
	*returned_len = buf_len;
	return ret_status;
}

/*************************************************************************
* FUNCTION
*  DclSI2C_WriteData
*
* DESCRIPTION
*  This function is not supported for the I2C module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclSI2C_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_BUFF_LEN* written_len,DCL_OPTIONS options)
{
	I2C_CTRL_SINGLE_WRITE_T prSingleWrite;
	DCL_STATUS ret_status;
	prSingleWrite.pu1Data = buff;
	prSingleWrite.u4DataLen = buf_len;
	ret_status = DclSI2C_Control(handle, I2C_CMD_SINGLE_WRITE, (DCL_CTRL_DATA_T *)&prSingleWrite);
	* written_len = buf_len;
	return ret_status;
}

/*************************************************************************
* FUNCTION
*  DclSI2C_Configure
*
* DESCRIPTION
*  This function is to configure the I2C module.
*
* PARAMETERS
*  handle: the returned handle value of DclSI2C_Open
*  configure: a structure which include the I2C configuration.  
*
* RETURNS
*  STATUS_OK: Successfully configure I2C module.
*  STATUS_INVALID_DCL_HANDLE: It's a invalid handle.
*  STATUS_NOT_OPENED: The module has not been opened.
*  STATUS_INVALID_CONFIGURATION: The configuration is invalid.
*
*************************************************************************/
DCL_STATUS DclSI2C_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure){

	// Check magic number
	if (((handle & DCL_I2C_DEV_MAGIC_NUM) != DCL_I2C_DEV_MAGIC_NUM) && ((handle & DCL_I2C2_DEV_MAGIC_NUM) != DCL_I2C2_DEV_MAGIC_NUM) )
	{
		//ASSERT(0);
		return STATUS_INVALID_DCL_HANDLE;
	}

	{
		I2C_CONFIG_T* prI2CConfig = (I2C_CONFIG_T*) configure;
		DCL_I2C_OWNER i2c_owner = (DCL_I2C_OWNER)(handle & 0xFF);
		
		//*/ check if the handle is opened /*//
		if (i2c_handle[i2c_owner].i2c_config.Fast_Mode_Speed == 0)
		{
			return STATUS_NOT_OPENED;
		}
		// Check owner
		if (i2c_owner >= (kal_uint8)DCL_I2C_NUM_OF_OWNER )
		{
			return STATUS_INVALID_CONFIGURATION;
		}

		i2c_handle[i2c_owner].i2c_config.get_handle_wait = (kal_bool)prI2CConfig->fgGetHandleWait;

 		i2c_handle[i2c_owner].i2c_config.slave_address = prI2CConfig->u1SlaveAddress;
 		i2c_handle[i2c_owner].i2c_config.delay_len = prI2CConfig->u1DelayLen;
 		
 		//*/ sccb_xxx will be replaced by i2c_xxx /*//
		i2c_handle[i2c_owner].i2c_config.transaction_mode = (I2C_TRANSACTION_MODE)prI2CConfig->eTransactionMode;
		
		i2c_handle[i2c_owner].i2c_config.Fast_Mode_Speed = prI2CConfig->u4FastModeSpeed;
		i2c_handle[i2c_owner].i2c_config.HS_Mode_Speed = prI2CConfig->u4HSModeSpeed;
		
		#if (defined(DRV_I2C_DMA_ENABLED))
		i2c_handle[i2c_owner].i2c_config.is_DMA_enabled = (kal_bool)(prI2CConfig->fgEnableDMA);
		#else
		if (prI2CConfig->fgEnableDMA)
		{
			//ASSERT(0);
			return STATUS_DEVICE_NOT_SUPPORT_DMA; //*/ user config fgEnableDMA == TRUE, but we do not support /*//
		}
		#endif // #if (defined(DRV_I2C_DMA_ENABLED))
          
        dcl_dual_i2c_set_transaction_speed(i2c_owner,i2c_handle[i2c_owner].i2c_config.transaction_mode,&(i2c_handle[i2c_owner].i2c_config.Fast_Mode_Speed),&(i2c_handle[i2c_owner].i2c_config.HS_Mode_Speed));          

        prI2CConfig->u4FastModeSpeed = i2c_handle[i2c_owner].i2c_config.Fast_Mode_Speed;
        prI2CConfig->u4HSModeSpeed = i2c_handle[i2c_owner].i2c_config.HS_Mode_Speed;
	}

	return STATUS_OK;
}

/*************************************************************************
* FUNCTION
*  DclSI2C_RegisterCallback
*
* DESCRIPTION
*  This function is to set callback function for the I2C module.
*
* PARAMETERS
*  handle: the returned handle value of DclSI2C_Open
*  event: Supported events:
*  callback: the callback function for registered events
*
* RETURNS
*  STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclSI2C_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, DCL_CALLBACK*	callback,void* parameter)
{
	return STATUS_UNSUPPORTED;
}

/*************************************************************************
* FUNCTION
*  DclSI2C_Control
*
* DESCRIPTION
*  This function is to send command to control the I2C module.
*
* PARAMETERS
*  handle: The handle value returned from DclSI2C_Open
*  cmd: A control command for I2C module
*          1. I2C_CMD_GET_TRANSACTION_MODE: to get transaction mode
*          2. I2C_CMD_SET_TRANSACTION_SPEED: to set transaction speed
*          3. I2C_CMD_SINGLE_WRITE: to perform a single WRITE
*          4. I2C_CMD_SINGLE_READ: to perform a single READ
*          5. I2C_CMD_CONT_WRITE: to perform a continuous WRITE
*          6. I2C_CMD_CONT_READ: to  perform a continuous READ
*          7. I2C_CMD_WRITE_AND_READ: to perform a specific sequence "WRITE then READ"
*          8. I2C_CMD_ENABLE_DMA: to enable/disable DMA
*  data: The data of the control command
*          1. I2C_CMD_GET_TRANSACTION_MODE: pointer to a I2C_CTRL_GET_TRANSACTION_MODE_T structure
*          2. I2C_CMD_SET_TRANSACTION_SPEED: pointer to a I2C_CTRL_SET_TRANSACTION_SPEED_T structure
*          3. I2C_CMD_SINGLE_WRITE: pointer to a I2C_CTRL_SINGLE_WRITE_T structure
*          4. I2C_CMD_SINGLE_READ: pointer to a I2C_CTRL_SINGLE_READ_T structure
*          5. I2C_CMD_CONT_WRITE: pointer to a I2C_CTRL_CONT_WRITE_T structure
*          6. I2C_CMD_CONT_READ: pointer to a I2C_CTRL_CONT_READ_T structure
*          7. I2C_CMD_WRITE_AND_READ: pointer to a I2C_CTRL_WRITE_AND_READE_T structure
*          8. I2C_CMD_ENABLE_DMA: pointer to a I2C_CTRL_ENABLE_DMA_T structure
*
* RETURNS
*  STATUS_OK: command is executed successfully.
*  STATUS_FAIL: command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*
*************************************************************************/
DCL_STATUS DclSI2C_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	DCL_I2C_OWNER i2c_owner;  
	kal_uint8 current_controller = 0;
	i2c_status_struct * tmp_i2c_status;
  // At present, this is not allowed to be used in LISR
	if (kal_if_lisr())
	{
    return STATUS_FAIL;
	}
	
	// Check magic number
	if (((handle & DCL_I2C_DEV_MAGIC_NUM) != DCL_I2C_DEV_MAGIC_NUM) && ((handle & DCL_I2C2_DEV_MAGIC_NUM) != DCL_I2C2_DEV_MAGIC_NUM) ){
		return STATUS_INVALID_DCL_HANDLE;}
			
	//*/ check if the handle is opened /*//
	if ((i2c_handle[(kal_uint8)(handle & 0xFF)].i2c_config.Fast_Mode_Speed) == 0)
	{
		return STATUS_NOT_OPENED;
	}
	
	i2c_owner = (DCL_I2C_OWNER)(handle & 0xFF);
	switch (cmd)
	{
		case I2C_CMD_GET_TRANSACTION_MODE:
		{
			I2C_CTRL_GET_TRANSACTION_MODE_T *prGetTransactionMode;
			prGetTransactionMode = &(data->rGetTransactionMode);
			
			prGetTransactionMode->eTransactionMode = (DCL_I2C_TRANSACTION_MODE)i2c_handle[i2c_owner].i2c_config.transaction_mode;
			return STATUS_OK;
		}
		//break;
		case I2C_CMD_SET_TRANSACTION_SPEED:
		{
			I2C_CTRL_SET_TRANSACTION_SPEED_T *prSetTransactionSpeed;
			prSetTransactionSpeed = &(data->rSetTransactionSpeed);

            i2c_handle[i2c_owner].i2c_config.Fast_Mode_Speed = prSetTransactionSpeed->u4FastModeSpeed;
            i2c_handle[i2c_owner].i2c_config.HS_Mode_Speed = prSetTransactionSpeed->u4HSModeSpeed;
            
            dcl_dual_i2c_set_transaction_speed(i2c_owner,i2c_handle[i2c_owner].i2c_config.transaction_mode,&(i2c_handle[i2c_owner].i2c_config.Fast_Mode_Speed),&(i2c_handle[i2c_owner].i2c_config.HS_Mode_Speed));          
            
            prSetTransactionSpeed->u4FastModeSpeed = i2c_handle[i2c_owner].i2c_config.Fast_Mode_Speed;
            prSetTransactionSpeed->u4HSModeSpeed = i2c_handle[i2c_owner].i2c_config.HS_Mode_Speed;

			return STATUS_OK;
		}
		//break;
		case I2C_CMD_SINGLE_WRITE:
        case I2C_CMD_SINGLE_READ:
        case I2C_CMD_CONT_WRITE:
        case I2C_CMD_CONT_READ:
        case I2C_CMD_WRITE_AND_READ:
		{
            kal_uint32 savedMask;
            
      /****************************************************************/
	  /***************added for ATV bug ********************************/
	 
		 	#ifdef __ATV_SUPPORT__
		 	extern kal_bool vSetLoadCodeflag;
		 	extern void MatvReadAudioRegister(void);
		 	if(vSetLoadCodeflag&&(i2c_owner != DCL_I2C_OWNER_MATV))
		  	{
         		MatvReadAudioRegister();  
		 	}
			#endif

	  /***************************************************************/
		
			if ((handle & DCL_I2C_DEV_MAGIC_NUM) == DCL_I2C_DEV_MAGIC_NUM)
			{
			    tmp_i2c_status = &dcl_i2c_status;
				current_controller = I2C_CONTROLLER_1;
			}
			else
			{
				tmp_i2c_status = &dcl_i2c2_status;
				current_controller = I2C_CONTROLLER_2;
			}
			savedMask=dcl_dual_i2c_wait_transaction_complete_and_lock(tmp_i2c_status,i2c_owner);
			if (tmp_i2c_status->owner != i2c_owner)
			{
				return STATUS_DEVICE_IS_BUSY;
			}

            if(cmd == I2C_CMD_SINGLE_WRITE)
            {
                I2C_CTRL_SINGLE_WRITE_T *prSingleWrite = &(data->rSingleWrite);
	            dcl_dual_i2c_hw_cfg (current_controller,i2c_owner, I2C_TRANSACTION_WRITE, prSingleWrite->pu1Data, prSingleWrite->u4DataLen, NULL, 0, 1); 
            }
            else if(cmd == I2C_CMD_SINGLE_READ)
            {
                I2C_CTRL_SINGLE_READ_T *prSingleRead = &(data->rSingleRead);
	            dcl_dual_i2c_hw_cfg (current_controller,i2c_owner, I2C_TRANSACTION_READ, NULL, 0, prSingleRead->pu1Data, prSingleRead->u4DataLen, 1);

            }
            else if(cmd == I2C_CMD_CONT_WRITE)
            {
                I2C_CTRL_CONT_WRITE_T *prContWrite = &(data->rContWrite);
	            dcl_dual_i2c_hw_cfg (current_controller,i2c_owner, I2C_TRANSACTION_CONT_WRITE, prContWrite->pu1Data, prContWrite->u4DataLen, NULL, 0, prContWrite->u4TransferNum);
            }
            else if(cmd == I2C_CMD_CONT_READ)
            {
                I2C_CTRL_CONT_READ_T *prContRead = &(data->rContRead);
	            dcl_dual_i2c_hw_cfg (current_controller,i2c_owner, I2C_TRANSACTION_CONT_READ, NULL, 0, prContRead->pu1Data, prContRead->u4DataLen, prContRead->u4TransferNum);
            
            }
            else if(cmd == I2C_CMD_WRITE_AND_READ)
            {
                I2C_CTRL_WRITE_AND_READE_T *prWriteAndRead  = &(data->rWriteAndRead);
	            dcl_dual_i2c_hw_cfg (current_controller,i2c_owner, I2C_TRANSACTION_WRITE_AND_READ, prWriteAndRead->pu1OutData, prWriteAndRead->u4OutDataLen, prWriteAndRead->pu1InData, prWriteAndRead->u4InDataLen, 2);  
            
            }
            
			dcl_dual_i2c_wait_transaction_complete(current_controller,tmp_i2c_status,savedMask);
			
            return _ConvertDclReturnStatus(i2c_handle[i2c_owner].transaction_result);
		}
		//break;
		case I2C_CMD_SET_SLAVE_ADDRESS:
		{
			I2C_CTRL_SET_SLAVE_ADDRESS_T *prSetSlaveAddress;
			prSetSlaveAddress = &(data->rSetSlaveAddress);

            i2c_handle[i2c_owner].i2c_config.slave_address=prSetSlaveAddress->u1SlaveAddress;
			return STATUS_OK;
		}
	//	break;
		default:
			return STATUS_INVALID_CMD;
	//	break;
	}
//	return STATUS_FAIL;
}

/*************************************************************************
* FUNCTION
*  DclSI2C_Close
*
* DESCRIPTION
*  This function is to close the I2C module.
*
* PARAMETERS
*  handle: the returned handle value of DclSI2C_Open
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
DCL_STATUS DclSI2C_Close(DCL_HANDLE handle)
{
	i2c_config_struct* config = &i2c_handle[(kal_uint8)(handle & 0xFF)].i2c_config;

	// Check magic number
	if (((handle & DCL_I2C_DEV_MAGIC_NUM) != DCL_I2C_DEV_MAGIC_NUM) && ((handle & DCL_I2C2_DEV_MAGIC_NUM) != DCL_I2C2_DEV_MAGIC_NUM) ){
		return STATUS_INVALID_DCL_HANDLE;}

		
	//*/ check if the handle is opened, if i2c handle is opened, the related Fast_Mode_Speed not equal to zero /*//
	if (config->Fast_Mode_Speed == 0)
	{
		return STATUS_NOT_OPENED;
	}

	config->Fast_Mode_Speed = 0;

	return STATUS_OK;
}
#else  // (!defined(DRV_I2C_OFF) && defined(DCL_I2C_INTERFACE))
DCL_STATUS DclSI2C_Initialize(void)
{
	return STATUS_FAIL;
}

DCL_HANDLE DclSI2C_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	return 0;
}
DCL_STATUS DclSI2C_ReadDataDclSI2C_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_BUFF_LEN *returned_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSI2C_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_BUFF_LEN* written_len,DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSI2C_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_FAIL;
}

DCL_STATUS DCL_STATUS DclSI2C_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, DCL_CALLBACK*	callback,void* parameter)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSI2C_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	return STATUS_FAIL;
}
DCL_STATUS DclSI2C_Close(DCL_HANDLE handle)
{
	return STATUS_FAIL;
}

#endif
#endif
