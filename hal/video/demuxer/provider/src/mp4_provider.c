/*****************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2007
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
 *   mp4_provider.c
 *
 * Project:
 * --------
 *   MAUI
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
 * removed!
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features_video.h"

#ifdef __VE_MP43GP_FILE_FORMAT_SUPPORT__

#include "kal_general_types.h"
#include "fs_type.h"
#include "fsal.h"
#include "mpl_common.h"
#include "med_status.h"
#include "vcodec_dec_demuxer_if.h"
#include "vcodec_v2_trc.h"
#include "source_provider_if.h"
#include "mp4_parser.h"
#include "mp4_provider.h"
#include "video_dbg_v2.h"
#include "mot_utility.h"
#include "video_kmv_v2.h"

#ifdef __VE_DCM_WITH_COMPRESSION__
#include "dcmgr.h" //DCM

#pragma arm section code = "DYNAMIC_CODE_VEDEC_ROCODE", rodata = "DYNAMIC_CODE_VEDEC_RODATA"
#endif

//#define MP4_PROVIDER_NO_ASSERT_TRACE
//#define __VE_H264_DEC_SUPPORT__

#ifdef MP4_PROVIDER_NO_ASSERT_TRACE
#define MP4_PVDR_ASSERT( exp )          \
{                           \
    do{}while(0);\
}

#define kal_trace(...)  do{}while(0);
#define video_dbg_trace(...)  do{}while(0);

#else
#define MP4_PVDR_ASSERT( exp )          \
{                           \
   if( !( exp ) )          \
   {ASSERT(0);}          \
}
#endif

#ifdef __VE_SLIM_PROJECT__
#define MP4_PROVIDER_REDUCE_META
#endif

//#define MP4_PROVIDER_KMV_PROFILING
#define MP4_PROVIDER_TRACE_GROUP TRACE_GROUP_2
#define MP4_PROVIDER_HAS_TRACK(_track_) ((prMP4ProviderCtrl->au1TrackNo[_track_]) != MP4_RESERVED_TRACK_NO)
#define MP4_PROVIDER_TRACE_RET_ERR(x) kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_RET_ERR, x, __LINE__);
#define MP4_PROVIDER_TRACE_FSAL_ERROR(x) kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_FSAL_ERROR, x, __LINE__);
#define MP4_PROVIDER_TRACE_PARSE_ERROR(x) kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_PARSER_ERROR, x, __LINE__);
#define MP4_PROVIDER_TRACE_3_VAL(v1,v2,v3)  kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_3_VAL, v1, v2, v3, __LINE__);
#define MP4_PROVIDER_TIME_UNITS_TO_MS(_TIME, _TIME_SCALE) ((kal_uint64)_TIME*1000/(kal_uint64)_TIME_SCALE)
#define MP4_PROVIDER_MS_TO_TIME_UNITS(_TIME, _TIME_SCALE) ((kal_uint64)_TIME*(kal_uint64)_TIME_SCALE/1000)
#define MP4_PROVIDER_CHECK_POINTER(a)            if (MP4ProviderCheckPointer((void *)a) != KAL_TRUE)  \
                                                 {                      \
                                                     return PROVIDER_ERROR; \
                                                 }

static MP4_PROVIDER_CTRL_T* pMP4ProviderHdlr;

#ifdef __VE_PGDL_SUPPORT__
static media_error_t MP4ProviderCheckPDLFileMeta(MP4_PROVIDER_CTRL_T *prMP4ProviderCtrl);
static PROVIDER_ERROR_T MP4ProviderOpenPDLMeta(MP4_PROVIDER_CTRL_T *prMP4ProviderCtrl);
static PROVIDER_ERROR_T MP4ProviderOpenPDLFile(MP4_PROVIDER_CTRL_T* prMP4ProviderCtrl);
#endif

#if 0
/* under construction !*/
/* under construction !*/
#endif


static kal_bool MP4ProviderCheckPointer(void *pvHandle)
{
    if (pvHandle == NULL)
    {
        MP4_PVDR_ASSERT(0);

        return KAL_FALSE;
    }

    return KAL_TRUE;
}

static void MP4ProviderSELFDeInit(MP4_PROVIDER_CTRL_T *prHandle, void *pvHandle)
{
	  if (pvHandle)
    {
        prHandle->prSourceAPI->SPFN_FREE_CLA(prHandle->prSourceHandle, pvHandle);
    }
    pvHandle = NULL;
}


static kal_bool _MP4ProviderCheckCodecSupport(MP4_Track_Type eTrackType, kal_uint32 type)
{
    kal_uint32 u4CodecType;

    u4CodecType = (MP4_Audio_Type)type;
    if(eTrackType == MP4_TRACK_VIDEO)
    {
        u4CodecType = (MP4_Video_Type)type;
    #ifndef MP4_DECODE
        if ((u4CodecType == MP4_VIDEO_MPEG4) || (u4CodecType == MP4_VIDEO_H263))
        {
            return KAL_FALSE;
        }
    #endif
    #ifndef __VE_H264_DEC_SUPPORT__
        if (u4CodecType == MP4_VIDEO_H264)
        {
            return KAL_FALSE;
        }
    #endif

    #ifndef MJPG_DECODE
        if (u4CodecType == MP4_VIDEO_MJPG)
        {
            return KAL_FALSE;
        }
    #endif
    }
    else
    {
    #ifndef AAC_DECODE
        if (u4CodecType == MP4_AUDIO_AAC)
        {
            return KAL_FALSE;
        }
    #endif

    #ifndef AMR_CODEC
        if (u4CodecType == MP4_AUDIO_AMR)
        {
            return KAL_FALSE;
        }
    #endif

    #ifndef AMRWB_DECODE
        if (u4CodecType == MP4_AUDIO_AMR_WB)
        {
            return KAL_FALSE;
        }
    #endif

    #ifndef BSAC_DECODE
        if (u4CodecType == MP4_AUDIO_BSAC)
        {
            return KAL_FALSE;
        }
    #endif

    #ifndef DAF_DECODE
        if (u4CodecType == MP4_AUDIO_MP3)
        {
            return KAL_FALSE;
        }
    #endif
    }
    return KAL_TRUE;
}

#ifdef __VE_PGDL_SUPPORT__
static kal_bool _MP4ProviderIsPDGL(MP4_PROVIDER_CTRL_T* prCtrl)
{
    return (kal_bool)(prCtrl->eSrcType == MED_MODE_PDL_FILE || prCtrl->eSrcType == MED_MODE_PDL_YTS_FILE);
}
#endif

#ifdef __VE_KMV_SUPPORT__  // Elsie
static kal_bool _MP4ProviderIsKMV(MP4_PROVIDER_CTRL_T* prCtrl)
{
		return (kal_bool)(prCtrl->eSrcType == MED_MODE_KMV_FILE|| prCtrl->eSrcType == MED_MODE_KMV_PREVIEW);
}
#endif

static kal_bool _MP4ProviderIsPreview(MP4_PROVIDER_CTRL_T* prCtrl)
{
    return (kal_bool)(prCtrl->eSrcType == MED_MODE_PREVIEW || prCtrl->eSrcType == MED_MODE_MOT_PREVIEW || prCtrl->eSrcType == MED_MODE_KMV_PREVIEW);
}

/*****************************************************************************
 * FUNCTION
 *  MP4ProviderSelfInit
 * DESCRIPTION
 *  This function is to initialize self.
 * PARAMETERS
 *  self             [IN]     mp4 mp context.
 * RETURNS
 *  void
 *****************************************************************************/
static void MP4ProviderSelfInit(MP4_PROVIDER_CTRL_T* prMP4ProviderCtrl)
{
    kal_uint32 i = 0;
    SP_TRACK_T eTrack = prMP4ProviderCtrl->eTrack;
    MP4_PROVIDER_TRACK_BUF_POOL_AUD_T* pt_track_pool_a = NULL;
    MP4_PROVIDER_TRACK_BUF_POOL_VID_T* pt_track_pool_v = NULL;
    MP4_PROVIDER_COMMON_BUF_POOL_T* pt_comn_pool = NULL;
#ifdef __VE_PGDL_SUPPORT__
    MP4_PROVIDER_TRACK_BUF_POOL_PDL_T* pt_track_pool_pdl = NULL;
#endif
#ifdef __VE_KMV_SUPPORT__
	MP4_PROVIDER_TRACK_BUF_POOL_KMV_T* pt_track_pool_s = NULL;
#endif

    SP_API_T *prSrcAPI = prMP4ProviderCtrl->prSourceAPI;

    MP4_PVDR_ASSERT(prSrcAPI);

    prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO] = NULL;
    prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO] = NULL;

    prMP4ProviderCtrl->prVidStreamInfo = NULL;
    prMP4ProviderCtrl->prAudStrmInfo = NULL;

    for(i=MP4_NUM_TRACKS;i!=0;i--)
    {
        prMP4ProviderCtrl->eTrackType[i-1] = SOURCE_PROVIDER_PORT_MAX;
    }

    prMP4ProviderCtrl->au1TrackNo[SOURCE_PROVIDER_PORT_AUDIO] = MP4_RESERVED_TRACK_NO;
    prMP4ProviderCtrl->au1TrackNo[SOURCE_PROVIDER_PORT_VIDEO] = MP4_RESERVED_TRACK_NO;

    if (eTrack & SOURCE_PROVIDER_TRACK_AUDIO)
    {
        prMP4ProviderCtrl->pt_track_buf_pool_aud =
            (MP4_PROVIDER_TRACK_BUF_POOL_AUD_T*)prSrcAPI->SPFN_MALLOC_CLA(prMP4ProviderCtrl->prSourceHandle,
                                                                          sizeof(MP4_PROVIDER_TRACK_BUF_POOL_AUD_T), KAL_FALSE);
        pt_track_pool_a = prMP4ProviderCtrl->pt_track_buf_pool_aud;
        MP4_PVDR_ASSERT(pt_track_pool_a != NULL);

        prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO] = &pt_track_pool_a->t_fsal;
        prMP4ProviderCtrl->pt_fsal_stsz[SOURCE_PROVIDER_PORT_AUDIO] = &pt_track_pool_a->t_fsal_stsz;
        prMP4ProviderCtrl->pt_fsal_stco[SOURCE_PROVIDER_PORT_AUDIO] = &pt_track_pool_a->t_fsal_stco;
        prMP4ProviderCtrl->pt_fsal_stts[MP4_TRACK_AUDIO] = &pt_track_pool_a->t_fsal_stts;
        prMP4ProviderCtrl->pt_fsal_mdat[SOURCE_PROVIDER_PORT_AUDIO] = &pt_track_pool_a->t_fsal_mdat;
        prMP4ProviderCtrl->p_fsal_buf[SOURCE_PROVIDER_PORT_AUDIO] = pt_track_pool_a->fsal_buf;
        prMP4ProviderCtrl->p_fsal_buf_stsz[SOURCE_PROVIDER_PORT_AUDIO] = pt_track_pool_a->fsal_buf_stsz;
        prMP4ProviderCtrl->p_fsal_buf_stco[SOURCE_PROVIDER_PORT_AUDIO] = pt_track_pool_a->fsal_buf_stco;
        prMP4ProviderCtrl->p_fsal_buf_stts[SOURCE_PROVIDER_PORT_AUDIO] = pt_track_pool_a->fsal_buf_stts;

#ifdef __VE_PGDL_SUPPORT__
        if (KAL_TRUE == _MP4ProviderIsPDGL(prMP4ProviderCtrl))
        {
            prMP4ProviderCtrl->pt_track_buf_pool_pdl[SOURCE_PROVIDER_PORT_AUDIO] =
                (MP4_PROVIDER_TRACK_BUF_POOL_PDL_T*)prSrcAPI->SPFN_MALLOC_CLA(prMP4ProviderCtrl->prSourceHandle,
                                                                                                                sizeof(MP4_PROVIDER_TRACK_BUF_POOL_PDL_T), KAL_FALSE);
            pt_track_pool_pdl = prMP4ProviderCtrl->pt_track_buf_pool_pdl[SOURCE_PROVIDER_PORT_AUDIO];
            MP4_PVDR_ASSERT(pt_track_pool_pdl != NULL);
            prMP4ProviderCtrl->pt_parser_pdl[SOURCE_PROVIDER_PORT_AUDIO] = &pt_track_pool_pdl->t_parser;
            prMP4ProviderCtrl->pt_fsal_pdl[SOURCE_PROVIDER_PORT_AUDIO] = &pt_track_pool_pdl->t_fsal;
            prMP4ProviderCtrl->pt_fsal_stsz_pdl[SOURCE_PROVIDER_PORT_AUDIO] = &pt_track_pool_pdl->t_fsal_stsz;
            prMP4ProviderCtrl->pt_fsal_stco_pdl[SOURCE_PROVIDER_PORT_AUDIO] = &pt_track_pool_pdl->t_fsal_stco;
            prMP4ProviderCtrl->p_fsal_buf_pdl[SOURCE_PROVIDER_PORT_AUDIO] = pt_track_pool_pdl->fsal_buf;
            prMP4ProviderCtrl->p_fsal_buf_stsz_pdl[SOURCE_PROVIDER_PORT_AUDIO] = pt_track_pool_pdl->fsal_buf_stsz;
            prMP4ProviderCtrl->p_fsal_buf_stco_pdl[SOURCE_PROVIDER_PORT_AUDIO] = pt_track_pool_pdl->fsal_buf_stco;
        }
#endif /* __VE_PGDL_SUPPORT__ */

    }

    //if (e_mode ==  MEDIA_PROVIDER_MODE_NORMAL || e_mode ==  MEDIA_PROVIDER_MODE_VIDEO)
    {
        prMP4ProviderCtrl->pt_track_buf_pool_vid =
            (MP4_PROVIDER_TRACK_BUF_POOL_VID_T*)prSrcAPI->SPFN_MALLOC_CLA(prMP4ProviderCtrl->prSourceHandle,
                                                                                                            sizeof(MP4_PROVIDER_TRACK_BUF_POOL_VID_T), KAL_FALSE);
        pt_track_pool_v = prMP4ProviderCtrl->pt_track_buf_pool_vid;
        MP4_PVDR_ASSERT(pt_track_pool_v != NULL);
        prMP4ProviderCtrl->pt_parser = &pt_track_pool_v->t_parser;
	prMP4ProviderCtrl->pt_parser->fgQuickClose = KAL_FALSE;
        prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO] = &pt_track_pool_v->t_fsal;
        prMP4ProviderCtrl->pt_fsal_stsz[SOURCE_PROVIDER_PORT_VIDEO] = &pt_track_pool_v->t_fsal_stsz;
        prMP4ProviderCtrl->pt_fsal_stco[SOURCE_PROVIDER_PORT_VIDEO] = &pt_track_pool_v->t_fsal_stco;
        prMP4ProviderCtrl->pt_fsal_stss[SOURCE_PROVIDER_PORT_VIDEO] = &pt_track_pool_v->t_fsal_stss;
        prMP4ProviderCtrl->pt_fsal_stts[SOURCE_PROVIDER_PORT_VIDEO] = &pt_track_pool_v->t_fsal_stts;
        prMP4ProviderCtrl->pt_fsal_mdat[SOURCE_PROVIDER_PORT_VIDEO] = &pt_track_pool_v->t_fsal_mdat;
        prMP4ProviderCtrl->p_fsal_buf[SOURCE_PROVIDER_PORT_VIDEO] = pt_track_pool_v->fsal_buf;
        prMP4ProviderCtrl->p_fsal_buf_stsz[SOURCE_PROVIDER_PORT_VIDEO] = pt_track_pool_v->fsal_buf_stsz;
        prMP4ProviderCtrl->p_fsal_buf_stco[SOURCE_PROVIDER_PORT_VIDEO] = pt_track_pool_v->fsal_buf_stco;
        prMP4ProviderCtrl->p_fsal_buf_stss[SOURCE_PROVIDER_PORT_VIDEO] = pt_track_pool_v->fsal_buf_stss;
        prMP4ProviderCtrl->p_fsal_buf_stts[SOURCE_PROVIDER_PORT_VIDEO] = pt_track_pool_v->fsal_buf_stts;
        //self->p_fsal_buf_mdat[SOURCE_PROVIDER_PORT_VIDEO] = pt_track_pool_v->fsal_buf_mdat;

#ifdef __VE_PGDL_SUPPORT__
        if (KAL_TRUE == _MP4ProviderIsPDGL(prMP4ProviderCtrl))
        {
            prMP4ProviderCtrl->pt_track_buf_pool_pdl[SOURCE_PROVIDER_PORT_VIDEO] =
                (MP4_PROVIDER_TRACK_BUF_POOL_PDL_T*)prSrcAPI->SPFN_MALLOC_CLA(prMP4ProviderCtrl->prSourceHandle,
                                                                                                                sizeof(MP4_PROVIDER_TRACK_BUF_POOL_PDL_T), KAL_FALSE);
            pt_track_pool_pdl = prMP4ProviderCtrl->pt_track_buf_pool_pdl[SOURCE_PROVIDER_PORT_VIDEO];
            MP4_PVDR_ASSERT(pt_track_pool_pdl != NULL);
            prMP4ProviderCtrl->pt_parser_pdl[SOURCE_PROVIDER_PORT_VIDEO] = &pt_track_pool_pdl->t_parser;
            prMP4ProviderCtrl->pt_fsal_pdl[SOURCE_PROVIDER_PORT_VIDEO] = &pt_track_pool_pdl->t_fsal;
            prMP4ProviderCtrl->pt_fsal_stsz_pdl[SOURCE_PROVIDER_PORT_VIDEO] = &pt_track_pool_pdl->t_fsal_stsz;
            prMP4ProviderCtrl->pt_fsal_stco_pdl[SOURCE_PROVIDER_PORT_VIDEO] = &pt_track_pool_pdl->t_fsal_stco;
            prMP4ProviderCtrl->p_fsal_buf_pdl[SOURCE_PROVIDER_PORT_VIDEO] = pt_track_pool_pdl->fsal_buf;
            prMP4ProviderCtrl->p_fsal_buf_stsz_pdl[SOURCE_PROVIDER_PORT_VIDEO] = pt_track_pool_pdl->fsal_buf_stsz;
            prMP4ProviderCtrl->p_fsal_buf_stco_pdl[SOURCE_PROVIDER_PORT_VIDEO] = pt_track_pool_pdl->fsal_buf_stco;
        }
#endif /* __VE_PGDL_SUPPORT__ */

#ifdef __VE_KMV_SUPPORT__

		if (KAL_TRUE == _MP4ProviderIsKMV(prMP4ProviderCtrl))
		{
			prMP4ProviderCtrl->pt_track_buf_pool_sub =
						(MP4_PROVIDER_TRACK_BUF_POOL_KMV_T*)prSrcAPI->SPFN_MALLOC_CLA(prMP4ProviderCtrl->prSourceHandle,
																														sizeof(MP4_PROVIDER_TRACK_BUF_POOL_KMV_T), KAL_FALSE);
			pt_track_pool_s = prMP4ProviderCtrl->pt_track_buf_pool_sub;
			MP4_PVDR_ASSERT(pt_track_pool_s != NULL);

			prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_SUBTITLE] = &pt_track_pool_s->t_fsal;
			prMP4ProviderCtrl->pt_fsal_stsz[SOURCE_PROVIDER_PORT_SUBTITLE] = &pt_track_pool_s->t_fsal_STSZ;
			prMP4ProviderCtrl->pt_fsal_stco[SOURCE_PROVIDER_PORT_SUBTITLE] = &pt_track_pool_s->t_fsal_STCO;
			prMP4ProviderCtrl->pt_fsal_map = &pt_track_pool_s->t_fsal_MAP;
			prMP4ProviderCtrl->p_fsal_buf[SOURCE_PROVIDER_PORT_SUBTITLE] = pt_track_pool_s->fsal_buf;
			prMP4ProviderCtrl->p_fsal_buf_stsz[SOURCE_PROVIDER_PORT_SUBTITLE] = pt_track_pool_s->fsal_buf_STSZ;
			prMP4ProviderCtrl->p_fsal_buf_stco[SOURCE_PROVIDER_PORT_SUBTITLE] = pt_track_pool_s->fsal_buf_STCO;
			prMP4ProviderCtrl->p_fsal_buf_map = pt_track_pool_s->fsal_buf_MAP;

		}

#endif


    }

    prMP4ProviderCtrl->pt_comn_buf_pool =
        (MP4_PROVIDER_COMMON_BUF_POOL_T*)prSrcAPI->SPFN_MALLOC_CLA(prMP4ProviderCtrl->prSourceHandle,
                                                                                                        sizeof(MP4_PROVIDER_COMMON_BUF_POOL_T), KAL_FALSE);
    pt_comn_pool = prMP4ProviderCtrl->pt_comn_buf_pool;
    MP4_PVDR_ASSERT(pt_comn_pool != NULL);
    prMP4ProviderCtrl->p_stbl_buf = pt_comn_pool->stbl_buf;

    prMP4ProviderCtrl->pt_fsal_seek_hint = pt_comn_pool->t_fsal_seek_hint;


#ifdef __VE_PGDL_SUPPORT__
    prMP4ProviderCtrl->fgWaitMeta = KAL_FALSE;

#endif /* __VE_PGDL_SUPPORT__ */


    /* allocate video memory pool */
    if (eTrack & SOURCE_PROVIDER_TRACK_VIDEO)
    {

        prMP4ProviderCtrl->prVideoParamSetData =
           (PU_VID_PARAM_SET_T*)prSrcAPI->SPFN_MALLOC_CLA(prMP4ProviderCtrl->prSourceHandle, sizeof(PU_VID_PARAM_SET_T), KAL_FALSE);
        MP4_PVDR_ASSERT(prMP4ProviderCtrl->prVideoParamSetData != NULL);
        prMP4ProviderCtrl->prSourceAPI->SPFN_MEM_SET(prMP4ProviderCtrl->prVideoParamSetData, 0, sizeof(PU_VID_PARAM_SET_T));

    }
}

/*****************************************************************************
 * FUNCTION
 *  MP4ProviderSelfDeInit
 * DESCRIPTION
 *  This function is to de-initialize self.
 * PARAMETERS
 *  self             [IN]     mp4 mp context.
 * RETURNS
 *  void
 *****************************************************************************/
static void MP4ProviderSelfDeInit(MP4_PROVIDER_CTRL_T* prMP4ProviderCtrl)
{
    PU_VID_PARAM_SET_T* prVidParamSetData = prMP4ProviderCtrl->prVideoParamSetData;

    MP4ProviderSELFDeInit(prMP4ProviderCtrl,prMP4ProviderCtrl->pt_track_buf_pool_aud);
    MP4ProviderSELFDeInit(prMP4ProviderCtrl,prMP4ProviderCtrl->pt_track_buf_pool_vid);

#ifdef __VE_KMV_SUPPORT__
	MP4ProviderSELFDeInit(prMP4ProviderCtrl,prMP4ProviderCtrl->pt_track_buf_pool_sub);
#endif


#ifdef __VE_PGDL_SUPPORT__
    MP4ProviderSELFDeInit(prMP4ProviderCtrl,prMP4ProviderCtrl->pt_track_buf_pool_pdl[SOURCE_PROVIDER_PORT_AUDIO]);
    MP4ProviderSELFDeInit(prMP4ProviderCtrl,prMP4ProviderCtrl->pt_track_buf_pool_pdl[SOURCE_PROVIDER_PORT_VIDEO]);
#endif
    MP4ProviderSELFDeInit(prMP4ProviderCtrl,prMP4ProviderCtrl->prVidStreamInfo);
    MP4ProviderSELFDeInit(prMP4ProviderCtrl,prMP4ProviderCtrl->prAudStrmInfo);
    MP4ProviderSELFDeInit(prMP4ProviderCtrl,prMP4ProviderCtrl->pt_comn_buf_pool);
//    MP4ProviderSELFDeInit(prMP4ProviderCtrl,prMP4ProviderCtrl->prUdtaInfo);

    FSAL_Close(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO]);
    FSAL_Close(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO]);
#ifdef __VE_KMV_SUPPORT__
	FSAL_Close(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_SUBTITLE]);
#endif

#ifdef __VE_PGDL_SUPPORT__
    FSAL_Close(prMP4ProviderCtrl->pt_fsal_pdl[SOURCE_PROVIDER_PORT_AUDIO]);
    FSAL_Close(prMP4ProviderCtrl->pt_fsal_pdl[SOURCE_PROVIDER_PORT_VIDEO]);
