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
 * Filename:
 * ---------
 *   em_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Engineer mode public structures.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

 
#ifndef _EM_PUBLIC_STRUCT_H
#define _EM_PUBLIC_STRUCT_H

#include "ps_public_struct.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "ps_em_enum.h"

typedef kal_uint32 request_info_type;

typedef enum
{
   /* RR */ 
    /* Begin of RR EM INFO Request enum */
   RR_EM_CELL_SELECT_PARA_INFO, RR_EM_INFO_BEGIN = RR_EM_CELL_SELECT_PARA_INFO,
   RR_EM_CHANNEL_DESCR_INFO,
   RR_EM_CTRL_CHANNEL_DESCR_INFO,
   RR_EM_RACH_CTRL_PARA_INFO,
   RR_EM_LAI_INFO,
   RR_EM_RADIO_LINK_COUNTER_INFO,
   RR_EM_MEASUREMENT_REPORT_INFO,
   /* ZY : Temp solution : Cell allocation list*/
   RR_EM_CA_LIST_INFO,
   /* RR new structure */
   RR_EM_CONTROL_MSG_INFO,
   RR_EM_SI2Q_INFO_STRUCT_INFO, 
   RR_EM_MI_INFO_STRUCT_INFO,
   RR_EM_BLK_INFO,
   RR_EM_TBF_INFO,
   RR_EM_GPRS_GENERAL_INFO,
#ifndef __UMTS_RAT__ 
   RR_EM_INFO_END = RR_EM_GPRS_GENERAL_INFO,
#else /* defined __UMTS_RAT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   /*End of RR EM INFO Request enum*/
   
   /* CC */ 
   CC_EM_CHANNEL_INFO,
   CC_EM_CALL_INFO,
   
   /* SS */
   SS_EM_INFO,
   
   /* MM */
   MM_EM_INFO,
   /*EM ehancement for RR new structure*/
   MMRR_EM_PLMN_INFO_STRUCT_INFO,
                                        
   /* UEM */                            
   UEM_EM_BATTERY_INFO,
   
   /* gprs em begins */
   GMM_EM_INFO,
   TCM_EM_EXT_PDP_INFO,
   TCM_EM_INT_PDP_INFO,
   TCM_EM_CONTEXT_INFO, //new
   SNDCP_EM_INFO,
   LLC_EM_INFO,
   PPP_EM_INFO,
   SM_EM_INFO,
   FLC_EM_INFO,

#ifdef __VIDEO_CALL_SUPPORT__       
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

#ifdef __UMTS_RAT__          //For MAUI, MONZA2G exclude 3G
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
#ifdef __UMTS_TDD128_MODE__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif /* __UMTS_RAT__ */   
#if defined(__UMTS_RAT__) && defined(__UMTS_TDD128_MODE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   CUS_EM_INFO_1,
   CUS_EM_INFO_2,
   CUS_EM_INFO_3,
   NUM_OF_EM_INFO
} em_info_enum;

typedef enum {
    ACCESS_CLASS_NOT_BARRED      = 0,
    ACCESS_CLASS_EMERGENCY_ONLY  = 1,
    ACCESS_CLASS_ALL_BARRED      = 2,
    ACCESS_CLASS_NOT_AVAILABLE   = 3
} access_class_level_enum;
//mtk01616_080622: for L4A code gen (Do NOT remove)
#define EM_INFO_REQ_NUM NUM_OF_EM_INFO

/* local parameter structures */

/* To identify the status of info_request */
typedef enum
{
   EM_ON  = 0,
   EM_OFF = 1,
   EM_NC  = 2 /* No change */
} em_info_status_enum;

/* For TSTL4C_EM_UPDATE_REQ */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   em_info_status_enum  info_request[NUM_OF_EM_INFO];
} tstl4c_em_update_req_struct;


/* For TSTL4C_EM_START_REQ, TSTL4C_EM_STOP_REQ */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   module_type mod_id;
   request_info_type	info_request;
} tstl4c_em_start_req_struct;

typedef tstl4c_em_start_req_struct tstl4c_em_stop_req_struct;


/* peer buffer structures */
/* RR structure */		
typedef struct
{
	kal_uint8	crh;   //CELL-RESELECT-HYSTERESIS
	kal_uint8	ms_txpwr;   // 	maximum TX power level an MS may use when accessing on a CCH
	kal_uint8	rxlev_access_min;   //	minimum received signal level at the MS for which it is permitted to access the system
} rr_em_cell_select_para_info_struct;
			
typedef struct
{
	kal_uint8	channel_type;   //	channel type
	kal_uint8	tn;   //	timeslot number
	kal_uint8	tsc;   //	training sequence code
	kal_uint8	hopping_flag;   //	hopping or not
	kal_uint8	maio;   //	MAIO value
	kal_uint8	hsn;   //	HSN value
	kal_uint8	num_of_carriers;   //	number of carriers in the BA list(in the non-hopping case, this shall be set to 1)
	kal_uint16	arfcn[64];   //	ARFCN value in the MA
	kal_bool     is_BCCH_arfcn_valid; /*the BCCH_arfcn is only valid 
	                              when receives H.O cmd in DEDI-state*/
	kal_uint16 BCCH_arfcn;   //	Target_BCCH carrier
	
	/*ZY:2006-08-15 add cipher algo for EM */
	kal_uint8	cipher_algo;  // ciphering value, OFF/A51/A52
	kal_uint8 imeisv_digit[16]; /* To show IMEISV if sent in ciphering mode setting procedure */
	
    kal_uint8 channel_mode;

	/* brwang, 051024, [AMR engineering mode info.] */
       #ifdef __AMR_SUPPORT__
//	rr_mpal_amr_req_struct amr_decode_buf;
       kal_bool amr_valid; /* the AMR(TRUE) or not(FALSE) */
//       kal_uint32 frame_number;/* the frame number to get RATSCCH messages */
//       kal_uint8 cmip;  /* CMI phase */
       kal_uint8 mr_ver;   /* MultiRate speech VERsion : 001-amr verion 1*/
       kal_bool nscb;      /* Noise Supression Control Bit : 0-noise supression is used */
       kal_bool icmi;       /* Initial Codec Mode Indicator : 0-is defined bythe implicit rule */
       kal_uint8 start_codec_mode; /* Start Codec Mode */
       kal_uint8 acs;       /* AMR Codec Activate Set */
       kal_uint8 threshold[3]; /* Threshold1/Threshold2/Threshold3 */
       kal_uint8 hysteresis[3]; /* Hysteresis1/Hysteresis2/Hysteresis3 */
       #endif
} rr_em_channel_descr_info_struct;	//This shall be used in IDLE and DEDI state
			
