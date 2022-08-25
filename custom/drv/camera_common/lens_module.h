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
 *   lens_module.h
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   Lens module header file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _LENS_MODULE_H
#define _LENS_MODULE_H

#include "mm_comm_def.h"
#include "sensor_comm_def.h"
#include "lens_comm_def.h"

#if(defined(SUNNY_S5M03G_MT9P012_AD5820))
#include "lens_module_SUNNY_S5M03G_MT9P012_AD5820.h"
#endif

#if(defined(AKEER_OV5642_AD5820))
#include "lens_module_AKEER_OV5642_AD5820.h"
#endif

#if(defined(FOXCONN_ATCM_5011_MT9P012_AD5820))
#include "lens_module_FOXCONN_ATCM_5011_MT9P012_AD5820.h"
#endif

#if(defined(ABICO_WZ36A333_OV3640_SITI_MD118B))
#include "lens_module_ABICO_WZ36A333_OV3640_SITI_MD118B.h"
#endif

#if(defined(SUNNY_Q5M04B_MT9P015_BH6412GUL))
#include "lens_module_SUNNY_Q5M04B_MT9P015_BH6412GUL.h"
#endif

#if(defined(SUNNY_P5D01A_ET8EV3_AD5820))
#include "lens_module_SUNNY_P5D01A_ET8EV3_AD5820.h"
#endif

#define MAX_LENS_NUMBER (4)


typedef struct
{
    kal_uint32 SensorId;
    MM_ERROR_CODE_ENUM (* LensFunc) (P_LENS_FUNCTION_STRUCT *pfLensFunc);
    IMAGE_SENSOR_INDEX_ENUM SensorIdx;
} LENS_LIST_STRUCT, *P_LENS_LIST_STRUCT;


// for camera HAL
#define ADD_LENS_MODULE(SensorId, PrefixName,SensorIdx)\
{\
    SensorId,\
    ##PrefixName##LensFuncInit,\
    SensorIdx,\
}

// for camera HAL
extern kal_uint32 LensOutParaLen;
extern LENS_LIST_STRUCT LensList[MAX_LENS_NUMBER+1];

MM_ERROR_CODE_ENUM GetAfLensInitFunc(P_LENS_LIST_STRUCT *pLensList);
void LensAfPowerOn(IMAGE_SENSOR_INDEX_ENUM Idx, kal_bool On);

#endif /* _LENS_MODULE_H */
