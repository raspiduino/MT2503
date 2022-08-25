#ifndef __HIF_LEGACY_INTERNAL_H__
#define __HIF_LEGACY_INTERNAL_H__

#include "drv_features.h"
#include "kal_release.h"
#include "reg_base.h"
#include "lcd_if_hw.h"
#include "dma_sw.h"
#include "dma_hw.h"
#include "lcd_if_manager.h"

#if defined(DRV_HIF_LEGACY) && defined(DRV_HIF_SUPPORT)

#define HIF_MAX_PORT_NUM 2

#define HIF_PORT_A0_LOW_ADDR(n)         (LCD_PARALLEL0_A0_LOW_ADDR+n*0x1000)
#define HIF_PORT_A0_HIGH_ADDR(n)        (LCD_PARALLEL0_A0_HIGH_ADDR+n*0x1000)

#define Gen_LCD_PARALLEL_IF_TIMING(in, clk, bus_width, Whold, Wsetup, Wwait_state, Rhold, Rsetup, Rlatency)\
   {                                                        \
        in &= ~LCD_PARALLEL_CONFIG_CE2WR_HOLD_TIME_MASK;\
        in |= ((Whold) << 28);\
        in &= ~LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_MASK;\
        in |= ((Wsetup) << 30);\
        in &= ~LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_MASK;\
        in |= ((Wwait_state) << 8);\
        in &= ~LCD_PARALLEL_CONFIG_CE2RD_SETUP_TIME_MASK;\
        in |= ((Rsetup) << 24);\
        in &= ~LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_MASK;\
        in |= ((Rlatency));\
        in &= ~LCD_PARALLEL_BUS_WIDTH_MASK;\
        in |= ((bus_width) << 16);\
        in &= ~LCD_PARALLEL_CLOCK_RATE_MASK;\
        in |= ((clk) << 14);\
   }\

typedef struct
{
    kal_uint32 port;
    kal_uint32 user;
    kal_uint32 power_handle;
    kal_uint32 if_handle;
    DMA_INPUT dma_input;
    DMA_FULLSIZE_HWMENU  dma_menu;
    kal_uint8 dma_id;
    HIF_CONFIG_T config;
    LCD_IOCTRL_DEVICE_IF_T lcd_if_config;
} HIF_INTERNAL_HANDLE_T;

// HIF internal functions
void hif_lisr(void);
void hif_hisr(void);
void hif_wait_for_idle(void);

#endif
#endif