typedef struct
{	
	kal_uint8	mscr;   //	MSC release
	kal_uint8	att;   //	att flag
	kal_uint8	bs_ag_blks_res;   //	BS-AG-BLKS-RES
	kal_uint8	ccch_conf;   //	CCCH-CONF
	kal_uint8	cbq2;   //	Cell Bar Qualify 2
	kal_uint8	bs_pa_mfrms;   //	BS-PA-MFRMS
	kal_uint8	t3212;   //	T3212 timeout value
} rr_em_ctrl_channel_descr_info_struct;
			
typedef struct
{		
	kal_uint8	max_retrans;   //	MAX Retrans value
	kal_uint8	tx_integer;   //	TX integer
	kal_uint8	cba;   //	cell bar for access
	kal_uint8	re;   //	call reestablishment allowed
	kal_uint8	acc_class[2];   //	acces control class
	kal_bool	CB_supported;	// cell broadcast is supported
} rr_em_rach_ctrl_para_info_struct;
			
typedef struct
{			
	kal_uint16	max_value;   //	timeout value for the DSF or RLF
	kal_int16	current_value;   //	current value in the DSF or RLF calculation
	kal_uint8	dtx_ind;	//DTX indicator
	kal_uint8	dtx_used;	//DTX used or not
	kal_bool	is_dsf;		//timeout value for the DSF or RLF	
} rr_em_radio_link_counter_info_struct;  //This shall be used in IDLE and DEDI state
			
typedef struct
{
	
	kal_uint8	rr_state;	//current RR state	3: IDLE, 4: ACCESS, 5: PKT_TRANSFER 6: DEDICATED
	kal_uint16	serving_arfcn;	//serving cell ARFCN
	kal_uint8	serving_bsic;	//serving cell BSIC

	kal_uint8 serving_current_band;

	kal_uint8	serv_gprs_supported;	//serving cell support GPRS or not		
	kal_int16	serv_rla_in_quarter_dbm;	/*rssi level for serving cell (BCCH
                   	                  in IDLE-state) & (TCH in DEDI-state) & (PDTCH in TRANSFER-state) */
    	kal_bool     is_serv_BCCH_rla_valid;  /*To indicate if the serv_BCCH rssi is valid*/                   	                     
	kal_int16	serv_BCCH_rla_in_dedi_state;	/*rssi level for serving cell (BCCH) in DEDI-State*/
	kal_uint8	quality;	//serving cell -TCH measured quality	

   	/* 2003-0919, add new C31/C32 cvalue information for GPRS service */
   	kal_bool     gprs_pbcch_present; // To indicate if the current cell supports GPRS & PBCCH is present

	/* 2003-0919, add new C31/C32 cvalue information for GPRS service */
   	kal_bool     gprs_c31_c32_enable; // To indicate if the current mode is GPRS_PMO_MODE or GPRS_PCCCH_MODE
	kal_int16	c31[32];	//C31 value for the neighbor cell	   

	kal_int16	c1_serv_cell;	//C1 value for the serving cell
	kal_int16	c2_serv_cell;	/* if gprs_c31_c32_enable is false, this field is shown as c2_value for serv_cell
	                              if gprs_c31_c32_enable is true, this field is shown as c32_value for serv_cell */
	kal_int16	c31_serv_cell;	/* if gprs_c31_c32_enable is false, this field is ignore
	                              if gprs_c31_c32_enable is true, this field shall be shown in based on report c31_value*/
	                                 

	kal_uint8	num_of_carriers;	//number of carriers in the BA list
	kal_uint16	nc_arfcn[32];	//ARFCN value in the BA list(The list will be sorted by the RSSI level)
	kal_int16	rla_in_quarter_dbm[32];	//rssi level for each carrier
	kal_uint8	nc_info_status[32];	/*Bit0 = 0: "nc_bsic","frame_offset","ebit_offset" is invalid
									Bit0 = 1: "nc_bsic","frame_offset","ebit_offset" is valid
             									Bit1 = 0: "c1","c2" is invalid
             									Bit1 = 1: "c1","c2" is valid 
             									Bit2 = 0: "gprs_status" is invalid
             									Bit2 = 1: "gprs_status" is valid */
	kal_uint8	nc_bsic[32];	//neighbor cell BSIC
	kal_int32	frame_offset[32];	//frame offset for each carrier
	kal_int32	ebit_offset[32];	//ebit offset for each carrier
	kal_int16	c1[32];	//C1 value for the neighbor cell
	kal_int16	c2[32];	/* if gprs_c31_c32_enable is false, this field is shown as c2_value for nbr_cell
                           if gprs_c31_c32_enable is true, this field is shown as c32_value for nbr_cell */

	
	//kal_uint8	nbr_gprs_supported[32];	//0: not supported, 1: supported
	kal_uint8	multiband_report;	//MULTIBAND_REPORT value
	kal_uint8	timing_advance;		//Timing advance, range is 0 - 63

    kal_int16 tx_power_level; 
    kal_int16 serv_rla_full_value_in_quater_dbm;
    kal_uint8 nco;

	kal_uint8	rxqual_sub;		//rx quality (sub), range is 0 - 7
	kal_uint8	rxqual_full;		//RX quality (full), range is 0 - 7
	kal_int16       using_tx_power_in_dbm; /*DL_DTX_AND_TX_POWER*/
#ifdef __AMR_SUPPORT__
    kal_bool amr_info_valid;
    kal_uint8 cmr_cmc_cmiu_cmid;
    kal_uint8 c_i;
    kal_uint16 icm;
    kal_uint16 acs;
    kal_bool dl_dtx_used; /*DL_DTX_AND_TX_POWER*/ 
#endif /* __AMR_SUPPORT__ */
/* brwang, 05/12/27, cell lock support */    
#ifdef __FWP_NC_LAI_INFO__
	kal_uint8	num_of_nc_lai;			/* how many valid LAI info in nc_lai[] array */
	rr_em_lai_info_struct	nc_lai[6]; 	/* store LAI and CID for at most 6 strongest neighbor cells */
#endif /* __FWP_NC_LAI_INFO__ */
/* brwang, 05/12/27, cell lock support */   
} rr_em_measurement_report_info_struct;	//This shall be used in IDLE and DEDI state;
			

