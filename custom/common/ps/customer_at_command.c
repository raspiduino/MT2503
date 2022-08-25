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
 * Custom_at_command.c
 *
 * Description:
 * ------------
 *   This file is intends for Customer to implement and parse its own defined AT commands
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
 * removed!
 * removed!
 *
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
*****************************************************************************/
//#include "kal_release.h"
//#include "kal_non_specific_general_types.h"
#include "stdio.h"
#include "string.h"
//#include "stack_config.h"	

#include "kal_general_types.h"
#include "kal_internal_api.h"
#include "ata_external.h"
#if (defined(__COMPOSITE_WEBCAM__))
#include "cal_api.h"
#include "cal_comm_def.h"
#endif
#ifdef __TWOMICNR_SUPPORT__
#include "two_mic_NR_custom_if.h" 
#endif

#if defined(__PLMN_LIST_WITH_CELL_INFO__)
#include "ps_public_struct.h"
#endif

#include "rmmi_common_enum.h"

extern void kal_monitor_buffer(kal_uint32 index);
extern kal_bool twomicnr_command_hdlr(char *full_cmd_string);
#if defined (__GPS_TRACK__)
#include "ell_os.h"

#endif/*__GPS_TRACK__*/

/*****************************************************************************
* CUSTOM_SYMBOL:
*	customer can modify this symbol.
*     Every command begin with this symbol will be recognized as a customer-defined command
*	and passed to custom_command_hdlr().
*     For example: if CUSTOM_SYMBOL is set to '^', 
*				then AT^AAAA, AT^BBBB will be customer-defined command.
*   	NOTE:  '+'  and '/' and ' \ 'is not allowed since they might be standard command format
*****************************************************************************/
#define CUSTOM_SYMBOL  '^'	 // '+'  and '/' and ' \ 'is NOT allowed

/*****************************************************************************
* MAX_UART_LEN = 128 bytes.
*	when you write a lot of data to UART at the same time, 
*	UART's buffer might be full and cannot handle.
*     so the safer way is to seperate the long data, each time only write data length <= 128
*****************************************************************************/

kal_uint8 custom_get_atcmd_symbol(void);
kal_bool custom_command_hdlr(char *full_cmd_string);

/*****************************************************************************
* FUNCTION
*  	rmmi_write_to_uart()
* DESCRIPTION
*   	This function extern L4C RMMI function,
*     is to write data to UART
* PARAMETERS
*   	kal_uint8 * buffer 	- the data to be written
*	kal_uint16 length 	- the length of data to be written
*     kal_bool stuff 		- KAL_TRUE : <CR><LF> will be added at the beginning and end. (eg.<CR><LF>OK<CR><LF>)
*					   KAL_FALSE: no <CR><LF> is added
* RETURNS
*	none
*****************************************************************************/
extern void rmmi_write_to_uart(kal_uint8 * buffer, kal_uint16 length, kal_bool stuff); 

#ifdef __GATI_ENABLE__
extern kal_bool gati_command_hdlr(kal_uint8* cmd_string, kal_uint8* full_string);

module_type gati_mod_table[] = 
{
    MOD_PHB,
    MOD_L4C,
    MOD_L4C,
    MOD_L4C, 
    MOD_NIL         /* Need to be the last one */
};

kal_char *gati_cmd_table[] = 
{
    "CPBBA",
    "CPBBR",
    "CPBBS",
    "CPBB"
};

#endif

#ifdef __GAS_SUPPORT__
extern kal_bool gas_command_hdlr(kal_uint8* cmd_string, kal_uint8* full_string);

module_type gas_mod_table[] = 
{
#ifdef __TCPIP__
    MOD_ABM,
#endif
    MOD_L4C,
    MOD_CSM,
#if defined(__BTMTK__)
    MOD_BT,
#endif
    MOD_NIL         /* Need to be the last one */
};

kal_char *gas_cmd_table[] = 
{
#ifdef __TCPIP__
    "EWIFI",
#endif
    "CL4C",
    "CCSM"
#if defined(__BTMTK__)
    ,"EBTAT"
#endif
};


#endif


