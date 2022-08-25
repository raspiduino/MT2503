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
 *  ImgViewerCacheCache.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Cache module of image viewer decoder.
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
 ****************************************************************************/

#include "ImgViewerCache.h"
#if defined(__MMI_IVF_CACHE_MGR__)
#include "Math.h"       /* sqrt */
#include "MMI_trc_Int.h"        /* MMI_ASSERT */
#include "gui.h"        /* gui timer */
#include "mmi_frm_events_gprot.h"       /* MMI_FRM_INIT_EVENT */
#include "DebugInitDef_Int.h"   /* MMI_TRACE */

#define __IVCMODULE__ "Mgr"

static void mmi_ivc_mgr_cell_init(mmi_ivc_cell_struct *cell);
static void mmi_ivc_mgr_cell_reset(mmi_ivc_cell_struct *cell, U32 type);
static void mmi_ivc_mgr_cell_update(mmi_ivc_mgr_cntx_struct *mgr, mmi_ivc_cell_struct *cell);

#ifdef __MMI_IVF_CACHE_L1__
#define MMI_IVC_MGR_IS_VALID_IDX(mgr, idx)  (mmi_ivc_mgr_l1_is_valid_dec_idx(&((mgr)->l1), idx))
#else /* __MMI_IVF_CACHE_L1__ */
#define mmi_ivc_mgr_l1_init(l1, runBufPtr, runBufSize)
#define mmi_ivc_mgr_l1_start_dec(l1)
#define mmi_ivc_mgr_l1_stop_dec(l1)
#define mmi_ivc_mgr_l1_remove_memory(l1, bufPtr)
#define mmi_ivc_mgr_l1_set_curr_idx(l1, idx)
#define mmi_ivc_mgr_l1_query_img(l1, idx, dstLyr)           NULL
#endif /* __MMI_IVF_CACHE_L1__ */

#if defined(__MMI_IVF_CACHE_DBC__)
#define MMI_IVC_MGR_IS_VALID_IDX(mgr, idx)                  MMI_TRUE
#define mmi_ivc_mgr_dbc_start_dec(dbc)                      mmi_ivc_mgr_cell_update(MMI_IVC_GET_MGR_FROM_DBC(dbc), (&(dbc)->cell))
#define mmi_ivc_mgr_dbc_stop_dec(dbc)
#else /* __MMI_IVF_CACHE_DBC__ */
#define mmi_ivc_mgr_dbc_start_dec(dbc)
#define mmi_ivc_mgr_dbc_stop_dec(dbc)
#define mmi_ivc_mgr_dbc_init(dbc)
#define mmi_ivc_mgr_dbc_remove_memory(dbc, bufPtr)
#define mmi_ivc_mgr_dbc_set_curr_idx(dbc, idx)
#endif /* __MMI_IVF_CACHE_DBC__ */

#if defined(__MMI_IVF_CACHE_DB__)
static void mmi_ivc_mgr_cell_dec_pre_cb(WCHAR *filepath, void *userData);
#else
#define mmi_ivc_mgr_cell_dec_pre_cb                             NULL
#endif

#if defined(__MMI_IVF_CACHE_DBC__)

