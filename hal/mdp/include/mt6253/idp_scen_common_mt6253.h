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
 *    idp_scen_common_mt6253.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    Only for MT6253 MDP driver...
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
 * 09 15 2011 peter.wang
 * removed!
 * .
 *
 * 07 26 2011 peter.wang
 * removed!
 * .
 *
 * 05 17 2011 peter.wang
 * removed!
 * .
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

extern kal_bool
idp_common_open_hook(
    idp_owner_t * const owner);

extern kal_bool
idp_common_stop_hook(
    idp_owner_t * const owner);

extern kal_bool
idp_common_hardware_setting_have_been_changed_hook(
    idp_owner_t * const owner);

extern kal_bool
idp_common_start_input_hook(
    idp_owner_t * const owner);

extern kal_bool
idp_common_is_busy_hook(
    idp_owner_t const * const owner,
    kal_bool * const busy);

extern kal_bool
idp_common_is_in_use_hook(void);

extern kal_bool
idp_dummy_hook(
    idp_owner_t * const owner);

extern void
idp_dummy_hook2(
    idp_owner_t * const owner);

extern kal_bool
idp_dummy_hook3(void);


#if defined(CONTOUR_IMPROVEMENT_MT6253)
extern kal_uint32 dithering_y_buffer_addr[2];
extern kal_uint32 dithering_u_buffer_addr[2];
extern kal_uint32 dithering_v_buffer_addr[2];

extern kal_uint32 sw_dithering_buffer_idx;
extern kal_uint32 sw_dithering_is_busy;
#endif

// this flag is used to indicate whether MDP triple display buffer is enabled or not
extern kal_bool _idp_scen_triple_display_buffer_enable;
extern kal_uint32 curr_display_buffer_addr;
extern kal_uint32 next_display_buffer_addr;


