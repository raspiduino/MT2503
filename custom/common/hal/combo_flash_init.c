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
 *   combo_flash_init.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the ComboMCP Init function
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
#include "custom_MemoryDevice.h"
#include "flash_opt.h"

#if defined(__COMBO_MEMORY_SUPPORT__) || defined(__SERIAL_FLASH__) || defined(__SPI_NAND_SUPPORT__)
#include "combo_flash_init.h"
#include "combo_flash_defs.h"
  #if (!defined(_NAND_FLASH_BOOTING_))
  #include "flash_cfi.h"
  #include "flash_cfi_internal.h"
  #include "flash_mtd.h"
  #endif
  #if defined(NAND_SUPPORT) || defined(__SPI_NAND_SUPPORT__)
  #ifdef __UBL__
    extern void NFI_ReadID(kal_uint32 id_num, kal_uint8* id_data);
  #else
    extern kal_bool DAL_is_initialized;
  	extern kal_int32 DAL_init (void);
    extern void MTD_ReadID(kal_uint32 id_num,kal_uint8* id_data);
  #endif
  #endif
#if defined(__SERIAL_FLASH__)
#include "flash_sf.h"
#endif

#ifdef __SV5_ENABLED__
#include "br_GFH_cmem_id_info.h"
#endif /* __SV5_ENABLED__ */

//-----------------------------------------------------------------------------
// MCP ID Table
//-----------------------------------------------------------------------------
#ifdef __SV5_ENABLED__
  #ifdef __UBL__
    #pragma arm section rodata = "BOOTLOADER_GFH_EXT"
  #else // __UBL__
    #pragma arm section rodata = "MAUI_GFH_EXT"
  #endif // __UBL__
#endif  // __SV5_ENABLED__

#define  COMBO_MEM_TYPE_MODIFIER  const
#define  COMBO_MEM_INST_NAME    combo_mem_id_list

#ifdef   __SV5_ENABLED__
  #define  COMBO_MEM_TYPE_NAME  GFH_CMEM_ID_INFO_v1
#else
  #define  COMBO_MEM_TYPE_NAME  CMEMEntryIDList
#endif

#ifdef __SV5_ENABLED__
#define COMBO_MEM_STRUCT_HEAD  COMBO_MEM_ID_GFH_HEADER, { COMBO_MEM_ID_VER, COMBO_MEM_DEVICE_COUNT, {
#define COMBO_MEM_STRUCT_FOOT  } }
#else
#define COMBO_MEM_STRUCT_HEAD  COMBO_MEM_IDENTITY_ID, COMBO_MEM_ID_VER, COMBO_MEM_DEVICE_COUNT, {
#define COMBO_MEM_STRUCT_FOOT  }
#endif

#include "combo_flash_id.h"       // ==== Instantiate ID table

#pragma arm section rodata

//-----------------------------------------------------------------------------
// External Functions
//-----------------------------------------------------------------------------
extern kal_uint32 custom_get_fat_addr(void);
extern kal_uint32 INT_RetrieveFlashBaseAddr(void);

//-----------------------------------------------------------------------------
// Internal Functions
//-----------------------------------------------------------------------------
// ===[EMI/SFI Initialization]===
#if defined(__DUAL_SERIAL_FLASH_SUPPORT__)
kal_int32 CMEM_EMIINIT_Index(const kal_uint16 CS);
#else
kal_int32 CMEM_EMIINIT_Index(void);
#endif
void CMEM_EMIINIT_ReadID(const kal_uint16 CS, void *BaseAddr, kal_uint16 *flashid);

//-----------------------------------------------------------------------------
// Internal Variables
//-----------------------------------------------------------------------------
#define CMEM_INVALID_INDEX -1

#if defined(__COMBO_MEMORY_SUPPORT__)

#ifdef __MTK_TARGET__
#pragma arm section rwdata = "EMIINITRW"
#endif /* __MTK_TARGET__ */
static kal_int16 cmem_emiinit_index=CMEM_INVALID_INDEX;  // Init stage only
#ifdef __MTK_TARGET__
#pragma arm section rwdata
#endif /* __MTK_TARGET__ */

static kal_int16 cmem_index=CMEM_INVALID_INDEX;

#endif //__COMBO_MEMORY_SUPPORT__

