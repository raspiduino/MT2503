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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   dcmgr_parload.c
 *
 * Project:
 * --------
 *   MAUI (MT6260)
 *
 * Description:
 * ------------
 *   Dynamic Code Compression for dynamic code relocation
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/


#include "dcmgr.h"
#include "dcmgr_comp.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "simple_memory_manager.h"
#include "LzmaDec.h"
#include "verno.h"
#include "cache_sw.h"
#include "us_timer.h"
#include "viva.h"

#if defined(__MTK_TARGET__)


#if defined(__DCM_WITH_COMPRESSION__)

#ifdef __MTK_TARGET__
#pragma arm section rodata = "DYNAMIC_DUMMY_CODE_HEAD"
#endif /* __MTK_TARGET__ */
const kal_uint32 dcmgr_dummy_dynamic_code_head = DCMGR_KEY_ID_HEAD;
const dcmgr_comp_header_t dcmgr_dynamic_code_hdr = {
    DCMGR_KEY_ID_HEAD, DCMGR_KEY_ID_TAIL, VERNO_STR, 
    {HW_VER_STR " " BUILD_DATE_TIME_STR}, 0, 0
};
#ifdef __MTK_TARGET__
#pragma arm section rodata
#endif /* __MTK_TARGET__ */

#ifdef __MTK_TARGET__
#pragma arm section rodata = "DYNAMIC_DUMMY_CODE_END"
#endif /* __MTK_TARGET__ */
const kal_uint32 dcmgr_dummy_dynamic_code_end = DCMGR_KEY_ID_DUMMY;
#ifdef __MTK_TARGET__
#pragma arm section rodata
#endif /* __MTK_TARGET__ */


#if defined(DCM_COMP_SCAT_SBC_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_SBC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_SBC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_SBC$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_SBC_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_SBC_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_SBC_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_SBC,
    DCM_COMP_SBC_TARGET
    DCM_COMP_SBC_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_SBC$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_SBC_AVAILABLE */

#if defined(DCM_COMP_SCAT_BESLOUDNESS_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_BESLOUDNESS$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_BESLOUDNESS$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_BESLOUDNESS$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_BESLOUDNESS_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_BESLOUDNESS_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_BESLOUDNESS_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_BESLOUDNESS,
    DCM_COMP_BESLOUDNESS_TARGET
    DCM_COMP_BESLOUDNESS_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_BESLOUDNESS$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_BESLOUDNESS_AVAILABLE */

#if defined(DCM_COMP_SCAT_MAUIINIT_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_MAUIINIT$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MAUIINIT$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MAUIINIT$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_MAUIINIT_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_MAUIINIT_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_MAUIINIT_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_MAUIINIT,
    DCM_COMP_MAUIINIT_TARGET
    DCM_COMP_MAUIINIT_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_MAUIINIT$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_BESLOUDNESS_AVAILABLE */


#if defined(DCM_COMP_SCAT_MP4DEC_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_MP4DEC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4DEC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4DEC$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4DEC_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_MP4DEC_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_MP4DEC_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_MP4DEC_C,
    DCM_COMP_MP4DEC_TARGET
    DCM_COMP_MP4DEC_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_MP4DEC$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_MP4DEC_AVAILABLE */

#if defined(DCM_COMP_SCAT_MP4ENC_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_MP4ENC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4ENC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4ENC$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4ENC_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_MP4ENC_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_MP4ENC_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_MP4ENC_C,
    DCM_COMP_MP4ENC_TARGET
    DCM_COMP_MP4ENC_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_MP4ENC$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_MP4ENC_AVAILABLE */

#if defined(DCM_COMP_SCAT_H264DEC_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_H264DEC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_H264DEC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_H264DEC$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_H264DEC_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_H264DEC_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_H264DEC_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_H264DEC_C,
    DCM_COMP_H264DEC_TARGET
    DCM_COMP_H264DEC_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_H264DEC$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_H264DEC_AVAILABLE */

#if defined(DCM_COMP_SCAT_MP4ASPDEC_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_MP4ASPDEC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4ASPDEC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4ASPDEC$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4ASPDEC_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_MP4ASPDEC_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_MP4ASPDEC_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_MP4ASPDEC,
    DCM_COMP_MP4ASPDEC_TARGET
    DCM_COMP_MP4ASPDEC_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_MP4ASPDEC$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_MP4ASPDEC_AVAILABLE */

#if defined(DCM_COMP_SCAT_VP8DEC_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_VP8DEC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_VP8DEC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_VP8DEC$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_VP8DEC_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_VP8DEC_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_VP8DEC_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_VP8DEC,
    DCM_COMP_VP8DEC_TARGET
    DCM_COMP_VP8DEC_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_VP8DEC$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_VP8DEC_AVAILABLE */

#if defined(DCM_COMP_SCAT_VCH_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_VCH$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_VCH$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_VCH$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_VCH_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_VCH_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_VCH_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_VCH,
    DCM_COMP_VCH_TARGET
    DCM_COMP_VCH_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_VCH$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_VCH_AVAILABLE */

#if defined(DCM_COMP_SCAT_MATVDRIVER_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_MATVDRIVER$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MATVDRIVER$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MATVDRIVER$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_MATVDRIVER_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_MATVDRIVER_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_MATVDRIVER_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_MATVDRIVER,
    DCM_COMP_MATVDRIVER_TARGET
    DCM_COMP_MATVDRIVER_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_MATVDRIVER$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_MATVDRIVER_AVAILABLE */

#if defined(DCM_COMP_SCAT_VEENC_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_VEENC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_VEENC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_VEENC$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_VEENC_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_VEENC_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_VEENC_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_VEENC,
    DCM_COMP_VEENC_TARGET
    DCM_COMP_VEENC_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_VEENC$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_VEENC_AVAILABLE */

#if defined(DCM_COMP_SCAT_VEDEC_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_VEDEC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_VEDEC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_VEDEC$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_VEDEC_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_VEDEC_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_VEDEC_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_VEDEC,
    DCM_COMP_VEDEC_TARGET
    DCM_COMP_VEDEC_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_VEDEC$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_VEDEC_AVAILABLE */

#if defined(DCM_COMP_SCAT_DAF_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_DAF$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_DAF$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_DAF$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_DAF_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_DAF_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_DAF_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_DAF,
    DCM_COMP_DAF_TARGET
    DCM_COMP_DAF_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_DAF$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_DAF_AVAILABLE */

#if defined(DCM_COMP_SCAT_WAVETABLE_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_WAVETABLE$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_WAVETABLE$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_WAVETABLE$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_WAVETABLE_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_WAVETABLE_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_WAVETABLE_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_WAVETABLE,
    DCM_COMP_WAVETABLE_TARGET
    DCM_COMP_WAVETABLE_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_WAVETABLE$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_WAVETABLE_AVAILABLE */

#if defined(DCM_COMP_SCAT_BROWSER_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_BROWSER$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_BROWSER$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_BROWSER$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_BROWSER_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_BROWSER_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_BROWSER_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_BROWSER,
    DCM_COMP_BROWSER_TARGET
    DCM_COMP_BROWSER_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_BROWSER$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_BROWSER_AVAILABLE */

#if defined(DCM_COMP_SCAT_CALC_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_CALC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CALC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CALC$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_CALC_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_CALC_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_CALC_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_CALC,
    DCM_COMP_CALC_TARGET
    DCM_COMP_CALC_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_CALC$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_CALC_AVAILABLE */

#if defined(DCM_COMP_SCAT_CALLSET_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_CALLSET$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CALLSET$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CALLSET$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_CALLSET_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_CALLSET_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_CALLSET_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_CALLSET,
    DCM_COMP_CALLSET_TARGET
    DCM_COMP_CALLSET_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_CALLSET$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_CALLSET_AVAILABLE */