#ifdef __MMI_AP_DCM_CAMIMGV__
#pragma arm section rodata = "DYNAMIC_CODE_CAMIMGV_RODATA",code = "DYNAMIC_CODE_CAMIMGV_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_dbc_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dbc             [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_mgr_dbc_init(mmi_ivc_mgr_dbc_cntx_struct *dbc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_MGR_DBC_INIT);
    mmi_ivc_mgr_cell_init(&dbc->cell);
    mmi_ivc_mgr_cell_reset(&dbc->cell, MMI_IVC_CELL_TYPE_DBC);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_dbc_add_memory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dbc         [?]         
 *  bufPtr      [IN]        
 *  bufSize     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_ivc_mgr_dbc_add_memory(mmi_ivc_mgr_dbc_cntx_struct *dbc, PU8 bufPtr, U32 bufSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == dbc->cell.bufPtr)
    {
        if (bufSize < MMI_IVC_FULL_SCR_BUF_SIZE)
        {
            count = 0;
        }
        else
        {
            dbc->cell.bufPtr = bufPtr;
            dbc->cell.allocBufPtr = bufPtr;
            dbc->cell.idx = MMI_IVC_GET_INS_FROM_MGR(MMI_IVC_GET_MGR_FROM_DBC(dbc))->currIdx;
        }
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_dbc_remove_memory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dbc         [?]         
 *  bufPtr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_mgr_dbc_remove_memory(mmi_ivc_mgr_dbc_cntx_struct *dbc, PU8 bufPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != dbc->cell.bufPtr && bufPtr == dbc->cell.allocBufPtr)
        mmi_ivc_mgr_cell_init(&dbc->cell);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_dbc_get_curr_img
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dbc     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ivc_cell_struct *mmi_ivc_mgr_dbc_get_curr_img(mmi_ivc_mgr_dbc_cntx_struct *dbc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_cell_struct *result = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != dbc->cell.bufPtr && MMI_IVC_CELL_STATE_INIT != MMI_IVC_CELL_STATE_GET(&dbc->cell))
    {
        result = &dbc->cell;
    }
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_MGR_DBC_GET_CURR_IMG, result);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_dbc_set_curr_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dbc     [?]         
 *  idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_mgr_dbc_set_curr_idx(mmi_ivc_mgr_dbc_cntx_struct *dbc, S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == dbc->cell.bufPtr || dbc->cell.idx == idx)
        return;
    mmi_ivc_mgr_cell_reset(&dbc->cell, MMI_IVC_CELL_TYPE_GET(&dbc->cell));
    dbc->cell.idx = idx;
    mmi_ivc_mgr_cell_update(MMI_IVC_GET_MGR_FROM_DBC(dbc), &dbc->cell);
}
#endif /* defined(__MMI_IVF_CACHE_DBC__) */ 

