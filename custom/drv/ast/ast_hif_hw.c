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
 *    ast_hif_hw_custom.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains common code for AST HIF adaptation layer.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================*/
#if defined(__AST_TL1_TDD__)

#include "kal_release.h"
#include "intrCtrl.h" 
#include "drv_comm.h"
#include "dma_sw.h"
#include "dma_hw.h"
#include "dcl.h"
#include "gpio_sw.h"
#include "eint.h"
#include "l1_interface.h"
#include "ast_hif_hw.h"
#include "hif_hal.h"
#include "reg_base.h"
#include "ast_hif_hw_custom.h"
#include "lcd_if_manager.h"
#include "nld_central_ctrl.h"

#if (defined(__NLD_CENTRAL_CTRL__)) && (defined(MT6255))
#define IO_DRV1  *((volatile kal_uint32 *)0x80000504)
#define IO_DRV2  *((volatile kal_uint32 *)0x80000508)
#define IO_DRV1_MASK_BITS   3
#define IO_DRV2_MASK_BITS   0x777777
#define IO_DRV2_MASK_BITS_2 7
#define IO_DRV_OFFSET_4_BIT    4
#define IO_DRV_OFFSET_8_BIT    8
#define IO_DRV_OFFSET_12_BIT   12
#define IO_DRV_OFFSET_16_BIT   16
#define IO_DRV_OFFSET_20_BIT   20
#endif 
HIF_HANDLE ast_hif_hw_handle = NULL;

//AST_GPIO_CLK32K_MODULE & AST_HIF_PORT gen by DCT tool(Later chip, such as MT6260....)
#if defined(GET_AST_GPIO_CLK32K_LPCEID_BY_DCT_TOOL)
char AST_HIF_PORT;
char AST_GPIO_CLK32K_MODULE;

static void ast_gpio_dct_init()
{
    extern char gpio_ast_clk32k_pin_CLK;
    extern char gpio_ast_cs_pin_LPCE;
    AST_GPIO_CLK32K_MODULE = gpio_ast_clk32k_pin_CLK;
    AST_HIF_PORT = gpio_ast_cs_pin_LPCE;
}
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
// Below is hif hardware interface
////////////////////////////////////////////////////////////////////////////////////////////////////

#if !defined(AST_HIF_HW_INIT_BY_PROJECT)
AST_HIF_HW_RESULT ast_hif_hw_init(AST_HIF_HW_CONFIG_T* pConfigParam)
{
    DCL_HANDLE gpio_handle;
    GPIO_CTRL_SET_CLK_OUT_T gpio_clk_data;
    #if defined(GET_AST_GPIO_CLK32K_LPCEID_BY_DCT_TOOL)
    ast_gpio_dct_init();
    #endif
    
    ASSERT(pConfigParam != NULL);

    //enable 32k to AST1001
    gpio_handle = DclGPIO_Open(DCL_GPIO_CLK, AST_GPIO_CLK32K_MODULE);
    gpio_clk_data.u2ClkNum=AST_GPIO_CLK32K_MODULE;
    gpio_clk_data.u2Mode=mode_f32k_ck;
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_CLK_OUT,(DCL_CTRL_DATA_T*)&gpio_clk_data);
    DclGPIO_Close(gpio_handle);	
    
    ast_hif_hw_handle = hif_open(AST_HIF_PORT);
    
    ASSERT(ast_hif_hw_handle);
    
    ast_hif_hw_power_ctrl(KAL_TRUE);
    
    ast_hif_hw_config(pConfigParam);
	{
		HIF_REALTIME_CALLBACK_T HifRealTimeCB;
		HIF_ULTRA_HIGH_CTRL_T UltraHighCtrl;
		HifRealTimeCB.realtime_callback_en = KAL_TRUE;
	  hif_ioctl(ast_hif_hw_handle,HIF_IOCTL_REALTIME_CALLBACK,&HifRealTimeCB);
       
    UltraHighCtrl.ultra_high_en = KAL_TRUE;
    hif_ioctl(ast_hif_hw_handle, HIF_IOCTL_ULTRA_HIGH_CTRL, &UltraHighCtrl);	
    }
    
    ast_hif_hw_power_ctrl(KAL_FALSE);
  #if defined(MT6922) && (!defined(__NLD_CENTRAL_CTRL__))
  #if defined(APOLLO22N_E2_EVB)
    set_lcd_driving_current(LCD_DRIVING_16MA);
  #else
    set_lcd_driving_current(LCD_DRIVING_8MA);
  #endif
#endif
    return AST_HIF_HW_RESULT_OK;
}
#endif

