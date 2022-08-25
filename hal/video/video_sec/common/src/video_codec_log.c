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
 *   video_codec_log.c
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
 ****************************************************************************/
#include "drv_comm.h"

#ifdef __VIDEO_ARCHI_V2__
 
#if defined(__MPEG4_DEC_SW_SUPPORT__) || defined(__H264_DEC_SW_SUPPORT__) || \
    defined(__RV_DEC_SW_SUPPORT__) || defined(__MPEG4_ENC_SW_SUPPORT__)

#include "vcodec_log.h"
#include "vcodec_v2_trc.h"

#ifdef __VE_MM_DCM_SUPPORT__
#include "dcmgr.h" //DCM

#pragma arm section code = "DYNAMIC_CODE_VECOM_ROCODE", rodata = "DYNAMIC_CODE_VECOM_RODATA"
#endif

void VideoTraceLog0(VCODEC_LOG_GROUP_T eGroup, VCODEC_LOG_INDEX_T eIndex)
{
    switch (eIndex)
    {
    //case VCODEC_LOG_INDEX_XXX:
    //    drv_trace0(TRACE_GROUP_7, XXX_XXX);
    //break;
	case VCODEC_LOG_INDEX_RMDEC_CLOSE:
		drv_trace0(TRACE_GROUP_7, RMDEC_CLOSE);
		break;
	case VCODEC_LOG_INDEX_RMDEC_STANDARD_DEC:
		drv_trace0(TRACE_GROUP_7, RMDEC_STANDARD_DEC);
		break;
	case VCODEC_LOG_INDEX_RMDEC_LOSSY_DEC:
		drv_trace0(TRACE_GROUP_7, RMDEC_LOSSY_DEC);
		break;
	case VCODEC_LOG_INDEX_RMDEC_OPEN:
		drv_trace0(TRACE_GROUP_7, RMDEC_OPEN);
		break;
	/* H.264 DECODER */	
	case VCODEC_LOG_INDEX_H264DEC_OPEN:
		drv_trace0(TRACE_GROUP_7, H264DEC_OPEN);
		break;
	case VCODEC_LOG_INDEX_H264DEC_INIT:
		drv_trace0(TRACE_GROUP_7, H264DEC_INIT);
		break;
	case VCODEC_LOG_INDEX_H264DEC_DEINIT:
		drv_trace0(TRACE_GROUP_7, H264DEC_DEINIT);
		break;
	case VCODEC_LOG_INDEX_H264DEC_CLOSE:
		drv_trace0(TRACE_GROUP_7, H264DEC_CLOSE);
		break;
	case VCODEC_LOG_INDEX_H264DEC_SUPPORT_ERROR:
		drv_trace0(TRACE_GROUP_7, H264DEC_SUPPORT_ERROR);
		break;
	case VCODEC_LOG_INDEX_H264DEC_CHANGE_SPS:
		drv_trace0(TRACE_GROUP_7, H264DEC_CHANGE_SPS);
		break;
	case VCODEC_LOG_INDEX_H264DEC_DECODE_ERROR:
		drv_trace0(TRACE_GROUP_7, H264DEC_DECODE_ERROR);
		break;	

	case VCODEC_LOG_INDEX_COMMON_0: 
		drv_trace0(TRACE_GROUP_7, SWVCODEC_COMMON_0);
		break;
	case VCODEC_LOG_INDEX_MAX: break;
	default: break;
    }
}

