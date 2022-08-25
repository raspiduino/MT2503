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
 *   FunAndGamesResDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Fun And Game source file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef FUNANDGAMESRESDEF_H
#define FUNANDGAMESRESDEF_H

#include "mmi_res_range_def.h"
#include "MMIDataType.h"

#define FUNANDGAMES_BASE                     (3000)

/* Fun and Games main menu ---------------------------------------------   */
// #define FUNANDGAMES_MAX_THEMES       3

#if defined(__MMI_VERSION_2__)
typedef enum
{
#if defined(__MMI_MRE_SUB_MENU__)
   FUG_ENUM_MRE,
#endif
#if defined(__J2ME__)
    FUN_ENUM_JAVA,
    FNG_ENUM_SETTING_JAVA,
    
    #ifdef OGDR_SECURITY_SETTING
    FNG_ENUM_SECURITY_JAVA,
    #endif

    #ifdef __SUPPORT_INFUSIO__
    FNG_ENUM_JAVA_EUREKA,
    #endif /* __SUPPORT_INFUSIO__ */
#endif /* __J2ME__ */

#if defined(__MMI_GAME__)
    FUN_ENUM_GAMES,
#endif 

#if defined(__MMI_3D_GAME__)
    FUN_ENUM_3D_GAME,
#endif 

#if defined(__MMI_MOTION_APP__)
    FUN_ENUM_MOTION_APP,
#endif 

#if defined (__MMI_PICTURE_EDITOR_SUPPORT__)
    FUN_ENUM_PIC_EDITOR,
#endif 

#if defined (__MMI_AVATAR__)
    FUN_ENUM_AVATAR,
#endif 

    FUN_ENUM_TOTAL
} FunAndGameMenu;

typedef enum
{
#if defined(__MMI_ATV_SUPPORT__)
    MMEDIA_ENUM_MOBILE_TV_PLAYER,
#endif

#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    MMEDIA_ENUM_DTV_PLAYER,
#endif

#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
#ifndef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    MMEDIA_ENUM_CAMERA,
#endif 
#endif /* defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) */ 

#if defined (__MMI_CAMCORDER__)
#ifndef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    MMEDIA_ENUM_CAMCORDER,
#endif 
#endif /* defined (__MMI_CAMCORDER__) */ 

#if defined(__MMI_IMAGE_VIEWER__)
    MMEDIA_ENUM_IMAGEVIEWER,
#endif 

#ifndef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
#if defined (__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)
    MMEDIA_ENUM_VIDEO_RECORDER,
#endif 
#if defined (__MMI_VIDEO_PLAYER__)
    MMEDIA_ENUM_VIDEO_PLAYER,
#endif 
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

#if defined(__MMI_VIDEO_EDITOR__)
    MMEDIA_ENUM_VIDEO_EDITOR,
#endif

#if defined(__MMI_PHOTOEDITOR__)
    MMEDIA_ENUM_PHOTO_EDITOR,
#endif 

#if defined(__MMI_BARCODEREADER__)
    MMEDIA_ENUM_BARCODEREADER,
#endif 

#ifndef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
#if defined(__MMI_AUDIO_PLAYER__)
    MMEDIA_ENUM_AUDIO_PLAYER,
#endif 
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

#if defined(__MMI_AB_REPEATER__)
    MMEDIA_ENUM_AB_REPEATER,
#endif 

#if defined(__MMI_SOUND_RECORDER__)
    MMEDIA_ENUM_SOUND_RECORDER,
#endif 

#if defined (__MMI_FM_RADIO__)
    MMEDIA_ENUM_FM_RADIO,
#endif 

#if defined(__MMI_FM_RADIO_SCHEDULE_REC__)
    MMEDIA_ENUM_FM_SCHEDULE_RECORD,
#endif 

#if defined(__MMI_VRSD__)
    MMEDIA_ENUM_VRSD,
#endif 

#if defined(__MMI_VRSI__)
    MMEDIA_ENUM_VRSI,
#endif

#if defined(__MMI_SLIDESHOW__)
    MMEDIA_ENUM_SLIDESHOW,
#endif

#if defined(__MMI_BCR__)
    MMEDIA_ENUM_BCR_APP,
#endif

#ifndef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
#if defined(__MMI_MEDIA_PLAYER__)
    MMEDIA_ENUM__MEDPLY_MAIN,
#endif
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
    MMEDIA_ENUM_TOTAL
} MultiMediaMenu;

