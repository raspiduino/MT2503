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
 *    dma_sw.h
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

#ifndef _DMA_SW_H
#define _DMA_SW_H

#include "dma_hw.h"
#include "drv_comm.h"
#include "kal_general_types.h"

/*===========================================================*/
// below is add to reorganize the dma header file. 
// from MT6261, new path will apllyed
/*===========================================================*/

#if defined(DMA_NEW_HEAD_FILE_ARCHI)  //dma new sw header file arch. go this path
#include "dma_sw_v2.h"
#else  // this is the old path
/*===========================================================*/

#if defined(MT6205) || defined(MT6205B) || defined(MT6208) || defined(FPGA)

typedef enum 
{
    cbyte,
    chword,
    cword
} DMAsize;

typedef enum 
{
    sw_hsk,
    hw_hsk
} DMAhsk;

typedef enum 
{
    mode1,
    mode7
} DMAtmode;

typedef enum 
{
    USBmas,
    UARTmas
} DMAmas;

typedef struct 
{
    void (*dma1_func)(void);
    void (*dma2_func)(void); 
} dma_func;

#define DMA1_Start() *(volatile kal_uint16 *)DMA1_START = DMA_START_BIT
#define DMA2_Start() *(volatile kal_uint16 *)DMA2_START = DMA_START_BIT
#define DMA1_Stop()  *(volatile kal_uint16 *)DMA1_START = DMA_STOP_BIT
#define DMA2_Stop()  *(volatile kal_uint16 *)DMA2_START = DMA_STOP_BIT
#define DMA1_GetCount() *(volatile kal_uint16 *)DMA1_COUNT
#define DMA2_GetCount() *(volatile kal_uint16 *)DMA2_COUNT
#define DMA1_ACKI()  *(volatile kal_uint16 *)DMA1_ACKINT = DMA_ACKINT_BIT
#define DMA2_ACKI()  *(volatile kal_uint16 *)DMA2_ACKINT = DMA_ACKINT_BIT
   
extern kal_bool DMA1_CheckRunStat(void);
extern kal_bool DMA1_CheckITStat(void);
extern void DMA1_Init(kal_uint32 src, kal_uint32 dst, kal_uint16 count,void func(void));
extern kal_bool DMA2_CheckRunStat(void);
extern kal_bool DMA2_CheckITStat(void);
extern void DMA2_Init(kal_uint32 src, kal_uint32 dst, kal_uint16 count,void func(void));
extern void UART_DMA_ENABLE(void);
extern kal_bool USBDMA_Ini(kal_bool Tx);
extern kal_bool UART1DMA_Ini(kal_bool Tx);
extern kal_bool UART2DMA_Ini(kal_bool Tx);
extern void DMA_LISR(void);
   
#else   /* MT6205 || MT6208 || MT6205B || FPGA */

#if defined(TK6516)
   
#define DMA_MAX_CHANNEL       3
#define DMA_MAX_FULL_CHANNEL  1

typedef enum 
{
   DMA_SIM=0,
   DMA_UART1TX,
   DMA_UART1RX,
   DMA_UART2TX,
   DMA_UART2RX,
   DMA_IDMA,
   DMA_IDMA2,
   DMA_NFITX,
   DMA_NFIRX,
   DMA_SW,
   DMA_IDLE
} DMA_Master;   
   
#elif defined(MT6516)

#define DMA_MAX_CHANNEL       3
#define DMA_MAX_FULL_CHANNEL  1

typedef enum 
{
   DMA_SIM=0,
   DMA_UART1TX,
   DMA_UART1RX,
   DMA_UART2TX,
   DMA_UART2RX,
   DMA_NFITX,
   DMA_NFIRX,
   DMA_IDMA,
   DMA_IDMA2,
   DMA_UART3TX,
   DMA_UART3RX,
   DMA_UART4TX,
   DMA_UART4RX,
   DMA_SIM2,
   DMA_SW,
   DMA_IDLE
} DMA_Master;   

#elif defined(MT6276)

#define __DMA_API_V2__

#if defined(MT6276_S00)

#define DMA_MAX_CHANNEL          9  //BT and VFF belong to VFF
#define DMA_MAX_FULL_CHANNEL     1  //Channel 2 dedicated for wifi

typedef enum {
    DMA_SW = 1,
    DMA_WIFI = 2,
    DMA_MSDC = 3,
    DMA_MSDC3,      /* E1 bug: MSDC2 and 3 reverse */
    DMA_MSDC2,     /* E1 bug: MSDC2 and 3 reverse */
    DMA_SIM,
    DMA_SIM2,
    DMA_I2C,
    DMA_IRDA,
    DMA_BTIFTX,
    DMA_BTIFRX,
    DMA_UART1TX,
    DMA_UART1RX,
    DMA_UART2TX,
    DMA_UART2RX,
    DMA_UART3TX,
    DMA_UART3RX,
    DMA_IDLE
} DMA_Master;

#else /*MT6276_S00*/

#define DMA_MAX_CHANNEL          12  //BT and VFF belong to VFF
#define DMA_MAX_FULL_CHANNEL     2  

