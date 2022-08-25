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
 *  EngineerModeMain.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is for engineer mode.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"
#include "EngineerModeUtil.h"
#if (defined(__MMI_ENGINEER_MODE__) || defined(__MMI_FACTORY_MODE__))

#if defined(COSMOS_EM_INTERNAL_DCM)
#include "dcmgr.h"
#elif defined (PLUTO_EM_INTERNAL_DCM)
#include "MMI_ap_dcm_config.h"  
#endif /* COSMOS_EM_INTERNAL_DCM */

#include "MMIDataType.h"
#include "Mdi_audio.h"
#include "GpioSrvGprot.h"
#ifdef __MMI_BT_SUPPORT__   
#include "BTMMIScrGprots.h"
#endif
#include "EngineerModeGprot.h"

mmi_emfm_mode_enum gCurrentMode = NORMAL_MODE;

mmi_ret DeInitSpecialMode(mmi_event_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gCurrentMode == ENGINEERING_MODE)
    {
        gCurrentMode = NORMAL_MODE;
        mdi_audio_resume_background_play();
        srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_START);
    }
    
    return MMI_RET_OK;
}

#if defined(PLUTO_EM_INTERNAL_DCM)
#pragma arm section rodata = "DYNAMIC_CODE_EM_RODATA" , code = "DYNAMIC_CODE_EM_ROCODE"
#elif defined(COSMOS_EM_INTERNAL_DCM)
#pragma arm section rodata = "DYNAMIC_CODE_COSMOS_EM_RODATA" , code = "DYNAMIC_CODE_COSMOS_EM_ROCODE"
#endif /* PLUTO_EM_INTERNAL_DCM */ 

void mmi_emfm_set_mode(mmi_emfm_mode_enum mode)
{
    gCurrentMode = mode;
}

mmi_emfm_mode_enum mmi_emfm_get_mode(void)
{
    return gCurrentMode;
}

void mmi_emfm_clear_mode(void)
{
    gCurrentMode = NORMAL_MODE;
}

#endif

#ifdef __MMI_ENGINEER_MODE__    
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "IdleAppDef.h"
#include "GpioSrvGprot.h"
#include "EngineerModeResDef.h"
#include "mmi_frm_history_gprot.h"
#include "GlobalMenuItems.h"
#include "CustMenuRes.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "uart_sw.h"
#include "EngineerModeAppResDef.h"

#include "ProtocolEvents.h"
#include "mdi_audio.h"
#include "CommonScreens.h"

#if defined (__MMI_CSB_BROWSER__)
#include "CatScreenBrowserProts.h"
#endif
#include "mmi_rp_app_idle_def.h"

#include "EngineerModeUtil.h"
#include "EngineerModeCommMem.h"
#include "EngineerModeCommUI.h"

#include "EngineerModePCSNetwork.h"
#include "EngineerModeDevice.h"
#include "EngineerModePMIC.h"
#include "EngineerModeAGPSlogGProt.h"

#if ( defined (__MMI_EM_PROFILING_FS_TEST__) && !defined(FMT_NOT_PRESENT) && !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__) )
#include "EngineerModeFSTestUI.h"
#endif 

#ifdef __MMI_EM_PROFILING_GDI_PROFILING__
#include "EngineerModeGDIProfiling.h"
#endif 

#include "EngineerMode.h"

#ifdef __MMI_EM_CTM_CTA_TDD__
#include "EngineerModeConftest.h"
#endif
#ifdef __MMI_EM_NW_FDD_NETWORK_INFO__
#include"EngineerMode3GInfo.h"
#endif  /* __MMI_EM_NW_FDD_NETWORK_INFO__*/

#ifdef __MMI_EM_GPRS_CNMGR_SCRI_SUPPORT__
#include "EngineerModeCnmgr.h"
#endif

#include "EngineerModeAudio.h"


/***************************************************************************** 
 * Static Variable
 *****************************************************************************/



/***************************************************************************** 
 * Global Variable
 *****************************************************************************/


/***************************************************************************** 
 * Static Function
 *****************************************************************************/


/***************************************************************************** 
 * Global Function 
 *****************************************************************************/

