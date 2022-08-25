/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010-2011
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
 *    wfd_lcd_6256.h
 *
 * Project:
 * --------
 *    MAUI/HAL/WFD
 *
 * Description:
 * ------------
 *    This file is the body of MT6256 LCD HW driver.
 *
 * Author:
 * -------
 * -------
 *    
 *============================================================================
 * HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * $Log$
 *
 * 04 12 2012 xiaoyong.ye
 * removed!
 * Redefine layer format ENUM with fix value.
 *
 * 03 20 2012 xiaoyong.ye
 * removed!
 * MT6250 display driver check in.
 *
 * 02 17 2012 dong.guo
 * removed!
 * .
 *
 * 01 09 2012 xiaoyong.ye
 * removed!
 * Resolve pre-build error.
 *
 * 01 06 2012 xiaoyong.ye
 * removed!
 * MT6250 LCD driver check in.
 *
 * 05 18 2011 zifeng.qiu
 * removed!
 * Event Group Slim.
 *
 * 03 08 2011 bin.han
 * removed!
 * .
 *
 * 02 21 2011 bin.han
 * removed!
 * .
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __WFD_LCD_6250_H__
#define __WFD_LCD_6250_H__

#if defined(DRV_LCD_MT6250_SERIES)
/*****************************************************************************
 *  Local macro definitions
 ****************************************************************************/

/*****************************************************************************
 *  Include directives
 ****************************************************************************/
#include "kal_release.h"
#include "drv_comm.h"
#include "drv_features_display.h"
#include "drv_sw_features_display.h"
#include "wfd\inc\wfd.h"
#include "wfd\inc\wfd_hwdevice.h"

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 *  Local type definitions
 ****************************************************************************/
typedef enum
{
   WFD_LCD_HW_EVENT_DATA_TRANSFER_COMPLETE_MTK     =   0x00000001,
   WFD_LCD_HW_EVENT_REG_LATCH_COMPLETE_MTK         =   0x00000002,
   WFD_LCD_HW_EVENT_COMMAND_TRANSFER_COMPLETE_MTK  =   0x00000004,
   WFD_LCD_HW_EVENT_HW_TRIGGER_RECIEVE_MTK         =   0x00000008,
   WFD_LCD_HW_EVENT_VSYNC_MTK                      =   0x00000010,
   WFD_LCD_HW_EVENT_TE_SIGNAL_RECEIVED_MTK         =   0x00000020,
   WFD_LCD_HW_EVENT_UNKNOWN                        =   0x00004000,
   WFD_LCD_HW_EVENT_HW_ENGIN_ALL                   =   0x0000FFFF
}  WFD_LCD_HW_EVENT_ENUM;

typedef enum
{
  WFD_LCD_LAYER_FORMAT_8BPP_INDEX = 0,
  WFD_LCD_LAYER_FORMAT_RGB565 = 1,
  WFD_LCD_LAYER_FORMAT_UYVY422 = 2,
  WFD_LCD_LAYER_FORMAT_RGB888 = 3,
  WFD_LCD_LAYER_FORMAT_ARGB8888 = 4,
  WFD_LCD_LAYER_FORMAT_PARGB8888 = 5,
  //WFD_LCD_LAYER_FORMAT_XRGB,
  WFD_LCD_LAYER_FORMAT_ARGB6666 = 7,
  WFD_LCD_LAYER_FORMAT_PARGB6666 = 8,
  WFD_LCD_LAYER_FORMAT_RSD   /*!<Reserved */
} WFD_LCD_LAYER_SOURCE_COLOR_FORMAT_ENUM;


typedef enum
{
  WFD_LCD_WMEM_COLOR_RGB565 = 0, /*!< Write to memory with RGB565 color format */  
  WFD_LCD_WMEM_COLOR_RGB888 = 1, /*!< Write to memory with RGB888 color format */
  WFD_LCD_WMEM_COLOR_ARGB8888_CONSTANT_ALPHA = 2, /*!< Write to memory with ARGB8888 color format with constant alpha value */
  WFD_LCD_WMEM_COLOR_ARGB8888_PIXEL_ALPHA = 3, /*!< Write to memory with ARGB8888 color format with per-pixel alpha value*/  
  WFD_LCD_WMEM_COLOR_PARGB6666_CONSTANT_ALPHA = 4, /*!< Write to memory with ARGB8888 color format with constant alpha value */
  WFD_LCD_WMEM_COLOR_PARGB6666_PIXEL_ALPHA = 5, /*!< Write to memory with ARGB8888 color format with per-pixel alpha value*/  
  WFD_LCD_WMEM_COLOR_RSVD  /*!<Reserved */
} WFD_LCD_WMEM_COLOR_FORMAT_ENUM;


typedef enum
{
   WFD_LCD_LAYER_ROTATE_NORMAL = 0,
   WFD_LCD_LAYER_ROTATE_90,
   WFD_LCD_LAYER_ROTATE_180,
   WFD_LCD_LAYER_ROTATE_270,
   WFD_LCD_LAYER_FLIP,
   WFD_LCD_LAYER_FLIP_ROTATE_90,
   WFD_LCD_LAYER_FLIP_ROTATE_180,
   WFD_LCD_LAYER_FLIP_ROTATE_270,
   WFD_LCD_LAYER_RSVD
}  WFD_LCD_LAYER_ROTATE_ENUM;


/*****************************************************************************
 *  Local Definitions
 ****************************************************************************/

