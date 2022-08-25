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
 *   video_decoder_component_v2.c
 *
 * Project:
 * --------
 *  MTK
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *
 *
 *
 ****************************************************************************/

#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__

#include "drv_comm.h"
#include "kal_release.h"      /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       /* Task message communiction */
#include "video_types_v2.h"
#include "video_comm_component_v2.h"
#include "video_decoder_component_internal_v2.h"
#include "video_comm_v2.h"
#include "vcodec_v2_trc.h"
#include "drv_gfx_stack_switch_manager.h"
#include "cache_sw.h"
#include "video_buffer_management_v2.h"
#include "video_dbg_v2.h"

#include "video_codec_schedule_control.h"
#include "video_codec_type_v2.h"
#include "video_codec_custom_setting_v2.h"
//#include "drv_features.h"
#include "video_codec_if_v2.h"
#include "video_codec_mem_v2.h"
#include "kal_trace.h"
#include "video_codec_buffer_mgr_v2.h"
#include "video_codec_utility_v2.h"
#include "stack_ltlcom.h"
#include "stack_config.h"
#include "video_decoder_il_if_v2.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "hisr_config.h"
#include "video_decoder_isolation_v2.h"

#include "video_fluency_if.h"

#include "lcd_sw_inc.h"


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // 0


#ifdef __VE_DCM_WITH_COMPRESSION__
#include "dcmgr.h" //DCM
#pragma arm section code = "DYNAMIC_CODE_VEDEC_ROCODE", rodata = "DYNAMIC_CODE_VEDEC_RODATA"
#endif  // __VE_DCM_WITH_COMPRESSION__


extern kal_uint32 INT_SwitchStackToRun(void *stack_start, kal_uint32 stack_size, kal_func_ptr func, kal_uint32 argc, ...);


typedef VIDEO_ERROR_TYPE_T (*PFN_VideoDecoderProcessThisBuffer)(VIDEO_BUFFERHEADER_TYPE_T*);


/*****************************************************************************
* Definition of macros
*****************************************************************************/
#define MAX_SLEEP_TICKS     (3)
#define SURPRISE_TIME       35670766


#ifdef VDEC_MEM_DBG
#include "fsal.h"
STFSAL rMDFile[DECODER_MDT_MAX];
VIDEO_DECODER_DEBUG_MODE_T eDebugMode = DECODER_DBM_NONE;
#endif  // VDEC_MEM_DBG


#ifdef __VE_MTK_INTERNAL__
#define __DECODER_MEASURE_SWLA__
#endif  // __VE_MTK_INTERNAL__


/*****************************************************************************
* Global variable(s)
*****************************************************************************/
VIDEO_DECODER_MGR_T *_prVideoDecoderMgr;


/*****************************************************************************
* Context:
*****************************************************************************/
static void _VideoDecoderInitWriteData2File(void)
{
#ifdef VDEC_MEM_DBG
    FSAL_Status FSAL_STATUS;
    if (eDebugMode & DECODER_DBM_INPUT_BITSTREAM != 0)
    {
        kal_wchar store_name[]=L"x:\\input.bin";

        store_name[0] = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
        FSAL_STATUS = FSAL_Open(&rMDFile[DECODER_MDT_INPUT_BITSTREAM], store_name, FSAL_APPEND);
        if (FSAL_STATUS != FSAL_OK)
        {
            ASSERT(0);
        }
    }

    if (eDebugMode & DECODER_DBM_SEND_FRAME != 0)
    {
        kal_wchar store_name[]=L"x:\\send.yuv";

        store_name[0] = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
        FSAL_STATUS = FSAL_Open(&rMDFile[DECODER_MDT_SEND_FRAME], store_name, FSAL_APPEND);
        if (FSAL_STATUS != FSAL_OK)
        {
            ASSERT(0);
        }
    }

    if (eDebugMode & DECODER_DBM_RETURN_FRAME != 0)
    {
        kal_wchar store_name[]=L"x:\\return.yuv";

        store_name[0] = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
        FSAL_STATUS = FSAL_Open(&rMDFile[DECODER_MDT_RETURN_FRAME], store_name, FSAL_APPEND);
        if (FSAL_STATUS != FSAL_OK)
        {
            ASSERT(0);
        }
    }
#endif
}


/*****************************************************************************
* Context:
*****************************************************************************/
static void _VideoDecoderDeInitWriteData2File(void)
{
#ifdef VDEC_MEM_DBG
    if (eDebugMode & DECODER_DBM_INPUT_BITSTREAM != 0)
    {
        FSAL_Close(&rMDFile[DECODER_MDT_INPUT_BITSTREAM]);
    }

    if (eDebugMode & DECODER_DBM_SEND_FRAME != 0)
    {
        FSAL_Close(&rMDFile[DECODER_MDT_SEND_FRAME]);
    }

    if (eDebugMode & DECODER_DBM_RETURN_FRAME != 0)
    {
        FSAL_Close(&rMDFile[DECODER_MDT_RETURN_FRAME]);
    }
#endif
}


#ifdef VDEC_MEM_DBG
/*****************************************************************************
* Context:
*****************************************************************************/
static kal_uint32 _VideoDecoderRunChecksum(kal_uint8 *pu1Addr, kal_uint32 u4Size)
{
    kal_uint32 u4Checksum = 0;
    kal_uint32 u4I;

    for (u4I = 0; u4I < u4Size; u4I++)
    {
        u4Checksum += pu1Addr[u4I];
    }

    return u4Checksum;
}
#endif  // VDEC_MEM_DBG


/*****************************************************************************
* Context:
*****************************************************************************/
static void _VideoDecoderMemDebug(VIDEO_DECODER_MEMORY_DUMP_TYPE_T eMode,
        void *pvAddr, kal_uint32 u4Size)
{
#ifdef VDEC_MEM_DBG
    FSAL_Status rWriteStatus;
    kal_uint32 u4Checksum;

    switch (eMode)
    {
        case DECODER_MDT_INPUT_BITSTREAM:
        {
            VIDEO_BUFFERHEADER_TYPE_T *prBufferHeader = (VIDEO_BUFFERHEADER_TYPE_T*)pvAddr;

            if (0 != prBufferHeader->eFlags & VIDEO_BUFFERFLAG_EOF)
            {
                break;
            }

            // input bitstream memory dump
            if (eDebugMode & DECODER_DBM_INPUT_BITSTREAM != 0)
            {
                rWriteStatus = FSAL_Write(&rMDFile[DECODER_MDT_INPUT_BITSTREAM],
                    (kal_uint8*)prBufferHeader, sizeof(*prBufferHeader));
                if (rWriteStatus != FSAL_OK)
                {
                    ASSERT(0);
                    return;
                }

                if (prBufferHeader->pPrivateData != NULL)
                {
                    switch (_prVideoDecoderMgr->rVDMgrDNZ.eCodec)
                    {
                        case CODEC_H264:
                        {
                            H264_DECODER_INPUT_PARAM_T *prInputParam;
                            H264_DECODER_PAYLOAD_INFO_T *prPayload;

                            prInputParam = (H264_DECODER_INPUT_PARAM_T*)prBufferHeader->pPrivateData;
                            rWriteStatus = FSAL_Write(&rMDFile[DECODER_MDT_INPUT_BITSTREAM],
                                (kal_uint8*)prInputParam, sizeof(*prInputParam));
                            if (rWriteStatus != FSAL_OK)
                            {
                                ASSERT(0);
                                return;
                            }

                            prPayload = prInputParam->pu1PayloadAddress;
                            rWriteStatus = FSAL_Write(&rMDFile[DECODER_MDT_INPUT_BITSTREAM],
                                (kal_uint8*)prPayload, sizeof(*prPayload) * prInputParam->u4PayloadNumber);
                            if (rWriteStatus != FSAL_OK)
                            {
                                ASSERT(0);
                                return;
                            }
                        }
                        break;

                        case CODEC_RV9_10:
                        {
                            RM_DECODER_INPUT_PARAM_T *prInputParam;
                            RM_DECODER_PAYLOAD_INFO_T *prPayload;

                            prInputParam = (RM_DECODER_INPUT_PARAM_T*)prBufferHeader->pPrivateData;
                            rWriteStatus = FSAL_Write(&rMDFile[DECODER_MDT_INPUT_BITSTREAM],
                                (kal_uint8*)prInputParam, sizeof(*prInputParam));
                            if (rWriteStatus != FSAL_OK)
                            {
                                ASSERT(0);
                                return;
                            }

                            prPayload = prInputParam->pu1PayloadAddress;
                            rWriteStatus = FSAL_Write(&rMDFile[DECODER_MDT_INPUT_BITSTREAM],
                                (kal_uint8*)prPayload, sizeof(*prPayload) * prInputParam->u4PayloadNumber);
                            if (rWriteStatus != FSAL_OK)
                            {
                                ASSERT(0);
                                return;
                            }
                        }
                        break;

                        default:
                            ASSERT(0);
                            break;
                    }
                }

                rWriteStatus = FSAL_Write(&rMDFile[DECODER_MDT_INPUT_BITSTREAM],
                    prBufferHeader->pu1Buffer, prBufferHeader->u4BuffSize);
                if (rWriteStatus != FSAL_OK)
                {
                    ASSERT(0);
                    return;
                }
            }

            // input bitsteam checksum
            if (eDebugMode & DECODER_DBM_INPUT_BITSTREAM_CS != 0)
            {
                u4Checksum = _VideoDecoderRunChecksum(prBufferHeader->pu1Buffer, prBufferHeader->u4BuffSize);
                drv_trace4(TRACE_GROUP_10, VDEC_CHECKSUM, DECODER_MDT_INPUT_BITSTREAM, prBufferHeader->u4BuffSize, prBufferHeader->u8TimeStamp, u4Checksum);
            }
        }
        break;

        case DECODER_MDT_SEND_FRAME:
        {
            VIDEO_BUFFERHEADER_TYPE_T *prBufferHeader = (VIDEO_BUFFERHEADER_TYPE_T*)pvAddr;

            if (NULL != ((prBufferHeader->eFlags) & (VIDEO_BUFFERFLAG_EOF)))
            {
                break;
            }

            if (eDebugMode & DECODER_DBM_SEND_FRAME != 0)
            {
                rWriteStatus = FSAL_Write(&rMDFile[DECODER_MDT_SEND_FRAME],
                    prBufferHeader->pu1Buffer, prBufferHeader->u4BuffSize);
                if (rWriteStatus != FSAL_OK)
                {
                    ASSERT(0);
                    return;
                }
            }

            if (eDebugMode & DECODER_DBM_SEND_FRAME_CS != 0)
            {
                u4Checksum = _VideoDecoderRunChecksum(prBufferHeader->pu1Buffer,
                    prBufferHeader->u4BuffSize);
                drv_trace4(TRACE_GROUP_10, VDEC_CHECKSUM, DECODER_MDT_SEND_FRAME,
                    prBufferHeader->u4BuffSize, prBufferHeader->u8TimeStamp, u4Checksum);
            }
        }
        break;

        case DECODER_MDT_RETURN_FRAME:
        {
            VIDEO_BUFFERHEADER_TYPE_T *prBufferHeader = (VIDEO_BUFFERHEADER_TYPE_T*)pvAddr;

            if (NULL != ((prBufferHeader->eFlags) & (VIDEO_BUFFERFLAG_EOF)))
            {
                break;
            }

            if (eDebugMode & DECODER_DBM_RETURN_FRAME != 0)
            {
                rWriteStatus = FSAL_Write(&rMDFile[DECODER_MDT_RETURN_FRAME], prBufferHeader->pu1Buffer, prBufferHeader->u4BuffSize);
                if (rWriteStatus != FSAL_OK)
                {
                    ASSERT(0);
                    return;
                }
            }

            if (eDebugMode & DECODER_DBM_RETURN_FRAME_CS != 0)
            {
                u4Checksum = _VideoDecoderRunChecksum(prBufferHeader->pu1Buffer, prBufferHeader->u4BuffSize);
                drv_trace4(TRACE_GROUP_10, VDEC_CHECKSUM, DECODER_MDT_RETURN_FRAME, prBufferHeader->u4BuffSize, prBufferHeader->u8TimeStamp, u4Checksum);
            }
        }
        break;

        default:
        break;
    }
#endif  // VDEC_MEM_DBG
}


/*****************************************************************************
* Context:
*****************************************************************************/
static void _VideoDecoderCodecMemoryInit(void)
{
    VIDEO_DECODER_MGR_DNZ_T *prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;

    prVDMgrDNZ->rAdmId = kal_adm_create(prVDMgrDNZ->pu1CodecBufferStartAddr,
        prVDMgrDNZ->rCodecMemorySize.u4ExternalSize, NULL, KAL_TRUE);
}


/*****************************************************************************
* Context:
*****************************************************************************/
static void _VideoDecoderCodecMemoryDeInit(void)
{
    VIDEO_DECODER_MGR_DNZ_T *prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;

    if (prVDMgrDNZ->rAdmId != 0)
    {
        kal_adm_delete(prVDMgrDNZ->rAdmId);
        prVDMgrDNZ->rAdmId = 0;
    }
}


/******************************************************************************
* Initialize the queue manager specified by the parameter.  Link each atom in
* the atom pool in series.
*
* Context:
*
* Side effect: data structure pointed to by the input argument
******************************************************************************/
static void _VideoDecoderInitQueueMgr(VIDEO_CORE_RING_BUFFER_MGR_T *prResendQ,
        kal_uint8 *pu1Buffer, kal_uint32 u4Num)
{
    kal_uint32 u4AtomSize = sizeof(VIDEO_BUFFERHEADER_TYPE_T);

    VideoCoreInitRingBuffer(prResendQ, pu1Buffer, u4Num, u4AtomSize);
}


/******************************************************************************
* De-initialize the queue manager specified by the parameter.
*
* Context:
*
* Side effect: data structure pointed to by the input argument
******************************************************************************/
static void _VideoDecoderDeInitQueueMgr(VIDEO_CORE_RING_BUFFER_MGR_T *prResendQ)
{
    VideoCoreDeInitRingBuffer(prResendQ);
}


/******************************************************************************
* Is the queue specified by the parameter is empty?
*
* Context:
*
* Side effect: none
******************************************************************************/
//static __inline kal_bool _VideoDecoderIsResendQEmpty(VIDEO_CORE_RING_BUFFER_MGR_T *prResendQ)
static kal_bool _VideoDecoderIsResendQEmpty(VIDEO_CORE_RING_BUFFER_MGR_T *prResendQ)
{
    return VideoCoreIsRingBufferEmpty(prResendQ);
}


/******************************************************************************
* Is the queue specified by the parameter is full?
*
* Context:
*
* Side effect: none
******************************************************************************/
//static __inline kal_bool _VideoDecoderIsResendQFull(VIDEO_CORE_RING_BUFFER_MGR_T *prResendQ)
static kal_bool _VideoDecoderIsResendQFull(VIDEO_CORE_RING_BUFFER_MGR_T *prResendQ)
{
    return VideoCoreIsRingBufferFull(prResendQ);
}


/******************************************************************************
* Copy the data pointed to by prBuffHeader to the atom at the head of the
* Resend queue.
*
* Context:
*
* Side effect: the queue manager (data pointed to by prResendQ)
******************************************************************************/
static kal_bool _VideoDecoderResendQAdd2Head(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader,
        VIDEO_CORE_RING_BUFFER_MGR_T *prResendQ)
{
    return VideoCoreInsertToTailofRingBuffer(prResendQ, (kal_uint8*)prBuffHeader);
}


/******************************************************************************
* Copy the data pointed to by prBuffHeader to the atom at the tail of the
* Resend queue.
*
* Context:
*
* Side effect: the queue manager (data pointed to by prResendQ)
******************************************************************************/
static kal_bool _VideoDecoderResendQAdd2Tail(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader,
        VIDEO_CORE_RING_BUFFER_MGR_T *prResendQ)
{
    return VideoCoreInsertToHeadofRingBuffer(prResendQ, (kal_uint8*)prBuffHeader);
}


/******************************************************************************
* Copy the data at the head atom of the Resend queue to the address pointed to
* by prBuffHeader.
*
* Context:
*
* Side effect: the queue manager (data pointed to by prResendQ), and *prBuffHeader
******************************************************************************/
static kal_bool _VideoDecoderGetResendBuffer(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader,
        VIDEO_CORE_RING_BUFFER_MGR_T *prResendQ)
{
    return VideoCoreRemoveFromTailofRingBufferAddr(prResendQ, (kal_uint8*)prBuffHeader);
}


#ifndef __VE_ROBUST_FLOW__
/*****************************************************************************
* Context:
*****************************************************************************/
static void _VideoDecoderInitTimeNFrameManager(void)
{
    VIDEO_DECODER_TIME_N_FRAME_BUFFER_ATOM_T *prTimeAndFrameAtom =
        _prVideoDecoderMgr->rVDMgrDNZ.prInfoExtMem->arTimeNFrameBuffer;

    kal_mem_set((void*)prTimeAndFrameAtom, 0,
        sizeof(*prTimeAndFrameAtom) * VIDEO_DECODER_MAX_YUV_BUF_NUM);
}


/*****************************************************************************
* Context:
*****************************************************************************/
static void _VideoDecoderRecordTimeNFrame(kal_uint8 **ppu1FrameAddr, kal_uint64 *pu8TimeStamp)
{
    // Remove RW
    kal_uint32 u4Index = _prVideoDecoderMgr->rVDMgrDZ.u4TimeNFrameIndex;
    kal_uint32 u4Count = 0;
    VIDEO_DECODER_TIME_N_FRAME_BUFFER_ATOM_T *prTimeNFrameBuffer =
        _prVideoDecoderMgr->rVDMgrDNZ.prInfoExtMem->arTimeNFrameBuffer;

    do
    {
        VIDEO_DECODER_TIME_N_FRAME_BUFFER_ATOM_T *prTimeNFrameBufferPos =
            prTimeNFrameBuffer + u4Index;
        if (KAL_FALSE == prTimeNFrameBufferPos->fgUsed)
        {
            prTimeNFrameBufferPos->pu1FrameBufferAddr = *ppu1FrameAddr;
            prTimeNFrameBufferPos->u8TimeStamp        = *pu8TimeStamp;
            prTimeNFrameBufferPos->fgUsed             = KAL_TRUE;
            drv_trace4(TRACE_GROUP_9, VDEC_RECORD_TIME_NFRAME, u4Index,
                (kal_uint32)*ppu1FrameAddr, (kal_uint32)*pu8TimeStamp, 0);
            break;
        }

        u4Index = (u4Index + 1) % VIDEO_DECODER_MAX_YUV_BUF_NUM;
        u4Count++;
    } while (u4Count < VIDEO_DECODER_MAX_YUV_BUF_NUM);

    if (u4Count == VIDEO_DECODER_MAX_YUV_BUF_NUM)
    {
        ASSERT(0);
    }

    _prVideoDecoderMgr->rVDMgrDZ.u4TimeNFrameIndex = u4Index;
}


/*****************************************************************************
* Context:
*****************************************************************************/
static void _VideoDecoderCheckTimeNFrame(kal_uint8 **ppu1FrameAddr, kal_uint64 *pu8TimeStamp)
{
    static kal_uint32 u4Index = 0;
    kal_uint32        u4Count = 0;
    VIDEO_DECODER_TIME_N_FRAME_BUFFER_ATOM_T *prTimeNFrameBuffer =
        _prVideoDecoderMgr->rVDMgrDNZ.prInfoExtMem->arTimeNFrameBuffer;

    do
    {
        VIDEO_DECODER_TIME_N_FRAME_BUFFER_ATOM_T *prTimeNFrameBufferPos =
            prTimeNFrameBuffer + u4Index;

        if ((prTimeNFrameBufferPos->pu1FrameBufferAddr == *ppu1FrameAddr)
            &&(prTimeNFrameBufferPos->u8TimeStamp == *pu8TimeStamp)
            &&(prTimeNFrameBufferPos->fgUsed == KAL_TRUE))
        {
            prTimeNFrameBufferPos->u8TimeStamp = SURPRISE_TIME;
            prTimeNFrameBufferPos->fgUsed = KAL_FALSE;
            drv_trace4(TRACE_GROUP_9, VDEC_CHECK_TIME_NFRAME, u4Index,
                (kal_uint32)*ppu1FrameAddr, (kal_uint32)*pu8TimeStamp, 0);
            break;
        }

        u4Index = (u4Index + 1) % VIDEO_DECODER_MAX_YUV_BUF_NUM;
        u4Count++;
    } while (u4Count < VIDEO_DECODER_MAX_YUV_BUF_NUM);

    if (u4Count == VIDEO_DECODER_MAX_YUV_BUF_NUM)
    {
        ASSERT(0);
    }
}
#endif //#ifndef __VE_ROBUST_FLOW__


/*****************************************************************************
* Context:
*****************************************************************************/
static VIDEO_ERROR_TYPE_T _VideoDecoderManagementInit(void)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    //VIDEO_DECODER_MGR_T *prMgr  = _prVideoDecoderMgr;
    VIDEO_DECODER_MGR_DNZ_T *prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;
    VIDEO_DECODER_MGR_DZ_T *prVDMgrDZ = &_prVideoDecoderMgr->rVDMgrDZ;
    VIDEO_DECODER_INFO_SAVE_EXT_MEM *prInfoExt = prVDMgrDNZ->prInfoExtMem;
    kal_uint8 *pu1GuardPatternAddr;

    kal_mem_set((void*)prVDMgrDZ, 0, sizeof(*prVDMgrDZ));

    prVDMgrDNZ->fgCallbackIL          = KAL_TRUE;
    prVDMgrDNZ->fgUnsupportCallbackIL = KAL_TRUE;
    prVDMgrDNZ->fgRetryCallbackIL     = KAL_TRUE;
    prVDMgrDZ->u4MinLeftSize          = 0xffffffff;

    pu1GuardPatternAddr = prVDMgrDNZ->pu1YUVBufferStartAddr + prVDMgrDNZ->u4YUVBufferTotalSize;

    *(kal_uint32*)pu1GuardPatternAddr = 0x4E534145;  // Be sure to be 4-byte alignment. Otherwise, please fill/check this pattern byte by byte.

    kal_mem_set((void*)(prInfoExt->arUnsentBufferHeader), 0,
        sizeof(prInfoExt->arUnsentBufferHeader));

    kal_mem_set((void*)(&prVDMgrDNZ->rNewestInputBufferHeader), 0,
        sizeof(prVDMgrDNZ->rNewestInputBufferHeader));

    _VideoDecoderInitQueueMgr(&prInfoExt->rInputResendQueueMgr,
        (kal_uint8*)(prInfoExt->arInputResendQueue), VIDEO_DECODER_RESEND_Q_NUM);
    _VideoDecoderInitQueueMgr(&prInfoExt->rOutputResendQueueMgr,
        (kal_uint8*)(prInfoExt->arOutputResendQueue), VIDEO_DECODER_RESEND_Q_NUM);
    //_VideoDecoderCodecMemoryInit();

    // We don't need to set all fgReturned = KAL_FALSE again since VideoCodecInitRingBuffer() sets all field to be 0
    VideoCoreInitRingBuffer(&prInfoExt->rReturningBitstreamBufferMgr,
        (kal_uint8*)(prInfoExt->arReturningBitstream),
        VIDEO_DECODER_RETURN_BS_BUFFER_Q_NUM,  // Leroy: Define a symbol for "sizeof(array)/sizeof(array[0])", and change the number of array entries to that symbol.
        sizeof(prInfoExt->arReturningBitstream[0]));

    VideoDecoderDeInitYUVBuffer(&prVDMgrDNZ->rYUVBufferMgr);

#ifndef __VE_ROBUST_FLOW__
    _VideoDecoderInitTimeNFrameManager();
#endif

    return eError;
}


