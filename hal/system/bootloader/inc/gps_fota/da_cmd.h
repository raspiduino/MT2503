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
 *  da_cmd.h
 *
 * Project:
 * --------
 *  Flash Download/Format Library.
 *
 * Description:
 * ------------
 *  DA(Download Agent) handshake command.
 *
 *******************************************************************************/
#ifndef  _DA_CMD_H_
#define  _DA_CMD_H_

#include "flashtool.h"

#define UART_READ_WRITE_MAX_RETRY      0
#define UART_READ_WRITE_RETRY_SLEEP      100
#define UART_BAUDRATE_FULL_SYNC_COUNT   20
#define UART_ERR_RETRY_TIMEOUT         99

//------------------------------------------------------------------------------
// DA Command Object                                                            
//------------------------------------------------------------------------------

int WriteData(GPS_Download_Arg arg, const void *write_buf, unsigned int write_len);
int ReadData(GPS_Download_Arg arg, void *read_buf, unsigned int read_len);

int CMD_SetMemBlock(GPS_Download_Arg arg, ROM_HANDLE_T  *dl_handle);

int CMD_Finish(GPS_Download_Arg arg);

int CMD_WriteData(
               GPS_Download_Arg arg,
               ROM_HANDLE_T  *dl_handle,
               CALLBACK_DOWNLOAD_PROGRESS_INIT  cb_download_flash_init,  void *cb_download_flash_init_arg,
               CALLBACK_DOWNLOAD_PROGRESS  cb_download_flash,  void *cb_download_flash_arg);

#endif
