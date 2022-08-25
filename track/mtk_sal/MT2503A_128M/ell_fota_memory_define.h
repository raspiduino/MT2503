/******************************************************************************
 * ell_fota_memory_define.h - 
 * 
 * Copyright .
 * 
 * DESCRIPTION: - 
 *        fota相关的存储空间地址配置定义 MT2503A
 * 
 * modification history
 * --------------------
 * v1.0   2017-01-09,  chengjun create this file
 * 
 ******************************************************************************/
#ifndef _ELL_FOTA_MEMORY_DEFINE_H
#define _ELL_FOTA_MEMORY_DEFINE_H

//ell_update.c
#define WRITE_NEW_TRACK_RO_ADRR         0x0 
#define WRITE_NEW_TRACK_RW_ADRR         0xC0000  
#define WRITE_NEW_TRACK_NVRAM_ADRR      0xD0000 

//1024-160
//RO 0-191 ,RW 192-207 ,NVRAM 208-223
#define ERASE_TRACK_BLOCK_SIZE          224
#define ERASE_TRACK_RO_BLOCK_BEGIN      0
#define ERASE_TRACK_RO_BLOCK_END        191
#define ERASE_TRACK_RW_BLOCK_BEGIN      192
#define ERASE_TRACK_RW_BLOCK_END        207
#define ERASE_TRACK_NVRAM_BLOCK_BEGIN   208
#define ERASE_TRACK_NVRAM_BLOCK_END     223

//track_drv_system_param.c
#define DISK1_START_ADD                 0x10F00000 
#define DISK1_ASSI_START_ADD            0xDC000          //220
#define IT0_PARAMETER_ADD               (DISK1_ASSI_START_ADD)
#define IT1_IMPORTANCE_ADD              0xDD000	//(IT0_PARAMETER_ADD + 1024) //221
#define IT2_PHONE_NUMBER_ADD            (IT0_PARAMETER_ADD + 3072)	//(IT1_IMPORTANCE_ADD + 2048)

#define IMPORT_USER_SUT                 (IT1_IMPORTANCE_ADD+DISK1_START_ADD)
#define DISK1_BACKUP_ADD                0xE0000          //224

//ell_update_net_apn.c
//track_drv_system_param.c
#define DISK1_LAST_SECTOR_ADD           0xF0000          //240

#endif  /* _ELL_FOTA_MEMORY_DEFINE_H */

