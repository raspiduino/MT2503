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
 *   video_fluency_utility.c
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
 ****************************************************************************/

#ifndef VIDEO_FLUENCY_UTILITY_H
#define VIDEO_FLUENCY_UTILITY_H


#include "drv_comm.h"         /* drv_traceX */
#include "kal_release.h"      /* Basic data type */

#include "kal_general_types.h"

#include "video_fluency_if.h"
#include "video_fluency_utility.h"
#include "vcodec_v2_trc.h"

#ifdef __VE_VFC_SCD_SUPPORT__
#include "SCD_eng_external.h"
#include "vcodec_dec_demuxer_if.h"
#endif

extern kal_uint32 query_opposite_switchable_cacheaddr_ram(kal_uint32 addr);

#pragma arm section code="SECONDARY_ROCODE"

VIDEO_FLUENCY_CONTROL_T* _prVFCMgr;


#if defined(__VE_FLUENCY_CONTROL_ENABLE__) || defined(__VE_VFC_RECOVER_SUPPORT__)

#ifdef __VE_VFC_SCD_SUPPORT__ 
kal_bool VFC_UpdateSCDInfo(VIDEO_FLUENCY_CONTROL_T* prVFC, VFC_SCD_OPERATION_ENUM eOperation, VFC_SCD_RECORD_OP_DATA_T* pSCDOPData)
{
    if (KAL_TRUE == prVFC->rVFCSCDRecord.fgInited)
    {    
        switch (eOperation)
        {
            case VFC_ADD_SCD_INFO:
            {
                kal_uint8 u1SCDNum = 0;
                kal_bool fgRet;

                // Check if flush had been performed.
                if (pSCDOPData->pSCDRecord->u8MaxTime > pSCDOPData->rSCDData.u8TimeStamp)
                {                
                    // Does this mean Source component had been flushed ?
                    // Because the timestamp of the newly added frame should be larger than the max one.
                    // Flush or seek operation should have occurred.
                    VFC_SLIM_LOG2(TRACE_GROUP_5, VFC_RESET_SCD_RECORD_FOR_MAX_TIME_REVERSE, (kal_uint32)pSCDOPData->pSCDRecord->u8MaxTime, 
                                                                                                     (kal_uint32)pSCDOPData->rSCDData.u8TimeStamp);

                    // Reset SCD record
                    VFCSCDRecordReset(pSCDOPData->pSCDRecord);
                }
                
                u1SCDNum = VideoCoreRingBufferUsedNum(&pSCDOPData->pSCDRecord->rSCDRecordBufferMgr);
               
                // Check if queue is full and update the min time
                if (u1SCDNum == VFC_MAX_FRAME_RECORD_NUM)
                {
                    // Scene change queue is full. Pop the oldest scene record
                    VFC_SCD_RECORD_ENTITY_T rSCDRecordEntity, *prOldestSCD;

                    VFC_SLIM_LOG4(TRACE_GROUP_5, VFC_SCD_RECORD_FULL, (kal_uint32)pSCDOPData->pSCDRecord->u8MaxTime,
                                                                               (kal_uint32)pSCDOPData->pSCDRecord->u8MinTime,
                                                                               (kal_uint32)pSCDOPData->rSCDData.u8TimeStamp, 0);
                               
                    fgRet = VideoCoreRemoveFromTailofRingBufferAddr(&pSCDOPData->pSCDRecord->rSCDRecordBufferMgr, (kal_uint8 *)(&rSCDRecordEntity));
                    VE_UNUSED(fgRet);

                    VFC_SLIM_LOG2(TRACE_GROUP_5, VFC_REMOVE_SCD_ENTITY, (kal_uint32)rSCDRecordEntity.u8TimeStamp, u1SCDNum-1);

                    // Update Min Time
                    prOldestSCD = (VFC_SCD_RECORD_ENTITY_T*)VideoCoreGetHeadofRingBufferAddr(&pSCDOPData->pSCDRecord->rSCDRecordBufferMgr);

                    if (prOldestSCD != NULL)
                    {
                        pSCDOPData->pSCDRecord->u8MinTime = prOldestSCD->u8TimeStamp;
                        
                        VFC_SLIM_LOG4(TRACE_GROUP_5, VFC_UPDATE_SCD_MIN_TIME, (kal_uint32)pSCDOPData->pSCDRecord->u8MaxTime, 
                                                                                       (kal_uint32)pSCDOPData->pSCDRecord->u8MinTime,
                                                                                       u1SCDNum-1,
                                                                                       (kal_uint32)pSCDOPData->rSCDData.u8TimeStamp);                    
                    }
                    else
                    {
                        // Something wrong or queue is empty ..Reset the queue
                        VFC_SLIM_LOG2(TRACE_GROUP_5, VFC_RESET_SCD_RECORD_FOR_MAX_TIME_REVERSE, 0, 0);
                        
                        // Reset SCD record
                        VFCSCDRecordReset(pSCDOPData->pSCDRecord);                       
                    }
                }                               

                VideoCoreInsertToHeadofRingBuffer(&pSCDOPData->pSCDRecord->rSCDRecordBufferMgr, (kal_uint8*)&(pSCDOPData->rSCDData.u8TimeStamp));                

                u1SCDNum = VideoCoreRingBufferUsedNum(&pSCDOPData->pSCDRecord->rSCDRecordBufferMgr);
                
                drv_trace4(TRACE_GROUP_5, VFC_ADD_SCD_FRAME, (kal_uint32)prVFC->rVFCPlaybackInfo.u8CurrentPlayTime, 
                                                                      (kal_uint32)pSCDOPData->rSCDData.u8TimeStamp, 
                                                                      u1SCDNum, 
                                                                      0);

                // Check if need to update MAX SCD time
                if ((pSCDOPData->pSCDRecord->u8MaxTime < pSCDOPData->rSCDData.u8TimeStamp) ||
                    (pSCDOPData->rSCDData.u8TimeStamp == 0))
                {                             
                    VFC_SLIM_LOG4(TRACE_GROUP_5, VFC_UPDATE_SCD_MAX_TIME, (kal_uint32)pSCDOPData->pSCDRecord->u8MaxTime, 
                                                                                   (kal_uint32)pSCDOPData->pSCDRecord->u8MinTime,
                                                                                   u1SCDNum,
                                                                                   (kal_uint32)pSCDOPData->rSCDData.u8TimeStamp);
                    
                    pSCDOPData->pSCDRecord->u8MaxTime = pSCDOPData->rSCDData.u8TimeStamp;
                }
                else
                {                    
                    // This might happen when the same time stamp of different frames.
                    // This implies it's a corrupt file.
                    
                    // Reset SCD record
                    VFCSCDRecordReset(pSCDOPData->pSCDRecord);
                }
            }
            break;

            case VFC_REMOVE_SCD_INFO:
            {           
                kal_bool fgRet;
                VFC_SCD_RECORD_ENTITY_T* prSCDRecordEntity = NULL;
                kal_uint8 u1SCDNum = 0;
               
                do
                {
                    prSCDRecordEntity = (VFC_SCD_RECORD_ENTITY_T*)VideoCoreGetTailofRingBufferAddr(&pSCDOPData->pSCDRecord->rSCDRecordBufferMgr);                                       

                    if (NULL != prSCDRecordEntity)
                    {
                        if (pSCDOPData->rSCDData.u8TimeStamp < prSCDRecordEntity->u8TimeStamp)
                        {
                            u1SCDNum = VideoCoreRingBufferUsedNum(&pSCDOPData->pSCDRecord->rSCDRecordBufferMgr);
                            break;
                        }

                        // Remove the items older than the specified time
                        fgRet = VideoCoreRemoveFromTailofRingBufferAddr(&pSCDOPData->pSCDRecord->rSCDRecordBufferMgr, (kal_uint8 *)(prSCDRecordEntity));                        
                        VE_UNUSED(fgRet);

                        u1SCDNum = VideoCoreRingBufferUsedNum(&pSCDOPData->pSCDRecord->rSCDRecordBufferMgr);

                        VFC_SLIM_LOG4(TRACE_GROUP_5, VFC_REMOVE_SCD_ENTITY, (kal_uint32)pSCDOPData->rSCDData.u8TimeStamp, 
                                                                              (kal_uint32)prSCDRecordEntity->u8TimeStamp, u1SCDNum, 0);                    
                    }
                    else
                    {
                        break;
                    }
                }while(u1SCDNum > 0);
                
                // Check if queue is full and update the min time
                if (u1SCDNum == 0)
                {
                    // Queue is empty ..Reset the queue
                    VFC_SLIM_LOG2(TRACE_GROUP_5, VFC_RESET_SCD_RESET_MAX_MIN_TIME, pSCDOPData->pSCDRecord->u8MaxTime, pSCDOPData->pSCDRecord->u8MinTime);
                    pSCDOPData->pSCDRecord->u8MaxTime = 0;
                    pSCDOPData->pSCDRecord->u8MinTime = 0;                
                }                               
                else
                {
                    VFC_SCD_RECORD_ENTITY_T *prOldestSCD;

                    // Update Min Time
                    prOldestSCD = (VFC_SCD_RECORD_ENTITY_T*)VideoCoreGetTailofRingBufferAddr(&pSCDOPData->pSCDRecord->rSCDRecordBufferMgr);


                    if (prOldestSCD != NULL)
                    {
                        if (pSCDOPData->pSCDRecord->u8MinTime < prOldestSCD->u8TimeStamp)
                        {
                            VFC_SLIM_LOG4(TRACE_GROUP_5, VFC_UPDATE_SCD_MIN_TIME, (kal_uint32)pSCDOPData->pSCDRecord->u8MaxTime, 
                                                                                        (kal_uint32)pSCDOPData->pSCDRecord->u8MinTime,
                                                                                        u1SCDNum,
                                                                                        (kal_uint32)prOldestSCD->u8TimeStamp);                    
                            
                            pSCDOPData->pSCDRecord->u8MinTime = prOldestSCD->u8TimeStamp;
                        }                    
                    }
                }
            }
            break;

            case VFC_RESET_SCD_INFO:
            {
                kal_uint8 u1SCDNum = 0;

                u1SCDNum = VideoCoreRingBufferUsedNum(&pSCDOPData->pSCDRecord->rSCDRecordBufferMgr);

                VFC_SLIM_LOG4(TRACE_GROUP_5, VFC_RESET_SCD_RECORD, (kal_uint32)pSCDOPData->rSCDData.u8TimeStamp, 
                                                                            u1SCDNum,
                                                                            pSCDOPData->pSCDRecord->u8MaxTime,
                                                                            pSCDOPData->pSCDRecord->u8MinTime);

                VE_UNUSED(u1SCDNum);

                // Reset SCD record
                VFCSCDRecordReset(pSCDOPData->pSCDRecord);
            }
            break;
            
            default:            
            break;   
        }
    }
    return KAL_TRUE;
}
#endif


