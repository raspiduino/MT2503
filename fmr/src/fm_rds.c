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
 * FM_RDS.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      FM Radio RDS Driver
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/
#if defined(__FM_RADIO_RDS_SUPPORT__)
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "fm_rds.h"
#include "fm_radio.h"
#include "fmr_trc.h"
#include "string.h"

#if (!defined(MT6616)&&defined(FMR_NEW_CHIP))
#define RDS_PS_CBC_SUPPORT
#endif
#if (!defined(FMR_DSP_CHIP)&&defined(FMR_NEW_CHIP))
#define RDS_FIFO_FULL_DETECT
#endif
#if (defined(FMR_DSP_CHIP))
#define RDS_RT_CBC_SUPPORT
#endif
extern RDS_CallBack pstRDS_Hdlr;
extern kal_int16 _current_frequency;
#if defined(FMR_DSP_CHIP)
#define   RDS_DCO_FIFO_OFST		(0x01F0)
#else
#define   RDS_DCO_FIFO_OFST		(0x01E0)
#endif

kal_uint16 _BLER_CHK_INTERVAL=5000;/*set default value 5s*/
kal_bool isRdsOn = KAL_FALSE;
static kal_uint8 PreTextABFlag;
kal_uint16 RDS_Sync_Cnt, RDS_Block_Reset_Cnt;
RDSData_Struct *pstRDSData;
kal_bool g_AF_Enable = KAL_TRUE;
kal_bool g_TP_Enable = KAL_TRUE;
#if (defined(MT6616) && defined(FM_INTERFACE_HCI))
extern FMR_data *pstFMR_data;
extern void FMDrv_HCI_Send_Cmd(kal_uint8 Opcode, kal_uint8 *data);
#endif
#if !defined(FMR_DSP_CHIP)
static kal_uint8 RDS_FirstIn = 1;
void FMDrv_RDS_BlockReset(void);
void RDS_BlerCheck(void);
kal_uint16 RDS_Get_Block_Value(kal_uint16 *block, kal_uint8 offset);
#endif

/**********************************************************************
*  RDS Support
**********************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
#endif
#if 0
/* under construction !*/
#endif
#if 1
/* under construction !*/
#endif
/* under construction !*/
#endif
/**********************************************************************
*  RDS Reset
**********************************************************************/
void RDS_Reset(void)
{
	FMDrv_RDS_Reset();
}
#ifndef FMR_DSP_CHIP
/**********************************************************************
*  RDS Block Reset
**********************************************************************/
void RDS_Block_Reset(void)
{
	FMDrv_RDS_BlockReset();
}
#endif
/**********************************************************************
*  RDS INTR Enable
**********************************************************************/
void RDS_INTR_Enable(void)
{
	FMDrv_RDS_INTR_OnOff(KAL_TRUE);
}
/**********************************************************************
*  RDS INTR Disable
**********************************************************************/
void RDS_INTR_Disable(void)
{
	FMDrv_RDS_INTR_OnOff(KAL_FALSE);
}
/**********************************************************************
*  RDS Enable
**********************************************************************/
void RDS_Enable(void)
{
#if (defined(FM_INTERFACE_HCI) && defined(MT6616))
       kal_uint8 buffer[3]={1, 0, 0};
       kal_uint16 tmp;
       kal_bool status;
	   
	if(isRdsOn)
		return;
       FMDrv_HCI_Send_Cmd(RDS_ENABLE_OPCODE, buffer);
#else
	if(isRdsOn)
		return;
	FMDrv_RDS_Enable();
#endif
    isRdsOn = KAL_TRUE;
	pstRDSData = (RDSData_Struct*)get_ctrl_buffer( sizeof(RDSData_Struct) );
	RDS_Init_Data();		
}
/**********************************************************************
*  RDS Disable
**********************************************************************/
void RDS_Disable(void)
{
#if (defined(FM_INTERFACE_HCI) && defined(MT6616))
  kal_uint8 buffer[3]={0, 0, 0};
  kal_uint16 tmp;
  kal_bool status;

	if(!isRdsOn)
		return;
  FMDrv_HCI_Send_Cmd(RDS_ENABLE_OPCODE, buffer);
#else
	if(!isRdsOn)
		return;
	FMDrv_RDS_Disable();
#endif
	free_ctrl_buffer(pstRDSData);
	isRdsOn = KAL_FALSE;
	pstRDSData = (RDSData_Struct *)0;
}
/**********************************************************************
*  RDS Check Event
**********************************************************************/
void RDS_EventGet(void)
{
	RdsEvent event;
	kal_uint8 cnt,cnt1;
	kal_uint16 event_mask, flag_mask;

	if((!isRdsOn) || (pstRDSData->event_status == 0))
       	return;
  kal_trace(TRACE_INFO, FM_INFO_FM_RDS_EVENT, pstRDSData->event_status, pstRDSData->RDSFlag.flag_status);
	for(cnt = 0; cnt<16; cnt++)
	{
		event_mask = 1<<cnt;
		if(pstRDSData->event_status&event_mask)
		{
			event = (RdsEvent)(pstRDSData->event_status&event_mask);			
			if(event == RDS_EVENT_FLAGS) //One of the RDS flag has changed state
			{
				for(cnt1 = 0; cnt1<16; cnt1++)
				{
					flag_mask =1<<cnt1;
					if(pstRDSData->RDSFlag.flag_status&flag_mask)
					{
						pstRDS_Hdlr(event);	
					}
				}
			}
			else
			{
				pstRDS_Hdlr(event);
			}
			pstRDSData->event_status &= ~event_mask;
		}
	}
	//kal_sleep_task(10);
	//FMR_RDS_INTR_OnOff(1);		
       return;
}
/**********************************************************************
*  RDS Read Block Counter
*  val = 1, Good Block Counter
*  val = 0, Bad Block Counter
**********************************************************************/
kal_uint16 RDS_Read_Block_Counter(kal_bool Val)
{	
	kal_uint16 BlockCnt;
	BlockCnt = FMDrv_RDS_Read_BKCnt(Val);
	kal_trace(TRACE_INFO,FM_INFO_FM_RDS_BLOCK_CNT,Val,BlockCnt);
	
	return BlockCnt;
}

/**********************************************************************
*  RDS Reset Block Counter
**********************************************************************/
void RDS_Reset_Block_Counter(void)
{
	FMDrv_RDS_Reset_BKCnt();
}
#ifndef FMR_DSP_CHIP
/**********************************************************************
*  RDS Get Block Value
**********************************************************************/
 kal_uint16 RDS_Get_Block_Value(kal_uint16 *block, kal_uint8 offset)
{
	FMDrv_RDS_Get_BKValue(block, offset);
	return KAL_TRUE;
}
#endif

/**********************************************************************
*  RDS_Eint_Handler
**********************************************************************/
#define GroupNum 32
#define GroupItem 64

