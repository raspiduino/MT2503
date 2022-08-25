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
 *  MediaAppFrame.c
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

#include "MMI_features.h"

#include "MMIDataType.h"
#include "gdi_include.h"
#include "mmi_trc_int.h"
#include "mmi_frm_input_gprot.h"
#include "gui.h"
#include "MediaAppPanel.h"
#include "MediaAppFrame.h"

#define MAPP_FRAME_FADE_INTERVAL        40
#define MAPP_FRAME_FADE_WG_INTERVAL     3000

#define MAPP_FRAME_EASE_STEPS   10
static const S32 mapp_frame_ease_out[MAPP_FRAME_EASE_STEPS] = {25, 46, 63, 76, 86, 92, 95, 97, 99, 100};
static void mmi_mapp_frame_hide(void *pdata);
static void mmi_mapp_frame_fade_cyclic(void *pdata);

/*****************************************************************************
 * FUNCTION
 *  mmi_mapp_frame_get_ease_offset
 * DESCRIPTION
 *
 * PARAMETERS
 *  length      [IN]
 *  index       [IN]
 * RETURNS
 *
 *****************************************************************************/
static S32 mmi_mapp_frame_get_ease_offset(S32 length, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return length * mapp_frame_ease_out[index] / 100;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mapp_frame_cancel_ops
 * DESCRIPTION
 *
 * PARAMETERS
 *  pframe      [IN]
 * RETURNS
 *
 *****************************************************************************/
static void mmi_mapp_frame_cancel_ops(mapp_frame_t *pframe)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gui_cancel_timer((FuncPtr)mmi_mapp_frame_hide);
    gui_cancel_timer((FuncPtr) mmi_mapp_frame_fade_cyclic);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mapp_frame_move_layer
 * DESCRIPTION
 *  Move layer according to fade direction. 
 *  The offset and dir is screen(Logic) coordination system
 * PARAMETERS
 *  panel       [IN]
 *  offset      [IN]
 * RETURNS
 *
 *****************************************************************************/
static void mmi_mapp_frame_move_layer(mapp_frame_panel_t *panel, S32 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 offx=0, offy=0, x, y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(panel->fade_dir){
        case FADE_DIR_LEFT:
            offx = -offset;
        break;

        case FADE_DIR_RIGHT:
            offx = offset;
        break;

        case FADE_DIR_UP:
            offy = -offset;
        break;

        case FADE_DIR_DOWN:
            offy = offset;
        break;

        default:
            return;
    };

    x = panel->fade_start_x + offx;
    y = panel->fade_start_y + offy;
    gdi_layer_set_position_nb_concurrent(panel->p_panel->h_layer, x, y);
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mapp_frame_fade_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pdata       [IN]
 * RETURNS
 *
 *****************************************************************************/
static void mmi_mapp_frame_fade_cyclic(void *pdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset;
    mapp_frame_t *pframe = (mapp_frame_t*)pdata;
    mapp_frame_panel_t *p_panel;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* update panel */
    for(i=0; i<pframe->panel_count; i++){
        p_panel = &(pframe->panel_array[i]);
        if(p_panel->fade_dir == FADE_DIR_NONE)
            continue;

        offset = mmi_mapp_frame_get_ease_offset(p_panel->fade_length, pframe->ease_index);
        /*Ajust direction based on in or out*/
        if(pframe->stat == MAPP_FRAME_STAT_SHOWING){
            offset = p_panel->fade_length - offset;
        }
        
        mmi_mapp_frame_move_layer(p_panel, offset);
    }

    /* update index */
    if (pframe->ease_index > 8)
    {
        pframe->ease_index = 0;
        pframe->stat = (pframe->stat == MAPP_FRAME_STAT_SHOWING) ? MAPP_FRAME_STAT_SHOW : MAPP_FRAME_STAT_HIDE;
        mmi_mapp_frame_start_watchdog(pframe);
    }
    else
    {   /* continue */
        pframe->ease_index++;
        gui_start_timer_ex(MAPP_FRAME_FADE_INTERVAL, mmi_mapp_frame_fade_cyclic, pdata);
    }

    /* notify to update screen */
    if(pframe->evt_cb){
        mapp_frame_evt_data_t evt_data;
        evt_data.evt = FRAME_EVT_PANEL_UPDATE;
        evt_data.usrdata = pframe->usrdata;
        pframe->evt_cb(FRAME_EVT_TYPE_FRM, &evt_data); 
    }


}

/*****************************************************************************
 * FUNCTION
 *  mmi_mapp_frame_hide
 * DESCRIPTION
 *  Timeout proc of watchdog.
 * PARAMETERS
 *  pdata       [IN]
 * RETURNS
 *
 *****************************************************************************/
static void mmi_mapp_frame_hide(void *pdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mapp_frame_t *pframe = (mapp_frame_t*)pdata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(pframe->flag & MAPP_FRAME_FLAG_FADE_ENABLE){
        mmi_mapp_frame_start_fade_out(pframe);
    }else{
        mmi_mapp_frame_show(pframe, MMI_FALSE);
        
        /* notify to update screen */
        if(pframe->evt_cb){
            mapp_frame_evt_data_t evt_data;
            evt_data.evt = FRAME_EVT_PANEL_UPDATE;
            evt_data.usrdata = pframe->usrdata;
            pframe->evt_cb(FRAME_EVT_TYPE_FRM, &evt_data); 
        }
    }
}

/*
 *  API implimentations
 */

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
extern U32 mmi_mapp_frame_create(mapp_frame_t *pframe, mapp_frame_panel_t panel_array[], U32 count, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(pframe, 0, sizeof(mapp_frame_t));
    pframe->flag = flag;
    mmi_mapp_frame_reset(pframe, panel_array, count);
    return (U32)pframe;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mapp_frame_init_panel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  panel      [IN/OUT]
 * RETURNS
 *
 *****************************************************************************/

static void mmi_mapp_frame_init_panel(mapp_frame_panel_t *panel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle layer = panel->p_panel->h_layer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(layer);
    gdi_layer_get_position(&panel->fade_start_x, &panel->fade_start_y);
    gdi_layer_pop_and_restore_active();
}

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
extern void mmi_mapp_frame_reset(mapp_frame_t *pframe, mapp_frame_panel_t panel_array[], U32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Cancel uncompleted operations */
    mmi_mapp_frame_cancel_ops(pframe);

    /* reset */
    pframe->panel_array = panel_array;
    pframe->panel_count = count;
    pframe->stat = MAPP_FRAME_STAT_SHOW;
    
    /* Redraw each panel */
    for(i=0; i<count; i++){
        mmi_mapp_frame_init_panel(&panel_array[i]);
        mmi_med_panel_redraw((med_panel_handle)panel_array[i].p_panel, MMI_FALSE);
    }
}

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
extern void mmi_mapp_frame_destory(mapp_frame_t *pframe)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_mapp_frame_cancel_ops(pframe);
}

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
extern void mmi_mapp_frame_start_fade_in(mapp_frame_t *pframe)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(!(pframe->flag & MAPP_FRAME_FLAG_FADE_ENABLE) || pframe->stat == MAPP_FRAME_STAT_SHOW)
        return;

    /* start fade in */
    if(pframe->stat == MAPP_FRAME_STAT_HIDE){
        gui_start_timer_ex(MAPP_FRAME_FADE_INTERVAL, mmi_mapp_frame_fade_cyclic, pframe);
    }

    pframe->stat = MAPP_FRAME_STAT_SHOWING;
}

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

extern void mmi_mapp_frame_start_fade_out(mapp_frame_t *pframe)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(!(pframe->flag & MAPP_FRAME_FLAG_FADE_ENABLE) || pframe->stat == MAPP_FRAME_STAT_HIDE)
        return;

    /* start fade in */
    if(pframe->stat == MAPP_FRAME_STAT_SHOW){
        gui_start_timer_ex(MAPP_FRAME_FADE_INTERVAL, mmi_mapp_frame_fade_cyclic, pframe);
    }

    pframe->stat = MAPP_FRAME_STAT_HIDING;

}

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
extern void mmi_mapp_frame_show(mapp_frame_t *pframe, MMI_BOOL is_show)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_mapp_frame_cancel_ops(pframe);
    
    if(is_show == MMI_TRUE){
        /* set layer position to original */
        pframe->stat = MAPP_FRAME_STAT_SHOW;
        if(!(pframe->flag & MAPP_FRAME_FLAG_FADE_ENABLE)){
            mmi_mapp_frame_start_watchdog(pframe);
        }
    }else{
        /* set layer position to hide */
        pframe->stat = MAPP_FRAME_STAT_HIDE;
    }
}

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
extern void mmi_mapp_frame_start_watchdog(mapp_frame_t *pframe)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gui_cancel_timer((FuncPtr)mmi_mapp_frame_hide);
    gui_start_timer_ex(MAPP_FRAME_FADE_WG_INTERVAL, mmi_mapp_frame_hide, pframe);
}

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

