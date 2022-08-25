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
 *   FactoryModeDualTouchCalibration.c
 *
 * Project:
 * --------
 *   11B
 *
 * Description:
 * ------------
 *   FM Dual Touch Calibration
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
/* dependence */
#ifdef __MMI_FACTORY_MODE__
#ifdef __TOUCH_PANEL_MULTITOUCH__
#ifdef __MMI_TOUCH_SCREEN__
///////////////////////////////////
#include "dcl_sts.h" /*dual touch service*/
#include "mmi_rp_app_factorymode_def.h"
#include "FactoryModeProt.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "mmi_frm_input_gprot.h" /*point struct*/
#include "Wgui_categories_util.h"/* register left and right key */
/*#include "drvsignals.h" */
#include "wgui_categories.h" /*wgui_cat9011_show*/
#include "dcl_sts.h"
#include "dcl.h"
wgui_cat9011_check_point_struct g_dual_current_struct[2];
wgui_cat9011_check_point_struct g_dual_old_struct[2];
DCL_HANDLE g_dual_fm_handle;


typedef struct
{
	S32 point_num;
	U32 flag;
	wgui_cat9011_check_point_struct *check_point_list;
	U8 doul_touch_index;
} mmi_fm_dual_touch_cat_struct;

mmi_fm_dual_touch_cat_struct g_cat_infor_cxt;



mmi_pen_point_struct g_fm_dual_touch_current;
void mmi_fm_dual_touch_cal_next_scrn(void);

/***************************************************************************** 
 * Define
 *****************************************************************************/

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/
#define MMI_FM_DUAL_DOUCH_CALI_POINTS_NOS 12
#define MMI_FM_SINGLE_DOUCH_CALI_POINTS_NO 9

#if defined(__MMI_MAINLCD_240X320__)
    #define MMI_FM_P_TO_P_LEN          (15)
	#define MMI_FM_CHECK_POINT_IMAGE_W (40)
	#define MMI_FM_CHECK_POINT_IMAGE_H (40)
#elif defined(__MMI_MAINLCD_320X240__)
    #define MMI_FM_P_TO_P_LEN		   (15)
    #define MMI_FM_CHECK_POINT_IMAGE_W (40)
    #define MMI_FM_CHECK_POINT_IMAGE_H (40)
#elif defined(__MMI_MAINLCD_240X400__)
    #define MMI_FM_P_TO_P_LEN		   (15)
    #define MMI_FM_CHECK_POINT_IMAGE_W (40)
    #define MMI_FM_CHECK_POINT_IMAGE_H (40)
#elif defined(__MMI_MAINLCD_320X480__)
    #define MMI_FM_P_TO_P_LEN		   (15)
    #define MMI_FM_CHECK_POINT_IMAGE_W (50)
    #define MMI_FM_CHECK_POINT_IMAGE_H (50)
#else
    #define MMI_FM_P_TO_P_LEN		   (15)
    #define MMI_FM_CHECK_POINT_IMAGE_W (40)
    #define MMI_FM_CHECK_POINT_IMAGE_H (40)
#endif




typedef struct
{
    mmi_pen_point_struct first;
    mmi_pen_point_struct second;
} mmi_fm_dual_touch_cali_struct;


typedef enum {
    mmi_pen_point_first_x,
    mmi_pen_point_first_y,
    mmi_pen_point_second_x,
    mmi_pen_point_second_y
} mmi_fm_dual_touch_cali_point_enum;

static mmi_fm_dual_touch_cali_struct g_fm_dual_touch_point_struct_TP_CALI_LEFT_TOP_RIGHT_DOWN_MAX = 
{
        {LCD_WIDTH / 20, LCD_HEIGHT / 20}, 
        {LCD_WIDTH * 19 / 20 - MMI_FM_CHECK_POINT_IMAGE_W, LCD_HEIGHT * 19 / 20 - MMI_FM_CHECK_POINT_IMAGE_H} 
};

static mmi_fm_dual_touch_cali_struct g_fm_dual_touch_point_struct_TP_CALI_LEFT_TOP_RIGHT_DOWN_MIN = 
{
        {LCD_WIDTH / 2 - MMI_FM_CHECK_POINT_IMAGE_W, LCD_HEIGHT / 2 - MMI_FM_CHECK_POINT_IMAGE_H}, 
        {LCD_WIDTH / 2, LCD_HEIGHT  / 2} 
};