/*ZY : 2007/07/25 : Add for Cell allocation list*/
typedef struct
{
        kal_uint8   valid;
        kal_uint8   number_of_channels;
        kal_uint16 arfcn_list[64];
} rr_em_ca_list_info_struct;  


typedef struct
{	
	kal_uint8	msg_type;	/*receives msg type from network in Dedi-State
	                          0: Assignment Command
	                          1: Channel Release
	                          2: Additional Assignment 
	                          3: Classmark Enquiry
	                          4: Ciphering Mode Command
	                          5: Configure Change Command
	                          6: Handover Command
	                          7: Frequency Redefinition
	                          8: Channel Mode Modify
	                          9: Cell Selection Indicator*/
	                           	                           

   kal_uint8 rr_cause;

} rr_em_control_msg_info_struct;


/*Byron: 2006/08/06: Add for SI2q information*/
typedef struct
{
	kal_bool 	present;	
	kal_uint8 no_of_instance;
	kal_bool 	emr_report;
       kal_bool 	pemr_report;
	kal_bool 	umts_parameter_exist;
} rr_em_si2q_info_struct;


/*Byron: 2006/08/06: Add for measurement information*/
typedef struct
{
	kal_bool 	present;
	kal_uint8 no_of_instance;
	kal_bool 	emr_report;
	kal_bool 	umts_parameter_exist;
} rr_em_mi_info_struct;

/* James 2012/8/15: move up gprs info for EM UT */
#ifdef __PS_SERVICE__
typedef struct 
{
	kal_uint32 t3192;         // in msec
	kal_uint32 t3168;         // in msec
	kal_uint8  rp;            // radio priority
	kal_uint8  gprs_support;  // GPRS channel request support(0 not support, 1 support, 2 support but not decode)
	kal_uint8  egprs_support; // EGPRS channel request support(0 not support, 1 support)
	kal_uint8  sgsn_r;		  // PS domain is R99 or R98(0 R98, 1 R99)
	kal_uint8  pfc_support;   // packet flow context support(0 not support, 1 support)
	kal_uint8  epcr_support;  // EGPRS channel request support(0 not support, 1 support)
	kal_uint8  bep_period;	  // BEP period
}rr_em_gprs_general_info_struct;
#endif /* #ifdef __PS_SERVICE__ */

/**************************************************************************
  * GSM DM - Engineer Mode
  *
  * Notes: Following structures are maintained by RR task                                               
  **************************************************************************/
/***************************** Beging of RR DM EM Config  **************************/

#ifndef _RRM_CONTEXT_H_
    typedef enum 
    {
        RRM_NULL_STATE               = 0,
        RRM_INACTIVE_STATE           = 1,
        RRM_CELL_SEL_STATE           = 2,
        RRM_IDLE_STATE               = 3,
        RRM_ACCESS_STATE             = 4,
        RRM_PKT_TRANSFER_STATE       = 5,
        RRM_DEDICATED_STATE          = 6,
        RRM_CELL_RESEL_STATE         = 7,
        RRM_NUM_STATES               = 8
    } rrm_state_enum;
#endif

#ifndef _ENH_PARAMS_SRC_ENUM
#define _ENH_PARAMS_SRC_ENUM
    typedef enum
    {
        SRC_INVALID,
        SRC_SI,
        SRC_MI,
        SRC_PSI,
        SRC_PMO,
        SRC_DEFAULT
    } enh_params_src_enum;
#endif