/*****************************************************************************
* Context:
*****************************************************************************/
static void _VideoDecoderManagementDeInit(void)
{
    //VIDEO_ERROR_TYPE_T eError  = VIDEO_ERROR_NONE;
    //VIDEO_DECODER_MGR_T *prMgr = _prVideoDecoderMgr;
    VIDEO_DECODER_MGR_DNZ_T *prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;
    VIDEO_DECODER_INFO_SAVE_EXT_MEM *prInfoExt = prVDMgrDNZ->prInfoExtMem;
    kal_uint8 *pu1GuardPatternAddr;

    _prVideoDecoderMgr->rVDMgrDZ.pu1LastDisplayYUVAddr = 0;

    pu1GuardPatternAddr = prVDMgrDNZ->pu1YUVBufferStartAddr + prVDMgrDNZ->u4YUVBufferTotalSize;

    if (*(kal_uint32*)pu1GuardPatternAddr != 0x4E534145) // Be sure to be 4-byte alignment. Otherwise, please fill/check this pattern byte by byte.
    {
        drv_trace1(TRACE_GROUP_10, VDEC_YUV_CORRUPTED, (kal_uint32)pu1GuardPatternAddr);
        //Memory corrupted
        ASSERT(0);
    }

    _VideoDecoderDeInitQueueMgr(&prInfoExt->rInputResendQueueMgr);
    _VideoDecoderDeInitQueueMgr(&prInfoExt->rOutputResendQueueMgr);

    //_VideoDecoderCodecMemoryDeInit();

    VideoCoreDeInitRingBuffer(&prInfoExt->rReturningBitstreamBufferMgr);
}


/*****************************************************************************
* Context:
*****************************************************************************/
static void _VideoDecoderSendMessage(kal_uint32 u4Message,
        kal_uint32 u4Param1, kal_uint32 u4Param2)
{
    VIDEO_DECODER_IND_T *prMsg = NULL;
    ilm_struct *prIlm = NULL;
    module_type eActiveModuleId = stack_get_active_module_id();

    prMsg = (VIDEO_DECODER_IND_T*) construct_local_para(sizeof(*prMsg), TD_CTRL);
    prMsg->u4Param1 = u4Param1;
    prMsg->u4Param2 = u4Param2;

    prIlm = allocate_ilm(eActiveModuleId);
    prIlm->src_mod_id = eActiveModuleId;

    prIlm->dest_mod_id = MOD_VCODEC_V2;
    prIlm->sap_id = MED_SAP;

    prIlm->msg_id = (msg_type) u4Message;
    prIlm->local_para_ptr = (local_para_struct*) prMsg;
    prIlm->peer_buff_ptr = NULL;

    msg_send_ext_queue(prIlm);

    drv_trace1(TRACE_GROUP_10, VDEC_SEND_MSG, u4Param1);
}


/*****************************************************************************
* Context:
*****************************************************************************/
static void _VideoDecoderWakeUp(void* pParam)
{
    kal_bool fgSendMsg = KAL_FALSE;

    fgSendMsg = VideoCommSetProcessingNew(&_prVideoDecoderMgr->rVDMgrDNZ.rCommState, KAL_FALSE);
    if (fgSendMsg == KAL_TRUE)
    {
        _VideoDecoderSendMessage(MSG_ID_DECODER_DATA_IND, DECODER_MSG_WAKEUP, 0);
    }
}


/*****************************************************************************
* Context:
*****************************************************************************/
static kal_bool _VideoDecoderStateSetHdlr( kal_uint32 u4Param )
{
    VIDEO_DECODER_CODEC_ERROR_T eRet = VIDEO_DECODER_CODEC_ERROR_NONE;
    kal_bool fgRet = KAL_FALSE;
    //kal_uint32 u4Dummy = 0;
    //VIDEO_DECODER_CODEC_ERROR_T eCodecError = VIDEO_DECODER_CODEC_ERROR_NONE;
    VIDEO_DECODER_MGR_DNZ_T *prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;

    switch(u4Param)
    {
        case VIDEO_STATE_CLOSE:
        {
            VCodecFlushItem(VCS_DECODER);
            fgRet = KAL_TRUE;
        }
        break;

        case VIDEO_STATE_IDLE:
        {
            eRet = prVDMgrDNZ->prCodecAPI->pfnDeInit();
            if (eRet != VIDEO_DECODER_CODEC_ERROR_NONE)
            {
                ASSERT(0);
            }

            VideoCommClrAllQ(&prVDMgrDNZ->rCommState);
            VCodecFlushItem(VCS_DECODER);

            _VideoDecoderManagementDeInit();

            _VideoDecoderManagementInit();

            eRet = prVDMgrDNZ->prCodecAPI->pfnInit();
            if (eRet != VIDEO_DECODER_CODEC_ERROR_NONE)
            {
                ASSERT(0);
            }

            VideoCommChangeState(&prVDMgrDNZ->rCommState, VIDEO_STATE_IDLE);
        }
        break;

        case VIDEO_STATE_INIT:
        {
            //ASSERT(0);
            VideoCommChangeState(&prVDMgrDNZ->rCommState, VIDEO_STATE_INIT);
        }
        break;

        case VIDEO_STATE_RUN:
        {
#ifndef __VE_SLIM_PROJECT__
            // Buffering only takes effect on RMVB.
            // Low cost project would NOT support RMVB so far.
            //eCodecError = _prVideoDecoderMgr->rVDMgrDNZ.prCodecAPI->pfnSetParameter(VIDEO_DECODER_PARAM_BUFFERING, (void*)(&u4Dummy));
            //_prVideoDecoderMgr->rVDMgrDZ.fgBuffering = KAL_TRUE;
            //if (eCodecError != VIDEO_DECODER_CODEC_ERROR_NONE)
            //{
            //    ASSERT(0);
            //}
#endif
            //_prVideoDecoderMgr->rVDMgrDNZ.fgUnsupportCallbackIL = KAL_TRUE;
            if (KAL_TRUE == _prVideoDecoderMgr->rVDMgrDZ.fgCodecNotSupport)
            {
                VIDEO_ERROR_TYPE_T eError;
                eError = prVDMgrDNZ->rCommState.prCallback->pfnEventHandler(VIDEO_EVENT_RESOLUTION_NOT_SUPPORT, VIDEO_COMMAND_NOTIFY, NULL, NULL);
                VE_UNUSED(eError);

                VE_SLIM_LOG1(TRACE_GROUP_10, VDEC_CALLBACK, VIDEO_EVENT_RESOLUTION_NOT_SUPPORT);
            }
            prVDMgrDNZ->fgUnsupportCallbackIL = KAL_TRUE;
            prVDMgrDNZ->fgRetryCallbackIL     = KAL_TRUE;

            VideoCommChangeState(&prVDMgrDNZ->rCommState, VIDEO_STATE_RUN);
        }
        break;

        case VIDEO_STATE_STOP:
            prVDMgrDNZ->fgCallbackIL = KAL_TRUE;
            prVDMgrDNZ->fgUnsupportCallbackIL = KAL_TRUE;
            prVDMgrDNZ->fgRetryCallbackIL = KAL_TRUE;
            VideoCommChangeState(&prVDMgrDNZ->rCommState, VIDEO_STATE_STOP);
            break;

        default:
#ifndef __VE_ROBUST_FLOW__
            ASSERT(0);
#endif
            break;
    }

    return fgRet;
}


/*****************************************************************************
* Context:
*****************************************************************************/
static kal_bool _VideoDecoderSendBufferOut(VIDEO_BUFFERHEADER_TYPE_T* prOutBufferHeader,
                                           kal_bool fgSendOutput,
                                           VIDEO_DECODER_BUFFER_PORT_T eBufferPort)
{
    VIDEO_BUFFERHEADER_TYPE_T rResentBufferHeader;

    PFN_VideoDecoderProcessThisBuffer pfnVDProcessThisBuffer = NULL;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VIDEO_PORT_TYPE_T ePortType = VIDEO_PORT_VIDEO_DATA;
    kal_uint32 u4PortIndex = 0;
    VIDEO_DECODER_MGR_DNZ_T* prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;
    VIDEO_DECODER_MGR_DZ_T* prVDMgrDZ = &_prVideoDecoderMgr->rVDMgrDZ;
    VIDEO_CORE_RING_BUFFER_MGR_T *prQueueMgr = &prVDMgrDNZ->prInfoExtMem->rInputResendQueueMgr; //Simply a initialization, real value would be assigned later
#ifndef __VE_SLIM_PROJECT__
    kal_uint32 u4FunctionStartTime, u4FunctionTime;
#endif
    kal_bool fgRet = KAL_TRUE;
    VIDEO_BUFFERHEADER_TYPE_T rLocalBufferHeader;
    kal_bool fgFail2Send = KAL_FALSE;   // Check if we could continue sending buffer out

    switch(eBufferPort)
    {
        case DECODER_BUFFER_PORT_INPUT:
        {
            prQueueMgr = &prVDMgrDNZ->prInfoExtMem->rInputResendQueueMgr;
            u4PortIndex = VideoCommGetInputPortIndex(&prVDMgrDNZ->rCommState, ePortType);
            pfnVDProcessThisBuffer = VideoCommGetInputProcessBufferFunc(&prVDMgrDNZ->rCommState, u4PortIndex);
        }
        break;

        case DECODER_BUFFER_PORT_OUTPUT:
        {
            prQueueMgr = &prVDMgrDNZ->prInfoExtMem->rOutputResendQueueMgr;
            u4PortIndex = VideoCommGetOutputPortIndex(&prVDMgrDNZ->rCommState, ePortType);
            pfnVDProcessThisBuffer = VideoCommGetOutputProcessBufferFunc(&prVDMgrDNZ->rCommState, u4PortIndex);
        }
        break;

        default:
#ifndef __VE_ROBUST_FLOW__
            ASSERT(0);
#endif
        break;
    }

    while (KAL_TRUE == _VideoDecoderGetResendBuffer(&rResentBufferHeader, prQueueMgr))
    {
        kal_mem_cpy((void*)(&rLocalBufferHeader), (void*)(&rResentBufferHeader), sizeof(rLocalBufferHeader));

#ifndef __VE_SLIM_PROJECT__
        u4FunctionStartTime = video_get_current_time();
#endif

        eError = pfnVDProcessThisBuffer(&rLocalBufferHeader);

#ifndef __VE_SLIM_PROJECT__
        u4FunctionTime = video_get_duration_ms(u4FunctionStartTime);

        switch(eBufferPort)
        {
            case DECODER_BUFFER_PORT_INPUT:
            {
                prVDMgrDZ->u4FileReaderTotalTime += u4FunctionTime;
                prVDMgrDZ->u4FileReaderCounter++;

                drv_trace4(TRACE_GROUP_9, VDEC_SEND_BUFFER_INPUT,
                    (kal_uint32)(rResentBufferHeader.pu1Buffer),
                    (kal_uint32)rResentBufferHeader.u8TimeStamp,
                    VideoCoreRingBufferUsedNum(prQueueMgr),
                    0);


                drv_trace4(TRACE_GROUP_8, VDEC_PROCESS_INPUT_BUFFER_PROFILE,
                    u4FunctionTime,
                    (prVDMgrDZ->u4FileReaderTotalTime/prVDMgrDZ->u4FileReaderCounter),
                    prVDMgrDZ->u4FileReaderCounter,
                    0);
            }
            break;

            case DECODER_BUFFER_PORT_OUTPUT:
            {
                prVDMgrDZ->u4SchedulerTotalTime += u4FunctionTime;
                prVDMgrDZ->u4SchedulerCounter++;

                drv_trace4(TRACE_GROUP_9, VDEC_SEND_BUFFER_OUTPUT,
                    (kal_uint32)(rResentBufferHeader.pu1Buffer),
                    (kal_uint32)rResentBufferHeader.u8TimeStamp,
                    VideoCoreRingBufferUsedNum(prQueueMgr),
                    0);


                drv_trace4(TRACE_GROUP_8, VDEC_PROCESS_OUTPUT_BUFFER_PROFILE,
                    u4FunctionTime,
                    (prVDMgrDZ->u4SchedulerTotalTime/prVDMgrDZ->u4SchedulerCounter),
                    prVDMgrDZ->u4SchedulerCounter,
                    0);
            }
            break;

            default:
#ifndef __VE_ROBUST_FLOW__
                ASSERT(0);
#endif
            break;
        }
#else
        switch(eBufferPort)
        {
            case DECODER_BUFFER_PORT_INPUT:
            {
                drv_trace4(TRACE_GROUP_9, VDEC_SEND_BUFFER_INPUT,
                           (kal_uint32)(rResentBufferHeader.pu1Buffer),
                           (kal_uint32)rResentBufferHeader.u8TimeStamp,
                           VideoCoreRingBufferUsedNum(prQueueMgr),
                           0);
            }
            break;

            case DECODER_BUFFER_PORT_OUTPUT:
            {
                drv_trace4(TRACE_GROUP_9, VDEC_SEND_BUFFER_OUTPUT,
                           (kal_uint32)(rResentBufferHeader.pu1Buffer),
                           (kal_uint32)rResentBufferHeader.u8TimeStamp,
                           VideoCoreRingBufferUsedNum(prQueueMgr),
                           0);
            }
            break;

            default:
#ifndef __VE_ROBUST_FLOW__
                ASSERT(0);
#endif
            break;
        }

#endif

        if (VIDEO_ERROR_BUFF_FULL == eError)
        {
            _VideoDecoderResendQAdd2Head(&rResentBufferHeader, prQueueMgr);

            if (KAL_TRUE == fgSendOutput)
            {
                _VideoDecoderResendQAdd2Tail(prOutBufferHeader, prQueueMgr);
                fgSendOutput = KAL_FALSE;
            }

            drv_trace4(TRACE_GROUP_9, VDEC_SEND_BUFFER_FAIL,
                       (kal_uint32)(rResentBufferHeader.pu1Buffer),
                       rResentBufferHeader.u8TimeStamp,
                       eBufferPort,
                       VideoCoreRingBufferUsedNum(prQueueMgr));

            fgRet = KAL_FALSE;
            fgFail2Send = KAL_TRUE;

            break;
        }
        else
        {
#ifndef __VE_ROBUST_FLOW__
            video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_SEND_BUFFER, (kal_uint32)(rResentBufferHeader.pu1Buffer));
            video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_SEND_TIME, rResentBufferHeader.u8TimeStamp);
#endif

            if (DECODER_BUFFER_PORT_OUTPUT == eBufferPort)
            {
#ifndef __VE_ROBUST_FLOW__
                if ((rResentBufferHeader.eFlags & VIDEO_BUFFERFLAG_EOF) == 0)
                {
                    _VideoDecoderRecordTimeNFrame(&rResentBufferHeader.pu1Buffer, &rResentBufferHeader.u8TimeStamp);
                }
#endif
                _VideoDecoderMemDebug(DECODER_MDT_SEND_FRAME, (void *)&rResentBufferHeader, 0);
            }
        }
    }


    if (KAL_TRUE == fgSendOutput)
    {
        if (KAL_FALSE == fgFail2Send)
        {
            kal_mem_cpy((void*)(&rLocalBufferHeader), (void*)(prOutBufferHeader), sizeof(rLocalBufferHeader));
#ifndef __VE_SLIM_PROJECT__
            u4FunctionStartTime = video_get_current_time();
#endif

            eError = pfnVDProcessThisBuffer(&rLocalBufferHeader);

#ifndef __VE_SLIM_PROJECT__
            u4FunctionTime = video_get_duration_ms(u4FunctionStartTime);

            switch(eBufferPort)
            {
                case DECODER_BUFFER_PORT_INPUT:
                {
                    prVDMgrDZ->u4FileReaderTotalTime += u4FunctionTime;
                    prVDMgrDZ->u4FileReaderCounter++;

                    drv_trace4(TRACE_GROUP_9, VDEC_SEND_BUFFER_INPUT,
                               (kal_uint32)(prOutBufferHeader->pu1Buffer),
                               (kal_uint32)prOutBufferHeader->u8TimeStamp,
                               VideoCoreRingBufferUsedNum(prQueueMgr),
                               1);

                    drv_trace4(TRACE_GROUP_8, VDEC_PROCESS_INPUT_BUFFER_PROFILE,
                               u4FunctionTime,
                               (prVDMgrDZ->u4FileReaderTotalTime/prVDMgrDZ->u4FileReaderCounter),
                               prVDMgrDZ->u4FileReaderCounter,
                               1);
                }
                break;

                case DECODER_BUFFER_PORT_OUTPUT:
                {
                    prVDMgrDZ->u4SchedulerTotalTime += u4FunctionTime;
                    prVDMgrDZ->u4SchedulerCounter++;

                    drv_trace4(TRACE_GROUP_9, VDEC_SEND_BUFFER_OUTPUT,
                               (kal_uint32)(prOutBufferHeader->pu1Buffer),
                               (kal_uint32)prOutBufferHeader->u8TimeStamp,
                               VideoCoreRingBufferUsedNum(prQueueMgr),
                               1);

                    drv_trace4(TRACE_GROUP_8, VDEC_PROCESS_OUTPUT_BUFFER_PROFILE,
                               u4FunctionTime,
                               (prVDMgrDZ->u4SchedulerTotalTime/prVDMgrDZ->u4SchedulerCounter),
                               prVDMgrDZ->u4SchedulerCounter,
                               1);
                }
                break;

                default:
#ifndef __VE_ROBUST_FLOW__
                    ASSERT(0);
#endif
                break;
            }
#else
            switch(eBufferPort)
            {
                case DECODER_BUFFER_PORT_INPUT:
                {
                    drv_trace4(TRACE_GROUP_9, VDEC_SEND_BUFFER_INPUT,
                               (kal_uint32)(prOutBufferHeader->pu1Buffer),
                               (kal_uint32)prOutBufferHeader->u8TimeStamp,
                               0,
                               1);
                }
                break;

                case DECODER_BUFFER_PORT_OUTPUT:
                {
                    drv_trace4(TRACE_GROUP_9, VDEC_SEND_BUFFER_OUTPUT,
                               (kal_uint32)(prOutBufferHeader->pu1Buffer),
                               (kal_uint32)prOutBufferHeader->u8TimeStamp,
                               0,
                               1);
                }
                break;

                default:
#ifndef __VE_ROBUST_FLOW__
                    ASSERT(0);
#endif
                break;
            }

#endif

            if (VIDEO_ERROR_BUFF_FULL == eError)
            {
                _VideoDecoderResendQAdd2Tail(prOutBufferHeader, prQueueMgr);

                VE_SLIM_LOG4(TRACE_GROUP_9, VDEC_SEND_BUFFER_FAIL,
                             (kal_uint32)(prOutBufferHeader->pu1Buffer),
                             (kal_uint32)prOutBufferHeader->u8TimeStamp,
                             eBufferPort,
                             VideoCoreRingBufferUsedNum(prQueueMgr));

                fgRet = KAL_FALSE;
                fgFail2Send = KAL_TRUE;
            }
            else
            {
#ifndef __VE_ROBUST_FLOW__
                video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_SEND_BUFFER, (kal_uint32)(prOutBufferHeader->pu1Buffer));
                video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_SEND_TIME, prOutBufferHeader->u8TimeStamp);
#endif

                if (DECODER_BUFFER_PORT_OUTPUT == eBufferPort)
                {
#ifndef __VE_ROBUST_FLOW__
                    if ((prOutBufferHeader->eFlags & VIDEO_BUFFERFLAG_EOF) == 0)
                    {
                        _VideoDecoderRecordTimeNFrame(&prOutBufferHeader->pu1Buffer, &prOutBufferHeader->u8TimeStamp);
                    }
#endif
                    _VideoDecoderMemDebug(DECODER_MDT_SEND_FRAME, (void *)prOutBufferHeader, 0);
                }
            }
        }
        else
        {
            ASSERT(0);
        }
    }

    // deal with the bitstream which codec returned
    if (eBufferPort == DECODER_BUFFER_PORT_INPUT)
    {
        VIDEO_DECODER_BS_BUFFER_ATOM_T* prBSAtom = NULL;
        kal_bool fgSendAnotherBS = KAL_TRUE;

        do{
            prBSAtom = (VIDEO_DECODER_BS_BUFFER_ATOM_T*)VideoCoreGetTailofRingBufferAddr(&prVDMgrDNZ->prInfoExtMem->rReturningBitstreamBufferMgr);

            if (KAL_TRUE == prBSAtom->fgReturned)
            {
                prBSAtom->fgReturned = KAL_FALSE;

                if (KAL_FALSE == fgFail2Send)
                {
#ifndef __VE_SLIM_PROJECT__
                    u4FunctionStartTime = video_get_current_time();
#endif
                    eError = pfnVDProcessThisBuffer(&prBSAtom->rBufferHeader);

#ifndef __VE_SLIM_PROJECT__
                    u4FunctionTime = video_get_duration_ms(u4FunctionStartTime);

                    prVDMgrDZ->u4FileReaderTotalTime += u4FunctionTime;
                    prVDMgrDZ->u4FileReaderCounter++;

                    drv_trace4(TRACE_GROUP_9, VDEC_SEND_BUFFER_INPUT,
                               (kal_uint32)(prBSAtom->rBufferHeader.pu1Buffer),
                               (kal_uint32)prBSAtom->rBufferHeader.u8TimeStamp,
                               VideoCoreRingBufferUsedNum(prQueueMgr),
                               2);

                    drv_trace4(TRACE_GROUP_8, VDEC_PROCESS_INPUT_BUFFER_PROFILE,
                               u4FunctionTime,
                               (prVDMgrDZ->u4FileReaderTotalTime/prVDMgrDZ->u4FileReaderCounter),
                               prVDMgrDZ->u4FileReaderCounter,
                               2);
#else
                    drv_trace4(TRACE_GROUP_9, VDEC_SEND_BUFFER_INPUT,
                              (kal_uint32)(prBSAtom->rBufferHeader.pu1Buffer),
                              (kal_uint32)prBSAtom->rBufferHeader.u8TimeStamp,
                              0,
                              2);
                    VE_UNUSED(prVDMgrDZ);
#endif

                    if (VIDEO_ERROR_BUFF_FULL == eError)
                    {
                        _VideoDecoderResendQAdd2Tail(&prBSAtom->rBufferHeader, prQueueMgr);
                        fgRet = KAL_FALSE;
                        fgFail2Send = KAL_TRUE;
                    }
#ifndef __VE_ROBUST_FLOW__
                    else
                    {
                        video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_SEND_BUFFER, (kal_uint32)(prBSAtom->rBufferHeader.pu1Buffer));
                        video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_SEND_TIME, prBSAtom->rBufferHeader.u8TimeStamp);
                    }
#endif
                }
                else
                {
                    _VideoDecoderResendQAdd2Tail(&prBSAtom->rBufferHeader, prQueueMgr);

                    fgRet = KAL_FALSE;
                }
                kal_mem_set((void*)(prBSAtom), 0, sizeof(*prBSAtom));
                VideoCoreConsumeTailofRingBuffer(&prVDMgrDNZ->prInfoExtMem->rReturningBitstreamBufferMgr);
            }
            else
            {
                fgSendAnotherBS = KAL_FALSE;
            }
        } while(KAL_TRUE == fgSendAnotherBS);
    }

    return fgRet;
}


/*****************************************************************************
* Context:
*****************************************************************************/
static kal_bool _VideoDecoderPopOutputBuff(VIDEO_DECODER_MGR_T *prDecoderMGR,
                                           VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader,
                                           VIDEO_DECODER_ACTION_T *peAction,
                                           kal_bool *pfgCheckFlag)
{
    VIDEO_COMM_STATE_T * prCommState = &prDecoderMGR->rVDMgrDNZ.rCommState;

    if (VideoCommPopOutputBuff(prCommState, prBuffHeader))
    {
        *peAction = DECODER_ACTION_OUTPUT_BUFFER;
        *pfgCheckFlag = KAL_TRUE;
        prDecoderMGR->rVDMgrDZ.u4ItemsInOutputQ--;
        return KAL_TRUE;
    }
    else
    {
        *peAction = DECODER_ACTION_NONE;
        *pfgCheckFlag = KAL_FALSE;
        return KAL_FALSE;
    }
}


/*****************************************************************************
* Context:
*****************************************************************************/
static kal_bool _VideoDecoderCheckBuffer(void)
{
    if (_prVideoDecoderMgr->rVDMgrDZ.fgInitBuffer == KAL_TRUE)
    {
#ifdef __VE_KMV_SUPPORT__
        if (_prVideoDecoderMgr->rVDMgrDNZ.eScenario == VIDEO_SCENARIO_KMV)
        {
            return (VideoDecoderGetAvailableYUVNumber(&_prVideoDecoderMgr->rVDMgrDNZ.rYUVBufferMgr) > 1)? KAL_TRUE : KAL_FALSE;
        }
        else
        {
            return VideoDecoderCheckAvailability(&_prVideoDecoderMgr->rVDMgrDNZ.rYUVBufferMgr);
        }
#else   
        // return kal_true if there's still buffer available
        return VideoDecoderCheckAvailability(&_prVideoDecoderMgr->rVDMgrDNZ.rYUVBufferMgr);
#endif
    }
    else
    {
        // buffer has not yet initialized, no need to check
        // assert fail would occur if anyone try to get buffer before initializing buffer
        // retun KAL_TRUE since codec would not need YUV buffer when decoding header
        return KAL_TRUE;
    }
}


