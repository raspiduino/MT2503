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
 *  vapp_res.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  resource declaration for venus app
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
#ifdef __MMI_VUI_ENGINE__

#if defined(__COSMOS_MMI__)
#include "..\..\cosmos\interface\app\vapp_package_res.h"
#endif

#if defined(__PLUTO_MMI_PACKAGE__)
#include "..\..\pluto_variation\interface\vapp_package_res.h"
#endif

#if defined(__MMI_VENUS_RT__)
#include "..\..\..\test\common\vtst_rt_res.h"
#endif

/***************************************************************************** 
 Definition 
*****************************************************************************/

#undef VFX_APP_RES_DECLARE
#define VFX_APP_RES_DECLARE(_app, _range, _path)    MMI_RES_DECLARE(_app, _range, "..\\venusmmi\\APP\\" _path)

/***************************************************************************** 
 APP resource declaration
*****************************************************************************/

//VFX_APP_RES_DECLARE(APP_SCENARIO_VIEWER, 40, "ScenarioViewer\\res\\")

MMI_RES_DECLARE(VENUS_UI_CORE, 128, "..\\venusmmi\\framework\\ui_core\\res\\")

#ifdef __VENUS_3D_UI_ENGINE__
MMI_RES_DECLARE(V3D_GLOBAL_SHADER, 200, "..\\venusmmi\\framework\\ui_core\\res\\")
#endif

VFX_APP_RES_DECLARE(VAPP_PLATFORM_CONTEXT, 5, "common\\platform\\res\\")

#if defined(__MMI_VUI_LAUNCHER_FACTORY__)
VFX_APP_RES_DECLARE(VAPP_LAUNCHER_SYSTEM, 5, "common\\launcher\\res\\")
VFX_APP_RES_DECLARE(VAPP_LAUNCHER_HEAP, 5, "common\\launcher\\res\\")
VFX_APP_RES_DECLARE(VAPP_LAUNCHER_HELLOWORLD, 5, "common\\launcher\\res\\")
#endif /* defined(__MMI_VUI_LAUNCHER_FACTORY__) */

#if defined(__MMI_VUI_LAUNCHER_MRE__)
VFX_APP_RES_DECLARE(VAPP_LAUNCHER_MRE, 10, "common\\launcher\\res\\")
#endif

#if defined(__MMI_VUI_WIDGET_FACTORY__)
VFX_APP_RES_DECLARE(VAPP_WIDGET_SYSTEM, 20, "common\\widget\\res\\")
VFX_APP_RES_DECLARE(VAPP_WIDGET_HELLOWORLD, 5, "common\\widget\\res\\")
#endif /* defined(__MMI_VUI_WIDGET_FACTORY__) */

#if defined(__MMI_VUI_WIDGET_MRE__)
VFX_APP_RES_DECLARE(VAPP_WIDGET_MRE, 10, "common\\widget\\res\\")
#endif

#if defined(__MMI_VUI_WALLPAPER_MRE__)
VFX_APP_RES_DECLARE(VAPP_WALLPAPER_MRE, 10, "common\\wallpaper\\res\\")
#endif

#if defined(__MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__)
VFX_APP_RES_DECLARE(VAPP_SCREEN_LOCK_MRE, 10, "common\\screen_lock\\res\\")
#endif

#if defined(__MMI_VUI_SCREEN_LOCK_FACTORY__)
VFX_APP_RES_DECLARE(VAPP_SCREEN_LOCK_SYSTEM, 20, "common\\screen_lock\\res\\")
VFX_APP_RES_DECLARE(VAPP_SCREEN_LOCK_HELLOWORLD, 10, "common\\screen_lock\\res\\")
#endif /* defined(__MMI_VUI_SCREEN_LOCK_FACTORY__) */

#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
#if defined(__MMI_VUI_3D_MAINMENU__) || defined(__COSMOS_MMI__) || defined(__MMI_VUI_LAUNCHER__)|| defined(__MMI_VUI_LAUNCHER_KEY__)
VFX_APP_RES_DECLARE(VCP_PAGE_MENU_TRANSITION, 30, "common\\cp\\res\\")
#endif
#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
#if defined(__MMI_NCENTER_SUPPORT__) && !defined(__MMI_KEY_ONLY_NCENTER__)
VFX_APP_RES_DECLARE(APP_NCENTER, 60, "common\\ncenter\\Res\\")
#endif /* defined(__MMI_NCENTER_SUPPORT__) && !defined(__MMI_KEY_ONLY_NCENTER__) */

#if defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_KEY_ONLY_NCENTER__)
VFX_APP_RES_DECLARE(APP_NCENTER, 60, "pluto_variation\\ncenter\\Res\\")
#endif /* defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
#endif
