//#pragma O0

#include "kal_release.h"
#include "drv_features.h"
#include "lcd_if.h"
#include "hif_hal.h"
#include "hif_legacy_internal.h"
#include "intrCtrl.h"
#include "dma_sw.h"
#include "dma_hw.h"
#include "drv_comm.h"
#include "lcd_power_mgr.h"
#include "lcd_if_manager.h"
#include "hif_hal.h"
#include "lcd_if_hw.h"
#if defined(DRV_HIF_LEGACY) && defined(DRV_HIF_SUPPORT)


// Global variables
static volatile kal_bool hif_power_on = KAL_FALSE;
static volatile HIF_INTERNAL_HANDLE_T hif_internal_handle[HIF_MAX_PORT_NUM];

// Debug data
typedef enum
{
    HIF_________INIT,
    HIF_________OPEN,
    HIF________CLOSE,
    HIF_______CONFIG,
    HIF____POWERCTRL,
    HIF________WRITE,
    HIF_________READ,
    HIF________IOCTL
} HIF_ACTION_ENUM;

typedef struct
{
    HIF_ACTION_ENUM action;
    kal_uint32 time;
    kal_uint32 param;
    kal_bool power;
} HIF_DEBUG_DATA_T;

#define HIF_DEBUG_COUNT 128
static volatile HIF_DEBUG_DATA_T hif_debug_data[HIF_DEBUG_COUNT];
static volatile kal_uint32 hif_debug_index = 0;

void hif_trace(HIF_ACTION_ENUM action, kal_uint32 param)
{
    //kal_uint32 index = hif_debug_index++;
    hif_debug_index = (hif_debug_index++) % HIF_DEBUG_COUNT;
    hif_debug_data[hif_debug_index].action = action;
    hif_debug_data[hif_debug_index].time = drv_get_current_time();
    hif_debug_data[hif_debug_index].param = param;
    hif_debug_data[hif_debug_index].power = hif_power_on;
}

void hif_init(void)
{
    // Init structure.
    hif_trace(HIF_________INIT, 0);
    memset(hif_internal_handle, 0, sizeof(hif_internal_handle));
}

HIF_HANDLE hif_open(kal_uint32 port)
{
    hif_trace(HIF_________OPEN, port);
    //ASSERT(port < HIF_MAX_PORT_NUM);
    if (port >= HIF_MAX_PORT_NUM)
        return 0;
    //ASSERT(hif_internal_handle[port].user == NULL);
    if (hif_internal_handle[port].user != NULL)
        return 0;
    hif_internal_handle[port].user = 1;
    hif_internal_handle[port].power_handle = lcd_power_ctrl__register_module();
    hif_internal_handle[port].if_handle = lcd_get_ioctrl_device_if_handle(LCD_IF_USER_HIF);
    hif_internal_handle[port].port = port;
#ifdef __AST_TL1_TDD__
    if (hif_internal_handle[port].dma_id == 0)
    {
        // dma init
        hif_internal_handle[port].dma_id = DMA_FullSize_GetChannel(DMA_TD_L1);

	    if (hif_internal_handle[port].dma_id != 0xff)
	    {
    		DMA_Register_RT_CallBack(hif_internal_handle[port].dma_id);

            hif_internal_handle[port].dma_input.size = DMA_SHORT;
            hif_internal_handle[port].dma_input.menu = (void*) &(hif_internal_handle[port].dma_menu);
            hif_internal_handle[port].dma_input.callback = NULL;

            hif_internal_handle[port].dma_menu.master = DMA_TD_L1;
            hif_internal_handle[port].dma_menu.TMOD.burst_mode = KAL_TRUE;
            hif_internal_handle[port].dma_menu.TMOD.cycle = 8;

            DMA_FullSize_Config(hif_internal_handle[port].dma_id, &(hif_internal_handle[port].dma_input), KAL_FALSE);
        }
    }
#endif
    lcd_power_ctrl__enable(hif_internal_handle[port].power_handle);

    hif_internal_handle[port].lcd_if_config.if_type = LCD_IF_TYPE_DBI_PARALLEL;
    hif_internal_handle[port].lcd_if_config.if_cs_no = 1;

    lcd_ioctrl_device_if_settings(hif_internal_handle[port].if_handle, LCD_IOCTRL_QUERY_DEVICE_IF, &(hif_internal_handle[port].lcd_if_config), sizeof(LCD_IOCTRL_DEVICE_IF_T));

    lcd_power_ctrl__disable(hif_internal_handle[port].power_handle);

    return (HIF_HANDLE)(&hif_internal_handle[port]);
}

