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
 *    dma_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for DMA driver.
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _DMA_HW_H
#define _DMA_HW_H

#include "reg_base.h"
#include "drv_comm.h"
#include "intrCtrl.h"
#include "drvpdn.h"

/*===================================================================*/
// below is for new dma head file archi.
/*===================================================================*/
#if defined(MT6261) || defined(MT2501) || defined(MT2502)
#include "dma_config_mt6261.h"
#else
#undef DMA_NEW_HEAD_FILE_ARCHI
#endif

#if defined(DMA_NEW_HEAD_FILE_ARCHI)
#include "dma_hw_v2.h"
#else // this is the old path

/*===================================================================*/


#if ( (defined(MT6205)) || (defined(MT6205B)) || (defined(MT6208)) || (defined(FPGA)) )
   /*****************
    * DMA Registers *
    *****************/
   #define DMA_GLBSTS                  (DMA_base+0x0000) /*Global status register */
   /* ch#1 (USB) */                    
   #define DMA1_MSBSRC                 (DMA_base+0x0004) /*Address source MSB bits */
   #define DMA1_LSBSRC                 (DMA_base+0x0008) /*Address source LSB bits */
   #define DMA1_MSBDST                 (DMA_base+0x000C) /*Address dest MSB bits   */
   #define DMA1_LSBDST                 (DMA_base+0x0010) /*Address dest LSB bits   */
   #define DMA1_COUNT                  (DMA_base+0x0014) /*Transfer count          */
   #define DMA1_CONTRL                 (DMA_base+0x0018) /*Control register        */
   #define DMA1_START                  (DMA_base+0x001C) /*Start register          */
   #define DMA1_INTSTS                 (DMA_base+0x0020) /*Interrupt status        */
   #define DMA1_ACKINT                 (DMA_base+0x0024) /*Interrupt acknowledge   */
   /* ch#2 (DSP) */                    
   #define DMA2_MSBSRC                 (DMA_base+0x0104) /*Address source MSB bits */
   #define DMA2_LSBSRC                 (DMA_base+0x0108) /*Address source LSB bits */
   #define DMA2_MSBDST                 (DMA_base+0x010C) /*Address dest MSB bits   */
   #define DMA2_LSBDST                 (DMA_base+0x0110) /*Address dest LSB bits   */
   #define DMA2_COUNT                  (DMA_base+0x0114) /*Transfer count          */
   #define DMA2_CONTRL                 (DMA_base+0x0118) /*Control register        */
   #define DMA2_START                  (DMA_base+0x011C) /*Start register          */
   #define DMA2_INTSTS                 (DMA_base+0x0120) /*Interrupt status        */
   #define DMA2_ACKINT                 (DMA_base+0x0124) /*Interrupt acknowledge   */
                                       
                                       
   #define DMA_GLBSTS_RUN1             0x0001
   #define DMA_GLBSTS_RUN2             0x0010
   #define DMA_GLBSTS_IT1              0x0002
   #define DMA_GLBSTS_IT2              0x0020
                                       
   #define DMA_CON_SIZEMASK            0x0003
                                       
   #define DMA_CON_SIZE_MASK           0x0003
   #define DMA_CON_SINC                0x0004
   #define DMA_CON_DINC                0x0008
   #define DMA_CON_DRQ                 0x0010   /*1: HW management,0:SW */
   #define DMA_CON_TMOD                0x0020   /*1: Block mode, 0:Single mode*/
   #define DMA_CON_MAS                 0x0100   /*00:,01:UART1 Rx(1)/UART1 Tx(2),10: UART2 tx(1),UART2 rx(2),11:SIM*/
   #define DMA_CON_CYCLE_MASK          0x3e00   /* Burst mode cycle */
   #define DMA_CON_ITEN                0x8000   /*Interrupt enable*/
   
   //Size = 8bit, sinc en, dinc disable, hw management, 
   //1 trans/dma cycle, UART1 master,Interrupt enable
   #define DMA_CON_UART1TxNormal       0x8034
   //Size = 8bit, sinc disable, dinc enable, hw management, 
   //1 trans/dma cycle, UART1 master,Interrupt enable
   #define DMA_CON_UART1RxNormal       0x8038
   //Size = 8bit, sinc en, dinc disable, hw management, 
   //1 trans/dma cycle, UART2 master,Interrupt enable
   #define DMA_CON_UART2TxNormal       0x8054
   //Size = 8bit, sinc disable, dinc enable, hw management, 
   //1 trans/dma cycle, UART2 master,Interrupt enable
   #define DMA_CON_UART2RxNormal       0x8058
   //Size = 32bit, sinc en, dinc disable, hw management, 
   //1 trans/dma cycle, USB master,Interrupt enable
   #define DMA_CON_USBTxNormal         0x8016
   //Size = 32bit, sinc disable, dinc enable, hw management, 
   //1 trans/dma cycle, USB master,Interrupt enable
   #define DMA_CON_USBRxNormal         0x801a
   
   #define DMA_START_BIT               0x8000
   #define DMA_STOP_BIT                0x0000
   
   #define DMA_INTSTS_MASK             0x8000
   
   #define DMA_ACKINT_BIT              0x8000

#elif defined(TK6516) || defined(MT6516)

   /*1 is full size, 4~5 are half size*/
   #define DMA_GLBSTA                  (DMA_base+0x0000)
   #define DMA_SRC(_n)                 (DMA_base+0x0100)                  /*_n = 1 only*/
   #define DMA_DST(_n)                 (DMA_base+0x0004+(0x0100))         /*_n = 1 only*/   
   #define DMA_WPPT(_n)                (DMA_base+0x0008+(0x0100*(_n)))    /*_n = 1,4,5*/
   #define DMA_WPTO(_n)                (DMA_base+0x000c+(0x0100*(_n)))    /*_n = 1,4,5*/   
   #define DMA_COUNT(_n)               (DMA_base+0x0010+(0x0100*(_n)))    /*_n = 1,4,5*/  
   #define DMA_CON(_n)                 (DMA_base+0x0014+(0x0100*(_n)))    /*_n = 1,4,5*/   
   #define DMA_START(_n)               (DMA_base+0x0018+(0x0100*(_n)))    /*_n = 1,4,5*/ 
   #define DMA_INTSTA(_n)              (DMA_base+0x001c+(0x0100*(_n)))    /*_n = 1,4,5*/
   #define DMA_ACKINT(_n)              (DMA_base+0x0020+(0x0100*(_n)))    /*_n = 1,4,5*/
   #define DMA_RLCT(_n)                (DMA_base+0x0024+(0x0100*(_n)))    /*_n = 1,4,5*/  /*DEBUG*/
   #define DMA_LIMITER(_n)             (DMA_base+0x0028+(0x0100*(_n)))    /*_n = 1,4,5*/
   #define DMA_PGMADDR(_n)             (DMA_base+0x002c+(0x0100*(_n)))    /*_n = 1,4,5*/

   #define DMA_GLBSTA_RUN(_n)          (0x00000001 << (2*((_n)-1)))  /*_n = 1,4,5*/
   #define DMA_GLBSTA_IT(_n)           (0x00000002 << (2*((_n)-1)))  /*_n = 1,4,5*/

   #define DMA_COUNT_MASK              0xffff /*6516: 0x00FF??*/

   /*DMA_CON*/
   #define DMA_CON_SIZE_MASK           0x00000003
   #define DMA_CON_SIZE_BYTE           0x00000000
   #define DMA_CON_SIZE_SHORT          0x00000001
   #define DMA_CON_SIZE_LONG           0x00000002

   #define DMA_CON_SINC                0x00000004
   #define DMA_CON_DINC                0x00000008
   #define DMA_CON_DRQ                 0x00000010  /*1:hw, 0:sw*/

   #define DMA_CON_B2W                 0x00000020  /*word to byte or byte to word, channel 4,5 only*/
   #define DMA_CON_BURST_SINGLE        0x00000000  /*without burst mode*/
   #define DMA_CON_BURST_4BEAT         0x00000200  /*4-beat incrementing burst, channel 1, 4,5 only*/
   #define DMA_CON_BURST_8BEAT         0x00000400  /*8-beat incrementing burst, channel 1, 4,5 only*/
   #define DMA_CON_BURST_16BEAT        0x00000600  /*16-beat incrementing burst, channel 1, 4,5 only*/
   #define DMA_CON_ITEN                0x00008000  /*Interrupt enable*/
   #define DMA_CON_WPSD                0x00010000  /*0:at source, 1: at destination, channel 1, 4,5 only*/
   #define DMA_CON_WPEN                0x00020000  /*0:disable, 1: enable, channel 1, 4,5 only*/
   #define DMA_CON_DIR                 0x00040000  /*Only valid when dma = 4,5,11,12*/
   #define DMA_CON_MASTER_MASK         0x00f00000  /*Only valid when dma = 4,5,11,12*/

   #define DMA_CON_RXCONTRL            (DMA_CON_DIR|DMA_CON_DINC) /*hw management*/
   #define DMA_CON_TXCONTRL            (DMA_CON_SINC) /*hw management*/
   #define DMA_CON_SWCOPY              (DMA_CON_SINC|DMA_CON_DINC) /*hw management*/

   #define DMA_CON_MASTER_SIM          0x00
   #define DMA_CON_MASTER_UART1TX      0x01
   #define DMA_CON_MASTER_UART1RX      0x02
   #define DMA_CON_MASTER_UART2TX      0x03
   #define DMA_CON_MASTER_UART2RX      0x04
   //#define DMA_CON_MASTER_NFITX      0x05 /*not support in 6516_MD*/
   //#define DMA_CON_MASTER_NFIRX      0x06 /*not support in 6516_MD*/
   #define DMA_CON_MASTER_IDMA         0x07
   #define DMA_CON_MASTER_IDMA2        0x08

   #define DMA_START_BIT               0x00008000
   #define DMA_STOP_BIT                0x00000000
   #define DMA_ACKINT_BIT              0x00008000
   #define DMA_INTSTA_BIT              0x00008000

   #define DMA_RLCT_MASK               0x0000ffff /*channel 1,4,5 only*/

   #define DMA_LIMITER_MASK            0x000000ff
   // add for virtual fifo
   #define DMA_VFIFO_CH_S		11		// start  of DMA Virtual fifo
   #define DMA_VFIFO_CH_E		12		// end of DMA Virtual fifo

   #define DMA_VPORT_BASE              0x61000000
   #define DMA_VPORT(_n)               (DMA_VPORT_BASE+0x0100*(_n-DMA_VFIFO_CH_S))    /*_n = 11~12*/
   #define DMA_WRPTR(_n)               (DMA_base+0x0030+(0x0100*(_n)))    /*_n = 11~12*/
   #define DMA_RDPTR(_n)               (DMA_base+0x0034+(0x0100*(_n)))    /*_n = 11~12*/
   #define DMA_FFCNT(_n)               (DMA_base+0x0038+(0x0100*(_n)))    /*_n = 11~12*/
   #define DMA_FFSTA(_n)               (DMA_base+0x003c+(0x0100*(_n)))    /*_n = 11~12*/
   #define DMA_ALTLEN(_n)              (DMA_base+0x0040+(0x0100*(_n)))    /*_n = 11~12*/
   #define DMA_FFSIZE(_n)              (DMA_base+0x0044+(0x0100*(_n)))    /*_n = 11~12*/

   #define DMA_FFSTA_FULL		0x0001
   #define DMA_FFSTA_EMPTY		0x0002
   #define DMA_FFSTA_ALERT		0x0004

   #define DMA_POP(_n)                 *(volatile kal_uint8*)DMA_VPORT(_n)
   #define DMA_PUSH(_n,_data)          *(volatile kal_uint8*)DMA_VPORT(_n) = (kal_uint8)_data
   #define DMA_GetVFIFO_Avail(ch)      DRV_Reg(DMA_FFCNT(ch))
   #define DMA_GetVFIFO_Roomleft(ch)   DRV_Reg(DMA_FFSIZE(ch)) - DMA_GetVFIFO_Avail(ch)
   #define IS_VFIFO_FULL(ch)           (DRV_Reg32(DMA_FFSTA(ch)) & DMA_FFSTA_FULL)
   #define DMA_EnableINT(ch)           DRV_Reg32(DMA_CON(ch)) |= DMA_CON_ITEN
   #define DMA_DisableINT(ch)          DRV_Reg32(DMA_CON(ch)) &= ~DMA_CON_ITEN
   #define DMA_TASK_PUSH(ch,data)      while(IS_VFIFO_FULL(ch)); \
                                       DMA_PUSH(ch,data)

   #define DMA_TX_TRIGGER_LEVEL(n)     ((n)/8)		// trigger level of tx vfifo
   #define DMA_RX_TRIGGER_LEVEL(n)     ((n)*3/4)	// trigger level of rx vfifo

   #define DMA_VIFOF_ALERT_LENGTH      0x3f			// flow control trigger level

#elif defined(MT6268T)||defined(MT6268H)     /* MT6205 || MT6205B || MT6208 || FPGA */

/*
 * NoteXXX: There will be two FPGA UART available on MT6268T (3G) EVB.
 *          But they doesn't exist on MT6268T (2G-only) EVB.
 *          Thus we need to detect original UART ports or FPGA UART ports at run time.
 */

#define DMA_GLBSTA                  (DMA_base+0x0000) 
#define DMA_SRC(_n)                 (DMA_base+(0x0100*(_n)))           /*_n = 1~3*/
#define DMA_DST(_n)                 (DMA_base+0x0004+(0x0100*(_n)))    /*_n = 1~3*/
#define DMA_WPPT(_n)                (DMA_base+0x0008+(0x0100*(_n)))    /*_n = 1~11*/
#define DMA_WPTO(_n)                (DMA_base+0x000c+(0x0100*(_n)))    /*_n = 1~11*/
#define DMA_COUNT(_n)               (DMA_base+0x0010+(0x0100*(_n)))    /*_n = 1~11*/
#define DMA_CON(_n)                 (DMA_base+0x0014+(0x0100*(_n)))    /*_n = 1~11*/
#define DMA_START(_n)               (DMA_base+0x0018+(0x0100*(_n)))    /*_n = 1~11*/
#define DMA_INTSTA(_n)              (DMA_base+0x001c+(0x0100*(_n)))    /*_n = 1~11*/
#define DMA_ACKINT(_n)              (DMA_base+0x0020+(0x0100*(_n)))    /*_n = 1~11*/
#define DMA_RLCT(_n)                (DMA_base+0x0024+(0x0100*(_n)))    /*_n = 1~11*/  /*DEBUG*/
#define DMA_LIMITER(_n)             (DMA_base+0x0028+(0x0100*(_n)))    /*_n = 1~11*/
#define DMA_PGMADDR(_n)             (DMA_base+0x002c+(0x0100*(_n)))    /*_n = 4~11*/

