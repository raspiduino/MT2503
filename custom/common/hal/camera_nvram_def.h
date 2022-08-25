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
 * ul1_nvram_def.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __CAMERA_NVRAM_DEF_H__
#define __CAMERA_NVRAM_DEF_H__

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

/*
 *   Include Headers
 */


/*
 *   NVRAM Basic Headers
 */
#include "nvram_data_items.h"
#include "nvram_defs.h"


/*
 *   User Headers
 */



/*
 *   Data Structure
 */
#include "isp_nvram.h"

/*
 *   LID Enums
 */
 
typedef enum
{
    NVRAM_EF_CAMERA_PARA_LID                    = NVRAM_LID_GRP_CAMERA(0),
    NVRAM_EF_CAMERA_GAMMA_LID                   = NVRAM_LID_GRP_CAMERA(1),
    NVRAM_EF_CAMERA_DEFECT_LID                  = NVRAM_LID_GRP_CAMERA(2),
    NVRAM_EF_CAMERA_LENS_LID                    = NVRAM_LID_GRP_CAMERA(3),
    NVRAM_EF_CAMERA_PARA1_LID                   = NVRAM_LID_GRP_CAMERA(4),
    NVRAM_EF_CAMERA_PARA2_LID                   = NVRAM_LID_GRP_CAMERA(5),
    NVRAM_EF_CAMERA_DEFECT1_LID                 = NVRAM_LID_GRP_CAMERA(6),
    NVRAM_EF_CAMERA_DEFECT2_LID                 = NVRAM_LID_GRP_CAMERA(7),
    NVRAM_EF_CAMERA_SHADING1_LID                = NVRAM_LID_GRP_CAMERA(8),
    NVRAM_EF_CAMERA_SHADING2_LID                = NVRAM_LID_GRP_CAMERA(9),
    NVRAM_EF_CAMERA_PCA_LID                     = NVRAM_LID_GRP_CAMERA(10),
    NVRAM_EF_CAMERA_PCA2_LID                    = NVRAM_LID_GRP_CAMERA(11),
    NVRAM_EF_CAMERA_PARA1_MAIN_LID              = NVRAM_LID_GRP_CAMERA(12),
    NVRAM_EF_CAMERA_PARA2_MAIN_LID              = NVRAM_LID_GRP_CAMERA(13),
    NVRAM_EF_CAMERA_DEFECT1_MAIN_LID            = NVRAM_LID_GRP_CAMERA(14),
    NVRAM_EF_CAMERA_DEFECT2_MAIN_LID            = NVRAM_LID_GRP_CAMERA(15),
    NVRAM_EF_CAMERA_SHADING1_MAIN_LID           = NVRAM_LID_GRP_CAMERA(16),
    NVRAM_EF_CAMERA_SHADING2_MAIN_LID           = NVRAM_LID_GRP_CAMERA(17),
    NVRAM_EF_CAMERA_PCA_MAIN_LID                = NVRAM_LID_GRP_CAMERA(18),
    NVRAM_EF_CAMERA_PCA2_MAIN_LID               = NVRAM_LID_GRP_CAMERA(19),
    NVRAM_EF_CAMERA_PARA1_SUB_LID               = NVRAM_LID_GRP_CAMERA(20),
    NVRAM_EF_CAMERA_PARA2_SUB_LID               = NVRAM_LID_GRP_CAMERA(21),
    NVRAM_EF_CAMERA_DEFECT1_SUB_LID             = NVRAM_LID_GRP_CAMERA(22),
    NVRAM_EF_CAMERA_DEFECT2_SUB_LID             = NVRAM_LID_GRP_CAMERA(23),
    NVRAM_EF_CAMERA_SHADING1_SUB_LID            = NVRAM_LID_GRP_CAMERA(24),
    NVRAM_EF_CAMERA_SHADING2_SUB_LID            = NVRAM_LID_GRP_CAMERA(25),
    NVRAM_EF_CAMERA_PCA_SUB_LID                 = NVRAM_LID_GRP_CAMERA(26),
    NVRAM_EF_CAMERA_PARA1_MAIN_BAK1_LID         = NVRAM_LID_GRP_CAMERA(27),
    NVRAM_EF_CAMERA_PARA2_MAIN_BAK1_LID         = NVRAM_LID_GRP_CAMERA(28),
    NVRAM_EF_CAMERA_DEFECT1_MAIN_BAK1_LID       = NVRAM_LID_GRP_CAMERA(29),
    NVRAM_EF_CAMERA_DEFECT2_MAIN_BAK1_LID       = NVRAM_LID_GRP_CAMERA(30),
    NVRAM_EF_CAMERA_SHADING1_MAIN_BAK1_LID      = NVRAM_LID_GRP_CAMERA(31),
    NVRAM_EF_CAMERA_SHADING2_MAIN_BAK1_LID      = NVRAM_LID_GRP_CAMERA(32),
    NVRAM_EF_CAMERA_PCA_MAIN_BAK1_LID           = NVRAM_LID_GRP_CAMERA(33),
    NVRAM_EF_CAMERA_PCA2_MAIN_BAK1_LID          = NVRAM_LID_GRP_CAMERA(34),
    NVRAM_EF_CAMERA_PARA1_SUB_BAK1_LID          = NVRAM_LID_GRP_CAMERA(35),
    NVRAM_EF_CAMERA_PARA2_SUB_BAK1_LID          = NVRAM_LID_GRP_CAMERA(36),
    NVRAM_EF_CAMERA_DEFECT1_SUB_BAK1_LID        = NVRAM_LID_GRP_CAMERA(37),
    NVRAM_EF_CAMERA_DEFECT2_SUB_BAK1_LID        = NVRAM_LID_GRP_CAMERA(38),
    NVRAM_EF_CAMERA_SHADING1_SUB_BAK1_LID       = NVRAM_LID_GRP_CAMERA(39),
    NVRAM_EF_CAMERA_SHADING2_SUB_BAK1_LID       = NVRAM_LID_GRP_CAMERA(40),
    NVRAM_EF_CAMERA_PCA_SUB_BAK1_LID            = NVRAM_LID_GRP_CAMERA(41),
    NVRAM_EF_CAMERA_MAIN_SENSOR_ID_LID          = NVRAM_LID_GRP_CAMERA(42),
    NVRAM_EF_CAMERA_SUB_SENSOR_ID_LID           = NVRAM_LID_GRP_CAMERA(43),
    NVRAM_EF_CAMERA_PARA_MAIN_LID               = NVRAM_LID_GRP_CAMERA(44),
    NVRAM_EF_CAMERA_PARA_MAIN_BAK1_LID          = NVRAM_LID_GRP_CAMERA(45),
    NVRAM_EF_CAMERA_PARA_SUB_LID                = NVRAM_LID_GRP_CAMERA(46),
    NVRAM_EF_CAMERA_PARA_SUB_BAK1_LID           = NVRAM_LID_GRP_CAMERA(47),
        
/*
 *  Last LID of Camera Group
 */
    NVRAM_EF_CAMERA_LAST_LID            = NVRAM_LID_GRP_CAMERA(255)
}nvram_lid_camera_enum;


