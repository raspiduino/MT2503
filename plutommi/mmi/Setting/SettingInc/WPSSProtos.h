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

/*******************************************************************************
 * Filename:
 * ---------
 *  WPSSProtos.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef WPSSRPROTOS_H
#define WPSSRPROTOS_H

#include "MMI_features.h"
#include "PhoneSetup.h"
#include "mmi_phnset_dispchar.h"
/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "kal_non_specific_general_types.h"
#include "mmi_rp_file_type_def.h"
#include "wgui_inline_edit.h"
#include "menucuigprot.h"
/* auto add by kw_check end */
typedef enum
{
    /* For internal use */
    PHNSET_WP_SS_SET_FILE_LIMIT_CHECK_FAIL = 5, // remember to modify this after add error code in phonesetupgprots.h
    PHNSET_WP_SS_SET_DRM_CHECK_FAIL,
    PHNSET_WP_SS_SET_FILE_NAME_BUF_ALLOC_FAIL,
    PHNSET_WP_SS_SET_PREPARE_FOLDER_FAIL,
    PHNSET_WP_SS_SET_PREPARE_FILE_FAIL,
    PHNSET_WP_SS_SET_GET_DISK_INFO_FAIL,
    PHNSET_WP_SS_UNSUPPORT_TYPE,

    PHNSET_WP_SS_ERROR_ENUM_TOTAL    
} phnset_wp_ss_set_error_internal_enum;


typedef enum
{
    SET_SS_SETTING_INLINE_CAPTION_STATUS,
    SET_SS_SETTING_INLINE_SELECT_OFF,
    SET_SS_SETTING_INLINE_SELECT_ON,
    SET_SS_SETTING_INLINE_SELECT_POWER_SAVING,
    SET_SS_SETTING_INLINE_CAPTION_WAITING,
    SET_SS_SETTING_INLINE_SELECT_5SEC,
    SET_SS_SETTING_INLINE_SELECT_15SEC,
    SET_SS_SETTING_INLINE_SELECT_30SEC,
    SET_SS_SETTING_INLINE_SELECT_1MIN,

    SET_SS_SETTING_INLINE_MAX_ID
} SET_SS_SETTING_INLINE_ENUM;

typedef enum
{
    SET_SS_STATUS_OFF = 0,
    SET_SS_STATUS_ON = 1,
    SET_SS_STATUS_POWERSAVING = 2
} SET_SS_SETTING_STATUS;

extern CHAR mmi_phnset_wallpaper_get_default_driver(void *obj);
extern void mmi_phnset_wallpaper_get_default_folder(void *obj, WCHAR *buffer, U8 buffer_len);
extern void mmi_phnset_wallpaper_get_default_file_prefix(void *obj, WCHAR *buffer, U8 buffer_len);
extern void mmi_phnset_wallpaper_direct_set_file(void* obj, const WCHAR* file_name);
extern void mmi_phnset_wallpaper_set_file(void* obj, const WCHAR* user_file_name, const WCHAR* cache_file_name);

#ifdef __MMI_SUB_WALLPAPER__
extern void mmi_phnset_sub_wallpaper_set_file(void* obj, const WCHAR* file_name);
#endif

extern void mmi_phnset_screensaver_set_file(void* obj, const WCHAR* user_file_name, const WCHAR* cache_file_name);
extern void mmi_phnset_screensaver_direct_set_file(void* obj, const WCHAR* file_name);
extern void mmi_phnset_screensaver_get_default_file_prefix(void *obj, WCHAR *buffer, U8 buffer_len);

extern void mmi_phnset_pwr_on_off_set_file(void* obj, const WCHAR* file_name);

extern WCHAR* mmi_phnset_pwr_on_off_get_user_file(U32 type);
extern U16 mmi_phnset_pwr_on_off_get_static_id(U32 type);
/*
 * Screen Saver
 */
extern void EntryPhnsetScrSvrSystem(MMI_ID parent_gid);
extern void EntryPhnsetScrSvrSysView(void);
extern void mmi_phnset_exit_scrsvr_sys_view(void);
extern void PhnsetScrSvrSysViewLskHdlr(void);
extern PS8 PhnsetGetCurScrSvrFileName(void);
extern void ExitPhnsetScrSvrSysView(void);


