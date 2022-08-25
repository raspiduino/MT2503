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
 *  EngineerModeMultimedia.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is for engineer mode multimedia items. It includes:
 *      - Ext Camera
 *      - TVOUT
 *      - MTV setting
 *      - FM Radio
 *      - Camera AF Contshot
 *      - J2ME
 *      - Video High baudrate
 *      - Java Heap Size
 *      - Software Tracer
 *      - BCR
 *      - JUI Debug
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
#ifdef __MMI_ENGINEER_MODE__ 

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


#include "CommonScreens.h"
#include "CommonScreensResDef.h"
#include "SettingDefs.h"        /* ST_NOTIFYDURATION define */

#include "EngineerModeUtil.h"

#include "EngineerModeMultimedia.h"
#include "EngineerModeCommUI.h"
#include "med_api.h"
#include "EngineerModeCommMem.h"
#include "App_mem.h"

/*  Device -> FM radio */
#ifdef __MMI_EM_DEV_FM_RADIO__
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "aud_defs.h"
#include "l1audio.h"
#endif /* __MMI_EM_DEV_FM_RADIO__ */


/* Device -> Cam AF */
#if defined(__MMI_EM_CAM_AF_CONTSHOT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_CAMERA__)
    #if defined(__MMI_CAMCORDER__)
/* under construction !*/
#if defined(__COSMOS_MMI_PACKAGE__)
#if defined(__LOW_COST_SUPPORT_COMMON__)
/* under construction !*/
#else
/* under construction !*/
#endif    
#else
/* under construction !*/
#endif    
    #else /* defined(__MMI_CAMCORDER__) */
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_CAMCORDER__) */
#endif /* defined(__MMI_CAMERA__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_EM_CAM_AF_CONTSHOT__) */


#if defined(__MMI_EM_MISC_MEDIA_MEMORY_SETTING__)
/* under construction !*/
#endif

/* Misc -> JAVA Heap Size */
#if defined(__MMI_EM_JAVA_HEAP_SIZE_SETTING__)
/* under construction !*/
/* under construction !*/
#endif /* __MMI_EM_JAVA_HEAP_SIZE_SETTING__ */

#include "ProfilesSrvGprot.h"
#include "InlineCuiGprot.h"
#if defined(__MMI_EM_VIDEO_SETTING__)
#include "hal_custom_video.h"
#include "hal_custom_video_codec_if.h" //#include "hal_custom_video_codec_internal.h"
#endif

#include "MMIDataType.h"
#include "lcd_sw_inc.h"
#include "gdi_datatype.h"
#include "isp_if.h"
#include "kal_general_types.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "mmi_frm_history_gprot.h"
#include "gui_typedef.h"
#include "GlobalResDef.h"
#include "wgui_include.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalMenuItems.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "wgui_categories_list.h"
#include "CustMenuRes.h"
#include "kal_public_api.h"
#include "wgui_categories_inputs.h"
#include "ImeGprot.h"
#include "mmi_frm_input_gprot.h"
#include "stdlib.h"
#include "mmi_msg_struct.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "device.h"
#include "ps_public_struct.h"
#include "stack_msgs.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "stdio.h"
#include "wgui_categories_text_viewer.h"
#include "mmi_rp_file_type_def.h"
#include "fs_type.h"
#include "fs_func.h"
#include "mmi_res_range_def.h"
#include "gdi_include.h"
#include "gui.h"
#include "wgui_inputs.h"
#include "DebugInitDef_Int.h"
#include "gui_themes.h"
#include "ScreenRotationGprot.h"
#include "lcd_if.h"
#include "lcd_sw_rnd.h"
#include "gdi_lcd_config.h"
#include "mmi_frm_mem_gprot.h"
#include "gdi_features.h"
#include "GpioSrvGprot.h"

#include "PhoneSetup.h"
#include "mmi_rp_app_engineermode1_def.h"
#include "MenuCuiGprot.h"
#include "FileMgrSrvGProt.h"
#include "FileMgrResDef.h"
#include "EngineerModeMultimediaMemConfig.h"
#ifdef __MMI_EM_MOBILE_TV_SETTING__
#include "MobileTVPlayerGProt.h"
#endif

#ifdef __MMI_CLIPBOARD__
#include "ImeGprot.h"
#endif /* __MMI_CLIPBOARD__ */
extern U16 mmi_java_get_title_icon(void);

/***************************************************************************** 
 * Define
 *****************************************************************************/

/*  Device -> FM radio */
/***********************************************
 ** Menu Tree: Device --> Fm radio
 ***********************************************/

#ifdef __MMI_EM_DEV_FM_RADIO__
#define EM_FM_RADIO_RSSI_INFO_DURATION 3000  /* 3 s */
#define MMI_EM_DEV_FM_W(_val, _format, _off, _record)  \
                       (_record) = (((_val) << (_off)) & (_format)) | (~(_format) & (_record))
#define MMI_EM_DEV_FM_R(_format, _off, _record)  ((_format) & (_record)) >> (_off)

typedef struct {
    U8       cmn_cmd_flag; // 0 is input, 1 is ouput
    U8       MonoCurrValue;
    U8       RSSICurrValue;
    U8       req_type;    
    U8       RSSIInfoCurrSignallevel;
    U8       RSSIInfoCurrVolume;
    U8       cmd_param[20];
    U16      rssi_info_freq;
    U16      fmr_is_stop;
} em_dev_fm_radio_struct;

#define MMI_EM_DEV_FMR_CMN_CMD_INPUT   (0)
#define MMI_EM_DEV_FMR_CMN_CMD_OUTPUT  (1)

em_dev_fm_radio_struct *g_fm_radio_cntx= NULL;
#endif /*__MMI_EM_DEV_FM_RADIO__*/


/* Device -> Cam AF */
#if defined(__MMI_EM_CAM_AF_CONTSHOT__)
/* under construction !*/
#if defined(HORIZONTAL_CAMERA)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(SENSOR_ON_BODY)
    #if defined(SENSOR_ROTATE_0)
/* under construction !*/
    #elif defined(SENSOR_ROTATE_180)
/* under construction !*/
    #else
/* under construction !*/
/* under construction !*/
    #endif
#elif defined(SENSOR_ON_COVER)
    #if defined(SENSOR_ROTATE_0)
/* under construction !*/
    #elif defined(SENSOR_ROTATE_180)
/* under construction !*/
    #else
/* under construction !*/
/* under construction !*/
    #endif
#else /* not define SENSOR_LCATION */
    #if defined(SENSOR_ROTATE_0)
/* under construction !*/
    #elif defined(SENSOR_ROTATE_180)
/* under construction !*/
    #else
/* under construction !*/
/* under construction !*/
    #endif              
#endif /* SENSOR_LOCATION */    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 1
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
#endif /* defined(__MMI_EM_CAM_AF_CONTSHOT__) */

#if defined (__MMI_EM_MISC_JUI_DEBUG__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/***************************************************************************** 
 * Static Variable
 *****************************************************************************/

/* Misc -> Video High Bitrate */


/* Misc -> JAVA Heap Size */
#if defined(__MMI_EM_JAVA_HEAP_SIZE_SETTING__)
/* under construction !*/
/* under construction !*/
#endif /* __MMI_EM_JAVA_HEAP_SIZE_SETTING__ */


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/* JUI debug */
#if defined (__MMI_EM_MISC_JUI_DEBUG__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

/* Device -> Cam AF */
#if defined(__MMI_EM_CAM_AF_CONTSHOT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SUBLCD__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_EM_CAM_AF_CONTSHOT__) */


/***************************************************************************** 
 * Local Function
 *****************************************************************************/
#if defined(__MMI_EM_CAM_AF_CONTSHOT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__COSMOS_MMI_PACKAGE__)
/* under construction !*/
#endif
/* under construction !*/
#endif

/* Device -> Mobile TV */
#if defined(__MMI_EM_MOBILE_TV_SETTING__)
void mmi_em_mtv_entry_setting_scr(void);
#endif /* __MMI_EM_MOBILE_TV_SETTING__ */


/* Device -> FM Radio */
#ifdef __MMI_EM_DEV_FM_RADIO__
//static void EmDevFMRadioRSSIInfoInit(void);
static void EntryEmDevFMRadioRSSIInfoMenu(void);
static void EmDevFMRadioRSSIInfoLeftArrowHdlr(void);
static void EmDevFMRadioRSSIInfoRightArrowHdlr(void);
static void EmDevFMRadioRSSIInfoUpArrowHdlr(void);
static void EmDevFMRadioRSSIInfoDownArrowHdlr(void);
static void EMFMRadioRSSIInfoTimeoutHdlr(void);
#endif /*__MMI_EM_DEV_FM_RADIO__*/

#ifdef __MMI_EM_MISC_RECORDER_PARAM_AJUST__
extern void mmi_em_misc_rec_setting_entry_param_ajust_scr(void);
extern void mmi_em_misc_rec_setting_store_data(mmi_event_struct *evt);
#endif /*__MMI_EM_MISC_RECORDER_PARAM_AJUST__*/


/***************************************************************************** 
 * Global Function 
 *****************************************************************************/

/*-----------------------------------------------------------------------------*/
/*------------------------ Misc -> recorder Setting ---------------------------*/
/*-----------------------------------------------------------------------------*/
BOOL is_RGB_source = TRUE;
BOOL is_VT_mode = FALSE;
extern void mdi_video_rec_set_record_yuv(MMI_BOOL is_yuv);
/*****************************************************************************
 * FUNCTION
 *  mmi_em_recorder_setting_source_hint_switch
 * DESCRIPTION
 *  hint recoder setting menu item
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_em_recorder_setting_rec_mode_is_VT(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_EM_MISC_RECORDER_SETTING__)    
/* under construction !*/
#else
    return FALSE;
#endif

}

#if defined(__MMI_EM_MISC_RECORDER_SETTING__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_EM_MISC_RECORDER_PARAM_AJUST__
/* under construction !*/
/* under construction !*/
    #endif /*__MMI_EM_MISC_RECORDER_PARAM_AJUST__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_EM_MISC_RECORDER_PARAM_AJUST__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /*__MMI_EM_MISC_RECORDER_PARAM_AJUST__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                    #ifdef __MED_VCALL_MOD__
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
                    #ifdef __MED_VCALL_MOD__
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
                #ifdef __MMI_EM_MISC_RECORDER_PARAM_AJUST__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif /*__MMI_EM_MISC_RECORDER_PARAM_AJUST__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

#define EM_DEV_MEDIAMEMORY
/*-----------------------------------------------------------------------------*/
/*------------------------ Misc -> Media Memory Setting -----------------------*/
/*-----------------------------------------------------------------------------*/
#if defined(__MMI_EM_MISC_MEDIA_MEMORY_SETTING__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_EM_MISC_MEDIA_MEMORY_SETTING__ */

/*-----------------------------------------------------------------------------*/
/*--------------------------- Device -> Video Setting ------------------------------*/
/*-----------------------------------------------------------------------------*/
#define EM_VIDEO_SETTING

#if defined(__MMI_EM_VIDEO_SETTING__)
#define EM_VIDEO_EDIT_NUM 10
#define EM_VIDEO_EDIT_MAX_DIGIT 11
kal_uint8 g_em_video_setting_format;
kal_uint8 g_em_video_setting_type;
typedef enum
{
    MMI_EM_VIDEO_SETTING_TYPE_COMMON,
    MMI_EM_VIDEO_SETTING_TYPE_CODEC,
    MMI_EM_VIDEO_SETTING_TYPE_MODE
} mmi_em_video_setting_type_enum;

enum
{
    //common, codec setting
    MMI_EM_VIDEO_CUST1_EDITOR = CUI_INLINE_ITEM_ID_BASE+1,
    MMI_EM_VIDEO_CUST2_EDITOR,
    MMI_EM_VIDEO_CUST3_EDITOR,
    MMI_EM_VIDEO_CUST4_EDITOR,
    MMI_EM_VIDEO_CUST5_EDITOR,
    MMI_EM_VIDEO_CUST6_EDITOR,
    MMI_EM_VIDEO_CUST7_EDITOR,
    MMI_EM_VIDEO_CUST8_EDITOR,
    MMI_EM_VIDEO_CUST9_EDITOR,
    MMI_EM_VIDEO_CUST10_EDITOR,
    //mode setting
    MMI_EM_VIDEO_PLAY_MODE_CAPTION,
    MMI_EM_VIDEO_PLAY_MODE_SELECTOR,
    MMI_EM_VIDEO_LAST_MODE_CAPTION,
    MMI_EM_VIDEO_LAST_MODE_DISPLAY_ONLY,
    MMI_EM_VIDEO_FLUENCY_SETTING_CAPTION,
    MMI_EM_VIDEO_FLUENCY_SETTING_SELECTOR
};

static const cui_inline_item_text_edit_struct g_em_video_cust_edit =
{
    0,
    0,
    EM_VIDEO_EDIT_MAX_DIGIT,
    IMM_INPUT_TYPE_NUMERIC,
    IMM_INPUT_TYPE_NUMERIC,
    NULL
};

static const cui_inline_item_caption_struct g_em_video_play_mode_caption =
{
    STR_ID_EM_DEV_VIDEO_SETTING_PLAY_MODE
};

static const U16 g_em_video_play_mode_str[] =
{
    STR_ID_EM_DEV_VIDEO_SETTING_QUALITY,
    STR_ID_EM_DEV_VIDEO_SETTING_BALANCE,
    STR_ID_EM_DEV_VIDEO_SETTING_FLUENCY
};

static const cui_inline_item_select_struct g_em_video_play_mode_selector =
{
    3,
    0,
    g_em_video_play_mode_str
};

static const cui_inline_item_caption_struct g_em_video_last_mode_caption =
{
    STR_ID_EM_DEV_VIDEO_SETTING_LAST_MODE
};

static const cui_inline_item_caption_struct g_em_video_fluency_setting_caption =
{
    STR_ID_EM_DEV_VIDEO_SETTING_FLUENCY_SETTING
};

static const U16 g_em_video_fluency_setting_str[] =
{
    STR_GLOBAL_1,
    STR_GLOBAL_2,
    STR_GLOBAL_3
};

static const cui_inline_item_select_struct g_em_video_fluency_setting_selector =
{
    3,
    0,
    g_em_video_fluency_setting_str
};

