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
 *   vcodec_dcm.c
 *
 * Project:
 * --------
 *	MTK
 *
 * Description:
 * ------------
 *   Declare variables for dcm supporting 
 *
 * Author:
 * -------
 * -------
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

#if defined(__MTK_TARGET__)
#include "dcmgr.h"

    #if defined(__DCM_WITH_COMPRESSION__)
        #ifdef __H264_DEC_SW_SUPPORT__ 
            const kal_uint32 g_h264dec_dcm_id = DYNAMIC_CODE_COMPRESS_H264DEC_C;
        #else
            const kal_uint32 g_h264dec_dcm_id = 0;
        #endif
        #ifdef __MPEG4_DEC_SW_SUPPORT__
            #ifdef __MP4_DEC_SW_SUPPORT_ASP__
                const kal_uint32 g_mp4dec_dcm_id = DYNAMIC_CODE_COMPRESS_MP4ASPDEC;
            #else
                const kal_uint32 g_mp4dec_dcm_id = DYNAMIC_CODE_COMPRESS_MP4DEC_C;
            #endif
        #else
            const kal_uint32 g_mp4dec_dcm_id = 0;
        #endif
        #ifdef __MPEG4_ENC_SW_SUPPORT__
            const kal_uint32 g_mp4enc_dcm_id = DYNAMIC_CODE_COMPRESS_MP4ENC_C;
        #else
            const kal_uint32 g_mp4enc_dcm_id = 0;
        #endif
        #ifdef __VP8_DEC_SW_SUPPORT__ 
            const kal_uint32 g_vp8dec_dcm_id = DYNAMIC_CODE_COMPRESS_VP8DEC;
        #else
            const kal_uint32 g_vp8dec_dcm_id = 0;
        #endif
    #else
        #ifdef __H264_DEC_SW_SUPPORT__ 
            const kal_uint32 g_h264dec_dcm_id = 0;
        #endif
        #ifdef __MPEG4_DEC_SW_SUPPORT__
            const kal_uint32 g_mp4dec_dcm_id = 0;
        #endif
        #ifdef __MPEG4_ENC_SW_SUPPORT__
            const kal_uint32 g_mp4enc_dcm_id = 0;
        #endif
        #ifdef __VP8_DEC_SW_SUPPORT__ 
            const kal_uint32 g_vp8dec_dcm_id = 0;
        #endif
    #endif

#else /* __MTK_TARGET__ */

    #ifdef __H264_DEC_SW_SUPPORT__ 
        const unsigned int g_h264dec_dcm_id = 0;
    #endif
    #ifdef __MPEG4_DEC_SW_SUPPORT__
        const unsigned int g_mp4dec_dcm_id = 0;
    #endif
    #ifdef __MPEG4_ENC_SW_SUPPORT__
        const unsigned int g_mp4enc_dcm_id = 0;
    #endif
    #ifdef __VP8_DEC_SW_SUPPORT__ 
        const unsigned int g_vp8dec_dcm_id = 0;
    #endif

#endif /* __MTK_TARGET__ */