#ifdef __UMTS_RAT__
/* under construction !*/
#ifndef _RRM_CONTEXT_H_
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
#ifdef __UMTS_FDD_MODE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__UMTS_FDD_MODE__*/
/* under construction !*/
#ifdef __UMTS_TDD128_MODE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__UMTS_TDD128_MODE__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __UMTS_FDD_MODE__ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__UMTS_FDD_MODE__*/
/* under construction !*/
#ifdef __UMTS_TDD128_MODE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__UMTS_TDD128_MODE__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __UMTS_FDD_MODE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__UMTS_FDD_MODE__*/
/* under construction !*/
#ifdef __UMTS_TDD128_MODE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__UMTS_TDD128_MODE__*/
/* under construction !*/
/* under construction !*/
#endif
/***************************** End of RR DM EM Config  ****************************/

/*SHUANG_EM_UT*/ 
#ifndef __MTK_TARGET__

typedef union
    {
    rr_em_cell_select_para_info_struct rr_em_cell_select_para_info;
    rr_em_channel_descr_info_struct rr_em_channel_descr_info;
    rr_em_ctrl_channel_descr_info_struct rr_em_ctrl_channel_descr_info;
    rr_em_rach_ctrl_para_info_struct rr_em_rach_ctrl_para_info;
    rr_em_lai_info_struct rr_em_lai_info;
    rr_em_radio_link_counter_info_struct rr_em_radio_link_counter_info;
    rr_em_measurement_report_info_struct rr_em_measurement_report_info;
    rr_em_ca_list_info_struct rr_em_ca_list_info;
    rr_em_control_msg_info_struct rr_em_control_msg_info;
    rr_em_si2q_info_struct rr_em_si2q_info;
    rr_em_mi_info_struct rr_em_mi_info;

    /* James 2012/8/15: add gprs info for EM UT */
#ifdef __PS_SERVICE__
    rr_em_gprs_general_info_struct rr_em_gprs_general_info;
#endif
    
#ifdef __UMTS_RAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    }em_rr_structs_union;

#endif


/* CC structure */
typedef struct
{
   kal_uint8   cause;	//channel sync cause
   kal_uint8   channel_type;	//channel type
   kal_uint8   channel_mode;	//channel mode
} cc_em_channel_info_struct;

typedef struct
{
	kal_uint8	call_id;	//call id
	kal_uint8	ti;	//transaction identifier
	kal_uint8	state;	//call state
	kal_uint8	aux_state;	//auxiliary state
   	kal_uint8	pi; //progress indicator
	kal_uint16	cause;	//call disconnect cause
	kal_uint8	cause_location;	//cause originating locatioin   
} cc_em_call_info_struct;

/* CB structure */
typedef struct
{
	kal_uint16	sn;	//serial number
	kal_uint16	mi;	//message identifier
	kal_uint8	dcs;	//data code scheme
	kal_uint8	page;	//current number of this page
	kal_uint8	pages;	//total number of pages
} cb_em_info_struct;
     
/* SS structure */
typedef struct
{			
	kal_uint8	ss_state;	//ciss state
	kal_uint8	ti;	//transaction identifier
	kal_uint8	call_id;	//call id
	kal_uint8	invoke_id;	//invoke id
	kal_uint8	num_invoke;	//number of active invokes
	kal_uint8	op_code;	//operation code
	kal_uint8	ss_code;	//supplementary service code
	kal_uint8	bs_code;	//basic service code
} ss_em_info_struct;

/* MM structure */ 
typedef struct
{
   kal_uint8   t3212_val;	//T3212 timer value
   kal_uint8   att_flag;	//ATT flag
   kal_uint8   mm_cause;	//MM Reject cause, if any
   kal_uint8   mm_state;	//MM State
   kal_uint8   mcc[3];	//MCC
   kal_uint8   mnc[3];	//MNC
   kal_uint8   loc[2];	 //registered LAC
   kal_uint8   rac;     //registered RAC
   kal_uint8   tmsi[4];	//TMSI, if valid
   kal_bool is_t3212_running;
   kal_uint16  t3212_timer_value;
   kal_uint16  t3212_passed_time;
   kal_uint8 common_access_class; //for Access Class ¡V Common, value defined in access_class_level_enum
   kal_uint8 cs_access_class; //for Access Class ¡V CS Domain, value defined in access_class_level_enum
   kal_uint8 ps_access_class; //for Access Class ¡V PS Domain, value defined in access_class_level_enum
#if defined(__WISDOM_EM__) || defined(__ADVANCED_EM__)
   kal_uint8 imsi[9];
   kal_uint8 gsm_update_status;
   kal_uint8 current_rat;
#endif
} mm_em_info_struct;

/* UEM structure */
typedef struct
{
	kal_int32	adc_value;	//battery ADC value
	kal_uint8	battery_level;	//battery level
	kal_uint8	battery_status;	//battery status: battery_status_enum
} uem_em_battery_info;


/* The rr_em_tbf_status_struct is updated whenever TBF is established/reallocated or released. */
typedef struct
{
	kal_uint8	tbf_mode;                // GPRS or EGPRS TBF mode

	/* UL TBF info */
	kal_uint8	ul_tbf_status;      //	access/active/inactive
	kal_uint8	ul_rel_cause;       //	if applicable
	kal_uint8	ul_ts_allocation;   // timeslot allocation  
	kal_uint8 ul_rlc_mode;            // RLC ACK / UNACK mode
	kal_uint8 ul_mac_mode;         // Dynamic allocation / Extended dynamic allocation / Fixed allocation
       /* new created fields */
       kal_uint16 number_rlc_octect;  // RLC requested octect/byte number
	kal_uint8 ul_tfi;
	kal_uint8 ul_granularity;
	kal_uint8 ul_usf;
       kal_uint8 ul_tai;
       kal_uint16 ul_tqi;       
	kal_uint16  ul_window_size;    // GPRS: 64, EGPRS 64 ~1024   
			
       /* DL TBF info */
	kal_uint8	dl_tbf_status;     //	active/inactive/release pending
	kal_uint8	dl_rel_cause;      //	if applicable
	kal_uint8	dl_ts_allocation;      // Ttimeslot allocation
	kal_uint8 dl_rlc_mode;            // RLC ACK / UNACK mode
	kal_uint8 dl_mac_mode;          // Dynamic allocation / Extended dynamic allocation / Fixed allocation
       /* new created fields */
	kal_uint8 dl_tfi;
       kal_uint8 dl_tai;
	kal_uint16 dl_window_size;	// GPRS: 64, EGPRS 64 ~1024   
#ifdef __EGPRS_MODE__	
	kal_uint8 dl_out_of_memory;   // EGPRS IR out of memory indication
#endif /* __EGPRS_MODE__ */
}rr_em_tbf_status_struct;

/* The new rr_em_blk_info_struct is updated every N (configurable?) block period during TBF. 
    N should be adjusted to suitable/smooth display rate. */
typedef struct
{
	/* UL TBF info */       
	kal_uint8	ul_coding_scheme;   
	kal_uint8 ul_cv;
	kal_uint8 ul_tlli;
	kal_uint16 ul_bsn1;
#ifdef __EGPRS_MODE__	
	kal_uint16 ul_bsn2;
       kal_uint8 ul_cps;
	kal_uint8 ul_rsb;
	kal_uint8 ul_spb;
#endif /* __EGPRS_MODE__ */

	/* DL TBF info */
	kal_uint8 dl_c_value_in_rx_level;  /* for both GPRS/EGPRS C value (channel quality) */
       kal_uint8 dl_rxqual;                         /* for GPRS RX QUAL (channel quality) */
       kal_uint8 dl_sign_var;                     /* for GPRS signal variance (channel quality) */
                     
	kal_uint8 dl_coding_scheme;
	kal_uint8 dl_fbi;
	kal_uint16 dl_bsn1;	
#ifdef __EGPRS_MODE__	
	kal_uint16 dl_bsn2;
	kal_uint8 dl_cps;
	kal_uint8 dl_gmsk_mean_bep_lev;	  /* for EGPRS GMSK mean BEP level (channel quality). valid: 0 ~ 31. invalid: 255 */
	kal_uint8 dl_8psk_mean_bep_lev;	  /* for EGPRS 8PSK mean BEP level (channel quality) . valid: 0 ~ 31. invalid: 255 */
       kal_uint8 dl_tn_mean_bep_lev[8];	  /* for EGPRS Timeslot Number mean BEP level (channel quality). valid: 0 ~ 31. invalid: 255 */		
#endif /* __EGPRS_MODE__ */       
       kal_uint8 dl_tn_interference_lev[8]; /* for GPRS/EGPRS Timeslot Number interference (channel quality). valid: 0 ~ 15. invalid: 255 */		       
}rr_em_blk_info_struct;

/* Poying: 20101210. Remove for EM_MODE. */
#if 0
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
#endif

/* Poying: 20101210. Add for EM_MODE */
typedef struct{
    kal_uint8 nsapi;
    kal_uint8 data_speed_value;  // data_speed_activate_enum 
} tcm_mmi_em_data_speed_struct;

/* Poying: 20101210. Add for EM_MODE */
typedef struct{
    kal_uint8 num_of_valid_entries;                                 // indicate how many valid records in data_speed[]
    tcm_mmi_em_data_speed_struct data_speed[GPRS_MAX_PDP_SUPPORT];  // might be 1~7
} tcm_mmi_em_info_struct;

/* Poying: To check TCM EM mode by UT */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   tcm_mmi_em_info_struct tcm_em_info ;
} l4cps_check_tcm_mmi_em_info_struct;

