/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *   lcd_exception_api_chip_id.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   LCD exception function
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
 * 01 21 2014 edwardyc.lin
 * removed!
 *
 * 01 21 2013 joey.pan
 * removed!
 * Fix pq build errors.
 *
 * 01 21 2013 joey.pan
 * removed!
 * Turn on mdp path PQ setting.
 *
 * 01 21 2013 joey.pan
 * removed!
 * Merge PQv2 modification.
 *
 * 01 03 2013 joey.pan
 * removed!
 * Sync display de-feature settings.
 *
 * 11 12 2012 joey.pan
 * removed!
 * Fix MT6260 LCD build error.
 * 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_general_types.h"
#include "lcd_exception_api.h"
#include "mm_power_ctrl.h"
#include "lcd_if_hw.h"
#include "lcd_sw.h"
#include "lcd_if.h"
#include "lcm_if.h"
#include "drv_comm.h"
#include "debug\inc\lcd_catcher_log.h"
#include "drv_features_color.h"
#include "color_enum.h"
#include "color_api.h"


void init_lcd_interface(void);
void LCD_FunConfig(void);
extern volatile LCD_Funcs *MainLCD;
extern kal_bool  lcd_assert_fail;

static kal_uint32* lcd_exception_register_dump_buffer = NULL;
static kal_bool g_bExceptionFlatten = KAL_FALSE;
//static kal_uint32 g_ExceptionTime = 0;

