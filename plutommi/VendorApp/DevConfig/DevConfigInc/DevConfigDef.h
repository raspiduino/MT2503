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
 *   DevConfigDef.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   3rd Party Get the system configuration information
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef DEVCONFIGDEF_H
#define DEVCONFIGDEF_H

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
    MMI_DEVCONFIG_GRAPHICS_CODEC_NONE,    /* graphics codec none */
    MMI_DEVCONFIG_GRAPHICS_CODEC_HW,      /* graphics codec hardware */
    MMI_DEVCONFIG_GRAPHICS_CODEC_SW,      /* graphics codec software */
    MMI_DEVCONFIG_GRAPHICS_CODEC_TOTAL
} mmi_devconfig_graphics_codec_enum;

typedef enum
{
    MMI_DEVCONFIG_SENSOR_ROTATE_0,        /* sensor rotate 0 degree */
    MMI_DEVCONFIG_SENSOR_ROTATE_90,       /* sensor rotate 90 degree */
    MMI_DEVCONFIG_SENSOR_ROTATE_180,      /* sensor rotate 180 degree */
    MMI_DEVCONFIG_SENSOR_ROTATE_270,      /* sensor rotate 270 degree */
    MMI_DEVCONFIG_SENSOR_ROTATE_TOTAL
} mmi_devconfig_sensor_rotate_enum;

typedef enum
{
    MMI_DEVCONFIG_KEYPAD_TYPE_NORMAL,     /* normal keypad type */
    MMI_DEVCONFIG_KEYPAD_TYPE_REDUCED,    /* reduced keypad type */
    MMI_DEVCONFIG_KEYPAD_TYPE_QWERTY,     /* qwerty keypad type */
    MMI_DEVCONFIG_KEYPAD_TYPE_TOTAL
} mmi_devconfig_keypad_type_enum;

typedef enum
{
    MMI_DEVCONFIG_MEMPEY_PROVIDER_NONE,   /* none memory */
    MMI_DEVCONFIG_MEMPEY_PROVIDER_ASM,    /* ASM memory */
    MMI_DEVCONFIG_MEMPEY_PROVIDER_MEDIA,  /* Media memory */
    MMI_DEVCONFIG_MEMOEY_PROVIDER_TOTAL
} mmi_devconfig_memory_provide_enum;

typedef enum
{
    MMI_DEVCONFIG_FONT_ENGINE_MONO_TYPE,  /* momotype font */
    MMI_DEVCONFIG_FONT_ENGINE_FREE_TYPE,  /* freetype font */
    MMI_DEVCONFIG_FONT_ENGINE_TYPE_TOTAL
} mmi_devconfig_font_engine_enum;

typedef enum
{
    MMI_DEVCONFIG_OBIGO_Q03C_MMS_V01,     /* mms q03c v01 */
    MMI_DEVCONFIG_OBIGO_Q03C_MMS_V02,     /* mms q03c v02 */
    MMI_DEVCONFIG_OBIGO_Q03C_MMS_TOTAL
} mmi_devconfig_mms_enum;

#endif /* DEVCONFIGDEF_H */ 