typedef enum{ // mtk01936 SM EM mode
     LOG_EM_MODE_PDP_INACTIVE, // PDP-INACTIVE
     LOG_EM_MODE_PDP_ACTIVE_PENDING, // PDP-ACTIVE-PENDING
     LOG_EM_MODE_PDP_INACTIVE_PENDING, // PDP-INACTIVE-PENDING
     LOG_EM_MODE_PDP_ACTIVE, // PDP-ACTIVE
     LOG_EM_MODE_PDP_MODIFY_PENDING, // PDP-MODIFY-PENDING
     LOG_EM_MODE_PDP_CONTEXT_ENUM_TOTAL
} sm_em_mode_pdp_context_enum;

typedef struct
{
   /*
     * MTK Question: what is the index mean? Does it mean the PDP array index?
     * Response: Yes
     */
   kal_uint8   pdp_index;

   kal_uint8   nsapi; // NSAPI 

   /*
     * MTK Question: How many states do you need to show? Just inactive & active?
     * Response:
     * PDP status is like below
     * PDP-INACTIVE
     * PDP-ACTIVE_-PENDING
     * PDP-INACTIVE-PENDING
     * PDP-ACTIVE
     * PDP-MODIFY-PENDING
     */
   sm_em_mode_pdp_context_enum   pdp_context_status; 

   kal_uint8   ip[16]; // IPv4 address or IPv6 address(not ready)

   kal_uint16 sdu_size; // Max SDU size in Bytes

   kal_uint8   apn[100];

   /*
     * MTK Question: In our current design, we clear the cause value after PDP deactivation, do you need to see the previous deactivation cause?
     * Response:
     * If MS work normal, just see the previos deactivaion cause.
     * If MS send PDP act msg to Network, MS recevie PDP reject msg from Network, then we need to see reject casue.
     */
   kal_uint8   sm_cause;          //  if applicable

   /*
     * MTK Question: Is this the neg QoS? According to 24.008 Table 10.5.156?
     * LG Response: Yes
     */
   kal_uint8 neg_delay_class; // possible value are Decimal 1, 2, 3, 4
   kal_uint8 neg_reliability_class; // possible value are Decimal 1, 2, 3, 4, 5
   kal_uint8 neg_peak_throughput; // possible value are Decimal 1~9
   kal_uint8 neg_precedence_class; // possible value are Decimal 1, 2, 3, 4
   kal_uint8 neg_mean_throughput; // possible value are Decimal 1~18
   kal_uint8 neg_traffic_class; // possible value are Decimal 1, 2, 3, 4
   kal_uint8 neg_delivery_order; // possible value are Decimal 1, 2
   kal_uint8 neg_delivery_of_err_sdu; // possible value are Decimal 1, 2, 3
   kal_uint8 neg_max_sdu_size; // max SDU size according to 24.008 Table 10.5.156 encoding
   kal_uint8 neg_max_bitrate_up_lnk; // possible value are Decimal 1~254
   kal_uint8 neg_max_bitrate_down_lnk;  // possible value are Decimal 1~254
   kal_uint8 neg_residual_bit_err_rate; // possible value are Decimal 1~9
   kal_uint8 neg_sdu_err_ratio; // possible value are Decimal 1~7
   kal_uint8 neg_transfer_delay; // possible value are Decimal 1~62
   kal_uint8 neg_traffic_hndl_priority; // possible value are Decimal 1, 2, 3
   kal_uint8 neg_guarntd_bit_rate_up_lnk; // possible value are Decimal 1~254
   kal_uint8 neg_guarntd_bit_rate_down_lnk;  // possible value are Decimal 1~254
   kal_uint8 neg_signalling_indication;
   kal_uint8 neg_source_statistics_descriptor;
   kal_uint8 neg_ext_max_bitrate_down_lnk;
   kal_uint8 neg_ext_guarntd_bit_rate_down_lnk;
   kal_uint8 neg_ext_max_bitrate_up_lnk;
   kal_uint8 neg_ext_guarntd_bit_rate_up_lnk;
   /* Poying: 20101210. Add for EM_MODE. */
   kal_uint8 human_readable_neg_delay_class; // delay_class_enum
   kal_uint8 human_readable_neg_reliability_class; // sm_readable_reliability_class_enum
   kal_uint8 human_readable_neg_peak_throughput; // sm_readable_peak_throughput_class_enum
   kal_uint8 human_readable_neg_precedence_class; // sm_readable_precedence_class_enum
   kal_uint8 human_readable_neg_mean_throughput; // sm_readable_mean_throughput_enum
   kal_uint8 human_readable_neg_traffic_class; // sm_readable_traffic_class_enum
   kal_uint8 human_readable_neg_delivery_order; // sm_readable_delivery_order_enum
   kal_uint8 human_readable_neg_delivery_of_err_sdu; // sm_readable_delivery_of_err_sdu_enum
   kal_uint16 human_readable_neg_max_sdu_size;
   kal_uint32 human_readable_neg_max_bitrate_up_lnk;
   kal_uint32 human_readable_neg_max_bitrate_down_lnk;
   kal_uint8 human_readable_neg_residual_bit_err_rate; // sm_readable_residual_bit_error_rate_enum
   kal_uint8 human_readable_neg_sdu_err_ratio; // sm_readable_sdu_err_ratio_enum
   kal_uint16 human_readable_neg_transfer_delay; 
   kal_uint8 human_readable_neg_traffic_hndl_priority; // sm_readable_traffic_hndl_priority_enum
   kal_uint32 human_readable_neg_guarntd_bit_rate_up_lnk;
   kal_uint32 human_readable_neg_guarntd_bit_rate_down_lnk;
   kal_uint8 human_readable_neg_signalling_indication; // sm_readable_signaling_indication_enum
   kal_uint8 human_readable_neg_source_statistics_descriptor; // sm_readable_source_statistics_descriptor_enum
   kal_uint32 human_readable_neg_ext_max_bitrate_down_lnk;
   kal_uint32 human_readable_neg_ext_guarntd_bit_rate_down_lnk;
   kal_uint32 human_readable_neg_ext_max_bitrate_up_lnk;
   kal_uint32 human_readable_neg_ext_guarntd_bit_rate_up_lnk;
} sm_em_pdp_info_struct;

