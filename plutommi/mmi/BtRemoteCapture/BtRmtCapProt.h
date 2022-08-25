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
 * BtRmtCapSrvProt.c
 *
 * Project:
 * --------
 *  
 *
 * Description:
 * ------------
 *   This file is for BTRemoteCapture App.
 *
 * Author:
 * -------
 * -------
 *
 *===========================================================
 ****************************************************************************/

#ifndef BT_RMTCAP_SRV_PROT_H
#define BT_RMTCAP_SRV_PROT_H

#include "mmi_features.h"

#include "MMIDataType.h"
#include "notificationGprot.h"
#include "custom_btcm_config.h"

#define MMI_BT_RMTCAP_MAX_CMD_LENGTH 40
#define MMI_BT_RMTCAP_MAX_FILE_LENGTH 80
#define MMI_BT_RMTCAP_TIME_OUT (10*1000)
#define MMI_BT_RMTCAP_PIC_DEFAULT_PATH L"z:\\@cap\\DefaultPic.jpg"
#define MMI_BT_RMTCAP_FOLDER_PATH L"z:\\@BtRmtCap"

typedef enum
{
    MMI_BT_RMTCAP_STATE_IDLE,
        
    MMI_BT_RMTCAP_STATE_LAUNCH,
    MMI_BT_RMTCAP_STATE_CAPTURE,    
    MMI_BT_RMTCAP_STATE_PRVIEW,
    MMI_BT_RMTCAP_STATE_PIC_SHOW,
    MMI_BT_RMTCAP_STATE_EXIT
}mmi_bt_rmt_cap_req_state;

typedef enum
{
    MMI_BT_RMTCAP_CMD_LAUNCH = 1,
    MMI_BT_RMTCAP_CMD_CAPTURE,
    MMI_BT_RMTCAP_CMD_EXIT,
    MMI_BT_RMTCAP_CMD_PRVIEW,
    MMI_BT_RMTCAP_CMD_END,    
}mmi_bt_rmt_cap_cmd_type;


typedef struct
{
    char cmd_type[3];
    char para_num[3];
}
mmi_bt_rmt_launch_cmd_struct;

typedef struct
{
    char cmd_type[3];
    char para_num[3];
}
mmi_bt_rmt_capture_cmd_struct;

typedef struct
{
    char cmd_type[3];
    char para_num[3];
}
mmi_bt_rmt_exit_cmd_struct;

typedef struct
{
    char cmd_type[3];
    char para_num[3];
}
mmi_bt_rmt_preview_cmd_struct;

typedef struct 
{
    U8 total;
    MMI_ID main_scrn_id;
    MMI_ID devce_list_scrn_id;
    MMI_ID show_pic_scrn_id;
    MMI_ID grp_id;  
    MMI_ID popup_src_id;

    MMI_BOOL is_remote_launched;
    MMI_BOOL need_exit_cmd;
    MMI_BOOL ignore_endkey;
    mmi_bt_rmt_cap_req_state curr_state;
    char cmd[MMI_BT_RMTCAP_MAX_CMD_LENGTH];
    WCHAR *file_name;
    S32 device_hilight_idx;
    srv_bt_cm_bt_addr *bt_addr;
}mmi_bt_rmt_cap_cntx_struct;



extern U16 mmi_bt_rmt_cap_gen_cmd_genaral(char *cmd, mmi_bt_rmt_cap_cmd_type cmd_type, void *data);

#endif