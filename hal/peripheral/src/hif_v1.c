//#pragma O0

#include "kal_release.h"
#include "drv_features.h"
#include "lcd_if.h"
#include "hif_hal.h"
#include "hif_v1_internal.h"
#include "eint.h"
#include "intrCtrl.h"
#include "dma_sw.h"
#include "dma_hw.h"
#include "drv_comm.h"
#include "l1sm_public.h"
#include "dcm.h"

#if defined(DRV_HIF_V1) && defined(DRV_HIF_SUPPORT)

// Global variables
static kal_bool hif_power_on = KAL_FALSE;
static HIF_INTERNAL_HANDLE_T hif_internal_handle[HIF_MAX_PORT_NUM];
static volatile kal_uint8 hif_sysdma_id;
static DMA_INPUT hif_dma_input;
static DMA_FULLSIZE_HWMENU  hif_dma_menu;
//static kal_hisrid hif_hisr_id;
static HIF_CALLBACK hif_cb = NULL;
static kal_uint8 hif_tl1_sleep_handle = 0;
static kal_uint8 hif_dcm_handle=0;

// Debug data
typedef enum
{
    HIF_____________,
    HIF_________INIT,
    HIF_________OPEN,
    HIF________CLOSE,
    HIF_______CONFIG,
    HIF____POWERCTRL,
    HIF__WRITE_CPU_H,
    HIF__WRITE_CPU_L,
    HIF_WRITE_DMA_HS,
    HIF_WRITE_DMA_LS,
    HIF_WRITE_DMA_HE,
    HIF_WRITE_DMA_LE,
    HIF____WRITE_RET,
    HIF___READ_CPU_H,
    HIF___READ_CPU_L,
    HIF__READ_DMA_HS,
    HIF__READ_DMA_LS,
    HIF__READ_DMA_HE,
    HIF__READ_DMA_LE,
    HIF_____READ_RET,
    HIF______HIF_INT,
    HIF____DMA_INT_S,
    HIF____DMA_INT_E,
    HIF________IOCTL
} HIF_ACTION_ENUM;

typedef struct
{
    HIF_ACTION_ENUM action;
    kal_uint32 data1;
    kal_uint32 data2;
    kal_uint32 data3;
    kal_uint32 data4;
    kal_uint32 time;
    kal_bool power;
} HIF_DEBUG_DATA_T;

#define HIF_DEBUG_COUNT 10000
static volatile HIF_DEBUG_DATA_T hif_debug_data[HIF_DEBUG_COUNT] = 0;
static volatile kal_uint32 hif_debug_index = 0;