#if defined(DCM_COMP_SCAT_CAMCO_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_CAMCO$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CAMCO$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CAMCO$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_CAMCO_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_CAMCO_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_CAMCO_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_CAMCO,
    DCM_COMP_CAMCO_TARGET
    DCM_COMP_CAMCO_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_CAMCO$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_CAMCO_AVAILABLE */

#if defined(DCM_COMP_SCAT_CLNDR_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_CLNDR$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CLNDR$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CLNDR$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_CLNDR_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_CLNDR_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_CLNDR_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_CLNDR,
    DCM_COMP_CLNDR_TARGET
    DCM_COMP_CLNDR_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_CLNDR$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_CLNDR_AVAILABLE */

#if defined(DCM_COMP_SCAT_CLOCK_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_CLOCK$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CLOCK$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CLOCK$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_CLOCK_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_CLOCK_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_CLOCK_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_CLOCK,
    DCM_COMP_CLOCK_TARGET
    DCM_COMP_CLOCK_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_CLOCK$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_CLOCK_AVAILABLE */

#if defined(DCM_COMP_SCAT_FMRADIO_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_FMRADIO$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_FMRADIO$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_FMRADIO$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_FMRADIO_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_FMRADIO_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_FMRADIO_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_FMRADIO,
    DCM_COMP_FMRADIO_TARGET
    DCM_COMP_FMRADIO_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_FMRADIO$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_FMRADIO_AVAILABLE */

#if defined(DCM_COMP_SCAT_SOUNDSET_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_SOUNDSET$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_SOUNDSET$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_SOUNDSET$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_SOUNDSET_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_SOUNDSET_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_SOUNDSET_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_SOUNDSET,
    DCM_COMP_SOUNDSET_TARGET
    DCM_COMP_SOUNDSET_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_SOUNDSET$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_SOUNDSET_AVAILABLE */

#if defined(DCM_COMP_SCAT_COSMOS_EM_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_COSMOS_EM$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_COSMOS_EM$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_COSMOS_EM$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_COSMOS_EM_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_COSMOS_EM_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_COSMOS_EM_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_COSMOS_EM,
    DCM_COMP_COSMOS_EM_TARGET
    DCM_COMP_COSMOS_EM_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_COSMOS_EM$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_COSMOS_EM_AVAILABLE */

#if defined(DCM_COMP_SCAT_COSMOS_FM_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_COSMOS_FM$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_COSMOS_FM$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_COSMOS_FM$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_COSMOS_FM_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_COSMOS_FM_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_COSMOS_FM_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_COSMOS_FM,
    DCM_COMP_COSMOS_FM_TARGET
    DCM_COMP_COSMOS_FM_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_COSMOS_FM$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_COSMOS_FM_AVAILABLE */

#if defined(DCM_COMP_SCAT_COSMOS_DTCNT_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_COSMOS_DTCNT$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_COSMOS_DTCNT$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_COSMOS_DTCNT$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_COSMOS_DTCNT_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_COSMOS_DTCNT_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_COSMOS_DTCNT_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_COSMOS_DTCNT,
    DCM_COMP_COSMOS_DTCNT_TARGET
    DCM_COMP_COSMOS_DTCNT_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_COSMOS_DTCNT$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_COSMOS_DTCNT_AVAILABLE */

#if defined(DCM_COMP_SCAT_MOT_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_MOT$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MOT$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MOT$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_MOT_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_MOT_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_MOT_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_MOT,
    DCM_COMP_MOT_TARGET
    DCM_COMP_MOT_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_MOT$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_MOT_AVAILABLE */

#if defined(DCM_COMP_SCAT_SECSET_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_SECSET$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_SECSET$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_SECSET$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_SECSET_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_SECSET_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_SECSET_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_SECSET,
    DCM_COMP_SECSET_TARGET
    DCM_COMP_SECSET_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_SECSET$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_SECSET_AVAILABLE */

#if defined(DCM_COMP_SCAT_BAIDUSEARCH_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_BAIDUSEARCH$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_BAIDUSEARCH$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_BAIDUSEARCH$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_BAIDUSEARCH_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_BAIDUSEARCH_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_BAIDUSEARCH_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_BAIDUSEARCH,
    DCM_COMP_BAIDUSEARCH_TARGET
    DCM_COMP_BAIDUSEARCH_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_BAIDUSEARCH$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_BAIDUSEARCH_AVAILABLE */

#if defined(DCM_COMP_SCAT_BOOTUP_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_BOOTUP$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_BOOTUP$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_BOOTUP$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_BOOTUP_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_BOOTUP_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_BOOTUP_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_BOOTUP,
    DCM_COMP_BOOTUP_TARGET
    DCM_COMP_BOOTUP_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_BOOTUP$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_BOOTUP_AVAILABLE */

#if defined(DCM_COMP_SCAT_SETTING_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_SETTING$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_SETTING$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_SETTING$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_SETTING_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_SETTING_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_SETTING_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_SETTING,
    DCM_COMP_SETTING_TARGET
    DCM_COMP_SETTING_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_SETTING$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_SETTING_AVAILABLE */

#if defined(DCM_COMP_SCAT_SOUNDREC_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_SOUNDREC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_SOUNDREC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_SOUNDREC$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_SOUNDREC_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_SOUNDREC_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_SOUNDREC_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_SOUNDREC,
    DCM_COMP_SOUNDREC_TARGET
    DCM_COMP_SOUNDREC_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_SOUNDREC$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_SOUNDREC_AVAILABLE */

#if defined(DCM_COMP_SCAT_CAMIMGV_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_CAMIMGV$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CAMIMGV$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CAMIMGV$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_CAMIMGV_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_CAMIMGV_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_CAMIMGV_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_CAMIMGV,
    DCM_COMP_CAMIMGV_TARGET
    DCM_COMP_CAMIMGV_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_CAMIMGV$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_CAMIMGV_AVAILABLE */

#if defined(DCM_COMP_SCAT_VDOREC_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_VDOREC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_VDOREC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_VDOREC$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_VDOREC_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_VDOREC_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_VDOREC_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_VDOREC,
    DCM_COMP_VDOREC_TARGET
    DCM_COMP_VDOREC_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_VDOREC$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_VDOREC_AVAILABLE */

#if defined(DCM_COMP_SCAT_CALENDAR_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_CALENDAR$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CALENDAR$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CALENDAR$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_CALENDAR_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_CALENDAR_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_CALENDAR_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_CALENDAR,
    DCM_COMP_CALENDAR_TARGET
    DCM_COMP_CALENDAR_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_CALENDAR$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_CALENDAR_AVAILABLE */

#if defined(DCM_COMP_SCAT_CALCULATOR_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_CALCULATOR$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CALCULATOR$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CALCULATOR$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_CALCULATOR_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_CALCULATOR_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_CALCULATOR_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_CALCULATOR,
    DCM_COMP_CALCULATOR_TARGET
    DCM_COMP_CALCULATOR_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_CALCULATOR$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_CALCULATOR_AVAILABLE */

#if defined(DCM_COMP_SCAT_VDOPLY_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_VDOPLY$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_VDOPLY$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_VDOPLY$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_VDOPLY_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_VDOPLY_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_VDOPLY_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_VDOPLY,
    DCM_COMP_VDOPLY_TARGET
    DCM_COMP_VDOPLY_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_VDOPLY$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_VDOPLY_AVAILABLE */

#if defined(DCM_COMP_SCAT_MATV_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_MATV$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MATV$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MATV$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_MATV_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_MATV_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_MATV_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_MATV,
    DCM_COMP_MATV_TARGET
    DCM_COMP_MATV_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_MATV$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_MATV_AVAILABLE */

