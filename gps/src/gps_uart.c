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
 *  gps_uart.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __GPS_SUPPORT__
/* basic system service headers */
#include "dcl.h"            /* uart APIs*/
#include "gps_main.h"
#include "stack_config.h"
#include "kal_general_types.h"   
#include "kal_trace.h"   
#include "gps_uart.h"
#include "gps_trc.h"
    
extern kal_uint8 gps_uart_port;
#ifdef __MNL_SUPPORT__
extern kal_uint8 mnl_port;
#endif
extern gps_context_struct *gps_context_p;
#ifdef __MNL_SUPPORT__
extern kal_uint16 mtk_mnl_uart_read(kal_uint8 *buffer, kal_uint16 length);  // Porting layer implementation
extern kal_int32 mtk_gps_nmea_input(const kal_int8 *buffer, kal_uint32 length);  // Library function
extern kal_int32 mtk_gps_sys_nmea_output (char* buffer, kal_uint32 length);
extern kal_uint32 L1I_GetTimeStamp( void );
#endif
/*****************************************************************************
 * FUNCTION
 *  GPS_UART_Read
 * DESCRIPTION
 *  Read data from GPS UART port
 * PARAMETERS
 *  ilm_ptr     [IN]     message data
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint16 GPS_UART_Read(kal_uint8 port, kal_uint8 *buffer, kal_uint16 length)
{
#if defined(__SMART_PHONE_MODEM__)


    kal_uint16 readLen = 0;
    kal_uint8 status;
    DCL_HANDLE handle;
  	UART_CTRL_GET_BYTES_T data;
    
       
    data.u4OwenrId = MOD_GPS;
	  data.u2Length = length;
	  data.puBuffaddr = buffer;
    data.pustatus = &status;
	  handle = DclSerialPort_Open(port, 0);
	  DclSerialPort_Control(handle, SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*)&data);
	  readLen = data.u2RetSize;	

    return readLen;
    
#else
    
#ifdef __MNL_SUPPORT__
    kal_uint8 status;
    status = mtk_mnl_uart_read(buffer, length);
    return status;
#else

    kal_uint16 readLen = 0;
    kal_uint8 status;
    DCL_HANDLE handle;
	UART_CTRL_GET_BYTES_T data;
    
    if (gps_context_p->gps_state != GPS_POWEROFF_STATE)
    {
        if (port == gps_uart_port)
        {
#ifdef __GPS_SW_DBG__
            kal_mem_set(buffer, 0x0, length);                
#endif    
            data.u4OwenrId = MOD_GPS;
	        data.u2Length = length;
	        data.puBuffaddr = buffer;
            data.pustatus = &status;
	        handle = DclSerialPort_Open(port, 0);
	        DclSerialPort_Control(handle, SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*)&data);
	        readLen = data.u2RetSize;	
#ifdef __GPS_SW_DBG__
            kal_print_string_trace(MOD_GPS, TRACE_FUNC, "[UART RX] %s", buffer);
#endif    
        }
    }
    return readLen;

#endif

#endif /* __SMART_PHONE_MODEM__ */
}


/*****************************************************************************
 * FUNCTION
 *  GPS_UART_Write
 * DESCRIPTION
 *  GPS task main
 * PARAMETERS
 *  task_entry_ptr      [IN]        task struct pointer 
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint16 GPS_UART_Write(kal_uint8 port, kal_uint8 *buffer, kal_uint16 length)
{    
#if defined(__SMART_PHONE_MODEM__)

    kal_uint16 writeLen = 0;
    
    DCL_HANDLE handle;
	  UART_CTRL_PUT_BYTES_T data;
	    
    gps_uart_tx_sleep_handler();
       
    data.u4OwenrId = MOD_GPS;
	  data.u2Length = length;
	  data.puBuffaddr = buffer;
	  handle = DclSerialPort_Open(port, 0);
	  DclSerialPort_Control(handle,SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*)&data);
	  writeLen =  data.u2RetSize;
        
    return writeLen;
    
#else
    
#ifdef __MNL_SUPPORT__
    mtk_gps_nmea_input((kal_int8 *)buffer, length);
    return length; // should be no problem, just return the length
#else
    kal_uint16 writeLen = 0;
    if(gps_context_p->gps_state != GPS_POWEROFF_STATE)
    {
        DCL_HANDLE handle;
	    UART_CTRL_PUT_BYTES_T data;

        //TX data don't need disable sleep mode
        #ifndef __GPS_MT3333__
        gps_uart_tx_sleep_handler();
        #endif
        
        data.u4OwenrId = MOD_GPS;
	    data.u2Length = length;
	    data.puBuffaddr = buffer;
	    handle = DclSerialPort_Open(port, 0);
	    DclSerialPort_Control(handle,SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*)&data);
	    writeLen =  data.u2RetSize;
        
#ifdef __GPS_SW_DBG__
        kal_print_string_trace(MOD_GPS, TRACE_FUNC, "[UART TX] %s", buffer);
#endif  
    }   
    return writeLen;

#endif

#endif /* __SMART_PHONE_MODEM__ */
}

