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
*  MediaAppWidgetDef.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Define enum values to share between background players (Media player/Audio player)
*  
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#ifndef MEDIA_APP_WIDGET_DEF_H
#define MEDIA_APP_WIDGET_DEF_H

typedef enum
{
    MMI_WIDGET_PLAYER_TOTAL_DURATION,
    MMI_WIDGET_PLAYER_FILENAME,
    MMI_WIDGET_PLAYER_CUR_TIME,
    MMI_WIDGET_PLAYER_CUR_STATE,
    MMI_WIDGET_PLAYER_IS_PAUSE_DISABLED,
    MMI_WIDGET_PLAYER_FULLPATH,
    MMI_WIDGET_PLAYER_VOL
} mmi_widget_player_get_value_enum;

typedef enum
{
    MMI_WIDGET_PLAYER_PLAY_PAUSE,
    MMI_WIDGET_PLAYER_NEXT,
    MMI_WIDGET_PLAYER_PREV,
    MMI_WIDGET_PLAYER_STOP
} mmi_widget_player_button_enum;

typedef enum
{
    MMI_WIDGET_PLAYER_KEY_DOWN,
    MMI_WIDGET_PLAYER_KEY_UP,
    MMI_WIDGET_PLAYER_KEY_CANCELED
} mmi_widget_player_key_event_enum;

typedef enum
{
    MMI_WIDGET_PLAYER_STATUS_CHANGE_CALLBACK,
    MMI_WIDGET_PLAYER_MEDIA_CHANGE_CALLBACK,
    MMI_WIDGET_PLAYER_LIST_END_CALLBACK,
    MMI_WIDTET_PLAYER_RESET_TIME_CALLBACK,
    MMI_WIDGET_PLAYER_PLAY_END_CALLBACK,
    MMI_WIDTET_PLAYER_VOL_UP_CALLBACK,
    MMI_WIDTET_PLAYER_VOL_DOWN_CALLBACK,
    MMI_WIDTET_PLAYER_VOL_CHANGE_CALLBACK,

    MMI_WIDTET_PLAYER_CALLBACK_END
} mmi_widget_player_callback_enum;

#endif /* MEDIA_APP_WIDGET_DEF_H */ 

