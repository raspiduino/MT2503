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
 * EngineerModeDevice.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for engineer mode device part.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#include "EngineerModeUtil.h"
#ifdef __MMI_ENGINEER_MODE__    /* MTK Add Robin 1001 for saperate MMI feature by project */

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#if defined(COSMOS_EM_INTERNAL_DCM)
#include "dcmgr.h"
#elif defined (PLUTO_EM_INTERNAL_DCM)
#include "MMI_ap_dcm_config.h"  
#endif /* COSMOS_EM_INTERNAL_DCM */
    
#if defined(PLUTO_EM_INTERNAL_DCM)
#pragma arm section rodata = "DYNAMIC_CODE_EM_RODATA" , code = "DYNAMIC_CODE_EM_ROCODE"
#elif defined(COSMOS_EM_INTERNAL_DCM)
#pragma arm section rodata = "DYNAMIC_CODE_COSMOS_EM_RODATA" , code = "DYNAMIC_CODE_COSMOS_EM_ROCODE"
#endif /* PLUTO_EM_INTERNAL_DCM */ 


#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif 
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "gdi_features.h"
#include "gdi_datatype.h"
#include "uart_sw.h"
#include "GlobalConstants.h"
#include "gui_data_types.h"
#include "wgui_inline_edit.h"
#include "l4c_common_enum.h"
#include "wgui_categories_util.h"
#include "mmi_frm_history_gprot.h"
#include "GlobalMenuItems.h"
#include "CustMenuRes.h"
#include "EngineerModeResDef.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_list.h"
#include "GlobalResDef.h"
#include "kal_public_api.h"
#include "wgui_categories_inputs.h"
#include "ImeGprot.h"
#include "mmi_frm_input_gprot.h"
#include "Unicodexdcl.h"
#include "stdlib.h"
#include "CustDataRes.h"
#include "wgui_categories_text_viewer.h"
#include "GpioSrvGprot.h"
#include "gui_typedef.h"
#include "wgui_include.h"
#include "gui.h"
#include "mmi_frm_mem_gprot.h"
#include "gdi_include.h"
#include "gdi_const.h"
#include "mmi_rp_file_type_def.h"
#include "string.h"
#ifdef __MMI_EM_DEV_USB_TETHERING__
#include "AlertScreen.h"
#include "usbacm_adap.h"
#include "shutdownSrvGprot.h"
#endif /* __MMI_EM_DEV_USB_TETHERING__ */

#ifdef __MMI_EM_DEV_WLAN_EAP_MODE__
#include "EngineerModeWLAN.h"
#endif

#ifdef __MMI_FILE_MANAGER__
    #include "FileMgrGProt.h"
#endif
#include "mmi_res_range_def.h"
#include "stdio.h"
#include "stack_msgs.h"
#include "mmi_msg_struct.h"
#include "wgui_categories.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "ps_public_struct.h"
#ifdef __MMI_EM_DEV_MEMORY_TEST__
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#endif
#include "mmi_frm_nvram_gprot.h"
#include "nvram_data_items.h"
#include "EngineerModeAppResDef.h"
#include "stack_config.h"
#include "drv_features.h"
#include "lcd_if.h"

#include "dcl.h"
#include "CharBatSrvGprot.h"

#include "ProtocolEvents.h"

#include "CommonScreens.h"

#include "Nvram_interface.h"
#include "Custom_equipment.h"
#include "gpio_measure.h"
#include "eint_measure.h"
#include "pwm_measure.h"
#include "battery_measure.h"
#include "lcd_measure.h"
#include "device.h"
#include "custom_em.h"
#include "custom_uem.h"
#include "custom_hw_default.h"
#include "PowerOnChargerProt.h"

#if defined(__MMI_EM_MISC_SOFTWARE_TRACER__)
/* under construction !*/
#endif

#if defined(NAND_SUPPORT)       /* && defined(MMI_ON_HARDWARE_P) */
#include "ProfilesSrvGProt.h"
#endif 

#ifdef __MTK_TARGET__
#ifdef __OTG_ENABLE__
#include "otg_if.h"
#endif 
#endif

#include "FileMgrSrvGProt.h"
#include "fmt_def.h"
#include "FileMgr.h"
#include "FileManagerDef.h"
#include "FileManagerGProt.h"
#include "GpioSrvGprot.h"

#include "adc_channel.h"

#ifdef __USB_TETHERING__
#include "usbacm_adap.h"
#endif
#include "timerevents.h"

/* For 10A*/
#include "fseditorcuigprot.h"
#include "FileMgrCUIGProt.h"
#include "inlinecuigprot.h"
#include "EngineerModeDef.h"
#include "EngineerModeType.h"
#include "EngineerModeUtil.h"
#include "EngineerModeCommUI.h"
#include "EngineerModeCommMem.h"
#include "EngineerModeMultimedia.h"
#include "EngineerModePMIC.h"
#include "EngineerModeDevice.h"
#include "EngineerModeGPS.h"
#include "mmi_rp_app_engineermode1_def.h"        
#include "drv_sw_features_color.h" //for __COLOR_HW_SUPPORTED__

#ifdef __MMI_BT_DIALER_SUPPORT__
#include "BtcmSrvGprot.h" 
#endif
/* For 10A*/
#define MMI_EM_CAPTION_1     CUI_INLINE_ITEM_ID_BASE+0
#define MMI_EM_CAPTION_2     CUI_INLINE_ITEM_ID_BASE+1
#define MMI_EM_CAPTION_3     CUI_INLINE_ITEM_ID_BASE+2
#define MMI_EM_CAPTION_4     CUI_INLINE_ITEM_ID_BASE+9
#define MMI_EM_CAPTION_5     CUI_INLINE_ITEM_ID_BASE+16
#define MMI_EM_TEXT_EDIT_1   CUI_INLINE_ITEM_ID_BASE+3
#define MMI_EM_TEXT_EDIT_2   CUI_INLINE_ITEM_ID_BASE+4
#define MMI_EM_TEXT_EDIT_3   CUI_INLINE_ITEM_ID_BASE+5
#define MMI_EM_STR_SELECT_1  CUI_INLINE_ITEM_ID_BASE+6
#define MMI_EM_STR_SELECT_2  CUI_INLINE_ITEM_ID_BASE+7
#define MMI_EM_STR_SELECT_3  CUI_INLINE_ITEM_ID_BASE+8
#define MMI_EM_STR_SELECT_4  CUI_INLINE_ITEM_ID_BASE+10
#define MMI_EM_STR_SELECT_5  CUI_INLINE_ITEM_ID_BASE+11
#define MMI_EM_STR_SELECT_6  CUI_INLINE_ITEM_ID_BASE+12
#define MMI_EM_STR_SELECT_7  CUI_INLINE_ITEM_ID_BASE+13
#define MMI_EM_STR_SELECT_8  CUI_INLINE_ITEM_ID_BASE+14
#define MMI_EM_STR_DISPLAY_ONLY_1 CUI_INLINE_ITEM_ID_BASE+15
#define MMI_EM_STR_SELECT_9  CUI_INLINE_ITEM_ID_BASE+17
#define MMI_EM_STR_SELECT_10  CUI_INLINE_ITEM_ID_BASE+18

#define MMI_EM_DEVICE_COLOR_ARRAY_LEN (3)

/***************************************************************************** 
 * Define
 *****************************************************************************/

/*-----------------------------------------------------------------------------*/
/*----------------------------- Device -> GPIO --------------------------------*/
/*-----------------------------------------------------------------------------*/
#ifdef __MMI_EM_DEV_GPIO__
#ifdef __CUST_NEW__
#define IS_GPO_SET(a)       ((gGPOState & (0x1 << (a & ~GPO_MAGIC_NUM))) >> (a & ~GPO_MAGIC_NUM))
#define GPO_STATE_TOGGLE(a) (gGPOState ^= (0x1 << (a & ~GPO_MAGIC_NUM)))
#else /* __CUST_NEW__ */
#define IS_GPO_SET(a)       ((gGPOState & (0x1 << a)) >> a)
#define GPO_STATE_TOGGLE(a) (gGPOState ^= (0x1 << a))
#endif /* __CUST_NEW__ */ 

U32 gGPOState;

static void mmi_em_gpo_gpio_writeIO(kal_uint8 data, kal_uint8 port, DCL_DEV eDev);
static kal_uint8 mmi_em_gpo_gpio_return_value(kal_uint8 port, DCL_DEV eDev, DCL_CTRL_CMD cmd);
static void mmi_em_gpo_gpio_modesetup(kal_uint16 pin, kal_uint16 conf_dada, DCL_DEV eDev);
#endif/*__MMI_EM_DEV_GPIO__*/
#if defined(__MMI_EM_MISC_HIGHSPEED_SIM__)
/* under construction !*/
#endif /*__MMI_EM_MISC_HIGHSPEED_SIM__*/


/*-----------------------------------------------------------------------------*/
/*----------------------------- Device -> UART --------------------------------*/
/*-----------------------------------------------------------------------------*/
typedef struct
{
    U32 port_tst;
    U32 baud_tst;
    U32 port_ps;
    U32 baud_ps;
    U32 port_tstl1;
    U32 baud_tstl1;
    U32 port_cti;
    U32 baud_cti;
    U32 port_dsp;
    U32 band_dsp;
    U8 app_port_arry[EM_APP_MAX_NUM];
    U8 app_band_arry[EM_APP_MAX_NUM];
    U8	swdbg;
    MMI_BOOL high_speed_sim;
    U8	uart_power_setting;
    mmi_id uart_inline_id;
} mmi_em_dev_set_uart_cntx_struct;

U8 g_EmDevTST_Ouput_mode;
U8 g_em_set_uart_req_type = 0;

/* DCM */
#if defined(__MMI_EM_DEV_DCM_MODE__)
kal_uint16 g_dcm_enable = 1;
#endif /* __MMI_EM_DEV_DCM_MODE__ */

/* Sleep mode */
U8 g_sleep_mode_state = 0;
/* Set UART */
#ifdef __DYNAMIC_UART_PORT_SWITCHING__
static U8 EmSetUartMsgDepth;
static UART_PORT old_tst_port;
static UART_baudrate old_tst_baudrate;
#endif
kal_bool UART_setting;


mmi_em_dev_set_uart_cntx_struct *mmi_em_dev_set_uart_cntx_p = NULL;

#ifndef L4_NOT_PRESENT
#ifdef __DYNAMIC_UART_PORT_SWITCHING__
static UART_PORT old_ps_port;
static UART_baudrate old_ps_baudrate;
#endif /*__DYNAMIC_UART_PORT_SWITCHING__*/
#endif /* L4_NOT_PRESENT */ 

/* USB boot mode */
#ifdef __MMI_EM_DEV_USB_BOOT_MODE__
/* under construction !*/
#endif

#if defined(__MMI_EM_DEV_MEMORY_TEST__)
#include "Emi_sw.h"
#include "info.h"

#define MMI_EM_DEV_MEM_TEST_EMI_SETTING_CONT_TEMP            "EMI [%d]=0x%X"
/* Custom settings
   NOR/NAND:
   FS region base address:
   0xXXXXXXXX
   FS total size: 
   0xXXXXXXXX
   FS first drive size:
   0xXXXXXXXX
   FDM version:
   x.0*/
#define MMI_EM_DEV_MEM_TEST_CUST_SETTING_CONT_TEMP          "%s\n%s\n0x%X\n%s\n0x%X\n%s\n0x%X\n%s\n%d.0\n"
//#define MMI_EM_DEV_MEM_TEST_CUST_SETTING_NOR_CONT_TEMP        "%s\n%s\n0x%X\n%s0x%X Bytss\n%s%d\n%s%d.0\n\n"
//#define MMI_EM_DEV_MEM_TEST_CUST_SETTING_NAND_CONT_TEMP        "%s\n%s\n0x%X\n%s0x%X Bytes\n%s%d\n%s%d.0"
/* Flash physical info
   NOR:
   Device ID: 0xXX 0xXX 0xXX 0xXX 0xXX 0xXX 0xXX 0xXX
   Device size X MB
   Boot mode: 0xX*/
#define MMI_EM_DEV_MEM_TEST_FLASH_INFO_NOR_CONT_TEMP        "%s\n%s%s\n%s%d MB\n%s0x%d\n\n"
/* Flash physical info
   NAND:
   Device ID: 0xXX 0xXX 0xXX 0xXX 0xXX 0xXX 0xXX 0xXX
   Device size X MB
   Page size: X Bytes
   Block size: X Bytes*/
#define MMI_EM_DEV_MEM_TEST_FLASH_INFO_NAND_CONT_TEMP        "%s\n%s%s\n%s%d MB\n%s%d Bytes\n%s%d Bytes"
#define MMI_EM_DEV_MEM_TEST_CUST_SETTING_NOR_START_ADDR        "FS region base address:"
#define MMI_EM_DEV_MEM_TEST_CUST_SETTING_NAND_START_ADDR    "FS region base address:"
#define MMI_EM_DEV_MEM_TEST_CUST_SETTING_LENGTH                "FS total size: "
#define MMI_EM_DEV_MEM_TEST_CUST_SETTING_FIRST_DRV_SIZE     "FS first drive size: "
#define MMI_EM_DEV_MEM_TEST_CUST_SETTING_FDM                "FDM version: "
#define MMI_EM_DEV_MEM_TEST_FLASH_INFO_NOR                    "NOR:"
#define MMI_EM_DEV_MEM_TEST_FLASH_INFO_DEV_SIZE                "Device size: "
#define MMI_EM_DEV_MEM_TEST_FLASH_INFO_DEV_ID                "Device ID: "
#define MMI_EM_DEV_MEM_TEST_FLASH_INFO_BOOT_MODE            "Boot mode: "
#define MMI_EM_DEV_MEM_TEST_FLASH_INFO_NAND                    "NAND:"
#define MMI_EM_DEV_MEM_TEST_FLASH_INFO_PAGE_SIZE            "Page size: "
#define MMI_EM_DEV_MEM_TEST_FLASH_INFO_BLOCK_SIZE            "Block size: "
#define MMI_EM_DEV_MEM_TEST_EMI_SETTING_NEW_LINE            L"\n"
#define MMI_EM_DEV_MEM_TEST_EMI_SETTING_TMP_STR_LEN            64
#define MMI_EM_DEV_MEM_TEST_FLASH_INFO_TMP_STR_LEN            64
#define MMI_EM_DEV_MEM_TEST_CUST_SETTING_BUF_SIZE            512
#define MMI_EM_DEV_MEM_TEST_FLASH_INFO_BUF_SIZE                1024
#endif /* __MMI_EM_DEV_MEMORY_TEST__*/

#ifdef __MMI_EM_FACTORY_LCD_TEST__

extern S32 MAIN_LCD_device_width;
extern S32 MAIN_LCD_device_height;

#define MMI_EM_LCD_TEST_SCREEN_LEFT    0
#define MMI_EM_LCD_TEST_SCREEN_TOP     0
#define MMI_EM_LCD_TEST_SCREEN_RIGHT    (MAIN_LCD_device_width - 1)
#define MMI_EM_LCD_TEST_SCREEN_BOTTOM    (MAIN_LCD_device_height - 1)
#define MMI_EM_LCD_TEST_SCREEN_MID_L_X    0
#define MMI_EM_LCD_TEST_SCREEN_MID_L_Y    (MAIN_LCD_device_height / 2)
#define MMI_EM_LCD_TEST_SCREEN_MID_R_X    MMI_EM_LCD_TEST_SCREEN_RIGHT
#define MMI_EM_LCD_TEST_SCREEN_MID_R_Y    MMI_EM_LCD_TEST_SCREEN_MID_L_Y
#define MMI_EM_LCD_TEST_SCREEN_TILT_GAP   5
#define MMI_EM_LCD_TEST_SCREEN_TILT_WIDTH   3
#define MMI_EM_LCD_TEST_SCREEN_TILT_LEFT    (MMI_EM_LCD_TEST_SCREEN_LEFT + MMI_EM_LCD_TEST_SCREEN_TILT_GAP)
#define MMI_EM_LCD_TEST_SCREEN_TILT_TOP     (MMI_EM_LCD_TEST_SCREEN_TOP + MMI_EM_LCD_TEST_SCREEN_TILT_GAP)
#define MMI_EM_LCD_TEST_SCREEN_TILT_RIGHT   (MMI_EM_LCD_TEST_SCREEN_RIGHT - MMI_EM_LCD_TEST_SCREEN_TILT_GAP)
#define MMI_EM_LCD_TEST_SCREEN_TILT_BOTTOM  (MMI_EM_LCD_TEST_SCREEN_BOTTOM - MMI_EM_LCD_TEST_SCREEN_TILT_GAP)
#define MMI_EM_LCD_TEST_WHITE   (gui_color(255, 255, 255))
#define MMI_EM_LCD_TEST_BLACK   (gui_color(0, 0, 0))
#define MMI_EM_LCD_TEST_R   (gui_color(255, 0, 0))
#define MMI_EM_LCD_TEST_G   (gui_color(0, 255, 0))
#define MMI_EM_LCD_TEST_B   (gui_color(0, 0, 240))
#define MMI_EM_LCD_TEST_GRAY   (gui_color(128, 128, 128))

static lcd_test_mode_enum g_lcd_test_mode;

extern void UI_fill_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, color c);
#ifdef __COLOR_HW_SUPPORTED__
extern void mmi_em_dev_mm_color_select_hdlr(void);
#endif //__COLOR_HW_SUPPORTED__
static void mmi_em_lcd_test_show_initial(void);
static void mmi_em_lcd_test_enter_progress(void);
static void mmi_em_lcd_test_close_progress(void);
static U8 mmi_em_lcd_test_progress_screen_del_handler(void *param);
static void mmi_em_lcd_test_show_test_screen(void);
static U8 mmi_em_lcd_test_screen_del_handler(void *param);
static void mmi_em_lcd_test_show_contrast(void);
static void mmi_em_lcd_test_show_tilt(void);
static void mmi_em_lcd_test_show_color(void);
static void mmi_em_lcd_test_led_test(MMI_BOOL is_on);
static void mmi_em_lcd_set_led_req(U8 type, U8 level);
static void mmi_em_lcd_test_show_rgb(lcd_test_mode_enum mode);
#endif /* __MMI_EM_FACTORY_LCD_TEST__ */ 

#if defined(__MMI_EM_DEV_USB_OTG_SRP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*-----------------------------------------------------------------------------*/
/*----------------------------- Device -> USB Tethering -----------------------*/
/*-----------------------------------------------------------------------------*/
#ifdef __MMI_EM_DEV_USB_TETHERING__
static void mmi_em_dev_usb_tethering_scrn(void);
static mmi_ret mmi_em_dev_usb_tethering_proc(mmi_event_struct* evt);
#endif

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
extern U8 currentHighlightIndex;
extern PU8 subMenuDataPtrs[MAX_SUB_MENUS];
extern U8 subMenuData[MAX_SUB_MENUS][MAX_SUB_MENU_SIZE];

/* Set UART */
#ifndef L4_NOT_PRESENT
extern UART_PORT PS_UART_PORT;
extern UART_baudrate PS_BAUDRATE;
#endif /* L4_NOT_PRESENT */ 

#if defined(__MMI_EM_DEV_USB_LOGGING__)
/* under construction !*/
/* under construction !*/
#endif 

/* UART POWER ON */
/* HAL rule*/
//extern kal_uint8 UART_POWER_SETTING;
//extern kal_uint8 SWDBG_Profile;
//extern kal_bool High_Speed_SIM;
extern U8 g_EmDevTST_Ouput_mode;
extern wgui_inline_item wgui_inline_items[];
extern UART_PORT TST_PORT;
extern UART_baudrate TST_BAUDRATE;

/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
extern void mmi_em_enter_pxs_sensor_hdlr(void);
extern void IdleScreenChargerConnected(U8 playtone);
extern void IdleScreenChargerDisconnected(void);
extern void IdleScreenBatteryFullCharged(void);
extern void BatteryStatusIndication(U8 battery_voltage);
extern S8 *release_verno(void);
#if defined(__MMI_EM_MOBILE_TV_SETTING__)
extern void mmi_em_mtv_entry_setting_scr(void);
#endif /* __MMI_EM_MOBILE_TV_SETTING__ */
extern void mmi_em_misc_entry_high_speed_sim(void);
extern void mmi_em_motion_sensor_entry(void);
#define EM_DEV
/***********************************************
 ** Device main menu
 ***********************************************/
static void mmi_em_dev_menu_hdlr(mmi_id menu_gid);

/***********************************************
 ** Menu Tree: Device -> Gpio
 ***********************************************/
#ifdef __MMI_EM_DEV_GPIO__
static mmi_ret mmi_em_dev_gpio_list_proc(mmi_event_struct *param);
static void mmi_em_device_set_certain(MMI_BOOL is_accept, U32 output_num, MMI_ID editor_gid, void* user_data);
static void mmi_em_device_set_gpio_hdlr(void);
static MMI_RET mmi_em_device_set_gpio_proc(mmi_event_struct* evt);
static void mmi_em_device_set_gpio_inline(void);
static void mmi_em_device_gpo_gpio_set_hdlr(U8 action_type, U16 title_id);
static void mmi_em_device_set_select_num(void);
#endif/*__MMI_EM_DEV_GPIO__*/


/***********************************************
 ** Menu Tree: Device --> Eint
 ***********************************************/
#if defined(__MMI_EM_DEV_EINT__)
static void mmi_em_dev_eint_prepare_lint(void);
static U8 mmi_em_dev_eint_gpio_recv_hdlr(void *inMsg);
//static void mmi_em_dev_eint_battery_recv_hdlr(void *inMsg);
static void mmi_em_dev_eint_exit_menu(void);
static void mmi_em_device_eint(void);
#endif

/***********************************************
 ** Menu Tree: Device --> adc
 ***********************************************/
#if 0 //__MMI_EM_DEV_ADC__ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif/*__MMI_EM_DEV_ADC__*/

/***********************************************
 ** Menu Tree: Device --> hw level
 ***********************************************/
#ifdef __MMI_EM_DEV_SET_HW_LEVEL__









static void mmi_em_device_change_hw_level_hdlr(void);
static void mmi_em_device_hw_level_detail_scrn(void);
static void mmi_em_device_hw_level_enter_detail_scrn(U16 menu_id, U16 str_id);
static MMI_BOOL mmi_em_device_check_hw_level_info_dirty_hdlr(void);
static MMI_BOOL EmHWLevelInfoAccess(U16 Type, U8 Item, U8 action, U32 *value);
static void mmi_em_device_enter_hwlist_proc(MMI_BOOL is_first_enter);
static void mmi_em_device_change_hw_level_notify(MMI_BOOL is_accept, U32 output_num, MMI_ID editor_gid, void* user_data);
static MMI_RET mmi_em_dev_hw_level_update_proc(mmi_event_struct *evt);
static void SendSetHWLevelInfoReq(void);

#endif/*__MMI_EM_DEV_SET_HW_LEVEL__*/

/***********************************************
 ** Menu Tree: Device --> momery
 ***********************************************/
#ifdef __MMI_EM_DEV_MEMORY_TEST__
static void mmi_em_dev_memory_test_emi_setting(void);
static void mmi_em_dev_memory_test_custom_setting(void);
static void mmi_em_dev_memory_test_flash_info(void);
static U16* mmi_em_dev_memory_test_compose_emi_setting_text(MEM_DEV_INFO_T *mem_info);
static U16* mmi_em_dev_memory_test_compose_custom_setting_text(MEM_DEV_INFO_T *mem_info);
static U16* mmi_em_dev_memory_test_compose_flash_info_text(MEM_DEV_INFO_T *mem_info);
#endif /* __MMI_EM_DEV_MEMORY_TEST__ */

/***********************************************
 ** Menu Tree: Device --> nand format
 ***********************************************/
#if defined(__MMI_EM_DEV_NAND_FORMAT__)
/* under construction !*/
/* under construction !*/
#endif


/***********************************************
 ** Menu Tree: Device --> tst output
 ***********************************************/
#ifdef __MMI_EM_DEV_TST_OUTPUT_MODE__
static void mmi_em_dev_tst_output_scrn(void);
static MMI_RET mmi_em_dev_tst_output_hdlr(cui_menu_event_struct *evt);
static void EmDevSetTSTOutputMode(void);
static void mmi_em_dev_set_tst_output_mode_send_uart_req(void* data);
#endif /* __MMI_EM_DEV_TST_OUTPUT_MODE__ */

/***********************************************
 ** Menu Tree: Device --> USB logging
 ***********************************************/
#if defined(__MMI_EM_DEV_USB_LOGGING__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_EM_DEV_USB_LOGGING__ */

/***********************************************
 ** Menu Tree: Device --> Dcm mode
 ***********************************************/
#ifdef __MMI_EM_DEV_DCM_MODE__
static void mmi_em_device_set_dcm_mode_hdlr(MMI_ID menu_id);
static void EngineerModeSetDCMModeReq(U16 is_on);
#endif /* __MMI_EM_DEV_DCM_MODE__ */

/***********************************************
 ** Menu Tree: Device --> Set uart
 ***********************************************/
 #ifdef __MMI_EM_DEV_SET_UART__
static void SendSetUartReq(void);
static void mmi_em_set_hilit_port(U32 *port);
static EM_SET_UART_INLINE mmi_em_get_highlight_port(U32 port);
static BOOL EmIsPortAllow(U8 port_num);

static void mmi_em_dev_uart_map_dev_port_to_mmi_port(
                U32 *highligh, EM_APP_UART_SETTING port_enum, 
                U32 range, U8* app_port_arry, 
                U32 *band, U8* app_band_arry);

static void mmi_em_dev_uart_map_mmi_port_to_dev_port(
                U32 highlight, EM_APP_UART_SETTING port_enum,
                U32 range, U8* app_port_arry,
                U32 band, U8* app_band_arry);


static void mmi_em_device_uart_setting_scrn(void);
static void mmi_em_device_uart_setting_hdlr(void);
static void mmi_em_dev_set_uart_req_hdlr(void* data);
static MMI_RET mmi_em_device_uart_setting_proc(mmi_event_struct *evt);
#endif
#ifdef __DYNAMIC_UART_PORT_SWITCHING__
static void mmi_em_dev_set_uart_close_inline(void);
#endif

/* sleep mode */
#ifdef __MMI_EM_DEV_SLEEP_MODE__
static void mmi_em_device_set_sleep_mode_hdlr(MMI_ID menu_id);
#endif

#ifdef __MMI_EM_DEV_PMU_REGISTER_SETTING__
static void mmi_em_dev_pmu_reg_enter_scrn(void);
#endif

#ifdef __MMI_EM_DEV_BACKLIGHT__
extern kal_uint32 custom_uem_get_bl_level_num(void);
extern kal_uint32 custom_uem_get_pwm_bl_mode(kal_uint8 gpio_dev_type);
#endif

