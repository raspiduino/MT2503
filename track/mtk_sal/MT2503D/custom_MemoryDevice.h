/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *   custom_MemoryDevice.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the part number of physical memory device,
 *   and flash logical layout configure.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __CUSTOM_MEMORYDEVICE__
#define __CUSTOM_MEMORYDEVICE__

/*
 ****************************************************************************
 [README , VERY IMPORTANT NOTICE]
 --------------------------------
 After user configured this C header file, not only C compiler compile it but
 also auto-gen tool parse user's configure setting.
 Here are recommend configure convention to make both work fine.

 1. All configurations in this file form as #define MACRO_NAME MACRO_VALUE format.
    Note the #define must be the first non-space character of a line

 2. To disable the optional configurable item. Please use // before #define,
    for example: //#define MEMORY_DEVICE_TYPE

 3. Please don't use #if , #elif , #else , #endif conditional macro key word here.
    Such usage might cause compile result conflict with auto-gen tool parsing result.
    Auto-Gen tool will show error and stop.
    3.1.  any conditional keyword such as #if , #ifdef , #ifndef , #elif , #else detected.
          execpt this #ifndef __CUSTOM_MEMORYDEVICE__
    3.2.  any duplicated MACRO_NAME parsed. For example auto-gen tool got 
          2nd MEMORY_DEVICE_TYPE macro value.
 ****************************************************************************
*/

/*
 ****************************************************************************
 Step 1: Specify memory device type and its complete part number
         Possible memory device type: NOR_RAM_MCP, LPSDRAM, NOR_LPSDRAM_MCP, SERIAL_FLASH
 ****************************************************************************
*/
#define MEMORY_DEVICE_TYPE    SERIAL_FLASH
#define CS0_PART_NUMBER       MTKSIP_6261_SF_32_01
#define CS1_PART_NUMBER       MTKSIP_6261_SF_32_01
/*
 ****************************************************************************
 Step 2: Specify part number for each device chosen when COMBO_MEMORY_SUPPORT is enabled
         Please note that this section will only be used when COMBO_MEMORY_SUPPORT is enabled,
         and will be ignored if COMBO_MEMORY_SUPPORT is disabled
 ****************************************************************************
*/
#define COMBO_MEM_ENTRY_COUNT 6
	
#define COMBO_MEM01_CS0_PART_NUMBER MTKSIP_6261_SF_32_03
#define COMBO_MEM01_CS1_PART_NUMBER MTKSIP_6261_SF_32_03
	
#define COMBO_MEM02_CS0_PART_NUMBER MTK_INTERNAL_MX25U12835FZNI_10G_FAKE32Mbits
#define COMBO_MEM02_CS1_PART_NUMBER MTK_INTERNAL_MX25U12835FZNI_10G_FAKE32Mbits
	
#define COMBO_MEM03_CS0_PART_NUMBER MTKSIP_6261_SF_32_04
#define COMBO_MEM03_CS1_PART_NUMBER MTKSIP_6261_SF_32_04

#define COMBO_MEM04_CS0_PART_NUMBER MTKSIP_6261_SF_32_05
#define COMBO_MEM04_CS1_PART_NUMBER MTKSIP_6261_SF_32_05

#define COMBO_MEM05_CS0_PART_NUMBER MTKSIP_6261_SF_32_01
#define COMBO_MEM05_CS1_PART_NUMBER MTKSIP_6261_SF_32_01

#define COMBO_MEM06_CS0_PART_NUMBER MTKSIP_6261_SF_32_02
#define COMBO_MEM06_CS1_PART_NUMBER MTKSIP_6261_SF_32_02




/*
 ****************************************************************************
 Step 3: Specify access type for NOR_RAM_MCP; for LPSDRAM and serial Flash, just assign
         UNDEF_ACCESS to both items (NOR_ACCESS_TYPE and RAM_ACCESS_TYPE)
         Possible access types: ASYNC_ACCESS,
                                SYNC_ACCESS,
                                UNDEF_ACCESS
 ****************************************************************************
*/
#define FLASH_ACCESS_TYPE     ASYNC_ACCESS
#define RAM_ACCESS_TYPE       SYNC_ACCESS

