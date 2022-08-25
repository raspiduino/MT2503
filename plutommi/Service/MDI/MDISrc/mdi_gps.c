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
*  mdi_gps.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  GPS related interface, such as GPS uart and NMEA parser
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
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
*******************************************************************************/

#include "MMI_features.h"
#if defined(__GPS_SUPPORT__) || defined(__BT_GPS_SUPPORT__)
#include "kal_release.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"     /* Task message communiction */


#include "mmi_frm_gprot.h"
#include "stdlib.h"         /*math lib such as atof*/
#include "ctype.h"          /*use toupper function*/
#include "dcl.h"         /*rtc to get time*/
#include "custom_events_notify.h"
#include "mmi_rp_srv_mdi_def.h"

#include "fat_fs.h"
#include "gps_struct.h"
#include "gps_uart.h"
#include "gps_common.h"
#include "mdi_datatype.h"   /* mdi datatype */
#include "mdi_resdef.h"
#include "mdi_gps.h"
#include "gps_uart_hdlr.h"

/*****************************************************************************
* Local Variable
*****************************************************************************/
static mdi_gps_ctx_struct           g_mdi_gps_cntx;

/*****************************************************************************
* Local Function
*****************************************************************************/
static void mdi_gps_nmea_load_logging_setting(void);
static void mdi_gps_gps_raw_data_ind_hdler(void *msg);
static void mdi_gps_gps_debug_info_ind_hdler(void *msg);
static void mdi_gps_gps_location_ind_hdler(void *msg);
static void mdi_gps_gps_sentence_ind_hdler(void *msg);
static void mdi_gps_gps_p_info_ind_hdler(void *msg);

/*****************************************************************************
* FUNCTION
*  mdi_gps_send_req_to_gps_task
* DESCRIPTION
*  send MSG to task
* PARAMETERS
*  msg_id               [IN]    MSG id
*  *local_param_ptr     [IN]    local paramiter
*  para_size            [IN]    local paramiter length
* RETURNS
* void
*****************************************************************************/
static void mdi_gps_send_req_to_gps_task(msg_type msg_id,void *local_param_ptr, U32 para_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct  *ilm_ptr;
    module_type src_mod;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    src_mod = stack_get_active_module_id();
    ilm_ptr = allocate_ilm(src_mod);
    ilm_ptr->src_mod_id = src_mod;
    ilm_ptr->dest_mod_id = MOD_GPS;
    ilm_ptr->sap_id = MMI_MMI_SAP;
    ilm_ptr->msg_id = msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;
    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_uart_init
* DESCRIPTION
*  init gps uart mdi layer
* PARAMETERS
*  void
* RETURNS
* MDI_RESULT
*****************************************************************************/
mmi_ret mdi_gps_uart_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i=0 ; i<MDI_GPS_UART_PORT_MAX ; i++)
    {
        g_mdi_gps_cntx.handle[i].port = MDI_GPS_DUMMY_PORT;
        g_mdi_gps_cntx.handle[i].is_opened = MMI_FALSE;
        for(j=0 ; j<MDI_GPS_UART_APP_PER_PORT_MAX ; j++)
        {
            g_mdi_gps_cntx.handle[i].mod_id[j] = MOD_NIL;
            g_mdi_gps_cntx.handle[i].gps_uart_raw_cb[j] = NULL;
            g_mdi_gps_cntx.handle[i].gps_uart_lct_cb[j] = NULL;
        }
    }
    g_mdi_gps_cntx.logging.file_handle = -1;
    g_mdi_gps_cntx.logging.debug_info_file_handle = -1;
    g_mdi_gps_cntx.event_id = kal_create_event_group((CHAR*)"gps_uart");
    g_mdi_gps_cntx.mutex = kal_create_mutex((CHAR*)"gps_uart_mutex");

    mdi_gps_nmea_load_logging_setting();

    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_open_find_slot_add
