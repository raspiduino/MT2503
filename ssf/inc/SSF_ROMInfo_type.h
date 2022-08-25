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
 *   SSF_RomInfo_type.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements image information structure.
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

/*******************************************************************************
 * Included header files
 *******************************************************************************/
// #include "kal_release.h"

#ifndef __MTK_FOTA_ROM_INFORMATION__
#define __MTK_FOTA_ROM_INFORMATION__

#include "kal_general_types.h"
#include "fue.h"

/*************************************************************************
 * Common macro definitions
 *************************************************************************/
/* NOTE: 
 * To ease the effort of string matching, the pattern is stored in 4-bye aligned manner
 */
#define STORAGE_QUALIFIER   __align(4)

/*************************************************************************
 * Type definitions
 *************************************************************************/
#define PATTERN_ID_LEN                (32) /* must be 4's multiples */
typedef struct {
 kal_char                              m_super_identifier[PATTERN_ID_LEN];
 kal_uint32                            m_super_id_chksum;
} MTK_ROMInfo_Super_Header_v1_ST;
#define ROM_SUPER_HEADER_LEN           sizeof(MTK_ROMInfo_Super_Header_v1_ST) /* ID length + check sum size */

/*************************************************************************
 * ROM Image information for Bootloader
 *************************************************************************/
/*************************************************************************
 * Type definitions
 *************************************************************************/
typedef struct {
 MTK_ROMInfo_Super_Header_v1_ST      m_bl_header;
 kal_char                            m_bl_platform_id[128];
 kal_char                            m_bl_project_id[64];
 kal_uint32                          m_bl_version;
 kal_uint32                          m_bl_load_address;
 kal_uint32                          m_bl_length;
 kal_uint32                          m_bl_max_length;
 kal_uint8                           m_bl_chksum;
} MTK_BL_ROMInfo_v1_ST;

typedef enum {
   IMG_INFO_FOTA_BINARY = 0xEEA0,
   IMG_INFO_OTHERS
} IMG_INFO_TYPE;

typedef enum {
   IMAGE_SEARCH_HEADER_PATTERN = 0xFF90,
   IMAGE_READ_HEADER_PATTERN,
   IMAGE_VERIFY_HEADER_PATTERN,
   IMAGE_READ_CONTENT,
   IMAGE_VERIFY_CONTENT
} IMAGE_INFO_CHECK_STATE;

/*************************************************************************
 * Macro definitions
 *************************************************************************/
#define MTK_BL_ROMINFO_VERSION (0x01)
#define BL_CHECK_INITIAL_KEY   (0x35)
/*************************************************************************
 * ROM Image information for FOTA Update Engine
 *************************************************************************/
/*************************************************************************
 * Type definitions
 *************************************************************************/
typedef struct {
 kal_uint32                            m_ua_start_address;
 kal_uint32                            m_ua_load_address;
 kal_uint32                            m_ua_max_length;
} MTK_UA_Image_Head_Info_v1_ST;

/* Specify the updatable area range - MUST match the configuration in update package */
typedef struct {
 kal_uint32                            m_image_base_address;
 kal_uint32                            m_image_max_length;
 kal_uint32                            m_image_load_size;
} MTK_MAUI_Image_Space_Info_v1_ST;

typedef struct {
 MTK_ROMInfo_Super_Header_v1_ST        m_ua_header;
 kal_char                              m_ua_platform_id[128];
 kal_char                              m_ua_project_id[64];
 kal_uint32                            m_ua_version;
 MTK_UA_Image_Head_Info_v1_ST          m_ua_head_info;
 kal_uint8                             m_ua_chksum;
} MTK_UA_ROMInfo_Head_v1_ST;

typedef struct {
 kal_uint32                            m_ua_length;
 kal_uint32                            m_ua_crc_len;
 kal_uint32                            m_ua_crc;
} MTK_UA_Image_Tail_Info_v1_ST;

typedef struct {
 kal_uint32                            m_bl_length;
 kal_uint32                            m_bl_crc_len;
 kal_uint32                            m_bl_crc;
} MTK_BL_Image_Tail_Info_v1_ST;

typedef struct {
 MTK_ROMInfo_Super_Header_v1_ST        m_ua_header;
 kal_uint32                            m_ua_version;
 MTK_UA_Image_Tail_Info_v1_ST          m_ua_tail_info;
 kal_uint32                            m_ua_chksum;
} MTK_UA_ROMInfo_Tail_v1_ST;

typedef struct {
 MTK_ROMInfo_Super_Header_v1_ST        m_bl_header;
 kal_uint32                            m_bl_version;
 MTK_BL_Image_Tail_Info_v1_ST          m_bl_tail_info;
 kal_uint32                            m_bl_chksum;
} MTK_BL_ROMInfo_Tail_v1_ST;

/*************************************************************************
 * Macro definitions
 *************************************************************************/
#define MTK_UA_HEAD_ROMINFO_VERSION (0x01)
#define MTK_UA_TAIL_ROMINFO_VERSION (0x01)
#define UA_CHECK_INITIAL_KEY        (0x79)

/*************************************************************************
 * ROM Image information for MAUI
 *************************************************************************/
/*************************************************************************
 * Type definitions
 *************************************************************************/

/* image executioon and load region information */
typedef struct {
 kal_uint32                   m_rom_load_address;
 kal_uint32                   m_rom_start_address;
 kal_uint32                   m_rom_length;
} MTK_MAUI_Image_Info_v1_ST;

typedef struct {
 MTK_ROMInfo_Super_Header_v1_ST    m_fota_header;
 kal_char                          m_fota_platform_id[128];
 kal_char                          m_fota_project_id[64];
 kal_uint32                        m_fota_version;
 kal_uint32                        m_fota_image_number;
 MTK_MAUI_Image_Space_Info_v1_ST   m_fota_updatable_area[FOTA_MAX_IMAGE_AMOUNT];
 kal_uint32                        m_fota_package_base;
 kal_uint32                        m_fota_package_size;
 kal_uint32                        m_fota_backup_base;
 kal_uint32                        m_fota_backup_size;
 kal_uint32                        m_fota_reserved_size;
 kal_uint8                         m_fota_chksum;
} MTK_FOTA_ROM_Info_v1_ST;

/*************************************************************************
 * Macro definitions
 *************************************************************************/
#define MTK_FOTA_ROMINFO_VERSION (0x02)
#define MAUI_CHECK_INITIAL_KEY   (0x86)

#endif /* __MTK_FOTA_ROM_INFORMATION__ */
