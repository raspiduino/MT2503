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
 *    adc_msg_handle.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements the adc message handle
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "dcl.h"
#include "stack_ltlcom.h"	/* msg_send_ext_queue.....definitions */
#include "kal_public_defs.h"
#include "dcl_adc.h"
#include "drvsignals.h"
#include "drv_comm.h"
#include "kal_trace.h"
#include "bmt_trc.h"
#include "bmt.h"
#include "bmt_timer_control.h"

// ============================================================ //
//define
// ============================================================ //


// ============================================================ //
//global variable
// ============================================================ //
static kal_uint32 VBAT_OFF = 3900000;
static double ADCBAT_OFF = 0;

// ============================================================ //
// function prototype
// ============================================================ //


// ============================================================ //
//extern variable
// ============================================================ //


// ============================================================ //
//extern function
// ============================================================ //


// ============================================================ //


void adc_BmtSendilm(module_type dest_id,  msg_type msg_id, local_para_struct *data, sap_type sap_id)
{
	ilm_struct *ilm;

	DRV_SendPrimitive(ilm,
			   MOD_BMT,
			   dest_id,
			   msg_id,
			   data,
			   sap_id); // DCL can use SchedulerPara.pPara.u4Sapid
	
	msg_send_ext_queue(ilm); 
}


// default adc scheduler complete call back
void adc_sche_task_complete_callback(DCL_INT32 handle, DCL_INT32 volt_result, DCL_DOUBLE adc_result)
{
#ifndef L4_NOT_PRESENT
	//ilm_struct *BMT_ilm;
	
	bmt_adc_measure_done_conf_struct *BMT_Prim;
	ADC_CTRL_GET_PHYSICAL_CHANNEL_T adc_ch;   
	ADC_CTRL_GET_SCHEDULER_PARAMETER_T	SchedulerPara;

	sap_type sap_id;
	
	adc_ch.u2AdcName = DCL_VBAT_ADC_CHANNEL;
	DclSADC_Control(handle, ADC_CMD_GET_CHANNEL, (DCL_CTRL_DATA_T *)&adc_ch);
 
	SchedulerPara.u4Handle = handle;
	DclSADC_Control(handle, ADC_CMD_GET_SCHEDULER_PARAMETER, (DCL_CTRL_DATA_T *)&SchedulerPara);   
	
	if (SchedulerPara.pPara.bSend_primitive)
	{
	   BMT_Prim = (bmt_adc_measure_done_conf_struct*)
		  construct_local_para(sizeof(bmt_adc_measure_done_conf_struct), TD_CTRL);
	   BMT_Prim->adc_handle = handle;
	   if ((SchedulerPara.pPara.u1Adc_phy_id == adc_ch.u1AdcPhyCh) &&
		  (SchedulerPara.pPara.u4Ownerid == MOD_UEM) )
	   {
 
		  // make sure the vbat voltage is not affected by the charging  
		  // VBAT_OFF and ADCBAT_OFF will update while charging in OFF state
		  switch(BMT.VBAT_UEM)
		  {
		  case VBAT_UEM_CHR_OUT:
			 BMT_Prim->volt= volt_result;
			 BMT_Prim->adc_value = adc_result;
			 break;
		  case VBAT_UEM_CHR_IN:
			 BMT_Prim->volt= (kal_int32)VBAT_OFF;
			 BMT_Prim->adc_value = ADCBAT_OFF;	 
			 break; 		 
		  case VBAT_UEM_CHR_IN_FISRT:
			 BMT_Prim->volt= volt_result;
			 BMT_Prim->adc_value = adc_result;	 
			 BMT.VBAT_UEM = VBAT_UEM_CHR_IN;
			 break;
		  case VBAT_UEM_CHR_OUT_FIRST:
			 BMT_Prim->volt= (kal_int32)VBAT_OFF;
			 BMT_Prim->adc_value = ADCBAT_OFF;	 
			 BMT.VBAT_UEM = VBAT_UEM_CHR_OUT;
			 break; 			 
		  }
	   }
	   else
	   { 
		  BMT_Prim->volt= volt_result;
		  BMT_Prim->adc_value = adc_result;
	   }

		if (SchedulerPara.pPara.u4Ownerid == MOD_L1)
		{
			sap_id = DRIVER_L1_SAP;
		} 
		else
		{
			sap_id = DRIVER_PS_SAP;
		}

		adc_BmtSendilm((module_type)SchedulerPara.pPara.u4Ownerid,MSG_ID_BMT_ADC_MEASURE_DONE_CONF,(local_para_struct *)BMT_Prim,sap_id);

	}

#endif // #ifndef L4_NOT_PRESENT
}


