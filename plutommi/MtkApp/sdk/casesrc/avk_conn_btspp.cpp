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
#ifdef __MMI_SPP_SUPPORT__
extern "C"
{
#include "MMIDataType.h"
#include "BtcmSrvGprot.h"
#include "SppSrvGprot.h"
#include "BtcmCuiGprot.h"
}

#define AVK_TEST_UUID 0xFFFC

#define AVK_SPP_REJECT_CASE_FLAG 0x00000001
//#define AVK_SPP_WRITE_BUFFER_FLAG 0x00000002

static CHAR testString[] ={"AVK Test"};

typedef struct
{
    SppHandle sppsrv_hd;
    S32 conn_id;
    U32 flag;
    CHAR buf[SRV_SPP_MIN_BUFF_SIZE];
} avk_sppc_cntx;


static avk_sppc_cntx g_sppc_cntx;


//================================================================================
//================================================================================
AVK_ADD_ITEM(AVK_CONN_BTSPP_CLIENT_CASE, L"BTSPP Client cases", AVK_CONN_BTSPP);

static S32 avk_sppc_event_handler(U32 event, void* para)
{
    kal_wap_trace(
        MOD_MMI_CONN_APP,
        TRACE_GROUP_7,
        "[AVK_SPP]avk_sppc_event_handler()event(0x%x),flag(0x%x)",
        event,
        g_sppc_cntx.flag);

    switch (event)
    {
        case SRV_SPP_EVENT_CONNECT:
        {
            srv_spp_event_cntx* event_p = (srv_spp_event_cntx*)para;
            kal_wap_trace(
                MOD_MMI_CONN_APP,
                TRACE_GROUP_7,
                "[AVK_SPP]avk_sppc_event_handler(),ret(%d),flag(%d)",
                event_p->ret,
                g_sppc_cntx.flag);

            if (event_p->ret)
            {
                g_sppc_cntx.conn_id = event_p->para;
                AVK_CASE_RESULT(AVK_PASS);
            }
            else
            {
                if (!(g_sppc_cntx.flag & AVK_SPP_REJECT_CASE_FLAG))
                {
                    g_sppc_cntx.flag |= AVK_SPP_REJECT_CASE_FLAG;
                    const srv_bt_cm_dev_struct* dev_info = srv_bt_cm_get_dev_info_by_index(0, SRV_BT_CM_PAIRED_DEV);
                    if (dev_info)
                    {
                        srv_spp_connect(
                            g_sppc_cntx.sppsrv_hd,
                            AVK_TEST_UUID,
                            (srv_bt_cm_bt_addr*)&(dev_info->bd_addr),
                            g_sppc_cntx.buf,
                            SRV_SPP_MIN_BUFF_SIZE/2,
                            SRV_SPP_MIN_BUFF_SIZE/2);
                    }
                    else
                    {
                        mmi_display_popup(
                            (UI_string_type)L"Please let the SPP server as 1st paired device!",
                            MMI_EVENT_FAILURE);

                        srv_spp_close(g_sppc_cntx.sppsrv_hd);
                        AVK_LOG_FUN(srv_spp_close, MMI_TRUE);
                        g_sppc_cntx.sppsrv_hd = -1;

                        AVK_CASE_RESULT(AVK_FAIL);
                        AVK_ASYN_DONE();
                    }
                }
                else
                {
                    AVK_CASE_RESULT(AVK_FAIL);

                    srv_spp_close(g_sppc_cntx.sppsrv_hd);
                    AVK_LOG_FUN(srv_spp_close, MMI_TRUE);
                    g_sppc_cntx.sppsrv_hd = -1;
            
                    AVK_ASYN_DONE();
                }
            }
            break;
        }

        case SRV_SPP_EVENT_READY_TO_WRITE:
        {
            U32 size;
            size = srv_spp_write(
                g_sppc_cntx.conn_id,
                testString,
                sizeof(testString));
            if (size == sizeof(testString))
            {
                AVK_LOG_FUN(srv_spp_write, MMI_TRUE);
            }
            else
            {
                AVK_LOG_FUN(srv_spp_write, MMI_FALSE);
                srv_spp_disconnect(g_sppc_cntx.conn_id);
            }

            break;
        }
    

        case SRV_SPP_EVENT_DISCONNECT:
        {
            g_sppc_cntx.conn_id = -1;

            srv_spp_close(g_sppc_cntx.sppsrv_hd);
            AVK_LOG_FUN(srv_spp_close, MMI_TRUE);
            g_sppc_cntx.sppsrv_hd = -1;
            
            AVK_ASYN_DONE();
            break;
        }
        
        default:
            break;
    }

    return MMI_RET_OK;
}

