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
 *   sccb_v2.c
 *
 *
 * Description:
 * ------------
 *   SCCB/I2C V2 Driver
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
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "drv_comm.h"
#include "reg_base.h"
#include "i2c2.h"    //*/ the new sccb_v2.h should be named i2c.h /*//
#include "i2c.h"
#include "drvpdn.h"
#include "dcl_i2c_owner.h"
#include "kal_general_types.h"
#include "intrCtrl.h"
#include "kal_public_api.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "kal_internal_api.h"

#if defined(DRV_I2C_DUAL_I2C)
#if (!defined(DRV_I2C_OFF))



/// I2C internal global variables
extern i2c_handle_struct i2c_handle[DCL_I2C_NUM_OF_OWNER];
extern i2c_status_struct dcl_i2c_status;
i2c_status_struct dcl_i2c2_status;


void dcl_i2c2_hw_cfg (DCL_I2C_OWNER owner, I2C_TRANSACTION_TYPE type, kal_uint8* write_buffer, kal_uint32 write_len, kal_uint8* read_buffer, kal_uint32 read_len, kal_uint32 transfer_num)
{ 
	i2c_handle_struct* handle=&i2c_handle[owner];
	i2c_config_struct* config=&handle->i2c_config;
	kal_uint32 count_write, count_read, i;
	#if defined(DRV_I2C_BUS_LATENCY)   //modified by dongming for MT6255 bus latency
	volatile kal_uint32 sta;//modified by dongming for 6255 BUS latency problem
	#endif
#if(defined (DRV_I2C_DMA_ENABLED))
    if (((!config->is_DMA_enabled) && (read_len>DRV_I2C_FIFO_DEPTH || write_len>DRV_I2C_FIFO_DEPTH)) ||
         (config->is_DMA_enabled && (type == I2C_TRANSACTION_WRITE_AND_READ) && (read_len>DRV_I2C_DMA_DEPTH_AUX || write_len>DRV_I2C_DMA_DEPTH)) ||
         (config->is_DMA_enabled && (type != I2C_TRANSACTION_WRITE_AND_READ) && (read_len>DRV_I2C_DMA_DEPTH || write_len>DRV_I2C_DMA_DEPTH)))
    {
        ASSERT(0); 
    }
#else 
    if (read_len>DRV_I2C_FIFO_DEPTH || write_len>DRV_I2C_FIFO_DEPTH) //if u want a transcation with len>8, please enable DMA.
    {
        ASSERT(0);
    }
#endif 

	count_write = write_len*transfer_num;
	count_read = read_len*transfer_num;
	
	CLEAR_I2C2_FIFO;
	CLEAR_I2C2_STA;
//	ENABLE_I2C_INT;
	DRV_I2C_ClearBits16(REG_I2C2_INT_MASK, I2C2_HS_NACK_ERR);
	DRV_I2C_ClearBits16(REG_I2C2_INT_MASK, I2C2_TRANSAC_ACK_ERR);
	DRV_I2C_SetBits16(REG_I2C2_INT_MASK, I2C2_TRANSAC_COMPLETE);
	
	SET_I2C2_STEP_CNT_DIV(handle->fs_step_cnt_div);
	SET_I2C2_SAMPLE_CNT_DIV(handle->fs_sample_cnt_div);
	
	SET_I2C2_TRANSACTION_LENGTH(transfer_num);
	
	if (handle->i2c_config.transaction_mode == I2C_TRANSACTION_FAST_MODE)
	{
		SET_I2C2_FAST_MODE;
		SET_I2C2_ST_BETWEEN_TRANSFER;
		if (config->delay_len>0)
		{
			SET_I2C2_DELAY_LENGTH(config->delay_len-1);
		}
		if ((config->delay_len == 0)&&((type == I2C_TRANSACTION_CONT_WRITE)||(type == I2C_TRANSACTION_CONT_READ)))
		{
			SET_I2C2_RS_BETWEEN_TRANSFER;
		}
	}
	else if (handle->i2c_config.transaction_mode == I2C_TRANSACTION_HIGH_SPEED_MODE)
	{
		SET_I2C2_HS_STEP_CNT_DIV(handle->hs_step_cnt_div);
		SET_I2C2_HS_SAMPLE_CNT_DIV(handle->hs_sample_cnt_div);
		SET_I2C2_HS_MODE;
		SET_I2C2_RS_BETWEEN_TRANSFER;
	}

	DISABLE_I2C2_DIR_CHANGE;	
    DISABLE_I2C2_DMA_TRANSFER;

	if ((type == I2C_TRANSACTION_WRITE)||(type == I2C_TRANSACTION_CONT_WRITE))
	{
		SET_I2C2_SLAVE_ADDRESS(config->slave_address,I2C2_WRITE_BIT);
		SET_I2C2_TRANSFER_LENGTH(write_len);
        dcl_i2c2_status.number_of_read=0;

		for (i=0;i<count_write;i++) 
		{
			DRV_I2C_WriteReg16(REG_I2C2_DATA_PORT, *(write_buffer+i));
		}  
	}
	else if ((type == I2C_TRANSACTION_READ)||(type == I2C_TRANSACTION_CONT_READ))
	{
		SET_I2C2_SLAVE_ADDRESS(config->slave_address,I2C2_READ_BIT);
		SET_I2C2_TRANSFER_LENGTH(read_len);
		
		dcl_i2c2_status.number_of_read = count_read;	
        dcl_i2c2_status.read_buffer=read_buffer;
	}
	else if (type == I2C_TRANSACTION_WRITE_AND_READ)
	{	
		SET_I2C2_SLAVE_ADDRESS(config->slave_address,I2C2_WRITE_BIT);
		SET_I2C2_TRANSFER_LENGTH(write_len);
		SET_I2C2_AUX_TRANSFER_LENGTH(read_len);
		ENABLE_I2C2_DIR_CHANGE;
		SET_I2C2_RS_BETWEEN_TRANSFER;
		
		dcl_i2c2_status.number_of_read = read_len;
        dcl_i2c2_status.read_buffer=read_buffer;
		for (i=0;i<write_len;i++)
		{
			DRV_I2C_WriteReg16(REG_I2C2_DATA_PORT, (*(write_buffer+i)));
		}  
	}
	START_I2C2_TRANSACTION;	
	#if defined(DRV_I2C_BUS_LATENCY)   //modified by dongming for MT6255 bus latency
	sta = DRV_I2C_ReadReg16(REG_I2C2_INT_STA);//modified by dongming for 6255 BUS latency problem
	#endif
}