typedef struct
{
	char *commandString;
	custom_rsp_type_enum (*commandFunc)(custom_cmdLine *commandBuffer_p);
} custom_atcmd;

custom_cmd_mode_enum custom_find_cmd_mode(custom_cmdLine *cmd_line);

custom_rsp_type_enum custom_test_func(custom_cmdLine *commandBuffer_p)
{
    custom_cmd_mode_enum result;
    custom_rsp_type_enum ret_value  = CUSTOM_RSP_ERROR;

    result = custom_find_cmd_mode(commandBuffer_p);		
    switch (result)
    {
        case CUSTOM_READ_MODE:
            ret_value = CUSTOM_RSP_OK;
            break;
        case CUSTOM_ACTIVE_MODE:
            ret_value = CUSTOM_RSP_OK;
            break;
        case CUSTOM_SET_OR_EXECUTE_MODE:
            ret_value = CUSTOM_RSP_OK;
            break;
        case CUSTOM_TEST_MODE:
            ret_value = CUSTOM_RSP_OK;
            break;    
        default:
            ret_value = CUSTOM_RSP_ERROR;
            break;
	}
    return ret_value;
}


/********************************
* The following table is used for the customer
* They can defined their own command and 
* corresponding handler function here
* Note that the last line {NULL, NULL} should not be removed
* since it is the terminator indicator
*********************************/
const custom_atcmd custom_cmd_table[ ] =
{    
    {"AT%CUSTOM",custom_test_func},

#if defined(__ATA_SUPPORT__) && defined(__MTK_TARGET__)
	#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__)|| defined(__MSDC_MSPRO__)) || defined(__MSDC_SD_SDIO)
						{"AT^MSDC",ata_t_card_hdlr_v1}, 		  //T Card
	#endif
				
						{"AT+EMVI",ata_vibrator_hdlr_v1},			  //Vibrator
				
	#if (defined(FM_RADIO_ENABLE))	
						{"AT+EMFM",ata_fm_hdlr_v1}, 			  //FM
	#endif
				
	#if defined(TOUCH_PANEL_SUPPORT) && defined(TOUCH_PANEL_INTERNAL)
						{"AT+ETPID",ata_tp_hdlr_v1},			  //TouchPanel
	#endif
				
	#if defined(ISP_SUPPORT)
						{"AT+ECMFP",ata_camera_hdlr_v1},		  //camera
	#endif
				
	#if defined(__ATV_SUPPORT__)
						{"AT+EMATV",ata_matv_hdlr_v1},				//Matv
						{"AT+EMATVP",ata_matv_video_hdlr_v1},				//Matv video	
	#endif
				
	#if defined(__CUST_NEW__)
						{"AT+EKPT",ata_kpt_hdlr_v1},			  //Keypad Test
	#endif
				
						{"AT+EMAUDIO",ata_audio_hdlr_v1},			  //Audio
						{"AT+ELED",ata_led_hdlr},			   //LED
						{"AT+ELEDT",ata_led_tsem_hdlr},		   //LED take sem
						{"AT+ELEDG",ata_led_gsem_hdlr},		   //LED give sem
						{"AT+ELCM",ata_lcm_hdlr},			   //LCM
						{"AT+EMBKL",ata_bkl_hdlr},			   //Backlight
#endif/*__ATA_SUPPORT__ && __MTK_TARGET__*/

    {NULL, NULL}  // this lind should not be removed, it will be treat as 
};

/*****************************************************************************
* FUNCTION
*     custom_find_cmd_mode()
* DESCRIPTION
*     This function is used to parsing the command mode for the customer
*     The input position of the cmd_line should stay at the character right after the command name
* PARAMETERS
*     cmd_line      the custom_cmdLine which contains the command string and its current parsing position
* RETURNS
*     custom_cmd_mode_enum
*****************************************************************************/
custom_cmd_mode_enum custom_find_cmd_mode(custom_cmdLine *cmd_line)
{
    custom_cmd_mode_enum result;

    if (cmd_line->position < cmd_line->length - 1)
    {
        switch (cmd_line->character[cmd_line->position])
        {
            case '?':  /* AT+...? */
            {
                cmd_line->position++;
                result = CUSTOM_READ_MODE;
                break;
            }
            case '=':  /* AT+...= */
            {
                cmd_line->position++;
                if ((cmd_line->position < cmd_line->length - 1 ) &&
                    (cmd_line->character[cmd_line->position] == '?'))
                {
                    cmd_line->position++;
                    result = CUSTOM_TEST_MODE;
                }
                else
                {
                    result = CUSTOM_SET_OR_EXECUTE_MODE;
                }
                break;
            }
            default:  /* AT+... */
            {
                result = CUSTOM_ACTIVE_MODE;
                break;
            }
        }
    }
    else
    {
        result = CUSTOM_ACTIVE_MODE;
    }
    return (result);
}

