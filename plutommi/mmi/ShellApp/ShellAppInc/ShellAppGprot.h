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
*  ShellAppGprot.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Shell Application header file
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
*==============================================================================*/

#ifndef _SHELL_APP_GPROT_H
#define _SHELL_APP_GPROT_H

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif
#include "MMI_features.h"   /* add if you use any compile options defined in MMI_features.h */
#include "MMIDataType.h"

/***************************************************************************** 
 * Define 
 *****************************************************************************/
#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__
#define LWP_MEM_SZ (40 * 1024)
#else
#define LWP_MEM_SZ (0)
#endif

#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
#if defined(__MMI_VUI_SHELL_BASE_SLIM__)
#define MAX_SHELL_MEM_SIZE  (300*1024 + LWP_MEM_SZ)
#else
#define MAX_SHELL_MEM_SIZE  (600*1024 + LWP_MEM_SZ)
#endif
#ifdef __MMI_MAINLCD_320X480__
#define MAX_SHELL_VRT_CACHE_SIZE    (300*1024 + LWP_MEM_SZ)
#else
#define MAX_SHELL_VRT_CACHE_SIZE    (200*1024 + LWP_MEM_SZ)
#endif
#else
#define MAX_SHELL_MEM_SIZE  (200*1024 + LWP_MEM_SZ)
#endif

/***************************************************************************** 
 * Structure and Enums
 *****************************************************************************/

/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
extern void mmi_shell_vapp_show_homescreen(void);       
extern mmi_ret mmi_shell_deinit_apps(mmi_event_struct *evt);
         
#ifdef __cplusplus
}
#endif

#endif/* _SHELL_APP_GPROT_H */

