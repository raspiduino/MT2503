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
 *   custom_jump_tbl.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   header file for indirect jump table for multiple binary load
 *
 * Author:
 * -------
 * -------    system auto generator  V1.95 
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _CUSTOM_JUMP_TBL_H_
#define _CUSTOM_JUMP_TBL_H_

#include "kal_general_types.h"
#include "mba_resource.h"
#include "custom_featureconfig.h"

/* resource_version = 1-byte res_type + 3-byte version# */
#define RESOURCE_TYPE_MASK        0xFF000000
#define RESOURCE_VERSION_MASK  0x00FFFFFF

#define RESOURCE_TYPE_AUDIO 0x00000000
#define RESOURCE_TYPE_IMAGE 0x01000000
#define RESOURCE_TYPE_FONT   0x02000000
#define RESOURCE_TYPE_STR      0x03000000
#define RESOURCE_TYPE_J2ME    0x04000000
#define RESOURCE_TYPE_IME     0x05000000
#define RESOURCE_TYPE_LANG_PACK     0x06000000

/* __CUSTPACK_MULTIBIN Cylen BEGIN */
#define RESOURCE_TYPE_CUSTPACK      0x07000000
#define RESOURCE_TYPE_AUTOGEN_AUDIO 0x08000000  /* 101205 audio resource Calvin added */
#define custpack_verno "My 1st time"
/* __CUSTPACK_MULTIBIN Cylen END */

#define MAGIC_NUMBER 0x12345678

/* extern kal_char verno_str[120]; */
#define PROJECTID_LEN   ((VERNO_MAX_LEN_IN_WORDS)*sizeof(void*))
#define ENTRY_PROJECT_ID  VERNO_MAX_LEN_IN_WORDS+PATTERN_LEN_IN_WORDS+COMPRESSED_IN_WORDS
#define VERNO_MAX_LEN_IN_WORDS 16
/*Pattern for backward compatibility*/
#define PATTERN_LEN_IN_WORDS 2
#define PATTERN_LEN 6
#define VERSION_PATTERN "MBAVer"
#define VERSION_NUMBER 0x0003
#define COMPRESSED_IN_WORDS 4

#define MAX_BIN_SUPPORT 5
#define MBAINFO_PATTERN_SIZE 8
#define MBAINFO_PATTERN "MBAINFO"
/*Compressed*/
#define MAX_COMPRESSED_BIN_SUPPORT 2
#define DEFAULT_NOT_COMPRESSED 0x0

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
#define SYSTEM_JUMP_TABLE_VAR_MODIFIER  
#else    /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */
#define SYSTEM_JUMP_TABLE_VAR_MODIFIER const
#endif   /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */

/*Structure*/
typedef struct
{
    kal_char   MBAInfoPattern[MBAINFO_PATTERN_SIZE];
    kal_char   Bin_Number;
    kal_uint32 Resource_version[MAX_BIN_SUPPORT];	
} MBA_Info;
typedef struct
{    
    kal_char ProjectID[PROJECTID_LEN];
    kal_char Vpattern[PATTERN_LEN];
    kal_uint16 Version;
    kal_uint16  Compressed;
    kal_uint16  Existed;
    // load view
    kal_uint32 *LoadAddress;
    kal_uint32 CompressedSize;
    kal_uint32 MAXRAMSize;
    kal_uint32 Resource_version;
    //execution view
    kal_uint32 *ExecAddress;
    kal_uint32 TableSize;
    kal_uint32 ContentSize;
    kal_uint32 Magic;
} Type_Preamble_Content;

//__CUSTPACK_MULTIBIN
typedef enum 
{
   JUMP_TABLE_ENTRY_START, 
   
   JUMP_TABLE_ENTRY_LANG_PACK = JUMP_TABLE_ENTRY_START, 
   JUMP_TABLE_ENTRY_CUSTPACK,
   JUMP_TABLE_ENTRY_AUTOGEN_AUDIO,
   JUMP_TABLE_ENTRY_END = JUMP_TABLE_ENTRY_CUSTPACK

} JUMP_TABLE_ENTRY_ENUM;


extern SYSTEM_JUMP_TABLE_VAR_MODIFIER Type_Preamble_Content system_jump_table[];
extern Type_Preamble_Content LangPackResPreamble ;
extern void* langpack2ndJumpTbl[];
extern Type_Preamble_Content CustPackResPreamble ;
extern void* custpack2ndJumpTbl[];


