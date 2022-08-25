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
 *   provider_utility.c
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
 * removed!
 * removed!
 * removed!
 *
 *
 ****************************************************************************/

#include "drv_comm.h"
#ifdef __VE_SOURCE_PROVIDER__
#include "provider_utility.h"
#include "vcodec_v2_trc.h"


#ifdef __VE_MM_DCM_SUPPORT__
#include "dcmgr.h" //DCM

#pragma arm section code = "DYNAMIC_CODE_VECOM_ROCODE", rodata = "DYNAMIC_CODE_VECOM_RODATA"
#endif

#ifdef __VE_H264_DEC_SUPPORT__

/**
 To Pack the NALU information for H.264 parameter sets.
 NOTE:
 1. Max PROVIDER_UTILITY_MAX_PARAMSET_NUM*2*sizeof(SPIF_H264_DECODER_PAYLOAD_INFO_T)
 bytes are allocated by using prSourceAPI.
 2. prVideoParamSetData->prNALCTRLBuff needs to be freed by caller
 **/
void ProviderUtilityGetParamSetNalUnits(SP_API_T *prSourceAPI,
                                        void *prSourceHandle,
                                        PU_VID_PARAM_SET_T *prVideoParamSetData)
{
    kal_uint32 u4NumOfSPS;
    kal_uint32 u4SPSLength;
    kal_uint32 u4NumOfPPS;
    kal_uint32 u4PPSLength;
    kal_uint32 u4DataIndex, u4ParamSetIndex, u4Sum;
    kal_uint32 i;
    kal_uint8 *pu1ParamSetDataBuff;
    SPIF_H264_DECODER_PAYLOAD_INFO_T *prNALCTRLBuff;
    kal_uint32 u4ParseError = 0;

    if (!prVideoParamSetData)
    {
        ASSERT(0);
        return;
    }

    prNALCTRLBuff =
        (SPIF_H264_DECODER_PAYLOAD_INFO_T*)prSourceAPI->SPFN_MALLOC_CLA
        (prSourceHandle, sizeof(SPIF_H264_DECODER_PAYLOAD_INFO_T)*PROVIDER_UTILITY_MAX_PARAMSET_NUM, KAL_FALSE);
    ASSERT(prNALCTRLBuff != NULL);

    do
    {
    // The following code is to obtain sps, pps information {address, length} of each NALu
    //
    pu1ParamSetDataBuff = prVideoParamSetData->pu1ParamSetBuff;

    u4DataIndex = 0;
    u4ParamSetIndex = 0;
    u4Sum = 0;
    // Pack parameter set
    // Remove length information
    //

    // SPS stream
    //
    u4NumOfSPS = (kal_uint32)(pu1ParamSetDataBuff[u4DataIndex++] & 0x1F);

    for (i = 0; i < u4NumOfSPS; i++)
    {
        u4SPSLength = (kal_uint32)(((pu1ParamSetDataBuff[u4DataIndex] & 0xFF) << 8) | (pu1ParamSetDataBuff[u4DataIndex + 1] & 0xFF));

        // Make sure total length is less than real buffer length
        // or it will occur memory curruption
        u4Sum += u4SPSLength;
        if (u4Sum > prVideoParamSetData->u4ParamSetTotalSize)
        {
            //MP4_PVDR_ASSERT(0);
            u4ParseError = 1;
            break;
        }
        u4DataIndex += 2;

        // Fill up parameter set information arrary
        //
        prNALCTRLBuff[u4ParamSetIndex].u4Address = (kal_uint32)&pu1ParamSetDataBuff[u4DataIndex];
        prNALCTRLBuff[u4ParamSetIndex].u4Length = (kal_uint32)u4SPSLength;

        // update index
        //
        u4DataIndex += u4SPSLength;
        u4ParamSetIndex++;
    }
    if(u4ParseError != 0)
    {
        break;
    }

    // PPS stream
    //
    u4NumOfPPS = (kal_uint32)(pu1ParamSetDataBuff[u4DataIndex++] & 0xFF);

    for (i = 0; i < u4NumOfPPS; i++)
    {
        u4PPSLength = (kal_uint32)(((pu1ParamSetDataBuff[u4DataIndex] & 0xFF) << 8) | (pu1ParamSetDataBuff[u4DataIndex + 1] & 0xFF));

        // Make sure total length is less than real buffer length
        // or it will occur memory curruption
        u4Sum += u4PPSLength;
        if (u4Sum > prVideoParamSetData->u4ParamSetTotalSize)
        {
            u4ParseError = 2;
            break;
        }
        u4DataIndex += 2;

        // Fill up parameter set information arrary
        //
        prNALCTRLBuff[u4ParamSetIndex].u4Address = (kal_uint32)&pu1ParamSetDataBuff[u4DataIndex];
        prNALCTRLBuff[u4ParamSetIndex].u4Length = (kal_uint32)u4PPSLength;

        // update index
        //
        u4DataIndex += u4PPSLength;
        u4ParamSetIndex++;
    }
    if(u4ParseError != 0)
    {
        break;
    }

    // Check boundary
    //
    if (u4DataIndex > prVideoParamSetData->u4ParamSetTotalSize)
    {
        u4ParseError = 3;
        break;
    }

    // parameter array index should be less than PROVIDER_UTILITY_MAX_PARAMSET_NUM
    //
    if (u4ParamSetIndex > PROVIDER_UTILITY_MAX_PARAMSET_NUM)
    {
        ASSERT(0);
        u4ParseError = 4;
        break;
    }
    else
    {
        if (u4ParamSetIndex)
        {
            prVideoParamSetData->prNALCTRLBuff =
                (SPIF_H264_DECODER_PAYLOAD_INFO_T*)prSourceAPI->SPFN_MALLOC_CLA(
                prSourceHandle, sizeof(SPIF_H264_DECODER_PAYLOAD_INFO_T)*u4ParamSetIndex, KAL_FALSE);
            ASSERT(prVideoParamSetData->prNALCTRLBuff != NULL);
            prSourceAPI->SPFN_MEM_SET(prVideoParamSetData->prNALCTRLBuff, 0, sizeof(SPIF_H264_DECODER_PAYLOAD_INFO_T)*u4ParamSetIndex);
        }

        for (i = 0; i < u4ParamSetIndex; i++)
        {
            prVideoParamSetData->prNALCTRLBuff[i].u4Address = prNALCTRLBuff[i].u4Address;
            prVideoParamSetData->prNALCTRLBuff[i].u4Length = prNALCTRLBuff[i].u4Length;
        }

        // Assign number of Parameter Set NALu here
        //
        prVideoParamSetData->u4NumOfNALuParamSet = u4ParamSetIndex;
    }
    }while(0);

    if(u4ParseError != 0)
    {
        // SPS/PPS in container error. Viewed as no SPS/PPS.
        drv_trace1(PU_TRACE_HIGH_GROUP, PU_H264_SPS_PPS_ERR, u4ParseError);
        prVideoParamSetData->u4ParamSetTotalSize = 0;
    }

    prSourceAPI->SPFN_FREE_CLA(prSourceHandle, prNALCTRLBuff);

}