static const cui_inline_set_item_struct g_em_video_setting_item[] =
{
    //common, codec setting
    {MMI_EM_VIDEO_CUST1_EDITOR,     CUI_INLINE_ITEM_TYPE_TEXT_EDIT,     IMG_GLOBAL_L1,   (void*)&g_em_video_cust_edit},
    {MMI_EM_VIDEO_CUST2_EDITOR,     CUI_INLINE_ITEM_TYPE_TEXT_EDIT,     IMG_GLOBAL_L2,   (void*)&g_em_video_cust_edit},
    {MMI_EM_VIDEO_CUST3_EDITOR,     CUI_INLINE_ITEM_TYPE_TEXT_EDIT,     IMG_GLOBAL_L3,   (void*)&g_em_video_cust_edit},
    {MMI_EM_VIDEO_CUST4_EDITOR,     CUI_INLINE_ITEM_TYPE_TEXT_EDIT,     IMG_GLOBAL_L4,   (void*)&g_em_video_cust_edit},
    {MMI_EM_VIDEO_CUST5_EDITOR,     CUI_INLINE_ITEM_TYPE_TEXT_EDIT,     IMG_GLOBAL_L5,   (void*)&g_em_video_cust_edit},
    {MMI_EM_VIDEO_CUST6_EDITOR,     CUI_INLINE_ITEM_TYPE_TEXT_EDIT,     IMG_GLOBAL_L6,   (void*)&g_em_video_cust_edit},
    {MMI_EM_VIDEO_CUST7_EDITOR,     CUI_INLINE_ITEM_TYPE_TEXT_EDIT,     IMG_GLOBAL_L7,   (void*)&g_em_video_cust_edit},
    {MMI_EM_VIDEO_CUST8_EDITOR,     CUI_INLINE_ITEM_TYPE_TEXT_EDIT,     IMG_GLOBAL_L8,   (void*)&g_em_video_cust_edit},
    {MMI_EM_VIDEO_CUST9_EDITOR,     CUI_INLINE_ITEM_TYPE_TEXT_EDIT,     IMG_GLOBAL_L9,   (void*)&g_em_video_cust_edit},
    {MMI_EM_VIDEO_CUST10_EDITOR,    CUI_INLINE_ITEM_TYPE_TEXT_EDIT,     IMG_GLOBAL_L10,  (void*)&g_em_video_cust_edit},
    //mode setting
    {MMI_EM_VIDEO_PLAY_MODE_CAPTION,     CUI_INLINE_ITEM_TYPE_CAPTION,  IMG_GLOBAL_L1,   (void*)&g_em_video_play_mode_caption},
    {MMI_EM_VIDEO_PLAY_MODE_SELECTOR,    CUI_INLINE_ITEM_TYPE_SELECT,   0,               (void*)&g_em_video_play_mode_selector},
    {MMI_EM_VIDEO_LAST_MODE_CAPTION,     CUI_INLINE_ITEM_TYPE_CAPTION,  IMG_GLOBAL_L2,   (void*)&g_em_video_last_mode_caption},
    {MMI_EM_VIDEO_LAST_MODE_DISPLAY_ONLY,CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY  | CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW,    0,   NULL},
    {MMI_EM_VIDEO_FLUENCY_SETTING_CAPTION,  CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L3, (void*)&g_em_video_fluency_setting_caption},
    {MMI_EM_VIDEO_FLUENCY_SETTING_SELECTOR, CUI_INLINE_ITEM_TYPE_SELECT,  0,             (void*)&g_em_video_fluency_setting_selector},

};

static const cui_inline_struct g_em_video_setting_inline =
{
    sizeof(g_em_video_setting_item)/sizeof(g_em_video_setting_item[0]),
    STR_ID_EM_DEV_VIDEO_SETTING,
    NULL,
    CUI_INLINE_SCREEN_DEFAULT_TEXT,
    NULL,
    g_em_video_setting_item
};


