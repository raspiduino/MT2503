/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   uart_test.c
 *
 * Project:
 * --------
 *   UART  HW  Verification
 *
 * Description:
 * ------------
 *   The file implements   testcases for  verifying UART  HW design 
 *
 * Author:
 * -------
 * -------
 *
  ****************************************************************************/

/*******************************************************************************
 * Include files
 *******************************************************************************/


#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "syscomp_config.h"
#include "task_config.h"
#include "stacklib.h"
#include "event_shed.h"
#include "app_buff_alloc.h"
#include "dcl.h"
#include "uart_internal.h"
#include "stack_ltlcom.h"
#include "kal_debug.h"


#define DCL_DEFINITION_PROTOTYPE
#include "dcl_uart.h"
#include "dcl_gpio.h"
#undef DCL_DEFINITION_PROTOTYPE

#include "uart_test.h"
#include "uart_sw.h"
//#include "smm_debug.h"  /* associated with sleep mode interface */

#if defined(__MAUI_BASIC__)

ilm_struct* pUartRxIlm; /* the msg which other module sent */

// control uart variable 

static DCL_HANDLE hgDVTuart;      /* UART device handle  */
static DCL_HANDLE hgUARTgpio;     /* handle for UART GPIO's */
static DCL_DEV     eTstUARTportNo = uart_port2; /* UART Test Port Number */
UART_CONFIG_T		 rConfigUART;			/* Variable to configure the UART */
kal_uint16			 u2LoopCnt; 			/* For Loop Count */

/* TX/RX Buffer Pointers*/
static kal_uint8* pu1TxData;      /* Buffer Pointer which Holds the TX data */
static kal_uint8* pu1RxData;      /* Buffer Pointer which Holds the RX data */
static kal_uint8* pu1RxCurrPtr;   /* This is the Pointer which indicates the Current Postion of Rx Buffer */
static kal_uint8* pu1TxCurrPtr;   /* This is the Pointer which indicates the Current Postion of Tx Buffer */


/* TX/RX Data length indicators */
/* Bhadra :should be Kal_uint32, other wise getting error*/
static kal_uint32 u2DataWritten;  /* This variable indicates the TX Data Length */
static kal_uint32 u2RemTxDataLen; /* This variable indicates the Remaning TX Data Length */
static kal_uint32 u2DataRead;     /* This variable indicates theRX Data Length */
static kal_uint32 u2RemRxDataLen; /* This variable indicates the Remaning RX Data Length */
static kal_uint16 u2DetectAutoB;


#define   MOD_DVT_UART              MOD_SSDBG1
#define UART_TOTAL_CNT  (uart_max_port - uart_port1) //subtract uart1, in case uart1 != 0 in future.

 extern kal_uint8 send_Txilm[];
 extern kal_uint8 send_Rxilm[];
 static kal_bool   fgUARTOpen[UART_TOTAL_CNT]; 
 static kal_uint32 u4OwenrId[UART_TOTAL_CNT];
 
 static PFN_DCL_CALLBACK pfUARTTxCallback[UART_TOTAL_CNT];
 static PFN_DCL_CALLBACK pfUARTRxCallback[UART_TOTAL_CNT];


 /* ADM Memroy for UART TX RX buffers   10K, 5K for Tx & 5K for RX  */
static kal_uint8 cDvtUartHeap[12 * 1024];   /* ADM Heap */
KAL_ADM_ID   pDvtUartAdmId;                  /* ADM Id     */


/********************************/
kal_uint32  debug_count=0;



 /*************************************************************************
 * FUNCTION
 *	alloc_uart_tx_rx_buffer
 *
 * DESCRIPTION
 *
 *	This function  makes user  alloc TX/RX memory buffer
 *
 *
 * PARAMETERS
 *	void
 *
 * RETURNS
 *	None
 *
 *************************************************************************/



 void  alloc_uart_tx_rx_buffer ()
   	{
      
    /* create Application Data Memroy for UART Data Buffers */
            pDvtUartAdmId= kal_adm_create(cDvtUartHeap, (12 * 1024), NULL,KAL_FALSE);
            if (pDvtUartAdmId == NULL)
            {
                kal_print("Error(COMM TASK) : ADM Create failed");
            }

             /* allocate the memroy for RX and TX Buffers */
            pu1TxData = (kal_uint8 *)kal_adm_alloc(pDvtUartAdmId,DVT_UART_PKT_LEN);
            pu1RxData = (kal_uint8 *)kal_adm_alloc(pDvtUartAdmId,DVT_UART_PKT_LEN);
   }
 /*************************************************************************
  * FUNCTION
  *  free_uart_tx_rx_buffer
  *
  * DESCRIPTION
  *
  *  This function	makes user	free  TX/RX memory buffer
  *
  *
  * PARAMETERS
  *  void
  *
  * RETURNS
  *  None
  *
  *************************************************************************/
 
 
 
  void	free_uart_tx_rx_buffer ()
	 {
	   
	    /* release the memroy allocated for TX & RX data Buffer */
            kal_adm_free(pDvtUartAdmId, pu1TxData);
            kal_adm_free(pDvtUartAdmId, pu1RxData);

			debug_count=0; /* reset this value */
	}