#define JUMP_TABLE_ENTRY_END              JUMP_TABLE_ENTRY_CUSTPACK

/* Macros for addressing each resource */
#define GET_Res_Addr(R, X)                (((kal_uint32 *) (system_jump_table[R].LoadAddress)) + X)
#define GET_Res_ProjectID(X)              (system_jump_table[X].ProjectID)
#define GET_Res_ResVersion(X)             (system_jump_table[X].Resource_version)
#define GET_Res_Magic(X)                  (system_jump_table[X].Magic)
#define GET_Res_LoadAddr(X)               (system_jump_table[X].LoadAddress)
#define GET_Res_ExecAddr(X)               (system_jump_table[X].ExecAddress)
#define GET_Res_IsExisted(X)              (system_jump_table[X].Existed)
#define GET_Res_IsCompressed(X)           (system_jump_table[X].Compressed)
#define GET_Res_TBLSize(X)                (system_jump_table[X].TableSize)
#define GET_Res_DeCompSize(X)             (system_jump_table[X].TableSize + system_jump_table[X].ContentSize)


#if defined(__MULTIPLE_BINARY_FILES__) && defined(__MTK_TARGET__) && !defined(GEN_FOR_PC)

/* Macros below specific for multiple binary files or multiple load segments only */
/* Collection of Lang Pack */
extern kal_uint32  Load$$LANG_PACK_ROM$$Base;
extern kal_uint32  Image$$LANG_PACK_ROM$$Base;
extern kal_uint32  Image$$LANG_PACK_ROM$$Length;
extern kal_uint32  Image$$LANG_PACK_ROM_CONTENT$$Base;
extern kal_uint32  Image$$LANG_PACK_ROM_CONTENT$$Length;

//__CUSTPACK_MULTIBIN__
extern kal_uint32  Load$$CUSTPACK_ROM$$Base;
extern kal_uint32  Image$$CUSTPACK_ROM$$Base;
extern kal_uint32  Image$$CUSTPACK_ROM$$Length;
extern kal_uint32  Image$$CUSTPACK_ROM_CONTENT$$Base;
extern kal_uint32  Image$$CUSTPACK_ROM_CONTENT$$Length;

/* macro of resource address and size for const arrary initialization */

//__LANGPACK_MULTIBIN__
#if defined(__MBA_LANG_ONLY__)
    #define GET_ResLangPack_Addr(X)           GET_Res_Addr(JUMP_TABLE_ENTRY_LANG_PACK, X)
    #define CONST_RES_LANG_PACK_EXEC_ADDR          (&Image$$LANG_PACK_ROM_CONTENT$$Base)
    #define CONST_RES_LANG_PACK_TBL_SIZE      ((kal_uint32)&Image$$LANG_PACK_ROM$$Length)
    #define CONST_RES_LANG_PACK_CONTENT_SIZE  ((kal_uint32)&Image$$LANG_PACK_ROM_CONTENT$$Length)
    #define CONST_RES_LANG_PACK_LOAD_ADDR (&Load$$LANG_PACK_ROM$$Base) 
    #define CONST_RES_LANG_PACK_COMPRESSED_SIZE ((kal_uint32)0)
    #define LANG_EXISTED ((kal_uint16)0x1)
#else
    #define GET_ResLangPack_Addr(X)           ((kal_uint32 *)&langpack2ndJumpTbl)
    #define CONST_RES_LANG_PACK_EXEC_ADDR          ((kal_uint32 *)&LangPackResPreamble)
    #define CONST_RES_LANG_PACK_TBL_SIZE      ((kal_uint32)0)
    #define CONST_RES_LANG_PACK_CONTENT_SIZE  ((kal_uint32)0)
    #define CONST_RES_LANG_PACK_LOAD_ADDR ((kal_uint32 *)&LangPackResPreamble) 
    #define CONST_RES_LANG_PACK_COMPRESSED_SIZE ((kal_uint32)0)
    #define LANG_EXISTED ((kal_uint16)0x0)
