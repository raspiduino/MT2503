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
 *  SIMAccessGprot.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intended for the header file of "SIM Access" feature. 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef SIM_ACCESS_GPROT_H
#define SIM_ACCESS_GPROT_H

/***************************************************************************** 
 * Include 
 *****************************************************************************/
/* Write your #include header file here */

/***************************************************************************** 
 * Define
 *****************************************************************************/
/* Write your #define here */

/* Definitions of maximum supported SIM access count. This macro also defines how many 
MMI applications can access SIM via this service concurrently. */
#define MMI_SIM_ACCESS_MAX_COUNT    (5)

/* Definitions of SIM access operation */
#define MMI_SIM_ACCESS_READ     (0)

/* Definitions of SIM access operation */
#define MMI_SIM_ACCESS_WRITE    (1)

/* Definitions of SIM access operation */
#define MMI_SIM_ACCESS_INFO     (2)

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  FuncPtrSIMAccess
 * DESCRIPTION
 *  Definitions of SIM access callback
 * PARAMETERS
 *  error_code:         [IN]        error code (SIM command result (sim_common_enums.h))
 *  read_length:        [IN]        read length
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*FuncPtrSIMAccess) (U16 error_code, U16 read_length);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  FuncPtrSIMInfo
 * DESCRIPTION
 *  Definitions of SIM info callback
 * PARAMETERS
 *  error_code:         [IN]        error code (SIM command result (sim_common_enums.h))
 *  file_size:          [IN]        total file size
 *  record_num:         [IN]        number of records
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*FuncPtrSIMInfo) (U16 error_code, U16 file_size, U16 record_num);

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
/* Write your global variable here */

/***************************************************************************** 
 * Global Function 
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_sim_access_transparent_ef
 * DESCRIPTION
 *  This function is used to access a transparent EF.
 * PARAMETERS
 *  file_index:         [IN]        EF index to access in "sim_common_enums.h"
 *  file_path:          [IN]        EF path with null terminator if file_index is FILE_NONE
 *  app_id:             [IN]        Application ID (MMIDataType.h)
 *  access_type:        [IN]        Read or write
 *  access_offset:      [IN]        Read/write offset from the beginning of the transparent EF
 *  access_length:      [IN]        Read/write data length
 *  data_buffer:        [IN]        Data buffer to keep read/write data
 *  buffer_length:      [IN]        Data buffer length, must not be shorter than access_length.
 *  read_callback:      [IN]        Callback to get data/error code
 *  sim_interface:      [IN]        Gemini: specify access SIM1 or SIM2 (sim_common_enums.h)
 * RETURNS
 *  a boolean value
 * RETURN VALUES
 *  MMI_TRUE:           This request is accepted.
 *  MMI_FALSE:          This request is rejected.
 *****************************************************************************/
extern MMI_BOOL mmi_sim_access_transparent_ef(
                    U8 file_index,                  /* EF index to access in "sim_common_enums.h" */
                    U8 *file_path,                  /* EF path with null terminator if file_index is FILE_NONE */
                    U8 app_id,                      /* Application ID (MMIDataType.h) */
                    U8 access_type,                 /* Read or write */
                    U16 access_offset,              /* Read/write offset from the beginning of the transparent EF */
                    U16 access_length,              /* Read/write data length */
                    U8 *data_buffer,                /* Data buffer to keep read/write data */
                    U16 buffer_length,              /* Data buffer length, must not be shorter than access_length. */
                    FuncPtrSIMAccess read_callback, /* Callback to get data/error code */
                    U8 sim_interface                /* Gemini: specify access SIM1 or SIM2 (sim_common_enums.h) */
                    );

/*****************************************************************************
 * FUNCTION
 *  mmi_sim_access_linear_fixed_ef
 * DESCRIPTION
 *  This function is used to access a linear fixed EF.
 * PARAMETERS
 *  file_index:         [IN]        EF index to access in "sim_common_enums.h"
 *  file_path:          [IN]        EF path with null terminator if file_index is FILE_NONE
 *  app_id:             [IN]        Application ID (MMIDataType.h)
 *  access_type:        [IN]        Read or write
 *  access_index:       [IN]        Read/write index of all records
 *  access_size:        [IN]        Read/write size of each record
 *  data_buffer:        [IN]        Data buffer to keep read/write data
 *  buffer_length:      [IN]        Data buffer length, must not be shorter than access_size.
 *  read_callback:      [IN]        Callback to get data/error code
 *  sim_interface:      [IN]        Gemini: specify access SIM1 or SIM2 (sim_common_enums.h)
 * RETURNS
 *  a boolean value
 * RETURN VALUES
 *  MMI_TRUE:           This request is accepted.
 *  MMI_FALSE:          This request is rejected.
 *****************************************************************************/
extern MMI_BOOL mmi_sim_access_linear_fixed_ef(
                    U8 file_index,
                    U8 *file_path,
                    U8 app_id,
                    U8 access_type,
                    U16 access_index,               /* Read/write index of all records */
                    U16 access_size,                /* Read/write size of each record */
                    U8 *data_buffer,
                    U16 buffer_length,
                    FuncPtrSIMAccess read_callback,
                    U8 sim_interface
                    );

/*****************************************************************************
 * FUNCTION
 *  mmi_sim_access_file_info
 * DESCRIPTION
 *  This function is used to read EF info, including file size and record numbers.
 * PARAMETERS
 *  file_index:         [IN]        EF index to access in "sim_common_enums.h"
 *  file_path:          [IN]        EF path with null terminator if file_index is FILE_NONE
 *  app_id:             [IN]        Application ID (MMIDataType.h)
 *  info_callback:      [IN]        Please set a callback to get returned file info.
 *  sim_interface:      [IN]        Gemini: specify access SIM1 or SIM2 (sim_common_enums.h)
 * RETURNS
 *  a boolean value
 * RETURN VALUES
 *  MMI_TRUE:           This request is accepted.
 *  MMI_FALSE:          This request is rejected.
 *****************************************************************************/
extern MMI_BOOL mmi_sim_access_file_info(
                    U8 file_index,
                    U8 *file_path,
                    U8 app_id,
                    FuncPtrSIMInfo info_callback,   /* Please set a callback to get returned file info. */
                    U8 sim_interface
                    );

#endif /* SIM_ACCESS_GPROT_H */

