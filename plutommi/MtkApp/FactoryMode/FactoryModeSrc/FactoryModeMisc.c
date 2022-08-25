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
 * FactoryModeMIsc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for Factory Mode Misc, it include version,res_bin, RTC...
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
 ********************************************************************************/
 #include "MMI_features.h"
	 
#ifdef __MMI_FACTORY_MODE__
/*****************************************************************************
* Include Files                                                                
*****************************************************************************/
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
#include "dcmgr.h"
#elif defined (__DCM_WITH_COMPRESSION_MMI_AP__) && defined(__MTK_TARGET__)
#include "MMI_ap_dcm_config.h"  
#endif /* __DCM_WITH_COMPRESSION_MMI_POOL_A__ */
    
#if defined(__MMI_AP_DCM_FM__)
#pragma arm section rodata = "DYNAMIC_CODE_FM_RODATA" , code = "DYNAMIC_CODE_FM_ROCODE"
#elif defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
#pragma arm section rodata = "DYNAMIC_CODE_COSMOS_FM_RODATA" , code = "DYNAMIC_CODE_COSMOS_FM_ROCODE"
#endif /* #ifdef __MMI_AP_DCM_FM__ */  

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gdi_datatype.h"
#include "gui_data_types.h"
#include "GlobalConstants.h"
#include "ps_public_struct.h"
#include "stack_config.h"
#include "mmi_frm_input_gprot.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "GpioSrvGprot.h"
#include "gpiosrvgprot.h"
#include "Unicodexdcl.h"
#include "stdio.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"

#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "wgui_categories_util.h"
#include "kal_public_api.h"
#include "mmi_frm_history_gprot.h"
#include "CustMenuRes.h"
#include "GlobalMenuItems.h"
#include "wgui_categories_list.h"
#include "gui_typedef.h"
#include "wgui_include.h"
#include "string.h"
#include "mmi_frm_nvram_gprot.h"
#include "wgui_categories_text_viewer.h"
#include "nvram_defs.h"
#include "gui.h"
#include "FontRes.h"
#include "gdi_include.h"
#include "wgui_categories.h"
#include "custom_mmi_default_value.h"
#include "wgui.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_msg_struct.h"
#include "AlarmFrameworkProt.h"
#include "mmi_res_range_def.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "wgui_touch_screen.h"
#include "gui_config.h"
#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "PixcomFontEngine.h"
#include "resource_audio.h"
#include "IdleAppDef.h"
//#include "FactoryModeDef.h"
#include "EngineerModeUtil.h"
#include "EngineerModeGprot.h"
#include "mdi_datatype.h"
#include "mdi_include.h"
#include "mdi_audio.h"
#include "CommonScreens.h"
#include "fmt_struct.h"

#include "mmi_rp_srv_gpio_def.h"
#include "wgui_categories.h"

#include "dcl.h"
 
#include "init.h"
#include "init_public.h"

#include "device.h"
#include "custom_em.h"
#include "custom_equipment.h"
//#include "custom_hw_default.h"
#include "nvram_data_items.h"
#include "nvram_interface.h"
#include "lcd_sw_inc.h"
#include "resource_verno.h"
#include "IdleGprot.h"
#ifdef __MTK_TARGET__
#include "l1audio.h"
#else 
#define L1SP_Tones kal_uint16
#endif 

#include "datetimetype.h"
#include "app_datetime.h"

#ifdef __MMI_FM_RADIO__
#include "aud_defs.h"
#ifdef __PLUTO_MMI_PACKAGE__
#include "mmi_rp_app_fmrdo_def.h"
#endif /*__PLUTO_MMI_PACKAGE__*/
#endif

#include "adc_channel.h"
#include "ShutdownSrvGprot.h"

#include "mmi_rp_app_factorymode_def.h"
#include "MenuCuiGprot.h"
#include "FactoryModeGProt.h"

/* For MRE version */
#include "vmsys.h"
#include  "stack_msgs.h"

#ifdef __GADGET_SUPPORT__
#include "WgtMgrSrvGprot.h"
#endif 

