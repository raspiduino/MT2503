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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * MT6626_rds.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      FM Radio RDS Driver (MT6626)
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#include "l1audio_def.h"
#include "MT6626.h"

#include "kal_non_specific_general_types.h"
#include "l1audio.h"

extern bool MT6626_ReadWord(uint8 CW, uint16 * data);
extern bool MT6626_WriteWord(uint8 CW, uint16 data);

#if (defined(MT6626)&&defined(__FM_RADIO_RDS_SUPPORT__))

static void Delayus(kal_uint32 data)
{
	kal_uint16 i;
	while(data--)
	{
		for(i=0;i<43;i++){}
	}
}

static void RDS_Recovery_Handler()
{
    kal_uint16 tempData=0;

    do
    {
        MT6626_ReadWord(RDS_DATA_REG, &tempData);
        MT6626_ReadWord(RDS_POINTER, &tempData);		
    }while(tempData & 0x3);
}

void FMDrv_RDS_GetData(uint16 *data)
{
	kal_uint16 CRC=0, i=0, RDS_adj=0, RDSDataCount=0, RDSCorrCnt=0;
	kal_uint16 temp=0, OutputPoint =0;

	MT6626_ReadWord(RDS_FIFO_STATUS0, &temp);
	RDSDataCount = ((RDS_GROUP_DIFF_OFS & temp) << 2);
		
	if((temp & RDS_FIFO_DIFF)>=4)
    {
        //block A data and info handling
        MT6626_ReadWord(RDS_INFO_REG, &temp);
		RDS_adj |= (temp & RDS_CRC_BLK_ADJ) << 10;
        CRC |= (temp & RDS_CRC_INFO)<<3;
		RDSCorrCnt |= ((temp & RDS_CRC_CORR_CNT)<<11);
        MT6626_ReadWord(RDS_DATA_REG, &data[0]);
        
        //block B data and info handling
        MT6626_ReadWord(RDS_INFO_REG, &temp);
		RDS_adj |= (temp & RDS_CRC_BLK_ADJ) << 9;
        CRC |= (temp & RDS_CRC_INFO)<<2;
		RDSCorrCnt |= ((temp & RDS_CRC_CORR_CNT)<<7);
        MT6626_ReadWord(RDS_DATA_REG, &data[1]);
        
        //block C data and info handling
        MT6626_ReadWord(RDS_INFO_REG, &temp);
		RDS_adj |= (temp & RDS_CRC_BLK_ADJ) << 8;
        CRC |= (temp & RDS_CRC_INFO)<<1;
		RDSCorrCnt |= ((temp & RDS_CRC_CORR_CNT)<<3);
        MT6626_ReadWord(RDS_DATA_REG, &data[2]);
        
        //block D data and info handling
        MT6626_ReadWord(RDS_INFO_REG, &temp);
		RDS_adj |= (temp & RDS_CRC_BLK_ADJ) << 7;
        CRC |= (temp & RDS_CRC_INFO);
		RDSCorrCnt |= ((temp & RDS_CRC_CORR_CNT)>>1);
        MT6626_ReadWord(RDS_DATA_REG, &data[3]);
        
        data[4] = (CRC | RDS_adj | RDSDataCount);
		data[5] = RDSCorrCnt;

        MT6626_ReadWord(RDS_PWDI, &data[6]);
        MT6626_ReadWord(RDS_PWDQ, &data[7]);

        MT6626_ReadWord(RDS_POINTER, &OutputPoint);
        //Go into RDS recovery handler while RDS output point doesn't align to 4 in numeric        
		if(OutputPoint & 0x3)
		{
            RDS_Recovery_Handler();
		}
		
    } 
    else
    {
        for(;i<8;i++)
			data[i] = 0;
    }

}

void FMDrv_RDS_Enable(void)
{
	uint16 dataRead;
	
	//kal_char debug_buff[50];
	//sprintf(debug_buff, "FMDrv_RDS_Enable");
	//kal_print((kal_char*)debug_buff);

	MT6626_ReadWord(RDS_CFG0, &dataRead);
	MT6626_WriteWord(RDS_CFG0, 6); //set buf_start_th

	MT6626_ReadWord(FM_MAIN_CTRL, &dataRead);
	MT6626_WriteWord(FM_MAIN_CTRL, dataRead|(RDS_MASK));

}

void FMDrv_RDS_Disable(void)
{
	uint16 dataRead;

	//kal_char debug_buff[50];
	//sprintf(debug_buff, "FMDrv_RDS_Disable");
	//kal_print((kal_char*)debug_buff);

	MT6626_ReadWord(FM_MAIN_CTRL, &dataRead);
	MT6626_WriteWord(FM_MAIN_CTRL, (dataRead & 0xFFEF));
}

kal_bool FMDrv_RDS_RegChk(void)
{
	return KAL_TRUE;
}

void FMDrv_RDS_Reset(void)
{
	uint16 dataRead;
	MT6626_ReadWord(FM_MAIN_CTRL, &dataRead);
	MT6626_WriteWord(FM_MAIN_CTRL, dataRead&(0xFFEF));
	Delayus(85);
	MT6626_ReadWord(FM_MAIN_CTRL, &dataRead);
	MT6626_WriteWord(FM_MAIN_CTRL, dataRead|(0x10));
}

void FMDrv_RDS_INTR_OnOff(kal_bool isOn)
{
	uint16 dataRead;
	
	//kal_char debug_buff[50];
	//sprintf(debug_buff, "FMDrv_RDS_INTR_OnOff [%x]", isOn);
	//kal_print((kal_char*)debug_buff);

	if(isOn)
	{
		MT6626_ReadWord(FM_MAIN_EXTINTRMASK, &dataRead);
		MT6626_WriteWord(FM_MAIN_EXTINTRMASK, dataRead|EXT_RDS_MASK);
	}
	else
	{
		MT6626_WriteWord(FM_MAIN_EXTINTRMASK, 0);
	}
}

void FMDrv_RDS_Reset_BKCnt(void)
{
	uint16 dataRead;
	MT6626_ReadWord(RDS_CFG0, &dataRead);
    MT6626_WriteWord(RDS_CFG0, dataRead |0x0100);
}

uint16 FMDrv_RDS_Read_BKCnt(kal_bool Val)
{
	uint16 dataRead;

	if(Val)
		MT6626_ReadWord(RDS_GOODBK_CNT, &dataRead);
	else
		MT6626_ReadWord(RDS_BADBK_CNT, &dataRead);
	
	return dataRead;
}

#endif // defined(MT6626&&FM_RADIO_RDS_SUPPORT)