AST_HIF_HW_RESULT ast_hif_hw_config(AST_HIF_HW_CONFIG_T* pConfigParam)
{
    HIF_CONFIG_T pHIFConfig;
    pHIFConfig.hif_time_c2ws = pConfigParam->hif_time_c2ws;
    pHIFConfig.hif_time_c2wh = pConfigParam->hif_time_c2wh;
    pHIFConfig.hif_time_wst = pConfigParam->hif_time_wst;
    pHIFConfig.hif_time_c2rs = pConfigParam->hif_time_c2rs;
    pHIFConfig.hif_time_c2rh = pConfigParam->hif_time_c2rh;
    pHIFConfig.hif_time_rlt = pConfigParam->hif_time_rlt;
    pHIFConfig.hif_time_chw = 0;
    pHIFConfig.hif_base_clk = pConfigParam->hif_base_clk;
    pHIFConfig.hif_bus_width = pConfigParam->hif_bus_width;
    
    hif_config(ast_hif_hw_handle, &pHIFConfig);
    return AST_HIF_HW_RESULT_OK;
}

AST_HIF_HW_RESULT ast_hif_hw_power_ctrl(kal_bool bPowerOn)
{
    if (bPowerOn)
    {
        //HIF_ULTRA_HIGH_CTRL_T UltraHighCtrl;
        hif_power_ctrl(ast_hif_hw_handle, KAL_TRUE);
        //UltraHighCtrl.ultra_high_en = KAL_TRUE;
        //hif_ioctl(ast_hif_hw_handle, HIF_IOCTL_ULTRA_HIGH_CTRL, &UltraHighCtrl);
    }
    else
    {
        hif_power_ctrl(ast_hif_hw_handle, KAL_FALSE);
    }
    return AST_HIF_HW_RESULT_OK;
}

AST_HIF_HW_RESULT ast_hif_hw_write(AST_HIF_HW_TYPE type, kal_uint32 addr, kal_uint32 size, AST_HIF_HW_CALLBACK fCB)
{
    HIF_RESULT result = HIF_RESULT_OK;
    switch (type)
    {
    case AST_HIF_HW_TYPE_A0H_CPU:
    	#if defined(MT6255)
        result = hif_mcu_write_fast(ast_hif_hw_handle, HIF_TYPE_A0H_CPU, addr, size);
      #else
        result = hif_write(ast_hif_hw_handle, HIF_TYPE_A0H_CPU, addr, size, fCB); 
      #endif
        break;
    case AST_HIF_HW_TYPE_A0H_DMA:
        result = hif_write(ast_hif_hw_handle, HIF_TYPE_A0H_DMA, addr, size, fCB);
        break;
    case AST_HIF_HW_TYPE_A0L_CPU:
    	#if defined(MT6255)
        result = hif_mcu_write_fast(ast_hif_hw_handle, HIF_TYPE_A0L_CPU, addr, size);
      #else
        result = hif_write(ast_hif_hw_handle, HIF_TYPE_A0L_CPU, addr, size, fCB);
      #endif
        break;
    case AST_HIF_HW_TYPE_A0L_DMA:
        result = hif_write(ast_hif_hw_handle, HIF_TYPE_A0L_DMA, addr, size, fCB);
        break;
    default:
        ASSERT(0);
        break;
    }
    return (AST_HIF_HW_RESULT)result;
}

AST_HIF_HW_RESULT ast_hif_hw_read(AST_HIF_HW_TYPE type, kal_uint32 addr, kal_uint32 size, AST_HIF_HW_CALLBACK fCB)
{
    HIF_RESULT result = HIF_RESULT_OK;
    switch (type)
    {
    case AST_HIF_HW_TYPE_A0H_CPU:
    	#if defined(MT6255)
        result = hif_mcu_read_fast(ast_hif_hw_handle, HIF_TYPE_A0H_CPU, addr, size);
      #else
        result = hif_read(ast_hif_hw_handle, HIF_TYPE_A0H_CPU, addr, size, fCB);
      #endif
        break;
    case AST_HIF_HW_TYPE_A0H_DMA:
        result = hif_read(ast_hif_hw_handle, HIF_TYPE_A0H_DMA, addr, size, fCB);
        break;
    case AST_HIF_HW_TYPE_A0L_CPU:
    	#if defined(MT6255)
        result = hif_mcu_read_fast(ast_hif_hw_handle, HIF_TYPE_A0L_CPU, addr, size);
      #else
        result = hif_read(ast_hif_hw_handle, HIF_TYPE_A0L_CPU, addr, size, fCB);
      #endif
        break;
    case AST_HIF_HW_TYPE_A0L_DMA:
        result = hif_read(ast_hif_hw_handle, HIF_TYPE_A0L_DMA, addr, size, fCB);
        break;
    default:
        ASSERT(0);
        break;
    }
    return (AST_HIF_HW_RESULT)result;
}

