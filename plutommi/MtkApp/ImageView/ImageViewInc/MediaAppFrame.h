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
 *  MediaAppFrame.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Frame for multi-media Apps.
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
 * removed!
 * removed!
 * removed!
 ****************************************************************************/

#ifndef _MEDIA_APP_FRAME_H_
#define _MEDIA_APP_FRAME_H_

#include "MMI_features.h"

#include "MMIDataType.h"
#include "gdi_include.h"
#include "mmi_frm_input_gprot.h"
#include "MediaAppPanel.h"

/*
 * data of FRAME_EVT_TYPE_FRM
 */
typedef enum
{
    FRAME_EVT_PANEL_UPDATE
} mapp_frame_evt_t;

/*
 * type of the frame event
 */
typedef enum
{
    FRAME_EVT_TYPE_FRM = 0,
    FRAME_EVT_TYPE_PANEL
} mapp_frame_evt_type_t;

typedef struct{
    mapp_frame_evt_t   evt;
    void              *usrdata;
}mapp_frame_evt_data_t;


/*
 * Data of FRAME_EVT_TYPE_PANEL event.
 */
typedef struct{
    U32  id;
    med_panel_evt_t   evt;
    void              *usrdata;
}mapp_panel_evt_data_t;

typedef void (*mapp_frame_cb_t)(mapp_frame_evt_type_t evt_type, void *evt_data);

/* Fade out direction of panel */
typedef enum{
    FADE_DIR_NONE,
    FADE_DIR_LEFT,
    FADE_DIR_RIGHT,
    FADE_DIR_UP,
    FADE_DIR_DOWN
}mapp_fade_direct;

typedef struct{
    med_panel_t *p_panel;
    mapp_fade_direct fade_dir;
    U32              fade_length;
    S32              fade_start_x;
    S32              fade_start_y;
}mapp_frame_panel_t;

typedef struct{
    U32 panel_count;
    mapp_frame_panel_t *panel_array;
    U32 flag;
    U32 stat;
    S32 ease_index;
    mapp_frame_cb_t evt_cb;
    void            *usrdata;
}mapp_frame_t;

/*
 * Flag of frame
 */
#define MAPP_FRAME_FLAG_FADE_ENABLE     0x1
/*****************************************************************************
 * FUNCTION
 *  mmi_mapp_frame_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pframe      [IN/OUT]
 *  panel_array [IN]
 *  count       [IN]
 *  flag        [IN] : See MAPP_FRAME_FLAG_XXX
 * RETURNS
 *      Handle of frame.
 *****************************************************************************/
extern U32 mmi_mapp_frame_create(mapp_frame_t *pframe, mapp_frame_panel_t panel_array[], U32 count, U32 fag);

/*****************************************************************************
 * FUNCTION
 *  mmi_mapp_frame_reset
 * DESCRIPTION
 *  Reset panel the frame contains.
 * PARAMETERS
 *  pframe           [IN/OUT]
 *  panel_array      [IN]
 *  count            [IN]
 * RETURNS
 *
 *****************************************************************************/
extern void mmi_mapp_frame_reset(mapp_frame_t *pframe, mapp_frame_panel_t panel_array[], U32 count);

/*****************************************************************************
 * FUNCTION
 *  mmi_mapp_frame_destory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pframe           [IN]
 * RETURNS
 *
 *****************************************************************************/
extern void mmi_mapp_frame_destory(mapp_frame_t *pframe);

/*****************************************************************************
 * FUNCTION
 *  mmi_mapp_frame_start_fade_in
 * DESCRIPTION
 *  Start fade in if the frame is not show.
 * PARAMETERS
 *  pframe           [IN]
 * RETURNS
 *
 *****************************************************************************/
extern void mmi_mapp_frame_start_fade_in(mapp_frame_t *pframe);

/*****************************************************************************
 * FUNCTION
 *  mmi_mapp_frame_start_fade_out
 * DESCRIPTION
 *  Start fade in if the frame is not hide.
 * PARAMETERS
 *  pframe           [IN]
 * RETURNS
 *
 *****************************************************************************/
extern void mmi_mapp_frame_start_fade_out(mapp_frame_t *pframe);

/*****************************************************************************
 * FUNCTION
 *  mmi_mapp_frame_show
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pframe            [IN]
 *  is_show           [IN]
 * RETURNS
 *
 *****************************************************************************/
extern void mmi_mapp_frame_show(mapp_frame_t *pframe, MMI_BOOL is_show);

/*****************************************************************************
 * FUNCTION
 *  mmi_mapp_frame_start_watchdog
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pframe            [IN]
 * RETURNS
 *
 *****************************************************************************/
extern void mmi_mapp_frame_start_watchdog(mapp_frame_t *pframe);

/*****************************************************************************
 * FUNCTION
 *  mmi_mapp_frame_stop_watchdog
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pframe            [IN]
 * RETURNS
 *
 *****************************************************************************/
extern void mmi_mapp_frame_stop_watchdog(mapp_frame_t *pframe);

/*****************************************************************************
 * FUNCTION
 *  mmi_mapp_frame_get_display_layers
 * DESCRIPTION
 *  Get layers to blt.
 * PARAMETERS
 *  pframe            [IN]
 *  layers            [IN] : 
 *  count             [IN] : Must greater than total panel count.
 * RETURNS
 *  
 *****************************************************************************/
