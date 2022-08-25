/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 *   display_io.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file implement misc interface for display driver.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_release.h"
#include "common\display_io.h"
#include "lcm_if\lcm_if.h"
#include "intrctrl.h"
#include "kal_public_api.h"
#include "wfd\inc\wfd_lcd_internal.h"
#include "lcd_sw_inc.h"
#include "lcd_sw.h"
#include "lcd_power_mgr.h"
#include "drv_comm.h"
#include "wfd\inc\wfd_common.h"
#include "wfd\inc\wfd.h"
#include "lcd_if_hw.h"
#include "debug\inc\lcd_catcher_log.h"
#include "common\include\display_io_internal.h"


extern volatile LCD_Funcs *MainLCD;
extern volatile LCD_Funcs *SubLCD;
void LCD_FunConfig(void);

extern WFD_PORT _wfd_lcd_port[];
extern WFDboolean __wfd_lcd_RollbackPortIFSetting(WFDint portId);

static kal_uint32 disp_io_lcd_power_handle = 0xFFFFFFFF;
//this global variable for 3D to record and debug
#ifdef DRV_LCD_3D_MODE_SUPPORT
static Display3DModeEnum disp_io_lcm_3D_mode = DISPLAY_3D_MODE_OFF;
#endif

#if defined(DISPLAYIO_DBG_SUPPORT)

    #if !defined(__LOW_COST_SUPPORT_COMMON__) && !defined(__LOW_COST_SUPPORT_ULC__)
        #define DISPLAYIO_DBG_ENTRY_CNT 32     
    #else
        #define DISPLAYIO_DBG_ENTRY_CNT 8      
    #endif

static volatile DisplayIODbgCtrlBlk _DisplayIO_DbgDat[DISPLAYIO_DBG_ENTRY_CNT] = \
														{DisplayIODBG________________INVALID,\
														DISPLAY_INVALID_DEVICE,\
														DISPLAY_IOCTL_INVALID,\
														NULL,\
														DISPLAY_RESULT_OK,\
														NULL,\
														NULL};
static volatile kal_uint32 _DisplayIO_DbgCnt = 0;

static void DisplayIO_Trace(DisplayIODbgIDEnum id, DisplayDeviceEnum device, DisplayCtrlCode code, void* pData, DisplayResultEnum error_code)
{
    kal_uint32 index;
    kal_uint32 save_irq_mask;

    save_irq_mask = SaveAndSetIRQMask( );
    index = _DisplayIO_DbgCnt;
    _DisplayIO_DbgCnt++;
    _DisplayIO_DbgCnt &= (DISPLAYIO_DBG_ENTRY_CNT -1);
    RestoreIRQMask(save_irq_mask);

    _DisplayIO_DbgDat[index].threadID = (kal_uint32)kal_get_current_thread_ID( );
    _DisplayIO_DbgDat[index].time = drv_get_current_time( );
    _DisplayIO_DbgDat[index].id = id;
    _DisplayIO_DbgDat[index].device = device;
    _DisplayIO_DbgDat[index].code = code;
    _DisplayIO_DbgDat[index].data_address = (kal_uint32)pData;
    _DisplayIO_DbgDat[index].error_code = error_code;

}

#else //#if defined(DISPLAYIO_DBG_SUPPORT)

define DisplayIO_Trace(...) 

#endif //#if defined(DISPLAYIO_DBG_SUPPORT)

