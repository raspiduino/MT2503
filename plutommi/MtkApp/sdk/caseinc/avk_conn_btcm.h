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
#include "mmi_features.h"
#ifdef __MAUI_SDK_TEST__



#define VS_BTCM_OPTOIN_SIZE 50

typedef enum 
{
    VS_BTCM_ITEM_START,
    VS_BTCM_ITEM_SWITCH_PWR_ON,  
    VS_BTCM_ITEM_SWITCH_VIS,
    VS_BTCM_ITEM_SET_LIMIT_VIS,
    VS_BTCM_ITEM_SEARCH,
    VS_BTCM_ITEM_SEARCH_ABT,
    VS_BTCM_ITEM_PAIR,
    VS_BTCM_ITEM_SRVLIST,
    VS_BTCM_ITEM_RENAME,
    VS_BTCM_ITEM_AUTHORIZE,
    VS_BTCM_ITEM_CONNECT,
    VS_BTCM_ITEM_CONN_STOP,
    VS_BTCM_ITEM_SET_HOST_NAME,
    VS_BTCM_ITEM_READ_REMOTE_INFO,
    VS_BTCM_ITEM_AUD,
    VS_BTCM_ITEM_DELETE,
    VS_BTCM_ITEM_SWITCH_PWR_OFF,
    VS_BTCM_ITEM_FINISH,
    VS_BTCM_ITEM_TEST_ALL
}vs_btcm_menu_item;

/* BTCM entry */
extern void vs_btcm_entry_scr(void);

extern void vs_btcm_start(void);
extern void vs_btcm_switch_pwr_on(void);
extern void vs_btcm_switch_vis(void);
extern void vs_btcm_set_limit_vis(void);
extern void vs_btcm_search(void);
extern void vs_btcm_search_abt(void);
extern void vs_btcm_pair(void);
extern void vs_btcm_srvlist(void);
extern void vs_btcm_rename(void);
extern void vs_btcm_authorize(void);
extern void vs_btcm_connect(void);
extern void vs_btcm_conn_stop(void);
extern void vs_btcm_set_host_name(void);
extern void vs_btcm_read_remote_info(void);
extern void vs_btcm_aud(void);
extern void vs_btcm_delete(void);
extern void vs_btcm_switch_pwr_off(void);
extern void vs_btcm_finish(void);

extern void vs_btcm_test_all(void);

#endif