#include "FactoryModeConfig.h"
#include "FactoryModeProt.h"

#include "common_nvram_editor_data_item.h"
#include "nvram_common_defs.h"
#include "FactoryModeUtil.h"
#include "AlarmGprot.h"

/***************************************************************************** 
* Define
*****************************************************************************/


/***************************************************************************** 
* global val / function
*****************************************************************************/
extern MMI_ID g_fm_gourp_id;   /*This group id is used by whole FM*/
extern mmi_fm_item_cntxt_struct *g_fm_contxt;    /*This is context pointer*/
extern char* build_date_time(void);
extern kal_char* release_flavor(void);
extern kal_char* release_build(void);
extern void InitFactoryModeEvent(void);
kal_char* release_hal_verno(void);
/***************************************************************************** 
* static  function
*****************************************************************************/




/* version */
static void mmi_fm_get_version_str(CHAR * content, U8 index );
static void mmi_fm_prepare_version_popup(UI_string_type *list);
static void mmi_fm_get_structed_version_number(CHAR * str, CHAR * format);

/* Res_bin */
#ifdef __MMI_FM_RES_BIN__
static void mmi_fm_prepare_res_bin_popup(UI_string_type *list);
#endif /*__MMI_FM_RES_BIN__*/
/* Other APP */
static MMI_BOOL mmi_fm_init_other_app_cntx(void);
static MMI_RET mmi_fm_other_app_leave_proc(mmi_event_struct *evt);

/* LCD AT cmd */
static void mmi_fm_at_lcd_set_color(U8 red, U8 green, U8 blue);





/***************************************************************************** 
* Code body
*****************************************************************************/

#define MMI_FM_VERSION

/*--------   Version  -------- */
/*****************************************************************************
 * FUNCTION
 *  mmi_fm_get_version_str
 * DESCRIPTION
 *  Get version string
 * PARAMETERS
 *  list        [?]     
 * RETURNS
 *  void
*****************************************************************************/
static void mmi_fm_get_version_str(CHAR * content, U8 index )
{
    CHAR TempString[MAX_SUB_MENU_SIZE];
    
    memcpy(TempString, (CHAR*) content, MAX_SUB_MENU_SIZE - 2);
    mmi_asc_to_ucs2((CHAR*) g_fm_contxt->common_contxt.MenuData[index], (CHAR*) TempString);
}

/*****************************************************************************
 * FUNCTION
 *  FM_PrepareVersionPopUp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  list        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_prepare_version_popup(UI_string_type *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
#ifdef __MMI_FM_MELODY_VERSION__
    CHAR TempString[MAX_SUB_MENU_SIZE];
#endif
    S16 Ret;
    version_struct ver_struct;
    mmi_fm_common_struct * common_cntx;
    mmi_fm_version_struct *version_cntx;
    U32 index = 1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MTK_TARGET__)
    common_cntx = &(g_fm_contxt->common_contxt);
    version_cntx = &(g_fm_contxt->version_contxt);

    /* Get Barcode from Nvram */
    if (version_cntx->gBarCodeReadFlag == 0)
    {
        Ret = ReadRecordSlim(NVRAM_EF_BARCODE_NUM_LID, 1, version_cntx->gBarCode, 64);
        if (!(Ret == NVRAM_EF_BARCODE_NUM_SIZE) || 
            version_cntx->gBarCode[0] == 0)
        {
            strcpy((CHAR*) version_cntx->gBarCode, "SN001234567");
        }
        version_cntx->gBarCodeReadFlag = 1;
    }

    /* Get sturctured version number */
    INT_VersionNumbers(&ver_struct);

    /* Lisen 04072005 */
    /* MCU SW Version */
    mmi_fm_get_version_str((CHAR*)ver_struct.mcu_sw,index);
    
    #ifdef __MMI_FM_MELODY_VERSION__
    /* Melody Ver. */
    mmi_fm_get_melody_version(TempString);
    mmi_asc_to_ucs2((CHAR*) common_cntx->MenuData[++index], (CHAR*) TempString);
    #endif /*__MMI_FM_MELODY_VERSION__*/

    /* Serial No. */
    mmi_fm_get_version_str((CHAR*)version_cntx->gBarCode,++index);

    /* BB Chip Ver. */
    mmi_fm_get_version_str((CHAR*)ver_struct.bb_chip,++index);

    /* DSP Code Ver. */
    mmi_fm_get_version_str((CHAR*)ver_struct.dsp_fw,++index);

    /* DSP Patch Ver. */
    mmi_fm_get_version_str((CHAR*)ver_struct.dsp_ptch,++index);

    /* MS Board (HW Ver.) */
    mmi_fm_get_version_str((CHAR*)ver_struct.bb_board,++index);

    /* Build Version */
    mmi_fm_get_version_str((CHAR*)build_date_time(),++index);

    for (i = 0; i < MAX_VER_NUM; i++)
    {
        list[i] = (UI_string_type) common_cntx->MenuData[i];
    }

