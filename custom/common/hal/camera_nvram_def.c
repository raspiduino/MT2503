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
 * camera_nvram_def.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file contains `vendor' defined logical data items stored in NVRAM.
 *    These logical data items are used in object code of Protocol Stack software.
 *
 *    As for customizable logical data items, they are defined in nvram_user_config.c
 *
 * Author:
 * -------
 * 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef NVRAM_NOT_PRESENT


/*
 *   Include Headers
 */

#include "kal_general_types.h"

/*
 *   NVRAM Basic Headers
 */
#ifdef NVRAM_AUTO_GEN
#include "nvram_auto_gen.h"
#endif

#include "nvram_enums.h"
#include "nvram_defs.h"
#include "nvram_data_items.h"

/*
 *   User Headers & Default value
 */
#if(defined(ISP_SUPPORT))
#include "camera_nvram_def.h"
#include "drv_sw_features_isp.h"
#include "camera_tuning_para.h"
#endif 


/*
 *   LID table
 */
#if(defined(ISP_SUPPORT))
ltable_entry_struct logical_data_item_table_camera[] =
{
#if (defined(ISP_SUPPORT) && (!defined(DRV_ISP_6238_SERIES)) && (!(defined(DUAL_CAMERA_SUPPORT)||defined(BACKUP_SENSOR_SUPPORT))))
    {
          NVRAM_EF_CAMERA_PARA_LID,
          NVRAM_EF_CAMERA_PARA_TOTAL,
          NVRAM_EF_CAMERA_PARA_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_PARA_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT50",
          VER(NVRAM_EF_CAMERA_PARA_LID)
    },
#endif/* (defined(ISP_SUPPORT) && (!defined(DRV_ISP_6238_SERIES)) && (!defined(BACKUP_SENSOR_SUPPORT))) */
#if defined(ISP_SUPPORT) && (defined(DRV_ISP_6227_SERIES) || defined(DRV_ISP_6229_SERIES))
    {
          NVRAM_EF_CAMERA_GAMMA_LID,
          NVRAM_EF_CAMERA_GAMMA_TOTAL,
          NVRAM_EF_CAMERA_GAMMA_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_GAMMA_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT51",
          VER(NVRAM_EF_CAMERA_GAMMA_LID)
    },
#endif/*defined(ISP_SUPPORT) && (defined(DRV_ISP_6227_SERIES) || defined(DRV_ISP_6229_SERIES))*/

#if defined(ISP_SUPPORT) && (defined(DRV_ISP_6227_SERIES) || defined(DRV_ISP_6229_SERIES) || defined(DRV_ISP_6228_SERIES))
    {
          NVRAM_EF_CAMERA_DEFECT_LID,
          NVRAM_EF_CAMERA_DEFECT_TOTAL,
          NVRAM_EF_CAMERA_DEFECT_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_DEFECT_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT52",
          VER(NVRAM_EF_CAMERA_DEFECT_LID)
    },
#endif /*defined(ISP_SUPPORT) && (defined(DRV_ISP_6227_SERIES) || defined(DRV_ISP_6229_SERIES) || defined(DRV_ISP_6228_SERIES))*/

#if defined(ISP_SUPPORT) && (defined(DRV_ISP_6227_SERIES) || defined(DRV_ISP_6229_SERIES) || defined(DRV_ISP_6228_SERIES))
    {
          NVRAM_EF_CAMERA_LENS_LID,
          NVRAM_EF_CAMERA_LENS_TOTAL,
          NVRAM_EF_CAMERA_LENS_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_LENS_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT53",
          VER(NVRAM_EF_CAMERA_LENS_LID)
    },
#endif/*defined(ISP_SUPPORT) && (defined(DRV_ISP_6227_SERIES) || defined(DRV_ISP_6229_SERIES) || defined(DRV_ISP_6228_SERIES))*/

#if (defined(ISP_SUPPORT) && defined(DRV_ISP_6238_SERIES))
  #if(!(defined(DUAL_CAMERA_SUPPORT) || defined(BACKUP_SENSOR_SUPPORT)))

    {
          NVRAM_EF_CAMERA_PARA1_LID,
          NVRAM_EF_CAMERA_PARA1_TOTAL,
          NVRAM_EF_CAMERA_PARA1_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_PARA_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT54",
          VER(NVRAM_EF_CAMERA_PARA1_LID)
    },

    #if (defined(DRV_ISP_6238_SERIES) && defined(RAW_MAIN_CAMERA))
    {
          NVRAM_EF_CAMERA_PARA2_LID,
          NVRAM_EF_CAMERA_PARA2_TOTAL,
          NVRAM_EF_CAMERA_PARA2_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_3A_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT55",
          VER(NVRAM_EF_CAMERA_PARA2_LID)
    },

    {
          NVRAM_EF_CAMERA_DEFECT1_LID,
          NVRAM_EF_CAMERA_DEFECT1_TOTAL,
          NVRAM_EF_CAMERA_DEFECT1_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_DEFECT1_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT56",
          VER(NVRAM_EF_CAMERA_DEFECT1_LID)
    },

    {
          NVRAM_EF_CAMERA_DEFECT2_LID,
          NVRAM_EF_CAMERA_DEFECT2_TOTAL,
          NVRAM_EF_CAMERA_DEFECT2_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_DEFECT2_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT57",
          VER(NVRAM_EF_CAMERA_DEFECT2_LID)
    },

    {
          NVRAM_EF_CAMERA_SHADING1_LID,
          NVRAM_EF_CAMERA_SHADING1_TOTAL,
          NVRAM_EF_CAMERA_SHADING1_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_SHADING1_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT58",
          VER(NVRAM_EF_CAMERA_SHADING1_LID)
    },

    {
          NVRAM_EF_CAMERA_SHADING2_LID,
          NVRAM_EF_CAMERA_SHADING2_TOTAL,
          NVRAM_EF_CAMERA_SHADING2_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_SHADING2_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT59",
          VER(NVRAM_EF_CAMERA_SHADING2_LID)
    },
    #endif
 #endif  //  #if(!(defined(DUAL_CAMERA_SUPPORT) || defined(BACKUP_SENSOR_SUPPORT)))
#endif/*defined(ISP_SUPPORT) && defined(DRV_ISP_6238_SERIES) */

#if (defined(ISP_SUPPORT) && defined(DRV_ISP_6238_SERIES))
#if (defined(DUAL_CAMERA_SUPPORT) || defined(BACKUP_SENSOR_SUPPORT))
    {
          NVRAM_EF_CAMERA_PARA1_MAIN_LID,
          NVRAM_EF_CAMERA_PARA1_MAIN_TOTAL,
          NVRAM_EF_CAMERA_PARA1_MAIN_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_PARA_MAIN_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT5A",
          VER(NVRAM_EF_CAMERA_PARA1_MAIN_LID)
    },

  #if defined(DRV_ISP_6238_SERIES)
    {
          NVRAM_EF_CAMERA_PARA2_MAIN_LID,
          NVRAM_EF_CAMERA_PARA2_MAIN_TOTAL,
          NVRAM_EF_CAMERA_PARA2_MAIN_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_3A_MAIN_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT5B",
          VER(NVRAM_EF_CAMERA_PARA2_MAIN_LID)
    },

    {
          NVRAM_EF_CAMERA_DEFECT1_MAIN_LID,
          NVRAM_EF_CAMERA_DEFECT1_MAIN_TOTAL,
          NVRAM_EF_CAMERA_DEFECT1_MAIN_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_DEFECT1_MAIN_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT5C",
          VER(NVRAM_EF_CAMERA_DEFECT1_MAIN_LID)
    },

    {
          NVRAM_EF_CAMERA_DEFECT2_MAIN_LID,
          NVRAM_EF_CAMERA_DEFECT2_MAIN_TOTAL,
          NVRAM_EF_CAMERA_DEFECT2_MAIN_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_DEFECT2_MAIN_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT5D",
          VER(NVRAM_EF_CAMERA_DEFECT2_MAIN_LID)
    },

    {
          NVRAM_EF_CAMERA_SHADING1_MAIN_LID,
          NVRAM_EF_CAMERA_SHADING1_MAIN_TOTAL,
          NVRAM_EF_CAMERA_SHADING1_MAIN_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_SHADING1_MAIN_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT5E",
          VER(NVRAM_EF_CAMERA_SHADING1_MAIN_LID)
    },

    {
          NVRAM_EF_CAMERA_SHADING2_MAIN_LID,
          NVRAM_EF_CAMERA_SHADING2_MAIN_TOTAL,
          NVRAM_EF_CAMERA_SHADING2_MAIN_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_SHADING2_MAIN_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT5F",
          VER(NVRAM_EF_CAMERA_SHADING2_MAIN_LID)
    },
    #endif

#if (defined(CMOS_SENSOR_SUB)) /*keep this sequence*/
    {
          NVRAM_EF_CAMERA_PARA1_SUB_LID,
          NVRAM_EF_CAMERA_PARA1_SUB_TOTAL,
          NVRAM_EF_CAMERA_PARA1_SUB_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_PARA_SUB_DEFAULT_VALUE),
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          NVRAM_CATEGORY_USER,
          "MT5G",
          VER(NVRAM_EF_CAMERA_PARA1_SUB_LID)
    },
    #if (defined(DRV_ISP_6238_SERIES) && defined(RAW_MAIN_CAMERA))
    {
          NVRAM_EF_CAMERA_PARA2_SUB_LID,
          NVRAM_EF_CAMERA_PARA2_SUB_TOTAL,
          NVRAM_EF_CAMERA_PARA2_SUB_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_3A_SUB_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT5H",
          VER(NVRAM_EF_CAMERA_PARA2_SUB_LID)
    },

    {
          NVRAM_EF_CAMERA_DEFECT1_SUB_LID,
          NVRAM_EF_CAMERA_DEFECT1_SUB_TOTAL,
          NVRAM_EF_CAMERA_DEFECT1_SUB_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_DEFECT1_SUB_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT5I",
          VER(NVRAM_EF_CAMERA_DEFECT1_SUB_LID)
    },

    {
          NVRAM_EF_CAMERA_DEFECT2_SUB_LID,
          NVRAM_EF_CAMERA_DEFECT2_SUB_TOTAL,
          NVRAM_EF_CAMERA_DEFECT2_SUB_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_DEFECT2_SUB_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT5J",
          VER(NVRAM_EF_CAMERA_DEFECT2_SUB_LID)
    },

    {
          NVRAM_EF_CAMERA_SHADING1_SUB_LID,
          NVRAM_EF_CAMERA_SHADING1_SUB_TOTAL,
          NVRAM_EF_CAMERA_SHADING1_SUB_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_SHADING1_SUB_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT5K",
          VER(NVRAM_EF_CAMERA_SHADING1_SUB_LID)
    },

    {
          NVRAM_EF_CAMERA_SHADING2_SUB_LID,
          NVRAM_EF_CAMERA_SHADING2_SUB_TOTAL,
          NVRAM_EF_CAMERA_SHADING2_SUB_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_SHADING2_SUB_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT5L",
          VER(NVRAM_EF_CAMERA_SHADING2_SUB_LID)
    },
#endif
#endif

#if (defined(CMOS_SENSOR_BAK1)) /*keep this sequence*/
    {
          NVRAM_EF_CAMERA_PARA1_MAIN_BAK1_LID,
          NVRAM_EF_CAMERA_PARA1_MAIN_BAK1_TOTAL,
          NVRAM_EF_CAMERA_PARA1_MAIN_BAK1_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_PARA_MAIN_BAK1_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT5M",
          VER(NVRAM_EF_CAMERA_PARA1_MAIN_BAK1_LID)
    },

    #if (defined(DRV_ISP_6238_SERIES) && defined(RAW_MAIN_CAMERA))
    {
          NVRAM_EF_CAMERA_PARA2_MAIN_BAK1_LID,
          NVRAM_EF_CAMERA_PARA2_MAIN_BAK1_TOTAL,
          NVRAM_EF_CAMERA_PARA2_MAIN_BAK1_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_3A_MAIN_BAK1_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT5N",
          VER(NVRAM_EF_CAMERA_PARA2_MAIN_BAK1_LID)
    },

    {
          NVRAM_EF_CAMERA_DEFECT1_MAIN_BAK1_LID,
          NVRAM_EF_CAMERA_DEFECT1_MAIN_BAK1_TOTAL,
          NVRAM_EF_CAMERA_DEFECT1_MAIN_BAK1_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_DEFECT1_MAIN_BAK1_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT5O",
          VER(NVRAM_EF_CAMERA_DEFECT1_MAIN_BAK1_LID)
    },

    {
          NVRAM_EF_CAMERA_DEFECT2_MAIN_BAK1_LID,
          NVRAM_EF_CAMERA_DEFECT2_MAIN_BAK1_TOTAL,
          NVRAM_EF_CAMERA_DEFECT2_MAIN_BAK1_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_DEFECT2_MAIN_BAK1_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT5P",
          VER(NVRAM_EF_CAMERA_DEFECT2_MAIN_BAK1_LID)
    },
    
    {
          NVRAM_EF_CAMERA_SHADING1_MAIN_BAK1_LID,
          NVRAM_EF_CAMERA_SHADING1_MAIN_BAK1_TOTAL,
          NVRAM_EF_CAMERA_SHADING1_MAIN_BAK1_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_SHADING1_MAIN_BAK1_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT5Q",
          VER(NVRAM_EF_CAMERA_SHADING1_MAIN_BAK1_LID)
    },
    
    {
          NVRAM_EF_CAMERA_SHADING2_MAIN_BAK1_LID,
          NVRAM_EF_CAMERA_SHADING2_MAIN_BAK1_TOTAL,
          NVRAM_EF_CAMERA_SHADING2_MAIN_BAK1_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_SHADING2_MAIN_BAK1_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT5R",
          VER(NVRAM_EF_CAMERA_SHADING2_MAIN_BAK1_LID)
    },
    
#endif
#endif

#if (defined(CMOS_SENSOR_SUB_BAK1)) /*keep this sequence*/
    {
          NVRAM_EF_CAMERA_PARA1_SUB_BAK1_LID,
          NVRAM_EF_CAMERA_PARA1_SUB_BAK1_TOTAL,
          NVRAM_EF_CAMERA_PARA1_SUB_BAK1_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_PARA_SUB_BAK1_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT5S",
          VER(NVRAM_EF_CAMERA_PARA1_SUB_BAK1_LID)
    },
    #if (defined(DRV_ISP_6238_SERIES) && defined(RAW_MAIN_CAMERA))
    {
          NVRAM_EF_CAMERA_PARA2_SUB_BAK1_LID,
          NVRAM_EF_CAMERA_PARA2_SUB_BAK1_TOTAL,
          NVRAM_EF_CAMERA_PARA2_SUB_BAK1_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_3A_SUB_BAK1_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT5T",
          VER(NVRAM_EF_CAMERA_PARA2_SUB_BAK1_LID)
    },
    
    {
          NVRAM_EF_CAMERA_DEFECT1_SUB_BAK1_LID,
          NVRAM_EF_CAMERA_DEFECT1_SUB_BAK1_TOTAL,
          NVRAM_EF_CAMERA_DEFECT1_SUB_BAK1_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_DEFECT1_SUB_BAK1_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT5U",
          VER(NVRAM_EF_CAMERA_DEFECT1_SUB_BAK1_LID)
    },
    
    {
          NVRAM_EF_CAMERA_DEFECT2_SUB_BAK1_LID,
          NVRAM_EF_CAMERA_DEFECT2_SUB_BAK1_TOTAL,
          NVRAM_EF_CAMERA_DEFECT2_SUB_BAK1_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_DEFECT2_SUB_BAK1_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT5V",
          VER(NVRAM_EF_CAMERA_DEFECT2_SUB_BAK1_LID)
    },
    
    {
          NVRAM_EF_CAMERA_SHADING1_SUB_BAK1_LID,
          NVRAM_EF_CAMERA_SHADING1_SUB_BAK1_TOTAL,
          NVRAM_EF_CAMERA_SHADING1_SUB_BAK1_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_SHADING1_SUB_BAK1_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT5W",
          VER(NVRAM_EF_CAMERA_SHADING1_SUB_BAK1_LID)
    },
    
    {
          NVRAM_EF_CAMERA_SHADING2_SUB_BAK1_LID,
          NVRAM_EF_CAMERA_SHADING2_SUB_BAK1_TOTAL,
          NVRAM_EF_CAMERA_SHADING2_SUB_BAK1_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_SHADING2_SUB_BAK1_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT5X",
          VER(NVRAM_EF_CAMERA_SHADING2_SUB_BAK1_LID)
    },
    #endif
#endif
#endif/* defined(DUAL_CAMERA_SUPPORT) || defined(BACKUP_SENSOR_SUPPORT) */
#endif/* defined(ISP_SUPPORT) && defined(DRV_ISP_6238_SERIES) */

#if defined (ISP_SUPPORT)
    {
          NVRAM_EF_CAMERA_MAIN_SENSOR_ID_LID,
          NVRAM_EF_CAMERA_MAIN_SENSOR_ID_TOTAL,
          NVRAM_EF_CAMERA_MAIN_SENSOR_ID_SIZE,
          NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
          "MT5Y",
          VER(NVRAM_EF_CAMERA_MAIN_SENSOR_ID_LID)
    },

#if defined(DUAL_CAMERA_SUPPORT)
    {
          NVRAM_EF_CAMERA_SUB_SENSOR_ID_LID,
          NVRAM_EF_CAMERA_SUB_SENSOR_ID_TOTAL,
          NVRAM_EF_CAMERA_SUB_SENSOR_ID_SIZE,
          NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
          "MT5Z",
          VER(NVRAM_EF_CAMERA_SUB_SENSOR_ID_LID)
    },
#endif /* defined(DUAL_CAMERA_SUPPORT) */
#endif /* defined (ISP_SUPPORT) */

#if (defined(ISP_SUPPORT) && (defined(DRV_ISP_6235_SERIES)||defined(DRV_ISP_6276_SERIES)) && (defined(DUAL_CAMERA_SUPPORT)||defined(BACKUP_SENSOR_SUPPORT)))
    {
          NVRAM_EF_CAMERA_PARA_MAIN_LID,
          NVRAM_EF_CAMERA_PARA_MAIN_TOTAL,
          NVRAM_EF_CAMERA_PARA_MAIN_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_PARA_MAIN_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT60",
          VER(NVRAM_EF_CAMERA_PARA_MAIN_LID)
    },
    
#if (defined(CMOS_SENSOR_BAK1)) /*keep this sequence*/
    {
          NVRAM_EF_CAMERA_PARA_MAIN_BAK1_LID,
          NVRAM_EF_CAMERA_PARA_MAIN_BAK1_TOTAL,
          NVRAM_EF_CAMERA_PARA_MAIN_BAK1_SIZE,
          NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_PARA_MAIN_BAK1_DEFAULT_VALUE),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
          "MT61",
          VER(NVRAM_EF_CAMERA_PARA_MAIN_BAK1_LID)
    },
#endif

#if (defined(CMOS_SENSOR_SUB)) /*keep this sequence*/
    {
        NVRAM_EF_CAMERA_PARA_SUB_LID,
        NVRAM_EF_CAMERA_PARA_SUB_TOTAL,
        NVRAM_EF_CAMERA_PARA_SUB_SIZE,
        NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_PARA_SUB_DEFAULT_VALUE),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MP7T",
        VER(NVRAM_EF_CAMERA_PARA_SUB_LID)
    },
#endif

#if (defined(CMOS_SENSOR_SUB_BAK1)) /*keep this sequence*/
    {
        NVRAM_EF_CAMERA_PARA_SUB_BAK1_LID,
        NVRAM_EF_CAMERA_PARA_SUB_BAK1_TOTAL,
        NVRAM_EF_CAMERA_PARA_SUB_BAK1_SIZE,
        NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_PARA_SUB_BAK1_DEFAULT_VALUE),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MP7U",
        VER(NVRAM_EF_CAMERA_PARA_SUB_BAK1_LID)
    },
#endif 
#endif/* defined(ISP_SUPPORT) && defined(DRV_ISP_6235_SERIES) && defined(BACKUP_SENSOR_SUPPORT) */

#if defined(DRV_ISP_PCA_SUPPORT)
#if (defined(ISP_SUPPORT) && defined(DRV_ISP_6238_SERIES))
    #if(!(defined(DUAL_CAMERA_SUPPORT) || defined(BACKUP_SENSOR_SUPPORT)))
    {
              NVRAM_EF_CAMERA_PCA_LID,
              NVRAM_EF_CAMERA_PCA_TOTAL,
              NVRAM_EF_CAMERA_PCA_SIZE,
              NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_PCA_DEFAULT_VALUE),
              NVRAM_CATEGORY_USER,
              NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
              "MT62",
              VER(NVRAM_EF_CAMERA_PCA_LID)
    },

    #if defined (__AUTO_SCENE_DETECT_SUPPORT__)      
      {
              NVRAM_EF_CAMERA_PCA2_LID,
              NVRAM_EF_CAMERA_PCA2_TOTAL,
              NVRAM_EF_CAMERA_PCA2_SIZE,
              NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_PCA2_DEFAULT_VALUE),
              NVRAM_CATEGORY_USER,
              NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,              
              "MI62",
              VER(NVRAM_EF_CAMERA_PCA2_LID)              
      },
    #endif      
			  
    #endif /* !(defined(DUAL_CAMERA_SUPPORT) || defined(BACKUP_SENSOR_SUPPORT)) */

    #if (defined(DUAL_CAMERA_SUPPORT) || defined(BACKUP_SENSOR_SUPPORT))
    {
              NVRAM_EF_CAMERA_PCA_MAIN_LID,
              NVRAM_EF_CAMERA_PCA_MAIN_TOTAL,
              NVRAM_EF_CAMERA_PCA_MAIN_SIZE,
              NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_PCA_MAIN_DEFAULT_VALUE),
              NVRAM_CATEGORY_USER,
              NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
              "MT63",
              VER(NVRAM_EF_CAMERA_PCA_MAIN_LID),
    },

    #if defined (__AUTO_SCENE_DETECT_SUPPORT__)      
      {
              NVRAM_EF_CAMERA_PCA2_MAIN_LID,
              NVRAM_EF_CAMERA_PCA2_MAIN_TOTAL,
              NVRAM_EF_CAMERA_PCA2_MAIN_SIZE,
              NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_PCA2_MAIN_DEFAULT_VALUE),
              NVRAM_CATEGORY_USER,              
              NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,              
              "MI63",
              VER(NVRAM_EF_CAMERA_PCA2_MAIN_LID)
      },
    #endif      

    #if (defined(CMOS_SENSOR_SUB))
    {
              NVRAM_EF_CAMERA_PCA_SUB_LID,
              NVRAM_EF_CAMERA_PCA_SUB_TOTAL,
              NVRAM_EF_CAMERA_PCA_SUB_SIZE,
              NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_PCA_SUB_DEFAULT_VALUE),
              NVRAM_CATEGORY_USER,
              NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
              "MT64",
              VER(NVRAM_EF_CAMERA_PCA_SUB_LID)
    },
    #endif

    #if (defined(CMOS_SENSOR_BAK1))
    {
              NVRAM_EF_CAMERA_PCA_MAIN_BAK1_LID,
              NVRAM_EF_CAMERA_PCA_MAIN_BAK1_TOTAL,
              NVRAM_EF_CAMERA_PCA_MAIN_BAK1_SIZE,
              NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_PCA_MAIN_BAK1_DEFAULT_VALUE),
              NVRAM_CATEGORY_USER,
              NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
              "MT65",
              VER(NVRAM_EF_CAMERA_PCA_MAIN_BAK1_LID)
    },
    #endif

    #if defined (__AUTO_SCENE_DETECT_SUPPORT__)      
      {
              NVRAM_EF_CAMERA_PCA2_MAIN_BAK1_LID,
              NVRAM_EF_CAMERA_PCA2_MAIN_BAK1_TOTAL,
              NVRAM_EF_CAMERA_PCA2_MAIN_BAK1_SIZE,
              NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_PCA2_MAIN_BAK1_DEFAULT_VALUE),
              NVRAM_CATEGORY_USER,              
              NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
              "MI65",
              VER(NVRAM_EF_CAMERA_PCA2_MAIN_BAK1_LID)
      },
    #endif      

    #if (defined(CMOS_SENSOR_SUB_BAK1))
    {
              NVRAM_EF_CAMERA_PCA_SUB_BAK1_LID,
              NVRAM_EF_CAMERA_PCA_SUB_BAK1_TOTAL,
              NVRAM_EF_CAMERA_PCA_SUB_BAK1_SIZE,
              NVRAM_NORMAL_NOT_GEN((void*)&CAMERA_PCA_SUB_BAK1_DEFAULT_VALUE),
              NVRAM_CATEGORY_USER,
              NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
              "MT66",
              VER(NVRAM_EF_CAMERA_PCA_SUB_BAK1_LID)
    },
    #endif
    #endif /* !(defined(DUAL_CAMERA_SUPPORT) || defined(BACKUP_SENSOR_SUPPORT)) */
#endif /* defined(ISP_SUPPORT) && defined(DRV_ISP_6238_SERIES) */
#endif /* PCA_SUPPORT */


};
#endif /* ISP_SUPPORT */
#endif /* NVRAM_NOT_PRESENT */
