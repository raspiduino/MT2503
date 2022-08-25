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
 *  MobileTVPlayerOSD.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Mobile TV Player OSD
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_features.h"

#if defined(__MMI_ATV_SUPPORT__)

#include "MobileTVPlayerOSD.h"

#include "lcd_sw_inc.h"

/******************************************************************************
 *    Analog TV OSD
 ******************************************************************************/
#if ((LCD_WIDTH == 176) && (LCD_HEIGHT == 220)) /* ATV */

mtv_player_layout_struct g_mtv_player_osd_cntx =
{
    {0,     0, 240,  27},    /* title */
    {8,   50, 160,  70},    /* hint */
    {57,  179,   0,   0},    /* channel number */
    {0,     0,   0,   0},    /* channel name */   
        
    {134, 155,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {54,  155,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {13,  155,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {123, 175,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {82,  175,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE}     /* rsk */
#if !defined(__MMI_FTE_SUPPORT__)
    ,
    {118, 155,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE}     /* vol_status */
#endif
};
    
mtv_player_layout_struct g_mtv_player_osd_cntx_270 =
{
    {0,     0, 233,  27},   /* title */
    {30,    50, 160,  70},   /* hint */
    {46,  151,   0,   0},    /* channel number */
    {0,     0,   0,   0},    /* channel name */
        
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */    
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {165, 147,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {136, 147,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {102, 147,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {68,  147,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE}     /* rsk */
#if !defined(__MMI_FTE_SUPPORT__)
    ,
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE}   /* vol_status */
#endif    
};

#elif ((LCD_WIDTH == 240) && (LCD_HEIGHT == 320)) /* ATV */
#ifdef __MMI_FTE_SUPPORT__
mtv_player_layout_struct g_mtv_player_osd_cntx =
{
    {0,     0,   0,   0},    /* title */
    {20,   50, 200,  70},    /* hint */
    {132, 229,   0,   0},    /* channel number */
    {0,     0,   0,   0},    /* channel name */   
        
    {194, 262,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {104, 249,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {104, 193,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {290, 169,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {236, 169,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {149, 221,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {59, 221,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {9,   289,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {199, 289,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* rsk */

    {80,  127, 160, 115, MTV_PLAYER_ICON_STATUS_DISABLE},    /* vol bg */
    {176, 262,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE},    /* vol status */
    {100, 191, 120,   0, MTV_PLAYER_ICON_STATUS_DISABLE},    /* vol bar */
    {100, 188,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE}     /* vol indx */ 
};
#else /* __MMI_FTE_SUPPORT__ */
mtv_player_layout_struct g_mtv_player_osd_cntx =
{
    {0,     0, 240,  27},    /* title */
    {20,   50, 200,  70},    /* hint */
    {77,  261,   0,   0},    /* channel number */
    {0,     0,   0,   0},    /* channel name */   
        
    {184, 217,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {58,  208,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {12,  208,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {168, 253,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {113, 253,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* rsk */
        
    {162, 217,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE}    /* vol_status */     
};
#endif /* __MMI_FTE_SUPPORT__ */

#ifdef __MMI_FTE_SUPPORT__
mtv_player_layout_struct g_mtv_player_osd_cntx_270 =
{
    {0,     0,   0,   0},   /* title */
    {40,    50, 240, 140},   /* hint */
    {129, 210,   0,   0},    /* channel number */
    {0,     0,   0,   0},    /* channel name */
        
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */    
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {233,  202,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {191, 202,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {147,  202,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {56,   202,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {285,   5,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},     /* rsk */

    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE},    /* vol bg */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE},    /* vol status */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE},    /* vol bar */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE}     /* vol indx */
};
#else /* __MMI_FTE_SUPPORT__ */
mtv_player_layout_struct g_mtv_player_osd_cntx_270 =
{
    {0,     0, 233,  27},   /* title */
    {40,    50, 240, 140},   /* hint */
    {64,  208,   0,   0},    /* channel number */
    {0,     0,   0,   0},    /* channel name */
        
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */    
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {264, 200,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {212, 200,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {151, 200,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {95,  200,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {283,   2,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},     /* rsk */

    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE}    /* vol_status */
};
#endif /* __MMI_FTE_SUPPORT__ */

#elif ((LCD_WIDTH == 320) && (LCD_HEIGHT == 240)) /* ATV */
#ifdef __MMI_FTE_SUPPORT__
mtv_player_layout_struct g_mtv_player_osd_cntx =
{
    {0,     0,   0,   0},    /* title */
    {40,   50, 240,  70},    /* hint */
    {172, 216,   0,   0},    /* channel number */
    {0,     0,   0,   0},    /* channel name */   

    {278, 184,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {143, 183,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {8,   177,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {290, 169,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {236, 169,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {189, 210,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {101, 210,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {9,   210,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {282, 210,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* rsk */

    {80,  127, 160, 115, MTV_PLAYER_ICON_STATUS_DISABLE},    /* vol bg */
    {260, 184,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE},    /* vol status */
    {100, 191, 120,   0, MTV_PLAYER_ICON_STATUS_DISABLE},    /* vol bar */
    {100, 188,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE}     /* vol indx */ 
};
#else /* __MMI_FTE_SUPPORT__ */
mtv_player_layout_struct g_mtv_player_osd_cntx =
{
    {0,     0, 320,  36},    /* title */
    {40,   50, 240,  70},    /* hint */
    {163, 169,   0,   0},    /* channel number */
    {0,     0,   0,   0},    /* channel name */   
        
    {254, 169,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {55,  169,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {10,  169,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {290, 169,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {236, 169,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {172, 169,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {96,  169,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE}     /* rsk */
#if !defined(__MMI_FTE_SUPPORT__)   
    ,
    {209, 169,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE}    /* vol_status */  
#endif    
};
#endif /* __MMI_FTE_SUPPORT__ */

mtv_player_layout_struct g_mtv_player_osd_cntx_270 =
{
    {0,     0, 233,  27},   /* title */
    {40,    50, 240, 70},   /* hint */
    {114, 213,   0,   0},    /* channel number */
    {0,     0,   0,   0},    /* channel name */
        
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */    
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {213, 205,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {171, 205,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {127,  205,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {36,   205,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {281, 210,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE}     /* rsk */
#ifdef __MMI_FTE_SUPPORT__
    ,
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE},    /* vol bg */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE},    /* vol status */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE},    /* vol bar */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE}     /* vol indx */
#else /* __MMI_FTE_SUPPORT__ */
    ,
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE}    /* vol_status */
#endif /* __MMI_FTE_SUPPORT__ */
};

#elif ((LCD_WIDTH == 240) && (LCD_HEIGHT == 400)) /* ATV */
#ifdef __MMI_FTE_SUPPORT__
mtv_player_layout_struct g_mtv_player_osd_cntx =
{
    {0,     0,   0,   0},    /* title */
    {20,   110, 200,  70},    /* hint */
    {132, 284,   0,   0},    /* channel number */
    {0,     0,   0,   0},    /* channel name */   
        
    {194, 332,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {104, 304,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {104, 248,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {290, 169,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {236, 169,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    { 149, 276,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {59, 276,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {9,   367,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {199, 367,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* rsk */

    {80,  127, 160, 115, MTV_PLAYER_ICON_STATUS_DISABLE},    /* vol bg */
    {176, 332,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE},    /* vol status */
    {100, 191, 120,   0, MTV_PLAYER_ICON_STATUS_DISABLE},    /* vol bar */
    {100, 188,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE}     /* vol indx */ 
};
#else /* __MMI_FTE_SUPPORT__ */
mtv_player_layout_struct g_mtv_player_osd_cntx =
{
    {0,     0, 240,  27},    /* title */
    {20,   110, 200,  70},    /* hint */
    {77,  337,   0,   0},    /* channel number */
    {0,     0,   0,   0},    /* channel name */   
        
    {184, 289,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {58,  282,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {12,  282,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {168, 329,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {113, 329,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* rsk */

    {162, 289,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE}    /* vol_status */
};
#endif /* __MMI_FTE_SUPPORT__ */

#ifdef __MMI_FTE_SUPPORT__
mtv_player_layout_struct g_mtv_player_osd_cntx_270 =
{
    {0,     0,   0,   0},   /* title */
    {40,    50, 320, 140},   /* hint */
    {172, 210,   0,   0},    /* channel number */
    {0,     0,   0,   0},    /* channel name */
        
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */    
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {272,  202,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {230,  202,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {186,  202,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {95, 202,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {361,   5,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},     /* rsk */

    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE},    /* vol bg */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE},    /* vol status */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE},    /* vol bar */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE}     /* vol indx */
};
#else /* __MMI_FTE_SUPPORT__ */
mtv_player_layout_struct g_mtv_player_osd_cntx_270 =
{
    {0,     0, 233,  27},   /* title */
    {40,    50, 320, 140},   /* hint */
    {61,  208,   0,   0},    /* channel number */
    {0,     0,   0,   0},    /* channel name */
        
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */    
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {260, 200,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {208, 200,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {147, 200,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {91,  200,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {360,   3,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},     /* rsk */

    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE}    /* vol_status */   
};
#endif /* __MMI_FTE_SUPPORT__ */ 

#elif ((LCD_WIDTH == 320) && (LCD_HEIGHT == 480)) /* ATV */
#ifdef __MMI_FTE_SUPPORT__
mtv_player_layout_struct g_mtv_player_osd_cntx =
{
    {0,     0, 240,   7},    /* title */
    {40,    90, 240,  70},    /* hint */
    {176, 342,   0,   0},    /* channel number */
    {0,     0,   0,   0},    /* channel name */   
        
    {256, 399,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {139, 374,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {139, 290,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {206, 332,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {72,  332,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {11,  436,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {267, 436,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* rsk */

    {80,  127, 160, 115, MTV_PLAYER_ICON_STATUS_DISABLE},    /* vol bg */
    {231, 399,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE},    /* vol status */
    {100, 191, 120,   0, MTV_PLAYER_ICON_STATUS_DISABLE},    /* vol bar */
    {100, 188,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE}     /* vol indx */
};
#else /* __MMI_FTE_SUPPORT__ */
mtv_player_layout_struct g_mtv_player_osd_cntx =
{
    {0,     0, 240,  27},    /* title */
    {40,   110, 240,  70},    /* hint */
    {99,  400,   0,   0},    /* channel number */
    {0,     0,   0,   0},    /* channel name */   
        
    {244, 335,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {70,  331,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {14,  331,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {222, 391,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {142, 391,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* rsk */

    {214, 335,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE}    /* vol_status */
};
#endif /* __MMI_FTE_SUPPORT__ */

mtv_player_layout_struct g_mtv_player_osd_cntx_270 =
{
#ifdef __MMI_FTE_SUPPORT__
    {0,     0, 233,   7},   /* title */
    {80,    50, 320, 140},   /* hint */
    {195, 280,   0,   0},    /* channel number */
    {0,     0,   0,   0},    /* channel name */
        
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */    
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {344, 269,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {286, 269,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {227, 269,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {88, 269,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {424,   9,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE}     /* rsk */
#else
    {0,     0, 233,  27},   /* title */
    {80,    50, 320, 140},   /* hint */
    {73,  281,   0,   0},    /* channel number */
    {0,     0,   0,   0},    /* channel name */
        
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */    
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {312, 273,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {250, 273,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {177, 273,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {110, 273,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {430,   4,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE}     /* rsk */
#endif
#ifdef __MMI_FTE_SUPPORT__
    ,
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE},    /* vol bg */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE},    /* vol status */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE},    /* vol bar */
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE}     /* vol indx */
#else
    ,
    {0,     0,   0,   0, MTV_PLAYER_ICON_STATUS_DISABLE}    /* vol_status */
#endif /* __MMI_FTE_SUPPORT__ */    
};

#else /* other LCD size */
#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */

#endif /* __MMI_ATV_SUPPORT__ */