HIF_RESULT hif_close(HIF_HANDLE handle)
{
    HIF_INTERNAL_HANDLE_T* pHandle = (HIF_INTERNAL_HANDLE_T*) handle;
    hif_trace(HIF________CLOSE, (kal_uint32)handle);
    //ASSERT(pHandle != NULL);
    if (pHandle == NULL)
        return HIF_RESULT_INVALID_HANDLE;
    //ASSERT(pHandle->user != 0);
    if (pHandle->user == 0)
        return HIF_RESULT_INVALID_HANDLE;
    pHandle->user = 0;
    pHandle->power_handle = 0;
    pHandle->if_handle = 0;
    return HIF_RESULT_OK;
}

HIF_RESULT hif_config(HIF_HANDLE handle, HIF_CONFIG_T* pConfigParam)
{
    //kal_uint32 TD_IF_Val;
    //kal_uint32 val;
    HIF_INTERNAL_HANDLE_T* pHandle = (HIF_INTERNAL_HANDLE_T*) handle;
    hif_trace(HIF_______CONFIG, (kal_uint32)handle);
    //ASSERT(pHandle != NULL);
    if (pHandle == NULL)
        return HIF_RESULT_INVALID_HANDLE;
    //ASSERT(hif_power_on == KAL_TRUE);
    if (hif_power_on == KAL_FALSE)
        return HIF_RESULT_HIF_NOT_POWER_ON;

    pHandle->config = *pConfigParam;

    pHandle->lcd_if_config.if_type = LCD_IF_TYPE_DBI_PARALLEL;
    pHandle->lcd_if_config.if_cs_no = 1;

    lcd_ioctrl_device_if_settings(pHandle->if_handle, LCD_IOCTRL_QUERY_DEVICE_IF, &(pHandle->lcd_if_config), sizeof(LCD_IOCTRL_DEVICE_IF_T));

    pHandle->lcd_if_config.if_settings.dbi_parallel_if.if_cs_no = 1;
    pHandle->lcd_if_config.if_settings.dbi_parallel_if.if_bus_width = pConfigParam->hif_bus_width;
    pHandle->lcd_if_config.if_settings.dbi_parallel_if.if_c2ws = pConfigParam->hif_time_c2ws;
    pHandle->lcd_if_config.if_settings.dbi_parallel_if.if_wst = pConfigParam->hif_time_wst;
    pHandle->lcd_if_config.if_settings.dbi_parallel_if.if_c2wh = pConfigParam->hif_time_c2wh;
    pHandle->lcd_if_config.if_settings.dbi_parallel_if.if_c2rs = pConfigParam->hif_time_c2rs;
    pHandle->lcd_if_config.if_settings.dbi_parallel_if.if_c2rh = pConfigParam->hif_time_c2rh;
    pHandle->lcd_if_config.if_settings.dbi_parallel_if.if_rlt = pConfigParam->hif_time_rlt;
    pHandle->lcd_if_config.if_settings.dbi_parallel_if.if_clk_freq = pConfigParam->hif_base_clk * 1000000;

    lcd_ioctrl_device_if_settings(pHandle->if_handle, LCD_IOCTRL_CONFIG_DEVICE_IF, &(pHandle->lcd_if_config), sizeof(LCD_IOCTRL_DEVICE_IF_T));

    return HIF_RESULT_OK;
}