#if defined (__BLE_GATT__)
extern void track_gatt_test_at(kal_uint8 num);

kal_bool track_cmd_ble_test(kal_uint8*cmd_name, void * full_cmd_string)
{
    char *p = NULL;
	kal_uint8 num;

	p=strstr((char *)full_cmd_string, "AT^BLE=");

	if(p==NULL)
	{
		return KAL_FALSE;
	}

	p=p+strlen("AT^BLE=");

	num=strlen(p);
	if((num<=0)||(num>5))
	{
		return KAL_FALSE;
	}

	num=atoi(p);
	track_gatt_test_at(num);
    return KAL_TRUE;
}
#endif


/*****************************************************************************
* FUNCTION
*  	custom_command_hdlr()
* DESCRIPTION
*   	This function should parse the custom AT command and do correspondent action.
*     Customer should maintain and modify the code.
* PARAMETERS
*   	kal_uint8 * cmd_string
* RETURNS
*    KAL_TRUE : the command is handled by the customer
*    KAL_FALSE: the command is not handled by the customer
*****************************************************************************/
kal_bool custom_command_hdlr(char *full_cmd_string)
{
    char buffer[MAX_UART_LEN+1]; //MAUI_02377056
    char *cmd_name, *cmdString;
    kal_uint8 index = 0; 
    kal_uint16 length;
    kal_uint16 i;
    custom_cmdLine command_line;

    cmd_name = buffer;

    length = strlen(full_cmd_string);
    #if defined (__GPS_TRACK__)
    /*超长AT指令不回显       --    chengjun  2013-05-14*/
    if(OTA_track_is_epo_long_data(length,full_cmd_string))
    {
        return KAL_TRUE;
    }
#endif /* __GPS_TRACK__ */

	
    length = length > MAX_UART_LEN ? MAX_UART_LEN : length;    
    while ((full_cmd_string[index] != '=' ) &&  //might be TEST command or EXE command
        (full_cmd_string[index] != '?' ) && // might be READ command
        (full_cmd_string[index] != 13 ) && //carriage return
        index < length)  
    {
        cmd_name[index] = full_cmd_string[index] ;
        index ++;
    }
    cmd_name[index] = '\0' ;    
    
    for (i = 0 ; custom_cmd_table[i].commandString != NULL; i++ )
    {
        cmdString = custom_cmd_table[i].commandString;
        if (strcmp(cmd_name, cmdString) == 0 )
        {
            strncpy(command_line.character, full_cmd_string, COMMAND_LINE_SIZE + NULL_TERMINATOR_LENGTH);
            command_line.character[COMMAND_LINE_SIZE] = '\0';
            command_line.length = strlen(command_line.character);
            command_line.position = index;
            if (custom_cmd_table[i].commandFunc(&command_line) == CUSTOM_RSP_OK) 
            {
                sprintf(buffer, "OK");
                rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
            }
            else
            {
                sprintf(buffer, "ERROR");
                rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
            }
            return KAL_TRUE;
        }
    }    

    if (index <= 2)
        return KAL_FALSE;
	
    /* just a very basic example : customer can implement their own */
    cmd_name += 3;
    if (strcmp(cmd_name, "EXAMPLE") == 0)
    {		
        /* BEGIN: do the following parsing and correspondent action */
        /*  												    */
        /*  												    */
        /*  												    */
        /* END: do the following parsing and correspondent action    */

        /* generate final result code: "OK" or "ERROR" */
        if(KAL_TRUE)    // if operation is success
        {
                sprintf(buffer, "OK");
                rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
        }
        else if (KAL_FALSE) // if operation is fail
        {
            sprintf(buffer, "ERROR");
            rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
        }
        return KAL_TRUE;
    }
    #if !defined(__MMI_FMI__) || defined(WISDOM_MMI)
    else if (strcmp(cmd_name, "buffer") == 0)
    {		
        kal_print("Buffer Monitor enabled!");
        kal_monitor_buffer(0xffffffff);		
        sprintf(buffer, "OK");
        rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);

        return KAL_TRUE;
    }	
    #endif	
    #ifdef __TWOMICNR_SUPPORT__ 
    else if (twomicnr_command_hdlr(full_cmd_string) == KAL_TRUE)
    {
	return KAL_TRUE;
    }
    #endif
    #if (defined(__COMPOSITE_WEBCAM__)) 
    else if (strcmp(cmd_name, "SENSOR") == 0)
    {
        CAL_FEATURE_CTRL_STRUCT CalInPara;
        CalInPara.FeatureId = CAL_FEATURE_CAMERA_TUNING_SENSOR;
        CalInPara.FeatureSetValue = (kal_uint32)(full_cmd_string);
        CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInPara, NULL, 0, NULL);
        return KAL_TRUE;
    }
    #endif
    else
    {
#ifdef __GAS_SUPPORT__
        if( gas_command_hdlr( (kal_uint8*)cmd_name, (kal_uint8*)full_cmd_string)==KAL_TRUE )
        {
            // it is a gati command and we will send the command to the appropriate module
            return KAL_TRUE;
        }
#endif 
    #ifdef __GATI_ENABLE__ 
        /* Judge if the command string is a GATI command*/
        if( gati_command_hdlr( (kal_uint8*)cmd_name, (kal_uint8*)full_cmd_string)==KAL_TRUE )
        {
            // it is a gati command and we will send the command to the appropriate module
            return KAL_TRUE;
        }		 	
    #endif
    }
	
