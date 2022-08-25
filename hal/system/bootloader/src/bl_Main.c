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
 *   bl_main.c
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   This file defines the major procedure of bootloader
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_general_types.h"   
#include "kal_public_api.h" 
#include "sw_types.h"
#include "reg_base.h"
#include "emi_hw.h"
#include "bl_MTK_BB_REG.H"
#include "bl_BootInfo.h"
#include "bl_Init.h"
#include "bl_FOTA.h"
#include "bl_loader.h"
#include <rt_misc.h>   /* for __rt_lib_init() */ 
#include "bl_uart_hw.h"
#include "kbd_table.h"

#include "bl_common.h"
#include "bl_features.h"
#include "bl_custom.h"
#include "bl_setting.h"

#include "feature_def.h"
#include <string.h>

#include "br_time_stamp.h"
#ifdef __TIME_STAMP__
#include "br_time_stamp_cb.h"
#include "bl_time_stamp_id.h"
#endif

#ifdef __SV5_ENABLED__
#include "br_GFH_file_info.h"
#include "br_GFH_epp_param.h"
#include "br_header_block.h"
#include "br_bl_param.h"
#include "bl_GFH_body.h"
#endif /* __SV5_ENABLED__ */

#if defined __NAND_FDM_50__   
#include "nand_dal_version.h"
#endif /*  __NAND_FDM_50__ */

#if defined(__CARD_DOWNLOAD__)
#include "bl_update.h"
#endif /* __CARD_DOWNLOAD__ */

#if defined(__FUNET_ENABLE__)
#include "bl_funet.h"
#include "fs_gprot.h"
#endif /* __FUNET_ENABLE__ */

#if defined(__FUNET_ENABLE__) && defined(__EXT_BOOTLOADER__)
#include "funet.h"
#endif /* __FUNET_ENABLE__ && __EXT_BOOTLOADER__ */

#if defined(__DSP_FCORE4__)
#include "dmdsp_init.h"
#endif /* __DSP_FCORE4__ */

#ifdef __EXT_BL_UPDATE__
#include "SSF_ROMInfo_Type.h"
#include "custom_img_config.h"
#endif /* __EXT_BL_UPDATE__ */

#if defined(__FAST_LOGO__) && defined(__EXT_BOOTLOADER__)
#include "bootup_logo.h"
#include "CustFastLogoImgData.h"
#endif /* __FAST_LOGO__ && __EXT_BOOTLOADER__*/

#include "drv_features.h"

//#include "gpio_sw.h"
#include "dcl.h"
#include "dcl_gpio.h"

#if defined(__BMT_2_0_ARCHITECTURE__)
#include "bmt_chr_setting.h"
#endif

#if defined(__GPS_FW_UPDATE_SUPPORT__)
#include "GPS_DL_api.h"
#endif
#include "bl_INIT.H"
#include "init.h"
#include "config_hw.h"

/*************************************************************************
 * Macro and const definition
 *************************************************************************/
//Note that these value cannot be adjusted without discussing with Tool team
#ifndef __N_PLUS_0_PROJECT__
#define BL_DA_SHARED_DATA_MAX_SIZE  (32*1024)
#else
#define BL_DA_SHARED_DATA_MAX_SIZE  (4*1024)
#endif
#define BL_DA_SHARED_DATA_ID        "_BL_DA_SHARED_DATA_"
#define MINI_EXT_SHARED_DATA_ID     "_MINI_EXT_SHR_DATA_"

//ID for share data items
#define MINI_EXT_SHARD_FEATURE_COMBINATION              0x1000
#define MINI_EXT_SHARD_FEATURE_COMBINATION_EXT          0x1001
#define MINI_EXT_SHARD_RANDOM_SEED                      0x1002
#define MINI_EXT_SHARD_BL_PARAM                         0x1003
#define MINI_EXT_SHARE_BL_HEADER                        0x1004
#define MINI_EXT_SHARE_BL_TOKEN                         0x1005
#define MINI_EXT_SHARE_BL_TIME_STAMP_RECORD             0x1006
#define MINI_EXT_SHARE_EMI_PARAM                        0x1007
#define MINI_EXT_SHARE_EXT_BL_UPDATE_INFO               0x1008
#define MINI_EXT_SHARE_USBDL_RETN                       0x1009

#define TLV_SIZE_RECORD 0

#define REMAPPING_MASK (custom_RAM_baseaddr()-1)
#define BROM_USBDL_V2_TIMEOUT  (30)

/*************************************************************************
 * Structure definition
 *************************************************************************/

typedef struct
{
   kal_char       m_blDaSharedDataId[32];
   kal_uint32     m_payloadLength;
   kal_uint32     m_payload[3];
} BL_DA_SHARED_DATA_HEADER;

typedef struct
{
   kal_uint32     m_type;
   kal_uint32     m_length;
} BL_DA_SHARED_DATA_STRUCT;

typedef enum
{
   USBDL_NOT_TRIGGERED     = 0x00,
   USBDL_RESCUE_KEY,
   USBDL_KEY,
   USBDL_GPIO,
   USBDL_FLAG,
   USBDL_AUTO              = 0x81,
} USBDL_TRIGGER_REASON;

/*************************************************************************
 * External reference definition
 *************************************************************************/
 
extern void Connect_FactoryTool(void);
extern kal_uint32 custom_ROM_baseaddr(void);
extern kal_bool USBDL_UART_Init(void);
extern void USBDL_Release(void);
extern kal_bool USBDL_Update_USB_Download_Mode(void);
extern kal_bool USBDL_Is_USB_Download_Mode(void);
extern void INT_RestorePLL(void);
extern void WatchDogResetAll(void);
extern kal_uint32 SST_Get_Secinfo(kal_uint32 rom_base, kal_bool check_mac);
extern kal_int32 SST_VerifyImageContent(kal_uint32 secinfo_addr, kal_uint32 mac_addr, kal_bool bFactoryBin);
extern kal_int32 SST_VerifyExtBootloader(kal_uint32 ebl_addr, kal_uint32 ebl_len, kal_uint32 ebl_header_addr, kal_uint32 ebl_header_len);
extern void set_debug_level(LOG_LEVEL level);

extern void NorFlashBooting(void);
extern void InitRegionsExt(void);
extern void CacheDeinit(void);
extern void CacheInit(void);
extern void InitExt(void);
extern void GetFeatureCombination(void);
extern kal_bool CheckPairedVersion(void);
extern kal_bool USBDLKey_Pressed(void);
extern kal_uint32* SST_GetToken(void);
extern void CacheDeInitMini(void);
extern void SetWDTNormalResetFlag(void);
extern void InitFPU(void);
extern kal_bool BL_kbd_IsKeyPressed(kal_uint8 key);
extern void ShutDownModule(void);
extern kal_uint32 custom_get_bootloader_version(kal_uint8 *version, kal_uint32 len);
extern void SST_SetToken(kal_uint32 *pToken, kal_uint32 tokenLen);
extern kal_uint32 GetMainRegionStartBlock(void);
extern kal_bool CheckFeatureCombination(void);

#ifdef __SV5_ENABLED__
extern kal_uint32 LoadMauiBody(void);
extern BL_STATUS LoadMAUIFirstPart(void);
#endif



#if defined(__FOTA_DM__)
extern kal_uint32 bl_loadFOTAImage(void);
#endif

#if defined(__SERIAL_FLASH_STT_EN__)
extern void stt_main(void);
#endif
extern void BL_ScanSerialFlashBlocks(void);

#if defined(__SNAND_STT_EN__)
extern void stt_snand_main();
#endif


extern kal_uint32 g_Bl_Secure_Test;
extern const LOG_LEVEL bootloader_debug_level;

/*************************************************************************
 * Forward declearaion
 *************************************************************************/
kal_bool bl_Init_BL_DA_SharedData(void);
void SetBootupFlag(kal_uint32 flag);
kal_uint32* bl_Allocate_BL_DA_SharedData(kal_uint32 type, kal_uint32 size);
void SetRetnFlag(kal_uint32 flag);
void ClrRetnFlag(kal_uint32 flag);
void SetRetnTimeout(kal_uint32 time);
USBDL_TRIGGER_REASON USBDL_Detect(void);
kal_bool IsBromUSBDLDetectionFailed(void);


/*************************************************************************
 * Global variables definition
 *************************************************************************/

kal_uint32 g_mauiFeatureCombination = 0;
kal_uint32 g_randomSeed = 0;
kal_bool   g_bromCmdModeDisabled = KAL_FALSE;
kal_uint8  g_emi_param[2] = {0};

//Flag to control the flow
kal_uint32 g_bootupStatus   = BL_BOOTUP_FAIL_REASON_NONE;
kal_bool   g_bootupDisabled = KAL_FALSE;
kal_bool   g_usbdlDisabled  = KAL_FALSE;
kal_bool   g_carddlDisabled = KAL_FALSE;
kal_bool   g_enterCarddl    = KAL_FALSE;

kal_bool   g_enterFUNET     = KAL_FALSE;

#ifdef __EXT_BL_UPDATE__
BL_EXT_BL_UPDATE_INFO g_extBlUpdateInfo;
#endif /* __EXT_BL_UPDATE__ */

#ifdef __SV5_ENABLED__

#if defined(__COPY_BROM_BL_PARAM_TO_EXTERNAL_RAM__) && defined(__EXT_BOOTLOADER__)

BL_Param_v4 g_BROM_BL_Param;
BL_Param_v4 *g_pBROM_BL_Param = &g_BROM_BL_Param;

#else

BL_Param_v4 *g_pBROM_BL_Param = NULL;

#endif /* __COPY_BROM_BL_PARAM_TO_EXTERNAL_RAM__ && __EXT_BOOTLOADER__ */

#else

#pragma arm section rodata = "HEAD_BL"
const MTK_EXT_BL_INFO_v01 g_ExtBootloaderInfo = 
{
#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)

#if defined(__EBL_UPDATE_TOOL_SUPPORT_NAND__)
   "MTK_EBL_INFO_v02",
#else
   "MTK_EBL_INFO_v01",
#endif

#else

   "MTK_EBL_INFO_v02",

#endif

   BL_MAUI_PAIRED_VER,
   (FEATURE_COMBINATION | FEATURE_BL_ALWAYS_SUPPORT),
#if defined __NAND_FDM_50__   
   FDM_VERSION, 0, 0, DAL_VERISON        // FDM and DAL version
#else
   0, 0, 0, 0        // FDM and DAL version
#endif
};
#pragma arm section rodata

