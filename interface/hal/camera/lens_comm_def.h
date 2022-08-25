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
 *   All chips
 *
 * Description:
 * ------------
 *   This file defines senso.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __LENS_COMM_DEF_H__
#define __LENS_COMM_DEF_H__

#include "cal_comm_def.h"


#define NULL_SENSOR_ID  (0xFFFFFFFF)


/* the lens feature will be used by CAL and ISP driver only */

typedef enum
{
    LENS_FEATURE_BEGIN = CAL_LENS_FEATURE_BEGIN,
    LENS_FEATURE_GET_LENS_ID,
    LENS_FEATURE_GET_LENS_CURRENT_POS,
    LENS_FEATURE_GET_LENS_HOME_CHECK,
    LENS_FEATURE_GET_LENS_STATUS,
    LENS_FEATURE_GET_LENS_TIMING_INFO,
    LENS_FEATURE_SET_LENS_INFO,
    LENS_FEATURE_SET_LENS_STEP_CW,
    LENS_FEATURE_SET_LENS_STEP_CCW,
    LENS_FEATURE_SET_LENS_MOVE_TO,
    LENS_FEATURE_MAX,
}LENS_FEATURE_ENUM;

typedef enum 
{
    AF_STATUS_READY,				/* AF Ready */
    AF_STATUS_OPERATING,			/* AF is operating/Busy */	
    AF_STATUS_FIXED				/* Low battary, AF Fixed */
}LENS_AF_STATUS;


typedef struct
{
    kal_uint32 FeatureValue;
} LENS_COMM_DATA_STRUCT, *P_LENS_COMM_DATA_STRUCT;

typedef struct
{
   MM_ERROR_CODE_ENUM (* LensOpen)(void);
   MM_ERROR_CODE_ENUM (* LensFeatureCtrl) (LENS_FEATURE_ENUM FeatureId, void* pFeatureParaIn, void* pFeatureParaOut,
                                             kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen);
   MM_ERROR_CODE_ENUM (* LensCtrl) (CAL_SCENARIO_ENUM ScenarioId, void *pParaIn, void *pParaOut, kal_uint32 ParaOutLen,
                                      kal_uint32 *pRealParaOutLen);
   MM_ERROR_CODE_ENUM (* LensClose)(void);
}LENS_FUNCTION_STRUCT, *P_LENS_FUNCTION_STRUCT;



#endif /* __LENS_COMM_DEF_H__ */