/*
 *   Verno
 */
#define NVRAM_EF_CAMERA_PARA_LID_VERNO                  "006"
#define NVRAM_EF_CAMERA_GAMMA_LID_VERNO                 "000"
#define NVRAM_EF_CAMERA_DEFECT_LID_VERNO                "000"
#define NVRAM_EF_CAMERA_LENS_LID_VERNO                  "000"

#define NVRAM_EF_CAMERA_PARA1_LID_VERNO                 "001"
#define NVRAM_EF_CAMERA_PARA2_LID_VERNO                 "000"
#define NVRAM_EF_CAMERA_DEFECT1_LID_VERNO               "000"
#define NVRAM_EF_CAMERA_DEFECT2_LID_VERNO               "000"
#define NVRAM_EF_CAMERA_SHADING1_LID_VERNO              "000"
#define NVRAM_EF_CAMERA_SHADING2_LID_VERNO              "000"

#define NVRAM_EF_CAMERA_PARA1_MAIN_LID_VERNO            "000"
#define NVRAM_EF_CAMERA_PARA2_MAIN_LID_VERNO            "000"
#define NVRAM_EF_CAMERA_DEFECT1_MAIN_LID_VERNO          "000"
#define NVRAM_EF_CAMERA_DEFECT2_MAIN_LID_VERNO          "000"
#define NVRAM_EF_CAMERA_SHADING1_MAIN_LID_VERNO         "000"
#define NVRAM_EF_CAMERA_SHADING2_MAIN_LID_VERNO         "000"
#define NVRAM_EF_CAMERA_PARA1_SUB_LID_VERNO             "000"
#define NVRAM_EF_CAMERA_PARA2_SUB_LID_VERNO             "000"
#define NVRAM_EF_CAMERA_DEFECT1_SUB_LID_VERNO           "000"
#define NVRAM_EF_CAMERA_DEFECT2_SUB_LID_VERNO           "000"
#define NVRAM_EF_CAMERA_SHADING1_SUB_LID_VERNO          "000"
#define NVRAM_EF_CAMERA_SHADING2_SUB_LID_VERNO          "000"
#define NVRAM_EF_CAMERA_PARA1_MAIN_BAK1_LID_VERNO       "000"
#define NVRAM_EF_CAMERA_PARA2_MAIN_BAK1_LID_VERNO       "000"
#define NVRAM_EF_CAMERA_DEFECT1_MAIN_BAK1_LID_VERNO     "000"
#define NVRAM_EF_CAMERA_DEFECT2_MAIN_BAK1_LID_VERNO     "000"
#define NVRAM_EF_CAMERA_SHADING1_MAIN_BAK1_LID_VERNO    "000"
#define NVRAM_EF_CAMERA_SHADING2_MAIN_BAK1_LID_VERNO    "000"
#define NVRAM_EF_CAMERA_PARA1_SUB_BAK1_LID_VERNO        "000"
#define NVRAM_EF_CAMERA_PARA2_SUB_BAK1_LID_VERNO        "000"
#define NVRAM_EF_CAMERA_DEFECT1_SUB_BAK1_LID_VERNO      "000"
#define NVRAM_EF_CAMERA_DEFECT2_SUB_BAK1_LID_VERNO      "000"
#define NVRAM_EF_CAMERA_SHADING1_SUB_BAK1_LID_VERNO     "000"
#define NVRAM_EF_CAMERA_SHADING2_SUB_BAK1_LID_VERNO     "000"
#define NVRAM_EF_CAMERA_PARA_MAIN_LID_VERNO             "001"
#define NVRAM_EF_CAMERA_PARA_MAIN_BAK1_LID_VERNO        "001"
#define NVRAM_EF_CAMERA_PARA_SUB_LID_VERNO             "001"
#define NVRAM_EF_CAMERA_PARA_SUB_BAK1_LID_VERNO        "001"

