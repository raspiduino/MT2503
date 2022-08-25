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
 *  CallLogSrv.res
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Describle the resource used in CallLogSrv.
 *
 * Author:
 * -------
 *  Kefeng Lian (mtk80043)
 *
 *                      
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 04 10 2014 xianggao.kong
 * [MAUI_03490154] call is not registered in this case
 * .
 *
 * 04 10 2014 xianggao.kong
 * [MAUI_03490154] call is not registered in this case
 * deal with EVT_ID_SRV_SHUTDOWN_HANDLER_RESET.
 *
 * 12 25 2012 yanchao.yang
 * [MAUI_03257435] [clog srv]SLIM check in
 * .
 *
 * 10 28 2010 kefeng.lian
 * [MAUI_02639064] [CallLog] Call log code revise
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 

#include "mmi_features.h"
#include "CustResDef.h"



<?xml version = "1.0" encoding = "UTF-8"?>


<APP id = "SRV_CALLLOG">


<!----------------- XML Begin ------------------------------------------------->

<!----------------- Include Area ---------------------------------------------->

  
<!----------------- Common ---------------------------------------------------->

    <!----------------- Event Id ------------------------------------------->             
	<EVENT id="EVT_ID_SRV_CLOG_READY" type="SENDER"/>
	<EVENT id="EVT_ID_SRV_CLOG_ADD_LOG" type="SENDER"/>
	<EVENT id="EVT_ID_SRV_CLOG_UPDATE_LOG" type="SENDER"/>
	<EVENT id="EVT_ID_SRV_CLOG_UPDATE_ALL" type="SENDER"/>
	<EVENT id="EVT_ID_SRV_CLOG_DEL_LOG" type="SENDER"/>
	<EVENT id="EVT_ID_SRV_CLOG_DEL_ALL" type="SENDER"/>
#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
	<RECEIVER id="EVT_ID_PHB_ADD_CONTACT" proc="srv_clog_phb_evt_hdlr"/>
	<RECEIVER id="EVT_ID_PHB_UPD_CONTACT" proc="srv_clog_phb_evt_hdlr"/>
	<RECEIVER id="EVT_ID_PHB_DEL_CONTACT" proc="srv_clog_phb_evt_hdlr"/>
#endif /* __MMI_CLOG_PHB_SYNC_SUPPORT__ */
#ifdef __MMI_TELEPHONY_SUPPORT__
	<RECEIVER id="EVT_ID_SRV_SHUTDOWN_HANDLER_RESET" proc="srv_clog_shutdown_evt_hdlr"/>
#endif /* __MMI_TELEPHONY_SUPPORT__ */
  
<!----------------- Common End ------------------------------------------------>






<!----------------- XML END --------------------------------------------------->

</APP>






  