#else /* defined(__MTK_TARGET__)) */ 
    /* For PC Simulatior */

    index = 1;

    if (g_fm_contxt->version_contxt.gBarCodeReadFlag == 0)
    {
        strcpy((CHAR*) g_fm_contxt->version_contxt.gBarCode, "SN001234567");
        g_fm_contxt->version_contxt.gBarCodeReadFlag = 1;
    }

    /* BB Chip Ver. */
    mmi_asc_to_ucs2((CHAR*) g_fm_contxt->common_contxt.MenuData[index], (CHAR*) "MTK_BB.V0");

    /* DSP Code Ver. */
    mmi_asc_to_ucs2((CHAR*) g_fm_contxt->common_contxt.MenuData[++index], (CHAR*) "MTK_DSP.V0");

    /* DSP Patch Ver. */
    mmi_asc_to_ucs2((CHAR*) g_fm_contxt->common_contxt.MenuData[++index], (CHAR*) "MTK_DSP_P.V0");

    /* MCU (SW Ver.) */
    mmi_asc_to_ucs2((CHAR*) g_fm_contxt->common_contxt.MenuData[++index], (CHAR*) "Branch MTK_SW.V0");

    /* MS Board (HW Ver.) */
    mmi_asc_to_ucs2((CHAR*) g_fm_contxt->common_contxt.MenuData[++index], (CHAR*) "MTK_HW.V0");

#ifdef __MMI_FM_MELODY_VERSION__
    /* Melody Ver. */
    mmi_asc_to_ucs2((CHAR*) g_fm_contxt->common_contxt.MenuData[++index], (CHAR*) "Melody.V0");
#endif

    /* Serial No. */
    kal_wsprintf( (WCHAR *)g_fm_contxt->common_contxt.MenuData[++index],
        "%w",g_fm_contxt->version_contxt.gBarCode); 

    /* Build Version */
    mmi_asc_to_ucs2((CHAR*) g_fm_contxt->common_contxt.MenuData[++index], (CHAR*) "Oct 25 19:08  2003");

    for (i = 0; i < MAX_VER_NUM; i++)
    {
        list[i] = (UI_string_type) g_fm_contxt->common_contxt.MenuData[i];
    }