#if defined (__GPS_TRACK__)
    if( OTA_track_cmd_parse((kal_uint8*)cmd_name, (kal_uint8*)full_cmd_string) == KAL_TRUE)
    {
		return KAL_TRUE;
    }
#endif /* __GPS_TRACK__ */


#if defined (__BLE_GATT__)
    if(track_cmd_ble_test((kal_uint8*)cmd_name, (kal_uint8*)full_cmd_string))
    {
        return KAL_TRUE;
    }
#endif /* __BLE_GATT__ */

    /* unrecognized command */
    /* we should return KAL_FALSE to let ATCI judge if the it can handle the command */
    return KAL_FALSE;
	
}

/*****************************************************************************
* FUNCTION
*  	custom_get_atcmd_symbol()
* DESCRIPTION
*   	This function returns special symbol for customer-defined AT command, 
*   	so AT parser can recognize its a custom command and forward the string to custom_command_handler().
*
*     CUSTOMER DOES NOT need to modify this function.
* PARAMETERS
*   	none
* RETURNS
*     kal_uint8 
*****************************************************************************/
kal_uint8 custom_get_atcmd_symbol(void)
{
   return (CUSTOM_SYMBOL);
}

/*****************************************************************************
* USER DEFINE CONSTANT
*  	RMMI_CUSTOM_DCD_VALUE_IN_DATA_STATE
* DESCRIPTION
* 	1. This value defines the control DCD value for data mode (CSD/GPRS dialup)
*   2. CUSTOMER CAN modify this value accroding to its TE requirement
*****************************************************************************/
#define RMMI_CUSTOM_DCD_VALUE_IN_DATA_STATE (1)

/*****************************************************************************
* USER DEFINE CONSTANT
*  	RMMI_CUSTOM_DCD_VALUE_IN_CMD_STATE
* DESCRIPTION
* 	1. This value defines the control DCD value for AT command mode (Normal/Escaped AT)
*   2. CUSTOMER CAN modify this value accroding to its TE requirement
*****************************************************************************/
#define RMMI_CUSTOM_DCD_VALUE_IN_CMD_STATE (0)