/*
 ****************************************************************************
 Step 4: Define the clock frequency of EMI and SFI

         By default, the highest EMI speed that can be supported by memory will be used 
         (define EMI_CLK to be DEFAULT).
         By specifying EMI_CLK to be ¡§104M¡¨, ¡§52M¡¨, ¡§166M¡¨, or ¡§200M¡¨ can force EMI/memory to be configured
         running at 104MHz, 52MHz, 166MHz, or 200MHz for special purpose.
         Please note that this feature is only available on MT6253D and MT6276! All other chip must set to 
         DEFAULT configuration.
         Available EMI_CLK configurations are:
         MT6253D: 104M, 52M, DEFAULT
         MT6276: 166M, 200M, DEFAULT
         other: DEFAULT

         For SFI, the highest SFI speed that can be supported by memory will be used by default
         (define SFI_CLK to be DEFAULT)
         By specifying SFI_CLK to be "130M", "104M" or "78M" can force SFI to be configured running
         at 130MHz, 104MHz or78MHz for special purpose.
         Please note that this feature is only available for platforms which support Serial Flash!
 ****************************************************************************
*/
#define EMI_CLK                 DEFAULT
#define SFI_CLK                 DEFAULT

/*
 ****************************************************************************
 Step 5: FDM Version Choose

         MTK NOR FDM is upgraded to 5.0 from 2006/Q3 to support large NOR-flash
         disk (multi-bank), for example, disk space larger than 64blocks.
         
         The major difference of NOR FDM 5.0 and NOR FDM 4.0 as below:
         1. RAM consumption
            To manage 32MB INTEL M18 NOR-flash disk, FDM 5.0 consumes 1KB,
            but FDM 4.0 takes 32KB.
         2. Addressable block numbers
            The addressable space of NOR FDM 5.0 is 65K-1 blocks, but NOR FDM 4.0
            is limited at 128-1 blocks.
         3. Idle reclaim and manual reclaim are implemented on NOR FDM 5.0.

         To enable NOR FDM 5.0 on NOR-flash disk, please enable the following 
         definition and customize custom_flash_norfdm5.c; the option is switch on/off 
         at customer site without deliver new library.
         
         [REMIND]
         ========
         To manage small disk space, like smaller than 64 blocks, FDM 4.0 is
         recommended.

 ****************************************************************************
*/
#define __NOR_FDM5__

/*
 ****************************************************************************
 Step 6: This is an optional step special for NOR-XIP configuration only.
 
         This step configures the FS (file system) region information on NOR FLASH!

         By default, FS region is located the last bank of NOR Flash.
         For specific purpose, user are able to manually configure the
         
         Step 1. Start address of FS region on NOR-flash,
         Step 2. Total FS size on NOR-flash disk
         Step 3. The first drive (or partition) size of FS region. if no additional drive
                 on NOR-flash disk, it should be 0. For more details, please refer to REMIND.
         
         [REMIND]
         ========
         It is special for flash disk which has two drives (or partitions), the
         first leading is user drive, visible on USB disk, the second may be
         system drive, and invisible from USB disk.

         [VERY IMPORTANT NOTICE]
         =======================
         1. Disable this definition and make auto Gen pick default setting from
            Memory Device Excel Database is recommend.
            
         2. Please assign the exact integer value in terms of sectors (one sector equal
            to 512 Bytes) in NOR_BOOTING_NOR_FS_FIRST_DRIVE_SECTORS.
            MUST NOT assign as
            (TOTAL_FS_SIZE - SIZE_OF_SYSTEM_DRIVE), because system will keep
            some spaces for disk management.

 ****************************************************************************
*/
//These are configured for the MT2503D
//chengj

//#define NOR_BOOTING_NOR_FS_BASE_ADDRESS 0x003B9000
//#define NOR_BOOTING_NOR_FS_SIZE 0x00047000
#define NOR_BOOTING_NOR_FS_BASE_ADDRESS          0x02E0000
#define NOR_BOOTING_NOR_FS_SIZE                  0x00B0000  //MagicNing    0x00F0000
#define NOR_BOOTING_NOR_FS_FIRST_DRIVE_SECTORS    0

