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
 * FactoryModeProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file define function that be called by many files of FM and structure, enum ...
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
 * removed!
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

#ifndef _FACTORY_MODE_PROT_H
#define _FACTORY_MODE_PROT_H

#include "MenuCuiGprot.h"
#include "MMIDataType.h"
#include "FactoryModeConfig.h"
#include "fmt_struct.h"
//#include "TouchScreenGprot_Int.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
#include "custom_fm.h"

#if defined(__MMI_FM_NFC_SUPPORT__)
#include "FactoryModeNFC.h"
#endif

/***************************************************************************** 
* typedef enum/struct/...
*****************************************************************************/
/* ===== Audio test status ======= */
typedef enum
{
    FM_AUDIO_TEST_STAT_NONE,
    FM_AUDIO_TEST_STAT_ECHOLOOP,
    FM_AUDIO_TEST_STAT_RINGTONE,
    FM_AUDIO_TEST_STAT_RECEIVER
} FM_AUDIO_TEST_STAT_ENUM;

/*keypad test*/
#ifdef __MMI_FM_KEYPAD_TEST__
typedef struct
{
    U32 key_pressed_flag[FM_KEYPAD_KEY_PRESSED_FLAG_LEN];
    U16 key_test_string[1];
} mmi_fm_keypad_test_context_struct;
#endif  /*__MMI_FM_KEYPAD_TEST__*/

/* MTBF */
typedef enum
{
    MMI_FM_TONE_ACT_PLAY,
    MMI_FM_TONE_ACT_STOP,
    MMI_FM_TONE_ACT_MAX_ITEM
} mmi_fm_tone_act_enum;

/* parallel line test & NxM point test */
#if defined(__MMI_TOUCH_SCREEN__)
typedef enum
{
    INVALID_TEST = 0,
    PARALLEL_TEST_1,    /* \\ */
    PARALLEL_TEST_2     /* // */
} parallel_test_type;

#endif

/* Radio */
#ifdef __MMI_FM_RADIO__
typedef struct {
    U16      text_id;
    U16      Currfreq;
    U8       CurrVolume;
    U8       is_FMRDO_on;
} fm_fm_radio_struct;
#endif

/* common */
typedef void (* mmi_fm_select_func)(cui_menu_event_struct *evt);
typedef void (* mmi_fm_highlight_func)(cui_menu_event_struct *evt);
typedef void (* mmi_fm_enter_func)(cui_menu_event_struct *evt);

#define FM_SETTINGINFO 0
#define FM_RESULTINFO 1

typedef struct
{
    MMI_ID menu_id;
    mmi_fm_select_func select_func;
    mmi_fm_highlight_func highlight_func;  
}mmi_fm_test_item_struct;

typedef struct
{
    MMI_ID menu_id;
    mmi_fm_enter_func enter_func;
}mmi_fm_entry_test_item_struct;

/*--------Version---------*/
typedef struct
{
    U8 gBarCodeReadFlag ;
    U8 gBarCode[MAX_SUB_MENU_SIZE];
   
    #ifdef __GADGET_SUPPORT__
    CHAR UnicodeDisplayBuf[MAX_TEST_STRING_BUF * 6];
    #else
    CHAR UnicodeDisplayBuf[MAX_TEST_STRING_BUF * 5];
    #endif   /* __GADGET_SUPPORT__ */
}mmi_fm_version_struct;


/*--------Viberate---------*/
typedef struct
{
   U8 vib;
   U8 vib_status;
}mmi_fm_viberate_struct;

/*------- LoudSpk ---------*/
typedef struct
{
    MMI_BOOL LoudSpkTestOn;
}mmi_fm_loudspk_struct;

/*-------- keypad --------*/
typedef struct
{
    U8 InkeyTestingScreen;
}mmi_fm_keypad_struct;

/*-------- ADC ----------*/
typedef struct
{
    U8 gFM_MenuItemNum;
}mmi_fm_adc_struct;

/*-------- RTC -----------*/
typedef struct
{
    U8 gFactoryAlarm;  
}mmi_fm_rtc_struct;

/*-------- MTBF----------- */
typedef struct
{
    U32 MTBF_counter;    /* for MTBF */
    FM_MTBF_LCD_ENUM MTBF_state_LCD;
    FM_MTBF_LED_ENUM MTBF_state_LED;
    FM_MTBF_VIB_ENUM MTBF_state_VIB;
    FM_MTBF_AUD_ALTERNATION_ENUM AUD_TEST_ON;
}mmi_fm_mtbf_struct;

/*-------------------- Memory card ---------------- */
#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__))
typedef struct
{
    mmi_fmt_get_msdc_status_rsp_strcut FM_Card_Status;
    BOOL Card_Response_Received ;
    BOOL Card_Response_Sent ; 
    CHAR CardType[32];
}mmi_fm_memcard_struct;
#endif