static mmi_fm_dual_touch_cali_struct g_fm_dual_touch_point_struct_TP_CALI_RIGHT_TOP_LEFT_DOWN_MAX = 
{
        {LCD_WIDTH * 19 / 20 - MMI_FM_CHECK_POINT_IMAGE_W, LCD_WIDTH / 20},
        {LCD_WIDTH / 20, LCD_HEIGHT * 19 / 20 - MMI_FM_CHECK_POINT_IMAGE_H},
};

static mmi_fm_dual_touch_cali_struct g_fm_dual_touch_point_struct_TP_CALI_RIGHT_TOP_LEFT_DOWN_MIN = 
{
        {LCD_WIDTH / 2 , LCD_HEIGHT / 2 - MMI_FM_CHECK_POINT_IMAGE_H}, 
        {LCD_WIDTH / 2 - MMI_FM_CHECK_POINT_IMAGE_W, LCD_HEIGHT / 2} 
};

static mmi_fm_dual_touch_cali_struct g_fm_dual_touch_point_struct_TP_CALI_LEFT_TOP_DOWN_MAX = 
{
        {LCD_WIDTH / 20, LCD_HEIGHT / 20}, 
        {LCD_WIDTH  / 20, LCD_HEIGHT * 19 / 20 - MMI_FM_CHECK_POINT_IMAGE_H}    
};

static mmi_fm_dual_touch_cali_struct g_fm_dual_touch_point_struct_TP_CALI_LEFT_TOP_DOWN_MIN = 
{
        {LCD_WIDTH / 20, LCD_HEIGHT / 2 - MMI_FM_CHECK_POINT_IMAGE_H}, 
        {LCD_WIDTH  / 20, LCD_HEIGHT / 2}    
};

static mmi_fm_dual_touch_cali_struct g_fm_dual_touch_point_struct_TP_CALI_RIGHT_TOP_DOWN_MAX = 
{
        {LCD_WIDTH * 19 / 20 - MMI_FM_CHECK_POINT_IMAGE_W, LCD_HEIGHT / 20}, 
        {LCD_WIDTH * 19 / 20 - MMI_FM_CHECK_POINT_IMAGE_W, LCD_HEIGHT * 19 / 20 - MMI_FM_CHECK_POINT_IMAGE_H}    
};

static mmi_fm_dual_touch_cali_struct g_fm_dual_touch_point_struct_TP_CALI_RIGHT_TOP_DOWN_MIN = 
{
        {LCD_WIDTH * 19 / 20 - MMI_FM_CHECK_POINT_IMAGE_W, LCD_HEIGHT / 2 - MMI_FM_CHECK_POINT_IMAGE_H}, 
        {LCD_WIDTH * 19 / 20 - MMI_FM_CHECK_POINT_IMAGE_W, LCD_HEIGHT / 2}    
};

static mmi_fm_dual_touch_cali_struct g_fm_dual_touch_point_struct_TP_CALI_TOP_RIGHT_LEFT_MAX = 
{
        {LCD_WIDTH / 20, LCD_HEIGHT / 20}, 
        {LCD_WIDTH * 19 / 20 - MMI_FM_CHECK_POINT_IMAGE_W, LCD_HEIGHT / 20} 
};

static mmi_fm_dual_touch_cali_struct g_fm_dual_touch_point_struct_TP_CALI_TOP_RIGHT_LEFT_MIN = 
{
        {LCD_WIDTH / 2 - MMI_FM_CHECK_POINT_IMAGE_W, LCD_HEIGHT / 20}, 
        {LCD_WIDTH / 2, LCD_HEIGHT / 20} 
};

static mmi_fm_dual_touch_cali_struct g_fm_dual_touch_point_struct_TP_CALI_DOWN_RIGHT_LEFT_MAX = 
{
        {LCD_WIDTH / 20, LCD_HEIGHT * 19 / 20 - MMI_FM_CHECK_POINT_IMAGE_H}, 
        {LCD_WIDTH * 19 / 20 - MMI_FM_CHECK_POINT_IMAGE_W, LCD_HEIGHT * 19 / 20 - MMI_FM_CHECK_POINT_IMAGE_H} 
};

