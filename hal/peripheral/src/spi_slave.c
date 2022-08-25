#include "spi_slave_sw.h"
#include "spi_slave_hw.h"
#include "intrCtrl.h"
#include "drv_hisr.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "stack_ltlcom.h"
#include "stack_config.h"
#include "drvpdn.h"
#include "dcl.h"

#if defined(DRV_SPI_SLAVE_SUPPORT) 
/* SPI Slave global information */
SPISlave_STRUCT SPISlave_Info[SPI_SLAVE_MAX_PORT_NUM];

/*SPI Slave 2 status--last status and  now status */
kal_uint8 last2now_status[2]={PWROFF_STA,PWROFF_STA};

/*SPI Slave FSM  */
SPI_SLV_ERROR_MSG_TYPE SPI_SLAVE_FSM[MAX_STATUS][MAX_OPERATION_CMD]={
{SPI_SLAVE_INVALID_OPERATION,    SPI_SLAVE_SUCCESS_OPERATION,  SPI_SLAVE_INVALID_OPERATION,          SPI_SLAVE_INVALID_OPERATION,   SPI_SLAVE_INVALID_OPERATION,         SPI_SLAVE_INVALID_OPERATION},
{SPI_SLAVE_SUCCESS_OPERATION,    SPI_SLAVE_INVALID_OPERATION,   SPI_SLAVE_SUCCESS_OPERATION,         SPI_SLAVE_INVALID_OPERATION,   SPI_SLAVE_SUCCESS_OPERATION,         SPI_SLAVE_INVALID_OPERATION},
{ERROR_PWROFF_AFTER_CONFIG_READ, SPI_SLAVE_INVALID_OPERATION,   ERROR_CONTINOUS_CONFIG_READ,         SPI_SLAVE_SUCCESS_OPERATION,   ERROR_CONFIG_WRITE_AFTER_CONFIG_READ,ERROR_WRITE_AFTER_CONFIG_READ},
{ERROR_PWROFF_AFTER_CONFIG_WRITE,SPI_SLAVE_INVALID_OPERATION,   ERROR_CONFIG_READ_AFTER_CONFIG_WRITE,ERROR_READ_AFTER_CONFIG_WRITE, ERROR_CONTINOUS_CONFIG_WRITE,        SPI_SLAVE_SUCCESS_OPERATION}
};

/*SPI Slave transfer length and address  */
kal_uint32 volatile spi_slave_transfer_len=0;
kal_uint32 volatile spi_slave_transfer_addr=0;

/*spi slave set clock polarity function*/
kal_bool spi_slv_set_clock_polarity(kal_uint8 port,
                                SPI_SLV_CPOL const cpol,module_type ownerid)
{
   kal_uint32 volatile temp_ctrl=0;
   kal_uint32 savedMask;
   EXT_ASSERT( (SPISlave_Info[port].ownerid == ownerid), (kal_uint32) ownerid, (kal_uint32)port, (kal_uint32)SPISlave_Info[port].ownerid);
  if ((cpol != SPI_SLV_CPOL_0) && (cpol != SPI_SLV_CPOL_1)) 
	return KAL_FALSE;
   savedMask = SaveAndSetIRQMask();
   temp_ctrl=DRV_SPISLV_Reg32(SPISLV_CTRL);
   temp_ctrl&=(~SLV_CPOL); //clear CPOL bit
   DRV_SPISLV_WriteReg32(SPISLV_CTRL,(temp_ctrl|(cpol<<SLV_CPOL_BIT)));
   RestoreIRQMask(savedMask);
   return KAL_TRUE;
}

/*spi slave set clock format function*/

kal_bool spi_slv_set_clock_format(kal_uint8 port,
                              SPI_SLV_CPHA const cpha,module_type ownerid)
{
    kal_uint32 volatile temp_ctrl=0;
	kal_uint32 savedMask;
    EXT_ASSERT( (SPISlave_Info[port].ownerid == ownerid), (kal_uint32) ownerid, (kal_uint32)port, (kal_uint32)SPISlave_Info[port].ownerid);
	if ((cpha != SPI_SLV_CPHA_0) && (cpha != SPI_SLV_CPHA_1))
     return KAL_FALSE;
	savedMask = SaveAndSetIRQMask();
	temp_ctrl=DRV_SPISLV_Reg32(SPISLV_CTRL);
	temp_ctrl&=(~SLV_CPHA); //clear CPHA bit
	DRV_SPISLV_WriteReg32(SPISLV_CTRL,(temp_ctrl|(cpha<<SLV_CPHA_BIT)));
	RestoreIRQMask(savedMask);
	return KAL_TRUE;
}

