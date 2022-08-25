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
*   VreDLTaskMgr.h
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   
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
*
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef MREDLTASKMGR_H
#define MREDLTASKMGR_H

#include "MRESrvDownloadGprot.h"

typedef enum
{
    EVT_ID_MRE_DLTM_LIST_CHANGE = AM_BASE + 1, 
    EVT_ID_MRE_DLTM_MAX
}mmi_mre_dltm_event_enum;


typedef enum {
    MRE_DLTM_STATE_WAITING,
    MRE_DLTM_STATE_DOWNLOAD,
    MRE_DLTM_STATE_PAUSE,
    MRE_DLTM_STATE_FAILURE,
    MRE_DLTM_STATE_FINISH,
}MRE_DLTM_STATUS;


typedef struct{
    S32 total_size;
    S32 download_size;
}mre_dltm_node_info;


typedef struct mre_dltm_node{
    MRE_DLTM_STATUS state;                  //download/wait/stop
    S32 err_code;
    S32 handle;                             //Download index
    S32 id;                                 //ID of app
    U16 filename[MAX_LEN_FILE_NAME + 1];  //Download filepath
    mre_dltm_node_info download_info;       //APP info of downlaod
    struct mre_dltm_node *next;             //next Task node
}mre_dltm_node;


typedef struct srv_mre_dltm_notify_struct
{
    MMI_EVT_PARAM_HEADER
        mre_dltm_node *changed_node;
    S32 result;
} srv_mre_dltm_notify_struct;




#define MRE_DLTM_MAX_NODE_COUNT 10



#define MRE_DLTM_RET_DONE           SRV_MRE_DL_DONE           
#define MRE_DLTM_RET_SUCCESS        SRV_MRE_DL_SUCCESS        
#define MRE_DLTM_RET_ERR            SRV_MRE_DL_ERR            
#define MRE_DLTM_RET_NET_ERR        SRV_MRE_DL_NET_ERR        
#define MRE_DLTM_RET_SAVE_ERR       SRV_MRE_DL_SAVE_ERR       
#define MRE_DLTM_RET_NOT_EXIST      SRV_MRE_DL_APP_NOT_EXIST  
#define MRE_DLTM_RET_SPACE_FULL     SRV_MRE_DL_SPACE_FULL     
#define MRE_DLTM_RET_OTHER_ERR      SRV_MRE_DL_OTHER_ERR      
#define MRE_DLTM_RET_FILE_NOT_EXIST SRV_MRE_DL_FILE_NOT_EXIST 
#define MRE_DLTM_RET_IO_ERROR       SRV_MRE_DL_IO_ERROR       
#define MRE_DLTM_RET_DOWNLOADING_ERR SRV_MRE_DL_ERR_DOWNLOADING

#define MRE_DLTM_RET_NOT_INIT           (-32)
#define MRE_DLTM_RET_REACH_MAX_COUNT    (-33)
#define MRE_DLTM_RET_MEM_NOT_ENOUGH     (-34)
#define MRE_DLTM_RET_APP_HAVE_EXIST     (-35)
#define MRE_DLTM_RET_HANDLE_ERR         (-36)
#define MRE_DLTM_RET_NODE_REMOVED            (-37)
#define MRE_DLTM_RET_NODE_MOVED         (-38)
#define MRE_DLTM_RET_NODE_PAUSED         (-39)
#define MRE_DLTM_RET_NODE_WAITING       (-40)


/**
* 任务列表文件名
*/
#define  MRE_DLTM_FILENAME                  "dltmlist.dat"

/**
* 任务列表缓存长度
*/
#define  MRE_DLTM_BUF_SIZE                  (20 * 1024)


extern S32 mre_dltm_init(void);
extern S32 mre_dltm_deinit(void);
extern S32 mre_dltm_add(S32 appid, U16* filepath);
extern S32 mre_dltm_start(S32 handle_id);
extern S32 mre_dltm_pause(S32 handle_id);
extern S32 mre_dltm_queue(S32 handle_id);
extern S32 mre_dltm_remove(S32 handle_id);
extern S32 mre_dltm_get_handle(S32 appid);
extern mre_dltm_node * mre_dltm_get_node(S32 handle_id);

extern mre_dltm_node * mre_dltm_get_first(void);
extern mre_dltm_node * mre_dltm_get_next(void);

extern S32 mre_dltm_get_state(void);




#undef MRE_DLTM_LOG_ON

#if defined(MRE_DLTM_LOG_ON)
#define MRE_DLTM_LOG vm_log_fatal
#else /* defined(MRE_DLTM_LOG_ON) */
#ifdef WIN32
#define MRE_DLTM_LOG 1 ? (void)0 : vm_log_fatal
#else
#define MRE_DLTM_LOG(...)
#endif 
#endif /* defined(MRE_DLTM_LOG_ON) */


#define MRE_DLTM_TRACE_ON

#if defined(MRE_DLTM_TRACE_ON)
#define MRE_DLTM_TRACE MMI_TRACE
#else /* defined(MRE_DLTM_LOG_ON) */
#ifdef WIN32
#define MRE_DLTM_TRACE 1 ? (void)0 : MMI_TRACE
#else
#define MRE_DLTM_TRACE(...)
#endif 
#endif /* defined(MRE_DLTM_LOG_ON) */

#define MRE_DLTM_TRACELINE          MRE_DLTM_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, TRC_MRE_DLTM_TRACELINE, __LINE__);
#define MRE_DLTM_CHECK_POINTER(x)   if(x == NULL){MRE_DLTM_LOG("Memory not available file=[%s]line=[%d]", __FILE__, __LINE__); return MRE_DLTM_RET_MEM_NOT_ENOUGH;}


#endif /* MREDLTASKMGR_H */