void VideoTraceLog1(VCODEC_LOG_GROUP_T eGroup, VCODEC_LOG_INDEX_T eIndex, UINT64 arg)
{
    switch (eIndex)
    {
    //case VCODEC_LOG_INDEX_XXX:
    //    drv_trace1(TRACE_GROUP_7, XXX_XXX, arg);
    //break;
    case VCODEC_LOG_INDEX_MP4ENC_ENCODE_ERROR:    
        drv_trace1(TRACE_GROUP_7, MP4ENC_ENCODE_ERROR, arg);
        break;
    case VCODEC_LOG_INDEX_MP4ENC_ERROR_GET_BITSTREAM:
        drv_trace1(TRACE_GROUP_7, MP4ENC_ERROR_GET_BITSTREAM, arg);
        break;
    case VCODEC_LOG_INDEX_MP4ENC_FREE_EXT_MEMORY:
        drv_trace1(TRACE_GROUP_7, MP4ENC_FREE_EXT_MEMORY, arg);
        break;
    case VCODEC_LOG_INDEX_MP4ENC_QPHDR:
        drv_trace1(TRACE_GROUP_7, MP4ENC_QPHDR, arg);
        break;
    case VCODEC_LOG_INDEX_RMDEC_DECODE_ERROR:    
        drv_trace1(TRACE_GROUP_7, RMDEC_DECODE_ERROR, arg); 
        break;
    case VCODEC_LOG_INDEX_RMDEC_UNKNOW_ERROR:
        drv_trace1(TRACE_GROUP_7, RMDEC_UNKNOW_ERROR, arg);
        break;
    case VCODEC_LOG_INDEX_RMDEC_HOLD_PIC_TYPE_ERROR:
        drv_trace1(TRACE_GROUP_7, RMDEC_HOLD_PIC_TYPE_ERROR, arg);
        break;
    /* MPEG4 DECODER */
    case VCODEC_LOG_INDEX_MP4DEC_DECODE_ERROR:
        drv_trace1(TRACE_GROUP_7, MP4DEC_DECODE_ERROR, arg);
        break;      
    case VCODEC_LOG_INDEX_MP4DEC_SET_FRAME_RATE:
        drv_trace1(TRACE_GROUP_7, MP4DEC_SET_FRAME_RATE, arg);
        break;
    case VCODEC_LOG_INDEX_MP4DEC_SET_BIT_RATE:
        drv_trace1(TRACE_GROUP_7, MP4DEC_SET_BIT_RATE, arg);
        break;
    case VCODEC_LOG_INDEX_MP4DEC_DECODE_EOF:
        drv_trace1(TRACE_GROUP_7, MP4DEC_DECODE_EOF, arg);
        break;
    case VCODEC_LOG_INDEX_MP4DEC_DECODE_FIRST_FRAME:
        drv_trace1(TRACE_GROUP_7, MP4DEC_DECODE_FIRST_FRAME, arg);
        break;
    /* H.264 DECODER */	
    case VCODEC_LOG_INDEX_H264DEC_INIT_ERROR:    
        drv_trace1(TRACE_GROUP_7, H264DEC_INIT_ERROR, arg);
        break;
    case VCODEC_LOG_INDEX_H264DEC_PAYLOAD_INFO:    
        drv_trace1(TRACE_GROUP_7, H264DEC_PAYLOAD_INFO, arg);
        break;
    case VCODEC_LOG_INDEX_H264DEC_HEADER_ERROR:    
        drv_trace1(TRACE_GROUP_7, H264DEC_HEADER_ERROR, arg);
        break;
    case VCODEC_LOG_INDEX_H264DEC_ALLOCATE_ERROR:    
        drv_trace1(TRACE_GROUP_7, H264DEC_ALLOCATE_ERROR, arg);
        break;
    case VCODEC_LOG_INDEX_H264DEC_ARGUMENT_ERROR:    
        drv_trace1(TRACE_GROUP_7, H264DEC_ARGUMENT_ERROR, arg);
        break;
    case VCODEC_LOG_INDEX_H264DEC_OUTPUT_IDR:    
        drv_trace1(TRACE_GROUP_7, H264DEC_OUTPUT_IDR, arg);
        break;		
    case VCODEC_LOG_INDEX_COMMON_1: 
        drv_trace1(TRACE_GROUP_7, SWVCODEC_COMMON_1, arg);
        break;
    /* INDEX MAX */
    case VCODEC_LOG_INDEX_MAX: break;
    default: break;
    }
}