/* Poying: Need to define enum so Catcher can get from database */
typedef enum{
      SM_EM_MAX_PDP_SUPPORT = GPRS_MAX_PDP_SUPPORT
} sm_em_max_pdp_support_enum;

/* Poying: Should display all nsapi no matter they are active or not. */
typedef struct{
   kal_uint8   num_of_active_pdp_context;
   sm_em_pdp_info_struct pdp[GPRS_MAX_PDP_SUPPORT];
} sm_em_info_struct;


typedef struct
{
   kal_uint16	ready_timer; //Ready timer value in SECONDS.
   kal_uint16	rau_timer;   //Periodical Routing Area Updating timer value in minute
   kal_uint8	ms_state;    //MS_NULL_STATE = 0,
                            //    MS_READY_STATE,
                            //    MS_STANDBY_STATE,
                            //    MS_FORCED_TO_STANDBY_STATE
   kal_bool is_rau_timer_running;
   kal_uint16  rau_timer_passed_time; //in minute   
#if defined(__WISDOM_EM__) || defined(__ADVANCED_EM__)
   kal_uint8 ptmsi[4]; /* P-TMSI */
   kal_uint8 attach_rej_cause; /* Attach Reject Cause, mm_cause_enum */
   kal_uint8 rau_rej_cause; /* RAU Reject Cause, mm_cause_enum */
   kal_uint8 gprs_update_status; /* gprs_update_status_enum */
   kal_uint8 cipher_algo; /* Cipher algorithm */
   kal_uint8 attach_type;/* GPRS Attach Type */
   kal_uint8 gmm_state; /* GMM state, gmm_state_enum */
   kal_uint8 gprs_attach_status; /* GPRS_DETACHED = 0, GPRS_ATTACHED = 1 */
#endif /* defined(__WISDOM_EM__) || defined(__ADVANCED_EM__) */
}gmm_em_info_struct;



