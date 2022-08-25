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
 * mmi_frm_nvram_gprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for NVRAM function prototype.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MMI_FRM_NVRAM_GPROT_H
#define MMI_FRM_NVRAM_GPROT_H


#include "MMIDataType.h"
#include "nvram_enums.h"
#include "kal_general_types.h"


/***************************************************************************** 
* Define
*****************************************************************************/

/* NVRAM read req msg struct. */
#define MMIEQNVRAMREADREQ     mmi_eq_nvram_read_req_struct

/* NVRAM read rsp msg struct. */
#define MMIEQNVRAMREADRSP     mmi_eq_nvram_read_rsp_struct

/* NVRAM write req msg struct. */
#define MMIEQNVRAMWRITEREQ    mmi_eq_nvram_write_req_struct

/* NVRAM write req msg struct. */
#define MMIEQNVRAMWRITERSP    mmi_eq_nvram_write_rsp_struct

/* NVRAM reset req msg struct. */
#define MMIEQNVRAMRESETREQ    mmi_eq_nvram_reset_req_struct

/* NVRAM reset rsp msg struct. */
#define MMIEQNVRAMRESETRSP    mmi_eq_nvram_reset_rsp_struct

/***************************************************************************** 
* Typedef 
*****************************************************************************/


/* This enum is used to indicate the three framework NVRAM cache type and their values stand for  the small data item size. */
typedef enum
{
    /* Corresponding to NVRAM_EF_CACHE_BYTE_LID. */
    DS_BYTE = 1,
    /* Corresponding to NVRAM_EF_CACHE_SHORT_LID. */
    DS_SHORT = 2,
    /* Corresponding to NVRAM_EF_CACHE_DOUBLE_LID. */
    DS_DOUBLE = 8
} DATASIZE;

/* This enum is used to indicate the NVRAM operation error code. */
typedef enum
{   
    /* Read NVRAM fail. */
    NVRAM_READ_FAIL,
    /* Read NVRAM success. */
    NVRAM_READ_SUCCESS,
    /* Read NVRAM actual size is greater than requested size. */
    NVRAM_ERROR_ACTUAL_READ_GREATER_THAN_REQUESTED_READ,
    /* Read NVRAM actual size is less than requested size. */
    NVRAM_ERROR_ACTUAL_READ_LESS_THAN_REQUESTED_READ,
    /* Write NVRAM success. */
    NVRAM_WRITE_SUCCESS,
    /* Write NVRAM fail. */
    NVRAM_WRITE_FAIL
} MMINVRAMERRORSENUM;

/* This enum is used to correspond to the NVRAM RSP MSG result field. */
typedef enum
{
    /* NVRAM operation success. */
    MMI_OK,
    /* NVRAM operation failure. */
    MMI_ERROR
} MMIRESULTENUM;

/* DOM-NOT_FOR_SDK-BEGIN */
typedef enum    /* l4c_cause_enum; */
{
    MMI_NO_CAUSE,
    MMI_GEN_CAUSE,
    MMI_WRONG_PASSWORD,
    MMI_RMMI_INVALID_CMD,
    MMI_TCM_INVALID_PARAMETER,
    MMI_TCM_NSAPI_NOT_IN_USE
} MMICAUSEENUM;
/* DOM-NOT_FOR_SDK-END */

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  ReadRecord
 * DESCRIPTION
 *  This function is to read record from NVRAM.
 * PARAMETERS
 *  nLID:          [IN]        NVRAM Data Item LID.
 *  nRecordId:     [IN]        Record index in file.
 *  pBuffer:       [OUT]       Output	Buffer in which data need to be retrieved, caller will allocate memory for this pointer.	
 *  nBufferSize:   [IN]        Size of record to be read it should be same as file record size.
 *  pError:        [OUT]       Error returned from NVRAM service.                                 
 * RETURNS
 *  Return the number of bytes actually read, or return -1 when read failed,  return 0 when FS check.
 * RETURN VALUES
 *  -1  :  Read NVRAM fail.
 *  0   :  File system is in checking drive process, read NVRAM will abort.
 *  Others  :  The number of bytes actually read.
 * 
 * EXAMPLE
 * <code>
 * S16 error;
 * U8 nvram_buf[NVRAM_ALM_ALARM_DATA_SIZE];
 * ReadRecord(NVRAM_EF_ALM_ALARM_DATA_LID, 1, (void*)nvram_buf, NVRAM_ALM_ALARM_DATA_SIZE, &error);
 * </code>
 *****************************************************************************/
extern S32 ReadRecordSlim(nvram_lid_enum nLID, U16 nRecordId, void *pBuffer, U16 nBufferSize);
extern S32 ReadRecord(nvram_lid_enum nLID, U16 nRecordId, void *pBuffer, U16 nBufferSize, S16 *pError);