void dcl_i2c_hw_cfg (DCL_I2C_OWNER owner, I2C_TRANSACTION_TYPE type, kal_uint8* write_buffer, kal_uint32 write_len, kal_uint8* read_buffer, kal_uint32 read_len, kal_uint32 transfer_num)
{ 
	i2c_handle_struct* handle=&i2c_handle[owner];
	i2c_config_struct* config=&handle->i2c_config;
	kal_uint32 count_write, count_read, i;
	#if defined(DRV_I2C_BUS_LATENCY)   //modified by dongming for MT6255 bus latency
	volatile kal_uint32 sta;//modified by dongming for 6255 BUS latency problem
	#endif
#if(defined (DRV_I2C_DMA_ENABLED))
    if (((!config->is_DMA_enabled) && (read_len>DRV_I2C_FIFO_DEPTH || write_len>DRV_I2C_FIFO_DEPTH)) ||
         (config->is_DMA_enabled && (type == I2C_TRANSACTION_WRITE_AND_READ) && (read_len>DRV_I2C_DMA_DEPTH_AUX || write_len>DRV_I2C_DMA_DEPTH)) ||
         (config->is_DMA_enabled && (type != I2C_TRANSACTION_WRITE_AND_READ) && (read_len>DRV_I2C_DMA_DEPTH || write_len>DRV_I2C_DMA_DEPTH)))
    {
        ASSERT(0); 
    }
#else 
    if (read_len>DRV_I2C_FIFO_DEPTH || write_len>DRV_I2C_FIFO_DEPTH) //if u want a transcation with len>8, please enable DMA.
    {
        ASSERT(0);
    }
#endif 

	count_write = write_len*transfer_num;
	count_read = read_len*transfer_num;
	
	CLEAR_I2C_FIFO;
	CLEAR_I2C_STA;
//	ENABLE_I2C_INT;
	DRV_I2C_ClearBits16(REG_I2C_INT_MASK, I2C_HS_NACK_ERR);
	DRV_I2C_ClearBits16(REG_I2C_INT_MASK, I2C_TRANSAC_ACK_ERR);
	DRV_I2C_SetBits16(REG_I2C_INT_MASK, I2C_TRANSAC_COMPLETE);
	
	SET_I2C_STEP_CNT_DIV(handle->fs_step_cnt_div);
	SET_I2C_SAMPLE_CNT_DIV(handle->fs_sample_cnt_div);
	
	SET_I2C_TRANSACTION_LENGTH(transfer_num);
	
	if (handle->i2c_config.transaction_mode == I2C_TRANSACTION_FAST_MODE)
	{
		SET_I2C_FAST_MODE;
		SET_I2C_ST_BETWEEN_TRANSFER;
		if (config->delay_len>0)
		{
			SET_I2C_DELAY_LENGTH(config->delay_len-1);
		}
		if ((config->delay_len == 0)&&((type == I2C_TRANSACTION_CONT_WRITE)||(type == I2C_TRANSACTION_CONT_READ)))
		{
			SET_I2C_RS_BETWEEN_TRANSFER;
		}
	}
	else if (handle->i2c_config.transaction_mode == I2C_TRANSACTION_HIGH_SPEED_MODE)
	{
		SET_I2C_HS_STEP_CNT_DIV(handle->hs_step_cnt_div);
		SET_I2C_HS_SAMPLE_CNT_DIV(handle->hs_sample_cnt_div);
		SET_I2C_HS_MODE;
		SET_I2C_RS_BETWEEN_TRANSFER;
	}

	DISABLE_I2C_DIR_CHANGE;	
    DISABLE_I2C_DMA_TRANSFER;

	if ((type == I2C_TRANSACTION_WRITE)||(type == I2C_TRANSACTION_CONT_WRITE))
	{
		SET_I2C_SLAVE_ADDRESS(config->slave_address,I2C_WRITE_BIT);
		SET_I2C_TRANSFER_LENGTH(write_len);
        dcl_i2c_status.number_of_read=0;

		#if (defined (DRV_I2C_DMA_ENABLED))
		dcl_i2c_status.is_DMA_enabled = config->is_DMA_enabled;
		if (dcl_i2c_status.is_DMA_enabled)
		{
			ENABLE_I2C_DMA_TRANSFER;
			if (!dcl_i2c_DMA_check_tx_buffer_cacheability((kal_uint32)write_buffer, count_write))
			{
				ASSERT(0); // Buffer cacheability check failed
			}
			dcl_i2c_DMA_tx((kal_uint32)write_buffer, count_write);
		}
		else
		#endif // #if (defined (DRV_I2C_DMA_ENABLED))
		{
			for (i=0;i<count_write;i++) 
			{
				DRV_I2C_WriteReg16(REG_I2C_DATA_PORT, *(write_buffer+i));
			}  
		}
	}
	else if ((type == I2C_TRANSACTION_READ)||(type == I2C_TRANSACTION_CONT_READ))
	{
		SET_I2C_SLAVE_ADDRESS(config->slave_address,I2C_READ_BIT);
		SET_I2C_TRANSFER_LENGTH(read_len);
		
		#if(defined (DRV_I2C_DMA_ENABLED))
		dcl_i2c_status.is_DMA_enabled = config->is_DMA_enabled;
		if (dcl_i2c_status.is_DMA_enabled)
		{
			dcl_i2c_status.number_of_read=0;	
			ENABLE_I2C_DMA_TRANSFER;
			if (!dcl_i2c_DMA_check_rx_buffer_cacheability((kal_uint32)read_buffer, count_read))
			{
				ASSERT(0); // Buffer cacheability check failed
			}
			dcl_i2c_DMA_rx((kal_uint32)read_buffer, count_read);
		}
		else
		#endif // #if(defined (DRV_I2C_DMA_ENABLED))
		{
			dcl_i2c_status.number_of_read = count_read;	
            dcl_i2c_status.read_buffer=read_buffer;
		}	
	}
	else if (type == I2C_TRANSACTION_WRITE_AND_READ)
	{	
		SET_I2C_SLAVE_ADDRESS(config->slave_address,I2C_WRITE_BIT);
		SET_I2C_TRANSFER_LENGTH(write_len);
		SET_I2C_AUX_TRANSFER_LENGTH(read_len);
		ENABLE_I2C_DIR_CHANGE;
		SET_I2C_RS_BETWEEN_TRANSFER;
		
		#if(defined (DRV_I2C_DMA_ENABLED))
		dcl_i2c_status.is_DMA_enabled = config->is_DMA_enabled;
		if (dcl_i2c_status.is_DMA_enabled)
		{
			dcl_i2c_status.number_of_read=0;	
			ENABLE_I2C_DMA_TRANSFER;
			if (!dcl_i2c_DMA_check_tx_buffer_cacheability((kal_uint32)write_buffer, write_len))
			{
				ASSERT(0); // Buffer cacheability check failed
			}
			if (!dcl_i2c_DMA_check_rx_buffer_cacheability((kal_uint32)read_buffer, read_len))
			{
				ASSERT(0); // Buffer cacheability check failed
			}
			dcl_i2c_DMA_tx_and_rx((kal_uint32)write_buffer, write_len, (kal_uint32)read_buffer, read_len);	
		}
		else
		#endif // #if(defined (DRV_I2C_DMA_ENABLED))
		{
			dcl_i2c_status.number_of_read = read_len;
            dcl_i2c_status.read_buffer=read_buffer;
			for (i=0;i<write_len;i++)
			{
				DRV_I2C_WriteReg16(REG_I2C_DATA_PORT, (*(write_buffer+i)));
			}  
		}	
	}
	START_I2C_TRANSACTION;	
	#if defined(DRV_I2C_BUS_LATENCY)   //modified by dongming for MT6255 bus latency
	sta = DRV_I2C_ReadReg16(REG_I2C_INT_STA);//modified by dongming for 6255 BUS latency problem
	#endif
}

