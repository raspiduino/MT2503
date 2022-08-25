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
 *   jpeg_mjpeg_mem_6235_series.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Main include file of JPEG codec unified interface.
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
#ifndef __JPEG_MJPEG_MEM_6235_SERIES_H__
#define __JPEG_MJPEG_MEM_6235_SERIES_H__

#include "drv_features_jpeg.h"
#include "jpeg_mem.h"


/// ******************************************************************SW Encoder******************************************************************
/// ******************************************************************SW Decoder******************************************************************
#include "jpeg_mjpeg_mem_sw.h"
///JPEG_SW_ENC_MJPEG_INT_MIN_MEM_SIZE
///JPEG_SW_ENC_MJPEG_INT_MAX_MEM_SIZE
///JPEG_SW_ENC_MJPEG_EXT_MIN_MEM_SIZE
///JPEG_SW_ENC_MJPEG_EXT_MAX_MEM_SIZE
///JPEG_SW_DEC_MJPEG_INT_MIN_MEM_SIZE
///JPEG_SW_DEC_MJPEG_INT_MAX_MEM_SIZE
///JPEG_SW_DEC_MJPEG_EXT_MIN_MEM_SIZE
///JPEG_SW_DEC_MJPEG_EXT_MAX_MEM_SIZE
/// ******************************************************************SW Decoder******************************************************************
/// ******************************************************************SW Encoder******************************************************************


#define JPEG_ENC_MJPEG_INT_MIN_MEM_SIZE                     JPEG_SW_ENC_MJPEG_INT_MIN_MEM_SIZE
#define JPEG_ENC_MJPEG_INT_MAX_MEM_SIZE                     JPEG_SW_ENC_MJPEG_INT_MAX_MEM_SIZE
#define JPEG_ENC_MJPEG_EXT_MIN_MEM_SIZE                     JPEG_SW_ENC_MJPEG_EXT_MIN_MEM_SIZE
#define JPEG_ENC_MJPEG_EXT_MAX_MEM_SIZE                     JPEG_SW_ENC_MJPEG_EXT_MAX_MEM_SIZE


#define JPEG_DEC_MJPEG_INT_MIN_MEM_SIZE                     JPEG_SW_DEC_MJPEG_INT_MIN_MEM_SIZE
#define JPEG_DEC_MJPEG_INT_MAX_MEM_SIZE                     JPEG_SW_DEC_MJPEG_INT_MAX_MEM_SIZE
#define JPEG_DEC_MJPEG_EXT_MIN_MEM_SIZE                     JPEG_SW_DEC_MJPEG_EXT_MIN_MEM_SIZE
#define JPEG_DEC_MJPEG_EXT_MAX_MEM_SIZE                     JPEG_SW_DEC_MJPEG_EXT_MAX_MEM_SIZE


#define JPEG_DEC_ENC_MJPEG_TOTAL_INT_MIN_MEM_SIZE           (JPEG_ENC_MJPEG_INT_MIN_MEM_SIZE + JPEG_DEC_MJPEG_INT_MIN_MEM_SIZE)
#define JPEG_DEC_ENC_MJPEG_TOTAL_INT_MAX_MEM_SIZE           (JPEG_ENC_MJPEG_INT_MAX_MEM_SIZE + JPEG_DEC_MJPEG_INT_MAX_MEM_SIZE)
#define JPEG_DEC_ENC_MJPEG_TOTAL_EXT_MIN_MEM_SIZE           (JPEG_ENC_MJPEG_EXT_MIN_MEM_SIZE + JPEG_DEC_MJPEG_EXT_MIN_MEM_SIZE)
#define JPEG_DEC_ENC_MJPEG_TOTAL_EXT_MAX_MEM_SIZE           (JPEG_ENC_MJPEG_EXT_MAX_MEM_SIZE + JPEG_DEC_MJPEG_EXT_MAX_MEM_SIZE)

#endif   // __JPEG_CODEC_MEM_H__