#endif /* ( defined(__MTK_TARGET__)) */ 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_get_structed_version_number
 * DESCRIPTION
 *  Get version number
 * PARAMETERS
 *  S8 * str, 
 *  S8 * format      
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_get_structed_version_number(CHAR * str, CHAR * format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tempbuf[MAX_TEST_STRING_BUF * 2];
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf((WCHAR *) tempbuf, format, str);
    mmi_ucs2cat((CHAR*) g_fm_contxt->version_contxt.UnicodeDisplayBuf, (const CHAR*)tempbuf);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_version_menu_item_highlight
 * DESCRIPTION
 *  If highlight version menu, this function will be called
 * PARAMETERS
 *  cui_menu_event_struct *evt        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_version_menu_item_highlight(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menu_evt->highlighted_menu_id == MENU_ID_FM_SW_SUMMARY)		
        change_softkey(STR_GLOBAL_OK, 0, MMI_LEFT_SOFTKEY);
    else
        change_softkey(0, 0, MMI_LEFT_SOFTKEY);

	redraw_softkey(MMI_LEFT_SOFTKEY);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_select_version_summary_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
 #ifdef __GADGET_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
 #endif /* __GADGET_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __GADGET_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __GADGET_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__MTK_INTERNAL__*/

#ifndef __MTK_INTERNAL__
extern void mmi_fm_select_version_summary_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    
 #ifdef __GADGET_SUPPORT__
    U8 AsciiDisplayBuf[MAX_TEST_STRING_BUF];
    U8 tempbuf[MAX_TEST_STRING_BUF * 2];
    U8 gadgetTempbuf[WGTMGR_VERSION_MAX_LEN] = {0};
 #endif /* __GADGET_SUPPORT__ */

    S16 Ret;
    version_struct ver_struct;

    CHAR * str[7];
    CHAR * format[7];
    
    U32 i = 0;

    mmi_fm_version_struct *version_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    version_cntx = &(g_fm_contxt->version_contxt);
    
     mmi_frm_scrn_enter
        (g_fm_gourp_id, 
         SCR_ID_FM_VERSION_SUMMARY, 
         NULL, 
         mmi_fm_select_version_summary_menu, 
         MMI_FRM_FULL_SCRN);
    
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    /* Get Barcode from Nvram */
    if (version_cntx->gBarCodeReadFlag == 0)
    {
        Ret = ReadRecordSlim(NVRAM_EF_BARCODE_NUM_LID, 1, version_cntx->gBarCode, 64);
        if (!(Ret == NVRAM_EF_BARCODE_NUM_SIZE) )
        {
            strcpy((CHAR*) version_cntx->gBarCode, "SN001234567");
        }
        version_cntx->gBarCodeReadFlag = 1;
    }
    INT_VersionNumbers(&ver_struct);

    str[0] = (CHAR*) ver_struct.mcu_sw_branch;
    str[1] = (CHAR*) release_build();
    str[2] = (CHAR*) version_cntx->gBarCode;
    str[3] = NULL;
    str[4] = (CHAR*) build_date_time();
    str[5] = (CHAR*) vm_get_mre_version();
    str[6] = (CHAR *)release_hal_verno();
    
    format[0] = " %s\n";
    format[1] = "BUILD: %s\n";
    format[2] = "SERIAL#: %s\n";
    format[3] = "[BUILD TIME] \n";
    format[4] = "%s\n";
    format[5] = "[MRE VERSION] %d\n";
    format[6] = "HAL_VERNO: %s\n";

    kal_wsprintf((WCHAR *)version_cntx->UnicodeDisplayBuf ,
        "[VERSION]  %s\n[BRANCH]:",(CHAR*) ver_struct.mcu_sw);

    for (i = 0; i<7; i++)
    {
        mmi_fm_get_structed_version_number(str[i],format[i]);
    }

    
#ifdef __GADGET_SUPPORT__
            /* Add one more item to show gadget engine version */
            sprintf((CHAR*) AsciiDisplayBuf, "[GADGET ENGINE] \n");
            mmi_asc_to_ucs2((CHAR*) tempbuf, (CHAR*) AsciiDisplayBuf);
            mmi_ucs2cat((CHAR*) version_cntx->UnicodeDisplayBuf, (const CHAR*)tempbuf);    
        
            /* Get gadget engine version */
            srv_wgtmgr_get_engine_version(gadgetTempbuf);
        
            sprintf((CHAR*) AsciiDisplayBuf, "%s\n", gadgetTempbuf);
            mmi_asc_to_ucs2((CHAR*) tempbuf, (CHAR*) AsciiDisplayBuf);
            mmi_ucs2cat((CHAR*) version_cntx->UnicodeDisplayBuf, (const CHAR*)tempbuf);  
#endif /* __GADGET_SUPPORT__ */

    ShowCategory74Screen(
        STR_ID_FM_SW_SUMMARY,
        0,
        (U16) NULL,
        0,
        STR_GLOBAL_BACK,
        0,
        (PU8) version_cntx->UnicodeDisplayBuf,
        sizeof(version_cntx->UnicodeDisplayBuf),
        guiBuffer);
    mmi_fm_set_general_goback_function();
}

