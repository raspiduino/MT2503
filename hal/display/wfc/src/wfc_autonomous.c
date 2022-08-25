/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010-2011
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
 *    wfc_autonomous.c
 *
 * Project:
 * --------
 *    MAUI/HAL/WFC/Autonomous
 *
 * Description:
 * ------------
 *    This file is the implementation of WFC autonomous mode.
 *
 * Author:
 * -------
 * -------
 *    
 *============================================================================
 * HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * $Log$
 * 
 * 07 24 2012 haitao.shang
 * removed!
 * .
 *
 * 07 18 2012 haitao.shang
 * removed!
 * .
 *
 * 06 13 2012 haitao.shang
 * removed!
 * .
 *
 * 03 08 2012 yinli.liang
 * removed!
 * .
 *
 * 03 01 2012 yinli.liang
 * removed!
 * .
 *
 * 02 23 2012 yinli.liang
 * removed!
 * .
 *
 * 01 05 2012 xiaoyong.ye
 * removed!
 * Cancel the timer and blt the last blt request immediately if has in wfcDeactivate() for fast exit automode.
 *
 * 09 23 2011 dong.guo
 * removed!
 * Add sssert in wfcactive and _wfc_change_stream_source_buffer.
 * exclude Lcd_profiling.h and it's reference
 *
 * 08 17 2011 zifeng.qiu
 * removed!
 * .
 *
 * 08 16 2011 matthew.chen
 * removed!
 * Remove ^M in the eol
 *
 * 07 26 2011 zifeng.qiu
 * removed!
 *   DDv2 On Modis Check In.
 *
 * 06 23 2011 bin.han
 * removed!
 * .
 *
 * 06 15 2011 bin.han
 * removed!
 * cleanup code and add comment
 *
 * 05 23 2011 zifeng.qiu
 * removed!
 * Revise timer-insert-mechanism.
 *
 * 05 20 2011 zifeng.qiu
 * removed!
 * .
 *
 * 04 22 2011 tianshu.qiu
 * removed!
 * .
 *
 * 04 21 2011 bin.han
 * removed!
 * .
 *
 * 03 12 2011 tianshu.qiu
 * removed!
 * .
 *
 * 03 11 2011 tianshu.qiu
 * removed!
 * .
 *
 * 03 03 2011 tianshu.qiu
 * removed!
 * .
 *
 * 03 02 2011 tianshu.qiu
 * removed!
 * .
 *
 * 02 23 2011 bin.han
 * removed!
 * .
 *
 * 01 17 2011 ke-ting.chen
 * removed!
 * Improve commit process.
 *
 * 01 12 2011 ke-ting.chen
 * removed!
 * Fix potential race condition.
 *
 * 01 07 2011 ke-ting.chen
 * removed!
 * Check-in VT support and timer frame insertion mechanism.
 *
 * 12 28 2010 ke-ting.chen
 * removed!
 * Check-in fast rotator mechanism for MT6253 and fix autonomous mode behavior for VT.
 *
 * 12 25 2010 ke-ting.chen
 * removed!
 * Resolve MT6253 60Qbit assert fail in wfcCommit.
 *
 * 12 24 2010 ke-ting.chen
 * removed!
 * Correct Autonomous Mode behavior.
 *
 * 12 22 2010 sophie.chen
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/******************************************************************************
 * Include directives
 ******************************************************************************/
#include <string.h>
   
#include <wfc\wfc.h>
#include <wfc\wfcext.h>
      
#include "common\owftypes.h"
#include "common\owfnativestream.h"
#include "common\owfimage.h"
      
#include "wfc\inc\wfc_internal.h"
#include "debug\inc\lcd_catcher_log.h"

#include "drv_comm.h" // KeTing: For drv timer
#if defined(__MTK_TARGET__)
#include "drv_hisr.h" // KeTing: For drv hisr 
#endif
#include "kal_release.h" // KeTing: For kal timer

#include "wfd\inc\wfd_common.h"
/******************************************************************************
 * Local variables
 ******************************************************************************/
// KeTing: The following two variables are for communication with HISR
// KeTing: They should be set and cleared at autonomous mode regist and deregist function
// KeTing: And should only be read by HISR
static WFCContextConfig *_pAutonomousModeContext = NULL;

