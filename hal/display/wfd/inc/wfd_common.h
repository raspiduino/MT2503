/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001-2007
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


/*******************************************************************************
 * Filename:
 * ---------
 * wfd_lcd_internal.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * ------- 
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 27 2012 joey.pan
 * removed!
 * Fix sub_lcd cannot sleep in issue.
 *
 * 07 17 2012 haitao.shang
 * removed!
 * .
 *
 * 02 23 2012 yinli.liang
 * removed!
 * .
 *
 * 02 10 2012 haitao.shang
 * removed!
 * .
 *
 * 08 12 2011 bin.han
 * removed!
 * .
 *
 * 08 12 2011 bin.han
 * removed!
 * .
 *
 * 07 12 2011 zifeng.qiu
 * removed!
 * .
 *
 * 06 08 2011 bin.han
 * removed!
 * .
 *
 * 06 02 2011 matthew.chen
 * removed!
 * Check in slim-ed DDv2 to Maui
 *
 * 05 11 2011 zifeng.qiu
 * removed!
 * Resolve lcd_sleep_in & out racing condition.
 *
 * 05 11 2011 bin.han
 * removed!
 * .
 *
 * 04 21 2011 bin.han
 * removed!
 * .
 *
 * 04 21 2011 bin.han
 * removed!
 * .6268 SLIM code check in
 *
 * 04 18 2011 zifeng.qiu
 * removed!
 * .
 *
 * 03 11 2011 sophie.chen
 * removed!
 * .
 *
 * 03 07 2011 chelun.tsai
 * removed!
 * wfd header move to hal.
 *
 * 03 07 2011 marvin.tsai
 * removed!
 * .
 *
 * 03 06 2011 chelun.tsai
 * removed!
 * _wfd_CheckPipelineSourceOffset.
 *
 * 03 03 2011 chelun.tsai
 * removed!
 * .
 *
 * 03 02 2011 sophie.chen
 * removed!
 * .
 *
 * 02 10 2011 chelun.tsai
 * removed!
 * modify drv_features.h include.
 *
 * 01 21 2011 sophie.chen
 * removed!
 * .
 *
 * 12 27 2010 chelun.tsai
 * removed!
 * .
 *
 * 12 22 2010 sophie.chen
 * removed!
 * .
 *
 * 11 23 2010 sophie.chen
 * removed!
 * .
 *
 * 11 18 2010 sophie.chen
 * removed!
 * .
 *
 * 11 15 2010 sophie.chen
 * removed!
 * .
 *
 *******************************************************************************/
 
#ifndef __WFD_LCD_COMMON_H__
#define __WFD_LCD_COMMON_H__


/*****************************************************************************
 *  Local macro definitions
 ****************************************************************************/

/*****************************************************************************
 *  Include directives
 ****************************************************************************/
#include "drv_comm.h"
//#include "drv_hisr.h"
#include "wfd\inc\wfd_hwdevice.h"
#include "wfd\inc\wfd.h"
#include "wfd\inc\wfdplatform.h"
//#include "mm_power_ctrl.h"
#include "drv_features_display.h"
#include "drv_sw_features_display.h"
#include "reg_base.h"
//#include "intrCtrl.h"
#include "kal_release.h"
#include "lcd_if.h"
#include "lcm_if.h"
//#include "lcd_sw.h"
//#include "lcd_sw_inc.h"
#include "common/owftypes.h"
#include "common/owfimage.h"
#include "lcd_tear_manager\inc\lcd_tear_manager.h"
#include "lcd_if_manager.h"

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 *  External symbols
 ****************************************************************************/
typedef enum
{
   RECT_OFFSETX = 0,
   RECT_OFFSETY,
   RECT_WIDTH,
   RECT_HEIGHT,
   RECT_RSD   
}RECT_INDEX_ENUM;

typedef enum
{
   CB_FUNC_PTR = 0,
   CB_PARA,
   
   CB_MAX_NUMBER
}CALLBACK_INDEX_ENUM;
/*****************************************************************************
 *  Local type definitions
 ****************************************************************************/
// TODO: consider to move all these typedefs to a common header for WFD internal use...but it might need to be extended for different HWs...
// TODO: We mark off what we don't need currently...

typedef struct WFD_DEVICE_              WFD_DEVICE;
typedef struct WFD_PIPELINE_            WFD_PIPELINE;
typedef struct WFD_PORT_                WFD_PORT;

typedef struct
{
  WFDboolean       _ifOnScreen;
  
  WFDuint          _ifUser;
  WFDuint          _ifType;
  WFDint           _ifCs;
  WFDuint          _ifCmdPort;
  WFDuint          _ifDataPort;
  WFDuint          _ifOutFormat;
  WFDuint          _ifCmdQueueIdx;    
  LCD_Funcs*       _ifFuncTable;  
}WFDLCDInterfacePara;