/*****************************************************************************
* Context:
*****************************************************************************/
static void _VideoDecoderUpdateYUVInfoToCCU(void)
{
    // Notify CCU about the current display number
    VIDEO_DECODER_MGR_DNZ_T* const prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;
    VIDEO_PORT_TYPE_T ePortType = VIDEO_PORT_VIDEO_DATA;
    kal_uint32 u4PortIndex;
    kal_uint32 u4ReturnedYUVNum;
    VFC_OP_DATA_YUV_INFO rDisplayYUVInfo;

    u4PortIndex = VideoCommGetOutputPortIndex(&prVDMgrDNZ->rCommState, ePortType);
    u4ReturnedYUVNum = VideoCommGetOutputBuffQUsedNum(&prVDMgrDNZ->rCommState, u4PortIndex);

    rDisplayYUVInfo.u4CodecDisplayNum      = VideoDecoderGetAvailableDisplayNumber(&prVDMgrDNZ->rYUVBufferMgr);
    rDisplayYUVInfo.u4SchedulerReturnedNum = u4ReturnedYUVNum;
    VFC_IOCtrl(VFC_OP_VD_NOT_DISPLAY_DONE_NUM, (void*)&rDisplayYUVInfo, NULL, NULL);
}


/*****************************************************************************
* Context:
*****************************************************************************/
static void _VideoDecoderFillRendererData(VIDEO_DECODER_PRIVATE_OUTPUT_T* prPrivateOutput,
                                          VA2_VIDEO_FRAME_T*              prUnsentPrivateData,
                                          VIDEO_BUFFERHEADER_TYPE_T*      prOutBufferHeader)
{
    VA2_CLIP_WINDOW_T* pWindownInfo         = &(prUnsentPrivateData->r_clip_window);
    VA2_FRAME_SIZE_T* pFrameSize            = &(prUnsentPrivateData->r_fb_size);
    VA2_FRAME_BUFFER_ADDRESS_T* pFbAddr     = &(prUnsentPrivateData->r_fb_addr);
    VA2_FRAME_ASPECT_RATIO_T* pFrameAspectRatio = &(prUnsentPrivateData->r_frame_aspect_ratio);
#ifdef __VE_KMV_SUPPORT__
    KMV_Class* pKMVObj = &(_prVideoDecoderMgr->rVDMgrDNZ.rKMVObj);
#endif

    pWindownInfo->b_clip_enable     = KAL_TRUE;
    pWindownInfo->u4_clip_left      = prPrivateOutput->u2ClipLeft;
    pWindownInfo->u4_clip_top       = prPrivateOutput->u2ClipTop;
    pWindownInfo->u4_clip_right     = prPrivateOutput->u2ClipRight;
    pWindownInfo->u4_clip_bottom    = prPrivateOutput->u2ClipBottom;

#ifdef __VE_KMV_SUPPORT__

    // We are in speed_mode, resolution will be 240x180
    if (pKMVObj->fg_kmv_inited == KAL_TRUE && 
        pKMVObj->kmv_speed_mode && 
        _prVideoDecoderMgr->rVDMgrDNZ.eCodec == CODEC_H264)
    {
        //pWindownInfo->u4_clip_right     = 239;
        //pWindownInfo->u4_clip_bottom    = 179;

        pWindownInfo->u4_clip_left      = pKMVObj->i4dPelx;
        pWindownInfo->u4_clip_top       = pKMVObj->i4dPely;
        pWindownInfo->u4_clip_right     = 239+pKMVObj->i4dPelx;
        pWindownInfo->u4_clip_bottom    = 179+pKMVObj->i4dPely;
        
    }
#endif

    pFrameSize->u4_height   = prPrivateOutput->u2FrameHeight;
    pFrameSize->u4_width    = prPrivateOutput->u2FrameWidth;

    if (prPrivateOutput->fgYUVSeperated == KAL_FALSE)
    {
        kal_uint8* pu1TempBuffer = prOutBufferHeader->pu1Buffer;

        pFbAddr->u4_fb_addr_plane0 = (kal_uint32)(pu1TempBuffer);
        pu1TempBuffer += prPrivateOutput->u2FrameWidth*prPrivateOutput->u2FrameHeight;

        pFbAddr->u4_fb_addr_plane1 = (kal_uint32)(pu1TempBuffer);
        pu1TempBuffer += (prPrivateOutput->u2FrameWidth>>1)*(prPrivateOutput->u2FrameHeight>>1);

        pFbAddr->u4_fb_addr_plane2 = (kal_uint32)(pu1TempBuffer);
    }
    else
    {
        pFbAddr->u4_fb_addr_plane0 = (kal_uint32)(prPrivateOutput->pu1YStartAddr);
        pFbAddr->u4_fb_addr_plane1 = (kal_uint32)(prPrivateOutput->pu1UStartAddr);
        pFbAddr->u4_fb_addr_plane2 = (kal_uint32)(prPrivateOutput->pu1VStartAddr);
    }

    pFrameAspectRatio->i4AspectRatioWidth   = prPrivateOutput->i4AspectRatioWidth;
    pFrameAspectRatio->i4AspectRatioHeight  = prPrivateOutput->i4AspectRatioHeight;

    //prUnsentPrivateData->r_dithering_info.u1TotalBufNs = _prVideoDecoderMgr->rVDMgrDNZ.rYUVBufferMgr.u4TotalNum;
    prUnsentPrivateData->eFrameColorFmt = VIDEO_RENDERER_COLOR_YUV420;

    VE_SLIM_LOG4(TRACE_GROUP_8, VDEC_DISPLAY_ATTR,
               pFrameSize->u4_width,
               pFrameSize->u4_width,
               pWindownInfo->u4_clip_right,
               pWindownInfo->u4_clip_bottom);
}


#ifdef __VE_KMV_SUPPORT__

void VideoDecoderKMVDeInit(KMV_Class* kmv_obj)
{
    // Release resource
    _VideoFreeEventGroup(EVG_USER_DECODER, kmv_obj->eEvent);
    
    kal_mem_set(kmv_obj, 0, sizeof(*kmv_obj));
}

kal_int32 VideoDecoderKMVInit(uint8_t *kmv_type, int speed_mode)
{
    kal_int32   u4need_rec_buffer   = 1;
    KMV_Class*  pkmv_obj            = &(_prVideoDecoderMgr->rVDMgrDNZ.rKMVObj);
    uint32_t    u4KMVType           = (uint32_t)(*kmv_type);

    if (KAL_TRUE == pkmv_obj->fg_kmv_inited)
    {
        return 0;
    }
    
    pkmv_obj->outframebuf = 0;

    pkmv_obj->kmv_speed_mode = speed_mode;//KAL_TRUE;

    if(pkmv_obj->kmv_speed_mode)
    {
        u4need_rec_buffer = 0;
    }
    else
    {
        u4need_rec_buffer = !KMV_IsM4vfmt(u4KMVType);
    }

    if (NULL == pkmv_obj->g_pMapBuf)
    {
        pkmv_obj->g_pMapBuf = (uint8_t *)VideoGetExtBuffer((VIDEO_EXTMEM_HANDLER_T*)_prVideoDecoderMgr->rVDMgrDNZ.rMemHdler.prExtMemHdr, KMV_MAX_MB_LEN + GUARD_PATTERN_LENGTH);
    
        if (pkmv_obj->g_pMapBuf == NULL)
        {
            ASSERT(0);
            goto KMV_INIT_FAILED;    
        }
    }

    if (NULL == pkmv_obj->pu8kmv_scaleup_buffer)
    {
        pkmv_obj->pu8kmv_scaleup_buffer = (char*)VideoGetExtBuffer((VIDEO_EXTMEM_HANDLER_T*)_prVideoDecoderMgr->rVDMgrDNZ.rMemHdler.prExtMemHdr, KMV_SW_SCALER_UP_BUFFER + GUARD_PATTERN_LENGTH);

        if (pkmv_obj->pu8kmv_scaleup_buffer == NULL)
        {
            ASSERT(0);
            goto KMV_INIT_FAILED;
        }
    }

    pkmv_obj->eEvent = _VideoGetEventGroup(EVG_USER_DECODER);

    pkmv_obj->fg_kmv_inited = KAL_TRUE;
    pkmv_obj->kmv_drpnum = KMV_DROP_REC;

    return 0;
    
KMV_INIT_FAILED:

    pkmv_obj->fg_kmv_inited = KAL_FALSE;

    return -1;
        
}



static void VideoDecoderFillKMVFrameBufferData(KMV_frame_buffer_ext* pFrameBuf, kmv_meta_st* pKMVMetaData, VIDEO_DECODER_PRIVATE_OUTPUT_T* prPrivateOutput, kal_uint8* pSrcYUVAddr)
{
    // Copy the KMV meta and prepare for post-processing @ _VideoDecoderGetDisplay2Send()    

    if (_prVideoDecoderMgr->rVDMgrDNZ.eScenario != VIDEO_SCENARIO_PREVIEW_KMV)
    {
        _prVideoDecoderMgr->rVDMgrDNZ.rKMVObj.outframebuf = (void*)VideoDecoderGetYUVBuffer();
        VideoDecoderRefFreeYUVBuffer((kal_uint8*)_prVideoDecoderMgr->rVDMgrDNZ.rKMVObj.outframebuf);
    }
    else
    {
        // If we're in preview scenario, just proceed 'In-Place' post-processing. 
        // Because there is only one available frame buffer.
        _prVideoDecoderMgr->rVDMgrDNZ.rKMVObj.outframebuf = (void*)pSrcYUVAddr;
    }

    if (1 == _prVideoDecoderMgr->rVDMgrDNZ.rKMVObj.kmv_speed_mode)
    // Copy frame for later post-process
    {
#ifdef __VE_KMV_PROFILE_ENABLE__        

        if (_prVideoDecoderMgr->rVDMgrDNZ.eScenario != VIDEO_SCENARIO_PREVIEW_KMV)
        {
            kal_uint32 u4CopyFrmStartTime = 0;
            kal_uint32 u4CopyFrmTime = 0;

            u4CopyFrmStartTime = video_get_current_time();
            VIDEO_START_LOGGING("CPF");
        
            kal_mem_cpy(_prVideoDecoderMgr->rVDMgrDNZ.rKMVObj.outframebuf, pSrcYUVAddr, (prPrivateOutput->u2FrameWidth*prPrivateOutput->u2FrameHeight*3)>>1);

            VIDEO_STOP_LOGGING("CPF");
            u4CopyFrmTime = video_get_duration_ms(u4CopyFrmStartTime);

            _prVideoDecoderMgr->rVDMgrDNZ.u4CopyFrmTotalTime += u4CopyFrmTime;
            _prVideoDecoderMgr->rVDMgrDNZ.u4CopyFrmCounter++;

            drv_trace4(TRACE_GROUP_10, VDEC_CPF_PROFILE, u4CopyFrmTime, (((kal_uint64)_prVideoDecoderMgr->rVDMgrDNZ.u4CopyFrmTotalTime) * 1000 / _prVideoDecoderMgr->rVDMgrDNZ.u4CopyFrmCounter), _prVideoDecoderMgr->rVDMgrDNZ.u4CopyFrmCounter, 0);
        }
#else
        if (_prVideoDecoderMgr->rVDMgrDNZ.eScenario != VIDEO_SCENARIO_PREVIEW_KMV)
        {
            kal_mem_cpy(_prVideoDecoderMgr->rVDMgrDNZ.rKMVObj.outframebuf, pSrcYUVAddr, (prPrivateOutput->u2FrameWidth*prPrivateOutput->u2FrameHeight*3)>>1);
        }
#endif
    }


    kal_mem_cpy((void*)pFrameBuf->kmv_metabuf->kmvMeta, (void*)pKMVMetaData->kmvMeta, pKMVMetaData->nsize);
    pFrameBuf->kmv_metabuf->nsize   = (kal_uint16)pKMVMetaData->nsize;

    // Todo get the real width/height
    pFrameBuf->kmv_metabuf->recH    = pKMVMetaData->recH; //180;   
    pFrameBuf->kmv_metabuf->recW    = pKMVMetaData->recW; //240;

    pFrameBuf->kmv_metabuf->tType   = pKMVMetaData->tType;

    pFrameBuf->width                = prPrivateOutput->u2FrameWidth;//320;
    pFrameBuf->height               = prPrivateOutput->u2FrameHeight;//240;
   
    *pFrameBuf->stride_y            = pFrameBuf->width;
    *pFrameBuf->stride_uv           = (pFrameBuf->width)>>1;


    if (prPrivateOutput->fgYUVSeperated == KAL_FALSE)
    {   
        // HW case
        // Todo : This path should NOT happenneed to verify this path
        ASSERT(0);
    }
    else
    {        
        if (_prVideoDecoderMgr->rVDMgrDNZ.rKMVObj.kmv_speed_mode && _prVideoDecoderMgr->rVDMgrDNZ.eCodec == CODEC_H264)
        {
            // speed mode
            
            prPrivateOutput->pu1YStartAddr = (kal_uint8*)_prVideoDecoderMgr->rVDMgrDNZ.rKMVObj.outframebuf;
            prPrivateOutput->pu1UStartAddr = (kal_uint8*)(prPrivateOutput->pu1YStartAddr + pFrameBuf->width*pFrameBuf->height);
            prPrivateOutput->pu1VStartAddr = (kal_uint8*)(prPrivateOutput->pu1UStartAddr + ((pFrameBuf->width)*(pFrameBuf->height)>>2));
            
        }
                
        pFrameBuf->src_y  = &(prPrivateOutput->pu1YStartAddr);
        pFrameBuf->src_u  = &(prPrivateOutput->pu1UStartAddr);
        pFrameBuf->src_v  = &(prPrivateOutput->pu1VStartAddr);  
    }           
}
#endif

/*****************************************************************************
* Context:
*****************************************************************************/
static VIDEO_DECODER_CODEC_ERROR_T _VideoDecoderGetDisplay2Send(kal_bool* pfgSendOutputBufferResult)
{
    VIDEO_DECODER_PRIVATE_OUTPUT_T rPrivateOutput;
    VIDEO_DECODER_CODEC_ERROR_T eCodecError = VIDEO_DECODER_CODEC_ERROR_NONE;
    VIDEO_BUFFERHEADER_TYPE_T rOutBufferHeader;
    kal_uint8 u1ArrayIdx = VIDEO_DECODER_MAX_YUV_BUF_NUM;
    kal_uint32 u4OutputPortIndex = 0;
    VIDEO_PORT_TYPE_T ePortType = VIDEO_PORT_VIDEO_DATA;

    VIDEO_DECODER_MGR_DZ_T*  prVDMgrDZ  = &_prVideoDecoderMgr->rVDMgrDZ;
    VIDEO_DECODER_MGR_DNZ_T* prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;

    VIDEO_DECODER_INFO_SAVE_EXT_MEM* pInfoExtMem = prVDMgrDNZ->prInfoExtMem;

    kal_mem_set((void*)&rPrivateOutput, 0, sizeof(rPrivateOutput));

    // Init aspect ratio. If no new aspect ratio was returned from codec, we'll use 1:1
    rPrivateOutput.i4AspectRatioWidth  = 1;
    rPrivateOutput.i4AspectRatioHeight = 1;

    do
    {
        kal_uint8* pu1Buffer = NULL;
        VA2_VIDEO_FRAME_T* prUnsentPrivateData = NULL;

        rPrivateOutput.fgUpdateTime      = KAL_FALSE;
        rPrivateOutput.fgYUVSeperated    = KAL_FALSE;
        rPrivateOutput.fgRepeatLastFrame = KAL_FALSE;
        rPrivateOutput.fgEOF             = KAL_FALSE;

        if (_VideoDecoderIsResendQFull(&pInfoExtMem->rOutputResendQueueMgr) )
        {
            prVDMgrDZ->fgDisplay2Send = KAL_TRUE;
            *pfgSendOutputBufferResult = KAL_FALSE;

            drv_trace1(TRACE_GROUP_9, VDEC_D2S_QUIT, 0);

            break;
        }

        eCodecError = prVDMgrDNZ->prCodecAPI->pfnGetNextDisplay(&pu1Buffer, &rPrivateOutput);

        if (rPrivateOutput.fgEOF == KAL_TRUE)
        {
            VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
            VIDEO_BUFFERHEADER_TYPE_T* pNewestInputBufferHeader = &prVDMgrDNZ->rNewestInputBufferHeader;

            u4OutputPortIndex = VideoCommGetOutputPortIndex(&prVDMgrDNZ->rCommState, ePortType);

            rOutBufferHeader.u4InputPort  = VideoCommGetOutputComp(&prVDMgrDNZ->rCommState, u4OutputPortIndex)->u4PortIndex;
            rOutBufferHeader.u4OutputPort = u4OutputPortIndex;
            rOutBufferHeader.pu1Buffer    = NULL;
            rOutBufferHeader.u4BuffSize   = 0;

            if ((pNewestInputBufferHeader->eFlags & VIDEO_BUFFERFLAG_EOF) == 0)
            {
                ASSERT(0);
            }

            rOutBufferHeader.eFlags      = pNewestInputBufferHeader->eFlags;
            rOutBufferHeader.u8TimeStamp = pNewestInputBufferHeader->u8TimeStamp;

            // This callback is to acknowledge the completion of VIDEO_PARAM_FLUSH_FRM
            // in SetParam() in which VIDEO_ERROR_ASYNC_OPERATION is returned indicating
            // that caller needs to wait for notification.
            eError = prVDMgrDNZ->rCommState.prCallback->pfnEventHandler(VIDEO_EVENT_COMPLETE, VIDEO_COMMAND_NOTIFY, NULL, NULL);
            VE_UNUSED(eError);

            drv_trace1(TRACE_GROUP_10, VDEC_CALLBACK, VIDEO_EVENT_COMPLETE);
        }
        else
        {
            kal_bool fgNeed2Display = KAL_TRUE;
            VIDEO_BUFFERHEADER_TYPE_T *pUnsentBufferHeader = pInfoExtMem->arUnsentBufferHeader;
#ifdef __VE_KMV_SUPPORT__
            kmv_meta_st *pUnsentKMVMetaData = pInfoExtMem->arKMVMetaData;
#endif

#ifndef __VE_ROBUST_FLOW__
            if ( eCodecError != VIDEO_DECODER_CODEC_ERROR_NONE)
            {
                ASSERT(0);
            }
#endif

            if (pu1Buffer == NULL)
            {
                prVDMgrDZ->fgDisplay2Send = KAL_FALSE;
                drv_trace1(TRACE_GROUP_9, VDEC_D2S_QUIT, 1);
                break;
            }
            prVDMgrDZ->u4FramesCodecDisplay++;

            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif

            if (KAL_TRUE == fgNeed2Display)
            {
                u4OutputPortIndex = VideoCommGetOutputPortIndex(&prVDMgrDNZ->rCommState, ePortType);

                rOutBufferHeader.u4InputPort  = VideoCommGetOutputComp(&prVDMgrDNZ->rCommState, u4OutputPortIndex)->u4PortIndex;
                rOutBufferHeader.u4OutputPort = u4OutputPortIndex;

                u1ArrayIdx = VideoDecoderGetYUVBufferIdx(pu1Buffer, &prVDMgrDNZ->rYUVBufferMgr);

                {
                    // This operation actually not that necessary...
                    //kal_mem_cpy((void*)(&rOutBufferHeader), (void*)(&_prVideoDecoderMgr->arUnsentBufferHeader[u1ArrayIdx]), sizeof(rOutBufferHeader));
                    rOutBufferHeader.u8TimeStamp = (pUnsentBufferHeader + u1ArrayIdx)->u8TimeStamp;
                    rOutBufferHeader.eFlags      = (pUnsentBufferHeader + u1ArrayIdx)->eFlags;
                }

                rOutBufferHeader.u4BuffSize = rPrivateOutput.u2FrameHeight * rPrivateOutput.u2FrameWidth * 3 / 2;//_prVideoDecoderMgr->u4BufferSize;

                if (rPrivateOutput.fgNotDisplay == KAL_TRUE) // For VP8
                {
                    VideoDecYUVBufDisFree(pu1Buffer, &prVDMgrDNZ->rYUVBufferMgr);
                    drv_trace1(TRACE_GROUP_9, VDEC_FREE_NOT_DISPLAY_FRAME, (kal_uint32)(pu1Buffer));
                    continue;
                }
                else if (((prVDMgrDNZ->eScenario == VIDEO_SCENARIO_PREVIEW)||(prVDMgrDNZ->eScenario == VIDEO_SCENARIO_PREVIEW_KMV)) &&
                    rPrivateOutput.fgRepeatLastFrame == KAL_TRUE &&
                    prVDMgrDZ->pu1LastDisplayYUVAddr == NULL)
                {
                    // This block of code is for CR [MAUI_03196809].
                    VideoDecYUVBufDisFree(pu1Buffer, &prVDMgrDNZ->rYUVBufferMgr);
                    drv_trace1(TRACE_GROUP_9, VDEC_FREE_NOT_DISPLAY_FRAME, (kal_uint32)pu1Buffer);
                    continue;
                }
                else if (rPrivateOutput.fgRepeatLastFrame == KAL_FALSE || prVDMgrDZ->pu1LastDisplayYUVAddr == NULL)
                {
                    rOutBufferHeader.pu1Buffer = pu1Buffer;
                    
#ifdef __VE_KMV_SUPPORT__

                    // For KMV playback, release the frame buffer from Codec and deliver the one after post-processing to Scheduler instead.

                    {

                        kal_uint64 u8NeedToPPTime = (prVDMgrDNZ->u8StartTime > KMV_EARLY_RECON_TIME)? prVDMgrDNZ->u8StartTime - KMV_EARLY_RECON_TIME : 0;
                        

                        if (prVDMgrDNZ->rKMVObj.fg_kmv_inited == KAL_TRUE && prVDMgrDNZ->eCodec == CODEC_H264 && rOutBufferHeader.u8TimeStamp >= u8NeedToPPTime)
                        {
                            int i4Ret = -1;
                            uint32_t u4NeedRecBuffer = 0;
                            
                            kmv_meta_st* pKMVData = (kmv_meta_st*)((pUnsentKMVMetaData + u1ArrayIdx));

                            if (pKMVData->nsize > 0)
                            {
                                kal_uint32 u4PPStartTime = 0;
                                kal_uint32 u4PPTime = 0;
                                prVDMgrDNZ->rKMVFrameBuffer.kmv_metabuf = &prVDMgrDNZ->rKMVMetaBuf;
                                
                                VideoDecoderFillKMVFrameBufferData(&prVDMgrDNZ->rKMVFrameBuffer, (kmv_meta_st*)(pKMVData), &rPrivateOutput, pu1Buffer);

#ifdef __VE_KMV_PROFILE_ENABLE__
                                u4PPStartTime = video_get_current_time();
                                VIDEO_START_LOGGING("KMV");
                                                        
                                i4Ret = kmv_recon_frame2(&prVDMgrDNZ->rKMVFrameBuffer, &prVDMgrDNZ->rKMVObj, pKMVData->tType, &u4NeedRecBuffer);

                                VIDEO_STOP_LOGGING("KMV");
                                u4PPTime = video_get_duration_ms(u4PPStartTime);

                                prVDMgrDNZ->u4PPTotalTime += u4PPTime;
                                prVDMgrDNZ->u4PPCounter++;

                                drv_trace4(TRACE_GROUP_10, VDEC_PP_PROFILE, u4PPTime, (((kal_uint64)prVDMgrDNZ->u4PPTotalTime) * 1000 / prVDMgrDNZ->u4PPCounter), prVDMgrDNZ->u4PPCounter, 0);
#else

                               i4Ret = kmv_recon_frame2(&prVDMgrDNZ->rKMVFrameBuffer, &prVDMgrDNZ->rKMVObj, pKMVData->tType, &u4NeedRecBuffer);

#endif

                                if (i4Ret < 0)
                                {
                                    drv_trace1(TRACE_GROUP_10, VDEC_RECONSTRUCT_FAIL, (kal_uint32)rOutBufferHeader.u8TimeStamp);
                                }
                            
                                VideoDecYUVBufDisFree(pu1Buffer, &prVDMgrDNZ->rYUVBufferMgr);

                                // Todo: the new buffer should the reconstructed one. NOT pu1Buffer
                                rOutBufferHeader.pu1Buffer = prVDMgrDNZ->rKMVObj.outframebuf;//pu1Buffer;
                            }
                            else
                            {
                                // Todo: add a error handle...
                                //ASSERT(0);
                            }
                            //drv_trace1(TRACE_GROUP_9, VDEC_FREE_NOT_DISPLAY_FRAME, (kal_uint32)pu1Buffer);
                        }                 
                    }
#endif                    
                    
                    // fill private data
                    prUnsentPrivateData = &pInfoExtMem->arUnsentPrivateData[u1ArrayIdx];
                    rOutBufferHeader.pPrivateData = (void*)prUnsentPrivateData;
                    _VideoDecoderFillRendererData(&rPrivateOutput, prUnsentPrivateData, &rOutBufferHeader);
                }
                else
                {
                    drv_trace1(TRACE_GROUP_9, VDEC_FREE_FRAME_DIS, (kal_uint32)(pu1Buffer));

                    VideoDecYUVBufDisFree(pu1Buffer, &prVDMgrDNZ->rYUVBufferMgr);
                    VideoDecYUVBufAddDisplayCount(prVDMgrDZ->pu1LastDisplayYUVAddr, &prVDMgrDNZ->rYUVBufferMgr);

                    rOutBufferHeader.pu1Buffer      = prVDMgrDZ->pu1LastDisplayYUVAddr;
                    rOutBufferHeader.pPrivateData   = (void*)prVDMgrDZ->parLastUnsentPrivateData;
                }

                prVDMgrDZ->pu1LastDisplayYUVAddr = rOutBufferHeader.pu1Buffer;
                prVDMgrDZ->parLastUnsentPrivateData = (VA2_VIDEO_FRAME_T*)rOutBufferHeader.pPrivateData;

                if (rPrivateOutput.fgUpdateTime == KAL_TRUE)
                {
                    // Temporarily modified for RM decoder, other codec seems no need to change timestamp
                    rOutBufferHeader.u8TimeStamp = rPrivateOutput.u8TimeStamp;
                    (pUnsentBufferHeader+u1ArrayIdx)->u8TimeStamp = rPrivateOutput.u8TimeStamp;
                }
                //make sure record the timestamp after it is updated
                prVDMgrDZ->u8TimeStampOfLastDecodedFrm = rOutBufferHeader.u8TimeStamp;
            }
            else
            {
                // CCU hopes Decoder NOT to deliver decoded frames to Scheduler

                drv_trace1(TRACE_GROUP_9, VDEC_FREE_FRAME_DIS, (kal_uint32)(pu1Buffer));
                VideoDecYUVBufDisFree(pu1Buffer, &prVDMgrDNZ->rYUVBufferMgr);

                continue;
            }
        }

        drv_trace8(TRACE_GROUP_10, VDEC_D2S,
                   rPrivateOutput.eFrameType,
                   rPrivateOutput.fgRepeatLastFrame,
                   rPrivateOutput.fgEOF,
                   rPrivateOutput.fgYUVSeperated,
                   rPrivateOutput.u2FrameWidth,
                   rPrivateOutput.u2FrameHeight,
                   rOutBufferHeader.u8TimeStamp,
                   (kal_uint32)rOutBufferHeader.pu1Buffer);

        *pfgSendOutputBufferResult = _VideoDecoderSendBufferOut(&rOutBufferHeader, KAL_TRUE, DECODER_BUFFER_PORT_OUTPUT);

        // CCU related
        // Notify CCU about the possible Jump penalty
        if (prVDMgrDZ->u4FramesCodecDisplay == 1)
        {
            VFC_IOCtrl(VFC_OP_VD_JUMP_PENALTY, (void*)&prVDMgrDZ->u4FramesCodecGet, NULL, NULL);
        }
    } while(1);

    return eCodecError;
}