#define FPGA_DMA_GLBSTA             (FPGA_DMA_base+0x0000) 
#define FPGA_DMA_SRC(_n)            (FPGA_DMA_base+(0x0100*(_n)))
#define FPGA_DMA_DST(_n)            (FPGA_DMA_base+0x0004+(0x0100*(_n)))
#define FPGA_DMA_WPPT(_n)           (FPGA_DMA_base+0x0008+(0x0100*(_n)))
#define FPGA_DMA_WPTO(_n)           (FPGA_DMA_base+0x000c+(0x0100*(_n)))
#define FPGA_DMA_COUNT(_n)          (FPGA_DMA_base+0x0010+(0x0100*(_n)))
#define FPGA_DMA_CON(_n)            (FPGA_DMA_base+0x0014+(0x0100*(_n)))
#define FPGA_DMA_START(_n)          (FPGA_DMA_base+0x0018+(0x0100*(_n)))
#define FPGA_DMA_INTSTA(_n)         (FPGA_DMA_base+0x001c+(0x0100*(_n)))
#define FPGA_DMA_ACKINT(_n)         (FPGA_DMA_base+0x0020+(0x0100*(_n)))
#define FPGA_DMA_RLCT(_n)           (FPGA_DMA_base+0x0024+(0x0100*(_n)))
#define FPGA_DMA_LIMITER(_n)        (FPGA_DMA_base+0x0028+(0x0100*(_n)))
#define FPGA_DMA_PGMADDR(_n)        (FPGA_DMA_base+0x002c+(0x0100*(_n)))

#define DMA_GLBSTA_RUN(_n)          (0x00000001 << (2*((_n)-1)))  /*_n = 1~11*/
#define DMA_GLBSTA_IT(_n)           (0x00000002 << (2*((_n)-1)))  /*_n = 1~11*/

#define DMA_COUNT_MASK              0xffff
#define DMA_CON_SIZE_MASK           0x00000003
#define DMA_CON_SIZE_BYTE           0x00000000
#define DMA_CON_SIZE_SHORT          0x00000001
#define DMA_CON_SIZE_LONG           0x00000002
#define DMA_CON_SINC                0x00000004
#define DMA_CON_DINC                0x00000008
#define DMA_CON_DRQ                 0x00000010  /*1:hw, 0:sw*/
#define DMA_CON_B2W                 0x00000020  /*word to byte or byte to word*/
#define DMA_CON_BURST_SINGLE        0x00000000  /*without burst mode*/
#define DMA_CON_BURST_4BEAT         0x00000200  /*4-beat incrementing burst*/
#define DMA_CON_BURST_8BEAT         0x00000400  /*8-beat incrementing burst*/
#define DMA_CON_BURST_16BEAT        0x00000600  /*16-beat incrementing burst*/
#define DMA_CON_ITEN                0x00008000  /*Interrupt enable*/
#define DMA_CON_WPSD                0x00010000  /*0:at source, 1: at destination*/
#define DMA_CON_WPEN                0x00020000  /*0:disable, 1: enable*/
#define DMA_CON_DIR                 0x00040000  /*Only valid when dma = 4~11*/
#define DMA_CON_MASTER_MASK         0x00f00000  /*Only valid when dma = 4~11*/
#define DMA_CON_RXCONTRL            (DMA_CON_DIR|DMA_CON_DINC)  /*hw management*/
#define DMA_CON_TXCONTRL            (DMA_CON_SINC)  /*hw management*/
#define DMA_CON_SWCOPY              (DMA_CON_SINC|DMA_CON_DINC) /*hw management*/
#define DMA_CON_MASTER_SIM          0x00
#define DMA_CON_MASTER_MSDC         0x01
#define DMA_CON_MASTER_IRDATX       0x02
#define DMA_CON_MASTER_IRDARX       0x03
#define DMA_CON_MASTER_USB1RX       0x04
#define DMA_CON_MASTER_USB1TX       0x05
#define DMA_CON_MASTER_USB2RX       0x06
#define DMA_CON_MASTER_USB2TX       0x07
#define DMA_CON_MASTER_UART1TX      0x08
#define DMA_CON_MASTER_UART1RX      0x09
#define DMA_CON_MASTER_UART2TX      0x0a
#define DMA_CON_MASTER_UART2RX      0x0b
#define DMA_CON_MASTER_UART3TX      0x0c
#define DMA_CON_MASTER_UART3RX      0x0d
#define DMA_CON_MASTER_IDMA         0x0e
#define DMA_CON_MASTER_NFITX        0x0f
#define DMA_CON_MASTER_NFIRX        0x10
#define DMA_START_BIT               0x00008000
#define DMA_STOP_BIT                0x00000000
#define DMA_ACKINT_BIT              0x00008000
#define DMA_INTSTA_BIT              0x00008000
#define DMA_RLCT_MASK               0x0000ffff
#define DMA_LIMITER_MASK            0x000000ff

/* DMA VFIFO */

#define DMA_VFIFO_CH_S              11      // start  of DMA Virtual fifo 
#define DMA_VFIFO_CH_E              14      // end of DMA Virtual fifo 	
#define DMA_VPORT_BASE              0x78000000

#if defined(MT6268T)
#define FPGA_DMA_VPORT_BASE         0xC4000000    //for MT6268T
#else
#define FPGA_DMA_VPORT_BASE         0xB4000000    //for MT6268H
#endif

#define DMA_FFSTA_FULL              0x0001
#define DMA_FFSTA_EMPTY             0x0002
#define DMA_FFSTA_ALERT             0x0004

#define DMA_VPORT(_n)               (DMA_VPORT_BASE+0x0100*(_n-DMA_VFIFO_CH_S))
#define FPGA_DMA_VPORT(_n)          (FPGA_DMA_VPORT_BASE+0x0100*(_n-DMA_VFIFO_CH_S))
#define DMA_WRPTR(_n)               (FPGA_DMA_base+0x0030+(0x0100*(_n)))
#define DMA_RDPTR(_n)               (FPGA_DMA_base+0x0034+(0x0100*(_n)))
#define DMA_FFCNT(_n)               (FPGA_DMA_base+0x0038+(0x0100*(_n)))
#define DMA_FFSTA(_n)               (FPGA_DMA_base+0x003c+(0x0100*(_n)))
#define DMA_ALTLEN(_n)              (FPGA_DMA_base+0x0040+(0x0100*(_n)))
#define DMA_FFSIZE(_n)              (FPGA_DMA_base+0x0044+(0x0100*(_n)))

#define DMA_POP(_n)                 (*(volatile kal_uint8*)FPGA_DMA_VPORT(_n))
#define DMA_PUSH(_n,_data)          do {    \
                                        *(volatile kal_uint8*)FPGA_DMA_VPORT(_n) = (kal_uint8)_data; \
                                    } while (0)
#define DMA_GetVFIFO_Avail(ch)      DRV_Reg(DMA_FFCNT(ch))
#define DMA_GetVFIFO_Roomleft(ch)   DRV_Reg(DMA_FFSIZE(ch)) - DMA_GetVFIFO_Avail(ch)
#define IS_VFIFO_FULL(ch)           (DRV_Reg32(DMA_FFSTA(ch)) & DMA_FFSTA_FULL)
#define DMA_EnableINT(ch)           do {    \
                                        if (((ch) >= DMA_VFIFO_CH_S))  \
                                            DRV_Reg32(FPGA_DMA_CON(ch)) |= DMA_CON_ITEN;    \
                                        else    \
                                            DRV_Reg32(DMA_CON(ch)) |= DMA_CON_ITEN; \
                                    } while (0)
#define DMA_DisableINT(ch)          do {    \
                                        if (((ch) >= DMA_VFIFO_CH_S))  \
                                            DRV_Reg32(FPGA_DMA_CON(ch)) &= ~DMA_CON_ITEN;    \
                                        else    \
                                            DRV_Reg32(DMA_CON(ch)) &= ~DMA_CON_ITEN;    \
                                    } while (0)
#define DMA_TASK_PUSH(ch,data)      while(IS_VFIFO_FULL(ch)); \
                                    DMA_PUSH(ch,data)	

#define DMA_TX_TRIGGER_LEVEL(n)     ((n)*6/8)   // trigger level of tx vfifo, change for MonzaE4
#define DMA_RX_TRIGGER_LEVEL(n)     ((n)*3/4)   // trigger level of rx vfifo

#define DMA_VIFOF_ALERT_LENGTH      0x3f        // flow control trigger level

#elif defined(MT6236) || defined(MT6236B)

#if defined(__AST_TL1_TDD__)
    #define __DMA_SUPPORT_CALLBACK_LISR__
#endif

#if !defined(MT6921)
#define __DMA_BT_VIRTUAL_FIFO__
#endif

   #define DMA_GLBSTA                  (DMA_base+0x0000) 
   #define DMA_GLBSTA2                 (DMA_base+0x0004) 
   #define DMA_SRC(_n)                 (DMA_base+(0x0100*(_n)))           /*_n = 1~3*/
   #define DMA_DST(_n)                 (DMA_base+0x0004+(0x0100*(_n)))    /*_n = 1~3*/
   #define DMA_WPPT(_n)                (DMA_base+0x0008+(0x0100*(_n)))    /*_n = 1~11*/
   #define DMA_WPTO(_n)                (DMA_base+0x000c+(0x0100*(_n)))    /*_n = 1~11*/
   #define DMA_COUNT(_n)               (DMA_base+0x0010+(0x0100*(_n)))    /*_n = 1~11*/
   #define DMA_CON(_n)                 (DMA_base+0x0014+(0x0100*(_n)))    /*_n = 1~11*/
   #define DMA_START(_n)               (DMA_base+0x0018+(0x0100*(_n)))    /*_n = 1~11*/
   #define DMA_INTSTA(_n)              (DMA_base+0x001c+(0x0100*(_n)))    /*_n = 1~11*/
   #define DMA_ACKINT(_n)              (DMA_base+0x0020+(0x0100*(_n)))    /*_n = 1~11*/
   #define DMA_RLCT(_n)                (DMA_base+0x0024+(0x0100*(_n)))    /*_n = 1~11*/  /*DEBUG*/
   #define DMA_LIMITER(_n)             (DMA_base+0x0028+(0x0100*(_n)))    /*_n = 1~11*/
   #define DMA_PGMADDR(_n)             (DMA_base+0x002c+(0x0100*(_n)))    /*_n = 4~11*/
                                       
   #define DMA_GLBSTA_RUN(_n)          (0x00000001 << (2*((_n)-1)))  /*_n = 1~11*/
   #define DMA_GLBSTA_IT(_n)           (0x00000002 << (2*((_n)-1)))  /*_n = 1~11*/
                                       
   #define DMA_COUNT_MASK              0xffff
                                       
   /*DMA_CON*/                         
   #define DMA_CON_SIZE_MASK           0x00000003
   #define DMA_CON_SIZE_BYTE           0x00000000
   #define DMA_CON_SIZE_SHORT          0x00000001
   #define DMA_CON_SIZE_LONG           0x00000002
   #define DMA_CON_SINC                0x00000004
   #define DMA_CON_DINC                0x00000008
   #define DMA_CON_DRQ                 0x00000010  /*1:hw, 0:sw*/
   #define DMA_CON_B2W                 0x00000020  /*word to byte or byte to word*/
   #define DMA_CON_BURST_SINGLE        0x00000000  /*without burst mode*/
   #define DMA_CON_BURST_4BEAT         0x00000200  /*4-beat incrementing burst*/
   #define DMA_CON_BURST_8BEAT         0x00000400  /*8-beat incrementing burst*/
   #define DMA_CON_BURST_16BEAT        0x00000600  /*16-beat incrementing burst*/
   #define DMA_CON_ITEN                0x00008000  /*Interrupt enable*/
   #define DMA_CON_WPSD                0x00010000  /*0:at source, 1: at destination*/
   #define DMA_CON_WPEN                0x00020000  /*0:disable, 1: enable*/
   #define DMA_CON_DIR                 0x00040000  /*Only valid when dma = 4~11*/
   #define DMA_CON_MASTER_MASK         0x00f00000  /*Only valid when dma = 4~11*/
   #define DMA_CON_RXCONTRL            (DMA_CON_DIR|DMA_CON_DINC) /*hw management*/
   #define DMA_CON_TXCONTRL            (DMA_CON_SINC) /*hw management*/
   #define DMA_CON_SWCOPY              (DMA_CON_SINC|DMA_CON_DINC) /*hw management*/

   #define DMA_CON_MASTER_SIM          0x00
   #define DMA_CON_MASTER_MSDC         0x01
   #define DMA_CON_MASTER_IRDATX       0x02
   #define DMA_CON_MASTER_IRDARX       0x03
   #define DMA_CON_MASTER_RESERVED_1   0x04
   #define DMA_CON_MASTER_RESERVED_2   0x05
   #define DMA_CON_MASTER_RESERVED_3   0x06
   #define DMA_CON_MASTER_RESERVED_4   0x07
   #define DMA_CON_MASTER_UART1TX      0x08
   #define DMA_CON_MASTER_UART1RX      0x09
   #define DMA_CON_MASTER_UART2TX      0x0a
   #define DMA_CON_MASTER_UART2RX      0x0b
   #define DMA_CON_MASTER_UART3TX      0x0c
   #define DMA_CON_MASTER_UART3RX      0x0d
   #define DMA_CON_MASTER_IDMA         0x0e
   #define DMA_CON_MASTER_NFITX        0x0f
   #define DMA_CON_MASTER_NFIRX        0x10
   #define DMA_CON_MASTER_DSPDMA2      0x11
   #define DMA_CON_MASTER_I2CTX        0x12
   #define DMA_CON_MASTER_I2CRX        0x13
   #define DMA_CON_MASTER_MSDC2        0x14
   #define DMA_CON_MASTER_SIM2         0x15
   #define DMA_CON_MASTER_RESERVED_5   0x16
   #define DMA_CON_MASTER_BTIFTX       0x17
   #define DMA_CON_MASTER_BTIFRX       0x18

   #define DMA_START_BIT               0x00008000
   #define DMA_STOP_BIT                0x00000000
   #define DMA_ACKINT_BIT              0x00008000
   #define DMA_INTSTA_BIT              0x00008000
                                       
   #define DMA_RLCT_MASK               0x0000ffff
                                       
   #define DMA_LIMITER_MASK            0x000000ff

   #define DMA_VFIFO_CH_S               11      // start  of DMA Virtual fifo 
   #define DMA_VFIFO_CH_E               18      // end of DMA Virtual fifo    

   #define DMA_VPORT_BASE              0x83000000

   #define DMA_VPORT(_n)               (DMA_VPORT_BASE+0x0100*(_n-DMA_VFIFO_CH_S))    /*_n = 10~13*/
   #define DMA_WRPTR(_n)               (DMA_base+0x0030+(0x0100*(_n)))    /*_n = 10~13*/
   #define DMA_RDPTR(_n)               (DMA_base+0x0034+(0x0100*(_n)))    /*_n = 10~13*/
   #define DMA_FFCNT(_n)               (DMA_base+0x0038+(0x0100*(_n)))    /*_n = 10~13*/
   #define DMA_FFSTA(_n)               (DMA_base+0x003c+(0x0100*(_n)))    /*_n = 10~13*/
   #define DMA_ALTLEN(_n)              (DMA_base+0x0040+(0x0100*(_n)))    /*_n = 10~13*/
   #define DMA_FFSIZE(_n)              (DMA_base+0x0044+(0x0100*(_n)))    /*_n = 10~13*/

   #define DMA_FFSTA_FULL              0x0001
   #define DMA_FFSTA_EMPTY             0x0002
   #define DMA_FFSTA_ALERT             0x0004

   #define DMA_POP(_n)                 *(volatile kal_uint8*)DMA_VPORT(_n)
   #define DMA_PUSH(_n,_data)          *(volatile kal_uint8*)DMA_VPORT(_n) = (kal_uint8)_data
   #define DMA_GetVFIFO_Avail(ch)      DRV_Reg(DMA_FFCNT(ch))
   #define DMA_GetVFIFO_Roomleft(ch)   DRV_Reg(DMA_FFSIZE(ch)) - DMA_GetVFIFO_Avail(ch)
   #define IS_VFIFO_FULL(ch)           (DRV_Reg32(DMA_FFSTA(ch)) & DMA_FFSTA_FULL)
   #define DMA_EnableINT(ch)           DRV_Reg32(DMA_CON(ch)) |= DMA_CON_ITEN
   #define DMA_DisableINT(ch)          DRV_Reg32(DMA_CON(ch)) &= ~DMA_CON_ITEN
   #define DMA_TASK_PUSH(ch,data)      while(IS_VFIFO_FULL(ch)); \
                                       DMA_PUSH(ch,data)   

   #define DMA_TX_TRIGGER_LEVEL(n)     ((n)/8)      // trigger level of tx vfifo
   #define DMA_RX_TRIGGER_LEVEL(n)     ((n)*3/4)   // trigger level of rx vfifo

   #define DMA_VIFOF_ALERT_LENGTH      0x3f         // flow control trigger level