#else /* defined(__MMI_VERSION_2__) */ 
#ifdef __MMI_OP01_MENU_NOSIM_LIST__
/* under construction !*/
/* under construction !*/
#if defined(__J2ME__)
/* under construction !*/
/* under construction !*/
#ifdef OGDR_SECURITY_SETTING
/* under construction !*/
#endif /* OGDR_SECURITY_SETTING */
#ifdef __SUPPORT_INFUSIO__
/* under construction !*/
#endif /* __SUPPORT_INFUSIO__ */
#endif /* __J2ME__ */
/* under construction !*/
#if defined(__MMI_GAME__)
/* under construction !*/
#endif 
/* under construction !*/
#if defined(__MMI_3D_GAME__)
/* under construction !*/
#endif 
/* under construction !*/
#if defined(__MMI_MOTION_APP__)
/* under construction !*/
#endif 
/* under construction !*/
#if defined(__MMI_STOPWATCH__)
/* under construction !*/
#endif 
/* under construction !*/
#if defined (__MMI_PICTURE_EDITOR_SUPPORT__)
/* under construction !*/
#endif 
/* under construction !*/
#if defined (__MMI_AVATAR__)
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
#ifndef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
/* under construction !*/
#endif 
#endif /* defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) */ 
/* under construction !*/
#if defined (__MMI_CAMCORDER__)
#ifndef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
/* under construction !*/
#endif 
#endif /* defined (__MMI_CAMCORDER__) */ 
/* under construction !*/
#ifndef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
#if defined(__MMI_AUDIO_PLAYER__)
/* under construction !*/
#endif 
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
#if defined (__MMI_FM_RADIO__)
/* under construction !*/
#endif 
#if defined(__MMI_IMAGE_VIEWER__)
/* under construction !*/
#endif 
#if defined(__MMI_PHOTOEDITOR__)
/* under construction !*/
#endif 
#ifndef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
#if defined (__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)
/* under construction !*/
#endif 
#if defined (__MMI_VIDEO_PLAYER__)
/* under construction !*/
#endif 
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
#if defined(__MMI_VIDEO_EDITOR__)
/* under construction !*/
#endif
#if defined(__MMI_BARCODEREADER__)
/* under construction !*/
#endif 
#if defined(__MMI_SOUND_RECORDER__)
/* under construction !*/
#endif 
#if defined(__MMI_AB_REPEATER__)
/* under construction !*/
#endif 
#if defined(__MMI_FM_RADIO_SCHEDULE_REC__)
/* under construction !*/
#endif 
/* under construction !*/
#if defined(__MMI_VRSD__)
/* under construction !*/
#endif 
/* under construction !*/
#if defined(__MMI_VRSI__)
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_MENU_NOSIM_LIST__ */

