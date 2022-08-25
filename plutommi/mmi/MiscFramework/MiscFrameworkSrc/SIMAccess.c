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
 *  SIMAccess.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intended for the implementation of "SIM Access" feature.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
/* Write your #include header file here */

#include "MMI_include.h"
#include "SIMAccessGprot.h"
#include "ProtocolEvents.h"

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
/* Write your typedef here (enum, struct, ...) */

typedef struct
{
    U8 app_id;
    U8 type_id;
    U8 sim_id;
    FuncPtrSIMAccess read_access;
    FuncPtrSIMInfo read_info;
    U8 file_id;
    U16 para;
    U8 *data;
    U16 length;
    U8 *path;
} mmi_sim_access_struct;

typedef struct
{
    MMI_BOOL more_flag;
    U16 read_length;
} mmi_sim_access_read_struct;

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
/* Define your local variable here */
/* Local variable are those variable only be used within this .c file. */

static mmi_sim_access_struct g_mmi_access_list[MMI_SIM_ACCESS_MAX_COUNT];
static mmi_sim_access_read_struct g_mmi_access_read_process;
static U8 g_mmi_access_count = 0;

/* Declare your local function here */

static void mmi_sim_access_read_sim_req(void);
static U8 mmi_sim_access_read_sim_rsp(void *info);
static void mmi_sim_access_write_sim_req(void);
static U8 mmi_sim_access_write_sim_rsp(void *info);
static void mmi_sim_access_read_file_info_req(void);
static U8 mmi_sim_access_read_file_info_rsp(void *info);

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
/* Write your global variable here */
/* 
 * Global variable shall be declared in the XxxxProt.h (not XXXGprot.h),
 * it shall be accessible by files within the same module.
 */

mmi_sim_access_struct *const mmi_access_p = &g_mmi_access_list[0];

/***************************************************************************** 
 * Local Function
 *****************************************************************************/