/*****************************************************************************
 * FUNCTION
 *  mmi_em_video_setting_done
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_video_setting_done(MMI_ID sender_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR ucs2_str[EM_VIDEO_EDIT_MAX_DIGIT];
    CHAR ansi_str[EM_VIDEO_EDIT_MAX_DIGIT];
    S32 value;
    U8 i, setting_value;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_em_video_setting_type == MMI_EM_VIDEO_SETTING_TYPE_COMMON)
    {
        for (i = 0; i < EM_VIDEO_EDIT_NUM; i ++)
        {
            cui_inline_get_value(
                sender_id, MMI_EM_VIDEO_CUST1_EDITOR + i, ucs2_str);
            mmi_ucs2_to_asc(ansi_str, (CHAR*)ucs2_str);
            value = atoi(ansi_str);
            mply_custom_set_cust(g_em_video_setting_format, i, value);

        }
    }
    else if (g_em_video_setting_type == MMI_EM_VIDEO_SETTING_TYPE_CODEC)
    {
        for (i = 0; i < EM_VIDEO_EDIT_NUM; i ++)
        {
            cui_inline_get_value(
                sender_id, MMI_EM_VIDEO_CUST1_EDITOR + i, ucs2_str);
            mmi_ucs2_to_asc(ansi_str, (CHAR*)ucs2_str);
            value = atoi(ansi_str);

            mply_codec_custom_set_cust(g_em_video_setting_format, i, value);
        }
    }
    else if (g_em_video_setting_type == MMI_EM_VIDEO_SETTING_TYPE_MODE)
    {
        /* play mode */
        cui_inline_get_value(
            sender_id, MMI_EM_VIDEO_PLAY_MODE_SELECTOR, &setting_value);
        mply_codec_custom_query(g_em_video_setting_format, MPLY_CODEC_CUSTOM_ITEM_SET_PLAYBACK_MODE, setting_value);

        /* Fluency setting */
        cui_inline_get_value(
            sender_id, MMI_EM_VIDEO_FLUENCY_SETTING_SELECTOR, &setting_value);
        mply_codec_custom_query(g_em_video_setting_format, MPLY_CODEC_CUSTOM_ITEM_SET_FLUENCY_LEVEL, setting_value + 1);
    }

    mmi_popup_display_simple(
        (WCHAR*) GetString(STR_GLOBAL_DONE),
        MMI_EVENT_SUCCESS,
        GRP_ID_EM_DEV_VIDEO_SETTING,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_video_setting_group_proc
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_em_video_setting_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_inline_common_struct *inline_evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        /**********************************************
         *  Inline Selector CUI
         **********************************************/
        case EVT_ID_CUI_INLINE_ABORT:
        {
            inline_evt = (cui_event_inline_common_struct *)evt;
            cui_inline_close(inline_evt->sender_id);
            break;
        }
        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            inline_evt = (cui_event_inline_common_struct *)evt;
            mmi_em_video_setting_done(inline_evt->sender_id);
            cui_inline_close(inline_evt->sender_id);
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_video_setting_config_inline_item
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_video_setting_config_inline_item(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Config inline item */
    if (g_em_video_setting_type == MMI_EM_VIDEO_SETTING_TYPE_COMMON ||
        g_em_video_setting_type == MMI_EM_VIDEO_SETTING_TYPE_CODEC)
    {
        //delete mode setting
        cui_inline_delete_item(cui_id, MMI_EM_VIDEO_PLAY_MODE_CAPTION);
        cui_inline_delete_item(cui_id, MMI_EM_VIDEO_PLAY_MODE_SELECTOR);
        cui_inline_delete_item(cui_id, MMI_EM_VIDEO_LAST_MODE_CAPTION);
        cui_inline_delete_item(cui_id, MMI_EM_VIDEO_LAST_MODE_DISPLAY_ONLY);
        cui_inline_delete_item(cui_id, MMI_EM_VIDEO_FLUENCY_SETTING_CAPTION);
        cui_inline_delete_item(cui_id, MMI_EM_VIDEO_FLUENCY_SETTING_SELECTOR);
    }
    else
    {
        //delete common, codec setting
        cui_inline_delete_item(cui_id, MMI_EM_VIDEO_CUST1_EDITOR);
        cui_inline_delete_item(cui_id, MMI_EM_VIDEO_CUST2_EDITOR);
        cui_inline_delete_item(cui_id, MMI_EM_VIDEO_CUST3_EDITOR);
        cui_inline_delete_item(cui_id, MMI_EM_VIDEO_CUST4_EDITOR);
        cui_inline_delete_item(cui_id, MMI_EM_VIDEO_CUST5_EDITOR);
        cui_inline_delete_item(cui_id, MMI_EM_VIDEO_CUST6_EDITOR);
        cui_inline_delete_item(cui_id, MMI_EM_VIDEO_CUST7_EDITOR);
        cui_inline_delete_item(cui_id, MMI_EM_VIDEO_CUST8_EDITOR);
        cui_inline_delete_item(cui_id, MMI_EM_VIDEO_CUST9_EDITOR);
        cui_inline_delete_item(cui_id, MMI_EM_VIDEO_CUST10_EDITOR);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_video_setting_config_inline_value
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_video_setting_config_inline_value(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR ucs2_str[EM_VIDEO_EDIT_MAX_DIGIT];
    kal_uint64 value;
    kal_int32 i, val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_em_video_setting_type == MMI_EM_VIDEO_SETTING_TYPE_COMMON)
    {
        for (i = 0; i < EM_VIDEO_EDIT_NUM; i ++)
        {
            value = mply_custom_get_cust(g_em_video_setting_format, i);
            kal_wsprintf(ucs2_str, "%d", value);
            cui_inline_set_value(
                cui_id, MMI_EM_VIDEO_CUST1_EDITOR + i, (void *)ucs2_str);
        }
    }
    else if (g_em_video_setting_type == MMI_EM_VIDEO_SETTING_TYPE_CODEC)
    {
        for (i = 0; i < EM_VIDEO_EDIT_NUM; i ++)
        {
            value = mply_codec_custom_get_cust(g_em_video_setting_format, i);
            kal_wsprintf(ucs2_str, "%d", value);
            cui_inline_set_value(
                cui_id, MMI_EM_VIDEO_CUST1_EDITOR + i, (void *)ucs2_str);
        }
    }
    else if (g_em_video_setting_type == MMI_EM_VIDEO_SETTING_TYPE_MODE)
    {
        /* play mode */
        val = mply_codec_custom_query(g_em_video_setting_format, MPLY_CODEC_CUSTOM_ITEM_GET_PLAYBACK_MODE, 0);
        cui_inline_set_value(cui_id,  MMI_EM_VIDEO_PLAY_MODE_SELECTOR, (void*)val);

        /* last mode */
        val = mply_codec_custom_query(g_em_video_setting_format, MPLY_CODEC_CUSTOM_ITEM_GET_PREVIOUS_MODE, 0);
        cui_inline_set_value(cui_id, MMI_EM_VIDEO_LAST_MODE_DISPLAY_ONLY, GetString(STR_GLOBAL_0 + val));

        /* Fluency setting */
        val = mply_codec_custom_query(g_em_video_setting_format, MPLY_CODEC_CUSTOM_ITEM_GET_FLUENCY_LEVEL, 0);
        cui_inline_set_value(cui_id,  MMI_EM_VIDEO_FLUENCY_SETTING_SELECTOR, (void*)(val - 1));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_video_entry_setting_screen
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_video_entry_setting_screen(U8 type_idx, U8 format_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_group_create(
        mmi_em_get_root_group(),
        GRP_ID_EM_DEV_VIDEO_SETTING,
        mmi_em_video_setting_group_proc,
        NULL);
    cui_id = mmi_frm_group_enter(
        GRP_ID_EM_DEV_VIDEO_SETTING,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_id = cui_inline_create(
                GRP_ID_EM_DEV_VIDEO_SETTING,
                &g_em_video_setting_inline);

    /* Init parameter */
    g_em_video_setting_format = format_idx;
    g_em_video_setting_type = type_idx;

    // config inline item
    mmi_em_video_setting_config_inline_item(cui_id);

    // config inline value
    mmi_em_video_setting_config_inline_value(cui_id);

    cui_inline_run(cui_id);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_video_setting_select_handler
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_video_setting_select_handler(mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(menu_id)
    {
        /* Common settig */
        case EM_DEV_VIDEO_SETTING_MP4_MENUID:
            mmi_em_video_entry_setting_screen(
                MMI_EM_VIDEO_SETTING_TYPE_COMMON, MPLY_CODEC_CUSTOM_FORMAT_MP4);
            break;
        case EM_DEV_VIDEO_SETTING_H264_MENUID:
            mmi_em_video_entry_setting_screen(
                MMI_EM_VIDEO_SETTING_TYPE_COMMON, MPLY_CODEC_CUSTOM_FORMAT_H264);
            break;
        case EM_DEV_VIDEO_SETTING_RM_MENUID:
            mmi_em_video_entry_setting_screen(
                MMI_EM_VIDEO_SETTING_TYPE_COMMON, MPLY_CODEC_CUSTOM_FORMAT_RM);
            break;
        case EM_DEV_VIDEO_SETTING_VP8_MENUID:
            mmi_em_video_entry_setting_screen(
                MMI_EM_VIDEO_SETTING_TYPE_COMMON, MPLY_CODEC_CUSTOM_FORMAT_VP8);
            break;    

        /* Codec settig */
        case EM_DEV_VIDEO_SETTING_CODEC_MP4_MENUID:
            mmi_em_video_entry_setting_screen(
                MMI_EM_VIDEO_SETTING_TYPE_CODEC, MPLY_CODEC_CUSTOM_FORMAT_MP4);
            break;
        case EM_DEV_VIDEO_SETTING_CODEC_H264_MENUID:
            mmi_em_video_entry_setting_screen(
                MMI_EM_VIDEO_SETTING_TYPE_CODEC, MPLY_CODEC_CUSTOM_FORMAT_H264);
            break;

        case EM_DEV_VIDEO_SETTING_CODEC_RM_MENUID:
            mmi_em_video_entry_setting_screen(
                MMI_EM_VIDEO_SETTING_TYPE_CODEC, MPLY_CODEC_CUSTOM_FORMAT_RM);
            break;
        case EM_DEV_VIDEO_SETTING_CODEC_VP8_MENUID:
            mmi_em_video_entry_setting_screen(
                MMI_EM_VIDEO_SETTING_TYPE_CODEC, MPLY_CODEC_CUSTOM_FORMAT_VP8);
            break;    

        /* Mode settig */
        case EM_DEV_VIDEO_SETTING_MODE_MP4_MENUID:
            mmi_em_video_entry_setting_screen(
                MMI_EM_VIDEO_SETTING_TYPE_MODE, MPLY_CODEC_CUSTOM_FORMAT_MP4);
            break;
        case EM_DEV_VIDEO_SETTING_MODE_H264_MENUID:
            mmi_em_video_entry_setting_screen(
                MMI_EM_VIDEO_SETTING_TYPE_MODE, MPLY_CODEC_CUSTOM_FORMAT_H264);
            break;

        case EM_DEV_VIDEO_SETTING_MODE_RM_MENUID:
            mmi_em_video_entry_setting_screen(
                MMI_EM_VIDEO_SETTING_TYPE_MODE, MPLY_CODEC_CUSTOM_FORMAT_RM);
            
            break;
        case EM_DEV_VIDEO_SETTING_MODE_VP8_MENUID:
            mmi_em_video_entry_setting_screen(
                MMI_EM_VIDEO_SETTING_TYPE_MODE, MPLY_CODEC_CUSTOM_FORMAT_VP8);    
            break;

    }
}

#endif /* __MMI_EM_VIDEO_SETTING__ */


#ifdef __MMI_EM_VIDEO_STREAMING_SETTING__

#include "mdi_video.h"

#define STREAMING_EM_TIME_DIGIT_LEN  5

typedef enum
{
    MMI_EM_VIDEO_STREAMING_SET_USER_AGENT_CAPTION = CUI_INLINE_ITEM_ID_BASE+1,
    MMI_EM_VIDEO_STREAMING_SET_USER_AGENT_SELECTOR,
    MMI_EM_VIDEO_STREAMING_SET_TRANSPORT_CAPTION,
    MMI_EM_VIDEO_STREAMING_SET_TRANSPORT_SELECTOR,
    MMI_EM_VIDEO_STREAMING_SET_PREBUFFER_TIME_CAPTION,
    MMI_EM_VIDEO_STREAMING_SET_PREBUFFER_TIME_EDITOR
};

static const cui_inline_item_caption_struct g_em_video_streaming_ua_caption =
{
    STR_ID_EM_DEV_VIDEO_STREAMING_UA
};

static const U16 g_em_video_streaming_ua_str[] =
{
    STR_ID_EM_DEV_VIDEO_STREAMING_UA_MTK,
    STR_ID_EM_DEV_VIDEO_STREAMING_UA_RM
};

static const cui_inline_item_select_struct g_em_video_streaming_ua_selector =
{
    sizeof(g_em_video_streaming_ua_str)/sizeof(g_em_video_streaming_ua_str[0]),
    0,
    g_em_video_streaming_ua_str
};

static const cui_inline_item_caption_struct g_em_video_streaming_transport_caption =
{
    STR_ID_EM_DEV_VIDEO_STREAMING_TRANSPORT
};

static const U16 g_em_video_streaming_transport_str[] =
{
    STR_ID_EM_DEV_VIDEO_STREAMING_TRANSPORT_UDP,
    STR_ID_EM_DEV_VIDEO_STREAMING_TRANSPORT_TCP
};

static const cui_inline_item_select_struct g_em_video_streaming_transport_selector =
{
    sizeof(g_em_video_streaming_transport_str)/sizeof(g_em_video_streaming_transport_str[0]),
    0,
    g_em_video_streaming_transport_str
};

static const cui_inline_item_caption_struct g_em_video_streaming_set_prebuffer_time_caption =
{
    STR_ID_EM_DEV_VIDEO_STREAMING_SETTING_PREBUFFER_TIME
};
static const cui_inline_item_text_edit_struct g_em_video_streaming_set_prebuffer_time_edit =
{
    0,
    0,
    STREAMING_EM_TIME_DIGIT_LEN,
    IMM_INPUT_TYPE_NUMERIC,
    IMM_INPUT_TYPE_NUMERIC,
    NULL
};

static const cui_inline_set_item_struct g_em_video_streaming_setting_item[] =
{
    {MMI_EM_VIDEO_STREAMING_SET_USER_AGENT_CAPTION,     CUI_INLINE_ITEM_TYPE_CAPTION,   IMG_GLOBAL_L1, (void*)&g_em_video_streaming_ua_caption},
    {MMI_EM_VIDEO_STREAMING_SET_USER_AGENT_SELECTOR,    CUI_INLINE_ITEM_TYPE_SELECT,    0,             (void*)&g_em_video_streaming_ua_selector},
    {MMI_EM_VIDEO_STREAMING_SET_TRANSPORT_CAPTION,      CUI_INLINE_ITEM_TYPE_CAPTION,   IMG_GLOBAL_L2, (void*)&g_em_video_streaming_transport_caption},
    {MMI_EM_VIDEO_STREAMING_SET_TRANSPORT_SELECTOR,     CUI_INLINE_ITEM_TYPE_SELECT,    0,             (void*)&g_em_video_streaming_transport_selector},
    {MMI_EM_VIDEO_STREAMING_SET_PREBUFFER_TIME_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION,   IMG_GLOBAL_L3, (void*)&g_em_video_streaming_set_prebuffer_time_caption},
    {MMI_EM_VIDEO_STREAMING_SET_PREBUFFER_TIME_EDITOR,  CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0,             (void*)&g_em_video_streaming_set_prebuffer_time_edit}

};

static const cui_inline_struct g_em_video_streaming_setting_inline =
{
    sizeof(g_em_video_streaming_setting_item)/sizeof(g_em_video_streaming_setting_item[0]),
    STR_ID_EM_DEV_VIDEO_STREAMING_SETTING,
    NULL,
    CUI_INLINE_SCREEN_DEFAULT_TEXT,
    NULL,
    g_em_video_streaming_setting_item
};

static kal_uint8 g_streaming_ua_idx = 0;
static kal_uint32 g_streaming_prebuffer_time = 5000;
static const CHAR g_streaming_ua_str_mtk[] = "MTKStreamClient/1.0(EM)";
static const CHAR g_streaming_ua_str_rm[] = "RealMedia Player(EM)";

static void mmi_em_video_streaming_setting_done(MMI_ID sender_id)
{
    U8 sel_idx;
    WCHAR ucs2_str[STREAMING_EM_TIME_DIGIT_LEN];
    CHAR ansi_str[STREAMING_EM_TIME_DIGIT_LEN];

    cui_inline_get_value(sender_id, MMI_EM_VIDEO_STREAMING_SET_USER_AGENT_SELECTOR, &sel_idx);
    //if (g_streaming_ua_idx != sel_idx)
    {
        g_streaming_ua_idx = sel_idx;
        if (sel_idx == 1)
        {
            mdi_video_stream_set_user_agent_str(g_streaming_ua_str_rm);
        }
        else
        {
            mdi_video_stream_set_user_agent_str(g_streaming_ua_str_mtk);
        }
    }

    cui_inline_get_value(sender_id, MMI_EM_VIDEO_STREAMING_SET_TRANSPORT_SELECTOR, &sel_idx);
    //if (g_streaming_transport_idx != sel_idx)
    {
        if (sel_idx == 1)
        {
            mdi_video_stream_set_prefer_transport(MDI_VIDEO_STREAM_TRANSPORT_TCP);
        }
        else
        {
            mdi_video_stream_set_prefer_transport(MDI_VIDEO_STREAM_TRANSPORT_UDP);
        }
    }

    cui_inline_get_value(sender_id, MMI_EM_VIDEO_STREAMING_SET_PREBUFFER_TIME_EDITOR, ucs2_str);
    mmi_ucs2_to_asc(ansi_str, (CHAR*)ucs2_str);
    g_streaming_prebuffer_time = atoi(ansi_str);
    mdi_video_stream_set_prebuffer_time(g_streaming_prebuffer_time);

    mmi_popup_display_simple(
        (WCHAR*) GetString(STR_GLOBAL_DONE),
        MMI_EVENT_SUCCESS,
        GRP_ID_EM_DEV_VIDEO_STREAMING_SETTING,
        NULL);
}

static mmi_ret mmi_em_video_streaming_group_proc(mmi_event_struct *evt)
{
    cui_event_inline_common_struct *inline_evt;

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_ABORT:
        {
            inline_evt = (cui_event_inline_common_struct *)evt;
            cui_inline_close(inline_evt->sender_id);
            break;
        }
        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            inline_evt = (cui_event_inline_common_struct *)evt;
            mmi_em_video_streaming_setting_done(inline_evt->sender_id);
            cui_inline_close(inline_evt->sender_id);
            break;
        }
    }
    return MMI_RET_OK;
}

void mmi_em_video_streaming_entry_setting_scr(void)
{
    mmi_id cui_id;
    U8 sel_idx;
    WCHAR ucs2_str[STREAMING_EM_TIME_DIGIT_LEN];
    mdi_video_stream_transport_type_enum type;

    mmi_frm_group_create(
        mmi_em_get_root_group(),
        GRP_ID_EM_DEV_VIDEO_STREAMING_SETTING,
        mmi_em_video_streaming_group_proc,
        NULL);
    mmi_frm_group_enter(
        GRP_ID_EM_DEV_VIDEO_STREAMING_SETTING,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_id = cui_inline_create(
                GRP_ID_EM_DEV_VIDEO_STREAMING_SETTING,
                &g_em_video_streaming_setting_inline);

    /* Init parameter */
    sel_idx = g_streaming_ua_idx;
    cui_inline_set_value(cui_id, MMI_EM_VIDEO_STREAMING_SET_USER_AGENT_SELECTOR, (void*)sel_idx);

    mdi_video_stream_get_prefer_transport(&type);
    sel_idx = (U8)type;
    cui_inline_set_value(cui_id, MMI_EM_VIDEO_STREAMING_SET_TRANSPORT_SELECTOR, (void*)sel_idx);

    kal_wsprintf(ucs2_str, "%d", g_streaming_prebuffer_time);
    cui_inline_set_value(cui_id, MMI_EM_VIDEO_STREAMING_SET_PREBUFFER_TIME_EDITOR, (void *)ucs2_str);

    cui_inline_run(cui_id);
}

#endif  //#ifdef __MMI_EM_VIDEO_STREAMING_SETTING__


#define EM_MOBILE_TV_SETTING
/*-----------------------------------------------------------------------------*/
/*--------------------------- Device ->Mobile TV ------------------------------*/
/*-----------------------------------------------------------------------------*/
#ifdef __MMI_EM_MOBILE_TV_SETTING__

#define MTV_EM_DIGIT_LEN 5
#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
#define MTV_EM_MTS_DIGIT (123)
extern kal_bool g_mtv_dump_service;
extern kal_bool g_mtv_show_demod_status;
extern kal_bool g_mtv_dump_esg_xml_file;
extern kal_uint32 g_mtv_demod_sim;
kal_uint32 g_em_mtv_mts_digit;
#endif /* defined(__MMI_MOBILE_TV_CMMB_SUPPORT__) */
#if defined(__MMI_ATV_SUPPORT__)
#define MTV_EM_CLI_DIGIT (123)
extern kal_bool mATV_CLI_enable;
kal_uint32 g_em_mtv_cli_digit;
#endif /* __MMI_ATV_SUPPORT__ */

enum
{
    MMI_EM_MTV_SET_MTS_CAPTION = CUI_INLINE_ITEM_ID_BASE+1,
    MMI_EM_MTV_SET_MTS_EDITOR,
    MMI_EM_MTV_DEMOD_SIM_CAPTION,
    MMI_EM_MTV_DEMOD_SIM_SELECTOR,
    MMI_EM_MTV_DUMP_CHANNEL_CAPTION,
    MMI_EM_MTV_DUMP_CHANNEL_SELECTOR,   
    MMI_EM_MTV_SAVE_ESG_CAPTION,
    MMI_EM_MTV_SAVE_ESG_SELECTOR, 
    MMI_EM_MTV_DEMOD_STATUS_CAPTION,
    MMI_EM_MTV_DEMOD_STATUS_SELECTOR,
    MMI_EM_MTV_SET_CLI_CAPTION,
    MMI_EM_MTV_SET_CLI_EDITOR
};

#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
/* Inline caption */
static const cui_inline_item_caption_struct g_em_mtv_set_mts_caption = 
{
    STR_ID_EM_DEV_MTV_SETTING_SET_MTS
};
static const cui_inline_item_caption_struct g_em_mtv_demod_sim_caption = 
{
    STR_ID_EM_DEV_MTV_SETTING_DEMOD_SIM
};
static const cui_inline_item_caption_struct g_em_mtv_dump_channel_caption = 
{
    STR_ID_EM_DEV_MTV_SETTING_DUMP_CHANNEL
};
static const cui_inline_item_caption_struct g_em_mtv_save_esg_caption = 
{
    STR_ID_EM_DEV_MTV_SETTING_SAVE_ESG
};
static const cui_inline_item_caption_struct g_em_mtv_demod_status_caption =
{
	STR_ID_EM_DEV_MTV_SETTING_SHOW_DEMOD_STATUS
};
static const U16 g_em_mtv_demod_sim_str[] = 
{
    STR_GLOBAL_OFF, 
    STR_ID_EM_DEV_MTV_SETTING_MFS
};
static const U16 g_em_mtv_dump_channel_str[] = 
{
    STR_GLOBAL_OFF, 
    STR_GLOBAL_ON
};
static const U16 g_em_mtv_save_esg_str[] = 
{
    STR_GLOBAL_OFF, 
    STR_GLOBAL_ON
};
static const U16 g_em_mtv_demod_status_str[] = 
{
	STR_GLOBAL_OFF, 
    STR_GLOBAL_ON
};
	
static const cui_inline_item_text_edit_struct g_em_mtv_set_mts_edit =
{
    0,  
    0,  
    MTV_EM_DIGIT_LEN,  
    IMM_INPUT_TYPE_NUMERIC,
    IMM_INPUT_TYPE_NUMERIC, 
    NULL 
};

static const cui_inline_item_select_struct g_em_mtv_demod_sim_selector = 
{
    sizeof(g_em_mtv_demod_sim_str)/sizeof(g_em_mtv_demod_sim_str[0]),
    0,
    g_em_mtv_demod_sim_str
}; 
static const cui_inline_item_select_struct g_em_mtv_dump_channel_selector = 
{
    sizeof(g_em_mtv_dump_channel_str)/sizeof(g_em_mtv_dump_channel_str[0]),
    0,
    g_em_mtv_dump_channel_str
};
static const cui_inline_item_select_struct g_em_mtv_save_esg_selector = 
{
    sizeof(g_em_mtv_save_esg_str)/sizeof(g_em_mtv_save_esg_str[0]),
    0,
    g_em_mtv_save_esg_str
};
static const cui_inline_item_select_struct g_em_mtv_demod_status_selector =
{
	sizeof(g_em_mtv_demod_status_str)/sizeof(g_em_mtv_demod_status_str[0]),
	0,
	g_em_mtv_demod_status_str
};

#endif /* __MMI_MOBILE_TV_CMMB_SUPPORT__ */
#if defined(__MMI_ATV_SUPPORT__)
static const cui_inline_item_caption_struct g_em_mtv_set_cli_caption = 
{
    STR_ID_EM_DEV_MTV_SETTING_CLI
};
static const cui_inline_item_text_edit_struct g_em_mtv_set_cli_edit =
{
    0,  
    0,  
    MTV_EM_DIGIT_LEN,  
    IMM_INPUT_TYPE_NUMERIC,
    IMM_INPUT_TYPE_NUMERIC, 
    NULL 
};

#endif /* __MMI_ATV_SUPPORT__ */


static const cui_inline_set_item_struct g_em_mtv_setting_item[] = 
{
#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)    
    {MMI_EM_MTV_SET_MTS_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION,       IMG_GLOBAL_L1, (void*)&g_em_mtv_set_mts_caption},
    {MMI_EM_MTV_SET_MTS_EDITOR,         CUI_INLINE_ITEM_TYPE_TEXT_EDIT,     0,             (void*)&g_em_mtv_set_mts_edit},
    {MMI_EM_MTV_DEMOD_SIM_CAPTION,      CUI_INLINE_ITEM_TYPE_CAPTION,       IMG_GLOBAL_L2, (void*)&g_em_mtv_demod_sim_caption},
    {MMI_EM_MTV_DEMOD_SIM_SELECTOR,     CUI_INLINE_ITEM_TYPE_SELECT,        0,             (void*)&g_em_mtv_demod_sim_selector},
    {MMI_EM_MTV_DUMP_CHANNEL_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION,       IMG_GLOBAL_L3, (void*)&g_em_mtv_dump_channel_caption},
    {MMI_EM_MTV_DUMP_CHANNEL_SELECTOR,  CUI_INLINE_ITEM_TYPE_SELECT,        0,             (void*)&g_em_mtv_dump_channel_selector},
    {MMI_EM_MTV_SAVE_ESG_CAPTION,       CUI_INLINE_ITEM_TYPE_CAPTION,       IMG_GLOBAL_L4, (void*)&g_em_mtv_save_esg_caption},
    {MMI_EM_MTV_SAVE_ESG_SELECTOR,      CUI_INLINE_ITEM_TYPE_SELECT,        0,             (void*)&g_em_mtv_save_esg_selector},
    {MMI_EM_MTV_DEMOD_STATUS_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION,       IMG_GLOBAL_L5, (void*)&g_em_mtv_demod_status_caption},
    {MMI_EM_MTV_DEMOD_STATUS_SELECTOR,  CUI_INLINE_ITEM_TYPE_SELECT,        0,             (void*)&g_em_mtv_demod_status_selector}
#endif
#if defined(__MMI_ATV_SUPPORT__)
    {MMI_EM_MTV_SET_CLI_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION,       IMG_GLOBAL_L1, (void*)&g_em_mtv_set_cli_caption},
    {MMI_EM_MTV_SET_CLI_EDITOR,         CUI_INLINE_ITEM_TYPE_TEXT_EDIT,     0,             (void*)&g_em_mtv_set_cli_edit}
#endif
};

static const cui_inline_struct g_em_mtv_setting_inline = 
{
    sizeof(g_em_mtv_setting_item)/sizeof(g_em_mtv_setting_item[0]),
    STR_ID_EM_DEV_MTV_SETTING,
    NULL,
    CUI_INLINE_SCREEN_DEFAULT_TEXT,
    NULL,
    g_em_mtv_setting_item
};

static void mmi_em_mtv_setting_done(MMI_ID sender_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR ucs2_str[MTV_EM_DIGIT_LEN];
    CHAR ansi_str[MTV_EM_DIGIT_LEN];
#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    U8 sel_idx;
#endif /*__MMI_MOBILE_TV_CMMB_SUPPORT__*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    cui_inline_get_value(sender_id, MMI_EM_MTV_SET_MTS_EDITOR, ucs2_str);    
    mmi_ucs2_to_asc(ansi_str, (CHAR*)ucs2_str);
    g_em_mtv_mts_digit = atoi(ansi_str);
    if (g_em_mtv_mts_digit == MTV_EM_MTS_DIGIT)
    {
        mmi_dtv_player_set_mts_display(MMI_TRUE);
    }
    else
    {
        mmi_dtv_player_set_mts_display(MMI_FALSE);
    }
            
    cui_inline_get_value(sender_id, MMI_EM_MTV_DEMOD_SIM_SELECTOR, &sel_idx);
    g_mtv_demod_sim = sel_idx;
    
    cui_inline_get_value(sender_id, MMI_EM_MTV_DUMP_CHANNEL_SELECTOR, &sel_idx);
    g_mtv_dump_service = sel_idx;
    
    cui_inline_get_value(sender_id, MMI_EM_MTV_SAVE_ESG_SELECTOR, &sel_idx);
    g_mtv_dump_esg_xml_file = sel_idx;
	
    cui_inline_get_value(sender_id, MMI_EM_MTV_DEMOD_STATUS_SELECTOR, &sel_idx);
    g_mtv_show_demod_status = sel_idx;
#endif /* __MMI_MOBILE_TV_CMMB_SUPPORT__ */

#if defined(__MMI_ATV_SUPPORT__)
    
    cui_inline_get_value(sender_id, MMI_EM_MTV_SET_CLI_EDITOR, ucs2_str);    
    mmi_ucs2_to_asc(ansi_str, (CHAR*)ucs2_str);
    g_em_mtv_cli_digit = atoi(ansi_str);
    mATV_CLI_enable = (g_em_mtv_cli_digit == MTV_EM_CLI_DIGIT) ? KAL_TRUE : KAL_FALSE;
#endif  /* __MMI_ATV_SUPPORT__ */ 

    mmi_popup_display_simple(
        (WCHAR*) GetString(STR_GLOBAL_DONE),
        MMI_EVENT_SUCCESS,
        GRP_ID_EM_DEV_MTV_SETTING,
        NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_auto_play_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_em_mtv_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_inline_common_struct *inline_evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {        
        /**********************************************
         *  Inline Selector CUI 
         **********************************************/
        case EVT_ID_CUI_INLINE_ABORT:
        {
            inline_evt = (cui_event_inline_common_struct *)evt;
            cui_inline_close(inline_evt->sender_id);
            break;
        }
        case EVT_ID_CUI_INLINE_SUBMIT:
        { 
            inline_evt = (cui_event_inline_common_struct *)evt;
            mmi_em_mtv_setting_done(inline_evt->sender_id);
            cui_inline_close(inline_evt->sender_id);
            break;
        }
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_mtv_entry_setting_scr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_mtv_entry_setting_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cui_id;
#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    U8 sel_idx;
#endif /*__MMI_MOBILE_TV_CMMB_SUPPORT__*/
    WCHAR ucs2_str[MTV_EM_DIGIT_LEN];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(
        mmi_em_get_root_group(), 
        GRP_ID_EM_DEV_MTV_SETTING, 
        mmi_em_mtv_group_proc, 
        NULL);
    mmi_frm_group_enter(
        GRP_ID_EM_DEV_MTV_SETTING, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_id = cui_inline_create(
                GRP_ID_EM_DEV_MTV_SETTING, 
                &g_em_mtv_setting_inline);    

    /* Init parameter */
#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    kal_wsprintf(ucs2_str, "%d", g_em_mtv_mts_digit);
    cui_inline_set_value(cui_id, MMI_EM_MTV_SET_MTS_EDITOR, (void *)ucs2_str);      

    sel_idx = g_mtv_demod_sim;
    cui_inline_set_value(cui_id, MMI_EM_MTV_DEMOD_SIM_SELECTOR, (void*)sel_idx);

    sel_idx = g_mtv_dump_service;
    cui_inline_set_value(cui_id, MMI_EM_MTV_DUMP_CHANNEL_SELECTOR, (void*)sel_idx);

    sel_idx = g_mtv_dump_esg_xml_file;
    cui_inline_set_value(cui_id, MMI_EM_MTV_SAVE_ESG_SELECTOR, (void*)sel_idx);

	sel_idx = g_mtv_show_demod_status;
	cui_inline_set_value(cui_id, MMI_EM_MTV_DEMOD_STATUS_SELECTOR, (void*)sel_idx);
#endif /* __MMI_MOBILE_TV_CMMB_SUPPORT__ */

#if defined(__MMI_ATV_SUPPORT__)
    kal_wsprintf(ucs2_str, "%d", g_em_mtv_cli_digit);
    cui_inline_set_value(cui_id, MMI_EM_MTV_SET_CLI_EDITOR, (void *)ucs2_str); 
#endif /* __MMI_ATV_SUPPORT__ */ 

    cui_inline_run(cui_id);
}
#endif /* __MMI_EM_MOBILE_TV_SETTING__ */


#define MMI_EM_DEV_FM_RADIO
/*-----------------------------------------------------------------------------*/
/* ---------------------------  Device -> FM radio --------------------------- */
/*-----------------------------------------------------------------------------*/
#ifdef __MMI_EM_DEV_FM_RADIO__

#ifdef __MMI_FM_RADIO_BING_EARPHONE__
#include "gpiosrvgprot.h"
#endif /* __MMI_FM_RADIO_BING_EARPHONE__ */
#include "fmr_common_api.h"
#include "fmr_rds_api.h"
#include "fmr_config_customize.h"
//#if 0
typedef enum
{
    MMI_EM_DEV_FMR_INLINE_ITEM1 = CUI_INLINE_ITEM_ID_BASE,
    MMI_EM_DEV_FMR_INLINE_ITEM2,
    MMI_EM_DEV_FMR_INLINE_ITEM3,
    MMI_EM_DEV_FMR_INLINE_ITEM4,
    MMI_EM_DEV_FMR_INLINE_ITEM5,
    MMI_EM_DEV_FMR_INLINE_ITEM6
} mmi_em_dev_fmr_inline_item_enum;


typedef struct
{
    WCHAR* sound_track;
    WCHAR* ant_type;
    U32    rds_bler;
    WCHAR  capArray[10];
} mmi_em_dev_fmr_status_struct;

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
#endif

// HEX string convert to dex number
static MMI_BOOL mmi_em_dev_fmr_ctohex(CHAR *str, U32 str_len, U32 *hex)
{
    MMI_BOOL result = MMI_TRUE;
    U32 i = 0;


    if (NULL == str || NULL == hex || str_len <= 0)
        return MMI_FALSE;

    *hex = 0;

    while (i < str_len)
    {
        // Hex value is '0~9a~f', so character belong to these character, input value is wrong
        if (*(str + i) <= 'f' && *(str + i) >= 'a')
        {
            *hex = (*(str + i) - 'a' + 10) +  *hex * 16;
        }
        else if (*(str + i) <= '9' && *(str + i) >= '0')
        {
            *hex = (*(str + i) - '0') +  *hex * 16;
        }
        else
        {
            return MMI_FALSE;
        }
                   
        i++;
    }
        
    
    return result;
}

static MMI_BOOL mmi_em_dev_fmr_ctohex_u8(CHAR *str, U32 str_len, U8 *hex)
{
    MMI_BOOL result = MMI_TRUE;
    U32 i = 0;


    if (NULL == str || NULL == hex || str_len <= 0)
        return MMI_FALSE;

    *hex = 0;

    while (i < str_len)
    {
        // Hex value is '0~9a~f', so character belong to these character, input value is wrong
        if (*(str + i) <= 'f' && *(str + i) >= 'a')
        {
            *hex = (*(str + i) - 'a' + 10) +  *hex * 16;
        }
        else if (*(str + i) <= '9' && *(str + i) >= '0')
        {
            *hex = (*(str + i) - '0') +  *hex * 16;
        }
        else
        {
            return MMI_FALSE;
        }
                   
        i++;
    }
        
    return result;
}

MMI_EM_INIT_ASM(dev_fmr, g_fm_radio_cntx, sizeof(em_dev_fm_radio_struct))


void mmi_em_dev_fmr_enter(void)
{
    //if (NULL == g_fm_radio_cntx)
    MMI_EM_ASM_INIT_FUNC(dev_fmr);
}

void mmi_em_dev_fmr_exit(void)
{
    MMI_EM_ASM_FREE_FUNC(dev_fmr);
    MMI_EM_UNREG_STOP_FUNC(MMI_EM_ASM_STOP_FUNC(dev_fmr));
}

void mmi_em_dev_fmr_stop(void)
{
    /* set flag about fm radio power off */
    if (NULL != g_fm_radio_cntx)
    {
        if (!g_fm_radio_cntx->fmr_is_stop)
        {
            StopTimer(EM_RINGTONE_HIGHLIGHT_TIMER);
            mdi_audio_stop_fmr();
            g_fm_radio_cntx->fmr_is_stop = MMI_TRUE;
            FMR_RDS_Disable();
        }
    }
}
#ifndef __MMI_SLIM_ENGINEER_MODE__
static U16 g_mmi_em_dev_fmr_sound_track[] = {
              STR_ID_EM_DEVICE_FM_RADIO_MONO,
              STR_ID_EM_DEVICE_FM_RADIO_STEREO};
              
static U16 g_mmi_em_dev_fmr_ant_type[] = {
              STR_ID_EM_DEV_FMR_ANT_LONG,
              STR_ID_EM_DEV_FMR_ANT_SHORT};
#endif /* __MMI_SLIM_ENGINEER_MODE__ */
/***********************************************
 ** Device->FMR->Radio Freq set scrn
 ***********************************************/
static void mmi_em_dev_fmr_set_fre_scrn(void);

static MMI_RET mmi_em_dev_fmr_fre_scrn_proc(mmi_event_struct *evt);

/***********************************************
 ** Device->FMR->Radio status scrn
 ***********************************************/
static void mmi_em_dev_fmr_enter_status_scrn(U16 fre);
#ifndef __MMI_SLIM_ENGINEER_MODE__
static void mmi_em_dev_fmr_get_status(mmi_em_dev_fmr_status_struct *fmr_status);
#endif /* __MMI_SLIM_ENGINEER_MODE__ */
static S32 mmi_em_dev_fmr_get_edit_value(mmi_id scrn_id, U16 item_id);

static void mmi_em_dev_fmr_set_edit_value(mmi_id scrn_id, U16 item_id, S32 value);
#ifndef __MMI_SLIM_ENGINEER_MODE__
/***********************************************
 ** Device->FMR->Radio status edit screen
 ***********************************************/
static void mmi_em_dev_fmr_enter_status_edit_scrn(void);

static MMI_RET mmi_em_dev_fmr_status_edit_scrn_proc(mmi_event_struct *evt);

static void mmi_em_dev_fmr_status_edit_scrn_init(mmi_id scrn_id);

static void mmi_em_dev_fmr_set_status(mmi_id scrn_id);

/***********************************************
 ** Device->FMR->Radio ant screen
 ***********************************************/
static void mmi_em_dev_fmr_enter_ant_edit_scrn(void);

static MMI_RET mmi_em_dev_fmr_ant_edit_scrn_proc(mmi_event_struct *evt);

static void mmi_em_dev_fmr_set_ant(S32 ant_long, S32 ant_short);

static void mmi_em_dev_fmr_get_ant(S32* ant_long, S32* ant_short);

static void mmi_em_dev_fmr_init_ant(mmi_id scrn_id);

static void mmi_em_dev_fmr_ant_hex_to_db(mmi_id scrn_id, U32 hex, U16 item_id);

static void mmi_em_dev_fmr_ant_db_to_hex(mmi_id scrn_id, S32 db, U16 item_id);
#endif /* __MMI_SLIM_ENGINEER_MODE__ */
static S32 mmi_em_dev_fmr_get_edit_value(mmi_id scrn_id, U16 item_id)
{
    S32 i;
    U32 str_len = 0;
    WCHAR edit_buf[6] = {0};
    

    cui_inline_get_value(scrn_id, item_id, (void *)edit_buf);
    
    str_len = mmi_wcslen(edit_buf);
    
    for (i = str_len; i >= 0; i--)
    {
        if ('.' == edit_buf[i])
            return -1;
    }
    
    return mmi_wcs_wtoi(edit_buf);
}


// edit_buf is NULL, this feature is used to edit text item
// edit_buf is No-NULL, this feature is used to display only text
static void mmi_em_dev_fmr_set_edit_value(mmi_id scrn_id, U16 item_id, S32 value)
{
    WCHAR buffer[6] = {0};
    

    mmi_em_itoa(value, 16, buffer);
    cui_inline_set_value(scrn_id, item_id, (void *)buffer);
}

/***********************************************
 ** Inline cui: Device->FMR->Radio Freq set scrn
 ***********************************************/
static const cui_inline_item_caption_struct g_mmi_em_dev_fmr_cap_fre = 
{
    STR_ID_EM_DEV_FMR_FRE_MHZ,
};

static const cui_inline_item_text_edit_struct g_mmi_em_dev_fmr_edit_fre = 
{
    0,
    0,
    6,
    IMM_INPUT_TYPE_DECIMAL_NUMERIC,
    0,
};

static const cui_inline_set_item_struct g_mmi_em_dev_fmr_fre_inline[] = 
{
    {MMI_EM_DEV_FMR_INLINE_ITEM1, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_dev_fmr_cap_fre},
    {MMI_EM_DEV_FMR_INLINE_ITEM2, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&g_mmi_em_dev_fmr_edit_fre},
};

static const cui_inline_item_softkey_struct g_mmi_em_dev_fmr_fre_sofkey =
{
    {{STR_GLOBAL_OK, 0},
     {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
     {0, IMG_GLOBAL_COMMON_CSK}}        
};

static const cui_inline_struct g_mmi_em_dev_fmr_fre_inline_screen = 
{
    sizeof(g_mmi_em_dev_fmr_fre_inline)/sizeof(cui_inline_set_item_struct),
    STR_ID_EM_DEVICE_FM_RADIO_STATUS,
    0,
    CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    (const cui_inline_set_item_struct*)&g_mmi_em_dev_fmr_fre_inline
};

static void mmi_em_dev_fmr_set_fre_scrn(void)
{
    MMI_ID gid;
    MMI_ID inline_id;


    /* before creating fre set screen, fm radio should be stop */
    mmi_em_dev_fmr_stop();
    
    gid = mmi_frm_group_create_ex(mmi_em_get_root_group(),
              GRP_ID_AUTO_GEN, 
              mmi_em_dev_fmr_fre_scrn_proc, NULL,
              MMI_FRM_NODE_SMART_CLOSE_FLAG);

    /* set flag about fm radio power on */
    g_fm_radio_cntx->fmr_is_stop = MMI_TRUE; 
    
    inline_id = cui_inline_create(gid, &g_mmi_em_dev_fmr_fre_inline_screen);

    cui_inline_run(inline_id);
}

static MMI_RET mmi_em_dev_fmr_fre_scrn_proc(mmi_event_struct *evt)
{
    cui_event_inline_common_struct* inline_evt = (cui_event_inline_common_struct*) evt;
 
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            mmi_em_dev_fmr_enter_status_scrn((U16)mmi_em_dev_fmr_get_edit_value(inline_evt->sender_id, MMI_EM_DEV_FMR_INLINE_ITEM2));
            break;
        }

        case EVT_ID_CUI_INLINE_ABORT:
        {
            /* set flag about fm radio power on */
            g_fm_radio_cntx->rssi_info_freq = 0;
            /* close set fre screen */
            cui_inline_close(inline_evt->sender_id);
            break;
        }
        
        case EVT_ID_GROUP_DEINIT:
        {
            mmi_em_dev_fmr_stop();
            break;
        }

        default:
           break;
    }

    return MMI_RET_OK;
}

/***********************************************
 ** Inline cui: Device->FMR->Radio status scrn
 ***********************************************/
static void mmi_em_dev_fmr_power_on(void)
{    
    if (g_fm_radio_cntx->fmr_is_stop)
    {
        /* set default volume */
        g_fm_radio_cntx->RSSIInfoCurrVolume = 3;  /* 0-6 */
        /* power on FM Radio , and callback can be null if nothing to be handled when interrupted */
        mdi_fmr_power_on_with_path( MDI_DEVICE_SPEAKER2, NULL, NULL);
        mdi_audio_set_volume(AUD_VOLUME_FMR, MDI_AUD_VOL_MUTE(g_fm_radio_cntx->RSSIInfoCurrVolume));
        /* set flag about fm radio power on */
        g_fm_radio_cntx->fmr_is_stop = MMI_FALSE;  
        FMR_RDS_Enable();
    }
    
    /* set FM Radio Frequency */
    mdi_fmr_set_freq(g_fm_radio_cntx->rssi_info_freq);
}

static void mmi_em_dev_fmr_enter_status_scrn(U16 freq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL earphone_is_plug_in = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
#ifdef __MMI_FM_RADIO_BING_EARPHONE__
    earphone_is_plug_in = srv_earphone_is_plug_in();
#endif
    /* set default FM frequency */
//    kal_prompt_trace(MOD_MMI, "[EM] status screen set freq is %d earphone_is_plug_in %d", freq, earphone_is_plug_in);

    if (earphone_is_plug_in && freq >= FM_RADIO_MIN_FREQ && freq <= FM_RADIO_MAX_FREQ)
    {
        g_fm_radio_cntx->rssi_info_freq = freq;
        /* power on FM radio */
        mmi_em_dev_fmr_power_on();
    
        /* Show FM Radio RSSI Info Screen */
        EntryEmDevFMRadioRSSIInfoMenu();
    }
    else
    {
        mmi_em_fail_popup();
    }
}


static void mmi_em_dev_fm_radio_rssi_info_fresh_scrn(void)
{
    StopTimer(EM_RINGTONE_HIGHLIGHT_TIMER);
    mmi_em_fresh_active_scrn();   
    StartTimer(
        EM_RINGTONE_HIGHLIGHT_TIMER, 
        EM_FM_RADIO_RSSI_INFO_DURATION, 
        EMFMRadioRSSIInfoTimeoutHdlr);            
}


static mmi_ret mmi_em_dev_fm_radio_rssi_info_scrn_proc(mmi_event_struct* evt)
{
    switch (evt->evt_id)
    {
       case EVT_ID_SCRN_ACTIVE:
       {
          S8 stringbuf[500] = {0};
        #ifndef __MMI_SLIM_ENGINEER_MODE__
          mmi_em_dev_fmr_status_struct fmr_status = {0};
		#endif //__MMI_SLIM_ENGINEER_MODE__
          mmi_frm_scrn_active_evt_struct *active_evt = (mmi_frm_scrn_active_evt_struct*)evt;


          if (!active_evt->is_first_active)
          {
          #ifdef __MTK_TARGET__
              g_fm_radio_cntx->RSSIInfoCurrSignallevel = FMR_GetSignalLevel(g_fm_radio_cntx->rssi_info_freq);
          #else
              g_fm_radio_cntx->RSSIInfoCurrSignallevel ++;
          #endif
          }
          else
          {
               StartTimer(EM_RINGTONE_HIGHLIGHT_TIMER, EM_FM_RADIO_RSSI_INFO_DURATION, EMFMRadioRSSIInfoTimeoutHdlr);
          }
        #ifndef __MMI_SLIM_ENGINEER_MODE__          
          /* get fm radio status */
          mmi_em_dev_fmr_get_status(&fmr_status);

          /* frequency */
          kal_wsprintf((WCHAR *)stringbuf, 
              "Fre:      %d.%d \nVol:      %d\nRSSI:     %d dBuVemf\nSound track: %w\nRDS BLER: %d\nAntenna type:%w\nCapArray(pF):%w",
              g_fm_radio_cntx->rssi_info_freq / 10, 
              g_fm_radio_cntx->rssi_info_freq % 10,
              g_fm_radio_cntx->RSSIInfoCurrVolume, 
              g_fm_radio_cntx->RSSIInfoCurrSignallevel,
              fmr_status.sound_track,
              fmr_status.rds_bler,
              fmr_status.ant_type,
              fmr_status.capArray);
        #else
          /* frequency */
          kal_wsprintf((WCHAR *)stringbuf, 
              "Fre:      %d.%d \nVol:      %d\nRSSI:     %d dBuVemf",
              g_fm_radio_cntx->rssi_info_freq / 10, 
              g_fm_radio_cntx->rssi_info_freq % 10,
              g_fm_radio_cntx->RSSIInfoCurrVolume, 
              g_fm_radio_cntx->RSSIInfoCurrSignallevel);
        #endif /* __MMI_SLIM_ENGINEER_MODE__ */

  //        kal_prompt_trace(MOD_MMI, "[EM] rssi info scrn freq is %d", g_fm_radio_cntx->rssi_info_freq);
  //        kal_prompt_trace(MOD_MMI, "[EM] rssi info scrn RSSIInfoCurrVolume is %d", g_fm_radio_cntx->RSSIInfoCurrVolume);
  //        kal_prompt_trace(MOD_MMI, "[EM] rssi info scrn RSSIInfoCurrSignallevel is %d", g_fm_radio_cntx->RSSIInfoCurrSignallevel);
  //        kal_prompt_trace(MOD_MMI, "[EM] rssi info scrn is sound_track %s", fmr_status.sound_track);
  //        kal_prompt_trace(MOD_MMI, "[EM] rssi info scrn is rds_bler %d", fmr_status.rds_bler);
  //        kal_prompt_trace(MOD_MMI, "[EM] rssi info scrn is ant_type %d", fmr_status.ant_type);
  //        kal_prompt_trace(MOD_MMI, "[EM] rssi info scrn is capArray %s", fmr_status.capArray);
        #ifndef __MMI_SLIM_ENGINEER_MODE__          
          ShowCategory7Screen(
              STR_ID_EM_DEVICE_FM_RADIO_STATUS, 0, 
              STR_GLOBAL_EDIT, IMG_GLOBAL_OK,
              STR_GLOBAL_BACK, IMG_GLOBAL_BACK, 
              (PU8)stringbuf, active_evt->gui_buffer);
        #else
          ShowCategory7Screen(
            STR_ID_EM_DEVICE_FM_RADIO_STATUS, 0, 
            0, 0,
            STR_GLOBAL_BACK, IMG_GLOBAL_BACK, 
            (PU8)stringbuf, active_evt->gui_buffer);
        #endif /* __MMI_SLIM_ENGINEER_MODE__ */

		   #ifdef __MMI_CLIPBOARD__
    		mmi_imc_clipboard_disconnect();
		  #endif /* __MMI_CLIPBOARD__ */
          break;
       }
    #ifndef __MMI_SLIM_ENGINEER_MODE__
       case EVT_ID_WGUI_LSK_CLICK:
       {
           // Before entering edit screen, timer and audio should be stop
           StopTimer(EM_RINGTONE_HIGHLIGHT_TIMER);
           
           // Enter status edit screen
           mmi_em_dev_fmr_enter_status_edit_scrn();
           break;
       }
    #endif /* __MMI_SLIM_ENGINEER_MODE__ */       
       case EVT_ID_WGUI_RSK_CLICK:
       {
           StopTimer(EM_RINGTONE_HIGHLIGHT_TIMER);
           break;
       }

       case EVT_ID_ON_KEY:
       {
           mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
           
           if (key_evt->key_type == KEY_EVENT_UP)
           {
               mmi_ret result = MMI_RET_KEY_HANDLED;
               
               switch (key_evt->key_code)
               {
               #ifndef __COSMOS_MMI__
                   case KEY_LEFT_ARROW:
                       EmDevFMRadioRSSIInfoLeftArrowHdlr();
                       break;
                       
                   case KEY_RIGHT_ARROW:
                       EmDevFMRadioRSSIInfoRightArrowHdlr();
                       break;
                       
                   case KEY_UP_ARROW:
                       EmDevFMRadioRSSIInfoUpArrowHdlr();
                       break;
                       
                   case KEY_DOWN_ARROW:
                       EmDevFMRadioRSSIInfoDownArrowHdlr();
                       break;
                       
               #else
                   case KEY_SEND:
                       EmDevFMRadioRSSIInfoLeftArrowHdlr();
                       break;
                       
                   case KEY_BACK:
                       EmDevFMRadioRSSIInfoRightArrowHdlr();
                       break;
                       
                   case KEY_VOL_UP:
                       EmDevFMRadioRSSIInfoUpArrowHdlr();
                       break;
                       
                   case KEY_VOL_DOWN:
                       EmDevFMRadioRSSIInfoDownArrowHdlr();
                       break;
               #endif
               
                    default:
                       result = MMI_RET_OK;
                       break;
               }
               
               return result;
           }
           
           break;
       }
    }
    
    return MMI_RET_OK;
}
/**************************************************************
**  FUNCTION NAME       : EntryEmDevFMRadioRSSIInfoMenu
**
**      PURPOSE             : to show FM Radio RSSI Info screen
**
**  INPUT PARAMETERS    : index
**
**  OUTPUT PARAMETERS   : void
**
**  RETURNS             : void
**
**  REMARKS         : 
**************************************************************/
void EntryEmDevFMRadioRSSIInfoMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_create(mmi_em_get_root_group(), 
        SCR_ID_EM_DEV_FM_RADIO_RSSI_INFO,
        mmi_em_dev_fm_radio_rssi_info_scrn_proc,
        NULL);
}


/**************************************************************
**  FUNCTION NAME       : EmDevFMRadioRSSIInfoLeftArrowHdlr
**
**  PURPOSE             : Entry function to FM Radio RSSI Info Left Arrow Hdler
**
**  INPUT PARAMETERS    : index
**
**  OUTPUT PARAMETERS   : void
**
**  RETURNS             : void
**
**  REMARKS         : 
**************************************************************/
void EmDevFMRadioRSSIInfoLeftArrowHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fm_radio_cntx->rssi_info_freq > 875)
        g_fm_radio_cntx->rssi_info_freq -= 1;
        
    /* set FM Radio Frequency */
    mdi_fmr_set_freq(g_fm_radio_cntx->rssi_info_freq);

    mmi_em_dev_fm_radio_rssi_info_fresh_scrn();
}


/**************************************************************
**  FUNCTION NAME       : EmDevFMRadioRSSIInfoRightArrowHdlr
**
**      PURPOSE             : Entry function to FM Radio RSSI Info Right Arrow Hdler
**
**  INPUT PARAMETERS    : index
**
**  OUTPUT PARAMETERS   : void
**
**  RETURNS             : void
**
**  REMARKS         : 
**************************************************************/
void EmDevFMRadioRSSIInfoRightArrowHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fm_radio_cntx->rssi_info_freq < 1080)
        g_fm_radio_cntx->rssi_info_freq += 1;
        
    /* set FM Radio Frequency */
    mdi_fmr_set_freq( g_fm_radio_cntx->rssi_info_freq);

    mmi_em_dev_fm_radio_rssi_info_fresh_scrn();
}


/**************************************************************
**  FUNCTION NAME       : EmDevFMRadioRSSIInfoUpArrowHdlr
**
**      PURPOSE             : Entry function to FM Radio RSSI Info Up Arrow Hdler
**
**  INPUT PARAMETERS    : index
**
**  OUTPUT PARAMETERS   : void
**
**  RETURNS             : void
**
**  REMARKS         : 
**************************************************************/
void EmDevFMRadioRSSIInfoUpArrowHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fm_radio_cntx->RSSIInfoCurrVolume < MAX_VOL_LEVEL - 1)
        g_fm_radio_cntx->RSSIInfoCurrVolume++;

    mdi_audio_set_volume(AUD_VOLUME_FMR, MDI_AUD_VOL_MUTE(g_fm_radio_cntx->RSSIInfoCurrVolume));
    
    mmi_em_dev_fm_radio_rssi_info_fresh_scrn();               
}


