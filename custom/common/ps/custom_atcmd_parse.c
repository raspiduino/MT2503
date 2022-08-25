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
 * Filename:
 * ---------
 * custom_atcmd_parse.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for parsing general proprietary AT command.
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

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#define RMMI_PARSER_C

#include "kal_general_types.h"


#include <stdio.h>
#include <string.h>
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "stack_ltlcom.h"
#include "app_ltlcom.h"       	/* Task message communiction */
#include "stacklib.h"        	/* Basic type for dll, evshed, stacktimer */
#include "kal_public_api.h"
#include "stack_timer.h"
#include "event_shed.h"
#include "nvram_editor_data_item.h"
#include "custom_nvram_editor_data_item.h"

#include "uart_sw.h"
#ifdef __UMTS_RAT__
/* under construction !*/
#endif
#ifdef __BTMTK__
#include "Bluetooth_struct.h"
extern void rmmi_send_msg_to_bt (msg_type msg_name, void *param_ptr);
#endif

#ifndef __L1_STANDALONE__
extern kal_bool tst_process_pc_command_from_ATCmd(kal_int32 len, kal_uint8 *param);
#endif

#if defined(__GPS_SUPPORT__)
#include "gps_struct.h"
#if defined(__FEATURE_PHONE_MODEM__)
#include "gps_common.h"
#endif
#endif /* __GPS_SUPPORT__ */

#ifdef __FM_AT_SUPPORT__
#include "FMATCommand.h"
#endif

#ifndef L4_NOT_PRESENT
#ifdef __MOD_SMU__
#include "ps2sim_struct.h"
#include "ps2sat_struct.h"
#include "sim_common_enums.h"
#include "smu_common_enums.h"
#endif /* __MOD_SMU__ */ 
#include "csmss_common_enums.h"
#include "mcd_l4_common.h"
#include "l4c_common_enum.h"
#include "rmmi_common_enum.h"
#include "rmmi_common_enum.h"
#include "rmmi_context.h"

#include "ps_public_enum.h"

extern rmmi_context_struct *rmmi_ptr_g;
#endif /* L4_NOT_PRESENT */

#if defined(__WIFI_SUPPORT__) && !defined(EXTERNAL_MMI) && defined(__MMI_FMI__)
#include "dtcntsrviprot.h"
#include "dtcnt_struct.h"
#endif

#ifdef __AGPS_CONTROL_PLANE__
extern void l4c_agps_reset_positioning_lind(void);
#endif

#if defined(__DUAL_TALK_MODEM_SUPPORT__)
extern void Spc_ATCommand(kal_uint32 uLen, kal_uint8 *pCmd);
#endif

/* mtk01616_080104: 
  * This is used to define default <time> and <pause> value for AT+CKPD.
  * <time> * 0.1 sec is the time to stroke each key
  * <pause> * 0.1 sec  is the length between two strokes.  
  * <time> or <pause> should not larger than 255 (25.5 sec)
  * Default value is manufacturer specific,but should be so long that a normal MT can handle keystrokes correctly
  * Please refer to spec 07.07 section 8.7 for more detailed information
  */
#define CUSTOM_AT_CKPD_DEFAULT_TIME 2
#define CUSTOM_AT_CKPD_DEFAULT_PAUSE 4 

//Define AT command URC "RING" interval , the unit is 0.1 sec , default value is 4 sec = 40 x 0.1 sec
#define CUSTOM_URC_RING_INTERVAL 40

#ifdef __UMTS_RAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __CTP_GOODIX_GT818_TRUE_MULTIPLE__
#include "fs_type.h"
#include "fs_func.h"
#include "kal_public_api.h"