#elif defined(MT6276) || defined(MT6256) || defined(MT6255)

#define __DMA_V3__

#if defined(MT6256) && defined (__BTMODULE_MT6256__)
#define __DMA_BT_VIRTUAL_FIFO__
#endif

#if defined(MT6255) && defined (__BTMODULE_MT6255__)
#define __DMA_BT_VIRTUAL_FIFO__
#endif

#if defined(MT6276) && defined (__BTMODULE_MT6276__)
#define __DMA_BT_VIRTUAL_FIFO__
#endif

#if defined(MT6276_S00) || defined(MT6256_S00)
#define __DMA_WIFI_SUPPORT_BY_GDMA__
#endif

#if ( !defined(MT6276_S00) && !defined(MT6256_S00) )
#define __DMA_SIM_TX_RX_SUPPORT__
#endif

#if defined(MT6255)
#define __DMA_FIXED_ADDRESS_NOT_SUPPORT__
#endif

	
#define DMA_OFFSET                  0x0080

/* DMA Global Registers */
#define DMA_GLBST_INT               (DMA_base+0x0000)
#define DMA_GLOBAL_RESET            (DMA_base+0x0004)
#define DMA_GLBST_RUNNING           (DMA_base+0x0008)
#define DMA_GLOBAL_SLOW_DOWN        (DMA_base+0x000c)

/* DMA Security Registers */
#define DMA_GLOBAL_SEC_EN           (DMA_base+0x0010)
#define DMA_GLOBAL_GSEC_EN          (DMA_base+0x0014)
#define DMA_GLOBAL_LAT_ADDR         (DMA_base+0x0018)
#define DMA_GLOBAL_ABORT            (DMA_base+0x001c)

/* DMA Control Registers */
#define DMA_INT_FLAG(_n)            (DMA_base+0x0000+(DMA_OFFSET*(_n)))
#define DMA_INT_EN(_n)              (DMA_base+0x0004+(DMA_OFFSET*(_n)))
#define DMA_START(_n)               (DMA_base+0x0008+(DMA_OFFSET*(_n)))
#define DMA_RESET(_n)               (DMA_base+0x000c+(DMA_OFFSET*(_n)))
#define DMA_STOP(_n)                (DMA_base+0x0010+(DMA_OFFSET*(_n)))
#define DMA_FLUSH(_n)               (DMA_base+0x0014+(DMA_OFFSET*(_n)))
#define DMA_CON(_n)                 (DMA_base+0x0018+(DMA_OFFSET*(_n)))
#define DMA_MEM_ADDR(_n)            (DMA_base+0x001c+(DMA_OFFSET*(_n)))
#define DMA_SRC(_n)                 (DMA_base+0x001c+(DMA_OFFSET*(_n)))
#define DMA_DST(_n)                 (DMA_base+0x0020+(DMA_OFFSET*(_n)))
#define DMA_LEN1(_n)                (DMA_base+0x0024+(DMA_OFFSET*(_n)))
#define DMA_VFF_SIZE(_n)            (DMA_base+0x0024+(DMA_OFFSET*(_n)))
#define DMA_LEN2(_n)                (DMA_base+0x0028+(DMA_OFFSET*(_n)))
#define DMA_VFF_THRE(_n)            (DMA_base+0x0028+(DMA_OFFSET*(_n)))
#define DMA_JMP_ADDR(_n)            (DMA_base+0x002c+(DMA_OFFSET*(_n)))
#define DMA_VFF_WPT(_n)             (DMA_base+0x002c+(DMA_OFFSET*(_n)))
#define DMA_BUF_SIZE(_n)            (DMA_base+0x0030+(DMA_OFFSET*(_n)))
#define DMA_VFF_RPT(_n)             (DMA_base+0x0030+(DMA_OFFSET*(_n)))
#define DMA_CONNECT(_n)             (DMA_base+0x0034+(DMA_OFFSET*(_n)))
#define DMA_W_INT_BUF_SIZE(_n)      (DMA_base+0x0034+(DMA_OFFSET*(_n)))
#define DMA_FLOW_CTRL_THRE(_n)      (DMA_base+0x0034+(DMA_OFFSET*(_n)))
#define DMA_INT_BUF_SIZE(_n)        (DMA_base+0x0038+(DMA_OFFSET*(_n)))
#define DMA_VFF_VALID_SIZE(_n)      (DMA_base+0x003c+(DMA_OFFSET*(_n)))
#define DMA_VFF_LEFT_SIZE(_n)       (DMA_base+0x0040+(DMA_OFFSET*(_n)))
#define DMA_DEBUG(_n)               (DMA_base+0x0050+(DMA_OFFSET*(_n)))

/* for backward compatible */
#define DMA_GLBSTA                  0x00000003                // this will cause data abort
#define DMA_COUNT(_n)               DMA_LEN1(_n)
#define DMA_WPPT(_n)                DMA_LEN2(_n)
#define DMA_WPTO(_n)                DMA_JMP_ADDR(_n)
#define DMA_PGMADDR(_n)             DMA_MEM_ADDR(_n)
#define DMA_ACKINT(_n)              DMA_INT_FLAG(_n)
#define DMA_RLCT(_n)                DMA_LEN1(_n)
#define DMA_LIMITER(_n)             DMA_CON(_n)
#define DMA_INTSTA(_n)              DMA_INT_FLAG(_n)
#define DMA_ALTLEN(_n)              DMA_FLOW_CTRL_THRE(_n)
#define DMA_FFSIZE(_n)              DMA_VFF_SIZE(_n)

#if defined(MT6276)

#define DMA_FULL_CH_NUM     2

#if defined(MT6276_S00)
#define DMA_HALF_CH_NUM     15
#else
#define DMA_HALF_CH_NUM     18
#endif

#elif defined(MT6256)

#if defined(MT6256_S00)
#define DMA_FULL_CH_NUM     2
#define DMA_HALF_CH_NUM     18
#else
#define DMA_FULL_CH_NUM     1
#define DMA_HALF_CH_NUM     19
#endif // defined (6256_S00)


#elif defined(MT6255)
#define DMA_FULL_CH_NUM     1
#define DMA_HALF_CH_NUM     19

#endif // defined (MT6276)

#define DMA_COUNT_MAX       0xFFFFF

/*
 * Define macros.
 */
 
#define DMA_GLBSTA_RUN(_n)          (0x00000001 << ((_n)-1))  /*_n = 1~11*/
#define DMA_GLBSTA_IT(_n)           (0x00000001 << ((_n)-1))  /*_n = 1~11*/

/*DMA_CON*/                         
#if !defined(__DMA_FIXED_ADDRESS_NOT_SUPPORT__)
#define DMA_CON_SIZE_MASK           0x00000003
#define DMA_CON_SIZE_BYTE           0x00000000
#define DMA_CON_SIZE_SHORT          0x00000001
#define DMA_CON_SIZE_LONG           0x00000002
                                       
#define DMA_CON_SFIX                0x00000010
#define DMA_CON_DFIX                0x00000008

#define DMA_CON_WSIZE_1BYTE         0x00000000
#define DMA_CON_WSIZE_2BYTE         0x00000001
#define DMA_CON_WSIZE_4BYTE         0x00000002
#define DMA_CON_WSIZE_OFFSET        24

#define DMA_CON_RSIZE_1BYTE         0x00000000
#define DMA_CON_RSIZE_2BYTE         0x00000001
#define DMA_CON_RSIZE_4BYTE         0x00000002
#define DMA_CON_RSIZE_OFFSET        28
#else //!defined(__DMA_FIXED_ADDRESS_NOT_SUPPORT__)

#define DMA_CON_SIZE_MASK           0x00000000  ///! zero-mask to avoid to write field
#define DMA_CON_SIZE_BYTE           0x00000000 
#define DMA_CON_SIZE_SHORT          0x00000001
#define DMA_CON_SIZE_LONG           0x00000002
                                       
#define DMA_CON_SFIX                0x0         ///! fill with zero 
#define DMA_CON_DFIX                0x0         ///! fill with zero 

#define DMA_CON_WSIZE_1BYTE         0x00000000
#define DMA_CON_WSIZE_2BYTE         0x00000001
#define DMA_CON_WSIZE_4BYTE         0x00000002
#define DMA_CON_WSIZE_OFFSET        24

#define DMA_CON_RSIZE_1BYTE         0x00000000
#define DMA_CON_RSIZE_2BYTE         0x00000001
#define DMA_CON_RSIZE_4BYTE         0x00000002
#define DMA_CON_RSIZE_OFFSET        28
#endif //!defined(__DMA_FIX_ADDRESS_NOT_SUPPORT__)

#define DMA_CON_SLOW_EN             4
#define DMA_CON_SLOW_OFFSET         5
#define DMA_CON_SLOW_MASK           0x00007FE0
                                  
#define DMA_CON_BURST_SINGLE        0x00000000  /*without burst mode*/
#define DMA_CON_BURST_2BEAT         0x00000001  /*4-beat incrementing burst*/
#define DMA_CON_BURST_3BEAT         0x00000002  /*4-beat incrementing burst*/
#define DMA_CON_BURST_4BEAT         0x00000003  /*4-beat incrementing burst*/
#define DMA_CON_BURST_5BEAT         0x00000004  /*4-beat incrementing burst*/
#define DMA_CON_BURST_6BEAT         0x00000005  /*4-beat incrementing burst*/
#define DMA_CON_BURST_7BEAT         0x00000006  /*4-beat incrementing burst*/
#define DMA_CON_BURST_8BEAT         0x00000007  /*8-beat incrementing burst*/
#define DMA_CON_BURST_OFFSET        16

                                       
#define DMA_CON_WPSD                0x00100000  /*0:at source, 1: at destination*/
#define DMA_CON_WPEN                0x00008000  /*0:disable, 1: enable*/

//#define DMA_CON_DIR                 0x00000000  //mask by AB

#define DMA_START_BIT               0x00000001
#define DMA_W_RST_BIT               0x00000001
#define DMA_H_RST_BIT               0x00000002
#define DMA_STOP_BIT                0x00000001
#define DMA_PAUSE_BIT               0x00000002
#define DMA_ACKINT_BIT              0x00000000
#define DMA_INTSTA_BIT              0x00000001
#define DMA_INTSTA_BIT1             0x00000002

                                       
#define DMA_CON_RXCONTRL            1 /*hw management*/ //mask by AB
#define DMA_CON_TXCONTRL            0 /*hw management*/ //mask by AB
//#define DMA_CON_SWCOPY              0 /*hw management*/ //mask by AB
#define DMA_CON_FIXED_PATTERN       2