/*****************************************************************************
 * FUNCTION
 *  GPS_SetUART
 * DESCRIPTION
 *  Set the baudrate of UART 
 * PARAMETERS
 *  task_entry_ptr      [IN]        task struct pointer 
 * RETURNS
 *  void
 *****************************************************************************/
void GPS_SetUART(kal_uint32 baudrate, kal_uint32 flow_control_type)
{
    DCL_HANDLE handle;
    UART_CTRL_DCB_T data;
#if defined(__SMART_PHONE_MODEM__)
    data.u4OwenrId = MOD_GPS;	
#else   
 

#ifdef __MNL_SUPPORT__
    data.u4OwenrId = MOD_MNL;	
#else
    data.u4OwenrId = MOD_GPS;	
#endif

#endif /* __SMART_PHONE_MODEM__ */
   	
	data.rUARTConfig.u4Baud = baudrate;
	data.rUARTConfig.u1DataBits = LEN_8;
	data.rUARTConfig.u1StopBits = SB_1;
	data.rUARTConfig.u1Parity = PA_NONE;
	data.rUARTConfig.u1FlowControl = flow_control_type;
	data.rUARTConfig.ucXonChar = 0x11;
	data.rUARTConfig.ucXoffChar = 0x13;
	data.rUARTConfig.fgDSRCheck = (DCL_BOOLEAN)KAL_FALSE;
	
    handle = DclSerialPort_Open(gps_uart_port, 0);
	DclSerialPort_Control(handle, SIO_CMD_SET_DCB_CONFIG, (DCL_CTRL_DATA_T*)&data);
    GPS_DEBUG_OUTPUT(GPS_DBG_INF, "[GPS_SetUART]baudrate=%d", baudrate);
    GPS_TRACE((TRACE_INFO, GPS_TRC_INF_POWER_SET_BAUD, baudrate));
}
/*****************************************************************************
 * FUNCTION
 *  GPS_Get_UART_Port
 * DESCRIPTION
 *  Get the UART port
 * PARAMETERS
 *  task_entry_ptr      [IN]        task struct pointer 
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 GPS_Get_UART_Port(void)
{
#if defined(__SMART_PHONE_MODEM__)

    return gps_uart_port;
    
#else

#ifdef __MNL_SUPPORT__
    return mnl_port;
#else
    return gps_uart_port;
#endif

#endif /* __SMART_PHONE_MODEM__ */
}

#ifdef __MNL_SUPPORT__

kal_bool fgVirtualUART_OK = KAL_FALSE;

/*****************************************************************************
 * FUNCTION
 *  gps_debug_print
 * DESCRIPTION
 *  output debug log to *.dbg file (when define __MNL_SUPPORT__)
 * PARAMETERS
 *  level_num    [IN]   one of ERR, WRN, INF
 * RETURNS
 *  void
 *****************************************************************************/
void gps_debug_print(GPS_DBG_LEVEL_T level_num, char *fmt, ...)
{
    va_list args;
    char szBuf[GPS_DBG_BUF_SZ] = {0};
    int length;

    char *level_str[] = {"ERR", "WRN", "INF"};

    if(level_num >= GPS_DBG_END)
    {
        kal_print_string_trace(MOD_GPS, TRACE_WARNING, 
            "Use illegal DEBUG_OUTPUT level!");
        return;
    }
    
    //sprintf(szBuf, "GPSD,%s[%06d]", level_str[level_num], L1I_GetTimeStamp());
    sprintf(szBuf, "GPSD,%s[%06u ms]", level_str[level_num], 
            (unsigned int) mtk_gps_sys_time_tick_get());
    length = strlen(szBuf);
    
    va_start(args, fmt);
    vsnprintf(szBuf + length, GPS_DBG_BUF_SZ - length - 2 -1, fmt, args );
    va_end(args);
    
    length = strlen(szBuf);
    sprintf(szBuf + length, "\r\n");
    
    if(KAL_FALSE == fgVirtualUART_OK)
    {
        kal_print_string_trace(MOD_GPS, TRACE_WARNING, 
            "Use DEBUG_OUTPUT before VirtualUART init!");
        
        kal_print_string_trace(MOD_GPS, TRACE_INFO, szBuf);
        return;
    }

    mtk_gps_sys_nmea_output(szBuf, length + 2);
}

#endif /* __MNL_SUPPORT__ */

#endif /* __GPS_SUPPORT__ */