/*spi slave set  bit order (MSB/LSB) function*/
kal_bool spi_slv_set_msb(kal_uint8 port,
                     SPI_SLV_MLSB const tx_msb,
                     SPI_SLV_MLSB const rx_msb,module_type ownerid)

{
    kal_uint32 bit_pos;
	kal_uint32 savedMask;
    EXT_ASSERT( (SPISlave_Info[port].ownerid == ownerid), (kal_uint32) ownerid, (kal_uint32)port, (kal_uint32)SPISlave_Info[port].ownerid);

	if ((tx_msb != SPI_SLV_MSB) && (tx_msb != SPI_SLV_LSB))  
        return KAL_FALSE;
	if ((rx_msb != SPI_SLV_MSB) && (rx_msb != SPI_SLV_LSB))
       return KAL_FALSE;
     savedMask = SaveAndSetIRQMask();
    bit_pos = SLV_TXMSBF_BIT; 
	CLEAR_SPI_CTRL_REG(bit_pos);
	SET_SPI_CTRL_REG(bit_pos, tx_msb);	
    bit_pos = SLV_RXMSBF_BIT; 
	CLEAR_SPI_CTRL_REG(bit_pos);
	SET_SPI_CTRL_REG(bit_pos,rx_msb);
    RestoreIRQMask(savedMask);
     return KAL_TRUE;
}

/*spi slave send ilm message function*/
void SPI_slave_sendilm(kal_uint8 port,SPI_SLV_OPERATION_CMD action,SPI_SLV_SEND_ILM_TYPE_T ilm_type,msg_type msgid)
{
   ilm_struct *SPI_Slave_ilm;
   void *port_ptr=0;
   kal_uint8 last_sta_tmp=0;   
   if(port >= SPI_SLAVE_MAX_PORT_NUM)
      return;
   
   /*  check whether  ilm_type matched with msgid  */
  if(ilm_type!=NORMAL_TRANSFER && msgid!=MSG_ID_SPI_SLV_ERROR_INFO_IND)
  	  ASSERT(0); 
   if (SPISlave_Info[port].ownerid != MOD_SPISLAVE_HISR)
   {
      switch(msgid)
      {
      case MSG_ID_SPI_SLV_SET_READ_IND:
         {	   		 	
            spi_slave_set_read_ind_struct *tmp;      
            tmp = (spi_slave_set_read_ind_struct *) 
               construct_local_para(sizeof(spi_slave_set_read_ind_struct),TD_UL);
            tmp->transfer_length=spi_slave_transfer_len;
			tmp->transfer_id=spi_slave_transfer_addr;
			tmp->port=port;
            port_ptr = tmp;   	
         }	
         break;	
      case MSG_ID_SPI_SLV_READ_DATA_IND:      		
         {
            spi_slave_read_ind_struct *tmp;      
            tmp = (spi_slave_read_ind_struct *) 
               construct_local_para(sizeof(spi_slave_read_ind_struct),TD_UL);
            tmp->transfer_length=spi_slave_transfer_len;
			tmp->transfer_id=spi_slave_transfer_addr; 
			tmp->port=port;
            port_ptr = tmp;
         }	   	
         break;
      case MSG_ID_SPI_SLV_SET_WRITE_IND:   	   		
         {
            spi_slave_set_write_ind_struct *tmp;      
            tmp = (spi_slave_set_write_ind_struct *) 
               construct_local_para(sizeof(spi_slave_set_write_ind_struct),TD_UL);
            tmp->transfer_length=spi_slave_transfer_len;
			tmp->transfer_id=spi_slave_transfer_addr; 
			tmp->port=port;
            port_ptr = tmp;   		
         }	
         break;
      case MSG_ID_SPI_SLV_WRITE_DATA_IND:   	
         {
            spi_slave_write_ind_struct *tmp;      
            tmp = (spi_slave_write_ind_struct *) 
               construct_local_para(sizeof(spi_slave_write_ind_struct),TD_UL);
            tmp->transfer_length=spi_slave_transfer_len;
			tmp->transfer_id=spi_slave_transfer_addr;
			tmp->port=port;
            port_ptr = tmp; 	
         }	
         break;

	   case MSG_ID_SPI_SLV_ERROR_INFO_IND:   	
         {
            spi_slave_error_message_ind_struct *tmp;      
            tmp = (spi_slave_error_message_ind_struct *) 
               construct_local_para(sizeof(spi_slave_error_message_ind_struct),TD_UL);
			last_sta_tmp=last2now_status[0];
			if(FSM_ERROR==ilm_type)
               tmp->error_msg_index=SPI_SLAVE_FSM[last_sta_tmp][action];
			else if(READ_ERROR==ilm_type)
				tmp->error_msg_index=ERROR_READ_DATA_AFTER_CONFIG_READ;
			else if(WRITE_ERROR==ilm_type)
				tmp->error_msg_index=ERROR_WRITE_DATA_AFTER_CONFIG_WRITE;
			else 
				tmp->error_msg_index=ERROR_TIMEOUT_TRANSFER;
			tmp->port=port;
            port_ptr = tmp; 	
         }	
         break;
      default:
         break;   	
      }         
      DRV_BuildPrimitive(SPI_Slave_ilm,
         MOD_SPISLAVE_HISR,
         SPISlave_Info[port].ownerid,
         msgid,
         port_ptr);
      
      /*lint -e(534)*/msg_send_ext_queue(SPI_Slave_ilm);
   }
}