/**************************************************************
**  FUNCTION NAME       : EmDevFMRadioRSSIInfoDownArrowHdlr
**
**      PURPOSE             : Entry function to FM Radio RSSI Info Down Arrow Hdler
**
**  INPUT PARAMETERS    : index
**
**  OUTPUT PARAMETERS   : void
**
**  RETURNS             : void
**
**  REMARKS         : 
**************************************************************/
void EmDevFMRadioRSSIInfoDownArrowHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fm_radio_cntx->RSSIInfoCurrVolume > 0)
        g_fm_radio_cntx->RSSIInfoCurrVolume--;
        
    mdi_audio_set_volume(AUD_VOLUME_FMR, MDI_AUD_VOL_MUTE(g_fm_radio_cntx->RSSIInfoCurrVolume));

    mmi_em_dev_fm_radio_rssi_info_fresh_scrn();
}


/**************************************************************
**  FUNCTION NAME       : EMFMRadioRSSIInfoTimeoutHdlr
**
**      PURPOSE             : Entry function to FM Radio RSSI Info timeout Hdler
**
**  INPUT PARAMETERS    : index
**
**  OUTPUT PARAMETERS   : void
**
**  RETURNS             : void
**
**  REMARKS         : 
**************************************************************/
void EMFMRadioRSSIInfoTimeoutHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_fresh_active_scrn();
    StartTimer(EM_RINGTONE_HIGHLIGHT_TIMER, EM_FM_RADIO_RSSI_INFO_DURATION, EMFMRadioRSSIInfoTimeoutHdlr);
}
#ifndef __MMI_SLIM_ENGINEER_MODE__
static void mmi_em_dev_fmr_get_status(mmi_em_dev_fmr_status_struct *fmr_status)
{
    U32 idx;
    CHAR temp[10];
    
    if (NULL == fmr_status)
        return;
    
    idx = FMR_Get_Sound_Track();
//    kal_prompt_trace(MOD_MMI, "[EM] FM Radio status Sound_Track is %d", idx);
    fmr_status->sound_track = (WCHAR*)get_string(g_mmi_em_dev_fmr_sound_track[idx]);
    
    fmr_status->rds_bler = FMR_RDS_GetBLER();
    
 //   kal_prompt_trace(MOD_MMI, "[EM] FM Radio status RDS BLER is %d", fmr_status->rds_bler);
    
    idx = FMR_Get_AntennaType();
 //   kal_prompt_trace(MOD_MMI, "[EM] FM Radio status AntennaType is %d", idx);
    fmr_status->ant_type = (WCHAR*)get_string(g_mmi_em_dev_fmr_ant_type[idx]);
    
    if (FMR_Get_AntennaType() == FMR_ANTENNA_TYPE_LONG)
        mmi_wcscpy(fmr_status->capArray, (WCHAR*)L"N/A");
    else
    {
        kal_sprintf(temp, "%.3fpF", FMR_GetCapArray()/(float)1000);
        mmi_asc_to_ucs2((CHAR*)fmr_status->capArray, temp);
    }
}
#endif /* __MMI_SLIM_ENGINEER_MODE__ */
/***********************************************
 ** Device->FMR->Radio status edit screen
 ***********************************************/
