
#ifndef __LCD_CATCHER_LOG_H__
#define __LCD_CATCHER_LOG_H__

#include "kal_trace.h"
#include "drv_trc.h"
#include "drv_features_display.h"


#if defined(__MTK_TARGET__)
    ///Bin: enable this to profiling LCD performance
    #if !defined(__LOW_COST_SUPPORT_COMMON__) && !defined(__LOW_COST_SUPPORT_ULC__)
        #define DDV2_PERFORMANCE_PROFILING_SUPPORT
    #endif
#endif

typedef enum
{
    LAYER0 = 0  ,
    LAYER1      ,
    LAYER2      ,
    LAYER3      ,
    LAYER4      ,
    LAYER5      ,
    LAYER_TOTAL_NUMBER
}PROFILING_LCD_LAYER_ID_ENUM;

typedef enum
{
    MAIN_LCM = 0  ,
    SUB_LCM       ,
    SCREEN_TOTAL_NUMBER
}PROFILING_LCD_SCREEN_ID_ENUM;

typedef enum
{
    /* definition of LCM data outptu format */
    P_LCM_8BIT_8_BPP_RGB332_1 =   0x00,  /* RRRGGBB */
    P_LCM_8BIT_8_BPP_RGB332_2 =   0x01,  /* BBGGGRR */
    P_LCM_8BIT_12_BPP_RGB444_1 =   0x08,  /* RRRRGGGG, BBBBRRRR, GGGGBBBB */
    P_LCM_8BIT_12_BPP_RGB444_2 =   0x0B,  /* GGGGRRRR, RRRRBBBB, BBBBGGGG */
    P_LCM_8BIT_16_BPP_RGB565_1 =   0x10,  /* RRRRRGGG, GGGBBBBB */
    P_LCM_8BIT_16_BPP_RGB565_2 =   0x12,  /* GGGBBBBB, RRRRRGGG */
    P_LCM_8BIT_16_BPP_BGR565_1 =   0x11,  /* BBBBBGGG, GGGRRRRR */
    P_LCM_8BIT_16_BPP_BGR565_2 =   0x13,  /* GGGRRRRR, BBBBBGGG */
    P_LCM_8BIT_18_BPP_RGB666_1 =   0x18,  /* RRRRRRXX, GGGGGGXX, BBBBBBXX */
    P_LCM_8BIT_18_BPP_RGB666_2 =   0x1C,  /* XXRRRRRR, XXGGGGGG, XXBBBBBB */
    P_LCM_8BIT_24_BPP_RGB888_1 =   0x20,  /* RRRRRRRR, GGGGGGGG, BBBBBBBB */
    P_LCM_16BIT_8_BPP_RGB332_1 =   0x40,  /* RRRGGGBBRRRGGGBB, MSB first*/
    P_LCM_16BIT_8_BPP_RGB332_2 =   0x42,  /* RRRGGGBBRRRGGGBB, LSB first*/
    P_LCM_16BIT_8_BPP_RGB332_3 =   0x41,  /* BBGGGRRRBBGGGRRR, MSB first */
    P_LCM_16BIT_8_BPP_RGB332_4 =   0x43,  /* BBGGGRRRBBGGGRRR, LSB first */
    P_LCM_16BIT_12_BPP_RGB444_1=   0x4C,  /* XXXXRRRRGGGGBBBB */
    P_LCM_16BIT_12_BPP_RGB444_2=   0x4D,  /* XXXXBBBBGGGGRRRR */
    P_LCM_16BIT_12_BPP_RGB444_3=   0x48,  /* RRRRGGGGBBBBXXXX */
    P_LCM_16BIT_12_BPP_RGB444_4=   0x49,  /* BBBBGGGGRRRRXXXX */
    P_LCM_16BIT_16_BPP_RGB565_1=   0x50,  /* RRRRRGGGGGGBBBBB */
    P_LCM_16BIT_16_BPP_RGB565_2=   0x52,  /* GGGBBBBBRRRRRGGG */
    P_LCM_16BIT_16_BPP_BGR565_1=   0x51,  /* BBBBBGGGGGGRRRRR */
    P_LCM_16BIT_16_BPP_BGR565_2=   0x53,  /* GGGRRRRRBBBBBGGG */
    P_LCM_16BIT_18_BPP_RGB666_1=   0x5C,  /* XXXXRRRRRRGGGGGG, XXXXBBBBBBRRRRRR, XXXXGGGGGGBBBBBB */
    P_LCM_16BIT_18_BPP_RGB666_2=   0x5F,  /* XXXXGGGGGGRRRRRR, XXXXRRRRRRBBBBBB, XXXXBBBBBBGGGGGG */
    P_LCM_16BIT_18_BPP_RGB666_3=   0x58,  /* RRRRRRGGGGGGXXXX, BBBBBBRRRRRRXXXX, GGGGGGBBBBBBXXXX */
    P_LCM_16BIT_18_BPP_RGB666_4=   0x5B,  /* GGGGGGRRRRRRXXXX, RRRRRRBBBBBBXXXX, BBBBBBGGGGGGXXXX */
    P_LCM_16BIT_24_BPP_RGB888_1=   0x60,  /* RRRRRRRRGGGGGGGG, BBBBBBBBRRRRRRRR, GGGGGGGGBBBBBBBB */
    P_LCM_16BIT_24_BPP_RGB888_2=   0x63,  /* GGGGGGGGRRRRRRRR, RRRRRRRRBBBBBBBB, BBBBBBBBGGGGGGGG */
    
    P_LCM_9BIT_8_BPP_RGB332_1  =   0x80,  /* RRRGGGBBX */
    P_LCM_9BIT_8_BPP_RGB332_2  =   0x81,  /* BBGGGRRRX */
    P_LCM_9BIT_12_BPP_RGB444_1 =   0x88,  /* RRRRGGGGX, BBBBRRRRX, GGGGBBBBX */
    P_LCM_9BIT_12_BPP_RGB444_2 =   0x8B,  /* GGGGRRRRX, RRRRBBBBX, BBBBGGGGX */
    P_LCM_9BIT_16_BPP_RGB565_1 =   0x90,  /* RRRRRGGGX, GGGBBBBBX */
    P_LCM_9BIT_16_BPP_RGB565_2 =   0x93,  /* GGGRRRRRX, BBBBBGGGX */
    P_LCM_9BIT_18_BPP_RGB666_1 =   0x98,  /* RRRRRRGGG, GGGBBBBBB */
    P_LCM_9BIT_18_BPP_RGB666_2 =   0x9B,  /* GGGRRRRRR, BBBBBBGGG */
    P_LCM_9BIT_24_BPP_RGB888_1 =   0xA0,  /* RRRRRRRRX, GGGGGGGGX, BBBBBBBBX */
    P_LCM_18BIT_8_BPP_RGB332_1 =   0xC0,  /* RRRGGGBBRRRGGGBBXX, MSB first */
    P_LCM_18BIT_8_BPP_RGB332_2 =   0xC2,  /* RRRGGGBBRRRGGGBBXX, LSB first */
    P_LCM_18BIT_8_BPP_RGB332_3 =   0xC1,  /* BBGGGRRRBBGGGRRRXX, MSB first */
    P_LCM_18BIT_8_BPP_RGB332_4 =   0xC3,  /* BBGGGRRRBBGGGRRRXX, LSB first */
    P_LCM_18BIT_12_BPP_RGB444_1=   0xCC,  /* XXXXXXRRRRGGGGBBBB */
    P_LCM_18BIT_12_BPP_RGB444_2=   0xCD,  /* XXXXXXBBBBGGGGRRRR */
    P_LCM_18BIT_12_BPP_RGB444_3=   0xC8,  /* RRRRGGGGBBBBXXXXXX */
    P_LCM_18BIT_12_BPP_RGB444_4=   0xC9,  /* BBBBGGGGRRRRXXXXXX */
    P_LCM_18BIT_16_BPP_RGB565_1=   0xD0,  /* RRRRRGGGGGGBBBBBXX */
    P_LCM_18BIT_16_BPP_RGB565_2=   0xD1,  /* BBBBBGGGGGGRRRRRXX */
    P_LCM_18BIT_18_BPP_RGB666_1=   0xD8,  /* RRRRRRGGGGGGBBBBBB */
    P_LCM_18BIT_18_BPP_RGB666_2=   0xD9,  /* BBBBBBGGGGGGRRRRRR */
    P_LCM_18BIT_24_BPP_RGB888_1=   0xE0,  /* RRRRRRRRGGGGGGGGXX, BBBBBBBBRRRRRRRRXX, GGGGGGGGBBBBBBBBXX */
    P_LCM_18BIT_24_BPP_RGB888_2=   0xE3,  /* GGGGGGGGRRRRRRRRXX, RRRRRRRRBBBBBBBBXX, BBBBBBBBGGGGGGGGXX */

}PROFILING_LCM_COLOR_FORMAT_ENUM;