#if defined(DCM_COMP_SCAT_SNDREC_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_SNDREC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_SNDREC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_SNDREC$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_SNDREC_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_SNDREC_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_SNDREC_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_SNDREC,
    DCM_COMP_SNDREC_TARGET
    DCM_COMP_SNDREC_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_SNDREC$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_SNDREC_AVAILABLE */

#if defined(DCM_COMP_SCAT_PROFILE_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_PROFILE$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_PROFILE$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_PROFILE$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_PROFILE_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_PROFILE_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_PROFILE_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_PROFILE,
    DCM_COMP_PROFILE_TARGET
    DCM_COMP_PROFILE_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_PROFILE$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_PROFILE_AVAILABLE */

#if defined(DCM_COMP_SCAT_CALLSETTING_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_CALLSETTING$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CALLSETTING$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CALLSETTING$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_CALLSETTING_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_CALLSETTING_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_CALLSETTING_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_CALLSETTING,
    DCM_COMP_CALLSETTING_TARGET
    DCM_COMP_CALLSETTING_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_CALLSETTING$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_CALLSETTING_AVAILABLE */

#if defined(DCM_COMP_SCAT_SCRLOCK_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_SCRLOCK$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_SCRLOCK$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_SCRLOCK$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_SCRLOCK_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_SCRLOCK_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_SCRLOCK_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_SCRLOCK,
    DCM_COMP_SCRLOCK_TARGET
    DCM_COMP_SCRLOCK_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_SCRLOCK$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_SCRLOCK_AVAILABLE */

#if defined(DCM_COMP_SCAT_SETTINGS_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_SETTINGS$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_SETTINGS$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_SETTINGS$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_SETTINGS_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_SETTINGS_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_SETTINGS_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_SETTINGS,
    DCM_COMP_SETTINGS_TARGET
    DCM_COMP_SETTINGS_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_SETTINGS$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_SETTINGS_AVAILABLE */

#if defined(DCM_COMP_SCAT_DTCNT_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_DTCNT$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_DTCNT$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_DTCNT$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_DTCNT_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_DTCNT_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_DTCNT_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_DTCNT,
    DCM_COMP_DTCNT_TARGET
    DCM_COMP_DTCNT_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_DTCNT$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_DTCNT_AVAILABLE */

#if defined(DCM_COMP_SCAT_EM_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_EM$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_EM$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_EM$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_EM_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_EM_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_EM_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_EM,
    DCM_COMP_EM_TARGET
    DCM_COMP_EM_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_EM$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_EM_AVAILABLE */

#if defined(DCM_COMP_SCAT_FM_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_FM$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_FM$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_FM$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_FM_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_FM_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_FM_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_FM,
    DCM_COMP_FM_TARGET
    DCM_COMP_FM_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_FM$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_FM_AVAILABLE */

#if defined(DCM_COMP_SCAT_AMRREC_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_AMRREC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_AMRREC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_AMRREC$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_AMRREC_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_AMRREC_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_AMRREC_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_AMRREC,
    DCM_COMP_AMRREC_TARGET
    DCM_COMP_AMRREC_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_AMRREC$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_AMRREC_AVAILABLE */

#if defined(DCM_COMP_SCAT_WAVREC_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_WAVREC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_WAVREC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_WAVREC$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_WAVREC_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_WAVREC_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_WAVREC_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_WAVREC,
    DCM_COMP_WAVREC_TARGET
    DCM_COMP_WAVREC_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_WAVREC$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_WAVREC_AVAILABLE */

#if defined(DCM_COMP_SCAT_PCMREC_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_PCMREC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_PCMREC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_PCMREC$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_PCMREC_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_PCMREC_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_PCMREC_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_PCMREC,
    DCM_COMP_PCMREC_TARGET
    DCM_COMP_PCMREC_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_PCMREC$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_PCMREC_AVAILABLE */

#if defined(DCM_COMP_SCAT_MDP_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_MDP$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MDP$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MDP$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_MDP_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_MDP_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_MDP_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_MDP,
    DCM_COMP_MDP_TARGET
    DCM_COMP_MDP_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_MDP$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_MDP_AVAILABLE */

#if defined(DCM_COMP_SCAT_VECOM_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_VECOM$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_VECOM$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_VECOM$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_VECOM_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_VECOM_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_VECOM_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_VECOM,
    DCM_COMP_VECOM_TARGET
    DCM_COMP_VECOM_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_VECOM$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_VECOM_AVAILABLE */

#if defined(DCM_COMP_SCAT_RENDER_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_RENDER$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_RENDER$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_RENDER$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_RENDER_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_RENDER_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_RENDER_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_RENDER,
    DCM_COMP_RENDER_TARGET
    DCM_COMP_RENDER_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_RENDER$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_RENDER_AVAILABLE */

#if defined(DCM_COMP_SCAT_MDICAM_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_MDICAM$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MDICAM$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MDICAM$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_MDICAM_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_MDICAM_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_MDICAM_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_MDICAM,
    DCM_COMP_MDICAM_TARGET
    DCM_COMP_MDICAM_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_MDICAM$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_MDICAM_AVAILABLE */

#if defined(DCM_COMP_SCAT_MWREC_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_MWREC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MWREC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MWREC$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_MWREC_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_MWREC_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_MWREC_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_MWREC,
    DCM_COMP_MWREC_TARGET
    DCM_COMP_MWREC_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_MWREC$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_MWREC_AVAILABLE */

#if defined(DCM_COMP_SCAT_MDIVID_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_MDIVID$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MDIVID$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MDIVID$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_MDIVID_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_MDIVID_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_MDIVID_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_MDIVID,
    DCM_COMP_MDIVID_TARGET
    DCM_COMP_MDIVID_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_MDIVID$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_MDIVID_AVAILABLE */

#if defined(DCM_COMP_SCAT_VIDMSG_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_VIDMSG$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_VIDMSG$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_VIDMSG$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_VIDMSG_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_VIDMSG_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_VIDMSG_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_VIDMSG,
    DCM_COMP_VIDMSG_TARGET
    DCM_COMP_VIDMSG_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_VIDMSG$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_VIDMSG_AVAILABLE */

#if defined(DCM_COMP_SCAT_MWWEBCAM_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_MWWEBCAM$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MWWEBCAM$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MWWEBCAM$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_MWWEBCAM_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_MWWEBCAM_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_MWWEBCAM_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_MWWEBCAM,
    DCM_COMP_MWWEBCAM_TARGET
    DCM_COMP_MWWEBCAM_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_MWWEBCAM$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_MWWEBCAM_AVAILABLE */

#if defined(DCM_COMP_SCAT_USBVIDEO_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_USBVIDEO$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_USBVIDEO$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_USBVIDEO$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_USBVIDEO_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_USBVIDEO_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_USBVIDEO_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_USBVIDEO,
    DCM_COMP_USBVIDEO_TARGET
    DCM_COMP_USBVIDEO_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_USBVIDEO$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_USBVIDEO_AVAILABLE */

#if defined(DCM_COMP_SCAT_MDIMTV_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_MDIMTV$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MDIMTV$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MDIMTV$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_MDIMTV_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_MDIMTV_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_MDIMTV_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_MDIMTV,
    DCM_COMP_MDIMTV_TARGET
    DCM_COMP_MDIMTV_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_MDIMTV$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_MDIMTV_AVAILABLE */

#if defined(DCM_COMP_SCAT_MEDMTV_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_MEDMTV$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MEDMTV$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MEDMTV$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_MEDMTV_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_MEDMTV_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_MEDMTV_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_MEDMTV,
    DCM_COMP_MEDMTV_TARGET
    DCM_COMP_MEDMTV_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_MEDMTV$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_MEDMTV_AVAILABLE */