#endif /* __SV5_ENABLED__ */

#if defined (__BROM_USBDL_V2__) || defined(__FUNET_ENABLE__)
kal_uint32 g_usbdlRetnValue = 0xffffffff;   //Must use RW

static kal_bool g_power_latched = KAL_FALSE;
#endif /* __BROM_USBDL_V2__ */

#pragma arm section rwdata = "MINI_EXT_DA_SHARE", zidata = "MINI_EXT_DA_SHARE"

kal_uint32 g_mini_ext_da_share_buf[BL_DA_SHARED_DATA_MAX_SIZE/4];

#pragma arm section rwdata, zidata


/*************************************************************************
 * Main code
 *************************************************************************/

#ifdef __BL_SLIM_DIV__

kal_uint32 bl_slim_div(const kal_uint32 n, const kal_uint32 d, kal_uint32 *pR)
{
   kal_uint32 q=0, r=0;
   kal_int32 m;
   for(m=0x8000000; m; m>>=1)
   {
      r = r << 1;
      r |= (n&m) ? 1 : 0;
      if(r >= d)
      {
         r -= d;
         q |= m;
      }
   }

   if(pR)
   {
      *pR = r;
   }
   return q;
}

kal_uint32 bl_slim_mod(const kal_uint32 n, const kal_uint32 d)
{
   kal_uint32 r;
   bl_slim_div(n, d, &r);
   return r;
}

#endif


/**********************************************************
Description : Facility for BL-DA shared data, initialize structure
Input       : 
Output      : 
***********************************************************/
kal_bool bl_Init_TLV_Service(kal_uint32 buffAddr, kal_uint32 buffSize, const kal_char *pId)
{
   BL_DA_SHARED_DATA_HEADER *pSharedData = (BL_DA_SHARED_DATA_HEADER*)buffAddr;

   ASSERT(buffSize > sizeof(BL_DA_SHARED_DATA_HEADER));

   memset(pSharedData->m_blDaSharedDataId, 0, sizeof(pSharedData->m_blDaSharedDataId));
   strcpy(pSharedData->m_blDaSharedDataId, pId);
   pSharedData->m_payload[0] = TLV_SIZE_RECORD;
   pSharedData->m_payload[1] = 4;
   pSharedData->m_payload[2] = buffSize;
   pSharedData->m_payloadLength = sizeof(pSharedData->m_payload);
   
   return KAL_TRUE;
}

kal_uint32* bl_Traverse_TLV_Record(kal_uint32 buffAddr, kal_uint32 *it, kal_uint32 *pType, kal_uint32 *pSize)
{
   BL_DA_SHARED_DATA_HEADER *pSharedDataHeader = (BL_DA_SHARED_DATA_HEADER*)buffAddr;
   BL_DA_SHARED_DATA_STRUCT *pSharedData;

   if(*it == NULL)
   {
      *it = (kal_uint32)pSharedDataHeader->m_payload;
   }

   pSharedData = (BL_DA_SHARED_DATA_STRUCT*)((kal_uint32)*it + sizeof(BL_DA_SHARED_DATA_STRUCT) + ((BL_DA_SHARED_DATA_STRUCT*)*it)->m_length);

   if((kal_uint32)pSharedData - (kal_uint32)pSharedDataHeader->m_payload < pSharedDataHeader->m_payloadLength)
   {
      if(pType)
   {
         *pType = pSharedData->m_type;
   }
      if(pSize)
   {
         *pSize = pSharedData->m_length;
   }

      *it = (kal_uint32)pSharedData;

      return (kal_uint32*)(pSharedData+1);
   }

   return NULL;
}

kal_uint32* bl_Get_TLV_Record(kal_uint32 buffAddr, kal_uint32 type, kal_uint32 *pSize)
{
   BL_DA_SHARED_DATA_HEADER *pSharedDataHeader = (BL_DA_SHARED_DATA_HEADER*)buffAddr;
   BL_DA_SHARED_DATA_STRUCT *pSharedData;

   kal_uint32 n;

   ASSERT(pSharedDataHeader->m_payload[0] == TLV_SIZE_RECORD && pSharedDataHeader->m_payload[1] == 4);

   n = 3;
   while(n<pSharedDataHeader->m_payloadLength)
   {
      pSharedData = (BL_DA_SHARED_DATA_STRUCT*)((kal_uint32)(&pSharedDataHeader->m_payload) + n);

      if(pSharedData->m_type == type)
   {
         if(pSize)
   {
            *pSize = pSharedData->m_length;
   }   
         return (kal_uint32*)(pSharedData+1);
   }   

      n += pSharedData->m_length + sizeof(BL_DA_SHARED_DATA_STRUCT);
   }   

   return NULL;
}

/**********************************************************
Description : Facility for BL-DA shared data, allocate a new space
Input       : id of the requested record, and size of it
Output      : the pointer to the buffer for record
***********************************************************/
kal_uint32* bl_Allocate_TLV_Record(kal_uint32 buffAddr, kal_uint32 type, kal_uint32 size)
{
   BL_DA_SHARED_DATA_HEADER *pSharedDataHeader = (BL_DA_SHARED_DATA_HEADER*)buffAddr;
   BL_DA_SHARED_DATA_STRUCT *pSharedData;

   kal_uint32 tlvLen = pSharedDataHeader->m_payload[2];

   ASSERT(type != TLV_SIZE_RECORD);

   //Align to 4B
   size = ((size+3)>>2)<<2;

   if(pSharedDataHeader->m_payloadLength + (size + sizeof(BL_DA_SHARED_DATA_STRUCT)) > tlvLen)
   {
      return NULL;
         }
         
   pSharedData = (BL_DA_SHARED_DATA_STRUCT*)(&pSharedDataHeader->m_payload[pSharedDataHeader->m_payloadLength/4]);
   pSharedData->m_type   = type;
   pSharedData->m_length = size;
   
   pSharedDataHeader->m_payloadLength += (size + sizeof(BL_DA_SHARED_DATA_STRUCT));

   return (kal_uint32*)(pSharedData+1);
}


/**********************************************************
Description : Facility for BL-DA shared data, initialize structure
Input       : 
Output      : 
***********************************************************/
kal_bool bl_Init_MINI_EXT_SharedData(void)
{
   return bl_Init_TLV_Service((kal_uint32)g_mini_ext_da_share_buf, sizeof(g_mini_ext_da_share_buf), MINI_EXT_SHARED_DATA_ID);
}

/**********************************************************
Description : Facility for BL-DA shared data, allocate a new space
Input       : id of the requested record, and size of it
Output      : the pointer to the buffer for record
***********************************************************/
kal_uint32* bl_Allocate_MINI_EXT_SharedData(kal_uint32 type, kal_uint32 size)
{
   return bl_Allocate_TLV_Record((kal_uint32)g_mini_ext_da_share_buf, type, size);
}


#ifdef __MINI_BOOTLOADER__

kal_bool VerifyExtBootloader(kal_uint32 extBlAddr)
{

#ifdef __MTK_SECURE_PLATFORM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__SV5_ENABLED__)
/* under construction !*/
#if !defined(__BRINGUP_SUPPORT__)
/* under construction !*/
#if !defined(__16_3_SEG__) && !defined(__32_32_SEG__) || defined(__MTK_SECURE_PLATFORM__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif /* !__BRINGUP_SUPPORT__ */
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
/* under construction !*/
#if defined(__EBL_UPDATE_TOOL_SUPPORT_NAND__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif /* __SV5_ENABLED__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_SECURE_PLATFORM__ */

   return KAL_TRUE;
}

void JumpToExtBootloader(kal_uint32 extBlAddr)
{
   bl_Init_MINI_EXT_SharedData();

   //Prepare argument needs to be passed

   #define PASS_BUFFER_TO_EXT_BL(_ID, _P, _LEN) \
      memcpy(bl_Allocate_MINI_EXT_SharedData((_ID), (_LEN)), (void*)(_P), (_LEN))

   //This is the simplied version for convenience. User must make sure this variable is 4B aligned
   #define PASS_VARIABLE_TO_EXT_BL(_ID, _VAR) \
      if(sizeof(_VAR) <= 4) *(kal_uint32*)bl_Allocate_MINI_EXT_SharedData((_ID), sizeof(_VAR)) = *(kal_uint32*)(&(_VAR)); \
      else memcpy(bl_Allocate_MINI_EXT_SharedData((_ID), sizeof(_VAR)), &(_VAR), sizeof(_VAR))

#ifdef __SV5_ENABLED__

#ifdef __COPY_BROM_BL_PARAM_TO_EXTERNAL_RAM__
   PASS_VARIABLE_TO_EXT_BL(MINI_EXT_SHARD_BL_PARAM,                *g_pBROM_BL_Param);
#else
   PASS_VARIABLE_TO_EXT_BL(MINI_EXT_SHARD_BL_PARAM,                g_pBROM_BL_Param);   
#endif

   PASS_VARIABLE_TO_EXT_BL(MINI_EXT_SHARD_FEATURE_COMBINATION,     g_bootloader_gfh.gfh_arm_bl_info.m_feature_combination);
   PASS_VARIABLE_TO_EXT_BL(MINI_EXT_SHARD_FEATURE_COMBINATION_EXT, g_bootloader_gfh.gfh_arm_bl_info.m_feature_combination_ex);
#else
   PASS_VARIABLE_TO_EXT_BL(MINI_EXT_SHARD_FEATURE_COMBINATION,     g_ExtBootloaderInfo.m_feature_combination);
#endif

   PASS_VARIABLE_TO_EXT_BL(MINI_EXT_SHARD_RANDOM_SEED,             g_randomSeed);
   PASS_VARIABLE_TO_EXT_BL(MINI_EXT_SHARE_BL_HEADER,               BLHeader);

   PASS_BUFFER_TO_EXT_BL(MINI_EXT_SHARE_BL_TOKEN,                  (kal_uint32*)SST_GetToken(), sizeof(((BL_MAUI_ShareData*)(0))->m_bl_token));

   PASS_BUFFER_TO_EXT_BL(MINI_EXT_SHARE_EMI_PARAM,                 g_emi_param, sizeof(g_emi_param));

#ifdef __EXT_BL_UPDATE__
   PASS_VARIABLE_TO_EXT_BL(MINI_EXT_SHARE_EXT_BL_UPDATE_INFO,      g_extBlUpdateInfo);
#endif /* __EXT_BL_UPDATE__ */

#if defined(__BROM_USBDL_V2__) || defined(__FUNET_ENABLE__)
   PASS_VARIABLE_TO_EXT_BL(MINI_EXT_SHARE_USBDL_RETN,              g_usbdlRetnValue);
#endif /* __BROM_USBDL_V2__ */

#ifdef __SV5_ENABLED__
   if(extBlAddr != INVALID_START_ADDR)
   {
      extBlAddr += ((GFH_FILE_INFO_v1*)(extBlAddr))->m_jump_offset;
   }
#endif /* __SV5_ENABLED__ */

   CacheDeInitMini();

   BL_PRINT(LOG_INFO, "Jump to ExtBL, %x\n\r",extBlAddr);

   TS_END(TSID_BL_BOOTLOADER);

#ifdef __TIME_STAMP__
{
   kal_uint32 tsAddr, tsSize;

   TS_GetContext(&tsAddr, &tsSize);
   PASS_BUFFER_TO_EXT_BL(MINI_EXT_SHARE_BL_TIME_STAMP_RECORD, tsAddr, tsSize);
}
#endif

   JumpCmd(extBlAddr);
}

