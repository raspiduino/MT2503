#ifndef _DMA_INTERNAL_HW_H_
#define _DMA_INTERNAL_HW_H_

/*=======================================================================*/
//below is from dma_hw.h.
//for new sw head file archi.
/*=======================================================================*/


/*=======================================================================*/
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

/*=======================================================================*/

#define DMA_COUNT_MASK              0xffff                                 
/*DMA_CON*/                         
#define DMA_CON_SIZE_MASK           0x00000003
#define DMA_CON_SIZE_BYTE           0x00000000
#define DMA_CON_SIZE_SHORT          0x00000001
#define DMA_CON_SIZE_LONG           0x00000002
                                   
#define DMA_CON_SINC                0x00000004
#define DMA_CON_DINC                0x00000008
#define DMA_CON_DRQ                 0x00000010  /*1:hw, 0:sw*/
#define DMA_CON_ITEN				0x00008000	/*Interrupt enable*/
#define DMA_CON_WPSD				  0x00010000  /*0:at source, 1: at destination*/
#define DMA_CON_WPEN				  0x00020000  /*0:disable, 1: enable*/
#define DMA_CON_DIR				  0x00040000  /*Only valid when dma = 4~11*/
#define DMA_CON_RXCONTRL            (DMA_CON_DIR|DMA_CON_DINC) /*hw management*/
#define DMA_CON_TXCONTRL            (DMA_CON_SINC) /*hw management*/
#define DMA_CON_SWCOPY              (DMA_CON_SINC|DMA_CON_DINC) /*hw management*/

#if defined(DMA_LESS_BURST_CTRL)                              
#define DMA_CON_B2W                 0x00000020  /*word to byte or byte to word*/
#define DMA_CON_BURST_SINGLE        0x00000000  /*without burst mode*/
#define DMA_CON_BURST_4BEAT         0x00000200  /*4-beat incrementing burst*/
#define DMA_CON_BURST_8BEAT         0x00000200  /*4-beat incrementing burst*/
#define DMA_CON_BURST_16BEAT        0x00000200  /*4-beat incrementing burst*/
#endif     

#if defined (DMA_EXT_MASTER_CTRL)
   #define DMA_CON_MASTER_MASK         0x01f00000  /*Only valid when dma = 4~11*/
#else
   #define DMA_CON_MASTER_MASK         0x00f00000  /*Only valid when dma = 4~11*/
#endif //#if defined (MT6250) || defined (MT6260)                                      

/*=======================================================================*/
#define DMA_START_BIT               0x00008000
#define DMA_STOP_BIT                0x00000000
#define DMA_ACKINT_BIT              0x00008000
#define DMA_INTSTA_BIT              0x00008000                             
#define DMA_RLCT_MASK               0x0000ffff                                  
#define DMA_LIMITER_MASK            0x000000ff
/*=======================================================================*/

#if defined(DMA_USE_AHB_BASE_ADDR)
#define DMA_VPORT_BASE               (DMA_AHB_base)
#endif

/*=======================================================================*/
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

/*=======================================================================*/

#if defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
#else   /* __WCDMA_RAT__ */
#define DMA_TX_TRIGGER_LEVEL(n)     ((n)/8)      // trigger level of tx vfifo
#endif  /* __UMTS_RAT__ */

#define DMA_RX_TRIGGER_LEVEL(n)     ((n)*3/4)   // trigger level of rx vfifo

#define DMA_VIFOF_ALERT_LENGTH      0x3f         // flow control trigger level

/*=======================================================================*/

#define DMA_IRQ_CODE                 IRQ_DMA_CODE

/*=======================================================================*/
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


/*=======================================================================*/

#endif