#if defined(__MMI_IVF_CACHE_L1__)


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_l1_dll_get_middle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  head        [?]     
 *  tail        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ivc_mgr_l1_node_struct *mmi_ivc_mgr_l1_dll_get_middle(
                                    mmi_ivc_mgr_l1_node_struct *head,
                                    mmi_ivc_mgr_l1_node_struct *tail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (head == tail)
        return head;
    while (head != tail && head->next != tail && tail->prev != head)
    {
        head = head->next;
        tail = tail->prev;
    }
    return head;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_l1_dll_plug_out
 * DESCRIPTION
 *  Only handle double link list, will not change the idx
 * PARAMETERS
 *  node        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_mgr_l1_dll_plug_out(mmi_ivc_mgr_l1_node_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != node->prev)
        node->prev->next = node->next;
    if (NULL != node->next)
        node->next->prev = node->prev;
    node->prev = node->next = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_l1_dll_plug_in
 * DESCRIPTION
 *  Only handle double link list and set the new node idx, will not change other node idx
 * PARAMETERS
 *  l1          [?]         
 *  node        [?]         
 *  base        [?]         
 *  isAfter     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_mgr_l1_dll_plug_in(
                mmi_ivc_mgr_l1_cntx_struct *l1,
                mmi_ivc_mgr_l1_node_struct *node,
                mmi_ivc_mgr_l1_node_struct *base,
                MMI_BOOL isAfter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 totalFileCount = MMI_IVC_GET_INS_FROM_MGR(MMI_IVC_GET_MGR_FROM_L1(l1))->count;
    S32 newIdx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == isAfter)
    {
        node->next = base->next;
        node->prev = base;
        base->next = node;
        newIdx = (base->cell.idx + 1) % totalFileCount;
    }
    else
    {
        node->prev = base->prev;
        node->next = base;
        base->prev = node;
        newIdx = (base->cell.idx - 1 + totalFileCount) % totalFileCount;
    }

    if (node->cell.idx != newIdx)
    {
        mmi_ivc_mgr_cell_reset(&node->cell, MMI_IVC_CELL_TYPE_L1);
        node->cell.idx = newIdx;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_l1_dll_get_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  node        [?]         
 *  head        [IN]        
 *  tail        [IN]        
 * RETURNS
 *  Return cell count
 *****************************************************************************/
static S32 mmi_ivc_mgr_l1_dll_get_info(
            mmi_ivc_mgr_l1_node_struct *node,
            mmi_ivc_mgr_l1_node_struct **head,
            mmi_ivc_mgr_l1_node_struct **tail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = 1;
    mmi_ivc_mgr_l1_node_struct *tempHead;
    mmi_ivc_mgr_l1_node_struct *tempTail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tempHead = tempTail = node;
    if (NULL == node)
        count = 0;

    while (NULL != tempHead && NULL != (tempHead)->prev)
    {
        count++;
        tempHead = (tempHead)->prev;
    }
    while (NULL != tempTail && NULL != (tempTail)->next)
    {
        count++;
        tempTail = (tempTail)->next;
    }

    if (NULL != head)
        *head = tempHead;
    if (NULL != tail)
        *tail = tempTail;

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_l1_malloc_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  l1      [?]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ivc_mgr_l1_node_struct *mmi_ivc_mgr_l1_malloc_node(mmi_ivc_mgr_l1_cntx_struct *l1)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_mgr_l1_node_struct *temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == l1->freeNodes)
        MMI_IVC_ASSERT(0);

    temp = l1->freeNodes;

    l1->freeNodes = l1->freeNodes->next;
    if (NULL != l1->freeNodes)
    {
        l1->freeNodes->prev = NULL;
    }

    temp->prev = temp->next = NULL;
    return temp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_l1_free_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  l1          [?]     
 *  node        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_mgr_l1_free_node(mmi_ivc_mgr_l1_cntx_struct *l1, mmi_ivc_mgr_l1_node_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node->prev = node->next = NULL;
    mmi_ivc_mgr_cell_init(&node->cell);
    if (NULL != l1->freeNodes)
    {
        node->next = l1->freeNodes;
        l1->freeNodes->prev = node;
    }
    l1->freeNodes = node;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_l1_dec
 * DESCRIPTION
 *  
 * PARAMETERS
 *  userData        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_mgr_l1_dec(void *userData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_mgr_l1_cntx_struct *l1 = (mmi_ivc_mgr_l1_cntx_struct*) userData;
    mmi_ivc_cell_struct *cell = NULL;
    mmi_ivc_mgr_l1_node_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer((FuncPtr) mmi_ivc_mgr_l1_dec);

    node = l1->curr;

    /* first search the next half list */
    while (NULL != node)
    {
        if (MMI_IVC_CELL_STATE_INIT == MMI_IVC_CELL_STATE_GET(&node->cell))
        {
            break;
        }
        node = node->next;
    }

    if (NULL == node)
    {
        node = l1->curr->prev;

        /* then search the prev half list */
        while (NULL != node)
        {
            if (MMI_IVC_CELL_STATE_INIT == MMI_IVC_CELL_STATE_GET(&node->cell))
            {
                break;
            }
            node = node->prev;
        }
    }

    if (NULL != node)
        cell = &node->cell;

    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_MGR_L1_DEC, cell);

    if (NULL != cell)
        mmi_ivc_mgr_cell_update(MMI_IVC_GET_MGR_FROM_L1(l1), cell);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_l1_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  l1              [?]         
 *  runBufPtr       [IN]        
 *  runBufSize      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_mgr_l1_init(mmi_ivc_mgr_l1_cntx_struct *l1, PU8 runBufPtr, U32 runBufSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_MGR_L1_INIT, runBufPtr, runBufSize);

    l1->freeNodes = (mmi_ivc_mgr_l1_node_struct*) runBufPtr;
    l1->nodeCount = runBufSize / MMI_IVC_L1_NODE_SIZE;
    l1->curr = NULL;

    /* init free nodes */
    for (i = 0; i < l1->nodeCount; i++)
    {
        mmi_ivc_mgr_cell_init(&(l1->freeNodes[i].cell));
        if (0 == i)
            l1->freeNodes[i].prev = NULL;
        else
            l1->freeNodes[i].prev = &l1->freeNodes[i - 1];

        if (i == l1->nodeCount - 1)
            l1->freeNodes[i].next = NULL;
        else
            l1->freeNodes[i].next = &l1->freeNodes[i + 1];
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_l1_start_dec
 * DESCRIPTION
 *  
 * PARAMETERS
 *  l1      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_mgr_l1_start_dec(mmi_ivc_mgr_l1_cntx_struct *l1)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_MGR_L1_START_DEC);
    if (NULL == l1->curr)
        return;
    gui_start_timer_ex(MMI_IVC_L1_DEC_CELL_TIMER_DURATION, mmi_ivc_mgr_l1_dec, (void*)l1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_l1_stop_dec
 * DESCRIPTION
 *  
 * PARAMETERS
 *  l1      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_mgr_l1_stop_dec(mmi_ivc_mgr_l1_cntx_struct *l1)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_MGR_L1_STOP_DEC);
    gui_cancel_timer((FuncPtr) mmi_ivc_mgr_l1_dec);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_l1_add_memory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  l1          [?]         
 *  bufPtr      [IN]        
 *  bufSize     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_ivc_mgr_l1_add_memory(mmi_ivc_mgr_l1_cntx_struct *l1, PU8 bufPtr, U32 bufSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = bufSize / MMI_IVC_FULL_SCR_BUF_SIZE;
    S32 i;
    S32 cellCount;
    MMI_BOOL forNext;
    S32 totalFileCount = MMI_IVC_GET_INS_FROM_MGR(MMI_IVC_GET_MGR_FROM_L1(l1))->count;
    mmi_ivc_mgr_l1_node_struct *head;
    mmi_ivc_mgr_l1_node_struct *tail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cellCount = mmi_ivc_mgr_l1_dll_get_info(l1->curr, &head, &tail);
    forNext = cellCount == 0 ? MMI_TRUE : (((cellCount - 1) % 2) == 0) ? MMI_TRUE : MMI_FALSE;

    /* Boundary check */
    count = cellCount + count;
    count = count > totalFileCount ? totalFileCount : count;
    count = count - cellCount;

    for (i = 0; i < count; i++)
    {
        mmi_ivc_mgr_l1_node_struct *newNode = mmi_ivc_mgr_l1_malloc_node(l1);

        mmi_ivc_mgr_cell_reset(&newNode->cell, MMI_IVC_CELL_TYPE_L1);
        newNode->cell.bufPtr = (bufPtr + (MMI_IVC_FULL_SCR_BUF_SIZE * i));
        newNode->cell.allocBufPtr = bufPtr;
        if (NULL == l1->curr)
        {
            l1->curr = newNode;
            l1->curr->cell.idx = MMI_IVC_GET_INS_FROM_MGR(MMI_IVC_GET_MGR_FROM_L1(l1))->currIdx;
            head = tail = l1->curr;
        }
        else
        {
            if (MMI_TRUE == forNext)
            {
                mmi_ivc_mgr_l1_dll_plug_in(l1, newNode, tail, MMI_TRUE);
                tail = newNode;
                forNext = MMI_FALSE;
            }
            else
            {
                mmi_ivc_mgr_l1_dll_plug_in(l1, newNode, head, MMI_FALSE);
                head = newNode;
                forNext = MMI_TRUE;
            }
        }
    }

    count = cellCount + count;

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_l1_remove_memory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  l1          [?]         
 *  bufPtr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_mgr_l1_remove_memory(mmi_ivc_mgr_l1_cntx_struct *l1, PU8 bufPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_mgr_l1_node_struct *head;
    mmi_ivc_mgr_l1_node_struct *tail;
    mmi_ivc_mgr_l1_node_struct *remove;
    mmi_ivc_mgr_l1_node_struct *temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == l1->curr)
        return;

    mmi_ivc_mgr_l1_dll_get_info(l1->curr, &head, NULL);
    while (NULL != head)
    {
        remove = head;
        head = head->next;
        if (bufPtr == remove->cell.allocBufPtr)
        {
            mmi_ivc_mgr_l1_dll_plug_out(remove);
            mmi_ivc_mgr_cell_reset(&remove->cell, MMI_IVC_CELL_TYPE_L1);
            mmi_ivc_mgr_l1_free_node(l1, remove);
        }
        else
            temp = remove;
    }

    mmi_ivc_mgr_l1_dll_get_info(temp, &head, &tail);
    l1->curr = mmi_ivc_mgr_l1_dll_get_middle(head, tail);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_l1_get_curr_img
 * DESCRIPTION
 *  
 * PARAMETERS
 *  l1      [?]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ivc_cell_struct *mmi_ivc_mgr_l1_get_curr_img(mmi_ivc_mgr_l1_cntx_struct *l1)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_cell_struct *result = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != l1->curr && MMI_IVC_CELL_STATE_INIT != MMI_IVC_CELL_STATE_GET(&l1->curr->cell))
        result = &l1->curr->cell;
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_MGR_L1_GET_CURR_IMG, result);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_l1_set_curr_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  l1      [?]         
 *  idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_mgr_l1_set_curr_idx(mmi_ivc_mgr_l1_cntx_struct *l1, S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 diff;
    S32 i;
    S32 cellCount;
    S32 totalFileCount = MMI_IVC_GET_INS_FROM_MGR(MMI_IVC_GET_MGR_FROM_L1(l1))->count;
    mmi_ivc_mgr_l1_node_struct  *head;
    mmi_ivc_mgr_l1_node_struct  *tail;
    mmi_ivc_mgr_l1_node_struct  *temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == l1->curr)
        return;

    cellCount = mmi_ivc_mgr_l1_dll_get_info(l1->curr, &head, &tail);

    {
        S32 ascDiff;
        S32 descDiff;

        /* Assume idx is bigger than currIdx, then calc the shortest step from currIdx to idx */
        ascDiff = idx - l1->curr->cell.idx;
        if (0 == ascDiff)
            return;

        descDiff = (totalFileCount - abs(ascDiff)) * ((-1) * (ascDiff / abs(ascDiff)));

        if (abs(ascDiff) <= abs(descDiff))
        {
            diff = ascDiff;
        }
        else
        {
            diff = descDiff;
        }
    }

    if (abs(diff) >= cellCount)
    {
        /* No cell could be reused.
           Set tail to be new head, to move before nodes after */
        mmi_ivc_mgr_cell_reset(&tail->cell, MMI_IVC_CELL_TYPE_L1);
        tail->cell.idx = (idx - ((cellCount - 1) / 2) + totalFileCount) % totalFileCount;
        /* To move head nodes to tail */
        diff = cellCount - 1;
    }

    if (diff < 0)
    {
        /* Move tail nodes to head */
        diff = diff * (-1);
        for (i = 0; i < diff; i++)
        {
            temp = tail->prev;
            mmi_ivc_mgr_l1_dll_plug_out(tail);
            mmi_ivc_mgr_l1_dll_plug_in(l1, tail, head, MMI_FALSE);
            head = tail;
            tail = temp;
        }
    }
    else
    {
        /* Move head nodes to tail */
        for (i = 0; i < diff; i++)
        {
            temp = head->next;
            mmi_ivc_mgr_l1_dll_plug_out(head);
            mmi_ivc_mgr_l1_dll_plug_in(l1, head, tail, MMI_TRUE);
            tail = head;
            head = temp;
        }
    }

    /* Set correct curr ptr */
    temp = mmi_ivc_mgr_l1_dll_get_middle(head, tail);
    MMI_IVC_ASSERT(idx == temp->cell.idx);
    l1->curr = temp;

    /* Here must not use directly call, cause mmi_ivc_mgr_set_curr_idx may do some check after this */
    gui_start_timer_ex(MMI_IVC_L1_DEC_CELL_TIMER_DURATION, mmi_ivc_mgr_l1_dec, (void*)l1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_l1_query_img
 * DESCRIPTION
 *  
 * PARAMETERS
 *  l1          [?]         
 *  idx         [IN]        
 *  dstLyr      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ivc_cell_struct *mmi_ivc_mgr_l1_query_img(mmi_ivc_mgr_l1_cntx_struct *l1, S32 idx, GDI_HANDLE dstLyr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_mgr_l1_node_struct *node;
    mmi_ivc_cell_struct *result = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ivc_mgr_l1_dll_get_info(l1->curr, &node, NULL);

    while (NULL != node)
    {
        if (idx == node->cell.idx)
        {
            break;
        }

        node = node->next;
    }

    if (NULL != node)
    {
        if (MMI_IVC_CELL_STATE_OK == MMI_IVC_CELL_STATE_GET(&node->cell))
        {
            result = &node->cell;
        }
    }

    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_MGR_L1_QUERY_IMG, idx, result);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_l1_is_valid_dec_idx
 * DESCRIPTION
 *
 * PARAMETERS
 *  l1          [?]
 *  idx         [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_ivc_mgr_l1_is_valid_dec_idx(mmi_ivc_mgr_l1_cntx_struct *l1, S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_mgr_l1_node_struct *head;
    mmi_ivc_mgr_l1_node_struct *tail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ivc_mgr_l1_dll_get_info(l1->curr, &head, &tail) > 0)
    {
        return (MMI_BOOL)(MMI_IVC_FILE_IDX_VALID(idx) && (head->cell.idx <= idx) && (idx <= tail->cell.idx));
    }
    return MMI_FALSE;
}
#endif /* defined(__MMI_IVF_CACHE_L1__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_cell_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cell        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_mgr_cell_init(mmi_ivc_cell_struct *cell)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(cell, 0, sizeof(mmi_ivc_cell_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_cell_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cell        [?]         
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_mgr_cell_reset(mmi_ivc_cell_struct *cell, U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cell->flag = type;
    MMI_IVC_FILE_IDX_RESET(cell->idx);
    cell->orgW = -1;
    cell->orgH = -1;
    cell->filename[0] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_cell_dec_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  userData        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_mgr_cell_dec_cb(S32 result, void *userData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_mgr_cntx_struct *mgr = (mmi_ivc_mgr_cntx_struct*) userData;
    mmi_ivc_event_struct evt;
    mmi_ivc_cell_struct *currDecCell = mgr->currDecCell;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(
        MMI_IVC_TRACE_GROUP,
        MMI_TRC_IVC_MGR_CELL_DEC_CB,
        result,
        mgr->currDecIdx,
        mgr->currDecCell->idx,
        mgr->currDecCell->flag);

    mgr->currDecCell = NULL;
    MMI_IVC_FILE_IDX_RESET(mgr->currDecIdx);

    MMI_FRM_INIT_EVENT(&evt, MMI_IVC_EVENT_DECODE);
    evt.data.decode.idx = currDecCell->idx;
    evt.data.decode.result = result;

    if (MMI_IVC_OK == result)
    {
        /* Set cell state flag */
        MMI_IVC_CELL_STATE_SET(currDecCell, MMI_IVC_CELL_STATE_OK);
        if (0 == (currDecCell->flag & MMI_IVC_CELL_FLAG_FROM_DB))
        {
            mmi_ivc_db_save(MMI_IVC_GET_INS_FROM_MGR(mgr), currDecCell);
        }
    }
    else
    {
        /* Set cell state flag */
        MMI_IVC_CELL_STATE_SET(currDecCell, MMI_IVC_CELL_STATE_ERR);
        evt.data.decode.result = MMI_IVC_ERR;
    }

    if (MMI_IVC_STATE_RUNNING == MMI_IVC_GET_INS_FROM_MGR(mgr)->state)
        mmi_ivc_adp_send_event(MMI_IVC_GET_INS_FROM_MGR(mgr), &evt);

    /* L1 need to continuously decode other images */
    mmi_ivc_mgr_l1_start_dec(&mgr->l1);
}

#if defined(__MMI_IVF_CACHE_DB__)


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_cell_dec_pre_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  userData        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_ivc_mgr_cell_dec_pre_cb(WCHAR *filepath, void *userData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_mgr_cntx_struct *mgr = (mmi_ivc_mgr_cntx_struct*) userData;
    S32 dbResult;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dbResult = mmi_ivc_db_get(MMI_IVC_GET_INS_FROM_MGR(mgr), mgr->currDecCell, filepath);
    if (MMI_IVC_OK == dbResult)
    {
        mgr->currDecCell->flag |= MMI_IVC_CELL_FLAG_FROM_DB;
    }

    MMI_IVC_TRACE(
        MMI_IVC_TRACE_GROUP,
        MMI_TRC_IVC_MGR_CELL_DEC_PRE_CB,
        dbResult,
        mgr->currDecIdx,
        mgr->currDecCell->idx,
        mgr->currDecCell->flag);
}
#endif /* defined(__MMI_IVF_CACHE_DB__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_cell_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mgr         [?]     
 *  cell        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ivc_mgr_cell_update(mmi_ivc_mgr_cntx_struct *mgr, mmi_ivc_cell_struct *cell)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_MGR_CELL_UPDATE, mgr->currDecIdx, cell->idx, cell->flag);

    if (MMI_IVC_CELL_STATE_INIT != MMI_IVC_CELL_STATE_GET(cell))
        /* MMI_IVC_CELL_STATE_OK and MMI_IVC_CELL_STATE_ERR mean decode done. */
        return;

    if (cell == mgr->currDecCell && cell->idx == mgr->currDecIdx)
        /* The cell is decoding. */
        return;

    if (NULL != mgr->currDecCell)
    {
        if (MMI_IVC_CELL_IS_L1(cell) &&                                     /* New request is a L1 cell */
            cell->idx != MMI_IVC_GET_INS_FROM_MGR(mgr)->currIdx)            /* New request is not current index */
            /*
             * Do not allow non-current decode to interrupt existing decode.
             * Cause only L1 mgr have this case, so add a condition as "MMI_IVC_CELL_IS_L1(cell)".
             */
            return;
    }

    mgr->currDecCell = cell;
    mgr->currDecIdx = cell->idx;
    mmi_ivc_adp_cell_dec_cell(
        MMI_IVC_GET_INS_FROM_MGR(mgr),
        cell,
        mmi_ivc_mgr_cell_dec_pre_cb,
        mmi_ivc_mgr_cell_dec_cb,
        (void*)mgr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_get_from_cell
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cell        [?]         
 *  dstLyr      [IN]        
 *  resizer     [IN]
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_ivc_mgr_get_from_cell(mmi_ivc_cell_struct *cell, GDI_HANDLE dstLyr, gdi_resizer_enum resizer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_MGR_GET_FROM_CELL, cell->idx, cell->flag, dstLyr);

    if (MMI_IVC_CELL_STATE_ERR == MMI_IVC_CELL_STATE_GET(cell))
        return MMI_IVC_ERR;

    if (GDI_LAYER_EMPTY_HANDLE != dstLyr)
    {
        S32 x, y, w, h;
        S32 bbw, bbh;

        mmi_ivc_adp_cell_create_layer(cell);
        gdi_layer_push_and_set_active(dstLyr);
        gdi_layer_get_dimension(&bbw, &bbh);
        gdi_util_fit_box(GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT, bbw, bbh, cell->orgW, cell->orgH, &x, &y, &w, &h);
        MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_MGR_GET_FROM_CELL_RESIZER, resizer, 0);IVC_PMD_START("ccl");
        gdi_bitblt_resized_with_resizer(
            cell->imgLyr,
            0,
            0,
            cell->resizedW - 1,
            cell->resizedH - 1,
            x,
            y,
            x + w - 1,
            y + h - 1,
            resizer);
        MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_MGR_GET_FROM_CELL_RESIZER, resizer, 1);IVC_PMD_STOP("ccl");
        gdi_layer_pop_and_restore_active();
        mmi_ivc_adp_cell_free_layer(cell);
    }
    return MMI_IVC_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ins             [?]         
 *  runBufPtr       [IN]        
 *  runBufSize      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_mgr_init(mmi_ivc_instance_struct *ins, PU8 runBufPtr, U32 runBufSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_mgr_cntx_struct *mgr = &ins->mgr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IVC_TRACE(MMI_IVC_TRACE_GROUP, MMI_TRC_IVC_MGR_INIT, runBufPtr, runBufSize);

    mgr->currDecCell = NULL;
    MMI_IVC_FILE_IDX_RESET(mgr->currDecIdx);

    mmi_ivc_mgr_l1_init(&mgr->l1, runBufPtr, runBufSize);
    mmi_ivc_mgr_dbc_init(&mgr->dbc);
    mmi_ivc_db_init(ins);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ins     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_mgr_start(mmi_ivc_instance_struct *ins)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ivc_db_start(ins);
    mmi_ivc_mgr_dbc_start_dec(&ins->mgr.dbc);
    mmi_ivc_mgr_l1_start_dec(&ins->mgr.l1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ins     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_mgr_stop(mmi_ivc_instance_struct *ins)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_mgr_cntx_struct *mgr = &ins->mgr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ivc_mgr_dbc_stop_dec(&ins->mgr.dbc);
    mmi_ivc_mgr_l1_stop_dec(&ins->mgr.l1);

    mgr->currDecCell = NULL;
    MMI_IVC_FILE_IDX_RESET(mgr->currDecIdx);

    mmi_ivc_db_stop(ins);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_add_memory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ins         [?]         
 *  bufPtr      [IN]        
 *  bufSize     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
extern S32 mmi_ivc_mgr_add_memory(mmi_ivc_instance_struct *ins, PU8 bufPtr, U32 bufSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IVF_CACHE_L1__)
    count = mmi_ivc_mgr_l1_add_memory(&ins->mgr.l1, bufPtr, bufSize);
#elif defined(__MMI_IVF_CACHE_DBC__)
    count = mmi_ivc_mgr_dbc_add_memory(&ins->mgr.dbc, bufPtr, bufSize);
#endif 

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_remove_memory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ins         [?]         
 *  bufPtr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_mgr_remove_memory(mmi_ivc_instance_struct *ins, PU8 bufPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ivc_mgr_l1_remove_memory(&ins->mgr.l1, bufPtr);
    mmi_ivc_mgr_dbc_remove_memory(&ins->mgr.dbc, bufPtr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_get_curr_img
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ins         [?]         
 *  dstLyr      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
extern S32 mmi_ivc_mgr_get_curr_img(mmi_ivc_instance_struct *ins, GDI_HANDLE dstLyr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_cell_struct *cell;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IVF_CACHE_L1__)
    cell = mmi_ivc_mgr_l1_get_curr_img(&ins->mgr.l1);
#endif 
#if defined(__MMI_IVF_CACHE_DBC__)
    cell = mmi_ivc_mgr_dbc_get_curr_img(&ins->mgr.dbc);
#endif 

    if (NULL != cell)
    {
        return mmi_ivc_mgr_get_from_cell(cell, dstLyr, GDI_RESIZER_SW_QUALITY_HIGH);
    }

    return MMI_IVC_DECODING;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_set_curr_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ins     [?]         
 *  idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_ivc_mgr_set_curr_idx(mmi_ivc_instance_struct *ins, U32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_mgr_cntx_struct *mgr = &ins->mgr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ivc_mgr_dbc_set_curr_idx(&mgr->dbc, idx);
    mmi_ivc_mgr_l1_set_curr_idx(&mgr->l1, idx);
    if (MMI_FALSE == MMI_IVC_MGR_IS_VALID_IDX(mgr, mgr->currDecIdx))
    {
        /*
         * The existing decode must be a valid index, if it is not, cancel it.
         * This action is only happens and useful on L1 cells.
         * mmi_ivc_mgr_l1_set_curr_idx must post invoke decode to avoid unexpected logic
         */
        mmi_ivc_adp_cell_cancel_dec(ins);
        MMI_IVC_FILE_IDX_RESET(ins->mgr.currDecIdx);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ivc_mgr_query_img
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ins         [?]         
 *  idx         [IN]        
 *  dstLyr      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
extern S32 mmi_ivc_mgr_query_img(mmi_ivc_instance_struct *ins, U32 idx, GDI_HANDLE dstLyr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ivc_cell_struct *cell = mmi_ivc_mgr_l1_query_img(&ins->mgr.l1, idx, dstLyr);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != cell)
    {
        return mmi_ivc_mgr_get_from_cell(cell, dstLyr, GDI_RESIZER_SW_QUALITY_HIGH);
    }
    return MMI_IVC_FAILE;
}
#ifdef __MMI_AP_DCM_CAMIMGV__
#pragma arm section rodata,code
#endif

#endif /* defined(__MMI_IVF_CACHE_MGR__) */ 