static U16 g_mmi_em_dev_fmr_edit_hex_char[] = L"-a-fX0-9";

#ifndef __MMI_SLIM_ENGINEER_MODE__
typedef enum
{
    MMI_EM_DEV_FMR_SOUND_TRACK_MONO = 0,
    MMI_EM_DEV_FMR_SOUND_TRACK_STEREO,
    MMI_EM_DEV_FMR_SOUND_TRACK_END_OF_ITEM
} mmi_em_dev_fmr_sound_track_enum;

typedef enum
{
    MMI_EM_DEV_FMR_ANT_LONG = 0,
    MMI_EM_DEV_FMR_ANT_SHORT,
    MMI_EM_DEV_FMR_ANT_END_OF_ITEM
} mmi_em_dev_fmr_ant_enum;

static const cui_inline_item_caption_struct g_mmi_em_dev_fmr_cap_force = 
{
    STR_ID_EM_DEV_FMR_FORCE_SET,
};

static const cui_inline_item_caption_struct g_mmi_em_dev_fmr_cap_antenna = 
{
    STR_ID_EM_DEV_FMR_ANTENNA_TYPE,
};

static const U16 g_mmi_em_dev_fmr_force_select_str[] = {
                      STR_ID_EM_DEVICE_FM_RADIO_MONO,
                      STR_ID_EM_DEVICE_FM_RADIO_STEREO};