HIF_RESULT hif_power_ctrl(HIF_HANDLE handle, kal_bool bPowerOn)
{
    HIF_INTERNAL_HANDLE_T* pHandle = (HIF_INTERNAL_HANDLE_T*) handle;
    hif_trace(HIF____POWERCTRL, (kal_uint32)bPowerOn);
    if (pHandle == NULL)
        return HIF_RESULT_INVALID_HANDLE;
    if (pHandle != NULL)
    {
        // TODO: [Multiple user concurrency issue].
    }
    if (bPowerOn)
    {
        lcd_power_ctrl__enable(pHandle->power_handle);
        lcd_ioctrl_device_if_settings(pHandle->if_handle, LCD_IOCTRL_CONFIG_DEVICE_IF, &(pHandle->lcd_if_config), sizeof(LCD_IOCTRL_DEVICE_IF_T));
        hif_power_on = KAL_TRUE;
    }
    else
    {
        hif_power_on = KAL_FALSE;
        lcd_power_ctrl__disable(pHandle->power_handle);
    }
    return HIF_RESULT_OK;
}

HIF_RESULT hif_write(HIF_HANDLE handle, HIF_TYPE type, kal_uint32 addr, kal_uint32 size, HIF_CALLBACK fCB)
{
    kal_uint32 index = 0;
    HIF_RESULT result = HIF_RESULT_OK;
    HIF_INTERNAL_HANDLE_T* pHandle = (HIF_INTERNAL_HANDLE_T*) handle;
    hif_trace(HIF________WRITE, (kal_uint32)handle);
    //ASSERT(pHandle != NULL);
    if (pHandle == NULL)
        return HIF_RESULT_INVALID_HANDLE;
    //ASSERT(pHandle->user != 0);
    if (pHandle->user == 0)
        return HIF_RESULT_INVALID_HANDLE;
    //ASSERT(size != 0);
    //ASSERT((pHandle->config.hif_bus_width==8)? 1 : (size%2==0));
    if ((size == 0) || (!((pHandle->config.hif_bus_width==8)? 1 : (size%2==0))))
        return HIF_RESULT_INVALID_ARGUMENT;
    //ASSERT(hif_power_on == KAL_TRUE);
    if (hif_power_on == KAL_FALSE)
        return HIF_RESULT_HIF_NOT_POWER_ON;
    switch (type)
    {
    case HIF_TYPE_A0H_CPU:
        {
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
            // Set DMA destination address. HIF_DATA_REG
            pHandle->dma_menu.source = addr;
            pHandle->dma_menu.destination = HIF_PORT_A0_HIGH_ADDR(pHandle->port);
            pHandle->dma_input.size = (pHandle->config.hif_bus_width == 16) ? DMA_SHORT : DMA_BYTE;
            pHandle->dma_input.type = DMA_HWTX;
            pHandle->dma_input.count  = (pHandle->config.hif_bus_width == 16) ? (size >> 1) : size;
            pHandle->dma_input.callback = fCB;
            DMA_FullSize_Config(pHandle->dma_id, &(pHandle->dma_input), KAL_FALSE);
            (*(volatile  kal_uint32 *)DMA_CON(pHandle->dma_id)) &= ~DMA_CON_DRQ;
            // Start DMA
            DMA_Start(pHandle->dma_id);

            if (fCB == NULL)
                DMA_WaitUntilRdy(pHandle->dma_id);
        }
        break;
    case HIF_TYPE_A0L_CPU:
        {
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
            // Set PDMA destination address. HIF_DATA_REG
            pHandle->dma_menu.source = addr;
            pHandle->dma_menu.destination = HIF_PORT_A0_LOW_ADDR(pHandle->port);
            pHandle->dma_input.size = (pHandle->config.hif_bus_width == 16) ? DMA_SHORT : DMA_BYTE;
            pHandle->dma_input.type = DMA_HWTX;
            pHandle->dma_input.count = (pHandle->config.hif_bus_width == 16) ? (size >> 1) : size;
            pHandle->dma_input.callback = fCB;
            DMA_FullSize_Config(pHandle->dma_id, &(pHandle->dma_input), KAL_FALSE);
            (*(volatile  kal_uint32 *)DMA_CON(pHandle->dma_id)) &= ~DMA_CON_DRQ;
            // Start DMA
            DMA_Start(pHandle->dma_id);

            if (fCB == NULL)
                DMA_WaitUntilRdy(pHandle->dma_id);
        }
        break;
    default:
        //ASSERT(0);
        result = HIF_RESULT_INVALID_ARGUMENT;
        break;
    }
    return result;
}

