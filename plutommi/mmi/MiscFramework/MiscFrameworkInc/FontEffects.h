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
 *  FontEffects.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Default font effects parameters description.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "MMIDataType.h"
#include "FontRes.h"

#ifndef _FONTEFFECTS_H
#define _FONTEFFECTS_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#if defined(__MMI_FONT_EFFECTS__)

/*********************************************************************************************
* Font effects macros: Start 
*********************************************************************************************/
#if defined(__MMI_MAINLCD_480X800__)  /* WVGA */
/* Drop Shadow */
#define SHADOW_DISTANT_E1_1 2
#define SHADOW_DEGREE_E1_1 135
#define SHADOW_RANGE_E1_1 0
#define SHADOW_TRANSPARENCY_E1_1 15

#define SHADOW_DISTANT_E1_2 2
#define SHADOW_DEGREE_E1_2 135
#define SHADOW_RANGE_E1_2 0
#define SHADOW_TRANSPARENCY_E1_2 60

#define SHADOW_DISTANT_E1_3 2
#define SHADOW_DEGREE_E1_3 -45
#define SHADOW_RANGE_E1_3 0
#define SHADOW_TRANSPARENCY_E1_3 40

#define SHADOW_DISTANT_E1_4 2
#define SHADOW_DEGREE_E1_4 -45
#define SHADOW_RANGE_E1_4 0
#define SHADOW_TRANSPARENCY_E1_4 60

#define SHADOW_DISTANT_E1_5 2
#define SHADOW_DEGREE_E1_5 -90
#define SHADOW_RANGE_E1_5 0
#define SHADOW_TRANSPARENCY_E1_5 60

#define SHADOW_DISTANT_E1_6 2
#define SHADOW_DEGREE_E1_6 -90
#define SHADOW_RANGE_E1_6 0
#define SHADOW_TRANSPARENCY_E1_6 60

#define SHADOW_DISTANT_E1_7 2
#define SHADOW_DEGREE_E1_7 90
#define SHADOW_RANGE_E1_7 0
#define SHADOW_TRANSPARENCY_E1_7 15

#define SHADOW_DISTANT_E1_8 2
#define SHADOW_DEGREE_E1_8 90
#define SHADOW_RANGE_E1_8 0
#define SHADOW_TRANSPARENCY_E1_8 80

#define SHADOW_DISTANT_E1_9 2
#define SHADOW_DEGREE_E1_9 135
#define SHADOW_RANGE_E1_9 0
#define SHADOW_TRANSPARENCY_E1_9 40

/* Add new shadow effects macro's below */

/* Outer Glow */
#define OUTERGLOW_RANGE_E2_1 3
#define OUTERGLOW_TRANSPARENCY_E2_1 100

/* Add new outer glow effects macro's below */

/* Enhanced Engraved */
#define ENGRAVED_DEGREE_E3_1 90
#define ENGRAVED_TRANSPARENCY_E3_1 100

/* Add new engraved effects macro's below */

/* Gradient */
#define GRADIENT_TRANSPARENCY_E4_1 100
#define GRADIENT_DIRECTION_E4_1 MMI_FE_GRADIENT_DIRECTION_VERTICAL

/* Add new gradient effects macro's below */

/* Bordered */
//static mmi_fe_color fe_border_color_E5_1 = {100, 0, 0, 0};
#define BORDER_SIZE_E5_1 2
#define BORDER_TRANSPARENCY_E5_1 50

/* Add new border effects macro's below */

#elif defined(__MMI_MAINLCD_320X480__)   /* HVGA */

/* Drop Shadow */
#define SHADOW_DISTANT_E1_1 1
#define SHADOW_DEGREE_E1_1 135
#define SHADOW_RANGE_E1_1 0
#define SHADOW_TRANSPARENCY_E1_1 15

#define SHADOW_DISTANT_E1_2 1
#define SHADOW_DEGREE_E1_2 135
#define SHADOW_RANGE_E1_2 0
#define SHADOW_TRANSPARENCY_E1_2 60

#define SHADOW_DISTANT_E1_3 1
#define SHADOW_DEGREE_E1_3 -45
#define SHADOW_RANGE_E1_3 0
#define SHADOW_TRANSPARENCY_E1_3 40

#define SHADOW_DISTANT_E1_4 1
#define SHADOW_DEGREE_E1_4 -45
#define SHADOW_RANGE_E1_4 0
#define SHADOW_TRANSPARENCY_E1_4 60

#define SHADOW_DISTANT_E1_5 1
#define SHADOW_DEGREE_E1_5 -90
#define SHADOW_RANGE_E1_5 0
#define SHADOW_TRANSPARENCY_E1_5 60

#define SHADOW_DISTANT_E1_6 1
#define SHADOW_DEGREE_E1_6 -90
#define SHADOW_RANGE_E1_6 0
#define SHADOW_TRANSPARENCY_E1_6 60

#define SHADOW_DISTANT_E1_7 1
#define SHADOW_DEGREE_E1_7 90
#define SHADOW_RANGE_E1_7 0
#define SHADOW_TRANSPARENCY_E1_7 15

#define SHADOW_DISTANT_E1_8 1
#define SHADOW_DEGREE_E1_8 90
#define SHADOW_RANGE_E1_8 0
#define SHADOW_TRANSPARENCY_E1_8 80

#define SHADOW_DISTANT_E1_9 1
#define SHADOW_DEGREE_E1_9 135
#define SHADOW_RANGE_E1_9 0
#define SHADOW_TRANSPARENCY_E1_9 40

/* Add new shadow effects macro's below */

/* Outer Glow */
#define OUTERGLOW_RANGE_E2_1 3
#define OUTERGLOW_TRANSPARENCY_E2_1 100