/* Write your local function here */
/*
 * Local function can only be called within this .C file, it shall be declared as static.
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_sim_access_queue_push
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sim_access_queue_push(
                U8 app_id,
                U8 access_type,
                U8 sim_interface,
                FuncPtrSIMAccess read_callback,
                FuncPtrSIMInfo info_callback,
                U8 file_index,
                U16 access_para,
                U8 *access_data,
                U16 access_length,
                U8 *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_access_count < MMI_SIM_ACCESS_MAX_COUNT)
    {
        g_mmi_access_list[g_mmi_access_count].app_id = app_id;
        g_mmi_access_list[g_mmi_access_count].type_id = access_type;
        g_mmi_access_list[g_mmi_access_count].sim_id = sim_interface;
        g_mmi_access_list[g_mmi_access_count].read_access = read_callback;
        g_mmi_access_list[g_mmi_access_count].read_info = info_callback;
        g_mmi_access_list[g_mmi_access_count].file_id = file_index;
        g_mmi_access_list[g_mmi_access_count].para = access_para;
        g_mmi_access_list[g_mmi_access_count].data = access_data;
        g_mmi_access_list[g_mmi_access_count].length = access_length;
        g_mmi_access_list[g_mmi_access_count].path = file_path;
        g_mmi_access_count++;
    }

    if (g_mmi_access_count == 1)
    {
        if (g_mmi_access_list[0].type_id == MMI_SIM_ACCESS_READ)
        {
            if (g_mmi_access_list[0].length > 255)
            {
                g_mmi_access_read_process.more_flag = MMI_TRUE;
                g_mmi_access_read_process.read_length = 0;
            }
            mmi_sim_access_read_sim_req();
        }
        else if (g_mmi_access_list[0].type_id == MMI_SIM_ACCESS_WRITE)
        {
            mmi_sim_access_write_sim_req();
        }
        else if (g_mmi_access_list[0].type_id == MMI_SIM_ACCESS_INFO)
        {
            mmi_sim_access_read_file_info_req();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sim_access_queue_pop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sim_access_queue_pop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_mmi_access_count <= MMI_SIM_ACCESS_MAX_COUNT);
    if (g_mmi_access_count > 0 && !g_mmi_access_read_process.more_flag)
    {
        for (i = 0; i < g_mmi_access_count - 1; i++)
        {
            g_mmi_access_list[i].app_id = g_mmi_access_list[i + 1].app_id;
            g_mmi_access_list[i].type_id = g_mmi_access_list[i + 1].type_id;
            g_mmi_access_list[i].sim_id = g_mmi_access_list[i + 1].sim_id;
            g_mmi_access_list[i].read_access = g_mmi_access_list[i + 1].read_access;
            g_mmi_access_list[i].read_info = g_mmi_access_list[i + 1].read_info;
            g_mmi_access_list[i].file_id = g_mmi_access_list[i + 1].file_id;
            g_mmi_access_list[i].para = g_mmi_access_list[i + 1].para;
            g_mmi_access_list[i].data = g_mmi_access_list[i + 1].data;
            g_mmi_access_list[i].length = g_mmi_access_list[i + 1].length;
            g_mmi_access_list[i].path = g_mmi_access_list[i + 1].path;
        }
        g_mmi_access_count--;
    }

    if (g_mmi_access_count >= 1)
    {
        if (g_mmi_access_list[0].type_id == MMI_SIM_ACCESS_READ)
        {
            if (g_mmi_access_list[0].length > 255 && !g_mmi_access_read_process.more_flag)
            {
                g_mmi_access_read_process.more_flag = MMI_TRUE;
                g_mmi_access_read_process.read_length = 0;
            }
            mmi_sim_access_read_sim_req();
        }
        else if (g_mmi_access_list[0].type_id == MMI_SIM_ACCESS_WRITE)
        {
            mmi_sim_access_write_sim_req();
        }
        else if (g_mmi_access_list[0].type_id == MMI_SIM_ACCESS_INFO)
        {
            mmi_sim_access_read_file_info_req();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sim_access_reach_max_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_sim_access_reach_max_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_access_count >= MMI_SIM_ACCESS_MAX_COUNT)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sim_access_read_sim_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sim_access_read_sim_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_sim_req_struct *local_ptr;
    MYQUEUE msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_access_list[0].sim_id == SIM1)
    {
        mmi_frm_set_protocol_event_handler(PRT_MMI_SMU_READ_SIM_RSP, mmi_sim_access_read_sim_rsp, MMI_TRUE);
    }
#if (MMI_MAX_SIM_NUM >=2)
    else if (g_mmi_access_list[0].sim_id == SIM2)
    {
        mmi_frm_set_protocol_event_handler(PRT_MMI_SMU_READ_SIM_RSP, mmi_sim_access_read_sim_rsp, MMI_TRUE);
    }
#if (MMI_MAX_SIM_NUM >= 3) 
    else if (g_mmi_access_list[0].sim_id == SIM3)
    {
        mmi_frm_set_protocol_event_handler(PRT_MMI_SMU_READ_SIM_RSP, mmi_sim_access_read_sim_rsp, MMI_TRUE);
    }
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    else if (g_mmi_access_list[0].sim_id == SIM4)
    {
        mmi_frm_set_protocol_event_handler(PRT_MMI_SMU_READ_SIM_RSP, mmi_sim_access_read_sim_rsp, MMI_TRUE);
    }
#endif
#endif /* GEMINI  */

    local_ptr = OslConstructDataPtr(sizeof(mmi_smu_read_sim_req_struct));
    local_ptr->access_id = 0;
    local_ptr->file_idx = g_mmi_access_list[0].file_id;
    local_ptr->para = g_mmi_access_list[0].para;
    if (g_mmi_access_read_process.more_flag)
    {
        local_ptr->para = g_mmi_access_list[0].para + g_mmi_access_read_process.read_length;
        local_ptr->length =
            ((g_mmi_access_list[0].length - g_mmi_access_read_process.read_length) < 255)
            ? g_mmi_access_list[0].length - g_mmi_access_read_process.read_length
            : 255;
    }
    else
    {
        local_ptr->length = g_mmi_access_list[0].length;
    }
    if (g_mmi_access_list[0].path != NULL)
    {
        memcpy(local_ptr->path, g_mmi_access_list[0].path, 6);
    }
    else
    {
        memset(local_ptr->path, 0, 6);
    }

    msg.oslSrcId = MOD_MMI;
    if (g_mmi_access_list[0].sim_id == SIM1)
    {
        msg.oslDestId = MOD_L4C;
    }
