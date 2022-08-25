/***********************************************************************
*   This software/firmware and related documentation ("MediaTek Software") 
*   are protected under relevant copyright laws. The information contained 
*   herein is confidential and proprietary to MediaTek Inc. and/or its licensors.
*
*   Without the prior written permission of MediaTek Inc. and/or its licensors, 
*   any reproduction, modification, use or disclosure of MediaTek Software, and 
*   information contained herein, in whole or in part, shall be strictly prohibited.
*
*   MediaTek Inc. (C) [2014]. All rights reserved.
*
*************************************************************************/ 
#ifndef __WEPODOWNLOAD_H__
#define __WEPODOWNLOAD_H__

#ifdef __GPS_EPO_DOWNLOAD__

#include "wps_struct.h"
#include "kal_public_defs.h"
#include "cbm_api.h"
#include "cbm_consts.h"
#include "wap_cmmn_utils.h"
#include "stack_ltlcom.h"
#include "syscomp_config.h"
#include "stdlib.h"  




#include "fs_errcode.h"
#include "fs_type.h"
#include "fs_func.h"


#include "mtk_gps.h"
#include "kal_trace.h"

#include "mtk_gps_type.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "soc_api.h"
#include "app_md5.h"
#include "ModeSwitchSrvGprot.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
#include <time.h>
#include "nvram_interface.h"
#include "nvram_data_items.h"
#include "gps_trc.h"
#include "tst_sap.h"
#include "app_datetime.h"

typedef enum {
    EPO_MODE_G,
    EPO_MODE_G_G,
    EPO_MODE_G_B,
    EPO_MODE_MAX
} epo_mode_enum;


typedef enum {
    STATE_EPO_3_DAY_DOWNLOAD,
    STATE_Q_EPO_DOWNLOAD,
    STATE_Q_AND_3_DAY_EPO_DOWNLOAD,
    STATE_EPO_IDLE
} epo_state_enum;


typedef enum {
    EPO_FILE_TYPE_3_DAY_EPO,
    EPO_FILE_TYPE_QEPO,
    EPO_FILE_TYPE_MAX
} epo_file_type;


typedef enum {
    EPO_CURR_TIMER_TYPE_NEXT_DOWNLOAD_TIMING,
    EPO_CURR_TIMER_TYPE_RETRY_DOWNLOAD_TIMING,
    EPO_CURR_TIMER_TYPE_DELAY_DOWNLOAD_TIMING,
    EPO_CURR_TIMER_TYPE_CANCLE_AIDING,
    EPO_CURR_TIMER_TYPE_DOWNLOAD_TIMEOUT,
    EPO_CURR_TIMER_TYPE_MAX
} epo_timer_type;

typedef enum {
    EPO_DOWNLOAD_ERROR_TYPE_GET_HOSTNAME_FAIL,
    EPO_DOWNLOAD_ERROR_TYPE_SOCKET_CREATE_FAIL,
    EPO_DOWNLOAD_ERROR_TYPE_CONNECTION_BROKEN,
    EPO_DOWNLOAD_ERROR_TYPE_CONNECTION_TIMEOUT,
    EPO_DOWNLOAD_ERROR_TYPE_NO_ENOUGH_SPACE,
    EPO_DOWNLOAD_ERROR_TYPE_FILE_CHECKSUM_ERROR,
    EPO_DOWNLOAD_ERROR_TYPE_FILE_OPERATE_ERROR,
    EPO_DOWNLOAD_ERROR_TYPE_DURING_DOWNLOAD,
    EPO_DOWNLOAD_ERROR_TYPE_MAX
} epo_download_error_enum;

#define EPO_DOWNLOAD_SUCCESS 0
#define EPO_DOWNLOAD_ERROR_MULTI_DOWNLOAD_REQUEST -1
#define EPO_DOWNLOAD_ERROR_CONNECTION_ERROR -2
#if defined(__GPS_SUPPORT__) && defined(__TCPIP__)
#define GPS_EPO_DOWNLOAD
#endif

#ifndef GPS_EPO_DOWNLOAD
#err
#endif

typedef void (*epo_download_notify_f)(kal_int32 epo_type, kal_int32 result);

#define EPO_G_G_3_DAY_SIZE 48384
#define EPO_G_G_Q_SIZE 4032

#define EPO_DEFAULT 0
#define EPO_MAX_CHUNK 2
#define EPO_EXPIRED_TIME 23

#define EPO_RECORD_SIZE     72
#define EPO_SV_NUMBER       (32 + 24)

#define EPO_3_DAY_RETRY_TIME_BASE(X) (((1 << (X)) > 8 ? 12 : (1 << (X)))*5*60*1000)



extern kal_uint32 app_gettime(kal_uint32 *t_loc);

extern void applib_md5_init(applib_md5_ctx *mdContext);
extern void applib_md5_update(applib_md5_ctx *mdContext, const kal_uint8 *inBuf, kal_uint32 inLen);
extern void applib_md5_final(kal_uint8 hash[], applib_md5_ctx *mdContext);

void epo_connectivty_message_handler(ilm_struct *ilm_ptr);
void epo_init(kal_uint32 account_id, kal_int32 trunk_num, char* epo_server_name, char* query_string);
kal_bool epo_aiding(kal_uint32 chip_gps_hours);
kal_uint32* epo_get_single_sv_data(kal_int32 num_sv);
void epo_aiding_cancle();
void epo_download_3_day();
void epo_qepo_download();
void epo_config(kal_bool disable_auto_download, kal_bool disable_download_retry, kal_bool disable_qepo_download, epo_download_notify_f notify_f);

#endif
#endif


