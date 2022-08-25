#ifndef __HIF_V1_INTERNAL_H__
#define __HIF_V1_INTERNAL_H__

#include "drv_features.h"
#include "kal_release.h"
#include "reg_base.h"

#if defined(DRV_HIF_V1) && defined(DRV_HIF_SUPPORT)

#define HIF_MAX_PORT_NUM 2

#define HIF_PORT_A0_LOW_ADDR(n)         (LCD_base+0x1000+n*0x1000)
#define HIF_PORT_A0_HIGH_ADDR(n)        (LCD_base+0x1100+n*0x1000)

#define HIF_TIMING_CONFIG_REG(n)        (LCD_base+0x0030+n*4)
#define HIF_LCD_PDW_REG                 (LCD_base+0x003C)
#define HIF_TIMING_CONFIG_WRITE_WAIT_STATE_MASK         0x3F
#define HIF_TIMING_CONFIG_WRITE_SETUP_TIME_MASK         0xF00
#define HIF_TIMING_CONFIG_WRITE_HOLD_TIME_MASK          0x3000
#define HIF_TIMING_CONFIG_READ_LATENCY_TIME_MASK        0x3F0000
#define HIF_TIMING_CONFIG_READ_SETUP_TIME_MASK          0xF000000
#define HIF_TIMING_CONFIG_READ_HOLD_TIME_MASK           0x30000000
#define HIF_TIMING_CONFIG_WRITE_WAIT_STATE_OFFSET       0
#define HIF_TIMING_CONFIG_WRITE_SETUP_TIME_OFFSET       8
#define HIF_TIMING_CONFIG_WRITE_HOLD_TIME_OFFSET        12
#define HIF_TIMING_CONFIG_READ_LATENCY_TIME_OFFSET      16
#define HIF_TIMING_CONFIG_READ_SETUP_TIME_OFFSET        24
#define HIF_TIMING_CONFIG_READ_HOLD_TIME_OFFSET         28
#define HIF_LCD_BUS_WIDTH_MASK(n)                       (0x7<<(n*4))
#define HIF_LCD_BUS_WIDTH_OFFSET(n)                     (n*4)

//Define MMSYS1 power
#define MM1_SYS_PWR_ACK         0x100000
#define RM_PWR_CON_FOR_HIF           (0x70022000+0x810)//((volatile kal_uint32*)(0x70022000+0x810))  //TOPSM_base+0x810
#define RM_PWR_STA_FOR_HIF           (0x70022000+0x820)//((volatile kal_uint32*)(0x70022000+0x820))  //TOPSM_base+0x820
#define APHW_VER_FOR_HIF             (0x70026000)//((volatile kal_uint32*)0x70026000)  //TOPSM_base+0x820
#define AP_SAPD_WAYEN_FOR_HIF        (0x700260B0)//((volatile kal_uint32*)0x700260B0)  //TOPSM_base+0x820
#define TOPSM_DMY0_FOR_HIF           (0x70026060)//((volatile kal_uint32*)0x70026060)  //TOPSM_base+0x820

// Define HIF registers
#define HIF_STA_REG             (HIF_base+0x0)
#define HIF_INTEN_REG           (HIF_base+0x4)
#define HIF_INSTA_REG           (HIF_base+0x8)
#define HIF_START_REG           (HIF_base+0xC)
#define HIF_SWRST_REG           (HIF_base+0x10)
#define HIF_CON_REG             (HIF_base+0x20)
#define HIF_DAMOUNT_REG         (HIF_base+0x24)
#define HIF_DATA_REG            (HIF_base+0x30)
#define HIF_DCNT_REG            (HIF_base+0x40)

#define HIF_BUSY_MASK           0x00000001
#define HIF_CPL_MASK            0x00000001
#define HIF_START_MASK          0x00000001
#define HIF_RST_MASK            0x00000001
#define HIF_HIFW_MASK           0x00000003
#define HIF_WRITE_MASK          0x00000004
#define HIF_A0_MASK             0x00000008
#define HIF_CS_MASK             0x00000010
#define HIF_DMA_SEL_MASK        0x00000020

#define HIF_HIFW_OFFSET         0
#define HIF_WRITE_OFFSET        2
#define HIF_A0_OFFSET           3
#define HIF_CS_OFFSET           4
#define HIF_DMA_SEL_OFFSET      5

#define SET_HIF_CE2WR_SETUP_TIME(n, val)        (*(volatile kal_uint32*)HIF_TIMING_CONFIG_REG(n)) &= ~HIF_TIMING_CONFIG_WRITE_SETUP_TIME_MASK;\
                                                (*(volatile kal_uint32*)HIF_TIMING_CONFIG_REG(n)) |= (val)<<HIF_TIMING_CONFIG_WRITE_SETUP_TIME_OFFSET;
#define SET_HIF_CE2WR_HOLD_TIME(n, val)         (*(volatile kal_uint32*)HIF_TIMING_CONFIG_REG(n)) &= ~HIF_TIMING_CONFIG_WRITE_HOLD_TIME_MASK;\
                                                (*(volatile kal_uint32*)HIF_TIMING_CONFIG_REG(n)) |= (val)<<HIF_TIMING_CONFIG_WRITE_HOLD_TIME_OFFSET;
