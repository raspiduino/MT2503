
#include "dcl.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "spi_slave_sw.h"
#include "spi_slave_hw.h"
#include "intrCtrl.h"
#include "drv_hisr.h"
#include "stack_config.h"



#if defined(DRV_SPI_SLAVE_SUPPORT) 

#define DCL_SPISLV_MAGIC_NUM  0xE0000000
#define DCL_SPISLV_IS_HANDLE_MAGIC(handl_) ((handl_)& DCL_SPISLV_MAGIC_NUM)
#define DCL_SPISLV_GET_DEV(handle_) ((handle_) & (~DCL_SPISLV_MAGIC_NUM))


/*THE SPI SLAVE  EVENT AND MSG PAIR*/
DCL_EVENT_MSG_PAIR spislv_event_msg_pairs[]={
	{SPI_SLAVE_SET_READ,MSG_ID_SPI_SLV_SET_READ_IND},
	{SPI_SLAVE_READ,MSG_ID_SPI_SLV_READ_DATA_IND},
	{SPI_SLAVE_SET_WRITE,MSG_ID_SPI_SLV_SET_WRITE_IND},
    {SPI_SLAVE_WRITE,MSG_ID_SPI_SLV_WRITE_DATA_IND},
	{SPI_SLAVE_ERROR_INFO,MSG_ID_SPI_SLV_ERROR_INFO_IND}
	};
DCL_EVENT_MSG_MAP spislv_event_msg_map={
sizeof(spislv_event_msg_pairs)/sizeof(DCL_EVENT_MSG_PAIR), spislv_event_msg_pairs};

/*DCL LAYER FUNCTIONS */

void DclSpiSlave_Initialize(DCL_DEV  dev)
{

   kal_uint8 port;
 
   port=dev-DCL_SPI_SLAVE;

	if(port>SPI_SLAVE_MAX_PORT_NUM)//
		ASSERT(0);

   SPISlave_Info[port].initialized = KAL_FALSE;
 
   if (SPISlave_Info[port].initialized == KAL_FALSE)
    {
	   SPISlave_Info[port].initialized  = KAL_TRUE;
	   SPISlave_Info[port].ownerid=MOD_SPISLAVE_HISR;
      IRQ_Register_LISR(IRQ_SPISLV_CODE, SPI_SLV_LISR, "SPI_SLAVE");
      DRV_Register_HISR(DRV_SPISLV_HISR_ID, SPI_SLV_HISR);
      IRQSensitivity(IRQ_SPISLV_CODE, LEVEL_SENSITIVE);
      IRQUnmask(IRQ_SPISLV_CODE);
    }

}

DCL_HANDLE DclSpiSlave_Open(DCL_DEV dev, DCL_FLAGS flags)
{

   	DCL_HANDLE handle;
    kal_bool status;
    dev-=DCL_SPI_SLAVE;
	status=spi_slave_open(dev,(module_type)flags);

   if (KAL_TRUE==status)	
	 return (DCL_SPISLV_MAGIC_NUM | dev);
   else
   	 return STATUS_INVALID_DEVICE;
}