/*****************************************************************************
* Context:
*****************************************************************************/
static void _VideoDecoderPopInputBuff(VIDEO_DECODER_MGR_T *prDecoderMGR,
                                      VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader,
                                      VIDEO_DECODER_ACTION_T *peAction,
                                      kal_bool *pfgCheckFlag)
{
    VIDEO_DECODER_MGR_DNZ_T* prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;
    VIDEO_DECODER_MGR_DZ_T* prVDMgrDZ = &_prVideoDecoderMgr->rVDMgrDZ;
    VIDEO_COMM_STATE_T * prCommState = &prVDMgrDNZ->rCommState;
    VCODEC_SCHEDULE_TASKQUEUE_T rGotTaskControl = VCS_TASKQUEUE_MAX;

    VIDEO_CORE_RING_BUFFER_MGR_T *pInputResendQueueMgr         = &prVDMgrDNZ->prInfoExtMem->rInputResendQueueMgr;
    VIDEO_CORE_RING_BUFFER_MGR_T *pReturningBitstreamBufferMgr = &prVDMgrDNZ->prInfoExtMem->rReturningBitstreamBufferMgr;
    VIDEO_CORE_RING_BUFFER_MGR_T *pOutputResendQueueMgr        = &prVDMgrDNZ->prInfoExtMem->rOutputResendQueueMgr;


    // if the difference is only one, scheduler should soon or later activate recover
    // we check codec black hole here
    if (((prVDMgrDZ->u4FramesCodecDisplay - prVDMgrDZ->u4FramesSchedulerReturn) == 1)
        && (prVDMgrDNZ->eScenario != VIDEO_SCENARIO_PREVIEW && prVDMgrDNZ->eScenario !=VIDEO_SCENARIO_PREVIEW_KMV))
    {
        // Enter _VideoDecoderPopInputBuff implies ouput queue is empty
        // and if we see there's no available buffer at this moment, codec must have them all
        //prDecoderMGR->rVDMgrDNZ.rYUVBufferMgr.u4VideoDecoderBufferAvailable == 0)
        if (_VideoDecoderCheckBuffer() == KAL_FALSE)
        {
            // Please check :
            // 1. prDecoderMGR->rVDMgrDNZ.rYUVBufferMgr.u4VideoDecoderBufferRefBitMap
            // 2. prDecoderMGR->rVDMgrDNZ.rYUVBufferMgr.u4VideoDecoderBufferDisplayBitMap
            // to check who occupies all buffers
            ASSERT(0);
        }
    }

    if (prVDMgrDZ->fgIsFlushCodecSyncFrm == KAL_TRUE)
    {
#ifndef __VE_SLIM_PROJECT__
        kal_uint32 u4FlushTime, u4FinTime;
#endif
        kal_uint32 u4DummyParam;
        kal_bool fgSendOutputBufferResult = KAL_TRUE;

#ifndef __VE_SLIM_PROJECT__
        u4FlushTime = video_get_current_time();
#endif
        prVDMgrDNZ->prCodecAPI->pfnSetParameter(VIDEO_DECODER_PARAM_FLUSH_BUFFER, (void*)(&u4DummyParam));

#ifndef __VE_SLIM_PROJECT__
        u4FinTime = video_get_duration_ms(u4FlushTime);
        drv_trace1(TRACE_GROUP_10, VDEC_CODEC_FLUSH, u4FinTime);
#endif

        _VideoDecoderGetDisplay2Send(&fgSendOutputBufferResult);
        prVDMgrDZ->fgIsFlushCodecSyncFrm = KAL_FALSE;
    }

    if (prVDMgrDZ->eFlushAllNonSyncFrmState != DECODER_FLUSH_STATE_NONE)
    {
        drv_trace4(TRACE_GROUP_10, VDEC_FLUSH_STATUS,
                   VideoCommQueryInputBuff(prCommState),
                   _VideoDecoderIsResendQEmpty(pInputResendQueueMgr),
                   VideoCoreIsRingBufferEmpty(pReturningBitstreamBufferMgr),
                   0);

        if ((VideoCommQueryInputBuff(prCommState) == 0) &&
            _VideoDecoderIsResendQEmpty(pInputResendQueueMgr) &&
            VideoCoreIsRingBufferEmpty(pReturningBitstreamBufferMgr))
        {
            VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
            prVDMgrDZ->eFlushAllNonSyncFrmState = DECODER_FLUSH_STATE_NONE;
            drv_trace1(TRACE_GROUP_10, VDEC_CALLBACK, VIDEO_EVENT_FLUSH_DONE);

            eError = prCommState->prCallback->pfnEventHandler(VIDEO_EVENT_FLUSH_DONE, VIDEO_COMMAND_NOTIFY, NULL, NULL);
            VE_UNUSED(eError);

            //prDecoderMGR->fgWaitInputBuffering = KAL_TRUE;
            //_prVideoDecoderMgr->rVDMgrDZ.eFlushAllNonSyncFrmState = DECODER_FLUSH_STATE_NONE;
        }
    }

    if (!_VideoDecoderCheckBuffer())
    {
        // YUV buffer full
        if (prVDMgrDNZ->fgCallbackIL == KAL_TRUE)
        {
            kal_uint32 u4Dummy = 0;
            VIDEO_DECODER_CODEC_ERROR_T eCodecError = VIDEO_DECODER_CODEC_ERROR_NONE;

            eCodecError = prVDMgrDNZ->prCodecAPI->pfnSetParameter(VIDEO_DECODER_PARAM_NOT_BUFFERING, (void*)(&u4Dummy));
            if (eCodecError != VIDEO_DECODER_CODEC_ERROR_NONE)
            {
                ASSERT(0);
            }
#ifndef __VE_SLIM_PROJECT__
            prVDMgrDZ->fgBuffering = KAL_FALSE;
#endif
            prVDMgrDNZ->fgCallbackIL = KAL_FALSE;
        }
#ifndef __VE_SLIM_PROJECT__
        prVDMgrDZ->fgWaitBuffer = KAL_TRUE;
#endif
        *peAction = DECODER_ACTION_NONE;
        drv_trace0(TRACE_GROUP_10, VDEC_YUV_BUFFER_FULL);

        //<preview_1_frame>
        // Under preview scenario, there should be EOF right after 1st frame received.
        if (prVDMgrDNZ->eScenario == VIDEO_SCENARIO_PREVIEW ||prVDMgrDNZ->eScenario == VIDEO_SCENARIO_PREVIEW_KMV)
        {
            if (VideoCommGetInputBuffData(prCommState, prBuffHeader) && prVDMgrDZ->fgBitstreamQFull == KAL_FALSE)
            {
                if (0 == ((kal_uint32)(prBuffHeader->eFlags) & (kal_uint32)(VIDEO_BUFFERFLAG_EOF)))
                {
                    // More than one frame delivered to codec before EOF
                    drv_trace0(TRACE_GROUP_10, VDEC_NO_EOF_AFTER_FIRST_FRAME);
#ifndef __VE_ROBUST_FLOW__
                    ASSERT(0);
#endif
                }
                else
                {
                    // Preview scenario
                    *peAction = DECODER_ACTION_INPUT_BUFFER;
                    *pfgCheckFlag = KAL_TRUE;
                    // To notify CCU about the lastest frame time for Jump-to-I
                    VFC_IOCtrl(VFC_OP_VD_LASTEST_FRAME_TIME, prBuffHeader, NULL, NULL);
                }
            }
        }

        return;
    }
    else
    {
#ifndef __VE_SLIM_PROJECT__
        prVDMgrDZ->fgWaitBuffer = KAL_FALSE;
#endif
        if (_VideoDecoderIsResendQFull(pOutputResendQueueMgr) ||
            prVDMgrDZ->fgDisplay2Send == KAL_TRUE)
        {
            *peAction = DECODER_ACTION_OUTPUT_RESENT_FULL;
            *pfgCheckFlag = KAL_FALSE;

            VE_SLIM_LOG0(TRACE_GROUP_10, VDEC_OUTPUT_RESENT_FULL);

            return;
        }

        if (_VideoDecoderIsResendQFull(pInputResendQueueMgr))
        {
            *peAction = DECODER_ACTION_INPUT_RESENT_FULL;
            *pfgCheckFlag = KAL_FALSE;

            VE_SLIM_LOG0(TRACE_GROUP_10, VDEC_INPUT_RESENT_FULL);

            return;
        }

        if (VideoCoreIsRingBufferFull(pReturningBitstreamBufferMgr))
        {
            *peAction = DECODER_ACTION_INPUT_RESENT_FULL;
            *pfgCheckFlag = KAL_FALSE;
            VE_SLIM_LOG0(TRACE_GROUP_10, VDEC_RETURN_BS_FULL);
            return;
        }

        rGotTaskControl = VCodecCtrlGetTaskControl(VCS_DECODER);
        if (VCS_TASKQUEUE_EXPECTED_TARGET == rGotTaskControl)
        {
            if (VideoCommGetInputBuffData(prCommState, prBuffHeader) &&
                prVDMgrDZ->fgBitstreamQFull == KAL_FALSE)
            {
                *peAction = DECODER_ACTION_INPUT_BUFFER;
                *pfgCheckFlag = KAL_TRUE;

                // To notify CCU about the lastest frame time for Jump-to-I
                // For display order != decode corder, we need to check the order of timestamp
                if (prVDMgrDZ->u8Last2CodecFrameTime < prBuffHeader->u8TimeStamp)
                {
                    VFC_IOCtrl(VFC_OP_VD_LASTEST_FRAME_TIME, prBuffHeader, NULL, NULL);
                    prVDMgrDZ->u8Last2CodecFrameTime = prBuffHeader->u8TimeStamp;
                }
            }
            else if (!_VideoDecoderIsResendQEmpty(pOutputResendQueueMgr))
            {
                *peAction = DECODER_ACTION_OUTPUT_RESENT_FULL;
                *pfgCheckFlag = KAL_FALSE;
            }
            else if (!_VideoDecoderIsResendQEmpty(pInputResendQueueMgr))
            {
                *peAction = DECODER_ACTION_INPUT_RESENT_FULL;
                *pfgCheckFlag = KAL_FALSE;
            }
            else
            {
                *peAction = DECODER_ACTION_NONE;
                *pfgCheckFlag = KAL_FALSE;
            }
        }
        else
        {
            void* pDummy = NULL;

            if (!_VideoDecoderIsResendQEmpty(pOutputResendQueueMgr))
            {
                *peAction = DECODER_ACTION_OUTPUT_RESENT_FULL;
                *pfgCheckFlag = KAL_FALSE;
            }
            else if (!_VideoDecoderIsResendQEmpty(pInputResendQueueMgr))
            {
                *peAction = DECODER_ACTION_INPUT_RESENT_FULL;
                *pfgCheckFlag = KAL_FALSE;
            }
            else
            {
                *peAction = DECODER_ACTION_NONE;
                *pfgCheckFlag = KAL_FALSE;
                if (VCS_TASKQUEUE_NOT_EXPECTED_TARGET == rGotTaskControl)
                {
                    _VideoDecoderWakeUp(pDummy);
                }
            }
        }
    }
}