/*
 ****************************************************************************
 Step 7: For NOR raw disk configuration, if "NOR SUPPORT RAW DISK"
 
         If raw disk feature turns on, user are able to manully config the
         
         Step 1. Number of raw disk region, it should be 1 or 2.
         Step 2. Start address of raw disk region(s)
         Step 3. Total size of raw disk region(s)
         
         [REMIND]
         ========
         If project with __SYSDRV_BACKUP_DISK_RAW__ defined, the first disk
         would be treated as backup partition to backup NVRAM data.

         [VERY IMPORTANT NOTICE]
         =======================
         1. The values in step 1~3 MUST be set if __NOR_SUPPORT_RAW_DISK__ defined
         
         2. The raw disk region and FS region cannot be overlapped
         
         3. Both the start address and size should be block aligned
         
 ****************************************************************************
*/         

//#define NOR_BOOTING_NOR_DISK_NUM             2
//#define NOR_BOOTING_NOR_DISK0_BASE_ADDRESS   0x1C00000
//#define NOR_BOOTING_NOR_DISK0_SIZE         0x200000

//#define NOR_BOOTING_NOR_DISK1_BASE_ADDRESS   0x1E00000
//#define NOR_BOOTING_NOR_DISK1_SIZE         0x1E0000

#define NOR_BOOTING_NOR_DISK_NUM             2
#define NOR_BOOTING_NOR_DISK0_BASE_ADDRESS   0x0390000  //MagicNing    0x1C00000
#define NOR_BOOTING_NOR_DISK0_SIZE                  0x0010000    //MagicNing    0x200000

#define NOR_BOOTING_NOR_DISK1_BASE_ADDRESS  0x03A0000   //MagicNing    0x1E00000
#define NOR_BOOTING_NOR_DISK1_SIZE                  0x0060000    //MagicNing    0x1E0000

/*
 ****************************************************************************
 Step 8: For NOR-XIP configuration, if
 
         1. "SYSTEM DRIVE ON NAND" or 
         2. "SYSTEM DRIVE ON NOR" and FOTA "UPDATE PACKAGE ON NAND" 
         
         feature is enabled. Users are responsible to specify FS (file system) region 
         information on NAND-flash here!
         
         Step 1. Start address of FS region on NAND-flash,
         Step 2. Total FS size on NAND-flash disk
         Step 3. The first drive (or partition) size of FS region. if no additional drive
                 on NAND-flash disk, it should be 0. For more details, please refer to REMIND 1 and 2.
            
         For example, on 128MB NAND-flash, because code is already located on NOR flash,
         total 128MB NAND-flash space is reserved for NAND-flash disk. Reserve ~110MB for user drive,
         remain around 15MB for system drive.
         
         #define NOR_BOOTING_NAND_FS_BASE_ADDRESS        0x00000000
         #define NOR_BOOTING_NAND_FS_SIZE                0x08000000  // 128MB
         #define NOR_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS 220000      // 110000KB
         
         [REMIND]
         ========
         1. It is special for flash disk which has two drives (or partitions), the
            first leading is user drive, visible on USB disk, the second may be
            system drive, and invisible from USB disk.
         
         2. For projects with __UP_PKG_ON_NAND__ defined, NOR_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS will
            be ignored. That is, NAND flash is allowed to create only one drive (or partition) in this case.
            
         3. For "SYSTEM DRIVE ON NOR" and FOTA "UPDATE PACKAGE ON NAND" configuration, FOTA
            update package will be located in the top of FS region by default. Auto-Gen will
            reserve required space automatically.

         [VERY IMPORTANT NOTICE]
         =======================
         1. The values in step 1~3 MUST be set if __FS_SYSDRV_ON_NAND__ or __UP_PKG_ON_NAND__ is defined !!
         
         2. The spare area is excluding from the FS SPACE !!
            
         3. Please assign the exact integer value in terms of sectors (one sector equal
            to 512 Bytes) in NOR_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS.
            MUST NOT assign as
            (TOTAL_FS_SIZE - SIZE_OF_SYSTEM_DRIVE), because system will keep
            some spaces for disk management.

 ****************************************************************************
*/

#define NOR_BOOTING_NAND_FS_BASE_ADDRESS           0x00000000
#define NOR_BOOTING_NAND_FS_SIZE                   0x08000000
#define NOR_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS    220000