#endif

    if (prVidParamSetData)
    {
    	MP4ProviderSELFDeInit(prMP4ProviderCtrl,prVidParamSetData->pu1ParamSetBuff);
 	MP4ProviderSELFDeInit(prMP4ProviderCtrl,prVidParamSetData->prNALCTRLBuff);
 
        prMP4ProviderCtrl->prSourceAPI->SPFN_FREE_CLA(prMP4ProviderCtrl->prSourceHandle, prVidParamSetData);
        prVidParamSetData = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  _mp4_mp_media_data_alloc
 * DESCRIPTION
 *  This function is to allocate memory of media data.
 * PARAMETERS
 *  self             [IN]     mp4 mp context.
 *  ppt_data         [IN]     pointer of media data.
 *  pp_sample        [IN]     pointer of sample data.
 *  type             [IN]     track type.
 * RETURNS
 *  void
 *****************************************************************************/
static void MP4ProviderMediaDataAlloc(MP4_PROVIDER_CTRL_T* prMP4ProviderCtrl,
                                     kal_uint8** pp_sample, SP_PORT_TYPE_T type)
{
    kal_uint32 start;
    kal_uint32 offset;
    MP4_PROVIDER_BATCH_READ_T *ptBatch = &(prMP4ProviderCtrl->t_batch[type]);

    MP4_PVDR_ASSERT(pp_sample);

    start = (kal_uint32)ptBatch->p_mem_start;
    MP4_PVDR_ASSERT(start);
    offset = ptBatch->sample_offset[ptBatch->read_idx] - ptBatch->sample_offset[0];
    *pp_sample = (kal_uint8*)(start + offset);
    MP4_PVDR_ASSERT(*pp_sample);

    ptBatch->read_idx++;
}

/*****************************************************************************
 * FUNCTION
 *  _mp4_mp_media_data_dealloc
 * DESCRIPTION
 *  This function is to allocate memory of media data.
 * PARAMETERS
 *  self             [IN]     mp4 mp context.
 *  ppt_data         [IN]     pointer of media data.
 *  pp_sample        [IN]     pointer of sample data.
 *  type             [IN]     track type.
 * RETURNS
 *  void
 *****************************************************************************/
static void MP4ProviderMediaDataDealloc(MP4_PROVIDER_CTRL_T* prMP4ProviderCtrl, SP_PORT_TYPE_T type)
{
    prMP4ProviderCtrl->t_batch[type].read_idx--;
}

static void MP4ProviderBatchReset(MP4_PROVIDER_CTRL_T* prMP4ProviderCtrl, SP_PORT_TYPE_T type)
{
    kal_uint32 i;

    MP4_PROVIDER_BATCH_READ_T *ptBatch = &(prMP4ProviderCtrl->t_batch[type]);

    ptBatch->p_mem_start = NULL; //prMP4ProviderCtrl->t_sample_buf[type].p_mem_pool_start;
    
    for(i=MP4_PROVIDER_BATCH_READ_MAX;i!=0;i--)
    {
        ptBatch->sample_offset[i-1] = 0;
        ptBatch->sample_size[i-1] = 0;
    }
    ptBatch->sample_no_start = prMP4ProviderCtrl->au4CurrSampleNo[type];
    ptBatch->curr_sample_no = prMP4ProviderCtrl->au4CurrSampleNo[type];
    ptBatch->read_idx = 0;
    ptBatch->write_idx = 0;

    if(prMP4ProviderCtrl->fgResend[type] == KAL_TRUE && type == SOURCE_PROVIDER_PORT_VIDEO)
    {
	SPIF_PROVIDER_FRAME_INFO_T *prFrameInfo = &(prMP4ProviderCtrl->rFrameInfo[type]);

	if(prFrameInfo->pu1Payload != NULL)
	{
	    prMP4ProviderCtrl->prSourceAPI->SPFN_FREE_CLA(prMP4ProviderCtrl->prSourceHandle,
																		  prFrameInfo->pu1Payload);
	}

#ifdef __VE_KMV_SUPPORT__
	if(prFrameInfo->pu1KMVPayload != NULL)
	{
		prMP4ProviderCtrl->prSourceAPI->SPFN_FREE_CLA(prMP4ProviderCtrl->prSourceHandle, prFrameInfo->pu1KMVPayload);
	}
#endif

    }



    prMP4ProviderCtrl->fgResend[type] = KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  _mp4_mp_seek_sample
 * DESCRIPTION
 *  This function is to seek sample for specific track type.
 * PARAMETERS
 *  self             [IN]     mp4 mp context.
 *  sample_no        [IN]     the sample number to seek.
 *  type             [IN]     mp4 track type.
 * RETURNS
 *  media_error_t
 *****************************************************************************/
static media_error_t MP4ProviderSeekSample(MP4_PROVIDER_CTRL_T* prMP4ProviderCtrl, kal_uint32 sample_no, SP_PORT_TYPE_T type)
{
    MP4_Parser_Status e_parser_ret;
    MP4_Track_Type eType = (type == SOURCE_PROVIDER_PORT_AUDIO) ? MP4_TRACK_AUDIO : MP4_TRACK_VIDEO;

    if (sample_no < prMP4ProviderCtrl->au4SampleCount[type])
    {
        e_parser_ret = MP4_GetSampleOffset(prMP4ProviderCtrl->pt_parser, sample_no, &(prMP4ProviderCtrl->t_batch[type].curr_sample_offset), eType);
        if (e_parser_ret != MP4_PARSER_OK)
        {
            MP4_PROVIDER_TRACE_PARSE_ERROR(e_parser_ret);
            return MED_E_PARSER_ERROR;
        }
    }
    else
    {
        return MED_E_INVALID_PARAM;
    }

    return MED_S_OK;
}

/*****************************************************************************
 * FUNCTION
 *  _mp4_mp_seek_sample_internal
 * DESCRIPTION
 *  This function is to seek sample for specific track type.
 * PARAMETERS
 *  self             [IN]     mp4 mp context.
 *  type             [IN]     mp4 track type.
 * RETURNS
 *  media_error_t
 *****************************************************************************/
static media_error_t MP4ProviderSeekSampleInternal(MP4_PROVIDER_CTRL_T* prMP4ProviderCtrl, SP_PORT_TYPE_T type)
{
    MP4_Parser_Status e_parser_ret;
    MP4_Track_Type eType = (type == SOURCE_PROVIDER_PORT_AUDIO) ? MP4_TRACK_AUDIO : MP4_TRACK_VIDEO;

    prMP4ProviderCtrl->t_batch[type].curr_sample_no++;

    if (prMP4ProviderCtrl->t_batch[type].curr_sample_no < prMP4ProviderCtrl->au4SampleCount[type])
    {
        e_parser_ret = MP4_GetSampleOffset_Next(prMP4ProviderCtrl->pt_parser, &(prMP4ProviderCtrl->t_batch[type].curr_sample_offset), eType);
        if (e_parser_ret != MP4_PARSER_OK)
        {
            MP4_PROVIDER_TRACE_PARSE_ERROR(e_parser_ret);
            return MED_E_PARSER_ERROR;
        }
    }

    return MED_S_OK;
}

#define MP4_READBTM_ALIGH 512
#define MP4_ALIGNMENT_READ_OVERHEAD 1024

static media_error_t MP4ProviderBatchRead(MP4_PROVIDER_CTRL_T* prMP4ProviderCtrl, SP_PORT_TYPE_T type)
{
    kal_uint32 batch_size = 0, u4ActualBufSize = 0;
    MP4_Parser_Status e_parser_ret;
    media_error_t ret = MED_S_OK;
    MP4_Track_Type eType = (type == SOURCE_PROVIDER_PORT_AUDIO) ? MP4_TRACK_AUDIO : MP4_TRACK_VIDEO;
    kal_uint32 u4SampleSize;
    kal_uint32 u4ReadSize;
    kal_uint32 u4TotalSize;
    kal_uint32 wr_idx;
    kal_uint32 offset_diff;
    FSAL_Status eFsalRet;
    kal_uint8* p_batch = NULL;
    kal_uint32 gap_sum = 0;
    kal_uint32 gap_threshold=0,temp_threshold;
    kal_uint32 reason = 0;
    MP4_PROVIDER_BATCH_READ_T *ptBatch = &(prMP4ProviderCtrl->t_batch[type]);
    kal_uint32 uElapsedTime = 0;
    kal_uint32 count = 0;

    if (!prMP4ProviderCtrl->fgSelectedTrack[type] ||
        ptBatch->curr_sample_no == prMP4ProviderCtrl->au4SampleCount[type] ||
        ptBatch->read_idx != ptBatch->write_idx)
    {
        return MED_S_OK;
    }

    uElapsedTime = video_get_current_time();
    VIDEO_START_LOGGING("MV1");

//    gap_threshold = (type == SOURCE_PROVIDER_PORT_VIDEO) ? MP4_PROVIDER_VID_SAMPLE_GAP_THRESHOLD : MP4_PROVIDER_AUD_SAMPLE_GAP_THRESHOLD;

    u4TotalSize = prMP4ProviderCtrl->prSourceAPI->SPFN_BITSTREAM_BUF_SIZE(prMP4ProviderCtrl->prSourceHandle, type);

#ifdef __VE_PGDL_SUPPORT__
    if (KAL_TRUE == _MP4ProviderIsPDGL(prMP4ProviderCtrl))
    {
        kal_uint32 u4FileSize;

        eFsalRet = FSAL_Direct_GetFileSize(prMP4ProviderCtrl->pt_fsal_mdat[type], &u4FileSize);
        if (eFsalRet != FSAL_OK)
        {
            MP4_PROVIDER_TRACE_FSAL_ERROR(eFsalRet);
        }
        else
        {
            prMP4ProviderCtrl->u4FileSize = u4FileSize;
            prMP4ProviderCtrl->pt_fsal_mdat[type]->uFileSize = u4FileSize;
        }
    }
#endif /* __VE_PGDL_SUPPORT__ */

    MP4ProviderBatchReset(prMP4ProviderCtrl, type);

    /* to find the first sample whose size is not zero */
    do
    {
        e_parser_ret = MP4_GetSampleSize(prMP4ProviderCtrl->pt_parser,
                                         ptBatch->curr_sample_no,
                                         &u4SampleSize,
                                         eType);
        if (e_parser_ret != MP4_PARSER_OK)
        {
            reason = 10;
            ret = MED_E_PARSER_ERROR;
            break;
        }
        u4ReadSize = u4SampleSize;

        if (u4SampleSize >= prMP4ProviderCtrl->u4FileSize)
        {
            reason = 11;
            ret = MED_E_CORRUPTED_DATA;
            break;
        }

        if ((ptBatch->curr_sample_offset + u4SampleSize) > prMP4ProviderCtrl->u4FileSize)
        {
#ifdef __VE_PGDL_SUPPORT__
            if (KAL_TRUE == _MP4ProviderIsPDGL(prMP4ProviderCtrl))
            {
                reason = 12;
                ret = MED_E_PDL_SHORT_OF_BUF;
                break;
            }
            else
#endif
            {
                reason = 13;
                ret = MED_E_CORRUPTED_DATA;
                break;
            }
        }

        /* Check if there is enough memory */
        if (u4SampleSize)
        {
            if(u4SampleSize > u4TotalSize)
            {
                // frame size is larger than bitstream buffer size
                ret = MED_E_MEM_INSUFFICIENT;
                reason = 16;
                break;
            }
            p_batch = (kal_uint8 *)prMP4ProviderCtrl->prSourceAPI->SPFN_BITSTREAM_BUF_QUERY_AVAILABLE_SIZE(
                                                        prMP4ProviderCtrl->prSourceHandle, type, (u4SampleSize+MP4_ALIGNMENT_READ_OVERHEAD), &u4ActualBufSize);

            gap_threshold = u4ActualBufSize*0.1;
			temp_threshold = (type == SOURCE_PROVIDER_PORT_VIDEO) ? MP4_PROVIDER_VID_SAMPLE_GAP_THRESHOLD : MP4_PROVIDER_AUD_SAMPLE_GAP_THRESHOLD;
			if(gap_threshold<temp_threshold)
			{
			    gap_threshold = temp_threshold;
			}
            if (p_batch == NULL)
            {
                ret = MED_E_OUT_OF_MEMORY;
                reason = 15;
                break;
            }
        }

        wr_idx = ptBatch->write_idx;
        ptBatch->sample_size[wr_idx] = u4ReadSize;
        ptBatch->sample_offset[wr_idx] = ptBatch->curr_sample_offset;

        ret = MP4ProviderSeekSampleInternal(prMP4ProviderCtrl, type); /* update curr_sample_no & curr_sample_offset */
        if (ret != MED_S_OK)
        {
            reason = 14;
            break;
        }
        ptBatch->write_idx++;

    } while (u4SampleSize == 0 &&
             ptBatch->curr_sample_no < prMP4ProviderCtrl->au4SampleCount[type] &&
             ptBatch->write_idx < MP4_PROVIDER_BATCH_READ_MAX);

    if(ret != MED_S_OK)
    {
        VIDEO_STOP_LOGGING("MV1");
        MP4_PROVIDER_TRACE_RET_ERR(ret);
        MP4_PROVIDER_TRACE_3_VAL(reason, u4SampleSize, u4TotalSize);
        return ret;
    }

    if (u4SampleSize == 0)
    {
        MP4_PROVIDER_TRACE_RET_ERR(type);
        VIDEO_STOP_LOGGING("MV1");
        return MED_E_CORRUPTED_DATA;
    }

    batch_size += u4ReadSize;
    if (ptBatch->curr_sample_offset >= ptBatch->sample_offset[wr_idx])
    {
        offset_diff = ptBatch->curr_sample_offset - ptBatch->sample_offset[wr_idx];
    }
    else
    {
        offset_diff = 0xFFFFFFFF;
    }

    /* check if there are other samples can be processed in this batch read */
    while (ptBatch->curr_sample_no < prMP4ProviderCtrl->au4SampleCount[type] &&
           ptBatch->write_idx < MP4_PROVIDER_BATCH_READ_MAX &&
           offset_diff != 0xFFFFFFFF)
    {
        kal_uint32 gap;

        if (offset_diff < u4SampleSize)
        {
            reason = 1;
            break;
        }

        if ((type == SOURCE_PROVIDER_PORT_VIDEO) &&
            (u4SampleSize > u4ActualBufSize) &&
            (u4ReadSize == u4ActualBufSize))
        {
            reason = 2;
            break;
        }

        gap = offset_diff - u4SampleSize;
        gap_sum += gap;

        if (gap_sum < gap_threshold)
        {
            e_parser_ret = MP4_GetSampleSize(prMP4ProviderCtrl->pt_parser,
                                             ptBatch->curr_sample_no,
                                             &u4SampleSize,
                                             eType);
            if (e_parser_ret != MP4_PARSER_OK)
            {
                reason = 3;
                break;
            }
            if (u4SampleSize >= prMP4ProviderCtrl->u4FileSize || u4SampleSize >= u4TotalSize)
            {
                reason = 4;
                break;
            }

            if ((ptBatch->curr_sample_offset + u4SampleSize) > prMP4ProviderCtrl->u4FileSize)
            {
#ifdef __VE_PGDL_SUPPORT__
                if (KAL_TRUE == _MP4ProviderIsPDGL(prMP4ProviderCtrl))
                {
                    reason = 5;
                    break;
                }
                else
#endif
                {
                    reason = 6;
                    break;
                }
            }
        }
        else
        {
            gap_sum -= gap;
            reason = 7;
            break;
        }

        if (u4ActualBufSize < (batch_size + gap + u4SampleSize + MP4_ALIGNMENT_READ_OVERHEAD))
        {
            reason = 8;
            break;
        }
        else
        {
            wr_idx = ptBatch->write_idx;
            ptBatch->sample_size[wr_idx] = u4SampleSize;
            ptBatch->sample_offset[wr_idx] = ptBatch->curr_sample_offset;

            ret = MP4ProviderSeekSampleInternal(prMP4ProviderCtrl, type); /* update curr_sample_no & curr_sample_offset */
            if (ret != MED_S_OK)
            {
                kal_uint32 sample_no = ptBatch->curr_sample_no - 1;

                MP4_PROVIDER_TRACE_RET_ERR(ret);
                ret = MP4ProviderSeekSample(prMP4ProviderCtrl, sample_no, type);
                if (ret != MED_S_OK)
                {
                    MP4_PROVIDER_TRACE_RET_ERR(ret);
                }
                reason = 9;
                break;
            }

            ptBatch->write_idx++;

            batch_size += (gap + u4SampleSize);
            if (ptBatch->curr_sample_offset >= ptBatch->sample_offset[wr_idx])
            {
                offset_diff = ptBatch->curr_sample_offset - ptBatch->sample_offset[wr_idx];
            }
            else
            {
                offset_diff = 0xFFFFFFFF;
            }
        }
    }
    MP4_PROVIDER_TRACE_3_VAL(reason, u4SampleSize, u4ActualBufSize);

    #if 1 // Alignment read bitstream start
    {
        kal_uint32 u4AlignOffset = 0;
        kal_uint32 uAlignSize = 0;

        u4AlignOffset = ptBatch->sample_offset[0]/MP4_READBTM_ALIGH*MP4_READBTM_ALIGH;
        eFsalRet = FSAL_Direct_Seek(prMP4ProviderCtrl->pt_fsal_mdat[type], u4AlignOffset);

        if (eFsalRet != FSAL_OK)
        {
            MP4_PROVIDER_TRACE_FSAL_ERROR(eFsalRet);
            MP4_PROVIDER_TRACE_3_VAL(ptBatch->sample_offset[0], ptBatch->sample_no_start, prMP4ProviderCtrl->u4FileSize);
            VIDEO_STOP_LOGGING("MV1");
            return MED_E_FSAL_ERROR;
        }

        uAlignSize = (batch_size+ (ptBatch->sample_offset[0]-u4AlignOffset)+ MP4_READBTM_ALIGH-1)/MP4_READBTM_ALIGH*MP4_READBTM_ALIGH;

        if(uAlignSize > (prMP4ProviderCtrl->u4FileSize-u4AlignOffset))
        {
            uAlignSize = prMP4ProviderCtrl->u4FileSize-u4AlignOffset;
        }
        MP4_PVDR_ASSERT(uAlignSize <= u4ActualBufSize);
        eFsalRet = FSAL_Direct_Read(prMP4ProviderCtrl->pt_fsal_mdat[type], p_batch, uAlignSize);
        if (eFsalRet != FSAL_OK)
        {
            MP4_PROVIDER_TRACE_FSAL_ERROR(eFsalRet);
            MP4_PROVIDER_TRACE_3_VAL(ptBatch->sample_offset[0], batch_size, prMP4ProviderCtrl->u4FileSize);
            VIDEO_STOP_LOGGING("MV1");
            return MED_E_FSAL_ERROR;
        }

        ptBatch->p_mem_start = p_batch;
        if(ptBatch->sample_offset[0] - u4AlignOffset != 0)
        {
            ptBatch->p_mem_start = p_batch + (ptBatch->sample_offset[0] - u4AlignOffset);
        }
    }
    #endif
    //prMP4ProviderCtrl->prSourceAPI->SPFN_BITSTREAM_BUF_UPDATA_ADD(prMP4ProviderCtrl->prSourceHandle, type, (kal_uint32)p_batch + batch_size);

    VIDEO_STOP_LOGGING("MV1");
    uElapsedTime = video_get_duration_ms(uElapsedTime);
    ptBatch->count++;
    ptBatch->accum_size += batch_size;
    ptBatch->accum_time += uElapsedTime;

    count = ptBatch->count;

    if (type == SOURCE_PROVIDER_PORT_AUDIO)
    {
        kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_BATCH_READ_AUDIO,
                  ptBatch->curr_sample_no, batch_size, uElapsedTime,
                  gap_sum, p_batch);
        kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_BATCH_READ_AUDIO_THUP,
              ptBatch->count, ptBatch->accum_time/count,
              ptBatch->accum_size/count,
              (ptBatch->accum_size/(ptBatch->accum_time+1)));
    }
    else if (type == SOURCE_PROVIDER_PORT_VIDEO)
    {
        kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_BATCH_READ_VIDEO,
                  ptBatch->curr_sample_no, batch_size, uElapsedTime,
                  gap_sum, p_batch);
        kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_BATCH_READ_VIDEO_THUP,
              ptBatch->count, ptBatch->accum_time/count,
              ptBatch->accum_size/count,
              (ptBatch->accum_size/(ptBatch->accum_time+1)));
    }

    return MED_S_OK;
}

#ifdef __VE_H264_DEC_SUPPORT__

static media_error_t MP4ProviderGetAvcConfigData(STMp4Parser *prSTMp4Parser,
                                                 STFSAL *prSTFSAL,
                                                 kal_uint32 *pu4NALuSizeInfo)
{
    FSAL_Status eStatus;
    kal_uint32 u4ConfigPosition;
    kal_uint32 u4ConfigSize;
    kal_uint8 au1ConfigData[MP4_PROVIDER_AVC_CONFIG_REC_SPS_OFFSET];

    /* Get AVC configuration information */
    u4ConfigPosition = MP4_Video_GetAVCConfigOffset(prSTMp4Parser);
    u4ConfigSize = MP4_Video_GetAVCConfigSize(prSTMp4Parser);

    do
    {
    if(u4ConfigSize != MP4_PROVIDER_AVC_CONFIG_REC_SPS_OFFSET)
    {
        *pu4NALuSizeInfo = 0;
        break;
    }

    /* Read AVC configuration from file system*/
    eStatus = FSAL_Seek(prSTFSAL, u4ConfigPosition);
    if (eStatus != FSAL_OK)
    {
        *pu4NALuSizeInfo = 0;
        break;
    }

    eStatus = FSAL_Read(prSTFSAL, au1ConfigData, u4ConfigSize);
    if (eStatus != FSAL_OK)
    {
        *pu4NALuSizeInfo = 0;
        break;
    }

    *pu4NALuSizeInfo = (au1ConfigData[MP4_PROVIDER_AVC_CONFIG_REC_SPS_OFFSET - 1] & 0x3) + 1;
#ifdef __VE_DUMP_PROVIDER_BITSTREAM__			
     kal_trace(TRACE_GROUP_1, VE_TRC_H264_NALUSIZELEN, *pu4NALuSizeInfo);
#endif	

    if((*pu4NALuSizeInfo!=4) && (*pu4NALuSizeInfo!=2) && (*pu4NALuSizeInfo!=1))
    {
        *pu4NALuSizeInfo = 0;
        break;

    }
    }while(0);

    return MED_S_OK;
}
#endif /* __VE_H264_DEC_SUPPORT__ */

/*
  MED_S_OK for EOS not reached
  MED_E_OUT_OF_MEMORY for EOS sent fail
  MED_S_PLAY_FINISH for EOS sent successful
  MED_E_ABORTED for EOS sent due to corrupted data
*/
static media_error_t MP4ProviderCheckEOSNotify(MP4_PROVIDER_CTRL_T* prMP4ProviderCtrl, SP_PORT_TYPE_T ePort)
{
    SPIF_PROVIDER_FRAME_INFO_T *prFrameInfo;
    SPIF_VIDEO_STREAM_INFO_T *prVideoSrm = NULL;
    SPIF_AUDIO_STREAM_INFO_T *prAudioSrm = NULL;
    kal_uint32 u4StreamNum;
    kal_uint64 u8StreamDuration = 0;
    kal_uint32 i = 0;
    kal_bool found = KAL_FALSE;

    prFrameInfo = &(prMP4ProviderCtrl->rFrameInfo[ePort]);
    prVideoSrm = prMP4ProviderCtrl->prVidStreamInfo;
    prAudioSrm = prMP4ProviderCtrl->prAudStrmInfo;

    u4StreamNum = prMP4ProviderCtrl->u4VidTrackNum;

    if(ePort==SOURCE_PROVIDER_PORT_VIDEO)
    {
        while(i < u4StreamNum)
        {
            if(prVideoSrm->u4StreamIndex == prMP4ProviderCtrl->au1TrackNo[ePort])
            {
                found = KAL_TRUE;
                u8StreamDuration = prVideoSrm->u8Duration;
                break;
            }
            i++;
            prVideoSrm++;
        }
    }
    else if(ePort==SOURCE_PROVIDER_PORT_AUDIO)
    {
        u4StreamNum = prMP4ProviderCtrl->u4AudTrackNum;
        while(i < u4StreamNum)
        {
            if(prAudioSrm->u4StreamIndex == prMP4ProviderCtrl->au1TrackNo[ePort])
            {
                found = KAL_TRUE;
                u8StreamDuration = prAudioSrm->u8Duration;
                break;
            }
            i++;
            prAudioSrm++;
        }
    }


    MP4_PVDR_ASSERT(found == KAL_TRUE);

    if (!prMP4ProviderCtrl->afgEos[ePort])
    {
        if (prMP4ProviderCtrl->au4CurrSampleNo[ePort] == prMP4ProviderCtrl->au4SampleCount[ePort] ||
            prMP4ProviderCtrl->demux_time[ePort] >= prMP4ProviderCtrl->stop_time ||
            prMP4ProviderCtrl->demux_time[ePort] > (u8StreamDuration + MP4_PROVIDER_DURATION_MARGIN) ||
            ((KAL_TRUE == _MP4ProviderIsPreview(prMP4ProviderCtrl)) && (prMP4ProviderCtrl->au4SampleNoStart[ePort]+1 == prMP4ProviderCtrl->au4CurrSampleNo[ePort]) ||
            prMP4ProviderCtrl->bad_sample_no[ePort] != MP4_PROVIDER_SAMPLE_NO_MAX )
           )
        {
            memset(prFrameInfo, 0, sizeof(SPIF_PROVIDER_FRAME_INFO_T));
            prFrameInfo->fgEof = KAL_TRUE;
            prFrameInfo->u8Timestamp = u8StreamDuration;

            if(prMP4ProviderCtrl->bad_sample_no[ePort] != MP4_PROVIDER_SAMPLE_NO_MAX)
            {
                // To stop at the point data corrupted, not to the stream duration
                prFrameInfo->u8Timestamp = prMP4ProviderCtrl->demux_time[ePort] + 30;
            }

            if (prMP4ProviderCtrl->prSourceAPI->SPFN_ADD_ONE_DATA(prMP4ProviderCtrl->prSourceHandle,
                                                                  ePort, prFrameInfo) == PROVIDER_ERROR_WAIT_RESOURCE)
            {
                prMP4ProviderCtrl->fgResend[ePort] = KAL_TRUE;
                return MED_E_OUT_OF_MEMORY;
            }
            // EOS sent successfully
            kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_EOS, ePort, __LINE__);
            MP4_PROVIDER_TRACE_3_VAL(prMP4ProviderCtrl->au4CurrSampleNo[ePort], prMP4ProviderCtrl->au4SampleCount[ePort], prMP4ProviderCtrl->bad_sample_no[ePort]);
            prMP4ProviderCtrl->afgEos[ePort] = KAL_TRUE;
            if(prMP4ProviderCtrl->bad_sample_no[ePort] != MP4_PROVIDER_SAMPLE_NO_MAX)
            {
                return MED_E_ABORTED;
            }
            return MED_S_PLAY_FINISH;
        }
    }
    return MED_S_OK;
}

#ifdef __VE_KMV_SUPPORT__
static media_error_t MP4ProviderParseKMVMeta(MP4_PROVIDER_CTRL_T* prMP4ProviderCtrl,SP_PORT_TYPE_T ePort)
{
	SPIF_KMV_DECODER_PAYLOAD_INFO_T *prKMVPayload = NULL;
	SPIF_PROVIDER_FRAME_INFO_T *prFrameInfo;
	MP4_Parser_Status e_parser_ret;
#ifdef MP4_PROVIDER_KMV_PROFILING
	kal_uint32 uTime = 0;
#endif


	prFrameInfo = &(prMP4ProviderCtrl->rFrameInfo[ePort]);


//	kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_Elsie2, prMP4ProviderCtrl->au4CurrSampleNo[ePort],__LINE__);

	prFrameInfo->u4KMVPayloadSize = sizeof(SPIF_KMV_DECODER_PAYLOAD_INFO_T);
	prKMVPayload = (SPIF_KMV_DECODER_PAYLOAD_INFO_T *)prMP4ProviderCtrl->prSourceAPI->SPFN_MALLOC_CLA(prMP4ProviderCtrl->prSourceHandle,
																									  sizeof(SPIF_KMV_DECODER_PAYLOAD_INFO_T), KAL_FALSE);
	MP4_PVDR_ASSERT(prKMVPayload != NULL);

	prKMVPayload->tType = prMP4ProviderCtrl->prKmvInfo.m_KMV_type;

#ifdef MP4_PROVIDER_KMV_PROFILING
	uTime = video_get_current_time();
#endif
	e_parser_ret = MP4DMX_ReadKMVMeta(prMP4ProviderCtrl,prMP4ProviderCtrl->au4CurrSampleNo[ePort],&prKMVPayload->tType,
									  &prKMVPayload->recH,
									  &prKMVPayload->recW,
									  &prKMVPayload->kmvMeta[0],
									  &prKMVPayload->nsize);

#ifdef MP4_PROVIDER_KMV_PROFILING
        uTime = video_get_duration_ms(uTime);
#endif

	if (e_parser_ret != MP4_PARSER_OK)
	{
		MP4_PROVIDER_TRACE_PARSE_ERROR(e_parser_ret);
		MP4ProviderMediaDataDealloc(prMP4ProviderCtrl, ePort);
		prMP4ProviderCtrl->prSourceAPI->SPFN_FREE_CLA(prMP4ProviderCtrl->prSourceHandle, prKMVPayload);
		return MED_E_PARSER_ERROR;

	}
	prFrameInfo->pu1KMVPayload = (kal_uint8 *)prKMVPayload;

#ifdef MP4_PROVIDER_KMV_PROFILING
	kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_ReadKMVMeta, uTime);
#endif

    return MED_S_OK;
}

#endif

/*****************************************************************************
 * FUNCTION
 *  MP4ProviderDemuxSampleAV
 * DESCRIPTION
 *  This function is to demux one sample data for specific track type.
 * PARAMETERS
 *  prMP4ProviderCtrl             [IN]     mp4 provider context.
 *  ePort                                [IN]     Track type
 * RETURNS
 *  media_error_t
 *****************************************************************************/