typedef enum {
    P_IMAGE_NOT_SUPPORTED = 0,
    P_IMAGE_ARGB8888      = 0x8888,
    P_IMAGE_XRGB8888      = 0xf888,
    P_IMAGE_RGB888        = 0x888, /**< \remark <b>[MTK]</b> R in high byte, B in low byte. */
    P_IMAGE_BGR888        = 0x1888, /**< <b>[MTK]</b> BGR color format. B in high byte and R in low byte. */
    P_IMAGE_RGB565        = 0x565,
    P_IMAGE_L32           = 0xA32,
    P_IMAGE_L16           = 0xA16,
    P_IMAGE_L8            = 0xA8,
    P_IMAGE_L1            = 0xA1,
    P_IMAGE_UYVY          = 0x422, /**< <b>[MTK]</b> UYVY color format. */
    P_IMAGE_ARGB_INTERNAL = 0x666 /**< OWFpixel rep */
} PROFILING_OWF_PIXEL_FORMAT;

typedef enum {
    FLIP_OFF               = 0,
    FLIP_ON                = 1
} PROFILING_FILP_BOOLEAN;

typedef enum {
    DITHER_OFF               = 0,
    DITHER_ON                = 1
} PROFILING_DITHER_BOOLEAN;



#define TRACE_DDV2_INFO               TRACE_INFO
#define TRACE_DDV2_WARNING            TRACE_WARNING
#define TRACE_DDV2_FUNC               TRACE_FUNC
#define TRACE_DDV2_ERROR              TRACE_ERROR
#define TRACE_DDV2_STATE              TRACE_STATE
                            
