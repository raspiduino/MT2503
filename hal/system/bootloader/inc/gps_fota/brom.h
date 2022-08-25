/*******************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2003
 *
 ******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  brom.h
 *
 * Project:
 * --------
 *  BootRom Library
 *
 * Description:
 * ------------
 *  Exported C interface APIs for BootRom library.
 *
 *******************************************************************************/
#ifndef _BROM_H_
#define _BROM_H_


#ifdef   __cplusplus
extern "C" {
#endif

// The magic value to stop boot process 
#define BOOT_STOP 9876

// boot infinitely
#define BOOT_INFINITE   0xFFFFFFF

// default start cmd retry count 
#define DEFAULT_BROM_START_CMD_RETRY_COUNT   1

//------------------------------------------------------------------------------
// Boolean                                                                      
//------------------------------------------------------------------------------
typedef enum {
   _FALSE = 0,
   _TRUE = 1
} _BOOL;

//------------------------------------------------------------------------------
// return code                                                                  
//------------------------------------------------------------------------------

#define BROM_RET(ret)   (ret&0x00FF0000)

#define BROM_OK                           0x000000
#define BROM_ERROR                        0x010000
#define BROM_NO_MEMORY                    0x020000
#define BROM_INVALID_ARGUMENTS            0x030000
#define BROM_SET_COM_STATE_FAIL           0x040000
#define BROM_PURGE_COM_FAIL               0x050000
#define BROM_SET_META_REG_FAIL            0x060000
#define BROM_SET_FLASHTOOL_REG_FAIL       0x070000
#define BROM_SET_REMAP_REG_FAIL           0x080000
#define BROM_SET_MEM_WAIT_STATE_FAIL      0x090000
#define BROM_DOWNLOAD_DA_FAIL             0x0A0000
#define BROM_CMD_START_FAIL               0x0B0000
#define BROM_CMD_JUMP_FAIL                0x0C0000
#define BROM_CMD_WRITE16_MEM_FAIL         0x0D0000
#define BROM_CMD_READ16_MEM_FAIL          0x0E0000
#define BROM_CMD_WRITE16_REG_FAIL         0x0F0000
#define BROM_CMD_READ16_REG_FAIL          0x100000
#define BROM_CMD_CHKSUM16_MEM_FAIL        0x110000
#define BROM_CMD_WRITE32_MEM_FAIL         0x120000
#define BROM_CMD_READ32_MEM_FAIL          0x130000
#define BROM_CMD_WRITE32_REG_FAIL         0x140000
#define BROM_CMD_READ32_REG_FAIL          0x150000
#define BROM_CMD_CHKSUM32_MEM_FAIL        0x160000
#define BROM_WR16_RD16_MEM_RESULT_DIFF    0x170000
#define BROM_WR16_RD16_REG_RESULT_DIFF    0x180000
#define BROM_WR32_RD32_MEM_RESULT_DIFF    0x190000
#define BROM_WR32_RD32_REG_RESULT_DIFF    0x1A0000
#define BROM_CHKSUM16_MEM_RESULT_DIFF     0x1B0000
#define BROM_CHKSUM32_MEM_RESULT_DIFF     0x1C0000
#define BROM_BBCHIP_HW_VER_INCORRECT      0x1D0000
#define BROM_FAIL_TO_GET_BBCHIP_HW_VER    0x1E0000
#define BROM_SKIP_BBCHIP_HW_VER_CHECK     0x1F0000
#define BROM_UNKNOWN_BBCHIP               0x200000
#define BROM_UNKNOWN_TGT_BBCHIP           0x210000
#define BROM_BBCHIP_DSP_VER_INCORRECT     0x220000
#define BROM_MULTIPLE_BAUDRATE_FAIL       0x230000
#define BROM_JUMP_TO_NFB_DETECTION_FAIL   0x240000


//------------------------------------------------------------------------------
// boot FlashTool download mode                                                 
//------------------------------------------------------------------------------
typedef struct BOOT_FLASHTOOL_ARG{

   // [IN] the PC side bbchip revsion name that is used to compare with target bbchip 
   // eg: "MT6218B_EN", if this field is NULL it will skip comparison with target bbchip 
   const char     *m_p_bbchip_name;

   // Download Agent 
   unsigned int         m_da_start_addr;     // DA start address 
   const unsigned char  *m_da_buf;           // buffer stored DA code 
   unsigned int         m_da_len;            // length of DA buffer 

   // This callback function will be invoke after BootROM start cmd is passed. 
   // You can issue other BootROM command by brom_handle and hCOM which provides callback arguments, 
   // or do whatever you want otherwise. 
   //CALLBACK_IN_BROM_STAGE  m_cb_in_brom_stage;
   //void  *m_cb_in_brom_stage_arg;

} s_BOOT_FLASHTOOL_ARG;


#ifdef   __cplusplus
}
#endif

#endif


