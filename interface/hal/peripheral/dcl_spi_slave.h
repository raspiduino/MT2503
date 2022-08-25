#ifndef __DCL_SPI_SLAVE_H__
#define __DCL_SPI_SLAVE_H__
#include "drv_features.h"
#include "kal_general_types.h"
#include "dcl.h"

 

#ifdef DCL_DEFINITION_STRUCT
#ifndef  __DCL_SPI_SLAVE_STRUCT__
#define   __DCL_SPI_SLAVE_STRUCT__

/*DCL SPI SLAVE  EVENT*/
#define SPI_SLAVE_EVENTS \
    SPI_SLAVE_SET_READ=0x1700,\
    SPI_SLAVE_READ,\
    SPI_SLAVE_SET_WRITE,\
    SPI_SLAVE_WRITE,\
    SPI_SLAVE_ERROR_INFO,

/*DCL_CTRL_CMD for SPI SLAVE*/	 
    #define SPI_SLAVE_CMDS \
		     SPISLV_CMD_CONFIG_FORMAT,\
		     SPISLV_CMD_SET_BUFF_SIZE,\
		     SPISLV_CMD_CONFIG_COMMANDS,\
		     SPISLV_CMD_START_DMA,\
		     SPISLV_CMD_READ_DATA,\
		     SPISLV_CMD_WRITE_DATA,\
		     SPISLV_CMD_GET_OWNER_ID,

 /* Choose the desired clock polarities supported by the SPI SLV interface. */
	typedef enum SPI_SLV_CPOL {
	  SPI_SLV_CPOL_0 = 0,
       SPI_SLV_CPOL_1
	}SPI_SLV_CPOL;
			
  /* Choose the desired clock formats supported by the SPI SLV interface. */
	typedef enum SPI_SLV_CPHA {
	  SPI_SLV_CPHA_0 = 0,
	  SPI_SLV_CPHA_1
	}SPI_SLV_CPHA;
		
  /* Specify the MSB or LSB used by the SPI  SLV TX/RX operation.*/
	typedef enum SPI_SLV_MLSB {
	  SPI_SLV_LSB = 0,
	  SPI_SLV_MSB
	}SPI_SLV_MLSB;
				
/* SPI SLAVE FSM STATUS*/
  typedef enum {
				PWROFF_STA,
				PWRON_STA,
				CR_STA ,
				CW_STA,
				MAX_STATUS
			} SPI_SLV_STATUS;	

/* SPI SLAVE OPERATON CMD*/
  typedef enum {
			   POWER_OFF_CMD,
			   POWER_ON_CMD,
			   CONDIG_READ_CMD ,
			   READ_CMD ,
			   CONFIG_WRITE_CMD,
			   WRITE_CMD, 
			   MAX_OPERATION_CMD
			} SPI_SLV_OPERATION_CMD;	

/* SPI SLAVE ERROR MESSAGE TYPE*/
   typedef enum {
	  SPI_SLAVE_SUCCESS_OPERATION,
	  SPI_SLAVE_INVALID_OPERATION,
      ERROR_MSG_INFO_START=0x400,
	  ERROR_PWROFF_AFTER_CONFIG_READ,
	  ERROR_PWROFF_AFTER_CONFIG_WRITE ,
	  ERROR_CONTINOUS_CONFIG_READ ,
	  ERROR_CONFIG_READ_AFTER_CONFIG_WRITE,
	  ERROR_CONTINOUS_CONFIG_WRITE ,
	  ERROR_CONFIG_WRITE_AFTER_CONFIG_READ,
	  ERROR_WRITE_AFTER_CONFIG_READ,
	  ERROR_READ_AFTER_CONFIG_WRITE,
	  ERROR_READ_DATA_AFTER_CONFIG_READ,
	  ERROR_WRITE_DATA_AFTER_CONFIG_WRITE,
	  ERROR_TIMEOUT_TRANSFER
} SPI_SLV_ERROR_MSG_TYPE;

