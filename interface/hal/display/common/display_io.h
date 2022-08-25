#ifndef __DISPLAY_IO_H__
#define __DISPLAY_IO_H__

#include "kal_release.h"
#include "drv_features_display.h"

typedef enum
{
    DISPLAY_RESULT_OK = 0,
    DISPLAY_RESULT_INVALID_CODE, /* The input control code is invalid. */
    DISPLAY_RESULT_INVALID_DATA, /* The input data is invalid. */
    DISPLAY_RESULT_LCM_SLEEP_IN, /* This error will be returned when calling LCM operation when LCM is sleep in. */
    DISPLAY_RESULT_CONTROL_FAIL  /* For other errors. */
} DisplayResultEnum;

typedef enum
{
    DISPLAY_IOCTL_INVALID = 0,
    DISPLAY_IOCTL_SEPARATOR_USE_LCDCLK_S,/* ========================= */
    DISPLAY_IOCTL_GET_SCREEN_INFO,
    DISPLAY_IOCTL_GET_FRAMEBUFFER_ADDRESS,
    DISPLAY_IOCTL_SEPARATOR_USE_LCDIF_S, /* ========================= */
    /* CABC Features */
    DISPLAY_IOCTL_CABC_QUERY_SUPPORT,
    DISPLAY_IOCTL_CABC_SET_MODE,
    DISPLAY_IOCTL_CABC_GET_MODE,
    DISPLAY_IOCTL_CABC_SET_BRIGHTNESS,
    /* LCM Settings */
    DISPLAY_IOCTL_LCM_SET_ROTATE,
    DISPLAY_IOCTL_LCM_SET_TEMP_COMPENSATE,
    DISPLAY_IOCTL_LCM_SET_LINERATE,
    DISPLAY_IOCTL_LCM_SET_CONTRAST,
    DISPLAY_IOCTL_LCM_SET_BIAS,
    DISPLAY_IOCTL_LCM_SET_POWER,
    DISPLAY_IOCTL_LCM_SET_PARTIAL_DISPLAY,
    DISPLAY_IOCTL_LCM_GET_PARTIAL_DISPLAY,
    DISPLAY_IOCTL_LCM_SET_BRIGHT_LEVEL,
#ifdef DRV_LCD_3D_MODE_SUPPORT
	DISPLAY_IOCTL_LCM_SET_3D_MODE,
#endif
    /*ESD Check Feature*/
    DISPLAY_IOCTL_ESD_CHECK,
    DISPLAY_IOCTL_ESD_RESET,
    
    DISPLAY_IOCTL_SEPARATOR_USE_LCDIF_E,/* ========================= */
    DISPLAY_IOCTL_SEPARATOR_USE_LCDCLK_E,/* ========================= */
} DisplayCtrlCode;

typedef enum
{
    DISPLAY_INVALID_DEVICE = 0,
    DISPLAY_LCM0,
    DISPLAY_LCM1
} DisplayDeviceEnum;
#ifdef DRV_LCD_3D_MODE_SUPPORT
typedef enum
{
    DISPLAY_3D_MODE_OFF = 0,
    DISPLAY_3D_MODE_PORTRAIT,
    DISPLAY_3D_MODE_LANDSCAPE,
    DISPLAY_3D_MODE_INVALID
} Display3DModeEnum;

typedef struct
{
    Display3DModeEnum mode;
	//for expend in the future
} Display3DMode_T;
#endif

typedef enum
{
    DISPLAY_CABC_MODE_OFF = 0,
    DISPLAY_CABC_MODE_UI,
    DISPLAY_CABC_MODE_STILL,
    DISPLAY_CABC_MODE_MOVING,
    DISPLAY_CABC_MODE_INVALID
} DisplayCABCModeEnum;

/* DisplayCABC_T structure definition.
   DISPLAY_IOCTL_CABC_QUERY_SUPPORT: [Input]: lcm_id       [Output]: bSupport [Ignored]: mode
   DISPLAY_IOCTL_CABC_SET_MODE:      [Input]: lcm_id, mode                    [Ignored]: bSupport
   DISPLAY_IOCTL_CABC_GET_MODE:      [Input]: lcm_id       [Output]: mode     [Ignored]: bSupport
*/
typedef struct
{
    kal_bool bSupport;
    DisplayCABCModeEnum mode;
} DisplayCABC_T;

typedef struct  
{
    kal_uint8 duty_value;
} DisplayCABCBrightness_T;

typedef struct  
{
    kal_uint8 rotate_value;
} DisplayLCMRotate_T;

typedef struct  
{
    kal_uint32 screen_width;
    kal_uint32 screen_height;
    kal_uint32 color_depth;
} DisplayGetScreenInfo_T;

typedef struct  
{
    kal_uint8 compensate;
} DisplayLCMTempCompensate_T;

typedef struct  
{
    kal_uint8 linerate;
} DisplayLCMLineRate_T;

typedef struct  
{
    kal_uint8 contrast;
} DisplayLCMContrast_T;

typedef struct  
{
    kal_uint8 bias;
} DisplayLCMBias_T;

typedef struct  
{
    kal_bool bPowerOn;
} DisplayLCMPower_T;

typedef struct  
{
    // For partial display configure.
    kal_bool bPartialOn;
    kal_uint16 start_line;
    kal_uint16 end_line;
    // For querying partial display parameter.
    kal_uint8 alignment;
} DisplayLCMPartialDisplay_T;

typedef struct  
{
    kal_uint8 bright_level;
} DisplayLCMBrightLevel_T;

typedef struct  
{
    kal_uint32 address;
} DisplayFrameBufferAddress_T;

/*ESD Check Feature*/
typedef struct
{
    kal_bool bEsdHappened;
} LcdEsdCheck_T;

DisplayResultEnum DisplayIOControl(DisplayDeviceEnum device, DisplayCtrlCode code, void* pData);

#endif /* __DISPLAY_IO_H__ */