static const cui_inline_item_select_struct g_mmi_em_dev_fmr_force_select = 
{
    sizeof(g_mmi_em_dev_fmr_force_select_str)/sizeof(U16),
    0,
    (U16*)g_mmi_em_dev_fmr_force_select_str,
};

static const U16 g_mmi_em_dev_fmr_ant_select_str[] = {
                      STR_ID_EM_DEV_FMR_ANT_LONG,
                      STR_ID_EM_DEV_FMR_ANT_SHORT};

static const cui_inline_item_select_struct g_mmi_em_dev_fmr_ant_select = 
{
    sizeof(g_mmi_em_dev_fmr_ant_select_str)/sizeof(U16),
    0,
    (U16*)g_mmi_em_dev_fmr_ant_select_str,
};

static const cui_inline_set_item_struct g_mmi_em_dev_fmr_status_edit_inline[] = 
{
    {MMI_EM_DEV_FMR_INLINE_ITEM1, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_dev_fmr_cap_force},
    {MMI_EM_DEV_FMR_INLINE_ITEM2, CUI_INLINE_ITEM_TYPE_SELECT,  0, (void*)&g_mmi_em_dev_fmr_force_select},
    {MMI_EM_DEV_FMR_INLINE_ITEM3, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_dev_fmr_cap_antenna},
    {MMI_EM_DEV_FMR_INLINE_ITEM4, CUI_INLINE_ITEM_TYPE_SELECT,  0, (void*)&g_mmi_em_dev_fmr_ant_select},
};

static const cui_inline_struct g_mmi_em_dev_fmr_status_edit_inline_screen = 
{
    sizeof(g_mmi_em_dev_fmr_status_edit_inline)/sizeof(cui_inline_set_item_struct),
    STR_ID_EM_DEVICE_FM_RADIO_STATUS,
    0,
    CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    (const cui_inline_set_item_struct*)&g_mmi_em_dev_fmr_status_edit_inline
};

static void mmi_em_dev_fmr_enter_status_edit_scrn(void)
{
    MMI_ID gid;
    MMI_ID inline_id;

    
    // Create new screen group, and create new inline cui
    gid = mmi_frm_group_create_ex(mmi_em_get_root_group(),
              GRP_ID_AUTO_GEN, 
              mmi_em_dev_fmr_status_edit_scrn_proc, NULL,
              MMI_FRM_NODE_SMART_CLOSE_FLAG);

    inline_id = cui_inline_create(gid, &g_mmi_em_dev_fmr_status_edit_inline_screen);

    mmi_em_dev_fmr_status_edit_scrn_init(inline_id);

    cui_inline_run(inline_id);
}

static void mmi_em_dev_fmr_status_edit_scrn_init(mmi_id scrn_id)
{
    fmr_sound_track_type_enum track_type;
    fmr_antenna_type_enum     antenna_type;
    
    track_type = FMR_Get_Sound_Track();
    cui_inline_set_value(scrn_id, MMI_EM_DEV_FMR_INLINE_ITEM2, (void *) track_type);
    
    antenna_type = FMR_Get_AntennaType();
    cui_inline_set_value(scrn_id, MMI_EM_DEV_FMR_INLINE_ITEM4, (void *) antenna_type);
}


static MMI_RET mmi_em_dev_fmr_status_edit_scrn_proc(mmi_event_struct *evt)
{
    cui_event_inline_common_struct* inline_evt = (cui_event_inline_common_struct*) evt;
 
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            mmi_em_dev_fmr_set_status(inline_evt->sender_id);
            cui_inline_close(inline_evt->sender_id);
            StartTimer(EM_RINGTONE_HIGHLIGHT_TIMER, EM_FM_RADIO_RSSI_INFO_DURATION, EMFMRadioRSSIInfoTimeoutHdlr);
            break;
        }

        case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_inline_close(inline_evt->sender_id);
            StartTimer(EM_RINGTONE_HIGHLIGHT_TIMER, EM_FM_RADIO_RSSI_INFO_DURATION, EMFMRadioRSSIInfoTimeoutHdlr);
            break;
        }

        default:
            break;
    }

    return MMI_RET_OK;
}

static void mmi_em_dev_fmr_set_status(mmi_id scrn_id)
{
    U8 select_idx;
    fmr_antenna_type_enum ant_type = FMR_ANTENNA_TYPE_END;
    //
    cui_inline_get_value(scrn_id, MMI_EM_DEV_FMR_INLINE_ITEM2, (void *)&select_idx);
    
    if (MMI_EM_DEV_FMR_SOUND_TRACK_MONO == select_idx)
    {
        FMR_Force_Mono();
    }
    else if (MMI_EM_DEV_FMR_SOUND_TRACK_STEREO == select_idx)
    {
        FMR_Force_Stereo();
    }
    
//    kal_prompt_trace(MOD_MMI, "[EM] mmi_em_dev_fmr_set_status, sound track idx is %d", select_idx);
    
    select_idx = 0;

    cui_inline_get_value(scrn_id, MMI_EM_DEV_FMR_INLINE_ITEM4, (void *)&select_idx);

    if (MMI_EM_DEV_FMR_ANT_LONG == select_idx)
    {
        ant_type = FMR_ANTENNA_TYPE_LONG;
    }
    else if (MMI_EM_DEV_FMR_ANT_SHORT == select_idx)
    {
        ant_type = FMR_ANTENNA_TYPE_SHORT;
    }
    
//    kal_prompt_trace(MOD_MMI, "[EM] mmi_em_dev_fmr_set_status, ant type is %d", ant_type);
    
    FMR_Set_AntennaType(ant_type);
}

/***********************************************
 ** Device->FMR->Radio Freq set scrn
 ***********************************************/
static const cui_inline_item_caption_struct g_mmi_em_dev_fmr_cap_long_ant = 
{
    STR_ID_EM_DEV_FMR_LONG_ANT,
};

static const cui_inline_item_caption_struct g_mmi_em_dev_fmr_cap_short_ant = 
{
    STR_ID_EM_DEV_FMR_SHORT_ANT,
};
#endif /* __MMI_SLIM_ENGINEER_MODE__ */
static const mmi_imm_input_mode_enum g_mmi_em_dev_imm_input_mode[] = 
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC,
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC,
    IMM_INPUT_MODE_123,
    IMM_INPUT_MODE_NONE
};
#ifndef __MMI_SLIM_ENGINEER_MODE__
static const cui_inline_item_text_edit_struct g_mmi_em_dev_fmr_edit_long_ant = 
{
    0,
    0,
    6,
    IMM_INPUT_TYPE_USER_SPECIFIC,
    0,
    (mmi_imm_input_mode_enum*)&g_mmi_em_dev_imm_input_mode
};

static const cui_inline_item_text_edit_struct g_mmi_em_dev_fmr_display_long_ant = 
{
    0,
    0,
    6,
    IMM_INPUT_TYPE_DECIMAL_NUMERIC,
    0,
    0
};

static const cui_inline_item_text_edit_struct g_mmi_em_dev_fmr_edit_short_ant = 
{
    0,
    0,
    6,
    IMM_INPUT_TYPE_USER_SPECIFIC,
    0,
    (mmi_imm_input_mode_enum*)&g_mmi_em_dev_imm_input_mode
};

static const cui_inline_item_text_edit_struct g_mmi_em_dev_fmr_display_short_ant = 
{
    0,
    0,
    6,
    IMM_INPUT_TYPE_DECIMAL_NUMERIC,
    0,
    0
};

static const cui_inline_set_item_struct g_mmi_em_dev_fmr_ant_edit_inline[] = 
{
    {MMI_EM_DEV_FMR_INLINE_ITEM1, CUI_INLINE_ITEM_TYPE_CAPTION,   0, (void*)&g_mmi_em_dev_fmr_cap_long_ant},
    {MMI_EM_DEV_FMR_INLINE_ITEM2, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&g_mmi_em_dev_fmr_edit_long_ant},
    {MMI_EM_DEV_FMR_INLINE_ITEM3, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&g_mmi_em_dev_fmr_display_long_ant},
    {MMI_EM_DEV_FMR_INLINE_ITEM4, CUI_INLINE_ITEM_TYPE_CAPTION,   0, (void*)&g_mmi_em_dev_fmr_cap_short_ant},
    {MMI_EM_DEV_FMR_INLINE_ITEM5, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&g_mmi_em_dev_fmr_edit_short_ant},
    {MMI_EM_DEV_FMR_INLINE_ITEM6, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&g_mmi_em_dev_fmr_display_short_ant},
};