/* send ilm type */
typedef enum{
		   NORMAL_TRANSFER,
		   FSM_ERROR,
		   READ_ERROR,
		   WRITE_ERROR,
		   TIMEOUT_ERROR
		}SPI_SLV_SEND_ILM_TYPE_T;
	
/*spi slave infomation struct*/	
	typedef struct{
		module_type   ownerid;
		kal_uint8	  port;
		kal_bool	  initialized;
	}SPISlave_STRUCT;
	
/*spi slave config format struct*/		
	typedef struct {
	module_type             ownerid;
	SPI_SLV_CPOL			uclock_polarity;
	SPI_SLV_CPHA			uclock_format;
	SPI_SLV_MLSB			utx_msbf;
	SPI_SLV_MLSB			urx_msbf;
	DCL_UINT32              u4timeout_len;
	}SPI_SLV_CTRL_CONFIG_FORMAT_T;


/*  for  spi slave   TX/RX buffer size configuration  command */
 typedef struct
 {
     module_type  ownerid;
	DCL_UINT32 u4buffer_size;     
 }SPI_SLV_CTRL_CONFIG_BUFF_SIZE_T;

 /*  for  spi slave  owner ID  */
 typedef struct
 {
	 DCL_UINT32 u4OwenrId;
 }SPI_SLV_CTRL_OWNER_T;
 
 /*  for  spi slave  start dma command */
 typedef struct
 {
      module_type  ownerid;
	DCL_UINT8 *pubuffer_addr;     /* the buffer address which SPI SLAVE read or write */
	DCL_BOOL  uis_rx;
	DCL_BOOL  fgdma_enable;  /*the switch which  enables dma to work : 1--enable, 0--no effective */ 
 }SPI_SLV_CTRL_START_DMA_T;

 /*  for  spi slave  CMDs configuration  command,the CMDs should be  the same as  the cmd which MASTER  sent*/
 typedef struct
  {
     module_type  ownerid;
	 DCL_UINT8 ucmd_read;	          /* read cmd define  */ 
	 DCL_UINT8 ucmd_write;	          /* write cmd define  */ 
	 DCL_UINT8 ucmd_read_sta;	      /* read  status cmd define  */ 
	 DCL_UINT8 ucmd_write_sta;	      /* write status cmd  define  */ 
     DCL_UINT8 ucmd_config_read;	      /* config read  cmd  define  */ 
     DCL_UINT8 ucmd_config_write;	  /* config write cmd define  */ 
     DCL_UINT8 ucmd_poweron;	          /* power on cmd   define  */ 
     DCL_UINT8 ucmd_poweroff;	      /* power off  cmd  define  */  
  }SPI_SLV_CTRL_CONFIG_COMMANDS_T;


 /*  spi slave   read data cmds */
 typedef struct
 {
    DCL_UINT32 u4OwenrId;          /*the user task ID which use SPI SLAVE */
	DCL_UINT16 u2data_length;     /* the buffer size  which SPI SLAVE read or write */ 
	DCL_UINT8 *pubuffer_addr;     /* the buffer address which SPI SLAVE read or write */
	
 }SPI_SLV_CTRL_READ_DATA_T;   

 /*  spi slave   write data cmds */
 typedef struct
 {
    DCL_UINT32 u4OwenrId;          /*the user task ID which use SPI SLAVE */
	DCL_UINT16 u2data_length;     /* the buffer size  which SPI SLAVE read or write */
	DCL_UINT8 *pubuffer_addr;     /* the buffer address which SPI SLAVE read or write */
	
 }SPI_SLV_CTRL_WRITE_DATA_T; 

  /*  for  spi slave   CMDS CONTROL */