void USBDLPreSet(void)
{
#if defined(__USB_DOWNLOAD__) && defined(__BROM_USBDL_V2__)
   g_usbdlRetnValue = *RETN_FLAG;

   //Set it to BROM USBDL, 10s
   SetRetnTimeout(10);
   SetRetnFlag(RETN_USBDL_BY_FLAG_EN);
   ClrRetnFlag(RETN_USBDL_TYPE_MASK);

#ifdef MT6250   
   SetRetnFlag(RETN_USBDL_TRIGGERED_BY_BL);
#endif
   
#elif defined(__FUNET_ENABLE__)
	g_usbdlRetnValue = *RETN_FLAG;
#endif /* __USB_DOWNLOAD__ && __BROM_USBDL_V2__ */   
}

void MiniBLErrorHandler(void)
{
   BL_PRINT(LOG_ERROR, "MiniBL is dead!!\r\n");

#if defined(__USB_DOWNLOAD__) && defined(__BROM_USBDL_V2__)
   //Trigger BROM USBDL and try to recover this situation
   WatchDogResetAll();
#endif

}

#endif /*__MINI_BOOTLOADER__ */


/*************************************************************************
 * Main code of both of Bootloaders
 *************************************************************************/

void TriggerMetaMode(void)
{
   (*(volatile kal_uint16 *)BOOT_CONFIG_ADDR) |= 0x01;
}
void TriggerExternalModemMetaMode(void)
{
   (*(volatile kal_uint16 *)BOOT_CONFIG_ADDR) |= 0x11;
}

kal_bool IsUsbATModeEnabled(void)
{
   return ((*(volatile kal_uint16 *)BOOT_CONFIG_ADDR) & 0x04) ? KAL_TRUE : KAL_FALSE;
}

kal_bool IsMetaModeEnabled(void)
{
   return ((*(volatile kal_uint16 *)BOOT_CONFIG_ADDR) & 0x01) ? KAL_TRUE : KAL_FALSE;
}

kal_bool IsFactoryModeToMAUI(void)
{
   return (IsMetaModeEnabled() || IsUsbATModeEnabled()) ? KAL_TRUE : KAL_FALSE;
}

#ifdef __USBDL_IN_BOOTROM__

kal_bool IsUSBEstablishedInBootROM(void) 
{
#ifdef __SV5_ENABLED__
   return (g_pBROM_BL_Param->m_brom_flags & BL_PARAM_USB_COM_ENABLED) ?  KAL_TRUE : KAL_FALSE;
#else
   return ((*(volatile kal_uint16 *)BOOT_CONFIG_ADDR) & 0x02) ? KAL_TRUE : KAL_FALSE;
#endif
}
#endif /* __USBDL_IN_BOOTROM__ */

kal_bool IsInWithOutBatteryMode(void)
{
   return ((*(volatile kal_uint16 *)BOOT_CONFIG_ADDR) & 0x08) ? KAL_TRUE : KAL_FALSE;
}

#ifdef __BROM_USBDL_V2__
void SetRetnFlag(kal_uint32 flag)
{
   *RETN_FLAG_SET = (0x4e000000 | flag);
}

void ClrRetnFlag(kal_uint32 flag)
{
   *RETN_FLAG_CLR = (0x4e000000 | flag);   
}

void SetRetnTimeout(kal_uint32 time)
{
   *RETN_DAT0 = time;
}

void ClearUSBDLFlag(void)
{
#ifdef MT6250   
   ClrRetnFlag(RETN_USBDL_TRIGGERED_BY_BL);
#endif            
   ClrRetnFlag(RETN_USBDL_BY_FLAG_EN|RETN_USBDL_TYPE_MASK);   
}

void RestoreUSBDLFlag(void)
{
   ClearUSBDLFlag();
   SetRetnFlag(g_usbdlRetnValue & (RETN_USBDL_BY_FLAG_EN|RETN_USBDL_TYPE_MASK));
}

#endif /* __BROM_USBDL_V2__ */

/*************************************************************************
 * Main code of ExtBootloader
 *************************************************************************/

#ifdef __EXT_BOOTLOADER__

#if defined(__USB_DOWNLOAD__) || defined(__UART_DOWNLOAD__)

static kal_uint32 usbdl_timer_start = 0xffffffff;
static enum {USBDL_TIMER_STOP, USBDL_TIMER_RUNNING} usbdl_timer_state = USBDL_TIMER_STOP;

kal_bool USBDLGPIO_Enabled(void)
{
   /* When the GPIO is connected to ground, enable USBDL */
#ifdef __CUST_NEW__   
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
   DCL_HANDLE handle;
   GPIO_CTRL_READ_T data;

   handle = DclGPIO_Open(DCL_GPIO, gpio_usbdl_pin);
   DclGPIO_Control(handle, GPIO_CMD_READ, (DCL_CTRL_DATA_T*)&data);
   DclGPIO_Close(handle);

   if(data.u1IOData == 0)
   {
      return KAL_TRUE;
   }
   
#endif   
#endif /* __CUST_NEW__ */

   return KAL_FALSE;
}

void USBDL_Start_Timer(void)
{
   if ( usbdl_timer_state == USBDL_TIMER_STOP )
   {
      usbdl_timer_state = USBDL_TIMER_RUNNING;
      usbdl_timer_start = INT_GetCurrentTime();
   }
}

void USBDL_Stop_Timer(void)
{
   usbdl_timer_state = USBDL_TIMER_STOP;
}


kal_bool USBDL_Is_Timeout_Ex(kal_uint32 timeoutMs)
{
   kal_uint32 elapsed;
   
   switch (usbdl_timer_state)
   {
      case USBDL_TIMER_STOP:
         return KAL_FALSE;
      
      case USBDL_TIMER_RUNNING:
         elapsed = INT_GetCurrentTime() - usbdl_timer_start;

         //32K, elapsed * (1/32K) is second based
         if ((elapsed>>10)*1000 < timeoutMs*32 )
            return KAL_FALSE;
         
         return KAL_TRUE;
   }

   return KAL_FALSE;
}

kal_bool USBDL_Is_Timeout(void)
{
   if (usbdlauto_timeout != NO_USBDL_AUTO_TIMEOUT)
   {
      return USBDL_Is_Timeout_Ex(usbdlauto_timeout);
   }

   return KAL_FALSE;
}


kal_bool USBDL_Cable_Detected(void)
{
#ifdef __DRV_EXT_CHARGER_DETECTION__
   extern kal_bool MU_BootUP_USB_Detect(void);
   return MU_BootUP_USB_Detect();
#else
   extern kal_bool USBDL_Cable_IN(void);
   return USBDL_Cable_IN();
#endif /* __DRV_EXT_CHARGER_DETECTION__ */      
	
}

kal_bool USBDL_76DLFlag_Detect(void)
{
#if defined(MT6276) || defined(MT6270)
   kal_bool firstBootup = KAL_FALSE;   	
   
#if 0   	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

   if( ((*(volatile unsigned short *)(RTC_base + 0x50)) != 0xa357) || ((*(volatile unsigned short *)(RTC_base + 0x54)) != 0x67d2) )
   {
       firstBootup = KAL_TRUE;
   }

   if(firstBootup == KAL_FALSE)
   {
   	 if ((*(volatile unsigned short *)(RTC_base + 0x60)) & 0x1)	//For data card to active USB COM PORT       
   	 {
         return KAL_TRUE;
      }
   }
   else
   {
       *(volatile unsigned short *)(RTC_base + 0x68) = 0x586a;
       *(volatile unsigned short *)(RTC_base + 0x74) = 0x0001;
       while((*(volatile unsigned short *)(RTC_base + 0x00)) & 0x40) {}; // Timeout period: 120usec
       *(volatile unsigned short *)(RTC_base + 0x68) = 0x9136;
       *(volatile unsigned short *)(RTC_base + 0x74) = 0x0001;
       while((*(volatile unsigned short *)(RTC_base + 0x00)) & 0x40) {}; // Timeout period: 120usec
   	
   	  //Clear SPARE 2
   	  *(volatile unsigned short *)(RTC_base + 0x60) = 0x0000;
   	  *(volatile unsigned short *)(RTC_base + 0x74) = 0x0001;
   }
#endif

   return KAL_FALSE;
   
}

/* Exported API for continously checking if the triggering condition remains,
 * including the 30s/auto-detection timeout handling
 */
