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
 *  DTVPlayerOSD.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files
*****************************************************************************/
#include "MMI_features.h"

#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)

#include "DTVPlayerOSD.h"
#include "lcd_sw_inc.h"

#if ((LCD_WIDTH == 240) && (LCD_HEIGHT == 320)) /* CMMB */
#if defined(__MMI_FTE_SUPPORT__)
dtv_player_layout_struct g_dtv_player_osd_cntx = /* with Time-Shift */
{
    {0,     0, 240,  27},    /* title */
    {0,    80, 240,  70},    /* hint */

    {  0,  20, 240,  33},    /* Subject */
    { 9,  245,  70,  30},    /* prev channel name */
    {85,  245,  70,  30},    /* cur channel name */
    {161, 245,  70,  30},    /* next channel name */

    {8,   205,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* change */
    {7,   243,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* Channel box */
    {199, 216,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */
    {92,  285,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {55,  205,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {102, 205,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* cycle */
    {8,   205,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {156, 285,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* forward */
    {53,  285,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* rewind */
    {211, 205,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {188, 205,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {156, 285,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {53,  285,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {0,   252,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* ts_ind */
    {17,  256,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* ts_bar */
    {0,   283,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {192, 283,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* rsk */

    {178, 211,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},   /* vol_status */
    {  0,   0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE}    /* view */
};
#else /* __MMI_FTE_SUPPORT__ */
dtv_player_layout_struct g_dtv_player_osd_cntx = /* with Time-Shift */
{
    {0,     0, 240,  27},    /* title */
    {0,    80, 240,  70},    /* hint */

    {  0,  20, 240,  36},    /* Subject */
    {  9, 259,  70,  30},    /* prev channel name */
    { 85, 259,  70,  30},    /* cur channel name */
    {161, 259,  70,  30},    /* next channel name */

    {8,   205,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* change */
    {7,   243,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* Channel box */
    {199, 229,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */
    {102, 297,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {55,  218,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {102, 218,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* cycle */
    {  8, 218,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {141, 297,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* forward */
    {73,  297,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* rewind */
    {211, 205,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {188, 205,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {141, 297,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {73,  297,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {0,   252,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* ts_ind */
    {17,  256,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* ts_bar */
    {0,   283,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {192, 283,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* rsk */

    {178, 224,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},   /* vol_status */
    {  0,   0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE}    /* view */

};
#endif /* __MMI_FTE_SUPPORT__ */
dtv_player_layout_struct g_dtv_player_osd_cntx_270 =  /* with Time-Shift */
{
    {0,     0, 320,  27},   /* title */
    {0,    50, 320, 140},   /* hint */

    {  0,   0,   0,   0},    /* Subject */
    {49,  201,  70,  30},    /* prev channel name */
    {125, 201,  70,  30},    /* current channel name */
    {201, 201,  70,  30},    /* next channel name */

    {172, 158,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* change */
    {47,  200,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* Chanenl box */
    {274, 168,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */
    {0,     0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {0,     0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {0,     0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* cycle */
    {213, 158,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {278, 201,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* forward */
    {11,  201,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* rewind */
    {0,     0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {0,     0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {278, 201,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {11,  201,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {0,   281,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* ts_ind */
    {47,  212,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* ts_bar */
    {0,     0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {283,   2,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* rsk */

    {251, 164,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},   /* vol_status */
    {  0,   0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE}    /* view */

};

#elif ((LCD_WIDTH == 240) && (LCD_HEIGHT == 400)) /* CMMB */
#if defined(__MMI_FTE_SUPPORT__)
dtv_player_layout_struct g_dtv_player_osd_cntx =
{
    {0,     0, 220,  27},    /* title */
    {0,   100, 240,  70},    /* hint */

    {0,    21, 240,  42},    /* Subject */
    {9,   325, 70,   30},    /* prev channel name */
    {85,  325, 70,   30},    /* cur channel name */
    {161, 325, 70,   30},    /* next channel name */

    {147, 209,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* change */
    {7,   323,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* Channel box */
    {199, 296,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */
    {92,  365,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {55,  285,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {102, 285,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* cycle */
    {  8, 285,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {156, 365,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* forward */
    {53,  365,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* rewind */
    {212, 267,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {189, 267,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {156, 365,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {53,  365,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {0,   250,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* ts_ind */
    {31,  253,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* ts_bar */
    {0,   363,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {192, 363,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* rsk */

    {178, 291,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},   /* vol_status */
    {  0,   0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE}    /* view */

};
#else
dtv_player_layout_struct g_dtv_player_osd_cntx =
{
    {0,     0, 220,  27},    /* title */
    {0,   100, 240,  70},    /* hint */

    {0,    21, 240,  50},    /* Subject */
    {9,   329, 70,   30},    /* prev channel name */
    {85,  329, 70,   30},    /* cur channel name */
    {161, 329, 70,   30},    /* next channel name */

    {147, 209,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* change */
    {7,   323,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* Channel box */
    {199, 296,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */
    {102, 374,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {55,  285,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {102, 285,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* cycle */
    {  8, 285,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {141, 374,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* forward */
    { 73, 374,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* rewind */
    {212, 267,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {189, 267,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {141, 374,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    { 73, 374,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {0,   250,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* ts_ind */
    {31,  253,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* ts_bar */
    {0,   363,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {192, 363,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* rsk */

    {178, 291,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},   /* vol_status */
    {  0,   0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE}    /* view */

};
#endif

dtv_player_layout_struct g_dtv_player_osd_cntx_270 =
{
    { 0,   0,  255,  27},   /* title */
    {10,   50, 380, 140},   /* hint */

    {0,     0,   0,   0},    /* Subject */
    {49,  202,  70,  30},    /* prev channel name */
    {125, 202,  70,  30},    /* cur channel name */
    {201, 202,  70,  30},    /* next channel name */

    {18,  273,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* change */
    {47,  200,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* Chanenl box */
    {352, 210,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */
    {0,     0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {0,     0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {0,     0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* cycle */
    {365, 161,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {369, 273,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* forward */
    {81,  273,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* rewind */
    {0,     0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {0,     0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {278, 201,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {11,  201,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {0,   146,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* ts_ind */
    {48,  150,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* ts_bar */
    {0,     0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {360,   3,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* rsk */

    {325, 206,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},   /* vol_status */
    {  0,   0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE}    /* view */

};

#elif ((LCD_WIDTH == 320) && (LCD_HEIGHT == 480)) /* CMMB */
#if defined(__MMI_FTE_SUPPORT__)
dtv_player_layout_struct g_dtv_player_osd_cntx =
{
    {0,     0, 320,  27},    /* title */
    {10,  133, 300,  70},    /* hint */

    {0,    20, 320,  50},    /* Subject */
    {44,  384,  74,  36},    /* prev channel name */
    {123, 384,  74,  36},    /* current channel name */
    {203, 384,  74,  36},    /* next channel name */

    {14,  329,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* change */
    {41,  382,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* channel box */
    {259, 341,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */
    {124, 435,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {74,  329,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {134, 329,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* cycle */
    {14,  329,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {279, 385,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* forward */
    {8,   385,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* rewind */
    {0,     0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {0,     0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {279, 385,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {  8, 385,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {0,   389,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* ts_ind */
    {48,  396,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* ts_bar */

    {0,   431,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {254, 431,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* rsk */

    {237,  338,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},   /* vol_status */
    {  0,   0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE}    /* view */

};
#else /* __MMI_FTE_SUPPORT__ */
dtv_player_layout_struct g_dtv_player_osd_cntx =
{
    {0,     0, 320,  27},    /* title */
    {10,  133, 300,  70},    /* hint */

    {0,    20, 320,  51},    /* Subject */
    {44,  392,  74,  36},    /* prev channel name */
    {123, 392,  74,  36},    /* current channel name */
    {203, 392,  74,  36},    /* next channel name */

    {14,  329,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* change */
    {41,  382,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* channel box */
    {259, 341,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */
    {127, 449,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {74,  329,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {134, 329,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* cycle */
    {14,  329,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {280, 394,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* forward */
    {8,   394,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* rewind */
    {0,     0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {0,     0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {280, 394,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {  8, 394,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {0,   389,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* ts_ind */
    {48,  396,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* ts_bar */

    {0,   431,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {254, 431,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* rsk */

    {237,  338,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},   /* vol_status */
    {  0,   0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE}    /* view */

};

#endif /* __MMI_FTE_SUPPORT__ */
dtv_player_layout_struct g_dtv_player_osd_cntx_270 =
{
    {86,    0, 339,  27},   /* title */
    {10,   50, 460, 140},   /* hint */

    {  0,   0,   0,   0},    /* Subject */
    {101, 275,  74,  36},    /* prev channel name */
    {184, 275,  74,  36},    /* current channel name */
    {267, 275,  74,  36},    /* next channel name */

    {18,  273,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* change */
    {98,  273,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* Chanenl box */
    {421, 284,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */
    {0,     0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {0,     0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {0,     0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* cycle */
    {11,  273,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {369, 273,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* forward */
    {81,  273,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* rewind */
    {0,     0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {0,     0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {350, 277,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {62,  277,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {0,   281,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* ts_ind */
    {119, 288,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* ts_bar */
    {0,     0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* lsk */
    {430,   4,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},    /* rsk */

    {396, 281,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE},   /* vol_status */
    {  0,   0,   0,   0, DTV_PLAYER_ICON_STATUS_ENABLE}    /* view */

};

#else /* other LCD size */
#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */

#endif /* __MMI_MOBILE_TV_CMMB_SUPPORT__ */