/*************************************************************************
* FUNCTION
*  uart_test_input
*
* DESCRIPTION
*
*  This function  makes user can input testcase number  ,and use which port to communicate
*
*
* PARAMETERS
*  input test case number,  uart port number
*
* RETURNS
*  None
*
*************************************************************************/


void uart_test_input(kal_uint16 *value,UART_PORT port)
{
	kal_uint32 result = 0;
		kal_uint8 str[30], input, offset;
	
		offset = 0;
	
		while (1)
		{
			input = U_GetUARTByte(port);
	
			if (input == 0x0d || input == 0x0a)
				break;
	
			if (input == ESCKEY)
				return;
	
			str[offset++] = input;
			dbg_print("%c", input);
		}
	
		str[offset] = 0;
	
		dbg_print("\r\n");
		sscanf(str, "%d", value);



}

/*************************************************************************
* FUNCTION
*  init_TxRx_buf
*
* DESCRIPTION
*
*  This function is to init TX/RX buffer
*
*
* PARAMETERS
*  input test case number,  uart port number
*
* RETURNS
*  None
*
*************************************************************************/


void init_TxRx_buf(kal_uint16 u2RemTxDataLen, kal_uint8 *pu1TxBuf, kal_uint8 *pu1RxBuf)
{
    kal_uint8 u1cnt = 0;  /* Loop Count */
    kal_uint16 u2LoopCnt; /* Loop Count */

    /* Write the TX and RX data buffers with default values*/
    for(u2LoopCnt = 0; u2LoopCnt < u2RemTxDataLen; u2LoopCnt++)
    {
        // init Rx buffer
        pu1RxBuf[u2LoopCnt] = 0x00;

        // init Tx buffer

        pu1TxBuf[u2LoopCnt] = 0x5a;

    }

}
/*************************************************************************
* FUNCTION
*  UART_Get_Port
*
* DESCRIPTION
*
*  This function  makes user can get which uart port are used right now 
*
*
* PARAMETERS
*   the handle 
*
* RETURNS
*  None
*
*************************************************************************/


DCL_DEV UART_Get_Port(DCL_HANDLE handle)
{
	DCL_DEV port;
	port = (handle) & (~0x40000000);
	return port;
}

/*************************************************************************
* FUNCTION
*  UART_Is_Handle_Magic
*
* DESCRIPTION
*
*  This function makes user know  whether it is uart handle 
*
*
* PARAMETERS
*   the handle 
*
* RETURNS
*  None
*
*************************************************************************/

kal_uint32 UART_Is_Handle_Magic(DCL_HANDLE handle)
{
	kal_uint32 magic_number;
	magic_number = (handle)& (0x40000000);
	return magic_number;
}

/*************************************************************************
* FUNCTION
*  DclUART_Initialize
*
* DESCRIPTION
*
*  This function makes UART HW init 
*
*
* PARAMETERS
*   void  
*
* RETURNS
*  None
*
*************************************************************************/


DCL_STATUS DclUART_Initialize(void)
{
   static kal_bool uart_initialized = KAL_FALSE;
   kal_uint32 i;

   
   if (uart_initialized == KAL_FALSE)
   {


	if(COMMUNICATE_PORT == uart_port1)
	{
     UART_HWInit(uart_port2);
     UART_Register(uart_port2,&UartDriver);
    }
	else
	   {
		 UART_HWInit(uart_port1);
		 UART_Register(uart_port1,&UartDriver);
	   }

	
#ifdef __UART3_SUPPORT__		 
      UART_HWInit(uart_port3);

	  UART_Register(uart_port3,&UartDriver);

#endif

   for(i=0;i<UART_TOTAL_CNT;i++)
      {
         	fgUARTOpen[i] = KAL_FALSE;
         	u4OwenrId[i] = MOD_NIL;
      }

  uart_initialized = KAL_TRUE;
      return STATUS_OK;
   }
   else
   {
      return STATUS_FAIL;
   }
}
/*************************************************************************
* FUNCTION
*  UART_Defaul_Callback
*
* DESCRIPTION
*
*  This function  is default callback function if user did not register specific function 
*
*
* PARAMETERS
*
* uart test port
*
* RETURNS
*  None
*
*************************************************************************/

static void UART_Defaul_Callback(UART_PORT port)
{
   ASSERT(0); // User has to register it's callback function.
   return;
}
/*************************************************************************
* FUNCTION
*  vDVT_UART_TxRxCallBack
*
* DESCRIPTION
*
*  This function  is uart txrx hisr CALLBACK FUNCTION 
*
*
* PARAMETERS
*
* uart test port
*
* RETURNS
*  None
*
*************************************************************************/