void RDS_RetrieveGroup0(kal_uint16 *block_data, kal_uint8 SubType)
{
	kal_uint8 indx, indx2,  PS_Num, AF_H, AF_L, num;
#if FMR_RDS_FULL_SUPPORT
	kal_bool DI_Flag;
	kal_uint8 DI_Code;
#endif
#ifdef RDS_PS_CBC_SUPPORT
	kal_uint8 corrBitCnt_BlkB, corrBitCnt_BlkD;
	static kal_int8 Pre_PS_Num = -1;
	corrBitCnt_BlkB = (block_data[5] & 0x0F00)>>8;
	corrBitCnt_BlkD = block_data[5] & 0xF;
#endif
	if(!(block_data[4]&RDS_GDBK_IND_D))
	{
    	  return;
	}
#ifdef RDS_PS_CBC_SUPPORT
	if(corrBitCnt_BlkB == 0)
#endif
	{
		if(pstRDSData->RDSFlag.TA != ((block_data[1]&0x0010)>>4))
		{
			pstRDSData->RDSFlag.TA = (kal_bool)((block_data[1]&0x0010)>>4);		   	
			pstRDSData->event_status |= RDS_EVENT_FLAGS;
			pstRDSData->RDSFlag.flag_status |= RDS_FLAG_IS_TA;	
		}
#if FMR_RDS_FULL_SUPPORT		
		if(pstRDSData->RDSFlag.Music!= ((block_data[1]&0x0008)>>3))
		{
			pstRDSData->RDSFlag.Music= (kal_bool)((block_data[1]&0x0008)>>3);
			pstRDSData->event_status |= RDS_EVENT_FLAGS;
			pstRDSData->RDSFlag.flag_status |= RDS_FLAG_IS_MUSIC;			
		}
#endif		
	}
	if((pstRDSData->Switch_TP)&&(pstRDSData->RDSFlag.TP[1])&&!(pstRDSData->RDSFlag.TA))
	{
		pstRDSData->event_status |= RDS_EVENT_TAON_OFF;
	}
	if(!SubType && g_AF_Enable) //Type A
	{
		if(block_data[4]&RDS_GDBK_IND_C)
		{
			AF_H = (block_data[2]&0xFF00)>>8;
			AF_L= block_data[2]&0x00FF;
			if((AF_H > 224)&&(AF_H < 250)) //Followed AF Number
			{
				pstRDSData->AF_Data.AF[0][0]= AF_H - 224; //AF Number
				if((pstRDSData->AF_Data.AF[1][0]) != (pstRDSData->AF_Data.AF[0][0]))
				{
					pstRDSData->AF_Data.AF[1][0] = pstRDSData->AF_Data.AF[0][0];
					pstRDSData->AF_Data.isAFNum_Get= KAL_FALSE;
				}
				else
					pstRDSData->AF_Data.isAFNum_Get= KAL_TRUE;
				if((AF_L < 205))
				{
					pstRDSData->AF_Data.AF[0][1] = AF_L;
					if((pstRDSData->AF_Data.AF[0][1]) != (pstRDSData->AF_Data.AF[1][1]))
					{
						pstRDSData->AF_Data.AF[1][1] = pstRDSData->AF_Data.AF[0][1];
					}
					else
					{
						if((pstRDSData->AF_Data.AF[1][1])  !=  (_current_frequency-875))
							pstRDSData->AF_Data.isMethod_A = KAL_TRUE;
						else
							pstRDSData->AF_Data.isMethod_A = KAL_FALSE;
					}
				}
				if(pstRDSData->AF_Data.isAFNum_Get)
				{
					if((pstRDSData->AF_Data.AF[1][0] == 1)&&(pstRDSData->AF_Data.AF[1][1] != 0))
					{
	                    if((pstRDSData->AF_Data.Addr_Cnt) != 0xFF)
	                    {
						    pstRDSData->AF_Data.Addr_Cnt = 0xFF;
	    					pstRDSData->event_status |= RDS_EVENT_AF_LIST;
	                    }
					}
				}
			}				
			else if((pstRDSData->AF_Data.isAFNum_Get)&&((pstRDSData->AF_Data.Addr_Cnt) != 0xFF)) //AF Num correct
			{
				num = pstRDSData->AF_Data.AF[1][0];
				num = num>>1;
				//Put AF freq into buffer and check if AF freq is repeat again
			    for(indx=1; indx < num+1; indx++)
		       	{
		       		if((AF_H == (pstRDSData->AF_Data.AF[0][2*indx]))&&(AF_L == (pstRDSData->AF_Data.AF[0][2*indx+1])))
					{
						break;
		            }
					else if(!(pstRDSData->AF_Data.AF[0][2*indx])) //null buffer
		            {
						pstRDSData->AF_Data.AF[0][2*indx] = AF_H;
						pstRDSData->AF_Data.AF[0][2*indx+1] = AF_L;
						break;
					}
		       	}
				num = pstRDSData->AF_Data.AF[1][0];
			    if(num > 0)
    			{
    				if((pstRDSData->AF_Data.AF[0][num]) != 0)
				    {
						num = num>> 1;
						//arrange frequency from low to high:start
						for(indx=1;indx<num;indx++)
						{
							for(indx2=indx+1;indx2<num+1;indx2++)
							{
								AF_H = pstRDSData->AF_Data.AF[0][2*indx];
								AF_L = pstRDSData->AF_Data.AF[0][2*indx+1];
								if(AF_H > (pstRDSData->AF_Data.AF[0][2*indx2]))
								{
									pstRDSData->AF_Data.AF[0][2*indx] = pstRDSData->AF_Data.AF[0][2*indx2];
									pstRDSData->AF_Data.AF[0][2*indx+1] = pstRDSData->AF_Data.AF[0][2*indx2+1];
									pstRDSData->AF_Data.AF[0][2*indx2] = AF_H;
									pstRDSData->AF_Data.AF[0][2*indx2+1] = AF_L;
								}
								else if(AF_H == (pstRDSData->AF_Data.AF[0][2*indx2]))
								{
									if(AF_L > (pstRDSData->AF_Data.AF[0][2*indx2+1]))
									{
										pstRDSData->AF_Data.AF[0][2*indx] = pstRDSData->AF_Data.AF[0][2*indx2];
										pstRDSData->AF_Data.AF[0][2*indx+1] = pstRDSData->AF_Data.AF[0][2*indx2+1];
										pstRDSData->AF_Data.AF[0][2*indx2] = AF_H;
										pstRDSData->AF_Data.AF[0][2*indx2+1] = AF_L;
									}
								}
							}
						}
						//arrange frequency from low to high:end
						//compare AF buff0 and buff1 data:start
						num = pstRDSData->AF_Data.AF[1][0];
						indx2 = 0;
						for(indx=1;indx<num+1;indx++)
		                {
							if((pstRDSData->AF_Data.AF[1][indx]) == (pstRDSData->AF_Data.AF[0][indx]))
			                {
							    if(pstRDSData->AF_Data.AF[1][indx] != 0)
									indx2 ++;
						    }
						    else
							    pstRDSData->AF_Data.AF[1][indx] = pstRDSData->AF_Data.AF[0][indx];
					    }
						//compare AF buff0 and buff1 data:end
						if(indx2 == num)
					    {
							kal_trace(TRACE_INFO, FM_INFO_FM_RDS_AF_BUFF_FULL, 2,
        					    pstRDSData->AF_Data.AF[1][0], pstRDSData->AF_Data.AF[1][1], 
        					    pstRDSData->AF_Data.AF[1][2], pstRDSData->AF_Data.AF[1][3],
        					    pstRDSData->AF_Data.AF[1][4], pstRDSData->AF_Data.AF[1][5],
        					    pstRDSData->AF_Data.AF[1][6], pstRDSData->AF_Data.AF[1][7]);	
    						pstRDSData->AF_Data.Addr_Cnt = 0xFF;
    						pstRDSData->event_status |= RDS_EVENT_AF_LIST;
    						for(indx=0;indx<num;indx++)
    						{
    							if((pstRDSData->AF_Data.AF[1][indx]) == 0)
    							{
    								pstRDSData->AF_Data.Addr_Cnt = 0x0F;
    								pstRDSData->event_status &= (~RDS_EVENT_AF_LIST);
    							}
    						}
					    }
    					else
    						pstRDSData->AF_Data.Addr_Cnt = 0x0F;
					}
				}
			}			
		}
	}
	else
	{
		pstRDSData->AF_Data.Addr_Cnt = 0;
	}
			   	
#if FMR_RDS_FULL_SUPPORT		
	/*DI_Code[1:0]:   "00" = d3 *
	  *                        "01" = d2 *
	  *                        "10" = d1 *
	  *                        "11" = d0 */
			   	
	DI_Code = block_data[1]&0x0003;
	DI_Flag = (kal_bool)((block_data[1]&0x0004)>>2);
				  
	switch(DI_Code)
	{
	   case 3:
  		if(pstRDSData->RDSFlag.Stereo != DI_Flag)
  		{
	   		pstRDSData->RDSFlag.Stereo = DI_Flag;
			pstRDSData->event_status |= RDS_EVENT_FLAGS;
			pstRDSData->RDSFlag.flag_status |= RDS_FLAG_IS_STEREO;
		}
	   	break;
          case 2:
  		if(pstRDSData->RDSFlag.Artificial_Head != DI_Flag)
		{
	   		pstRDSData->RDSFlag.Artificial_Head = DI_Flag;
			pstRDSData->event_status |= RDS_EVENT_FLAGS;
			pstRDSData->RDSFlag.flag_status |= RDS_FLAG_IS_ARTIFICIAL_HEAD;
  		}
	   	break;
          case 1:
  		if(pstRDSData->RDSFlag.Compressed != DI_Flag)
  		{
	   		pstRDSData->RDSFlag.Compressed = DI_Flag;
			pstRDSData->event_status |= RDS_EVENT_FLAGS;
			pstRDSData->RDSFlag.flag_status |= RDS_FLAG_IS_COMPRESSED;	
		}
	      	break;
          case 0:
  		if(pstRDSData->RDSFlag.Dynamic_PTY != DI_Flag)
		{
	   		pstRDSData->RDSFlag.Dynamic_PTY = DI_Flag;
			pstRDSData->event_status |= RDS_EVENT_FLAGS;
			pstRDSData->RDSFlag.flag_status |= RDS_FLAG_IS_DYNAMIC_PTY;	
  		}
		break;		
          default:
	      	break;			 
	}
#endif	
	PS_Num = block_data[1]&0x0003;
    kal_trace(TRACE_INFO, FM_INFO_FM_RDS_PS_DATA, PS_Num, block_data[3]);
	/*Get PS Code Table*/
#if 0/*newly spec phase out code table*/	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
	AF_H = pstRDSData->PS_Data.PS[0][2*PS_Num];
	AF_L = pstRDSData->PS_Data.PS[0][2*PS_Num+1];
	if((AF_H == (block_data[3])>>8)&&(AF_L == (block_data[3]&0xFF)))
	{
#ifndef RDS_PS_CBC_SUPPORT
		if((!((pstRDSData->event_status)&RDS_EVENT_PROGRAMNAME))&&((PS_Num == 0)||(pstRDSData->PS_Data.Addr_Cnt)))
#endif
		{			
			pstRDSData->PS_Data.PS[1][2*PS_Num]=(block_data[3])>>8;
			pstRDSData->PS_Data.PS[1][2*PS_Num+1] = (block_data[3])&0xFF;
#ifndef RDS_PS_CBC_SUPPORT
			if((PS_Num == 0)&&(pstRDSData->PS_Data.Addr_Cnt == 0))
			{
				for(indx=2;indx<8;indx++)
				{
					pstRDSData->PS_Data.PS[0][indx] = 0x00;
				}
			}
#endif				
			pstRDSData->PS_Data.Addr_Cnt |= 1<<PS_Num;
			if(pstRDSData->PS_Data.Addr_Cnt == 0x0F)
			{
#ifndef RDS_PS_CBC_SUPPORT
				//Avoid PS transient:Start 
				num = 0;	
				for(indx=0;indx<8;indx++)
				{
					if(pstRDSData->PS_Data.PS[0][indx] == pstRDSData->PS_Data.PS[1][indx])
						num++;
				}
				pstRDSData->PS_Data.Addr_Cnt = 0;
				//Avoid PS transient:END 
				if(num == 8)
#endif
				{
					num = 0;
					for(indx=0;indx<8;indx++)
					{
						if(pstRDSData->PS_Data.PS[1][indx] == pstRDSData->PS_Data.PS[2][indx])
						num++;
					}
					if(num != 8)
				    {
						pstRDSData->event_status |= RDS_EVENT_PROGRAMNAME;			
						pstRDSData->PS_Data.Addr_Cnt = 0;
				    }
					for(indx=0;indx<8;indx++)
					{
						pstRDSData->PS_Data.PS[2][indx] = pstRDSData->PS_Data.PS[1][indx];
#ifndef RDS_PS_CBC_SUPPORT
						pstRDSData->PS_Data.PS[1][indx] = 0x20;
						pstRDSData->PS_Data.PS[0][indx] = 0x00;
#endif
					}
				}
#ifndef RDS_PS_CBC_SUPPORT
				else
				{
	                 pstRDSData->PS_Data.PS[0][0] = 0x00;
	                 pstRDSData->PS_Data.PS[0][1] = 0x00;
				}
#endif
			}
		}
	}
	else
	{
#ifdef RDS_PS_CBC_SUPPORT
		if (PS_Num-Pre_PS_Num > 1) 
		{
			for (indx=Pre_PS_Num+1; indx<PS_Num; indx++) 
			{
				pstRDSData->PS_Data.Addr_Cnt &= ~(1<<indx);
				pstRDSData->PS_Data.PS[0][2*indx] = 0x00;
				pstRDSData->PS_Data.PS[0][2*indx+1] = 0x00;
				pstRDSData->PS_Data.PS[1][2*indx] = 0x00;
				pstRDSData->PS_Data.PS[1][2*indx+1] = 0x00;
			}
		}
		else if (PS_Num-Pre_PS_Num < 1) 
		{
			for (indx=0; indx<PS_Num; indx++) 
			{
				pstRDSData->PS_Data.Addr_Cnt &= ~(1<<indx);
				pstRDSData->PS_Data.PS[0][2*indx] = 0x00;
				pstRDSData->PS_Data.PS[0][2*indx+1] = 0x00;
				pstRDSData->PS_Data.PS[1][2*indx] = 0x00;
				pstRDSData->PS_Data.PS[1][2*indx+1] = 0x00;
			}
		}
		
		if ((pstRDSData->PS_Data.PS[0][2*PS_Num] != 0) || (pstRDSData->PS_Data.PS[0][2*PS_Num+1] != 0)) 
		{
			for (indx=PS_Num; indx<4; indx++) 
			{
				pstRDSData->PS_Data.Addr_Cnt &= ~(1<<indx);
			}
		}
		if((corrBitCnt_BlkB == 0) && (corrBitCnt_BlkD == 0)) 
        {
        	if(pstRDSData->PS_Data.Addr_Cnt&(1<<PS_Num))
				pstRDSData->PS_Data.Addr_Cnt &= ~(1<<PS_Num);
			else
				pstRDSData->PS_Data.Addr_Cnt |= 1<<PS_Num;	
			pstRDSData->PS_Data.PS[0][2*PS_Num]=(block_data[3])>>8;
			pstRDSData->PS_Data.PS[0][2*PS_Num+1] = (block_data[3])&0xFF;
			pstRDSData->PS_Data.PS[1][2*PS_Num]=(block_data[3])>>8;
			pstRDSData->PS_Data.PS[1][2*PS_Num+1] = (block_data[3])&0xFF;
		
			if(pstRDSData->PS_Data.Addr_Cnt == 0x0F) 
			{
				num = 0;
				for(indx = 0; indx < 8; indx++)
				{
					if(pstRDSData->PS_Data.PS[1][indx] == pstRDSData->PS_Data.PS[2][indx]) 
					{
						num++;
					}
				}
				if(num != 8) 
				{
					pstRDSData->event_status |= RDS_EVENT_PROGRAMNAME;
					pstRDSData->PS_Data.Addr_Cnt = 0;
				}
						
				for(indx = 0; indx < 8; indx++)
				{
					pstRDSData->PS_Data.PS[2][indx] = pstRDSData->PS_Data.PS[1][indx];
				}					
			}
		} 
		else 
#endif			
		{
#ifndef RDS_PS_CBC_SUPPORT
            if(PS_Num == 0)
            {
                pstRDSData->PS_Data.Addr_Cnt = 0;
            }
#endif		
		    pstRDSData->PS_Data.PS[0][2*PS_Num]=(block_data[3])>>8;
		    pstRDSData->PS_Data.PS[0][2*PS_Num+1] = (block_data[3])&0xFF;
		}
	}
	kal_trace(TRACE_INFO, FM_INFO_FM_RDS_PS_STATUS, pstRDSData->event_status, PS_Num, pstRDSData->PS_Data.Addr_Cnt);
	kal_trace(TRACE_INFO,FM_INFO_FM_RDS_PS1_STATUS,
			pstRDSData->PS_Data.PS[0][0], pstRDSData->PS_Data.PS[0][1], pstRDSData->PS_Data.PS[0][2], pstRDSData->PS_Data.PS[0][3], 
			pstRDSData->PS_Data.PS[0][4], pstRDSData->PS_Data.PS[0][5], pstRDSData->PS_Data.PS[0][6], pstRDSData->PS_Data.PS[0][7]);
	kal_trace(TRACE_INFO,FM_INFO_FM_RDS_PS2_STATUS,
			pstRDSData->PS_Data.PS[1][0], pstRDSData->PS_Data.PS[1][1], pstRDSData->PS_Data.PS[1][2], pstRDSData->PS_Data.PS[1][3], 
			pstRDSData->PS_Data.PS[1][4], pstRDSData->PS_Data.PS[1][5], pstRDSData->PS_Data.PS[1][6], pstRDSData->PS_Data.PS[1][7]);
#ifdef RDS_PS_CBC_SUPPORT
	Pre_PS_Num = PS_Num;
#endif
	if((pstRDSData->event_status)&RDS_EVENT_PROGRAMNAME)
	{
		PS_Num = 0;
		for(num=0;num<8;num++)
		{
			if((pstRDSData->PS_Data.PS[2][num] == 0x20)||(pstRDSData->PS_Data.PS[2][num] == 0x00))
			{
				PS_Num |= 1<<num;
			}
		}
		if(PS_Num == 0xFF)
		{
			kal_trace(TRACE_INFO, FM_INFO_FM_RDS_PS_CANNCEL); 
			pstRDSData->event_status &= (~RDS_EVENT_PROGRAMNAME);
	    }
	}
}	
#if FMR_RDS_FULL_SUPPORT
void RDS_RetrieveGroup1(kal_uint16 *block_data, kal_uint8 SubType)
{
	//kal_uint8 SubType
	kal_uint8 variant_code;
	
	//SubType = (*(block_data+1)&0x0800)>>11;
	variant_code = block_data[2]&0x7000>>12;
	if(variant_code == 0)
		pstRDSData->Extend_Country_Code = block_data[2]&0x00FF;
	else if(variant_code == 3)
		pstRDSData->Language_Code = block_data[2]&0x0FFF;		
	pstRDSData->Radio_Page_Code = block_data[1]&0x001F;
	pstRDSData->Program_Item_Number_Code = block_data[3];	
}
#endif
void RDS_RetrieveGroup2(kal_uint16 *block_data, kal_uint8 SubType)
{
	kal_int8 indx,TextNum;
	kal_uint8 TextAddr, space, buffer0, buffer1;
#ifdef RDS_RT_CBC_SUPPORT
	kal_uint8 corrBitCnt_BlkC, corrBitCnt_BlkD;
#endif	
	kal_uint16 addrcnt;
	kal_bool RTCRC=KAL_FALSE;
	//SubType = (*(block_data+1)&0x0800)>>11;	
	TextAddr = block_data[1]&0x000F;

	//if(pstRDSData->RDSFlag.Text_AB != ((block_data[1]&0x0010)>>4))
	{
		pstRDSData->RDSFlag.Text_AB = (kal_bool)((block_data[1]&0x0010)>>4);
		//pstRDSData->event_status |= 0x0001;
		//pstRDSData->RDSFlag.flag_status |= 0x0080;
	}
	if(PreTextABFlag != pstRDSData->RDSFlag.Text_AB)
	{
		PreTextABFlag = pstRDSData->RDSFlag.Text_AB;
		if(!(pstRDSData->event_status & RDS_EVENT_LAST_RADIOTEXT))
		{
			kal_mem_set(&pstRDSData->RT_Data,0,sizeof(pstRDSData->RT_Data));
			kal_mem_set(pstRDSData->RT_Data.TextData,0x20,sizeof(pstRDSData->RT_Data.TextData));
		}
	}
	
#ifdef RDS_RT_CBC_SUPPORT
	corrBitCnt_BlkC = (block_data[5] & 0x00F0)>>4;
	corrBitCnt_BlkD = block_data[5] & 0xF;
#endif
	
	pstRDSData->RT_Data.isTypeA = (kal_bool)(1-SubType);
	if(!SubType)
	{
        if((block_data[4]&RDS_GDBK_IND_C)&&(block_data[4]&RDS_GDBK_IND_D))/*check each block CRC*/
        {

	  		kal_trace(TRACE_INFO, FM_INFO_FM_RDS_RT_DATA, TextAddr, block_data[2], block_data[3]);
			pstRDSData->RT_Data.TextData[0][4*TextAddr] = block_data[2]>>8;
			pstRDSData->RT_Data.TextData[0][4*TextAddr+1] = block_data[2]&0xFF;
			pstRDSData->RT_Data.TextData[0][4*TextAddr+2] = block_data[3]>>8;
			pstRDSData->RT_Data.TextData[0][4*TextAddr+3] = block_data[3]&0xFF;
#ifdef RDS_RT_CBC_SUPPORT
			if(corrBitCnt_BlkC == 0) 
			{
				pstRDSData->RT_Data.TextData[1][4*TextAddr] = block_data[2]>>8;
				pstRDSData->RT_Data.TextData[1][4*TextAddr+1] = block_data[2]&0xFF;
			}
			if(corrBitCnt_BlkD == 0) 
			{
				pstRDSData->RT_Data.TextData[1][4*TextAddr+2] = block_data[3]>>8;
				pstRDSData->RT_Data.TextData[1][4*TextAddr+3] = block_data[3]&0xFF;
			}
#endif        
			RTCRC=KAL_TRUE;
		}
		TextNum=4;
	}
	else
	{
		if(block_data[4]&RDS_GDBK_IND_D)
		{
			kal_trace(TRACE_INFO, FM_INFO_FM_RDS_RT_DATA, TextAddr, 0, block_data[3]);
			pstRDSData->RT_Data.TextData[0][2*TextAddr] = block_data[3]>>8;
			pstRDSData->RT_Data.TextData[0][2*TextAddr+1] = block_data[3]&0xFF;
#ifdef RDS_RT_CBC_SUPPORT
			if(corrBitCnt_BlkD == 0) 
			{
				pstRDSData->RT_Data.TextData[1][2*TextAddr] = block_data[3]>>8;
				pstRDSData->RT_Data.TextData[1][2*TextAddr+1] = block_data[3]&0xFF;
			}
#endif            
			RTCRC=KAL_TRUE;
		}
		TextNum=2;
	}
	if(RTCRC==KAL_TRUE)
	{
		space = 0;
		for(indx=0;indx<TextNum;indx++)
		{
			buffer0 = pstRDSData->RT_Data.TextData[0][TextNum*TextAddr+indx];
			buffer1 = pstRDSData->RT_Data.TextData[1][TextNum*TextAddr+indx];
			if((!((pstRDSData->event_status)&RDS_EVENT_LAST_RADIOTEXT))&&(buffer0 == buffer1))//avoid cover RT be shown
			{
				space ++;
				kal_trace(TRACE_INFO, FM_INFO_FM_RDS_RT_BUFF2, TextNum*TextAddr+indx);
				pstRDSData->RT_Data.TextData[2][TextNum*TextAddr+indx] = buffer0;
			}
			else
			{
				kal_trace(TRACE_INFO, FM_INFO_FM_RDS_RT_BUFF1, TextNum*TextAddr+indx);
				pstRDSData->RT_Data.TextData[1][TextNum*TextAddr+indx] = buffer0;
				pstRDSData->RT_Data.Addr_Cnt &= ~(1<<TextAddr);
			}					
		}
		if(space == TextNum)
		{
			addrcnt = pstRDSData->RT_Data.Addr_Cnt;
			pstRDSData->RT_Data.Addr_Cnt |= (1<<TextAddr);
			if(addrcnt == pstRDSData->RT_Data.Addr_Cnt)
			{
				pstRDSData->RT_Data.BufCnt ++;
			}
			else if(pstRDSData->RT_Data.BufCnt > 0)
			{
				pstRDSData->RT_Data.BufCnt --;
			}
		}
	}
	for(indx=0;indx<TextNum;indx++)
	{
		if((pstRDSData->RT_Data.TextData[2][TextNum*TextAddr+indx]) == 0x0D)
		{
			pstRDSData->RT_Data.TextLength = TextAddr;
			pstRDSData->RT_Data.GetLength = KAL_TRUE;
		}
	}

/*Check if text is fully received*/
	indx = pstRDSData->RT_Data.TextLength;
	if((pstRDSData->RT_Data.GetLength) == KAL_TRUE)
	{
    	addrcnt = 0xFFFF>>(0x0F-indx);
	}
	else if(pstRDSData->RT_Data.BufCnt > 100)
	{
		pstRDSData->RT_Data.BufCnt = 0;
		for(indx=15;indx>0;indx--)
		{
			addrcnt = (pstRDSData->RT_Data.Addr_Cnt)&(1<<indx);
			if(addrcnt)
				break;
		}
		pstRDSData->RT_Data.TextLength = indx;
		addrcnt = 0xFFFF>>(0x0F-indx);
	}
	else
	{
		pstRDSData->RT_Data.TextLength = 0x0F;
		addrcnt = 0xFFFF;
	}
	kal_trace(TRACE_INFO, FM_INFO_FM_RDS_RT_LEN, pstRDSData->RT_Data.Addr_Cnt, indx, addrcnt);
	if((((pstRDSData->RT_Data.Addr_Cnt)&addrcnt) == addrcnt)&&(pstRDSData->RT_Data.isRTDisplay == KAL_FALSE))
	{		
		if((pstRDSData->RT_Data.Addr_Cnt) == addrcnt)
		{
		pstRDSData->RT_Data.isRTDisplay = KAL_TRUE;
		pstRDSData->event_status |= RDS_EVENT_LAST_RADIOTEXT; 
		space = 0;
		for(indx=0;indx<64;indx++)
		{
			if(pstRDSData->RT_Data.TextData[2][indx] == 0x20)
				space++;
		    if(space == 64)
				pstRDSData->event_status &= (~RDS_EVENT_LAST_RADIOTEXT);
	    }	
		/*for(indx=0;indx<64;indx++)
		{
			pstRDSData->RT_Data.TextData[1][indx] = 0x20;
			pstRDSData->RT_Data.TextData[0][indx] = 0x20;
		}*/
		}
		
		pstRDSData->RT_Data.Addr_Cnt = 0;
		addrcnt = 0;
		kal_mem_set(pstRDSData->RT_Data.TextData,0x20,sizeof(pstRDSData->RT_Data.TextData[0])*2);
    }
}