/*-----------------------------------------------------------------------------*/
/*----------------------------- Device main menu ------------------------------*/
/*-----------------------------------------------------------------------------*/
static void mmi_em_dev_menu_hdlr(mmi_id menu_gid)
{
    mmi_menu_id menu_id = 0;
    
    
    if (nvram_sec_port_is_enable() == KAL_FALSE)
    {
    #ifdef __MMI_EM_DEV_TST_OUTPUT_MODE__
        menu_id = MENU_ID_EM_DEV_TST_OUTPUT_MODE;
    #endif /* __MMI_EM_DEV_TST_OUTPUT_MODE__ */

    #ifdef __MMI_EM_DEV_USB_LOGGING__
/* under construction !*/
    #endif /* __MMI_EM_DEV_USB_LOGGING__ */
    }
    
    if (menu_id != 0)
    {
        cui_menu_delete_currlist_menuid(menu_gid, menu_id);
    }

#ifdef __MMI_EM_DEV_BACKLIGHT__
    if (!custom_uem_get_pwm_bl_mode(GPIO_DEV_LED_MAINLCD))
    {
        cui_menu_delete_currlist_menuid(menu_gid, MENU_ID_EM_DEV_BACKLIGHT);
    }
#endif
}


#define EM_DEVICE_GPIO
/*-----------------------------------------------------------------------------*/
/*----------------------------- Device -> GPIO --------------------------------*/
/*-----------------------------------------------------------------------------*/
#ifdef __MMI_EM_DEV_GPIO__
#define MMI_EM_DEV_GPIO_SET_LIST_FLAG(_idx, _flag) \
    do { \
        (_flag) = (_flag) | (0x00000001) << (_idx); \
    } while(0)

#define MMI_EM_DEV_GPIO_RESET_LIST_FLAG(_idx, _flag) \
    do { \
       (_flag) = (_flag) & (~((0x00000001) << (_idx))); \
    } while(0)

#define MMI_EM_DEV_GPIO_GET_LIST_FLAG(_idx, _flag) (_flag) & ((0x00000001) << (_idx))

typedef struct
{
    S32 highlight_index;
    U32 menu_list_mum;
    S32 gport;
    S32 direction;
    S32 level;
    S32 mode;
    U8 EmGpioIdxMenu2Tbl[30];
    U8 gpio_action;
    WCHAR title_name[20];
} mmi_em_dev_gpio_cnxt_struct;

mmi_em_dev_gpio_cnxt_struct *mmi_em_dev_gpio_cnxt_p = NULL;

U32 mmi_em_dev_gpio_gpo_list_flag = 0;

static const DCL_CTRL_CMD_T g_mmi_em_gpio_mode[] =
{
    GPIO_CMD_SET_MODE_0,
    GPIO_CMD_SET_MODE_1,
    GPIO_CMD_SET_MODE_2,
    GPIO_CMD_SET_MODE_3,
    GPIO_CMD_SET_MODE_4,
    GPIO_CMD_SET_MODE_5,
    GPIO_CMD_SET_MODE_6,
    GPIO_CMD_SET_MODE_7
};

static const DCL_CTRL_CMD_T g_gpo_cmd_mode_set_id[] = {
                     GPO_CMD_MODE_SET_0,
                     GPO_CMD_MODE_SET_1,
                     GPO_CMD_MODE_SET_2,
                     GPO_CMD_MODE_SET_3
                 };

MMI_EM_INIT_ASM(dev_gpio, mmi_em_dev_gpio_cnxt_p, sizeof(mmi_em_dev_gpio_cnxt_struct))

static void mmi_em_dev_gpio_hdlr(void)
{
    MMI_EM_ASM_INIT_FUNC(dev_gpio);
    gGPOState = 0x0;
}

static void mmi_em_gpio_start(kal_uint8 port);
static void mmi_em_gpo_start(kal_uint8 port);
static void mmi_em_gpio_writeIO(kal_uint8 data, kal_uint8 port);
static void mmi_em_gpo_writeIO(kal_uint8 data,kal_uint8 port);

/***********************************************
 ** Menu Tree: Device --> Gpio list
 ***********************************************/
/*****************************************************************************
 * FUNCTION
 *  HighlightOnCertainEmGPIO
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightOnCertainEmGPIO(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 Idx = 0;
    U16 left_key_str = 0;
    U32 bit_flag = 0;
    gpio_measure_map_entry_struct gpio_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Idx = mmi_em_dev_gpio_cnxt_p->EmGpioIdxMenu2Tbl[mmi_em_dev_gpio_cnxt_p->highlight_index];
    
    bit_flag = MMI_EM_DEV_GPIO_GET_LIST_FLAG(mmi_em_dev_gpio_cnxt_p->highlight_index, mmi_em_dev_gpio_gpo_list_flag);

    if (!gpio_measure_get_item_by_idx(Idx, &gpio_item))
    {
        return;
    }
    
    if (((gpio_item.is_vaild == GPIO_VAILD) && bit_flag)
        || ((gpio_item.is_vaild == GPO_VAILD) && IS_GPO_SET(gpio_item.port)))
    {
        left_key_str = STR_GLOBAL_OFF;
    }
    else if ((gpio_item.is_vaild == GPIO_VAILD) || (gpio_item.is_vaild == GPO_VAILD))
    {
        left_key_str = STR_GLOBAL_ON;
    }
    else
    {
        left_key_str = STR_GLOBAL_ERROR;
    }
    
    change_left_softkey(left_key_str, 0);

    redraw_left_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  EmPrepareGPIOList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmPrepareGPIOList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j = 0;
    U32 *list_num = &mmi_em_dev_gpio_cnxt_p->menu_list_mum;
    gpio_measure_map_entry_struct gpio_item;
    U32 gpio_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *list_num = 0;
    gpio_num = gpio_measure_get_total_num();
    for (i = 0; i < gpio_num; i++)
    {
        if (gpio_measure_get_item_by_idx(i, &gpio_item))
    {
            if (gpio_item.is_vaild == GPIO_VAILD)
        {
            mmi_em_dev_gpio_cnxt_p->EmGpioIdxMenu2Tbl[j] = (U8) i;
            j++;
                kal_wsprintf((WCHAR*)subMenuData[*list_num], "%s", gpio_item.name);
            subMenuDataPtrs[*list_num] = subMenuData[*list_num];
            (*list_num)++;
        }
    }
}
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmGPIOListMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_dev_gpio_list_menu_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_create(
        mmi_em_get_root_group(),
        SCR_ID_EM_DEV_GPIO_LIST,
        mmi_em_dev_gpio_list_proc, NULL);
}

static mmi_ret mmi_em_dev_gpio_list_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_frm_scrn_active_evt_struct *active_evt = (mmi_frm_scrn_active_evt_struct *)param;
            U32 *num_of_items = &mmi_em_dev_gpio_cnxt_p->menu_list_mum;
            
            EmPrepareGPIOList();
            
            if (*num_of_items < 1)
            {
                (*num_of_items)++;
            }
    
            ShowCategory6Screen(
                STR_ID_EM_DEV_GPIO_LIST_GPO_GPIO,
                0,
                STR_GLOBAL_OK, 0,
                STR_GLOBAL_BACK, 0,
                (*num_of_items),
                (PU8*) subMenuDataPtrs,
                NULL, 0,
                active_evt->gui_buffer);
           
            break;
        }

        case EVT_ID_WGUI_LSK_CLICK:
        {   
            if (mmi_em_dev_gpio_cnxt_p->menu_list_mum >= 1)
            {
                LSKEmGPIOListMenu();
                return MMI_RET_KEY_HANDLED;
            }
            break;
        }

        case EVT_ID_SCRN_HIGHLIGHT_CHANGE:
        {
            cat_evt_struct *cat_evt = (cat_evt_struct *)param;
            HighlightOnCertainEmGPIO(cat_evt->item_index);
            return MMI_RET_CHANGED;
        }

        default:
            break;
    }
    
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  LSKEmGPIOListMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void LSKEmGPIOListMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = mmi_em_dev_gpio_cnxt_p->highlight_index;
    U8 Idx = mmi_em_dev_gpio_cnxt_p->EmGpioIdxMenu2Tbl[index];
    gpio_measure_map_entry_struct gpio_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gpio_measure_get_item_by_idx(Idx, &gpio_item))
    {
        return;
    }
    
    switch (gpio_item.is_vaild)
    {
        case GPIO_VAILD:
        {
            mmi_em_common_set_left_softkey(!(MMI_EM_DEV_GPIO_GET_LIST_FLAG(index, mmi_em_dev_gpio_gpo_list_flag)));
            mmi_em_gpio_start(gpio_item.port);
            if (mmi_em_dev_gpio_gpo_list_flag)
                MMI_EM_DEV_GPIO_RESET_LIST_FLAG(index, mmi_em_dev_gpio_gpo_list_flag);
            else
                MMI_EM_DEV_GPIO_SET_LIST_FLAG(index, mmi_em_dev_gpio_gpo_list_flag);
            break;
        }

        case GPO_VAILD:
        {            
            mmi_em_common_set_left_softkey(!(IS_GPO_SET(gpio_item.port)));
            mmi_em_gpo_start(gpio_item.port);
            GPO_STATE_TOGGLE(gpio_item.port);
            break;
        }

        default:
            break;
    }

}


#define EM_DEVICE_GPIO_Set
/***********************************************
 ** Menu Tree: Device --> Gpio/gpo set
 ***********************************************/
static const cui_inline_item_caption_struct g_mmi_em_gpio_cap = 
{
    STR_ID_EM_DEV_GPIO,
};

static const cui_inline_item_caption_struct g_mmi_em_gpio_cur_level_cap = 
{
    STR_ID_EM_DEV_GPIO_LEVEL,
};

static const U16 g_mmi_em_gpio_level_str[] = 
{
    STR_GLOBAL_LOW, 
    STR_GLOBAL_HIGH
};

static const cui_inline_item_select_struct g_mmi_em_gpio_level_select = 
{
    2, 0, (U16*)g_mmi_em_gpio_level_str,
};

static const cui_inline_item_caption_struct g_mmi_em_gpio_mode_cap = 
{
    STR_GLOBAL_MODE,
};

static const U16 g_mmi_em_gpio_mode_str[] = 
{
    STR_GLOBAL_0, 
    STR_GLOBAL_1,
    STR_GLOBAL_2, 
    STR_GLOBAL_3
};

static const cui_inline_item_select_struct g_mmi_em_gpio_mode_select = 
{
    4, 0, (U16*)g_mmi_em_gpio_mode_str,
};

static const cui_inline_item_caption_struct g_mmi_em_gpio_dirc_cap = 
{
    STR_ID_EM_DEV_GPIO_DIRECTION,
};

static const U16 g_mmi_em_gpio_dirc_str[] = 
{
    STR_ID_EM_DEV_GPIO_DIRECTION_OUT, 
    STR_ID_EM_DEV_GPIO_DIRECTION_IN
};

static cui_inline_item_select_struct g_mmi_em_gpio_dirc_select = 
{
    2, 0, (U16*)g_mmi_em_gpio_dirc_str,
};

static const cui_inline_set_item_struct g_mmi_em_gpio_inline[7] = 
{
    {MMI_EM_CAPTION_1, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_gpio_cap},
    {MMI_EM_CAPTION_2, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_gpio_cur_level_cap},
    {MMI_EM_STR_SELECT_1, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_gpio_level_select},
    {MMI_EM_CAPTION_3, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_gpio_mode_cap},
    {MMI_EM_STR_SELECT_2, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_gpio_mode_select},
    {MMI_EM_CAPTION_4, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_gpio_dirc_cap},
    {MMI_EM_STR_SELECT_3, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_gpio_dirc_select},
};

static cui_inline_struct g_mmi_em_gpio_inline_screen = 
{
    7,
    STR_ID_EM_DEV_GPIO_EDIT_GPIO,
    0,
    CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    (const cui_inline_set_item_struct*)&g_mmi_em_gpio_inline,
};

static void mmi_em_device_set_gpio_inline(void)
{
    U16 string_id;
    MMI_ID gpio_gid;
    MMI_ID gpio_inline_id;
    WCHAR *title_name = mmi_em_dev_gpio_cnxt_p->title_name;
    S32 *direction = &mmi_em_dev_gpio_cnxt_p->direction;
    S32 *level = &mmi_em_dev_gpio_cnxt_p->level;
    S32 *mode = &mmi_em_dev_gpio_cnxt_p->mode;
    
    
    gpio_gid = mmi_frm_group_create_ex(mmi_em_get_root_group(),
                   GRP_ID_AUTO_GEN, 
                   mmi_em_device_set_gpio_proc, NULL,
                   MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_em_device_set_select_num();
    gpio_inline_id = cui_inline_create(gpio_gid, &g_mmi_em_gpio_inline_screen);

    if (mmi_em_dev_gpio_cnxt_p->gpio_action)
    {
        kal_wsprintf((WCHAR*)title_name, "GPIO %d", mmi_em_dev_gpio_cnxt_p->gport);
        string_id = STR_ID_EM_DEV_GPIO_EDIT_GPIO;
    }
    else
    {
        kal_wsprintf((WCHAR*)title_name, "GPO %d", mmi_em_dev_gpio_cnxt_p->gport);
        string_id = STR_ID_EM_DEV_GPIO_EDIT_GPO;
        cui_inline_set_item_attributes(gpio_inline_id, MMI_EM_STR_SELECT_3, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);
    }

    cui_inline_set_value(gpio_inline_id, MMI_EM_STR_SELECT_1, (void *) *level);
    cui_inline_set_value(gpio_inline_id, MMI_EM_STR_SELECT_2, (void *) *mode);
    cui_inline_set_value(gpio_inline_id, MMI_EM_STR_SELECT_3, (void *) *direction);
    
    cui_inline_set_title_string_with_string_id(gpio_inline_id, string_id);
    cui_inline_set_value(gpio_inline_id, MMI_EM_CAPTION_1, (void*)title_name);
    cui_inline_run(gpio_inline_id);
}

static void mmi_em_device_set_select_num(void)
{
    g_mmi_em_gpio_dirc_select.n_items = mmi_em_dev_gpio_cnxt_p->gpio_action ? 2 : 1;
}

static MMI_RET mmi_em_device_set_gpio_proc(mmi_event_struct* evt)
{
    S32 *direction = &mmi_em_dev_gpio_cnxt_p->direction;
    S32 *level = &mmi_em_dev_gpio_cnxt_p->level;
    S32 *mode = &mmi_em_dev_gpio_cnxt_p->mode;
    cui_event_inline_common_struct* inline_evt = (cui_event_inline_common_struct*) evt;

    switch (inline_evt->evt_id)
    {
    case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_CSK_PRESS:
         cui_inline_get_value(inline_evt->sender_id, MMI_EM_STR_SELECT_1, (void *) level);
         cui_inline_get_value(inline_evt->sender_id, MMI_EM_STR_SELECT_2, (void *) mode);
         cui_inline_get_value(inline_evt->sender_id, MMI_EM_STR_SELECT_3, (void *) direction);
         mmi_em_device_set_gpio_hdlr();
         cui_inline_close(inline_evt->sender_id);
         break;
         
    case EVT_ID_CUI_INLINE_ABORT:
         cui_inline_close(inline_evt->sender_id);
         break;

    default:
        break;        
    }

    return MMI_RET_OK;
}

static void mmi_em_device_set_gpio_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 *gport = &mmi_em_dev_gpio_cnxt_p->gport;
    S32 *level = &mmi_em_dev_gpio_cnxt_p->level;
    S32 *mode = &mmi_em_dev_gpio_cnxt_p->mode;
    DCL_DEV eDev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (KAL_TRUE == mmi_em_dev_gpio_cnxt_p->gpio_action)
    {
#ifdef __CUST_NEW__
        *gport = *gport | GPIO_MAGIC_NUM;
#endif
        eDev = DCL_GPIO;
    }
    else
    {
#ifdef __CUST_NEW__
        *gport = *gport | GPO_MAGIC_NUM;
#endif
        eDev = DCL_GPO;
    }
    
    mmi_em_gpo_gpio_modesetup((kal_uint16) *gport, (kal_uint16) *mode, eDev);
    mmi_em_gpo_gpio_writeIO((kal_uint8)*level, (kal_uint8)*gport, eDev);
    mmi_em_success_popup();
}

static void mmi_em_device_gpo_gpio_set_hdlr(U8 action_type, U16 title_id)
{
    mmi_em_num_editor_struct info = {0};


    info.title_id = title_id;
    info.notify = mmi_em_device_set_certain;
    mmi_em_dev_gpio_cnxt_p->highlight_index= action_type;
    mmi_em_show_num_editor(&info);
}

static void mmi_em_device_set_certain(MMI_BOOL is_accept, U32 output_num, MMI_ID editor_gid, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 Arg = (S8)output_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Lisen 0906 */
    if (Arg >= GPIO_LABELID_MAX /* || Arg <= 0 */ )
    {
        mmi_em_fail_popup();
        return;
    }

    mmi_em_dev_gpio_cnxt_p->gport = Arg;

    switch (mmi_em_dev_gpio_cnxt_p->highlight_index)
    {
        case SET_GPIO_ACTION:
            mmi_em_dev_gpio_cnxt_p->direction = mmi_em_gpo_gpio_return_value(Arg, DCL_GPIO, GPIO_CMD_RETURN_DIR);
            mmi_em_dev_gpio_cnxt_p->level = mmi_em_gpo_gpio_return_value(Arg, DCL_GPIO, GPIO_CMD_RETURN_OUT);
            mmi_em_dev_gpio_cnxt_p->mode = mmi_em_gpo_gpio_return_value(Arg, DCL_GPIO, GPIO_CMD_RETURN_MODE);
            mmi_em_dev_gpio_cnxt_p->gpio_action= KAL_TRUE;
            mmi_em_device_set_gpio_inline();
            break;

        case SET_GPO_ACTION:
            mmi_em_dev_gpio_cnxt_p->direction = mmi_em_gpo_gpio_return_value(Arg, DCL_GPIO, GPIO_CMD_RETURN_DIR);
            mmi_em_dev_gpio_cnxt_p->level = mmi_em_gpo_gpio_return_value(Arg, DCL_GPO, GPO_CMD_RETURN_OUT);
            mmi_em_dev_gpio_cnxt_p->mode = mmi_em_gpo_gpio_return_value(Arg, DCL_GPO, GPO_CMD_RETURN_MODE);
            mmi_em_dev_gpio_cnxt_p->gpio_action= KAL_FALSE;
            mmi_em_device_set_gpio_inline();
            break;

        default:
            break;
    }    
}


static void mmi_em_gpo_gpio_writeIO(kal_uint8 data, kal_uint8 port, DCL_DEV eDev)
{
    DCL_HANDLE handle;
    DCL_CTRL_CMD cmd;
    
    handle=DclGPIO_Open(eDev, port);
    
    if (eDev == DCL_GPO)
    {
        cmd = (1 == data) ? GPO_CMD_WRITE_HIGH : GPO_CMD_WRITE_LOW;
    }
    else
    {
        cmd = (1 == data) ? GPIO_CMD_WRITE_HIGH : GPIO_CMD_WRITE_LOW;
    }
    DclGPIO_Control(handle, cmd, 0);
    DclGPIO_Close(handle);
}

static kal_uint8 mmi_em_gpo_gpio_return_value(kal_uint8 port, DCL_DEV eDev, DCL_CTRL_CMD cmd)
{
    DCL_HANDLE handle;
    DCL_CTRL_DATA_T data = {0};
    kal_uint8 return_value = 0;
    
    
    handle = DclGPIO_Open(eDev, port);
    DclGPIO_Control(handle, cmd, &data);
    switch (cmd)
    {
        case GPO_CMD_RETURN_MODE:
            return_value = data.oReturnMode.u1RetMode;
            break;
            
        case GPO_CMD_RETURN_OUT:
            return_value = data.oReturnOut.u1RetOutData;
            break;
            
        case GPIO_CMD_RETURN_DIR:
            return_value = data.rReturnDir.u1RetDirData;
            break;
            
        case GPIO_CMD_RETURN_MODE:
            return_value = data.rReturnMode.u1RetMode;;
            break;
            
        case GPIO_CMD_RETURN_OUT:
            return_value = data.rReturnOut.u1RetOutData;
            break;
    }
    DclGPIO_Close(handle);
    return return_value;
}