void vDVT_UART_TxRxCallBack(DCL_EVENT event)
{
    ilm_struct  *pHisr_ilm;
    kal_uint32  uiHisr_msg_type;
    module_type UART_HISR;

    /* The Souce Id of the Ilm */
    if (eTstUARTportNo == uart_port1)
    {
         UART_HISR = MOD_UART1_HISR;
    }
    else if (eTstUARTportNo == uart_port2)
    {
         UART_HISR = MOD_UART2_HISR;
    }
    else
    {
         UART_HISR = MOD_UART3_HISR;
    }

    /* If the Rx event */
    if(event == EVENT_UART_RX_READY_TO_READ)
    {
        /* uiHisr_msg_type = READY_TO_RECEIVE;    */
        uiHisr_msg_type = MSG_ID_UART_READY_TO_READ_IND;

        /* Intimate the comm task about the availability of data in RX FIFO */
        DRV_BuildPrimitive(pHisr_ilm,
                           UART_HISR,
                           MOD_DVT_UART,
                           uiHisr_msg_type,
                           NULL);
        msg_send_ext_queue(pHisr_ilm);
    }
    else /* Tx Event */
    {
        /* uiHisr_msg_type = READY_TO_WRITE;   */
        uiHisr_msg_type = MSG_ID_UART_READY_TO_WRITE_IND;
        /* Intimate the comm task about the availability of free space in TX FIFO */
        DRV_BuildPrimitive(pHisr_ilm,
                           UART_HISR,
                           MOD_DVT_UART,
                           uiHisr_msg_type,
                           NULL);
        msg_send_ext_queue(pHisr_ilm);
    }
}

/*************************************************************************
* FUNCTION
*  DclUART_Open
*
* DESCRIPTION
*
*  This function  makes user to open  UART
*
*
* PARAMETERS
*
* uart test port, flags( MCU or  VFIFO mode )
*
* RETURNS
*  None
*
*************************************************************************/


DCL_HANDLE DclUART_Open(DCL_DEV eDev, DCL_FLAGS flags)
{
   kal_bool   fgRet;
   DCL_DEV  port;
   module_type    ownerid;

   DCL_HANDLE handle;
   UART_CTRL_OPEN_T data;
   DCL_STATUS status;
   UART_CTRL_REG_TX_CB_T data1;
   UART_CTRL_REG_RX_CB_T data2;

   port = eDev;
   if(port > uart_max_port)
   {
      return STATUS_INVALID_DEVICE;
   }
   else if (fgUARTOpen[port] == KAL_TRUE)
   {
      return STATUS_ALREADY_OPENED;
   }
   else
   {
      kal_bool   fgUseVfifo;

      fgUseVfifo = KAL_FALSE;
      if (flags & FLAGS_UART_USE_VFIFO)
      {
         fgUseVfifo = KAL_TRUE;
      }
      ownerid = (module_type)(flags & ~(FLAGS_UART_USE_VFIFO));
#ifdef __UART3_SUPPORT__		 
      if ((port >= uart_port1) && (port <= uart_port3))
#else
      ASSERT((port==uart_port1)||(port==uart_port2));
      if ( (uart_port1 != port) && (uart_port2 != port) )
      {
         return STATUS_INVALID_DEVICE;
      }
      if ((port >= uart_port1) && (port <= uart_port2))
#endif
      {
         fgRet = UART_UseVFIFO(port, fgUseVfifo);
         if (KAL_TRUE == fgRet)  
         {
	         if(KAL_TRUE == fgUseVfifo) /* UART IS IN VFIFO DMA MODE */
            {

               UART_Register(port,&UartDriver_VFIFO);
            }
            else  /* UART IS IN MCU MODE */
            {
	             UART_Register(port,&UartDriver);
            }
            fgRet = U_Open(port, ownerid);

            ASSERT(KAL_TRUE == fgRet);
         }
         else
         {
            return STATUS_SET_VFIFO_FAIL;
         }
      }
      else
      {
         fgRet = U_Open(port, ownerid); 
 
      }
   }
   
   if (KAL_TRUE == fgRet)
   {
      fgUARTOpen[port] = KAL_TRUE;
      u4OwenrId[port] = ownerid;
      if((port <= uart_port3) && (ownerid == MOD_NIL))
      {
      
		  data1.u4OwenrId = MOD_NIL;
		  data1.func = UART_Defaul_Callback;	  
		  handle = DclSerialPort_Open(port,0);
		  DclSerialPort_Control(handle,SIO_CMD_REG_TX_CB, (DCL_CTRL_DATA_T*)&data1);
		  data2.u4OwenrId = MOD_NIL;
		  data2.func = UART_Defaul_Callback;
		  DclSerialPort_Control(handle,SIO_CMD_REG_RX_CB, (DCL_CTRL_DATA_T*)&data2);
       }
      return (0x40000000 | eDev);
   }

   return STATUS_FAIL;

}

/*************************************************************************
* FUNCTION
*  DclUART_WriteData
*
* DESCRIPTION
*
*  This function  makes user to put data into UART ring buffer( middle buffer)
*
*
* PARAMETERS
*
* handle,user defined  TXbuffer address,user defined  TX buffer length, TX buffer class(ISR or normal buffer)
*
* RETURNS

*  STATUS_OK  
*
*************************************************************************/