//#define DMA_CON_DRQ                 0x0000   /*1: HW management,0:SW */
//#define DMA_CON_TMOD                0x0000   /*1: Block mode, 0:Single mode*/
//#define DMA_CON_MAS                 0x0000   /*00:,01:UART1 Rx(1)/UART1 Tx(2),10: UART2 tx(1),UART2 rx(2),11:SIM*/
//#define DMA_CON_CYCLE_MASK          0x0000   /* Burst mode cycle */
//#define DMA_CON_ITEN                0x0000   /*Interrupt enable*/

#define DMA_CONNECT_WRITE             0x00000000
#define DMA_CONNECT_READ              0x00000004
#define DMA_REQ_ACK_RATIO_1_2         0x00000000
#define DMA_REQ_ACK_RATIO_1_1         0x00000008
   
#define DMA_TX_TRIGGER_LEVEL(n)     ((n)/8)     // trigger level of tx vfifo
#define DMA_RX_TRIGGER_LEVEL(n)     ((n)*3/4)   // trigger level of rx vfifo
#define DMA_VIFOF_ALERT_LENGTH      0x3f        // flow control trigger level

#define DMA_Start(_n)                DRV_WriteReg32(DMA_START(_n),DMA_START_BIT)
#define DMA_Reset(_n,_m)             DRV_WriteReg32(DMA_RESET(_n),_m?DMA_H_RST_BIT:DMA_W_RST_BIT)
#define DMA_Pause(_n)                DRV_WriteReg32(DMA_STOP(_n),DMA_PAUSE_BIT)
#define DMA_Resume(_n)               DRV_WriteReg32(DMA_STOP(_n),0)
#define DMA_Flush(_n)                DRV_WriteReg32(DMA_FLUSH(_n),1)
#define DMA_GetCount(_n)             DRV_Reg32(DMA_COUNT(_n))
#define DMA_ACKI(_n)                 DRV_WriteReg32(DMA_ACKINT(_n),DMA_ACKINT_BIT)

#if defined(MT6276)

#if defined(MT6276_S00)
#define DMA_CON_MASTER_BTIFTX        0x09
#define DMA_CON_MASTER_BTIFRX        0x0A
#define DMA_CON_MASTER_UART1TX       0x0B
#define DMA_CON_MASTER_UART1RX       0x0C
#define DMA_CON_MASTER_UART2TX       0x0D
#define DMA_CON_MASTER_UART2RX       0x0E
#define DMA_CON_MASTER_UART3TX       0x0F
#define DMA_CON_MASTER_UART3RX       0x10
#else /* MT6276_S00 */
#define DMA_CON_MASTER_BTIFTX        0x0C
#define DMA_CON_MASTER_BTIFRX        0x0D
#define DMA_CON_MASTER_UART1TX       0x0E
#define DMA_CON_MASTER_UART1RX       0x0F
#define DMA_CON_MASTER_UART2TX       0x10
#define DMA_CON_MASTER_UART2RX       0x11
#define DMA_CON_MASTER_UART3TX       0x12
#define DMA_CON_MASTER_UART3RX       0x13
#endif /* MT6276_S00 */

#elif defined(MT6256)

#if defined(MT6256_S00)
#define DMA_CON_MASTER_BTIFTX        0x09
#define DMA_CON_MASTER_BTIFRX        0x0A
#define DMA_CON_MASTER_UART1TX       0x0B
#define DMA_CON_MASTER_UART1RX       0x0C
#define DMA_CON_MASTER_UART2TX       0x0D
#define DMA_CON_MASTER_UART2RX       0x0E
#define DMA_CON_MASTER_UART3TX       0x0F
#define DMA_CON_MASTER_UART3RX       0x10
#else
#define DMA_CON_MASTER_BTIFTX        0x0C
#define DMA_CON_MASTER_BTIFRX        0x0D
#define DMA_CON_MASTER_UART1TX       0x0E
#define DMA_CON_MASTER_UART1RX       0x0F
#define DMA_CON_MASTER_UART2TX       0x10
#define DMA_CON_MASTER_UART2RX       0x11
#define DMA_CON_MASTER_UART3TX       0x12
#define DMA_CON_MASTER_UART3RX       0x13
#endif

#elif defined (MT6255)
#define DMA_CON_MASTER_BTIFTX        0x0C
#define DMA_CON_MASTER_BTIFRX        0x0D
#define DMA_CON_MASTER_UART1TX       0x0E
#define DMA_CON_MASTER_UART1RX       0x0F
#define DMA_CON_MASTER_UART2TX       0x10
#define DMA_CON_MASTER_UART2RX       0x11
#define DMA_CON_MASTER_UART3TX       0x12
#define DMA_CON_MASTER_UART3RX       0x13

#endif // defined (MT6276)


#if defined(MT6256_S00)
#define DMA_UART_VFF_S              12
#define DMA_VPORT_BASE              0x73000000
#define DMA_VPORT(_n)               (DMA_VPORT_BASE+0x0100*((_n-DMA_UART_VFF_S)>>1))    //only for TX channel: 12,14,16
#elif defined(MT6276_S00)
#define DMA_UART_VFF_S              12
#define DMA_VPORT_BASE              0x65800000
#define DMA_VPORT(_n)               (DMA_VPORT_BASE+0x0100*((_n-DMA_UART_VFF_S)>>1))    //only for TX channel: 12,14,16
#endif

#define DMA_WRPTR(_n)               DMA_VFF_WPT(_n)
#define DMA_RDPTR(_n)               DMA_VFF_RPT(_n)
#define DMA_FFCNT(_n)               DMA_VFF_VALID_SIZE(_n)
#define DMA_FFSTA(_n)               0x00000003
   
#define DMA_FFSTA_FULL              0x0001
#define DMA_FFSTA_EMPTY             0x0002
#define DMA_FFSTA_ALERT             0x0004

#if defined(MT6276)

#if defined(MT6276_S00)
#define DMA_VFIFO_CH_S		10		// start  of DMA Virtual fifo
#define DMA_VFIFO_CH_E		17		// end of DMA Virtual fifo
#else
#define DMA_VFIFO_CH_S		13		// start  of DMA Virtual fifo
#define DMA_VFIFO_CH_E		20		// end of DMA Virtual fifo
#endif 

#elif defined(MT6256)
#if defined(MT6256_S00)
#define DMA_VFIFO_CH_S		10		// start  of DMA Virtual fifo
#define DMA_VFIFO_CH_E		17		// end of DMA Virtual fifo
#else
#define DMA_VFIFO_CH_S		13		// start  of DMA Virtual fifo
#define DMA_VFIFO_CH_E		20		// end of DMA Virtual fifo
#endif

#elif defined(MT6255)
#define DMA_VFIFO_CH_S		13		// start  of DMA Virtual fifo
#define DMA_VFIFO_CH_E		20		// end of DMA Virtual fifo

#endif  //defined (MT6276)

//#define DMA_POP(_n)                 *(volatile kal_uint8*)DMA_VPORT(_n)
//#define DMA_PUSH(_n,_data)          *(volatile kal_uint8*)DMA_VPORT(_n) = (kal_uint8)_data
#define DMA_GetVFIFO_Avail(ch)      DRV_Reg(DMA_FFCNT(ch))
#if defined(MT6276_S00) || defined(MT6256_S00)
#define DMA_GetVFIFO_Roomleft(ch)   ( DRV_Reg(DMA_VFF_LEFT_SIZE(ch)) - 16 )            //VFF requires 16 bytes to do flush
#define IS_VFIFO_FULL(ch)           (DRV_Reg32(DMA_VFF_LEFT_SIZE(ch)) < 16)            //VFF requires 16 bytes to do flush
#else
#define DMA_GetVFIFO_Roomleft(ch)   ( DRV_Reg(DMA_VFF_LEFT_SIZE(ch)) )            //VFF requires 16 bytes to do flush
#define IS_VFIFO_FULL(ch)           (DRV_Reg32(DMA_VFF_LEFT_SIZE(ch)) == 0)            //VFF requires 16 bytes to do flush
#endif
#define DMA_EnableINT(ch)                                                                    \
                                   do{                                                       \
                                      if( (ch >= DMA_VFIFO_CH_S) &&                          \
                                          (( ch & 0x1 ) == ((DMA_CON_MASTER_UART1RX+1) & 0x1)) ) \
                                      {                                                      \
                                         DRV_Reg32(DMA_INT_EN(ch)) = 3;                      \
                                      }                                                      \
                                      else                                                   \
                                      {                                                      \
                                         DRV_Reg32(DMA_INT_EN(ch)) = 1;                      \
                                      }                                                      \
                                    }while(0)
#define DMA_DisableINT(ch)          DRV_Reg32(DMA_INT_EN(ch)) = 0
#if !defined(MT6255) /// since no VPORT, here not provide DMA_PUSH.
#define DMA_TASK_PUSH(ch,data)      while(IS_VFIFO_FULL(ch)); \
                                          DMA_PUSH(ch,data)
#endif /// defined(MT6255)

#elif defined(MT6573)
   
#define __DMA_V3__
#define __MULTI_CORE_SHARED_DMA__
#if defined(__AST_TL1_TDD__)
#define __DMA2_SUPPORT__
#define __DMA_SUPPORT_CALLBACK_LISR__
#endif
	
#define DMA_OFFSET                  0x0080

/* DMA Global Registers */
#define DMA_GLBST_INT               (AP_DMA_base+0x0000)
#define DMA_GLOBAL_RESET            (AP_DMA_base+0x0004)
#define DMA_GLBST_RUNNING           (AP_DMA_base+0x0008)
#define DMA_GLOBAL_SLOW_DOWN        (AP_DMA_base+0x000c)
#define DMA_GLOBAL_INT_SEL          (AP_DMA_base+0x0020)

/* DMA Security Registers */
#define DMA_GLOBAL_SEC_EN           (AP_DMA_base+0x0010)
#define DMA_GLOBAL_GSEC_EN          (AP_DMA_base+0x0014)
#define DMA_GLOBAL_LAT_ADDR         (AP_DMA_base+0x0018)
#define DMA_GLOBAL_ABORT            (AP_DMA_base+0x001c)

/* DMA Control Registers */
#define DMA_INT_FLAG(_n)            (AP_DMA_base+0x0000+(DMA_OFFSET*(_n)))
#define DMA_INT_EN(_n)              (AP_DMA_base+0x0004+(DMA_OFFSET*(_n)))
#define DMA_START(_n)               (AP_DMA_base+0x0008+(DMA_OFFSET*(_n)))
#define DMA_RESET(_n)               (AP_DMA_base+0x000c+(DMA_OFFSET*(_n)))
#define DMA_STOP(_n)                (AP_DMA_base+0x0010+(DMA_OFFSET*(_n)))
#define DMA_FLUSH(_n)               (AP_DMA_base+0x0014+(DMA_OFFSET*(_n)))
#define DMA_CON(_n)                 (AP_DMA_base+0x0018+(DMA_OFFSET*(_n)))
#define DMA_MEM_ADDR(_n)            (AP_DMA_base+0x001c+(DMA_OFFSET*(_n)))
#define DMA_SRC(_n)                 (AP_DMA_base+0x001c+(DMA_OFFSET*(_n)))
#define DMA_DST(_n)                 (AP_DMA_base+0x0020+(DMA_OFFSET*(_n)))
#define DMA_LEN1(_n)                (AP_DMA_base+0x0024+(DMA_OFFSET*(_n)))
#define DMA_VFF_SIZE(_n)            (AP_DMA_base+0x0024+(DMA_OFFSET*(_n)))
#define DMA_LEN2(_n)                (AP_DMA_base+0x0028+(DMA_OFFSET*(_n)))
#define DMA_VFF_THRE(_n)            (AP_DMA_base+0x0028+(DMA_OFFSET*(_n)))
#define DMA_JMP_ADDR(_n)            (AP_DMA_base+0x002c+(DMA_OFFSET*(_n)))
#define DMA_VFF_WPT(_n)             (AP_DMA_base+0x002c+(DMA_OFFSET*(_n)))
#define DMA_BUF_SIZE(_n)            (AP_DMA_base+0x0030+(DMA_OFFSET*(_n)))
#define DMA_VFF_RPT(_n)             (AP_DMA_base+0x0030+(DMA_OFFSET*(_n)))
#define DMA_CONNECT(_n)             (AP_DMA_base+0x0034+(DMA_OFFSET*(_n)))
#define DMA_W_INT_BUF_SIZE(_n)      (AP_DMA_base+0x0034+(DMA_OFFSET*(_n)))
#define DMA_FLOW_CTRL_THRE(_n)      (AP_DMA_base+0x0034+(DMA_OFFSET*(_n)))
#define DMA_INT_BUF_SIZE(_n)        (AP_DMA_base+0x0038+(DMA_OFFSET*(_n)))
#define DMA_VFF_VALID_SIZE(_n)      (AP_DMA_base+0x003c+(DMA_OFFSET*(_n)))
#define DMA_VFF_LEFT_SIZE(_n)       (AP_DMA_base+0x0040+(DMA_OFFSET*(_n)))
#define DMA_DEBUG(_n)               (AP_DMA_base+0x0050+(DMA_OFFSET*(_n)))

/* DMA Global Registers */
#define DMA2_GLBST_INT               (DMA_base+0x0000)
#define DMA2_GLOBAL_RESET            (DMA_base+0x0004)
#define DMA2_GLBST_RUNNING           (DMA_base+0x0008)
#define DMA2_GLOBAL_SLOW_DOWN        (DMA_base+0x000c)
#define DMA2_GLOBAL_INT_SEL          (DMA_base+0x0020)

/* DMA Security Registers */
#define DMA2_GLOBAL_SEC_EN           (DMA_base+0x0010)
#define DMA2_GLOBAL_GSEC_EN          (DMA_base+0x0014)
#define DMA2_GLOBAL_LAT_ADDR         (DMA_base+0x0018)
#define DMA2_GLOBAL_ABORT            (DMA_base+0x001c)