/*master  power on cmd  interrupt handler function*/
void SPIslv_CMD_PowerOn_Handler()

{
     kal_uint32 savedMask; 
	 
	 /* Update SPI slave status */
    savedMask = SaveAndSetIRQMask();
	 SPI_SLAVE_UPDATE_STATUS(PWRON_STA);
	 
	 /*set SLV_ON of SPISLV_STATUS  */
	  CLEAR_SPI_STATUS_REG(0);
      SET_SPI_STATUS_REG(0,1);
	    RestoreIRQMask(savedMask);
		
	  /*lock sleep mode, enable PDN*/
	PDN_CLR(PDN_SPISLV); 

}

/*master config read cmd   interrupt handler function*/
void SPIslv_CMD_CR_Handler()

{
	kal_uint8 last_sta_tmp=0;
       kal_uint32 savedMask; 

	/* Update SPI slave status */
 savedMask = SaveAndSetIRQMask();
	SPI_SLAVE_UPDATE_STATUS(CR_STA);
	last_sta_tmp=last2now_status[0];
  RestoreIRQMask(savedMask);

	/* read Transfer length  and Transfer addr */
	spi_slave_transfer_len=DRV_SPISLV_Reg32(SPISLV_TRANS_LEN);	 
	spi_slave_transfer_addr=DRV_SPISLV_Reg32(SPISLV_TRANS_ADDR);  
	
   /*firstly ,send  abnormal  message to user  */
   if((SPI_SLAVE_FSM[last_sta_tmp][CONDIG_READ_CMD]!=SPI_SLAVE_INVALID_OPERATION) &&(SPI_SLAVE_FSM[last_sta_tmp][CONDIG_READ_CMD]!=SPI_SLAVE_SUCCESS_OPERATION))
    SPI_slave_sendilm(0,CONDIG_READ_CMD,FSM_ERROR,MSG_ID_SPI_SLV_ERROR_INFO_IND); 
   
   /*secondly,send normal  message to user */
    SPI_slave_sendilm(0,CONDIG_READ_CMD,NORMAL_TRANSFER,MSG_ID_SPI_SLV_SET_WRITE_IND); 
}

/*master config write cmd   interrupt handler function*/
void SPIslv_CMD_CW_Handler()