/*****************************************************************************
 * FUNCTION
 *  ReadMultiRecord
 * DESCRIPTION
 *  The function is used to read multi-record from NVRAM.
 * PARAMETERS
 *  nLID:            [IN]        NVRAM data item LID.
 *  nRecordId:       [IN]        Record Index in file.
 *  pBuffer:         [OUT]       Buffer in which data need to be retrieved, caller will allocate memory for this pointer.	
 *  nBufferSize:     [IN]        Total size of records to be read, i.e. nBufferSize = (single file record size) * nRecordAmount.
 *  nRecordAmount:   [IN]        Amount of records to read.
 *  pError:          [OUT]       Output	Error returned from NVRAM service.
 * RETURNS
 *  Return the total number of bytes actually read, or return -1 when read failed, return 0 when FS check.
 * RETURN VALUES
 *  -1  :  Read NVRAM fail.
 *  0   :  File system is in checking drive process, read NVRAM will abort.
 *  Others  :   The total number of bytes actually read.
 *****************************************************************************/
extern S32 ReadMultiRecordSlim(nvram_lid_enum nLID, U16 nRecordId, void *pBuffer, U16 nBufferSize, U16 nRecordAmount);
extern S32 ReadMultiRecord(nvram_lid_enum nLID, U16 nRecordId, void *pBuffer, U16 nBufferSize, U16 nRecordAmount, S16 *pError);

/*****************************************************************************
 * FUNCTION
 *  WriteRecord
 * DESCRIPTION
 *  This function is to write record to NVRAM.
 * PARAMETERS
 *  nLID:            [IN]       NVRAM Data Item LID. 
 *  nRecordId:       [IN]       Record Index in file.
 *  pBuffer:         [IN]       Buffer containing the data to be written.
 *  nBufferSize:     [IN]       Size of record to be write it should be same as file record size.
 *  pError:          [OUT]      Error returned from NVRAM service.
 * RETURNS
 *  Return the number of bytes actually write, or return -1 when write failed.
 * RETURN VALUES
 *  -1  :  Write NVRAM fail.
 *  Others  :   The number of bytes actually write.
 *****************************************************************************/
extern S32 WriteRecordSlim(nvram_lid_enum nLID, U16 nRecordId, void *pBuffer, U16 nBufferSize);
extern S32 WriteRecord(nvram_lid_enum nLID, U16 nRecordId, void *pBuffer, U16 nBufferSize, S16 *pError);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_write_async_record
 * DESCRIPTION
 *  Send Write NVRAM request to NVRAM, this is async case, just send message,
 *  not wait for writing result. If you are care about the write result, you should register protocol event
 *  handler for MSG_ID_NVRAM_WRITE_CNF and the message struct is nvram_write_cnf_struct.
 * PARAMETERS
 *  nLID            [IN]        NVRAM Data Item ID
 *  nRecordId       [IN]        Record Index
 *  pBuffer         [IN]        Data to be writen
 *  nBufferSize     [IN]        Size of data to be writen
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_write_async_record(nvram_lid_enum nLID, U16 nRecordId, void *pBuffer, U16 nBufferSize);



/*****************************************************************************
 * FUNCTION
 *  ReadValue
 * DESCRIPTION
 *  This function for read 1, 2 or 8 bytes from MMI cache.
 * PARAMETERS
 *  nDataItemId:     [IN]         Small data Item Id.
 *  pBuffer:         [OUT]        Buffer in which data need to be retrieved, caller will allocate memory for this pointer.
 *  nDataType:       [IN]         Data type can be one ,two or eight bytes.
 *  pError:          [OUT]        Output	Error returned from NVRAM service.                               
 * RETURNS
 *  Return the number of bytes actually read, or return -1 when read failed.
 * RETURN VALUES
 *  -1 : Read NVRAM fail.
 *  Others : The number of bytes actually read, 1, 2 or 8 bytes.
 *
 * EXAMPLE
 * <code>
 * S16 local_nfo_id;
 * ReadValue(NVRAM_EBOOK_NFO_LID, (void*)&local_nfo_id, DS_SHORT, &error);
 * </code>
 *****************************************************************************/
extern S32 ReadValueSlim(U16 nDataItemId, void *pBuffer, U8 nDataType);
extern S32 ReadValue(U16 nDataItemId, void *pBuffer, U8 nDataType, S16 *pError);