/* EM init functions */
#ifdef __MMI_EM_MISC_SOFTWARE_TRACER__
/* under construction !*/
#endif
extern void nvram_get_ps(kal_uint8 *port, kal_uint32 *baudrate);
extern void mmi_em_audio_debug_info_init(void);
extern void nvram_get_tst(kal_uint8 *port, kal_uint32 *baudrate);
extern void nvram_get_tst_l1(kal_uint8 *port, kal_uint32 *baudrate);
extern void nvram_get_cti(kal_uint8 *port, kal_uint32 *baudrate);
extern void mmi_em_misc_menu_event_hdlr(cui_menu_event_struct *event);
extern void mmi_em_misc_menu_event_entry_hdlr(cui_menu_event_struct *event);
#ifdef __MMI_EM_IPERF__
	extern void mmi_em_iperf_menu_sel_event_hdlr(cui_menu_event_struct *event);
#endif /* __MMI_EM_IPERF__ */
#ifdef __MMI_EM_PROFILING_MULTIMEDIA_PROFILING__
/* under construction !*/
#endif /*__MMI_EM_PROFILING_MULTIMEDIA_PROFILING__*/

#ifdef __MMI_EM_RF_GSM__ 
extern void EMRFTestGSMInitContext(void);
extern void EMRFTestGsmSendRes(void* inMsg);
#endif /* #ifdef __MMI_EM_RF_GSM__ */

#if defined(__MMI_EM_RF_WIFI__)
extern void EMRFTestWiFiInitContext(void);
#endif  /* defined(__MMI_EM_RF_WIFI__) */

extern void mmi_em_inet_init(void);

#if defined(__MMI_EM_CAM_AF_CONTSHOT__)
/* under construction !*/
#endif

#ifdef __MMI_EM_MISC_FOTA_DEBUG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_EM_MISC_FOTA_DEBUG__ */

#ifdef __MMI_EM_GPRS_PDP__
extern void EngineerModeGprsDeactivatePDPRes(void *inMsg);
extern void EngineerModeGprsSendDataRes(void *inMsg);
extern void EngineerModeGprsSetDefinitionRes(void *inMsg);
#ifdef __R99__
extern void EngineerModeGprsSetEQosRes(void *inMsg);
#endif 
extern void EngineerModeGprsSetQosRes(void *inMsg);
extern void EngineerModeGprsActTestRes(void *inMsg);
#endif /*__MMI_EM_GPRS_PDP__*/
extern void InitEngineerModeSetting(void);

/* EM ASM*/
static void mmi_em_init_asm_mem(void);
static void mmi_em_main_menu_init_and_entry(void);
static MMI_BOOL mmi_em_main_menu_mem_stop_hdlr(void);
void mmi_em_main_menu_release_mem(void);
static MMI_ID mmi_em_enter_main_menu(void);

#ifdef __MMI_EM_NW_TDD_NETWORK_INFO__
extern void mmi_em_enter_tdd(cui_menu_event_struct *evt);
#endif


/*****************************************************************************
 * FUNCTION
 *  DummyEmCBHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DummyEmCBHandler(void)
{
    return;
}


/*****************************************************************************
 * FUNCTION
 *  DeinitEngineerEvent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeinitEngineerEvent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /********************* Network **********************/
    const U16 eventIDs[] = {
#ifdef __MODEM_EM_MODE__
#ifdef __MMI_EM_NW_NETWORK_INFO__
    MSG_ID_MMI_EM_UPDATE_RSP,
#endif
#if defined(__MMI_EM_NW_EVENT_NOTIFY__)
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__MMI_EM_NW_EVENT_NOTIFY__) */    
#endif /* #ifdef __MODEM_EM_MODE__ */    
    
    /********************** Device **********************/    
    /* Set UART */
    MSG_ID_EM_SET_UART_RSP,
#ifdef __DYNAMIC_UART_PORT_SWITCHING__
    MSG_ID_MMI_ATTACH_UART_PORT_RSP,
    MSG_ID_MMI_DETACH_UART_PORT_RSP,
#endif
    /* Set Default Level */
#ifdef __MMI_EM_DEV_SET_HW_LEVEL__
    MSG_ID_MMI_EQ_SET_HW_LEVEL_RSP,
#endif
    /* Sleep mode */
    MSG_ID_MMI_EQ_SET_SLEEP_MODE_RSP,
#ifdef __MMI_EM_DEV_FM_RADIO__
    /* FM Radio */
    MSG_ID_MMI_EQ_FM_RADIO_CONFIG_RSP,
#endif
    /*********************** RF Tool *********************/ 