#define NVRAM_EF_CAMERA_PCA_LID_VERNO              "000"
#define NVRAM_EF_CAMERA_PCA_MAIN_LID_VERNO         "000"
#define NVRAM_EF_CAMERA_PCA_SUB_LID_VERNO          "000"
#define NVRAM_EF_CAMERA_PCA_MAIN_BAK1_LID_VERNO    "000"
#define NVRAM_EF_CAMERA_PCA_SUB_BAK1_LID_VERNO     "000"

#if defined (__AUTO_SCENE_DETECT_SUPPORT__)
#define NVRAM_EF_CAMERA_PCA2_LID_VERNO              "000"
#define NVRAM_EF_CAMERA_PCA2_MAIN_LID_VERNO         "000"
#define NVRAM_EF_CAMERA_PCA2_MAIN_BAK1_LID_VERNO    "000"
#endif

#define NVRAM_EF_CAMERA_MAIN_SENSOR_ID_LID_VERNO        "000"
#define NVRAM_EF_CAMERA_SUB_SENSOR_ID_LID_VERNO         "000"



/*
 * Record Size/Total Records
 */
#if defined(ISP_SUPPORT) && (!defined(DRV_ISP_6238_SERIES)) && (!(defined(DUAL_CAMERA_SUPPORT)||defined(BACKUP_SENSOR_SUPPORT)))/* !(defined(DUAL_CAMERA_SUPPORT) || defined(BACKUP_SENSOR_SUPPORT))) */
#define NVRAM_EF_CAMERA_PARA_SIZE      sizeof(nvram_camera_para_struct)
#define NVRAM_EF_CAMERA_PARA_TOTAL     1
#endif