void VideoTraceLog2(VCODEC_LOG_GROUP_T eGroup, VCODEC_LOG_INDEX_T eIndex, UINT64 arg1, UINT64 arg2)
{
    switch (eIndex)
    {
    //case VCODEC_LOG_INDEX_XXX:
    //    drv_trace2(TRACE_GROUP_7, XXX_XXX, arg1, arg2);
    //break;    
    case VCODEC_LOG_INDEX_MP4ENC_ALLOCATE_EXT_MEMORY:
        drv_trace2(TRACE_GROUP_7, MP4ENC_ALLOCATE_EXT_MEMORY, arg1, arg2);
        break;
    case VCODEC_LOG_INDEX_RMDEC_ERROR_FRM:
        drv_trace2(TRACE_GROUP_7, RMDEC_ERROR_FRM, arg1, arg2);
        break;
    case VCODEC_LOG_INDEX_RMDEC_SKIP_FRM:
        drv_trace2(TRACE_GROUP_7, RMDEC_SKIP_FRM, arg1, arg2);
        break;
    case VCODEC_LOG_INDEX_RMDEC_UNSUPPORT:
        drv_trace2(TRACE_GROUP_7, RMDEC_UNSUPPORT, arg1, arg2);
        break; 
		/* MPEG4 DECODER */
    case VCODEC_LOG_INDEX_MP4DEC_DECODE_RESOLUTION:
        drv_trace2(TRACE_GROUP_7, MP4DEC_DECODE_RESOLUTION, arg1, arg2);
        break;
    /* H.264 DECODER */	
    case VCODEC_LOG_INDEX_H264DEC_DECODE_RESULT:    
        drv_trace2(TRACE_GROUP_7, H264DEC_DECODE_RESULT, arg1, arg2);
        break;
    case VCODEC_LOG_INDEX_SWH264DEC_CONCEAL:    
        drv_trace2(TRACE_GROUP_7, SWH264DEC_CONCEAL, arg1, arg2);
        break;
    case VCODEC_LOG_INDEX_SWH264DEC_LOSSY_INIT_DSWITCH:    
        drv_trace2(TRACE_GROUP_7, SWH264DEC_LOSSY_INIT_DSWITCH, arg1, arg2);
        break;				
    case VCODEC_LOG_INDEX_COMMON_2: 
        drv_trace2(TRACE_GROUP_7, SWVCODEC_COMMON_2, arg1, arg2);
        break;
    /* INDEX MAX */
    case VCODEC_LOG_INDEX_MAX: break;
    default: break;
    }
}

