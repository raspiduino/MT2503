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
 *   SSF_RomInfo.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file keep some definitions about image information structure.
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
 * removed!
 * removed!
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SSF_ROMINFO_H__
#define __SSF_ROMINFO_H__

#include "kal_general_types.h"

/*************************************************************************
 * Macro definition
 *************************************************************************/
#define MTK_UA_HEAD_INFO_VALID     (0x56484155)
#define MTK_UA_TAIL_INFO_VALID     (0x4F415455)

#define MTK_BL_HEAD_INFO_VALID     (0x56484C42)

#define MTK_MAUI_HEAD_INFO_VALID   (0x4F48414D)

#define MTK_MAUI_ROM_INFO_VALID    (0x5649524D)

#define INVALID_LONG_VALUE         (0xFFFFFFFF)

//#define FOTA_UA_IMAGE_SIZE         (0x20000)
#define FOTA_UA_IMAGE_TEMP_ADDRESS (0x00000000)

#define FIELD_OFFSET(type, field, val) \
do{\
   type* ptr = 0;\
   val = (kal_uint32)&ptr->field;\
} while(0);

/*************************************************************************
 * Function declaration
 *************************************************************************/
kal_uint32 SSF_GetUpdateAgentSize(void);
kal_uint32 SSF_GetUpdateAgentAvailableSize(void);
kal_uint32 SSF_GetUpdateAgentBackupSize(void);
kal_uint32 SSF_GetUAImageHeadSize(void);
kal_uint32 SSF_GetUAImageTailSize(void);
kal_uint32 SSF_GetUAImageExecutionAddress(void);
kal_uint32 SSF_GetUAImageExecutionSize(void);
kal_uint32 SSF_GetMAUIImageAmount(void);
kal_uint32 SSF_GetMAUIImageAvailableSize(kal_uint32 idx);
//void SSF_LookUpImageRange(kal_uint32 idx, kal_uint32 *base, kal_uint32* max_len);
//kal_uint32 SSF_Check_LookUpImage(kal_uint32 base_addr);
kal_bool SSF_UAImageInfoCheck(void);
kal_uint32 SSF_LookUpMAUIImage(kal_uint32 base_addr);

kal_uint32 SSF_GetBootloaderSize(void);
kal_uint32 SSF_GetBootloaderAreaSize(void);

kal_uint32 SSF_GetMAUIImageNumber(void);
kal_uint32 SSF_GetMAUIImageLength(kal_uint32 idx);
kal_bool SSF_SearchMAUIImageHead(kal_uint8 *buff, kal_uint32 buff_size, kal_uint8* info_buff, \
                                 kal_uint32 *info_size);
kal_uint32 SSF_GetTotalMAUIImages(void);
kal_uint32 SSF_GetMAUIImageSize(kal_uint32 idx);
kal_uint32 SSF_GetMAUIImageBaseAddress(kal_uint32 idx);
kal_uint32 SSF_GetMAUIImageSpaceSize(kal_uint32 idx);
kal_uint32 SSF_GetMAUIBackupAreaBase(void);
kal_uint32 SSF_GetMAUIBackupAreaLength(void);

kal_uint32 SSF_GetUALoadAddress(void);

#endif
