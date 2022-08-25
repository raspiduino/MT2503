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
 * SndrecUI.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for sound recorder.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled bmy PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 04 02 2014 deepak.singhrawat
 * removed!
 * .
 *
 * 03 27 2014 deepak.singhrawat
 * removed!
 * .
 *
 * 12 19 2013 deepak.singhrawat
 * removed!
 * .
 *
 * 12 17 2013 deepak.singhrawat
 * removed!
 * .
 *
 * 12 12 2013 deepak.singhrawat
 * removed!
 * .
 *
 * 12 05 2013 deepak.singhrawat
 * removed!
 * .
 *
 * 11 19 2013 deepak.singhrawat
 * removed!
 * .
 *
 * 11 18 2013 deepak.singhrawat
 * removed!
 * .
 *
 * 11 12 2013 deepak.singhrawat
 * removed!
 * .
 *
 * 10 21 2013 deepak.singhrawat
 * removed!
 * .
 *
 * 10 15 2013 deepak.singhrawat
 * removed!
 * .
 *
 * 07 30 2013 deepak.singhrawat
 * removed!
 * .
 *
 * 03 22 2013 deepak.singhrawat
 * removed!
 * .
 *
 * 02 10 2013 deepak.singhrawat
 * removed!
 * .
 *
 * 02 06 2013 deepak.singhrawat
 * removed!
 * .
 *
 * 01 23 2013 deepak.singhrawat
 * removed!
 * Now Sound recorder in consistent with other app will exit and not enter if memory card removed and only mmory card supported projects
 *
 * 01 23 2013 deepak.singhrawat
 * removed!
 * .
 *
 * 12 25 2012 deepak.singhrawat
 * removed!
 * .
 *
 * 12 19 2012 deepak.singhrawat
 * removed!
 * .
 *
 * 07 09 2012 deepak.singhrawat
 * removed!
 * .
 *
 * 07 09 2012 deepak.singhrawat
 * removed!
 * .
 *
 * 06 13 2012 deepak.singhrawat
 * removed!
 * .
 *
 * 05 28 2012 deepak.singhrawat
 * removed!
 * .
 *
 * 05 25 2012 deepak.singhrawat
 * removed!
 * .
 *
 * 05 07 2012 deepak.singhrawat
 * removed!
 * .
 *
 * 05 04 2012 deepak.singhrawat
 * removed!
 * .
 *
 * 04 24 2012 deepak.singhrawat
 * removed!
 * .
 *
 * 04 19 2012 deepak.singhrawat
 * removed!
 * .
 *
 * 04 17 2012 deepak.singhrawat
 * removed!
 * Sound recorder added 41 character limit to sync with file manager
 *
 * 04 17 2012 deepak.singhrawat
 * removed!
 * To show ? from sound recorder end
 *
 * 04 16 2012 deepak.singhrawat
 * removed!
 * This fix for the issue to show please record or record button is enabled when we do nex prev during playing
 *
 * 04 11 2012 deepak.singhrawat
 * removed!
 * .
 *
 * 04 10 2012 deepak.singhrawat
 * removed!
 * .
 *
 * 04 04 2012 satish.chandra
 * removed!
 * .
 *
 * 03 29 2012 deepak.singhrawat
 * removed!
 * .
 *
 * 03 21 2012 boli.li
 * removed!
 * .
 *
 * 03 21 2012 boli.li
 * removed!
 * .
 *
 * 03 14 2012 satish.chandra
 * removed!
 * .
 *
 * 03 13 2012 boli.li
 * removed!
 * .
 *
 * 02 22 2012 boli.li
 * removed!
 * .
 *
 * 02 21 2012 boli.li
 * removed!
 * .
 *
 * 02 16 2012 boli.li
 * removed!
 * .
 *
 * 02 16 2012 boli.li
 * removed!
 * .
 *
 * 02 14 2012 boli.li
 * removed!
 * .
 *
 * 02 08 2012 boli.li
 * removed!
 * .
 *
 * 02 07 2012 boli.li
 * removed!
 * .
 *
 * 01 18 2012 boli.li
 * removed!
 * .
 *
 * 12 19 2011 boli.li
 * removed!
 * .
 *
 * 12 03 2011 boli.li
 * removed!
 * .
 *
 * 11 15 2011 boli.li
 * removed!
 * .
 *
 * 11 02 2011 ruoyao.liu
 * removed!
 * .
 *
 * 10 25 2011 ruoyao.liu
 * removed!
 * .
 *
 * 10 21 2011 ruoyao.liu
 * removed!
 * .
 *
 * 10 11 2011 ruoyao.liu
 * removed!
 * .
 *
 * 10 10 2011 ruoyao.liu
 * removed!
 * .
 *
 * 09 28 2011 ruoyao.liu
 * removed!
 * .
 *
 * 09 23 2011 ruoyao.liu
 * removed!
 * .
 *
 * 09 13 2011 bingbing.ma
 * removed!
 * .
 *
 * 09 05 2011 bingbing.ma
 * removed!
 * .
 *
 * 09 05 2011 bingbing.ma
 * removed!
 * .
 *
 * 09 01 2011 bingbing.ma
 * removed!
 * .
 *
 * 09 01 2011 bingbing.ma
 * removed!
 * .
 *
 * 08 31 2011 bingbing.ma
 * removed!
 * .
 *
 * 08 24 2011 bingbing.ma
 * removed!
 * .
 *
 * 08 23 2011 bingbing.ma
 * removed!
 * .
 *
 * 08 23 2011 bingbing.ma
 * removed!
 * .
 *
 * 08 12 2011 bingbing.ma
 * removed!
 * .
 *
 * 08 09 2011 bingbing.ma
 * removed!
 * .
 *
 * 08 04 2011 bingbing.ma
 * removed!
 * .
 *
 * 07 29 2011 bingbing.ma
 * removed!
 * .
 *
 * 07 19 2011 bingbing.ma
 * removed!
 * .
 *
 * 07 18 2011 bingbing.ma
 * removed!
 * .
 *
 * 07 05 2011 bingbing.ma
 * removed!
 * .
 *
 * 06 24 2011 bingbing.ma
 * removed!
 * .
 *
 * 06 23 2011 bingbing.ma
 * removed!
 * .
 *
 * 06 21 2011 bingbing.ma
 * removed!
 * .
 *
 * 06 21 2011 bingbing.ma
 * removed!
 * .
 *
 * 06 20 2011 bingbing.ma
 * removed!
 * .
 *
 * 06 16 2011 bingbing.ma
 * removed!
 * .
 *
 * 06 16 2011 bingbing.ma
 * removed!
 * .
 *
 * 06 15 2011 bingbing.ma
 * removed!
 * .
 *
 * 06 14 2011 bingbing.ma
 * removed!
 * .
 *
 * 06 13 2011 bingbing.ma
 * removed!
 * .
 *
 * 06 13 2011 bingbing.ma
 * removed!
 * .
 *
 * 06 12 2011 bingbing.ma
 * removed!
 * .
 *
 * 06 12 2011 bingbing.ma
 * removed!
 * .
 *
 * 06 10 2011 bingbing.ma
 * removed!
 * .
 *
 * 06 07 2011 bingbing.ma
 * removed!
 * .
 *
 * 06 07 2011 bingbing.ma
 * removed!
 * .
 *
 * 04 11 2011 satish.chandra
 * removed!
 * .
 *
 * 03 09 2011 satish.chandra
 * removed!
 * .
 *
 * 02 16 2011 satish.chandra
 * removed!
 * .
 *
 * 01 31 2011 satish.chandra
 * removed!
 * .
 *
 * 01 20 2011 satish.chandra
 * removed!
 * .
 *
 * 01 12 2011 konark.mehra
 * removed!
 * Resolve sanity fail..
 *
 * 01 11 2011 konark.mehra
 * removed!
 * for media volume, use MDI_VOLUME_MEDIA instead of speech
 *
 * 01 05 2011 satish.chandra
 * removed!
 * .
 *
 * 12 22 2010 satish.chandra
 * removed!
 * .
 *
 * 12 18 2010 satish.chandra
 * removed!
 * .
 *
 * 12 14 2010 satish.chandra
 * removed!
 * .
 *
 * 12 09 2010 satish.chandra
 * removed!
 * .
 *
 * 12 01 2010 cs.kuo
 * removed!
 * .
 *
 * 11 30 2010 satish.chandra
 * removed!
 * .
 *
 * 11 29 2010 satish.chandra
 * removed!
 * .
 *
 * 11 26 2010 satish.chandra
 * removed!
 * .
 *
 * 11 26 2010 aidan.hung
 * removed!
 * Remove Pluto FMGR resource file on COSMOS project
 *
 * 11 25 2010 satish.chandra
 * removed!
 * .
 *
 * 11 24 2010 satish.chandra
 * removed!
 * .
 *
 * 11 23 2010 satish.chandra
 * removed!
 * .
 *
 * 11 18 2010 satish.chandra
 * removed!
 * .
 *
 * 11 18 2010 satish.chandra
 * removed!
 * .
 *
 * 11 16 2010 satish.chandra
 * removed!
 * .
 *
 * 11 15 2010 satish.chandra
 * removed!
 * .
 *
 * 11 15 2010 satish.chandra
 * removed!
 * .
 *
 * 11 01 2010 satish.chandra
 * removed!
 * .
 *
 * 10 27 2010 satish.chandra
 * removed!
 * .
 *
 * 10 27 2010 satish.chandra
 * removed!
 * .
 *
 * 10 27 2010 satish.chandra
 * removed!
 * .
 *
 * 10 26 2010 satish.chandra
 * removed!
 * .
 *
 * 10 25 2010 satish.chandra
 * removed!
 * removed!
 * .
 *
 * 10 20 2010 satish.chandra
 * removed!
 * .
 *
 * 10 19 2010 satish.chandra
 * removed!
 * .
 *
 * 10 18 2010 satish.chandra
 * removed!
 * .
 *
 * 10 15 2010 satish.chandra
 * removed!
 * .
 *
 * 10 12 2010 satish.chandra
 * removed!
 * .
 *
 * 10 04 2010 satish.chandra
 * removed!
 * .
 *
 * 10 04 2010 satish.chandra
 * removed!
 * .
 *
 * 09 23 2010 satish.chandra
 * removed!
 * .
 *
 * 09 20 2010 satish.chandra
 * removed!
 * .
 *
 * 09 20 2010 satish.chandra
 * removed!
 * .
 *
 * 09 16 2010 satish.chandra
 * removed!
 * .
 *
 * 09 16 2010 satish.chandra
 * removed!
 * .
 *
 * 09 10 2010 satish.chandra
 * removed!
 * .
 *
 * 09 04 2010 satish.chandra
 * removed!
 * .
 *
 * 09 04 2010 satish.chandra
 * removed!
 * .
 *
 * 09 02 2010 satish.chandra
 * removed!
 * .
 *
 * 09 02 2010 satish.chandra
 * removed!
 * .
 *
 * 09 01 2010 satish.chandra
 * removed!
 * .
 *
 * 08 31 2010 satish.chandra
 * removed!
 * .
 *
 * 08 31 2010 satish.chandra
 * removed!
 * .
 *
 * 08 30 2010 satish.chandra
 * removed!
 * .
 *
 * 08 29 2010 satish.chandra
 * removed!
 * .
 *
 * 08 28 2010 satish.chandra
 * removed!
 * .
 *
 * 08 28 2010 satish.chandra
 * removed!
 * .
 *
 * 08 28 2010 satish.chandra
 * removed!
 * .
 *
 * 08 28 2010 satish.chandra
 * removed!
 * .
 *
 * 08 18 2010 satish.chandra
 * removed!
 * .
 *
 * 08 11 2010 satish.chandra
 * removed!
 * .
 *
 * 08 10 2010 satish.chandra
 * removed!
 * .
 *
 * 08 10 2010 satish.chandra
 * removed!
 * .
 *
 * 08 06 2010 satish.chandra
 * removed!
 * .
 *
 * 08 06 2010 satish.chandra
 * removed!
 * .
 *
 * 08 05 2010 satish.chandra
 * removed!
 * .
 *
 * 08 04 2010 satish.chandra
 * removed!
 * .
 *
 * 08 04 2010 satish.chandra
 * removed!
 * .
 *
 * 08 04 2010 satish.chandra
 * removed!
 * .
 *
 * 08 03 2010 satish.chandra
 * removed!
 * .
 *
 * 07 30 2010 satish.chandra
 * removed!
 * .
 *
 * 07 27 2010 satish.chandra
 * removed!
 * .
 *
 * 07 27 2010 satish.chandra
 * removed!
 * .
 *
 * 07 27 2010 satish.chandra
 * removed!
 * .
 *
 * 07 26 2010 satish.chandra
 * removed!
 * .
 *
 * 07 26 2010 satish.chandra
 * removed!
 * .
 *
 * 07 26 2010 satish.chandra
 * removed!
 * .
 *
 * 07 26 2010 satish.chandra
 * removed!
 * .
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * redraw lsk when up hadler is called
 *
 * removed!
 * removed!
 * play lsk handler handling for idle state added
 *
 * removed!
 * removed!
 * str_global_invalid_format string used
 *
 * removed!
 * removed!
 * argument type of mmi_sndrec_get_res_string chnged from U8 to mdi_result
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Else condition added in mmi_sndrec_auto_record_switch when auto record is off
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * tone added again
 *
 * removed!
 * removed!
 * tone removed
 *
 * removed!
 * removed!
 * making voda soln as common soln
 *
 * removed!
 * removed!
 * daily build
 * 
 *
 * removed!
 * removed!
 * CTM call check
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * daily build maui
 *
 * removed!
 * removed!
 * exit function for save screen defined
 *
 * removed!
 * removed!
 * popup rules implemented
 *
 * removed!
 * removed!
 * editor screen deleted
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_features.h"
#if defined(__MMI_SOUND_RECORDER__)
#include "mmi_rp_srv_prof_def.h"
#include "FileMgrSrvGProt.h"
#include "commonscreens.h"
#include "RightsMgrGProt.h"
#include "mdi_datatype.h"
#include "Mdi_audio.h"
#include "dcl.h"
//#include "GpioSrvGprot.h"
#include "GpioSrvGProt.h"

#include "Fmt_struct.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif
/*For UCM Generic change*/
#include "UcmSrvGprot.h"
/*ucm changes end*/
#include "UCMGProt.h"
#include "Conversions.h"
#include "SndrecUI.h"

#ifdef __CTM_SUPPORT__
#include "CallSetSrvGprot.h"
#endif 

#ifdef __DM_LAWMO_SUPPORT__
#include "Dmuigprot.h"
#endif
#include "SndrecProt.h"
#include "SndrecDef.h"
#include "SndrecType.h"
#include "SndrecUtil.h"
#include "SndrecMsg.h"
#include "SoundRecSrvGProt.h"
#include "ProfilesSrvGprot.h"
#include "MenuCuiGprot.h"
#include "InlineCuiGprot.h"
#include "FileMgrCUIGProt.h"

#include "MMIDataType.h"
#include "mmi_rp_app_soundrecorder_def.h"
#include "GlobalResDef.h"
#include "wgui_categories_list.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "Unicodexdcl.h"
#include "gui_data_types.h"
#include "kal_trace.h"
#include "stack_config.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mmi_media_app_trc.h"
#include "GpioSrvGprot.h"
#include "device.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "AlertScreen.h"
#include "fs_func.h"
#include "fs_type.h"
#include "mmi_frm_events_gprot.h"
#include "fs_errcode.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
#include "wgui_categories_multimedia.h"
#include "mmi_cb_mgr_gprot.h"
#include "gui.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_rp_file_type_def.h"
#include "CustMenuRes.h"
#include "CustDataRes.h"
#include "mmi_rp_app_filemanager_def.h"
#include "CommonScreensResDef.h"
#include "mmi_rp_srv_filemanager_def.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "wgui_inline_edit.h"
#include "FileMgrResDef.h"
#include "inlinecuigprot.h"
#include "SndrecDraw.h"
#include "MediaAppGprot.h"
#include "mmi_rp_srv_soundrec_def.h"
#include "mmi_rp_app_profiles_def.h"
#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
#include "ScrLockerGprot.h"
#endif

/* For DCM */
#if defined (__DCM_WITH_COMPRESSION_MMI_AP__) && defined(__MTK_TARGET__)
#include "mmi_ap_dcm_config.h"
#endif

/****************************************************************************
* Global Variable
*****************************************************************************/
#ifdef __MMI_AP_DCM_SNDREC__
#pragma arm section rodata = "DYNAMIC_CODE_SNDREC_RODATA",code = "DYNAMIC_CODE_SNDREC_ROCODE"
#endif

mmi_sndrec_cntx g_sndrec_cntx;
extern U32 g_size_limit = 0;
extern U32 g_time_limit = 0;

#ifdef __MMI_SNDREC_SKIN__
extern const mmi_sndrec_draw_skin_struct g_sndrec_record_skins[];
#endif 

MMI_BOOL g_sndrec_wait_next_prev = MMI_FALSE;
/* This global variable is added to avoide showing record idle screen when doing next or previous playing of song */
MMI_BOOL g_sndrec_no_idle_next_prev = MMI_FALSE;

/****************************************************************************
* Static Variable
*****************************************************************************/
#if defined(__MMI_OP02_LEMEI__)
static U8 g_set_updated_info = MMI_FALSE;
#endif

static WCHAR extBuffer[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];

const static U16 g_sndrec_quality_id[] = {STR_GLOBAL_LOW, STR_GLOBAL_HIGH};;
static mmi_id g_current_id = 0;
FuncPtr g_sndrec_mc_cb = NULL;
void (*mmi_sndrec_sms_record_callback) (BOOL result, U16 *filepath);

#ifdef __MMI_OP12_SNDREC_STYLE__
static MMI_BOOL mmi_sndrec_preview_flag = MMI_FALSE;
#endif

static U16 need_save_later = 0;

#ifdef __MMI_AP_DCM_SNDREC__
#pragma arm section rodata , code
#endif

#if defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
MMI_BOOL mmi_sndrec_is_play_flag = MMI_FALSE;
MMI_BOOL mmi_sndrec_is_play_goback = MMI_FALSE; /*when click rsk back to pre list, set to true.*/
#endif

/****************************************************************************
* Function Forward Declaration
*****************************************************************************/
#if defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
void mmi_entry_sndrec_pre_list(void);
#endif

#if 0    /* Auto Record Phased Out */
/* under construction !*/
#endif
static void mmi_sndrec_entry_record_from_other_app_ex(void);
void mmi_sndrec_pre_entry_main_screen(void);
void mmi_sndrec_entry_record_from_other_app(
        U16 *file_path,
        U32 size_limit,
        U32 time_limit,
        void (*callback_func) (BOOL result, U16 *filepath));

#ifdef __MMI_APP_MANAGER_SUPPORT__
MMI_ID mmi_sndrec_launch_function(void *param, U32 param_size);
#endif

#ifdef __MMI_OP12_SNDREC_STYLE__
static mmi_ret mmi_sndrec_save_option_rename_proc(mmi_event_struct *evt);
static void mmi_sndrec_entry_save_option(void);
static void mmi_sndrec_save_option_cancel(void);
static void mmi_sndrec_save_option_discard_query(void);
static void mmi_sndrec_save_option_discard_confirm(void);
static void mmi_sndrec_save_option_discard_cancel(void);
static void mmi_sndrec_save_option_play(void);
static void mmi_sndrec_preview_end_cb(MDI_RESULT result);
static void mmi_sndrec_save_option_entry_rename(void);
static void mmi_sndrec_save_option_rename_option(void);
static void mmi_sndrec_save_option_rename_save();
#endif

static void mmi_sndrec_get_new_file(mmi_sndrec_format_ext ext);

#if 0  //__VM_CODEC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

static void mmi_sndrec_adjust_speech_volume(MMI_BOOL is_decr);
static void mmi_sndrec_save_speech_volume(void);
/* since SLIM sound recorder will not play audio file no need to adjust media volume  */
#ifdef __MMI_SNDREC_SKIN__
static void mmi_sndrec_adjust_media_volume(MMI_BOOL is_decr);
#endif

static void mmi_sndrec_delete_self(void);
static void mmi_sndrec_entry_main_screen(void);
#ifdef __MMI_SNDREC_SKIN__
static void mmi_sndrec_mainscr_lsk_down_hdlr(void);
static void mmi_sndrec_mainscr_rsk_down_hdlr(void);
static void mmi_sndrec_registe_keys(void);
static void mmi_sndrec_press_record_btn(void);
static void mmi_sndrec_press_play_btn(void);
static void mmi_sndrec_press_prev_btn(void);
static void mmi_sndrec_press_next_btn(void);
#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
static void mmi_sndrec_press_stop_btn(void);
#endif
static void mmi_sndrec_exit_reclist_create(void);
static void mmi_sndrec_reclist_cancel(void);
static void mmi_sndrec_pre_play_next(MMI_BOOL isNext);
static void mmi_sndrec_play_next(void);
static void mmi_sndrec_play_next_req(void);
static void mmi_sndrec_play_end_cb(MDI_RESULT result);
#else /* __MMI_SNDREC_SKIN__ */
static void mmi_sndrec_left_key_main(void);
static void mmi_sndrec_right_key_main(void);
#if 0 //__MMI_BASIC_UI_STYLE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /* __MMI_SNDREC_SKIN__ */
static void mmi_sndrec_exit_main_screen(void);
#if 0
/* under construction !*/
/* under construction !*/
#endif
#ifdef __MMI_OP02_LEMEI__
static void mmi_sndrec_abort_save(void);
#endif
static void mmi_sndrec_delete_main_screen(void);
static void mmi_sndrec_set_option_menu(mmi_id parent_menu_id);
static void mmi_sndrec_entry_option_screen(void);
static void mmi_sndrec_rec_play_select(void);
static void mmi_sndrec_list_play_select(void);
#ifndef __MMI_SNDREC_SLIM__
static void mmi_sndrec_append(void);
#endif
static void mmi_sndrec_entry_rename_save(MMI_ID cui_id);
static void mmi_sndrec_entry_delete_cnf(void);
static void mmi_sndrec_entry_record_list(void);
static void mmi_sndrec_pre_entry_setting_screen(void);
static void mmi_sndrec_entry_setting_screen(void);
static void mmi_sndrec_pre_save_setting(void);
static void mmi_sndrec_save_setting(void);
static void mmi_sndrec_clear_file_name(void);

static void mmi_sndrec_setting_init(void);

static void mmi_sndrec_entry_save_query(void);
static void mmi_sndrec_entry_save(void);
static void mmi_sndrec_entry_edit_name(void);
static void mmi_sndrec_entry_delete_animation(void);

#if 0 //__VM_CODEC_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif

static void mmi_sndrec_new_record_hdlr(void);
static MMI_BOOL mmi_sndrec_app_check_drive_status(CHAR drive);
static MMI_BOOL mmi_sndrec_check_file_type(const U16 *file, const U16 *strtype);
static MMI_BOOL mmi_sndrec_useby_others_with_cb(void);
static MMI_BOOL mmi_sndrec_check_folder_valid(void);
static MMI_BOOL mmi_sndrec_check_drive_is_external_drive(CHAR , S32 *);
static MMI_BOOL mmi_sndrec_entry_mc_rules(void);
static MMI_BOOL mmi_sndrec_is_settings_changed(void);
static MMI_BOOL mmi_sndrec_new_record(void);
static S32 mmi_sndrec_types_get_use_option_menu(void);
static S32 mmi_sndrec_types_get_send_option_menu(void);
static mmi_ret mmi_sndrec_entry_edit_name_proc(mmi_event_struct *evt);
static mmi_ret mmi_sndrec_entry_setting_screen_inline_cui_proc(mmi_event_struct *evt);
static mmi_ret mmi_sndrec_entry_record_list_proc(mmi_event_struct *evt);
/* For Low cost Slim, audio player is used for playing so no need of volume sync bt callback */
#ifdef __MMI_SNDREC_SKIN__
#ifdef __BT_SPK_VOL_CONTROL__
static MMI_BOOL mmi_sndrec_hfp_volume_callback(U8 volume, MMI_BOOL is_mute);
#endif
#endif
/****************************************************************************
* Function Body
*****************************************************************************/

/* External API Start - Not wrapped with DCM */

MMI_BOOL mmi_sndrec_is_in_recording(void)
{
    if ((g_sndrec_cntx.record.state == MMI_SNDREC_REC_STATE) || 
        (g_sndrec_cntx.record.state == MMI_SNDREC_REC_PAUSE_STATE))
    {
        return MMI_TRUE;      
    }    
    else
    {
        return MMI_FALSE;
    }
}

MMI_BOOL mmi_sndrec_is_in_app(void)
{
   if(mmi_frm_group_get_active_id() == GRP_ID_SNDREC_MAIN)
   {
        return MMI_TRUE;
   }

    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_launch_function
 * DESCRIPTION
 *  launch sndrec for cosmos_fte
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_APP_MANAGER_SUPPORT__
MMI_ID mmi_sndrec_launch_function(void *param, U32 param_size)
{
    mmi_sndrec_pre_entry_main_screen();
    if(MMI_TRUE == mmi_frm_group_is_present(GRP_ID_SNDREC_MAIN))
    {
        return GRP_ID_SNDREC_MAIN;
    }
    return GRP_ID_INVALID;
}
#endif

#ifdef __MMI_BT_DIALER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_bt_music_disconnect_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_bt_music_disconnect_callback(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        mmi_sndrec_pre_entry_main_screen();
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_pre_entry_main_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_pre_entry_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 filepath[MMI_SNDREC_PATH_LEN];
    //S32 result;
    S32 attribute;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__MMI_BT_MUSIC__) || defined(__MMI_AUDIO_PLAYER_BT__) || defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__))
    if (mmi_bt_music_check_connection())
    {
        mmi_bt_music_disconnect(mmi_sndrec_bt_music_disconnect_callback);
        //return;
    }
#endif
    
    /* Load DCM for Sound Recorder */
#ifdef __MMI_AP_DCM_SNDREC__
    mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_SNDREC);
#endif

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_PRE_ENTRY_MAIN_SCREEN);

    if (mmi_sndrec_check_usb_mode())
    {
        /* Unload DCM for Sound Recorder */
    #ifdef __MMI_AP_DCM_SNDREC__
        mmi_ap_send_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_SNDREC);
    #endif
        return;
    }

#if 0    /* Auto Record Phased Out */
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_AP_DCM_SNDREC__
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
#endif

    /* Check for Public drive - when only memory card (card is mapped to public drive) do not enter app */
#ifndef __MMI_SNDREC_SLIM_SETTINGS__
    if (FS_GetDevStatus(SRV_FMGR_PUBLIC_DRV, FS_MOUNT_STATE_ENUM) < FS_NO_ERROR)
#else
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) < FS_NO_ERROR)
#endif
    {
        mmi_popup_display_ext(STR_GLOBAL_INSERT_MEMORY_CARD, 
                                (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(FS_MEDIA_CHANGED), 
                                NULL);
    #ifdef __MMI_AP_DCM_SNDREC__
        mmi_ap_send_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_SNDREC);
    #endif
        return;
    }

    mmi_sndrec_get_file_path(filepath);
    attribute = FS_GetAttributes(filepath);
    if (((FS_ATTR_DIR & attribute) == 0) || attribute < 0)
    {
        FS_CreateDir(filepath);
    }

#if defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
    if( mmi_frm_group_get_state(GRP_ID_SNDREC_START_BASE) != MMI_SCENARIO_STATE_NONE)
    {
        mmi_sndrec_is_play_flag = MMI_TRUE;
    }
    else
    {
        mmi_sndrec_is_play_flag = MMI_FALSE;
    }
#endif
    
    mmi_sndrec_entry_main_screen();
}


/*****************************************************************************
 * FUNCTION
 *  InitSoundRecorderApp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitSoundRecorderApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_AP_DCM_SNDREC__
    mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_SNDREC);
#endif

#ifndef __MMI_SNDREC_SLIM__
    g_sndrec_cntx.record.isappend = MMI_FALSE;
#endif
    g_sndrec_cntx.record.is_break = MMI_FALSE;      //support ogg
    g_sndrec_cntx.record.isIncall = MMI_FALSE;
    g_sndrec_cntx.record.isdelete = MMI_FALSE;
    //g_sndrec_cntx.record.is_sim_two = MMI_FALSE;
    //g_sndrec_cntx.record.need_file_prefix = MMI_FALSE;
    g_sndrec_cntx.record.is_in_app = MMI_FALSE;
    g_sndrec_cntx.record.isEntryFromOther = MMI_FALSE;
    g_sndrec_cntx.record.isStopBySelf = MMI_FALSE;
    g_sndrec_cntx.record.volume	= MDI_AUD_VOL_MUTE(MDI_AUD_VOL_4);

    mmi_sndrec_setting_init();

#if 0 //__VM_CODEC_SUPPORT__    
/* under construction !*/
#endif

#ifdef __MMI_SNDREC_SKIN__
    g_sndrec_cntx.record.is_timer_on = MMI_FALSE;
    mmi_sndrec_util_fmgr_init();
#endif /* __MMI_SNDREC_SKIN__ */ 

#ifdef __MMI_AP_DCM_SNDREC__
    mmi_ap_send_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_SNDREC);
#endif
}


#if defined(__MMI_OP02_LEMEI__)
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_record_from_lamei
 * DESCRIPTION
 *  this function is used for record in sms
 * PARAMETERS
 *  file_path         [IN]         
 *  size_limit        [IN]        
 *  time_limit       [IN]        
 *  callback_func  [OUT] application's call back handler.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_record_from_lamei(
        U16 *file_path,
        U32 size_limit,
        U32 time_limit,
        void (*app_callback_func) (BOOL result, U16 *filepath))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: add trace
    
    g_set_updated_info = MMI_TRUE;
    mmi_sndrec_entry_record_from_other_app(file_path,
                size_limit, time_limit, app_callback_func);
    g_sndrec_cntx.record.need_save = MMI_TRUE;
    g_set_updated_info = MMI_FALSE;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_in_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_in_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: add log
    mmi_sndrec_entry_record_from_other_app(NULL, 0, 0, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_record_in_sms
 * DESCRIPTION
 *  this function is used for record in sms
 * PARAMETERS
 *  file_path           [?]         
 *  max_file_size       [IN]        
 *  callback_func       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_record_in_sms(
        U16 *file_path,
        U32 max_file_size,
        void (*callback_func) (BOOL result, U16 *filepath))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: add trace
    mmi_sndrec_entry_record_from_other_app(file_path, max_file_size, 0, callback_func);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_record_from_other_app
 * DESCRIPTION
 *  this function is provided for other app to record with limit.
 *  The format and quality depend on sndrec's setting and if in call.
 * PARAMETERS
 *  file_path           [?]         
 *  size_limit          [IN]        
 *  time_limit          [IN]        
 *  callback_func       [IN]        
 *  [file_path]     [IN] has no use, always treat as NULL(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_record_from_other_app(
        U16 *file_path,
        U32 size_limit,
        U32 time_limit,
        void (*callback_func) (BOOL result, U16 *filepath))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drive_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Load DCM for Sound Recorder */
#ifdef __MMI_AP_DCM_SNDREC__
    mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_SNDREC);
#endif

    /* TODO : add trace */

    /* check is in mass storage mode or auto record on */
#ifdef __CTM_SUPPORT__
    if (srv_callset_ctm_get_mode() == MMI_TRUE && g_sndrec_cntx.record.isIncall)
    {
        mmi_popup_display_ext(STR_ID_SNDREC_NOT_ALLOWED_IN_CTM_CALL, MMI_EVENT_FAILURE, NULL);
        /* Unload DCM for Sound Recorder as the app exit here */
    #ifdef __MMI_AP_DCM_SNDREC__
        mmi_ap_send_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_SNDREC);
    #endif
        return;
    }
#endif /* __CTM_SUPPORT__ */ 

#ifdef __MMI_OP02_LEMEI__
    mmi_sndrec_set_app_record_time_limit( time_limit);
    mmi_sndrec_set_app_record_size_limit(size_limit);
#else
    g_size_limit = size_limit;
    g_time_limit = time_limit;
#endif
    if (mmi_sndrec_check_usb_mode())
    {
        /* Unload DCM for Sound Recorder as the app exit here */
    #ifdef __MMI_AP_DCM_SNDREC__
        mmi_ap_send_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_SNDREC);
    #endif
        return;
    }

#if 0    /* Auto Record Phased Out */
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_AP_DCM_SNDREC__
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
#endif
    
    mmi_sndrec_delete_self();
#ifdef __MMI_OP02_LEMEI__    
    if (g_set_updated_info)
    {
        mmi_sndrec_disable_record_pause();
        mmi_sndrec_enable_app_recording_time_left();
    }
#endif
    g_sndrec_cntx.record.isEntryFromOther = MMI_TRUE;
    mmi_sndrec_sms_record_callback = callback_func;
    if (mmi_sndrec_check_drive_is_external_drive(g_sndrec_cntx.setting.drive, &drive_type) == MMI_TRUE)
    {
        if (mmi_sndrec_app_check_drive_status(g_sndrec_cntx.setting.drive) == MMI_FALSE)
        {
            //mmi_sndrec_entry_main_screen();        // Old code - to enter sound recorder screen and remain there
            /* If only memory card supported and try to enter from other app exit sound recorder with memory card popup */
        #ifndef __MMI_SNDREC_SLIM_SETTINGS__
            if(srv_fmgr_drv_is_accessible((U8)SRV_FMGR_PUBLIC_DRV) == MMI_FALSE)
        #else
            if(srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV) == MMI_FALSE)
        #endif
            {
                mmi_popup_display_ext(STR_GLOBAL_INSERT_MEMORY_CARD, 
                                        (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(FS_MEDIA_CHANGED), 
                                        NULL);
            #ifdef __MMI_AP_DCM_SNDREC__
                mmi_ap_send_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_SNDREC);
            #endif
                return;
            }
        }

        if (mmi_sndrec_entry_mc_rules() == MMI_TRUE)
        {
            g_sndrec_mc_cb = mmi_sndrec_entry_record_from_other_app_ex;
            return;
        }
		// In else case unload [?] if not set the memory card change
    }  
    
#ifdef __MMI_OP02_LEMEI__ 
    if (g_set_updated_info == MMI_TRUE)
    {
         mmi_sndrec_entry_main_screen();
    }
    else
    {
        mmi_sndrec_entry_record_from_other_app_ex();
    }
#else    
        mmi_sndrec_entry_record_from_other_app_ex();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_exit_notify
 * DESCRIPTION
 *  cancel callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_sndrec_exit_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	MMI_SNDREC_MSG_TRACE(1);
	
	if (mmi_sndrec_sms_record_callback != NULL)
	{
		mmi_sndrec_sms_record_callback = NULL;
	}
}


#ifdef __MMI_AUTO_ANSWER_MACHINE__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_record_from_autoam
 * DESCRIPTION
 *  the file path should not be null
 * PARAMETERS
 *  file_path           [?]         
 *  size_limit          [IN]        
 *  time_limit          [IN]        
 *  callback_func       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_record_from_autoam(
        U16 *file_path,
        U32 size_limit,
        U32 time_limit,
        void (*callback_func) (BOOL result, U16 *filepath))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *file_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Load DCM for Sound Recorder */
#ifdef __MMI_AP_DCM_SNDREC__
    mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_SNDREC);
#endif

    /* check is in mass storage mode */
    if (mmi_sndrec_check_usb_mode())
    {
        /* Unload DCM for Sound Recorder as app is not opened */
    #ifdef __MMI_AP_DCM_SNDREC__
        mmi_ap_send_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_SNDREC);
    #endif
        return;
    }

#if 0 /* Auto Record Phased Out */
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_AP_DCM_SNDREC__
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
#endif

    mmi_sndrec_delete_self();

    /* the file format and quality must be WAV and Low */
    g_sndrec_cntx.record.quality = SRV_SOUNDREC_QUALITY_NORMAL;

    MMI_ASSERT(NULL != file_path);
    /* Parse file name */
    file_p = srv_fmgr_path_get_filename_ptr((WCHAR*) ((CHAR*) file_path));
    mmi_wcsncpy(g_sndrec_cntx.record.displayname, file_p, MMI_SNDREC_FILE_LEN);

    mmi_sndrec_bgsound_suspend();
    g_sndrec_cntx.record.isEntryFromOther = MMI_TRUE;

    if (mmi_sndrec_send_record_limit_req(
            file_path,
            (U8)MEDIA_WAV_DVI_ADPCM,
            g_sndrec_cntx.record.quality,
            size_limit,
            time_limit,
            1))
    {
    #ifndef __MMI_SNDREC_SLIM__
        g_sndrec_cntx.record.isappend = MMI_FALSE;
    #endif
        mmi_sndrec_entry_main_screen();
    }
    else
    {
        mmi_sndrec_clear_file_name();
        g_sndrec_cntx.record.isEntryFromOther = MMI_FALSE;
        mmi_sndrec_bgsound_resume();
        /* Unload DCM for Sound Recorder as app is not opened */
    #ifdef __MMI_AP_DCM_SNDREC__
        mmi_ap_send_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_SNDREC);
    #endif
    }
}
#endif /* __MMI_AUTO_ANSWER_MACHINE__ */ 


/* External API End - Not wrapped with DCM */

/* Event handlers Start - Not wrapped with DCM */


/*****************************************************************************
 * FUNCTION
 *  mmi_sound_recorder_broadcast_event_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_sound_recorder_broadcast_event_callback_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(event->evt_id == EVT_ID_SRV_PROF_IS_PLAYING)
    {
        if(mmi_sndrec_record_is_on() == MMI_TRUE)
        {
            return MMI_TRUE;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_sound_recorder_notify_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_fmgr_sound_recorder_notify_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 drive_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {

        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:

            if (mmi_sndrec_check_drive_is_external_drive(g_sndrec_cntx.setting.drive, &drive_type) == MMI_TRUE)
            {
                 /* Play, Play Pause, Preview, Preview states are not present in SLIM (Use Audio Player API) */
            #ifdef __MMI_SNDREC_SKIN__
                 if((MMI_SNDREC_PLAY_STATE == g_sndrec_cntx.record.state) ||
                     (MMI_SNDREC_PLAY_PAUSE_STATE == g_sndrec_cntx.record.state) ||
                     (MMI_SNDREC_PREVIEW_STATE == g_sndrec_cntx.record.state) ||
                     (MMI_SNDREC_PREVIEW_PAUSE_STATE == g_sndrec_cntx.record.state))    
                {
                    g_sndrec_cntx.record.state = MMI_SNDREC_IDLE_STATE;
                    mmi_sndrec_util_reclist_free();
                    mmi_sndrec_send_stop_req(MMI_TRUE);
                }
             #endif
                if (g_sndrec_cntx.record.is_in_app == MMI_TRUE)
                {
                #ifndef __MMI_SNDREC_SLIM_SETTINGS__
                    /* Exit sound recorder when remove memory card and phone drive is not present */
                    if (srv_fmgr_drv_is_accessible((U8)SRV_FMGR_PUBLIC_DRV) == MMI_FALSE)
                    {
                        mmi_sndrec_delete_self();
                    }
                #else
                    /* In case of slim settings exit sndrec */
                    mmi_sndrec_delete_self();
                #endif
                }
            }

            break;

        case EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE:
            if (MMI_SNDREC_IDLE_STATE == g_sndrec_cntx.record.state)
            {
                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_gpio_event_notify_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_sndrec_gpio_event_notify_handler(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event->evt_id == EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN)
    {
        if (g_sndrec_cntx.record.state == MMI_SNDREC_REC_STATE || g_sndrec_cntx.record.state == MMI_SNDREC_REC_PAUSE_STATE)
        {
            return MMI_RET_ERR;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_sound_recorder_def_storage_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event       [?]     
 *  p_event(?)
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_fmgr_sound_recorder_def_storage_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret result_value = MMI_RET_OK;
    srv_fmgr_notification_set_def_storage_event_struct *p_event = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_event = (srv_fmgr_notification_set_def_storage_event_struct*) event;

    switch (p_event->state)
    {

        case SRV_FMGR_NOTIFICATION_STATE_AFTER:
        {
            g_sndrec_cntx.setting.drive = (CHAR) (p_event->drv_letter);
            srv_soundrec_set_storage(g_sndrec_cntx.setting.drive); 
            break;
        }
        default:
        {
            break;
        }
    }

    return result_value;
}

#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_scrlocker_event_notify_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_sndrec_scrlocker_event_notify_handler(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event->evt_id == EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING)
    {
        if (g_sndrec_cntx.record.state == MMI_SNDREC_REC_STATE || g_sndrec_cntx.record.state == MMI_SNDREC_REC_PAUSE_STATE)
        {
            return MMI_RET_ERR;
        }
    }
    return MMI_RET_OK;
}
#endif


/*****************************************************************************
* FUNCTION
*  mmi_sndrec_a2dp_connect_callback_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if defined(__MMI_A2DP_SUPPORT__) && defined(__BT_SPEAKER_SUPPORT__)
void mmi_sndrec_a2dp_connect_callback_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    if (mmi_frm_group_get_state(GRP_ID_SNDREC_MAIN_PRE_LIST) != MMI_SCENARIO_STATE_NONE)
    {
        mmi_idle_display();
    }
#endif
}
#endif /*defined(__MMI_A2DP_SUPPORT__) && (__BT_SPEAKER_SUPPORT__)*/


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_option_enabler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_id         [IN]        
 *  filepath        [IN]        
 *  fileinfo        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_option_enabler(U16 menu_id, const WCHAR *filepath, const srv_fmgr_fileinfo_struct *fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __DRM_SUPPORT__
    S32 fwd_flag;
#endif /* __DRM_SUPPORT__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_SNDREC_SLIM__
    if (fileinfo->type == FMGR_TYPE_WAV || fileinfo->type == FMGR_TYPE_OGG)
    {
        mmi_frm_hide_menu_item(MENU_ID_SNDREC_LIST_APPEND);
    }

#ifdef __MMI_OP12_SNDREC_STYLE__
    mmi_frm_hide_menu_item(MENU_ID_SNDREC_LIST_APPEND);
#endif 
#endif


#ifdef __DRM_SUPPORT__
    if (filepath == NULL)
    {
        return;
    }

    fwd_flag = mmi_rmgr_check_forward((U16*) filepath);
#ifdef __PLUTO_MMI_PACKAGE__
    if (!(fwd_flag & MMI_RMGR_USAGE_SEND))
    {
        mmi_frm_hide_menu_item(MENU_ID_FMGR_GEN_OPTION_FORWARD_SEND);
    }

    if (!(fwd_flag & MMI_RMGR_USAGE_SET))
    {
        mmi_frm_hide_menu_item(MENU_ID_FMGR_GEN_OPTION_FORWARD_USE);
    }
#endif
#endif /* __DRM_SUPPORT__ */ 
}

/* Event handlers End - Not wrapped with DCM */


/* Common Used functions based on context data Start - Not wrapped with DCM */


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_record_is_on
 * DESCRIPTION
 *  querry if sndrec is running
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sndrec_record_is_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sndrec_cntx.record.state != MMI_SNDREC_IDLE_STATE)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_check_drive_is_external_drive
 * DESCRIPTION
 *  Check whether the drive is memory card or OTG device
 * PARAMETERS
 *  drive               [IN]        The drive's number
 *  p_drive_type        [?]         
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_sndrec_check_drive_is_external_drive(CHAR drive, S32 *p_drive_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR drive_wcs_path[10];
    S32 dev_type = FS_DEVICE_TYPE_CARD;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_wsprintf(drive_wcs_path,"%c:\\",drive);

    dev_type = FS_GetDevType((const WCHAR*)drive_wcs_path);
    if (NULL != p_drive_type)
    {
        *p_drive_type = dev_type;
    }
    return (MMI_BOOL)((FS_DEVICE_TYPE_CARD == dev_type) || (FS_DEVICE_TYPE_EXTERNAL == dev_type));
}



#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
static mmi_ret mmi_sndrec_pre_list_proc(mmi_event_struct *evt)
{
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    switch(menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            if (menu_evt->highlighted_menu_id == MENU_ID_SNDREC_NEW_RECORD_ENTER)
            {   
                mmi_sndrec_pre_entry_main_screen();
                //mmi_sndrec_new_record_hdlr();                
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_SNDREC_MY_RECORDS_LIST)
            { 
                mmi_sndrec_entry_record_list();                
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_SNDREC_SETTING_LIST)
            {    
                mmi_sndrec_pre_entry_setting_screen();                
            }
            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_bt_music_disconnect_callback_entry_pre_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_bt_music_disconnect_callback_entry_pre_list(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        mmi_entry_sndrec_pre_list();
    }
}


void mmi_entry_sndrec_pre_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sndrec_group_id;
    mmi_id cui_menu_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bt_music_check_connection())
    {
        mmi_bt_music_disconnect(mmi_sndrec_bt_music_disconnect_callback_entry_pre_list);
        //return;
    }
    
    sndrec_group_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SNDREC_MAIN_PRE_LIST, mmi_sndrec_pre_list_proc, NULL);
    mmi_frm_group_enter(sndrec_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_menu_id = cui_menu_create(sndrec_group_id, 
                                  CUI_MENU_SRC_TYPE_RESOURCE, 
                                  CUI_MENU_TYPE_APPSUB, 
                                  MENU_ID_SNDREC_MAIN_PRE_LIST_MENUID, 
                                  MMI_FALSE, 
                                  NULL);

    cui_menu_run(cui_menu_id);
}
#endif /* __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__ */


/* Common Used functions based on context data Start - Not wrapped with DCM */


#define __SNDREC_UI_HILIT_
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_hightlight_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_hightlight_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_entry_sndrec_pre_list, KEY_EVENT_UP);
#else
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_sndrec_pre_entry_main_screen, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
    SetCenterSoftkeyFunction(mmi_sndrec_pre_entry_main_screen, KEY_EVENT_UP);
#endif

}