static void mmi_em_gpo_gpio_modesetup(kal_uint16 pin, kal_uint16 conf_dada, DCL_DEV eDev)
{
    DCL_HANDLE handle;


    handle=DclGPIO_Open(eDev, pin);
    
    if (eDev == DCL_GPO)
    {
        if (conf_dada <= 3)
        {
            DclGPIO_Control(handle, g_gpo_cmd_mode_set_id[conf_dada], 0);
        }
    }
    else
    {
        DclGPIO_Control(handle,g_mmi_em_gpio_mode[conf_dada],0);
    }
    DclGPIO_Close(handle);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_gpio_start
 * DESCRIPTION
 *
 * PARAMETERS
 *  port        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_gpio_start(kal_uint8 port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_gpio_writeIO(1, port);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_gpo_start
 * DESCRIPTION
 *
 * PARAMETERS
 *  port        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_gpo_start(kal_uint8 port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_gpo_writeIO(1, port);
}

static void mmi_em_gpio_writeIO(kal_uint8 data, kal_uint8 port)
{
	DCL_HANDLE handle;
    
	handle=DclGPIO_Open(DCL_GPIO, port);	

    if(0 == data)
		DclGPIO_Control(handle,GPIO_CMD_WRITE_LOW,0);
	else if(1 == data)
		DclGPIO_Control(handle,GPIO_CMD_WRITE_HIGH,0);
	
	DclGPIO_Close(handle);	
}

static void mmi_em_gpo_writeIO(kal_uint8 data,kal_uint8 port)
{
	DCL_HANDLE handle;
    
	handle=DclGPIO_Open(DCL_GPO,port);	

    if(0 == data)
		DclGPIO_Control(handle,GPO_CMD_WRITE_LOW,0);
	else if(1 == data)
		DclGPIO_Control(handle,GPO_CMD_WRITE_HIGH,0);

	DclGPIO_Close(handle);
}

#endif/*__MMI_EM_DEV_GPIO__*/

/*-----------------------------------------------------------------------------*/
/*------------------------------ Device -> Backlight -----------------------------*/
/*-----------------------------------------------------------------------------*/
#ifdef __MMI_EM_DEV_BACKLIGHT__

#include "custom_hw_default.h"

#define MMI_EM_DEV_BACKLIGHT_ITEM_NUM   6
#define MMI_EM_DEV_BACKLIGHT_BUF_LEN    3
#define MMI_EM_DEV_BACKLIGHT_FREQ_BUF_LEN    6
#define MMI_EM_DEV_BACKLIGHT_LEVEL_STR_NUM  100
#define MMI_EM_DEV_BACKLIGHT_MAX_FREQ   PWM_MAX_FREQ
#define MMI_EM_DEV_BACKLIGHT_MIN_FREQ   PWM_MIN_FREQ
#define MMI_EM_DEV_BACKLIGHT_MAX_DUTY   PWM_MAX_DUTY
#define MMI_EM_DEV_BACKLIGHT_MIN_DUTY   PWM_MIN_DUTY
#define MMI_EM_DEV_BACKLIGHT_INVALID_POPUP_TEXT_LEN 40

typedef struct
{
    U32 pwm;
    U32 max_level;
    U32 level;
    U32 freq;
    U32 duty;
    mmi_id inline_id;
    WCHAR freq_buf[MMI_EM_DEV_BACKLIGHT_FREQ_BUF_LEN + 1];
    WCHAR duty_buf[MMI_EM_DEV_BACKLIGHT_BUF_LEN + 1];
    WCHAR level_str[MMI_EM_DEV_BACKLIGHT_LEVEL_STR_NUM][MMI_EM_DEV_BACKLIGHT_BUF_LEN];
    WCHAR *level_str_list[MMI_EM_DEV_BACKLIGHT_LEVEL_STR_NUM];
    U32 pwm_new[1][2];
} mmi_em_dev_backlight_cntx_struct;

mmi_em_dev_backlight_cntx_struct *mmi_em_dev_backlight_cntx_p;

MMI_EM_INIT_ASM(dev_backlight, mmi_em_dev_backlight_cntx_p, 
    sizeof(mmi_em_dev_backlight_cntx_struct) + sizeof(U32)*pwm_measure_backlight_get_max_level()*2)

static const cui_inline_item_caption_struct g_mmi_em_backlight_level_cap = 
{
    STR_ID_EM_DEV_BACKLIGHT_LEVEL
};

static const cui_inline_item_caption_struct g_mmi_em_backlight_freq_cap = 
{
    STR_ID_EM_DEV_BACKLIGHT_FREQ
};

static const cui_inline_item_text_edit_struct g_mmi_em_backlight_freq_edit =
{
    0, 0, MMI_EM_DEV_BACKLIGHT_FREQ_BUF_LEN+1, IMM_INPUT_TYPE_NUMERIC, 0, NULL,
};

static const cui_inline_item_caption_struct g_mmi_em_backlight_duty_cap = 
{
    STR_ID_EM_DEV_BACKLIGHT_DUTY,
};

static const cui_inline_item_text_edit_struct g_mmi_em_backlight_duty_edit =
{
    0, 0, MMI_EM_DEV_BACKLIGHT_BUF_LEN+1, IMM_INPUT_TYPE_NUMERIC, 0, NULL,
};

static const cui_inline_set_item_struct g_mmi_em_backlight_inline[] = 
{
    {MMI_EM_CAPTION_1,        CUI_INLINE_ITEM_TYPE_CAPTION,    IMG_STATUS,  (void*)&g_mmi_em_backlight_level_cap},
    {MMI_EM_STR_SELECT_1,   CUI_INLINE_ITEM_TYPE_SELECT,      0,                   (void*)NULL}, //&g_mmi_em_backlight_level_select},
    {MMI_EM_CAPTION_2,        CUI_INLINE_ITEM_TYPE_CAPTION,    IMG_STATUS,  (void*)&g_mmi_em_backlight_freq_cap},
    {MMI_EM_TEXT_EDIT_1,     CUI_INLINE_ITEM_TYPE_TEXT_EDIT,  0,                   (void*)&g_mmi_em_backlight_freq_edit},
    {MMI_EM_CAPTION_3,        CUI_INLINE_ITEM_TYPE_CAPTION,    IMG_STATUS,   (void*)&g_mmi_em_backlight_duty_cap},
    {MMI_EM_TEXT_EDIT_2,     CUI_INLINE_ITEM_TYPE_TEXT_EDIT,  0,                    (void*)&g_mmi_em_backlight_duty_edit},
};

static const cui_inline_struct g_mmi_em_backlight_inline_scrn = 
{
    MMI_EM_DEV_BACKLIGHT_ITEM_NUM,
    STR_ID_EM_DEV_BACKLIGHT,
    0,
    CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    (const cui_inline_set_item_struct*)&g_mmi_em_backlight_inline,
};

static void mmi_em_dev_enter_backlight(void);
static MMI_RET mmi_em_device_backlightl_proc(mmi_event_struct* evt);
static MMI_BOOL mmi_em_device_backlight_set_hdlr(MMI_ID parent_id);
static MMI_BOOL mmi_em_device_backlight_all_level_valid(U32 *level, U32 *item);
static void mmi_em_device_backlight_invalid_popup(U32 level, U32 item);
static void mmi_em_device_backlight_select_notify(MMI_ID parent_id);
static void mmi_em_device_backlight_set_pwm(U32 level, U32 freq, U32 duty);
static void mmi_em_device_backlight_send_set_hw_level_req(void);
static void mmi_em_device_backlight_update_bl(MMI_ID parent_id);
static void mmi_em_device_backlight_abort(void);

extern void custom_pwm_configure(kal_uint8 gpio_dev_type, kal_uint32 level, kal_uint32 freq, kal_uint32 duty);

static void mmi_em_dev_backlight_hdlr(void)
{
    MMI_EM_ASM_INIT_FUNC(dev_backlight);
    mmi_em_dev_enter_backlight();
}

static void mmi_em_dev_enter_backlight(void)
{
    MMI_ID gid;
    MMI_ID inline_id;
    U32      i;
    mmi_em_dev_backlight_cntx_struct *cntx = mmi_em_dev_backlight_cntx_p;
    U32 max_level = pwm_measure_backlight_get_max_level();
    pwm_measure_level_info_struct pwm_info;
    
    /* Get max levels*/
    cntx->max_level = custom_uem_get_bl_level_num();
    /* Which PWM control backlight*/
    cntx->pwm = custom_uem_get_pwm_bl_mode(GPIO_DEV_LED_MAINLCD) - 1;

//    kal_prompt_trace(MOD_MMI, "[EM] PWM%d", cntx->pwm+1);
    
    gid = mmi_frm_group_create_ex(mmi_em_get_root_group(),
                  GRP_ID_AUTO_GEN, 
                  mmi_em_device_backlightl_proc, NULL,
                  MMI_FRM_NODE_SMART_CLOSE_FLAG);

    inline_id = cui_inline_create(gid, &g_mmi_em_backlight_inline_scrn);

    /* Get current level, from GPIO srv */
    cntx->level = srv_backlight_get_level(SRV_BACKLIGHT_TYPE_MAINLCD) -1;
//    kal_prompt_trace(MOD_MMI, "[EM] level=%d", cntx->level);
    
    if (cntx->level > cntx->max_level)
    {
        cntx->level = 0;
    }

    /* Get current level's freq & duty, from drv*/
    for (i = 0; i < max_level; i++)
    {
        pwm_measure_get_level_info(cntx->pwm, i, &pwm_info);
//        kal_prompt_trace(MOD_MMI, "[EM] freq=%d", pwm_info.freq);

        cntx->pwm_new[i][0] = pwm_info.freq;
        cntx->pwm_new[i][1] = pwm_info.duty;
        
        /* level text*/
        kal_wsprintf((WCHAR*)cntx->level_str[i], "%d", i+1);
        cntx->level_str_list[i] = (WCHAR*)cntx->level_str[i];
    }

    cntx->freq = cntx->pwm_new[cntx->level][0];
    cntx->duty = cntx->pwm_new[cntx->level][1];
//    kal_prompt_trace(MOD_MMI, "[EM] this fre=%d, duty=%d", cntx->freq, cntx->duty);
    
    cui_inline_set_item_select(inline_id, MMI_EM_STR_SELECT_1, cntx->max_level, (PU8*)cntx->level_str_list, cntx->level);
    kal_wsprintf((WCHAR*)cntx->freq_buf, "%d", cntx->freq);
    cui_inline_set_value(inline_id, MMI_EM_TEXT_EDIT_1, (void *) cntx->freq_buf);
    kal_wsprintf((WCHAR*)cntx->duty_buf, "%d", cntx->duty);
    cui_inline_set_value(inline_id, MMI_EM_TEXT_EDIT_2, (void *) cntx->duty_buf);
    
    cui_inline_run(inline_id);
}

static MMI_RET mmi_em_device_backlightl_proc(mmi_event_struct* evt)
{
    cui_event_inline_common_struct* inline_evt = (cui_event_inline_common_struct*) evt;
    cui_event_inline_notify_struct* notify_evt = (cui_event_inline_notify_struct*) evt;

    switch (inline_evt->evt_id)
    {
    case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_CSK_PRESS:
        if (mmi_em_device_backlight_set_hdlr(inline_evt->sender_id))
        {
            cui_inline_close(inline_evt->sender_id);
            MMI_EM_ASM_FREE_FUNC(dev_backlight);
        }
        break;

    case EVT_ID_CUI_INLINE_ABORT:
        mmi_em_device_backlight_abort();
        cui_inline_close(inline_evt->sender_id);
        MMI_EM_ASM_FREE_FUNC(dev_backlight);
        break;

    case EVT_ID_CUI_INLINE_NOTIFY:
//        kal_prompt_trace(MOD_MMI, "[EM] EVT_ID_CUI_INLINE_NOTIFY(%d)", notify_evt->event_type);
        switch (notify_evt->event_type)
        {
            case CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED:
                mmi_em_device_backlight_select_notify(inline_evt->sender_id);
                break;

            //case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
            case CUI_INLINE_NOTIFY_ITEM_CHANGED:
                mmi_em_device_backlight_update_bl(inline_evt->sender_id);
                break;
                
            default:
                break;
        }
        break;

    case EVT_ID_CUI_INLINE_GROUP_DEINIT:
        mmi_em_device_backlight_abort();
        break;
        
    default:
        break;
    }

    return MMI_RET_OK;
}

static MMI_BOOL mmi_em_device_backlight_set_hdlr(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_em_dev_backlight_cntx_struct *cntx = mmi_em_dev_backlight_cntx_p;
    U32 invalid_level;
    U32 invalid_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    kal_prompt_trace(MOD_MMI, "[EM] mmi_em_device_backlight_set_hdlr");
#if 1
    /* Get input buffer*/
    cui_inline_get_value(parent_id, MMI_EM_TEXT_EDIT_1, (void *)cntx->freq_buf);
    cui_inline_get_value(parent_id, MMI_EM_TEXT_EDIT_2, (void *)cntx->duty_buf);

    if (!mmi_em_device_backlight_all_level_valid(&invalid_level, &invalid_item))
    {
        mmi_em_device_backlight_invalid_popup(invalid_level, invalid_item);
        return MMI_FALSE;
    }
#endif

    /* Set PWM*/
    for (i = 0; i < PWM_MAX_BACKLIGHT_LEVEL; i++)
    {
        mmi_em_device_backlight_set_pwm(i + 1, cntx->pwm_new[i][0], cntx->pwm_new[i][1]);
    }
    mmi_em_device_backlight_send_set_hw_level_req();
    /* Set backlight level*/
    srv_gpio_setting_bl_restore();

    return MMI_TRUE;
}

static MMI_BOOL mmi_em_device_backlight_all_level_valid(U32 *level, U32 *item)
{
    U32 i;
    U32 value;
    mmi_em_dev_backlight_cntx_struct *cntx = mmi_em_dev_backlight_cntx_p;

    for (i = 0; i < cntx->max_level; i++)
    {
        /* Check freq*/
        value = cntx->pwm_new[i][0];
        if (value < MMI_EM_DEV_BACKLIGHT_MIN_FREQ ||
            value > MMI_EM_DEV_BACKLIGHT_MAX_FREQ)
        {
            *level = i;
            *item = 0;
            return MMI_FALSE;
        }

        /* Check duty*/
        value = cntx->pwm_new[i][1];
        if (value < MMI_EM_DEV_BACKLIGHT_MIN_DUTY ||
            value > MMI_EM_DEV_BACKLIGHT_MAX_DUTY)
        {
            *level = i;
            *item = 1;
            return MMI_FALSE;
        }
    }

    *level = 0;
    *item = 0;
    return MMI_TRUE;
}

static void mmi_em_device_backlight_invalid_popup(U32 level, U32 item)
{
    WCHAR string[MMI_EM_DEV_BACKLIGHT_INVALID_POPUP_TEXT_LEN];
    WCHAR *item_string;

    switch(item)
    {
        case 0:
            item_string = get_string(STR_ID_EM_DEV_BACKLIGHT_FREQ);
            break;
            
        case 1:
            item_string = get_string(STR_ID_EM_DEV_BACKLIGHT_DUTY);
            break;
            
        default:
            item_string = (WCHAR*)L"";
            break;
    }

    kal_wsprintf(string, "%w %w %d %w", 
        item_string, 
        get_string(STR_ID_EM_DEV_BACKLIGHT_INVALID_POPUP1), 
        level + 1, 
        get_string(STR_ID_EM_DEV_BACKLIGHT_INVALID_POPUP2));

    mmi_popup_display(string, MMI_EVENT_WARNING, NULL);
}

static void mmi_em_device_backlight_set_pwm(U32 level, U32 freq, U32 duty)
{
    custom_pwm_configure(SRV_GPIO_DEV_MAINLCD, level, freq, duty);
}


static void mmi_em_device_backlight_select_notify(MMI_ID parent_id)
{
    U32 new_level = 0;
    mmi_em_dev_backlight_cntx_struct *cntx = mmi_em_dev_backlight_cntx_p;

//    kal_prompt_trace(MOD_MMI, "[EM] mmi_em_device_backlight_select_notify");
    
    cui_inline_get_value(parent_id, MMI_EM_STR_SELECT_1, (void *)&new_level);
    
	if (new_level == cntx->level)
	{
            return;
	}
	cntx->level = new_level;
    
    /* get freq&duty*/
    cntx->freq = cntx->pwm_new[cntx->level][0]; //*(pwm_tbl + 2 * cntx->level);
    cntx->duty = cntx->pwm_new[cntx->level][1]; //*(pwm_tbl + 2 * cntx->level + 1);

    /* Set buffer*/
    kal_wsprintf((WCHAR*)cntx->freq_buf, "%d", cntx->freq);
    kal_wsprintf((WCHAR*)cntx->duty_buf, "%d", cntx->duty);
    cui_inline_set_value(parent_id, MMI_EM_TEXT_EDIT_1, (void *)cntx->freq_buf);
    cui_inline_set_value(parent_id, MMI_EM_TEXT_EDIT_2, (void *)cntx->duty_buf);

    srv_gpio_setting_set_bl_level(cntx->level+1, MMI_FALSE);
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

static void mmi_em_device_backlight_update_bl(MMI_ID parent_id)
{
    U32 freq;
    U32 duty;
    mmi_em_dev_backlight_cntx_struct *cntx = mmi_em_dev_backlight_cntx_p;

//    kal_prompt_trace(MOD_MMI, "[EM] mmi_em_device_backlight_update_bl");
    
    cui_inline_get_value(parent_id, MMI_EM_STR_SELECT_1, (void *)&cntx->level);
    
    /* Get input buffer*/
    cui_inline_get_value(parent_id, MMI_EM_TEXT_EDIT_1, (void *)cntx->freq_buf);
    cui_inline_get_value(parent_id, MMI_EM_TEXT_EDIT_2, (void *)cntx->duty_buf);

    /* Convert to value*/
    freq = mmi_wcs_wtoi(cntx->freq_buf);
    duty = mmi_wcs_wtoi(cntx->duty_buf);
    
    /* Range check*/
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    cntx->freq = freq;
    cntx->duty = duty;
    
    /* Set PWM*/
    cntx->pwm_new[cntx->level ][0] = cntx->freq;
    cntx->pwm_new[cntx->level ][1] = cntx->duty;
}

static void mmi_em_device_backlight_abort(void)
{
    srv_gpio_setting_bl_restore();
}

static void mmi_em_device_backlight_send_set_hw_level_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    mmi_eq_set_hw_level_req_struct *set_hw_struct;
    mmi_em_dev_backlight_cntx_struct *cntx = mmi_em_dev_backlight_cntx_p;
    pwm_measure_level_info_struct pwm_info;
    Battery_measure_level_info_struct batt_info;
    U32 max_level;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_hw_struct = OslConstructDataPtr(sizeof(mmi_eq_set_hw_level_req_struct));

    for (i = 0; i < 5; i++)
    {
        pwm_measure_get_level_info(PWM_MEASURE_TYPE_PWM1, i, &pwm_info);
        set_hw_struct->hw_profile.PWM1_freq_Level_Info[i] = pwm_info.freq; //PWM1_Level_Info[i][0];
        set_hw_struct->hw_profile.PWM1_duty_Level_Info[i] = pwm_info.duty; //PWM1_Level_Info[i][1];

        pwm_measure_get_level_info(PWM_MEASURE_TYPE_PWM2, i, &pwm_info);
        set_hw_struct->hw_profile.PWM2_freq_Level_Info[i] = pwm_info.freq; //PWM2_Level_Info[i][0];
        set_hw_struct->hw_profile.PWM2_duty_Level_Info[i] = pwm_info.duty; //PWM2_Level_Info[i][1];

        pwm_measure_get_level_info(PWM_MEASURE_TYPE_ALTER, i, &pwm_info);
        set_hw_struct->hw_profile.PWM3_freq_Level_Info[i] = pwm_info.freq; //Alter_Level_Info[i][0];
        set_hw_struct->hw_profile.PWM3_duty_Level_Info[i] = pwm_info.duty; //Alter_Level_Info[i][1];
    }

    //pwm_tbl = g_mmi_em_dev_backlight_level_info[cntx->pwm];
    
    for (i = 0; i < cntx->max_level; i++)
    {
        set_hw_struct->hw_profile.bl_PWM_freq_Level_Info[i] = cntx->pwm_new[i][0]; //*(pwm_tbl + 2 * i);
        set_hw_struct->hw_profile.bl_PWM_duty_Level_Info[i] = cntx->pwm_new[i][1]; //*(pwm_tbl + 2 * i + 1);
    }

    memcpy(
        set_hw_struct->hw_profile.MainLCD_Contrast_Level_Info,
        lcd_measure_get_level_info(LCD_MEASURE_TYPE_MAINLCD_CONTRAST),
        sizeof(set_hw_struct->hw_profile.MainLCD_Contrast_Level_Info));
    memcpy(
        set_hw_struct->hw_profile.MainLCD_Bias_Level_Info,
        lcd_measure_get_level_info(LCD_MEASURE_TYPE_MAINLCD_BIAS),
        sizeof(set_hw_struct->hw_profile.MainLCD_Bias_Level_Info));
    memcpy(
        set_hw_struct->hw_profile.MainLCD_Linerate_Level_Info,
        lcd_measure_get_level_info(LCD_MEASURE_TYPE_MAINLCD_LINERATE),
        sizeof(set_hw_struct->hw_profile.MainLCD_Linerate_Level_Info));
    memcpy(
        set_hw_struct->hw_profile.MainLCD_Temp_Level_Info,
        lcd_measure_get_level_info(LCD_MEASURE_TYPE_MAINLCD_TEMP),
        sizeof(set_hw_struct->hw_profile.MainLCD_Temp_Level_Info));

#ifdef __MMI_SUBLCD__
    memcpy(
        set_hw_struct->hw_profile.SubLCD_Contrast_Level_Info,
        lcd_measure_get_level_info(LCD_MEASURE_TYPE_SUBLCD_CONTRAST),
        sizeof(set_hw_struct->hw_profile.SubLCD_Contrast_Level_Info));
    memcpy(
        set_hw_struct->hw_profile.SubLCD_Bias_Level_Info,
        lcd_measure_get_level_info(LCD_MEASURE_TYPE_SUBLCD_BIAS),
        sizeof(set_hw_struct->hw_profile.SubLCD_Bias_Level_Info));
    memcpy(
        set_hw_struct->hw_profile.SubLCD_Linerate_Level_Info,
        lcd_measure_get_level_info(LCD_MEASURE_TYPE_SUBLCD_LINERATE),
        sizeof(set_hw_struct->hw_profile.SubLCD_Linerate_Level_Info));
    memcpy(
        set_hw_struct->hw_profile.SubLCD_Temp_Level_Info,
        lcd_measure_get_level_info(LCD_MEASURE_TYPE_SUBLCD_TEMP),
        sizeof(set_hw_struct->hw_profile.SubLCD_Temp_Level_Info));
#endif /* __MMI_SUBLCD__ */ 

    max_level = battery_measure_get_max_level();
    for (i = 0; i < max_level; i++)
    {
        battery_measure_get_level_info(i, &batt_info);
        set_hw_struct->hw_profile.Battery_Level_Info[i] = batt_info.value;
    }

    EngineerModeSendMsg(MSG_ID_MMI_EQ_SET_HW_LEVEL_REQ, set_hw_struct, NULL);
}

#endif /* __MMI_EM_DEV_BACKLIGHT__*/
            

#define MMI_EM_DEV_EINT
/*-----------------------------------------------------------------------------*/
/* -------------------------  Device -> EINT --------------------------------- */
/*-----------------------------------------------------------------------------*/
#if defined(__MMI_EM_DEV_EINT__)
static void mmi_em_dev_eint_format_show_strings(U32 index, U32 param)
{
    eint_measure_map_entry_struct item;

    if (!eint_measure_get_item_by_idx(index, &item))
    {
        return;
    }
//    kal_prompt_trace(MOD_MMI, "[EM]%s", item.name);
    kal_wsprintf((WCHAR*)subMenuData[index], "%s %d", item.name, param);
    subMenuDataPtrs[index] = subMenuData[index];
}

/*****************************************************************************
 * FUNCTION
 *  EmPrepareEINTList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_dev_eint_prepare_lint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    eint_measure_map_entry_struct item;
    U32 max_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    max_item = eint_measure_get_total_num();
    currentHighlightIndex = 0;
    
    for (i = 0; i <= max_item; i++)
    {
        if (eint_measure_get_item_by_idx(i, &item))
        {
            if (item.is_vaild == GPIO_VAILD)
        {
            mmi_em_dev_eint_format_show_strings(i, 0);
            currentHighlightIndex++;
        }
    }
    }
    /* Initialize charger value */
    if (g_charbat_context.isChargerConnected == 1)
    {
        mmi_em_dev_eint_format_show_strings(0, 1);
    }
    /* Initialize earphone value */
    if (srv_earphone_is_plug_in())
    {
        mmi_em_dev_eint_format_show_strings(3, 1);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_dev_eint_gpio_recv_hdlr
 * DESCRIPTION
 *  Helper function for EINT GPIO Recv
 * PARAMETERS
 *  inMsg       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_em_dev_eint_gpio_recv_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    mmi_eq_gpio_detect_ind_struct *gpio_detect_struct = (mmi_eq_gpio_detect_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gpio_detect_struct->gpio_device)
    {
        case EXT_DEV_NONE:
            for (i = 1; i <= 3; i++)
            {
                mmi_em_dev_eint_format_show_strings(i, 0);
            }
            break;

        case EXT_DEV_UART:
            mmi_em_dev_eint_format_show_strings(1, gpio_detect_struct->on_off == KAL_TRUE);
            break;

        case EXT_DEV_KEY_1:
        case EXT_DEV_KEY_2:
            mmi_em_dev_eint_format_show_strings(2, gpio_detect_struct->gpio_device == EXT_DEV_KEY_1);
            break;

        case EXT_DEV_EARPHONE:
            mmi_em_dev_eint_format_show_strings(3, gpio_detect_struct->on_off == KAL_TRUE);
            break;

        default:
            return 0;
    }

    mmi_em_fresh_active_scrn();
	return 0;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_em_dev_eint_exit_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_dev_eint_exit_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EQ_GPIO_DETECT_IND, srv_gpio_detect_ind_hdlr, MMI_FALSE);
    mmi_frm_set_protocol_event_handler(PRT_BATTERY_STATUS_IND, srv_charbat_status_ind_hdlr, MMI_FALSE);
}

static mmi_ret mmi_em_device_eint_scrn_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_frm_scrn_active_evt_struct *active_evt = (mmi_frm_scrn_active_evt_struct*)evt;
            
            
            mmi_em_dev_eint_prepare_lint();
            if (currentHighlightIndex < 1)
            {
                currentHighlightIndex++;
            }
            ShowCategory6Screen(
                STR_ID_EM_DEV_EINT,
                (U16) 0, (U16) 0,
                (U16) 0, STR_GLOBAL_BACK,
                (U16) 0, currentHighlightIndex,
                (PU8*) subMenuDataPtrs,
                 NULL, 0, active_evt->gui_buffer);
            mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EQ_GPIO_DETECT_IND, mmi_em_dev_eint_gpio_recv_hdlr, MMI_FALSE);
            //mmi_frm_set_protocol_event_handler(PRT_BATTERY_STATUS_IND, mmi_em_dev_eint_battery_recv_hdlr, MMI_FALSE);  
            break;
        }
        
        case EVT_ID_SCRN_DEINIT:
        {
            mmi_em_dev_eint_exit_menu();
            break;
        }
        
        default:
            break;
    }
    
    return MMI_RET_OK;
}

static void mmi_em_device_eint(void)
{
    mmi_frm_scrn_create(mmi_em_get_root_group(),
        SCR_ID_EM_DEV_EINT,
        mmi_em_device_eint_scrn_proc,
        NULL);
}
#endif /* #if defined(__MMI_EM_DEV_EINT__) */


/*****************************************************************************
 * FUNCTION
 *  EMFMBatteryStatusMsgHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EMFMBatteryStatusMsgHandler(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_battery_status_ind_struct *BatState = (mmi_eq_battery_status_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* send ACK to UEM, Charger flow control mechanism. */
    srv_charbat_send_ack(BatState->battery_status);
        
    switch (BatState->battery_status)
    {
        case PMIC_CHARGER_IN:
            g_charbat_context.isChargerConnected = 1;
            g_charbat_context.ChargingComplete = 0; /* MTK added, Robin 1009 to prevent reentrence of charging complete screen */
            srv_charbat_set_charger_status(SRV_CHARBAT_STATUS_CHARGER_IN);
            IdleScreenChargerConnected(KAL_TRUE);
            break;

        case PMIC_CHARGER_OUT:
            g_charbat_context.ChargingComplete = 0; /* MTK added, Robin 1009 to prevent reentrence of charging complete screen */
            g_charbat_context.isChargerConnected = 0;
            srv_charbat_set_charger_status(SRV_CHARBAT_STATUS_CHARGER_OUT);
            IdleScreenChargerDisconnected();
            break;

        case PMIC_CHARGE_COMPLETE:
            srv_charbat_set_charger_status(SRV_CHARBAT_STATUS_CHARGE_COMPLETE);
            IdleScreenBatteryFullCharged();
            break;

        case PMIC_VBAT_STATUS:
            BatteryStatusIndication(BatState->battery_voltage);
            break;

        default:
            srv_charbat_status_ind_hdlr(BatState);
            return;
    }

}


#define EM_DEVICE_ADC
/*-----------------------------------------------------------------------------*/
/*------------------------------ Device -> ADC --------------------------------*/
/*-----------------------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __COSMOS_MMI_PACKAGE__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__MMI_EM_DEV_ADC__*/
#undef  ___EM_DEVICE_ADC___


#define EM_DEV_CLAM
/*-----------------------------------------------------------------------------*/
/*----------------------------- Device -> Clam --------------------------------*/
/*-----------------------------------------------------------------------------*/
#if defined(__MMI_EM_DEV_CLAM__)

static mmi_ret mmi_em_dev_clam_menu_proc(mmi_event_struct *param)
{
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            U32 num_items;
            mmi_frm_scrn_active_evt_struct *active_evt = (mmi_frm_scrn_active_evt_struct *)param;
            
            for (num_items = 0; num_items < 2; num_items++)
            {
                kal_wsprintf((WCHAR*)subMenuData[num_items], "ClamOpen %u", 0);
                subMenuDataPtrs[num_items] = subMenuData[num_items];
            }
            
            ShowCategory6Screen(
                STR_ID_EM_DEV_CLAM,
                (U16) 0,
                (U16) NULL,
                (U16) 0,
                STR_GLOBAL_BACK,
                (U16) 0,
                num_items,
                (PU8*) subMenuDataPtrs,
                NULL,
                0,
                active_evt->gui_buffer);
                
            break;
        }
    }
    
    return MMI_RET_OK; 
}
/*****************************************************************************
 * FUNCTION
 *  EntryClamMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryClamMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_frm_scrn_create(
        mmi_em_get_root_group(),
        MENU_ID_EM_DEV_CLAM,
        mmi_em_dev_clam_menu_proc,
        NULL);
}

#endif /*__MMI_EM_DEV_CLAM__*/


#define EM_DEVICE_SetHwLevel
/*-----------------------------------------------------------------------------*/
/*--------------------------- Device -> HW Level ------------------------------*/
/*-----------------------------------------------------------------------------*/
#ifdef __MMI_EM_DEV_SET_HW_LEVEL__

#if 0 //#ifdef __BK_LIGHT_20LEVEL_SUPPORT__
/* under construction !*/
#else
#define PWM_MAX_LEVEL_NUM PWM_MAX_LEVEL
#endif

typedef enum
{
    MMI_EM_DEV_HW_LEVEL_INFO_TYPE_BATTERY  = 0X01,
    MMI_EM_DEV_HW_LEVEL_INFO_TYPE_PWM1     = 0X02,
    MMI_EM_DEV_HW_LEVEL_INFO_TYPE_PWM2     = 0X04,
    MMI_EM_DEV_HW_LEVEL_INFO_TYPE_PWM3     = 0X08,
    MMI_EM_DEV_HW_LEVEL_INFO_TYPE_END_OF_ITEM
} mmi_em_dev_hw_level_info_type_enum;

/*
    The different bit of info_dirty indicated different mean;
    0000 0001 : BATTERY
    0000 0010 : PWM1
    0000 0100 : PWM2
    0000 1000 : PWM3
*/

#define MMI_EM_DEV_HW_LEVEL_INFO_CHECK_INFO_DIRTY(_info, _type) ((_info) & (_type))

#define MMI_EM_DEV_HW_LEVEL_INFO_SET_INFO_DIRTY(_info, _type)   ((_info) |= (_type))

typedef struct
{
    U8  info_dirty;
    U16 list_num;
    U16 menu_id;
    U16 hilit_index;
    U16 str_id;
    U32 Battery_Level_Info[BATTERY_MAX_LEVEL];
    U32 PWM1_Level_Info[PWM_MAX_LEVEL_NUM][2];
    U32 PWM2_Level_Info[PWM_MAX_LEVEL][2];
    U32 Alter_Level_Info[PWM_MAX_LEVEL][2];
} mmi_em_dev_hw_level_cntx_struct;

mmi_em_dev_hw_level_cntx_struct *mmi_em_dev_hw_level_cntx_p = NULL;

MMI_EM_INIT_ASM(dev_hw_level, mmi_em_dev_hw_level_cntx_p, sizeof(mmi_em_dev_hw_level_cntx_struct))

static void mmi_em_dev_hw_level_hdlr(void)
{
    MMI_EM_ASM_INIT_FUNC(dev_hw_level);
}

