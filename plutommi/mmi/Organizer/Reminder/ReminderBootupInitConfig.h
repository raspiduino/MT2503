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
 *  ReminderBootupInitConfig.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Alarm powern-on bootup init table
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * Please declare your initialization handler here rather the framework's table.
 * DO NOT include any header file or declare any function prototype here,
 * we will generate them for applications. That is, the only thing you have to do
 * is, adding an entry with your compile option:
 *
 * #ifdef __MMI_MYAPP__
 *     MMI_BOOTUP_INIT_REG(mmi_myapp_init)
 * #endif
 *
 * Its prototype should be:
 *  mmi_ret mmi_myapp_init(mmi_event_struct *evt)
 * But you don't need to declare it here.
 *
 * MMI_BOOTUP_ALM_INIT_ADP() is an adaptor only for old void (*)(void) initalization
 * functions, newly-added code should register by MMI_BOOTUP_INIT_REG().
 *
 * ----------------------------------------------------------------------------
 * You can modify and check in this file by yourself, and do not need to inform
 * alarm bootup owner.
 * ----------------------------------------------------------------------------
 */

/* ------------------------------------------------------------
 *  [Reminder bootup Init]
 *  Framework or services required by other applications' init
 *  These procs will be called right after power on.
 * ------------------------------------------------------------ */
MMI_BOOTUP_INIT_REG_BEGIN(EVT_ID_SRV_REMINDER_BOOTUP_INIT)
	MMI_BOOTUP_INIT_ADP(applib_dt_init_time)
#ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
	MMI_BOOTUP_INIT_ADP(InitUnicodeSupport)
#endif
	MMI_BOOTUP_INIT_ADP(PhnsetReadGPIOSetting)
	MMI_BOOTUP_INIT_ADP(srv_backlight_init_context_early)
	MMI_BOOTUP_INIT_ADP(mdi_audio_init)
	MMI_BOOTUP_INIT_ADP(mmi_fe_init)
	MMI_BOOTUP_INIT_ADP(InitFramework)/* Initialize framework */
	MMI_BOOTUP_INIT_ADP(InitHardwareEvents)
	MMI_BOOTUP_INIT_ADP(setup_UI_wrappers)
	MMI_BOOTUP_INIT_ADP(PopulateResData)
	MMI_BOOTUP_INIT_ADP(PowerAndEndKeyHandler)	/* deepali */
	MMI_BOOTUP_INIT_ADP(initialize_UI_demo)
	MMI_BOOTUP_INIT_ADP(InitChargerPwrOn)
	MMI_BOOTUP_INIT_ADP(srv_prof_init)
	MMI_BOOTUP_INIT_ADP(InitSettingNVRAM)
 
#ifdef __MMI_USB_SUPPORT__
	MMI_BOOTUP_INIT_ADP(InitMMIUsbContext)
#endif 
	MMI_BOOTUP_INIT_ADP(mdi_audio_init_event_hdlrs)
	MMI_BOOTUP_INIT_REG(srv_reminder_init)		
#ifdef __MMI_THEMES_APPLICATION__
	MMI_BOOTUP_INIT_ADP(InitThemes)
#endif 
	MMI_BOOTUP_INIT_ADP(initialize_mainmenu_title_icons)/*for GetRootTitleIcon*/
MMI_BOOTUP_INIT_REG_END(EVT_ID_SRV_REMINDER_BOOTUP_INIT)


