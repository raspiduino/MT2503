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
 *   MP4SwDecMem.h
 *
 * Project:
 * --------
 *	MTK
 *
 * Description:
 * ------------
 *   The API module user interface of the Decoder.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef MP4SWDECMEM_H
#define MP4SWDECMEM_H

#ifdef __cplusplus
extern "C"
    {
#endif

#include "drv_features_vcodec.h"



#if (defined(MT6236) || defined(MT6236B)) && defined(MP4_FRAME_BUFFER_ALLOCATED_BY_CODEC)
#define MP4SwDecExtSize_128x96_SP (38+2+2)*1024
#define MP4SwDecExtSize_176x144_SP (75+2+4)*1024
#define MP4SwDecExtSize_320x240_SP (230+5+12)*1024
#define MP4SwDecExtSize_400x240_SP (288+7+14)*1024
#define MP4SwDecExtSize_352x288_SP (300+7+15)*1024
#define MP4SwDecExtSize_432x240_SP (320+7+16)*1024
#define MP4SwDecExtSize_480x320_SP (460+10+23)*1024
#define MP4SwDecExtSize_640x368_SP (700+15+35)*1024
#define MP4SwDecExtSize_640x480_SP (920+19+45)*1024
#define MP4SwDecExtSize_720x480_SP (1024+22+51)*1024
#define MP4SwDecExtSize_800x480_SP (1152+26+56)*1024
#define MP4SwDecExtSize_848x480_SP (1220+26+60)*1024
#define MP4SwDecExtSize_864x480_SP (1220+26+61)*1024
#define MP4SwDecExtSize_720x576_SP (1220+26+61)*1024
#define MP4SwDecExtSize_800x608_SP (1440+30+71)*1024
#define MP4SwDecExtSize_1024x768_SP (2350+48+114)*1024
#define MP4SwDecExtSize_1280x720_SP (2750+57+134)*1024
#define MP4SwDecExtSize_1280x960_SP (3650+75+179)*1024
#define MP4SwDecExtSize_1280x1024_SP (3900+80+190)*1024
#define MP4SwDecExtSize_1408x1152_SP (4800+99+236)*1024
#define MP4SwDecExtSize_1600x1200_SP (5760+118+279)*1024
#define MP4SwDecExtSize_1920x1088_SP (6250+128+303)*1024

#define MP4SwDecExtSize_128x96_ASP 4*38*1024
#define MP4SwDecExtSize_176x144_ASP 4*75*1024
#define MP4SwDecExtSize_320x240_ASP 4*230*1024
#define MP4SwDecExtSize_400x240_ASP 4*288*1024
#define MP4SwDecExtSize_352x288_ASP 4*300*1024
#define MP4SwDecExtSize_432x240_ASP 4*320*1024
#define MP4SwDecExtSize_480x320_ASP 4*460*1024
#define MP4SwDecExtSize_640x368_ASP 4*700*1024
#define MP4SwDecExtSize_640x480_ASP 4*920*1024
#define MP4SwDecExtSize_720x480_ASP 4*1024*1024
#define MP4SwDecExtSize_800x480_ASP 4*1152*1024
#define MP4SwDecExtSize_848x480_ASP 4*1220*1024
#define MP4SwDecExtSize_864x480_ASP 4*1220*1024
#define MP4SwDecExtSize_720x576_ASP 4*1220*1024
#define MP4SwDecExtSize_800x608_ASP 4*1440*1024
#define MP4SwDecExtSize_1024x768_ASP 4*2350*1024
#define MP4SwDecExtSize_1280x720_ASP 4*2750*1024
#define MP4SwDecExtSize_1280x960_ASP 4*3650*1024
#define MP4SwDecExtSize_1280x1024_ASP 4*3900*1024
#define MP4SwDecExtSize_1408x1152_ASP 4*4800*1024
#define MP4SwDecExtSize_1600x1200_ASP 4*5760*1024
#define MP4SwDecExtSize_1920x1088_ASP 4*6250*1024

#define MP4SwDecIntraModeExtSize_128x96_SP (38+2+2)*1024
#define MP4SwDecIntraModeExtSize_176x144_SP (75+2+4)*1024
#define MP4SwDecIntraModeExtSize_320x240_SP (230+5+12)*1024
#define MP4SwDecIntraModeExtSize_400x240_SP (288+7+14)*1024
#define MP4SwDecIntraModeExtSize_352x288_SP (300+7+15)*1024
#define MP4SwDecIntraModeExtSize_432x240_SP (320+7+16)*1024
#define MP4SwDecIntraModeExtSize_480x320_SP (460+10+23)*1024
#define MP4SwDecIntraModeExtSize_640x368_SP (700+15+35)*1024
#define MP4SwDecIntraModeExtSize_640x480_SP (920+19+45)*1024
#define MP4SwDecIntraModeExtSize_720x480_SP (1024+22+51)*1024
#define MP4SwDecIntraModeExtSize_800x480_SP (1152+26+56)*1024
#define MP4SwDecIntraModeExtSize_848x480_SP (1220+26+60)*1024
#define MP4SwDecIntraModeExtSize_864x480_SP (1220+26+61)*1024
#define MP4SwDecIntraModeExtSize_720x576_SP (1220+26+61)*1024
#define MP4SwDecIntraModeExtSize_800x608_SP (1440+30+71)*1024
#define MP4SwDecIntraModeExtSize_1024x768_SP (2350+48+114)*1024
#define MP4SwDecIntraModeExtSize_1280x720_SP (2750+57+134)*1024
#define MP4SwDecIntraModeExtSize_1280x960_SP (3650+75+179)*1024
#define MP4SwDecIntraModeExtSize_1280x1024_SP (3900+80+190)*1024
#define MP4SwDecIntraModeExtSize_1408x1152_SP (4800+99+236)*1024
#define MP4SwDecIntraModeExtSize_1600x1200_SP (5760+118+279)*1024
#define MP4SwDecIntraModeExtSize_1920x1088_SP (6250+128+303)*1024

#define MP4SwDecIntraModeExtSize_128x96_ASP (38+2+2)*1024
#define MP4SwDecIntraModeExtSize_176x144_ASP (75+2+4)*1024
#define MP4SwDecIntraModeExtSize_320x240_ASP (230+5+12)*1024
#define MP4SwDecIntraModeExtSize_400x240_ASP (288+7+14)*1024
#define MP4SwDecIntraModeExtSize_352x288_ASP (300+7+15)*1024
#define MP4SwDecIntraModeExtSize_432x240_ASP (320+7+16)*1024
#define MP4SwDecIntraModeExtSize_480x320_ASP (460+10+23)*1024
#define MP4SwDecIntraModeExtSize_640x368_ASP (700+15+35)*1024
#define MP4SwDecIntraModeExtSize_640x480_ASP (920+19+45)*1024
#define MP4SwDecIntraModeExtSize_720x480_ASP (1024+22+51)*1024
#define MP4SwDecIntraModeExtSize_800x480_ASP (1152+26+56)*1024
#define MP4SwDecIntraModeExtSize_848x480_ASP (1220+26+60)*1024
#define MP4SwDecIntraModeExtSize_864x480_ASP (1220+26+61)*1024
#define MP4SwDecIntraModeExtSize_720x576_ASP (1220+26+61)*1024
#define MP4SwDecIntraModeExtSize_800x608_ASP (1440+30+71)*1024
#define MP4SwDecIntraModeExtSize_1024x768_ASP (2350+48+114)*1024
#define MP4SwDecIntraModeExtSize_1280x720_ASP (2750+57+134)*1024
#define MP4SwDecIntraModeExtSize_1280x960_ASP (3650+75+179)*1024
#define MP4SwDecIntraModeExtSize_1280x1024_ASP (3900+80+190)*1024
#define MP4SwDecIntraModeExtSize_1408x1152_ASP (4800+99+236)*1024
#define MP4SwDecIntraModeExtSize_1600x1200_ASP (5760+118+279)*1024
#define MP4SwDecIntraModeExtSize_1920x1088_ASP (6250+128+303)*1024
#elif defined(MT6276) && defined(DUO_MP4_VIDEO_SUPPORT)
#define MP4SwDecExtSize_128x96_SP (110+2+2)*1024
#define MP4SwDecExtSize_176x144_SP (190+2+4)*1024
#define MP4SwDecExtSize_320x240_SP (500+5+12)*1024
#define MP4SwDecExtSize_400x240_SP (620+7+14)*1024
#define MP4SwDecExtSize_352x288_SP (650+7+15)*1024
#define MP4SwDecExtSize_432x240_SP (660+7+16)*1024
#define MP4SwDecExtSize_480x320_SP (970+10+23)*1024
#define MP4SwDecExtSize_640x368_SP (1480+15+35)*1024
#define MP4SwDecExtSize_640x480_SP (1920+19+45)*1024
#define MP4SwDecExtSize_720x480_SP (2160+22+51)*1024
#define MP4SwDecExtSize_800x480_SP (2408+26+56)*1024
#define MP4SwDecExtSize_848x480_SP (2550+26+60)*1024
#define MP4SwDecExtSize_864x480_SP (2550+26+61)*1024
#define MP4SwDecExtSize_720x576_SP (2600+26+61)*1024
#define MP4SwDecExtSize_800x608_SP (3046+30+71)*1024
#define MP4SwDecExtSize_1024x768_SP (4900+48+114)*1024
#define MP4SwDecExtSize_1280x720_SP (5750+57+134)*1024
#define MP4SwDecExtSize_1280x960_SP (7660+75+179)*1024
#define MP4SwDecExtSize_1280x1024_SP (8160+80+190)*1024
#define MP4SwDecExtSize_1408x1152_SP (10100+99+236)*1024
#define MP4SwDecExtSize_1600x1200_SP (11950+118+279)*1024
#define MP4SwDecExtSize_1920x1088_SP (13000+128+303)*1024

#define MP4SwDecExtSize_128x96_ASP 4*110*1024
#define MP4SwDecExtSize_176x144_ASP 4*190*1024
#define MP4SwDecExtSize_320x240_ASP 4*500*1024
#define MP4SwDecExtSize_400x240_ASP 4*620*1024
#define MP4SwDecExtSize_352x288_ASP 4*650*1024
#define MP4SwDecExtSize_432x240_ASP 4*660*1024
#define MP4SwDecExtSize_480x320_ASP 4*970*1024
#define MP4SwDecExtSize_640x368_ASP 4*1480*1024
#define MP4SwDecExtSize_640x480_ASP 4*1920*1024
#define MP4SwDecExtSize_720x480_ASP 4*2160*1024
#define MP4SwDecExtSize_800x480_ASP 4*2408*1024
#define MP4SwDecExtSize_848x480_ASP 4*2550*1024
#define MP4SwDecExtSize_864x480_ASP 4*2550*1024
#define MP4SwDecExtSize_720x576_ASP 4*2600*1024
#define MP4SwDecExtSize_800x608_ASP 4*3046*1024
#define MP4SwDecExtSize_1024x768_ASP 4*4900*1024
#define MP4SwDecExtSize_1280x720_ASP 4*5750*1024
#define MP4SwDecExtSize_1280x960_ASP 4*7660*1024
#define MP4SwDecExtSize_1280x1024_ASP 4*8160*1024
#define MP4SwDecExtSize_1408x1152_ASP 4*10100*1024
#define MP4SwDecExtSize_1600x1200_ASP 4*11950*1024
#define MP4SwDecExtSize_1920x1088_ASP 4*13000*1024

#define MP4SwDecIntraModeExtSize_128x96_SP (110+2+2)*1024
#define MP4SwDecIntraModeExtSize_176x144_SP (190+2+4)*1024
#define MP4SwDecIntraModeExtSize_320x240_SP (500+5+12)*1024
#define MP4SwDecIntraModeExtSize_400x240_SP (620+7+14)*1024
#define MP4SwDecIntraModeExtSize_352x288_SP (650+7+15)*1024
#define MP4SwDecIntraModeExtSize_432x240_SP (660+7+16)*1024
#define MP4SwDecIntraModeExtSize_480x320_SP (970+10+23)*1024
#define MP4SwDecIntraModeExtSize_640x368_SP (1480+15+35)*1024
#define MP4SwDecIntraModeExtSize_640x480_SP (1920+19+45)*1024
#define MP4SwDecIntraModeExtSize_720x480_SP (2160+22+51)*1024
#define MP4SwDecIntraModeExtSize_800x480_SP (2408+26+56)*1024
#define MP4SwDecIntraModeExtSize_848x480_SP (2550+26+60)*1024
#define MP4SwDecIntraModeExtSize_864x480_SP (2550+26+61)*1024
#define MP4SwDecIntraModeExtSize_720x576_SP (2600+26+61)*1024
#define MP4SwDecIntraModeExtSize_800x608_SP (3046+30+71)*1024
#define MP4SwDecIntraModeExtSize_1024x768_SP (4900+48+114)*1024
#define MP4SwDecIntraModeExtSize_1280x720_SP (5750+57+134)*1024
#define MP4SwDecIntraModeExtSize_1280x960_SP (7660+75+179)*1024
#define MP4SwDecIntraModeExtSize_1280x1024_SP (8160+80+190)*1024
#define MP4SwDecIntraModeExtSize_1408x1152_SP (10100+99+236)*1024
#define MP4SwDecIntraModeExtSize_1600x1200_SP (11950+118+279)*1024
#define MP4SwDecIntraModeExtSize_1920x1088_SP (13000+128+303)*1024

#define MP4SwDecIntraModeExtSize_128x96_ASP (110+2+2)*1024
#define MP4SwDecIntraModeExtSize_176x144_ASP (190+2+4)*1024
#define MP4SwDecIntraModeExtSize_320x240_ASP (500+5+12)*1024
#define MP4SwDecIntraModeExtSize_400x240_ASP (620+7+14)*1024
#define MP4SwDecIntraModeExtSize_352x288_ASP (650+7+15)*1024
#define MP4SwDecIntraModeExtSize_432x240_ASP (660+7+16)*1024
#define MP4SwDecIntraModeExtSize_480x320_ASP (970+10+23)*1024
#define MP4SwDecIntraModeExtSize_640x368_ASP (1480+15+35)*1024
#define MP4SwDecIntraModeExtSize_640x480_ASP (1920+19+45)*1024
#define MP4SwDecIntraModeExtSize_720x480_ASP (2160+22+51)*1024
#define MP4SwDecIntraModeExtSize_800x480_ASP (2408+26+56)*1024
#define MP4SwDecIntraModeExtSize_848x480_ASP (2550+26+60)*1024
#define MP4SwDecIntraModeExtSize_864x480_ASP (2550+26+61)*1024
#define MP4SwDecIntraModeExtSize_720x576_ASP (2600+26+61)*1024
#define MP4SwDecIntraModeExtSize_800x608_ASP (3046+30+71)*1024
#define MP4SwDecIntraModeExtSize_1024x768_ASP (4900+48+114)*1024
#define MP4SwDecIntraModeExtSize_1280x720_ASP (5750+57+134)*1024
#define MP4SwDecIntraModeExtSize_1280x960_ASP (7660+75+179)*1024
#define MP4SwDecIntraModeExtSize_1280x1024_ASP (8160+80+190)*1024
#define MP4SwDecIntraModeExtSize_1408x1152_ASP (10100+99+236)*1024
#define MP4SwDecIntraModeExtSize_1600x1200_ASP (11950+118+279)*1024
#define MP4SwDecIntraModeExtSize_1920x1088_ASP (13000+128+303)*1024
#else
#define MP4SwDecExtSize_128x96_SP 43*1024
#define MP4SwDecExtSize_176x144_SP 45*1024
#define MP4SwDecExtSize_320x240_SP 53*1024
#define MP4SwDecExtSize_400x240_SP 58*1024
#define MP4SwDecExtSize_352x288_SP 58*1024
#define MP4SwDecExtSize_432x240_SP 58*1024
#define MP4SwDecExtSize_480x320_SP 65*1024
#define MP4SwDecExtSize_640x368_SP 78*1024
#define MP4SwDecExtSize_640x480_SP 90*1024
#define MP4SwDecExtSize_720x480_SP 97*1024
#define MP4SwDecExtSize_800x480_SP 109*1024
#define MP4SwDecExtSize_848x480_SP 109*1024
#define MP4SwDecExtSize_864x480_SP 109*1024
#define MP4SwDecExtSize_720x576_SP 109*1024
#define MP4SwDecExtSize_800x608_SP 117*1024
#define MP4SwDecExtSize_1024x768_SP 170*1024
#define MP4SwDecExtSize_1280x720_SP 190*1024
#define MP4SwDecExtSize_1280x960_SP 238*1024
#define MP4SwDecExtSize_1280x1024_SP 252*1024
#define MP4SwDecExtSize_1408x1152_SP 302*1024
#define MP4SwDecExtSize_1600x1200_SP 351*1024
#define MP4SwDecExtSize_1920x1088_SP 381*1024

#define MP4SwDecExtSize_128x96_ASP 44*1024
#define MP4SwDecExtSize_176x144_ASP 46*1024
#define MP4SwDecExtSize_320x240_ASP 62*1024
#define MP4SwDecExtSize_400x240_ASP 69*1024
#define MP4SwDecExtSize_352x288_ASP 70*1024
#define MP4SwDecExtSize_432x240_ASP 71*1024
#define MP4SwDecExtSize_480x320_ASP 85*1024
#define MP4SwDecExtSize_640x368_ASP 110*1024
#define MP4SwDecExtSize_640x480_ASP 132*1024
#define MP4SwDecExtSize_720x480_ASP 145*1024
#define MP4SwDecExtSize_800x480_ASP 162*1024
#define MP4SwDecExtSize_848x480_ASP 166*1024
#define MP4SwDecExtSize_864x480_ASP 167*1024
#define MP4SwDecExtSize_720x576_ASP 167*1024
#define MP4SwDecExtSize_800x608_ASP 185*1024
#define MP4SwDecExtSize_1024x768_ASP 282*1024
#define MP4SwDecExtSize_1280x720_ASP 321*1024
#define MP4SwDecExtSize_1280x960_ASP 414*1024
#define MP4SwDecExtSize_1280x1024_ASP 440*1024
#define MP4SwDecExtSize_1408x1152_ASP 535*1024
#define MP4SwDecExtSize_1600x1200_ASP 627*1024
#define MP4SwDecExtSize_1920x1088_ASP 681*1024

#define MP4SwDecIntraModeExtSize_128x96_SP 43*1024
#define MP4SwDecIntraModeExtSize_176x144_SP 45*1024 
#define MP4SwDecIntraModeExtSize_320x240_SP 53*1024 
#define MP4SwDecIntraModeExtSize_400x240_SP 58*1024 
#define MP4SwDecIntraModeExtSize_352x288_SP 58*1024 
#define MP4SwDecIntraModeExtSize_432x240_SP 58*1024 
#define MP4SwDecIntraModeExtSize_480x320_SP 65*1024 
#define MP4SwDecIntraModeExtSize_640x368_SP 78*1024 
#define MP4SwDecIntraModeExtSize_640x480_SP 90*1024 
#define MP4SwDecIntraModeExtSize_720x480_SP 97*1024 
#define MP4SwDecIntraModeExtSize_800x480_SP 109*1024
#define MP4SwDecIntraModeExtSize_848x480_SP 109*1024
#define MP4SwDecIntraModeExtSize_864x480_SP 109*1024
#define MP4SwDecIntraModeExtSize_720x576_SP 109*1024
#define MP4SwDecIntraModeExtSize_800x608_SP 117*1024
#define MP4SwDecIntraModeExtSize_1024x768_SP 170*1024
#define MP4SwDecIntraModeExtSize_1280x720_SP 190*1024
#define MP4SwDecIntraModeExtSize_1280x960_SP 238*1024
#define MP4SwDecIntraModeExtSize_1280x1024_SP 252*1024
#define MP4SwDecIntraModeExtSize_1408x1152_SP 302*1024
#define MP4SwDecIntraModeExtSize_1600x1200_SP 351*1024
#define MP4SwDecIntraModeExtSize_1920x1088_SP 381*1024

#define MP4SwDecIntraModeExtSize_128x96_ASP 44*1024
#define MP4SwDecIntraModeExtSize_176x144_ASP 46*1024 
#define MP4SwDecIntraModeExtSize_320x240_ASP 62*1024 
#define MP4SwDecIntraModeExtSize_400x240_ASP 69*1024 
#define MP4SwDecIntraModeExtSize_352x288_ASP 70*1024 
#define MP4SwDecIntraModeExtSize_432x240_ASP 71*1024 
#define MP4SwDecIntraModeExtSize_480x320_ASP 85*1024 
#define MP4SwDecIntraModeExtSize_640x368_ASP 110*1024
#define MP4SwDecIntraModeExtSize_640x480_ASP 132*1024
#define MP4SwDecIntraModeExtSize_720x480_ASP 145*1024
#define MP4SwDecIntraModeExtSize_800x480_ASP 162*1024
#define MP4SwDecIntraModeExtSize_848x480_ASP 166*1024
#define MP4SwDecIntraModeExtSize_864x480_ASP 167*1024
#define MP4SwDecIntraModeExtSize_720x576_ASP 167*1024
#define MP4SwDecIntraModeExtSize_800x608_ASP 185*1024
#define MP4SwDecIntraModeExtSize_1024x768_ASP 282*1024
#define MP4SwDecIntraModeExtSize_1280x720_ASP 321*1024
#define MP4SwDecIntraModeExtSize_1280x960_ASP 414*1024
#define MP4SwDecIntraModeExtSize_1280x1024_ASP 440*1024
#define MP4SwDecIntraModeExtSize_1408x1152_ASP 535*1024
#define MP4SwDecIntraModeExtSize_1600x1200_ASP 627*1024
#define MP4SwDecIntraModeExtSize_1920x1088_ASP 681*1024
#endif



#ifdef __cplusplus
    }
#endif
    
#endif /* MP4SWDECMEM_H */