* DESCRIPTION
*  find a slot to add callback and send msg to gps if needed
* PARAMETERS
*  index    [IN]    port index
*  mode     [IN]    open in this mode
*  gps_uart_event_callback    [IN]  callback function of APP
* RETURNS
* MDI_RESULT
*****************************************************************************/
MMI_BOOL mdi_gps_open_find_slot_add(
    U8 index,
    mdi_gps_uart_work_mode_enum mode,
    void (*gps_uart_event_callback)(mdi_gps_parser_info_enum type, void *buffer, U32 length))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gps_uart_open_req_struct            *local_param_ptr;
    U32     event_group;
    kal_eventgrpid  event_id;
    U8  j;
    module_type module_id;
    MDI_RESULT ret;
    MMI_BOOL    is_need_send_to_gps = MMI_FALSE;
    MMI_BOOL    func_ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    module_id = stack_get_active_module_id();
    if (mode == MDI_GPS_UART_MODE_LOCATION)
    {
        for (j = 0; j < MDI_GPS_UART_APP_PER_PORT_MAX; j++)
        {
            if (g_mdi_gps_cntx.handle[index].gps_uart_lct_cb[j] == gps_uart_event_callback &&
                g_mdi_gps_cntx.handle[index].mod_id[j] == module_id)
            {
                /*this callback function is in the list and module is same too*/
                return MMI_TRUE;
            }
        }
        is_need_send_to_gps = MMI_TRUE;
        for (j = 0; j < MDI_GPS_UART_APP_PER_PORT_MAX; j++)
        {
            if (g_mdi_gps_cntx.handle[index].gps_uart_lct_cb[j] != NULL &&
                g_mdi_gps_cntx.handle[index].mod_id[j] == module_id)
            {
            /*find a mod use uart so no need send request*/
                is_need_send_to_gps = MMI_FALSE;
                break;
            }
        }
        /*find if raw data mode callback in this module,if yes open lct mode*/
        for (j = 0; j < MDI_GPS_UART_APP_PER_PORT_MAX; j++)
        {
            if ((g_mdi_gps_cntx.handle[index].gps_uart_raw_cb[j] != NULL ||
                g_mdi_gps_cntx.handle[index].gps_uart_lct_qop_cb[j] != NULL) &&
                g_mdi_gps_cntx.handle[index].gps_uart_lct_cb[j] == NULL &&
                g_mdi_gps_cntx.handle[index].mod_id[j] == module_id)
            {
                g_mdi_gps_cntx.handle[index].gps_uart_lct_cb[j] = gps_uart_event_callback;
                func_ret = MMI_TRUE;
                break;
            }
        }
        /*if not found a module use raw this open lct mode in empty struct*/
        if (j == MDI_GPS_UART_APP_PER_PORT_MAX)
        {
            for (j = 0; j < MDI_GPS_UART_APP_PER_PORT_MAX; j++)
            {
                if (g_mdi_gps_cntx.handle[index].gps_uart_lct_cb[j] == NULL &&
                    g_mdi_gps_cntx.handle[index].mod_id[j] == MOD_NIL)
                {
                    g_mdi_gps_cntx.handle[index].gps_uart_lct_cb[j] = gps_uart_event_callback;
                    g_mdi_gps_cntx.handle[index].mod_id[j] = module_id;
                    func_ret = MMI_TRUE;
                    break;
                }
            }
        }
        /*no slot to add callback so request is also no need*/
        if (j == MDI_GPS_UART_APP_PER_PORT_MAX)
        {
            is_need_send_to_gps = MMI_FALSE;
        }
    }
    else if(mode == MDI_GPS_UART_MODE_RAW_DATA)
    {
        for (j = 0; j < MDI_GPS_UART_APP_PER_PORT_MAX; j++)
        {
            if (g_mdi_gps_cntx.handle[index].gps_uart_raw_cb[j] == gps_uart_event_callback &&
                g_mdi_gps_cntx.handle[index].mod_id[j] == module_id)
            {
                /*this callback function is in the list and module is same too*/
                return MMI_TRUE;
            }
        }
        is_need_send_to_gps = MMI_TRUE;
        for (j = 0; j < MDI_GPS_UART_APP_PER_PORT_MAX; j++)
        {
            if (g_mdi_gps_cntx.handle[index].gps_uart_raw_cb[j] != NULL &&
                g_mdi_gps_cntx.handle[index].mod_id[j] == module_id)
            {
            /*find a mod use uart so no need send request*/
                is_need_send_to_gps = MMI_FALSE;
                break;
            }
        }
        /*find if lct data mode callback in this module,if yes open raw mode*/
        for (j = 0; j < MDI_GPS_UART_APP_PER_PORT_MAX; j++)
        {
            if ((g_mdi_gps_cntx.handle[index].gps_uart_lct_cb[j] != NULL ||
                g_mdi_gps_cntx.handle[index].gps_uart_lct_qop_cb[j] != NULL) &&
                g_mdi_gps_cntx.handle[index].gps_uart_raw_cb[j] == NULL &&
                g_mdi_gps_cntx.handle[index].mod_id[j] == module_id)
            {
                g_mdi_gps_cntx.handle[index].gps_uart_raw_cb[j] = gps_uart_event_callback;
                func_ret = MMI_TRUE;
                break;
            }
        }
        /*find a slot to store callback*/
        /*if not found a module use lct this open raw mode in empty struct*/
        if (j == MDI_GPS_UART_APP_PER_PORT_MAX)
        {
            for (j = 0; j < MDI_GPS_UART_APP_PER_PORT_MAX; j++)
            {
                if (g_mdi_gps_cntx.handle[index].gps_uart_raw_cb[j] == NULL &&
                    g_mdi_gps_cntx.handle[index].mod_id[j] == MOD_NIL)
                {
                    g_mdi_gps_cntx.handle[index].gps_uart_raw_cb[j] = gps_uart_event_callback;
                    g_mdi_gps_cntx.handle[index].mod_id[j] = module_id;
                    func_ret = MMI_TRUE;
                    break;
                }
            }
        }
        /*no slot to add callback so request is also no need*/
        if (j == MDI_GPS_UART_APP_PER_PORT_MAX)
        {
            is_need_send_to_gps = MMI_FALSE;
        }
    }
    else if(mode == MDI_GPS_UART_MODE_LOCATION_WITH_QOP)
    {
        for (j = 0; j < MDI_GPS_UART_APP_PER_PORT_MAX; j++)
        {
            if (g_mdi_gps_cntx.handle[index].gps_uart_lct_qop_cb[j] == gps_uart_event_callback &&
                g_mdi_gps_cntx.handle[index].mod_id[j] == module_id)
            {
                /*this callback function is in the list and module is same too*/
                return MMI_TRUE;
            }
        }
        is_need_send_to_gps = MMI_TRUE;
        for (j = 0; j < MDI_GPS_UART_APP_PER_PORT_MAX; j++)
        {
            if (g_mdi_gps_cntx.handle[index].gps_uart_lct_qop_cb[j] != NULL &&
                g_mdi_gps_cntx.handle[index].mod_id[j] == module_id)
            {
            /*find a mod use uart so no need send request*/
                is_need_send_to_gps = MMI_FALSE;
                break;
            }
        }
        /*find if lct qop data mode callback in this module,if yes open raw or lct mode*/
        for (j = 0; j < MDI_GPS_UART_APP_PER_PORT_MAX; j++)
        {
            if ((g_mdi_gps_cntx.handle[index].gps_uart_lct_cb[j] != NULL ||
                g_mdi_gps_cntx.handle[index].gps_uart_raw_cb[j] != NULL) &&
                g_mdi_gps_cntx.handle[index].gps_uart_lct_qop_cb[j] == NULL &&
                g_mdi_gps_cntx.handle[index].mod_id[j] == module_id)
            {
                g_mdi_gps_cntx.handle[index].gps_uart_lct_qop_cb[j] = gps_uart_event_callback;
                func_ret = MMI_TRUE;
                break;
            }
        }
        /*find a slot to store callback*/
        /*if not found a module use lct this open raw mode in empty struct*/
        if (j == MDI_GPS_UART_APP_PER_PORT_MAX)
        {
            for (j = 0; j < MDI_GPS_UART_APP_PER_PORT_MAX; j++)
            {
                if (g_mdi_gps_cntx.handle[index].gps_uart_lct_qop_cb[j] == NULL &&
                    g_mdi_gps_cntx.handle[index].mod_id[j] == MOD_NIL)
                {
                    g_mdi_gps_cntx.handle[index].gps_uart_lct_qop_cb[j] = gps_uart_event_callback;
                    g_mdi_gps_cntx.handle[index].mod_id[j] = module_id;
                    func_ret = MMI_TRUE;
                    break;
                }
            }
        }
        /*no slot to add callback so request is also no need*/
        if (j == MDI_GPS_UART_APP_PER_PORT_MAX)
        {
            is_need_send_to_gps = MMI_FALSE;
        }
    }
    else
    {
        ASSERT(MDI_GPS_OPEN_MODE_ERROR);
    }
    if (is_need_send_to_gps)
    {
        local_param_ptr = construct_local_para(sizeof(gps_uart_open_req_struct),TD_CTRL);
        local_param_ptr->port = g_mdi_gps_cntx.handle[index].port;
        local_param_ptr->mode = mode;
        local_param_ptr->return_val = &ret;
        local_param_ptr->module_id = module_id;
        event_id = g_mdi_gps_cntx.event_id;
        local_param_ptr->event_id = event_id;
        kal_take_mutex(g_mdi_gps_cntx.mutex);
        mdi_gps_send_req_to_gps_task(
            MSG_ID_GPS_UART_OPEN_REQ,
            local_param_ptr,
            sizeof(gps_uart_open_req_struct));
        kal_retrieve_eg_events(
            event_id,
            GPS_UART_OPEN_FINISH_EVENT,
            KAL_OR_CONSUME,
            &event_group,
            KAL_SUSPEND);
        kal_give_mutex(g_mdi_gps_cntx.mutex);
        if (ret != MDI_RES_GPS_UART_SUCCEED)
        {
            func_ret = MMI_FALSE;
        }
        else
        {
            func_ret = MMI_TRUE;
        }
    }
    return func_ret;
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_open_and_send_req
* DESCRIPTION
*  while open port check if need send msg to GPS
* PARAMETERS
*  index     [IN]        port index
*  port      [IN]        port number
*  mode      [IN]        open port in this mode
*  gps_uart_event_callback      [IN]        callback function
*  *ret      [OUT]       return error code here
* RETURNS
*  void
*****************************************************************************/
MMI_BOOL mdi_gps_open_and_send_req(
    U8 index,
    U16 port,
    mdi_gps_uart_work_mode_enum mode,
    void (*gps_uart_event_callback)(mdi_gps_parser_info_enum type, void *buffer, U32 length),
    MDI_RESULT *ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gps_uart_open_req_struct            *local_param_ptr;
    module_type module_id;
    U32                                 event_group;
    kal_eventgrpid                      event_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    module_id = stack_get_active_module_id();
    local_param_ptr = construct_local_para(sizeof(gps_uart_open_req_struct),TD_CTRL);
    local_param_ptr->port = port;
    local_param_ptr->mode = mode;
    local_param_ptr->return_val = ret;
    local_param_ptr->module_id = module_id;
    event_id = g_mdi_gps_cntx.event_id;
    local_param_ptr->event_id = event_id;
    kal_take_mutex(g_mdi_gps_cntx.mutex);
    mdi_gps_send_req_to_gps_task(
        MSG_ID_GPS_UART_OPEN_REQ,
        local_param_ptr,
        sizeof(gps_uart_open_req_struct));
    kal_retrieve_eg_events(
        event_id,
        GPS_UART_OPEN_FINISH_EVENT,
        KAL_OR_CONSUME,
        &event_group,
        KAL_SUSPEND);
    kal_give_mutex(g_mdi_gps_cntx.mutex);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_UART_TRC_OPEN_OK);
    if (*ret == MDI_RES_GPS_UART_SUCCEED)
    {
        g_mdi_gps_cntx.handle[index].mod_id[0] = module_id;
        g_mdi_gps_cntx.handle[index].port = port;
        g_mdi_gps_cntx.handle[index].is_opened = MMI_TRUE;
        if (mode == MDI_GPS_UART_MODE_LOCATION)
        {
            g_mdi_gps_cntx.handle[index].gps_uart_lct_cb[0] = gps_uart_event_callback;
        }
        else if(mode == MDI_GPS_UART_MODE_RAW_DATA)
        {
            g_mdi_gps_cntx.handle[index].gps_uart_raw_cb[0] = gps_uart_event_callback;
        }
        else if(mode == MDI_GPS_UART_MODE_LOCATION_WITH_QOP)
        {
            g_mdi_gps_cntx.handle[index].gps_uart_lct_qop_cb[0] = gps_uart_event_callback;
        }
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_nmea_get_filename
* DESCRIPTION
*  make the file name for file logging
* PARAMETERS
*  *buffer    [OUT]        the name of file
*  length     [IN]         the buffer lenght
* RETURNS
*  MMI_TRUE     make file name ok
*  MMI_FALSE    make file name failed
*****************************************************************************/
static MMI_BOOL mdi_gps_nmea_get_filename(U16 *buffer,U32 length, CHAR *ext_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    RTC_CTRL_GET_TIME_T rtc_time;
    DCL_HANDLE rtc_handler = 0;

    S32     driver, ret;
    U16     path[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (length < MDI_GPS_NMEA_FILENAME_LENGTH)
    {
        return MMI_FALSE;
    }
    rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);
    DclRTC_Control(rtc_handler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T *)& rtc_time);
    DclRTC_Close(rtc_handler);
    /*get memory card driver letter*/
    driver = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
    if (driver < FS_NO_ERROR)
    {
        /*no card we get normal driver*/
        driver = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_LOG_TRC_MAKE_PATH_CARD_DRIVER,driver);
        if (driver < FS_NO_ERROR)
        {
            return MMI_FALSE;
        }
    }
    kal_wsprintf(path,"%c:\\GPSlog",(U8)driver);
    FS_CreateDir(path);
    ret = FS_SetCurrentDir(path);
    if (ret != FS_NO_ERROR)
    {
        /*no card we get normal driver*/
        driver = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_LOG_TRC_MAKE_PATH_USER_DRIVER,driver);
        if (driver < FS_NO_ERROR)
        {
            return MMI_FALSE;
        }
        kal_wsprintf(path,"%c:\\GPSlog",(U8)driver);
        FS_CreateDir(path);
        ret = FS_SetCurrentDir(path);
        if (ret != FS_NO_ERROR)
        {
            return MMI_FALSE;
        }
    }
    kal_wsprintf(path,"%c:\\",(U8)driver);
    FS_SetCurrentDir(path);
    kal_wsprintf(buffer,
        "%c:\\GPSlog\\%2d%2d%2d%2d%2d%2d.%s",
        (U8)driver,
        rtc_time.u1Year,
        rtc_time.u1Mon,
        rtc_time.u1Day,
        rtc_time.u1Hour,
        rtc_time.u1Min,
        rtc_time.u1Sec,
        ext_name
        );
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_proc_and_open_log_file
* DESCRIPTION
*  make and open log file name
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mdi_gps_proc_and_open_log_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL    ret;
    U16 filename[MDI_GPS_NMEA_FILENAME_LENGTH];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mdi_gps_cntx.logging.file_handle >= 0)
    {
        FS_Close(g_mdi_gps_cntx.logging.file_handle);
        g_mdi_gps_cntx.logging.file_handle = -1;
    }
    if (g_mdi_gps_cntx.logging.debug_info_file_handle >= 0)
    {
        FS_Close(g_mdi_gps_cntx.logging.debug_info_file_handle);
        g_mdi_gps_cntx.logging.debug_info_file_handle = -1;
    }
    g_mdi_gps_cntx.logging.file_pre_allocate_failed = MMI_FALSE;
    g_mdi_gps_cntx.logging.debug_info_file_pre_allocate_failed = MMI_FALSE;
    g_mdi_gps_cntx.logging.file_pre_allocate = 0;
    g_mdi_gps_cntx.logging.debug_info_file_pre_allocate = 0;
    for(i=0 ; i<MDI_GPS_UART_PORT_MAX ; i++)
    {
        if (g_mdi_gps_cntx.handle[i].port != MDI_GPS_DUMMY_PORT)
        {
            break;
        }
    }
    if (i == MDI_GPS_UART_PORT_MAX)
    {
        return;
    }
    if (g_mdi_gps_cntx.logging.debug_info != MMI_TRUE &&
        g_mdi_gps_cntx.logging.file_logging == MMI_TRUE)
    {
        /*construct file name and open the file in write MOD*/
        ret = mdi_gps_nmea_get_filename(filename,MDI_GPS_NMEA_FILENAME_LENGTH,"nma");
        if (ret == MMI_TRUE)
        {
            g_mdi_gps_cntx.logging.file_handle =
                FS_Open(filename, FS_CREATE_ALWAYS);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,
                MDI_GPS_LOG_TRC_OPEN_FILE_HANDLE,
                g_mdi_gps_cntx.logging.file_handle);
        }
        else
        {
        /*make file name error, no need process now*/
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_LOG_TRC_MAKE_NMA_FILE_ERR);
        }
    }
    else if (g_mdi_gps_cntx.logging.file_logging == MMI_TRUE &&
        g_mdi_gps_cntx.logging.debug_info == MMI_TRUE)
    {
        /*construct file name and open the file in write MOD*/
        ret = mdi_gps_nmea_get_filename(filename,MDI_GPS_NMEA_FILENAME_LENGTH,"dbg");
        if (ret == MMI_TRUE)
        {
            g_mdi_gps_cntx.logging.debug_info_file_handle =
                FS_Open(filename, FS_CREATE_ALWAYS);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,
                MDI_GPS_LOG_TRC_OPEN_DBG_FILE_HANDLE,
                g_mdi_gps_cntx.logging.debug_info_file_handle);
        }
        else
        {
        /*make file name error, no need process now*/
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_LOG_TRC_MAKE_DBG_FILE_ERR);
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_close_log_file
* DESCRIPTION
*  close log file
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mdi_gps_close_log_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mdi_gps_cntx.logging.file_handle >= 0)
    {
        FS_Close(g_mdi_gps_cntx.logging.file_handle);
        g_mdi_gps_cntx.logging.file_handle = -1;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,
            MDI_GPS_LOG_TRC_CLOSE_FILE_HANDLE,
            g_mdi_gps_cntx.logging.file_handle);
    }
    if (g_mdi_gps_cntx.logging.debug_info_file_handle >= 0)
    {
        /*construct file name and open the file in write MOD*/
        FS_Close(g_mdi_gps_cntx.logging.debug_info_file_handle);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_LOG_TRC_CLOSE_DBG_FILE, g_mdi_gps_cntx.logging.debug_info_file_handle);
        g_mdi_gps_cntx.logging.debug_info_file_handle = -1;
    }
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_uart_open
* DESCRIPTION
*  open the uart and give the callor the uart handle
* PARAMETERS
*  port                     [IN]        port number for open
*  gps_uart_event_callback  [IN]        callback function of uart events
* RETURNS
*  mdi_gps_uart_handle
*****************************************************************************/
MDI_RESULT mdi_gps_uart_open(
    U16 port,
    mdi_gps_uart_work_mode_enum mode,
    void (*gps_uart_event_callback)(mdi_gps_parser_info_enum type, void *buffer, U32 length))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT                          ret;
    MMI_BOOL                            ret_value;
    U8                                  i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_UART_TRC_OPEN, port, gps_uart_event_callback);
    ret = MDI_RES_GPS_UART_ERR_PORT_ERR_UNKNOW;
    if (port > uart_max_port)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_UART_TRC_OPEN_RETURN_ERR);
        return ret;
    }
    ASSERT(NULL != gps_uart_event_callback);
    /*crying for msg dispatcher not ready*/
    SetProtocolEventHandler(mdi_gps_gps_raw_data_ind_hdler, MSG_ID_GPS_UART_RAW_DATA);
    SetProtocolEventHandler(mdi_gps_gps_debug_info_ind_hdler, MSG_ID_GPS_UART_DEBUG_RAW_DATA);
    SetProtocolEventHandler(mdi_gps_gps_location_ind_hdler, MSG_ID_GPS_UART_NMEA_LOCATION);
    SetProtocolEventHandler(mdi_gps_gps_sentence_ind_hdler, MSG_ID_GPS_UART_NMEA_SENTENCE);
    SetProtocolEventHandler(mdi_gps_gps_p_info_ind_hdler,   MSG_ID_GPS_UART_P_INFO_IND);

    for(i=0 ; i<MDI_GPS_UART_PORT_MAX ; i++)
    {
        if (g_mdi_gps_cntx.handle[i].port == port)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_UART_TRC_OPEN_ALREADY_OPEN);
            ret_value = mdi_gps_open_find_slot_add(i,mode,gps_uart_event_callback);
            if (ret_value == MMI_FALSE)
            {
                ret = MDI_RES_GPS_UART_ERR_NO_SLOT;
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_UART_TRC_OPEN_RETURN_ERR);
            }
            else
            {
                if (g_mdi_gps_cntx.handle[i].is_ready_to_write == MMI_TRUE)
                {
                    ret = MDI_RES_GPS_UART_READY_TO_WRITE;
                }
                else
                {
                ret = MDI_RES_GPS_UART_SUCCEED;
                }
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_UART_TRC_OPEN_RETURN_OK);
            }
            return ret;
        }
    }
    for(i=0 ; i<MDI_GPS_UART_PORT_MAX ; i++)
    {
        if (g_mdi_gps_cntx.handle[i].is_opened == MMI_FALSE)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_UART_TRC_FIND_SLOT, i);
            g_mdi_gps_cntx.handle[i].is_ready_to_write = MMI_FALSE;
            ret_value = mdi_gps_open_and_send_req(
                i,
                port,
                mode,
                gps_uart_event_callback,
                &ret);
            if (ret_value == MMI_FALSE)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_UART_TRC_OPEN_RETURN_ERR);
            }
            else
            {
                ret = MDI_RES_GPS_UART_SUCCEED;
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_UART_TRC_OPEN_RETURN_OK);
                /*now we set parser and logging work on newest port that opened*/
                mdi_gps_set_work_port(port);
                mdi_gps_proc_and_open_log_file();
            }
            break;
        }
    }
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_uart_cmd
* DESCRIPTION
*  write command to uart port
* PARAMETERS
*  port         [IN]        handle of the port
*  cmd          [IN]        the cmd to GPS
*  *param       [IN]        reserved
* RETURNS
*  MDI_RESULT
*****************************************************************************/
MDI_RESULT mdi_gps_uart_cmd(U16 port, mdi_gps_uart_cmd_type_enum cmd, void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gps_uart_write_req_struct            *local_param_ptr;
    module_type module_id;
    U32                                 event_group;
    kal_eventgrpid                      event_id;
    MDI_RESULT          ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    module_id = stack_get_active_module_id();
    local_param_ptr = construct_local_para(sizeof(gps_uart_write_req_struct),TD_CTRL);
    local_param_ptr->port = port;
    local_param_ptr->return_val = &ret;
    local_param_ptr->cmd = cmd;
    local_param_ptr->buffer = NULL;
    local_param_ptr->is_rawdata = MMI_FALSE;
    local_param_ptr->module_id = module_id;
    event_id = g_mdi_gps_cntx.event_id;
    local_param_ptr->event_id = event_id;
    kal_take_mutex(g_mdi_gps_cntx.mutex);
    mdi_gps_send_req_to_gps_task(
        MSG_ID_GPS_UART_WRITE_REQ,
        local_param_ptr,
        sizeof(gps_uart_write_req_struct));
    kal_retrieve_eg_events(
        event_id,
        GPS_UART_WRITE_FINISH_EVENT,
        KAL_OR_CONSUME,
        &event_group,
        KAL_SUSPEND);
    kal_give_mutex(g_mdi_gps_cntx.mutex);
    return MDI_RES_GPS_UART_SUCCEED;
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_uart_write
* DESCRIPTION
*  write data to uart port
* PARAMETERS
*  port          [IN]        port number
*  *buffer       [IN]        the data need send to UART
*  length        [IN]        data length
*  write         [OUT]       mdi uart return the number of byte writen here
* RETURNS
*  MDI_RESULT
*****************************************************************************/
MDI_RESULT mdi_gps_uart_write(U16 port, void* buffer, U32 length, U32 *write)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gps_uart_write_req_struct            *local_param_ptr;
    module_type module_id;
    U32                                 event_group;
    kal_eventgrpid                      event_id;
    MDI_RESULT          ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(port <= uart_max_port);
    module_id = stack_get_active_module_id();
    local_param_ptr = construct_local_para(sizeof(gps_uart_write_req_struct),TD_CTRL);
    local_param_ptr->port = port;
    local_param_ptr->return_val = &ret;
    local_param_ptr->is_rawdata = MMI_TRUE;
    local_param_ptr->length = length;
    local_param_ptr->buffer = buffer;
    local_param_ptr->return_written = write;
    local_param_ptr->module_id = module_id;
    event_id = g_mdi_gps_cntx.event_id;
    local_param_ptr->event_id = event_id;
    kal_take_mutex(g_mdi_gps_cntx.mutex);
    mdi_gps_send_req_to_gps_task(
        MSG_ID_GPS_UART_WRITE_REQ,
        local_param_ptr,
        sizeof(gps_uart_write_req_struct));
    kal_retrieve_eg_events(
        event_id,
        GPS_UART_WRITE_FINISH_EVENT,
        KAL_OR_CONSUME,
        &event_group,
        KAL_SUSPEND);
    kal_give_mutex(g_mdi_gps_cntx.mutex);
    return MDI_RES_GPS_UART_SUCCEED;
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_uart_close
* DESCRIPTION
*  close the port so other app can use
* PARAMETERS
*  handle        [IN]        the handle of the port want to close
* RETURNS
*  MDI_RESULT
*****************************************************************************/
MDI_RESULT mdi_gps_uart_close(
    U16 port,
    mdi_gps_uart_work_mode_enum mode,
    void (*gps_uart_event_callback)(mdi_gps_parser_info_enum type, void *buffer, U32 length))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type                 module_id;
    gps_uart_close_req_struct    *local_param_ptr;
    U32                         event_group;
    mdi_gps_uart_work_mode_enum     closed_mode = MDI_GPS_UART_MODE_RAW_DATA;
    kal_eventgrpid              event_id;
    MMI_BOOL                    is_need_close;
    U8                          index, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(NULL != gps_uart_event_callback);
    module_id = stack_get_active_module_id();
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_UART_TRC_CLOSE, port, mode, gps_uart_event_callback);
    if (g_mdi_gps_cntx.logging.file_handle >= 0)
    {
        FS_Commit(g_mdi_gps_cntx.logging.file_handle);
        g_mdi_gps_cntx.logging.file_write_count = 0;
    }
    if (g_mdi_gps_cntx.logging.debug_info_file_handle >= 0)
    {
        FS_Commit(g_mdi_gps_cntx.logging.debug_info_file_handle);
        g_mdi_gps_cntx.logging.file_write_count = 0;
    }
    /*check the mode's callback all unregistered then request gps close that mode*/
    for (index= 0 ; index < MDI_GPS_UART_PORT_MAX; index++)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_UART_TRC_CLOSE_CHECK, index, g_mdi_gps_cntx.handle[index].port);
        if (g_mdi_gps_cntx.handle[index].port == port)
        {
            for (i=0 ; i< MDI_GPS_UART_APP_PER_PORT_MAX ; i++)
            {
                if (g_mdi_gps_cntx.handle[index].gps_uart_lct_cb[i] == gps_uart_event_callback &&
                    g_mdi_gps_cntx.handle[index].mod_id[i] == module_id &&
                    mode == MDI_GPS_UART_MODE_LOCATION)
                {
                    g_mdi_gps_cntx.handle[index].gps_uart_lct_cb[i] = NULL;
                    closed_mode = MDI_GPS_UART_MODE_LOCATION;
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_UART_TRC_SET_CLOSE_MODE, closed_mode);
                }
                else if (g_mdi_gps_cntx.handle[index].gps_uart_raw_cb[i] == gps_uart_event_callback &&
                    g_mdi_gps_cntx.handle[index].mod_id[i] == module_id &&
                    mode == MDI_GPS_UART_MODE_RAW_DATA)
                {
                    g_mdi_gps_cntx.handle[index].gps_uart_raw_cb[i] = NULL;
                    closed_mode = MDI_GPS_UART_MODE_RAW_DATA;
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_UART_TRC_SET_CLOSE_MODE, closed_mode);
                }
                else if (g_mdi_gps_cntx.handle[index].gps_uart_lct_qop_cb[i] == gps_uart_event_callback &&
                    g_mdi_gps_cntx.handle[index].mod_id[i] == module_id &&
                    mode == MDI_GPS_UART_MODE_LOCATION_WITH_QOP)
                {
                    g_mdi_gps_cntx.handle[index].gps_uart_lct_qop_cb[i] = NULL;
                    closed_mode = MDI_GPS_UART_MODE_LOCATION_WITH_QOP;
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_UART_TRC_SET_CLOSE_MODE, closed_mode);
                }
            }
            is_need_close = MMI_TRUE;
            for (i=0 ; i< MDI_GPS_UART_APP_PER_PORT_MAX ; i++)
            {
                if (g_mdi_gps_cntx.handle[index].gps_uart_lct_cb[i] != NULL &&
                    g_mdi_gps_cntx.handle[index].mod_id[i] == module_id &&
                    closed_mode == MDI_GPS_UART_MODE_LOCATION)
                {
                    is_need_close = MMI_FALSE;
                    break;
                }
                else if (g_mdi_gps_cntx.handle[index].gps_uart_raw_cb[i] != NULL &&
                    g_mdi_gps_cntx.handle[index].mod_id[i] == module_id &&
                    closed_mode == MDI_GPS_UART_MODE_RAW_DATA)
                {
                    is_need_close = MMI_FALSE;
                    break;
                }
                else if (g_mdi_gps_cntx.handle[index].gps_uart_lct_qop_cb[i] != NULL &&
                    g_mdi_gps_cntx.handle[index].mod_id[i] == module_id &&
                    closed_mode == MDI_GPS_UART_MODE_LOCATION_WITH_QOP)
                {
                    is_need_close = MMI_FALSE;
                    break;
                }
            }
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_UART_TRC_FINAL_CLOSE_MODE, closed_mode);
            if (is_need_close == MMI_TRUE)
            {
                local_param_ptr = construct_local_para(sizeof(gps_uart_close_req_struct),TD_CTRL);
                local_param_ptr->port = g_mdi_gps_cntx.handle[index].port;
                local_param_ptr->mode = closed_mode;
                local_param_ptr->module_id = module_id;
                event_id = g_mdi_gps_cntx.event_id;
                local_param_ptr->event_id = event_id;
                kal_take_mutex(g_mdi_gps_cntx.mutex);
                mdi_gps_send_req_to_gps_task(
                    MSG_ID_GPS_UART_CLOSE_REQ,
                    local_param_ptr,
                    sizeof(gps_uart_close_req_struct));
                kal_retrieve_eg_events(
                    event_id,
                    GPS_UART_CLOSE_FINISH_EVENT,
                    KAL_OR_CONSUME,
                    &event_group,
                    KAL_SUSPEND);
                kal_give_mutex(g_mdi_gps_cntx.mutex);
                mdi_gps_close_log_file();
            }
            for (i=0 ; i< MDI_GPS_UART_APP_PER_PORT_MAX ; i++)
            {
                if (g_mdi_gps_cntx.handle[index].gps_uart_lct_cb[i] == NULL &&
                    g_mdi_gps_cntx.handle[index].gps_uart_lct_qop_cb[i] == NULL &&
                    g_mdi_gps_cntx.handle[index].gps_uart_raw_cb[i] == NULL)
                {
                    g_mdi_gps_cntx.handle[index].mod_id[i] = MOD_NIL;
                }
            }
            for (i=0 ; i< MDI_GPS_UART_APP_PER_PORT_MAX ; i++)
            {
                if (g_mdi_gps_cntx.handle[index].mod_id[i] != MOD_NIL)
                {
                    break;
                }
            }
            if (i == MDI_GPS_UART_APP_PER_PORT_MAX)
            {
                g_mdi_gps_cntx.handle[index].port = MDI_GPS_DUMMY_PORT;
                g_mdi_gps_cntx.handle[index].is_opened = MMI_FALSE;
            }
        }
    }
    return MDI_RES_GPS_UART_SUCCEED;
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_uart_clear_nvram
* DESCRIPTION
*  close the port so other app can use
* PARAMETERS
*  handle        [IN]        the handle of the port want to close
* RETURNS
*  MDI_RESULT
*****************************************************************************/
MDI_RESULT mdi_gps_uart_clear_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    gps_uart_clear_on_broad_gps_nvram();
#endif
    return MDI_RES_GPS_UART_SUCCEED;
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_logging_file_pre_allocate
* DESCRIPTION
*  pre-allocate file space
* PARAMETERS
*  handle           [IN]        file handle
*  num_allocated    [IN/OUT]    in still left and out the number after allocated
* RETURNS
*  MMI_FALSE    allocate failed, maybe disk full
*  MMI_TRUE     allocate OK
*****************************************************************************/
static MMI_BOOL mdi_gps_logging_file_pre_allocate(FS_HANDLE handle, U32* num_allocated)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle < 0)
    {
        return MMI_FALSE;
    }
    if (*num_allocated <= MDI_GPS_RAW_DATA_PER_CB)
    {
        ret_code = FS_Extend(handle, MDI_GPS_RAW_DATA_PER_EXTEND);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_UART_TRC_FILE_SPACE_PRE_ALLOCATE_OLD, handle,  *num_allocated);
        if (ret_code < 0)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_UART_TRC_FILE_SPACE_PRE_ALLOCATE_FAILED, ret_code);
            return MMI_FALSE;
        }
        else
        {
            *num_allocated += MDI_GPS_RAW_DATA_PER_EXTEND;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_UART_TRC_FILE_SPACE_PRE_ALLOCATE_NEW, handle, *num_allocated);
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_uart_callback_app_ind_hdler
* DESCRIPTION
*  callback app according to the message mdi get
* PARAMETERS
*  type        [IN]        callback type
*  port        [IN]        port number
*  *buffer     [IN]        data buffer
*  length      [IN]        data length
* RETURNS
*  void
*****************************************************************************/
void mdi_gps_uart_callback_app_ind_hdler(module_type module_id, mdi_gps_parser_info_enum type, U16 port, void *buffer, U32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  i,j;
    U32 written;
    MMI_BOOL    ok_to_write = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (module_id == MOD_NIL)
    {
        module_id = stack_get_active_module_id();
    }
    if (type == MDI_GPS_PARSER_RAW_DATA &&
        g_mdi_gps_cntx.logging.file_logging == MMI_TRUE &&
        g_mdi_gps_cntx.logging.debug_info == MMI_FALSE &&
        module_id == MOD_MMI)
    {

        if (g_mdi_gps_cntx.logging.file_pre_allocate_failed == MMI_FALSE)
        {
            ok_to_write = mdi_gps_logging_file_pre_allocate(
                g_mdi_gps_cntx.logging.file_handle,
                &g_mdi_gps_cntx.logging.file_pre_allocate);
            if (ok_to_write == MMI_FALSE)
            {
                g_mdi_gps_cntx.logging.file_pre_allocate_failed = MMI_TRUE;
            }
        }
        if (ok_to_write == MMI_TRUE)
        {
            FS_Write(
                g_mdi_gps_cntx.logging.file_handle,
                buffer,
                length,
                &written);
            g_mdi_gps_cntx.logging.file_pre_allocate -= written;
            g_mdi_gps_cntx.logging.file_write_count++;
            if (g_mdi_gps_cntx.logging.file_write_count > MDI_GPS_NMEA_FILE_LOGGING_WRITE_TIME)
            {
                FS_Commit(g_mdi_gps_cntx.logging.file_handle);
                g_mdi_gps_cntx.logging.file_write_count = 0;
            }
        }
    }
    for(i=0 ; i<MDI_GPS_UART_PORT_MAX ; i++)
    {
       if (g_mdi_gps_cntx.handle[i].port == port)
        {
            MMI_TRACE(
                MMI_MEDIA_TRC_G2_APP,
                MDI_GPS_UART_TRC_APP_IND_PORT_FOUND,
                port);
            for(j=0 ; j<MDI_GPS_UART_APP_PER_PORT_MAX ; j++)
            {
                if (g_mdi_gps_cntx.handle[i].gps_uart_raw_cb[j] != NULL &&
                    g_mdi_gps_cntx.handle[i].mod_id[j] == module_id &&
                    type == MDI_GPS_PARSER_RAW_DATA)
                {
                    MMI_TRACE(
                        MMI_MEDIA_TRC_G2_APP,
                        MDI_GPS_UART_TRC_RAW_CB,
                        g_mdi_gps_cntx.handle[i].gps_uart_raw_cb[j]);
                    g_mdi_gps_cntx.handle[i].gps_uart_raw_cb[j](MDI_GPS_PARSER_RAW_DATA,buffer, length);
                }
                else if (g_mdi_gps_cntx.handle[i].gps_uart_lct_cb[j] != NULL &&
                    g_mdi_gps_cntx.handle[i].mod_id[j] == module_id &&
                    ((type >= MDI_GPS_PARSER_NMEA_GGA &&type < MDI_GPS_PARSER_NMEA_SENTENCE) ||
                    type==MDI_GPS_PARSER_NMEA_ACC))
                {
                	kal_prompt_trace(MOD_MMI_MEDIA_APP,"gps enter miniGPS.\n");
                    g_mdi_gps_cntx.handle[i].gps_uart_lct_cb[j](type, buffer, length);
                }
                else if (g_mdi_gps_cntx.handle[i].gps_uart_lct_cb[j] != NULL &&
                    g_mdi_gps_cntx.handle[i].mod_id[j] == module_id &&
                    type == MDI_GPS_PARSER_NMEA_SENTENCE)
                {
                    g_mdi_gps_cntx.handle[i].gps_uart_lct_cb[j](type, buffer, length);
                }
                else if(type == MDI_GPS_UART_EVENT_VPORT_LOST)
                {
                    if (g_mdi_gps_cntx.handle[i].gps_uart_lct_cb[j] != NULL &&
                        g_mdi_gps_cntx.handle[i].mod_id[j] == module_id)
                    {
                        g_mdi_gps_cntx.handle[i].gps_uart_lct_cb[j](type, buffer, length);
                    }
                    if (g_mdi_gps_cntx.handle[i].gps_uart_raw_cb[j] != NULL &&
                        g_mdi_gps_cntx.handle[i].mod_id[j] == module_id)
                    {
                        g_mdi_gps_cntx.handle[i].gps_uart_raw_cb[j](type, buffer, length);
                    }
                }
            }
            break;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_gps_raw_data_ind_hdler
* DESCRIPTION
*  the message proccess function of raw data ind
* PARAMETERS
*  msg        [IN]        the coming message
* RETURNS
*  void
*****************************************************************************/
static void mdi_gps_gps_raw_data_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gps_uart_raw_data_struct* uart_raw_data_ind = (gps_uart_raw_data_struct*)msg;
    U8      mdi_raw_buffer[MDI_GPS_RAW_DATA_PER_CB + 1];
    U32     readed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gps_uart_read_data_nmea(uart_raw_data_ind->module_id, uart_raw_data_ind->port,mdi_raw_buffer,MDI_GPS_RAW_DATA_PER_CB,&readed);
    ASSERT(readed<=MDI_GPS_RAW_DATA_PER_CB);
    mdi_raw_buffer[readed] = 0;
    if (readed > 0)
    {
        mdi_gps_uart_callback_app_ind_hdler(
            uart_raw_data_ind->module_id,
            MDI_GPS_PARSER_RAW_DATA,
            uart_raw_data_ind->port,
            mdi_raw_buffer,
            readed);
    }
    while (readed > 0)
    {
        gps_uart_read_data_nmea(uart_raw_data_ind->module_id, uart_raw_data_ind->port,mdi_raw_buffer,MDI_GPS_RAW_DATA_PER_CB,&readed);
        ASSERT(readed<=MDI_GPS_RAW_DATA_PER_CB);
        mdi_raw_buffer[readed] = 0;
        if (readed > 0)
        {
            mdi_gps_uart_callback_app_ind_hdler(
                uart_raw_data_ind->module_id,
                MDI_GPS_PARSER_RAW_DATA,
                uart_raw_data_ind->port,
                mdi_raw_buffer,
                readed);
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_gps_raw_data_ind_hdler
* DESCRIPTION
*  the message proccess function of raw data ind
* PARAMETERS
*  msg        [IN]        the coming message
* RETURNS
*  void
*****************************************************************************/
static void mdi_gps_gps_debug_info_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gps_uart_debug_raw_data_struct* uart_raw_data_ind = (gps_uart_debug_raw_data_struct*)msg;
    U8          mdi_raw_buffer[MDI_GPS_RAW_DATA_PER_CB + 1];
    module_type module_id;
    U32     written;
    U32     readed;
    MMI_BOOL    ok_to_write = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    module_id = stack_get_active_module_id();
    gps_uart_read_data_dbg(uart_raw_data_ind->port,mdi_raw_buffer,MDI_GPS_RAW_DATA_PER_CB,&readed);
    ASSERT(readed<=MDI_GPS_RAW_DATA_PER_CB);
    if (g_mdi_gps_cntx.logging.debug_info_file_pre_allocate_failed == MMI_FALSE)
    {
        ok_to_write = mdi_gps_logging_file_pre_allocate(
            g_mdi_gps_cntx.logging.debug_info_file_handle,
            &g_mdi_gps_cntx.logging.debug_info_file_pre_allocate);
        if (ok_to_write == MMI_FALSE)
        {
            g_mdi_gps_cntx.logging.debug_info_file_pre_allocate_failed = MMI_TRUE;
        }
    }
    if (readed > 0)
    {
        if (g_mdi_gps_cntx.logging.file_logging == MMI_TRUE &&
            module_id == MOD_MMI &&
            ok_to_write == MMI_TRUE)
        {
            FS_Write(
                g_mdi_gps_cntx.logging.debug_info_file_handle,
                mdi_raw_buffer,
                readed,
                &written);
            g_mdi_gps_cntx.logging.debug_info_file_pre_allocate -= written;
            g_mdi_gps_cntx.logging.debug_info_file_write_count++;
            if (g_mdi_gps_cntx.logging.debug_info_file_write_count> MDI_GPS_NMEA_FILE_DEBUGINOF_WRITE_TIME)
            {
                FS_Commit(g_mdi_gps_cntx.logging.debug_info_file_handle);
                g_mdi_gps_cntx.logging.debug_info_file_write_count = 0;
            }
        }
    }
    while (readed == MDI_GPS_RAW_DATA_PER_CB)
    {
        gps_uart_read_data_dbg(uart_raw_data_ind->port,mdi_raw_buffer,MDI_GPS_RAW_DATA_PER_CB,&readed);
        ASSERT(readed<=MDI_GPS_RAW_DATA_PER_CB);
        if (g_mdi_gps_cntx.logging.file_logging == MMI_TRUE &&
            module_id == MOD_MMI &&
            ok_to_write == MMI_TRUE)
        {
            FS_Write(
                g_mdi_gps_cntx.logging.debug_info_file_handle,
                mdi_raw_buffer,
                readed,
                &written);
            g_mdi_gps_cntx.logging.debug_info_file_pre_allocate -= written;
            g_mdi_gps_cntx.logging.debug_info_file_write_count++;
            if (g_mdi_gps_cntx.logging.debug_info_file_write_count> MDI_GPS_NMEA_FILE_DEBUGINOF_WRITE_TIME)
            {
                FS_Commit(g_mdi_gps_cntx.logging.debug_info_file_handle);
                g_mdi_gps_cntx.logging.debug_info_file_write_count = 0;
            }
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_gps_location_ind_hdler
* DESCRIPTION
*  the message proccess function of location ind
* PARAMETERS
*  msg        [IN]        the coming message
* RETURNS
*  void
*****************************************************************************/
static void mdi_gps_gps_location_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gps_uart_nmea_location_struct* uart_raw_data_ind = (gps_uart_nmea_location_struct*)msg;
    gps_common_nmea_info_struct        nmea;
    U16  bitmap;
    U8 tempbuf[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bitmap = gps_get_nmea_location(uart_raw_data_ind->port, &nmea);
    kal_prompt_trace(MOD_MMI_MEDIA_APP,"MDI GPS bitmap=%d.\n",bitmap);
    if (bitmap & GPS_NMEA_BITMAP_GGA)
    {
    mdi_gps_uart_callback_app_ind_hdler(
            MOD_NIL,
            MDI_GPS_PARSER_NMEA_GGA,
            uart_raw_data_ind->port,
            &nmea.gga,
            0);
    }
    if (bitmap & GPS_NMEA_BITMAP_GSA)
    {
        mdi_gps_uart_callback_app_ind_hdler(
            MOD_NIL,
            MDI_GPS_PARSER_NMEA_GSA,
            uart_raw_data_ind->port,
            &nmea.gsa,
            0);
    }
    if (bitmap & GPS_NMEA_BITMAP_GSV)
    {
        mdi_gps_uart_callback_app_ind_hdler(
            MOD_NIL,
            MDI_GPS_PARSER_NMEA_GSV,
            uart_raw_data_ind->port,
            &nmea.gsv,
        0);
    }
    if (bitmap & GPS_NMEA_BITMAP_RMC)
    {
        mdi_gps_uart_callback_app_ind_hdler(
            MOD_NIL,
            MDI_GPS_PARSER_NMEA_RMC,
            uart_raw_data_ind->port,
            &nmea.rmc,
            0);
    }
    if (bitmap & GPS_NMEA_BITMAP_VTG)
    {
        mdi_gps_uart_callback_app_ind_hdler(
            MOD_NIL,
            MDI_GPS_PARSER_NMEA_VTG,
            uart_raw_data_ind->port,
            &nmea.vtg,
            0);
    }
    if (bitmap & GPS_NMEA_BITMAP_GLL)
    {
        mdi_gps_uart_callback_app_ind_hdler(
            MOD_NIL,
            MDI_GPS_PARSER_NMEA_GLL,
            uart_raw_data_ind->port,
            &nmea.gll,
            0);
    }
    if (bitmap & GPS_NMEA_BITMAP_GLGSV)
    {
        mdi_gps_uart_callback_app_ind_hdler(
            MOD_NIL,
            MDI_GPS_PARSER_NMEA_GLGSV,
            uart_raw_data_ind->port,
            &nmea.glgsv,
            0);
    }
    if (bitmap & GPS_NMEA_BITMAP_GLGSA)
    {
        mdi_gps_uart_callback_app_ind_hdler(
            MOD_NIL,
            MDI_GPS_PARSER_NMEA_GLGSA,
            uart_raw_data_ind->port,
            &nmea.glgsa,
            0);
    }
    if (bitmap & GPS_NMEA_BITMAP_GAGSA)
    {
        mdi_gps_uart_callback_app_ind_hdler(
            MOD_NIL,
            MDI_GPS_PARSER_NMEA_GAGSA,
            uart_raw_data_ind->port,
            &nmea.gagsa,
            0);
    }
    if (bitmap & GPS_NMEA_BITMAP_GAGSV)
    {
        mdi_gps_uart_callback_app_ind_hdler(
            MOD_NIL,
            MDI_GPS_PARSER_NMEA_GAGSV,
            uart_raw_data_ind->port,
            &nmea.gagsv,
            0);
    }
	if (bitmap & GPS_NMEA_BITMAP_BDGSA)
    {
        mdi_gps_uart_callback_app_ind_hdler(
            MOD_NIL,
            MDI_GPS_PARSER_NMEA_BDGSA,
            uart_raw_data_ind->port,
            &nmea.bdgsa,
            0);
    }
    if (bitmap & GPS_NMEA_BITMAP_BDGSV)
    {
        mdi_gps_uart_callback_app_ind_hdler(
            MOD_NIL,
            MDI_GPS_PARSER_NMEA_BDGSV,
            uart_raw_data_ind->port,
            &nmea.bdgsv,
            0);
    }
    if (bitmap & GPS_NMEA_BITMAP_ACCURACY)
    {
    	sprintf(tempbuf,"gps accuracy=%.3f\r\n",nmea.acc.accuracy);
    	kal_prompt_trace(MOD_MMI_MEDIA_APP,"%s",tempbuf);
        mdi_gps_uart_callback_app_ind_hdler(
            MOD_NIL,
            MDI_GPS_PARSER_NMEA_ACC,
            uart_raw_data_ind->port, 
            &nmea.acc,
            0);
    }

}


/*****************************************************************************
* FUNCTION
*  mdi_gps_gps_sentence_ind_hdler
* DESCRIPTION
*  the message proccess function of sentence ind
* PARAMETERS
*  msg        [IN]        the coming message
* RETURNS
*  void
*****************************************************************************/
static void mdi_gps_gps_sentence_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gps_uart_nmea_sentence_struct* uart_raw_data_ind = (gps_uart_nmea_sentence_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_gps_uart_callback_app_ind_hdler(
        MOD_NIL,
        MDI_GPS_PARSER_NMEA_SENTENCE,
        uart_raw_data_ind->port,
        uart_raw_data_ind->buffer,
        uart_raw_data_ind->length);
}




/*****************************************************************************
* FUNCTION
*  mdi_gps_gps_p_info_ind_hdler
* DESCRIPTION
*  the message proccess function of p_info ind
* PARAMETERS
*  msg        [IN]        the coming message
* RETURNS
*  void
*****************************************************************************/
static void mdi_gps_gps_p_info_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gps_uart_p_info_ind_struct* uart_p_info_data_ind = (gps_uart_p_info_ind_struct*)msg;
    mdi_gps_parser_p_info_enum  type = MDI_GPS_PARSER_P_END;
    void*  param = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(uart_p_info_data_ind->type)
    {
    case GPS_PARSER_P_VERSION:
        type = MDI_GPS_PARSER_P_VERSION;
        break;
    case GPS_PARSER_P_GPS_MODE_SWITCH_OK:
        type = MDI_GPS_PARSER_P_GPS_MODE_SWITCH_OK;
        break;
    case GPS_PARSER_P_SYSTEM_START_OK:
        type = MDI_GPS_PARSER_P_SYSTEM_START_OK;
        g_mdi_gps_cntx.handle[0].is_ready_to_write = MMI_TRUE;
        break;
    case GPS_PARSER_P_GPS_FIXED:
        type = MDI_GPS_PARSER_P_GPS_FIXED;
        param = &(uart_p_info_data_ind->p_info.gps_fix);
        break;
    case GPS_PARSER_P_GPS_FIXED_AND_TIME_OK:
        type = MDI_GPS_PARSER_P_GPS_FIXED_AND_TIME_OK;
        param = &(uart_p_info_data_ind->p_info.gps_fix);
        break;
    case GPS_PARSER_P_GPS_BT_VPORT_LOST:
        param = &(uart_p_info_data_ind->p_info.vport);
        mdi_gps_uart_callback_app_ind_hdler(
            MOD_NIL,
            MDI_GPS_UART_EVENT_VPORT_LOST,
            ((gps_p_info_gps_vport_struct*)param)->port,
            NULL,
            0);
        break;
    default:
        break;
    }
    if (g_mdi_gps_cntx.gps_uart_p_callback != NULL)
    {
        g_mdi_gps_cntx.gps_uart_p_callback(type);
    }
    if (g_mdi_gps_cntx.gps_uart_p_info_callback != NULL)
    {
        g_mdi_gps_cntx.gps_uart_p_info_callback(type,param);
    }
}


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
#endif


/*****************************************************************************
* FUNCTION
*  mdi_gps_uart_message_dispatcher
* DESCRIPTION
*  dispatcher of the mdi gps, this will get message for task needed
* PARAMETERS
*  ilm_ptr        [IN]        ilm_struct data
* RETURNS
*  MMI_TRUE    message is processed by this function
*  MMI_FALSE   message is not processed by this function
*****************************************************************************/
MMI_BOOL mdi_gps_uart_message_dispatcher(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_p = ilm_ptr;
    MMI_BOOL handle_msg = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(ilm_p->msg_id)
    {
    case MSG_ID_UART_PLUGOUT_IND:
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_UART_TRC_DISPATCHER_PLUGOUT);
        break;
    case MSG_ID_GPS_UART_RAW_DATA:
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_UART_TRC_DISPATCHER_PLUGOUT);
        mdi_gps_gps_raw_data_ind_hdler(ilm_p->local_para_ptr);
        break;
    case MSG_ID_GPS_UART_NMEA_LOCATION:
        mdi_gps_uart_callback_app_ind_hdler(
            MOD_NIL,
            (mdi_gps_parser_info_enum)((gps_uart_nmea_location_struct*)(ilm_p->local_para_ptr))->type,
            ((gps_uart_nmea_location_struct*)(ilm_p->local_para_ptr))->port,
            ((gps_uart_nmea_location_struct*)(ilm_p->local_para_ptr))->buffer,
            0);
        break;
    case MSG_ID_GPS_UART_NMEA_SENTENCE:
        mdi_gps_uart_callback_app_ind_hdler(
            MOD_NIL,
            MDI_GPS_PARSER_NMEA_SENTENCE,
            ((gps_uart_nmea_sentence_struct*)(ilm_p->local_para_ptr))->port,
            ((gps_uart_nmea_sentence_struct*)(ilm_p->local_para_ptr))->buffer,
            ((gps_uart_nmea_sentence_struct*)(ilm_p->local_para_ptr))->length);
        break;
    case MSG_ID_GPS_UART_DEBUG_RAW_DATA:
        mdi_gps_gps_debug_info_ind_hdler(ilm_p->local_para_ptr);
        break;
    case MSG_ID_GPS_UART_P_INFO_IND:
        mdi_gps_gps_p_info_ind_hdler(ilm_p->local_para_ptr);
        break;
    default:
        handle_msg = MMI_FALSE;
        break;
    }
    return handle_msg;
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_nmea_calculate_logging_flag_internal
* DESCRIPTION
*  calculate the NVRAM value should store
* PARAMETERS
*  void
* RETURNS
*  the calculated value of NVRAM
*****************************************************************************/
static U8 mdi_gps_nmea_calculate_logging_flag_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    value = 0;
    if (g_mdi_gps_cntx.logging.catcher_logging == MMI_TRUE)
    {
        value |= MDI_GPS_NMEA_CATCHER_LOGGING_FLAG;
    }
    if (g_mdi_gps_cntx.logging.file_logging == MMI_TRUE)
    {
        value |= MDI_GPS_NMEA_FILE_LOGGING_FLAG;
    }
    if (g_mdi_gps_cntx.logging.agent_logging == MMI_TRUE)
    {
        value |= MDI_GPS_NMEA_AGENT_LOGGING_FLAG;
    }
    if (g_mdi_gps_cntx.logging.debug_info == MMI_TRUE)
    {
        value |= MDI_GPS_NMEA_DEBUG_INFO_FLAG;
    }
    if (g_mdi_gps_cntx.logging.power_saving == MMI_TRUE)
    {
        value |= MDI_GPS_NMEA_POWER_SAVING_FLAG;
    }
    if (g_mdi_gps_cntx.logging.hot_still == MMI_TRUE)
    {
        value |= MDI_GPS_NMEA_HOTSTILL_FLAG;
    }
    if (g_mdi_gps_cntx.logging.hot_still_debug == MMI_TRUE)
    {
        value |= MDI_GPS_NMEA_HOTSTILL_DEBUG_FLAG;
    }
    return value;
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_nmea_set_catcher_logging
* DESCRIPTION
*  set the switch for NMEA catcher logging,
* PARAMETERS
*  param    [IN]    MMI_TRUE    open the catcher logging
*                   MMI_FALSE   close the catcher logging
* RETURNS
*  void
*****************************************************************************/
void mdi_gps_nmea_set_catcher_logging(MMI_BOOL param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8  value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_LOG_TRC_SET_CATCHER_LOGGING,param);
    if (param == MMI_TRUE)
    {
        g_mdi_gps_cntx.logging.catcher_logging = MMI_TRUE;
        gps_logging_catcher_enable();
    }
    else
    {
        g_mdi_gps_cntx.logging.catcher_logging = MMI_FALSE;
        gps_logging_catcher_disable();
    }
    value = mdi_gps_nmea_calculate_logging_flag_internal();
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,
        MDI_GPS_LOG_TRC_SET_CATCHER_LOGGING_RES,
        g_mdi_gps_cntx.logging.catcher_logging);
    WriteValue(NRRAM_GPS_LOGGING_SWITCH, &value, DS_BYTE, &error);
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_nmea_set_file_logging
* DESCRIPTION
*  set the switch for NMEA file logging,
* PARAMETERS
*  param    [IN]    MMI_TRUE    open the file logging
*                   MMI_FALSE   close the file logging
* RETURNS
*  void
*****************************************************************************/
void mdi_gps_nmea_set_file_logging(MMI_BOOL param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8  value;
    MMI_BOOL    need_check_flag = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_LOG_TRC_SET_FILE_LOGGING,param);
    if (g_mdi_gps_cntx.logging.file_logging != param)
    {
        need_check_flag = MMI_TRUE;
    }
    if (param == MMI_TRUE)
    {
        g_mdi_gps_cntx.logging.file_logging = MMI_TRUE;
    }
    else
    {
        g_mdi_gps_cntx.logging.file_logging = MMI_FALSE;
        mdi_gps_close_log_file();
    }
    value = mdi_gps_nmea_calculate_logging_flag_internal();
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,
        MDI_GPS_LOG_TRC_SET_FILE_LOGGING_RES,
        g_mdi_gps_cntx.logging.file_logging);
    WriteValue(NRRAM_GPS_LOGGING_SWITCH, &value, DS_BYTE, &error);
    if (need_check_flag == MMI_TRUE)
    {
        mdi_gps_proc_and_open_log_file();
    }
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_nmea_set_agent_logging
* DESCRIPTION
*  set the switch for NMEA agent logging,
* PARAMETERS
*  param    [IN]    MMI_TRUE    open the agent logging
*                   MMI_FALSE   close the agent logging
* RETURNS
*  void
*****************************************************************************/
void mdi_gps_nmea_set_agent_logging(MMI_BOOL param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8  value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_LOG_TRC_SET_AGENT_LOGGING,param);
    if (param == MMI_TRUE)
    {
        g_mdi_gps_cntx.logging.agent_logging = MMI_TRUE;
        gps_logging_agent_enable();
    }
    else
    {
        g_mdi_gps_cntx.logging.agent_logging = MMI_FALSE;
        gps_logging_agent_disable();
    }
    value = mdi_gps_nmea_calculate_logging_flag_internal();
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,
        MDI_GPS_LOG_TRC_SET_AGENT_LOGGING_RES,
        g_mdi_gps_cntx.logging.agent_logging);
    WriteValue(NRRAM_GPS_LOGGING_SWITCH, &value, DS_BYTE, &error);
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_nmea_set_debug_info
* DESCRIPTION
*  set the switch for NMEA debug info,
* PARAMETERS
*  param    [IN]    MMI_TRUE    open the debug info
*                   MMI_FALSE   close the debug info
* RETURNS
*  void
*****************************************************************************/
void mdi_gps_nmea_set_debug_info(MMI_BOOL param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8  value;
    MMI_BOOL    need_check_flag = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_LOG_TRC_SET_DEBUG_INFO ,param);
    if (g_mdi_gps_cntx.logging.debug_info != param)
    {
        need_check_flag = MMI_TRUE;
    }
    if (param == MMI_TRUE)
    {
        g_mdi_gps_cntx.logging.debug_info = MMI_TRUE;
        gps_debug_info_enable();
    }
    else
    {
        g_mdi_gps_cntx.logging.debug_info = MMI_FALSE;
        gps_debug_info_disable();
    }
    value = mdi_gps_nmea_calculate_logging_flag_internal();
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,
        MDI_GPS_LOG_TRC_SET_DEBUG_INFO_RES,
        g_mdi_gps_cntx.logging.agent_logging);
    WriteValue(NRRAM_GPS_LOGGING_SWITCH, &value, DS_BYTE, &error);
    if (need_check_flag == MMI_TRUE)
    {
        mdi_gps_proc_and_open_log_file();
    }
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_nmea_set_power_saving
* DESCRIPTION
*  set the switch for GPS power saving,
* PARAMETERS
*  param    [IN]    MMI_TRUE    enable the power saving
*                   MMI_FALSE   disable the power saving
* RETURNS
*  void
*****************************************************************************/
void mdi_gps_nmea_set_power_saving(MMI_BOOL param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8  value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param == MMI_TRUE)
    {
        g_mdi_gps_cntx.logging.power_saving = MMI_TRUE;
        gps_power_saving_mode_enable();
    }
    else
    {
        g_mdi_gps_cntx.logging.power_saving = MMI_FALSE;
        gps_power_saving_mode_disable();
    }
    value = mdi_gps_nmea_calculate_logging_flag_internal();
    WriteValue(NRRAM_GPS_LOGGING_SWITCH, &value, DS_BYTE, &error);
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_nmea_set_hotstill_setting
* DESCRIPTION
*  set the switch for GPS power saving,
* PARAMETERS
*  param    [IN]    MMI_TRUE    enable the power saving
*                   MMI_FALSE   disable the power saving
* RETURNS
*  void
*****************************************************************************/
void mdi_gps_nmea_set_hotstill_setting(MMI_BOOL param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8  value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param == MMI_TRUE)
    {
        g_mdi_gps_cntx.logging.hot_still = MMI_TRUE;
    }
    else
    {
        g_mdi_gps_cntx.logging.hot_still= MMI_FALSE;
    }
#ifdef __BEE_SUPPORT__
    gps_set_hotstill_shutdown_mode((g_mdi_gps_cntx.logging.hot_still == MMI_TRUE) ? KAL_FALSE : KAL_TRUE);
#endif
    value = mdi_gps_nmea_calculate_logging_flag_internal();
    WriteValue(NRRAM_GPS_LOGGING_SWITCH, &value, DS_BYTE, &error);
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_nmea_set_hotstill_setting
* DESCRIPTION
*  set the switch for GPS power saving,
* PARAMETERS
*  param    [IN]    MMI_TRUE    enable the power saving
*                   MMI_FALSE   disable the power saving
* RETURNS
*  void
*****************************************************************************/
void mdi_gps_nmea_set_hotstill_debug_setting(MMI_BOOL param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8  value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param == MMI_TRUE)
    {
        g_mdi_gps_cntx.logging.hot_still_debug = MMI_TRUE;
    }
    else
    {
        g_mdi_gps_cntx.logging.hot_still_debug = MMI_FALSE;
    }
#ifdef __BEE_SUPPORT__
    gps_set_hotstill_debug_mode(g_mdi_gps_cntx.logging.hot_still_debug);
#endif
    value = mdi_gps_nmea_calculate_logging_flag_internal();
    WriteValue(NRRAM_GPS_LOGGING_SWITCH, &value, DS_BYTE, &error);
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_nmea_load_logging_flag_internal
* DESCRIPTION
*  process loaded data of setting
* PARAMETERS
*  *value       [IN]    the NVRAM's value of setting
* RETURNS
*  void
*****************************************************************************/
static void mdi_gps_nmea_load_logging_flag_internal(U8 *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*value == 0xFF)
    {
        *value = MDI_GPS_NMEA_LOGGING_DEFAULT_FLAG;
        WriteValue(NRRAM_GPS_LOGGING_SWITCH, value, DS_BYTE, &error);
    }
    if (MDI_GPS_NMEA_CATCHER_LOGGING_FLAG & *value)
    {
        g_mdi_gps_cntx.logging.catcher_logging = MMI_TRUE;
    }
    else
    {
        g_mdi_gps_cntx.logging.catcher_logging = MMI_FALSE;
    }
    if (MDI_GPS_NMEA_FILE_LOGGING_FLAG & *value)
    {
        g_mdi_gps_cntx.logging.file_logging = MMI_TRUE;
    }
    else
    {
        g_mdi_gps_cntx.logging.file_logging = MMI_FALSE;
    }
    if (MDI_GPS_NMEA_AGENT_LOGGING_FLAG & *value)
    {
        g_mdi_gps_cntx.logging.agent_logging = MMI_TRUE;
    }
    else
    {
        g_mdi_gps_cntx.logging.agent_logging = MMI_FALSE;
    }
    if (MDI_GPS_NMEA_DEBUG_INFO_FLAG & *value)
    {
        g_mdi_gps_cntx.logging.debug_info = MMI_TRUE;
    }
    else
    {
        g_mdi_gps_cntx.logging.debug_info = MMI_FALSE;
    }
    if (MDI_GPS_NMEA_POWER_SAVING_FLAG & *value)
    {
        g_mdi_gps_cntx.logging.power_saving = MMI_TRUE;
    }
    else
    {
        g_mdi_gps_cntx.logging.power_saving = MMI_FALSE;
    }
    if (MDI_GPS_NMEA_HOTSTILL_FLAG & *value)
    {
        g_mdi_gps_cntx.logging.hot_still = MMI_TRUE;
    }
    else
    {
        g_mdi_gps_cntx.logging.hot_still = MMI_FALSE;
    }
    if (MDI_GPS_NMEA_HOTSTILL_DEBUG_FLAG & *value)
    {
        g_mdi_gps_cntx.logging.hot_still_debug = MMI_TRUE;
    }
    else
    {
        g_mdi_gps_cntx.logging.hot_still_debug = MMI_FALSE;
    }
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_nmea_load_logging_setting
* DESCRIPTION
*  load the setting from NVRAM
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mdi_gps_nmea_load_logging_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16         error;
    U8          value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NRRAM_GPS_LOGGING_SWITCH, &value, DS_BYTE, &error);
    mdi_gps_nmea_load_logging_flag_internal(&value);
    mdi_gps_nmea_set_catcher_logging(g_mdi_gps_cntx.logging.catcher_logging);
    mdi_gps_nmea_set_agent_logging(g_mdi_gps_cntx.logging.agent_logging);
    mdi_gps_nmea_set_debug_info(g_mdi_gps_cntx.logging.debug_info);
    mdi_gps_nmea_set_file_logging(g_mdi_gps_cntx.logging.file_logging);
    mdi_gps_nmea_set_hotstill_setting(g_mdi_gps_cntx.logging.hot_still);
    mdi_gps_nmea_set_hotstill_debug_setting(g_mdi_gps_cntx.logging.hot_still_debug);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MDI_GPS_LOG_TRC_GET_SETTING,
        g_mdi_gps_cntx.logging.catcher_logging,
        g_mdi_gps_cntx.logging.file_logging,
        g_mdi_gps_cntx.logging.agent_logging,
        g_mdi_gps_cntx.logging.debug_info);
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_nmea_get_catcher_logging
* DESCRIPTION
*  get the switch of NMEA catcher logging,
* PARAMETERS
*  void
* RETURNS
*  MMI_TRUE    the catcher logging is opened
*  MMI_FALSE   the catcher logging is closed
*****************************************************************************/
MMI_BOOL mdi_gps_nmea_get_hotstill_debug_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8  value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NRRAM_GPS_LOGGING_SWITCH, &value, DS_BYTE, &error);
    mdi_gps_nmea_load_logging_flag_internal(&value);
    if (MDI_GPS_NMEA_HOTSTILL_DEBUG_FLAG & value)
    {
        g_mdi_gps_cntx.logging.hot_still_debug = MMI_TRUE;
    }
    else
    {
        g_mdi_gps_cntx.logging.hot_still_debug = MMI_FALSE;
    }
