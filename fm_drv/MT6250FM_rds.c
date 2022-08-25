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
 * MT6250FM_rds.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      FM Radio RDS Driver (MT6250)
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/
#if ((defined(MT6250FM) || defined(MT6260FM) || defined(MT6261FM))&&defined(__FM_RADIO_RDS_SUPPORT__))
#include "kal_general_types.h"
//#include "l1audio_def.h"
#include "MT6250FM.h"
//#include "kal_non_specific_general_types.h"
//#include "l1audio.h"

static void RDS_Recovery_Handler()
{
    kal_uint16 tempData=0;

    do
    {
        MT6250FM_ReadWord(FM_RDS_RDATA, &tempData);
        MT6250FM_ReadWord(FM_RDS_FIFO_STATE1, &tempData);		
    }while(tempData & 0x3);
}

void FMDrv_RDS_GetData(kal_uint16 *data)
{
	kal_uint16 CRC=0, i=0, RDS_adj=0, RDSDataCount=0, RDSCorrCnt=0;
	kal_uint16 temp=0, OutputPoint =0;

	MT6250FM_ReadWord(FM_RDS_FIFO_STATUS0, &temp);
	RDSDataCount = ((RDS_GROUP_FIFO_DIFF&temp)<<2);//group number
		
	if((temp&RDS_BLOCK_FIFO_DIFF)>=4)
    {
        //block A data and info handling
        MT6250FM_ReadWord(FM_RDS_INFO_RDATA, &temp);
		RDS_adj |= (temp & RDS_CRC_BLK_ADJ) << 10;
        CRC |= (temp & RDS_CRC_INFO)<<3;
		RDSCorrCnt |= ((temp & RDS_CRC_CORR_CNT)<<11);
        MT6250FM_ReadWord(FM_RDS_RDATA, &data[0]);
        
        //block B data and info handling
        MT6250FM_ReadWord(FM_RDS_INFO_RDATA, &temp);
		RDS_adj |= (temp & RDS_CRC_BLK_ADJ) << 9;
        CRC |= (temp & RDS_CRC_INFO)<<2;
		RDSCorrCnt |= ((temp & RDS_CRC_CORR_CNT)<<7);
        MT6250FM_ReadWord(FM_RDS_RDATA, &data[1]);
        
        //block C data and info handling
        MT6250FM_ReadWord(FM_RDS_INFO_RDATA, &temp);
		RDS_adj |= (temp & RDS_CRC_BLK_ADJ) << 8;
        CRC |= (temp & RDS_CRC_INFO)<<1;
		RDSCorrCnt |= ((temp & RDS_CRC_CORR_CNT)<<3);
        MT6250FM_ReadWord(FM_RDS_RDATA, &data[2]);
        
        //block D data and info handling
        MT6250FM_ReadWord(FM_RDS_INFO_RDATA, &temp);
		RDS_adj |= (temp & RDS_CRC_BLK_ADJ) << 7;
        CRC |= (temp & RDS_CRC_INFO);
		RDSCorrCnt |= ((temp & RDS_CRC_CORR_CNT)>>1);
        MT6250FM_ReadWord(FM_RDS_RDATA, &data[3]);
        
        data[4] = (CRC | RDS_adj | RDSDataCount);
		data[5] = RDSCorrCnt;

        MT6250FM_ReadWord(FM_RDS_PWDI, &data[6]);
        MT6250FM_ReadWord(FM_RDS_PWDQ, &data[7]);

        MT6250FM_ReadWord(FM_RDS_FIFO_STATE1, &OutputPoint);
        //Go into RDS recovery handler while RDS output point doesn't align to 4 in numeric        
		if(OutputPoint & 0x3)
		{
            RDS_Recovery_Handler();
		}
		
    } 
    else
    {
        for(i=0;i<8;i++)
			*(data+i) = 0;
    }

}

void FMDrv_RDS_Enable(void)
{
	kal_uint16 dataRead;
	
	MT6250FM_ReadWord(FM_RDS_CFG0, &dataRead);
	MT6250FM_WriteWord(FM_RDS_CFG0, dataRead&(~RDS_START_TH)|0x0006); //set buf_start_th

	MT6250FM_ReadWord(FM_MAIN_CTRL, &dataRead);
	MT6250FM_WriteWord(FM_MAIN_CTRL, dataRead|RDS_MASK);

}

void FMDrv_RDS_Disable(void)
{
	kal_uint16 dataRead;

	MT6250FM_ReadWord(FM_MAIN_CTRL, &dataRead);
	MT6250FM_WriteWord(FM_MAIN_CTRL, (dataRead&(~RDS_MASK)));
}

kal_bool FMDrv_RDS_RegChk(void)
{
	return KAL_TRUE;
}

void FMDrv_RDS_Reset(void)
{
	FMDrv_RDS_Disable();
	Delayus(85);
	FMDrv_RDS_Enable();
}

void FMDrv_RDS_INTR_OnOff(kal_bool isOn)
{
	kal_uint16 dataRead;

	MT6250FM_ReadWord(FM_INTE_MASK, &dataRead);
	if(isOn)
	{
		MT6250FM_WriteWord(FM_INTE_MASK, dataRead|FM_RDS_MASK);
	}
	else
	{
		MT6250FM_WriteWord(FM_INTE_MASK, dataRead&(~FM_RDS_MASK));
	}
}

void FMDrv_RDS_Reset_BKCnt(void)
{
	kal_uint16 dataRead;
	MT6250FM_ReadWord(FM_RDS_CFG0, &dataRead);
    MT6250FM_WriteWord(FM_RDS_CFG0, dataRead |RDS_BLOCK_CNT_RESET);
}
/*val:1.good block count,0.bad block count
*/
kal_uint16 FMDrv_RDS_Read_BKCnt(kal_bool Val)
{
	kal_uint16 dataRead;

	if(Val)
		MT6250FM_ReadWord(FM_RDS_GOODBK_CNT, &dataRead);
	else
		MT6250FM_ReadWord(FM_RDS_BADBK_CNT, &dataRead);
	
	return dataRead;
}

#endif // defined(MT6250FM&&FM_RADIO_RDS_SUPPORT)