// KeTing: These variables are for sync to element mechansim to compute the next timer trigger time
//static kal_uint32 _lastTriggerTime; // The last trigger time, don't care from timer or element
static kal_uint32 _lastElementTriggerTime; // The last trigger time from element
//static kal_uint32 _maxTriggerPeriod = 0; // The maximum trigger period
static kal_uint32 _maxRefreshTime = 0; // The maximum _wfdRefreshTime
kal_bool _timer_run_status = KAL_FALSE; // Whether timer is running or not
static kal_uint32 _currentRefreshRate = 0; //current refresh rate
// KeTing: This macro is to compute the safe margin for judging whether to insert a timer trigger frame while sync to element
// KeTing: Margin is 25% for now
//#define _WFC_AUTONOMOUS_TIMER_COMPUTE_SAFE_PERIOD_MARGIN(x) ((x) >> 2)

/******************************************************************************
 * Local function prototypes
 ******************************************************************************/
static void _wfc_autonomous_timer_handler(void *param);
static void _wfc_autonomous_activate_release_done_hisr(void);


/******************************************************************************
 * Local functions
 ******************************************************************************/
static void _wfc_autonomous_invoke_callback(WFCContextConfig *pContext, WFCContextEventTypeMTK event)
{
    kal_uint32 i;

    // TODO: [o] set event here... 
    for (i = WFC_CONTEXT_MM_CALLBACK_COUNT; i-- != 0; )
    {
        WFCCallbackType *pCallback = &(pContext->capturedRWAttrib->mmCallbacks[i]);
        if ((event == pCallback->event) && 
            (NULL != pCallback->cbfunc))
        {
            pCallback->cbfunc(event, pCallback->cbparam);
        }
    }
}
// KeTing: Change the buffer of stream source
// KeTing: Acquiring buffer should be prior than releasing, this is a protocal, don't change it
// KeTing: Return true if the change is success
static WFCboolean 
_wfc_change_stream_source_buffer(volatile WFCSourceConfig *pSource)
{
    kal_uint32 savedMask;
    OWFNativeStreamBuffer newBuffer;
    WFCboolean result = WFC_FALSE;

    WFCContextConfig *pContext = (WFCContextConfig *)pSource->ctxt;
    //WFCAutonomousSyncTriggerMTK syncTrigger = pContext->capturedRWAttrib->syncTrigger;

    DDV2CatcherLogL3D8(TRACE_DDV2_AUTOMODE, DDV2_TRC_WFCCHANGEBUFFER,
                                            drv_get_current_time(),
                                            (kal_uint32)(kal_get_current_thread_ID()),
                                            (kal_uint32)(pSource),
                                            pSource->element,
                                            pSource->stream, 0, 0, 0);
    wfcTrace3(WFCDBG____AUTO________CHANGE_BUFFER, (WFCuint)pSource, (WFCuint)pSource->element, (WFCuint)pSource->stream);

    //Dong: assert if change buffer when automode off
    if (WFC_AUTONOMOUS_STATE_OFF== pContext->_autonomousMode)
		ASSERT(0);
    
    savedMask = SaveAndSetIRQMask();
    {
        // KeTing: If this source is already in changing buffer process, don't change again to avoid race condition
        // KeTing: If we are using this source doing blt, we cannot allow the change or buffer tearing may occur
        if (WFC_TRUE == pSource->_isChangingBuffer || WFC_TRUE == pContext->_busy)
        {
            // KeTing: Try it again later if sync to timer
            //if (WFC_AUTONOMOUS_SYNC_TO_TIMER == syncTrigger)
            {
                pSource->_needChangeBuffer = WFC_TRUE;
            }
            RestoreIRQMask(savedMask);
            DDV2CatcherLogL3D2(TRACE_DDV2_WARNING, DDV2_TRC_WARNING_AUTOMODE_DROPFRAME,
                                                   drv_get_current_time(),
                                                   (kal_uint32)(kal_get_current_thread_ID()));
            goto Exit;
        }

        // Bin: to here means the changebuffer process can be executed (WFC not busy, prevous change buffer process is done)
        pSource->_isChangingBuffer = WFC_TRUE;
        pSource->_needChangeBuffer = WFC_FALSE;
    }
    RestoreIRQMask(savedMask);

    do
    {
        // Bin: should acquire new buffer first, since MM release one buffer just now
        newBuffer = owfNativeStreamAcquireReadBuffer(pSource->stream);

        if (OWF_INVALID_HANDLE != newBuffer)
        {
            // KeTing: Byebye old lover
            if (OWF_INVALID_HANDLE != pSource->_streamBuffer)
            {
                owfNativeStreamReleaseReadBuffer(pSource->stream, pSource->_streamBuffer);
				if((pContext->capturedRWAttrib->mmCallbacks[0].event)== WFC_CONTEXT_EVENT_REALSE_READ_BUFFER_DONE_CALLBACK_MTK || \
					(pContext->capturedRWAttrib->mmCallbacks[1].event)== WFC_CONTEXT_EVENT_REALSE_READ_BUFFER_DONE_CALLBACK_MTK)
				{
					//Yinli: activate hisr to callback to user. This callback indicates LCD already release read buffer, and MDP can get the buffer
   					//Yinli: This callback only be used when camera preview triple buffer currently.
   					_wfc_autonomous_activate_release_done_hisr();
				}
            }

            // KeTing: Hello new darling
            {
                OWFint width;
                OWFint height;
                OWFint stride;
                OWF_IMAGE_FORMAT format;
                OWFint pixelSize;
                void *data;

                /// get new buffer information and buffer address
                owfNativeStreamGetHeader(pSource->stream, &(width), &(height), &(stride), &(format), &(pixelSize));
                data = owfNativeStreamGetBufferPtr(pSource->stream, newBuffer);

                // KeTing: To gurantee WFC can use all new or all old settings, make it become an atomic operation
                savedMask = SaveAndSetIRQMask();
                {
                    // KeTing: Make my stream baby to become an image girl
                    OWF_IMAGE *image = (OWF_IMAGE *)(&(pSource->image));
                    image->width = width;
                    image->height = height;
                    image->stride = stride;
                    image->format = format;
                    image->pixelSize = pixelSize;
                    image->foreign = OWF_TRUE;
                    image->dataMax = height * stride;
                    image->data = data;
                    image->alpha = 0;
                    pSource->_streamBuffer = newBuffer;
                }
                RestoreIRQMask(savedMask);
            }

            result = WFC_TRUE;
        }

        savedMask = SaveAndSetIRQMask();
        // KeTing: _needChangeBuffer may be set to true during the changing buffer process while sync to timer
        if (WFC_FALSE == pSource->_needChangeBuffer)
        {
            // reset the _isChangingBuffer flag to finish the changing buffer process
            pSource->_isChangingBuffer = WFC_FALSE;
            RestoreIRQMask(savedMask);
            break;
        }
        pSource->_needChangeBuffer = WFC_FALSE;
        RestoreIRQMask(savedMask);  
    }while(1);

Exit:
    return result;
}


