/******************************************************************************
 * ell_fota_memory_define.h - 
 * 
 * Copyright .
 * 
 * DESCRIPTION: - 
 *        fota相关的存储空间地址配置定义 MT2503D
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
#define WRITE_NEW_TRACK_RW_ADRR         0x50000 
#define WRITE_NEW_TRACK_NVRAM_ADRR      0x55000

//RO 0-79  RW 80-84 NVRAM 85-90
#define ERASE_TRACK_BLOCK_SIZE          91
#define ERASE_TRACK_RO_BLOCK_BEGIN      0
#define ERASE_TRACK_RO_BLOCK_END        79
#define ERASE_TRACK_RW_BLOCK_BEGIN      80
#define ERASE_TRACK_RW_BLOCK_END        84
#define ERASE_TRACK_NVRAM_BLOCK_BEGIN   85
#define ERASE_TRACK_NVRAM_BLOCK_END     90

//track_drv_system_param.c
#define DISK1_START_ADD                 0x103A0000 
#define DISK1_ASSI_START_ADD            0x58000          //88
#define IT0_PARAMETER_ADD               (DISK1_ASSI_START_ADD)
#define IT1_IMPORTANCE_ADD              (IT0_PARAMETER_ADD + 1024)
#define IT2_PHONE_NUMBER_ADD            (IT1_IMPORTANCE_ADD + 2048)
#define IMPORT_USER_SUT                 (IT1_IMPORTANCE_ADD+DISK1_START_ADD)
#define DISK1_BACKUP_ADD                0x5D000          //93

//ell_update_net_apn.c
//track_drv_system_param.c
#define DISK1_LAST_SECTOR_ADD           0x5F000          //95

#endif  /* _ELL_FOTA_MEMORY_DEFINE_H */