extern void PhnsetScrSvrSysHiliteHdlr(S32);
extern void PhnsetDwnlScrSvrHiliteHdlr(S32);
extern U8 PhnsetConstDwnlScrSvrList(U8 **Names, U16 *DLSSImgID, S16 *HligtItem);
extern U8 PhnsetConstSysScrSvrList(U8 **pSysSSStrList, U16 *pSysSSImgIDList, S16 *HighliteItem);

extern void ScreenSaverKeyPressHandler(void);
extern void PhnsetScrSvrInlineHiliteHdlr(S32 nIndex);
extern void PhnsetScrSvrFillInline(InlineItem *);
extern void PhnsetScrSvrSettingLskHdlr(void);
extern void PhnsetRstScrSvrDefault(void);
extern void PhnsetGetScrSvrSetings(U8 *, U8 *);
extern void PhnsetGetCurScrSvr(U16 *);
extern void PhnsetReadNvramScrSvrSettings(void);
extern void ssDecrementCounter(void);
extern void ssIncrementCounter(void);
extern void setScreenSaverPopupTimeout(void);
extern void DeleteScreenSaverViewHistory(void);
extern PS8 PhnsetGetCurScrSvrName(void);
extern PS8 PhnsetGetScrSvrNameById(U16);
extern void viewScreenSaver(void);
extern SET_SS_SETTING_STATUS PhnsetGetCurScrSvrStatus(void);
extern void PhnsetScrSvrSysViewPre(void);
extern void PhnsetScrSvrSysViewNext(void);
extern void UpdateDeletedImageScreenSaver(U16);
extern BOOL PhnsetIsScrSvrAnalogClock(void);
extern BOOL PhnsetIsScrSvrDigitalClock(void);
extern BOOL PhnsetIsScrSvrPartialOn(void);
extern BOOL PhnsetIsScrSvrCurrentTheme(void);
extern BOOL PhnsetIsWPCurrentTheme(void);
extern void EntryPhnsetScrSvrDwnlView(void);
extern void PhnsetScrSvrDwnlViewLskHdlr(void);
extern void ExitPhnsetScrSvrDwnlView(void);
extern void PhnsetScrSvrDwnlViewNext(void);
extern void PhnsetScrSvrDwnlViewPre(void);

extern void InitScreenSaver(void);
extern void HintPhnsetScreenSaver(void);
extern void HintPhnsetScrSvrSetting(void);
extern void HintPhnsetScrSvrSelect(void);
extern S32 PhnsetScreenSaverBadFileCallBack(U16 StrID);
extern void PhnsetScrSvrSelectFmgrCallBack(void *path, int is_short);
extern void PhnsetSetScrSvrByFileName(CHAR *path);


/*
 * Wallpaper
 */
extern void HintPhnsetWallpaper(void); 

#if 0
#ifdef __MMI_AVATAR__
/* under construction !*/
#endif
#endif

#ifdef __MMI_SUB_WALLPAPER__
extern void HintPhnsetSubWallpaper(void);
#endif 
#if 0
#ifdef __DAILY_WALLPAPER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __DAILY_WALLPAPER__ */ 
/* under construction !*/
#endif /* __DAILY_WALLPAPER__ */ 
#else
extern U16 PhnsetGetCurWallPaperIdx(void);
#endif
extern void EntryPhnsetWallpaperSys(MMI_ID parent_gid);
extern void PhnsetWallpaperSysHiliteHandler(S32 nIndex);
extern void EntryPhnsetWallpaperSysView(void);
#ifndef __MMI_PHNSET_WP_SLIM__ 
extern void PhnsetWallpaperSysViewPre(void);
extern void PhnsetWallpaperSysViewNext(void);
#endif
extern void ExitPhnsetWallpaperSysView(void);
extern void PhnsetWallpaperSet(void);
extern void ThemeManagerSetWallpaper(U16);
extern void ThemeManagerSetScreensaver(U16);
extern void PhnsetRstWallpaperDefault(void);
extern void PhnsetRstSubWallpaperDefault(void);
extern void PhnsetReadWallpaper(void);
extern PS8 PhnsetGetCurWallpaperName(void);
#ifdef __MMI_PHNSET_APPICON_SUPPORT__
extern void mmi_phnset_appicon_init(void);
extern void mmi_phnset_appicon_setting_view_lsk(void);
extern void mmi_phnset_appicon_setting_exit_preview(void);
extern void mmi_phnset_appicon_set_hint(void);
extern void mmi_phnset_appicon_complete_active(MMI_BOOL result);
#endif