kal_bool VFC_IOCtrl(VIDEO_FLUENCY_OP_CODE_ENUM eOPCode, void* pInData, void* pOutData, void* pExtra)
{
    if (VFC_OP_MPL_INIT_VFC != eOPCode && NULL == _prVFCMgr)
    {
        drv_trace0(TRACE_GROUP_5, VFC_NOT_INIT);
        return KAL_FALSE;
    }

    switch(eOPCode)        
    {
        case VFC_OP_MPL_INIT_VFC:
        {
            _prVFCMgr = (VIDEO_FLUENCY_CONTROL_T*)VideoGetExtBuffer((VIDEO_EXTMEM_HANDLER_T*)pInData, sizeof(VIDEO_FLUENCY_CONTROL_T) + GUARD_PATTERN_LENGTH);
            if (NULL == _prVFCMgr)
            {
                ASSERT(0);
            }
            
            VFC_Init(_prVFCMgr);            
            
#ifdef __VE_VFC_SCD_SUPPORT__  
            // Init SCD record mgr
            VFCSCDRecordInit(&(_prVFCMgr->rVFCSCDRecord), 
                             (kal_uint8*)(_prVFCMgr->rVFCSCDRecord.arSCDRecord),
                             VFC_MAX_FRAME_RECORD_NUM, 
                             sizeof(VFC_SCD_RECORD_ENTITY_T));
#endif            
        }
            return KAL_TRUE;

        case VFC_OP_MPL_DEINIT_VFC:
        {
#ifdef __VE_VFC_SCD_SUPPORT__  
            VFCSCDRecordDeinit(&(_prVFCMgr->rVFCSCDRecord));
#endif            
            VFC_Deinit(_prVFCMgr);
            _prVFCMgr = NULL;
        }
            return KAL_TRUE;
 
        case VFC_OP_SRC_SET_VIDEO_CODEC_TYPE:
        {            
            _prVFCMgr->eCodecType = *(media_codec_type_t*)pInData;

            switch (_prVFCMgr->eCodecType)
            {
#ifdef __VE_RV_DEC_SW_SUPPORT__                
                case MEDIA_CODEC_VID_RV_9:
                case MEDIA_CODEC_VID_RV_10:
                    _prVFCMgr->pFrameHeaderParser = RVSwDecDecodeFrameHeader;
                    break;
#endif
#ifdef __VE_MPEG4_DEC_SW_SUPPORT__
                case MEDIA_CODEC_VID_MPEG4:
                    _prVFCMgr->pFrameHeaderParser = MP4SwDecDecodeFrameHeader;
                    break;
                case MEDIA_CODEC_VID_H263:
                    _prVFCMgr->pFrameHeaderParser = H263SwDecDecodeFrameHeader;
                    break;
#endif
#ifdef __VE_H264_DEC_SW_SUPPORT__
                case MEDIA_CODEC_VID_H264:
                    _prVFCMgr->pFrameHeaderParser = H264SwDecDecodeFrameHeader;
                    break;
#endif
#ifdef __VE_VP8_DEC_SW_SUPPORT__
                case MEDIA_CODEC_VID_VP8:
                    _prVFCMgr->pFrameHeaderParser = VP8SwDecDecodeFrameHeader;
                    break;
#endif                    
                    
                case MEDIA_CODEC_VID_MJPG:                    
                default:
                    _prVFCMgr->pFrameHeaderParser = NULL;
                    break;
            }
        }
        return KAL_TRUE;
         
        case VFC_OP_VD_CHECK_IF_TRIGGER_DECODE:
        {
            // This OP will provide current play time. It should NOT be disabled.
            VFC_VD_CHECK_IF_TRIGGER_DECODE(_prVFCMgr, pInData, pOutData, pExtra);            
        }
            return KAL_TRUE;
        
        case VFC_OP_VD_CHECK_IF_SEND_TO_DISPLAY:
        {
#ifdef __VE_FLUENCY_CONTROL_ENABLE__
            VFC_VD_CHECK_IF_SEND_TO_DISPLAY(_prVFCMgr, pInData, pOutData, pExtra);
            return KAL_TRUE;
#endif             
        }
        break;

        case VFC_OP_SCH_SET_START_TIME:
        {
#ifdef __VE_VFC_SCD_SUPPORT__ 
            VFCSCDRecordReset(&_prVFCMgr->rVFCSCDRecord);
#endif
            
            VFC_SCH_SET_START_TIME(_prVFCMgr, pInData, pOutData, pExtra);
        }
            return KAL_TRUE;

        case VFC_OP_SCH_SET_KEY_FRAME_TIME:
        {
            VFC_SCH_SET_KEY_FRAME_TIME(_prVFCMgr, pInData, pOutData, pExtra);            
            
#ifdef __VE_VFC_SCD_SUPPORT__
            VFC_CheckSCDStatus(_prVFCMgr, pInData, pOutData, pExtra);
#endif
        }
            return KAL_TRUE;

        case VFC_OP_VD_LASTEST_FRAME_TIME:
        {
#ifdef __VE_VFC_SCD_SUPPORT__
            VIDEO_BUFFERHEADER_TYPE_T* pBufferHeader = (VIDEO_BUFFERHEADER_TYPE_T*)pInData;
            VFC_SCD_RECORD_OP_DATA_T rSCDOPData;

            // Remove SCD record
            rSCDOPData.pSCDRecord = &_prVFCMgr->rVFCSCDRecord;                        
            rSCDOPData.rSCDData.u8TimeStamp = pBufferHeader->u8TimeStamp;                    
            VFC_UpdateSCDInfo(_prVFCMgr, VFC_REMOVE_SCD_INFO, &rSCDOPData); 
#endif
            
            VFC_VD_SET_LASTEST_FRAME_TIME(_prVFCMgr, pInData, pOutData, pExtra);            
        }
            return KAL_TRUE;

        case VFC_OP_MPL_SET_JUMP_RANGE:
        {
            VFC_MPL_SET_JUMP_RANGE(_prVFCMgr, pInData, pOutData, pExtra);            
        }
            return KAL_TRUE;

        case VFC_OP_MPL_SET_MAX_AV_TOLERANCE:
        {
            VFC_MPL_SET_MAX_AV_TOLERANCE(_prVFCMgr, pInData, pOutData, pExtra);            
        }
            return KAL_TRUE;

        case VFC_OP_MPL_SET_VIDEO_DURATION:
        {
            VFC_MPL_SET_VIDEO_DURATION(_prVFCMgr, pInData, pOutData, pExtra);            
        }
            return KAL_TRUE;
        
        case VFC_OP_MPL_SET_JUMP_TO_I_THRE:
        {
            VFC_MPL_SET_JUMP_TO_I_THRE(_prVFCMgr, pInData, pOutData, pExtra);
        }
            return KAL_TRUE;

        case VFC_OP_MPL_SET_STOP_AUDIO_THRE:
        {
            VFC_MPL_SET_STOP_AUDIO_THRE(_prVFCMgr, pInData, pOutData, pExtra);            
        }
            return KAL_TRUE;

        case VFC_OP_MPL_SET_SCENARIO:
        {
            VFC_MPL_SET_SCENARIO(_prVFCMgr, pInData, pOutData, pExtra);            
        }
            return KAL_TRUE;

        case VFC_OP_SRC_FRAME_REMOVED:
        case VFC_OP_VD_FRAME_REMOVED:            
        {
#ifdef __VE_VFC_SCD_SUPPORT__    
            //VIDEO_BUFFERHEADER_TYPE_T* pBufferHeader = (VIDEO_BUFFERHEADER_TYPE_T*)pInData;
            kal_bool fgResetAll                      = *(kal_bool*)pExtra;    
            VFC_SCD_RECORD_OP_DATA_T rSCDOPData;
                
            rSCDOPData.pSCDRecord = &_prVFCMgr->rVFCSCDRecord;                        

            if (KAL_TRUE == fgResetAll)
            {
                rSCDOPData.rSCDData.u8TimeStamp = _prVFCMgr->rVFCPlaybackInfo.u8CurrentPlayTime;
                VFC_UpdateSCDInfo(_prVFCMgr, VFC_RESET_SCD_INFO, &rSCDOPData);
            }
#endif                         
        }
            return KAL_TRUE;

        case VFC_OP_SRC_FRAME_ADDED:
        {
#ifdef __VE_VFC_SCD_SUPPORT__      
            VIDEO_BUFFERHEADER_TYPE_T* pBufferHeader = (VIDEO_BUFFERHEADER_TYPE_T*)pInData;     
            // Get the frame type
            VCODEC_DEC_FRAME_HDR_INPUT_T rInput;
            VCODEC_DEC_FRAME_HDR_INFO_T rOutput;
            VCODEC_DEC_FRAME_HDR_ERROR_T eRet;
            
            VFC_SCD_RECORD_OP_DATA_T rSCDOPData;
            SCD_INPUT_DATA_T rInputData;
            SCD_OUTPUT_DATA_T rOutputData;

#ifdef __VE_H264_DEC_SW_SUPPORT__
            H264_DECODER_INPUT_PARAM_T *prH264Input = pBufferHeader->pPrivateData;
            H264_DECODER_PAYLOAD_INFO_T *prPayload = prH264Input->pu1PayloadAddress;
            kal_uint32 u4I;
#endif            
            
            
            kal_mem_set(&rInputData, 0, sizeof(rInputData));
            kal_mem_set(&rOutputData, 0, sizeof(rOutputData));

            

            if (VIDEO_BUFFERFLAG_PARAMETERSET == pBufferHeader->eFlags || VIDEO_BUFFERFLAG_EOF == pBufferHeader->eFlags)
            {
                // We don't want to process data containing only header or EOF
                break;
            }

            if (NULL != _prVFCMgr->pFrameHeaderParser)            
            {                
#ifdef __VE_H264_DEC_SW_SUPPORT__
                if (MEDIA_CODEC_VID_H264 == _prVFCMgr->eCodecType)
                {
                    if (NULL != prPayload && NULL != prH264Input)
                    {
                        for (u4I = 0; u4I < prH264Input->u4PayloadNumber; u4I++)
                        {
                            rInput.eFlags       = INPUT_FLAG_FRAME_TYPE;
                            rInput.pByteStrm    = (unsigned char*)query_opposite_switchable_cacheaddr_ram((kal_uint32)prPayload[u4I].u4Address);
                            rInput.u4Len        = prPayload[u4I].u4Length;
                            
                            eRet = (VCODEC_DEC_FRAME_HDR_ERROR_T)_prVFCMgr->pFrameHeaderParser((void*)&rInput, (void*)&rOutput);                      

                            if (VCODEC_PIC_UNKNOWN_TYPE != rOutput.eFrameType)
                            {
                                break;
                            }
                        }
                    }          
                }
                else
#endif                    
                {                    
                    rInput.eFlags       = INPUT_FLAG_FRAME_TYPE;
                    rInput.pByteStrm    = pBufferHeader->pu1Buffer;
                    rInput.u4Len        = pBufferHeader->u4BuffSize;
                    
                    eRet = (VCODEC_DEC_FRAME_HDR_ERROR_T)_prVFCMgr->pFrameHeaderParser((void*)&rInput, (void*)&rOutput); 
                }

                VFC_SLIM_LOG2(TRACE_GROUP_5, VFC_HEADER_PARSE, eRet, rOutput.eFrameType);

                switch (rOutput.eFrameType)
                {
                    case VCODEC_PIC_FRAMETYPE_I:
                    case VCODEC_PIC_FRAMETYPE_I_NS:
                    case VCODEC_PIC_FRAMETYPE_I_FC:
                    case VCODEC_PIC_FRAMETYPE_I_ND:            
                    {
                        rInputData.rCurr_Frame_type = SCD_PIC_FRAMETYPE_I;
                    }
                    break;

                    case VCODEC_PIC_FRAMETYPE_P:
                    case VCODEC_PIC_FRAMETYPE_P_ND:
                    {
                        rInputData.rCurr_Frame_type = SCD_PIC_FRAMETYPE_P;
                    }
                    break;

                    case VCODEC_PIC_FRAMETYPE_B:
                    {
                        rInputData.rCurr_Frame_type = SCD_PIC_FRAMETYPE_B;
                    }
                    break;

                    default:
                    {
                        rInputData.rCurr_Frame_type = SCD_PIC_UNKNOWN_TYPE;
                    }
                    break;        
                }                
            }
            else
            {
                // if no proper parser function selected, just trust the flag in buffer header
                
                if (NULL != ((kal_uint32)(pBufferHeader->eFlags) & (kal_uint32)(VIDEO_BUFFERFLAG_SYNCFRAME)))
                {         
                    rInputData.rCurr_Frame_type = SCD_PIC_FRAMETYPE_I;
                }
                else
                {
                    // Todo : seperate P an B frame
                    rInputData.rCurr_Frame_type = SCD_PIC_FRAMETYPE_P;
                }
            }

            // Todo: SCD detection
            // Deliver frame size to detector and update the record

            rInputData.u4Length         = pBufferHeader->u4BuffSize;
            rInputData.pu1ParamStream   = pBufferHeader->pu1Buffer;

            if (KAL_FALSE == _prVFCMgr->fgSCDOpened && 
                _prVFCMgr->rVFCPlaybackInfo.u4ContainerBitRate > 0 && 
                _prVFCMgr->rVFCPlaybackInfo.u4ContainerFrameRate > 0)
            {
                SCD_OPEN_DATA_T rOpenData;
                kal_mem_set(&rOpenData, 0, sizeof(rOpenData));
                
                rOpenData.u4Bitrate     = _prVFCMgr->rVFCPlaybackInfo.u4ContainerBitRate/1000;   // SCD's unit: kbytes
                rOpenData.u4Framerate   = _prVFCMgr->rVFCPlaybackInfo.u4ContainerFrameRate/100;  // SCD's unit: fps
                
                SCD_open(&rOpenData);
                SCD_init(NULL); // Reset SCD
                _prVFCMgr->fgSCDOpened = KAL_TRUE;
            }
            else
            {
                if (KAL_TRUE == _prVFCMgr->fgSCDOpened)
                {        
                    SCD_eng_V1(&rInputData, &rOutputData);

                    VFC_SLIM_LOG4(TRACE_GROUP_5, VFC_SCENE_DETECT_INPUT,  (kal_uint32)pBufferHeader->u8TimeStamp,
                                                                          pBufferHeader->u4BuffSize,
                                                                          pBufferHeader->eFlags,
                                                                          _prVFCMgr->rVFCPlaybackInfo.u8CurrentPlayTime);
                    
                    VFC_SLIM_LOG4(TRACE_GROUP_5, VFC_SCENE_DETECT_RESULT, rInputData.rCurr_Frame_type,
                                                                          rInputData.u4Length,
                                                                          rOutputData.rDetect,
                                                                          rOutputData.rScene);

                    if (DET_YES == rOutputData.rDetect)
                    {
                        rSCDOPData.pSCDRecord = &(_prVFCMgr->rVFCSCDRecord);
                        rSCDOPData.rSCDData.u8TimeStamp = pBufferHeader->u8TimeStamp;                
                        
                        VFC_UpdateSCDInfo(_prVFCMgr, VFC_ADD_SCD_INFO, &rSCDOPData); 
                    }
                }
            }
#endif // __VE_VFC_SCD_SUPPORT__     
        }
            return KAL_TRUE;

        case VFC_OP_VD_CHECK_BITSTREAM_RECEIPT:
        {
#ifdef __VE_FLUENCY_CONTROL_ENABLE__
            VFC_VD_CHECK_BITSTREAM_RECEIPT(_prVFCMgr, pInData, pOutData, pExtra);
            return KAL_TRUE;
#endif              
        }
        break;

        case VFC_OP_VD_UPDATE_DECODER_STAT:
        {
            VFC_VD_UPDATE_DECODER_STAT(_prVFCMgr, pInData, pOutData, pExtra);            
        }
            return KAL_TRUE;

        case VFC_OP_SCH_CHECK_AV_SYNC_STAT:
        {
            VFC_SCH_CHECK_AV_SYNC_STAT(_prVFCMgr, pInData, pOutData, pExtra);            
        }
            return KAL_TRUE;

        case VFC_OP_SCH_UPDATE_AV_SYNC_TIME:
        {
            VFC_CheckSCDStatus(_prVFCMgr, pInData, pOutData, pExtra);
            VFC_SCH_UPDATE_AV_SYNC_TIME(_prVFCMgr, pInData, pOutData, pExtra);            
        }
            return KAL_TRUE;

        case VFC_OP_MPL_NOTIFY_JUMP_I:
        {
            VFC_MPL_NOTIFY_JUMP_I(_prVFCMgr, pInData, pOutData, pExtra);            
        }
            return KAL_TRUE;

        case VFC_OP_MPL_SET_CONTAINER_FRAMERATE:
        {
            VFC_MPL_SET_CONTAINER_FRAMERATE(_prVFCMgr, pInData, pOutData, pExtra);            
        }
        return KAL_TRUE;

        case VFC_OP_MPL_SET_CONTAINER_BITRATE:
        {
            VFC_MPL_SET_CONTAINER_BITRATE(_prVFCMgr, pInData, pOutData, pExtra);            
        }
            return KAL_TRUE;

        case VFC_OP_SCH_CHECK_RCV_FRAME:
        {
            VFC_SCH_CHECK_RCV_FRAME(_prVFCMgr, pInData, pOutData, pExtra);            
        }
        return KAL_TRUE;

        case VFC_OP_SCH_CHECK_DISPLAY_DURATION:
        {
            VFC_SCH_CHECK_DISPLAY_DURATION(_prVFCMgr, pInData, pOutData, pExtra);            
        }
        return KAL_TRUE;

        case VFC_OP_VD_TOTAL_YUV_NUM:
        {
            VFC_VD_NOTIFY_TOTAL_YUV_NUM(_prVFCMgr, pInData, pOutData, pExtra);            
        }
        return KAL_TRUE;

        case VFC_OP_VD_JUMP_PENALTY:
        {
            VFC_VD_NOTIFY_JUMP_PENALTY(_prVFCMgr, pInData, pOutData, pExtra);            
        }
        return KAL_TRUE;

        case VFC_OP_VD_NOT_DISPLAY_DONE_NUM:
        {
            VFC_VD_NOTIFY_NOT_DISPLAY_DONE_NUM(_prVFCMgr, pInData, pOutData, pExtra);            
        }
        return KAL_TRUE;        

        default:
        {
            //drv_trace1(TRACE_GROUP_5, VFC_UNREG_OP_CODE, eOPCode);
        }
        break;        
    }    

    return KAL_FALSE;
  

}

