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
*  AMGprot.h
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  AM header file.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef AM_GPROT_H
#define AM_GPROT_H

#include "MMIDataType.h"
#include "AMGprot_int.h"

/* shortcut id */
typedef enum
{
    APPID_NONE = 0,
    APPID_VAS,
    APPID_QQBROWSER,
    APPID_QQ,
    APPID_QQ_2010,    
    APPID_WLOL,
    APPID_MOBILEKK,
    APPID_STOCKSTAR,
    APPID_FETION,
    APPID_QQLANDLORD,
    APPID_MSN,
    APPID_OPERA,
    APPID_100TV,
    APPID_AIPIM,
    APPID_LUUTOO,
    APPID_PUSHMAIL,
    APPID_WORLDCLOCK,   /* worldclock */
    APPID_YAHOOMV1,
    APPID_FBLITE,
    APPID_FACEBOOK_V2,
	APPID_FACEBOOK_V2_MESSENGER,
    APPID_TWITTER,
    APPID_YOUTUBE,
    APPID_YAHOOFINANCE,
    APPID_YAHOOWEATHER,
    APPID_YAHOONEWS,
    APPID_YAHOOCRICKET,
    APPID_OPERA_MINI_V6,
    APPID_CALCULATOR,   /* calculator */
    APPID_CONVERTER,
    APPID_HEALTH,
    APPID_STOPWATCH,
    APPID_ZAKAT,
    APPID_ZY_EBOOK,
    /*<---------------------------- ADD 3GT Game START ---------------------------->*/
    APPID_BOWLING_ENG,
    APPID_BOWLING_CHS,
    APPID_BOWLING_CHT,
    APPID_DANDELION,
    APPID_3GT_RASH_MOTOR_CHS,
    APPID_3GT_RASH_MOTOR_CHT,
    APPID_3GT_RASH_MOTOR_ENG,
    APPID_3GT_BALANCE_BALL_CHS,
    APPID_3GT_BALANCE_BALL_CHT,
    APPID_3GT_BALANCE_BALL_ENG,

    /*<---------------------------- ADD 3GT Game END ------------------------------>*/
    APPID_RENREN,
    APPID_KAIXIN,
    APPID_YOUKU,
    APPID_GAMELOFT_ASPHALT6,
    APPID_GAMELOFT_BRAINCHALLENGE,
    APPID_GAMELOFT_BLOCKBREAKER,
    APPID_GAMELOFT_ASSASSINCREED,
    APPID_ANGRYBIRD_EN,
    APPID_ANGRYBIRD_SC,
    APPID_FRUITNINJA_EN,
    APPID_FRUITNINJA_SC,
    APPID_FISHINGFUN_EN,
    APPID_FISHINGFUN_SC,
    APPID_HAPPYWAR_EN,
    APPID_HAPPYWAR_CHS,
    APPID_EGYPTCODE_EN,
    APPID_EGYPTCODE_CHS,
    APPID_KINGCOMBAT_EN,
    APPID_KINGCOMBAT_CHS,
    APPID_GOLDMINER_EN,
    APPID_GOLDMINER_CHS,
    APPID_MOTO_EN,
    APPID_MOTO_CHS,
    APPID_GIRLSLOT_EN,
    APPID_GIRLSLOT_CHS,
    APPID_PARKOUR_EN,
    APPID_PARKOUR_CHS,
    APPID_TEARDRESS_EN,
    APPID_TEARDRESS_CHS,
    APPID_HAPPYEGG_EN,
    APPID_HAPPYEGG_CHS,	
    APPID_GAMELOFT_GLIVE,
    APPID_GAMELOFT_MC2,
    APPID_SINA_WEIBO,
    APPID_MAX
} mmi_am_shortcut_id_enum;

/***************************************************************************** 
* Define
*****************************************************************************/
typedef struct
{
    mmi_am_shortcut_id_enum app_id;
    U16 image_id;
    U16 name_id;
    const U8 *app_array; /* application dump array pointer */ 
} mmi_am_launch_app_info_struct;
extern mmi_am_launch_app_info_struct g_am_la_info_list[];
extern MMI_BOOL mmi_am_install_app_check_popup(U16 *app_path);
/****************************************************************************
* External Global Function                                                            
*****************************************************************************/
extern MMI_BOOL mmi_am_launch_app_by_path(U16 *app_path);
extern MMI_BOOL mmi_am_launch_app_by_id(mmi_am_shortcut_id_enum appid);
//fix
#if defined(__MMI_MRE_SUB_MENU__)||defined( __MMI_MRE_MAIN_MENU__)
extern void mmi_am_start(void);                 /* start am from main menu */
extern void mmi_am_start_from_fm(U16 *path);    /* start app from file manager */
extern void mmi_am_start_from_hs(U16 *path);    /* start app from home screen */
extern void mmi_am_start_from_mm(mmi_am_shortcut_id_enum appid);        /* start app from main menu */

#ifdef __USB_IN_NORMAL_MODE__
extern void mmi_am_enter_usb_mode(void);
#endif 

/* HS-Shortcut Api */
U8 mmi_am_get_shortcut_number(void);
void mmi_am_get_all_shortcut_id(U32 *id_array, U32 size);      /* #id in id_array. Memory is provided by HS. */
void mmi_am_get_shortcut_icon(U32 icon_id, U16 *icon_file, U32 size);  /* icon_file memory is offered by hs */
void mmi_am_launch_shortcut(U32 icon_id);
void mmi_am_read_shorcut_record(void);
void mmi_am_init(void);
#endif

/* For Video Recorder App */
extern S32 mmi_am_is_using_media_memory(void);
extern void mmi_am_media_memory_unavailable_popup(void);
extern MMI_STR_ID mmi_am_get_error_info(S32 error_result, S32 *popup_type);


/*Do not add launch function declare here if launch function is static*/

#if defined(__MMI_MRE_APP_OPERA__)
extern void mmi_am_la_launch_opera(void);
#endif

#if (defined (__MMI_MRE_APP_YAHOOMV1__) || defined(__MMI_MRE_APP_YAHOOMV2__))
extern void mmi_am_la_launch_Yahoo(void);
#endif

/*Do not add launch function declare here if launch function is static*/

#endif /* AM_GPROT_H */ 

