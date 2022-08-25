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
 *   vcodec_demand_page.c
 *
 * Project:
 * --------
 *	MTK
 *
 * Description:
 * ------------
 *   Declare variables for demand page supporting 
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 ****************************************************************************/

#if (defined(MT6276) || defined(MT6256))&& defined(__MTK_TARGET__) && defined(__DEMAND_PAGING__)
    /****************************************************************************/
    /* The address and length decidec in link time of H264DEC                   */
    /****************************************************************************/
    #ifdef __H264_DEC_SW_SUPPORT__ 
        extern unsigned int Image$$DEMAND_PAGING_ROM_VIDEO_H264DEC$$Base;
        extern unsigned int Image$$DEMAND_PAGING_ROM_VIDEO_H264DEC$$Length;
        const unsigned int h264dec_demand_page_address = (unsigned int)&Image$$DEMAND_PAGING_ROM_VIDEO_H264DEC$$Base;
        const unsigned int h264dec_demand_page_length  = (unsigned int)&Image$$DEMAND_PAGING_ROM_VIDEO_H264DEC$$Length;
    #else
        const unsigned int h264dec_demand_page_address = 0;
        const unsigned int h264dec_demand_page_length  = 0;  
    #endif
    /****************************************************************************/
    /* The address and length decidec in link time of H264ENC                   */
    /****************************************************************************/
    #ifdef __H264_ENC_SW_SUPPORT__ 
        extern unsigned int Image$$DEMAND_PAGING_ROM_VIDEO_H264ENC$$Base;
        extern unsigned int Image$$DEMAND_PAGING_ROM_VIDEO_H264ENC$$Length;
        const unsigned int h264enc_demand_page_address = (unsigned int)&Image$$DEMAND_PAGING_ROM_VIDEO_H264ENC$$Base;
        const unsigned int h264enc_demand_page_length  = (unsigned int)&Image$$DEMAND_PAGING_ROM_VIDEO_H264ENC$$Length;
    #else
        const unsigned int h264enc_demand_page_address = 0;
        const unsigned int h264enc_demand_page_length  = 0;  
    #endif
    /****************************************************************************/
    /* The address and length decidec in link time of MP4DEC                   */
    /****************************************************************************/
    #ifdef __MPEG4_DEC_SW_SUPPORT__
        extern unsigned int Image$$DEMAND_PAGING_ROM_VIDEO_MP4DEC$$Base;
        extern unsigned int Image$$DEMAND_PAGING_ROM_VIDEO_MP4DEC$$Length;
        extern unsigned int Image$$DEMAND_PAGING_ROM_VIDEO_MP4COM$$Base;
        extern unsigned int Image$$DEMAND_PAGING_ROM_VIDEO_MP4COM$$Length;
        const unsigned int mp4dec_demand_page_address = (unsigned int)&Image$$DEMAND_PAGING_ROM_VIDEO_MP4DEC$$Base;
        const unsigned int mp4dec_demand_page_length  = (unsigned int)&Image$$DEMAND_PAGING_ROM_VIDEO_MP4DEC$$Length;
        const unsigned int mp4com_demand_page_address = (unsigned int)&Image$$DEMAND_PAGING_ROM_VIDEO_MP4COM$$Base;
        const unsigned int mp4com_demand_page_length  = (unsigned int)&Image$$DEMAND_PAGING_ROM_VIDEO_MP4COM$$Length;
    #else
        const unsigned int mp4dec_demand_page_address = 0;
        const unsigned int mp4dec_demand_page_length  = 0;
        const unsigned int mp4com_demand_page_address = 0;
        const unsigned int mp4com_demand_page_length  = 0;
    #endif
    /****************************************************************************/
    /* The address and length decidec in link time of MP4ENC                   */
    /****************************************************************************/
    #ifdef __MPEG4_ENC_SW_SUPPORT__
        extern unsigned int Image$$DEMAND_PAGING_ROM_VIDEO_MP4ENC$$Base;
        extern unsigned int Image$$DEMAND_PAGING_ROM_VIDEO_MP4ENC$$Length;
        const unsigned int mp4enc_demand_page_address = (unsigned int)&Image$$DEMAND_PAGING_ROM_VIDEO_MP4ENC$$Base;
        const unsigned int mp4enc_demand_page_length  = (unsigned int)&Image$$DEMAND_PAGING_ROM_VIDEO_MP4ENC$$Length;
    #else
        const unsigned int mp4enc_demand_page_address = 0;
        const unsigned int mp4enc_demand_page_length  = 0;            
    #endif
    
    #ifdef __VIDEO_VT_SUPPORT__ 
        /****************************************************************************/
        /* The address and length decidec in link time of UVTDEC                   */
        /****************************************************************************/
        #ifdef __MPEG4_DEC_SW_SUPPORT__
            extern unsigned int Image$$DEMAND_PAGING_ROM_VIDEO_UVTDEC$$Base;
            extern unsigned int Image$$DEMAND_PAGING_ROM_VIDEO_UVTDEC$$Length;
            const unsigned int uvtdec_demand_page_address = (unsigned int)&Image$$DEMAND_PAGING_ROM_VIDEO_UVTDEC$$Base;
            const unsigned int uvtdec_demand_page_length  = (unsigned int)&Image$$DEMAND_PAGING_ROM_VIDEO_UVTDEC$$Length;
        #else
            const unsigned int uvtdec_demand_page_address = 0;
            const unsigned int uvtdec_demand_page_length  = 0;    
        #endif
        /****************************************************************************/
        /* The address and length decidec in link time of UVTENC                   */
        /****************************************************************************/
        #ifdef __MPEG4_ENC_SW_SUPPORT__
            extern unsigned int Image$$DEMAND_PAGING_ROM_VIDEO_UVTENC$$Base;
            extern unsigned int Image$$DEMAND_PAGING_ROM_VIDEO_UVTENC$$Length;
            const unsigned int uvtenc_demand_page_address = (unsigned int)&Image$$DEMAND_PAGING_ROM_VIDEO_UVTENC$$Base;
            const unsigned int uvtenc_demand_page_length  = (unsigned int)&Image$$DEMAND_PAGING_ROM_VIDEO_UVTENC$$Length;   
        #else
            const unsigned int uvtenc_demand_page_address = 0;
            const unsigned int uvtenc_demand_page_length  = 0;    
        #endif
    #else
        const unsigned int uvtdec_demand_page_address = 0;
        const unsigned int uvtdec_demand_page_length  = 0;
        const unsigned int uvtenc_demand_page_address = 0;
        const unsigned int uvtenc_demand_page_length  = 0;            
    #endif //__VIDEO_VT_SUPPORT__
    /****************************************************************************/
    /* The address and length decidec in link time of RMDEC                   */
    /****************************************************************************/
    #ifdef __RV_DEC_SW_SUPPORT__
        extern unsigned int Image$$DEMAND_PAGING_ROM_VIDEO_RMDEC$$Base;
        extern unsigned int Image$$DEMAND_PAGING_ROM_VIDEO_RMDEC$$Length;
        const unsigned int rmdec_demand_page_address = (unsigned int)&Image$$DEMAND_PAGING_ROM_VIDEO_RMDEC$$Base;
        const unsigned int rmdec_demand_page_length  = (unsigned int)&Image$$DEMAND_PAGING_ROM_VIDEO_RMDEC$$Length;
    #else
        const unsigned int rmdec_demand_page_address = 0;
        const unsigned int rmdec_demand_page_length  = 0;    
    #endif
#else
    const unsigned int h264dec_demand_page_address = 0;
    const unsigned int h264dec_demand_page_length  = 0;  
    const unsigned int h264enc_demand_page_address = 0;
    const unsigned int h264enc_demand_page_length  = 0;  
    const unsigned int mp4dec_demand_page_address = 0;
    const unsigned int mp4dec_demand_page_length  = 0;
    const unsigned int mp4enc_demand_page_address = 0;
    const unsigned int mp4enc_demand_page_length  = 0;   
    const unsigned int uvtdec_demand_page_address = 0;
    const unsigned int uvtdec_demand_page_length  = 0;
    const unsigned int uvtenc_demand_page_address = 0;
    const unsigned int uvtenc_demand_page_length  = 0;
    const unsigned int mp4com_demand_page_address = 0;
    const unsigned int mp4com_demand_page_length  = 0;
    const unsigned int rmdec_demand_page_address = 0;
    const unsigned int rmdec_demand_page_length  = 0;
#endif