#if (MMI_MAX_SIM_NUM >=2)
    else if (g_mmi_access_list[0].sim_id == SIM2)
    {
        msg.oslDestId = MOD_L4C_2;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (g_mmi_access_list[0].sim_id == SIM3)
    {
        msg.oslDestId = MOD_L4C_3;
    }
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    else if (g_mmi_access_list[0].sim_id == SIM4)
    {
        msg.oslDestId = MOD_L4C_4;
    }
#endif
#endif /* GEMINI */
    msg.oslMsgId = PRT_MMI_SMU_READ_SIM_REQ;
    msg.oslDataPtr = (oslParaType*) local_ptr;
    msg.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&msg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sim_access_read_sim_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_sim_access_read_sim_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_sim_rsp_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_smu_read_sim_rsp_struct*) info;

    if (local_ptr->access_id != 0)
    {
        /* SMS will take it */
        return MMI_FALSE;
    }

    if (g_mmi_access_read_process.more_flag)
    {
        memcpy(
            g_mmi_access_list[0].data + g_mmi_access_read_process.read_length,
            local_ptr->data,
            local_ptr->length);
        g_mmi_access_read_process.read_length += local_ptr->length;
        if (g_mmi_access_read_process.read_length == g_mmi_access_list[0].length)
        {
            g_mmi_access_read_process.more_flag = MMI_FALSE;
            g_mmi_access_list[0].read_access(SIM_CMD_SUCCESS, g_mmi_access_read_process.read_length);
        }
    }
    else
    {
        memcpy(g_mmi_access_list[0].data, local_ptr->data, local_ptr->length);
        if (local_ptr->result.flag == L4C_OK)
        {
            g_mmi_access_list[0].read_access(SIM_CMD_SUCCESS, (U16) local_ptr->length);
        }
        else
        {
            g_mmi_access_list[0].read_access((U16) local_ptr->result.cause, (U16) local_ptr->length);
        }
    }

    mmi_sim_access_queue_pop();
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sim_access_write_sim_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sim_access_write_sim_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_write_sim_req_struct *local_ptr;
    MYQUEUE msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_access_list[0].sim_id == SIM1)
    {
        mmi_frm_set_protocol_event_handler(MSG_ID_MMI_SMU_WRITE_SIM_RSP, mmi_sim_access_write_sim_rsp, MMI_TRUE);
    }
#if (MMI_MAX_SIM_NUM >=2)
    else if (g_mmi_access_list[0].sim_id == SIM2)
    {
        mmi_frm_set_protocol_event_handler(MSG_ID_MMI_SMU_WRITE_SIM_RSP, mmi_sim_access_write_sim_rsp, MMI_TRUE);
    }
#if (MMI_MAX_SIM_NUM >=3)
    else if (g_mmi_access_list[0].sim_id == SIM3)
    {
        mmi_frm_set_protocol_event_handler(MSG_ID_MMI_SMU_WRITE_SIM_RSP, mmi_sim_access_write_sim_rsp, MMI_TRUE);
    }
#endif
#if (MMI_MAX_SIM_NUM >=4)
    else if (g_mmi_access_list[0].sim_id == SIM4)
    {
        mmi_frm_set_protocol_event_handler(MSG_ID_MMI_SMU_WRITE_SIM_RSP, mmi_sim_access_write_sim_rsp, MMI_TRUE);
    }
#endif

#endif /* GEMINI */

    local_ptr = OslConstructDataPtr(sizeof(mmi_smu_write_sim_req_struct));
    local_ptr->access_id = 0;
    local_ptr->file_idx = g_mmi_access_list[0].file_id;
    local_ptr->para = (U8) g_mmi_access_list[0].para;
    if (g_mmi_access_list[0].length > 0)
    {
        memcpy(local_ptr->data, g_mmi_access_list[0].data, g_mmi_access_list[0].length);
    }
    local_ptr->length = g_mmi_access_list[0].length;
    if (g_mmi_access_list[0].path != NULL)
    {
        memcpy(local_ptr->path, g_mmi_access_list[0].path, 6);
    }
    else
    {
        memset(local_ptr->path, 0, 6);
    }

    msg.oslSrcId = MOD_MMI;
    if (g_mmi_access_list[0].sim_id == SIM1)
    {
        msg.oslDestId = MOD_L4C;
    }