static media_error_t MP4ProviderDemuxSampleAV(MP4_PROVIDER_CTRL_T* prMP4ProviderCtrl,
                                                           SP_PORT_TYPE_T ePort,
                                                           kal_uint32 *pu4Time)
{
    MP4_Parser_Status e_parser_ret;
    kal_uint8* p_sample  = NULL;
    kal_uint32 u_sample_size;
    kal_uint64 composition_time = 0, composition_time_remainder = 0;
    kal_uint32 curr_time = 0; // in ms
    media_error_t ret;
    MP4_PROVIDER_BATCH_READ_T *ptBatch = &(prMP4ProviderCtrl->t_batch[ePort]);
    SPIF_PROVIDER_FRAME_INFO_T *prFrameInfo;
    kal_bool fgResend;
    MP4_Track_Type eType;

    if (!prMP4ProviderCtrl->fgSelectedTrack[ePort])
    {
        return MED_S_FALSE;
    }
    eType = (ePort == SOURCE_PROVIDER_PORT_VIDEO) ? MP4_TRACK_VIDEO : MP4_TRACK_AUDIO;

    prFrameInfo = &(prMP4ProviderCtrl->rFrameInfo[ePort]);
    fgResend = prMP4ProviderCtrl->fgResend[ePort];

    if(fgResend == KAL_TRUE)
    {
        if(prFrameInfo->fgEof == KAL_TRUE)
        {
            // resend EOS
            if (prMP4ProviderCtrl->prSourceAPI->SPFN_ADD_ONE_DATA(prMP4ProviderCtrl->prSourceHandle,
                                                                  ePort, prFrameInfo) == PROVIDER_ERROR_WAIT_RESOURCE)
            {
                prMP4ProviderCtrl->fgResend[ePort] = KAL_TRUE;
                return MED_E_OUT_OF_MEMORY;
            }
            else
            {
                prMP4ProviderCtrl->fgResend[ePort] = KAL_FALSE;
                kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_EOS, ePort, __LINE__);
                prMP4ProviderCtrl->afgEos[ePort] = KAL_TRUE;
                return MED_S_PLAY_FINISH;
            }
        }
        else
        {
            MP4ProviderMediaDataAlloc(prMP4ProviderCtrl, &p_sample, ePort);

            if (prMP4ProviderCtrl->prSourceAPI->SPFN_ADD_ONE_DATA(prMP4ProviderCtrl->prSourceHandle,
                                                              ePort, prFrameInfo) == PROVIDER_ERROR_WAIT_RESOURCE)
            {
                MP4ProviderMediaDataDealloc(prMP4ProviderCtrl, ePort);
                prMP4ProviderCtrl->fgResend[ePort] = KAL_TRUE;
                return MED_E_OUT_OF_MEMORY;
            }
            prMP4ProviderCtrl->prSourceAPI->SPFN_BITSTREAM_BUF_UPDATA_ADD(prMP4ProviderCtrl->prSourceHandle,
                ePort, (kal_uint32)(prFrameInfo->pu1Addr+ prFrameInfo->u4FrameSize));

            if(prFrameInfo->pu1Payload != NULL)
            {
                MP4_PVDR_ASSERT(MEDIA_CODEC_VID_H264 == prMP4ProviderCtrl->prVidStreamInfo->eCodecType &&
                           SOURCE_PROVIDER_PORT_VIDEO == ePort);
                prMP4ProviderCtrl->prSourceAPI->SPFN_FREE_CLA(prMP4ProviderCtrl->prSourceHandle,
                                                              prFrameInfo->pu1Payload);
            }

#ifdef __VE_KMV_SUPPORT__
			if(prFrameInfo->pu1KMVPayload != NULL)
			{
				prMP4ProviderCtrl->prSourceAPI->SPFN_FREE_CLA(prMP4ProviderCtrl->prSourceHandle, prFrameInfo->pu1KMVPayload);
			}
#endif
            if(prMP4ProviderCtrl->au4SampleNoSync[ePort] == prMP4ProviderCtrl->au4CurrSampleNo[ePort])
            {
                // prMP4ProviderCtrl->au4SampleNoSync[ePort] == prMP4ProviderCtrl->au4CurrSampleNo[ePort]
                // MP4_GetCompositionTime and MP4_ChkIsSyncSample should be called for 1st time
                // Add one here for resend case
                prMP4ProviderCtrl->au4SampleNoSync[ePort]++;

            }
            prMP4ProviderCtrl->fgResend[ePort] = KAL_FALSE;
            prMP4ProviderCtrl->au4CurrSampleNo[ePort]++;
            ret = MP4ProviderCheckEOSNotify(prMP4ProviderCtrl, ePort);
            return ret;
        }

    }

    MP4_PVDR_ASSERT(prMP4ProviderCtrl->au4CurrSampleNo[ePort] == (ptBatch->sample_no_start + ptBatch->read_idx));

    memset(prFrameInfo, 0, sizeof(SPIF_PROVIDER_FRAME_INFO_T));

    if ((ptBatch->read_idx != ptBatch->write_idx) &&
        (prMP4ProviderCtrl->bad_sample_no[ePort] == MP4_PROVIDER_SAMPLE_NO_MAX))
    {
        u_sample_size = ptBatch->sample_size[ptBatch->read_idx];

        if (u_sample_size > 0)
        {
            MP4ProviderMediaDataAlloc(prMP4ProviderCtrl, &p_sample, ePort);

            prFrameInfo->pu1Addr = p_sample;
            prFrameInfo->u4FrameSize = u_sample_size;
            prFrameInfo->u4PayloadSize = 0;
            prFrameInfo->pu1Payload = NULL;
            prFrameInfo->fgHeader = KAL_FALSE;
            prFrameInfo->fgKeyFrame = KAL_FALSE;

#ifdef __VE_KMV_SUPPORT__
			if ((KAL_TRUE == _MP4ProviderIsKMV(prMP4ProviderCtrl))&& (SOURCE_PROVIDER_PORT_VIDEO==ePort))
			{
			    ret=MP4ProviderParseKMVMeta(prMP4ProviderCtrl,ePort);
				if(ret!=MED_S_OK)
					return ret;
			}
#endif

        }
        else
        {
            ptBatch->read_idx++;
        }

        if(SOURCE_PROVIDER_PORT_VIDEO == ePort)
        {
            if (prMP4ProviderCtrl->au4SampleNoStart[ePort] == prMP4ProviderCtrl->au4CurrSampleNo[ePort] ||
                prMP4ProviderCtrl->au4SampleNoSync[ePort] == prMP4ProviderCtrl->au4CurrSampleNo[ePort])
            {
                /* must call MP4_ChkIsSyncSample first, or MP4_ChkIsSyncSample_Next can't work */
                e_parser_ret = MP4_ChkIsSyncSample(prMP4ProviderCtrl->pt_parser,
                                                    prMP4ProviderCtrl->au4CurrSampleNo[SOURCE_PROVIDER_PORT_VIDEO],
                                                    MP4_TRACK_VIDEO,
                                                    &(prFrameInfo->fgKeyFrame),
                                                    &prMP4ProviderCtrl->stss_next_index[eType]);
            }
            e_parser_ret = MP4_ChkIsSyncSample_Next(prMP4ProviderCtrl->pt_parser,
                                                    prMP4ProviderCtrl->au4CurrSampleNo[SOURCE_PROVIDER_PORT_VIDEO],
                                                    MP4_TRACK_VIDEO,
                                                    &(prFrameInfo->fgKeyFrame),
                                                    &prMP4ProviderCtrl->stss_next_index[SOURCE_PROVIDER_PORT_VIDEO]);
            if (e_parser_ret != MP4_PARSER_OK)
            {
                MP4_PROVIDER_TRACE_PARSE_ERROR(e_parser_ret);
                MP4ProviderMediaDataDealloc(prMP4ProviderCtrl, SOURCE_PROVIDER_PORT_VIDEO);
#ifdef __VE_KMV_SUPPORT__
		if(prFrameInfo->pu1KMVPayload != NULL)
		{
		prMP4ProviderCtrl->prSourceAPI->SPFN_FREE_CLA(prMP4ProviderCtrl->prSourceHandle, prFrameInfo->pu1KMVPayload);
		}
#endif

                return MED_E_PARSER_ERROR;
            }

            if (MEDIA_CODEC_VID_H264 == prMP4ProviderCtrl->prVidStreamInfo->eCodecType &&
                u_sample_size > prMP4ProviderCtrl->prVideoParamSetData->u4NALuSizeInfo)
            {
            #ifdef __VE_H264_DEC_SUPPORT__
                ret = ProviderUtilityGetAvcSampleNALU(prMP4ProviderCtrl->prSourceAPI,
                                                     prMP4ProviderCtrl->prSourceHandle,
                                                     prFrameInfo,
                                                     prMP4ProviderCtrl->prVideoParamSetData->u4NALuSizeInfo);
                if (ret != MED_S_OK)
                {
                    kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_ERROR, MED_E_OUT_OF_MEMORY, __LINE__);
                    MP4ProviderMediaDataDealloc(prMP4ProviderCtrl, SOURCE_PROVIDER_PORT_VIDEO);
#ifdef __VE_KMV_SUPPORT__
		    if(prFrameInfo->pu1KMVPayload != NULL)
		    {
		    prMP4ProviderCtrl->prSourceAPI->SPFN_FREE_CLA(prMP4ProviderCtrl->prSourceHandle, prFrameInfo->pu1KMVPayload);
		    }
#endif
                    return MED_E_CORRUPTED_DATA;
                }
            #endif
            }
        }

        // MP4_GetCompositionTime will use MP4_GetDecodeTime if no CTTS present. (Audio case)
        if (prMP4ProviderCtrl->au4SampleNoStart[ePort] == prMP4ProviderCtrl->au4CurrSampleNo[ePort] ||
            prMP4ProviderCtrl->au4SampleNoSync[ePort] == prMP4ProviderCtrl->au4CurrSampleNo[ePort])
        {
            e_parser_ret = MP4_GetCompositionTime(prMP4ProviderCtrl->pt_parser,
                                                  prMP4ProviderCtrl->au4CurrSampleNo[ePort],
                                                  &composition_time,
                                                  eType);
        }
        else
        {
            e_parser_ret = MP4_GetCompositionTime_Next(prMP4ProviderCtrl->pt_parser,
                                                       &composition_time,
                                                       eType);
        }
        if (e_parser_ret != MP4_PARSER_OK)
        {
            MP4_PROVIDER_TRACE_PARSE_ERROR(e_parser_ret);
            MP4ProviderMediaDataDealloc(prMP4ProviderCtrl, ePort);
#ifdef __VE_KMV_SUPPORT__
	    if(prFrameInfo->pu1KMVPayload != NULL)
	    {
	    prMP4ProviderCtrl->prSourceAPI->SPFN_FREE_CLA(prMP4ProviderCtrl->prSourceHandle, prFrameInfo->pu1KMVPayload);
	    }
#endif
            return MED_E_PARSER_ERROR;
        }
        curr_time = (kal_uint32)MP4_PROVIDER_TIME_UNITS_TO_MS(composition_time, prMP4ProviderCtrl->au4TimeScale[ePort]);

        #if 1 /* To avoid precision lost. e.g. 33.x ms will be 34 ms to MPL. MPL will set 34 ms to source */
              /* Source will use 34 ms to check. So 33 ms needs t s o be changed as 34 ms */
        composition_time_remainder = (composition_time*(kal_uint64)1000)%(kal_uint64)prMP4ProviderCtrl->au4TimeScale[eType];
        if(composition_time_remainder != 0)
        {
            curr_time++;
        }
        #endif

        if(SOURCE_PROVIDER_PORT_VIDEO == ePort)
        {
            if (prMP4ProviderCtrl->au4SampleNoStart[SOURCE_PROVIDER_PORT_VIDEO] == prMP4ProviderCtrl->au4CurrSampleNo[SOURCE_PROVIDER_PORT_VIDEO] &&
                curr_time > prMP4ProviderCtrl->au4StartTime[SOURCE_PROVIDER_PORT_VIDEO])
            {
                curr_time = prMP4ProviderCtrl->au4StartTime[SOURCE_PROVIDER_PORT_VIDEO];
            }
        }

        if (!(prMP4ProviderCtrl->au4SampleNoStart[ePort] == prMP4ProviderCtrl->au4CurrSampleNo[ePort]))
        {
            if(curr_time > prMP4ProviderCtrl->demux_time[ePort])
            {
                // the duration this demux data can be played
                *pu4Time = curr_time - prMP4ProviderCtrl->demux_time[ePort];
            }
        }
        prMP4ProviderCtrl->demux_time[ePort] = curr_time;

        if (u_sample_size > 0)
        {
            prFrameInfo->u8Timestamp = curr_time;

#ifdef __VE_KMV_SUPPORT__

			if ((KAL_TRUE == _MP4ProviderIsKMV(prMP4ProviderCtrl))&& (SOURCE_PROVIDER_PORT_VIDEO==ePort))
			{
                kal_int32 i= (kal_int32)prFrameInfo->u4PayloadNum,j=0,p_len=0;
				kal_uint8 *p_frame = prFrameInfo->pu1Payload;
				kal_uint8 *p_start=p_sample;
				kal_uint8 p_type = 0;

				if (MEDIA_CODEC_VID_H264 == prMP4ProviderCtrl->prVidStreamInfo->eCodecType)
				{
                    while(i>0)
                    {

					    p_start = p_start+(prMP4ProviderCtrl->prVideoParamSetData->u4NALuSizeInfo+p_len);      //   prFrameInfo->pu1Payload[i].u4Address

                        p_len = (kal_uint32)(p_frame[j*8+4]+(p_frame[j*8+5]<<8)+(p_frame[j*8+6]<<16)+(p_frame[j*8+7]<<24));        // prFrameInfo->pu1Payload[i].u4Length

                        //kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_Elsie2, p_len,__LINE__);

					    p_type = (kal_uint8)p_start[0];

					    switch(p_type&0x1f)
					    {
					        case 1:
						    case 2:
						    case 3:
						    case 4:
						    case 5:
						    case 7:
						    case 8:
						        KMV_DecryptFrame(p_start, p_len, &prMP4ProviderCtrl->Decrypted_Key[0], prMP4ProviderCtrl->prKmvInfo.m_KMV_type);
							    break;
						    default:
							    break;
					    }

                        i--;
					    j++;
				    }
				}
				else
				{
                    KMV_DecryptFrame(p_start, prFrameInfo->u4FrameSize, &prMP4ProviderCtrl->Decrypted_Key[0], prMP4ProviderCtrl->prKmvInfo.m_KMV_type);
				}

			}
#endif


            if (prMP4ProviderCtrl->prSourceAPI->SPFN_ADD_ONE_DATA(prMP4ProviderCtrl->prSourceHandle,
                                                                  ePort, prFrameInfo) == PROVIDER_ERROR_WAIT_RESOURCE)
            {
                MP4ProviderMediaDataDealloc(prMP4ProviderCtrl, ePort);
                prMP4ProviderCtrl->fgResend[ePort] = KAL_TRUE;
                return MED_E_OUT_OF_MEMORY;
            }
            prMP4ProviderCtrl->prSourceAPI->SPFN_BITSTREAM_BUF_UPDATA_ADD(prMP4ProviderCtrl->prSourceHandle,
                ePort, (kal_uint32)p_sample + u_sample_size);
        }

        if(prFrameInfo->pu1Payload != NULL)
        {
            MP4_PVDR_ASSERT(MEDIA_CODEC_VID_H264 == prMP4ProviderCtrl->prVidStreamInfo->eCodecType &&
                       SOURCE_PROVIDER_PORT_VIDEO == ePort);
            prMP4ProviderCtrl->prSourceAPI->SPFN_FREE_CLA(prMP4ProviderCtrl->prSourceHandle,
                                                          prFrameInfo->pu1Payload);
        }
#ifdef __VE_KMV_SUPPORT__
		if(prFrameInfo->pu1KMVPayload != NULL)
		{
			prMP4ProviderCtrl->prSourceAPI->SPFN_FREE_CLA(prMP4ProviderCtrl->prSourceHandle, prFrameInfo->pu1KMVPayload);
		}
#endif

        prMP4ProviderCtrl->au4CurrSampleNo[ePort]++;

    }

    ret = MP4ProviderCheckEOSNotify(prMP4ProviderCtrl, ePort);
    return ret;
}

static media_error_t MP4ProviderGetParameterSetData(MP4_PROVIDER_CTRL_T* prMP4ProviderCtrl,
                                                    STMp4Parser *prSTMp4Parser,
                                                    STFSAL *prSTFSAL,
                                                    MP4_Video_Type u4VideoDecodeType)
{
    PU_VID_PARAM_SET_T *prVideoParamSetData;
    FSAL_Status eStatus;
    kal_uint32 u4ParamPosition;
    SP_API_T *prSrcAPI = prMP4ProviderCtrl->prSourceAPI;

    MP4_PVDR_ASSERT(prMP4ProviderCtrl);

    prVideoParamSetData = prMP4ProviderCtrl->prVideoParamSetData;

    if (!prSTMp4Parser || !prSTFSAL || !prVideoParamSetData)
    {
        MP4_PVDR_ASSERT(0);
        return MED_E_INVALID_PARAM;
    }

    // Get parameter set information
    // MPEG-4 or H.264
    //
    if (MP4_VIDEO_H264 == u4VideoDecodeType)
    {
#ifdef __VE_H264_DEC_SUPPORT__
        media_error_t ret = MED_S_OK;

        // Get AVC information, size info of NAL
        ret = MP4ProviderGetAvcConfigData(prSTMp4Parser,
                                          prSTFSAL,
                                          &prVideoParamSetData->u4NALuSizeInfo);
        if (ret != MED_S_OK)
        {
            return ret;
        }

        u4ParamPosition = MP4_Video_GetParameterSetOffset(prSTMp4Parser, 0);
        prVideoParamSetData->u4ParamSetTotalSize= MP4_Video_GetParameterSetSize(prSTMp4Parser, 0);

        if (prVideoParamSetData->u4ParamSetTotalSize > MP4_PROVIDER_PARAMSET_LENGTH)
        {
            MP4_PROVIDER_TRACE_RET_ERR(prVideoParamSetData->u4ParamSetTotalSize);
            return MED_E_OUT_OF_MEMORY;
        }

        if (!(prVideoParamSetData->u4ParamSetTotalSize == 0))
        {
        prVideoParamSetData->pu1ParamSetBuff =
            (kal_uint8*)prSrcAPI->SPFN_MALLOC_CLA(
                prMP4ProviderCtrl->prSourceHandle, prVideoParamSetData->u4ParamSetTotalSize, KAL_FALSE);
        MP4_PVDR_ASSERT(prVideoParamSetData->pu1ParamSetBuff != NULL);
        prSrcAPI->SPFN_MEM_SET(prVideoParamSetData->pu1ParamSetBuff, 0, prVideoParamSetData->u4ParamSetTotalSize);

        // Read parameter sets from file system
        //
        eStatus = FSAL_Seek(prSTFSAL, u4ParamPosition);
        if (eStatus != FSAL_OK)
        {
            //drv_trace1(TRACE_GROUP_8, VFILE_FSAL_ERROR, eStatus);
            //_VideoFileReaderFailHdlr();
            return MED_E_FSAL_ERROR;
        }

        eStatus = FSAL_Read(prSTFSAL, prVideoParamSetData->pu1ParamSetBuff, prVideoParamSetData->u4ParamSetTotalSize);
        if (eStatus != FSAL_OK)
        {
            //drv_trace1(TRACE_GROUP_8, VFILE_FSAL_ERROR, eStatus);
            //_VideoFileReaderFailHdlr();
            return MED_E_FSAL_ERROR;
        }

        // Obtain Parameter set NAL units
        ProviderUtilityGetParamSetNalUnits(prSrcAPI,
                                          prMP4ProviderCtrl->prSourceHandle,
                                          prVideoParamSetData);
        }
#endif /* __VE_H264_DEC_SUPPORT__ */
    }
    else if (MP4_VIDEO_MPEG4 == u4VideoDecodeType)
    {
        u4ParamPosition = MP4_Video_GetVOSOffset(prSTMp4Parser);
        prVideoParamSetData->u4ParamSetTotalSize = MP4_Video_GetVOSSize(prSTMp4Parser);

        if (prVideoParamSetData->u4ParamSetTotalSize > MP4_PROVIDER_PARAMSET_LENGTH)
        {
            MP4_PROVIDER_TRACE_RET_ERR(prVideoParamSetData->u4ParamSetTotalSize);
            return MED_E_OUT_OF_MEMORY;
        }
        prVideoParamSetData->pu1ParamSetBuff =
           // (kal_uint8*)_mp4_mp_mem_alloc(prMP4ProviderCtrl, SOURCE_PROVIDER_PORT_VIDEO, prVideoParamSetData->u4ParamSetTotalSize, KAL_FALSE, KAL_TRUE);
           (kal_uint8*)prSrcAPI->SPFN_MALLOC_CLA(
                prMP4ProviderCtrl->prSourceHandle, prVideoParamSetData->u4ParamSetTotalSize, KAL_FALSE);
        MP4_PVDR_ASSERT(prVideoParamSetData->pu1ParamSetBuff != NULL);
        prSrcAPI->SPFN_MEM_SET(prVideoParamSetData->pu1ParamSetBuff, 0, prVideoParamSetData->u4ParamSetTotalSize);

        // Read parameter sets from file system
        //
        eStatus = FSAL_Seek(prSTFSAL, u4ParamPosition);
        if (eStatus != FSAL_OK)
        {
            //drv_trace1(TRACE_GROUP_8, VFILE_FSAL_ERROR, eStatus);
            //_VideoFileReaderFailHdlr();
            return MED_E_FSAL_ERROR;
        }

        eStatus = FSAL_Read(prSTFSAL, prVideoParamSetData->pu1ParamSetBuff, prVideoParamSetData->u4ParamSetTotalSize);
        if (eStatus != FSAL_OK)
        {
            //drv_trace1(TRACE_GROUP_8, VFILE_FSAL_ERROR, eStatus);
            //_VideoFileReaderFailHdlr();
            return MED_E_FSAL_ERROR;
        }
    }

    //kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_PARAM_SET_INFO,
        //      prVideoParamSetData->u4ParamSetTotalSize, prVideoParamSetData->u4NumOfNALuParamSet);

    return MED_S_OK;
}

/*****************************************************************************
 * FUNCTION
 *  MP4ProviderOpenCore
 * DESCRIPTION
 *  This function is the core part to open mp4 mp.
 * PARAMETERS
 *  self             [IN]     mp4 mp context.
 * RETURNS
 *  media_error_t
 *****************************************************************************/

#ifdef __VE_MP43GP_MULTI_TRACK__
static PROVIDER_ERROR_T MP4ProviderOpenCore(MP4_PROVIDER_CTRL_T* prMP4ProviderCtrl)
{
#ifdef __VE_PGDL_SUPPORT__
    PROVIDER_ERROR_T ret = PROVIDER_ERROR_NONE;
#endif
    //media_error_t eRet;
    kal_int32 drm_ret;
    FSAL_Status eFsalRet;
    MP4_Parser_Status eParserRet;
    kal_uint8 u1HasAudTrack = MP4_RESERVED_TRACK_NO;
    kal_uint8 u1HasVidTrack = MP4_RESERVED_TRACK_NO;
    MP4_Video_Type eVideoType = MP4_VIDEO_NONE;
    MP4_Audio_Type eAudioType = MP4_AUDIO_NONE;
    SPIF_VIDEO_STREAM_INFO_T *prVidStream;
    SPIF_AUDIO_STREAM_INFO_T *prAudStream;
    kal_uint32 u4Duration;
    SP_API_T *prSrcAPI = prMP4ProviderCtrl->prSourceAPI;
    kal_uint32 u4VideoRet = 0;
    kal_uint32 u4AudioRet = 0;
    kal_uint32 u4VidTrackNum, u4AudTrackNum;
    kal_uint32 i;
#ifdef __VE_KMV_SUPPORT__
	kal_uint32 u4SubtitleRet = 0;
	int errRtl;
#endif

    MP4_PVDR_ASSERT(prSrcAPI);

    /* (2) open media for video */
    if (prMP4ProviderCtrl->eSrcType!= MED_MODE_BUFFER)
    {
        eFsalRet = FSAL_Open(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO], (void*)prMP4ProviderCtrl->u_src.acFileName, FSAL_READ_SHARED);
    }
    else
    {
        FSAL_Direct_SetRamFileSize(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO], prMP4ProviderCtrl->u4FileSize);
        eFsalRet = FSAL_Open(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO], (void*)prMP4ProviderCtrl->u_src.u4FileBufAddr, FSAL_ROMFILE);
    }

    if (eFsalRet != FSAL_OK)
    {
        MP4_PROVIDER_TRACE_FSAL_ERROR(eFsalRet);
        return PROVIDER_ERROR;
    }

    prMP4ProviderCtrl->file_handle = prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO]->hFile;

    if (prMP4ProviderCtrl->eSrcType != MED_MODE_BUFFER)
    {
        /* set buffer for FSAL is not from memory */
        FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO],
                       (kal_uint32)MP4_PROVIDER_FSAL_BUF_SIZE*4,
                       (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf[SOURCE_PROVIDER_PORT_VIDEO]);

        eFsalRet = FSAL_GetFileSize(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO], &(prMP4ProviderCtrl->u4FileSize));
        if (eFsalRet != FSAL_OK)
        {
            //MP4_PROVIDER_TRACE_FSAL_ERROR(eFsalRet);
            return PROVIDER_ERROR;
        }

        {
        kal_uint32 i;
        kal_uint64 temp;

        for (i = MP4_PROVIDER_SEEK_HINT_SIZE; i !=0  ; i--)
        {
            temp = ((kal_uint64)prMP4ProviderCtrl->u4FileSize * (kal_uint64)(i)) / (kal_uint64)(MP4_PROVIDER_SEEK_HINT_SIZE + 1);
            prMP4ProviderCtrl->pt_fsal_seek_hint[i-1].Index = (kal_uint32)temp;
        }
        }

        drm_ret = FSAL_SetSeekHint(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO],
                                    MP4_PROVIDER_SEEK_HINT_SIZE, prMP4ProviderCtrl->pt_fsal_seek_hint);

        if (drm_ret < 0)
        {
            //MP4_PROVIDER_TRACE_RET_ERR(drm_ret);
            return PROVIDER_ERROR;
        }
    }

#ifdef __VE_KMV_SUPPORT__

	if (KAL_TRUE == _MP4ProviderIsKMV(prMP4ProviderCtrl))
	{

		/* info. for KMV subtitle */
		if (prMP4ProviderCtrl->eSrcType != MED_MODE_BUFFER)
		{
			eFsalRet = FSAL_Open(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_SUBTITLE],
												(void*)prMP4ProviderCtrl->u_src.acFileName, FSAL_READ_SHARED);
		}
		else
		{
			FSAL_Direct_SetRamFileSize(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_SUBTITLE], prMP4ProviderCtrl->u4FileSize);
			eFsalRet = FSAL_Open(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_SUBTITLE],
												(void*)prMP4ProviderCtrl->u_src.u4FileBufAddr, FSAL_ROMFILE);
		}

		if (eFsalRet != FSAL_OK)
		{
			u4SubtitleRet = 1;
		}


		if (prMP4ProviderCtrl->eSrcType != MED_MODE_BUFFER)
		{
			drm_ret = FSAL_SetSeekHint(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_SUBTITLE],
										MP4_PROVIDER_SEEK_HINT_SIZE,
										prMP4ProviderCtrl->pt_fsal_seek_hint);
			if (drm_ret < 0)
			{
				u4SubtitleRet = 2;
			}

			FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_SUBTITLE],
						   (kal_uint32)MP4_PROVIDER_FSAL_BUF_SIZE*4,
						   (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf[SOURCE_PROVIDER_PORT_SUBTITLE]);
		}

	}