#if defined(DCM_COMP_SCAT_MDISTREAM_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_MDISTREAM$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MDISTREAM$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MDISTREAM$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_MDISTREAM_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_MDISTREAM_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_MDISTREAM_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_MDISTREAM,
    DCM_COMP_MDISTREAM_TARGET
    DCM_COMP_MDISTREAM_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_MDISTREAM$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_MDISTREAM_AVAILABLE */

#if defined(DCM_COMP_SCAT_MEDSTREAM_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_MEDSTREAM$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MEDSTREAM$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MEDSTREAM$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_MEDSTREAM_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_MEDSTREAM_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_MEDSTREAM_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_MEDSTREAM,
    DCM_COMP_MEDSTREAM_TARGET
    DCM_COMP_MEDSTREAM_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_MEDSTREAM$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_MEDSTREAM_AVAILABLE */

#if defined(DCM_COMP_SCAT_CAMCAL_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_CAMCAL$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CAMCAL$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CAMCAL$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_CAMCAL_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_CAMCAL_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_CAMCAL_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_CAMCAL,
    DCM_COMP_CAMCAL_TARGET
    DCM_COMP_CAMCAL_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_CAMCAL$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_CAMCAL_AVAILABLE */

#if defined(DCM_COMP_SCAT_CAMMED_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_CAMMED$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CAMMED$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CAMMED$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_CAMMED_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_CAMMED_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_CAMMED_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_CAMMED,
    DCM_COMP_CAMMED_TARGET
    DCM_COMP_CAMMED_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_CAMMED$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_CAMMED_AVAILABLE */

#if defined(DCM_COMP_SCAT_VKLAYOUT_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_VKLAYOUT$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_VKLAYOUT$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_VKLAYOUT$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_VKLAYOUT_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_VKLAYOUT_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_VKLAYOUT_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_VKLAYOUT,
    DCM_COMP_VKLAYOUT_TARGET
    DCM_COMP_VKLAYOUT_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_VKLAYOUT$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_VKLAYOUT_AVAILABLE */

#if defined(DCM_COMP_SCAT_GUOBIHW_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_GUOBIHW$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_GUOBIHW$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_GUOBIHW$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_GUOBIHW_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_GUOBIHW_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_GUOBIHW_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_GUOBIHW,
    DCM_COMP_GUOBIHW_TARGET
    DCM_COMP_GUOBIHW_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_GUOBIHW$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_GUOBIHW_AVAILABLE */

#if defined(DCM_COMP_SCAT_IME_AVAILABLE)
extern kal_uint32 Load$$DYNAMIC_COMP_IME$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_IME$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_IME$$Length;
extern kal_uint32 Image$$DYNAMIC_COMP_IME_BODY$$Length;

#pragma arm section rodata = "DYNAMIC_COMP_IME_HEAD"
const dcmgr_image_header_t   dcmgr_dynamic_comp_IME_head = {
    DCMGR_COMPRESS_ID,     
    0x31322D44,
    DYNAMIC_CODE_COMPRESS_IME,
    DCM_COMP_IME_TARGET
    DCM_COMP_IME_GROUP
    (kal_uint32)&Image$$DYNAMIC_COMP_IME$$Base,
};
#pragma arm section rodata
#endif /* DCM_COMP_SCAT_IME_AVAILABLE */


