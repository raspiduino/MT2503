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
 *  brom_base.h
 *
 * Project:
 * --------
 *  BootRom Library
 *
 * Description:
 * ------------
 *  BootRom base class with basic bootrom command implementation.
 *
 *******************************************************************************/
#ifndef   _BROM_BASE_H_
#define   _BROM_BASE_H_

#include "brom.h"
#include "bbchip_id.h"
#include "GPS_DL_api.h"
#include <stdio.h>
   
//-----------------------------------------------------------------------------
// BootROM base class                                                          
   // bootrom start command
int BRom_StartCmd(GPS_Download_Arg arg);

   // boot FlashTool download mode
int Boot_FlashTool(const s_BOOT_FLASHTOOL_ARG  *p_arg, GPS_Download_Arg arg);


   // bootrom command
int BRom_WriteBuf(GPS_Download_Arg arg,
                        unsigned int ulBaseAddr,
                        const unsigned char *buf_in, 
                        unsigned int num_of_byte);
int BRom_CheckSumCmd(GPS_Download_Arg arg, unsigned int baseaddr,
                        unsigned int num_of_word, unsigned short *result);
int BRom_JumpCmd(GPS_Download_Arg arg, unsigned int addr);
int BRom_CmdSend(GPS_Download_Arg arg, unsigned char cmd);
int BRom_OutData(GPS_Download_Arg arg, unsigned int data);

#endif
//-----------------------------------------------------------------------------
