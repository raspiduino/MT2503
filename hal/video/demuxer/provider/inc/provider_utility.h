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
 *   provider_utility.h
 *
 * Project:
 * --------
 *	MTK
 *
 * Description:
 * ------------
 *
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
 ****************************************************************************/

#ifndef PROVIDER_UTILITY_H
#define PROVIDER_UTILITY_H
#include "source_provider_if.h"

#define PU_TRACE_HIGH_GROUP TRACE_GROUP_1
#define PU_TRACE_LOW_GROUP TRACE_GROUP_3

#define PROVIDER_UTILITY_MAX_PARAMSET_NUM (288) // 32 + 256

/***************************
   enum
  ***************************/
typedef enum
{
    PROVIDER_UTILITY_NAL_UNIT_LEN_1 = 1,
    PROVIDER_UTILITY_NAL_UNIT_LEN_2 = 2,
    PROVIDER_UTILITY_NAL_UNIT_LEN_4 = 4
} PU_H264_NAL_UNIT_LENGTH;

/***************************
   struct
  ***************************/
/* Parameter Set Information */
typedef struct
{
    // MPEG-4 & H.264 common, excluding H.263

    // Starting from numOfSequenceParameterSets in H.264 case. refer
    // Refer AVCDecoderConfigurationRecord in 14496-15
    kal_uint8* pu1ParamSetBuff;
    kal_uint32 u4ParamSetTotalSize;

    // Only for H.264
    //
    kal_uint32 u4NALuSizeInfo;
    kal_uint32 u4NumOfNALuParamSet;

    // The private data is used only for H.264
    // The buffer is used for parameter set record
    kal_uint32 u4TotalNALSize;
    SPIF_DECODE_PAYLOAD_T rPrivateData;
    SPIF_H264_DECODER_PAYLOAD_INFO_T* prNALCTRLBuff;
} PU_VID_PARAM_SET_T;

/***************************
   extern frunction
  ***************************/
#ifdef __VE_H264_DEC_SUPPORT__
extern void ProviderUtilityGetParamSetNalUnits(SP_API_T *prSourceAPI,
                                              void *prSourceHandle,
                                              PU_VID_PARAM_SET_T *prVideoParamSetData);

extern media_error_t ProviderUtilityGetAvcSampleNALU(SP_API_T *prSourceAPI,
                                                    void *prSourceHandle,
                                                    SPIF_PROVIDER_FRAME_INFO_T* pt_data,
                                                    kal_uint32 u4NALUnitLength);
#endif

extern kal_int32 ProviderUtilityUtf8toUcs2(kal_uint8 *pu1Dest, kal_uint32 u4DestSize, kal_uint8 *pu1Src, kal_uint32 u4SrcSize);

#endif //#ifndef PROVIDER_UTILITY_H