void hif_trace(HIF_ACTION_ENUM action, kal_uint32 data1, kal_uint32 data2, kal_uint32 data3, kal_uint32 data4)
{
    int index;
    kal_uint32 save_irq_mask;
    save_irq_mask = SaveAndSetIRQMask();
    hif_debug_index++;
    hif_debug_index %= HIF_DEBUG_COUNT;
    index =hif_debug_index;
    RestoreIRQMask(save_irq_mask);
    hif_debug_data[index].action = action;
    hif_debug_data[index].time = drv_get_current_time();
    hif_debug_data[index].data1 = data1;
    hif_debug_data[index].data2 = data2;
    hif_debug_data[index].data3 = data3;
    hif_debug_data[index].data4 = data4;
    hif_debug_data[index].power = hif_power_on;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

void hif_init(void)
{
    hif_trace(HIF_________INIT, 0, 0, 0, 0);
    // Init structure.
    memset(hif_internal_handle, 0, sizeof(hif_internal_handle));

    // Init HIF interrupr
    IRQ_Register_LISR(IRQ_HIF_CODE, hif_lisr, "HIF ISR");
    IRQSensitivity(IRQ_HIF_CODE, LEVEL_SENSITIVE);
    //hif_hisr_id = kal_create_hisr("HIF_HISR", 0, 1024, hif_hisr, KAL_TRUE);
    IRQUnmask(IRQ_HIF_CODE);
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif


}

HIF_HANDLE hif_open(kal_uint32 port)
{
    hif_trace(HIF_________OPEN, port, 0, 0, 0);
    if(port >= HIF_MAX_PORT_NUM)
      return 0;
    //ASSERT(hif_internal_handle[port].user == NULL);
    if(hif_internal_handle[port].user != NULL)
      return 0;
    if(DRV_Reg32(APHW_VER_FOR_HIF)==0xCA10)
    {//MT6573E2=0xCA10,MT6573E1=0x8A00,only on MT6573E2,need to check whether it succeeded to power on MMSYS1
      hif_tl1_sleep_handle = L1SM_GetHandle();
    }
    hif_internal_handle[port].user = 1;
    hif_internal_handle[port].port = port;
    hif_power_ctrl((HIF_HANDLE)NULL, KAL_TRUE);

    // HIF driver works in MD side. Select MD DMA.
    HIF_SET_MD_DMA;
    //HIF_SET_AP_DMA;
#if defined(__UMTS_TDD128_MODE__)
    hif_sysdma_id = DMA_FullSize_GetChannel(DMA_TD_L1);
#else
    hif_sysdma_id = DMA_GDMA2;
#endif
    //hif_sysdma_id = 2;

    // Configure DMA
    hif_dma_input.size = DMA_SHORT;
    hif_dma_input.menu = (void*) &hif_dma_menu;
#if defined(__UMTS_TDD128_MODE__)
    hif_dma_menu.master = DMA_TD_L1;
#else
    hif_dma_menu.master = DMA_GDMA2;
#endif
    hif_dma_menu.rsize = DMA_CON_RSIZE_4BYTE;
    hif_dma_menu.wsize = DMA_CON_WSIZE_4BYTE;
    hif_dma_menu.req_ack_connect = DMA_CONNECT_HIF;
	hif_dma_menu.req_ack_ratio = DMA_REQ_ACK_RATIO_1_1;
    hif_dma_menu.TMOD.burst_mode = KAL_TRUE;
    hif_dma_menu.TMOD.cycle = 8;

    //DMA_FullSize_Config(hif_sysdma_id, &hif_dma_input, KAL_FALSE);
    hif_dcm_handle=DCM_GetHandle();
    hif_power_ctrl((HIF_HANDLE)NULL, KAL_FALSE);
    return (HIF_HANDLE)(&hif_internal_handle[port]);
}

HIF_RESULT hif_close(HIF_HANDLE handle)
{
    HIF_INTERNAL_HANDLE_T* pHandle = (HIF_INTERNAL_HANDLE_T*) handle;
    hif_trace(HIF________CLOSE, pHandle->port, 0, 0, 0);
    //ASSERT(pHandle != NULL);
    //ASSERT(pHandle->user != 0);
  if((pHandle == NULL)||(pHandle->user == 0))
        return HIF_RESULT_INVALID_HANDLE;
    pHandle->user = 0;

    return HIF_RESULT_OK;
}

HIF_RESULT hif_config(HIF_HANDLE handle, HIF_CONFIG_T* pConfigParam)
{
    HIF_INTERNAL_HANDLE_T* pHandle = (HIF_INTERNAL_HANDLE_T*) handle;
    hif_trace(HIF_______CONFIG, pHandle->port, 0, 0, 0);
    //ASSERT(pHandle != NULL);
    //ASSERT(pHandle->user != 0);
  if((pHandle == NULL)||(pHandle->user == 0))
        return HIF_RESULT_INVALID_HANDLE;
    //ASSERT(pConfigParam != NULL);
    if(pConfigParam == NULL)
      return HIF_RESULT_INVALID_ARGUMENT;
    pHandle->config = *pConfigParam;
    switch (pHandle->config.hif_base_clk)
    {
    case 122:
        // Parallel clock is fixed to be 122.28MHz
        break;
    default:
        //ASSERT(0);
        return HIF_RESULT_INVALID_ARGUMENT;
        break;
    }
//set LCD interface width,,PDW
    switch (pHandle->config.hif_bus_width)
    {
    case 8:
        SET_HIF_LCD_8BIT_DATA_BUS(pHandle->port);
        break;
    case 16:
        SET_HIF_LCD_16BIT_DATA_BUS(pHandle->port);
        break;
    default:
        //ASSERT(0);
        return HIF_RESULT_INVALID_ARGUMENT;
        break;
    }
//for V1,set LCD timing
    SET_HIF_CE2WR_SETUP_TIME (pHandle->port, pHandle->config.hif_time_c2ws);
    SET_HIF_CE2WR_HOLD_TIME  (pHandle->port, pHandle->config.hif_time_c2wh);
    SET_HIF_CE2RD_SETUP_TIME (pHandle->port, pHandle->config.hif_time_c2rs);
    SET_HIF_CE2RD_HOLD_TIME  (pHandle->port, pHandle->config.hif_time_c2rh);
    SET_HIF_WRITE_WAIT_STATE (pHandle->port, pHandle->config.hif_time_wst);
    SET_HIF_READ_LATENCY_TIME(pHandle->port, pHandle->config.hif_time_rlt);

    return HIF_RESULT_OK;
}

HIF_RESULT hif_power_ctrl(HIF_HANDLE handle, kal_bool bPowerOn)
{
    kal_uint32 start_time=drv_get_current_time();
    HIF_INTERNAL_HANDLE_T* pHandle = (HIF_INTERNAL_HANDLE_T*) handle;
    hif_trace(HIF____POWERCTRL, pHandle->port, bPowerOn, 0, 0);
    if (pHandle != NULL)
    {
        // TODO: [Multiple user concurrency issue].
    }
    if (bPowerOn)
    {
      if(DRV_Reg32(APHW_VER_FOR_HIF)==0xCA10)//for MT6573E2
      {
        L1SM_SleepDisable(hif_tl1_sleep_handle);//unlock MD sleep mode
        DRV_SetBits32(RM_PWR_CON_FOR_HIF,0x20);//power on MMSYS1:(TOPSM_base+0x810),bit[5] MD_PWR_REQ_EN
        //MT6573E2=0xCA10,MT6573E1=0x8A00,only on MT6573E2,need to check whether it succeeded to power on MMSYS1
          while(1)
          {
            if(DRV_Reg32(RM_PWR_STA_FOR_HIF) & MM1_SYS_PWR_ACK)//0x820 RM_PWR_STA,MM1 SYS PWR ACK BIT[20]
              break;
            if(drv_get_duration_ms(start_time)>2000)//power on timeout
              ASSERT(0);
          }
        DRV_WriteReg32(TOPSM_DMY0_FOR_HIF,0);//AP dummy
        DRV_SetBits32(AP_SAPD_WAYEN_FOR_HIF,1<<8);//AP MMSYS1 wayen
      }
      //lcd_power_ctrl__enable(AST_HIF_PWR_HANDLE);
      //FOR AB:DMA clock
      DRV_WriteReg32(DRVPDN_CON1_CLR, DRVPDN_CON0_MDDMA);     // MD size DMA clock.
      //DRV_WriteReg32(MMSYS_CG_CLR0, MMSYS_CG_CON0_LCD);       // LCD clock.
      DRV_WriteReg32(MMSYS_CG_CLR1, MMSYS_CG_CON1_HIF);       // HIF clock.
      hif_power_on = KAL_TRUE;
    }
    else
    {
      if(DRV_Reg32(APHW_VER_FOR_HIF)==0xCA10)//for MT6573E2,power off,when on MT6573,neednot to do AP dummy and wayen
      {
        L1SM_SleepEnable(hif_tl1_sleep_handle);//lock MD sleep mode
        //DRV_WriteReg32(TOPSM_DMY0_FOR_HIF,0xFFFFFFFF);//AP dummy
        //DRV_ClearBits32(AP_SAPD_WAYEN_FOR_HIF,1<<8);
        //DRV_ClearBits32(RM_PWR_CON_FOR_HIF,0x20);//power OFF MMSYS1:(TOPSM_base+0x810),bit[5] MD_PWR_REQ_EN
      }
      hif_power_on = KAL_FALSE;
      //lcd_power_ctrl__disable(AST_HIF_PWR_HANDLE);
      //FOR AB:DMA clock
      DRV_WriteReg32(DRVPDN_CON1_SET, DRVPDN_CON0_MDDMA);     // MD size DMA clock.
      DRV_WriteReg32(MMSYS_CG_SET1, MMSYS_CG_CON1_HIF);       // HIF clock.
      //DRV_WriteReg32(MMSYS_CG_SET0, MMSYS_CG_CON0_LCD);       // LCD clock.
    }
    return HIF_RESULT_OK;
}

HIF_RESULT hif_write(HIF_HANDLE handle, HIF_TYPE type, kal_uint32 addr, kal_uint32 size, HIF_CALLBACK fCB)
{
    kal_uint32 index = 0;
    HIF_RESULT result = HIF_RESULT_OK;
    HIF_INTERNAL_HANDLE_T* pHandle = (HIF_INTERNAL_HANDLE_T*) handle;
    //ASSERT(pHandle != NULL);
    //ASSERT(pHandle->user != 0);
    if((pHandle == NULL)||(pHandle->user == 0))
        return HIF_RESULT_INVALID_HANDLE;
    //ASSERT(size != 0);
    //ASSERT((pHandle->config.hif_bus_width==8)? 1 : (size%2==0));
    if ((size == 0) || (!((pHandle->config.hif_bus_width==8)? 1 : (size%2==0))))
        return HIF_RESULT_INVALID_ARGUMENT;
    //ASSERT(hif_power_on == KAL_TRUE);
    if (hif_power_on == KAL_FALSE)
        return HIF_RESULT_HIF_NOT_POWER_ON;
    //check if DMA is busy,to avoid re-entry DMA mode.
    if ((HIF_BUSY==1)&&(type == HIF_TYPE_A0H_DMA||type == HIF_TYPE_A0L_DMA))
        return HIF_RESULT_DMA_IS_BUSY;

    switch (type)
    {
    case HIF_TYPE_A0H_CPU:
        {
            //hif_trace(HIF__WRITE_CPU_H, pHandle->port, size, addr, (kal_uint32)(fCB));
            if (pHandle->config.hif_bus_width == 8)
            {
                for (index = 0; index < size; index++)
                    *(volatile kal_uint8*)(HIF_PORT_A0_HIGH_ADDR(pHandle->port)) = *(volatile kal_uint8*)(((kal_uint8*)(addr)) + index);
            }
            else if (pHandle->config.hif_bus_width == 16)
            {
                for (index = 0; index < size/2; index++)
                    *(volatile kal_uint16*)(HIF_PORT_A0_HIGH_ADDR(pHandle->port)) = *(volatile kal_uint16*)(((kal_uint16*)(addr)) + index);
            }
            else
            {
                //ASSERT(0);
                result = HIF_RESULT_INVALID_ARGUMENT;
            }
        }
        break;
    case HIF_TYPE_A0H_DMA:
        {
            // TODO: First check if HIF is runing. Wait until HIF is idle and disable I bit. After HIF is started, enable I bit again.
            // Disable PDMA interrupt. Enable HIF interrupt.
            hif_trace(HIF_WRITE_DMA_HS, pHandle->port, size, addr, (kal_uint32)(fCB));
            if (fCB)
            {
                ENABLE_HIF_INTR;
            }
            // Setup HIF.
            SET_HIF_BUS_WIDTH(pHandle->config.hif_bus_width);
            SET_HIF_WRITE;
            SET_HIF_A0_HIGH;
            SET_HIF_CS(pHandle->port);
            SET_HIF_DAMOUNT(size);
            // Set PDMA destination address. HIF_DATA_REG
            hif_dma_menu.source = addr;
            hif_dma_menu.destination = HIF_DATA_REG;
            hif_dma_input.size = (pHandle->config.hif_bus_width == 16) ? DMA_SHORT : DMA_BYTE;
            hif_dma_input.type = DMA_HWTX;
            hif_dma_input.count  = (pHandle->config.hif_bus_width == 16) ? (size >> 1) : size;
            hif_dma_input.callback = NULL;
            hif_dma_menu.fixed_waddr = KAL_TRUE;
            hif_dma_menu.fixed_raddr = KAL_FALSE;
            hif_dma_menu.req_ack_connect = DMA_CONNECT_HIF;
            hif_dma_menu.req_ack_ratio = DMA_REQ_ACK_RATIO_1_1;
            hif_dma_menu.req_ack_dir = DMA_CONNECT_WRITE;
            hif_dma_menu.wsize = DMA_CON_WSIZE_4BYTE;
            hif_dma_menu.rsize = DMA_CON_RSIZE_4BYTE;
            hif_dma_menu.TMOD.burst_mode = KAL_TRUE;
            hif_dma_menu.TMOD.cycle = 8;

            DMA_FullSize_Config(hif_sysdma_id, &hif_dma_input, KAL_FALSE);

            // Set fCB as HIF interrupt callback.
            hif_cb = fCB;
            DCM_Disable(hif_dcm_handle);//disable DCM,before transfer,enalbe in hif_hisr

            // Start HIF
            START_HIF;
            // Start DMA
            DMA_Run(hif_sysdma_id);
            if (fCB == NULL)
            {
                // Polling mode.
                // Wait for HIF done.
                hif_wait_for_idle();
                //DMA_WaitforDone(hif_sysdma_id);
            }
            hif_trace(HIF_WRITE_DMA_HE, pHandle->port, size, addr, (kal_uint32)(fCB));
        }
        break;
    case HIF_TYPE_A0L_CPU:
        {
            //hif_trace(HIF__WRITE_CPU_L, pHandle->port, size, addr, (kal_uint32)(fCB));
            if (pHandle->config.hif_bus_width == 8)
            {
                for (index = 0; index < size; index++)
                    *(volatile kal_uint8*)(HIF_PORT_A0_LOW_ADDR(pHandle->port)) = *(volatile kal_uint8*)(((kal_uint8*)(addr)) + index);
            }
            else if (pHandle->config.hif_bus_width == 16)
            {
                for (index = 0; index < size/2; index++)
                    *(volatile kal_uint16*)(HIF_PORT_A0_LOW_ADDR(pHandle->port)) = *(volatile kal_uint16*)(((kal_uint16*)(addr)) + index);
            }
            else
            {
                //ASSERT(0);
                result = HIF_RESULT_INVALID_ARGUMENT;
            }
        }
        break;
    case HIF_TYPE_A0L_DMA:
        {
            hif_trace(HIF_WRITE_DMA_LS, pHandle->port, size, addr, (kal_uint32)(fCB));
            // TODO: [Multiple user concurrency issue]. First check if HIF is runing. Wait until HIF is idle and disable I bit. After HIF is started, enable I bit again.
            // Disable PDMA interrupt. Enable HIF interrupt.
            if (fCB)
            {
                ENABLE_HIF_INTR;
            }
            // Setup HIF.
            SET_HIF_BUS_WIDTH(pHandle->config.hif_bus_width);
            SET_HIF_WRITE;
            SET_HIF_A0_LOW;
            SET_HIF_CS(pHandle->port);
            SET_HIF_DAMOUNT(size);
            // Set PDMA destination address. HIF_DATA_REG
            hif_dma_menu.source = addr;
            hif_dma_menu.destination = HIF_DATA_REG;
            hif_dma_input.size = (pHandle->config.hif_bus_width == 16) ? DMA_SHORT : DMA_BYTE;
            hif_dma_input.type = DMA_HWTX;
            hif_dma_input.count = (pHandle->config.hif_bus_width == 16) ? (size >> 1) : size;
            hif_dma_input.callback = NULL;
            hif_dma_menu.fixed_waddr = KAL_TRUE;
            hif_dma_menu.fixed_raddr = KAL_FALSE;
            hif_dma_menu.req_ack_connect = DMA_CONNECT_HIF;
            hif_dma_menu.req_ack_ratio = DMA_REQ_ACK_RATIO_1_1;
            hif_dma_menu.req_ack_dir = DMA_CONNECT_WRITE;
            hif_dma_menu.wsize = DMA_CON_WSIZE_4BYTE;
            hif_dma_menu.rsize = DMA_CON_RSIZE_4BYTE;
            hif_dma_menu.TMOD.burst_mode = KAL_TRUE;
            hif_dma_menu.TMOD.cycle = 8;
            DMA_FullSize_Config(hif_sysdma_id, &hif_dma_input, KAL_FALSE);
            *(volatile kal_uint32*)(0x60000118) = 0x22070008;

            // Set fCB as HIF interrupt callback.
            hif_cb = fCB;
            DCM_Disable(hif_dcm_handle);//DCM disable
            // Start HIF
            START_HIF;
            // Start DMA
            //DMA2_Start(hif_sysdma_id);
            DMA_Run(hif_sysdma_id);
            if (fCB == NULL)
            {
                // Polling mode.
                // Wait for HIF done.
                hif_wait_for_idle();
                //DMA_WaitforDone(hif_sysdma_id);
            }
            hif_trace(HIF_WRITE_DMA_LE, pHandle->port, size, addr, (kal_uint32)(fCB));
        }
        break;
    default:
        //ASSERT(0);
        result = HIF_RESULT_INVALID_ARGUMENT;
        break;
    }
    //hif_trace(HIF____WRITE_RET, pHandle->port, size, addr, (kal_uint32)(fCB));
    return result;
}

HIF_RESULT hif_read(HIF_HANDLE handle, HIF_TYPE type, kal_uint32 addr, kal_uint32 size, HIF_CALLBACK fCB)
{
    kal_uint32 index = 0;
    HIF_RESULT result = HIF_RESULT_OK;
    HIF_INTERNAL_HANDLE_T* pHandle = (HIF_INTERNAL_HANDLE_T*) handle;
    //ASSERT(pHandle != NULL);
    //ASSERT(pHandle->user != 0);
    if((pHandle == NULL)||(pHandle->user == 0))
        return HIF_RESULT_INVALID_HANDLE;
    //ASSERT(hif_power_on == KAL_TRUE);
    if (hif_power_on == KAL_FALSE)
        return HIF_RESULT_HIF_NOT_POWER_ON;
    //check if DMA is busy,to avoid re-entry DMA mode.
    if ((HIF_BUSY==1)&&(type == HIF_TYPE_A0H_DMA||type == HIF_TYPE_A0L_DMA))
        return HIF_RESULT_DMA_IS_BUSY;
    switch (type)
    {
    case HIF_TYPE_A0H_CPU:
        {
            //hif_trace(HIF___READ_CPU_H, pHandle->port, size, addr, (kal_uint32)(fCB));
            if (pHandle->config.hif_bus_width == 8)
            {
                for (index = 0; index < size; index++)
                    *(volatile kal_uint8*)(((kal_uint8*)addr)+index) = *(volatile kal_uint8*)(HIF_PORT_A0_HIGH_ADDR(pHandle->port));
            }
            else if (pHandle->config.hif_bus_width == 16)
            {
                for (index = 0; index < size/2; index++)
                    *(volatile kal_uint16*)(((kal_uint16*)addr)+index) = *(volatile kal_uint16*)(HIF_PORT_A0_HIGH_ADDR(pHandle->port));
            }
            else
            {
                //ASSERT(0);
                result = HIF_RESULT_INVALID_ARGUMENT;
            }
        }
        break;
    case HIF_TYPE_A0H_DMA:
        {
            hif_trace(HIF__READ_DMA_HS, pHandle->port, size, addr, (kal_uint32)(fCB));
            // TODO: First check if HIF is runing. Wait until HIF is idle and disable I bit. After HIF is started, enable I bit again.
            // Enable PDMA interrupt. Disable HIF interrupt.
            if (fCB)
            {
                ENABLE_HIF_INTR;
            }
            hif_dma_input.callback = NULL;
            // Setup HIF.
            SET_HIF_BUS_WIDTH(pHandle->config.hif_bus_width);
            SET_HIF_READ;
            SET_HIF_A0_HIGH;
            SET_HIF_CS(pHandle->port);
            SET_HIF_DAMOUNT(size);
            // Set PDMA source address. HIF_DATA_REG
            hif_dma_menu.source = HIF_DATA_REG;
            hif_dma_menu.destination = addr;
            hif_dma_input.size = (pHandle->config.hif_bus_width == 16) ? DMA_SHORT : DMA_BYTE;
            hif_dma_input.type = DMA_HWRX;
            hif_dma_input.count = (pHandle->config.hif_bus_width == 16) ? (size >> 1) : size;
            hif_dma_menu.fixed_raddr = KAL_TRUE;
            hif_dma_menu.req_ack_connect = DMA_CONNECT_HIF;
            hif_dma_menu.req_ack_ratio = DMA_REQ_ACK_RATIO_1_1;
            hif_dma_menu.req_ack_dir = DMA_CONNECT_READ;

            hif_dma_menu.wsize = DMA_CON_WSIZE_4BYTE;
                  hif_dma_menu.rsize = DMA_CON_RSIZE_4BYTE;
            hif_dma_menu.TMOD.burst_mode = KAL_TRUE;
            hif_dma_menu.TMOD.cycle = 8;
            DMA_FullSize_Config(hif_sysdma_id, &hif_dma_input, KAL_FALSE);
            hif_cb = fCB;

            DCM_Disable(hif_dcm_handle);//disable DCM,before transfer,enalbe in hif_hisr
            // Start HIF
            START_HIF;
            // Start DMA
            DMA_Run(hif_sysdma_id);
            if (fCB == NULL)
            {
                // Polling mode.
                // Wait for hif done.
               hif_wait_for_idle();
                //DMA_WaitforDone(hif_sysdma_id);
            }
            hif_trace(HIF__READ_DMA_HE, pHandle->port, size, addr, (kal_uint32)(fCB));
        }
        break;
    case HIF_TYPE_A0L_CPU:
        {
            //hif_trace(HIF___READ_CPU_L, pHandle->port, size, addr, (kal_uint32)(fCB));
            if (pHandle->config.hif_bus_width == 8)
            {
                for (index = 0; index < size; index++)
                    *(volatile kal_uint8*)(((kal_uint8*)addr)+index) = *(volatile kal_uint8*)(HIF_PORT_A0_LOW_ADDR(pHandle->port));
            }
            else if (pHandle->config.hif_bus_width == 16)
            {
                for (index = 0; index < size/2; index++)
                    *(volatile kal_uint16*)(((kal_uint16*)addr)+index) = *(volatile kal_uint16*)(HIF_PORT_A0_LOW_ADDR(pHandle->port));
            }
            else
            {
                //ASSERT(0);
                result = HIF_RESULT_INVALID_ARGUMENT;
            }
        }
        break;
    case HIF_TYPE_A0L_DMA:
        {
            hif_trace(HIF__READ_DMA_LS, pHandle->port, size, addr, (kal_uint32)(fCB));
            // TODO: First check if HIF is runing. Wait until HIF is idle and disable I bit. After HIF is started, enable I bit again.
            // Enable PDMA interrupt. Disable HIF interrupt.
            if (fCB)
            {
                ENABLE_HIF_INTR;
            }
            hif_dma_input.callback = NULL;
            // Setup HIF.
            SET_HIF_BUS_WIDTH(pHandle->config.hif_bus_width);
            SET_HIF_READ;
            SET_HIF_A0_LOW;
            SET_HIF_CS(pHandle->port);
            SET_HIF_DAMOUNT(size);
            // Set PDMA source address. HIF_DATA_REG
            hif_dma_menu.source = HIF_DATA_REG;
            hif_dma_menu.destination = addr;
            hif_dma_input.size = (pHandle->config.hif_bus_width == 16) ? DMA_SHORT : DMA_BYTE;
            hif_dma_input.type = DMA_HWRX;
            hif_dma_input.count = (pHandle->config.hif_bus_width == 16) ? (size >> 1) : size;
            hif_dma_menu.fixed_raddr = KAL_TRUE;
            hif_dma_menu.fixed_waddr = KAL_FALSE;
            hif_dma_menu.req_ack_connect = DMA_CONNECT_HIF;
            hif_dma_menu.req_ack_ratio = DMA_REQ_ACK_RATIO_1_1;
            hif_dma_menu.req_ack_dir = DMA_CONNECT_READ;

            hif_dma_menu.wsize = DMA_CON_WSIZE_4BYTE;
            hif_dma_menu.rsize = DMA_CON_RSIZE_4BYTE;
            hif_dma_menu.TMOD.burst_mode = KAL_TRUE;
            hif_dma_menu.TMOD.cycle = 8;

            DMA_FullSize_Config(hif_sysdma_id, &hif_dma_input, KAL_FALSE);

            hif_cb = fCB;
            DCM_Disable(hif_dcm_handle);//disable DCM,before transfer,enalbe in hif_hisr

            // Start HIF
            START_HIF;
            // Start DMA
            DMA_Run(hif_sysdma_id);
            if (fCB == NULL)
            {
                // Polling mode.Wait for HIF done.
                hif_wait_for_idle();
                //DMA_WaitforDone(hif_sysdma_id);
            }
            hif_trace(HIF__READ_DMA_LE, pHandle->port, size, addr, (kal_uint32)(fCB));
        }
        break;
    default:
        //ASSERT(0);
        result = HIF_RESULT_INVALID_ARGUMENT;
        break;
    }

    //hif_trace(HIF_____READ_RET, pHandle->port, size, addr, (kal_uint32)(fCB));
    return result;
}

void hif_lisr(void)
{
    volatile kal_uint32 insta;
    IRQMask(IRQ_HIF_CODE);
    insta = (*(volatile kal_uint32*)HIF_INSTA_REG);//hif int status,read clear
    //kal_activate_hisr(hif_hisr_id);
    hif_hisr(); // Call HIF callback function at LISR level. HIF V1 is only used on MT6573 for TD.
}

void hif_hisr(void)
{
    hif_trace(HIF______HIF_INT, 0, 0, 0, 0);
    DCM_Enable(hif_dcm_handle);
    if (hif_cb)
        hif_cb();
    IRQUnmask(IRQ_HIF_CODE);
}

void hif_wait_for_idle(void)
{
    while(HIF_BUSY);
}

HIF_RESULT hif_ioctl(HIF_HANDLE handle, HIF_IOCTL_CODE code, void* pParam)
{
    HIF_RESULT result = HIF_RESULT_OK;
    HIF_INTERNAL_HANDLE_T* pHandle = (HIF_INTERNAL_HANDLE_T*) handle;
    //ASSERT(pHandle);
    if (pHandle == NULL)
        return HIF_RESULT_INVALID_HANDLE;
    switch (code)
    {
    case HIF_IOCTL_QUERY_TIMING_SUPPORT:
        {
            HIF_QUERY_TIMING_SUPPORT_T* pTimingSupport = (HIF_QUERY_TIMING_SUPPORT_T*) pParam;
            //ASSERT(pTimingSupport);
            if (pTimingSupport == NULL)
            {
                result = HIF_RESULT_INVALID_ARGUMENT;
                break;
            }
            pTimingSupport->c2ws_support = KAL_TRUE;
            pTimingSupport->c2wh_support = KAL_TRUE;
            pTimingSupport->wst_support = KAL_TRUE;
            pTimingSupport->c2rs_support = KAL_TRUE;
            pTimingSupport->c2rh_support = KAL_TRUE;
            pTimingSupport->rlt_support = KAL_TRUE;
        }
        break;
    case HIF_IOCTL_QUERY_CLOCK_SUPPORT:
        {
            HIF_QUERY_CLOCK_SUPPORT_T* pColckSupport = (HIF_QUERY_CLOCK_SUPPORT_T*) pParam;
            //ASSERT(pColckSupport);
            if (pColckSupport == NULL)
            {
                result = HIF_RESULT_INVALID_ARGUMENT;
                break;
            }
            pColckSupport->clock[0] = 122;
            pColckSupport->clock[1] = 0;
            pColckSupport->clock[2] = 0;
            pColckSupport->clock[3] = 0;
        }
        break;
    case HIF_IOCTL_GET_PARAM:
        {
            HIF_CONFIG_T* pHIFParam = (HIF_CONFIG_T*) pParam;
            //ASSERT(pHIFParam);
            if (pHIFParam == NULL)
            {
                result = HIF_RESULT_INVALID_ARGUMENT;
                break;
            }
            *pHIFParam = pHandle->config;
            /*
            pHIFParam->hif_time_c2ws = pHandle->config.hif_time_c2ws;
            pHIFParam->hif_time_c2wh = pHandle->config.hif_time_c2wh;
            pHIFParam->hif_time_wst = pHandle->config.hif_time_wst;
            pHIFParam->hif_time_c2rs = pHandle->config.hif_time_c2rs;
            pHIFParam->hif_time_c2rh = pHandle->config.hif_time_c2rh;
            pHIFParam->hif_time_rlt = pHandle->config.hif_time_rlt;
            pHIFParam->hif_base_clk = pHandle->config.hif_base_clk;
            pHIFParam->hif_bus_width = pHandle->config.hif_bus_width;
            */
        }
        break;
    case HIF_IOCTL_QUERY_CAPABILITY:
        {
            HIF_CAPABILITY_T* pCapability = (HIF_CAPABILITY_T*) pParam;
            //ASSERT(pCapability);
            if (pCapability == NULL)
            {
                result = HIF_RESULT_INVALID_ARGUMENT;
                break;
            }
            pCapability->transfer_length_min = 1;
            pCapability->transfer_length_max = 65536;
        }
        break;
    case HIF_IOCTL_QUERY_POWER_STATE:
        {
            HIF_POWER_STATE_T* pPowerState = (HIF_POWER_STATE_T*) pParam;
            if (pPowerState == NULL)
            {
                result = HIF_RESULT_INVALID_ARGUMENT;
                break;
            }
            pPowerState->hif_power_on = hif_power_on;
        }
        break;
    default:
        //ASSERT(0);
        result = HIF_RESULT_NOT_SUPPORTED;
        break;
    }
    return result;
}

#endif