static mmi_fm_dual_touch_cali_struct g_fm_dual_touch_point_struct_TP_CALI_DOWN_RIGHT_LEFT_MIN = 
{
        {LCD_WIDTH / 2 - MMI_FM_CHECK_POINT_IMAGE_W, LCD_HEIGHT * 19 / 20 - MMI_FM_CHECK_POINT_IMAGE_H}, 
        {LCD_WIDTH / 2, LCD_HEIGHT * 19 / 20 - MMI_FM_CHECK_POINT_IMAGE_H} 
};


static mmi_pen_point_struct g_fm_single_point[MMI_FM_SINGLE_DOUCH_CALI_POINTS_NO] = 
{
    {LCD_WIDTH / 20, LCD_HEIGHT / 20},
    {LCD_WIDTH / 2 - (MMI_FM_CHECK_POINT_IMAGE_W / 2), LCD_HEIGHT / 20},
    {LCD_WIDTH * 19 / 20 - MMI_FM_CHECK_POINT_IMAGE_W,   LCD_HEIGHT / 20},

    {LCD_WIDTH / 20, LCD_HEIGHT / 2 - (MMI_FM_CHECK_POINT_IMAGE_H / 2)},
    {LCD_WIDTH / 2 - (MMI_FM_CHECK_POINT_IMAGE_W / 2), LCD_HEIGHT / 2 - (MMI_FM_CHECK_POINT_IMAGE_H / 2)},
    {LCD_WIDTH * 19 / 20 - MMI_FM_CHECK_POINT_IMAGE_W,   LCD_HEIGHT / 2 - (MMI_FM_CHECK_POINT_IMAGE_H / 2)},

    {LCD_WIDTH / 20, LCD_HEIGHT * 19 / 20 - MMI_FM_CHECK_POINT_IMAGE_H},
    {LCD_WIDTH / 2 - (MMI_FM_CHECK_POINT_IMAGE_W / 2), LCD_HEIGHT * 19 / 20 - MMI_FM_CHECK_POINT_IMAGE_H},
    {LCD_WIDTH * 19 / 20 - MMI_FM_CHECK_POINT_IMAGE_W,   LCD_HEIGHT * 19 / 20 - MMI_FM_CHECK_POINT_IMAGE_H}
};


extern void mmi_fm_dual_touch_calibr_entry(void);
static void mmi_fm_dual_touch_rsp(void *msg);