static const cui_inline_struct g_mmi_em_dev_fmr_ant_edit_inline_screen = 
{
    sizeof(g_mmi_em_dev_fmr_ant_edit_inline)/sizeof(cui_inline_set_item_struct),
    STR_ID_EM_DEVICE_FM_RADIO_THOSRHELD,
    0,
    CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    (const cui_inline_set_item_struct*)&g_mmi_em_dev_fmr_ant_edit_inline
};

static void mmi_em_dev_fmr_enter_ant_edit_scrn(void)
{
    MMI_ID gid;
    MMI_ID inline_id;

    
    gid = mmi_frm_group_create_ex(mmi_em_get_root_group(),
              GRP_ID_AUTO_GEN, 
              mmi_em_dev_fmr_ant_edit_scrn_proc, NULL,
              MMI_FRM_NODE_SMART_CLOSE_FLAG);

    inline_id = cui_inline_create(gid, &g_mmi_em_dev_fmr_ant_edit_inline_screen);

    mmi_em_dev_fmr_init_ant(inline_id);

    cui_inline_run(inline_id);
}


static MMI_RET mmi_em_dev_fmr_ant_edit_scrn_proc(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            U32 ant_long, ant_short;
            cui_event_inline_submit_struct* submit_evt = (cui_event_inline_submit_struct*)evt;
            CHAR  acs_buf[6]  = {0};
            WCHAR edit_buf[6] = {0};

            ant_long = ant_short = 0;

            cui_inline_get_value(submit_evt->sender_id, MMI_EM_DEV_FMR_INLINE_ITEM2, (void *)edit_buf);
            mmi_wcs_to_asc(acs_buf, edit_buf);
            if (MMI_FALSE == mmi_em_dev_fmr_ctohex(acs_buf, strlen((const CHAR*)acs_buf), &ant_long))
            {
                mmi_em_fail_popup();
                return MMI_RET_OK;
            }
            mmi_em_dev_fmr_ant_hex_to_db(submit_evt->sender_id, ant_long, MMI_EM_DEV_FMR_INLINE_ITEM3);
            
            cui_inline_get_value(submit_evt->sender_id, MMI_EM_DEV_FMR_INLINE_ITEM5, (void *)edit_buf);
            mmi_wcs_to_asc(acs_buf, edit_buf);
            if (MMI_FALSE == mmi_em_dev_fmr_ctohex(acs_buf, strlen((const CHAR*)acs_buf), &ant_short))
            {
                mmi_em_fail_popup();
                return MMI_RET_OK;
            }
            mmi_em_dev_fmr_ant_hex_to_db(submit_evt->sender_id, ant_short, MMI_EM_DEV_FMR_INLINE_ITEM6);
            
            mmi_em_dev_fmr_set_ant(ant_long, ant_short);
            
            mmi_em_success_popup();
            break;
        }

        case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_common_struct* inline_evt = (cui_event_inline_common_struct*) evt;


            cui_inline_close(inline_evt->sender_id);
            break;
        }
        
        case EVT_ID_CUI_INLINE_NOTIFY:
        {
            cui_event_inline_notify_struct* notify_evt = (cui_event_inline_notify_struct*) evt;
            
            if (CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM == notify_evt->event_type)
            {
                if (MMI_EM_DEV_FMR_INLINE_ITEM2 == notify_evt->item_id
                    || MMI_EM_DEV_FMR_INLINE_ITEM5 == notify_evt->item_id)
                {
                     mmi_imm_set_characters(MMI_TRUE, g_mmi_em_dev_fmr_edit_hex_char);
                }
            }

            if (CUI_INLINE_NOTIFY_ITEM_CHANGED == notify_evt->event_type)
            {
                if (MMI_EM_DEV_FMR_INLINE_ITEM2 == notify_evt->item_id)
                {
                    U32 hex_value;
                    CHAR  acs_buf[6]  = {0};
                    WCHAR edit_buf[6] = {0};
                                        
                    
                    cui_inline_get_value(notify_evt->sender_id, MMI_EM_DEV_FMR_INLINE_ITEM2, (void *)edit_buf);
                    mmi_wcs_to_asc(acs_buf, edit_buf);
                    if (MMI_FALSE == mmi_em_dev_fmr_ctohex(acs_buf, strlen((const CHAR*)acs_buf), &hex_value))
                    {
                        return MMI_RET_OK;
                    }
                    mmi_em_dev_fmr_ant_hex_to_db(notify_evt->sender_id, hex_value, MMI_EM_DEV_FMR_INLINE_ITEM3);
                }
                else if (MMI_EM_DEV_FMR_INLINE_ITEM3 == notify_evt->item_id)
                {
                     S32 db  = mmi_em_dev_fmr_get_edit_value(notify_evt->sender_id, MMI_EM_DEV_FMR_INLINE_ITEM3);
                     
                     mmi_em_dev_fmr_ant_db_to_hex(notify_evt->sender_id, db, MMI_EM_DEV_FMR_INLINE_ITEM2);
                }
                else if (MMI_EM_DEV_FMR_INLINE_ITEM5 == notify_evt->item_id)
                {
                    U32 hex_value;
                    CHAR  acs_buf[6]  = {0};
                    WCHAR edit_buf[6] = {0};
                                        
                    
                    cui_inline_get_value(notify_evt->sender_id, MMI_EM_DEV_FMR_INLINE_ITEM5, (void *)edit_buf);
                    mmi_wcs_to_asc(acs_buf, edit_buf);
                    if (MMI_FALSE == mmi_em_dev_fmr_ctohex(acs_buf, strlen((const CHAR*)acs_buf), &hex_value))
                    {
                        return MMI_RET_OK;
                    }
                    mmi_em_dev_fmr_ant_hex_to_db(notify_evt->sender_id, hex_value, MMI_EM_DEV_FMR_INLINE_ITEM6);
                }
                else if (MMI_EM_DEV_FMR_INLINE_ITEM6 == notify_evt->item_id)
                {
                     S32 db  = mmi_em_dev_fmr_get_edit_value(notify_evt->sender_id, MMI_EM_DEV_FMR_INLINE_ITEM6);
                     
                     mmi_em_dev_fmr_ant_db_to_hex(notify_evt->sender_id, db, MMI_EM_DEV_FMR_INLINE_ITEM5);
                }
            }
            break;
        }

        default:
            break;
    }

    return MMI_RET_OK;
}

static void mmi_em_dev_fmr_set_ant(S32 ant_long, S32 ant_short)
{
    FMR_Set_RSSI_Threshold(FMR_ANTENNA_TYPE_LONG, ant_long);
    
    FMR_Set_RSSI_Threshold(FMR_ANTENNA_TYPE_SHORT, ant_short);
}

static void mmi_em_dev_fmr_get_ant(S32* ant_long, S32* ant_short)
{
    if (!ant_long || !ant_short)
        return;
        
    *ant_long = FMR_Get_RSSI_Threshold(FMR_ANTENNA_TYPE_LONG);
    *ant_short = FMR_Get_RSSI_Threshold(FMR_ANTENNA_TYPE_SHORT);
}

static void mmi_em_dev_fmr_init_ant(mmi_id scrn_id)
{
    S32 ant_long, ant_short;
    

    mmi_em_dev_fmr_get_ant(&ant_long, &ant_short);
    
//    kal_prompt_trace(MOD_MMI, "[EM] init ant screen ant_long %d, ant_short %d", ant_long, ant_short);
    
    mmi_em_dev_fmr_set_edit_value(
        scrn_id, MMI_EM_DEV_FMR_INLINE_ITEM2,
        ant_long);

    mmi_em_dev_fmr_set_edit_value(
        scrn_id, MMI_EM_DEV_FMR_INLINE_ITEM5, 
        ant_short);
    
    mmi_em_dev_fmr_ant_hex_to_db(scrn_id, ant_long, MMI_EM_DEV_FMR_INLINE_ITEM3);
    mmi_em_dev_fmr_ant_hex_to_db(scrn_id, ant_short, MMI_EM_DEV_FMR_INLINE_ITEM6);
}

static void mmi_em_dev_fmr_ant_hex_to_db(mmi_id scrn_id, U32 hex, U16 item_id)
{
    kal_int32 db;
    WCHAR buffer[6] = {0};
    
    
    db = FMR_RSSI_Hex2Db(hex);
//    kal_prompt_trace(MOD_MMI, "[EM] hex_to_db, hex = %d, db = %d", hex, db);

    mmi_wcs_itow(db, buffer, 10);
    cui_inline_set_value(scrn_id, item_id, (void *)buffer);
}

static void mmi_em_dev_fmr_ant_db_to_hex(mmi_id scrn_id, S32 db, U16 item_id)
{
    U32 hex;
    WCHAR buffer[6] = {0};
    
    
    hex = FMR_RSSI_Db2Hex(db);
    mmi_em_itoa((S32)hex, 16, buffer);
    
 //   kal_prompt_trace(MOD_MMI, "[EM] db_to_hex, db = %d, hex = %d", db, hex);
 
    cui_inline_set_value(scrn_id, item_id, (void *)buffer);
}
#endif /* __MMI_SLIM_ENGINEER_MODE__ */
/***********************************************
 ** Device->FMR->Radio Common Cmd
 ***********************************************/
#define MMI_EM_DEV_VAILID_NUM_PRE_LINE      (4)

#define MMI_EM_DEV_FMR_CMD_EXIT_STR_MAX_LEN (20)

static MMI_BOOL mmi_em_dev_fmr_cmd_convert_format_cmd(WCHAR* edit_text, U8* cmd, U32 cmd_len);

static MMI_BOOL mmi_em_dev_fmr_cmd_display_format_cmd(U8* cmd, U32 len, WCHAR* buf, U32 buf_len);

static mmi_ret mmi_em_dev_fmr_cmn_cmd_scrn_proc(mmi_event_struct *evt);

static void mmi_em_dev_fmr_enter_cmn_cmd_scrn(void);

static void mmi_em_dev_fmr_cmd_init_scrn(mmi_id scrn_id);

//static MMI_BOOL mmi_em_dev_fmr_cmd_init_output_scrn(WCHAR *scrn_cntx_buf, U32 except_text_len);

static MMI_BOOL mmi_em_dev_fmr_set_cmn_cmd(mmi_id scrn_id);

static void mmi_em_dev_fmr_enter_output_scrn(void);

static const cui_inline_item_caption_struct g_mmi_em_dev_fmr_cap_cmn_cmd_type = 
{
    STR_ID_EM_DEVICE_FM_RADIO_COMN_CMD_INPUT,
};

static const cui_inline_item_text_edit_struct g_mmi_em_dev_fmr_cmd_edit_item1 = 
{
    0,
    0,
    MMI_EM_DEV_FMR_CMD_EXIT_STR_MAX_LEN,
    IMM_INPUT_TYPE_USER_SPECIFIC,
    0,
    (mmi_imm_input_mode_enum *)&g_mmi_em_dev_imm_input_mode,
};

static const cui_inline_item_text_edit_struct g_mmi_em_dev_fmr_cmd_edit_item2 = 
{
    0,
    0,
    MMI_EM_DEV_FMR_CMD_EXIT_STR_MAX_LEN,
    IMM_INPUT_TYPE_USER_SPECIFIC,
    0,
    (mmi_imm_input_mode_enum *)&g_mmi_em_dev_imm_input_mode,
};

static const cui_inline_item_text_edit_struct g_mmi_em_dev_fmr_cmd_edit_item3 = 
{
    0,
    0,
    MMI_EM_DEV_FMR_CMD_EXIT_STR_MAX_LEN,
    IMM_INPUT_TYPE_USER_SPECIFIC,
    0,
    (mmi_imm_input_mode_enum *)&g_mmi_em_dev_imm_input_mode,
};

static const cui_inline_item_text_edit_struct g_mmi_em_dev_fmr_cmd_edit_item4 = 
{
    0,
    0,
    MMI_EM_DEV_FMR_CMD_EXIT_STR_MAX_LEN,
    IMM_INPUT_TYPE_USER_SPECIFIC,
    0,
    (mmi_imm_input_mode_enum *)&g_mmi_em_dev_imm_input_mode,
};

static const cui_inline_item_text_edit_struct g_mmi_em_dev_fmr_cmd_edit_item5 = 
{
    0,
    0,
    MMI_EM_DEV_FMR_CMD_EXIT_STR_MAX_LEN,
    IMM_INPUT_TYPE_USER_SPECIFIC,
    0,
    (mmi_imm_input_mode_enum *)&g_mmi_em_dev_imm_input_mode,
};

static const cui_inline_set_item_struct g_mmi_em_dev_fmr_cmd_inline[] = 
{
    {MMI_EM_DEV_FMR_INLINE_ITEM1, CUI_INLINE_ITEM_TYPE_CAPTION,   0, (void*)&g_mmi_em_dev_fmr_cap_cmn_cmd_type},
    {MMI_EM_DEV_FMR_INLINE_ITEM2, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&g_mmi_em_dev_fmr_cmd_edit_item1},
    {MMI_EM_DEV_FMR_INLINE_ITEM3, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&g_mmi_em_dev_fmr_cmd_edit_item2},
    {MMI_EM_DEV_FMR_INLINE_ITEM4, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&g_mmi_em_dev_fmr_cmd_edit_item3},
    {MMI_EM_DEV_FMR_INLINE_ITEM5, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&g_mmi_em_dev_fmr_cmd_edit_item4},
    {MMI_EM_DEV_FMR_INLINE_ITEM6, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&g_mmi_em_dev_fmr_cmd_edit_item5},
};

static const cui_inline_struct g_mmi_em_dev_fmr_cmn_cmd_screen = 
{
    sizeof(g_mmi_em_dev_fmr_cmd_inline)/sizeof(cui_inline_set_item_struct),
    STR_ID_EM_DEVICE_FM_RADIO_COMN_CMD,
    0,
    CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    (const cui_inline_set_item_struct*)&g_mmi_em_dev_fmr_cmd_inline
};

static void mmi_em_dev_fmr_enter_cmn_cmd_scrn(void)
{
    MMI_ID gid;
    MMI_ID inline_id;

    
    gid = mmi_frm_group_create_ex(mmi_em_get_root_group(),
              GRP_ID_AUTO_GEN, 
              mmi_em_dev_fmr_cmn_cmd_scrn_proc, NULL,
              MMI_FRM_NODE_SMART_CLOSE_FLAG);

    inline_id = cui_inline_create(gid, &g_mmi_em_dev_fmr_cmn_cmd_screen);
    
    mmi_em_dev_fmr_cmd_init_scrn(inline_id);

    cui_inline_run(inline_id);
}