static kal_bool process_gt818_ctp_cmd( kal_uint8 action, kal_uint32 data_len, kal_uint8 *data_str )
{
    kal_uint16 ret_len = 0;
    kal_uint16 i;
    kal_uint16 inlen;
    kal_uint16 offset;
    STS_CTRL_COMMAND_T cmd;
    DCL_HANDLE handle;
    kal_uint8 *ctp_buffer = NULL;
    kal_uint8 *result = NULL;
    
    ctp_buffer = (kal_uint8 *)get_ctrl_buffer( 1024 );
    
    if ( ctp_buffer == NULL )
        EXT_ASSERT(0, (int)ctp_buffer, 0, 0);
        
    cmd.u4Command = action;
    cmd.pVoid1 = (void *)data_str;
    cmd.pVoid2 = (void *)&result;
    
    handle = DclSTS_Open( DCL_TS, 0 );
    DclSTS_Control( handle, STS_CMD_COMMAND, (DCL_CTRL_DATA_T *)&cmd );   
    DclSTS_Close(handle);     
    
    if ( action == DCL_CTP_COMMAND_GET_VERSION )
        ret_len = 6;
        
    if ( action == DCL_CTP_COMMAND_GET_CONFIG )
        ret_len = 106;
            
    if ( action == DCL_CTP_COMMAND_GET_DIFF_DATA )
        ret_len = 162;      

    if ( action == DCL_CTP_COMMAND_GET_FW_BUFFER )
    {
        offset = data_str[0]*256 + data_str[1];
        inlen = data_str[2];
        memcpy( &result[offset], &data_str[3], inlen);
        
        if ( inlen != 128 )
        {
            #define GT818_FW_STRING  "ctp_firmware_rusklmeoxkwjadfjnklruo3"
            kal_int16   drv_letter;
            FS_HANDLE fs_handle;
            UINT writen;
            kal_wchar   CTP_FIRMWARE_PATH[64];
                    
            drv_letter = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_I_SYSTEM | FS_DRIVE_V_NORMAL);
            kal_wsprintf( CTP_FIRMWARE_PATH, "%c:\\%s", drv_letter, GT818_FW_STRING );    
            fs_handle = FS_Open( CTP_FIRMWARE_PATH, FS_CREATE_ALWAYS | FS_READ_WRITE );
            FS_Write(fs_handle, (kal_uint8 *) result , offset+inlen, &writen);
            FS_Close( fs_handle );
        }            
    }
    
    kal_sprintf( (kal_char *)ctp_buffer, "+EGCMD: " );
            
    for ( i = 0 ; i < ret_len ; i++ )
        kal_sprintf( (kal_char *)&ctp_buffer[strlen((char *)(ctp_buffer))], "%02X", result[i] );            
        
    rmmi_write_unsolicitedResultCode( ctp_buffer, strlen((kal_char *)(ctp_buffer)), KAL_TRUE, 1, NULL );    
    
    free_ctrl_buffer( ctp_buffer );
    
    return KAL_TRUE;
}
#endif

