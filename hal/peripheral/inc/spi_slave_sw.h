#ifndef _SPI_SLV_SW
#define _SPI_SLV_SW
#include "dcl.h"
#include "kal_general_types.h"
#include "drv_comm.h"

#if defined(DRV_SPI_SLAVE_SUPPORT) 

/* SPI SLAVE  ports number. */
#define SPI_SLAVE_MAX_PORT_NUM 1

/* update FSM status */
#define SPI_SLAVE_UPDATE_STATUS(now_status)   \
  do {                                          \
      last2now_status[0]=last2now_status[1]; \
      last2now_status[1]=now_status;          \
  } while (0)

/*  clear bit MACRO for CRTL register */
#define CLEAR_SPI_CTRL_REG(bit_pos)             \
  do {                                          \
      kal_uint32 volatile temp_ctrl=0;        \
      temp_ctrl=DRV_SPISLV_Reg32(SPISLV_CTRL); \
      temp_ctrl &= (~(1 << bit_pos));          \
      DRV_SPISLV_WriteReg32(SPISLV_CTRL,temp_ctrl); \
  } while (0)

  /* set bit MACRO for CRTL register */
#define SET_SPI_CTRL_REG(bit_pos, status)       \
  do {                                          \
      kal_uint32 volatile temp_ctrl=0;        \
      temp_ctrl=DRV_SPISLV_Reg32(SPISLV_CTRL); \
      temp_ctrl |= (status << bit_pos);        \
      DRV_SPISLV_WriteReg32(SPISLV_CTRL,temp_ctrl); \
  } while(0)

  /* clear bit MACRO for STATUS  register */  
#define CLEAR_SPI_STATUS_REG(bit_pos)             \
	do {										  \
		kal_uint32 volatile temp_ctrl=0;		\
		temp_ctrl=DRV_SPISLV_Reg32(SPISLV_STATUS); \
		temp_ctrl &= (~(1 << bit_pos)); 		 \
		DRV_SPISLV_WriteReg32(SPISLV_STATUS,temp_ctrl); \
	} while (0)
	
  /* set bit MACRO for STATUS  register */  
#define SET_SPI_STATUS_REG(bit_pos, status)       \
	do {										  \
		kal_uint32 volatile temp_ctrl=0;		\
		temp_ctrl=DRV_SPISLV_Reg32(SPISLV_STATUS); \
		temp_ctrl |= (status << bit_pos);		 \
		DRV_SPISLV_WriteReg32(SPISLV_STATUS,temp_ctrl); \
	} while(0)

/* define common register operation */	
#define DRV_SPISLV_WriteReg32(addr,data)            DRV_WriteReg32(addr,data)          
#define DRV_SPISLV_Reg32(addr)                      DRV_Reg32(addr)

/* global variable extern  delcartion */
extern SPISlave_STRUCT SPISlave_Info[SPI_SLAVE_MAX_PORT_NUM];

/* function delcartion */
extern void  spi_slave_init(kal_uint8 port);

extern kal_bool spi_slave_open(kal_uint8 port,module_type ownerid );

extern kal_bool spi_slave_config_format(kal_uint8 port,SPI_SLV_CTRL_CONFIG_FORMAT_T *data);

extern kal_bool spi_slave_config_commands(kal_uint8 port,SPI_SLV_CTRL_CONFIG_COMMANDS_T *data);

extern kal_bool spi_slave_config_buffer_size(kal_uint8 port,SPI_SLV_CTRL_CONFIG_BUFF_SIZE_T *data);

extern module_type spi_slave_Get_OwnerID(kal_uint8 port);

extern kal_bool spi_slave_start_DMA(kal_uint8 port,SPI_SLV_CTRL_START_DMA_T *data);

extern kal_bool  spi_slave_read(kal_uint8 port,SPI_SLV_CTRL_READ_DATA_T *data);
extern kal_bool  spi_slave_write(kal_uint8 port,SPI_SLV_CTRL_WRITE_DATA_T *data);
extern kal_bool spi_slave_close(kal_uint8 port,module_type ownerid);
extern void    SPI_SLV_LISR();
extern void    SPI_SLV_HISR();

#endif
#endif /*_SPI_SLV_SW*/

