/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *	.h
 *
 * Project:
 * --------
 *   MT6238
 *
 * Description:
 * ------------
 *   This file is intends for ISP HW.
 *
 * Author:
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __ISP_NVRAM_H__
#define __ISP_NVRAM_H__

#include "kal_release.h"
#include "image_sensor_nvram.h"
#include "aaa_nvram.h"  // SC NV



#define MAX_DEFECT_MEM_SIZE		(2048)	/* bytes */
#define MAX_PV_SHADING_MEM_SIZE	(2240)	/* bytes(2240)=>560 = 7*5*12*4/3 */
#define MAX_SHADING_MEM_SIZE	(3584)	       /* bytes(3584)=>896 = 7*8*12*4/3 */

#if defined(DRV_ISP_PCA_SUPPORT)
#define MAX_PCA_MEM_SIZE        (2160)  /* 2160 = 4*180(bin)*3(table) */
#define MAX_ISP_MEM_SIZE (MAX_DEFECT_MEM_SIZE+MAX_SHADING_MEM_SIZE+MAX_PCA_MEM_SIZE)
#define MAX_ISP_MP4_MEM_SIZE (MAX_DEFECT_MEM_SIZE+MAX_PV_SHADING_MEM_SIZE+MAX_PCA_MEM_SIZE)
#else
#define MAX_ISP_MEM_SIZE (MAX_DEFECT_MEM_SIZE+MAX_SHADING_MEM_SIZE)
#define MAX_ISP_MP4_MEM_SIZE (MAX_DEFECT_MEM_SIZE+MAX_PV_SHADING_MEM_SIZE)
#endif

#define MAX_DEFECT1_CAP_SIZE  	(508)
#define MAX_DEFECT2_PRV_SIZE  	(255)
#define MAX_DEFECT2_CAP_SIZE  	(255) 
#define MAX_SHADING1_CAP_SIZE 	(508)
#define MAX_SHADING2_PRV_SIZE  	(320) 
#define MAX_SHADING2_CAP_SIZE  	(190)

#define PCA_BIN180 (180)
#define PCA_BIN360 (360)
#define PCA_BIN_NUM PCA_BIN180
#define PCA_LUT_NVRAM_SIZE  (PCA_BIN_NUM*3)   /* 540 = (180 bins * 3 channels) */
#define PCA_LUT_SYSRAM_SIZE (PCA_BIN_NUM*4)   /* 720 = (180 bins * 4 bytes for storage) */

typedef struct
{
    sensor_reg_struct	reg[ENGINEER_END_ADDR];
    sensor_reg_struct	cct[FACTORY_END_ADDR];
} sensor_data_struct;


typedef struct
{
    kal_uint32 commReg[64];
}isp_common_para_struct;


typedef struct
{
    kal_uint8 shading;
    kal_uint8 nr1;
    kal_uint8 nr2;
    kal_uint8 edge;
    kal_uint8 autodefect;    
    kal_uint8 saturation;        
    kal_uint8 contrast;    
    kal_uint8 reserved;
}isp_tuning_index_struct;

typedef struct
{
    isp_tuning_index_struct idx;
    kal_uint32 shadingReg[3][5];/*binning*/
    kal_uint32 nr1Reg[7][11];
    kal_uint32 nr2Reg[7][5];
    kal_uint32 edgeReg[7][3];
    kal_uint32 autodefect[3][5];    
    kal_uint32 saturation[7][4];        
    kal_uint32 contrast[3][3];    
}isp_tuning_para_struct;

typedef struct
{
	kal_uint32 target_time;/*minimum exposure time, unit:pv exp line*/
	kal_uint32 shutter_delay_time; /*shutter delay time, unit: us */
}shutter_delay_struct;



typedef struct
{
    kal_uint16 previewSize;
    kal_uint16 captureSize;
    kal_uint32 captureTable1[MAX_DEFECT1_CAP_SIZE];
}isp_defect1_struct;

typedef struct
{
    kal_uint32 previewTable[MAX_DEFECT2_PRV_SIZE];
    kal_uint32 captureTable2[MAX_DEFECT2_CAP_SIZE];
}isp_defect2_struct;

typedef struct
{
    kal_uint16 previewSize;
    kal_uint16 captureSize;
    kal_uint32 captureTable1[MAX_SHADING1_CAP_SIZE];
}isp_shading1_struct;

typedef struct
{
    kal_uint32 previewTable[MAX_SHADING2_PRV_SIZE];
    kal_uint32 captureTable2[MAX_SHADING2_CAP_SIZE];
}isp_shading2_struct;


#if defined(__CAMERA_NVRAM_REDUCTION__)// add for 53/35 series yuv sensor
typedef struct
{
	sensor_data_struct		SENSOR;
}nvram_camera_para_struct;
#else
typedef struct
{
    isp_common_para_struct  ISPCOMM;
    isp_tuning_para_struct  ISPTUNING;        
    shutter_delay_struct MSHUTTER;
    sensor_data_struct  SENSOR;  
}nvram_camera_para_struct;
#endif

typedef struct
{
    nvram_ae_para_struct  AE;
    NVRAM_AWB_PARA_STRUCT  AWB;
    AF_NVRAM_PARA_STRUCT  AF;    
}nvram_camera_3a_struct;


typedef struct
{
    isp_defect1_struct  DEFECT1;
}nvram_camera_defect1_struct;


typedef struct
{
    isp_defect2_struct  DEFECT2;
}nvram_camera_defect2_struct;


typedef struct
{
    isp_shading1_struct  SHADING1;
}nvram_camera_shading1_struct;


typedef struct
{
    isp_shading2_struct  SHADING2;
}nvram_camera_shading2_struct;


typedef struct
{
    kal_uint8 Hue_shift[PCA_BIN_NUM];
    kal_uint8 Sat_gain[PCA_BIN_NUM];
    kal_uint8 Y_gain[PCA_BIN_NUM];
} isp_pca_lut_struct;

typedef struct
{
    kal_uint32 pcaCtrlReg;
    kal_uint32 pcaGmcReg;
    kal_uint8 chroma_thres_lo;
    kal_uint8 chroma_thres_md;
    kal_uint8 chroma_thres_hi;
    isp_pca_lut_struct PCA_LUT_LO;
    isp_pca_lut_struct PCA_LUT_MD;
    isp_pca_lut_struct PCA_LUT_HI;
} nvram_camera_pca_struct;





#endif /* __ISP_COMM_IF_H__ */
