/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *	.h
 *
 * Project:
 * --------
 *   MT6238
 *
 * Description:
 * ------------
 *   This file is intends for ISP HW.
 *
 * Author:
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __ISP_HW_FEATURE_DEF_H__
#define __ISP_HW_FEATURE_DEF_H__

#include "drv_features.h"

#undef __ISP_BAYER_SENSOR_SUPPORT__			/* raw sensor support */
#undef __ISP_YUV_SENSOR_SUPPORT__				/* yuv sensor support */
#undef __ISP_COMPRESSED_YUV_SENSOR_SUPPORT__    /* compressed yuv output data sensor support */
#undef __ISP_RGB_SENSOR_SUPPORT__                           /*rgb format sensor support */
#undef __ISP_HW_CAPTURE_JPEG_DATA_SUPPORT__	/* isp hw jpeg sensor interface support */

#undef __ISP_PARALLE_SENSOR_SUPPORT__                   /* parallel interface support */
#undef __ISP_MIPI_SENSOR_SUPPORT__                          /* mipi interface support */
#undef __ISP_SERIAL_SENSOR_SUPPORT__                    /* serial interface support */
#undef __ISP_DIRECT_SENSOR_SUPPORT__                    /* direct interface support */ 

#undef __ISP_CPLL_SUPPORT__						/* cpll support 38,36,76 series*/
#undef __ISP_UPLL_SUPPORT__						/* upll 48M support */
#undef __ISP_CROP_WINDOW_SUPPORT__			/* digital zoom crop by isp */

#undef __ISP_BURST_READ_4_4_SUPPORT__                   /*Memory in burst read 4 x 4bytes for each read, 6268*/
#undef __ISP_BURST_READ_16_4_SUPPORT__                  /*Memory in burst read 4 x 4bytes for each read, 6236*/
#undef __ISP_BAYER_10_BIT_PACKET_OUTPUT_SUPPORT__   /*ISP output 10bit package(3 pixel in one word) rawdata support, 6236*/
#undef __ISP_AUTO_RECAPTURE_SUPPORT__                  /* isp auto recapture when capture fail, 6236*/
#undef __ISP_MEM_IN_SUPPORT__					/* isp mem in function */
#undef __ISP_MEM_OUT_SUPPORT__					/* isp mem dump function */
#undef __ISP_CRZ_HW_FRAME_SYNC_SUPPORT__		/* auto re-send full frame to crz */
#undef __ISP_RESET_MCLK_OUTPUT_INDEPENDENT__	/* reset isp won't reset mclk : 76,55,53EL,75,52,...*/

#undef __ISP_CAPTURE_MODE_BEST_SHOT_SUPPORT__		/* isp capture mode  */
#undef __ISP_CAPTURE_MODE_CONT_SHOT_SUPPORT__		/* isp capture mode  */
#undef __ISP_CAPTURE_MODE_BURST_SHOT_SUPPORT__	/* isp capture mode  */
#undef __ISP_CAPTURE_MODE_EV_BRACKET_SUPPORT__	/* isp capture mode  */
#undef __ISP_CAPTURE_MODE_ADD_FRAME_SUPPORT__		/* isp capture mode  */



// define some comoon compile option for ISP drivers of various chips.
#if (defined(DRV_ISP_MT6236_HW_SUPPORT))
#define __ISP_BAYER_SENSOR_SUPPORT__
#define __ISP_YUV_SENSOR_SUPPORT__
#define __ISP_PARALLE_SENSOR_SUPPORT__
#define __ISP_MIPI_SENSOR_SUPPORT__
#define __ISP_CPLL_SUPPORT__
#define __ISP_CROP_WINDOW_SUPPORT__
#define __ISP_BURST_READ_16_4_SUPPORT__
#define __ISP_BAYER_10_BIT_PACKET_OUTPUT_SUPPORT__
#define __ISP_AUTO_RECAPTURE_SUPPORT__
#define __ISP_MEM_IN_SUPPORT__
#define __ISP_MEM_OUT_SUPPORT__
#define __ISP_CRZ_HW_FRAME_SYNC_SUPPORT__