/* DMA Control Registers */
#define DMA2_INT_FLAG(_n)            (DMA_base+0x0000+(DMA_OFFSET*(_n)))
#define DMA2_INT_EN(_n)              (DMA_base+0x0004+(DMA_OFFSET*(_n)))
#define DMA2_START(_n)               (DMA_base+0x0008+(DMA_OFFSET*(_n)))
#define DMA2_RESET(_n)               (DMA_base+0x000c+(DMA_OFFSET*(_n)))
#define DMA2_STOP(_n)                (DMA_base+0x0010+(DMA_OFFSET*(_n)))
#define DMA2_FLUSH(_n)               (DMA_base+0x0014+(DMA_OFFSET*(_n)))
#define DMA2_CON(_n)                 (DMA_base+0x0018+(DMA_OFFSET*(_n)))
#define DMA2_MEM_ADDR(_n)            (DMA_base+0x001c+(DMA_OFFSET*(_n)))
#define DMA2_SRC(_n)                 (DMA_base+0x001c+(DMA_OFFSET*(_n)))
#define DMA2_DST(_n)                 (DMA_base+0x0020+(DMA_OFFSET*(_n)))
#define DMA2_LEN1(_n)                (DMA_base+0x0024+(DMA_OFFSET*(_n)))
#define DMA2_VFF_SIZE(_n)            (DMA_base+0x0024+(DMA_OFFSET*(_n)))
#define DMA2_LEN2(_n)                (DMA_base+0x0028+(DMA_OFFSET*(_n)))
#define DMA2_VFF_THRE(_n)            (DMA_base+0x0028+(DMA_OFFSET*(_n)))
#define DMA2_JMP_ADDR(_n)            (DMA_base+0x002c+(DMA_OFFSET*(_n)))
#define DMA2_VFF_WPT(_n)             (DMA_base+0x002c+(DMA_OFFSET*(_n)))
#define DMA2_BUF_SIZE(_n)            (DMA_base+0x0030+(DMA_OFFSET*(_n)))
#define DMA2_VFF_RPT(_n)             (DMA_base+0x0030+(DMA_OFFSET*(_n)))
#define DMA2_CONNECT(_n)             (DMA_base+0x0034+(DMA_OFFSET*(_n)))
#define DMA2_W_INT_BUF_SIZE(_n)      (DMA_base+0x0034+(DMA_OFFSET*(_n)))
#define DMA2_FLOW_CTRL_THRE(_n)      (DMA_base+0x0034+(DMA_OFFSET*(_n)))
#define DMA2_INT_BUF_SIZE(_n)        (DMA_base+0x0038+(DMA_OFFSET*(_n)))
#define DMA2_VFF_VALID_SIZE(_n)      (DMA_base+0x003c+(DMA_OFFSET*(_n)))
#define DMA2_VFF_LEFT_SIZE(_n)       (DMA_base+0x0040+(DMA_OFFSET*(_n)))
#define DMA2_DEBUG(_n)               (DMA_base+0x0050+(DMA_OFFSET*(_n)))




/* for backward compatible */
#define DMA_GLBSTA                  0x00000003                // this will cause data abort
#define DMA_COUNT(_n)               DMA_LEN1(_n)
#define DMA_WPPT(_n)                DMA_LEN2(_n)
#define DMA_WPTO(_n)                DMA_JMP_ADDR(_n)
#define DMA_PGMADDR(_n)             DMA_MEM_ADDR(_n)
#define DMA_ACKINT(_n)              DMA_INT_FLAG(_n)
#define DMA_RLCT(_n)                DMA_LEN1(_n)
#define DMA_LIMITER(_n)             DMA_CON(_n)
#define DMA_INTSTA(_n)              DMA_INT_FLAG(_n)
#define DMA_ALTLEN(_n)              DMA_FLOW_CTRL_THRE(_n)
#define DMA_FFSIZE(_n)              DMA_VFF_SIZE(_n)

#define DMA2_COUNT(_n)               DMA2_LEN1(_n)
#define DMA2_WPPT(_n)                DMA2_LEN2(_n)
#define DMA2_WPTO(_n)                DMA2_JMP_ADDR(_n)
#define DMA2_PGMADDR(_n)             DMA2_MEM_ADDR(_n)
#define DMA2_ACKINT(_n)              DMA2_INT_FLAG(_n)
#define DMA2_RLCT(_n)                DMA2_LEN1(_n)
#define DMA2_LIMITER(_n)             DMA2_CON(_n)
#define DMA2_INTSTA(_n)              DMA2_INT_FLAG(_n)
#define DMA2_ALTLEN(_n)              DMA2_FLOW_CTRL_THRE(_n)
#define DMA2_FFSIZE(_n)              DMA2_VFF_SIZE(_n)



#define DMA_FULL_CH_NUM     0
#define DMA_HALF_CH_NUM     2
#define DMA_VFF_CH_NUM      4

#define DMA2_FULL_CH_NUM     2
#define DMA2_HALF_CH_NUM     0
#define DMA2_VFF_CH_NUM      0

#define DMA_COUNT_MAX       0xFFFFF

/*
 * Define macros.
 */
 
#define DMA_GLBSTA_RUN(_n)          (0x00000001 << ((_n)-1))  /*_n = 1~11*/
#define DMA_GLBSTA_IT(_n)           (0x00000001 << ((_n)-1))  /*_n = 1~11*/

/*DMA_CON*/                         
#define DMA_CON_SIZE_MASK           0x00000003
#define DMA_CON_SIZE_BYTE           0x00000000
#define DMA_CON_SIZE_SHORT          0x00000001
#define DMA_CON_SIZE_LONG           0x00000002
                                       
#define DMA_CON_SFIX                0x00000010
#define DMA_CON_DFIX                0x00000008

#define DMA_CON_WSIZE_1BYTE         0x00000000
#define DMA_CON_WSIZE_2BYTE         0x00000001
#define DMA_CON_WSIZE_4BYTE         0x00000002
#define DMA_CON_WSIZE_OFFSET        24

#define DMA_CON_RSIZE_1BYTE         0x00000000
#define DMA_CON_RSIZE_2BYTE         0x00000001
#define DMA_CON_RSIZE_4BYTE         0x00000002
#define DMA_CON_RSIZE_OFFSET        28

#define DMA_CON_SLOW_EN             4
#define DMA_CON_SLOW_OFFSET         5
#define DMA_CON_SLOW_MASK           0x00007FE0
                                  
#define DMA_CON_BURST_SINGLE        0x00000000  /*without burst mode*/
#define DMA_CON_BURST_2BEAT         0x00000001  /*4-beat incrementing burst*/
#define DMA_CON_BURST_3BEAT         0x00000002  /*4-beat incrementing burst*/
#define DMA_CON_BURST_4BEAT         0x00000003  /*4-beat incrementing burst*/
#define DMA_CON_BURST_5BEAT         0x00000004  /*4-beat incrementing burst*/
#define DMA_CON_BURST_6BEAT         0x00000005  /*4-beat incrementing burst*/
#define DMA_CON_BURST_7BEAT         0x00000006  /*4-beat incrementing burst*/
#define DMA_CON_BURST_8BEAT         0x00000007  /*8-beat incrementing burst*/
#define DMA_CON_BURST_OFFSET        16

                                       
#define DMA_CON_WPSD                0x00100000  /*0:at source, 1: at destination*/
#define DMA_CON_WPEN                0x00008000  /*0:disable, 1: enable*/

//#define DMA_CON_DIR                 0x00000000  //mask by AB

#define DMA_START_BIT               0x00000001
#define DMA_W_RST_BIT               0x00000001
#define DMA_H_RST_BIT               0x00000002
#define DMA_STOP_BIT                0x00000001
#define DMA_PAUSE_BIT               0x00000002
#define DMA_ACKINT_BIT              0x00000000
#define DMA_INTSTA_BIT              0x00000001
#define DMA_INTSTA_BIT1             0x00000002

                                       
#define DMA_CON_RXCONTRL            1 /*hw management*/ //mask by AB
#define DMA_CON_TXCONTRL            0 /*hw management*/ //mask by AB
//#define DMA_CON_SWCOPY              0 /*hw management*/ //mask by AB
#define DMA_CON_FIXED_PATTERN       2

//#define DMA_CON_DRQ                 0x0000   /*1: HW management,0:SW */
//#define DMA_CON_TMOD                0x0000   /*1: Block mode, 0:Single mode*/
//#define DMA_CON_MAS                 0x0000   /*00:,01:UART1 Rx(1)/UART1 Tx(2),10: UART2 tx(1),UART2 rx(2),11:SIM*/
//#define DMA_CON_CYCLE_MASK          0x0000   /* Burst mode cycle */
//#define DMA_CON_ITEN                0x0000   /*Interrupt enable*/

#define DMA_CONNECT_HIF               0x00000001
#define DMA_CONNECT_WRITE             0x00000000
#define DMA_CONNECT_READ              0x00000004
#define DMA_REQ_ACK_RATIO_1_2         0x00000000
#define DMA_REQ_ACK_RATIO_1_1         0x00000008

#define DMA_TX_TRIGGER_LEVEL(n)     ((n)/8)     // trigger level of tx vfifo
#define DMA_RX_TRIGGER_LEVEL(n)     ((n)*3/4)   // trigger level of rx vfifo
#define DMA_VIFOF_ALERT_LENGTH      0x3f        // flow control trigger level

#define DMA_Start(_n)                DRV_WriteReg32(DMA_START(_n),DMA_START_BIT)
#define DMA_Reset(_n,_m)             DRV_WriteReg32(DMA_RESET(_n),_m?DMA_H_RST_BIT:DMA_W_RST_BIT)
#define DMA_Pause(_n)                DRV_WriteReg32(DMA_STOP(_n),DMA_PAUSE_BIT)
#define DMA_Resume(_n)               DRV_WriteReg32(DMA_STOP(_n),0)
#define DMA_Flush(_n)                DRV_WriteReg32(DMA_FLUSH(_n),1)
#define DMA_GetCount(_n)             DRV_Reg32(DMA_COUNT(_n))
#define DMA_ACKI(_n)                 DRV_WriteReg32(DMA_ACKINT(_n),DMA_ACKINT_BIT)
#define DMA_CH_SEL(_n)               DRV_Reg32(DMA_CON(_n)) |= (1<<(_n-2))

#define DMA2_Start(_n)                DRV_WriteReg32(DMA2_START(_n),DMA_START_BIT)
#define DMA2_Reset(_n,_m)             DRV_WriteReg32(DMA2_RESET(_n),_m?DMA_H_RST_BIT:DMA_W_RST_BIT)
#define DMA2_Pause(_n)                DRV_WriteReg32(DMA2_STOP(_n),DMA_PAUSE_BIT)
#define DMA2_Resume(_n)               DRV_WriteReg32(DMA2_STOP(_n),0)
#define DMA2_Flush(_n)                DRV_WriteReg32(DMA2_FLUSH(_n),1)
#define DMA2_GetCount(_n)             DRV_Reg32(DMA2_COUNT(_n))
#define DMA2_ACKI(_n)                 DRV_WriteReg32(DMA2_ACKINT(_n),DMA_ACKINT_BIT)
//#define DMA2_CH_SEL(_n)               DRV_Reg32(DMA2_CON(_n)) |= (1<<(_n-2))
#define DMA2_CH_SEL(_n)               while(0)



#define DMA_CON_MASTER_UART1TX       0x0B
#define DMA_CON_MASTER_UART1RX       0x0C
#define DMA_CON_MASTER_UART2TX       0x0D
#define DMA_CON_MASTER_UART2RX       0x0E
#define DMA_CON_MASTER_UART3TX       0x0F
#define DMA_CON_MASTER_UART3RX       0x10
#define DMA_CON_MASTER_UART4TX       0x11
#define DMA_CON_MASTER_UART4RX       0x12
/* in general, UART only has 3 ports so, MT6573 use uart port 2 to map UART4 */
#define DMA_REMP_UART_PORT4                   uart_port2

#if 0 // vport is obsolete
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#define DMA_WRPTR(_n)               DMA_VFF_WPT(_n)
#define DMA_RDPTR(_n)               DMA_VFF_RPT(_n)
#define DMA_FFCNT(_n)               DMA_VFF_VALID_SIZE(_n)
#define DMA_FFSTA(_n)               0x00000003
   
#define DMA_FFSTA_FULL              0x0001
#define DMA_FFSTA_EMPTY             0x0002
#define DMA_FFSTA_ALERT             0x0004

/* For Multi-Core DMA, DMA VIVFO channel always start from 0 logitically */
#define DMA_VFIFO_CH_S		0            		// start  of DMA Virtual fifo
#define DMA_VFIFO_CH_E		DMA_VFF_CH_NUM		// end of DMA Virtual fifo

#define DMA_VFIFO_PHY_CH_S  12      // Real VFIFO start channel number

//#define DMA_POP(_n)                 *(volatile kal_uint8*)DMA_VPORT(_n)
//#define DMA_PUSH(_n,_data)          *(volatile kal_uint8*)DMA_VPORT(_n) = (kal_uint8)_data
#define DMA_GetVFIFO_Avail(ch)      DRV_Reg(DMA_FFCNT(ch))
#define DMA_GetVFIFO_Roomleft(ch)   ( DRV_Reg(DMA_VFF_LEFT_SIZE(ch)) - 16 )            //VFF requires 16 bytes to do flush
#define IS_VFIFO_FULL(ch)           (DRV_Reg32(DMA_VFF_LEFT_SIZE(ch)) < 16)            //VFF requires 16 bytes to do flush
#define DMA_EnableINT(ch)                                                                    \
                                   do{                                                       \
                                      if( (ch >= DMA_VFIFO_PHY_CH_S) &&                          \
                                          (( ch & 0x1 ) == ((DMA_CON_MASTER_UART1RX+1) & 0x1)) ) \
                                      {                                                      \
                                         DRV_Reg32(DMA_INT_EN(ch)) = 3;                      \
                                      }                                                      \
                                      else                                                   \
                                      {                                                      \
                                         DRV_Reg32(DMA_INT_EN(ch)) = 1;                      \
                                      }                                                      \
                                    }while(0)
