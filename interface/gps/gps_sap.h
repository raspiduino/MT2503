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
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2003
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *  gps_sap.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GIS SAP
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
MSG_ID_GPS_UART_OPEN_REQ = MSG_ID_GPS_MSG_CODE_BEGIN,
MSG_ID_GPS_UART_READ_REQ,
MSG_ID_GPS_UART_WRITE_REQ,
MSG_ID_GPS_UART_CLOSE_REQ,
MSG_ID_GPS_UART_NMEA_LOCATION,
MSG_ID_GPS_UART_NMEA_SENTENCE,
MSG_ID_GPS_UART_RAW_DATA,
MSG_ID_GPS_UART_DEBUG_RAW_DATA,
MSG_ID_GPS_UART_P_INFO_IND,
#ifdef __GPS_ADAPTOR_SUPPORT__
MSG_ID_GPS_UART_RETURN_CONFIRM_IND,
#endif
MSG_ID_GPS_UART_OPEN_SWITCH_REQ,
MSG_ID_GPS_UART_CLOSE_SWITCH_REQ,
#ifndef __SMART_PHONE_MODEM__
MSG_ID_GPS_UART_LOG_WRITE_REQ,
#endif

MSG_ID_GPS_POS_GAD_CNF,
MSG_ID_GPS_LCSP_MSG_CODE_BEGIN = MSG_ID_GPS_POS_GAD_CNF,
MSG_ID_GPS_LCSP_MEAS_GAD_CNF,
MSG_ID_GPS_LCSP_ASSIST_DATA_CNF,
MSG_ID_GPS_LCSP_MSG_CODE_END = MSG_ID_GPS_LCSP_ASSIST_DATA_CNF,
MSG_ID_GPS_POS_GAD_REQ,
MSG_ID_GPS_LCSP_MEAS_GAD_REQ,
MSG_ID_GPS_LCSP_ASSIST_DATA_REQ,
MSG_ID_GPS_LCSP_ABORT_REQ,

MSG_ID_GPS_ASSIST_BIT_MASK_IND,

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* RTC -> GPS */
MSG_ID_RTC_GPS_TIME_CHANGE_IND,
/* GPS EINT HISR -> GPS */
MSG_ID_GPS_HOST_WAKE_UP_IND,

MSG_ID_UAGPS_CP_GPS_ASSIST_DATA_ENQUIRY_IND,
MSG_ID_UAGPS_CP_GPS_SFN_GPS_TOW_DRIFT_TIME_REQ,
MSG_ID_UAGPS_CP_GPS_SFN_GPS_TOW_DRIFT_TIME_CNF,
MSG_ID_UAGPS_CP_GPS_SFN_GPS_TOW_DRIFT_TIME_CANCEL_REQ,
MSG_ID_GPS_AREA_EVENT_ADD_RSP,
MSG_ID_GPS_AREA_EVENT_ADD_REQ,
MSG_ID_GPS_AREA_EVENT_DEL_REQ,
MSG_ID_GPS_AREA_EVENT_HAPPEN_IND,
MSG_ID_UAGPS_CP_GPS_POS_CHANGE_EVALUATION_REQ,
MSG_ID_UAGPS_CP_GPS_POS_CHANGE_EVALUATION_RSP,
MSG_ID_UAGPS_CP_GPS_POS_CHANGE_EVALUATION_DEL,

/* GPS -> BEE */
MSG_ID_GPS_HOTSTILL_SHUTDOWN_REQ,
MSG_ID_GPS_HOTSTILL_RESUME_REQ,
MSG_ID_GPS_HOTSTILL_DEBUG_ENABLE_REQ,
MSG_ID_GPS_HOTSTILL_DEBUG_DISABLE_REQ,

/* GPS ATE */
MSG_ID_MMI_GPS_ATE_TEST_REQ,

#ifdef UNIT_TEST
/* GPS -> GPS */
MSG_ID_GPS_UT_SET_EVENT_IND,
MSG_ID_GPS_UT_WRITE_DATA_IND,
#endif

/*  FT ( META ) --> GPS */
MSG_ID_META_GPS_OP_REQ,    

/* GPS --> FT ( META ) */
MSG_ID_META_GPS_OP_RSP,
MSG_ID_META_GPS_DATA_IND,

/* GPS --> Feature Config */
MSG_ID_ENABLE_EPO_DOWNLOAD,
MSG_ID_ENABLE_TIME_SYNC,
MSG_ID_DISABLE_EPO_DOWNLOAD,
MSG_ID_DISABLE_TIME_SYNC,
#if defined(EMPTY_MMI)
MSG_ID_GPS_SYNC_TIME,
#endif
MSG_ID_SUPL_ENABLE,
MSG_ID_SUPL_DISABLE,

MSG_ID_SUPL_FORCE_LOCATION_REQ,