/*--------------- parallel line test------------------*/

/* N Cross M Points Test */
#ifdef __MMI_TOUCH_SCREEN__
#define TOUCH_N_ROWS 4  /* Number of Rows of Points */
#define TOUCH_N_COLS 5  /* Number of Columns of Points */
#define IMAGE_HIDE      0       /* Hide image of Point */
#define IMAGE_SHOW      1       /* Show image of Point */
// TODO: dynamic compute margin
#define TOUCH_ROW_MARGIN   30   /* Horizontal Margin between points */
#define TOUCH_COL_MARGIN   15   /* Vertical Margin between points */
#endif


#if defined(__MMI_TOUCH_SCREEN__)
typedef struct
{
    /* Previous point in pen test program */
    mmi_pen_point_struct gFMPenPreviousPoint;

    /* Capture pen events by test drawing program */
    BOOL gFMPenTestCapture ;

    /* Line color */
    color gFMPenLineColor;
    S16 gFMPenParallel_test_type ;
    S16 gFMPenParallel_first_x1;
    S16 gFMPenParallel_first_y1;
    S16 gFMPenParallel_first_x2;
    S16 gFMPenParallel_first_y2;
    S16 gFMPenParallel_second_x1;
    S16 gFMPenParallel_second_y1;
    S16 gFMPenParallel_second_x2;
    S16 gFMPenParallel_second_y2;
    S16 gFMPenParallel_first_point_x;    /* Starting point's x */
    S16 gFMPenParallel_first_point_y;    /* Starting point's y */
    S16 gFMPenParallel_second_point_x;   /* End point's x */
    S16 gFMPenParallel_second_point_y;   /* End point's y */
    BOOL gFM_pen_test_start_from_top;
  
    S16 gFMPenNByMStartx;
    S16 gFMPenNByMStarty;
    S32 gFMPenNByMImageHeight;   /* Point Image's height */
    S32 gFMPenNByMImageWidth;    /* Point Image's width */
    S16 gFMPenNByMStatus[TOUCH_N_ROWS][TOUCH_N_COLS];    /* Show hide point status */
    U8 addtohistory;    /* Parallel Test screen need's to be added in History */
}mmi_fm_parallelline_NxMpoint_struct;
#endif

/*------------------- Radio ---------------------*/
#ifdef __MMI_FM_RADIO__
typedef struct
{
    fm_fm_radio_struct g_fm_fm_radio_cntx;
    U8 FmcurrentHighlightIndex;
}mmi_fm_radio_struct;
#endif

/*---------------- UART ------------------------*/

#ifdef __MMI_FM_UART_TEST__
typedef struct
{
   BOOL UART_Response_Received; 
}mmi_fm_uart_struct;
#endif /*__MMI_FM_UART_TEST__*/


/*------------------Eachloop---------------------------*/
typedef struct
{
    MMI_BOOL EchoLoopTestOn;     /* Echo Loop */
    BOOL ReceiverTestOn;     /* Receiver */
    BOOL HeadsetTestOn;      /* Headset Test */
    BOOL RingToneTestOn;     /* RingTone */
    U8 g_FM_AUDIO_TEST_STATUS ; 
}mmi_fm_eachloop_struct;


/*---------------------- LED -----------------------------*/
typedef struct
{
    U32 sequence_counter; 
    U32 FM_LEDState; 
    U32 gFM_HighlightIdx;
}mmi_fm_led_struct;


/*---------------------- common --------------------------*/
typedef struct
{
    CHAR EMFMUnicodeDisplayBuf[MAX_TEST_STRING_BUF * 2];  /* display buffer */
    U8 EMFMAsciiDisplayBuf[MAX_TEST_STRING_BUF]; 
    U8 sequence_counter; /* for auto display action use */ 
    U8 MenuData[MAX_SUB_MENUS][MAX_SUB_MENU_SIZE];
    U8 autoTestMode;
    U8 NeedExitFunc;
    S16 currTestItem;
    BOOL TestExecuted[MAX_AUTO_TEST_ITEMS];
    U8 currentTest;
}mmi_fm_common_struct;

#ifdef __MMI_FM_DUAL_MIC_ECHO_LOOP__
/*-------------------- 2micnr ---------------------------- */
typedef struct
{
    U8  two_micnr_audio_mode_enum;
    kal_bool two_micnr_test; /* KAL_TRUE is on in the status not the softkey, KAL_FALSE is off*/
    kal_bool disable_2micnr_test; /* KAL_TRUE is on in the status not the softkey, KAL_FALSE is off*/
} mmi_fm_2micnr_struct;
#endif