DCL_STATUS DclUART_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
   kal_uint16 u2RetLen;
   DCL_DEV port;
   UART_CTRL_PUT_BYTES_T data;
   UART_CTRL_PUT_UART_BYTE_T data1;
   char *bp;
   port = UART_Get_Port(handle);
   if (!UART_Is_Handle_Magic(handle))
   {
      ASSERT(0);
      return STATUS_INVALID_DCL_HANDLE;
   }


   if (uart_port_null == port)
   {
      return STATUS_INVALID_DCL_HANDLE;
   }
   if (KAL_FALSE == fgUARTOpen[port])
   {
      return STATUS_NOT_OPENED;
   }

   	data.u4OwenrId = u4OwenrId[port];
	data.u2Length = *buf_len;
	data.puBuffaddr = buff;
   if (options&OPTIONS_UART_WRITE_DATA_IN_ISR)
   {
	 DclSerialPort_Control(handle,SIO_CMD_PUT_ISR_BYTES, (DCL_CTRL_DATA_T*)&data);
	 u2RetLen = data.u2RetSize;
     }
   else
   {
       	for (bp= data.puBuffaddr; *bp; bp++)
	{
		//PutUARTByte(DBG_PRINT_PORT,*bp);	
	data1.uData = *bp;
	DclSerialPort_Control(handle,SIO_CMD_PUT_UART_BYTE, (DCL_CTRL_DATA_T*)&data1);
	debug_count++;
	}

	 //DclSerialPort_Control(handle,SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*)&data);
	 //u2RetLen = data.u2RetSize;
   }
   //*buf_len = u2RetLen;
   return STATUS_OK;
}
/*************************************************************************
* FUNCTION
*  DclUART_ReadData
*
* DESCRIPTION
*
*  This function  makes user to get data from UART ring buffer( middle buffer)
*
*
* PARAMETERS
*
* handle,user defined RX buffer address,user defined  RX buffer length, RX buffer class(ISR or normal buffer)
*
* RETURNS

*  STATUS_OK  
*
*************************************************************************/


DCL_STATUS DclUART_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
   kal_uint16 u2RetLen;
   DCL_DEV  port;
   UART_CTRL_GET_BYTES_T data;
    UART_CTRL_GET_UART_BYTE_T data_read; 
    DCL_BUFF *bp;
    port = UART_Get_Port(handle);
   if (!UART_Is_Handle_Magic(handle))
   {
      ASSERT(0);
      return STATUS_INVALID_DCL_HANDLE;
   }

   if (uart_port_null == port)
   {
      return STATUS_INVALID_DCL_HANDLE;
   }
   if (KAL_FALSE == fgUARTOpen[port])
   {
      return STATUS_NOT_OPENED;
   }

	data.u4OwenrId = u4OwenrId[port];
	data.u2Length = *buf_len;
	data.puBuffaddr = buff;
	data.pustatus = 0;
	bp= data.puBuffaddr;
	//DclSerialPort_Control(handle,SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*)&data);
   while(1)
 {

	DclSerialPort_Control(handle,SIO_CMD_GET_UART_BYTE, (DCL_CTRL_DATA_T*)&data_read);
       if(data_read.uByte==0x5a)
       	{
              *bp=data_read.uByte;
			  bp++;
			  debug_count++;
	       }

	   if(debug_count==2048)
    {
      dbg_print("TEST  SUCCESS");
	   break;
	   	}
   	}
	
   return STATUS_OK;
}
/*************************************************************************
* FUNCTION
*  UART_GetBytes
*
* DESCRIPTION
*
*  This function  makes user to get a byte from UART ring buffer( middle buffer)
*
*
* PARAMETERS
*
* port,RX buffer address, data length, status, owner_id
* RETURNS

*  STATUS_OK  
*
*************************************************************************/


kal_uint16 UART_GetBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid)
{

	DCL_HANDLE handle;
	UART_CTRL_GET_BYTES_T data;

	data.u4OwenrId = ownerid;
	data.u2Length = Length;
	data.puBuffaddr = Buffaddr;
	data.pustatus = status;
	handle = DclSerialPort_Open(port,0);
	DclSerialPort_Control(handle,SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*)&data);
	return data.u2RetSize;

}
/*************************************************************************
* FUNCTION
*  DclUART_Configure
*
* DESCRIPTION
*
*  This function  makes user to config UART DCB struct variable
*
*
* PARAMETERS
*
*  handle, configurate variable 
* RETURNS

*  STATUS_OK  
*
*************************************************************************/



DCL_STATUS DclUART_Configure(DCL_HANDLE handle, UART_CONFIG_T *configure)
{
   DCL_DEV port;
   UART_CTRL_DCB_T data;
	
   
   if (!UART_Is_Handle_Magic(handle))
   {
      ASSERT(0);
      return STATUS_INVALID_DCL_HANDLE;
   }
   port = UART_Get_Port(handle);
   if (uart_port_null == port)
   {
      return STATUS_INVALID_DCL_HANDLE;
   }
   if (KAL_FALSE == fgUARTOpen[port])
   {
      return STATUS_NOT_OPENED;
   }

	data.u4OwenrId = u4OwenrId[port];
	data.rUARTConfig.u4Baud = configure->u4Baud;
	data.rUARTConfig.u1DataBits = configure->u1DataBits;
	data.rUARTConfig.u1StopBits = configure->u1StopBits;
	data.rUARTConfig.u1Parity = configure->u1Parity;
	data.rUARTConfig.u1FlowControl = configure->u1FlowControl;
	data.rUARTConfig.ucXonChar = configure->ucXonChar;
	data.rUARTConfig.ucXoffChar = configure->ucXoffChar;
	data.rUARTConfig.fgDSRCheck = configure->fgDSRCheck;

	DclSerialPort_Control(handle,SIO_CMD_SET_DCB_CONFIG, (DCL_CTRL_DATA_T*)&data);

   return STATUS_OK;
}