DisplayResultEnum DisplayIOControl(DisplayDeviceEnum device, DisplayCtrlCode code, void* pData)
{
    WFD_PORT_TYPE_ENUM portId; 
    DisplayResultEnum result = DISPLAY_RESULT_OK;
    volatile LCD_Funcs *pLCMDevice = NULL;

    DDV2CatcherLogL1D8(TRACE_DDV2_DISPLAY_IO, DDV2_TRC_DISPLAYIO_CTRL, 
                                              drv_get_current_time( ),
                                              (kal_uint32)kal_get_current_thread_ID( ),
                                              DisplayIODBG__________________ENTER,
                                              device,
                                              code,
                                              (kal_uint32)pData,
                                              DISPLAY_RESULT_OK, 0);
    DisplayIO_Trace(DisplayIODBG__________________ENTER, device, code, pData, DISPLAY_RESULT_OK);

    // Not allowed to be called when exception occurs.
    if (KAL_TRUE == INT_QueryExceptionStatus())
    {
        result = DISPLAY_RESULT_CONTROL_FAIL;
        goto Exit;
    } 
    // Hook LCM function pointers if they have not been initialized.
    if (MainLCD == NULL)
    {
        result = DISPLAY_RESULT_CONTROL_FAIL;
        goto Exit;
    } 
    // Register LCD power manager module if it has not been registered.
    if (disp_io_lcd_power_handle == 0xFFFFFFFF)
    {
        disp_io_lcd_power_handle = lcd_power_ctrl__register_module();
    }
    lcd_power_ctrl__enable(disp_io_lcd_power_handle);
    if ((code > DISPLAY_IOCTL_SEPARATOR_USE_LCDIF_S) && (code < DISPLAY_IOCTL_SEPARATOR_USE_LCDIF_E))
    {
        // Get permission for LCD hardware interface and lock it.
        if (KAL_TRUE != LCD_Physical_Interface_Lock())
        {
            lcd_power_ctrl__disable(disp_io_lcd_power_handle);
            result = DISPLAY_RESULT_CONTROL_FAIL;
            goto Exit;
        }

        // For LCM device, rewrite interface settings.
        if (device == DISPLAY_LCM0)
        {
            __wfd_lcd_RollbackPortIFSetting(0);
            DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,MAIN_LCD_CMD_ADDR);
            DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,MAIN_LCD_DATA_ADDR);
            pLCMDevice = MainLCD;
            portId = WFD_PORT_MAIN_LCD; //MAIN_LCD
        }
#ifdef DUAL_LCD
        if (device == DISPLAY_LCM1)
        {
            __wfd_lcd_RollbackPortIFSetting(1);
            DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,SUB_LCD_CMD_ADDR);
            DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,SUB_LCD_DATA_ADDR);
            pLCMDevice = SubLCD;
            portId = WFD_PORT_SUB_LCD; //Sub_LCD
        }