#ifdef __MMI_EM_RF_GSM__
    MSG_ID_MMI_EQ_RF_TEST_GSM_RSP,
#endif /* __MMI_EM_RF_GSM__ */ 
    /************************ GPRS ***********************/ 
#if (defined(__MOD_TCM__) && defined(__MMI_EM_GPRS_PDP__))
    MSG_ID_MMI_PS_ACT_TEST_RSP,
    MSG_ID_MMI_PS_SEND_DATA_RSP,
    MSG_ID_MMI_PS_SET_DEFINITION_RSP,
    MSG_ID_MMI_PS_SET_SEC_DEFINITION_RSP,
#ifdef __R99__
    MSG_ID_MMI_PS_SET_EQOS_RSP,
#endif 
    MSG_ID_MMI_PS_SET_QOS_RSP,
    MSG_ID_MMI_PS_ACT_TEST_RSP
#endif /* defined(__MOD_TCM__) && defined(__MMI_EM_GPRS_PDP__) */
    };    
    U16 eventNum = (sizeof(eventIDs)/sizeof(U16));
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(index = 0; index < eventNum; ++index)
    {
        SetProtocolEventHandler(DummyEmCBHandler, eventIDs[index]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  InitEngineerEvent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void InitEngineerEvent(void)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /********************* Network **********************/
#ifdef __MODEM_EM_MODE__
#ifdef __MMI_EM_NW_NETWORK_INFO__
    SetProtocolEventHandler(EngineerModeStartRes, MSG_ID_MMI_EM_UPDATE_RSP);
#endif
#if defined(__MMI_EM_NW_EVENT_NOTIFY__)
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__MMI_EM_NW_EVENT_NOTIFY__) */    
#endif /* #ifdef __MODEM_EM_MODE__ */    
    
    /********************** Device **********************/    
    /* Set UART */
    SetProtocolEventHandler(EngineerModeSetUartRes, MSG_ID_EM_SET_UART_RSP);
#ifdef __DYNAMIC_UART_PORT_SWITCHING__
    SetProtocolEventHandler(EngineerModeAttachUartRes, MSG_ID_MMI_ATTACH_UART_PORT_RSP);
    SetProtocolEventHandler(EngineerModeDetachUartRes, MSG_ID_MMI_DETACH_UART_PORT_RSP);
#endif
    /* Set Default Level */
#ifdef __MMI_EM_DEV_SET_HW_LEVEL__
    SetProtocolEventHandler(SendSetHWLevelInfoRsp, MSG_ID_MMI_EQ_SET_HW_LEVEL_RSP);
#endif
    /* Sleep mode */
    SetProtocolEventHandler(EngineerModeSetSleepModeRes, MSG_ID_MMI_EQ_SET_SLEEP_MODE_RSP);


#ifdef __MMI_EM_DEV_FM_RADIO__
    /* FM Radio */
    SetProtocolEventHandler (EMFMRadioSendRes, MSG_ID_MMI_EQ_FM_RADIO_CONFIG_RSP);
#endif	
    /*********************** RF Tool *********************/ 
#ifdef __MMI_EM_RF_GSM__
    SetProtocolEventHandler(EMRFTestGsmSendRes ,  MSG_ID_MMI_EQ_RF_TEST_GSM_RSP);
#endif /* __MMI_EM_RF_GSM__ */
    /************************ GPRS ***********************/ 
#if (defined(__MOD_TCM__) && defined(__MMI_EM_GPRS_PDP__))
    SetProtocolEventHandler(EngineerModeGprsDeactivatePDPRes, MSG_ID_MMI_PS_ACT_TEST_RSP);
    SetProtocolEventHandler(EngineerModeGprsSendDataRes, MSG_ID_MMI_PS_SEND_DATA_RSP);
    SetProtocolEventHandler(EngineerModeGprsSetDefinitionRes, MSG_ID_MMI_PS_SET_DEFINITION_RSP);
    SetProtocolEventHandler(EngineerModeGprsSetDefinitionRes, MSG_ID_MMI_PS_SET_SEC_DEFINITION_RSP);
#ifdef __R99__
    SetProtocolEventHandler(EngineerModeGprsSetEQosRes, MSG_ID_MMI_PS_SET_EQOS_RSP);
#endif 
    SetProtocolEventHandler(EngineerModeGprsSetQosRes, MSG_ID_MMI_PS_SET_QOS_RSP);
    SetProtocolEventHandler(EngineerModeGprsActTestRes, MSG_ID_MMI_PS_ACT_TEST_RSP);
#endif /* defined(__MOD_TCM__) && defined(__MMI_EM_GPRS_PDP__) */
     
}

