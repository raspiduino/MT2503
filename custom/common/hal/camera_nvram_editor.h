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
 * camera_nvram_editor.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __CAMERA_NVRAM_EDITOR_H__
#define __CAMERA_NVRAM_EDITOR_H__
#ifndef NVRAM_NOT_PRESENT

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
 
/*
 *   User Headers
 */
#include "camera_nvram_def.h"


/*
 *   Bit Level Description Language
 */
#ifdef GEN_FOR_PC
BEGIN_NVRAM_DATA

#if (defined(ISP_SUPPORT) && (!defined(DRV_ISP_6238_SERIES)) && (!(defined(DUAL_CAMERA_SUPPORT)||defined(BACKUP_SENSOR_SUPPORT))))
LID_BIT VER_LID(NVRAM_EF_CAMERA_PARA_LID)
     nvram_camera_para_struct *NVRAM_EF_CAMERA_PARA_TOTAL
     {
     #if (!((defined(DRV_ISP_6225_SERIES) || defined(DRV_ISP_6235_SERIES)||defined(DRV_ISP_6276_SERIES)) && defined(__CAMERA_NVRAM_REDUCTION__)))

         ISPCOMM:"ISP Comm Register"
         {
         };
       ISPCOMM.commReg: "ISP register"
         {
         };
         ISPTUNING:"ISP tuning para"
         {
         };
         MSHUTTER:"Mechanical shutter calibration"
         {
         };
         SENSOR:"SENSOR SETTING"
         {
         };
       SENSOR.reg:"Sensor register"
         {
         };
       SENSOR.cct:"cct"
         {
         };
#endif /* (!defined(DRV_ISP_6235_SERIES)) */

         };
#endif /* defined(ISP_SUPPORT) */
 
#if (defined(ISP_SUPPORT) && (!defined(DRV_ISP_6238_SERIES)) && (!(defined(DUAL_CAMERA_SUPPORT)||defined(BACKUP_SENSOR_SUPPORT))))
    LID_BIT VER_LID(NVRAM_EF_CAMERA_PARA_LID)
     nvram_camera_para_struct *NVRAM_EF_CAMERA_PARA_TOTAL
     {
     #if (!((defined(DRV_ISP_6225_SERIES) || defined(DRV_ISP_6235_SERIES)||defined(DRV_ISP_6276_SERIES)) && defined(__CAMERA_NVRAM_REDUCTION__)))

         ISPCOMM:"ISP Comm Register"
         {
         };
       ISPCOMM.commReg: "ISP register"
         {
         };
         ISPTUNING:"ISP tuning para"
         {
         };
         MSHUTTER:"Mechanical shutter calibration"
         {
         };
         SENSOR:"SENSOR SETTING"
         {
         };
       SENSOR.reg:"Sensor register"
         {
         };
       SENSOR.cct:"cct"
         {
         };
    #endif /* (!defined(DRV_ISP_6235_SERIES)) */

    };
#endif /* defined(ISP_SUPPORT) */


/* 6276 camera */
//deleted

