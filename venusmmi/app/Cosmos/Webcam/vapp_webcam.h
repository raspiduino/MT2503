/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_webcam.h
 *
 * Project:
 * --------
 *  Venus
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_WEBCAM_H__
#define __VAPP_WEBCAM_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 
#if 1
#include "vfx_mc_include.h"
#include "vcp_include.h"

#include "vcp_Form.h"
#ifdef __cplusplus
extern "C"
{
#endif
#include "MMIDataType.h"
#ifdef __cplusplus
}
#endif
/***************************************************************************** 
 * Define
 *****************************************************************************/

class VappWebcamScreen;

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/

/***************************************************************************** 
 * Class VappSoundRecorderApp
 *****************************************************************************/
class VappWebcamApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappWebcamApp);

// Override
protected:
    // application is doing to die. release all your resource here.
    virtual void onDeinit();
    
// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
    static void cablePlugOut();
    
private:
    VappWebcamScreen *m_scr;
};

/***************************************************************************** 
 * Class VappWebcamScreen
 *****************************************************************************/
class VappWebcamScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappWebcamScreen);

public:
    enum
    {
        STATE_DISCONNECT,
        STATE_CONNECTED,
        STATE_LISTENING,
        STATE_PAUSE_LISTENING,
        STATE_RUNNING,
        STATE_PAUSE
    };
    
// Override
public:
    virtual void on1stReady();

    // While entering the screen to be active
    virtual void onEnter(VfxBool isBackward);
    
    // While leaving the screen to be inactive
    virtual void onExit(VfxBool isBackward);

    virtual void onDeinit();

public:
    void terminate();

private:
    void getPauseImages();

    void enterScr();

    void exitScr(VfxBool isBackward);

    static void eventHdlr(
        VfxS32 ret, 
        BOOL camera_workable,
        void* user_data
    );

    void onPopupButtonClicked(
        VfxObject* obj, 
        VfxId id
    );
        
    void displayPopup(
        VcpPopupTypeEnum type,         
        VfxU32 stringID
    );

    static mmi_ret cbEventHandler(
        mmi_event_struct *evt
    );

    VfxBool onKeyInput(
        VfxKeyEvent &event
    );

    void onTimerTick(
        VfxTimer *source
    );
private:
    static VfxU8 m_state;
    VfxBool m_isInCall;
    VcpConfirmPopup* m_popup;
};


/***************************************************************************** 
 * Class VappWebcamMainPage
 *****************************************************************************/
class VappWebcamPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappWebcamPage);
public:

    enum
    {
        INTERVAL_IMAGE_AND_STRING = 12
    };
    
    virtual void onInit();

    virtual void setBounds(const VfxRect &value);

	virtual void onQueryRotateEx(VfxScreenRotateParam &param);  //Replace onQueryRotate with onQueryRotateEx;

    VappWebcamPage();

private:
    VfxImageFrame *m_bg;
    VfxImageFrame *m_image;
    VfxTextFrame  *m_string;
};

#endif /* __MMI_WEBCAM__ */
#endif /* __VAPP_WEBCAM_H__ */