kal_bool USBDL_Ready_To_Enter_DLMode(void)
{
   static USBDL_TRIGGER_REASON triggeredReason = USBDL_NOT_TRIGGERED;
   static kal_bool explicitUSBDLDetected = KAL_FALSE;

#if defined(__USBDL_IN_BOOTROM__) && !defined(__BROM_USBDL_V2__)
   if (IsUSBEstablishedInBootROM())
   {
      //Since BootROM has established the connection, no more tests      
      return IsFactoryModeToMAUI() ? KAL_FALSE : KAL_TRUE;
   }
#endif /* __USBDL_IN_BOOTROM__  && !__BROM_USBDL_V2__ */

   if(usbdl_holding_mode)
   {
      if(explicitUSBDLDetected)
      {
         return KAL_TRUE;
      }
   }

   //For auto-detection and BROM USBDL v2's timeout
   USBDL_Start_Timer();

   //Aligned with BootROM's behavior -- "detect once, trigger always until timedout"
#if defined(__BROM_USBDL_V2__)
   if(triggeredReason == USBDL_NOT_TRIGGERED)
#endif      
   {
      triggeredReason = USBDL_Detect();

      //Explict USBDL conditions
      if(triggeredReason != USBDL_NOT_TRIGGERED && triggeredReason != USBDL_AUTO)
      {
         explicitUSBDLDetected = KAL_TRUE;
         return KAL_TRUE;
      }
   }

   //No explicit condition now, check timeout
   
   if(explicitUSBDLDetected)
   {
      //Explicit condition was found, keep it waiting for BROM v2
#if defined(__BROM_USBDL_V2__)      
      if(USBDL_Is_Timeout_Ex(BROM_USBDL_V2_TIMEOUT*1000) == KAL_FALSE)
      {
         return KAL_TRUE;
      }
#endif      
   }
   else
   {
      //Try auto-timeout if no explicit condition has been ever found      
      if(triggeredReason == USBDL_AUTO && USBDL_Cable_Detected() && USBDL_Is_Timeout() == KAL_FALSE)
      {
         return KAL_TRUE;
      }
   }

   return KAL_FALSE;
}

#define Delay_Count      324675
static const volatile kal_uint8  startcmd_len = 4;
static const kal_uint8  startcmd[4] = {
	0xa0,
	0x0a,
	0x50, 
	0x05
};


kal_uint8 USBDL_CheckStartCmd(void)
{
   kal_uint8  startcmd_index = 0;
   kal_uint32 count = Delay_Count;
   kal_uint8  data;
   kal_uint8  GetStartCmd = KAL_FALSE;
     
   while(count || usbdl_holding_mode)
   {
#ifdef __USB_DOWNLOAD__     
      data = USBDL_GetUARTByte_Ext(KAL_FALSE) ;
      USBDL_PutUARTByte_Ext(~data,KAL_FALSE);
      USBDL_PutUARTByte_Complete_Ext(KAL_FALSE);
      if(USBDL_Ready_To_Enter_DLMode() == KAL_FALSE)
      {
         break;
      }
#elif __UART_DOWNLOAD__      
      data = GetUARTByte() ;
      PutUARTByte(~data);
      PutUARTByte_Complete();
#else
      #error "Impossible"
#endif
         
      if (data == startcmd[startcmd_index])
      {
         count = Delay_Count;
         startcmd_index++;

         if (startcmd_index == startcmd_len)
         {
            GetStartCmd = KAL_TRUE;
            break;
         }
      }
      else
      {
         startcmd_index = 0;
      }
      count--;
   }
   return GetStartCmd;
}

/**********************************************************
Description : Major Procedure for USB Download
Input       : None
Output      : None
***********************************************************/
void USBDL_Main(void)
{
   kal_bool skipDownload = KAL_FALSE;
  
   /* MAIN 1 : Check USB DL KEY Pressed */
   if (USBDL_Ready_To_Enter_DLMode() == KAL_FALSE)
   {
      /* go to boot maui */
      return;
   }

   dbg_print("Open COM port...\n\r");

   /* MAIN 2 : Setup USB Virtual COM */

#ifdef __DRV_EXT_CHARGER_DETECTION__
   {
      extern kal_bool MU_BootUP_USB_Detect(void);
      MU_BootUP_USB_Detect();
   }
#endif /* __DRV_EXT_CHARGER_DETECTION__ */      

#ifdef __USB_DOWNLOAD__
#if defined(__USBDL_IN_BOOTROM__) && !defined(__BROM_USBDL_V2__)
   if (IsUSBEstablishedInBootROM())
   {
      USBDL_USB_Config_Init();
   }
   else
#endif
   {
      USBDL_UART_Init();      
   }

   /* MAIN 3 : Confirm COM port is ready */
   if (USBDL_Is_USB_Download_Mode() == KAL_FALSE )
   {
      /* User Abort the USB Download */
      skipDownload = KAL_TRUE;
   }
#endif

   /* MAIN 4 : Check Start Cmd */
#if defined(__USBDL_IN_BOOTROM__) && !defined(__BROM_USBDL_V2__) && defined(__USB_DOWNLOAD__)
   if(!IsUSBEstablishedInBootROM())
#endif      
   {
      if (skipDownload == KAL_FALSE && USBDL_CheckStartCmd() == KAL_FALSE)
      {
         /* User Run Unknown Program on PC side */
         skipDownload = KAL_TRUE;
      }
   }

   /* MAIN 5 : BOOTROM-like procedure start */
   if (skipDownload == KAL_FALSE)
   {
#ifdef __USBDL_IN_BOOTROM__
      /* Reset the boot config register since it may be set due to GPIO init */
      *(volatile kal_uint16 *)BOOT_CONFIG_ADDR = 0;
#endif

#if defined(__MTK_SECURE_PLATFORM__) && defined(_NAND_FLASH_BOOTING_) && !defined(__SV5_ENABLED__)
/* under construction !*/
#endif /* __MTK_SECURE_PLATFORM__ && _NAND_FLASH_BOOTING_ */

#if defined(__MTK_SECURE_PLATFORM__) && defined(__SV5_ENABLED__)
/* under construction !*/
#endif

      USBDL_Stop_Timer();

      if(usbdl_holding_mode)
      {
         extern void USBDL_SetWDTMode(kal_bool wdtkick);
         USBDL_SetWDTMode(KAL_FALSE);
         WacthDogDisable();
      }

      bl_Init_BL_DA_SharedData();

#if defined(__TC01__)   	 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if defined(__EXT_BL_UPDATE__)
      {
         BL_EXT_BL_UPDATE_INFO *pExtBlUpdateInfo = (BL_EXT_BL_UPDATE_INFO*) bl_Allocate_BL_DA_SharedData(BL_DA_SHARED_DATA_ID_EXT_BL_UPDATE_INFO, sizeof(BL_EXT_BL_UPDATE_INFO));
         memcpy(pExtBlUpdateInfo, &g_extBlUpdateInfo, sizeof(BL_EXT_BL_UPDATE_INFO));
      }   
#endif /* __EXT_BL_UPDATE__ */

#if defined(__BROM_USBDL_V2__)
      RestoreUSBDLFlag();
#endif

      Connect_FactoryTool();

      /* if it reach here, boot maui directly (Meta mode) */
      SetBootupFlag(BL_INFO_USBDL_IN_BL_CONNECTED);

#if defined(__SECURE_USB_DOWNLOAD__) || defined(__SECURE_UART_DOWNLOAD__)
      {
         extern kal_bool g_BlFirstDownload;
         if(g_BlFirstDownload != KAL_TRUE)
         {
           SetBootupFlag(BL_INFO_SUSBDL_IN_BL_ENABLED);
         } 
      }
#endif

   }
   else
   {
      if (USBDL_Is_Timeout() == KAL_FALSE)
      {
         /* Not because of timeout. Reset the phone */
         dbg_print("Key or GPIO release before USBDL initialization completed, reset\n\r");

         SetWDTNormalResetFlag();

         WatchDogResetAll();
      }

      // Go on with the bootup procedure since it's caused by a time-out of implicit USBDL      

#ifdef __USB_DOWNLOAD__
      USBDL_Release();
#endif

   }

   //Return and continue the boot-up
}

kal_bool KeyCombinationPressed(kal_uint8 key1, kal_uint8 key2)
{
   if(key1 != DEVICE_KEY_NONE)
   {
      if(!BL_kbd_IsKeyPressed(key1))
      {
         return KAL_FALSE;
      }
      if(key2 != DEVICE_KEY_NONE && !BL_kbd_IsKeyPressed(key2) )
      {
         return KAL_FALSE;
      }
   }
   else
   {
      return KAL_FALSE;
   }

   return KAL_TRUE;
}

USBDL_TRIGGER_REASON USBDL_Detect(void)
{
   USBDL_TRIGGER_REASON detected = USBDL_NOT_TRIGGERED;

#if defined(__BROM_USBDL_V2__)
   if(IsBromUSBDLDetectionFailed())
   {
      BL_PRINT(LOG_INFO, "BROM tried but not detected cable or tool, skip it this time\r\n");
      return USBDL_NOT_TRIGGERED;
   }
#endif  

#if defined(__BMT_2_0_ARCHITECTURE__)
   if(USBDL_Cable_Detected())
   {
	   DCL_BOOL vbat_cc_det_status = DCL_FALSE;
	   bl_chr_control_handler(BMT_BL_CHARGING_CMD_GET_CC_STATUS, &vbat_cc_det_status);
	   if(vbat_cc_det_status == DCL_FALSE)
	   {
	      BL_PRINT(LOG_INFO, "Still in preCC stage, skip it this time\r\n");
	      return USBDL_NOT_TRIGGERED;
	   }
	}
#endif

   //Check all possible conditions to enter USBDL

   //Rescue key has the highest priority
#if defined(__BROM_USBDL_V2__)
   if(KeyCombinationPressed(usbdlkey_rescue_position, usbdlkey_rescue_position2))
   {
      detected = USBDL_RESCUE_KEY;
   }
   else
#endif /* __BROM_USBDL_V2__ */

   //Detect flags from MAUI
#if defined(__BROM_USBDL_V2__)
   if((g_usbdlRetnValue & RETN_USBDL_BY_FLAG_EN) &&
      (g_usbdlRetnValue & RETN_USBDL_TYPE_MASK))
   {
      detected = USBDL_FLAG;
   }
   else 
#else
   if(USBDL_76DLFlag_Detect())
   {
      detected = USBDL_FLAG;
   }
   else
#endif /* __BROM_USBDL_V2__ */   

   //GPIO
#ifdef __CUST_NEW__
   if (gpio_usbdl_pin != NO_USBDL_GPIO && USBDLGPIO_Enabled() == KAL_TRUE)
   {
      detected = USBDL_GPIO;
   }
   else
#endif /* __CUST_NEW__ */

   //Keypad, normal download
   if(KeyCombinationPressed(usbdlkey_position, usbdlkey_position2))
   {
      detected = USBDL_KEY;
   }
   else

   //Auto-timeout, lowest priority
   if(usbdlauto_timeout != NO_USBDL_AUTO_TIMEOUT && USBDL_Cable_Detected())
   {
      detected = USBDL_AUTO;
   }

   return detected;   
}