void dcl_i2c2_lisr(void)
{
	kal_uint32 savedMask;
	kal_uint32 sta;
 	
	savedMask = SaveAndSetIRQMask();

	sta = DRV_I2C_ReadReg16(REG_I2C2_INT_STA); //sta=REG_I2C_INT_STA;

    dcl_dual_i2c_status_handler(I2C_CONTROLLER_2,&dcl_i2c2_status,sta);
 	
	RestoreIRQMask(savedMask);
}
void dcl_i2c_lisr(void)
{
	kal_uint32 savedMask;
	kal_uint32 sta;
 	
	savedMask = SaveAndSetIRQMask();

	sta = DRV_I2C_ReadReg16(REG_I2C_INT_STA); //sta=REG_I2C_INT_STA;

    dcl_dual_i2c_status_handler(I2C_CONTROLLER_1,&dcl_i2c_status,sta);
 	
	RestoreIRQMask(savedMask);
}


void i2c2_init(void)
{
    if(dcl_i2c2_status.state != I2C_IDLE_STATE)
        return;
	dcl_i2c2_status.state=I2C_READY_STATE;
  
	IRQ_Register_LISR(IRQ_I2C_18V_CODE, dcl_i2c2_lisr,"DCL I2C2 ISR");
	IRQUnmask(IRQ_I2C_18V_CODE);
    
	ENABLE_I2C2_ACK_ERR_DET; //Always enable ack error detection
	ENABLE_I2C2_NAKERR_DET;  //Always enable nack error detection
}
void i2c_init(void)
{
    if(dcl_i2c_status.state != I2C_IDLE_STATE)
        return;
	dcl_i2c_status.state=I2C_READY_STATE;
  
	IRQ_Register_LISR(IRQ_I2C_CODE, dcl_i2c_lisr,"DCL I2C ISR");
	IRQUnmask(IRQ_I2C_CODE);
    
	ENABLE_I2C_ACK_ERR_DET; //Always enable ack error detection
	ENABLE_I2C_NAKERR_DET;  //Always enable nack error detection

}