/*****************************************************************************
 * FUNCTION
 *  WriteValue
 * DESCRIPTION
 *  This function for write 1, 2 or 8 bytes to NVRAM.
 * PARAMETERS
 *  nDataItemId:     [IN]        Small data Item Id.
 *  pBuffer:         [IN]        Buffer containing the data to be written.
 *  nDataType:       [IN]        Data type can be one ,two or eight byte.
 *  pError:          [OUT]       Error returned from NVRAM service.
 * RETURNS
 *  Return the number of bytes actually write, or return -1 when write failed.
 * RETURN VALUES
 *  -1 : Write NVRAM fail.
 *  Others : The number of bytes actually write, 1, 2 or 8bytes.
 *****************************************************************************/
extern S32 WriteValueSlim(U16 nDataItemId, void *pBuffer, U8 nDataType);
extern S32 WriteValue(U16 nDataItemId, void *pBuffer, U8 nDataType, S16 *pError);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  SetFlashNVRAMCatchData
 * DESCRIPTION
 *  This function is to set the flag if want to flash the 
 *  BYTE or SHORT or DOUBLE type of catch data into NVRAM.
 * PARAMETERS
 *  nDataType:                   [IN]     Data type can be one ,two or eight byte.
 *  l_DataWriteFlashFlag:        [IN]     Enable to flash into NVRAM or not.
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetFlashNVRAMCatchData(U8 nDataType, MMI_BOOL l_DataWriteFlashFlag);

/*****************************************************************************
 * FUNCTION
 *  SetFlashAllNVRAMCatchData
 * DESCRIPTION
 *  This function is used for set the flag if want to flash all the 
 *  BYTE, SHORT, and DOUBLE of catch datas into NVRAM.
 * PARAMETERS
 *  l_DataWriteFlashFlag:        [IN]  Enable to flash into NVRAM or not.
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetFlashAllNVRAMCatchData(MMI_BOOL l_DataWriteFlashFlag);

/*****************************************************************************
 * FUNCTION
 *  WriteFlashNVRAMCatchData
 * DESCRIPTION
 *  This function is to write the BYTE or SHORT or DOUBLE of catch data into NVRAM.
 * PARAMETERS
 *  nDataType:       [IN]      Data type can be one ,two or eight byte.
 * RETURNS
 *  Return the number of bytes actually write, or return -1 when write failed, 
 *  return 0 when not write back to NVRAM.
 * RETURN VALUES
 *  -1 : Write NVRAM fail.
 *  0 :  No need to write NVRAM.
 *  Others : The number of bytes actually write.
 *****************************************************************************/
extern S32 WriteFlashNVRAMCatchData(U8 nDataType);

/*****************************************************************************
 * FUNCTION
 *  WriteFlashAllNVRAMCatchData
 * DESCRIPTION
 *  This function is used for write all types of data into NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return the number of bytes actually write, or return -1 when write failed, 
 *  return 0 when no write back to NVRAM happen.
 * RETURN VALUES
 *  -1 :               Write Back Failed.
 *   0 :                No need to write NVRAM.
 *  Others : The number of bytes actually write.
 *****************************************************************************/
extern S32 WriteFlashAllNVRAMCatchData(void);

/*****************************************************************************
 * FUNCTION
 *  IsInNVRAMProcedure
 * DESCRIPTION
 *  This function is to check if in NVRAM procedure while loop procedure.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return MMI_TRUE, if in NVRAM while loop now; return MMI_FALSE, if not in NVRAM procedure. 
 *****************************************************************************/
extern MMI_BOOL IsInNVRAMProcedure(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_reset_record
 * DESCRIPTION
 *  This function is used to reset nvram record to default value.
 * PARAMETERS
 *  reset_category:            [IN]  NVRAM reset category,see nvram_reset_category_enum.
 *  app_id:                    [IN]  App id see enum nvram_restore_app_enum.
 *  lid:                       [IN]  NVRAM data item LID.
 *  rec_index:                 [IN]  Record Index in file.
 *  record_amount:             [IN]  Amount of records to read.
 * RETURNS
 *  If reset successfully, return 1, if fail, return 0.
 *
 * EXAMPLE
 * <code>
 * mmi_frm_reset_record(NVRAM_RESET_CERTAIN, app_id, 0, 0, 0);
 * </code>
 *****************************************************************************/
extern S32 mmi_frm_reset_record(U8 reset_category, U16 app_id, nvram_lid_enum lid, U16 rec_index, U16 record_amount);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_default_cache_value
 * DESCRIPTION
 *  Get nvram cache default value
 * PARAMETERS
 *  cache_type:    [IN]  Data type can be one ,two or eight byte.
 *  data_item_id:  [IN]  Small data Item Id.
 *  buffer_p:      [IN]  Buffer in which data need to be retrieved, caller will allocate memory for this pointer.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_get_default_cache_value(U8 cache_type, U16 data_item_id, U8 * buffer_p);
#endif /* MMI_FRM_NVRAM_GPROT_H */ 