typedef enum {
    DMA_SW = 1,
    DMA_MSDC = 3,
    DMA_MSDC2,
    DMA_MSDC3,
    DMA_HIF0,
    DMA_HIF1,
    DMA_SIM,
    DMA_SIM2,
    DMA_I2C,
    DMA_I2C2,
    DMA_IRDA,
    DMA_BTIFTX,
    DMA_BTIFRX,
    DMA_UART1TX,
    DMA_UART1RX,
    DMA_UART2TX,
    DMA_UART2RX,
    DMA_UART3TX,
    DMA_UART3RX,
    DMA_IDLE
} DMA_Master;

#endif /*MT6276_S00*/


#elif defined(MT6256)

#define __DMA_API_V2__

#if defined(MT6256_S00)

#define DMA_MAX_CHANNEL          9  //BT and VFF belong to VFF
#define DMA_MAX_FULL_CHANNEL     1  //Channel 2 dedicated for wifi

typedef enum {
    DMA_SW = 1,
    DMA_WIFI = 2,
    DMA_MSDC = 3,
    DMA_MSDC2,
    DMA_RESERVED_1,
    DMA_SIM,
    DMA_SIM2,
    DMA_I2C,
    DMA_IRDA,
    DMA_BTIFTX,
    DMA_BTIFRX,
    DMA_UART1TX,
    DMA_UART1RX,
    DMA_UART2TX,
    DMA_UART2RX,
    DMA_UART3TX,
    DMA_UART3RX,
    DMA_IDLE
} DMA_Master;

#else

#define DMA_MAX_CHANNEL          11  //BT and VFF belong to VFF
#define DMA_MAX_FULL_CHANNEL     1  //Channel 2 dedicated for wifi

typedef enum {
    DMA_SW = 1,
    DMA_RESERVED_1 = 2,
    DMA_MSDC = 3,
    DMA_MSDC2,
    DMA_RESERVED_2,
    DMA_HIF0,
    DMA_HIF1,    
    DMA_SIM,
    DMA_SIM2,
    DMA_I2C,
    DMA_I2C2,
    DMA_RESERVED_3,
    DMA_BTIFTX,
    DMA_BTIFRX,
    DMA_UART1TX,
    DMA_UART1RX,
    DMA_UART2TX,
    DMA_UART2RX,
    DMA_UART3TX,
    DMA_UART3RX,
    DMA_IDLE
} DMA_Master;

#endif

#elif defined(MT6255)

#define __DMA_API_V2__

#define DMA_MAX_CHANNEL          11  //BT and VFF belong to VFF
#define DMA_MAX_FULL_CHANNEL     1  //Channel 2 dedicated for wifi

typedef enum {
    DMA_SW = 1,
    DMA_RESERVED_1 = 2,
    DMA_MSDC = 3,
    DMA_MSDC2,
    DMA_RESERVED_2,
    DMA_HIF0,
    DMA_HIF1,    
    DMA_SIM,
    DMA_SIM2,
    DMA_I2C,
    DMA_I2C2,
    DMA_RESERVED_3,
    DMA_BTIFTX,
    DMA_BTIFRX,
    DMA_UART1TX,
    DMA_UART1RX,
    DMA_UART2TX,
    DMA_UART2RX,
    DMA_UART3TX,
    DMA_UART3RX,
    DMA_IDLE
} DMA_Master;


#elif defined(MT6573)

#define __DMA_API_V2__

#define DMA_ALL_CHANNEL          11  //All peripheral channel
#define DMA_MAX_CHANNEL          2   //Peripheral Channel number for MD
#define DMA_MAX_FULL_CHANNEL     0

#define DMA2_ALL_CHANNEL         2
#define DMA2_MAX_CHANNEL         2
#define DMA2_MAX_FULL_CHANNEL    2


typedef enum {
    DMA_SIM = 7,
    DMA_SIM2 = 8,
    DMA_UART1TX = 12,
    DMA_UART1RX = 13,    
    DMA_UART4TX = 18,
    DMA_UART4RX = 19,
    DMA_IDLE,
    DMA_SW = 0x81,
    DMA_GDMA1 = 0x81,
    DMA_GDMA2 = 0x82,
#if defined(__UMTS_TDD128_MODE__)
    DMA_TD_L1 = 0x82,
#endif   /*(__UMTS_TDD128_MODE__)*/        
} DMA_Master;

#elif defined(MT6575)

#define __DMA_API_V2__

/*MD-side*/
#define DMA_ALL_CHANNEL          2  //All peripheral channels  (GDMA1, GDMA2)
#define DMA_MAX_CHANNEL          2	//Peripheral Channel number (GDMA1, GDMA2)
#define DMA_MAX_FULL_CHANNEL     2  //full-size channels

/*AP-side*/
#define DMA2_ALL_CHANNEL         7	//All peripheral channels (GDMA1, GDMA2, HIF1, HIF2, SIM1, SIM2, IrDa)
#define DMA2_MAX_CHANNEL         6	//Peripheral Channel number (GDMA1, GDMA2, HIF1, HIF2, SIM1, SIM2)
#define DMA2_MAX_FULL_CHANNEL    2	//full-size channels