/*****************************************************************************
* FUNCTION
*  	rmmi_general_command_parsing()
* DESCRIPTION
*   	This function should parse general proprietary AT command request.
*     Each owner should maintain and modify the code.
* PARAMETERS
*   	kal_uint32 op 
*	kal_uint32 data_len 
*	kal_uint8 *data_str
* RETURNS
*	KAL_TRUE or KAL_FALSE
*****************************************************************************/
kal_bool rmmi_general_command_parsing(kal_uint32 op, 
												kal_uint32 data_len, 
												kal_uint8 *data_str)
{
	kal_bool ret_val = KAL_FALSE;
	
#ifndef L4_NOT_PRESENT

	switch(op)
	{
		
		case 2: /* add by stanley 2006-07-03*/
		{
#if  defined(__BTMTK__)
			bt_test_cmd_req_struct  *param_ptr;
			param_ptr = (bt_test_cmd_req_struct *)construct_local_para(
															(kal_uint16)sizeof(bt_test_cmd_req_struct),
															TD_CTRL);   

			kal_mem_cpy(param_ptr->test_cmd_content, data_str, data_len);
			rmmi_send_msg_to_bt(MSG_ID_BT_TEST_CMD_REQ, param_ptr);	 
			ret_val = KAL_TRUE;
#endif /* __BTMTK__ */
      break;
		}
        
    #ifdef __GPS_SUPPORT__      

		case 3: /* mtk00612_071025: for GPS testing - Power On */
		case 4: /* mtk00612_071025: for GPS testing - Power Off */
		case 5: /* mtk00612_071025: for GPS testing - Command */          
		{
			gps_ate_test_req_struct  *param_ptr;
            ilm_struct *ilm_ptr = NULL;                  
            kal_uint32 written;
            
			param_ptr = (gps_ate_test_req_struct *)construct_local_para(
													        (kal_uint16)sizeof(gps_ate_test_req_struct),
															TD_CTRL);   
            if (op == 3)
            {
                /* power on */
                param_ptr->event = MMI_GPS_ATE_EVENT_POWER_ON;
                #ifdef __FEATURE_PHONE_MODEM__
                gps_power_on_req(GPS_UART_MODE_RAW_DATA);
                #endif
            }
            else if(op == 4)
            {
                /* power off */
                param_ptr->event = MMI_GPS_ATE_EVENT_POWER_OFF;
                #ifdef __FEATURE_PHONE_MODEM__
                gps_power_off_req(GPS_UART_MODE_RAW_DATA);
                #endif

            }
            else if (op == 5)
            {
                param_ptr->event = MMI_GPS_ATE_EVENT_COMMAND;
                
                /* send command */
    			kal_mem_cpy(param_ptr->cmd_buf, data_str, data_len);
                param_ptr->cmd_length = data_len;
                #ifdef __FEATURE_PHONE_MODEM__
                gps_uart_command_write((kal_uint8 *)param_ptr->cmd_buf,data_len,&written);
                #endif
            }
            else 
            {
                ASSERT(0);
            }
            
            ilm_ptr = allocate_ilm(MOD_L4C);
            ilm_ptr->msg_id = (kal_uint16)MSG_ID_MMI_GPS_ATE_TEST_REQ;
            ilm_ptr->peer_buff_ptr = NULL;
            ilm_ptr->local_para_ptr = (local_para_struct*)param_ptr;

            ilm_ptr->src_mod_id  = MOD_L4C;
#ifdef __FEATURE_PHONE_MODEM__
            ilm_ptr->dest_mod_id = MOD_GPS;
#else
            ilm_ptr->dest_mod_id = MOD_MMI;
#endif
            msg_send_ext_queue(ilm_ptr);

            ret_val = KAL_TRUE;
			break;
		} 
    #endif /* __GPS_SUPPORT__ */
    case 6:
    {
#ifdef __UMTS_RAT__
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
#endif /* __UMTS_RAT__ */
    }
    break;
#ifdef __FM_AT_SUPPORT__
    case 7: /* mtk00650_091025: for FM testing - Power On */
    case 8: /* mtk00650_091025: for FM testing - Power Off */
    case 9: /* mtk00650_091025: for FM testing - Set Freq */
    case 10: /* mtk00650_091025: for FM testing - Command */          
    {
    	mmi_fm_ate_test_req_struct  *param_ptr;
       ilm_struct *ilm_ptr = NULL;                  
            
	param_ptr = (mmi_fm_ate_test_req_struct *)construct_local_para(
				        (kal_uint16)sizeof(mmi_fm_ate_test_req_struct),
													TD_CTRL);   
       if (op == 7)
       {
              /* power on */
       	param_ptr->event = MMI_FM_ATE_EVENT_POWER_ON;
       }
       else if(op == 8)
       {
              /* power off */
              param_ptr->event = MMI_FM_ATE_EVENT_POWER_OFF;

       }
       else if (op == 9)
       {
              param_ptr->event = MMI_FM_ATE_EVENT_SET_FREQ;
                
                /* send command */
    			kal_mem_cpy(param_ptr->cmd_buf, data_str, data_len);
                param_ptr->cmd_length = data_len;
       }
       else if (op == 10)
       {
              param_ptr->event = MMI_FM_ATE_EVENT_COMMAND;
                
                /* send command */
    			kal_mem_cpy(param_ptr->cmd_buf, data_str, data_len);
                param_ptr->cmd_length = data_len;
       }
       else 
       {
              ASSERT(0);
       }
            
        ilm_ptr = allocate_ilm(MOD_L4C);
        ilm_ptr->msg_id = (kal_uint16)MSG_ID_MMI_FM_ATE_TEST_REQ;
        ilm_ptr->peer_buff_ptr = NULL;
        ilm_ptr->local_para_ptr = (local_para_struct*)param_ptr;

        ilm_ptr->src_mod_id  = MOD_L4C;
        ilm_ptr->dest_mod_id = MOD_MMI;
        msg_send_ext_queue(ilm_ptr);

        ret_val = KAL_TRUE;
	 break;
    } 
#endif /* __FM_AT_SUPPORT__ */

#if defined(__WIFI_SUPPORT__) && !defined(EXTERNAL_MMI) && defined(__MMI_FMI__)
    case 11: /* mtk01476_20100701: wifi chip verification for factory setting */
    case 12: /* mtk01476_20100701: wifi chip verification for factory setting */
    case 13: /* mtk01476_20100701: wifi chip verification for factory setting */        
    {
		srv_dtcnt_wlan_atcmd_req_struct  *req;
        ilm_struct *ilm_ptr = NULL;                  
        
		req = (srv_dtcnt_wlan_atcmd_req_struct *)construct_local_para(
												        (kal_uint16)sizeof(srv_dtcnt_wlan_atcmd_req_struct),
												        TD_RESET);
        /* send command */
        if (op == 11)
        {
            req->opcode = SRV_DTCNT_WLAN_WLAN_ATCMD_OPCODE_ADD_PROF;
        }
        else if (op == 12)
        {
            req->opcode = SRV_DTCNT_WLAN_WLAN_ATCMD_OPCODE_CONN_PROF;
        }
        else /* 13 */
        {
            req->opcode = SRV_DTCNT_WLAN_WLAN_ATCMD_OPCODE_DEL_PROF;
        }
		kal_mem_cpy(req->cmd_buf, data_str, data_len);
        req->cmd_length = data_len;												

        ilm_ptr = allocate_ilm(MOD_L4C);
        ilm_ptr->msg_id = (kal_uint16)MSG_ID_SRV_DTCNT_WLAN_ATCMD_REQ;
        ilm_ptr->peer_buff_ptr = NULL;
        ilm_ptr->local_para_ptr = (local_para_struct*)req;

        ilm_ptr->src_mod_id  = MOD_L4C;
        ilm_ptr->dest_mod_id = MOD_MMI;
        msg_send_ext_queue(ilm_ptr);
            
        ret_val = KAL_TRUE;
        break;
    }
#endif

    #if defined(__AGPS_CONTROL_PLANE__)            
        case 14:
        {
            l4c_agps_reset_positioning_lind();
            ret_val = KAL_TRUE;
            break;
        }
    #endif

/************************sample code begin************************/			
//		case op: /*owner_date: purpose*/
//		{
//			/*call proprietary parsing function here and AT will give result  */
//			/*code OK/ERROR according to return value of parsing function*/	
//
//			break;
//		}
/************************sample code end*************************/
    #ifdef __CTP_GOODIX_GT818_TRUE_MULTIPLE__
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        {
            ret_val = process_gt818_ctp_cmd( (kal_uint8)(op - 15), data_len, data_str );
            break;
        }   
    #endif

#if defined(__DUAL_TALK_MODEM_SUPPORT__)
        case 25:
           Spc_ATCommand(data_len, data_str);
           ret_val = KAL_TRUE;
           break;
#endif

		default:
			break;	
	}
#endif // L4_NOT_PRESENT

	return ret_val;
}

