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
 *    touch_panel.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module is touch panel driver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include    "drv_features.h"
#include    "drv_comm.h"
#include 	"stack_common.h"
#include    "syscomp_config.h"   /*MOD_BMT*/
#if defined(TOUCH_PANEL_SUPPORT) || defined(HAND_WRITING)
#include 	"stack_msgs.h"
#include 	"app_ltlcom.h"       /* Task message communiction */
#include    "stack_ltlcom.h"       /*msg_send_ext_queue.....definitions*/
#include    "reg_base.h"
#include    "eint.h"
#include    "intrCtrl.h"
#include 	"touch_panel.h"
#include 	"touch_panel_buff.h"
#include 	"gpt_sw.h"
#include "drv_trc.h"
#include "dcl_hts.h"
#include "kal_trace.h"
#include "l1_interface.h"
#include "us_timer.h"
#include "stack_config.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "dcl.h"
#include "stack_config.h"
#if !defined(IC_MODULE_TEST)
extern kal_uint32 /*lint -e(526)*/L1I_GetTimeStamp(void);
#endif

#if defined(DRV_ADC_TOUCH_SCREEN)
#include "init.h"
extern kal_bool /*lint -e(526)*/tp_up_intr_lost_flag;
extern kal_bool /*lint -e(526)*/tp_level(void);
extern void /*lint -e(526)*/TPUpdateNotify(void);
#endif // #if defined(DRV_ADC_TOUCH_SCREEN)


#if defined(DRV_MISC_CACHE_REGION_SUPPORT)
  // If cache is supported, put GPT data into cahched region
  #pragma arm section rwdata = "CACHEDRW" , zidata = "CACHEDZI"
#endif  // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)

#if defined(DRV_TP_NO_EXT_EINT)
   extern void /*lint -e(526)*/ts_drv_init(void);
   extern void /*lint -e(526)*/ts_mask_int(void);
   extern void /*lint -e(526)*/ts_unmask_int(void);
   #define TP_MASK_INT     ts_mask_int();
   #define TP_UNMASK_INT   ts_unmask_int();
#else
   #define TP_MASK_INT     EINT_Mask(TP.eint_chan)
   #define TP_UNMASK_INT   EINT_UnMask(TP.eint_chan)
#endif

TouchPanelBufferStruct    touch_panel_data_buffer;
kal_bool    touch_panel_state = (kal_bool)touch_down_level; /*touch panel inq level*/


kal_bool send_touch_ilm=KAL_TRUE;
TouchPanelCoordStruct tp_stroke_pre;
#if defined(DRV_ADC_TOUCH_SCREEN)
static kal_uint16 TP_Stroke_Up_Count = 0;
#endif //#if defined(DRV_ADC_TOUCH_SCREEN)
#if !defined(__TOUCH_PANEL_CAPACITY__) && !defined(__TOUCH_PANEL_MULTITOUCH__)
static Touch_Panel_Event_enum tp_decode_state=TP_UNKNOWN_EVENT;/*get event state*/
#endif //#if !defined(__TOUCH_PANEL_CAPACITY__)

/*GPT timer handle*/
kal_uint32   touch_panel_handle=0;  /*gpt handle*/
kal_uint32   touch_panel_repeat_handle=0;

kal_int32 TP_SCREEN_X_MILLIMETER;
kal_int32 TP_SCREEN_Y_MILLIMETER;
/*Screen ADC Value*/
kal_int32 TP_ADC_X_START=230;
kal_int32 TP_ADC_X_END=3867;
kal_int32 TP_ADC_Y_START=287;
kal_int32 TP_ADC_Y_END=3853;
kal_int32 TP_SCREEN_X_START=0;
kal_int32 TP_SCREEN_X_END=176;
kal_int32 TP_SCREEN_Y_START=0;
kal_int32 TP_SCREEN_Y_END=220;

#if defined(DRV_TOUCH_PANEL_CUSTOMER_PARAMETER)
extern kal_uint32   TS_DEBOUNCE_TIME; //already declare in dcl_hts.c
kal_uint32   TP_CALI_CHECK_OFFSET;
kal_uint32   TP_MIN_PEN_MOVE_OFFSET;
kal_uint32   TP_HAND_WRITING_MAX_OFFSET;
kal_uint32   TP_NONHAND_WRITING_MAX_OFFSET;
kal_uint32   TP_MAX_STROKE_MOVE_OFFSET;
kal_uint32   TP_PRESSURE_THRESHOLD_HIGH;
kal_uint32   TP_PRESSURE_THRESHOLD_LOW = 1; //don't care about pressure value low
#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
kal_uint32   TP_MULTIPLE_POINT_SELECTION;
#endif //#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
#if defined(__DRV_TP_DISCARD_SHIFTING__)
kal_uint32   TP_PRESSURE_CHECK_BOUNDARY;
kal_uint32   TP_PRESSURE_SHIFTING_BOUNDARY;
#endif //#if defined(__DRV_TP_DISCARD_SHIFTING__)
#endif //#if defined(DRV_TOUCH_PANEL_CUSTOMER_PARAMETER)
kal_uint32   TP_FILTER_THRESHOLD;
static kal_uint16 TP_BORDER_PASS_CRITERION;
static kal_uint16 TP_BORDER_RANGE;
static kal_uint16 TP_NON_BORDER_PASS_CRITERION;
static kal_uint16 TP_JITTER_CIRCUIT_INTERNAL;
static kal_uint16 TP_DUMP_SCREEN = 0;

/*Calibration*/
#define TOUCH_CALIBRATION_POINT_NUM 3
TouchPanelCaliStruct TPCali;  /*Calibration offset and slope*/
static TouchPanelCoordStruct cali_point[TOUCH_CALIBRATION_POINT_NUM];
static TouchPanelCoordStruct cali_point_adc[TOUCH_CALIBRATION_POINT_NUM];
Touch_Panel_Calibration_Mode_enum tp_cali_mode = TP_FINISH_CALIBRATION_MODE;
static kal_bool tp_eint_mask = KAL_FALSE;

extern TouchPanel_customize_function_struct /*lint -e(526)*/*tp_GetFunc(void);
TouchPanel_customize_function_struct *tp_fun_ptr;
Touch_Panel_Dual_Calibration_Mode_enum tp_dual_cali_mode;
TouchPanelDataStruct TP;

#if defined(__TOUCH_PANEL_MULTITOUCH__)
extern void tp_multiple_start_dual_cali_(void);
extern void tp_multiple_stop_dual_cali_(void);
extern void tp_multiple_init(TouchPanel_custom_data_struct *tp_data);
kal_bool TP_DUAL=KAL_TRUE;
extern kal_bool tp_multiple_touch_down_get_2nd_point(TouchPanelMultipleEventStruct *tp_event);
extern kal_bool tp_multiple_touch_cb_get_2nd_point(TouchPanelMultipleEventStruct *tp_event);
extern void tp_multiple_touch_save_calibration(void);
extern kal_bool tp_multiple_dual_cali_pass(Touch_Panel_Dual_Calibration_Mode_enum mode);
static kal_bool touch_panel_dual_peek_event(TouchPanelMultipleEventStruct *touch_data);
kal_bool touch_panel_dual_get_event(TouchPanelMultipleEventStruct *touch_data);
static kal_bool touch_panel_dual_event_cb(TouchPanelMultipleEventStruct* tp_event);
#endif //#if defined(__TOUCH_PANEL_MULTITOUCH__)

#if defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)
static kal_uint16 TP_ASSERT_STATUS_FUNC(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 count);
static kal_uint16 TP_PEN_DOWN_STATUS_FUNC(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 count);
//static kal_uint16 CTP_PEN_UP_STATUS_FUNC(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 count);
static kal_uint16 TP_PEN_MOVE_STATUS_FUNC(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 count);
//static kal_uint16 CTP_PEN_LONGTAP_STATUS_FUNC(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 count);
//static kal_uint16 CTP_PEN_REPEAT_STATUS_FUNC(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 count);
//static kal_uint16 CTP_PEN_ABORT_STATUS_FUNC(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 count);
//static kal_uint16 CTP_TP_UNKNOWN_EVENT_STATUS_FUNC(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 count);
static kal_uint16 TP_STROKE_MOVE_STATUS_FUNC(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 count);
//static kal_uint16 CTP_STROKE_STATICAL_STATUS_FUNC(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 count);
static kal_uint16 TP_STROKE_HOLD_STATUS_FUNC(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 count);
static kal_uint16 TP_PEN_LONGTAP_HOLD_STATUS_FUNC(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 count);
static kal_uint16 TP_PEN_REPEAT_HOLD_STATUS_FUNC(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 count);
static kal_uint16 TP_STROKE_DOWN_STATUS_FUNC(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 count);
//static kal_uint16 CTP_STROKE_LONGTAP_STATUS_FUNC(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 count);
//static kal_uint16 CTP_STROKE_UP_STATUS_FUNC(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 count);
const CTP_FUNC	TP_STATUS_FUNC[] =  
{
	TP_PEN_DOWN_STATUS_FUNC,    /*0*/  
	TP_ASSERT_STATUS_FUNC, //CTP_PEN_UP_STATUS_FUNC,      /*1*/
	TP_PEN_MOVE_STATUS_FUNC,    /*2*/
	TP_PEN_MOVE_STATUS_FUNC, //currently same as CTP_PEN_LONGTAP_STATUS_FUNC, /*3*/     
	TP_PEN_MOVE_STATUS_FUNC, //currently same as CTP_PEN_REPEAT_STATUS_FUNC,  /*4*/ 
	TP_ASSERT_STATUS_FUNC, //CTP_PEN_ABORT_STATUS_FUNC,   /*5*/ 
	TP_ASSERT_STATUS_FUNC, //CTP_TP_UNKNOWN_EVENT_STATUS_FUNC,/*6*/
	TP_STROKE_MOVE_STATUS_FUNC,     /*7*/
	TP_STROKE_MOVE_STATUS_FUNC, //currently same as CTP_STROKE_STATICAL_STATUS_FUNC, /*8*/
	TP_STROKE_HOLD_STATUS_FUNC, /*9*/
	TP_PEN_LONGTAP_HOLD_STATUS_FUNC, /*10*/
	TP_PEN_REPEAT_HOLD_STATUS_FUNC,  /*11*/ 
	TP_STROKE_DOWN_STATUS_FUNC, /*12*/
	TP_STROKE_MOVE_STATUS_FUNC, //currently same as CTP_STROKE_LONGTAP_STATUS_FUNC,   /*13*/
	TP_ASSERT_STATUS_FUNC, //CTP_STROKE_UP_STATUS_FUNC/*14*/
};
static kal_uint32 tp_state_count[TP_SUPPORT_POINTS];
static kal_int16 tp_accum_sh_x_diff[TP_SUPPORT_POINTS], tp_accum_sh_y_diff[TP_SUPPORT_POINTS];
static kal_int16 tp_accum_plh_x_diff[TP_SUPPORT_POINTS], tp_accum_plh_y_diff[TP_SUPPORT_POINTS];
static kal_int16 tp_accum_prh_x_diff[TP_SUPPORT_POINTS], tp_accum_prh_y_diff[TP_SUPPORT_POINTS];
static kal_uint32 tp_state_start_tick[TP_SUPPORT_POINTS];

static void touch_panel_multiple_touch_stop_timer(void);
static void touch_panel_multiple_touch_set_timer(kal_bool higher_sampling_rate);
static kal_bool touch_panel_multiple_touch_check_event_valid(TouchPanelMultipleEventStruct *tp_event);
static void touch_panel_multiple_touch_data_push(TouchPanelMultipleEventStruct *push_event);
static kal_uint16 touch_panel_multiple_touch_state_machine(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 pre_event, kal_uint16 count);
static void touch_panel_multiple_touch_event_handler(TouchPanelMultipleEventStruct *tp_event, TouchPanelMultipleEventStruct *last_tp_event);
static void  touch_panel_multiple_touch_event_cb(void *parameter);
static void touch_panel_multipel_touch_retrieve_event(TouchPanelMultipleEventStruct *tp_event, kal_uint16 *index, kal_bool increase_index);
#endif //#if defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)

#if defined(__TOUCH_PANEL_CAPACITY__)
TouchPanelMultipleEventStruct CTP_g_event;
extern CTP_customize_function_struct /*lint -e(526)*/*ctp_GetFunc(void);
static void touch_panel_capacitive_HISR(void);
static kal_bool touch_panel_capacitive_get_event(TouchPanelMultipleEventStruct *touch_data);
static kal_bool touch_panel_capacitive_peek_event(TouchPanelMultipleEventStruct *touch_data);
static kal_bool touch_panel_capacitive_to_coordinate(TouchPanelMultipleEventStruct *tp_event);
static Touch_Panel_PenState_enum touch_panel_capacitive_get_data(TouchPanelMultipleEventStruct *tp_event);
static kal_bool touch_panel_capacitive_power_state(ctp_device_mode_enum mode);
static CTP_customize_function_struct *ctp_fun_ptr;
#endif //#if defined(__TOUCH_PANEL_CAPACITY__)

kal_bool Touch_Panel_first_valid = KAL_FALSE; //Speed up the sampling rate before send first valid event to MMI.
extern void SLA_CustomLogging(kal_char *customJob, kal_uint32 saAction);

/*
  When share pin design, we share tp serial pins with other interface (Ex. B2PSI)
  To protect the communication of each other, we may use SaveIRQMask and RestoreIRQMask
  But this may cause over 60qbit problem
  To solve this, we move TP serial communication to HISR, and do NOT add protection 
  HISR has higher priority than Task and is FIFS design. 
  Unless someone break the protection via LISR (Ex. Call PMIC function in LISR)
  Or we can execute TP serial function without protection
*/
#if defined(__DRV_B2SPI_SHARE_PIN__)
//#define __READ_TP_DATA_IN_HISR__
#if !defined(__READ_TP_DATA_IN_HISR__)
#define __READ_TP_DATA_IN_HISR__
#endif // #if !defined(__READ_TP_DATA_IN_HISR__)
#endif // #if defined(__DRV_B2SPI_SHARE_PIN__)

/*
  SIM(6302) controler interface and TP serial interface share pin design
  For share pin design we read TP data in HISR to avoid race condition
*/
#if defined(__DRV_SIM_TP_SHARE_PIN__)
#define __READ_TP_DATA_IN_HISR__
#endif // #if defined(__DRV_SIM_TP_SHARE_PIN__)

#if defined(__MTK_INTERNAL__) && !defined(LOW_COST_SUPPORT) && !defined(__MAUI_BASIC__) && defined(__DRV_DBG_MEMORY_TRACE_SUPPORT__) && defined(__DRV_TP_MEMORY_TRACE__)
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
#endif //#if defined(__DRV_TP_MEMORY_TRACE__)

#if defined(__READ_TP_DATA_IN_HISR__)
kal_uint16  gX, gY;
//only extend RTP controler need call the following intructions
#ifndef DRV_TP_SLIM
kal_uint32 touch_panel_irq_en_handle;
//kal_bool touch_panel_irq_en_performed = KAL_TRUE;
void touch_panel_irq_en_cb(void *parameter)
{
    if ( ((kal_uint32)parameter) == (kal_uint32)KAL_TRUE)
    {
		tp_fun_ptr->tp_irq_enable(KAL_TRUE);
    }
    else
    {
		tp_fun_ptr->tp_irq_enable(KAL_FALSE);
	}
	//touch_panel_irq_en_performed = KAL_TRUE;
	
}
#endif
#ifdef TOUCH_PANEL_PRESSURE
kal_bool gPressureCheck = KAL_FALSE;
#endif // #ifdef TOUCH_PANEL_PRESSURE
kal_uint16 gPressure = 0;
#endif // #if defined(__READ_TP_DATA_IN_HISR__)


void tp_get_buf_roomleft_(kal_uint16* pleft)
{
    if ( touch_panel_data_buffer.touch_buffer_rindex <= touch_panel_data_buffer.touch_buffer_windex ) 
    {
    *pleft = TOUCH_PANEL_BUFFER_SIZE - touch_panel_data_buffer.touch_buffer_windex + touch_panel_data_buffer.touch_buffer_rindex - 1;
    }
    else
    {
    *pleft = touch_panel_data_buffer.touch_buffer_rindex - touch_panel_data_buffer.touch_buffer_windex - 1;
    }
}
void tp_get_buf_avail_(kal_uint16* pleft)
{
    if ( touch_panel_data_buffer.touch_buffer_windex >= touch_panel_data_buffer.touch_buffer_rindex ) 
    {
      *pleft =touch_panel_data_buffer.touch_buffer_windex - touch_panel_data_buffer.touch_buffer_rindex;
    }
    else
    {
    	*pleft = TOUCH_PANEL_BUFFER_SIZE - touch_panel_data_buffer.touch_buffer_rindex + touch_panel_data_buffer.touch_buffer_windex;
    }
}

void touhc_push_data_to_buffer(kal_uint8 _data, kal_uint8 _state) 
{
    kal_uint16 room=0;
   tp_get_buf_roomleft(room);
   ASSERT(room!=0);
   touch_panel_data_buffer.touch_panel_data[touch_panel_data_buffer.touch_buffer_windex]= _data;
   touch_panel_data_buffer.touch_buffer_windex++;
   touch_panel_data_buffer.touch_buffer_windex &= (TOUCH_PANEL_BUFFER_SIZE-1);
   TP.touch_panel_event_cb(TP.cb_para,(Touch_Panel_Event_enum)_state);
}

void touch_pop_data_from_buffer_(kal_uint8*pdata) 
{
      if(touch_panel_data_buffer.touch_buffer_rindex==touch_panel_data_buffer.touch_buffer_windex)
      ASSERT(0);
   *pdata = touch_panel_data_buffer.touch_panel_data[touch_panel_data_buffer.touch_buffer_rindex];
   touch_panel_data_buffer.touch_buffer_rindex++;
   touch_panel_data_buffer.touch_buffer_rindex &= (TOUCH_PANEL_BUFFER_SIZE-1);
}

void touch_peek_data_from_buffer(kal_uint8*_ptr, kal_uint8 _num)
{
     kal_uint8 _index;
   kal_uint16 _tmp=0;
   if(touch_panel_data_buffer.touch_buffer_rindex==touch_panel_data_buffer.touch_buffer_windex)
      ASSERT(0);
   _tmp=touch_panel_data_buffer.touch_buffer_rindex;
   for(_index=0; _index<_num; _index++)
   {
      *(_ptr+_index) = touch_panel_data_buffer.touch_panel_data[_tmp];
     _tmp++;
     _tmp&= (TOUCH_PANEL_BUFFER_SIZE-1);
   }
}
void touch_flush_data_buffer()
{
#if defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)
    touch_panel_data_buffer.touch_buffer_rindex=0;
    touch_panel_data_buffer.touch_buffer_windex=0;
    touch_panel_data_buffer.touch_buffer_last_rindex=0;
    touch_panel_data_buffer.touch_buffer_last_windex=0;
    touch_panel_data_buffer.touch_panel_data[0]=0;
#else
    touch_panel_data_buffer.touch_buffer_rindex=0;
    touch_panel_data_buffer.touch_buffer_windex=0;
#endif
   
}


#if defined(DRV_MISC_CACHE_REGION_SUPPORT)
  // If cache is supported, put GPT data into cahched region
  #pragma arm section rwdata, zidata
#endif // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)

/*************************************************************************
* FUNCTION
*	touch_panel_tuning
*
* DESCRIPTION
*	This function is to calculate slope and offset.
*
* PARAMETERS
*  coord1: coordinate of calibration point 1
*  coord2: coordinate of calibration point 2
*  adc1:   ADC of calibration point 1
*  adc2:   ADC of calibration point 1
*  slope:  slope of calibration
*  offset: offset of calibration
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void touch_panel_tuning(kal_int16 coord1, kal_uint16 adc1,
                        kal_int16 coord2, kal_uint16 adc2,
                        double *slope,     double *offset)
{
   *slope=((double)(coord2-coord1)/((double)(adc2-adc1)));
   *offset=(double)coord1-(*slope)*(double)adc1;      
}
/*************************************************************************
* FUNCTION
*	touch_panel_flush
*
* DESCRIPTION
*	This function is to flush all data in ring buffer.
*
* PARAMETERS
*  None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/   
void touch_panel_flush_(void)
{
   drv_trace0(TRACE_GROUP_10, TP_FLUSH);
   
   IRQMask(IRQ_GPT_CODE);
   /* only mask eint when it's unmasked. */
   if (tp_eint_mask == KAL_FALSE)
   TP_MASK_INT;
   TP_DBG(__LINE__, ust_get_current_time(), touch_panel_data_buffer.touch_buffer_rindex, touch_panel_data_buffer.touch_buffer_windex);
   touch_flush_data_buffer();
   /*reset decode state*/
#if !defined(__TOUCH_PANEL_CAPACITY__) && !defined(__TOUCH_PANEL_MULTITOUCH__)
   tp_decode_state=TP_UNKNOWN_EVENT;