#endif /*__MTK_INTERNAL__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_version_pre_hint
 * DESCRIPTION
 *  Prepear hint when enter version menu
 * PARAMETERS
 *  cui_menu_event_struct *evt        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_version_pre_hint(cui_menu_event_struct *evt)
{

    MMI_ID tab[8] ={
    MENU_ID_FM_SW_VER,               

    #ifdef __MMI_FM_MELODY_VERSION__
       MENU_ID_FM_MELODY_VER,             
    #endif
    
       MENU_ID_FM_ISN,                 
       MENU_ID_FM_BBCHIP_VER,             
       MENU_ID_FM_DSPCODE_VER,            
       MENU_ID_FM_DSPATCH_VER,            
       MENU_ID_FM_HW_VER,                 
       MENU_ID_FM_BUILD_TIME}; 

    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
    UI_string_type PopUpList[32] = { NULL };
    U8 i = 0 ;

    /*prepear popuplist*/
    mmi_fm_prepare_version_popup(PopUpList);

    for (i = 0 ; i < MAX_VERSION_HINT_ITEM_NUM; i++)
    {
         cui_menu_set_item_hint(menu_evt->sender_id, tab[i], PopUpList[i+1]);
    }       
}


#define MMI_FM_RES_BIN

#ifdef __MMI_FM_RES_BIN__

/*------------- RESOURCE_BIN ------------- */

/*****************************************************************************
 * FUNCTION
 *  mtk_itoa
 * DESCRIPTION
 *  
 * PARAMETERS
 *  TempString      [?]         
 *  val             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mtk_itoa(CHAR *TempString, S32 val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (val <= 0)
    {
        TempString[0] = '0';
        return;
    }
    else if (val <= 9)
    {
        TempString[0] = (CHAR) ('0' + val);
        return;
    }
    else
    {
        S32 v, digits, pos;

        for (v = val, digits = 0; v > 0; v = v / 10)
        {
            digits++;
        }

        for (v = val, pos = digits - 1; digits > 0; v = v / 10)
        {
            TempString[pos] = '0' + v % 10;
            digits--;
            pos--;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_fm_prepare_res_bin_popup(UI_string_type *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    CHAR version_string[] = "version ";
    mmi_fm_common_struct *common_cntx;
    
#if defined(__MTK_TARGET__)
    CHAR TempString[MAX_SUB_MENU_SIZE] = {0};
    CHAR *temp;
    U8 *custpack_ver;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    common_cntx = &(g_fm_contxt->common_contxt);
    memset(common_cntx->MenuData, 0, sizeof(common_cntx->MenuData));
    /* Lisen 06052005 */
    /* LangPack Ver# */
    memcpy(TempString, version_string, sizeof(version_string));
    temp = TempString + sizeof(version_string) - 1;
    mtk_itoa((CHAR*) temp, CURRENT_LANG_PACK_RES_VERSION);
    mmi_asc_to_ucs2((CHAR*) common_cntx->MenuData[0], (CHAR*) TempString);

    /* CustPack Ver# */
    memcpy(TempString, version_string, sizeof(version_string));
    temp = TempString + sizeof(version_string) - 1;

    custpack_ver = nvram_get_custpack_version();

    memcpy(temp, custpack_ver, strlen(custpack_ver));

    mmi_asc_to_ucs2((CHAR*) common_cntx->MenuData[1], (CHAR*) TempString);

    for (i = 0; i < 2; i++)
    {
        list[i] = (UI_string_type) common_cntx->MenuData[i];
    }