#if !defined(AST_HIF_HW_REG_EINT_BY_PROJECT)
AST_HIF_HW_RESULT ast_hif_hw_reg_eint(AST_HIF_HW_EINT_T* pEintParam)
{
    DCL_HANDLE gpio_handle;
    // register interrupt

    EINT_Set_Sensitivity(AST_EINT_NO, LEVEL_SENSITIVE);
    EINT_Set_Polarity(AST_EINT_NO, KAL_FALSE);
    EINT_Registration(AST_EINT_NO, KAL_FALSE, KAL_FALSE, pEintParam->fINTCB/*ast_hif_hw_eint_isr*/, KAL_TRUE);

    EINT_Set_Sensitivity(AST_WAKEUP_EINT_NO, EDGE_SENSITIVE);
    EINT_Set_Polarity(AST_WAKEUP_EINT_NO, KAL_TRUE);
    EINT_Registration(AST_WAKEUP_EINT_NO, KAL_FALSE, KAL_TRUE, pEintParam->fWakeUpCB, KAL_TRUE);

    EINT_Set_Sensitivity(AST_RFCONF_EINT_NO, LEVEL_SENSITIVE);
    EINT_Set_Polarity(AST_RFCONF_EINT_NO, KAL_TRUE);
	/* clear original debounce value */
	EINTaddr(AST_RFCONF_EINT_NO) &= ~EINT_CON_DEBOUNCE;
	/* set new debounce value */
	EINTaddr(AST_RFCONF_EINT_NO) |= (1 | EINT_CON_DEBOUNCE_EN);
    EINT_Registration(AST_RFCONF_EINT_NO, KAL_TRUE, KAL_TRUE, pEintParam->fRFConfCB, KAL_TRUE);
    return AST_HIF_HW_RESULT_OK;
}
#endif

kal_bool ast_hif_hw_query_power_state(void)
{
    HIF_POWER_STATE_T power_state;
    hif_ioctl(ast_hif_hw_handle, HIF_IOCTL_QUERY_POWER_STATE, &power_state);
    return power_state.hif_power_on;
}

#if !defined(AST_HIF_HW_SET_GPIO_BY_PROJECT)
AST_HIF_HW_RESULT ast_hif_hw_set_gpio(char value, char pin)
{
    DCL_HANDLE handle;
    handle=DclGPIO_Open(DCL_GPIO, pin);	
    if(0==value)
        DclGPIO_Control(handle,GPIO_CMD_WRITE_LOW,0);
    else if(1==value)
        DclGPIO_Control(handle,GPIO_CMD_WRITE_HIGH,0);
    else
    {
        DclGPIO_Close(handle);
        ASSERT(0);
    }
    DclGPIO_Close(handle);
    return AST_HIF_HW_RESULT_OK;
}
#endif
#if (!defined(__UBL__) && !defined(__FUE__))
#pragma arm section code = "PRIMARY_ROCODE", rwdata = "PRIMARY_RW", rodata = "PRIMARY_RODATA"
#endif
#if defined(__NLD_CENTRAL_CTRL__)
void ast_hif_set_driving_current(kal_uint32 current)
{
	kal_uint32 saved_irq;
	kal_uint8 tempCurrent;
	switch(current)
	{
		case 0:
		case 1:tempCurrent = 0;break;
		case 2:
		case 3:tempCurrent = 1;break;
		case 4:
		case 5:tempCurrent = 2;break;
		case 6:
		case 7:tempCurrent = 3;break;
		default:tempCurrent = 1;
	}
	saved_irq = SaveAndSetIRQMask();
	IO_DRV1 &= ~IO_DRV1_MASK_BITS;
	IO_DRV1 |= (tempCurrent & IO_DRV1_MASK_BITS); // set ctrl pin driving current
	IO_DRV1 &= ~(IO_DRV1_MASK_BITS << IO_DRV_OFFSET_8_BIT);
	IO_DRV1 |= ((tempCurrent & IO_DRV1_MASK_BITS)<<IO_DRV_OFFSET_8_BIT);	// set data pin driving current
	IO_DRV2 &= ~IO_DRV2_MASK_BITS;
	IO_DRV2 |= (current & IO_DRV2_MASK_BITS_2) |((current & IO_DRV2_MASK_BITS_2) << IO_DRV_OFFSET_4_BIT)\
	                                           |((current & IO_DRV2_MASK_BITS_2) << IO_DRV_OFFSET_8_BIT)\
	                                           |((current & IO_DRV2_MASK_BITS_2) << IO_DRV_OFFSET_12_BIT)\
	                                           |((current & IO_DRV2_MASK_BITS_2) << IO_DRV_OFFSET_16_BIT)\
	                                           |((current & IO_DRV2_MASK_BITS_2) << IO_DRV_OFFSET_20_BIT) ;
	RestoreIRQMask(saved_irq);
}

#endif
#if (!defined(__UBL__) && !defined(__FUE__))
#pragma arm section code 
#endif
#endif
// END