// Yinli: Acitvate the autonomous release done hisr
static void _wfc_autonomous_activate_release_done_hisr()
{
#if defined(__MTK_TARGET__)
	// Yinli: Activate autonomous hisr
	drv_active_hisr(DRV_LCD_RELEASE_DONE_HISR_ID);
#else
	// On Modis, there is no DRV_HISR, so use this way.
	_wfc_autonomous_release_done_hisr();
#endif

}
//Yinli: activate hisr to callback to user. This callback indicates LCD already release read buffer, and MDP can get the buffer
//Yinli: This callback only be used when camera preview triple buffer currently.
void _wfc_autonomous_release_done_hisr(void)
{


	 DDV2CatcherLogL3D2(TRACE_DDV2_AUTOMODE, DDV2_TRC_WFCAUTO_RELEASE_DONE_HISR,
									 drv_get_current_time(),
									 (kal_uint32)(kal_get_current_thread_ID()));
	 wfcTrace(WFCDBG____AUTO_REASELE_DONE____HISR);
	 
	//Yinli: callback to user. This callback  indicates LCD already release read buffer, and MDP can get the buffer
	//Yinli: This callback only be used when camera preview triple buffer currently.
	_wfc_autonomous_invoke_callback(_pAutonomousModeContext,WFC_CONTEXT_EVENT_REALSE_READ_BUFFER_DONE_CALLBACK_MTK);
}