typedef struct
{
	kal_uint32	num_checksum_error;
	kal_uint32  requested_ip;
	kal_uint32  negotiated_ip;
	kal_uint32  requested_dns;
	kal_uint32  negotiated_dns;
} ppp_em_info_struct;


typedef struct
{
	kal_uint32	num_reasm_failure;
} sndcp_em_info_struct;

typedef struct
{
    kal_uint8   sapi_id;
    kal_uint16  n201_ui;
    kal_uint16  n201_i;
    kal_uint16  kU;
    kal_uint16  kD;
    kal_uint32	num_fcs_error;
} llc_sapi_info_struct ;

typedef struct
{
    llc_sapi_info_struct  sapi_info[2];
} llc_em_info_struct;

typedef struct
{
    kal_uint8   pool_status[255];
}flc_em_info_struct;

typedef struct
{
    kal_uint8 is_higher_pri_plmn_srch; /* indicate that if the higher priority PLMN search is performing */
    kal_uint8 hp_timeout_timer; /* higher priority PLMN search timer (6 mins per unit) */
    kal_uint8 hp_count_down_timer; /* higher priority PLMN search count down timer (6 mins per unit) */
    kal_uint8 rplmn[6]; /* RPLMN */
    kal_uint8 eq_plmn[5][6]; /* 1~5 equivalent PLMNs (6 digits for each PLMN ID) */
    kal_uint8 forbid_plmn[4][6]; /* 1~4 forbidden PLMNs (6 digits for each PLMN ID) */
#if defined(__WISDOM_EM__) || defined(__ADVANCED_EM__)
    kal_uint8 hplmn[6];
    kal_uint8 previous_rplmn[6];
    kal_uint8 requested_plmn[6];
    kal_uint8 plmn_sel_mode;
#endif
} mmrr_plmn_info_struct;


#ifdef __UMTS_RAT__    //For MAUI, MONZA2G exclude 3G
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
#ifdef __UMTS_TDD128_MODE__
/* under construction !*/
#endif
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
#ifdef __UMTS_TDD128_MODE__
/* under construction !*/
#endif
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
#if defined(__UMTS_TDD128_MODE__)
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
/* under construction !*/
#if defined(__UMTS_FDD_MODE__)
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
#ifdef __UMTS_TDD128_MODE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __UMTS_TDD128_MODE__
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
#endif /*__UMTS_TDD128_MODE__*/
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
#ifdef __UMTS_FDD_MODE__   
/* under construction !*/
#endif   
/* under construction !*/
#ifdef __UMTS_FDD_MODE__   
/* under construction !*/
/* under construction !*/
#endif
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __UMTS_RAT__ */

/**************************************************************************
  * Video Telephony (3G324M) - Engineer Mode
  *
  * Notes: Following structures are maintained by VT task                                               
  * Meggie: 2007/10/05:  Add VT EM related structures     
  **************************************************************************/
/***************************** VT EM Config  ********************************/
typedef enum{
    VT_EM_DATA_TYPE_INVALID = -1,
    VT_EM_DATA_TYPE_AUDIO = 0,
    VT_EM_DATA_TYPE_VIDEO
}vt_em_channel_data_type;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    vt_em_config_struct em_config;
}l4c_vt_em_set_config_req_struct;   /* MSG: MSG_ID_L4C_VT_EM_SET_CONFIG_REQ */

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    vt_em_config_struct em_config;
}l4c_vt_em_get_config_cnf_struct;   /* MSG: MSG_ID_L4C_VT_EM_GET_CONFIG_CNF */


/****************************  VT EM Display  ********************************/
/* Radvision strucuture dependent */
typedef enum{
    VT_EM_CALL_STATE_INIT = -1,
    VT_EM_CALL_STATE_SYNCHRONIZED = 0,
    VT_EM_CALL_STATE_CONNECTED,
    VT_EM_CALL_STATE_CONNECTEDCHANNELS,
    VT_EM_CALL_STATE_IDLE,
    VT_EM_CALL_STATE_RESETTING,
    VT_EM_CALL_STATE_LOSTSYNC
}vt_em_call_state_choice; /* Refer to Rv3G324mCallState type */

typedef enum
{
    VT_EM_CODEC_TYPE_Unknown = -1,
    VT_EM_CODEC_TYPE_Amr,
    VT_EM_CODEC_TYPE_Mpeg4,
    VT_EM_CODEC_TYPE_H264,
    VT_EM_CODEC_TYPE_H239Control,
    VT_EM_CODEC_TYPE_H239ExtendedVideo,
    VT_EM_CODEC_TYPE_G7221,
    VT_EM_CODEC_TYPE_G726,
    VT_EM_CODEC_TYPE_H324AnnexI,
    VT_EM_CODEC_TYPE_SessionReset,
    VT_EM_CODEC_TYPE_G7222,
    VT_EM_CODEC_TYPE_G7231,
    VT_EM_CODEC_TYPE_H263,
    VT_EM_CODEC_TYPE_G711,
    VT_EM_CODEC_TYPE_G722,
    VT_EM_CODEC_TYPE_G729,
    VT_EM_CODEC_TYPE_H249NavigationKey,
    VT_EM_CODEC_TYPE_H249SoftKeys,
    VT_EM_CODEC_TYPE_H249PointingDevice,
    VT_EM_CODEC_TYPE_H249ModalInterface,
    VT_EM_CODEC_TYPE_Last
} vt_em_codec_type;