#else /* (defined(__MTK_TARGET__)) */ 
    /* For PC Simulatior */
    common_cntx = &(g_fm_contxt->common_contxt);

    /* LangPack Ver# */
    mmi_asc_to_ucs2((CHAR*) common_cntx->MenuData[0], (CHAR*) "version 0");

    /* CustPack Ver# */
    mmi_asc_to_ucs2((CHAR*) common_cntx->MenuData[1], (CHAR*) "version 0");

    for (i = 0; i < 2; i++)
    {
        list[i] = (UI_string_type) common_cntx->MenuData[i];
    }
#endif /* ( defined(__MTK_TARGET__)) */ 
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
extern void mmi_fm_res_bin_show_hint(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
    UI_string_type PopUpList[32] = { NULL };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fm_prepare_res_bin_popup(PopUpList);
/*
    for (i = 0, j = 12; i < MAX_RES_BIN_HINT_ITEM_NUM; i++ , j++)
    {
        if (g_fm_test_item_tab[j].menu_id == menu_evt->highlighted_menu_id)
        {
            cui_menu_set_item_hint(menu_evt->sender_id, menu_evt->highlighted_menu_id, PopUpList[i+1]);
        }
    }
 */

	if (menu_evt->highlighted_menu_id == MENU_ID_FM_RESOURCE_LANGPACK)
	{
		cui_menu_set_item_hint(menu_evt->sender_id, menu_evt->highlighted_menu_id, PopUpList[0]);
	}
	else if (menu_evt->highlighted_menu_id == MENU_ID_FM_RESOURCE_CUSTPACK)
	{
		cui_menu_set_item_hint(menu_evt->sender_id, menu_evt->highlighted_menu_id, PopUpList[1]);
	}
	
	change_left_softkey(0, 0);
	redraw_left_softkey();
}

#endif /*__MMI_FM_RES_BIN__*/


#define MMI_FM_AT_CMD

/*****************************************************************************
 * FUNCTION
 *  FM_IsInKeypadTest
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
BOOL FM_IsInKeypadTest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fm_contxt->keypad_contxt.InkeyTestingScreen == 1)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_at_keypad_test_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_at_keypad_test_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FM_KEYPAD_TEST__

    mmi_em_keypad_event_act_ind_struct *rsp_p = (mmi_em_keypad_event_act_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Lisen 0630 */
    mmi_fm_init_other_app_cntx();
    
    if (rsp_p->on_off == 1)
    {
        mmi_fm_select_keypad_test();
    }
    else if (FM_IsInKeypadTest() == MMI_TRUE)
    {
        mmi_frm_scrn_close_active_id();
    }
#endif
}

/* LCD and RGM AT cmd test */

MMI_ID g_fm_at_cmd_gourp_id = 0;

static MMI_RET mmi_fm_at_cmd_leave_proc(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
           g_fm_at_cmd_gourp_id = 0;
           break;          
        }
	return MMI_RET_OK;
}

