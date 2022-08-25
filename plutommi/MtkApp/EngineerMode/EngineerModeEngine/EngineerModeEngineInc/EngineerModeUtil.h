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
 *  EngineerModeUtil.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Engineer mode util header file.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_EM_UTIL_H
#define MMI_EM_UTIL_H

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "AlertScreen.h"
#include "InlineCuiGprot.h"
#include "mmi_cb_mgr_gprot.h"

#ifdef __TCPIP__
#include "Soc_api.h"
#include "EngineerModeSocketDemoApp.h"
#endif /* __TCPIP__ */ 

/***************************************************************************** 
 * Define
 *****************************************************************************/
#if (defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__) && defined(__MMI_SLIM_ENGINEER_MODE__) && defined(COSMOS_SHOW_EM_DCM))
#ifndef COSMOS_EM_INTERNAL_DCM
#define COSMOS_EM_INTERNAL_DCM
#endif
#endif  /* defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__) && defined(__MMI_SLIM_ENGINEER_MODE__) */

#if (defined (__DCM_WITH_COMPRESSION_MMI_AP__) && defined(__MTK_TARGET__))
#ifndef PLUTO_EM_INTERNAL_DCM
#define PLUTO_EM_INTERNAL_DCM
#endif
#endif /* defined (__DCM_WITH_COMPRESSION_MMI_AP__) && defined(__MTK_TARGET__) */
#if (defined(COSMOS_EM_INTERNAL_DCM))
#define COSMOS_EM_DCM_TIMERID           1001
#define COSMOS_EM_DCM_TIMERDURATION     1
#endif

#define EM_IS_SET(b, a)       (((b) & (0x1 << (a))) >> (a))
#define EM_STATE_SET(b, a)    ((b) |= (0x1 << (a)))
#define EM_STATE_UNSET(b, a)  ((b) &= ~(0x1 << (a)))
#define EM_STATE_TOGGLE(b, a) ((b) ^= (0x1 << (a)))

#define MMI_EM_DISPLAY_BUF_MAX_LEN 80
#define MMI_EM_CONSTRUCT_MSG_DATA(type) (type*)OslConstructDataPtr(sizeof(type))