#if (MMI_MAX_SIM_NUM >=2)
    else if (g_mmi_access_list[0].sim_id == SIM2)
    {
        msg.oslDestId = MOD_L4C_2;
    }
#if (MMI_MAX_SIM_NUM >= 3)
		else if (g_mmi_access_list[0].sim_id == SIM3)
		{
			msg.oslDestId = MOD_L4C_3;
		}
#endif
#if (MMI_MAX_SIM_NUM >= 4)
		else if (g_mmi_access_list[0].sim_id == SIM4)
		{
			msg.oslDestId = MOD_L4C_4;
		}
#endif
#endif /* GEMINI */


    msg.oslMsgId = MSG_ID_MMI_SMU_WRITE_SIM_REQ;
    msg.oslDataPtr = (oslParaType*) local_ptr;
    msg.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&msg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sim_access_write_sim_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_sim_access_write_sim_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_write_sim_rsp_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_smu_write_sim_rsp_struct*) info;

    if (local_ptr->access_id != 0)
    {
        /* SMS will take it */
        return MMI_FALSE;
    }

    if (g_mmi_access_list[0].read_access != NULL)
    {
        if (local_ptr->result)
        {
            g_mmi_access_list[0].read_access(SIM_CMD_SUCCESS, 0 /* Reserved */);
        }
        else
        {
            g_mmi_access_list[0].read_access(SIM_CMD_FAIL, 0 /* Reserved */);
        }
    }

    mmi_sim_access_queue_pop();
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sim_access_read_file_info_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sim_access_read_file_info_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_file_info_req_struct *local_ptr;
    MYQUEUE msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_access_list[0].sim_id == SIM1)
    {
        mmi_frm_set_protocol_event_handler(PRT_MMI_SMU_READ_FILE_INFO_RSP, mmi_sim_access_read_file_info_rsp, MMI_TRUE);
    }
#if (MMI_MAX_SIM_NUM >=2)
    else if (g_mmi_access_list[0].sim_id == SIM2)
    {
        mmi_frm_set_protocol_event_handler(PRT_MMI_SMU_READ_FILE_INFO_RSP, mmi_sim_access_read_file_info_rsp, MMI_TRUE);
    }
#if (MMI_MAX_SIM_NUM >=3)
    else if (g_mmi_access_list[0].sim_id == SIM3)
    {
        mmi_frm_set_protocol_event_handler(PRT_MMI_SMU_READ_FILE_INFO_RSP, mmi_sim_access_read_file_info_rsp, MMI_TRUE);
    }
#endif
#if (MMI_MAX_SIM_NUM >=4)
    else if (g_mmi_access_list[0].sim_id == SIM4)
    {
        mmi_frm_set_protocol_event_handler(PRT_MMI_SMU_READ_FILE_INFO_RSP, mmi_sim_access_read_file_info_rsp, MMI_TRUE);
    }
#endif
#endif /* GEMINI */

    local_ptr = OslConstructDataPtr(sizeof(mmi_smu_read_file_info_req_struct));
    local_ptr->access_id = 0;
    local_ptr->file_idx = g_mmi_access_list[0].file_id;
    if (g_mmi_access_list[0].path != NULL)
    {
        memcpy(local_ptr->path, g_mmi_access_list[0].path, 6);
    }
    else
    {
        memset(local_ptr->path, 0, 6);
    }

    msg.oslSrcId = MOD_MMI;
    if (g_mmi_access_list[0].sim_id == SIM1)
    {
        msg.oslDestId = MOD_L4C;
    }
#if (MMI_MAX_SIM_NUM >=2)
    else if (g_mmi_access_list[0].sim_id == SIM2)
    {
        msg.oslDestId = MOD_L4C_2;
    }
#if (MMI_MAX_SIM_NUM >= 3)
		else if (g_mmi_access_list[0].sim_id == SIM3)
		{
			msg.oslDestId = MOD_L4C_3;
		}
#endif
#if (MMI_MAX_SIM_NUM >= 4)
		else if (g_mmi_access_list[0].sim_id == SIM4)
		{
			msg.oslDestId = MOD_L4C_4;
		}