/* Below this are DCM functions */
#ifdef __MMI_AP_DCM_SNDREC__
#pragma arm section rodata = "DYNAMIC_CODE_SNDREC_RODATA",code = "DYNAMIC_CODE_SNDREC_ROCODE"
#endif


#define __MMI_SNDREC_FILE_HANDLE__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_check_file_isnull
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sndrec_check_file_isnull(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sndrec_cntx.record.displayname[0] == 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_check_folder_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_sndrec_check_folder_valid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 filepath[MMI_SNDREC_PATH_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sndrec_get_file_path(filepath);
    return mmi_sndrec_fs_check_folder(filepath);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_get_full_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fullname        [OUT]       
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_get_full_file_name(U16 *fullname, const U16 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sndrec_get_file_path(fullname);
    mmi_wcscat(fullname, filename);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_get_file_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filepath        [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_get_file_path(U16 *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf((WCHAR*) filepath, "%c%w", g_sndrec_cntx.setting.drive, MMI_SNDREC_DEFAULT_PATH);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_check_file_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file        [IN]        
 *  strtype     [IN]        
 *  type(?)     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_sndrec_check_file_type(const U16 *file, const U16 *strtype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *ext;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ext = (U16*) mmi_wcsrchr(file, (U16) '.');
    if (ext)
    {
        if (0 == mmi_wcsicmp(ext, strtype))
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_get_new_file
 * DESCRIPTION
 *  should assign 'g_sndrec_cntx.record.format' before call this function
 * PARAMETERS
 *  file        [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_get_new_file(mmi_sndrec_format_ext ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 filename_tmp[MMI_SNDREC_FILE_LEN];
    RTC_CTRL_GET_TIME_T   rtc_time;
    DCL_HANDLE rtc_handler = 0;
    kal_uint8 count = 0;
    mdi_audio_rec_param_struct rec_param;
    U16 fullname[MMI_SNDREC_FULL_NAME_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE); 
    DclRTC_Control(rtc_handler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T *) &rtc_time);
    DclRTC_Close(rtc_handler);
    for (; count < 99; count++)
    {
        kal_wsprintf(
            filename_tmp,
            "%02d%02d%02d%02d%02d%02d",
            rtc_time.u1Mon,
            rtc_time.u1Day,
            rtc_time.u1Hour,
            rtc_time.u1Min,
            rtc_time.u1Sec,
            count);   

        if(ext == MMI_SNDREC_FORMAT_NULL)
        {
        mdi_audio_get_record_param(mmi_sndrec_get_rec_type(), (MDI_AUDIO_REC_QUALITY_ENUM)g_sndrec_cntx.record.quality, &rec_param);
        kal_wsprintf((kal_wchar*) g_sndrec_cntx.record.displayname, "%w%w", (CHAR*)filename_tmp,(CHAR*)rec_param.file_ext);
        }
        else
        {
            kal_wsprintf((kal_wchar*) g_sndrec_cntx.record.displayname, "%w%w", (CHAR*)filename_tmp,L".vm");
        }

        mmi_sndrec_get_full_file_name(fullname, g_sndrec_cntx.record.displayname);
        if (!mmi_sndrec_fs_check_file(fullname))
        {
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_is_file_exist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sndrec_is_file_exist()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_sndrec_fs_check_file(g_sndrec_cntx.record.displayname))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_useby_others_with_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_sndrec_useby_others_with_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sndrec_cntx.record.isEntryFromOther && (mmi_sndrec_sms_record_callback != NULL))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_remove_file_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_remove_file_ext(UI_string_type filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extBuffer[0] = 0;
    //extBuffer[1] = 0;
    p = filename + mmi_wcslen((const WCHAR*)filename);
    while (p > filename)
    {
        if (*p == L'.')
        {
            *p = 0;
            mmi_wcsncpy(extBuffer, p + 1, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
            break;
        }
        p--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_get_file_name_without_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_get_file_name_without_ext(UI_string_type filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy(filename, g_sndrec_cntx.record.displayname);
    mmi_sndrec_remove_file_ext(g_sndrec_cntx.record.displayname);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_get_rec_type
 * DESCRIPTION
 *  In call state, the format and quality will change according setting.
 *  In idle state, the format and quality is setting.
 * PARAMETERS
 *  format_p        [?]     
 *  quality_p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
MDI_AUDIO_REC_MODE_ENUM mmi_sndrec_get_rec_type()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_REC_MODE_ENUM rec_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        rec_type = MDI_AUDIO_REC_MODE_SPEECH;
    }
    else
    {
        rec_type = MDI_AUDIO_REC_MODE_IDLE;
    }
    return rec_type;
}

#define __MMI_SNDREC_VOLUME__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_record_side_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_record_init_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* register the BT volume handle callback here when init the app */
	/* For Low cost Slim, audio player is used for playing so no need of volume sync bt callback */
#ifdef __MMI_SNDREC_SKIN__
#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_register_volume_sync_callback(APP_SOUNDRECORDER, MDI_AUD_VOL_LEVEL_NORMAL_MUTE, mmi_sndrec_hfp_volume_callback);
#endif
#endif

        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
        {
            g_sndrec_cntx.record.volume = srv_speech_get_mode_volume();
            mdi_audio_set_volume(MDI_VOLUME_SPH, g_sndrec_cntx.record.volume);
        }
        else
        {
            g_sndrec_cntx.record.volume =  MDI_AUD_VOL_MUTE(MDI_AUD_VOL_4);
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, g_sndrec_cntx.record.volume);
        }


}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_adjust_speech_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_adjust_speech_volume(MMI_BOOL is_decr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 modified_vol = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Konark: why remove check for UCM? */
    g_sndrec_cntx.record.volume = srv_speech_get_mode_volume();
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_SPEECH_VOLUME, g_sndrec_cntx.record.volume);
    
    if(is_decr == MMI_TRUE)
    {
        modified_vol = mdi_audio_decr_volume(g_sndrec_cntx.record.volume);
    }
    else
    {
        modified_vol = mdi_audio_incr_volume(g_sndrec_cntx.record.volume);
    }
    if (modified_vol != g_sndrec_cntx.record.volume)
    {
        mdi_audio_set_volume(MDI_VOLUME_SPH, modified_vol);
        g_sndrec_cntx.record.volume = modified_vol;
        StartTimer(KEY_VOL_TIMER_ID, 2000, mmi_sndrec_save_speech_volume);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_save_speech_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_save_speech_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_speech_save_mode_volume((U8) g_sndrec_cntx.record.volume);
}

/* since SLIM sound recorder will not play audio file no need to adjust media volume  */
#ifdef __MMI_SNDREC_SKIN__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_decrease_media_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_adjust_media_volume(MMI_BOOL is_decr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 modified_vol = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_MEDIA_VOLUME, g_sndrec_cntx.record.volume);

    if(is_decr == MMI_TRUE)
    {
        modified_vol = mdi_audio_decr_volume(g_sndrec_cntx.record.volume);
    }
    else
    {
        modified_vol = mdi_audio_incr_volume(g_sndrec_cntx.record.volume);
    }
    
    if (modified_vol != g_sndrec_cntx.record.volume)
    {
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, modified_vol);
        g_sndrec_cntx.record.volume = modified_vol;
    }
}
#endif


#define __MMI_SNDREC_MAIN__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_delete_self
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_delete_self(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_DELETE_SELF);

    /* If save query do not exist. sms retutn True */
    if (!mmi_sndrec_check_file_isnull())
    {
        MMI_SNDREC_MSG_TRACE(1);
        mmi_sndrec_cb_for_other_app(MMI_TRUE);
    }

#ifndef __MMI_SNDREC_SKIN__

    mmi_frm_scrn_close(GRP_ID_SNDREC_PLAYER, SCR_ID_SNDREC_PLAYER);
#endif /* __MMI_SNDREC_SKIN__ */ 
    mmi_frm_group_close(GRP_ID_SNDREC_MAIN);

    if (0 != g_sndrec_cntx.record.fmgr_id)
    {
        g_sndrec_cntx.record.fmgr_id = 0;
    }
    #if defined(__MMI_OP02_LEMEI__)
    mmi_sndrec_disable_app_recording_time_left();   
    mmi_sndrec_enable_record_pause();
    #endif
    MMI_SNDREC_MSG_TRACE(2);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_main_screen_active
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_main_screen_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_back = mmi_frm_is_in_backward_scenario();
    MMI_BOOL is_incall_now = (MMI_BOOL)srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL);
    MMI_BOOL is_need_quit = MMI_FALSE;

#ifdef __MMI_SNDREC_SKIN__
    U8 drive[32];
    FS_DiskInfo diskinfo;
    S16 ret;
#endif /* __MMI_SNDREC_SKIN__ */ 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_ENTRY_MAIN_SCREEN, is_back);
               
    ClearKeyEvents();
    g_current_id = GRP_ID_SNDREC_MAIN;

#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    if(!is_back)
    {
        mmi_sndrec_bgsound_suspend();
    }
#else
    mmi_sndrec_bgsound_suspend();
#endif

    /* if back from history, check if the file is still valid */
    if (is_back && (!mmi_sndrec_check_file_isnull()) && (g_sndrec_cntx.record.state == MMI_SNDREC_IDLE_STATE))
    {
        MMI_SNDREC_MSG_TRACE(g_sndrec_cntx.record.state);
        /* Go back to sound recorder, but handle file not found */
        if (!mmi_sndrec_is_file_exist())
        {
            MMI_SNDREC_MSG_TRACE(g_sndrec_cntx.record.isEntryFromOther);
            /* if is entry from other app, Popup error and quit */
            if (g_sndrec_cntx.record.isEntryFromOther && (!mmi_sndrec_useby_others_with_cb()))
            {
                is_need_quit = MMI_TRUE;
            }
            /* If entry from idle, clear screen. */
            else
            {
                mmi_sndrec_clear_file_name();
                mmi_sndrec_init_time();
            }
        }
        else
        {
                /* if back from history, called by other application and the file is still valid. call the other application callback with true and exit */
                if (g_sndrec_cntx.record.isEntryFromOther)
                {
                        /* if file exist should call the callback with true */
                        mmi_sndrec_cb_for_other_app(MMI_TRUE);
                        mmi_sndrec_delete_self();
                }
        }
        g_sndrec_cntx.record.isIncall = is_incall_now;
    }

#ifdef __MMI_SNDREC_SKIN__
    /* every time display main screen, caculate remind size */
    kal_wsprintf((U16*) drive, "%c:\\", g_sndrec_cntx.setting.drive);
    ret = FS_GetDevStatus(g_sndrec_cntx.setting.drive, FS_FEATURE_STATE_ENUM);
    if (ret < FS_NO_ERROR)
    {
        g_sndrec_cntx.record.remindsize = 0;
        MMI_SNDREC_ERR_TRACE(ret);
    }
    else
    {
        ret = FS_GetDiskInfo((U16*) drive, &diskinfo, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
        if (ret >= FS_NO_ERROR)
        {
            g_sndrec_cntx.record.remindsize =
                diskinfo.FreeClusters * diskinfo.SectorsPerCluster * diskinfo.BytesPerSector;
            MMI_SNDREC_MSG_TRACE(g_sndrec_cntx.record.remindsize);
        }
        else
        {
            g_sndrec_cntx.record.remindsize = 0;
            MMI_SNDREC_ERR_TRACE(ret);
        }
    }

    entry_full_screen();
    mmi_sndrec_show_main_screen(STR_ID_SNDREC_MAIN);

    ClearInputEventHandler(MMI_DEVICE_KEY);
    mmi_sndrec_registe_keys();

#else /* __MMI_SNDREC_SKIN__ */ 
    mmi_sndrec_show_record_screen();
#endif /* __MMI_SNDREC_SKIN__ */ 

    // mmi_sndrec_record_init_volume();

    if (is_back)
    {
        MMI_SNDREC_MSG_TRACE(is_need_quit);
        if (is_need_quit)
        {
            /* if file not exist , should callback false */
            mmi_sndrec_cb_for_other_app(MMI_FALSE);
            mmi_sndrec_delete_self();
        }
        /* if the state change between call and idle, or is recording in call, popup save */
        if (((g_sndrec_cntx.record.isIncall != is_incall_now) || g_sndrec_cntx.record.isIncall || g_sndrec_cntx.record.isEntryFromOther)
            && (g_sndrec_cntx.record.is_break || need_save_later))
        {            
        #if defined (__MMI_OP12_SNDREC_STYLE__)
            if (g_sndrec_cntx.record.state != MMI_SNDREC_PREVIEW_STATE)
            {
                mmi_sndrec_entry_save_option();
            }
        #else
		if (mmi_is_redrawing_bk_screens() == 0)
		{
            mmi_sndrec_entry_save_query();
		}
		else
		{
			need_save_later = 1;
		}
        #endif /* __MMI_OP12_SNDREC_STYLE__ */ 
            g_sndrec_cntx.record.isIncall = is_incall_now;            
        }
    #ifdef __MMI_OP12_SNDREC_STYLE__
        else if (mmi_sndrec_preview_flag)
        {
            mmi_sndrec_entry_save_option();
        }
        /* if not preview state, clear preview high light flag */
        if (g_sndrec_cntx.record.state != MMI_SNDREC_PREVIEW_STATE)
        {
            mmi_sndrec_preview_flag = MMI_FALSE;
        }
    #endif /* __MMI_OP12_SNDREC_STYLE__ */
        g_sndrec_cntx.record.is_break = MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_clear_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_clear_file_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sndrec_cntx.record.displayname[0] = 0;
	//g_sndrec_cntx.record.displayname[1] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_main_screen_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_sndrec_main_screen_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct* p_key;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_INIT:
            mmi_sndrec_bgsound_suspend();
            mmi_sndrec_record_init_volume();
            break;
            
        case EVT_ID_SCRN_ACTIVE:
            mmi_sndrec_entry_main_screen_active();
            break;
            
        case EVT_ID_SCRN_INACTIVE:
            mmi_sndrec_exit_main_screen();
            break;
            
        case EVT_ID_SCRN_DEINIT:
            mmi_sndrec_delete_main_screen();
            break;
     #ifndef __MMI_SNDREC_SKIN__ 
        case EVT_ID_WGUI_LSK_CLICK:
        /* The CSK is handled in key type */
        //case EVT_ID_WGUI_CSK_CLICK:
            mmi_sndrec_left_key_main();
            return MMI_RET_KEY_HANDLED;

        case EVT_ID_WGUI_RSK_CLICK:
            mmi_sndrec_right_key_main();
            return MMI_RET_KEY_HANDLED;      
            //break;
     #endif       
        case EVT_ID_ON_KEY:          
            p_key = (mmi_frm_key_evt_struct*) evt;
       
            if(p_key->key_type == KEY_EVENT_DOWN)
            {   
                switch(p_key->key_code)
                {
                #ifdef __MMI_SNDREC_SKIN__ 
                    case KEY_LSK:
                    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
                        if(g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_STATE || g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_PAUSE_STATE)
                        {
                            mmi_sndrec_redraw_play_btn(MMI_TRUE);
                        }
                        else
                        {
                            mmi_sndrec_redraw_record_btn(MMI_TRUE);
                        } 
                    #endif
                        mmi_sndrec_mainscr_lsk_down_hdlr();
                    
                        break;
                        
                    case KEY_RSK:
                    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
                        if(g_sndrec_cntx.record.state == MMI_SNDREC_REC_STATE || g_sndrec_cntx.record.state == MMI_SNDREC_REC_PAUSE_STATE || mmi_sndrec_is_play_flag == MMI_TRUE)
                        {
                            mmi_sndrec_redraw_stop_btn(MMI_TRUE);
                        } 
                    #endif
                        mmi_sndrec_mainscr_rsk_down_hdlr();
                    
                        break;

                #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
                    case KEY_CSK:
                #ifdef  __MMI_OP02_LEMEI__
                        if(mmi_sndrec_query_is_record_pause_enabled() == MMI_FALSE)
                        {     
                            mmi_sndrec_press_record_btn();
                        }
                        else
                        {
                            mmi_sndrec_mainscr_lsk_down_hdlr();
                        }
                #else
                        mmi_sndrec_mainscr_lsk_down_hdlr();
                #endif
                        break;
                    
                    case KEY_UP_ARROW:
                        mmi_sndrec_press_record_btn();
                        break;
                        
                    case KEY_DOWN_ARROW:
                        mmi_sndrec_press_play_btn();
                        break;

                    case KEY_LEFT_ARROW:
                        mmi_sndrec_press_prev_btn();
                        break;
                        
                    case KEY_RIGHT_ARROW:
                        mmi_sndrec_press_next_btn();
                        break;   
                #else /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
                    case KEY_CSK:
                        mmi_sndrec_press_record_btn();
                        break;

                    case KEY_UP_ARROW:
                    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
                        if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
                        {
                            mmi_sndrec_adjust_speech_volume(MMI_FALSE);
                        }
                        /* since SLIM sound recorder will not play audio file no need to adjust media volume  */
                    #ifdef __MMI_SNDREC_SKIN__
                        else
                        {
                            mmi_sndrec_adjust_media_volume(MMI_FALSE);
                        }
                    #endif
                    
                    #else
                        mmi_sndrec_press_play_btn();
                    #endif
                        break;

                    case KEY_DOWN_ARROW:
                    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
                        if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
                        {
                            mmi_sndrec_adjust_speech_volume(MMI_TRUE);
                        }
                        /* since SLIM sound recorder will not play audio file no need to adjust media volume  */
                        #ifdef __MMI_SNDREC_SKIN__
                        else
                        {
                            mmi_sndrec_adjust_media_volume(MMI_TRUE);
                        }
                        #endif
                    #else
                        mmi_sndrec_press_stop_btn();
                    #endif
                        break;

                    case KEY_LEFT_ARROW:
                        mmi_sndrec_press_prev_btn();
                        break;

                    case KEY_RIGHT_ARROW:
                        mmi_sndrec_press_next_btn();
                        break;

                #endif   /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
                #endif /* __MMI_SNDREC_SKIN__ */
        
                    case KEY_VOL_DOWN:
                    case KEY_STAR:   
                        if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
                        {
                            mmi_sndrec_adjust_speech_volume(MMI_TRUE);
                        }
                        /* since SLIM sound recorder will not play audio file no need to adjust media volume  */
                    #ifdef __MMI_SNDREC_SKIN__
                        else
                        {
                            mmi_sndrec_adjust_media_volume(MMI_TRUE);
                        }
                    #endif
                        break;

                    case KEY_VOL_UP:
                    case KEY_POUND:     
                        if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
                        {
                            mmi_sndrec_adjust_speech_volume(MMI_FALSE);
                        }
                        /* since SLIM sound recorder will not play audio file no need to adjust media volume  */
                    #ifdef __MMI_SNDREC_SKIN__
                        else
                        {
                            mmi_sndrec_adjust_media_volume(MMI_FALSE);
                        }
                    #endif
                        break;
    
                    default:
                        break;    
                }
            }
            else if(p_key->key_type == KEY_EVENT_UP)
            {
                if (mmi_frm_scrn_get_active_id() != SCR_ID_SNDREC_MAIN)
                {
                     return MMI_RET_OK;
                }

                switch(p_key->key_code)
                {
                #ifdef __MMI_SNDREC_SKIN__
                    case KEY_LSK:                        
                    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
                        if(g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_STATE || g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_PAUSE_STATE || mmi_sndrec_is_play_flag == MMI_TRUE)
                        {
                            mmi_sndrec_release_play_btn();
                        }
                        else
                        {
                            mmi_sndrec_release_record_btn();
                        }
                    #endif
                        mmi_sndrec_mainscr_lsk_up_hdlr();
                        break;
                        
                    case KEY_RSK:
                    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__   
                        if((g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_STATE || g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_PAUSE_STATE) 
                            || (g_sndrec_cntx.record.state == MMI_SNDREC_REC_STATE || g_sndrec_cntx.record.state == MMI_SNDREC_REC_PAUSE_STATE))
                        {
                            if(g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_STATE || g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_PAUSE_STATE)
                            {
                                mmi_sndrec_is_play_goback = MMI_TRUE;
                            }
                            mmi_sndrec_release_stop_btn();
                        }                        
                    #endif 
                        mmi_sndrec_mainscr_rsk_up_hdlr();
                        break;

                #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
                    case KEY_CSK:
                    #ifdef  __MMI_OP02_LEMEI__
                        if(mmi_sndrec_query_is_record_pause_enabled() == MMI_FALSE)
                        {     
                            mmi_sndrec_release_record_btn_other_app();
                        }
                        else
                        {
                            mmi_sndrec_mainscr_lsk_up_hdlr();
                        }
                    #else
                        mmi_sndrec_mainscr_lsk_up_hdlr();
                    #endif
                        break;

                     case KEY_UP_ARROW:
                        mmi_sndrec_release_record_btn();
                        break;
                        
                    case KEY_DOWN_ARROW:
                        mmi_sndrec_release_play_btn();
                        break;
                #else  /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
                    case KEY_CSK:
	                    mmi_sndrec_release_record_btn();
	                    break;

                    #ifndef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
                    case KEY_UP_ARROW:
	                    mmi_sndrec_release_play_btn();
	                    break;

                    case KEY_DOWN_ARROW:
	                    mmi_sndrec_release_stop_btn();
	                    break;
                    #endif
                    
                #endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */

                    case KEY_LEFT_ARROW:
                        mmi_sndrec_release_prev_btn();
                        break;
                        
                    case KEY_RIGHT_ARROW:
                        mmi_sndrec_release_next_btn();
                        break;
                #else
                    case KEY_CSK:
                        /* When Idle send record request otherwise do what LSK does */
                        if (g_sndrec_cntx.record.state == MMI_SNDREC_IDLE_STATE)
                        {
                            mmi_sndrec_new_record_hdlr();
                            mmi_sndrec_show_record_screen();
                        }
                        else
                        {
                            mmi_sndrec_left_key_main();
                        }
                        break;
                #endif /* __MMI_SNDREC_SKIN__ */

                    default:
                        break;
                }
                
            }
        #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
            else if(p_key->key_type == KEY_LONG_PRESS && p_key->key_code == KEY_RSK)
            {
                mmi_idle_display();
            }
            else if(p_key->key_type == KEY_LONG_PRESS || p_key->key_type == KEY_EVENT_REPEAT)
            {
                if (p_key->key_code == KEY_UP_ARROW)
                {
                    if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
                    {
                        mmi_sndrec_adjust_speech_volume(MMI_FALSE);
                    }
                    /* since SLIM sound recorder will not play audio file no need to adjust media volume  */
                #ifdef __MMI_SNDREC_SKIN__
                    else
                    {
                        mmi_sndrec_adjust_media_volume(MMI_FALSE);
                    }
                #endif

                }
                else if (p_key->key_code == KEY_DOWN_ARROW)
                {
                    if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
                    {
                        mmi_sndrec_adjust_speech_volume(MMI_TRUE);
                    }
                    /* since SLIM sound recorder will not play audio file no need to adjust media volume  */
                #ifdef __MMI_SNDREC_SKIN__
                    else
                    {
                        mmi_sndrec_adjust_media_volume(MMI_TRUE);
                    }
                #endif
                }
            }
        #endif
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_main_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_entry_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_SNDREC_MAIN, NULL, (void*)NULL, MMI_FRM_NODE_SMART_CLOSE_CAUSED_BY_CLOSE_FLAG);

    mmi_frm_scrn_create(GRP_ID_SNDREC_MAIN,SCR_ID_SNDREC_MAIN,mmi_sndrec_main_screen_proc,NULL);   

    g_sndrec_cntx.record.is_in_app = MMI_TRUE;
}

#ifdef __MMI_SNDREC_SKIN__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_mainscr_lsk_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_mainscr_lsk_up_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FTE_SUPPORT__
    MMI_BOOL res = MMI_FALSE;
    MMI_BOOL is_true = MMI_FALSE;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_sndrec_cntx.record.isButtonDown)
    {
        return;
    }
    g_sndrec_cntx.record.isButtonDown = MMI_FALSE;
    
#ifdef __MMI_FTE_SUPPORT__
    if(MMI_SNDREC_IDLE_STATE == g_sndrec_cntx.record.state)
    {
    #if defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
        if(mmi_sndrec_is_play_flag)
        {
            mmi_sndrec_release_play_btn();
        }
        else
        {
            mmi_sndrec_release_record_btn();
        }
    #else
         mmi_sndrec_redraw_main_lsk();
         mmi_sndrec_entry_option_screen();
     #endif
    }  
#else /* __MMI_FTE_SUPPORT__ */ 
    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_IDLE_STATE:
            /* recording state is breaked by other screen */
            mmi_sndrec_redraw_main_lsk();
            mmi_sndrec_entry_option_screen();
            return;

        case MMI_SNDREC_REC_STATE:
            res = mmi_sndrec_send_pause_req(MMI_SNDREC_REC_PAUSE_STATE);
            is_true = MMI_FALSE;
            
            break;

        case MMI_SNDREC_REC_PAUSE_STATE:
            res = mmi_sndrec_send_resume_req(MMI_SNDREC_REC_STATE);
            is_true = MMI_TRUE;

            break;

        case MMI_SNDREC_PLAY_STATE:
            res = mmi_sndrec_send_pause_req(MMI_SNDREC_PLAY_PAUSE_STATE);
            is_true = MMI_FALSE;

            break;
        case MMI_SNDREC_PLAY_PAUSE_STATE:
            res = mmi_sndrec_send_resume_req(MMI_SNDREC_PLAY_STATE);
            is_true = MMI_TRUE;
    
            break;
        case MMI_SNDREC_PREVIEW_STATE:
            res = mmi_sndrec_send_pause_req(MMI_SNDREC_PREVIEW_PAUSE_STATE);
            is_true = MMI_FALSE;
 
            break;
        case MMI_SNDREC_PREVIEW_PAUSE_STATE:
            res = mmi_sndrec_send_resume_req(MMI_SNDREC_PREVIEW_STATE);
            is_true = MMI_TRUE;
          
            break;
        default:
        {
            MMI_SNDREC_ASSERT(0);
        }

    }
    
    if (res)
    {
        mmi_sndrec_redraw_skins_animal_img(is_true);
        mmi_sndrec_show_time_text(is_true);
    }
    else
    {
        return;
    }
    
    mmi_sndrec_redraw_main_lsk();
    mmi_sndrec_redraw_state_text();
    mmi_sndrec_redraw_play_btn(MMI_FALSE);
    mmi_sndrec_redraw_record_btn(MMI_FALSE);
    mmi_sndrec_redraw_prev_btn(MMI_FALSE);
    mmi_sndrec_redraw_next_btn(MMI_FALSE);
    mmi_sndrec_blt_screen();
#endif /* __MMI_FTE_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_mainscr_lsk_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_mainscr_lsk_down_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sndrec_redraw_main_lsk_down();
    mmi_sndrec_blt_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_mainscr_rsk_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_mainscr_rsk_up_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_sndrec_cntx.record.isButtonDown)
    {
        return;
    }
    mmi_sndrec_redraw_main_rsk();

#ifdef __MMI_FTE_SUPPORT__
    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_IDLE_STATE:
            mmi_frm_scrn_close_active_id();
            
            if(mmi_sndrec_useby_others_with_cb() == MMI_TRUE)
            {
                mmi_sndrec_sms_record_callback(FALSE, NULL);	
            }   //may be no use
            break;

        case MMI_SNDREC_REC_STATE:
        case MMI_SNDREC_REC_PAUSE_STATE:
#ifdef __MMI_OP02_LEMEI__
        if(g_sndrec_cntx.record.isEntryFromOther == MMI_TRUE && !mmi_sndrec_query_is_record_pause_enabled())
        {
            g_sndrec_cntx.record.need_save = MMI_FALSE;
            mmi_sndrec_send_stop_req(MMI_TRUE);
        }
#endif
            break;

        case MMI_SNDREC_PLAY_STATE:
        case MMI_SNDREC_PLAY_PAUSE_STATE:
        case MMI_SNDREC_PREVIEW_STATE:
        case MMI_SNDREC_PREVIEW_PAUSE_STATE:
            break;
        default:
            MMI_SNDREC_ASSERT(0);
    }
#else /* __MMI_FTE_SUPPORT__ */ /* MMI_FTE_SUPPORT__ */
    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_IDLE_STATE:
                mmi_frm_scrn_close_active_id();
            break;

        case MMI_SNDREC_REC_STATE:
        case MMI_SNDREC_REC_PAUSE_STATE:
    #ifdef __MMI_OP02_LEMEI__
        if(g_sndrec_cntx.record.isEntryFromOther == MMI_TRUE && !mmi_sndrec_query_is_record_pause_enabled())
        {
            g_sndrec_cntx.record.need_save = MMI_FALSE;
        }
    #endif
            mmi_sndrec_send_stop_req(MMI_TRUE);
            /* mmi_sndrec_redraw_list_btn(MMI_FALSE); */
            break;

        case MMI_SNDREC_PLAY_STATE:
        case MMI_SNDREC_PLAY_PAUSE_STATE:
            mmi_sndrec_send_stop_req(MMI_FALSE);
            mmi_sndrec_redraw_main_rsk();
            mmi_sndrec_redraw_main_lsk();
            mmi_sndrec_redraw_file_name(g_sndrec_cntx.record.displayname);
            mmi_sndrec_redraw_skins_animal_img(MMI_FALSE);
            mmi_sndrec_show_time_text(MMI_FALSE);
            mmi_sndrec_redraw_state_text();
            mmi_sndrec_redraw_play_btn(MMI_FALSE);
            mmi_sndrec_redraw_record_btn(MMI_FALSE);
            mmi_sndrec_blt_screen();
            break;
            
        case MMI_SNDREC_PREVIEW_STATE:
        case MMI_SNDREC_PREVIEW_PAUSE_STATE:
            mmi_sndrec_send_stop_req(MMI_FALSE);
            break;
        default:
            MMI_SNDREC_ASSERT(0);
    }