#define SPI_SLAVE_CTRLS		\
	 SPI_SLV_CTRL_CONFIG_FORMAT_T	 rSPISLVConfigformat; \
	 SPI_SLV_CTRL_CONFIG_BUFF_SIZE_T			rSPISLVConfigbuffsize; \
	 SPI_SLV_CTRL_START_DMA_T 	 rSPISLVStartdma; \
	 SPI_SLV_CTRL_CONFIG_COMMANDS_T	 rSPISLVConfigcommands; \
	 SPI_SLV_CTRL_READ_DATA_T		 rSPISLVReaddata;	   \
	 SPI_SLV_CTRL_WRITE_DATA_T		 rSPISLVWritedata;	  \
	 SPI_SLV_CTRL_OWNER_T		 rSPISLVOwnerid;

  /*start of local parameter struct*/
  typedef struct  
  { 	  
	  kal_uint8   ref_count;
	  kal_uint16  msg_len;			  /* LOCAL_PARA_HDR */	  
	  DCL_UINT16  transfer_length;
	  DCL_UINT8   transfer_id;      
	  kal_uint8	  port;             /*if  port >1, which should be added port variable later */  
	                              
  }spi_slave_set_read_ind_struct; 
  
  typedef struct  
  { 	  
	  kal_uint8   ref_count;
	  kal_uint16  msg_len;			  /* LOCAL_PARA_HDR */	  
	  DCL_UINT16  transfer_length;
	  DCL_UINT8   transfer_id; 
	  kal_uint8	  port;             /*if  port >1, which should be added port variable later */ 

  }spi_slave_read_ind_struct;
   
   typedef struct  
  { 	  
	   kal_uint8   ref_count;
	   kal_uint16  msg_len; 		   /* LOCAL_PARA_HDR */    
	   DCL_UINT16  transfer_length;
	   DCL_UINT8   transfer_id; 
	   kal_uint8   port;             /*if  port >1, which should be added port variable later */ 

  }spi_slave_set_write_ind_struct;

   typedef struct  
  { 	  
	  kal_uint8   ref_count;
	  kal_uint16  msg_len;			  /* LOCAL_PARA_HDR */	  
	  DCL_UINT16  transfer_length;
	  DCL_UINT8   transfer_id;
	  kal_uint8	  port;             /*if  port >1, which should be added port variable later */ 

  }spi_slave_write_ind_struct;


      typedef struct  
  { 	  
	  kal_uint8   ref_count;
	  kal_uint16  msg_len;			  /* LOCAL_PARA_HDR */	  
      SPI_SLV_ERROR_MSG_TYPE   error_msg_index;
	  kal_uint8	  port;             /*if  port >1, which should be added port variable later */ 

  }spi_slave_error_message_ind_struct;

#endif //#ifdef DCL_DEFINITION_STRUCT
#endif //#ifndef  __DCL_SPI_SLAVE_STRUCT__
	  

#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_SPI_SLAVE_H_PROTOTYPE__
#define __DCL_SPI_SLAVE_H_PROTOTYPE__

extern DCL_HANDLE  DclSpiSlave_Open(DCL_DEV dev, DCL_FLAGS flags);
extern DCL_STATUS DclSpiSlave_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_BUFF_LEN *returned_len, DCL_OPTIONS options);
extern DCL_STATUS DclSpiSlave_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_BUFF_LEN* written_len,DCL_OPTIONS options);
extern DCL_STATUS  DclSpiSlave_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
extern DCL_STATUS  DclSpiSlave_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, DCL_CALLBACK* callback,void* parameter); 
extern DCL_STATUS DclSpiSlave_Query(DCL_HANDLE handle, void* handle_status);
extern DCL_STATUS DclSpiSlave_Close(DCL_HANDLE handle);
extern DCL_STATUS DclSpiSlave_QueryHandleWithMSG(msg_type msg_id,ilm_struct* ilm,DCL_HANDLE* handle);
#endif //#ifdef DCL_DEFINITION_PROTOTYPE
#endif //#ifndef __DCL_UART_H_PROTOTYPE__


#endif


