
#include "lcd_if.h"
#include "lcm_if.h"
#include "lcd_if_hw.h"
#include "drv_features_display.h"
#include "drv_sw_features_display.h"
/**
 *  The following variables are used to refer to LCM primitives...
 *  And used widely by LCD driver and other SW modules, it is used by both 
 *  DDv1 and DDv2. So it is extracted...
 */
volatile LCD_Funcs *MainLCD = NULL; //MainLCD (referred from custom_em.obj).
volatile LCD_Funcs *SubLCD = NULL;
//volatile kal_uint16 lcd_cmd_period_count; //(referred from lcd.obj).

// (referred from lcd.obj)
#define LCD_FMARK_G_NO_FOR_NOT_MM    0x13579024
volatile unsigned int lcd_fmark=LCD_FMARK_G_NO_FOR_NOT_MM;

/* referred from lcd.obj
 * This function is only B/W or gray scale LCM, LCM driver
 * will read from frame buffer and write to LCM by CPU after
 * color transform. Some assumptions are made when use this
 * function : 
 * 1. Only 1 layer used
 * 2. Frame buffer format is RGB565
 * 3. Update entire LCM.
 */
kal_uint32 get_lcd_frame_buffer_address(void)              
{                                                          
   kal_uint32 lcd_frame_buffer_address = 0;                

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

   return lcd_frame_buffer_address;                        
}                         