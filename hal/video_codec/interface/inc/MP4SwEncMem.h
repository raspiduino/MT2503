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
 *   MP4SwEncMem.h
 *
 * Project:
 * --------
 *	MTK
 *
 * Description:
 * ------------

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
 ****************************************************************************/

#ifndef ___MP4SWENCMEM_H_
#define ___MP4SWENCMEM_H_

#ifdef __cplusplus
extern "C"
    {
#endif

#include "drv_features_vcodec.h"

#include "MP4SwEncDefs.h"

#ifdef MP4SwEncMaxVidCodRes_QCIF
#define MP4SwEncMaxVidCodRes      RES_QCIF
#elif defined(MP4SwEncMaxVidCodRes_QVGA)
#define MP4SwEncMaxVidCodRes      RES_QVGA
#elif defined(MP4SwEncMaxVidCodRes_CIF)
#define MP4SwEncMaxVidCodRes      RES_CIF
#elif defined(MP4SwEncMaxVidCodRes_WQVGA)
#define MP4SwEncMaxVidCodRes      RES_WQVGA
#elif defined(MP4SwEncMaxVidCodRes_HVGA)
#define MP4SwEncMaxVidCodRes      RES_HVGA
#elif defined(MP4SwEncMaxVidCodRes_nHD)
#define MP4SwEncMaxVidCodRes      RES_nHD
#elif defined(MP4SwEncMaxVidCodRes_VGA)
#define MP4SwEncMaxVidCodRes      RES_VGA
#elif defined(MP4SwEncMaxVidCodRes_D1)
#define MP4SwEncMaxVidCodRes      RES_D1
#elif defined(MP4SwEncMaxVidCodRes_WVGA)
#define MP4SwEncMaxVidCodRes      RES_WVGA
#elif defined(MP4SwEncMaxVidCodRes_4CIF)
#define MP4SwEncMaxVidCodRes      RES_4CIF
#elif defined(MP4SwEncMaxVidCodRes_WVGA_848x480)
#define MP4SwEncMaxVidCodRes      RES_WVGA_848x480
#elif defined(MP4SwEncMaxVidCodRes_D1_720x576)
#define MP4SwEncMaxVidCodRes      RES_D1_720x576
#elif defined(MP4SwEncMaxVidCodRes_FWVGA)
#define MP4SwEncMaxVidCodRes      RES_FWVGA
#elif defined(MP4SwEncMaxVidCodRes_SVGA)
#define MP4SwEncMaxVidCodRes      RES_SVGA
#elif defined(MP4SwEncMaxVidCodRes_XGA)
#define MP4SwEncMaxVidCodRes      RES_XGA
#elif defined(MP4SwEncMaxVidCodRes_720p)
#define MP4SwEncMaxVidCodRes      RES_720p
#else
#define MP4SwEncMaxVidCodRes      RES_ZERO
#endif

#define MP4SwEnc
#if MP4SwEncMaxVidCodRes >= RES_QCIF
#define MP4SwEncExtSize_176x144   (MP4SwEncFBSize_QCIF + MP4SwEncExtContextSize_QCIF + ExtMemMargin)
#else
#define MP4SwEncExtSize_176x144   (MP4SwEncExtContextSize_QCIF + ExtMemMargin)
#endif

#if MP4SwEncMaxVidCodRes >= RES_QVGA
#define MP4SwEncExtSize_320x240   (MP4SwEncFBSize_QVGA + MP4SwEncExtContextSize_QVGA + ExtMemMargin)
#else
#define MP4SwEncExtSize_320x240   (MP4SwEncExtContextSize_QVGA + ExtMemMargin)
#endif

#if MP4SwEncMaxVidCodRes >= RES_WQVGA
#define MP4SwEncExtSize_400x240   (MP4SwEncFBSize_WQVGA + MP4SwEncExtContextSize_WQVGA + ExtMemMargin)
#else
#define MP4SwEncExtSize_400x240   (MP4SwEncExtContextSize_WQVGA + ExtMemMargin)
#endif

#if MP4SwEncMaxVidCodRes >= RES_CIF
#define MP4SwEncExtSize_352x288   (MP4SwEncFBSize_CIF + MP4SwEncExtContextSize_CIF + ExtMemMargin)
#else
#define MP4SwEncExtSize_352x288   (MP4SwEncExtContextSize_CIF + ExtMemMargin)
#endif

#if MP4SwEncMaxVidCodRes >= RES_HVGA
#define MP4SwEncExtSize_480x320   (MP4SwEncFBSize_HVGA + MP4SwEncExtContextSize_HVGA + ExtMemMargin)
#else
#define MP4SwEncExtSize_480x320   (MP4SwEncExtContextSize_HVGA + ExtMemMargin)
#endif

#if MP4SwEncMaxVidCodRes >= RES_nHD
#define MP4SwEncExtSize_640x360   (MP4SwEncFBSize_nHD + MP4SwEncExtContextSize_nHD + ExtMemMargin)
#else
#define MP4SwEncExtSize_640x360   (MP4SwEncExtContextSize_nHD + ExtMemMargin)
#endif

#if MP4SwEncMaxVidCodRes >= RES_VGA
#define MP4SwEncExtSize_640x480   (MP4SwEncFBSize_VGA + MP4SwEncExtContextSize_VGA + ExtMemMargin)
#else
#define MP4SwEncExtSize_640x480   (MP4SwEncExtContextSize_VGA + ExtMemMargin)
#endif


#if MP4SwEncMaxVidCodRes >= RES_D1
#define MP4SwEncExtSize_720x480   (MP4SwEncFBSize_D1 + MP4SwEncExtContextSize_D1 + ExtMemMargin)
#else
#define MP4SwEncExtSize_720x480   (MP4SwEncExtContextSize_D1 + ExtMemMargin)
#endif

#if MP4SwEncMaxVidCodRes >= RES_WVGA
#define MP4SwEncExtSize_800x480   (MP4SwEncFBSize_WVGA + MP4SwEncExtContextSize_WVGA + ExtMemMargin)
#else
#define MP4SwEncExtSize_800x480   (MP4SwEncExtContextSize_WVGA + ExtMemMargin)
#endif

#if MP4SwEncMaxVidCodRes >= RES_4CIF
#define MP4SwEncExtSize_704x576   (MP4SwEncFBSize_4CIF + MP4SwEncExtContextSize_4CIF + ExtMemMargin)
#else
#define MP4SwEncExtSize_704x576   (MP4SwEncExtContextSize_4CIF + ExtMemMargin)
#endif

#if MP4SwEncMaxVidCodRes >= RES_WVGA_848x480
#define MP4SwEncExtSize_848x480  (MP4SwEncFBSize_WVGA_848x480 + MP4SwEncExtContextSize_WVGA_848x480 + ExtMemMargin)
#else
#define MP4SwEncExtSize_848x480  (MP4SwEncExtContextSize_WVGA_848x480 + ExtMemMargin)
#endif

#if MP4SwEncMaxVidCodRes >= RES_D1_720x576
#define MP4SwEncExtSize_720x576  (MP4SwEncFBSize_D1_720x576 + MP4SwEncExtContextSize_D1_720x576 + ExtMemMargin)
#else
#define MP4SwEncExtSize_720x576  (MP4SwEncExtContextSize_D1_720x576 + ExtMemMargin)
#endif

#if MP4SwEncMaxVidCodRes >= RES_FWVGA
#define MP4SwEncExtSize_864x480   (MP4SwEncFBSize_FWVGA + MP4SwEncExtContextSize_FWVGA + ExtMemMargin)
#else
#define MP4SwEncExtSize_864x480   (MP4SwEncExtContextSize_FWVGA + ExtMemMargin)
#endif

#if MP4SwEncMaxVidCodRes >= RES_SVGA
#define MP4SwEncExtSize_800x608  (MP4SwEncFBSize_SVGA + MP4SwEncExtContextSize_SVGA + ExtMemMargin)
#else
#define MP4SwEncExtSize_800x608  (MP4SwEncExtContextSize_SVGA + ExtMemMargin)
#endif

#if MP4SwEncMaxVidCodRes >= RES_XGA
#define MP4SwEncExtSize_1024x768  (MP4SwEncFBSize_XGA + MP4SwEncExtContextSize_XGA + ExtMemMargin)
#else
#define MP4SwEncExtSize_1024x768  (MP4SwEncExtContextSize_XGA + ExtMemMargin)
#endif

#if MP4SwEncMaxVidCodRes >= RES_720p
#define MP4SwEncExtSize_1280x720  (MP4SwEncFBSize_720p + MP4SwEncExtContextSize_720p + ExtMemMargin)
#else
#define MP4SwEncExtSize_1280x720  (MP4SwEncExtContextSize_720p + ExtMemMargin)
#endif


//#define MP4SwEncExtSize_720x576   -1

#ifdef __cplusplus
    }
#endif

#endif  // ___MP4SWENCMEM_H_