#ifdef __MTK_TARGET__
#pragma arm section code = "SECOND_PART"
#endif /* __MTK_TARGET__ */



//-----------------------------------------------------------------------------
/*!
  @brief
    Determine whether SF ID is valid.
    Apply for MT6250 MT6260/61/2501/2502 because after command issue(ex: Read ID), Data pins are in floating, may read trasient value instead of 0x00 or 0xFF.
  @retval
    KAL_TRUE: the device ID0 is valid.
    KAL_FALSE: the device ID0 is not valid.  
*/
kal_bool CMEM_CheckValidDeviceID(kal_uint8 *id)
{
		// Serial Flash
#if defined(__SERIAL_FLASH__)
    kal_int32 i, j;
    const CMEMEntryID *id_list=NULL;
	
#ifdef   __SV5_ENABLED__
    id_list=combo_mem_id_list.m_data.List;
#else
    id_list=combo_mem_id_list.List;
#endif	
    // seach CMEM list for specific Flash ID
    for (i=0; i<COMBO_MEM_DEVICE_COUNT; i++)	{
        // Check 1: Compare ID
        for (j=0; j<id_list[i].IDLength; j++) {
            if (id_list[i].ID[j]!=id[j]) break;
        }
        // Check 2: Compare RegionInfo
        if (j==id_list[i].IDLength)   {
            // TBD: Compare RegionInfo
            return KAL_TRUE;
        }
    }  
#endif //defined(__SERIAL_FLASH__)
    return KAL_FALSE;
}

//-----------------------------------------------------------------------------
/*!
  @brief
  Seach device in the combo MCP list by Flash ID.
    1. Read NOR/NAND flash ID
    2. Lookup ID table and return the index to the found entry.

  @retval
    The index to the found entry.
    -1 : ID not found
  @remars
    If combo MCP was not turned on, the returned index is always 0.
*/
#if defined(__COMBO_MEMORY_SUPPORT__)
extern kal_int32 EMI_QueryIsRemapped(void);
#if defined(__DUAL_SERIAL_FLASH_SUPPORT__)
kal_int32 CMEM_Index(const kal_uint16 CS)
#else //ADMUX or Nand or SF without Dual SF enable
kal_int32 CMEM_Index()
#endif
{
    kal_int32 i, j;
    CMEMFlashID id;
    const CMEMEntryID *id_list=NULL;

#if !defined(__DUAL_SERIAL_FLASH_SUPPORT__)
    if (cmem_index>=0) return cmem_index;
#endif

// Read Flash ID
#if defined(_NAND_FLASH_BOOTING_)
    #if defined(__UBL__)
    return CMEM_INVALID_INDEX;
    #else
    if(DAL_is_initialized == 0)
    {
    	DAL_init(); // Call DAL init to ensure FlashID alreay there.
    }
    MTD_ReadID(8, id.NAND);
    #endif
#elif defined(__DUAL_SERIAL_FLASH_SUPPORT__)
  #if defined(__UBL__)
    //begin from MT6255, remapping is done before NOR_ReadID
    if(CS !=2) //Skip Read ID for dummy SF2
    {
        if(EMI_QueryIsRemapped())
            NOR_ReadID(CS,(void*)0x10000000, id.NOR);
        else
            NOR_ReadID(CS, (void*)0, id.NOR);
    }
  #else
    if(CS !=2)//Skip Read ID for dummy SF2
        NOR_ReadID(CS, (void *)(INT_RetrieveFlashBaseAddr() + NOR_FLASH_BASE_ADDRESS), id.NOR);
  #endif
#else //ADMUX and SF without Dual SF enable
  #if defined(__UBL__)
    //begin from MT6255, remapping is done before NOR_ReadID
        if(EMI_QueryIsRemapped())
            NOR_ReadID(0,(void*)0x10000000, id.NOR);
        else
            NOR_ReadID(0, (void*)0, id.NOR);
  #else
        NOR_ReadID(0, (void *)(INT_RetrieveFlashBaseAddr() + NOR_FLASH_BASE_ADDRESS), id.NOR);
  #endif
#endif //defined(_NAND_FLASH_BOOTING_)

#ifdef   __SV5_ENABLED__
    id_list=combo_mem_id_list.m_data.List;
#else
    id_list=combo_mem_id_list.List;
#endif

    // seach CMEM list for specific Flash ID
    for (i=0; i<COMBO_MEM_DEVICE_COUNT; i++)    {
        // Check 1: Compare ID
        for (j=0; j<id_list[i].IDLength; j++) {
            #if defined(_NAND_FLASH_BOOTING_)
            if (id_list[i].ID[j]!=id.NAND[j]) break;
            #else // __SERIAL_FLASH__ || NOR FLASH
            if (id_list[i].ID[j]!=id.NOR[j]) break;
            #endif
        }
        // Check 2: Compare RegionInfo
        if (j==id_list[i].IDLength)   {
            // TBD: Compare RegionInfo
            cmem_index=i;
            break;  // entry found, break the loop
        }
    }
#if defined(__DUAL_SERIAL_FLASH_SUPPORT__)
    /*Get Dummy SF entry ID*/
    if(CS==2)
    {
        // seach CMEM list for specific Flash ID
        for (i=0; i<COMBO_MEM_DEVICE_COUNT; i++)    {
            // Check 1: Compare ID
            for (j=0; j<id_list[i].IDLength; j++) {
				if(j==0)
                    if (id_list[i].ID[j]!= 0x00) break;
			    if(j==1)
                    if (id_list[i].ID[j]!= 0x34) break;
				if(j==2)
                    if (id_list[i].ID[j]!= 0x56) break;
            }
        
            if (j==id_list[i].IDLength)   
            {
                // TBD: Compare RegionInfo
                cmem_index=i;
                break;  // entry found, break the loop
            }
        }
    }
#endif

    return cmem_index;
}