#if defined(ISP_SUPPORT) && (defined(DRV_ISP_6235_SERIES) ||defined(DRV_ISP_6276_SERIES))
#if(defined(DUAL_CAMERA_SUPPORT) || defined(BACKUP_SENSOR_SUPPORT))
#define NVRAM_EF_CAMERA_PARA_MAIN_SIZE          sizeof(nvram_camera_para_struct)
#define NVRAM_EF_CAMERA_PARA_MAIN_TOTAL         1
#if (defined(CMOS_SENSOR_SUB)) /*keep this sequence*/
#define NVRAM_EF_CAMERA_PARA_SUB_SIZE          sizeof(nvram_camera_para_struct)
#define NVRAM_EF_CAMERA_PARA_SUB_TOTAL         1
#endif
#if (defined(CMOS_SENSOR_BAK1)) /*keep this sequence*/
#define NVRAM_EF_CAMERA_PARA_MAIN_BAK1_SIZE     sizeof(nvram_camera_para_struct)
#define NVRAM_EF_CAMERA_PARA_MAIN_BAK1_TOTAL    1
#endif
#if (defined(CMOS_SENSOR_SUB_BAK1)) /*keep this sequence*/
#define NVRAM_EF_CAMERA_PARA_SUB_BAK1_SIZE         sizeof(nvram_camera_para_struct)
#define NVRAM_EF_CAMERA_PARA_SUB_BAK1_TOTAL        1
#endif

#endif

#endif /* defined(ISP_SUPPORT) && defined(DRV_ISP_6235_SERIES) && defined(BACKUP_SENSOR_SUPPORT) */

#if defined(ISP_SUPPORT) && (defined(DRV_ISP_6227_SERIES) || defined(DRV_ISP_6229_SERIES))
#define NVRAM_EF_CAMERA_GAMMA_SIZE     sizeof(nvram_camera_gamma_struct)
#define NVRAM_EF_CAMERA_GAMMA_TOTAL    1
#endif /* defined(ISP_SUPPORT) && (defined(DRV_ISP_6227_SERIES) || defined(DRV_ISP_6229_SERIES)) */ 
#if defined(ISP_SUPPORT) && (defined(DRV_ISP_6227_SERIES) || defined(DRV_ISP_6229_SERIES) || defined(DRV_ISP_6228_SERIES))
#define NVRAM_EF_CAMERA_DEFECT_SIZE   sizeof(nvram_camera_defect_struct)
#define NVRAM_EF_CAMERA_DEFECT_TOTAL   1
#endif /* defined(ISP_SUPPORT) && (defined(DRV_ISP_6227_SERIES) || defined(DRV_ISP_6229_SERIES) || defined(DRV_ISP_6228_SERIES)) */ 
#if defined(ISP_SUPPORT) && (defined(DRV_ISP_6227_SERIES) || defined(DRV_ISP_6229_SERIES) || defined(DRV_ISP_6228_SERIES))
#define NVRAM_EF_CAMERA_LENS_SIZE     sizeof(nvram_camera_lens_struct)
#define NVRAM_EF_CAMERA_LENS_TOTAL     1
#endif /* defined(ISP_SUPPORT) && (defined(DRV_ISP_6227_SERIES) || defined(DRV_ISP_6229_SERIES) || defined(DRV_ISP_6228_SERIES)) */ 

/* 6276 camera */
//deleted