static void mmi_em_dev_hw_level_pwm_limit_notify(void)
{
    U32 min, max;
    const WCHAR *freq = L"FREQ";
    const WCHAR *duty = L"DUTY";
    WCHAR* temp;
    WCHAR notify_str_buf[40] = {0};
    
    
    if (mmi_em_dev_hw_level_cntx_p->hilit_index % 2 == 0)
    {
        min = PWM_MIN_FREQ;
        max = PWM_MAX_FREQ;
        temp = (WCHAR*) freq;
    }
    else
    {
        min = PWM_MIN_DUTY;
        max = PWM_MAX_DUTY;
        temp = (WCHAR*) duty;
    }
    
    kal_wsprintf(
        notify_str_buf, 
        "PWM %w limitation between %d and %d",
        temp,
        min, 
        max);
    
    mmi_popup_display_simple(
        notify_str_buf, 
        MMI_EVENT_INFO,
        mmi_em_get_root_group(),
        NULL);
}

static void mmi_em_device_set_hw_pwm_level(
                U32 * const pwm_level_info_p, void* dest, 
                const void* src, U32 size, U32 level_num,
                MMI_BOOL is_first_enter)
{
    U32 i;
	U32 *pwm = (U32*)src;
    mmi_em_dev_hw_level_cntx_struct *cntx = mmi_em_dev_hw_level_cntx_p;
    
    
    cntx->list_num = 0;
    
    for (i = 0; i < level_num; i++)
    {
        kal_wsprintf((WCHAR*)subMenuData[cntx->list_num], "[Freq %2d] %u", (i + 1), (U32)*(pwm + 2 * i + 0));
        subMenuDataPtrs[cntx->list_num] = subMenuData[cntx->list_num];
        cntx->list_num++;

        kal_wsprintf((WCHAR*)subMenuData[cntx->list_num], "[Duty %2d] %u", (i + 1), (U32)*(pwm + 2 * i + 1));
        subMenuDataPtrs[cntx->list_num] = subMenuData[cntx->list_num];
        cntx->list_num++;
    }

    if (is_first_enter)
        memcpy((void *)dest, (const void *)src, size);
}

static void mmi_em_device_enter_hwlist_proc(MMI_BOOL is_first_enter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    mmi_em_dev_hw_level_cntx_struct *cntx = mmi_em_dev_hw_level_cntx_p;
    U32 max_level;
    U32 *pwm;
    pwm_measure_level_info_struct info;
    Battery_measure_level_info_struct batt_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->list_num = 0;

    switch (cntx->menu_id)
    {
        case MENU_ID_EM_DEV_HW_LEVEL_BATTERY:    /* Battery */
            max_level = battery_measure_get_max_level();
            for (i = 0; i < max_level; i++)
            {
                battery_measure_get_level_info(i, &batt_info);
                kal_wsprintf((WCHAR*)subMenuData[i], "[LEV %2d] %d", (i + 1), batt_info.value);
                subMenuDataPtrs[i] = subMenuData[i];
                cntx->list_num++;

                if (is_first_enter)
                {
                    mmi_em_dev_hw_level_cntx_p->Battery_Level_Info[i] = batt_info.value;
                }
            }
            break;
			
#ifndef __MMI_EM_60BACKLIGHT__            
        case MENU_ID_EM_DEV_HW_LEVEL_PWM1:   /* PWM 1 */
            max_level = pwm_measure_get_max_level(PWM_MEASURE_TYPE_PWM1);
            if (max_level > PWM_MAX_LEVEL_NUM)
                max_level = PWM_MAX_LEVEL_NUM;
            pwm = (U32*)get_ctrl_buffer(sizeof(U32) * max_level * 2);
            for (i = 0; i < max_level; i++)
            {
                pwm_measure_get_level_info(PWM_MEASURE_TYPE_PWM1, i, &info);
                *(pwm + i*2) = info.freq;
                *(pwm + i*2 + 1) = info.duty;
            }
            mmi_em_device_set_hw_pwm_level(NULL,
                (void *)mmi_em_dev_hw_level_cntx_p->PWM1_Level_Info, 
                (const void *)pwm, 
                sizeof(U32) * max_level * 2,
                max_level, 
                is_first_enter);

            free_ctrl_buffer(pwm);
            break;
            
        case MENU_ID_EM_DEV_HW_LEVEL_PWM2:   /* PWM 2 */
            max_level = pwm_measure_get_max_level(PWM_MEASURE_TYPE_PWM2);
            if (max_level > PWM_MAX_LEVEL_NUM)
                max_level = PWM_MAX_LEVEL_NUM;
            pwm = (U32*)get_ctrl_buffer(sizeof(U32) * max_level * 2);
            for (i = 0; i < max_level; i++)
            {
                pwm_measure_get_level_info(PWM_MEASURE_TYPE_PWM2, i, &info);
                *(pwm + i*2) = info.freq;
                *(pwm + i*2 + 1) = info.duty;
            }
            mmi_em_device_set_hw_pwm_level(NULL,
                (void *)mmi_em_dev_hw_level_cntx_p->PWM2_Level_Info, 
                (const void *)pwm,
                sizeof(U32) * max_level * 2,
                max_level, 
                is_first_enter);

            free_ctrl_buffer(pwm);
            break;
            
        case MENU_ID_EM_DEV_HW_LEVEL_PWM3:   /* PWM 3 */
            max_level = pwm_measure_get_max_level(PWM_MEASURE_TYPE_ALTER);
            pwm = (U32*)get_ctrl_buffer(sizeof(U32) * max_level * 2);
            for (i = 0; i < max_level; i++)
            {
                pwm_measure_get_level_info(PWM_MEASURE_TYPE_ALTER, i, &info);
                *(pwm + i*2) = info.freq;
                *(pwm + i*2 + 1) = info.duty;
            }
            mmi_em_device_set_hw_pwm_level(NULL,
                (void *)mmi_em_dev_hw_level_cntx_p->Alter_Level_Info, 
                (const void *)pwm,
                sizeof(U32) * max_level * 2, 
                max_level, 
                is_first_enter);
            
            free_ctrl_buffer(pwm);
            break;
#endif // __MMI_EM_60BACKLIGHT__ 

        default:
            break;
    }
}


static void mmi_em_device_hw_level_enter_detail_scrn(U16 menu_id, U16 str_id)
{
    mmi_em_dev_hw_level_cntx_p->menu_id = menu_id;
    mmi_em_dev_hw_level_cntx_p->str_id = str_id;
    
    
    mmi_em_device_hw_level_detail_scrn();
}

static mmi_ret mmi_em_device_hw_level_detail_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_frm_scrn_active_evt_struct *active_evt = (mmi_frm_scrn_active_evt_struct *)evt;
            
            mmi_em_device_enter_hwlist_proc(active_evt->is_first_active);
        
            ShowCategory6Screen(
                mmi_em_dev_hw_level_cntx_p->str_id,
                0, STR_GLOBAL_OK,
                0, STR_GLOBAL_BACK,
                0, mmi_em_dev_hw_level_cntx_p->list_num,
                (PU8*) subMenuDataPtrs,
                NULL,  mmi_em_dev_hw_level_cntx_p->hilit_index,
                active_evt->gui_buffer);
            
            break;
        }
        
        case EVT_ID_WGUI_LSK_CLICK:
        {
            mmi_em_device_change_hw_level_hdlr();
            return MMI_RET_KEY_HANDLED;
        }
        
        case EVT_ID_WGUI_RSK_CLICK:
        {
            if (mmi_em_device_check_hw_level_info_dirty_hdlr())
            {
                return MMI_RET_KEY_HANDLED;
            }
            break;
        }
        
        case EVT_ID_SCRN_HIGHLIGHT_CHANGE:
        {
            cat_evt_struct *cat_evt = (cat_evt_struct *)evt;
            mmi_em_dev_hw_level_cntx_p->hilit_index = cat_evt->item_index;
            return MMI_RET_CHANGED;
        }
        
        default:
            break;
    }
    
    return MMI_RET_OK;
}

static void mmi_em_device_hw_level_detail_scrn(void)
{
    mmi_frm_scrn_create(
        mmi_em_get_root_group(),
        SCR_ID_EM_CMN_SCRN,
        mmi_em_device_hw_level_detail_proc, NULL);
}

static void mmi_em_device_change_hw_level_hdlr(void)
{
    U32 level;
    mmi_em_num_editor_struct info = {0};

    EmHWLevelInfoAccess(mmi_em_dev_hw_level_cntx_p->menu_id,
                   (U8) mmi_em_dev_hw_level_cntx_p->hilit_index, EM_HW_LEVEL_ACT_GET, &level);

    info.title_id = STR_ID_EM_DEV_LCD_SET_PARAM_1;
    info.notify = mmi_em_device_change_hw_level_notify;
    info.value = level;

    mmi_em_show_num_editor(&info);
}

static void mmi_em_device_change_hw_level_notify(MMI_BOOL is_accept, U32 output_num, MMI_ID editor_gid, void* user_data)
{
    if (!EmHWLevelInfoAccess(mmi_em_dev_hw_level_cntx_p->menu_id,
                   (U8) mmi_em_dev_hw_level_cntx_p->hilit_index, EM_HW_LEVEL_ACT_SET, &output_num))
    {
        mmi_em_dev_hw_level_pwm_limit_notify();
    }
}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
static MMI_BOOL mmi_em_dev_hw_level_info_data_hdlr_ext(
                U8 item, 
                U8 action, 
                U32 *value,
                pwm_measure_type_enum info_type)
{
    U32 old_val;
    pwm_measure_level_info_struct info;
    
    if (action == EM_HW_LEVEL_ACT_GET)    /* GET */
    {
        pwm_measure_get_level_info(info_type, item/2, &info);
        *value =  *(((U32*)&info) + item % 2);
    }
    else  /* SET */
    {
        if ((0 == item % 2) && (*value > PWM_MAX_FREQ || *value < PWM_MIN_FREQ))
        {
            //*value = 9999999;
            return MMI_FALSE;
        }
        else if ((1 == item % 2) && (*value > PWM_MAX_DUTY || *value < PWM_MIN_DUTY))
        {
            return MMI_FALSE;
        }

        pwm_measure_get_level_info(info_type, item/2, &info);

        old_val = *(((U32*)&info) + item % 2);
        if (old_val == (U32) * value)
        {
            return MMI_TRUE;
        }

		*(((U32*)&info) + item % 2) = (U32) * value;
		pwm_measure_set_level_info(info_type, item/2, &info);
		
		info_type = info_type - PWM_MEASURE_TYPE_PWM1 + MENU_ID_EM_DEV_HW_LEVEL_PWM1;
        MMI_EM_DEV_HW_LEVEL_INFO_SET_INFO_DIRTY(
                mmi_em_dev_hw_level_cntx_p->info_dirty,
                info_type);

    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  EmHWLevelInfoAccess
 * DESCRIPTION
 *  
 * PARAMETERS
 *  Type        [IN]        
 *  Item        [IN]        
 *  action      [IN]        
 *  value       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL EmHWLevelInfoAccess(U16 Type, U8 Item, U8 action, U32 *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Battery_measure_level_info_struct batt_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (Type)
    {
        case MENU_ID_EM_DEV_HW_LEVEL_BATTERY:
        {
            battery_measure_get_level_info(Item, &batt_info);
            if (action == EM_HW_LEVEL_ACT_GET)  /* GET */
            {
                *value = batt_info.value;
            }
            else    /* SET */
            {
                if (*value > 9999999)
                {
                    *value = 9999999;
                }

                if (batt_info.value == (U32) * value)
                    break;
                batt_info.value = *value;

                 MMI_EM_DEV_HW_LEVEL_INFO_SET_INFO_DIRTY(
                    mmi_em_dev_hw_level_cntx_p->info_dirty,
                    MMI_EM_DEV_HW_LEVEL_INFO_TYPE_BATTERY);

                battery_measure_set_level_info(Item, &batt_info);
            }
            break;
        }
#ifndef __MMI_EM_60BACKLIGHT__ 

        case MENU_ID_EM_DEV_HW_LEVEL_PWM1:
            return mmi_em_dev_hw_level_info_data_hdlr_ext(
                       Item, action, value,
                PWM_MEASURE_TYPE_PWM1);

        case MENU_ID_EM_DEV_HW_LEVEL_PWM2:
            return mmi_em_dev_hw_level_info_data_hdlr_ext(
                       Item, action, value,
                PWM_MEASURE_TYPE_PWM2);

        case MENU_ID_EM_DEV_HW_LEVEL_PWM3:
            return mmi_em_dev_hw_level_info_data_hdlr_ext(
                       Item, action, value,
                PWM_MEASURE_TYPE_ALTER);
#endif //__MMI_EM_60BACKLIGHT__
        default:
            break;
    }
    
    return MMI_TRUE;
}

static MMI_BOOL mmi_em_device_check_hw_level_info_dirty_hdlr(void)
{
    MMI_BOOL result = MMI_FALSE;
    
    
    if (mmi_em_dev_hw_level_cntx_p->info_dirty)
    {
        mmi_em_display_confirm(STR_GLOBAL_UPDATE,
            mmi_em_get_root_group(),
            MMI_EVENT_QUERY,
            mmi_em_dev_hw_level_update_proc);
        result = MMI_TRUE;
    }
    
    return result;
}

static MMI_RET mmi_em_dev_hw_level_update_proc(mmi_event_struct *evt)
{
    mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*) evt;
    U32 max_level;
    U32 i;
    pwm_measure_level_info_struct info;
    Battery_measure_level_info_struct batt_info;
    
    switch (alert->result)
    {
    case MMI_ALERT_CNFM_YES:
        SendSetHWLevelInfoReq();
        break;

    case MMI_ALERT_CNFM_NO:
    {
        /* recover old value */
        U8 info_dirty = mmi_em_dev_hw_level_cntx_p->info_dirty;
        
        if (MMI_EM_DEV_HW_LEVEL_INFO_CHECK_INFO_DIRTY(info_dirty, MMI_EM_DEV_HW_LEVEL_INFO_TYPE_BATTERY))
        {
            max_level = battery_measure_get_max_level();
            for (i = 0; i < max_level; i++)
            {
                batt_info.value = mmi_em_dev_hw_level_cntx_p->Battery_Level_Info[i];
                battery_measure_set_level_info(i, &batt_info);
            }
        }

        if (MMI_EM_DEV_HW_LEVEL_INFO_CHECK_INFO_DIRTY(info_dirty, MMI_EM_DEV_HW_LEVEL_INFO_TYPE_PWM1))
        {
            max_level = pwm_measure_get_max_level(PWM_MEASURE_TYPE_PWM1);
            for (i = 0; i < max_level; i++)
            {
                info.freq = mmi_em_dev_hw_level_cntx_p->PWM1_Level_Info[i][0];
                info.duty = mmi_em_dev_hw_level_cntx_p->PWM1_Level_Info[i][1];
                pwm_measure_set_level_info(PWM_MEASURE_TYPE_PWM1, i, &info);
            }
        }

        if (MMI_EM_DEV_HW_LEVEL_INFO_CHECK_INFO_DIRTY(info_dirty, MMI_EM_DEV_HW_LEVEL_INFO_TYPE_PWM2))
        {
            max_level = pwm_measure_get_max_level(PWM_MEASURE_TYPE_PWM2);
            for (i = 0; i < max_level; i++)
            {
                info.freq = mmi_em_dev_hw_level_cntx_p->PWM2_Level_Info[i][0];
                info.duty = mmi_em_dev_hw_level_cntx_p->PWM2_Level_Info[i][1];
                pwm_measure_set_level_info(PWM_MEASURE_TYPE_PWM2, i, &info);
            }
        }

        if (MMI_EM_DEV_HW_LEVEL_INFO_CHECK_INFO_DIRTY(info_dirty, MMI_EM_DEV_HW_LEVEL_INFO_TYPE_PWM3))
        {
            max_level = pwm_measure_get_max_level(PWM_MEASURE_TYPE_ALTER);
            for (i = 0; i < max_level; i++)
            {
                info.freq = mmi_em_dev_hw_level_cntx_p->Alter_Level_Info[i][0];
                info.duty = mmi_em_dev_hw_level_cntx_p->Alter_Level_Info[i][1];
                pwm_measure_set_level_info(PWM_MEASURE_TYPE_ALTER, i, &info);
            }
        }
        
        mmi_em_dev_hw_level_cntx_p->info_dirty = 0;
        mmi_frm_scrn_close(mmi_em_get_root_group(), SCR_ID_EM_CMN_SCRN);
        break;
    }

    default:
        break;
    }

    return MMI_RET_OK; 
}


/*****************************************************************************
 * FUNCTION
 *  SendSetHWLevelInfoReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void SendSetHWLevelInfoReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    mmi_eq_set_hw_level_req_struct *set_hw_struct;
    pwm_measure_level_info_struct pwm_info;
    Battery_measure_level_info_struct batt_info;
    U32 max_level;
#ifdef __MMI_EM_DEV_BACKLIGHT__
    U32 bl_pwm;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_hw_struct = OslConstructDataPtr(sizeof(mmi_eq_set_hw_level_req_struct));

    for (i = 0; i < PWM_MAX_LEVEL_NUM; i++)
    {
        pwm_measure_get_level_info(PWM_MEASURE_TYPE_PWM1, i, &pwm_info);
        set_hw_struct->hw_profile.PWM1_freq_Level_Info[i] = pwm_info.freq; //PWM1_Level_Info[i][0];
        set_hw_struct->hw_profile.PWM1_duty_Level_Info[i] = pwm_info.duty; //PWM1_Level_Info[i][1];
    }
    
    for (i = 0; i < PWM_MAX_LEVEL; i++)
    {
        pwm_measure_get_level_info(PWM_MEASURE_TYPE_PWM2, i, &pwm_info);
        set_hw_struct->hw_profile.PWM2_freq_Level_Info[i] = pwm_info.freq; //PWM2_Level_Info[i][0];
        set_hw_struct->hw_profile.PWM2_duty_Level_Info[i] = pwm_info.duty; //PWM1_Level_Info[i][1];

        pwm_measure_get_level_info(PWM_MEASURE_TYPE_ALTER, i, &pwm_info);
        set_hw_struct->hw_profile.PWM3_freq_Level_Info[i] = pwm_info.freq; //Alter_Level_Info[i][0];
        set_hw_struct->hw_profile.PWM3_duty_Level_Info[i] = pwm_info.duty; //Alter_Level_Info[i][1];
    }

#ifdef __MMI_EM_DEV_BACKLIGHT__
    if (bl_pwm = custom_uem_get_pwm_bl_mode(GPIO_DEV_LED_MAINLCD))
    {
        bl_pwm--;
        if (pwm_measure_get_level_info(bl_pwm, 0, &pwm_info))
	    {
            max_level = pwm_measure_backlight_get_max_level();
            for (i = 0; i < max_level; i++)
		    {
                pwm_measure_get_level_info(bl_pwm, i, &pwm_info);
	            set_hw_struct->hw_profile.bl_PWM_freq_Level_Info[i] = pwm_info.freq; //PWM3_Level_Info[i][0];
	            set_hw_struct->hw_profile.bl_PWM_duty_Level_Info[i] = pwm_info.duty; //PWM3_Level_Info[i][1];
	        }
	    }
    }
#endif


    max_level = battery_measure_get_max_level();
    for (i = 0; i < max_level; i++)
    {
        battery_measure_get_level_info(i, &batt_info);
        set_hw_struct->hw_profile.Battery_Level_Info[i] = batt_info.value;
        
    }

    EngineerModeSendMsg(MSG_ID_MMI_EQ_SET_HW_LEVEL_REQ, set_hw_struct, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  SendSetHWLevelInfoRsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SendSetHWLevelInfoRsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_hw_level_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_display_notify_popup(rsp_p->result);

    if (mmi_em_dev_hw_level_cntx_p)
    {
        mmi_em_dev_hw_level_cntx_p->info_dirty= 0;
    }
    mmi_frm_scrn_close(mmi_em_get_root_group(), SCR_ID_EM_CMN_SCRN);
}

#endif/*__MMI_EM_DEV_SET_HW_LEVEL__*/

#define EM_DEV_NAND_FORMAT
/*-----------------------------------------------------------------------------*/
/*------------------------- Device -> NAND format -----------------------------*/
/*-----------------------------------------------------------------------------*/
#ifdef __MMI_EM_DEV_NAND_FORMAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__MMI_EM_DEV_NAND_FORMAT__) */ 

#define EM_DEV_USB_OTG
/*-----------------------------------------------------------------------------*/
/*--------------------------- Device -> USB OTG -------------------------------*/
/*-----------------------------------------------------------------------------*/
#if defined(__MMI_EM_DEV_USB_OTG_SRP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MTK_TARGET__    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__MMI_EM_DEV_USB_OTG_SRP__) */ 

#define EM_DEV_USB_BOOT_MODE
/*-----------------------------------------------------------------------------*/
/*------------------------ Device -> USB boot mode ----------------------------*/
/*-----------------------------------------------------------------------------*/
#if defined(__MMI_EM_DEV_USB_BOOT_MODE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if defined(__USB_MASS_STORAGE_ENABLE__) && !defined(__MTP_ENABLE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #elif !defined(__USB_MASS_STORAGE_ENABLE__) && defined(__MTP_ENABLE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #elif defined(__USB_MASS_STORAGE_ENABLE__) && defined(__MTP_ENABLE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* defined(__USB_MASS_STORAGE_ENABLE__) && defined(__MTP_ENABLE__) */   
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if defined(__USB_MASS_STORAGE_ENABLE__) && defined(__MTP_ENABLE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
     #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_EM_DEV_USB_BOOT_MODE__ */ 

/*-----------------------------------------------------------------------------*/
/*------------------------ Device -> Memory test ------------------------------*/
/*-----------------------------------------------------------------------------*/
#if defined(__MMI_EM_DEV_MEMORY_TEST__)
static void mmi_em_dev_memory_test_emi_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MEM_DEV_INFO_T *mem_info = NULL;
    mmi_em_text_viewer_struct text_info = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get mem info*/
    mem_info = (MEM_DEV_INFO_T*)get_ctrl_buffer(sizeof(MEM_DEV_INFO_T));
    INT_GetMemDevInfo(mem_info);
    
    text_info.text = mmi_em_dev_memory_test_compose_emi_setting_text(mem_info);
    /* Compose string*/
    if (!text_info.text)
    {
        free_ctrl_buffer(mem_info);
        return;
    }
    text_info.title_id = STR_ID_EM_DEV_MEMORY_TEST_EMI_SETTING;
    mmi_em_show_text_viewer(&text_info);
    
    if (NULL != mem_info)
    {
        free_ctrl_buffer(mem_info);
        mem_info = NULL;
    }
    
    if (NULL != text_info.text)
    {
        free_ctrl_buffer((void*)text_info.text);
        text_info.text = NULL;
    }
}

static void mmi_em_dev_memory_test_custom_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MEM_DEV_INFO_T *mem_info = NULL;
    mmi_em_text_viewer_struct text_info = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get mem info*/
    mem_info = (MEM_DEV_INFO_T*)get_ctrl_buffer(sizeof(MEM_DEV_INFO_T));
    INT_GetMemDevInfo(mem_info);
    
    text_info.text = mmi_em_dev_memory_test_compose_custom_setting_text(mem_info);
    if (!text_info.text)
    {
        free_ctrl_buffer(mem_info);
        return;
    }
    text_info.title_id = STR_ID_EM_DEV_MEMORY_TEST_CUSTOM_SETTING;
    mmi_em_show_text_viewer(&text_info);
    
    if (NULL != mem_info)
    {
        free_ctrl_buffer(mem_info);
        mem_info = NULL;
    }
    
    if (NULL != text_info.text)
    {
        free_ctrl_buffer((void*)text_info.text);
        text_info.text = NULL;
    }
}

static void mmi_em_dev_memory_test_flash_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MEM_DEV_INFO_T *mem_info = NULL;
    mmi_em_text_viewer_struct text_info = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get mem info*/
    mem_info = (MEM_DEV_INFO_T*)get_ctrl_buffer(sizeof(MEM_DEV_INFO_T));
    INT_GetMemDevInfo(mem_info);
    
    text_info.text = mmi_em_dev_memory_test_compose_flash_info_text(mem_info);
    if (!text_info.text)
    {
        free_ctrl_buffer(mem_info);
        return;
    }
    text_info.title_id = STR_ID_EM_DEV_MEMORY_TEST_FLASH_INFO;
    mmi_em_show_text_viewer(&text_info);
    
    if (NULL != mem_info)
    {
        free_ctrl_buffer(mem_info);
        mem_info = NULL;
    }
    
    if (NULL != text_info.text)
    {
        free_ctrl_buffer((void*)text_info.text);
        text_info.text = NULL;
    }
}

static U16* mmi_em_dev_memory_test_compose_emi_setting_text(MEM_DEV_INFO_T *mem_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = 0;
    U32 reg_num;
    U32 *reg_pos = NULL;
    U32 i;
    U16 cur_str[MMI_EM_DEV_MEM_TEST_EMI_SETTING_TMP_STR_LEN];
    U16 *cur_str_tail = NULL;
    U16 *cur_str_head = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mem_info)
    {
        return NULL;
    }

    reg_num = mem_info->EMIInfo.reg_num;
    reg_pos = (U32*)&mem_info->EMIInfo.reg_num + 1;

    /* Get len*/
    for(i = 0; i < reg_num; i++)
    {
        kal_wsprintf(cur_str, MMI_EM_DEV_MEM_TEST_EMI_SETTING_CONT_TEMP, i, *(reg_pos + i));
        len += mmi_wcslen((U16*)cur_str) + 1;
    }
    len++;

    /* Alloc text buffer*/
    cur_str_head = (U16*)get_ctrl_buffer(sizeof(U16) * len);
    cur_str_tail = cur_str_head;
    /* Compose text*/
    for(i = 0; i < reg_num; i++)
    {
        kal_wsprintf(cur_str_tail, MMI_EM_DEV_MEM_TEST_EMI_SETTING_CONT_TEMP, i, *(reg_pos + i));
        cur_str_tail += mmi_wcslen((U16*)cur_str_tail);
        mmi_wcscpy(cur_str_tail, (U16*)MMI_EM_DEV_MEM_TEST_EMI_SETTING_NEW_LINE);
        cur_str_tail += 1;
    }
    *cur_str_tail = 0;
    return cur_str_head;    
}