#if defined(__VE_SLIM_PROJECT__)
/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoDecoderWaitInputDataLog(VIDEO_DECODER_ACTION_T eAction)
{
    /* empty */
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
static void _VideoDecoderWaitOutputDataLog(VIDEO_DECODER_ACTION_T eAction)
{
    /* empty */
}


/******************************************************************************
* u1Mark can be 'I' or 'O' representing Input and Output respectively.
*
* Context:
*
* Side effect:
******************************************************************************/
__inline static void _VDEC_LogWaterMark(kal_char u1Mark, kal_uint32 u4Items)
{
    /* empty */
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
__inline static void _VDEC_CalculateStatistics(void)
{
    /* empty */
}


#else


/*****************************************************************************
* Context:
*****************************************************************************/
static void _VideoDecoderWaitInputDataLog(VIDEO_DECODER_ACTION_T eAction)
{
    VIDEO_DECODER_MGR_DNZ_T* prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;
    VIDEO_DECODER_MGR_DZ_T* prVDMgrDZ = &_prVideoDecoderMgr->rVDMgrDZ;

    if (prVDMgrDZ->fgWaitInputLogging == KAL_TRUE)
    {
        if (prVDMgrDZ->u4ItemsInInputQ != 0 ||
            eAction == DECODER_ACTION_INPUT_BUFFER ||
            VideoCommGetState(&prVDMgrDNZ->rCommState) != VIDEO_STATE_RUN ||
            prVDMgrDZ->fgBuffering == KAL_TRUE)
        {
            kal_uint32 u4WaitTotoalTime;
            VIDEO_STATE_TYPE_T eState;

            u4WaitTotoalTime = video_get_duration_ms(prVDMgrDNZ->u4WaitInputStartTime);
            eState = VideoCommGetState(&prVDMgrDNZ->rCommState);

            //if (_prVideoDecoderMgr->fgWaitInputBuffering == KAL_FALSE)
            {
                drv_trace4(TRACE_GROUP_8, VDEC_WAIT_INPUT,
                    u4WaitTotoalTime, prVDMgrDNZ->u4CoverWaitTime, eState, 0);
            }
            prVDMgrDNZ->u4CoverWaitTime = 0;
            prVDMgrDNZ->u4WaitInputStartTime  = 0;
            //_prVideoDecoderMgr->fgWaitInputBuffering = KAL_FALSE;
            prVDMgrDZ->fgWaitInputLogging = KAL_FALSE;

            VIDEO_STOP_LOGGING("WI");
        }
    }
    else
    {
        if (prVDMgrDZ->u4ItemsInInputQ == 0 && eAction == DECODER_ACTION_NONE &&
            VideoCommGetState(&prVDMgrDNZ->rCommState) == VIDEO_STATE_RUN &&
            prVDMgrDZ->fgBuffering == KAL_FALSE)
        {
            kal_uint32 i, u4Temp, u4MinTime;
            VIDEO_YUV_BUFFER_T *prBufferMgr;

            prBufferMgr = &prVDMgrDNZ->rYUVBufferMgr;

            // obtian min. display time
            u4MinTime = 0xffffffff;
            for (i = 0; i < prBufferMgr->u4TotalNum; i++)
            {
                kal_uint32 u4BitMask = (0x1 << i);
                if (!(u4BitMask & prBufferMgr->u4VideoDecoderBufferDisplayBitMap))
                {
                    u4Temp = (kal_uint32)(prVDMgrDNZ->prInfoExtMem->arUnsentBufferHeader[i].u8TimeStamp / 1000);
                    if (u4Temp < u4MinTime)
                    {
                        u4MinTime = u4Temp;
                    }
                }
            }

            u4Temp =  (kal_uint32) (prVDMgrDZ->u8TimeStampOfLastDecodedFrm/1000);
            if (u4MinTime == 0xffffffff || u4Temp < u4MinTime)
            {
                prVDMgrDNZ->u4CoverWaitTime = 0;
            }
            else
            {
                prVDMgrDNZ->u4CoverWaitTime = u4Temp - u4MinTime;
            }
            prVDMgrDNZ->u4WaitInputStartTime = video_get_current_time();
            prVDMgrDZ->fgWaitInputLogging = KAL_TRUE;

            VIDEO_START_LOGGING("WI");
        }
    }
}


/*****************************************************************************
* Context:
*****************************************************************************/
static void _VideoDecoderWaitOutputDataLog(VIDEO_DECODER_ACTION_T eAction)
{
    VIDEO_DECODER_MGR_DNZ_T* prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;
    VIDEO_DECODER_MGR_DZ_T* prVDMgrDZ = &_prVideoDecoderMgr->rVDMgrDZ;

    if (prVDMgrDZ->fgWaitOutputQLogging == KAL_TRUE)
    {
        if (prVDMgrDZ->u4AvailableYUVNumber != 0 ||
            eAction == DECODER_ACTION_OUTPUT_BUFFER ||
            VideoCommGetState(&prVDMgrDNZ->rCommState) != VIDEO_STATE_RUN ||
            prVDMgrDZ->fgBuffering == KAL_TRUE)
        {
            kal_uint32 u4WaitTotoalTime;
            u4WaitTotoalTime = video_get_duration_ms(prVDMgrDNZ->u4WaitOutputStartTime);

            //if (_prVideoDecoderMgr->fgWaitOutputBuffering == KAL_FALSE)
            {
                prVDMgrDZ->u4WaitOutputTotalTime += u4WaitTotoalTime;
                prVDMgrDZ->u4WaitOutputCounter++;

                if (u4WaitTotoalTime > prVDMgrDZ->u4WaitOutputMaxTime)
                {
                    prVDMgrDZ->u4WaitOutputMaxTime = u4WaitTotoalTime;
                }

                drv_trace4(TRACE_GROUP_8, VDEC_WAIT_OUTPUT,
                           u4WaitTotoalTime,
                           (prVDMgrDZ->u4WaitOutputTotalTime/prVDMgrDZ->u4WaitOutputCounter),
                           prVDMgrDZ->u4WaitOutputCounter,
                           prVDMgrDZ->u4WaitOutputMaxTime);
            }

            prVDMgrDNZ->u4WaitOutputStartTime  = 0;
            //_prVideoDecoderMgr->fgWaitOutputBuffering = KAL_FALSE;
            prVDMgrDZ->fgWaitOutputQLogging = KAL_FALSE;

            VIDEO_STOP_LOGGING("WO");
        }
    }
    else
    {
        if (prVDMgrDZ->u4AvailableYUVNumber == 0 &&
            eAction == DECODER_ACTION_NONE &&
            VideoCommGetState(&prVDMgrDNZ->rCommState) == VIDEO_STATE_RUN &&
            prVDMgrDZ->fgBuffering == KAL_FALSE)
        {
            prVDMgrDNZ->u4WaitOutputStartTime = video_get_current_time();
            prVDMgrDZ->fgWaitOutputQLogging = KAL_TRUE;

            VIDEO_START_LOGGING("WO");
        }
    }
}


/******************************************************************************
* u1Mark can be 'I' or 'O' representing Input and Output respectively.
*
* Context:
*
* Side effect:
******************************************************************************/
__inline static void _VDEC_LogWaterMark(kal_char u1Mark, kal_uint32 u4Items)
{
    kal_char au1WaterMark[] = "DX_";

    au1WaterMark[1] = u1Mark;

    if (u4Items < 10)
    {
        au1WaterMark[2] = (kal_char)u4Items + '0';
    }
    else
    {
        au1WaterMark[2] = (kal_char)(u4Items - 10) + 'A';
    }

    VIDEO_LABEL_LOGGING(au1WaterMark);
}


/******************************************************************************
*
* Context:
*
* Side effect:
******************************************************************************/
__inline static void _VDEC_CalculateStatistics(void)
{
    VIDEO_DECODER_MGR_DZ_T* const prVDMgrDZ = &_prVideoDecoderMgr->rVDMgrDZ;

    if (_VideoDecoderCheckBuffer())
    {
        // There is at least one YUV buffer.
        if (prVDMgrDZ->u4ItemsInInputQ == 0)
        {
            prVDMgrDZ->u4IdleDueToNoBitstream++;
        }
    }
    else
    {
        // There is no YUV buffer.
        if (prVDMgrDZ->u4ItemsInInputQ != 0)
        {
            prVDMgrDZ->u4IdleDueToNoYUVBuffer++;
        }
    }
}
#endif  // defined(__VE_SLIM_PROJECT__)


/*****************************************************************************
* Context:
*****************************************************************************/
static void _VideoDecoderDataHdlr(ilm_struct *prIlm)
{
    VIDEO_BUFFERHEADER_TYPE_T rBufferHeader;
    VIDEO_BUFFERHEADER_TYPE_T rOutBufferHeader;
    VIDEO_BUFFERFLAG_TYPE_T eFlag;
    VIDEO_DECODER_ACTION_T eAction;
    VIDEO_COMMAND_TYPE_T eType;
    kal_uint32 u4Param;
    VIDEO_DECODER_MGR_DNZ_T* prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;
    VIDEO_DECODER_MGR_DZ_T* prVDMgrDZ = &_prVideoDecoderMgr->rVDMgrDZ;

    if (prVDMgrDNZ->fgStartWakeUpTimer == KAL_TRUE)
    {
        kal_cancel_timer(prVDMgrDNZ->rTimerID);
        prVDMgrDNZ->fgStartWakeUpTimer = KAL_FALSE;
    }

    VideoCommClrProcessing(&prVDMgrDNZ->rCommState);

    do {
        // Decision of Action
        kal_bool fgCheckFlag = KAL_FALSE;
        kal_bool fgSendInputBufferResult = KAL_TRUE;
        kal_bool fgSendOutputBufferResult = KAL_TRUE;

        kal_mem_set((void*)&rBufferHeader, 0, sizeof(VIDEO_BUFFERHEADER_TYPE_T));
        kal_mem_set((void*)&rOutBufferHeader, 0, sizeof(VIDEO_BUFFERHEADER_TYPE_T));
        eAction = DECODER_ACTION_NONE;
        eFlag = VIDEO_BUFFERFLAG_MAX;
        eType = VIDEO_COMMAND_MAX;

        if (VideoCommPopCommand(&prVDMgrDNZ->rCommState, &eType, &u4Param))
        {
            eAction = DECODER_ACTION_COMMAND;
        }
        else
        {
            if (VideoCommGetState(&prVDMgrDNZ->rCommState) == VIDEO_STATE_RUN)
            {
                if (!_VideoDecoderPopOutputBuff(_prVideoDecoderMgr,
                                                &rBufferHeader,
                                                &eAction,
                                                &fgCheckFlag))
                {
                    _VideoDecoderPopInputBuff(_prVideoDecoderMgr,
                                              &rBufferHeader,
                                              &eAction,
                                              &fgCheckFlag);
                }
            }
        }

        _VDEC_LogWaterMark('I', prVDMgrDZ->u4ItemsInInputQ);

        prVDMgrDZ->u4AvailableYUVNumber = VideoDecoderGetAvailableYUVNumber(&prVDMgrDNZ->rYUVBufferMgr);
        _VDEC_LogWaterMark('O', prVDMgrDZ->u4AvailableYUVNumber);

        _VideoDecoderWaitInputDataLog(eAction);
        _VideoDecoderWaitOutputDataLog(eAction);

        if (eAction == DECODER_ACTION_NONE)
        {
            VIDEO_DECODER_CODEC_ERROR_T eCodecError = VIDEO_DECODER_CODEC_ERROR_NONE;
            kal_int32 i4RemainDecodingItem = 0;

            i4RemainDecodingItem = VCodecCtrlGetContinuousItemNum(VCS_DECODER);

            for (; i4RemainDecodingItem > 0; i4RemainDecodingItem--)
            {
                VCodecCtrlMoveItem(VCS_DECODER);
            }

            _VDEC_CalculateStatistics();

            if (VideoCommGetState(&prVDMgrDNZ->rCommState) == VIDEO_STATE_RUN)
            {
                // Before breaking main loop, make sure input/output sent all buffers out
                eCodecError = _VideoDecoderGetDisplay2Send(&fgSendOutputBufferResult);
#ifndef __VE_ROBUST_FLOW__
                if ( eCodecError != VIDEO_DECODER_CODEC_ERROR_NONE)
                {
                    ASSERT(0);
                }
#else
                VE_UNUSED(eCodecError);
#endif
                fgSendInputBufferResult = _VideoDecoderSendBufferOut(&rBufferHeader, KAL_FALSE, DECODER_BUFFER_PORT_INPUT);
            }

            VE_SLIM_LOG4(TRACE_GROUP_8, VDEC_NO_ACTION,
                         prVDMgrDZ->u4IdleDueToNoBitstream,
                         prVDMgrDZ->u4IdleDueToNoYUVBuffer,
                         prVDMgrDZ->fgClosingDecoder,
                         0);


            drv_trace8(TRACE_GROUP_10, VDEC_STATUS,
                       prVDMgrDZ->u4ItemsInInputQ, prVDMgrDZ->u4ItemsInOutputQ,
                       VideoCoreRingBufferUsedNum(&prVDMgrDNZ->prInfoExtMem->rInputResendQueueMgr), VideoCoreRingBufferUsedNum(&prVDMgrDNZ->prInfoExtMem->rOutputResendQueueMgr),
                       prVDMgrDNZ->rYUVBufferMgr.u4VideoDecoderBufferRefBitMap, prVDMgrDNZ->rYUVBufferMgr.u4VideoDecoderBufferDisplayBitMap,
                       prVDMgrDZ->u4FramesCodecDisplay, prVDMgrDZ->u4FramesSchedulerReturn);

            break;
        }

        if (fgCheckFlag == KAL_TRUE)
        {
            eFlag = rBufferHeader.eFlags;
        }

        switch (eAction)
        {
            case DECODER_ACTION_COMMAND:
            {
                drv_trace2(TRACE_GROUP_10, VDEC_PROCESS_COMMAND, u4Param, eType);

                if (eType != VIDEO_COMMAND_STATESET)
                {
                    // VIDEO_COMMAND_NOTIFY would also be asserted
                    ASSERT(0);
                }

                prVDMgrDZ->fgClosingDecoder = _VideoDecoderStateSetHdlr(u4Param);
            }
            break;

            case DECODER_ACTION_OUTPUT_BUFFER:
            {
                _VideoDecoderMemDebug(DECODER_MDT_RETURN_FRAME, (void *)&rBufferHeader, 0);

                drv_trace2(TRACE_GROUP_10, VDEC_PROCESS_OUTPUT, (kal_uint32)(rBufferHeader.pu1Buffer), rBufferHeader.u8TimeStamp);

                VE_SLIM_LOG1(TRACE_GROUP_8, VDEC_FREE_FRAME_DIS, (kal_uint32)(rBufferHeader.pu1Buffer));

#ifndef __VE_ROBUST_FLOW__
                _VideoDecoderCheckTimeNFrame(&rBufferHeader.pu1Buffer, &rBufferHeader.u8TimeStamp);
#endif
                // Update current play time for codec's query

                VideoDecYUVBufDisFree(rBufferHeader.pu1Buffer, &prVDMgrDNZ->rYUVBufferMgr);
                prVDMgrDZ->u4FramesSchedulerReturn++;

                if (VideoCoreRingBufferUsedNum(&prVDMgrDNZ->prInfoExtMem->rOutputResendQueueMgr) != 0)
                {
                    fgSendOutputBufferResult = _VideoDecoderSendBufferOut(&rOutBufferHeader, KAL_FALSE, DECODER_BUFFER_PORT_OUTPUT);
                }
                // Notify CCU about YUV info
                _VideoDecoderUpdateYUVInfoToCCU();
            }
            break;

            case DECODER_ACTION_OUTPUT_RESENT_FULL:
            {
                VE_SLIM_LOG0(TRACE_GROUP_10, VDEC_PROCESS_OUTPUT_RESEND);

                // Here, rOutBufferHeader is dummy and would not send to scheduler (param 2 is kal_false)
                fgSendOutputBufferResult = _VideoDecoderSendBufferOut(&rOutBufferHeader, KAL_FALSE, DECODER_BUFFER_PORT_OUTPUT);
                _VideoDecoderGetDisplay2Send(&fgSendOutputBufferResult);
            }
            break;

            case DECODER_ACTION_INPUT_BUFFER:
            {
                VIDEO_CORE_RING_BUFFER_MGR_T *pRBBM =  &prVDMgrDNZ->prInfoExtMem->rReturningBitstreamBufferMgr;
                VIDEO_DECODER_BS_BUFFER_ATOM_T rBSAtom;

                drv_trace4(TRACE_GROUP_10, VDEC_PROCESS_INPUT,
                    (kal_uint32)(rBufferHeader.pu1Buffer),
                    rBufferHeader.u8TimeStamp, rBufferHeader.u4BuffSize,
                    rBufferHeader.eFlags);

                {
                    VIDEO_BUFFERHEADER_TYPE_T *prBufferHeader = &prVDMgrDNZ->rNewestInputBufferHeader;
                    kal_mem_cpy((void*)(prBufferHeader), (void*)(&rBufferHeader), sizeof(*prBufferHeader));
                }

                _VideoDecoderMemDebug(DECODER_MDT_INPUT_BITSTREAM, (void *)&rBufferHeader, 0);

#ifdef __VE_KMV_SUPPORT__

                {
                    VIDEO_DECODER_CODEC_ERROR_T eCodecError = VIDEO_DECODER_CODEC_ERROR_NONE;

                    // Check if KMV is initialized
                    if ((prVDMgrDNZ->eScenario == VIDEO_SCENARIO_KMV || prVDMgrDNZ->eScenario == VIDEO_SCENARIO_PREVIEW_KMV) && prVDMgrDNZ->rKMVObj.fg_kmv_inited == KAL_FALSE)
                    {
                        kal_int32 u4Ret;
                        
                        kmv_meta_st *prUnsentKMVMetaData = (kmv_meta_st*)prVDMgrDNZ->rNewestInputBufferHeader.pPrivateData;                        
                        
                        prVDMgrDNZ->rKMVFrameBuffer.stride_y = &prVDMgrDNZ->rKMVFrameInfo.i4stride_y;
                        prVDMgrDNZ->rKMVFrameBuffer.stride_uv = &prVDMgrDNZ->rKMVFrameInfo.i4stride_uv;
                        
                        //u4Ret = kmv_init(&_prVideoDecoderMgr, &(prUnsentKMVMetaData->tType), KAL_TRUE); // KAL_TRUE --> Enable kmv_speed_mode.
                        u4Ret = VideoDecoderKMVInit(&(prUnsentKMVMetaData->tType), KAL_FALSE); // KAL_TRUE --> Enable kmv_speed_mode.
    
                        if (0 != u4Ret)
                        {
                            ASSERT(0);
                            drv_trace0(TRACE_GROUP_10, VDEC_KMV_INIT_FAIL);
                            prVDMgrDZ->fgFail2SetYUV = KAL_TRUE; // KMV init would only fail for insufficient memory.
                        }
                    }

                    // We should try to proceed post-processing before trigger next decode                               
                    eCodecError = _VideoDecoderGetDisplay2Send(&fgSendOutputBufferResult);
                    VE_UNUSED(eCodecError);
                }
#endif

                kal_mem_cpy((void*)(&rBSAtom.rBufferHeader), (void*)(&rBufferHeader), sizeof(rBSAtom.rBufferHeader));

                if (0 == ((kal_uint32)(eFlag) & (kal_uint32)(VIDEO_BUFFERFLAG_EOF)))
                {
                    //VIDEO_DECODER_BS_BUFFER_ATOM_T rBSAtom;
                    kal_uint32 u4SavedMask = 0;
                    VFC_OP_DATA_DECODER_INFO_T rDecoderInfo;
                    kal_mem_set((void*)&rDecoderInfo, 0, sizeof(rDecoderInfo));

                    //kal_mem_cpy((void*)(&rBSAtom.rBufferHeader), (void*)(&rBufferHeader), sizeof(rBSAtom.rBufferHeader));

                    // Always check trigger decode or not
                    {
                        rDecoderInfo.fgNeed2TriggerDecode = KAL_TRUE;
                        VFC_IOCtrl(VFC_OP_VD_CHECK_IF_TRIGGER_DECODE, (void*)&rBufferHeader, (void*)&(rDecoderInfo), NULL);
                        prVDMgrDZ->u8CurrentPlayTime = rDecoderInfo.u8CurrentPlayTime;
                    }

                    if ((prVDMgrDZ->eFlushAllNonSyncFrmState != DECDOER_FLUSH_STATE_FLUSH)/* && (KAL_TRUE == rDecoderInfo.fgNeed2TriggerDecode)*/)
                    {
                        kal_uint32 u4DecodeStartTime, u4DecodeTime;
                        VIDEO_DECODER_CODEC_ERROR_T eCodecError = VIDEO_DECODER_CODEC_ERROR_NONE;

                        // Insert bitsteam bufferheader to ring buffer
                        rBSAtom.fgReturned = KAL_FALSE;

                        VideoCoreInsertToHeadofRingBuffer(pRBBM, (kal_uint8*)(&rBSAtom));

                        // Decode a unit
                        u4DecodeTime = 0;
                        if (KAL_FALSE == prVDMgrDZ->fgCodecNotSupport && KAL_FALSE == prVDMgrDZ->fgFail2SetYUV)
                        {
                            kal_uint32 u4EndTime;

                            if (prVDMgrDZ->fg1stKeyFrameReady == KAL_FALSE)
                            {
                                if (0 == ((kal_uint32)(eFlag) & (kal_uint32)(VIDEO_BUFFERFLAG_SYNCFRAME)) &&
                                    0 == ((kal_uint32)(eFlag) & (kal_uint32)(VIDEO_BUFFERFLAG_PARAMETERSET)))
                                {
                                    drv_trace4(TRACE_GROUP_10, VDEC_KEY_FRAME_STAT, 0,
                                        prVDMgrDNZ->rNewestInputBufferHeader.u4BuffSize,
                                        (kal_uint32) prVDMgrDNZ->rNewestInputBufferHeader.u8TimeStamp, 0);
                                    //ASSERT(0);
                                }
                                else
                                {
                                    if (0 != ((kal_uint32)(eFlag) & (kal_uint32)(VIDEO_BUFFERFLAG_SYNCFRAME)))
                                    {
                                        prVDMgrDZ->fg1stKeyFrameReady = KAL_TRUE;
                                        drv_trace4(TRACE_GROUP_10, VDEC_KEY_FRAME_STAT, 1,
                                            prVDMgrDNZ->rNewestInputBufferHeader.u4BuffSize,
                                            (kal_uint32) prVDMgrDNZ->rNewestInputBufferHeader.u8TimeStamp, 0);
                                    }
                                }
                            }

                            u4DecodeStartTime = video_get_current_time();
                            VIDEO_START_LOGGING("DEC");

                            eCodecError = prVDMgrDNZ->prCodecAPI->pfnDecodeOneUnit(&rBufferHeader);
                            VIDEO_STOP_LOGGING("DEC");
                            u4DecodeTime = video_get_duration_ms(u4DecodeStartTime);

                            prVDMgrDZ->u4DecoderTotalTime += u4DecodeTime;

                            u4EndTime = video_get_current_time();
                            prVDMgrDZ->u4ExecuteTicks += video_get_duration_tick(u4DecodeStartTime, u4EndTime);
                            prVDMgrDZ->u4DecoderCounter++;

                            {
                                VFC_OP_DATA_DECODE_TIME_WND_T rWndData;
                                rWndData.eBufferFlag       = rBufferHeader.eFlags;
                                rWndData.u4DecodeTime      = u4DecodeTime;
                                rWndData.u4DecodeTotalTime = prVDMgrDZ->u4DecoderTotalTime;
                                rWndData.u4DecodeCount     = prVDMgrDZ->u4DecoderCounter;
                                rWndData.pBufferHeader     = &rBufferHeader;
                                VFC_IOCtrl(VFC_OP_VD_UPDATE_DECODER_STAT, &rWndData, NULL, NULL);
                            }
                        }
                        else
                        {
                            // Once the rVDMgrDZ.fgCodecNotSupport is set, no bitstream would be sent to adaptation layer anymore

                            if (prVDMgrDNZ->fgUnsupportCallbackIL == KAL_TRUE)
                            {
                                VIDEO_ERROR_TYPE_T eError;
                                eError = prVDMgrDNZ->rCommState.prCallback->pfnEventHandler(VIDEO_EVENT_RESOLUTION_NOT_SUPPORT, VIDEO_COMMAND_NOTIFY, NULL, NULL);
                                VE_UNUSED(eError);

                                VE_SLIM_LOG1(TRACE_GROUP_10, VDEC_CALLBACK, VIDEO_EVENT_RESOLUTION_NOT_SUPPORT);

                                prVDMgrDNZ->fgUnsupportCallbackIL = KAL_FALSE;
                            }

                            VideoDecoderReturnBitstream(rBufferHeader.pu1Buffer, rBufferHeader.u4BuffSize);
                        }

#ifdef __VE_ENABLE_FORCE_SLEEP__
                        if (KAL_TRUE == prVDMgrDZ->fgDecoderSleep)
                        {
                            kal_uint32 u4Count, u4TotalTick;
                            u4Count = prVDMgrDZ->u4ExecuteTicks / prVDMgrDZ->u1ElapseTicks;
                            u4TotalTick =  u4Count * prVDMgrDZ->u1SleepTicks;
                            prVDMgrDZ->u4ExecuteTicks -= (u4Count * prVDMgrDZ->u1ElapseTicks);

                            if (u4TotalTick > MAX_SLEEP_TICKS)
                            {
                                u4TotalTick = MAX_SLEEP_TICKS;
                            }
                            if (u4TotalTick > 0)
                            {
                                drv_trace4(TRACE_GROUP_10, VDEC_DECODE_SLEEP, u4TotalTick, prVDMgrDZ->u1ElapseTicks, prVDMgrDZ->u1SleepTicks, prVDMgrDZ->u4ExecuteTicks);
                                kal_sleep_task(u4TotalTick);
                            }
                        }
#endif
                        drv_trace4(TRACE_GROUP_8, VDEC_DECODE_PROFILE,
                            u4DecodeTime,
                            (((kal_uint64)prVDMgrDZ->u4DecoderTotalTime) * 1000 / prVDMgrDZ->u4DecoderCounter),
                            prVDMgrDZ->u4DecoderCounter,
                            0);

                        if (eCodecError == VIDEO_DECODER_CODEC_BSQUE_OVERFLOW)
                        {
                            kal_mem_set((void*)(&rBSAtom), 0, sizeof(rBSAtom));

                            VideoCoreRemoveFromHeadofRingBufferAddr(pRBBM, (kal_uint8*)(&rBSAtom));

                            if (rBSAtom.fgReturned == KAL_TRUE || rBSAtom.rBufferHeader.pu1Buffer != rBufferHeader.pu1Buffer)
                            {
                                ASSERT(0);
                            }
                        }
                        else
                        {
                            switch (eCodecError)
                            {
                                case VIDEO_DECODER_CODEC_EXCEED_MAX_RETRY:
                                {
                                    // Once YUV can be set successfully(Scheduler will be able to receive frames to callback READY),
                                    //  we don't care decode error.
                                    if (KAL_FALSE == prVDMgrDZ->fgInitBuffer && KAL_TRUE == prVDMgrDNZ->fgRetryCallbackIL)
                                    {
                                        VIDEO_ERROR_TYPE_T eError;

                                        eError = prVDMgrDNZ->rCommState.prCallback->pfnEventHandler(VIDEO_EVENT_EXCEED_MAX_RETRY, VIDEO_COMMAND_NOTIFY, NULL, NULL);
                                        drv_trace1(TRACE_GROUP_10, VDEC_CALLBACK, VIDEO_EVENT_EXCEED_MAX_RETRY);

                                        prVDMgrDNZ->fgRetryCallbackIL = KAL_FALSE;
                                        VE_UNUSED(eError);
                                    }
                                }
                                break;


                                case VIDEO_DECODER_CODEC_ERROR_NONE:
                                break;

                                case VIDEO_DECODER_CODEC_ERROR:
                                {
                                    drv_trace0(TRACE_GROUP_8, VDEC_DECODE_ERR);
                                }
                                break;

                                case VIDEO_DECODER_CODEC_ERROR_FAIL_PLAYBACK:
                                case VIDEO_DECODER_CODEC_ERROR_NOT_SUPPORT:
                                {
                                    VIDEO_ERROR_TYPE_T eError;

                                    prVDMgrDZ->fgCodecNotSupport = KAL_TRUE;

                                    if (eCodecError == VIDEO_DECODER_CODEC_ERROR_FAIL_PLAYBACK)
                                    {
                                        eError = prVDMgrDNZ->rCommState.prCallback->pfnEventHandler(VIDEO_EVENT_ERROR, VIDEO_COMMAND_NOTIFY, NULL, NULL);

                                        VE_SLIM_LOG1(TRACE_GROUP_10, VDEC_CALLBACK, VIDEO_EVENT_ERROR);
                                    }
                                    else
                                    {
                                        eError = prVDMgrDNZ->rCommState.prCallback->pfnEventHandler(VIDEO_EVENT_RESOLUTION_NOT_SUPPORT, VIDEO_COMMAND_NOTIFY, NULL, NULL);

                                        drv_trace1(TRACE_GROUP_10, VDEC_CALLBACK, VIDEO_EVENT_RESOLUTION_NOT_SUPPORT);
                                    }

                                    if (eError != VIDEO_ERROR_NONE)
                                    {
                                        ASSERT(0);
                                    }
                                }
                                break;

                                case VIDEO_DECODER_CODEC_BSQUE_FULL:
                                {
                                    u4SavedMask = SaveAndSetIRQMask();
                                    prVDMgrDZ->fgBitstreamQFull = KAL_TRUE;
                                    RestoreIRQMask(u4SavedMask);
                                }
                                break;

                                default:
#ifndef __VE_ROBUST_FLOW__
                                    ASSERT(0);
#endif
                                break;
                            }

                            // consume component input data
                            if (VideoCommConsumeInputBuffData(&prVDMgrDNZ->rCommState) == KAL_FALSE)
                            {
                                ASSERT(0);
                            }

                            if (prVDMgrDZ->eFlushAllNonSyncFrmState != DECODER_FLUSH_STATE_NONE && prVDMgrDZ->u4NeedToFlushNum > 0)
                            {
                                prVDMgrDZ->u4NeedToFlushNum--;
                            }

                            prVDMgrDZ->u4ItemsInInputQ--;

                            // notify VFC for removing a key frame record
                            {
                                kal_bool fgResetAll = KAL_FALSE;
                                VFC_IOCtrl(VFC_OP_VD_FRAME_REMOVED, &rBufferHeader, NULL, &fgResetAll);
                            }
                        }

                        eCodecError = _VideoDecoderGetDisplay2Send(&fgSendOutputBufferResult);

                        // Call this function to send bitstream back if there's any, note that the second parameter is false
                        // which means we would not automatically send the bitstream back
                        // the bitstream would be sent back only when codec return it
                        fgSendInputBufferResult = _VideoDecoderSendBufferOut(&rBufferHeader, KAL_FALSE, DECODER_BUFFER_PORT_INPUT);
                    }
                    else if (KAL_FALSE == rDecoderInfo.fgNeed2TriggerDecode || prVDMgrDZ->eFlushAllNonSyncFrmState == DECDOER_FLUSH_STATE_FLUSH)
                    {
                        // consume component input data
                        if (VideoCommConsumeInputBuffData(&prVDMgrDNZ->rCommState) == KAL_FALSE)
                        {
                            ASSERT(0);
                        }

                        if (prVDMgrDZ->u4NeedToFlushNum > 0)
                        {
                            prVDMgrDZ->u4NeedToFlushNum--;
                        }

                        prVDMgrDZ->u4ItemsInInputQ--;

                        // notify VFC for removing a key frame record
                        {
                            kal_bool fgResetAll = KAL_FALSE;
                            VFC_IOCtrl(VFC_OP_VD_FRAME_REMOVED, &rBufferHeader, NULL, &fgResetAll);
                        }

                        // Insert bitsteam bufferheader to ring buffer
                        rBSAtom.fgReturned = KAL_TRUE;

                        VideoCoreInsertToHeadofRingBuffer(pRBBM, (kal_uint8*)(&rBSAtom));

                        fgSendInputBufferResult = _VideoDecoderSendBufferOut(&rBufferHeader, KAL_FALSE, DECODER_BUFFER_PORT_INPUT);

                        {
                            VIDEO_PORT_TYPE_T ePortType = VIDEO_PORT_VIDEO_DATA;
                            kal_uint32 u4PortIndex = 0;

                            u4PortIndex = VideoCommGetInputPortIndex(&prVDMgrDNZ->rCommState, ePortType);
                            prVDMgrDZ->u4NeedToFlushNum = VideoCommGetInputBuffQUsedNum(&prVDMgrDNZ->rCommState, u4PortIndex);

                            /*
                            drv_trace4(TRACE_GROUP_10, VDEC_DROP_ALL,
                                       prVDMgrDNZ->rCommState.rInputBuffQ.u4ReadIdx,
                                       prVDMgrDNZ->rCommState.rInputBuffQ.u4WriteIdx,
                                       _prVideoDecoderMgr->u4FlushWriteIdx, 0);
                            */

                            drv_trace1(TRACE_GROUP_10, VDEC_DROP_ALL_NUM, prVDMgrDZ->u4NeedToFlushNum);


                            //if (_prVideoDecoderMgr->u4FlushWriteIdx == prVDMgrDNZ->rCommState.rInputBuffQ.u4ReadIdx)
                            if (prVDMgrDZ->u4NeedToFlushNum == 0)
                            {
                                prVDMgrDZ->eFlushAllNonSyncFrmState = DECDOER_FLUSH_STATE_DONE;
                            }
                        }
                    }
                    else
                    {
                        ASSERT(0);
                    }
                }
                else
                {
                    kal_uint32 u4DummyParam;
                    VIDEO_DECODER_CODEC_ERROR_T eCodecError = VIDEO_DECODER_CODEC_ERROR_NONE;

                    if (prVDMgrDZ->eFlushAllNonSyncFrmState == DECDOER_FLUSH_STATE_FLUSH)
                    {
                        VIDEO_PORT_TYPE_T ePortType = VIDEO_PORT_VIDEO_DATA;
                        kal_uint32 u4PortIndex = 0;

                        u4PortIndex = VideoCommGetInputPortIndex(&prVDMgrDNZ->rCommState, ePortType);
                        prVDMgrDZ->u4NeedToFlushNum = VideoCommGetInputBuffQUsedNum(&prVDMgrDNZ->rCommState, u4PortIndex);

                        //if (_prVideoDecoderMgr->u4FlushWriteIdx == prVDMgrDNZ->rCommState.rInputBuffQ.u4ReadIdx)
                        if (prVDMgrDZ->u4NeedToFlushNum == 0)
                        {
                            prVDMgrDZ->eFlushAllNonSyncFrmState = DECDOER_FLUSH_STATE_DONE;
                        }
                    }

                    // consume component input data
                    if (VideoCommConsumeInputBuffData(&prVDMgrDNZ->rCommState) == KAL_FALSE)
                    {
                        ASSERT(0);
                    }

                    if (prVDMgrDZ->eFlushAllNonSyncFrmState != DECODER_FLUSH_STATE_NONE && prVDMgrDZ->u4NeedToFlushNum > 0)
                    {
                        prVDMgrDZ->u4NeedToFlushNum--;
                    }

                    prVDMgrDZ->u4ItemsInInputQ--;

                    eCodecError = prVDMgrDNZ->prCodecAPI->pfnSetParameter(VIDEO_DECODER_PARAM_EOF, (void*)(&u4DummyParam));
#ifndef __VE_ROBUST_FLOW__
                    if (eCodecError != VIDEO_DECODER_CODEC_ERROR_NONE)
                    {
                        ASSERT(0);
                    }
#endif

                    eCodecError = _VideoDecoderGetDisplay2Send(&fgSendOutputBufferResult);

                    drv_trace1(TRACE_GROUP_10, VDEC_EOF_READY, rOutBufferHeader.u8TimeStamp);

                    // Send the EOF back

                    // Insert bitsteam bufferheader to ring buffer
                    rBSAtom.fgReturned = KAL_TRUE;

                    VideoCoreInsertToHeadofRingBuffer(pRBBM, (kal_uint8*)(&rBSAtom));

                    fgSendInputBufferResult = _VideoDecoderSendBufferOut(&rBufferHeader, KAL_FALSE, DECODER_BUFFER_PORT_INPUT);
                    VE_UNUSED(eCodecError);
                }

                // Now, decoder doesn't need to do this automatically, codec would trigger this action instead
                //fgSendInputBufferResult = _VideoDecoderSendBufferOut(&rBufferHeader, KAL_TRUE, BUFFER_PORT_INPUT);

                // Clean an item after decode done
                VCodecCtrlCleanItem(VCS_DECODER, &rBufferHeader);
            }
            break;

            case DECODER_ACTION_INPUT_RESENT_FULL:
            {
                VE_SLIM_LOG0(TRACE_GROUP_10, VDEC_PROCESS_INPUT_RESEND);
                // Here, rOutBufferHeader is dummy and would not send to file reader (param 2 is kal_false)
                fgSendInputBufferResult = _VideoDecoderSendBufferOut(&rOutBufferHeader, KAL_FALSE, DECODER_BUFFER_PORT_INPUT);
            }
            break;

            default:
#ifndef __VE_ROBUST_FLOW__
                ASSERT(0);
#endif
            break;
        }  // switch (eAction)

        if (prVDMgrDZ->fgClosingDecoder == KAL_TRUE)
        {
            break;
        }

        if (VideoCommGetState(&prVDMgrDNZ->rCommState) == VIDEO_STATE_STOP)
        {
            // Stop doing things when switch to STOP state
            break;
        }

        if ((fgSendInputBufferResult == KAL_FALSE)||(fgSendOutputBufferResult == KAL_FALSE))
        {
            kal_set_timer(prVDMgrDNZ->rTimerID, _VideoDecoderWakeUp, NULL, 10, 0);
            prVDMgrDNZ->fgStartWakeUpTimer = KAL_TRUE;
            VE_SLIM_LOG0(TRACE_GROUP_8, VDEC_ACTIVATE_TIMER);
            break;
        }
    } while(1);

    // Move this part to NON-DCM region
    /*
    if (prVDMgrDZ->fgClosingDecoder == KAL_TRUE)
    {
        if (VideoCommCheckProcessing(&prVDMgrDNZ->rCommState) == KAL_FALSE)
        {
            VideoCommChangeState(&prVDMgrDNZ->rCommState, VIDEO_STATE_CLOSE);
        }
    }
    */
}


/*****************************************************************************
* Context:
*****************************************************************************/
static VIDEO_ERROR_TYPE_T _VideoDecoderOpen(void)
{
    VIDEO_DECODER_MGR_DNZ_T* prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;
    //VIDEO_DECODER_MGR_T *prMgr = _prVideoDecoderMgr;
    kal_uint32 u4OutputPortIndex = 0;

    prVDMgrDNZ->prInfoExtMem = (VIDEO_DECODER_INFO_SAVE_EXT_MEM*)VideoGetExtBuffer(prVDMgrDNZ->rMemHdler.prExtMemHdr, sizeof(VIDEO_DECODER_INFO_SAVE_EXT_MEM));
    if (0 == prVDMgrDNZ->prInfoExtMem)
    {
        goto VIDEO_DECODER_OPEN_FAILED;
    }

    prVDMgrDNZ->u4YUVBufferTotalSize = _VideoDecoderGetYUVBufferSize(_prVideoDecoderMgr);
    prVDMgrDNZ->u4YUVBufferTotalSize = ROUND_UP_TO_POWER_OF_TWO(prVDMgrDNZ->u4YUVBufferTotalSize, 4);

    VideoSetExtCacheBuffer(prVDMgrDNZ->rMemHdler.prExtMemHdr, prVDMgrDNZ->u4YUVBufferTotalSize + GUARD_PATTERN_LENGTH);
    prVDMgrDNZ->pu1YUVBufferStartAddr = (kal_uint8*)VideoGetExtCacheBuffer(prVDMgrDNZ->rMemHdler.prExtMemHdr, prVDMgrDNZ->u4YUVBufferTotalSize + GUARD_PATTERN_LENGTH);
    if (0 == prVDMgrDNZ->pu1YUVBufferStartAddr)
    {
        goto VIDEO_DECODER_OPEN_FAILED;
    }

    u4OutputPortIndex = VideoCommGetOutputPortIndex(&prVDMgrDNZ->rCommState, VIDEO_PORT_VIDEO_DATA);
    prVDMgrDNZ->pu1CodecBufferStartAddr = VideoCommGetOutputBuff(&prVDMgrDNZ->rCommState, VIDEO_PORT_VIDEO_DATA, &u4OutputPortIndex);
    prVDMgrDNZ->pu1CodecBufferStartAddr = (kal_uint8*)ROUND_UP_TO_POWER_OF_TWO((kal_uint32)prVDMgrDNZ->pu1CodecBufferStartAddr, 4);
    _VideoDecoderCodecMemoryInit();

    return VIDEO_ERROR_NONE;

VIDEO_DECODER_OPEN_FAILED:
    return VIDEO_ERROR_BUFF_FULL;

}


/*****************************************************************************
* Context:
*****************************************************************************/
static void _VideoDecoderReleaseResource(kal_bool fgCloseCodec,
        kal_bool fgFreeTimer)
{
    VIDEO_DECODER_MGR_DNZ_T* prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;
    VIDEO_ERROR_TYPE_T eNestedError;
    VIDEO_DECODER_CODEC_ERROR_T eNestedRet;

    if (fgCloseCodec == KAL_TRUE)
    {
        eNestedRet = prVDMgrDNZ->prCodecAPI->pfnClose();
        VE_UNUSED(eNestedRet);
    }

    _VideoDecoderManagementDeInit();

    VideoFreeMutex(MUTEX_USER_DECODER_V2COMMON, prVDMgrDNZ->eCommonMutex);

    eNestedError = VideoCommDeInit(&prVDMgrDNZ->rCommState);

    if (fgFreeTimer == KAL_TRUE)
    {
        _VideoFreeTimer(TIMER_USER_DECODER, prVDMgrDNZ->rTimerID);
    }

    drv_trace1(TRACE_GROUP_8, VDEC_COMMON_DEINIT, eNestedError);
}


/*****************************************************************************
* Context:
*****************************************************************************/
VIDEO_ERROR_TYPE_T VideoDecoderInit(void)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VIDEO_DECODER_CODEC_ERROR_T eRet = VIDEO_DECODER_CODEC_ERROR_NONE;
    VIDEO_PORT_CONFIG_T rInputPort;
    VIDEO_PORT_CONFIG_T rOutputPort;
    VIDEO_COMPONENT_INIT_T rInitConfig;
    VIDEO_DECODER_MGR_DNZ_T* prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;
    VIDEO_CODEC_MEMORY_T *prCodecMemorySize = &prVDMgrDNZ->rCodecMemorySize;
    VIDEO_DECODER_CODEC_ERROR_T eCodecError = VIDEO_DECODER_CODEC_ERROR_NONE;
    kal_bool fgCloseCodec = KAL_FALSE;
    kal_bool fgFreeTimer = KAL_FALSE;

    _VideoDecoderInitWriteData2File();

    eCodecError = prVDMgrDNZ->prCodecAPI->pfnGetParameter(VIDEO_DECODER_PARAM_MEMORY_REQUIREMENT, (void*)prCodecMemorySize);

#ifndef __VE_ROBUST_FLOW__
    if (eCodecError != VIDEO_DECODER_CODEC_ERROR_NONE)
    {
        ASSERT(0);
    }
#else
    VE_UNUSED(eCodecError);
#endif

    prCodecMemorySize->u4ExternalSize += CODEC_ADM_SIZE;
    prCodecMemorySize->u4ExternalSize = ROUND_UP_TO_POWER_OF_TWO((prCodecMemorySize->u4ExternalSize), 4);

    // Common API initialization
    rInputPort.ePortType = VIDEO_PORT_VIDEO_DATA;
    rInputPort.fgSupplier = KAL_FALSE;
    rInputPort.u4BuffSize = 0;

    rOutputPort.ePortType = VIDEO_PORT_VIDEO_DATA;
    rOutputPort.fgSupplier = KAL_TRUE;
    rOutputPort.u4BuffSize = prCodecMemorySize->u4ExternalSize;

    kal_mem_set(&rInitConfig, 0, sizeof(rInitConfig));
    rInitConfig.prInputPort1 = &rInputPort;
    rInitConfig.prInputPort2 = NULL;
    rInitConfig.prOutputPort1 = &rOutputPort;
    rInitConfig.prOutputPort2 = NULL;
    rInitConfig.u4CmdQSize = VIDEO_DECODER_COMMAND_Q_LEN;
    rInitConfig.u4InputBuffQSize = VIDEO_DECODER_INPUT_BUFFER_Q_LEN;
    rInitConfig.u4OutputBuffQSize = VIDEO_DECODER_OUTPUTPUT_BUFFER_Q_LEN;
    rInitConfig.prExtMemHdlr = prVDMgrDNZ->rMemHdler.prExtMemHdr;

    rInitConfig.eMutex = prVDMgrDNZ->eCommonMutex = VideoGetMutex(MUTEX_USER_DECODER_V2COMMON);
    eError = VideoCommInit(&prVDMgrDNZ->rCommState, & rInitConfig, "DECODER");
    if(eError != VIDEO_ERROR_NONE)
    {
        drv_trace2(TRACE_GROUP_10, VDEC_COMMON_INIT, eError, __LINE__);
        VideoFreeMutex(MUTEX_USER_DECODER_V2COMMON, prVDMgrDNZ->eCommonMutex);
        return eError;
    }

    // Decoder driver initilization
    eError = _VideoDecoderOpen();
    if(eError != VIDEO_ERROR_NONE)
    {
        VIDEO_ERROR_TYPE_T eNestedError = VIDEO_ERROR_NONE;

        drv_trace2(TRACE_GROUP_10, VDEC_COMMON_INIT, eError, __LINE__);

        // Common API de-initialization
        VideoFreeMutex(MUTEX_USER_DECODER_V2COMMON, prVDMgrDNZ->eCommonMutex);
        eNestedError = VideoCommDeInit(&prVDMgrDNZ->rCommState);
        drv_trace1(TRACE_GROUP_8, VDEC_COMMON_DEINIT, eNestedError);

        //VideoCommChangeState(&_prVideoDecoderMgr->rVDMgrDNZ.rCommState, VIDEO_STATE_CLOSE);
        prVDMgrDNZ->rCommState.eState = VIDEO_STATE_CLOSE; // Temp solution.

        return eError;
    }

    eError = _VideoDecoderManagementInit();
    if(eError != VIDEO_ERROR_NONE)
    {
        _VideoDecoderReleaseResource(fgCloseCodec, fgFreeTimer);
        drv_trace1(TRACE_GROUP_10, VDEC_DRV_INIT, eError);
        return eError;
    }

    prVDMgrDNZ->rTimerID = _VideoGetTimer(TIMER_USER_DECODER);

    prVDMgrDNZ->fgStartWakeUpTimer = KAL_FALSE;

    // Decoder API initialization
    eRet = prVDMgrDNZ->prCodecAPI->pfnOpen();
    if (eRet != VIDEO_DECODER_CODEC_ERROR_NONE)
    {
        fgFreeTimer = KAL_TRUE;
        _VideoDecoderReleaseResource(fgCloseCodec, fgFreeTimer);
        eError = VIDEO_ERROR_INIT_ERROR;
        drv_trace1(TRACE_GROUP_10, VDEC_CODEC_INIT, eRet);
        return eError;
    }

    eRet = prVDMgrDNZ->prCodecAPI->pfnInit();
    if (eRet != VIDEO_DECODER_CODEC_ERROR_NONE)
    {
        fgCloseCodec = KAL_TRUE;
        fgFreeTimer = KAL_TRUE;
        _VideoDecoderReleaseResource(fgCloseCodec, fgFreeTimer);
        eError = VIDEO_ERROR_INIT_ERROR;
        drv_trace1(TRACE_GROUP_10, VDEC_CODEC_INIT, eRet);
        return eError;
    }

    VE_SLIM_LOG2(TRACE_GROUP_8, VDEC_COMMON_INIT, eError, __LINE__);

    return eError;
}


/*****************************************************************************
* Context:
*****************************************************************************/
VIDEO_ERROR_TYPE_T VideoDecoderSendCommand(VIDEO_COMMAND_TYPE_T rCmd, kal_uint32 u4Param)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_bool fgSendMsg = KAL_FALSE;
    kal_bool fgRet = KAL_FALSE;
    VIDEO_DECODER_MGR_DNZ_T* prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;

    fgRet = VideoCommPushCommand(&prVDMgrDNZ->rCommState, rCmd, u4Param);
    if (fgRet == KAL_FALSE)
    {
        // error handling
        eError = VIDEO_ERROR_BUFF_FULL;
    }

    if (u4Param != VIDEO_STATE_CLOSE)
    {
        fgSendMsg = VideoCommSetProcessingNew(&prVDMgrDNZ->rCommState, KAL_FALSE);
    }
    else
    {
        fgSendMsg = VideoCommSetProcessingNew(&prVDMgrDNZ->rCommState, KAL_TRUE);
    }

    if (fgSendMsg == KAL_TRUE)
    {
        _VideoDecoderSendMessage(MSG_ID_DECODER_DATA_IND, DECODER_MSG_COMMAND, 0);
    }

    return eError;
}