// lcd_exception_flatten
// Description: Overlay LCD layers to a framebuffer.
kal_uint32 lcd_exception_flatten(kal_uint32 layers, lcd_exception_layer_struct* pLayerInfo, kal_uint8* pFramebuffer, kal_uint32 bg_color, kal_uint32 width, kal_uint32 height)
{
    kal_uint32 i;
    kal_uint32 layer_en_mask;
    kal_uint32 max_layer_buffer_size;
    // Check exception status. This API can only be called when exception occurs.
    if (KAL_FALSE == INT_QueryExceptionStatus())
        return 1;
    // This API can only be called once.
    if (g_bExceptionFlatten == KAL_TRUE)
        return 2;
    mm_enable_power(MMPWRMGR_LCD);
#if  defined(__SERIAL_LCM__) && (defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))
	  mm_enable_power(MMPWRMGR_SLCD);
#endif
    
    // Backup LCD registers
    // Temp solution. Store LCD registers to a frame buffer and record the buffer address.
    // Find a large enough layer buffer which is not equal to pFramebuffer.
    if (g_bExceptionFlatten == KAL_FALSE)
    {
        //g_ExceptionTime = drv_get_current_time();
        max_layer_buffer_size = 0;
        /*
        for (i=0; i<(0x174/4); i+=4) // LCD common registers
        {
            kal_uint32 address = LCD_base + i*4;
            DDV2CatcherLogException((address), *(volatile kal_uint32*) (address + 0), *(volatile kal_uint32*) (address + 4), *(volatile kal_uint32*) (address + 8), *(volatile kal_uint32*) (address + 12));
        }
        for (i=0; i<(0x60/4); i+=4) // LCD debug registers
        {
            kal_uint32 address = LCD_base + 0x1F0 + i*4;
            DDV2CatcherLogException((address), *(volatile kal_uint32*) (address + 0), *(volatile kal_uint32*) (address + 4), *(volatile kal_uint32*) (address + 8), *(volatile kal_uint32*) (address + 12));
        }*/
        
        
        for (i=0; i<layers; i++)
        {
            if (pLayerInfo[i].frame_buffer != (kal_uint32)pFramebuffer)
            {
                // Calculate layer buffer size.
                max_layer_buffer_size = pLayerInfo[i].mem_pitch * pLayerInfo[i].src_rect[3];
                if (max_layer_buffer_size > 0x300)
                {
                    // Record buffer pointer.
                    lcd_exception_register_dump_buffer = (kal_uint32*) (pLayerInfo[i].frame_buffer + max_layer_buffer_size - 0x300);
                    break;
                }
            }
        }
        if (lcd_exception_register_dump_buffer)
        {
            // Dump LCD registers.
            lcd_exception_register_dump_buffer[0] = 0x5F44434C; // Guard pattern "LCD_REG"
            lcd_exception_register_dump_buffer[1] = 0x20474552; // Guard pattern "LCD_REG"
            lcd_exception_register_dump_buffer[2] = 0x5F44434C; // Guard pattern "LCD_REG"
            lcd_exception_register_dump_buffer[3] = 0x00474552; // Guard pattern "LCD_REG"
            for (i=0; i<(0x174/4); i++) // LCD common registers
                lcd_exception_register_dump_buffer[4+i] = *(kal_uint32*) (LCD_base + i*4);
            for (i=0; i<(0x60/4); i++)  // LCD debug registers
                lcd_exception_register_dump_buffer[4+0x174/4+i] = *(kal_uint32*) (LCD_base + 0x1F0 + i*4);
            //for (i=0; i<(0x80/4); i++) // LCD command queue registers
            //    lcd_exception_register_dump_buffer[4+0x1D4/4+i] = *(kal_uint32*) (LCD_base + 0xC400 + i*4);
        }
    }
    g_bExceptionFlatten = KAL_TRUE;
    
    // Flatten current layers.
    //Reset key LCD registers.
    REG_LCD_START = 1;  // Reset LCD controller.
    REG_LCD_START = 0;
    REG_LCD_INT_ENABLE = 0;
    REG_LCD_ROI_CTRL = 0;
    REG_LCD_TECON = 0;
    REG_LCD_GMCCON = 0;
    REG_LCD_ULTRA_CON = 0;
    
    // The frame buffer must be 2 bytes allignment for RGB565.
    if ((kal_uint32)pFramebuffer % 2)
        return 2;
    // Config ROI registers.
    LCD_SET_ROI_BG_COLOR(bg_color);
    
    LCD_SET_ROI_OFFSET(1024, 1024);
    LCD_SET_ROI_SIZE(width, height);
    
    // Config layers.
    // Since the data in LCD layer registers may lose when power off. So we need to retrieve the information for GDI.
    layer_en_mask = 0;
    for (i=0; i<layers; i++)
    {
        layer_en_mask |= (0x80000000>>i);
        
        LCD_SET_LAYER_CTRL_CLEAR(i);
        
        if (pLayerInfo[i].src_key_en)
        {
            LCD_SET_LAYER_CTRL_SOURCE_KEY_EN(i);
            LCD_SET_LAYER_COLOR_KEY(i, pLayerInfo[i].color_key);
        }
        if (pLayerInfo[i].alpha_blend_en)
        {
            LCD_SET_LAYER_CTRL_OPACITY_EN(i);
            LCD_SET_LAYER_CTRL_OPACITY(i, pLayerInfo[i].alpha);
        }

        //Rotation Angle
        {
            kal_uint16 angle;
            switch (pLayerInfo[i].rotate_angle)
            {
                case 0:
                    angle = ((KAL_FALSE == (pLayerInfo[i].flip_en&0x1)) ? 0: 4);
                    break;
                case 90:
                    angle = ((KAL_FALSE == (pLayerInfo[i].flip_en&0x1)) ? 3: 7);
                    break;
                case 180:
                    angle = ((KAL_FALSE == (pLayerInfo[i].flip_en&0x1)) ? 2: 6);
                    break;
                case 270:
                    angle = ((KAL_FALSE == (pLayerInfo[i].flip_en&0x1)) ? 1: 5);
                    break;
                default:
                    return 4;
            }
            LCD_SET_LAYER_CTRL_ROTATE(i, angle);
        }

        // Byte Swap Enable?
        if (pLayerInfo[i].swap_en)
        {
            LCD_SET_LAYER_CTRL_DATA_SWAP_EN(i);
        }

        //Color Format
        switch (pLayerInfo[i].color_format)
        {
        case LCD_EXPT_LAYER_FORMAT_RGB565:
            LCD_SET_LAYER_CTRL_FMT(i, 1);
            break;
        case LCD_EXPT_LAYER_FORMAT_RGB888:
            LCD_SET_LAYER_CTRL_FMT(i, 3);
            break;
        case LCD_EXPT_LAYER_FORMAT_ARGB8888:
            LCD_SET_LAYER_CTRL_FMT(i, 4);
            break;
        case LCD_EXPT_LAYER_FORMAT_PARGB8888:
            LCD_SET_LAYER_CTRL_FMT(i, 5);
            break;
        case LCD_EXPT_LAYER_FORMAT_UYVY422:
            LCD_SET_LAYER_CTRL_FMT(i, 2);
            break;
        default:
            return 5;
        }

        //roi offset x, y
        LCD_SET_LAYER_OFFSET(i, pLayerInfo[i].dst_rect[0] + 1024, pLayerInfo[i].dst_rect[1] + 1024);
                             
        LCD_SET_LAYER_MEM_OFFSET(i, pLayerInfo[i].src_rect[0], pLayerInfo[i].src_rect[1]);
                                 
        //layer size x, y
        LCD_SET_LAYER_SIZE(i, pLayerInfo[i].src_rect[2], pLayerInfo[i].src_rect[3]);
        
        // Layer memory pitch
        *((volatile unsigned int *) (LCD_LAYER0_MEM_PITCH_REG   + (i)  * LCD_LAYER_ADDR_OFFSET)) = pLayerInfo[i].mem_pitch;        
        
        LCD_SET_LAYER_BUFF_ADDR(i, pLayerInfo[i].frame_buffer);
        
    }
    REG_LCD_ROI_CTRL |= layer_en_mask;
    
    // Output to memory
    
    REG_LCD_START = 0;
    REG_LCD_START = 0x8000; // Start LCD
    
    for (i=0; i<100; i++) ; //Short Delay to avoid CPU checking status bit before the bit is set.
    
    {
        kal_uint32 start_time = drv_get_current_time();
        while(1)
        {
            if (!(REG_LCD_STA & 1))
                break;
            // Time out protect. Flatten should be done in 1 second. Interrupt is disabled at this moment.
            if (drv_get_duration_ms(start_time) > 1000)
                return 6;
        }
    }

//Dong: after exception handle, turn off MM power, avoid from accidental injuries. 
    mm_disable_power(MMPWRMGR_LCD);  
#if defined(__SERIAL_LCM__) && (defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))
		mm_disable_power(MMPWRMGR_SLCD);
#endif

    return 0;
}