#if FMR_RDS_FULL_SUPPORT
void RDS_RetrieveGroup4(kal_uint16 *block_data, kal_uint8 SubType)
{
  kal_uint16 Year,Month,K=0, D1, D2, minute;
  kal_uint32 MJD;
  if((block_data[4]&RDS_GDBK_IND_C)&&(block_data[4]&RDS_GDBK_IND_D))
  {
	MJD = (kal_uint32) (((block_data[1]&0x0003)<<15)+((block_data[2]&0xFFFE)>>1));
	Year = (MJD-15078.2)/365.25;
	Month = (MJD-14956.1-365.25*Year)/30.6001;
	if((Month == 14)||(Month == 15))
	  K = 1;
	D1 = (kal_uint32)(365.25*Year);
	D2 = (kal_uint16)(30.6001*Month);
	pstRDSData->CT.Year = 1900 + Year + K;
	pstRDSData->CT.Month = Month - 1 - K*12;
	pstRDSData->CT.Day = MJD - 14956 - D1 - D2;
	pstRDSData->CT.Hour = ((block_data[2]&0x0001)<<4)+((block_data[3]&0xF000)>>12);
	minute = (block_data[3]&0x0FC0)>>6;
	if(block_data[3]&0x0020)
	{
		pstRDSData->CT.Local_Time_offset_signbit = KAL_TRUE;
	}
	pstRDSData->CT.Local_Time_offset_half_hour = block_data[3]&0x001F;
	if(pstRDSData->CT.Minute != minute)
	{
        pstRDSData->CT.Minute = (block_data[3]&0x0FC0)>>6;
	    pstRDSData->event_status |= RDS_EVENT_UTCDATETIME;
    }
}
}
#endif
void RDS_RetrieveGroup14(kal_uint16 *block_data, kal_uint8 SubType)
{
	kal_uint8 TP_ON, TA_ON, PS_Num, AF_H, AF_L, indx, indx2, num;

	//SubType = (*(block_data+1)&0x0800)>>11;
	TP_ON = block_data[1]&0x0010;						   	
	if(!SubType&&(block_data[4]&RDS_GDBK_IND_C)) //Type A
	{
		PS_Num= block_data[1]&0x000F;
		if(PS_Num <4)
		{
			for(indx=0;indx<2;indx++)
			{
				pstRDSData->PS_ON[2*PS_Num] = block_data[2]>>8;
				pstRDSData->PS_ON[2*PS_Num+1] = block_data[2]&0xFF;
			}						
		}
		else if(PS_Num == 4)
		{
			AF_H = (block_data[2]&0xFF00)>>8;
			AF_L = block_data[2]&0x00FF;
			if((AF_H > 223)&&(AF_H  <250)) //Followed AF Number
			{
				pstRDSData->AFON_Data.AF[0][0]= AF_H - 224; //AFON Number
				if((pstRDSData->AFON_Data.AF[1][0]) != (pstRDSData->AFON_Data.AF[0][0]))
				{
					pstRDSData->AFON_Data.AF[1][0] = pstRDSData->AFON_Data.AF[0][0];
				}
				else
					pstRDSData->AFON_Data.isAFNum_Get= KAL_TRUE;
				if((AF_L < 205))
				{
					pstRDSData->AFON_Data.AF[0][1] = AF_L;
					if((pstRDSData->AFON_Data.AF[0][1]) != (pstRDSData->AFON_Data.AF[1][1]))
					{
						pstRDSData->AFON_Data.AF[1][1] = pstRDSData->AFON_Data.AF[0][1];
					}
					else
					{
						pstRDSData->AFON_Data.isMethod_A = KAL_TRUE;
					}
				}
			}
			else if((pstRDSData->AFON_Data.isAFNum_Get)&&((pstRDSData->AFON_Data.Addr_Cnt) != 0xFF)) //AF Num correct
			{
				num = pstRDSData->AFON_Data.AF[1][0];
				num = num>>1;
				//Put AF freq into buffer and check if AF freq is repeat again
			       for(indx=1; indx < num+1; indx++)
		       	{
		       		if((AF_H == (pstRDSData->AFON_Data.AF[0][2*num]))&&(AF_L == (pstRDSData->AFON_Data.AF[0][2*num+1])))
					{
						break;
					}
					else if(!(pstRDSData->AFON_Data.AF[0][2*indx])) //null buffer
					{
						pstRDSData->AFON_Data.AF[0][2*indx] = AF_H;
						pstRDSData->AFON_Data.AF[0][2*indx+1] = AF_L;
						break;
					}
		       	}
				num = pstRDSData->AFON_Data.AF[1][0];
				if(num > 0)
				{
					if((pstRDSData->AFON_Data.AF[0][num]) != 0)
					{
						num = num>> 1;
						//arrange frequency from low to high:start
						for(indx=1;indx<num;indx++)
						{
							for(indx2=indx+1;indx2<num+1;indx2++)
							{
								AF_H = pstRDSData->AFON_Data.AF[0][2*indx];
								AF_L = pstRDSData->AFON_Data.AF[0][2*indx+1];
								if(AF_H > (pstRDSData->AFON_Data.AF[0][2*indx2]))
								{
									pstRDSData->AFON_Data.AF[0][2*indx] = pstRDSData->AFON_Data.AF[0][2*indx2];
									pstRDSData->AFON_Data.AF[0][2*indx+1] = pstRDSData->AFON_Data.AF[0][2*indx2+1];
									pstRDSData->AFON_Data.AF[0][2*indx2] = AF_H;
									pstRDSData->AFON_Data.AF[0][2*indx2+1] = AF_L;
								}
								else if(AF_H == (pstRDSData->AFON_Data.AF[0][2*indx2]))
								{
									if(AF_L > (pstRDSData->AFON_Data.AF[0][2*indx2+1]))
			{			
										pstRDSData->AFON_Data.AF[0][2*indx] = pstRDSData->AFON_Data.AF[0][2*indx2];
										pstRDSData->AFON_Data.AF[0][2*indx+1] = pstRDSData->AFON_Data.AF[0][2*indx2+1];
										pstRDSData->AFON_Data.AF[0][2*indx2] = AF_H;
										pstRDSData->AFON_Data.AF[0][2*indx2+1] = AF_L;
									}
			}
							}
						}
						//arrange frequency from low to high:end
						//compare AF buff0 and buff1 data:start
						num = pstRDSData->AFON_Data.AF[1][0];
						indx2 = 0;
						for(indx=1;indx<num+1;indx++)
						{
							if((pstRDSData->AFON_Data.AF[1][indx]) == (pstRDSData->AFON_Data.AF[0][indx]))
			{
								if(pstRDSData->AFON_Data.AF[1][indx] != 0)
									indx2 ++;
							}
							else
								pstRDSData->AFON_Data.AF[1][indx] = pstRDSData->AFON_Data.AF[0][indx];
			}
						//compare AF buff0 and buff1 data:end
						if(indx2 == num)
						{
							pstRDSData->AFON_Data.Addr_Cnt = 0xFF;
			pstRDSData->event_status |= RDS_EVENT_AFON_LIST;				
							for(indx=0;indx<num;indx++)
							{
								if((pstRDSData->AFON_Data.AF[1][indx]) == 0)
								{
									pstRDSData->AFON_Data.Addr_Cnt = 0x0F;
									pstRDSData->event_status &= (~RDS_EVENT_AFON_LIST);
								}
							}
						}
						else
							pstRDSData->AFON_Data.Addr_Cnt = 0x0F;
					}
				}
			}
		}		
	}
	else//Type B
	{
		TA_ON = *(block_data+1)&0x0008;
		if((!pstRDSData->RDSFlag.TP[1])&&(pstRDSData->RDSFlag.TA)&&TP_ON&&TA_ON)
		{
			//pstRDSData->AF_ON[0] = 1000;	 //for test				
			pstRDSData->event_status |= RDS_EVENT_TAON;	
		}
	}					
}

