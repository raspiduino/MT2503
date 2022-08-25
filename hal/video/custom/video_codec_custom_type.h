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
 *   video_codce_custom_type.h
 *
 * Project:
 * --------
 *	MTK
 *
 * Description:
 * ------------
 *
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
 *
 ****************************************************************************/
 
#ifndef VIDEO_CODEC_CUSTOM_TYPE_H
#define VIDEO_CODEC_CUSTOM_TYPE_H

#include "drv_comm.h"
#ifdef __VIDEO_ARCHI_V2__
#include "drv_features_video.h"



/***********************************************************************
*
*   Choices of support resolution
*
*   Please note that any modification of this section is prohibited
*
***********************************************************************/
#define RESOLUTION_128x96           0   // SQCIF
#define RESOLUTION_176x144          1   // QCIF
#define RESOLUTION_320x240          2   // QVGA
#define RESOLUTION_400x240          3   // WQVGA
#define RESOLUTION_352x288          4   // CIF
#define RESOLUTION_432x240          5   // CIF
#define RESOLUTION_480x320          6   // HVGA
#define RESOLUTION_640x368          7   // VGA
#define RESOLUTION_640x480          8   // VGA
#define RESOLUTION_720x480          9   // D1
#define RESOLUTION_800x480          10  // WVGA
#define RESOLUTION_848x480          11  // WVGA
#define RESOLUTION_720x576          12 // D1
#define RESOLUTION_800x608          13 // SVGA
#define RESOLUTION_1024x768         14 // XGA
#define RESOLUTION_1280x720         15 // 720P
#define RESOLUTION_1280x960         16 // 4VGA
#define RESOLUTION_1280x1024        17 // SXGA
#define RESOLUTION_1408x1152        18 // 16CIF
#define RESOLUTION_1600x1200        19 // 4SVGA
#define RESOLUTION_1920x1088        20 // FHD 
#define RESOLUTION_240x192          21 // TO support MOT 
#define RESOLUTION_704x576          22 // 4CIF
#define RESOLUTION_864x480          23 // FWVGA 

/***********************************************************************
*
*   Choices of support level (for h264)
*
*   Please note that any modification of this section is prohibited
*
***********************************************************************/
#define Level_10        0
#define Level_1b        1
#define Level_11        2
#define Level_12        3
#define Level_13        4
#define Level_20        5
#define Level_21        6
#define Level_22        7
#define Level_30        8
#define Level_31        9
#define Level_32        10
#define Level_40        11
#define Level_41        12
#define Level_42        13
#define Level_50        14
#define Level_51        15

#endif /* __VIDEO_ARCHI_V2__ */
#endif /* VIDEO_CODEC_CUSTOM_TYPE_H */