static S32 mmi_fm_dual_touch_calibr_get_point(mmi_fm_dual_touch_cali_struct cali_location, mmi_fm_dual_touch_cali_point_enum point)
{
    if(point==mmi_pen_point_first_x)
    	return cali_location.first.x;
    else if(point==mmi_pen_point_first_y)
    	return cali_location.first.y;
    else if(point==mmi_pen_point_second_x)
    	return cali_location.second.x;
    else if(point==mmi_pen_point_second_y)
    	return cali_location.second.y;
}
static S32 mmi_fm_dual_touch_calibr_get_location(DCL_TP_CALIBRATION_MODE_Enum mode, mmi_fm_dual_touch_cali_point_enum point)
{
    switch (mode)
    {
	case DCL_TP_CALI_LEFT_TOP_RIGHT_DOWN_MAX:
		return mmi_fm_dual_touch_calibr_get_point(g_fm_dual_touch_point_struct_TP_CALI_LEFT_TOP_RIGHT_DOWN_MAX, point);
	case DCL_TP_CALI_LEFT_TOP_RIGHT_DOWN_MIN:
		return mmi_fm_dual_touch_calibr_get_point(g_fm_dual_touch_point_struct_TP_CALI_LEFT_TOP_RIGHT_DOWN_MIN, point);
	case DCL_TP_CALI_RIGHT_TOP_LEFT_DOWN_MAX:
		return mmi_fm_dual_touch_calibr_get_point(g_fm_dual_touch_point_struct_TP_CALI_RIGHT_TOP_LEFT_DOWN_MAX, point);
	case DCL_TP_CALI_RIGHT_TOP_LEFT_DOWN_MIN:
		return mmi_fm_dual_touch_calibr_get_point(g_fm_dual_touch_point_struct_TP_CALI_RIGHT_TOP_LEFT_DOWN_MIN, point);
	case DCL_TP_CALI_LEFT_TOP_DOWN_MAX:
		return mmi_fm_dual_touch_calibr_get_point(g_fm_dual_touch_point_struct_TP_CALI_LEFT_TOP_DOWN_MAX, point);
	case DCL_TP_CALI_LEFT_TOP_DOWN_MIN:
		return mmi_fm_dual_touch_calibr_get_point(g_fm_dual_touch_point_struct_TP_CALI_LEFT_TOP_DOWN_MIN, point);
	case DCL_TP_CALI_RIGHT_TOP_DOWN_MAX:
		return mmi_fm_dual_touch_calibr_get_point(g_fm_dual_touch_point_struct_TP_CALI_RIGHT_TOP_DOWN_MAX, point);
	case DCL_TP_CALI_RIGHT_TOP_DOWN_MIN:
		return mmi_fm_dual_touch_calibr_get_point(g_fm_dual_touch_point_struct_TP_CALI_RIGHT_TOP_DOWN_MIN, point);
	case DCL_TP_CALI_TOP_RIGHT_LEFT_MAX:
		return mmi_fm_dual_touch_calibr_get_point(g_fm_dual_touch_point_struct_TP_CALI_TOP_RIGHT_LEFT_MAX, point);
	case DCL_TP_CALI_TOP_RIGHT_LEFT_MIN:
		return mmi_fm_dual_touch_calibr_get_point(g_fm_dual_touch_point_struct_TP_CALI_TOP_RIGHT_LEFT_MIN, point);
	case DCL_TP_CALI_DOWN_RIGHT_LEFT_MAX:
		return mmi_fm_dual_touch_calibr_get_point(g_fm_dual_touch_point_struct_TP_CALI_DOWN_RIGHT_LEFT_MAX, point);
	case DCL_TP_CALI_DOWN_RIGHT_LEFT_MIN:
		return mmi_fm_dual_touch_calibr_get_point(g_fm_dual_touch_point_struct_TP_CALI_DOWN_RIGHT_LEFT_MIN, point);
    default:
		ASSERT(0);
		return 0;
}
}

/*****************************************************************************
  * FUNCTION
  *  mmi_fm_dual_touch_calibr_gproc
  * DESCRIPTION
  *  mmi_fm_dual_touch_calibr_gproc
  * PARAMETERS
  *  param            [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static MMI_RET mmi_fm_dual_touch_calibr_gproc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *evt = (cui_menu_event_struct *)param;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:

            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(evt->sender_id);
            break;
		case EVT_ID_GROUP_GOBACK_IN_END_KEY:
			g_cat_infor_cxt.doul_touch_index = DCL_TP_CALI_FINISH;
			break;
		case EVT_ID_GROUP_DEINIT:
			if (g_cat_infor_cxt.doul_touch_index == DCL_TP_CALI_FINISH)	
			{
			#ifdef __MTK_TARGET__
				ClearProtocolEventHandler(MSG_ID_TP_CALI_DONE);
			#endif
				DclSTS_Control(g_dual_fm_handle, STS_CMD_STOP_DUAL_CALI, NULL);		
				DclSTS_Close(g_dual_fm_handle);	
				g_cat_infor_cxt.doul_touch_index = 0;
			}
	
			break;

        default:
            break;        
    }
    return MMI_RET_OK;
}


void mmi_fm_dual_touch_scrn_rightkey (void)
{
	#ifdef __MTK_TARGET__
			ClearProtocolEventHandler(MSG_ID_TP_CALI_DONE);
	#endif
	DclSTS_Control(g_dual_fm_handle, STS_CMD_STOP_DUAL_CALI, NULL); 	
	DclSTS_Close(g_dual_fm_handle); 
	g_cat_infor_cxt.doul_touch_index = 0;
	mmi_frm_scrn_close(GRP_ID_ID_FM_DUAL_TOUCH_CALIBRATION, SCR_ID_FM_DUAL_TOUCH_CALIBRATION);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_fm_dual_touch_calibr_sproc
 * DESCRIPTION
 * mmi_fm_dual_touch_calibr_sproc
 * PARAMETERS
 *  evt    : [IN] mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_fm_dual_touch_calibr_sproc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (evt->evt_id)
	{
        case EVT_ID_SCRN_ACTIVE:
        	{   
				wgui_cat9011_show(
					g_cat_infor_cxt.point_num,
					g_cat_infor_cxt.check_point_list,
					g_cat_infor_cxt.flag/*1 is represent 2point, 0 is represent 9point*/
					);
				SetRightSoftkeyFunction(mmi_fm_dual_touch_scrn_rightkey, KEY_EVENT_UP);
				#if defined(__COSMOS_MMI_PACKAGE__)
		    	SetKeyHandler(mmi_fm_dual_touch_scrn_rightkey, KEY_BACK, KEY_EVENT_UP);
				#endif
        		break;
        	}
        
	}
    return MMI_RET_OK;
}