#endif//#if !defined(__TOUCH_PANEL_CAPACITY__)
#if defined(DRV_TOUCH_PANEL_PAIR_GUARANTEE)
   TP.buffer_push_stat = TP_UNKNOWN_EVENT;
#endif //#if defined(DRV_TOUCH_PANEL_PAIR_GUARANTEE)
   /*recover from buffer full*/
   TP.is_buff_full=KAL_FALSE;
   Touch_Panel_first_valid = KAL_FALSE;
   //GPTI_StopItem(touch_panel_handle);
   DclSGPT_Control(touch_panel_handle,SGPT_CMD_STOP,0);
   //GPTI_StopItem(touch_panel_repeat_handle);
   DclSGPT_Control(touch_panel_repeat_handle,SGPT_CMD_STOP,0);
   TP.skip_unrelease_state=KAL_TRUE;
   if (tp_eint_mask == KAL_FALSE)
   TP_UNMASK_INT;
   IRQUnmask(IRQ_GPT_CODE);
   
}
/*************************************************************************
* FUNCTION
*	touch_panel_flush
*
* DESCRIPTION
*	This function is to reset touch panel driver. 
*
* PARAMETERS
*  skip_unrelease_enable: skip the first unrelease events or not.
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/  
void touch_panel_reset_(kal_bool skip_unrelease_enable)
{
#if defined(DRV_ADC_TOUCH_SCREEN) && (defined(TOUCH_PANEL_SUPPORT) || defined(HAND_WRITING))
   HTS_CTRL_DATA_T tp_state;		// Read back value of TP state
   kal_bool need_detect_pen_down;		// After buffer full scenario, we need to detect pen down and send another pen down event.
#endif
   kal_uint32 savedMask;
	
	drv_trace0(TRACE_GROUP_10, TP_RESET);
	
   IRQMask(IRQ_GPT_CODE);
   TP_MASK_INT;
   /*stop calibration*/
   touch_panel_stop_cali_();
   /*flush ring buffer*/   
   TP_DBG(__LINE__, ust_get_current_time(), touch_panel_data_buffer.touch_buffer_rindex, touch_panel_data_buffer.touch_buffer_windex);
   touch_flush_data_buffer();
   /*reset decode state*/
#if !defined(__TOUCH_PANEL_CAPACITY__) && !defined(__TOUCH_PANEL_MULTITOUCH__)
   tp_decode_state=TP_UNKNOWN_EVENT;
#endif//#if !defined(__TOUCH_PANEL_CAPACITY__)
#if defined(DRV_TOUCH_PANEL_PAIR_GUARANTEE)
   TP.buffer_push_stat = TP_UNKNOWN_EVENT;
#endif //#if defined(DRV_TOUCH_PANEL_PAIR_GUARANTEE)
   /*configure default pen/move offset*/
   //touch_panel_conf_move_offset(TP_MIN_PEN_MOVE_OFFSET, TP_MAX_STROKE_MOVE_OFFSET, 10);
   /*buff full flag*/
#if defined(DRV_ADC_TOUCH_SCREEN) && (defined(TOUCH_PANEL_SUPPORT) || defined(HAND_WRITING))
   need_detect_pen_down = TP.is_buff_full;
#endif
   TP.is_buff_full=KAL_FALSE;
   TP.ext_enable=KAL_FALSE;
   Touch_Panel_first_valid = KAL_FALSE;
   /*skip the first unrelease events or not*/
   TP.skip_unrelease_enable=skip_unrelease_enable;
   if(TP.skip_unrelease_enable)
   {
      TP.skip_unrelease_state=KAL_TRUE;
      #ifdef TOUCH_PANEL_DEBUG
      dbg_printWithTime("reset and skip");
      #endif
   }   
   else
   {
      TP.skip_unrelease_state=KAL_FALSE;   
      #ifdef TOUCH_PANEL_DEBUG
      dbg_printWithTime("reset but not skip");
      #endif
   }   
   /*stop polling*/
   // GPTI_StopItem(touch_panel_handle);
   DclSGPT_Control(touch_panel_handle,SGPT_CMD_STOP,0);
   //   GPTI_StopItem(touch_panel_repeat_handle);
   DclSGPT_Control(touch_panel_repeat_handle,SGPT_CMD_STOP,0);
   savedMask = SaveAndSetIRQMask();
   if (tp_eint_mask == KAL_FALSE)//toy add for insure touch_panel_enable(False) won't destory by tp_reset.
   TP_UNMASK_INT;                //it must wait touch_panel_enable(true) to unmask TP IRQ.
   RestoreIRQMask(savedMask);   
   IRQUnmask(IRQ_GPT_CODE);
  
#if defined(DRV_ADC_TOUCH_SCREEN) && (defined(TOUCH_PANEL_SUPPORT) || defined(HAND_WRITING))
// for solve flush under buffer full but pen still down.
   if(need_detect_pen_down)
   {
#if !defined(__TOUCH_PANEL_CAPACITY__)
      DclHTS_Control(TP.hts_handle,HTS_CMD_GET_TP_LEVEL,&tp_state);
      if (tp_state.rTSCtrlTL.fgIsUP==touch_down_level)/*low*/
#endif //#if defined(__TOUCH_PANEL_CAPACITY__)
      {
         touch_panel_state=(kal_bool)touch_down_level;
         TP.state=DOWN;	
         TP.tp_down_cb(NULL);
         /* touch screen pressed. */
         #ifdef TOUCH_PANEL_DEBUG
         dbg_printWithTime("After flush, resend touch down\r\n");            
         #endif
         drv_trace0(TRACE_GROUP_4, TP_HISR_DOWN);
    	
      }
   }
#endif   
}
/*************************************************************************
* FUNCTION
*	touch_panel_start_cali
*
* DESCRIPTION
*	This function is to do coordinate calibration. 
*
* PARAMETERS
*  point: coordiante of calibration points
*  num:   number of calibration points
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void touch_panel_start_cali_(TouchPanelCoordStruct *point, kal_uint16 num)
{
   #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #else
   kal_uint32 i;
   for(i=0;i<num;i++)
   {
      cali_point[i].x=point[i].x;   
      cali_point[i].y=point[i].y;
   }      
   #endif
   if( (tp_cali_mode < TP_DUAL_CALIBRATION_MODE) || (tp_cali_mode == TP_FINISH_CALIBRATION_MODE) )
   	tp_cali_mode = TP_SINGLE_CALIBRATION_MODE_STEP1;
}
/*************************************************************************
* FUNCTION
*	touch_panel_stop_cali
*
* DESCRIPTION
*	This function is to stop coordinate calibration.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void touch_panel_stop_cali_(void)
{
   if(tp_cali_mode < TP_DUAL_CALIBRATION_MODE)
   	tp_cali_mode = TP_FINISH_CALIBRATION_MODE;
   cali_point[0].x=0;   
   cali_point[0].y=0;
   cali_point[1].x=0;
   cali_point[1].y=0;      
}

void touch_panel_start_dual_cali_(void)
{
#if defined(__TOUCH_PANEL_MULTITOUCH__)
	tp_multiple_start_dual_cali_();
#endif //#if defined(__TOUCH_PANEL_MULTITOUCH__)
}
void touch_panel_stop_dual_cali_(void)
{
#if defined(__TOUCH_PANEL_MULTITOUCH__)
	tp_multiple_stop_dual_cali_();
#endif //#if defined(__TOUCH_PANEL_MULTITOUCH__)
}

/*************************************************************************
* FUNCTION
*	touch_panel_set_cali
*
* DESCRIPTION
*	This function is to set coordinate calibration.
*
* PARAMETERS
*	cali: calibration data
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
/*MMI configures calibration accodring to the value in the NVRAM*/
void touch_panel_set_cali_(TouchPanelCaliStruct cali)
{
   
   TPCali.x_slope= cali.x_slope;
   TPCali.x_offset= cali.x_offset;
   TPCali.y_slope= cali.y_slope;
   TPCali.y_offset= cali.y_offset;
}
/*************************************************************************
* FUNCTION
*	touch_panel_read_cali
*
* DESCRIPTION
*	This function is to read coordinate calibration.
*
* PARAMETERS
*	cali: the pointer to read calibraion data
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
/*MMI reads calibration after receiving MSG_ID_TP_CALI_DONE*/
/*and stores it in NVRAM*/
void touch_panel_read_cali_(TouchPanelCaliStruct *cali)
{
   cali->x_slope =TPCali.x_slope;  
   cali->x_offset=TPCali.x_offset;
   cali->y_slope =TPCali.y_slope;  
   cali->y_offset=TPCali.y_offset;
}  
   

/*************************************************************************
* FUNCTION
*	touch_panel_up_hdr
*
* DESCRIPTION
*	This function is to handle up event.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void touch_panel_up_hdr(DCL_EVENT event)
{
     TP_SINGLE_EVENT_T RTPEvent;
   /*check if the down point is reasonable*/
   if(TP.wait_next_down==KAL_TRUE)
      return;
      
      
	drv_trace0(TRACE_GROUP_10, TP_UP_HDR);
      
   /*reset temp coordinate*/
   TP.temp.x=0;
   TP.temp.y=0;
   RTPEvent.x = TP.pre.x;
   RTPEvent.y = TP.pre.y;
   RTPEvent.z = 0;
 
   DclSGPT_Control(touch_panel_handle,SGPT_CMD_STOP,0);
   DclSGPT_Control(touch_panel_repeat_handle,SGPT_CMD_STOP,0); 
   if(TP.skip_unrelease_state==KAL_FALSE)
   {   
	   if(TP.area==NON_HAND_WRITING)
	   {    
	        RTPEvent.event = PEN_UP;
	   }   
	   else
	   {      
	       RTPEvent.event = STROKE_UP;
	   }   
            tp_data_push(&RTPEvent);
   }
   else
    {
        /*TP.skip_unrelease_state==KAL_TRUE*/
      TP.skip_unrelease_state=KAL_FALSE;   
      Touch_Panel_first_valid = KAL_FALSE;
   }
}   

Touch_Panel_Area_enum touch_panel_area_check(kal_uint16 x, kal_uint16 y)
{
   kal_uint32 i=0;
   
   if(TP.ext_enable==KAL_FALSE)/*not extend handwriting area*/
   {
      for(i=0;i<TP.hand_num;i++)
      {
         if((x>=TP.handarea[i].min.x)&&(y>=TP.handarea[i].min.y)&&
         (x<=TP.handarea[i].max.x)&&(y<=TP.handarea[i].max.y))
         {
            /*check if ext_handwriting exists?*/
            if((TP.ext_handarea.min.x!=TP.ext_handarea.max.x)&&
               (TP.ext_handarea.min.y!=TP.ext_handarea.max.y))
            {
               TP.ext_enable=KAL_TRUE;/*use extended handwriting area*/
            }   
            return HAND_WRITING;
         }
      }      
   }         
   else/*extend handwriting area*/
   {
      if((x>=TP.ext_handarea.min.x)&&(y>=TP.ext_handarea.min.y)&&
         (x<=TP.ext_handarea.max.x)&&(y<=TP.ext_handarea.max.y))
      {
         return HAND_WRITING;         
      }
      else/*non-handwriting*/
      {
         return NON_HAND_WRITING;                  
      }
   }
   return NON_HAND_WRITING;
}

/*************************************************************************
* FUNCTION
*	touch_panel_down_hdr
*
* DESCRIPTION
*	This function is to handle down event.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void touch_panel_down_hdr(DCL_EVENT event)
{
   kal_bool valid=KAL_FALSE;
    TP_SINGLE_EVENT_T RTPEvent;
#if defined(DRV_ADC_TOUCH_SCREEN)
	// Check if we lost up intr
    if (tp_up_intr_lost_flag == KAL_TRUE)
    {
		DclSGPT_Control(touch_panel_handle,SGPT_CMD_STOP,0);
		DclSGPT_Control(touch_panel_repeat_handle,SGPT_CMD_STOP,0);
		// Perform up handler first
		touch_panel_up_hdr(NULL);
		tp_up_intr_lost_flag = KAL_FALSE;
	}
#endif // #if defined(DRV_ADC_TOUCH_SCREEN)
   
   TP.skip_unrelease_state=KAL_FALSE;
   Touch_Panel_first_valid = KAL_FALSE;
   drv_trace0(TRACE_GROUP_10, TP_DOWN_HDR);
   
#if defined(__READ_TP_DATA_IN_HISR__)
	RTPEvent.x = gX;
       RTPEvent.y = gY;
#endif // #if defined(__READ_TP_DATA_IN_HISR__)

#if !defined(__READ_TP_DATA_IN_HISR__)
	// Non share pin design, read data from tp controller
   touch_panel_read_adc(&RTPEvent.x, &RTPEvent.y);
#endif // #if !defined(__READ_TP_DATA_IN_HISR__)
   
   touch_excute_cali( RTPEvent.x, RTPEvent.y);

#ifdef TOUCH_PANEL_PRESSURE
#if defined(__READ_TP_DATA_IN_HISR__)
     RTPEvent.z = gPressure;
	// Share pin, we just read the prev read flag
	if (KAL_FALSE == gPressureCheck)
#else
	// Non share pin, read tp pressure info
#ifndef DRV_TP_SLIM
   if (KAL_FALSE == tp_fun_ptr->tp_pressure_check())
#else
    if (KAL_FALSE == tp_pressure_check_value((kal_int32*)&RTPEvent.z))
#endif
#endif // #if defined(__READ_TP_DATA_IN_HISR__)
   {
   	
   	drv_trace0(TRACE_GROUP_10, TP_WAIT_NEXT_SET_TRUE);
      TP.wait_next_down=KAL_TRUE;
      return;
   }
#endif
   valid=touch_panel_adc_to_coordinate(&RTPEvent.x, & RTPEvent.y);/*tranlate*/            
   if(valid==KAL_TRUE)
   {
       TP.pre.x=RTPEvent.x; 
       TP.pre.y=RTPEvent.y;
      TP.begin.x=RTPEvent.x; 
      TP.begin.y=RTPEvent.y;
      TP.wait_next_down=KAL_FALSE;
   }
   else
   {
      /*use the previous down coordinate to prevent touch panel controller temp state*/
   	//x=TP.pre.x; 
   	//y=TP.pre.y;
   	drv_trace0(TRACE_GROUP_10, TP_WAIT_NEXT_TRUE);
   	TP.wait_next_down=KAL_TRUE;
   	return;
   }		
   TP.temp.x=0;
   TP.temp.y=0;
   
   TP.area = touch_panel_area_check(RTPEvent.x, RTPEvent.y);

   if(TP.area==HAND_WRITING)            
   {            
        RTPEvent.event = STROKE_DOWN;
       tp_data_push(&RTPEvent);
#if defined(DRV_ADC_TOUCH_SCREEN)
       TP_Stroke_Up_Count = 0;
#endif //#if defined(DRV_ADC_TOUCH_SCREEN)
    //  tp_data_pop(STROKE_DOWN, RTPEvent.x, RTPEvent.y);            
      touch_panel_stroke_hdr();
      touch_start_handwriting_longtap();      
   }
   else/*non-handwriting*/
   {            
    RTPEvent.event = PEN_DOWN;
       tp_data_push(&RTPEvent);
     // tp_data_pop(PEN_DOWN, RTPEvent.x, RTPEvent.y);            
      touch_panel_event_hdr();
      touch_start_longtap();
   }   
} 
/*************************************************************************
* FUNCTION
*	touch_panel_sendilm
*
* DESCRIPTION
*	This function is to send touch event indication to upper layer.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/  
/*send touch event indication to upper layer*/
void touch_panel_sendilm(void *para, Touch_Panel_Event_enum state)
{
   ilm_struct *tp_ilm;
   module_type owner = MOD_NIL;
   //kal_bool    btmp;
   
   
   if (send_touch_ilm)
   {
   	#ifdef TOUCH_PANEL_DEBUG
   		owner=MOD_SSDBG1;
   	#else
   		owner=MOD_MMI;
   	#endif
   	
      send_touch_ilm = KAL_FALSE;
      DRV_BuildPrimitive(tp_ilm,
                         MOD_TP_TASK,
                         owner,
                         MSG_ID_TP_EVENT_IND,
                         NULL);   
      //btmp = msg_send_ext_queue(tp_ilm);
      msg_send_ext_queue(tp_ilm);
   }   
}  
/*************************************************************************
* FUNCTION
*	touch_panel_conf_handwriting
*
* DESCRIPTION
*	This function is to configure handwriting area.
*
* PARAMETERS
*	area: handwriting area
*  n: number of handwriting areas
*  ext_area: extended handwriting area
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/ 
void touch_panel_conf_handwriting_(TouchPanelHandAreaStruct *area, kal_uint16 n, 
                              TouchPanelHandAreaStruct  *ext_area)
{
   kal_uint32 i;
      
   /*n handwriting area*/       
   for(i=0;i<n;i++)
   {      
      TP.handarea[i]=*(area+i);
   }   
   /*extended handwriting area*/
   TP.ext_handarea=*ext_area;
   TP.hand_num=n;
}                                     
/*************************************************************************
* FUNCTION
*	touch_panel_reset_handwriting
*
* DESCRIPTION
*	This function is to reset handwriting area as normal.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/ 
void touch_panel_reset_handwriting_(void)                               
{
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();
   /*MMI will reset handwriting area*/
   TP.ext_enable=KAL_FALSE;
   RestoreIRQMask(savedMask);
}                     
/*************************************************************************
* FUNCTION
*	touch_panle_conf_sample_period
*
* DESCRIPTION
*	This function is to configure sample period in handwriting and non-handwriting area.
*
* PARAMETERS
*	low:  sample period in non-handwriting area
*  high: sample period in handwriting area
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/                       
/*configure sample period in non-handwriting and handwriting area*/
void touch_panle_conf_sample_period_(kal_uint32 low, kal_uint32 high)
{
	drv_trace2(TRACE_GROUP_10, TP_CONF_SAMPLE_PERIOD, low, high);
   TP.low_sample_period=low;
   TP.high_sample_period=high;
}   