{

	kal_uint8 last_sta_tmp=0;
	kal_uint32 savedMask;

   /* Update SPI slave status */
    savedMask = SaveAndSetIRQMask();
	 SPI_SLAVE_UPDATE_STATUS(CW_STA);
     last_sta_tmp=last2now_status[0];
	  RestoreIRQMask(savedMask);
	  
	/* read Transfer length  and Transfer addr */
	spi_slave_transfer_len=DRV_SPISLV_Reg32(SPISLV_TRANS_LEN);	  
	spi_slave_transfer_addr=DRV_SPISLV_Reg32(SPISLV_TRANS_ADDR);   

   
	/* send  abnormal  message to user   */
	 if((SPI_SLAVE_FSM[last_sta_tmp][CONFIG_WRITE_CMD]!=SPI_SLAVE_INVALID_OPERATION) &&(SPI_SLAVE_FSM[last_sta_tmp][CONFIG_WRITE_CMD]!=SPI_SLAVE_SUCCESS_OPERATION))
		 SPI_slave_sendilm(0,CONFIG_WRITE_CMD,FSM_ERROR,MSG_ID_SPI_SLV_ERROR_INFO_IND); 

     /* send normal  message to user */
  	SPI_slave_sendilm(0,CONFIG_WRITE_CMD,NORMAL_TRANSFER,MSG_ID_SPI_SLV_SET_READ_IND); 
 
}

/*master write cmd  interrupt handler function*/
void SPIslv_CMD_WR_Handler()

{

  kal_uint8 last_sta_tmp=0;
  kal_uint32 savedMask;

   /* Update SPI slave status */
     savedMask = SaveAndSetIRQMask();
	 SPI_SLAVE_UPDATE_STATUS(PWRON_STA);
     last_sta_tmp=last2now_status[0];
	   RestoreIRQMask(savedMask);
	   
   	/* send  abnormal  message to user   */
   if((SPI_SLAVE_FSM[last_sta_tmp][WRITE_CMD]!=SPI_SLAVE_INVALID_OPERATION) &&(SPI_SLAVE_FSM[last_sta_tmp][WRITE_CMD]!=SPI_SLAVE_SUCCESS_OPERATION))
    SPI_slave_sendilm(0,WRITE_CMD,FSM_ERROR,MSG_ID_SPI_SLV_ERROR_INFO_IND);
   
   /* send normal  message to user */
   SPI_slave_sendilm(0,WRITE_CMD,NORMAL_TRANSFER,MSG_ID_SPI_SLV_READ_DATA_IND); 

	 /* disable  DMA */
     CLEAR_SPI_CTRL_REG(SLV_RX_DMA_SW_READY_BIT);

}

/*master read cmd  interrupt handler function*/
void SPIslv_CMD_RD_Handler()

{
     kal_uint8 last_sta_tmp=0;
	  kal_uint32 savedMask;
	  
	/* Update SPI slave status */
	savedMask = SaveAndSetIRQMask();
	 SPI_SLAVE_UPDATE_STATUS(PWRON_STA);
	last_sta_tmp=last2now_status[0];
     RestoreIRQMask(savedMask);
	 
	/* send  abnormal  message to user   */
	 if((SPI_SLAVE_FSM[last_sta_tmp][READ_CMD]!=SPI_SLAVE_INVALID_OPERATION) &&(SPI_SLAVE_FSM[last_sta_tmp][READ_CMD]!=SPI_SLAVE_SUCCESS_OPERATION))
     SPI_slave_sendilm(0,READ_CMD,FSM_ERROR,MSG_ID_SPI_SLV_ERROR_INFO_IND); 

   /* send normal  message to user */
	SPI_slave_sendilm(0,READ_CMD,NORMAL_TRANSFER,MSG_ID_SPI_SLV_WRITE_DATA_IND); 
	 /* disable DMA */
	CLEAR_SPI_CTRL_REG(SLV_TX_DMA_SW_READY_BIT);
}

/*master power off cmd  interrupt handler function*/

void SPIslv_CMD_PowerOff_Handler()

{
     kal_uint8 last_sta_tmp=0;   
       kal_uint32 savedMask;
	   
	 /* Update SPI slave status */
	 	savedMask = SaveAndSetIRQMask();
	 SPI_SLAVE_UPDATE_STATUS(PWROFF_STA);
     last_sta_tmp=last2now_status[0];
        RestoreIRQMask(savedMask);
		
	 /* send  abnormal  message to user   */
	 if((SPI_SLAVE_FSM[last_sta_tmp][POWER_OFF_CMD]!=SPI_SLAVE_INVALID_OPERATION) &&(SPI_SLAVE_FSM[last_sta_tmp][POWER_OFF_CMD]!=SPI_SLAVE_SUCCESS_OPERATION))
       SPI_slave_sendilm(0,POWER_OFF_CMD,FSM_ERROR,MSG_ID_SPI_SLV_ERROR_INFO_IND); 

     /* Clear SLV_ON */
	   CLEAR_SPI_STATUS_REG(0);
      PDN_SET(PDN_SPISLV);	
}