static U16* mmi_em_dev_memory_test_compose_custom_setting_text(MEM_DEV_INFO_T *mem_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *cur_str_tail = NULL;
    U16 *cur_str_head = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mem_info)
    {
        return NULL;
    }

    cur_str_head = (U16*)get_ctrl_buffer(MMI_EM_DEV_MEM_TEST_CUST_SETTING_BUF_SIZE);
    cur_str_tail = cur_str_head;
    
    if (mem_info->NORPresent)
    {
        kal_wsprintf(cur_str_tail, MMI_EM_DEV_MEM_TEST_CUST_SETTING_CONT_TEMP,
            MMI_EM_DEV_MEM_TEST_FLASH_INFO_NOR,
            MMI_EM_DEV_MEM_TEST_CUST_SETTING_NOR_START_ADDR,
            mem_info->NORConfInfo.FSBaseAddress,
            MMI_EM_DEV_MEM_TEST_CUST_SETTING_LENGTH,
            mem_info->NORConfInfo.FSTotalSize,
            MMI_EM_DEV_MEM_TEST_CUST_SETTING_FIRST_DRV_SIZE,
            mem_info->NORConfInfo.FSFirstDriveSize,
            MMI_EM_DEV_MEM_TEST_CUST_SETTING_FDM,
            mem_info->NORFDMVer);
        cur_str_tail += mmi_wcslen(cur_str_tail);
        kal_wsprintf(cur_str_tail, "\n");
        cur_str_tail++;
    }

    if (mem_info->NANDPresent)
    {        
        kal_wsprintf(cur_str_tail, MMI_EM_DEV_MEM_TEST_CUST_SETTING_CONT_TEMP,
            MMI_EM_DEV_MEM_TEST_FLASH_INFO_NAND,
            MMI_EM_DEV_MEM_TEST_CUST_SETTING_NAND_START_ADDR,
            mem_info->NANDConfInfo.FSBaseAddress,
            MMI_EM_DEV_MEM_TEST_CUST_SETTING_LENGTH,
            mem_info->NANDConfInfo.FSTotalSize,
            MMI_EM_DEV_MEM_TEST_CUST_SETTING_FIRST_DRV_SIZE,
            mem_info->NANDConfInfo.FSFirstDriveSize,
            MMI_EM_DEV_MEM_TEST_CUST_SETTING_FDM,
            mem_info->NANDFDMVer);
        cur_str_tail += mmi_wcslen(cur_str_tail);
    }

    *cur_str_tail = 0;
    return cur_str_head;
}

static U16* mmi_em_dev_memory_test_compose_flash_info_text(MEM_DEV_INFO_T *mem_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *cur_str_tail = NULL;
    U8 dev_id[MMI_EM_DEV_MEM_TEST_FLASH_INFO_TMP_STR_LEN];
    U16 *cur_str_head = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mem_info)
    {
        return NULL;
    }
    cur_str_head = (U16*)get_ctrl_buffer(MMI_EM_DEV_MEM_TEST_FLASH_INFO_BUF_SIZE);
    cur_str_tail = cur_str_head;

    if (mem_info->NORPresent)
    {
        sprintf((char*)dev_id, "0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X",
            mem_info->NORDevInfo.DeviceInfo.NOR.DeviceID[0],
            mem_info->NORDevInfo.DeviceInfo.NOR.DeviceID[1],
            mem_info->NORDevInfo.DeviceInfo.NOR.DeviceID[2],
            mem_info->NORDevInfo.DeviceInfo.NOR.DeviceID[3],
            mem_info->NORDevInfo.DeviceInfo.NOR.DeviceID[4],
            mem_info->NORDevInfo.DeviceInfo.NOR.DeviceID[5],
            mem_info->NORDevInfo.DeviceInfo.NOR.DeviceID[6],
            mem_info->NORDevInfo.DeviceInfo.NOR.DeviceID[7]);
        kal_wsprintf(cur_str_tail, 
            MMI_EM_DEV_MEM_TEST_FLASH_INFO_NOR_CONT_TEMP,
            MMI_EM_DEV_MEM_TEST_FLASH_INFO_NOR,
            MMI_EM_DEV_MEM_TEST_FLASH_INFO_DEV_ID,
            dev_id,
            MMI_EM_DEV_MEM_TEST_FLASH_INFO_DEV_SIZE,
            mem_info->NORDevInfo.DeviceInfo.NOR.DeviceSize,
            MMI_EM_DEV_MEM_TEST_FLASH_INFO_BOOT_MODE,
            mem_info->NORDevInfo.DeviceInfo.NOR.BootLocation);
        cur_str_tail += mmi_wcslen(cur_str_tail);
    }

    if (mem_info->NANDPresent)
    {
        sprintf((char*)dev_id, "0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X 0x%X",
            mem_info->NANDDevInfo.DeviceInfo.NAND.DeviceID[0],
            mem_info->NANDDevInfo.DeviceInfo.NAND.DeviceID[1],
            mem_info->NANDDevInfo.DeviceInfo.NAND.DeviceID[2],
            mem_info->NANDDevInfo.DeviceInfo.NAND.DeviceID[3],
            mem_info->NANDDevInfo.DeviceInfo.NAND.DeviceID[4],
            mem_info->NANDDevInfo.DeviceInfo.NAND.DeviceID[5],
            mem_info->NANDDevInfo.DeviceInfo.NAND.DeviceID[6],
            mem_info->NANDDevInfo.DeviceInfo.NAND.DeviceID[7]);
        kal_wsprintf(cur_str_tail,
            MMI_EM_DEV_MEM_TEST_FLASH_INFO_NAND_CONT_TEMP,
            MMI_EM_DEV_MEM_TEST_FLASH_INFO_NAND,
            MMI_EM_DEV_MEM_TEST_FLASH_INFO_DEV_ID,
            dev_id,
            MMI_EM_DEV_MEM_TEST_FLASH_INFO_DEV_SIZE,
            mem_info->NANDDevInfo.DeviceInfo.NAND.DeviceSize,
            MMI_EM_DEV_MEM_TEST_FLASH_INFO_PAGE_SIZE,
            mem_info->NANDDevInfo.DeviceInfo.NAND.PageSize,
            MMI_EM_DEV_MEM_TEST_FLASH_INFO_BLOCK_SIZE,
            mem_info->NANDDevInfo.DeviceInfo.NAND.BlockSize);
        cur_str_tail += mmi_wcslen(cur_str_tail);
    }

    *cur_str_tail = 0;
    return cur_str_head;
}
#endif /* defined(__MMI_EM_DEV_MEMORY_TEST__) */



#define EM_DEV_TST_OUTPUT_MODE
/*-----------------------------------------------------------------------------*/
/*------------------------ Device -> TST output mode --------------------------*/
/*-----------------------------------------------------------------------------*/
#if defined(__MMI_EM_DEV_TST_OUTPUT_MODE__)
/*****************************************************************************
 * FUNCTION
 *  EmDevSetTSTOutputMode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void EmDevSetTSTOutputMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_EmDevTST_Ouput_mode = currentHighlightIndex;
    
    EngineerModeSetUartReq(
        UART_NVRAM_LID_FUNC_TST_OUTPUT_MODE, 
        mmi_em_dev_set_tst_output_mode_send_uart_req,
        (void*)mmi_em_dev_set_uart_cntx_p);
}

static void mmi_em_dev_set_tst_output_mode_send_uart_req(void* data)
{
    mmi_em_dev_set_uart_cntx_struct* cntx_p = (mmi_em_dev_set_uart_cntx_struct*)data;
    U8 *app_port_array = NULL;
    
    
    if (NULL == cntx_p)
    {
        return;
    }
    
    app_port_array = cntx_p->app_port_arry;
    
#if defined(__DSPIRDBG__)&& defined(__MMI_USB_SUPPORT__)
    if (g_EmDevTST_Ouput_mode == EM_USB_LOGGING_IRDBG)
    {
        if( (app_port_array[EM_APP_PS]==uart_port_usb) || 
            (app_port_array[EM_APP_TST_PS]==uart_port_usb) ||
            (app_port_array[EM_APP_TST_L1]==uart_port_usb) ||
            (app_port_array[EM_APP_CTI]==uart_port_usb))
        {
            app_port_array[EM_APP_TST_PS] = uart_port2;
            app_port_array[EM_APP_TST_L1] = uart_port2;
            app_port_array[EM_APP_PS] = uart_port1;
            app_port_array[EM_APP_CTI] = uart_port_null;
        }
    }
#endif /* __DISPIRDBG__) */

    UART_setting = KAL_FALSE;
}

static MMI_RET mmi_em_dev_tst_output_hdlr(cui_menu_event_struct *evt)
{
    g_em_set_uart_req_type = EM_SET_UART_TST_OUTPUT_MODE;

    if(MENU_ID_EM_DEV_TST_OUTPUT_MODE == evt->highlighted_menu_id)
    {
        EngineerModeGetUartReq();
    }

    return MMI_RET_OK;
}

static mmi_ret mmi_em_dev_tst_output_scrn_proc(mmi_event_struct* evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            U16 ItemList[] = 
            {
                STR_ID_EM_DEV_TST_OUTPUT_MODE_UART,
                STR_ID_EM_DEV_TST_OUTPUT_MODE_FILE,
                STR_ID_EM_DEV_TST_OUTPUT_MODE_BOTH,
            };
            mmi_frm_scrn_active_evt_struct* active_evt = (mmi_frm_scrn_active_evt_struct*)evt;
            
            
            currentHighlightIndex = g_EmDevTST_Ouput_mode;
            ShowCategory11Screen(
                STR_ID_EM_DEV_TST_OUTPUT_MODE,
                0,
                STR_GLOBAL_OK,
                0,
                STR_GLOBAL_BACK,
                0,
                3,
                ItemList,
                currentHighlightIndex,
                active_evt->gui_buffer);
            
            break;
        }
        
        case EVT_ID_SCRN_HIGHLIGHT_CHANGE:
        {
            cat_evt_struct *cat_evt = (cat_evt_struct *)evt;
            currentHighlightIndex = cat_evt->item_index;
            return MMI_RET_CHANGED;
        }
        
        case EVT_ID_WGUI_LSK_CLICK:
        {
            EmDevSetTSTOutputMode();
            return MMI_RET_KEY_HANDLED;
        }
    }
    
    return MMI_RET_OK;
}

static void mmi_em_dev_tst_output_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_create(mmi_em_get_root_group(),
        SCR_ID_EM_DEV_TST_OUTPUT_MODE,
        mmi_em_dev_tst_output_scrn_proc,
        NULL);
}
#endif /* #if defined(__MMI_EM_DEV_TST_OUTPUT_MODE__) */


#define EM_DEV_USB_LOGGING
/*-----------------------------------------------------------------------------*/
/*-------------------------- Device -> USB logging ----------------------------*/
/*-----------------------------------------------------------------------------*/
#ifdef __MMI_EM_DEV_USB_LOGGING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __DSPIRDBG__
/* under construction !*/
/* under construction !*/
    #endif /* __DSPIRDBG__ */
/* under construction !*/
    #if defined(__MODEM_3G_LOGGING__)
/* under construction !*/
/* under construction !*/
    #endif /* __MODEM_3G_LOGGING__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __USB_MULTIPLE_COMPORT_SUPPORT__
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_EM_DEV_USB_LOGGING__ */


#define EM_DEV_DCM
/*-----------------------------------------------------------------------------*/
/*------------------------------- Device -> DCM -------------------------------*/
/*-----------------------------------------------------------------------------*/
#ifdef __MMI_EM_DEV_DCM_MODE__
static void mmi_em_device_set_dcm_mode_hdlr(MMI_ID menu_id)
{    
    g_dcm_enable = (MENU_ID_EM_DEV_DCM_MODE_OFF != menu_id);

    EngineerModeSetDCMModeReq(g_dcm_enable);
}

/*****************************************************************************
 * FUNCTION
 *  EngineerModeSetDCMModeReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_on       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void EngineerModeSetDCMModeReq(U16 is_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_dcm_enable_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = OslConstructDataPtr(sizeof(mmi_eq_dcm_enable_req_struct));
    msg_p->enable = (is_on > 0 ? KAL_TRUE : KAL_FALSE);
    EngineerModeSendMsg(MSG_ID_MMI_EQ_DCM_ENABLE_REQ, msg_p, NULL);
    mmi_em_success_popup();
}
#endif /* (__MMI_EM_DEV_DCM_MODE__)) */ 


#define EM_DEV_SET_UART

/*-----------------------------------------------------------------------------*/
/*------------------------------- Device -> BQB -------------------------------*/
/*-----------------------------------------------------------------------------*/

#ifdef __MMI_BT_DIALER_SUPPORT__
static void mmi_em_device_set_bqb_mode_hdlr(MMI_ID menu_id)
{    
    MMI_BOOL set_bqb = (menu_id == MENU_ID_EM_DEV_BQB_MODE_ON);
    srv_bt_cm_set_bqb_test_flag(set_bqb);
    mmi_em_success_popup();
}

#endif

/*-----------------------------------------------------------------------------*/
/*---------------------------- Device -> Set UART -----------------------------*/
/*-----------------------------------------------------------------------------*/
#ifdef __MMI_EM_DEV_SET_UART__
MMI_EM_INIT_ASM(dev_set_uart, mmi_em_dev_set_uart_cntx_p, sizeof(mmi_em_dev_set_uart_cntx_struct))

static void mmi_em_dev_uart_hdlr(void)
{
    MMI_EM_ASM_INIT_FUNC(dev_set_uart);
}


void mmi_em_dev_stop_uart_hdlr(void)
{
    MMI_EM_ASM_FREE_FUNC(dev_set_uart);
    MMI_EM_UNREG_STOP_FUNC(MMI_EM_ASM_STOP_FUNC(dev_set_uart));
}

static void mmi_em_dev_pre_entry_uart_menu(void)
{
    cui_menu_set_item_hidden(
        mmi_em_get_main_menu_id(), 
        MENU_ID_EM_DEV_UART_SETTING, 
        (MMI_BOOL)(!nvram_sec_port_is_enable()));
}
#endif /* __MMI_EM_DEV_SET_UART__ */

static const U32 g_mmi_em_dev_get_band_rate[] = 
{
    UART_BAUD_AUTO,
    UART_BAUD_75,
    UART_BAUD_150,
    UART_BAUD_300,
    UART_BAUD_600,
    UART_BAUD_1200,
    UART_BAUD_2400,
    UART_BAUD_4800,
    UART_BAUD_7200,
    UART_BAUD_9600,
    UART_BAUD_14400,
    UART_BAUD_19200,
    UART_BAUD_28800,
    UART_BAUD_33900,
    UART_BAUD_38400,
    UART_BAUD_57600,
    UART_BAUD_115200,
    UART_BAUD_230400,
    UART_BAUD_460800,
    UART_BAUD_921600,
    UART_BAUD_1500000
};

/*****************************************************************************
 * FUNCTION
 *  EM_GetBaudRateByIdx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 EM_GetBaudRateByIdx(U8 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (idx > 20)
    {
        return UART_BAUD_115200;
    }
         
    return g_mmi_em_dev_get_band_rate[idx];
}


/*****************************************************************************
 * FUNCTION
 *  EM_GetIdxByBaudRate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  baud        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 EM_GetIdxByBaudRate(U32 baud)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 range = sizeof(g_mmi_em_dev_get_band_rate)/sizeof(U32);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < range; i++)
    {
        if (baud == g_mmi_em_dev_get_band_rate[i])
            return i;
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  EngineerModeGetUartReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ConfApp     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGetUartReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(MSG_ID_EM_GET_UART_RSP, EngineerModeGetUartRes, MMI_FALSE);
    mmi_em_dev_uart_hdlr();
    EngineerModeSendMsg(MSG_ID_MMI_EQ_GET_UART_REQ, NULL, NULL);
}

typedef struct
{
    U8 dev_uart_port;           // uart port of device
    EM_PORT_ENUM mmi_uart_port; // uart port of mmi
    U8 uart_type;
} mmi_em_app_uart_port;

#define MMI_EM_APP_ALL      (0XFF)
#define MMI_EM_APP_TST_PS   (0X01)
#define MMI_EM_APP_PS       (0X02)
#define MMI_EM_APP_TST_L1   (0X04)
#define MMI_EM_APP_CTI      (0X08)    
#define MMI_EM_APP_TST_DSP  (0X10)

#define MMI_EM_UART_SET_BIT(_num) (MMI_EM_APP_TST_PS << (_num))

static const mmi_em_app_uart_port mmi_em_dev_uart_port[] = 
{
#ifdef __USB_COMPORT_SUPPORT_TC01_DRIVER__
    {uart_port_usb,  EM_USB_PORT, MMI_EM_APP_PS},
    {uart_port_usb2, EM_USB_PORT, MMI_EM_APP_TST_L1 | MMI_EM_APP_TST_PS},
    {uart_port_null, EM_USB_PORT_2, MMI_EM_APP_ALL ^ MMI_EM_APP_CTI ^ MMI_EM_APP_TST_DSP},
#else
#if defined(__MMI_USB_SUPPORT__)&& defined(__USB_COM_PORT_ENABLE__)
    {uart_port_usb,  EM_USB_PORT, MMI_EM_APP_ALL},
#ifdef __USB_MULTIPLE_COMPORT_SUPPORT__
    {uart_port_usb2, EM_USB_PORT_2, MMI_EM_APP_ALL},
#endif /* __USB_MULTIPLE_COMPORT_SUPPORT__ */
#endif /* __MMI_USB_SUPPORT__ && __USB_COM_PORT_ENABLE__ */
    {uart_port_null, EM_UART_PORT_NULL, MMI_EM_APP_ALL},
#endif /* __USB_COMPORT_SUPPORT_TC01_DRIVER__ */

#ifdef __TST_LMU_LOGGING__
    {uart_port_lmu, EM_UART_PORT_LMU, MMI_EM_APP_TST_PS | MMI_EM_APP_TST_L1 | MMI_EM_APP_TST_DSP}
#endif
};




/*****************************************************************************
 * FUNCTION
 *  EngineerModeGetUartRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 EngineerModeGetUartRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_get_uart_rsp_struct *rsp_p = inMsg;
    U32 range = sizeof(mmi_em_dev_uart_port)/sizeof(mmi_em_app_uart_port);
    U8* app_port_arry = mmi_em_dev_set_uart_cntx_p->app_port_arry;
    U8* app_band_arry = mmi_em_dev_set_uart_cntx_p->app_band_arry;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_em_dev_set_uart_cntx_p)
    {
        mmi_em_dev_set_uart_cntx_p->swdbg = rsp_p->swdbg;
        mmi_em_dev_set_uart_cntx_p->high_speed_sim = rsp_p->high_Speed_SIM_Enabled;
        mmi_em_dev_set_uart_cntx_p->uart_power_setting = rsp_p->uart_power_setting;
    }
    
    if (rsp_p->result)
    {
        if (mmi_em_dev_set_uart_cntx_p)
        {
            app_port_arry[EM_APP_TST_PS] = rsp_p->tst_uart_port_ps;
            app_port_arry[EM_APP_PS] = rsp_p->ps_uart_port;
            app_port_arry[EM_APP_TST_L1] = rsp_p->tst_uart_port_l1;
            app_port_arry[EM_APP_CTI] = rsp_p->cti_uart_port;
            app_port_arry[EM_APP_TST_DSP] = rsp_p->tst_port_dsp; 

            app_band_arry[EM_APP_TST_PS] = EM_GetIdxByBaudRate(rsp_p->tst_baud_rate_ps);
            app_band_arry[EM_APP_PS] = EM_GetIdxByBaudRate(rsp_p->ps_baud_rate);
            app_band_arry[EM_APP_TST_L1] = EM_GetIdxByBaudRate(rsp_p->tst_baud_rate_l1);
            app_band_arry[EM_APP_CTI] = EM_GetIdxByBaudRate(rsp_p->cti_baud_rate);
            app_band_arry[EM_APP_TST_DSP] = EM_GetIdxByBaudRate(rsp_p->tst_baud_rate_dsp);

            /**************************/
            /* TST-PS Port & Baudrate */
            /**************************/
            mmi_em_dev_uart_map_dev_port_to_mmi_port(
                &mmi_em_dev_set_uart_cntx_p->port_tst,
                EM_APP_TST_PS, range, app_port_arry,
                &mmi_em_dev_set_uart_cntx_p->baud_tst,
                app_band_arry);
            
            mmi_em_set_hilit_port(&mmi_em_dev_set_uart_cntx_p->port_tst);

            /**************************/
            /*** PS Port & Baudrate ***/
            /**************************/
            mmi_em_dev_uart_map_dev_port_to_mmi_port(
                &mmi_em_dev_set_uart_cntx_p->port_ps,
                EM_APP_PS, range, app_port_arry,
                &mmi_em_dev_set_uart_cntx_p->baud_ps,
                app_band_arry);

            //mmi_em_set_hilit_port(&mmi_em_dev_set_uart_cntx_p->port_ps);

            /**************************/
            /* TST-L1 Port & Baudrate */
            /**************************/
            mmi_em_dev_uart_map_dev_port_to_mmi_port(
                &mmi_em_dev_set_uart_cntx_p->port_tstl1,
                EM_APP_TST_L1, range, app_port_arry,
                &mmi_em_dev_set_uart_cntx_p->baud_tstl1,
                app_band_arry);

            mmi_em_set_hilit_port(&mmi_em_dev_set_uart_cntx_p->port_tstl1);

            /**************************/
            /** CTI Port & Baudrate ***/
            /**************************/
            mmi_em_dev_uart_map_dev_port_to_mmi_port(
                &mmi_em_dev_set_uart_cntx_p->port_cti,
                EM_APP_CTI, range, app_port_arry,
                &mmi_em_dev_set_uart_cntx_p->baud_cti,
                app_band_arry);
        
            /***************************/
            /* TST-DSP Port & Baudrate */
            /***************************/
            mmi_em_dev_uart_map_dev_port_to_mmi_port(
                &mmi_em_dev_set_uart_cntx_p->port_dsp,
                EM_APP_TST_DSP, range, app_port_arry,
                &mmi_em_dev_set_uart_cntx_p->band_dsp,
                app_band_arry);
        }
        else
        {
            mmi_em_fail_popup();
            return 0;
        }

        g_EmDevTST_Ouput_mode = rsp_p->tst_output_mode;

    #ifdef __MMI_EM_DEV_USB_LOGGING__
/* under construction !*/
    #endif

        switch(g_em_set_uart_req_type)
        {
        #ifdef __MMI_EM_DEV_SET_UART__
            case EM_SET_UART_UART_SETTING:
            {
                mmi_em_device_uart_setting_scrn();
                break;
            }
        #endif /* __MMI_EM_DEV_SET_UART__ */
        
        #if defined(__MMI_EM_MISC_HIGHSPEED_SIM__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* #if defined(__MMI_EM_MISC_HIGHSPEED_SIM__) */

        #if defined(__MMI_EM_DEV_TST_OUTPUT_MODE__)
            case EM_SET_UART_TST_OUTPUT_MODE:
            {
                mmi_em_dev_tst_output_scrn();
                break;
            }
        #endif /* #if defined(__MMI_EM_DEV_TST_OUTPUT_MODE__) */
        #ifdef __MMI_EM_DEV_USB_LOGGING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /*  __MMI_EM_DEV_USB_LOGGING__ */
        }
    }
	return 0;
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeSetUartReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeSetUartReq(uart_nvram_lid_function_enum func_id, EM_SEND_UART_PROC proc, void * proc_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_uart_req_struct *msg_p;
    U8 *app_port_array = mmi_em_dev_set_uart_cntx_p->app_port_arry;
    U8 *app_band_array = mmi_em_dev_set_uart_cntx_p->app_band_arry;
    //extern kal_uint8 SWDBG_Profile;
    //extern kal_uint8 UART_POWER_SETTING;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = OslConstructDataPtr(sizeof(mmi_eq_set_uart_req_struct));

    msg_p->func_id = func_id;
    
    if (NULL != proc)
    {
        proc(proc_param);
    }

    msg_p->ps_port = app_port_array[EM_APP_PS];
    msg_p->tst_port_ps = app_port_array[EM_APP_TST_PS];
    msg_p->tst_port_l1 = app_port_array[EM_APP_TST_L1];
    msg_p->cti_uart_port = app_port_array[EM_APP_CTI];
    
    msg_p->ps_baud_rate = EM_GetBaudRateByIdx(app_band_array[EM_APP_PS]);
    msg_p->tst_baud_rate_ps = EM_GetBaudRateByIdx(app_band_array[EM_APP_TST_PS]);
    msg_p->tst_baud_rate_l1 = EM_GetBaudRateByIdx(app_band_array[EM_APP_TST_L1]);
    msg_p->cti_baud_rate = EM_GetBaudRateByIdx(app_band_array[EM_APP_CTI]);
    
    msg_p->tst_port_dsp= app_port_array[EM_APP_TST_DSP];
    msg_p->tst_baud_rate_dsp= EM_GetBaudRateByIdx(app_band_array[EM_APP_TST_DSP]);

    msg_p->High_Speed_SIM_Enabled = mmi_em_dev_set_uart_cntx_p->high_speed_sim; //High_Speed_SIM;
    msg_p->swdbg = mmi_em_dev_set_uart_cntx_p->swdbg; //SWDBG_Profile;
    msg_p->uart_power_setting = mmi_em_dev_set_uart_cntx_p->uart_power_setting; //UART_POWER_SETTING;

    msg_p->tst_output_mode = g_EmDevTST_Ouput_mode;

#ifdef __MMI_EM_DEV_USB_LOGGING__
/* under construction !*/
#endif

    EngineerModeSendMsg(MSG_ID_MMI_EQ_SET_UART_REQ, msg_p, NULL);
}


#if (defined(COSMOS_EM_INTERNAL_DCM) || defined(PLUTO_EM_INTERNAL_DCM))
#pragma arm section rodata , code
#endif /* COSMOS_EM_INTERNAL_DCM || PLUTO_EM_INTERNAL_DCM */ 


/*****************************************************************************
 * FUNCTION
 *  EngineerModeSetUartRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeSetUartRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_uart_rsp_struct *rsp_p = inMsg;
    //extern kal_uint8 SWDBG_Profile;
#ifdef __DYNAMIC_UART_PORT_SWITCHING__
    U8* app_port_array = mmi_em_dev_set_uart_cntx_p->app_port_arry;
    U8* app_band_array = mmi_em_dev_set_uart_cntx_p->app_band_arry;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EM_DCM_LOAD();
    if (rsp_p->result)
    {
        /* Lisen 09062005 */
    #ifndef __DYNAMIC_UART_PORT_SWITCHING__
        mmi_em_dev_stop_uart_hdlr();
        EngineerModeSuccessRebootNotice(STR_ID_EM_NOTICE_SUCCESS_REBOO);
    #else /* __DYNAMIC_UART_PORT_SWITCHING__ */ 
        if (UART_setting == TRUE &&
            (old_tst_port != app_port_array[EM_APP_TST_PS] ||
             old_ps_port != app_port_array[EM_APP_PS] ||
             old_tst_baudrate != EM_GetBaudRateByIdx(app_band_array[EM_APP_TST_PS]) ||
             old_ps_baudrate != EM_GetBaudRateByIdx(app_band_array[EM_APP_PS])))
        {
            EngineeringModeUartSendDetachReq();
            EmSetUartMsgDepth = 0;
        }
        else
        {
            mmi_em_success_popup();
            mmi_em_dev_set_uart_close_inline();
        }

        UART_setting = FALSE;
    #endif /* __DYNAMIC_UART_PORT_SWITCHING__ */ /* __SHUTDOWN_AFTER_UART_PORT_SETTING__ */
    }
    else
    {
        mmi_em_popup_by_str(STR_ID_EM_WARNING, MMI_EVENT_WARNING);
    }
    MMI_EM_DCM_SEND_UNLOAD();
}


#if defined(PLUTO_EM_INTERNAL_DCM)
#pragma arm section rodata = "DYNAMIC_CODE_EM_RODATA" , code = "DYNAMIC_CODE_EM_ROCODE"
#elif defined(COSMOS_EM_INTERNAL_DCM)
#pragma arm section rodata = "DYNAMIC_CODE_COSMOS_EM_RODATA" , code = "DYNAMIC_CODE_COSMOS_EM_ROCODE"
#endif /* PLUTO_EM_INTERNAL_DCM */ 


