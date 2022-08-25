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
 *   idp_imgproc.h
 *
 * Project:
 * --------
 *	 Maui
 *
 * Description:
 * ------------
 *   image processor
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
 * 01 07 2011 chrono.wu
 * removed!
 * .
 *
 * 12 06 2010 gellmann.chang
 * removed!
 * .
 *
 * 11 23 2010 gellmann.chang
 * removed!
 * .
 *
 * removed!
 * removed!
 * MT6255 HQA check-in
 *
 * removed!
 * removed!
 * DVT check-in
 *
 * removed!
 * removed!
 * MDP driver
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/**
 * \defgroup imgproc Image processor
 * \ingroup idp
 * @{
 */
#ifndef __idp_imgproc_mt6276_h__
#define __idp_imgproc_mt6276_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include <idp_define.h>

#if defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6256_SERIES) || defined(DRV_IDP_MT6276E2_SERIES)

#include "reg_base.h"

#define NO_ERROR 0

// TODO: TBD
#if 0
/* under construction !*/
/* under construction !*/
#endif //0

// TODO: TBD
#if 0
/* under construction !*/
/* under construction !*/
#endif // 0

/*bit define of IMGPROC_R2Y_SRC*/ 
// TODO: TBD
#if defined (MT6268B)
#define IMGPROC_R2Y_SRC_IPP_IO_MASK         0X000000FF            
#else // MT6268B
#define IMGPROC_R2Y_SRC_IPP_IO_MASK         0X0000007F            
#endif // MT6268B
#define IMGPROC_R2Y_SRC_Y2R1_IO_MASK        0X00000F00            
#define IMGPROC_R2Y_SRC_R2Y0_IO_MASK        0X001F0000

/*bit define of IMGPROC_EN*/ 
// TODO: TBD
#define IMGPROC_HW_IPP_ENABLE_BIT           0x00000001            
#define IMGPROC_HW_R2Y0_ENABLE_BIT          0x00000010            
#define IMGPROC_HW_Y2R1_ENABLE_BIT          0x00000100
#define IMGPROC_RESET_BIT                   0x00001000
#if defined (MT6268B)
#define IMGPROC_INIT_ENABLE_BIT             0x00002000
#endif // MT6268B

// TODO: TBD
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined (MT6268B)
/* under construction !*/
/* under construction !*/
#endif // MT6268B
#endif // 0

extern void 
idp_imgproc_init(void);

#endif // #if defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6256_SERIES)
#endif // __idp_imgproc_mt6276_h__
/** @} */