/*****************************************************************************
* FUNCTION
*  InitEngineerModeSetting
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void InitEngineerModeSetting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCurrentMode = ENGINEERING_MODE;
    mdi_audio_suspend_background_play();
    srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_STOP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_device_is_use_usb_as_uart_port
 * DESCRIPTION
 *  To check if USB port is occupied.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_em_device_is_use_usb_as_uart_port(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ps_port;
    U32 ps_baudrate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_get_tst(&ps_port, &ps_baudrate);
    if (ps_port == uart_port_usb)
    {
        return MMI_TRUE;
    }

    nvram_get_tst_l1(&ps_port, &ps_baudrate);
    if (ps_port == uart_port_usb)
    {
        return MMI_TRUE;        
    }

    nvram_get_ps(&ps_port, &ps_baudrate);
    if (ps_port == uart_port_usb)
    {
        return MMI_TRUE;        
    }

    nvram_get_cti(&ps_port, &ps_baudrate);
    if (ps_port == uart_port_usb)
    {
        return MMI_TRUE;        
    }
    return MMI_FALSE;
}

/* EM ASM*/
/*****************************************************************************
* FUNCTION
*  mmi_em_init_asm_mem
* DESCRIPTION
*  Register EM to ASM
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_em_init_asm_mem(void)
{
    /*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    mmi_em_comm_mem_ap_register();
}

static void mmi_em_main_menu_init_and_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EM_REG_STOP_FUNC(mmi_em_main_menu_mem_stop_hdlr);
    
    mmi_em_enter_main_menu();
}

static MMI_BOOL mmi_em_main_menu_mem_stop_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_close_root_group();
    mmi_em_main_menu_release_mem();
    return MMI_TRUE;
}

void mmi_em_main_menu_release_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EM_UNREG_STOP_FUNC(mmi_em_main_menu_mem_stop_hdlr);
    mmi_em_comm_mem_ap_deinit();
}

#include "mmi_rp_app_engineermode1_def.h"
#include "MenuCuiGprot.h"
#include "EngineerModeGprs.h"
#include "EngineerModeRfTest.h"
#include "EngineerModeDM.h"
#include "EngineerModeBT.h"
#include "EngineerModePCSNetwork.h"
#include "EngineerModeMultimedia.h"
#include "EngineerModeStorage.h"
#include "EngineerModeIperf.h"
#include "EngineerModeFRMProfiling.h"
#include "EngineerModeDebugInfo.h"

static MMI_ID mmi_em_enter_main_menu(void)
{
    MMI_ID em_root_group_id;
    MMI_ID em_main_menu_id;


    if (mmi_em_get_root_group() != 0)
    {
        mmi_em_close_root_group();
    }
    
    em_root_group_id = mmi_em_enter_root_group();

    em_main_menu_id = cui_menu_create(em_root_group_id, 
                               CUI_MENU_SRC_TYPE_RESOURCE, 
                               CUI_MENU_TYPE_FROM_RESOURCE, 
                               MENU_ID_EM_MAIN_MENU,
                               MMI_TRUE, NULL);
    mmi_em_set_main_menu_id(em_main_menu_id);
    InitEngineerModeSetting();
    cui_menu_run(em_main_menu_id);

    mmi_em_scr_level_notify(
        MMI_EM_SCR_NODE_FLAG_MENU_CUR,
        MENU_ID_EM_MAIN_MENU,
        MMI_EM_SCR_NODE_FLAG_NONE, 0);

    return em_main_menu_id;
}

S32 mmi_em_mainmenu_select_handler(mmi_event_struct *arg)
{ 
    cui_menu_event_struct *em_menu_event = (cui_menu_event_struct*)arg;
       
    /* Network*/
#ifdef __MMI_EM_NETWORK_SETTINGS__
    mmi_em_nw_menu_event_hdlr(em_menu_event);
#endif
    /* MISC */
    mmi_em_misc_menu_event_hdlr(em_menu_event);
    /* multi media file*/
    mmi_em_misc_multi_media_menu_event_hdlr(em_menu_event);
    /* Device */
    mmi_em_device_menu_sel_event_hdlr(em_menu_event);