void mmi_em_dev_set_high_speed_sim(MMI_BOOL on)
{
    if (mmi_em_dev_set_uart_cntx_p)
    {
        mmi_em_dev_set_uart_cntx_p->high_speed_sim = on;
    }
}

#ifdef __DYNAMIC_UART_PORT_SWITCHING__
/*****************************************************************************
 * FUNCTION
 *  EngineeringModeUartSendDetachReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EngineeringModeUartSendDetachReq()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_detach_uart_port_req_struct *msp_p_detach_uart1;
    mmi_detach_uart_port_req_struct *msp_p_detach_uart2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EmSetUartMsgDepth = 0;

    /* Detach for TST */
    msp_p_detach_uart1 = OslConstructDataPtr(sizeof(mmi_detach_uart_port_req_struct));
    msp_p_detach_uart1->module_id = MOD_TST_READER;
    msp_p_detach_uart1->port = old_tst_port;

    /* Detach for L4C */
    msp_p_detach_uart2 = OslConstructDataPtr(sizeof(mmi_detach_uart_port_req_struct));
    msp_p_detach_uart2->module_id = MOD_L4C;
    msp_p_detach_uart2->port = old_ps_port;

    EngineerModeSendMsg(MSG_ID_MMI_DETACH_UART_PORT_REQ, msp_p_detach_uart1, NULL);
    EngineerModeSendMsg(MSG_ID_MMI_DETACH_UART_PORT_REQ, msp_p_detach_uart2, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeDetachUartRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeDetachUartRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_attach_uart_port_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!rsp_p->result)
    {
        EmSetUartMsgDepth++;
        if (EmSetUartMsgDepth == 2)
        {
            EngineeringModeUartSendAttachReq();
            EmSetUartMsgDepth = 0;
        }
    }
    else
    {
        mmi_em_fail_popup();
        mmi_em_dev_set_uart_close_inline();
    }
}

/*****************************************************************************
 * FUNCTION
 *  EngineeringModeUartSendAttachReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EngineeringModeUartSendAttachReq()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_attach_uart_port_req_struct *msp_p_uart1;
    mmi_attach_uart_port_req_struct *msp_p_uart2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Attach for TST */
    msp_p_uart1 = OslConstructDataPtr(sizeof(mmi_attach_uart_port_req_struct));
    msp_p_uart1->module_id = MOD_TST_READER;
    msp_p_uart1->port = EmAppPortArray[EM_APP_TST_PS];
    msp_p_uart1->baud_rate = EM_GetBaudRateByIdx(EmAppBaudArray[EM_APP_TST_PS]);

    /* Attach for L4C */
    msp_p_uart2 = OslConstructDataPtr(sizeof(mmi_attach_uart_port_req_struct));
    msp_p_uart2->module_id = MOD_L4C;
    msp_p_uart2->port = EmAppPortArray[EM_APP_PS];
    msp_p_uart2->baud_rate = EM_GetBaudRateByIdx(EmAppBaudArray[EM_APP_PS]);

    EmSetUartMsgDepth = 0;
    EngineerModeSendMsg(MSG_ID_MMI_ATTACH_UART_PORT_REQ, msp_p_uart1, NULL);
    EngineerModeSendMsg(MSG_ID_MMI_ATTACH_UART_PORT_REQ, msp_p_uart2, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeAttachUartRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeAttachUartRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_attach_uart_port_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!rsp_p->result)
    {
        EmSetUartMsgDepth++;
        if (EmSetUartMsgDepth == 2)
        {
            mmi_em_success_popup();
            EmSetUartMsgDepth = 0;
        }
    }
    else
    {
        mmi_em_fail_popup();
    }
    mmi_em_dev_set_uart_close_inline();
}
#endif

#ifdef __MMI_EM_DEV_SET_UART__
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  EmIsPortAllow
 * DESCRIPTION
 *  
 * PARAMETERS
 *  port_num        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static BOOL EmIsPortAllow(U8 port_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
/*
    if (mmi_em_dev_get_uart_owner_id(uart_port3) != (module_type)((kal_uint16)MOD_UART1_HISR + (kal_uint8)uart_port3))
    {
        return MMI_FALSE;
    }
*/

#ifndef L4_NOT_PRESENT
    if ((PS_UART_PORT == TST_PORT) && (PS_UART_PORT!=uart_port_null))
    {
        return MMI_FALSE;
    }
#endif /* L4_NOT_PRESENT */ 

#if defined(__MMI_IRDA_SUPPORT__)
    {
    #ifndef L4_NOT_PRESENT
        if (PS_UART_PORT == uart_port_irda)
        {
            return MMI_FALSE;
        }
    #endif /* L4_NOT_PRESENT */ 
    }
#endif /* defined(__MMI_IRDA_SUPPORT__) */ 

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  SendSetUartReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void SendSetUartReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 tst_port_highlight;
    U32 tst_l1_highlight;
    U32 ps_port_highlight;
    MMI_BOOL port_conflict = MMI_FALSE;
    U8 range = sizeof(mmi_em_dev_uart_port) / sizeof(mmi_em_app_uart_port);
    U8* app_port_array = mmi_em_dev_set_uart_cntx_p->app_port_arry;
    U8* app_band_array = mmi_em_dev_set_uart_cntx_p->app_band_arry;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tst_port_highlight = mmi_em_get_highlight_port(mmi_em_dev_set_uart_cntx_p->port_tst);
    tst_l1_highlight = mmi_em_get_highlight_port(mmi_em_dev_set_uart_cntx_p->port_tstl1);
    ps_port_highlight = mmi_em_dev_set_uart_cntx_p->port_ps;

    /* Check TST Port Setting & PS Port Setting */
    if (port_conflict 
        || EmIsPortAllow((U8) tst_port_highlight) == MMI_FALSE 
        || EmIsPortAllow((U8) ps_port_highlight) == MMI_FALSE
        || EmIsPortAllow((U8) tst_l1_highlight) == MMI_FALSE  
        #if defined(__MA_L1__)
/* under construction !*/
        #endif
        #if defined(__DSP_FCORE4__)
        || EmIsPortAllow((U8) mmi_em_dev_set_uart_cntx_p->port_dsp) == MMI_FALSE
        #endif
        /* Check TST & PS & CTI conflict */
        || ( (tst_port_highlight == ps_port_highlight) && (tst_port_highlight!= EM_UART_PORT_NULL)) 
        || ( (tst_l1_highlight == ps_port_highlight) && (tst_l1_highlight != EM_UART_PORT_NULL)) 
    #if defined(__MA_L1__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #if defined(__MMI_USB_SUPPORT__ ) && defined(__USB_COM_PORT_ENABLE__) && defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
        || ( (tst_port_highlight == EM_USB_PORT || tst_l1_highlight == EM_USB_PORT)
             && (ps_port_highlight== EM_USB_PORT_2) )
    #endif
    #if defined(__MMI_USB_SUPPORT__ ) && defined(__USB_COM_PORT_ENABLE__) && defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
        || ( (tst_port_highlight == EM_USB_PORT && tst_l1_highlight == EM_USB_PORT)
        ||   (tst_port_highlight == EM_USB_PORT && tst_l1_highlight == NULL)
        ||   (tst_port_highlight == EM_USB_PORT && tst_l1_highlight == EM_USB_PORT_2)
        ||   (tst_port_highlight == NULL && tst_l1_highlight == EM_USB_PORT)
        ||   (tst_port_highlight == EM_USB_PORT_2 && tst_l1_highlight == EM_USB_PORT))    
    #endif
    #if defined(__MMI_ONLY_ONE_UART_AVAILABLE__)
        || tst_port_highlight==EM_UART_PORT_2 
        || ps_port_highlight==EM_UART_PORT_2
        || tst_l1_highlight==EM_UART_PORT_2
    #endif
    )
    {
        port_conflict = MMI_TRUE;
    }

    /* Check USB tethering and PS conflict*/
#if defined(__USB_TETHERING__) && defined(__MTK_TARGET__)
    if ( port_conflict
    #if defined(__MMI_USB_SUPPORT__) && defined(__USB_COM_PORT_ENABLE__)
        || ps_port_highlight == EM_USB_PORT
    #endif
    )
    {
    	DCL_HANDLE usb_handle;
    	DCL_BOOL  dcl_data;

//			usb_handle = DclSerialPort_Open(uart_port_usb,0);
//			DclSerialPort_Control(usb_handle,USB_CMD_GET_RNDIS_MODE, (DCL_CTRL_DATA_T *)&dcl_data);
//			DclSerialPort_Close(usb_handle);
						    
    	usb_handle = DclUSB_DRV_Open(DCL_USB, FLAGS_NONE);
    	DclUSB_DRV_Control(usb_handle, USB_DRV_CMD_GET_MENU_CONFIG, (DCL_CTRL_DATA_T *)&dcl_data);
    	DclUSB_DRV_Close(usb_handle);
	
    	if((kal_bool)dcl_data == KAL_TRUE) // if (USB_Get_RNDIS_Mode() == KAL_TRUE)
        {
            port_conflict = MMI_TRUE;
        }
    }
#endif

/* check LMU port conflict */
#if defined(__TST_LMU_LOGGING__)
{
    if (port_conflict || ps_port_highlight == EM_UART_PORT_LMU
        || (tst_port_highlight == EM_UART_PORT_LMU && tst_l1_highlight != EM_UART_PORT_LMU)
        || (tst_port_highlight != EM_UART_PORT_LMU && tst_l1_highlight == EM_UART_PORT_LMU)
        || (mmi_em_dev_set_uart_cntx_p->port_dsp == EM_UART_PORT_LMU && (tst_l1_highlight != EM_UART_PORT_LMU 
        || tst_port_highlight != EM_UART_PORT_LMU))
       )
    {
        port_conflict = MMI_TRUE;
    }
}    
#endif /* if defined(__TST_LMU_LOGGING__) */

    if (port_conflict == MMI_TRUE)
    {
        mmi_eq_set_uart_rsp_struct st_rsp;

        st_rsp.result = MMI_FALSE;
        EngineerModeSetUartRes(&st_rsp);
        return;
    }

/* check TST-DSP port conflict */
#if defined(__DSP_FCORE4__)
   do{
    MMI_BOOL port_conflict = MMI_FALSE;
    
    if (mmi_em_dev_set_uart_cntx_p->port_dsp != EM_UART_PORT_NULL)
    {
      
      //Only allow UART1, USB, USB2, LMU
      if ( (mmi_em_dev_set_uart_cntx_p->port_dsp != EM_UART_PORT_1) 
         #if defined(__MMI_USB_SUPPORT__) && defined(__USB_COM_PORT_ENABLE__)
            && (mmi_em_dev_set_uart_cntx_p->port_dsp != EM_USB_PORT) 
            #ifdef __USB_MULTIPLE_COMPORT_SUPPORT__
              && (mmi_em_dev_set_uart_cntx_p->port_dsp != EM_USB_PORT_2)
            #endif  // __USB_MULTIPLE_COMPORT_SUPPORT__
         #endif // __MMI_USB_SUPPORT__   
         #if defined(__TST_LMU_LOGGING__)
            && (mmi_em_dev_set_uart_cntx_p->port_dsp != EM_UART_PORT_LMU)
         #endif // __TST_LMU_LOGGING__
         )
      {
          port_conflict = MMI_TRUE;
      }
      else
      { //Can't the same as TST-PS, TST-L1, PS ports
        if ( (mmi_em_dev_set_uart_cntx_p->port_dsp == tst_port_highlight) ||
             (mmi_em_dev_set_uart_cntx_p->port_dsp == ps_port_highlight) ||
             (mmi_em_dev_set_uart_cntx_p->port_dsp == tst_l1_highlight)
           )
        {
          #if defined(__TST_LMU_LOGGING__)
          if (mmi_em_dev_set_uart_cntx_p->port_dsp != EM_UART_PORT_LMU)
          #endif
            port_conflict = MMI_TRUE;
          
        }
      }
    }
    
    if (port_conflict == MMI_TRUE)
    {
      mmi_eq_set_uart_rsp_struct st_rsp;

      st_rsp.result = MMI_FALSE;
      EngineerModeSetUartRes(&st_rsp);
      return;  
    }
  }while(0);
#endif /* #if defined(__DSP_FCORE4__) */

    /**************************/
    /* TST-PS UART & Baudrate */
    /**************************/
    mmi_em_dev_uart_map_mmi_port_to_dev_port(
        tst_port_highlight, EM_APP_TST_PS, 
        range, app_port_array,
        mmi_em_dev_set_uart_cntx_p->baud_tst,
        app_band_array);

    /**************************/
    /*** PS UART & Baudrate ***/
    /**************************/
    mmi_em_dev_uart_map_mmi_port_to_dev_port(
        ps_port_highlight, EM_APP_PS, 
        range, app_port_array,
        mmi_em_dev_set_uart_cntx_p->baud_ps,
        app_band_array);

    /**************************/
    /* TST-L1 UART & Baudrate */
    /**************************/
    mmi_em_dev_uart_map_mmi_port_to_dev_port(
        tst_l1_highlight, EM_APP_TST_L1,
        range, app_port_array,
        mmi_em_dev_set_uart_cntx_p->baud_tstl1,
        app_band_array);

    /**************************/
    /*** CTI UART & Baudrate **/
    /**************************/
    mmi_em_dev_uart_map_mmi_port_to_dev_port(
        mmi_em_dev_set_uart_cntx_p->port_cti, EM_APP_CTI, 
        range, app_port_array,
        mmi_em_dev_set_uart_cntx_p->baud_cti,
        app_band_array);

    /***************************/
    /* TST-DSP UART & Baudrate */
    /***************************/
    mmi_em_dev_uart_map_mmi_port_to_dev_port(
        mmi_em_dev_set_uart_cntx_p->port_dsp, EM_APP_TST_DSP, 
        range, app_port_array,
        mmi_em_dev_set_uart_cntx_p->band_dsp,
        app_band_array);

    mmi_frm_scrn_create(mmi_em_get_root_group(), GLOBAL_SCR_DUMMY, NULL, NULL);

    EngineerModeSetUartReq(
        UART_NVRAM_LID_FUNC_UART_CONFIG, 
        mmi_em_dev_set_uart_req_hdlr, 
        (void*)mmi_em_dev_set_uart_cntx_p);
}


static EM_SET_UART_INLINE mmi_em_get_highlight_port(U32 port)
{
#if defined(__MMI_USB_SUPPORT__) && defined(__USB_COM_PORT_ENABLE__) && defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
    #if defined(__USB_TETHERING__) || defined(__COMPOSITE_WEBCAM__)
        if (port >= (U32)EM_USB_PORT)
            return (EM_SET_UART_INLINE)(port + 1);
    #endif
#endif
    return (EM_SET_UART_INLINE)port;
}

static void mmi_em_set_hilit_port(U32* port)
{
#if defined(__MMI_USB_SUPPORT__) && defined(__USB_COM_PORT_ENABLE__) && defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
    #if defined(__USB_TETHERING__) || defined(__COMPOSITE_WEBCAM__)
        if ((*port) > (U32)EM_USB_PORT)
            (*port)--;  
    #endif
#endif
}

static void mmi_em_dev_uart_map_dev_port_to_mmi_port(
                U32 *highligh, EM_APP_UART_SETTING port_enum, 
                U32 range, U8* app_port_arry, 
                U32 *band, U8* app_band_arry)
{
    U32 i;
    

    *band = app_band_arry[port_enum];
    
    for(i = 0; i < range; i++)
    {
        if(app_port_arry[port_enum] == mmi_em_dev_uart_port[i].dev_uart_port &&
           (mmi_em_dev_uart_port[i].uart_type & MMI_EM_UART_SET_BIT(port_enum)))
        {
            *highligh = mmi_em_dev_uart_port[i].mmi_uart_port;
            return;
        }
    }
    
    if (i == range)
        *highligh = app_port_arry[port_enum];
}


static void mmi_em_dev_uart_map_mmi_port_to_dev_port(
                U32 highlight, EM_APP_UART_SETTING port_enum,
                U32 range, U8* app_port_arry,
                U32 band, U8* app_band_arry)
{
    U32 i = 0;
    
    
    app_band_arry[port_enum] = (U8)band;
    
    for(; i < range; i++)
    {
        if(highlight == mmi_em_dev_uart_port[i].mmi_uart_port && 
           (mmi_em_dev_uart_port[i].uart_type & MMI_EM_UART_SET_BIT(port_enum)))
        {
            app_port_arry[port_enum] = mmi_em_dev_uart_port[i].dev_uart_port;
            return;
        }
    }
    
    if (i == range)
        app_port_arry[port_enum] = highlight;
}

static void mmi_em_dev_set_uart_req_hdlr(void* data)
{
    mmi_em_dev_set_uart_cntx_struct* cntx_p = (mmi_em_dev_set_uart_cntx_struct*)data;
#ifdef __MMI_EM_DEV_USB_LOGGING__
/* under construction !*/
#endif
    
    if (NULL == cntx_p)
    {
        return;
    }
    
#ifdef __DYNAMIC_UART_PORT_SWITCHING__
    old_tst_port = TST_PORT;
    old_tst_baudrate = TST_BAUDRATE;
    old_ps_port = PS_UART_PORT;
    old_ps_baudrate = PS_BAUDRATE;
#endif
    
    UART_setting = KAL_TRUE;
    
#ifdef __MMI_EM_DEV_USB_LOGGING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __USB_MULTIPLE_COMPORT_SUPPORT__
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_EM_DEV_USB_LOGGING__ */
}


static void mmi_em_device_uart_setting_hdlr(void)
{
    g_em_set_uart_req_type = EM_SET_UART_UART_SETTING;
    EngineerModeGetUartReq();
}






static const cui_inline_item_caption_struct g_mmi_em_set_uart_tst_ps_cap = 
{
    STR_ID_EM_DEV_SET_UART_TST_PS,
};

static const U16 g_mmi_em_set_uart_tst_ps_str[] = {
                     STR_ID_EM_DEV_UART_1,
                     STR_ID_EM_DEV_UART_2,
                 #ifdef __UART3_SUPPORT__
                     STR_ID_EM_DEV_UART_3,
                 #endif 
                 #if defined(__MMI_USB_SUPPORT__) && defined(__USB_COM_PORT_ENABLE__)
                     STR_ID_EM_DEV_USB_PORT,
                 #ifdef __USB_MULTIPLE_COMPORT_SUPPORT__
                     STR_ID_EM_DEV_USB_PORT2,
                 #endif
                 #endif
                 #ifdef __TST_LMU_LOGGING__
                     STR_ID_EM_DEV_UART_PORT_LMU,
                 #endif
                 STR_GLOBAL_NONE};



#if defined(__USB_COMPORT_SUPPORT_TC01_DRIVER__)
static const U16 g_mmi_em_set_uart_port_test_only_usb[] = {
                     STR_ID_EM_DEV_UART_1,
                     STR_ID_EM_DEV_UART_2,
                 #ifdef __UART3_SUPPORT__
                     STR_ID_EM_DEV_UART_3,
                 #endif 
                 #ifdef __MMI_USB_SUPPORT__
                     STR_ID_EM_DEV_USB_PORT,
                 #ifdef __USB_MULTIPLE_COMPORT_SUPPORT__
                     STR_GLOBAL_NONE,
                 #endif
                 #endif
                 };

static const U16 g_mmi_em_set_uart_port_test_only_usb2[] = {
                     STR_ID_EM_DEV_UART_1,
                     STR_ID_EM_DEV_UART_2,
                 #ifdef __UART3_SUPPORT__
                     STR_ID_EM_DEV_UART_3,
                 #endif 
                 #ifdef __MMI_USB_SUPPORT__
                     STR_ID_EM_DEV_USB_PORT2,
                 #ifdef __USB_MULTIPLE_COMPORT_SUPPORT__
                     STR_GLOBAL_NONE,
                 #endif
                 #endif
                 };
#endif /* __USB_COMPORT_SUPPORT_TC01_DRIVER__ */

#if (!defined(__USB_COMPORT_SUPPORT_TC01_DRIVER__) && (defined(__MMI_USB_SUPPORT__) && (defined(__USB_TETHERING__) || defined(__COMPOSITE_WEBCAM__))))
static const U16 g_mmi_em_set_uart_tst_ps_no_usb_str[] = {
                     STR_ID_EM_DEV_UART_1,
                     STR_ID_EM_DEV_UART_2,
                 #ifdef __UART3_SUPPORT__
                     STR_ID_EM_DEV_UART_3,
                 #endif 
                 #if defined(__MMI_USB_SUPPORT__) && defined(__USB_COM_PORT_ENABLE__)
                 #ifdef __USB_MULTIPLE_COMPORT_SUPPORT__
                     STR_ID_EM_DEV_USB_PORT2,
                 #endif
                 #endif
                 #ifdef __TST_LMU_LOGGING__
                     STR_ID_EM_DEV_UART_PORT_LMU,
                 #endif
                 STR_GLOBAL_NONE};
                 
static const cui_inline_item_select_struct g_mmi_em_dev_uart_port_text_no_usb_sel = 
{
    sizeof(g_mmi_em_set_uart_tst_ps_no_usb_str)/sizeof(U16), 
    0, (U16*)g_mmi_em_set_uart_tst_ps_no_usb_str,
};
#endif

#if defined(__USB_COMPORT_SUPPORT_TC01_DRIVER__)
static const cui_inline_item_select_struct g_mmi_em_dev_uart_port_text_only_usb_sel = 
{
    sizeof(g_mmi_em_set_uart_port_test_only_usb)/sizeof(U16), 
    0, (U16*)g_mmi_em_set_uart_port_test_only_usb,
};

static const cui_inline_item_select_struct g_mmi_em_dev_uart_port_text_only_usb2_sel = 
{
    sizeof(g_mmi_em_set_uart_port_test_only_usb2)/sizeof(U16), 
    0, (U16*)g_mmi_em_set_uart_port_test_only_usb2,
};
#endif /* __USB_COMPORT_SUPPORT_TC01_DRIVER__ */


static const cui_inline_item_select_struct g_mmi_em_dev_uart_port_text_sel = 
{
    sizeof(g_mmi_em_set_uart_tst_ps_str)/sizeof(U16),
    0, (U16*)g_mmi_em_set_uart_tst_ps_str,
};
                                                  
static const cui_inline_item_select_struct g_mmi_em_set_uart_band_select = 
{
    0, 0, (U16*)NULL,
};

static const cui_inline_item_caption_struct g_mmi_em_uart_ps_config_cap = 
{
    STR_ID_EM_DEV_SET_UART_PS,
};
 
#if defined(__USB_COMPORT_SUPPORT_TC01_DRIVER__)
static const cui_inline_item_select_struct g_mmi_em_dev_uart_port_text_only_usb_sel = 
{
    sizeof(g_mmi_em_set_uart_port_test_only_usb)/sizeof(U16), 
    0, (U16*)g_mmi_em_set_uart_port_test_only_usb,
};
#endif /* __USB_COMPORT_SUPPORT_TC01_DRIVER__ */
 
static const cui_inline_item_caption_struct g_mmi_em_set_uart_tst_l1_cap = 
{
    STR_ID_EM_DEV_SET_UART_TST_L1,
};

#if defined(__MA_L1__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__MA_L1__) */

#if defined(__DSP_FCORE4__)
static const cui_inline_item_caption_struct g_mmi_em_dev_uart_port_tst_dsp_cap = 
{
    STR_ID_EM_DEV_SET_UART_TST_DSP,
};
#endif

static const cui_inline_set_item_struct g_mmi_em_set_uart_inline[] = 
{
    {MMI_EM_CAPTION_1, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_set_uart_tst_ps_cap},
#if defined(__USB_COMPORT_SUPPORT_TC01_DRIVER__)
    {MMI_EM_STR_SELECT_1, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_dev_uart_port_text_only_usb2_sel},
#else
    #if (defined(__MMI_USB_SUPPORT__) && (defined(__USB_TETHERING__) || defined(__COMPOSITE_WEBCAM__)))
        {MMI_EM_STR_SELECT_1, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_dev_uart_port_text_no_usb_sel},
    #else
        {MMI_EM_STR_SELECT_1, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_dev_uart_port_text_sel},
    #endif
#endif
    {MMI_EM_STR_SELECT_2, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_set_uart_band_select},
    
    {MMI_EM_CAPTION_2, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_uart_ps_config_cap},
#if defined(__USB_COMPORT_SUPPORT_TC01_DRIVER__)
    {MMI_EM_STR_SELECT_3, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_dev_uart_port_text_only_usb_sel},
#else
        {MMI_EM_STR_SELECT_3, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_dev_uart_port_text_sel},
#endif
    {MMI_EM_STR_SELECT_4, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_set_uart_band_select},
    
    {MMI_EM_CAPTION_3, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_set_uart_tst_l1_cap},
#if defined(__USB_COMPORT_SUPPORT_TC01_DRIVER__)
    {MMI_EM_STR_SELECT_5, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_dev_uart_port_text_only_usb_sel},
#else
    #if (defined(__MMI_USB_SUPPORT__) && (defined(__USB_TETHERING__) || defined(__COMPOSITE_WEBCAM__)))
        {MMI_EM_STR_SELECT_5, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_dev_uart_port_text_no_usb_sel},
    #else
        {MMI_EM_STR_SELECT_5, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_dev_uart_port_text_sel},
    #endif
#endif
    {MMI_EM_STR_SELECT_6, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_set_uart_band_select},
    
#if defined(__MA_L1__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if defined(__DSP_FCORE4__)
    {MMI_EM_CAPTION_5, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_dev_uart_port_tst_dsp_cap},
    {MMI_EM_STR_SELECT_9, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_dev_uart_port_text_sel},
    {MMI_EM_STR_SELECT_10, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_set_uart_band_select},
#endif 
};

const cui_inline_struct g_mmi_em_set_uart_inline_screen = 
{
    sizeof(g_mmi_em_set_uart_inline)/sizeof(cui_inline_set_item_struct),
    STR_ID_EM_DEV_SET_UART_SETTING,
    0,
    CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    (const cui_inline_set_item_struct*)&g_mmi_em_set_uart_inline,
};