#endif


    /* (3) enable Parser for video */
    {
    UDTAInfo* prUdataInfo;


    prUdataInfo = (UDTAInfo*)prSrcAPI->SPFN_MALLOC_CLA(prMP4ProviderCtrl->prSourceHandle, sizeof(UDTAInfo), KAL_FALSE);
    MP4_PVDR_ASSERT(prUdataInfo != NULL);
    prSrcAPI->SPFN_MEM_SET(prUdataInfo, 0, sizeof(UDTAInfo));
    prMP4ProviderCtrl->pt_parser->OpenType = prMP4ProviderCtrl->eSrcType;
    eParserRet = MP4_Parse_UDTAExt(prMP4ProviderCtrl->pt_parser, prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO],
                                     (void*)prUdataInfo, sizeof(UDTAInfo));

    if (eParserRet != MP4_PARSER_OK && eParserRet != MP4_PARSER_WARNING_TRAILING_GARBAGE)
    {
        MP4_PROVIDER_TRACE_PARSE_ERROR(eParserRet);
	prMP4ProviderCtrl->pt_parser->OpenType = prMP4ProviderCtrl->eSrcType;
        eParserRet = MP4_Parse(prMP4ProviderCtrl->pt_parser, prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO]);

        if (eParserRet != MP4_PARSER_OK && eParserRet != MP4_PARSER_WARNING_TRAILING_GARBAGE)
        {
            MP4_PROVIDER_TRACE_PARSE_ERROR(eParserRet);
            return PROVIDER_ERROR;
            }
        }
    }


#ifdef __VE_KMV_SUPPORT__
	if (KAL_TRUE == _MP4ProviderIsKMV(prMP4ProviderCtrl))
    {
		prMP4ProviderCtrl->u4KMVFileLen = prMP4ProviderCtrl->pt_parser->u4KMVFileLen;
		prMP4ProviderCtrl->u4UUIDFileLen = prMP4ProviderCtrl->pt_parser->u4UUIDFileLen;

    errRtl = MP4DMX_InitKMVMeta(prMP4ProviderCtrl, 0);
    if (errRtl != KMV_SUCCESS)
    {
        MP4_PROVIDER_TRACE_PARSE_ERROR(errRtl);
        return PROVIDER_ERROR;
    }

        i = 0;
        do{
            eFsalRet = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_stsz[SOURCE_PROVIDER_PORT_SUBTITLE], prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_SUBTITLE]);
            if (eFsalRet != FSAL_OK)
            {
                i = __LINE__;
                break;
            }

            eFsalRet = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_stco[SOURCE_PROVIDER_PORT_SUBTITLE], prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_SUBTITLE]);
            if (eFsalRet != FSAL_OK)
            {
                i = __LINE__;
                break;
            }

            eFsalRet = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_map, prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_SUBTITLE]);
            if (eFsalRet != FSAL_OK)
            {
                i = __LINE__;
                break;
            }

        }while(0);

        if(i != 0)
        {
            kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_FSAL_ERROR, eFsalRet, i);
            return PROVIDER_ERROR;
        }

		if (prMP4ProviderCtrl->eSrcType != MED_MODE_BUFFER)
        {
            FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal_stco[SOURCE_PROVIDER_PORT_SUBTITLE],
                       MP4_PROVIDER_STCO_BUF_SIZE*4,
                       (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf_stco[SOURCE_PROVIDER_PORT_SUBTITLE]);
            FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal_stsz[SOURCE_PROVIDER_PORT_SUBTITLE],
                       MP4_PROVIDER_STSZ_BUF_SIZE*4,
                       (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf_stsz[SOURCE_PROVIDER_PORT_SUBTITLE]);
            FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal_map,
                       MP4_PROVIDER_MAP_BUF_SIZE*4,
                       (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf_map);
        }

    }
#endif

    u4VidTrackNum = MP4_GetTrackNum(prMP4ProviderCtrl->pt_parser, MP4_TRACK_VIDEO);
    /* check if there is any video track */
    if (!(prMP4ProviderCtrl->eTrack & SOURCE_PROVIDER_TRACK_VIDEO))        
    {
        u1HasVidTrack = MP4_RESERVED_TRACK_NO;
    }
    else if (u4VidTrackNum > 0)
    {
        for(i=0; i<u4VidTrackNum; i++)
        {
            u1HasVidTrack = MP4_GetTrackNoByTypeIdx(prMP4ProviderCtrl->pt_parser, MP4_TRACK_VIDEO, i);
            MP4_SetTrackIndex(prMP4ProviderCtrl->pt_parser, u1HasVidTrack);
            eVideoType = MP4_GetVideoType(prMP4ProviderCtrl->pt_parser);
            if (eVideoType == MP4_VIDEO_NONE)
            {
                u1HasVidTrack = MP4_RESERVED_TRACK_NO;
            }
            else if(KAL_TRUE == _MP4ProviderCheckCodecSupport(MP4_TRACK_VIDEO, eVideoType))
                {
                    break;
                }
        }
        if(i == u4VidTrackNum)
        {
            u1HasVidTrack = MP4_RESERVED_TRACK_NO;
        }
    }
    prMP4ProviderCtrl->au1TrackNo[SOURCE_PROVIDER_PORT_VIDEO] = u1HasVidTrack;

    u4AudTrackNum = MP4_GetTrackNum(prMP4ProviderCtrl->pt_parser, MP4_TRACK_AUDIO);
    /* check if there is any audio track */
    if (!(prMP4ProviderCtrl->eTrack & SOURCE_PROVIDER_TRACK_AUDIO)) 
    {
        u1HasAudTrack = MP4_RESERVED_TRACK_NO;
    }
    else if (u4AudTrackNum > 0)
    {
        for(i=0; i<u4AudTrackNum; i++)
        {
            u1HasAudTrack = MP4_GetTrackNoByTypeIdx(prMP4ProviderCtrl->pt_parser, MP4_TRACK_AUDIO, i);
            MP4_SetTrackIndex(prMP4ProviderCtrl->pt_parser, u1HasAudTrack);
            eAudioType = MP4_GetAudioType(prMP4ProviderCtrl->pt_parser);
            if (eAudioType == MP4_AUDIO_NONE)
            {
                u1HasAudTrack = MP4_RESERVED_TRACK_NO;
            }
            else if(KAL_TRUE == _MP4ProviderCheckCodecSupport(MP4_TRACK_AUDIO, eAudioType))
                {
                    break;
                }
        }
        if(i == u4AudTrackNum)
        {
            u1HasAudTrack = MP4_RESERVED_TRACK_NO;
        }
    }
    prMP4ProviderCtrl->au1TrackNo[SOURCE_PROVIDER_PORT_AUDIO] = u1HasAudTrack;

    if (u1HasVidTrack == MP4_RESERVED_TRACK_NO && u1HasAudTrack == MP4_RESERVED_TRACK_NO)
    {
        if ((prMP4ProviderCtrl->eTrack == SOURCE_PROVIDER_TRACK_AUDIO) || (prMP4ProviderCtrl->eTrack == SOURCE_PROVIDER_TRACK_VIDEO))
        {
            MP4_PROVIDER_TRACE_RET_ERR(MED_E_NO_REQUIRED_TRACK);
        }
        else
        {
            MP4_PROVIDER_TRACE_RET_ERR(MED_E_OPEN_FILE_FAIL);
        }
            return PROVIDER_ERROR_NONE;
    }

    i = 0;
    do{
        eFsalRet = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_mdat[SOURCE_PROVIDER_PORT_VIDEO], prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO]);
        if (eFsalRet != FSAL_OK)
        {
            i = __LINE__;
            break;
        }

        eFsalRet = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_stco[SOURCE_PROVIDER_PORT_VIDEO], prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO]);
        if (eFsalRet != FSAL_OK)
        {
            i = __LINE__;
            break;
        }

        eFsalRet = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_stss[SOURCE_PROVIDER_PORT_VIDEO], prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO]);
        if (eFsalRet != FSAL_OK)
        {
            i = __LINE__;
            break;
        }

        eFsalRet = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_stsz[SOURCE_PROVIDER_PORT_VIDEO], prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO]);
        if (eFsalRet != FSAL_OK)
        {
            i = __LINE__;
            break;
        }

        eFsalRet = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_stts[SOURCE_PROVIDER_PORT_VIDEO], prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO]);
        if (eFsalRet != FSAL_OK)
        {
            i = __LINE__;
            break;
        }
    }while(0);

    if(i != 0)
    {
        kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_FSAL_ERROR, eFsalRet, i);
        return PROVIDER_ERROR;
    }

    if (prMP4ProviderCtrl->eSrcType != MED_MODE_BUFFER)
    {
        FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal_stco[SOURCE_PROVIDER_PORT_VIDEO],
                       MP4_PROVIDER_STCO_BUF_SIZE*4,
                       (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf_stco[SOURCE_PROVIDER_PORT_VIDEO]);
        FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal_stsz[SOURCE_PROVIDER_PORT_VIDEO],
                       MP4_PROVIDER_STSZ_BUF_SIZE*4,
                       (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf_stsz[SOURCE_PROVIDER_PORT_VIDEO]);
        FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal_stss[SOURCE_PROVIDER_PORT_VIDEO],
                       MP4_PROVIDER_STSS_BUF_SIZE*4,
                       (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf_stss[SOURCE_PROVIDER_PORT_VIDEO]);
        FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal_stts[MP4_TRACK_VIDEO],
                       MP4_PROVIDER_STTS_BUF_SIZE*4,
                       (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf_stts[MP4_TRACK_VIDEO]);
    }

    MP4_SetFSAL_STCO(prMP4ProviderCtrl->pt_parser, MP4_TRACK_VIDEO, prMP4ProviderCtrl->pt_fsal_stco[SOURCE_PROVIDER_PORT_VIDEO]);
    MP4_SetFSAL_STSZ(prMP4ProviderCtrl->pt_parser, MP4_TRACK_VIDEO, prMP4ProviderCtrl->pt_fsal_stsz[SOURCE_PROVIDER_PORT_VIDEO]);
    MP4_SetFSAL_STSS(prMP4ProviderCtrl->pt_parser, MP4_TRACK_VIDEO, prMP4ProviderCtrl->pt_fsal_stss[SOURCE_PROVIDER_PORT_VIDEO]);
    MP4_SetFSAL_STTS(prMP4ProviderCtrl->pt_parser, MP4_TRACK_VIDEO, prMP4ProviderCtrl->pt_fsal_stts[SOURCE_PROVIDER_PORT_VIDEO]);
    MP4_STBL_CacheTablePreprocess(prMP4ProviderCtrl->pt_parser, prMP4ProviderCtrl->p_stbl_buf, MP4_PROVIDER_STBL_BUF_SIZE);

    eParserRet =  MP4_GetMovieTimeScaleDuration(prMP4ProviderCtrl->pt_parser,
                                                  &prMP4ProviderCtrl->u4MovieTimeScale,
                                                  &prMP4ProviderCtrl->u4MovieDuration);
    if (eParserRet != MP4_PARSER_OK)
    {
        MP4_PROVIDER_TRACE_PARSE_ERROR(eParserRet);
        return PROVIDER_ERROR;
    }
    else if (prMP4ProviderCtrl->u4MovieTimeScale != 0)
    {
        prMP4ProviderCtrl->u4MovieDuration = MP4_PROVIDER_TIME_UNITS_TO_MS(prMP4ProviderCtrl->u4MovieDuration,
                                                                        prMP4ProviderCtrl->u4MovieTimeScale);
    }

    /* (4) notify client if there is any video track */
    do
    {
    if (u1HasVidTrack != MP4_RESERVED_TRACK_NO)
    {
        MP4_PVDR_ASSERT(u1HasVidTrack < MP4_NUM_TRACKS);
        prMP4ProviderCtrl->eTrackType[u1HasVidTrack] = SOURCE_PROVIDER_PORT_VIDEO;

        /* allocate media_stream_t */
        if (prMP4ProviderCtrl->prVidStreamInfo == NULL)
        {
           prMP4ProviderCtrl->prVidStreamInfo = (SPIF_VIDEO_STREAM_INFO_T*)prSrcAPI->SPFN_MALLOC_CLA(
                                                            prMP4ProviderCtrl->prSourceHandle, sizeof(SPIF_VIDEO_STREAM_INFO_T)*u4VidTrackNum, KAL_FALSE);
           if (prMP4ProviderCtrl->prVidStreamInfo == NULL)
           {
               u4VideoRet = 1;
               break;
           }
           prSrcAPI->SPFN_MEM_SET(prMP4ProviderCtrl->prVidStreamInfo, 0, sizeof(SPIF_VIDEO_STREAM_INFO_T)*u4VidTrackNum);
        }

        prVidStream = prMP4ProviderCtrl->prVidStreamInfo;
        for(i=0; i<u4VidTrackNum; i++)
        {
            u1HasVidTrack = MP4_GetTrackNoByTypeIdx(prMP4ProviderCtrl->pt_parser, MP4_TRACK_VIDEO, i);
            MP4_SetTrackIndex(prMP4ProviderCtrl->pt_parser, u1HasVidTrack);
            eVideoType = MP4_GetVideoType(prMP4ProviderCtrl->pt_parser);
            if (eVideoType == MP4_VIDEO_NONE)
            {
                u1HasVidTrack = MP4_RESERVED_TRACK_NO;
            }
            else
            {
                if(KAL_TRUE == _MP4ProviderCheckCodecSupport(MP4_TRACK_VIDEO, eVideoType))
                {
                    u4VideoRet = 0;
                    prVidStream->u4StreamIndex = u1HasVidTrack;
                    do {

                        MP4_SetFSAL_STCO(prMP4ProviderCtrl->pt_parser, MP4_TRACK_VIDEO, prMP4ProviderCtrl->pt_fsal_stco[SOURCE_PROVIDER_PORT_VIDEO]);
                        MP4_SetFSAL_STSZ(prMP4ProviderCtrl->pt_parser, MP4_TRACK_VIDEO, prMP4ProviderCtrl->pt_fsal_stsz[SOURCE_PROVIDER_PORT_VIDEO]);
                        MP4_SetFSAL_STSS(prMP4ProviderCtrl->pt_parser, MP4_TRACK_VIDEO, prMP4ProviderCtrl->pt_fsal_stss[SOURCE_PROVIDER_PORT_VIDEO]);
                        MP4_SetFSAL_STTS(prMP4ProviderCtrl->pt_parser, MP4_TRACK_VIDEO, prMP4ProviderCtrl->pt_fsal_stts[SOURCE_PROVIDER_PORT_VIDEO]);

                        eParserRet =  MP4_GetMediaTimeScale(prMP4ProviderCtrl->pt_parser,
                                              &(prMP4ProviderCtrl->au4TimeScale[SOURCE_PROVIDER_PORT_VIDEO]),
                                              MP4_TRACK_VIDEO);
                        if (eParserRet != MP4_PARSER_OK || prMP4ProviderCtrl->au4TimeScale[SOURCE_PROVIDER_PORT_VIDEO] == 0)
                        {
                            u4VideoRet = 2;
                            break;
                        }

                        eParserRet = MP4_GetMediaDuration(prMP4ProviderCtrl->pt_parser, &u4Duration, MP4_TRACK_VIDEO);
                        if (eParserRet != MP4_PARSER_OK)
                        {
                            u4VideoRet = 3;
                            break;

                        }
                        else if (u4Duration == 0)
                        {
                            u4VideoRet = 4;
                            break;
                        }
                        prVidStream->u8Duration = MP4_PROVIDER_TIME_UNITS_TO_MS(u4Duration, prMP4ProviderCtrl->au4TimeScale[SOURCE_PROVIDER_PORT_VIDEO]);

                        eParserRet = MP4_GetVideoResolution(prMP4ProviderCtrl->pt_parser,
                                                              &(prVidStream->u4Width), &(prVidStream->u4Height));
                        if (eParserRet != MP4_PARSER_OK
                            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
                            #endif
                            )
                        {
                            u4VideoRet = 5;
                            break;
                        }
                        prVidStream->u4Fps = 0;

                        prVidStream->u4AvgBitrate =prMP4ProviderCtrl->u4FileSize*8/(prVidStream->u8Duration+1)*1000; // bps

                        eParserRet = MP4_GetSampleCount(prMP4ProviderCtrl->pt_parser,
                                                          MP4_TRACK_VIDEO,
                                                          &prMP4ProviderCtrl->au4SampleCount[SOURCE_PROVIDER_PORT_VIDEO]);
                        if (eParserRet != MP4_PARSER_OK)
                        {
                            u4VideoRet = 7;
                            break;
                        }
                        /* to calculate the average frame rate */
                        if (u4Duration > 0)
                        {
                            kal_uint64 u8Fps = 0;

                            u8Fps = (kal_uint64)prMP4ProviderCtrl->au4SampleCount[SOURCE_PROVIDER_PORT_VIDEO] *
                                (kal_uint64)prMP4ProviderCtrl->au4TimeScale[SOURCE_PROVIDER_PORT_VIDEO] * 100 / (kal_uint64)u4Duration ;
                            prVidStream->u4Fps = (kal_uint32)u8Fps;

                            #if 0 // Not to block frame rate. Best effort decode & display
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                            #endif
                        }

                        #ifdef __VE_PRIRATE_3D_FORMAT__
                        if(MP4_IsVideo3DTrack(prMP4ProviderCtrl->pt_parser, u1HasVidTrack))
                        {
                            prVidStream->eProperty = SOURCE_PROVIDER_TRACK_PRIVATE_3D;
                        }
                        #endif
                        switch (eVideoType)
                        {
                        case MP4_VIDEO_MPEG4:
                            prVidStream->eCodecType = MEDIA_CODEC_VID_MPEG4;
                            break;

                        case MP4_VIDEO_H263:
                            prVidStream->eCodecType = MEDIA_CODEC_VID_H263;
                            break;

                        case MP4_VIDEO_H264:
                            prVidStream->eCodecType = MEDIA_CODEC_VID_H264;
                            break;

                        case MP4_VIDEO_MJPG:
                            prVidStream->eCodecType = MEDIA_CODEC_VID_MJPG;
                            break;

                        default:
                            u4VideoRet = 12;
                            break;
                        }
                    } while(0);

                    if(u4VideoRet != 0)
                    {
                        kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_INVALID_TRACK,
                            u1HasVidTrack, u4VideoRet, __LINE__);
                    }
                    else
                    {
                        kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_HAS_VIDEO,
                          prVidStream->eCodecType,
                          u1HasVidTrack,
                          prMP4ProviderCtrl->au4SampleCount[SOURCE_PROVIDER_PORT_VIDEO],
                          (kal_uint32)prVidStream->u8Duration);

                        prMP4ProviderCtrl->eTrackType[u1HasVidTrack] = SOURCE_PROVIDER_PORT_VIDEO;
                        prMP4ProviderCtrl->u4VidTrackNum++;
                        prVidStream++;
                    }
                }
            }
        }
    }
    } while (0);

    if((u4VideoRet != 0) || (prMP4ProviderCtrl->u4VidTrackNum==0))
    {
        if (prMP4ProviderCtrl->prVidStreamInfo)
        {
            prSrcAPI->SPFN_FREE_CLA(prMP4ProviderCtrl->prSourceHandle, prMP4ProviderCtrl->prVidStreamInfo);
        }
        prMP4ProviderCtrl->prVidStreamInfo = NULL;
        prMP4ProviderCtrl->au1TrackNo[SOURCE_PROVIDER_PORT_VIDEO] = MP4_RESERVED_TRACK_NO;
        MP4_PROVIDER_TRACE_RET_ERR(u4VideoRet);
    }

    do
    {
    if (u1HasAudTrack != MP4_RESERVED_TRACK_NO)
    {
        /* (5) open media for audio */
        if (prMP4ProviderCtrl->eSrcType != MED_MODE_BUFFER)
        {
            eFsalRet = FSAL_Open(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO],
                                                (void*)prMP4ProviderCtrl->u_src.acFileName, FSAL_READ_SHARED);
        }
        else
        {
            FSAL_Direct_SetRamFileSize(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO], prMP4ProviderCtrl->u4FileSize);
            eFsalRet = FSAL_Open(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO],
                                                (void*)prMP4ProviderCtrl->u_src.u4FileBufAddr, FSAL_ROMFILE);
        }

        if (eFsalRet != FSAL_OK)
        {
            u4AudioRet = 1;
            break;
        }

        if (prMP4ProviderCtrl->eSrcType != MED_MODE_BUFFER)
        {
            drm_ret = FSAL_SetSeekHint(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO],
                                        MP4_PROVIDER_SEEK_HINT_SIZE,
                                        prMP4ProviderCtrl->pt_fsal_seek_hint);
            if (drm_ret < 0)
            {
                u4AudioRet = 2;
                break;
            }

            FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO],
                           (kal_uint32)MP4_PROVIDER_FSAL_BUF_SIZE*4,
                           (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf[SOURCE_PROVIDER_PORT_AUDIO]);
        }
        /* (6) enable Parser for audio */
        MP4_PVDR_ASSERT(u1HasAudTrack < MP4_NUM_TRACKS);
        prMP4ProviderCtrl->eTrackType[u1HasAudTrack] = SOURCE_PROVIDER_PORT_AUDIO;

        eFsalRet = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_mdat[SOURCE_PROVIDER_PORT_AUDIO], prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO]);
        if (eFsalRet != FSAL_OK)
        {
            u4AudioRet = 3;
            break;
        }

        eFsalRet = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_stco[SOURCE_PROVIDER_PORT_AUDIO], prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO]);
        if (eFsalRet != FSAL_OK)
        {
            u4AudioRet = 4;
            break;
        }

        eFsalRet = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_stsz[SOURCE_PROVIDER_PORT_AUDIO], prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO]);
        if (eFsalRet != FSAL_OK)
        {
            u4AudioRet = 5;
            break;
        }

        eFsalRet = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_stts[SOURCE_PROVIDER_PORT_AUDIO], prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO]);
        if (eFsalRet != FSAL_OK)
        {
            u4AudioRet = 5;
            break;
        }

        if (prMP4ProviderCtrl->eSrcType != MED_MODE_BUFFER)
        {
            FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal_stco[SOURCE_PROVIDER_PORT_AUDIO],
                           MP4_PROVIDER_STCO_BUF_SIZE*4,
                           (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf_stco[SOURCE_PROVIDER_PORT_AUDIO]);
            FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal_stsz[SOURCE_PROVIDER_PORT_AUDIO],
                           MP4_PROVIDER_STSZ_BUF_SIZE*4,
                           (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf_stsz[SOURCE_PROVIDER_PORT_AUDIO]);
            FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal_stts[SOURCE_PROVIDER_PORT_AUDIO],
                           MP4_PROVIDER_STTS_BUF_SIZE*4,
                           (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf_stts[SOURCE_PROVIDER_PORT_AUDIO]);
        }

        /* (7) notify client if there is any audio track */
        /* allocate media_stream_t */
        if (prMP4ProviderCtrl->prAudStrmInfo == NULL)
        {
           prMP4ProviderCtrl->prAudStrmInfo = (SPIF_AUDIO_STREAM_INFO_T*)prSrcAPI->SPFN_MALLOC_CLA(
                                                                                prMP4ProviderCtrl->prSourceHandle, sizeof(SPIF_AUDIO_STREAM_INFO_T)*u4AudTrackNum, KAL_FALSE);
           if (prMP4ProviderCtrl->prAudStrmInfo == NULL)
           {
               u4AudioRet = 6;
               break;
           }
           prSrcAPI->SPFN_MEM_SET(prMP4ProviderCtrl->prAudStrmInfo, 0, sizeof(SPIF_AUDIO_STREAM_INFO_T)*u4AudTrackNum);
        }


        prAudStream = prMP4ProviderCtrl->prAudStrmInfo;

        for(i=0; i<u4AudTrackNum; i++)
        {
            u1HasAudTrack = MP4_GetTrackNoByTypeIdx(prMP4ProviderCtrl->pt_parser, MP4_TRACK_AUDIO, i);
            MP4_SetTrackIndex(prMP4ProviderCtrl->pt_parser, u1HasAudTrack);
            eAudioType = MP4_GetAudioType(prMP4ProviderCtrl->pt_parser);
            if (eAudioType == MP4_AUDIO_NONE)
            {
                u1HasAudTrack = MP4_RESERVED_TRACK_NO;
            }
            else
            {
                if(KAL_TRUE == _MP4ProviderCheckCodecSupport(MP4_TRACK_AUDIO, eAudioType))
                {
                    u4AudioRet = 0;
                    prAudStream->u4StreamIndex = u1HasAudTrack;
                    do{

                        MP4_SetFSAL_STCO(prMP4ProviderCtrl->pt_parser, MP4_TRACK_AUDIO,
                                                            prMP4ProviderCtrl->pt_fsal_stco[SOURCE_PROVIDER_PORT_AUDIO]);
                        MP4_SetFSAL_STSZ(prMP4ProviderCtrl->pt_parser, MP4_TRACK_AUDIO,
                                                            prMP4ProviderCtrl->pt_fsal_stsz[SOURCE_PROVIDER_PORT_AUDIO]);
                        MP4_SetFSAL_STTS(prMP4ProviderCtrl->pt_parser, MP4_TRACK_AUDIO,
                                                            prMP4ProviderCtrl->pt_fsal_stts[SOURCE_PROVIDER_PORT_AUDIO]);

                        MP4_UpdateSampleCount(prMP4ProviderCtrl->pt_parser, MP4_TRACK_AUDIO);

                        eParserRet = MP4_GetMediaTimeScale(prMP4ProviderCtrl->pt_parser,
                                                             &(prMP4ProviderCtrl->au4TimeScale[SOURCE_PROVIDER_PORT_AUDIO]),
                                                             MP4_TRACK_AUDIO);
                        if (eParserRet != MP4_PARSER_OK || prMP4ProviderCtrl->au4TimeScale[SOURCE_PROVIDER_PORT_AUDIO] == 0)
                        {
                            u4AudioRet = 7;
                            break;
                        }

                        eParserRet = MP4_GetMediaDuration(prMP4ProviderCtrl->pt_parser, &u4Duration, MP4_TRACK_AUDIO);
                        if (eParserRet != MP4_PARSER_OK)
                        {
                            u4AudioRet = 8;
                            break;

                        }
                        else if (u4Duration == 0)
                        {
                            u4AudioRet = 9;
                            break;
                        }
                        prAudStream->u8Duration = MP4_PROVIDER_TIME_UNITS_TO_MS(u4Duration, prMP4ProviderCtrl->au4TimeScale[SOURCE_PROVIDER_PORT_AUDIO]);

                        prAudStream->u2Channels = MP4_Audio_GetChannelCount(prMP4ProviderCtrl->pt_parser);
                        prAudStream->u2BitsPerSample = MP4_Audio_GetSampleSize(prMP4ProviderCtrl->pt_parser); /* default value of 16 */
                        prAudStream->u4SampleRate = MP4_Audio_GetSamplingFreq(prMP4ProviderCtrl->pt_parser);
                        eParserRet = MP4_GetSampleCount(prMP4ProviderCtrl->pt_parser,
                                                          MP4_TRACK_AUDIO,
                                                          &prMP4ProviderCtrl->au4SampleCount[SOURCE_PROVIDER_PORT_AUDIO]);
                        if (eParserRet != MP4_PARSER_OK)
                        {
                            u4AudioRet = 10;
                            break;
                        }

                        prAudStream->u4FrameDuration = 0;
                        prAudStream->fgAddHeader = KAL_FALSE;

                        switch (eAudioType)
                        {
                        case MP4_AUDIO_AAC:
                            prAudStream->eCodecType = MEDIA_CODEC_AUD_AAC;
                            prAudStream->fgAddHeader = KAL_TRUE;
                            break;

                        case MP4_AUDIO_AMR:
                            prAudStream->eCodecType = MEDIA_CODEC_AUD_AMR;
                            break;

                        case MP4_AUDIO_AMR_WB:
                            prAudStream->eCodecType = MEDIA_CODEC_AUD_AMR_WB;
                            break;

                        case MP4_AUDIO_BSAC:
                            prAudStream->eCodecType = MEDIA_CODEC_AUD_BSAC;
                            break;

                        case MP4_AUDIO_MP3:
                            prAudStream->eCodecType = MEDIA_CODEC_AUD_MPEGLAYER3;
                            break;
                        default:
                            u4AudioRet = 11;
                            break;

                        }
                    }while(0);
                    if(u4AudioRet != 0)
                    {
                        kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_INVALID_TRACK,
                            u1HasAudTrack, u4AudioRet, __LINE__);
                    }
                    else
                    {
                        kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_HAS_AUDIO,
                                  prAudStream->eCodecType,
                                  u1HasAudTrack,
                                  prMP4ProviderCtrl->au4SampleCount[SOURCE_PROVIDER_PORT_AUDIO],
                                  (kal_uint32)prAudStream->u8Duration);

                        prMP4ProviderCtrl->eTrackType[u1HasAudTrack] = SOURCE_PROVIDER_PORT_AUDIO;
                        prMP4ProviderCtrl->u4AudTrackNum++;
                        prAudStream++;
                    }
                }
            }
        }

    }
    } while (0);
    if((u4AudioRet != 0) || (prMP4ProviderCtrl->u4AudTrackNum==0))
    {
        if (prMP4ProviderCtrl->prAudStrmInfo)
        {
            prSrcAPI->SPFN_FREE_CLA(prMP4ProviderCtrl->prSourceHandle, prMP4ProviderCtrl->prAudStrmInfo);
        }
        prMP4ProviderCtrl->prAudStrmInfo = NULL;
        prMP4ProviderCtrl->au1TrackNo[SOURCE_PROVIDER_PORT_AUDIO] = MP4_RESERVED_TRACK_NO;
        MP4_PROVIDER_TRACE_RET_ERR(u4AudioRet);
    }


    if (!MP4_PROVIDER_HAS_TRACK(SOURCE_PROVIDER_PORT_AUDIO) && !MP4_PROVIDER_HAS_TRACK(SOURCE_PROVIDER_PORT_VIDEO))
    {
        //MP4_PROVIDER_TRACE_RET_ERR(MED_E_CORRUPTED_DATA);
        return PROVIDER_ERROR;
    }
    /* default is to select */
    if (MP4_PROVIDER_HAS_TRACK(SOURCE_PROVIDER_PORT_AUDIO))
    {
        prMP4ProviderCtrl->fgSelectedTrack[SOURCE_PROVIDER_PORT_AUDIO] = KAL_TRUE;
    }
    if (MP4_PROVIDER_HAS_TRACK(SOURCE_PROVIDER_PORT_VIDEO))
    {
        prMP4ProviderCtrl->fgSelectedTrack[SOURCE_PROVIDER_PORT_VIDEO] = KAL_TRUE;
    }