// KeTing: Acitvate the autonomous blt hisr
// KeTing: Return true if successful activated
static WFCboolean _wfc_autonomous_activate_blt_hisr(WFCContextConfig *pContext)
{
    kal_uint32 savedMask = SaveAndSetIRQMask();
    if (WFC_TRUE == _wfc_is_wfd_busy(pContext))
    {
        RestoreIRQMask(savedMask);
        #if defined(DDV2_PERFORMANCE_PROFILING_SUPPORT)
        {
            extern kal_uint32 lcd_profiling_period_drop_frame_count;

            DDV2CatcherLogL3D0(TRACE_DDV2_PROFILING, LCD_TRC_PROFILING_DROP_FRAME_HAPPENED);
            lcd_profiling_period_drop_frame_count++;
        }
        #endif
        return WFC_FALSE;
    }

    // KeTing: Set the busy flag to prevent other source changing buffer
    // KeTing: In other words, we lock all the streams for this blt
    pContext->_busy = WFC_TRUE;
    RestoreIRQMask(savedMask);

    _wfc_set_context_frame_done_event(pContext, WFC_FALSE);

#if defined(__MTK_TARGET__)
    // KeTing: Activate autonomous hisr
    drv_active_hisr(DRV_LCD_WFC_HISR_ID);
#else
    // On Modis, there is no DRV_HISR, so use this way.
    _wfc_autonomous_mode_blt_hisr( );
#endif

    // KeTing: Record the hisr activate time to measure the current trigger period
    // KeTing: This variable is for sync to element
   // _lastTriggerTime = drv_get_current_time();

    return WFC_TRUE;
}

//Xiaoyong: When in wfcDeactivate(),a last blt request is valid, activate this HISR to blt
void _wfc_autonomous_activate_hisr_in_deactivate(WFCContextConfig *pContext)
{
	wfcTrace(WFCDBG____AUTO__ACT__HISR__IN_DEACT);
	_wfc_autonomous_activate_blt_hisr(pContext);	
}

// KeTing: When the autonomous trigger event is recieved, activate this HISR to blt
void _wfc_autonomous_mode_blt_hisr(void)
{
    WFC_ASSERT(NULL != _pAutonomousModeContext);
		 DDV2CatcherLogL3D2(TRACE_DDV2_AUTOMODE, DDV2_TRC_WFCAUTO_BLT_HISR,
												 drv_get_current_time(),
												 (kal_uint32)(kal_get_current_thread_ID()));
		 wfcTrace(WFCDBG____AUTO_BLT_____________HISR);

    // trigger WFD to blt
    _wfc_config_wfd_and_commit(_pAutonomousModeContext, WFC_FALSE);
    return;
}

static void _wfc_autonomous_timer_config_timer_and_start(WFCContextConfig *pContext);


// KeTing: Refresh the frame insertion mechanism
// KeTing: This function should be invoked for every change buffer of target sync element
static void _wfc_autonomous_timer_init_sync_to_element(WFCContextConfig *pContext)
{
    if (_timer_run_status == KAL_FALSE)
    {
        _wfc_autonomous_timer_config_timer_and_start(pContext);
    }

    _lastElementTriggerTime = drv_get_current_time();

}


static void _wfc_autonomous_timer_config_timer_and_start(WFCContextConfig *pContext)
{
    
    WFCint framerate = pContext->capturedRWAttrib->currRefreshRate;
    WFCuint i;
    kal_uint32 ap_expect_refresh_period;
    
    if (framerate <= 0)
    {
        return;
    }
	_currentRefreshRate = framerate;
    
    for (i = WFC_CONTEXT_MAX_INSERTED_ELEMENT; i-- != 0; )
    {
        WFCElementConfig* pElement = (WFCElementConfig*)pContext->capturedRWAttrib->_insertedElements[i];
        if ((WFC_INVALID_HANDLE != pElement) && (pElement->capturedRWAttrib->isDCLayer == WFC_TRUE))
        {
            return;
        }
    }

    // 1s == 217*4.615ms
    ap_expect_refresh_period = 217 / framerate;

    DDV2CatcherLogL3D4(TRACE_DDV2_AUTOMODE, DDV2_TRC_WFCAUTOMODE_SYNCTIMER_CONFIGTIMER,
                                            drv_get_current_time(),
                                            (kal_uint32)(kal_get_current_thread_ID()),
                                            (kal_uint32)(pContext),
                                            ap_expect_refresh_period);
    //Zifeng: Create a repeated timer to handle Sync-To-Timer
    _timer_run_status = KAL_TRUE;
    kal_set_timer(pContext->_timer, _wfc_autonomous_timer_handler, pContext, ap_expect_refresh_period, ap_expect_refresh_period);
}