#if defined(__MMI_OP01_MENU_9MATRIX__) || defined(__MMI_OP01_MENU_12MATRIX__)
typedef enum
{
#if defined(__MMI_IMAGE_VIEWER__)
	MMEDIA_ENUM_IMAGEVIEWER,
#endif 
#if defined(__MMI_PHOTOEDITOR__)
	MMEDIA_ENUM_PHOTO_EDITOR,
#endif 
#if defined (__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)
	MMEDIA_ENUM_VIDEO_RECORDER,
#endif 
#if defined (__MMI_VIDEO_PLAYER__)
	MMEDIA_ENUM_VIDEO_PLAYER,
#endif 
#if defined(__MMI_VIDEO_EDITOR__)
	MMEDIA_ENUM_VIDEO_EDITOR,
#endif
#if defined(__MMI_BARCODEREADER__)
	MEDIA_ENUM_BARCODEREADER,
#endif 
#if defined(__MMI_SOUND_RECORDER__)
	MMEDIA_ENUM_SOUND_RECORDER,
#endif 
#if defined(__MMI_GAME__)
	MMEDIA_ENUM_GAMES,
#endif
#if defined(__MMI_3D_GAME__)
	MEDIA_ENUM_3D_GAME,
#endif 
#if defined(__MMI_AB_REPEATER__)
	MMEDIA_ENUM_AB_REPEATER,
#endif 
#if defined(__MMI_FM_RADIO_SCHEDULE_REC__)
	MMEDIA_ENUM_FM_SCHEDULE_RECORD,
#endif 
#if defined(__MMI_VRSD__)
	MMEDIA_ENUM_VRSD,
#endif 
#if defined(__MMI_VRSI__)
	MEDIA_ENUM_VRSI,
#endif  				
#if defined(__MMI_MOTION_APP__) 
	MEDIA_ENUM_MOTION,
#endif 
#if defined( __MMI_STOPWATCH__)        
	MEDIA_ENUM_STOPWATCH,
#endif  
#if defined (__MMI_PICTURE_EDITOR_SUPPORT__)
	MEDIA_ENUM_PICTURE_EDITOR,
#endif
#if defined(__MMI_AVATAR__)
       MEDIA_ENUM_AVATAR_EDITOR,
#endif
    MMEDIA_ENUM_TOTAL
} MultiMediaMenu;
#else /* __MMI_OP01_MENU_9MATRIX__ */
typedef enum
{
#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
    MMEDIA_ENUM_CAMERA,
#endif 

#if defined (__MMI_CAMCORDER__)
    MMEDIA_ENUM_CAMCORDER,
#endif 

#if defined(__MMI_IMAGE_VIEWER__)
    MMEDIA_ENUM_IMAGEVIEWER,
#endif 

#if defined (__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)
    MMEDIA_ENUM_VIDEO_RECORDER,
#endif 

#if defined (__MMI_VIDEO_PLAYER__)
    MMEDIA_ENUM_VIDEO_PLAYER,
#endif 

#if defined(__MMI_VIDEO_EDITOR__)
    MMEDIA_ENUM_VIDEO_EDITOR,
#endif

#if defined(__MMI_PHOTOEDITOR__)
    MMEDIA_ENUM_PHOTO_EDITOR,
#endif 

#if defined(__MMI_BARCODEREADER__)
    MMEDIA_ENUM_BARCODEREADER,
#endif 

#if defined(__MMI_AUDIO_PLAYER__)
    MMEDIA_ENUM_AUDIO_PLAYER,
#endif 

#if defined(__MMI_AB_REPEATER__)
    MMEDIA_ENUM_AB_REPEATER,
#endif 

#if defined(__MMI_SOUND_RECORDER__)
    MMEDIA_ENUM_SOUND_RECORDER,
#endif 

#if defined (__MMI_FM_RADIO__)
    MMEDIA_ENUM_FM_RADIO,
#endif 

#if defined(__MMI_FM_RADIO_SCHEDULE_REC__)
    MMEDIA_ENUM_FM_SCHEDULE_RECORD,
#endif 

#if defined(__MMI_VRSD__)
    MMEDIA_ENUM_VRSD,
#endif 

#if defined(__MMI_VRSI__)
    MMEDIA_ENUM_VRSI,
#endif 

#if defined(__MMI_FILE_MANAGER__)
    MMEDIA_ENUM_FILE_MANAGER,
#endif
    MMEDIA_ENUM_TOTAL
} MultiMediaMenu;
#endif /* __MMI_OP01_MENU_9MATRIX__ */

typedef enum
{
#if defined(__MMI_MRE_SUB_MENU__)
   FUG_ENUM_MRE,
#endif
#if defined(__J2ME__)
    FUN_ENUM_JAVA,
    FNG_ENUM_SETTING_JAVA,

    #ifdef OGDR_SECURITY_SETTING
    FNG_ENUM_SECURITY_JAVA,
    #endif

    #ifdef __SUPPORT_INFUSIO__
    FNG_ENUM_SETTING_JAVA_EUREKA,
    #endif 

#endif 

#if defined(__MMI_GAME__)
    FUN_ENUM_GAMES,
#endif 

#if defined(__MMI_3D_GAME__)
    FUN_ENUM_3D_GAME,
#endif 

#if defined(__MMI_MOTION_APP__)
    FUN_ENUM_MOTION_APP,
#endif 

#if defined (__MMI_PICTURE_EDITOR_SUPPORT__)
    FUN_ENUM_PIC_EDITOR,
#endif 

#if defined (__MMI_AVATAR__)
    FUN_ENUM_AVATAR,
#endif 

    FUN_ENUM_TOTAL
} FunAndGameMenu;

#endif /* defined(__MMI_VERSION_2__) */ // #if defined(__MMI_VERSION_2__)

typedef enum
{
    SCR3000_FUNANDGAMES = FUN_GAMES_BASE + 1,
    SCR_ID_FNG_NUM
} SCREENID_LIST_FUNANDGAMES;

typedef enum
{
    STR_MENU3104_VOICE_MEMO = FUN_GAMES_BASE + 1,
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
#endif

    STR_GAMES_RICHES,

    /*  FNG Setting */
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
    #endif
    STR_ID_FNG_MAX
} STRINGID_LIST_FUNANDGAMES;

typedef enum
{
    IMG_MENU3104_VOICE_MEMO = FUN_GAMES_BASE + 1,
    IMG_MENU3106_WALLPAPER,
    IMG_MENU3107_SCREENSAVER,
  
    /* FNG Setting */
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
	#endif
	
//    IMG_ID_FNG_FMGR_SUB_ICON,
    
        /* Full Screen status icon */
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
          #endif
} IMAGEID_LIST_FUNANDGAMES;

#endif /* FUNANDGAMESRESDEF_H */ 