#endif
        // If LCM is in sleep mode, do nothing and return. LCM cannot receive command when it is in sleep mode.
        if ((pLCMDevice != NULL) && (WFD_POWER_MODE_ON != _wfd_lcd_port[portId].config.powerMode))
        {
            // Turn off LCD power.
            lcd_power_ctrl__disable(disp_io_lcd_power_handle);
            // Unlock LCD HW interface
            LCD_Physical_Interface_Unlock();
            result = DISPLAY_RESULT_LCM_SLEEP_IN;
            goto Exit;
        }
    }

    // Process control code.
    switch (code)
    {
    case DISPLAY_IOCTL_CABC_QUERY_SUPPORT:
        {
            DisplayCABC_T* pCABCStruct = (DisplayCABC_T*) pData;
            if (pCABCStruct)
            {
                LCM_CABC_INFO_STRUCT CABC_Info;
                LCM_COMM_DATA_STRUCT CABC_Param;
                CABC_Info.Type = LCM_CABC_TYPE__QUERY_SUPPORT;
                CABC_Info.FeatureValue = &CABC_Param;
                
                pCABCStruct->bSupport = KAL_FALSE;
                // Query CABC support
                if (pLCMDevice)
                {
                    pLCMDevice->IOCTRL(LCM_IOCTRL_CABC, &CABC_Info);
                    pCABCStruct->bSupport = (kal_bool)CABC_Param.Value;
                }
                else
                    result = DISPLAY_RESULT_CONTROL_FAIL;
            }
            else
                result = DISPLAY_RESULT_INVALID_DATA;
        }
        break;
    case DISPLAY_IOCTL_CABC_SET_MODE:
        {
            DisplayCABC_T* pCABCStruct = (DisplayCABC_T*) pData;
            if (pCABCStruct && pCABCStruct->mode < DISPLAY_CABC_MODE_INVALID)
            {
                LCM_CABC_INFO_STRUCT CABC_Info;
                //LCM_COMM_DATA_STRUCT CABC_Param;
                switch (pCABCStruct->mode)
                {
                case DISPLAY_CABC_MODE_OFF:
                    CABC_Info.Type = LCM_CABC_TYPE__SET_MODE_OFF;
                    break;
                case DISPLAY_CABC_MODE_UI:
                    CABC_Info.Type = LCM_CABC_TYPE__SET_MODE_UI;
                    break;
                case DISPLAY_CABC_MODE_STILL:
                    CABC_Info.Type = LCM_CABC_TYPE__SET_MODE_STILL;
                    break;
                case DISPLAY_CABC_MODE_MOVING:
                    CABC_Info.Type = LCM_CABC_TYPE__SET_MODE_MOVING;
                    break;
                default:
                    result = DISPLAY_RESULT_CONTROL_FAIL;
                    break;
                }
                // Set CABC mode
                if (pLCMDevice)
                {
                    pLCMDevice->IOCTRL(LCM_IOCTRL_CABC, &CABC_Info);
                }
                else
                    result = DISPLAY_RESULT_CONTROL_FAIL;
            }
            else
                result = DISPLAY_RESULT_INVALID_DATA;
        }
        break;
    case DISPLAY_IOCTL_CABC_GET_MODE:
        {
            DisplayCABC_T* pCABCStruct = (DisplayCABC_T*) pData;
            if (pCABCStruct)
            {
                LCM_CABC_INFO_STRUCT CABC_Info;
                LCM_COMM_DATA_STRUCT CABC_Param;
                CABC_Info.Type = LCM_CABC_TYPE__QUERY_MODE;
                CABC_Info.FeatureValue = &CABC_Param;
                // Get CABC mode
                if (pLCMDevice)
                {
                    pLCMDevice->IOCTRL(LCM_IOCTRL_CABC, &CABC_Info);
                    pCABCStruct->mode = (DisplayCABCModeEnum)CABC_Param.Value;
                }
                else
                    result = DISPLAY_RESULT_CONTROL_FAIL;
            }
            else
                result = DISPLAY_RESULT_INVALID_DATA;
        }
        break;
    case DISPLAY_IOCTL_CABC_SET_BRIGHTNESS:
        {
            DisplayCABCBrightness_T* pDisplayBrightness = (DisplayCABCBrightness_T*) pData;
            if (pLCMDevice)
                pLCMDevice->IOCTRL(LCM_IOCTRL_CABC__SET_BRIGHTNESS, &(pDisplayBrightness->duty_value));
        }
        break;
    case DISPLAY_IOCTL_LCM_SET_ROTATE:
        {
#ifdef LCM_ROTATE_SUPPORT
            DisplayLCMRotate_T* pLCMRotateStruct = (DisplayLCMRotate_T*) pData;
            if (pLCMDevice)
                pLCMDevice->SetRotation(pLCMRotateStruct->rotate_value);
#endif
        }
        break;
    case DISPLAY_IOCTL_GET_SCREEN_INFO:
        {
            DisplayGetScreenInfo_T* pScreenInfoStruct = (DisplayGetScreenInfo_T*) pData;
            kal_uint32 color_format = 0;
            pScreenInfoStruct->screen_width = 0;
            pScreenInfoStruct->screen_height = 0;
            if (device == DISPLAY_LCM0)
            {
                pScreenInfoStruct->screen_width = LCD_WIDTH;
                pScreenInfoStruct->screen_height = LCD_HEIGHT;
                color_format = (MAIN_LCD_OUTPUT_FORMAT & 0x38) >> 3;
            }
#ifdef DUAL_LCD
            if (device == DISPLAY_LCM1)
            {
                pScreenInfoStruct->screen_width = SUBLCD_WIDTH;
                pScreenInfoStruct->screen_height = SUBLCD_HEIGHT;
                color_format = (SUB_LCD_OUTPUT_FORMAT & 0x38) >> 3;
            }
#endif   
            switch(color_format)
            {
            case 0: pScreenInfoStruct->color_depth = 8; break;
            case 1: pScreenInfoStruct->color_depth = 12; break;
            case 2: pScreenInfoStruct->color_depth = 16; break;
            case 3: pScreenInfoStruct->color_depth = 18; break;
            case 4: pScreenInfoStruct->color_depth = 24; break;
            default: pScreenInfoStruct->color_depth = 0;
            }
        }
        break;
    case DISPLAY_IOCTL_LCM_SET_TEMP_COMPENSATE:
        {
            DisplayLCMTempCompensate_T* pDisplayLCMTempCompensate = (DisplayLCMTempCompensate_T*) pData;
            if (pLCMDevice)
                pLCMDevice->SetTemperatureCompensate(&(pDisplayLCMTempCompensate->compensate));
        }
        break;
    case DISPLAY_IOCTL_LCM_SET_LINERATE:
        {
            DisplayLCMLineRate_T* pDisplayLCMLinerate = (DisplayLCMLineRate_T*) pData;
            if (pLCMDevice)
                pLCMDevice->SetLineRate(&(pDisplayLCMLinerate->linerate));
        }
        break;
    case DISPLAY_IOCTL_LCM_SET_CONTRAST:
        {
            DisplayLCMContrast_T* pDisplayLCMContrast = (DisplayLCMContrast_T*) pData;
            if (pLCMDevice)
                pLCMDevice->SetContrast(&(pDisplayLCMContrast->contrast));
        }
        break;
    case DISPLAY_IOCTL_LCM_SET_BIAS:
        {
            DisplayLCMBias_T* pDisplayLCMBias = (DisplayLCMBias_T*) pData;
            if (pLCMDevice)
                pLCMDevice->SetBias(&(pDisplayLCMBias->bias));
        }
        break;
    case DISPLAY_IOCTL_LCM_SET_POWER:
        {
            DisplayLCMPower_T* pDisplayLCMPower = (DisplayLCMPower_T*) pData;
            if (pLCMDevice)
                pLCMDevice->TurnOnPower(pDisplayLCMPower->bPowerOn);
        }
        break;
    case DISPLAY_IOCTL_LCM_SET_PARTIAL_DISPLAY:
        {
            DisplayLCMPartialDisplay_T* pDisplayLCMPartialOn = (DisplayLCMPartialDisplay_T*) pData;
            if (pLCMDevice)
            {
                if (pDisplayLCMPartialOn->bPartialOn)
                    pLCMDevice->TurnOnPartialDisplay(pDisplayLCMPartialOn->start_line, pDisplayLCMPartialOn->end_line);
                else
                    pLCMDevice->TurnOffPartialDisplay();
            }
        }
        break;
    case DISPLAY_IOCTL_LCM_GET_PARTIAL_DISPLAY:
        {
            DisplayLCMPartialDisplay_T* pDisplayLCMPartialOn = (DisplayLCMPartialDisplay_T*) pData;
            if (pLCMDevice)
                pDisplayLCMPartialOn->alignment = pLCMDevice->GetPartialDisplayAlignment();
            else
                pDisplayLCMPartialOn->alignment = 0;
        }
        break;
    case DISPLAY_IOCTL_LCM_SET_BRIGHT_LEVEL:
        {
            DisplayLCMBrightLevel_T* pDisplayLCMBrightLevel = (DisplayLCMBrightLevel_T*) pData;
            if (pLCMDevice)
                pLCMDevice->SetBrightLevel(pDisplayLCMBrightLevel->bright_level);
        }
        break;
    case DISPLAY_IOCTL_GET_FRAMEBUFFER_ADDRESS:
        {
            kal_uint32 lcd_frame_buffer_address = 0;
            DisplayFrameBufferAddress_T* pDisplayFBAddress = (DisplayFrameBufferAddress_T*) pData;
#if defined(__MTK_TARGET__)
#if (DRV_LAYER_TOTAL_COUNT>1)                           
            switch (REG_LCD_ROI_CTRL&LCD_LAYER_MASK) 
            {           
            case LCD_LAYER0_ENABLE:                              
                lcd_frame_buffer_address=REG_LCD_LAYER0_BUFF_ADDR;
                break;                                            
            case LCD_LAYER1_ENABLE:                              
                lcd_frame_buffer_address=REG_LCD_LAYER1_BUFF_ADDR;
                break;                                            
            case LCD_LAYER2_ENABLE:                              
                lcd_frame_buffer_address=REG_LCD_LAYER2_BUFF_ADDR;
                break;                                            
            case LCD_LAYER3_ENABLE:                              
                lcd_frame_buffer_address=REG_LCD_LAYER3_BUFF_ADDR;
                break;                                            
#if (DRV_LAYER_TOTAL_COUNT>4)                        
            case LCD_LAYER4_ENABLE:                              
                lcd_frame_buffer_address=REG_LCD_LAYER4_BUFF_ADDR;
                break;                                            
            case LCD_LAYER5_ENABLE:                              
                lcd_frame_buffer_address=REG_LCD_LAYER5_BUFF_ADDR;
                break;                                            
#endif/// (DRV_LAYER_TOTAL_COUNT>4)                  
            }                                                    
#endif///(DRV_LAYER_TOTAL_COUNT>1)
#endif
            pDisplayFBAddress->address = lcd_frame_buffer_address;
        }
        break;
        
    case DISPLAY_IOCTL_ESD_CHECK:
        {
            LcdEsdCheck_T * pEsdStruct = (LcdEsdCheck_T *) pData;
            LCM_ESD_INFO_STRUCT ESD_Info;
            ESD_Info.bEsdHappened = KAL_FALSE;
            
            if (pEsdStruct)
            {
                if (pLCMDevice)
                {
                    ///If LCM do not support, we assume NO ESD happened here~~
                    if(pLCMDevice->IOCTRL(LCM_IOCTL_ESD_CHECK, &ESD_Info) != LCM_IOCTRL_OK)
                    {
                        ESD_Info.bEsdHappened = KAL_FALSE;
                    }
                }
                pEsdStruct->bEsdHappened = ESD_Info.bEsdHappened;
            }
            else
                result = DISPLAY_RESULT_INVALID_DATA;
        }
        break;
        
    case DISPLAY_IOCTL_ESD_RESET:
        if (pLCMDevice)
        {
            pLCMDevice->IOCTRL(LCM_IOCTL_ESD_RESET, NULL);
        }
        break;
        
#ifdef DRV_LCD_3D_MODE_SUPPORT
    case DISPLAY_IOCTL_LCM_SET_3D_MODE:
        {
            Display3DMode_T* p3DModeStruct = (Display3DMode_T*) pData;
			disp_io_lcm_3D_mode = p3DModeStruct ->mode;
            if (p3DModeStruct && p3DModeStruct->mode < DISPLAY_3D_MODE_INVALID)
            {
                LCM_3D_Mode_Enum LCM_3D_MODE;
                //LCM_COMM_DATA_STRUCT CABC_Param;
                switch (p3DModeStruct->mode)
                {
                case DISPLAY_3D_MODE_OFF:
                    LCM_3D_MODE = LCM_3D_MODE_OFF;
                    break;
                case DISPLAY_3D_MODE_PORTRAIT:
                    LCM_3D_MODE = LCM_3D_MODE_PORTRAIT;
                    break;
                case DISPLAY_3D_MODE_LANDSCAPE:
                    LCM_3D_MODE = LCM_3D_MODE_LANDSCAPE;
                    break;
                default:
                    result = DISPLAY_RESULT_CONTROL_FAIL;
                    break;
                }
                // Set 3D mode
                if (pLCMDevice)
                {
                    pLCMDevice->IOCTRL(LCM_IOCTRL_SET_3D_PANEL_WORKING_MODE, &LCM_3D_MODE);
                }
                else
                    result = DISPLAY_RESULT_CONTROL_FAIL;
            }
            else
                result = DISPLAY_RESULT_INVALID_DATA;
        }
        break;
#endif
    default:
        result = DISPLAY_RESULT_INVALID_CODE;
        break;
    }
	
    //read DBI ULTRA HIGH REG to delay 4T for MT6255/56 F2S bus early return potential risk.
     #if defined(MT6255) || defined(MT6256)
   	 DRV_Reg(LCD_DBI_ULTRA_TH_REG);
     #endif
    //This must wait for LCD Transfer Complete, otherwise NLI_ARBITER will hang because of lcd power is off
    while( LCD_IS_RUNNING ) { }
    
    STOP_LCD_TRANSFER;

    //Sanity fail of MAUI_03006155, read this register to clear LCD Interrupt.
    DRV_Reg(LCD_INT_STATUS_REG);

    if ((code > DISPLAY_IOCTL_SEPARATOR_USE_LCDIF_S) && (code < DISPLAY_IOCTL_SEPARATOR_USE_LCDIF_E))
    {
        // Unlock LCD hardware interface.
        LCD_Physical_Interface_Unlock();
    }

    // Turn off LCD power.
    lcd_power_ctrl__disable(disp_io_lcd_power_handle);

Exit:        
    DDV2CatcherLogL1D8(TRACE_DDV2_DISPLAY_IO, DDV2_TRC_DISPLAYIO_CTRL, 
                                              drv_get_current_time( ),
                                              (kal_uint32)kal_get_current_thread_ID( ),
                                              DiaplayIODBG___________________EXIT,
                                              device,
                                              code,
                                              (kal_uint32)pData,
                                              result, 0);
    DisplayIO_Trace(DiaplayIODBG___________________EXIT, device, code, pData, result);
    return result;
}