/* EM ASM*/
#define MMI_EM_MALLOC(size) mmi_em_comm_mem_alloc(size)
#define MMI_EM_FREE(p)      mmi_em_comm_mem_free(p)

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
#define MMI_EM_DEF_ASM_FUNC(_func_name)  \
    void mmi_em_##_func_name##_free_cntx(void);  \
    MMI_BOOL mmi_em_##_func_name##_stop_hdlr(void);  \
    void mmi_em_##_func_name##_init_cntx(void);  
        

 #define MMI_EM_INIT_ASM(_func_name, _ptr, _size)                                 \
    void mmi_em_##_func_name##_free_cntx(void)                         \
    {                                                                    \
        if (!_ptr)                                                        \
        {                                                                \
            return;                                                      \
        }                                                                \
                                                                         \
        MMI_EM_FREE(_ptr);                                               \
    	_ptr = NULL;                                                     \
    }                                                                    \
                                                                         \
    MMI_BOOL mmi_em_##_func_name##_stop_hdlr(void)                       \
    {                                                                    \
        extern MMI_ID mmi_em_get_root_group();                           \
        MMI_ID em_root_group_id = mmi_em_get_root_group();               \
                                                                         \
        if (em_root_group_id)                                            \
            mmi_frm_group_close(em_root_group_id);                       \
        mmi_em_##_func_name##_free_cntx();                               \
        return MMI_TRUE;                                                 \
    }                                                                    \
                                                                         \
    void mmi_em_##_func_name##_init_cntx(void)                    \
    {                                                                    \
        MMI_EM_REG_STOP_FUNC(mmi_em_##_func_name##_stop_hdlr);           \
    	_ptr = MMI_EM_MALLOC(_size);                                     \
    	memset(_ptr, 0X0, _size);                                        \
    }                                                                 
 
#define MMI_EM_ASM_INIT_FUNC(_func_name) mmi_em_##_func_name##_init_cntx()
#define MMI_EM_ASM_FREE_FUNC(_func_name) mmi_em_##_func_name##_free_cntx()
#define MMI_EM_ASM_STOP_FUNC(_func_name) mmi_em_##_func_name##_stop_hdlr

/***************************************************************************** 
 * Global Variable 
 *****************************************************************************/
extern U8 currentHighlightIndex;
extern MMI_ID g_em_root_group_id;

/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
extern void SetHighlightIndex(S32 nIndex);

extern void EngineerModeSuccessRebootNotice(U16 stringId);

extern void WriteTestResultToNVRAM(void);

extern void WriteCurrentTimeToNVRAM(void);

extern void ReadSettingsFromNVRAM(void);

extern void ReadTestResultFromNVRAM(void);

extern void ReadTimeFromNVRAM(void);

extern void EngineerModeSendMsg(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr);

extern void EngineerModeSendMsg_Ext(U16 msg_id, U16 dest_mod_id, void *local_param_ptr, void *peer_buf_ptr);

extern MMI_BOOL mmi_em_device_is_use_usb_as_uart_port(void);

extern void EngineerModeSetSleepModeReq(U8 index);

extern void EngineerModeSetSleepModeRes(void *inMsg);

extern MMI_BOOL mmi_em_is_in_call(void);

#if defined(__FLIGHT_MODE_SUPPORT__) && defined(__MMI_TELEPHONY_SUPPORT__)
extern void mmi_em_dualmode_enter_flight_mode(FuncPtr callback);
#endif

extern void mmi_em_shutdown(void);

extern void mmi_em_shutdown_exit_system(void);

extern void mmi_em_display_notify_popup(MMI_BOOL result);

extern void mmi_em_success_popup(void);

extern void mmi_em_fail_popup(void);

extern void mmi_em_popup_by_str(MMI_ID str_id, mmi_event_notify_enum event_type);

extern void mmi_em_display_confirm(MMI_STR_ID title_id, MMI_ID group_id, mmi_event_notify_enum event_type, mmi_proc_func callback);

extern void mmi_em_display_confirm_by_str(WCHAR* title, MMI_ID group_id, mmi_event_notify_enum event_type, mmi_proc_func callback);

extern void mmi_em_display_confirm_by_type(MMI_STR_ID title_id, MMI_ID group_id, mmi_confirm_type_enum type, mmi_event_notify_enum event_type, mmi_proc_func callback);

extern void mmi_em_popup(MMI_ID gid, MMI_ID title_id, mmi_event_notify_enum event_type);

extern MMI_ID mmi_em_get_main_menu_id(void);

extern void mmi_em_set_main_menu_id(MMI_ID menu_id);

/* Screen Level Nofity */
extern void mmi_em_scr_level_notify(U32 cur_flag, MMI_ID cur_id, U32 parent_flag, MMI_ID parent_id);

extern void mmi_em_set_menu_list_items_title(mmi_id menu_group_id, U16 temp_str_id);

extern void mmi_em_entry_dualmode_switch_progress(void);

extern void mmi_em_close_dualmode_switch_progress(void);

extern void mmi_em_fresh_active_scrn(void);

extern MMI_BOOL mmi_em_ctrl_sim_is_available(mmi_sim_enum sim_id);

extern void mmi_em_common_set_left_softkey(U32 item);

extern U32 mmi_em_itoa(S32 i, S32 base, WCHAR *buf);


#if (defined(PLUTO_EM_INTERNAL_DCM) || defined(COSMOS_EM_INTERNAL_DCM))
extern void DeinitEngineerEvent(void);
#endif /* (defined(PLUTO_EM_INTERNAL_DCM) || defined(COSMOS_EM_INTERNAL_DCM)) */

#ifdef COSMOS_EM_INTERNAL_DCM 
extern void mmi_em_send_dcm_unload_process(void);
#endif /* COSMOS_EM_INTERNAL_DCM */



#if defined(PLUTO_EM_INTERNAL_DCM)
#define MMI_EM_DCM_LOAD_INTERNAL()    mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_EM)
#elif defined(COSMOS_EM_INTERNAL_DCM)
#define MMI_EM_DCM_LOAD_INTERNAL()  if(DCM_Isloaded(DYNAMIC_CODE_COMPRESS_COSMOS_EM)== KAL_FALSE) \
                         { \
                               DCM_Load(DYNAMIC_CODE_COMPRESS_COSMOS_EM, 0,0); \
                         }
#else
#define MMI_EM_DCM_LOAD_INTERNAL()  
#endif /* PLUTO_EM_INTERNAL_DCM */


#if defined(PLUTO_EM_INTERNAL_DCM)
extern MMI_BOOL mmi_frm_app_is_launched(MMI_ID app_id);
#define MMI_EM_DCM_SEND_UNLOAD_INTERNAL()   if(MMI_FALSE == mmi_frm_app_is_launched(g_em_root_group_id)) \
                                  { \
                                      mmi_ap_send_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_EM); \
                                  }
#elif defined(COSMOS_EM_INTERNAL_DCM)
#define MMI_EM_DCM_SEND_UNLOAD_INTERNAL()    if(DCM_Isloaded(DYNAMIC_CODE_COMPRESS_COSMOS_EM)== KAL_TRUE) \
                                  { \
                                      DCM_Unload(DYNAMIC_CODE_COMPRESS_COSMOS_EM); \
                                  }
#else
#define MMI_EM_DCM_SEND_UNLOAD_INTERNAL()  
#endif /* PLUTO_EM_INTERNAL_DCM */


#if defined(PLUTO_EM_INTERNAL_DCM)
#define MMI_EM_DCM_POST_UNLOAD_INTERNAL()   DeinitEngineerEvent(); \
                                            mmi_ap_post_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_EM)
#elif defined(COSMOS_EM_INTERNAL_DCM)
#define MMI_EM_DCM_POST_UNLOAD_INTERNAL()   DeinitEngineerEvent(); \
                                            StartTimer(COSMOS_EM_DCM_TIMERID, COSMOS_EM_DCM_TIMERDURATION, mmi_em_send_dcm_unload_process)
#else
#define MMI_EM_DCM_POST_UNLOAD_INTERNAL()  
#endif /* PLUTO_EM_INTERNAL_DCM */


#define MMI_EM_DCM_LOAD()           MMI_EM_DCM_LOAD_INTERNAL()
#define MMI_EM_DCM_SEND_UNLOAD()    MMI_EM_DCM_SEND_UNLOAD_INTERNAL()
#define MMI_EM_DCM_POST_UNLOAD()    MMI_EM_DCM_POST_UNLOAD_INTERNAL()


#endif /* MMI_EM_UTIL_H */ 