#ifdef __BEE_SUPPORT__
    gps_set_hotstill_debug_mode(g_mdi_gps_cntx.logging.hot_still_debug);
#endif
    return g_mdi_gps_cntx.logging.hot_still_debug;
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_nmea_get_catcher_logging
* DESCRIPTION
*  get the switch of NMEA catcher logging,
* PARAMETERS
*  void
* RETURNS
*  MMI_TRUE    the catcher logging is opened
*  MMI_FALSE   the catcher logging is closed
*****************************************************************************/
MMI_BOOL mdi_gps_nmea_get_hotstill_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8  value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NRRAM_GPS_LOGGING_SWITCH, &value, DS_BYTE, &error);
    mdi_gps_nmea_load_logging_flag_internal(&value);
    if (MDI_GPS_NMEA_HOTSTILL_FLAG & value)
    {
        g_mdi_gps_cntx.logging.hot_still = MMI_TRUE;
    }
    else
    {
        g_mdi_gps_cntx.logging.hot_still = MMI_FALSE;
    }
#ifdef __BEE_SUPPORT__
    gps_set_hotstill_shutdown_mode((g_mdi_gps_cntx.logging.hot_still == MMI_TRUE) ? KAL_FALSE : KAL_TRUE);
#endif
    return g_mdi_gps_cntx.logging.hot_still;
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_nmea_get_catcher_logging
* DESCRIPTION
*  get the switch of NMEA catcher logging,
* PARAMETERS
*  void
* RETURNS
*  MMI_TRUE    the catcher logging is opened
*  MMI_FALSE   the catcher logging is closed
*****************************************************************************/
MMI_BOOL mdi_gps_nmea_get_catcher_logging(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8  value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NRRAM_GPS_LOGGING_SWITCH, &value, DS_BYTE, &error);
    mdi_gps_nmea_load_logging_flag_internal(&value);
    if (MDI_GPS_NMEA_CATCHER_LOGGING_FLAG & value)
    {
        g_mdi_gps_cntx.logging.catcher_logging = MMI_TRUE;
        gps_logging_catcher_enable();
    }
    else
    {
        g_mdi_gps_cntx.logging.catcher_logging = MMI_FALSE;
        gps_logging_catcher_disable();
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,
        MDI_GPS_LOG_TRC_GET_CATCHER_LOGGING,
        g_mdi_gps_cntx.logging.catcher_logging);
    return g_mdi_gps_cntx.logging.catcher_logging;
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_nmea_get_file_logging
* DESCRIPTION
*  get the switch of NMEA file logging,
* PARAMETERS
*  void
* RETURNS
*  MMI_TRUE    the file logging is opened
*  MMI_FALSE   the file logging is closed
*****************************************************************************/
MMI_BOOL mdi_gps_nmea_get_file_logging(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8  value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NRRAM_GPS_LOGGING_SWITCH, &value, DS_BYTE, &error);
    mdi_gps_nmea_load_logging_flag_internal(&value);
    if (MDI_GPS_NMEA_FILE_LOGGING_FLAG & value)
    {
        g_mdi_gps_cntx.logging.file_logging = MMI_TRUE;
    }
    else
    {
        g_mdi_gps_cntx.logging.file_logging = MMI_FALSE;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,
        MDI_GPS_LOG_TRC_GET_FILE_LOGGING,
        g_mdi_gps_cntx.logging.file_logging);
    return g_mdi_gps_cntx.logging.file_logging;
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_nmea_get_agent_logging
* DESCRIPTION
*  get the switch of NMEA agnet logging,
* PARAMETERS
*  void
* RETURNS
*  MMI_TRUE    the agent logging is opened
*  MMI_FALSE   the agent logging is closed
*****************************************************************************/
MMI_BOOL mdi_gps_nmea_get_agent_logging(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8  value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NRRAM_GPS_LOGGING_SWITCH, &value, DS_BYTE, &error);
    mdi_gps_nmea_load_logging_flag_internal(&value);
    if (MDI_GPS_NMEA_AGENT_LOGGING_FLAG & value)
    {
        g_mdi_gps_cntx.logging.agent_logging = MMI_TRUE;
        gps_logging_agent_enable();
    }
    else
    {
        g_mdi_gps_cntx.logging.agent_logging = MMI_FALSE;
        gps_logging_agent_disable();
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,
        MDI_GPS_LOG_TRC_GET_AGENT_LOGGING,
        g_mdi_gps_cntx.logging.agent_logging);
    return g_mdi_gps_cntx.logging.agent_logging;
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_nmea_get_debug_info
* DESCRIPTION
*  get the switch of debug info,
* PARAMETERS
*  void
* RETURNS
*  MMI_TRUE    the debug info is opened
*  MMI_FALSE   the debug info is closed
*****************************************************************************/
MMI_BOOL mdi_gps_nmea_get_debug_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8  value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NRRAM_GPS_LOGGING_SWITCH, &value, DS_BYTE, &error);
    mdi_gps_nmea_load_logging_flag_internal(&value);
    if (MDI_GPS_NMEA_DEBUG_INFO_FLAG & value)
    {
        g_mdi_gps_cntx.logging.debug_info = MMI_TRUE;
        gps_debug_info_enable();
    }
    else
    {
        g_mdi_gps_cntx.logging.debug_info = MMI_FALSE;
        gps_debug_info_disable();
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,
        MDI_GPS_LOG_TRC_GET_DEBUG_INFO,
        g_mdi_gps_cntx.logging.debug_info);
    return g_mdi_gps_cntx.logging.debug_info;
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_nmea_get_power_saving
* DESCRIPTION
*  get the switch of NMEA agnet logging,
* PARAMETERS
*  void
* RETURNS
*  MMI_TRUE    the power saving is opened
*  MMI_FALSE   the power saving is closed
*****************************************************************************/
MMI_BOOL mdi_gps_nmea_get_power_saving(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8  value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NRRAM_GPS_LOGGING_SWITCH, &value, DS_BYTE, &error);
    mdi_gps_nmea_load_logging_flag_internal(&value);
    if (MDI_GPS_NMEA_POWER_SAVING_FLAG & value)
    {
        g_mdi_gps_cntx.logging.power_saving = MMI_TRUE;
        gps_power_saving_mode_enable();
    }
    else
    {
        g_mdi_gps_cntx.logging.power_saving = MMI_FALSE;
        gps_power_saving_mode_disable();
    }
    return g_mdi_gps_cntx.logging.power_saving;
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_set_work_port
* DESCRIPTION
*  set parser or logging work port
* PARAMETERS
*  port        [IN]        port number for parser
* RETURNS
*  void
*****************************************************************************/
void mdi_gps_set_work_port(U8 port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(port <= uart_max_port);
    gps_set_work_port(port);
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_enable_parser
* DESCRIPTION
*  enable the parser
* PARAMETERS
*  port        [IN]        port number for parser
*  mode        [IN]        the mode of parser
* RETURNS
*  MMI_TRUE    enable parser ok
*  MMI_FALSE   enable parser failed
*****************************************************************************/
void mdi_gps_enable_parser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_disable_parser
* DESCRIPTION
*  disable parser
* PARAMETERS
*  void
* RETURNS
*  MMI_TRUE        disable parser ok
*  MMI_FALSE       disable parser failed
*****************************************************************************/
MMI_BOOL mdi_gps_disable_parser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_disable_parser
* DESCRIPTION
*  disable parser
* PARAMETERS
*  void
* RETURNS
*  MMI_TRUE        disable parser ok
*  MMI_FALSE       disable parser failed
*****************************************************************************/
void mdi_gps_eng_disable_sentence(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gps_nmea_eng_sentence_disable();
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_disable_parser
* DESCRIPTION
*  disable parser
* PARAMETERS
*  void
* RETURNS
*  MMI_TRUE        disable parser ok
*  MMI_FALSE       disable parser failed
*****************************************************************************/
void mdi_gps_eng_enable_sentence(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gps_nmea_eng_sentence_enable();
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_is_parser_enabled
* DESCRIPTION
*  return the state of parser
* PARAMETERS
*  void
* RETURNS
*  MMI_TRUE    enabled
*  MMI_FALSE   disabled
*****************************************************************************/
MMI_BOOL mdi_gps_is_parser_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_get_firmware_version
* DESCRIPTION
*  return firmware version
* PARAMETERS
*  void
* RETURNS
*  MMI_TRUE    enabled
*  MMI_FALSE   disabled
*****************************************************************************/
CHAR* mdi_gps_get_firmware_version(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (CHAR*)gps_p_get_fireware_version();
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_register_p_callback
* DESCRIPTION
*  register the callback function of p info process
* PARAMETERS
*  *gps_uart_p_callback  [IN]  callback function pointer
* RETURNS
*  old callback function pointer
*****************************************************************************/
/*****************************************************************************
* Please use mdi_gps_register_p_info_callback don't use this any more
*****************************************************************************/
void* mdi_gps_register_p_callback(void (*gps_uart_p_callback)(mdi_gps_parser_p_info_enum type))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void (*old_callback)(mdi_gps_parser_p_info_enum type);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_callback = g_mdi_gps_cntx.gps_uart_p_callback;
    g_mdi_gps_cntx.gps_uart_p_callback = gps_uart_p_callback;
    return (void *)old_callback;
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_register_p_info_callback
* DESCRIPTION
*  register the callback function of p info process
* PARAMETERS
*  *mdi_gps_register_p_info_callback  [IN]  callback function pointer
*           type                  *param
* GPS_PARSER_P_GPS_FIXED   gps_p_info_gps_fix_struct
* RETURNS
*  old callback function pointer
*****************************************************************************/
void* mdi_gps_register_p_info_callback(void (*gps_uart_p_info_callback)(mdi_gps_parser_p_info_enum type,void *param))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void (*old_callback)(mdi_gps_parser_p_info_enum type,void *param);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_callback = g_mdi_gps_cntx.gps_uart_p_info_callback;
    g_mdi_gps_cntx.gps_uart_p_info_callback = gps_uart_p_info_callback;
    return (void *)old_callback;
}

/*****************************************************************************
* FUNCTION
*  mdi_get_gps_port
* DESCRIPTION
*  return the gps uart port
* PARAMETERS
*  void
* RETURNS
*  gps uart port
*****************************************************************************/
S16 mdi_get_gps_port(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__GPS_SUPPORT__)
    return (S16)GPS_Get_UART_Port();
#else
    return -1;
#endif
}

/*****************************************************************************
* FUNCTION
*  mdi_gps_get_mdi_error_info
* DESCRIPTION
*  return string id by error code
* PARAMETERS
*  error_code   [IN]    error code
*  *popup_type  [OUT]   bring back the popup event type
* RETURNS
*  string id
*****************************************************************************/
MMI_ID_TYPE mdi_gps_get_mdi_error_info(MDI_RESULT error_code, mmi_event_notify_enum* popup_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 string_id = MDI_RES_GPS_UART_SUCCEED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *popup_type = MMI_EVENT_FAILURE;
    switch(error_code)
    {
    case MDI_RES_GPS_UART_ERR_PORT_ALREADY_OPEN:
        string_id = STR_ID_MDI_GPS_UART_ERR_PORT_ALREADY_OPEN;
        break;
    case MDI_RES_GPS_UART_ERR_PORT_NUMBER_WRONG:
        string_id = STR_ID_MDI_GPS_UART_ERR_PORT_NUMBER_WRONG;
        break;
    case MDI_RES_GPS_UART_ERR_PARAM_ERROR:
        string_id = STR_ID_MDI_GPS_UART_ERR_PARAM_ERROR;
        break;
    case MDI_RES_GPS_UART_ERR_PORT_ALREADY_CLOSED:
        string_id = STR_ID_MDI_GPS_UART_ERR_PORT_ALREADY_CLOSED;
        break;
    case MDI_RES_GPS_UART_ERR_PORT_ERR_UNKNOW:
        string_id = STR_ID_MDI_GPS_UART_ERR_PORT_ERR_UNKNOW;
        break;
    case MDI_RES_GPS_UART_ERR_PORT_ERR_NOT_OPEN:
        string_id = STR_ID_MDI_GPS_UART_ERR_PORT_ERR_NOT_OPEN;
        break;
    case MDI_RES_GPS_UART_ERR_NO_SLOT:
        string_id = STR_ID_MDI_GPS_UART_ERR_NO_SLOT;
        break;
    default:
        break;
    }
    return string_id;
}


#endif /*defined(__GPS_SUPPORT__) || defined(__BT_GPS_SUPPORT__)*/