void dcl_dual_i2c_hw_cfg (kal_uint8 controller,DCL_I2C_OWNER owner, I2C_TRANSACTION_TYPE type, kal_uint8* write_buffer, kal_uint32 write_len, kal_uint8* read_buffer, kal_uint32 read_len, kal_uint32 transfer_num)
{ 
	if(controller == I2C_CONTROLLER_1)
	{
		I2C_POWER_ON();
		dcl_i2c_hw_cfg (owner,type, write_buffer, write_len,  read_buffer,  read_len, transfer_num);
	}
	else
	{
		I2C2_POWER_ON();
		dcl_i2c2_hw_cfg (owner,type, write_buffer, write_len,  read_buffer,  read_len, transfer_num);
	}
}
void dcl_dual_i2c_status_handler(kal_uint8 current_controller,i2c_status_struct *i2c_status,kal_uint32 sta)
{
	kal_uint32 i;
	kal_uint8* read_buffer=i2c_status->read_buffer;
    kal_uint32 number_of_read=i2c_status->number_of_read;
	i2c_handle_struct* handle=&i2c_handle[i2c_status->owner];
	kal_uint16 *i2c_data_port;//OOO:do we need declar:kal_uint16 * i2c_data_port???

	if (sta == I2C_TRANSAC_COMPLETE) //This transaction is done now
	{
        #if(defined (DRV_I2C_DMA_ENABLED))
		if (!handle->i2c_config.is_DMA_enabled) //copy the read data to the previous transcation owner
        #endif // #if(defined (DRV_I2C_DMA_ENABLED))
		{
			if(current_controller == I2C_CONTROLLER_1){
				i2c_data_port = (kal_uint16 *)REG_I2C_DATA_PORT;}
			else{
				i2c_data_port = (kal_uint16 *)REG_I2C2_DATA_PORT;}
			
			for (i=0;i<number_of_read;i++)
			{
				read_buffer[i]=(DRV_I2C_ReadReg16(i2c_data_port) & 0xff); //copy the read data to the previous transcation owner
			}
		}
		handle->transaction_result = I2C_TRANSACTION_COMPLETE;
	}
	else
	{
		if (sta & I2C_TRANSAC_ACK_ERR)
			handle->transaction_result = I2C_TRANSACTION_ACKERR;
		else if (sta & I2C_HS_NACK_ERR)
			handle->transaction_result = I2C_TRANSACTION_HS_NACKERR;
		else //if got this, check register INTR_STAT to debug
			handle->transaction_result = I2C_TRANSACTION_FAIL;
	}
	i2c_status->state=I2C_READY_STATE;
	if(current_controller == I2C_CONTROLLER_1){
		I2C_POWER_OFF();}
	else{
		I2C2_POWER_OFF();}
		
}