static mmi_ret mmi_em_dev_fmr_cmn_cmd_scrn_proc(mmi_event_struct *evt)
{    
    cui_event_inline_common_struct* inline_evt = (cui_event_inline_common_struct*) evt;


    switch(evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            if (mmi_em_dev_fmr_set_cmn_cmd(inline_evt->sender_id))
            {
                // If input common cmd is right, enter output screen
                mmi_em_dev_fmr_enter_output_scrn();
            }
            else
            {
                // If input common cmd is right, popup fail screen
                mmi_em_fail_popup();
            }

            break;
        }

        case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_inline_close(inline_evt->sender_id);
            break;
        }

        case EVT_ID_CUI_INLINE_NOTIFY:
        {
            mmi_imm_set_characters(MMI_TRUE, g_mmi_em_dev_fmr_edit_hex_char);
            break;
        }

        default:
            break;
    }
    
    return MMI_RET_OK;
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
#endif

static void mmi_em_dev_fmr_cmd_init_scrn(mmi_id scrn_id)
{
    U32 i, j;
    U8 cmd_param[50] = {0};
    WCHAR edit_item_buf[MMI_EM_DEV_FMR_CMD_EXIT_STR_MAX_LEN];
    
    
    //cmd_len = FMR_Get_Param(cmd_param);
    
    i = j = 0;
    
    while (i < 20)
    {
        if ((i + 1)%4 == 0)
        {
           edit_item_buf[0] = 0;
           
           // if display format cmd is not right, return to exit this funcation and stop this process
           if (mmi_em_dev_fmr_cmd_display_format_cmd(&cmd_param[i-3], 4, edit_item_buf, MMI_EM_DEV_FMR_CMD_EXIT_STR_MAX_LEN))
           {
               cui_inline_set_value(scrn_id, MMI_EM_DEV_FMR_INLINE_ITEM2 + j, (void*)edit_item_buf);
           }
           else
           {
               return;
           }
           
           j++;
        }

        i++;
    }
}

/*
static MMI_BOOL mmi_em_dev_fmr_cmd_init_output_scrn(WCHAR *scrn_cntx_buf, U32 except_text_len)
{
    U32 i, j, cmd_len;
    U8 cmd_param[50] = {0};
    
    
    if (NULL == scrn_cntx_buf)
        return MMI_FALSE;

    cmd_len = FMR_Get_Param(cmd_param);
    
    i = j = 0;
    
    while (i < cmd_len)
    {
        if ((i + 1)%4 == 0)
        {
           // if display format cmd is not right, return to exit this funcation and stop this process
           if (!mmi_em_dev_fmr_cmd_display_format_cmd(&cmd_param[i-3], 4, scrn_cntx_buf + j * MMI_EM_DEV_FMR_CMD_EXIT_STR_MAX_LEN, MMI_EM_DEV_FMR_CMD_EXIT_STR_MAX_LEN))
           {
               return MMI_FALSE;
           }
           
           j++;
           
           *(scrn_cntx_buf + j * MMI_EM_DEV_FMR_CMD_EXIT_STR_MAX_LEN - 1) = '\n';
        }

        i++;
    }
    
    *(scrn_cntx_buf + j * MMI_EM_DEV_FMR_CMD_EXIT_STR_MAX_LEN - 1) = '\0';
    
    return (MMI_BOOL)(mmi_wcslen(scrn_cntx_buf) <= except_text_len);
}
*/
static MMI_BOOL mmi_em_dev_fmr_cmd_display_format_cmd(U8* cmd, U32 len, WCHAR* buf, U32 buf_len)
{
     U32 i;
     
     // "0X%2x-0X%2x-0X%2x-0X%2x" is cmd format
     kal_wsprintf(buf, "0X%-2x-0X%-2x-0X%-2x-0X%-2x", *cmd, *(cmd + 1), *(cmd + 2), *(cmd + 3));
     
     i = mmi_wcslen((const WCHAR*)buf);
     
     // check if format cmd string is rignt
     return (MMI_BOOL)(i < buf_len);
}

static MMI_BOOL mmi_em_dev_fmr_cmd_convert_format_cmd(WCHAR* edit_text, U8* cmd, U32 cmd_len)
{
    U32 i, j, text_len, valib_num;
    U32 start_idx, end_idx;
    CHAR edit_text_buf[MMI_EM_DEV_FMR_CMD_EXIT_STR_MAX_LEN] = {0};
    
    
    start_idx = end_idx = i = j = valib_num = 0;
    
    // If edit len is more then MMI_EM_DEV_FMR_CMD_EXIT_STR_MAX_LEN,
    // the string of edit_text is wrong 
    if ((text_len = mmi_wcslen(edit_text)) >= MMI_EM_DEV_FMR_CMD_EXIT_STR_MAX_LEN)
    {
        return MMI_FALSE;
    }
    
    mmi_wcs_to_asc(edit_text_buf, edit_text);
    
    // traverse all array to get cmd value.
    while(i < text_len)
    {
        if (edit_text_buf[i] == 'X')
        {
            start_idx = i + 1;
        }
        else if (edit_text_buf[i + 1] == '-' || edit_text_buf[i + 1] == '\0' || edit_text_buf[i + 1] == ' ')
        {
            end_idx = i;
        }
        
        if (start_idx <= end_idx && end_idx < text_len && edit_text_buf[start_idx - 1] == 'X' 
            && (edit_text_buf[end_idx + 1] == '\0' || edit_text_buf[end_idx + 1] == '-' || edit_text_buf[end_idx + 1] == ' '))
        {
            if (MMI_FALSE == mmi_em_dev_fmr_ctohex_u8(&edit_text_buf[start_idx], end_idx - start_idx + 1, &cmd[j]))
            {
                return MMI_FALSE;
            }

            if (++valib_num == MMI_EM_DEV_VAILID_NUM_PRE_LINE && edit_text_buf[end_idx + 1] == '-' || end_idx - start_idx + 1 > 2)
            {
                return MMI_FALSE;
            }

            end_idx++;

            start_idx = end_idx;
            j++;
        }
        i++;
    }
    
    return (MMI_BOOL)(j == cmd_len);
}


static MMI_BOOL mmi_em_dev_fmr_set_cmn_cmd(mmi_id scrn_id)
{
     U32 i;
     WCHAR edit_text_buf[MMI_EM_DEV_FMR_CMD_EXIT_STR_MAX_LEN] = {0};
     
     
     // 5 indicate there are 5 edit items, if any item edit is not right, return MMI_FALSE
     for (i = 0; i < 5; i++)
     {
         cui_inline_get_value(scrn_id, MMI_EM_DEV_FMR_INLINE_ITEM2 + i, (void *)edit_text_buf);

         if (mmi_wcslen(edit_text_buf) > (MMI_EM_DEV_FMR_CMD_EXIT_STR_MAX_LEN - 1))
             return MMI_FALSE;

         if (!mmi_em_dev_fmr_cmd_convert_format_cmd(edit_text_buf, &g_fm_radio_cntx->cmd_param[i * 4], 4))
             return MMI_FALSE;
     }
     
     FMR_Set_Param(g_fm_radio_cntx->cmd_param, 20);
     return MMI_TRUE;
}

static void mmi_em_dev_fmr_enter_output_scrn(void)
{
    U8 *cmd;
    U32 idx;
    U32 str_len;
    U8 cmd_param[20] = {0};
    WCHAR scrn_content[110] = {0};
    mmi_em_text_viewer_struct cntx = {0};
    
    
    FMR_Get_Param(cmd_param);
    // Initial output screen content
    // Total the number of cmd is 20. And every edit item only display 4 value.
    // so need 5 edit item to input cmd value. And display screen need 5 line to
    // show all value
    for (idx = 0; idx < 5; idx++)
    {
       cmd = cmd_param + idx * 4;
       str_len = mmi_wcslen(scrn_content);
       kal_wsprintf(scrn_content + str_len, "0X%-2x-0X%-2x-0X%-2x-0X%-2x\n", *cmd, *(cmd + 1), *(cmd + 2), *(cmd + 3));
    }
    
    scrn_content[mmi_wcslen((const WCHAR*)scrn_content)] = '\0';
    
    cntx.title_id = STR_ID_EM_DEVICE_FM_RADIO_COMN_CMD_OUTPUT;
    cntx.text     = scrn_content;
    
    mmi_em_show_text_viewer(&cntx);
}


// main menu select event handler
mmi_ret mmi_em_dev_fmr_menu_sel_event_hdlr(mmi_menu_id menu_id)
{
    switch (menu_id)
    {
        case MENU_ID_EM_DEVICE_FM_RADIO_STATUS:
            mmi_em_dev_fmr_set_fre_scrn();
            break;
    #ifndef __MMI_SLIM_ENGINEER_MODE__
        case MENU_ID_EM_DEVICE_FM_RADIO_THOSRHELD:
            mmi_em_dev_fmr_enter_ant_edit_scrn();
            break;
    #endif /* __MMI_SLIM_ENGINEER_MODE__ */
        case MENU_ID_EM_DEVICE_FM_RADIO_COMN_CMD:
            mmi_em_dev_fmr_enter_cmn_cmd_scrn();
            break;
            
        default:
            break;
    }
    
    return MMI_RET_OK;
}

#endif /*__MMI_EM_DEV_FM_RADIO__*/


#define EM_DEV_CAM_AF_CONTSHOT
/*-----------------------------------------------------------------------------*/
/* --------------------------  Device -> Cam AF test ------------------------- */
/*-----------------------------------------------------------------------------*/
#if defined(__MMI_EM_CAM_AF_CONTSHOT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef AAA_ENGINEER_MODE
/* under construction !*/
#else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_EM_CAM_HORIZONTAL_CAMERA__) && defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_EM_CAM_HORIZONTAL_CAMERA__) && defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_EM_CAM_HORIZONTAL_CAMERA__) && defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_EM_CAM_HORIZONTAL_CAMERA__) && defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef RAW_MAIN_CAMERA
/* under construction !*/
    #else
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __COSMOS_MMI__
/* under construction !*/
    #else
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else
/* under construction !*/
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
    #ifdef RAW_MAIN_CAMERA    
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
    #if 0
/* under construction !*/
/* under construction !*/
    #else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if 1
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if defined(__MMI_EM_CAM_HORIZONTAL_CAMERA__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if 1
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if defined(__MMI_EM_CAM_HORIZONTAL_CAMERA__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
/* under construction !*/
/* under construction !*/
#endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __COSMOS_MMI__
/* under construction !*/
#else
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
#ifdef __COSMOS_MMI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MDI_CAMERA_FD_SUPPORT__)
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
#if defined(__MMI_EM_CAM_HORIZONTAL_CAMERA__) && defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__)
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
        #ifdef RAW_MAIN_CAMERA
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
#if defined(__MMI_EM_CAM_HORIZONTAL_CAMERA__)
/* under construction !*/
/* under construction !*/
#else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __COSMOS_MMI__    
/* under construction !*/
#else
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
#if defined(__MMI_EM_CAM_HORIZONTAL_CAMERA__)
/* under construction !*/
/* under construction !*/
#else
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
/* under construction !*/
/* under construction !*/
#if defined(__MMI_EM_CAM_HORIZONTAL_CAMERA__)
/* under construction !*/
#endif
/* under construction !*/
#ifdef GDI_USING_LAYER_BACKGROUND
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __COSMOS_MMI__    
/* under construction !*/
    #else
/* under construction !*/
/* under construction !*/
    #endif    
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef RAW_MAIN_CAMERA
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #else
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
    #ifdef RAW_MAIN_CAMERA
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SUBLCD__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SUBLCD__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_AUDIO_REVERB_EFFECT__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_AUDIO_REVERB_EFFECT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_TARGET__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_EM_CAM_HORIZONTAL_CAMERA__)
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
#ifdef __MTK_TARGET__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_TARGET__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __COSMOS_MMI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __COSMOS_MMI__
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
#ifdef __MMI_AUDIO_REVERB_EFFECT__
/* under construction !*/
#endif /* __MMI_AUDIO_REVERB_EFFECT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SUBLCD__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SUBLCD__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SUBLCD__
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MTK_TARGET__
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __COSMOS_MMI__
/* under construction !*/
        #else
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
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_TARGET__ */
/* under construction !*/
    #ifndef __COSMOS_MMI__
/* under construction !*/
/* under construction !*/
    #else
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
        #ifdef __COSMOS_MMI__
/* under construction !*/
        #else
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
#ifdef __COSMOS_MMI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0
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
#endif /* defined(__MMI_EM_CAM_AF_CONTSHOT__) */

#define EM_MISC_VIDEO_HIGH_BITRATE
/*-----------------------------------------------------------------------------*/
/* -----------------------  Misc -> Video High Bitrate ----------------------- */
/*-----------------------------------------------------------------------------*/
#if defined(__MMI_EM_MISC_VIDEO_HI_BITRATE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__MMI_EM_MISC_VIDEO_HI_BITRATE__) */ 


#define EM_MISC_JAVA_HEAP_SIZE
/*-----------------------------------------------------------------------------*/
/* -------------------------  Misc -> JAVA Heap Size ------------------------- */
/*-----------------------------------------------------------------------------*/
#if defined(__MMI_EM_JAVA_HEAP_SIZE_SETTING__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_EM_JAVA_HEAP_SIZE_SETTING__ */


#if defined (__MMI_EM_MISC_JUI_DEBUG__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  /* __MMI_EM_MISC_JUI_DEBUG__ */

void mmi_em_misc_multi_media_menu_event_hdlr(cui_menu_event_struct *event)
{
#ifdef __MMI_EM_JAVA_HEAP_SIZE_SETTING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
    switch(event->highlighted_menu_id)
    {
	default:
		break;
    }
}

#if (defined(COSMOS_EM_INTERNAL_DCM) || defined(PLUTO_EM_INTERNAL_DCM))
#pragma arm section rodata , code
#endif /* COSMOS_EM_INTERNAL_DCM || PLUTO_EM_INTERNAL_DCM */ 

/**************************************************************
**  FUNCTION NAME       : EMFMRadioSendRes
**
**  PURPOSE             : FM Radio send request response function. 
**
**  INPUT PARAMETERS    : nil
**
**  OUTPUT PARAMETERS   : void
**
**  RETURNS             : void
**
**  REMARKS         : 
**************************************************************/
void EMFMRadioSendRes(void* inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_success_popup();
    mdi_audio_stop_fmr();
}


#endif /* __MMI_ENGINEER_MODE__ */