void Touch_Panel_Ctrl_Param(DCL_CTRL_CUSTOM_PARAM_T param)
{
	TouchPanel_EM_custom_data_struct* pData = param.pEmData;
	TouchPanel_custom_data_struct *tp_data;
#if defined(TOUCH_PANEL_INTERNAL)
	DCL_HANDLE handle;  
	HTS_CTRL_DATA_T data;
#endif

	tp_fun_ptr=tp_GetFunc();
	tp_data = tp_fun_ptr->tp_get_data();   

	ASSERT(pData != NULL);
	if(param.type == TP_PARAM_GET)
	{
#if defined(DRV_TOUCH_PANEL_CUSTOMER_PARAMETER)
#if defined(TOUCH_PANEL_INTERNAL)
		handle = DclHTS_Open(TOUCH_PANEL_R,0);
		DclHTS_Control(handle,HTS_CMD_GET_DEBOUNCE_TIME, &data);
		pData->ts_debounce_time = data.rTSCtrlDebouncetime.u4DebounceTime/32;
		DclHTS_Control(handle,HTS_CMD_GET_SPL_NUM, &data);
		pData->reserve_parameter1 = data.rTSCtrlSPLNum.u4SPLNum;
#endif
		pData->hand_writing_max_offset = TP_HAND_WRITING_MAX_OFFSET;
		pData->max_stroke_move_offset = TP_MAX_STROKE_MOVE_OFFSET;
		pData->min_pen_move_offset = TP_MIN_PEN_MOVE_OFFSET; 
		pData->touch_panel_cali_check_offset = TP_CALI_CHECK_OFFSET;
		pData->nonhand_writing_max_offset = TP_NONHAND_WRITING_MAX_OFFSET;
#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
		pData->multiple_point_selection = TP_MULTIPLE_POINT_SELECTION;
#endif
#if defined(__DRV_TP_DISCARD_SHIFTING__)
		pData->pressure_check_boundary = TP_PRESSURE_CHECK_BOUNDARY;
		pData->pressure_shifting_boundary = TP_PRESSURE_SHIFTING_BOUNDARY;
#endif
#ifdef TOUCH_PANEL_PRESSURE
		pData->touch_pressure_threshold_high = TP_PRESSURE_THRESHOLD_HIGH;
		pData->touch_pressure_threshold_low = TP_PRESSURE_THRESHOLD_LOW;
#endif
#endif
		pData->border_pass_criterion = TP_BORDER_PASS_CRITERION;
		pData->border_range = TP_BORDER_RANGE;
		pData->non_border_pass_criterion = TP_NON_BORDER_PASS_CRITERION;
		pData->jitter_circuit_interval =  TP_JITTER_CIRCUIT_INTERNAL;
		pData->Dump_Screen =  TP_DUMP_SCREEN;
	}
	else if(param.type == TP_PARAM_SET)
	{
#if defined(DRV_TOUCH_PANEL_CUSTOMER_PARAMETER)
#if defined(TOUCH_PANEL_INTERNAL)
		handle = DclHTS_Open(TOUCH_PANEL_R,0);
		data.rTSCtrlDebouncetime.u4DebounceTime = (pData->ts_debounce_time)*32;
		DclHTS_Control(handle,HTS_CMD_SET_DEBOUNCE_TIME, &data);
		data.rTSCtrlSPLNum.u4SPLNum = pData->reserve_parameter1;
		DclHTS_Control(handle,HTS_CMD_SET_SPL_NUM, &data);
#endif
		TP_HAND_WRITING_MAX_OFFSET = pData->hand_writing_max_offset;
		TP_MAX_STROKE_MOVE_OFFSET =  pData->max_stroke_move_offset;
		TP_MIN_PEN_MOVE_OFFSET = pData->min_pen_move_offset;
		TP_NONHAND_WRITING_MAX_OFFSET =  pData->nonhand_writing_max_offset;
		TP_CALI_CHECK_OFFSET = pData->touch_panel_cali_check_offset;
		
#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
		TP_MULTIPLE_POINT_SELECTION = pData->multiple_point_selection;
#endif
#if defined(__DRV_TP_DISCARD_SHIFTING__)
		TP_PRESSURE_CHECK_BOUNDARY = pData->pressure_check_boundary;
		TP_PRESSURE_SHIFTING_BOUNDARY = pData->pressure_shifting_boundary;
#endif
		 
#ifdef TOUCH_PANEL_PRESSURE
		TP_PRESSURE_THRESHOLD_HIGH = pData->touch_pressure_threshold_high;
		TP_PRESSURE_THRESHOLD_LOW = pData->touch_pressure_threshold_low;
#endif
#endif
		TP_BORDER_PASS_CRITERION =  pData->border_pass_criterion;
		TP_BORDER_RANGE = pData->border_range ;
		TP_NON_BORDER_PASS_CRITERION =  pData->non_border_pass_criterion;
		TP_JITTER_CIRCUIT_INTERNAL = pData->jitter_circuit_interval;
		TP_DUMP_SCREEN = pData->Dump_Screen;
	}
	else if (param.type == TP_PARAM_RESET)
	{
#if defined(DRV_TOUCH_PANEL_CUSTOMER_PARAMETER)
#if defined(TRULY_HVGA_LCM)
		TP_CALI_CHECK_OFFSET = 12;
#else
		TP_CALI_CHECK_OFFSET = tp_data->touch_panel_cali_check_offset;
#endif
		TS_DEBOUNCE_TIME = tp_data->ts_debounce_time;
		TP_MIN_PEN_MOVE_OFFSET = tp_data->min_pen_move_offset;
		TP_HAND_WRITING_MAX_OFFSET = tp_data->hand_writing_max_offset;
		TP_NONHAND_WRITING_MAX_OFFSET = tp_data->nonhand_writing_max_offset;
		TP_MAX_STROKE_MOVE_OFFSET = tp_data->max_stroke_move_offset;
		TP_PRESSURE_THRESHOLD_HIGH = tp_data->touch_pressure_threshold_high;
		TP_PRESSURE_THRESHOLD_LOW = 10;
#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
		TP_MULTIPLE_POINT_SELECTION = tp_data->multiple_point_selection;
		TP_MULTIPLE_POINT_SELECTION = (TP_MULTIPLE_POINT_SELECTION < 3)?3:TP_MULTIPLE_POINT_SELECTION;
		TP_MULTIPLE_POINT_SELECTION = (TP_MULTIPLE_POINT_SELECTION > 32)?32:TP_MULTIPLE_POINT_SELECTION;	
#endif //#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
#if defined(__DRV_TP_DISCARD_SHIFTING__)
		TP_PRESSURE_CHECK_BOUNDARY = tp_data->pressure_check_boundary;
		TP_PRESSURE_SHIFTING_BOUNDARY = tp_data->pressure_shifting_boundary;
#endif //#if defined(__DRV_TP_DISCARD_SHIFTING__)
#endif //#if defined(DRV_TOUCH_PANEL_CUSTOMER_PARAMETER)

		TP_BORDER_PASS_CRITERION = 2000;
		TP_BORDER_RANGE = 5000;
		TP_NON_BORDER_PASS_CRITERION = 2000;
		TP_JITTER_CIRCUIT_INTERNAL = 15000;
		TP_DUMP_SCREEN = 0;
	}
	return;
}

void Touch_Panel_Ctrl_Param_Range(DCL_CTRL_CUSTOM_PARAM_RANGE_T param)
{
	TP_PARAM_RANGE* pData = param.pEmDataRange;
	pData->border_pass_criterion_min = 100;
	pData->border_pass_criterion_max = 10000;
	pData->border_range_min = 100;
	pData->border_range_max = 10000;
	pData->hand_writing_max_offset_min = 1;
	pData->hand_writing_max_offset_max = 300;
	
	pData->max_stroke_move_offset_min = 1;
	pData->max_stroke_move_offset_max = 300;
	pData->min_pen_move_offset_min = 1;
	pData->min_pen_move_offset_max = 300;
	pData->multiple_point_selection_min = 1;
	pData->multiple_point_selection_max = 10;
	
	pData->nonborder_pass_criterion_max = 10000;
	pData->nonborder_pass_criterion_min = 100;
	pData->nonhand_writing_max_offset_min = 1;
	pData->nonhand_writing_max_offset_max = 300;
	pData->pressure_check_boundary_min = 1;
	pData->pressure_check_boundary_max = 3000;
	
	pData->touch_panel_cali_check_offset_max = 20;
	pData->touch_panel_cali_check_offset_min = 1;
	pData->touch_pressure_threshold_high_min = 100;
	pData->touch_pressure_threshold_high_max = 20000;
	pData->ts_debounce_time_max = 50;
	pData->ts_debounce_time_min = 1;
	pData->jitter_circuit_interval_min = 5000;
	pData->jitter_circuit_interval_max = 20000;
	pData->pressure_shifting_boundary_min = 1;
	pData->pressure_shifting_boundary_max = 6000;
	pData->reserve_parameter1_min = 0;
	pData->reserve_parameter1_max = 0xFFFF;
	pData->reserve_parameter2_min = 0;
	pData->reserve_parameter2_max = 0xFFFF;
	pData->reserve_parameter3_min = 0;
	pData->reserve_parameter3_max = 0xFFFF;
	pData->Dump_Screen_max = 1;
	pData->Dump_Screen_min = 0;
}

void Touch_Panel_MicronMeter_To_Coord(DCL_CTRL_MICRONMETER_COORD_T* pparam)
{
	pparam->x_coord = pparam->x_micronmeter*(TP_SCREEN_X_END+1)/(TP_SCREEN_X_MILLIMETER*1000);
	pparam->y_coord = pparam->y_micronmeter*(TP_SCREEN_Y_END+1)/(TP_SCREEN_Y_MILLIMETER*1000);
}


void Touch_Panel_Pixel_To_MicronMeter(DCL_CTRL_MICRONMETER_COORD_T* pparam )
{
	pparam->x_micronmeter =  pparam->x_coord*TP_SCREEN_X_MILLIMETER*1000/(TP_SCREEN_X_END+1);
	pparam->y_micronmeter = pparam->y_coord*TP_SCREEN_Y_MILLIMETER*1000/(TP_SCREEN_Y_END+1);
}

/*************************************************************************
* FUNCTION
*	touch_panle_conf_timeout_period
*
* DESCRIPTION
*	This function is to configure period of long tap and repeat event.
*
* PARAMETERS
*	long tap: long tap event period
*  repeat:  repeat event period
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/                       
/*configure longtap and repeat period*/
void touch_panle_conf_timeout_period_(kal_uint32 longtap, 
                                     kal_uint32 repeat,
                                     kal_uint32 handwriting_longtap)
{
	drv_trace4(TRACE_GROUP_10, TP_CONF_TIMEOUT_PERIOD, longtap, repeat, handwriting_longtap, 0);
	
   TP.handwriting_longtap_cnt=handwriting_longtap;
   TP.longtap_cnt=longtap;
   TP.repeat_cnt=repeat;
}


/*************************************************************************
* FUNCTION
*	touch_panle_conf_timeout_period
*
* DESCRIPTION
*	This function is to configure period of long tap and repeat event.
*
* PARAMETERS
*	long tap: long tap event period
*  repeat:  repeat event period
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool touch_panle_pressure_shift_check(kal_uint32 p1, kal_uint32 p2)
{
#if defined(__DRV_TP_DISCARD_SHIFTING__)
   if ((p1 > (TP_PRESSURE_THRESHOLD_HIGH-TP_PRESSURE_CHECK_BOUNDARY)) || 
       (p2 > (TP_PRESSURE_THRESHOLD_HIGH-TP_PRESSURE_CHECK_BOUNDARY)) )
   {
      if( (p1>p2) && ((p1-p2)>TP_PRESSURE_SHIFTING_BOUNDARY))
         return KAL_TRUE;
      if( (p2>p1) && ((p2-p1)>TP_PRESSURE_SHIFTING_BOUNDARY))
         return KAL_TRUE;
   }
#endif //#if defined(__DRV_TP_DISCARD_SHIFTING__)
   return KAL_FALSE;
}

void touch_panel_set_timer(kal_uint32 handle, TP_EVENT_FUNC cb, kal_uint32 tick, void *vp)
{
	SGPT_CTRL_START_T start;
	start.pfCallback=(void(*)(void*))cb;
	start.vPara=vp;

	IRQMask(IRQ_GPT_CODE);
	if(handle == touch_panel_handle) //only event call back need to change the timeout
	{
		if((!kal_if_hisr()) && (!kal_if_lisr())) //TP task pen down
			start.u2Tick=0;
		else if(!Touch_Panel_first_valid) //not get first valid event and under GPT call back
			start.u2Tick=1;
		else
			start.u2Tick=tick;
	}
	else
		start.u2Tick=tick;
	DclSGPT_Control(handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
	IRQUnmask(IRQ_GPT_CODE);
}

/*************************************************************************
* FUNCTION
*	touch_panel_event_hdr
*
* DESCRIPTION
*	This function is to handle down event in non-handwriting area.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/ 
/*start timer in non-handwriting area*/
void touch_panel_event_hdr(void)
{
	if(TP.low_sample_period!=0)
	{
		touch_panel_set_timer(touch_panel_handle, (TP_EVENT_FUNC)touch_panel_event_cb, TP.low_sample_period, NULL);
	}                     
}  
/*************************************************************************
* FUNCTION
*	touch_start_longtap
*
* DESCRIPTION
*	This function is to long tap timer.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void touch_start_longtap(void)
{
	if(TP.longtap_cnt!=0)          
	{
		touch_panel_set_timer(touch_panel_repeat_handle, (TP_EVENT_FUNC)touch_panel_longtap_cb, TP.longtap_cnt, NULL);
		TP.longtap_state=KAL_TRUE;
	}   
}   
/*************************************************************************
* FUNCTION
*	touch_start_handwriting_longtap
*
* DESCRIPTION
*	This function is to start long tap timer in handwriting area.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void touch_start_handwriting_longtap(void)
{
	if(TP.handwriting_longtap_cnt!=0)          
	{
		TP.longtap_state=KAL_TRUE;
		touch_panel_set_timer(touch_panel_repeat_handle, (TP_EVENT_FUNC)touch_panel_longtap_cb, TP.handwriting_longtap_cnt, NULL);
	}
}
/*************************************************************************
* FUNCTION
*	touch_panel_stroke_hdr
*
* DESCRIPTION
*	This function is to handle down event in handwriting area.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void touch_panel_stroke_hdr(void)
{
	if(TP.high_sample_period!=0)
	{
		touch_panel_set_timer(touch_panel_handle, (TP_EVENT_FUNC)touch_panel_stroke_cb, TP.high_sample_period, NULL);
	}
}                              

#if !defined(__TOUCH_PANEL_CAPACITY__) && !defined(__TOUCH_PANEL_MULTITOUCH__)
kal_bool touch_panel_resistive_get_event(TouchPanelMultipleEventStruct *touch_data)
{
   kal_bool result;
   kal_uint8 hign_data=0, low_data=0;
   kal_int8 diff=0;
   kal_uint16 avail=0;
   kal_uint8 timestamp = 0;
   kal_uint8 itmp8 = 0;
   
   IRQMask(IRQ_GPT_CODE);
   /* only mask eint when it's unmasked. */
   if (tp_eint_mask == KAL_FALSE)
   TP_MASK_INT;   
   
   touch_data->model = 1;
   
   if(TP.is_buff_full==KAL_TRUE)
   {
      touch_data->points[0].event = PEN_ABORT;
      touch_data->points[0].x= 0;
      touch_data->points[0].y = 0;
      touch_data->points[0].z = 0;
      touch_data->time_stamp = 0;
      if (tp_eint_mask == KAL_FALSE)
         TP_UNMASK_INT;
      IRQUnmask(IRQ_GPT_CODE);
      return KAL_TRUE;
   }
   
   tp_get_buf_avail(avail); 
   TP_DBG(__LINE__, ust_get_current_time(), touch_panel_data_buffer.touch_buffer_rindex, touch_panel_data_buffer.touch_buffer_windex);
   if(touch_panel_data_buffer.touch_buffer_rindex != touch_panel_data_buffer.touch_buffer_windex)   	
   {            
      TP_DBG(__LINE__, ust_get_current_time(), touch_panel_data_buffer.touch_buffer_rindex, touch_panel_data_buffer.touch_buffer_windex);
      if(tp_decode_state==TP_UNKNOWN_EVENT)            
        {
            /*complete x and y*/
         touch_pop_data_from_buffer(itmp8);
            /*lint -e(64)*/
            touch_data->points[0].event = (Touch_Panel_Event_enum)itmp8;
         TP_DBG(__LINE__, ust_get_current_time(), touch_panel_data_buffer.touch_buffer_rindex, touch_panel_data_buffer.touch_buffer_windex);
         if(touch_data->points[0].event!=STROKE_UP)/*stroke end*/
         {
            touch_pop_data_from_buffer(hign_data);/*high*/
            touch_pop_data_from_buffer(low_data);/*low*/
            touch_data->points[0].x=(hign_data<<8);     
            touch_data->points[0].x|=low_data;     
            touch_pop_data_from_buffer(hign_data);/*high*/
            touch_pop_data_from_buffer(low_data);/*low*/
            touch_data->points[0].y=(hign_data<<8);               
            touch_data->points[0].y|=low_data;     
            TP_DBG(__LINE__, ust_get_current_time(), touch_panel_data_buffer.touch_buffer_rindex, touch_panel_data_buffer.touch_buffer_windex);

			// Extract timestamp
			if ( (touch_data->points[0].event == PEN_DOWN) || (touch_data->points[0].event == PEN_UP) ||(touch_data->points[0].event == PEN_MOVE) )
                {
				touch_pop_data_from_buffer(timestamp);
				 touch_data->time_stamp= timestamp << 24;
				touch_pop_data_from_buffer(timestamp);
				 touch_data->time_stamp |= timestamp<<16;
                        touch_pop_data_from_buffer(timestamp);
				 touch_data->time_stamp |= timestamp<<8;
                        touch_pop_data_from_buffer(timestamp);
				 touch_data->time_stamp |= timestamp;

		}
         }   
         else// if(touch_data->event == STROKE_UP) //because state already flush to TP_UNKNOWN_EVENT
         {
            touch_data->points[0].event=STROKE_UP;
            touch_data->points[0].x=tp_stroke_pre.x;//0;
            touch_data->points[0].y=tp_stroke_pre.y;//0;
            //tp_decode_state=TP_UNKNOWN_EVENT;
            tp_stroke_pre.x=0;
            tp_stroke_pre.y=0;            
         }                         
         if(touch_data->points[0].event==STROKE_DOWN)
         {
            tp_decode_state=STROKE_MOVE;
            tp_stroke_pre.x=touch_data->points[0].x;
            tp_stroke_pre.y=touch_data->points[0].y;
         }    
      }
      else if(tp_decode_state==STROKE_MOVE)    
      { 
         TP_DBG(__LINE__, ust_get_current_time(), touch_panel_data_buffer.touch_buffer_rindex, touch_panel_data_buffer.touch_buffer_windex);
            /*lint -e(64)*/
            touch_pop_data_from_buffer(diff);
         if((kal_uint8)diff==(kal_uint8)STROKE_UP) 
         {
            touch_data->points[0].event=STROKE_UP;
            touch_data->points[0].x=tp_stroke_pre.x;//0;
            touch_data->points[0].y=tp_stroke_pre.y;//0;
            tp_decode_state=TP_UNKNOWN_EVENT;
            tp_stroke_pre.x=0;
            tp_stroke_pre.y=0;
         }                         
         else if((kal_uint8)diff==(kal_uint8)STROKE_LONGTAP) 
         {
            //touch_pop_data_from_buffer(diff);
            touch_data->points[0].x=tp_stroke_pre.x;//0;
            touch_data->points[0].y=tp_stroke_pre.y;//0;
            touch_data->points[0].event=STROKE_LONGTAP;
         }   
         else/*delta x, delta y*/
         {     
#if defined(DRV_AUX_ADC_TP_MESSED_UP_WA)
	tp_get_buf_avail(avail); 
                if (avail < 1)
                {
		touch_data->points[0].event=PEN_ABORT;
		touch_data->points[0].x=0;
		touch_data->points[0].y=0;
		if (tp_eint_mask == KAL_FALSE)
			TP_UNMASK_INT;
		IRQUnmask(IRQ_GPT_CODE);
		return KAL_TRUE;
	}
#endif // #if defined(DRV_AUX_ADC_TP_MESSED_UP_WA)
            /*x*/    
            touch_data->points[0].x=(kal_int16)((kal_int16)tp_stroke_pre.x+(kal_int16)diff);
            tp_stroke_pre.x=touch_data->points[0].x;
            /*y*/
                /*lint -e(63)*/
                touch_pop_data_from_buffer(diff);
            touch_data->points[0].y=(kal_int16)((kal_int16)tp_stroke_pre.y+(kal_int16)diff);;
            tp_stroke_pre.y=touch_data->points[0].y;
            touch_data->points[0].event=STROKE_MOVE;
         }
      } 
      
         // event + (x,y)+timestamp+pressure
           touch_pop_data_from_buffer(hign_data);/*high*/
            touch_data->points[0].z = hign_data<<8;
            touch_pop_data_from_buffer(low_data);/*high*/
            touch_data->points[0].z |= low_data;
      drv_trace4(TRACE_GROUP_10, TP_GET_EVENT, touch_data->points[0].event, touch_data->points[0].x, touch_data->points[0].y, 0);
     result = KAL_TRUE;
   }
   else
   {
      send_touch_ilm = KAL_TRUE;
      result = KAL_FALSE;
   }      
   if (tp_eint_mask == KAL_FALSE)
   TP_UNMASK_INT;
   IRQUnmask(IRQ_GPT_CODE);
   TP_DBG(__LINE__, ust_get_current_time(), touch_panel_data_buffer.touch_buffer_rindex, touch_panel_data_buffer.touch_buffer_windex);
   return result;      
}
#endif //#if !defined(__TOUCH_PANEL_CAPACITY__) && !defined(__TOUCH_PANEL_MULTITOUCH__)

/*************************************************************************
* FUNCTION
*	touch_panel_get_event
*
* DESCRIPTION
*	This function is to get event from ring buffer.
*
* PARAMETERS
*	data: touch event
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
/*Get touch panel coord. value*/
kal_bool touch_panel_get_event_(TouchPanelMultipleEventStruct *touch_data)
{
#if defined(__TOUCH_PANEL_CAPACITY__)
	return touch_panel_capacitive_get_event(touch_data);
#elif defined(__TOUCH_PANEL_MULTITOUCH__)
	return touch_panel_dual_get_event(touch_data);
#else//#if defined(__TOUCH_PANEL_CAPACITY__)
	return touch_panel_resistive_get_event(touch_data);
#endif //#if defined(__TOUCH_PANEL_CAPACITY__)
}   
	
