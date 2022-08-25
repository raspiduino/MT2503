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
 *   FactoryModeFM.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   FM ATE
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __FM_AT_SUPPORT__
 
 /***************************************************************************** 
  * Include
  *****************************************************************************/
 //#include "Mdi_include.h"
 //#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "FMATCommand.h"
#include "us_timer.h"
 //#include "FileManagerGProt.h"
 //#include "FMRadioDef.h"
 //#include "FMRadioType.h"
 //#include "mmi_frm_events_gprot.h"
 
#define FM_ATE_DEFAULT_FREQ (987)
 extern void FMR_SetAntennaType(kal_uint8 ata_type);
 extern void rmmi_write_to_uart(kal_uint8 *buffer, kal_uint16 length, kal_bool stuff);
 extern void mmi_fmrdo_preempted(S32 result, void *user_data);
 extern void FMDrv_JammerScan(void);
 extern kal_bool All_Channel_Hopping_Set;
 /* 
  * [AT Command] 
  * (1) Power On : at+egcmd = 7, 1, "00"
  * (2) Power Off : at+egcmd = 8, 1, "00" .
  (3)set freq: at+egcmd = 9, 2, "xxXX",xxXX is frequency(hex,khz)
  (4)set antenna type: at+egcmd = 10, 2, "0001",1:short antenna,0:long antenna.
  (5)read register:at+egcmd = 10, 2, "01XX",XX:register address.
  (6)write register:at+egcmd = 10, 4, "02XXoooo",XX:register address, oooo:data to be written.
  (7)read register:at+egcmd = 10, 5, "04xxxxXXXX",xxxxXXXX:register address.
  (8)write register:at+egcmd = 10, 9, "05xxxxXXXXooooOOOO",xxxxXXXX:register address, ooooOOOO:data to be written.
  */
 
 void mmi_fm_atcommand_init(void)
 {
	 SetProtocolEventHandler(fm_ate_test_cmd_req_hdlr, MSG_ID_MMI_FM_ATE_TEST_REQ); //ALBERT_AT
	 kal_prompt_trace(MOD_FMR,"fm_atcommand_init: DONE!");
 }
 
 /*****************************************************************************
  * FUNCTION
  *  mmi_fm_fm_ate_power_on
  * DESCRIPTION
  *  Power on FM module
  * PARAMETERS
  *  void
  * RETURNS
  *  void
  *****************************************************************************/
 void fm_ate_power_on(void)
 {	 
	 if (FMR_IsActive() == KAL_FALSE)
	 {
		 mdi_fmr_power_on_with_path(MDI_DEVICE_SPEAKER2, (mdi_ext_callback) NULL,NULL);
		 kal_prompt_trace(MOD_FMR,"fm_atcommand_power_on: DONE!");
	 }
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  mmi_fm_fm_ate_power_off
  * DESCRIPTION
  *  Power off FM module
  * PARAMETERS
  *  void
  * RETURNS
  *  void
  *****************************************************************************/
 void fm_ate_power_off(void)
 {
	 if (FMR_IsActive() == KAL_TRUE)
	 {
		 mdi_fmr_power_off();
		 kal_prompt_trace(MOD_FMR,"fm_atcommand_power_off: DONE!");
	 }
 }
  /*****************************************************************************
  * FUNCTION
  *  Delayms  
  * PARAMETERS
  *  data : delay ms
  * RETURNS
  *  void
  *****************************************************************************/

 static void Delayms(kal_uint32 data)
{
    while(data--)
    {        
		ust_busy_wait(1000);
    }
}
 /*****************************************************************************
  * FUNCTION
  *  mmi_fm_fm_ate_set_freq
  * DESCRIPTION
  *  Power off FM module
  * PARAMETERS
  *  void
  * RETURNS
  *  void
  *****************************************************************************/
 void fm_ate_set_freq(kal_uint16 freq)
 {
	 /*----------------------------------------------------------------*/
	 /* Local Variables 											   */
	 /*----------------------------------------------------------------*/
	 
	 /*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
	 if (FMR_IsActive() == KAL_FALSE)
	 {
		 mdi_fmr_power_on_with_path(MDI_DEVICE_SPEAKER2,(mdi_ext_callback)NULL,NULL);
	 }
	 mdi_fmr_set_freq(freq);
	 kal_prompt_trace(MOD_FMR,"fm_atcommand_set_freq: %d'd",freq);
 }
 
 
 
 /*****************************************************************************
  * FUNCTION
  *  mmi_fm_fm_ate_send_pmtk_command
  * DESCRIPTION
  *  Send pmtk command to gps module
  * PARAMETERS
  *  data_len		 [IN]		 command len
  *  data_str		 [IN]		 command data
  * RETURNS
  *  void
  *****************************************************************************/
 void fm_ate_other_command(kal_int32 data_len, kal_uint8 *data_str)
 {
#if defined(__MTK_TARGET__) 	
	 kal_uint16 ReadData;
	 kal_uint8 buffer[32];
	 kal_uint32 Reg32,Addr32;
 
	 switch(data_str[0])
	 {
		 case 0:
			 FMR_SetAntennaType(data_str[1]);
			 kal_prompt_trace(MOD_FMR,"fm_atcommand_SetAntennaType: %d'd",data_str[1]);
			 break;
		 case 1:
			 ReadData = FMR_ReadByte(data_str[1]);
			 kal_prompt_trace(MOD_FMR,"fm_ate_other_command: ReadData=%x,address=%x!",ReadData,data_str[1]);
			 kal_sprintf((kal_char*) buffer, "REG:0x%x", ReadData);	  // now buffer string is "REG=12"
			 rmmi_write_to_uart(buffer, strlen((char*)buffer),KAL_TRUE);
			 break;
		 case 2:
			 ReadData = (kal_uint16)((data_str[2]<<8)|data_str[3]);
			 kal_prompt_trace(MOD_FMR,"fm_ate_other_command: WriteData=%x,address=%x!",ReadData,data_str[1]);
			 FMR_WriteByte(data_str[1], ReadData);
			 break; 
#if (defined(MT6250FM) || defined(MT6260FM) || defined(MT6261FM))
		 case 3:
			 kal_prompt_trace(MOD_FMR,"6250 jammer scan start");
			FMDrv_JammerScan();
			 break; 	
#endif			 
		case 4:
			Addr32=(data_str[1]<<24)|(data_str[2]<<16)|(data_str[3]<<8)|data_str[4];
			Reg32=*((volatile unsigned int*)Addr32);
			kal_prompt_trace(MOD_FMR,"FMATCMD:Read %x=%x",Addr32,Reg32);
			kal_sprintf((kal_char*) buffer, "REG:0x%x", Reg32);	
			rmmi_write_to_uart(buffer, strlen((char*)buffer),KAL_TRUE);
			break; 	
		case 5:
			Addr32=(data_str[1]<<24)|(data_str[2]<<16)|(data_str[3]<<8)|data_str[4];
			Reg32=(data_str[5]<<24)|(data_str[6]<<16)|(data_str[7]<<8)|data_str[8];
			*((volatile unsigned int*)Addr32)=Reg32;
			kal_prompt_trace(MOD_FMR,"FMATCMD:Write %x=%x",Addr32,Reg32);
			break;
		case 6:
#if defined(MT6250FM)
			Reg32=data_str[3];
			L1D_FH_FM_SetFreq(Reg32);
			ReadData=(data_str[1]<<8)|data_str[2];
			FMDrv_SetFreq( ReadData );
#endif
#if defined(MT6260FM)
			L1D_FH_FM_Set_PLL_FreeRunParams(data_str[3],data_str[4]);
			ReadData=(data_str[1]<<8)|data_str[2];
			FMDrv_SetFreq( ReadData );
#endif
			kal_prompt_trace(MOD_FMR,"FMATCMD:freq:%d, hopping:%dx",ReadData,Reg32);
			break;
		case 7://read all fm register
		{
			ReadData=FMR_ReadByte(0x60);
			FMR_WriteByte(0x60,ReadData&(~0x0008));			
			for(Reg32=0;Reg32<=0xFF;Reg32++)	
			{												
				ReadData=FMR_ReadByte(Reg32);				
				kal_sprintf((kal_char*) buffer, "REG:%x=0x%x", Reg32,ReadData);	 
				rmmi_write_to_uart(buffer, strlen((char*)buffer),KAL_TRUE);
				Delayms(30);
			}	
			ReadData=FMR_ReadByte(0x60);
			FMR_WriteByte(0x60,ReadData|0x0008);
			break;
		}
		case 8://all channel hopping set
		{
			if(data_str[1])
			{
				All_Channel_Hopping_Set = 1;
				L1D_FH_FM_Set_PLL_FreeRunParams(data_str[2],data_str[3]);
			}
			else
				All_Channel_Hopping_Set = 0;
			
			break;
		}
		 default:
			 break;
	 }
#endif
 }
 
 
 /*****************************************************************************
  * FUNCTION
  *  mmi_fm_fm_ate_test_cmd_req_hdlr
  * DESCRIPTION
  *  Test cammand req handler, this function will handle test requst send from 
  *  L4 Uart (at+cmd)
  * PARAMETERS
  *  msg_ptr		 [IN]		message data
  * RETURNS
  *  void
  *****************************************************************************/
 void fm_ate_test_cmd_req_hdlr(void *msg_ptr)
 {
	 mmi_fm_ate_test_req_struct *ind_p;
	 kal_uint8 buffer[10];
	 ind_p = (mmi_fm_ate_test_req_struct*)msg_ptr;
 
	 if (ind_p->event == MMI_FM_ATE_EVENT_POWER_ON)
	 {
		 fm_ate_power_on();
		 fm_ate_set_freq(FM_ATE_DEFAULT_FREQ);
	 }
	 else if (ind_p->event == MMI_FM_ATE_EVENT_POWER_OFF)
	 {
		 fm_ate_power_off();
	 }
	 else if (ind_p->event == MMI_FM_ATE_EVENT_SET_FREQ)
	 {
		fm_ate_set_freq((ind_p->cmd_buf[0]<<8)+ind_p->cmd_buf[1]);
	 }
	 else if (ind_p->event == MMI_FM_ATE_EVENT_COMMAND)
	 {
		 fm_ate_other_command(ind_p->cmd_length, ind_p->cmd_buf);
	 }
	 else 
	 {
		 //MDI_ASSERT(0);
		 kal_prompt_trace(MOD_FMR,"fm_ate_test_cmd_req_hdlr: unknow command!");
		 kal_sprintf((kal_char*) buffer, "FM:FAIL");	// now buffer string is "REG=12"
		 rmmi_write_to_uart(buffer, strlen((char*)buffer),KAL_TRUE);
	 }
 
 }
#endif /* __FM_AT_SUPPORT__ */
 