static const dcmgr_image_header_t* DCM_image_list[DYNAMIC_CODE_COMPRESS_NUM+1] = {
#if defined(DCM_COMP_SCAT_SBC_AVAILABLE)
    &dcmgr_dynamic_comp_SBC_head,
#endif

#if defined(DCM_COMP_SCAT_BESLOUDNESS_AVAILABLE)
    &dcmgr_dynamic_comp_BESLOUDNESS_head,
#endif

#if defined(DCM_COMP_SCAT_MAUIINIT_AVAILABLE)
	&dcmgr_dynamic_comp_MAUIINIT_head,
#endif

#if defined(DCM_COMP_SCAT_MP4DEC_AVAILABLE)
    &dcmgr_dynamic_comp_MP4DEC_head,
#endif

#if defined(DCM_COMP_SCAT_MP4ENC_AVAILABLE)
    &dcmgr_dynamic_comp_MP4ENC_head,
#endif

#if defined(DCM_COMP_SCAT_H264DEC_AVAILABLE)
    &dcmgr_dynamic_comp_H264DEC_head,
#endif

#if defined(DCM_COMP_SCAT_MP4ASPDEC_AVAILABLE)
    &dcmgr_dynamic_comp_MP4ASPDEC_head,
#endif

#if defined(DCM_COMP_SCAT_VP8DEC_AVAILABLE)
    &dcmgr_dynamic_comp_VP8DEC_head,
#endif

#if defined(DCM_COMP_SCAT_VCH_AVAILABLE)
			&dcmgr_dynamic_comp_VCH_head,
#endif

#if defined(DCM_COMP_SCAT_MATVDRIVER_AVAILABLE)
    &dcmgr_dynamic_comp_MATVDRIVER_head,
#endif

#if defined(DCM_COMP_SCAT_VEENC_AVAILABLE)
    &dcmgr_dynamic_comp_VEENC_head,
#endif

#if defined(DCM_COMP_SCAT_VEDEC_AVAILABLE)
    &dcmgr_dynamic_comp_VEDEC_head,
#endif

#if defined(DCM_COMP_SCAT_DAF_AVAILABLE)
    &dcmgr_dynamic_comp_DAF_head,
#endif

#if defined(DCM_COMP_SCAT_WAVETABLE_AVAILABLE)
    &dcmgr_dynamic_comp_WAVETABLE_head,
#endif

#if defined(DCM_COMP_SCAT_BROWSER_AVAILABLE)
    &dcmgr_dynamic_comp_BROWSER_head,
#endif

#if defined(DCM_COMP_SCAT_CALC_AVAILABLE)
    &dcmgr_dynamic_comp_CALC_head,
#endif

#if defined(DCM_COMP_SCAT_CALLSET_AVAILABLE)
    &dcmgr_dynamic_comp_CALLSET_head,
#endif

#if defined(DCM_COMP_SCAT_CAMCO_AVAILABLE)
    &dcmgr_dynamic_comp_CAMCO_head,
#endif

#if defined(DCM_COMP_SCAT_CLNDR_AVAILABLE)
    &dcmgr_dynamic_comp_CLNDR_head,
#endif

#if defined(DCM_COMP_SCAT_CLOCK_AVAILABLE)
    &dcmgr_dynamic_comp_CLOCK_head,
#endif

#if defined(DCM_COMP_SCAT_FMRADIO_AVAILABLE)
    &dcmgr_dynamic_comp_FMRADIO_head,
#endif

#if defined(DCM_COMP_SCAT_SOUNDSET_AVAILABLE)
    &dcmgr_dynamic_comp_SOUNDSET_head,
#endif

#if defined(DCM_COMP_SCAT_COSMOS_EM_AVAILABLE)
    &dcmgr_dynamic_comp_COSMOS_EM_head,
#endif

#if defined(DCM_COMP_SCAT_COSMOS_FM_AVAILABLE)
    &dcmgr_dynamic_comp_COSMOS_FM_head,
#endif

#if defined(DCM_COMP_SCAT_COSMOS_DTCNT_AVAILABLE)
    &dcmgr_dynamic_comp_COSMOS_DTCNT_head,
#endif

#if defined(DCM_COMP_SCAT_MOT_AVAILABLE)
    &dcmgr_dynamic_comp_MOT_head,
#endif

#if defined(DCM_COMP_SCAT_SECSET_AVAILABLE)
    &dcmgr_dynamic_comp_SECSET_head,
#endif

#if defined(DCM_COMP_SCAT_BAIDUSEARCH_AVAILABLE)
    &dcmgr_dynamic_comp_BAIDUSEARCH_head,
#endif

#if defined(DCM_COMP_SCAT_BOOTUP_AVAILABLE)
    &dcmgr_dynamic_comp_BOOTUP_head,
#endif

#if defined(DCM_COMP_SCAT_SETTING_AVAILABLE)
    &dcmgr_dynamic_comp_SETTING_head,
#endif

#if defined(DCM_COMP_SCAT_SOUNDREC_AVAILABLE)
    &dcmgr_dynamic_comp_SOUNDREC_head,
#endif

#if defined(DCM_COMP_SCAT_CAMIMGV_AVAILABLE)
    &dcmgr_dynamic_comp_CAMIMGV_head,
#endif

#if defined(DCM_COMP_SCAT_VDOREC_AVAILABLE)
    &dcmgr_dynamic_comp_VDOREC_head,
#endif

#if defined(DCM_COMP_SCAT_CALENDAR_AVAILABLE)
    &dcmgr_dynamic_comp_CALENDAR_head,
#endif

#if defined(DCM_COMP_SCAT_CALCULATOR_AVAILABLE)
    &dcmgr_dynamic_comp_CALCULATOR_head,
#endif

#if defined(DCM_COMP_SCAT_VDOPLY_AVAILABLE)
    &dcmgr_dynamic_comp_VDOPLY_head,
#endif

#if defined(DCM_COMP_SCAT_MATV_AVAILABLE)
    &dcmgr_dynamic_comp_MATV_head,
#endif

#if defined(DCM_COMP_SCAT_SNDREC_AVAILABLE)
    &dcmgr_dynamic_comp_SNDREC_head,
#endif

#if defined(DCM_COMP_SCAT_PROFILE_AVAILABLE)
    &dcmgr_dynamic_comp_PROFILE_head,
#endif

#if defined(DCM_COMP_SCAT_CALLSETTING_AVAILABLE)
    &dcmgr_dynamic_comp_CALLSETTING_head,
#endif

#if defined(DCM_COMP_SCAT_SCRLOCK_AVAILABLE)
    &dcmgr_dynamic_comp_SCRLOCK_head,
#endif

#if defined(DCM_COMP_SCAT_SETTINGS_AVAILABLE)
    &dcmgr_dynamic_comp_SETTINGS_head,
#endif

#if defined(DCM_COMP_SCAT_DTCNT_AVAILABLE)
    &dcmgr_dynamic_comp_DTCNT_head,
#endif

#if defined(DCM_COMP_SCAT_EM_AVAILABLE)
    &dcmgr_dynamic_comp_EM_head,
#endif

#if defined(DCM_COMP_SCAT_FM_AVAILABLE)
    &dcmgr_dynamic_comp_FM_head,
#endif

#if defined(DCM_COMP_SCAT_AMRREC_AVAILABLE)
    &dcmgr_dynamic_comp_AMRREC_head,
#endif

#if defined(DCM_COMP_SCAT_WAVREC_AVAILABLE)
    &dcmgr_dynamic_comp_WAVREC_head,
#endif

#if defined(DCM_COMP_SCAT_PCMREC_AVAILABLE)
    &dcmgr_dynamic_comp_PCMREC_head,
#endif

#if defined(DCM_COMP_SCAT_MDP_AVAILABLE)
    &dcmgr_dynamic_comp_MDP_head,
#endif

#if defined(DCM_COMP_SCAT_VECOM_AVAILABLE)
    &dcmgr_dynamic_comp_VECOM_head,
#endif

#if defined(DCM_COMP_SCAT_RENDER_AVAILABLE)
    &dcmgr_dynamic_comp_RENDER_head,
#endif

#if defined(DCM_COMP_SCAT_MDICAM_AVAILABLE)
    &dcmgr_dynamic_comp_MDICAM_head,
#endif

#if defined(DCM_COMP_SCAT_MWREC_AVAILABLE)
    &dcmgr_dynamic_comp_MWREC_head,
#endif

#if defined(DCM_COMP_SCAT_MDIVID_AVAILABLE)
    &dcmgr_dynamic_comp_MDIVID_head,
#endif

#if defined(DCM_COMP_SCAT_VIDMSG_AVAILABLE)
    &dcmgr_dynamic_comp_VIDMSG_head,
#endif

#if defined(DCM_COMP_SCAT_MWWEBCAM_AVAILABLE)
    &dcmgr_dynamic_comp_MWWEBCAM_head,
#endif

#if defined(DCM_COMP_SCAT_USBVIDEO_AVAILABLE)
    &dcmgr_dynamic_comp_USBVIDEO_head,
#endif

#if defined(DCM_COMP_SCAT_MDIMTV_AVAILABLE)
    &dcmgr_dynamic_comp_MDIMTV_head,
#endif

#if defined(DCM_COMP_SCAT_MEDMTV_AVAILABLE)
    &dcmgr_dynamic_comp_MEDMTV_head,
#endif

#if defined(DCM_COMP_SCAT_MDISTREAM_AVAILABLE)
    &dcmgr_dynamic_comp_MDISTREAM_head,
#endif

#if defined(DCM_COMP_SCAT_MEDSTREAM_AVAILABLE)
    &dcmgr_dynamic_comp_MEDSTREAM_head,
#endif

#if defined(DCM_COMP_SCAT_CAMCAL_AVAILABLE)
    &dcmgr_dynamic_comp_CAMCAL_head,
#endif

#if defined(DCM_COMP_SCAT_CAMMED_AVAILABLE)
    &dcmgr_dynamic_comp_CAMMED_head,
#endif

#if defined(DCM_COMP_SCAT_VKLAYOUT_AVAILABLE)
    &dcmgr_dynamic_comp_VKLAYOUT_head,
#endif

#if defined(DCM_COMP_SCAT_GUOBIHW_AVAILABLE)
    &dcmgr_dynamic_comp_GUOBIHW_head,
#endif

#if defined(DCM_COMP_SCAT_IME_AVAILABLE)
    &dcmgr_dynamic_comp_IME_head,
#endif

    NULL
};

const kal_uint8 DCM_comp_group_by_dynamic_code_id[DYNAMIC_CODE_COMPRESS_NUM] = {
    DCM_COMP_GROUP_CONFIGURE
}; 


const kal_uint8 DCM_comp_pool_by_dynamic_code_id[DYNAMIC_CODE_COMPRESS_NUM] = {
    DCM_COMP_TARGET_CONFIGURE
}; 

const kal_uint8 dynamic_code_id_mapping_tbl[DYNAMIC_CODE_COMPRESS_MAX_NUM] = {
    DYNAMIC_CODE_COMPRESS_ID_MAPPING_TBL_CONFIGURE
}; 

/*
 * Function prototype
 */
typedef void (*dcmgr_decomp_load_func)(kal_uint32* , kal_uint32* , kal_int32 , kal_uint32);

/* 
 * imported function
 */
extern void INT_InitDynamicDCZIMMIpoolRegion(void); 
extern void  mmi_frm_appmem_stage1_init(void);
extern kal_bool INT_QueryExceptionStatus(void);
extern kal_uint32 custom_get_fat_addr(void);
extern kal_uint32 INT_RetrieveRemappedFlashBaseAddr(void);

extern void DCM_Load_Logic( kal_int32,
                     kal_int32,
                     kal_int32,
                     kal_uint32,
                     kal_uint32,
                     const kal_uint8 *,
                     const kal_uint8 *,
                     dcmgr_trunk_info_t **,
                     kal_uint8 *,
                     dcmgr_decomp_load_func,
                     kal_uint32);

extern void DCM_Unload_Logic( kal_int32,
                              kal_int32,
                              kal_int32,
                              kal_uint32,
                              kal_uint32,
                              const kal_uint8 *,
                              const kal_uint8 *,
                              dcmgr_trunk_info_t **,
                              kal_uint8 *,
                              dcmgr_decomp_load_func,
                              kal_uint32);
                            