#define DMA_DisableINT(ch)          DRV_Reg32(DMA_INT_EN(ch)) = 0
#define DMA_TASK_PUSH(ch,data)      while(IS_VFIFO_FULL(ch)); \
                                          DMA_PUSH(ch,data)

#elif defined(MT6575)
   
#define __DMA_V3__
#define __MULTI_CORE_SHARED_DMA__
#define __DMA_SIM_TX_RX_SUPPORT__

/*compile option for including MD-side only DMA*/
#define __DMA2_SUPPORT__
	
#define DMA_OFFSET                  0x0080

/* DMA Global Registers */
#define DMA_GLBST_INT               (DMA_base+0x0000)
#define DMA_GLOBAL_RESET            (DMA_base+0x0004)
#define DMA_GLBST_RUNNING           (DMA_base+0x0008)
#define DMA_GLOBAL_SLOW_DOWN        (DMA_base+0x000c)
#define DMA_GLOBAL_INT_SEL          (DMA_base+0x0020)

/* DMA Security Registers */
#define DMA_GLOBAL_SEC_EN           (DMA_base+0x0010)
#define DMA_GLOBAL_GSEC_EN          (DMA_base+0x0014)
#define DMA_GLOBAL_LAT_ADDR         (DMA_base+0x0018)
#define DMA_GLOBAL_ABORT            (DMA_base+0x001c)
#define DMA_GDMA1_SEC_EN			(DMA_base+0x0020)
#define DMA_GDMA2_SEC_EN			(DMA_base+0x0024)
#define DMA_HIF1_SEC_EN				(DMA_base+0x0028)
#define DMA_HIF2_SEC_EN				(DMA_base+0x002c)
#define DMA_SIM1_SEC_EN				(DMA_base+0x0030)
#define DMA_SIM2_SEC_EN				(DMA_base+0x0034)
#define DMA_IRDA_SEC_EN				(DMA_base+0x0038)
#define DMA_UART1_TX_SEC_EN			(DMA_base+0x003c)
#define DMA_UART1_RX_SEC_EN			(DMA_base+0x0040)
#define DMA_UART2_TX_SEC_EN			(DMA_base+0x0044)
#define DMA_UART2_RX_SEC_EN			(DMA_base+0x0048)
#define DMA_UART3_TX_SEC_EN			(DMA_base+0x004c)
#define DMA_UART3_RX_SEC_EN			(DMA_base+0x0050)

/* DMA Control Registers */
#define DMA_INT_FLAG(_n)            (DMA_base+0x0000+(DMA_OFFSET*(_n)))
#define DMA_INT_EN(_n)              (DMA_base+0x0004+(DMA_OFFSET*(_n)))
#define DMA_START(_n)               (DMA_base+0x0008+(DMA_OFFSET*(_n)))
#define DMA_RESET(_n)               (DMA_base+0x000c+(DMA_OFFSET*(_n)))
#define DMA_STOP(_n)                (DMA_base+0x0010+(DMA_OFFSET*(_n)))
#define DMA_FLUSH(_n)               (DMA_base+0x0014+(DMA_OFFSET*(_n)))
#define DMA_CON(_n)                 (DMA_base+0x0018+(DMA_OFFSET*(_n)))
#define DMA_MEM_ADDR(_n)            (DMA_base+0x001c+(DMA_OFFSET*(_n)))
#define DMA_SRC(_n)                 (DMA_base+0x001c+(DMA_OFFSET*(_n)))
#define DMA_DST(_n)                 (DMA_base+0x0020+(DMA_OFFSET*(_n)))
#define DMA_LEN1(_n)                (DMA_base+0x0024+(DMA_OFFSET*(_n)))
#define DMA_VFF_SIZE(_n)            (DMA_base+0x0024+(DMA_OFFSET*(_n)))
#define DMA_LEN2(_n)                (DMA_base+0x0028+(DMA_OFFSET*(_n)))
#define DMA_VFF_THRE(_n)            (DMA_base+0x0028+(DMA_OFFSET*(_n)))
#define DMA_JMP_ADDR(_n)            (DMA_base+0x002c+(DMA_OFFSET*(_n)))
#define DMA_VFF_WPT(_n)             (DMA_base+0x002c+(DMA_OFFSET*(_n)))
#define DMA_BUF_SIZE(_n)            (DMA_base+0x0030+(DMA_OFFSET*(_n)))
#define DMA_VFF_RPT(_n)             (DMA_base+0x0030+(DMA_OFFSET*(_n)))
#define DMA_CONNECT(_n)             (DMA_base+0x0034+(DMA_OFFSET*(_n)))
#define DMA_W_INT_BUF_SIZE(_n)      (DMA_base+0x0034+(DMA_OFFSET*(_n)))
#define DMA_FLOW_CTRL_THRE(_n)      (DMA_base+0x0034+(DMA_OFFSET*(_n)))
#define DMA_INT_BUF_SIZE(_n)        (DMA_base+0x0038+(DMA_OFFSET*(_n)))
#define DMA_VFF_VALID_SIZE(_n)      (DMA_base+0x003c+(DMA_OFFSET*(_n)))
#define DMA_VFF_LEFT_SIZE(_n)       (DMA_base+0x0040+(DMA_OFFSET*(_n)))
#define DMA_DEBUG(_n)               (DMA_base+0x0050+(DMA_OFFSET*(_n)))

/* DMA Global Registers */
#define DMA2_GLBST_INT              (AP_DMA_base+0x0000)
#define DMA2_GLOBAL_RESET           (AP_DMA_base+0x0004)
#define DMA2_GLBST_RUNNING          (AP_DMA_base+0x0008)
#define DMA2_GLOBAL_SLOW_DOWN       (AP_DMA_base+0x000c)

// For MT6575, we use interrupt signal for each DMA channel for better security control.
// If MD-side/AP-side users want to use some specific DMA, they need to control MD/AP interrupt controller to unmask the corresponding DMA interrupt before using it.
//#define DMA2_GLOBAL_INT_SEL          (DMA_base+0x0020)

/* DMA Security Registers */
#define DMA2_GLOBAL_SEC_EN           (AP_DMA_base+0x0010)
#define DMA2_GLOBAL_GSEC_EN          (AP_DMA_base+0x0014)
#define DMA2_GLOBAL_LAT_ADDR         (AP_DMA_base+0x0018)
#define DMA2_GLOBAL_ABORT            (AP_DMA_base+0x001c)

/* DMA Control Registers */
#define DMA2_INT_FLAG(_n)            (AP_DMA_base+0x0000+(DMA_OFFSET*(_n)))
#define DMA2_INT_EN(_n)              (AP_DMA_base+0x0004+(DMA_OFFSET*(_n)))
#define DMA2_START(_n)               (AP_DMA_base+0x0008+(DMA_OFFSET*(_n)))
#define DMA2_RESET(_n)               (AP_DMA_base+0x000c+(DMA_OFFSET*(_n)))
#define DMA2_STOP(_n)                (AP_DMA_base+0x0010+(DMA_OFFSET*(_n)))
#define DMA2_FLUSH(_n)               (AP_DMA_base+0x0014+(DMA_OFFSET*(_n)))
#define DMA2_CON(_n)                 (AP_DMA_base+0x0018+(DMA_OFFSET*(_n)))
#define DMA2_MEM_ADDR(_n)            (AP_DMA_base+0x001c+(DMA_OFFSET*(_n)))
#define DMA2_SRC(_n)                 (AP_DMA_base+0x001c+(DMA_OFFSET*(_n)))
#define DMA2_DST(_n)                 (AP_DMA_base+0x0020+(DMA_OFFSET*(_n)))
#define DMA2_LEN1(_n)                (AP_DMA_base+0x0024+(DMA_OFFSET*(_n)))
#define DMA2_VFF_SIZE(_n)            (AP_DMA_base+0x0024+(DMA_OFFSET*(_n)))
#define DMA2_LEN2(_n)                (AP_DMA_base+0x0028+(DMA_OFFSET*(_n)))
#define DMA2_VFF_THRE(_n)            (AP_DMA_base+0x0028+(DMA_OFFSET*(_n)))
#define DMA2_JMP_ADDR(_n)            (AP_DMA_base+0x002c+(DMA_OFFSET*(_n)))
#define DMA2_VFF_WPT(_n)             (AP_DMA_base+0x002c+(DMA_OFFSET*(_n)))
#define DMA2_BUF_SIZE(_n)            (AP_DMA_base+0x0030+(DMA_OFFSET*(_n)))
#define DMA2_VFF_RPT(_n)             (AP_DMA_base+0x0030+(DMA_OFFSET*(_n)))
#define DMA2_CONNECT(_n)             (AP_DMA_base+0x0034+(DMA_OFFSET*(_n)))
#define DMA2_W_INT_BUF_SIZE(_n)      (AP_DMA_base+0x0034+(DMA_OFFSET*(_n)))
#define DMA2_FLOW_CTRL_THRE(_n)      (AP_DMA_base+0x0034+(DMA_OFFSET*(_n)))
#define DMA2_INT_BUF_SIZE(_n)        (AP_DMA_base+0x0038+(DMA_OFFSET*(_n)))
#define DMA2_VFF_VALID_SIZE(_n)      (AP_DMA_base+0x003c+(DMA_OFFSET*(_n)))
#define DMA2_VFF_LEFT_SIZE(_n)       (AP_DMA_base+0x0040+(DMA_OFFSET*(_n)))
#define DMA2_DEBUG(_n)               (AP_DMA_base+0x0050+(DMA_OFFSET*(_n)))

/* for backward compatible */
#define DMA_GLBSTA                  0x00000003                // this will cause data abort
#define DMA_COUNT(_n)               DMA_LEN1(_n)
#define DMA_WPPT(_n)                DMA_LEN2(_n)
#define DMA_WPTO(_n)                DMA_JMP_ADDR(_n)
#define DMA_PGMADDR(_n)             DMA_MEM_ADDR(_n)
#define DMA_ACKINT(_n)              DMA_INT_FLAG(_n)
#define DMA_RLCT(_n)                DMA_LEN1(_n)
#define DMA_LIMITER(_n)             DMA_CON(_n)
#define DMA_INTSTA(_n)              DMA_INT_FLAG(_n)
#define DMA_ALTLEN(_n)              DMA_FLOW_CTRL_THRE(_n)
#define DMA_FFSIZE(_n)              DMA_VFF_SIZE(_n)

#define DMA2_COUNT(_n)               DMA2_LEN1(_n)
#define DMA2_WPPT(_n)                DMA2_LEN2(_n)
#define DMA2_WPTO(_n)                DMA2_JMP_ADDR(_n)
#define DMA2_PGMADDR(_n)             DMA2_MEM_ADDR(_n)
#define DMA2_ACKINT(_n)              DMA2_INT_FLAG(_n)
#define DMA2_RLCT(_n)                DMA2_LEN1(_n)
#define DMA2_LIMITER(_n)             DMA2_CON(_n)
#define DMA2_INTSTA(_n)              DMA2_INT_FLAG(_n)
#define DMA2_ALTLEN(_n)              DMA2_FLOW_CTRL_THRE(_n)
#define DMA2_FFSIZE(_n)              DMA2_VFF_SIZE(_n)

/*AP-side*/
#define DMA2_FULL_CH_NUM     2	//DSP performance test requires AP GDMA for stressing
#define DMA2_HALF_CH_NUM     4	//since MD-side needs SIM and HIF, config the channels for SIM_1, SIM_2, HIF_1, HIF_2
#define DMA2_VFF_CH_NUM      0	//for MD-side, we don't use AP-side's UART

/*MD-side*/
#define DMA_FULL_CH_NUM     2	//for MD-side GDMA1 and GDMA2
#define DMA_HALF_CH_NUM     0	//we don't have peripheral DMA
#define DMA_VFF_CH_NUM      4	//for MD-side UART1 TX, UART1 RX, UART2 TX, UART2 RX

#define DMA_COUNT_MAX       0xFFFFF

/*
 * Define macros.
 */
 
#define DMA_GLBSTA_RUN(_n)          (0x00000001 << ((_n)-1))  /*_n = 1~11*/
#define DMA_GLBSTA_IT(_n)           (0x00000001 << ((_n)-1))  /*_n = 1~11*/

/*DMA_CON*/                         
#define DMA_CON_SIZE_MASK           0x00000003
#define DMA_CON_SIZE_BYTE           0x00000000
#define DMA_CON_SIZE_SHORT          0x00000001
#define DMA_CON_SIZE_LONG           0x00000002
                                       
#define DMA_CON_SFIX                0x00000010
#define DMA_CON_DFIX                0x00000008

#define DMA_CON_WSIZE_1BYTE         0x00000000
#define DMA_CON_WSIZE_2BYTE         0x00000001
#define DMA_CON_WSIZE_4BYTE         0x00000002
#define DMA_CON_WSIZE_OFFSET        24

#define DMA_CON_RSIZE_1BYTE         0x00000000
#define DMA_CON_RSIZE_2BYTE         0x00000001
#define DMA_CON_RSIZE_4BYTE         0x00000002
#define DMA_CON_RSIZE_OFFSET        28

#define DMA_CON_SLOW_EN             4
#define DMA_CON_SLOW_OFFSET         5
#define DMA_CON_SLOW_MASK           0x00007FE0
                                  
#define DMA_CON_BURST_SINGLE        0x00000000  /*without burst mode*/
#define DMA_CON_BURST_2BEAT         0x00000001  /*4-beat incrementing burst*/
#define DMA_CON_BURST_3BEAT         0x00000002  /*4-beat incrementing burst*/
#define DMA_CON_BURST_4BEAT         0x00000003  /*4-beat incrementing burst*/
#define DMA_CON_BURST_5BEAT         0x00000004  /*4-beat incrementing burst*/
#define DMA_CON_BURST_6BEAT         0x00000005  /*4-beat incrementing burst*/
#define DMA_CON_BURST_7BEAT         0x00000006  /*4-beat incrementing burst*/
#define DMA_CON_BURST_8BEAT         0x00000007  /*8-beat incrementing burst*/
#define DMA_CON_BURST_OFFSET        16
                                       