// KeTing: When the autonomous timer expired, this function is invoked
static void _wfc_autonomous_timer_handler(void *param)
{
    WFCContextConfig *pContext = (WFCContextConfig *)param;
    WFCuint currentTime = drv_get_current_time();
	WFCint framerate = pContext->capturedRWAttrib->currRefreshRate;
	WFCboolean isValidBlt = WFC_TRUE;
    DDV2CatcherLogL3D2(TRACE_DDV2_AUTOMODE, DDV2_TRC_WFCTIMERHDLR,
                                    currentTime,
                                    (kal_uint32)(kal_get_current_thread_ID()));

    // KeTing: May be deactiveated during this kal timer tick
    if (WFC_AUTONOMOUS_STATE_ON == pContext->_autonomousMode)
    {
        //if(WFC_AUTONOMOUS_SYNC_TO_TIMER == pContext->capturedRWAttrib->autonomousSync.syncTrigger)
        if(WFC_AUTONOMOUS_SYNC_TO_TIMER == pContext->capturedRWAttrib->syncTrigger)
        {
#if defined(__MTK_TARGET__)
			//Yinli: MDP already modify framerate, so must update timer expired time and restart timer
			if(_currentRefreshRate != framerate && framerate > 0)
			{
				kal_uint32 ap_expect_refresh_period =  217 / framerate;
				if (_timer_run_status == KAL_TRUE)
				{
					kal_cancel_timer(pContext->_timer);
					;;
					//_timer_run_status == KAL_FALSE;
				}
				
				kal_set_timer(pContext->_timer, _wfc_autonomous_timer_handler, pContext,ap_expect_refresh_period, ap_expect_refresh_period);
				//_timer_run_status == KAL_TRUE;
			}
#endif			
#if !defined(__MTK_TARGET__)
            // On Modis, there is no re-secedule timer to use
            kal_cancel_timer(pContext->_timer);
#endif
			//Yinli: if sync-to-timer, but video layer source use stream and source->image.data invalid, will bypass this blt operation
			//Yinli: about two-video layer scenario, such as VTC, must check two-video layer, all of them source->image.data invalid, will bypass this blt operation
			//Yinli: this case only possible occur when camera preview triple buffer use sync-to-timer mode
			{
				WFCuint i;
				WFCuint countVideoLayer = 0;
				WFCuint countInvalidSource = 0;
				for (i = 0; i<WFC_CONTEXT_MAX_INSERTED_ELEMENT;i++ )
                {
                    WFCElementConfig* pElement = (WFCElementConfig*)pContext->capturedRWAttrib->_insertedElements[i];
                    if (WFC_INVALID_HANDLE != pElement && WFC_TRUE == pElement->capturedRWAttrib->isVideoLayer)
                    {
                    	WFCSourceConfig* pSource = (WFCSourceConfig*)pElement->capturedRWAttrib->source;
						++countVideoLayer;
                    	if(WFC_INVALID_HANDLE != pSource && pSource->useStream && NULL != pSource->stream && OWF_INVALID_HANDLE == pSource->image.data)
							++countInvalidSource;
                    }
                }
				if(countVideoLayer == countInvalidSource)//Yinli: all video layer source are invalid, so bypass this blt operation
				{
					isValidBlt = WFC_FALSE;
                    DDV2CatcherLogL3D4(TRACE_DDV2_AUTOMODE, DDV2_TRC_BYPASS_BLT_OPERATION,
                                        drv_get_current_time(),
                                        (kal_uint32)(kal_get_current_thread_ID()),
                                        (WFCContext)pContext,0);
				}
			}		
			if(isValidBlt)
			{
				_wfc_autonomous_activate_blt_hisr(pContext);	
			}
#if !defined(__MTK_TARGET__)
            kal_set_timer(pContext->_timer, _wfc_autonomous_timer_handler, pContext, 217 / framerate, 217 / framerate);
#endif
        }
        else //if(WFC_AUTONOMOUS_SYNC_TO_ELEMENT == pContext->capturedRWAttrib->autonomousSync.syncTrigger)
        {
            kal_uint32 savedMask;
            kal_uint32 lastElementTriggerTime;
            kal_uint32 maxRefreshTime;
            WFCuint timeFromLastElementTrigger;
            WFCuint elementTriggerExpectedPeriod;
            WFCuint timeToNextElementTrigger;
            //WFCuint safeRefreshTime;

            //Avoid race condition between Timer-Hisr and LCD-Hisr, MDP-Hisr
            savedMask = SaveAndSetIRQMask();
            lastElementTriggerTime = _lastElementTriggerTime;
            maxRefreshTime = _maxRefreshTime;
            RestoreIRQMask(savedMask);
            
            timeFromLastElementTrigger = drv_get_duration_tick(lastElementTriggerTime, currentTime);
            //elementTriggerExpectedPeriod = pContext->capturedRWAttrib->autonomousSync.period * 33;
            elementTriggerExpectedPeriod = pContext->capturedRWAttrib->period * 33;
			//safeRefreshTime = maxRefreshTime + _WFC_AUTONOMOUS_TIMER_COMPUTE_SAFE_PERIOD_MARGIN(maxRefreshTime);
            
            if (timeFromLastElementTrigger >= elementTriggerExpectedPeriod)
            {
                timeToNextElementTrigger = 0;
            }
            else
            {
                timeToNextElementTrigger = elementTriggerExpectedPeriod - timeFromLastElementTrigger;
            }
            
            //if (timeToNextElementTrigger > safeRefreshTime)
            if(timeToNextElementTrigger > maxRefreshTime)
            {
                WFCboolean success = _wfc_autonomous_activate_blt_hisr(pContext);
                if (WFC_TRUE == success)
                {
                    DDV2CatcherLogL3D2(TRACE_DDV2_AUTOMODE, DDV2_TRC_INSERTFRAME,
                                                            drv_get_current_time(),
                                                            (kal_uint32)(kal_get_current_thread_ID()));
                }
            }
            
        }//else //if(WFC_AUTONOMOUS_SYNC_TO_ELEMENT == pContext->capturedRWAttrib->autonomousSync.syncTrigger)
    }//if (WFC_AUTONOMOUS_STATE_ON == pContext->_autonomousMode)
}



