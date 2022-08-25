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
 *   VP8SwDecCustomize.c
 *
 * Project:
 * --------
 *	MTK
 *
 * Description:
 * ------------
 *   The API module C-functions of the VP8 Decoder
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
 ****************************************************************************/

#include "VP8SwDecCustomize.h" 
#if defined(__MTK_TARGET__)
#include "hal_custom_video_codec_if.h"
#else
#define mply_codec_custom_get_cust(argv1, argv2) 0
#define mply_codec_custom_set_cust(argv1, argv2, argv3)
#endif

#ifdef __VP8_DEC_SW_SUPPORT__ 
int SWVP8QuerySpeedyMode(int width, int height, int framerate, int bitrate)
{
    int mode, mode_custom, ret;
    unsigned int cust4;
    int width_pad =(width + VP8_PADDING + 31) & ~31;
    int height_pad =(height + VP8_PADDING + 31) & ~31;  
    if (width_pad*height_pad > SW_VP8_SPEEDY_BOUND_RES_2)
        mode = SW_VP8_SPEEDY_MODE_2;
    else if (width_pad*height_pad > SW_VP8_SPEEDY_BOUND_RES_1)
        mode = SW_VP8_SPEEDY_MODE_1;
    else
        mode = SW_VP8_SPEEDY_MODE_0;

    cust4 = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_VP8,1);		
    mode_custom = (int)(cust4 & 0xffffffff);

    if (mode == 2) ret = mode;
    else 
    {
        if (mode_custom >= 3) ret = mode;
        else ret = mode_custom;
    }
    
    return ret;
}

int SWVP8QueryDynamicSwitch(int width, int height, int framerate, int bitrate)
{ 
    unsigned int cust4, cust5;
    int mode_custom, switch_custom, ret;
    unsigned int cust32;
    int width_pad =(width + VP8_PADDING + 31) & ~31;
    int height_pad =(height + VP8_PADDING + 31) & ~31;  

    cust4 = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_VP8,1);	
    cust5 = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_VP8,2);	
    mode_custom = (int)(cust4 & 0xffffffff);
    switch_custom = (int)(cust5 & 0xffffffff);
	
    ret = 0;
    if (width_pad*height_pad > SW_VP8_SPEEDY_BOUND_RES_1)
    {
        if (mode_custom >= 0 && mode_custom <= 2) ret = 0;
        else ret = switch_custom; 
    }

    cust32 = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_VP8,5)&0xffffff00;
    if(ret > 0) cust32 |= 0x1;
    mply_codec_custom_set_cust(MPLY_CODEC_CUSTOM_FORMAT_VP8,5,cust32);

    return ret;  
}

int SWVP8QueryDynamicSwitchSetting(int width, int height, int framerate, int bitrate)
{
    unsigned int cust3;
    int custInt32;
    cust3 = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_VP8,0);	
    custInt32 = (int)(cust3 & 0xffffffff);	
    return custInt32;
}

int SWVP8QueryAsyncTolerance(int width, int height, int framerate, int bitrate)
{
    unsigned int cust;
    unsigned int diff_max;
    cust = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_VP8,6);
    diff_max = (unsigned int)(cust&0xffffffff);
    return diff_max;
}

int SWVP8QuerySpeedyModeOffset(int width, int height, int framerate, int bitrate)
{
    int mode_custom, mode;
    unsigned int cust4;
    int width_pad =(width + VP8_PADDING + 31) & ~31;
    int height_pad =(height + VP8_PADDING + 31) & ~31;  
    
    if (width_pad*height_pad > SW_VP8_SPEEDY_BOUND_RES_2)
        mode = (width_pad*height_pad > SW_VP8_SPEEDY_FVSS_RES) ? SW_VP8_SPEEDY_MODE_OFFSET_2 : SW_VP8_SPEEDY_MODE_OFFSET_0;
    else if (width_pad*height_pad > SW_VP8_SPEEDY_BOUND_RES_1)
        mode = (width_pad*height_pad > SW_VP8_SPEEDY_VSS_RES) ? SW_VP8_SPEEDY_MODE_OFFSET_4 : SW_VP8_SPEEDY_MODE_OFFSET_1;
    else
        mode = SW_VP8_SPEEDY_MODE_OFFSET_0;

    cust4 = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_VP8,1);		
    mode_custom = (int)(cust4 & 0xffffffff);
    if (mode_custom >= 1 && mode_custom <= 2)
    {
        cust4 = mply_codec_custom_get_cust(MPLY_CODEC_CUSTOM_FORMAT_VP8,9);		
        mode_custom = (int)(cust4 & 0xffffffff);    
        return mode_custom;
    }
    else return mode; 
}
#else // #ifndef __VP8_DEC_SW_SUPPORT__ 
int SWVP8QuerySpeedyMode(int width, int height, int framerate, int bitrate)
{
    return 0;
}
int SWVP8QuerySpeedyModeOffset(int width, int height, int framerate, int bitrate)
{
    return 0;
}
int SWVP8QueryDynamicSwitch(int width, int height, int framerate, int bitrate)
{
    return 0;
}
int SWVP8QueryDynamicSwitchSetting(int width, int height, int framerate, int bitrate)
{
    return 0;
}
int SWVP8QueryAsyncTolerance(int width, int height, int framerate, int bitrate)
{
    return 0;
}
#endif // #ifndef __VP8_DEC_SW_SUPPORT__ 
