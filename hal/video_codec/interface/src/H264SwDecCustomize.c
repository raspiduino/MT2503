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
 *   H264SwDecCustomize.c
 *
 * Project:
 * --------
 *	MTK
 *
 * Description:
 * ------------
 *   The API module C-functions of the H.264 Decoder
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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

#include "H264SwDecCustomize.h" 
#if defined(__MTK_TARGET__)
#include "hal_custom_video_codec_if.h"
#endif

int SWH264QuerySkipScalability()
{
#if defined(__H264_DEC_SW_SUPPORT__) && defined(__MTK_TARGET__)
    return mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_H264,6-3);	
#else
    return 0x00FA7001;
#endif
}

int SWH264QuerySpeedyMode(int width, int height, int isBaselineProfile)
{
#ifndef __H264_DEC_SW_SUPPORT__ 
    return SW_H264_SPEEDY_MODE_0;
#else // __H264_DEC_SW_SUPPORT__
    int mode, mode_custom, boundRes1, boundRes2, ret;
    unsigned int cust32;
#if !defined(__MTK_TARGET__)
    unsigned __int64     cust4;
#else
    unsigned long long   cust4;
#endif    

    if (isBaselineProfile)
    {
        boundRes1 = SW_H264_SPEEDY_BOUND_RES_1_BP;	
        boundRes2 = SW_H264_SPEEDY_BOUND_RES_2_BP;
    }
    else
    {
        boundRes1 = SW_H264_SPEEDY_BOUND_RES_1_MPHP;			
        boundRes2 = SW_H264_SPEEDY_BOUND_RES_2_MPHP;
    }

    if (width*height>boundRes2)
        mode = SW_H264_SPEEDY_MODE_2;
    else if (width*height>boundRes1)
        mode = SW_H264_SPEEDY_MODE_1;
    else
        mode = SW_H264_SPEEDY_MODE_0;
	
#if defined(__MTK_TARGET__)	
    cust4 = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_H264,4-3);		
#else
    cust4 = SW_H264_SPEEDY_MODE_0;
#endif    
    mode_custom = (int)(cust4 & 0xffffffff);

    if (mode == 2) 
    {        
        ret = mode; //return mode; 
    }
    else 
    {
        if (mode_custom >= 3) ret = mode;//return mode; 
        else ret = mode_custom;//return mode_custom; 
    }
    
#if defined(__MTK_TARGET__)
    cust32 = (unsigned int)(mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_H264,5)&0xffff00ff);
    if(ret>0) cust32 |= (ret<<8);
    mply_codec_custom_set_cust(MPLY_CODEC_CUSTOM_FORMAT_H264,5,cust32);
#endif    
    
    return ret;
#endif // __H264_DEC_SW_SUPPORT__
}

int SWH264QueryDynamicSwitch(int width, int height, int isBaselineProfile)
{ 
#ifdef __H264_DEC_SW_SUPPORT__    
#if !defined(__MTK_TARGET__)
    unsigned __int64     cust4, cust5;
#else
    unsigned long long   cust4, cust5;
#endif      
    int mode_custom, switch_custom, boundRes1, ret;
    unsigned int cust32;
#if defined(__MTK_TARGET__)    
    cust4 = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_H264,4-3);	
    cust5 = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_H264,5-3);	
#else
    cust4 = 0;	
    cust5 = 0;	
#endif    
    mode_custom = (int)(cust4 & 0xffffffff);
    switch_custom = (int)(cust5 & 0xffffffff);
	
    if (isBaselineProfile) boundRes1 = SW_H264_SPEEDY_BOUND_RES_1_BP;	
    else                   boundRes1 = SW_H264_SPEEDY_BOUND_RES_1_MPHP;			
	
    if (width*height > boundRes1)
    {
        if (mode_custom >= 0 && mode_custom <= 2) ret = 0;//return 0;
        else ret = switch_custom; //return switch_custom;	
    }
    else  
        ret = 0;//return 0;	   
#if defined(__MTK_TARGET__)
    cust32 = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_H264,5)&0xffffff00;
    if(ret > 0) cust32 |= 0x1;
    mply_codec_custom_set_cust(MPLY_CODEC_CUSTOM_FORMAT_H264,5,cust32);
#endif        

    return ret;  
#else // __H264_DEC_SW_SUPPORT__
    return 0;	             
#endif // __H264_DEC_SW_SUPPORT__

}

void SWH264QueryDynamicSwitchSetting(int *p01)
{
#ifndef __H264_DEC_SW_SUPPORT__     
    *p01 = 0;
#else // __H264_DEC_SW_SUPPORT__  
#if !defined(__MTK_TARGET__)
    unsigned __int64     cust3;
#else
    unsigned long long   cust3;
#endif    
    int custInt32;
#if defined(__MTK_TARGET__)   
    cust3 = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_H264,3-3);	
#else
    cust3 = 0;
#endif  
    custInt32 = (int)(cust3 & 0xffffffff);	
#ifdef SWITCHQTY12	
    *p01 = custInt32;
#else	
    *p01 = (custInt32 >> 16) & 0xff; // bound01: 23:16
#endif
#endif // __H264_DEC_SW_SUPPORT__
}


void SWH264QueryConcealSetting(unsigned int *mode)
{
#ifndef __H264_DEC_SW_SUPPORT__  
    *mode = 1;
#else // __H264_DEC_SW_SUPPORT__
#if !defined(__MTK_TARGET__)
    unsigned __int64     cust5;
#else
    unsigned long long   cust5;
#endif   	
    int switch_custom;
#if defined(__MTK_TARGET__)     
    cust5 = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_H264,9);		
#else
    cust5 = 1;
#endif    
    switch_custom = (int)(cust5 & 0xffffffff);
    if (switch_custom >= 3) *mode = SW_H264_CONCEAL_MODE_SETTING;
    else *mode = switch_custom;
#endif // __H264_DEC_SW_SUPPORT__
}	 

int SWH264QueryAsyncTolerance(int width, int height, int fps, int bitrate)
{
#ifndef __H264_DEC_SW_SUPPORT__
    return 250;
#else    
    unsigned int cust;
    unsigned int diff_max;
#if defined(__MTK_TARGET__)    
    cust = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_H264,6);
#else
    cust = 250;
#endif
    diff_max = (unsigned int)(cust&0xffffffff);
    return diff_max;
#endif // __H264_DEC_SW_SUPPORT__
}

int SWH264QuerySpeedyModeOffset(int offset)
{
#ifndef __H264_DEC_SW_SUPPORT__ 
    return offset;
#else // __H264_DEC_SW_SUPPORT__
    int mode_custom;
#if !defined(__MTK_TARGET__)
    unsigned __int64     cust4;
#else
    unsigned long long   cust4;
#endif    

#if defined(__MTK_TARGET__)	
    cust4 = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_H264,4-3);		
#else
    cust4 = SW_H264_SPEEDY_MODE_0;
#endif    
    mode_custom = (int)(cust4 & 0xffffffff);

    if (mode_custom == 1) return 2; 
    else return offset; 

#endif // __H264_DEC_SW_SUPPORT__
}

#ifdef __CONTOUR_IMPROVEMENT_SUPPORT__
int SWH264PredictDecTime(unsigned int w, unsigned int h, unsigned int fps, unsigned int bitrate)
{
    int dec_time;    
    if(w<=0 || h<=0 || bitrate<=0) return -1;   
    // use 30fps to estimate decode time per frame
    dec_time = 10000;    
    return dec_time;
}
#endif /* __CONTOUR_IMPROVEMENT_SUPPORT__ */