#else  // __COMBO_MEMORY_SUPPORT__

#if defined(__DUAL_SERIAL_FLASH_SUPPORT__)
kal_int32 CMEM_Index(const kal_uint16 CS)
#else //ADMUX or Nand flash
kal_int32 CMEM_Index()
#endif

{
    return 0;
}

#endif // __COMBO_MEMORY_SUPPORT__

const CMEMEntryID *CMEM_GetIDEntry(kal_uint32 index)
{
#ifdef   __SV5_ENABLED__
        return &combo_mem_id_list.m_data.List[index];
#else
        return &combo_mem_id_list.List[index];
#endif
}

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE"
#endif /* __MTK_TARGET__ */

//-----------------------------------------------------------------------------
/*!
  @brief
    Read Flash ID
  @param[in] BaseAddr Base address to the Flash
  @param[out] flashid Flash ID
  @remarks
    This function is only allowed in EMI/SFI init stage.
*/
void CMEM_EMIINIT_ReadID(const kal_uint16 CS, void *BaseAddr, kal_uint16 *flashid)
{
    // Serial Flash
#if defined(__SERIAL_FLASH__)
    {
        kal_uint8 cmd, id[SF_FLASH_ID_LENGTH], i;

        cmd=SF_CMD_READ_ID_QPI;
            SFI_Dev_Command_Ext(CS, &cmd, id, 1, SF_FLASH_ID_LENGTH);

        if (id[0]==0x00 || id[0]==0xFF || (CMEM_EMIINIT_CheckValidDeviceID(id) == KAL_FALSE)) {
            cmd=SF_CMD_READ_ID;
                SFI_Dev_Command_Ext(CS, &cmd, id, 1, SF_FLASH_ID_LENGTH);
        }

        for (i=0;i<SF_FLASH_ID_LENGTH;i++) flashid[i]=id[i];
    }
    // ADMUX NOR Flash
#elif !defined(_NAND_FLASH_BOOTING_) // ADMUX
    {
        volatile FLASH_CELL *fp = (volatile FLASH_CELL*)(BaseAddr);

        *(fp+CFI_RDID_UNLOCK_ADR1)=CFI_RDID_UNLOCK_DAT1;
        *(fp+CFI_RDID_UNLOCK_ADR2)=CFI_RDID_UNLOCK_DAT2;
        *(fp+CFI_RDID_ADR)=CFI_RDID_CMD;

        flashid[0]=fp[0];
        flashid[1]=fp[1];
        flashid[2]=fp[2];
        flashid[3]=fp[3];

        *(fp) = CFI_CMD_EXIT1;
        *(fp) = CFI_CMD_EXIT2;

    }
#endif  // defined(__SERIAL_FLASH__)
    return;
}