#if !defined(__TOUCH_PANEL_CAPACITY__) && !defined(__TOUCH_PANEL_MULTITOUCH__)	
kal_bool touch_panel_resistive_peek_event(TouchPanelMultipleEventStruct *touch_data)
{
   kal_bool result;
   //kal_uint8 hign_data=0, low_data=0;
   kal_uint8 peek_data[5];
   //kal_int8 diff;
   IRQMask(IRQ_GPT_CODE);
   /* only mask eint when it's unmasked. */
   if (tp_eint_mask == KAL_FALSE)
   TP_MASK_INT;   
   if (touch_panel_data_buffer.touch_buffer_rindex != touch_panel_data_buffer.touch_buffer_windex)
   {                  
      if(tp_decode_state==TP_UNKNOWN_EVENT)            
        {
            /*complete x and y*/
         touch_peek_data_from_buffer(peek_data,5);   
         touch_data->points[0].event= (Touch_Panel_Event_enum)peek_data[0];            
         if(peek_data[0]!= (kal_uint8)STROKE_UP)/*stroke end*/
         {
            touch_data->points[0].x=(peek_data[1]<<8);     
            touch_data->points[0].x|=peek_data[2];     
            touch_data->points[0].y=(peek_data[3]<<8);               
            touch_data->points[0].y|=peek_data[4];                       
         }            
      }
      else if(tp_decode_state==(kal_uint8)STROKE_MOVE)    
{
         touch_peek_data_from_buffer(peek_data,3);   
         if((kal_uint8)peek_data[0]==STROKE_UP) 
         {
            touch_data->points[0].event=STROKE_UP;
            touch_data->points[0].x=0;
            touch_data->points[0].y=0;            
         }                         
         else/*delta x, delta y*/
         {     
            /*x*/    
            touch_data->points[0].x=(kal_int16)((kal_int16)tp_stroke_pre.x+(kal_int16)peek_data[1]);            
            /*y*/            
            touch_data->points[0].y=(kal_int16)((kal_int16)tp_stroke_pre.y+(kal_int16)peek_data[2]);;                        
         }
      }       
      drv_trace4(TRACE_GROUP_10, TP_PEEK_EVENT, touch_data->points[0].event, touch_data->points[0].x, touch_data->points[0].y, 0);
     result = KAL_TRUE;
   }
   else   
   {
      send_touch_ilm = KAL_TRUE;
      result = KAL_FALSE;
   }
      
   if (tp_eint_mask == KAL_FALSE)
   TP_UNMASK_INT;
   IRQUnmask(IRQ_GPT_CODE);
   return result;      
}
#endif //#if !defined(__TOUCH_PANEL_CAPACITY__) && !defined(__TOUCH_PANEL_MULTITOUCH__)

kal_bool touch_panel_peek_event_(TouchPanelMultipleEventStruct *touch_data)
{
#if defined(__TOUCH_PANEL_CAPACITY__)
	return touch_panel_capacitive_peek_event(touch_data);
#elif defined(__TOUCH_PANEL_MULTITOUCH__)
	return touch_panel_dual_peek_event(touch_data);
#else//#if defined(__TOUCH_PANEL_CAPACITY__)
	return touch_panel_resistive_peek_event(touch_data);
#endif //#if defined(__TOUCH_PANEL_CAPACITY__)
}

/*************************************************************************
* FUNCTION
*	touch_panel_conf_move_offset
*
* DESCRIPTION
*	This function is to configure pen move offset and stroke move offset.
*
* PARAMETERS
*	pen_offset: pen move offset
*	stroke_offset: stroke move offset
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void touch_panel_conf_move_offset_(kal_uint16 pen_offset, kal_uint16 stroke_offset, 
                                  kal_uint16 longtap_pen_offset,
                                  kal_uint16 longtap_stroke_offset)
{
	
	drv_trace4(TRACE_GROUP_10, TP_CONF_MOVE_OFFSET, pen_offset, stroke_offset, longtap_pen_offset, longtap_stroke_offset);
   TP.pen_offset=pen_offset;
   TP.storke_offset=stroke_offset;      
   TP.longtap_pen_offset=longtap_pen_offset;
   TP.longtap_stroke_offset=longtap_stroke_offset;
}  


/*************************************************************************
* FUNCTION
*	touch_panel_exceed_penmove
*
* DESCRIPTION
*	This function is pen move event filter.
*
* PARAMETERS
*	x: x coord.
*	y: y coord.
*
* RETURNS
*	exceed TP_MIN_PEN_MOVE_OFFSET or not
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool touch_panel_exceed_penmove(kal_int16 x, kal_int16 y)
{
   kal_int16 x_diff, y_diff;
   
   if(x>TP.pre.x)   
      x_diff=x-TP.pre.x;
   else
      x_diff=TP.pre.x-x;   
   if(y>TP.pre.y)   
      y_diff=y-TP.pre.y;
   else
      y_diff=TP.pre.y-y;      
          
   if(TP.longtap_state==KAL_FALSE)/*normal*/
   {
   if((x_diff>=TP.pen_offset||y_diff>=TP.pen_offset)
                &&(x_diff<TP_NONHAND_WRITING_MAX_OFFSET)&&(y_diff<TP_NONHAND_WRITING_MAX_OFFSET))
        {
          	
         drv_trace1(TRACE_GROUP_10, TP_EXCEED_PENMOVE, 1);
      return KAL_TRUE;          
        }
        else
        {
      	drv_trace1(TRACE_GROUP_10, TP_EXCEED_PENMOVE, 0);
      return KAL_FALSE;   
}  
   }  
   else/*longtap*/
   {
      if((x_diff>=TP.longtap_pen_offset||y_diff>=TP.longtap_pen_offset)
                &&(x_diff<TP_NONHAND_WRITING_MAX_OFFSET)&&(y_diff<TP_NONHAND_WRITING_MAX_OFFSET))
        {
         drv_trace1(TRACE_GROUP_10, TP_EXCEED_PENMOVE, 1);
         return KAL_TRUE;          
        }
        else
        {
      	drv_trace1(TRACE_GROUP_10, TP_EXCEED_PENMOVE, 0);
         return KAL_FALSE;   
      }
      
   }         
}  

/*************************************************************************
* FUNCTION
*	touch_panel_longtap_handwriting_filter
*
* DESCRIPTION
*	This function is to check longtap event in handwriting area.
*
* PARAMETERS
*	x: x coord.
*	y: y coord.
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void touch_panel_longtap_handwriting_filter(kal_int16 x, kal_int16 y)
{
   kal_int16 x_diff, y_diff;      
   
   if(x>TP.begin.x)   
      x_diff=x-TP.begin.x;
   else
      x_diff=TP.begin.x-x;    
      
   if(y>TP.begin.y)    
      y_diff=y-TP.begin.y;
   else
      y_diff=TP.begin.y-y;    
      
   if(x_diff>TP.longtap_stroke_offset||y_diff>TP.longtap_stroke_offset)/*handwriting long tap*/   
   {
      //GPTI_StopItem(touch_panel_repeat_handle);          
      DclSGPT_Control(touch_panel_repeat_handle,SGPT_CMD_STOP,0);
      TP.longtap_state=KAL_FALSE;
   }   
}  
/*************************************************************************
* FUNCTION
*	touch_panel_stroke_filter
*
* DESCRIPTION
*	This function is stroke move event filter.
*
* PARAMETERS
*	x: x coord.
*	y: y coord.
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void touch_panel_stroke_filter(TP_SINGLE_EVENT_T* pEvent)
{
   kal_int16 x_diff, y_diff;
   kal_int16 tmp_x, tmp_y;
   kal_uint16 x, y;
   TP_SINGLE_EVENT_T RTPEvent;
   x = pEvent->x;
   y = pEvent->y;
   
   if(TP.longtap_state==KAL_TRUE)
      touch_panel_longtap_handwriting_filter(x, y);
      
   if(x>TP.pre.x)   
      x_diff=x-TP.pre.x;
   else
      x_diff=TP.pre.x-x;    
      
   if(y>TP.pre.y)    
      y_diff=y-TP.pre.y;
   else
      y_diff=TP.pre.y-y;     
         
      if((x_diff>TP_HAND_WRITING_MAX_OFFSET)||(y_diff>TP_HAND_WRITING_MAX_OFFSET))
         {
              return;
         }
	// When diff >= 128, we will get overflow problem
	// Ex: 147(int16), put 147(cast to uint8) into ring buffer, the value get from 147(int8) will be -109
	// Formula: When diff >=128, we should cut the offset into 2 segments
	if ( (y_diff >= 128) || (x_diff >= 128) )
	 {
			tmp_x = (x + TP.pre.x)/2;
			tmp_y = (y + TP.pre.y)/2;
                    RTPEvent.x = tmp_x;
                    RTPEvent.y = tmp_y;
                    RTPEvent.z = pEvent->z;
			touch_panel_stroke_filter(&RTPEvent);
			// Re-calculate TP.pre if it is updated
			if(x>TP.pre.x)   
				x_diff=x-TP.pre.x;
			else
				x_diff=TP.pre.x-x;    
	      
			if(y>TP.pre.y)    
				y_diff=y-TP.pre.y;
			else
				y_diff=TP.pre.y-y;
	}

  if((x_diff>TP.storke_offset||y_diff>TP.storke_offset))
        {
            if((x_diff<TP_HAND_WRITING_MAX_OFFSET)&&(y_diff<TP_HAND_WRITING_MAX_OFFSET))
   {           
      if(TP.temp.x==0&&TP.temp.y==0)      
      {
                        RTPEvent.x = x-TP.pre.x;
                         RTPEvent.y = y-TP.pre.y;
                        RTPEvent.event= STROKE_MOVE;
                        RTPEvent.z = pEvent->z;
                        tp_data_push(&RTPEvent);
                       //  tp_data_pop(STROKE_MOVE,(x-TP.pre.x) ,(y-TP.pre.y));
         TP.pre.x=x;
         TP.pre.y=y;
      }   
      else
      {
                        //      kal_prompt_trace(MOD_TP_TASK,"TP.temp.x!=0&&TP.temp.y!=0;tmp.x = %d, tmp.y = %d", TP.temp.x,TP.temp.y);
                          
				if(TP.temp.x>TP.pre.x)
					x_diff=TP.temp.x-TP.pre.x;
				else
					x_diff=TP.pre.x-TP.temp.x;
      		
				if(TP.temp.y>TP.pre.y)
					y_diff=TP.temp.y-TP.pre.y;
				else
					y_diff=TP.pre.y-TP.temp.y;
				if ( (y_diff >= 128) || (x_diff >= 128) )
                            {
					tmp_x = (TP.temp.x + TP.pre.x)/2;
					tmp_y = (TP.temp.y + TP.pre.y)/2;
                           //  kal_prompt_trace(MOD_TP_TASK,"y_diff >= 128) || (x_diff >= 128;, tmp_x = %d, tmp_y = %d", tmp_x,tmp_y);
                                         RTPEvent.x = tmp_x;
                                            RTPEvent.y = tmp_y;
                                            RTPEvent.z = pEvent->z;
                        			touch_panel_stroke_filter(&RTPEvent);
        				//	touch_panel_stroke_filter(tmp_x, tmp_y);
        			
			}
                        RTPEvent.x = TP.temp.x-TP.pre.x;
                         RTPEvent.y = TP.temp.y-TP.pre.y;
                        RTPEvent.event= STROKE_MOVE;
                        tp_data_push(&RTPEvent);
                       //  tp_data_pop(STROKE_MOVE, (TP.temp.x-TP.pre.x), (TP.temp.y-TP.pre.y));

         TP.pre.x=TP.temp.x;
         TP.pre.y=TP.temp.y;
         if(x>TP.pre.x)   
            x_diff=x-TP.pre.x;
         else
            x_diff=TP.pre.x-x;   
      
         if(y>TP.pre.y)   
            y_diff=y-TP.pre.y;
         else         
            y_diff=TP.pre.y-y;          
            
         if((x_diff>TP.storke_offset||y_diff>TP.storke_offset))
         {
                                  RTPEvent.x = x-TP.pre.x;
                                 RTPEvent.y = y-TP.pre.y;
                                RTPEvent.event= STROKE_MOVE;
                                tp_data_push(&RTPEvent);
                             //   tp_data_pop(STROKE_MOVE, (x-TP.pre.x), (y-TP.pre.y));
            TP.pre.x=x;
            TP.pre.y=y;
            TP.temp.x=0;
            TP.temp.y=0;
         }   
         else
         {
            TP.temp.x=x;
            TP.temp.y=y;
         }                                    
      }                        
   }
   else     
   {
                  //  kal_prompt_trace(MOD_TP_TASK,"x_diff > TP_HAND_WRITING_MAX_OFFSET||y_diff > TP_HAND_WRITING_MAX_OFFSET");
                }
        }
      else
        {
              // kal_prompt_trace(MOD_TP_TASK,"(x_diff<TP.storke_offset&&y_diff<TP.storke_offset:TP.temp.x = %d, TP.temp.y = %d",TP.temp.x,TP.temp.y);
      TP.temp.x=x;
      TP.temp.y=y;  
   }   
} 

/*************************************************************************
* FUNCTION
*	tp_data_pop
*
* DESCRIPTION
*	This function is to "push" data to buffer.
*
* PARAMETERS
*	x: x coord.
*	y: y coord.
*  event: event type
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/  
kal_uint16 tp_roomleft_min=TOUCH_PANEL_BUFFER_SIZE;
void tp_data_push(TP_SINGLE_EVENT_T* push_event)
{
    kal_uint16 roomleft=0;
   kal_uint32 timestamp = 0;
   Touch_Panel_Event_enum pop_event;
   kal_int16 x;
   kal_int16 y;
   kal_uint16 pressure = 0;
   TP_SINGLE_EVENT_T RTPEvent;
   RTPEvent.z = 0;
   
   tp_get_buf_roomleft(roomleft);   
   pop_event = (Touch_Panel_Event_enum)push_event->event;
   x = push_event->x;
   y = push_event->y;
   pressure = push_event->z;
   
   /*To get minimum roomleft*/
   if(roomleft<tp_roomleft_min)
      tp_roomleft_min=roomleft;
   
   if(TP.is_buff_full==KAL_TRUE)
      return;
   
   drv_trace4(TRACE_GROUP_9, TP_DATA_POP, pop_event, x, y, roomleft);
   
   if(roomleft<=BASIC_EVENT_UNIT)
   {
       TP.is_buff_full=KAL_TRUE;
       return;
   }    
#if defined(DRV_TOUCH_PANEL_PAIR_GUARANTEE)
   if( (pop_event == PEN_DOWN) || (pop_event == STROKE_DOWN))
   {
      if(TP.buffer_push_stat == PEN_DOWN)
        {
            RTPEvent.event = PEN_UP;
            RTPEvent.x = TP.buffer_push_point.x;
            RTPEvent.y = TP.buffer_push_point.y;
            
            tp_data_push(&RTPEvent);
        }
        // tp_data_pop(PEN_UP, TP.buffer_push_point.x, TP.buffer_push_point.y);
      else if(TP.buffer_push_stat == STROKE_DOWN)
        {
             RTPEvent.event = STROKE_UP;
            RTPEvent.x = TP.buffer_push_point.x;
            RTPEvent.y = TP.buffer_push_point.y;
             tp_data_push(&RTPEvent);
        }
        // tp_data_pop(STROKE_UP, TP.buffer_push_point.x, TP.buffer_push_point.y);
      TP.buffer_push_stat = pop_event; //use to guarantee this pop_event will have pair UP event.
   }
   else if((pop_event == PEN_UP) || (pop_event == STROKE_UP))
   {
      TP.buffer_push_stat = pop_event; //use to guarantee this pop_event will have pair UP event.
   }
   TP.buffer_push_point.x = x;
   TP.buffer_push_point.y = y;
#endif //#if defined(DRV_TOUCH_PANEL_PAIR_GUARANTEE)
   if((pop_event == PEN_MOVE) || (pop_event == STROKE_MOVE)) //before we get move event, we use faster sampling rate.
   {
      Touch_Panel_first_valid = KAL_TRUE; //start to use original sampling rate   	
   }

   if(pop_event==STROKE_MOVE) 
   {
      kal_uint8 x_value;
      kal_uint8 y_value;

      /* Cast x, y to kal_uint8. */
      x_value = x;
      y_value = y;
      #ifdef TOUCH_PANEL_DEBUG
      dbg_printWithTime("Move %d,%d\r\n",(kal_int16)x,(kal_int16)y);
      #endif
      drv_trace2(TRACE_GROUP_10, TP_STROKE_MOVE, x, y);

      /*to avoid STROKE_UP and STROKE_LONGTAP data show in the packet*/
      if(x_value==(kal_uint8)STROKE_UP)
         x_value = (kal_uint8)STROKE_UP - 2;
      else if (x_value==(kal_uint8)STROKE_LONGTAP)
         x_value = (kal_uint8)STROKE_LONGTAP - 1;
      if(y_value==(kal_uint8)STROKE_UP)
         y_value = (kal_uint8)STROKE_UP - 2;   
      else if (y_value==(kal_uint8)STROKE_LONGTAP)
         y_value = (kal_uint8)STROKE_LONGTAP - 1;
      touhc_push_data_to_buffer(x_value,pop_event);/*diff_x*/
      touhc_push_data_to_buffer(y_value,pop_event);/*diff_y*/   
   }   
   else if(pop_event==STROKE_LONGTAP) 
   {
      touhc_push_data_to_buffer(pop_event,pop_event);/*diff_x*/
   }   
   else if(pop_event==STROKE_UP) 
   {
      touhc_push_data_to_buffer(pop_event, pop_event);         
   }
   else
   {
         touhc_push_data_to_buffer(pop_event, pop_event);   
         /*lint -e702*/
         // no matter x is signed or unsigned, shift for 16 bits separate into 2 parts.
         touhc_push_data_to_buffer((x>>8), pop_event);   
         touhc_push_data_to_buffer(x, pop_event);
	      touhc_push_data_to_buffer((y>>8), pop_event);   
         /*lint +e702*/
	      touhc_push_data_to_buffer(y, pop_event);   
	 //  }
		// If the pop_event is PEN_UP or PEN_DOWN, we add timestamp info
		if ( (pop_event == PEN_UP) || (pop_event == PEN_DOWN) ||(pop_event == PEN_MOVE))
            {
			#if !defined(IC_MODULE_TEST) && !defined(IC_BURNIN_TEST)
			timestamp = (kal_uint32)L1I_GetTimeStamp();
			#endif
			// add 0 as timestamp when module test.
			touhc_push_data_to_buffer((timestamp>>24), pop_event);
			touhc_push_data_to_buffer((timestamp>>16)&0xFF, pop_event);
                   touhc_push_data_to_buffer((timestamp>>8)&0xFF, pop_event);
                   touhc_push_data_to_buffer(timestamp, pop_event);
                   drv_trace1(TRACE_GROUP_10, TP_PUSH_TIMESTAMP, timestamp );
		}
   }   

      touhc_push_data_to_buffer((pressure>>8),pop_event );/*high*/
      touhc_push_data_to_buffer(pressure,pop_event );/*high*/
      drv_trace1(TRACE_GROUP_10, TP_PUSH_DATA_PRESSURE,  pressure );
            
      
} 
  