#ifdef __MTK_INTERNAL__
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
#if defined(__BROM_USBDL_V2__)       
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
#if defined(__SECURE_USB_DOWNLOAD__)
/* under construction !*/
#endif
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
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__BROM_USBDL_V2__)       
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_INTERNAL__ */

#ifdef __BROM_USBDL_V2__

void InitiateBromUSBDL(USBDL_TRIGGER_REASON triggerReason)
{
   kal_uint32 timeout = 0;

   switch(triggerReason)
   {
   case USBDL_RESCUE_KEY:
   case USBDL_KEY:
   case USBDL_GPIO:
   case USBDL_FLAG:
      if(usbdl_holding_mode)
      {
         timeout = 0xff;
      }
      else
      {

         timeout = BROM_USBDL_V2_TIMEOUT;
      }
      break;

   case USBDL_AUTO:
      timeout = usbdlauto_timeout/1000;
      break;

   default:
      ASSERT(0);
   }

   SetRetnTimeout(timeout);
   SetRetnFlag(RETN_USBDL_BY_FLAG_EN);
   ClrRetnFlag(RETN_USBDL_TYPE_MASK);

#ifdef MT6250
   SetRetnFlag(RETN_USBDL_TRIGGERED_BY_BL);
#endif

   BL_PRINT(LOG_INFO, "Launch BROM USBDL (%ds)\r\n\r\n\r\n\r\n\r\n", timeout);

   SetWDTNormalResetFlag();
   WatchDogResetAll();

   while(1);
}

kal_bool IsBromUSBDLDetectionFailed(void)
{
#ifndef MT6250
   return (g_pBROM_BL_Param->m_brom_flags & BL_PARAM_BROM_USBDL_FAILED) ? KAL_TRUE : KAL_FALSE;
#else
   //MT6250 BootROM doesn't has this flag, use another retention bit instead
   return (g_usbdlRetnValue & RETN_USBDL_TRIGGERED_BY_BL) ? KAL_TRUE : KAL_FALSE ;
#endif
}

#endif /* __BROM_USBDL_V2__ */

#endif /* __USB_DOWNLOAD__ || __UART_DOWNLOAD__ */

void CheckForOpenedUSBDLConn(void)
{
#if defined(__USBDL_IN_BOOTROM__)  
#if !defined(__USB_DOWNLOAD__) || defined(__BROM_USBDL_V2__)
   //It is not normal since Tool needs Bootloader to do Secure USBDL, which is, however, not enabled or correct
   if (IsUSBEstablishedInBootROM() && !IsFactoryModeToMAUI())                                       
   {    
      BL_PRINT(LOG_ERROR, "BROM requested doing DL, beyond capbility\n\r");
#if defined(__BROM_USBDL_V2__)
      ClearUSBDLFlag();
#endif
      SetWDTNormalResetFlag();                                                                     
      WatchDogResetAll();                                                                          
   }  
#endif
#endif
}

#if defined(__DUAL_TALK_MODEM_SUPPORT__)
kal_bool GPIO_TRIGGER_META()
{
   extern const char gpio_bootloader_meta_pin;
   DCL_HANDLE handle;
   GPIO_CTRL_READ_T data;
   handle = DclGPIO_Open(DCL_GPIO, gpio_bootloader_meta_pin);
   DclGPIO_Control(handle, GPIO_CMD_SET_DIR_IN, 0);
   DclGPIO_Control(handle, GPIO_CMD_READ, (DCL_CTRL_DATA_T*)&data);
   DclGPIO_Close(handle);
   if(data.u1IOData == 1)
   {
      return KAL_TRUE;
   }
   return KAL_FALSE;
}
#endif
/**********************************************************
Description : Major Procedure for Factory Purpose
Input       : None
Output      : None
***********************************************************/
void FactoryProcedure(void)
{
   TS_BEGIN(TSID_BL_FACTORY_PROCEDURE);
   
   InitFPU();

   if(metakey_position != NO_META_KEY && BL_kbd_IsKeyPressed(metakey_position))
   {
      BL_PRINT(LOG_INFO, "Fast META triggered\n\r");
      SetBootupFlag(BL_FAST_META_TRIGGERED);      
      TriggerMetaMode();
      return;
   }
#if defined(__DUAL_TALK_MODEM_SUPPORT__)
   if(GPIO_TRIGGER_META())
   {
	 dbg_print( "GPIO META triggered\n\r");
     SetBootupFlag(BL_FAST_META_TRIGGERED);      
     TriggerExternalModemMetaMode();
     return;
   }
#endif
   
   CheckForOpenedUSBDLConn();
      
#if defined(__USB_DOWNLOAD__) || defined(__UART_DOWNLOAD__)
   if (!g_usbdlDisabled)
   {
#if __MTK_INTERNAL__       
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_INTERNAL__ */

#if defined(__BROM_USBDL_V2__) 

      if(!IsFactoryModeToMAUI())
      {
         USBDL_TRIGGER_REASON usbdlTriggered = USBDL_Detect();         

#if __MTK_INTERNAL__
/* under construction !*/
#endif

         if(usbdlTriggered != USBDL_NOT_TRIGGERED)
         {
            //If Bootloader supports S-USBDL, then only go to BROM when Rescue mode is detected
            //Or always go to BROM dirtectly since BROM can provide all we need;
#if !defined(__SECURE_USB_DOWNLOAD__)         
            InitiateBromUSBDL(usbdlTriggered);
#else
            if(usbdlTriggered == USBDL_RESCUE_KEY)
            {
               InitiateBromUSBDL(usbdlTriggered);
            }

            USBDL_Main();
#endif
         }
         else
         {
            ClearUSBDLFlag();
         }
      }
      else
      {
         BL_PRINT(LOG_INFO, "META mode detected, go to MAUI directly\r\n");
      }

      //Wait for tools' ready
      ClearUSBDLFlag();
      
#else

      //BROM USBDL v1 or legacy BL USBDL part
      USBDL_Main();

#endif

   }
   
#endif // __USB_DOWNLOAD__|| __UART_DOWNLOAD__

   TS_END(TSID_BL_FACTORY_PROCEDURE);

}



/**********************************************************
Description : Major Procedure for Card download
Input       : None
Output      : None
***********************************************************/
void CardDLProcedure(void)
{
#if defined(__CARD_DOWNLOAD__)
   if( g_carddlDisabled )
   {
      return;
   }

   TS_BEGIN(TSID_BL_CARD_DOWNLOAD_PROCEDURE);

   if( bl_IsCardDownloadGoing() )
   {
      g_enterCarddl = KAL_TRUE;
      g_bootupDisabled = KAL_TRUE;
      g_bootupStatus = BL_BOOTUP_FAIL_REASON_UPDATE_IN_PROGRESS;
   }
   
   if (g_enterCarddl || bl_CardDownloadTriggered() )
   {
      BL_CD_ERROR_CODE status;
      
      WacthDogRestart();
      status = bl_UpdateMain(g_bootupDisabled);

      if(status == BL_CD_ERROR_NONE)
      {
         //Impossible to get here. 
      }
      else if(status == BL_CD_ERROR_NO_CARD_FOUND || status == BL_CD_ERROR_NO_DL_PACKAGE_FOUND)
      {
         //Continue bootup
      }
      else
      {
         dbg_print("CDL error:%d\n\r", status);
         while(1);
      }
   }

   TS_END(TSID_BL_CARD_DOWNLOAD_PROCEDURE);

#endif // __CARD_DOWNLOAD__
}



kal_bool bl_FUNET_Triggered()
{
	// full download
	if(g_usbdlRetnValue & RETN_FUNET_FULL_DL_EN)
    {
		return KAL_TRUE;
	}
	// partial download (diff package)
	else if(g_usbdlRetnValue & RETN_FUNET_PARTIAL_DL_EN)
	{
		return KAL_TRUE;
	}
	else
	{
		return KAL_FALSE;
	}
}


kal_bool bl_FUNET_IsGoing()
{
#if defined(__FUNET_ENABLE__)
	return bl_IsFUNETGoing();
#else
	return KAL_FALSE;
#endif
	
}

#if defined(__FUNET_ENABLE__) || defined(__GPS_FW_UPDATE_SUPPORT__)
void bl_DL_latch_power()
{
    if(!g_power_latched)
   {     
       /* HW initialization */
      DclPW_Initialize();
      
      //GPIO_init();          //Not init GIPO here or other one's setting will be overwritten
      //DclGPIO_Initialize();

      //DclPWM_Initialize();
      //PWM_initialize();
      //DclPMU_Initialize();

      
      BL_PRINT(LOG_DEBUG, "[FUNET]Latch power start...\n\r");
      {
         DCL_HANDLE rtc_handler;
         DCL_HANDLE pw_handle;

         //before call dclpw, rtc is needed to be initialized
         rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);

         BL_PRINT(LOG_DEBUG, "[FUNET]Latch power rtc_handler  = %d \n\r", rtc_handler);
         
         DclRTC_Control(rtc_handler, RTC_CMD_SETXOSC, (DCL_CTRL_DATA_T *)NULL);
         DclRTC_Control(rtc_handler, RTC_CMD_HW_INIT, (DCL_CTRL_DATA_T *)NULL);
         DclRTC_Close(rtc_handler);

         //Use dclpw to latch the power
         pw_handle=DclPW_Open(DCL_PW, FLAGS_NONE);
         
         BL_PRINT(LOG_DEBUG, "[FUNET]Latch power pw_handle  = %d \n\r", pw_handle);
         
         DclPW_Control(pw_handle,PW_CMD_POWERON,NULL);
         DclPW_Close(pw_handle);
      }

      g_power_latched = KAL_TRUE;
      BL_PRINT(LOG_DEBUG, "[FUNET]Latch power done...\n\r");
    }
}
#endif 