/*spi slave timeout  interrupt handler function*/
void  SPIslv_CMD_TIMEOUT_Handler()
{

  /* Update SPI slave status */
 kal_uint32 savedMask;
    	savedMask = SaveAndSetIRQMask();
 SPI_SLAVE_UPDATE_STATUS(PWRON_STA);
     RestoreIRQMask(savedMask);
	 
/* send  abnormal  message to user	 */
SPI_slave_sendilm(0,POWER_OFF_CMD,TIMEOUT_ERROR,MSG_ID_SPI_SLV_ERROR_INFO_IND);
}

/*master read  error interrupt handler function*/
void  SPIslv_CMD_READ_ERROR_Handler()
{

kal_uint32 savedMask;

/* Update SPI slave status */	
  savedMask = SaveAndSetIRQMask();
SPI_SLAVE_UPDATE_STATUS(PWRON_STA);
	RestoreIRQMask(savedMask);
	
/* disable DMA */
CLEAR_SPI_CTRL_REG(SLV_TX_DMA_SW_READY_BIT);
CLEAR_SPI_CTRL_REG(SLV_RX_DMA_SW_READY_BIT);

/* send  abnormal  message to user	 */
SPI_slave_sendilm(0,POWER_OFF_CMD,READ_ERROR,MSG_ID_SPI_SLV_ERROR_INFO_IND); 
}

/*master write  error interrupt handler function*/
void  SPIslv_CMD_WRITE_ERROR_Handler()
{
  kal_uint32 savedMask;

/* Update SPI slave status */	
  savedMask = SaveAndSetIRQMask();
SPI_SLAVE_UPDATE_STATUS(PWRON_STA);
	RestoreIRQMask(savedMask);

/* disable DMA */
CLEAR_SPI_CTRL_REG(SLV_TX_DMA_SW_READY_BIT);
CLEAR_SPI_CTRL_REG(SLV_RX_DMA_SW_READY_BIT);

/* send  abnormal  message to user	 */
SPI_slave_sendilm(0,POWER_OFF_CMD,WRITE_ERROR,MSG_ID_SPI_SLV_ERROR_INFO_IND); 

}

/*spi slave LISR function*/
void SPI_SLV_LISR()
{
  /*trigger SPI HISR */
    IRQMask(IRQ_SPISLV_CODE); 
  
    /* activate driver HISR */
    drv_active_hisr(DRV_SPISLV_HISR_ID);
}

/*spi slave HISR function*/

void SPI_SLV_HISR()
{
  kal_uint32 volatile tmp=0;

/*read now interrupt status */
 tmp = DRV_SPISLV_Reg32(SPISLV_IRQ);

/* to execute  handler of every interrupt */
switch(tmp)
  {
     case SLV_POWERON_INT:
	 	SPIslv_CMD_PowerOn_Handler();
		break;	 	
	 case SLV_POWEROFF_INT:	
       SPIslv_CMD_PowerOff_Handler();
	   break;
	 case SLV_CRD_FINISH_INT:
	 	SPIslv_CMD_CR_Handler();
		break;
	 case SLV_CWR_FINISH_INT:
	 	SPIslv_CMD_CW_Handler();
		break;	
	 case SLV_RD_FINISH_INT:
	 	SPIslv_CMD_RD_Handler();
		break;
	 case SLV_WR_FINISH_INT:
	 	SPIslv_CMD_WR_Handler();
		break; 	
	 case SLV_TIMEOUT_ERR_INT:
	 	SPIslv_CMD_TIMEOUT_Handler();
	 case SLV_RD_ERR_INT:
	 	SPIslv_CMD_READ_ERROR_Handler();
		break; 	
	 case SLV_WR_ERR_INT:
	 	SPIslv_CMD_WRITE_ERROR_Handler();
		break;
	  default:
	  	ASSERT(0);
         break;
	}
    IRQClearInt(IRQ_SPISLV_CODE); 
    IRQUnmask(IRQ_SPISLV_CODE);  

}

