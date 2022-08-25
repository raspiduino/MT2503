#ifndef _DMA_CONFIG_MT6261_H
#define _DMA_CONFIG_MT6261_H

#include "reg_base.h"
#include "drv_comm.h"
#include "intrCtrl.h"
#include "drvpdn.h"

/*=======================================================================*/



/*=======================================================================*/

#define DMA_LESS_BURST_CTRL          //this means burst type is less than before chip
#define DMA_EXT_MASTER_CTRL
#define DMA_USE_AHB_BASE_ADDR

#define DMA_DEDICATED_CHANNEL_GROUP
#define DMA_NEW_HEAD_FILE_ARCHI
/*=======================================================================*/
//below is from dma_hw.h
#define DMA_CON_MASTER_RESERVED_0	(0)
#define DMA_CON_MASTER_RESERVED_1	(1)
#define DMA_CON_MASTER_MSDC		    (2)
#define DMA_CON_MASTER_SIM		    (3)
#define DMA_CON_MASTER_SIM2		    (4)
#define DMA_CON_MASTER_USB1TX		(5)
#define DMA_CON_MASTER_USB1RX		(6)
#define DMA_CON_MASTER_USB2TX		(7)
#define DMA_CON_MASTER_MSDC2		(8)
#define DMA_CON_MASTER_UART1TX		(9)
#define DMA_CON_MASTER_UART1RX		(10)
#define DMA_CON_MASTER_UART2TX		(11)
#define DMA_CON_MASTER_UART2RX		(12)
#define DMA_CON_MASTER_UART3TX		(13)
#define DMA_CON_MASTER_UART3RX		(14)
#define DMA_CON_MASTER_BTIFTX		(15)
#define DMA_CON_MASTER_BTIFRX		(16)
#define DMA_CON_MASTER_RESERVED_17	(17)

#define DMA_VFIFO_CH_S               9      // start  of DMA Virtual fifo 
#define DMA_VFIFO_CH_E               16      // end of DMA Virtual fifo   
#if defined (__BTMODULE_MT6261__)
#define __DMA_BT_VIRTUAL_FIFO__
#endif //   #if defined (__BTMODULE_MT6260__)   


/*======================================================================*/
//below is from dma_sw.h
#define DMA_MAX_CHANNEL         8
#define DMA_MAX_FULL_CHANNEL     1
#define DMA_FULL_CHANNEL_MASK (0x00001)


typedef enum {
	DMA_RESERVED_0,  // 0
    DMA_RESERVED_1,  // 1
    DMA_MSDC,        // 2
    DMA_SIM,         // 3
    DMA_SIM2,        // 4
    DMA_USB1TX,      // 5
    DMA_USB1RX,      // 6
    DMA_USB2TX,      // 7
	DMA_MSDC2,        // 8
	DMA_UART1TX,       // 9
    DMA_UART1RX,     // 10
    DMA_UART2TX,     // 11
    DMA_UART2RX,     // 12
	DMA_UART3TX,	 // 13
	DMA_UART3RX,	 // 14
    DMA_BTIFRX,      // 15
    DMA_BTIFTX,      // 16

/* Add Software DMA Master as below*/
   DMA_SW,
   DMA_H264,
   DMA_MPEG4,
   DMA_L1_R2BC, 
#if defined(__UMTS_TDD128_MODE__)
   DMA_TD_L1,
#endif   /*(__UMTS_TDD128_MODE__)*/
   DMA_IDLE
} DMA_Master;

typedef enum {
   VDMA_UART1TX_CH = 9,
   VDMA_UART1RX_CH = 10,
   VDMA_UART2TX_CH = 11,
   VDMA_UART2RX_CH = 12,
   VDMA_UART3TX_CH = 13,
   VDMA_UART3RX_CH = 14,
   VDMA_BTIFRX_CH = 15,
   VDMA_BTIFTX_CH = 16, 
} DMA_VFIFO_UART;

/*=======================================================================*/
/*=======================================================================*/

#endif //_DMA_HW_H