#if defined(__GPS_FW_UPDATE_SUPPORT__)
#define GPS_MARKER_FILE_NAME    (L"Z:\\gps_image_marker")  // (L"Z:\\@fota_gps\\gps_image_marker")
#define GPS_MARKER_NUM 32
#define GPS_MARKER (0x54454E46)
kal_bool bl_FUNET_GPS_FW_Triggered()
{
    if(g_usbdlRetnValue & RETN_FUNET_GPS_FW_DL_EN)
    {
        return KAL_TRUE;
    }
}

kal_bool bl_FUNET_GPS_IsGoing()
{
	kal_int32 fHandle;
	kal_int32 marker[GPS_MARKER_NUM], read_len, read_ret;
	kal_int32 i;

	fHandle = FS_Open(GPS_MARKER_FILE_NAME, FS_READ_ONLY);
	if (fHandle < 0)
	{
		return KAL_FALSE;
	}
	
	read_ret = FS_Read(fHandle, marker, sizeof(marker), &read_len);

	FS_Close(fHandle);
	
	if (read_ret == FS_NO_ERROR && read_len == sizeof(marker))
	{
		for (i = 0; i < GPS_MARKER_NUM; i++)
		{
			if (marker[i] != GPS_MARKER)
			{
				break;
			}
		}
		if (i >= GPS_MARKER_NUM)
		{
			return KAL_TRUE;
		}
		else
		{
			return KAL_FALSE;
		}
	}
	else
	{
		return KAL_FALSE;
	}
	
}

void bl_FUNET_GPS_update()
{
	kal_int32 fHandle;
	kal_int32 marker[GPS_MARKER_NUM], read_len;
	kal_int32 i;

	BL_PRINT(LOG_DEBUG, "[FUNET]bl_FUNET_GPS_update enter \n\r");
	fHandle = FS_Open(GPS_MARKER_FILE_NAME, 0x00020000 /* FS_CREATE_ALWAYS */);\

    BL_PRINT(LOG_DEBUG, "[FUNET]bl_FUNET_GPS_update, file open err = %d \n\r", fHandle);
	if (fHandle >= 0)
	{
		for (i = 0; i < GPS_MARKER_NUM; i++)
		{
			marker[i] = GPS_MARKER;
		}
		FS_Write(fHandle, marker, sizeof(marker), &read_len);
		FS_Close(fHandle);
	}
	else
	{
	    BL_PRINT(LOG_DEBUG, "[FUNET]Fail to open gps marker file  \n\r");
		//do {NULL;} while (1);
	}
}

#endif

void FUNETProcedure(void)
{
#if defined(__GPS_FW_UPDATE_SUPPORT__)
    kal_int32 ret;
#endif

    BL_PRINT(LOG_DEBUG, "[FUNET]FUNETProcedure enter \n\r");
    
#if defined(__GPS_FW_UPDATE_SUPPORT__)   
    if (bl_FUNET_GPS_FW_Triggered() || bl_FUNET_GPS_IsGoing())
    {
        BL_PRINT(LOG_DEBUG, "[FUNET]Enter gps FW upgrade process \n\r");
        // burn GPS FW.
        if (bl_FUNET_GPS_IsGoing() == KAL_FALSE)
    	{
    		bl_FUNET_GPS_update();
    	}

        bl_DL_latch_power();
        WacthDogDisable();
		ret = GPS_DL();
		BL_PRINT(LOG_DEBUG, "[FUNET]GPS DL result = %d \n\r", ret);
		if (ret == GPS_FW_DOWNLOAD_OK)
		{
			// delete marker file
			FS_Delete(GPS_MARKER_FILE_NAME);
		}

        // TODO: clear flag after succeed to upgrade.
        ClrRetnFlag(RETN_FUNET_GPS_FW_DL_EN);
    }
#endif

#if defined(__FUNET_ENABLE__) && defined(__SV5_ENABLED__) 

	if( bl_FUNET_IsGoing() ) {
      g_enterFUNET = KAL_TRUE;
      g_bootupDisabled = KAL_TRUE;
      g_bootupStatus = BL_BOOTUP_FAIL_REASON_FUNET_IN_PROGRESS;
	}
    
    BL_PRINT(LOG_DEBUG, "[FUNET]before check trigger flag, g_usbdlRetnValue = %d\n\r", g_usbdlRetnValue);
	if(g_enterFUNET || bl_FUNET_Triggered())
	{
	   BL_FUNET_ERROR_CODE status;
       
       BL_PRINT(LOG_DEBUG, "[FUNET]start to update \n\r");

       bl_DL_latch_power();
       
	   WacthDogRestart();
	   status = bl_UpdateMain(g_bootupDisabled);
		
	   if(status == BL_FUNET_ERROR_NONE)
	   {
		  //Impossible to get here. 
	   }
	   else if(status == BL_FUNET_ERROR_NO_CARD_FOUND || status == BL_FUNET_ERROR_NO_DL_PACKAGE_FOUND)
	   {
		  //Continue bootup
	   }
	   else
	   {
		  dbg_print("FUNET error%d\n\r", status);
		  while(1);
	   }
	}


#endif /* __FUNET_ENABLE__ && __SV5_ENABLED__ */

}

#pragma arm section code = "INTERNCODE"

/**********************************************************
Description : Post process before jumping
Input       : None
Output      : None
***********************************************************/
void PostProcess(void)
{
#if defined(MT6268T) || defined(MT6268H)
   {
      kal_uint32 delay;         

      *(volatile kal_uint32 *)0x80010060 = 3;

      /* delay for a while to wait for EMI remapping takes effect */
      for (delay = 0; delay < 5000; delay++) {
      }
   }
#else   /* MT6268T || MT6268H */

#if defined(__USB_DOWNLOAD__) && defined(__BROM_USBDL_V2__)       
   BL_PRINT(LOG_INFO, "Out Retn = (%d,%d), %d\r\n", (*RETN_FLAG&RETN_USBDL_BY_FLAG_EN)?1:0, (*RETN_FLAG&RETN_USBDL_TYPE_MASK)?1:0, (*RETN_FLAG&RETN_USBDL_TRIGGERED_BY_BL)?1:0);
#endif

   CheckUARTSendEnd();
#endif   /* MT6268T || MT6268H */

}

/**********************************************************
Description : Procedures for boot and handover to next ROM
Input       : None
Output      : None
***********************************************************/

#ifdef __SV5_ENABLED__

kal_uint32 LoadAndVerifyNextBinary(kal_bool *pDoRemap)
{
   kal_uint32 targetAddr = INVALID_START_ADDR;

#if defined(__FOTA_DM__)

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)

   /* NAND FOTA support */
   targetAddr = LoadFotaOnNand();

#else

   /* NOR FOTA support */
   targetAddr = bl_loadFOTAImage();
   *pDoRemap = KAL_TRUE;   /* must be executed in internal RAM since remapping register is changed */

#endif /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */

#else

    /* Non-FOTA part */
   targetAddr = LoadMauiBody();

#endif /* __FOTA_DM__ */

   if(targetAddr != INVALID_START_ADDR)
   {
      targetAddr += ((GFH_FILE_INFO_v1*)(targetAddr))->m_jump_offset;
   }

   return targetAddr;
}

#else

kal_uint32 LoadAndVerifyNextBinary(kal_bool *pDoRemap)
{
   kal_uint32 targetAddr = INVALID_START_ADDR;

#if defined(__FOTA_DM__)

#if defined(_NAND_FLASH_BOOTING_)

   /* NAND FOTA support */
   targetAddr = LoadFotaOnNand();

#else

   /* NOR FOTA support */
   targetAddr = bl_loadFOTAImage();
   *pDoRemap = KAL_TRUE;   /* must be executed in internal RAM since remapping register is changed */

#endif /* _NAND_FLASH_BOOTING_ */

#else

#ifdef _NAND_FLASH_BOOTING_

   targetAddr = LoadPrimariMAUI();

#else

   if(FACTORY_BIN_START_ADDR_NOR != 0xffffffff && IsMetaModeEnabled() )
   {
      targetAddr = FACTORY_BIN_START_ADDR_NOR & REMAPPING_MASK ;
      BL_PRINT(LOG_INFO, "Launching FactoryBin in Combine mode...\r\n");
   }
   else
   {
      targetAddr = MAUI_START_ADDR_NOR & REMAPPING_MASK;
   }

#ifdef __MTK_SECURE_PLATFORM__
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
#endif /* __MTK_SECURE_PLATFORM__ */

#endif /* _NAND_FLASH_BOOTING_ */

#endif /* __FOTA_DM__ */

   return targetAddr;
}

#endif

void RemapCmd(void)
{

#ifdef EMI_REMAP_OFFSET_MIXED

   *EMI_REMAP |= 3;

#else

   *EMI_REMAP = 3;

#endif
   
}

#if defined(__DSP_BOOT_SEC__) || defined(__DSP_BOOT_ORG__)

void DmdspBootInit(void)
{
#ifdef MT6276   
    *(volatile unsigned long *)0x81160090 = 0;    
    *(volatile unsigned long *)0x811600A0 = 5;    
#endif

#if defined(__DSP_BOOT_SEC__)
    //Used to ungate DSP 
    dmdsp_ungate_dsp();
#elif defined(__DSP_BOOT_ORG__)
    *(volatile unsigned long *)0xFF080000 |= 0xC;    
#endif

}

#endif /* __DSP_BOOT_SEC__ || __DSP_BOOT_ORG__ */

void BootAndHandOver(void)
{
   kal_uint32 targetAddr = INVALID_START_ADDR;
   kal_bool   doRemap = KAL_FALSE;

  TS_BEGIN(TSID_BL_BOOT_AND_HANDOVER);

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
   dbg_print("Start loading image...\n\r"); 
#endif

   WacthDogRestart();

   targetAddr = LoadAndVerifyNextBinary(&doRemap);

   WacthDogRestart();

#if defined(__DSP_BOOT_SEC__) || defined(__DSP_BOOT_ORG__)
   DmdspBootInit();
#endif /* __DSP_BOOT_SEC__ || __DSP_BOOT_ORG__ */

#if !defined(__BL_SLIM_SEG__) && !defined(__BRINGUP_SUPPORT__)

   CacheDeinit();
#endif /* !__BL_SLIM_SEG__ && !__BRINGUP_SUPPORT__ */

   ShutDownModule();

   if(targetAddr != INVALID_START_ADDR)
   {
      TS_END(TSID_BL_BOOT_AND_HANDOVER);
      TS_END(TSID_BL_EXT_BOOTLOADER);
      TS_END(TSID_BL_TOTAL);

#ifdef __TIME_STAMP__
      TS_SetTimeUnit(TS_TIME_MS);
      TS_ConvertTimeUnit();
      TS_DumpTimeStamps();
      BL_PRINT(LOG_DEBUG, "Dump timestamp done\r\n");
#endif

      dbg_print("\nBye bye bootloader, jump to=%x\n\r", targetAddr);

      PostProcess();
      
      if (doRemap == KAL_TRUE)
      {
         RemapCmd();
      }
   
      JumpCmd(targetAddr);
   }

   g_Bl_Secure_Test = 1;
}