extern kal_bool DCM_Isloaded_Logic( kal_int32,
                                    kal_int32,
                                    kal_int32,
                                    kal_uint32,
                                    kal_uint32,
                                    const kal_uint8 *,
                                    const kal_uint8 *,
                                    dcmgr_trunk_info_t **,
                                    kal_uint8 *,
                                    dcmgr_decomp_load_func,
                                    kal_uint32);   
                                                    
extern kal_bool DCM_IsAvailable_Logic( kal_int32,
                                       kal_int32,
                                       kal_int32,
                                       kal_uint32,
                                       const kal_uint8 *,
                                       const kal_uint8 *,
                                       dcmgr_trunk_info_t **,
                                       kal_uint8 *,
                                       dcmgr_decomp_load_func,
                                       kal_uint32);
                                       
extern void init_mutex();                                  
                                       
/* 
 * forward declaration 
 */
static void* decomp_mem_alloc(void* mem_ptr, kal_uint32 mem_size);
static void decomp_mem_free(void* mem_ptr, void* mem_address);

/* 
 * global variables 
 */
/* !!CAUTION!!
 * Following pointer must have volatile attribute to ensure that 
 * the compressed file header would be read from flash.
 * Otherwise, compiler would do optimization according to the dummy header content 
 * which would be updated by build script during image compression stage.
 */
volatile dcmgr_comp_header_t const *dcmgr_code_ptr = NULL;
kal_uint32 dcmgr_comp_image_num;


/* 
 * Variables for lzma decmpression
 */
static STSMM _dcmgr_decompress_smm;
static ISzAlloc dcmgr_decomp_Alloc = { decomp_mem_alloc, decomp_mem_free };
kal_uint32 dcmgr_decomp_buff_pool[DCMGR_DECOMP_BUFF_SIZE>>2];


/*
 * For DCM lazy loading, we may divide a region into many trunks.
 * For each trunk, we need to record its information (e.g. base loading address and size, execution address and size ...)
 * Since we don't know the number of trunks until post-build. We reserve a memory space for the use of trunk information.
 * The memory space is managed by simple memory manager
 * You can refer to dcmgr_comp.h to see the definition of data structure of trunk information.
 * Variables for 
 */
static STSMM _dcmgr_trunk_info_smm;
kal_uint32 dcmgr_trunk_info_buff_pool[DCMGR_TRUNK_INFO_BUFF_SIZE>>2];

/*
 * dcmgr_trunk_by_pool is indexed by DCM pool id.
 * Each entry is a head of a single link list and the link list store the information of trunks which are in the same pool. 
 */
dcmgr_trunk_info_t * dcmgr_trunk_by_pool[DCM_COMP_TARGET_NUM] = {0};


/*
  * Principle
  * 1. A group consists of regions
  * 2. Exclusive : A pool can be occupied by many groups but only one group can occupy the pool a time
  */

// current group that occupied the pool
kal_uint8 current_comp_group_id[DCM_COMP_TARGET_NUM];


/*************************************************************************
* FUNCTION
*  decomp_mem_init
*
* DESCRIPTION
* Initialize memory buffer for LZMA decompression use
*
* CALLS 
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void decomp_mem_init(void* buff_ptr, kal_uint32 buff_size)
{
    smmInit(&_dcmgr_decompress_smm, buff_ptr, buff_size);
}

/*************************************************************************
* FUNCTION
*  decomp_mem_alloc
*
* DESCRIPTION
*   Allocation memory from LZMA decompression memory buffer
*
* CALLS 
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void* decomp_mem_alloc(void* mem_ptr, kal_uint32 mem_size)
{
    return smmMallocAligned(&_dcmgr_decompress_smm, mem_size, 4);
}

/*************************************************************************
* FUNCTION
*  decomp_mem_free
*
* DESCRIPTION
*   Dummy free decompression memory buffer
*
* CALLS 
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void decomp_mem_free(void* mem_ptr, void* mem_address)
{
    /* do nothing */
}

/*************************************************************************
* FUNCTION
*  trunk_buffer_mem_init
*
* DESCRIPTION
*   Initialize memory buffer for storing trunk information
*
* CALLS 
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/

static kal_uint32 trunk_buffer_mem_init(void* buff_ptr, kal_uint32 buff_size)
{
    return smmInit(&_dcmgr_trunk_info_smm, buff_ptr, buff_size);
}

/*************************************************************************
* FUNCTION
*  trunk_buffer_mem_alloc
*
* DESCRIPTION
*   Allocation memory from trunk memory buffer
*
* CALLS 
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void* trunk_buffer_mem_alloc(kal_uint32 mem_size)
{
    return smmMallocAligned(&_dcmgr_trunk_info_smm, mem_size, 4);
}

/*************************************************************************
* FUNCTION
*  trunk_buffer_mem_free
*
* DESCRIPTION
*   Dummy free trunk memory buffer
*
* CALLS 
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
//static void trunk_buffer_mem_free(void* mem_ptr, void* mem_address)
//{
    /* do nothing */
//}

/*************************************************************************
* FUNCTION
*  dcmgr_decomp_load
*
* DESCRIPTION
*   Dynamic code manager for decompress and relocate code into the overlay RAM region 
*
* CALLS 
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/

void dcmgr_decomp_load(kal_uint32* dest_ptr, kal_uint32* src_ptr, kal_int32 img_size, kal_uint32 src_size)
{
    kal_uint32 destsize = 0, srcsize = 0;
    ELzmaStatus status;
    SRes ret;
#if defined(__DCMGR_LOG_DECOMPRESS_TIME__)
    static kal_uint32 dec_start = 0, dec_end = 0, dec_dur = 0;
    dec_start = ust_get_current_time();
#endif
    /* initialize malloc pool */
    decomp_mem_init(dcmgr_decomp_buff_pool, DCMGR_DECOMP_BUFF_SIZE);
    /* decompress target image */
    destsize = img_size;
    srcsize = src_size-13;

    ret = LzmaDecodeWithOption((Byte*)dest_ptr, &destsize, ((const Byte*)src_ptr)+13, &srcsize,
                     (const Byte*)src_ptr, LZMA_PROPS_SIZE, LZMA_FINISH_ANY, &status,
                     &dcmgr_decomp_Alloc, LZMA_ADDON_OPTION_T);
    EXT_ASSERT(ret == SZ_OK, ret, (kal_uint32)dest_ptr, (kal_uint32)src_ptr);


    /* clean and invalidate D-cache */
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
    clean_and_invalidate_dcache((kal_uint32)dest_ptr, (img_size+0x1f)&(~0x1f));
#endif /* __DYNAMIC_SWITCH_CACHEABILITY__ */

    /* invalidate I-cache */
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) || defined(__WRITE_THROUGH_CACHEABLE__)
    invalidate_icache((kal_uint32)dest_ptr, (img_size+0x1f)&(~0x1f));
#endif /* __DYNAMIC_SWITCH_CACHEABILITY__ || __WRITE_THROUGH_CACHEABLE__ */

#if defined(__DCMGR_LOG_DECOMPRESS_TIME__)
    dec_end = ust_get_current_time();
    dec_dur = ust_get_duration(dec_start, dec_end);
#endif
}

/*************************************************************************
* FUNCTION
*  dcmgr_copy_load
*
* DESCRIPTION
*   Dynamic code manager for relocate code into the overlay TCM region 
*
* CALLS 
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
//static void dcmgr_copy_load(kal_uint32* dest_ptr, kal_uint32* src_ptr,  kal_int32 img_size, kal_uint32 src_size)
//{
//    kal_mem_cpy(dest_ptr, src_ptr, img_size);
    
//}


/*************************************************************************
* FUNCTION
*  DCM_Load
*
* DESCRIPTION
*   Dynamic code manager for relocate code into the overlay TCM region 
*
* CALLS 
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/

void DCM_Load( kal_int32 dynamic_code_id, kal_uint32 **remaining_buf, kal_uint32 *buf_size )
{
     /* log for DCM_Load*/
