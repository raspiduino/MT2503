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
 *   MP4SwDecCustomize.c
 *
 * Project:
 * --------
 *	MTK
 *
 * Description:
 * ------------
 *   The API module C-functions of the MPEG4 Decoder
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
 ****************************************************************************/
#include "drv_features_vcodec.h"
//#include "kal_general_types.h"
#include "mp4dec_basetype.h"
#include "MP4SwDecCustomize.h" 
#if defined(__MTK_TARGET__)
//#include "custom_sw_video.h"
#include "hal_custom_video_codec_if.h"
//#include "hal_custom_video.h"
#endif

/**
 * SWMP4QuerySpeedyMode
 * @brief Determine initial decode mode based on video information 
 *
 * @param width number of pixels in a row
 * @param height number of pixels in a column
 * @param fps video frame rate x 100 (ex: 2997 = 29.97 fps)
 * @param bitrate video bit rate (in bps)
 *
 * @retval decode mode
 */
int SWMP4QuerySpeedyMode(int width, int height, int fps, int bitrate)
{
#ifdef SW_MP4_DEC_SUPPORT
    uint64 cust;
    int mode,ret;
    unsigned int cust32;

    #if defined(__MTK_TARGET__) 
    cust = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_MP4,4-3);
    #else
    cust = SW_MP4_SPEEDY_MODE_0;
    #endif
    mode = (int)(cust & 0xffffffff);
    if (width*height>SW_MP4_SPEEDY_BOUND_RES_3)
        ret = ((mode!=SW_MP4_SPEEDY_MODE_3) ? SW_MP4_SPEEDY_MODE_3 : (mode));
    else if (width*height>SW_MP4_SPEEDY_BOUND_RES_2)
        ret = ((mode>SW_MP4_SPEEDY_MODE_3 || mode<SW_MP4_SPEEDY_MODE_2) ? SW_MP4_SPEEDY_MODE_2 : (mode));
    else if (width*height>SW_MP4_SPEEDY_BOUND_RES_1)
        ret = ((mode>SW_MP4_SPEEDY_MODE_3) ? SW_MP4_SPEEDY_MODE_1 : (mode));
    else
        ret = ((mode>SW_MP4_SPEEDY_MODE_3) ? SW_MP4_SPEEDY_MODE_0 : (mode));
    #if defined(__MTK_TARGET__)
    cust32 = (unsigned int)(mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_MP4,5)&0xffff00ff);
    if(ret>0) cust32 |= (ret<<8);
    mply_codec_custom_set_cust(MPLY_CODEC_CUSTOM_FORMAT_MP4,5,cust32);
    #endif
    return ret;
#else
    return SW_MP4_SPEEDY_MODE_0;
#endif /* MP4 */
}

int SWMP4QueryDynamicSwitch(int width, int height, int fps, int bitrate)
{
#ifdef SW_MP4_DEC_SUPPORT
    uint64 cust;
    int mode,dynamic,ret;
    unsigned int cust32;

    #if defined(__MTK_TARGET__) 
    cust = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_MP4,4-3);
    #else
    cust = 0;
    #endif
    mode = (int)(cust & 0xffffffff);
    #if defined(__MTK_TARGET__) 
    cust = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_MP4,5-3);
    #else
    cust = 0;
    #endif
    dynamic = (int)(cust & 0xffffffff);
    if(mode <= SW_MP4_SPEEDY_MODE_3) ret = 0;
    else if(dynamic == 0) ret = 0;
    else if(width*height > SW_MP4_SPEEDY_DYNAMIC_SWITCH_BOUND_RES_3) ret = 3;
    else if(width*height > SW_MP4_SPEEDY_DYNAMIC_SWITCH_BOUND_RES_2) ret = 2;
    else ret = 1;
    #if defined(__MTK_TARGET__)
    cust32 = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_MP4,5)&0xffffff00;
    if(ret > 0) cust32 |= 0x1;
    mply_codec_custom_set_cust(MPLY_CODEC_CUSTOM_FORMAT_MP4,5,cust32);
    #endif
    return ret;
#else
    return 0;
#endif /* MP4 */
}