extern void mmi_mapp_frame_stop_watchdog(mapp_frame_t *pframe)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gui_cancel_timer((FuncPtr)mmi_mapp_frame_hide);
}

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
S32 mmi_mapp_frame_state(mapp_frame_t *pframe)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return pframe->stat;
}

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

void mmi_mapp_frame_enable_item(mapp_frame_t *pframe, U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for(i=0; i<pframe->panel_count; i++)
    {
        mmi_med_panel_enable_item((med_panel_handle)pframe->panel_array[i].p_panel, id);
    }

}

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

void mmi_mapp_frame_disable_item(mapp_frame_t *pframe, U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    for(i=0; i<pframe->panel_count; i++)
    {
        mmi_med_panel_disable_item((med_panel_handle)pframe->panel_array[i].p_panel, id);
    }

}

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

void mmi_mapp_frame_press_item(mapp_frame_t *pframe, U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    for(i=0; i<pframe->panel_count; i++)
    {
        mmi_med_panel_press_item((med_panel_handle)pframe->panel_array[i].p_panel, id);
    }

}

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

void mmi_mapp_frame_up_item(mapp_frame_t *pframe, U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    for(i=0; i<pframe->panel_count; i++)
    {
        mmi_med_panel_up_item((med_panel_handle)pframe->panel_array[i].p_panel, id);
    }

}

