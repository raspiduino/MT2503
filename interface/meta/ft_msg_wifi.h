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
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   ft_msg_wifi.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Messages definition of WiFi category of FT Library
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *              HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __FT_MSG_WIFI_H__
#define __FT_MSG_WIFI_H__
#include "ft_msg_common.h"
#include "wndrv_ft_types.h"
/*******************************************************************************
*  WiFi Driver SET Operation
*******************************************************************************/
typedef struct {
    FT_H                        header;
    wndrv_test_set_data_enum    op;
    wndrv_test_set_data_union   data;
} FT_WIFI_WNDRV_SET_REQ;

typedef struct {
    FT_H                        header;
    wndrv_test_set_data_enum    op;
    kal_int32                   status;
} FT_WIFI_WNDRV_SET_CNF;

/*******************************************************************************
*  WiFi Driver QUERY Operation
*******************************************************************************/
typedef struct {
    FT_H                            header;
    wndrv_test_query_result_enum    op;
} FT_WIFI_WNDRV_QUERY_REQ;

typedef struct {
    FT_H                            header;
    wndrv_test_query_result_enum    op;
    kal_int32                       status;
    wndrv_test_query_result_union   result;
} FT_WIFI_WNDRV_QUERY_CNF;

/*******************************************************************************
*  General Operation
*******************************************************************************/
typedef enum {
     FT_WIFI_OP_QUERY_CHIP_CAPABILITY = 0
    ,FT_WIFI_OP_SET_MAC_ADDR
    ,FT_WIFI_OP_SET_TXPWR_2400M
    ,FT_WIFI_OP_SET_TXPWR_5000M
    ,FT_WIFI_OP_SET_DAC_DC_OFFSET
    ,FT_WIFI_OP_SET_TXALC_2400M
    ,FT_WIFI_OP_END
} FT_WIFI_OP;

typedef union {
    kal_uint32  dummy;
} FT_WIFI_CMD;

typedef union {
    wndrv_query_chip_capability_struct  capability;
    kal_uint32  dummy;
} FT_WIFI_RESULT;

typedef struct {
    FT_H                header;
    FT_WIFI_OP          op;
    FT_WIFI_CMD         cmd;
} FT_WIFI_REQ;

typedef struct {
    FT_H                header;
    FT_WIFI_OP          op;
    kal_int32           status;
    FT_WIFI_RESULT      result;
} FT_WIFI_CNF;

#endif // #ifndef __FT_MSG_WIFI_H__