/*************************************************************************
* FUNCTION
*  UART_Tx_Callback
*
* DESCRIPTION
*
*  This function  is to user's  registered TX callback function
*
*
* PARAMETERS
*
*  port
* RETURNS

*  void
*
*************************************************************************/


static void UART_Tx_Callback(UART_PORT port)
{
   if (send_Txilm[port])
   {
      (pfUARTTxCallback[port])(EVENT_UART_TX_READY_TO_WRITE);
      send_Txilm[port] = KAL_FALSE;
   }
   return;
}
/*************************************************************************
* FUNCTION
*  UART_Rx_Callback
*
* DESCRIPTION
*
*  This function  is to user's  registered RX callback function
*
*
* PARAMETERS
*
*  port
* RETURNS

*  void
*
*************************************************************************/

static void UART_Rx_Callback(UART_PORT port)
{
   if (send_Rxilm[port])
   {
      (pfUARTRxCallback[port])(EVENT_UART_RX_READY_TO_READ);
   }
   return;
}


/*************************************************************************
* FUNCTION
*  DclUART_RegisterCallback
*
* DESCRIPTION
*
*  This function  makes user to register callback function
*
*
* PARAMETERS
*
*  handle, event, callback function point
* RETURNS

*  STATUS_OK  
*
*************************************************************************/


DCL_STATUS DclUART_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
   DCL_DEV port;
   kal_bool   validEvent;
   UART_CTRL_REG_TX_CB_T data;
   UART_CTRL_REG_RX_CB_T data1;

   port = UART_Get_Port(handle);

   if (!UART_Is_Handle_Magic(handle))
   {
      ASSERT(0);
      return STATUS_INVALID_DCL_HANDLE;
   }
   if (uart_port_null == port)
   {
      return STATUS_INVALID_DCL_HANDLE;
   }
   if (KAL_FALSE == fgUARTOpen[port])
   {
      return STATUS_NOT_OPENED;
   }
   
   validEvent = KAL_FALSE;
   if (event & EVENT_UART_TX_READY_TO_WRITE)
   {
      pfUARTTxCallback[port] = callback;
      data.u4OwenrId =  u4OwenrId[port];
	  data.func = UART_Tx_Callback;

	  DclSerialPort_Control(handle,SIO_CMD_REG_TX_CB, (DCL_CTRL_DATA_T*)&data);
      validEvent = KAL_TRUE;
   }
   if (event & EVENT_UART_RX_READY_TO_READ)
   {
      pfUARTRxCallback[port] = callback;
     
	  data1.u4OwenrId = u4OwenrId[port];
	  data1.func = UART_Rx_Callback;
	  DclSerialPort_Control(handle,SIO_CMD_REG_RX_CB, (DCL_CTRL_DATA_T*)&data1);
      validEvent = KAL_TRUE;
   }
   if (KAL_FALSE == validEvent)
   {
      return STATUS_INVALID_EVENT;
   }
   return STATUS_OK;
}
/*************************************************************************
* FUNCTION
*  UART_Open
*
* DESCRIPTION
*
*  This function  is to open UART
*
*
* PARAMETERS
*
*  port,ownerid
* RETURNS

*  KAL_TRUE 
*
*************************************************************************/

kal_bool UART_Open(UART_PORT port, module_type ownerid)
{
	DCL_HANDLE handle;
    UART_CTRL_OPEN_T data;
	
	DCL_STATUS status;
	data.u4OwenrId = ownerid;
	handle = DclSerialPort_Open(port,0);
   	status = DclSerialPort_Control(handle,SIO_CMD_OPEN, (DCL_CTRL_DATA_T*)&data);
	 if(STATUS_OK != status)
		return KAL_FALSE;
	
}



/*************************************************************************
* FUNCTION
*  UART_Register_TX_cb
*
* DESCRIPTION
*
*  This function  is to register TX callback function
*
*
* PARAMETERS
*
*  port,ownerid.func
* RETURNS

*  void
*
*************************************************************************/

void UART_Register_TX_cb(UART_PORT port, module_type ownerid, UART_TX_FUNC func)
{

	DCL_HANDLE handle;
	UART_CTRL_REG_TX_CB_T data;
	data.u4OwenrId = ownerid;
	data.func = func;

	handle = DclSerialPort_Open(port,0);
	DclSerialPort_Control(handle,SIO_CMD_REG_TX_CB, (DCL_CTRL_DATA_T*)&data);

}
/*************************************************************************
* FUNCTION
*  UART_Register_RX_cb
*
* DESCRIPTION
*
*  This function  is to register RX callback function
*
*
* PARAMETERS
*
*  port,ownerid.func
* RETURNS

*  void
*
*************************************************************************/



