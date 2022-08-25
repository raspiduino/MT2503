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
 *   color_drv_api.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Common interface for COLOR HW driver.
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features_color.h"

#ifndef __COLOR_DRV_API_H__
#define __COLOR_DRV_API_H__

#ifdef FPGA
   #include "typedefs.h"
#else
   #include "kal_general_types.h"
#endif

#if defined(__DRV_COLOR_MT6260_SERIES__) && defined(__DRV_COLOR_HW_SUPPORT__)
   #include "color_drv_6260_series.h"
#endif


/* COLOR driver common API prototypes */
kal_uint32 color_drv_power_on(void);
kal_uint32 color_drv_power_off(void);

/* COLOR driver common API prototypes */
kal_uint32 color_drv_set_sharpness(kal_uint32 gain, kal_uint32 soft_ratio, kal_uint32 limit, kal_uint32 bound);
kal_uint32 color_drv_set_contrast_point(kal_uint32 point0, kal_uint32 point1);
kal_uint32 color_drv_set_contrast_gain(kal_uint32 gain0, kal_uint32 gain1, kal_uint32 gain2);
kal_uint32 color_drv_set_contrast_offset(kal_uint32 offset0, kal_uint32 offset1);
kal_uint32 color_drv_set_saturation_point(kal_uint32 con_point, kal_uint32 coef_a, kal_uint32 coef_b);
kal_uint32 color_drv_set_saturation_gain(kal_uint32 gain);
kal_uint32 color_drv_set_source_size(kal_uint32 src_w);
kal_uint32 color_drv_set_bypass(kal_uint32 bypass_config);
kal_uint32 color_drv_set_enable(kal_uint32 enable);

#endif  // __COLOR_DRV_API_H__