/**
 To Pack the NALU information for H.264 sample
 NOTE:
 1. pt_data->pu1Payload needs to be freed by caller.
 **/
media_error_t ProviderUtilityGetAvcSampleNALU(SP_API_T *prSourceAPI,
                                              void *prSourceHandle,
                                              SPIF_PROVIDER_FRAME_INFO_T* pt_data,
                                              kal_uint32 u4NALUnitLength)
{
    kal_uint32 u4FrameStartAddr;  // this address will remove length information
    kal_uint32 u4FrameLength;  // this address will remove length information
    kal_uint8 *pu1PadNALuStartAddr;
    kal_uint32 u4PadNALuLength = 0;
    kal_uint32 u4CurrentLength;
    kal_uint32 u4PayLoadNALCount;
    kal_uint32 u4PayLoadNALTotal;
    kal_uint32 u4NALuSizeInfo;
    SPIF_H264_DECODER_PAYLOAD_INFO_T *prCurrentNALPayload = NULL;

    // Get basic information
    // We should pack frame information here
    // Pack NALu start address and NALu length
    //
    u4FrameStartAddr = (kal_uint32)pt_data->pu1Addr;
    u4FrameLength = pt_data->u4FrameSize;
    u4NALuSizeInfo = u4NALUnitLength;

    /* Get the total number of NAL Uinits in this sample */
    u4CurrentLength = 0;
    u4PayLoadNALTotal = 0;
    while ((u4CurrentLength + u4NALuSizeInfo) < u4FrameLength)
    {
        u4PayLoadNALTotal++;
        pu1PadNALuStartAddr = (kal_uint8 *)(u4FrameStartAddr + u4CurrentLength);

        if (PROVIDER_UTILITY_NAL_UNIT_LEN_4 == u4NALuSizeInfo)
        {
            u4PadNALuLength = (((pu1PadNALuStartAddr[0] & 0xFF) << 24) |
                               ((pu1PadNALuStartAddr[1] & 0xFF) << 16) |
                               ((pu1PadNALuStartAddr[2] & 0xFF) << 8) |
                               (pu1PadNALuStartAddr[3] & 0xFF));

        }
        else if (PROVIDER_UTILITY_NAL_UNIT_LEN_2 == u4NALuSizeInfo)
        {
            u4PadNALuLength = (((pu1PadNALuStartAddr[0] & 0xFF) << 8) |
                               (pu1PadNALuStartAddr[1] & 0xFF));
        }
        else if (PROVIDER_UTILITY_NAL_UNIT_LEN_1 == u4NALuSizeInfo)
        {
            u4PadNALuLength = (pu1PadNALuStartAddr[0] & 0xFF);
        }
        else
        {
            // 1 payload contains all frame
            u4PayLoadNALTotal = 1;
            break;
        }
        if (u4PadNALuLength <= (u4FrameLength - (u4CurrentLength + u4NALuSizeInfo)))
        {
            u4CurrentLength += u4PadNALuLength + u4NALuSizeInfo;
        }
        else /* error recovery for the case that u4PadNALuLength is not a valid value */
        {
            drv_trace2(PU_TRACE_HIGH_GROUP, PU_H264_NALU_SIZE_ERROR, u4PadNALuLength, __LINE__);
            break;
        }
    }

    pt_data->u4PayloadSize = u4PayLoadNALTotal * sizeof(SPIF_H264_DECODER_PAYLOAD_INFO_T);
    prCurrentNALPayload =
        (SPIF_H264_DECODER_PAYLOAD_INFO_T *)prSourceAPI->SPFN_MALLOC_CLA(prSourceHandle, pt_data->u4PayloadSize, KAL_FALSE);

    if(prCurrentNALPayload == NULL)
    {
        return MED_E_CORRUPTED_DATA;
    }

    pt_data->pu1Payload = (kal_uint8 *)prCurrentNALPayload;
    pt_data->u4PayloadNum = u4PayLoadNALTotal;

    u4CurrentLength = 0;
    u4PayLoadNALCount = 0;
    while ((u4CurrentLength + u4NALuSizeInfo) < u4FrameLength)
    {
        ASSERT(u4PayLoadNALCount < u4PayLoadNALTotal);

        pu1PadNALuStartAddr = (kal_uint8 *)(u4FrameStartAddr + u4CurrentLength);

        if (PROVIDER_UTILITY_NAL_UNIT_LEN_4 == u4NALuSizeInfo)
        {
            u4PadNALuLength = (((pu1PadNALuStartAddr[0] & 0xFF) << 24) |
                               ((pu1PadNALuStartAddr[1] & 0xFF) << 16) |
                               ((pu1PadNALuStartAddr[2] & 0xFF) << 8) |
                               (pu1PadNALuStartAddr[3] & 0xFF));

        }
        else if (PROVIDER_UTILITY_NAL_UNIT_LEN_2 == u4NALuSizeInfo)
        {
            u4PadNALuLength = (((pu1PadNALuStartAddr[0] & 0xFF) << 8) |
                               (pu1PadNALuStartAddr[1] & 0xFF));
        }
        else if (PROVIDER_UTILITY_NAL_UNIT_LEN_1 == u4NALuSizeInfo)
        {
            u4PadNALuLength = (pu1PadNALuStartAddr[0] & 0xFF);
        }
        else
        {
            // 1 payload contains all frame
            prCurrentNALPayload[0].u4Address = u4FrameStartAddr;
            prCurrentNALPayload[0].u4Length = u4FrameLength;
            break;
        }

        // fill out NAL Unit information
        //
        prCurrentNALPayload[u4PayLoadNALCount].u4Address = (kal_uint32)pu1PadNALuStartAddr + u4NALuSizeInfo;
        if (u4PadNALuLength <= (u4FrameLength - (u4CurrentLength + u4NALuSizeInfo)))
        {
            prCurrentNALPayload[u4PayLoadNALCount].u4Length = u4PadNALuLength;
        }
        else /* error recovery for the case that u4PadNALuLength is not a valid value */
        {
            prCurrentNALPayload[u4PayLoadNALCount].u4Length = u4FrameLength - (u4CurrentLength + u4NALuSizeInfo);
            break;
        }

        u4CurrentLength += u4PadNALuLength + u4NALuSizeInfo;
        u4PayLoadNALCount++;
    }

    return MED_S_OK;

}
#endif

