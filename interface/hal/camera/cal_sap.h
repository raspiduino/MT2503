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
 *   cal_sap.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   CAL task related message identity definition
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*------------------------CAL_MSG_CODE_BEGIN ---------------*/
    MSG_ID_CAL_STARTUP_REQ = MSG_ID_CAL_CODE_BEGIN,
    MSG_ID_CAL_STARTUP_CNF,     // will be removed after MED checked in
    MSG_ID_CAL_ROTATE_IMAGE_REQ,
    MSG_ID_CAL_RESIZE_QUICK_VIEW_AND_THUMBNAIL_IMAGE_REQ,
    MSG_ID_CAL_JAIA_MERGE_REQ,
    MSG_ID_CAL_PP_START_REQ,
    MSG_ID_CAL_WEBCAM_FRAME_READY_REQ,
    MSG_ID_CAL_INFORM_MDP_FRAME_RATE_REQ,
    MSG_ID_CAL_GET_PREVIEW_IMAGE_REQ,
    MSG_ID_CAL_JPEG_SENSOR_PARSE_REQ,
    MSG_ID_CAL_SW_Y2R_DITHERING_REQ,
    MSG_ID_CAL_SW_RESIZER_START_REQ,
    MSG_ID_CAL_VIDEO_RENDERER_REQ,
    MSG_ID_CAL_SW_IMAGE_EFFECT_REQ,
    MSG_ID_CAL_COPY_AND_RESIZE_POSTPROC_IMAGE_REQ,
    MSG_ID_CAL_G2D_REQ,
    MSG_ID_CAL_MAX,

    MSG_ID_CAL_LOW_START,
    MSG_ID_CAL_LOW_SW_JPEG_ENCODE_REQ = MSG_ID_CAL_LOW_START,
    MSG_ID_CAL_LOW_HW_JPEG_ENCODE_REQ,
    MSG_ID_CAL_LOW_JPEG_DECODE_REQ,
    MSG_ID_CAL_LOW_PP_START_REQ,
    MSG_ID_CAL_LOW_PP_START_TIMER_REQ,
    MSG_ID_CAL_LOW_PP_STOP_REQ, 
    MSG_ID_CAL_LOW_GET_AF_RESULT,
    MSG_ID_CAL_LOW_ROTATE_IMAGE_LIST_REQ,
    MSG_ID_CAL_LOW_MAX,
    MSG_ID_CAL_CODE_END = MSG_ID_CAL_LOW_MAX,
/*------------------------CAL_MSG_CODE_END -----------------*/