#ifdef __VE_PGDL_SUPPORT__
    ret = MP4ProviderOpenPDLFile(prMP4ProviderCtrl);
    if (ret != PROVIDER_ERROR_NONE)
    {
        return ret;
    }
#endif

    /* init sample memory pool after _mp4_mp_open_core() */
    //_mp4_mp_sample_buf_init(prMP4ProviderCtrl, SOURCE_PROVIDER_PORT_VIDEO);

    return PROVIDER_ERROR_NONE;
}

#else
static PROVIDER_ERROR_T MP4ProviderOpenCore(MP4_PROVIDER_CTRL_T* prMP4ProviderCtrl)
{
    PROVIDER_ERROR_T ret = PROVIDER_ERROR_NONE;
    media_error_t eRet;
    kal_int32 drm_ret;
    FSAL_Status eFsalRet;
    MP4_Parser_Status eParserRet;
    kal_uint8 u1HasAudTrack = MP4_RESERVED_TRACK_NO;
    kal_uint8 u1HasVidTrack = MP4_RESERVED_TRACK_NO;
    MP4_Video_Type eVideoType = MP4_VIDEO_NONE;
    MP4_Audio_Type eAudioType = MP4_AUDIO_NONE;
    SPIF_VIDEO_STREAM_INFO_T *prVidStream = NULL;
    SPIF_AUDIO_STREAM_INFO_T *prAudStream = NULL;
    kal_uint32 u4Duration;
    SP_API_T *prSrcAPI = prMP4ProviderCtrl->prSourceAPI;
    kal_uint32 u4VideoRet = 0;
    kal_uint32 u4AudioRet = 0;

    MP4_PVDR_ASSERT(prSrcAPI);

    /* (2) open media for video */
    if (prMP4ProviderCtrl->eSrcType!= MED_MODE_BUFFER)
    {
        eFsalRet = FSAL_Open(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO], (void*)prMP4ProviderCtrl->u_src.acFileName, FSAL_READ_SHARED);
    }
    else
    {
        FSAL_Direct_SetRamFileSize(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO], prMP4ProviderCtrl->u4FileSize);
        eFsalRet = FSAL_Open(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO], (void*)prMP4ProviderCtrl->u_src.u4FileBufAddr, FSAL_ROMFILE);
    }

    if (eFsalRet != FSAL_OK)
    {
        MP4_PROVIDER_TRACE_FSAL_ERROR(eFsalRet);
        return PROVIDER_ERROR;
    }
    prMP4ProviderCtrl->file_handle = prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO]->hFile;

    if (prMP4ProviderCtrl->eSrcType != MED_MODE_BUFFER)
    {
        /* set buffer for FSAL is not from memory */
        FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO],
                       (kal_uint32)MP4_PROVIDER_FSAL_BUF_SIZE*4,
                       (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf[SOURCE_PROVIDER_PORT_VIDEO]);

        eFsalRet = FSAL_GetFileSize(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO], &(prMP4ProviderCtrl->u4FileSize));
        if (eFsalRet != FSAL_OK)
        {
            //MP4_PROVIDER_TRACE_FSAL_ERROR(eFsalRet);
            return PROVIDER_ERROR;
        }

        {
        kal_uint32 i;
        kal_uint64 temp;

        for(i=MP4_PROVIDER_SEEK_HINT_SIZE; i!=0; i--)
        {
            temp = ((kal_uint64)prMP4ProviderCtrl->u4FileSize * (kal_uint64)(i)) / (kal_uint64)(MP4_PROVIDER_SEEK_HINT_SIZE + 1);
            prMP4ProviderCtrl->pt_fsal_seek_hint[i-1].Index = (kal_uint32)temp;
        }
        }

        drm_ret = FSAL_SetSeekHint(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO],
                                    MP4_PROVIDER_SEEK_HINT_SIZE, prMP4ProviderCtrl->pt_fsal_seek_hint);

        if (drm_ret < 0)
        {
            //MP4_PROVIDER_TRACE_RET_ERR(drm_ret);
            return PROVIDER_ERROR;
        }
    }

    /* (3) enable Parser for video */
    {
    UDTAInfo* prUdataInfo;

    prUdataInfo = (UDTAInfo*)prSrcAPI->SPFN_MALLOC_CLA(prMP4ProviderCtrl->prSourceHandle, sizeof(UDTAInfo), KAL_FALSE);
    MP4_PVDR_ASSERT(prUdataInfo != NULL);
    prSrcAPI->SPFN_MEM_SET(prUdataInfo, 0, sizeof(UDTAInfo));

    eParserRet = MP4_Parse_UDTAExt(prMP4ProviderCtrl->pt_parser, prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO],
                                     (void*)prUdataInfo, sizeof(UDTAInfo));
    if (eParserRet != MP4_PARSER_OK && eParserRet != MP4_PARSER_WARNING_TRAILING_GARBAGE)
    {
        MP4_PROVIDER_TRACE_PARSE_ERROR(eParserRet);
        eParserRet = MP4_Parse(prMP4ProviderCtrl->pt_parser, prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO]);
        if (eParserRet != MP4_PARSER_OK && eParserRet != MP4_PARSER_WARNING_TRAILING_GARBAGE)
        {
            MP4_PROVIDER_TRACE_PARSE_ERROR(eParserRet);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            return PROVIDER_ERROR;
        }
    }
    else
    {
#if 0
#ifndef MP4_PROVIDER_REDUCE_META
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
#endif
#endif
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    }

    /* check if there is any video track */
    eParserRet = MP4_GetTrackNoByType(prMP4ProviderCtrl->pt_parser, MP4_TRACK_VIDEO, &u1HasVidTrack);
    if (!(prMP4ProviderCtrl->eTrack & SOURCE_PROVIDER_TRACK_VIDEO))
    {
        u1HasVidTrack = MP4_RESERVED_TRACK_NO;
    }
    else if (u1HasVidTrack != MP4_RESERVED_TRACK_NO)
    {
        eVideoType = MP4_GetVideoType(prMP4ProviderCtrl->pt_parser);

#ifndef __VE_H264_DEC_SUPPORT__
        if (eVideoType == MP4_VIDEO_H264)
        {
            u1HasVidTrack = MP4_RESERVED_TRACK_NO;
        }
#endif

#ifndef MJPG_DECODE
        if (eVideoType == MP4_VIDEO_MJPG)
        {
            u1HasVidTrack = MP4_RESERVED_TRACK_NO;
        }
#endif

        if (eVideoType == MP4_VIDEO_NONE)
        {
            u1HasVidTrack = MP4_RESERVED_TRACK_NO;
        }
    }
    prMP4ProviderCtrl->au1TrackNo[SOURCE_PROVIDER_PORT_VIDEO] = u1HasVidTrack;

    /* check if there is any audio track */
    eParserRet = MP4_GetTrackNoByType(prMP4ProviderCtrl->pt_parser, MP4_TRACK_AUDIO, &u1HasAudTrack);
    if (!(prMP4ProviderCtrl->eTrack & SOURCE_PROVIDER_TRACK_AUDIO))
    {
        u1HasAudTrack = MP4_RESERVED_TRACK_NO;
    }
    else if (u1HasAudTrack != MP4_RESERVED_TRACK_NO)
    {
        eAudioType = MP4_GetAudioType(prMP4ProviderCtrl->pt_parser);

#ifndef AAC_DECODE
        if (eAudioType == MP4_AUDIO_AAC)
        {
            u1HasAudTrack = MP4_RESERVED_TRACK_NO;
        }
#endif

#ifndef AMR_CODEC
        if (eAudioType == MP4_AUDIO_AMR)
        {
            u1HasAudTrack = MP4_RESERVED_TRACK_NO;
        }
#endif

#ifndef AMRWB_DECODE
        if (eAudioType == MP4_AUDIO_AMR_WB)
        {
            u1HasAudTrack = MP4_RESERVED_TRACK_NO;
        }
#endif

#ifndef BSAC_DECODE
        if (eAudioType == MP4_AUDIO_BSAC)
        {
            u1HasAudTrack = MP4_RESERVED_TRACK_NO;
        }
#endif

#ifndef DAF_DECODE
        if (eAudioType == MP4_AUDIO_MP3)
        {
            u1HasAudTrack = MP4_RESERVED_TRACK_NO;
        }
#endif

        if (eAudioType == MP4_AUDIO_NONE)
        {
            u1HasAudTrack = MP4_RESERVED_TRACK_NO;
        }
    }
    prMP4ProviderCtrl->au1TrackNo[SOURCE_PROVIDER_PORT_AUDIO] = u1HasAudTrack;

    if (u1HasVidTrack == MP4_RESERVED_TRACK_NO && u1HasAudTrack == MP4_RESERVED_TRACK_NO)
    {
            return PROVIDER_ERROR;
    }

    eFsalRet = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_mdat[SOURCE_PROVIDER_PORT_VIDEO], prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO]);
    if (eFsalRet != FSAL_OK)
    {
        MP4_PROVIDER_TRACE_FSAL_ERROR(eFsalRet);
        return PROVIDER_ERROR;
    }

    eFsalRet = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_stco[SOURCE_PROVIDER_PORT_VIDEO], prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO]);
    if (eFsalRet != FSAL_OK)
    {
        MP4_PROVIDER_TRACE_FSAL_ERROR(eFsalRet);
        return PROVIDER_ERROR;
    }

    eFsalRet = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_stss[SOURCE_PROVIDER_PORT_VIDEO], prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO]);
    if (eFsalRet != FSAL_OK)
    {
        MP4_PROVIDER_TRACE_FSAL_ERROR(eFsalRet);
        return PROVIDER_ERROR;
    }

    eFsalRet = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_stsz[SOURCE_PROVIDER_PORT_VIDEO], prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO]);
    if (eFsalRet != FSAL_OK)
    {
        MP4_PROVIDER_TRACE_FSAL_ERROR(eFsalRet);
        return PROVIDER_ERROR;
    }

    if (prMP4ProviderCtrl->eSrcType != MED_MODE_BUFFER)
    {
        /*FSAL_SetBuffer(self->pt_fsal_mdat[SOURCE_PROVIDER_PORT_VIDEO],
                       MP4_MP_MDAT_V_BUF_SIZE,
                       (kal_uint8*)self->p_fsal_buf_mdat[SOURCE_PROVIDER_PORT_VIDEO]);*/
        FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal_stco[SOURCE_PROVIDER_PORT_VIDEO],
                       MP4_PROVIDER_STCO_BUF_SIZE*4,
                       (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf_stco[SOURCE_PROVIDER_PORT_VIDEO]);
        FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal_stsz[SOURCE_PROVIDER_PORT_VIDEO],
                       MP4_PROVIDER_STSZ_BUF_SIZE*4,
                       (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf_stsz[SOURCE_PROVIDER_PORT_VIDEO]);
        FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal_stss[SOURCE_PROVIDER_PORT_VIDEO],
                       MP4_PROVIDER_STSS_BUF_SIZE*4,
                       (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf_stss[SOURCE_PROVIDER_PORT_VIDEO]);
    }

    MP4_SetFSAL_STCO(prMP4ProviderCtrl->pt_parser, MP4_TRACK_VIDEO, prMP4ProviderCtrl->pt_fsal_stco[SOURCE_PROVIDER_PORT_VIDEO]);
    MP4_SetFSAL_STSZ(prMP4ProviderCtrl->pt_parser, MP4_TRACK_VIDEO, prMP4ProviderCtrl->pt_fsal_stsz[SOURCE_PROVIDER_PORT_VIDEO]);
    MP4_SetFSAL_STSS(prMP4ProviderCtrl->pt_parser, MP4_TRACK_VIDEO, prMP4ProviderCtrl->pt_fsal_stss[SOURCE_PROVIDER_PORT_VIDEO]);
    MP4_STBL_CacheTablePreprocess(prMP4ProviderCtrl->pt_parser[SOURCE_PROVIDER_PORT_VIDEO], prMP4ProviderCtrl->p_stbl_buf, MP4_PROVIDER_STBL_BUF_SIZE);

    eParserRet =  MP4_GetMovieTimeScaleDuration(prMP4ProviderCtrl->pt_parser,
                                                  &prMP4ProviderCtrl->u4MovieTimeScale,
                                                  &prMP4ProviderCtrl->u4MovieDuration);
    if (eParserRet != MP4_PARSER_OK)
    {
        MP4_PROVIDER_TRACE_PARSE_ERROR(eParserRet);
        return PROVIDER_ERROR;
    }
    else if (prMP4ProviderCtrl->u4MovieTimeScale != 0)
    {
        prMP4ProviderCtrl->u4MovieDuration = MP4_PROVIDER_TIME_UNITS_TO_MS(prMP4ProviderCtrl->u4MovieDuration,
                                                                        prMP4ProviderCtrl->u4MovieTimeScale);
    }

    /* (4) notify client if there is any video track */
    if (u1HasVidTrack != MP4_RESERVED_TRACK_NO)
    {
        do
        {
        MP4_PVDR_ASSERT(u1HasVidTrack < MP4_NUM_TRACKS);
        prMP4ProviderCtrl->eTrackType[u1HasVidTrack] = SOURCE_PROVIDER_PORT_VIDEO;

        /* allocate media_stream_t */
        if (prMP4ProviderCtrl->prVidStreamInfo == NULL)
        {
           prMP4ProviderCtrl->prVidStreamInfo = (SPIF_VIDEO_STREAM_INFO_T*)prSrcAPI->SPFN_MALLOC_CLA(
                                                            prMP4ProviderCtrl->prSourceHandle, sizeof(SPIF_VIDEO_STREAM_INFO_T), KAL_FALSE);
           if (prMP4ProviderCtrl->prVidStreamInfo == NULL)
           {
               u4VideoRet = 1;
               break;
           }
           prSrcAPI->SPFN_MEM_SET(prMP4ProviderCtrl->prVidStreamInfo, 0, sizeof(SPIF_VIDEO_STREAM_INFO_T));
        }
        prVidStream = prMP4ProviderCtrl->prVidStreamInfo;

        prVidStream->u4StreamIndex = prMP4ProviderCtrl->au1TrackNo[SOURCE_PROVIDER_PORT_VIDEO];

        eParserRet =  MP4_GetMediaTimeScale(prMP4ProviderCtrl->pt_parser,
                                              &(prMP4ProviderCtrl->au4TimeScale[SOURCE_PROVIDER_PORT_VIDEO]),
                                              MP4_TRACK_VIDEO);
        if (eParserRet != MP4_PARSER_OK || prMP4ProviderCtrl->au4TimeScale[SOURCE_PROVIDER_PORT_VIDEO] == 0)
        {
            u4VideoRet = 2;
            break;
        }

        eParserRet = MP4_GetMediaDuration(prMP4ProviderCtrl->pt_parser, &u4Duration, MP4_TRACK_VIDEO);
        if (eParserRet != MP4_PARSER_OK)
        {
            u4VideoRet = 3;
            break;

        }
        else if (u4Duration == 0)
        {
            u4VideoRet = 4;
            break;
        }
        prVidStream->u8Duration = MP4_PROVIDER_TIME_UNITS_TO_MS(u4Duration, prMP4ProviderCtrl->au4TimeScale[SOURCE_PROVIDER_PORT_VIDEO]);

        eParserRet = MP4_GetVideoResolution(prMP4ProviderCtrl->pt_parser,
                                              &(prVidStream->u4Width), &(prVidStream->u4Height));
        if (eParserRet != MP4_PARSER_OK
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            )
        {
            u4VideoRet = 5;
            break;
        }
        prVidStream->u4Fps = 0;
        eParserRet = MP4_GetAverageBitRate(prMP4ProviderCtrl->pt_parser,
                                             &(prVidStream->u4AvgBitrate), MP4_TRACK_VIDEO);
        if (eParserRet != MP4_PARSER_OK)
        {
            u4VideoRet = 6;
            break;
        }
        eParserRet = MP4_GetSampleCount(prMP4ProviderCtrl->pt_parser,
                                          MP4_TRACK_VIDEO,
                                          &prMP4ProviderCtrl->au4SampleCount[SOURCE_PROVIDER_PORT_VIDEO]);
        if (eParserRet != MP4_PARSER_OK)
        {
            u4VideoRet = 7;
            break;
        }
        /* to calculate the average frame rate */
        if (u4Duration > 0)
        {
            kal_uint64 u8Fps = 0;

            u8Fps = (kal_uint64)prMP4ProviderCtrl->au4SampleCount[SOURCE_PROVIDER_PORT_VIDEO] *
                (kal_uint64)prMP4ProviderCtrl->au4TimeScale[SOURCE_PROVIDER_PORT_VIDEO] * 100 / (kal_uint64)u4Duration ;
            prVidStream->u4Fps = (kal_uint32)u8Fps;

            if (u8Fps > MP4_PROVIDER_VID_FPS_UPPER_BOUND)
            {
                u4VideoRet = 8;
                break;
            }
        }

        switch (eVideoType)
        {
        case MP4_VIDEO_MPEG4:
            prVidStream->eCodecType = MEDIA_CODEC_VID_MPEG4;
            eRet = MP4ProviderGetParameterSetData(prMP4ProviderCtrl,
                                                 prMP4ProviderCtrl->pt_parser,
                                                 prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO],
                                                 MP4_VIDEO_MPEG4);
            if (eRet != MED_S_OK)
            {
                u4VideoRet = 9;
                break;
            }
            break;

        case MP4_VIDEO_H263:
            prVidStream->eCodecType = MEDIA_CODEC_VID_H263;
            break;

        case MP4_VIDEO_H264:
            prVidStream->eCodecType = MEDIA_CODEC_VID_H264;
            eRet = MP4ProviderGetParameterSetData(prMP4ProviderCtrl,
                                                 prMP4ProviderCtrl->pt_parser,
                                                 prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO],
                                                 MP4_VIDEO_H264);
            if (eRet != MED_S_OK)
            {
                u4VideoRet = 10;
                break;

            }
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            break;

        case MP4_VIDEO_MJPG:
            prVidStream->eCodecType = MEDIA_CODEC_VID_MJPG;
            break;

        default:
            u4VideoRet = 12;
            break;

        }

        }while (0);

        if(u4VideoRet != 0)
        {
            if (prMP4ProviderCtrl->prVidStreamInfo)
            {
                prSrcAPI->SPFN_FREE_CLA(prMP4ProviderCtrl->prSourceHandle, prMP4ProviderCtrl->prVidStreamInfo);
            }
            prMP4ProviderCtrl->prVidStreamInfo = NULL;
            prMP4ProviderCtrl->au1TrackNo[SOURCE_PROVIDER_PORT_VIDEO] = MP4_RESERVED_TRACK_NO;
            MP4_PROVIDER_TRACE_RET_ERR(u4VideoRet);
        }
        else
        {
            kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_HAS_VIDEO,
                      prVidStream->eCodecType,
                      prMP4ProviderCtrl->au1TrackNo[SOURCE_PROVIDER_PORT_VIDEO],
                      prMP4ProviderCtrl->au4SampleCount[SOURCE_PROVIDER_PORT_VIDEO],
                      (kal_uint32)prVidStream->u8Duration);
        }
    }

    if (u1HasAudTrack != MP4_RESERVED_TRACK_NO)
    {
        do
        {
        /* (5) open media for audio */
        if (prMP4ProviderCtrl->eSrcType != MED_MODE_BUFFER)
        {
            eFsalRet = FSAL_Open(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO],
                                                (void*)prMP4ProviderCtrl->u_src.acFileName, FSAL_READ_SHARED);
        }
        else
        {
            FSAL_Direct_SetRamFileSize(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO], prMP4ProviderCtrl->u4FileSize);
            eFsalRet = FSAL_Open(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO],
                                                (void*)prMP4ProviderCtrl->u_src.u4FileBufAddr, FSAL_ROMFILE);
        }

        if (eFsalRet != FSAL_OK)
        {
            u4AudioRet = 1;
            break;
        }

        if (prMP4ProviderCtrl->eSrcType != MED_MODE_BUFFER)
        {
            drm_ret = FSAL_SetSeekHint(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO],
                                        MP4_PROVIDER_SEEK_HINT_SIZE,
                                        prMP4ProviderCtrl->pt_fsal_seek_hint);
            if (drm_ret < 0)
            {
                u4AudioRet = 2;
                break;
            }

            FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO],
                           (kal_uint32)MP4_PROVIDER_FSAL_BUF_SIZE*4,
                           (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf[SOURCE_PROVIDER_PORT_AUDIO]);
        }
        /* (6) enable Parser for audio */
        MP4_PVDR_ASSERT(u1HasAudTrack < MP4_NUM_TRACKS);
        prMP4ProviderCtrl->eTrackType[u1HasAudTrack] = SOURCE_PROVIDER_PORT_AUDIO;

        eFsalRet = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_mdat[SOURCE_PROVIDER_PORT_AUDIO], prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO]);
        if (eFsalRet != FSAL_OK)
        {
            u4AudioRet = 3;
            break;
        }

        eFsalRet = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_stco[SOURCE_PROVIDER_PORT_AUDIO], prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO]);
        if (eFsalRet != FSAL_OK)
        {
            u4AudioRet = 4;
            break;
        }

        eFsalRet = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_stsz[SOURCE_PROVIDER_PORT_AUDIO], prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO]);
        if (eFsalRet != FSAL_OK)
        {
            u4AudioRet = 5;
            break;
        }

        if (prMP4ProviderCtrl->eSrcType != MED_MODE_BUFFER)
        {
            FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal_stco[SOURCE_PROVIDER_PORT_AUDIO],
                           MP4_PROVIDER_STCO_BUF_SIZE*4,
                           (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf_stco[SOURCE_PROVIDER_PORT_AUDIO]);
            FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal_stsz[SOURCE_PROVIDER_PORT_AUDIO],
                           MP4_PROVIDER_STSZ_BUF_SIZE*4,
                           (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf_stsz[SOURCE_PROVIDER_PORT_AUDIO]);
        }

        MP4_SetFSAL_STCO(prMP4ProviderCtrl->pt_parser, MP4_TRACK_AUDIO,
                                            prMP4ProviderCtrl->pt_fsal_stco[SOURCE_PROVIDER_PORT_AUDIO]);
        MP4_SetFSAL_STSZ(prMP4ProviderCtrl->pt_parser, MP4_TRACK_AUDIO,
                                            prMP4ProviderCtrl->pt_fsal_stsz[SOURCE_PROVIDER_PORT_AUDIO]);
        MP4_UpdateSampleCount(prMP4ProviderCtrl->pt_parser, MP4_TRACK_AUDIO);

        /* (7) notify client if there is any audio track */
        /* allocate media_stream_t */
        if (prMP4ProviderCtrl->prAudStrmInfo == NULL)
        {
           prMP4ProviderCtrl->prAudStrmInfo = (SPIF_AUDIO_STREAM_INFO_T*)prSrcAPI->SPFN_MALLOC_CLA(
                                                                                prMP4ProviderCtrl->prSourceHandle, sizeof(SPIF_AUDIO_STREAM_INFO_T), KAL_FALSE);
           if (prMP4ProviderCtrl->prAudStrmInfo == NULL)
           {
               u4AudioRet = 6;
               break;
           }
           prSrcAPI->SPFN_MEM_SET(prMP4ProviderCtrl->prAudStrmInfo, 0, sizeof(SPIF_AUDIO_STREAM_INFO_T));
        }
        prAudStream = prMP4ProviderCtrl->prAudStrmInfo;

        prAudStream->u4StreamIndex = prMP4ProviderCtrl->au1TrackNo[SOURCE_PROVIDER_PORT_AUDIO];

        eParserRet = MP4_GetMediaTimeScale(prMP4ProviderCtrl->pt_parser,
                                             &(prMP4ProviderCtrl->au4TimeScale[SOURCE_PROVIDER_PORT_AUDIO]),
                                             MP4_TRACK_AUDIO);
        if (eParserRet != MP4_PARSER_OK || prMP4ProviderCtrl->au4TimeScale[SOURCE_PROVIDER_PORT_AUDIO] == 0)
        {
            u4AudioRet = 7;
            break;
        }

        eParserRet = MP4_GetMediaDuration(prMP4ProviderCtrl->pt_parser, &u4Duration, MP4_TRACK_AUDIO);
        if (eParserRet != MP4_PARSER_OK)
        {
            u4AudioRet = 8;
            break;

        }
        else if (u4Duration == 0)
        {
            u4AudioRet = 9;
            break;
        }
        prAudStream->u8Duration = MP4_PROVIDER_TIME_UNITS_TO_MS(u4Duration, prMP4ProviderCtrl->au4TimeScale[SOURCE_PROVIDER_PORT_AUDIO]);

        prAudStream->u2Channels = MP4_Audio_GetChannelCount(prMP4ProviderCtrl->pt_parser);
        prAudStream->u2BitsPerSample = MP4_Audio_GetSampleSize(prMP4ProviderCtrl->pt_parser); /* default value of 16 */
        prAudStream->u4SampleRate = MP4_Audio_GetSamplingFreq(prMP4ProviderCtrl->pt_parser);
        eParserRet = MP4_GetSampleCount(prMP4ProviderCtrl->pt_parser,
                                          MP4_TRACK_AUDIO,
                                          &prMP4ProviderCtrl->au4SampleCount[SOURCE_PROVIDER_PORT_AUDIO]);
        if (eParserRet != MP4_PARSER_OK)
        {
            u4AudioRet = 10;
            break;
        }

        prAudStream->u4FrameDuration = 0;
        prAudStream->fgAddHeader = KAL_FALSE;

        switch (eAudioType)
        {
        case MP4_AUDIO_AAC:
            prAudStream->eCodecType = MEDIA_CODEC_AUD_AAC;
            prAudStream->fgAddHeader = KAL_TRUE;
            break;

        case MP4_AUDIO_AMR:
            prAudStream->eCodecType = MEDIA_CODEC_AUD_AMR;
            break;

        case MP4_AUDIO_AMR_WB:
            prAudStream->eCodecType = MEDIA_CODEC_AUD_AMR_WB;
            break;

        case MP4_AUDIO_BSAC:
            prAudStream->eCodecType = MEDIA_CODEC_AUD_BSAC;
            break;

        case MP4_AUDIO_MP3:
            prAudStream->eCodecType = MEDIA_CODEC_AUD_MPEGLAYER3;
            break;
        default:
            u4AudioRet = 11;
            break;

        }

        }while (0);

        if(u4AudioRet != 0)
        {
            if (prMP4ProviderCtrl->prAudStrmInfo)
            {
                prSrcAPI->SPFN_FREE_CLA(prMP4ProviderCtrl->prSourceHandle, prMP4ProviderCtrl->prAudStrmInfo);
            }
            prMP4ProviderCtrl->prAudStrmInfo = NULL;
            prMP4ProviderCtrl->au1TrackNo[SOURCE_PROVIDER_PORT_AUDIO] = MP4_RESERVED_TRACK_NO;
            MP4_PROVIDER_TRACE_RET_ERR(u4AudioRet);
        }
        else
        {
            kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_HAS_AUDIO,
                      prAudStream->eCodecType,
                      prMP4ProviderCtrl->au1TrackNo[SOURCE_PROVIDER_PORT_AUDIO],
                      prMP4ProviderCtrl->au4SampleCount[SOURCE_PROVIDER_PORT_AUDIO],
                      (kal_uint32)prAudStream->u8Duration);
        }
    }


    if (!MP4_PROVIDER_HAS_TRACK(SOURCE_PROVIDER_PORT_AUDIO) && !MP4_PROVIDER_HAS_TRACK(SOURCE_PROVIDER_PORT_VIDEO))
    {
        //MP4_PROVIDER_TRACE_RET_ERR(MED_E_CORRUPTED_DATA);
        return PROVIDER_ERROR;
    }
    /* default is to select */
    if (MP4_PROVIDER_HAS_TRACK(SOURCE_PROVIDER_PORT_AUDIO))
    {
        prMP4ProviderCtrl->fgSelectedTrack[SOURCE_PROVIDER_PORT_AUDIO] = KAL_TRUE;
    }
    if (MP4_PROVIDER_HAS_TRACK(SOURCE_PROVIDER_PORT_VIDEO))
    {
        prMP4ProviderCtrl->fgSelectedTrack[SOURCE_PROVIDER_PORT_VIDEO] = KAL_TRUE;
    }