#ifndef __MMI_MAINLCD_96X64__
/*****************************************************************************
 * FUNCTION
 *  FM_ATLCDTestMsgHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_at_lcd_test_msg_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_lcm_test_ind_struct *rsp_p = (mmi_em_lcm_test_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_fm_at_cmd_gourp_id == 0)
    {
        g_fm_at_cmd_gourp_id = mmi_frm_group_create(GRP_ID_ROOT,GRP_ID_AUTO_GEN, mmi_fm_at_cmd_leave_proc, NULL);
        mmi_frm_group_enter(g_fm_at_cmd_gourp_id, MMI_FRM_NODE_SMART_CLOSE_CAUSED_BY_CLOSE_FLAG);
		mmi_frm_scrn_enter
        (g_fm_at_cmd_gourp_id, 
         GLOBAL_SCR_DUMMY, 
         NULL, 
         NULL, 
         MMI_FRM_FULL_SCRN);
    }

    switch (rsp_p->color)
    {

   /***********************/
   /** FM_LCDShowColor:  **/
   /**  0 : Auto         **/
   /**  1 : Red          **/
   /**  2 : Green        **/
   /**  3 : Blue         **/
   /**  4 : White        **/
   /***********************/

        case 0: /* R */
			 mmi_fm_set_show_color(255, 0, 0);
            break;

        case 1: /* G */
			 mmi_fm_set_show_color(0, 255, 0);
            break;

        case 2: /* B */
			 mmi_fm_set_show_color(0, 0, 255);
            break;

        case 3: /* W */
			 mmi_fm_set_show_color(255, 255, 255);
            break;

        case 4: /* Back to Idle screen */
            mmi_idle_display();
            EntryFMMenu();
            break;

        default:
            break;
    }
    /*
     * if (rsp_p->color_type == 1)
     * {
     * FM_EntryColorTest();
     * }
     * else
     * GoBackHistory();
     */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_at_lcm_rgb_test_handler
 * DESCRIPTION
 *  This function is to handle AT command LCM RGB Test
  * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_at_lcm_rgb_test_handler(void *ind, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_at_general_res_req_struct *rsp_msg;
    mmi_em_rgb_test_req_ind_struct *msg = (mmi_em_rgb_test_req_ind_struct*) ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    rsp_msg = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));
    
    if (msg->type)
    {
        if ((msg->red > 255) || (msg->green > 255) || (msg->blue > 255))
        {
            rsp_msg->result = KAL_FALSE;
        }
        else
        {
            rsp_msg->result = KAL_TRUE;
           mmi_fm_at_lcd_set_color((U8)msg->red, (U8)msg->green, (U8)msg->blue);       
        }
    }
    else
    {
        rsp_msg->result = KAL_TRUE;
        mmi_frm_scrn_close_active_id();
    }    

	   mmi_frm_send_ilm((oslModuleType)mod_id, MSG_ID_MMI_AT_GENERAL_RES_REQ, 
                    (oslParaType*) rsp_msg, (oslPeerBuffType *)NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_at_lcm_rgb_test_handler
 * DESCRIPTION
 *  This function is to handle AT command LCM RGB Test
  * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_at_lcd_set_color(U8 red, U8 green, U8 blue)
{
	if (g_fm_at_cmd_gourp_id == 0)
    {
        g_fm_at_cmd_gourp_id = mmi_frm_group_create(GRP_ID_ROOT,GRP_ID_AUTO_GEN, mmi_fm_at_cmd_leave_proc, NULL);
        mmi_frm_group_enter(g_fm_at_cmd_gourp_id, MMI_FRM_NODE_SMART_CLOSE_CAUSED_BY_CLOSE_FLAG);
		mmi_frm_scrn_enter
        (g_fm_at_cmd_gourp_id, 
         GLOBAL_SCR_DUMMY, 
         NULL, 
         NULL, 
         MMI_FRM_FULL_SCRN);
    }

   mmi_fm_set_show_color(red, green, blue);
}
#endif /* __MMI_MAINLCD_96X64__ */
#define MMI_FM_OTHER_APP

/*------------- other app -------------*/

static MMI_RET mmi_fm_other_app_leave_proc(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:

           g_fm_gourp_id = 0;

           if (g_fm_contxt)
           {
                applib_mem_ap_free(g_fm_contxt);
                g_fm_contxt = NULL;
           }      
           MMI_FM_DCM_POST_UNLOAD();
           break;          
           
        }
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_init_other_app_cntx
 * DESCRIPTION
 *  At present, *#8375#, AT cmd test , will call it. It will create group and
 *  alloc ASM for these APP, becasue these APP will reuse FactoryMode code.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_fm_init_other_app_cntx(void)
{
    g_fm_contxt = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_FM_COMM_MEM,sizeof(mmi_fm_item_cntxt_struct));
    
    if (g_fm_contxt == 0)
     {
        DisplayPopup((PU8) GetString(STR_GLOBAL_INSUFFICIENT_MEMORY), NULL, 0, 1000, 0);
        return MMI_FALSE;
     }

    memset(g_fm_contxt, 0, sizeof(mmi_fm_item_cntxt_struct));
    //mmi_fm_common_greate_group();   
    if (g_fm_gourp_id == 0)
    {
        g_fm_gourp_id = mmi_frm_group_create(GRP_ID_ROOT,GRP_ID_AUTO_GEN, mmi_fm_other_app_leave_proc, NULL);
        mmi_frm_group_enter(g_fm_gourp_id, MMI_FRM_NODE_SMART_CLOSE_CAUSED_BY_CLOSE_FLAG);
    }

    return MMI_TRUE;
}