#define TRACE_DDV2_RENDERING          TRACE_GROUP_1
#define TRACE_DDV2_CONTEXTATTRIB      TRACE_GROUP_2
#define TRACE_DDV2_ELEMENTATTRIB      TRACE_GROUP_3
#define TRACE_DDV2_RESOURCEALLOCATION TRACE_GROUP_4
#define TRACE_DDV2_ELEMENTINSERTION   TRACE_GROUP_5
#define TRACE_DDV2_AUTOMODE           TRACE_GROUP_6
#define TRACE_DDV2_HWUPDATE           TRACE_GROUP_7
#define TRACE_DDV2_RESERVE1           TRACE_GROUP_8
#define TRACE_DDV2_PROFILING          TRACE_GROUP_9
#define TRACE_DDV2_HW_REGISTERS       TRACE_GROUP_10
#define TRACE_DDV2_DISPLAY_IO         TRACE_GROUP_10


#if defined(__MTK_TARGET__) && !defined(__LOW_COST_SUPPORT_COMMON__) && !defined(__LOW_COST_SUPPORT_ULC__)
    #define DDV2_CATCHERLOG_LEVEL 3 // 0: Turn off catcher log. 1: Limited log. 2: Important log. 3: Detail log.
#elif defined(__MTK_TARGET__) && (defined(__LOW_COST_SUPPORT_COMMON__) || defined(__LOW_COST_SUPPORT_ULC__))
    #define DDV2_PERFORMANCE_PROFILING_SUPPORT
    #define DDV2_CATCHERLOG_LEVEL 2 // 0: Turn off catcher log. 1: Limited log. 2: Important log. 3: Detail log.
#else
    #define DDV2_CATCHERLOG_LEVEL 0 // 0: Turn off catcher log. 1: Limited log. 2: Important log. 3: Detail log.
#endif

#if (DDV2_CATCHERLOG_LEVEL == 0)
#define DDV2CatcherLogL1(...)
#define DDV2CatcherLogL1D0(...)
#define DDV2CatcherLogL1D1(...)
#define DDV2CatcherLogL1D2(...)
#define DDV2CatcherLogL1D4(...)
#define DDV2CatcherLogL1D8(...)
#define DDV2CatcherLogL2(...)
#define DDV2CatcherLogL2D0(...)
#define DDV2CatcherLogL2D1(...)
#define DDV2CatcherLogL2D2(...)
#define DDV2CatcherLogL2D4(...)
#define DDV2CatcherLogL2D8(...)
#define DDV2CatcherLogL3(...)
#define DDV2CatcherLogL3D0(...)
#define DDV2CatcherLogL3D1(...)
#define DDV2CatcherLogL3D2(...)
#define DDV2CatcherLogL3D4(...)
#define DDV2CatcherLogL3D8(...)
#define DDV2CatcherLogException(...)
#endif

