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
 *  BarcodeReaderOp02ResDefs.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  barcodereader op02
 *
 * Author:
 * -------
 * -------
 *                      
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MMI_BARCODEREADER_COMMON_RES_H
#define MMI_BARCODEREADER_COMMON_RES_H

#define MMI_BARCODEREADER_COMMON_RESOURCE_BASE (BARCODEREADER_BASE + 100)

typedef enum
{
    STR_ID_BARCODEREADER_ERROR_NO_ERROR = MMI_BARCODEREADER_COMMON_RESOURCE_BASE,
    STR_ID_BARCODEREADER_ERROR_ENCODING_ERROR,
    STR_ID_BARCODEREADER_ERROR_COMMON,
    STR_ID_BARCODEREADER_ERROR_DECODE_FAILED,
    STR_ID_BARCODEREADER_ERROR_NOT_DM_CODE,
    STR_ID_BARCODEREADER_ERROR_NOT_SUPPORT_THIS_SERIVCE,
    STR_ID_BARCODEREADER_ERROR_NOT_SUPPORT_THIS_MODE,
    STR_ID_BARCODEREADER_ERROR_FORMAT,
    STR_ID_BARCODEREADER_ERROR_TOO_LONG_URL,
    STR_ID_BARCODEREADER_ERROR_FORBID_DIRECT_MODE,
    STR_ID_BARCODEREADER_ERROR_SERVER_NOT_CONNECT,
    STR_ID_BARCODEREADER_ERROR_SERVER_NOT_CONFIGED,
    STR_ID_BARCODEREADER_ERROR_DECODE_TIMEOUT,
    STR_ID_BARCODEREADER_ERROR_FILE_CORRUPT,
    STR_ID_BARCODEREADER_ERROR_NO_SIMCARD,
    STR_ID_BARCODEREADER_OP01_ENCODING_ERROR,
    STR_ID_BARCODEREADER_NOTIFY_NO_MEMORY_CARD,

    STR_ID_BARCODEREADER_QUESTION,
    STR_ID_BARCODEREADER_ERROR_ALL
} mmi_barcoderader_common_string_id_enum;

#endif /* MMI_BARCODEREADER_COMMON_RES_H */ 