//PU8 subEmMenuDataPtrs[MAX_SUB_MENUS];
//U8 subEmMenuData[MAX_SUB_MENUS][MAX_SUB_MENU_SIZE];
#define MAX_SUB_MENU_DEVICE_SIZE 20
PU8 *g_setting_subEmMenuDataPtrs = NULL;
U8  *g_setting_subEmMenuData;
static void mmi_em_device_uart_setting_scrn(void)
{   
     MMI_ID uart_gid;
     MMI_ID uart_inline_id;
     S32 i;
     S32 len;     
     U8 *local_subEmMenuDataPtrs;
#ifdef __MTK_TARGET__
     DCL_HANDLE handle;
     UART_CTRL_GET_MAXBAUDRATE_T result;
#endif
     len = sizeof(g_mmi_em_dev_get_band_rate)/sizeof(g_mmi_em_dev_get_band_rate[0]);
     g_setting_subEmMenuDataPtrs = (PU8 *)MMI_EM_MALLOC(len * sizeof(PU8));
     g_setting_subEmMenuData = (U8 *)MMI_EM_MALLOC(len * MAX_SUB_MENU_DEVICE_SIZE * sizeof(U8)); 
#ifdef __MTK_TARGET__
     handle = DclSerialPort_Open(uart_port1, NULL);
     DclSerialPort_Control(handle, UART_CMD_GET_MAX_BAUDRATE,(DCL_CTRL_DATA_T *)&result);
     DclSerialPort_Close(handle);

 //    kal_prompt_trace(MOD_MMI, "[EM] max=%d", result.max_baudrate);
     
     if (result.max_baudrate == UART_BAUD_921600)
     {
         len--;
     }
#endif

     //kal_prompt_trace(MOD_MMI, "[EM] mmi_em_device_uart_setting_scrn, len=%d", len);
     local_subEmMenuDataPtrs = g_setting_subEmMenuData;
     for (i = 0; i < len; i++)
     {
         kal_wsprintf((WCHAR*)local_subEmMenuDataPtrs, "%d", g_mmi_em_dev_get_band_rate[i]);
         g_setting_subEmMenuDataPtrs[i] = local_subEmMenuDataPtrs;
         local_subEmMenuDataPtrs += MAX_SUB_MENU_DEVICE_SIZE;
     };
     
     uart_gid = mmi_frm_group_create_ex(mmi_em_get_root_group(),
                    GRP_ID_AUTO_GEN, 
                    mmi_em_device_uart_setting_proc, NULL,
                    MMI_FRM_NODE_SMART_CLOSE_FLAG);
                  
     mmi_em_dev_set_uart_cntx_p->uart_inline_id = cui_inline_create(uart_gid, &g_mmi_em_set_uart_inline_screen);
     uart_inline_id = mmi_em_dev_set_uart_cntx_p->uart_inline_id;
     cui_inline_set_value(uart_inline_id, MMI_EM_STR_SELECT_1, (void *) mmi_em_dev_set_uart_cntx_p->port_tst);
     cui_inline_set_item_select(uart_inline_id, MMI_EM_STR_SELECT_2, 
        len, 
        g_setting_subEmMenuDataPtrs, 
        mmi_em_dev_set_uart_cntx_p->baud_tst);
        
     cui_inline_set_value(uart_inline_id, MMI_EM_STR_SELECT_3, (void *) mmi_em_dev_set_uart_cntx_p->port_ps);
     cui_inline_set_item_select(uart_inline_id, MMI_EM_STR_SELECT_4, 
        len, 
        g_setting_subEmMenuDataPtrs, 
        mmi_em_dev_set_uart_cntx_p->baud_ps);
        
     cui_inline_set_value(uart_inline_id, MMI_EM_STR_SELECT_5, (void *) mmi_em_dev_set_uart_cntx_p->port_tstl1);
     cui_inline_set_item_select(uart_inline_id, MMI_EM_STR_SELECT_6, 
        len, 
        g_setting_subEmMenuDataPtrs, 
        mmi_em_dev_set_uart_cntx_p->baud_tstl1);
        
#if defined(__MA_L1__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MA_L1__ */

#if defined(__DSP_FCORE4__)
     cui_inline_set_value(uart_inline_id, MMI_EM_STR_SELECT_9, (void *) mmi_em_dev_set_uart_cntx_p->port_dsp);
     cui_inline_set_item_select(uart_inline_id, MMI_EM_STR_SELECT_10, 
        len, 
        g_setting_subEmMenuDataPtrs, 
        mmi_em_dev_set_uart_cntx_p->band_dsp);
#endif
     cui_inline_run(mmi_em_dev_set_uart_cntx_p->uart_inline_id); 
}

static MMI_RET mmi_em_device_uart_setting_proc(mmi_event_struct *evt)
{
    cui_event_inline_common_struct* inline_evt = (cui_event_inline_common_struct*) evt;
    mmi_id sender_id = inline_evt->sender_id;

    
    switch (inline_evt->evt_id)
    {
    case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_CSK_PRESS:
        cui_inline_get_value(sender_id, MMI_EM_STR_SELECT_1, (void *) &mmi_em_dev_set_uart_cntx_p->port_tst);
        cui_inline_get_value(sender_id, MMI_EM_STR_SELECT_2, (void *) &mmi_em_dev_set_uart_cntx_p->baud_tst);
        cui_inline_get_value(sender_id, MMI_EM_STR_SELECT_3, (void *) &mmi_em_dev_set_uart_cntx_p->port_ps);
        cui_inline_get_value(sender_id, MMI_EM_STR_SELECT_4, (void *) &mmi_em_dev_set_uart_cntx_p->baud_ps);
        cui_inline_get_value(sender_id, MMI_EM_STR_SELECT_5, (void *) &mmi_em_dev_set_uart_cntx_p->port_tstl1);
        cui_inline_get_value(sender_id, MMI_EM_STR_SELECT_6, (void *) &mmi_em_dev_set_uart_cntx_p->baud_tstl1);
    #if defined(__MA_L1__)
/* under construction !*/
/* under construction !*/
    #endif /* __MA_L1__ */
    #if defined(__DSP_FCORE4__)
        cui_inline_get_value(sender_id, MMI_EM_STR_SELECT_9, (void *) &mmi_em_dev_set_uart_cntx_p->port_dsp);
        cui_inline_get_value(sender_id, MMI_EM_STR_SELECT_10, (void *) &mmi_em_dev_set_uart_cntx_p->band_dsp);
    #endif
        SendSetUartReq();
        break;

    case EVT_ID_CUI_INLINE_ABORT:
        cui_inline_close(inline_evt->sender_id);
        mmi_em_dev_set_uart_cntx_p->uart_inline_id = 0;
        break;
	case EVT_ID_GROUP_INACTIVE:
        if(NULL != g_setting_subEmMenuDataPtrs)
        {
            MMI_EM_FREE(g_setting_subEmMenuDataPtrs);
            g_setting_subEmMenuDataPtrs = NULL;
            MMI_EM_FREE(g_setting_subEmMenuData);
            g_setting_subEmMenuData = NULL;
        }        
        break;
    default:
        break;
    }

    return MMI_RET_OK;    
}
#endif /* __MMI_EM_DEV_SET_UART__ */

#ifdef __DYNAMIC_UART_PORT_SWITCHING__

static void mmi_em_dev_set_uart_close_inline(void)
{
#ifdef __MMI_EM_DEV_SET_UART__
    if (mmi_em_dev_set_uart_cntx_p->uart_inline_id)
    {
       cui_inline_close(mmi_em_dev_set_uart_cntx_p->uart_inline_id);
       mmi_em_dev_set_uart_cntx_p->uart_inline_id = 0;
    }
#endif /* __MMI_EM_DEV_SET_UART__ */
}

#endif

#define EM_DEV_SLEEP_MODE
/*-----------------------------------------------------------------------------*/
/*--------------------------- Device -> Sleep mode ----------------------------*/
/*-----------------------------------------------------------------------------*/
#ifdef __MMI_EM_DEV_SLEEP_MODE__
static void mmi_em_device_set_sleep_mode_hdlr(MMI_ID menu_id)
{
    g_sleep_mode_state = (MENU_ID_EM_DEV_SLEEP_MODE_OFF == menu_id) ? 1 : 0;
    
    EngineerModeSetSleepModeReq(g_sleep_mode_state);
}
#endif /*__MMI_EM_DEV_SLEEP_MODE__*/


#define EM_DEV_SPEECH_LCD
/*-----------------------------------------------------------------------------*/
/*--------------------------- Device -> Sleep lcd -----------------------------*/
/*-----------------------------------------------------------------------------*/

#ifdef __MMI_EM_DEV_SPEECH_LCD__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_EM_DEV_SPEECH_LCD__ */

void mmi_em_device_menu_sel_event_hdlr(cui_menu_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(event->highlighted_menu_id)
    {
/*----------------------- gpio -------------------------------------*/
    #ifdef __MMI_EM_DEV_GPIO__
        case MENU_ID_EM_DEV_GPIO:
            mmi_em_dev_gpio_hdlr();
            break;

        case MENU_ID_EM_DEV_GPIO_LIST_GPO_GPIO:
            mmi_em_dev_gpio_list_menu_hdlr();
            break;

        case MENU_ID_EM_DEV_GPIO_EDIT_GPIO:
            mmi_em_device_gpo_gpio_set_hdlr(SET_GPIO_ACTION, STR_ID_EM_DEV_GPIO_EDIT_GPIO);
            break;

        case MENU_ID_EM_DEV_GPIO_EDIT_GPO:
            mmi_em_device_gpo_gpio_set_hdlr(SET_GPO_ACTION, STR_ID_EM_DEV_GPIO_EDIT_GPO);
            break;
    #endif /*__MMI_EM_DEV_GPIO__*/
	
/*----------------------- MM Color -------------------------------------*/
#if defined(__COLOR_HW_SUPPORTED__)
        case MENU_ID_EM_MM_COLOR:
            mmi_em_dev_mm_color_select_hdlr();
            break;
#endif


/*----------------------- backlight -------------------------------------*/
    #if defined(__MMI_EM_DEV_BACKLIGHT__)
        case MENU_ID_EM_DEV_BACKLIGHT:
            mmi_em_dev_backlight_hdlr();
            break;
    #endif
    #if defined(__MMI_EM_60BACKLIGHT__) 
        case MENU_ID_EM_DEV_BACKLIGHT:
            mmi_em_dev_60backlight_hdlr();
            break;
    #endif   
/*----------------------- Eint -------------------------------------*/      
    #ifdef __MMI_EM_DEV_EINT__
        case MENU_ID_EM_DEV_EINT:
            mmi_em_device_eint();
            break;
    #endif

/*------------------------ ADC -------------------------------------*/             
#if 0 //def __MMI_EM_DEV_ADC__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif/*__MMI_EM_DEV_ADC__*/

/*------------------------ Clam ------------------------------------*/
    #ifdef __MMI_EM_DEV_CLAM__
        case MENU_ID_EM_DEV_CLAM:
            EntryClamMenu();
            break;
    #endif

/*------------------------ hw level --------------------------------*/
    #ifdef __MMI_EM_DEV_SET_HW_LEVEL__
        case MENU_ID_EM_DEV_HW_LEVEL:
            mmi_em_dev_hw_level_hdlr();
            break;

        case MENU_ID_EM_DEV_HW_LEVEL_BATTERY:
            mmi_em_device_hw_level_enter_detail_scrn(
                MENU_ID_EM_DEV_HW_LEVEL_BATTERY,
                STR_ID_EM_DEV_HW_LEVEL_BATTERY);
            break;
#ifndef __MMI_EM_60BACKLIGHT__
        case MENU_ID_EM_DEV_HW_LEVEL_PWM1:
            mmi_em_device_hw_level_enter_detail_scrn(
                MENU_ID_EM_DEV_HW_LEVEL_PWM1,
                STR_ID_EM_DEV_PWM_SET_1);
            break;
        
        case MENU_ID_EM_DEV_HW_LEVEL_PWM2:
            mmi_em_device_hw_level_enter_detail_scrn(
                MENU_ID_EM_DEV_HW_LEVEL_PWM2, 
                STR_ID_EM_DEV_PWM_SET_2);
            break;
        
        case MENU_ID_EM_DEV_HW_LEVEL_PWM3:
            mmi_em_device_hw_level_enter_detail_scrn(
                MENU_ID_EM_DEV_HW_LEVEL_PWM3,
                STR_ID_EM_DEV_PWM_SET_3);
            break;
#endif //__MMI_EM_60BACKLIGHT__ 
    #endif/*__MMI_EM_DEV_SET_HW_LEVEL__*/

    #ifdef __MMI_EM_DEV_SET_UART__
        case MENU_ID_EM_DEV_UART_SETTING:
            mmi_em_device_uart_setting_hdlr();
            break;

    #endif /* __MMI_EM_DEV_SET_UART__ */

/*------------------------ hw level --------------------------------*/
    #ifdef __MMI_EM_DEV_SLEEP_MODE__
        case MENU_ID_EM_DEV_SLEEP_MODE_ON:
        case MENU_ID_EM_DEV_SLEEP_MODE_OFF:
            mmi_em_device_set_sleep_mode_hdlr(event->highlighted_menu_id);
            break;
    #endif/*__MMI_EM_DEV_SLEEP_MODE__*/ 

    #ifdef __MMI_EM_DEV_DCM_MODE__
        case MENU_ID_EM_DEV_DCM_MODE_ON:
        case MENU_ID_EM_DEV_DCM_MODE_OFF:
            mmi_em_device_set_dcm_mode_hdlr(event->highlighted_menu_id);
            break;
    #endif 

    #ifdef __MMI_BT_DIALER_SUPPORT__
        case MENU_ID_EM_DEV_BQB_MODE_ON:
        case MENU_ID_EM_DEV_BQB_MODE_OFF:
            mmi_em_device_set_bqb_mode_hdlr(event->highlighted_menu_id);
            break;
    #endif

/*------------------------ nand format ------------------------------*/              
    #ifdef __MMI_EM_DEV_NAND_FORMAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    #ifdef __MMI_EM_MOBILE_TV_SETTING__
        case MENU_ID_EM_DEV_MTV_SETTING:
            mmi_em_mtv_entry_setting_scr();
            break;
    #endif

    #ifdef __MMI_EM_VIDEO_SETTING__
        case EM_DEV_VIDEO_SETTING_MP4_MENUID:
        case EM_DEV_VIDEO_SETTING_H264_MENUID:
        case EM_DEV_VIDEO_SETTING_RM_MENUID:
        case EM_DEV_VIDEO_SETTING_VP8_MENUID:
        case EM_DEV_VIDEO_SETTING_CODEC_MP4_MENUID:
        case EM_DEV_VIDEO_SETTING_CODEC_H264_MENUID:    
        case EM_DEV_VIDEO_SETTING_CODEC_RM_MENUID:
        case EM_DEV_VIDEO_SETTING_CODEC_VP8_MENUID:
        case EM_DEV_VIDEO_SETTING_MODE_MP4_MENUID:
        case EM_DEV_VIDEO_SETTING_MODE_H264_MENUID:    
        case EM_DEV_VIDEO_SETTING_MODE_RM_MENUID:
        case EM_DEV_VIDEO_SETTING_MODE_VP8_MENUID:
            {
                mmi_em_video_setting_select_handler(event->highlighted_menu_id);
            }
            break;     
    #endif

    #ifdef __MMI_EM_VIDEO_STREAMING_SETTING__
        case MENU_ID_EM_DEV_VIDEO_STREAMING_SETTING:
            mmi_em_video_streaming_entry_setting_scr();
            break;
    #endif

/*------------------------ USB ------------------------------------*/               
    #ifdef __MMI_EM_DEV_USB_OTG_SRP__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_EM_DEV_USB_OTG_SRP__ */

    #ifdef __MMI_EM_DEV_USB_BOOT_MODE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_EM_DEV_USB_BOOT_MODE__ */

    #ifdef __MMI_EM_DEV_USB_TETHERING__
        case MENU_ID_EM_DEVICE_USB_TETHERING:  
            mmi_em_dev_usb_tethering_scrn();
            break;
    #endif
/*------------------------ Memory test ------------------------------*/              
    #ifdef __MMI_EM_DEV_MEMORY_TEST__
        case MENU_ID_EM_DEV_MEMORY_TEST_EMI_SETTING:
            mmi_em_dev_memory_test_emi_setting();
            break;

        case MENU_ID_EM_DEV_MEMORY_TEST_CUSTOM_SETTING:
            mmi_em_dev_memory_test_custom_setting();
            break;

        case MENU_ID_EM_DEV_MEMORY_TEST_FLASH_INFO:
            mmi_em_dev_memory_test_flash_info();
            break;
    #endif

/*------------------------ Fm radio ---------------------------------*/                              
    #ifdef __MMI_EM_DEV_FM_RADIO__
        case MENU_ID_EM_DEV_FM_RADIO:
            mmi_em_dev_fmr_enter();
            break;
    #endif/*__MMI_EM_DEV_FM_RADIO__*/

    #ifdef __MMI_EM_DEV_TST_OUTPUT_MODE__
        case MENU_ID_EM_DEV_TST_OUTPUT_MODE:
            mmi_em_dev_tst_output_hdlr(event);
            break;
    #endif
            
    #ifdef __MMI_EM_DEV_USB_LOGGING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif 

    #if defined(__GPS_SUPPORT__)
        case MENU_ID_EM_DEV_MINI_GPS:
            mmi_em_dev_minigps_enter_main_src();   
            break;
    #endif
            
    #ifdef __MMI_EM_MOTION_APP__
        case MENU_ID_EM_DEV_MOTION:
            mmi_em_motion_sensor_entry();
            break;
    #endif

    #ifdef __MMI_EM_DEV_SPEECH_LCD__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
 
    #ifdef __MMI_EM_DEV_PXS_SENSOR__
        case MENU_ID_EM_DEV_PXS:
            mmi_em_enter_pxs_sensor_hdlr();
            break;
    #endif

    #ifdef __MMI_EM_DEV_PMU_REGISTER_SETTING__
        case MENU_ID_EM_DEV_PMU_REG_SET:
            mmi_em_dev_pmu_reg_enter_scrn();
            break;
    #endif

    #ifdef __MMI_EM_DEV_WLAN_EAP_MODE__
        case MENU_ID_EM_DEV_WLAN_SETTING:
            mmi_em_enter_wlan_eap_mode_settings ();
            break;
    #endif
    
    /*------------------------ NFC ---------------------------------*/
    #ifdef __MMI_EM_NFC_SUPPORT__
    case MENU_ID_EM_NFC:
        mmi_em_nfc_enter();
        break;
    #endif    

    #if defined(__MMI_EM_CAM_AF_CONTSHOT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif        
        default:
            break;
    }
    
#ifdef __MMI_EM_DEV_FM_RADIO__
    mmi_em_dev_fmr_menu_sel_event_hdlr(event->highlighted_menu_id);
#endif/*__MMI_EM_DEV_FM_RADIO__*/
}


void mmi_em_device_menu_event_entry_hdlr(cui_menu_event_struct *event)
{
    mmi_menu_id menu_id;
    
    
    switch (event->parent_menu_id)
    {
    #ifdef __MMI_EM_DEV_SLEEP_MODE__
        case MENU_ID_EM_DEV_SLEEP_MODE:
            cui_menu_set_currlist_flags(event->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
            menu_id = g_sleep_mode_state ? MENU_ID_EM_DEV_SLEEP_MODE_OFF : MENU_ID_EM_DEV_SLEEP_MODE_ON;
            cui_menu_set_currlist_highlighted_id(event->sender_id, menu_id);
            break;
    #endif/*__MMI_EM_DEV_SLEEP_MODE__*/

    #ifdef __MMI_EM_DEV_DCM_MODE__
        case MENU_ID_EM_DEV_DCM_MODE:
            cui_menu_set_currlist_flags(event->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
            menu_id = g_dcm_enable ? MENU_ID_EM_DEV_DCM_MODE_ON : MENU_ID_EM_DEV_DCM_MODE_OFF;
            cui_menu_set_currlist_highlighted_id(event->sender_id, menu_id);
            break;
    #endif /* __MMI_EM_DEV_DCM_MODE__ */

    #ifdef __MMI_BT_DIALER_SUPPORT__
        case MENU_ID_EM_DEV_BQB_MODE:
            cui_menu_set_currlist_flags(event->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
            menu_id = srv_bt_cm_get_bqb_test_flag() ? MENU_ID_EM_DEV_BQB_MODE_ON : MENU_ID_EM_DEV_BQB_MODE_OFF;
            cui_menu_set_currlist_highlighted_id(event->sender_id, menu_id);
            break;
    #endif
   
        case MENU_ID_EM_DEVICE:
            mmi_em_dev_menu_hdlr(event->sender_id);
            break;


    #ifdef __MMI_EM_DEV_SET_UART__
        case MENU_ID_EM_DEV_SET_UART:
            mmi_em_dev_pre_entry_uart_menu();
            break;
    #endif /* __MMI_EM_DEV_SET_UART__ */
        default:
            break;
    }
}

void mmi_em_device_menu_event_exit_hdlr(cui_menu_event_struct *evt)
{
    if (1 != evt->cui_menu_event_flags)
    {
        return;
    }
            
    switch(evt->parent_menu_id)
    {
    #ifdef __MMI_EM_DEV_GPIO__
        case MENU_ID_EM_DEV_GPIO:
            MMI_EM_ASM_FREE_FUNC(dev_gpio);
            MMI_EM_UNREG_STOP_FUNC(MMI_EM_ASM_STOP_FUNC(dev_gpio));
            break;
    #endif/*__MMI_EM_DEV_GPIO__*/

    #ifdef __MMI_EM_DEV_SET_HW_LEVEL__
        case MENU_ID_EM_DEV_HW_LEVEL:
            MMI_EM_ASM_FREE_FUNC(dev_hw_level);
            MMI_EM_UNREG_STOP_FUNC(MMI_EM_ASM_STOP_FUNC(dev_hw_level));
            break;
    #endif/*__MMI_EM_DEV_SET_HW_LEVEL__*/

    #ifdef __MMI_EM_DEV_SET_UART__
        case MENU_ID_EM_DEV_UART_SETTING:
            mmi_em_dev_stop_uart_hdlr();
            break;
    #endif/*__MMI_EM_DEV_SET_HW_LEVEL__*/
    
    #ifdef __MMI_EM_DEV_FM_RADIO__
         case MENU_ID_EM_DEV_FM_RADIO:
             mmi_em_dev_fmr_exit();
             break;
    #endif /* __MMI_EM_DEV_FM_RADIO__ */
          
         default:
             break;
    }
}
#endif /* __MMI_ENGINEER_MODE__ */ 

#ifdef __MMI_EM_DEV_USB_TETHERING__
/*****************************************************************************
* FUNCTION
*  mmi_em_dev_usb_tethering_scrn
* DESCRIPTION
*  enter tethering scrn
* PARAMETERS
*  
* RETURNS           
*  void
*****************************************************************************/
static void mmi_em_dev_usb_tethering_scrn(void)
{
    mmi_id menu_cui_id = 0;
    mmi_id menu_group_id = 0;
    mmi_id cur_hilit_id = 0;
    DCL_HANDLE usb_handle;
    DCL_BOOL  dcl_data;     
    
    menu_group_id = mmi_frm_group_create_ex(mmi_em_get_root_group(),
              GRP_ID_AUTO_GEN, 
              mmi_em_dev_usb_tethering_proc, NULL,
              MMI_FRM_NODE_SMART_CLOSE_FLAG);

    menu_cui_id = cui_menu_create(menu_group_id,
                      CUI_MENU_SRC_TYPE_RESOURCE,
                      CUI_MENU_TYPE_APPSUB,
                      MENU_ID_EM_DEV_USB_TETHERING,
                      MMI_TRUE,
                      NULL);

//	usb_handle = DclSerialPort_Open(uart_port_usb,0);
//	DclSerialPort_Control(usb_handle,USB_CMD_GET_RNDIS_MODE, (DCL_CTRL_DATA_T *)&dcl_data);
//	DclSerialPort_Close(usb_handle);
						
	usb_handle = DclUSB_DRV_Open(DCL_USB, FLAGS_NONE);
	DclUSB_DRV_Control(usb_handle, USB_DRV_CMD_GET_MENU_CONFIG, (DCL_CTRL_DATA_T *)&dcl_data);
	DclUSB_DRV_Close(usb_handle);


    if((kal_bool)dcl_data == KAL_TRUE)  //if(USB_Get_RNDIS_Mode())
    {
        cur_hilit_id = MENU_ID_EM_DEV_USB_TETHERING_ENABLE;
    }
    else 
    {
        cur_hilit_id = MENU_ID_EM_DEV_USB_TETHERING_DISABLE;
    }
    
    cui_menu_set_currlist_highlighted_id(menu_cui_id, cur_hilit_id);
        
    cui_menu_run(menu_cui_id);
}

/*****************************************************************************
* FUNCTION
*  mmi_em_dev_usb_tethering_proc
* DESCRIPTION
*  set engineermode usb_tethering_is_enable enable/disable
* PARAMETERS
*  
* RETURNS           
*  void
*****************************************************************************/
static mmi_ret mmi_em_dev_usb_tethering_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct * menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct *)evt;
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            DCL_HANDLE usb_handle;
            USB_DRV_CTRL_SET data;	
            data.u2set = (DCL_BOOL)(menu_evt->highlighted_menu_id == MENU_ID_EM_DEV_USB_TETHERING_ENABLE);

//						usb_handle = DclSerialPort_Open(uart_port_usb,0);
//						DclSerialPort_Control(usb_handle,USB_CMD_SET_RNDIS_MODE, (DCL_CTRL_DATA_T *)&data);
//						DclSerialPort_Close(usb_handle);
					 
            usb_handle = DclUSB_DRV_Open(DCL_USB, FLAGS_NONE);
            DclUSB_DRV_Control(usb_handle, USB_DRV_CMD_SET_MENU_CONFIG, (DCL_CTRL_DATA_T *)&data);
            DclUSB_DRV_Close(usb_handle);
			
//            if(!USB_Set_RNDIS_Mode((kal_bool)(menu_evt->highlighted_menu_id == MENU_ID_EM_DEV_USB_TETHERING_ENABLE)))
            if((kal_bool)(data.u2Retresult) == KAL_FALSE)
            {
               mmi_em_popup_by_str(STR_ID_EM_WARNING, MMI_EVENT_FAILURE);
               return MMI_RET_OK;
            }

            cui_menu_close(menu_evt->sender_id);
            srv_shutdown_normal_start(APP_ENGINEERMODE1);
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
            break;
        }
		
        case EVT_ID_GROUP_DEINIT:
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}
#endif



#ifdef __MMI_EM_DEV_PMU_REGISTER_SETTING__
/*-----------------------------------------------------------------------------*/
/*-----------------------_ Device -> PMU register settings --------------------*/
/*-----------------------------------------------------------------------------*/
#include "EngineerModeCommMem.h"
#include "EngineerModeCommUI.h"
#include "dcl.h"

#define MMI_EM_DEV_PMU_REG_SET_HDLR_VAL(flag, value)  (value) & (flag)
#define MMI_EM_DEV_PMU_REG_SET_VAL_INIT(flag, value)  (value) | (flag)
#define MMI_EM_DEV_PMU_REG_SET_VAL_HEX                (0X04)
#define MMI_EM_DEV_PMU_REG_SET_VAL_HIGH               (0X02)
#define MMI_EM_DEV_PMU_REG_SET_VAL_LOW                (0X01)

#define MMI_EM_DEV_PMU_REG_SET_MAX_ADR_LEN  (4)
#define MMI_EM_DEV_PMU_REG_SET_MAX_OP_ITEM  (2)
#define MMI_EM_DEV_PMU_REG_SET_MAX_HEX_LEN  (10)
#define MMI_EM_DEV_PMU_REG_SET_MAX_BIN_LEN  (16)
#define MMI_EM_DEV_PMU_REG_SET_HEX_LEN      (6)
#define MMI_EM_DEV_PMU_REG_SET_BIN_LEN      (16)