/*! Port attributes defined by OpenWF display specification.
 *
 */
typedef struct WFD_PORT_CONFIG_
{
    WFDint            id;
    WFDPortType       type;
    WFDint            nativeResolution[2];
    WFDint            physicalSize[2];
    WFDint            backgroundColor[4]; // for [0]A/[1]R/[2]G/[3]B channel; 
    WFDboolean        flip;
    WFDboolean        mirror;
    WFDint            rotation; //clockwise 0/90/180/270
    //WFDboolean        use_hw_rot;
    WFDPowerMode      powerMode;
    WFDPowerMode      powerModeBackup;
    //WFDfloat          gammaRange[2];
    //WFDfloat          gamma;
    WFDPartialRefresh partialRefreshSupport;
    //WFDint            partialRefreshMaximum[2];
    //WFDPartialRefresh partialRefreshEnable;
    WFDint            partialRefreshRectangle[4]; //target's offsetx, offsety, width, height

    WFDint            roiDestRectangle[4];        //ROI's offsetx, offsety, width, height

    WFDboolean        bindedPipelines[DRV_LAYER_TOTAL_COUNT]; //mtk: used to keep which pipelines will be enabled.
    
    //WFDboolean        protectionEnable;


    /*! current port mode, all read-only*/
    WFDint            portWidth;        ///UI width and height
    WFDint            portHeight;
    WFDint            refreshRate;
    WFDSyncModeMTK    syncMode;
    WFDint            ppi;              ///pixels per inch
    WFDint			  portTearFreeRefreshRate; //1te(1te-mode) or 1te+hwRefreshTime(theory evaluate use full screen) ( 1-2te-mode),only used for blt , unit:fps
    
	WFDTearControlModeMTK tearControlMode;

    WFDboolean        syncEnable;       /**< WFD_TRUE to enable sync, If there is no sync mechanism provided, this is N/A. */
    WFDboolean        blockModeReq;     /**< WFD_TRUE for a blocking request. WFD_FALSE for a non-blocking request. */
    WFDuint           updateDoneCallback[CB_MAX_NUMBER];    //0:pointer, 1:parameter
    WFDboolean        doBlt;            /**< WFD_TRUE to mean do blt to LCM. */

    OWF_IMAGE*        targetImage; //for GOVL
    WFDuint           paletteTable; ///global palette table buffer address
} WFD_PORT_CONFIG;

struct WFD_PORT_
{
    /*! backpointer to device */
    WFD_DEVICE*         device;

    WFD_PORT_CONFIG     config;

    /*! internal screen number for the SI */
    WFDint              screenNumber;

    //Privite data
    WFDuint             portOutputFormat;
    LCD_Funcs          *portFuncTable;      //mtk
    WFDuint             portDataAddr;
    WFDuint             portCmdAddr;
    WFDuint             cmdQueueIdx;        //which CmdQ

	WFDuint				hwRefreshTime;		//Yinli: record hw refresh time,only used for sync-to-element frame-insertion mechnism currently, unit: tick by 32.768kHz
    //Tear sync primitivies
    LCDTearSyncModePrimitives portSyncPrimitives;

    WFDboolean          TEDetectionFail;    // only valid for LCM
    WFDboolean          needToDetectTE;     // only valid for LCM
    WFDboolean			isTEsyncMode;		//Yinli: in te-control mode,only valid for LCM
};

/*! Pipeline attributes defined by OpenWF display specification.
 *
 */
typedef struct WFD_PIPELINE_CONFIG_
{
    WFDuint             id;                 //keep ID in order to know it is which layer
    WFDPort             portId;
    WFDint              maxSourceSize[2];
    WFDint              sourceRectangle[4]; //mem_offsetx, mem_offsety, width, height
    WFDboolean          swapEnable;         //?????
    WFDboolean          flip;
    WFDboolean          mirror;
    WFDint              rotation;                // clockwise 0/90/180/270

    WFDint              destinationRectangle[4]; //roi_offsetx, roi_offsety, width, height
    WFDuint             transparencyEnable;      //WFDTransparency
    WFDuint             transparencyColor;       //Add

    WFDint              globalAlpha;
    WFDboolean          ditherEnable;            //Add
    WFDboolean          dcEnable;
    WFDboolean          FastRotatorEnable;

    OWF_IMAGE*              image_source;
#ifdef DRV_LCD_3D_MODE_SUPPORT
	WFDboolean          _3DEnable;				//true:enable 3D, false:disable 3D
	WFDboolean          _3DPortraitMode;			//true:portrait Mode, false:landscape mode
	WFDboolean          _3DLeftEyeFirst;			//true:left eye show first, false:right eye show first
	//WFDboolean          _3DStartAddrForLeft;		//true:the left or top part of 3D buffer is  for left eye, false:the left or top part of 3D buffer is  for right eye
#endif
} WFD_PIPELINE_CONFIG;