#if defined(__MMI_EM_AUDIO__) || defined(__MMI_EM_AUDIO_DEBUG_INFO__) || defined(__MMI_EM_AUDIO_AUTO_VM__)  
    /* Audio*/
    mmi_em_audio_menu_sel_event_hdlr(em_menu_event);
#endif
    
#if defined(__MMI_EM_GPRS_AUTO_ATTACH__) || defined(__MMI_EM_GPRS_PDP__)
    /* GPRS*/    
    mmi_em_gprs_menu_event_hdlr(em_menu_event);
#endif 
    /* Profiling */
    //mmi_em_profiling_menu_event_hdlr(em_menu_event);
    mmi_em_profiling_menu_event_select_hdlr(em_menu_event);

#if defined(__MMI_EM_RF_GSM__) || defined(__MMI_EM_RF_WIFI__)
    /* RF test*/
    mmi_em_rf_test_menu_event_hdlr(em_menu_event);
#endif

#if defined(__MMI_EM_LAST_EXCEPTION__) || defined(__MMI_EM_DEBUG_INFO_SYS_STATS__)    
    /* Bug info */
    mmi_em_debug_info_menu_event_hdlr(em_menu_event);
#endif
    /* BT */
#if defined(__MMI_EM_BT_GENERAL_TEST__)
    mmi_em_bt_menu_sel_event_hdlr(em_menu_event);
#endif

#if defined(__MMI_EM_DEBUG_INFO_DRIVE_LETTER__) || defined(__MMI_EM_MISC_FOTA_DEBUG__) 
/* under construction !*/
/* under construction !*/
#endif
    
#ifdef __MMI_EM_MISC_DCD__    
    /* DM */
    mmi_em_dm_menu_event_hdlr(em_menu_event);
#endif
#ifdef __MMI_EM_IPERF__
    mmi_em_iperf_menu_sel_event_hdlr(em_menu_event);
#endif /* __MMI_EM_IPERF__ */




#ifdef __MMI_EM_PROFILING_MULTIMEDIA_PROFILING__
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_EM_PROFILING_GDI_PROFILING__
    /* Second level: Profiling | GDI */
    mmi_em_profiling_gdi_menu_select_hdlr(em_menu_event);
#endif

#ifdef __MMI_EM_CTM_CTA_TDD__

    /*CTA*/
    mmi_em_conf_test_highlight_hdlr(em_menu_event);
#endif



    return MMI_RET_OK;
}