#if defined(__DCMGR_LOG_LOAD_TIME__)
	   static kal_uint32 load_start = 0, load_end = 0, load_dur = 0;
	   load_start = ust_get_current_time();
#endif

    kal_uint32 dcmgr_api_caller = 0;
    GET_RETURN_ADDRESS(dcmgr_api_caller);

	  
    DCM_Load_Logic(dynamic_code_id,
                   DYNAMIC_CODE_COMPRESS_BEGIN,
                   DYNAMIC_CODE_COMPRESS_END,
                   DCM_COMP_TARGET_NUM,
                   DCM_COMP_GROUP_NUM,
                   DCM_comp_group_by_dynamic_code_id,
                   DCM_comp_pool_by_dynamic_code_id,
                   dcmgr_trunk_by_pool,
                   current_comp_group_id,
                   dcmgr_decomp_load,
                   dcmgr_api_caller);

    /* log for DCM_Load */
#if defined(__DCMGR_LOG_LOAD_TIME__)
    load_end = ust_get_current_time();
    load_dur = ust_get_duration(load_start, load_end);
#endif		
    
}


/*************************************************************************
* FUNCTION
*   DCM_Unload
*
* DESCRIPTION
*   Terminate the usage of DCM
*
* CALLS 
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/

void DCM_Unload( kal_int32 dynamic_code_id ) /* TODO - add DCM with compression support */
{
    
    kal_uint32 dcmgr_api_caller = 0;
    GET_RETURN_ADDRESS(dcmgr_api_caller);
    
    DCM_Unload_Logic(dynamic_code_id,
                   DYNAMIC_CODE_COMPRESS_BEGIN,
                   DYNAMIC_CODE_COMPRESS_END,
                   DCM_COMP_TARGET_NUM,
                   DCM_COMP_GROUP_NUM,
                   DCM_comp_group_by_dynamic_code_id,
                   DCM_comp_pool_by_dynamic_code_id,
                   dcmgr_trunk_by_pool,
                   current_comp_group_id,
                   dcmgr_decomp_load,
                   dcmgr_api_caller);
    
}



/*************************************************************************
* FUNCTION
*   DCM_Isloaded
*
* DESCRIPTION
*   query if the DCM code already loaded
*
* CALLS 
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/


kal_bool DCM_Isloaded( kal_int32 dynamic_code_id ) /* TODO - add DCM with compression support */
{
	
	  kal_uint32 dcmgr_api_caller = 0;
    GET_RETURN_ADDRESS(dcmgr_api_caller);
	
    return DCM_Isloaded_Logic(dynamic_code_id,
                              DYNAMIC_CODE_COMPRESS_BEGIN,
                              DYNAMIC_CODE_COMPRESS_END,
                              DCM_COMP_TARGET_NUM,
                              DCM_COMP_GROUP_NUM,
                              DCM_comp_group_by_dynamic_code_id,
                              DCM_comp_pool_by_dynamic_code_id,
                              dcmgr_trunk_by_pool,
                              current_comp_group_id,
                              dcmgr_decomp_load,
                              dcmgr_api_caller);

}



/*************************************************************************
* FUNCTION
*   DCM_IsAvailable
*
* DESCRIPTION
*   query if the DCM pool for the dynamic_code_id is free
*
* CALLS 
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/

kal_bool DCM_IsAvailable( kal_int32 dynamic_code_id ) /* TODO - add DCM with compression support */
{
	
	  kal_uint32 dcmgr_api_caller = 0;
    GET_RETURN_ADDRESS(dcmgr_api_caller);
	
    return DCM_IsAvailable_Logic(dynamic_code_id,
                                 DYNAMIC_CODE_COMPRESS_BEGIN,
                                 DYNAMIC_CODE_COMPRESS_END,
                                 DCM_COMP_TARGET_NUM,
                                 DCM_comp_group_by_dynamic_code_id,
                                 DCM_comp_pool_by_dynamic_code_id,
                                 dcmgr_trunk_by_pool,
                                 current_comp_group_id,
                                 dcmgr_decomp_load,
                                 dcmgr_api_caller);
}

/*************************************************************************
* FUNCTION
*   add_trunk
*
* DESCRIPTION
* 
*
* CALLS 
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/

/*
 * This is only used in bootup time. Should we protect it via mutex ?
 */

void add_trunk(kal_int32 pool_id, 
               kal_uint32 dcmgr_img_id,
               kal_uint32 dcmgr_comp_base,
               kal_uint32 dcmgr_exec_base,
               kal_uint32 dcmgr_comp_size,
               kal_uint32 dcmgr_trunk_size)
{
		
	  dcmgr_trunk_info_t * new_trunk;
	  dcmgr_trunk_info_t * ptr;
	  
	  /* allocate new trunk node */
    new_trunk = (dcmgr_trunk_info_t *) trunk_buffer_mem_alloc(DCMGR_TRUNK_INFO_STRUCT_SIZE);
    
    EXT_ASSERT(new_trunk != NULL, 0, 0, 0);
    
    /* fill value */
    new_trunk->dcmgr_img_id = dcmgr_img_id;
    new_trunk->dcmgr_comp_base = dcmgr_comp_base;
    new_trunk->dcmgr_exec_base = dcmgr_exec_base;
    new_trunk->dcmgr_comp_size = dcmgr_comp_size;
    new_trunk->dcmgr_trunk_size = dcmgr_trunk_size;
    new_trunk->dcmgr_trunk_state = DCM_COMP_TRUNK_NOT_ON_RAM;
    new_trunk->next = 0;
        
    /* insert trunk node */
    ptr = dcmgr_trunk_by_pool[pool_id];
    if(ptr == 0) {
        dcmgr_trunk_by_pool[pool_id] = new_trunk;
    }
    else {
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_trunk;
    }
    
}

/*************************************************************************
* FUNCTION
*   DCMGR_Init_Trunk_Information
*
* DESCRIPTION
*   Initialize trunk informations 
*
* CALLS 
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/

static kal_bool DCMGR_Init_Trunk_Information()
{
	  kal_uint32 idx;
	  kal_uint32 idx2;
	  kal_uint32 code_id;
	  kal_int32 pool_id;
	  kal_uint32 comp_addr;
	  kal_uint32 exec_addr;
	  kal_uint32 comp_size;
	  kal_uint32 trunk_size;
	  kal_uint32 * src_ptr=0;
	  kal_uint32 trunk_num_of_region;
	  
	  if( trunk_buffer_mem_init(dcmgr_trunk_info_buff_pool, DCMGR_TRUNK_INFO_BUFF_SIZE) == 1)
	  {
	      
	      for( idx = 0 ; idx < dcmgr_code_ptr->dcmgr_img_num ; idx++ )
	      {
            code_id = dcmgr_code_ptr->dcmgr_img_list[idx].dcmgr_exec_info.dcmgr_img_id;
            
            pool_id = dcmgr_code_ptr->dcmgr_img_list[idx].dcmgr_exec_info.dcmgr_pool;
            pool_id--;

	          src_ptr = (kal_uint32 *)(((kal_uint32)dcmgr_code_ptr)+
                                      dcmgr_code_ptr->dcmgr_img_list[idx].dcmgr_file_pos);
            
            /*
             * There is header at beginning of each region
             */                          
            trunk_num_of_region = src_ptr[0];
            
            
            EXT_ASSERT(trunk_num_of_region != 0, 0, 0, 0);
            
            
            comp_addr = ((kal_uint32)src_ptr) + (1 + trunk_num_of_region * 2) * 4;
			exec_addr = dcmgr_code_ptr->dcmgr_img_list[idx].dcmgr_exec_info.dcmgr_img_exec_base;
            for( idx2 = 0 ; idx2 < trunk_num_of_region ; idx2++ )
            {
            	  
            	  trunk_size = src_ptr[1 + (idx2 * 2) + 0];
            	  comp_size = src_ptr[1 + (idx2 * 2) + 1];
            	  add_trunk(pool_id, 
               						code_id,
               						comp_addr,
               						exec_addr,
               						comp_size,
               						trunk_size);
               	comp_addr = comp_addr + comp_size;
               	exec_addr = exec_addr + trunk_size;
            	  
            }
            
	      }
	      
	      return KAL_TRUE;
	  }
	  else 
	  {
	      return KAL_FALSE;
	  }
}