void RDS_Init_Data(void)
{
	kal_uint8 indx;

  memset (pstRDSData, 0 ,sizeof(RDSData_Struct)); 
#if !defined(FMR_DSP_CHIP)
  RDS_FirstIn = 1;
#endif
#if FMR_RDS_FULL_SUPPORT
  pstRDSData->PTY = 0xFF; //to avoid "rx PTY == 0" case, this will cause no PTY event
#endif  
	for(indx=0;indx<64;indx++)
	{
		pstRDSData->RT_Data.TextData[0][indx]=0x20;
		pstRDSData->RT_Data.TextData[1][indx]=0x20;		
	}
	for(indx=0;indx<8;indx++)
	{
		pstRDSData->PS_Data.PS[0][indx] = 0x00;
		pstRDSData->PS_Data.PS[1][indx] = 0x20;	
		pstRDSData->PS_Data.PS[2][indx] = 0x20;
		pstRDSData->PS_ON[indx] = 0x20;
	}
}
//void RDS_Eint_Handler(void (*callback)( kal_uint16 event, RDSData_Struct Data))
void RDS_Eint_Handler(void)
{
#ifdef RDS_PS_CBC_SUPPORT
	kal_uint16 block_data[8], fifo_offset;
	kal_bool is_first = KAL_TRUE;//TP need get twice continuously
#else
	kal_uint16 block_data[5], fifo_offset;
#endif
	kal_uint8 GroupType, SubType;
#if (defined(FM_INTERFACE_HCI) && defined(MT6616))
	kal_uint8 indx, indx2, dataM, dataL;
#endif
	if(!isRdsOn)   
	{
		return;
	}
	//pstRDSData->EINT_Flag = KAL_TRUE;
#if (defined(FM_INTERFACE_HCI) && defined(MT6616))
	for(indx=0;indx<5;indx++)
	{
		dataL = pstFMR_data->FM_HCI_data.buffer[5+2*indx];
		dataM = pstFMR_data->FM_HCI_data.buffer[6+2*indx];
		block_data[indx] = (kal_uint16)(dataM<<8|dataL);
	}
    kal_trace(TRACE_INFO, FM_INFO_FM_RDS_BLOCK_DATA, block_data[0], block_data[1], block_data[2], block_data[3], block_data[4]);
	if(block_data[4]&RDS_GDBK_IND_B) //Block1 is CRC OK
	{
		GroupType = (block_data[1]&0xF000)>>12;
		SubType = (block_data[1]&0x0800)>>11;
	    kal_trace(TRACE_INFO, FM_INFO_FM_RDS_GROUP, GroupType, SubType);
		/*
		pstRDSData->Block_Backup[GroupType*2+SubType][0]=block_data[0];
		pstRDSData->Block_Backup[GroupType*2+SubType][1]=block_data[1];
		pstRDSData->Block_Backup[GroupType*2+SubType][2]=block_data[2];
		pstRDSData->Block_Backup[GroupType*2+SubType][3]=block_data[3];
		*/
	}
	else
		return;
	if(pstRDSData->Group_Cnt[2*GroupType+SubType]<0xFFFF)
		pstRDSData->Group_Cnt[2*GroupType+SubType] += 1;

#if FMR_RDS_FULL_SUPPORT
	if(block_data[4]&RDS_GDBK_IND_A) //Block0 is CRC OK
	{
		if(pstRDSData->PI != block_data[0])
	        {
			pstRDSData->PI = block_data[0];
			pstRDSData->event_status |= RDS_EVENT_PI_CODE;
	        }
	}
	if(pstRDSData->PTY != ((block_data[1]&0x03E0)>>5))
	{
		pstRDSData->PTY = (block_data[1]&0x03E0)>>5;
		pstRDSData->event_status |= RDS_EVENT_PTY_CODE;			
	}
#endif	

	/*TP Flag: Start */
	if((block_data[1]&0x0400)>>10)
	{
		if(pstRDSData->RDSFlag.TP[0])
		{
			if((pstRDSData->RDSFlag.TP[1]) != 1)
			{
				pstRDSData->RDSFlag.TP[1] = 1;
				pstRDSData->event_status |= RDS_EVENT_FLAGS;			
				pstRDSData->RDSFlag.flag_status |= RDS_FLAG_IS_TP;	
			}
		}
		else
		{
			pstRDSData->RDSFlag.TP[0] = 1;
		}
	}
	else
	{
        if(pstRDSData->RDSFlag.TP[1])
        {
            pstRDSData->event_status |= RDS_EVENT_FLAGS;           
            pstRDSData->RDSFlag.flag_status |= RDS_FLAG_IS_TP;    
        }
		pstRDSData->RDSFlag.TP[0] = 0;
		pstRDSData->RDSFlag.TP[1] = 0;
	}
	/*TP Flag:End */
	switch(GroupType)
	{
	   case 0:
	   	RDS_RetrieveGroup0(&block_data[0], SubType);
	   	break;
#if FMR_RDS_FULL_SUPPORT
          case 1:
	   	RDS_RetrieveGroup1(&block_data[0], SubType);							
	   	break;
          case 4:
	   	RDS_RetrieveGroup4(&block_data[0], SubType);		
		break;		
#endif		
          case 2:
	   	RDS_RetrieveGroup2(&block_data[0], SubType);							
	      	break;
	   case 14:
	   	RDS_RetrieveGroup14(&block_data[0], SubType);										   	
	   	break;	
          default:
	      	break;			 
	}
#else/*(defined(FM_INTERFACE_HCI) && defined(MT6616))*/
	//pstRDSData->EINT_Flag = KAL_TRUE;
	do
	{
		FMDrv_RDS_GetData(&block_data[0]);
		// print RDS data
		kal_trace(TRACE_INFO, FM_INFO_FM_RDS_BLOCK_DATA, block_data[0], block_data[1], block_data[2], block_data[3], block_data[4]);
#if defined(FMR_DSP_CHIP)
		kal_trace(TRACE_INFO, FM_INFO_FM_RDS_BLOCK_DATA, block_data[5], block_data[6], block_data[7]);
        fifo_offset = (block_data[4] & RDS_DCO_FIFO_OFST) >> 4;
#elif (defined(RDS_PS_CBC_SUPPORT))
		kal_trace(TRACE_INFO, FM_INFO_READ_DATA,0xD6,block_data[5]);
		fifo_offset = (block_data[4] & RDS_DCO_FIFO_OFST) >> 5;
#else
		fifo_offset = (block_data[4] & RDS_DCO_FIFO_OFST) >> 5;
#endif
		/*whether FIFO is full*/
#ifdef RDS_FIFO_FULL_DETECT
		if(block_data[4] & 0x8000)
		{
			fifo_offset = 0xffff;
		}
#endif
		// set flag		
		if(block_data[4]&RDS_GDBK_IND_B) //Block1 is CRC OK
		{
			GroupType = (block_data[1]&0xF000)>>12;
			SubType = (block_data[1]&0x0800)>>11;
			kal_trace(TRACE_INFO, FM_INFO_FM_RDS_GROUP, GroupType, SubType);
		}
		else
        {
            continue;
        }
		if(pstRDSData->Group_Cnt[2*GroupType+SubType]<0xFFFF)
		{
			pstRDSData->Group_Cnt[2*GroupType+SubType] += 1;//meta get
		}
		//Backup Block data
		/*
		pstRDSData->Block_Backup[GroupType*2+SubType][0]=block_data[0];
		pstRDSData->Block_Backup[GroupType*2+SubType][1]=block_data[1];
		pstRDSData->Block_Backup[GroupType*2+SubType][2]=block_data[2];
		pstRDSData->Block_Backup[GroupType*2+SubType][3]=block_data[3];
		*/
		
#if FMR_RDS_FULL_SUPPORT
#ifdef RDS_PS_CBC_SUPPORT
		if((block_data[5]&0xF000) == 0)//block A CBC==0
#endif
		{
			if(block_data[4]&RDS_GDBK_IND_A) //Block A is CRC OK
			{		
				if(pstRDSData->PI != block_data[0])
				  {
					pstRDSData->PI = block_data[0];
					pstRDSData->event_status |= RDS_EVENT_PI_CODE;
				  }			
			}
		}
#ifdef RDS_PS_CBC_SUPPORT
		if((block_data[5]&0x0F00) == 0)//block B CBC==0
#endif
		{
			if(pstRDSData->PTY != ((block_data[1]&0x03E0)>>5))
			{
				pstRDSData->PTY = (block_data[1]&0x03E0)>>5;
				pstRDSData->event_status |= RDS_EVENT_PTY_CODE;			
			}
		}
#endif
	  /*TP Flag: Start */
		if(g_TP_Enable)
		{
#ifdef RDS_PS_CBC_SUPPORT
			if((block_data[5]&0x0F00) != 0)//block B CBC!=0
			{
				is_first = KAL_TRUE;//CBC right twice continuously
			}
			else
#endif
			{
			  if((block_data[1]&0x0400)>>10)/*TP is 1*/
			  {
				  if((pstRDSData->RDSFlag.TP[0])
#ifdef RDS_PS_CBC_SUPPORT
				  && (is_first == KAL_FALSE)
#endif
				  )/*CBC right twice and TP is same*/
				  {
					  if(!(pstRDSData->RDSFlag.TP[1]))/*last TP flag is differernt*/
					  {
						  pstRDSData->RDSFlag.TP[1] = KAL_TRUE;
						  pstRDSData->event_status |= RDS_EVENT_FLAGS;			
						  pstRDSData->RDSFlag.flag_status |= RDS_FLAG_IS_TP;	
					  }
				  }
				  else/*fist CBC right*/
				  {
#ifdef RDS_PS_CBC_SUPPORT
					  is_first = KAL_FALSE;
#endif
					  pstRDSData->RDSFlag.TP[0] = KAL_TRUE;
				  }
			  }
			  else/*TP is 0*/
			  {
		          if(pstRDSData->RDSFlag.TP[1])/*last TP is different*/
		          {
		              pstRDSData->event_status |= RDS_EVENT_FLAGS;           
		              pstRDSData->RDSFlag.flag_status |= RDS_FLAG_IS_TP;    
		          }
				  pstRDSData->RDSFlag.TP[0] = KAL_FALSE;
				  pstRDSData->RDSFlag.TP[1] = KAL_FALSE;
			  }
			}
		}
		else/*Set TP default value*/
		{
			pstRDSData->RDSFlag.TP[1] = KAL_FALSE;
		}
	  /*TP Flag:End */
		switch(GroupType)
		{
			case 0:
			   	RDS_RetrieveGroup0(&block_data[0], SubType);
			   	break;
#if FMR_RDS_FULL_SUPPORT
			case 1:
			   	RDS_RetrieveGroup1(&block_data[0], SubType);							
			   	break;
			case 4:
				RDS_RetrieveGroup4(&block_data[0], SubType);		
				break;		
#endif				
            case 2:
			   	RDS_RetrieveGroup2(&block_data[0], SubType);							
               	break;
		    case 14:
			   	RDS_RetrieveGroup14(&block_data[0], SubType);										   	
			   	break;	
			default:
				break;			 
		}
	}while(fifo_offset > 1);
	#endif	
}
#ifndef FMR_DSP_CHIP
#define RDS_BLER_TH1 90
#define RDS_BLER_TH2 60
#define RDS_BLER_C1  12
#define RDS_BLER_C2  6
#define RDS_BLER_T1 5000
#define RDS_BLER_T2 5000