#define DMA_CON_WPSD                0x00100000  /*0:at source, 1: at destination*/
#define DMA_CON_WPEN                0x00008000  /*0:disable, 1: enable*/

//#define DMA_CON_DIR                 0x00000000  //mask by AB

#define DMA_START_BIT               0x00000001
#define DMA_W_RST_BIT               0x00000001
#define DMA_H_RST_BIT               0x00000002
#define DMA_STOP_BIT                0x00000001
#define DMA_PAUSE_BIT               0x00000002
#define DMA_ACKINT_BIT              0x00000000
#define DMA_INTSTA_BIT              0x00000001
#define DMA_INTSTA_BIT1             0x00000002
                                       
#define DMA_CON_RXCONTRL            1 /*hw management*/ //mask by AB
#define DMA_CON_TXCONTRL            0 /*hw management*/ //mask by AB
//#define DMA_CON_SWCOPY              0 /*hw management*/ //mask by AB
#define DMA_CON_FIXED_PATTERN       2

//#define DMA_CON_DRQ                 0x0000   /*1: HW management,0:SW */
//#define DMA_CON_TMOD                0x0000   /*1: Block mode, 0:Single mode*/
//#define DMA_CON_MAS                 0x0000   /*00:,01:UART1 Rx(1)/UART1 Tx(2),10: UART2 tx(1),UART2 rx(2),11:SIM*/
//#define DMA_CON_CYCLE_MASK          0x0000   /* Burst mode cycle */
//#define DMA_CON_ITEN                0x0000   /*Interrupt enable*/
   
#define DMA_CONNECT_HIF               0x00000001
#define DMA_CONNECT_WRITE             0x00000000
#define DMA_CONNECT_READ              0x00000004
#define DMA_REQ_ACK_RATIO_1_2         0x00000000
#define DMA_REQ_ACK_RATIO_1_1         0x00000008
#define DMA_TX_TRIGGER_LEVEL(n)     ((n)/8)     // trigger level of tx vfifo
#define DMA_RX_TRIGGER_LEVEL(n)     ((n)*3/4)   // trigger level of rx vfifo
#define DMA_VIFOF_ALERT_LENGTH      0x3f        // flow control trigger level

#define DMA_Start(_n)                DRV_WriteReg32(DMA_START(_n),DMA_START_BIT)
#define DMA_Reset(_n,_m)             DRV_WriteReg32(DMA_RESET(_n),_m?DMA_H_RST_BIT:DMA_W_RST_BIT)
#define DMA_Pause(_n)                DRV_WriteReg32(DMA_STOP(_n),DMA_PAUSE_BIT)
#define DMA_Resume(_n)               DRV_WriteReg32(DMA_STOP(_n),0)
#define DMA_Flush(_n)                DRV_WriteReg32(DMA_FLUSH(_n),1)
#define DMA_GetCount(_n)             DRV_Reg32(DMA_COUNT(_n))
#define DMA_ACKI(_n)                 DRV_WriteReg32(DMA_ACKINT(_n),DMA_ACKINT_BIT)
#define DMA_CH_SEL(_n)               DRV_Reg32(DMA_CON(_n)) |= (1<<(_n-2))

#define DMA2_Start(_n)                DRV_WriteReg32(DMA2_START(_n),DMA_START_BIT)
#define DMA2_Reset(_n,_m)             DRV_WriteReg32(DMA2_RESET(_n),_m?DMA_H_RST_BIT:DMA_W_RST_BIT)
#define DMA2_Pause(_n)                DRV_WriteReg32(DMA2_STOP(_n),DMA_PAUSE_BIT)
#define DMA2_Resume(_n)               DRV_WriteReg32(DMA2_STOP(_n),0)
#define DMA2_Flush(_n)                DRV_WriteReg32(DMA2_FLUSH(_n),1)
#define DMA2_GetCount(_n)             DRV_Reg32(DMA2_COUNT(_n))
#define DMA2_ACKI(_n)                 DRV_WriteReg32(DMA2_ACKINT(_n),DMA_ACKINT_BIT)
#define DMA2_CH_SEL(_n)               DRV_Reg32(DMA2_CON(_n)) |= (1<<(_n-2))

//MD-side register offset for UART config
#define DMA_CON_MASTER_UART1TX       0x02	//(0x180/0x80) -1
#define DMA_CON_MASTER_UART1RX       0x03	//(0x200/0x80) -1
#define DMA_CON_MASTER_UART2TX       0x04	//(0x280/0x80) -1
#define DMA_CON_MASTER_UART2RX       0x05	//(0x300/0x80) -1

//MT6575 AP-side only has 3 UART ports
/* in general, UART only has 3 ports so, MT6573 use uart port 2 to map UART4 */
//#define DMA_REMP_UART_PORT4        	 uart_port2

#if 0 //obsolete
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#define DMA_WRPTR(_n)               DMA_VFF_WPT(_n)
#define DMA_RDPTR(_n)               DMA_VFF_RPT(_n)
#define DMA_FFCNT(_n)               DMA_VFF_VALID_SIZE(_n)
#define DMA_FFSTA(_n)               0x00000003
   
#define DMA_FFSTA_FULL              0x0001
#define DMA_FFSTA_EMPTY             0x0002
#define DMA_FFSTA_ALERT             0x0004

/* For Multi-Core DMA, DMA VIVFO channel always start from 0 logitically */
#define DMA_VFIFO_CH_S		0            		// start  of DMA Virtual fifo
#define DMA_VFIFO_CH_E		DMA_VFF_CH_NUM		// end of DMA Virtual fifo

#define DMA_VFIFO_PHY_CH_S  3      // Real VFIFO start channel number

//#define DMA_POP(_n)                 *(volatile kal_uint8*)DMA_VPORT(_n)
//#define DMA_PUSH(_n,_data)          *(volatile kal_uint8*)DMA_VPORT(_n) = (kal_uint8)_data
#define DMA_GetVFIFO_Avail(ch)      DRV_Reg(DMA_FFCNT(ch))
#define DMA_GetVFIFO_Roomleft(ch)   ( DRV_Reg(DMA_VFF_LEFT_SIZE(ch)) - 16 )            //VFF requires 16 bytes to do flush
#define IS_VFIFO_FULL(ch)           (DRV_Reg32(DMA_VFF_LEFT_SIZE(ch)) < 16)            //VFF requires 16 bytes to do flush
#define DMA_EnableINT(ch)                                                                    \
                                   do{                                                       \
                                      if( (ch >= DMA_VFIFO_PHY_CH_S) &&                          \
                                          (( ch & 0x1 ) == ((DMA_CON_MASTER_UART1RX+1) & 0x1)) ) \
                                      {                                                      \
                                         DRV_Reg32(DMA_INT_EN(ch)) = 3;                      \
                                      }                                                      \
                                      else                                                   \
                                      {                                                      \
                                         DRV_Reg32(DMA_INT_EN(ch)) = 1;                      \
                                      }                                                      \
                                    }while(0)
#define DMA_DisableINT(ch)          DRV_Reg32(DMA_INT_EN(ch)) = 0
#define DMA_TASK_PUSH(ch,data)      while(IS_VFIFO_FULL(ch)); \
                                          DMA_PUSH(ch,data)

#else   /* MT6205 || MT6205B || MT6208 || FPGA */

   /*4~11 hw management dma, 1~3 are normal dma*/
   #define DMA_GLBSTA                  (DMA_base+0x0000) 
   #define DMA_GLBSTA2                 (DMA_base+0x0004)
   #define DMA_SRC(_n)                 (DMA_base+(0x0100*(_n)))           /*_n = 1~3*/
   #define DMA_DST(_n)                 (DMA_base+0x0004+(0x0100*(_n)))    /*_n = 1~3*/
   #define DMA_WPPT(_n)                (DMA_base+0x0008+(0x0100*(_n)))    /*_n = 1~11*/
   #define DMA_WPTO(_n)                (DMA_base+0x000c+(0x0100*(_n)))    /*_n = 1~11*/
   #define DMA_COUNT(_n)               (DMA_base+0x0010+(0x0100*(_n)))    /*_n = 1~11*/
   #define DMA_CON(_n)                 (DMA_base+0x0014+(0x0100*(_n)))    /*_n = 1~11*/
   #define DMA_START(_n)               (DMA_base+0x0018+(0x0100*(_n)))    /*_n = 1~11*/
   #define DMA_INTSTA(_n)              (DMA_base+0x001c+(0x0100*(_n)))    /*_n = 1~11*/
   #define DMA_ACKINT(_n)              (DMA_base+0x0020+(0x0100*(_n)))    /*_n = 1~11*/
   #define DMA_RLCT(_n)                (DMA_base+0x0024+(0x0100*(_n)))    /*_n = 1~11*/  /*DEBUG*/
   #define DMA_LIMITER(_n)             (DMA_base+0x0028+(0x0100*(_n)))    /*_n = 1~11*/
   #define DMA_PGMADDR(_n)             (DMA_base+0x002c+(0x0100*(_n)))    /*_n = 4~11*/
                                       
   #define DMA_GLBSTA_RUN(_n)          (0x00000001 << (2*((_n)-1)))  /*_n = 1~11*/
   #define DMA_GLBSTA_IT(_n)           (0x00000002 << (2*((_n)-1)))  /*_n = 1~11*/
                                       
   #define DMA_COUNT_MASK              0xffff
                                       
   /*DMA_CON*/                         
   #define DMA_CON_SIZE_MASK           0x00000003
   #define DMA_CON_SIZE_BYTE           0x00000000
   #define DMA_CON_SIZE_SHORT          0x00000001
   #define DMA_CON_SIZE_LONG           0x00000002
                                       
   #define DMA_CON_SINC                0x00000004
   #define DMA_CON_DINC                0x00000008
   #define DMA_CON_DRQ                 0x00000010  /*1:hw, 0:sw*/
                                       
#ifdef MT6218                          
   #define DMA_CON_TMOD                0x00000100  /*1:burst, 0:single*/
   #define DMA_CON_CYCLE_MASK          0x00003e00  /*burst cycle*/
#elif defined(MT6260)                              
   #define DMA_CON_B2W                 0x00000020  /*word to byte or byte to word*/
   #define DMA_CON_BURST_SINGLE        0x00000000  /*without burst mode*/
   #define DMA_CON_BURST_4BEAT         0x00000200  /*4-beat incrementing burst*/
   #define DMA_CON_BURST_8BEAT         0x00000200  /*4-beat incrementing burst*/
   #define DMA_CON_BURST_16BEAT        0x00000200  /*4-beat incrementing burst*/
#else                                 
   #define DMA_CON_B2W                 0x00000020  /*word to byte or byte to word*/
   #define DMA_CON_BURST_SINGLE        0x00000000  /*without burst mode*/
   #define DMA_CON_BURST_4BEAT         0x00000200  /*4-beat incrementing burst*/
   #define DMA_CON_BURST_8BEAT         0x00000400  /*8-beat incrementing burst*/
   #define DMA_CON_BURST_16BEAT        0x00000600  /*16-beat incrementing burst*/
#endif                                 
                                       
   #define DMA_CON_ITEN                0x00008000  /*Interrupt enable*/
   #define DMA_CON_WPSD                0x00010000  /*0:at source, 1: at destination*/
   #define DMA_CON_WPEN                0x00020000  /*0:disable, 1: enable*/
   #define DMA_CON_DIR                 0x00040000  /*Only valid when dma = 4~11*/
#if defined (MT6250) || defined (MT6260)
   #define DMA_CON_MASTER_MASK         0x001f00000  /*Only valid when dma = 4~11*/
#else
   #define DMA_CON_MASTER_MASK         0x00f00000  /*Only valid when dma = 4~11*/
#endif //#if defined (MT6250) || defined (MT6260)                                      
   #define DMA_CON_RXCONTRL            (DMA_CON_DIR|DMA_CON_DINC) /*hw management*/
   #define DMA_CON_TXCONTRL            (DMA_CON_SINC) /*hw management*/
   #define DMA_CON_SWCOPY              (DMA_CON_SINC|DMA_CON_DINC) /*hw management*/

#if defined (MT6250)
#define DMA_CON_MASTER_RESERVED_0	(0)
#define DMA_CON_MASTER_MSDC		    (1)
#define DMA_CON_MASTER_SIM		    (2)
#define DMA_CON_MASTER_SIM2		    (3)
#define DMA_CON_MASTER_USB1TX		(4)
#define DMA_CON_MASTER_USB1RX		(5)
#define DMA_CON_MASTER_USB2TX		(6)
#define DMA_CON_MASTER_USB2RX		(7)
#define DMA_CON_MASTER_UART1TX		(8)
#define DMA_CON_MASTER_UART1RX		(9)
#define DMA_CON_MASTER_UART2TX		(10)
#define DMA_CON_MASTER_UART2RX		(11)
#define DMA_CON_MASTER_UART3TX		(12)
#define DMA_CON_MASTER_UART3RX		(13)
#define DMA_CON_MASTER_BTIFRX		(14)
#define DMA_CON_MASTER_BTIFTX		(15)
#define DMA_CON_MASTER_HIF0		    (16)
#define DMA_CON_MASTER_HIF1		    (17)
#define DMA_CON_MASTER_RESERVED_18  (18)  //, AST: i hope reserved_xx is annotated by its index number in total channels.
#elif defined (MT6260) 
#define DMA_CON_MASTER_RESERVED_0	(0)
#define DMA_CON_MASTER_RESERVED_1	(1)
#define DMA_CON_MASTER_MSDC		    (2)
#define DMA_CON_MASTER_SIM		    (3)
#define DMA_CON_MASTER_SIM2		    (4)
#define DMA_CON_MASTER_USB1TX		(5)
#define DMA_CON_MASTER_USB1RX		(6)
#define DMA_CON_MASTER_USB2TX		(7)
#define DMA_CON_MASTER_HIF0		    (8)
#define DMA_CON_MASTER_MSDC2	    (9) //need to confirm naming with MSDC driver owner
#define DMA_CON_MASTER_UART1TX		(10)
#define DMA_CON_MASTER_UART1RX		(11)
#define DMA_CON_MASTER_UART2TX		(12)
#define DMA_CON_MASTER_UART2RX		(13)
#define DMA_CON_MASTER_BTIFRX		(14)
#define DMA_CON_MASTER_BTIFTX		(15)
#define DMA_CON_MASTER_RESERVED_16	(16)

