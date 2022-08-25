/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *
 * Filename:
 * ---------
 * EONSGProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is created for EONS support (3GPP 51.11 EF OPL/PNN)
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *==============================================================================
 *******************************************************************************/

#ifndef __EONS_GPROT_H__
#define __EONS_GPROT_H__

#ifdef __MMI_EONS_SUPPORT__

#define MAX_MCC_MNC_LENGTH 3    /* Do not modify this definition */
#define MAX_OPL_PNN_RECORD 50   /* Modify this definition to support more records in EF OPL/PNN */
                                /* If this value is larger than 50, NVRAM size should also be modified */

typedef struct
{
    S8 pnn_plmn_num[MAX_MCC_MNC_LENGTH + 1];
    U8 pnn_identifier;
    U8 LAC1[2];
    U8 LAC2[2];
} eons_plmn_info;

typedef struct
{
    MMI_BOOL is_pnn_no_opl;       /* EF PNN present but EF OPL not present */
    MMI_BOOL is_got_read_pnn_rsp; /* prevent from sending this message twice before get the response */
    U8 pnn_record_number;         /* EF PNN record index to query */
    U8 opl_record_number;         /* total records read from EF OPL */
    U8 opl_record_count;          /* count for how many records which have been read */
    U8* opl_data_ptr;
    U8* pnn_data_ptr;
    eons_plmn_info plmn_info[MAX_OPL_PNN_RECORD];
} eons_context_struct;

/* EONS.c */
extern void mmi_eons_get_opl_file_info_req(void);
extern void mmi_eons_get_pnn_record_req(U8);
extern U8 mmi_eons_check_if_plmn_present(U8 *, U8 *);
extern MMI_BOOL mmi_eons_is_pnn_present_without_opl(void);
extern void mmi_eons_get_opl_record_req(U8);
extern void mmi_eons_read_opl_from_nvram(void);
extern void mmi_eons_write_opl_to_nvram(void);
extern void mmi_eons_reset_nvram(void);

#endif /* __MMI_EONS_SUPPORT__ */

extern void mmi_eons_convert_plmn_bcd_format_to_string(U8 *, U8 *);
extern MMI_BOOL mmi_eons_is_service_available(void);
extern void mmi_eons_init(void);

/* SPDI.c */
extern void mmi_idle_get_spdi_info_req(void);
extern MMI_BOOL mmi_idle_is_rplmn_in_spdi_list(void);
extern MMI_BOOL mmi_idle_is_spn_b1_set(void);
extern MMI_BOOL mmi_idle_is_spn_b2_set(void);

#endif /* __EONS_GPROT_H__ */

