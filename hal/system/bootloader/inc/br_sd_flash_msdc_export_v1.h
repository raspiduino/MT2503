/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *   br_sd_flash_msdc_export_v1.h
 *
 * Project:
 * --------
 *   BOOTROM
 *
 * Description:
 * ------------
 *   BOOTROM MSDC flash shared driver version 1 (EXPORTED APIs)
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __BR_SD_FLASH_MSDC_EXPORT_V1_H__
#define __BR_SD_FLASH_MSDC_EXPORT_V1_H__

#include "tcard_drv.h"

#ifdef __cplusplus
extern "C" {
#endif

//==============================================================================
// Shared MSDC flash driver function prototype
//==============================================================================

typedef MSDC_STATUS (*SD_MSDC_INIT_V1)              (PMSDC_USER_HANDLE pUser_Handle,void (*timer_callback)(kal_uint32),kal_uint32 init_timeout,PMSDC_USER_REQ_DESCRIPTOR preq);
typedef MSDC_STATUS (*SD_MSDC_READ_V1)              (PMSDC_USER_HANDLE pUser_Handle,PMSDC_USER_REQ_DESCRIPTOR pUser_Req,void (*timer_callback)(kal_uint32),kal_uint32 read_timeout);
typedef MSDC_STATUS (*SD_MSDC_DEINIT_V1)            (PMSDC_USER_HANDLE pUser_Handle,void (*timer_callback)(kal_uint32),kal_uint32 deinit_timeout);
typedef MSDC_STATUS (*SD_MSDC_TUNING_CLK_V1)        (PMSDC_USER_HANDLE pUser_Handle);
typedef void        (*SD_MSDC_CUSTOM_INIT_V1)       (MSDC_USER_HANDLE *pbrom);
typedef void        (*SD_MSDC_CUSTOM_DE_INIT_V1)    (MSDC_USER_HANDLE *pbrom);

//==============================================================================
// Shared MSDC flash driver function table
//==============================================================================
typedef struct SD_MSDC_FuncTable_v1 {
    SD_MSDC_INIT_V1             m_msdc_init;
    SD_MSDC_READ_V1             m_msdc_read;
    SD_MSDC_DEINIT_V1           m_msdc_deinit;
    SD_MSDC_TUNING_CLK_V1       m_msdc_tuning_clk;
    SD_MSDC_CUSTOM_INIT_V1      m_msdc_custom_init;
    SD_MSDC_CUSTOM_DE_INIT_V1   m_msdc_custom_de_init;
} SD_MSDC_FuncTable_v1;

#ifdef __cplusplus
}
#endif

#endif

