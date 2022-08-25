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
 *  AGPSSUPLOTAP.h
 *
 * Project:
 * --------
 *
 *
 * Description:
 * ------------
 *
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _AGPSSUPLOTAP_H_
#define _AGPSSUPLOTAP_H_

#ifdef __MMI_AGPS_OTAP__

typedef enum
{
    MMI_SUPL_NS_OMA_BOOTSTRAP,   /* L1 node */
    MMI_SUPL_NS_OMA_PROXY,       /* L1 node */
    MMI_SUPL_NS_OMA_APP,         /* L1 node */
    MMI_SUPL_NS_OMA_APPADDR,
    MMI_SUPL_NS_OMA_TOTAL
} mmi_supl_ns_oma_enum;

typedef struct
{
    U32 account_id;
    U16 name[AGPS_MAX_PROFILE_NAME_LEN];
    U16 addr[AGPS_MAX_PROFILE_ADDR_LEN];
    U8 nap_id[MMI_SUPL_OTA_HASH_LEN];
    U8 proxy_id[MMI_SUPL_OTA_HASH_LEN];
    U8 match_index;
    MMI_BOOL addr_type_valid;
    MMI_BOOL wait_fill_addr;
    MMI_BOOL is_used;
} mmi_supl_profile_struct;

typedef struct
{
#if(MMI_SIM_TOTAL > 1)
    mmi_supl_profile_struct profile_list[NVRAM_EF_AGPS_PROFILE_TOTAL * NVRAM_EF_GPS_MMI_SIM_DATA_TOTAL];
#else
    mmi_supl_profile_struct profile_list[NVRAM_EF_AGPS_PROFILE_TOTAL];
#endif

    S32 sel_profile_index;
    S32 config_handle;
    S16 curr_index;
    U16 config_id;
    U16 sim_id;
    MMI_BOOL is_update;
    MMI_BOOL is_install;
    U8 provurl[MMI_SUPL_OTA_HASH_LEN];
    U8 count;
    U8 sim_profile_id;
    mmi_id cur_gid;
    mmi_id cui_id;
} mmi_supl_ota_context_struct;

extern void mmi_supl_handle_app_configure(mmi_cca_app_configure_ind_struct *newconfigdoc);
extern void mmi_supl_ota_select(void);
extern void mmi_supl_ota_check_next_profile(void);
extern void mmi_supl_ota_install_status(void);

#endif /* __MMI_AGPS_OTAP__ */

#endif /* _AGPSSUPLOTAP_H_ */


