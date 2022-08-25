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
 *    flash_mtd_sf_common.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This is flash common driver for serial flash
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
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/
#include "flash_opt.h"
#include "flash_sfi_release.h"

#ifdef __SERIAL_FLASH__

#ifdef __SF_DVT__
#include "flash_mtd_sf_dvt.h"
#include "flash_mtd_sf_dal.h"
#else
#include "kal_general_types.h"
#include "flash_mtd_internal.h"
#include "reg_base.h"
#include "flash_sf.h"
#include "flash_mtd_sf_dal.h"
#include "kal_release.h"
#include "sfi_hw.h"
#endif

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined(__MTK_TARGET__)
#if defined(__UBL__)
#pragma arm section code = "INTERNCODE"
#else
#pragma arm section code = "SNORCODE"
#endif
#endif

#if defined(MT6251) || defined(MT6252)
    #define SF_1T_WORKAROUND
        #define SFI_IsQPIMode()      (SFI_ReadReg32(RW_SFI_MAC_CTL) & SFI_QPI_EN)
        /*MT6251/52 has no CS1, this function just for compatible to MT6250*/
        #define SFI_IsQPIMode_CS1()  (SFI_ReadReg32(RW_SFI_MAC_CTL) & SFI_QPI_EN)
#elif defined(MT6255) || defined(MT6250) || defined(MT6280) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
        #define SFI_IsQPIMode()      (SFI_ReadReg32(RW_SFI_DIRECT_CTL) & SFI_QPI_EN)
        #define SFI_IsQPIMode_CS1()      (SFI_ReadReg32(RW_SFI_DIRECT_CTL2) & SFI_QPI_EN)
#else
        #error "Undefined Serial Flash Platform"
#endif

//This variable is to support L1 Modem Hard Real Time Enhancement
kal_bool DelayResume = KAL_FALSE;

//Extern APIs
extern kal_bool CMEM_CheckValidDeviceID(kal_uint8 *id);


//Support MT6250 MT6260/61/2501/2502 Mask Code decompressor and LZMA when SFC Macro mode/ Flash busy
extern kal_bool NOR_FLASH_BUSY;
extern kal_bool NOR_FLASH_SUSPENDED;


/*----------------------------
 * Serial Flash Common APIs
 *----------------------------*/

#ifndef __UBL__
void SFI_BlankCheck(void *MTDData, kal_uint32 BlockIndex)
{
   SF_MTD_Data *D = MTDData;
   kal_uint32   i, data_cnt;
   kal_uint32  *p_data;

   data_cnt = BlockSize(MTDData, BlockIndex) / sizeof(kal_uint32);

   for (i = 0, p_data = (kal_uint32*)D->CurrAddr; i < data_cnt; ++i, ++p_data)
   {
      if (*p_data != 0xFFFFFFFF)
      {
         MTD_SNOR_ASSERT(0, __LINE__, 0, 0, NOR_MTD_ERASE_COMP_BLOCK_DATA_FAIL);
      }
   }
}
#endif /* !__UBL__ */