#define MMI_EM_DEV_PMU_REG_HEX              (16)
#define MMI_EM_DEV_PMU_REG_DEC              (10)
#define MMI_EM_DEV_PMU_REG_BIN              (2)
typedef enum
{
    MMI_EM_DEV_PMU_REG_SET_OP_READ,
    MMI_EM_DEV_PMU_REG_SET_OP_WRITE,
    MMI_EM_DEV_PMU_REG_SET_TOTAL
} mmi_em_dev_pmu_reg_set_op_enum;

typedef enum
{
    MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_OP_SEL  = CUI_INLINE_ITEM_ID_BASE + 0,
    MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_ADDR_CAP,
    MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_VALUE_CAP,
    MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_BIT_VALUE_CAP,
    MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_ADDR_EDIT,
    MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_VALUE_EDIT,
    MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_BIT_VALUE_HIGH_EDIT,
    MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_BIT_VALUE_LOW_EDIT
} mmi_em_dev_pmu_inline_item_display;

typedef struct
{
    U8* op_items[MMI_EM_DEV_PMU_REG_SET_MAX_OP_ITEM];
    S32 op_index;
    S32 cur_op_index;
    WCHAR adr_name[MMI_EM_DEV_PMU_REG_SET_MAX_ADR_LEN + 1];
    WCHAR hex[MMI_EM_DEV_PMU_REG_SET_MAX_HEX_LEN + 1];
    WCHAR high_bit[MMI_EM_DEV_PMU_REG_SET_MAX_HEX_LEN + 1];
    WCHAR low_bit[MMI_EM_DEV_PMU_REG_SET_MAX_HEX_LEN + 1];
    MMI_ID inline_id;
} mmi_em_dev_pmu_reg_set_cntx_struct;

/* PMU register settings */
static mmi_em_dev_pmu_reg_set_cntx_struct * g_mmi_em_dev_pmu_reg_set_cntx = NULL;

static U16 g_mmi_em_dev_pmu_reg_edit_hex_char[] = L"a-f0-9";



static void mmi_em_dev_pmu_reg_set_init(void);

static MMI_BOOL mmi_em_dev_pmu_reg_set_mem_stop_hdlr(void);

static void mmi_em_dev_pmu_reg_set_release_mem(void);

static U32 mmi_em_dev_pmu_reg_set_itoa(WCHAR *buf, S32 i, S32 base);

static S32 mmi_em_dev_pmu_reg_set_atovalue(WCHAR* a, S32 base);

static void mmi_em_dev_pmu_reg_set_read_hdlr(mmi_id inline_id);

static mmi_ret mmi_em_dev_pmu_reg_set_write_hdlr(mmi_event_struct *evt);

static void mmi_em_dev_pmu_reg_set_confirm(void);

static MMI_BOOL mmi_em_dev_pmu_reg_check_and_set_valid(WCHAR *buf, S32 scr_len);

static void mmi_em_dev_pmu_reg_set_cnvt_hex_to_high_low_bin(void);

static mmi_ret mmi_em_dev_pmu_reg_scrn_proc(mmi_event_struct *evt);

static void mmi_em_dev_pmu_reg_inline_item_set_attr(mmi_id sender_id, MMI_BOOL result);

static void mmi_em_dev_pmu_reg_adjust_high_low_bin(MMI_ID sender_id);

#define LEN 20

static U32 mmi_em_dev_pmu_reg_set_itoa(WCHAR *buf, S32 i, S32 base)
{
    CHAR *s;
    CHAR *d;
    CHAR wcs_buf[20] = {0};
    S32 rem;
    U32 count = 0;
    static CHAR rev[LEN+1];

    d = wcs_buf;
    rev[LEN] = 0;
    if (i == 0)
    {
        (*d) = '0';
        *(++d) = '\0';
        count++;
    }
    else
    {
        s = &rev[LEN];

        while (i)
        {
           rem = i % base;
           if (rem < 10)
               *--s = rem + '0';
           else if (base == 16)
               *--s = "abcde"[rem - 10];
           i /= base;
        }
        while (*s)
        {
           (*d) = *s++;
           ++d;
           count++;
        }
    }
    mmi_asc_to_wcs(buf,wcs_buf);

    return count;
}

static S32 mmi_em_dev_pmu_reg_set_atovalue(WCHAR* a, S32 base)
{
    S32 value = 0;
    CHAR acs_buf[20 + 1] = {0};
    S32 i = 0;


    mmi_wcs_to_asc(acs_buf, a);
/*
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_CLOG, "WCHAR %s",a);
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_CLOG, "CHAR %s",acs_buf);
*/
    while(a[i])
    {
        if (a[i] <= '9')
            value = value * base + (a[i] - '0');
        else if (16 == base)
            value = value * base + (a[i] - 'a') + 10;

 //       kal_prompt_trace(MOD_MMI, "value%d = %d", i, value);
        i++;
    }
    return value;
}

#define BIT_LEN (16)

/*
static void mmi_em_dev_pmu_reg_set_cnvt_valid_input(WCHAR *buf, S32 base)
{
    switch(base)
    {
    case 16:
        if (*buf >= 'a' && *buf <= 'f')
        {
            *buf = *buf - 'a' + 'A';
        }
           
        if (!((*buf >= 'A') && (*buf <= 'F') || (*buf >= '0') && (*buf <= '9') || *buf == 0 || *buf == 'x'))
        {
            *buf = L'0';
        }
        break;

    case 2:
        if ((*buf != '0') && (*buf != '1') && *buf != 0 && *buf != 32)
        {
            *buf = L'0';
        }
        break;

    default:
        MMI_ASSERT(!"mmi_em_dev_pmu_reg_set_cnvt_valid_input");
    }
}
*/

static MMI_BOOL mmi_em_dev_pmu_reg_check_and_set_valid(WCHAR *buf, S32 src_len)
{
    S32 i = 0;
    S32 j = src_len ;
    MMI_BOOL result;

    while(buf[i])
    {
        i++;
    }

	if(i == j)
		result = MMI_TRUE;
	else
		result = MMI_FALSE;
		
		
		

    if(i != src_len)
    {
        buf[j] = '\0';
        j--;
          
        for (i--; i >= 0; i-- , j--)
        {
            buf[j] = buf[i];
        }

        while(j >= 0)
        {
            buf[j] = L'0';
            j--;
        }
/*
        if (9 == valid_len)
        {
            j = 8;
            while(j > 4)
            {
                buf[j] = buf[j - 1];
                j--;
            }
            buf[4] = 32;
        }
*/
    }

/*
    if (6 == valid_len && (buf[0] != '0' || buf[1] != 'x'))
    {
        buf[0] = L'0';
        buf[1] = L'x';
    }
*/
    return result;
}

/*
static void mmi_em_dev_pmu_reg_set_auto_flag(U8 base_flag, U8 *flag, WCHAR* buf)
{
    if(mmi_em_dev_pmu_reg_set_val_isvalid(buf, base_flag))
    {
        *flag = MMI_EM_DEV_PMU_REG_SET_VAL_INIT(*flag, base_flag);
    }
}

static MMI_BOOL mmi_em_dev_pmu_reg_set_val_isvalid(WCHAR *buf, U8 base_flag)
{
    U16 valid_len;
    U32 len = 0;

    
    switch(base_flag)
    {
    case MMI_EM_DEV_PMU_REG_SET_VAL_HEX:
        valid_len = 6;
        break;

    case MMI_EM_DEV_PMU_REG_SET_VAL_HIGH:
    case MMI_EM_DEV_PMU_REG_SET_VAL_LOW:
        valid_len = 9;
        break;

    default:
        valid_len = 0;
    }

    while(buf[len])
    {
       len++;
    }

    return len != valid_len;
}
*/


static void mmi_em_dev_pmu_reg_set_cnvt_hex_to_high_low_bin(void)
{
     WCHAR* hex = (WCHAR*)g_mmi_em_dev_pmu_reg_set_cntx->hex;
     WCHAR* high_bin = g_mmi_em_dev_pmu_reg_set_cntx->high_bit;
     WCHAR* low_bin = g_mmi_em_dev_pmu_reg_set_cntx->low_bit;
     WCHAR wsc_buf[20] = {0};
     U32 i = 0;
     S32 value = 0;
 
     value = mmi_em_dev_pmu_reg_set_atovalue(hex, MMI_EM_DEV_PMU_REG_HEX);
     mmi_em_dev_pmu_reg_set_itoa(wsc_buf, value, MMI_EM_DEV_PMU_REG_BIN);
     mmi_em_dev_pmu_reg_check_and_set_valid(wsc_buf, MMI_EM_DEV_PMU_REG_SET_MAX_BIN_LEN);
     
     for(i = 0; i < 8; i++)
     {
         high_bin[i] = wsc_buf[i];
         low_bin[i] = wsc_buf[i + 8];
     }

     high_bin[i] = '\0';
     low_bin[i] = '\0';
     //mmi_em_dev_pmu_reg_check_and_set_valid(high_bin, 9);
     //mmi_em_dev_pmu_reg_check_and_set_valid(low_bin, 9);
}


static void mmi_em_dev_pmu_reg_adjust_high_low_bin(MMI_ID sender_id)
{
    WCHAR* hex = (WCHAR*)g_mmi_em_dev_pmu_reg_set_cntx->hex;
    WCHAR* high_bin = g_mmi_em_dev_pmu_reg_set_cntx->high_bit;
    WCHAR* low_bin = g_mmi_em_dev_pmu_reg_set_cntx->low_bit;
    
    cui_inline_get_value(sender_id, MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_VALUE_EDIT, (void *)hex);
    mmi_em_dev_pmu_reg_set_cnvt_hex_to_high_low_bin();
    
    cui_inline_set_value(
        sender_id, 
        MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_BIT_VALUE_HIGH_EDIT, 
        (void *)high_bin);
        
    cui_inline_set_value(
        sender_id, 
        MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_BIT_VALUE_LOW_EDIT, 
        (void *)low_bin);
}


static void mmi_em_dev_pmu_reg_set_init(void)
{
    MMI_EM_REG_STOP_FUNC(mmi_em_dev_pmu_reg_set_mem_stop_hdlr);

    if (NULL == g_mmi_em_dev_pmu_reg_set_cntx)
    {
        g_mmi_em_dev_pmu_reg_set_cntx = (mmi_em_dev_pmu_reg_set_cntx_struct*)MMI_EM_MALLOC(sizeof(mmi_em_dev_pmu_reg_set_cntx_struct));
        MMI_ASSERT(g_mmi_em_dev_pmu_reg_set_cntx);
    }
    
    if (g_mmi_em_dev_pmu_reg_set_cntx)
    {
        memset(g_mmi_em_dev_pmu_reg_set_cntx, 0, sizeof(mmi_em_dev_pmu_reg_set_cntx_struct));
    }
}

static MMI_BOOL mmi_em_dev_pmu_reg_set_mem_stop_hdlr(void)
{
    MMI_ID inline_id = g_mmi_em_dev_pmu_reg_set_cntx->inline_id;
    
    
    mmi_em_dev_pmu_reg_set_release_mem();
    cui_inline_close(inline_id);
    return MMI_TRUE;
}

static void mmi_em_dev_pmu_reg_set_release_mem(void)
{
    if (g_mmi_em_dev_pmu_reg_set_cntx)
    {
        MMI_EM_FREE(g_mmi_em_dev_pmu_reg_set_cntx);
        g_mmi_em_dev_pmu_reg_set_cntx = NULL;
        MMI_EM_UNREG_STOP_FUNC(mmi_em_dev_pmu_reg_set_mem_stop_hdlr);
    }
}


static void mmi_em_dev_pmu_reg_set_scrn_init(MMI_ID inline_id)
{
    S32 op_index = g_mmi_em_dev_pmu_reg_set_cntx->op_index;
    WCHAR *hex = (WCHAR*)g_mmi_em_dev_pmu_reg_set_cntx->hex;
    WCHAR *high_bin = (WCHAR*)g_mmi_em_dev_pmu_reg_set_cntx->high_bit;
    WCHAR *low_bin = (WCHAR*)g_mmi_em_dev_pmu_reg_set_cntx->low_bit;


    *hex = L'0';
    *high_bin = L'0';
    *low_bin = L'0';
    
    mmi_em_dev_pmu_reg_check_and_set_valid(hex, MMI_EM_DEV_PMU_REG_SET_HEX_LEN);
    mmi_em_dev_pmu_reg_check_and_set_valid(high_bin, 8);
    mmi_em_dev_pmu_reg_check_and_set_valid(low_bin, 8);
    
    cui_inline_set_value(inline_id, MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_OP_SEL, (void *)op_index);
    cui_inline_set_value(inline_id, MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_VALUE_EDIT, (void *) hex);
    cui_inline_set_value(inline_id, MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_BIT_VALUE_HIGH_EDIT, (void *) high_bin);
    cui_inline_set_value(inline_id, MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_BIT_VALUE_LOW_EDIT, (void *) low_bin);

    cui_inline_set_item_attributes(
        inline_id, 
        MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_BIT_VALUE_HIGH_EDIT, 
        CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);
        
    cui_inline_set_item_attributes(
        inline_id, 
        MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_BIT_VALUE_LOW_EDIT, 
        CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);
}


/***
 *  inline screen about read / write
 ***/
static const U16 g_mmi_em_dev_pmu_reg_sel_strs[MMI_EM_DEV_PMU_REG_SET_MAX_OP_ITEM] = {
                     STR_GLOBAL_READ, 
                     STR_ID_EM_DEV_PMU_REG_SET_WRITE};

static const cui_inline_item_select_struct g_mmi_em_dev_pmu_reg_sel_item =
{
    MMI_EM_DEV_PMU_REG_SET_MAX_OP_ITEM,
    0,
    g_mmi_em_dev_pmu_reg_sel_strs
};

static const cui_inline_item_caption_struct g_mmi_em_dev_pmu_addr_cap = 
{
    STR_ID_EM_DEV_PMU_REG_SET_Addr
};

static const cui_inline_item_text_edit_struct g_mmi_em_dev_pmu_addr_tex_edit = 
{
    0,
    0,
    MMI_EM_DEV_PMU_REG_SET_MAX_ADR_LEN + 1,
    IMM_INPUT_TYPE_SENTENCE,
    0,
};

static const cui_inline_item_caption_struct g_mmi_em_dev_pmu_value_cap = 
{
    STR_ID_EM_DEV_PMU_REG_SET_VALUE,
};

static const cui_inline_item_text_edit_struct g_mmi_em_dev_pmu_value_tex_edit = 
{
    0,
    0,
    MMI_EM_DEV_PMU_REG_SET_HEX_LEN,
    IMM_INPUT_TYPE_SENTENCE,
    0,
};

static const cui_inline_item_caption_struct g_mmi_em_dev_pmu_bit_value_cap = 
{
    STR_ID_EM_DEV_PMU_REG_SET_HIGH_LOW,
};

static const cui_inline_item_text_edit_struct g_mmi_em_dev_pmu_bit_high_value_tex_edit = 
{
    0,
    0,
    MMI_EM_DEV_PMU_REG_SET_MAX_HEX_LEN + 1,
    IMM_INPUT_TYPE_PHONE_NUMBER,
    0,
};

static const cui_inline_item_text_edit_struct g_mmi_em_dev_pmu_bit_low_value_tex_edit = 
{
    0,
    0,
    MMI_EM_DEV_PMU_REG_SET_MAX_HEX_LEN + 1,
    IMM_INPUT_TYPE_PHONE_NUMBER,
    0,
};

static const cui_inline_item_softkey_struct g_mmi_em_dev_pmu_inline_sofkey =
{
    {{CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
     {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
     {STR_GLOBAL_BACK, 0}}        
};

static const cui_inline_set_item_struct g_mmi_em_dev_pmu_inline[] = 
{
    {MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_OP_SEL,              CUI_INLINE_ITEM_TYPE_SELECT,          IMG_GLOBAL_L1, (void *)&g_mmi_em_dev_pmu_reg_sel_item},        
    {MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_ADDR_CAP,            CUI_INLINE_ITEM_TYPE_CAPTION,         IMG_GLOBAL_L2, (void *)&g_mmi_em_dev_pmu_addr_cap},      
    {MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_ADDR_EDIT,           CUI_INLINE_ITEM_TYPE_TEXT_EDIT ,      0, (void *)&g_mmi_em_dev_pmu_addr_tex_edit},
    {MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_VALUE_CAP,           CUI_INLINE_ITEM_TYPE_CAPTION,         IMG_GLOBAL_L3, (void *)&g_mmi_em_dev_pmu_value_cap},
    {MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_VALUE_EDIT,          CUI_INLINE_ITEM_TYPE_TEXT_EDIT,       0, (void *)&g_mmi_em_dev_pmu_value_tex_edit},
    {MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_BIT_VALUE_CAP,       CUI_INLINE_ITEM_TYPE_CAPTION,         IMG_GLOBAL_L4, (void *)&g_mmi_em_dev_pmu_bit_value_cap},
    {MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_BIT_VALUE_HIGH_EDIT, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY ,      0, (void *)&g_mmi_em_dev_pmu_bit_high_value_tex_edit},
    {MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_BIT_VALUE_LOW_EDIT,  CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,       0, (void *)&g_mmi_em_dev_pmu_bit_low_value_tex_edit}
};

static const cui_inline_struct g_mmi_em_dev_pmu_inline_screen = 
{
    sizeof(g_mmi_em_dev_pmu_inline)/sizeof(cui_inline_set_item_struct),
    STR_ID_EM_DEV_PMU_REG_SET,
    0,
    CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    (const cui_inline_set_item_struct*)&g_mmi_em_dev_pmu_inline
};

static void mmi_em_dev_pmu_reg_inline_item_set_attr(mmi_id sender_id, MMI_BOOL result)
{
    U32 index = 0;
    
    
    for (index = 0; index < 4; index++)
    {
        //cui_inline_delete_item(sender_id, index + MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_VALUE_EDIT);
        /*
        cui_inline_set_item_attributes(
             sender_id,
             (index + MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_VALUE_EDIT),
             CUI_INLINE_SET_ATTRIBUTE,
             result);
        */
        //cui_inline_insert_item(sender_id,U16 pre_id,cui_inline_set_item_struct * new_item)
    }
}

static void mmi_em_dev_pmu_reg_enter_scrn(void)
{
    MMI_ID inline_id;
    MMI_ID inline_group_id;
    
    
    mmi_em_dev_pmu_reg_set_init();
    
    g_mmi_em_dev_pmu_reg_set_cntx->op_index = MMI_EM_DEV_PMU_REG_SET_OP_READ;
    
    inline_group_id = mmi_frm_group_create(
                          mmi_em_get_root_group(), 
                          GRP_ID_AUTO_GEN, 
                          mmi_em_dev_pmu_reg_scrn_proc, NULL);

    mmi_frm_group_enter(inline_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    inline_id = cui_inline_create(
                    inline_group_id,
                    (const cui_inline_struct *) &g_mmi_em_dev_pmu_inline_screen);
                    
    mmi_em_dev_pmu_reg_set_scrn_init(inline_id);
    
    cui_inline_run(inline_id);
    
    g_mmi_em_dev_pmu_reg_set_cntx->inline_id = inline_id;
}


static mmi_ret mmi_em_dev_pmu_reg_scrn_proc(mmi_event_struct *evt)
{
    cui_event_inline_common_struct* comm_evt = (cui_event_inline_common_struct*) evt;
    
    
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_NOTIFY:
        {
            MMI_BOOL result = MMI_FALSE;

            cui_event_inline_notify_struct *notify = (cui_event_inline_notify_struct*)evt;
            
            if (CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED == notify->event_type &&
                MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_OP_SEL == notify->item_id)
            {
                cui_inline_get_value(
                    notify->sender_id,
                    MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_OP_SEL,
                    &g_mmi_em_dev_pmu_reg_set_cntx->op_index);
                    
                if (0 == g_mmi_em_dev_pmu_reg_set_cntx->op_index)
                {
                    result = MMI_TRUE;
                }
                
                mmi_em_dev_pmu_reg_inline_item_set_attr(notify->sender_id, result);
            }
            
            if (result)
            {
                break;
            }

            if (CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM == notify->event_type)
            {
                if (MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_ADDR_EDIT == notify->item_id ||
                    MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_VALUE_EDIT == notify->item_id)
                    mmi_imm_set_characters(MMI_TRUE, g_mmi_em_dev_pmu_reg_edit_hex_char);
            }

            break;
        }
        
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        {
            MMI_BOOL result = MMI_FALSE;
            
            if (1 == g_mmi_em_dev_pmu_reg_set_cntx->op_index)
            {
                result = MMI_TRUE;
            }
                
            mmi_em_dev_pmu_reg_inline_item_set_attr(comm_evt->sender_id, result);
            break;
        }
            
        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            cui_event_inline_submit_struct *submit_evt = (cui_event_inline_submit_struct*)evt;
            
            if (MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_BIT_VALUE_HIGH_EDIT == submit_evt->item_id ||
                MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_BIT_VALUE_LOW_EDIT == submit_evt->item_id)
                break;
               
            cui_inline_get_value(
                comm_evt->sender_id, 
                MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_OP_SEL,
                (void *) &g_mmi_em_dev_pmu_reg_set_cntx->op_index);
            
            if (0 == g_mmi_em_dev_pmu_reg_set_cntx->op_index)
            {
                mmi_em_dev_pmu_reg_set_read_hdlr(comm_evt->sender_id);
            }
            else 
            {
                if (1 == g_mmi_em_dev_pmu_reg_set_cntx->op_index)
                    mmi_em_dev_pmu_reg_set_confirm();
            }
                
            break;
        }
            
        case EVT_ID_CUI_INLINE_ABORT:
        {            
            mmi_em_dev_pmu_reg_set_release_mem();
            cui_inline_close(comm_evt->sender_id);
            break;
        }
        
        default:
            break;
    }
    return MMI_RET_OK;
}

static void mmi_em_dev_pmu_reg_set_read_hdlr(mmi_id inline_id)
{
    U16 reg_offset;
    U16 read_result;
    WCHAR adr_name[MMI_EM_DEV_PMU_REG_SET_MAX_ADR_LEN + 1] = {0};
    WCHAR* hex = (WCHAR*)g_mmi_em_dev_pmu_reg_set_cntx->hex;
    
    
    
    
    cui_inline_get_value(inline_id, MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_ADDR_EDIT, (void *)adr_name);
    reg_offset = (U16) mmi_em_dev_pmu_reg_set_atovalue((WCHAR*)adr_name, MMI_EM_DEV_PMU_REG_HEX);
    
    if (0 == reg_offset || '\0' == adr_name[0])
    {
       mmi_popup_display_simple(L"Please input address", MMI_EVENT_FAILURE, mmi_em_get_root_group(), NULL);
       return;
    }
    
//    kal_prompt_trace(MOD_MMI, "reg_offset = %d", reg_offset);
#ifdef __MTK_TARGET__
    {
        DCL_HANDLE handle;
        PMU_CTRL_MISC_GET_REGISTER_VALUE val;
        val.offset = reg_offset;
        handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
        DclPMU_Control(handle, MISC_GET_REGISTER_VALUE, 
            (DCL_CTRL_DATA_T *)&val);
        DclPMU_Close(handle);
        read_result = val.value;
    } 
    //read_result = pmic_adpt2_reg_read(reg_offset);
//    kal_prompt_trace(MOD_MMI, "read_result = %d", read_result);
#else
    read_result = reg_offset;
#endif
    mmi_em_dev_pmu_reg_set_itoa(hex, read_result, MMI_EM_DEV_PMU_REG_HEX);
    mmi_em_dev_pmu_reg_check_and_set_valid(hex, MMI_EM_DEV_PMU_REG_SET_HEX_LEN);
    cui_inline_set_value(inline_id, MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_VALUE_EDIT,(void *)hex);
    
    mmi_em_dev_pmu_reg_adjust_high_low_bin(inline_id);
    mmi_em_success_popup();
}

static void mmi_em_dev_pmu_reg_set_confirm(void)
{
    mmi_em_display_confirm(
        STR_ID_EM_DEV_PMU_REG_SET_WRITE,
        mmi_em_get_root_group(),
        MMI_EVENT_WARNING,
        mmi_em_dev_pmu_reg_set_write_hdlr);
}

static mmi_ret mmi_em_dev_pmu_reg_set_write_hdlr(mmi_event_struct *evt)
{
    mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*) evt;
    
    switch (alert->result)
    {
        case MMI_ALERT_CNFM_YES:
        {
            U16 reg_offset;
            U16 write_result;
            WCHAR* addr_name = (WCHAR*)g_mmi_em_dev_pmu_reg_set_cntx->adr_name;
            WCHAR* hex = (WCHAR*)g_mmi_em_dev_pmu_reg_set_cntx->hex;
            MMI_ID inline_id = g_mmi_em_dev_pmu_reg_set_cntx->inline_id;
            
            cui_inline_get_value(
                inline_id,
                MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_ADDR_EDIT, 
                (void *)addr_name);
            
            cui_inline_get_value(
                inline_id,
                MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_VALUE_EDIT, 
                (void *)hex);
                
            reg_offset = (U16) mmi_em_dev_pmu_reg_set_atovalue(addr_name, MMI_EM_DEV_PMU_REG_HEX);
            write_result = (U16) mmi_em_dev_pmu_reg_set_atovalue(hex, MMI_EM_DEV_PMU_REG_HEX);
            
            if (0 == reg_offset || '\0' == addr_name[0])
            {
                mmi_popup_display_simple(L"Please input value", MMI_EVENT_FAILURE, mmi_em_get_root_group(), NULL);
                return MMI_RET_ERR;
            }
        #ifdef __MTK_TARGET__
            {
                DCL_HANDLE handle;
                PMU_CTRL_MISC_SET_REGISTER_VALUE val;
                val.offset = reg_offset;
                val.value = write_result;
                handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
                DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, 
                    (DCL_CTRL_DATA_T *)&val);
                DclPMU_Close(handle);
            }
            //pmic_adpt2_reg_write(reg_offset, write_result);
        #endif
        
            mmi_em_dev_pmu_reg_check_and_set_valid(hex, MMI_EM_DEV_PMU_REG_SET_HEX_LEN);
            cui_inline_set_value(inline_id, MMI_EM_DEV_PMU_REG_SET_INLINE_ITEM_VALUE_EDIT,(void *)hex);
    
            mmi_em_dev_pmu_reg_adjust_high_low_bin(inline_id);
            mmi_em_success_popup();
            break;
        }
        
        default:
            break;
    }
    return MMI_RET_OK;
}

#if (defined(COSMOS_EM_INTERNAL_DCM) || defined(PLUTO_EM_INTERNAL_DCM))
#pragma arm section rodata , code
#endif /* COSMOS_EM_INTERNAL_DCM || PLUTO_EM_INTERNAL_DCM */ 

#endif /* __MMI_EM_DEV_PMU_REGISTER_SETTING__ */