#pragma arm section code


/**********************************************************
Description : Set up flags for init module
Input       : None
Output      : None
***********************************************************/

void SetBootupFlag(kal_uint32 flag)
{
   extern BL_Info_Wrapper_st BL_Shared_info;
   ASSERT(BL_Shared_info.m_bl_maui_share_data.m_bl_magic_head == BL_INFO_V1);
   BL_Shared_info.m_bl_maui_share_data.m_bl_bootup_flag |= flag;
}

kal_uint32 InitBlSysInfo(void)
{
      extern BL_Info_Wrapper_st BL_Shared_info;
      extern kal_uint32* SST_GetToken(void);

      memset(&BL_Shared_info.m_bl_maui_share_data, 0x00, sizeof(BL_Shared_info.m_bl_maui_share_data));
 
      BL_Shared_info.m_bl_maui_share_data.m_bl_magic_head = BL_INFO_V1;
      BL_Shared_info.m_bl_maui_share_data.m_bl_random_seed = g_randomSeed;

      custom_get_bootloader_version(BL_Shared_info.m_bl_maui_share_data.m_bl_version_str, sizeof(BL_Shared_info.m_bl_maui_share_data.m_bl_version_str));

#ifndef __16_3_SEG__      
      memcpy(BL_Shared_info.m_bl_maui_share_data.m_bl_token, SST_GetToken(), sizeof(BL_Shared_info.m_bl_maui_share_data.m_bl_token));      
#endif /* __16_3_SEG__ */

      memcpy(&BL_Shared_info.m_bl_maui_share_data.m_emi_param, g_emi_param, sizeof(g_emi_param));
      memcpy(&BL_Shared_info.m_bl_maui_share_data.m_me_identity, &g_pBROM_BL_Param->m_me_identity, sizeof(BL_Shared_info.m_bl_maui_share_data.m_me_identity));
      SetBootupFlag(BL_BROM_RID_GOT);

#if 0
/* under construction !*/
#ifdef __SV5_ENABLED__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef MT6251
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif /* __SV5_ENABLED__ */
#endif


      return 0;
}

#ifdef __SV5_ENABLED__
void ChekcInfoFromBootROM(void)
{
   if((g_pBROM_BL_Param->m_brom_flags & BL_PARAM_BL_ALL_PASS) == 0)
   {
      kal_uint32 i;
      BL_LoadInfo *pLoadInfo = g_pBROM_BL_Param->m_bl_loadinfo;

      for(i=0; i<MAX_BL_NUM; i++)
      {
         if(pLoadInfo[i].m_state == BL_NOT_EXIST)
         {
            continue;
         }

         BL_PRINT(LOG_INFO, "Bootloader[%d], state=%d, c1=%x, c2=%x\n\r", i, pLoadInfo[i].m_state, pLoadInfo[i].m_code_1, pLoadInfo[i].m_code_2);
      }
      
      BL_PRINT(LOG_ERROR, "Some bootloader is not loaded!\n\rDeadEnd!!");

      while(1);
   }
}
#endif /* __SV5_ENABLED__ */


void GetArgFromMini(void)
{
   kal_uint32 it = 0;
   kal_uint32 *p, type, size;

   p = bl_Traverse_TLV_Record((kal_uint32)g_mini_ext_da_share_buf, &it, &type, &size);

   while(p)
   {      
      switch(type)
      {
         case MINI_EXT_SHARD_RANDOM_SEED:
            g_randomSeed = *p;
            break;

#ifdef __SV5_ENABLED__            
         case MINI_EXT_SHARD_BL_PARAM:

#if defined(__COPY_BROM_BL_PARAM_TO_EXTERNAL_RAM__)
            memcpy(&g_BROM_BL_Param, p, sizeof(g_BROM_BL_Param));
#else
            g_pBROM_BL_Param = (BL_Param_v4*)*p;
#endif /* __COPY_BROM_BL_PARAM_TO_EXTERNAL_RAM__ */

            break;
#endif

         case MINI_EXT_SHARE_BL_HEADER:
            memcpy(&BLHeader, p, sizeof(BLHeader));
            break;

         case MINI_EXT_SHARE_BL_TOKEN:
            SST_SetToken(p, size);
            break;

#ifdef __SV5_ENABLED__
         case MINI_EXT_SHARD_FEATURE_COMBINATION:
            //BL_TODO
            break;
#else
         case MINI_EXT_SHARD_FEATURE_COMBINATION:
            //BL_TODO
            break;
#endif

#ifdef __TIME_STAMP__            
         case MINI_EXT_SHARE_BL_TIME_STAMP_RECORD:
         {
            kal_uint32 tsAddr, tsSize;
            TS_GetContext(&tsAddr, &tsSize);
            memcpy((void*)tsAddr, p, tsSize);
            break;
         }
#endif /* __TIME_STAMP__ */

         case MINI_EXT_SHARE_EMI_PARAM:
            memcpy(g_emi_param, p, sizeof(g_emi_param));
            break;
            
#ifdef __EXT_BL_UPDATE__
         case MINI_EXT_SHARE_EXT_BL_UPDATE_INFO:
            memcpy(&g_extBlUpdateInfo, p, sizeof(g_extBlUpdateInfo));
            break;
#endif /* __EXT_BL_UPDATE__ */

#ifdef __BROM_USBDL_V2__
         case MINI_EXT_SHARE_USBDL_RETN:
            g_usbdlRetnValue = *p;
            break;
#endif /* __BROM_USBDL_V2__ */

      }
      p = bl_Traverse_TLV_Record((kal_uint32)g_mini_ext_da_share_buf, &it, &type, &size);
   }
}


#ifdef __FAST_LOGO__

const kal_uint8 *GetBootLogoPicture(void)
{
   return g_fast_logo_img;
}

#endif /* __FAST_LOGO__ */

void ShowLogo(void)
{
#ifdef __FAST_LOGO__

   //Show the first screen
   const kal_uint8 *pLogoPic = GetBootLogoPicture();
   
   TS_BEGIN(TSID_BL_DISPLAY_LOGO);

   BL_PRINT(LOG_INFO, "Displaying logo...\r\n");

   BL_LCDHWInit();

#if defined(GUI_BOOTUP_LOGO_X) && defined(GUI_BOOTUP_LOGO_Y)
   BL_ShowUpdateFirmwareInitBackgroundByImage((U8*)pLogoPic, GUI_BOOTUP_LOGO_X, GUI_BOOTUP_LOGO_Y, KAL_FALSE);
#else
   BL_ShowUpdateFirmwareInitBackgroundByImage((U8*)pLogoPic, 0, 0, KAL_TRUE);
#endif

   BL_LCDSetBackLight();

   SetBootupFlag(BL_FAST_LOGO_DISPLAYED);
   
   TS_END(TSID_BL_DISPLAY_LOGO);
   
#endif /* __FAST_LOGO__ */   

}

#ifdef __TC01__
/* under construction !*/
/* under construction !*/
#endif

kal_bool LatchPowerInBL(void)
{
   kal_bool toLatchPower = KAL_FALSE;

   TS_BEGIN(TSID_BL_PREPARE_LATCH_POWER);

#ifdef __TC01__
/* under construction !*/
#endif
   
#ifdef __FAST_LOGO__

   DclPW_Initialize();
   BL_Shared_info.m_bl_maui_share_data.m_poweron_param = PW_PowerDetect();

   if(BL_Shared_info.m_bl_maui_share_data.m_poweron_param != 0)
   {
      toLatchPower = KAL_TRUE;
   }

#endif

   TS_END(TSID_BL_PREPARE_LATCH_POWER);

   if(toLatchPower)
   {
      kal_bool firstBootup;
      DCL_HANDLE rtc_handler;
      RTC_CTRL_BOOTLOADER_POWERON_T rtc_cmd_data12;

      TS_BEGIN(TSID_BL_LATCH_POWER);

      rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);
      DclRTC_Control(rtc_handler, RTC_CMD_BOOTLOADER_POWERON, (DCL_CTRL_DATA_T *)&rtc_cmd_data12);
      firstBootup = (kal_bool)rtc_cmd_data12.fgBootloaderPowerOn;
      DclRTC_Close(rtc_handler);

      SetBootupFlag(BL_INFO_POWER_LATCHED);

      if(firstBootup)
      {
         SetBootupFlag(BL_INFO_FIRST_POWER_ON);
      }
      
      TS_END(TSID_BL_LATCH_POWER);      
   }

   return toLatchPower;

}


/**********************************************************
Description : Main body of Ext Bootloader
Input       : None
Output      : None
***********************************************************/