void UART_Register_RX_cb(UART_PORT port, module_type ownerid, UART_RX_FUNC func)
{

	DCL_HANDLE handle;
	UART_CTRL_REG_RX_CB_T data;
	data.u4OwenrId = ownerid;
	data.func = func;

	handle = DclSerialPort_Open(port,0);
	DclSerialPort_Control(handle,SIO_CMD_REG_RX_CB, (DCL_CTRL_DATA_T*)&data);

}


/*************************************************************************
* FUNCTION
*  DclUART_Close
*
* DESCRIPTION
*
*  This function  is to close UART ,release UART handle 
*
*
* PARAMETERS
*
* handle
* RETURNS

*  STATUS_OK
*
*************************************************************************/

DCL_STATUS DclUART_Close(DCL_HANDLE handle)
{
   DCL_DEV port;
   UART_CTRL_CLOSE_T data;

   if (!UART_Is_Handle_Magic(handle))
   {
      ASSERT(0);
      return STATUS_INVALID_DCL_HANDLE;
   }
   port = UART_Get_Port(handle);
   if (uart_port_null == port)
   {
      return STATUS_INVALID_DCL_HANDLE;
   }
   if (KAL_FALSE == fgUARTOpen[port])
   {
      return STATUS_NOT_OPENED;
   }
   
   data.u4OwenrId = u4OwenrId[port];
   DclSerialPort_Control(handle,SIO_CMD_CLOSE, (DCL_CTRL_DATA_T*)&data);
   u4OwenrId[port] = MOD_NIL;
   fgUARTOpen[port] = KAL_FALSE;

   return STATUS_OK;
}
/*************************************************************************
* FUNCTION
*  UART_Close
*
* DESCRIPTION
*
*  This function  is to close UART Port
*
*
* PARAMETERS
*
* port,ownerid
* RETURNS

*  void
*
*************************************************************************/

void UART_Close(UART_PORT port, module_type ownerid)
{
	DCL_HANDLE handle;
	UART_CTRL_CLOSE_T data;
	data.u4OwenrId = ownerid;
	 handle = DclSerialPort_Open(port,0);
	DclSerialPort_Control(handle,SIO_CMD_CLOSE, (DCL_CTRL_DATA_T*)&data);		 
}
/*************************************************************************
* FUNCTION
*  UART_set_FIFO_trigger_
*
* DESCRIPTION
*
*  This function  is to set FIFO trigger level
*
*
* PARAMETERS
*
* port,tx_level,rx_level
* RETURNS

*  void
*
*************************************************************************/

void UART_set_FIFO_trigger_(DCL_DEV port, kal_uint16 tx_level, kal_uint16 rx_level)
{
		DCL_HANDLE handle;
		UART_CTRL_SFT_T data;
		data.tx_level = tx_level;
		data.rx_level = rx_level;
		
		handle = DclSerialPort_Open(port,0);
		DclSerialPort_Control(handle,UART_CMD_SET_FIFO_TRIGGER,(DCL_CTRL_DATA_T*)&data);
}
/*************************************************************************
* FUNCTION
*  UART_set_FIFO_trigger_
*
* DESCRIPTION
*
*  This function  is to set  UART baudrate
*
*
* PARAMETERS
*
* port,baudrate,ownerid
* RETURNS

*  void
*
*************************************************************************/

void UART_SetBaudRate(UART_PORT port, UART_baudrate baudrate, module_type ownerid)
{

	DCL_HANDLE handle;
	UART_CTRL_BAUDRATE_T data;
	data.u4OwenrId = ownerid;
	data.baudrate = baudrate;
	
	handle = DclSerialPort_Open(port,0);
	DclSerialPort_Control(handle,SIO_CMD_SET_BAUDRATE, (DCL_CTRL_DATA_T*)&data);

}
/*************************************************************************
* FUNCTION
*  UART_Purge
*
* DESCRIPTION
*
*  This function  is to clear UART FIFO
*
*
* PARAMETERS
*
* port,dir,ownerid
* RETURNS

*  void
*
*************************************************************************/

void UART_Purge(UART_PORT port, UART_buffer dir, module_type ownerid)
{

	DCL_HANDLE handle;
	UART_CTRL_PURGE_T data;

	data.u4OwenrId = ownerid;
	data.dir = dir;

	handle = DclSerialPort_Open(port,0);
	DclSerialPort_Control(handle,SIO_CMD_PURGE, (DCL_CTRL_DATA_T*)&data);
}
/*************************************************************************
* FUNCTION
*  Uart_test_init
*
* DESCRIPTION
*
*  This function  is to init UART paramter as default configruation
*
*
* PARAMETERS
*
* port,dir,ownerid
* RETURNS

*  void
*
*************************************************************************/