#endif /* __MMI_FTE_SUPPORT__ */ /* MMI_FTE_SUPPORT */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_mainscr_rsk_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_mainscr_rsk_down_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sndrec_redraw_main_rsk_down();
    mmi_sndrec_blt_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_registe_keys
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_registe_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_register_down_handler(mmi_sndrec_pen_down_hdlr);
    mmi_pen_register_up_handler(mmi_sndrec_pen_up_hdlr);
    mmi_pen_register_move_handler(mmi_sndrec_pen_move_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */ 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_press_record_btn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_press_record_btn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 curre_state = g_sndrec_cntx.record.state;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_SNDREC_REC_STATE == curre_state) ||
        (MMI_SNDREC_REC_PAUSE_STATE == curre_state) ||
       (MMI_SNDREC_IDLE_STATE == curre_state))
    {
        mmi_sndrec_redraw_record_btn(MMI_TRUE);
        mmi_sndrec_blt_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_press_play_btn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_press_play_btn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_SNDREC_PLAY_STATE == g_sndrec_cntx.record.state) ||
        (MMI_SNDREC_PLAY_PAUSE_STATE == g_sndrec_cntx.record.state) ||
        (MMI_SNDREC_PREVIEW_STATE == g_sndrec_cntx.record.state) ||
        (MMI_SNDREC_PREVIEW_PAUSE_STATE == g_sndrec_cntx.record.state))
    {
        mmi_sndrec_redraw_play_btn(MMI_TRUE);
        mmi_sndrec_blt_screen();
    }
    else if (MMI_SNDREC_IDLE_STATE == g_sndrec_cntx.record.state)
    {
        if (!mmi_sndrec_check_file_isnull())
        {
            mmi_sndrec_redraw_play_btn(MMI_TRUE);
            mmi_sndrec_blt_screen();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_press_prev_btn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_press_prev_btn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_SNDREC_PLAY_STATE == g_sndrec_cntx.record.state) ||
        (MMI_SNDREC_PLAY_PAUSE_STATE == g_sndrec_cntx.record.state))
    {
        mmi_sndrec_redraw_prev_btn(MMI_TRUE);
        mmi_sndrec_blt_screen();
    }
    else if (MMI_SNDREC_IDLE_STATE == g_sndrec_cntx.record.state)
    {
        if (!mmi_sndrec_check_file_isnull())
        {
            mmi_sndrec_redraw_prev_btn(MMI_TRUE);
            mmi_sndrec_blt_screen();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_press_next_btn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_press_next_btn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_SNDREC_PLAY_STATE == g_sndrec_cntx.record.state) ||
        (MMI_SNDREC_PLAY_PAUSE_STATE == g_sndrec_cntx.record.state))
    {
        mmi_sndrec_redraw_next_btn(MMI_TRUE);
        mmi_sndrec_blt_screen();
    }
    else if (MMI_SNDREC_IDLE_STATE == g_sndrec_cntx.record.state)
    {
        if (!mmi_sndrec_check_file_isnull())
        {
            mmi_sndrec_redraw_next_btn(MMI_TRUE);
            mmi_sndrec_blt_screen();
        }
    }
}
#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_press_stop_btn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_press_stop_btn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_SNDREC_PLAY_STATE == g_sndrec_cntx.record.state) ||
        (MMI_SNDREC_PLAY_PAUSE_STATE == g_sndrec_cntx.record.state) ||
        (MMI_SNDREC_REC_STATE == g_sndrec_cntx.record.state) ||
        (MMI_SNDREC_REC_PAUSE_STATE == g_sndrec_cntx.record.state))
    {
        mmi_sndrec_redraw_stop_btn(MMI_TRUE);
        mmi_sndrec_blt_screen();
    }
}
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_release_record_btn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_release_record_btn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL res = MMI_FALSE;
    MMI_BOOL is_true = MMI_FALSE;
    S32 drive_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_sndrec_check_drive_is_external_drive(g_sndrec_cntx.setting.drive, &drive_type) == MMI_TRUE)
    {
        if (mmi_sndrec_entry_mc_rules() == MMI_TRUE)
        {
            g_sndrec_mc_cb = mmi_sndrec_new_record_hdlr;
            return;
        }
    }

#ifndef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    if (!g_sndrec_cntx.record.isButtonDown)
    {
        return;
    }
#endif
    g_sndrec_cntx.record.isButtonDown = MMI_FALSE;
    
#if !defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
    /* If draw the record btn after sending record start/pause request it appears slow better redraw it before also */
    mmi_sndrec_redraw_record_btn(MMI_FALSE);
    mmi_sndrec_blt_screen();
#endif

    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_IDLE_STATE:
    #ifdef __CTM_SUPPORT__
            if (srv_callset_ctm_get_mode() == MMI_TRUE && g_sndrec_cntx.record.isIncall)
            {

                mmi_popup_display_ext(STR_ID_SNDREC_NOT_ALLOWED_IN_CTM_CALL,MMI_EVENT_FAILURE,NULL);
                return;
            }
    #endif /* __CTM_SUPPORT__ */ 
            is_true = MMI_TRUE;
            res = mmi_sndrec_new_record();
            if (res)
            {
                mmi_sndrec_redraw_file_name(g_sndrec_cntx.record.displayname);
            #ifdef __MMI_FTE_SUPPORT__
                mmi_sndrec_redraw_stop_btn(MMI_FALSE);
            #endif
            }

            break;

        case MMI_SNDREC_REC_STATE:
            res = mmi_sndrec_send_pause_req(MMI_SNDREC_REC_PAUSE_STATE);
            is_true = MMI_FALSE;
           
            break;

        case MMI_SNDREC_REC_PAUSE_STATE:
            res = mmi_sndrec_send_resume_req(MMI_SNDREC_REC_STATE);
            is_true = MMI_TRUE;
            
            break;

        default:
            /* mmi_sndrec_redraw_record_btn(MMI_FALSE); */
            return;
    }

    if (res)
    {
        mmi_sndrec_redraw_skins_animal_img(is_true);
        mmi_sndrec_show_time_text(is_true);
    #ifdef __MMI_FTE_SUPPORT__
        mmi_sndrec_redraw_rec_icon();
    #endif 
    }
    else
    {
        return;
    }
    
    mmi_sndrec_redraw_record_btn(MMI_FALSE);
    mmi_sndrec_redraw_play_btn(MMI_FALSE);
    mmi_sndrec_redraw_prev_btn(MMI_FALSE);
    mmi_sndrec_redraw_next_btn(MMI_FALSE);
#ifdef __MMI_FTE_SUPPORT__
    /* remove out of this later for NON FTE */
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    mmi_sndrec_redraw_list_btn(MMI_FALSE);
#endif
#else
    mmi_sndrec_redraw_state_text();
#endif /* __MMI_FTE_SUPPORT__ */ 

    mmi_sndrec_redraw_main_lsk();
    mmi_sndrec_redraw_main_rsk();
    mmi_sndrec_blt_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_release_play_btn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_release_play_btn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL res = MMI_FALSE;
    MMI_BOOL is_true = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_sndrec_cntx.record.isButtonDown)
    {
        return;
    }
    g_sndrec_cntx.record.isButtonDown = MMI_FALSE;

    if (!mmi_sndrec_func_allow_incall())
    {
        return;
    }

#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    mmi_sndrec_redraw_main_lsk();
#endif
    /* If draw the play btn after sending play request it appears slow better redraw it before also */
    mmi_sndrec_redraw_play_btn(MMI_FALSE);
    mmi_sndrec_blt_screen();

    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_IDLE_STATE:
            if (!mmi_sndrec_check_file_isnull())
            {
                res = mmi_sndrec_send_play_req(g_sndrec_cntx.record.displayname, mmi_sndrec_play_end_cb);
                is_true = MMI_TRUE;
                if (res)
                {
                    mmi_sndrec_redraw_file_name(g_sndrec_cntx.record.displayname);
                #ifdef __MMI_FTE_SUPPORT__
                    mmi_sndrec_redraw_stop_btn(MMI_FALSE);
                #endif 
                }
            }
            else
            {
                return;
            }
            break;

        case MMI_SNDREC_PLAY_STATE:
            res = mmi_sndrec_send_pause_req(MMI_SNDREC_PLAY_PAUSE_STATE);
            is_true = MMI_FALSE;
            
            break;

        case MMI_SNDREC_PLAY_PAUSE_STATE:
            res = mmi_sndrec_send_resume_req(MMI_SNDREC_PLAY_STATE);
            is_true = MMI_TRUE;

            break;
        case MMI_SNDREC_PREVIEW_STATE:
            res = mmi_sndrec_send_pause_req(MMI_SNDREC_PREVIEW_PAUSE_STATE);
            is_true = MMI_FALSE;

            break;
        case MMI_SNDREC_PREVIEW_PAUSE_STATE:
            res = mmi_sndrec_send_resume_req(MMI_SNDREC_PREVIEW_STATE);
            is_true = MMI_TRUE;

            break;
        default:
            return;
    }

    if (res)
    {
        mmi_sndrec_redraw_skins_animal_img(is_true);
        mmi_sndrec_show_time_text(is_true);
    }
    else
    {
        return;
    }

    
    mmi_sndrec_redraw_record_btn(MMI_FALSE);
    mmi_sndrec_redraw_play_btn(MMI_FALSE);
#ifdef __MMI_FTE_SUPPORT__
    /* remove out of this later for NON FTE */
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    mmi_sndrec_redraw_list_btn(MMI_FALSE);
#endif
#else
    mmi_sndrec_redraw_state_text();
#endif 
    mmi_sndrec_redraw_main_lsk();
    mmi_sndrec_redraw_main_rsk();
    mmi_sndrec_blt_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_release_prev_btn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_release_prev_btn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_SNDREC_PLAY_STATE == g_sndrec_cntx.record.state) ||
        (MMI_SNDREC_PLAY_PAUSE_STATE == g_sndrec_cntx.record.state))
    {
        if (!g_sndrec_cntx.record.isButtonDown)
        {
            return;
        }
        g_sndrec_cntx.record.isButtonDown = MMI_FALSE;

        if (!mmi_sndrec_func_allow_incall())
        {
            return;
        }
        mmi_sndrec_redraw_prev_btn(MMI_FALSE);
        mmi_sndrec_blt_screen();
        mmi_sndrec_pre_play_next(MMI_FALSE);
    }
    else if (MMI_SNDREC_IDLE_STATE == g_sndrec_cntx.record.state)
    {
        if (!mmi_sndrec_check_file_isnull())
        {
            if (!g_sndrec_cntx.record.isButtonDown)
            {
                return;
            }
            g_sndrec_cntx.record.isButtonDown = MMI_FALSE;

            mmi_sndrec_redraw_prev_btn(MMI_FALSE);
            mmi_sndrec_blt_screen();
            mmi_sndrec_pre_play_next(MMI_FALSE);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_release_next_btn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_release_next_btn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_SNDREC_PLAY_STATE == g_sndrec_cntx.record.state) ||
        (MMI_SNDREC_PLAY_PAUSE_STATE == g_sndrec_cntx.record.state))
    {
        if (!g_sndrec_cntx.record.isButtonDown)
        {
            return;
        }
        g_sndrec_cntx.record.isButtonDown = MMI_FALSE;

        if (!mmi_sndrec_func_allow_incall())
        {
            return;
        }
        mmi_sndrec_redraw_next_btn(MMI_FALSE);
        mmi_sndrec_blt_screen();
        mmi_sndrec_pre_play_next(MMI_TRUE);
    }
    else if (MMI_SNDREC_IDLE_STATE == g_sndrec_cntx.record.state)
    {
        if (!mmi_sndrec_check_file_isnull())
        {
            if (!g_sndrec_cntx.record.isButtonDown)
            {
                return;
            }
            g_sndrec_cntx.record.isButtonDown = MMI_FALSE;

            mmi_sndrec_redraw_next_btn(MMI_FALSE);
            mmi_sndrec_blt_screen();
            mmi_sndrec_pre_play_next(MMI_TRUE);
        }
    }

}

#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_release_list_btn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_release_list_btn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_SNDREC_IDLE_STATE == g_sndrec_cntx.record.state)
    {
        if (!g_sndrec_cntx.record.isButtonDown)
        {
            return;
        }
        g_sndrec_cntx.record.isButtonDown = MMI_FALSE;
        if (!mmi_sndrec_func_allow_incall())
        {
            return;
        }

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        mmi_sndrec_redraw_list_btn(MMI_FALSE);
#endif
        mmi_sndrec_blt_screen();
        mmi_sndrec_entry_record_list();
    }
    else if ((MMI_SNDREC_PLAY_STATE == g_sndrec_cntx.record.state) ||
             (MMI_SNDREC_PLAY_PAUSE_STATE == g_sndrec_cntx.record.state) ||
             (MMI_SNDREC_REC_STATE == g_sndrec_cntx.record.state) ||
             (MMI_SNDREC_REC_PAUSE_STATE == g_sndrec_cntx.record.state))
    {
        if (!g_sndrec_cntx.record.isButtonDown)
        {
            return;
        }
        g_sndrec_cntx.record.isButtonDown = MMI_FALSE;
        if (!mmi_sndrec_func_allow_incall())
        {
            return;
        }
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        mmi_sndrec_redraw_list_btn(MMI_FALSE);
#endif
        mmi_sndrec_blt_screen();
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_release_stop_btn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_release_stop_btn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_sndrec_cntx.record.isButtonDown)
    {
        return;
    }
    mmi_sndrec_redraw_stop_btn(MMI_FALSE);

    g_sndrec_cntx.record.isButtonDown = MMI_FALSE;

    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_IDLE_STATE:
            break;

        case MMI_SNDREC_REC_STATE:
        case MMI_SNDREC_REC_PAUSE_STATE:
            mmi_sndrec_send_stop_req(MMI_TRUE);
            break;

        case MMI_SNDREC_PLAY_STATE:
        case MMI_SNDREC_PLAY_PAUSE_STATE:
            mmi_sndrec_send_stop_req(MMI_FALSE);

        #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
            mmi_frm_scrn_close_active_id();
            
            if(mmi_sndrec_useby_others_with_cb() == MMI_TRUE)
            {
                mmi_sndrec_sms_record_callback(FALSE, NULL);	
            }   //may be no use
        #else
            
            mmi_sndrec_redraw_stop_btn(MMI_FALSE);
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
            mmi_sndrec_redraw_list_btn(MMI_FALSE);
#endif

            mmi_sndrec_redraw_file_name(g_sndrec_cntx.record.displayname);
            mmi_sndrec_redraw_skins_animal_img(MMI_FALSE);
            mmi_sndrec_show_time_text(MMI_FALSE);
            mmi_sndrec_redraw_play_btn(MMI_FALSE);
            mmi_sndrec_redraw_record_btn(MMI_FALSE);
            mmi_sndrec_redraw_main_rsk();
            mmi_sndrec_redraw_main_lsk();

            mmi_sndrec_blt_screen();
        #endif
            break;
        case MMI_SNDREC_PREVIEW_STATE:
        case MMI_SNDREC_PREVIEW_PAUSE_STATE:
            mmi_sndrec_send_stop_req(MMI_FALSE);
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
            mmi_sndrec_redraw_list_btn(MMI_FALSE);
