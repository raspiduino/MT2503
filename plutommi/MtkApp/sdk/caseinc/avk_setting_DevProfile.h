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
 *   tst_DevProfile.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   3rd Party Integration Development Environment
 *
 * Author:
 * ------- Zhibo.Tong(mtk80982)
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifdef __MAUI_SDK_TEST__
#ifndef LOW_COST_SUPPORT

#ifndef TST_DEVPROFILE_H
#define TST_DEVPROFILE_H
#include "DevprofileGprot.h"

#if defined(__MMI_MAINLCD_320X240__)		   	// WIDTH:320 && HEIGHT:240 (such as LION52)
    #define DRAW_TOP_Y 5
    #define DRAW_TOP_X 5
    #define DISTANCE_TWO_LINE 17//20    
#elif defined(__MMI_MAINLCD_320X480__) 	//WIDTH:320 && HEIGHT:480 (such as JADE36V2)
    #define DRAW_TOP_Y 75
    #define DRAW_TOP_X 5
    #define DISTANCE_TWO_LINE 25
#else									// default value (may be issue)
    #define DRAW_TOP_Y 75
    #define DRAW_TOP_X 5
    #define DISTANCE_TWO_LINE 25
#endif

#ifndef VS_MM_BUFFER_SIZE
#define VS_MM_BUFFER_SIZE        (128)
#endif 

#ifndef VS_MM_DEVPROFILE_SIZE
#define VS_MM_DEVPROFILE_SIZE          (3)
#endif

void vs_mm_devprofile_set_device_level_screen_enter(void);
void vs_mm_devprofile_speech_set_mode_volume_screen_enter(void);
extern void vs_appser_setting_devprofile_entry_scr(void);

#endif /* TST_DEVPROFILE_H */ 

#endif /* LOW_COST_SUPPORT */ 

#endif /* __MAUI_SDK_TEST__ */ 