DCL_STATUS  DclSpiSlave_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	   DCL_DEV Device ;
      kal_bool status;
	   if(handle == STATUS_INVALID_DEVICE)
		   return STATUS_FAIL;
			   
		if (!DCL_SPISLV_IS_HANDLE_MAGIC(handle))
	  {
		 ASSERT(0);
		 return STATUS_INVALID_DCL_HANDLE;
	  }
					   
	Device = DCL_SPISLV_GET_DEV(handle);
	 if(Device > SPI_SLAVE_MAX_PORT_NUM) 
		   return  STATUS_FAIL; 

	switch (cmd)
			{
			case SPISLV_CMD_CONFIG_FORMAT:   /* cmd 1*/
					{
                       
						SPI_SLV_CTRL_CONFIG_FORMAT_T* prConfigFormat;
						prConfigFormat = &(data->rSPISLVConfigformat);
						
					    status=spi_slave_config_format(Device,prConfigFormat);
					}
				break;

		    case SPISLV_CMD_SET_BUFF_SIZE:    /* cmd 2*/
				{
				  SPI_SLV_CTRL_CONFIG_BUFF_SIZE_T* prConfigBuffSize;
				   prConfigBuffSize=&(data->rSPISLVConfigbuffsize);
				   		    status=spi_slave_config_buffer_size(Device,prConfigBuffSize);
		    	}

			    break;

			 case SPISLV_CMD_CONFIG_COMMANDS:   /* cmd 3*/
			 		{
						SPI_SLV_CTRL_CONFIG_COMMANDS_T* prConfigCommands;
                       	 prConfigCommands=&(data->rSPISLVConfigcommands);
				   		    status=spi_slave_config_commands(Device,prConfigCommands);
                   }

                  break;

			case SPISLV_CMD_START_DMA:      /* cmd 4*/
                    {
						SPI_SLV_CTRL_START_DMA_T* prStartDMA;
                       	 prStartDMA=&(data->rSPISLVStartdma);
				   		    status=spi_slave_start_DMA(Device,prStartDMA);
                   }

                  break;

		    case SPISLV_CMD_READ_DATA:      /* cmd 5*/

					{
                    	SPI_SLV_CTRL_READ_DATA_T* prReadData;
                       	 prReadData=&(data->rSPISLVReaddata);
				   		    status=spi_slave_read(Device,prReadData);
                    }
				   break;
          
		  case SPISLV_CMD_WRITE_DATA:       /* cmd 6*/
		  
				  {
					  SPI_SLV_CTRL_WRITE_DATA_T* prWriteData;
					   prWriteData=&(data->rSPISLVWritedata);
						  status=spi_slave_write(Device,prWriteData);
				  }
				 break;
			/*case SPISLV_CMD_GET_OWNER_ID:       /* cmd 7*
		  
				  {
					  SPI_SLV_CTRL_OWNER_T* prOwnerId;
					   prOwnerId=&(data->rSPISLVOwnerid);
					   prOwnerId->u4OwenrId=spi_slave_Get_OwnerID(Device);
				  }
				 break;	 
				*/ 
           	 default:
				return STATUS_INVALID_CMD;
}
	 if(KAL_FALSE==status)
		return STATUS_FAIL;
	else
		return STATUS_OK;

}


 DCL_STATUS DclSpiSlave_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_BUFF_LEN *returned_len, DCL_OPTIONS options)
 {

        SPI_SLV_CTRL_READ_DATA_T  data;
         DCL_STATUS status;
           data.u4OwenrId=(module_type)options;
		   data.u2data_length=buf_len;
	       data.pubuffer_addr=buff;
		 status =DclSpiSlave_Control(handle,SPISLV_CMD_READ_DATA,(DCL_CTRL_DATA_T*)&data);
		  return status;
 }
 DCL_STATUS DclSpiSlave_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_BUFF_LEN* written_len,DCL_OPTIONS options)
{
	 SPI_SLV_CTRL_WRITE_DATA_T data;
	  DCL_STATUS status;
		 data.u4OwenrId =(module_type)options;
	 data.u2data_length= buf_len;
	 data.pubuffer_addr= buff;
	  status =DclSpiSlave_Control(handle,SPISLV_CMD_WRITE_DATA,(DCL_CTRL_DATA_T*)&data);
	 return status;

}

 DCL_STATUS  DclSpiSlave_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, DCL_CALLBACK* callback,void* parameter) 
{	
  return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSpiSlave_Query(DCL_HANDLE handle, void* handle_status)
{
	return STATUS_UNSUPPORTED;
}
DCL_STATUS DclSpiSlave_QueryHandleWithMSG(msg_type msg_id,ilm_struct* ilm,DCL_HANDLE* handle)
{
	DCL_UINT8 port;
	switch(msg_id) 
	{
	  case MSG_ID_SPI_SLV_SET_READ_IND:
         {	   		 	
		 	port=((spi_slave_set_read_ind_struct*)(ilm->local_para_ptr))->port;
         }	
         break;	
      case MSG_ID_SPI_SLV_READ_DATA_IND:      		
         {
		 	port=((spi_slave_read_ind_struct*)(ilm->local_para_ptr))->port;
         }	   	
         break;

     case MSG_ID_SPI_SLV_SET_WRITE_IND:
         {	   		 	
		 	port=((spi_slave_set_write_ind_struct*)(ilm->local_para_ptr))->port;		 	
         }	
         break;	
      case MSG_ID_SPI_SLV_WRITE_DATA_IND:      		
         {
		 	port=((spi_slave_write_ind_struct*)(ilm->local_para_ptr))->port;
         }	   	
         break;
	         break;	
       case MSG_ID_SPI_SLV_ERROR_INFO_IND:      		
         {
		 	port=((spi_slave_error_message_ind_struct*)(ilm->local_para_ptr))->port;
         }	   	
         break;
	   default:
         break;
	}
	*handle = port | DCL_SPISLV_MAGIC_NUM;

}

DCL_STATUS DclSpiSlave_Close(DCL_HANDLE handle)
{

   
	kal_uint8 port;
    kal_bool status;
	module_type owner;
    port=handle-DCL_SPI_SLAVE;
	owner=spi_slave_Get_OwnerID(port);
	status=spi_slave_close(port,owner);

   if (KAL_TRUE==status)	
	 return STATUS_OK;
   else
   	 return STATUS_FAIL;
}

/*add for common dcl layer*/
extern DEV_Operations spislv_dev_operations = {DclSpiSlave_Open,DclSpiSlave_ReadData,DclSpiSlave_WriteData,DclSpiSlave_Control,NULL,NULL,DclSpiSlave_Close};/* add for dcl common layer */

extern DEV_Utility  spislv_dev_query={DclSpiSlave_QueryHandleWithMSG};
#else

  extern DEV_Operations spislv_dev_operations = {NULL,NULL,NULL,NULL,NULL,NULL,NULL};/* add for dcl common layer */

extern DEV_Utility  spislv_dev_query={NULL};
DCL_EVENT_MSG_PAIR spislv_event_msg_pairs[]={NULL,NULL};
DCL_EVENT_MSG_MAP spislv_event_msg_map={NULL,NULL};

#endif
