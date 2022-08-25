/******************************************************************************
 * track_cust_ussd.h - 
 * 
 * Copyright .
 * 
 * DESCRIPTION: - 
 *        
 * 
 * modification history
 * --------------------
 * 
 ******************************************************************************/

#ifndef _TRACK_CUST_USSD_H
#define _TRACK_CUST_USSD_H

/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/
#include "ps_public_struct.h"

/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
#define MAX_DIGITS_USSD          183

/***************************************************************************** 
* Typedef  Enum
*****************************************************************************/


/*****************************************************************************
 *  Struct					数据结构定义
 *****************************************************************************/
typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 ton_npi;
   kal_uint8 length;
   kal_uint8 ss_dcs;
   kal_uint8 ss_string[MAX_DIGITS_USSD];
   kal_bool change_phase_req;
   kal_uint8 type_of_modification;
   kal_uint8 cf_number_length; /* [MAUI_01722785] add cf number interface */
   kal_uint8 explicit_ss_op; //MAUI_02553565 explicit SS operation
} l4ccsm_ciss_ss_parse_req_struct;

typedef struct
{
    kal_uint8	ref_count;
    kal_uint8    lp_reserved;
    kal_uint16	msg_len;
    kal_uint8	input[MAX_DIGITS_USSD];
    kal_uint8	dcs;
    kal_uint8	length;
    kal_uint8	cf_number_length;
} mmi_ss_operation_req_struct;

typedef struct {
   kal_uint8 cause_present;
   kal_uint16 cause_value;
   kal_uint8 para_present;
#ifdef __SAT__
   kal_uint8 res;
   kal_uint8 size_of_additional_info;
   kal_uint8 additional_info[255];
#endif
} ss_return_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 return_code;
   kal_uint8 op_code;
   kal_uint8 ussd_dcs;
   kal_uint8 ussd_string[MAX_DIGITS_USSD];
   kal_uint8 ussd_string_length;
   ss_return_struct ss_return;
#ifdef WISDOM_MMI
/* under construction !*/
/* under construction !*/
#endif
   kal_bool change_phase_ind;
   kal_uint8 ss_id; //MAUI_02857408, [AGPS][UP CP conflict] Support Parallel SS
} l4ccsm_ciss_pussr_end_cnf_struct;

typedef struct
{
    kal_uint8	ref_count;
    kal_uint8    lp_reserved;
    kal_uint16	msg_len;
    l4c_result_struct	result;
    kal_uint8	para_present;
    kal_uint8	op_code;
    kal_uint8	dcs;
    kal_uint8	ussd_str[MAX_DIGITS_USSD];
    kal_uint8	length;
    kal_uint8	ussd_version;
} mmi_ss_ussd_rsp_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 ussd_dcs;
   kal_uint8 ussd_string[MAX_DIGITS_USSD];
   kal_uint8 ussd_string_length;
   kal_bool change_phase_req;   
   kal_uint8 ss_id; //MAUI_02857408, [AGPS][UP CP conflict] Support Parallel SS
} l4ccsm_ciss_pussr_begin_req_struct;

/*****************************************************************************
 *  Global Functions			全局变量
 *****************************************************************************/

/*****************************************************************************
 *  Local Functions			本地函数
 *****************************************************************************/


/*****************************************************************************
 *  Global Functions			全局函数
 *****************************************************************************/



#endif  /* _TRACK_CUST_USSD_H */
