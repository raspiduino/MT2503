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
 *   color_custom.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This Module defines the custom setting of COLOR.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_sw_features_color.h"

#include "color_enum.h"
#include "color_structure.h"


#if defined(__COLOR_HW_SUPPORTED__)

COLOR_CUSTOM_TABLE_T colorCustomTableIndex[MAX_COLOR_SCENARIO] = 
{
   {1, 3, 7},  // COLOR_SCENARIO_DEFAULT
   {1, 3, 7},  // COLOR_SCENARIO_IMAGE_PLAYBACK
   {1, 3, 7},  // COLOR_SCENARIO_VIDEO_PLAYBACK
   {1, 1, 1},  // COLOR_SCENARIO_VIDEO_ENCODE
   {1, 1, 1},  // COLOR_SCENARIO_CAMERA_PREVIEW
   {1, 1, 1}  // COLOR_SCENARIO_CAMERA_QUICKVIEW
};


COLOR_PATH_ENUM colorCustomPathTable[MAX_COLOR_SCENARIO]=
{
   {COLOR_PATH_LCD},  // COLOR_SCENARIO_DEFAULT
   {COLOR_PATH_LCD},  // COLOR_SCENARIO_IMAGE_PLAYBACK
   {COLOR_PATH_LCD},  // COLOR_SCENARIO_VIDEO_PLAYBACK
   {COLOR_PATH_LCD},  // COLOR_SCENARIO_VIDEO_ENCODE
   {COLOR_PATH_LCD},  // COLOR_SCENARIO_CAMERA_PREVIEW
   {COLOR_PATH_LCD},  // COLOR_SCENARIO_CAMERA_QUICKVIEW
//   {COLOR_PATH_MDP},  // COLOR_SCENARIO_CAMERA_QUICKVIEW
};


COLOR_SHARPNESS_T colorCustomSharpnessTable[COLOR_CUSTOM_SHARPNESS_TABLE_NUM+1]=
{
   {0xFF, 0xFF, 0xFF, 0xFF},  // turn off effect
   
   {4, 8, 2, 4},  // table 1
   {8, 8, 4, 8}, 
   {12, 8, 6, 12},
   {16, 8, 8, 16},
   {20, 8, 10, 20},
   {24, 8, 12, 24},
   {28, 8, 14, 28},
   {32, 8, 16, 32},
   {36, 8, 18, 36},
   {40, 8, 20, 40},
};


COLOR_CONTRAST_T colorCustomContrastTable[COLOR_CUSTOM_CONTRAST_TABLE_NUM+1]=
{
   {0xFF, 0xFF, 0xFF, 0xFF, 0xFF},  // turn off effect

   {64, 192, 128, 128, 128},  // table 1
   {64, 192, 120, 136, 120},
   {64, 192, 112, 144, 112},
   {64, 192, 104, 152, 104},
   {64, 192, 96, 160, 96},
   {64, 192, 88, 168, 88},
   {64, 192, 80, 176, 80},
   {64, 192, 72, 184, 72},
   {64, 192, 64, 192, 64},
   {64, 192, 56, 200, 56},
};


COLOR_SATURATION_T colorCustomSaturationTable[COLOR_CUSTOM_SATURATION_TABLE_NUM+1]=
{
   {0xFFFF, 0xFF, 0xFF},  // turn off effect
   
   {1160, 128, 120},  // table 1
   {1044, 128, 128},
   {928, 128, 136},
   {812, 128, 144},
   {696, 128, 152},
   {580, 128, 160},
   {464, 128, 168},
   {348, 128, 176},
   {232, 128, 184},
   {116, 128, 192},
};

#endif  // __COLOR_HW_SUPPORTED__