typedef enum {
	/*AP-side*/
    DMA_AP_GDMA1 = 0x81,	/*since DSP performance test requires AP GDMA, so list it as Master*/
    DMA_AP_GDMA2 = 0x82,	/*since DSP performance test requires AP GDMA, so list it as Master*/
    DMA_HIF0 = 0x83,		/*since MD-side requires HIF, so list it as Master*/
    DMA_HIF1 = 0x84,		/*since MD-side requires HIF, so list it as Master*/
    DMA_SIM = 0x85,			/*since MD-side requires SIM, so list it as Master*/
    DMA_SIM2 = 0x86,		/*since MD-side requires SIM, so list it as Master*/
    DMA_IDLE,

	/*MD-side*/
    DMA_SW = 0x1,
    DMA_GDMA1 = 0x1,		/*MD-side GDMA1*/
    DMA_GDMA2 = 0x2,		/*MD-side GDMA2*/
	DMA_UART1TX = 0x3,		/*MD-side UART1TX*/
	DMA_UART1RX = 0x4,	 	/*MD-side UART1RX*/
	DMA_UART2TX = 0x5,		/*MD-side UART2TX*/
	DMA_UART2RX = 0x6,	 	/*MD-side UART2RX*/
} DMA_Master;

#else   /* TK6516 */

#ifdef MT6218
#define DMA_MAX_CHANNEL          11
#elif defined(MT6218B) || defined(MT6217)
#define DMA_MAX_CHANNEL          9
#elif defined(MT6223) || defined(MT6223P)
#define DMA_MAX_CHANNEL          6
#elif defined(MT6253T) || defined(MT6253)
#define DMA_MAX_CHANNEL          11
#elif defined(MT6251)
#define DMA_MAX_CHANNEL          12
#elif defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
#define DMA_MAX_CHANNEL          9
#elif defined (MT6250)
#define DMA_MAX_CHANNEL         17
#define DMA_HALF_CHANNEL_MASK (0x300fe)
#elif defined (MT6260)
#define DMA_MAX_CHANNEL         9
#else
#define DMA_MAX_CHANNEL          10
#endif

#if defined(MT6223) || defined(MT6223P)
#define DMA_MAX_FULL_CHANNEL     1
#elif defined(MT6253T) || defined(MT6253)
#define DMA_MAX_FULL_CHANNEL     4
#elif defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H) || defined(MT6250) || defined(MT6260)
#define DMA_MAX_FULL_CHANNEL     1
#define DMA_FULL_CHANNEL_MASK (0x00001)
#else
#define DMA_MAX_FULL_CHANNEL     3
#endif

