/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005-2007
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
 *   lcd_power_mgr.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   LCD Power/Clock control layer APIs.
 *
 * Author:
 * -------
 * -------
 *============================================================================
 * HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 01 21 2014 edwardyc.lin
 * removed!
 *
 * 01 21 2014 edwardyc.lin
 * removed!
 *
 * 11 12 2012 joey.pan
 * removed!
 * Fix MT6260 LCD build error.
 *
 * 07 18 2012 haitao.shang
 * removed!
 * .
 *
 * 05 15 2012 jody.li
 * removed!
 * mm_disable_power() has no delay for MT6250.
 *
 * 03 29 2012 xiaoyong.ye
 * removed!
 * 
 * Fix some problem.
 *
 * 03 28 2012 haitao.shang
 * removed!
 * .
 *
 * 03 20 2012 xiaoyong.ye
 * removed!
 * MT6250 display driver check in.
 *
 * 08 31 2011 zifeng.qiu
 * removed!
 * .
 *
 * 08 18 2011 zifeng.qiu
 * removed!
 * Resolve low power issue.
 *
 * 08 10 2011 zifeng.qiu
 * removed!
 * Resolve lcd power ctrl racing issue.
 *
 * 08 09 2011 zifeng.qiu
 * removed!
 * Resovle lcd power manager racing issue.
 *
 * 08 05 2011 zifeng.qiu
 * removed!
 * .
 *
 * 08 01 2011 tianshu.qiu
 * removed!
 * .
 *
 * 06 26 2011 tianshu.qiu
 * removed!
 * .
 *
 * 06 23 2011 bin.han
 * removed!
 * .
 *
 * 04 22 2011 zifeng.qiu
 * removed!
 * Slim for LCD Power Ctrl Layer.
 *
 * 04 21 2011 bin.han
 * removed!
 * .
 *
 * 03 08 2011 bin.han
 * removed!
 * .MT6256 LCD driver code first check in
 *
 * 02 11 2011 sophie.chen
 * removed!
 * .
 *
 * 02 10 2011 chelun.tsai
 * removed!
 * modify drv_features.h include.
 *
 * 01 07 2011 sophie.chen
 * removed!
 * .
 *
 * 12 24 2010 sophie.chen
 * removed!
 * .
 *
 * 12 23 2010 sophie.chen
 * removed!
 * .
 *
 * 12 22 2010 sophie.chen
 * removed!
 * .
 *
 * 12 06 2010 sophie.chen
 * removed!
 * .
 *
 * 12 06 2010 sophie.chen
 * removed!
 * .
 *
 * 11 23 2010 sophie.chen
 * removed!
 * .
 *
 * 11 15 2010 sophie.chen
 * removed!
 * .
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"
#include "drv_comm.h"
#include "mm_power_ctrl.h"
#include "lcd_power_manager\inc\lcd_power_mgr_utility.h"
#include "lcd_power_mgr.h"
#include "lcd_if.h" 
#include "lcd_if_hw.h"
#include "drv_features_display.h"
#include "lcd_sw.h" //For 6252 serial lcm
#include "drv_sw_features_display.h"
#include "drv_features_color.h"
#include "color_enum.h"
#include "color_api.h"



#ifdef MTK_SLEEP_ENABLE
extern kal_uint8 L1SM_GetHandle(void);
extern void L1SM_SleepEnable(kal_uint8 HANDLE);
extern void L1SM_SleepDisable(kal_uint8 HANDLE);
static kal_uint8 lcd_power_sleep_mode_hander;
#endif
static LCD_POWER_CTRL_CNXT_STRUCT lcd_ctrl_cntx = { KAL_FALSE,0,0 };

#define lcd_power_ctrl__get_registered_module_count()  lcd_ctrl_cntx.lcd_power_ctrl_registered_module_count

#define lcd_power_ctrl__get_module_handle() lcd_ctrl_cntx.lcd_power_ctrl_handle
#define lcd_power_ctrl__set_module_handle(module_id) lcd_ctrl_cntx.lcd_power_ctrl_handle |= (1 << module_id)
#define lcd_power_ctrl__clear_module_handle(module_id) lcd_ctrl_cntx.lcd_power_ctrl_handle &= (~(1 << module_id))
//#define lcd_power_ctrl__init_cnxt() memset(lcd_ctrl_cntx, 0, sizeof(lcd_ctrl_cntx))


//#define LCD_POWER_CTRL__TRACE
#if defined(LCD_POWER_CTRL__TRACE)
LCD_POWER_CTRL__DBG_STRUCT lcd_power_ctrl__debug_data[LCD_POWER_CTRL__DEBUG_CNT];
kal_uint32 lcd_power_ctrl__dbg_idx = 0;
static void _lcd_power_ctrl__trace(kal_uint32 module_id, LCD_POWER_CTRL__DEBUG_ENUM id)
{
    kal_uint32 save_irq_mask;
    kal_uint32 index;

    save_irq_mask=SaveAndSetIRQMask();
    index = lcd_power_ctrl__dbg_idx;
    lcd_power_ctrl__dbg_idx++;
    lcd_power_ctrl__dbg_idx = lcd_power_ctrl__dbg_idx % LCD_POWER_CTRL__DEBUG_CNT;
    RestoreIRQMask(save_irq_mask); 	
    lcd_power_ctrl__debug_data[index].id = id;
    lcd_power_ctrl__debug_data[index].caller_module_id = module_id;
    lcd_power_ctrl__debug_data[index].ctrl_module_val = lcd_power_ctrl__get_module_handle();
    lcd_power_ctrl__debug_data[index].lcd_clk_hw_sts = (!mm_query_clock_status(MMPWRMGR_LCD));
}
#else
#define _lcd_power_ctrl__trace(id, module_id) 
#endif


