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
 *
 * Project:
 * --------
 *	 Maui
 *
 * Description:
 * ------------
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 11 23 2010 cm.huang
 * removed!
 * .
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#define THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL

#include "drv_comm.h"
#include <idp_define.h>

#if defined(IDP_ENABLE_BUS_MONITOR)

#include "drv_comm.h"
#include <bus_monitor.h>

#define IDP_BUS_MONITOR_BUF_SIZE (20480)

struct idp_bus_monitor_data_t
{
  BM_LOG_T m_log_buf;
  
  kal_uint32 m_video_encode_frame_idx;
  kal_bool m_idp_start_fetching;
  kal_bool m_idp_done;
  kal_bool m_lcd_done;
  
  // The following 2 fields are filled by ISP interrupt if
  // it supports.
  kal_bool m_isp_gmc_overrun;
  kal_bool m_isp_resz_overrun;
};
typedef struct idp_bus_monitor_data_t idp_bus_monitor_data_t;

static kal_uint32 idp_bus_monitor_cur_idx = 0;
static idp_bus_monitor_data_t idp_bus_monitor_log_buf[IDP_BUS_MONITOR_BUF_SIZE] = {0};
static kal_bool idp_bus_monitor_start_log = KAL_FALSE;
static kal_timerid idp_bus_monitor_timer_id = 0;
static kal_uint32 idp_bus_monitor_video_encode_frame_idx = 0;

static void
idp_bus_monitor_incre_idx(void)
{
  ++idp_bus_monitor_cur_idx;
  idp_bus_monitor_cur_idx %= IDP_BUS_MONITOR_BUF_SIZE;
}

static void
idp_bus_monitor_timer_cb(void *timer_param)
{
  // Stop first.
  {
    BM_END_LOG_ALL();
    BM_GET_LOG(&(idp_bus_monitor_log_buf[idp_bus_monitor_cur_idx].m_log_buf));
    
    {
      kal_uint32 const savedMask = SaveAndSetIRQMask();
      
      idp_bus_monitor_log_buf[idp_bus_monitor_cur_idx].m_video_encode_frame_idx =
        idp_bus_monitor_video_encode_frame_idx;
      
      idp_bus_monitor_incre_idx();
      
      RestoreIRQMask(savedMask);
    }
  }
  
  // Start again.
  BM_BEGIN_LOG_ALL();
}

void
idp_bus_monitor_init(void)
{
  if (kal_if_hisr())
  {
    ASSERT(0);
  }
  
  if (kal_if_lisr())
  {
    ASSERT(0);
  }
  
  if (idp_bus_monitor_timer_id != 0)
  {
    kal_cancel_timer(idp_bus_monitor_timer_id);
    idp_bus_monitor_timer_id = 0;
  }
  
  {
    kal_uint32 const savedMask = SaveAndSetIRQMask();
    idp_bus_monitor_cur_idx = 0;
    idp_bus_monitor_start_log = KAL_FALSE;
    RestoreIRQMask(savedMask);
  }
  
  memset(&(idp_bus_monitor_log_buf[0]), 0, sizeof(idp_bus_monitor_log_buf));
}

void
idp_bus_monitor_init_timer(void)
{
  if (kal_if_hisr())
  {
    ASSERT(0);
  }
  
  if (kal_if_lisr())
  {
    ASSERT(0);
  }
  
  idp_bus_monitor_timer_id = kal_create_timer("IdpBusMonitorTimer");
}

void
idp_bus_monitor_start_timer(kal_uint32 const ticks)
{
  if (kal_if_hisr())
  {
    ASSERT(0);
  }
  
  if (kal_if_lisr())
  {
    ASSERT(0);
  }
  
  kal_set_timer(idp_bus_monitor_timer_id,
                (kal_timer_func_ptr)idp_bus_monitor_timer_cb,
                NULL, ticks, ticks);
  
  {
    kal_uint32 const savedMask = SaveAndSetIRQMask();
    idp_bus_monitor_start_log = KAL_TRUE;
    RestoreIRQMask(savedMask);
  }
}

void
idp_bus_monitor_deinit_timer(void)
{
  if (kal_if_hisr())
  {
    ASSERT(0);
  }
  
  if (kal_if_lisr())
  {
    ASSERT(0);
  }
  
  kal_cancel_timer(idp_bus_monitor_timer_id);
  idp_bus_monitor_timer_id = 0;
  
  {
    kal_uint32 const savedMask = SaveAndSetIRQMask();
    idp_bus_monitor_start_log = KAL_FALSE;
    RestoreIRQMask(savedMask);
  }
}

void
idp_bus_monitor_mark_idp_start_fetching(void)
{
  if (KAL_TRUE == idp_bus_monitor_start_log)
  {
    idp_bus_monitor_log_buf[idp_bus_monitor_cur_idx].m_idp_start_fetching = KAL_TRUE;
  }
}

void
idp_bus_monitor_mark_idp_done(void)
{
  if (KAL_TRUE == idp_bus_monitor_start_log)
  {
    idp_bus_monitor_log_buf[idp_bus_monitor_cur_idx].m_idp_done = KAL_TRUE;
  }
}

void
idp_bus_monitor_mark_lcd_done(void)
{
  if (KAL_TRUE == idp_bus_monitor_start_log)
  {
    idp_bus_monitor_log_buf[idp_bus_monitor_cur_idx].m_lcd_done = KAL_TRUE;
  }
}

void
idp_bus_monitor_mark_isp_gmc_overrun(void)
{
  if (KAL_TRUE == idp_bus_monitor_start_log)
  {
    idp_bus_monitor_log_buf[idp_bus_monitor_cur_idx].m_isp_gmc_overrun = KAL_TRUE;
  }
}

void
idp_bus_monitor_mark_isp_resz_overrun(void)
{
  if (KAL_TRUE == idp_bus_monitor_start_log)
  {
    idp_bus_monitor_log_buf[idp_bus_monitor_cur_idx].m_isp_resz_overrun = KAL_TRUE;
  }
}

void
idp_bus_monitor_mark_video_encode_frame_idx(void)
{
  if (KAL_TRUE == idp_bus_monitor_start_log)
  {
    ++idp_bus_monitor_video_encode_frame_idx;
  }
}

#endif