#endif
#endif /* GEMINI */


    msg.oslMsgId = PRT_MMI_SMU_READ_FILE_INFO_REQ;
    msg.oslDataPtr = (oslParaType*) local_ptr;
    msg.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&msg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sim_access_read_file_info_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_sim_access_read_file_info_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_file_info_rsp_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_smu_read_file_info_rsp_struct*) info;

    if (local_ptr->access_id != 0)
    {
        /* SMS will take it */
        return MMI_FALSE;
    }

    if (local_ptr->result.flag == L4C_OK)
    {
        g_mmi_access_list[0].read_info(SIM_CMD_SUCCESS, (U16) local_ptr->file_size, (U16) local_ptr->num_of_rec);
    }
    else
    {
        g_mmi_access_list[0].read_info((U16) local_ptr->result.cause, (U16) local_ptr->file_size, (U16) local_ptr->num_of_rec);
    }

    mmi_sim_access_queue_pop();
    return MMI_TRUE;
}

/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
/* Write your global function here */
/* 
 * Global functions shall be declared in XxxProt.h or XxxGprot.h.
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_sim_access_transparent_ef
 * DESCRIPTION
 *  This function is used to access a transparent EF.
 * PARAMETERS
 *  file_index      [IN]        EF index to access in "sim_common_enums.h"
 *  file_path       [IN]        EF path with null terminator if file_index is FILE_NONE
 *  app_id          [IN]        Application ID (MMIDataType.h)
 *  access_type     [IN]        Read or write
 *  access_offset   [IN]        Read/write offset from the beginning of the transparent EF
 *  access_length   [IN]        Read/write data length
 *  data_buffer     [IN]        Data buffer to keep read/write data
 *  buffer_length   [IN]        Data buffer length, must not be shorter than access_length.
 *  read_callback   [IN]        Callback to get data/error code
 *  sim_interface   [IN]        Gemini: specify access SIM1 or SIM2 (sim_common_enums.h)
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUE LIST
 *  MMI_TRUE        This request is accepted.
 *  MMI_FALSE       This request is rejected.
 *****************************************************************************/
MMI_BOOL mmi_sim_access_transparent_ef(
            U8 file_index,
            U8 *file_path,
            U8 app_id,
            U8 access_type,
            U16 access_offset,
            U16 access_length,
            U8 *data_buffer,
            U16 buffer_length,
            FuncPtrSIMAccess read_callback,
            U8 sim_interface
            )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((file_index != FILE_NONE && file_path == NULL) ||
               (file_index == FILE_NONE && file_path != NULL));
    MMI_ASSERT(access_type == MMI_SIM_ACCESS_READ || access_type == MMI_SIM_ACCESS_WRITE);
    MMI_ASSERT(access_length <= buffer_length);
    MMI_ASSERT(data_buffer != NULL);
    MMI_ASSERT(access_type == MMI_SIM_ACCESS_WRITE || read_callback != NULL);
#if (MMI_MAX_SIM_NUM >=2)
    MMI_ASSERT(sim_interface == SIM1 || sim_interface == SIM2);
#if (MMI_MAX_SIM_NUM >= 3)
	MMI_ASSERT(sim_interface == SIM1 || sim_interface == SIM2 ||sim_interface == SIM3);
#if (MMI_MAX_SIM_NUM >= 4)
	MMI_ASSERT(sim_interface == SIM1 || sim_interface == SIM2 ||sim_interface == SIM3 ||sim_interface == SIM4);
#endif
#endif
#else
    MMI_ASSERT(sim_interface == SIM1);
#endif


    if (mmi_sim_access_reach_max_count())
    {
        return MMI_FALSE;
    }

    mmi_sim_access_queue_push(
        app_id,
        access_type,
        sim_interface,
        read_callback,
        NULL,
        file_index,
        access_offset,
        data_buffer,
        access_length,
        file_path
        );

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sim_access_linear_fixed_ef
 * DESCRIPTION
 *  This function is used to access a linear fixed EF.
 * PARAMETERS
 *  file_index      [IN]        EF index to access in "sim_common_enums.h"
 *  file_path       [IN]        EF path with null terminator if file_index is FILE_NONE
 *  app_id          [IN]        Application ID (MMIDataType.h)
 *  access_type     [IN]        Read or write
 *  access_index    [IN]        Read/write index of all records
 *  access_size     [IN]        Read/write size of each record
 *  data_buffer     [IN]        Data buffer to keep read/write data
 *  buffer_length   [IN]        Data buffer length, must not be shorter than access_size.
 *  read_callback   [IN]        Callback to get data/error code
 *  sim_interface   [IN]        Gemini: specify access SIM1 or SIM2 (sim_common_enums.h)
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUE LIST
 *  MMI_TRUE        This request is accepted.
 *  MMI_FALSE       This request is rejected.
 *****************************************************************************/