static void _lcd_power_ctrl__init(void)
{
    kal_uint32 save_irq_mask;

    save_irq_mask = SaveAndSetIRQMask();
    if (KAL_TRUE == lcd_ctrl_cntx.lcd_power_ctrl_init)
    { 
        RestoreIRQMask(save_irq_mask);
        return;
    }
    lcd_ctrl_cntx.lcd_power_ctrl_init = KAL_TRUE;    
#ifdef MTK_SLEEP_ENABLE
    lcd_power_sleep_mode_hander = L1SM_GetHandle();
#endif
    RestoreIRQMask(save_irq_mask);

    _lcd_power_ctrl__trace(0, LCD_PWR_CTRL__INIT____________________X);
}

kal_uint32 lcd_power_ctrl__register_module(void)
{
    kal_uint32 save_irq_mask;
    kal_uint32 count = 0;

    _lcd_power_ctrl__init();

    save_irq_mask = SaveAndSetIRQMask();
    if (32 == lcd_ctrl_cntx.lcd_power_ctrl_registered_module_count)
    {
        count = 0xFFFFFFFF;
    }
    else
    {
        count = lcd_ctrl_cntx.lcd_power_ctrl_registered_module_count++; 
    }
    RestoreIRQMask(save_irq_mask);

    _lcd_power_ctrl__trace(0, LCD_PWR_CTRL__REGISTER________________X);

    return count;
}

//Caller shall handle rollback register
void lcd_power_ctrl__enable(kal_uint32 module)
{
    kal_uint32 save_irq_mask;

    if (lcd_ctrl_cntx.lcd_power_ctrl_init == 0)
    {
        _lcd_power_ctrl__trace(module, LCD_PWR_CTRL__ERROR_NOT_INITIALIZED___X);
        return;
    }
    if (module >= lcd_power_ctrl__get_registered_module_count())
    {
        _lcd_power_ctrl__trace(module, LCD_PWR_CTRL__ERROR_INVALID_MODULE____X);
        return;
    }
    _lcd_power_ctrl__trace(module, LCD_PWR_CTRL__ENABLE____B_____________X);

    // Set power module handle.
    save_irq_mask = SaveAndSetIRQMask();
    lcd_power_ctrl__set_module_handle(module);
    RestoreIRQMask(save_irq_mask);

    // Turn on power
    mm_enable_power(MMPWRMGR_LCD);
#if defined(__SERIAL_LCM__) && defined(MT6252)
    mm_enable_power(MMPWRMGR_LCD104M);
#elif defined(__SERIAL_LCM__) && (defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))
	mm_enable_power(MMPWRMGR_SLCD);
#endif
    _lcd_power_ctrl__trace(module, LCD_PWR_CTRL__ENABLE____MMPWRMGR_ON___X);

    _lcd_power_ctrl__trace(module, LCD_PWR_CTRL__ENABLE____E_____________X);

#ifdef MTK_SLEEP_ENABLE
    L1SM_SleepDisable(lcd_power_sleep_mode_hander);
#endif

#if defined(__DRV_COLOR_HW_SUPPORT__)
		// turn on color power
		colorPowerEnable(KAL_TRUE);
#endif
}

void lcd_power_ctrl__disable(kal_uint32 module)
{
    kal_uint32 save_irq_mask;

    if (lcd_ctrl_cntx.lcd_power_ctrl_init == 0)
    {
        _lcd_power_ctrl__trace(module, LCD_PWR_CTRL__ERROR_NOT_INITIALIZED___X);
        return;
    }
    if (module >= lcd_power_ctrl__get_registered_module_count())
    {
        _lcd_power_ctrl__trace(module, LCD_PWR_CTRL__ERROR_INVALID_MODULE____X);
        return;
    }
 
    _lcd_power_ctrl__trace(module, LCD_PWR_CTRL__DISABLE___B_____________X);

    save_irq_mask = SaveAndSetIRQMask();

    // Clear power module handle.
    lcd_power_ctrl__clear_module_handle(module);

    // Turn off power
    if (lcd_power_ctrl__get_module_handle() == 0)
    {
        mm_disable_power(MMPWRMGR_LCD);
#if defined(__SERIAL_LCM__) && defined(MT6252)
        mm_disable_power(MMPWRMGR_LCD104M);
#elif defined(__SERIAL_LCM__) && (defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))
		mm_disable_power(MMPWRMGR_SLCD);
#endif

#if defined(__DRV_COLOR_HW_SUPPORT__)
		// turn off color power
		colorPowerEnable(KAL_FALSE);
#endif
    }

    RestoreIRQMask(save_irq_mask);


    _lcd_power_ctrl__trace(module, LCD_PWR_CTRL__DISABLE___E_____________X);

#ifdef MTK_SLEEP_ENABLE
    save_irq_mask = SaveAndSetIRQMask( );
    if (0 == lcd_power_ctrl__get_module_handle( )) //Because lcd_power_ctrl__enable( ) may be invoked from last I-bit protection to now
    {
        L1SM_SleepEnable(lcd_power_sleep_mode_hander);
    }
    RestoreIRQMask(save_irq_mask);
#endif
}