//----------------------------I2C internal arbiteration------------------------------
//--When return from this function, I bit is turned off!!--
kal_uint32 dcl_dual_i2c_wait_transaction_complete_and_lock(i2c_status_struct *i2c_status,DCL_I2C_OWNER owner)
{
	kal_uint32 savedMask;

	if ((kal_query_systemInit()==KAL_FALSE)&&(kal_if_lisr()==KAL_FALSE))
	{
		while(1)
		{
		    savedMask = kal_take_thread_protect();
			if (i2c_status->state==I2C_READY_STATE)
			{
					i2c_status->state=I2C_BUSY_STATE; //Lock it
					i2c_status->owner=owner;
					return savedMask;//will restore it at:  dcl_i2c_wait_transaction_complete
				
				
			}
			else if (i2c_handle[owner].i2c_config.get_handle_wait==KAL_FALSE)
			{
				kal_give_thread_protect(savedMask);
				return 0;
			}
			kal_give_thread_protect(savedMask);
			
		}//end of while
	}
	else
	{
		if (i2c_status->state!=I2C_READY_STATE)
		{
			ASSERT(0);
		}

		i2c_status->state=I2C_BUSY_STATE; //Lock it
		i2c_status->owner=owner;
		
	}

	return 0;
}



void dcl_dual_i2c_wait_transaction_complete(kal_uint8 current_controller,i2c_status_struct *i2c_status,kal_uint32 savedMask)
{
	
	kal_uint16 *i2c_int_sta_reg;
	if ((kal_query_systemInit()==KAL_FALSE)&&(kal_if_lisr()==KAL_FALSE))
	{
		kal_give_thread_protect(savedMask);
		while (i2c_status->state == I2C_BUSY_STATE)
		{
			;
		}
		return;
	}
	else
	{
		kal_uint32 sta;
		if(current_controller == I2C_CONTROLLER_1){
			i2c_int_sta_reg = (kal_uint16 *)REG_I2C_INT_STA;}
		else{
			i2c_int_sta_reg = (kal_uint16 *)REG_I2C2_INT_STA;}
		do
		{
			sta = DRV_I2C_ReadReg16(i2c_int_sta_reg); 
		} while((sta & I2C_TRANSAC_COMPLETE) == 0);

        dcl_dual_i2c_status_handler(current_controller,i2c_status,sta);
	}
}



