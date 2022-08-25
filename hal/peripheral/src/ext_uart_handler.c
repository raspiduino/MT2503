/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ext_uart_handler.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Source file of APIs for EXT_UART DCL.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __8_WIRE_UART_SUPPORT__
//#include "kal_release.h"
#include "dcl.h"
#include "dcl_extuart.h"
#include "dcl_uart.h"
#include "uart_internal.h"
#include "uart_sw.h"
#include "kal_general_types.h"
#include "drv_comm.h"
#include "ext_uart.h"

ExtUartDriver_strcut* ExtUart_FUNC[MAX_UART_PORT_NUM];

//extern UARTStruct UARTPort[];

static DCL_STATUS EXT_UART_Handler(DCL_DEV dev,DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);

Seriport_HANDLER_T  ExtUart_Drv_Handler = {DCL_UART_TYPE, EXT_UART_Handler};

DCL_STATUS EXT_UART_Handler(DCL_DEV dev,DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	kal_bool return_flag = KAL_FALSE;
	DCL_STATUS return_status = STATUS_OK;
	if(dev >= MAX_UART_PORT_NUM)
      return STATUS_INVALID_DEVICE;
	switch (cmd)
		{
		
		case SWUART_CMD_INIT:
				{
					//ExtUart_FUNC[dev]->ExtUart_Init(dev);
					ExtUart_Init(dev);
				}
			break;
			
	/*	case SWUART_CMD_ENALBE_RI:
				{
					EXTUART_CTRL_RI_T*    prEnableRI;
					prEnableRI = &(data->rExtUARTCtrlRI);
					ExtUart_FUNC[dev]->CtrlRI(dev, (RIConfigure *)prEnableRI);		
				}
			break;
			
		case SWUART_CMD_DISABLE_RI:
				{
					EXTUART_CTRL_RI_T*   prDisableRI;
					prDisableRI = &(data->rExtUARTCtrlRI);
					ExtUart_FUNC[dev]->CtrlRI(dev, (RIConfigure *)prDisableRI);
				}
			break;*/
			
		case SWUART_CMD_CTRL_RI:
				{
					EXTUART_CTRL_RI_T* prCtrlRI;
					prCtrlRI = &(data->rExtUARTCtrlRI);
					ExtUart_FUNC[dev]->CtrlRI(dev, (RIConfigure *)prCtrlRI);
				}
			break;
			
		case SWUART_CMD_CTRL_DCD:
				{
                    kal_prompt_trace(MOD_DRV_HISR, "SWUART_CMD_CTRL_DCD level=%d",
                                     data->rExtUARTCtrlDCD.level);
				    ExtUart_FUNC[dev]->CtrlDCD(dev, data->rExtUARTCtrlDCD.level);
				}
			break;
			
		case SWUART_CMD_CTRL_DSR:
				{
                    kal_prompt_trace(MOD_DRV_HISR, "SWUART_CMD_CTRL_DSR level=%d",
                                     data->rExtUARTCtrlDSR.level);
					ExtUart_FUNC[dev]->CtrlDSR(dev, data->rExtUARTCtrlDSR.level);
				}
			break;
			
			default:
				return STATUS_INVALID_CMD;
		}

	return return_status;
}

#endif /* __8_WIRE_UART_SUPPORT__ */