/* 6238 camera */
#if (defined(ISP_SUPPORT) && defined(DRV_ISP_6238_SERIES))
    #if(!(defined(DUAL_CAMERA_SUPPORT) || defined(BACKUP_SENSOR_SUPPORT)))
        LID_BIT VER_LID(NVRAM_EF_CAMERA_PARA1_LID)
        nvram_camera_para_struct *NVRAM_EF_CAMERA_PARA1_TOTAL
        {
            ISPCOMM:"ISP Comm Register"
            {
            };
            ISPCOMM.commReg: "ISP register"
            {
            };
            ISPTUNING:"ISP tuning para"
            {
            };
            MSHUTTER:"Mechanical shutter calibration"
            {
            };
            SENSOR:"SENSOR SETTING"
            {
            };
            SENSOR.reg:"Sensor register"
            {
            };
            SENSOR.cct:"cct"
            {
            };
        };
        
        #if (defined(RAW_MAIN_CAMERA))
            LID_BIT VER_LID(NVRAM_EF_CAMERA_PARA2_LID)
            nvram_camera_3a_struct *NVRAM_EF_CAMERA_PARA2_TOTAL
            {
                AE:"AE para"
                {
                };
                AE.aeIsoPara: "Iso calibration data"
                {
                };
                AE.aeIsoPara.IsoGain: "Iso gain"
                {
                };
                AE.aeIsoPara.IsoValue: "Iso value"
                {
                };
                AE.aeMeteringComm: "metering"
                {
                };
                AE.aeMeteringComm.target_mean: "target mean"
                {
                };
                AE.aeMeteringComm.init_expo_idx: "init index"
                {
                };
                AE.aeMeteringComm.flare_fix_flag: "flare fix flage"
                {
                };
                AE.aeMeteringComm.flare_fix_offset: "flare fix offset"
                {
                };
                AE.aeMeteringComm.flare_search_dn_ratio: "flare auto search ratio by 1024 base"
                {
                };
                AE.aeMeteringComm.flare_min_offset: "flare auto min offset"
                {
                };
                AE.aeMeteringComm.preview_gamma_no: "preview gamma no"
                {
                };
                AE.aeMeteringComm.preview_flare_offset: "preview flare offset"
                {
                };
                AE.aeMeteringComm.indoor_outdoor_ev: "indoor & outdoor ev"
                {
                };
                AE.aeMeteringComm.indoor_min_gamma_mean: "indoor gamma mean"
                {
                };
                AE.aeMeteringComm.outdoor_max_gamma_mean: "outdoor gamma mean"
                {
                };
                AE.aeMeteringComm.sky_ev: "sky detetcion ev"
                {
                };
                AE.aeMeteringComm.sky_mean: "sky gamma mean"
                {
                };
                AE.aeMeteringComm.sky_max_window_mean: "sky detetcion window mean"
                {
                };
                AE.aeMeteringComm.min_under_expo_bin:"min under expo bin"
                {
                };
                AE.aeMeteringComm.lowlight_ev: "ev to limit max gamma"
                {
                };
                AE.aeMeteringComm.lowlight_min_target_mean: "linear mean to limit max gamma"
                {
                };
                AE.aeMeteringComm.non_over_exposure_stretch_enabled: "non-over expo stretch enable"
                {
                };
                AE.aeMeteringComm.full_dark_background_check_enabled: "full dark check enable"
                {
                };
                AE.aeMeteringComm.gamma_lut: "fast lut gamma table"
                {
                };
                AE.aeMeteringComm.grass_detect_enable: "grass_detect_enable"
                {
                };
                AE.ae_smooth: "AE smooth"
                {
                };
                AE.reserve_1: "reserve"
                {
                };
                AWB:"AWB para"
                {
                };
                AWB.AWB:"AWB para"
                {
                };
                AWB.CCM:"CCM para"
                {
                };
                AF:"AF para"
                {
                };
                AF.lens_calibration:"lens calibration"
                {
                };
                AF.table_info:"table info"
                {
                };
                AF.para_info:"para info"
                {
                };

            };
            
            LID_BIT VER_LID(NVRAM_EF_CAMERA_DEFECT1_LID)
            nvram_camera_defect1_struct *NVRAM_EF_CAMERA_DEFECT1_TOTAL
            {
                DEFECT1:"Defect table 1"
                {
                };
                DEFECT1.previewSize:"Preview defect table size"
                {
                };
                DEFECT1.captureSize:"Capture defect table size"
                {
                };
                DEFECT1.captureTable1:"Capture defect table 1"
                {
                };
            };
            
            LID_BIT VER_LID(NVRAM_EF_CAMERA_DEFECT2_LID)
            nvram_camera_defect2_struct *NVRAM_EF_CAMERA_DEFECT2_TOTAL
            {
                DEFECT2:"defect table 2"
                {
                };
                DEFECT2.previewTable:"Preview defect table"
                {
                };
                DEFECT2.captureTable2:"Capture defect table 2"
                {
                };
            };
            
            LID_BIT VER_LID(NVRAM_EF_CAMERA_SHADING1_LID)
            nvram_camera_shading1_struct *NVRAM_EF_CAMERA_SHADING1_TOTAL
            {
                SHADING1:"shading table 1"
                {
                };
                SHADING1.previewSize:"Preview shading table size"
                {
                };
                SHADING1.captureSize:"Capture shading table size"
                {
                };
                SHADING1.captureTable1:"Capture shading table 1"
                {
                };
            };
            
            LID_BIT VER_LID(NVRAM_EF_CAMERA_SHADING2_LID)
            nvram_camera_shading2_struct *NVRAM_EF_CAMERA_SHADING2_TOTAL
            {
                SHADING2:"shading table 2"
                {
                };
                SHADING2.previewTable:"Preview shading table"
                {
                };
                SHADING2.captureTable2:"Capture shading table 2"
                {
                };
            };

            #if defined(DRV_ISP_PCA_SUPPORT)
                LID_BIT VER_LID(NVRAM_EF_CAMERA_PCA_LID)
                nvram_camera_pca_struct *NVRAM_EF_CAMERA_PCA_TOTAL
                {
                    pcaCtrlReg:"PCA control register"
                    {
                    };
                    pcaGmcReg:"PCA GMC throttle control"
                    {
                    };
                    chroma_thres_lo:"Y threshold in ct low"
                    {
                    };
                    chroma_thres_md:"Y threshold in ct medium"
                    {
                    };
                    chroma_thres_hi:"Y threshold in ct high"
                    {
                    };
                    PCA_LUT_LO:"PCA low CT table"
                    {
                    };
                    PCA_LUT_LO.Hue_shift:"Hue shift"
                    {
                    };
                    PCA_LUT_LO.Sat_gain:"Saturation gain"
                    {
                    };
                    PCA_LUT_LO.Y_gain:"Y gain"
                    {
                    };
                    PCA_LUT_MD:"PCA medium CT table"
                    {
                    };
                    PCA_LUT_MD.Hue_shift:"Hue shift"
                    {
                    };
                    PCA_LUT_MD.Sat_gain:"Saturation gain"
                    {
                    };
                    PCA_LUT_MD.Y_gain:"Y gain"
                    {
                    };
                    PCA_LUT_HI:"PCA high CT table"
                    {
                    };
                    PCA_LUT_HI.Hue_shift:"Hue shift"
                    {
                    };
                    PCA_LUT_HI.Sat_gain:"Saturation gain"
                    {
                    };
                    PCA_LUT_HI.Y_gain:"Y gain"
                    {
                    };
                };
                #if defined (__AUTO_SCENE_DETECT_SUPPORT__)
                LID_BIT VER_LID(NVRAM_EF_CAMERA_PCA2_LID)
                nvram_camera_pca_struct *NVRAM_EF_CAMERA_PCA2_TOTAL
                {
                    pcaCtrlReg:"PCA2 control register"
                    {
                    };
                    pcaGmcReg:"PCA2 GMC throttle control"
                    {
                    };
                    chroma_thres_lo:"Y threshold in ct low"
                    {
                    };
                    chroma_thres_md:"Y threshold in ct medium"
                    {
                    };
                    chroma_thres_hi:"Y threshold in ct high"
                    {
                    };
                    PCA_LUT_LO:"PCA2 low CT table"
                    {
                    };
                    PCA_LUT_LO.Hue_shift:"Hue shift"
                    {
                    };
                    PCA_LUT_LO.Sat_gain:"Saturation gain"
                    {
                    };
                    PCA_LUT_LO.Y_gain:"Y gain"
                    {
                    };
                    PCA_LUT_MD:"PCA2 medium CT table"
                    {
                    };
                    PCA_LUT_MD.Hue_shift:"Hue shift"
                    {
                    };
                    PCA_LUT_MD.Sat_gain:"Saturation gain"
                    {
                    };
                    PCA_LUT_MD.Y_gain:"Y gain"
                    {
                    };
                    PCA_LUT_HI:"PCA2 high CT table"
                    {
                    };
                    PCA_LUT_HI.Hue_shift:"Hue shift"
                    {
                    };
                    PCA_LUT_HI.Sat_gain:"Saturation gain"
                    {
                    };
                    PCA_LUT_HI.Y_gain:"Y gain"
                    {
                    };
                };
                #endif			
            #endif
        #endif
    
    #else /* defined(ISP_SUPPORT) & 6238 */

        LID_BIT VER_LID(NVRAM_EF_CAMERA_PARA1_MAIN_LID)
        nvram_camera_para_struct *NVRAM_EF_CAMERA_PARA1_MAIN_TOTAL
        {
            ISPCOMM:"ISP Comm Register"
            {
            };
            ISPCOMM.commReg: "ISP register"
            {
            };
            ISPTUNING:"ISP tuning para"
            {
            };
            MSHUTTER:"Mechanical shutter calibration"
            {
            };
            SENSOR:"SENSOR SETTING"
            {
            };
            SENSOR.reg:"Sensor register"
            {
            };
            SENSOR.cct:"cct"
            {
            };
        };
        
        #if (defined(RAW_MAIN_CAMERA))
            LID_BIT VER_LID(NVRAM_EF_CAMERA_PARA2_MAIN_LID)
            nvram_camera_3a_struct *NVRAM_EF_CAMERA_PARA2_MAIN_TOTAL
            {
                AE:"AE para"
                {
                };
                AE.aeIsoPara: "Iso calibration data"
                {
                };
                AE.aeIsoPara.IsoGain: "Iso gain"
                {
                };
                AE.aeIsoPara.IsoValue: "Iso value"
                {
                };
                AE.aeMeteringComm: "metering"
                {
                };
                AE.aeMeteringComm.target_mean: "target mean"
                {
                };
                AE.aeMeteringComm.init_expo_idx: "init index"
                {
                };
                AE.aeMeteringComm.flare_fix_flag: "flare fix flage"
                {
                };
                AE.aeMeteringComm.flare_fix_offset: "flare fix offset"
                {
                };
                AE.aeMeteringComm.flare_search_dn_ratio: "flare auto search ratio by 1024 base"
                {
                };
                AE.aeMeteringComm.flare_min_offset: "flare auto min offset"
                {
                };
                AE.aeMeteringComm.preview_gamma_no: "preview gamma no"
                {
                };
                AE.aeMeteringComm.preview_flare_offset: "preview flare offset"
                {
                };
                AE.aeMeteringComm.indoor_outdoor_ev: "indoor & outdoor ev"
                {
                };
                AE.aeMeteringComm.indoor_min_gamma_mean: "indoor gamma mean"
                {
                };
                AE.aeMeteringComm.outdoor_max_gamma_mean: "outdoor gamma mean"
                {
                };
                AE.aeMeteringComm.sky_ev: "sky detetcion ev"
                {
                };
                AE.aeMeteringComm.sky_mean: "sky gamma mean"
                {
                };
                AE.aeMeteringComm.sky_max_window_mean: "sky detetcion window mean"
                {
                };
                AE.aeMeteringComm.min_under_expo_bin:"min under expo bin"
                {
                };
                AE.aeMeteringComm.lowlight_ev: "ev to limit max gamma"
                {
                };
                AE.aeMeteringComm.lowlight_min_target_mean: "linear mean to limit max gamma"
                {
                };
                AE.aeMeteringComm.non_over_exposure_stretch_enabled: "non-over expo stretch enable"
                {
                };
                AE.aeMeteringComm.full_dark_background_check_enabled: "full dark check enable"
                {
                };
                AE.aeMeteringComm.gamma_lut: "fast lut gamma table"
                {
                };
                AE.aeMeteringComm.grass_detect_enable: "grass_detect_enable"
                {
                };
                AE.ae_smooth: "AE smooth"
                {
                };
                AE.reserve_1: "reserve"
                {
                };
                AWB:"AWB para"
                {
                };
                AWB.AWB:"AWB para"
                {
                };
                AWB.CCM:"CCM para"
                {
                };
                AF:"AF para"
                {
                };
                AF.lens_calibration:"lens calibration"
                {
                };
                AF.table_info:"table info"
                {
                };
                AF.para_info:"para info"
                {
                };
            };
            
            LID_BIT VER_LID(NVRAM_EF_CAMERA_DEFECT1_MAIN_LID)
            nvram_camera_defect1_struct *NVRAM_EF_CAMERA_DEFECT1_MAIN_TOTAL
            {
                DEFECT1:"Defect table 1"
                {
                };
                DEFECT1.previewSize:"Preview defect table size"
                {
                };
                DEFECT1.captureSize:"Capture defect table size"
                {
                };
                DEFECT1.captureTable1:"Capture defect table 1"
                {
                };
            };
            
            LID_BIT VER_LID(NVRAM_EF_CAMERA_DEFECT2_MAIN_LID)
            nvram_camera_defect2_struct *NVRAM_EF_CAMERA_DEFECT2_MAIN_TOTAL
            {
                DEFECT2:"defect table 2"
                {
                };
                DEFECT2.previewTable:"Preview defect table"
                {
                };
                DEFECT2.captureTable2:"Capture defect table 2"
                {
                };
            };
            
            LID_BIT VER_LID(NVRAM_EF_CAMERA_SHADING1_MAIN_LID)
            nvram_camera_shading1_struct *NVRAM_EF_CAMERA_SHADING1_MAIN_TOTAL
            {
                SHADING1:"shading table 1"
                {
                };
                SHADING1.previewSize:"Preview shading table size"
                {
                };
                SHADING1.captureSize:"Capture shading table size"
                {
                };
                SHADING1.captureTable1:"Capture shading table 1"
                {
                };
            };
        
            LID_BIT VER_LID(NVRAM_EF_CAMERA_SHADING2_MAIN_LID)
            nvram_camera_shading2_struct *NVRAM_EF_CAMERA_SHADING2_MAIN_TOTAL
            {
                SHADING2:"shading table 2"
                {
                };
                SHADING2.previewTable:"Preview shading table"
                {
                };
                SHADING2.captureTable2:"Capture shading table 2"
                {
                };
            };

            #if defined(DRV_ISP_PCA_SUPPORT)
                LID_BIT VER_LID(NVRAM_EF_CAMERA_PCA_MAIN_LID)
                nvram_camera_pca_struct *NVRAM_EF_CAMERA_PCA_MAIN_TOTAL
                {
                    pcaCtrlReg:"PCA control register"
                    {
                    };
                    pcaGmcReg:"PCA GMC throttle control"
                    {
                    };
                    chroma_thres_lo:"Y threshold in ct low"
                    {
                    };
                    chroma_thres_md:"Y threshold in ct medium"
                    {
                    };
                    chroma_thres_hi:"Y threshold in ct high"
                    {
                    };
                    PCA_LUT_LO:"PCA low CT table"
                    {
                    };
                    PCA_LUT_LO.Hue_shift:"Hue shift"
                    {
                    };
                    PCA_LUT_LO.Sat_gain:"Saturation gain"
                    {
                    };
                    PCA_LUT_LO.Y_gain:"Y gain"
                    {
                    };
                    PCA_LUT_MD:"PCA medium CT table"
                    {
                    };
                    PCA_LUT_MD.Hue_shift:"Hue shift"
                    {
                    };
                    PCA_LUT_MD.Sat_gain:"Saturation gain"
                    {
                    };
                    PCA_LUT_MD.Y_gain:"Y gain"
                    {
                    };
                    PCA_LUT_HI:"PCA high CT table"
                    {
                    };
                    PCA_LUT_HI.Hue_shift:"Hue shift"
                    {
                    };
                    PCA_LUT_HI.Sat_gain:"Saturation gain"
                    {
                    };
                    PCA_LUT_HI.Y_gain:"Y gain"
                    {
                    };
                };

                #if defined (__AUTO_SCENE_DETECT_SUPPORT__)
                LID_BIT VER_LID(NVRAM_EF_CAMERA_PCA2_MAIN_LID)
                nvram_camera_pca_struct *NVRAM_EF_CAMERA_PCA2_MAIN_TOTAL
                {
                    pcaCtrlReg:"PCA2 control register"
                    {
                    };
                    pcaGmcReg:"PCA2 GMC throttle control"
                    {
                    };
                    chroma_thres_lo:"Y threshold in ct low"
                    {
                    };
                    chroma_thres_md:"Y threshold in ct medium"
                    {
                    };
                    chroma_thres_hi:"Y threshold in ct high"
                    {
                    };
                    PCA_LUT_LO:"PCA2 low CT table"
                    {
                    };
                    PCA_LUT_LO.Hue_shift:"Hue shift"
                    {
                    };
                    PCA_LUT_LO.Sat_gain:"Saturation gain"
                    {
                    };
                    PCA_LUT_LO.Y_gain:"Y gain"
                    {
                    };
                    PCA_LUT_MD:"PCA2 medium CT table"
                    {
                    };
                    PCA_LUT_MD.Hue_shift:"Hue shift"
                    {
                    };
                    PCA_LUT_MD.Sat_gain:"Saturation gain"
                    {
                    };
                    PCA_LUT_MD.Y_gain:"Y gain"
                    {
                    };
                    PCA_LUT_HI:"PCA2 high CT table"
                    {
                    };
                    PCA_LUT_HI.Hue_shift:"Hue shift"
                    {
                    };
                    PCA_LUT_HI.Sat_gain:"Saturation gain"
                    {
                    };
                    PCA_LUT_HI.Y_gain:"Y gain"
                    {
                    };
                };
                #endif			
            #endif
        #endif
        
        #if (defined(CMOS_SENSOR_SUB)) /*keep this sequence*/
            LID_BIT VER_LID(NVRAM_EF_CAMERA_PARA1_SUB_LID)
            nvram_camera_para_struct *NVRAM_EF_CAMERA_PARA1_SUB_TOTAL
            {
                ISPCOMM:"ISP Comm Register"
                {
                };
                ISPCOMM.commReg: "ISP register"
                {
                };
                ISPTUNING:"ISP tuning para"
                {
                };
                MSHUTTER:"Mechanical shutter calibration"
                {
                };
                SENSOR:"SENSOR SETTING"
                {
                };
                SENSOR.reg:"Sensor register"
                {
                };
                SENSOR.cct:"cct"
                {
                };
            };

            #if (defined(RAW_MAIN_CAMERA))
                LID_BIT VER_LID(NVRAM_EF_CAMERA_PARA2_SUB_LID)
                nvram_camera_3a_struct *NVRAM_EF_CAMERA_PARA2_SUB_TOTAL
                {
                    AE:"AE para"
                    {
                    };
                    AE.aeIsoPara: "Iso calibration data"
                    {
                    };
                    AE.aeIsoPara.IsoGain: "Iso gain"
                    {
                    };
                    AE.aeIsoPara.IsoValue: "Iso value"
                    {
                    };
                    AE.aeMeteringComm: "metering"
                    {
                    };
                    AE.aeMeteringComm.target_mean: "target mean"
                    {
                    };
                    AE.aeMeteringComm.init_expo_idx: "init index"
                    {
                    };
                    AE.aeMeteringComm.flare_fix_flag: "flare fix flage"
                    {
                    };
                    AE.aeMeteringComm.flare_fix_offset: "flare fix offset"
                    {
                    };
                    AE.aeMeteringComm.flare_search_dn_ratio: "flare auto search ratio by 1024 base"
                    {
                    };
                    AE.aeMeteringComm.flare_min_offset: "flare auto min offset"
                    {
                    };
                    AE.aeMeteringComm.preview_gamma_no: "preview gamma no"
                    {
                    };
                    AE.aeMeteringComm.preview_flare_offset: "preview flare offset"
                    {
                    };
                    AE.aeMeteringComm.indoor_outdoor_ev: "indoor & outdoor ev"
                    {
                    };
                    AE.aeMeteringComm.indoor_min_gamma_mean: "indoor gamma mean"
                    {
                    };
                    AE.aeMeteringComm.outdoor_max_gamma_mean: "outdoor gamma mean"
                    {
                    };
                    AE.aeMeteringComm.sky_ev: "sky detetcion ev"
                    {
                    };
                    AE.aeMeteringComm.sky_mean: "sky gamma mean"
                    {
                    };
                    AE.aeMeteringComm.sky_max_window_mean: "sky detetcion window mean"
                    {
                    };
                    AE.aeMeteringComm.min_under_expo_bin:"min under expo bin"
                    {
                    };
                    AE.aeMeteringComm.lowlight_ev: "ev to limit max gamma"
                    {
                    };
                    AE.aeMeteringComm.lowlight_min_target_mean: "linear mean to limit max gamma"
                    {
                    };
                    AE.aeMeteringComm.non_over_exposure_stretch_enabled: "non-over expo stretch enable"
                    {
                    };
                    AE.aeMeteringComm.full_dark_background_check_enabled: "full dark check enable"
                    {
                    };
                    AE.aeMeteringComm.gamma_lut: "fast lut gamma table"
                    {
                    };
                    AE.aeMeteringComm.grass_detect_enable: "grass_detect_enable"
                    {
                    };
                    AE.ae_smooth: "AE smooth"
                    {
                    };
                    AE.reserve_1: "reserve"
                    {
                    };
                    AWB:"AWB para"
                    {
                    };
                    AWB.AWB:"AWB para"
                    {
                    };
                    AWB.CCM:"CCM para"
                    {
                    };
                    AF:"AF para"
                    {
                    };
                    AF.lens_calibration:"lens calibration"
                    {
                    };
                    AF.table_info:"table info"
                    {
                    };
                    AF.para_info:"para info"
                    {
                    };

                };
                
                LID_BIT VER_LID(NVRAM_EF_CAMERA_DEFECT1_SUB_LID)
                nvram_camera_defect1_struct *NVRAM_EF_CAMERA_DEFECT1_SUB_TOTAL
                {
                    DEFECT1:"Defect table 1"
                    {
                    };
                    DEFECT1.previewSize:"Preview defect table size"
                    {
                    };
                    DEFECT1.captureSize:"Capture defect table size"
                    {
                    };
                    DEFECT1.captureTable1:"Capture defect table 1"
                    {
                    };
                };
            
                LID_BIT VER_LID(NVRAM_EF_CAMERA_DEFECT2_SUB_LID)
                nvram_camera_defect2_struct *NVRAM_EF_CAMERA_DEFECT2_SUB_TOTAL
                {
                    DEFECT2:"defect table 2"
                    {
                    };
                    DEFECT2.previewTable:"Preview defect table"
                    {
                    };
                    DEFECT2.captureTable2:"Capture defect table 2"
                    {
                    };
                };
                
                LID_BIT VER_LID(NVRAM_EF_CAMERA_SHADING1_SUB_LID)
                nvram_camera_shading1_struct *NVRAM_EF_CAMERA_SHADING1_SUB_TOTAL
                {
                    SHADING1:"shading table 1"
                    {
                    };
                    SHADING1.previewSize:"Preview shading table size"
                    {
                    };
                    SHADING1.captureSize:"Capture shading table size"
                    {
                    };
                    SHADING1.captureTable1:"Capture shading table 1"
                    {
                    };
                };
            
                LID_BIT VER_LID(NVRAM_EF_CAMERA_SHADING2_SUB_LID)
                nvram_camera_shading2_struct *NVRAM_EF_CAMERA_SHADING2_SUB_TOTAL
                {
                    SHADING2:"shading table 2"
                    {
                    };
                    SHADING2.previewTable:"Preview shading table"
                    {
                    };
                    SHADING2.captureTable2:"Capture shading table 2"
                    {
                    };
                };

                #if defined(DRV_ISP_PCA_SUPPORT)
                    
                    LID_BIT VER_LID(NVRAM_EF_CAMERA_PCA_SUB_LID)
                    nvram_camera_pca_struct *NVRAM_EF_CAMERA_PCA_SUB_TOTAL
                    {
                        pcaCtrlReg:"PCA control register"
                        {
                        };
                        pcaGmcReg:"PCA GMC throttle control"
                        {
                        };
                        chroma_thres_lo:"Y threshold in ct low"
                        {
                        };
                        chroma_thres_md:"Y threshold in ct medium"
                        {
                        };
                        chroma_thres_hi:"Y threshold in ct high"
                        {
                        };
                        PCA_LUT_LO:"PCA low CT table"
                        {
                        };
                        PCA_LUT_LO.Hue_shift:"Hue shift"
                        {
                        };
                        PCA_LUT_LO.Sat_gain:"Saturation gain"
                        {
                        };
                        PCA_LUT_LO.Y_gain:"Y gain"
                        {
                        };
                        PCA_LUT_MD:"PCA medium CT table"
                        {
                        };
                        PCA_LUT_MD.Hue_shift:"Hue shift"
                        {
                        };
                        PCA_LUT_MD.Sat_gain:"Saturation gain"
                        {
                        };
                        PCA_LUT_MD.Y_gain:"Y gain"
                        {
                        };
                        PCA_LUT_HI:"PCA high CT table"
                        {
                        };
                        PCA_LUT_HI.Hue_shift:"Hue shift"
                        {
                        };
                        PCA_LUT_HI.Sat_gain:"Saturation gain"
                        {
                        };
                        PCA_LUT_HI.Y_gain:"Y gain"
                        {
                        };
                    };
                #endif
            #endif
        #endif

        #if (defined(CMOS_SENSOR_BAK1)) /*keep this sequence*/
            LID_BIT VER_LID(NVRAM_EF_CAMERA_PARA1_MAIN_BAK1_LID)
            nvram_camera_para_struct *NVRAM_EF_CAMERA_PARA1_MAIN_BAK1_TOTAL
            {
                ISPCOMM:"ISP Comm Register"
                {
                };
                ISPCOMM.commReg: "ISP register"
                {
                };
                ISPTUNING:"ISP tuning para"
                {
                };
                MSHUTTER:"Mechanical shutter calibration"
                {
                };
                SENSOR:"SENSOR SETTING"
                {
                };
                SENSOR.reg:"Sensor register"
                {
                };
                SENSOR.cct:"cct"
                {
                };
            };

            #if (defined(RAW_MAIN_CAMERA))
                LID_BIT VER_LID(NVRAM_EF_CAMERA_PARA2_MAIN_BAK1_LID)
                nvram_camera_3a_struct *NVRAM_EF_CAMERA_PARA2_MAIN_BAK1_TOTAL
                {
                    AE:"AE para"
                    {
                    };
                    AE.aeIsoPara: "Iso calibration data"
                    {
                    };
                    AE.aeIsoPara.IsoGain: "Iso gain"
                    {
                    };
                    AE.aeIsoPara.IsoValue: "Iso value"
                    {
                    };
                    AE.aeMeteringComm: "metering"
                    {
                    };
                    AE.aeMeteringComm.target_mean: "target mean"
                    {
                    };
                    AE.aeMeteringComm.init_expo_idx: "init index"
                    {
                    };
                    AE.aeMeteringComm.flare_fix_flag: "flare fix flage"
                    {
                    };
                    AE.aeMeteringComm.flare_fix_offset: "flare fix offset"
                    {
                    };
                    AE.aeMeteringComm.flare_search_dn_ratio: "flare auto search ratio by 1024 base"
                    {
                    };
                    AE.aeMeteringComm.flare_min_offset: "flare auto min offset"
                    {
                    };
                    AE.aeMeteringComm.preview_gamma_no: "preview gamma no"
                    {
                    };
                    AE.aeMeteringComm.preview_flare_offset: "preview flare offset"
                    {
                    };
                    AE.aeMeteringComm.indoor_outdoor_ev: "indoor & outdoor ev"
                    {
                    };
                    AE.aeMeteringComm.indoor_min_gamma_mean: "indoor gamma mean"
                    {
                    };
                    AE.aeMeteringComm.outdoor_max_gamma_mean: "outdoor gamma mean"
                    {
                    };
                    AE.aeMeteringComm.sky_ev: "sky detetcion ev"
                    {
                    };
                    AE.aeMeteringComm.sky_mean: "sky gamma mean"
                    {
                    };
                    AE.aeMeteringComm.sky_max_window_mean: "sky detetcion window mean"
                    {
                    };
                    AE.aeMeteringComm.min_under_expo_bin:"min under expo bin"
                    {
                    };
                    AE.aeMeteringComm.lowlight_ev: "ev to limit max gamma"
                    {
                    };
                    AE.aeMeteringComm.lowlight_min_target_mean: "linear mean to limit max gamma"
                    {
                    };
                    AE.aeMeteringComm.non_over_exposure_stretch_enabled: "non-over expo stretch enable"
                    {
                    };
                    AE.aeMeteringComm.full_dark_background_check_enabled: "full dark check enable"
                    {
                    };
                    AE.aeMeteringComm.gamma_lut: "fast lut gamma table"
                    {
                    };
                    AE.aeMeteringComm.grass_detect_enable: "grass_detect_enable"
                    {
                    };
                    AE.ae_smooth: "AE smooth"
                    {
                    };
                    AE.reserve_1: "reserve"
                    {
                    };
                    AWB:"AWB para"
                    {
                    };
                    AWB.AWB:"AWB para"
                    {
                    };
                    AWB.CCM:"CCM para"
                    {
                    };
                    AF:"AF para"
                    {
                    };
                    AF.lens_calibration:"lens calibration"
                    {
                    };
                    AF.table_info:"table info"
                    {
                    };
                    AF.para_info:"para info"
                    {
                    };
                };

                LID_BIT VER_LID(NVRAM_EF_CAMERA_DEFECT1_MAIN_BAK1_LID)
                nvram_camera_defect1_struct *NVRAM_EF_CAMERA_DEFECT1_MAIN_BAK1_TOTAL
                {
                    DEFECT1:"Defect table 1"
                    {
                    };
                    DEFECT1.previewSize:"Preview defect table size"
                    {
                    };
                    DEFECT1.captureSize:"Capture defect table size"
                    {
                    };
                    DEFECT1.captureTable1:"Capture defect table 1"
                    {
                    };
                };
                
                LID_BIT VER_LID(NVRAM_EF_CAMERA_DEFECT2_MAIN_BAK1_LID)
                nvram_camera_defect2_struct *NVRAM_EF_CAMERA_DEFECT2_MAIN_BAK1_TOTAL
                {
                    DEFECT2:"defect table 2"
                    {
                    };
                    DEFECT2.previewTable:"Preview defect table"
                    {
                    };
                    DEFECT2.captureTable2:"Capture defect table 2"
                    {
                    };
                };

                LID_BIT VER_LID(NVRAM_EF_CAMERA_SHADING1_MAIN_BAK1_LID)
                nvram_camera_shading1_struct *NVRAM_EF_CAMERA_SHADING1_MAIN_BAK1_TOTAL
                {
                    SHADING1:"shading table 1"
                    {
                    };
                    SHADING1.previewSize:"Preview shading table size"
                    {
                    };
                    SHADING1.captureSize:"Capture shading table size"
                    {
                    };
                    SHADING1.captureTable1:"Capture shading table 1"
                    {
                    };
                };
                
                LID_BIT VER_LID(NVRAM_EF_CAMERA_SHADING2_MAIN_BAK1_LID)
                nvram_camera_shading2_struct *NVRAM_EF_CAMERA_SHADING2_MAIN_BAK1_TOTAL
                {
                    SHADING2:"shading table 2"
                    {
                    };
                    SHADING2.previewTable:"Preview shading table"
                    {
                    };
                    SHADING2.captureTable2:"Capture shading table 2"
                    {
                    };
                };
                
                #if defined(DRV_ISP_PCA_SUPPORT)
                    LID_BIT VER_LID(NVRAM_EF_CAMERA_PCA_MAIN_BAK1_LID)
                    nvram_camera_pca_struct *NVRAM_EF_CAMERA_PCA_MAIN_BAK1_TOTAL
                    {
                        pcaCtrlReg:"PCA control register"
                        {
                        };
                        pcaGmcReg:"PCA GMC throttle control"
                        {
                        };
                        chroma_thres_lo:"Y threshold in ct low"
                        {
                        };
                        chroma_thres_md:"Y threshold in ct medium"
                        {
                        };
                        chroma_thres_hi:"Y threshold in ct high"
                        {
                        };
                        PCA_LUT_LO:"PCA low CT table"
                        {
                        };
                        PCA_LUT_LO.Hue_shift:"Hue shift"
                        {
                        };
                        PCA_LUT_LO.Sat_gain:"Saturation gain"
                        {
                        };
                        PCA_LUT_LO.Y_gain:"Y gain"
                        {
                        };
                        PCA_LUT_MD:"PCA medium CT table"
                        {
                        };
                        PCA_LUT_MD.Hue_shift:"Hue shift"
                        {
                        };
                        PCA_LUT_MD.Sat_gain:"Saturation gain"
                        {
                        };
                        PCA_LUT_MD.Y_gain:"Y gain"
                        {
                        };
                        PCA_LUT_HI:"PCA high CT table"
                        {
                        };
                        PCA_LUT_HI.Hue_shift:"Hue shift"
                        {
                        };
                        PCA_LUT_HI.Sat_gain:"Saturation gain"
                        {
                        };
                        PCA_LUT_HI.Y_gain:"Y gain"
                        {
                        };
                    };
                    #if defined (__AUTO_SCENE_DETECT_SUPPORT__)
                    LID_BIT VER_LID(NVRAM_EF_CAMERA_PCA2_MAIN_BAK1_LID)
                    nvram_camera_pca_struct *NVRAM_EF_CAMERA_PCA2_MAIN_BAK1_TOTAL
                    {
                        pcaCtrlReg:"PCA2 control register"
                        {
                        };
                        pcaGmcReg:"PCA2 GMC throttle control"
                        {
                        };
                        chroma_thres_lo:"Y threshold in ct low"
                        {
                        };
                        chroma_thres_md:"Y threshold in ct medium"
                        {
                        };
                        chroma_thres_hi:"Y threshold in ct high"
                        {
                        };
                        PCA_LUT_LO:"PCA2 low CT table"
                        {
                        };
                        PCA_LUT_LO.Hue_shift:"Hue shift"
                        {
                        };
                        PCA_LUT_LO.Sat_gain:"Saturation gain"
                        {
                        };
                        PCA_LUT_LO.Y_gain:"Y gain"
                        {
                        };
                        PCA_LUT_MD:"PCA2 medium CT table"
                        {
                        };
                        PCA_LUT_MD.Hue_shift:"Hue shift"
                        {
                        };
                        PCA_LUT_MD.Sat_gain:"Saturation gain"
                        {
                        };
                        PCA_LUT_MD.Y_gain:"Y gain"
                        {
                        };
                        PCA_LUT_HI:"PCA high CT table"
                        {
                        };
                        PCA_LUT_HI.Hue_shift:"Hue shift"
                        {
                        };
                        PCA_LUT_HI.Sat_gain:"Saturation gain"
                        {
                        };
                        PCA_LUT_HI.Y_gain:"Y gain"
                        {
                        };
                    };
                    #endif				
                #endif
            #endif
        #endif
        
        #if (defined(CMOS_SENSOR_SUB_BAK1)) /*keep this sequence*/
            LID_BIT VER_LID(NVRAM_EF_CAMERA_PARA1_SUB_BAK1_LID)
            nvram_camera_para_struct *NVRAM_EF_CAMERA_PARA1_SUB_BAK1_TOTAL
            {
                ISPCOMM:"ISP Comm Register"
                {
                };
                ISPCOMM.commReg: "ISP register"
                {
                };
                ISPTUNING:"ISP tuning para"
                {
                };
                MSHUTTER:"Mechanical shutter calibration"
                {
                };
                SENSOR:"SENSOR SETTING"
                {
                };
                SENSOR.reg:"Sensor register"
                {
                };
                SENSOR.cct:"cct"
                {
                };
            };

            #if (defined(RAW_MAIN_CAMERA))
                LID_BIT VER_LID(NVRAM_EF_CAMERA_PARA2_SUB_BAK1_LID)
                nvram_camera_3a_struct *NVRAM_EF_CAMERA_PARA2_SUB_BAK1_TOTAL
                {
                    AE:"AE para"
                    {
                    };
                    AE.aeIsoPara: "Iso calibration data"
                    {
                    };
                    AE.aeIsoPara.IsoGain: "Iso gain"
                    {
                    };
                    AE.aeIsoPara.IsoValue: "Iso value"
                    {
                    };
                    AE.aeMeteringComm: "metering"
                    {
                    };
                    AE.aeMeteringComm.target_mean: "target mean"
                    {
                    };
                    AE.aeMeteringComm.init_expo_idx: "init index"
                    {
                    };
                    AE.aeMeteringComm.flare_fix_flag: "flare fix flage"
                    {
                    };
                    AE.aeMeteringComm.flare_fix_offset: "flare fix offset"
                    {
                    };
                    AE.aeMeteringComm.flare_search_dn_ratio: "flare auto search ratio by 1024 base"
                    {
                    };
                    AE.aeMeteringComm.flare_min_offset: "flare auto min offset"
                    {
                    };
                    AE.aeMeteringComm.preview_gamma_no: "preview gamma no"
                    {
                    };
                    AE.aeMeteringComm.preview_flare_offset: "preview flare offset"
                    {
                    };
                    AE.aeMeteringComm.indoor_outdoor_ev: "indoor & outdoor ev"
                    {
                    };
                    AE.aeMeteringComm.indoor_min_gamma_mean: "indoor gamma mean"
                    {
                    };
                    AE.aeMeteringComm.outdoor_max_gamma_mean: "outdoor gamma mean"
                    {
                    };
                    AE.aeMeteringComm.sky_ev: "sky detetcion ev"
                    {
                    };
                    AE.aeMeteringComm.sky_mean: "sky gamma mean"
                    {
                    };
                    AE.aeMeteringComm.sky_max_window_mean: "sky detetcion window mean"
                    {
                    };
                    AE.aeMeteringComm.min_under_expo_bin:"min under expo bin"
                    {
                    };
                    AE.aeMeteringComm.lowlight_ev: "ev to limit max gamma"
                    {
                    };
                    AE.aeMeteringComm.lowlight_min_target_mean: "linear mean to limit max gamma"
                    {
                    };
                    AE.aeMeteringComm.non_over_exposure_stretch_enabled: "non-over expo stretch enable"
                    {
                    };
                    AE.aeMeteringComm.full_dark_background_check_enabled: "full dark check enable"
                    {
                    };
                    AE.aeMeteringComm.gamma_lut: "fast lut gamma table"
                    {
                    };
                    AE.aeMeteringComm.grass_detect_enable: "grass_detect_enable"
                    {
                    };
                    AE.ae_smooth: "AE smooth"
                    {
                    };
                    AE.reserve_1: "reserve"
                    {
                    };
                    AWB:"AWB para"
                    {
                    };
                    AWB.AWB:"AWB para"
                    {
                    };
                    AWB.CCM:"CCM para"
                    {
                    };
                    AF:"AF para"
                    {
                    };
                    AF.lens_calibration:"lens calibration"
                    {
                    };
                    AF.table_info:"table info"
                    {
                    };
                    AF.para_info:"para info"
                    {
                    };
                };

                LID_BIT VER_LID(NVRAM_EF_CAMERA_DEFECT1_SUB_BAK1_LID)
                nvram_camera_defect1_struct *NVRAM_EF_CAMERA_DEFECT1_SUB_BAK1_TOTAL
                {
                    DEFECT1:"Defect table 1"
                    {
                    };
                    DEFECT1.previewSize:"Preview defect table size"
                    {
                    };
                    DEFECT1.captureSize:"Capture defect table size"
                    {
                    };
                    DEFECT1.captureTable1:"Capture defect table 1"
                    {
                    };
                };

                LID_BIT VER_LID(NVRAM_EF_CAMERA_DEFECT2_SUB_BAK1_LID)
                nvram_camera_defect2_struct *NVRAM_EF_CAMERA_DEFECT2_SUB_BAK1_TOTAL
                {
                    DEFECT2:"defect table 2"
                    {
                    };
                    DEFECT2.previewTable:"Preview defect table"
                    {
                    };
                    DEFECT2.captureTable2:"Capture defect table 2"
                    {
                    };
                };

                LID_BIT VER_LID(NVRAM_EF_CAMERA_SHADING1_SUB_BAK1_LID)
                nvram_camera_shading1_struct *NVRAM_EF_CAMERA_SHADING1_SUB_BAK1_TOTAL
                {
                    SHADING1:"shading table 1"
                    {
                    };
                    SHADING1.previewSize:"Preview shading table size"
                    {
                    };
                    SHADING1.captureSize:"Capture shading table size"
                    {
                    };
                    SHADING1.captureTable1:"Capture shading table 1"
                    {
                    };
                };

                LID_BIT VER_LID(NVRAM_EF_CAMERA_SHADING2_SUB_BAK1_LID)
                nvram_camera_shading2_struct *NVRAM_EF_CAMERA_SHADING2_SUB_BAK1_TOTAL
                {
                    SHADING2:"shading table 2"
                    {
                    };
                    SHADING2.previewTable:"Preview shading table"
                    {
                    };
                    SHADING2.captureTable2:"Capture shading table 2"
                    {
                    };
                };

                #if defined(DRV_ISP_PCA_SUPPORT)
                    LID_BIT VER_LID(NVRAM_EF_CAMERA_PCA_SUB_BAK1_LID)
                    nvram_camera_pca_struct *NVRAM_EF_CAMERA_PCA_SUB_BAK1_TOTAL
                    {
                        pcaCtrlReg:"PCA control register"
                        {
                        };
                        pcaGmcReg:"PCA GMC throttle control"
                        {
                        };
                        chroma_thres_lo:"Y threshold in ct low"
                        {
                        };
                        chroma_thres_md:"Y threshold in ct medium"
                        {
                        };
                        chroma_thres_hi:"Y threshold in ct high"
                        {
                        };
                        PCA_LUT_LO:"PCA low CT table"
                        {
                        };
                        PCA_LUT_LO.Hue_shift:"Hue shift"
                        {
                        };
                        PCA_LUT_LO.Sat_gain:"Saturation gain"
                        {
                        };
                        PCA_LUT_LO.Y_gain:"Y gain"
                        {
                        };
                        PCA_LUT_MD:"PCA medium CT table"
                        {
                        };
                        PCA_LUT_MD.Hue_shift:"Hue shift"
                        {
                        };
                        PCA_LUT_MD.Sat_gain:"Saturation gain"
                        {
                        };
                        PCA_LUT_MD.Y_gain:"Y gain"
                        {
                        };
                        PCA_LUT_HI:"PCA high CT table"
                        {
                        };
                        PCA_LUT_HI.Hue_shift:"Hue shift"
                        {
                        };
                        PCA_LUT_HI.Sat_gain:"Saturation gain"
                        {
                        };
                        PCA_LUT_HI.Y_gain:"Y gain"
                        {
                        };
                    };
                #endif
            #endif
        #endif
    #endif /* (!(defined(DUAL_CAMERA_SUPPORT) || defined(BACKUP_SENSOR_SUPPORT))) */
#endif /* defined(ISP_SUPPORT) & 6238 */
 
END_NVRAM_DATA

#endif  /* GEN_FOR_PC */
#endif  /* !NVRAM_NOT_PRESENT */
#endif  /* __CAMERA_NVRAM_EDITOR_H__ */