/*
 ****************************************************************************
 Step 9: This is an optional step special for NFB (NAND-flash Booting)
         system only.

         Users are responsible to specify the drives (or partitions) on NAND-flash,
         
         Step 1. Start address of FS region on NAND-flash,
         Step 2. Total FS size on NAND-flash disk
         Step 3. The first drive (or partition) size of FS region. if no additional drive
                 on NAND-flash disk, it should be 0. For more details, please refer to REMIND.

         For example, on 128MB NAND-flash, code segment occupies 32MB, the
         balanced 96MB is reserved for NAND-flash disk. Reserve ~80MB for user drive,
         remain around 15MB for system drive.

         #define NAND_BOOTING_NAND_FS_BASE_ADDRESS         0x02000000   // 32MB
         #define NAND_BOOTING_NAND_FS_SIZE                 0x06000000   // 96MB
         #define NAND_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS  160000       // 80000KB
         
         [REMIND]
         ========
         It is special for NAND-flash disk which has two drives (or partitions), the
         first leading is user drive, visible on USB disk, the second may be
         system drive or user drive.

         [VERY IMPORTANT NOTICE]
         =======================
         1. All values MUST be set if _NAND_FLASH_BOOTING_ are defined !!
         
         2. The spare area is excluding from the FS SPACE !!
         
         3. Please assign the exact integer value in terms of sectors (one sector equal
            to 512 Bytes) in NAND_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS.
            MUST NOT assign as
            (TOTAL_FS_SIZE - SIZE_OF_SYSTEM_DRIVE), because system will keep
            some spaces for disk management.
 ****************************************************************************
*/

#define NAND_BOOTING_NAND_FS_BASE_ADDRESS         0x02000000
#define NAND_BOOTING_NAND_FS_SIZE                 0x06000000
#define NAND_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS  160000

//#define NAND_BOOTING_NAND_FS_DISK_NUMBER		  	4
//#define NAND_BOOTING_NAND_FS_DISK0_BASE_ADDRESS		0x01800000
//#define NAND_BOOTING_NAND_FS_DISK0_SIZE				0x03800000
//#define NAND_BOOTING_NAND_FS_DISK0_REPLACE_RATIO	20			// Unit is 0.1% . 0 is using default value.
//#define NAND_BOOTING_NAND_FS_DISK1_BASE_ADDRESS		0x05000000
//#define NAND_BOOTING_NAND_FS_DISK1_SIZE				0x00800000
//#define NAND_BOOTING_NAND_FS_DISK1_REPLACE_RATIO	20			// Unit is 0.1% . 0 is using default value.
//#define NAND_BOOTING_NAND_FS_DISK2_BASE_ADDRESS		0x05800000
//#define NAND_BOOTING_NAND_FS_DISK2_SIZE				0x02000000
//#define NAND_BOOTING_NAND_FS_DISK2_REPLACE_RATIO	20			// Unit is 0.1% . 0 is using default value.
//#define NAND_BOOTING_NAND_FS_DISK3_BASE_ADDRESS		0x07800000
//#define NAND_BOOTING_NAND_FS_DISK3_SIZE				0x00800000
//#define NAND_BOOTING_NAND_FS_DISK3_REPLACE_RATIO	20			// Unit is 0.1% . 0 is using default value.
//#define NAND_BOOTING_NAND_FS_DISK4_BASE_ADDRESS		0x00000000
//#define NAND_BOOTING_NAND_FS_DISK4_SIZE				0x00000000
//#define NAND_BOOTING_NAND_FS_DISK4_REPLACE_RATIO	00			// Unit is 0.1% . 0 is using default value.
//#define NAND_BOOTING_NAND_FS_DISK5_BASE_ADDRESS		0x00000000
//#define NAND_BOOTING_NAND_FS_DISK5_SIZE				0x00000000
//#define NAND_BOOTING_NAND_FS_DISK5_REPLACE_RATIO	00			// Unit is 0.1% . 0 is using default value.
//#define NAND_BOOTING_NAND_FS_DISK6_BASE_ADDRESS		0x00000000
//#define NAND_BOOTING_NAND_FS_DISK6_SIZE				0x00000000
//#define NAND_BOOTING_NAND_FS_DISK6_REPLACE_RATIO	00			// Unit is 0.1% . 0 is using default value.
//#define NAND_BOOTING_NAND_FS_DISK7_BASE_ADDRESS		0x00000000
//#define NAND_BOOTING_NAND_FS_DISK7_SIZE				0x00000000
//#define NAND_BOOTING_NAND_FS_DISK7_REPLACE_RATIO	00			// Unit is 0.1% . 0 is using default value.