/* 6238 camera */
#if (defined(ISP_SUPPORT) && defined(DRV_ISP_6238_SERIES))
#if(!(defined(DUAL_CAMERA_SUPPORT) || defined(BACKUP_SENSOR_SUPPORT)))
#define NVRAM_EF_CAMERA_PARA1_SIZE      sizeof(nvram_camera_para_struct)
#define NVRAM_EF_CAMERA_PARA1_TOTAL     1
#define NVRAM_EF_CAMERA_PARA2_SIZE      sizeof(nvram_camera_3a_struct)
#define NVRAM_EF_CAMERA_PARA2_TOTAL     1
#define NVRAM_EF_CAMERA_DEFECT1_SIZE      sizeof(nvram_camera_defect1_struct)
#define NVRAM_EF_CAMERA_DEFECT1_TOTAL     1
#define NVRAM_EF_CAMERA_DEFECT2_SIZE      sizeof(nvram_camera_defect2_struct)
#define NVRAM_EF_CAMERA_DEFECT2_TOTAL     1
#define NVRAM_EF_CAMERA_SHADING1_SIZE      sizeof(nvram_camera_shading1_struct)
#define NVRAM_EF_CAMERA_SHADING1_TOTAL     1
#define NVRAM_EF_CAMERA_SHADING2_SIZE      sizeof(nvram_camera_shading2_struct)
#define NVRAM_EF_CAMERA_SHADING2_TOTAL     1
#if defined(DRV_ISP_PCA_SUPPORT)
#define NVRAM_EF_CAMERA_PCA_SIZE      sizeof(nvram_camera_pca_struct)
#define NVRAM_EF_CAMERA_PCA_TOTAL     1
#if defined (__AUTO_SCENE_DETECT_SUPPORT__)      
#define NVRAM_EF_CAMERA_PCA2_SIZE      sizeof(nvram_camera_pca_struct)
#define NVRAM_EF_CAMERA_PCA2_TOTAL     1
#endif
#endif
#else
#define NVRAM_EF_CAMERA_PARA1_MAIN_SIZE         sizeof(nvram_camera_para_struct)
#define NVRAM_EF_CAMERA_PARA1_MAIN_TOTAL        1
#define NVRAM_EF_CAMERA_PARA2_MAIN_SIZE         sizeof(nvram_camera_3a_struct)
#define NVRAM_EF_CAMERA_PARA2_MAIN_TOTAL        1
#define NVRAM_EF_CAMERA_DEFECT1_MAIN_SIZE       sizeof(nvram_camera_defect1_struct)
#define NVRAM_EF_CAMERA_DEFECT1_MAIN_TOTAL      1
#define NVRAM_EF_CAMERA_DEFECT2_MAIN_SIZE       sizeof(nvram_camera_defect2_struct)
#define NVRAM_EF_CAMERA_DEFECT2_MAIN_TOTAL      1
#define NVRAM_EF_CAMERA_SHADING1_MAIN_SIZE      sizeof(nvram_camera_shading1_struct)
#define NVRAM_EF_CAMERA_SHADING1_MAIN_TOTAL     1
#define NVRAM_EF_CAMERA_SHADING2_MAIN_SIZE      sizeof(nvram_camera_shading2_struct)
#define NVRAM_EF_CAMERA_SHADING2_MAIN_TOTAL     1
#if defined(DRV_ISP_PCA_SUPPORT)
#define NVRAM_EF_CAMERA_PCA_MAIN_SIZE      sizeof(nvram_camera_pca_struct)
#define NVRAM_EF_CAMERA_PCA_MAIN_TOTAL     1
#if defined (__AUTO_SCENE_DETECT_SUPPORT__)      
#define NVRAM_EF_CAMERA_PCA2_MAIN_SIZE      sizeof(nvram_camera_pca_struct)
#define NVRAM_EF_CAMERA_PCA2_MAIN_TOTAL     1
#endif
#endif

#if (defined(CMOS_SENSOR_SUB)) /*keep this sequence*/
#define NVRAM_EF_CAMERA_PARA1_SUB_SIZE          sizeof(nvram_camera_para_struct)
#define NVRAM_EF_CAMERA_PARA1_SUB_TOTAL         1
#define NVRAM_EF_CAMERA_PARA2_SUB_SIZE          sizeof(nvram_camera_3a_struct)
#define NVRAM_EF_CAMERA_PARA2_SUB_TOTAL         1
#define NVRAM_EF_CAMERA_DEFECT1_SUB_SIZE        sizeof(nvram_camera_defect1_struct)
#define NVRAM_EF_CAMERA_DEFECT1_SUB_TOTAL       1
#define NVRAM_EF_CAMERA_DEFECT2_SUB_SIZE        sizeof(nvram_camera_defect2_struct)
#define NVRAM_EF_CAMERA_DEFECT2_SUB_TOTAL       1
#define NVRAM_EF_CAMERA_SHADING1_SUB_SIZE       sizeof(nvram_camera_shading1_struct)
#define NVRAM_EF_CAMERA_SHADING1_SUB_TOTAL      1
#define NVRAM_EF_CAMERA_SHADING2_SUB_SIZE       sizeof(nvram_camera_shading2_struct)
#define NVRAM_EF_CAMERA_SHADING2_SUB_TOTAL      1
#if defined(DRV_ISP_PCA_SUPPORT)
#define NVRAM_EF_CAMERA_PCA_SUB_SIZE       sizeof(nvram_camera_pca_struct)
#define NVRAM_EF_CAMERA_PCA_SUB_TOTAL      1
#endif
#endif