void Uart_test_init(kal_uint32 test_mode)
{
//  kal_uint32 test_mode=0;// for debugging

    DclUART_Initialize();

	
   /* Open the UART port for UART Testing with MCU mode(0) or  VIFIO Enable (1)*/
   if(test_mode==0)
                hgDVTuart = DclUART_Open(eTstUARTportNo,  MOD_DVT_UART );
   if(test_mode==1)
   hgDVTuart = DclUART_Open(eTstUARTportNo,  ( MOD_DVT_UART |FLAGS_UART_USE_VFIFO) );

   
                if(hgDVTuart == DCL_HANDLE_INVALID)
                {
                  dbg_print(" TEST FAILURE\r\n");
                }

                /* Register the call back function for WRITE event */
                DclUART_RegisterCallback(hgDVTuart,
                                         EVENT_UART_TX_READY_TO_WRITE,
                                         vDVT_UART_TxRxCallBack);

                /* Register the call back function for READ event */
                DclUART_RegisterCallback(hgDVTuart,
                                         EVENT_UART_RX_READY_TO_READ,
                                         vDVT_UART_TxRxCallBack);

}

/*************************************************************************
* FUNCTION
*  Uart_test_config
*
* DESCRIPTION
*
*  This function  is to config UART paramter as user's need
*
*
* PARAMETERS
*
* port,dir,ownerid
* RETURNS

*  void
*
*************************************************************************/

void Uart_test_config_start(kal_uint32 test_id,kal_uint32  TX_RX_FLAG)

{
/* Extact the Length Of Data to be TX */
		   u2RemTxDataLen = 2048;
		   u2DataWritten  =2048;

		   /* Extact the Length Of Data to be Receive */
		   u2DataRead	  = 1024;
		   u2RemRxDataLen = 1024;

		   /* Assing the TX & RX Data buffer base address */
		   pu1TxCurrPtr   = pu1TxData;
		   pu1RxCurrPtr   = pu1RxData;

		   /* Re Confgire the UART with default values */

		if (test_id==6)
	      rConfigUART.u4Baud = (kal_uint32)3000000;
		else
		  rConfigUART.u4Baud = (kal_uint32)115200;
		 
		   rConfigUART.u1DataBits	  = LEN_8;
		   rConfigUART.u1Parity 	  = PA_NONE;
		   rConfigUART.u1StopBits	  = SB_1;
		 if (test_id==3)
		   rConfigUART.u1FlowControl  = FC_SW;
		else
			rConfigUART.u1FlowControl  = FC_NONE;	
		   rConfigUART.fgDSRCheck	  = KAL_FALSE;
		   rConfigUART.ucXoffChar	  = 0x13;
		   rConfigUART.ucXonChar	  = 0x11;
		   if (STATUS_INVALID_CONFIGURATION ==
			   DclUART_Configure(hgDVTuart, &rConfigUART))
		   {
			   dbg_print(" TEST FAILURE\r\n");
		   }


		   init_TxRx_buf(u2RemTxDataLen, pu1TxData, pu1RxData);

		   /* Write the TX and RX data buffers with default values*/

		   if(TX_RX_FLAG==0)  /* 0 presents TX */
		   	{
		   DclUART_WriteData(hgDVTuart, (DCL_BUFF *)pu1TxCurrPtr,
							 (DCL_BUFF_LEN *)&u2DataWritten, 0x0);
		   /* If written Length is the equal to Specified Written Len then Read Data */
		   if(u2DataWritten == u2RemTxDataLen)
		   {
			   u2DataWritten  = 0;
			   u2RemTxDataLen = 0;
                 dbg_print(" TEST SUCCESS\r\n");
			}
		
		   else /* if No of bytes written is not equal to Length Of data to be Tx, the increament the TX data buff pointer accordingly */
		   {
			   /* Move the RX data buffer base pointer */
			   pu1TxCurrPtr   =  pu1TxCurrPtr+u2DataWritten;
			   /* Caliculate Length of Data still to be TX */
			   u2RemTxDataLen = u2RemTxDataLen-u2DataWritten;
			   u2DataWritten  = u2RemTxDataLen;
		   } 

		   	}

		   if(TX_RX_FLAG==1)  /* 1 presents RX */
		   	{


				 /* Read Data */
                DclUART_ReadData(hgDVTuart, (DCL_BUFF *) pu1RxCurrPtr,
                                 (DCL_BUFF_LEN *) &u2DataRead, 0x0);
                /* if No of bytes read is equal to Length Of data to be read then comapre the data
                   and send status message back to Host*/
                if( u2DataRead==u2RemRxDataLen)
                {
                    ;
		        }
            else /* if No of bytes written is not equal to Length Of data to be Tx, the increament the TX data buff pointer accordingly */
              {
                /* Move the RX data buffer base pointer */
                pu1TxCurrPtr   =  pu1TxCurrPtr+u2DataWritten;
                /* Caliculate Length of Data still to be TX */
                u2RemTxDataLen = u2RemTxDataLen-u2DataWritten;
                u2DataWritten  = u2RemTxDataLen;
             } /* if(u2DataWritten == u2RemTxDataLen) */

}
}



void uart_testcase1(ilm_struct* pUartRxIlm)
{

	alloc_uart_tx_rx_buffer (0);

	Uart_test_init(0);
    Uart_test_config_start(0,0); /* Tx  test */
   
   
    free_uart_tx_rx_buffer ();
}

