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
 *   ResgenLogCAPI.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    Resgen Log API header for C language source
 *
 * Author:
 * -------
 * -------
 *
*==============================================================================
 *                 HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifndef __REGEN_LOG_CAPI_H__
#define __REGEN_LOG_CAPI_H__

#include <stdio.h>
#include <stdarg.h>
#include "ResgenLogConfig.h"

#ifdef RESLOG_SIMPLE_IMPLEMENTATION
// The following macro only supported in GCC

#define RES_LOG_D(tag, format, args...) resgen_log(RES_LOG_LEVEL_DEBUG, tag, format  , ##args)
#define RES_LOG_V(tag, format, args...) resgen_log(RES_LOG_LEVEL_VERBOSE, tag, format , ##args)
#define RES_LOG_W(tag, format, args...) resgen_log(RES_LOG_LEVEL_WARN,tag, format , ##args)
#define RES_LOG_E(tag, format, args...) resgen_log(RES_LOG_LEVEL_ERR, tag, format  , ##args)

#define RES_WLOG_D(tag, format, args...) resgen_wlog(RES_LOG_LEVEL_DEBUG, tag, format, ##args)
#define RES_WLOG_V(tag, format, args...) resgen_wlog(RES_LOG_LEVEL_VERBOSE, tag,format , ##args)
#define RES_WLOG_E(tag, format, args...) resgen_wlog(RES_LOG_LEVEL_ERR, tag, format, ##args)
#define RES_WLOG_W(tag, format, args...) resgen_wlog(RES_LOG_LEVEL_WARN, tag, format, ##args)

#else

#define RES_LOG_PENDING_FATAL(tag, msg,detail,suggestion) reslog_adaptor_fatal_error_pending_log(RES_LOG_LEVEL_ERR, tag, msg, detail,suggestion)
#define RES_WLOG_PENDING_FATAL(tag, msg,detail,suggestion) reslog_adaptor_fatal_error_pending_wlog(RES_LOG_LEVEL_ERR, tag,msg, detail, suggestion)

#define RES_LOG_D(tag, format, args...) reslog_adaptor_log(RES_LOG_LEVEL_DEBUG, tag, format  , ##args)
#define RES_LOG_V(tag, format, args...) reslog_adaptor_log(RES_LOG_LEVEL_VERBOSE, tag, format , ##args)
#define RES_LOG_W(tag, format, args...) reslog_adaptor_log(RES_LOG_LEVEL_WARN,tag, format , ##args)
#define RES_LOG_E(tag, format, args...) reslog_adaptor_log(RES_LOG_LEVEL_ERR, tag, format  , ##args)

#define RES_WLOG_D(tag, format, args...) reslog_adaptor_wlog(RES_LOG_LEVEL_DEBUG, tag, format, ##args)
#define RES_WLOG_V(tag, format, args...) reslog_adaptor_wlog(RES_LOG_LEVEL_VERBOSE, tag,format , ##args)
#define RES_WLOG_E(tag, format, args...) reslog_adaptor_wlog(RES_LOG_LEVEL_ERR, tag, format, ##args)
#define RES_WLOG_W(tag, format, args...) reslog_adaptor_wlog(RES_LOG_LEVEL_WARN, tag, format, ##args)

#endif//RESLOG_SIMPLE_IMPLEMENTATION


#if defined __cplusplus
extern "C" {
#endif
// Don't using resgen_log and resgen_wlog directly. please use RES_LOG and RES_WLOG APIs.
#ifdef RESLOG_SIMPLE_IMPLEMENTATION
    void resgen_log( const int level, const char *tag, const char *fmt,...);
    void resgen_wlog(const int level, const char *tag, const wchar_t *fmt,...);
    void resgen_log_set_max_level(int level);
    void resgen_logger_start();
    void resgen_logger_stop();
#endif //RESLOG_SIMPLE_IMPLEMENTATION

    void reslog_adaptor_set_max_level(int level);
    void reslog_adaptor_fatal_error_pending_wlog(const int level, const char* tag, const wchar_t * msg, const wchar_t *detail, const wchar_t *sugestion);
    void reslog_adaptor_fatal_error_pending_log(const int level, const char* tag, const char * msg, const char *detail, const char *sugestion);
    int  reslog_adaptor_has_pending_fatal_error();
    void reslog_adaptor_flush_pending_fatal_error();
    void reslog_adaptor_log(const int level, const char *tag, const char *fmt,...);
    void reslog_adaptor_wlog(const int level, const char *tag, const wchar_t *fmt,...);
    void reslog_adaptor_start_service();
    void reslog_adaptor_stop_service();

#if defined __cplusplus
}
#endif

#endif //__REGEN_LOG_CAPI_H__