extern void mmi_mapp_frame_get_display_layers(mapp_frame_t *pframe, gdi_handle layers[], U32 count);

/*****************************************************************************
 * FUNCTION
 *  mmi_mapp_frame_enable_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pframe            [IN]
 *  id                [IN] : id of item
 * RETURNS
 *  
 *****************************************************************************/
extern void mmi_mapp_frame_enable_item(mapp_frame_t *pframe, U32 id);

/*****************************************************************************
 * FUNCTION
 *  mmi_mapp_frame_disable_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pframe            [IN]
 *  id                [IN] : id of item
 * RETURNS
 *  
 *****************************************************************************/
extern void mmi_mapp_frame_disable_item(mapp_frame_t *pframe, U32 id);

/*****************************************************************************
 * FUNCTION
 *  mmi_mapp_frame_press_item
 * DESCRIPTION
 *  Just change the item to press state. Not callback to user.
 *  Used for sync to key operation.
 * PARAMETERS
 *  pframe            [IN]
 *  id                [IN] : id of item
 * RETURNS
 *  
 *****************************************************************************/
extern void mmi_mapp_frame_press_item(mapp_frame_t *pframe, U32 id);

/*****************************************************************************
 * FUNCTION
 *  mmi_mapp_frame_up_item
 * DESCRIPTION
 *  Just change the item to up state. Not callback to user.
 *  Used for sync to key operation.
 * PARAMETERS
 *  pframe            [IN]
 *  id                [IN] : id of item
 * RETURNS
 *  
 *****************************************************************************/
extern void mmi_mapp_frame_up_item(mapp_frame_t *pframe, U32 id);

typedef enum{
    MAPP_FRAME_STAT_SHOW = 0,
    MAPP_FRAME_STAT_HIDE,
    MAPP_FRAME_STAT_SHOWING,
    MAPP_FRAME_STAT_HIDING,
}MAPP_FRAME_STAT;
/*****************************************************************************
 * FUNCTION
 *  mmi_mapp_frame_state
 * DESCRIPTION
 *  Get frame state.
 * PARAMETERS
 *  pframe            [IN]
 * RETURNS
 *  Frame state, see MAPP_FRAME_STAT
 *****************************************************************************/
extern S32 mmi_mapp_frame_state(mapp_frame_t *pframe);

/*****************************************************************************
 * FUNCTION
 *  mmi_mapp_frame_set_cb
 * DESCRIPTION
 *  Just change the item to up state. Not callback to user.
 *  Used for sync to key operation.
 * PARAMETERS
 *  pframe            [IN]
 *  event_cb          [IN] : 
 *  usrdata           [IN] : 
 * RETURNS
 *  
 *****************************************************************************/
extern void mmi_mapp_frame_set_cb(mapp_frame_t *pframe, mapp_frame_cb_t event_cb, void *usrdata);

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_mapp_frame_pendown
 * DESCRIPTION
 *  Get layers to blt.
 * PARAMETERS
 *  pframe            [IN]
 *  pos            [IN] : 
 * RETURNS
 *  MMI_TRUE -- frame process the event.
 *  MMI_FALSE -- Frame not process the event.
 *****************************************************************************/
extern MMI_BOOL mmi_mapp_frame_pendown(mapp_frame_t *pframe, mmi_pen_point_struct pos);

/*****************************************************************************
 * FUNCTION
 *  mmi_mapp_frame_penup
 * DESCRIPTION
 *  Get layers to blt.
 * PARAMETERS
 *  pframe            [IN]
 * RETURNS
 *  MMI_TRUE -- frame process the event.
 *  MMI_FALSE -- Frame not process the event.
 *****************************************************************************/
extern MMI_BOOL mmi_mapp_frame_penup(mapp_frame_t *pframe);

/*****************************************************************************
 * FUNCTION
 *  mmi_mapp_frame_penmove
 * DESCRIPTION
 *  Get layers to blt.
 * PARAMETERS
 *  pframe            [IN]
 *  pos            [IN] : 
 * RETURNS
 *  MMI_TRUE -- frame process the event.
 *  MMI_FALSE -- Frame not process the event.
 *****************************************************************************/
extern MMI_BOOL mmi_mapp_frame_penmove(mapp_frame_t *pframe, mmi_pen_point_struct pos);

/*****************************************************************************
 * FUNCTION
 *  mmi_mapp_frame_penabort
 * DESCRIPTION
 *  Get layers to blt.
 * PARAMETERS
 *  pframe            [IN]
 *  type              [IN] : 
 * RETURNS
 *  MMI_TRUE -- frame process the event.
 *  MMI_FALSE -- Frame not process the event.
 *****************************************************************************/
extern MMI_BOOL mmi_mapp_frame_penabort(mapp_frame_t *pframe, mmi_pen_abort_type_enum type);

#endif

#define MEDIA_APP_ALIGN_4(size)        (((size)+3) & (~0x3))

#define MEDIA_APP_FRAME_SIZE(nPanel, nItems) (MEDIA_APP_ALIGN_4(sizeof(mapp_frame_t)) + \
                                        (nPanel)*(MEDIA_APP_ALIGN_4(sizeof(mapp_frame_panel_t)) + MEDIA_APP_ALIGN_4(sizeof(med_panel_t))) + \
                                        (nItems)*MEDIA_APP_ALIGN_4(sizeof(med_panel_item_t)))


#endif /* _MEDIA_APP_PANEL_H_ */ 