#else //#if defined (MT6250)
   #define DMA_CON_MASTER_SIM          0x00
   #define DMA_CON_MASTER_MSDC         0x01
   #if defined(MT6251) || defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
   #define DMA_CON_MASTER_RESERVED_1     0x02
   #define DMA_CON_MASTER_RESERVED_2     0x03
   #else
   #define DMA_CON_MASTER_IRDATX       0x02
   #define DMA_CON_MASTER_IRDARX       0x03
   #endif
   #if defined(MT6238)||defined(MT6239)||defined(MT6235)||defined(MT6235B)||defined(MT6253T)||defined(MT6253)
   
   #define DMA_CON_MASTER_RESERVED_1       0x04
   #define DMA_CON_MASTER_RESERVED_2       0x05
   #define DMA_CON_MASTER_RESERVED_3       0x06
   #define DMA_CON_MASTER_RESERVED_4       0x07
   
   #elif defined(MT6268A) || defined(MT6268)

   #define DMA_CON_MASTER_I2C2TX           0x04
   #define DMA_CON_MASTER_I2C2RX           0x05
   #define DMA_CON_MASTER_RESERVED_1       0x06
   #define DMA_CON_MASTER_RESERVED_2       0x07

   #else
   
   #define DMA_CON_MASTER_USB1RX       0x04
   #define DMA_CON_MASTER_USB1TX       0x05
   #define DMA_CON_MASTER_USB2RX       0x06
   #define DMA_CON_MASTER_USB2TX       0x07
   
   #endif

   #define DMA_CON_MASTER_UART1TX      0x08
   #define DMA_CON_MASTER_UART1RX      0x09
   #define DMA_CON_MASTER_UART2TX      0x0a
   #define DMA_CON_MASTER_UART2RX      0x0b
   #if defined(MT6251)
   #define DMA_CON_MASTER_RESERVED_3       0x0c
   #define DMA_CON_MASTER_RESERVED_4       0x0d
   #else
   #define DMA_CON_MASTER_UART3TX      0x0c
   #define DMA_CON_MASTER_UART3RX      0x0d
   #endif
   #define DMA_CON_MASTER_IDMA         0x0e
   
#if defined(MT6251)
   #define DMA_CON_MASTER_RESERVED_5       0x0f
   #define DMA_CON_MASTER_RESERVED_6       0x10
#elif defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
   #define DMA_CON_MASTER_RESERVED_3       0x0f
   #define DMA_CON_MASTER_RESERVED_4       0x10
#else   
#if ( !defined(MT6218B) && !defined(MT6217) )
   #define DMA_CON_MASTER_NFITX        0x0f
   #define DMA_CON_MASTER_NFIRX        0x10
#endif                                 
#endif                                        
#if defined(MT6238)||defined(MT6239)||defined(MT6235)||defined(MT6235B)||defined(MT6268A)||defined(MT6268) || defined(MT6270A)
   #define DMA_CON_MASTER_DSPDMA2       0x11
   #define DMA_CON_MASTER_I2CTX        	0x12
   #define DMA_CON_MASTER_I2CRX        	0x13
   #define DMA_CON_MASTER_MSDC2        	0x14
   #define DMA_CON_MASTER_SIM2        	0x15
#elif defined(MT6253T)||defined(MT6253)||defined(MT6251) || defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
   #define DMA_CON_MASTER_I2CTX        	0x11
   #define DMA_CON_MASTER_I2CRX        	0x12
   #define DMA_CON_MASTER_SIM2        	0x13
 #endif
#if defined(MT6251)
   #define DMA_CON_MASTER_DSPDMA2       0x14
#endif
#if defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
   #define DMA_CON_MASTER_IDMA2         0x14
#endif
#endif //#if defined (MT6250)

   #define DMA_START_BIT               0x00008000
   #define DMA_STOP_BIT                0x00000000
   #define DMA_ACKINT_BIT              0x00008000
   #define DMA_INTSTA_BIT              0x00008000
                                       
   #define DMA_RLCT_MASK               0x0000ffff
                                       
   #define DMA_LIMITER_MASK            0x000000ff
   // add for virtual fifo
#if ( defined(MT6218B) || defined(MT6217) )
   #define DMA_VFIFO_CH_S               10      // start  of DMA Virtual fifo 
   #define DMA_VFIFO_CH_E               13      // end of DMA Virtual fifo    
#elif ( defined(MT6253T) || defined(MT6253) )
   #define DMA_VFIFO_CH_S               12      // start  of DMA Virtual fifo 
   #define DMA_VFIFO_CH_E               17      // end of DMA Virtual fifo  
#elif defined(MT6268) || defined(MT6270A)
   #define DMA_VFIFO_CH_S               11      // start  of DMA Virtual fifo
   #define DMA_VFIFO_CH_E               16      // end of DMA Virtual fifo 
#elif defined(MT6251)
   #define DMA_VFIFO_CH_S               13      // start  of DMA Virtual fifo
   #define DMA_VFIFO_CH_E               16      // end of DMA Virtual fifo 
#elif defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
   #define DMA_VFIFO_CH_S               10      // start  of DMA Virtual fifo
   #define DMA_VFIFO_CH_E               15      // end of DMA Virtual fifo 
#elif defined (MT6250)                                  
   #define DMA_VFIFO_CH_S               8      // start  of DMA Virtual fifo 
   #define DMA_VFIFO_CH_E               15      // end of DMA Virtual fifo   
   #if defined (__BTMODULE_MT6250__)
   #define __DMA_BT_VIRTUAL_FIFO__
   #endif //   #if defined (__BTMODULE_MT6250__)
#elif defined (MT6260)                                  
   #define DMA_VFIFO_CH_S               10      // start  of DMA Virtual fifo 
   #define DMA_VFIFO_CH_E               15      // end of DMA Virtual fifo   
   #if defined (__BTMODULE_MT6260__)
   #define __DMA_BT_VIRTUAL_FIFO__
   #endif //   #if defined (__BTMODULE_MT6260__)   
#else                                  
   #define DMA_VFIFO_CH_S               11      // start  of DMA Virtual fifo 
   #define DMA_VFIFO_CH_E               14      // end of DMA Virtual fifo    
#endif                                 
                                       

#if defined(MT6238)||defined(MT6239)||defined(MT6235)||defined(MT6235B)
   #define DMA_VPORT_BASE              0x61000000
#elif defined(MT6268A) || defined(MT6268)
   #define DMA_VPORT_BASE              0x64000000
#elif defined(MT6250) 
   #define DMA_VPORT_BASE               (DMA_AHB_base)
#elif defined(MT6260) 
   #define DMA_VPORT_BASE               (DMA_AHB_base)
#else  /* MT6238 */
   #define DMA_VPORT_BASE              0x78000000
#endif  /* MT6238 */

   #define DMA_VPORT(_n)               (DMA_VPORT_BASE+0x0100*(_n-DMA_VFIFO_CH_S))    /*_n = 10~13*/
   #define DMA_WRPTR(_n)               (DMA_base+0x0030+(0x0100*(_n)))    /*_n = 10~13*/
   #define DMA_RDPTR(_n)               (DMA_base+0x0034+(0x0100*(_n)))    /*_n = 10~13*/
   #define DMA_FFCNT(_n)               (DMA_base+0x0038+(0x0100*(_n)))    /*_n = 10~13*/
   #define DMA_FFSTA(_n)               (DMA_base+0x003c+(0x0100*(_n)))    /*_n = 10~13*/
   #define DMA_ALTLEN(_n)              (DMA_base+0x0040+(0x0100*(_n)))    /*_n = 10~13*/
   #define DMA_FFSIZE(_n)              (DMA_base+0x0044+(0x0100*(_n)))    /*_n = 10~13*/

   #define DMA_FFSTA_FULL              0x0001
   #define DMA_FFSTA_EMPTY             0x0002
   #define DMA_FFSTA_ALERT             0x0004

   #define DMA_POP(_n)                 *(volatile kal_uint8*)DMA_VPORT(_n)
   #define DMA_PUSH(_n,_data)          *(volatile kal_uint8*)DMA_VPORT(_n) = (kal_uint8)_data
   #define DMA_GetVFIFO_Avail(ch)      DRV_Reg(DMA_FFCNT(ch))
   #define DMA_GetVFIFO_Roomleft(ch)   DRV_Reg(DMA_FFSIZE(ch)) - DMA_GetVFIFO_Avail(ch)
   #define IS_VFIFO_FULL(ch)           (DRV_Reg32(DMA_FFSTA(ch)) & DMA_FFSTA_FULL)
   #define DMA_EnableINT(ch)           DRV_Reg32(DMA_CON(ch)) |= DMA_CON_ITEN
   #define DMA_DisableINT(ch)          DRV_Reg32(DMA_CON(ch)) &= ~DMA_CON_ITEN
   #define DMA_TASK_PUSH(ch,data)      while(IS_VFIFO_FULL(ch)); \
                                       DMA_PUSH(ch,data)   

#if defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
#else   /* __WCDMA_RAT__ */
   #define DMA_TX_TRIGGER_LEVEL(n)     ((n)/8)      // trigger level of tx vfifo
#endif  /* __UMTS_RAT__ */

   #define DMA_RX_TRIGGER_LEVEL(n)     ((n)*3/4)   // trigger level of rx vfifo

   #define DMA_VIFOF_ALERT_LENGTH      0x3f         // flow control trigger level
   
#endif //#if ( (defined(MT6205)) || (defined(MT6205B)) || (defined(MT6208)) || (defined(FPGA)) )


#if defined(__MULTI_CORE_SHARED_DMA__)

#if defined(MT6573)
#define DMA_IRQ_CODE                 IRQ_DMA_AP_CODE
/* DMA is AP side DMA  */
#define DMA_POWER_ON()         *(volatile kal_uint32*)(AP_CONFIG_base + 0x00000318) = 0x00000010
#define DMA_SLEEP_ENABLE()     *(volatile kal_uint32*)(AP_CONFIG_base + 0x00000314) = 0x00000010
#define DMA_SLEEP_DISABLE()    *(volatile kal_uint32*)(AP_CONFIG_base + 0x00000318) = 0x00000010

#define DMA2_IRQ_CODE                IRQ_DMA_CODE
/* DMA2 is MD side DMA, using PDN macro to control DMA */
#define DMA2_POWER_ON()         PDN_CLR(PDN_DMA)
#define DMA2_SLEEP_ENABLE()     PDN_SET(PDN_DMA)
#define DMA2_SLEEP_DISABLE()    PDN_CLR(PDN_DMA)

#elif defined(MT6575)
/* AP side DMA  */
//#define DMA2_IRQ_CODE           	IRQ_DMA_AP_CODE
#define DMA2_POWER_ON()         *(volatile kal_uint32*)(AP_CONFIG_base + 0x00000018) &= ~0x00001000
#define DMA2_SLEEP_ENABLE()     *(volatile kal_uint32*)(AP_CONFIG_base + 0x00000018) |= 0x00001000
#define DMA2_SLEEP_DISABLE()    *(volatile kal_uint32*)(AP_CONFIG_base + 0x00000018) &= ~0x00001000

/* MD side DMA, using PDN macro to control DMA */
#define DMA_IRQ_CODE          	IRQ_DMA_CODE
#define DMA_POWER_ON()        	PDN_CLR(PDN_DMA)
#define DMA_SLEEP_ENABLE()		PDN_SET(PDN_DMA)
#define DMA_SLEEP_DISABLE()    PDN_CLR(PDN_DMA)
#endif

#else //__MULTI_CORE_SHARED_DMA__

#define DMA_IRQ_CODE                 IRQ_DMA_CODE

#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
#if defined(TK6516)
#define DMA_POWER_ON()       *(volatile kal_uint16 *) DRVPDN_CON1_CLR = DRVPDN_CON1_DMA
#define DMA_SLEEP_ENABLE()   DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_DMA,PDN_DMA)
#define DMA_SLEEP_DISABLE()  DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_DMA,PDN_DMA);
#else   /* TK6516 */
#define DMA_POWER_ON()       *(volatile kal_uint16 *) DRVPDN_CON0_CLR = DRVPDN_CON0_DMA
#define DMA_SLEEP_ENABLE()   DRVPDN_Enable(DRVPDN_CON0,DRVPDN_CON0_DMA,PDN_DMA)
#define DMA_SLEEP_DISABLE()  DRVPDN_Disable(DRVPDN_CON0,DRVPDN_CON0_DMA,PDN_DMA)
#endif /* TK6516 */
#elif defined(__CLKG_DEFINE__)
#define DMA_POWER_ON()       *(volatile kal_uint16 *)CG_CLR0 = CG_CON0_DMA
#define DMA_SLEEP_ENABLE()   DRVPDN_Enable(CG_CON0, CG_CON0_DMA, PDN_DMA)
#define DMA_SLEEP_DISABLE()  DRVPDN_Disable(CG_CON0, CG_CON0_DMA, PDN_DMA)
#endif
#else   /* __OLD_PDN_ARCH__ */
#define DMA_POWER_ON()       PDN_CLR(PDN_DMA)
#define DMA_SLEEP_ENABLE()   PDN_SET(PDN_DMA)
#define DMA_SLEEP_DISABLE()  PDN_CLR(PDN_DMA)
#endif  /* __OLD_PDN_ARCH__ */


#endif//__MULTI_CORE_SHARED_DMA__

#endif //#if defined(DMA_NEW_HEAD_FILE_ARCHI)
#endif //_DMA_HW_H