/*spi slave open function*/
kal_bool spi_slave_open(kal_uint8 port,module_type ownerid )

{
    DCL_HANDLE gpio_handle;
     kal_uint32 volatile temp_ctrl=0;
	 kal_uint32 savedMask;

	if(port > SPI_SLAVE_MAX_PORT_NUM)
	   return KAL_FALSE;

/*step 1:  check if initilize ,and set owner_id*/
if (SPISlave_Info[port].initialized &&
	(SPISlave_Info[port].ownerid != (module_type)((kal_uint16)MOD_SPISLAVE_HISR + (kal_uint8)port)))
	return KAL_FALSE;
 SPISlave_Info[port].initialized = KAL_TRUE;
 SPISlave_Info[port].ownerid = ownerid;

  savedMask = SaveAndSetIRQMask();
  /*step2 : enable all interrupts */ 
 temp_ctrl=DRV_SPISLV_Reg32(SPISLV_CTRL);
 DRV_SPISLV_WriteReg32(SPISLV_CTRL,(temp_ctrl|SLV_INTERRUPT_ALL_ENABLE));
 
 /* set address and length type*/
  CLEAR_SPI_CTRL_REG(SLV_ADDR_SIZE_BIT);
  SET_SPI_CTRL_REG(SLV_ADDR_SIZE_BIT, 1);
 
  /* set slv sw decode  */	
  CLEAR_SPI_CTRL_REG(SLV_DECODE_BIT);
  SET_SPI_CTRL_REG(SLV_DECODE_BIT, 1);
  RestoreIRQMask(savedMask);
  return KAL_TRUE;


/* step 3: config gpio, please help config DRV_TOOL  fisrtly if convincence*/

   return KAL_TRUE;

}

/*spi slave config format(clock format/clock palarity/bit order/ decode type/transfer address type/transfer length type/timeout length)function*/
kal_bool spi_slave_config_format(kal_uint8 port,SPI_SLV_CTRL_CONFIG_FORMAT_T *data)

{
 module_type ownerid=data->ownerid;
 kal_bool status;
   status=spi_slv_set_clock_format( port,data->uclock_format,ownerid);
 if(status==KAL_FALSE)
 	ASSERT(0);
   status=spi_slv_set_clock_polarity( port,data->uclock_polarity,ownerid);
if(status==KAL_FALSE)
  ASSERT(0);
   status=spi_slv_set_msb(port,data->urx_msbf,data->utx_msbf,ownerid);
if(status==KAL_FALSE)
   ASSERT(0);

/*set timeout length */
DRV_SPISLV_WriteReg32(SPISLV_TIMEOUT_THR,data->u4timeout_len);
return KAL_TRUE;
}

/*spi slave config commands (PWRON/PWROFF/RD/WR/CR/CW/RS/WS) function*/
kal_bool spi_slave_config_commands(kal_uint8 port,SPI_SLV_CTRL_CONFIG_COMMANDS_T *data)
{
  kal_uint32 temp_command=0;
  module_type ownerid=data->ownerid;
  EXT_ASSERT( (SPISlave_Info[port].ownerid == ownerid), (kal_uint32) ownerid, (kal_uint32)port, (kal_uint32)SPISlave_Info[port].ownerid);
  temp_command=((data->ucmd_read)| (data->ucmd_write<<8) | (data->ucmd_read_sta<<16) |(data->ucmd_write_sta<<24));
   DRV_SPISLV_WriteReg32(SPISLV_CMD_0,temp_command);
  temp_command=((data->ucmd_config_read)| (data->ucmd_config_write<<8) | (data->ucmd_poweron<<16) | (data->ucmd_poweroff<<24));
   DRV_SPISLV_WriteReg32(SPISLV_CMD_1,temp_command);

   return KAL_TRUE;
}

/*spi slave config buffer size  function*/
kal_bool spi_slave_config_buffer_size(kal_uint8 port,SPI_SLV_CTRL_CONFIG_BUFF_SIZE_T *data)

