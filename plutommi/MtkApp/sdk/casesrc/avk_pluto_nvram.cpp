/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 * avk_pluto_nvram.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implement the function to test pluto nvram
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/
extern "C"
{
#include "mmi_frm_nvram_gprot.h"
#include "common_nvram_editor_data_item.h"
#include "nvram_common_defs.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_cache_table.h"
#include "nvram_struct.h"
#include "nvram_interface.h"
#include "kal_public_api.h"
}

/****************************************************************************
 * Define
 ****************************************************************************/
#define AVK_PLUTO_NVRAM_TEST_REC_LID NVRAM_EF_MMI_CACHE_BYTE_KEY_LID
#define AVK_PLUTO_NVRAM_TEST_REC_SIZE NVRAM_MMI_CACHE_BYTE_KEY_SIZE

#define AVK_PLUTO_NVRAM_TEST_MULTI_REC_LID NVRAM_EF_PHB_LID
#define AVK_PLUTO_NVRAM_TEST_MULTI_REC_SIZE NVRAM_EF_PHB_SIZE
#define AVK_PLUTO_NVRAM_TEST_MULTI_REC_TOTAL 2
#define AVK_PLUTO_NVRAM_TEST_MULTI_REC_TOTAL_SIZE (AVK_PLUTO_NVRAM_TEST_MULTI_REC_SIZE * AVK_PLUTO_NVRAM_TEST_MULTI_REC_TOTAL)

#define AVK_PLUTO_NVRAM_TEST_TYPE_MAX_SIZE DS_DOUBLE
#define AVK_PLUTO_NVRAM_TEST_DATA_VAL 65
#define AVK_PLUTO_NVRAM_TEST_VAL_INDX_BASE 3
#define AVK_PLUTO_NVRAM_TEST_VAL_COUNT 3

typedef struct
{
    U8 buff_backup[AVK_PLUTO_NVRAM_TEST_REC_SIZE];
}avk_pluto_nvram_context;

static avk_pluto_nvram_context g_avk_pluto_nvram_cntx;

/*****************************************************************************
 * Declaration                                                      
 *****************************************************************************/
static U8 avk_pluto_nvram_async_write_handler(void *write_cnf);

/*****************************************************************************
 * Static Function                                                      
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  avk_pluto_nvram_async_write_handler
 * DESCRIPTION
 *  handler for async write response
 * PARAMETERS
 *  write_cnf : [IN]  nvram write response
 * RETURNS
 *  0 : for protocal event, to diliver msg for other listener
 *  1 : stop diliver the msg for other listener
 *****************************************************************************/
static U8 avk_pluto_nvram_async_write_handler(void *write_cnf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_write_cnf_struct *nvram_write_cnf;
    S16 error;
    S32 ret, i;
    U8 buff[AVK_PLUTO_NVRAM_TEST_REC_SIZE];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_write_cnf = (nvram_write_cnf_struct *)write_cnf;
    if (nvram_write_cnf->file_idx == AVK_PLUTO_NVRAM_TEST_REC_LID)
    { 
        mmi_frm_clear_protocol_event_handler(MSG_ID_NVRAM_WRITE_CNF, avk_pluto_nvram_async_write_handler);
        MMI_ASSERT(nvram_write_cnf->result == NVRAM_IO_ERRNO_OK);
        memset(buff, AVK_PLUTO_NVRAM_TEST_DATA_VAL + 10, AVK_PLUTO_NVRAM_TEST_REC_SIZE);
        ret = ReadRecord(AVK_PLUTO_NVRAM_TEST_REC_LID, 1, buff, AVK_PLUTO_NVRAM_TEST_REC_SIZE, &error);
        MMI_ASSERT((ret == AVK_PLUTO_NVRAM_TEST_REC_SIZE) && (error == NVRAM_READ_SUCCESS));
        for (i = 0; i < AVK_PLUTO_NVRAM_TEST_REC_SIZE; i++)
        {
            MMI_ASSERT(buff[i] == AVK_PLUTO_NVRAM_TEST_DATA_VAL);
        }
        ret = WriteRecord(AVK_PLUTO_NVRAM_TEST_REC_LID, 1, g_avk_pluto_nvram_cntx.buff_backup, AVK_PLUTO_NVRAM_TEST_REC_SIZE, &error);
        MMI_ASSERT((ret == AVK_PLUTO_NVRAM_TEST_REC_SIZE) && (error == NVRAM_WRITE_SUCCESS));
        AVK_CASE_RESULT(MMI_TRUE);
        AVK_ASYN_DONE();
        return 1;
    }
    return 0;
}