void VideoTraceLog4(VCODEC_LOG_GROUP_T eGroup, VCODEC_LOG_INDEX_T eIndex, UINT64 arg1, UINT64 arg2, UINT64 arg3, UINT64 arg4)
{
    switch (eIndex)
    {
    //case VCODEC_LOG_INDEX_XXX:
    //    drv_trace0(TRACE_GROUP_7, XXX_XXX, arg1, arg2, arg3, arg4);
    //break;    
    case VCODEC_LOG_INDEX_MP4ENC_FRAMETYPE:
        drv_trace4(TRACE_GROUP_7, MP4ENC_FRAMETYPE, arg1, arg2, arg3, arg4);
        break;
    case VCODEC_LOG_INDEX_MP4ENC_SETTING:
        drv_trace4(TRACE_GROUP_7, MP4ENC_SETTING, arg1, arg2, arg3, arg4);
        break;
    case VCODEC_LOG_INDEX_MP4ENC_GET_BITSTREAM:
        drv_trace4(TRACE_GROUP_7, MP4ENC_GET_BITSTREAM, arg1, arg2, arg3, arg4);
        break;
    case VCODEC_LOG_INDEX_RMDEC_DECODE_RESULT1:
        drv_trace4(TRACE_GROUP_7, RMDEC_DECODE_RESULT1, arg1, arg2, arg3, arg4); 
        break;
    case VCODEC_LOG_INDEX_RMDEC_TIMESTAMP1:
        drv_trace4(TRACE_GROUP_7, RMDEC_TIMESTAMP1, arg1, arg2, arg3, arg4);
        break;
    case VCODEC_LOG_INDEX_RMDEC_TIMESTAMP2:
        drv_trace4(TRACE_GROUP_7, RMDEC_TIMESTAMP2, arg1, arg2, arg3, arg4);
        break;
    case VCODEC_LOG_INDEX_RMDEC_UNSUPPORT:
        drv_trace4(TRACE_GROUP_7, RMDEC_UNSUPPORT, arg1, arg2, arg3, arg4);
        break;      
    /* MPEG4 DECODER */
    case VCODEC_LOG_INDEX_MP4DEC_DECODE_VOP_TYPE:
        drv_trace4(TRACE_GROUP_7, MP4DEC_DECODE_VOP_TYPE, arg1, arg2, arg3, arg4);
        break;      
    case VCODEC_LOG_INDEX_SWMP4DEC_SPEEDY_INIT_QTY:
        drv_trace4(TRACE_GROUP_7, SWMP4DEC_LOSSY_INIT_QTY, arg1, arg2, arg3, arg4);
        break;
    case VCODEC_LOG_INDEX_SWMP4DEC_SPEEDY_INIT_DSWITCH:
        drv_trace4(TRACE_GROUP_7, SWMP4DEC_LOSSY_INIT_DSWITCH, arg1, arg2, arg3, arg4);
        break;
    case VCODEC_LOG_INDEX_SWMP4DEC_SPEEDY_SWITCH_QTY:
        drv_trace4(TRACE_GROUP_7, SWMP4DEC_LOSSY_SWITCH_QTY, arg1, arg2, arg3, arg4);
        break;
    /* H.264 DECODER */	
    case VCODEC_LOG_INDEX_H264DEC_TIMESTAMP_INIT:    
        drv_trace4(TRACE_GROUP_7, H264DEC_TIMESTAMP_INIT, arg1, arg2, arg3, arg4);
        break;
    case VCODEC_LOG_INDEX_H264DEC_BITSTREAM_INFO:    
        drv_trace4(TRACE_GROUP_7, H264DEC_BITSTREAM_INFO, arg1, arg2, arg3, arg4);
        break;
    case VCODEC_LOG_INDEX_H264DEC_TIMESTAMP_MPHP:    
        drv_trace4(TRACE_GROUP_7, H264DEC_TIMESTAMP_MPHP, arg1, arg2, arg3, arg4);
        break;
    case VCODEC_LOG_INDEX_H264DEC_TIMESTAMP_INFO:    
        drv_trace4(TRACE_GROUP_7, H264DEC_TIMESTAMP_INFO, arg1, arg2, arg3, arg4);
        break;
    case VCODEC_LOG_INDEX_H264DEC_TIMESTAMP:    
        drv_trace4(TRACE_GROUP_7, H264DEC_TIMESTAMP, arg1, arg2, arg3, arg4);
        break;
    case VCODEC_LOG_INDEX_H264DEC_TIMESTAMP_STATUS:    
        drv_trace4(TRACE_GROUP_7, H264DEC_TIMESTAMP_STATUS, arg1, arg2, arg3, arg4);
        break;
    case VCODEC_LOG_INDEX_H264DEC_TIMESTAMP_BP:    
        drv_trace4(TRACE_GROUP_7, H264DEC_TIMESTAMP_BP, arg1, arg2, arg3, arg4);
        break;
    case VCODEC_LOG_INDEX_H264DEC_DISPLAY_INFO:    
        drv_trace4(TRACE_GROUP_7, H264DEC_DISPLAY_INFO, arg1, arg2, arg3, arg4);
        break;
    case VCODEC_LOG_INDEX_H264DEC_CROP_INFO:    
        drv_trace4(TRACE_GROUP_7, H264DEC_CROP_INFO, arg1, arg2, arg3, arg4);
        break;
    case VCODEC_LOG_INDEX_SWH264DEC_LOSSY_SWITCH_QTY:    
        drv_trace4(TRACE_GROUP_7, SWH264DEC_LOSSY_SWITCH_QTY, arg1, arg2, arg3, arg4);
        break;	
    case VCODEC_LOG_INDEX_SWH264DEC_MEM_ALLOCATE:    
        drv_trace4(TRACE_GROUP_7, SWH264DEC_MEM_ALLOCATE, arg1, arg2, arg3, arg4);
        break;
    case VCODEC_LOG_INDEX_SWH264DEC_DPB_MARK_REFPIC:    
        drv_trace4(TRACE_GROUP_7, SWH264DEC_DPB_MARK_REFPIC, arg1, arg2, arg3, arg4);
        break;
    case VCODEC_LOG_INDEX_SWH264DEC_DPB_INIT:    
        drv_trace4(TRACE_GROUP_7, SWH264DEC_DPB_INIT, arg1, arg2, arg3, arg4);
        break;
    case VCODEC_LOG_INDEX_SWH264DEC_SPSDPB_CHECK:    
        drv_trace4(TRACE_GROUP_7, SWH264DEC_SPSDPB_CHECK, arg1, arg2, arg3, arg4);
        break;
    case VCODEC_LOG_INDEX_SWH264DEC_LOSSY_INIT_QTY:    
        drv_trace4(TRACE_GROUP_7, SWH264DEC_LOSSY_INIT_QTY, arg1, arg2, arg3, arg4);
        break;
    case VCODEC_LOG_INDEX_SWH264DEC_OUTPIC1:    
        drv_trace4(TRACE_GROUP_7, SWH264DEC_OUTPIC1, arg1, arg2, arg3, arg4);
        break;
    case VCODEC_LOG_INDEX_SWH264DEC_OUTPIC2:    
        drv_trace4(TRACE_GROUP_7, SWH264DEC_OUTPIC2, arg1, arg2, arg3, arg4);
        break;		
    case VCODEC_LOG_INDEX_SWH264DEC_EARLIER_OUTPUT:    
        drv_trace4(TRACE_GROUP_7, SWH264DEC_EARLIER_OUTPUT, arg1, arg2, arg3, arg4);
        break;		        
    case VCODEC_LOG_INDEX_SWH264DEC_EARLIER_OUTPUT_POC:    
        drv_trace4(TRACE_GROUP_7, SWH264DEC_EARLIER_OUTPUT_POC, arg1, arg2, arg3, arg4);
        break;		                
    case VCODEC_LOG_INDEX_SWH264DEC_BSDDECODE_OUTPUT:    
        drv_trace4(TRACE_GROUP_7, SWH264DEC_BSDDECODE_OUTPUT, arg1, arg2, arg3, arg4);
        break;		                
    case VCODEC_LOG_INDEX_H264DEC_INPUT_TIMEINFO:    
        drv_trace4(TRACE_GROUP_7, H264DEC_INPUT_TIMEINFO, arg1, arg2, arg3, arg4);
        break;				
    /* VP8 DECODER */		
    case VCODEC_LOG_INDEX_VP8DEC_OPEN:
        drv_trace4(TRACE_GROUP_7, VP8DEC_OPEN, arg1, arg2, arg3, arg4);	
        break;	
    case VCODEC_LOG_INDEX_VP8DEC_CLOSE:
        drv_trace4(TRACE_GROUP_7, VP8DEC_CLOSE, arg1, arg2, arg3, arg4);	
        break;	
    case VCODEC_LOG_INDEX_VP8DEC_INIT:
        drv_trace4(TRACE_GROUP_7, VP8DEC_INIT, arg1, arg2, arg3, arg4);	
        break;	
    case VCODEC_LOG_INDEX_VP8DEC_DEINIT:
        drv_trace4(TRACE_GROUP_7, VP8DEC_DEINIT, arg1, arg2, arg3, arg4);	
        break;	
    case VCODEC_LOG_INDEX_VP8DEC_GETPARAM:
        drv_trace4(TRACE_GROUP_7, VP8DEC_GETPARAM, arg1, arg2, arg3, arg4);	
        break;	
    case VCODEC_LOG_INDEX_VP8DEC_SETPARAM:	
        drv_trace4(TRACE_GROUP_7, VP8DEC_SETPARAM, arg1, arg2, arg3, arg4);	
        break;	
    case VCODEC_LOG_INDEX_VP8DEC_LOSSY_SWITCH_QTY:    
        drv_trace4(TRACE_GROUP_7, VP8DEC_LOSSY_SWITCH_QTY, arg1, arg2, arg3, arg4);
        break;	
    case VCODEC_LOG_INDEX_VP8DEC_SUPPORT_ERROR:
        drv_trace4(TRACE_GROUP_7, VP8DEC_SUPPORT_ERROR, arg1, arg2, arg3, arg4);
        break;
                
    case VCODEC_LOG_INDEX_COMMON_4: 
        drv_trace4(TRACE_GROUP_7, SWVCODEC_COMMON_4, arg1, arg2, arg3, arg4);
        break;
    /* INDEX MAX */  
    case VCODEC_LOG_INDEX_MAX: break;
    default: break;
    }
}

