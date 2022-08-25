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
 *   SSS_interface.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains the interface between SST and SSS 
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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/*******************************************************************************
 * Included header files
 *******************************************************************************/
#include "kal_general_types.h"
#include "reg_base.h"
#include "che_hw.h"
#ifdef __FOTA_DM__
#include "custom_fota.h"
#endif /* __FOTA_DM__ */
/*************************************************************************
 * External global data declaration
 *************************************************************************/

#ifdef __MTK_SECURE_PLATFORM__
/* under construction !*/
#else //__MTK_SECURE_PLATFORM__
const kal_bool g_SST_SecurePlatform = KAL_FALSE;
#endif //__MTK_SECURE_PLATFORM__

#ifdef __SECURE_RO_ENABLE__
const kal_bool g_SST_SecureRO = KAL_TRUE;
#else //__SECURE_RO_ENABLE__
const kal_bool g_SST_SecureRO = KAL_FALSE;
#endif //__SECURE_RO_ENABLE__

#if defined (__SECURE_USB_DOWNLOAD__) || defined(__SECURE_UART_DOWNLOAD__)
const kal_bool g_SST_USBDownload4EndUser = KAL_TRUE;
#else //__SECURE_USB_DOWNLOAD__ || __SECURE_UART_DOWNLOAD__
const kal_bool g_SST_USBDownload4EndUser = KAL_FALSE;
#endif //__SECURE_USB_DOWNLOAD__ || __SECURE_UART_DOWNLOAD__

#ifdef _NAND_FLASH_BOOTING_
const kal_bool g_SST_NFB = KAL_TRUE;

#if defined(__MTK_SECURE_PLATFORM__)
#if defined(MT6235) || defined(MT6238) || defined(MT6268A) || defined(MT6235B) || defined(MT6239) || defined(MT6268) || defined(MT6236) || defined(MT6236B)
/* under construction !*/
#else
/* under construction !*/
#endif
#else /* defined(__MTK_SECURE_PLATFORM__) */
const kal_bool g_SST_SecureNFB = KAL_FALSE;
#endif /* defined(__MTK_SECURE_PLATFORM__) */

#else // _NAND_FLASH_BOOTING_
const kal_bool g_SST_NFB = KAL_FALSE;
const kal_bool g_SST_SecureNFB = KAL_FALSE;
#endif // _NAND_FLASH_BOOTING_

#if defined(MT6235) || defined(MT6238) || defined(MT6268A) || defined(MT6235B) || defined(MT6239) || defined(MT6268) || defined(MT6253) || defined(MT6236) || defined(MT6236B) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252)
const kal_bool g_SST_SWOTP = KAL_TRUE;
#else
const kal_bool g_SST_SWOTP = KAL_FALSE;
#endif

#if defined(MT6253) || defined(MT6268) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252)
const kal_bool g_SST_HW_HASH = KAL_TRUE;
#else
const kal_bool g_SST_HW_HASH = KAL_FALSE;
#endif

#if defined(__FOTA_DM__)
const kal_bool g_SST_FOTA = KAL_TRUE;
#else
const kal_bool g_SST_FOTA = KAL_FALSE;
#endif

#if defined(__FOTA_DM__) && !defined(_NAND_FLASH_BOOTING_) && !defined(__EMMC_BOOTING__)
#define FOTA_MARS_HEADER_OFFSET         (FOTA_NOR_FLASH_PAGE_SIZE<<1) /*(0x1000)*/
#define FOTA_MARS_HEADER_SIZE           FOTA_NOR_FLASH_PAGE_SIZE /*(0x800)*/
const kal_bool g_SST_FOTAPartial = KAL_TRUE;
const kal_uint32 g_SST_UAoffset = 1;
const kal_uint32 g_FOTA_MAC_Valid_Offset = FOTA_MARS_HEADER_OFFSET;
const kal_uint32 g_FOTA_MAC_Offset = FOTA_MARS_HEADER_SIZE+4;
const kal_uint32 g_FOTA_MAC_Valid_Size = FOTA_MARS_HEADER_SIZE;
#else //__MTK_SECURE_PLATFORM__
const kal_bool g_SST_FOTAPartial = KAL_FALSE;
const kal_uint32 g_SST_UAoffset = 0;
const kal_uint32 g_FOTA_MAC_Valid_Offset = 0;
const kal_uint32 g_FOTA_MAC_Offset = 0;
const kal_uint32 g_FOTA_MAC_Valid_Size = 0;
#endif //__MTK_SECURE_PLATFORM__

