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
 *   gps_ate.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   GPS ATE
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef FACTORYMODEGPS_C
#define FACTORYMODEGPS_C

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_include.h"

#ifdef __GPS_SUPPORT__

#include "mmiapi_struct.h"
#include "mdi_datatype.h"
#include "mdi_gps.h"
#include "gps_ate.h"
#include "FileMgrSrvGProt.h"
#include "FileManagerGProt.h"
#include "gps_struct.h"

extern kal_uint8 GPS_Get_UART_Port(void);


/*****************************************************************************
 * Typedef
 *****************************************************************************/
typedef struct {
    MMI_BOOL is_poweron;

    s32 ut_file_idx;
    S32 ut_file_handle;
} mmi_fm_gps_ate_cntx;


/*****************************************************************************
 * Define
 *****************************************************************************/

/*****************************************************************************
 * Global Variable
 *****************************************************************************/
static mmi_fm_gps_ate_cntx g_mmi_fm_gps_ate_cntx;
static mmi_fm_gps_ate_cntx *mmi_fm_gps_ate_p = &g_mmi_fm_gps_ate_cntx;

void GPS_ATE_SendMsg(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_send_ilm((oslModuleType) MOD_L4C, (oslMsgType)msg_id,
                        (oslParaType*)local_param_ptr, (oslPeerBuffType*)peer_buf_ptr);

}

