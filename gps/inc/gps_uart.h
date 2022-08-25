/***********************************************************************
*   This software/firmware and related documentation ("MediaTek Software") 
*   are protected under relevant copyright laws. The information contained 
*   herein is confidential and proprietary to MediaTek Inc. and/or its licensors.
*
*   Without the prior written permission of MediaTek Inc. and/or its licensors, 
*   any reproduction, modification, use or disclosure of MediaTek Software, and 
*   information contained herein, in whole or in part, shall be strictly prohibited.
*
*   MediaTek Inc. (C) [2007]. All rights reserved.
*
*************************************************************************/ 
/*******************************************************************************
 * Filename:
 * ---------
 *  gps_uart.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GPS task
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __GPS_SUPPORT__

#ifndef _GPS_UART_H_
#define _GPS_UART_H_

#include "kal_general_types.h"

extern kal_uint16 GPS_UART_Read(kal_uint8 port, kal_uint8 *buffer, kal_uint16 length);
extern kal_uint16 GPS_UART_Write(kal_uint8 port, kal_uint8 *buffer, kal_uint16 length);
extern kal_uint8 GPS_Get_UART_Port(void);
extern void GPS_SetUART(kal_uint32 baudrate, kal_uint32 flow_control_type);

typedef enum
{
    GPS_DBG_ERR = 0,
    GPS_DBG_WRN,
    GPS_DBG_INF,
    GPS_DBG_END
} GPS_DBG_LEVEL_T;

#define GPS_DBG_BUF_SZ 256

#ifdef __MNL_SUPPORT__
extern void gps_debug_print(GPS_DBG_LEVEL_T, char *, ...);
#define GPS_DEBUG_OUTPUT(level_num, ...) gps_debug_print(level_num, __VA_ARGS__)
#else
#define GPS_DEBUG_OUTPUT(level_num, ...) NULL
#endif

#endif /* _GPS_UART_H_ */

#endif /* __GPS_SUPPORT__ */