static void avk_sppc_begin_test(void)
{

    kal_wap_trace(
        MOD_MMI_CONN_APP,
        TRACE_GROUP_7,
        "[AVK_SPP]avk_sppc_begin_test()sppsrv_hd(%d)",
        g_sppc_cntx.sppsrv_hd);

    if (g_sppc_cntx.sppsrv_hd > 0)
    {
        srv_spp_close(g_sppc_cntx.sppsrv_hd);
        g_sppc_cntx.sppsrv_hd = -1;
    }

    if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_ON)
    {
        //srv_spp_init();
        //AVK_LOG_FUN(srv_spp_init, MMI_TRUE);
        memset(&g_sppc_cntx, 0, sizeof(g_sppc_cntx));

        g_sppc_cntx.sppsrv_hd = srv_spp_open();
        if (g_sppc_cntx.sppsrv_hd >= 0)
        {
            AVK_LOG_FUN(srv_spp_open, MMI_TRUE);

            U32 eventMask(
                SRV_SPP_EVENT_CONNECT |
                SRV_SPP_EVENT_READY_TO_WRITE |
                SRV_SPP_EVENT_DISCONNECT);
            srv_spp_set_notify_hdlr(g_sppc_cntx.sppsrv_hd, eventMask, avk_sppc_event_handler, NULL);
            AVK_LOG_FUN(srv_spp_set_notify_hdlr, MMI_TRUE);

            srv_spp_set_security_level(g_sppc_cntx.sppsrv_hd, SRV_SPP_SEC_NAN);
            AVK_LOG_FUN(srv_spp_set_security_level, MMI_TRUE);

            const srv_bt_cm_dev_struct* dev_info = srv_bt_cm_get_dev_info_by_index(0, SRV_BT_CM_PAIRED_DEV);
            if (dev_info)
            {
                srv_spp_connect(
                    g_sppc_cntx.sppsrv_hd,
                    AVK_TEST_UUID,
                    (srv_bt_cm_bt_addr*)&(dev_info->bd_addr),
                    g_sppc_cntx.buf,
                    SRV_SPP_MIN_BUFF_SIZE / 2,
                    SRV_SPP_MIN_BUFF_SIZE / 2);

                AVK_LOG_FUN_ASYN(srv_spp_connect);
            }
            else
            {
                mmi_display_popup(
                    (UI_string_type)L"Please let the SPP server as 1st paired device!",
                    MMI_EVENT_FAILURE);

                srv_spp_close(g_sppc_cntx.sppsrv_hd);
                AVK_LOG_FUN(srv_spp_close, MMI_TRUE);
                g_sppc_cntx.sppsrv_hd = -1;
            }
        }
        else
        {
            AVK_LOG_FUN(srv_spp_open, MMI_FALSE);

            AVK_LOG_FUN(srv_spp_set_notify_hdlr, MMI_FALSE);

            AVK_LOG_FUN(srv_spp_set_security_level, MMI_FALSE);

            AVK_LOG_FUN(srv_spp_connect, MMI_FALSE);

            AVK_LOG_FUN(srv_spp_close, MMI_FALSE);
        }
    }
    else
    {
        mmi_popup_display_ext(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            NULL);
    }
}