/*
 * [AT Command]
 * (1) Disable Sleep: at+eslp=0
 * (2) Power On : at+egcmd = 3, 1, "00"
 * (3) Power Off : at+egcmd = 4, 1, "00"
 * (4) TTFF (Cold Start) $PMTK101*30\x0d\x0a : at+egcmd = 5, 13, "24504D544B3130312A33300D0A"
 * (5) 1-command Test    $PMTK810,000F,10*4C\x0d\x0a : at+egcmd = 5, 21, "24504D544B3831302C303030462C31302A34430D0A"
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_gps_ate_send_to_at_uart
 * DESCRIPTION
 *  Send data out from UART
 * PARAMETERS
 *  buf_size    [IN]        buffer size
 *  buf_ptr     [IN]        data
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_gps_ate_send_to_at_uart(U16 buf_size, CHAR *buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_str_res_req_struct *rsp_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_msg = (mmi_eq_str_res_req_struct *)OslConstructDataPtr(sizeof(mmi_eq_str_res_req_struct));
    memcpy(rsp_msg->data_string, buf_ptr, buf_size);
    rsp_msg->length = buf_size;

    GPS_ATE_SendMsg(MSG_ID_MMI_EQ_STR_RES_REQ, rsp_msg, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_gps_ate_data_callback
 * DESCRIPTION
 *  Get data callback function
 * PARAMETERS
 *  type        [IN]        incoming data type
 *  buffer      [IN]        data
 *  length      [IN]        data size
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_gps_ate_data_callback(mdi_gps_parser_info_enum type, void *buffer, U32 length)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == MDI_GPS_UART_MODE_RAW_DATA)
    {
    #ifdef __MMI_FM_GPS_ATE_UT__
        {
            U32 written;

            if (mmi_fm_gps_ate_p->ut_file_handle > 0)
            {
                FS_Write(mmi_fm_gps_ate_p->ut_file_handle, buffer, length, &written);
            }
        }
    #endif /* __MMI_FM_GPS_ATE_UT__ */

        mmi_fm_gps_ate_send_to_at_uart(length, buffer);
    }
    else
    {
        /* invalid type */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_gps_ate_power_on
 * DESCRIPTION
 *  Power on GPS module
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_gps_ate_power_on(void)
{
#ifdef __MMI_FM_GPS_ATE_UT__
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define MMI_FM_GPS_UT_FILENAME_LEN (50)

    CHAR filename[MMI_FM_GPS_UT_FILENAME_LEN];
    CHAR filename_ucs2[MMI_FM_GPS_UT_FILENAME_LEN * ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	sprintf((CHAR*)filename, "%c:\\GPS_ATE_%d.log", SRV_FMGR_CARD_DRV, mmi_fm_gps_ate_p->ut_file_idx);
    mmi_asc_to_ucs2(filename_ucs2, filename);
    mmi_fm_gps_ate_p->ut_file_handle = FS_Open((kal_wchar*)filename_ucs2, FS_CREATE_ALWAYS | FS_READ_WRITE);
    mmi_fm_gps_ate_p->ut_file_idx++;
#endif  /* __MMI_FM_GPS_ATE_UT__ */

    if (!mmi_fm_gps_ate_p->is_poweron)
    {
        mdi_gps_uart_open((U16)mdi_get_gps_port(), MDI_GPS_UART_MODE_RAW_DATA, mmi_fm_gps_ate_data_callback);

        mmi_fm_gps_ate_p->is_poweron = MMI_TRUE;

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_gps_ate_power_off
 * DESCRIPTION
 *  Power off GPS module
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_gps_ate_power_off(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_fm_gps_ate_p->is_poweron)
    {
        mdi_gps_uart_close((U16)GPS_Get_UART_Port(), MDI_GPS_UART_MODE_RAW_DATA, mmi_fm_gps_ate_data_callback);
        mmi_fm_gps_ate_p->is_poweron = MMI_FALSE;
    }

#ifdef __MMI_FM_GPS_ATE_UT__
    if (mmi_fm_gps_ate_p->ut_file_handle > 0)
    {
        FS_Close(mmi_fm_gps_ate_p->ut_file_handle);
    }
#endif /* __MMI_FM_GPS_ATE_UT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_gps_ate_send_pmtk_command
 * DESCRIPTION
 *  Send pmtk command to gps module
 * PARAMETERS
 *  data_len        [IN]        command len
 *  data_str        [IN]        command data
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_gps_ate_send_pmtk_command(kal_int32 data_len, kal_uint8 *data_str)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 written;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_gps_uart_write((U16)GPS_Get_UART_Port(), data_str, data_len, &written);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fm_gps_ate_test_cmd_req_hdlr
 * DESCRIPTION
 *  Test cammand req handler, this function will handle test requst send from
 *  L4 Uart (at+cmd)
 * PARAMETERS
 *  msg_ptr         [IN]       message data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fm_gps_ate_test_cmd_req_hdlr(void *msg_ptr)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gps_ate_test_req_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (gps_ate_test_req_struct*)msg_ptr;

    if (ind_p->event == MMI_GPS_ATE_EVENT_POWER_ON)
    {
        mmi_fm_gps_ate_power_on();
    }
    else if (ind_p->event == MMI_GPS_ATE_EVENT_POWER_OFF)
    {
        mmi_fm_gps_ate_power_off();
    }
    else if (ind_p->event == MMI_GPS_ATE_EVENT_COMMAND)
    {
        mmi_fm_gps_ate_send_pmtk_command(ind_p->cmd_length, ind_p->cmd_buf);
    }
    else
    {
        MMI_ASSERT(0);
    }

}


#ifdef __MMI_FM_GPS_ATE_UT__
typedef enum
{
    MMI_FM_GPS_ATE_UT_ONE_COMMAND_TEST,
    MMI_FM_GPS_ATE_UT_TTFF,

    MMI_FM_GPS_ATE_UT_END_OF_ENUM
} mmi_fm_gps_ate_ut_test_item_enum;

#define MMI_FMG_GPS_ATE_UT_TEST MMI_FM_GPS_ATE_UT_ONE_COMMAND_TEST

static void mmi_fmg_gps_ut_send_one_command_test(void)
{
    U8 pmtk_cmd[] = "$PMTK810,000F,10*4C\x0d\x0a";
    mmi_fm_gps_ate_send_pmtk_command(sizeof(pmtk_cmd), pmtk_cmd);
}

static void mmi_fmg_gps_ut_send_ttff(void)
{
    U8 pmtk_cmd[] = "$PMTK101*30\x0d\x0a";
    mmi_fm_gps_ate_send_pmtk_command(sizeof(pmtk_cmd), pmtk_cmd);
}

static void mmi_fmg_gps_ut_send_command(void)
{
    switch(MMI_FMG_GPS_ATE_UT_TEST)
    {
        case MMI_FM_GPS_ATE_UT_ONE_COMMAND_TEST:
            mmi_fmg_gps_ut_send_one_command_test();
            break;

        case MMI_FM_GPS_ATE_UT_TTFF:
            mmi_fmg_gps_ut_send_ttff();
            break;

        default:
            MMI_ASSERT(0);
    }
}


void mmi_fm_gps_start_ut(void)
{
    mmi_fm_gps_ate_power_on();

    /* start 1 command test after 3 sec */
    gui_start_timer(3000, mmi_fmg_gps_ut_send_command);
}

void mmi_fm_gps_stop_ut(void)
{
    gui_cancel_timer(mmi_fmg_gps_ut_send_command);
    mmi_fm_gps_ate_power_off();
}

#endif /* __MMI_FM_GPS_ATE_UT__ */


#endif /* __GPS_SUPPORT__ */
#endif /* FACTORYMODEGPS_C */