#ifdef __VE_PGDL_SUPPORT__
    ret = MP4ProviderOpenPDLFile(prMP4ProviderCtrl);
    if (ret != PROVIDER_ERROR_NONE)
    {
        return ret;
    }
#endif

    /* init sample memory pool after _mp4_mp_open_core() */
    //_mp4_mp_sample_buf_init(prMP4ProviderCtrl, SOURCE_PROVIDER_PORT_VIDEO);

    return PROVIDER_ERROR_NONE;
}
#endif

static PROVIDER_ERROR_T MP4ProviderParseAV(void *prHandle, kal_uint32 *pu4Time,
                                                   SP_PORT_TYPE_T ePort)
{
    media_error_t eRet;
    MP4_PROVIDER_CTRL_T *prMP4ProviderCtrl = (MP4_PROVIDER_CTRL_T *)prHandle;
    MP4_PROVIDER_CHECK_POINTER(prHandle);

    *pu4Time = MP4_PROVIDER_MIN_ACCU_TIME;

    eRet = MP4ProviderBatchRead(prMP4ProviderCtrl, ePort);
    if (eRet != MED_S_OK)
    {
        if (eRet == MED_E_CORRUPTED_DATA ||
            eRet == MED_E_PARSER_ERROR ||
            eRet == MED_E_FSAL_ERROR ||
            eRet == MED_E_MEM_INSUFFICIENT)
        {
            MP4ProviderBatchReset(prMP4ProviderCtrl, ePort);
            prMP4ProviderCtrl->bad_sample_no[ePort] = prMP4ProviderCtrl->t_batch[ePort].curr_sample_no;
            if(prMP4ProviderCtrl->au4CurrSampleNo[ePort] == prMP4ProviderCtrl->au4SampleNoStart[ePort])
            {
                // No data is sent.
                // If any data are sent, EOS is notified with PROVIDER_ERROR_DELAY_REPORT_WITH_EOF returned.
                return PROVIDER_ERROR;
            }
        }
        else if(eRet == MED_E_OUT_OF_MEMORY)
        {
            return PROVIDER_ERROR_WAIT_RESOURCE;
        }        	

#ifdef __VE_PGDL_SUPPORT__
        if (eRet == MED_E_PDL_SHORT_OF_BUF)
        {
            /* NOT enough buffer for PDL to demux, waiting for more... */
            return PROVIDER_ERROR_WAIT_DATA;
        }
#endif

    }

    eRet = MP4ProviderDemuxSampleAV(prMP4ProviderCtrl, ePort, pu4Time);

    if (eRet != MED_S_OK)
    {
        if (eRet == MED_E_CORRUPTED_DATA ||
            eRet == MED_E_PARSER_ERROR ||
            eRet == MED_E_FSAL_ERROR)
        {
            prMP4ProviderCtrl->bad_sample_no[ePort] = prMP4ProviderCtrl->au4CurrSampleNo[ePort];
        }
        else if(eRet == MED_E_OUT_OF_MEMORY)
        {
            return PROVIDER_ERROR_WAIT_RESOURCE;
        }
        else if (eRet == MED_S_PLAY_FINISH)
        {
            // EOS
            return PROVIDER_ERROR_EOF;
        }
        else if (eRet == MED_E_ABORTED)
        {
            // EOS due to data corrupted
            return PROVIDER_ERROR_DELAY_REPORT_WITH_EOF;
        }
    }

    return PROVIDER_ERROR_NONE;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

static MP4_Parser_Status MP4_GetMetaInfo(MP4_PROVIDER_CTRL_T *prMP4ProviderCtrl,kal_uint32 u4MetaSize, kal_wchar *MetaBuff, kal_uint32 metaPos, kal_uint32 u4BuffLen, kal_uint8 *pu1Temp)
{   
    kal_uint32 u4ReadSize=0,u4tempRead;
	kal_uint8 *pbData = (kal_uint8 *)MetaBuff;
	MP4_Parser_Status ret = MP4_PARSER_OK;

	if(u4MetaSize>0 && u4BuffLen>1)
	{
	    u4ReadSize = (u4MetaSize <= (u4BuffLen-1))?u4MetaSize: (u4BuffLen-1);

        if(prMP4ProviderCtrl->pt_parser->pUDTAExtInfo->bHasILSTData == KAL_TRUE)
		{

		    do{
			    u4tempRead = (u4ReadSize <= (MP4_META_ARRAY_EXT_SIZE-2))?u4ReadSize: (MP4_META_ARRAY_EXT_SIZE-2);
			
		        ret = mp4_read_metaarray(prMP4ProviderCtrl->pt_parser, pu1Temp,metaPos, &u4tempRead);
			    ProviderUtilityUtf8toUcs2(pbData, 2*u4tempRead+2, pu1Temp, u4tempRead);
			
		        metaPos+=u4tempRead;
			    pbData+=2*u4tempRead;			
			    u4ReadSize-=u4tempRead;

		    }while(u4ReadSize>0);
		}
		else
		{
			u4tempRead = (u4ReadSize <= (MP4_META_ARRAY_EXT_SIZE-2))?u4ReadSize: (MP4_META_ARRAY_EXT_SIZE-2);
			ret = mp4_read_metaarray(prMP4ProviderCtrl->pt_parser, pu1Temp,metaPos, &u4tempRead);

			if((pu1Temp[0] == 0xFF) && (pu1Temp[1] == 0xFE))
			{
				prMP4ProviderCtrl->prSourceAPI->SPFN_MEM_COPY(MetaBuff, pu1Temp+2, MP4_PROVIDER_MAX_DESCRIPTION*sizeof(kal_wchar));
			}
            else
            {
                ProviderUtilityUtf8toUcs2(pbData, 2*u4tempRead+2, pu1Temp, u4tempRead);
            }

		}

	}

	return ret;

}


/*****************************************************************************
 * FUNCTION
 *  MP4ProviderOpen
 * DESCRIPTION
 *  This function is used to open mp4 provider.
 * PARAMETERS
 *  prHandle             [IN]     the handle of the mp4 provider.
 *  prInfo             [IN]     the open mode of the container.
 * RETURNS
 *  PROVIDER_ERROR_T
 *****************************************************************************/
static PROVIDER_ERROR_T MP4ProviderOpen(void *prHandle, SPIF_PROVIDER_OPEN_INFO_T *prInfo)
{
    MP4_PROVIDER_CTRL_T *prMP4ProviderCtrl = (MP4_PROVIDER_CTRL_T *)prHandle;
    PROVIDER_ERROR_T eRet;

    MP4_PROVIDER_CHECK_POINTER(prHandle);
    MP4_PROVIDER_CHECK_POINTER(prInfo);

    video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MP4PVDR_OPEN, prMP4ProviderCtrl->eSrcType);

#ifdef __VE_PGDL_SUPPORT__
    if (prMP4ProviderCtrl->fgWaitMeta)
    {
        //rebuffering meta data
        if (KAL_TRUE == _MP4ProviderIsPDGL(prMP4ProviderCtrl))
        {
            eRet = MP4ProviderOpenPDLMeta(prMP4ProviderCtrl);
            if (eRet != PROVIDER_ERROR_NONE)
            {
                return eRet;
            }
            eRet = MP4ProviderOpenCore(prMP4ProviderCtrl);
            if (eRet != PROVIDER_ERROR_NONE)
            {
                MP4ProviderSelfDeInit(prMP4ProviderCtrl);
                return eRet;
            }
        }
        else
        {
            MP4_PVDR_ASSERT(0);
        }
        return PROVIDER_ERROR_NONE;
    }
#endif

    prMP4ProviderCtrl->eSrcType = prInfo->eOpenType;
    prMP4ProviderCtrl->eTrack = prInfo->eOpenTrack;
    if (prMP4ProviderCtrl->eSrcType != MED_MODE_BUFFER)
    {
        prMP4ProviderCtrl->prSourceAPI->SPFN_MEM_COPY(prMP4ProviderCtrl->u_src.acFileName, (void *)prInfo->pu1Data,
                                MPL_MAX_FILE_NAME_LEN * sizeof(kal_wchar));
    }
    else
    {
        prMP4ProviderCtrl->u_src.u4FileBufAddr = (kal_uint32)prInfo->pu1Data;
        prMP4ProviderCtrl->u4FileSize = prInfo->u4DataSize;
    }

    MP4ProviderSelfInit(prMP4ProviderCtrl);

#ifdef __VE_PGDL_SUPPORT__
    if (KAL_TRUE == _MP4ProviderIsPDGL(prMP4ProviderCtrl))
    {
        FSAL_Status eFsalRet;

        prMP4ProviderCtrl->prSourceAPI->SPFN_MEM_COPY(prMP4ProviderCtrl->u_src.acFileName, (void *)prInfo->pu1Data,
                                MPL_MAX_FILE_NAME_LEN * sizeof(kal_wchar));
        eFsalRet = FSAL_Open(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO], (void*)prMP4ProviderCtrl->u_src.acFileName, FSAL_READ_SHARED);

        if (eFsalRet != FSAL_OK)
        {
            MP4_PROVIDER_TRACE_FSAL_ERROR(eFsalRet);
            MP4ProviderSelfDeInit(prMP4ProviderCtrl);
            return PROVIDER_ERROR;
        }

        FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO],
                       (kal_uint32)MP4_PROVIDER_FSAL_BUF_SIZE*4,
                       (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf[SOURCE_PROVIDER_PORT_VIDEO]);

        if (prMP4ProviderCtrl->eTrack & SOURCE_PROVIDER_TRACK_AUDIO)
        {
            eFsalRet = FSAL_Open(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO], (void*)prMP4ProviderCtrl->u_src.acFileName, FSAL_READ_SHARED);

            if (eFsalRet != FSAL_OK)
            {
                MP4_PROVIDER_TRACE_FSAL_ERROR(eFsalRet);
                MP4ProviderSelfDeInit(prMP4ProviderCtrl);
                return PROVIDER_ERROR;
            }

            FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO],
                           (kal_uint32)MP4_PROVIDER_FSAL_BUF_SIZE*4,
                           (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf[SOURCE_PROVIDER_PORT_AUDIO]);
        }

        eRet = MP4ProviderOpenPDLMeta(prMP4ProviderCtrl);
        if (eRet != PROVIDER_ERROR_NONE)
        {
            return eRet;
        }

    }
#endif /* __MED_VID_PDL_MOD__ */

    eRet = MP4ProviderOpenCore(prMP4ProviderCtrl);
    if (eRet != PROVIDER_ERROR_NONE)
    {
        MP4ProviderSelfDeInit(prMP4ProviderCtrl);
        return eRet;
    }

    return PROVIDER_ERROR_NONE;
}

/*****************************************************************************
 * FUNCTION
 *  MP4ProviderClose
 * DESCRIPTION
 *  This function is used to close mp4 provider
 * PARAMETERS
 *  prHandle             [IN]     the handle of the mp4 provider.
 * RETURNS
 *  PROVIDER_ERROR_T
 *****************************************************************************/
static PROVIDER_ERROR_T MP4ProviderClose(void *prHandle)
{
    MP4_PROVIDER_CTRL_T *prMP4ProviderCtrl = (MP4_PROVIDER_CTRL_T *)prHandle;
    MP4_PROVIDER_CHECK_POINTER(prHandle);

    video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MP4PVDR_CLOSE, prMP4ProviderCtrl->eSrcType);

    MP4ProviderSelfDeInit(prMP4ProviderCtrl);

    return PROVIDER_ERROR_NONE;
}

/*****************************************************************************
 * FUNCTION
 *  MP4ProviderInit
 * DESCRIPTION
 *  This function is used to Initialize mp4 provider.
 * PARAMETERS
 *  prHandle             [IN]     the handle of the mp4 provider.
 * RETURNS
 *  PROVIDER_ERROR_T
 *****************************************************************************/
static PROVIDER_ERROR_T MP4ProviderInit(void *prHandle)
{
    MP4_PROVIDER_CTRL_T *prMP4ProviderCtrl = (MP4_PROVIDER_CTRL_T *)prHandle;

    MP4_PROVIDER_CHECK_POINTER(prMP4ProviderCtrl);

    video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MP4PVDR_INIT,
        prMP4ProviderCtrl->t_batch[SOURCE_PROVIDER_PORT_VIDEO].read_idx);
    video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MP4PVDR_INIT,
        prMP4ProviderCtrl->t_batch[SOURCE_PROVIDER_PORT_VIDEO].write_idx);
    kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_INIT);

    return PROVIDER_ERROR_NONE;
}

/*****************************************************************************
 * FUNCTION
 *  MP4ProviderDeInit
 * DESCRIPTION
 *  This function is used to de-initialize mp4 provider.
 * PARAMETERS
 *  prHandle             [IN]     the handle of the mp4 provider.
 * RETURNS
 *  PROVIDER_ERROR_T
 *****************************************************************************/
static PROVIDER_ERROR_T MP4ProviderDeInit(void *prHandle)
{
    MP4_PROVIDER_CTRL_T *prMP4ProviderCtrl = (MP4_PROVIDER_CTRL_T *)prHandle;

    MP4_PROVIDER_CHECK_POINTER(prMP4ProviderCtrl);

    //Do nothing.
    video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MP4PVDR_DEINIT,
        prMP4ProviderCtrl->t_batch[SOURCE_PROVIDER_PORT_VIDEO].read_idx);
    video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MP4PVDR_DEINIT,
        prMP4ProviderCtrl->t_batch[SOURCE_PROVIDER_PORT_VIDEO].write_idx);
    kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_DEINIT);

    return PROVIDER_ERROR_NONE;
}

/*****************************************************************************
 * FUNCTION
 *  MP4ProviderGetParameter
 * DESCRIPTION
 *  This function is used to get parameter from mp4 provider.
 * PARAMETERS
 *  prHandle             [IN]     the pointer of the buffer in the file beginning.
 *  eCmd             [IN]     the command which used to get parameter.
 *  pParam             [IN] the parameter which source want to get from mp4 provider.
 * RETURNS
 *  PROVIDER_ERROR_T
 *****************************************************************************/
