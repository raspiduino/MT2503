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
 *  SwatchGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Swatch
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef _MMI_SWATCH_GPROT_H_
#define _MMI_SWATCH_GPROT_H_

#include "mmi_features.h"

#ifdef __MMI_WEARABLE_DEVICE__

#include "MMIDataType.h"
#include "gdi_datatype.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
typedef struct
{
    U32 steps;
    U32 calories;
} mmi_idle_swatch_pedometer_data;

typedef void (*mmi_idle_swatch_pedometer_cb)(void* data);


/***************************************************************************** 
 * Functions
 *****************************************************************************/
extern void mmi_idle_swatch_enter(MMI_ID group_id);
extern void mmi_idle_swatch_exit(void);

#ifdef __CUI_SWATCH_SUPPORT__
extern void cui_swatch_create(MMI_ID group_id);
extern void cui_swatch_run(void);
extern void cui_swatch_create_and_run(MMI_ID group_id);
extern void cui_swatch_close(void);
#endif  //__CUI_SWATCH_SUPPORT__

extern void mmi_idle_swatch_update_clock(void);
extern void mmi_idle_swatch_update_clock_by_minute(void);
extern void mmi_idle_swatch_update_clock_by_second(void);
extern void mmi_idle_swatch_update_ap(void);
extern void mmi_idle_swatch_update_ap_ext(U8 index, U32 count);
extern mmi_ret mmi_idle_swatch_event_handler(mmi_event_struct *evt);

extern void mmi_idle_swatch_pedometer_resgiter_callback(mmi_idle_swatch_pedometer_cb cb);

#endif /* __MMI_WEARABLE_DEVICE__ */ 
#endif /* _MMI_SWATCH_GPROT_H_ */ 

