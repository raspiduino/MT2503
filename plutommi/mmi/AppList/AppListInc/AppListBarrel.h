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
 *  AppListBarrel.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  AppList Barrel
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

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef _MMI_APPLIST_BARREL_H_
#define _MMI_APPLIST_BARREL_H_

#include "mmi_features.h"


#ifdef __MMI_APPLIST_BARREL_SUPPORT__

#include "MMIDataType.h"
#include "gdi_linear_transform.h"
#include "AppList.h"

//for slim
#ifdef __MMI_APPLIST_BARREL_DISABLE_MATRIX_EFFECT__
#define __MMI_APPLIST_BARREL_DISABLE_CYLINDER_EFFECT__
#define __MMI_APPLIST_BARREL_DISABLE_CUBE_EFFECT__
#define __MMI_APPLIST_BARREL_DISABLE_TORNADO_EFFECT__
#define __MMI_APPLIST_BARREL_DISABLE_BALL_EFFECT__
#define __MMI_APPLIST_BARREL_DISABLE_TILT_EFFECT__
#define __MMI_APPLIST_BARREL_DISABLE_WAVE_EFFECT__
#else  //__MMI_APPLIST_BARREL_DISABLE_MATRIX_EFFECT__
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
#if defined(__MMI_APPLIST_BARREL_DISABLE_CYLINDER_EFFECT__) && defined(__MMI_APPLIST_BARREL_DISABLE_CUBE_EFFECT__) && defined(__MMI_APPLIST_BARREL_DISABLE_TORNADO_EFFECT__) && \
    defined(__MMI_APPLIST_BARREL_DISABLE_BALL_EFFECT__) && defined(__MMI_APPLIST_BARREL_DISABLE_TILT_EFFECT__) && defined(__MMI_APPLIST_BARREL_DISABLE_WAVE_EFFECT__)
#define __MMI_APPLIST_BARREL_DISABLE_MATRIX_EFFECT__
#endif

#endif  //__MMI_APPLIST_BARREL_DISABLE_MATRIX_EFFECT__


#if defined(__MMI_MAINLCD_320X480__)
#ifndef __MMI_APPLIST_BARREL_DISABLE_CYLINDER_EFFECT__
#define MMI_APPLIST_BARREL_CYLINDER_RADIUS (162)
#define MMI_APPLIST_BARREL_CYLINDER_NEAR   (340)
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_TORNADO_EFFECT__
#define MMI_APPLIST_TORNADO_MENU_ANGLE                              (45) 
#define MMI_APPLIST_TORNADO_MENU_FROM_RADIUS                        (182)
#define MMI_APPLIST_TORNADO_MENU_TO_RADIUS                          (50)
#define MMI_APPLIST_TORNADO_MENU_Y_GAP                               (97)
#define MMI_APPLIST_TORNADO_MENU_AHEAD_COUNT                        (9) 
#define MMI_APPLIST_TORNADO_MENU_BEHIND_COUNT                       (16)
#define MMI_APPLIST_TORNADO_MENU_Y_SHIFT                            (0)
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_JUMP_UP_EFFECT__
#define MMI_APPLIST_JUMP_UP_VANISH_POINT_X                          (130)
#define MMI_APPLIST_JUMP_UP_VANISH_POINT_Y                          (500)
#define MMI_APPLIST_JUMP_UP_VANISH_POINT_SCALE                      (0.75f)
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_SPACE_BEAM_EFFECT__
#define MMI_APPLIST_SPACE_BEAM_VANISH_POINT_X                       (140)
#define MMI_APPLIST_SPACE_BEAM_VANISH_POINT_Y                       (140)
#define MMI_APPLIST_SPACE_BEAM_VANISH_POINT_SCALE                   (0.36f)
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_BALL_EFFECT__
#define MMI_APPLIST_BARREL_BALL_RADIUS                               (162)
#endif

#else  //defined(__MMI_MAINLCD_320X480__)
#ifndef __MMI_APPLIST_BARREL_DISABLE_CYLINDER_EFFECT__
#define MMI_APPLIST_BARREL_CYLINDER_RADIUS (140)
#define MMI_APPLIST_BARREL_CYLINDER_NEAR   (340)
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_TORNADO_EFFECT__
#define MMI_APPLIST_TORNADO_MENU_ANGLE                              (45) 
#define MMI_APPLIST_TORNADO_MENU_FROM_RADIUS                        (152)
#define MMI_APPLIST_TORNADO_MENU_TO_RADIUS                          (50)
#define MMI_APPLIST_TORNADO_MENU_Y_GAP                               (85)
#define MMI_APPLIST_TORNADO_MENU_AHEAD_COUNT                        (9) 
#define MMI_APPLIST_TORNADO_MENU_BEHIND_COUNT                       (16)
#define MMI_APPLIST_TORNADO_MENU_Y_SHIFT                            (0)
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_JUMP_UP_EFFECT__
#define MMI_APPLIST_JUMP_UP_VANISH_POINT_X                          (101)
#define MMI_APPLIST_JUMP_UP_VANISH_POINT_Y                          (460)
#define MMI_APPLIST_JUMP_UP_VANISH_POINT_SCALE                      (0.75f)
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_SPACE_BEAM_EFFECT__
#define MMI_APPLIST_SPACE_BEAM_VANISH_POINT_X                       (109)
#define MMI_APPLIST_SPACE_BEAM_VANISH_POINT_Y                       (120)
#define MMI_APPLIST_SPACE_BEAM_VANISH_POINT_SCALE                   (0.36f)
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_BALL_EFFECT__
#define MMI_APPLIST_BARREL_BALL_RADIUS                               (140)
#endif

#endif  //defined(__MMI_MAINLCD_320X480__)


#if defined(__MMI_MAINLCD_240X320__)
#ifndef __MMI_APPLIST_BARREL_DISABLE_JUMP_UP_EFFECT__
#define MMI_APPLIST_JUMP_UP_VANISH_POINT_X                          (101)
#define MMI_APPLIST_JUMP_UP_VANISH_POINT_Y                          (360)
#define MMI_APPLIST_JUMP_UP_VANISH_POINT_SCALE                      (0.75f)
#endif
#endif  //defined(__MMI_MAINLCD_240X320__)

#ifndef __MMI_APPLIST_BARREL_DISABLE_CUBE_EFFECT__
#define MMI_APPLIST_CUBE_TRANSITION_CAMERA_DISTANCE                (520) 
#endif


/* Get transform matrix */
typedef void (*transform_func)( 
        S32 cell_index,                         
        gdi_lt_matrix_struct *transform,  
        U8 *opacity,
        float *pos_z);

extern void mmi_applist_barrel_load_type(void);
extern void mmi_applist_barrel_change_transform(void);
extern transform_func mmi_applist_barrel_get_transform(void);
extern void mmi_applist_barrel_auto_slide_back(void);

#endif /* __MMI_APPLIST_BARREL_SUPPORT__ */

#endif /* _MMI_APPLIST_BARREL_H_ */