HIF_RESULT hif_read(HIF_HANDLE handle, HIF_TYPE type, kal_uint32 addr, kal_uint32 size, HIF_CALLBACK fCB)
{
    kal_uint32 index = 0;
    HIF_RESULT result = HIF_RESULT_OK;
    HIF_INTERNAL_HANDLE_T* pHandle = (HIF_INTERNAL_HANDLE_T*) handle;
    hif_trace(HIF_________READ, (kal_uint32)handle);
    //ASSERT(pHandle != NULL);
    if (pHandle == NULL)
        return HIF_RESULT_INVALID_HANDLE;
    //ASSERT(pHandle->user != 0);
    if (pHandle->user == 0)
        return HIF_RESULT_INVALID_HANDLE;
    //ASSERT(size != 0);
    //ASSERT((pHandle->config.hif_bus_width==8)? 1 : (size%2==0));
    if ((size == 0) || (!((pHandle->config.hif_bus_width==8)? 1 : (size%2==0))))
        return HIF_RESULT_INVALID_ARGUMENT;
    //ASSERT(hif_power_on == KAL_TRUE);
    if (hif_power_on == KAL_FALSE)
        return HIF_RESULT_HIF_NOT_POWER_ON;
    switch (type)
    {
    case HIF_TYPE_A0H_CPU:
        {
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
            // Set DMA source address.
            pHandle->dma_menu.source = HIF_PORT_A0_HIGH_ADDR(pHandle->port);
            pHandle->dma_menu.destination = addr;
            pHandle->dma_input.size = (pHandle->config.hif_bus_width == 16) ? DMA_SHORT : DMA_BYTE;
            pHandle->dma_input.type = DMA_HWRX;
            pHandle->dma_input.count = (pHandle->config.hif_bus_width == 16) ? (size >> 1) : size;
            pHandle->dma_input.callback = fCB;
            DMA_FullSize_Config(pHandle->dma_id, &(pHandle->dma_input), KAL_FALSE);
            (*(volatile  kal_uint32 *)DMA_CON(pHandle->dma_id)) &= ~DMA_CON_DRQ;
            // Start DMA
            DMA_Start(pHandle->dma_id);
            if (fCB == NULL)
                DMA_WaitUntilRdy(pHandle->dma_id);
        }
        break;
    case HIF_TYPE_A0L_CPU:
        {
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
            // Set DMA source address.
            pHandle->dma_menu.source = HIF_PORT_A0_LOW_ADDR(pHandle->port);
            pHandle->dma_menu.destination = addr;
            pHandle->dma_input.size = (pHandle->config.hif_bus_width == 16) ? DMA_SHORT : DMA_BYTE;
            pHandle->dma_input.type = DMA_HWRX;
            pHandle->dma_input.count = (pHandle->config.hif_bus_width == 16) ? (size >> 1) : size;
            pHandle->dma_input.callback = fCB;
            DMA_FullSize_Config(pHandle->dma_id, &(pHandle->dma_input), KAL_FALSE);
            (*(volatile  kal_uint32 *)DMA_CON(pHandle->dma_id)) &= ~DMA_CON_DRQ;
            // Start DMA
            DMA_Start(pHandle->dma_id);
            if (fCB == NULL)
                DMA_WaitUntilRdy(pHandle->dma_id);
        }
        break;
    default:
        //ASSERT(0);
        result = HIF_RESULT_INVALID_ARGUMENT;
        break;
    }
    return result;
}

HIF_RESULT hif_ioctl(HIF_HANDLE handle, HIF_IOCTL_CODE code, void* pParam)
{
    HIF_RESULT result = HIF_RESULT_OK;
    HIF_INTERNAL_HANDLE_T* pHandle = (HIF_INTERNAL_HANDLE_T*) handle;
    hif_trace(HIF________IOCTL, (kal_uint32)handle);
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
            pTimingSupport->c2rh_support = KAL_FALSE;
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
            pColckSupport->clock[0] = 26;
            pColckSupport->clock[1] = 52;
            pColckSupport->clock[2] = 104;
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
