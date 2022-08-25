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
 *    bmt_sw_chip_setting.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines bmt sw workaound.
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
#include 	"drv_comm.h"
#include 	"bmt_trc.h"
#include 	"bmt_utility.h"
#if defined(PULSE_LI_CHARGING)  
#include 	"bmt_pulse_li.h"
#elif defined(LINEAR_LI_CHARGING)
#include 	"bmt_linear_li.h"
#endif

#if !defined(BMT_CHARGING_DISABLE)
// ============================================================ //
//define
// ============================================================ //


// ============================================================ //
//global variable
// ============================================================ //
#if defined(DRV_BMT_HW_PRECC_WORKAROUND)
kal_bool SW_Workaround_Flag = KAL_TRUE;
kal_bool Manual_Disable_Charge_Flag = KAL_FALSE;
#endif


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
#if defined(DRV_BMT_HW_PRECC_WORKAROUND)
/*
* FUNCTION
*	   bmt_set_charger_out
*
* DESCRIPTION                                                           
*   	This function is called to set charger out status
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   
*
* GLOBALS AFFECTED
*     None
*/
void bmt_set_charger_status(Charger_Status chr_status)
{
	DCL_HANDLE bmt_dcl_handle;
  	BMT_CTRL_SET_CHR_STATUS_T ChrStatus;
	
	bmt_dcl_handle = DclBMT_Open(DCL_BMT, FLAGS_NONE);
    ChrStatus.ChargerStat = DCL_BMT_CHR_OUT;
    DclBMT_Control(bmt_dcl_handle, BMT_CMD_SET_CHR_STATUS, (DCL_CTRL_DATA_T *)&ChrStatus);
    DclBMT_Close(bmt_dcl_handle);
}


/*
* FUNCTION
*	   PreCC_Chr_Plugout_Check
*
* DESCRIPTION                                                           
*   	This function is called to check whether chrager is plug out
*
* CALLS  
*
* PARAMETERS
*	   BATPHYS
*	
* RETURNS
*	   KAL_TRUE: finish
*	   KAL_FALSE: not finish
*
* GLOBALS AFFECTED
*     None
*/
kal_bool PreCC_Chr_Plugout_Check(BATPHYStruct *BATPHYS)
{
 
   static kal_uint8 SW_Low_Current_Cnts=0;
   Charger_Status ChrStatus;
   DCL_BOOL chr_enable;

	drv_trace0(TRACE_GROUP_10, BMT_SW_WORKAROUND_FLAG_TRUE_TRC);
    if(BATPHYS->VBAT > bmt_charging_para.V_PRE2FAST_THRES)
    {
        SW_Workaround_Flag = KAL_FALSE;
        drv_trace0(TRACE_GROUP_10, BMT_OUTSIDE_SW_WORKAROUND_RANGE_TRC);
        drv_trace0(TRACE_GROUP_10, BMT_SW_WORKAROUND_FLAG_FALSE_TRC);
		Dcl_Chr_Det_Control(NULL, CHR_DET_CMD_GET_CHR_STATUS, (DCL_CTRL_DATA_T *)&ChrStatus);
        if(ChrStatus == bmt_chr_out)
        {
            drv_trace0(TRACE_GROUP_10, BMT_MISSING_HW_PLUG_OUT_TRC);
            bmt_set_charger_status(bmt_chr_out);
            return KAL_TRUE;
        }                
    }
    else
    {
        drv_trace0(TRACE_GROUP_10, BMT_INSIDE_SW_WORKAROUND_RANGE_TRC);
        SW_Workaround_Flag = KAL_TRUE;
        if( BATPHYS->ICHARGE  < bmt_charging_para.ICHARGE_ON_LOW &&
        (BATPHYS->VCHARGER < 2000000))
        {
            SW_Workaround_Flag = KAL_FALSE;
            drv_trace0(TRACE_GROUP_10, BMT_SW_WORKAROUND_FLAG_FALSE_TRC);    
            drv_trace0(TRACE_GROUP_10, BMT_SW_PLUG_OUT_TRC);      
            bmt_set_charger_status(bmt_chr_out);
            return KAL_TRUE;
        }

	
		if( (BMT.pmictrl_state == PMIC_CHARGEON)&&(BATPHYS->ICHARGE < bmt_charging_para.ICHARGE_ON_LOW))
		{
			kal_uint8 threshold=7;

			if (threshold>bmt_get_on_count())
				threshold=bmt_get_on_count();
			
			SW_Low_Current_Cnts++;
			if (SW_Low_Current_Cnts>=threshold)
			{
			    SW_Workaround_Flag = KAL_FALSE;
			    drv_trace0(TRACE_GROUP_10, BMT_SW_WORKAROUND_FLAG_FALSE_TRC);    
			    drv_trace0(TRACE_GROUP_10, BMT_SW_PLUG_OUT_TRC);      
			    bmt_set_charger_status(bmt_chr_out);
			    return KAL_TRUE;
			}
		}
		else
		{		  
			SW_Low_Current_Cnts=0;
		}


		         if(Manual_Disable_Charge_Flag == KAL_TRUE)
                {
                    drv_trace0(TRACE_GROUP_10, BMT_PLUG_OUT_FALSE_ALARM_TRC);   
                    Manual_Disable_Charge_Flag = KAL_FALSE;
                    if(BMT.pmictrl_state == PMIC_CHARGEON)
                    {
                        drv_trace0(TRACE_GROUP_10, BMT_ENABLE_CHARGE_AT_CHARGE_ON_TRC);
						chr_enable = KAL_TRUE;
						bmt_charging_control_handler(BMT_CHARGING_CMD_CHARGING_ENABLE, &chr_enable);
                      
                    }
                    bmt_timer_config(KAL_TICKS_200_MSEC); //45 frames ~= 200ms
                    return KAL_TRUE;
                }
                
                if(BATPHYS->ICHARGE  < bmt_charging_para.ICHARGE_ON_LOW)
                {
                    if(BMT.pmictrl_state == PMIC_CHARGEON)
                    {
                        drv_trace0(TRACE_GROUP_10, BMT_POSSIBLE_PLUG_OUT_TRC);
                        Manual_Disable_Charge_Flag = KAL_TRUE;
						chr_enable = KAL_FALSE;
						bmt_charging_control_handler(BMT_CHARGING_CMD_CHARGING_ENABLE, &chr_enable);
                        drv_trace0(TRACE_GROUP_10, BMT_DISABLE_CHARGE_AT_CHARGE_ON_TRC); 
                        bmt_timer_config(KAL_TICKS_200_MSEC); //45 frames ~= 200ms
                        return KAL_TRUE;
                    }
                    drv_trace0(TRACE_GROUP_10, BMT_LOW_CHARGE_CURRENT_AT_CHARGE_OFF_TRC); 
                }
        }

		return KAL_FALSE;
	
}

#endif // End of #if defined(DRV_BMT_HW_PRECC_WORKAROUND)
#endif //End of #if !defined(BMT_CHARGING_DISABLE)