S32 mmi_em_mainmenu_entry_handler(mmi_event_struct *arg)
{
    cui_menu_event_struct *em_menu_event = (cui_menu_event_struct*)arg;
            
    cui_menu_set_currlist_flags(em_menu_event->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
 
#ifdef __MMI_BT_SUPPORT__   
    cui_menu_set_item_hidden(
        em_menu_event->sender_id,
        MENU_ID_EM_BLUETOOTH,
        (mmi_bt_is_to_display_bt_menu()?MMI_FALSE:MMI_TRUE));
#endif

    /* Network*/
#ifdef __MMI_EM_NETWORK_SETTINGS__
    mmi_em_nw_menu_entry_event_hdlr(em_menu_event);
#endif

    /* MISC */
    mmi_em_misc_menu_event_entry_hdlr(em_menu_event);

    /* DEVICE */
    mmi_em_device_menu_event_entry_hdlr(em_menu_event);

    /* Profiling */
#ifndef __MMI_MAINLCD_96X64__
    mmi_em_profiling_menu_event_entry_hdlr(em_menu_event);
#endif

#if defined(__MMI_EM_AUDIO__) || defined(__MMI_EM_AUDIO_DEBUG_INFO__) || defined(__MMI_EM_AUDIO_AUTO_VM__)  
    /* Audio*/
    mmi_em_audio_menu_entry_event_hdlr(em_menu_event);
#endif

#if defined(__MMI_EM_BT_GENERAL_TEST__)
    /* BT */
    mmi_em_bt_menu_entry_event_hdlr(em_menu_event);
#endif

#if defined(__MMI_EM_GPRS_PDP__) || defined (__MMI_EM_GPRS_AUTO_ATTACH__) || defined(__MMI_EM_GPRS_CNMGR_SCRI_SUPPORT__)
    /* GPRS */
    mmi_em_gprs_menu_entry_event_hdlr(em_menu_event);
#endif

    return MMI_RET_OK;
}

S32 mmi_em_mainmenu_list_exit_handler(cui_menu_event_struct *em_menu_event)
{
    
    /* Network*/
#ifdef __MMI_EM_NETWORK_SETTINGS__
    mmi_em_nw_menu_exit_event_hdlr(em_menu_event);
#endif
#if defined(__MMI_EM_RF_GSM__) || defined(__MMI_EM_RF_WIFI__)    
    /* rf_test */
    mmi_em_rf_test_tool_menu_list_exit_hdlr(em_menu_event);
#endif
    /* device  */
    mmi_em_device_menu_event_exit_hdlr(em_menu_event);
#if defined(__MMI_EM_AUDIO__) || defined(__MMI_EM_AUDIO_DEBUG_INFO__) || defined(__MMI_EM_AUDIO_AUTO_VM__)  
    /* Audio */
    mmi_em_aud_menu_exit_event_hdlr(em_menu_event);
#endif
#ifdef __MMI_EM_GPRS_PDP__
    /* gprs */
    mmi_em_gprs_menu_list_exit_hdlr(em_menu_event);
#endif
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_em_entry_engineermode_menu
* DESCRIPTION
*  Init ASM before entering EM main menu
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_em_entry_engineermode_menu(void)
{
    //DCM require
    InitEngineerEvent();
    
    if (!mmi_em_comm_mem_ap_init(mmi_em_main_menu_init_and_entry))
    {
        return;
    }
    mmi_em_main_menu_init_and_entry();
}


// DCM require
#if (defined(COSMOS_EM_INTERNAL_DCM) || defined(PLUTO_EM_INTERNAL_DCM))
#pragma arm section rodata , code
#endif /* COSMOS_EM_INTERNAL_DCM || PLUTO_EM_INTERNAL_DCM */ 

/*****************************************************************************
 * FUNCTION
 *  InitEngineerMode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitEngineerMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EM_DCM_LOAD();

    mmi_em_init_asm_mem();
    
#ifdef __MMI_EM_RF_GSM__
    /* RF Test Tool GSM Init Context */
    EMRFTestGSMInitContext();
#endif /* __MMI_EM_RF_GSM__ */   


#if defined(__MMI_EM_RF_WIFI__)
    /* RF Test Tool Wifi Init Context */
    EMRFTestWiFiInitContext();
#endif   /* #if defined(__MMI_EM_RF_WIFI__) */

#ifdef __MMI_EM_GPRS_CNMGR_SCRI_SUPPORT__
    mmi_em_cnmgr_init();
#endif

    /********************** Bluetooth *******************/

    /***********************CSB**************************/
#if defined(__MMI_CSB_BROWSER__)
    InitCSB();	
#endif

#ifdef __MMI_EM_MISC_SOFTWARE_TRACER__
/* under construction !*/
#endif

#if defined(__MMI_EM_CAM_AF_CONTSHOT__)
/* under construction !*/
#endif

    /********************** AGPSLOG *******************/
    mmi_em_agpslog_init();

    /*********************** Internet Application ************************/
#if !defined(__MMI_EM_INET_APP_SLIM__)
    mmi_em_inet_init();
#endif

    #if ( defined (__MMI_EM_PROFILING_FS_TEST__) && !defined(FMT_NOT_PRESENT) && !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__) )
      /*FS Test*/
    mmi_em_fs_test_init();
    #endif

    mmi_frm_cb_reg_event(EVT_ID_IDLE_GROUP_ENTER, DeInitSpecialMode, NULL);
    
#ifdef __MMI_EM_AUDIO_AUTO_VM__
    mmi_em_aud_auto_vm_setting_init();
#endif
#if defined(__MMI_EM_AUDIO__) || defined(__MMI_EM_AUDIO_DEBUG_INFO__) || defined(__MMI_EM_AUDIO_AUTO_VM__)  
    /* Audio Debug Info Init */
    mmi_em_audio_debug_info_init();
#endif

    MMI_EM_DCM_SEND_UNLOAD();
}


/*****************************************************************************
* FUNCTION
*  mmi_em_pre_entry_engineermode_menu
* DESCRIPTION
*  Init ASM before entering EM main menu
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_em_pre_entry_engineermode_menu(void)
{
    MMI_EM_DCM_LOAD();

    mmi_em_entry_engineermode_menu();
}


#endif /* __MMI_ENGINEER_MODE__ */
