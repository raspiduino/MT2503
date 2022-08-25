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
 *
 * Project:
 * --------
 *	 Maui
 *
 * Description:
 * ------------
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 11 23 2010 hung-wen.hsieh
 * removed!
 * .
 *
 * 10 18 2010 ct.fang
 * removed!
 * .
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * add to source control recursely
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_core_mt6238_h__
#define __idp_core_mt6238_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include "kal_non_specific_general_types.h"
#include "drv_features.h"
#include "drv_comm.h"
#include <idp_define.h>

#if defined(DRV_IDP_6238_SERIES)

#include "mt6238\idp_hw\idp_imgdma_ibr1.h"
#include "mt6238\idp_hw\idp_imgdma_ibr2.h"
#include "mt6238\idp_hw\idp_imgdma_ibw1.h"
#include "mt6238\idp_hw\idp_imgdma_ibw2.h"
#include "mt6238\idp_hw\idp_imgdma_irt0.h"
#include "mt6238\idp_hw\idp_imgdma_irt1.h"
#include "mt6238\idp_hw\idp_imgdma_irt2.h"
#include "mt6238\idp_hw\idp_imgdma_irt3.h"
#include "mt6238\idp_hw\idp_imgdma_ovl.h"
#include "mt6238\idp_hw\idp_imgdma_jpeg.h"
#include "mt6238\idp_hw\idp_imgdma_video_decode.h"
#include "mt6238\idp_hw\idp_imgdma_video_encode.h"
#include "mt6238\idp_hw\idp_imgproc_ipp.h"
#include "mt6238\idp_hw\idp_imgproc_y2r1.h"
#include "mt6238\idp_hw\idp_imgproc_r2y0.h"
#include "mt6238\idp_hw\idp_resz_prz.h"
#include "mt6238\idp_hw\idp_resz_crz.h"
#include "mt6238\idp_hw\idp_resz_drz.h"
#include "mt6238\idp_hw\idp_mp4deblk.h"

enum idp_high_priority
{
  IDP_HIGH_PRIORITY_IRT1,
  IDP_HIGH_PRIORITY_ISP,
  IDP_HIGH_PRIORITY_VIDEO_ENCODE_DMA,
  IDP_HIGH_PRIORITY_MPEG4_DECODER,
  IDP_HIGH_PRIORITY_H264_DECODER
};
typedef enum idp_high_priority idp_high_priority;

extern idp_imgdma_ibr1_struct ibr1_struct;
extern idp_imgdma_ibr2_struct ibr2_struct;
extern idp_imgdma_ibw1_struct ibw1_struct;
extern idp_imgdma_ibw2_struct ibw2_struct;
extern idp_imgdma_irt0_struct irt0_struct;
extern idp_imgdma_irt1_struct irt1_struct;
extern idp_imgdma_irt2_struct irt2_struct;
extern idp_imgdma_irt3_struct irt3_struct;
extern idp_imgdma_ovl_struct ovl_struct;
extern idp_imgdma_jpeg_struct jpeg_struct;
extern idp_imgdma_video_decode_struct video_decode_struct;
extern idp_imgdma_video_encode_struct video_encode_struct;
extern idp_imgproc_ipp_struct ipp_struct;
extern idp_imgproc_y2r1_struct y2r1_struct;
extern idp_imgproc_r2y0_struct r2y0_struct;
extern idp_resz_prz_struct prz_struct;
extern idp_resz_crz_struct crz_struct;
extern idp_resz_drz_struct drz_struct;
extern idp_mp4deblk_struct mp4deblk_struct;

extern void idp_hw_init(void);
extern void turn_off_idp_power(void);
extern void idp_switch_high_priority(
  idp_high_priority const which, kal_bool const enable);

#endif
#endif
