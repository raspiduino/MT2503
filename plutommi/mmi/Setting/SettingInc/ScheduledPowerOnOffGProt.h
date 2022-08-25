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
 * ScheduledPowerOnOffGprot.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines global functions used in schedule power on/off application.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *==============================================================================
 *******************************************************************************/
/*
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME :ScheduledPowerOnOffGprot.h

   PURPOSE     : nil

   REMARKS     : nil

   AUTHOR      : Gautam Saluja

   DATE     : 

**************************************************************/
#ifndef _MMI_SCHEDULEPOWERONOFFGPROT_H
#define _MMI_SCHEDULEPOWERONOFFGPROT_H
#ifdef __MMI_PHNSET_SCHEDULE_POWER_ON_OFF__
/* auto add by kw_check begin */
#include "MMIDataType.h"
/* auto add by kw_check end */
#include "custom_mmi_default_value.h"

/* 
 * Define
 */
#define MMI_SETTING_SCHEDULE_OFF_REC_NUM 2
#define MMI_SETTING_SCHEDULE_ON_REC_NUM 2

/* 
 * Typedef 
 */
typedef enum
{
    SETTING_SPOF_DISABLE,
    SETTING_SPOF_ENABLE,

    SETTING_SPOF_END
} mmi_spof_status_enum;

typedef enum
{
    SETTING_SPOF_POWER_ON,
    SETTING_SPOF_POWER_OFF,

    SETTING_SPOF_TYPE_END
} mmi_spof_type_enum;
/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */

extern void SPOFDeInit(void);   /* currently unused */
extern void EntrySpofApp(MMI_ID parent_id);
extern void SPOFInitNvRam(void);
extern void SpofRestore(void);
extern void SPOFFCBInit(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_spof_set_schedule
 * DESCRIPTION
 *  Save the SPOF data to NVRAM 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_spof_set_schedule(U8 index, spof_nvram_struct *spof_data);
#endif /* __MMI_PHNSET_SCHEDULE_POWER_ON_OFF__ */
#endif /* _MMI_SCHEDULEPOWERONOFFGPROT_H */ 