AVK_MANUAL_CASE(AVK_CONN_BTSPP_CLIENT_CASE_1, AVK_CONN_BTSPP_CLIENT_CASE)
{
    AVK_MANU_SHOW_TIPS(
        L"Please\n1 power on BT\n2 launch AVK test SPP server\n3 let SPP server as 1st paired device",
        avk_sppc_begin_test);
}


//================================================================================
//================================================================================
typedef struct
{
    SppHandle sppsrv_hd;
    S32 conn_id;
    U32 flag;
    CHAR buf[SRV_SPP_MIN_BUFF_SIZE];
} avk_spps_cntx;


avk_spps_cntx g_spps_cntx;


AVK_ADD_ITEM(AVK_CONN_BTSPP_SERVER_CASE, L"BTSPP Server cases", AVK_CONN_BTSPP);

static S32 avk_spps_event_handler(U32 event, void* para)
{
    kal_wap_trace(
        MOD_MMI_CONN_APP,
        TRACE_GROUP_7,
        "[AVK_SPP]avk_spps_event_handler()event(0x%x), falg(%d)",
        event,
        g_spps_cntx.flag);

    srv_spp_event_cntx* event_p = (srv_spp_event_cntx*)para;
    switch (event)
    {
        case SRV_SPP_EVENT_BIND_FAIL:
            srv_spp_close(g_spps_cntx.sppsrv_hd);
            AVK_LOG_FUN(srv_spp_close, MMI_TRUE);
            g_spps_cntx.sppsrv_hd = -1;
            break;

        case SRV_SPP_EVENT_AUTHORIZE:
        {
            if (!(g_spps_cntx.flag & AVK_SPP_REJECT_CASE_FLAG))
            {
                srv_spp_reject(event_p->para);
                AVK_CASE_RESULT(AVK_PASS);
            }
            else
            {
                srv_bt_cm_bt_addr dev_addr;
                memset(&dev_addr, 0, sizeof(dev_addr));
                srv_spp_get_dev_addr(event_p->para, &dev_addr);
                const srv_bt_cm_dev_struct* dev_info = srv_bt_cm_get_dev_info_by_index(0, SRV_BT_CM_PAIRED_DEV);
                if ((dev_addr.lap == dev_info->bd_addr.lap) &&
                    (dev_addr.uap == dev_info->bd_addr.uap) &&
                    (dev_addr.nap == dev_info->bd_addr.nap))
                {
                    AVK_LOG_FUN(srv_spp_get_dev_addr, MMI_TRUE);
                }
                else
                {
                    AVK_LOG_FUN(srv_spp_get_dev_addr, MMI_FALSE);
                }

                srv_spp_accept(
                    event_p->para,
                    g_spps_cntx.buf,
                    SRV_SPP_MIN_BUFF_SIZE / 2,
                    SRV_SPP_MIN_BUFF_SIZE / 2);

                AVK_LOG_FUN(srv_spp_accept, MMI_TRUE);
            }
            break;
        }

        case SRV_SPP_EVENT_CONNECT:
            g_spps_cntx.conn_id = event_p->para;
            break;

        case SRV_SPP_EVENT_READY_TO_READ:
        {
            CHAR tmp_buf[50];
            memset(tmp_buf, 0, sizeof(tmp_buf));
            srv_spp_read(
                g_spps_cntx.conn_id,
                tmp_buf,
                sizeof(testString));
            if (!strcmp(tmp_buf, testString))
            {
                AVK_LOG_FUN(srv_spp_read, MMI_TRUE);
            }
            else
            {
                AVK_LOG_FUN(srv_spp_read, MMI_FALSE);
            }

            srv_spp_disconnect(g_spps_cntx.conn_id);
            AVK_LOG_FUN(srv_spp_disconnect, MMI_TRUE);
            break;
        }

        case SRV_SPP_EVENT_DISCONNECT:
        {
            g_spps_cntx.conn_id = -1;

            if (!(g_spps_cntx.flag & AVK_SPP_REJECT_CASE_FLAG))
            {
                g_spps_cntx.flag |= AVK_SPP_REJECT_CASE_FLAG;
            }
            else
            {
                g_spps_cntx.flag &= ~AVK_SPP_REJECT_CASE_FLAG;
                srv_spp_close(g_spps_cntx.sppsrv_hd);
                AVK_LOG_FUN(srv_spp_close, MMI_TRUE);
                g_spps_cntx.sppsrv_hd = -1;

                AVK_ASYN_DONE();
            }
            break;
        }

        default:
            break;
    }

    return MMI_RET_OK;
}