void dcl_dual_i2c_set_transaction_speed(DCL_I2C_OWNER owner,I2C_TRANSACTION_MODE mode,kal_uint16* Fast_Mode_Speed,kal_uint16* HS_Mode_Speed)
{
	kal_uint32	step_cnt_div;
	kal_uint32	sample_cnt_div;
	kal_uint32	temp;

	//Fast Mode Speed
	for (sample_cnt_div=1;sample_cnt_div<=8;sample_cnt_div++)
	{
		if (NULL != Fast_Mode_Speed)
		{
			temp=((*Fast_Mode_Speed)*2*sample_cnt_div);	
		}
		else
		{
			temp = 1*2*sample_cnt_div;
		}
		step_cnt_div=(I2C_CLOCK_RATE+temp-1)/temp;	//cast the <1 part
   
		if (step_cnt_div<=64) 
		{
			break;
		}
	}
	if (step_cnt_div>64 && sample_cnt_div>8)
	{
		step_cnt_div=64;
		sample_cnt_div=8;
	}


    
	if (NULL != Fast_Mode_Speed)
	{
        *Fast_Mode_Speed = I2C_CLOCK_RATE/2/sample_cnt_div/step_cnt_div; 
        i2c_handle[owner].fs_sample_cnt_div=sample_cnt_div-1;
        i2c_handle[owner].fs_step_cnt_div=step_cnt_div-1;
        i2c_handle[owner].i2c_config.transaction_mode=I2C_TRANSACTION_FAST_MODE;
 
	}
  
	//HS Mode Speed
	if (mode==I2C_TRANSACTION_HIGH_SPEED_MODE) 
	{ 
		for (sample_cnt_div=1;sample_cnt_div<=8;sample_cnt_div++)
		{
			if (NULL != HS_Mode_Speed)
			{
				temp=((*HS_Mode_Speed)*2*sample_cnt_div);	
			}
			else
			{
				temp=(1*2*sample_cnt_div);	
			}
			step_cnt_div=(I2C_CLOCK_RATE+temp-1)/temp;
			if (step_cnt_div<=8) 
			{
				break;
			}
		}
		if (NULL != HS_Mode_Speed)
		{
			*HS_Mode_Speed=I2C_CLOCK_RATE/2/sample_cnt_div/step_cnt_div; 
            i2c_handle[owner].hs_sample_cnt_div=sample_cnt_div-1;
            i2c_handle[owner].hs_step_cnt_div=step_cnt_div-1;
            i2c_handle[owner].i2c_config.transaction_mode=I2C_TRANSACTION_HIGH_SPEED_MODE;
		}
	}
}

#endif
#endif