#ifdef __MMI_TOUCH_SCREEN__

static void mmi_mapp_frame_panel_cb(U32 id, med_panel_evt_t event, void *userdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mapp_frame_t *pframe = (mapp_frame_t *)userdata;
    mapp_panel_evt_data_t evt_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt_data.id = id;
    evt_data.evt = event;
    evt_data.usrdata = pframe->usrdata;

    if(pframe->evt_cb){
        pframe->evt_cb(FRAME_EVT_TYPE_PANEL, &evt_data);
    }
}
#endif

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

extern void mmi_mapp_frame_set_cb(mapp_frame_t *pframe, mapp_frame_cb_t event_cb, void *usrdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    U32 i;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    pframe->evt_cb = event_cb;
    pframe->usrdata = usrdata;

#ifdef __MMI_TOUCH_SCREEN__

    /*set panel callback */
    for(i=0; i<pframe->panel_count; i++)
    {
        mmi_med_panel_set_cb((med_panel_handle)pframe->panel_array[i].p_panel, mmi_mapp_frame_panel_cb, pframe);
    }
#endif    
}

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
void mmi_mapp_frame_get_display_layers(mapp_frame_t *pframe, gdi_handle layers[], U32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(count >= pframe->panel_count);
    memset(layers, 0, sizeof(gdi_handle)*count);

    if(pframe->stat == MAPP_FRAME_STAT_HIDE)
        return;
        
    for(i=0; i<pframe->panel_count; i++)
    {
        layers[i] = pframe->panel_array[i].p_panel->h_layer;
    }
    
}

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

MMI_BOOL mmi_mapp_frame_pendown(mapp_frame_t *pframe, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for(i=0; i<pframe->panel_count; i++)
    {
        if(mmi_med_panel_pendown((med_panel_handle)pframe->panel_array[i].p_panel, pos)){
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}

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

MMI_BOOL mmi_mapp_frame_penup(mapp_frame_t *pframe)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for(i=0; i<pframe->panel_count; i++)
    {
        if(mmi_med_panel_penup((med_panel_handle)pframe->panel_array[i].p_panel)){
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;

}

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

MMI_BOOL mmi_mapp_frame_penmove(mapp_frame_t *pframe, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for(i=0; i<pframe->panel_count; i++)
    {
        if(mmi_med_panel_penmove((med_panel_handle)pframe->panel_array[i].p_panel, pos)){
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;

}

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


extern MMI_BOOL mmi_mapp_frame_penabort(mapp_frame_t *pframe, mmi_pen_abort_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for(i=0; i<pframe->panel_count; i++)
    {
        if(mmi_med_panel_penabort((med_panel_handle)pframe->panel_array[i].p_panel, type)){
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;

}

#endif