void uart_testcase2(ilm_struct* pUartRxIlm)
{

	alloc_uart_tx_rx_buffer (0);

	Uart_test_init(0);
    Uart_test_config_start(0,1); /*Rx  test */
   
   
    free_uart_tx_rx_buffer ();
}


void uart_testcase3(ilm_struct* pUartRxIlm)
{

	alloc_uart_tx_rx_buffer (0);

	Uart_test_init(0);
    Uart_test_config_start(3,1); /*SW flow control for RX   test */
   
   
    free_uart_tx_rx_buffer ();
}

void uart_testcase4(ilm_struct* pUartRxIlm)
{

	alloc_uart_tx_rx_buffer ();

	Uart_test_init(0);
    Uart_test_config_start(3,0); /*/*SW flow control for TX   test */
   
   
    free_uart_tx_rx_buffer ();
}

void uart_testcase5(ilm_struct* pUartRxIlm)
{

	alloc_uart_tx_rx_buffer ();

	Uart_test_init(1);
    Uart_test_config_start(0,0); /*VFIFO DMA   test */
   
   
    free_uart_tx_rx_buffer ();
}

void uart_testcase6(ilm_struct* pUartRxIlm)
{

	alloc_uart_tx_rx_buffer ();

	Uart_test_init(0);
    Uart_test_config_start(6,0); /*High baudrate Test */
   
   
    free_uart_tx_rx_buffer ();
}

/*************************************************************************
* FUNCTION
*  ssdbg1_main_uart
*
* DESCRIPTION
*
*  This function is the  task 's entry function ,also  all testcases are listed in it, user can
*  select testcases by inputing number 
*
*
* PARAMETERS
*  task_entry_struct  pointer
*
* RETURNS
*  None
*
*************************************************************************/


void ssdbg1_main_uart(task_entry_struct *task_entry_ptr)
{
  
    ilm_struct current_ilm;
  
    kal_uint32 my_index;
	kal_uint32 testcase_id=999;
	kal_uint32 addr;  
    kal_uint16 input=999;  //the input testcase  number 
    //kal_get_my_task_index (&my_index);


   //ASSERT(task_info_g[task_entry_ptr->task_indx].task_ext_qid != KAL_NILQ_ID);

	   
	   while (1)
		   {


				 /* Receive msg (ilm) from any Module task */
				 receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid,
								   &current_ilm);
			   
			   /* log the ilm msg in Global Data */
				   pUartRxIlm=&current_ilm;  
			   
			  // stack_set_active_module_id ( my_index, MOD_SSDBG1 );

	       // stack_set_active_module_id(my_index, (*pUartRxIlm).dest_mod_id);
	   
	   
			   dbg_print("\r\n");
			   dbg_print("*********************************************************\r\n");
			   dbg_print("* 													  *\r\n");
			   dbg_print("* 			   MT6280 UART Basicload				  *\r\n");
			   dbg_print("* 													  *\r\n");
			   dbg_print("*********************************************************\r\n");
	   
			   dbg_print("============================\r\n");
			   dbg_print(" 1  UART TX setting Test(data valid)... \r\n");
			   dbg_print(" 2  UART RX setting Test(data valid)... \r\n");
			   dbg_print(" 3  UART TX SW Flow Control Test(data valid)...\r\n");
			   dbg_print(" 4  UART RX SW Flow Control Test(data valid)...\r\n");
			   dbg_print(" 5  UART Auto Baudrate(110-115200) Test...\r\n");
			   dbg_print(" 6  UART HIGH BAUDRATE Test(3M)...\r\n");
			   dbg_print(" 7  UART FIFO threshold trigger Test...\r\n");
			   dbg_print(" 8  UART SW Flow Control(0X13,0X11) Test...\r\n");
	   
	   
				dbg_print("input:");
			   uart_test_input(&input,COMMUNICATE_PORT);
			   dbg_print("%d\r\n", input);
	   
	   
			   switch (input)
			   {
				   case 1:
                           
                           dbg_print("this is the TX test case\r\n");
						    uart_testcase1(pUartRxIlm);
					   //uart_testcase1(pUartRxIlm);
					   /* the test case function here*/;
					   break;
	   
				   case 2:
                       
                          dbg_print("this is the RX test case\r\n");
						  uart_testcase2(pUartRxIlm);
						/* the test case function here*/;
					   break;
	   
				   case 3:
                           uart_testcase3(pUartRxIlm);
					   /* the test case function here*/;
					   break;
	   
				   case 4:
                            uart_testcase4(pUartRxIlm);
						 /* the test case function here*/;
					   break;
	   
				   case 5:
                          uart_testcase5(pUartRxIlm);
					   /* the test case function here*/;
					   break;
	   
				   case 6:
                           uart_testcase6(pUartRxIlm);
						 /* the test case function here*/;
					   break;
	   
				   case 7:
					  /* the test case function here*/;
					   break;
				  default:
					   break;
		   
	   }

             //  free_ilm(pUartRxIlm);
			   }
 
   

	  }

#else //#if defined(__MAUI_BASIC__) 
void ssdbg1_main_uart(task_entry_struct *task_entry_ptr)
{
 ;//for dummy function when DRV_UART_BASIC_LOAD_TEST is off
}
#endif