#if defined(MT6223) || defined(MT6223P) || defined(MT6225) || defined(MT6229) || defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252) || defined(MT6250)
const kal_uint32 g_SST_REMAPPING_ADDR = 0x08000000;
#else
const kal_uint32 g_SST_REMAPPING_ADDR = 0x10000000;
#endif


/* some platforms didn't have such definition */
#ifndef CHE_base

#ifdef SEJ_base
#define CHE_base  SEJ_base
#elif defined(CHE_BASE) /* SEJ_base */
#define CHE_base  CHE_BASE
#else /* SEJ_base */
#define CHE_base  0
#endif /* SEJ_base */
#endif /* CHE_base */
#ifndef RTC_base

#if defined(RTC_BASE)
#define RTC_base RTC_BASE
#else /* RTC_BASE */
#define RTC_base 0
#endif  /* RTC_BASE */

#endif  /* !RTC_base */

#ifndef EFUSE_base
#define EFUSE_base   (0x80000000)
#endif /* EFUSE_base */

#ifndef CONFIG_base
#ifdef CONFG_base
#define CONFIG_base CONFG_base
#else
#error "No CONFIG_base!"
#endif 
#endif /* CONFIG_base */

#if defined(MT6276) || defined(MT6251) || defined(MT6256) || defined(MT6573) || defined(MT6575) || defined(MT6255) || defined(MT6250) || defined(MT6260)  || defined(MT6261)  || defined(MT2501) || defined(MT2502)
const kal_uint32 g_SST_BootROM_version = 0x05;
#elif defined(MT6268) || defined(MT6516) || defined(MT6253) || defined(MT6236) || defined(MT6236B) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252)
const kal_uint32 g_SST_BootROM_version = 0x03;
#else
#error "No Bootrom Version!"
//const kal_uint32 g_SST_BootROM_version = 0x02;
#endif

#ifdef __USBDL_IN_BOOTROM__
const kal_uint32 g_SST_USBDownloadInBootROM = KAL_TRUE;
#else
const kal_uint32 g_SST_USBDownloadInBootROM = KAL_FALSE;
#endif /* __USBDL_IN_BOOTROM__ */

#if defined(MT6268)
const kal_uint32 g_SST_INTSRAM_base = 0x92000000;
#else
const kal_uint32 g_SST_INTSRAM_base = 0x40000000;
#endif /* defined(MT6268) */

const kal_uint32 g_SST_CONFIG_base = CONFIG_base;
const kal_uint32 g_SST_CHE_base = CHE_base;
const kal_uint32 g_SST_RTC_base = RTC_base;
const kal_uint32 g_SST_EFUSE_base = EFUSE_base;

#if defined(MT6276_S01) || defined(MT6250) || defined(MT6260) || defined(MT6261)  || defined(MT2501) || defined(MT2502)
const kal_uint32 g_SST_VERSION_base = VERSION_base;
#else
const kal_uint32 g_SST_VERSION_base = CONFIG_base;
#endif

#if defined(MT6268)
const kal_uint32 g_SST_PDN_CLR_OFFSET = 0x0320;
const kal_uint32 g_SST_PDN_SET_OFFSET = 0x0310;
const kal_uint32 g_SST_PDN_BIT        = 0x0010;
#elif defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252)
const kal_uint32 g_SST_PDN_CLR_OFFSET = 0x032C;
const kal_uint32 g_SST_PDN_SET_OFFSET = 0x031C;
const kal_uint32 g_SST_PDN_BIT        = 0x0004;
#elif defined(MT6236) || defined(MT6236B)
const kal_uint32 g_SST_PDN_CLR_OFFSET = 0x0720;
const kal_uint32 g_SST_PDN_SET_OFFSET = 0x0710;
const kal_uint32 g_SST_PDN_BIT        = 0x0010;
#else
const kal_uint32 g_SST_PDN_CLR_OFFSET = 0x0000;
const kal_uint32 g_SST_PDN_SET_OFFSET = 0x0000;
const kal_uint32 g_SST_PDN_BIT        = 0x0000;
#endif

#ifndef __SV5_ENABLED__
#ifdef __MTK_TARGET__
#pragma arm section rodata = "INIT_CODE"
const kal_uint32 g_SST_CONFIG_base_init = g_SST_CONFIG_base;
const kal_uint32 g_SST_CHE_base_init    = g_SST_CHE_base;
#pragma arm section rodata
#endif /* __MTK_TARGET__ */
#endif /* __SV5_ENABLED__ */

#if defined(MT6229)
const kal_uint32 g_EFUSE_VER = 0x1;
#else
const kal_uint32 g_EFUSE_VER = 0x2;
#endif /* MT6229 */