#ifdef __MMI_SUB_WALLPAPER__
extern PS8 PhnsetGetCurSubWallpaperName(void);
#endif 
extern PS8 PhnsetGetWallpaperNameById(U16 Id);
extern void UpdateDeletedImageWallpaper(U16 ImageId);
extern void InitWallpaper(void);
extern void PhnsetWallpaperBadFileCallBack(U16 imgID);
extern void PhnsetWallpaperSubBadFileCallBack(U16 imgID);

extern void PhnsetSetWallpaperByImgID(U16 imgID);
#if 0
#if  !defined(__MMI_PHNSET_AT_DISABLE__)||defined(__DAILY_WALLPAPER__)
/* under construction !*/
#endif
#else
#if  !defined(__MMI_PHNSET_AT_DISABLE__)
extern BOOL PhnsetSetDisplayFromAT(U8 idx, U8 type);
#endif
#endif

#ifdef __MMI_POWER_ON_OFF_DISPLAY__
extern void PhnsetReadPwrOnOffDisp(void);
extern void HintPhnsetPwrOnDisplay(void);
extern void HintPhnsetPwrOffDisplay(void);
extern void EntryPhnsetPowerOnOffSys(MMI_ID parent_gid);
extern void EntryPhnsetPwrOnOffSysView(void);
extern void PhnsetPwrOnOffSysViewPre(void);
extern void PhnsetPwrOnOffSysViewNext(void);
extern void PhnsetPowerOnOffSysHiliteHandler(S32 nIndex);
extern void PhnsetGetPwrOnDisp(U16 *id);
extern PS8 PhnsetGetPwrOnFileName(void);
extern void PhnsetGetPwrOffDisp(U16 *id);
extern PS8 PhnsetGetPwrOffFileName(void);
extern void PhnsetRstPwrOnDisplayDefault(void);
extern void PhnsetRstPwrOffDisplayDefault(void);
extern void PhnsetSetPwrOnOffDisplay(void);
extern void PhnsetPwrOnOffSelectFmgrCallBack(void *path, int is_short);
extern U8 PhnsetConstSysPwrOnOffList(U8 **pSysPwrOnOffStrList, U16 *pSysPwrOnOffImgIDList, S16 *HighliteItem);
extern mmi_ret mmi_phnset_pwr_on_off_sub_menu_handler(cui_menu_event_struct *param, MMI_ID parent_gid);
#endif /* __MMI_POWER_ON_OFF_DISPLAY__ */ 

#ifdef __USB_IN_NORMAL_MODE__
extern void mmi_phnset_screensaver_enter_mass_storage_mode(void);
extern void mmi_phnset_screensaver_exit_mass_storage_mode(void);

#ifdef __MMI_POWER_ON_OFF_DISPLAY__
extern void mmi_phnset_pwr_on_off_enter_mass_storage_mode(void);
extern void mmi_phnset_pwr_on_off_exit_mass_storage_mode(void);
#endif 
#endif /* __USB_IN_NORMAL_MODE__ */ 

extern mmi_ret mmi_phnset_wallpaper_sub_menu_handler(cui_menu_event_struct *param, MMI_ID parent_gid);
extern mmi_ret mmi_phnset_screensaver_sub_menu_handler(cui_menu_event_struct *param, MMI_ID parent_gid);
extern MMI_BOOL mmi_phnset_enter_switch_screen(void);
void ExitPhnsetPwrOnOffSysView(void);
#endif /* WPSSRPROTOS_H */ /* WPSSPROTOS_H */