/*****************************************************************************
* Context:
*****************************************************************************/
VIDEO_ERROR_TYPE_T VideoDecoderGetParameter(VIDEO_PARAM_TYPE_T eCmd, void *pParam)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VIDEO_DECODER_QUERY_FRAME_SIZE_TYPE_T rQueryResult;
    VIDEO_DECODER_CODEC_ERROR_T eCodecError = VIDEO_DECODER_CODEC_ERROR_NONE;
    VIDEO_DECODER_MGR_DNZ_T* prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;

    switch(eCmd)
    {
#ifdef __VE_3D_SIDE_BY_SIDE__
        case VIDEO_PARAM_GET_SBSFLAG:
        {
            prVDMgrDNZ->prCodecAPI->pfnGetParameter(VIDEO_DECODER_PARAM_GET_SBSFLAG, (void*)(pParam));
        }
        break;
#endif
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        case VIDEO_PARAM_INPUT_BUFFER_PARAM:
        {
            VideoCommGetInputPortParam(&prVDMgrDNZ->rCommState, pParam);
        }
        break;

        case VIDEO_PARAM_OUTPUT_BUFFER_PARAM:
        {
            VideoCommGetOutputPortParam(&prVDMgrDNZ->rCommState, pParam);
        }
        break;

        case VIDEO_PARAM_QUERY_RESOLUTION:
        {
            VIDEO_QUERY_FRAME_SIZE_TYPE_T *prQuery =  (VIDEO_QUERY_FRAME_SIZE_TYPE_T*)pParam;

            rQueryResult.pu1ParamStream = prQuery->pu1ParamStream;
            rQueryResult.u4ParamLength = prQuery->u4ParamLength;
            rQueryResult.pu4Height = &prQuery->u4Height;
            rQueryResult.pu4Width = &prQuery->u4Width;

            eCodecError = prVDMgrDNZ->prCodecAPI->pfnGetParameter(VIDEO_DECODER_PARAM_QUERY_RESOLUTION, (void*)&rQueryResult);

            switch(eCodecError)
            {
                case VIDEO_DECODER_CODEC_ERROR_NONE:
                break;

                case VIDEO_DECODER_CODEC_ERROR_NOT_SUPPORT:
                {
                    eError = VIDEO_ERROR_CODEC_NOT_SUPPORT;
                }
                break;

                default:
                {
                    eError = VIDEO_ERROR_DECODER_ERROR;
                }
                break;
            }
        }
        break;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        case VIDEO_PARAM_QUERY_PREDICATION_TIME:
        {
            prVDMgrDNZ->prCodecAPI->pfnGetParameter(VIDEO_DECODER_PARAM_QUERY_PREDICATION_TIME, pParam);
        }
        break;

        default:
        {
            eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
        }
        break;
    }

    drv_trace2(TRACE_GROUP_10, VDEC_GET_PARAM, eCmd, eError);

    return eError;
}