#endif
            mmi_sndrec_redraw_stop_btn(MMI_FALSE);
            break;
        default:
            MMI_SNDREC_ASSERT(0);
    }
    mmi_sndrec_blt_screen();
}
#endif /* __MMI_FTE_SUPPORT__ */ 

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_pre_play_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  isNext      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_pre_play_next(MMI_BOOL isNext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_SNDREC_PLAY_NEXT);
    /* record button and current state */
    g_sndrec_cntx.record.isnext = isNext;
    if (g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_STATE)
    {
        g_sndrec_cntx.record.isplay = MMI_TRUE;
    }
    else
    {
        g_sndrec_cntx.record.isplay = MMI_FALSE;
    }

    /* Stop play */
    if (g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_STATE ||
        g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_PAUSE_STATE)
    {
        /* make this global TRUE as need not to show the record idle screen during next/prev */
        g_sndrec_no_idle_next_prev = MMI_TRUE;
        mmi_sndrec_send_stop_req(MMI_FALSE);
    #ifdef __MMI_FTE_SUPPORT__
        /* remove out of this later for NON FTE */
    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        mmi_sndrec_redraw_list_btn(MMI_FALSE);
    #endif
    #endif /* __MMI_FTE_SUPPORT__ */ 
    }

    /* If file list valid, switch to next */
    if (mmi_sndrec_util_reclist_check_valid())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_PLAY_NEXT_RECLIST);
        mmi_sndrec_play_next();
    }
    else
    {
        if(mmi_sndrec_util_reclist_query_is_process() == MMI_FALSE)
        {
            ret = mmi_sndrec_util_reclist_create();
        }
        else
        {
             return;
        }
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_PLAY_NEXT_RECLIST_ID, ret);
        if (FS_NO_ERROR == ret)
        {
            /*  
             mmi_frm_scrn_create(GRP_ID_SNDREC_MAIN, SCR_ID_SNDREC_CREATING, mmi_sndrec_reclist_scrn_proc, NULL);
             g_sndrec_wait_next_prev = MMI_TRUE; */
        }
        else
        {
            /* Create False, Release filelist and popup */
            mmi_sndrec_util_reclist_free();
            mmi_sndrec_error_hdlr(ret, MMI_FALSE);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_exit_reclist_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_exit_reclist_create(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_sndrec_util_check_created())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_PLAY_NEXT_CLIST_FAIL);
        mmi_sndrec_util_reclist_free();
        mmi_frm_scrn_close(GRP_ID_SNDREC_CREATING, SCR_ID_SNDREC_CREATING);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_reclist_create_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fl_hdl          [IN]        
 *  result          [IN]        
 *  progress        [IN]        
 *  total           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_sndrec_reclist_create_callback(SRV_FMGR_FILELIST_HANDLE fl_hdl, S32 result, S32 progress, S32 total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* MMI_BOOL bret; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_PLAY_NEXT_RECLIST_CALLBACK, result, progress, total, fl_hdl);
    if ((progress == total))
    {
        mmi_sndrec_util_reclist_ready(fl_hdl, total);
        mmi_sndrec_util_curridx_set_async();    /* May be false, need add */
        g_sndrec_wait_next_prev = MMI_FALSE;
        mmi_frm_scrn_close(GRP_ID_SNDREC_MAIN, SCR_ID_SNDREC_CREATING);
    }
    else if (result < 0)
    {
        /* Create Filelist fail, popup error and */
        mmi_sndrec_util_reclist_free();
        mmi_sndrec_error_hdlr(result, MMI_FALSE);
        mmi_frm_scrn_close(GRP_ID_SNDREC_CREATING, SCR_ID_SNDREC_CREATING);

    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_reclist_set_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bret        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_reclist_set_callback(MMI_BOOL bret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(GRP_ID_SNDREC_MAIN, GRP_ID_SNDREC_MAIN);
    if (!bret)
    {
        mmi_sndrec_util_reclist_free();
    }
    else
    {
        mmi_sndrec_play_next();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_reclist_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_reclist_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sndrec_util_reclist_free();
    mmi_frm_scrn_close_active_id();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_reclist_play_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_reclist_play_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bret = mmi_sndrec_util_get_filename((CHAR*) g_sndrec_cntx.record.displayname);
    if (bret)
    {
        mmi_sndrec_play_next_req();
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_PLAY_NEXT_SUCC);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_play_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_play_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bret;
    //U16 file_name_path[MMI_SNDREC_FULL_NAME_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if change file, clear rectime to 0 */
    g_sndrec_cntx.record.rectime = 0;
    bret = mmi_sndrec_util_get_next_pre_rec(g_sndrec_cntx.record.isnext, (CHAR*) g_sndrec_cntx.record.displayname);  

    if (bret)
    {
        mmi_sndrec_play_next_req();
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_PLAY_NEXT_SUCC);
    }
    ClearKeyEvents();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_play_next_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_play_next_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If pressed next when playing file will send play request else only change the display name */
    if (g_sndrec_cntx.record.isplay)
    {
        bret = mmi_sndrec_send_play_req(g_sndrec_cntx.record.displayname, mmi_sndrec_play_end_cb);
        if (bret)
        {
            mmi_sndrec_redraw_skins_animal_img(MMI_TRUE);
            mmi_sndrec_show_time_text(MMI_TRUE);
            mmi_sndrec_redraw_file_name(g_sndrec_cntx.record.displayname); 
            mmi_sndrec_redraw_main_lsk();
            mmi_sndrec_redraw_main_rsk();
            mmi_sndrec_redraw_record_btn(MMI_FALSE);
            mmi_sndrec_redraw_play_btn(MMI_FALSE);

#ifdef __MMI_FTE_SUPPORT__
            mmi_sndrec_redraw_stop_btn(MMI_FALSE);
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
            mmi_sndrec_redraw_list_btn(MMI_FALSE);
#endif
#else
            mmi_sndrec_redraw_state_text();
#endif 
            mmi_sndrec_blt_screen();
        }
    }
    else
    {
        mmi_sndrec_redraw_skins_animal_img(MMI_FALSE);
        mmi_sndrec_show_time_text(MMI_FALSE);
        mmi_sndrec_redraw_file_name(g_sndrec_cntx.record.displayname);	
        mmi_sndrec_redraw_main_lsk();
        mmi_sndrec_redraw_main_rsk();
        mmi_sndrec_redraw_record_btn(MMI_FALSE);
        mmi_sndrec_redraw_play_btn(MMI_FALSE);
#ifdef __MMI_FTE_SUPPORT__
        /* remove out of this later for NON FTE */
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        mmi_sndrec_redraw_list_btn(MMI_FALSE);
#endif
#else
        mmi_sndrec_redraw_state_text();
#endif /* __MMI_FTE_SUPPORT__ */ 
        mmi_sndrec_blt_screen();
    }
}

#else /* __MMI_SNDREC_SKIN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_show_record_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_show_record_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guibuffer;
    U16 leftkeyid = 0, rightkeyid = 0;
    U16 imgid = 0;
    U16 timeflag = 0;
    U32 duration = 0;
#ifdef __MMI_SNDREC_SLIM__
    WCHAR* title;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_SHOW_RECORD_SCREEN, g_sndrec_cntx.record.state);

    guibuffer = mmi_frm_scrn_get_active_gui_buf();
    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_IDLE_STATE:
            MMI_SNDREC_MSG_TRACE(1);
            leftkeyid = STR_GLOBAL_OPTIONS;
            rightkeyid = STR_GLOBAL_BACK;
            timeflag = 0;
            imgid = 0;
            break;

        case MMI_SNDREC_REC_STATE:
            leftkeyid = STR_GLOBAL_PAUSE;
            rightkeyid = STR_GLOBAL_STOP;
            timeflag = 1;
            imgid = IMG_ID_SNDREC_ANIMAL_RECORD;
            break;

        case MMI_SNDREC_REC_PAUSE_STATE:
            leftkeyid = STR_GLOBAL_CONTINUE;
            rightkeyid = STR_GLOBAL_STOP;
            timeflag = 0;
        #ifdef __MMI_MAINLCD_96X64__
            imgid = IMG_ID_SNDREC_ANIMAL_REC_PAUSE;
        #else
            imgid = 0;
        #endif
            break;
            
        default:
            break;
    }

    duration = mmi_sndrec_get_ticks();
    
    if (1 == timeflag)
    {
        mmi_sndrec_start_ticks();
    }

#ifdef __MMI_SNDREC_SLIM__

    /* Show the filename as title when file exist */
    if (mmi_sndrec_is_file_exist() && !mmi_sndrec_check_file_isnull())
    {
        title = (WCHAR*)g_sndrec_cntx.record.displayname;
    }
    else
    {
        title = (WCHAR*)get_string(STR_ID_SNDREC_MAIN);
    }

    /* ShowCategory223Screen_ext slim modification - removed lsk and rsk image parameter */
    ShowCategory223Screen_ext(
        title,
        (PU8)GetImage((U16)GetRootTitleIcon(MENU_ID_SNDREC_MAIN)),
        leftkeyid,
        /*0,*/
        rightkeyid,
        /*0,*/
        imgid,
        timeflag,
        duration,
        guibuffer);
#else

    ShowCategory223Screen(
        STR_ID_SNDREC_MAIN,
        GetRootTitleIcon(MENU_ID_SNDREC_MAIN),
        leftkeyid,
        0,
        rightkeyid,
        0,
        imgid,
        timeflag,
        duration,
        guibuffer);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_left_key_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_left_key_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_REC_LSK_PRESS, g_sndrec_cntx.record.state);

    switch (g_sndrec_cntx.record.state)
    {
        case MMI_SNDREC_IDLE_STATE:
            mmi_sndrec_entry_option_screen();
            break;

        case MMI_SNDREC_REC_STATE:
            res = mmi_sndrec_send_pause_req(MMI_SNDREC_REC_PAUSE_STATE);
            if (res)
            {
                mmi_sndrec_update_rec_ticks();
                mmi_sndrec_show_record_screen();
            }
            break;

        case MMI_SNDREC_REC_PAUSE_STATE:
            res = mmi_sndrec_send_resume_req(MMI_SNDREC_REC_STATE);
            if (res)
            {
                /* mmi_sndrec_start_duration(); */
                mmi_sndrec_show_record_screen();
            }
            break;

        default:
            MMI_SNDREC_ERR_TRACE(g_sndrec_cntx.record.state);
            MMI_SNDREC_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_right_key_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_right_key_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_REC_RSK_PRESS, g_sndrec_cntx.record.state);

    g_sndrec_cntx.record.isStopBySelf = MMI_TRUE;

    if (MMI_SNDREC_IDLE_STATE == g_sndrec_cntx.record.state)
    {
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        mmi_sndrec_send_stop_req(MMI_TRUE);
    }
}

#endif /* __MMI_SNDREC_SKIN__ */ 


///*****************************************************************************
// * FUNCTION
// *  mmi_sndrec_vm_record_in_call_cb
// * DESCRIPTION
// *  
// * PARAMETERS
// *  param       [?]     
// * RETURNS
// *  void
// *****************************************************************************/
// mmi_ret mmi_sndrec_vm_record_in_call_cb(void *param)
//{
//    /*----------------------------------------------------------------*/
//    /* Local Variables                                                */
//    /*----------------------------------------------------------------*/
//
//    mmi_evt_mdi_audio_speech_ind_struct *event = (mmi_evt_mdi_audio_speech_ind_struct*) param;
//
//    /*----------------------------------------------------------------*/
//    /* Code Body                                                      */
//    /*----------------------------------------------------------------*/
//    switch (event->status)
//    {
//        case MDI_AUDIO_SPH_PRE_SPEECH_OFF:
//            mmi_sndrec_send_stop_req(MMI_TRUE);
//            mmi_frm_cb_dereg_event(
//                EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND,
//                (mmi_proc_func) mmi_sndrec_vm_record_in_call_cb,
//                NULL);
//            break;
//        default:
//            break;
//    }
//    return MMI_RET_OK;   
//}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_exit_main_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_exit_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_EXIT_MAIN_SCREEN, g_sndrec_cntx.record.state);

    if ((g_sndrec_cntx.record.state == MMI_SNDREC_REC_STATE) ||
        (g_sndrec_cntx.record.state == MMI_SNDREC_REC_PAUSE_STATE))
    {
        g_sndrec_cntx.record.is_break = MMI_TRUE;
        mmi_sndrec_send_stop_req(MMI_TRUE);
    }
#ifdef __MMI_SNDREC_SKIN__
    mmi_sndrec_exit_draw_screen();
    mmi_sndrec_blt_screen();
    if (g_sndrec_cntx.record.is_timer_on == MMI_TRUE)
    {
        MMI_SNDREC_MSG_TRACE(0);
        g_sndrec_cntx.record.is_timer_on = MMI_FALSE;
        gui_cancel_timer(mmi_sndrec_get_drive_size);
    }
#else /* __MMI_SNDREC_SKIN__ */ 
    mmi_sndrec_update_rec_ticks();
#endif /* __MMI_SNDREC_SKIN__ */ 

     mmi_frm_end_scenario(MMI_SCENARIO_ID_SND_REC);
    

    /* Play, Play Pause, Preview, Preview states are not present in SLIM (Use Audio Player API) */
    #ifdef __MMI_SNDREC_SKIN__
    if ((g_sndrec_cntx.record.state != MMI_SNDREC_PLAY_STATE) &&
        (g_sndrec_cntx.record.state != MMI_SNDREC_PLAY_PAUSE_STATE) &&
        (g_sndrec_cntx.record.state != MMI_SNDREC_PREVIEW_STATE) &&
        (g_sndrec_cntx.record.state != MMI_SNDREC_PREVIEW_PAUSE_STATE))
    #endif
    {
        mmi_sndrec_bgsound_resume();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_delete_main_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_delete_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_DELETE_MAIN_SCREEN, g_sndrec_cntx.record.state);

#ifndef __MMI_SNDREC_SLIM__
    g_sndrec_cntx.record.isappend = MMI_FALSE;
#endif
    g_sndrec_cntx.record.is_break = MMI_FALSE;
    g_sndrec_cntx.record.is_in_app = MMI_FALSE;
    mmi_sndrec_clear_file_name();

    if (g_sndrec_cntx.record.state != MMI_SNDREC_IDLE_STATE)
    {
        if (g_sndrec_cntx.record.state == MMI_SNDREC_REC_STATE ||
            g_sndrec_cntx.record.state == MMI_SNDREC_REC_PAUSE_STATE)
        {
            g_sndrec_cntx.record.isdelete = MMI_TRUE;
            mmi_sndrec_send_stop_req(MMI_TRUE);
        }
        else
        {
            mmi_sndrec_send_stop_req(MMI_FALSE);
        }
    }
    /* clear last record time */
    #if defined(__MMI_OP02_LEMEI__)
    mmi_sndrec_enable_record_pause();
    #endif
#ifdef __MMI_OP12_SNDREC_STYLE__
    mmi_sndrec_preview_flag = MMI_FALSE;
#endif 
    mmi_sndrec_bgsound_resume();
    mmi_sndrec_sms_record_callback = NULL;
    if (g_sndrec_cntx.record.isEntryFromOther)
    {
        g_size_limit = 0;
        g_time_limit = 0;
        g_sndrec_cntx.record.isEntryFromOther = MMI_FALSE;
    }
    g_sndrec_cntx.record.isIncall = MMI_FALSE;
    g_sndrec_cntx.record.isdelete = MMI_FALSE;
    mmi_sndrec_init_time();
    /* release file list */
#ifdef __MMI_SNDREC_SKIN__
    mmi_sndrec_util_reclist_free();
#endif 

#ifdef __MMI_SNDREC_SKIN__
#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_clear_volume_sync_callback(APP_SOUNDRECORDER);
#endif
#endif

/* Unload DCM for Sound Recorder if exit from app */
#ifdef __MMI_AP_DCM_SNDREC__
    mmi_ap_post_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_SNDREC);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_func_allow_incall
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sndrec_func_allow_incall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        mmi_ucm_app_entry_error_message();
        return MMI_FALSE;
    }
#else /* __MMI_BACKGROUND_CALL__ */ 
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        mmi_popup_display_ext(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL, MMI_EVENT_WARNING, NULL);
        return MMI_FALSE;
    }
#endif /* __MMI_BACKGROUND_CALL__ */ 
    return MMI_TRUE;
}

#define __SNDREC_UI_OPT__


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_set_option_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_menu_id      [IN]        
 *  MMI_ID(?)           [IN]        Parent_menu_id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_set_option_menu(mmi_id parent_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 file_path_name[MMI_SNDREC_FULL_NAME_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sndrec_get_full_file_name((U16*) file_path_name, (U16*) g_sndrec_cntx.record.displayname);

    /* Hide the menu items first, then unhide depending on below scenario */
    cui_menu_set_item_hidden(parent_menu_id, MENU_ID_SNDREC_RECORD_PLAY, MMI_TRUE);

#ifndef __MMI_SNDREC_SLIM__
    /* For SLIM Append in main option is wrapped */
    cui_menu_set_item_hidden(parent_menu_id, MENU_ID_SNDREC_APPEND, MMI_TRUE);
    /* For SLIM Rename, Delete in main option menu are wrapped */
    cui_menu_set_item_hidden(parent_menu_id, MENU_ID_SNDREC_RENAME, MMI_TRUE);
    cui_menu_set_item_hidden(parent_menu_id, MENU_ID_SNDREC_DELETE, MMI_TRUE);
#endif

#ifndef __MMI_SNDREC_SLIM_SETTINGS__
    cui_menu_set_item_hidden(parent_menu_id, MENU_ID_SNDREC_SETTING, MMI_TRUE);
#endif

#ifndef __MMI_SNDREC_SLIM__
    /* For SLIM Send As and Use As in main option menu are wrapped */
    cui_menu_set_item_hidden(parent_menu_id, MENU_ID_SNDREC_FORWARD_USE, MMI_TRUE);
    cui_menu_set_item_hidden(parent_menu_id, MENU_ID_SNDREC_FORWARD_SEND, MMI_TRUE);
#endif

    if (mmi_sndrec_useby_others_with_cb())
    {
        /* Default set of the menu items are hidden */
    }
    else if (!mmi_sndrec_is_file_exist() || mmi_sndrec_check_file_isnull())
    {
        /* unhide valid menu */
    #ifndef __MMI_SNDREC_SLIM_SETTINGS__
        cui_menu_set_item_hidden(parent_menu_id, MENU_ID_SNDREC_SETTING, MMI_FALSE);
    #endif
        cui_menu_set_item_hidden(parent_menu_id, MENU_ID_SNDREC_RECORD_LIST, MMI_FALSE);
    }
    else
    {
        /* unhide valid menu */
        cui_menu_set_item_hidden(parent_menu_id, MENU_ID_SNDREC_RECORD_PLAY, MMI_FALSE);

    #ifndef __MMI_SNDREC_SLIM__
        /* For SLIM Rename, Delete in main option menu are wrapped */
        cui_menu_set_item_hidden(parent_menu_id, MENU_ID_SNDREC_RENAME, MMI_FALSE);
        cui_menu_set_item_hidden(parent_menu_id, MENU_ID_SNDREC_DELETE, MMI_FALSE);
    #endif

    #ifndef __MMI_SNDREC_SLIM_SETTINGS__
        cui_menu_set_item_hidden(parent_menu_id, MENU_ID_SNDREC_SETTING, MMI_FALSE);
    #endif

        cui_menu_set_item_hidden(parent_menu_id, MENU_ID_SNDREC_RECORD_LIST, MMI_FALSE);

        /* Judge if need hide append item */
    #ifndef __MMI_SNDREC_SLIM__
        if (mmi_sndrec_check_file_type(g_sndrec_cntx.record.displayname, MMI_SNDREC_NAME_WAV) || mmi_sndrec_check_file_type(g_sndrec_cntx.record.displayname, MMI_SNDREC_NAME_OGG))  
        {
            cui_menu_set_item_hidden(parent_menu_id, MENU_ID_SNDREC_APPEND, MMI_TRUE);
        }
        else
        {
            cui_menu_set_item_hidden(parent_menu_id, MENU_ID_SNDREC_APPEND, MMI_FALSE);
        }
    #endif

        /* Judge if need hide forward item */
        /* For SLIM Send As and Use As in main option menu are wrapped */
    #ifndef __MMI_SNDREC_SLIM__
        if (mmi_sndrec_types_get_use_option_menu() <= 0)
        {
            cui_menu_set_item_hidden(parent_menu_id, MENU_ID_SNDREC_FORWARD_USE, MMI_TRUE);
        }
        else
        {
            cui_menu_set_item_hidden(parent_menu_id, MENU_ID_SNDREC_FORWARD_USE, MMI_FALSE);

        }

        if (mmi_sndrec_types_get_send_option_menu() <= 0)
        {
            cui_menu_set_item_hidden(parent_menu_id, MENU_ID_SNDREC_FORWARD_SEND, MMI_TRUE);
        }
        else
        {
            cui_menu_set_item_hidden(parent_menu_id, MENU_ID_SNDREC_FORWARD_SEND, MMI_FALSE);
        }
    #endif
    #ifdef __MMI_OP12_SNDREC_STYLE__
        cui_menu_set_item_hidden(parent_menu_id, MENU_ID_SNDREC_APPEND, MMI_TRUE);
    #endif 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_option_screen_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_evt        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_sndrec_entry_option_screen_select_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_ID_SNDREC_NEW_RECORD:
        {
            mmi_sndrec_new_record_hdlr();
        }
            break;
        case MENU_ID_SNDREC_RECORD_PLAY:
        {
            mmi_sndrec_rec_play_select();
        }
            break;
    #ifndef __MMI_SNDREC_SLIM__
        case MENU_ID_SNDREC_APPEND:
        {
            mmi_sndrec_append();
        }
            break;
        case MENU_ID_SNDREC_RENAME:
        {
            mmi_sndrec_entry_edit_name();
        }
            break;
        case MENU_ID_SNDREC_DELETE:
        {
            mmi_sndrec_entry_delete_cnf();
        }
            break;
    #endif
        case MENU_ID_SNDREC_RECORD_LIST:
        {
            mmi_sndrec_entry_record_list();
        }
            break;
    #ifndef __MMI_SNDREC_SLIM_SETTINGS__
        case MENU_ID_SNDREC_SETTING:
        {
            mmi_sndrec_pre_entry_setting_screen();
        }
            break;
    #endif
    #ifndef __MMI_SNDREC_SLIM__
        case MENU_ID_SNDREC_FORWARD_USE:
            break;
        case MENU_ID_SNDREC_FORWARD_SEND:
            break;
    #endif
    }
    return MMI_RET_OK;
}


#ifndef __MMI_SNDREC_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_option_use_init_list
 * DESCRIPTION
 *  init use option list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_option_use_init_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 parent_menu_id;
    S32 sub_menu_id;
    U16 sub_id_num;
    U16 sub_ids[MAX_SUB_MENUS];
    U16 sub_id_strs[MAX_SUB_MENUS];
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* condition: have saved the image
       use filepath to ask fmgr for send option and init the sub menu list of send */
    parent_menu_id = mmi_sndrec_types_get_use_option_menu();
    sub_id_num = GetNumOfChild_Ext(parent_menu_id);
    GetSequenceStringIds_Ext(parent_menu_id, sub_id_strs);

    for (i = 0; i < sub_id_num; i++)
    {
        sub_ids[i] = GetSeqItemId_Ext(parent_menu_id, i);
    }

    if (parent_menu_id > 0)
    {
        cui_menu_set_currlist(mmi_frm_group_get_active_id(), sub_id_num, (MMI_MENU_ID*) sub_ids);

        for (i = 0; i < sub_id_num; i++)
        {
            sub_menu_id = cui_menu_get_currlist_menu_id_from_index(mmi_frm_group_get_active_id(), i);

            cui_menu_set_item_string_by_id(mmi_frm_group_get_active_id(), sub_menu_id, sub_id_strs[i]);
        }
    }
    cui_menu_set_default_title_image_by_id(mmi_frm_group_get_active_id(), GetRootTitleIcon(MENU_ID_SNDREC_MAIN));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_types_get_use_option_menu
 * DESCRIPTION
 *  init use option list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_sndrec_types_get_use_option_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 file_path_name[MMI_SNDREC_FULL_NAME_LEN + 1];
    S32 parent_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sndrec_get_full_file_name((U16*) file_path_name, (U16*) g_sndrec_cntx.record.displayname);
    parent_menu_id = srv_fmgr_types_get_use_option_menu(FMGR_TYPE_ALL, (WCHAR*)file_path_name);
    return parent_menu_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_types_get_send_option_menu
 * DESCRIPTION
 *  init use option list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_sndrec_types_get_send_option_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 file_path_name[MMI_SNDREC_FULL_NAME_LEN + 1];
    S32 parent_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sndrec_get_full_file_name((U16*) file_path_name, (U16*) g_sndrec_cntx.record.displayname);
    parent_menu_id = srv_fmgr_types_get_send_option_menu(FMGR_TYPE_ALL, (WCHAR*) file_path_name);
    return parent_menu_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_option_send_init_list
 * DESCRIPTION
 *  init use option list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_option_send_init_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 parent_menu_id;
    S32 sub_menu_id;
    U16 sub_id_num;
    U16 sub_ids[MAX_SUB_MENUS];
    U16 sub_id_strs[MAX_SUB_MENUS];
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    parent_menu_id = mmi_sndrec_types_get_send_option_menu();
    sub_id_num = GetNumOfChild_Ext(parent_menu_id);
    GetSequenceStringIds_Ext(parent_menu_id, sub_id_strs);

    for (i = 0; i < sub_id_num; i++)
    {
        sub_ids[i] = GetSeqItemId_Ext(parent_menu_id, i);
    }

    if (parent_menu_id > 0)
    {
        cui_menu_set_currlist(mmi_frm_group_get_active_id(), sub_id_num, (MMI_MENU_ID*) sub_ids);

        for (i = 0; i < sub_id_num; i++)
        {
            sub_menu_id = cui_menu_get_currlist_menu_id_from_index(mmi_frm_group_get_active_id(), i);

            cui_menu_set_item_string_by_id(mmi_frm_group_get_active_id(), sub_menu_id, sub_id_strs[i]);
        }
    }
    cui_menu_set_default_title_image_by_id(mmi_frm_group_get_active_id(), GetRootTitleIcon(MENU_ID_SNDREC_MAIN));
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_option_screen_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_sndrec_entry_option_screen_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    //U16 file_path_name[MMI_SNDREC_FULL_NAME_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {

        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            switch (menu_evt->parent_menu_id)
            {
                case MENU_ID_SNDREC_OPTION:
                {
                    mmi_sndrec_set_option_menu((mmi_id) menu_evt->sender_id);
                #ifndef __MMI_SNDREC_SLIM__
                    if (mmi_sndrec_types_get_use_option_menu() > 0)
                    {

                        cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_SNDREC_FORWARD_USE, MMI_TRUE);
                    }

                    if (mmi_sndrec_types_get_send_option_menu() > 0)
                    {
                        cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_SNDREC_FORWARD_SEND, MMI_TRUE);
                    }
                #endif
                    cui_menu_set_default_title_image_by_id(
                        menu_evt->sender_id,
                        GetRootTitleIcon(MENU_ID_SNDREC_MAIN));

                }
                cui_menu_set_default_left_softkey_by_id(menu_evt->sender_id,STR_GLOBAL_OK);
                    break;
            #ifndef __MMI_SNDREC_SLIM__
                case MENU_ID_SNDREC_FORWARD_USE:
                {
                    mmi_sndrec_option_use_init_list();
                }
                    break;
                case MENU_ID_SNDREC_FORWARD_SEND:
                {
                    mmi_sndrec_option_send_init_list();
                }
                    break;
            #endif

            }

        }
            break;
            
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            if(menu_evt ->highlighted_menu_id == MENU_ID_SNDREC_LIST_PLAY)
            {
                SetLeftSoftkeyFunction(mmi_sndrec_list_play_select, KEY_EVENT_UP);
            }
            break;
            
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            if (menu_evt->parent_menu_id == MENU_ID_SNDREC_OPTION)
            {
                mmi_sndrec_entry_option_screen_select_hdlr(menu_evt);
            }
        #ifndef __MMI_SNDREC_SLIM__
            else if (menu_evt->parent_menu_id == MENU_ID_SNDREC_FORWARD_USE || menu_evt->parent_menu_id == MENU_ID_SNDREC_FORWARD_SEND)
            {
            	U16 file_path_name[MMI_SNDREC_FULL_NAME_LEN + 1];
                mmi_sndrec_get_full_file_name(file_path_name,g_sndrec_cntx.record.displayname); 
                srv_fmgr_types_launch_option((WCHAR*)file_path_name, menu_evt->highlighted_menu_id);
            }
        #endif

        }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
        }
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_option_screen
 * DESCRIPTION
 *  Do not call this function directly,
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_entry_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 //   MMI_ID menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Every time entry option list, release file list */
#ifdef __MMI_SNDREC_SKIN__
    mmi_sndrec_util_reclist_free();