static void avk_spps_begin_test(void)
{
    kal_wap_trace(
        MOD_MMI_CONN_APP,
        TRACE_GROUP_7,
        "[AVK_SPP]avk_spps_begin_test()g_spps_cntx.sppsrv_hd(%d)",
        g_spps_cntx.sppsrv_hd);

    if (g_spps_cntx.sppsrv_hd > 0)
    {
        srv_spp_close(g_spps_cntx.sppsrv_hd);
        g_spps_cntx.sppsrv_hd = -1;
    }

    if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_ON)
    {
        memset(&g_spps_cntx, 0, sizeof(g_spps_cntx));
        g_spps_cntx.sppsrv_hd = srv_spp_open();
        if (g_spps_cntx.sppsrv_hd >= 0)
        {
            AVK_LOG_FUN(srv_spp_open, MMI_TRUE);

            U32 eventMask(
                SRV_SPP_EVENT_BIND_FAIL |
                SRV_SPP_EVENT_AUTHORIZE |
                SRV_SPP_EVENT_CONNECT |
                SRV_SPP_EVENT_READY_TO_READ |
                SRV_SPP_EVENT_DISCONNECT);
            srv_spp_set_notify_hdlr(g_spps_cntx.sppsrv_hd, eventMask, avk_spps_event_handler, NULL);
            AVK_LOG_FUN(srv_spp_set_notify_hdlr, MMI_TRUE);

            srv_spp_bind(g_spps_cntx.sppsrv_hd, AVK_TEST_UUID);
            AVK_LOG_FUN(srv_spp_bind, MMI_TRUE);

            WCHAR service_name[] ={'B','T',' ','S','P','P',' ','A','V','K',' ','t','e','s','t', 0};

            srv_spp_set_service_name(g_spps_cntx.sppsrv_hd, service_name);
            AVK_LOG_FUN(srv_spp_set_service_name, MMI_TRUE);

            srv_spp_set_security_level(g_sppc_cntx.sppsrv_hd, SRV_SPP_SEC_NAN);
            AVK_LOG_FUN(srv_spp_set_security_level, MMI_TRUE);

            AVK_LOG_FUN_ASYN(srv_spp_reject);
        }
        else
        {
            AVK_LOG_FUN(srv_spp_open, MMI_FALSE);

            AVK_LOG_FUN(srv_spp_set_notify_hdlr, MMI_FALSE);

            AVK_LOG_FUN(srv_spp_set_service_name, MMI_FALSE);

            AVK_LOG_FUN(srv_spp_set_security_level, MMI_FALSE);

            AVK_LOG_FUN(srv_spp_bind, MMI_FALSE);

            AVK_LOG_FUN(srv_spp_close, MMI_FALSE);
        }
    }
    else
    {
        mmi_popup_display_ext(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            NULL);
    }
}


AVK_MANUAL_CASE(AVK_CONN_BTSPP_SERVER_CASE_1, AVK_CONN_BTSPP_SERVER_CASE)
{
    AVK_MANU_SHOW_TIPS(
        L"Please\n1 power on BT\n2 let SPP Client device as 1st paired device",
        avk_spps_begin_test);
}


#endif  // __MMI_SPP_SUPPORT__
#endif  // __MAUI_SDK_TEST__