#else // defined(__VE_FLUENCY_CONTROL_ENABLE__) || defined(__VE_VFC_RECOVER_SUPPORT__)

kal_bool VFC_IOCtrl(VIDEO_FLUENCY_OP_CODE_ENUM eOPCode, void* pInData, void* pOutData, void* pExtra)
{
    switch(eOPCode)        
    {
        case VFC_OP_VD_CHECK_IF_TRIGGER_DECODE:
        {
            VFC_OP_DATA_DECODER_INFO_T* pDecoderInfo = (VFC_OP_DATA_DECODER_INFO_T*)pOutData;
            
            pDecoderInfo->fgNeed2TriggerDecode  = KAL_TRUE; // Always decode.
        }
        break; 

        case VFC_OP_SCH_SET_KEY_FRAME_TIME:
        {
            VFC_OP_DATA_JUMP_EVENT_T* pJumpEvent = (VFC_OP_DATA_JUMP_EVENT_T*) pOutData;
            pJumpEvent->fgNeed2Jump = KAL_FALSE;
        }
        break; 

        case VFC_OP_SCH_CHECK_AV_SYNC_STAT:
        {
            VFC_OP_DATA_CHECK_RECOVER_RESULT_T*  pCheckRecoverResult    = (VFC_OP_DATA_CHECK_RECOVER_RESULT_T*)pOutData;
            kal_mem_set(pCheckRecoverResult, 0, sizeof(VFC_OP_DATA_CHECK_RECOVER_RESULT_T));
        }
        break; 

        case VFC_OP_SCH_UPDATE_AV_SYNC_TIME:
        {
            VFC_OP_DATA_JUMP_EVENT_T* pJumpEvent = (VFC_OP_DATA_JUMP_EVENT_T*) pOutData;
            pJumpEvent->fgNeed2Jump = KAL_FALSE;
        }
        break;                 

        default:            
        {           
        }
        break;
    }    

    return KAL_FALSE;
    
}
#endif //defined(__VE_FLUENCY_CONTROL_ENABLE__) || defined(__VE_VFC_RECOVER_SUPPORT__)


#pragma arm section code

#endif // VIDEO_FLUENCY_UTILITY_H
