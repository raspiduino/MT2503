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
 *    idp_hw_common.h
 *
 * Project:
 * --------
 *    MAUI
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
 * 04 22 2011 peter.wang
 * removed!
 * .
 *
 * 11 23 2010 cm.huang
 * removed!
 * .
 *
 * 10 20 2010 cm.huang
 * NULL
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_hw_common_mt6253_h__
#define __idp_hw_common_mt6253_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

enum idp_module_enum_t
{
    IDP_MODULE_IMGDMA_RDMA0
  , IDP_MODULE_IMGDMA_RDMA1

  , IDP_MODULE_IMGDMA_WDMA0
  , IDP_MODULE_IMGDMA_WDMA1
  , IDP_MODULE_IMGDMA_WDMA2

  , IDP_MODULE_IMGDMA_ROTDMA0 /**< The control code of the mux is put in ROT_DMA0. */
  , IDP_MODULE_IMGDMA_ROTDMA1

  , IDP_MODULE_IMGDMA_OVL
  , IDP_MODULE_IMGDMA_JPEG

  , IDP_MODULE_IMGPROC_IPP

  , IDP_MODULE_RESZ_CRZ
  , IDP_MODULE_RESZ_PRZ
  , IDP_MODULE_RESZ_DRZ

  , IDP_MODULE_MMSYS_MOUT

  , IDP_MODULE_OUTER_LCD // TODO: change outer to external
  , IDP_MODULE_OUTER_ISP // TODO: change outer to external
  , IDP_MODULE_OUTER_JPEG_ENCODER // TODO: change outer to external

  , IDP_MODULE_LAST
};
typedef enum idp_module_enum_t idp_module_enum_t;

typedef enum
{
    IDP_LCD_HW_TRIGGER_MODE_DISABLE,
    IDP_LCD_HW_TRIGGER_MODE_NO_SYNC,
    IDP_LCD_HW_TRIGGER_MODE_SYNC_N_STALL,
    IDP_LCD_HW_TRIGGER_MODE_SYNC_N_REDRAW,
    IDP_LCD_HW_TRIGGER_MODE_SYNC_N_DROP
} idp_lcd_hw_trigger_mode_t;

#endif // #ifndef __idp_hw_common_mt6253_h__