void VideoTraceLog8(VCODEC_LOG_GROUP_T eGroup, VCODEC_LOG_INDEX_T eIndex, UINT64 arg1, UINT64 arg2, UINT64 arg3, UINT64 arg4, UINT64 arg5, UINT64 arg6, UINT64 arg7, UINT64 arg8)
{

	switch (eIndex)
	{

    //case VCODEC_LOG_INDEX_XXX:
    //    drv_trace8(TRACE_GROUP_7, XXX_XXX, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
    //break;  
    case VCODEC_LOG_INDEX_RMDEC_DECODE_RESULT2:
         drv_trace8(TRACE_GROUP_7, RMDEC_DECODE_RESULT2, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        break;
    case VCODEC_LOG_INDEX_RMDEC_SKIP_SETTING2:
        drv_trace8(TRACE_GROUP_7, RMDEC_SKIP_SETTING2, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        break;  
	/* H.264 DECODER */		
    case VCODEC_LOG_INDEX_H264DEC_MODECHANGE_I:
         drv_trace8(TRACE_GROUP_7, H264DEC_MODECHANGE_I, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        break;
    case VCODEC_LOG_INDEX_H264DEC_MODECHANGE_P:
        drv_trace8(TRACE_GROUP_7, H264DEC_MODECHANGE_P, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        break;  		
    case VCODEC_LOG_INDEX_COMMON_8: 
        drv_trace8(TRACE_GROUP_7, SWVCODEC_COMMON_8, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        break;
    case VCODEC_LOG_INDEX_SWMP4DEC_DYNAMIC_SWITCH1:
        drv_trace8(TRACE_GROUP_7, SWMP4DEC_DYNAMIC_SWITCH1, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        break;
    case VCODEC_LOG_INDEX_SWMP4DEC_DYNAMIC_SWITCH2:
        drv_trace8(TRACE_GROUP_7, SWMP4DEC_DYNAMIC_SWITCH2, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        break;
    /* VP8 DECODER */
    case VCODEC_LOG_INDEX_VP8DEC_GETNEXTDISPLAY:
        drv_trace8(TRACE_GROUP_7, VP8DEC_GETNEXTDISPLAY, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        break;  
    case VCODEC_LOG_INDEX_VP8DEC_DECODEONEUNIT1:
        drv_trace8(TRACE_GROUP_7, VP8DEC_DECODEONEUNIT1, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        break;  
    case VCODEC_LOG_INDEX_VP8DEC_GETMEMREQ:
        drv_trace8(TRACE_GROUP_7, VP8DEC_GETMEMREQ, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        break;  		
    case VCODEC_LOG_INDEX_VP8DEC_MODECHANGE_I:
         drv_trace8(TRACE_GROUP_7, VP8DEC_MODECHANGE_I, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        break;
    case VCODEC_LOG_INDEX_VP8DEC_MODECHANGE_P:
        drv_trace8(TRACE_GROUP_7, VP8DEC_MODECHANGE_P, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        break;  	        
    case VCODEC_LOG_INDEX_VP8DEC_INPUT_TIMEINFO:    
        drv_trace8(TRACE_GROUP_7, VP8DEC_INPUT_TIMEINFO, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        break;	        
    case VCODEC_LOG_INDEX_VP8DEC_STRM_INFO:
        drv_trace8(TRACE_GROUP_7, VP8DEC_STRM_INFO, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        break;      
        
	case VCODEC_LOG_INDEX_MAX: break;
	default: break;
	}
}

#ifdef __VE_MM_DCM_SUPPORT__
#pragma arm section code, rodata
#endif

#endif
#endif /* __VIDEO_ARCHI_V2__ */