/*!
 *  MT6256 LCD has 1 port for each LCM connected, and
 *  1 port for memory output.
 *  Each port has only one port mode in current implementation.
 *  MT6256 LCD has four pipelines since MT6256 LCD HW has only
 *  four layers.
 */
#ifdef DUAL_LCD
#define ATTACHED_LCM_CNT 2
#else
#define ATTACHED_LCM_CNT 1
#endif

/*!
 *  LCD_FLATTEN_SUPPORT: indicate if LCD driver support flatten or not.
 */ 
#define LCD_FLATTEN_SUPPORT
//DRV_LCD_MEMORY_OUTPUT
/*!
 *  WFD_ATTACHED_PORT_COUNT: indicate how many ports attached on LCD.
 */
#if defined(LCD_FLATTEN_SUPPORT)
#define WFD_ATTACHED_PORT_COUNT (ATTACHED_LCM_CNT + 1)
#else
#define WFD_ATTACHED_PORT_COUNT (ATTACHED_LCM_CNT)
#endif


/*!
 *  LCD ROI related definitions
 */
#define  WFD_LCD_ROI_MAX_WIDTH                   0x7FF
#define  WFD_LCD_ROI_MAX_HEIGHT                  0x7FF
#define  WFD_LCD_ROI_MAX_OFFSETX                 0x7FF
#define  WFD_LCD_ROI_MAX_OFFSETY                 0x7FF
#define  WFD_LCD_ROI_ORIGIN_X                    1024
#define  WFD_LCD_ROI_ORIGIN_Y                    1024

/*!
 *  LCD Layer related definitions
 */
#define  WFD_LCD_LAYER_MAX_WIDTH                 0x7FF
#define  WFD_LCD_LAYER_MAX_HEIGHT                0x7FF
#define  WFD_LCD_LAYER_MAX_OFFSETX               0x7FF
#define  WFD_LCD_LAYER_MAX_OFFSETY               0x7FF
#define  WFD_LCD_LAYER_MAX_ALPHA                 0xFF
#define  WFD_LCD_LAYER_MEM_MAX_OFFSETX           0x7FF
#define  WFD_LCD_LAYER_MEM_MAX_OFFSETY           0x7FF
#define  WFD_LCD_LAYER_MEM_MAX_PITCH             0x7FF

/*!
 *  LCD Flatten related definitions
 */
#define  WFD_LCD_MEM_OUT_MAX_MAIN_WINDOW_WIDTH   0x7FF
#define  WFD_LCD_MEM_OUT_MAX_MAIN_WINDOW_HEIGHT  0x7FF
#define  WFD_LCD_MEM_OUT_MAX_OFFSETX             0x7FF
#define  WFD_LCD_MEM_OUT_MAX_OFFSETY             0x7FF

//#define WFD_LCD_PARALLEL_INTERFACE_COUNT  3 //the definition shall be in drv_feature due to the reference by IFManager
//#define WFD_LCD_SERIAL_INTERFACE_COUNT  2
#define  WFD_LCD_PALETTE_COUNT	                DRV_PALETTE_COUNT       
#define  WFD_LCD_CMD_QUEUE_COUNT                DRV_LCD_CMD_QUEUE_COUNT       
#define  WFD_LCD_CMD_QUEUE_NUMBER               DRV_LCD_CMD_QUEUE_NUMBER

//#define WFD_LCD_BYTE_ALIGN_COUNT 4


/*!
 *  WFD LCD DRIVER RELATED DEFINITIONS
 */
#define CALLBACK_ENTRY_SIZE 4
#define CALLBACK_MAX_COUNT 10

//unit:10ms
#define WFD_LCD_TIMEOUT_INTERVAL 300
/*****************************************************************************
 *  Local variables
 ****************************************************************************/

/*****************************************************************************
 *  Local function definitions
 ****************************************************************************/ 
//Supported Event
#define IS_LCD_SUPPORTED_EVENT(event)(((event) == WFD_EVENT_VSYNC_MTK) || \
                                      ((event) == WFD_EVENT_TE_SIGNAL_RECEIVED_MTK) || \
                                      ((event) == WFD_EVENT_COMMAND_TRANSFER_COMPLETE_MTK) || \
                                      ((event) == WFD_EVENT_DATA_TRANSFER_COMPLETE_MTK))

#define CONVERT_TO_LCD_HW_BK_COLOR(A,R,G,B) ((((A)&0xFF)<<24)|(((R)&0xFF)<<16)|(((G)&0xFF)<<8)|(((B)&0xFF)))

#define ENABLE_LCD_SERIAL_IF_CS(csNum, enable)  ///TODO: should implement this??


/*!
 *  Set LCD W2MEM Pitch.
 *
 *  \param layer_order      LCD layer order (ie: ID)
 *  \param stride           Source image's stride
 *  \param bpp              Source image's byte per pixel
 *
 *  \remark                 For those chips not supported layer pitch,
 *                          please let this macro as null.
 *
 */
#define SET_LCD_W2MEM_PITCH(stride, bpp)\
{\
  DRV_WriteReg32(LCD_ROI_WMEM_PITCH_REG,(stride));\
}

#define WFD_LCD_DBG_SUPPORT
//#define LCD_V1_ADP_DBG_SUPPORT

/*****************************************************************************
 *  API function definitions
 ****************************************************************************/
//extern WFDErrorCode wfd_lcd_6256_initialize(
//    WFDHWDevicePrimitivesMTK **pDevicePrimitives);



////////////////////


#ifdef __cplusplus
}
#endif

#endif  // #if defined(DRV_LCD_MT6250_SERIES)

#endif  // #ifndef __WFD_LCD_6256_H__