/*************************************************************************
* FUNCTION
*   DCM_ImageAmount
*
* DESCRIPTION
*   query how many images are dynamically lodable
*
* CALLS 
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static kal_uint32 DCM_ImageAmount(void)
{
    kal_uint32                 idx = 0;

    for(idx = 0 ; idx < DYNAMIC_CODE_COMPRESS_NUM ; idx++)
    {
        if(NULL == DCM_image_list[idx])
        {
            break;
        }
    }
    return idx;
}

/*************************************************************************
* FUNCTION
*   DCM_SearchImage
*
* DESCRIPTION
*   query how many images are dynamically lodable
*
* CALLS 
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static kal_uint32 DCM_SearchImage(void)
{
    kal_uint32  comp_pattern = 0;
    //kal_uint32  zimage_size = 0;
    kal_uint32  idx = 0;
    kal_uint8   *look_ptr = NULL;
    kal_uint8   *compare_ptr = NULL;
    kal_uint8   *end_ptr = NULL;
    kal_uint8   *ret_ptr = NULL;

#if (0)
#if defined(__ZIMAGE_SUPPORT__)
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
#endif /* !__ZIMAGE_SUPPORT__ */
#endif

    look_ptr = (kal_uint8 *)vivaInfo.dcmcmp_base;
    end_ptr = (kal_uint8 *)(custom_get_fat_addr()+INT_RetrieveRemappedFlashBaseAddr());

    compare_ptr = (kal_uint8 *)&comp_pattern;
    while(look_ptr < end_ptr)
    {
        /* try to find first key */
        for(idx = 0 ; idx < 4 ; idx++)
        {
            compare_ptr[idx] = look_ptr[idx];
        }
        if(DCMGR_KEY_ID_HEAD == comp_pattern)
        {
            ret_ptr = look_ptr;
            look_ptr += 4;
            /* try to find second key */
            for(idx = 0 ; idx < 4 ; idx++)
            {
                compare_ptr[idx] = look_ptr[idx];
            }
            if(DCMGR_KEY_ID_TAIL == comp_pattern)
            {
                return (kal_uint32)ret_ptr;
            }
        }
        else
        {
            look_ptr++;
        }
    };
    return DCMGR_INVALID_VAL;
}


/*************************************************************************
* FUNCTION
*   DCMGR_Init
*
* DESCRIPTION
*   
*
* CALLS 
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)

void DCMGR_init_phase1( void )
{
    kal_uint32 hdr_addr = 0;

    /* keep constant data from being removed by linker */
    dcmgr_code_ptr = &dcmgr_dynamic_code_hdr;

    hdr_addr = DCM_SearchImage();
    EXT_ASSERT( DCMGR_INVALID_VAL != hdr_addr, 0, 0, 0);

    dcmgr_code_ptr = (volatile dcmgr_comp_header_t const *)hdr_addr;
    dcmgr_comp_image_num = DCM_ImageAmount();
    if( dcmgr_code_ptr->dcmgr_img_num != dcmgr_comp_image_num )
    {
        /* number of image is not consistent between compressed file and primary ROM */
        EXT_ASSERT(0, dcmgr_code_ptr->dcmgr_img_num, dcmgr_comp_image_num, 0);
        return;
    }
    
    if (DCMGR_Init_Trunk_Information() == KAL_FALSE)
    {
        EXT_ASSERT(0, DCMGR_TRUNK_INFO_BUFF_SIZE, DYNAMIC_CODE_COMPRESS_NUM, 0);
        return;
    }

	DCM_Load(DYNAMIC_CODE_COMPRESS_MAUIINIT,NULL,NULL);
}

void DCMGR_init_phase2( void )
{
	init_mutex();
	
	DCM_Unload(DYNAMIC_CODE_COMPRESS_MAUIINIT);
	
	/* clear ZI region */
	INT_InitDynamicDCZIMMIpoolRegion();

	/* create ASM pool, because asm pool is used for MAUIINIT region before this time.*/
	mmi_frm_appmem_stage1_init();
}

void DCMGR_Init( void ){}


#else /* not defined __DCM_WITH_COMPRESSION_MAUI_INIT__ */

void DCMGR_init_phase1( void ){}

void DCMGR_init_phase2( void ){}

void DCMGR_Init( void )
{
    kal_uint32 hdr_addr = 0;

#if defined(__DCM_WITH_COMPRESSION__)
    /* keep constant data from being removed by linker */
    dcmgr_code_ptr = &dcmgr_dynamic_code_hdr;

    hdr_addr = DCM_SearchImage();
    EXT_ASSERT( DCMGR_INVALID_VAL != hdr_addr, 0, 0, 0);

    dcmgr_code_ptr = (volatile dcmgr_comp_header_t const *)hdr_addr;
    dcmgr_comp_image_num = DCM_ImageAmount();
    if( dcmgr_code_ptr->dcmgr_img_num != dcmgr_comp_image_num )
    {
        /* number of image is not consistent between compressed file and primary ROM */
        EXT_ASSERT(0, dcmgr_code_ptr->dcmgr_img_num, dcmgr_comp_image_num, 0);
        return;
    }
    
    if (DCMGR_Init_Trunk_Information() == KAL_FALSE)
    {
        EXT_ASSERT(0, DCMGR_TRUNK_INFO_BUFF_SIZE, DYNAMIC_CODE_COMPRESS_NUM, 0);
        return;
    }

#endif /* __DCM_WITH_COMPRESSION__ */

    //g_dcmgr_semid = kal_create_sem("DCMGR_load", 1);
    init_mutex();
}


#endif /* __DCM_WITH_COMPRESSION_MAUI_INIT__ */

#else /* __DCM_WITH_COMPRESSION__ */


/* 
 * Empty expoted fuction to make linker happy.
 */
void DCM_Load( kal_int32 dynamic_code_id, kal_uint32 **remaining_buf, kal_uint32 *buf_size ) { }

void DCM_Unload( kal_int32 dynamic_code_id ) { }

kal_bool DCM_Isloaded( kal_int32 dynamic_code_id ) { }

kal_bool DCM_IsAvailable( kal_int32 dynamic_code_id ) { }

void DCMGR_init_phase1( void ) { }

void DCMGR_init_phase2( void ) { }

void DCMGR_Init( void ) {}

#endif /* __DCM_WITH_COMPRESSION__ */



#else /* __MTK_TARGET__ */

/* 
 * Empty expoted fuction to make linker happy.
 */
void DCM_Load( kal_int32 dynamic_code_id, kal_uint32 **remaining_buf, kal_uint32 *buf_size ) { }

void DCM_Unload( kal_int32 dynamic_code_id ) { }

kal_bool DCM_Isloaded( kal_int32 dynamic_code_id ) { }

kal_bool DCM_IsAvailable( kal_int32 dynamic_code_id ) { }

void DCMGR_init_phase1( void ) { }

void DCMGR_init_phase2( void ) { }

void DCMGR_Init( void ) {}


#endif /* __MTK_TARGET__ */