/* temp */


void mmi_fm_dual_touch_cal_next_scrn(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	if (mmi_frm_scrn_is_present(GRP_ID_ID_FM_DUAL_TOUCH_CALIBRATION, SCR_ID_FM_DUAL_TOUCH_CALIBRATION, MMI_FRM_NODE_ALL_FLAG))
	{
		mmi_frm_scrn_close(
	        GRP_ID_ID_FM_DUAL_TOUCH_CALIBRATION,
	        SCR_ID_FM_DUAL_TOUCH_CALIBRATION);
	}

    if (!mmi_frm_group_is_present(GRP_ID_FM_ROOT))
    {
        mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_FM_ROOT,NULL, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }   
    if (!mmi_frm_group_is_present(GRP_ID_ID_FM_DUAL_TOUCH_CALIBRATION))
    {
        mmi_frm_group_create_ex(
        GRP_ID_FM_ROOT,
        GRP_ID_ID_FM_DUAL_TOUCH_CALIBRATION,
        mmi_fm_dual_touch_calibr_gproc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }

    mmi_frm_scrn_create(
        GRP_ID_ID_FM_DUAL_TOUCH_CALIBRATION,
        SCR_ID_FM_DUAL_TOUCH_CALIBRATION,
        mmi_fm_dual_touch_calibr_sproc,
        NULL);


}

void mmi_fm_dual_pre_night_point(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static wgui_cat9011_check_point_struct night_point[9];
	U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* left top point */
	night_point[0].cp_response_x = 0;
	night_point[0].cp_response_y = 0;
	night_point[1].cp_response_x = LCD_WIDTH/ 3;
	night_point[1].cp_response_y = 0;
	night_point[2].cp_response_x = 2 * LCD_WIDTH / 3;
	night_point[2].cp_response_y = 0;

	night_point[3].cp_response_x = 0;
	night_point[3].cp_response_y = LCD_HEIGHT / 3;
	night_point[4].cp_response_x = LCD_WIDTH / 3;
	night_point[4].cp_response_y = LCD_HEIGHT / 3;
	night_point[5].cp_response_x = 2 * LCD_WIDTH/ 3;
	night_point[5].cp_response_y = LCD_HEIGHT / 3;

	night_point[6].cp_response_x = 0;
	night_point[6].cp_response_y = 2 * LCD_HEIGHT / 3;
	night_point[7].cp_response_x = LCD_WIDTH / 3;
	night_point[7].cp_response_y = 2 * LCD_HEIGHT / 3;
	night_point[8].cp_response_x = 2 * LCD_WIDTH / 3;
	night_point[8].cp_response_y = 2 * LCD_HEIGHT / 3;

	/* other infor */
	for (i = 0; i < 9; i++)
	{
		night_point[i].cp_pos_x = g_fm_single_point[i].x;
		night_point[i].cp_pos_y= g_fm_single_point[i].y;
		night_point[i].normal_img = (PU8)GetImage(IMG_FM_DUAL_TOUCH_NOR);
		night_point[i].pressed_img = (PU8)GetImage(IMG_FM_DUAL_TOUCH_DOWN);
		night_point[i].cp_response_h = LCD_HEIGHT / 3;
		night_point[i].cp_response_w = LCD_WIDTH / 3;
	}
	
	g_cat_infor_cxt.check_point_list = night_point;
	g_cat_infor_cxt.point_num = 9;
	g_cat_infor_cxt.flag = 0;/*1 is represent 2point, 0 is represent 9point*/
	mmi_fm_dual_touch_cal_next_scrn();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_setting_pen_calibration_rsp
 * DESCRIPTION
 *  Handle the response for calibration 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fm_dual_touch_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tp_cali_done_struct *rsp = (tp_cali_done_struct*) msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (rsp->result)
	{
		if ((rsp->mode !=  DCL_TP_CALI_SINGLE_POINT) && (rsp->mode != DCL_TP_CALI_FINISH))
		{
			g_dual_current_struct[0].normal_img = (PU8)GetImage(IMG_FM_DUAL_TOUCH_NOR);
			g_dual_current_struct[0].pressed_img = (PU8)GetImage(IMG_FM_DUAL_TOUCH_DOWN);
			g_dual_current_struct[0].cp_pos_x = mmi_fm_dual_touch_calibr_get_location(rsp->mode, mmi_pen_point_first_x);
			g_dual_current_struct[0].cp_pos_y = mmi_fm_dual_touch_calibr_get_location(rsp->mode, mmi_pen_point_first_y);
			g_dual_current_struct[0].cp_response_h = LCD_HEIGHT / 2;
			g_dual_current_struct[0].cp_response_w = LCD_WIDTH / 2;
			g_dual_current_struct[0].cp_state = WGUI_CAT9011_CP_NORMAL_STATE;
			
			g_dual_current_struct[1].normal_img = (PU8)GetImage(IMG_FM_DUAL_TOUCH_NOR);
			g_dual_current_struct[1].pressed_img = (PU8)GetImage(IMG_FM_DUAL_TOUCH_DOWN);
			g_dual_current_struct[1].cp_pos_x = mmi_fm_dual_touch_calibr_get_location(rsp->mode, mmi_pen_point_second_x);
			g_dual_current_struct[1].cp_pos_y = mmi_fm_dual_touch_calibr_get_location(rsp->mode, mmi_pen_point_second_y);
			g_dual_current_struct[1].cp_response_h = LCD_HEIGHT / 2;
			g_dual_current_struct[1].cp_response_w = LCD_WIDTH / 2;
			g_dual_current_struct[1].cp_state = WGUI_CAT9011_CP_NORMAL_STATE;
			g_cat_infor_cxt.check_point_list = g_dual_current_struct;
			g_cat_infor_cxt.point_num = 2;
	        g_cat_infor_cxt.flag = rsp->mode;
	        g_cat_infor_cxt.doul_touch_index = 0;
			
			switch (rsp->mode)
			{
			case DCL_TP_CALI_LEFT_TOP_RIGHT_DOWN_MAX:/*0*/
			case DCL_TP_CALI_LEFT_TOP_RIGHT_DOWN_MIN:/*1*/
					g_dual_current_struct[0].cp_response_x = 0;
				    g_dual_current_struct[0].cp_response_y = 0;
					g_dual_current_struct[1].cp_response_x = LCD_WIDTH / 2;
				    g_dual_current_struct[1].cp_response_y = LCD_HEIGHT / 2;
				break;
				
			case DCL_TP_CALI_RIGHT_TOP_LEFT_DOWN_MAX:/*2*/
			case DCL_TP_CALI_RIGHT_TOP_LEFT_DOWN_MIN:/*3*/
					g_dual_current_struct[0].cp_response_x = LCD_WIDTH / 2;
				    g_dual_current_struct[0].cp_response_y = 0;
					g_dual_current_struct[1].cp_response_x = 0;
				    g_dual_current_struct[1].cp_response_y = LCD_HEIGHT / 2;
				break;
				
			case DCL_TP_CALI_LEFT_TOP_DOWN_MAX:/*4*/		
			case DCL_TP_CALI_LEFT_TOP_DOWN_MIN:/*5*/
					g_dual_current_struct[0].cp_response_x = 0;
				    g_dual_current_struct[0].cp_response_y = 0;
					g_dual_current_struct[1].cp_response_x = 0;
				    g_dual_current_struct[1].cp_response_y = LCD_HEIGHT / 2;
				break;
				
			case DCL_TP_CALI_RIGHT_TOP_DOWN_MAX:/*6*/			
			case DCL_TP_CALI_RIGHT_TOP_DOWN_MIN:/*7*/
					g_dual_current_struct[0].cp_response_x = LCD_WIDTH / 2;
				    g_dual_current_struct[0].cp_response_y = 0;
					g_dual_current_struct[1].cp_response_x = LCD_WIDTH / 2;
				    g_dual_current_struct[1].cp_response_y = LCD_HEIGHT / 2;
				break;
				
			case DCL_TP_CALI_TOP_RIGHT_LEFT_MAX:/*8*/
			case DCL_TP_CALI_TOP_RIGHT_LEFT_MIN:/*9*/
					g_dual_current_struct[0].cp_response_x = 0;
				    g_dual_current_struct[0].cp_response_y = 0;
					g_dual_current_struct[1].cp_response_x = LCD_WIDTH / 2;
				    g_dual_current_struct[1].cp_response_y = 0;
				break;
				
			case DCL_TP_CALI_DOWN_RIGHT_LEFT_MAX:/*10*/
			case DCL_TP_CALI_DOWN_RIGHT_LEFT_MIN: /*11*/
					g_dual_current_struct[0].cp_response_x = 0;
				    g_dual_current_struct[0].cp_response_y = LCD_HEIGHT / 2;
					g_dual_current_struct[1].cp_response_x = LCD_WIDTH / 2;
				    g_dual_current_struct[1].cp_response_y = LCD_HEIGHT / 2;
				break;
				
			}
			mmi_fm_dual_touch_cal_next_scrn();
			memcpy(&g_dual_old_struct, &g_dual_current_struct, 2 * sizeof(wgui_cat9011_check_point_struct));
		}
		else
		{
			switch (rsp->mode)
			{
			case DCL_TP_CALI_FINISH:
				g_cat_infor_cxt.doul_touch_index = DCL_TP_CALI_FINISH;
				mmi_frm_group_close(GRP_ID_ID_FM_DUAL_TOUCH_CALIBRATION);
				break;
				
			case DCL_TP_CALI_SINGLE_POINT:
				mmi_fm_dual_pre_night_point();
				break;
			}
		}	
	}
    else
    {
    	if ((rsp->mode !=  DCL_TP_CALI_SINGLE_POINT) && (rsp->mode != DCL_TP_CALI_FINISH))
		{
			memcpy(&g_dual_current_struct, &g_dual_old_struct, 2 * sizeof(wgui_cat9011_check_point_struct));
			g_cat_infor_cxt.check_point_list = g_dual_current_struct;
			g_cat_infor_cxt.point_num = 2;
			g_cat_infor_cxt.flag = 1;
			mmi_fm_dual_touch_cal_next_scrn();
    	}
    	else if (rsp->mode == DCL_TP_CALI_SINGLE_POINT)
		{
			mmi_fm_dual_pre_night_point();
		}
    }
    
}


/*****************************************************************************
  * FUNCTION
  *  mmi_fm_dual_touch_calibr_entry
  * DESCRIPTION
  *  mmi_fm_dual_touch_calibr_entry
  * PARAMETERS
  *  void
  * RETURNS
  *  void 
  *****************************************************************************/
extern void mmi_fm_dual_touch_calibr_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* DCL_TP_CALI_SINGLE_POINT */
    mmi_fm_dual_pre_night_point();
	g_dual_fm_handle = DclSTS_Open(DCL_TS, 0);	
	DclSTS_Control(g_dual_fm_handle, STS_CMD_START_DUAL_CALI, NULL);

#ifdef __MTK_TARGET__
	SetProtocolEventHandler(mmi_fm_dual_touch_rsp, MSG_ID_TP_CALI_DONE);
#endif

    if (!mmi_frm_group_is_present(GRP_ID_FM_ROOT))
    {
        mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_FM_ROOT,NULL, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }   

    mmi_frm_group_create_ex(
        GRP_ID_FM_ROOT,
        GRP_ID_ID_FM_DUAL_TOUCH_CALIBRATION,
        mmi_fm_dual_touch_calibr_gproc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_create(
        GRP_ID_ID_FM_DUAL_TOUCH_CALIBRATION,
        SCR_ID_FM_DUAL_TOUCH_CALIBRATION,
        mmi_fm_dual_touch_calibr_sproc,
        NULL);
}

#endif
#endif
///////////////////////////////////////////////
#endif  /* __MMI_FACTORY_MODE__*/