void ExtBootloader(void)
{
   
#ifdef __DRV_EXT_CHARGER_DETECTION__
   extern void MU_BootUp_Init(void);
#endif /* __DRV_EXT_CHARGER_DETECTION__ */

   GetArgFromMini();

   TS_Init(KAL_FALSE);

   set_debug_level(bootloader_debug_level);

   TS_BEGIN(TSID_BL_EXT_BOOTLOADER);

   TS_BEGIN(TSID_BL_PRINT_WELCOME);

   dbg_print("\n\n\n\r~~~ Welcome to MTK Bootloader %s (since 2005) ~~~\n\r", BootLDVerno);
   dbg_print("**===================================================**\n\n\r");

#ifdef __MTK_INTERNAL__
/* under construction !*/
#if defined(_NAND_FLASH_BOOTING_)
/* under construction !*/
#elif defined(__EMMC_BOOTING__)
/* under construction !*/
#endif
/* under construction !*/
#endif

#if defined(__EXT_BL_UPDATE__)
   BL_PRINT(LOG_DEBUG, "Active BL = %d\r\n", g_extBlUpdateInfo.m_current_bl);
#endif 

   TS_END(TSID_BL_PRINT_WELCOME);
   
#ifdef __DRV_EXT_CHARGER_DETECTION__
   MU_BootUp_Init();
#endif /* __DRV_EXT_CHARGER_DETECTION__ */
   BL_PRINT(LOG_DEBUG, "[FUNET]aaa, g_usbdlRetnValue = %d \n\r", g_usbdlRetnValue);
   InitExt();

   BL_PRINT(LOG_DEBUG, "[FUNET]bbb, g_usbdlRetnValue = %d \n\r", g_usbdlRetnValue);
#if defined(__SERIAL_FLASH_STT_EN__)
	  stt_main();
#endif

#if defined(__SNAND_STT_EN__)
    stt_snand_main();
#endif

   BL_PRINT(LOG_DEBUG, "[FUNET]ccc, g_usbdlRetnValue = %d \n\r", g_usbdlRetnValue);
   InitBlSysInfo();
   BL_PRINT(LOG_DEBUG, "[FUNET]ddd, g_usbdlRetnValue = %d \n\r", g_usbdlRetnValue);
#ifdef __SV5_ENABLED__
/* There is only one bootloader on 50/60, no need to check them */
#if!defined(MT6250) && !defined(MT6260) && !defined(MT6261)
   ChekcInfoFromBootROM();
#endif   

   if(g_bromCmdModeDisabled)
   {
      SetBootupFlag(BL_BROM_CMD_MODE_DISABLED);
   }

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
   //Temp solution for non-final tool. This part should be replaced by CBR
   BL_DEBUG_PRINT("Find and load image list block...\n\r");
   if ( LoadImageListblock(GetMainRegionStartBlock()) == KAL_FALSE )
   {
      BL_PRINT(LOG_ERROR, "Invalid ILB config\n\r");
      return;
   }
#endif /* _NAND_FLASH_BOOTING_ */

   //Find (and load) MAUI's GFH
   if(!g_bootupDisabled)
   {
      LoadMAUIFirstPart();
   }

#else   

#ifdef _NAND_FLASH_BOOTING_
   BL_DEBUG_PRINT("Find and load image list block...\n\r");
   if ( LoadImageListblock(GetMainRegionStartBlock()) == KAL_FALSE )
   {
      dbg_print("Invalid ILB config\n\r");
      return;
   }
#endif /* _NAND_FLASH_BOOTING_ */

#endif /* __SV5_ENABLED__ */

   BL_PRINT(LOG_DEBUG, "[FUNET]eee, g_usbdlRetnValue = %d \n\r", g_usbdlRetnValue);
   WacthDogRestart();   
   BL_PRINT(LOG_DEBUG, "[FUNET]fff, g_usbdlRetnValue = %d \n\r", g_usbdlRetnValue);
   GetFeatureCombination();

   if ( CheckPairedVersion() == KAL_FALSE )
   {
      g_bootupDisabled = KAL_TRUE;
      g_bootupStatus = BL_BOOTUP_FAIL_PAIRED_VER_MISMATCHED;
   }

   if ( CheckFeatureCombination() == KAL_FALSE )
   {
      g_bootupDisabled = KAL_TRUE;
      g_bootupStatus = BL_BOOTUP_FAIL_UNSUPPORTED_MAUI_FEAUTRE;
   }

   BL_PRINT(LOG_DEBUG, "[FUNET]ggg, g_usbdlRetnValue = %d \n\r", g_usbdlRetnValue);
#if !defined(__BL_SLIM_SEG__) && !defined(__BRINGUP_SUPPORT__)

   FactoryProcedure();
   
    if(!IsInWithOutBatteryMode())   
      BL_Disable_Usbdl_Wo_Battery();
      
   CardDLProcedure();
   
#if defined(__EXT_BL_UPDATE__)
   if(g_bootupDisabled == KAL_FALSE && g_extBlUpdateInfo.m_current_bl != E_EXTBL_PRIMARY_REGION)
   {
      g_bootupDisabled = KAL_TRUE;
      g_bootupStatus = BL_BOOTUP_FAIL_BACKUP_BL_EXECUTING;
   }
#endif /* __EXT_BL_UPDATE__ */

#endif /* !__BL_SLIM_SEG__ && !__BRINGUP_SUPPORT__ */
   BL_PRINT(LOG_DEBUG, "[FUNET]g_usbdlRetnValue = %d \n\r", g_usbdlRetnValue);
   FUNETProcedure();

    if(!IsInWithOutBatteryMode())   
      BL_Disable_Usbdl_Wo_Battery();

   if( !g_bootupDisabled )
   {
      kal_bool powerLatched = KAL_FALSE;
      
      TS_BEGIN(TSID_BL_PREPARE_BOOTUP);

      TS_END(TSID_BL_PREPARE_BOOTUP);

#if !defined(__BL_SLIM_SEG__) && !defined(__BRINGUP_SUPPORT__)

      powerLatched = LatchPowerInBL();

      CacheInit();      

      if(powerLatched)
      {
         ShowLogo();
      }

#endif /* !__BL_SLIM_SEG__ && !__BRINGUP_SUPPORT__ */

#if defined(__UBL__) && defined(__NOR_FULL_DRIVER__)
			BL_ScanSerialFlashBlocks();
#endif

      BootAndHandOver();
   }

   dbg_print("Bootloader dead end(%d,%d)\n\r", g_bootupDisabled, g_bootupStatus);
}

/**********************************************************
Description : Get the memory regions that are used by bootloader
Input       : A buffer and lenght of it
Output      : The information about bootloader region 
***********************************************************/

kal_uint32 GetBootloaderRegion(BL_MEM_REGION_INFO **pResultArr)
{
   #define GET_REGION_INFO(R, T) {                                                                                             \
                              extern kal_uint32 Image$$##R##$$Base;                                                            \
                              extern kal_uint32 Image$$##R##$$Length;                                                          \
                              extern kal_uint32 Image$$##R##$$ZI$$Length;                                                      \
                              if ( (kal_uint32)(&Image$$##R##$$Length) != 0 || (kal_uint32)(&Image$$##R##$$ZI$$Length) != 0 )  \
                              {                                                                                                \
                                pInfo[count].addr = (kal_uint32)(&Image$$##R##$$Base);                                             \
                                pInfo[count].len  = (kal_uint32)(&Image$$##R##$$Length) + (kal_uint32)(&Image$$##R##$$ZI$$Length); \
                                pInfo[count].type = T;                                                                             \
                                count++;                                                                                           \
                              }                                                                                                \
   }

   static kal_uint32 count = 0;
   static BL_MEM_REGION_INFO regionInfo[9];
   
   BL_MEM_REGION_INFO *pInfo = &regionInfo[0];

   if(count == 0)
   {
       //These code should be modified corresponding to scatter file
#ifdef __N_PLUS_0_PROJECT__
      GET_REGION_INFO(DA_SHARE,                     BL_EXCLUSIVE_TO_DA)
#else
      GET_REGION_INFO(EXT_READ_ONLY,                BL_EXCLUSIVE_TO_DA)
      GET_REGION_INFO(EXT_READ_ONLY_HEAD,           BL_EXCLUSIVE_TO_DA)
      GET_REGION_INFO(EXT_READ_ONLY_TAIL,           BL_EXCLUSIVE_TO_DA)
      GET_REGION_INFO(EXT_READ_WRITE,               BL_EXCLUSIVE_TO_DA)
#endif

      GET_REGION_INFO(EXT_READ_ONLY_INT,            BL_FREE_DURING_EXECUTION)
      GET_REGION_INFO(EXT_READ_WRITE_INT,           BL_FREE_DURING_EXECUTION)
      GET_REGION_INFO(STACK_AREA,                   BL_FREE_DURING_EXECUTION)
      GET_REGION_INFO(EXT_UN_INIT,                  BL_FREE_DURING_EXECUTION)

      //SHARE_BUF is not protected due to DA's behavior
      //GET_REGION_INFO(SHARE_BUF,                    BL_FREE_DURING_EXECUTION)
      ASSERT(count < sizeof(regionInfo)/sizeof(regionInfo[0]));   
   }

   if(pResultArr)
   {
      *pResultArr = pInfo;
   }
      
   return count;

}

/**********************************************************
Description : Facility for wrapping USB and UART driver
Input       : 
Output      : 
***********************************************************/
#if defined(__USB_DOWNLOAD__) || defined(__UART_DOWNLOAD__)

kal_uint8 BL_GetUARTByte(void)
{
#ifdef __UART_DOWNLOAD__
   return GetUARTByte();
#else
   return USBDL_GetUARTByte();
#endif
}

void BL_PutUARTByte(kal_uint8 data)
{
#ifdef __UART_DOWNLOAD__
   PutUARTByte(data);
#else
   USBDL_PutUARTByte(data);
#endif    
}

void BL_PutUARTByte_Complete(void)
{
#ifdef __UART_DOWNLOAD__
   PutUARTByte_Complete();
#else
   USBDL_PutUARTByte_Complete();
#endif        
}

void BL_CheckUARTSendEnd(void)
{
#ifdef __UART_DOWNLOAD__
   CheckUARTSendEnd();
#else
   USBDL_CheckUARTSendEnd();
#endif        
}
#endif /* defined(__USB_DOWNLOAD__) || defined(__UART_DOWNLOAD__) */

/**********************************************************
Description : Facility for BL-DA shared data, initialize structure
Input       : 
Output      : 
***********************************************************/
kal_bool bl_Init_BL_DA_SharedData(void)
{
   return bl_Init_TLV_Service((kal_uint32)g_mini_ext_da_share_buf, sizeof(g_mini_ext_da_share_buf), BL_DA_SHARED_DATA_ID);   
}

/**********************************************************
Description : Facility for BL-DA shared data, allocate a new space
Input       : id of the requested record, and size of it
Output      : the pointer to the buffer for record
***********************************************************/
kal_uint32* bl_Allocate_BL_DA_SharedData(kal_uint32 type, kal_uint32 size)
{
   return bl_Allocate_TLV_Record((kal_uint32)g_mini_ext_da_share_buf, type, size);
}

   
#endif /* __EXT_BOOTLOADER__ */