/* Radvision strucuture independent */
typedef enum{
    VT_EM_MASTER_SLAVE_STATUS_INVALID = -1,
    VT_EM_SLAVE = 0,
    VT_EM_MASTER
}vt_em_master_slave_status_choice;

typedef enum{
    VT_EM_RETRANSMISSION_PROTOCOL_INVALID = -1,
    VT_EM_RETRANSMISSION_PROTOCOL_SRP = 0,
    VT_EM_RETRANSMISSION_PROTOCOL_NSRP,
    VT_EM_RETRANSMISSION_PROTOCOL_WNSRP
}vt_em_retransmission_protocol_choice;

typedef enum{
    VT_EM_RESOLUTION_INVALID = -1,
    VT_EM_RESOLUTION_SQCIF = 0,
    VT_EM_RESOLUTION_QCIF,
    VT_EM_RESOLUTION_CIF
}vt_em_video_resolution_choice;

typedef enum{
    VT_EM_H223_AL_TYPE_UNKNOWN = -1,
    VT_EM_H223_AL_TYPE_1 = 0,
    VT_EM_H223_AL_TYPE_2,
    VT_EM_H223_AL_TYPE_3
}vt_em_al_type;

typedef struct{
    kal_uint16 lcn;
    kal_uint8   is_chan_duplex;
    vt_em_codec_type   codec_type;
    vt_em_video_resolution_choice  resolution_choice;
    vt_em_al_type forward_al;
    kal_int32   max_sdu_size;
}vt_em_video_channel_info_struct;

typedef struct{
    kal_uint16 lcn;
    kal_uint8   is_chan_duplex;
    vt_em_codec_type   codec_type;
    vt_em_al_type forward_al;
    kal_int32   max_sdu_size;
}vt_em_audio_channel_info_struct;

typedef enum{
    VT_EM_RP_UNKNOWN = -1,
    VT_EM_RP_COMMAND = 0,
    VT_EM_RP_RESPONSE
}vt_em_xSRP_data_type;

typedef struct{
    kal_uint8 sq;
    vt_em_xSRP_data_type type;
}vt_em_outgoing_xSRP;

typedef struct{
    kal_uint8 sq;
    vt_em_xSRP_data_type type;
}vt_em_incoming_xSRP;

typedef struct{        
        kal_uint32 vt_csr_DL_Q_frame_num;
        kal_uint32 vt_csr_UL_Q_frame_num;
        kal_uint32 vt_MED_DL_Q_frame_num;
        kal_uint32 vt_MED_DL_Q_state;

        kal_uint32 vt_DL_video_frame_num;
        kal_uint32 vt_DL_video_frame_size;
        kal_uint32 vt_DL_video_I_frame_num;
        kal_uint32 vt_DL_video_P_frame_num;

        kal_uint32 vt_DL_audio_frame_num;
        kal_uint32 vt_DL_audio_frame_size;
        
        kal_uint32 vt_UL_video_frame_num;
        kal_uint32 vt_UL_video_frame_size;
        kal_uint32 vt_UL_video_drop_frame_num;
        kal_uint32 vt_UL_video_drop_frame_size;

        kal_uint32 vt_UL_audio_frame_num;
        kal_uint32 vt_UL_audio_frame_size;
        kal_uint32 vt_UL_audio_drop_frame_num;
        kal_uint32 vt_UL_audio_drop_frame_size;

        kal_uint32 vt_UL_csr_size;
        kal_uint32 vt_UL_csr_num;
        kal_uint32 vt_DL_csr_size;
        kal_uint32 vt_DL_csr_num;

        kal_uint32 vt_downlink_mc_tbl[16];  /* # pkts using this mc entry */
        kal_uint32 vt_uplink_mc_tbl[16];

        kal_uint32 vt_ra_add_failures;
        kal_uint32 vt_incoming_audio_crc_errors;
        kal_uint32 vt_incoming_video_crc_errors;
        kal_uint32 vt_incoming_control_crc_errors;
        kal_uint32 vt_incoming_control_total_packets;
}vt_em_statistic_info_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    em_info_enum em_info;
}l4cvt_em_display_ind_struct;   /* MSG: VT to L4C */
/************************** VT EM Definition End  *****************************/

/* __UL2_EM_MODE__ */
#if defined(__UMTS_RAT__) && defined(__UMTS_TDD128_MODE__)
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
#endif

typedef struct
{
    kal_uint8 group_id;                  /* Group ID */
    unsigned char group_name[MAX_LEN_OF_NW_GROUP_NAME];
    
    module_type  mod_id;                 /* Mod ID */

    kal_uint32 event_id;                 /* Evnet ID */
    unsigned char event_name[MAX_LEN_OF_NW_EVENT_NAME];
    
    kal_uint16 ring_tone_id;             /* Ring Tone ID */        
} em_network_event_struct;

extern em_network_event_struct em_network_event_tbl[];

extern kal_uint32 em_get_total_mod(void);

extern kal_uint32 em_get_total_info_req(void);

extern kal_uint32 em_nw_get_total_event(void);

#endif /* ~_EM_STRUCT_H */