kal_uint16 rmmi_get_ckpd_default_time(void)
{
	return CUSTOM_AT_CKPD_DEFAULT_TIME;
}

kal_uint16 rmmi_get_ckpd_default_pause(void)
{
	return CUSTOM_AT_CKPD_DEFAULT_PAUSE;
}

kal_uint16 rmmi_get_ring_interval(void)
{
	return CUSTOM_URC_RING_INTERVAL;
}

/*****************************************************************************
* FUNCTION
*  	rmmi_custom_init_context()
* DESCRIPTION
* This function is to customize AT command default setting
*
* PARAMETERS
*	NONE
*
* RETURNS
*	NONE
*
*****************************************************************************/
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif

void rmmi_custom_init_context()
{
#ifndef L4_NOT_PRESENT
    /* ATE default value */
#if defined(__SP_RIL_SUPPORT__)
    RMMI_PTR->rsp_mode.echo_flag = 0x00; // default echo off
#else 
    RMMI_PTR->rsp_mode.echo_flag = 0xff; // default echo on
#endif 

    /* ATV default value */
    RMMI_PTR->rsp_mode.format = RMMI_VERBOSE_FULL_HEAD_TAIL;

	/* ATW default value */
    RMMI_PTR->rsp_mode.ext_result_code = 2;

	/* ATQ default value */
    RMMI_PTR->rsp_mode.suppress_flag = RMMI_SUPPRESS_OFF;

    /* AT+CMEE=<n> default value */
    RMMI_PTR->error_report_mode = RMMI_SIMPLE_ERROR;

    /* AT+CSCS=<chset> default value */
    RMMI_PTR->char_set = RMMI_CHSET_IRA;    

	/* AT+COPS=<mode>,<format> default value */
    RMMI_PTR->plmn_format = RMMI_PLMN_LONG_ALPHA;       //default for long alpha
    RMMI_PTR->cops_mode = 0; // default "automatic" mode

	/* AT+CPOL=<index>,<format> , set <format> default value here */
    RMMI_PTR->CPOL_plmn_format = RMMI_PLMN_NUMERIC;	

    /* AT+CMEC=<keyp>,<disp>,<ind> default value */
    RMMI_PTR->cmec_keyp = 2; 
    RMMI_PTR->cmec_disp = 0;
    RMMI_PTR->cmec_ind = 0;

    /* AT+CLAE=<mode> default value */    
    RMMI_PTR->clae_mode = KAL_FALSE;    

    /* AT+CSCB=<mode> , if <mode>=0 then set cb_mode=KAL_TRUE , if <mode>=1 then set cb_mode= KAL_FALSE */
    RMMI_PTR->cb_mode = KAL_TRUE; 

	/* AT+CSDH=<show> default value */
    RMMI_PTR->csdh_show = KAL_FALSE;

    /* AT+CPBS=<storage> default value */
    RMMI_PTR->phb_storage_type = RMMI_PHB_ME;

	/* AT+CVHU=<mode> default value, only (0-1) is supported */
#if defined(__MULTIPLE_PPP_DIALUP_SUPPORT__) && defined(__MMI_FMI__)
	RMMI_PTR->cvhu_mode = 1; //MAUI_02862643, mtk02285, ignore ATH in default -> To prevent disc CS call for Ericsson IOT  
#else
	RMMI_PTR->cvhu_mode = 0;
#endif

    /* AT+EIND=<flag> default value*/
#if defined (__CMUX_SUPPORT__) || defined (__MODEM_CARD__) /* EDGE card default enable eind */
    RMMI_PTR->report_mode.eind = 0x000000ff;
#else
    RMMI_PTR->report_mode.eind = 0; 
#endif

    /* AT+EINFO=<flag> default value*/
#if defined (__SP_RIL_SUPPORT__) 
    RMMI_PTR->report_mode.einfo = 0x00000013;
#else
    RMMI_PTR->report_mode.einfo = 0;
#endif

    /* AT+ECPI=<mode> default value*/
    RMMI_PTR->report_mode.ecpi = 0;

    /* AT+ECSQ=<flag> default value*/
    RMMI_PTR->report_mode.ecsq = 0;

    /* AT+CMER=<mode>,<keyp>,0,<ind>,<bfr> default value */	
    RMMI_PTR->report_mode.cmer_mode = 0;  
    RMMI_PTR->report_mode.cmer_keyp = 0;
    RMMI_PTR->report_mode.cmer_ind = 0;   
    RMMI_PTR->report_mode.cmer_bfr = 0;	

    /* AT+CLIP=<n> default value*/	
    RMMI_PTR->report_mode.clip = 0;

    /* AT+COLP=<n> default value*/	
    RMMI_PTR->report_mode.colp = RMMI_DISABLE_REPORT;

    /* AT+CLIR=<n> default value*/	
    RMMI_PTR->report_mode.clir = RMMI_DISABLE_REPORT;

    /* AT+CDIP=<n> default value*/	
    RMMI_PTR->report_mode.cdip = RMMI_DISABLE_REPORT;

    /* AT+CNAP=<n> default value*/	
    RMMI_PTR->report_mode.cnap = RMMI_DISABLE_REPORT;
	
    /* AT+CREG=<n> default value*/	
    RMMI_PTR->report_mode.cs_reg = RMMI_DISABLE_NW_REG_REPORT;

    /* AT+CGREG=<n> default value*/	
    RMMI_PTR->report_mode.ps_reg = RMMI_DISABLE_NW_REG_REPORT;

    /* AT+CAOC=<mode> default value*/	
    RMMI_PTR->report_mode.ccm = RMMI_DISABLE_REPORT;

    /* AT+CCWE=<mode> default value*/	
    RMMI_PTR->report_mode.acm_warning = RMMI_DISABLE_REPORT;

    /* AT+CCWA=<n> default value*/	
    RMMI_PTR->report_mode.call_wait = RMMI_DISABLE_REPORT;

    /* AT+CGEREP=<mode> default value*/	
    RMMI_PTR->report_mode.cgerep = RMMI_DISABLE_REPORT;

    /* AT+CR=<mode> default value*/	
    RMMI_PTR->report_mode.cr = RMMI_DISABLE_REPORT;

    /* AT+CRC=<mode> default value*/	
    RMMI_PTR->report_mode.crc = RMMI_DISABLE_REPORT;

    /* AT+CTZR=<onoff> default value*/	
    RMMI_PTR->report_mode.timezone = RMMI_DISABLE_REPORT;

    /* AT+CUSD=<n> default value*/	
    RMMI_PTR->report_mode.ussd = RMMI_DISABLE_REPORT;

    /* AT+CSSN=<n>,<m> default value*/	
    RMMI_PTR->report_mode.ss_mo = RMMI_DISABLE_REPORT;	
    RMMI_PTR->report_mode.ss_mt = RMMI_DISABLE_REPORT;	

#if !defined(__MMI_FMI__)
    /* AT+ESIMS=<n> default value*/
    RMMI_PTR->report_mode.esims = 0;
#endif

#ifdef __OP01__
    /* AT^DSCI=<n> default value */
    RMMI_PTR->op01_report_mode.dsci = 0;
    RMMI_PTR->op01_report_mode.cardmode = 0;
    RMMI_PTR->op01_report_mode.rfsw = 0;
#endif

#endif /* L4_NOT_PRESENT */    
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif


/*****************************************************************************
* FUNCTION
*  	rmmi_get_vgr_default_setting()
* DESCRIPTION
*   	This function is to define default setting for ATE
*
* PARAMETERS
*	NONE
*
* RETURNS
*
*****************************************************************************/
void rmmi_get_vgr_default_setting(kal_bool *customer_provided, kal_uint8 *vgr_gain)
{
    *customer_provided = KAL_FALSE;
    *vgr_gain = 150;
}

/*****************************************************************************
* FUNCTION
*  	rmmi_get_vgt_default_setting()
* DESCRIPTION
*   	This function is to define default setting for ATE
*
* PARAMETERS
*	NONE
*
* RETURNS
*
*****************************************************************************/
void rmmi_get_vgt_default_setting(kal_bool *customer_provided, kal_uint8 *vgt_gain)
{
    *customer_provided = KAL_FALSE;
    *vgt_gain = 150;
}

#ifdef __CLAC_SUPPORT__


/*****************************************************************************
* FUNCTION
*  	rmmi_remove_listing_at_command()
* DESCRIPTION
*   	
* PARAMETERS
*	NONE
*
* RETURNS
*
*****************************************************************************/
kal_bool rmmi_remove_listing_at_command(kal_char const *rsp_str)
{
/* If you don't want to list some at command, you can refer the following example.
    If you don't list ata and at+casp, please refer the following code.*/
/*	
       if (strcmp(rsp_str, "a") == 0 || strcmp(rsp_str, "casp") == 0)
	{
		return KAL_FALSE;
	}
*/
	return KAL_TRUE;
}
/*****************************************************************************
* FUNCTION
*  	rmmi_add_listing_at_command()
* DESCRIPTION
*   	
* PARAMETERS
*	NONE
*
* RETURNS
*
*****************************************************************************/
kal_uint16 rmmi_add_listing_at_command(kal_char **rsp_str)
{
/* If you want to list some custom at command, you can refer the following example.
    If you list at+aaaa and at+bbbb, please refer the following code.*/
/*    
    rsp_str[0]="at+aaaa\0";
    rsp_str[1]="at+bbbb\0";

    return 2; // total 2 at command (at+aaaa and at+bbbb)
*/
    return 0;
}
#endif