#define __ISP_CAPTURE_MODE_BEST_SHOT_SUPPORT__		
#define __ISP_CAPTURE_MODE_CONT_SHOT_SUPPORT__		
#define __ISP_CAPTURE_MODE_BURST_SHOT_SUPPORT__	
#define __ISP_CAPTURE_MODE_EV_BRACKET_SUPPORT__
#define __ISP_CAPTURE_MODE_ADD_FRAME_SUPPORT__		
#endif

#if (defined(DRV_ISP_MT6268_HW_SUPPORT))
#define __ISP_BAYER_SENSOR_SUPPORT__
#define __ISP_YUV_SENSOR_SUPPORT__
#define __ISP_PARALLE_SENSOR_SUPPORT__
#define __ISP_CPLL_SUPPORT__
#define __ISP_CROP_WINDOW_SUPPORT__
#define __ISP_BURST_READ_4_4_SUPPORT__
#define __ISP_MEM_IN_SUPPORT__
#define __ISP_MEM_OUT_SUPPORT__
#define __ISP_CRZ_HW_FRAME_SYNC_SUPPORT__

#define __ISP_CAPTURE_MODE_BEST_SHOT_SUPPORT__		
#define __ISP_CAPTURE_MODE_CONT_SHOT_SUPPORT__		
#define __ISP_CAPTURE_MODE_BURST_SHOT_SUPPORT__	
#define __ISP_CAPTURE_MODE_EV_BRACKET_SUPPORT__
#define __ISP_CAPTURE_MODE_ADD_FRAME_SUPPORT__		
#endif

#if (defined(MT6276)||defined(MT6256)||defined(MT6255))
#define __ISP_YUV_SENSOR_SUPPORT__
#define __ISP_PARALLE_SENSOR_SUPPORT__
#define __ISP_SERIAL_SENSOR_SUPPORT__
#define __ISP_HW_CAPTURE_JPEG_DATA_SUPPORT__
#define __ISP_MEM_IN_SUPPORT__
#define __ISP_MEM_OUT_SUPPORT__
#define __ISP_CRZ_HW_FRAME_SYNC_SUPPORT__
#define __ISP_RESET_MCLK_OUTPUT_INDEPENDENT__
#define __ISP_CPLL_SUPPORT__

#define __ISP_CAPTURE_MODE_CONT_SHOT_SUPPORT__		
#define __ISP_CAPTURE_MODE_BURST_SHOT_SUPPORT__		
#if (defined(MT6276)||defined(MT6256))
#define __ISP_CAPTURE_MODE_ADD_FRAME_SUPPORT__		
#endif

#endif

#if (defined(MT6235) || defined(MT6235B) || defined(MT6253) )
#define __ISP_YUV_SENSOR_SUPPORT__
#define __ISP_PARALLE_SENSOR_SUPPORT__
#define __ISP_MEM_IN_SUPPORT__
#define __ISP_MEM_OUT_SUPPORT__
#define __ISP_CROP_WINDOW_SUPPORT__
#define __ISP_CROP_WINDOW_SUPPORT_ONLY__
#define __ISP_UPLL_SUPPORT__
#if (defined(MT6235))// jpeg sensor not support add frame
#define __ISP_CAPTURE_MODE_BURST_SHOT_SUPPORT__		
#endif
#define __ISP_CAPTURE_MODE_CONT_SHOT_SUPPORT__		
#endif


#if (defined(MT6253E)||defined(MT6253L)||defined(MT6252)||defined(MT6252H)||defined(MT6250)||defined(MT6260)||defined(MT6261)||defined(MT2501)||defined(MT2502))
#define __ISP_YUV_SENSOR_SUPPORT__
#define __ISP_RGB_SENSOR_SUPPORT__
#define __ISP_PARALLE_SENSOR_SUPPORT__
#define __ISP_SERIAL_SENSOR_SUPPORT__
#define __ISP_DIRECT_SENSOR_SUPPORT__
#define __ISP_UPLL_SUPPORT__

#define __ISP_CAPTURE_MODE_CONT_SHOT_SUPPORT__		
#endif


#endif /* __ISP_HW_FEATURE_DEF_H__ */