// KeTing: Clear the autonomous mode configuration
WFCboolean
_wfc_clear_autonomous_sync_trigger(WFCContextConfig* pContext)
{
    if( _timer_run_status == KAL_TRUE)
    {
    kal_cancel_timer(pContext->_timer);
    _timer_run_status = KAL_FALSE;
	}
    return WFC_TRUE;
}



// KeTing: Set the autonomous sync trigger and parameter
static WFCboolean
_wfc_config_autonomous_sync_trigger(WFCContextConfig* pContext)
{
    //WFCAutonomousSyncTriggerMTK syncTrigger = pContext->capturedRWAttrib->autonomousSync.syncTrigger;
    WFCAutonomousSyncTriggerMTK syncTrigger = pContext->capturedRWAttrib->syncTrigger;
    WFCboolean result = WFC_TRUE;

    DDV2CatcherLogL3D8(TRACE_DDV2_AUTOMODE, DDV2_TRC_WFCCONFIGSYNCTRIGGER,
                                    drv_get_current_time(),
                                    (kal_uint32)(kal_get_current_thread_ID()),
                                    //pContext->capturedRWAttrib->autonomousSync.syncTrigger,
                                    //pContext->capturedRWAttrib->autonomousSync.period,
                                    //pContext->capturedRWAttrib->autonomousSync.element, 0, 0, 0);
                                    pContext->capturedRWAttrib->syncTrigger,
                                    pContext->capturedRWAttrib->period,
                                    pContext->capturedRWAttrib->sync_element, 0, 0, 0);
    wfcTrace3(WFCDBG____AUTO__CONFIG_AUTO_TRIGGER,
        //(WFCuint) pContext->capturedRWAttrib->autonomousSync.syncTrigger,
        //(WFCuint) pContext->capturedRWAttrib->autonomousSync.period,
        //(WFCuint) pContext->capturedRWAttrib->autonomousSync.element);
        (WFCuint) pContext->capturedRWAttrib->syncTrigger,
        (WFCuint) pContext->capturedRWAttrib->period,
        (WFCuint) pContext->capturedRWAttrib->sync_element);

    if (WFC_AUTONOMOUS_SYNC_TO_ELEMENT == syncTrigger)
    {
        //WFCElement element = (WFCElement) pContext->capturedRWAttrib->autonomousSync.element;
        WFCElement element = (WFCElement) pContext->capturedRWAttrib->sync_element;
        if (WFC_INVALID_HANDLE == element)
        {
            result = WFC_FALSE;
            goto Exit;
        }
    }
    else if (WFC_AUTONOMOUS_SYNC_TO_TIMER == syncTrigger)
    {
        WFCint framerate = pContext->capturedRWAttrib->currRefreshRate;

        if (framerate <= 0)
        {
            result = WFC_FALSE;
            goto Exit;
        }

        if (_timer_run_status == KAL_FALSE)
        {
            _wfc_autonomous_timer_config_timer_and_start(pContext);
        }
    }
    // KeTing: Currently not support, and perhaps we will never do it
    else if (WFC_AUTONOMOUS_SYNC_TO_VSYNC == syncTrigger)
    {
        result = WFC_FALSE;
        goto Exit;
    }
    // KeTing: When sync to none, we won't do any blt
    // KeTing: This is for free style autonomous sync control
    else if (WFC_AUTONOMOUS_SYNC_TO_NONE == syncTrigger)
    {
        kal_cancel_timer(pContext->_timer);
    }
    else
    {
        result = WFC_FALSE;
        goto Exit;
    }

Exit:
    return result;
}