/*------------------ FM context structure ---------------------------*/
typedef struct
{
    mmi_fm_version_struct      version_contxt;
    mmi_fm_viberate_struct     viberate_contxt;
    mmi_fm_loudspk_struct      loudspk_contxt;
    mmi_fm_keypad_struct       keypad_contxt;
    mmi_fm_adc_struct          adc_contxt;
    mmi_fm_rtc_struct          rtc_contxt;
    mmi_fm_mtbf_struct         mtbf_contxt;

#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__))
    mmi_fm_memcard_struct      memcard_contxt;
#endif

#if defined(__MMI_TOUCH_SCREEN__)
    mmi_fm_parallelline_NxMpoint_struct parallelline_NxMpoint_contxt;
#endif

#ifdef __MMI_FM_RADIO__
    mmi_fm_radio_struct        radio_contxt;
#endif

#ifdef __MMI_FM_UART_TEST__
    mmi_fm_uart_struct         uart_contxt;
#endif

    mmi_fm_eachloop_struct     eachloop_contxt; 

    mmi_fm_led_struct          led_contxt;
        
    mmi_fm_common_struct       common_contxt;

#if defined(__MMI_FM_NFC_SUPPORT__)
    mmi_fm_nfc_struct           nfc;
#endif

#ifdef __MMI_FM_DUAL_MIC_ECHO_LOOP__
    mmi_fm_2micnr_struct        two_micnr;
#endif

}mmi_fm_item_cntxt_struct;



/***************************************************************************** 
* extern function
*****************************************************************************/
/* ----- Version ------ */
/* version select entry */
extern void mmi_fm_select_version_summary_menu(void);
/* version highlight entry */
extern void mmi_fm_version_menu_item_highlight(cui_menu_event_struct *evt);

/* --------Res_bin---------- */
/* res_bin highlight entry */
extern void mmi_fm_res_bin_show_hint(cui_menu_event_struct *evt);

/* ---------echo_loop--------------- */
/* echo_loop select entry */
extern void mmi_fm_select_echo_loop(void);
/* echo_loop highlight entry */
extern void mmi_fm_echo_loop_highlight(void);

#ifdef __ACOUSTIC_LOOPBACK_SUPPORT__
extern void mmi_fm_select_acoustic_loopback(void);
extern void mmi_fm_highlight_acoustic_loopback(void);
#endif

#ifdef __MMI_FM_DUAL_MIC_ECHO_LOOP__
extern void mmi_fm_select_echo_loop2(void);
extern void mmi_fm_highlight_echo_loop2(void);
extern void mmi_fm_select_2micnr_test(void);
extern void mmi_fm_highlight_2micnr_test(void);
/* ---------disable_2micnr_test--------------- */
/* disable_2micnr_test select entry */
extern void mmi_fm_select_disable_2micnr_test(void);
/* mmi_fm_disable_2micnr_test_highlight highlight entry */
extern void mmi_fm_highlight_disable_2micnr_test(void);
#endif

#ifdef __MMI_FM_KEYPAD_TEST__
extern void mmi_fm_select_keypad_test(void);
#endif

/* -------------- Vibrator ------------------ */
extern void mmi_fm_select_vibrator(cui_menu_event_struct *evt);
extern void mmi_fm_vibrator_highlight(void);

/* ---------------- loudspeaker ------------------------- */
extern void mmi_fm_select_loud_spk(cui_menu_event_struct *evt);
extern void mmi_fm_loud_spk_highlight(void);

/* ----------------- Ringtone ---------------------- */
extern void mmi_fm_select_ring_tone(void);
extern void mmi_fm_ring_tone_highlight(void);
extern void FM_SendPlayAudioReq(U8 index);

/* ------------------ LED ----------------------- */
extern void mmi_fm_select_led(cui_menu_event_struct *evt);
extern void mmi_fm_led_highlight(cui_menu_event_struct *evt);

/* ------------------ LCD ----------------------- */
extern void mmi_fm_lcd_highlight(void);
extern void mmi_fm_select_certain_lcd_test(cui_menu_event_struct *evt);
extern void FM_HandleInitialColor(U8 color_r, U8 color_g, U8 color_b);   /*MTBF ,LCD */
extern void mmi_fm_show_color(S32 type) ; /* LCD , AT cmd LCD test */
extern void mmi_fm_handle_color_set_change(void);

/* ------------------- Receiver ----------------------- */
extern void mmi_fm_select_receiver_hdlr(void);
extern void mmi_fm_highlight_receiver_hdlr(void);

/*--------------------- ADC -----------------------*/
extern void mmi_fm_select_adc_menu(void);

/*----------------------- Charger ------------------------*/
extern void mmi_fm_select_charger_hdlr(void);

/* ---------------- headset ----------------------- */
extern void mmi_fm_select_headset(void);
extern void mmi_fm_highlight_headset(void);

/* ---------------- RTC ----------------------- */
extern void mmi_fm_select_rtc(void);