#if (DDV2_CATCHERLOG_LEVEL == 1)
// Define log with level 1
#define DDV2CatcherLogL1 kal_trace
#define DDV2CatcherLogL1D0 drv_trace0
#define DDV2CatcherLogL1D1 drv_trace1
#define DDV2CatcherLogL1D2 drv_trace2
#define DDV2CatcherLogL1D4 drv_trace4
#define DDV2CatcherLogL1D8 drv_trace8
#define DDV2CatcherLogL2(...)
#define DDV2CatcherLogL2D0(...)
#define DDV2CatcherLogL2D1(...)
#define DDV2CatcherLogL2D2(...)
#define DDV2CatcherLogL2D4(...)
#define DDV2CatcherLogL2D8(...)
#define DDV2CatcherLogL3(...)
#define DDV2CatcherLogL3D0(...)
#define DDV2CatcherLogL3D1(...)
#define DDV2CatcherLogL3D2(...)
#define DDV2CatcherLogL3D4(...)
#define DDV2CatcherLogL3D8(...)
#define DDV2CatcherLogException(...)
#endif

#if (DDV2_CATCHERLOG_LEVEL == 2)
#define DDV2CatcherLogL1 kal_trace
#define DDV2CatcherLogL1D0 drv_trace0
#define DDV2CatcherLogL1D1 drv_trace1
#define DDV2CatcherLogL1D2 drv_trace2
#define DDV2CatcherLogL1D4 drv_trace4
#define DDV2CatcherLogL1D8 drv_trace8
#define DDV2CatcherLogL2 kal_trace
#define DDV2CatcherLogL2D0 drv_trace0
#define DDV2CatcherLogL2D1 drv_trace1
#define DDV2CatcherLogL2D2 drv_trace2
#define DDV2CatcherLogL2D4 drv_trace4
#define DDV2CatcherLogL2D8 drv_trace8
#define DDV2CatcherLogL3(...)
#define DDV2CatcherLogL3D0(...)
#define DDV2CatcherLogL3D1(...)
#define DDV2CatcherLogL3D2(...)
#define DDV2CatcherLogL3D4(...)
#define DDV2CatcherLogL3D8(...)
#define DDV2CatcherLogException(...)
#endif

#if (DDV2_CATCHERLOG_LEVEL > 2)
#define DDV2CatcherLogL1 kal_trace
#define DDV2CatcherLogL1D0 drv_trace0
#define DDV2CatcherLogL1D1 drv_trace1
#define DDV2CatcherLogL1D2 drv_trace2
#define DDV2CatcherLogL1D4 drv_trace4
#define DDV2CatcherLogL1D8 drv_trace8
#define DDV2CatcherLogL2 kal_trace
#define DDV2CatcherLogL2D0 drv_trace0
#define DDV2CatcherLogL2D1 drv_trace1
#define DDV2CatcherLogL2D2 drv_trace2
#define DDV2CatcherLogL2D4 drv_trace4
#define DDV2CatcherLogL2D8 drv_trace8
#define DDV2CatcherLogL3 kal_trace
#define DDV2CatcherLogL3D0 drv_trace0
#define DDV2CatcherLogL3D1 drv_trace1
#define DDV2CatcherLogL3D2 drv_trace2
#define DDV2CatcherLogL3D4 drv_trace4
#define DDV2CatcherLogL3D8 drv_trace8
#define DDV2CatcherLogException(...) kal_assert_trace(TRACE_DDV2_HW_REGISTERS, DDV2_TRC_REGISTER_LCD_HW_REGISTERS, ##__VA_ARGS__)
#endif

typedef enum
{
    WFC_NOCALLBACK = 0,
    WFC_CALLBACK = 1
} WFCDBG_CallbackResultEnum;

typedef enum
{
    WFC_NOWAIT = 0,
    WFC_WAIT = 1
} WFCDBG_WaitEnum;

typedef enum
{
    WFC_CreateSourceFromStream = 0,
    WFC_CreateSourceFromImage,
    WFC_MMSetContextAttribi,
    WFC_MMSetContextAttribiv,
    WFC_MMSetElementAttribi,
    WFC_MMSetElementAttribiv,
    WFC_MMCommit
} WFCDBG_FunctionEnum;

typedef enum
{
    WFC_AUTONOMOUS_OFF             = 0x0, 
    WFC_AUTONOMOUS_TURNING_OFF     = 0x1, 
    WFC_AUTONOMOUS_ON              = 0x2, 
}WFCDBG_AutonomousState;

typedef enum {
    WFC_SYNC_TO_NONE             = 0x7A00,
    WFC_SYNC_TO_ELEMENT          = 0x7A01,
    WFC_SYNC_TO_VSYNC            = 0x7A02,
    WFC_SYNC_TO_TIMER            = 0x7A03,
    WFC_SYNC_FORCE_32BIT         = 0x7FFFFFFF   
} WFCDBG_SyncTrigger;

#endif