/*************************************************************************
* FUNCTION
*	touch_panel_check_cali
*
* DESCRIPTION
*	This function is to check calibration result.
*
* PARAMETERS
*	x: x coord.
*	y: y coord.
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/   
kal_bool touch_panel_check_cali_stage3(void)
{
   kal_int32 x, y, x_diff, y_diff;
   double x_slope, y_slope, x_offset, y_offset; 
   kal_int32 offset = (kal_int32)TP_CALI_CHECK_OFFSET; //default value = 6
      
   touch_panel_tuning(cali_point[0].x, cali_point_adc[0].x, 
                      cali_point[1].x, cali_point_adc[1].x, 
                      &x_slope, &x_offset);
   touch_panel_tuning(cali_point[0].y, cali_point_adc[0].y, 
                      cali_point[1].y, cali_point_adc[1].y, 
                      &y_slope, &y_offset); 
        
   x=(kal_int16)(x_slope*(double)(cali_point_adc[2].x)+x_offset);   
   y=(kal_int16)(y_slope*(double)(cali_point_adc[2].y)+y_offset); 
   
   x_diff=cali_point[2].x-x;
   y_diff=cali_point[2].y-y;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

   if(x_diff>offset||x_diff<(-offset)|| y_diff>offset||y_diff<(-offset))
      return KAL_FALSE;
   return KAL_TRUE;
}   

kal_bool touch_panel_check_cali_stage1(void)
{
   kal_int32 x_adc_range, x_coord_range, x_adc_high, x_adc_low;   
   kal_int32 y_adc_range, y_coord_range, y_adc_high, y_adc_low;
   
   /*use the relative ADC difference*/
   /*X ADC Diff*/
   if(cali_point_adc[1].x>=cali_point_adc[0].x)
      x_adc_range=cali_point_adc[1].x-cali_point_adc[0].x;   
   else
      x_adc_range=cali_point_adc[0].x-cali_point_adc[1].x;   
   /*Y ADC Diff*/   
   if(cali_point_adc[1].y>=cali_point_adc[0].y)   
      y_adc_range=cali_point_adc[1].y-cali_point_adc[0].y;   
   else
      y_adc_range=cali_point_adc[0].y-cali_point_adc[1].y; 
                 
   /*X Coord Diff*/   
   if(cali_point[1].x>=cali_point[0].x)         
      x_coord_range=cali_point[1].x-cali_point[0].x;   
   else
      x_coord_range=cali_point[0].x-cali_point[1].x;      
   /*Y Coord Diff*/      
   if(cali_point[1].y>=cali_point[0].y)   
      y_coord_range=cali_point[1].y-cali_point[0].y;  
   else   
      y_coord_range=cali_point[0].y-cali_point[1].y;  
   #ifdef __MTK_INTERNAL__            
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #else
   x_adc_high=(kal_int32)(x_coord_range*(TP_ADC_X_END-TP_ADC_X_START)*150/(TP_SCREEN_X_END-TP_SCREEN_X_START)/100);
   x_adc_low=(kal_int32)(x_coord_range*(TP_ADC_X_END-TP_ADC_X_START)*50/(TP_SCREEN_X_END-TP_SCREEN_X_START)/100);
   y_adc_high=(kal_int32)(y_coord_range*(TP_ADC_Y_END-TP_ADC_Y_START)*150/(TP_SCREEN_Y_END-TP_SCREEN_Y_START)/100); 
   y_adc_low=(kal_int32)(y_coord_range*(TP_ADC_Y_END-TP_ADC_Y_START)*50/(TP_SCREEN_Y_END-TP_SCREEN_Y_START)/100);       
   #endif
   
   #ifdef TOUCH_PANEL_DEBUG
   dbg_printWithTime("x adc diff=%d high=%d low=%d\r\n",x_adc_range,x_adc_high,x_adc_low ); 
   dbg_printWithTime("y adc diff=%d high=%d low=%d\r\n",y_adc_range,y_adc_high,y_adc_low );                        
   #endif
   
   drv_trace8(TRACE_GROUP_10, TP_CALI_ADC_DIFF, x_adc_range, x_adc_high, x_adc_low, y_adc_range, y_adc_high, y_adc_low, 0, 0);
   if((x_adc_range<x_adc_low) || (x_adc_range>x_adc_high))
      return KAL_FALSE;
   if((y_adc_range<y_adc_low) || (y_adc_range>y_adc_high))
      return KAL_FALSE;                           
   return KAL_TRUE;      
}
kal_bool touch_panel_check_cali_stage2(void)
{   
   kal_int32 x02_diff, y02_diff, x12_diff, y12_diff;
      
   /*use the point 3 to check if the previous 2 two points are opposite*/      
   if(cali_point_adc[1].x>=cali_point_adc[0].x)/*1>2>0*/
   {
      x12_diff=cali_point_adc[1].x-cali_point_adc[2].x;
      x02_diff=cali_point_adc[2].x-cali_point_adc[0].x;            
   }
   else/*0>2>1*/
   {  
      x12_diff=cali_point_adc[2].x-cali_point_adc[1].x;
      x02_diff=cali_point_adc[0].x-cali_point_adc[2].x;            
   }            
   if(cali_point_adc[1].y>=cali_point_adc[0].y)/*1>2>0*/
   {
      y12_diff=cali_point_adc[1].y-cali_point_adc[2].y;
      y02_diff=cali_point_adc[2].y-cali_point_adc[0].y;            
   }
   else/*0>2>1*/
   {  
      y12_diff=cali_point_adc[2].y-cali_point_adc[1].y;
      y02_diff=cali_point_adc[0].y-cali_point_adc[2].y;            
   }   
      
   if(y12_diff>y02_diff||x12_diff>x02_diff)
      return KAL_FALSE;      
   return KAL_TRUE;
}
kal_bool touch_panel_check_cali(void)
{
#if !defined(__TOUCH_PANEL_CAPACITY__)

   kal_bool result1, result2, result3;
   result1=touch_panel_check_cali_stage1();
   result2=touch_panel_check_cali_stage2();
   result3=touch_panel_check_cali_stage3();
#endif
      
#if defined(__TOUCH_PANEL_CAPACITY__)
   return KAL_TRUE;
#else      
   if(result1==KAL_TRUE&&result2==KAL_TRUE&&result3==KAL_TRUE)
      return KAL_TRUE;
   else   
      return KAL_FALSE;
#endif
}

void touch_panel_send_msg(kal_bool result, Touch_Panel_Dual_Calibration_Mode_enum mode)
{
   ilm_struct *tp_ilm;
   tp_cali_done_struct *local_para;
   module_type owner=MOD_NIL;

   local_para = (tp_cali_done_struct *) 
      construct_local_para(sizeof(tp_cali_done_struct),TD_UL);
   local_para->result=result;
   local_para->mode = (DCL_TP_CALIBRATION_MODE_Enum)mode;
   
   #ifdef TOUCH_PANEL_DEBUG
   	owner=MOD_SSDBG1;
   #else
   	owner=MOD_MMI;
   #endif
   
     DRV_BuildPrimitive(tp_ilm,
                        MOD_TP_TASK,
     					    owner,
                        MSG_ID_TP_CALI_DONE,
                        local_para);   
     msg_send_ext_queue(tp_ilm);
}

/*************************************************************************
* FUNCTION
*	touch_excute_cali
*
* DESCRIPTION
*	This function is to excute calibration.
*
* PARAMETERS
*	x: x coord.
*	y: y coord.
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/   
void touch_excute_cali(kal_uint16 x_adc, kal_uint16 y_adc)
{
#if !defined(__TOUCH_PANEL_CAPACITY__)
   kal_bool cali_result;
   
   if(tp_cali_mode==TP_FINISH_CALIBRATION_MODE)
   {
      return;
   }
   if(tp_cali_mode==TP_SINGLE_CALIBRATION_MODE_STEP1)
   {
      drv_trace2(TRACE_GROUP_10, TP_CALI_1ST_ADC, x_adc, y_adc);

      tp_cali_mode = TP_SINGLE_CALIBRATION_MODE_STEP2;
      cali_point_adc[0].x=x_adc;
      cali_point_adc[0].y=y_adc;      
   }         
   else if(tp_cali_mode==TP_SINGLE_CALIBRATION_MODE_STEP2)
   {
      drv_trace2(TRACE_GROUP_10, TP_CALI_2ND_ADC, x_adc, y_adc);
      tp_cali_mode = TP_SINGLE_CALIBRATION_MODE_STEP3;
      cali_point_adc[1].x=x_adc;
      cali_point_adc[1].y=y_adc;          
   }
   else if(tp_cali_mode==TP_SINGLE_CALIBRATION_MODE_STEP3)
   {      
      cali_point_adc[2].x=x_adc;
      cali_point_adc[2].y=y_adc;          
      tp_cali_mode=TP_FINISH_CALIBRATION_MODE;
      cali_result=touch_panel_check_cali();
      drv_trace1(TRACE_GROUP_10, TP_CALIBRATION, cali_result );
      if(cali_result==KAL_TRUE) 
      {
      touch_panel_tuning(cali_point[0].x, cali_point_adc[0].x, 
                         cali_point[1].x, cali_point_adc[1].x, 
                         &TPCali.x_slope, &TPCali.x_offset);
      touch_panel_tuning(cali_point[0].y, cali_point_adc[0].y, 
                         cali_point[1].y, cali_point_adc[1].y, 
                         &TPCali.y_slope, &TPCali.y_offset);      
      }   
      touch_panel_send_msg(cali_result, TP_CALI_FINISH);
   }
   else if(tp_cali_mode == TP_DUAL_CALIBRATION_MODE)
   {
   }
   else
   {
      tp_cali_mode=TP_FINISH_CALIBRATION_MODE;
      touch_panel_send_msg(KAL_TRUE, TP_CALI_FINISH);
   }               
#endif //#if defined(__TOUCH_PANEL_CAPACITY__)
}  

/*************************************************************************
* FUNCTION
*	touch_panel_longtap_cb
*
* DESCRIPTION
*	This function is long tap timer callback function.
*
* PARAMETERS
*  Parameter
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/    
void touch_panel_longtap_cb(void *parameter)
{ 
	//kal_bool btmp;
     TP_SINGLE_EVENT_T RTPEvent;
#if defined(DRV_ADC_TOUCH_SCREEN)
	HTS_CTRL_DATA_T tp_state;
	DclHTS_Control(TP.hts_handle,HTS_CMD_GET_TP_LEVEL,&tp_state);
    if ((kal_bool)touch_up_level == tp_state.rTSCtrlTL.fgIsUP)
    {
#ifdef DRV_TP_PENUP_FIXED  //pen irq don't lost, so just wait for pen irq
        return;
#else
		DclHTS_Control(TP.hts_handle,HTS_CMD_TP_UPDATENOTIFY,0);
		return;
#endif
	}
     DclHTS_Control(TP.hts_handle,HTS_CMD_GET_TP_LEVEL_PRESSURE,&tp_state);
    RTPEvent.z = tp_state.rTSCtrlTPPV.fgPressureValue;
#endif // #if defined(DRV_ADC_TOUCH_SCREEN)
	
   if(TP.state==DOWN)
   {
      if(TP.area==HAND_WRITING)    
      {
       RTPEvent.event = STROKE_LONGTAP;
        RTPEvent.x = TP.pre.x;
        RTPEvent.y = TP.pre.y;
        tp_data_push(&RTPEvent);
         //tp_data_pop(STROKE_LONGTAP, TP.pre.x, TP.pre.y);      
      }
      else
      {
      RTPEvent.event = PEN_LONGTAP;
        RTPEvent.x = TP.pre.x;
        RTPEvent.y = TP.pre.y;
        tp_data_push(&RTPEvent);
   //   tp_data_pop(PEN_LONGTAP, TP.pre.x, TP.pre.y);
      #ifdef TOUCH_PANEL_DEBUG                    
      dbg_printWithTime("PEN LONGTAP x=%d y=%d\r\n",TP.pre.x,TP.pre.y);		         
      #endif
      drv_trace2(TRACE_GROUP_10, TP_PEN_LONGTAP, TP.pre.x, TP.pre.y);   
      if(TP.repeat_cnt!=0)
      {
      	touch_panel_set_timer(touch_panel_repeat_handle, (TP_EVENT_FUNC)touch_panel_repeat_cb, TP.repeat_cnt, NULL);
      }                        
   }                        
}
}

/*************************************************************************
* FUNCTION
*	touch_panel_repeat_cb
*
* DESCRIPTION
*	This function is repeat timer callback function.
*
* PARAMETERS
*  Parameter
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/  
void touch_panel_repeat_cb(void *parameter)
{   
          TP_SINGLE_EVENT_T RTPEvent;
#if defined(DRV_ADC_TOUCH_SCREEN)
	HTS_CTRL_DATA_T tp_state;
	DclHTS_Control(TP.hts_handle,HTS_CMD_GET_TP_LEVEL,&tp_state);
	if ((kal_bool)touch_up_level == tp_state.rTSCtrlTL.fgIsUP)
		{
#ifdef DRV_TP_PENUP_FIXED  //pen irq don't lost, so just wait for pen irq
        return;
#else
			DclHTS_Control(TP.hts_handle,HTS_CMD_TP_UPDATENOTIFY,0);
			return;
#endif
		}
    DclHTS_Control(TP.hts_handle,HTS_CMD_GET_TP_LEVEL_PRESSURE,&tp_state);
    RTPEvent.z = tp_state.rTSCtrlTPPV.fgPressureValue;
#endif // #if defined(DRV_ADC_TOUCH_SCREEN)
	
   if(TP.state==DOWN)
   {
    RTPEvent.event = PEN_REPEAT;
    RTPEvent.x = TP.pre.x;
    RTPEvent.y = TP.pre.y;
    tp_data_push(&RTPEvent);
     // tp_data_pop(PEN_REPEAT, TP.pre.x, TP.pre.y);
      
      drv_trace2(TRACE_GROUP_10, TP_PEN_REPEAT, TP.pre.x, TP.pre.y);
      if(TP.repeat_cnt!=0)
      {
      	touch_panel_set_timer(touch_panel_repeat_handle, (TP_EVENT_FUNC)touch_panel_repeat_cb, TP.repeat_cnt, NULL);
      }                     
   }                         
   
}

/*************************************************************************
* FUNCTION
*	touch_panel_stroke_cb
*
* DESCRIPTION
*	This function is polling timer callback function in handwriting area.
*
* PARAMETERS
*  Parameter
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/    
void touch_panel_stroke_cb(void *parameter)
{
  // kal_int16 x, y;
   kal_bool valid=KAL_FALSE;
   TP_SINGLE_EVENT_T RTPEvent;
   
#if defined(__DRV_TP_DISCARD_SHIFTING__)
   kal_uint32 pressure1 = 0, pressure2 = 0;
#endif //#if defined(__DRV_TP_DISCARD_SHIFTING__)

#if defined(DRV_ADC_TOUCH_SCREEN)
	HTS_CTRL_DATA_T tp_state;	
//	kal_prompt_trace(MOD_TP_TASK,"touch_panel_stroke_cb s=%d", ust_get_current_time());
        drv_trace1(TRACE_GROUP_10, TP_STROKE_CB_START,  ust_get_current_time());
	SLA_CustomLogging("TDW",1);
        // modify by xugang for RTP overhead improvement  at 2011.11.29
		DclHTS_Control(TP.hts_handle,HTS_CMD_GET_TP_LEVEL_PRESSURE,&tp_state);
		pressure1=tp_state.rTSCtrlTL.pressure_value;
		if ((kal_bool)touch_up_level == tp_state.rTSCtrlTL.fgIsUP)
{
	 if(TP_Stroke_Up_Count == 2)
            {
                TP_Stroke_Up_Count = 0;
#ifdef DRV_TP_PENUP_FIXED  //pen irq don't lost, so just wait for pen irq
            return;
#else
                DclHTS_Control(TP.hts_handle,HTS_CMD_TP_UPDATENOTIFY,0);
                SLA_CustomLogging("TDW",0);
	//	kal_prompt_trace(MOD_TP_TASK,"touch_panel_stroke_cb e1=%d", ust_get_current_time());
                drv_trace1(TRACE_GROUP_10, TP_STROKE_CB_END,  ust_get_current_time());
		    return;
#endif
            }   
           TP_Stroke_Up_Count++;
	}
#endif // #if defined(DRV_ADC_TOUCH_SCREEN)
 
   if(TP.state==DOWN)
   {

#ifdef TOUCH_PANEL_PRESSURE
      if ((kal_bool)touch_up_level != tp_state.rTSCtrlTL.fgIsUP)
      {
        RTPEvent.z = pressure1;
#endif //#ifdef TOUCH_PANEL_PRESSURE
         touch_panel_read_adc(&RTPEvent.x, &RTPEvent.y);				      
        valid=touch_panel_adc_to_coordinate(&RTPEvent.x, &RTPEvent.y);/*translate*/		
#if defined(__DRV_TP_DISCARD_SHIFTING__)
         if( (KAL_FALSE == tp_pressure_check_value(&pressure2))
           || touch_panle_pressure_shift_check(pressure1, pressure2) )
         {
            valid = KAL_FALSE;
         }
#endif //#if defined(__DRV_TP_DISCARD_SHIFTING__)
        if(valid==KAL_TRUE)
        {
             touch_panel_stroke_filter(&RTPEvent);	
        }      
		     	
#ifdef TOUCH_PANEL_PRESSURE
      }
#endif
		/*start polling again*/
		touch_panel_stroke_hdr();
	}
       SLA_CustomLogging("TDW",0); 
//	kal_prompt_trace(MOD_TP_TASK,"touch_panel_stroke_cb e2=%d", ust_get_current_time());
       drv_trace1(TRACE_GROUP_10, TP_STROKE_CB_END,  ust_get_current_time());
}    

/*************************************************************************
* FUNCTION
*	touch_panel_event_cb
*
* DESCRIPTION
*	This function is polling timer callback function in non-handwriting.
*
* PARAMETERS
*  Parameter
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/    
/*Event timer callback function*/
void touch_panel_event_cb(void *parameter)
{
	kal_uint16 x=0, y=0;
	kal_bool valid=KAL_FALSE;
	TP_SINGLE_EVENT_T RTPEvent;

#if defined(__DRV_TP_DISCARD_SHIFTING__)
	kal_uint32 pressure1=0, pressure2=0;
#endif //#if defined(__DRV_TP_DISCARD_SHIFTING__)

#if defined(DRV_ADC_TOUCH_SCREEN)
	HTS_CTRL_DATA_T tp_state;	
     //  kal_prompt_trace(MOD_TP_TASK,"touch_panel_event_cb s=%d", ust_get_current_time());
       drv_trace1(TRACE_GROUP_10, TP_EVENT_CB_START,  ust_get_current_time());
	SLA_CustomLogging("TDW",1); 
        // modify by xugang for RTP overhead improvement  at 2011.11.29
    DclHTS_Control(TP.hts_handle,HTS_CMD_GET_TP_LEVEL_PRESSURE,&tp_state);
		pressure1=tp_state.rTSCtrlTL.pressure_value;
		if ((kal_bool)touch_up_level == tp_state.rTSCtrlTL.fgIsUP)
		{
#ifdef DRV_TP_PENUP_FIXED  //if up irq don't lost, so just wait for pen irq
        return;
#else
			DclHTS_Control(TP.hts_handle,HTS_CMD_TP_UPDATENOTIFY,0);
		SLA_CustomLogging("TDW",0);
	//	kal_prompt_trace(MOD_TP_TASK,"touch_panel_event_cb e1=%d", ust_get_current_time());
                drv_trace1(TRACE_GROUP_10, TP_EVENT_CB_END,  ust_get_current_time());
			return;

#endif
		}
#endif // #if defined(DRV_ADC_TOUCH_SCREEN)

		if(TP.state==DOWN)
		{		
 // modify by xugang for RTP overhead improvement  at 2011.11.29		
#ifdef TOUCH_PANEL_PRESSURE

			if ((kal_bool)touch_up_level != tp_state.rTSCtrlTL.fgIsUP)
			{
				RTPEvent.z = pressure1;
#endif
				touch_panel_read_adc(&x, &y);				
				valid=touch_panel_adc_to_coordinate(&x,&y);/*translate*/		
#if defined(__DRV_TP_DISCARD_SHIFTING__)
				if( (KAL_FALSE == tp_pressure_check_value(&pressure2))
				|| touch_panle_pressure_shift_check(pressure1, pressure2) )
				{
					valid = KAL_FALSE;
				}
#endif //#if defined(__DRV_TP_DISCARD_SHIFTING__)
				if(touch_panel_exceed_penmove(x, y)&&(valid==KAL_TRUE))
				{
					TP.longtap_state=KAL_FALSE;
					RTPEvent.x = x;
					RTPEvent.y = y;
					RTPEvent.event = PEN_MOVE;
					tp_data_push(&RTPEvent);
#ifdef TOUCH_PANEL_DEBUG
dbg_printWithTime("PEN MOVE x=%d y=%d\r\n",x,y);
#endif
					drv_trace2(TRACE_GROUP_10, TP_PEN_MOVE, x, y);
					TP.pre.x=x;
					TP.pre.y=y;    		   
					DclSGPT_Control(touch_panel_repeat_handle,SGPT_CMD_STOP,0);
					if(TP.repeat_cnt!=0)/*long tap and reapeat timer*/
					{
						touch_panel_set_timer(touch_panel_repeat_handle, (TP_EVENT_FUNC)touch_panel_repeat_cb, TP.repeat_cnt, NULL);
					}                  
				}
#ifdef TOUCH_PANEL_PRESSURE
			}
#endif
		/*start polling again*/
		touch_panel_event_hdr();
	}
	SLA_CustomLogging("TDW",0); 
//	kal_prompt_trace(MOD_TP_TASK,"touch_panel_event_cb e2=%d", ust_get_current_time());
        drv_trace1(TRACE_GROUP_10, TP_EVENT_CB_END,  ust_get_current_time());
} 