/*****************************************************************************
* Context:
*****************************************************************************/
VIDEO_ERROR_TYPE_T VideoDecoderSetParameter(VIDEO_PARAM_TYPE_T eCmd, void *pParam)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VIDEO_STATE_TYPE_T eState;
    VIDEO_DECODER_MGR_DNZ_T* prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;
    VIDEO_DECODER_MGR_DZ_T* prVDMgrDZ = &_prVideoDecoderMgr->rVDMgrDZ;

    eState = VideoCommGetState(&prVDMgrDNZ->rCommState);

    if (eState == VIDEO_STATE_RUN)
    {
        switch(eCmd)
        {
            case VIDEO_PARAM_FLUSH_FRM:
            {
                if ((prVDMgrDZ->eFlushAllNonSyncFrmState == DECODER_FLUSH_STATE_NONE))
                {
                    //kal_uint32 u4Read, u4Write;
                    void *pVoid = NULL;

                    VIDEO_PORT_TYPE_T ePortType = VIDEO_PORT_VIDEO_DATA;
                    kal_uint32 u4PortIndex = 0;

                    //u4Read = _prVideoDecoderMgr->rVDMgrDNZ.rCommState.rInputBuffQ.u4ReadIdx;
                    //u4Write = _prVideoDecoderMgr->rVDMgrDNZ.rCommState.rInputBuffQ.u4WriteIdx;

                    // Ask codec to flush non-displayed frames.
                    prVDMgrDZ->fgIsFlushCodecSyncFrm = KAL_TRUE;

                    if ((VideoCommQueryInputBuff(&prVDMgrDNZ->rCommState) != 0) ||
                        _VideoDecoderIsResendQEmpty(&prVDMgrDNZ->prInfoExtMem->rInputResendQueueMgr) == KAL_FALSE  ||
                        VideoCoreIsRingBufferEmpty(&prVDMgrDNZ->prInfoExtMem->rReturningBitstreamBufferMgr) == KAL_FALSE)
                    {
                        prVDMgrDZ->eFlushAllNonSyncFrmState = DECDOER_FLUSH_STATE_FLUSH;
                        //_prVideoDecoderMgr->u4FlushWriteIdx = u4Write;

                        u4PortIndex = VideoCommGetInputPortIndex(&prVDMgrDNZ->rCommState, ePortType);
                        prVDMgrDZ->u4NeedToFlushNum = VideoCommGetInputBuffQUsedNum(&prVDMgrDNZ->rCommState, u4PortIndex);

                        eError = VIDEO_ERROR_ASYNC_OPERATION;
                        _VideoDecoderWakeUp(pVoid);
                    }
                    else
                    {
                        eError = VIDEO_ERROR_NO_FRAME_TO_FLUSH;
                    }
                    //drv_trace4(TRACE_GROUP_10, VDEC_FLUSH_ALL, u4Read, u4Write, _prVideoDecoderMgr->rVDMgrDZ.eFlushAllNonSyncFrmState, 0);
                    drv_trace2(TRACE_GROUP_10, VDEC_FLUSH_ALL_NUM, prVDMgrDZ->u4NeedToFlushNum, prVDMgrDZ->eFlushAllNonSyncFrmState);

                    //_prVideoDecoderMgr->rVDMgrDZ.fgIsFlushCodecSyncFrm = KAL_TRUE;
                }
                else
                {
                    eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
                }

                prVDMgrDZ->fg1stKeyFrameReady = KAL_FALSE;

                drv_trace4(TRACE_GROUP_10, VDEC_FLUSH_REQUEST,
                    VideoCommQueryInputBuff(&prVDMgrDNZ->rCommState),
                    VideoCoreRingBufferUsedNum(&prVDMgrDNZ->prInfoExtMem->rInputResendQueueMgr),
                    VideoCoreRingBufferUsedNum(&prVDMgrDNZ->prInfoExtMem->rReturningBitstreamBufferMgr),
                    eError);
            }
            break;

            case VIDEO_PARAM_BUFFERING_DONE:
            {
#ifndef __VE_SLIM_PROJECT__
                kal_uint32 u4Dummy = 0;
                prVDMgrDNZ->prCodecAPI->pfnSetParameter(VIDEO_DECODER_PARAM_NOT_BUFFERING, (void*)(&u4Dummy));
#endif
                prVDMgrDZ->fgBuffering = KAL_FALSE;
            }
            break;

            case VIDEO_PARAM_START_BUFFERING:
            {
                prVDMgrDZ->fgBuffering = KAL_TRUE;
            }
            break;

#ifdef __VE_ENABLE_FORCE_SLEEP__
            case VIDEO_PARAM_ELAPSE_TICKS_BEFORE_SLEEP:
            {
                prVDMgrDZ->u1ElapseTicks = *(kal_uint8*)(pParam);
                drv_trace1(TRACE_GROUP_9, VDEC_ELAPSE_TICKS, prVDMgrDZ->u1ElapseTicks);
            }
            break;

            case VIDEO_PARAM_SLEEP_TICKS:
            {
                prVDMgrDZ->u1SleepTicks = *(kal_uint8*)(pParam);
                drv_trace1(TRACE_GROUP_9, VDEC_SLEEP_TICKS, prVDMgrDZ->u1SleepTicks);
            }
            break;
#endif
            default:
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
            }
            break;
        }
    }
    else if (eState == VIDEO_STATE_IDLE)
    {
        switch(eCmd)
        {
#ifdef __VE_KMV_SUPPORT__
            case VIDEO_PARAM_SET_START_TIME:
            {
                prVDMgrDNZ->u8StartTime = *((kal_uint64*)(pParam));
            }
            break;
#endif
            
#ifdef __VE_PRIRATE_3D_FORMAT__
            case VIDEO_PARAM_DECRYPTION_MODE:
            {
                prVDMgrDNZ->prCodecAPI->pfnSetParameter(VIDEO_DECODER_PARAM_DECRYPTION_MODE, (void*)(pParam));
                prVDMgrDZ->fgDecryptionMode = KAL_TRUE;
            }
            break;

            case VIDEO_PARAM_SET_DECODE_MODE:
            {
                prVDMgrDNZ->rDecodeMode = *(VIDEO_DECODE_MODE_T*)(pParam);
                prVDMgrDNZ->prCodecAPI->pfnSetParameter(VIDEO_DECODER_PARAM_SET_DECODE_MODE, (void*)(pParam));
                //drv_trace1(TRACE_GROUP_9, VDEC_SLEEP_TICKS, _prVideoDecoderMgr->rVDMgrDZ.u1SleepTicks);
            }
            break;
#endif
            case VIDEO_PARAM_FRAMERATE:
            {
                prVDMgrDNZ->u4FrameRateFrmFile = *(kal_uint32*)(pParam);
                prVDMgrDNZ->prCodecAPI->pfnSetParameter(VIDEO_DECODER_PARAM_FRAMERATE, pParam);
                drv_trace1(TRACE_GROUP_8, VDEC_FRAME_RATE, prVDMgrDNZ->u4FrameRateFrmFile);
            }
            break;

            case VIDEO_PARAM_BITRATE:
            {
                prVDMgrDNZ->u4BitRateFrmFile = *(kal_uint32*)(pParam);
                prVDMgrDNZ->prCodecAPI->pfnSetParameter(VIDEO_DECODER_PARAM_BITRATE, pParam);
                drv_trace1(TRACE_GROUP_8, VDEC_BIT_RATE, prVDMgrDNZ->u4BitRateFrmFile);
            }
            break;

#ifdef __VE_ENABLE_FORCE_SLEEP__
            case VIDEO_PARAM_ELAPSE_TICKS_BEFORE_SLEEP:
            {
                prVDMgrDZ->u1ElapseTicks = *(kal_uint8*)(pParam);
                drv_trace1(TRACE_GROUP_9, VDEC_ELAPSE_TICKS, prVDMgrDZ->u1ElapseTicks);
            }
            break;

            case VIDEO_PARAM_SLEEP_TICKS:
            {
                prVDMgrDZ->u1SleepTicks = *(kal_uint8*)(pParam);
                drv_trace1(TRACE_GROUP_9, VDEC_SLEEP_TICKS, prVDMgrDZ->u1SleepTicks);
            }
            break;
#endif

            case VIDEO_PARAM_HEADER_RETRY:
            {
                //prVDMgrDNZ->u4HeaderRetryNs = *(kal_uint32*)(pParam);
                prVDMgrDNZ->prCodecAPI->pfnSetParameter(VIDEO_DECODER_PARAM_HEADER_RETRY, pParam);
            }
            break;

#ifdef __VE_VIDEO_VT_SUPPORT__
            case VIDEO_PARAM_SET_CTRL_VOS:
            {
                prVDMgrDNZ->prCodecAPI->pfnSetParameter(VIDEO_DECODER_PARAM_SET_CTRL_VOS, (void*)pParam);
            }
            break;
#endif

            default:
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
            }
            break;
        }
    }
    else if (eState == VIDEO_STATE_INIT)
    {
        switch(eCmd)
        {
            case VIDEO_PARAM_INPUT_BUFFER_PARAM:
            {
                VideoCommSetInputPortParam(&prVDMgrDNZ->rCommState, pParam);
            }
            break;

            case VIDEO_PARAM_OUTPUT_BUFFER_PARAM:
            {
                VideoCommSetOutputPortParam(&prVDMgrDNZ->rCommState, pParam);
            }
            break;

#ifdef __VE_ENABLE_FORCE_SLEEP__
            case VIDEO_PARAM_ELAPSE_TICKS_BEFORE_SLEEP:
            {
                prVDMgrDZ->u1ElapseTicks = *(kal_uint8*)(pParam);
                drv_trace1(TRACE_GROUP_9, VDEC_ELAPSE_TICKS, prVDMgrDZ->u1ElapseTicks);
            }
            break;

            case VIDEO_PARAM_SLEEP_TICKS:
            {
                prVDMgrDZ->u1SleepTicks = *(kal_uint8*)(pParam);
                drv_trace1(TRACE_GROUP_9, VDEC_SLEEP_TICKS, prVDMgrDZ->u1SleepTicks);
            }
            break;
#endif
            default:
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
            }
            break;
        }
    }
    else if (eState == VIDEO_STATE_STOP)
    {
        switch(eCmd)
        {
#ifdef __VE_ENABLE_FORCE_SLEEP__
            case VIDEO_PARAM_ELAPSE_TICKS_BEFORE_SLEEP:
            {
                prVDMgrDZ->u1ElapseTicks = *(kal_uint8*)(pParam);
                drv_trace1(TRACE_GROUP_9, VDEC_ELAPSE_TICKS, prVDMgrDZ->u1ElapseTicks);
            }
            break;

            case VIDEO_PARAM_SLEEP_TICKS:
            {
                prVDMgrDZ->u1SleepTicks = *(kal_uint8*)(pParam);
                drv_trace1(TRACE_GROUP_9, VDEC_SLEEP_TICKS, prVDMgrDZ->u1SleepTicks);
            }
            break;
#endif

#if defined(__VE_PRIRATE_3D_FORMAT__) || defined(__VE_3D_SIDE_BY_SIDE__)
            case VIDEO_PARAM_SET_DECODE_MODE:
            {
                prVDMgrDNZ->rDecodeMode = *(VIDEO_DECODE_MODE_T*)(pParam);
                prVDMgrDNZ->prCodecAPI->pfnSetParameter(VIDEO_DECODER_PARAM_SET_DECODE_MODE, (void*)(pParam));
                //drv_trace1(TRACE_GROUP_9, VDEC_SLEEP_TICKS, _prVideoDecoderMgr->rVDMgrDZ.u1SleepTicks);
            }
            break;
#endif
            default:
            {
                eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
            }
            break;
        }
    }
    else
    {
        eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
    }

#ifdef __VE_ENABLE_FORCE_SLEEP__
    if ((0 != prVDMgrDZ->u1ElapseTicks) && (0 != prVDMgrDZ->u1SleepTicks))
    {
        // Decoder would start to regularly sleep when both of the two fields are set
        prVDMgrDZ->fgDecoderSleep = KAL_TRUE;
        prVDMgrDZ->u4ExecuteTicks = 0;
        VIDEO_START_LOGGING("SLOW");
    }
    else
    {
        if (prVDMgrDZ->fgDecoderSleep == KAL_TRUE)
        {
            VIDEO_STOP_LOGGING("SLOW");
        }
        prVDMgrDZ->fgDecoderSleep = KAL_FALSE;
    }
#endif

    drv_trace4(TRACE_GROUP_10, VDEC_SET_PARAM, eCmd, eError, eState, 0);

    return eError;
}


/*****************************************************************************
* Context:
*****************************************************************************/
VIDEO_ERROR_TYPE_T VideoDecoderEmptyThisBuffer(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_bool fgSendMsg = KAL_FALSE;
    kal_bool fgRet = KAL_FALSE;
    VIDEO_DECODER_MGR_DNZ_T* prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;
    VIDEO_DECODER_MGR_DZ_T* prVDMgrDZ = &_prVideoDecoderMgr->rVDMgrDZ;
    kal_uint32 u4InputPort = VideoCommGetInputPortIndex(&prVDMgrDNZ->rCommState, VIDEO_PORT_VIDEO_DATA);
    VIDEO_COMPONENT_PARAM_T *prComParam = VideoCommGetInputComp(&prVDMgrDNZ->rCommState, u4InputPort);
#ifndef __VE_ROBUST_FLOW__
    kal_uint32 u4TunnelOutputPort = prComParam->u4PortIndex;
#endif

    if (prVDMgrDZ->fgClosingDecoder == KAL_TRUE)
    {
        return VIDEO_ERROR_BUFF_FULL;
    }

#ifndef __VE_ROBUST_FLOW__
    if((prBuffHeader->u4InputPort == u4InputPort) && (prBuffHeader->u4OutputPort == u4TunnelOutputPort))
    {
#endif
        drv_trace2(TRACE_GROUP_9, VDEC_EMPTY_BUF, (kal_uint32)(prBuffHeader->pu1Buffer), prBuffHeader->u8TimeStamp);

        fgRet = VideoCommPushInputBuff(&prVDMgrDNZ->rCommState, prBuffHeader);

        if(fgRet == KAL_FALSE)
        {
            //error handling
            drv_trace0(TRACE_GROUP_10, VDEC_EMPTY);
            return VIDEO_ERROR_BUFF_FULL;
        }

#ifndef __VE_SLIM_PROJECT__
        // Log to show the status of frame delivery
        if (prVDMgrDZ->u4PreviousRcvTime > 0)
        {
            prVDMgrDZ->u4TotalRcvTimeInMS += video_get_duration_ms(prVDMgrDZ->u4PreviousRcvTime);

            if (prVDMgrDZ->u4TotalRcvTimeInMS >= 1000)
            {
                drv_trace4(TRACE_GROUP_10, VDEC_DECODE_EMPTY_BUFFER_PROFILE,
                           prVDMgrDZ->u4TotalRcvFrameNum*1000/prVDMgrDZ->u4TotalRcvTimeInMS,
                           prVDMgrDZ->u4TotalRcvTimeInMS,
                           prVDMgrDZ->u4TotalRcvFrameNum,
                           0);

                prVDMgrDZ->u4TotalRcvTimeInMS = 0;
                prVDMgrDZ->u4TotalRcvFrameNum = 0;
            }
        }

        prVDMgrDZ->u4PreviousRcvTime = video_get_current_time();
        prVDMgrDZ->u4TotalRcvFrameNum ++;
#endif

        // Check if Source delivers data too late
        {
            VFC_OP_DATA_BITSTREAM_RECEIPT_T rBSReceiptData;
            rBSReceiptData.pBufferHeader        = prBuffHeader;
            rBSReceiptData.u1DataNumInInputQ    = VideoCommQueryInputBuff(&prVDMgrDNZ->rCommState);

            VFC_IOCtrl(VFC_OP_VD_CHECK_BITSTREAM_RECEIPT, &rBSReceiptData, NULL, NULL);
        }

        VCodecCtrlAddItem(VCS_DECODER, prBuffHeader);

        prVDMgrDZ->u4ItemsInInputQ++;

        if (((VideoDecoderGetAvailableYUVNumber(&prVDMgrDNZ->rYUVBufferMgr) != 0) && (KAL_TRUE == prVDMgrDZ->fgInitBuffer))
            || (NULL != ((prBuffHeader->eFlags) & (VIDEO_BUFFERFLAG_EOF)))
            || (KAL_FALSE == prVDMgrDZ->fgInitBuffer))
        {
            fgSendMsg = VideoCommSetProcessingNew(&prVDMgrDNZ->rCommState, KAL_FALSE);
            if (fgSendMsg == KAL_TRUE)
            {
                _VideoDecoderSendMessage(MSG_ID_DECODER_DATA_IND, DECODER_MSG_EMPTYBUFFER, 0);
            }
        }
#ifndef __VE_ROBUST_FLOW__
    }
    else
    {
        ASSERT(0);
        eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
    }
#endif

    return eError;
}


/*****************************************************************************
* Context:
*****************************************************************************/
VIDEO_ERROR_TYPE_T VideoDecoderFillThisBuffer(VIDEO_BUFFERHEADER_TYPE_T *prBuffHeader)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    kal_bool fgSendMsg = KAL_FALSE;
    kal_bool fgRet = KAL_FALSE;
    VIDEO_DECODER_MGR_DNZ_T* prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;
    VIDEO_DECODER_MGR_DZ_T* prVDMgrDZ = &_prVideoDecoderMgr->rVDMgrDZ;
    kal_uint32 u4OutputPortIndex = VideoCommGetOutputPortIndex(&prVDMgrDNZ->rCommState, VIDEO_PORT_VIDEO_DATA);
    VIDEO_COMPONENT_PARAM_T *prComParam = VideoCommGetOutputComp(&prVDMgrDNZ->rCommState, u4OutputPortIndex);
#ifndef __VE_ROBUST_FLOW__
    kal_uint32 u4TunneInputPort = prComParam->u4PortIndex;
#endif

    if (prVDMgrDZ->fgClosingDecoder == KAL_TRUE)
    {
        return VIDEO_ERROR_BUFF_FULL;
    }

#ifndef __VE_ROBUST_FLOW__
    if ((prBuffHeader->u4InputPort == u4TunneInputPort) && (prBuffHeader->u4OutputPort == u4OutputPortIndex))
    {
#endif
        drv_trace2(TRACE_GROUP_9, VDEC_FILL_BUF, (kal_uint32)(prBuffHeader->pu1Buffer), prBuffHeader->u8TimeStamp);

        fgRet = VideoCommPushOutputBuff(&prVDMgrDNZ->rCommState, prBuffHeader);
        if( fgRet == KAL_FALSE)
        {
            // Error handling
            drv_trace0(TRACE_GROUP_10, VDEC_FILL);
            return VIDEO_ERROR_BUFF_FULL;
        }

        prVDMgrDZ->u4ItemsInOutputQ++;

#ifndef __VE_ROBUST_FLOW__
        video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_RETURN_BUFFER, (kal_uint32)(prBuffHeader->pu1Buffer));
        video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_RETURN_TIME, prBuffHeader->u8TimeStamp);
#endif

        //fgSendMsg = VideoCommSetProcessing(&_prVideoDecoderMgr->rVDMgrDNZ.rCommState);
        fgSendMsg = VideoCommSetProcessingNew(&prVDMgrDNZ->rCommState, KAL_FALSE);
        if ( fgSendMsg == KAL_TRUE )  //|| (_prVideoDecoderMgr->bWaitBuffer == KAL_TRUE) )
        {
            _VideoDecoderSendMessage(MSG_ID_DECODER_DATA_IND, DECODER_MSG_FILLBUFFER, 0);
        }
#ifndef __VE_ROBUST_FLOW__
    }
    else
    {
        ASSERT(0);
        eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
    }
#endif
    return eError;
}


/*****************************************************************************
* Context:
*****************************************************************************/
VIDEO_ERROR_TYPE_T VideoDecoderSetCallbacks(VIDEO_CALLBACK_TYPE_T *prCallback)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    eError = VideoCommSetCallbacks(&_prVideoDecoderMgr->rVDMgrDNZ.rCommState, prCallback);

    VE_SLIM_LOG1(TRACE_GROUP_9, VDEC_SET_CALLBACK, eError);
    return eError;
}


/*****************************************************************************
* Context:
*****************************************************************************/
VIDEO_ERROR_TYPE_T VideoDecoderDeInit(void)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;
    VIDEO_DECODER_CODEC_ERROR_T eRet = VIDEO_DECODER_CODEC_ERROR_NONE;
    VIDEO_DECODER_MGR_DNZ_T* prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;

    _VideoDecoderDeInitWriteData2File();

    // CODEC de-initialization
    eRet = prVDMgrDNZ->prCodecAPI->pfnDeInit();
    if ( eRet != VIDEO_DECODER_CODEC_ERROR_NONE )
    {
        drv_trace1(TRACE_GROUP_10, VDEC_CODEC_DEINIT, eRet);
        eError = VIDEO_ERROR_DECODER_ERROR;
        return eError;
    }

    eRet = prVDMgrDNZ->prCodecAPI->pfnClose();
    if ( eRet != VIDEO_DECODER_CODEC_ERROR_NONE )
    {
        drv_trace1(TRACE_GROUP_10, VDEC_CODEC_DEINIT, eRet);
        eError = VIDEO_ERROR_DECODER_ERROR;
        return eError;
    }

    // Decoder driver de-initilization
    _VideoDecoderManagementDeInit();
    _VideoDecoderCodecMemoryDeInit();

    // Common API de-initialization
    VideoFreeMutex(MUTEX_USER_DECODER_V2COMMON, prVDMgrDNZ->eCommonMutex);
    eError = VideoCommDeInit(&prVDMgrDNZ->rCommState);

#ifdef __VE_KMV_SUPPORT__
    // Deinit KMV
    //VideoDecoderKMVDeInit(&_prVideoDecoderMgr->rVDMgrDNZ.rKMVObj);
#endif

    _VideoFreeTimer(TIMER_USER_DECODER, prVDMgrDNZ->rTimerID);

    drv_trace1(TRACE_GROUP_8, VDEC_COMMON_DEINIT, eError);

    return eError;
}


/*****************************************************************************
* Context:
*****************************************************************************/
static const VIDEO_COMPONENT_TYPE_T rVideoDecoderComp =
{
    /* .pfnInit            = */ VideoDecoderInit,
    /* .pfnSendCommand     = */ VideoDecoderSendCommand,
    /* .pfnGetParameter    = */ VideoDecoderGetParameter,
    /* .pfnSetParameter    = */ VideoDecoderSetParameter,
    /* .pfnUseBuffer       = */ NULL,
    /* .pfnEmptyThisBuffer = */ VideoDecoderEmptyThisBuffer,
    /* .pfnFillThisBuffer  = */ VideoDecoderFillThisBuffer,
    /* .pfnSetCallbacks    = */ VideoDecoderSetCallbacks,
    /* .pfnDeInit          = */ VideoDecoderDeInit
};


/*****************************************************************************
* Context:
*****************************************************************************/
VIDEO_DECODER_COMPONENT_TYPE_T GetVideoDecoderHandle(VIDEO_DECODER_HDLR_INFO_T* pVDHandleInfo)
{
    VIDEO_DECODER_COMPONENT_TYPE_T rVideoDecoderCompType;
    VIDEO_DECODER_MGR_DNZ_T *prVDMgrDNZ;
    //VIDEO_DECODER_MGR_DZ_T * prVDMgrDZ;
    VIDEO_DECODER_CUSTOM_SETTINGS_T *prCustomSettings;
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

#ifdef __VE_STKMGR_USER_FILTER_ENABLE__
    drv_gfx_stkmgr_set_user_filter(SW_VIDEO_STACK_SIZE);
#endif

    _prVideoDecoderMgr = (VIDEO_DECODER_MGR_T*)VideoGetExtBuffer(pVDHandleInfo->prExtMemHdr, sizeof(*_prVideoDecoderMgr) + GUARD_PATTERN_LENGTH);
    if (_prVideoDecoderMgr == NULL)
    {
        ASSERT(0);
    }

    // Reset Decoder Context
    kal_mem_set(_prVideoDecoderMgr, 0, sizeof(*_prVideoDecoderMgr));

    prVDMgrDNZ          = &(_prVideoDecoderMgr->rVDMgrDNZ);
    //prVDMgrDZ           = &(_prVideoDecoderMgr->rVDMgrDZ);
    prCustomSettings    = &(prVDMgrDNZ->rCustomSettings);

    // Remove RW
    kal_mem_set(&rVideoDecoderCompType, 0, sizeof(rVideoDecoderCompType));
    rVideoDecoderCompType.pComponent = (VIDEO_COMPONENT_TYPE_T*)&rVideoDecoderComp;

    // Read Custom Settings
    VideoDecoderGetSetting(prCustomSettings);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    drv_trace4(TRACE_GROUP_10, VDEC_EXT_MEM,
               prCustomSettings->u4FrmBufferSize,
               prCustomSettings->u4CodecWorkingMemory,
               prCustomSettings->u4DriverWorkingMemory,
               prCustomSettings->u4InfoExtMemSize);

    prVDMgrDNZ->rMemHdler.prExtMemHdr = pVDHandleInfo->prExtMemHdr;
    prVDMgrDNZ->rMemHdler.prIntMemHdr = pVDHandleInfo->prIntMexHdr;
    prVDMgrDNZ->rContainerInfo.u4ContainerHeight = pVDHandleInfo->prContainerInfo->u4ContainerHeight;
    prVDMgrDNZ->rContainerInfo.u4ContainerWidth  = pVDHandleInfo->prContainerInfo->u4ContainerWidth;

    if (_VideoDecoderScenarioTypeChecking(_prVideoDecoderMgr, pVDHandleInfo->eCodec, pVDHandleInfo->eScenario) == KAL_FALSE)
    {
        rVideoDecoderCompType.eErrorType = VIDEO_DECODER_ERROR_UNKNOWN_CODEC;
        rVideoDecoderCompType.pComponent = NULL;
        return rVideoDecoderCompType;
    }

    if (rVideoDecoderCompType.pComponent != NULL)
    {
        eError = rVideoDecoderCompType.pComponent->pfnInit();
        if (eError != VIDEO_ERROR_NONE)
        {
            rVideoDecoderCompType.eErrorType = VIDEO_DECODER_ERROR_INSUFFICIENT_MEMORY;
            rVideoDecoderCompType.pComponent = NULL;
            drv_trace0(TRACE_GROUP_10, VDEC_INIT_FAILED);
            return rVideoDecoderCompType;
        }
    }

    //Register codec schedule control
    VCodecCtrlRegister(VCS_DECODER, _VideoDecoderWakeUp);

    drv_trace4(TRACE_GROUP_10, VDEC_GET_HDLR, pVDHandleInfo->eCodec, pVDHandleInfo->eScenario, eError, 0);

    return rVideoDecoderCompType;
}


/*****************************************************************************
* Context:
*****************************************************************************/
VIDEO_ERROR_TYPE_T ReleaseVideoDecoderHandle(VIDEO_COMPONENT_TYPE_T *prHandle)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

#ifndef __VE_ROBUST_FLOW__
    if (prHandle != &rVideoDecoderComp)
    {
        eError = VIDEO_ERROR_INPUT_PARAM_ERROR;
        ASSERT(0);
        return eError;
    }
#endif

    eError = prHandle->pfnDeInit();

#ifdef __VE_KMV_SUPPORT__
    // Deinit KMV
    VideoDecoderKMVDeInit(&_prVideoDecoderMgr->rVDMgrDNZ.rKMVObj);
#endif

    //De-register codec schedule control
    VCodecCtrlDeRegister(VCS_DECODER);

    drv_trace1(TRACE_GROUP_8, VDEC_RELEASE_HDLR, eError);

#ifdef __VE_STKMGR_USER_FILTER_ENABLE__
    drv_gfx_stkmgr_unset_user_filter(SW_VIDEO_STACK_SIZE);
#endif

    return eError;
}