#endif 

    mmi_frm_group_create_ex(GRP_ID_SNDREC_MAIN, GRP_ID_SNDREC_OPTION, mmi_sndrec_entry_option_screen_proc, (void*)NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    g_current_id = GRP_ID_SNDREC_OPTION;

    cui_menu_create_and_run(
             GRP_ID_SNDREC_OPTION,
             CUI_MENU_SRC_TYPE_RESOURCE,
             CUI_MENU_TYPE_OPTION,
             MENU_ID_SNDREC_OPTION,
             MMI_TRUE,
             NULL);
}

#define __SNCREC_UI_REC_OPT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_record_list_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]        Event
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_sndrec_entry_record_list_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    cui_folder_browser_on_menu_event_struct *option_menu_evt = (cui_folder_browser_on_menu_event_struct*) menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {

        case EVT_ID_GROUP_DEINIT:
            mmi_frm_group_close(GRP_ID_SNDREC_START_BASE);
            break;

        case EVT_ID_CUI_FOLDER_BROWSER_ON_QUIT:
            cui_folder_browser_close(g_sndrec_cntx.record.fmgr_id);
            mmi_frm_group_close(GRP_ID_SNDREC_START_BASE);
            break;

        case EVT_ID_CUI_FOLDER_BROWSER_ON_MENU:
        {
            switch (option_menu_evt->menuitem_id)
            {
                case MENU_ID_SNDREC_LIST_PLAY:
                {
                    mmi_sndrec_list_play_select();
                #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
                    mmi_sndrec_pre_entry_main_screen();
                #else                
                    mmi_frm_group_close(g_sndrec_cntx.record.fmgr_id);
                #endif

                    return MMI_RET_DONT_CARE;
                }

            #ifndef __MMI_SNDREC_SLIM__
                case MENU_ID_SNDREC_LIST_APPEND:
                {
                    mmi_sndrec_append();
                    mmi_frm_group_close(g_sndrec_cntx.record.fmgr_id);
                    return MMI_RET_DONT_CARE;
                }
            #endif
                
                default:
                    break;
            }

            break;
        }

        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_record_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_entry_record_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 filepath[MMI_SNDREC_PATH_LEN];
    FMGR_FILTER filter = {0};
    MMI_ID fmgr_grp_id;
    MMI_ID parent_id = GRP_ID_SNDREC_OPTION;
    S32 drive_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (!mmi_sndrec_func_allow_incall())
    {
         return;
    }
    
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    if (mmi_sndrec_check_usb_mode())
    {
        /* Unload DCM for Sound Recorder */
    #ifdef __MMI_AP_DCM_SNDREC__
        mmi_ap_send_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_SNDREC);
    #endif
        return;
    }
#endif

    if (mmi_sndrec_check_drive_is_external_drive(g_sndrec_cntx.setting.drive, &drive_type) == MMI_TRUE)
    {
        if (mmi_sndrec_entry_mc_rules() == MMI_TRUE)
        {
            g_sndrec_mc_cb = mmi_sndrec_entry_record_list;
            return;
        }
    }
    if (!mmi_sndrec_check_folder_valid())
    {
        return;
    }

    if (mmi_frm_group_is_present(GRP_ID_SNDREC_OPTION) == MMI_FALSE)
    {
    #ifdef __MMI_SNDREC_SKIN__
        mmi_sndrec_util_reclist_free();
    #endif 
        parent_id = mmi_frm_group_get_active_id();
    }

    mmi_frm_group_create_ex(parent_id, GRP_ID_SNDREC_START_BASE, mmi_sndrec_entry_record_list_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    g_current_id = GRP_ID_SNDREC_START_BASE;
    
    mmi_sndrec_util_filter_set(&filter);
    mmi_sndrec_get_file_path(filepath);

    fmgr_grp_id = cui_folder_browser_create(
                    GRP_ID_SNDREC_START_BASE,
                    (WCHAR*) filepath,
                    &filter,
                    CUI_FOLDER_BROWSER_OPT_USE_CSK_OFF,
                    MENU_ID_SNDREC_REC_OPTION,
                    0);
    if (fmgr_grp_id != GRP_ID_INVALID)
    {

        g_sndrec_cntx.record.fmgr_id = fmgr_grp_id;
        cui_folder_browser_set_title(fmgr_grp_id, STR_ID_SNDREC_MAIN, GetRootTitleIcon(MENU_ID_SNDREC_MAIN));
        cui_folder_browser_run(fmgr_grp_id);

    }

}

#define __SNDREC_UI_PLAY__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_list_play_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_list_play_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 filepath[MMI_SNDREC_PATH_LEN];
    srv_fmgr_fileinfo_struct file_info;
    WCHAR *file_name;
    S32 fs_result;
    WCHAR buffer[MMI_SNDREC_FULL_NAME_LEN + 20];
    mmi_id grp_id;
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_ENTRY_LIST_PLAY);

    if (!mmi_sndrec_func_allow_incall())
    {
        return;
    }

    mmi_sndrec_get_file_path(filepath);

    fs_result = srv_fmgr_fs_path_exist(filepath);

    if (fs_result < FS_NO_ERROR)
    {
        mmi_popup_display_ext(srv_fmgr_fs_error_get_string(fs_result),MMI_EVENT_PROPLEM,NULL);
        return;
    }

    grp_id = g_sndrec_cntx.record.fmgr_id;
    index = cui_folder_browser_get_highlight_index(grp_id);
    cui_folder_browser_get_filepath(grp_id, index, &file_info, buffer, sizeof(buffer));
    file_name = (WCHAR*) srv_fmgr_path_get_filename_ptr((WCHAR*) buffer);
    if (!buffer)
    {
        MMI_SNDREC_ASSERT(0);
    }


    if (0 != mmi_wcscmp(file_name, g_sndrec_cntx.record.displayname))
    {
        mmi_sndrec_init_time();
    }

    mmi_wcscpy(g_sndrec_cntx.record.displayname,file_name);
    mmi_sndrec_rec_play_select();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_rec_play_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_rec_play_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
#ifdef __MMI_SNDREC_SKIN__
    MMI_BOOL res;
#else
    U16 file_path_name[MMI_SNDREC_FULL_NAME_LEN + 1];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_ENTRY_REC_PLAY);

    if (!mmi_sndrec_func_allow_incall())
    {
        return;
    }

#ifdef __MMI_SNDREC_SKIN__

    res = mmi_sndrec_send_play_req(g_sndrec_cntx.record.displayname, mmi_sndrec_play_end_cb);
    if (res)
    {
        mmi_frm_group_close(GRP_ID_SNDREC_OPTION);
    }
    else
    {
        mmi_sndrec_bgsound_resume();
    }
    mmi_frm_group_close(GRP_ID_SNDREC_OPTION);

#else /* __MMI_SNDREC_SKIN__ */ 

        mmi_sndrec_get_full_file_name(file_path_name,g_sndrec_cntx.record.displayname);
    
        mmi_media_app_play_audio_with_title(
            (CHAR*)file_path_name,
             NULL,
            GetRootTitleIcon(MENU_ID_SNDREC_MAIN),
            STR_ID_SNDREC_MAIN);
        
    #if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif 
#endif /* __MMI_SNDREC_SKIN__ */ 
}

#if !defined (__MMI_SNDREC_SKIN__)
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif //!defined (__MMI_SNDREC_SKIN__) 

#ifdef __MMI_SNDREC_SKIN__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_play_end_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_play_end_cb(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_PLAY_END_CALLBACK, result);

    if (MDI_AUDIO_END_OF_FILE == result || MDI_AUDIO_TERMINATED == result)
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_SNDREC_MAIN)
        {
            /* When come from next prev no need to update screen to show record idle screen */
            if (g_sndrec_no_idle_next_prev == MMI_FALSE)
            {
                mmi_sndrec_redraw_record_btn(MMI_FALSE);
                mmi_sndrec_redraw_play_btn(MMI_FALSE);
                mmi_sndrec_redraw_prev_btn(MMI_FALSE);
                mmi_sndrec_redraw_next_btn(MMI_FALSE);
            #ifdef __MMI_FTE_SUPPORT__
                /* remove out of this later for NON FTE */
            #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
                mmi_sndrec_redraw_list_btn(MMI_FALSE);
            #endif
            // TODO: mtk81132
                mmi_sndrec_redraw_stop_btn(MMI_FALSE);
        
            #endif /* __MMI_FTE_SUPPORT__ */ 
                
            #if defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
                mmi_sndrec_is_play_flag = MMI_TRUE;

                if(mmi_sndrec_is_play_goback)
                {
                   mmi_sndrec_is_play_goback = MMI_FALSE;  
                }
                else
                {                    
                    mmi_sndrec_redraw_main_lsk();     
                }
            #else
                mmi_sndrec_redraw_main_lsk();
            #endif                
                    
                mmi_sndrec_redraw_main_rsk();
                mmi_sndrec_redraw_skins_animal_img(MMI_FALSE);
                mmi_sndrec_show_time_text(MMI_FALSE);
            #ifndef __MMI_FTE_SUPPORT__
                mmi_sndrec_redraw_state_text();
            #endif 
                mmi_sndrec_blt_screen();
            }
            g_sndrec_no_idle_next_prev = MMI_FALSE;
        }
        else
        {
            /* When play stoppend and not in sound recorder main screen, resume the background play MAUI_03212201 */
            mmi_sndrec_bgsound_resume();
        }
    }
    else
    {
        mmi_sndrec_error_hdlr(result, MMI_FALSE);
    }
#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
}
#endif /* __MMI_SNDREC_SKIN__ */ 

#define __SNDREC_UI_RECORD__

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_new_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_sndrec_new_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    MMI_BOOL res;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_sndrec_check_folder_valid())
    {
        return MMI_FALSE;
    }

#if 0    /* Auto Record Phased Out */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_SNDREC_SKIN__
    mmi_sndrec_util_reclist_free();
#endif

    g_sndrec_cntx.record.quality = g_sndrec_cntx.setting.quality;
    mmi_sndrec_get_new_file(MMI_SNDREC_FORMAT_NULL);

    res = mmi_sndrec_send_record_req(
            g_sndrec_cntx.record.displayname,
            (U8)MEDIA_FORMAT_NONE,
            g_sndrec_cntx.record.quality);
    if (res)
    {
    #ifndef __MMI_SNDREC_SLIM__
        g_sndrec_cntx.record.isappend = MMI_FALSE;
    #endif
    }
    return res;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_new_record_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_new_record_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drive_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_sndrec_check_drive_is_external_drive(g_sndrec_cntx.setting.drive, &drive_type) == MMI_TRUE)
    {
        if (mmi_sndrec_entry_mc_rules() == MMI_TRUE)
        {
            g_sndrec_mc_cb = mmi_sndrec_new_record_hdlr;
            return;
        }
    }

#if 0    /* Auto Record Phased Out */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __CTM_SUPPORT__
    if (srv_callset_ctm_get_mode() == MMI_TRUE && g_sndrec_cntx.record.isIncall)
    {
        mmi_popup_display_ext(STR_ID_SNDREC_NOT_ALLOWED_IN_CTM_CALL, MMI_EVENT_FAILURE, NULL);
        return;
    }
#endif /* __CTM_SUPPORT__ */ 

    if (mmi_sndrec_new_record())
    {
        mmi_frm_group_close(GRP_ID_SNDREC_OPTION);
    }
    else
    {
        mmi_sndrec_bgsound_resume();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_record_stop_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_record_stop_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
     MMI_BOOL is_incall_now = (MMI_BOOL)srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_end_scenario(MMI_SCENARIO_ID_SND_REC);
    if ((!g_sndrec_cntx.record.isdelete) &&(!g_sndrec_cntx.record.is_break))
    {
    #ifndef __MMI_OP12_SNDREC_STYLE__
        #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
        mmi_sndrec_redraw_main_rsk();
        #endif
        mmi_sndrec_entry_save_query();
    #else 
        mmi_sndrec_entry_save_option();
    #endif 
    }
    else
    {
    #ifndef __MMI_SNDREC_SLIM__
        g_sndrec_cntx.record.isappend = MMI_FALSE;
    #endif
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_save_query
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_save_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if 0 //__MMI_BASIC_UI_STYLE__ 
/* under construction !*/
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_sndrec_is_file_exist())
    {
        mmi_popup_display_simple_ext(
            FMGR_FS_FILE_NOT_FOUND_TEXT, 
            MMI_EVENT_FAILURE, 
            GRP_ID_SNDREC_MAIN,
            NULL);       
        if (g_sndrec_cntx.record.isEntryFromOther)
        {
            mmi_sndrec_cb_for_other_app(MMI_FALSE);
            mmi_sndrec_delete_self();
            return;
        }
        mmi_sndrec_clear_file_name();
        mmi_sndrec_init_time();
    #ifndef __MMI_SNDREC_SLIM__
        g_sndrec_cntx.record.isappend = MMI_FALSE;
    #endif

        return;
    }

    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    srv_prof_play_tone(mmi_get_event_based_sound(MMI_EVENT_QUERY), NULL);

#if defined(__MMI_OP02_LEMEI__)
    if(mmi_sndrec_query_is_record_pause_enabled() == MMI_FALSE)
    {
        if(g_sndrec_cntx.record.need_save == MMI_TRUE)
        {
            mmi_sndrec_entry_save();
        }
        else
        {
            mmi_sndrec_abort_save();
        }    
        return;
    }
#endif

    mmi_sndrec_entry_save();
}

#ifdef __MMI_OP02_LEMEI__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_abort_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_abort_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    U16 file_path_name[MMI_SNDREC_FULL_NAME_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sndrec_get_full_file_name(file_path_name,g_sndrec_cntx.record.displayname);    
    result = FS_Delete(file_path_name);
    
    if (result < 0)
    {
        mmi_popup_display_simple_ext(
            srv_fmgr_fs_error_get_string(result),
            MMI_EVENT_FAILURE,
            GRP_ID_SNDREC_MAIN,
            NULL);
    }

    if (mmi_sndrec_useby_others_with_cb())
    {
        if (mmi_sndrec_sms_record_callback != NULL)
        {
            mmi_sndrec_sms_record_callback(FALSE, file_path_name);
        #ifndef __MMI_OP12_SNDREC_STYLE__
            mmi_sndrec_sms_record_callback = NULL;
        #endif 
        }           
        else
        {
            MMI_SNDREC_ERR_TRACE(0);
        }
    #ifndef __MMI_OP12_SNDREC_STYLE__
        mmi_sndrec_delete_self();
    #endif 
        mmi_sndrec_init_time();
        mmi_sndrec_clear_file_name();
    }
    else if (g_sndrec_cntx.record.isEntryFromOther)
    {
        mmi_sndrec_cb_for_other_app(MMI_FALSE);
        mmi_sndrec_delete_self();
    }
    else
    {
        mmi_sndrec_init_time();
        mmi_sndrec_clear_file_name();
    }
#ifndef __MMI_SNDREC_SLIM__
    g_sndrec_cntx.record.isappend = MMI_FALSE;
