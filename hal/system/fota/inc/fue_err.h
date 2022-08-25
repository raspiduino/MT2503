/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   fue_err.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This is error of firmware update engine
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __FUE_ERR_H__
#define __FUE_ERR_H__

/* Operation Status Code */

typedef enum 
{
   ERROR_FUE_NEW_ALLOCATED_BLOCK                  = 2,
   ERROR_FUE_CORRECTED_ECC                        = 1,
   ERROR_FUE_NONE                                 = 0,
   ERROR_FUE_CUSTOMIZATION                        = -1,
   ERROR_FUE_LOCK                                 = -2,
   ERROR_FUE_PROGRAM                              = -3,
   ERROR_FUE_ERASE                                = -4,
   ERROR_FUE_INFLATE_INIT                         = -5,
   ERROR_FUE_INFLATING                            = -6,
   ERROR_FUE_WAITREADY                            = -7,
   ERROR_FUE_PROGRAM_FAILED                       = -8,
   ERROR_FUE_ERASE_FAILED                         = -9,
   ERROR_FUE_PROGRAM_TIMEOUT                      = -10,
   ERROR_FUE_ERASE_TIMEOUT                        = -11,
   ERROR_FUE_FLASH_BUSY                           = -12,
   ERROR_FUE_FLASH_CONFIGURATION                  = -13,
   ERROR_FUE_BUFFER_NOT_ALIGNED                   = -14,
   ERROR_FUE_DMA_TIMEOUT                          = -15,
   ERROR_FUE_TRANSFER_TIMEOUT                     = -16,
   ERROR_FUE_UNKNOWN_PARAMETER                    = -17,
   ERROR_FUE_UNRECOVERABLE_ECC                    = -18,
   ERROR_FUE_CHECKSUM_FAILED                      = -19,
   ERROR_FUE_OVER_DESIGN                          = -20,
   ERROR_FUE_MAP_TABLE_CORRUPTED                  = -21,
   ERROR_FUE_MAPPING_TABLE_LOST                   = -22,
   ERROR_FUE_MAPPING_TABLE_FULL                   = -23,
   ERROR_FUE_INVALID_PARAMETER                    = -24,
   ERROR_FUE_NO_VALID_UPADTE_RECORD               = -25,
   ERROR_FUE_NO_UPDATE_RECORD_BLOCK               = -26,
   ERROR_FUE_UPADTE_RECORD_CORRUPTED              = -27,
   ERROR_FUE_UPADTE_BLOCK_CORRUPTED               = -28,
   ERROR_FUE_TOO_MANY_UPADTE_BLOCK                = -29,
   ERROR_FUE_NO_AVAILABLE_BLOCK                   = -30,
   ERROR_FUE_NO_AVAILABLE_PAGE                    = -31,
   ERROR_FUE_OUT_OF_IMAGE_RANGE                   = -32,
   ERROR_FUE_READ_FORBIDDEN                       = -33,
   ERROR_FUE_WRITE_FORBIDDEN                      = -34,
   ERROR_FUE_NOT_INITIALIZED                      = -35,
   ERROR_FUE_IMAGE_LIST_EXIST                     = -36,
   ERROR_FUE_UNRECOVERABLE_MAP_REPLACEMENT        = -37,
   ERROR_FUE_TOO_MANY_MAP_REPLACEMENTS            = -38,
   ERROR_FUE_INSUFFICIENT_BUFFER                  = -40,
   ERROR_FUE_NOT_FOUND                            = -41,
   ERROR_FUE_TOO_MANY_DUPLICATE_BLOCKS            = -42,
   ERROR_FUE_VERSION_MISMATCH                     = -43,
   ERROR_FUE_OUT_OF_TABLE_RANGE                   = -44,
   ERROR_FUE_CORRUPTED_IMAGE_BLOCK                = -45,
   ERROR_FUE_INVALID_ROM_IMAGE                    = -46,
   ERROR_FUE_INVALID_CHECK_REFERENCE              = -47,
   ERROR_FUE_INVALID_IMAGE_INFO                   = -48,
   ERROR_FUE_OPERATION_STOP                       = -49,
   ERROR_FUE_INFO_NAME_MISMATCH                   = -50,
   ERROR_FUE_TOO_MANY_PACKAGE_BLOCKS              = -51,
   ERROR_FUE_TOO_MANY_INTERRUPTED_BLOCKS          = -52,
   ERROR_FUE_READ_FAILURE                         = -53,
   ERROR_FUE_NO_MORE_PACKAGE_BLOCK                = -54,
   ERROR_FUE_INCORRECT_PACKAGE_HEAD               = -55,
   ERROR_FUE_WRONG_UPDATE_PACKAGE                 = -56,
   ERROR_FUE_INVALID_UPDATE_PACKAGE               = -57,
   ERROR_FUE_RECOVER_PROGRAM_ERROR                = -58,
   ERROR_FUE_BLK_TYPE_MISMATCH                    = -59,
   ERROR_FUE_UA_MAC_UPDATE_FAILED                 = -60,
   ERROR_FUE_UA_MAC_UPDATE_WRONG_VER              = -61,
   ERROR_FUE_MAUI_MAC_UPDATE_FAILED               = -62,
   ERROR_FUE_MAUI_MAC_UPDATE_WRONG_VER            = -63,
   ERROR_FUE_UA_UPDATE_FAIL                       = -64,
   ERROR_FUE_CONTENT_POLLUTED                     = -65,
   ERROR_FUE_UNEXPECTED_CHECK_CONFIGURATION       = -66,
   ERROR_FUE_BLOCK_OCCUPIED                       = -67
} FUE_ERROR_CODE;

/* Update Result Code */
typedef enum 
{
   UPDATE_FUE_DONE = 0x500,
   UPDATE_FUE_ERROR,
   UPDATE_FUE_NONE
} FUE_UPDATE_CODE;

/* FUE update error state */
typedef enum 
{
   FUE_UPDATE_ERROR_NONE = 0x700,
   FUE_UPDATE_ERROR_OUT_OF_RANGE,
   FUE_UPDATE_ERROR_NO_FREE_BLOCKS,
   FUE_UPDATE_ERROR_UPDATE_FORBIDDEN,
   FUE_UPDATE_ERROR_NUM
} FUE_UPDATE_ERROR_STATE;

/* Invalid value definition */
#define INVALID_DWORD    (0xFFFFFFFF)
#define INVALID_WORD     (0xFFFF)
#define INVALID_BYTE     (0xFF)

#endif /*__FUE_ERR_H__*/
