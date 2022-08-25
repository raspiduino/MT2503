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
 *    wfd_lcd_adapter.c
 *
 * Project:
 * --------
 *    MAUI/HAL/WFD
 *
 * Description:
 * ------------
 *    .............................
 *    This file is only for target.
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
 * 06 06 2014 edwardyc.lin
 * removed!
 * 	.
 *
 * 02 26 2014 edwardyc.lin
 * removed!
 * 	.
 *
 * 01 21 2014 edwardyc.lin
 * removed!
 *
 * 12 31 2013 edwardyc.lin
 * removed!
 *
 * 12 31 2013 ting.wang
 * removed!
 * IOT code check in on 11C trunk.
 *
 * 10 14 2013 chrono.wu
 * removed!
 * .
 *
 * 11 12 2012 joey.pan
 * removed!
 * Fix MT6260 LCD build error.
 *
 * 07 18 2012 haitao.shang
 * removed!
 * .
 *
 * 05 31 2012 haitao.shang
 * removed!
 * .
 *
 * 10 20 2011 xiaoyong.ye
 * removed!
 * .
 *
 * 09 23 2011 haitao.shang
 * removed!
 * .
 *
 * 08 25 2011 bin.han
 * removed!
 * .
 *
 * 08 18 2011 bin.han
 * removed!
 * .
 *
 * 08 04 2011 bin.han
 * removed!
 * .
 *
 * 07 21 2011 tianshu.qiu
 * removed!
 * .
 *
 * 07 12 2011 tianshu.qiu
 * removed!
 * .
 *
 * 07 12 2011 zifeng.qiu
 * removed!
 * .
 *
 * 07 06 2011 bin.han
 * removed!
 * .
 *
 * 06 26 2011 tianshu.qiu
 * removed!
 * Remove L UI and adapter option wrapped code.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(__MTK_TARGET__)
/*****************************************************************************
 *  Local macro definitions
 ****************************************************************************/

/*****************************************************************************
 *  Include directives
 ****************************************************************************/
#include "drv_comm.h"
#include "drv_hisr.h"
#include "wfd\inc\wfd_hwdevice.h"
#include "wfd\inc\wfd_lcd_chip_select.h"
#include "wfd\inc\wfd.h"
#include "wfd\inc\wfdplatform.h"
#include "wfd\inc\wfd_common.h"
#include "mm_power_ctrl.h"
#include "drv_features_display.h"
#include "drv_sw_features_display.h"
#include "reg_base.h"
#include "intrCtrl.h"
#include "kal_release.h"
#include "lcd_if.h"
#include "lcm_if.h"
#include "lcd_sw.h"
#include "lcd_sw_inc.h"
#include "common/owftypes.h"
#include "common/owfimage.h"
#include "wfd\inc\wfd_lcd_internal.h"
#include "wfd\inc\wfd_common.h"
#include "lcd_power_mgr.h"
#include "lcd_if_manager.h"
#include "l1_interface.h"
#include "wfc/wfc.h"
#include "wfc/wfcplatform.h"
#include "common/owfnativestream.h"
#include "common/owfimage.h"
#include "lcd_if.h"
#include "lcd_if_hw.h"
#include "lcd_sw_inc.h"
#include "display_io.h"
#include "mmi_features.h"