//-----------------------------------------------------------------------------
/*!
  @brief
    Determine whether SF ID is valid.
    Apply for MT6250 MT6260/61/2501/2502 because after command issue(ex: Read ID), Data pins are in floating, may read trasient value instead of 0x00 or 0xFF.
  @retval
    KAL_TRUE: the device ID0 is valid.
    KAL_FALSE: the device ID0 is not valid.  
*/
kal_bool CMEM_EMIINIT_CheckValidDeviceID(kal_uint8 *id)
{
		// Serial Flash
#if defined(__SERIAL_FLASH__)
    kal_int32 i, j;
    const CMEMEntryID *id_list=NULL;
	// seach CMEM list for specific Flash ID
#ifdef   __SV5_ENABLED__
    id_list=combo_mem_id_list.m_data.List;
#else
    id_list=combo_mem_id_list.List;
#endif

    for (i=0; i<COMBO_MEM_DEVICE_COUNT; i++)    {
        // Check 1: Compare ID
        for (j=0; j<id_list[i].IDLength; j++) {
            if (id_list[i].ID[j]!=id[j]) break;            
        }
        // Check 2: Compare RegionInfo
        if (j==id_list[i].IDLength)   {
            // TBD: Compare RegionInfo
           return KAL_TRUE;
        }
    }
  
#endif //defined(__SERIAL_FLASH__)
    return KAL_FALSE;
}



//-----------------------------------------------------------------------------
/*!
  @brief
    Search device ID list
  @retval
    The index to the found device ID.
    -1: device not found
  @remarks
    This function is only allowed in EMI/SFI init stage.
*/
#if defined(__COMBO_MEMORY_SUPPORT__)
#if defined(__DUAL_SERIAL_FLASH_SUPPORT__)
kal_int32 CMEM_EMIINIT_Index(const kal_uint16 CS)
#else
kal_int32 CMEM_EMIINIT_Index()
#endif
{
    kal_int32 i, j;
    CMEMFlashID id;
    const CMEMEntryID *id_list=NULL;

#if !defined(__DUAL_SERIAL_FLASH_SUPPORT__)// Dual SF will enter this function two times
    if (cmem_emiinit_index>=0) return cmem_emiinit_index;
#endif
    // Read Flash ID
#if defined(_NAND_FLASH_BOOTING_)
    #if defined(__UBL__)
    NFI_ReadID(8, id.NAND);
    #else
    return CMEM_INVALID_INDEX;
    #endif
#else
    #if defined(__DUAL_SERIAL_FLASH_SUPPORT__)
    CMEM_EMIINIT_ReadID(CS, (void*)NOR_FLASH_BASE_ADDRESS, id.NOR);
	#else //ADMUX, SF without Dual SF enable
    CMEM_EMIINIT_ReadID(0, (void*)NOR_FLASH_BASE_ADDRESS, id.NOR);
	#endif
#endif

// seach CMEM list for specific Flash ID
#ifdef   __SV5_ENABLED__
    id_list=combo_mem_id_list.m_data.List;
#else
    id_list=combo_mem_id_list.List;
#endif

    for (i=0; i<COMBO_MEM_DEVICE_COUNT; i++)    {
        // Check 1: Compare ID
        for (j=0; j<id_list[i].IDLength; j++) {
            #if defined(_NAND_FLASH_BOOTING_)
            if (id_list[i].ID[j]!=id.NAND[j]) break;
            #else // Serial Flash / NOR Flash
            if (id_list[i].ID[j]!=id.NOR[j]) break;
            #endif
        }
        // Check 2: Compare RegionInfo
        if (j==id_list[i].IDLength)   {
            // TBD: Compare RegionInfo
            cmem_emiinit_index=i;
            break;
        }
    }
    return cmem_emiinit_index;  // entry not found
}

#else  // __COMBO_MEMORY_SUPPORT__
#if defined(__DUAL_SERIAL_FLASH_SUPPORT__)
kal_int32 CMEM_EMIINIT_Index(const kal_uint16 CS)
#else
kal_int32 CMEM_EMIINIT_Index()
#endif
{
    return 0;
}

#ifdef __MTK_TARGET__
#pragma arm section code
#endif /* __MTK_TARGET__ */

#endif // __COMBO_MEMORY_SUPPORT__

#endif //  defined(__COMBO_MEMORY_SUPPORT__) || defined(__SERIAL_FLASH__)


