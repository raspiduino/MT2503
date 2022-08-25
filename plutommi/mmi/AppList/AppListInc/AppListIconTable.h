/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  AppListIconTable.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Applist
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MMI_APPLIST_ICON_TABLE_H_
#define _MMI_APPLIST_ICON_TABLE_H_

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"
#include "mmi_rp_app_applist_def.h"


typedef struct{
	mmi_app_package_name_struct app_name;
	MMI_ID image_icon;
}mmi_applist_icon_map_struct;


const mmi_applist_icon_map_struct g_mmi_applist_icon_table[]=
{
	{"native.mtk.alarm", IMG_ID_APPLIST_ALARM_ICON},
#if defined(__MMI_AUDIO_PLAYER__)
	{"native.mtk.audioplayer", IMG_ID_APPLIST_APLY_ICON},
#endif
#ifdef __MMI_AZAAN_ALARM__
	{"native.mtk.azaanalarm", IMG_ID_APPLIST_AALARM_ICON},
#endif
#if defined(__MMI_SEARCH_WEB_BAIDU__)
	{"native.mtk.baidu", IMG_ID_APPLIST_BAIDU_ICON},
#endif
#ifdef __MMI_BT_SUPPORT__
	{"native.mtk.bluetooth", IMG_ID_APPLIST_BT_ICON},
#endif
#if defined(__MMI_CALCULATOR__)
	{"native.mtk.calculator", IMG_ID_APPLIST_CALCULATOR_ICON},
#endif
#if defined(__MMI_CALENDAR__)
	{"native.mtk.calendar", IMG_ID_APPLIST_CALENDAR_ICON},
#endif
#if defined(__MMI_CAMCORDER__)
	{"native.mtk.camcorder", IMG_ID_APPLIST_CAMCORDER_ICON},
#endif
#if defined (__MMI_CAMERA__)
	{"native.mtk.camcera", IMG_ID_APPLIST_CAMERA_ICON},
#endif
	{"native.mtk.connectivity", IMG_ID_APPLIST_CONNECT_ICON},
#if defined(__MMI_CURRENCY_CONVERTER__)
	{"native.mtk.currencyconverter", IMG_ID_APPLIST_CURRENCY_ICON},
#endif
#ifdef __MMI_EBOOK_READER__
	{"native.mtk.ebook", IMG_ID_APPLIST_EBOOK_ICON},
#endif
	{"native.mtk.email", IMG_ID_APPLIST_EMAIL_ICON},
	{"native.mtk.filemgr", IMG_ID_APPLIST_FMGR_ICON},
#ifdef __MMI_FM_RADIO__
	{"native.mtk.fmrdo", IMG_ID_APPLIST_FMRDO_ICON},
#endif
#if defined(__MMI_BMI__) || defined(__MMI_MENSTRUAL__)
	{"native.mtk.health", IMG_ID_APPLIST_HEALTH_ICON},
#endif
	{"native.mtk.imageviewer", IMG_ID_APPLIST_IVIEWER_ICON},
	{"native.mtk.funandgames", IMG_ID_APPLIST_JAVA_ICON},
	{"native.mtk.mediaplayer", IMG_ID_APPLIST_MPLYER_ICON},
#if defined(__MMI_ATV_SUPPORT__)
	{"native.mtk.mobiletvplayer", IMG_ID_APPLIST_MTV_ICON},
#endif
#ifdef __MMI_NOTE_APP__
	{"native.mtk.note", IMG_ID_APPLIST_NOTE_ICON},
#endif
#ifdef __MMI_TELEPHONY_SUPPORT__
	{"native.mtk.phonebook", IMG_ID_APPLIST_PHB_ICON},
	{"native.mtk.messaging", IMG_ID_APPLIST_MESSAGE_ICON},
	{"native.mtk.calllog", IMG_ID_APPLIST_CLOG_ICON},
	{"native.mtk.dialer", IMG_ID_APPLIST_DIALER_ICON},
#endif /* __MMI_TELEPHONY_SUPPORT__ */
#ifdef __SYNCML_SUPPORT__
	{"native.mtk.syncmldevice", IMG_ID_APPLIST_PSYNC_ICON},
	{"native.mtk.syncmlremote", IMG_ID_APPLIST_SYNC_ICON},
#endif
#ifdef __MMI_PHOTOEDITOR__
	{"native.mtk.photoeditor",IMG_ID_APPLIST_PEDITOR_ICON},
#endif
	{"native.mtk.profile", IMG_ID_APPLIST_PROFILES_ICON},
	{"native.mtk.setting", IMG_ID_APPLIST_SETTING_ICON},
	{"native.mtk.services_sat", IMG_ID_APPLIST_SERVICE_ICON},
#ifdef __MMI_APPLIST_BARREL_SUPPORT__
	{"native.mtk.barrel", IMG_ID_APPLIST_BARREL_ICON},
#endif
	{"native.mtk.sndrec", IMG_ID_APPLIST_RECORDER_ICON},
#if defined(__MMI_TODOLIST__)
	{"native.mtk.todo", IMG_ID_APPLIST_TODO_ICON},
#endif
#if defined(__MMI_UNIT_CONVERTER__)
	{"native.mtk.unitconverter", IMG_ID_APPLIST_UCONVERTER_ICON},
#endif
#ifdef __MMI_BROWSER_2__
	{"native.mtk.browser", IMG_ID_APPLIST_BROWSER_ICON},
#endif
	{"native.mtk.wlan", IMG_ID_APPLIST_WIFI_ICON},
#if defined (__MMI_WORLD_CLOCK__)
	{"native.mtk.worldclock", IMG_ID_APPLIST_WCLOCK_ICON},
#endif
	{"native.mtk.ucm", IMG_ID_APPLIST_VCALL_ICON},
#ifdef __SOCIAL_NETWORK_SUPPORT__
	{"native.mtk.sns", IMG_ID_APPLIST_SNS_ICON},
#endif
#if defined(__MMI_VIDEO_PLAYER__)
	{"native.mtk.videoplayer", IMG_ID_APPLIST_VPLY_ICON},
#endif
#if defined(__MMI_3D_GAME_INTERGRAFX__)
    {"native.mtk.3dgame", IMG_ID_APPLIST_3DGAME_ICON},
#endif
    {"native.mtk.opera", IMG_ID_APPLIST_OPERA_ICON},
#if defined(__MMI_VIDEO_RECORDER__)
    {"native.mtk.vdorec", IMG_ID_APPLIST_VREC_ICON},
#endif
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
  {"native.mtk.provbox", IMG_ID_APPLIST_SETTINGMSG_ICON},
#endif
#ifdef __MMI_MOT_SUPPORT__
  {"native.mtk.mot", IMG_ID_APPLIST_MOT_ICON},
#endif
#if defined(__MMI_YOUTUBE_SHORTCUT__)
  {"native.mtk.youtube", IMG_ID_APPLIST_YOUTUBE_ICON},
#endif
#ifdef __MMI_BT_DIALER_SUPPORT__
      {"native.mtk.btdialer", IMG_ID_APPLIST_BT_DIALER_ICON},
#endif
  {"native.mtk.end", 0}
};

const S32 g_mmi_applist_icon_table_len = sizeof(g_mmi_applist_icon_table) / sizeof(mmi_applist_icon_map_struct);


#endif // _MMI_APPLIST_ICON_TABLE_H_