/*************************************************************************
* FUNCTION
*	touch_panel_adc_to_coordinate
*
* DESCRIPTION
*	This function is to translate ADC to coordinate.
*
* PARAMETERS
*  x: x coord.
*  y: y coord.
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/ 
/*adc to coordinate*/
kal_bool touch_panel_adc_to_coordinate(kal_uint16 *x, kal_uint16 *y)
{
   kal_int32 xtmp, ytmp;
   kal_uint16 x2, y2;
   kal_uint32 xStart, xEnd, yStart, yEnd;
      
   xtmp = (TPCali.x_slope*(double)(*x)+TPCali.x_offset);
   ytmp = (TPCali.y_slope*(double)(*y)+TPCali.y_offset);
   *x=(kal_uint16)(xtmp<0?0:xtmp);   
   *y=(kal_uint16)(ytmp<0?0:ytmp);   
   if( (TP_SCREEN_X_START<=*x)&&(*x<=TP_SCREEN_X_END)&&
       (TP_SCREEN_Y_START<=*y)&&(*y<=TP_SCREEN_Y_END))
   {
      drv_trace2(TRACE_GROUP_10, TP_VALID_COORD_VALUE, *x, *y);
      
      return KAL_TRUE;  
   }
   else
   {
      drv_trace8(TRACE_GROUP_10, TP_INVALID_COORD_VALUE, TP_SCREEN_X_START, TP_SCREEN_X_END, TP_SCREEN_Y_START, TP_SCREEN_Y_END, *x, *y, 0, 0);
      // during calibration, the slope and offset maybe invalid, we can not modify the measure result to boundary,
        if (tp_cali_mode != TP_FINISH_CALIBRATION_MODE)
        {
         if(TP_SCREEN_X_START<=*x)  //avoid MMI ignore the exceed range point
         	*x = TP_SCREEN_X_START;
         if(*x<=TP_SCREEN_X_END)
         	*x = TP_SCREEN_X_END;
         if(TP_SCREEN_Y_START<=*y)
         	*y = TP_SCREEN_Y_START;
         if(*y<=TP_SCREEN_Y_END)
         	*y = TP_SCREEN_Y_END;
      	 drv_trace0(TRACE_GROUP_10, TP_CALI_FORCE_VALID_COORD_VALUE);
         return KAL_TRUE;
      }

      touch_panel_read_adc(&x2, &y2);

      // use custom setting boundary to filter out unwanted sample point.
      xStart = (kal_uint32)TP_ADC_X_START>>2;
      xEnd = (kal_uint32)TP_ADC_X_END + xStart;
      yStart = (kal_uint32)TP_ADC_Y_START>>2;
      yEnd = (kal_uint32)TP_ADC_Y_END + yStart;
      if( (x2 <= xStart) || (x2 >= xEnd) || (y2 <= yStart) || (y2 >= yEnd))
        {
            // filter out adc boundary. we assuem it's invalid sample point
         return KAL_FALSE;
      }

      xtmp = (TPCali.x_slope*(double)(x2)+TPCali.x_offset);
      ytmp = (TPCali.y_slope*(double)(y2)+TPCali.y_offset);
      *x=(kal_uint16)(xtmp<0?0:xtmp);
      *y=(kal_uint16)(ytmp<0?0:ytmp);
      //return boundary value for keep trace the pen on panel.
      if(*x<TP_SCREEN_X_START)
         *x=TP_SCREEN_X_START;
      else if (*x>TP_SCREEN_X_END)
         *x=TP_SCREEN_X_END;
         
      if(*y<TP_SCREEN_Y_START)
         *y=TP_SCREEN_Y_START;
      else if (*y>TP_SCREEN_Y_END)
         *y=TP_SCREEN_Y_END;     
               
      drv_trace0(TRACE_GROUP_10, TP_CALI_FORCE_VALID_COORD_VALUE);

      return KAL_TRUE;
   }          
   
}
/*************************************************************************
* FUNCTION
*	touch_panel_HISR
*
* DESCRIPTION
*	This function is to handle touch event.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/    
/*touch event HISR, wake up touch panel task*/
void touch_panel_HISR(void)
{   
	kal_uint32 pressure;
   if (touch_panel_state==(kal_bool)touch_down_level)/*low*/
   {
      #ifdef TOUCH_PANEL_DEBUG
      dbg_printWithTime("touch down\r\n");            
      #endif
      drv_trace0(TRACE_GROUP_10, TP_HISR_DOWN);
      TP.state=DOWN;
#if defined(__READ_TP_DATA_IN_HISR__)
		touch_panel_read_adc(&gX, &gY);
#ifdef TOUCH_PANEL_PRESSURE

#ifndef DRV_TP_SLIM
		gPressureCheck = tp_fun_ptr->tp_pressure_check();
#else
        gPressureCheck = tp_pressure_check_value(&pressure);
#endif

#endif // #ifdef TOUCH_PANEL_PRESSURE

#endif // #if defined(__READ_TP_DATA_IN_HISR__)
TP.tp_down_cb(NULL);
   }
   else/*high*/
   {      
      #ifdef TOUCH_PANEL_DEBUG
      dbg_printWithTime("touch up\r\n");            
      #endif
      drv_trace0(TRACE_GROUP_10, TP_HISR_UP);
      TP.state=UP;
      TP.tp_up_cb(NULL);
   }
   touch_panel_state = (kal_bool)!touch_panel_state;
   EINT_Set_Polarity(TP.eint_chan,touch_panel_state);
   TP_UNMASK_INT;
}

/*************************************************************************
* FUNCTION
*	touch_panel_read_adc
*
* DESCRIPTION
*	This function is to read adc from touch panel module.
*
* PARAMETERS
*  x: x coord.
*  y: y coord.
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void touch_panel_read_adc(kal_uint16 *x, kal_uint16 *y)
{
   tp_fun_ptr->tp_read_adc(x, y);
	#if defined(__PORTRAIT_LCM_SIMULATE_LANDSCAPE_LCM__) || defined(__LCM_SCANLINE_ROTATION_SUPPORT__)
	{
		// Swap X-axis and Y-axis ADC value for Portrait LCM simuates Landscape LCM
		// For this condition, driver reports X-axis coordinate value by refering TP Y-axis ADC value
		//                     driver reports Y-axis coordinate value by refering TP X-axis ADC value
		kal_int16 swap_temp;
		swap_temp = *x;
		*x = *y;
		*y = swap_temp;
	}
	#endif // #if defined(__PORTRAIT_LCM_SIMULATE_LANDSCAPE_LCM__)
	
	drv_trace2(TRACE_GROUP_10, TP_ADC_VALUE, *x, *y);
}

/*************************************************************************
* FUNCTION
*	touch_panel_enable
*
* DESCRIPTION
*	This function is to enable/disbale touch panel module.
*
* PARAMETERS
*  x: x coord.
*  y: y coord.
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
/*enable/disable touch panel*/
void touch_panel_enable_(kal_bool enable)
{  
   /*enable*/
   if(enable==KAL_TRUE)
   {
      /*EINT*/
		
//only extend RTP controler need call the following intructions
#ifndef DRV_TP_SLIM
#if !defined(__TOUCH_PANEL_CAPACITY__)
		#if defined(__READ_TP_DATA_IN_HISR__)
		touch_panel_set_timer(touch_panel_irq_en_handle, (TP_EVENT_FUNC)touch_panel_irq_en_cb, 1, (void *)KAL_TRUE);
		#else
		tp_fun_ptr->tp_irq_enable(enable);
		#endif // #if defined(__READ_TP_DATA_IN_HISR__)
#endif //#if !defined(__TOUCH_PANEL_CAPACITY__)
#endif
      TP_UNMASK_INT;
      tp_eint_mask = KAL_FALSE;
   }   
   else/*disbale*/
   {
      TP_MASK_INT;
      //GPTI_StopItem(touch_panel_handle);
      DclSGPT_Control(touch_panel_handle,SGPT_CMD_STOP,0);
      //GPTI_StopItem(touch_panel_repeat_handle);
      DclSGPT_Control(touch_panel_repeat_handle,SGPT_CMD_STOP,0);
//only extend RTP controler need call the following intructions
#ifndef DRV_TP_SLIM  
#if !defined(__TOUCH_PANEL_CAPACITY__)
		#if defined(__READ_TP_DATA_IN_HISR__)
		touch_panel_set_timer(touch_panel_irq_en_handle, (TP_EVENT_FUNC)touch_panel_irq_en_cb, 1, (void *)KAL_TRUE);
		#else
		tp_fun_ptr->tp_irq_enable(enable);
		#endif // #if defined(__READ_TP_DATA_IN_HISR__)
#endif //#if !defined(__TOUCH_PANEL_CAPACITY__)
#endif

      tp_eint_mask = KAL_TRUE;
   }   
}      
/*************************************************************************
* FUNCTION
*	touch_panel_init
*
* DESCRIPTION
*	This function is to initialize touch panel module.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/

void touch_custom_init(void)
{   
   TouchPanel_custom_data_struct *tp_data;
   
#if defined(__TOUCH_PANEL_CAPACITY__)
   ctp_fun_ptr = ctp_GetFunc();
   ctp_fun_ptr->ctp_init();
#endif //#if defined(__TOUCH_PANEL_CAPACITY__)
   tp_fun_ptr=tp_GetFunc();
   tp_data = tp_fun_ptr->tp_get_data();   

#if defined(DRV_TOUCH_PANEL_CUSTOMER_PARAMETER)
   
   #if defined(TRULY_HVGA_LCM)
   TP_CALI_CHECK_OFFSET = 12;
   #else
   TP_CALI_CHECK_OFFSET = tp_data->touch_panel_cali_check_offset;
   #endif

   TS_DEBOUNCE_TIME = tp_data->ts_debounce_time;
   TP_MIN_PEN_MOVE_OFFSET = tp_data->min_pen_move_offset;
   TP_HAND_WRITING_MAX_OFFSET = tp_data->hand_writing_max_offset;
   TP_NONHAND_WRITING_MAX_OFFSET = tp_data->nonhand_writing_max_offset;
   TP_MAX_STROKE_MOVE_OFFSET = tp_data->max_stroke_move_offset;
   TP_PRESSURE_THRESHOLD_HIGH = tp_data->touch_pressure_threshold_high;
#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
   TP_MULTIPLE_POINT_SELECTION = tp_data->multiple_point_selection;
   TP_MULTIPLE_POINT_SELECTION = (TP_MULTIPLE_POINT_SELECTION < 3)?3:TP_MULTIPLE_POINT_SELECTION;
   TP_MULTIPLE_POINT_SELECTION = (TP_MULTIPLE_POINT_SELECTION > 32)?32:TP_MULTIPLE_POINT_SELECTION;	
#endif //#if defined(DRV_TOUCH_PANEL_MULTIPLE_PICK)
#if defined(__DRV_TP_DISCARD_SHIFTING__)
   TP_PRESSURE_CHECK_BOUNDARY = tp_data->pressure_check_boundary;
   TP_PRESSURE_SHIFTING_BOUNDARY = tp_data->pressure_shifting_boundary;
#endif //#if defined(__DRV_TP_DISCARD_SHIFTING__)
#endif //#if defined(DRV_TOUCH_PANEL_CUSTOMER_PARAMETER)
   TP_FILTER_THRESHOLD=tp_data->touch_panel_filter_thresold;

   TP_ADC_X_START=tp_data->x_adc_start;
   TP_ADC_X_END=tp_data->x_adc_end;
   TP_ADC_Y_START=tp_data->y_adc_start;
   TP_ADC_Y_END=tp_data->y_adc_end;
   TP_SCREEN_X_START=tp_data->x_coord_start;
   TP_SCREEN_X_END=tp_data->x_coord_end;
   TP_SCREEN_Y_START=tp_data->y_coord_start;
   TP_SCREEN_Y_END=tp_data->y_coord_end;
   TP_SCREEN_X_MILLIMETER=tp_data->x_millimeter;
   TP_SCREEN_Y_MILLIMETER=tp_data->y_millimeter;
   touch_panel_state= (kal_bool)tp_data->eint_down_level;
   
   TP_BORDER_PASS_CRITERION = 2000;
   TP_BORDER_RANGE = 5000;
   TP_NON_BORDER_PASS_CRITERION = 2000;
   TP_JITTER_CIRCUIT_INTERNAL = 15000;
   TP_DUMP_SCREEN = 0;
#if defined(__TOUCH_PANEL_MULTITOUCH__)
   tp_multiple_init(tp_data);
#endif //#if defined(__TOUCH_PANEL_MULTITOUCH__)

	#if defined(__PORTRAIT_LCM_SIMULATE_LANDSCAPE_LCM__) || defined(__LCM_SCANLINE_ROTATION_SUPPORT__)
	{
		// Swap X-axis and Y-axis ADC value for Portrait LCM simuates Landscape LCM
		// For this condition, driver reports X-axis coordinate value by refering TP Y-axis ADC value
		//                     driver reports Y-axis coordinate value by refering TP X-axis ADC value
		kal_uint32 swap_tmp;
		// Swap TP_ADC_X_START, TP_ADC_Y_START
		swap_tmp = TP_ADC_X_START;
		TP_ADC_X_START = TP_ADC_Y_START;
		TP_ADC_Y_START = swap_tmp;
		// Swap TP_ADC_X_END, TP_ADC_Y_END
		swap_tmp = TP_ADC_X_END;
		TP_ADC_X_END = TP_ADC_Y_END;
		TP_ADC_Y_END = swap_tmp;
		
		swap_tmp = TP_SCREEN_X_MILLIMETER;
		TP_SCREEN_X_MILLIMETER = TP_SCREEN_Y_MILLIMETER;
		TP_SCREEN_Y_MILLIMETER = swap_tmp;
		
	}
	#endif // #if defined(__PORTRAIT_LCM_SIMULATE_LANDSCAPE_LCM__)
   drv_trace8(TRACE_GROUP_10, TP_CUSTOM_SETTING, TP_ADC_X_START, TP_ADC_X_END, TP_ADC_Y_START, TP_ADC_Y_END, 
   				TP_SCREEN_X_START, TP_SCREEN_X_END, TP_SCREEN_Y_START, TP_SCREEN_Y_END);
   
}  
   	

/*touch panel initialization*/
void touch_panel_init(void)
{
	// kal_uint8 itmp;
	   DCL_HANDLE handle; 
   touch_custom_init();                              
   /*external interrupt*/
#if defined(DRV_TP_NO_EXT_EINT)
   TP.hts_handle=DclHTS_Open(TOUCH_PANEL_R,0);
   DclHTS_Initialize();
    
#elif defined(__TOUCH_PANEL_CAPACITY__)
   TP.eint_chan=custom_eint_get_channel(touch_panel_eint_chann);
   EINT_Set_HW_Debounce(TP.eint_chan, 0);
   EINT_Registration(TP.eint_chan,KAL_FALSE,touch_panel_state,touch_panel_capacitive_HISR, KAL_TRUE);
#else
   TP.eint_chan=custom_eint_get_channel(touch_panel_eint_chann);
   EINT_Set_HW_Debounce(TP.eint_chan, 10);
   EINT_Registration(TP.eint_chan,KAL_TRUE,touch_panel_state,touch_panel_HISR, KAL_TRUE);   
#endif
   TP_MASK_INT;
   /*event call back*/
  // change to DCL interface
    handle=DclSTS_Open(DCL_TS,0);
     DclSTS_RegisterCallback(handle, DCL_EVENT_STS_PUSH_BUFF, touch_panel_sendilm);
	 
	 #if defined(__TOUCH_PANEL_CAPACITY__)
  		DclSTS_RegisterCallback(handle,DCL_EVNET_STS_DOWN,touch_panel_capacitive_down_hdr);
   		DclSTS_RegisterCallback(handle,DCL_EVENT_STS_UP,touch_panel_capacitive_up_hdr);
	#elif defined(__TOUCH_PANEL_MULTITOUCH__)
   		DclSTS_RegisterCallback(handle,DCL_EVNET_STS_DOWN,touch_panel_dual_down_hdr);
   		DclSTS_RegisterCallback(handle,DCL_EVENT_STS_UP,touch_panel_dual_up_hdr);
	#else
   		DclSTS_RegisterCallback(handle,DCL_EVNET_STS_DOWN,touch_panel_down_hdr);
   		DclSTS_RegisterCallback(handle,DCL_EVENT_STS_UP,touch_panel_up_hdr);
	#endif//#if defined(__TOUCH_PANEL_CAPACITY__)
     DclSTS_Close(handle);	
	  
   /*get gpt handle*/
   //itmp = GPTI_GetHandle(&touch_panel_handle);
   touch_panel_handle=DclSGPT_Open(DCL_GPT_CB,0);
   //itmp = GPTI_GetHandle(&touch_panel_repeat_handle);
   touch_panel_repeat_handle=DclSGPT_Open(DCL_GPT_CB,0); 
	#if defined(__READ_TP_DATA_IN_HISR__)
	//	itmp = GPTI_GetHandle(&touch_panel_irq_en_handle);
#ifndef DRV_TP_SLIM
   touch_panel_irq_en_handle=DclSGPT_Open(DCL_GPT_CB,0); 
#endif 

	#endif // #if defined(__READ_TP_DATA_IN_HISR__)
	
   /*configure default pen/move offset*/
   touch_panel_conf_move_offset_(TP_MIN_PEN_MOVE_OFFSET, TP_MAX_STROKE_MOVE_OFFSET, 10,10);
   /*buff full flag*/
   TP.is_buff_full=KAL_FALSE;
   TP.wait_next_down=KAL_FALSE;

#if defined(DRV_TOUCH_PANEL_PAIR_GUARANTEE)
   TP.buffer_push_stat = TP_UNKNOWN_EVENT;
#endif //#if defined(DRV_TOUCH_PANEL_PAIR_GUARANTEE)
   /*cali*/   
   touch_panel_tuning(TP_SCREEN_X_START, TP_ADC_X_START, TP_SCREEN_X_END, TP_ADC_X_END, &TPCali.x_slope, &TPCali.x_offset);
   touch_panel_tuning(TP_SCREEN_Y_START, TP_ADC_Y_START, TP_SCREEN_Y_END, TP_ADC_Y_END, &TPCali.y_slope, &TPCali.y_offset);
   //touch_panel_start_cali(coord, 2);
}
/*The following are for tests*/
void touch_panel_test(void)
{
    TouchPanelHandAreaStruct handarea[2]=
    {
                                         {{0,0},
            {88,110}
        },
                                         {{0,0},
            {88,110}
        }
   };

   TouchPanelHandAreaStruct ext_handarea={ {1,1},
        {176,220}
    };
 	/*MMI should call the following function*/
	touch_panel_enable_(KAL_TRUE); 		
	touch_panel_conf_handwriting_(handarea,2,&ext_handarea);
	touch_panle_conf_sample_period_(10, 1);/*100ms, 20ms*/		
	touch_panle_conf_timeout_period_(200,100, 200);/*2s, 1s, 2s*/	   	  
}
void tp_area_change_to_event(void)
   {
    TouchPanelHandAreaStruct handarea[2]=
    {
                                         {{0,0},
            {0,0}
        },
                                         {{1,1},
            {1,1}
        }
                                         };
   TouchPanelHandAreaStruct ext_handarea={ {1,1},
        {176,220}
    };
   touch_panel_conf_handwriting_(handarea,2,&ext_handarea);                                           
   touch_panel_reset_handwriting_();
			}
void tp_area_change_to_stroke(void)
{
    TouchPanelHandAreaStruct handarea[2]=
    {
                                         {{0,0},
            {175,219}
        },
                                         {{1,1},
            {176,219}
        }
                                         };
   TouchPanelHandAreaStruct ext_handarea={ {1,1},
        {176,220}
    };
   touch_panel_conf_handwriting_(handarea,2,&ext_handarea);
   touch_panel_reset_(KAL_TRUE);
}

void tp_cali_test(void)   
{
    TouchPanelCoordStruct coord[2]=
    {
                                    {0,0},
                                    {176,220}
                                  };
   touch_panel_start_cali_(coord, 2);
}

void tp_cali_end_test(void)
{
   touch_panel_stop_cali_();
}

void tp_kp_control(kal_uint8 key)
{
   switch (key)
   {
      case 1:
         tp_area_change_to_event();
      break;
      case 2:
         tp_area_change_to_stroke();    
      break;
      case 3:
         tp_cali_test();
      break;    
      case 4:
         tp_cali_end_test();
      break;
      case 5:
         touch_panel_reset_handwriting_();                     
      break;
      default:
      break;
   }
}

#if defined(__TOUCH_PANEL_MULTITOUCH__)

kal_bool touch_panel_dual_peek_event(TouchPanelMultipleEventStruct *touch_data)
{
	kal_bool result;
	kal_uint8  i;
	ASSERT(touch_data);
	IRQMask(IRQ_GPT_CODE);
	/* only mask eint when it's unmasked. */
	
	if(touch_panel_data_buffer.touch_buffer_rindex != touch_panel_data_buffer.touch_buffer_windex)
	{
		touch_panel_multipel_touch_retrieve_event(touch_data, &touch_panel_data_buffer.touch_buffer_rindex, KAL_FALSE);
		for(i=0; i<touch_data->model; i++)
		{
			drv_trace4(TRACE_GROUP_10, TP_GET_EVENT, touch_data->points[i].event,  touch_data->points[i].x,  touch_data->points[i].y, 0);
		}
		result = KAL_TRUE;
	}
	else
	{
	   send_touch_ilm = KAL_TRUE;
	   result = KAL_FALSE;
	}
	IRQUnmask(IRQ_GPT_CODE);
	TP_DBG(__LINE__, ust_get_current_time(), touch_panel_data_buffer.touch_buffer_rindex, touch_panel_data_buffer.touch_buffer_windex);
	return result;
}

kal_bool touch_panel_dual_get_event(TouchPanelMultipleEventStruct *touch_data)
{
	kal_bool result;
	kal_uint16  i;

	ASSERT(touch_data);
	IRQMask(IRQ_GPT_CODE);
	
	if(TP.is_buff_full==KAL_TRUE)
	{
		touch_panel_multipel_touch_retrieve_event(touch_data, &touch_panel_data_buffer.touch_buffer_rindex, KAL_FALSE);
		for(i=0; i<touch_data->model; i++)
		{
			touch_data->points[i].event = PEN_ABORT;
			touch_data->points[i].x = 0;
			touch_data->points[i].y = 0;
			touch_data->points[i].z = 0;
		}
		IRQUnmask(IRQ_GPT_CODE);
		return KAL_TRUE;
	}
	if(touch_panel_data_buffer.touch_buffer_rindex != touch_panel_data_buffer.touch_buffer_windex)
	{
		touch_panel_multipel_touch_retrieve_event(touch_data, &touch_panel_data_buffer.touch_buffer_rindex, KAL_TRUE);
		for(i=0; i<touch_data->model; i++)
		{
			drv_trace4(TRACE_GROUP_10, TP_GET_EVENT, touch_data->points[i].event,  touch_data->points[i].x,  touch_data->points[i].y, 0);
		}
		result = KAL_TRUE;
	}
	else
	{
	   send_touch_ilm = KAL_TRUE;
	   result = KAL_FALSE;
	}

	IRQUnmask(IRQ_GPT_CODE);
	TP_DBG(__LINE__, ust_get_current_time(), touch_panel_data_buffer.touch_buffer_rindex, touch_panel_data_buffer.touch_buffer_windex);
	return result;
}

