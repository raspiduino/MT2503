/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   ipp_interface.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Prototypes of IPP(image post process) APIs.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features_color.h"

#ifndef __COLOR_API_H__
#define __COLOR_API_H__

#ifdef FPGA
   #include "typedefs.h"
#else
   #include "kal_general_types.h"
#endif

#include "color_enum.h"
#include "color_structure.h"


COLOR_STATUS_ENUM colorWrapperOpen(COLOR_HANDLE *handle, COLOR_SCENARIO_ENUM scenario);
COLOR_STATUS_ENUM colorWrapperEnable(COLOR_HANDLE handle, kal_uint32 src_width);
COLOR_STATUS_ENUM colorWrapperDisable(COLOR_HANDLE handle);
COLOR_STATUS_ENUM colorWrapperClose(COLOR_HANDLE handle);

COLOR_STATUS_ENUM colorInit(void);
COLOR_STATUS_ENUM colorUpdateConfig(COLOR_PATH_ENUM path, kal_uint32 src_width);
COLOR_STATUS_ENUM colorPowerEnable(kal_bool enable);

kal_uint32 colorGetCustomSharpnessIndex(COLOR_SCENARIO_ENUM scenario);
kal_uint32 colorGetCustomContrastIndex(COLOR_SCENARIO_ENUM scenario);
kal_uint32 colorGetCustomSaturationIndex(COLOR_SCENARIO_ENUM scenario);

COLOR_STATUS_ENUM colorSetCustomSharpnessTableIndex(kal_uint32 index);
COLOR_STATUS_ENUM colorSetCustomContrastTableIndex(kal_uint32 index);
COLOR_STATUS_ENUM colorSetCustomSaturationTableIndex(kal_uint32 index);
COLOR_STATUS_ENUM colorSetCustomEnable(kal_bool enable);
COLOR_STATUS_ENUM colorGetCustomEnable(kal_bool* enable);

#endif  // __COLOR_API_H__

