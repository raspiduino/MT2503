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
 * BtRmtCapSrvCore.c
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

#include "mmi_features.h"
#ifdef __MMI_BT_REMOTE_CAPTURE__
#include "BtRmtCapProt.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_btremotecapture_def.h"
#include "CustDataRes.h"
#include "wgui_categories_multimedia.h"
#include "wgui_categories_popup.h"

static void bt_rmtcap_itoa(kal_char *buf, kal_int32 i, kal_int32 base)
{
    kal_char *s;
#define LEN   20
   kal_int32 rem;
   static kal_char rev[LEN+1];

   rev[LEN] = 0;
   if (i == 0)
   {
      buf[0] = '0';
      ++buf;
      return;
   }
   s = &rev[LEN];
   while (i)
   {
      rem = i % base;
      if (rem < 10)
         *--s = rem + '0';
      else if (base == 16)
         *--s = "abcdef"[rem - 10];
      i /= base;
   }
   while (*s)
   {
      buf[0] = *s++;
      ++buf;
   }
}

U16 mmi_bt_rmt_cap_gen_cmd_launch(char *cmd)
{
    mmi_bt_rmt_launch_cmd_struct launch_cmd = {0};
    
    bt_rmtcap_itoa(launch_cmd.cmd_type, MMI_BT_RMTCAP_CMD_LAUNCH, 10);
    bt_rmtcap_itoa(launch_cmd.para_num, 0, 10);

    sprintf(cmd,"%s %s",
        launch_cmd.cmd_type, 
        launch_cmd.para_num);

    return strlen(cmd);
}


U16 mmi_bt_rmt_cap_gen_cmd_capture(char *cmd)
{
    mmi_bt_rmt_capture_cmd_struct capture_cmd = {0};
    
    bt_rmtcap_itoa(capture_cmd.cmd_type, MMI_BT_RMTCAP_CMD_CAPTURE, 10);
    bt_rmtcap_itoa(capture_cmd.para_num, 0, 10);

    sprintf(cmd,"%s %s",
        capture_cmd.cmd_type, 
        capture_cmd.para_num);

    return strlen(cmd);
}


U16 mmi_bt_rmt_cap_gen_cmd_exit(char *cmd)
{
    mmi_bt_rmt_exit_cmd_struct exit_cmd = {0};
    
    bt_rmtcap_itoa(exit_cmd.cmd_type, MMI_BT_RMTCAP_CMD_EXIT, 10);
    bt_rmtcap_itoa(exit_cmd.para_num, 0, 10);

    sprintf(cmd,"%s %s",
        exit_cmd.cmd_type, 
        exit_cmd.para_num);

    return strlen(cmd);
}


U16 mmi_bt_rmt_cap_gen_cmd_preview(char *cmd)
{
    mmi_bt_rmt_preview_cmd_struct preview_cmd = {0};
    
    bt_rmtcap_itoa(preview_cmd.cmd_type, MMI_BT_RMTCAP_CMD_PRVIEW, 10);
    bt_rmtcap_itoa(preview_cmd.para_num, 0, 10);

    sprintf(cmd,"%s %s",
        preview_cmd.cmd_type, 
        preview_cmd.para_num);

    return strlen(cmd);
}


U16 mmi_bt_rmt_cap_gen_cmd_genaral(char *cmd, mmi_bt_rmt_cap_cmd_type cmd_type, void *data)
{
    U16 cmd_len = 0;
    memset(cmd, 0, MMI_BT_RMTCAP_MAX_CMD_LENGTH);

    switch (cmd_type)
    {
        case MMI_BT_RMTCAP_CMD_LAUNCH:
        {
            cmd_len = mmi_bt_rmt_cap_gen_cmd_launch(cmd);
            break;
        }
        case MMI_BT_RMTCAP_CMD_CAPTURE:
        {
            cmd_len = mmi_bt_rmt_cap_gen_cmd_capture(cmd);
            break;
        }
        case MMI_BT_RMTCAP_CMD_EXIT:
        {
            cmd_len = mmi_bt_rmt_cap_gen_cmd_exit(cmd);
            break;
        }
        case MMI_BT_RMTCAP_CMD_PRVIEW:
        {
            cmd_len = mmi_bt_rmt_cap_gen_cmd_preview(cmd);
            break;
        }
    }
    return cmd_len;
}

#endif/*__MMI_BT_REMOTE_CAPTURE__*/