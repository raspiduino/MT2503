#ifndef _DMA_INTERNAL_SW_H_
#define _DMA_INTERNAL_SW_H_

/*=======================================================================*/
//below is from dma_sw.h

/*=======================================*/
//struct define
/*=======================================*/

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


/*=======================================*/

#define DMA_MAX_GBL_CLASS 4
#define DMA_GBL_CLASS0 0
#define DMA_GBL_CLASS1 1
#define DMA_GBL_CLASS2 2
#define DMA_GBL_CLASS3 3
#define DMA_GBL_CLASS4 4
#define DMA_INVALID_GBL_HANDLE -1
#define DMA_GBL_TOTAL_PRIORITY_BANK 8
                                                                                              
#define DMA_GBL_PRIORITY_2_BL(priority_bank, dma_gbl) (((priority_bank) * (dma_gbl)) >> 3)
/*=======================================*/

#define DMA_Start(_n)                  DRV_WriteReg32(DMA_START(_n),DMA_START_BIT)
#define DMA_Stop_Now(_n)               DRV_WriteReg32(DMA_START(_n),DMA_STOP_BIT)
#define DMA_GetCount(_n)               DRV_Reg32(DMA_COUNT(_n))
#define DMA_ACKI(_n)                   DRV_WriteReg32(DMA_ACKINT(_n),DMA_ACKINT_BIT)
#define DMA_CheckRunStat(_n)           ((DRV_Reg32(DMA_GLBSTA) & DMA_GLBSTA_RUN(_n))!=0) //fixme. DMA_GLBSTA_RUN(_n) fail,  if _n > 16 
#define DMA_CheckITStat(_n)            ((DRV_Reg32(DMA_GLBSTA) & DMA_GLBSTA_IT(_n))!=0)
#define DMA_WaitUntilRdy(_n)           while(DMA_CheckRunStat(_n))
#define APB_DUMMY_READ() do {  } while(0)

/*=======================================*/

#define DMA_Config(dma_no, dma_menu, start) DMA_Config_Internal(dma_no, dma_menu, KAL_FALSE, KAL_FALSE, 0, start)
#define DMA_FullSize_Config(dma_no, dma_menu, start) DMA_Config_Internal(dma_no, dma_menu, KAL_TRUE, KAL_FALSE, 0, start)
#define DMA_Config_B2W(dma_no, dma_menu, start, b2w) DMA_Config_Internal(dma_no, dma_menu, KAL_FALSE, b2w, 0, start)

/*=======================================*/
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

/*=======================================*/

#ifdef __DMA_UART_VIRTUAL_FIFO__
#include "uart_sw.h"
extern void DMA_Vfifo_init(void);
extern void DMA_Vfifo_SetAdrs(kal_uint32 adrs, kal_uint32 len, DMA_VFIFO_UART ch, kal_bool IsTx );
extern void DMA_Vfifo_Flush(DMA_VFIFO_UART ch);
extern int DMA_Vfifo_SetChan(UART_PORT port);
#endif   /* __DMA_UART_VIRTUAL_FIFO__ */
/*=======================================================================*/

#endif