#if (defined(CMOS_SENSOR_BAK1)) /*keep this sequence*/
#define NVRAM_EF_CAMERA_PARA1_MAIN_BAK1_SIZE        sizeof(nvram_camera_para_struct)
#define NVRAM_EF_CAMERA_PARA1_MAIN_BAK1_TOTAL       1
#define NVRAM_EF_CAMERA_PARA2_MAIN_BAK1_SIZE        sizeof(nvram_camera_3a_struct)
#define NVRAM_EF_CAMERA_PARA2_MAIN_BAK1_TOTAL       1
#define NVRAM_EF_CAMERA_DEFECT1_MAIN_BAK1_SIZE      sizeof(nvram_camera_defect1_struct)
#define NVRAM_EF_CAMERA_DEFECT1_MAIN_BAK1_TOTAL     1
#define NVRAM_EF_CAMERA_DEFECT2_MAIN_BAK1_SIZE      sizeof(nvram_camera_defect2_struct)
#define NVRAM_EF_CAMERA_DEFECT2_MAIN_BAK1_TOTAL     1
#define NVRAM_EF_CAMERA_SHADING1_MAIN_BAK1_SIZE     sizeof(nvram_camera_shading1_struct)
#define NVRAM_EF_CAMERA_SHADING1_MAIN_BAK1_TOTAL    1
#define NVRAM_EF_CAMERA_SHADING2_MAIN_BAK1_SIZE     sizeof(nvram_camera_shading2_struct)
#define NVRAM_EF_CAMERA_SHADING2_MAIN_BAK1_TOTAL    1
#if defined(DRV_ISP_PCA_SUPPORT)
#define NVRAM_EF_CAMERA_PCA_MAIN_BAK1_SIZE     sizeof(nvram_camera_pca_struct)
#define NVRAM_EF_CAMERA_PCA_MAIN_BAK1_TOTAL    1
#if defined (__AUTO_SCENE_DETECT_SUPPORT__)      
#define NVRAM_EF_CAMERA_PCA2_MAIN_BAK1_SIZE      sizeof(nvram_camera_pca_struct)
#define NVRAM_EF_CAMERA_PCA2_MAIN_BAK1_TOTAL     1
#endif
#endif
#endif

#if (defined(CMOS_SENSOR_SUB_BAK1)) /*keep this sequence*/
#define NVRAM_EF_CAMERA_PARA1_SUB_BAK1_SIZE         sizeof(nvram_camera_para_struct)
#define NVRAM_EF_CAMERA_PARA1_SUB_BAK1_TOTAL        1
#define NVRAM_EF_CAMERA_PARA2_SUB_BAK1_SIZE         sizeof(nvram_camera_3a_struct)
#define NVRAM_EF_CAMERA_PARA2_SUB_BAK1_TOTAL        1
#define NVRAM_EF_CAMERA_DEFECT1_SUB_BAK1_SIZE       sizeof(nvram_camera_defect1_struct)
#define NVRAM_EF_CAMERA_DEFECT1_SUB_BAK1_TOTAL      1
#define NVRAM_EF_CAMERA_DEFECT2_SUB_BAK1_SIZE       sizeof(nvram_camera_defect2_struct)
#define NVRAM_EF_CAMERA_DEFECT2_SUB_BAK1_TOTAL      1
#define NVRAM_EF_CAMERA_SHADING1_SUB_BAK1_SIZE      sizeof(nvram_camera_shading1_struct)
#define NVRAM_EF_CAMERA_SHADING1_SUB_BAK1_TOTAL     1
#define NVRAM_EF_CAMERA_SHADING2_SUB_BAK1_SIZE      sizeof(nvram_camera_shading2_struct)
#define NVRAM_EF_CAMERA_SHADING2_SUB_BAK1_TOTAL     1
#if defined(DRV_ISP_PCA_SUPPORT)
#define NVRAM_EF_CAMERA_PCA_SUB_BAK1_SIZE      sizeof(nvram_camera_pca_struct)
#define NVRAM_EF_CAMERA_PCA_SUB_BAK1_TOTAL     1
#endif
#endif
#endif /* !(defined(DUAL_CAMERA_SUPPORT) || defined(BACKUP_SENSOR_SUPPORT))) */
#endif /* defined(ISP_SUPPORT) && 6238 */ 

#define NVRAM_EF_CAMERA_MAIN_SENSOR_ID_SIZE     4
#define NVRAM_EF_CAMERA_MAIN_SENSOR_ID_TOTAL    1
#if defined(DUAL_CAMERA_SUPPORT)
#define NVRAM_EF_CAMERA_SUB_SENSOR_ID_SIZE      4
#define NVRAM_EF_CAMERA_SUB_SENSOR_ID_TOTAL     1
#endif 





#ifdef __cplusplus
}
#endif 

#endif /* __CAMERA_NVRAM_DEF_H__ */ 