static kal_bool touch_panel_dual_event_cb(TouchPanelMultipleEventStruct* tp_event)
{
	kal_bool valid_event;
#if defined(__DRV_TP_DISCARD_SHIFTING__)
	kal_uint32 pressure2=0;
#endif //#if defined(__DRV_TP_DISCARD_SHIFTING__)
#if defined(DRV_ADC_TOUCH_SCREEN)
	HTS_CTRL_DATA_T tp_state;	
	drv_trace1(TRACE_GROUP_10, TP_EVENT_CB_START,  ust_get_current_time());
	SLA_CustomLogging("TDW",1); 
	DclHTS_Control(TP.hts_handle,HTS_CMD_GET_TP_LEVEL_PRESSURE,&tp_state);  //tp_level_pressure 
	tp_event->points[0].z=tp_state.rTSCtrlTL.pressure_value;
	if ((kal_bool)touch_up_level == tp_state.rTSCtrlTL.fgIsUP)
	{
#ifdef DRV_TP_PENUP_FIXED  //if up irq don't lost, so just wait for pen irq
        return KAL_FALSE;
#else
		DclHTS_Control(TP.hts_handle,HTS_CMD_TP_UPDATENOTIFY,0);
		SLA_CustomLogging("TDW",0);
		drv_trace1(TRACE_GROUP_10, TP_EVENT_CB_END,  ust_get_current_time());
		return KAL_FALSE;
#endif
	}
#endif // #if defined(DRV_ADC_TOUCH_SCREEN)

#ifdef TOUCH_PANEL_PRESSURE
	if ((kal_bool)touch_up_level != tp_state.rTSCtrlTL.fgIsUP)
#endif
	{
		touch_panel_read_adc(&tp_event->points[0].x, &tp_event->points[0].y);
		valid_event=touch_panel_adc_to_coordinate(&tp_event->points[0].x,&tp_event->points[0].y);/*translate*/		
		if(valid_event)
		{
#if defined(__DRV_TP_DISCARD_SHIFTING__)
			if( (KAL_FALSE == tp_pressure_check_value(&pressure2))
			|| touch_panle_pressure_shift_check(tp_event->points[0].z, pressure2) )
			{
				touch_panel_multiple_touch_set_timer(KAL_TRUE); //set next timer then check again.
				return KAL_FALSE;
			}
#endif //#if defined(__DRV_TP_DISCARD_SHIFTING__)
			if(TP_DUAL)
				tp_multiple_touch_cb_get_2nd_point(tp_event);
		}//if(valid)
	}
	SLA_CustomLogging("TDW",0); 
	drv_trace1(TRACE_GROUP_10, TP_EVENT_CB_END,  ust_get_current_time());
	return KAL_TRUE;
}

void touch_panel_dual_down_hdr(DCL_EVENT event)
{
	kal_uint32 i=0, pressure;
	TouchPanelMultipleEventStruct tp_event;
	kal_bool valid=KAL_FALSE;
	
#if defined(DRV_ADC_TOUCH_SCREEN)
	// Check if we lost up intr
    if (tp_up_intr_lost_flag == KAL_TRUE)
    {
		// Stop sampling data no matter what is done in touch_panel_up_hdr()
		touch_panel_multiple_touch_stop_timer();
		// Perform up handler first
		touch_panel_dual_up_hdr(NULL);
		tp_up_intr_lost_flag = KAL_FALSE;
}
#endif // #if defined(DRV_ADC_TOUCH_SCREEN)

	TP.skip_unrelease_state=KAL_FALSE;
	Touch_Panel_first_valid = KAL_FALSE;
	drv_trace0(TRACE_GROUP_10, TP_DOWN_HDR);

#if defined(__READ_TP_DATA_IN_HISR__)
	tp_event.points[0].x = gX;
	tp_event.points[0].y = gY;
#else	// Non share pin design, read data from tp controller
	touch_panel_read_adc(&tp_event.points[0].x, &tp_event.points[0].y);
#endif // #if !defined(__READ_TP_DATA_IN_HISR__)
	
	touch_excute_cali( tp_event.points[0].x, tp_event.points[0].y);
#ifdef TOUCH_PANEL_PRESSURE
#if defined(__READ_TP_DATA_IN_HISR__)
	pressure = gPressure;
	if(KAL_FALSE == gPressureCheck)
#else
	// Non share pin, read tp pressure info
	if (KAL_FALSE == tp_pressure_check_value(&pressure))
#endif // #if defined(__READ_TP_DATA_IN_HISR__)
{
		drv_trace0(TRACE_GROUP_10, TP_WAIT_NEXT_SET_TRUE);
		TP.wait_next_down=KAL_TRUE;
		return;
}
	tp_event.points[0].z = pressure;
#endif

	valid=touch_panel_adc_to_coordinate(&tp_event.points[0].x, & tp_event.points[0].y);/*tranlate*/            
	if(valid==KAL_TRUE)
	{
		if(TP_DUAL)
			tp_multiple_touch_down_get_2nd_point(&tp_event);
		TP.wait_next_down=KAL_FALSE;
	}
	else
{
		drv_trace0(TRACE_GROUP_10, TP_WAIT_NEXT_TRUE);
		TP.wait_next_down=KAL_TRUE;
		return;
}
	TP.area = touch_panel_area_check(tp_event.points[0].x, tp_event.points[0].y);

	for(i=0; i<tp_event.model; i++)
	{
		if(TP.area == HAND_WRITING) //if the first 
		{
			tp_event.points[i].event = STROKE_DOWN;
#if defined(DRV_ADC_TOUCH_SCREEN)
       TP_Stroke_Up_Count = 0;
#endif //#if defined(DRV_ADC_TOUCH_SCREEN)
		}
		else/*non-handwriting*/
		{
			tp_event.points[i].event = PEN_DOWN;
		}
	}
	tp_event.time_stamp = L1I_GetTimeStamp();
	touch_panel_multiple_touch_data_push(&tp_event);
	touch_panel_multiple_touch_set_timer(KAL_TRUE);
}

void touch_panel_dual_up_hdr(DCL_EVENT event)
{
	kal_uint32 i=0;
	TouchPanelMultipleEventStruct tp_event;

	/*check if the down point is reasonable*/
	if(TP.wait_next_down == KAL_TRUE)
		return;

	if(TP.skip_unrelease_state==KAL_FALSE)
	{
		touch_panel_multiple_touch_stop_timer();

		if(tp_cali_mode == TP_DUAL_CALIBRATION_MODE)
		{
			if(tp_multiple_dual_cali_pass(tp_dual_cali_mode))
			{
				tp_dual_cali_mode++;
				touch_panel_send_msg(KAL_TRUE, tp_dual_cali_mode);
				if(tp_dual_cali_mode == TP_CALI_FINISH)
				{
					tp_cali_mode = TP_FINISH_CALIBRATION_MODE;
					tp_multiple_touch_save_calibration();
				}
			}
		}
   		
		touch_panel_multipel_touch_retrieve_event(&tp_event, &touch_panel_data_buffer.touch_buffer_last_windex, KAL_FALSE); //not increase index
		if(TP.area == HAND_WRITING) //already all up in last event.
		{
			if(tp_event.points[0].event == STROKE_UP)
			{
				drv_trace0(TRACE_GROUP_4, CTP_UP_HDR_STROKE_UP_AGAIN);
				return;
			}
		}
		else/*non-handwriting*/
		{
			if(tp_event.points[0].event == PEN_UP)
			{
				drv_trace0(TRACE_GROUP_4, CTP_UP_HDR_PEN_UP_AGAIN);
				return;
			}
		}
		for(i=0; i<tp_event.model; i++) //set all exist event as UP
		{
			if((tp_event.points[i].event == PEN_UP)||(tp_event.points[i].event == STROKE_UP))
			{
				tp_event.model = i; //all other points already up in last event
				break;
			}
			else if(TP.area == HAND_WRITING) //if the first 
			{
				tp_event.points[i].event = STROKE_UP;
			}
			else/*non-handwriting*/
			{
				tp_event.points[i].event = PEN_UP;
			}
		}
		tp_event.time_stamp = L1I_GetTimeStamp();
		touch_panel_multiple_touch_data_push(&tp_event);
	}
	else
    {
        /*TP.skip_unrelease_state==KAL_TRUE*/
		TP.skip_unrelease_state=KAL_FALSE;   
	}
}

#endif //#if defined(__TOUCH_PANEL_MULTITOUCH__)

#if defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)
static void TP_STATUS_FUNC_ABSOLUTE(kal_int16 *x_diff, kal_int16 *y_diff)
{
	if(*x_diff < 0) 
		*x_diff = -*x_diff;
	if(*y_diff < 0)
		*y_diff = -*y_diff;	
}
static kal_uint16 TP_ASSERT_STATUS_FUNC(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 count)
{
	ASSERT(0);
	return 0;
}
static kal_uint16 TP_PEN_DOWN_STATUS_FUNC(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 count)
{
	tp_accum_plh_x_diff[count] = tp_accum_plh_y_diff[count] = 0; //reset the difference whenever pen down.
	tp_accum_prh_x_diff[count] = tp_accum_prh_y_diff[count] = 0; //otherwise it would accumulate last pen down-up diff.

	tp_state_count[count] = 0;
	tp_state_start_tick[count] = drv_get_current_time();

	if(TP.longtap_pen_offset == 0) //cosmos already handle longtap, do not need to check longtap
		return TP_STATUS_FUNC[PEN_MOVE](x_diff, y_diff, count);

	TP_STATUS_FUNC_ABSOLUTE(&x_diff, &y_diff);//otherwise compare with kal_uint16 will cause always larger
	if(x_diff>TP.longtap_pen_offset || y_diff>TP.longtap_pen_offset)
	{
		return PEN_MOVE;
	}
	else
		return PEN_LONGTAP_HOLD; //it may change to PEN_LOGNTAP in timer check.
}
static kal_uint16 TP_PEN_MOVE_STATUS_FUNC(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 count)
{
	tp_state_count[count] = 0;
	tp_state_start_tick[count] = drv_get_current_time();
	TP_STATUS_FUNC_ABSOLUTE(&x_diff, &y_diff);//otherwise compare with kal_uint16 will cause always larger
	if(x_diff>TP.pen_offset || y_diff>TP.pen_offset)
		return PEN_MOVE;
	else
		return PEN_REPEAT_HOLD; //it may change to PEN_REPEAT in timer check.
}
static kal_uint16 TP_STROKE_MOVE_STATUS_FUNC(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 count)
{
	tp_state_count[count] = 0;
	tp_state_start_tick[count] = drv_get_current_time();
	TP_STATUS_FUNC_ABSOLUTE(&x_diff, &y_diff);//otherwise compare with kal_uint16 will cause always larger
	if(x_diff>TP.storke_offset||y_diff>TP.storke_offset)
	{
		return STROKE_MOVE;
	}
	else
		return STROKE_STATICAL;
}
static kal_uint16 TP_STROKE_HOLD_STATUS_FUNC(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 count)
{
	if(TP.longtap_stroke_offset == 0) //cosmos already handle longtap, do not need to check longtap
		return TP_STATUS_FUNC[STROKE_MOVE](x_diff, y_diff, count);
	
	tp_state_count[count]++;
	tp_accum_sh_x_diff[count] += x_diff;
	tp_accum_sh_y_diff[count] += y_diff;
	if((tp_accum_sh_x_diff[count] &&(tp_accum_sh_x_diff[count]>TP.longtap_stroke_offset))  ||
		 (tp_accum_sh_y_diff[count] &&(tp_accum_sh_y_diff[count]>TP.longtap_stroke_offset))  ||
		 (-tp_accum_sh_x_diff[count]&&(-tp_accum_sh_x_diff[count]>TP.longtap_stroke_offset)) ||
		 (-tp_accum_sh_y_diff[count]&&(-tp_accum_sh_y_diff[count]>TP.longtap_stroke_offset)) )
	{
		tp_accum_sh_x_diff[count] = tp_accum_sh_y_diff[count] = 0;
		return STROKE_MOVE;
	}
	else
	{
		if(drv_get_duration_ms(tp_state_start_tick[count]) >= TP.handwriting_longtap_cnt*10)
		{
			tp_accum_sh_x_diff[count] = tp_accum_sh_y_diff[count] = 0;
			return STROKE_LONGTAP;
		}
	}
	return STROKE_HOLD;
}
static kal_uint16 TP_PEN_LONGTAP_HOLD_STATUS_FUNC(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 count)
{
	if(TP.longtap_pen_offset == 0) //cosmos already handle longtap, do not need to check longtap
		return TP_STATUS_FUNC[PEN_MOVE](x_diff, y_diff, count);
	
	tp_state_count[count]++;
	tp_accum_plh_x_diff[count] += x_diff;
	tp_accum_plh_y_diff[count] += y_diff;
	if((tp_accum_plh_x_diff[count] &&(tp_accum_plh_x_diff[count]>TP.longtap_pen_offset))  ||
		 (tp_accum_plh_y_diff[count] &&(tp_accum_plh_y_diff[count]>TP.longtap_pen_offset))  ||
		 (-tp_accum_plh_x_diff[count]&&(-tp_accum_plh_x_diff[count]>TP.longtap_pen_offset)) ||
		 (-tp_accum_plh_y_diff[count]&&(-tp_accum_plh_y_diff[count]>TP.longtap_pen_offset)) )
	{
		tp_accum_plh_x_diff[count] = tp_accum_plh_y_diff[count] = 0;
		return PEN_MOVE;
	}
	else
	{
		if(drv_get_duration_ms(tp_state_start_tick[count]) >= TP.longtap_cnt*10)
		{
			tp_accum_plh_x_diff[count] = tp_accum_plh_y_diff[count] = 0;
			return PEN_LONGTAP;
		}
		else
		{
			return PEN_LONGTAP_HOLD; //it may change to PEN_LOGNTAP in timer check.
		}
	}
}
static kal_uint16 TP_PEN_REPEAT_HOLD_STATUS_FUNC(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 count)
{
	tp_state_count[count]++;
	tp_accum_prh_x_diff[count] += x_diff;
	tp_accum_prh_y_diff[count] += y_diff;
	if((tp_accum_prh_x_diff[count] &&(tp_accum_prh_x_diff[count]>TP.pen_offset))  ||
		 (tp_accum_prh_y_diff[count] &&(tp_accum_prh_y_diff[count]>TP.pen_offset))  ||
		 (-tp_accum_prh_x_diff[count]&&(-tp_accum_prh_x_diff[count]>TP.pen_offset)) ||
		 (-tp_accum_prh_y_diff[count]&&(-tp_accum_prh_y_diff[count]>TP.pen_offset)) )
	{
		tp_accum_prh_x_diff[count] = tp_accum_prh_y_diff[count] = 0;
		return PEN_MOVE;
	}
	else
	{
		if(drv_get_duration_ms(tp_state_start_tick[count]) >= TP.repeat_cnt*10)
		{
			tp_accum_prh_x_diff[count] = tp_accum_prh_y_diff[count] = 0;
			return PEN_REPEAT;
		}
		else
			return PEN_REPEAT_HOLD; //it may change to PEN_REPEAT in timer check.
	}
}
static kal_uint16 TP_STROKE_DOWN_STATUS_FUNC(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 count)
{
	tp_accum_sh_x_diff[count] = tp_accum_sh_y_diff[count] = 0; //reset the difference whenever stroke down.//otherwise it would accumulate last pen down-up diff.
	if(TP.longtap_pen_offset == 0) //cosmos already handle longtap, do not need to check longtap
		return TP_STATUS_FUNC[STROKE_MOVE](x_diff, y_diff, count);

	tp_state_count[count] = 0;
	tp_state_start_tick[count] = drv_get_current_time();
	TP_STATUS_FUNC_ABSOLUTE(&x_diff, &y_diff);//otherwise compare with kal_uint16 will cause always larger
	if(x_diff>TP.longtap_stroke_offset||y_diff>TP.longtap_stroke_offset)/*handwriting long tap*/
	{
		return STROKE_MOVE;
	}
	return STROKE_HOLD;
}

kal_uint16 touch_panel_multiple_touch_state_machine(kal_int16 x_diff, kal_int16 y_diff, kal_uint16 pre_event, kal_uint16 count)
{
	drv_trace4(TRACE_GROUP_4, CTP_STATE_MACHINE, x_diff, y_diff, pre_event, count);

	if(pre_event==STROKE_DOWN)
		pre_event = STROKE_DOWN_;
	else if(pre_event==STROKE_LONGTAP)
		pre_event = STROKE_LONGTAP_;
	else if(pre_event==STROKE_UP)
		pre_event = STROKE_UP_;

	return TP_STATUS_FUNC[pre_event](x_diff, y_diff, count);
}

static void touch_panel_multiple_touch_data_push(TouchPanelMultipleEventStruct *push_event)
{
	kal_uint16 model;
	kal_uint16 roomleft=0;
	kal_uint8 *wptr, *sptr;
	kal_uint32 len, i;
	//kal_uint32 avail_len, overflow_len;
			
	IRQMask(IRQ_GPT_CODE);
	/* only mask eint when it's unmasked. */
	if (tp_eint_mask == KAL_FALSE)
		TP_MASK_INT;   

	if(TP.is_buff_full==KAL_TRUE)
	   return;
	tp_get_buf_roomleft(roomleft);   
	drv_trace4(TRACE_GROUP_9, TP_DATA_POP, push_event->points[0].event, push_event->points[0].x, push_event->points[0].y, roomleft);

	if(roomleft<=BASIC_EVENT_UNIT)
	{
	    TP.is_buff_full=KAL_TRUE;
	    if (tp_eint_mask == KAL_FALSE)
	    	TP_UNMASK_INT;
	    IRQUnmask(IRQ_GPT_CODE);
	    return;
}

	model = push_event->model;

	touch_panel_data_buffer.touch_buffer_last_windex = touch_panel_data_buffer.touch_buffer_windex; //save last windex

	len =TP_EVENT_HEADER+8*model; //check the length over buffer size or not
	drv_trace4(TRACE_GROUP_4, CTP_DATA_PUSH, len, model, touch_panel_data_buffer.touch_buffer_windex, 0);

	sptr = (kal_uint8 *)push_event;
	for(i=0; i<len; i++)
	{
		wptr = &touch_panel_data_buffer.touch_panel_data[touch_panel_data_buffer.touch_buffer_windex];
		*wptr = *(sptr+i);
		touch_panel_data_buffer.touch_buffer_windex++;
		if(touch_panel_data_buffer.touch_buffer_windex >= TOUCH_PANEL_BUFFER_SIZE)
			touch_panel_data_buffer.touch_buffer_windex = 0;
}

	TP.touch_panel_event_cb(TP.cb_para, (Touch_Panel_Event_enum)push_event->points[0].event); // default send ilm to UEM.
	if (tp_eint_mask == KAL_FALSE)
		TP_UNMASK_INT;
	IRQUnmask(IRQ_GPT_CODE);
}

void touch_panel_multiple_touch_stop_timer(void)
{
	DclSGPT_Control(touch_panel_handle,SGPT_CMD_STOP,0);
}

