/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *      download.h
 *
 * Project:
 * --------
 *   MTK3301 DOWNLOAD AGENT
 *
 * Description:
 * ------------
 *   This file is intends for download agent specific definition
 *
 *******************************************************************************/
#ifndef _DOWNLOAD_H_
#define _DOWNLOAD_H_

/* DA Version */
#define DA_MAJOR_VER    0x04
#define DA_MINOR_VER    0x00

/* Max Number of Load Sections */
#define MAX_LOAD_SECTIONS     10

// Max Die Number of MCP 
#define MAX_DIE_IN_MCP        2

/* RETURN VALUE */
#define HW_ERROR              0x1c
#define HW_RAM_OK             0xE0
#define HW_RAM_FLOARTING      0xE1
#define HW_RAM_UNACCESSABLE   0xE2
#define HW_RAM_ERROR          0xE3
#define SOC_FAIL              0x0c
#define SYNC_CHAR             0xc0
#define CONT_CHAR             0x69
#define STOP_CHAR             0x96
#define ACK                   0x5a
#define NACK                  0xa5
#define UNKNOWN_CMD           0xbb

/* FLASH OPERATION STATUS */
typedef enum {
    S_DONE = 0
   ,S_PGM_FAILED
   ,S_ERASE_FAILED
   ,S_TIMEOUT
   ,S_IN_PROGRESS
   ,S_CMD_ERR
   ,S_BLOCK_LOCKED_ERR
   ,S_BLOCK_UNSTABLE
   ,S_VPP_RANGE_ERR
   ,S_ERASE_ADDR_ERR
   ,S_ERASE_RANGE_ERR
   ,S_PGM_AT_ODD_ADDR
   ,S_PGM_WITH_ODD_LENGTH
   ,S_BUFPGM_NO_SUPPORT
   ,S_UNKNOWN_ERR
} STATUS_E;

/* COMMANDS */
#define DA_EXT_CLOCK_CMD      0xD0
#define DA_BBCHIP_TYPE_CMD      0xD1
#define DA_SPEED_CMD         0xD2
#define DA_MEM_CMD            0xD3
#define DA_FORMAT_CMD         0xD4
#define DA_WRITE_CMD         0xD5
#define DA_READ_CMD            0xD6
#define DA_WRITE_REG16_CMD      0xD7
#define DA_READ_REG16_CMD      0xD8
#define DA_FINISH_CMD         0xD9
#define DA_GET_DSP_VER_CMD      0xDA
#define DA_ENABLE_WATCHDOG_CMD   0xDB

/* SPEED_PARA */
typedef enum {
   UART_BAUD_921600  = 0x01,
   UART_BAUD_460800  = 0x02,
   UART_BAUD_230400  = 0x03,
   UART_BAUD_115200  = 0x04,
   UART_BAUD_57600   = 0x05,
   UART_BAUD_38400   = 0x06,
   UART_BAUD_19200   = 0x07,
   UART_BAUD_14400   = 0x08,
   UART_BAUD_9600    = 0x09,
   UART_BAUD_4800    = 0x0a,
   UART_BAUD_2400    = 0x0b,
   UART_BAUD_1200    = 0x0c,
   UART_BAUD_300     = 0x0d,
   UART_BAUD_110     = 0x0e,
   UART_BAUD_AUTO    = 0x0f,	
   
}UART_BAUDRATE;

typedef enum
{
   TIMEOUT_DATA = 0,
   CKSUM_ERROR,
   RX_BUFFER_FULL,
   TIMEOUT_CKSUM_LSB,
   TIMEOUT_CKSUM_MSB,
   ERASE_TIMEOUT,
   PROGRAM_TIMEOUT,
   RECOVERY_BUFFER_FULL,
   UNKNOWN_ERROR
}eRX_error;

/* DEVICE_INFO */
typedef enum
{
   DEVICE_TV0057A003AABD,
   DEVICE_LAST = DEVICE_TV0057A003AABD,
   DEVICE_UNKNOWN = 0xFF         // Unknown Device 
}DEVICE_INFO;

#endif