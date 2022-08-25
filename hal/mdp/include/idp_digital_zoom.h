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
 *    idp_digital_zoom.h
 *
 * Project:
 * --------
 *    MAUI
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
 * 07 27 2011 chelun.tsai
 * removed!
 * .
 *
 * 01 07 2011 chrono.wu
 * removed!
 * .
 *
 * 12 17 2010 cm.huang
 * removed!
 * .
 *
 * 12 06 2010 gellmann.chang
 * removed!
 * .
 *
 * 12 03 2010 cm.huang
 * removed!
 * .
 *
 * 11 23 2010 cm.huang
 * removed!
 * .
 *
 * removed!
 * removed!
 * MT6255 HQA check-in
 *
 * removed!
 * removed!
 * MM integration check-in
 *
 * removed!
 * removed!
 * MM integration check-in
 *
 * removed!
 * removed!
 * DVT check-in
 * 
 *
 * 
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_idp_digital_zoom_h__
#define __idp_idp_digital_zoom_h__

/// \defgroup adaptation_layer
/// \ingroup idp
/// @{

/// \defgroup cal
/// @{

#include "kal_general_types.h"
#include "drv_features_mdp.h"
#include "idp_define.h"


typedef struct
{
	kal_bool		start;		//KAL_TRUE : START, KAL_FALSE : STOP
	kal_bool		zoom_in;		//KAL_TRUE : ZOOM IN , KAL_FALSE : ZOOM OUT
	kal_uint8	zoom_limit;	//Max Zoom Factor
	kal_uint8	zoom_step;	//Step of Zoom Factor for Zoom In or Zoom Out
	kal_uint8	zoom_speed;	//How many frames to Zoom one step, ex: 0: zoom one step per frame
}idp_fast_zoom_struct;


#if defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6256_SERIES) || defined(DRV_IDP_MT6276E2_SERIES)

extern void idp_digital_zoom(kal_uint8 zoom_step);
extern kal_bool idp_fast_zoom_setting(idp_fast_zoom_struct zoom_data);
extern kal_bool idp_digital_zoom_cb(void *user_data);
extern kal_uint32 get_idp_digital_zoom_factor(void);
extern kal_uint32 get_idp_digital_zoom_vertical_factor(void);
extern kal_uint8 get_idp_digital_zoom_step(void);
//extern void idp_digital_zoom_init(kal_uint32 max_zoom_step,kal_uint32 max_zoom_factor,kal_bool jpeg_senor,
//                           kal_uint32 width,kal_uint32 height,kal_uint32 x,kal_uint32 y);

//extern void idp_digital_zoom_init(kal_uint32 max_zoom_step,kal_uint32 max_zoom_factor,ZOOM_SUPPORT_TYPE_ENUM zoom_type,
//                           kal_uint32 width,kal_uint32 height,kal_uint32 x,kal_uint32 y);

extern void idp_digital_zoom_config(kal_uint8 zoom_step);
extern void idp_get_dz_window(kal_uint16* right,kal_uint16* bottom,kal_uint16* left,kal_uint16* top);
extern kal_bool get_idp_fast_zoom_enabled(void);

/// @}
#endif //#if defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6256_SERIES)

#endif //#define __idp_idp_digital_zoom_h__