// 
#if defined (MT6250)
#define DMA_CHANNEL_MASK (DMA_HALF_CHANNEL_MASK | DMA_FULL_CHANNEL_MASK)
#define SPARSE_CHANNEL_GROUP  // defined this if channels are not grouped compactly.
typedef enum {
    DMA_RESERVED_0,  // 0
    DMA_MSDC,        // 1
    DMA_SIM,         // 2
    DMA_SIM2,        // 3
    DMA_USB1TX,      // 4
    DMA_USB1RX,      // 5
    DMA_USB2TX,      // 6
    DMA_USB2RX,      // 7
    DMA_UART1TX,     // 8
    DMA_UART1RX,     // 9
    DMA_UART2TX,     // 10
    DMA_UART2RX,     // 11
    DMA_UART3TX,     // 12
    DMA_UART3RX,     // 13
    DMA_BTIFRX,      // 14
    DMA_BTIFTX,      // 15
    DMA_HIF0,        // 16
    DMA_HIF1,        // 17

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

#elif defined (MT6260)
//dedicated channel design
typedef enum {
	DMA_RESERVED_0,  // 0
    DMA_RESERVED_1,  // 1
    DMA_MSDC,        // 2
    DMA_SIM,         // 3
    DMA_SIM2,        // 4
    DMA_USB1TX,      // 5
    DMA_USB1RX,      // 6
    DMA_USB2TX,      // 7
	DMA_HIF0,        // 8
	DMA_MSDC2,       // 9
    DMA_UART1TX,     // 10
    DMA_UART1RX,     // 11
    DMA_UART2TX,     // 12
    DMA_UART2RX,     // 13
    DMA_BTIFRX,      // 14
    DMA_BTIFTX,      // 15

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

#else //#if defined (MT6250)
typedef enum {
   DMA_SIM=0,
#if defined(MT6270A)
   DMA_RESERVED_1,
   DMA_RESERVED_2,
   DMA_RESERVED_3,
#elif defined(MT6251) || defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
   DMA_MSDC,
   DMA_RESERVED_1,
   DMA_RESERVED_2,   
#else
   DMA_MSDC,
   DMA_IRDATX,
   DMA_IRDARX,
#endif
#if defined(MT6238)||defined(MT6239) || defined(MT6235)||defined(MT6235B) || defined(MT6253T) || defined(MT6253) || defined(MT6236) || defined(MT6236B)
   DMA_RESERVED_1,
   DMA_RESERVED_2,
   DMA_RESERVED_3,
   DMA_RESERVED_4,
#elif defined(MT6268A)
   DMA_I2C2TX,
   DMA_I2C2RX,
   DMA_RESERVED_1,
   DMA_RESERVED_2,
#elif defined(MT6268)
   DMA_I2C2TX,
   DMA_I2C2RX,
   DMA_USBTX,
   DMA_USBRX,
#elif defined(MT6270A)
   DMA_RESERVED_4,
   DMA_RESERVED_5,
   DMA_RESERVED_6,
   DMA_RESERVED_7,   
#else
   DMA_USB1TX, 
   DMA_USB1RX,
   DMA_USB2TX,
   DMA_USB2RX,
#endif
#if defined(MT6251)
   DMA_UART1TX,
   DMA_UART1RX,
   DMA_UART2TX,
   DMA_UART2RX,
   DMA_RESERVED_8,
   DMA_RESERVED_9,   
#else
   DMA_UART1TX,
   DMA_UART1RX,
   DMA_UART2TX,
   DMA_UART2RX,
   DMA_UART3TX,
   DMA_UART3RX,
#endif
#if defined(MT6270A)
   DMA_RESERVED_E, 
#else
   DMA_IDMA,
#endif   
#if defined(MT6251)
   DMA_RESERVED_F,
   DMA_RESERVED_10,
#elif defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
   DMA_RESERVED_8,
   DMA_RESERVED_9, 
#else
#if ( !defined(MT6218B) && !defined(MT6217) )
   DMA_NFITX,
   DMA_NFIRX,
#endif
#endif
#if defined(MT6238)||defined(MT6239) || defined(MT6235)||defined(MT6235B) || defined(MT6268A)||defined(MT6268) || defined(MT6236) || defined(MT6236B)
   DMA_DSPDMA2,
   DMA_I2CTX,
   DMA_I2CRX,
   DMA_MSDC2,	
   DMA_SIM2,
#elif defined(MT6253T) || defined(MT6253) || defined(MT6251) || defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
   DMA_I2CTX,
   DMA_I2CRX,
   DMA_SIM2,
#elif defined(MT6270A)
   DMA_RESERVED_17,
   DMA_RESERVED_18,
   DMA_RESERVED_19,
   DMA_RESERVED_20,
   DMA_SIM2,
#endif

#if defined(MT6236) || defined(MT6236B)
   DMA_RESERVED_5,
   DMA_BTIFTX,
   DMA_BTIFRX,
#elif defined(MT6251) || defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
   DMA_DSPDMA2,
#endif

#if defined(__DIRECT_SENSOR_SUPPORT__)
   DMA_UNUSED_1,
   DMA_UNUSED_2,
   DMA_CAM,
#endif

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
#endif //#if defined (MT6250)

#endif  /* TK6516 */

typedef enum {
    DMA_BYTE=0,
    DMA_SHORT,
    DMA_LONG
} DMA_TranSize;

typedef enum {
    DMA_HWTX,          /*use DMA_HWMENU*/  /*from RAM to register, 4~11*/
    DMA_HWRX,          /*use DMA_HWMENU*/ /*from register to RAM, 4~11*/
    DMA_SWCOPY,        /*use DMA_SWCOPYMENU*/  /*from RAM to RAM, 1~3*/
    DMA_HWTX_RINGBUFF, /*use DMA_HWRINGBUFF_MENU*/   /*from RAM to register, 4~11*/
    DMA_HWRX_RINGBUFF  /*use DMA_HWRINGBUFF_MENU*/  /*from register to RAM, 4~11*/
} DMA_Type;

typedef struct
{
    kal_bool  burst_mode; /*burst mode = 0 ==> single mode*/
    kal_uint8 cycle;      /*active only when (burst_mode == TRUE)*/
}DMA_TMODE;              /*only active when hw management*/

typedef struct
{
    DMA_TMODE      TMOD;
    DMA_Master     master;
    kal_uint32     addr;
    void           *WPPT; /*if ring buffer support, ==NULL==> not supprot*/
    void           *WPTO; /*if ring buffer support, ==NULL==> not supprot*/
}DMA_HWRINGBUFF_MENU;

typedef struct
{
    DMA_TMODE      TMOD;
    DMA_Master     master;
    kal_uint32     addr;
}DMA_HWMENU;

typedef struct
{
    DMA_TMODE      TMOD;
    DMA_Master     master;
    kal_uint32     source;
    kal_uint32     destination;
    void           *WPPT; /*if ring buffer support, ==NULL==> not supprot*/
    void           *WPTO; /*if ring buffer support, ==NULL==> not supprot*/
#if defined(__DMA_API_V2__)	
    kal_bool     fixed_raddr;
    kal_uint32     rsize;
    kal_bool     fixed_waddr;
    kal_uint32     wsize;
	kal_uint32   req_ack_connect;
	kal_uint32   req_ack_dir;
	kal_uint32   req_ack_ratio;
#endif	

}DMA_FULLSIZE_HWRINGBUFF_MENU;

typedef struct
{
    DMA_TMODE      TMOD;
    DMA_Master     master;
    kal_uint32     source;
    kal_uint32     destination;
#if defined(__DMA_API_V2__)
    kal_bool     fixed_raddr;
    kal_uint32     rsize;
    kal_bool     fixed_waddr;
    kal_uint32     wsize;
	kal_uint32   req_ack_connect;
	kal_uint32   req_ack_dir;
	kal_uint32   req_ack_ratio;
#endif
}DMA_FULLSIZE_HWMENU;

typedef struct
{
#if defined(__DMA_API_V2__)
    DMA_TMODE      TMOD;
#endif
    kal_uint32     srcaddr;
    kal_uint32     dstaddr;
#if defined(__DMA_API_V2__)
    kal_bool     fixed_raddr;
    kal_uint32     rsize;
    kal_bool     fixed_waddr;
    kal_uint32     wsize;
	kal_uint32   req_ack_connect;
	kal_uint32   req_ack_dir;
	kal_uint32   req_ack_ratio;	
#endif
}DMA_SWCOPYMENU;

typedef union
{
    DMA_HWMENU                    menu_hw;
    DMA_HWRINGBUFF_MENU           menu_hw_ringbuff;
    DMA_SWCOPYMENU                menu_swcopy;
    DMA_FULLSIZE_HWMENU           menu_fullsize_hw;
    DMA_FULLSIZE_HWRINGBUFF_MENU  menu_fullsize_hw_ringbuff;
} DMA_MENU;

typedef struct
{
    DMA_Type       type;
    DMA_TranSize   size;
    kal_uint32     count;
#if defined(__DMA_API_V2__)
    kal_bool     fixed_pattern;
#endif
    void           *menu;      /*DMA_HWMENU,DMA_HWRINGBUFF_MENU,DMA_SWCOPYMENU,or DMA_SWCOPY_RINGBUFF_MENU*/
    void           (*callback)(void);      /*if callback == NULL, interrupt disable*/
}DMA_INPUT;

typedef struct
{
    kal_uint32   sleepDisable;      
    //kal_uint8    DMA_ChanCount;
} DMA_PWRCTRL;

typedef kal_uint8 DMA_GBL_CLASS;
typedef kal_int8 DMA_GBL_HANDLE;

typedef struct
{
    kal_uint8 lower;
    kal_uint8 upper;
    kal_uint8 bank; 
} DMA_GBL_PRIORITY_BANK;

typedef struct
{
    kal_uint32 len1;
	kal_uint32 len2;
	DMA_TranSize size;
}DMA_SAVE_PARAM;

#define DMA_MAX_GBL_CLASS 4
#define DMA_GBL_CLASS0 0
#define DMA_GBL_CLASS1 1
#define DMA_GBL_CLASS2 2
#define DMA_GBL_CLASS3 3
#define DMA_GBL_CLASS4 4
#define DMA_INVALID_GBL_HANDLE -1
#define DMA_GBL_TOTAL_PRIORITY_BANK 8
                                                                                              
#define DMA_GBL_PRIORITY_2_BL(priority_bank, dma_gbl) (((priority_bank) * (dma_gbl)) >> 3)

#if defined(__DMA_API_V2__)
#define DMA_Start(_n)                  DRV_WriteReg32(DMA_START(_n),DMA_START_BIT)
//#define DMA_Stop_Now(_n)               DRV_WriteReg32(DMA_START(_n),DMA_STOP_BIT)   //change by AB
#define DMA_Stop_Now(_n)               DRV_WriteReg32(DMA_STOP(_n),DMA_STOP_BIT)
#define DMA_GetCount(_n)               DRV_Reg32(DMA_COUNT(_n))
#define DMA_ACKI(_n)                   DRV_WriteReg32(DMA_ACKINT(_n),DMA_ACKINT_BIT)
#define DMA_CheckRunStat(_n)           ((DRV_Reg32(DMA_GLBST_RUNNING) & DMA_GLBSTA_RUN(_n))!=0)
#define DMA_CheckITStat(_n)            ((DRV_Reg32(DMA_GLBST_INT) & DMA_GLBSTA_IT(_n))!=0)
#define DMA_WaitUntilRdy(_n)           while(DMA_CheckRunStat(_n))

#if defined(__MULTI_CORE_SHARED_DMA__)
#if defined(MT6575)
/*AP side*/
#define DMA2_Start(_n)                  DRV_WriteReg32(DMA2_START(_n),DMA_START_BIT)
//#define DMA2_Stop_Now(_n)               DRV_WriteReg32(DMA2_START(_n),DMA_STOP_BIT)   //change by AB
#define DMA2_Stop_Now(_n)               DRV_WriteReg32(DMA2_STOP(_n),DMA_STOP_BIT)
#define DMA2_GetCount(_n)               DRV_Reg32(DMA2_COUNT(_n))
#define DMA2_ACKI(_n)                   DRV_WriteReg32(DMA2_ACKINT(_n),DMA_ACKINT_BIT)
#define DMA2_CheckRunStat(_n)           (DRV_Reg32(DMA2_START(_n)) == DMA_START_BIT)                //AST fix, ((DRV_Reg32(DMA2_GLBST_RUNNING) & DMA_GLBSTA_RUN(_n))!=0)
#define DMA2_CheckITStat(_n)            ((DRV_Reg32(DMA2_GLBST_INT) & DMA_GLBSTA_IT(_n))!=0)	
#define DMA2_WaitUntilRdy(_n)           while(DMA2_CheckRunStat(_n))
#else
/*MD side*/
#define DMA2_Start(_n)                  DRV_WriteReg32(DMA2_START(_n),DMA_START_BIT)
//#define DMA2_Stop_Now(_n)               DRV_WriteReg32(DMA2_START(_n),DMA_STOP_BIT)   //change by AB
#define DMA2_Stop_Now(_n)               DRV_WriteReg32(DMA2_STOP(_n),DMA_STOP_BIT)
#define DMA2_GetCount(_n)               DRV_Reg32(DMA2_COUNT(_n))
#define DMA2_ACKI(_n)                   DRV_WriteReg32(DMA2_ACKINT(_n),DMA_ACKINT_BIT)
#define DMA2_CheckRunStat(_n)           ((DRV_Reg32(DMA_GLBST_RUNNING) & DMA_GLBSTA_RUN(_n))!=0)
#define DMA2_CheckITStat(_n)            ((DRV_Reg32(DMA_GLBST_INT) & DMA_GLBSTA_IT(_n))!=0)
#define DMA2_WaitUntilRdy(_n)           while(DMA2_CheckRunStat(_n))
#endif
#endif

#else
#define DMA_Start(_n)                  DRV_WriteReg32(DMA_START(_n),DMA_START_BIT)
#define DMA_Stop_Now(_n)               DRV_WriteReg32(DMA_START(_n),DMA_STOP_BIT)
#define DMA_GetCount(_n)               DRV_Reg32(DMA_COUNT(_n))
#define DMA_ACKI(_n)                   DRV_WriteReg32(DMA_ACKINT(_n),DMA_ACKINT_BIT)
#if defined (MT6250) || defined(MT6236) //channel number > 16
#define DMA_CheckRunStat(_n)           (((_n) < 17) ? ((DRV_Reg32(DMA_GLBSTA) & DMA_GLBSTA_RUN(_n))!=0) : ((DRV_Reg32(DMA_GLBSTA2) & DMA_GLBSTA_RUN((_n)-16))!=0))
#define DMA_CheckITStat(_n)            (((_n) < 17) ? ((DRV_Reg32(DMA_GLBSTA) & DMA_GLBSTA_IT(_n))!=0) : ((DRV_Reg32(DMA_GLBSTA2) & DMA_GLBSTA_IT((_n)-16))!=0))
#else
#define DMA_CheckRunStat(_n)           ((DRV_Reg32(DMA_GLBSTA) & DMA_GLBSTA_RUN(_n))!=0) //fixme. DMA_GLBSTA_RUN(_n) fail,  if _n > 16 
#define DMA_CheckITStat(_n)            ((DRV_Reg32(DMA_GLBSTA) & DMA_GLBSTA_IT(_n))!=0)
#endif //#if defined (MT6250) || defined(MT6236)
#define DMA_WaitUntilRdy(_n)           while(DMA_CheckRunStat(_n))
#endif    /* __DMA_API_V2__ */

#if defined(MT6268T) || defined(MT6268H)
#define FPGA_DMA_Start(_n) DRV_WriteReg32(FPGA_DMA_START(_n), DMA_START_BIT)
#define FPGA_DMA_Stop_Now(_n) DRV_WriteReg32(FPGA_DMA_START(_n), DMA_STOP_BIT)
#define FPGA_DMA_GetCount(_n) DRV_Reg32(FPGA_DMA_COUNT(_n))
#define FPGA_DMA_ACKI(_n) DRV_WriteReg32(FPGA_DMA_ACKINT(_n), DMA_ACKINT_BIT)
#define FPGA_DMA_CheckRunStat(_n) ((DRV_Reg32(FPGA_DMA_GLBSTA) & DMA_GLBSTA_RUN(_n))!=0)
#define FPGA_DMA_CheckITStat(_n) ((DRV_Reg32(FPGA_DMA_GLBSTA) & DMA_GLBSTA_IT(_n))!=0)
#define FPGA_DMA_WaitUntilRdy(_n) while(DMA_CheckRunStat(_n))
#endif   /* MT6268T || MT6268H */

extern void DMA_Stop(kal_uint8 channel);
extern void DMA_Run(kal_uint8 channel);
extern void DMA_WaitforDone(kal_uint8 channel);
extern kal_uint8 DMA_GetChannel(DMA_Master DMA_CODE);
extern void DMA_FreeChannel(kal_uint8 handle);
extern kal_uint8 DMA_FullSize_GetChannel(DMA_Master DMA_CODE);
extern void DMA_FullSize_FreeChannel(kal_uint8 handle);
extern void DMA_Config_Internal(kal_uint8 dma_no, DMA_INPUT *dma_menu, kal_bool fullsize, kal_bool b2w, kal_uint8 limit, kal_bool start);
extern DMA_GBL_HANDLE DMA_SetGBL(DMA_GBL_CLASS dma_gbl_class);
extern void DMA_RestoreGBL(DMA_GBL_HANDLE dma_gbl_handle);
extern void DMA_Quick_Config(kal_uint32 dma_no, kal_uint32 dst);
extern void DMA_Quick_Config_Bidir(  kal_uint32 dma_no, kal_uint32 dst, kal_uint32 src, kal_uint32 count, DMA_Type type );
extern void DMA_CleanUp(kal_uint8 channel);

#if defined(__DMA_SUPPORT_CALLBACK_LISR__)
extern void DMA_Register_RT_CallBack ( kal_uint8 dma_no );
extern void DMA_Unregister_RT_CallBack ( kal_uint8 dma_no );
#endif

#if defined(__RTL_SIMULATION_FOR_60QBIT__)

extern void  test_dma_slowdown( void );
extern void test_dma_recover( void );

#endif //__RTL_SIMULATION_FOR_60QBIT__


#define DMA_Config(dma_no, dma_menu, start) DMA_Config_Internal(dma_no, dma_menu, KAL_FALSE, KAL_FALSE, 0, start)
#define DMA_FullSize_Config(dma_no, dma_menu, start) DMA_Config_Internal(dma_no, dma_menu, KAL_TRUE, KAL_FALSE, 0, start)
#define DMA_Config_B2W(dma_no, dma_menu, start, b2w) DMA_Config_Internal(dma_no, dma_menu, KAL_FALSE, b2w, 0, start)

#endif  /* MT6205 || MT6208 || MT6205B || FPGA */

#if !defined(MT6205B) && !defined(MT6208)
#if defined(MT6218B) || defined(MT6217)
   typedef enum {
      VDMA_UART1RX_CH = 10,
      VDMA_UART1TX_CH = 12,
      VDMA_UART2RX_CH = 11,
      VDMA_UART2TX_CH = 13,
      VDMA_UART3RX_CH = 0,
      VDMA_UART3TX_CH = 0
   } DMA_VFIFO_UART;  
#elif defined(TK6516) || defined(MT6516)   /* MT6218B || MT6217 */
   typedef enum {
      VDMA_UART1RX_CH = 11,
      VDMA_UART1TX_CH = 12,
      VDMA_UART2RX_CH = 0,
      VDMA_UART2TX_CH = 0,
      VDMA_UART3RX_CH = 0,
      VDMA_UART3TX_CH = 0
   } DMA_VFIFO_UART;
#elif defined(MT6276)

#if defined(MT6276_S00)
   typedef enum {
      VDMA_BTIFTX_CH = 10,
	  VDMA_BTIFRX_CH = 11,	
      VDMA_UART1TX_CH = 12,
      VDMA_UART1RX_CH = 13,
      VDMA_UART2TX_CH = 14,
      VDMA_UART2RX_CH = 15,
      VDMA_UART3TX_CH = 16,
      VDMA_UART3RX_CH = 17
   } DMA_VFIFO_UART;
#else /* MT6276_S00 */
   typedef enum {
      VDMA_BTIFTX_CH = 12,
	  VDMA_BTIFRX_CH = 13,	
      VDMA_UART1TX_CH = 14,
      VDMA_UART1RX_CH = 15,
      VDMA_UART2TX_CH = 16,
      VDMA_UART2RX_CH = 17,
      VDMA_UART3TX_CH = 18,
      VDMA_UART3RX_CH = 19
   } DMA_VFIFO_UART;
#endif /* MT6276_S00 */

#elif defined(MT6256)

#if defined(MT6256_S00)

   typedef enum {
      VDMA_BTIFTX_CH = 10,
	  VDMA_BTIFRX_CH = 11,	
      VDMA_UART1TX_CH = 12,
      VDMA_UART1RX_CH = 13,
      VDMA_UART2TX_CH = 14,
      VDMA_UART2RX_CH = 15,
      VDMA_UART3TX_CH = 16,
      VDMA_UART3RX_CH = 17
   } DMA_VFIFO_UART;

#else

typedef enum {
   VDMA_BTIFTX_CH = 13,
   VDMA_BTIFRX_CH = 14,  
   VDMA_UART1TX_CH = 15,
   VDMA_UART1RX_CH = 16,
   VDMA_UART2TX_CH = 17,
   VDMA_UART2RX_CH = 18,
   VDMA_UART3TX_CH = 19,
   VDMA_UART3RX_CH = 20
} DMA_VFIFO_UART;

#endif

#elif defined(MT6255)
typedef enum {
   VDMA_BTIFTX_CH = 13,
   VDMA_BTIFRX_CH = 14,  
   VDMA_UART1TX_CH = 15,
   VDMA_UART1RX_CH = 16,
   VDMA_UART2TX_CH = 17,
   VDMA_UART2RX_CH = 18,
   VDMA_UART3TX_CH = 19,
   VDMA_UART3RX_CH = 20
} DMA_VFIFO_UART;


#elif defined(MT6573)
   typedef enum {	
      VDMA_UART1TX_CH = 12,
      VDMA_UART1RX_CH = 13,
      VDMA_UART2TX_CH = 0,
      VDMA_UART2RX_CH = 0,
      VDMA_UART3TX_CH = 0,
      VDMA_UART3RX_CH = 0,
      VDMA_UART4TX_CH = 18,
      VDMA_UART4RX_CH = 19      
   } DMA_VFIFO_UART;
#elif defined(MT6575)
   typedef enum {	
   	  /*MD-side*/
      VDMA_UART1TX_CH = 3,
      VDMA_UART1RX_CH = 4,
      VDMA_UART2TX_CH = 5,
      VDMA_UART2RX_CH = 6,
   } DMA_VFIFO_UART;

#elif defined(MT6250)
typedef enum {
   VDMA_UART1TX_CH = 8,
   VDMA_UART1RX_CH = 9,
   VDMA_UART2TX_CH = 10,
   VDMA_UART2RX_CH = 11,
   VDMA_UART3TX_CH = 12,
   VDMA_UART3RX_CH = 13,
   VDMA_BTIFRX_CH = 14,
   VDMA_BTIFTX_CH = 15,  
} DMA_VFIFO_UART;

#elif defined(MT6260)
typedef enum {
   VDMA_UART1TX_CH = 10,
   VDMA_UART1RX_CH = 11,
   VDMA_UART2TX_CH = 12,
   VDMA_UART2RX_CH = 13,
   VDMA_BTIFRX_CH = 14,
   VDMA_BTIFTX_CH = 15 
} DMA_VFIFO_UART;

#else   /* MT6218B || MT6217 */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else   /* if 0 */
  typedef enum {
      VDMA_UART1RX_CH = 11,
      VDMA_UART1TX_CH = 12,
      VDMA_UART2RX_CH = 0,
      VDMA_UART2TX_CH = 0,
      VDMA_UART3RX_CH = 13,
      VDMA_UART3TX_CH = 14
      } DMA_VFIFO_UART;  
#endif  /* if 0 */
#endif  /* MT6218B || MT6217 */
#endif  /* !MT6205B && !MT6208 */

#ifdef __DMA_UART_VIRTUAL_FIFO__
#if !defined(MT6205B) && !defined(MT6208)
extern void DMA_Vfifo_init(void);
extern void DMA_Vfifo_SetAdrs(kal_uint32 adrs, kal_uint32 len, DMA_VFIFO_UART ch, kal_bool IsTx );
extern void DMA_Vfifo_Flush(DMA_VFIFO_UART ch);

#if 1 //defined(__MEUT__) || defined(__MEIT__)
#include "uart_sw.h"
extern int DMA_Vfifo_SetChan(UART_PORT port);
#endif /*#if defined(__MEUT__) || defined(__MEIT__)*/

#endif  /* !MT6205B && !MT6208 */
#endif   /* __DMA_UART_VIRTUAL_FIFO__ */


#if defined (MT6255) || defined (MT6256)
/**
 * to workaround for HW bug that 
 * 1. bridge will postpond write transaction, and
 * 2. slave device responces in a long latency.
 * APB_DUMMY_READY() will push write transaction and make a delay.
 **/
#undef APB_DUMMY_READ
#define APB_DUMMY_READ() do { *(volatile long *)(DMA_base); } while(0)

#undef DMA_Start
#undef DMA_Stop_Now
#undef DMA_Reset
#undef DMA_Pause
#undef DMA_Resume
#undef DMA_Flush
#undef DMA_ACKI

#define DMA_Start(_n)                do { DRV_WriteReg32(DMA_START(_n),DMA_START_BIT); APB_DUMMY_READ(); } while(0)
#define DMA_Stop_Now(_n)             do { DRV_WriteReg32(DMA_STOP(_n),DMA_STOP_BIT); APB_DUMMY_READ(); } while(0)
#define DMA_Reset(_n,_m)             do { DRV_WriteReg32(DMA_RESET(_n),_m?DMA_H_RST_BIT:DMA_W_RST_BIT); APB_DUMMY_READ(); } while(0)
#define DMA_Pause(_n)                do { DRV_WriteReg32(DMA_STOP(_n),DMA_PAUSE_BIT); APB_DUMMY_READ(); } while(0)
#define DMA_Resume(_n)               do { DRV_WriteReg32(DMA_STOP(_n),0); APB_DUMMY_READ(); } while(0)
#define DMA_Flush(_n)                do { DRV_WriteReg32(DMA_FLUSH(_n),1); APB_DUMMY_READ(); } while(0)
#define DMA_ACKI(_n)                 do { DRV_WriteReg32(DMA_ACKINT(_n),DMA_ACKINT_BIT); APB_DUMMY_READ(); } while(0)

#else //#if defined (MT6255) || defined (MT6256)
#define APB_DUMMY_READ() do {  } while(0)
#endif //#if defined (MT6255) || defined (MT6256)

#endif
#endif   /* !_DMA_SW_H */

