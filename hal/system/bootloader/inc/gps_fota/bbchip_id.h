/*******************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2004
 *
 ******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  bbchip_id.h
 *
 * Project:
 * --------
 *  Flash Download/Format Library.
 *
 * Description:
 * ------------
 *  Baseband Chip ID module.
 *
 *******************************************************************************/
#ifndef  _ROM_ID_H_
#define  _ROM_ID_H_

//-----------------------------------------------------------------------------
// FAT info                                                                    
//-----------------------------------------------------------------------------
typedef struct FlashDeviceKey {
   unsigned short m_ManufactureId;
   unsigned short m_DeviceCode;
   unsigned short m_ExtDeviceCode1;
   unsigned short m_ExtDeviceCode2;
}s_FlashDeviceKey;

#endif
