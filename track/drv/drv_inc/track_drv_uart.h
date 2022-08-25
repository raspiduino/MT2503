/******************************************************************************
 * track_drv_uart.h -
 *
 * Copyright .
 *
 * DESCRIPTION: -

 * modification history
 * --------------------
 * v1.0   2013-04-17,  wangqi create this file
 *
 ******************************************************************************/
 
#ifndef _TRACK_DRV_UART_H
#define _TRACK_DRV_UART_H

/****************************************************************************
* Include Files             包含头文件
*****************************************************************************/
#include "Device.h"
#include "track_os_data_types.h"
#include "stack_ltlcom.h"

/*******************************************************************************
 * Type Definitions
 *******************************************************************************/
#define EXT_UART_PORT               uart_port3

#define EXT_UART_BAND               9600

/*
 * general definitions
 */

extern void track_drv_uart_ready_read(void* msg);
extern void track_drv_uart_init(void);
extern kal_uint8 track_drv_uart_config(UART_PORT port, module_type ownerid, UART_baudrate uart_baud);
extern void track_drv_mgps_on();
extern void track_drv_mgps_off();
extern void track_uart_decode(char* buf, kal_uint16 len);
extern void track_cust_ubxcold(void);
extern kal_uint8 track_get_gps_ota(kal_uint8 flag);

extern void track_drv_uart_receice_data_notify(UART_PORT port, kal_uint8* data, kal_uint16 len);
extern kal_uint8 track_drv_uart_write(UART_PORT port, kal_uint8 *data, kal_uint16 len);
extern void track_drv_uart1_write_data(kal_uint8 *data, kal_uint16 len);
extern void track_drv_uart2_write_data(kal_uint8 *data, kal_uint16 len);
extern void track_drv_uart3_write_data(kal_uint8 *data, kal_uint16 len);
#endif  /* _TRACK_DRV_UART_H */