/*
 ****************************************************************************
 Step 10: This is an optional step special for eMMC booting system only.

         Users are responsible to specify the drives (or partitions) on eMMC,

         Step 1. Start address of FS region on eMMC,
         Step 2. Total FS size on NAND-flash disk
         Step 3. The system drive size of FS region. It must be a positive integer.

         For example, all User Area Partition will be used as FS region, 
         and reserve ~2.5MB for system drive,

         #define EMMC_BOOTING_UP_FS_BASE_ADDRESS         0          // 32MB
         #define EMMC_BOOTING_UP_FS_SIZE                 0          // All User Area Partition will be used as File System
         #define EMMC_BOOTING_UP_FS_SYSTEM_DRIVE_SIZE    5000       // 80000KB

         [VERY IMPORTANT NOTICE]
         =======================
         1. All values MUST be set if __EMMC_BOOTING__ is defined !!

         2. Please assign the exact integer value in terms of sectors (one sector equal
            to 512 Bytes) in EMMC_BOOTING_UP_FS_SYSTEM_DRIVE_SIZE.
 ****************************************************************************/

#define EMMC_BOOTING_GP1_PARTITION_SIZE             0x10000000       // GP is general purpose partition for code
#define EMMC_BOOTING_GP2_PARTITION_SIZE             0       // Reserved now
#define EMMC_BOOTING_GP3_PARTITION_SIZE             0       // Reserved now
#define EMMC_BOOTING_GP4_PARTITION_SIZE             0       // Reserved now
#define EMMC_BOOTING_UP_FS_BASE_ADDRESS             0       // UP is user area partition for file system. File system base address (Range: 0 to 0xFFFF_FFFF_FFFF_FFFF)
#define EMMC_BOOTING_UP_FS_SIZE                     0       // File system size. 0 means the all UP will be used for FS (Range: 0 to 0xFFFF_FFFF_FFFF_FFFF)
#define EMMC_BOOTING_UP_FS_SYSTEM_DRIVE_SIZE        5000    // System drive size (Unit: #Sectors)

#define EMMC_BOOTING_CODE_PARTITION_SIZE            0
#define EMMC_BOOTING_FS_SYSTEM_DRIVE_SIZE           5000

/*
 ****************************************************************************
 Step 11. Enhanced Single Bank NOR Flash Support Configure Parameter

         Modify the size of block erase queue, which is the number of reserved 
         blocks. It is recommended to be 10~20% of TOTAL_BLOCK value.
         This value should be at least 3. Setting value less than 3 will cause errors.
         When FS size is reduced (by configuring NOR_ALLOCATED_FAT_SPACE), 
         set this value to 3 to avoid insufficient system drive space.

         [VERY IMPORTANT NOTICE]
         =======================
         Recommend comment out this value and use default setting.
         Only for Enhanced Single Bank NOR Flash support
 ****************************************************************************
*/
#define NOR_FDM4_ESB_PARAMETER_ERASE_QUEUE_SIZE    3

/*
 ****************************************************************************
 Step 12. Multi Bank NOR Flash Configure Parameter

         Modify the size of system drive reserved blocks. 
         It is recommended to be 10~20% of TOTAL_BLOCK value.
         This value should be at least 3. Setting value less than 3 will cause errors.
         When FS size is reduced (by configuring NOR_ALLOCATED_FAT_SPACE), 
         set this value to 3 to avoid insufficient system drive space.
         The basic unit is 0.5 block. For example, reserved blocks can be set to 3.5 blocks.

         [VERY IMPORTANT NOTICE]
         =======================
         Recommend comment out this value and use default setting.
         Only for Multi Bank NOR Flash configuration
 ****************************************************************************
*/
//#define NOR_PARAMETER_SYSTEM_DRIVE_RESERVED_BLOCK  3


#endif /* __CUSTOM_MEMORYDEVICE__ */