/* ---------------- mtbf ----------------------- */
#ifdef __MMI_FM_MTBF__
extern void mmi_fm_select_mtbf(void);
#endif
extern void mmi_fm_stop_MTBF_tone(void);
extern void mmi_fm_back_to_normal_state(void);

/* ---------------- memory card ----------------------- */
#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__)) 
extern void mmi_fm_select_memory_card(void);
#endif
extern void FM_MemoryCardReq(void);

/* ---------------- Nand flash ----------------------- */
extern void mmi_fm_select_nand_flash(void);

#if defined(__MMI_FM_CAMERA_PREVIEW__)
extern void mmi_fm_camera_entry_preview_screen(void);
extern void mmi_fm_close_camera(void);
#endif

/* ----parallel line test & NxM point test-------- */
#if defined(__MMI_TOUCH_SCREEN__)
extern void mmi_fm_select_pen_parallel_test(void);
extern void mmi_fm_select_pen_n_cross_test(void);
extern void FM_AutoTest_Pen_N_Cross_M_Test(void);
#endif

/* ---- FM radio -------- */
extern void mmi_fm_select_radio_test(cui_menu_event_struct *evt);
extern void mmi_fm_highlight_radio_menu(void);

/* ---- MATV -------- */
extern void mmi_fm_select_atv(void);
extern void mmi_fm_highlight_atv(void);

/* -------Touch panel--------- */
#ifdef  __MMI_FM_TOUCH_PANEL_ACCURACY_TEST__
extern void mmi_fm_touch_panel_entry(void);
#endif

/* -------Dual Touch Calibration--------- */
#ifdef __TOUCH_PANEL_MULTITOUCH__
extern void mmi_fm_dual_touch_calibr_entry(void);
#endif


#ifdef __MMI_FM_PXS_SENSOR__
extern void mmi_fm_enter_pxs(void);
#endif

/* --------------AUTO test setting------------ */
#ifdef __MMI_FM_AUTO_TEST__
extern void mmi_fm_select_auto_test_setting(void);
extern void mmi_fm_ReadSettingsFromNVRAM(U8 Type);
extern void FM_Autotest_set_key_handlers(U8 is_reg_sendkey);
extern void FM_Autotest_test_done_USC2string(const CHAR *name);
#endif

/* --------------- UART test (phase out) -------------------------- */
#ifdef __MMI_FM_UART_TEST__
extern void mmi_fm_select_uart(void);
#endif


/*------ version per hint ------*/
extern void mmi_fm_version_pre_hint(cui_menu_event_struct *evt);

/* For TC01_CAMERA_TEST */
#if defined(__MMI_FM_TC01_CAMERA_TEST__)
extern void mmi_fm_camera_test_entry_cam_test(void);
#endif

/* AT cmd */
extern void mmi_fm_at_entry_menu_hdlr(void *inMsg);
extern void mmi_fm_at_keypad_test_hdlr(void *inMsg);
extern void mmi_fm_at_lcd_test_msg_hdlr(void *inMsg);

/*FactoryModeUtil.c  */
extern void mmi_fm_common_set_left_softkey(U32 item);
extern void mmi_fm_set_general_goback_function(void);


/*---------- Send Message --------------*/
extern void FM_SendADCStopReq(void);
extern void FM_SendSetAudioModeReq(U8 mode);
extern void FM_SendMsg(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr);


/* -------------- FactoryMode init ---------------- */
extern void mmi_fm_init_mem_contxt(void);


/* For AT cmd Read quick test report*/
extern void mmi_fm_quick_test_report(void);

extern void mmi_fm_set_show_color(U8 color_r, U8 color_g, U8 color_b);
extern void mmi_fm_at_lcm_rgb_test_handler(void *ind, int mod_id);


/* -------- Audio util----------- */
extern void mmi_fm_set_loopback(kal_uint32 on, void* arg );
extern void mmi_fm_gpio_start(kal_uint8 port);
extern void mmi_fm_gpio_writeIO(kal_uint8 data, kal_uint8 port);
extern kal_bool mmi_fm_get_melody_version(kal_char *mel_ver);
extern void mmi_fm_set_loopback2(kal_uint32 on, void* arg );
#ifdef __MMI_FM_DUAL_MIC_ECHO_LOOP__
extern void mmi_fm_set_acoustic_loopback(kal_uint32 on, void* arg );
extern void mmi_fm_set_disable_2mic_nr_back(kal_uint32 on, void* arg );
#endif

/* ---------------------------motion sensor------------ */
extern void mmi_fm_motion_sensor_cali(void);



/* get factorymode context to avoid use extern g_fm_contxt  */
/* every item can call this function to get the context */ 
mmi_fm_item_cntxt_struct *mmi_fm_get_context(void);


#endif  /* _FACTORY_MODE_PROT_H */
