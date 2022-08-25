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
 *   ext_uart.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file for extended UART driver.
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
 * removed!
 * removed!
 * removed!
 *
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
 *============================================================================
 ****************************************************************************/
#ifdef __8_WIRE_UART_SUPPORT__

#ifndef __EXT_UART_H__
#define __EXT_UART_H__

#include "uart_sw.h"
#include "dcl.h"

#include "kal_general_types.h"
#include "drv_comm.h"


typedef enum
{
   ten_percent=0x00,
   twenty_percent,
   thirty_percent,
   fourty_percent,
   fifty_percent,
   sixty_percent,
   seventy_percent,
   eighty_percent,
   ninety_percent,
   full_percent
}RI_DutyCycle;

typedef enum
{
   level=0x00,  //RI signal type
   pulse
}RI_Signal;


typedef enum
{
   CycleTimer= 0x00,  //cycle timer
   DutyTimer
}TimerType;


typedef struct
{
      kal_bool                   enable;
	  kal_bool                   isactive;
	  RI_Signal           		 signaltype;        
	  IO_level					ri_state;
	  RI_DutyCycle				 duty;
	  kal_uint32				duration; // pulse duration
	  kal_uint32				 cycletime; //one period of ri pulse cycle
} RIConfigure;


typedef struct
{
      UART_PORT						port_no;
	  IO_level                      dsr_state;
	  IO_level						dcd_state;
	  RIConfigure					RIConfig;
} ExtUARTStruct;





typedef struct _extuartdriver
{
	//void (*ExtUart_Init)(UART_PORT port);
	void (*CtrlRI)(UART_PORT port, RIConfigure *RI);		
	void (*CtrlDSR)(UART_PORT port, IO_level SDSR);	
	void (*CtrlDCD)(UART_PORT port, IO_level SDCD);
}ExtUartDriver_strcut;

/*Function Declaration*/
extern ExtUartDriver_strcut ExtUartDriver;	

extern ExtUartDriver_strcut* ExtUart_FUNC[];

void ExtUart_CtrlRI(UART_PORT port, RIConfigure *RI);
void ExtUart_CtrlDSR(UART_PORT port, IO_level SDSR);
void ExtUart_CtrlDCD(UART_PORT port, IO_level SDCD);
void ExtUart_Init(UART_PORT port);
void DTR_EINT_CB();
void ExtUart_RIPulse_Set_Timer(UART_PORT port,kal_uint16 period,TimerType t);
void ExtUART_RI_Pulse(UART_PORT port);
ExtUARTStruct ExtUart_GetData(void);

#endif

#endif /* __8_WIRE_UART_SUPPORT__ */