// lcd_exception_screen_update
// Descrption: Output flatten frame buffer to LCM.
kal_uint32 lcd_exception_screen_update(kal_uint8* pFramebuffer, kal_uint32 width, kal_uint32 height)
{
   kal_uint32 i;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    mm_enable_power(MMPWRMGR_LCD);
#if  defined(__SERIAL_LCM__) && (defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))
	  mm_enable_power(MMPWRMGR_SLCD);
#endif
    
    REG_LCD_START = 1;  // Reset LCD controller.
    REG_LCD_START = 0;
    REG_LCD_INT_ENABLE = 0;
    REG_LCD_TECON = 0;
    REG_LCD_GMCCON = 0;
    REG_LCD_ULTRA_CON = 0;
    REG_LCD_ROI_CTRL = 0;
    // Call init_lcd_interface() to set LCM timing.
    init_lcd_interface();
    // Call LCM init
    REG_LCD_START = 1;  // Reset LCD controller.
    REG_LCD_START = 0;    
    SET_LCD_ROI_CTRL_OUTPUT_FORMAT(MAIN_LCD_OUTPUT_FORMAT);
    DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,MAIN_LCD_CMD_ADDR);
    DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,MAIN_LCD_DATA_ADDR);
    // Call LCM init
    LCD_FunConfig();
    // Init LCM.
    MainLCD->Init(0xFFFF, 0);
        
    if ((kal_uint32)pFramebuffer % 2)
        return 2;
    REG_LCD_ROI_CTRL |= 0x80000000;   // Enable layer0.
    SET_LCD_ROI_CTRL_OUTPUT_FORMAT(MAIN_LCD_OUTPUT_FORMAT);
    DRV_WriteReg32(LCD_ROI_CMD_ADDR_REG,MAIN_LCD_CMD_ADDR);
    DRV_WriteReg32(LCD_ROI_DATA_ADDR_REG,MAIN_LCD_DATA_ADDR);
    LCD_SET_ROI_OFFSET(1024, 1024);
    LCD_SET_ROI_SIZE(width, height);
    
    // Config layer0
    LCD_SET_LAYER_CTRL_CLEAR(0);
    LCD_SET_LAYER_CTRL_ROTATE(0, 0);
    LCD_SET_LAYER_CTRL_FMT(0, 1);   // RGB565
    LCD_SET_LAYER_OFFSET(0, 1024, 1024);
    LCD_SET_LAYER_SIZE(0, width, height);
    LCD_SET_LAYER_BUFF_ADDR(0, (kal_uint32)(pFramebuffer));
    REG_LCD_LAYER0_MEM_PITCH = width * 2;
    
#if defined(__DRV_COLOR_HW_SUPPORT__)
    // config mm_color
    colorUpdateConfig(COLOR_PATH_LCD, LCD_GET_ROI_WIDTH);
#endif

    // This flag should be set to KAL_FALSE before calling LCM block write function.
    lcd_assert_fail = KAL_FALSE;
    
    MainLCD->BlockWrite(0, 0, width-1, height-1);
    for (i=0; i<100; i++) ; //Short Delay to avoid CPU checking status bit before the bit is set.
    
    {
        kal_uint32 start_time = drv_get_current_time();
        while(1)
        {
            if (!(REG_LCD_STA & 1))
                break;
            // Time out protect. Flatten should be done in 1 second. Interrupt is disabled at this moment.
            if (drv_get_duration_ms(start_time) > 1000)
            	{
            	DRV_Reg(LCD_INT_STATUS_REG);
                return 6;
            	}

        }
    }
	DRV_Reg(LCD_INT_STATUS_REG);
	
//Dong: after exception handle, turn off MM power, avoid from accidental injuries. 	
	mm_disable_power(MMPWRMGR_LCD);
#if defined(__SERIAL_LCM__) && (defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))
	mm_disable_power(MMPWRMGR_SLCD);
#endif
	
    return 0;
}