/*****************************************************************************
 * Extern Global Function                                                      
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  avk_pluto_nvram_test_access_record
 * DESCRIPTION
 *  test case of access nvram record; include ReadRecord and WriteRecord
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_PLUTO_NVRAM_TEST_ACCESS_RECORD, AVK_PLUTO_NVRAM)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S32 ret, i;
    U8 buff[AVK_PLUTO_NVRAM_TEST_REC_SIZE] = {0};
    U8 buff_backup[AVK_PLUTO_NVRAM_TEST_REC_SIZE] = {0};
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Try to reserve the data, but can not make sure if read operation is correct */
    ret = ReadRecord(AVK_PLUTO_NVRAM_TEST_REC_LID, 1, buff, AVK_PLUTO_NVRAM_TEST_REC_SIZE, &error);
    MMI_ASSERT((ret == AVK_PLUTO_NVRAM_TEST_REC_SIZE) && (memcmp(buff, buff_backup, AVK_PLUTO_NVRAM_TEST_REC_SIZE) != 0) && (error == NVRAM_READ_SUCCESS));
    memcpy(buff_backup, buff, AVK_PLUTO_NVRAM_TEST_REC_SIZE);

    /* test if read and write operation is correct */
    memset(buff, AVK_PLUTO_NVRAM_TEST_DATA_VAL, AVK_PLUTO_NVRAM_TEST_REC_SIZE);
    ret = WriteRecord(AVK_PLUTO_NVRAM_TEST_REC_LID, 1, buff, AVK_PLUTO_NVRAM_TEST_REC_SIZE, &error);
    MMI_ASSERT((ret == AVK_PLUTO_NVRAM_TEST_REC_SIZE) && (error == NVRAM_WRITE_SUCCESS));
    memset(buff, AVK_PLUTO_NVRAM_TEST_DATA_VAL + 10, sizeof(buff));
    ret = ReadRecord(AVK_PLUTO_NVRAM_TEST_REC_LID, 1, buff, AVK_PLUTO_NVRAM_TEST_REC_SIZE, &error);
    MMI_ASSERT((ret == AVK_PLUTO_NVRAM_TEST_REC_SIZE) && (memcmp(buff, buff_backup, AVK_PLUTO_NVRAM_TEST_REC_SIZE) != 0) && (error == NVRAM_READ_SUCCESS));
    for (i = 0; i < AVK_PLUTO_NVRAM_TEST_REC_SIZE; i++)
    {
        MMI_ASSERT(buff[i] == AVK_PLUTO_NVRAM_TEST_DATA_VAL);
    }

    /*
     * if above case pass, We can confirm read and write operation is correct 
     * then restore the original record data
     */
    ret = WriteRecord(AVK_PLUTO_NVRAM_TEST_REC_LID, 1, buff_backup, AVK_PLUTO_NVRAM_TEST_REC_SIZE, &error);
    MMI_ASSERT((ret == AVK_PLUTO_NVRAM_TEST_REC_SIZE) && (error == NVRAM_WRITE_SUCCESS));
    AVK_CASE_RESULT(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_nvram_test_access_value
 * DESCRIPTION
 *  test case of access mmi cache value; include ReadValue and WriteValue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_PLUTO_NVRAM_TEST_ACCESS_VALUE, AVK_PLUTO_NVRAM)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S32 ret, i, j;
    U16 cache_id;
    U8 buff[AVK_PLUTO_NVRAM_TEST_TYPE_MAX_SIZE];
    U8 buff_backup[AVK_PLUTO_NVRAM_TEST_TYPE_MAX_SIZE];
    U8 test_type_table[] = {DS_BYTE, DS_SHORT, DS_DOUBLE};
    const kal_uint16 *test_cache_id_table[] = {
        MMI_CACHE_BYTE_ENUM_TABLE, 
        MMI_CACHE_SHORT_ENUM_TABLE,
        MMI_CACHE_DOUBLE_ENUM_TABLE};
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sizeof(test_type_table) / sizeof(U8); i++)
    {
        /* firstly backup the value */
        cache_id = (U16)test_cache_id_table[i][AVK_PLUTO_NVRAM_TEST_VAL_INDX_BASE];
        ret = ReadValue(cache_id, buff_backup, test_type_table[i], &error);
        MMI_ASSERT((ret > 0) && (error == NVRAM_READ_SUCCESS));

        /* test correctness of read and write operation */
        memset(buff, AVK_PLUTO_NVRAM_TEST_DATA_VAL, test_type_table[i]);
        ret = WriteValue(cache_id, buff, test_type_table[i], &error);
        MMI_ASSERT((ret > 0) && (error == NVRAM_WRITE_SUCCESS));
        memset(buff, AVK_PLUTO_NVRAM_TEST_DATA_VAL + 10, test_type_table[i]);
        ret = ReadValue(cache_id, buff, test_type_table[i], &error);
        MMI_ASSERT((ret > 0) && (error == NVRAM_READ_SUCCESS));
        for (j = 0; j < test_type_table[i]; j++)
        {
            MMI_ASSERT(buff[j] == AVK_PLUTO_NVRAM_TEST_DATA_VAL);
        }
        /* restore original value */
        ret = WriteValue(cache_id, buff_backup, test_type_table[i], &error);
        MMI_ASSERT((ret > 0) && (error == NVRAM_WRITE_SUCCESS));
    }
    AVK_CASE_RESULT(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_nvram_test_multi_access_record
 * DESCRIPTION
 *  test case of access multi record
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_PLUTO_NVRAM_TEST_MULTI_ACCESS_RECORD, AVK_PLUTO_NVRAM)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S32 ret, i;
    U8 buff[AVK_PLUTO_NVRAM_TEST_MULTI_REC_TOTAL_SIZE] = {0};
    U8 buff_backup[AVK_PLUTO_NVRAM_TEST_MULTI_REC_TOTAL_SIZE] = {0};
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Try to reserve the data, but can not make sure if read operation is correct */
    ret = ReadMultiRecord(AVK_PLUTO_NVRAM_TEST_MULTI_REC_LID, 
            1, 
            buff_backup, 
            AVK_PLUTO_NVRAM_TEST_MULTI_REC_TOTAL_SIZE, 
            AVK_PLUTO_NVRAM_TEST_MULTI_REC_TOTAL,
            &error);
    MMI_ASSERT((ret == AVK_PLUTO_NVRAM_TEST_MULTI_REC_TOTAL_SIZE) && (error == NVRAM_READ_SUCCESS));

    /* test if read and write operation is correct */
    memset(buff, AVK_PLUTO_NVRAM_TEST_DATA_VAL, AVK_PLUTO_NVRAM_TEST_MULTI_REC_TOTAL_SIZE);
    for (i = 0; i < AVK_PLUTO_NVRAM_TEST_MULTI_REC_TOTAL; i++)
    {
        ret = WriteRecord(AVK_PLUTO_NVRAM_TEST_MULTI_REC_LID, 
                1 + i, 
                buff + i * AVK_PLUTO_NVRAM_TEST_MULTI_REC_SIZE, 
                AVK_PLUTO_NVRAM_TEST_MULTI_REC_SIZE, 
                &error);
        MMI_ASSERT((ret == AVK_PLUTO_NVRAM_TEST_MULTI_REC_SIZE) && (error == NVRAM_WRITE_SUCCESS));
    }
    memset(buff, AVK_PLUTO_NVRAM_TEST_DATA_VAL + 10, AVK_PLUTO_NVRAM_TEST_MULTI_REC_TOTAL_SIZE);
    ret = ReadMultiRecord(AVK_PLUTO_NVRAM_TEST_MULTI_REC_LID, 
            1, 
            buff, 
            AVK_PLUTO_NVRAM_TEST_MULTI_REC_TOTAL_SIZE, 
            AVK_PLUTO_NVRAM_TEST_MULTI_REC_TOTAL,
            &error);
    MMI_ASSERT((ret == AVK_PLUTO_NVRAM_TEST_MULTI_REC_TOTAL_SIZE) && (error == NVRAM_READ_SUCCESS));
    for (i = 0; i < AVK_PLUTO_NVRAM_TEST_MULTI_REC_TOTAL_SIZE; i++)
    {
        MMI_ASSERT(buff[i] == AVK_PLUTO_NVRAM_TEST_DATA_VAL);
    }

    /*
     * if above case pass, We can confirm read and write operation is correct 
     * then restore the original record data
     */
    for (i = 0; i < AVK_PLUTO_NVRAM_TEST_MULTI_REC_TOTAL; i++)
    {
        ret = WriteRecord(AVK_PLUTO_NVRAM_TEST_MULTI_REC_LID, 
                1 + i, 
                buff_backup + i * AVK_PLUTO_NVRAM_TEST_MULTI_REC_SIZE, 
                AVK_PLUTO_NVRAM_TEST_MULTI_REC_SIZE, 
                &error);
        MMI_ASSERT((ret == AVK_PLUTO_NVRAM_TEST_MULTI_REC_SIZE) && (error == NVRAM_WRITE_SUCCESS));
    }
    AVK_CASE_RESULT(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_nvram_test_aync_write_record
 * DESCRIPTION
 *  test case of async write record
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_ASYN_CASE(AVK_PLUTO_NVRAM_TEST_ASYNC_WRITE_RECORD, AVK_PLUTO_NVRAM)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S32 ret;
    U8 buff[AVK_PLUTO_NVRAM_TEST_REC_SIZE];
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = ReadRecord(AVK_PLUTO_NVRAM_TEST_REC_LID,
            1, 
            g_avk_pluto_nvram_cntx.buff_backup, 
            AVK_PLUTO_NVRAM_TEST_REC_SIZE, 
            &error);
    MMI_ASSERT((ret == AVK_PLUTO_NVRAM_TEST_REC_SIZE) && (error == NVRAM_READ_SUCCESS));
    mmi_frm_set_protocol_event_handler(
        MSG_ID_NVRAM_WRITE_CNF, 
        avk_pluto_nvram_async_write_handler, 
        MMI_TRUE);
    memset(buff, AVK_PLUTO_NVRAM_TEST_DATA_VAL, AVK_PLUTO_NVRAM_TEST_REC_SIZE);
    mmi_frm_write_async_record(AVK_PLUTO_NVRAM_TEST_REC_LID, 1, buff, AVK_PLUTO_NVRAM_TEST_REC_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_nvram_test_cache_batch_flush
 * DESCRIPTION
 *  test case of batch write value to cache, then flush to nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_PLUTO_NVRAM_TEST_CACHE_BATCH_FLUSH, AVK_PLUTO_NVRAM)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S32 ret, i, j;
    U16 cache_id;
    U8 test_type_table[] = {DS_BYTE, DS_SHORT, DS_DOUBLE};
    const kal_uint16 *test_cache_id_table[] = {
        MMI_CACHE_BYTE_ENUM_TABLE, 
        MMI_CACHE_SHORT_ENUM_TABLE,
        MMI_CACHE_DOUBLE_ENUM_TABLE};
    U8 type_buff[AVK_PLUTO_NVRAM_TEST_TYPE_MAX_SIZE * AVK_PLUTO_NVRAM_TEST_VAL_COUNT];
    U8 type_buff_backup[AVK_PLUTO_NVRAM_TEST_TYPE_MAX_SIZE * AVK_PLUTO_NVRAM_TEST_VAL_COUNT];
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* First for each type cache respectively, batch write */
    for (i = 0; i < sizeof(test_type_table) / sizeof(U8); i++)
    {
        for (j = 0; j < AVK_PLUTO_NVRAM_TEST_VAL_COUNT; j++)
        {
            cache_id = (U16)test_cache_id_table[i][AVK_PLUTO_NVRAM_TEST_VAL_INDX_BASE + j];
            ret = ReadValue(cache_id, type_buff_backup + j * test_type_table[i], test_type_table[i], &error);
            MMI_ASSERT((ret == test_type_table[i]) && (error == NVRAM_READ_SUCCESS));
        }

        SetFlashNVRAMCatchData(test_type_table[i], MMI_TRUE);
        memset(type_buff, AVK_PLUTO_NVRAM_TEST_DATA_VAL, test_type_table[i] * AVK_PLUTO_NVRAM_TEST_VAL_COUNT);

        /* multi write value to cache, not directly to nvram */
        for (j = 0; j < AVK_PLUTO_NVRAM_TEST_VAL_COUNT; j++)
        {
            cache_id = (U16)test_cache_id_table[i][AVK_PLUTO_NVRAM_TEST_VAL_INDX_BASE + j];
            ret = WriteValue(cache_id, type_buff + j * test_type_table[i], test_type_table[i], &error);
            MMI_ASSERT((ret == test_type_table[i]) && (error == NVRAM_WRITE_SUCCESS));
        }
        /* flush the cache to nvram */
        WriteFlashNVRAMCatchData(test_type_table[i]);

        memset(type_buff, AVK_PLUTO_NVRAM_TEST_DATA_VAL + 10, test_type_table[i] * AVK_PLUTO_NVRAM_TEST_VAL_COUNT);
        /* confirm the write operation */
        for (j = 0; j < AVK_PLUTO_NVRAM_TEST_VAL_COUNT; j++)
        {
            cache_id = (U16)test_cache_id_table[i][AVK_PLUTO_NVRAM_TEST_VAL_INDX_BASE + j];
            ret = ReadValue(cache_id, type_buff + j * test_type_table[i], test_type_table[i], &error);
            MMI_ASSERT((ret == test_type_table[i]) && (error == NVRAM_READ_SUCCESS));
        }

        for (j = 0; j < test_type_table[i] * AVK_PLUTO_NVRAM_TEST_VAL_COUNT; j++)
        {
            MMI_ASSERT(type_buff[j] == AVK_PLUTO_NVRAM_TEST_DATA_VAL);
        }

        /* restore original value  */
        SetFlashNVRAMCatchData(test_type_table[i], MMI_TRUE);
        for (j = 0; j < AVK_PLUTO_NVRAM_TEST_VAL_COUNT; j++)
        {
            cache_id = (U16)test_cache_id_table[i][AVK_PLUTO_NVRAM_TEST_VAL_INDX_BASE + j];
            ret = WriteValue(cache_id, type_buff_backup + j * test_type_table[i], test_type_table[i], &error);
            MMI_ASSERT((ret == test_type_table[i]) && (error == NVRAM_WRITE_SUCCESS));
        }
        WriteFlashNVRAMCatchData(test_type_table[i]);
    }

    /* accross type cache, batch write */
    for (i = 0; i < sizeof(test_type_table) / sizeof(U8); i++)
    {
        cache_id = (U16)test_cache_id_table[i][AVK_PLUTO_NVRAM_TEST_VAL_INDX_BASE];
        ret = ReadValue(cache_id, type_buff_backup + i * AVK_PLUTO_NVRAM_TEST_TYPE_MAX_SIZE, test_type_table[i], &error);
        MMI_ASSERT((ret == test_type_table[i]) && (error == NVRAM_READ_SUCCESS));
    }
    SetFlashAllNVRAMCatchData(MMI_TRUE);
    memset(type_buff, AVK_PLUTO_NVRAM_TEST_DATA_VAL, sizeof(type_buff));

    for (i = 0; i < sizeof(test_type_table) / sizeof(U8); i++)
    {
        cache_id = (U16)test_cache_id_table[i][AVK_PLUTO_NVRAM_TEST_VAL_INDX_BASE];
        ret = WriteValue(cache_id, type_buff + i * AVK_PLUTO_NVRAM_TEST_TYPE_MAX_SIZE, test_type_table[i], &error);
        MMI_ASSERT((ret == test_type_table[i]) && (error == NVRAM_WRITE_SUCCESS));
    }
    WriteFlashAllNVRAMCatchData();
    memset(type_buff, AVK_PLUTO_NVRAM_TEST_DATA_VAL + 10, sizeof(type_buff));

    for (i = 0; i < sizeof(test_type_table) / sizeof(U8); i++)
    {
        cache_id = (U16)test_cache_id_table[i][AVK_PLUTO_NVRAM_TEST_VAL_INDX_BASE];
        ret = ReadValue(cache_id, type_buff + i * AVK_PLUTO_NVRAM_TEST_TYPE_MAX_SIZE, test_type_table[i], &error);
        MMI_ASSERT((ret == test_type_table[i]) && (error == NVRAM_READ_SUCCESS));
    }

    for (i = 0; i < sizeof(test_type_table) / sizeof(U8); i++)
    {
        for (j = 0; j < test_type_table[i]; j++)
        {
            MMI_ASSERT(type_buff[i * AVK_PLUTO_NVRAM_TEST_TYPE_MAX_SIZE + j] == AVK_PLUTO_NVRAM_TEST_DATA_VAL);
        }
    }

    SetFlashAllNVRAMCatchData(MMI_TRUE);
    for (i = 0; i < sizeof(test_type_table) / sizeof(U8); i++)
    {
        cache_id = (U16)test_cache_id_table[i][AVK_PLUTO_NVRAM_TEST_VAL_INDX_BASE];
        ret = WriteValue(cache_id, type_buff_backup+ i * AVK_PLUTO_NVRAM_TEST_TYPE_MAX_SIZE, test_type_table[i], &error);
        MMI_ASSERT((ret == test_type_table[i]) && (error == NVRAM_WRITE_SUCCESS));
    }
    WriteFlashAllNVRAMCatchData();
    AVK_CASE_RESULT(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_nvram_test_reset_rec
 * DESCRIPTION
 *  test case of reset record
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_PLUTO_NVRAM_TEST_RESET_REC, AVK_PLUTO_NVRAM)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S32 ret, i;
    kal_uint8 *dft_ptr;
    U8 buff[AVK_PLUTO_NVRAM_TEST_REC_SIZE];
    U8 buff_backup[AVK_PLUTO_NVRAM_TEST_REC_SIZE];
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = ReadRecord(AVK_PLUTO_NVRAM_TEST_REC_LID, 1, buff_backup, AVK_PLUTO_NVRAM_TEST_REC_SIZE, &error);
    MMI_ASSERT(ret == AVK_PLUTO_NVRAM_TEST_REC_SIZE && error == NVRAM_READ_SUCCESS);
    
    ret = mmi_frm_reset_record(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, AVK_PLUTO_NVRAM_TEST_REC_LID, 1, 1);
    MMI_ASSERT(ret > 0);

    /* check reset operation correctness */
    MMI_ASSERT(nvram_get_default_value(AVK_PLUTO_NVRAM_TEST_REC_LID, 1, &dft_ptr) == NVRAM_DEFAULT_VALUE_POINT);
    ret = ReadRecord(AVK_PLUTO_NVRAM_TEST_REC_LID, 1, buff, AVK_PLUTO_NVRAM_TEST_REC_SIZE, &error);
    MMI_ASSERT(ret == AVK_PLUTO_NVRAM_TEST_REC_SIZE && error == NVRAM_READ_SUCCESS);
    for (i = 0; i < AVK_PLUTO_NVRAM_TEST_REC_SIZE; i++)
    {
        MMI_ASSERT(buff[i] == dft_ptr[i]);
    }

    /* restore original data */
    ret = WriteRecord(AVK_PLUTO_NVRAM_TEST_REC_LID, 1, buff_backup, AVK_PLUTO_NVRAM_TEST_REC_SIZE, &error);
    MMI_ASSERT(ret == AVK_PLUTO_NVRAM_TEST_REC_SIZE && error == NVRAM_WRITE_SUCCESS);
    AVK_CASE_RESULT(MMI_TRUE);
}