/******************************************************************************
* WFC internal functions
******************************************************************************/

void _wfc_init_autonomous_mode_hisr()
{
#if defined(__MTK_TARGET__)
    DRV_Register_HISR(DRV_LCD_WFC_HISR_ID, _wfc_autonomous_mode_blt_hisr);
#endif
}



// Do anything you want to do when a frame is blt done
// This function should only be invoked in auto mode
void _wfc_autonomous_frame_done_callback(WFCContextConfig *pContext)
{
    WFCuint i;
    //WFCAutonomousSyncTriggerMTK syncTrigger = pContext->capturedRWAttrib->autonomousSync.syncTrigger;
    //WFCAutonomousSyncTriggerMTK syncTrigger = pContext->capturedRWAttrib->syncTrigger;
    //WFCuint currentTime = drv_get_current_time();
    //WFCuint _wfdRefreshTime;
    
    WFD_PORT* pPort = (WFD_PORT*) pContext->_port;
	WFCuint maxWaitTeTime = 33 * 1000 / pPort->config.refreshRate;	//tick by 32.768kHz, 1te time
    DDV2CatcherLogL3D4(TRACE_DDV2_AUTOMODE, DDV2_TRC_WFCFRAMEDONECALLBACK,
                                            drv_get_current_time(),
                                            (kal_uint32)(kal_get_current_thread_ID()),
                                            (kal_uint32)(pContext),
                                            (pContext->capturedRWAttrib->syncTrigger));
    
    //_wfdRefreshTime = drv_get_duration_tick(_lastTriggerTime, currentTime);
    
    //if (_wfdRefreshTime > _maxRefreshTime)
    //{
    //    _maxRefreshTime = _wfdRefreshTime;
    //}
    //Yinli: update _maxRefreshTime
    if(0 != pPort->hwRefreshTime)
    {   
    	WFCuint hwRefreshTime = pPort->hwRefreshTime;
		WFCuint wfdRefreshTime;
		if(pPort->isTEsyncMode == KAL_TRUE)
		{
			if(pPort->config.tearControlMode == WFD_Tear_Control_MODE_1TE_MTK)//1te mode
				wfdRefreshTime = maxWaitTeTime;
			else	//2te mode
				wfdRefreshTime = maxWaitTeTime + hwRefreshTime;
		}
		else
			wfdRefreshTime = hwRefreshTime;

		_maxRefreshTime = (_maxRefreshTime + wfdRefreshTime) >> 1;
	}
    
    //if (WFC_AUTONOMOUS_SYNC_TO_TIMER == syncTrigger)
    {
        // KeTing: Change buffer if the stream released her buffer while wfc busy
        for (i = 0; i < WFC_CONTEXT_MAX_INSERTED_ELEMENT; i++)
        {
            WFCElementConfig* pElement = (WFCElementConfig*) pContext->capturedRWAttrib->_insertedElements[i];

            if (WFC_INVALID_HANDLE != pElement)
            {
                WFCSourceConfig* pSource = (WFCSourceConfig*) pElement->capturedRWAttrib->source;

                if (WFC_INVALID_HANDLE != pSource)
                {
                    if (WFC_TRUE == pSource->useStream && WFC_TRUE == pSource->_needChangeBuffer)
                    {
                        _wfc_change_stream_source_buffer(pSource);
                    }
                }
            }
        }
    }

}



// Do anything you want to do when commit is invoked
// This function should only be invoked in auto mode
WFCboolean _wfc_autonomous_commit_callback(WFCContextConfig *pContext)
{
    // KeTing: The function is almost the same with _wfc_config_autonomous_sync_trigger in current implementation
    // KeTing: So I merged the difference to that function and invoked it here.
    return _wfc_config_autonomous_sync_trigger(pContext);
}