struct WFD_PIPELINE_
{
    /*! backpointer to device */
    WFD_DEVICE*             device;
    /*! hardware configuration area */
    WFD_PIPELINE_CONFIG     config;
};

typedef struct WFD_DEVICE_CONFIG_
{
    WFDboolean            enableFastRotatorMem;
} WFD_DEVICE_CONFIG;


/*****************************************************************************
 *  Type definitions
 ****************************************************************************/
/**
 *  To implement one WFD device in MTK MAUI, one WFDHWDevicePrimitivesMTK must be 
 *  provided.
 *  \remark We don't support float type and Mask
 */
typedef struct 
{
  WFDDevice     (*wfdCreateDevice)(WFDint deviceId, const WFDint *attribList);
  WFDErrorCode  (*wfdDestroyDevice)(WFDDevice device);
  void          (*wfdDeviceCommit)(WFDDevice device, WFDCommitType type, WFDHandle handle);
} WFDHWDevicePrimitivesMTK;


typedef struct 
{
  void          (*_wfd_PowerCtrl)(WFD_DEVICE* device, WFDuint handle, WFDboolean enable);
  WFDuint       (*_wfd_CnvtImgFormatToHwDef)(OWF_IMAGE_FORMAT *format);
  WFDuint       (*_wfd_CnvtEventToHWDef)(WFDEventType event_type);
  WFDuint       (*_wfd_CnvtW2memFormatToHwDef)(OWF_IMAGE_FORMAT *format);
  WFDuint       (*_wfd_CnvtAngleToHwDef)(WFD_DEVICE* device, WFDint angle, WFDboolean flip);
  WFDint        (*_wfd_GetIFPara)(WFDLCDInterfacePara *device_if, WFDint ifNum);
  WFDboolean    (*_wfd_Blt)(WFD_DEVICE* device, WFD_PORT* port, WFDEventType event);
  WFDboolean    (*_wfd_PipelineCommit)(WFD_DEVICE* device, WFD_PIPELINE* pipeline);
  WFDboolean    (*_wfd_ConfigMemOut)(WFD_DEVICE* device, WFD_PORT* port);
  WFDboolean    (*_wfd_FastRotatorMemEnable)(WFDboolean enable);

  void          (*_wfd_ConfigPerformancePara)(WFD_PORT* port, LCD_IOCTRL_DEVICE_IF_T* if_mgr_setting);
} WFDHWDeviceInternalUtilityMTK;


struct WFD_DEVICE_
{
    ///Bin: must pay attenation to the following order
    WFDHWDevicePrimitivesMTK      primitivesTable;  
    WFDHWDeviceInternalUtilityMTK utilityTable;     
    WFDErrorCode          lastUnreadError;
    WFDboolean            busyFlag;
    /*! A pointer to current device object, NULL if device is  unallocated */
    WFD_DEVICE*           inUse;
    /*! Device id */
    WFDint                id;
    WFD_DEVICE_CONFIG     config;    
    //Ports
    WFD_PORT              *ports;
    WFDuint               portCount;
    //Pipelines
    WFD_PIPELINE          *pipelines;
    WFDuint               pipelineCount;
};


typedef enum
{ WFD_HANDLE_DEVICE                  = 0x0,
  WFD_HANDLE_PORT                    = 0x1,
  WFD_HANDLE_PIPELINE                = 0x2,
  WFD_HANDLE_FORCE_32BIT             = 0x7FFFFFFF
} WFDHandleType;


typedef enum
{
    WFD_PORT_MAIN_LCD   = 0,
    WFD_PORT_SUB_LCD    = 1,
    WFD_PORT_MEM_OUT    = 2

} WFD_PORT_TYPE_ENUM;


#define WFD_ASSERT_CHECK(d, c, errorcode, retval)       ASSERT(c);
#define WFD_ASSERT_CHECK_NR(d, c, errorcode, retval)    ASSERT(c);

extern void LCD_FunConfig(void);

kal_bool LCD_Physical_Interface_Lock(void);
kal_bool LCD_Physical_Interface_Unlock(void);



#ifdef __cplusplus
}
#endif

#endif //__WFD_LCD_COMMON_H__