/*****************************************************************************
* FUNCTION
*  	custom_get_dcd_value_for_data_state()
* DESCRIPTION
*   	This function returns the user-defined DCD value for data state
*
*     CUSTOMER DOES NOT need to modify this function.
* PARAMETERS
*   	none
* RETURNS
*     kal_uint8 
*****************************************************************************/
kal_uint8 custom_get_dcd_value_for_data_state(void)
{
    return (kal_uint8) RMMI_CUSTOM_DCD_VALUE_IN_DATA_STATE;
}

/*****************************************************************************
* FUNCTION
*  	custom_get_dcd_value_for_cmd_state()
* DESCRIPTION
*   	This function returns the user-defined DCD value for command state
*       It shall be inverted value of custom_get_dcd_value_for_data_state()
*     CUSTOMER DOES NOT need to modify this function.
* PARAMETERS
*   	none
* RETURNS
*     kal_uint8 
*****************************************************************************/
kal_uint8 custom_get_dcd_value_for_cmd_state(void)
{
    return (kal_uint8)RMMI_CUSTOM_DCD_VALUE_IN_CMD_STATE;
}

#ifdef __MOD_TCM__
/*****************************************************************************
* FUNCTION
*  	custom_get_gprs_dialup_connect_post_string()
* DESCRIPTION
*   This function returns the post string right after CONNECT in gprs dialup.
*
*   The return string length must be less than 64
*
*   If post_string is XXXXXX, 
*   then MS sends "<cr><lf>CONNECT XXXXXX<cr><lf>" when GPRS dialup
*   Ex.1 if post_string=" 230400", 
*        then entire output string is "<cr><lf>CONNECT 230400<cr><lf>"
*   Ex.2 if post_string=" 56000 V42bis", 
*        then entire output string is "<cr><lf>CONNECT 56000 V42bis<cr><lf>"
*    
* PARAMETERS
*   kal_uint8 act, ACcess Technology, 
                   This field value can be referred to TS27.007
                   0,   GSM
                   1,   GSM Compact
                   2,   UTRAN
                   3,   GSM w/EGPRS
                   4,   UTRAN w/HSDPA
                   5,   UTRAN w/HSUPA
                   6,   UTRAN w/HSDPA and HSUPA
* RETURNS
*     kal_uint8* post_string
*****************************************************************************/
const kal_uint8* custom_get_gprs_dialup_connect_post_string(kal_uint8 act)
{
    /* Note: The return string length must be less than 64!!! */
#ifdef __TC01__
    #if defined(__HSDPA_SUPPORT__)
/* under construction !*/
	#elif defined(__EGPRS_MODE__)
/* under construction !*/
	#else
/* under construction !*/
	#endif
#elif defined(__PS_DIALUP_CONNECT_STRING_BY_ACT__)
    static kal_uint8 temp_string[64];
    const kal_uint8* post_string = temp_string;    
    if ((act == 0) || (act == 1) || (act == 3))
    {
        strcpy(temp_string, " 236800");
    }
    else
    {
        strcpy(temp_string, " 7200000");
    }    
#else
  //Note: user MUST prepare a space before the speed number
  #if defined(__HSDPA_SUPPORT__) && defined(__UMTS_FDD_MODE__)
	static const kal_uint8 post_string[] = " 7200000"; //7.2Mbps
  #elif defined(__HSDPA_SUPPORT__) && defined(__UMTS_TDD128_MODE__)
  	static const kal_uint8 post_string[] = " 2624000"; //2.6Mbps
  #elif defined(__UMTS_FDD_MODE__) || defined(__UMTS_TDD128_MODE__)
    static const kal_uint8 post_string[] =  " 384000"; //384kbps
  #elif defined(__EGPRS_MODE__)
    static const kal_uint8 post_string[] =  " 473600"; //473.6kbps
  #else
    static const kal_uint8 post_string[] =   " 80000"; //80kbps  
  #endif
#endif
    return (const kal_uint8*) post_string;
} // MAUI_02386357, mtk02285, MAUI_02825172
#endif /* __MOD_TCM__ */