void RDS_BlerCheck(void)
{
	kal_uint16 GOOD_BLK_CNT, BAD_BLK_CNT, TOTAL_CNT;
	kal_uint8 BAD_BLK_RATIO;
	
	if(!isRdsOn)
       	return;

	_BLER_CHK_INTERVAL = RDS_BLER_T1;
	GOOD_BLK_CNT = RDS_Read_Block_Counter(KAL_TRUE);
	BAD_BLK_CNT = RDS_Read_Block_Counter(KAL_FALSE);
	TOTAL_CNT = GOOD_BLK_CNT + BAD_BLK_CNT;
	FMDrv_RDS_Reset_BKCnt();
	if((GOOD_BLK_CNT==0)&&(BAD_BLK_CNT==0))
		BAD_BLK_RATIO = 0;
	else
		BAD_BLK_RATIO = ((float)BAD_BLK_CNT/(GOOD_BLK_CNT + BAD_BLK_CNT))*100;

    kal_trace(TRACE_INFO,FM_INFO_FM_RDS_BLER_ERR,TOTAL_CNT, BAD_BLK_RATIO);
	if((BAD_BLK_RATIO < RDS_BLER_TH2)&&(RDS_Sync_Cnt > RDS_BLER_C1))
	{
		_BLER_CHK_INTERVAL = RDS_BLER_T2;
		if(RDS_Block_Reset_Cnt > 1)
			RDS_Block_Reset_Cnt --;
	}
	else
	{
		if(BAD_BLK_RATIO > RDS_BLER_TH1)
		{
			RDS_Reset_Block_Counter();
			RDS_Sync_Cnt = 0;
			RDS_Block_Reset_Cnt ++;
			if((RDS_Block_Reset_Cnt > RDS_BLER_C2)||RDS_FirstIn)
			{
                if(RDS_FirstIn)
				  RDS_FirstIn = 0;
				RDS_Reset();
				RDS_Block_Reset_Cnt = 0;
			}
			else if(TOTAL_CNT > 12)
			{
				kal_trace(TRACE_INFO, FM_INFO_FM_RDS_BLK_RST, RDS_Block_Reset_Cnt);
				RDS_Block_Reset();
			}
		}
		else
		{
			RDS_Sync_Cnt ++;		
			if(RDS_Block_Reset_Cnt > 1)
				RDS_Block_Reset_Cnt --;
			if(RDS_Sync_Cnt > RDS_BLER_C1)
			{
				_BLER_CHK_INTERVAL = RDS_BLER_T2;
			}
		}
	}
}
#endif
#endif // defined(FM_RADIO_RDS_SUPPORT)