#ifdef __cplusplus
extern "C" {
#endif

extern void FlattenInit(void);
extern WFD_PORT _wfd_lcd_port[];
extern WFD_DEVICE _wfd_lcd_device;
extern WFDboolean __wfd_lcd_RollbackPortIFSetting(WFDint portId);

static kal_uint32 _lcd_power_handle = 0xFFFFFFFF;

void lcd_power_ctrl(kal_bool enable)
{
    if (_lcd_power_handle == 0xFFFFFFFF)
    {
        _lcd_power_handle = lcd_power_ctrl__register_module();
    }

    if(KAL_TRUE == enable)
    {
        lcd_power_ctrl__enable(_lcd_power_handle);
        __wfd_lcd_RollbackPortIFSetting(0);

#if (ATTACHED_LCM_CNT == 2)
        __wfd_lcd_RollbackPortIFSetting(1);
#endif
    }
    else
    {
        lcd_power_ctrl__disable(_lcd_power_handle);
    }
}

/**
 * Set Rotation of LCM
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 * @param rotate_value the rotate value of LCM
 *
 * @return None.
 */
void lcd_set_rotate(kal_uint8 lcd_id, kal_uint8 rotate_value)
{
    DisplayLCMRotate_T DisplayLCMRotate;
    DisplayLCMRotate.rotate_value = rotate_value;
    DisplayIOControl((DisplayDeviceEnum)lcd_id, DISPLAY_IOCTL_LCM_SET_ROTATE, &DisplayLCMRotate);
   }

/**
 * lcd_get_screen_para_info: Get LCD information
 *
 * @param screen_id: MAIN_LCD or SUB_LCD
 * @param scren_width, screen_height: display resolution
 * @param color_depth: Bpp of output color format
 *
 * @return None.
 */
 
void lcd_get_screen_para_info(
   LCD_TYPE_ENUM screen_id,
   kal_uint32* scren_width,
   kal_uint32* screen_height,
   kal_uint32* color_depth)
{
    DisplayGetScreenInfo_T DisplayGetScreenInfo;
    DisplayIOControl((DisplayDeviceEnum)screen_id, DISPLAY_IOCTL_GET_SCREEN_INFO, &DisplayGetScreenInfo);
    *scren_width = DisplayGetScreenInfo.screen_width;
    *screen_height = DisplayGetScreenInfo.screen_height;
    *color_depth = DisplayGetScreenInfo.color_depth;
}


/**
 * Set the temperature compensation parameters of LCM
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 * @param compensate the temperature compensate of LCM
 *
 * @return None.
 */
void lcd_set_temp_compensate(kal_uint8 lcd_id, kal_uint8 *compensate)
{
    DisplayLCMTempCompensate_T DisplayLCMTempCompensate;
    DisplayLCMTempCompensate.compensate = *compensate;
    DisplayIOControl((DisplayDeviceEnum)(lcd_id), DISPLAY_IOCTL_LCM_SET_TEMP_COMPENSATE, &DisplayLCMTempCompensate);
    *compensate = DisplayLCMTempCompensate.compensate;
}

/**
 * set the line rate of LCM.
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 * @param linereate the line rate of LCM
 *
 * @return None.
 */
void lcd_set_linerate(kal_uint8 lcd_id, kal_uint8 *linereate)
{
    DisplayLCMLineRate_T DisplayLCMLinerate;
    DisplayLCMLinerate.linerate = *linereate;
    DisplayIOControl((DisplayDeviceEnum)(lcd_id), DISPLAY_IOCTL_LCM_SET_LINERATE, &DisplayLCMLinerate);
    *linereate = DisplayLCMLinerate.linerate;
}

/**
 * set the contrast of LCM.
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 * @param contrast the contrast of LCM
 *
 * @return None.
 */
void lcd_set_contrast(kal_uint8 lcd_id, kal_uint8 *contrast)
{
    DisplayLCMContrast_T DisplayLCMContrast;
    DisplayLCMContrast.contrast = *contrast;
    DisplayIOControl((DisplayDeviceEnum)(lcd_id), DISPLAY_IOCTL_LCM_SET_CONTRAST, &DisplayLCMContrast);
    *contrast = DisplayLCMContrast.contrast;
}

/**
 * set the bias of LCM.
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 * @param bias the bias of LCM
 *
 * @return None.
 */
void lcd_set_bias(kal_uint8 lcd_id, kal_uint8 *bias)
{
    DisplayLCMBias_T DisplayLCMBias;
    DisplayLCMBias.bias = *bias;
    DisplayIOControl((DisplayDeviceEnum)(lcd_id), DISPLAY_IOCTL_LCM_SET_BIAS, &DisplayLCMBias);
    *bias = DisplayLCMBias.bias;
}

/**
 * Get the width and height of LCM
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 * @param lcd_width the width of LCM
 * @param lcd_height the height of LCM
 *
 * @return None.
 */
void lcd_get_size(kal_uint8 lcd_id, kal_uint16 *lcd_width, kal_uint16 *lcd_height)
{
    DisplayGetScreenInfo_T DisplayGetScreenInfo;
    DisplayIOControl((DisplayDeviceEnum)(lcd_id), DISPLAY_IOCTL_GET_SCREEN_INFO, &DisplayGetScreenInfo);
    *lcd_width = DisplayGetScreenInfo.screen_width;
    *lcd_height = DisplayGetScreenInfo.screen_height;
}
 
/**
 * Turns on/off LCM screen
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 * @param on turn on/off screen (KAL_TRUE/KAL_FALSE)
 *
 * @return None.
 */
void lcd_screen_on(kal_uint8 lcd_id, kal_bool on)
{
    DisplayLCMPower_T DisplayLCMPower;
    DisplayLCMPower.bPowerOn = on;
    DisplayIOControl((DisplayDeviceEnum)(lcd_id), DISPLAY_IOCTL_LCM_SET_POWER, &DisplayLCMPower);
}

/**
 * Turns on/off LCM power
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 * @param on turn on/off LCM power (KAL_TRUE/KAL_FALSE)
 *
 * @return None.
 */
void lcd_power_on(kal_uint8 lcd_id, kal_bool on)
{
    //sht:fix MAUI_03034393
	#if defined(__EMPTY_MMI__) || defined(__IOT__)
			return;
	#else
    	if(on)
    	{
        lcd_sleep_out(lcd_id);
    	}
    	else
    	{
        lcd_sleep_in(lcd_id);
    	}
	#endif
}

/**
 * Display partial screen on LCD
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 * @param start_line the first line to display
 * @param end_line the last line to display
 *
 * @return None.
 */
void lcd_partial_on(kal_uint8 lcd_id, kal_uint16 start_line, kal_uint16 end_line)
{
    DisplayLCMPartialDisplay_T DisplayLCMPartialOn;
    DisplayLCMPartialOn.bPartialOn = KAL_TRUE;
    DisplayLCMPartialOn.start_line = start_line;
    DisplayLCMPartialOn.end_line = end_line;
    DisplayIOControl((DisplayDeviceEnum)(lcd_id), DISPLAY_IOCTL_LCM_SET_PARTIAL_DISPLAY, &DisplayLCMPartialOn);
}

/**
 * Exit partial display mode
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 *
 * @return None.
 */
void lcd_partial_off(kal_uint8 lcd_id)
{
    DisplayLCMPartialDisplay_T DisplayLCMPartialOn;
    DisplayLCMPartialOn.bPartialOn = KAL_FALSE;
    DisplayIOControl((DisplayDeviceEnum)(lcd_id), DISPLAY_IOCTL_LCM_SET_PARTIAL_DISPLAY, &DisplayLCMPartialOn);
}

/**
 * Get align line for partial display
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 *
 * @return align line for partial display
 */
kal_uint8 lcd_partial_display_align_line(kal_uint8 lcd_id)
{
    DisplayLCMPartialDisplay_T DisplayLCMPartialOn;
    DisplayIOControl((DisplayDeviceEnum)(lcd_id), DISPLAY_IOCTL_LCM_GET_PARTIAL_DISPLAY, &DisplayLCMPartialOn);
    return DisplayLCMPartialOn.alignment;
}

/**
 * Set the brightness of LCM
 *
 * @param lcd_id MAIN_LCD or SUB_LCD
 * @param bright_level brightness level of LCM
 *
 * @return None.
 */
void lcd_bright_level(kal_uint8 lcd_id, kal_uint8 bright_level)
{
    DisplayLCMBrightLevel_T DisplayLCMBrightLevel;
    DisplayLCMBrightLevel.bright_level = bright_level;
    DisplayIOControl((DisplayDeviceEnum)(lcd_id), DISPLAY_IOCTL_LCM_SET_BRIGHT_LEVEL, &DisplayLCMBrightLevel);
}


//extern WFCDevice getWfcLCDDeviceHandle(void);
//extern WFCContext getWfcLCMPortHandle(WFCDevice device, WFCint portId);
//extern WFCint getWfcPortNum(WFCDevice device);

extern WFDboolean __wfd_lcd_PortPowerCtrl(WFD_DEVICE* device, WFD_PORT* port);
kal_bool lcd_sleep_in(kal_uint8 lcd_id)
{
#if !defined(__KEEP_LCD_ENGINE_ON__)   
   WFD_PORT_TYPE_ENUM portId; 
   //kal_uint32 save_irq_mask;
   if (MAIN_LCD == lcd_id)
   {
      portId = WFD_PORT_MAIN_LCD; //MAIN_LCD
   }
   #if (ATTACHED_LCM_CNT == 2)
   else if (SUB_LCD == lcd_id)
   {
      portId = WFD_PORT_SUB_LCD; //Sub_LCD
   }
   #endif
   else
   {
      return KAL_TRUE;
   }
   
   if (KAL_TRUE != LCD_Physical_Interface_Lock())
   {
       return KAL_FALSE;
   }

   //Set Power state to OFF.
   _wfd_lcd_port[portId].config.powerMode = WFD_POWER_MODE_OFF;

   __wfd_lcd_PortPowerCtrl((WFD_DEVICE*)&_wfd_lcd_device, (WFD_PORT*)&_wfd_lcd_port[portId]);

   LCD_Physical_Interface_Unlock();
#endif
   
   return KAL_TRUE;
   
}

void lcd_sleep_out(kal_uint8 lcd_id)
{
   WFD_PORT_TYPE_ENUM portId; 
   //kal_uint32 save_irq_mask;
   if (MAIN_LCD == lcd_id)
   {
      portId = WFD_PORT_MAIN_LCD; //MAIN_LCD
   }
   #if (ATTACHED_LCM_CNT == 2)
   else if (SUB_LCD == lcd_id)
   {
      portId = WFD_PORT_SUB_LCD; //Sub_LCD
   }
   #endif
   else
   {
      return;
   }
   
   
   if (KAL_TRUE != LCD_Physical_Interface_Lock())
   {
       return;
   }
   
   
   //Set Power state to ON.
   _wfd_lcd_port[portId].config.powerMode = WFD_POWER_MODE_ON;
   
   __wfd_lcd_PortPowerCtrl((WFD_DEVICE*)&_wfd_lcd_device, (WFD_PORT*)&_wfd_lcd_port[portId]);

   LCD_Physical_Interface_Unlock();
   
   return;

}



//Notice
//The following functions are used by others rather than GDI.
//We need to discuss with callers and try to remove these APIs by using WFC interface
//But at current stage, we have no time to handle this issue...
//TODO: remove this APIs

void SpeechLcdTest(kal_bool iEnable,kal_uint8 iPeriod)
{

}

void assert_lcd_fb_update(kal_uint8 lcd_id, kal_uint16 start_x, kal_uint16 start_y, kal_uint16 end_x,
                          kal_uint16 end_y,kal_uint16 roi_offset_x, kal_uint16 roi_offset_y, kal_uint32 update_layer)

{
}

LCD_STATUS_CODE_ENUM lcd_fb_update(lcd_frame_update_struct *lcd_para)
{

 return LCD_OK;
}

void hpi_power_ctrl(kal_bool bTurnOnClock)
{
}

kal_uint8 lcd_get_power_handle( void )
{
   return 0;
}

void set_lcd_color_palette(kal_uint8 color_palette_select,kal_uint16 *color_palette_addr_ptr,
                           kal_uint8 start_index, kal_uint8 number_of_color)
{
}


kal_bool lcd_is_flatten_ready(void)
{
    return KAL_TRUE;
}



//lcd_display_enable (referred from idp_cal.obj).
void lcd_display_enable(kal_bool enable)
{
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 

void lcd_system_init(void)
{
//workaround for MT6250 watchdog can't reset MM sys,uing sw reset MM sys here.
#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
		
		
		(*(volatile kal_uint32 *)(0xA0180808)) &= 0xFFFFFFFE;
		
		(*(volatile kal_uint32 *)(0xA0180808)) |= 0x1;
		
#endif

 FlattenInit( );
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

void lcd_stop_hw_update(kal_uint8 lcd_id)
{


}

kal_uint8 lcd_get_te_ctrl_handle(void)
{
    return 0;
}

kal_bool lcd_te_ctrl_push(kal_bool on_Noff, kal_uint8 handle)
{

    return KAL_TRUE;
}

kal_bool lcd_te_ctrl_pop( kal_uint8 handle)
{
    return KAL_TRUE;
}

////////////////////////////////////////////////////////////////////



#ifdef __cplusplus
}
#endif

#endif  // #if defined(__MTK_TARGET__)

