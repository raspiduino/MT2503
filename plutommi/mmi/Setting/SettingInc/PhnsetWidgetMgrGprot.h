/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  PhnsetWidgetMgrGprot.h
 *
 * Project:
 * --------
 *  MAUI
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
 *----------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MMI_PHNSET_WIDGET_MGR_H__
#define __MMI_PHNSET_WIDGET_MGR_H__

#include "MMI_features.h"
#include "MMIDataType.h"
#ifdef __MMI_VUI_LAUNCHER_KEY__
#include "vapp_launcher_key_gprot.h"

/*****************************************************************************
***	  	Define					*****
 *****************************************************************************/
#define MAX_PHNSET_WIDGETS_NUM 10
#define MIN_PHNSET_WIDGETS_NUM 3
#define MAX_PHNSET_WIDGETS_NAME_LEN 24

/*****************************************************************************
***		 Local struct					*
 *****************************************************************************/
typedef struct
{
	S32 widget_name_list[MAX_PHNSET_WIDGETS_NUM];
	U8	widget_mark_flag[MAX_PHNSET_WIDGETS_NUM];
}mmi_phnset_widget_manager_cntx_struct;

/*****************************************************************************
*		 Local Enum					*
 *****************************************************************************/
typedef enum
{
	PHNSET_WIDGET_MGR_ORDER_NONE,
	PHNSET_WIDGET_MGR_ORDER_MOVE,
		

}mmi_phnset_widget_mgr_order_status_enum;

/*****************************************************************************
*		 extern function					*
 *****************************************************************************/

/*****************************************************************************
* FUNCTION
*  mmi_phnset_widget_get_widget_num
* DESCRIPTION
*  widget manger for get widget number
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
extern S32 mmi_phnset_widget_get_widget_num(void);

/*****************************************************************************
* FUNCTION
*  mmi_phnset_widget_get_widget_name_list
* DESCRIPTION
*  widget manger for get widget name list.
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
extern void mmi_phnset_widget_get_widget_name_list(mmi_vapp_widget_name_struct * name_array);

/*****************************************************************************
* FUNCTION
*  mmi_phnset_widget_get_widget_name_id_list
* DESCRIPTION
*  widget manger for get widget id name list.
* PARAMETERS
*  evt        [IN]
* RETURNS
*  void
*****************************************************************************/
extern void  mmi_phnset_widget_get_widget_ids_list(S32* id);


#endif /* __MMI_VUI_LAUNCHER_KEY__ */
#endif // __MMI_PHNSET_WIDGET_MGR_H__