/*****************************************************************************
* FUNCTION
*  	custom_is_edit_mode_command()
* DESCRIPTION
*   This function is used to let customer judge if the input command is needed to enter 
* editor mode or not. If true, we will output "> " and wait for 
*       ctrl+z character to execute the whole command string
*       ESC character to cancel the command
*    
* PARAMETERS
*   	data    [IN]    input command string header, maximum length : 10
* RETURNS
*     KAL_TRUE or KAL_FALSE
*****************************************************************************/
kal_bool custom_is_edit_mode_command(kal_uint8 *data)
{
    /*if (strncmp(data, "AT%EDIT", 7) == 0)
        return KAL_TRUE;
    else*/
        return KAL_FALSE;
}

#if defined(__PLMN_LIST_WITH_CELL_INFO__)
kal_uint32 custom_at_posi_get_ndssign(kal_char *buffer, kal_uint32 buf_len, kal_uint8 plmn_num, l4c_rat_plmn_info_struct *list)
{
    /* buf_len: MAX size of the 'buffer' please do not cruppt
       string_length: Indicates how many bytes writes into 'buffer'
    */
    
   /* Prototype of l4c_rat_plmn_info_struct
            #ifdef __PLMN_LIST_WITH_CELL_INFO__
                #define MAX_NUM_CELL_PER_PLMN  10
            #endif 
            
            #if defined(__PLMN_LIST_WITH_CELL_INFO__)
            typedef struct {
                kal_uint16       arfcn;
                kal_int16        rxlev;
                kal_uint8        bsic;
                kal_uint8        la_code[2];
                kal_uint16       cell_id;
                }l4c_location_cell_info_struct;
            #endif
            
            typedef struct {
               kal_uint8   plmn_id[7];
               kal_uint8   status;
               kal_uint8 rat;
               #if defined(__PLMN_LIST_WITH_CELL_INFO__)
               l4c_location_cell_info_struct cell_list[MAX_NUM_CELL_PER_PLMN];
               #endif
            } l4c_rat_plmn_info_struct;
      */
     /* sample code, judge how many PLMN and cell info in the parameter 'list'
          kal_uint8 i;
          kal_uint8 j;
          kal_uint8 ended;
          kal_uint16 temp_lac;
          kal_uint16 temp_lac_2;
          
          for (i = 0; i < plmn_num; i++)
            {
                for(j = 0; j < MAX_NUM_CELL_PER_PLMN; j++)
                {
                    temp_lac = list[i].cell_list[j].la_code[0];
                    temp_lac = (temp_lac << 8) | (list[i].cell_list[j].la_code[1]);

                    if((temp_lac == 0) && (list[i].cell_list[j].cell_id == 0))
                    {
                        break;
                    }

                    // Judge if this is the last cell info 
                    if((i == (plmn_num - 1)) && (j == (MAX_NUM_CELL_PER_PLMN - 1)))
                    {
                        ended = 1;
                    }
                    else if(i == (plmn_num - 1))
                    {
                        temp_lac_2 = list[i].cell_list[j+1].la_code[0];
                        temp_lac_2 = (temp_lac_2 << 8) | (list[i].cell_list[j+1].la_code[1]);

                        if((temp_lac_2 == 0) && (list[i].cell_list[j+1].cell_id == 0))
                        {
                            ended = 1;
                        }
                    }
                 }
             }
    */
    kal_uint32 string_length = 0;
    
    /* Replace the line after thie comment, calculate NDSSIGN and write into buffer */
    string_length = kal_sprintf(buffer, "\"NDSSIGN\"");

    
    /* It's recommended that do not remove the codes after this line! */
    if(string_length > buf_len)
    {
        /* Add length check, void memory curruption */
        ASSERT(0);
    }
    return string_length;
}

kal_bool custom_process_at_posi()
{
	  // customer code
    return KAL_FALSE;
}
#endif