unsigned int SWMP4QueryDynamicSwitchSetting(int width, int height, int fps, int bitrate)
{
#ifdef SW_MP4_DEC_SUPPORT
    uint64 cust;
    unsigned int percent;

    #if defined(__MTK_TARGET__) 
    cust = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_MP4,3-3);
    #else
    cust = 0;
    #endif
    percent = (unsigned int)(cust & 0xffffffff);
    if(width*height <= SW_MP4_SPEEDY_DYNAMIC_SWITCH_BOUND_RES_1)
    {
        unsigned int p01,p02,p12,p23;
        
        p23 = (percent>>24)&0xff;
        p01 = (percent>>16)&0xff;
        p02 = (percent>>8)&0xff;
        p12 = percent&0xff;
        p01 /= 2; p02 /= 2; p12 /= 2;
        percent = (p23<<24) | (p01<<16) | (p02<<8) | p12;
    }
    return percent;
#else
    return 0;
#endif /* MP4 */
}

unsigned int SWMP4QuerySkipScalability(int width, int height, int fps, int bitrate)
{
#ifdef SW_MP4_DEC_SUPPORT
    uint64 cust;
    unsigned int skip_thr;
    #if defined(__MTK_TARGET__)    
    cust = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_MP4,7-3);
    #else
    cust = 151;
    #endif
    skip_thr = (unsigned int)(cust&0xffffffff);
    //if(skip_thr > 1) return 2;
    return skip_thr;
#else
    return 0;
#endif /* MP4 */
}

unsigned int SWMP4QuerySkipBScalability()
{
#ifdef SW_MP4_DEC_SUPPORT
    uint64 cust;
    unsigned int skipB;
    #if defined(__MTK_TARGET__)    
    cust = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_MP4,3);
    #else
    cust = 0;
    #endif
    skipB = (unsigned int)(cust&0xffffffff);
    return skipB;
#else
    return 0;
#endif /* MP4 */
}

int SWMP4QueryAsyncTolerance(int width, int height, int fps, int bitrate)
{
#ifdef SW_MP4_DEC_SUPPORT
    uint64 cust;
    unsigned int diff_max;
    #if defined(__MTK_TARGET__)    
    cust = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_MP4,6);
    #else
    cust = 250;
    #endif
    diff_max = (unsigned int)(cust&0xffffffff);
    return diff_max;
#else
    return 250;
#endif /* MP4 */
}

#ifdef __CONTOUR_IMPROVEMENT_SUPPORT__
int 
SWMP4PredictDecTime(unsigned int w, unsigned int h, unsigned int fps, unsigned int bitrate)
{
    int dec_time;
    
    if(w<=0 || h<=0 || bitrate<=0) return -1;
    
    // use 30fps to estimate decode time per frame
    if(w*h <= 176*144)
    {
        if(bitrate < 200) dec_time = 10;
        else if(bitrate < 400) dec_time = 12;
        else if(bitrate < 600) dec_time = 14;
        else if(bitrate < 800) dec_time = 16;
        else 
        {
            dec_time = 20;
            if(bitrate>1024) dec_time += (bitrate-1024+99)/100;
        }
    }
    else if(w*h <= 320*240)
    {
        if(bitrate < 150) dec_time = 18;
        else if(bitrate < 300) dec_time = 23;
        else if(bitrate < 450) dec_time = 28;
        else
        {
            dec_time = 33;
            if(bitrate>512) dec_time += (bitrate-512+31)/32;
        }
    }
    else if(w*h <= 352*288)
    {
        if(bitrate < 100) dec_time = 18;
        else if(bitrate < 200) dec_time = 22;
        else if(bitrate < 300) dec_time = 26;
        else if(bitrate < 400) dec_time = 30;
        else
        {
            dec_time = 33;
            if(bitrate>450) dec_time += (bitrate-450+24)/25;
        }
    }
    else
    {
        if(bitrate < 100) dec_time = 18;
        else if(bitrate < 200) dec_time = 22;
        else if(bitrate < 300) dec_time = 26;
        else if(bitrate < 400) dec_time = 30;
        else dec_time = 30+(bitrate-400)/25;
        
        dec_time = dec_time*(w*h)/(352*288);
    }
    
    // adjust decode time if not 30fps
    if(fps>0 && fps<30)
    {
        if(fps > 15) dec_time += (dec_time*(30-fps)*(30-fps)/fps/fps);
        else dec_time = dec_time*30/fps;
    }
    
    return dec_time;
}
#endif /* CONTOUR_SUPPORT */