#endif
//__CUSTPACK_MULTIBIN__
#if defined(__MBA_CUST_ONLY__)
    #define GET_ResCUSTPACK_Addr(X)           GET_Res_Addr(JUMP_TABLE_ENTRY_CUSTPACK, X)
    #define CONST_RES_CUSTPACK_EXEC_ADDR           (&Image$$CUSTPACK_ROM_CONTENT$$Base)
    #define CONST_RES_CUSTPACK_TBL_SIZE       ((kal_uint32)&Image$$CUSTPACK_ROM$$Length)
    #define CONST_RES_CUSTPACK_CONTENT_SIZE   ((kal_uint32)&Image$$CUSTPACK_ROM_CONTENT$$Length)
    #define CONST_RES_CUSTPACK_LOAD_ADDR (&Load$$CUSTPACK_ROM$$Base)
    #define CONST_RES_CUSTPACK_COMPRESSED_SIZE ((kal_uint32)0)
    #define CUST_EXISTED ((kal_uint16)0x1)
#else
    #define GET_ResCUSTPACK_Addr(X)           ((kal_uint32 *)&custpack2ndJumpTbl)
    #define CONST_RES_CUSTPACK_EXEC_ADDR           ((kal_uint32 *)&CustPackResPreamble)
    #define CONST_RES_CUSTPACK_TBL_SIZE       ((kal_uint32)0)
    #define CONST_RES_CUSTPACK_CONTENT_SIZE   ((kal_uint32)0)
    #define CONST_RES_CUSTPACK_LOAD_ADDR ((kal_uint32 *)&CustPackResPreamble)
    #define CONST_RES_CUSTPACK_COMPRESSED_SIZE ((kal_uint32)0)
    #define CUST_EXISTED ((kal_uint16)0x0)
#endif

#else /* __MULTIPLE_BINARY_FILES__ && __MTK_TARGET__ && GEN_FOR_PC */

#if defined(EMPTY_MMI) || defined(EXTERNAL_MMI)
#define CONST_RES_LANG_PACK_EXEC_ADDR               ((kal_uint32)0)
#else  /* EMPTY_MMI || EXTERNAL_MMI */
#define CONST_RES_LANG_PACK_EXEC_ADDR               ((kal_uint32 *)&LangPackResPreamble)
#endif /* EMPTY_MMI || EXTERNAL_MMI */

#define CONST_RES_LANG_PACK_TBL_SIZE           ((kal_uint32)0)
#define CONST_RES_LANG_PACK_CONTENT_SIZE       ((kal_uint32)0)
#define CONST_RES_LANG_PACK_LOAD_ADDR ((kal_uint32 *)&LangPackResPreamble) 
#define CONST_RES_LANG_PACK_COMPRESSED_SIZE ((kal_uint32)0)
#define LANG_EXISTED ((kal_uint16)0x0)


#define CONST_RES_CUSTPACK_EXEC_ADDR                ((kal_uint32 *)&CustPackResPreamble)
#define CONST_RES_CUSTPACK_TBL_SIZE            ((kal_uint32)0)
#define CONST_RES_CUSTPACK_CONTENT_SIZE        ((kal_uint32)0)
#define CONST_RES_CUSTPACK_LOAD_ADDR ((kal_uint32 *)&CustPackResPreamble)
#define CONST_RES_CUSTPACK_COMPRESSED_SIZE ((kal_uint32)0)
#define CUST_EXISTED ((kal_uint16)0x0)

#define GET_ResLangPack_Addr(X)                ((kal_uint32 *)&langpack2ndJumpTbl)
#define GET_ResCUSTPACK_Addr(X)                ((kal_uint32 *)&custpack2ndJumpTbl)

#endif /* __MULTIPLE_BINARY_FILES__ && __MTK_TARGET__ */

#if defined(__ZIMAGE_SUPPORT__)
#if !defined(__MBA_LANG_ONLY__) && (LANG_PACK_ROM_COMPRESS != 0)
    #error There is no langpack binary, please turn off LANG_PACK_ROM_COMPRESS
#endif 
#if !defined(__MBA_CUST_ONLY__) && (CUSTPACK_ROM_COMPRESS != 0)
    #error There is no custpack binary, please turn off CUSTPACK_ROM_COMPRESS
#endif
#else /* __ZIMAGE_SUPPORT__ */
#if (LANG_PACK_ROM_COMPRESS != 0) || (CUSTPACK_ROM_COMPRESS != 0)
    #error Please turn off LANG_PACK_ROM_COMPRESS and CUSTPACK_ROM_COMPRESS when Zimage is not support
#endif 
#endif /* __ZIMAGE_SUPPORT__ */

#endif /* _CUSTOM_JUMP_TBL_H_ */