#define SET_HIF_CE2RD_SETUP_TIME(n, val)        (*(volatile kal_uint32*)HIF_TIMING_CONFIG_REG(n)) &= ~HIF_TIMING_CONFIG_READ_SETUP_TIME_MASK;\
                                                (*(volatile kal_uint32*)HIF_TIMING_CONFIG_REG(n)) |= (val)<<HIF_TIMING_CONFIG_READ_SETUP_TIME_OFFSET;
#define SET_HIF_CE2RD_HOLD_TIME(n, val)         (*(volatile kal_uint32*)HIF_TIMING_CONFIG_REG(n)) &= ~HIF_TIMING_CONFIG_READ_HOLD_TIME_MASK;\
                                                (*(volatile kal_uint32*)HIF_TIMING_CONFIG_REG(n)) |= (val)<<HIF_TIMING_CONFIG_READ_HOLD_TIME_OFFSET;
#define SET_HIF_WRITE_WAIT_STATE(n, val)        (*(volatile kal_uint32*)HIF_TIMING_CONFIG_REG(n)) &= ~HIF_TIMING_CONFIG_WRITE_WAIT_STATE_MASK;\
                                                (*(volatile kal_uint32*)HIF_TIMING_CONFIG_REG(n)) |= (val)<<HIF_TIMING_CONFIG_WRITE_WAIT_STATE_OFFSET;
#define SET_HIF_READ_LATENCY_TIME(n, val)       (*(volatile kal_uint32*)HIF_TIMING_CONFIG_REG(n)) &= ~HIF_TIMING_CONFIG_READ_LATENCY_TIME_MASK;\
                                                (*(volatile kal_uint32*)HIF_TIMING_CONFIG_REG(n)) |= (val)<<HIF_TIMING_CONFIG_READ_LATENCY_TIME_OFFSET;
#define SET_HIF_LCD_8BIT_DATA_BUS(n)            (*(volatile kal_uint32*)HIF_LCD_PDW_REG) &= ~HIF_LCD_BUS_WIDTH_MASK(n);
#define SET_HIF_LCD_16BIT_DATA_BUS(n)           (*(volatile kal_uint32*)HIF_LCD_PDW_REG) &= ~HIF_LCD_BUS_WIDTH_MASK(n);\
                                                (*(volatile kal_uint32*)HIF_LCD_PDW_REG) |= 2<<HIF_LCD_BUS_WIDTH_OFFSET(n);

#define SET_HIF_BUS_WIDTH(val)                  (*(volatile kal_uint32*)HIF_CON_REG) &= ~HIF_HIFW_MASK;\
                                                (*(volatile kal_uint32*)HIF_CON_REG) |= (val/8-1)<<HIF_HIFW_OFFSET;
#define SET_HIF_WRITE                           (*(volatile kal_uint32*)HIF_CON_REG) &= ~HIF_WRITE_MASK;\
                                                (*(volatile kal_uint32*)HIF_CON_REG) |= 1<<HIF_WRITE_OFFSET;
#define SET_HIF_READ                            (*(volatile kal_uint32*)HIF_CON_REG) &= ~HIF_WRITE_MASK;\
                                                (*(volatile kal_uint32*)HIF_CON_REG) |= 0<<HIF_WRITE_OFFSET;
#define SET_HIF_A0_HIGH                         (*(volatile kal_uint32*)HIF_CON_REG) &= ~HIF_A0_MASK;\
                                                (*(volatile kal_uint32*)HIF_CON_REG) |= 1<<HIF_A0_OFFSET;
#define SET_HIF_A0_LOW                          (*(volatile kal_uint32*)HIF_CON_REG) &= ~HIF_A0_MASK;\
                                                (*(volatile kal_uint32*)HIF_CON_REG) |= 0<<HIF_A0_OFFSET;
#define SET_HIF_CS(port)                        (*(volatile kal_uint32*)HIF_CON_REG) &= ~HIF_CS_MASK;\
                                                (*(volatile kal_uint32*)HIF_CON_REG) |= (port-1)<<HIF_CS_OFFSET;
#define SET_HIF_DAMOUNT(val)                    (*(volatile kal_uint32*)HIF_DAMOUNT_REG) = (val) - 1;

#define ENABLE_HIF_INTR                         (*(volatile kal_uint32*)HIF_INTEN_REG) = 1;
#define DISABLE_HIF_INTR                        (*(volatile kal_uint32*)HIF_INTEN_REG) = 0;

#define START_HIF                               (*(volatile kal_uint32*)HIF_START_REG) = 0;\
                                                (*(volatile kal_uint32*)HIF_START_REG) = 1;
#define HIF_BUSY                                ((*(volatile kal_uint32*)HIF_STA_REG) & HIF_BUSY_MASK)
#define HIF_SET_AP_DMA                          (*(volatile kal_uint32*)HIF_CON_REG) &= ~HIF_DMA_SEL_MASK;
#define HIF_SET_MD_DMA                          (*(volatile kal_uint32*)HIF_CON_REG) &= ~HIF_DMA_SEL_MASK;\
                                                (*(volatile kal_uint32*)HIF_CON_REG) |= 1<<HIF_DMA_SEL_OFFSET;
#define HIF_INT_CLEAR                           do {volatile kal_uint32 hif_insta = (*(volatile kal_uint32*)HIF_INSTA_REG));} while(0);

typedef struct
{
    kal_uint32 port;
    kal_uint32 user;
    HIF_CONFIG_T config;
} HIF_INTERNAL_HANDLE_T;

// HIF internal functions
void hif_lisr(void);
void hif_hisr(void);
void hif_wait_for_idle(void);

#endif
#endif