MMI_BOOL mmi_sim_access_linear_fixed_ef(
            U8 file_index,
            U8 *file_path,
            U8 app_id,
            U8 access_type,
            U16 access_index,
            U16 access_size,
            U8 *data_buffer,
            U16 buffer_length,
            FuncPtrSIMAccess read_callback,
            U8 sim_interface
            )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((file_index != FILE_NONE && file_path == NULL) ||
               (file_index == FILE_NONE && file_path != NULL));
    MMI_ASSERT(access_type == MMI_SIM_ACCESS_READ || access_type == MMI_SIM_ACCESS_WRITE);
    MMI_ASSERT(access_size <= buffer_length);
    MMI_ASSERT(data_buffer != NULL);
    MMI_ASSERT(access_type == MMI_SIM_ACCESS_WRITE || read_callback != NULL);
#if (MMI_MAX_SIM_NUM >=2)
    MMI_ASSERT(sim_interface == SIM1 || sim_interface == SIM2);
#if (MMI_MAX_SIM_NUM >= 3)
	MMI_ASSERT(sim_interface == SIM1 || sim_interface == SIM2 ||sim_interface == SIM3);
#if (MMI_MAX_SIM_NUM >= 4)
	MMI_ASSERT(sim_interface == SIM1 || sim_interface == SIM2 ||sim_interface == SIM3 ||sim_interface == SIM4);
#endif
#endif
#else
    MMI_ASSERT(sim_interface == SIM1);
#endif

    if (mmi_sim_access_reach_max_count())
    {
        return MMI_FALSE;
    }

    mmi_sim_access_queue_push(
        app_id,
        access_type,
        sim_interface,
        read_callback,
        NULL,
        file_index,
        access_index,
        data_buffer,
        access_size,
        file_path
        );

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sim_access_file_info
 * DESCRIPTION
 *  This function is used to read EF info, including file size and record numbers.
 * PARAMETERS
 *  file_index      [IN]        EF index to access in "sim_common_enums.h"
 *  file_path       [IN]        EF path with null terminator if file_index is FILE_NONE
 *  app_id          [IN]        Application ID (MMIDataType.h)
 *  info_callback   [IN]        Please set a callback to get returned file info.
 *  sim_interface   [IN]        Gemini: specify access SIM1 or SIM2 (sim_common_enums.h)
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUE LIST
 *  MMI_TRUE        This request is accepted.
 *  MMI_FALSE       This request is rejected.
 *****************************************************************************/
MMI_BOOL mmi_sim_access_file_info(
            U8 file_index,
            U8 *file_path,
            U8 app_id,
            FuncPtrSIMInfo info_callback,
            U8 sim_interface
            )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((file_index != FILE_NONE && file_path == NULL) ||
               (file_index == FILE_NONE && file_path != NULL));
    MMI_ASSERT(info_callback != NULL);
#if (MMI_MAX_SIM_NUM >=2)
    MMI_ASSERT(sim_interface == SIM1 || sim_interface == SIM2);
#if (MMI_MAX_SIM_NUM >= 3)
    MMI_ASSERT(sim_interface == SIM1 || sim_interface == SIM2 ||sim_interface == SIM3);
#if (MMI_MAX_SIM_NUM >= 4)
    MMI_ASSERT(sim_interface == SIM1 || sim_interface == SIM2 ||sim_interface == SIM3 ||sim_interface == SIM4);
#endif
#endif
#else
    MMI_ASSERT(sim_interface == SIM1);
#endif

    if (mmi_sim_access_reach_max_count())
    {
        return MMI_FALSE;
    }

    mmi_sim_access_queue_push(
        app_id,
        MMI_SIM_ACCESS_INFO,
        sim_interface,
        NULL,
        info_callback,
        file_index,
        0,
        NULL,
        0,
        file_path
        );

    return MMI_TRUE;
}