//-----------------------------------------------------------------------------
/*!
  @brief
    Reverse byte order in a DWORD
*/
kal_uint32 SFI_ReverseByteOrder(kal_uint32 num)
{
   unsigned int ret = 0;

   ret |= ((num >> 24) & 0x000000FF);
   ret |= ((num >> 8)  & 0x0000FF00);
   ret |= ((num << 8)  & 0x00FF0000);
   ret |= ((num << 24) & 0xFF000000);

   return ret;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Enter macro mode, and set SFI_MAC_SIO_SEL if QPI mode is enabled.
*/
void SFI_MacEnable(const kal_uint16 CS)
{
    kal_uint32 val;
#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) //Mask SFC AHB Channel 2 and 3 during SFC Mac mode/ Flash busy
    SFI_MaskAhbChannel(1);
#endif

    val = SFI_ReadReg32(RW_SFI_MAC_CTL);
    if(CS == 0x0)
    {
        if (SFI_IsQPIMode())    
            val|=SFI_MAC_SIO_SEL;
    }
    else if(CS == 0x1)
    {   
        if (SFI_IsQPIMode_CS1())    
            val|=SFI_MAC_SIO_SEL;
    }
    else
    {
        MTD_SNOR_ASSERT(0, __LINE__, 0, 0, NOR_MTD_DATA_CORRUPTED);
    }

    val|=SFI_MAC_EN;
	
	//Wait SFC idle before issue Macro command
#if defined(MT6252)
    while (!(SFI_ReadReg32(RW_SFI_MISC_CTL) & SFI_REQ_IDLE));
#endif
    
#if defined(MT6250) &&  !defined(__UBL__) //Wait until SFC AHB Channel 2 and 3 become IDLE before enter Macro mode
     while (!(SFI_ReadReg32(RW_SFI_MISC_CTL3) & SFI_CH2_TRANS_IDLE));
     //while (!(SFI_ReadReg32(RW_SFI_MISC_CTL3) & SFI_CH3_TRANS_IDLE));
     /* SW workaround: Channel3 idle bit will not raise, use SFC idle bit instead.  */
     while (!(SFI_ReadReg32(RW_SFI_MISC_CTL) & SFI_REQ_IDLE));
#elif (defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)) &&  !defined(__UBL__) //Wait until SFC AHB Channel 2 become IDLE before enter Macro mode
     while (!(SFI_ReadReg32(RW_SFI_MISC_CTL3) & SFI_CH2_TRANS_IDLE));
     while (!(SFI_ReadReg32(RW_SFI_MISC_CTL) & SFI_REQ_IDLE));
#endif

    SFI_WriteReg32(RW_SFI_MAC_CTL, val);
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Leaves macro mode, and returns to direct read mode
  @remarks
    MT6251, MT6252, MT6255
*/
void SFI_MacLeave(const kal_uint16 CS)
{
    kal_uint32 val;

    // clear SF_TRIG and leave MACRO mode
    val = SFI_ReadReg32(RW_SFI_MAC_CTL);
    val &= ~(SFI_TRIG | SFI_MAC_SIO_SEL| SFI_MAC_SEL);
    SFI_WriteReg32(RW_SFI_MAC_CTL, val);

#if defined(MT6255) || defined(MT6250) || defined(MT6280) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    // SW workaround for MT625x(after 6255) F2S write early response and Slave engine latency
    while ((SFI_ReadReg32(RW_SFI_MAC_CTL) & SFI_WIP_READY));
#endif
    //Disable SFI_MAC_EN must after polling SFI_WIP_READY for MT6250 HW DCM
    //Because once SFI_MAC_EN is disabled, Idle bit of SFC will be set, HW DCM may gate SFCLK.
    //Then SFI_WIP_READAY will keep high because it depends on SFCLK.
    val = SFI_ReadReg32(RW_SFI_MAC_CTL);
    val &= ~(SFI_MAC_EN);
    SFI_WriteReg32(RW_SFI_MAC_CTL, val);

#if defined(MT6255) || defined(MT6250) || defined(MT6280) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    // SW workaround for MT625x(after 6255) F2S write early response and Slave engine latency
    while ((SFI_ReadReg32(RW_SFI_MAC_CTL) & SFI_MAC_EN)); 
#endif

#if (defined(MT6250) &&  !defined(__UBL__)) || ((defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)) &&  !defined(__UBL__))//UnMask SFC AHB Channel 2 and 3 when Flash is not busy
    /*Notice: This variable has not been initialized during ScanSerialFlashBlcoks() in Init stage*/
    /*SFI channel2 and channel3 may be locked and unable to use in maui if NOR_FLASH_BUSY != KAL_FALSE*/
    /*Solution: Always Unmask SFI channel2 and channel3 in the end of ScanSerialFlashBlocks()*/
    if((NOR_FLASH_BUSY==KAL_FALSE)) 
    {
        SFI_MaskAhbChannel(0);
    }
#endif
   
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Send commands placed in GPRAM (in macro mode)
*/
kal_uint32 SFI_MacTrigger(const kal_uint16 CS)
{
    kal_uint32  val=0;
    kal_uint32  misc_ctl=0;

#ifdef SF_1T_WORKAROUND
    kal_uint32  j;
    kal_uint8   delay1t=0;
    misc_ctl = SFI_ReadReg32(RW_SFI_MISC_CTL);
    j   = SFI_ReadReg32(RW_SFI_MAC_INL);
    delay1t = misc_ctl & 0x80;
    if (j==0 && delay1t!=0)   {
        val = SFI_ReadReg32(RW_SFI_MISC_CTL);
        val &= (0xFFFFFF7F);
        SFI_WriteReg32(RW_SFI_MISC_CTL, val);
    }
#endif // SF_1T_WORKAROUND

    val = SFI_ReadReg32(RW_SFI_MAC_CTL);

    // trigger SFC
    val |= (SFI_TRIG | SFI_MAC_EN);
    if (CS == 0x1)    //for CS1
    {
        val |= SFI_MAC_SEL;
    }

    SFI_WriteReg32(RW_SFI_MAC_CTL, val);

    // wait for SFC ready
    while (!(SFI_ReadReg32(RW_SFI_MAC_CTL) & SFI_WIP_READY));
    while ((SFI_ReadReg32(RW_SFI_MAC_CTL) & SFI_WIP));

    return misc_ctl;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Set trigger and send GPRAM data toward serial Flash
    Leave macro mode when done
*/
void SFI_MacWaitReady(const kal_uint16 CS)
{
#ifdef SF_1T_WORKAROUND
    kal_uint32  misc_ctl;
    misc_ctl = SFI_MacTrigger(CS);
    SFI_MacLeave(CS);
    SFI_WriteReg32(RW_SFI_MISC_CTL, misc_ctl);
#else
    SFI_MacTrigger(CS);
    SFI_MacLeave(CS);
#endif
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Issue generic command to serial Flash (max: 4 bytes)

  @param[in] cmd The command to be sent, the first shift out byte is MSB.
  @remarks This function is only called by bootloader.
           Other callers must be aware of interrupts during the MAC mode
*/
void SFI_Dev_Command(const kal_uint16 CS, const kal_uint32 cmd)
{
    kal_uint32 cmdi, cmdo;
    kal_uint8  len;

    for (cmdi=cmd, len=0, cmdo=0; cmdi!=0 ;cmdi=cmdi>>8, len++)   {
        cmdo = (cmdo<<8) | (cmdi & 0xFF);
    }

    if (len==0) return;

    SFI_MacEnable(CS);
    SFI_WriteReg32(RW_SFI_GPRAM_DATA, cmdo);
    SFI_WriteReg32(RW_SFI_MAC_OUTL, len);
    SFI_WriteReg32(RW_SFI_MAC_INL , 0);
    SFI_MacWaitReady(CS);

    return;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Send command and address to serial Flash

  @param[in] cmd The command to be sent
  @param[in] address The address to be sent, followed by cmd.
  @remarks This function is only called by bootloader.
           Other callers must be aware of interrupts during the MAC mode
*/
void SFI_Dev_CommandAddress(const kal_uint16 CS, const kal_uint8 cmd, const kal_uint32 address, const kal_uint32 address_bytes)
{
    kal_uint32 cmd1, cmd2;

    cmd2 = SFI_ReverseByteOrder(address);

    if (address_bytes== 3)   {
        cmd1= (cmd2 & 0xFFFFFF00) | cmd;
    }
    else {
        cmd1 = (cmd2 << 8) | cmd;
        cmd2 = cmd2 >> 24;
    }

    SFI_WriteReg32(RW_SFI_GPRAM_DATA, cmd1);
    SFI_WriteReg32(RW_SFI_GPRAM_DATA+4, cmd2);
    SFI_WriteReg32(RW_SFI_MAC_OUTL, address_bytes+1);
    SFI_WriteReg32(RW_SFI_MAC_INL , 0);

    SFI_MacEnable(CS);
    SFI_MacWaitReady(CS);
    return;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    GPRAM access: Write 1 byte command and 3 bytes address

  @param[in] cmd The command to be sent
  @param[in] address The address followed by the command.
*/
kal_uint32 SFI_GPRAM_Write_C1A3(const kal_uint32 cmd, const kal_uint32 address)
{
    return ((SFI_ReverseByteOrder(address) & 0xFFFFFF00) | (cmd&0xFF));
}

//-----------------------------------------------------------------------------
/*!
  @brief
    GPRAM access: Write 1 byte command, 4 bytes address, and 3 bytes of data

  @param[in] cmd The command to be sent
  @param[in] address The address followed by the command.
  @param[in] p_data The pointer-pointer to the data buffer.
  @param[in] length The pointer to the length of the data buffer.
  @remarks This function fills in the 2nd GPRAM register with
     LSB address, and 3 bytes (at most) of the data buffer. It also
     move the given pointer to next buffer address, and subtract the length of
     the data buffer for next GPRAM buffer copy.
*/
#if defined(__SFI_4BYTES_ADDRESS__)
kal_uint32 SFI_GPRAM_Write_C1A4(const kal_uint32 cmd, const kal_uint32 address, kal_uint8 **p_data, kal_uint32 *length)
{
    sf_uint    tmp;
    kal_uint32 cmd1, cmd2;
    kal_uint32 i;

    cmd2=SFI_ReverseByteOrder(address);
    cmd1=cmd2<<8 | (cmd&0xFF);
    cmd2=cmd2>>24;

    tmp.u8[0] = cmd2 & 0x000000FF;
    for (i=1;i<4;i++) {
        tmp.u8[i] = **p_data;
        (*p_data)++;
    }
    cmd2=tmp.u32;
    *length=(*length>3)?(*length-3):0;
    SFI_WriteReg32(RW_SFI_GPRAM_DATA+4, cmd2);
    return cmd1;
}
#endif

//-----------------------------------------------------------------------------
/*!
  @brief
    GPRAM access: Write data to GPRAM

  @param[in] gpram_offset The offset of the GPRAM in terms of byte, it must be
             multiple of four.
  @param[in] buff The pointer to the data buffer
  @param[in] length The length of the data buffer.
  @remarks The given gpram offset must be 4 bytes aligned, and the function will
           copy the data buffer to the GPRAM WORD/HALF-WORD/BYTE wise
           according to the starting address of the buffer.
*/
void SFI_GPRAM_Write(kal_uint32 gpram_offset, void* buff, kal_int32 length)
{
    kal_uint32 i;
    kal_uint8 *p_data=(kal_uint8*)buff;
    sf_uint tmp;

    gpram_offset+=RW_SFI_GPRAM_DATA;

    // source address is 4-byte aligned, and gpram_offset is 4-bytes aligned, too
    if (0 == ((kal_uint32)buff & 0x3))    {
        for (;length > 0; gpram_offset+=4, p_data+=4, length-=4)        {
            SFI_WriteReg32(gpram_offset, *(kal_uint32*)p_data);
        }
    }
    // source address is 2-byte aligned
    else if (0 == ((kal_uint32)p_data & 0x1))     {
        for (;length > 0; gpram_offset+=4, p_data+=4, length-=4)        {
            tmp.u16[0]=*(kal_uint16*)p_data;
            tmp.u16[1]=*((kal_uint16*)p_data + 1);
            SFI_WriteReg32(gpram_offset, tmp.u32); // save local_data to SFI GPRAM
        }
    }
    // source data is NOT 2-byte aligned
    else    {
        for (;length > 0; gpram_offset+=4, length-=4)  {
            for (i=0; i<4 && i<length; i++) {
                tmp.u8[i]=*p_data++;
            }
            SFI_WriteReg32(gpram_offset, tmp.u32); // save local_data to SFI GPRAM
        }
    }
}


//-----------------------------------------------------------------------------
/*!
  @brief
    Issue generic command to serial Flash, and read results.

  @param[in] cmd Pointer to the commands that to be sent
  @param[out] data Pointer to the data buffer that to be stored
  @param[in] outl Length of commands (in bytes)
  @param[in] intl Length of read data

  @remarks This function shall only be invoked in bootloader.
           Other callers must be aware of interrupts during the MAC mode
*/
void SFI_Dev_Command_Ext(const kal_uint16 CS,const kal_uint8 *cmd, kal_uint8 *data, const kal_uint16 outl, const kal_uint16 inl)
{
    kal_uint32      tmp;
    kal_uint32      i, j;
    kal_uint8       *p_data, *p_tmp;

    p_tmp=(kal_uint8*)(&tmp);

    for (i=0, p_data=((kal_uint8*)RW_SFI_GPRAM_DATA); i<outl; p_data+=4)   {
        for (j=0, tmp=0; i<outl && j<4; i++, j++) {
            p_tmp[j]=cmd[i];
        }
        SFI_WriteReg32(p_data, tmp);
    }
    SFI_WriteReg32(RW_SFI_MAC_OUTL, outl);
    SFI_WriteReg32(RW_SFI_MAC_INL, inl);
    SFI_MacEnable(CS);
    SFI_MacWaitReady(CS);

    for (i = 0, p_data = ((kal_uint8*)RW_SFI_GPRAM_DATA + outl); i < inl; ++i, ++data, ++p_data)    {
        *data = SFI_ReadReg8(p_data);
    }
    return;
}



//-----------------------------------------------------------------------------
/*!
  @brief
    Issue multiple generic commands to serial Flash

  @param[in] cmdlist Pointer to the list of the commands that to be sent to serial Flash.

  @remarks 1. This function is only called by bootloader.
              Other callers must be aware of interrupts during the MAC mode
           2. The Command List Format:
                cmd 1- {QPI/SPI, length in bytes, byte1, byte2, ... },
                cmd 2- {QPI/SPI, length in bytes, byte1, byte2, ... },
                ...
                end  - {SF_UNDEF}
              Example:
                {SPI, 1, 0x38}, {QPI, 2, 0xC0, 0x02}, {SF_UNDEF}
           3. If the first command is 0x05, the second byte will be the status polling bit mask.
              The function will wait till (status & mask) euqals zero.
              Example: {SPI, 1, 0x05, 0x01} - polling status register till bit0 becomes zero.

*/
void SFI_Dev_Command_List(const kal_uint16 CS, const kal_uint8 *cmdlist)
{
    kal_uint32 i=0;
    kal_uint32 val;

    if (cmdlist==NULL) return;

#if defined(__DUAL_SERIAL_FLASH_SUPPORT__)
    val= (CS==0x0)?SFI_DevMode:SFI_DevMode_CS1; // denotes the orignal mode
#else
    val=SFI_DevMode; // denotes the orignal mode
#endif

    while (1)   {
        switch (cmdlist[i]) { // TODO : compile option for MT6255/51/52 of Direct Read change mode
            case SPI: case SPIQ:
                    SFI_SetDevMode(CS,0); 
                break;   // Switch to SPI mode
            case QPI:
                    SFI_SetDevMode(CS,SFI_QPI_EN);
                break;   // Switch to QPI mode
            default:
                    SFI_SetDevMode(CS,val);
                return;  // Resume to orignal mode and returns
        }
        // When Read Status (05h) is encountered
        if (cmdlist[i+2]==SF_CMD_READ_SR) {
            kal_uint8 status;
            // The second byte is the bit mask, polling till zero.
            do {
                SFI_Dev_Command_Ext(CS, &cmdlist[i+2], &status, 1, 1);
            } while (status & cmdlist[i+3]);
        }
        // Commands other than 05h
        else {
            SFI_Dev_Command_Ext(CS, &cmdlist[i+2], NULL, cmdlist[i+1], 0);   // send command
        }

        i+=(cmdlist[i+1]+2);
    }
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Read 3 bytes ID (Vendor + Density + Device) in request mode (SPI/QPI)
  @param[out] id The pointer to the array that ID to be stored
  @remarks This function shall only be invoked in bootloader.
*/
void SFI_ReadDeviceID(const kal_uint16 CS,kal_uint8 *id, kal_uint8 cmd)
{
	//kal_uint8 cmd=SF_CMD_READ_ID;
	SFI_Dev_Command_Ext(CS, &cmd, id, 1, SF_FLASH_ID_LENGTH);
}


void SFI_ReadDeviceID_SPI(const kal_uint16 CS,kal_uint8 *id)
{
	SFI_ReadDeviceID(CS, id, SF_CMD_READ_ID);
}


//-----------------------------------------------------------------------------
/*!
  @brief
    Determine whether the device support frequency up hopping  (78Mhz > 80MHz) or not.
  @retval
    KAL_TRUE: the device doesn't support 80MHz.
    KAL_FALSE: the device supports FH to 80Mhz
  @remarks
    The caller is L1D_Init_MPLLFH()
*/
kal_bool SFI_Dev_SupportUpHopping(void)
{
    kal_uint8 id[SF_FLASH_ID_LENGTH];
    kal_uint8 i=0;
    for(;i<CS_COUNT;i++)
    {
        SFI_ReadDeviceID(i, id, SF_CMD_READ_ID_QPI);
	if (id[0]==0xFF || id[0]==0x00 || (CMEM_CheckValidDeviceID(id) == KAL_FALSE))    
	    {
		    SFI_ReadDeviceID(i, id, SF_CMD_READ_ID);
	    }
        // Note
        //  SF_DAL_TYPE_NUMONYX_W: Supports 80Mhz
        //  SF_DAL_TYPE_NUMONYX:   Supports 78Mhz
        if (id[0]==SF_DAL_TYPE_NUMONYX) return KAL_FALSE;
    }
    return KAL_TRUE;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Determine whether the device needs L1 Hard-Real-Time(HRT) timing recovery 
    software workaround.
  @retval
    KAL_TRUE: the device requires the HRT timing recovery software workaround
    KAL_FALSE: otherwise (default)  
*/
kal_bool SFI_Dev_IsModemTimingRecoveryRequired(void)
{
    kal_uint8 id[SF_FLASH_ID_LENGTH];
    kal_uint8 i=0;
    for(;i<CS_COUNT;i++)
    {
        SFI_ReadDeviceID_SPI(i, id);
        // Note
        // Winbond 3V series Serial Flash,
        // JEDEC ID: 0xEF, 0x40, *
        if ((id[0]==SF_DAL_TYPE_WINBOND)&&(id[1]==0x40)) return KAL_TRUE;
    }
    return KAL_FALSE;  
}

/*!
  @brief
    Determine whether the device needs L1 Delay Erase Resume Operation
    software workaround.
  @param[in] 
    flag = KAL_TRUE: Enable Delay Erase Resume 
    flag = KAL_FALSE: Disable Delay Erase Resume
*/

void SFI_Dev_SupportDelayResume(kal_bool flag)
{

	if (flag == KAL_TRUE)
		DelayResume = KAL_TRUE;
	else
		DelayResume = KAL_FALSE;
}

/*!
  @brief
    L1 query this function to get SF working frequency
    software workaround.
  @retval
    SFI_CLK_78/104/130MHZ: 78/104/130 working FQ
    SFI_CLK_UNKNOWN: working FQ unknown
*/
sfi_clock_enum SFI_Dev_WorkingFrequencyQuery(void)
{

#if defined(__SFI_CLK_78MHZ__)
    return SFI_CLK_78MHZ;
#elif defined(__SFI_CLK_104MHZ__)
    return SFI_CLK_104MHZ;
#elif defined(__SFI_CLK_130MHZ__)
    return SFI_CLK_130MHZ;
#elif defined(__SFI_CLK_166MHZ__)
    return SFI_CLK_166MHZ;
#else
    return SFI_CLK_UNKNOWN;
#endif

}

/*!
  @brief
    L1 query this function to get SF Voltage
    software workaround.
  @retval
    SFI_Voltage_18/ 30: 1.8V/ 3.0V Voltage
    SFI_Voltage_UNKNOWN: working Voltage unknown
*/
sfi_voltage_enum SFI_Dev_WorkingVoltageQuery(void)
{  
#if defined(MT6250)|| defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    /*Only query Internal SF's driving because it is equal to External SF's driving setting*/
    if( (SFI_ReadReg32(RW_SFI_MISC_CTL3)&0x00700000) <= 0x00200000) /* <= 6mA for 3.0V Serial Flash*/
        return SFI_Voltage_30;
    else  /*  >=8 mA for 1.8V Serial Flash*/
        return SFI_Voltage_18;
#else
    return SFI_Voltage_UNKNOWN;
#endif
}



#else  // !__SERIAL_FLASH__

#include "kal_general_types.h"
#include "kal_release.h"

kal_bool SFI_Dev_SupportUpHopping(void)
{
    return KAL_TRUE;
}

// Dummy function for non-serial Flash platform
kal_bool SFI_Dev_IsModemTimingRecoveryRequired(void)
{
    // The timing recovery workaround should be default disabled 
    return KAL_FALSE;
}

void SFI_Dev_SupporteraDelayResume(kal_bool flag)
{}

sfi_clock_enum SFI_Dev_WorkingFrequencyQuery(void)
{
    return SFI_CLK_UNKNOWN;
}

sfi_voltage_enum SFI_Dev_WorkingVoltageQuery(void)
{
    return SFI_Voltage_UNKNOWN;
}


#endif // __SERIAL_FLASH__

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined(__MTK_TARGET__)
#pragma arm section code
#endif