// KeTing: The callback function of a stream buffer is released.
void _wfc_stream_event_hdlr(
                            OWFNativeStreamType stream, 
                            OWFNativeStreamEvent event, 
                            void* param)
{
    WFCElementConfig *pElement = (WFCElementConfig *)param;
    WFCContextConfig *pContext = NULL;
    WFCSourceConfig *pSource = NULL;
    WFCAutonomousSyncTriggerMTK syncTrigger;

    WFCboolean changeBufferSuccess;

    WFC_ASSERT(NULL != param);

    // KeTing: Parse the parameters
    {
        pContext = (WFCContextConfig *)pElement->_context;
        pSource  = (WFCSourceConfig *)pElement->capturedRWAttrib->source;
        syncTrigger = pContext->capturedRWAttrib->syncTrigger;
    }

    // KeTing: Change buffer 
    //             1 release the read buffer in hand
    //             2 acquire the latest read buffer from stream buffer pool
    {
        changeBufferSuccess = _wfc_change_stream_source_buffer(pSource);
    }

    // KeTing: If sync to this element, commit to wfd
    if (WFC_AUTONOMOUS_STATE_ON == pContext->_autonomousMode)
    {
        if (WFC_AUTONOMOUS_SYNC_TO_ELEMENT == syncTrigger)
        {
            //if (pSource->element == (WFCElement)pContext->capturedRWAttrib->autonomousSync.element)
            if (pSource->element == (WFCElement)pContext->capturedRWAttrib->sync_element)
            {
                if (WFC_TRUE == changeBufferSuccess)
                {
                    WFCboolean success = WFC_FALSE;

                    // reconfig the timer which is used to frame insertion mechanism
                    _wfc_autonomous_timer_init_sync_to_element(pContext);

                    // activate HISR to config and trigger WFD to blt
                    success = _wfc_autonomous_activate_blt_hisr(pContext);
                    if (WFC_TRUE != success)
                    {
                        DDV2CatcherLogL3D2(TRACE_DDV2_AUTOMODE, DDV2_TRC_WFCAUTODROPFRAME,
                                                                drv_get_current_time(),
                                                                (kal_uint32)(kal_get_current_thread_ID()));
                        wfcTrace(WFCDBG____AUTO______HISR_DROP_FRAME);
                    }
                }
            }
        }
    }

}


// KeTing: Regist the specified context as in autonomous mode
// KeTing: Currently, we only allow at most one context in autonomous mode at any time
WFCboolean
_wfc_regist_autonomous_mode(WFCContextConfig *pContext)
{
    if ((NULL != _pAutonomousModeContext) && (pContext != _pAutonomousModeContext))
    {
        return WFC_FALSE;
    }

    //Zifeng: when enter Hw_update, we make the syncTrigger always be Sync-To-Timer
    //pContext->cachedRWAttrib->autonomousSync.syncTrigger = WFC_AUTONOMOUS_SYNC_TO_TIMER;
    //pContext->capturedRWAttrib->autonomousSync.syncTrigger = WFC_AUTONOMOUS_SYNC_TO_TIMER;
    pContext->cachedRWAttrib->syncTrigger = WFC_AUTONOMOUS_SYNC_TO_TIMER;
    pContext->capturedRWAttrib->syncTrigger = WFC_AUTONOMOUS_SYNC_TO_TIMER;
     
    if (WFC_FALSE == _wfc_config_autonomous_sync_trigger(pContext))
    {
        return WFC_FALSE;
    }

    {
		WFD_PORT* pPort = (WFD_PORT*) pContext->_port;
        _pAutonomousModeContext = pContext;
		if(pPort->config.tearControlMode == WFD_Tear_Control_MODE_1TE_MTK)//1te mode
       		 _maxRefreshTime =  33 * 1000 / pPort->config.refreshRate;	//tick by 32.768kHz, int to 1-te time
        else
			_maxRefreshTime = 2 * 33 * 1000 / pPort->config.refreshRate;	//tick by 32.768kHz, int to 2-te time
    }

    return WFC_TRUE;
}



WFCboolean
_wfc_deregist_autonomous_mode(WFCContextConfig *pContext)
{
    if (WFC_FALSE == _wfc_clear_autonomous_sync_trigger(pContext))
    {
        return WFC_FALSE;
    }

    {
        //_uint32 savedMask = SaveAndSetIRQMask();
        _pAutonomousModeContext = NULL;
        //RestoreIRQMask(savedMask);                 
    }

    return WFC_TRUE;
}