static PROVIDER_ERROR_T MP4ProviderGetParameter(void *prHandle, PROVIDER_PARAM_TYPE_T eCmd, void * pParam)
{
    MP4_PROVIDER_CTRL_T *prMP4ProviderCtrl = (MP4_PROVIDER_CTRL_T *)prHandle;
    MP4_Parser_Status eParserRet;
    SP_PORT_TYPE_T eType;
    MP4_Track_Type eTrackType;
    kal_uint64 u8DecodeTime, u8DecodeTimeTrans;
    kal_uint32 u4FrameNum;
    kal_bool fgSync;
#ifdef __VE_JAVA_ENABLED__
    SPIF_FRAME_TIME_T *prFrameTime;
#endif

    MP4_PROVIDER_CHECK_POINTER(prHandle);
    MP4_PROVIDER_CHECK_POINTER(pParam);

    video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MP4PVDR_GET_PARAM, eCmd);
    kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_GET_PARAM, eCmd);

    switch (eCmd)
    {
        case PROVIDER_PARAM_VID_STREAM_INFO:
            {
                SPIF_STREAM_INFO_T *prStreamInfo = (SPIF_STREAM_INFO_T *)pParam;
                SPIF_VIDEO_STREAM_INFO_T *prVidStrmInfo = prMP4ProviderCtrl->prVidStreamInfo;

                prStreamInfo->pvStreamInfo = NULL;
                prStreamInfo->fgSupport = KAL_FALSE;
                prStreamInfo->u4Num = 0;

                if(prMP4ProviderCtrl->u4VidTrackNum != 0)
                {
                    prStreamInfo->u4Num = prMP4ProviderCtrl->u4VidTrackNum;
                    prStreamInfo->fgSupport = KAL_TRUE;
                    prStreamInfo->pvStreamInfo = (void *)prVidStrmInfo;
                }
            }
            break;

        case PROVIDER_PARAM_AUD_STREAM_INFO:
            {
                SPIF_STREAM_INFO_T *prStreamInfo = (SPIF_STREAM_INFO_T *)pParam;
                SPIF_AUDIO_STREAM_INFO_T *prAudStrmInfo = (SPIF_AUDIO_STREAM_INFO_T *)prMP4ProviderCtrl->prAudStrmInfo;

                prStreamInfo->pvStreamInfo = NULL;
                prStreamInfo->fgSupport = KAL_FALSE;
                prStreamInfo->u4Num = 0;

                if(prMP4ProviderCtrl->u4AudTrackNum != 0)
                {
                    prStreamInfo->u4Num = prMP4ProviderCtrl->u4AudTrackNum;
                    prStreamInfo->fgSupport = KAL_TRUE;
                    prStreamInfo->pvStreamInfo = (void *)prAudStrmInfo;
                }
            }
            break;

#ifdef __VE_SUBTITLE_SUPPORT__
        case PROVIDER_PARAM_SUBS_STREAM_INFO:
            {
                SPIF_STREAM_INFO_T *prStreamInfo = (SPIF_STREAM_INFO_T *)pParam;
                prStreamInfo->fgSupport = KAL_FALSE;
            }
            break;            
#endif

        case PROVIDER_PARAM_META_DATA:
            {
                SPIF_META_DATA_T *prMetaData = (SPIF_META_DATA_T *)pParam;

		UDTAInfo *UserDataInfo = prMP4ProviderCtrl->pt_parser->pUDTAExtInfo;
		kal_uint32 u4ReadSize=0;

#ifdef __VE_KMV_SUPPORT__
				if (KAL_TRUE == _MP4ProviderIsKMV(prMP4ProviderCtrl))
				{
					MP4_GetMetaInfo(prMP4ProviderCtrl,UserDataInfo->lyricsLen,prMetaData->pu2Annotation,UserDataInfo->lyricsPos, prMetaData->u4AnnotationLen, UserDataInfo->temp);
					MP4_GetMetaInfo(prMP4ProviderCtrl,UserDataInfo->groupingLen,prMetaData->pu2Type,UserDataInfo->groupingPos, prMetaData->u2TypeLen, UserDataInfo->temp);
				}
				else
#endif
                {
		            MP4_GetMetaInfo(prMP4ProviderCtrl,UserDataInfo->commentLen,prMetaData->pu2Annotation,UserDataInfo->commentPos, prMetaData->u4AnnotationLen, UserDataInfo->temp);
		            MP4_GetMetaInfo(prMP4ProviderCtrl,UserDataInfo->categoryLen,prMetaData->pu2Type,UserDataInfo->categoryPos, prMetaData->u2TypeLen, UserDataInfo->temp);
                }

		MP4_GetMetaInfo(prMP4ProviderCtrl,UserDataInfo->authorLen,prMetaData->pu2Author,UserDataInfo->authorPos, prMetaData->u2AuthorLen, UserDataInfo->temp);
		MP4_GetMetaInfo(prMP4ProviderCtrl,UserDataInfo->albumLen,prMetaData->pu2Album,UserDataInfo->albumPos, prMetaData->u2AlbumLen, UserDataInfo->temp);
		MP4_GetMetaInfo(prMP4ProviderCtrl,UserDataInfo->copyrightLen,prMetaData->pu2Copyright,UserDataInfo->copyrightPos, prMetaData->u2CopyrightLen, UserDataInfo->temp);
		MP4_GetMetaInfo(prMP4ProviderCtrl,UserDataInfo->titleLen,prMetaData->pu2Title,UserDataInfo->titlePos, prMetaData->u2TitleLen, UserDataInfo->temp);
		MP4_GetMetaInfo(prMP4ProviderCtrl,UserDataInfo->artistLen,prMetaData->pu2Artist,UserDataInfo->artistPos, prMetaData->u2ArtistLen, UserDataInfo->temp);
		MP4_GetMetaInfo(prMP4ProviderCtrl,UserDataInfo->dateLen,prMetaData->pu2Date,UserDataInfo->datePos, prMetaData->u2DateLen, UserDataInfo->temp);

		u4ReadSize = (UserDataInfo->thumbnaildataLen <= prMetaData->u4ThumbnailDataAllocatedLen)?UserDataInfo->thumbnaildataLen: 0;
		if(u4ReadSize!=0 & prMetaData->u4ThumbnailDataAllocatedLen!=0){
			mp4_read_metaarray(prMP4ProviderCtrl->pt_parser, prMetaData->pu1ThumbnailData,UserDataInfo->thumbnaildataPos, &u4ReadSize);
		}
		prMetaData->u4ThumbnailDataUsagedLen = u4ReadSize;

		if(prMetaData->u4ThumbnailDataUsagedLen > 0)
		{	
			switch(UserDataInfo->eThumbType)
			{
				case MP4_MIMETYPE_JPEG:
					prMetaData->eThumbnailType = SOURCE_PROVIDER_THUMBNAIL_JPG;
#ifdef __VE_KMV_SUPPORT__
					if (KAL_TRUE == _MP4ProviderIsKMV(prMP4ProviderCtrl))
					{
					    prMetaData->eThumbnailType = SOURCE_PROVIDER_THUMBNAIL_BMP;
					}
#endif
					break;
				case MP4_MIMETYPE_PNG:
					prMetaData->eThumbnailType = SOURCE_PROVIDER_THUMBNAIL_PNG; 				
					break;
				default:
					return PROVIDER_ERROR_NOT_SUPPORT;
			}
		}

            }
            break;
        case PROVIDER_PARAM_META_CAPABILITY:
            {
                SP_CAPABILITY_T *prCap = (SP_CAPABILITY_T *)pParam;
                *prCap = SOURCE_PROVIDER_SEEK;
            }
            break;
        case PROVIDER_PARAM_KEY_FRAME_TIME:
            {
                SPIF_KEY_FRAME_TIME_T *prKeyFrameTime = (SPIF_KEY_FRAME_TIME_T *)pParam;
                kal_uint32 u4TargetSampleNo;
                kal_uint64 u8VideoTimeRemainder;

                eType = prKeyFrameTime->ePort;
                eTrackType = (eType == SOURCE_PROVIDER_PORT_AUDIO) ? MP4_TRACK_AUDIO : MP4_TRACK_VIDEO;

                u8DecodeTime = prKeyFrameTime->u8StartTime;
                u8DecodeTime = (kal_uint64)MP4_PROVIDER_MS_TO_TIME_UNITS(u8DecodeTime, prMP4ProviderCtrl->au4TimeScale[eType]);

                eParserRet = MP4_GetSampleNumber(prMP4ProviderCtrl->pt_parser,
                                                &u4FrameNum,
                                                u8DecodeTime,
                                                eTrackType);
                if (eParserRet != MP4_PARSER_OK)
                {
                    MP4_PROVIDER_TRACE_PARSE_ERROR(eParserRet);
                    if (eParserRet == MP4_PARSER_NO_SUCH_SAMPLE)
                    {
                        prKeyFrameTime->u8KeyFrameTime = prKeyFrameTime->u8StartTime;
                        break;
                    }
                    else
                    {
                        return PROVIDER_ERROR;
                    }
                }

                /* must call MP4_ChkIsSyncSample first, or MP4_ChkIsSyncSample_Next can't work */
                eParserRet = MP4_ChkIsSyncSample(prMP4ProviderCtrl->pt_parser,
                                                    u4FrameNum,
                                                    eTrackType,
                                                    &fgSync,
                                                    &prMP4ProviderCtrl->stss_next_index[eType]);
                if (eParserRet != MP4_PARSER_OK)
                {
                    MP4_PROVIDER_TRACE_PARSE_ERROR(eParserRet);
                    return PROVIDER_ERROR;
                }
                u4TargetSampleNo = u4FrameNum;

                if(!fgSync)
                {
                    if (prKeyFrameTime->eDirect == SOURCE_PROVIDER_SEARCH_BACKWARD)
                    {
                        /* search the key frame just read before "time" */
                        eParserRet = MP4_GetPrevSyncSampleNo(prMP4ProviderCtrl->pt_parser, u4FrameNum, &u4TargetSampleNo, eTrackType);
                        if (eParserRet != MP4_PARSER_OK)
                        {
                            MP4_PROVIDER_TRACE_PARSE_ERROR(eParserRet);
                            return PROVIDER_ERROR;
                        }
                    }
                    else if (prKeyFrameTime->eDirect == SOURCE_PROVIDER_SEARCH_FORWARD)
                    {
                        /* search the key frame newer than "time" */
                        eParserRet = MP4_GetNextSyncSampleNo(prMP4ProviderCtrl->pt_parser, u4FrameNum, &u4TargetSampleNo, eTrackType);
                        if (eParserRet != MP4_PARSER_OK)
                        {
                            MP4_PROVIDER_TRACE_PARSE_ERROR(eParserRet);
                            return PROVIDER_ERROR;
                        }
                    }
                    else
                    {
                        return PROVIDER_ERROR;
                    }
                }

                eParserRet = MP4_GetCompositionTime(prMP4ProviderCtrl->pt_parser,
                                                u4TargetSampleNo,
                                                &u8DecodeTime,
                                                eTrackType);

                if (eParserRet != MP4_PARSER_OK)
                {
                    MP4_PROVIDER_TRACE_PARSE_ERROR(eParserRet);
                    return PROVIDER_ERROR;
                }

                u8DecodeTimeTrans= (kal_uint64)MP4_PROVIDER_TIME_UNITS_TO_MS(u8DecodeTime, prMP4ProviderCtrl->au4TimeScale[eType]);
                u8VideoTimeRemainder = (u8DecodeTime*(kal_uint64)1000)%(kal_uint64)prMP4ProviderCtrl->au4TimeScale[eType];
                if(u8VideoTimeRemainder != 0)
                {
                    u8DecodeTimeTrans++;
                }
                prKeyFrameTime->u8KeyFrameTime = u8DecodeTimeTrans;

                prMP4ProviderCtrl->au4SampleNoSync[eType] = prMP4ProviderCtrl->au4CurrSampleNo[eType];
                kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_GET_KEYTIME, eType,
                    (kal_uint32)prKeyFrameTime->u8StartTime, (kal_uint32)prKeyFrameTime->u8KeyFrameTime);
            }
            break;
        #ifdef __VE_JAVA_ENABLED__
        case PROVIDER_PARAM_TIME_TO_FRAME:
            {
                prFrameTime = (SPIF_FRAME_TIME_T *)pParam;
                eType = prFrameTime->ePort;
                eTrackType = (prFrameTime->ePort == SOURCE_PROVIDER_PORT_AUDIO) ? MP4_TRACK_AUDIO : MP4_TRACK_VIDEO;
                u8DecodeTime = (kal_uint64)MP4_PROVIDER_MS_TO_TIME_UNITS(prFrameTime->u8FrameTime, prMP4ProviderCtrl->au4TimeScale[eType]);
                eParserRet = MP4_GetSampleNumber(prMP4ProviderCtrl->pt_parser,
                                           &u4FrameNum,
                                           u8DecodeTime,
                                           eTrackType);
                if (eParserRet != MP4_PARSER_OK)
                {
                    MP4_PROVIDER_TRACE_PARSE_ERROR(eParserRet);
                    if (eParserRet == MP4_PARSER_NO_SUCH_SAMPLE)
                    {
                        u4FrameNum = prMP4ProviderCtrl->au4SampleCount[eType] - 1;
                    }
                    else
                    {
                        return PROVIDER_ERROR;
                    }
                }
                prFrameTime->u4Frame = u4FrameNum;
            }
            break;
        case PROVIDER_PARAM_FRAME_TO_TIME:
            {
                prFrameTime = (SPIF_FRAME_TIME_T *)pParam;
                eType = prFrameTime->ePort;
                eTrackType = (prFrameTime->ePort == SOURCE_PROVIDER_PORT_AUDIO) ? MP4_TRACK_AUDIO : MP4_TRACK_VIDEO;
                eParserRet = MP4_GetDecodeTime(prMP4ProviderCtrl->pt_parser,
                                         prFrameTime->u4Frame,
                                         &u8DecodeTime,
                                         eTrackType);
                prMP4ProviderCtrl->au4SampleNoSync[eType] = prMP4ProviderCtrl->au4CurrSampleNo[eType];
                if (eParserRet != MP4_PARSER_OK)
                {
                    MP4_PROVIDER_TRACE_PARSE_ERROR(eParserRet);
                    u8DecodeTime = (prFrameTime->ePort == SOURCE_PROVIDER_PORT_AUDIO) ? prMP4ProviderCtrl->prAudStrmInfo->u8Duration :
                                                                                                                                           prMP4ProviderCtrl->prVidStreamInfo->u8Duration;
                    u8DecodeTimeTrans = u8DecodeTime;

                }
                else
                {
                    kal_uint64 u8VideoTimeRemainder;

                    u8DecodeTimeTrans = MP4_PROVIDER_TIME_UNITS_TO_MS(u8DecodeTime, prMP4ProviderCtrl->au4TimeScale[eType]);
                    u8VideoTimeRemainder = (u8DecodeTime*(kal_uint64)1000)%(kal_uint64)prMP4ProviderCtrl->au4TimeScale[eType];
                    if(u8VideoTimeRemainder != 0)
                    {
                        u8DecodeTimeTrans++;
                    }

                    if (prFrameTime->ePort == SOURCE_PROVIDER_PORT_AUDIO &&
                        prFrameTime->u4Frame == (prMP4ProviderCtrl->au4SampleCount[SOURCE_PROVIDER_PORT_AUDIO] - 1) &&
                        (prMP4ProviderCtrl->prAudStrmInfo->u8Duration - u8DecodeTimeTrans) >= 4000) /* ref to MP4_Audio_Seek_To_Video */
                    {
                        return PROVIDER_ERROR;
                    }
                }
                prFrameTime->u8FrameTime = u8DecodeTimeTrans;
            }
            break;
        #endif

        #ifdef __VE_PGDL_SUPPORT__
        case PROVIDER_PARAM_QURERY_FRAME_BUF:
        {
            kal_uint32 u4AvailDuration=0;
            SPIF_BUF_STATUS_T *prBufferStatus = (SPIF_BUF_STATUS_T *)pParam;
            SPIF_BUF_INFO_T *pt_buf_status = prBufferStatus->prBufStatus;

            memset(pt_buf_status, 0, sizeof(SPIF_BUF_INFO_T));

            if (MP4_PROVIDER_HAS_TRACK(SOURCE_PROVIDER_PORT_AUDIO))
            {
                eParserRet = MP4_Audio_GetAvailableDur(prMP4ProviderCtrl->pt_parser_pdl[SOURCE_PROVIDER_PORT_AUDIO], &u4AvailDuration);
                if (eParserRet != MP4_PARSER_OK)
                {
                    MP4_PROVIDER_TRACE_PARSE_ERROR(eParserRet);
                    return PROVIDER_ERROR;
                }
                pt_buf_status->u8AudioAvailDur = (media_time_t)u4AvailDuration;

            }
            if (MP4_PROVIDER_HAS_TRACK(SOURCE_PROVIDER_PORT_VIDEO))
            {
                eParserRet = MP4_Video_GetAvailableDur(prMP4ProviderCtrl->pt_parser_pdl[SOURCE_PROVIDER_PORT_VIDEO], &u4AvailDuration);
                if (eParserRet != MP4_PARSER_OK)
                {
                    MP4_PROVIDER_TRACE_PARSE_ERROR(eParserRet);
                    return PROVIDER_ERROR;
                }
                    pt_buf_status->u8VideoAvailDur = (media_time_t)u4AvailDuration;
            }
            kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_AVAIL_DUR, pt_buf_status->u8AudioAvailDur, pt_buf_status->u8VideoAvailDur);
        }
        break;
        #endif
        case PROVIDER_PARAM_DRM_FSAL:
        {
            SPIF_DRM_INFO_T *prDrmInfo = (SPIF_DRM_INFO_T *)pParam;

            prDrmInfo->file_handle= prMP4ProviderCtrl->file_handle;
        }
        break;

        #ifdef __VE_VIDEO_CLIPPER_SUPPORT__
        case PROVIDER_PARAM_MTK_FILE:
        {
            kal_bool *bValidPrivateFile = (kal_bool *)pParam;

            *bValidPrivateFile = KAL_FALSE;
            if(prMP4ProviderCtrl->pt_parser->bPrivateEncodeFormat == KAL_TRUE)
            {
                *bValidPrivateFile = KAL_TRUE;
            }
        }
        break;

        #ifdef __VE_H264_DEC_SUPPORT__
        case PROVIDER_PARAM_AVC_CONF_RECORD:
        {
            SPIF_AVC_CONF_RECORD_T *pstAVCInfoDst = (SPIF_AVC_CONF_RECORD_T *)pParam;
            STAVCInfo *pstAVCInfoSrc = NULL;

            pstAVCInfoSrc = MP4_Video_GetAVCConfigRecord(prMP4ProviderCtrl->pt_parser);
            pstAVCInfoDst->configurationVersion = pstAVCInfoSrc->configurationVersion;
            pstAVCInfoDst->AVCProfileIndication = pstAVCInfoSrc->AVCProfileIndication;
            pstAVCInfoDst->profile_compatibility = pstAVCInfoSrc->profile_compatibility;
            pstAVCInfoDst->AVCLevelIndication = pstAVCInfoSrc->AVCLevelIndication;
            pstAVCInfoDst->lengthSizeMinusOne = pstAVCInfoSrc->lengthSizeMinusOne;
        }
        break;
        #endif
        #endif

        #ifdef __VE_PARSE_TRANSFORMATION_INFO__
        case PROVIDER_PARAM_TRANSFORMATION_INFO:
        {
            SPIF_TRANSFORMATION_INFO_T *prtransInfo =  (SPIF_TRANSFORMATION_INFO_T *)pParam;
            prtransInfo->u2Rotation = prMP4ProviderCtrl->pt_parser->u2RotateAngle;
            prtransInfo->u1HorizontalMirror = prMP4ProviderCtrl->pt_parser->u1HMirror;
            prtransInfo->u1VertialMirror = prMP4ProviderCtrl->pt_parser->u1VMirror;
        }
        break;
        #endif

        default:
            return PROVIDER_ERROR;
    }

    return PROVIDER_ERROR_NONE;
}

/*****************************************************************************
 * FUNCTION
 *  MP4ProviderSetParameter
 * DESCRIPTION
 *  This function is used to set parameter to mp4 provider
 * PARAMETERS
 *  prHandle             [IN]     the pointer of the buffer in the file beginning.
 *  eCmd             [IN]     the command which used to set parameter.
 *  pParam             [OUT] the parameter which source want to set to mp4 provider.
 * RETURNS
 *  PROVIDER_ERROR_T
 *****************************************************************************/
static PROVIDER_ERROR_T MP4ProviderSetParameter(void *prHandle, PROVIDER_PARAM_TYPE_T eCmd, void * pParam)
{
    MP4_PROVIDER_CTRL_T *prMP4ProviderCtrl = (MP4_PROVIDER_CTRL_T *)prHandle;
    SPIF_STREAM_T *prStream;
    SP_PORT_TYPE_T eType;
    MP4_Parser_Status eParserRet;
    PROVIDER_ERROR_T eRet = PROVIDER_ERROR_NONE;
    media_error_t eMediaRet;
    SP_API_T *prSrcAPI = prMP4ProviderCtrl->prSourceAPI;
    SPIF_PROVIDER_FRAME_INFO_T rFrameInfo;
    PU_VID_PARAM_SET_T *prParameterSet;
    MP4_Video_Type eVideoType = MP4_VIDEO_NONE;
    MP4_Track_Type eTrackType;
    kal_uint8* pu1Sample;
    kal_uint32 u4ActualBufSize;

    MP4_PROVIDER_CHECK_POINTER(prHandle);
    //MP4_PROVIDER_CHECK_POINTER(pParam);

    video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MP4PVDR_SET_PARAM, eCmd);
    kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_SET_PARAM, eCmd);

    switch (eCmd)
    {
        case PROVIDER_PARAM_SEEK_TIME:
        {
            SPIF_SEEK_TIME_T *prSeekTime = (SPIF_SEEK_TIME_T *)pParam;
            kal_bool fgSync;
            kal_uint64 u8DecodeTime;
            kal_uint32 u4FrameNum;
            kal_uint32 u4TargetSampleNo;
            kal_uint32 u8StreamDuration;

            eType = prSeekTime->eType;
            eTrackType = (eType == SOURCE_PROVIDER_PORT_AUDIO) ? MP4_TRACK_AUDIO : MP4_TRACK_VIDEO;
            prMP4ProviderCtrl->afgEos[eType] = KAL_FALSE;
            prMP4ProviderCtrl->bad_sample_no[eType] = MP4_PROVIDER_SAMPLE_NO_MAX;
            prMP4ProviderCtrl->au4SampleNoSync[eType] = MP4_PROVIDER_SAMPLE_NO_MAX;
            prMP4ProviderCtrl->au4StartTime[eType] = (kal_uint32)prSeekTime->u8StartTime;
            prMP4ProviderCtrl->stop_time = (kal_uint32)prSeekTime->u8EndTime;

            u8StreamDuration = prMP4ProviderCtrl->prAudStrmInfo->u8Duration;
            if(eType == SOURCE_PROVIDER_PORT_VIDEO)
            {
                u8StreamDuration = prMP4ProviderCtrl->prVidStreamInfo->u8Duration;
            }

            // To avoid audio frame not enough. Strange noise is appearing
            if((eType == SOURCE_PROVIDER_PORT_AUDIO) && (prSeekTime->u8StartTime >= u8StreamDuration))
            {
                prMP4ProviderCtrl->au4CurrSampleNo[eType] = prMP4ProviderCtrl->au4SampleCount[eType];
                MP4ProviderBatchReset(prMP4ProviderCtrl, eType);
                break;
            }

            u8DecodeTime = (kal_uint64)MP4_PROVIDER_MS_TO_TIME_UNITS(prSeekTime->u8StartTime, prMP4ProviderCtrl->au4TimeScale[eType]);

            eParserRet = MP4_GetSampleNumber(prMP4ProviderCtrl->pt_parser,
                                                &u4FrameNum,
                                                u8DecodeTime,
                                                eTrackType);
            if (eParserRet != MP4_PARSER_OK)
            {
                MP4_PROVIDER_TRACE_PARSE_ERROR(eParserRet);
                if (eParserRet == MP4_PARSER_NO_SUCH_SAMPLE)
                {
                    if(prSeekTime->u8StartTime < u8StreamDuration + MP4_PROVIDER_DURATION_MARGIN)
                    {
                        prMP4ProviderCtrl->au4CurrSampleNo[eType] = prMP4ProviderCtrl->au4SampleCount[eType] - 1;
                        prMP4ProviderCtrl->au4SampleNoSync[eType] = prMP4ProviderCtrl->au4CurrSampleNo[eType];
                        u4FrameNum = prMP4ProviderCtrl->au4CurrSampleNo[eType];
                    }
                    else
                    {
                        prMP4ProviderCtrl->au4CurrSampleNo[eType] = prMP4ProviderCtrl->au4SampleCount[eType];
                        MP4ProviderBatchReset(prMP4ProviderCtrl, eType);
                        break;
                    }
                }
                else
                {
                    return PROVIDER_ERROR;
                }
            }

            /* must call MP4_ChkIsSyncSample first, or MP4_ChkIsSyncSample_Next can't work */
                eParserRet = MP4_ChkIsSyncSample(prMP4ProviderCtrl->pt_parser,
                                                u4FrameNum,
                                                eTrackType,
                                                &fgSync,
                                                &prMP4ProviderCtrl->stss_next_index[eType]);
            if (eParserRet != MP4_PARSER_OK)
            {
                MP4_PROVIDER_TRACE_PARSE_ERROR(eParserRet);
                eRet = PROVIDER_ERROR;
                break;
            }
            u4TargetSampleNo = u4FrameNum;
            if (!fgSync)
            {
                /* search the key frame just read before "time" */
                eParserRet = MP4_GetPrevSyncSampleNo(prMP4ProviderCtrl->pt_parser, u4FrameNum, &u4TargetSampleNo, eTrackType);
                if (eParserRet != MP4_PARSER_OK)
                {
                    MP4_PROVIDER_TRACE_PARSE_ERROR(eParserRet);
                    eRet = PROVIDER_ERROR;
                    break;

                }
                /* must call MP4_ChkIsSyncSample first, or MP4_ChkIsSyncSample_Next can't work */
                eParserRet = MP4_ChkIsSyncSample(prMP4ProviderCtrl->pt_parser,
                                                    u4TargetSampleNo,
                                                    eTrackType,
                                                    &fgSync,
                                                    &prMP4ProviderCtrl->stss_next_index[eType]);
                if (eParserRet != MP4_PARSER_OK)
                {
                    MP4_PROVIDER_TRACE_PARSE_ERROR(eParserRet);
                    eRet = PROVIDER_ERROR;
                    break;
                }
            }

            prMP4ProviderCtrl->au4CurrSampleNo[eType] = u4TargetSampleNo;
            prMP4ProviderCtrl->au4SampleNoSync[eType] = prMP4ProviderCtrl->au4CurrSampleNo[eType];

            eMediaRet = MP4ProviderSeekSample(prMP4ProviderCtrl, prMP4ProviderCtrl->au4CurrSampleNo[eType], eType);
            if (eMediaRet != MED_S_OK)
            {
                MP4_PROVIDER_TRACE_RET_ERR(eMediaRet);
                eRet = PROVIDER_ERROR;
                break;
            }
            kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_SET_SEEKTIME, eType,
                prMP4ProviderCtrl->au4StartTime[eType], prMP4ProviderCtrl->stop_time, prMP4ProviderCtrl->au4CurrSampleNo[eType]);

            prMP4ProviderCtrl->au4SampleNoStart[eType] = prMP4ProviderCtrl->au4CurrSampleNo[eType];
            MP4ProviderBatchReset(prMP4ProviderCtrl, eType);
            prMP4ProviderCtrl->au4LastReleaseSampleNo[eType] = MP4_PROVIDER_SAMPLE_NO_MAX;
        }
        break;

        case PROVIDER_PARAM_SELECT_STREAM:
            prStream = (SPIF_STREAM_T *)pParam;
            if (prStream->u1Track >= MP4_NUM_TRACKS)
            {
                MP4_PVDR_ASSERT(0);
                eRet = PROVIDER_ERROR;
                break;
            }

            kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_SELECT_TRACK, prStream->eType, prStream->u1Track);
            eType = prMP4ProviderCtrl->eTrackType[prStream->u1Track];
            ASSERT(prStream->eType == eType);

            prMP4ProviderCtrl->fgSelectedTrack[eType] = KAL_FALSE;
            eTrackType = MP4_TRACK_AUDIO;
            if(eType == SOURCE_PROVIDER_PORT_VIDEO)
            {
                eTrackType = MP4_TRACK_VIDEO;
            }

            prMP4ProviderCtrl->au1TrackNo[eType] = prStream->u1Track;

            MP4_SetTrackIndex(prMP4ProviderCtrl->pt_parser, prStream->u1Track);

//            MP4_STBL_CacheTablePreprocess(prMP4ProviderCtrl->pt_parser, prMP4ProviderCtrl->p_stbl_buf, MP4_PROVIDER_STBL_BUF_SIZE);

            eParserRet =  MP4_GetMediaTimeScale(prMP4ProviderCtrl->pt_parser,
                                                  &(prMP4ProviderCtrl->au4TimeScale[eType]),
                                                  eTrackType);
            if (eParserRet != MP4_PARSER_OK || prMP4ProviderCtrl->au4TimeScale[eType] == 0)
            {
                MP4_PVDR_ASSERT(0);
                eRet = PROVIDER_ERROR;
                break;
            }
            eParserRet = MP4_GetSampleCount(prMP4ProviderCtrl->pt_parser,
                                              eTrackType,
                                             &prMP4ProviderCtrl->au4SampleCount[eType]);
            if (eParserRet != MP4_PARSER_OK)
            {
                MP4_PVDR_ASSERT(0);
                eRet = PROVIDER_ERROR;
                break;
            }

            prMP4ProviderCtrl->fgSelectedTrack[eType] = KAL_TRUE;
            break;
        case PROVIDER_PARAM_DESELECT_STREAM:
            prStream = (SPIF_STREAM_T *)pParam;
            if (prStream->u1Track >= MP4_NUM_TRACKS)
            {
                MP4_PVDR_ASSERT(0);
                eRet = PROVIDER_ERROR;
            }
            eType = prMP4ProviderCtrl->eTrackType[prStream->u1Track];
            prMP4ProviderCtrl->fgSelectedTrack[eType] = KAL_FALSE;
            break;
        case PROVIDER_PARAM_SEND_HEADER:
        {
            SPIF_SNED_HEADER_T *prSendHeader = (SPIF_SNED_HEADER_T *)pParam;

            if (prSendHeader->fgVideo == KAL_TRUE)
            {
            SPIF_H264_DECODER_PAYLOAD_INFO_T *prPayload = NULL;
            kal_uint32 u4VidError = 0;

            eVideoType = MP4_GetVideoType(prMP4ProviderCtrl->pt_parser);
            if ((eVideoType == MP4_VIDEO_H263) || (eVideoType == MP4_VIDEO_MJPG))
            {
                //H.263, MJPEG no header
                break;
            }

            do
            {
              eVideoType = MP4_GetVideoType(prMP4ProviderCtrl->pt_parser);

              // Free allocated parameter set data during changing video track
              if (prMP4ProviderCtrl->prVideoParamSetData->pu1ParamSetBuff)
              {
                  prSrcAPI->SPFN_FREE_CLA(prMP4ProviderCtrl->prSourceHandle, prMP4ProviderCtrl->prVideoParamSetData->pu1ParamSetBuff);
                  prMP4ProviderCtrl->prVideoParamSetData->pu1ParamSetBuff = NULL;
              }
              if (prMP4ProviderCtrl->prVideoParamSetData->prNALCTRLBuff)
              {
                  prSrcAPI->SPFN_FREE_CLA(prMP4ProviderCtrl->prSourceHandle, prMP4ProviderCtrl->prVideoParamSetData->prNALCTRLBuff);
                  prMP4ProviderCtrl->prVideoParamSetData->prNALCTRLBuff = NULL;
              }

              switch (eVideoType)
              {
                case MP4_VIDEO_MPEG4:
                    eMediaRet = MP4ProviderGetParameterSetData(prMP4ProviderCtrl,
                                                         prMP4ProviderCtrl->pt_parser,
                                                         prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO],
                                                         MP4_VIDEO_MPEG4);
                    if (eMediaRet != MED_S_OK)
                    {
                        u4VidError = 1;
                        eRet = PROVIDER_ERROR;

                    }
                    break;


                case MP4_VIDEO_H264:
                    eMediaRet = MP4ProviderGetParameterSetData(prMP4ProviderCtrl,
                                                         prMP4ProviderCtrl->pt_parser,
                                                         prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO],
                                                         MP4_VIDEO_H264);
                    if (eMediaRet != MED_S_OK)
                    {
                        u4VidError = 2;
                        eRet = PROVIDER_ERROR;
                        break;

                    }
                    break;


                default:
                    break;

                }
            } while(0);

            if(u4VidError > 0)
            {
                break;
            }

            prParameterSet = prMP4ProviderCtrl->prVideoParamSetData;
            if((eVideoType == MP4_VIDEO_H264) && (prParameterSet->u4ParamSetTotalSize == 0))
            {
                // H.264 w/o SPS/PPS in container
                break;
            }

            pu1Sample = (kal_uint8 *)prSrcAPI->SPFN_BITSTREAM_BUF_QUERY_AVAILABLE_SIZE(
                                    prMP4ProviderCtrl->prSourceHandle, SOURCE_PROVIDER_PORT_VIDEO, prParameterSet->u4ParamSetTotalSize, &u4ActualBufSize);
            MP4_PVDR_ASSERT(pu1Sample);
            prSrcAPI->SPFN_MEM_COPY((void *)pu1Sample, (void *)prParameterSet->pu1ParamSetBuff, prParameterSet->u4ParamSetTotalSize);
            prSrcAPI->SPFN_BITSTREAM_BUF_UPDATA_ADD(prMP4ProviderCtrl->prSourceHandle, SOURCE_PROVIDER_PORT_VIDEO, (kal_uint32)pu1Sample + prParameterSet->u4ParamSetTotalSize);

            memset(&rFrameInfo, 0, sizeof(SPIF_PROVIDER_FRAME_INFO_T));
            rFrameInfo.pu1Addr = pu1Sample;
            rFrameInfo.u4FrameSize = prParameterSet->u4ParamSetTotalSize;
            if (eVideoType == MP4_VIDEO_H264)
            {
                kal_uint32 i;

                rFrameInfo.u4PayloadNum = prParameterSet->u4NumOfNALuParamSet;
                if(rFrameInfo.u4PayloadNum == 0)
                {
                    // Parameter set  numOfSPS and numOfPPS are 0 case
                    rFrameInfo.u4PayloadNum = 1;
                }
                rFrameInfo.u4PayloadSize = sizeof(SPIF_H264_DECODER_PAYLOAD_INFO_T) * rFrameInfo.u4PayloadNum;
                prPayload = (SPIF_H264_DECODER_PAYLOAD_INFO_T *)prSrcAPI->SPFN_MALLOC_CLA(prMP4ProviderCtrl->prSourceHandle,
                                                                                     rFrameInfo.u4PayloadSize, KAL_FALSE);
                for(i = 0; i < prParameterSet->u4NumOfNALuParamSet; i++)
                {
                    prPayload[i].u4Address = (kal_uint32)pu1Sample +
                                             (prParameterSet->prNALCTRLBuff[i].u4Address - (kal_uint32)prParameterSet->pu1ParamSetBuff);
                    prPayload[i].u4Length = prParameterSet->prNALCTRLBuff[i].u4Length;
                }
                if(prParameterSet->u4NumOfNALuParamSet == 0)
                {
                    prPayload[0].u4Address = (kal_uint32)pu1Sample;
                    prPayload[0].u4Length = prParameterSet->u4ParamSetTotalSize;
                }
                rFrameInfo.pu1Payload = (kal_uint8 *)prPayload;
            }
            else
            {
                rFrameInfo.u4PayloadSize = 0;
                rFrameInfo.pu1Payload = NULL;
                rFrameInfo.u4PayloadNum = 0;
            }
            rFrameInfo.fgHeader = KAL_TRUE;
            rFrameInfo.u8Timestamp = 0;
            rFrameInfo.fgEof = rFrameInfo.fgKeyFrame = rFrameInfo.fgSilent = KAL_FALSE;

            if (prSrcAPI->SPFN_ADD_ONE_DATA(prMP4ProviderCtrl->prSourceHandle,
                                            SOURCE_PROVIDER_PORT_VIDEO, &rFrameInfo) == PROVIDER_ERROR_WAIT_RESOURCE)
            {
                MP4_PVDR_ASSERT(0);
                return PROVIDER_ERROR_WAIT_RESOURCE;
            }
            if(prPayload != NULL)
            {
                prSrcAPI->SPFN_FREE_CLA(prMP4ProviderCtrl->prSourceHandle, prPayload);
            }
            }
        }
        break;
		case PROVIDER_PARAM_QUICK_CLOSE:
            prMP4ProviderCtrl->pt_parser->fgQuickClose = KAL_TRUE;
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
        default:
            return PROVIDER_ERROR;
    }

    return eRet;
}

