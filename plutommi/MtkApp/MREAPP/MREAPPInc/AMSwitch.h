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
*  AMSwitch.h
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef AM_SWITCH_H
#define AM_SWITCH_H

#include "MMI_features.h"

/***************************************************************************** 
* Config AM module by following MACRO
*****************************************************************************/
#define AM_APP_LAUNCH_SUPPORT
#define AM_APP_MANAGEMENT_SUPPORT
#define AM_APP_DOWNLOAD_SUPPORT

#ifdef AM_APP_MANAGEMENT_SUPPORT
/***************************************************************************** 
* Config AM memory mode
*****************************************************************************/
#ifdef __MRE_MEDIA_BUF__
#define MMI_AM_USING_MRE_MEM
#endif 

/***************************************************************************** 
* AM Shortcut feature switch
*****************************************************************************/
#ifdef __MMI_VUI_HOMESCREEN__
#ifndef __MMI_VUI_SHELL_MULTI_PAGE__    /* home screen called Shell */
#define MMI_AM_SHORTCUT_ENABLE
#endif
#endif

/***************************************************************************** 
* AM Shortcut Application switch
*****************************************************************************/
#if 0
#if defined(MT6223) || defined(MT6223C) || defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223_SERIES)
/* under construction !*/
#endif 
/* under construction !*/
#if defined(MT6253) || defined(MT6253D) || defined(MT6253T) || defined(MT6253_SERIES)
/* under construction !*/
#endif 
/* under construction !*/
#if defined(MT6225) || defined(MT6225_SERIES)
/* under construction !*/
#endif 
#else
#if defined(__CPU_ARM7EJ_S__)
#if defined(MCU_13M)||defined(MCU_26M)||defined(MCU_39M)||defined(MCU_52M)||defined(MCU_104M)
#define MMI_AM_LOW_PERFORMANCE_SERIES
#endif
#endif
#endif

/* configuration for shortcut applications */
//#define MMI_AM_SC_APP_AS        /* MUST have AS, or you need to modify am_shortcut_info_list */

//#ifndef __MMI_FTE_SUPPORT__
#if 0
/* under construction !*/
#if defined(__MMI_MAINLCD_240X320__)    /* QVGA */
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if !defined(MMI_AM_LOW_PERFORMANCE_SERIES)
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if !defined(MMI_AM_LOW_PERFORMANCE_SERIES)
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if !defined(MMI_AM_LOW_PERFORMANCE_SERIES)
/* under construction !*/
#endif 
/* under construction !*/
#elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if !defined(MMI_AM_LOW_PERFORMANCE_SERIES)
/* under construction !*/
#endif 
/* under construction !*/
#elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
#endif /* __MMI_FTE_SUPPORT__ */ 

#ifdef __MMI_MRE_SHORTCUT_QQ__
//#define MMI_AM_SC_APP_QQ
#endif

#ifdef __MMI_MRE_SHORTCUT_OPERA__
//#define MMI_AM_SC_APP_OPERA
#endif

#endif /* AM_APP_MANAGEMENT_SUPPORT */ 

#endif /* AM_SWITCH_H */ 

