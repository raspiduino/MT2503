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
 *   MPEG4HWEncMem.h
 *
 * Project:
 * --------
 *	 MAUI
 *
 * Description:
 * ------------
 *   This file declares the memory requirement of MPEG4 HW
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MPEG4_HW_ENC_MEM_H
#define MPEG4_HW_ENC_MEM_H

/******************************************************************************
*
*
* MPEG4 HW for Video Recorder System
*
*
******************************************************************************/

/// Maximum encode frame width
#define ENC_MAX_FRAME_WIDTH                         720
/// Maximum encode frame height
#define ENC_MAX_FRAME_HEIGHT                        480
/// Maximum Chip encode frame width
#define CHIP_ENC_MAX_FRAME_WIDTH                    720
/// Maximum Chip encode frame height
#define CHIP_ENC_MAX_FRAME_HEIGHT                   480
/// Maximum Chip encode frame height
#define ENC_MAX_RESUME_BUFFER_SIZE                  2048


/******************************************************************************
*
*
* MPEG4 HW for Video Call System
*
*
******************************************************************************/

/// Maximum encode frame width for VT
#define ENC_MAX_FRAME_WIDTH_VT                      176
/// Maximum encode frame height for VT
#define ENC_MAX_FRAME_HEIGHT_VT                     144
/// Maximum Chip encode frame height
#define ENC_MAX_RESUME_BUFFER_SIZE_VT               1024


/******************************************************************************
*
*
* MPEG4 HW for Common Scenario
*
*
******************************************************************************/

/// YUV buffer alignment byte number
#define ENC_YUV_BUFFER_ALIGNED_BYTES                8

// Maximum encode internal (working) memory
#define ENC_MAX_INT_MEMORY(_FRAME_WIDTH,_FRAME_HEIGHT)     (3072+1024+328 + (_FRAME_WIDTH*(56+32)) + (3*16*16))
// Maximum encode internal (working) memory
#define ENC_MAX_EXT_MEMORY(_FRAME_WIDTH,_FRAME_HEIGHT)     (_FRAME_WIDTH * _FRAME_HEIGHT * 3) // W x H x 1.5 x 2

// HW internal working memory
#define ENC_INT_WORK_MEMORY ENC_MAX_INT_MEMORY(ENC_MAX_FRAME_WIDTH, ENC_MAX_FRAME_HEIGHT)
// HW external working memory
#define ENC_EXT_WORK_MEMORY ENC_MAX_EXT_MEMORY(ENC_MAX_FRAME_WIDTH, ENC_MAX_FRAME_HEIGHT)+ENC_MAX_RESUME_BUFFER_SIZE+CPU_CACHE_LINE_SIZE_MINE

#endif  /* MPEG4_HW_ENC_MEM_H */