/*****************************************************************************
 * FUNCTION
 *  MP4ProviderParseVideo
 * DESCRIPTION
 *  This function is used to read video bitstream and demux one video sample.
 * PARAMETERS
 *  prHandle             [IN]     the handle of the mp4 provider.
 * RETURNS
 *  PROVIDER_ERROR_T
 *****************************************************************************/
static PROVIDER_ERROR_T MP4ProviderParseVideo(void *prHandle, kal_uint32 *pu4Time)
{
    return MP4ProviderParseAV(prHandle, pu4Time, SOURCE_PROVIDER_PORT_VIDEO);
}

/*****************************************************************************
 * FUNCTION
 *  MP4ProviderParseAudio
 * DESCRIPTION
 *  This function is used to read audio bitstream and demux one audio sample
 * PARAMETERS
 *  prHandle             [IN]     the handle of the mp4 provider.
 * RETURNS
 *  PROVIDER_ERROR_T
 *****************************************************************************/
static PROVIDER_ERROR_T MP4ProviderParseAudio(void *prHandle, kal_uint32 *pu4Time)
{
    return MP4ProviderParseAV(prHandle, pu4Time, SOURCE_PROVIDER_PORT_AUDIO);
}


static const PROVIDER_API_T rMP4ProviderAPI =
{
    MP4ProviderOpen,
    MP4ProviderClose,
    MP4ProviderInit,
    MP4ProviderDeInit,
    MP4ProviderGetParameter,
    MP4ProviderSetParameter,
    MP4ProviderParseVideo,
    MP4ProviderParseAudio
#ifdef __VE_SUBTITLE_SUPPORT__
    ,NULL
#endif
};

/*****************************************************************************
 * FUNCTION
 *  MP4ProviderGetHandle
 * DESCRIPTION
 *  This function is used to get the handle of mp4 provider, and send source component's handle and APIs.
 * PARAMETERS
 *  prSrcMgr             [IN]     the handle of the source component.
 *  prSrcAPI             [IN]     APIs which provided by source component.
 *  prPrvHdlr            [OUT]    the handle of the mp4 provider.
 * RETURNS
 *  PROVIDER_ERROR_T
 *****************************************************************************/
PROVIDER_ERROR_T MP4ProviderGetHandle(void *prSrcMgr, SP_API_T *prSrcAPI, SPIF_PROVIDER_HANDLE_T *prPrvHdlr)
{
    MP4_PROVIDER_CTRL_T *prMP4ProviderCtrl;

    if (prSrcMgr == NULL || prSrcAPI == NULL || prPrvHdlr == NULL)
    {
        MP4_PVDR_ASSERT(0);
        return PROVIDER_ERROR;
    }

    video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MP4PVDR_GET_HANDLE, 0);

    prMP4ProviderCtrl = (MP4_PROVIDER_CTRL_T *)prSrcAPI->SPFN_MALLOC_CLA(prSrcMgr, sizeof(MP4_PROVIDER_CTRL_T), KAL_TRUE);
    if(prMP4ProviderCtrl == NULL)
    {
        return PROVIDER_ERROR;
    }
    memset(prMP4ProviderCtrl, 0, sizeof(MP4_PROVIDER_CTRL_T));
    prMP4ProviderCtrl->prSourceAPI = prSrcAPI;
    prMP4ProviderCtrl->prSourceHandle = prSrcMgr;
    prPrvHdlr->pvHandle = (void *)prMP4ProviderCtrl;
    prPrvHdlr->prAPI = (PROVIDER_API_T *)&rMP4ProviderAPI;

    pMP4ProviderHdlr = prMP4ProviderCtrl;
    MP4_PVDR_ASSERT(pMP4ProviderHdlr != NULL);
    return PROVIDER_ERROR_NONE;
}

/*****************************************************************************
 * FUNCTION
 *  MP4ProviderReleaseHandle
 * DESCRIPTION
 *  This function is used to release the handle of mp4 provider.
 * PARAMETERS
 *  pvHandle             [IN]     the handle of the mp4 provider.
 * RETURNS
 *  PROVIDER_ERROR_T
 *****************************************************************************/
PROVIDER_ERROR_T MP4ProviderReleaseHandle(void* pvHandle)
{
    MP4_PROVIDER_CTRL_T *prMP4ProviderCtrl = (MP4_PROVIDER_CTRL_T *)pvHandle;

    MP4_PROVIDER_CHECK_POINTER(pvHandle);

    video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MP4PVDR_REL_HANDLE, sizeof(MP4_PROVIDER_CTRL_T));

    prMP4ProviderCtrl->prSourceAPI->SPFN_FREE_CLA(prMP4ProviderCtrl->prSourceHandle, pvHandle);

    return PROVIDER_ERROR_NONE;
}

#ifdef __VE_DCM_WITH_COMPRESSION__
#pragma arm section code, rodata
#endif

#ifdef __VE_MOT_DECRYPTION__
/*****************************************************************************
 * FUNCTION
 *  MP4ProviderCheckMotIntegrity
 * DESCRIPTION
 *  This function is used to check current file is mp4 container or not.
 * PARAMETERS
 *  pu1Buf             [IN]     the pointer of the buffer in the file beginning.
 *  u4Len             [IN]     size of check buffer.
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool MP4ProviderCheckMotIntegrity(kal_uint8 *pu1Buf, kal_uint32 u4Len)
{
    kal_uint32 u4Type,u4DecryptedType;

    if (((void *)pu1Buf) == NULL)
    {
        return KAL_FALSE;
    }

    if (u4Len < MP4_PROVIDER_CHECK_CONTAINER_LEN)
    {
        return KAL_FALSE;
    }

    u4Type = (kal_uint32)((pu1Buf[4] << 24) + (pu1Buf[5] << 16) + (pu1Buf[6] << 8) + (pu1Buf[7]));

    MotUtilityCrackTheCode(u4Type,&u4DecryptedType,(kal_bool)1);
	
	if (u4DecryptedType != MP4_PROVIDER_CHECK_FTYP)
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  MP4ProviderCheckIntegrity
 * DESCRIPTION
 *  This function is used to check current file is mp4 container or not.
 * PARAMETERS
 *  pu1Buf             [IN]     the pointer of the buffer in the file beginning.
 *  u4Len             [IN]     size of check buffer.
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool MP4ProviderCheckIntegrity(kal_uint8 *pu1Buf, kal_uint32 u4Len)
{
    kal_uint32 u4Type;

    if (((void *)pu1Buf) == NULL)
    {
        return KAL_FALSE;
    }

    if (u4Len < MP4_PROVIDER_CHECK_CONTAINER_LEN)
    {
        return KAL_FALSE;
    }

    u4Type = (kal_uint32)((pu1Buf[4] << 24) + (pu1Buf[5] << 16) + (pu1Buf[6] << 8) + (pu1Buf[7]));

    if (u4Type != MP4_PROVIDER_CHECK_FTYP)
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}

#ifdef __VE_PGDL_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mp4_mp_is_prog_dl_file
 * DESCRIPTION
 *  This function is to indicate if the progressive download mp4 file is ready to play.
 * PARAMETERS
 *  p_file_buf       [IN]     pointer of file buffer.
 *  buf_size         [IN]     buffer size.
 *  is_pd            [IN]     boolean value to indicate if it is a progressive download file profile.
 * RETURNS
 *  media_error_t
 *****************************************************************************/
media_error_t mp4_mp_is_prog_dl_file(kal_uint8* p_file_buf, kal_uint32 buf_size, kal_bool* is_pdl)
{
    STFSAL t_fsal;
    FSAL_Status e_fsal_ret;
    STMp4Parser t_parser;
    MP4_Parser_Status e_parser_ret;

    if(MP4ProviderCheckIntegrity(p_file_buf,buf_size)==KAL_TRUE)
        t_parser.OpenType = MED_MODE_PDL_FILE;


    FSAL_Direct_SetRamFileSize(&t_fsal, buf_size);
    e_fsal_ret = FSAL_Open(&t_fsal, (void*)p_file_buf, FSAL_ROMFILE);

    if (e_fsal_ret != FSAL_OK)
    {
        kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_FSAL_ERROR, e_fsal_ret, __LINE__);
        return MED_E_FSAL_ERROR;
    }

    //kal_trace(TRACE_FUNC, VID_TRC_MP4MP_QUERY_ISPDPROFILE, __LINE__);
    e_parser_ret = MP4_IsPDProfile(&t_parser, &t_fsal, is_pdl);

    FSAL_Close(&t_fsal);

    if (e_parser_ret != MP4_PARSER_OK)
    {
        kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_PARSER_ERROR, e_parser_ret, __LINE__);
        return MED_E_PARSER_ERROR;
    }
    else
    {
        //MP4_MP_TRACE_RET_OK();
        return MED_S_OK;
    }
}

static media_error_t MP4ProviderCheckPDLFileMeta(MP4_PROVIDER_CTRL_T *prMP4ProviderCtrl)
{
    MP4_Parser_Status e_parser_ret;
    FSAL_Status e_fsal_ret;
    kal_uint32 file_size;
    kal_uint32 meta_size;
    kal_uint8 has_aud_track = MP4_RESERVED_TRACK_NO;
    kal_uint8 has_vid_track = MP4_RESERVED_TRACK_NO;
    kal_uint32 vid_duration;
    kal_uint32 aud_duration;

    /* get file size */
    e_fsal_ret = FSAL_GetFileSize(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO], &file_size);

    kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_CHECK_PDL_FILE_META, file_size);

    if (e_fsal_ret != FSAL_OK)
    {
        MP4_PROVIDER_TRACE_FSAL_ERROR(e_fsal_ret);
        return MED_E_FSAL_ERROR;
    }
	prMP4ProviderCtrl->pt_parser->OpenType = prMP4ProviderCtrl->eSrcType;

    e_parser_ret = MP4_GetMdatBoxOffset(prMP4ProviderCtrl->pt_parser, prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO], &meta_size);

    if (e_parser_ret != MP4_PARSER_OK)
    {
        MP4_PROVIDER_TRACE_PARSE_ERROR(e_parser_ret);
        return MED_E_PARSER_ERROR;
    }

    if (file_size > meta_size)
    {
        /* TODO: this can be called once only for optimization */
        e_parser_ret = MP4_Parse(prMP4ProviderCtrl->pt_parser, prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO]);
        if (e_parser_ret != MP4_PARSER_OK && e_parser_ret != MP4_PARSER_WARNING_TRAILING_GARBAGE)
        {
            MP4_PROVIDER_TRACE_PARSE_ERROR(e_parser_ret);
            return MED_E_PARSER_ERROR;
        }

        e_fsal_ret = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_stco[SOURCE_PROVIDER_PORT_VIDEO], prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO]);
        if (e_fsal_ret != FSAL_OK)
        {
            MP4_PROVIDER_TRACE_FSAL_ERROR(e_fsal_ret);
            return MED_E_FSAL_ERROR;
        }

        e_fsal_ret = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_stsz[SOURCE_PROVIDER_PORT_VIDEO], prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO]);
        if (e_fsal_ret != FSAL_OK)
        {
            MP4_PROVIDER_TRACE_FSAL_ERROR(e_fsal_ret);
            return MED_E_FSAL_ERROR;
        }

        FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal_stco[SOURCE_PROVIDER_PORT_VIDEO],
                       MP4_PROVIDER_STCO_BUF_SIZE*4,
                       (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf_stco[SOURCE_PROVIDER_PORT_VIDEO]);
        FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal_stsz[SOURCE_PROVIDER_PORT_VIDEO],
                       MP4_PROVIDER_STSZ_BUF_SIZE*4,
                       (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf_stsz[SOURCE_PROVIDER_PORT_VIDEO]);

        MP4_SetFSAL_STCO(prMP4ProviderCtrl->pt_parser, MP4_TRACK_VIDEO,
                                                            prMP4ProviderCtrl->pt_fsal_stco[SOURCE_PROVIDER_PORT_VIDEO]);
        MP4_SetFSAL_STSZ(prMP4ProviderCtrl->pt_parser, MP4_TRACK_VIDEO,
                                                            prMP4ProviderCtrl->pt_fsal_stsz[SOURCE_PROVIDER_PORT_VIDEO]);
        MP4_UpdateSampleCount(prMP4ProviderCtrl->pt_parser, MP4_TRACK_VIDEO);
        //MP4_STBL_CacheTablePreprocess(self->pt_parser, self->p_stbl_buf, MP4_MP_STBL_BUF_SIZE);

        /* check if there is any video track */
        e_parser_ret = MP4_GetTrackNoByType(prMP4ProviderCtrl->pt_parser, MP4_TRACK_VIDEO, &has_vid_track);
        if (!(prMP4ProviderCtrl->eTrack & SOURCE_PROVIDER_TRACK_VIDEO))
        {
            has_vid_track = MP4_RESERVED_TRACK_NO;
        }

        /* check if there is any audio track */
        e_parser_ret = MP4_GetTrackNoByType(prMP4ProviderCtrl->pt_parser, MP4_TRACK_AUDIO, &has_aud_track);
        if (!(prMP4ProviderCtrl->eTrack & SOURCE_PROVIDER_TRACK_AUDIO))
        {
            has_aud_track = MP4_RESERVED_TRACK_NO;
        }

        /* if there is audio track, we need at least 1 frame for audio driver to init */
        if (has_aud_track != MP4_RESERVED_TRACK_NO)
        {
            // To make prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO] file size sync with FS
            e_fsal_ret = FSAL_GetFileSize(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO], &file_size);

            e_fsal_ret = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_stco[SOURCE_PROVIDER_PORT_AUDIO], prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO]);
            if (e_fsal_ret != FSAL_OK)
            {
                MP4_PROVIDER_TRACE_FSAL_ERROR(e_fsal_ret);
                return MED_E_FSAL_ERROR;
            }

            e_fsal_ret = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_stsz[SOURCE_PROVIDER_PORT_AUDIO], prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO]);
            if (e_fsal_ret != FSAL_OK)
            {
                MP4_PROVIDER_TRACE_FSAL_ERROR(e_fsal_ret);
                return MED_E_FSAL_ERROR;
            }

            FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal_stco[SOURCE_PROVIDER_PORT_AUDIO],
                           MP4_PROVIDER_STCO_BUF_SIZE*4,
                           (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf_stco[SOURCE_PROVIDER_PORT_AUDIO]);
            FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal_stsz[SOURCE_PROVIDER_PORT_AUDIO],
                           MP4_PROVIDER_STSZ_BUF_SIZE*4,
                           (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf_stsz[SOURCE_PROVIDER_PORT_AUDIO]);

            MP4_SetFSAL_STCO(prMP4ProviderCtrl->pt_parser, MP4_TRACK_AUDIO,
                                                prMP4ProviderCtrl->pt_fsal_stco[SOURCE_PROVIDER_PORT_AUDIO]);
            MP4_SetFSAL_STSZ(prMP4ProviderCtrl->pt_parser, MP4_TRACK_AUDIO,
                            prMP4ProviderCtrl->pt_fsal_stsz[SOURCE_PROVIDER_PORT_AUDIO]);
            MP4_UpdateSampleCount(prMP4ProviderCtrl->pt_parser, MP4_TRACK_AUDIO);

            e_parser_ret = MP4_Audio_GetAvailableDur(prMP4ProviderCtrl->pt_parser, &aud_duration);

            if (e_parser_ret != MP4_PARSER_OK)
            {
                MP4_PROVIDER_TRACE_PARSE_ERROR(e_parser_ret);
                return MED_E_PDL_SHORT_OF_BUF;
            }
        }
        else
        {
            /* set aud_duration > 0 to pretend audio is ready */
            aud_duration = 1;
        }

        /* if there is visual track, we need at least 1 frame for video driver to init */
        if (has_vid_track != MP4_RESERVED_TRACK_NO)
        {
            e_parser_ret = MP4_Video_GetAvailableDur(prMP4ProviderCtrl->pt_parser, &vid_duration);

            if (e_parser_ret != MP4_PARSER_OK)
            {
                MP4_PROVIDER_TRACE_PARSE_ERROR(e_parser_ret);
                return MED_E_PDL_SHORT_OF_BUF;
            }
        }
        else
        {
            /* set vid_duration > 0 to pretend audio is ready */
            vid_duration = 1;
        }

        //kal_trace(MP4_PROVIDER_TRACE_GROUP, VID_TRC_MP4MP_AVAIL_DUR, aud_duration, vid_duration);

        if (aud_duration > 0 && vid_duration > 0)
        {
            return MED_S_OK;
        }
        else
        {
           return MED_E_PDL_SHORT_OF_BUF;
        }
    }
    else
    {
        return MED_E_PDL_SHORT_OF_BUF;
    }
}

static PROVIDER_ERROR_T MP4ProviderOpenPDLMeta(MP4_PROVIDER_CTRL_T *prMP4ProviderCtrl)
{
    media_error_t eRet;

    eRet = MP4ProviderCheckPDLFileMeta(prMP4ProviderCtrl);

    if (eRet == PROVIDER_ERROR_NONE)
    {
        /* enough buffer for PDL to open file */
        FSAL_Close(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_VIDEO]);
        FSAL_Close(prMP4ProviderCtrl->pt_fsal[SOURCE_PROVIDER_PORT_AUDIO]);
    }
    else if (eRet == MED_E_PDL_SHORT_OF_BUF)
    {
        /* NOT enough buffer for PDL open, waiting for more... */
        //MP4_MP_SET_STATE(MEDIA_PROVIDER_STATE_PDL_META_BUFFERING);
        //mpl_start_timer(MPL_TIMER_PDL_BUFFERING, 1000, _mp4_mp_pdl_meta_buffering_hdlr, (void*)self);
        prMP4ProviderCtrl->fgWaitMeta = KAL_TRUE;
        return PROVIDER_ERROR_WAIT_DATA;
    }
    else
    {
        /* other errors */
        MP4_PROVIDER_TRACE_RET_ERR(eRet);
        MP4ProviderSelfDeInit(prMP4ProviderCtrl);
        return PROVIDER_ERROR;
    }

    return PROVIDER_ERROR_NONE;
}

/*****************************************************************************
 * FUNCTION
 *  _mp4_mp_open_pdl_file
 * DESCRIPTION
 *  This function is to open the progressive download file
 *  is ready to play.
 * PARAMETERS
 *  self             [IN]     mp4 mp context.
 * RETURNS
 *  media_error_t
 *****************************************************************************/
static PROVIDER_ERROR_T MP4ProviderOpenPDLFile(MP4_PROVIDER_CTRL_T* prMP4ProviderCtrl)
{
    FSAL_Status eFsalRet;
    kal_int32 u4DrmRet;

    if (KAL_FALSE == _MP4ProviderIsPDGL(prMP4ProviderCtrl))
    {
        return PROVIDER_ERROR_NONE;
    }

    if (MP4_PROVIDER_HAS_TRACK(SOURCE_PROVIDER_PORT_AUDIO))
    {
        /***************************************
         * PDL MP4 Audio
         ***************************************/
        eFsalRet = FSAL_Open(prMP4ProviderCtrl->pt_fsal_pdl[SOURCE_PROVIDER_PORT_AUDIO],
                               (void*)prMP4ProviderCtrl->u_src.acFileName,
                               FSAL_READ_SHARED);
        if (eFsalRet != FSAL_OK)
        {
            MP4_PROVIDER_TRACE_FSAL_ERROR(eFsalRet);
            return PROVIDER_ERROR;
        }

        FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal_pdl[SOURCE_PROVIDER_PORT_AUDIO],
                       (kal_uint32)MP4_PROVIDER_FSAL_BUF_SIZE*4,
                       (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf_pdl[SOURCE_PROVIDER_PORT_AUDIO]);

        MP4_Parser_Clone(prMP4ProviderCtrl->pt_parser,
                         prMP4ProviderCtrl->pt_parser_pdl[SOURCE_PROVIDER_PORT_AUDIO],
                         prMP4ProviderCtrl->pt_fsal_pdl[SOURCE_PROVIDER_PORT_AUDIO]);

        eFsalRet = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_stco_pdl[SOURCE_PROVIDER_PORT_AUDIO],
                                      prMP4ProviderCtrl->pt_fsal_pdl[SOURCE_PROVIDER_PORT_AUDIO]);
        if (eFsalRet != FSAL_OK)
        {
            MP4_PROVIDER_TRACE_FSAL_ERROR(eFsalRet);
            return PROVIDER_ERROR;
        }

        FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal_stco_pdl[SOURCE_PROVIDER_PORT_AUDIO],
                       MP4_PROVIDER_STCO_BUF_SIZE*4,
                       (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf_stco_pdl[SOURCE_PROVIDER_PORT_AUDIO]);

        eFsalRet = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_stsz_pdl[SOURCE_PROVIDER_PORT_AUDIO],
                                      prMP4ProviderCtrl->pt_fsal_pdl[SOURCE_PROVIDER_PORT_AUDIO]);
        if (eFsalRet != FSAL_OK)
        {
            MP4_PROVIDER_TRACE_FSAL_ERROR(eFsalRet);
            return PROVIDER_ERROR;
        }

        FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal_stsz_pdl[SOURCE_PROVIDER_PORT_AUDIO],
                       MP4_PROVIDER_STSZ_BUF_SIZE*4,
                       (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf_stsz_pdl[SOURCE_PROVIDER_PORT_AUDIO]);

        MP4_SetFSAL_STCO(prMP4ProviderCtrl->pt_parser_pdl[SOURCE_PROVIDER_PORT_AUDIO],
                         MP4_TRACK_AUDIO,
                         prMP4ProviderCtrl->pt_fsal_stco_pdl[SOURCE_PROVIDER_PORT_AUDIO]);
        MP4_SetFSAL_STSZ(prMP4ProviderCtrl->pt_parser_pdl[SOURCE_PROVIDER_PORT_AUDIO],
                         MP4_TRACK_AUDIO,
                         prMP4ProviderCtrl->pt_fsal_stsz_pdl[SOURCE_PROVIDER_PORT_AUDIO]);
        MP4_UpdateSampleCount(prMP4ProviderCtrl->pt_parser_pdl[SOURCE_PROVIDER_PORT_AUDIO], MP4_TRACK_AUDIO);

        u4DrmRet = FSAL_SetSeekHint(prMP4ProviderCtrl->pt_fsal_pdl[SOURCE_PROVIDER_PORT_AUDIO],
                                    MP4_PROVIDER_SEEK_HINT_SIZE,
                                    prMP4ProviderCtrl->pt_fsal_seek_hint);
        if (u4DrmRet < 0)
        {
            MP4_PROVIDER_TRACE_RET_ERR(u4DrmRet);
            return PROVIDER_ERROR;
        }
    }

    if (MP4_PROVIDER_HAS_TRACK(SOURCE_PROVIDER_PORT_VIDEO))
    {
        /***************************************
         * PDL MP4 Visual
         ***************************************/
        eFsalRet = FSAL_Open(prMP4ProviderCtrl->pt_fsal_pdl[SOURCE_PROVIDER_PORT_VIDEO],
                               (void*)prMP4ProviderCtrl->u_src.acFileName,
                               FSAL_READ_SHARED);
        if (eFsalRet != FSAL_OK)
        {
            MP4_PROVIDER_TRACE_FSAL_ERROR(eFsalRet);
            return PROVIDER_ERROR;
        }

        FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal_pdl[SOURCE_PROVIDER_PORT_VIDEO],
                       (kal_uint32)MP4_PROVIDER_FSAL_BUF_SIZE*4,
                       (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf_pdl[SOURCE_PROVIDER_PORT_VIDEO]);

        MP4_Parser_Clone(prMP4ProviderCtrl->pt_parser,
                         prMP4ProviderCtrl->pt_parser_pdl[SOURCE_PROVIDER_PORT_VIDEO],
                         prMP4ProviderCtrl->pt_fsal_pdl[SOURCE_PROVIDER_PORT_VIDEO]);

        eFsalRet = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_stco_pdl[SOURCE_PROVIDER_PORT_VIDEO],
                                      prMP4ProviderCtrl->pt_fsal_pdl[SOURCE_PROVIDER_PORT_VIDEO]);
        if (eFsalRet != FSAL_OK)
        {
            MP4_PROVIDER_TRACE_FSAL_ERROR(eFsalRet);
            return PROVIDER_ERROR;
        }

        FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal_stco_pdl[SOURCE_PROVIDER_PORT_VIDEO],
                       MP4_PROVIDER_STCO_BUF_SIZE*4,
                       (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf_stco_pdl[SOURCE_PROVIDER_PORT_VIDEO]);

        eFsalRet = FSAL_Open_Attach(prMP4ProviderCtrl->pt_fsal_stsz_pdl[SOURCE_PROVIDER_PORT_VIDEO],
                                      prMP4ProviderCtrl->pt_fsal_pdl[SOURCE_PROVIDER_PORT_VIDEO]);
        if (eFsalRet != FSAL_OK)
        {
            MP4_PROVIDER_TRACE_FSAL_ERROR(eFsalRet);
            return PROVIDER_ERROR;
        }

        FSAL_SetBuffer(prMP4ProviderCtrl->pt_fsal_stsz_pdl[SOURCE_PROVIDER_PORT_VIDEO],
                       MP4_PROVIDER_STSZ_BUF_SIZE*4,
                       (kal_uint8*)prMP4ProviderCtrl->p_fsal_buf_stsz_pdl[SOURCE_PROVIDER_PORT_VIDEO]);

        MP4_SetFSAL_STCO(prMP4ProviderCtrl->pt_parser_pdl[SOURCE_PROVIDER_PORT_VIDEO],
                         MP4_TRACK_VIDEO,
                         prMP4ProviderCtrl->pt_fsal_stco_pdl[SOURCE_PROVIDER_PORT_VIDEO]);
        MP4_SetFSAL_STSZ(prMP4ProviderCtrl->pt_parser_pdl[SOURCE_PROVIDER_PORT_VIDEO],
                         MP4_TRACK_VIDEO,
                         prMP4ProviderCtrl->pt_fsal_stsz_pdl[SOURCE_PROVIDER_PORT_VIDEO]);
        MP4_UpdateSampleCount(prMP4ProviderCtrl->pt_parser_pdl[SOURCE_PROVIDER_PORT_VIDEO], MP4_TRACK_VIDEO);

        u4DrmRet = FSAL_SetSeekHint(prMP4ProviderCtrl->pt_fsal_pdl[SOURCE_PROVIDER_PORT_VIDEO],
                                    MP4_PROVIDER_SEEK_HINT_SIZE,
                                    prMP4ProviderCtrl->pt_fsal_seek_hint);
        if (u4DrmRet < 0)
        {
            MP4_PROVIDER_TRACE_RET_ERR(u4DrmRet);
            return PROVIDER_ERROR;
        }
    }

    return PROVIDER_ERROR_NONE;
}
#endif

media_error_t mp4_mp_scramble_buffer(kal_uint8* p_file_buf, kal_uint32 buf_size)
{
#ifdef	__VE_PGDL_SUPPORT_YOUTUBE__
    return MotUtilityPGDLDecryption(p_file_buf,buf_size);
#else
    return MED_E_PARSER_ERROR;
#endif
}


#endif /* __VE_MP43GP_FILE_FORMAT_SUPPORT__ */

