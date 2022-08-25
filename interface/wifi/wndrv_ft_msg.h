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
 *  wndrv_ft_msg.h
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  Message struct prototypes exported by WLAN network driver.
 *  These messages are used between FT and WNDRV.
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _WNDRV_FT_MSG_H
#define _WNDRV_FT_MSG_H

#include "wndrv_ft_types.h"
#include "wndrv_cal.h"
//#include "kal_non_specific_general_types.h"
#include "kal_general_types.h"
/*******************************************************************************
*
*  1) Function Interface
*
*******************************************************************************/
void wndrv_cal_query_chip_capability( wndrv_query_chip_capability_struct *cap );
void wndrv_cal_macaddr              ( wndrv_cal_mac_addr_struct          *mac );
void wndrv_cal_txpwr_2400M          ( wndrv_cal_txpwr_2400M_struct       *txpwr );
void wndrv_cal_txpwr_5000M          ( wndrv_cal_txpwr_5000M_struct       *txpwr );
void wndrv_cal_dac_dc_offset        ( wndrv_cal_dac_dc_offset_struct     *dcOffset );

/* Single Antenna Support Usage */
kal_bool bwcs_query_single_antenna_capability( void );
kal_bool bwcs_query_antenna_path( void );
void bwcs_set_antenna_path( kal_bool fgAntForBT );


/*----------------------------MMI/WIFI------------------------------------*/
void RFTool_WiFi_Stop           ( void );
void RFTool_WiFi_EnterTestMode  ( void );
void RFTool_WiFi_EnterNormalMode( void );
void RFTool_WiFi_DacDCOffset    ( kal_uint8  *i_ch, kal_uint8  *q_ch);
void RFTool_WiFi_ContTx         ( kal_uint8 country_code[2], wndrv_test_tx_struct cont_tx );
void RFTool_WiFi_CarrierSupp    ( kal_uint8 country_code[2], wndrv_test_tx_struct carrier_supp );
void RFTool_WiFi_LocalFreq      ( kal_uint8 country_code[2], wndrv_test_tx_struct local_freq );
void RFTool_WiFi_PktTx          ( kal_uint8 country_code[2], wndrv_test_pkt_tx_struct pkt_tx );
void RFTool_WiFi_PktTxEX        ( kal_uint8 country_code[2], wndrv_test_pkt_tx_structEX pkt_tx );
void RFTool_WiFi_PktRx          ( kal_uint32 ch_freq, void (* callback) (wndrv_test_rx_status_struct* result) );
void RFTool_WiFi_Query_PktRx    ( void );
void RFTool_WiFi_PwrMgt         ( wndrv_test_pwr_mgt_enum pwr_mgt );
void RFTool_WiFi_MCR32_Write    ( kal_uint32  mcr_index,  kal_uint32  mcr32 );
void RFTool_WiFi_MCR32_Read     ( kal_uint32  mcr_index,  kal_uint32  *mcr32 );
void RFTool_WiFi_EFUSE_Write    ( kal_uint32  mcr_index,  kal_uint32  mcr32 );
void RFTool_WiFi_EFUSE_Read     ( kal_uint32  mcr_index,  kal_uint32  *mcr32 );
void RFTool_WiFi_MCR16_Write    ( kal_uint32  mcr_index,  kal_uint16  mcr16 );
void RFTool_WiFi_MCR16_Read     ( kal_uint32  mcr_index,  kal_uint16  *mcr16 );
void RFTool_WiFi_BBCR_Write     ( kal_uint32  bbcr_index,  kal_uint8   bbcr );
void RFTool_WiFi_BBCR_Read      ( kal_uint32  bbcr_index,  kal_uint8   *bbcr );
void RFTool_WiFi_EEPROM_Write   ( kal_uint32  eeprom_index,  kal_uint16  eeprom );
void RFTool_WiFi_EEPROM_Read    ( kal_uint32  eeprom_index,  kal_uint16  *eeprom );

/*******************************************************************************
*
*  Message Interface
*
*******************************************************************************/
/***************************************************************************
*  PRIMITIVE STRUCTURE
*     wndrv_test_set_req_struct
*
*  DESCRIPTION
*     Configure and set parameters to network driver.
***************************************************************************/
typedef struct
{
   kal_uint8                   ref_count;
   kal_uint16                  msg_len;
   kal_uint32                  token;
   wndrv_test_set_data_enum    type;    /* A list of set commands */
   wndrv_test_set_data_union   data;    /* Unioin of setting data structures */
                                        /* When type is one of the following values, 
                                           some setting data are put in peer buffer.
 	                                   - WNDRV_TEST_SET_MCR32
 	                                   - WNDRV_TEST_SET_MCR16
 	                                   - WNDRV_TEST_SET_BBCR
 	                                   - WNDRV_ TEST_SET_EEPROM */                                                                                                                  
} wndrv_test_set_req_struct;


/***************************************************************************
*  PRIMITIVE STRUCTURE
*     wndrv_test_set_cnf_struct
*
*  DESCRIPTION
*     Confirmation of MSG_ID_WNDRV_TEST_SET_REQ.
***************************************************************************/
typedef struct
{
   kal_uint8                   ref_count;
   kal_uint16                  msg_len;
   kal_uint32                  token;
   wndrv_test_set_data_enum    type;        /* A list of set commands */
   kal_int32                   successful;  /* 0: success other values: failure */
} wndrv_test_set_cnf_struct;


/***************************************************************************
*  PRIMITIVE STRUCTURE
*     wndrv_test_query_req_struct
*
*  DESCRIPTION
*     Query responses or status of network driver.
***************************************************************************/
typedef struct
{
   kal_uint8                     ref_count;
   kal_uint16                    msg_len;
   kal_uint32                    token;
   wndrv_test_query_result_enum  type;    /* A list of query commands */  
                                          /* When type is one of the following values, 
                                             wndrv_test_peer_buff_query_struct are put 
                                             in peer buffer.
                                             - WNDRV_TEST_QUERY_MCR32
 	                                     - WNDRV_TEST_QUERY_MCR16
 	                                     - WNDRV_TEST_QUERY_BBCR
 	                                     - WNDRV_ TEST_QUERY_EEPROM */
} wndrv_test_query_req_struct;

/***************************************************************************
*  PRIMITIVE STRUCTURE
*     wndrv_test_query_cnf_struct
*
*  DESCRIPTION
*     Confirmation of MSG_ID_WNDRV_TEST_QUERY_REQ.
***************************************************************************/
typedef struct
{
   kal_uint8                     ref_count;
   kal_uint16                    msg_len;
   kal_uint32                    token;
   wndrv_test_query_result_enum  type;    /* A list of query commands */
   wndrv_test_query_result_union result;  /* Unioin of  query results structure */
                                          /* When type is one of the following values, 
                                             some query results are put in peer buffer.
                                             - WNDRV_TEST_QUERY_MCR32
 	                                     - WNDRV_TEST_QUERY_MCR16
 	                                     - WNDRV_TEST_QUERY_BBCR
 	                                     - WNDRV_ TEST_QUERY_EEPROM */   
} wndrv_test_query_cnf_struct;


#endif /* end of _WNDRV_FT_MSG_H */