{
	module_type ownerid=data->ownerid;
	EXT_ASSERT( (SPISlave_Info[port].ownerid == ownerid), (kal_uint32) ownerid, (kal_uint32)port, (kal_uint32)SPISlave_Info[port].ownerid);
    DRV_SPISLV_WriteReg32(SPISLV_BUF_SIZE,data->u4buffer_size);
    return KAL_TRUE;
}

/*spi slave get current owner  function*/
module_type spi_slave_Get_OwnerID(kal_uint8 port)
{
   return SPISlave_Info[port].ownerid;
}

/*spi slave get current owner  function*/
kal_bool spi_slave_start_DMA(kal_uint8 port,SPI_SLV_CTRL_START_DMA_T *data)

{
      kal_uint32 savedMask;
	module_type ownerid=data->ownerid;
	EXT_ASSERT( (SPISlave_Info[port].ownerid == ownerid), (kal_uint32) ownerid, (kal_uint32)port, (kal_uint32)SPISlave_Info[port].ownerid);

     savedMask = SaveAndSetIRQMask();
	  DRV_SPISLV_WriteReg32(SPISLV_BUF_BASEADDR,data->pubuffer_addr);  
	  if(data->uis_rx==KAL_TRUE)
   	  	{
   	  	    /*start RX DMA work*/
           CLEAR_SPI_CTRL_REG(SLV_RX_DMA_SW_READY_BIT);  
           SET_SPI_CTRL_REG(SLV_RX_DMA_SW_READY_BIT, data->fgdma_enable);   
	    }
	 else
	 	{
	 	  	 /*start TX DMA work*/
	       CLEAR_SPI_CTRL_REG(SLV_TX_DMA_SW_READY_BIT);  
           SET_SPI_CTRL_REG(SLV_TX_DMA_SW_READY_BIT, data->fgdma_enable);   
	  	}
	   RestoreIRQMask(savedMask);
    return KAL_TRUE;
}

/*spi slave read data  function*/
kal_bool  spi_slave_read(kal_uint8 port,SPI_SLV_CTRL_READ_DATA_T *data)

{
     kal_uint32 length_tmp=0;
	 kal_uint32 address_tmp=0;
	 module_type ownerid=data->u4OwenrId;
	 EXT_ASSERT( (SPISlave_Info[port].ownerid == ownerid), (kal_uint32) ownerid, (kal_uint32)port, (kal_uint32)SPISlave_Info[port].ownerid);
     length_tmp=DRV_SPISLV_Reg32(SPISLV_TRANS_LEN);
	 address_tmp=DRV_SPISLV_Reg32(SPISLV_TRANS_ADDR);    
     if ((kal_uint32)data->pubuffer_addr!=address_tmp && (kal_uint32)data->u2data_length!=length_tmp)
		ASSERT(0);
	 return KAL_TRUE;
}

/*spi slave write data  function*/
kal_bool  spi_slave_write(kal_uint8 port,SPI_SLV_CTRL_WRITE_DATA_T *data)

{
	kal_uint32 length_tmp=0;
	kal_uint32 address_tmp=0;
	module_type ownerid=data->u4OwenrId;
	EXT_ASSERT( (SPISlave_Info[port].ownerid == ownerid), (kal_uint32) ownerid, (kal_uint32)port, (kal_uint32)SPISlave_Info[port].ownerid);
	length_tmp=DRV_SPISLV_Reg32(SPISLV_TRANS_LEN);
	address_tmp=DRV_SPISLV_Reg32(SPISLV_TRANS_ADDR); 
     if ((kal_uint32)data->pubuffer_addr!=address_tmp && (kal_uint32)data->u2data_length!=length_tmp)
		ASSERT(0);
	return KAL_TRUE; 
}

/*spi slave close  function*/
kal_bool spi_slave_close(kal_uint8 port,module_type ownerid)
{
   if(port > SPI_SLAVE_MAX_PORT_NUM)
	   return KAL_FALSE;
    EXT_ASSERT((SPISlave_Info[port].ownerid == ownerid), (kal_uint32) ownerid, (kal_uint32)port, (kal_uint32)SPISlave_Info[port].ownerid);
	SPISlave_Info[port].initialized = KAL_FALSE;
	SPISlave_Info[port].ownerid = (module_type)((kal_uint16)MOD_SPISLAVE_HISR+(kal_uint8)port);
    return KAL_FALSE;
}

#endif