/*****************************************************************************
* FUNCTION
*  	custom_at_response_result_generator()
* DESCRIPTION
*   	This function should generate the custom AT intermediate and response
*       Customer should maintain and modify the code.
* PARAMETERS
*   	kal_uint8 *src_date:   [IN] original string
*       kal_uint16 src_len:    [IN] len of original string
*       kal_uint8 *final_data: [OUT] formatted string
*       kal_uint8 format:      [IN] ATV0/1, see 3gpp 27.007 for more
*       kal_uint8 s3:          [IN] command line termination character, see 3gpp 27.007 for more
*       kal_uint8 s4:          [IN] reponse formatting character, see 3gpp 27.007 for more
*       kal_bool force:       [IN] always apply cust format if true for intermediate starting with alpha-numeric
*       kal_bool stuff:        [IN] original setting in rmmi_write_to_uart
* RETURNS
*    kal_uint16: length of formatted string, 0 will use MTK default format
*****************************************************************************/
kal_uint16 custom_at_response_result_generator(kal_uint8 *src_data, kal_uint16 src_len, kal_uint8 *final_data, kal_uint8 format, kal_uint8 s3, kal_uint8 s4, kal_bool force, kal_bool stuff)
{
    kal_uint16 len = 0;
    kal_bool   is_exception = KAL_FALSE;

#ifdef __CUSTOM_AT_FORMAT__

    // exception
    if (!stuff)
    {
        return 0;
    }

    if (src_data[0] == RMMI_CHAR_PLUS)
    {
        // +CME ERROR
        if (((src_data[1] == RMMI_CHAR_C) || (src_data[1] == rmmi_char_c)) &&
            ((src_data[2] == RMMI_CHAR_M) || (src_data[2] == rmmi_char_m)) &&
            ((src_data[3] == RMMI_CHAR_E) || (src_data[3] == rmmi_char_e)))
        {
            is_exception = KAL_TRUE;
        }
    }
    else if ((src_data[0] != RMMI_MONEY) && (!force))
    {
        is_exception = KAL_TRUE;
    }

    if (!is_exception)
    {
        kal_uint16 i;

        kal_sys_trace("custom at response result");

        final_data[0] = s3;
        final_data[1] = s4;
        len += 2;

        for (i = 0; i < src_len; i++)
        {
            final_data[len + i] = *((kal_uint8 *)src_data + i);
        }

        len += src_len;
    }

#endif /* __CUSTOM_AT_FORMAT__ */

    return len;
}

/*****************************************************************************
* FUNCTION
*  	custom_block_urc_to_bcm()
* DESCRIPTION
*   This function is used to let customer block specific URC  
* PARAMETERS
*   	buffer    [IN]    input urc string header and content
* RETURNS
*       KAL_TRUE or KAL_FALSE
*****************************************************************************/
kal_bool custom_block_urc(kal_uint8 *buffer)
{
    if(strncmp((char*)buffer, "+EGPSC", strlen("+EGPSC"))== 0)//Block URC +EGPSC
        return KAL_TRUE;
    //else if()
        //return KAL_TRUE;
    return KAL_FALSE;
}
#ifdef __GPS_TRACK__

extern void rmmi_uart_rtr_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void $Super$$rmmi_uart_rtr_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

/******************************************************************************
 *  Function    -  $Sub$$rmmi_uart_rtr_ind_hdlr
 *
 *  Purpose     -  函数嵌入修改，实现串口函数拦截处理
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void $Sub$$rmmi_uart_rtr_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    uart_ready_to_read_ind_struct *data = (uart_ready_to_read_ind_struct *)local_para_ptr;
    if(data->port == 6)
    {
        kal_uint16 len;
        kal_uint8 *buf;
        buf = (kal_uint8 *)((kal_uint8 *)data + sizeof(uart_ready_to_read_ind_struct));
        memcpy(&len, buf, 2);
        OTA_LOGD(L_SYS, L_V4, "module_id:%d,%d", kal_get_active_module_id(), len);
        if(len < 256)
        {
            OTA_track_atci_at_command_buf(2, buf + 2, &len);
            data->port = 0;
            $Super$$rmmi_uart_rtr_ind_hdlr(local_para_ptr, peer_buff_ptr);
        }
        else
        {
            extern kal_uint32 INT_MemoryDumpFlag;
            INT_MemoryDumpFlag = 0x26409001;
            ASSERT(0);
        }
    }
    else
    {
        $Super$$rmmi_uart_rtr_ind_hdlr(local_para_ptr, peer_buff_ptr);
    }
}
#endif /* __GPS_TRACK__ */