#define MMI_READ_VERSION_8375

#define MMI_FM_RTC

/*--------  RTC -------- */

/*****************************************************************************
 * FUNCTION
 *  FM_HandleRTCRsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_handle_rtc_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(FM_RTC_START_TIMER);

    /* MTK added, Max for alarm */

    g_fm_contxt->rtc_contxt.gFactoryAlarm = 1;

    FactorySetAlarm(3);
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMRTCHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_select_rtc(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_enter
        (g_fm_gourp_id, 
        SCR_ID_FM_RTC, 
        NULL, 
        mmi_fm_select_rtc, 
        MMI_FRM_FULL_SCRN);

    ShowCategory21Screen((U16) NULL, 0, (U16) NULL, 0, (U16) NULL, 0, STR_ID_FM_RTC_NOTIFY, NULL);
    
    mmi_fm_set_general_goback_function();
    mmi_fm_handle_rtc_rsp();

#else /* __MTK_TARGET__ */ 

    PopupNoSupport();

#endif /* __MTK_TARGET__ */ 
} 

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_get_melody_version
 * DESCRIPTION
 *
 * PARAMETERS
 *  mel_ver     [?]
 * RETURNS
 *
 *****************************************************************************/
kal_bool mmi_fm_get_melody_version(kal_char *mel_ver)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strcpy(mel_ver, "Melody V0.0");
    return KAL_TRUE;
}

void mmi_fm_entry_summary_version(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    InitFactoryModeEvent();

	if (g_fm_gourp_id != NULL)
	{
		DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), NULL, 0, 1000, 0);
        MMI_FM_DCM_POST_UNLOAD();
        return ;
	}

     if (mmi_fm_init_other_app_cntx()== MMI_FALSE)
     {
        MMI_FM_DCM_POST_UNLOAD();
        return;
     }
     mmi_fm_select_version_summary_menu();
}


#if (defined(__MMI_AP_DCM_FM__) || defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__))
#pragma arm section rodata , code
#endif /* (defined(__MMI_AP_DCM_FM__) || defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)) */


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_quick_test_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
/* For AT cmd Read quick test report*/
extern void mmi_fm_quick_test_report(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_em_quick_test_report_res_req_struct *msg;
	nvram_ef_quicktest_struct testdata;
	U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //memset(&testdata, 0, sizeof(testdata));
    ReadRecordSlim(NVRAM_EF_QUICKTEST_LID, 2, &testdata, NVRAM_EF_QUICKTEST_SIZE);
    msg = OslConstructDataPtr(sizeof(mmi_em_quick_test_report_res_req_struct));

    msg->result = KAL_TRUE;
    msg->test_count = testdata.testcount;

	for (i = 0; i < sizeof(testdata.testlist); i++)
	{
		msg->test_list[i] = testdata.testlist[i];
	}
    FM_SendMsg(MSG_ID_MMI_EM_QUICK_TEST_REPORT_RES_REQ, msg, NULL);
	

}


/*****************************************************************************
 * FUNCTION
 *  FM_ATEntryMenuHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fm_at_entry_menu_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_factory_test_ind_struct *factory_test_struct = (mmi_factory_test_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_display();

    if (factory_test_struct->on_off == 1)
    {
        EntryFMMenu();    /* This is a test for enter FactoryMode mainmenu */
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryFMVersionSummaryMenu
 * DESCRIPTION
 *  *#8375#
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
extern void EntryFMVersionSummaryMenu(void)
{    
    /*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
    MMI_FM_DCM_LOAD();

    mmi_fm_entry_summary_version();
}


#endif