void touch_panel_multiple_touch_set_timer(kal_bool higher_sampling_rate)
{
	SGPT_CTRL_START_T start;
	start.pfCallback = touch_panel_multiple_touch_event_cb;
	start.vPara = NULL;
	
	IRQMask(IRQ_GPT_CODE);
	if(higher_sampling_rate && (!kal_if_hisr()) && (!kal_if_lisr())) //TP task pen down
		start.u2Tick=0;
	else if(!Touch_Panel_first_valid && higher_sampling_rate) //not get first valid event and under GPT call back
		start.u2Tick=1;
	else if(((TP.area == HAND_WRITING)) && (TP.high_sample_period!=0))
		start.u2Tick=TP.high_sample_period;
	else if(TP.low_sample_period!=0)
		start.u2Tick=TP.low_sample_period;
	else
		start.u2Tick=1; //default value;

	DclSGPT_Control(touch_panel_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
	IRQUnmask(IRQ_GPT_CODE);
}

kal_bool touch_panel_multiple_touch_check_event_valid(TouchPanelMultipleEventStruct *tp_event)
{
	kal_uint32 i;
	
	for(i=0;i<tp_event->model;i++)
	{
		if( (tp_event->points[i].event<STROKE_STATICAL) || (tp_event->points[i].event>PEN_REPEAT_HOLD))
		{
			Touch_Panel_first_valid = KAL_TRUE;
			return KAL_TRUE;
		}
	}
	return KAL_FALSE;
}

void touch_panel_multiple_touch_event_handler(TouchPanelMultipleEventStruct *tp_event, TouchPanelMultipleEventStruct *last_tp_event)
{
// This API may increase ctp->model, it depends on the pen up counts.
	kal_uint32 i=0, event;
	kal_int16 x_diff, y_diff;
	kal_uint32 event_need_handle;
	
	event_need_handle = (last_tp_event->model > tp_event->model)?last_tp_event->model:tp_event->model;
	//the last->model may include up event.
	//the ctp->model do not include up event	
	drv_trace2(TRACE_GROUP_4, CTP_EVENT_HANDLER, last_tp_event->model, tp_event->model);
	
	for(i=0; i<event_need_handle; i++) //check all points which needed to be handle
	{
		if(i >= tp_event->model) //not included in this time, MUST be up.
		{
			if((last_tp_event->points[i].event == PEN_UP) ||
			   (last_tp_event->points[i].event == STROKE_UP))
			{
				drv_trace0(TRACE_GROUP_4, CTP_UP_HDR_PEN_UP_AGAIN);
				event_need_handle = i;
				break;
			}
			else if(TP.area == HAND_WRITING)
			{
				event = STROKE_UP;
				tp_event->points[i].x = last_tp_event->points[i].x;
				tp_event->points[i].y = last_tp_event->points[i].y;
				tp_event->points[i].z = last_tp_event->points[i].z;
				drv_trace1(TRACE_GROUP_4, CTP_EVENT_HANDLER_STROKE_UP, i);
			}
			else
			{
				event = PEN_UP;
				tp_event->points[i].x = last_tp_event->points[i].x;
				tp_event->points[i].y = last_tp_event->points[i].y;
				tp_event->points[i].z = last_tp_event->points[i].z;
				drv_trace1(TRACE_GROUP_4, CTP_EVENT_HANDLER_PEN_UP, i);
			}
		}
		else if((i >= last_tp_event->model) || //new down
		(last_tp_event->points[i].event == PEN_UP) ||
		(last_tp_event->points[i].event == STROKE_UP))
		{
			if(TP.area == HAND_WRITING)
			{
				event = STROKE_DOWN;
				drv_trace1(TRACE_GROUP_4, CTP_EVENT_HANDLER_STROKE_DOWN, i);
			}
			else
			{
				event = PEN_DOWN;
				drv_trace1(TRACE_GROUP_4, CTP_EVENT_HANDLER_PEN_DOWN, i);
			}
		}
		else  // still down
		{
			x_diff = tp_event->points[i].x - last_tp_event->points[i].x;
			y_diff = tp_event->points[i].y - last_tp_event->points[i].y;
			event = touch_panel_multiple_touch_state_machine(x_diff, y_diff, last_tp_event->points[i].event, i);
			drv_trace1(TRACE_GROUP_4, CTP_STATE_MACHINE_RETURN, event);
		}
		tp_event->points[i].event = event;
	}
	tp_event->model = event_need_handle;
	//the last->model may include up event.
	//the ctp->model may include up event.
}



static void  touch_panel_multiple_touch_event_cb(void *parameter)
{
	kal_bool valid_event;
	TouchPanelMultipleEventStruct* tp_event;
	TouchPanelMultipleEventStruct  local_tp_event;
	kal_uint16 model;
	TouchPanelMultipleEventStruct last_tp_event;

#if defined(__TOUCH_PANEL_CAPACITY__)
	tp_event = (TouchPanelMultipleEventStruct*)&CTP_g_event;
#else //defined(__TOUCH_PANEL_MULTITOUCH__)
	tp_event = (TouchPanelMultipleEventStruct*)&local_tp_event;
	valid_event = touch_panel_dual_event_cb(tp_event);
	if(!valid_event) //if not valid, not sampling again.
		return;
#endif //#if defined(__TOUCH_PANEL_CAPACITY__)

	model = tp_event->model;

	touch_panel_multipel_touch_retrieve_event(&last_tp_event, &touch_panel_data_buffer.touch_buffer_last_windex, KAL_FALSE);
		
	touch_panel_multiple_touch_event_handler(tp_event, &last_tp_event); //feed PEN_MOVE or PEN_STATICAL
	
	valid_event = touch_panel_multiple_touch_check_event_valid(tp_event);
	tp_event->time_stamp = L1I_GetTimeStamp();
	touch_panel_multiple_touch_data_push(tp_event);
	if(valid_event)
	{
		touch_panel_multiple_touch_set_timer(KAL_FALSE);
	}
	else
	{
		if(tp_event->model != 0) //we need to know the event is up or just invalid event.
			touch_panel_multiple_touch_set_timer(KAL_TRUE);
	}
	tp_event->model = model;
}
 

static void touch_panel_multipel_touch_retrieve_event(TouchPanelMultipleEventStruct *tp_event, kal_uint16 *index, kal_bool increase_index)
{
	kal_uint16 model;
	kal_uint8  *wptr;
	kal_uint32 current_index, i, len;
	
	current_index = *index;
	model = touch_panel_data_buffer.touch_panel_data[current_index];
	
	//padding = touch_panel_data_buffer.touch_panel_data[current_index+2];
	

	wptr = (kal_uint8 *)tp_event;
	len =TP_EVENT_HEADER+8*model; //check the length over buffer size or not
	for(i=0; i<len; i++)
	{
		*(wptr+i) = touch_panel_data_buffer.touch_panel_data[*index];
		(*index)++;
		if(*index >= TOUCH_PANEL_BUFFER_SIZE)
			*index = 0;
  }
  if(increase_index == KAL_FALSE)
  	*index = current_index;

  ASSERT(model == tp_event->model);
}

#endif //#if defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)

#if defined(__TOUCH_PANEL_CAPACITY__)
void touch_panel_capacitive_power_on(kal_bool on)
{
	ctp_fun_ptr->ctp_power_on(on);
}

kal_bool touch_panel_capacitive_get_event(TouchPanelMultipleEventStruct *touch_data)
{
	kal_bool result;
	kal_uint16  i;

	ASSERT(touch_data);
	IRQMask(IRQ_GPT_CODE);
	/* only mask eint when it's unmasked. */
	if (tp_eint_mask == KAL_FALSE)
		TP_MASK_INT;   
   
	if(TP.is_buff_full==KAL_TRUE)
	{
		touch_panel_multipel_touch_retrieve_event(touch_data, &touch_panel_data_buffer.touch_buffer_rindex, KAL_FALSE);
		for(i=0; i<touch_data->model; i++)
		{
			touch_data->points[i].event = PEN_ABORT;
			touch_data->points[i].x = 0;
			touch_data->points[i].y = 0;
			touch_data->points[i].z = 0;
		}
		if (tp_eint_mask == KAL_FALSE)
			TP_UNMASK_INT;
		IRQUnmask(IRQ_GPT_CODE);
		return KAL_TRUE;
	}
	
	
	if(touch_panel_data_buffer.touch_buffer_rindex != touch_panel_data_buffer.touch_buffer_windex)
	{
		touch_panel_multipel_touch_retrieve_event(touch_data, &touch_panel_data_buffer.touch_buffer_rindex, KAL_TRUE);
		for(i=0; i<touch_data->model; i++)
		{
			drv_trace4(TRACE_GROUP_10, TP_GET_EVENT, touch_data->points[i].event,  touch_data->points[i].x,  touch_data->points[i].y, 0);
		}
		result = KAL_TRUE;
	}
	else
	{
	   send_touch_ilm = KAL_TRUE;
	   result = KAL_FALSE;
	}

	if (tp_eint_mask == KAL_FALSE)
		TP_UNMASK_INT;
	IRQUnmask(IRQ_GPT_CODE);
	TP_DBG(__LINE__, ust_get_current_time(), touch_panel_data_buffer.touch_buffer_rindex, touch_panel_data_buffer.touch_buffer_windex);
	return result;
}

/*************************************************************************
* FUNCTION
*	touch_panel_capacitive_peek_event
*
* DESCRIPTION
*	This function is to peek event from ring buffer.
*
* PARAMETERS
*	data: touch event
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool touch_panel_capacitive_peek_event(TouchPanelMultipleEventStruct *touch_data)
{
	kal_bool result;
	kal_uint8  i;

	ASSERT(touch_data);
	IRQMask(IRQ_GPT_CODE);
	/* only mask eint when it's unmasked. */
	if (tp_eint_mask == KAL_FALSE)
		TP_MASK_INT;   
	
	if(touch_panel_data_buffer.touch_buffer_rindex != touch_panel_data_buffer.touch_buffer_windex)
	{
		touch_panel_multipel_touch_retrieve_event(touch_data, &touch_panel_data_buffer.touch_buffer_rindex, KAL_FALSE);
		for(i=0; i<touch_data->model; i++)
		{
			drv_trace4(TRACE_GROUP_10, TP_GET_EVENT, touch_data->points[i].event,  touch_data->points[i].x,  touch_data->points[i].y, 0);
		}
		result = KAL_TRUE;
	}
	else
	{
	   send_touch_ilm = KAL_TRUE;
	   result = KAL_FALSE;
	}

	if (tp_eint_mask == KAL_FALSE)
		TP_UNMASK_INT;
	IRQUnmask(IRQ_GPT_CODE);
	TP_DBG(__LINE__, ust_get_current_time(), touch_panel_data_buffer.touch_buffer_rindex, touch_panel_data_buffer.touch_buffer_windex);
	return result;
}
kal_bool touch_panel_capacitive_to_coordinate(TouchPanelMultipleEventStruct *tp_event)
{
	kal_uint32 i=0;
	
	for(i=0; i<tp_event->model; i++) // check each point of last event in buffer. 
	{
		drv_trace4(TRACE_GROUP_4, CTP_CAPACITIVE_GET_DATA_RAW, i, tp_event->points[i].x, i, tp_event->points[i].y);
		tp_event->points[i].x = (kal_uint16)(TPCali.x_slope*tp_event->points[i].x+TPCali.x_offset);
		tp_event->points[i].y = (kal_uint16)(TPCali.y_slope*tp_event->points[i].y+TPCali.y_offset);
		#if defined(__PORTRAIT_LCM_SIMULATE_LANDSCAPE_LCM__) || defined(__LCM_SCANLINE_ROTATION_SUPPORT__)
		{
		// Swap X-axis and Y-axis ADC value for Portrait LCM simuates Landscape LCM
		// For this condition, driver reports X-axis coordinate value by refering TP Y-axis ADC value
		//                     driver reports Y-axis coordinate value by refering TP X-axis ADC value
			kal_int16 swap_temp;
			swap_temp = tp_event->points[i].x;
			tp_event->points[i].x = tp_event->points[i].y;
			tp_event->points[i].y = swap_temp;
}
		#endif

		if(tp_event->points[i].x < TP_SCREEN_X_START)
			tp_event->points[i].x = TP_SCREEN_X_START;
		else if(tp_event->points[i].x > TP_SCREEN_X_END)
			tp_event->points[i].x = TP_SCREEN_X_END;
	
		if(tp_event->points[i].y < TP_SCREEN_Y_START)
			tp_event->points[i].y = TP_SCREEN_Y_START;

		else if(tp_event->points[i].y > TP_SCREEN_Y_END)
			tp_event->points[i].y = TP_SCREEN_Y_END;

		drv_trace4(TRACE_GROUP_4, CTP_CAPACITIVE_GET_DATA, i, tp_event->points[i].x, i, tp_event->points[i].y);
	}
	
	if(tp_event->model == 1)
		drv_trace2(TRACE_GROUP_3, CTP_COORDINATE1, tp_event->points[0].x, tp_event->points[0].y);
	else if(tp_event->model == 2)
		drv_trace4(TRACE_GROUP_3, CTP_COORDINATE2, tp_event->points[0].x, tp_event->points[0].y,
		                                           tp_event->points[1].x, tp_event->points[1].y);
	else if(tp_event->model == 3)
		drv_trace8(TRACE_GROUP_3, CTP_COORDINATE3, tp_event->points[0].x, tp_event->points[0].y,
		                                           tp_event->points[1].x, tp_event->points[1].y,
		                                           tp_event->points[2].x, tp_event->points[2].y, 0, 0);
	else if(tp_event->model == 4)
		drv_trace8(TRACE_GROUP_3, CTP_COORDINATE4, tp_event->points[0].x, tp_event->points[0].y,
		                                           tp_event->points[1].x, tp_event->points[1].y,
		                                           tp_event->points[2].x, tp_event->points[2].y,
		                                           tp_event->points[3].x, tp_event->points[3].y);
	return KAL_TRUE;
	}    
   
Touch_Panel_PenState_enum touch_panel_capacitive_get_data(TouchPanelMultipleEventStruct *tp_event)
{
	kal_bool result = KAL_FALSE;
	kal_uint32 uscnti1, uscnti2;
   
	uscnti1= ust_get_current_time();
	result = ctp_fun_ptr->ctp_get_data(tp_event);
        tp_event->time_stamp = L1I_GetTimeStamp();
	uscnti2= ust_get_current_time();
	if(uscnti2 > uscnti1)
		drv_trace1(TRACE_GROUP_4, CTP_GET_DATA_DURATION, uscnti2 - uscnti1);
	else
		drv_trace1(TRACE_GROUP_4, CTP_GET_DATA_DURATION, 5000 + uscnti2 - uscnti1);	

	return result?DOWN:UP;
}    
	
kal_uint32 touch_panel_capacitive_command(kal_uint32 cmd, void *p1, void*p2)
	{
	return ctp_fun_ptr->ctp_command(cmd, p1, p2);
	}    
	
kal_bool touch_panel_capacitive_set_device(ctp_device_mode_enum mode)
	{
	return ctp_fun_ptr->ctp_set_device_mode(mode);
  }

kal_bool touch_panel_capacitive_power_state(ctp_device_mode_enum mode)
	{
	return ctp_fun_ptr->ctp_set_device_mode(mode);
}

void touch_panel_capacitive_up_hdr(DCL_EVENT event)
{
	kal_uint32 i=0;
	TouchPanelMultipleEventStruct tp_event;
	
	/*check if the down point is reasonable*/
	if(TP.wait_next_down == KAL_TRUE)
		return;
	
	if(TP.skip_unrelease_state==KAL_FALSE)
	{
		touch_panel_multiple_touch_stop_timer();
		touch_panel_multipel_touch_retrieve_event(&tp_event, &touch_panel_data_buffer.touch_buffer_last_windex, KAL_FALSE); //not increase index
		if(TP.area == HAND_WRITING) //already all up in last event.
		{
			if(tp_event.points[0].event == STROKE_UP)
			{
				drv_trace0(TRACE_GROUP_4, CTP_UP_HDR_STROKE_UP_AGAIN);
				return;
			}
			}
		else/*non-handwriting*/
			{
			if(tp_event.points[0].event == PEN_UP)
			{
				drv_trace0(TRACE_GROUP_4, CTP_UP_HDR_PEN_UP_AGAIN);
				return;
			}
		}
		for(i=0; i<tp_event.model; i++) //set all exist event as UP
		{
			if((tp_event.points[i].event == PEN_UP)||(tp_event.points[i].event == STROKE_UP))
			{
				tp_event.model = i; //all other points already up in last event
				break;
			}
			else if(TP.area == HAND_WRITING) //if the first 
			{
				tp_event.points[i].event = STROKE_UP;
		}
			else/*non-handwriting*/
		{
				tp_event.points[i].event = PEN_UP;
		}
	}
		tp_event.time_stamp = L1I_GetTimeStamp();
		touch_panel_multiple_touch_data_push(&tp_event);
		}
	else
    {
        /*TP.skip_unrelease_state==KAL_TRUE*/
		TP.skip_unrelease_state=KAL_FALSE;   
	}
}


void touch_panel_capacitive_down_hdr(DCL_EVENT event)
{
	kal_uint32 i=0;
	CTP_parameters_struct CTP_para;
	TouchPanelMultipleEventStruct tp_event;
	
	/* only mask eint when it's unmasked. */
	if (tp_eint_mask == KAL_FALSE)//CTP_g_event may change during HISR prempt
		TP_MASK_INT;   

	memcpy((kal_uint8 *)(&tp_event), (kal_uint8 *)(&CTP_g_event), sizeof(TouchPanelMultipleEventStruct)); 

	if (tp_eint_mask == KAL_FALSE)
		TP_UNMASK_INT;

	if(tp_event.model == 0)//CTP_g_event may change during HISR prempt, if model become 0, ignore the touch
	{
		drv_trace0(TRACE_GROUP_10, TP_IGNORE_FAST_TP_DOWN);
		//drv_trace2(TRACE_GROUP_4, CTP_HISR_UP_TO_UP, state, TP.state);
		return;
	}
	
	TP.skip_unrelease_state=KAL_FALSE;
	Touch_Panel_first_valid = KAL_FALSE;
	
	TP.area = touch_panel_area_check(tp_event.points[0].x, tp_event.points[0].y);
	
	for(i=0; i<tp_event.model; i++)
	{
		if(TP.area == HAND_WRITING) //if the first 
		{
			//touch_panel_capacitive_feed_event(STROKE_DOWN, &data, i);
			tp_event.points[i].event = STROKE_DOWN;
			CTP_para.Report_interval = TP.high_sample_period*9; //GPT tick: 10ms per tick
		}
		else/*non-handwriting*/
		{
			//touch_panel_capacitive_feed_event(PEN_DOWN, &data, i);
			tp_event.points[i].event = PEN_DOWN;
			CTP_para.Report_interval = TP.low_sample_period*9; //GPT tick: 10ms per tick
		}
	}
	ctp_fun_ptr->ctp_parameters(&CTP_para, 0, CTP_PARA_REPORT_INTVAL);

	touch_panel_multiple_touch_data_push(&tp_event);
	touch_panel_multiple_touch_set_timer(KAL_TRUE);
}

 
void touch_panel_capacitive_HISR(void)
{
	static Touch_Panel_PenState_enum state = UP;
	TouchPanelMultipleEventStruct controller_touch_data, last_tp_event;
	kal_bool bGetNewEvent = KAL_FALSE;
    
	state  = touch_panel_capacitive_get_data(&controller_touch_data);
	touch_panel_multipel_touch_retrieve_event(&last_tp_event, &touch_panel_data_buffer.touch_buffer_last_windex, KAL_FALSE);
	//if((last_tp_event.model > CTP_g_event.model) && (CTP_g_event.model < controller_touch_data.model)) // not update CTP_g_event
	if((last_tp_event.model <= CTP_g_event.model) || (CTP_g_event.model >= controller_touch_data.model) || (CTP_g_event.model==0))
	{
		memcpy((kal_uint8 *)(&CTP_g_event), (kal_uint8 *)(&controller_touch_data), sizeof(TouchPanelMultipleEventStruct));
		bGetNewEvent = KAL_TRUE;
		if((CTP_g_event.model != controller_touch_data.model)&&(last_tp_event.model!=0)&&(controller_touch_data.model!=0)) //pen count changes need handle it immediately
        {
            // do not handle first pen down and last pen up. tp task will handle that.
			touch_panel_capacitive_to_coordinate(&CTP_g_event);
			touch_panel_multiple_touch_event_handler(&CTP_g_event, &last_tp_event); //feed PEN_MOVE or PEN_STATICAL
			touch_panel_multiple_touch_data_push(&CTP_g_event);
			TP_UNMASK_INT;
			return;
		}
	}
	if (state == DOWN)/*low*/
	{
		if(bGetNewEvent) //Don't need to change to coordinate again, if not get new event
			touch_panel_capacitive_to_coordinate(&CTP_g_event);
		if(TP.state == UP)
		{
			TP.state = state;
			TP.tp_down_cb(NULL);
			drv_trace0(TRACE_GROUP_10, TP_HISR_DOWN);        
		}
		else
		{              
			drv_trace2(TRACE_GROUP_4, CTP_HISR_DOWN_TO_DOWN, state, TP.state);
		}      
		// not trigger TP task if down->down
	}
	else/*high*/
	{
		if(TP.state == DOWN) //work around?
		{
			touch_panel_multiple_touch_stop_timer(); //yali
			TP.state = state;
		    TP.tp_up_cb(NULL);
			drv_trace0(TRACE_GROUP_10, TP_HISR_UP);
		}
		else
			drv_trace2(TRACE_GROUP_4, CTP_HISR_UP_TO_UP, state, TP.state);
	}
	TP_UNMASK_INT;
}
#endif //#if defined(__TOUCH_PANEL_CAPACITY__)

void Ctp_Init_Update_Firmware(void)
{
#if defined(__TOUCH_PANEL_CAPACITY__)
	DCL_HANDLE handle;
	STS_CTRL_SET_DEVICE_T set_device;
	handle=DclSTS_Open(DCL_TS,0);
	set_device.mode = DCL_CTP_FIRMWARE_UPDATE;
	DclSTS_Control(handle,STS_CMD_SET_DEVICE,(DCL_CTRL_DATA_T *)&set_device);
	DclSTS_Close(handle);
#endif /*#if defined(__TOUCH_PANEL_CAPACITY__)*/  

}
#endif