/* Add new outer glow effects macro's below */

/* Enhanced Engraved */
#define ENGRAVED_DEGREE_E3_1 90
#define ENGRAVED_TRANSPARENCY_E3_1 100

/* Add new engraved effects macro's below */

/* Gradient */
#define GRADIENT_TRANSPARENCY_E4_1 100
#define GRADIENT_DIRECTION_E4_1 MMI_FE_GRADIENT_DIRECTION_VERTICAL

/* Add new gradient effects macro's below */

/* Bordered */
//static mmi_fe_color fe_border_color_E5_1 = {100, 0, 0, 0};
#define BORDER_SIZE_E5_1 2
#define BORDER_TRANSPARENCY_E5_1 50

/* Add new border effects macro's below */
#else  /* Default */

/* Drop Shadow */
#define SHADOW_DISTANT_E1_1 1
#define SHADOW_DEGREE_E1_1 135
#define SHADOW_RANGE_E1_1 0
#define SHADOW_TRANSPARENCY_E1_1 15

#define SHADOW_DISTANT_E1_2 1
#define SHADOW_DEGREE_E1_2 135
#define SHADOW_RANGE_E1_2 0
#define SHADOW_TRANSPARENCY_E1_2 60

#define SHADOW_DISTANT_E1_3 1
#define SHADOW_DEGREE_E1_3 -45
#define SHADOW_RANGE_E1_3 0
#define SHADOW_TRANSPARENCY_E1_3 40

#define SHADOW_DISTANT_E1_4 1
#define SHADOW_DEGREE_E1_4 -45
#define SHADOW_RANGE_E1_4 0
#define SHADOW_TRANSPARENCY_E1_4 60

#define SHADOW_DISTANT_E1_5 1
#define SHADOW_DEGREE_E1_5 -90
#define SHADOW_RANGE_E1_5 0
#define SHADOW_TRANSPARENCY_E1_5 60

#define SHADOW_DISTANT_E1_6 1
#define SHADOW_DEGREE_E1_6 -90
#define SHADOW_RANGE_E1_6 0
#define SHADOW_TRANSPARENCY_E1_6 60

#define SHADOW_DISTANT_E1_7 1
#define SHADOW_DEGREE_E1_7 90
#define SHADOW_RANGE_E1_7 0
#define SHADOW_TRANSPARENCY_E1_7 15

#define SHADOW_DISTANT_E1_8 1
#define SHADOW_DEGREE_E1_8 90
#define SHADOW_RANGE_E1_8 0
#define SHADOW_TRANSPARENCY_E1_8 80

#define SHADOW_DISTANT_E1_9 1
#define SHADOW_DEGREE_E1_9 135
#define SHADOW_RANGE_E1_9 0
#define SHADOW_TRANSPARENCY_E1_9 40

/* Add new shadow effects macro's below */

/* Outer Glow */
#define OUTERGLOW_RANGE_E2_1 3
#define OUTERGLOW_TRANSPARENCY_E2_1 100

/* Add new outer glow effects macro's below */

/* Enhanced Engraved */
#define ENGRAVED_DEGREE_E3_1 90
#define ENGRAVED_TRANSPARENCY_E3_1 100

/* Add new engraved effects macro's below */

/* Gradient */
#define GRADIENT_TRANSPARENCY_E4_1 100
#define GRADIENT_DIRECTION_E4_1 MMI_FE_GRADIENT_DIRECTION_VERTICAL

/* Add new gradient effects macro's below */

/* Bordered */
//static mmi_fe_color fe_border_color_E5_1 = {100, 0, 0, 0};
#define BORDER_SIZE_E5_1 2
#define BORDER_TRANSPARENCY_E5_1 50

/* Add new border effects macro's below */

#endif
/*********************************************************************************************
* Font effects macros: End 
*********************************************************************************************/

/*********************************************************************************************
* Font effects ID: Start 
*********************************************************************************************/
typedef enum
{
    /* Drop Shadow */
    MMI_FE_FONT_EFFECT_E1_1 = FONTS_EFFECT_NODE_START,
    MMI_FE_FONT_EFFECT_E1_2,
    MMI_FE_FONT_EFFECT_E1_3,
    MMI_FE_FONT_EFFECT_E1_4,
    MMI_FE_FONT_EFFECT_E1_5,
    MMI_FE_FONT_EFFECT_E1_6,
    MMI_FE_FONT_EFFECT_E1_7,
    MMI_FE_FONT_EFFECT_E1_8,
    MMI_FE_FONT_EFFECT_E1_9,
    /* Add new shadow effects enum hare */

    /* Outer Glow */
    MMI_FE_FONT_EFFECT_E2_1,
    /* Add new outer glow effects enum hare */

    /* Enhanced Engraved */
    MMI_FE_FONT_EFFECT_E3_1,
    /* Add new engraved effects enum hare */

    /* Gradient */
    MMI_FE_FONT_EFFECT_E4_1,
    /* Add new gradient effects enum hare */

    /* Bordered */
    MMI_FE_FONT_EFFECT_E5_1,
    /* Add new border effects enum hare */

    MMI_FE_FONT_EFFECT_MAX,
	MMI_FE_FONT_EFFECT_FINAL_MAX = MMI_FE_FONT_EFFECT_MAX - FONTS_EFFECT_NODE_START
} mmi_fe_sub_font_effect_enum;
/*********************************************************************************************
* Font effects ID: End 
*********************************************************************************************/

#endif /* __MMI_FONT_EFFECTS__ */


#ifdef __cplusplus
}
#endif /* __cplusplus */ 

#endif /* _FONTEFFECTS_H */

