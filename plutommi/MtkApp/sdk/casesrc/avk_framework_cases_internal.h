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
 *   avk_framework_cases_internal.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *  all AVK cases should include in this file
 *
 * Author:
 * -------
 *Jia Luo (mtk80935)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __AVK_FRAMEWORK_INTERNAL__
#include "avk_pluto_res.cpp"
#include "avk_pluto_font.cpp"
#include "avk_pluto_chset.cpp"
#include "avk_pluto_senario.cpp"
#include "avk_pluto_screen.cpp"
#include "avk_pluto_event.cpp"
#include "avk_pluto_mem.cpp"
#include "avk_pluto_touch.cpp"
#include "avk_pluto_key.cpp"
#include "avk_pluto_string.cpp"
#include "avk_pluto_timer.cpp"
#include "avk_pluto_mutex.cpp"
#include "avk_pluto_queue.cpp"
#include "avk_pluto_nvram.cpp"
#include "avk_cui_edit.cpp"
#include "avk_cui_inline.cpp"
#include "avk_cui_menu.cpp"
#include "avk_pluto_cbmgr.cpp"
#include "avk_pluto_nmgr.cpp"
#include "avk_pluto_appmgr.cpp"
#include "avk_pluto_rotation.cpp"

#include "avk_venus_uiengine.cpp"
#include "avk_v3d_engine.cpp"
#include "avk_venus_fw.cpp"

#include "avk_fw_graphic.cpp"
#include "avk_fw_graphic3d_egl.cpp"

#include "avk_idle_bootup.cpp"
#include "avk_idle_nwinfo.cpp"
#include "avk_idle_nwusa.cpp"
#include "avk_idle_shutdown.cpp"
#include "avk_idle_nwname.cpp"

#include "avk_msg_sms.cpp"
#include "avk_msg_email.cpp"
#include "avk_msg_um.cpp"
#include "avk_msg_mms.cpp"

#include "avk_appsrv_pim_phb.cpp"

#include "avk_call_calllog.cpp"
#include "avk_call_setting.cpp"
#include "avk_call_sim.cpp"
#include "avk_call_ucm.cpp"
#include "avk_call_ss.cpp"
#include "avk_call_cphs.cpp"

#include "avk_mm_camera.cpp"
#include "avk_mm_audio.cpp"
#include "avk_mm_video.cpp"
#include "avk_mm_profile.cpp"
#include "avk_mm_bitstream.cpp"
#include "avk_mm_drm.cpp"

#include "avk_appsrv_fmgr.cpp"

#include "avk_secu_cert.cpp"

#include "avk_setting_alarmtime.cpp"
#include "avk_setting_switchmode.cpp"
#include "avk_setting_DevProfile.cpp"
#include "avk_setting_applib_date_time.cpp"


#include "avk_syssrv_base.cpp"
#include "avk_syssrv_filesys.cpp"
#include "avk_syssrv_fs_async.cpp"

#include "avk_network_cbm.cpp"
#include "avk_network_da.cpp"
#include "avk_network_soc.cpp"
#include "avk_network_wps.cpp"

#include "avk_device_battery.cpp"
#include "avk_device_backlight.cpp"
#include "avk_device_gpio.cpp"
#include "avk_device_usb.cpp"
#include "avk_conn_btds.cpp"
#include "avk_conn_btcm.cpp"
#include "avk_conn_bthfp.cpp"
#include "avk_conn_btopp.cpp"
#include "avk_conn_btspp.cpp"

#include "avk_other_imei.cpp"
#include "avk_other_uriagent.cpp"
#include "avk_other_applib.cpp"
#include "avk_other_xml.cpp"
#endif
