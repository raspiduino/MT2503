#ifndef _SPI_SLV_HW_H
#define _SPI_SLV_HW_H

#include "reg_base.h"
#include "drvpdn.h"
#if defined(DRV_SPI_SLAVE_SUPPORT) 
/*use temp base address on MT6260  FPGA ,which will be defined in base_reg_mt6261.h on MT6261 project*/
//#define SPI_SLAVE_base  0xA0240000  

/*use NFI IRQ CHANNEL on MT6260 MT6260  FPGA ,which will be defined in  intrCtrl_mt6261.h on MT6261 project*/
//#define IRQ_SPISLV_CODE  IRQ_NFI_CODE

/*use NFI PDN on MT6260  FPGA ,which will be defined in  PDN file  on MT6261 project*/
//#define PDN_SPISLV      PDN_NFI

/* HW registers definition*/
#define SPISLV_TRANS_TYPE          (SPI_SLAVE_base+0x0000)
#define SPISLV_TRANS_LEN           (SPI_SLAVE_base+0x0004)
#define SPISLV_TRANS_ADDR          (SPI_SLAVE_base+0x0008)
#define SPISLV_CTRL                (SPI_SLAVE_base+0x000c)
#define SPISLV_STATUS              (SPI_SLAVE_base+0x0010)
#define SPISLV_TIMEOUT_THR         (SPI_SLAVE_base+0x0014)
#define SPISLV_SW_RST              (SPI_SLAVE_base+0x0018)
#define SPISLV_BUF_BASEADDR        (SPI_SLAVE_base+0x001c)
#define SPISLV_BUF_SIZE            (SPI_SLAVE_base+0x0020)
#define SPISLV_IRQ                 (SPI_SLAVE_base+0x0024)
#define SPISLV_EARLY_HALFSCK       (SPI_SLAVE_base+0x0028)
#define SPISLV_CMD_0               (SPI_SLAVE_base+0x002c)
#define SPISLV_CMD_1               (SPI_SLAVE_base+0x0030)

/*the bit value in SPISLV_CTRL register  */
#define  SLV_INTERRUPT_ALL_ENABLE   0x07F8
#define  SLV_CPOL                   0x0004
#define  SLV_CPHA                   0x0002
#define  SLV_TXMSBF                 0x1000
#define  SLV_RXMSBF                 0x0800
#define  SLV_ADDR_SIZE              0x0001
#define  SLV_TX_DMA_SW_READY        0x4000
#define  SLV_RX_DMA_SW_READY        0x2000


/*the STATUS bit value */
#define SLV_CRD_FINISH_INT       0x0001 
#define SLV_CWR_FINISH_INT       0x0002
#define SLV_RD_FINISH_INT        0x0004
#define SLV_WR_FINISH_INT        0x0008
#define SLV_POWEROFF_INT         0x0010
#define SLV_POWERON_INT          0x0020
#define SLV_RD_ERR_INT           0x0040
#define SLV_WR_ERR_INT           0x0080
#define SLV_TIMEOUT_ERR_INT      0x0100


/* he bit location in SPISLV_CTRL register*/
#define  SLV_CPOL_BIT                         0x0002
#define  SLV_CPHA_BIT                         0x0001
#define  SLV_RXMSBF_BIT                       0x000B
#define  SLV_TXMSBF_BIT                       0x000C
#define  SLV_ADDR_SIZE_BIT                    0x0000
#define  SLV_RX_DMA_SW_READY_BIT              0x000D
#define  SLV_TX_DMA_SW_READY_BIT              0x000E
#define  SLV_DECODE_BIT                       0x000F
#endif
#endif   /*_SPI_SLV_HW_H*/

