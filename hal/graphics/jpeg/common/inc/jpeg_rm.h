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
 *   jpeg_rm_api.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Prototypes of some RM API for JPEG RM control.
 *   Notice that these API are for internal use only.
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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __JPEG_RM_H__
#define __JPEG_RM_H__

#include "jpeg_decode_api.h"
#include "jpeg_encode_api.h"

#if (defined(__RESOURCE_MANAGER__) && defined(__MTK_TARGET__))

typedef enum {
   JPEG_DCT_ACQUIRE_RET_SUCCESS = 0,
   JPEG_DCT_ACQUIRE_RET_FAILED
} JPEG_DCT_ACQUIRE_RET_CODE;

typedef enum {
   JPEG_DCT_RELEASE_RET_SUCCESS = 0,
   JPEG_DCT_RELEASE_RET_FAILED
} JPEG_DCT_RELEASE_RET_CODE;

#define JPEG_DECODER_EVENT_RM_DCT_ACQUIRE_SUCCESS   0x00000001
#define JPEG_DECODER_EVENT_RM_DCT_ACQUIRE_FAILED    0x00000002
#define JPEG_DECODER_EVENT_RM_DCT_ACQUIRE_TIMEOUT   0x00000004

#define JPEG_ENCODER_EVENT_RM_DCT_ACQUIRE_SUCCESS   0x00010000
#define JPEG_ENCODER_EVENT_RM_DCT_ACQUIRE_FAILED    0x00020000
#define JPEG_ENCODER_EVENT_RM_DCT_ACQUIRE_TIMEOUT   0x00040000


void _jpeg_rm_register(void);
JPEG_DCT_ACQUIRE_RET_CODE _jpeg_decoder_rm_acquire_dct(JPEG_DECODER_HANDLE handle);
JPEG_DCT_ACQUIRE_RET_CODE _jpeg_encoder_rm_acquire_dct(JPEG_ENCODER_HANDLE handle);
JPEG_DCT_RELEASE_RET_CODE _jpeg_decoder_rm_release_dct(void);
JPEG_DCT_RELEASE_RET_CODE _jpeg_encoder_rm_release_dct(void);

#endif //__RESOURCE_MANAGER__

#endif //__JPEG_RM_H__
