/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * PhoneSetupSlim.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Phnsetup Slim Compile option control
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *
 * $Log
 *
 ****************************************************************************/
#include "MMI_features.h"
/*=============================================================*/
#ifdef __MMI_PHONESETTING_SLIM__ 
  #ifndef __MMI_PHNSET_DATE_SEPARATOR_DISABLE__
    #define __MMI_PHNSET_DATE_SEPARATOR_DISABLE__
  #endif
  
  #ifndef __MMI_PHNSET_DAYLIGHT_SAVING_DISABLE__
    #define __MMI_PHNSET_DAYLIGHT_SAVING_DISABLE__
  #endif
  
  #ifndef __MMI_PHNSET_WP_SLIM__
    #define __MMI_PHNSET_WP_SLIM__
  #endif
  
  #ifndef __MMI_PHNSET_AT_DISABLE__
    #define __MMI_PHNSET_AT_DISABLE__
  #endif
  
  #ifndef __MMI_PHNSET_SLIM__
  #define __MMI_PHNSET_SLIM__
  #endif 
#endif

#if defined(__MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER__) || defined(__MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__)
  #ifdef __MMI_PHNSET_WP_SLIM__
   #undef __MMI_PHNSET_WP_SLIM__
  #endif
#endif
#if defined(__32_32_SEG__)&& defined(__MMI_FTE_SUPPORT__)&& defined(__MMI_MAINLCD_240X320__)&& defined(__MTK_INTERNAL__)
  #ifdef __MMI_PHNSET_AT_DISABLE__
/* under construction !*/
  #endif
#endif

#ifdef __MMI_NETWORKSETTING_SLIM__
  #ifndef __MMI_NETSET_DISABLE_OPERATOR_CHECK__
    #define __MMI_NETSET_DISABLE_OPERATOR_CHECK__
  #endif
  #ifndef __MMI_NETSET_SLIM__
    #define __MMI_NETSET_SLIM__
  #endif
#endif  
#ifndef __MMI_TIMEZONE_CHANGE_DATETIME__
#define __MMI_TIMEZONE_CHANGE_DATETIME__
#endif

#ifndef __MMI_VIEW_SETTING_DISABLE_CACHE__
#define __MMI_VIEW_SETTING_DISABLE_CACHE__
#endif