/*****************************************************************************
* Context:
*****************************************************************************/
void VideoDecoderMain(ilm_struct *prIlm)
{
#if 1
    VIDEO_START_LOGGING("VT");
    _VideoDecoderDataHdlr(prIlm);
    VIDEO_STOP_LOGGING("VT");
#else
    #if defined(__VE_MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
* This is not a good function prototype because there is no length information.
*
* Context:
*****************************************************************************/
void VideoDecoderSetDebug(kal_uint8 *string)
{
#ifdef VDEC_MEM_DBG
    kal_uint32 u4SetValue = 0;

    // process value
    if (string[0] == '0' && string[1] == 'x')
    {
        if (string[2] >= 'a')
        {
            u4SetValue = (string[2]-'a' + 10)*16;
        }
        else
        {
            u4SetValue = (string[2]-'0')*16;
        }

        if (string[3] >= 'a')
        {
            u4SetValue += (string[3]-'a' + 10);
        }
        else
        {
            u4SetValue += (string[3]-'0');
        }
    }

    eDebugMode = (VIDEO_DECODER_DEBUG_MODE_T)u4SetValue;

    drv_trace1(TRACE_GROUP_10, VDEC_SET_DBG, eDebugMode);
#endif  // VDEC_MEM_DBG
}


/*****************************************************************************
* Context:
*****************************************************************************/
void* VideoDecoderMalloc(kal_uint32 u4Size)
{
    return VideoDecoderMallocCacheLineAlign(u4Size, KAL_FALSE);
}


/*****************************************************************************
* Context:
*****************************************************************************/
void VideoDecoderFree(void *pVoid)
{
    VideoDecoderFreeCacheLineAlign(pVoid);
}


/*****************************************************************************
* Context:
*****************************************************************************/
void* VideoDecoderMallocCacheLineAlign(kal_uint32 u4Size, kal_bool fgCacheable)
{
    void *pVoid;
    VIDEO_DECODER_MGR_DNZ_T* prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;
    kal_uint32 u4NumBytes   = prVDMgrDNZ->u4NumBytesMalloced;
    kal_uint32 u4MemSize = 0;

    //Make sure all the allocation chche line aligned
    u4MemSize = ROUND_UP_TO_POWER_OF_TWO(u4Size, (kal_uint32)CPU_CACHE_LINE_SIZE);

    u4NumBytes += u4MemSize;

    if (fgCacheable == KAL_TRUE)
    {
        pVoid =  kal_adm_alloc_cacheable(prVDMgrDNZ->rAdmId, u4MemSize, CPU_CACHE_LINE_SIZE);
    }
    else
    {
        pVoid =  kal_adm_alloc_noncacheable(prVDMgrDNZ->rAdmId, u4MemSize, CPU_CACHE_LINE_SIZE);
    }

    if (pVoid == NULL)
    {
        kal_uint32 u4LeftSize = kal_adm_get_total_left_size(prVDMgrDNZ->rAdmId);

        drv_trace4(TRACE_GROUP_10, VDEC_MALLOC_FAIL, u4Size, u4LeftSize, u4NumBytes, (kal_uint32)prVDMgrDNZ->rAdmId);
    }
    else
    {
        // Succeed to Malloc
        drv_trace4(TRACE_GROUP_8, VDEC_MALLOC, u4Size, fgCacheable, u4NumBytes, (kal_uint32)pVoid);
    }

    return (void*)(pVoid);
}


/*****************************************************************************
* Context:
*****************************************************************************/
void VideoDecoderFreeCacheLineAlign(void *pVoid)
{
    kal_uint32 u4LeftSize;
    VIDEO_DECODER_MGR_DNZ_T* prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;

    drv_trace1(TRACE_GROUP_8, VDEC_MFREE, (kal_uint32)pVoid);

    if (NULL != pVoid)
    {
        u4LeftSize = kal_adm_get_total_left_size(prVDMgrDNZ->rAdmId);
        // Remove RW
        if (u4LeftSize < _prVideoDecoderMgr->rVDMgrDZ.u4MinLeftSize)
        {
            _prVideoDecoderMgr->rVDMgrDZ.u4MinLeftSize = u4LeftSize;
        }
        kal_adm_free(prVDMgrDNZ->rAdmId, (kal_uint8*)pVoid);
    }
}


/*****************************************************************************
* Context:
*****************************************************************************/
void *VideoDecoderMemSet(void *pVoid, kal_int32 u4Value, kal_uint32 u4Size)
{
    void *pDest = NULL;

    if (pVoid != NULL)
    {
        pDest = kal_mem_set(pVoid,u4Value,u4Size);
    }
    return pDest;
}


/*****************************************************************************
* Context:
*****************************************************************************/
void VideoDecoderMemCopy(void *pDest, void *pSrc, kal_uint32 u4Size)
{
    kal_mem_cpy(pDest, pSrc, u4Size);
}


/*****************************************************************************
* Context:
*****************************************************************************/
kal_uint32 VideoDecoderIntBuffer(kal_uint32 u4RequestSize)
{
    return VideoGetIntBuffer(_prVideoDecoderMgr->rVDMgrDNZ.rMemHdler.prIntMemHdr ,u4RequestSize);
}


/*****************************************************************************
* Context:
*****************************************************************************/
void VideoDecoderFreeIntMem(kal_uint8* pu1FreeAddr, kal_uint32 u4FreeSize)
{
    VideoFreeIntBuffer(_prVideoDecoderMgr->rVDMgrDNZ.rMemHdler.prIntMemHdr, pu1FreeAddr, u4FreeSize);
}


/*****************************************************************************
* Context:
*****************************************************************************/
void VideoDecoderResetIntBuffer(void)
{
    VideoResetIntBuffer(_prVideoDecoderMgr->rVDMgrDNZ.rMemHdler.prIntMemHdr);
}


/*****************************************************************************
* Context:
*****************************************************************************/
kal_bool VideoDecoderCheckIntBuffer(void)
{
    return GetVideoIntBufferInitStatus(_prVideoDecoderMgr->rVDMgrDNZ.rMemHdler.prIntMemHdr);
}


/*****************************************************************************
* Context:
*****************************************************************************/
VIDEO_CONTAINER_INFO_T* VideoDecoderGetContainerInfo(void)
{
    return &(_prVideoDecoderMgr->rVDMgrDNZ.rContainerInfo);
}


/*****************************************************************************
* This function is used in MJPEG subsampling.
*
* Context:
*****************************************************************************/
void VideoDecoderGetResizerFactor(VIDEO_RESIZE_FACTOR_TYPE_T* pResizeFactor)
{
    VIDEO_DECODER_RESIZER_SETTINGS_T rResizerSetting;

    if (pResizeFactor == NULL)
    {
        ASSERT(0);
    }

    // assign init value
    pResizeFactor->u4SelectedWidthFactor  = 1;
    pResizeFactor->u4SelectedHeightFactor = 1;

    VE_SLIM_LOG4(TRACE_GROUP_10, VDEC_RESIZER_DATA, LCD_WIDTH,
                                                    LCD_HEIGHT,
                                                    pResizeFactor->u4MinAvailableFactor,
                                                    pResizeFactor->u4MaxAvailableFactor);

    if (KAL_TRUE == VideoDecoderGetResizerSetting(&rResizerSetting))
    {
        if (pResizeFactor->u4SrcWidth*pResizeFactor->u4SrcHeight <= rResizerSetting.u4MaxWidth*rResizerSetting.u4MaxHeight)
        {
            if (pResizeFactor->u4MaxAvailableFactor >= 4 &&
                pResizeFactor->u4SrcWidth*pResizeFactor->u4SrcHeight > rResizerSetting.u4MaxQtyWidth*rResizerSetting.u4MaxQtyHeight)
            {
                pResizeFactor->u4SelectedWidthFactor  = 4;
                pResizeFactor->u4SelectedHeightFactor = 4;
            }
            else if (pResizeFactor->u4MaxAvailableFactor >= 2 &&
                     pResizeFactor->u4SrcWidth*pResizeFactor->u4SrcHeight >rResizerSetting.u4MaxNormalWidth*rResizerSetting.u4MaxNormalHeight)
            {
                pResizeFactor->u4SelectedWidthFactor  = 2;
                pResizeFactor->u4SelectedHeightFactor = 2;
            }
        }
    }

    drv_trace4(TRACE_GROUP_10, VDEC_RESIZER_FACTOR, pResizeFactor->u4SrcWidth,
                                                    pResizeFactor->u4SrcHeight,
                                                    pResizeFactor->u4SelectedWidthFactor,
                                                    pResizeFactor->u4SelectedHeightFactor);
}


/*****************************************************************************
* Context:
*****************************************************************************/
kal_bool VideoDecoderSetYUVBuffer(kal_uint32* pu4Width,
                              kal_uint32* pu4Height,
                              kal_uint8 u1Alignment,
                              kal_uint32 u4Offset,
                              kal_uint32 u4ReduceLength)
{
    kal_uint8* pu1BufferStartAddr = NULL;
    kal_uint32 u4OriWidth = *pu4Width;
    kal_uint32 u4OriHeight = *pu4Height;
    kal_uint32 u4RoundUpOffset = 0;
    kal_uint32 u4AdjustedYUVBufferTotalSize = 0;
    kal_uint32 u4BufferNumber = 0;
    kal_uint32 u4AlignValue;
    kal_uint32 u4OneYUVBufferSize;
    VIDEO_DECODER_MGR_DNZ_T* prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;
    VIDEO_DECODER_MGR_DZ_T* prVDMgrDZ = &_prVideoDecoderMgr->rVDMgrDZ;
    kal_bool ret = KAL_TRUE;

    if ((u1Alignment == 0) || ((*pu4Width) == 0) || ((*pu4Height)== 0))
    {
        ASSERT(0);
    }

    if (prVDMgrDZ->fgInitBuffer == KAL_FALSE)
    {
        // set YUV buffer first time
        pu1BufferStartAddr = prVDMgrDNZ->pu1YUVBufferStartAddr;

        if (pu1BufferStartAddr != NULL)
        {
            if (CPU_CACHE_LINE_SIZE>u1Alignment)
            {
                u4AlignValue = CPU_CACHE_LINE_SIZE;

#ifndef __VE_ROBUST_FLOW__
                if ((CPU_CACHE_LINE_SIZE % u1Alignment) != 0)
                {
                    ASSERT(0);
                }
#endif
            }
            else
            {
                u4AlignValue = u1Alignment;

#ifndef __VE_ROBUST_FLOW__
                if ((u1Alignment % CPU_CACHE_LINE_SIZE) != 0)
                {
                    ASSERT(0);
                }
#endif
            }

            pu1BufferStartAddr += u4Offset;

            u4OriWidth = ROUND_UP_TO_POWER_OF_TWO(u4OriWidth, 16);
            u4OriHeight = ROUND_UP_TO_POWER_OF_TWO(u4OriHeight, 16);

            u4OneYUVBufferSize = (u4OriWidth)*(u4OriHeight)*3/2;

            if((u4OneYUVBufferSize % u4AlignValue) != 0)
            {
                u4OneYUVBufferSize = ((u4OneYUVBufferSize + u4AlignValue - 1) / u4AlignValue) * u4AlignValue;
            }

            if(((kal_uint32)(pu1BufferStartAddr) % u4AlignValue) != 0)
            {
                pu1BufferStartAddr = (kal_uint8*)((((kal_uint32)(pu1BufferStartAddr) + u4AlignValue - 1) / u4AlignValue) * u4AlignValue);
            }

            u4RoundUpOffset = (kal_uint32)(pu1BufferStartAddr) - (kal_uint32)(prVDMgrDNZ->pu1YUVBufferStartAddr);
            u4AdjustedYUVBufferTotalSize = prVDMgrDNZ->u4YUVBufferTotalSize - u4ReduceLength - u4RoundUpOffset;

            if((u4AdjustedYUVBufferTotalSize % u4AlignValue) != 0)
            {
                u4AdjustedYUVBufferTotalSize = (u4AdjustedYUVBufferTotalSize / u4AlignValue) * u4AlignValue;
            }

#ifdef __VE_IMPROVE_RESIZER__
            // To improve 6235 resizer, we deliver cacheable YUV buffer
            if (VideoCommIsExtBufferCacheable((kal_uint32)(pu1BufferStartAddr) , u4AdjustedYUVBufferTotalSize) == KAL_FALSE)
            {
                pu1BufferStartAddr = (kal_uint8*) VideoCommExtBufferCacheableSwitch((kal_uint32)(pu1BufferStartAddr) , u4AdjustedYUVBufferTotalSize, VIDEO_CACHEABLE);
            }
#else
            if (VideoCommIsExtBufferCacheable((kal_uint32)(pu1BufferStartAddr) , u4AdjustedYUVBufferTotalSize) == KAL_TRUE)
            {
                pu1BufferStartAddr = (kal_uint8*) VideoCommExtBufferCacheableSwitch((kal_uint32)(pu1BufferStartAddr) , u4AdjustedYUVBufferTotalSize, VIDEO_NON_CACHEABLE);
            }
#endif

            u4BufferNumber = VideoDecoderInitYUVBuffer(pu1BufferStartAddr, u4AdjustedYUVBufferTotalSize, u4OneYUVBufferSize, &prVDMgrDNZ->rYUVBufferMgr);

            // Minimum YUV buffer number is 4.  2 of them would be taken by scheduler and 2 of them would be taken by codec
            // For preview, not check the buffer number
            if ((u4BufferNumber < 3 && prVDMgrDNZ->eScenario != VIDEO_SCENARIO_PREVIEW && prVDMgrDNZ->eScenario != VIDEO_SCENARIO_PREVIEW_KMV) ||
                (u4BufferNumber < 1 && prVDMgrDNZ->eScenario == VIDEO_SCENARIO_PREVIEW)
#ifdef __VE_KMV_SUPPORT__
                || (u4BufferNumber < 1 && prVDMgrDNZ->eScenario == VIDEO_SCENARIO_PREVIEW_KMV)
#endif                
                )
            {
                VIDEO_ERROR_TYPE_T eError;
                //drv_trace1(TRACE_GROUP_10, VDEC_NOT_SUPPORT, __LINE__);
                drv_trace4(TRACE_GROUP_10, VDEC_SET_YUV_NOT_SUPPORT, u4BufferNumber,
                    *((kal_uint32*)pu4Width),
                    *((kal_uint32*)pu4Height),
                    prVDMgrDNZ->u4YUVBufferTotalSize);

                eError = prVDMgrDNZ->rCommState.prCallback->pfnEventHandler(VIDEO_EVENT_ERROR, VIDEO_COMMAND_NOTIFY, NULL, NULL);
                VE_SLIM_LOG1(TRACE_GROUP_10, VDEC_CALLBACK, VIDEO_EVENT_ERROR);
                VE_UNUSED(eError);
                prVDMgrDZ->fgFail2SetYUV =  KAL_TRUE;
		return KAL_FALSE;
            }
            else
            {
                prVDMgrDZ->fgInitBuffer = KAL_TRUE;
                // Notify CCU about the result of set-YUV
                VFC_IOCtrl(VFC_OP_VD_TOTAL_YUV_NUM, (void*)&u4BufferNumber, NULL, NULL);
            }
        }
        else
        {
            // No memories for YUV buffer
            ASSERT(0);
        }
    }
    else
    {
        // Set YUV buffer multiple times, will support later when needed
        ASSERT(0);
    }

    return ret;
}


/*****************************************************************************
* Context:
*****************************************************************************/
kal_uint8* VideoDecoderGetYUVBuffer(void)
{
    kal_uint8* pu1BufferAddr = NULL;
    kal_uint8 u1ArrayIdx;
    VIDEO_DECODER_MGR_DNZ_T* prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;
    VIDEO_YUV_BUFFER_T* pYUVBufferMgr = &prVDMgrDNZ->rYUVBufferMgr;
    VIDEO_BUFFERHEADER_TYPE_T* pNewestInputBufferHeader = &prVDMgrDNZ->rNewestInputBufferHeader;

    if (_prVideoDecoderMgr->rVDMgrDZ.fgInitBuffer == KAL_TRUE)
    {
        drv_trace1(TRACE_GROUP_9, VDEC_GET_FRAME_TIMESTAMP, pNewestInputBufferHeader->u8TimeStamp);

        pu1BufferAddr = VideoDecGetYUVBuffer(pYUVBufferMgr);
        u1ArrayIdx = VideoDecoderGetYUVBufferIdx(pu1BufferAddr, pYUVBufferMgr);

        drv_trace1(TRACE_GROUP_9, VDEC_GET_FRAME_ADD, (kal_uint32)(pu1BufferAddr));

        _prVideoDecoderMgr->rVDMgrDZ.u4FramesCodecGet++;
        if (u1ArrayIdx < VIDEO_DECODER_MAX_YUV_BUF_NUM)
        {
            VIDEO_BUFFERHEADER_TYPE_T *prBufferHeader = &prVDMgrDNZ->prInfoExtMem->arUnsentBufferHeader[u1ArrayIdx];
            kal_mem_cpy((void*)(prBufferHeader), (void*)(pNewestInputBufferHeader), sizeof(*prBufferHeader));

#ifdef __VE_KMV_SUPPORT__
            
            if (_prVideoDecoderMgr->rVDMgrDNZ.rKMVObj.fg_kmv_inited == KAL_TRUE && prVDMgrDNZ->eCodec == CODEC_H264)
            {
                // Copy the KMV meta and prepare for post-processing @ _VideoDecoderGetDisplay2Send()

                KMV_PRIVATE_PAYLOAD_T* prKMVMetaDataAddr = ((KMV_PRIVATE_PAYLOAD_T*)pNewestInputBufferHeader->pPrivateData)->pu1KMVPayloadAddress;                                
                kal_uint32 u4KMVSize = ((KMV_PRIVATE_PAYLOAD_T*)pNewestInputBufferHeader->pPrivateData)->u4KMVSize;

                VE_SLIM_LOG2(TRACE_GROUP_10, VDEC_TXTMAP_INFO, ((kmv_meta_st*)prKMVMetaDataAddr)->nsize, (kal_uint32)pNewestInputBufferHeader->u8TimeStamp);
                
                if (NULL != prKMVMetaDataAddr && u4KMVSize > 0)
                {
                    kmv_meta_st *prUnsentKMVMetaData = &prVDMgrDNZ->prInfoExtMem->arKMVMetaData[u1ArrayIdx];

                    kal_mem_cpy((void*)(prUnsentKMVMetaData), (void*)(prKMVMetaDataAddr), u4KMVSize);                    

                    // To indicate this KMV meta had been stored.
                    ((KMV_PRIVATE_PAYLOAD_T*)pNewestInputBufferHeader->pPrivateData)->u4KMVSize = 0;
                }
            }
            
#endif
        }
        else
        {
            // Out-of-boundary access
            ASSERT(0);
        }
    }
    else
    {
        // Get buffer before buffer initialization
        ASSERT(0);
    }

    _VideoDecoderUpdateYUVInfoToCCU();
    return pu1BufferAddr;
}


/*****************************************************************************
* Context:
*****************************************************************************/
kal_bool VideoDecoderRefFreeYUVBuffer(kal_uint8* pu1BufferAddr)
{
    drv_trace1(TRACE_GROUP_9, VDEC_FREE_FRAME_REF, (kal_uint32)(pu1BufferAddr));
    return VideoDecYUVBufRefFree(pu1BufferAddr, &_prVideoDecoderMgr->rVDMgrDNZ.rYUVBufferMgr);
}


/*****************************************************************************
* Context:
*****************************************************************************/
kal_bool VideoDecoderDisplayFreeYUVBuffer(kal_uint8* pu1BufferAddr)
{
    drv_trace1(TRACE_GROUP_9, VDEC_FREE_FRAME_DIS, (kal_uint32)(pu1BufferAddr));

    // Notify CCU about the current display number
    _VideoDecoderUpdateYUVInfoToCCU();

    return VideoDecYUVBufDisFree(pu1BufferAddr, &_prVideoDecoderMgr->rVDMgrDNZ.rYUVBufferMgr);
}


/*****************************************************************************
* Context:
*****************************************************************************/
kal_uint64 VideoDecoderGetCurrPlayTime(void)
{
    if (KAL_TRUE == _prVideoDecoderMgr->rVDMgrDZ.fgBuffering)
    {
        // MJPEG codec will refer this value to proceed frame-dropping.
        // Return 0 will make MJPEG codec decode all frames.
        return 0;
    }

    return _prVideoDecoderMgr->rVDMgrDZ.u8CurrentPlayTime;
}


/*****************************************************************************
* Context:
*****************************************************************************/
kal_uint64 VideoDecoderGetLastDeliverTime(void)
{
    return _prVideoDecoderMgr->rVDMgrDZ.u8TimeStampOfLastDecodedFrm;
}


/*****************************************************************************
* Context:
*****************************************************************************/
kal_uint32 VideoDecoderGetAvialableCodec(void)
{
    return _VideoDecoderGetAvialableCodec();
}


/*****************************************************************************
* Context:
*****************************************************************************/
kal_uint32 VideoDecoderGetAvailableYUV(void)
{
    return VideoDecoderGetAvailableYUVNumber(&_prVideoDecoderMgr->rVDMgrDNZ.rYUVBufferMgr);
}


/*****************************************************************************
* Context:
*****************************************************************************/
kal_uint32 VideoDecoderGetAvailableDisplay(void)
{
    return VideoDecoderGetAvailableDisplayNumber(&_prVideoDecoderMgr->rVDMgrDNZ.rYUVBufferMgr);
}


/*****************************************************************************
* Context:
*****************************************************************************/
kal_uint32 VideoDecoderGetRealAvailableDisplay(void)
{
    return VideoDecoderGetRealAvailableDisplayNumber(&_prVideoDecoderMgr->rVDMgrDNZ.rYUVBufferMgr);
}


/*****************************************************************************
* Context:
*****************************************************************************/
kal_uint32 VideoDecoderGetTotalYUV(void)
{
    return VideoDecGetTotalYUVNumber(&_prVideoDecoderMgr->rVDMgrDNZ.rYUVBufferMgr); //_prVideoDecoderMgr->rVDMgrDNZ.rYUVBufferMgr.u4TotalNum;
}


/*****************************************************************************
* Context:
*****************************************************************************/
kal_bool VideoDecodecIsYUVBufferInit(void)
{
    return VideoDecIsYUVBufferInit(&_prVideoDecoderMgr->rVDMgrDNZ.rYUVBufferMgr);
}


/*****************************************************************************
* Context:
*****************************************************************************/
void VideoDecoderReturnBitstream(kal_uint8* pu1Addr, kal_uint32 u4Length)
{
    VIDEO_DECODER_MGR_DNZ_T* prVDMgrDNZ = &_prVideoDecoderMgr->rVDMgrDNZ;
    kal_uint8 u1Index = prVDMgrDNZ->u1ReturnBitstremIndex;
    kal_uint8 u1Count = 0;
    void* pVoid = NULL;
    kal_uint32 u4SavedMask = 0;

    VIDEO_DECODER_BS_BUFFER_ATOM_T *pRB = prVDMgrDNZ->prInfoExtMem->arReturningBitstream;

    do
    {
        //if (_prVideoDecoderMgr->rVDMgrDNZ.prInfoExtMem->arReturningBitstream[u1Index].rBufferHeader.pu1Buffer == pu1Addr)
        if ((pRB+u1Index)->rBufferHeader.pu1Buffer == pu1Addr)
        {
            break;
        }

        u1Index = (u1Index + 1) % VIDEO_DECODER_RETURN_BS_BUFFER_Q_NUM;
        u1Count++;
    } while(u1Count < VIDEO_DECODER_RETURN_BS_BUFFER_Q_NUM);

    if (u1Count == VIDEO_DECODER_RETURN_BS_BUFFER_Q_NUM)
    {
        ASSERT(0);
    }

    if ((pRB + u1Index)->rBufferHeader.u4BuffSize != u4Length)
    {
        ASSERT(0);
    }

    u4SavedMask = SaveAndSetIRQMask();
    (pRB+u1Index)->fgReturned = KAL_TRUE;
    _prVideoDecoderMgr->rVDMgrDZ.fgBitstreamQFull = KAL_FALSE;

    prVDMgrDNZ->u1ReturnBitstremIndex = u1Index;
    RestoreIRQMask(u4SavedMask);

    // Temporarily, we assumed the bitstream would return in order
    //_VideoDecoderCheckReturnBitstreamOrder(u1Index);

    _VideoDecoderWakeUp(pVoid);
}


/*****************************************************************************
* Context:
*****************************************************************************/
void VideoDecoderGetCustomSetting(void* pVoid)
{
    _VideoDecoderGetCustomSetting(_prVideoDecoderMgr, pVoid);
}


#ifdef __VE_DCM_WITH_COMPRESSION__
#pragma arm section code, rodata
#endif  // __VE_DCM_WITH_COMPRESSION__


/*****************************************************************************
* Context:
*****************************************************************************/
// Non DCM usage+
void VideoDecoderMainNonDCM(ilm_struct *prIlm)
{
    // Process Decoder normal jobs
    VideoDecoderMain(prIlm);

    // Check if we should close Decoder
    // Split 'normal jobs' and 'close' to avoid DCM page fault issues
    if (KAL_TRUE == _prVideoDecoderMgr->rVDMgrDZ.fgClosingDecoder)
    {
        if (VideoCommCheckProcessing(&_prVideoDecoderMgr->rVDMgrDNZ.rCommState) == KAL_FALSE)
        {
            VideoCommChangeState(&_prVideoDecoderMgr->rVDMgrDNZ.rCommState, VIDEO_STATE_CLOSE);
        }
    }

}
// Non DCM usage -


#endif  /* __VE_VIDEO_ARCHI_V2__ */

