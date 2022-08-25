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
 *	visualhisr.c
 *
 * Project:
 * --------
 *		MT6218B and MT6219 later chips
 *
 * Description:
 * ------------
 *   This file is intends for multimedia HISR management.
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
 *============================================================================
 ****************************************************************************/

#include "drv_comm.h"
#include "visualhisr.h"
#include "hisr_config.h"
#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "drv_features_video.h"

#if defined(_MAUI_SOFTWARE_LA_)
/* under construction !*/
/* under construction !*/
#endif

//for 60qbit issue
#ifdef DRV_MP4_V2_ENHANCE
#pragma arm section rwdata = "INTERNRW" , rodata = "INTERNCONST" , zidata = "INTERNZI"
#endif

kal_hisrid visual_hisr;
kal_uint32 visual_hisr_status;

void VISUAL_ERROR_HISR(void);
VISUAL_HISR_STRUCT VISUAL_HISR_TABLE[MAX_VISUAL_DEVICE];
VISUAL_HISR_ID    VISUAL_CURRENT_HISR;

#ifdef DRV_MP4_V2_ENHANCE
#pragma arm section rwdata, rodata , zidata
#endif

#ifdef __VE_VISUAL_HISR_DBG_LOG__
VISUAL_HISR_DBG_STRUCT	VISUAL_HISR_DBG_INFO_DATA;
void visual_hisr_dbg_trace(VISUAL_HISR_ID index, kal_uint32 time)
{
    kal_uint32 savedMask;
    
    savedMask = SaveAndSetIRQMask();
    
    if (VISUAL_UNKNOWN_HISR_ID != index) /* Means it's enter. */    
    {
        VISUAL_HISR_DBG_INFO_DATA.dbg_data[VISUAL_HISR_DBG_INFO_DATA.dbg_data_idx&(MAX_VISUAL_HISR_DBG_INFO_SIZE - 1)].tag = (kal_uint16)index;
        VISUAL_HISR_DBG_INFO_DATA.dbg_data[VISUAL_HISR_DBG_INFO_DATA.dbg_data_idx&(MAX_VISUAL_HISR_DBG_INFO_SIZE - 1)].time_enter = time;
        VISUAL_HISR_DBG_INFO_DATA.dbg_data[VISUAL_HISR_DBG_INFO_DATA.dbg_data_idx&(MAX_VISUAL_HISR_DBG_INFO_SIZE - 1)].time_leave = 0;		

    }
    else /* Means it's leave. */
    {
        VISUAL_HISR_DBG_INFO_DATA.dbg_data[VISUAL_HISR_DBG_INFO_DATA.dbg_data_idx&(MAX_VISUAL_HISR_DBG_INFO_SIZE - 1)].time_leave = time;    
        VISUAL_HISR_DBG_INFO_DATA.dbg_data_idx++;    
    }
    
    RestoreIRQMask(savedMask);
}
#endif  /*__VE_VISUAL_HISR_DBG_LOG__*/

void VISUAL_ERROR_HISR(void)
{
    ASSERT(0);
}

void VISUAL_Register_HISR(kal_uint8 visula_hisr_id, VOID_FUNCTION hisr_func)
{
    VISUAL_HISR_TABLE[visula_hisr_id].hisr_func = hisr_func;
}

//for 60qbit issue
#ifdef DRV_MP4_V2_ENHANCE
#pragma arm section code = "INTERNCODE"
#endif

void VISUAL_HISR(void)
{
    register kal_uint32 index;
    register kal_uint32 savedMask;
#if defined(_MAUI_SOFTWARE_LA_)
/* under construction !*/
#endif
   
    if (visual_hisr_status != 0)
    {
        for(index = 0;index<MAX_VISUAL_DEVICE;index++)
        {
            if (visual_hisr_status & (1 << index))
            {
                savedMask = SaveAndSetIRQMask();
#if defined(_MAUI_SOFTWARE_LA_)
/* under construction !*/
/* under construction !*/
#endif
                VISUAL_CURRENT_HISR = (VISUAL_HISR_ID)index;
                if (0 == VISUAL_HISR_TABLE[index].hisr_count)
                {
                    ASSERT(0);
                }
                VISUAL_HISR_TABLE[index].hisr_count--;
                if (VISUAL_HISR_TABLE[index].hisr_count == 0)
                {
                    visual_hisr_status &= ~((1 << index));
                }
                RestoreIRQMask(savedMask);
                #ifdef __VE_VISUAL_HISR_DBG_LOG__
                visual_hisr_dbg_trace((VISUAL_HISR_ID) index, drv_get_current_time());
                #endif /*__VE_VISUAL_HISR_DBG_LOG__*/
                VISUAL_HISR_TABLE[index].hisr_func();
#ifdef __VE_VISUAL_HISR_DBG_LOG__
                visual_hisr_dbg_trace(VISUAL_UNKNOWN_HISR_ID, drv_get_current_time());
#endif /*__VE_VISUAL_HISR_DBG_LOG__*/
                VISUAL_CURRENT_HISR = VISUAL_UNKNOWN_HISR_ID;
            }
        }
    }
}

#ifdef DRV_MP4_V2_ENHANCE
#pragma arm section code
#endif

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 
void visual_hisr_init(void)
{
    
    kal_uint32 index;
    for(index=0;index<MAX_VISUAL_DEVICE;index++)
    {
        VISUAL_HISR_TABLE[index].hisr_func = VISUAL_ERROR_HISR;
        VISUAL_HISR_TABLE[index].hisr_count = 0;
    }
    
    if (visual_hisr == NULL)
    {
        #if defined(__MTK_TARGET__) && !defined(MT6251)
        visual_hisr = kal_init_hisr(VISUHISR);
        #endif /*__MTK_TARGET__*/
    }
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif
void visual_active_hisr(VISUAL_HISR_ID eId)
{
   kal_uint32 _savedMask;
   _savedMask = SaveAndSetIRQMask();
   visual_hisr_status |= (1<<eId);
   VISUAL_HISR_TABLE[eId].hisr_count++;
   RestoreIRQMask(_savedMask);
   kal_activate_hisr(visual_hisr);
}