#endif
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_entry_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    //MMI_STR_ID popup_str;
    U16 file_path_name[MMI_SNDREC_FULL_NAME_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sndrec_get_full_file_name(file_path_name,g_sndrec_cntx.record.displayname); 

    result = FS_GetAttributes(file_path_name);
    if (result >= FS_NO_ERROR)
    {
    #if defined(__MMI_OP02_LEMEI__)
        if(mmi_sndrec_query_is_record_pause_enabled() == MMI_TRUE)
    #endif
        //if (!g_sndrec_cntx.record.is_break)
        //{    
            mmi_popup_display_ext(STR_GLOBAL_SAVED, MMI_EVENT_SUCCESS, NULL);
            //mmi_popup_display_simple_ext(STR_GLOBAL_SAVED, MMI_EVENT_SUCCESS, GRP_ID_SNDREC_MAIN, NULL);
        //}
    }
    else
    {
        mmi_popup_display_ext(srv_fmgr_fs_error_get_string(result),(mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(result),NULL);
        //mmi_popup_display_simple_ext(srv_fmgr_fs_error_get_string(result),(mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(result), GRP_ID_SNDREC_MAIN, NULL);
    }


    /* Quit if is entry from other */
    if (g_sndrec_cntx.record.isEntryFromOther)
    {
        mmi_sndrec_cb_for_other_app((MMI_BOOL)(result >= FS_NO_ERROR));
        
        if (mmi_sndrec_sms_record_callback != NULL)
        {
            if (result >= FS_NO_ERROR)
            {
                mmi_sndrec_sms_record_callback(TRUE, file_path_name);
            }
            else
            {
                mmi_sndrec_sms_record_callback(FALSE, file_path_name);
            }
            mmi_sndrec_sms_record_callback = NULL;
        }
        mmi_sndrec_delete_self();
        return;
    }

    if (result < FS_NO_ERROR)
    {
        mmi_sndrec_clear_file_name();
        mmi_sndrec_init_time();
    }
#ifndef __MMI_SNDREC_SLIM__
    g_sndrec_cntx.record.isappend = MMI_FALSE;
#endif
}

#ifndef __MMI_SNDREC_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_append
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_append(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    U16 active_grp_id;
    S32 result;
    MMI_BOOL res;
    srv_fmgr_fileinfo_struct file_info = {0};
    S32 index = 0;
//    S32 fs_result;
//    SRV_FMGR_FILEINFO_HANDLE file_info_handle;
    WCHAR *file_name; // *filepath;
    WCHAR buffer[MMI_SNDREC_FULL_NAME_LEN + 20];
  //  S32 buffer_size = MMI_SNDREC_FULL_NAME_LEN;
    mmi_id grp_id;
    U16 file_path_name[MMI_SNDREC_FULL_NAME_LEN + 1];
  
  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
  mmi_sndrec_get_full_file_name(file_path_name,g_sndrec_cntx.record.displayname); 

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_APPEND_REQ);

    if (!mmi_sndrec_func_allow_incall())
    {
        return;
    }

#if 0 /* Auto Record Phased Out */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    if (g_current_id != GRP_ID_SNDREC_OPTION)
    {

        //memset(buffer, 0, sizeof(buffer));
        grp_id = g_sndrec_cntx.record.fmgr_id;
        index = cui_folder_browser_get_highlight_index(grp_id);
        cui_folder_browser_get_filepath(grp_id, index, &file_info, buffer, sizeof(buffer));
        file_name = (WCHAR*) srv_fmgr_path_get_filename_ptr((WCHAR*) buffer);
        if (!buffer)
        {
            MMI_SNDREC_ASSERT(0);
        }

        mmi_wcscpy( g_sndrec_cntx.record.displayname, file_name);
    }

    /* Add judge if file exist */
    result = FS_GetAttributes(file_path_name);
    if (result < FS_NO_ERROR)
    {
        mmi_popup_display_ext(srv_fmgr_fs_error_get_string(result),(mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(result),NULL);
    }
    else
    {
        /* Parse file format */
		
        g_sndrec_cntx.record.quality = g_sndrec_cntx.setting.quality;
		
        res = mmi_sndrec_send_record_req(
                g_sndrec_cntx.record.displayname,
                (U8)MEDIA_FORMAT_NONE,
                g_sndrec_cntx.record.quality);
        if (res)
        {
            g_sndrec_cntx.record.isappend = MMI_TRUE;
            mmi_frm_group_close(GRP_ID_SNDREC_OPTION);
        }
        else
        {
            mmi_sndrec_init_time();
            mmi_sndrec_bgsound_resume();
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_append_stop_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_append_stop_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sndrec_cntx.record.isappend = MMI_FALSE;
#ifdef __MMI_SNDREC_SKIN__
    mmi_sndrec_blt_screen();

    mmi_sndrec_redraw_file_name(g_sndrec_cntx.record.displayname);
    mmi_sndrec_redraw_skins_animal_img(MMI_FALSE);
    mmi_sndrec_show_time_text(MMI_FALSE);
#ifndef __MMI_FTE_SUPPORT__
    mmi_sndrec_redraw_state_text();
#else /* __MMI_FTE_SUPPORT__ */
    mmi_sndrec_redraw_rec_icon();
    mmi_sndrec_redraw_stop_btn(MMI_FALSE);
    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    mmi_sndrec_redraw_list_btn(MMI_FALSE);
    #endif
#endif /* __MMI_FTE_SUPPORT__ */
    mmi_sndrec_redraw_record_btn(MMI_FALSE);
    mmi_sndrec_redraw_play_btn(MMI_FALSE);
    mmi_sndrec_redraw_prev_btn(MMI_FALSE);
    mmi_sndrec_redraw_next_btn(MMI_FALSE);

    mmi_sndrec_redraw_main_lsk();
    mmi_sndrec_redraw_main_rsk();
    mmi_sndrec_blt_screen();
#else /* __MMI_SNDREC_SKIN__ */ 
    mmi_sndrec_show_record_screen();
#endif /* __MMI_SNDREC_SKIN__ */ 
}
#endif

#ifdef __MMI_OP12_SNDREC_STYLE__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_save_option_menu_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_evt        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_sndrec_save_option_menu_select_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_ID_SNDREC_FORWARD_SEND:
            break;
            
        case MENU_ID_SNDREC_SAVE_OPTION_PLAY:
            {
                mmi_sndrec_save_option_play();
            }
            break;
        case MENU_ID_SNDREC_SAVE_OPTION_SAVE:
            {
                mmi_sndrec_save_option_entry_rename();
            }
            break;
        case MENU_ID_SNDREC_SAVE_OPTION_DISCARD:
            {
                mmi_sndrec_save_option_discard_query();
            }
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_save_option_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_sndrec_save_option_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    U16 file_path_name[MMI_SNDREC_FULL_NAME_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sndrec_get_full_file_name(file_path_name,g_sndrec_cntx.record.displayname);

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            {
                mmi_frm_group_close(GRP_ID_SNDREC_AUDIO_SAVE_OPTION);
            }
            break;
            
        case EVT_ID_GROUP_ACTIVE:
            if (mmi_sndrec_is_file_exist() == MMI_FALSE)
            {
                mmi_sndrec_preview_flag = MMI_FALSE;
                mmi_frm_group_close(GRP_ID_SNDREC_AUDIO_SAVE_OPTION);
            }
            break;
            
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            {
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                if (menu_evt->parent_menu_id == MENU_ID_SNDREC_FORWARD_SEND)
                {
                    mmi_sndrec_option_send_init_list();
                }
                if (mmi_sndrec_types_get_send_option_menu() > 0)
                {
                    cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_SNDREC_FORWARD_SEND, MMI_TRUE);
                }

                if (mmi_sndrec_preview_flag)
                {
                    cui_menu_set_currlist_highlighted_id(menu_evt->sender_id, MENU_ID_SNDREC_SAVE_OPTION_PLAY);
                    mmi_sndrec_preview_flag = MMI_FALSE;
                }
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_HILITE:
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_SNDREC_SAVE_OPTION_PLAY:
                    SetLeftSoftkeyFunction(mmi_sndrec_save_option_play, KEY_EVENT_UP);
                    SetKeyHandler(mmi_sndrec_save_option_play, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                    break;
                    
                case MENU_ID_SNDREC_SAVE_OPTION_RENAME_SAVE:
                    SetLeftSoftkeyFunction(mmi_sndrec_save_option_rename_save, KEY_EVENT_UP);
                    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
                    SetKeyHandler(mmi_sndrec_save_option_rename_save, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                    break;
                    
                case MENU_ID_SNDREC_SAVE_OPTION_DISCARD:
                    SetLeftSoftkeyFunction(mmi_sndrec_save_option_discard_query, KEY_EVENT_UP);
                    SetKeyHandler(mmi_sndrec_save_option_discard_query, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                    break; 

                case MENU_ID_SNDREC_SAVE_OPTION_SAVE:
                    SetLeftSoftkeyFunction(mmi_sndrec_save_option_entry_rename, KEY_EVENT_UP);
                    SetKeyHandler(mmi_sndrec_save_option_entry_rename, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

                default:
                    break;
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            {
                if (menu_evt->parent_menu_id == MENU_ID_SNDREC_FORWARD_SEND)
                {
                    srv_fmgr_types_launch_option((WCHAR*)file_path_name, menu_evt->highlighted_menu_id);
                    mmi_frm_group_close(GRP_ID_SNDREC_AUDIO_SAVE_OPTION);
                }
                else
                {
                    mmi_sndrec_save_option_menu_select_hdlr(menu_evt);
                }
            }
            break;
            
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            {
                mmi_sndrec_save_option_cancel();
                cui_menu_close(menu_evt->sender_id);
            }
            break;

        default:
            break;    
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_save_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_entry_save_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MMI_ID grp_id;
    MMI_ID menu_gid;
    mmi_id cui_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sndrec_cntx.record.displayname[0] == 0 && g_sndrec_cntx.record.displayname[1] == 0)    
    {
        MMI_SNDREC_ERR_TRACE(0);
        return;
    }

    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    /* hide menu */
    MMI_SNDREC_MSG_TRACE(1);
    if ((mmi_sndrec_types_get_send_option_menu() <= 0) ||
        mmi_sndrec_sms_record_callback != NULL)
    {
        mmi_frm_hide_menu_item(MENU_ID_SNDREC_FORWARD_SEND);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_SNDREC_FORWARD_SEND);
    }
	
    if (mmi_sndrec_is_file_exist() == MMI_FALSE)
    {
        mmi_sndrec_preview_flag = MMI_FALSE;
        mmi_frm_group_close(GRP_ID_SNDREC_AUDIO_SAVE_OPTION);
        return;
    }
    
    mmi_frm_group_create_ex( GRP_ID_SNDREC_MAIN, GRP_ID_SNDREC_AUDIO_SAVE_OPTION, mmi_sndrec_save_option_proc,(void*)NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    menu_gid = cui_menu_create_and_run(
            GRP_ID_SNDREC_AUDIO_SAVE_OPTION,
            CUI_MENU_SRC_TYPE_RESOURCE,
            CUI_MENU_TYPE_APPSUB,
            MENU_ID_SNDREC_SAVE_OPTION,
            MMI_TRUE,
            NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_save_option_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_save_option_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    mmi_sndrec_entry_save_query();
    mmi_frm_group_close(GRP_ID_SNDREC_AUDIO_SAVE_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_save_option_discard_query_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_sndrec_save_option_discard_query_cb(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
            case MMI_ALERT_CNFM_YES:
                mmi_sndrec_save_option_discard_confirm();
                break;
                
            case MMI_ALERT_CNFM_NO:
                mmi_frm_scrn_close_active_id();
                break;
                
            default:
                break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_save_option_discard_query
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_save_option_discard_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = GRP_ID_SNDREC_AUDIO_SAVE_OPTION;
    arg.f_enter_history = MMI_TRUE;
    arg.f_auto_map_empty_softkey = MMI_TRUE;
    arg.callback = (mmi_proc_func) mmi_sndrec_save_option_discard_query_cb;
    mmi_confirm_display_ext(STR_ID_SNDREC_DISCARD_ASK, MMI_EVENT_QUERY, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_save_option_discard_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_save_option_discard_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    U16 file_path_name[MMI_SNDREC_FULL_NAME_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sndrec_get_full_file_name(file_path_name,g_sndrec_cntx.record.displayname);
    result = FS_Delete(file_path_name);

    if (result < 0)
    {
        mmi_popup_display_simple_ext(
            srv_fmgr_fs_error_get_string(result),
            MMI_EVENT_FAILURE,
            GRP_ID_SNDREC_MAIN,
            NULL);

    }
    else
    {
        mmi_popup_display_simple_ext(
            STR_GLOBAL_DONE,
            MMI_EVENT_SUCCESS,
            GRP_ID_SNDREC_MAIN,
            NULL);

    }
    mmi_frm_group_close(GRP_ID_SNDREC_AUDIO_SAVE_OPTION);

    mmi_sndrec_cb_for_other_app(MMI_FALSE);
   /* if (mmi_sndrec_sms_record_callback != NULL)
    {
        mmi_sndrec_sms_record_callback(FALSE, g_sndrec_cntx.record.fullname);
        mmi_sndrec_sms_record_callback = NULL;
    }*/

    if (g_sndrec_cntx.record.isEntryFromOther)
    {
        mmi_sndrec_delete_self();
    }
    else
    {
        mmi_sndrec_init_time();
        mmi_sndrec_clear_file_name();
    }
#ifndef __MMI_SNDREC_SLIM__
    g_sndrec_cntx.record.isappend = MMI_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_save_option_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_save_option_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_sndrec_func_allow_incall())
    {
        return;
    }

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        mmi_popup_display_ext(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL, MMI_EVENT_WARNING, NULL);
    }
    else
    {
    #ifdef __MMI_SNDREC_SKIN__
        res = mmi_sndrec_send_preview_req(g_sndrec_cntx.record.displayname, mmi_sndrec_preview_end_cb);
        if (res)
        {
            mmi_frm_group_close(GRP_ID_SNDREC_AUDIO_SAVE_OPTION);
        }
        else
        {
            return;
        }
    #else /* __MMI_SNDREC_SKIN__ */ 
        //mmi_sndrec_entry_audio_player(g_sndrec_cntx.record.fullname);          // category223? 
    #endif /* __MMI_SNDREC_SKIN__ */ 
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_preview_end_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_preview_end_cb(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* MMI_BOOL res; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, "[SNDREC]preview call back, result: %d. state: %d", result, g_sndrec_cntx.record.state);
    if (!mmi_frm_test_menu_item_hide(MENU_ID_SNDREC_FORWARD_SEND))
    {
        mmi_sndrec_preview_flag = MMI_TRUE;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, "[SNDREC]before entry save option");
    }

    if (SCR_ID_SNDREC_MAIN == mmi_frm_scrn_get_active_id())
    {
        mmi_sndrec_entry_save_option();
    }
    if (MDI_AUDIO_END_OF_FILE != result)
    {
        mmi_sndrec_error_hdlr(result, MMI_FALSE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_save_option_rename_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt             [?]         
 *  index(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_sndrec_save_option_rename_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    cui_filename_editor_result_event_struct *response = (cui_filename_editor_result_event_struct*) evt;
    mmi_id editor_id = mmi_frm_group_get_active_id();
//    UI_character_type fullname[MMI_SNDREC_FULL_NAME_LEN];
    mmi_id str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_FILENAME_EDITOR_RESULT:
        {
            if ((response->result > 0) || (response->result == FS_FILE_EXISTS)) /* User completed */
            {
                mmi_sndrec_save_option_rename_save();
                cui_filename_editor_close(response->sender_id);
                mmi_frm_group_close(GRP_ID_SNDREC_AUDIO_SAVE_OPTION_RENAME);
            }
            else if (response->result < 0)  /* too deep */
            {
                str_id = srv_fmgr_fs_error_get_string(response->result);
                mmi_popup_display_simple_ext(str_id, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
            }
            else if (response->result == 0) /* user cancel */
            {
                cui_filename_editor_close(response->sender_id);
                mmi_frm_group_close(GRP_ID_SNDREC_AUDIO_SAVE_OPTION_RENAME);
            }

            break;
        }
        case EVT_ID_GROUP_DEINIT:
        {
            mmi_frm_group_close(GRP_ID_SNDREC_AUDIO_SAVE_OPTION_RENAME);
        }
    }

    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_save_option_entry_rename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_save_option_entry_rename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    mmi_id grp_id;
    mmi_id editor_id;
    MMI_BOOL is_back = mmi_frm_is_in_backward_scenario();
    U16 filepath[MMI_SNDREC_PATH_LEN];
    WCHAR editorBuffer[MMI_SNDREC_FILE_LEN + 1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grp_id = mmi_frm_group_get_active_id();
    mmi_frm_group_create_ex(GRP_ID_SNDREC_AUDIO_SAVE_OPTION, GRP_ID_SNDREC_AUDIO_SAVE_OPTION_RENAME, mmi_sndrec_save_option_rename_proc,(void*)NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    if (is_back == MMI_FALSE)
    {
        mmi_wcscpy(editorBuffer, g_sndrec_cntx.record.displayname);
        mmi_sndrec_remove_file_ext(editorBuffer);
    }

    mmi_sndrec_get_file_path((U16*) filepath);
    editor_id = cui_filename_editor_create(
                    GRP_ID_SNDREC_AUDIO_SAVE_OPTION_RENAME,
                    (WCHAR*) editorBuffer,
                    sizeof(editorBuffer),
                    SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN,
                    filepath,
                    extBuffer);
    cui_filename_editor_set_title(editor_id, STR_GLOBAL_FILENAME, GetRootTitleIcon(MENU_ID_SNDREC_MAIN));
    cui_filename_editor_run(editor_id);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_save_option_rename_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_popup_and_close_scr(MMI_ID title_id,mmi_event_notify_enum event_id)
{
     mmi_popup_display_ext(title_id, MMI_EVENT_FAILURE, NULL);
     mmi_frm_scrn_close(
            GRP_ID_SNDREC_AUDIO_SAVE_OPTION_RENAME_OPTION,
            SCR_ID_SNDREC_AUDIO_SAVE_OPTION_RENAME_OPTION);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_save_option_rename_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_save_option_rename_save()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret;
    U16 old_path[MMI_SNDREC_FULL_NAME_LEN + 1];
    WCHAR *ptr;
    WCHAR new_path[MMI_SNDREC_FULL_NAME_LEN + 1];
    WCHAR *new_filename = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(0 == cui_filename_editor_get_fullpath(cui_id, new_path, MMI_SNDREC_FULL_NAME_LEN))
    {
        //mmi_sndrec_get_file_name_without_ext(editorBuffer);
        ptr = srv_fmgr_path_skip_leading_space((WCHAR*) ((CHAR *) g_sndrec_cntx.record.displayname));

    if (ptr != (CHAR *) g_sndrec_cntx.record.displayname)
    {
        mmi_sndrec_popup_and_close_scr(STR_GLOBAL_INVALID_FILENAME, NULL);
        return;
    }

    	mmi_sndrec_get_full_file_name(old_path, g_sndrec_cntx.record.displayname);
    	fs_ret = FS_Rename((PU16) old_path, (PU16) new_path);

    if (fs_ret == FS_NO_ERROR)
    {
            new_filename = mmi_wcsrchr(new_path,L'\\');
            mmi_wcscpy(g_sndrec_cntx.record.displayname, new_filename + 1);
    }
    else
    {
        mmi_sndrec_popup_and_close_scr(srv_fmgr_fs_error_get_string(fs_ret),srv_fmgr_fs_error_get_popup_type(fs_ret));
        return;
    }
	}
    
    mmi_sndrec_entry_save();
    mmi_frm_group_close(GRP_ID_SNDREC_AUDIO_SAVE_OPTION);
    mmi_frm_scrn_close(GRP_ID_SNDREC_AUDIO_SAVE_OPTION_RENAME_OPTION, SCR_ID_SNDREC_AUDIO_SAVE_OPTION_RENAME_OPTION);
}
#endif /* __MMI_OP12_SNDREC_STYLE__ */ 

#define __SNDREC_UI_SETTING__

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_setting_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_setting_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sndrec_setting_struct *setting = &g_sndrec_cntx.setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_SNDREC_SLIM_SETTINGS__

    setting->quality = srv_soundrec_get_quality();
    setting->drive = srv_soundrec_get_storage();

#if defined(__FS_CARD_SUPPORT__)
    if (!srv_fmgr_drv_is_valid((U8) (setting->drive)))
#endif 
    {
        setting->drive = SRV_FMGR_PUBLIC_DRV;
    }

#else

    /* When settings are not supported take default quality and storage */
    setting->quality = SRV_SOUNDREC_QUALITY_NORMAL;
    setting->drive = SRV_FMGR_CARD_DRV;
#endif
}

#ifndef __MMI_SNDREC_SLIM_SETTINGS__

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_pre_entry_setting_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_pre_entry_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 storage_highlight;
    SRV_FMGR_DRVLIST_HANDLE drv_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_list = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
    storage_highlight = srv_fmgr_drivelist_get_index_by_drv_letter(drv_list, g_sndrec_cntx.setting.drive);
    srv_fmgr_drivelist_destroy(drv_list);

    g_sndrec_cntx.setting.drive_index = storage_highlight;
    g_sndrec_cntx.setting.quality_temp = g_sndrec_cntx.setting.quality;

    mmi_sndrec_entry_setting_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_pre_save_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_pre_save_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 driveletter;
    SRV_FMGR_DRVLIST_HANDLE drv_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_list = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
    driveletter = srv_fmgr_drivelist_get_drv_letter(drv_list, (U8) g_sndrec_cntx.setting.drive_index);
    srv_fmgr_drivelist_destroy(drv_list);

    if (FS_GetDevStatus(driveletter, FS_MOUNT_STATE_ENUM) < FS_NO_ERROR)
    {
        mmi_popup_display_ext(STR_GLOBAL_INSERT_MEMORY_CARD, 
                                (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(FS_MEDIA_CHANGED), 
                                NULL);
    }
    else
    {
        if (mmi_sndrec_is_settings_changed())
        {
            mmi_sndrec_save_setting();

        }
        mmi_frm_group_close(GRP_ID_SNDREC_SETTING);
    }
}

typedef enum
{
    MMI_SNDREC_INLINE_DUMMY = CUI_INLINE_ITEM_ID_BASE + 1,
#if defined(__FS_CARD_SUPPORT__)
    MMI_SNDREC_INLINE_STORAGE_CAPTION,
    MMI_SNDREC_INLINE_STORAGE_TYPE,
#endif /* defined(__FS_CARD_SUPPORT__) */ 
    MMI_SNDREC_INLINE_AUDIO_QUALITY_CAPTION,
    MMI_SNDREC_INLINE_AUDIO_QUALITY_TYPE,
    MMI_SNDREC_INLINE_TOTAL_ITEMS
} mmi_sndrec_inline_enum;

static const cui_inline_item_caption_struct g_mmi_sndrec_settings_inline_caption_data[] = 
{
    {STR_GLOBAL_STORAGE},
    {STR_ID_SNDREC_SETTING_QUALITY},
};

static const cui_inline_item_select_struct g_mmi_sndrec_setting_inline_select_quality = 
{
    sizeof(g_sndrec_quality_id) / sizeof(U16), 0, g_sndrec_quality_id
};

static const cui_inline_set_item_struct g_mmi_sndrec_inline_item[] = 
{
#if defined(__FS_CARD_SUPPORT__)
    {MMI_SNDREC_INLINE_STORAGE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1,
     &g_mmi_sndrec_settings_inline_caption_data[0]},
    {MMI_SNDREC_INLINE_STORAGE_TYPE, CUI_INLINE_ITEM_TYPE_SELECT, 0, NULL},
#endif /* defined(__FS_CARD_SUPPORT__) */ 
    {MMI_SNDREC_INLINE_AUDIO_QUALITY_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2,
     &g_mmi_sndrec_settings_inline_caption_data[1]},
    {MMI_SNDREC_INLINE_AUDIO_QUALITY_TYPE, CUI_INLINE_ITEM_TYPE_SELECT, 0, &g_mmi_sndrec_setting_inline_select_quality}

};

static const cui_inline_struct g_mmi_sndrec_inline_data = 
{
    sizeof(g_mmi_sndrec_inline_item) / sizeof(cui_inline_set_item_struct),
    STR_GLOBAL_SETTINGS,
    0,
    CUI_INLINE_SCREEN_DEFAULT_TEXT,
    NULL, //&g_mmi_sndrec_inline_softkey,
    g_mmi_sndrec_inline_item
};


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_setting_screen_inline_cui_proc
 * DESCRIPTION
 *  Group event process function
 * PARAMETERS
 *  evt     [IN]        Group event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_sndrec_entry_setting_screen_inline_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
            mmi_frm_group_close(GRP_ID_SNDREC_SETTING);
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;

            cui_menu_close(menu_evt->sender_id);
        }
            break;

	case EVT_ID_CUI_INLINE_CSK_PRESS:
        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            if (mmi_frm_group_is_present(GRP_ID_SNDREC_SETTING))
            {
                mmi_sndrec_pre_save_setting();

            }
            break;
        }

        case EVT_ID_CUI_INLINE_NOTIFY:
        {
            cui_event_inline_notify_struct *inline_evt = (cui_event_inline_notify_struct*) evt;

            S32 item = inline_evt->item_id;

            if (inline_evt->event_type == CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED)
            {
                switch (item)
                {
                #if defined(__FS_CARD_SUPPORT__)
                    case MMI_SNDREC_INLINE_STORAGE_TYPE:
                    {
                        g_sndrec_cntx.setting.drive_index = inline_evt->param;
                    }
                        break;
                #endif /* defined(__FS_CARD_SUPPORT__) */ 
                    case MMI_SNDREC_INLINE_AUDIO_QUALITY_TYPE:
                    {
                        g_sndrec_cntx.setting.quality_temp = inline_evt->param;
                    }
                        break;

                    default:
                        break;
                }
            }
        }
            break;

        case EVT_ID_CUI_INLINE_ABORT:
            mmi_frm_group_close(GRP_ID_SNDREC_SETTING);
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_setting_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_entry_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#if defined(__FS_CARD_SUPPORT__)
    U8 total_drv_num;
    SRV_FMGR_DRVLIST_HANDLE drv_list;
    S32 i;
    U8 drv;
    U8 *storage_str_p[SRV_FMGR_DRV_TOTAL];
#endif /* defined(__FS_CARD_SUPPORT__) */ 
    MMI_ID inline_cui_id = GRP_ID_INVALID;
    U16 icon_list[(sizeof(g_mmi_sndrec_inline_item) / sizeof(cui_inline_set_item_struct))];
    S32 nitem_max = (sizeof(g_mmi_sndrec_inline_item) / sizeof(cui_inline_set_item_struct));
    S32 item_idx = 0, image_i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(
    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
        GRP_ID_SNDREC_MAIN_PRE_LIST,
    #else
        GRP_ID_SNDREC_MAIN,
    #endif
        GRP_ID_SNDREC_SETTING,
        mmi_sndrec_entry_setting_screen_inline_cui_proc,NULL,MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    inline_cui_id = cui_inline_create(GRP_ID_SNDREC_SETTING, &g_mmi_sndrec_inline_data);

    if (inline_cui_id == GRP_ID_INVALID)
    {
        mmi_frm_group_close(GRP_ID_SNDREC_SETTING);
        return;
    }
#if defined(__FS_CARD_SUPPORT__)
    drv_list = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
    total_drv_num = (U8) srv_fmgr_drivelist_count(drv_list);
    for (i = 0; i < total_drv_num; i++)
    {
        drv = srv_fmgr_drivelist_get_drv_letter(drv_list, i);
        storage_str_p[i] = (U8*) get_string(srv_fmgr_drv_get_string(drv));
    }
    srv_fmgr_drivelist_get_drv_letter(drv_list, g_sndrec_cntx.setting.drive_index);
    srv_fmgr_drivelist_destroy(drv_list);
    if(total_drv_num > 1)
    {
        cui_inline_set_item_select(
            inline_cui_id,
            MMI_SNDREC_INLINE_STORAGE_TYPE,
            total_drv_num,
            (U8 **) storage_str_p,
            g_sndrec_cntx.setting.drive_index);
    }
    else
    {
        cui_inline_delete_item(inline_cui_id, MMI_SNDREC_INLINE_STORAGE_CAPTION);
        cui_inline_delete_item(inline_cui_id, MMI_SNDREC_INLINE_STORAGE_TYPE);
    }
#endif /* defined(__FS_CARD_SUPPORT__) */ 

    cui_inline_set_value(
        inline_cui_id,
        MMI_SNDREC_INLINE_AUDIO_QUALITY_TYPE,
        (void*)g_sndrec_cntx.setting.quality_temp);

    cui_inline_set_title_icon(inline_cui_id, GetRootTitleIcon(MENU_ID_SNDREC_MAIN));
    for (item_idx = 0, image_i; item_idx < nitem_max;)
    {
        icon_list[item_idx++] = IMG_GLOBAL_L1 + image_i++;
        icon_list[item_idx++] = 0;

    }
    cui_inline_set_icon_list(inline_cui_id, &icon_list[0]);
    cui_inline_run(inline_cui_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_is_settings_changed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_sndrec_is_settings_changed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 driveletter;
    SRV_FMGR_DRVLIST_HANDLE drv_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_list = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
    driveletter = srv_fmgr_drivelist_get_drv_letter(drv_list, (U8) g_sndrec_cntx.setting.drive_index);
    srv_fmgr_drivelist_destroy(drv_list);

    if (driveletter != g_sndrec_cntx.setting.drive)
    {
        /* if driver change, clear last file name and record time */
        mmi_sndrec_clear_file_name();
        mmi_sndrec_init_time();
        return MMI_TRUE;
    }

    if ((g_sndrec_cntx.setting.quality_temp) != g_sndrec_cntx.setting.quality)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_save_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_save_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 driveletter;
    SRV_FMGR_DRVLIST_HANDLE drv_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_list = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
    driveletter = srv_fmgr_drivelist_get_drv_letter(drv_list, (U8) g_sndrec_cntx.setting.drive_index);
    srv_fmgr_drivelist_destroy(drv_list);

    g_sndrec_cntx.setting.drive = driveletter;
    g_sndrec_cntx.setting.quality = g_sndrec_cntx.setting.quality_temp;

    srv_soundrec_set_quality((srv_soundrec_quality_enum)g_sndrec_cntx.setting.quality);
    srv_soundrec_set_storage(g_sndrec_cntx.setting.drive);     
    mmi_popup_display_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, NULL);
}
#endif    // __MMI_SNDREC_SLIM_SETTINGS__

#define __SNDREC_UI_RENAME__
#ifndef __MMI_SNDREC_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_edit_name_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt             [?]         
 *  index(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_sndrec_entry_edit_name_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    cui_filename_editor_result_event_struct *response = (cui_filename_editor_result_event_struct*) evt;
    mmi_id editor_id = mmi_frm_group_get_active_id();
    mmi_id str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_FILENAME_EDITOR_RESULT:
        {
            if ((response->result > 0) || (response->result == FS_FILE_EXISTS)) /* User completed */
            {
                mmi_sndrec_entry_rename_save(response->sender_id);
            }
            else if (response->result < 0)  /* too deep */
            {
                str_id = srv_fmgr_fs_error_get_string(response->result);
                mmi_popup_display_simple_ext(str_id, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
            }
            else if (response->result == 0) /* user cancel */
            {
                cui_filename_editor_close(response->sender_id);
                mmi_frm_group_close(GRP_ID_SNDREC_RENAME);
            }

            break;
        }
        case EVT_ID_GROUP_DEINIT:
        {
            mmi_frm_group_close(GRP_ID_SNDREC_RENAME);
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_edit_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_entry_edit_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id editor_id;
    U16 filepath[MMI_SNDREC_PATH_LEN];
    WCHAR editorBuffer[MMI_SNDREC_FILE_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_is_in_backward_scenario() == MMI_FALSE)
    {
        mmi_wcscpy(editorBuffer, g_sndrec_cntx.record.displayname);
        mmi_sndrec_remove_file_ext(editorBuffer);
    }
    mmi_frm_group_create_ex(GRP_ID_SNDREC_MAIN, GRP_ID_SNDREC_RENAME, mmi_sndrec_entry_edit_name_proc, (void*)NULL,MMI_FRM_NODE_SMART_CLOSE_FLAG);
        
    mmi_sndrec_get_file_path((U16*) filepath);
    editor_id = cui_filename_editor_create(
                    GRP_ID_SNDREC_RENAME,
                    (WCHAR*) editorBuffer,
                    sizeof(editorBuffer),
                    SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN,
                    filepath,
                    extBuffer);
    cui_filename_editor_set_title(editor_id, STR_GLOBAL_FILENAME, GetRootTitleIcon(MENU_ID_SNDREC_MAIN));
    cui_filename_editor_run(editor_id);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_rename_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_entry_rename_save(MMI_ID cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret = FS_ERROR;
    UI_character_type old_path[MMI_SNDREC_FULL_NAME_LEN];
    U16 new_path[MMI_SNDREC_FULL_NAME_LEN];
    WCHAR * new_filename;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(0 == cui_filename_editor_get_fullpath(cui_id, new_path, SRV_FMGR_PATH_BUFFER_SIZE))
    {
		mmi_sndrec_get_full_file_name(old_path, g_sndrec_cntx.record.displayname);
		fs_ret = FS_Rename((PU16) old_path, (PU16) new_path);
    }

    if (fs_ret == FS_NO_ERROR)
    {
        /* success , notify apps */
        new_filename = mmi_wcsrchr(new_path,L'\\');
        
        mmi_wcscpy(g_sndrec_cntx.record.displayname,new_filename + 1);
        mmi_frm_group_close(GRP_ID_SNDREC_RENAME);
    }
    else
    {
        /* fail */
        mmi_popup_display_ext(
            srv_fmgr_fs_error_get_string(fs_ret),
            (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(fs_ret),
            NULL);
        
        return;
    }

}
#endif

#define __SNDREC_UI_DELETE__
#ifndef __MMI_SNDREC_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_delete_cnf_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_sndrec_entry_delete_cnf_cb(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
            case MMI_ALERT_CNFM_YES:
                mmi_sndrec_entry_delete_animation();
                break;
            case MMI_ALERT_CNFM_NO:
                mmi_frm_scrn_close_active_id();
                break;

            default:
                break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_delete_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_entry_delete_cnf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR str[MMI_SNDREC_FULL_NAME_LEN + (ENCODING_LENGTH * 100)];
    WCHAR display_str[MAX_SUBMENU_CHARACTERS+1];
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //memset(str, 0, sizeof(str));

    kal_wsprintf(str,"%w ",get_string(STR_GLOBAL_DELETE));
    mmi_wcsncat(str, g_sndrec_cntx.record.displayname, MMI_SNDREC_FULL_NAME_LEN);

    /* If more than MAX_SUBMENU_CHARACTERS add ... */
    if (mmi_wcslen(str) >= MAX_SUBMENU_CHARACTERS)
    {
        mmi_wcsncpy(display_str, str, MAX_SUBMENU_CHARACTERS - 4);
        mmi_wcscat(display_str, (WCHAR*)L"...");
    }
    else
    {
        mmi_wcsncpy(display_str, str, MAX_SUBMENU_CHARACTERS);
    }

    arg.parent_id = GRP_ID_SNDREC_MAIN;
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.f_auto_map_empty_softkey = MMI_TRUE;
    arg.callback = (mmi_proc_func) & mmi_sndrec_entry_delete_cnf_cb;
    /* To add the "?" string */
    arg.f_auto_question_mark = MMI_TRUE;
    mmi_confirm_display((WCHAR*) ((UI_string_type) display_str), MMI_EVENT_QUERY, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_delete_proc_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_sndrec_entry_delete_proc_func(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_fmgr_async_done_event_struct *adv_action = (srv_fmgr_async_done_event_struct*) param;
    MMI_BOOL is_incall = MMI_FALSE;
    mmi_id str_id = STR_GLOBAL_DELETED;
    S32 event_id = MMI_EVENT_SUCCESS;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 &&
        GetExitScrnID() != SCR_ID_SNDREC_DELETE_ANIMATION
#ifdef __DM_LAWMO_SUPPORT__
        || mmi_dmui_is_phone_lock()
#endif 
        )
    {
        is_incall = MMI_TRUE;
    }

    switch (param->evt_id)
    {
        case EVT_ID_SRV_FMGR_ASYNC_DONE:

            if (adv_action->result >= FS_NO_ERROR)
            {
                mmi_sndrec_clear_file_name();
                mmi_sndrec_init_time();
            }
   
            else
            {
                event_id = srv_fmgr_fs_error_get_popup_type(adv_action->result);
                str_id = srv_fmgr_fs_error_get_string(adv_action->result);

            }
            
            if (is_incall == MMI_FALSE && str_id != STR_GLOBAL_DELETED)
            {
                mmi_popup_display_ext(str_id, (mmi_event_notify_enum)event_id, NULL);
            }
            mmi_frm_group_close(GRP_ID_SNDREC_OPTION);
            break;
    }
	srv_backlight_turn_off();
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_delete_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_entry_delete_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 file_path_name[MMI_SNDREC_FULL_NAME_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_sndrec_is_file_exist())
    {
        mmi_popup_display_ext(FMGR_FS_PATH_NOT_FOUND_TEXT, MMI_EVENT_FAILURE, NULL);
        return;
    }
    
    mmi_sndrec_get_full_file_name(file_path_name, g_sndrec_cntx.record.displayname); 
    srv_fmgr_async_delete((WCHAR*)file_path_name, 0, mmi_sndrec_entry_delete_proc_func, NULL);
    ClearInputEventHandler(MMI_DEVICE_ALL);
    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
#ifndef __MMI_SNDREC_SKIN__    
    g_sndrec_cntx.record.rectime = 0;
    g_sndrec_cntx.record.lasttime = 0;
#else
    mmi_frm_scrn_enter(GRP_ID_SNDREC_OPTION , SCR_ID_SNDREC_DELETE_ANIMATION, NULL, NULL, MMI_FRM_SMALL_SCRN);

    /* MAUI_03162445 - instead of category66 screen, use category63 screen for avoiding flikering */

    /*
    ShowCategory66Screen(
        STR_GLOBAL_DELETE,
        GetRootTitleIcon(MENU_ID_SNDREC_MAIN),
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_GLOBAL_DELETING),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);
        */

    ShowCategory63Screen(
        (PU8) GetString(STR_GLOBAL_DELETING),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
#endif    
}
#endif

#define __SNDREC_AUTO_REC__
#if 0 //__VM_CODEC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __USB_IN_NORMAL_MODE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __USB_IN_NORMAL_MODE__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __VM_CODEC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
 #endif
/* under construction !*/
/* under construction !*/
#endif /* __VM_CODEC_SUPPORT__ */

#define __SNDREC_APP_ENTRY__

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_save_option_discard_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_cb_for_other_app(MMI_BOOL is_true)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 fullname[MMI_SNDREC_FULL_NAME_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sndrec_get_full_file_name(fullname,g_sndrec_cntx.record.displayname);    

    if (mmi_sndrec_sms_record_callback != NULL)
    {
        if(is_true == MMI_TRUE)
        {
            mmi_sndrec_sms_record_callback(TRUE, fullname);
        }
        else
        {
            mmi_sndrec_sms_record_callback(FALSE, fullname);
        }
        mmi_sndrec_sms_record_callback = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_check_usb_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_sndrec_check_usb_mode(void)
{
#ifdef __USB_IN_NORMAL_MODE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check is in mass storage mode */
    if (srv_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
        return MMI_TRUE;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    return MMI_FALSE;
}


#if defined(__MMI_OP02_LEMEI__)
void mmi_sndrec_release_record_btn_other_app(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mdi_audio_rec_param_struct rec_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
        if (!g_sndrec_cntx.record.isButtonDown)
        {
            return;
        }
        g_sndrec_cntx.record.isButtonDown = MMI_FALSE;
    
        switch (g_sndrec_cntx.record.state)
        {
            case MMI_SNDREC_IDLE_STATE:
    #ifdef __CTM_SUPPORT__
                if (srv_callset_ctm_get_mode() == MMI_TRUE && g_sndrec_cntx.record.isIncall)
                {
                    mmi_popup_display_ext(STR_ID_SNDREC_NOT_ALLOWED_IN_CTM_CALL,MMI_EVENT_FAILURE,NULL);
                    return;
                }
    #endif /* __CTM_SUPPORT__ */ 

                mmi_sndrec_entry_record_from_other_app_ex();
    
                mmi_sndrec_redraw_record_btn(MMI_FALSE);
                mmi_sndrec_redraw_skins_animal_img(MMI_TRUE);
                mmi_sndrec_show_time_text(MMI_TRUE);
            #ifdef __MMI_FTE_SUPPORT__
                mmi_sndrec_redraw_stop_btn(MMI_FALSE);
                mmi_sndrec_redraw_rec_icon();
            #endif /* __MMI_FTE_SUPPORT__ */ 
                mmi_sndrec_redraw_file_name(g_sndrec_cntx.record.displayname);
                mmi_sndrec_redraw_main_rsk();

                mmi_sndrec_blt_screen();
				break; 
                
            case MMI_SNDREC_REC_STATE:
                g_sndrec_cntx.record.need_save = MMI_TRUE;
                mmi_sndrec_send_stop_req(MMI_TRUE);
                break;
        }
       
#ifndef __MMI_FTE_SUPPORT__
        mmi_sndrec_redraw_state_text();
#endif 
}
#endif

static void mmi_sndrec_entry_record_from_other_app_ex(void)
{	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  

    if (!mmi_sndrec_check_folder_valid())
    {
        /* Unload DCM for Sound Recorder as not enter app */
    #ifdef __MMI_AP_DCM_SNDREC__
        mmi_ap_send_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_SNDREC);
    #endif
        return;
    }

	g_sndrec_cntx.record.quality = g_sndrec_cntx.setting.quality;

    /* get file name */
    mmi_sndrec_get_new_file(MMI_SNDREC_FORMAT_NULL);

    mmi_sndrec_bgsound_suspend();
    g_sndrec_cntx.record.isEntryFromOther = MMI_TRUE;
    g_sndrec_cntx.record.isStopBySelf = MMI_FALSE;

    
    if (mmi_sndrec_send_record_limit_req(
            g_sndrec_cntx.record.displayname,
            (U8)MEDIA_FORMAT_NONE,  //g_sndrec_cntx.record.format,
            g_sndrec_cntx.record.quality,
            g_size_limit,
            g_time_limit,
            0))
    {
    #ifndef __MMI_SNDREC_SLIM__
        g_sndrec_cntx.record.isappend = MMI_FALSE;        
    #endif
     
        if(mmi_frm_scrn_is_present(GRP_ID_SNDREC_MAIN, SCR_ID_SNDREC_MAIN, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE)
        {
            mmi_sndrec_entry_main_screen();
        }        
    }
    else
    {
        mmi_sndrec_clear_file_name();
        g_sndrec_cntx.record.isEntryFromOther = MMI_FALSE;
        mmi_sndrec_sms_record_callback = NULL;
        mmi_sndrec_bgsound_resume();
        /* Unload DCM for Sound Recorder as not enter app. this is error hanlding as not able to record file */
    #ifdef __MMI_AP_DCM_SNDREC__
        mmi_ap_send_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_SNDREC);
    #endif
    }
}
    

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_mc_rules_cb
 * DESCRIPTION
 *  Check the drive's statue
 * PARAMETERS
 *  evt             [?]         
 *  drive(?)        [IN]        The drive's number
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_ret mmi_sndrec_entry_mc_rules_cb(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {

            case MMI_ALERT_CNFM_YES:
            {
                g_sndrec_cntx.setting.drive = SRV_FMGR_PUBLIC_DRV;
                srv_soundrec_set_storage(g_sndrec_cntx.setting.drive); 
                if(g_sndrec_mc_cb)
                {
                     g_sndrec_mc_cb();
                     g_sndrec_mc_cb = NULL;
                }
               
            }
                break;
            case MMI_ALERT_CNFM_NO:
                break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_app_check_drive_status
 * DESCRIPTION
 *  Check the drive's statue
 * PARAMETERS
 *  drive       [IN]        The drive's number
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sndrec_app_check_drive_status(CHAR drive)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_fmgr_drv_is_valid((U8) drive) ||
        (FS_GetDevStatus(drive, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR) ||
        (FS_GetDevStatus(drive, FS_FEATURE_STATE_ENUM) == FS_DEVICE_BUSY))
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_mc_rules
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  Void(?)     [IN]        The drive's number
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_sndrec_entry_mc_rules(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_SNDREC_SLIM_SETTINGS__
    mmi_confirm_property_struct arg;
    S32 drive_type = 0;
    S32 event_type = 0;
    U16 str_ID = 0;
    S32 total_drive_num = 1;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SNDREC_SLIM_SETTINGS__

    /* For slim settings only use memory card, If memory card is not accessible show error popup and return */
    if(srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV) == MMI_FALSE)
    {
        mmi_popup_display_ext(STR_GLOBAL_INSERT_MEMORY_CARD, 
                                (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(FS_MEDIA_CHANGED), 
                                NULL);
        return MMI_FALSE;
    }

    return MMI_FALSE;

#else

    /* Check Memory Card rules */
    if (mmi_sndrec_app_check_drive_status(g_sndrec_cntx.setting.drive) == MMI_TRUE)
    {
        return MMI_FALSE;
    }

    if(srv_fmgr_drv_is_accessible((U8)SRV_FMGR_PUBLIC_DRV) == MMI_FALSE)
    {
        mmi_popup_display_ext(STR_GLOBAL_INSERT_MEMORY_CARD, 
                                (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(FS_MEDIA_CHANGED), 
                                NULL);
        return MMI_FALSE;
    }

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = GRP_ID_SNDREC_MAIN;
    arg.callback = (mmi_proc_func)mmi_sndrec_entry_mc_rules_cb;
    mmi_sndrec_check_drive_is_external_drive(g_sndrec_cntx.setting.drive, &drive_type);
    if (1 == total_drive_num)
    {

        if (FS_DEVICE_TYPE_EXTERNAL == drive_type)
        {
            str_ID = STR_GLOBAL_OTG_REMOVED_USE_PHONE_QUERY;
            event_type = MMI_EVENT_QUERY;
        }
        else
        {
            str_ID = STR_GLOBAL_MC_REMOVED_USE_PHONE;
            event_type = MMI_EVENT_QUERY;
        }

    }
    else
    {
        arg.callback = (mmi_proc_func)mmi_sndrec_entry_mc_rules_cb;
        if (FS_DEVICE_TYPE_EXTERNAL == drive_type)
        {
            str_ID = STR_GLOBAL_OTG_REMOVED;
            event_type = MMI_EVENT_INFO;
        }
        else
        {
            str_ID = STR_GLOBAL_MC_REMOVED;
            event_type = MMI_EVENT_INFO;
        }

    }
    if (str_ID)
    {
        mmi_confirm_display_ext(str_ID, (mmi_event_notify_enum)event_type, &arg);
    }

    return MMI_TRUE;

#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sdnrec_append_mdi_format_enum
 * DESCRIPTION
 *  return MDI record format refer to display name
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_FORMAT_ENUM
 *****************************************************************************/

MDI_FORMAT_ENUM  mmi_sdnrec_append_mdi_format_enum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_sndrec_check_file_type(g_sndrec_cntx.record.displayname, MMI_SNDREC_NAME_AMR))
	{
		return MDI_FORMAT_AMR;
	}
	else if(mmi_sndrec_check_file_type(g_sndrec_cntx.record.displayname, MMI_SNDREC_NAME_AWB))
	{
		return MDI_FORMAT_AMR_WB;
	}
	return MDI_FORMAT_NONE;
}

#ifdef __MMI_SNDREC_SKIN__
#ifdef __BT_SPK_VOL_CONTROL__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_hfp_volume_callback
 * DESCRIPTION
 *  This is the bt volume UP/Down key handler for sound recorder (Support 7 level with mute)
 * PARAMETERS
 *  volume      [IN]        Volume want to set to Sound Recorder by HFP
 *  is_mute     [IN]        not support mute [?]
 * RETURNS
 *  MMI_TRUE    Set volume OK
 *  MMI_FALSE   not handle the action
 *****************************************************************************/
MMI_BOOL mmi_sndrec_hfp_volume_callback(U8 volume, MMI_BOOL is_mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check the volume level received */
    if (volume < MAX_VOL_LEVEL)
    {
        if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
        {
            /* [?] Is it necessary to change speech volume from BT when in call As done from volume keys */
            /* Currently do nothing - check the levels */
            return MMI_TRUE;
        }
        else
        {
            /* change the media volume */
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_MEDIA_VOLUME, MDI_AUD_VOL_MUTE(g_sndrec_cntx.record.volume));
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_MUTE(volume));
            g_sndrec_cntx.record.volume = MDI_AUD_VOL_MUTE(volume);
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}
#endif
#endif

#ifdef __MMI_AP_DCM_SNDREC__
#pragma arm section rodata , code
#endif

#endif /* (defined(__MMI_SOUND_RECORDER__)) */ 

