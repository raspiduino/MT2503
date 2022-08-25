/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  gps_meta_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for local parameter declaration about GIS sap
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 *******************************************************************************/
#ifndef __GPS_META_STRUCT_H__
#define __GPS_META_STRUCT_H__




#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "gps_struct.h"




/*meta mode gps operation request ----------------------------------------------*/
typedef enum {
    META_GPS_OP_START_MP_TEST=0, /* start signal mode test */
    META_GPS_OP_STOP_MP_TEST,		 /* stop  signal mode test */
    META_GPS_OP_QUERY_CMD_BITMAP,/* query bitmap supported for signal mode test */
    META_GPS_OP_START_CW_TEST,   /* start CW mode test */
    META_GPS_OP_STOP_CW_TEST,    /* stop  CW mode test */
    META_GPS_OP_START_CNR_TEST,  /* start CNR mode test */
    META_GPS_OP_STOP_CNR_TEST,   /* stop  CNR mode test */
    META_GPS_OP_START_FIX_TEST,  /* start fix mode test */
    META_GPS_OP_STOP_FIX_TEST,   /* stop  fix mode test */
    //here may add other operation type for future
    MAX_NUM_OF_META_GPS_OP_CMD_TYPE, 
} meta_gps_op_cmd_type_enum;

typedef struct  {
  
  meta_gps_op_cmd_type_enum   cmd_type;
  kal_uint32   SV_id;      /* SV id:(1~32) */
  kal_uint32   cmd_bitmap; /* cmd_bitmap: test control bitmap for cmd  META_GPS_OP_START_TEST */
} meta_gps_op_cmd_struct;

typedef enum {
    META_GPS_OP_OPEN=0,
    META_GPS_OP_CLOSE,
    META_GPS_OP_WRITE_CMD,
    //here may add other operation type for future
    MAX_NUM_OF_META_GPS_OP_TYPE, 
} meta_gps_op_type_enum;

typedef struct  {
  LOCAL_PARA_HDR
  meta_gps_op_type_enum  op_type;
  meta_gps_op_cmd_struct cmd;  
} meta_gps_op_req_struct;


/*meta mode gps operation responce---------------------------------------------- */
typedef enum {
  META_GPS_OPEN_SUCCESS = 0,
  META_GPS_OPEN_FAIL,
  META_GPS_CLOSE_DONE,
  META_GPS_START_MP_TEST_SUCCESS,
  META_GPS_START_MP_TEST_FAIL,
  META_GPS_STOP_MP_TEST_SUCCESS,
  META_GPS_STOP_MP_TEST_FAIL,
  META_GPS_SV_ID_INVALID,
  META_GPS_QUERY_BITMAP_SUCCESS,
  META_GPS_CMD_BITMAP_INVALID,
  /* CW test responce */
  META_GPS_START_CW_TEST_SUCCESS,  
  META_GPS_START_CW_TEST_FAIL,
  META_GPS_STOP_CW_TEST_SUCCESS,
  META_GPS_STOP_CW_TEST_FAIL,
  /* CNR test responce */
  META_GPS_START_CNR_TEST_SUCCESS,
  META_GPS_START_CNR_TEST_FAIL,
  META_GPS_STOP_CNR_TEST_SUCCESS,
  META_GPS_STOP_CNR_TEST_FAIL,
  /* FIX test responce */
  META_GPS_START_FIX_TEST_SUCCESS,
  META_GPS_START_FIX_TEST_FAIL,
  META_GPS_STOP_FIX_TEST_SUCCESS,
  META_GPS_STOP_FIX_TEST_FAIL,
  /* Exception hanler resp */
  META_GPS_NOT_OPEN_YET,
  META_GPS_INVALID_CMD,
  
  MAX_NUM_OF_META_GPS_OP_RSP,
 //here may add other response enum for future
} meta_gps_op_rsp_enum ;
typedef struct {
  LOCAL_PARA_HDR
  meta_gps_op_rsp_enum   rsp_type;  
  kal_uint32             valid_cmd_bitmask; /* cmd_bitmap: valid bitmask for cmd  META_GPS_OP_START_TEST */
} meta_gps_op_rsp_struct ;


/*meta mode gps test result indication---------------------------------------------- */
typedef enum {
 META_GPS_MP_TEST_FINISHED = 0,
 META_GPS_DATA_IND_INFOR_VERSION,
 META_GPS_DATA_IND_INFOR_FIXCTRL,
 META_GPS_DATA_IND_ACQ, 
 META_GPS_DATA_IND_BITSYNC,
 META_GPS_DATA_IND_SIGNAL,
 META_GPS_DATA_IND_CW_TEST_RESULT,
 META_GPS_DATA_IND_CNR_TEST_RESULT,
 META_GPS_DATA_IND_FIX_TEST_RESULT,
 MAX_NUM_OF_META_GPS_DATA_IND_ENUM,
}meta_gps_data_ind_type_enum;

typedef union{
 gps_mp_test_result_union    mp_result;           /* test result for meta mp  mode(signal test mode) */
 gps_cw_test_result_struct   cw_result;           /* test result for meta cw  mode */                                  
 gps_cnr_test_result_struct  cnr_result;          /* test result for meta cnr  mode */                                 
 gps_fix_test_result_struct  fix_result;          /* test result for meta fix  mode */ 
}gps_meta_test_result_union;

typedef struct  {
 LOCAL_PARA_HDR
 meta_gps_data_ind_type_enum ind_type;
 kal_uint32                  test_finished_flag;
 gps_meta_test_result_union    result;              /*  meta mode test result */                               
} meta_gps_data_ind_struct;


#endif /*__GPS_META_STRUCT_H__*/