kal_int32 ProviderUtilityUtf8toUcs2(kal_uint8 *pu1Dest, kal_uint32 u4DestSize, kal_uint8 *pu1Src, kal_uint32 u4SrcSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 u1WordByte, u1SrcByte;
    kal_uint16 u2Ucs2;
    kal_uint32 u4DestCount = 0;
    kal_uint32 u4SrcCount = 0;
    kal_uint8 u1Utf8BytesPerChar[16] = {1, 1, 1, 1, 1, 1, 1, 1,
                                        0, 0, 0, 0, 2, 2, 3, 4 };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    u4DestSize -= ((u4DestSize % 2) + 2); /* make it a even number + null terminator */

    while ((u4DestCount < u4DestSize) && (u4SrcCount < u4SrcSize) && ((u1SrcByte = *pu1Src) != 0))
    {
        u1WordByte = u1Utf8BytesPerChar[u1SrcByte >> 4];
        switch (u1WordByte)
        {
            case 1:
                pu1Dest[u4DestCount] = u1SrcByte;
                pu1Dest[u4DestCount + 1] = 0;
                u4DestCount += 2;
                pu1Src++;
                u4SrcCount++;
                break;
            case 2:
                u2Ucs2 = ((kal_uint16) (u1SrcByte & 0x1F) << 6) | (kal_uint16) (pu1Src[1] & 0x3F);
                pu1Dest[u4DestCount] = u2Ucs2 & 0xFF;
                pu1Dest[u4DestCount + 1] = u2Ucs2 >> 8;
                u4DestCount += 2;
                pu1Src += 2;
                u4SrcCount += 2;
                break;
            case 3:
                u2Ucs2 =
                    ((kal_uint16) (u1SrcByte & 0x0F) << 12) | ((kal_uint16) (pu1Src[1] & 0x3F) << 6) | (kal_uint16) (pu1Src[2] & 0x3F);
                pu1Dest[u4DestCount] = u2Ucs2 & 0xFF;
                pu1Dest[u4DestCount + 1] = u2Ucs2 >> 8;
                u4DestCount += 2;
                pu1Src += 3;
                u4SrcCount += 3;
                break;
            case 4:
                pu1Src += 4;   /* skip it since we don't support UCS4 */
                u4SrcCount += 4;
                break;
            case 0:
                pu1Src++;      /* something wrong with the src, skip it */
                u4SrcCount++;
                break;
        }
    }
    
    pu1Dest[u4DestCount] = 0;
    pu1Dest[u4DestCount + 1] = 0;
    
    return u4DestCount + 2;
}

#ifdef __VE_MM_DCM_SUPPORT__
#pragma arm section code, rodata
#endif

#endif //#ifdef __VE_SOURCE_PROVIDER__