static void adc_control_status_check(DCL_STATUS adc_status)
{
	if(adc_status != STATUS_OK)
	{
		ASSERT(0);			
	}
}

void bmt_adc_sche_add_item(local_para_struct *buf)
{
	 DCL_STATUS adc_status;

	 bmt_adc_add_item_req_struct *ptr=(bmt_adc_add_item_req_struct *)buf;
	 adc_status = DclSADC_Control(ptr->adc_handle, ADC_CMD_START_MEASURE, NULL);
	 adc_control_status_check(adc_status);
}

 
void bmt_adc_sche_remove_item(local_para_struct *buf)
{
	 DCL_STATUS adc_status;
	 
	 bmt_adc_remove_item_req_struct *ptr=(bmt_adc_remove_item_req_struct *)buf;
	 adc_status = DclSADC_Control(ptr->adc_handle, ADC_CMD_STOP_MEASURE, NULL);
	 adc_control_status_check(adc_status);
}

 
void bmt_adc_sche_modify_parameters(local_para_struct *buf)
{
	 DCL_STATUS adc_status;
	 ADC_CTRL_MODIFY_PARAM_T adc_para;
	 bmt_adc_modify_parameters_req_struct *ptr=(bmt_adc_modify_parameters_req_struct *)buf;
	 adc_para.u4Period = ptr->period;
	 adc_para.u1EvaluateCount = ptr->evaluate_count;
	 adc_status = DclSADC_Control(ptr->adc_handle, ADC_CMD_MODIFY_PARAM, (DCL_CTRL_DATA_T *)&adc_para);
	 adc_control_status_check(adc_status);
}
 
 
void bmt_adc_nvram_read(ilm_struct *current_ilm)
{
	 DCL_HANDLE dcl_handle;
	 ADC_CTRL_SET_CALIBRATION_DATA_T  prSetCalibrationData;
#ifdef __DRV_BMT_REPORT_VBAT_IN_BOOTING__	 
	 ilm_struct 	*BMT_ilm2;
	 bmt_adc_measure_done_conf_struct *BMT_Prim;
#endif
	 drv_trace0(TRACE_GROUP_10, BMT_MSG_ADC_NVRAM_READ_CNF);
	 prSetCalibrationData.ilm_ptr = (void *)current_ilm;
	 dcl_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);
	 DclSADC_Control(dcl_handle, ADC_CMD_SET_CALIBRATION_DATA, (DCL_CTRL_DATA_T *)&prSetCalibrationData);
	 DclSADC_Close(dcl_handle);
 
#ifdef __DRV_BMT_REPORT_VBAT_IN_BOOTING__
	 BMT_Prim = (bmt_adc_measure_done_conf_struct*)construct_local_para(sizeof(bmt_adc_measure_done_conf_struct), TD_CTRL);
	 bmt_get_adc_channel_voltage(DCL_VBAT_ADC_CHANNEL, &VBAT_OFF);
	 BMT_Prim->volt= VBAT_OFF;
	 DRV_BuildPrimitive(BMT_ilm2,
				  MOD_BMT,
				  MOD_UEM,
				  MSG_ID_BMT_ADC_MEASURE_DONE_CONF,
				  BMT_Prim);
	 msg_send_ext_queue(BMT_ilm2);
#endif
 
}


void bmt_set_charge_off_vbat_status(kal_uint32 vbat_off, double adcbat_off)
{
	VBAT_OFF = vbat_off;	
	ADCBAT_OFF = adcbat_off;
}

