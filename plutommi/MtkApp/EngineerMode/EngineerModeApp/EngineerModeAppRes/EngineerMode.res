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
 *  EngineerMode.res
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Engineer mode resource file.
 *
 * Author:
 * -------
 *  Ying Fang (mtk80514)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 07 2013 yupeng.zhou
 * [MAUI_03479170] [EM Request] add EM item for BQB Mode
 * .
 *
 * 01 16 2013 xiufeng.zhang
 * [MAUI_03305828] [Approved DVT] MT6260 MM Color Feature Check-in
 * .
 *
 * 01 10 2013 shengxi.xu
 * [MAUI_03307614] [MT6260 pre-SQC]the images are showing red x in alternate text
 * - Check in for cosmos, cosmos still use pbm format
 *
 * 12 28 2012 xiufeng.zhang
 * [MAUI_03296036] [PWM][DRV_TOOL][EM] Add Drv_tool PWM setting and  EM/BL/UEM/PWM  modification
 * .
 *
 * 12 25 2012 shengxi.xu
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * - Patch back to 11B
 *
 * 12 25 2012 yuan.yin
 * [MAUI_03299111] Pluto Cosmos SG EM FM Slim
 * .
 *
 * 12 04 2012 yuan.yin
 * [MAUI_03282750] FM Slim
 * .
 *
 * 12 02 2012 xiufeng.zhang
 * [MAUI_03280715] [EM][FM] Remove the unused strings
 * .
 *
 * 12 02 2012 xiufeng.zhang
 * [MAUI_03280715] [EM][FM] Remove the unused strings
 * .
 *
 * 11 29 2012 xiufeng.zhang
 * [MAUI_03278229] [EM][FM] patch 11BW1232OF_SLIM_DEV back to 11B branch
 * .
 * 
 * 07 31 2012 shooting.chuang
 * [MAUI_03221175] [GDI] Add GDI performance index & image decode test cases
 * .
 *
 * 05 10 2012 yiruei.wu
 * [MAUI_03183750] [GDI] Revise engineer mode GDI profiling
 * Check in profiling framework & test cases
 *
 * 05 10 2012 feng.yang
 * [MAUI_03183525] [SensorSrv]add filter noise and mutilstage step
 * .
 *
 * 04 26 2012 yixiong.zhao
 * [MAUI_03175560] Move trace to app resource
 * Reduce inline items to 16 for slim projects.
 *
 * 04 26 2012 kefeng.lian
 * [MAUI_03175912] [EM]Remove phase out item code for device->PWM and device-set hw level-LCD part
 * .
 *
 * 04 26 2012 kefeng.lian
 * [MAUI_03175912] [EM]Remove phase out item code for device->PWM and device-set hw level-LCD part
 * .
 *
 * 04 24 2012 jianhua.zhao
 * [MAUI_03026529] [EM][Device][Set UART]it cannot work when off UART1
 * .
 *
 * 04 20 2012 jianhua.zhao
 * [MAUI_03171622] [Timer id] USB srv
 * .
 *
 * 04 19 2012 yixiong.zhao
 * [MAUI_03166693] [EM Request] EM menu for invalid SIM recovery
 * .
 *
 * 04 18 2012 feng.yang
 * [MAUI_03170814] [EMFM]Move timer to module own res file
 * .
 *
 * 03 27 2012 youzhong.cheng
 * [MAUI_03157073] [Cosmos slim] FM radio
 * .
 *
 * 03 22 2012 mengmeng.cao
 * [MAUI_03151808] [WCDMA_prefer_SQC][MT6276]Engineering Mode WCDMA Prefer setting issue
 * .
 *
 * 03 14 2012 chuangjie.xia
 * [MAUI_03123066] [EM Request][Phase Out] Phase out [RF test] => [TX continuous][RX continuous] function
 * .
 *
 * 03 14 2012 feng.yang
 * [MAUI_03148691] [EM motion]Code enhance
 * .
 *
 * 03 08 2012 mengmeng.cao
 * [MAUI_03123989] [EM Request] SWLA for EM item
 * .
 *
 * 03 06 2012 mengmeng.cao
 * [MAUI_03075210] [EM Request] WCDMA Preferred - Add "WCDMA Preferred" into EM menu
 * .
 *
 * 03 06 2012 feng.yang
 * [MAUI_03138645] [Apollo55V2][Beijing][CMCC TD FT]Can not check the Value of  serving cell`s RSCP from the EM of MS & Catcher tool
 * .
 *
 * 03 04 2012 yuxiong.feng
 * [MAUI_03130549] Please turn on "Device Name" & "Master Switch" on EM->Misc->DM Self Register
 * .
 *
 * 02 22 2012 feng.yang
 * [MAUI_03135149] [Sensor service]mCube motion sensor porting support
 * .
 *
 * 02 21 2012 mengmeng.cao
 * [MAUI_03117769] [EM Request]CFU query setting in MMI EM mode
 * .
 *
 * 02 16 2012 shuo.xie
 * [MAUI_03131531] [EM Request][BT] To solve fail SIG spec issue during ICS in BT EM.
 * .
 *
 * 02 14 2012 feng.yang
 * [MAUI_03129795] [EHPLMN] check in code for invalid sim
 * .
 *
 * 02 09 2012 macross.chen
 * [MAUI_03102379] [AGPS] fix CP only build error
 * fix EM resource override.
 *
 * 02 08 2012 macross.chen
 * [MAUI_03102379] [AGPS] fix CP only build error
 * fix EM and GPS setting menu.
 *
 * 02 07 2012 mengmeng.cao
 * [MAUI_03117769] [EM Request]CFU query setting in MMI EM mode
 * .
 *
 * 01 11 2012 chuangjie.xia
 * [MAUI_03112327] [EM][RF test tool][GSM][1] Assert fail: PcmSink.c 726 0x0 0x0 0x0 - MED
 * .
 *
 * 12 22 2011 feng.yang
 * [MAUI_03103515] [EM GPRS]Check in Fast Dormancy
 * .
 *
 * 12 21 2011 macross.chen
 * [MAUI_03102371] [Streaming] RTSP Streaming Enhancement check in [MAUI/11B].
 * add prebuffer time EM.
 *
 * 12 20 2011 macross.chen
 * [MAUI_02899095] [EM Request] Video Streaming UserAgent Support
 * add UA and Transport selection.
 *
 * 12 09 2011 stella.yang
 * [MAUI_03081945] [V2] VP8 check-in
 * .
 *
 * 12 02 2011 ying.fang
 * [MAUI_03089587] [Known Issue][FM-EM]Radio threshold spell wrong
 * .
 *
 * 11 29 2011 shuo.xie
 * [MAUI_03077340] [EM Request] [BT] Can't choose "patten type". Need to add "patten type" field
 * .
 *
 * 11 25 2011 ying.fang
 * [MAUI_03084909] [FM radio][EM]check in FM radio new feature in EM
 * .
 *
 * 11 24 2011 xiangnan.qi
 * [MAUI_03086089] [EM Request] [TD-Gemini1.0][NFST]CTA Test Need GPRS Always Setting function
 * .
 *
 * 11 22 2011 jianhua.zhao
 * [MAUI_03078269] [Backlight] Cannot enter all number between 1 to 100 in duty
 * .
 *
 * 11 08 2011 jianhua.zhao
 * [MAUI_03070341] [Settings]The duty can be set as 0
 * .
 *
 * 11 07 2011 iris.chang
 * [MAUI_02983487] [EM Request] T-Mobile Fast Dormancy Requirement - IOT support
 * Revise menu tree
 *
 * 11 04 2011 jianhua.zhao
 * [MAUI_03072488] [HAL] Revise custom_em.c, custom_em.h
 * .
 *
 * 11 01 2011 ying.fang
 * [MAUI_03067425] [EM] EM->device->LCD phase out
 * .
 *
 * 10 19 2011 jianhua.zhao
 * [MAUI_03053384] [EM backlight setting enhancement]it save the modified level value after diredtly press home key
 * .
 *
 * 10 03 2011 cathytr.huang
 * [MAUI_03038722] [EM][Profiling]cann't enter recorder screen
 * .
 *
 * 09 30 2011 ying.fang
 * [MAUI_03038819] [EM][bluetooth] it  should go to RF test screen directly.
 * .
 *
 * 09 30 2011 ying.fang
 * [MAUI_03032112] [MT6256][Engineering Mode] BT Modify Tx Power Level Fail
 * .
 *
 * 09 29 2011 chuangjie.xia
 * [MAUI_03039542] [NFC][EM][FM]New UI design
 * .
 *
 * 09 28 2011 cathytr.huang
 * [MAUI_03036702] Camera engineer mode check-in
 * .
 *
 * 09 23 2011 yixiong.zhao
 * [MAUI_03035390] [EM][Iperf]Assert fail: vfx_app_launcher.cpp 1205 - MMI
 * .
 *
 * 09 23 2011 jianhua.zhao
 * [MAUI_03035428] [Settings]The popup text is wrong
 * .
 *
 * 09 21 2011 yixiong.zhao
 * [MAUI_03033113] (Blocking)[Single Antenna]Iperf cannot work when SIM slot has SIM card in it
 * .
 *
 * 09 16 2011 macross.chen
 * [MAUI_03029474] [In-house FTA][TP][AGPS-EM-Test][LUFFY76V22] Run TC_EM_DEVICE_GPS-059
 * add hint and error popup.
 *
 * 09 15 2011 macross.chen
 * [MAUI_03029020] [In-house FTA][TP][AGPS-EM-Test][LUFFY76V22] Run TC_EM_DEVICE_GPS-004
 * .
 *
 * 09 15 2011 jianhua.zhao
 * [MAUI_03026288] [Settings][1] Fatal Error (0x4, 0x0) - MMI
 * .
 *
 * 09 05 2011 ying.fang
 * [MAUI_02986827] [Auto_test][RTC][EM]Should give a popup after press 'ok'
 * .
 *
 * 09 05 2011 julie.cheng
 * [MAUI_03017482] COSMOS VT loopback mode
 * .
 *
 * 09 04 2011 zhenhai.zhao
 * [MAUI_03020102] remove __MTK_INTERNAL__ compile option
 * remove __MTK_INTERNAL compile option for release customer.
 *
 * 09 02 2011 jianhua.zhao
 * [MAUI_03019279] New Backlight support
 * .
 *
 * 09 01 2011 chuangjie.xia
 * [MAUI_03018206] [MAUI][TRUNK 11B][NFC]add NFC project
 * .
 *
 * 08 31 2011 chuangjie.xia
 * [MAUI_02864096] [EM Request] WiFi UI refinement for MT5931
 * .
 *
 * 08 30 2011 yixiong.zhao
 * [MAUI_03016518] [Data account UE enhancement] check in
 * .
 *
 * 08 24 2011 yunpeng.li
 * [MAUI_02997002] [ WIFI ] [ SUPC ]  add EAP AKA authentication method
 * Check in for adding EAP mode settings in the EM.
 *
 * 08 24 2011 stella.yang
 * [MAUI_02983645] [New feature] Add Video Setting: playback mode support
 * .
 *
 * 08 24 2011 macross.chen
 * [MAUI_03007923] [AGPS/UP][AT&T Concurrent] EM setting for SUPL UT timer
 * add SUPL UT Timer in EM.
 *
 * 08 19 2011 zhenhai.zhao
 * [MAUI_03008104] [SSP settings]reboot phone,SPP parameter value restore to default value
 * add SSP Setting Data screen to show the SSP coefficent value to user, and not allow apply the result in EngineerMode to Project.
 *
 * 08 16 2011 feng.yang
 * [MAUI_03006160] [EM 3G Info]Move 3G Info item to Network seting
 * .
 *
 * 08 09 2011 chuangjie.xia
 * [MAUI_03001030] [EM Request][Phase out] Request phase out LCD General Test
 * .
 *
 * 08 04 2011 xiuli.sui
 * [MAUI_02998137] [EngineerMode]Recorder Setting
 * .
 *
 * 08 03 2011 jia.luo
 * [MAUI_02979969] [FM Request] add mre version information in FM version item
 * .
 *
 * 08 02 2011 wei.fu
 * [MAUI_02995022] [EM Request] Venus Debug Panel
 * .
 *
 * 07 25 2011 ying.fang
 * [MAUI_02988784] [EM] FM EM mode RSSI info, read RSSI continuously without tuning channel continuosuly
 * .
 *
 * 07 15 2011 iris.chang
 * [MAUI_02984604] [FD][SCRI][T-Mobile] implement MTR-26019, MTR-6513, MTR-27883~27886
 * Check in T-Mobile Fast Dormancy requirements
 *
 * 07 15 2011 zhenhai.zhao
 * [MAUI_02984512] varify ssp setting
 * roll back to prev verson.
 *
 * 07 14 2011 zhenhai.zhao
 * [MAUI_02984512] varify ssp setting
 * update the varify for string res.
 *
 * 07 14 2011 zhenhai.zhao
 * [MAUI_02984512] varify ssp setting
 * varify ssp setting for string and menu style.
 *
 * 07 13 2011 stella.yang
 * [MAUI_02983645] [New feature] Add Video Setting: playback mode support
 * .
 *
 * 07 13 2011 cong.zhou
 * [MAUI_02961165] [EM Request] Add network service mode selection menu to EM
 * .
 *
 * 07 04 2011 ying.fang
 * [MAUI_02976315] [EM] remove the same string of engineermode resource
 * .
 *
 * 06 29 2011 zhenhai.zhao
 * [MAUI_02972926] add inline ssp code to MAUI/11B
 * varify string define for inline ssp.
 *
 * 06 28 2011 zhenhai.zhao
 * [MAUI_02972926] add inline ssp code to MAUI/11B
 * add __MTK_INTERNAL__ compile option for MAUI/11B.
 *
 * 06 27 2011 helena.li
 * [MAUI_02935348] [EM Request][GDI] Add GDI profiling: graphic profiling
 * .
 *
 * 06 23 2011 feng.yang
 * [MAUI_02970061] FM2.0_SLIM and move EM auto_test_setting into FM
 * .
 *
 * 06 23 2011 chuangjie.xia
 * [MAUI_02968382] [EM] Engineermode slim
 * .
 *
 * 06 23 2011 jianhua.zhao
 * [MAUI_02969680] [EM] No EM->Device->USB menu
 * .
 *
 * 06 21 2011 macross.chen
 * [MAUI_02961448] [MT6276_ADAPT][NVIOT][EricssonMTL][AGPS] G-SUPL-B-06 failed: the MS should reply to server in 10 secs if the user didn't response
 * add SUPL Notify Timer to EM.
 *
 * 06 17 2011 chuangjie.xia
 * [MAUI_02960539] [EM] slim inlcude code use compiler option(DM, debuginfo, rftest, storage)
 * .
 *
 * 06 16 2011 ying.fang
 * [MAUI_02964312] [EM] Use GPIO server API to replace the useless GPIO API
 * .
 *
 * 06 15 2011 tokiya.chang
 * [MAUI_02962350] [PLUTO] code refine
 * .
 *
 * 06 15 2011 ying.fang
 * [MAUI_02959952] [Daily build error] Fix the daily build error
 * .
 *
 * 06 10 2011 iris.chang
 * [MAUI_02956693] [Connection Management] Pluto CNMGR App/Srv Split
 * EM SCRI & Fast Dormancy IOT support
 *
 * 06 10 2011 chuangjie.xia
 * [MAUI_02960222] [EM] engineermode Slim: include code in compiler option in em gprs
 * .
 *
 * 06 08 2011 feng.yang
 * [MAUI_02957398] Check in EM TDD into MAUI and 11B
 * .
 *
 * 06 07 2011 vovo.yang
 * [MAUI_02832291] Cosmos Development
 * fix .res syntax errors
 *
 * 06 07 2011 vovo.yang
 * [MAUI_02832291] Cosmos Development
 * fix .res syntax errors
 *
 * 06 07 2011 ying.fang
 * [MAUI_02956402] [Need Patch][Build Error] MAUI.W11.24 build error for LUFFY76V22_512256_hspa(FTE_WQVGA_11B)
 * .
 *
 * 06 02 2011 chuangjie.xia
 * [MAUI_02955281] [EM] Engineermode Slim
 * .
 *
 * 06 01 2011 chuangjie.xia
 * [MAUI_02954282] [EM] slim
 * .
 *
 * 06 01 2011 ying.fang
 * [MAUI_02953881] [EM] Engineermode Slim
 * .
 *
 * 06 01 2011 ying.fang
 * [MAUI_02953881] [EM] Engineermode Slim
 * .
 *
 * 05 28 2011 ying.fang
 * [MAUI_02951477] [EM] PMU register settings support FW2.0
 * .
 *
 * 05 26 2011 jia.liu
 * [MAUI_02942854] CMCC TD Patch back Check in
 * .
 *
 * 05 25 2011 yixiong.zhao
 * [MAUI_02948626] [Need Patch][Build Error] MAUI.W11.22 build error for LUFFY76V22_DEMO_hspa(COSMOS_WVGA)
 * .
 *
 * 05 23 2011 ying.fang
 * [MAUI_02660419] [EM]It should not show red x
 * .
 *
 * 05 23 2011 ying.fang
 * [MAUI_02660419] [EM]It should not show red x
 * .
 *
 * 05 20 2011 yixiong.zhao
 * [MAUI_02945842] [Tethering] Check-in DOM
 * .
 *
 * 05 10 2011 helena.li
 * [MAUI_02935348] [GDI] Add GDI profiling: graphic profiling
 * .
 *
 * 05 10 2011 macross.chen
 * [MAUI_02929731] [MT6276_ADAPT][NVIOT][Nokia2G] CSAGPS_007 case failed
 * add AGPS QOP setting in MiniGPS.
 *
 * 05 03 2011 chuangjie.xia
 * [MAUI_02923474] WIFI EM
 * .
 *
 * 04 28 2011 chuangjie.xia
 * [MAUI_02661960] [EM] RF tool test WIFI Revise
 * .
 *
 * 04 28 2011 chuangjie.xia
 * [MAUI_02924783] EM(FM) add Touchpanel code
 * .
 *
 * 04 27 2011 yuxiong.feng
 * [MAUI_02661632] [fix build error] USB tethering id undefined
 * .
 *
 * 04 22 2011 ying.fang
 * [MAUI_02658696] [EngineerMode] Daily build error
 * .
 *
 * 04 15 2011 jianhua.zhao
 * [MAUI_02660351] [COSMOS] [USB] Add NMGR for balloon
 * .
 *
 * 04 15 2011 chuangjie.xia
 * [MAUI_02660372] [EngineerMode] modify "RF test tool" UI
 * .
 *
 * 04 14 2011 ying.fang
 * [MAUI_02660140] It should not show red x
 * .
 *
 * 04 13 2011 feng.yang
 * [MAUI_02659855] EM/FM PXS check in
 * .
 *
 * 04 13 2011 kefeng.lian
 * [MAUI_02864146] [EM Request][Phase out] Request phase out Misc?Power on duration
 * .
 *
 * 04 13 2011 feng.yang
 * [MAUI_02659855] EM/FM PXS check in
 * .
 *
 * 04 01 2011 ying.fang
 * [MAUI_02658696] [EngineerMode] Daily build error
 * .
 *
 * 03 29 2011 yixiong.zhao
 * [MAUI_02652736] [EM] iperf code revise
 * .
 *
 * 03 29 2011 kefeng.lian
 * [MAUI_02658083] [MMI]  Revise __GEMINI__ to MMI_MAX_SIM_NUM >= 2
 * .
 *
 * 03 22 2011 yuxiong.feng
 * [MAUI_02854220] [EM Request] USB RNDIS
 * .
 *
 * 03 22 2011 shuo.xie
 * [MAUI_02653262] [EM Request]BT HID BQB Test
 * Update and remove pluto only res&&fix the build error.
 *
 * 03 19 2011 ying.fang
 * [MAUI_02741168] [EM] it should not give error popup
 * .
 *
 * 03 18 2011 aidan.hung
 * [MAUI_02897477] [SLIM FMGR] Wrap compile option for renaming volume label
 * Wrap compile option for renaming volume label
 *
 * 03 17 2011 shuo.xie
 * [MAUI_02653262] [EM Request]BT HID BQB Test
 * Update && remove limited discover.
 *
 * 03 16 2011 feng.yang
 * [MAUI_02656543] [3G FDD MMI EM] 3G FDD MMMI EM of SIM2 should be removed
 * .
 *
 * 03 16 2011 feng.yang
 * [MAUI_02656503] Check in EM FDD 3G info to MAUI
 * .
 *
 * 03 15 2011 stella.yang
 * [MAUI_02649939] [CMCC_lab]¥¼¦b¤???¤¤,?¦³¥X?´£¿??* .
 *
 * 03 12 2011 aidan.hung
 * [MAUI_02656007] Press is 'ok' is unuseful
 * Press is 'ok' work well in engineermode->scan disk
 *
 * 03 11 2011 xuemei.liu
 * [MAUI_02655752] Press 'ok' is unuseful in BT list
 * .
 *
 * 03 11 2011 kefeng.lian
 * [MAUI_02655921] [EM]  code revise
 * .
 *
 * 03 10 2011 ying.fang
 * [MAUI_02740079] [EM] lsk is no use in this case
 * .
 *
 * 03 10 2011 shaoqing.ma
 * [MAUI_02654046] [EM Request]Touch screen->pen event test wrapped by __MTK_INTERNAL__ option
 * Rollback Touch screen->pen event test wrapped by __MTK_INTERNAL__ option.
 *
 * 03 09 2011 yuxiong.feng
 * [MAUI_02653700] [EM Request] Motify MMI show and add 3 menus for CTA test
 * .
 *
 * 03 06 2011 ying.fang
 * [MAUI_02738937] [EM] always shows mode switching
 * .
 *
 * 03 05 2011 shuo.xie
 * [MAUI_02653262] [EM Request]BT HID BQB Test
 * BT HID profile BQB Test.
 *
 * 03 04 2011 cathytr.huang
 * [MAUI_02888116] Phase out TVOUT
 * .
 *
 * 03 04 2011 ying.fang
 * [MAUI_02452205] [Known Issue] Sanity Test of TR TSSQA00008277 is Fail Unable to set UART
 * .
 *
 * 03 02 2011 ying.fang
 * [MAUI_02653618] [EM]It should can save when change
 * c.
 *
 * 03 01 2011 shaoqing.ma
 * [MAUI_02654046] [EM Request]Touch screen->pen event test wrapped by __MTK_INTERNAL__ option
 * .
 *
 * 03 01 2011 yixiong.zhao
 * [MAUI_02652736] [EM] iperf code revise
 * .
 *
 * 02 28 2011 ying.fang
 * [MAUI_02653625] [EM]Tap ok have no response,show popup a screen display the result
 * .
 *
 * 02 28 2011 ying.fang
 * [MAUI_02736780] [Ke][EM]Go to java performance ,have no use
 * .
 *
 * 02 24 2011 yuxiong.feng
 * [MAUI_02865854] [EM Request]LCD General Test
 * .
 *
 * 02 23 2011 wei.fu
 * [MAUI_02652751] [EM Request] Multi-point touch
 * .
 *
 * 02 23 2011 ying.fang
 * [MAUI_02652981] Press 'ok' is unuseful
 * .
 *
 * 02 22 2011 ying.fang
 * [MAUI_02650948] [1] Assert fail: EngineerModeUtil.c 729 - MMI
 * .
 *
 * 02 22 2011 jianhua.zhao
 * [MAUI_02652325] [EM] Remove chip option
 * .
 *
 * 02 22 2011 yixiong.zhao
 * [MAUI_02652736] [EM] iperf code revise
 * Remove iperf menu img.
 *
 * 02 21 2011 yiping.xie
 * [MAUI_02652512] [BCR] Engineer Mode BCR phase out code remove
 * .
 *
 * 02 20 2011 wei.fu
 * [MAUI_02641197] [EM Request] Gesture Behavior Tuning
 * .
 *
 * 02 18 2011 chuangjie.xia
 * [MAUI_01970980] [EM Request] Touch panel accuracy test and parameters setting
 * .
 *
 * 02 17 2011 vincent.cho
 * [MAUI_02871501] EM - revision - Media memory and video recorder
 * .
 *
 * 02 16 2011 yizheng.yang
 * [MAUI_02651937] em 2.0 build error fix
 * .
 *
 * 02 16 2011 tim.chang
 * [MAUI_02870964] [EM] remove non-used header file
 * .
 *
 * 02 16 2011 stella.yang
 * [MAUI_02864993] Pop up "Failed to play".
 * .
 *
 * 02 16 2011 ying.fang
 * [MAUI_02651692] [EMV2.0] Fix build errors which are invoked by removing v1 resource
 * .
 *
 * 02 16 2011 cathytr.huang
 * [MAUI_02377434] [EM][CAM] Revise code
 * .
 *
 * 02 16 2011 aidan.hung
 * [MAUI_02870921] Fix daily build derror
 * Update engineermode string about checking drive and display drive letter
 *
 * 02 16 2011 ying.fang
 * [MAUI_02651692] [EMV2.0] Fix build errors which are invoked by removing v1 resource
 * .
 *
 * 02 15 2011 ying.fang
 * [MAUI_02651692] [EMV2.0] Fix build errors which are invoked by removing v1 resource
 * .
 *
 * 02 15 2011 leona.chou
 * [MAUI_02834247] [Socket EM] phase out socket engineer mode except iperf
 * .
 *
 * 02 15 2011 cathytr.huang
 * [MAUI_02377434] [EM][CAM] Revise code
 * .
 *
 * 02 15 2011 cathytr.huang
 * [MAUI_02377434] [EM][CAM] Revise code
 * .
 *
 * 02 11 2011 tokiya.chang
 * [MAUI_02832686] Code patch
 * .
 *
 * 02 11 2011 tokiya.chang
 * [MAUI_02832686] Code patch
 * .
 *
 * 02 11 2011 kefeng.lian
 * [MAUI_02651125] [EM] remove __MMI_EM_V2_SUPPORT__
 * .
 *
 * 01 30 2011 ying.fang
 * [MAUI_02736727] [EM][1]Fatal Error(4,f8042ac4) - MMI
 * .
 *
 * 01 21 2011 shuo.xie
 * [MAUI_02644495] [EM] network settings support Gemini+
 * .
 *
 * 01 15 2011 yixiong.zhao
 * [MAUI_02645462] [Hotspot] Check in code (TCPIP, DHCPD, MMI)
 * Do some update
 *
 * 01 11 2011 yixiong.zhao
 * [MAUI_02860249] [Hotspot] iperf test STA-->AP, it shows test failed popup
 * .
 *
 * 01 11 2011 bingbing.ma
 * [MAUI_02647082] [gps]:check in hotstill debug item
 * .
 *
 * 01 06 2011 bingbing.ma
 * [MAUI_02647082] [gps]:check in hotstill debug item
 * .
 *
 * 12 25 2010 feng.yang
 * [MAUI_02645789] [Sensor] Fix build error for EM motion sensor
 * .
 *
 * 12 23 2010 yizheng.yang
 * [MAUI_02645461] engineer mode ?»»µ½EM2.0
 * .
 *
 * 12 21 2010 bingbing.ma
 * [MAUI_02644979] [gps]:check in Bee switch and TLS
 * .
 *
 * 12 19 2010 bingbing.ma
 * [MAUI_02644798] [gps]:engineermode gps 2.0 add head files
 * .
 *
 * 12 16 2010 wilson.lien
 * [MAUI_02847109] [EM Request][Phase out] Request phase out Audio->TTS Test
 * .
 *
 * 12 15 2010 shaoqing.ma
 * [MAUI_02644233] [EM Request][Phase Out]Misc->MMI Debug
 * .
 *
 * 12 15 2010 shaoqing.ma
 * [MAUI_02644180] [EM Request] Profiling->Memory monitor
 * .
 *
 * 12 15 2010 shaoqing.ma
 * [MAUI_02644169] [EM Request] Touch screen->pen event test
 * .
 *
 * 12 15 2010 yang.cui
 * [MAUI_02639813] [EM Request] SSP Settings App
 * .
 *
 * 12 14 2010 yang.cui
 * [MAUI_02640254] Check in RHR
 * .
 *
 * 12 09 2010 ying.fang
 * [MAUI_02643632] [Daily build] Fix build error
 * .
 *
 * 12 09 2010 ying.fang
 * [MAUI_02643632] [Daily build] Fix build error
 * .
 *
 * 12 08 2010 ying.fang
 * [MAUI_02643205] [Build error] Need patch for MAUIw1049OF
 * .
 *
 * 12 07 2010 stella.yang
 * [MAUI_02846526] EM 2.0 support
 * .
 *
 * 12 07 2010 ying.fang
 * [MAUI_02643188] [EM2.0]Delete code of old version and Split large item to simple file
 * .
 *
 * 12 07 2010 ying.fang
 * [MAUI_02643188] [EM2.0]Delete code of old version and Split large item to simple file
 * .
 *
 * 12 07 2010 yan.liang
 * [MAUI_02831491] New MMI Cache Mechanism (MBJ site)
 * Rollback //MAUI/TRUNK/MAUI/mcu/plutommi/MtkApp/EngineerMode/EngineerModeApp/EngineerModeAppRes/EngineerMode.res to revision 24
 *
 * 12 06 2010 tim.chang
 * [MAUI_02843755] [EM] Engineer mode 2.0 check in
 * .
 *
 * 12 03 2010 jianhua.zhao
 * [MAUI_02642540] Fix MAUIW1049 build error
 * .
 *
 * 12 03 2010 teng.fu
 * [MAUI_02642788] [EM2.0] engineer mode FW2.0 revise
 * 
 * .
 *
 * 12 03 2010 teng.fu
 * [MAUI_02642788] [EM2.0] engineer mode FW2.0 revise
 * .
 *
 * 12 02 2010 yan.liang
 * [MAUI_02831491] New MMI Cache Mechanism (MBJ site)
 * .
 *
 * 12 01 2010 jianhua.zhao
 * [MAUI_02642540] Fix MAUIW1049 build error
 * .
 *
 * 12 01 2010 yixiong.zhao
 * [MAUI_02642453] [EMv2] Iperf Check-in MAUI
 * .
 *
 * 11 30 2010 kefeng.lian
 * [MAUI_02642426] [EM] Add comments info to EM.res files to tracking the check in history
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 

 /***************************************************************************** 
  * Include 
  *****************************************************************************/
  
/*!---- 20 char --!------------------------------ total 81 char ---------------
<!----------------- Section Template ------------------------------------------>


<!----------------- Level1 Menu : Mainmenu ------------------------------------>

    <!----------------- Timer Id ------------------------------------------>             
    <TIMER id = "TIMER_ID_EM_XXX"/> 

    <!----------------- Event Id ------------------------------------------>             
    <EVENT id = "EVT_ID_EM_XXX"/>

    <!----------------- Screen Id ----------------------------------------->             
    <SCREEN id = "SCR_ID_EM_XXX"/>

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_XXX"/>
    
    <!----------------- Image Id ------------------------------------------>
    <IMAGE id = "IMG_ID_EM_XXX"> path </IMAGE>
    
    <!----------------- Audio Id ------------------------------------------>   
    <AUDIO id = "IMG_ID_EM_XXX"> path </AUDIO>

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_XXX">
        <MENUITEM id = "MENU_ID_EM_XXX"/>
    </MENU>

<!----------------- EM Item End ----------------------------------------------->



<!----------------- Device | LCD ---------------------------------------------->

    <!----------------- Timer Id ------------------------------------------>             

    <!----------------- Event Id ------------------------------------------>             

    <!----------------- Screen Id ----------------------------------------->             

    <!----------------- String Id ----------------------------------------->             

    <!----------------- Image Id ------------------------------------------>

    <!----------------- Audio Id ------------------------------------------>      

    <!----------------- Menu Id ------------------------------------------->             

<!----------------- EM Item End ----------------------------------------------->


<!----------------- Section Template End -------------------------------------->
 *!---- 20 char --!------------------------------ total 81 char --------------*/





#include "mmi_features.h"
#include "custresdef.h"
#include "drv_sw_features_color.h" // for __COLOR_HW_SUPPORTED__
#ifdef __MMI_ENGINEER_MODE__
<?xml version = "1.0" encoding="UTF-8"?>

<APP id = "APP_ENGINEERMODE1">

<!----------------- Include Area ---------------------------------------------->

    <INCLUDE file = "MMI_features.h"/>
    <INCLUDE file = "MMIDataType.h"/>
    <INCLUDE file = "GlobalResDef.h"/>
#ifdef __J2ME__
    <INCLUDE file = "mmi_rp_app_java_def.h"/>
#endif

<!----------------- Common Area ----------------------------------------------->

    <!----------------- Timer Id ------------------------------------------>             
    <TIMER id = "EM_NOTIFYDURATION_TIMER"/> 
    <TIMER id = "EM_RINGTONE_HIGHLIGHT_TIMER"/> 
    <TIMER id = "EM_GPRS_PING_TIMER"/> 
    <TIMER id = "EM_GPRS_SOC_DEMO_APP_TIMER"/> 
	
    <!----------------- Event Id ------------------------------------------>

    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_EM_GLOBAL_PROCESSING">Processing...</STRING>
    <STRING id = "STR_ID_EM_SIM_CARD_IS_NOT_AVAILABLE">This SIM card is not available</STRING>
    <STRING id = "STR_ID_EM_WARNING">Not allow or conflict!</STRING>   <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_SET_LSK">Set</STRING>
    <STRING id = "STR_ID_EM_NOTICE_SUCCESS_REBOO">Done.\nPower off in 3 sec</STRING>
    <STRING id = "STR_ID_EM_GLOBAL_AUTO">Auto</STRING>
    <STRING id = "STR_ID_EM_TRUE">True</STRING>
    <STRING id = "STR_ID_EM_FALSE">False</STRING>
    
#if (defined(__MMI_EM_DEV_BACKLIGHT__)||defined(__MMI_EM_60BACKLIGHT__))
    <STRING id = "STR_ID_EM_DEV_BACKLIGHT">Backlight level</STRING>
#endif
    
    <!----------------- Screen Id ----------------------------------------->             
    <SCREEN id = "GRP_ID_EM_ROOT"/>
    <SCREEN id = "SCR_ID_EM_CMN_SCRN"/>
    <SCREEN id = "SCR_ID_EM_DUALMODE_SWITCH_PROGRESS"/>
    
<!----------------- Menu Id ------------------------------------------->             
    <MENUSET id = "MENUSET_ON_OFF">
        <MENUITEM id = "MENU_ID_EM_MISC_ON" str = "STR_GLOBAL_ON"/>
        <MENUITEM id = "MENU_ID_EM_MISC_OFF" str = "STR_GLOBAL_OFF"/>        
    </MENUSET>

    <MENUSET id = "MENUSET_TRUE_FALSE">
        <MENUITEM id = "MENU_ID_EM_TRUE" str = "STR_ID_EM_TRUE"/>
        <MENUITEM id = "MENU_ID_EM_FALSE" str = "STR_ID_EM_FALSE"/>        
    </MENUSET>

<!----------------- Level1 Menu : Mainmenu ------------------------------------>

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_APP_NAME">Engineering mode</STRING>

    <!----------------- Image Id ------------------------------------------>
    <IMAGE id = "IMG_ID_EM_MAIN_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_EM.png"</IMAGE>

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_MAIN_MENU" type = "APP_MAIN" str = "STR_ID_EM_APP_NAME">
    
    #ifdef __MMI_EM_NETWORK_SETTINGS__
        <MENUITEM_ID>MENU_ID_EM_NW_SETTING</MENUITEM_ID>
    #endif
    
        <MENUITEM_ID>MENU_ID_EM_DEVICE</MENUITEM_ID>
   #if defined(__MMI_EM_AUDIO__) || defined(__MMI_EM_AUDIO_DEBUG_INFO__) || defined(__MMI_EM_AUDIO_AUTO_VM__)          
        <MENUITEM_ID>MENU_ID_EM_AUDIO</MENUITEM_ID>
   #endif
   #if defined(__MMI_EM_GPRS_AUTO_ATTACH__) || defined(__MMI_EM_GPRS_PDP__) || defined(__MMI_EM_GPRS_CNMGR_SCRI_SUPPORT__)
        <MENUITEM_ID>MENU_ID_EM_GPRS_ACT</MENUITEM_ID>
   #endif     
        <MENUITEM_ID>MENU_ID_EM_MISC</MENUITEM_ID>

#if defined(__MMI_EM_LAST_EXCEPTION__) || defined(__MMI_EM_DEBUG_INFO_SYS_STATS__) || defined(__MMI_EM_DEBUG_INFO_DRIVE_LETTER__)        
        <MENUITEM_ID>MENU_ID_EM_DEBUG_INFO</MENUITEM_ID>
#endif        
        
    #ifdef __MMI_EM_IPERF__
        <MENUITEM_ID>MENU_ID_EM_IPERF</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_EM_BT_GENERAL_TEST__
        <MENUITEM_ID>MENU_ID_EM_BLUETOOTH</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_EM_PROFILING__
        <MENUITEM_ID>MENU_ID_EM_PROFILING</MENUITEM_ID>
    #endif
    
    #if defined(__MMI_EM_RF_GSM__) || defined(__MMI_EM_RF_WIFI__)
        <MENUITEM_ID>MENU_ID_EM_RF_TEST_TOOL</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_EM_VOIP__    
        <MENUITEM_ID>MENU_ID_EM_VOIP</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_CTM_CTA_TDD__
        <MENUITEM_ID>MENU_ID_EM_CONFORMANCE_TEST</MENUITEM_ID>
    #endif
    
   </MENU>

<!----------------- EM Item End ----------------------------------------------->


<!----------------- Level2 Menu | Network Setting ----------------------------->
#ifdef __MMI_EM_NETWORK_SETTINGS__
    
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_NW_SETTING">Network setting</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_NW_SETTING" type = "APP_SUB" str = "STR_ID_EM_NW_SETTING">
    
    #ifdef __MMI_EM_NW_NETWORK_INFO__
        <MENUITEM_ID>MENU_ID_EM_NW_NETWORK_INFO</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_EM_NW_BAND_SEL__
        <MENUITEM_ID>MENU_ID_EM_NW_BAND_SELECTION</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_EM_NW_PREFER_RAT__
        <MENUITEM_ID>MENU_ID_EM_NW_PREFER_RAT</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_EM_NW_CELL_LOCK__
        <MENUITEM_ID>MENU_ID_EM_NW_CELL_LOCK</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_EM_NW_EVENT_NOTIFY__
        <MENUITEM_ID>MENU_ID_EM_NW_NETWORK_EVENT</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_EM_NW_PLMN_LIST__
        <MENUITEM_ID>MENU_ID_EM_NW_PLMN_LIST_PREFERENCE</MENUITEM_ID>
    #endif
    #ifdef __MMI_EM_NW_SERVICE_MODE_SELECTION__
        <MENUITEM_ID>MENU_ID_EM_NW_SERVICE_SELECTION</MENUITEM_ID>
    #endif    
    #if defined(__MMI_EM_NW_GPRS_CONN__)
        <MENUITEM_ID>MENU_ID_EM_NW_GPRS_CONN</MENUITEM_ID>
    #endif 
    #ifdef __MMI_EM_NW_FDD_NETWORK_INFO__
    /* 3G_Info test FDD */  
        <MENUITEM_ID>MENU_ID_EM_3G_INFO</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_EM_NW_TDD_NETWORK_INFO__
    /*3G_Info test TDD*/
        <MENUITEM_ID>MENU_ID_EM_TDD</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_EM_NW_WCDMA_PREFERRED__
    /* WCDMA PREFERRED */
        <MENUITEM_ID>MENU_ID_EM_NW_WCDMA_PREFERRED</MENUITEM_ID>
    #endif

    #ifdef __GSMCDMA_DUALSIM__
        <MENUITEM_ID>MENU_ID_EM_IVSR</MENUITEM_ID>
    #endif /* __GSMCDMA_DUALSIM__ */

    </MENU>
    
#endif /* __MMI_EM_NETWORK_SETTINGS__ */
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Network Setting | Network Info ---------------------------->
#ifdef __MMI_EM_NW_NETWORK_INFO__
    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id = "SCR_ID_EM_NW_INFO_LOG"/>
    
    <!----------------- String Id ----------------------------------------->             

    <STRING id = "STR_ID_EM_NW_NETWORK_INFO">Network info</STRING>
    <STRING id = "STR_ID_EM_NW_INFO_RR_CELL_SEL">RR_CELL_SEL</STRING>
    <STRING id = "STR_ID_EM_NW_INFO_RR_CH_DSCR">RR Ch Dscr</STRING>
    <STRING id = "STR_ID_EM_NW_INFO_RR_CTRL_CHAN">RR ctrl chan</STRING>
    <STRING id = "STR_ID_EM_NW_INFO_RR_RACH_CTRL">RR rach ctrl</STRING>
    <STRING id = "STR_ID_EM_NW_INFO_RR_LAI_INFO">RR lai info</STRING>
    <STRING id = "STR_ID_EM_NW_INFO_RR_RADIO_LINK">RR radio link</STRING>
    <STRING id = "STR_ID_EM_NW_INFO_RR_MEAS_REP">RR meas rep</STRING>
    <STRING id = "STR_ID_EM_NW_INFO_CC_CHAN_INFO">CC chan info</STRING>
    <STRING id = "STR_ID_EM_NW_INFO_CC_CALL_INFO">CC call info</STRING>
    <STRING id = "STR_ID_EM_NW_INFO_CA_LIST_INFO">CA list info</STRING>
    <STRING id = "STR_ID_EM_NW_INFO_PLMN_INFO">PLMN info</STRING>
    <STRING id = "STR_ID_EM_NW_INFO_GPRS_INFO">GPRS info</STRING>
    <STRING id = "STR_ID_EM_NW_INFO_SI2Q_MI_INFO">Si2Q/Mi info</STRING>
    <STRING id = "STR_ID_EM_NW_INFO_TBF_STATUS">TBF status</STRING>
    <STRING id = "STR_ID_EM_NW_INFO_BLOCK_INFO">Block info</STRING>
    
    <!----------------- Menu Id --------external----------------------------------->        
    <MENU id = "MENU_ID_EM_NW_NETWORK_INFO" str = "STR_ID_EM_NW_NETWORK_INFO">
         <MENUITEM id = "MENU_ID_EM_NW_SETTING_SIM_1" str = "STR_GLOBAL_SIM_1"/>
    #if (MMI_MAX_SIM_NUM >= 2)
         <MENUITEM id = "MENU_ID_EM_NW_SETTING_SIM_2" str = "STR_GLOBAL_SIM_2"/>
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
         <MENUITEM id = "MENU_ID_EM_NW_SETTING_SIM_3" str = "STR_GLOBAL_SIM_3"/>
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
         <MENUITEM id = "MENU_ID_EM_NW_SETTING_SIM_4" str = "STR_GLOBAL_SIM_4"/>
    #endif
    </MENU>

    <MENU id = "MENU_ID_EM_NW_NETWORK_INFO_LIST" type = "APP_SUB" str = "STR_ID_EM_NW_NETWORK_INFO" flag = "CHECKBOX">
        <MENUITEM id = "MENU_ID_EM_NW_INFO_RR_CELL_SEL" str = "STR_ID_EM_NW_INFO_RR_CELL_SEL"/>
        <MENUITEM id = "MENU_ID_EM_NW_INFO_RR_CH_DSCR" str = "STR_ID_EM_NW_INFO_RR_CH_DSCR"/>
        <MENUITEM id = "MENU_ID_EM_NW_INFO_RR_CTRL_CHAN" str = "STR_ID_EM_NW_INFO_RR_CTRL_CHAN"/>
        <MENUITEM id = "MENU_ID_EM_NW_INFO_RR_RACH_CTRL" str = "STR_ID_EM_NW_INFO_RR_RACH_CTRL"/>
        <MENUITEM id = "MENU_ID_EM_NW_INFO_RR_LAI_INFO" str = "STR_ID_EM_NW_INFO_RR_LAI_INFO"/>
        <MENUITEM id = "MENU_ID_EM_NW_INFO_RR_RADIO_LINK" str = "STR_ID_EM_NW_INFO_RR_RADIO_LINK"/>
        <MENUITEM id = "MENU_ID_EM_NW_INFO_RR_MEAS_REP" str = "STR_ID_EM_NW_INFO_RR_MEAS_REP"/>
        <MENUITEM id = "MENU_ID_EM_NW_INFO_CC_CHAN_INFO" str = "STR_ID_EM_NW_INFO_CC_CHAN_INFO"/>
        <MENUITEM id = "MENU_ID_EM_NW_INFO_CC_CALL_INFO" str = "STR_ID_EM_NW_INFO_CC_CALL_INFO"/>
        <MENUITEM id = "MENU_ID_EM_NW_INFO_CA_LIST_INFO" str = "STR_ID_EM_NW_INFO_CA_LIST_INFO"/>
        <MENUITEM id = "MENU_ID_EM_NW_INFO_PLMN_INFO" str = "STR_ID_EM_NW_INFO_PLMN_INFO"/>
        <MENUITEM id = "MENU_ID_EM_NW_INFO_GPRS_INFO" str = "STR_ID_EM_NW_INFO_GPRS_INFO"/>
        <MENUITEM id = "MENU_ID_EM_NW_INFO_SI2Q_MI_INFO" str = "STR_ID_EM_NW_INFO_SI2Q_MI_INFO"/>
        <MENUITEM id = "MENU_ID_EM_NW_INFO_TBF_STATUS" str = "STR_ID_EM_NW_INFO_TBF_STATUS"/>
        <MENUITEM id = "MENU_ID_EM_NW_INFO_BLOCK_INFO" str = "STR_ID_EM_NW_INFO_BLOCK_INFO"/>
   </MENU>
#endif /* __MMI_EM_NW_NETWORK_INFO__ */

<!----------------- EM Item End ----------------------------------------------->



<!----------------- Network Setting | Band Selection--------------------------->
#ifdef __MMI_EM_NW_BAND_SEL__
    <!----------------- Screen Id -----------------------------------------> 

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_NW_BAND_SELECTION">Band selection</STRING>
    //<STRING id = "STR_ID_EM_NW_BAND_SEL_AUTO">Auto</STRING>
    <STRING id = "STR_ID_EM_BAND_SEL_ALL_3G_OFF">Not allow all 3G band off</STRING>
    <STRING id = "STR_ID_EM_NW_BAND_SEL_2G">2G band setting</STRING>
#ifdef __GSM850__
    <STRING id = "STR_ID_EM_NW_BAND_SEL_GSM850">850 band</STRING>
#endif
#ifdef __EGSM900__
    <STRING id = "STR_ID_EM_NW_BAND_SEL_EGSM900">900 band</STRING>
#endif
#ifdef __DCS1800__
    <STRING id = "STR_ID_EM_NW_BAND_SEL_DCS1800">1800 band</STRING>
#endif
#ifdef __PCS1900__
    <STRING id = "STR_ID_EM_NW_BAND_SEL_PCS1900">1900 band</STRING>
#endif
#if defined(__GSM850__) && defined(__DCS1800__)
    <STRING id = "STR_ID_EM_NW_BAND_SEL_850_1800">850/1800</STRING>
#endif
#if defined(__EGSM900__) && defined(__DCS1800__)
    <STRING id = "STR_ID_EM_NW_BAND_SEL_900_1800">900/1800</STRING>
#endif

#if defined(__GSM850__) && defined(__PCS1900__)
    <STRING id = "STR_ID_EM_NW_BAND_SEL_850_1900">850/1900</STRING>
#endif

#ifdef __UMTS_RAT__
    <STRING id = "STR_ID_EM_NW_BAND_SEL_3G">3G band setting</STRING>
    <STRING id = "STR_ID_EM_NW_BAND_SEL_UMTS_BAND_I">UMTS band I</STRING>
    <STRING id = "STR_ID_EM_NW_BAND_SEL_UMTS_BAND_II">UMTS band II</STRING>
    <STRING id = "STR_ID_EM_NW_BAND_SEL_UMTS_BAND_III">UMTS band III</STRING>
    <STRING id = "STR_ID_EM_NW_BAND_SEL_UMTS_BAND_IV">UMTS band IV</STRING>
    <STRING id = "STR_ID_EM_NW_BAND_SEL_UMTS_BAND_V">UMTS band V</STRING>
    <STRING id = "STR_ID_EM_NW_BAND_SEL_UMTS_BAND_VI">UMTS band VI</STRING>
    <STRING id = "STR_ID_EM_NW_BAND_SEL_UMTS_BAND_VII">UMTS band VII</STRING>
    <STRING id = "STR_ID_EM_NW_BAND_SEL_UMTS_BAND_VIII">UMTS band VIII</STRING>
    <STRING id = "STR_ID_EM_NW_BAND_SEL_UMTS_BAND_IX">UMTS band IX</STRING>
    <STRING id = "STR_ID_EM_NW_BAND_SEL_UMTS_BAND_X">UMTS band X</STRING>
#endif /* __UMTS_RAT__ */

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_NW_BAND_SELECTION" type = "APP_SUB" str = "STR_ID_EM_NW_BAND_SELECTION">
        <MENU id = "MENU_ID_EM_NW_BD_SL_SIM_1" str = "STR_GLOBAL_SIM_1">
        </MENU>
    #if (MMI_MAX_SIM_NUM >= 2)
        <MENU id = "MENU_ID_EM_NW_BD_SL_SIM_2" str = "STR_GLOBAL_SIM_2">
        </MENU>
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        <MENU id = "MENU_ID_EM_NW_BD_SL_SIM_3" str = "STR_GLOBAL_SIM_3">
        </MENU>
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        <MENU id = "MENU_ID_EM_NW_BD_SL_SIM_4" str = "STR_GLOBAL_SIM_4">
        </MENU>
    #endif
    </MENU>
#endif /* __MMI_EM_NW_BAND_SEL__ */
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Network Setting | Prefer Rat ------------------------------>
#ifdef __MMI_EM_NW_PREFER_RAT__

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_NW_PREFER_RAT">Prefer Rat</STRING>
    <STRING id = "STR_ID_EM_NW_PREFER_RAT_2G">2G</STRING>
    <STRING id = "STR_ID_EM_NW_PREFER_RAT_3G">3G</STRING>

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_NW_PREFER_RAT" type = "APP_SUB" str = "STR_ID_EM_NW_PREFER_RAT" flag = "RADIO">
    <MENUITEM id = "MENU_ID_EM_NW_PREFER_RAT_NOE" str = "STR_GLOBAL_NONE"/>
    <MENUITEM id = "MENU_ID_EM_NW_PREFER_RAT_2G" str = "STR_ID_EM_NW_PREFER_RAT_2G"/>
    <MENUITEM id = "MENU_ID_EM_NW_PREFER_RAT_3G" str = "STR_ID_EM_NW_PREFER_RAT_3G"/>
    </MENU>       

#endif /* __MMI_EM_NW_PREFER_RAT__ */    
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Network Setting | Cell Lock ------------------------------->
#ifdef __MMI_EM_NW_CELL_LOCK__

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_NW_CELL_LOCK">Cell lock</STRING>
    <STRING id = "STR_ID_EM_NW_CELL_LOCK_BAND_1900">1900 Band</STRING>
    <STRING id = "STR_ID_EM_NW_CELL_LOCK_ARFCN">Arfcn</STRING>

    <!----------------- Menu Id ------------------------------------------->             
    <MENUITEM id = "MENU_ID_EM_NW_CELL_LOCK" str = "STR_ID_EM_NW_CELL_LOCK"/>

#endif /* __MMI_EM_NW_CELL_LOCK__ */    
<!----------------- EM Item End ----------------------------------------------->

<!----------------- Network Setting | Network WCDMA PREFERRED --------------------------->
#ifdef __MMI_EM_NW_WCDMA_PREFERRED__
    <!----------------- Screen Id ----------------------------------------->             
    <SCREEN id = "SCR_ID_EM_NW_WCDMA_PRO"/>
    
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_NW_WCDMA_PREFERRED">WCDMA Preferred</STRING>
    <!----------------- Menu Id ------------------------------------------->

    <MENU id = "MENU_ID_EM_NW_WCDMA_PREFERRED" type = "APP_SUB" str = "STR_ID_EM_NW_WCDMA_PREFERRED" flag = "RADIO">
        <MENUITEM id = "MENU_ID_EM_WCDMA_PREFERRED_ON" str = "STR_GLOBAL_ON"/>
        <MENUITEM id = "MENU_ID_EM_WCDMA_PREFERRED_OFF" str = "STR_GLOBAL_OFF"/>  
    </MENU>

#endif /* __MMI_EM_NW_WCDMA_PREFERRED__ */
<!----------------- EM Item End ------------------------------------------->

<!----------------- Network Setting | IVSR -------------------------------->
#ifdef __GSMCDMA_DUALSIM__
    <!----------------- Screen Id ----------------------------------------->             
    <SCREEN id = "SCR_ID_EM_IVSR"/>

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_IVSR_ON">IVSR</STRING>

    <!----------------- Menu Id ------------------------------------------->

    <MENU id = "MENU_ID_EM_IVSR" type = "APP_SUB" str = "STR_ID_EM_IVSR_ON" flag = "RADIO">
        <MENUITEM id = "MENU_ID_EM_IVSR_ON" str = "STR_GLOBAL_ON"/>
        <MENUITEM id = "MENU_ID_EM_IVSR_OFF" str = "STR_GLOBAL_OFF"/>
    </MENU>

    <CACHEDATA type="byte" id="NVRAM_EM_IVSR" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> invalid sim recovery </DESCRIPTION>
    </CACHEDATA>

#endif /* __GSMCDMA_DUALSIM__ */

<!----------------- EM Item End ----------------------------------------------->


<!----------------- Network Setting | Network Event --------------------------->
#ifdef __MMI_EM_NW_EVENT_NOTIFY__

    <!----------------- Screen Id ----------------------------------------->             
    <SCREEN id = "SCR_ID_EM_NETWORK_NETWORK_EVENT_UPDATE"/>
    <SCREEN id = "SCR_ID_EM_NETWORK_NETWORK_EVENT_FILTER_SETTING"/>
    <SCREEN id = "SCR_ID_EM_NETWORK_NETWORK_EVENT_GROUP"/>

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_NW_NETWORK_EVENT">Network events</STRING>
    <STRING id = "STR_ID_EM_NW_NWEVT_FILTER">Filter</STRING>
    <STRING id = "STR_ID_EM_NW_NWEVT_GROUP">Event group</STRING>
    <STRING id = "STR_ID_EM_NW_NWEVT_SELET_RING">Select ring</STRING>
    <STRING id = "STR_ID_EM_NET_NETWORK_EVENT_SETTING">Setting</STRING>
        
    <!----------------- Menu Id ------------------------------------------->

    <MENU id = "MENU_ID_EM_NW_NETWORK_EVENT" type = "APP_SUB" str = "STR_ID_EM_NW_NETWORK_EVENT"> 
        <MENUITEM_ID>MENU_ID_EM_NW_NWEVT_START</MENUITEM_ID>
        <MENUITEM id = "MENU_ID_EM_NW_NWEVT_FILTER" str = "STR_ID_EM_NW_NWEVT_FILTER"/>
        <MENUITEM id = "MENU_ID_EM_NW_NWEVT_SETTING" str = "STR_GLOBAL_SETTINGS"/>
    </MENU>

    <MENU id = "MENU_ID_EM_NW_NWEVT_START" type = "APP_SUB" str = "STR_GLOBAL_START" flag = "RADIO">
        <MENUSET_ID>MENUSET_ON_OFF</MENUSET_ID>
    </MENU>

	<!----------------- Timer Id ------------------------------------------->
	<TIMER id = "EM_NW_EVENT_PLAY_TONE_TIMER"/>


#endif /* __MMI_EM_NW_EVENT_NOTIFY__ */    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Network Setting | PLMN List ------------------------------->
#ifdef __MMI_EM_NW_PLMN_LIST__

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_NW_PLMN_LIST_PREFERENCE">PLMN list preference</STRING>
    <STRING id = "STR_ID_EM_NW_PLMN_LIST_SPPEED_PREFERRED">Speed prefered</STRING>
    <STRING id = "STR_ID_EM_NW_PLMN_LIST_ACCURACY_PREFERRED">Accuracy prefered</STRING>
    
    <!----------------- Menu Id ------------------------------------------->
    <MENU id = "MENU_ID_EM_NW_PLMN_LIST_PREFERENCE" type = "APP_SUB" str = "STR_ID_EM_NW_PLMN_LIST_PREFERENCE" flag = "RADIO">
        <MENUITEM id = "MENU_ID_EM_NW_PLMN_LIST_SPPEED_PREFERRED" str = "STR_ID_EM_NW_PLMN_LIST_SPPEED_PREFERRED"/>
        <MENUITEM id = "MENU_ID_EM_NW_PLMN_LIST_ACCURACY_PREFERRED" str = "STR_ID_EM_NW_PLMN_LIST_ACCURACY_PREFERRED"/>
    </MENU>

#endif /* __MMI_EM_NW_PLMN_LIST__ */    
<!----------------- EM Item End ----------------------------------------------->

<!----------------- Network Setting | Service selection ------------------------------->
#ifdef __MMI_EM_NW_SERVICE_MODE_SELECTION__
    <!----------------- String Id ----------------------------------------->   
    <STRING id = "STR_ID_EM_NW_SERVICE_SELECTION">Service selection</STRING>

<!----------------- Menu Id -------------------------------------------> 
    <MENUITEM id="MENU_ID_EM_NW_SERVICE_SELECTION" str="STR_ID_EM_NW_SERVICE_SELECTION"/>
#endif /* __MMI_EM_NW_SERVICE_MODE_SELECTION__ */


<!----------------- EM Item End ----------------------------------------------->

<!----------------- Network Setting | Gprs Connection ------------------------------->
#if defined(__MMI_EM_NW_GPRS_CONN__)
<!----------------- String Id ----------------------------------------->   
    <STRING id = "STR_ID_EM_NW_GPRS_CONN">GPRS connection</STRING>
<!----------------- Menu Id -------------------------------------------> 
    <MENUITEM id="MENU_ID_EM_NW_GPRS_CONN" str="STR_ID_EM_NW_GPRS_CONN"/>
#endif /* defined(__MMI_EM_NW_GPRS_CONN__) */

<!----------------- EM Item End ----------------------------------------------->


<!----------------- Network Setting | 3G_info --------------------------------->

#ifdef __MMI_EM_NW_FDD_NETWORK_INFO__

    <!----------------- screen Id ----------------------------------------->

    <SCREEN id = "SCR_ID_EM_3G_INFO"/>

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_3G_INFO">3G Info</STRING>

    <STRING id = "STR_ID_EM_3G_INFO_SELECT_PLMN">Selected PLMN</STRING>
    <STRING id = "STR_ID_EM_3G_INFO_ACCESS_CLASS">Access Class</STRING>
    <STRING id = "STR_ID_EM_3G_INFO_SRNC_ID">Srnc ID</STRING>
    <STRING id = "STR_ID_EM_3G_INFO_SRV_CELL_PLMN">Serving Cell PLMN</STRING>

    <STRING id = "STR_ID_EM_3G_INFO_H_SRV_CELL">H-Serving Cell</STRING>
    <STRING id = "STR_ID_EM_3G_INFO_PDP_DATA_SPEED">PDP Data Speed</STRING>
    <STRING id = "STR_ID_EM_3G_INFO_PS_SRV_INFO">PS Service Information</STRING>
    <STRING id = "STR_ID_EM_3G_INFO_BLK_ERR_RATE">Block Error Rate</STRING>
    <STRING id = "STR_ID_EM_3G_INFO_UE_TRANS_POWER">UE Transmission Power</STRING>

    <STRING id = "STR_ID_EM_3G_INFO_SRV_CELL">Serving Cell</STRING>
    <STRING id = "STR_ID_EM_3G_INFO_ACTIVE_CELL">Active Cell</STRING>
    <STRING id = "STR_ID_EM_3G_INFO_INTRA_MONITORED_CELL">Intra_freq Monitored Cell</STRING>
    <STRING id = "STR_ID_EM_3G_INFO_INTER_MONITORED_CELL">Inter_freq Monitored Cell</STRING>
    <STRING id = "STR_ID_EM_3G_INFO_DETECTED_CELL">Detected Cell</STRING>

    <STRING id = "STR_ID_EM_TDD">TDD</STRING>

    <STRING id = "STR_ID_EM_3G_INFO_UMTS_CELL">UMTS Cell</STRING>
    <STRING id = "STR_ID_EM_3G_INFO_GSM_CELL">GSM Cell</STRING>
    <STRING id = "STR_ID_EM_3G_INFO_NEXT">Next</STRING>


<!----------------- menu Id ----------------------------------------------->

    <MENU id = "MENU_ID_EM_3G_INFO" type = "APP_SUB" str = "STR_ID_EM_3G_INFO" >
        <MENUITEM_ID>MENU_ID_EM_SIM1</MENUITEM_ID>
    </MENU>


    <MENUITEM id ="MENU_ID_EM_SIM1" str ="STR_GLOBAL_SIM_1"/>


    <MENU id = "MENU_ID_EM_3G_INFO_NEW_ROOT" type = "APP_SUB" str = "STR_ID_EM_3G_INFO" flag="CHECKBOX">

        <MENUITEM_ID>MENU_ID_EM_3G_INFO_SELECT_PLMN</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_3G_INFO_ACCESS_CLASS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_3G_INFO_SRNC_ID</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_3G_INFO_SRV_CELL_PLMN</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_3G_INFO_SRV_CELL</MENUITEM_ID> 
        <MENUITEM_ID>MENU_ID_EM_3G_INFO_ACTIVE_CELL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_3G_INFO_INTRA_MONITORED_CELL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_3G_INFO_INTER_MONITORED_CELL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_3G_INFO_DETECTED_CELL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_3G_INFO_H_SRV_CELL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_3G_INFO_PDP_DATA_SPEED</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_3G_INFO_PS_SRV_INFO</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_3G_INFO_BLK_ERR_RATE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_3G_INFO_UE_TRANS_POWER</MENUITEM_ID>
    </MENU>


    <MENUITEM id ="MENU_ID_EM_3G_INFO_SELECT_PLMN" str ="STR_ID_EM_3G_INFO_SELECT_PLMN"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_ACCESS_CLASS" str ="STR_ID_EM_3G_INFO_ACCESS_CLASS"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_SRNC_ID" str = "STR_ID_EM_3G_INFO_SRNC_ID"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_SRV_CELL_PLMN" str = "STR_ID_EM_3G_INFO_SRV_CELL_PLMN"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_SRV_CELL" str = "STR_ID_EM_3G_INFO_SRV_CELL"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_ACTIVE_CELL" str = "STR_ID_EM_3G_INFO_ACTIVE_CELL"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_INTRA_MONITORED_CELL" str = "STR_ID_EM_3G_INFO_INTRA_MONITORED_CELL"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_INTER_MONITORED_CELL" str = "STR_ID_EM_3G_INFO_INTER_MONITORED_CELL"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_DETECTED_CELL" str = "STR_ID_EM_3G_INFO_DETECTED_CELL"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_H_SRV_CELL" str = "STR_ID_EM_3G_INFO_H_SRV_CELL"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_PDP_DATA_SPEED" str = "STR_ID_EM_3G_INFO_PDP_DATA_SPEED"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_PS_SRV_INFO" str = "STR_ID_EM_3G_INFO_PS_SRV_INFO"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_BLK_ERR_RATE" str = "STR_ID_EM_3G_INFO_BLK_ERR_RATE"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_UE_TRANS_POWER" str = "STR_ID_EM_3G_INFO_UE_TRANS_POWER"/>

#endif /* __MMI_EM_NW_FDD_NETWORK_INFO__*/


<!----------------- EM Item End ----------------------------------------------->



<!----------------- Network Setting | TDD --------------------------------->
#ifdef __MMI_EM_NW_TDD_NETWORK_INFO__

 		<SCREEN id = "SCR_ID_EM_TDD"/>

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_3G_INFO">3G Info</STRING>
    
    <STRING id = "STR_ID_EM_3G_INFO_SELECT_PLMN">Selected PLMN</STRING>
    <STRING id = "STR_ID_EM_3G_INFO_ACCESS_CLASS">Access Class</STRING>
    <STRING id = "STR_ID_EM_3G_INFO_SRNC_ID">SRNC ID</STRING>
    <STRING id = "STR_ID_EM_3G_INFO_SRV_CELL_PLMN">Serving Cell PLMN</STRING>

    <STRING id = "STR_ID_EM_3G_INFO_H_SRV_CELL">H-Serving Cell</STRING>
    <STRING id = "STR_ID_EM_3G_INFO_PDP_DATA_SPEED">PDP Data Speed</STRING>
    <STRING id = "STR_ID_EM_3G_INFO_PS_SRV_INFO">PS Service Information</STRING>
    <STRING id = "STR_ID_EM_3G_INFO_BLK_ERR_RATE">Block Error Rate</STRING>
    <STRING id = "STR_ID_EM_3G_INFO_UE_TRANS_POWER">UE Transmission Power</STRING>

    <STRING id = "STR_ID_EM_3G_INFO_SRV_CELL">Serving Cell</STRING>
    <STRING id = "STR_ID_EM_3G_INFO_ACTIVE_CELL">Active Cell</STRING>
    <STRING id = "STR_ID_EM_3G_INFO_INTRA_MONITORED_CELL">Intra_freq Monitored Cell</STRING>
    <STRING id = "STR_ID_EM_3G_INFO_INTER_MONITORED_CELL">Inter_freq Monitored Cell</STRING>
    <STRING id = "STR_ID_EM_3G_INFO_DETECTED_CELL">Detected Cell</STRING>

    <STRING id = "STR_ID_EM_SIM1">SIM-1</STRING>
    <STRING id = "STR_ID_EM_SIM2">SIM-2</STRING>

    <STRING id = "STR_ID_EM_TDD">TDD</STRING>

    
     <STRING id = "STR_ID_EM_3G_INFO_UMTS_CELL">UMTS Cell</STRING>
     <STRING id = "STR_ID_EM_3G_INFO_GSM_CELL">GSM Cell</STRING>

     <STRING id = "STR_ID_EM_3G_INFO_NEXT">Next</STRING>   

<!----------------- Menu Id ------------------------------------------->   

    <MENUITEM id ="MENU_ID_EM_3G_INFO_SELECT_PLMN" str ="STR_ID_EM_3G_INFO_SELECT_PLMN"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_ACCESS_CLASS" str ="STR_ID_EM_3G_INFO_ACCESS_CLASS"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_SRNC_ID" str = "STR_ID_EM_3G_INFO_SRNC_ID"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_SRV_CELL_PLMN" str = "STR_ID_EM_3G_INFO_SRV_CELL_PLMN"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_SRV_CELL" str = "STR_ID_EM_3G_INFO_SRV_CELL"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_ACTIVE_CELL" str = "STR_ID_EM_3G_INFO_ACTIVE_CELL"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_INTRA_MONITORED_CELL" str = "STR_ID_EM_3G_INFO_INTRA_MONITORED_CELL"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_INTER_MONITORED_CELL" str = "STR_ID_EM_3G_INFO_INTER_MONITORED_CELL"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_DETECTED_CELL" str = "STR_ID_EM_3G_INFO_DETECTED_CELL"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_H_SRV_CELL" str = "STR_ID_EM_3G_INFO_H_SRV_CELL"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_PDP_DATA_SPEED" str = "STR_ID_EM_3G_INFO_PDP_DATA_SPEED"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_PS_SRV_INFO" str = "STR_ID_EM_3G_INFO_PS_SRV_INFO"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_BLK_ERR_RATE" str = "STR_ID_EM_3G_INFO_BLK_ERR_RATE"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_UE_TRANS_POWER" str = "STR_ID_EM_3G_INFO_UE_TRANS_POWER"/>



     <MENU id = "MENU_ID_EM_TDD" type = "APP_SUB" str = "STR_ID_EM_TDD" flag="CHECKBOX">
        <MENUITEM_ID>MENU_ID_EM_3G_INFO_SELECT_PLMN</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_3G_INFO_ACCESS_CLASS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_3G_INFO_SRNC_ID</MENUITEM_ID>
        
        <MENUITEM_ID>MENU_ID_EM_3G_INFO_SRV_CELL</MENUITEM_ID> 
        <MENUITEM_ID>MENU_ID_EM_3G_INFO_UMTS_CELL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_3G_INFO_GSM_CELL</MENUITEM_ID>
        
        <MENUITEM_ID>MENU_ID_EM_3G_INFO_PDP_DATA_SPEED</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_3G_INFO_PS_SRV_INFO</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_3G_INFO_BLK_ERR_RATE</MENUITEM_ID>
    </MENU>


    <MENUITEM id ="MENU_ID_EM_3G_INFO_UMTS_CELL" str = "STR_ID_EM_3G_INFO_UMTS_CELL"/>
    <MENUITEM id ="MENU_ID_EM_3G_INFO_GSM_CELL" str = "STR_ID_EM_3G_INFO_GSM_CELL"/>

    
#endif /*__MMI_EM_NW_TDD_NETWORK_INFO__*/


<!----------------- EM Item End ----------------------------------------------->




<!----------------- Level2 Menu | Device -------------------------------------->

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_DEVICE">Device</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_DEVICE" type = "APP_SUB" str = "STR_ID_EM_DEVICE">
    #ifdef __MMI_EM_DEV_SET_UART__
        <MENUITEM_ID>MENU_ID_EM_DEV_SET_UART</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_DEV_GPIO__
        <MENUITEM_ID>MENU_ID_EM_DEV_GPIO</MENUITEM_ID>
    #endif
    #ifdef __COLOR_HW_SUPPORTED__
        <MENUITEM_ID>MENU_ID_EM_MM_COLOR</MENUITEM_ID>
    #endif
    #ifdef __MMI_EM_DEV_BACKLIGHT__
    	<MENUITEM_ID>MENU_ID_EM_DEV_BACKLIGHT</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_EM_DEV_EINT__
        <MENUITEM_ID>MENU_ID_EM_DEV_EINT</MENUITEM_ID>
    #endif
    
    #if 0 //def __MMI_EM_DEV_ADC__
        <MENUITEM_ID>MENU_ID_EM_DEV_ADC</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_DEV_CLAM__
        <MENUITEM_ID>MENU_ID_EM_DEV_CLAM</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_EM_DEV_SET_HW_LEVEL__    
        <MENUITEM_ID>MENU_ID_EM_DEV_HW_LEVEL</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_DEV_SLEEP_MODE__
        <MENUITEM_ID>MENU_ID_EM_DEV_SLEEP_MODE</MENUITEM_ID>
    #endif
        
    #ifdef __MMI_EM_DEV_DCM_MODE__
        <MENUITEM_ID>MENU_ID_EM_DEV_DCM_MODE</MENUITEM_ID>
    #endif             

	#ifdef __MMI_BT_DIALER_SUPPORT__
		<MENUITEM_ID>MENU_ID_EM_DEV_BQB_MODE</MENUITEM_ID>
	#endif
        
    #ifdef __MMI_EM_DEV_NAND_FORMAT__
        <MENUITEM_ID>MENU_ID_EM_DEV_NAND_FORMAT</MENUITEM_ID>
    #endif
            
    #if defined(__MMI_EM_VIDEO_SETTING__)
    	<MENUITEM_ID>EM_DEV_VIDEO_SETTING_MENUID</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_VIDEO_STREAMING_SETTING__
        <MENUITEM_ID>MENU_ID_EM_DEV_VIDEO_STREAMING_SETTING</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_MOBILE_TV_SETTING__
        <MENUITEM_ID>MENU_ID_EM_DEV_MTV_SETTING</MENUITEM_ID>
    #endif
    
    #if (defined(__MMI_EM_DEV_USB_OTG_SRP__) || defined(__MMI_EM_DEV_USB_BOOT_MODE__) || defined(__MMI_EM_DEV_USB_TETHERING__))
        <MENUITEM_ID>MENU_ID_EM_DEV_USB</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_EM_DEV_MEMORY_TEST__
        <MENUITEM_ID>MENU_ID_EM_DEV_MEMORY_TEST</MENUITEM_ID>
    #endif
        
    #if (defined(__MMI_FM_RADIO__) && defined(__MMI_EM_DEV_FM_RADIO__))                  
        <MENUITEM_ID>MENU_ID_EM_DEV_FM_RADIO</MENUITEM_ID>
    #endif
            
    #ifdef __MMI_EM_DEV_TST_OUTPUT_MODE__
        <MENUITEM_ID>MENU_ID_EM_DEV_TST_OUTPUT_MODE</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_EM_DEV_USB_LOGGING__
        <MENUITEM_ID>MENU_ID_EM_DEV_USB_LOGGING</MENUITEM_ID>
    #endif 
    
    #ifdef __MMI_EM_CAM_AF_CONTSHOT__
        <MENUITEM_ID>MENU_ID_EM_DEV_CAM_AF_CONTSHOT</MENUITEM_ID>
    #endif
    
    #if defined(__GPS_SUPPORT__) || defined(__BT_GPS_SUPPORT__)
        <MENUITEM_ID>MENU_ID_EM_DEV_MINI_GPS</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_EM_MOTION_APP__
        <MENUITEM_ID>MENU_ID_EM_DEV_MOTION</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_DEV_SPEECH_LCD__
        <MENUITEM_ID>MENU_ID_EM_DEV_SPEECH_LCD</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_DEV_PMU_REGISTER_SETTING__
        <MENUITEM_ID>MENU_ID_EM_DEV_PMU_REG_SET</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_DEV_PXS_SENSOR__
        <MENUITEM_ID>MENU_ID_EM_DEV_PXS</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_DEV_WLAN_EAP_MODE__
        <MENUITEM_ID>MENU_ID_EM_DEV_WLAN_SETTING</MENUITEM_ID>
    #endif
    #ifdef __MMI_EM_NFC_SUPPORT__
        <MENUITEM_ID>MENU_ID_EM_NFC</MENUITEM_ID>
    #endif

    </MENU>
<!----------------- EM Item End ----------------------------------------------->
        


<!----------------- Device | GPIO ----------------------------------------->
#ifdef __MMI_EM_DEV_GPIO__
    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id = "SCR_ID_EM_DEV_GPIO_LIST"/>

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_DEV_GPIO">GPIO</STRING>
    <STRING id = "STR_ID_EM_DEV_GPIO_LIST_GPO_GPIO">List GPO/GPIO</STRING>
    <STRING id = "STR_ID_EM_DEV_GPIO_EDIT_GPIO">GPIO editor</STRING>
    <STRING id = "STR_ID_EM_DEV_GPIO_EDIT_GPO">GPO editor</STRING>
    <STRING id = "STR_ID_EM_DEV_GPIO_DIRECTION">Direction</STRING>
    <STRING id = "STR_ID_EM_DEV_GPIO_LEVEL">Current level</STRING>
    <STRING id = "STR_ID_EM_DEV_GPIO_DIRECTION_OUT">Out</STRING>
    <STRING id = "STR_ID_EM_DEV_GPIO_DIRECTION_IN">In</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_DEV_GPIO" type = "APP_SUB" str = "STR_ID_EM_DEV_GPIO">
        <MENUITEM id = "MENU_ID_EM_DEV_GPIO_LIST_GPO_GPIO" str = "STR_ID_EM_DEV_GPIO_LIST_GPO_GPIO"/>
        <MENUITEM id = "MENU_ID_EM_DEV_GPIO_EDIT_GPIO" str = "STR_ID_EM_DEV_GPIO_EDIT_GPIO"/>
        <MENUITEM id = "MENU_ID_EM_DEV_GPIO_EDIT_GPO" str = "STR_ID_EM_DEV_GPIO_EDIT_GPO"/>
    </MENU>

#endif/*__MMI_EM_DEV_GPIO__*/
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Device | MM Color ----------------------------------------->
#ifdef __COLOR_HW_SUPPORTED__
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_DEV_MM_COLOR">MM Color Adjust</STRING>
    <STRING id = "STR_ID_EM_DEV_SHARP">Sharpness</STRING>
    <STRING id = "STR_ID_EM_DEV_CONTRAST">Contrast</STRING>
    <STRING id = "STR_ID_EM_DEV_SATURATION">Saturation</STRING>    
    <!----------------- Menu Id -------------------------------------------> 
    <MENUITEM id = "MENU_ID_EM_MM_COLOR" str = "STR_ID_EM_DEV_MM_COLOR"/>
#endif /*__COLOR_HW_SUPPORTED__*/
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Device | Backlight ------------------------------------------>


#if (defined(__MMI_EM_DEV_BACKLIGHT__)||defined(__MMI_EM_60BACKLIGHT__))
    <STRING id = "STR_ID_EM_DEV_BACKLIGHT_LEVEL">Level</STRING>
    <STRING id = "STR_ID_EM_DEV_BACKLIGHT_FREQ">Frequency</STRING>
    <STRING id = "STR_ID_EM_DEV_BACKLIGHT_DUTY">Duty</STRING>
    <STRING id = "STR_ID_EM_DEV_BACKLIGHT_INVALID_DUTY">Duty out of range</STRING>
    <STRING id = "STR_ID_EM_DEV_BACKLIGHT_INVALID_FREQ">Freq out of range</STRING>
    <STRING id = "STR_ID_EM_DEV_BACKLIGHT_INVALID_POPUP1"> of level </STRING>
    <STRING id = "STR_ID_EM_DEV_BACKLIGHT_INVALID_POPUP2"> is out of range</STRING>
    
    <MENU id = "MENU_ID_EM_DEV_BACKLIGHT" type = "APP_SUB" str = "STR_ID_EM_DEV_BACKLIGHT" />
    
#endif

<!----------------- EM Item End ----------------------------------------------->

<!----------------- Device | EINT ----------------------------------------->
#ifdef __MMI_EM_DEV_EINT__
    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id = "SCR_ID_EM_DEV_EINT"/> 

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_DEV_EINT">Eint</STRING>                                 <!-- Engineer Mode Menu Caption String -->
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_DEV_EINT" type = "APP_SUB" str = "STR_ID_EM_DEV_EINT">
    </MENU>
    
#endif /* __MMI_EM_DEV_EINT__ */    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Device | ADC ------------------------------------------>
#if 0 //def __MMI_EM_DEV_ADC__
    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id = "SCR_ID_EM_DEV_ADC"/>

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_DEV_ADC">Adc</STRING>                                   <!-- Engineer Mode Menu Caption String -->
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_DEV_ADC" type = "APP_SUB" str = "STR_ID_EM_DEV_ADC">
    </MENU>
#endif/*__MMI_EM_DEV_ADC__*/
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Device | CLAM ----------------------------------------->
#ifdef __MMI_EM_DEV_CLAM__

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_DEV_CLAM">Clam</STRING>                                 <!-- Engineer Mode Menu Caption String -->
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_DEV_CLAM" type = "APP_SUB" str = "STR_ID_EM_DEV_CLAM">
    </MENU>
    
#endif /* __MMI_EM_DEV_CLAM__ */    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Device | HW Level ----------------------------------------->
#ifdef __MMI_EM_DEV_SET_HW_LEVEL__
    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_EM_DEV_HW_LEVEL">Set default level</STRING>                <!-- Engineer Mode Menu Caption String -->

    <STRING id = "STR_ID_EM_DEV_HW_LEVEL_BATTERY">Battery</STRING>                  <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_PWM_SET_1">Pwm1</STRING>
    <STRING id = "STR_ID_EM_DEV_PWM_SET_2">Pwm2</STRING>
    <STRING id = "STR_ID_EM_DEV_PWM_SET_3">Pwm3</STRING>

    <STRING id = "STR_ID_EM_DEV_LCD_SET_PARAM_1">Set value</STRING>             

    <!----------------- Menu Id ------------------------------------------->
    <MENU id = "MENU_ID_EM_DEV_HW_LEVEL" type = "APP_SUB" str = "STR_ID_EM_DEV_HW_LEVEL">
        <MENUITEM id = "MENU_ID_EM_DEV_HW_LEVEL_BATTERY" str = "STR_ID_EM_DEV_HW_LEVEL_BATTERY"/>
        #ifdef __MMI_EM_60BACKLIGHT__
        <MENUITEM_ID>MENU_ID_EM_DEV_BACKLIGHT</MENUITEM_ID>
        #else
        <MENUITEM id = "MENU_ID_EM_DEV_HW_LEVEL_PWM1" str = "STR_ID_EM_DEV_PWM_SET_1"/>
        <MENUITEM id = "MENU_ID_EM_DEV_HW_LEVEL_PWM2" str = "STR_ID_EM_DEV_PWM_SET_2"/>
        <MENUITEM id = "MENU_ID_EM_DEV_HW_LEVEL_PWM3" str = "STR_ID_EM_DEV_PWM_SET_3"/>
        #endif
    </MENU>
#endif/*__MMI_EM_DEV_SET_HW_LEVEL__*/    
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Device | Set UART ----------------------------------------->
#ifdef __MMI_EM_DEV_SET_UART__
    <!----------------- Screen Id -----------------------------------------> 
    <SCREEN id = "SCR_ID_EM_DEV_UART_POWER_ONOFF_MENU"/>

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_DEV_SET_UART">Set UART</STRING>                         <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_SET_UART_SETTING">UART setting</STRING>             <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_SET_UART_TST_PS">TST-PS config</STRING>             <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_SET_UART_TST_L1">TST-L1 config</STRING>             <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_SET_UART_PS">PS config</STRING>                     <!-- Engineer Mode Menu Caption String -->

#ifdef __MMI_USB_SUPPORT__
    <STRING id = "STR_ID_EM_DEV_USB_PORT">USB port</STRING>                         <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_USB_PORT2">USB port 2</STRING>                      <!-- Engineer Mode Menu Caption String -->
#endif

#if defined(__MA_L1__)
    <STRING id = "STR_ID_EM_DEV_SET_UART_CTI_ENABLE">CTI log config</STRING>        <!-- Engineer Mode Menu Caption String -->
#endif

    <STRING id = "STR_ID_EM_DEV_UART_1">UART 1</STRING>                             <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_UART_2">UART 2</STRING>                             <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_UART_3">UART 3</STRING>                             <!-- Engineer Mode Menu Caption String -->

 #if defined(__TST_DNT_LOGGING__) && defined(__LOGACC_ENABLE__)
    <STRING id = "STR_ID_EM_DEV_UART_PORT_LGA1">LGA port 1</STRING>
    <STRING id = "STR_ID_EM_DEV_UART_PORT_LGA2">LGA port 2</STRING>
 #endif
 
 #if defined(__TST_LMU_LOGGING__)
    <STRING id = "STR_ID_EM_DEV_UART_PORT_LMU">LMU port</STRING>
 #endif
 
 #if defined(__DSP_FCORE4__)
    <STRING id = "STR_ID_EM_DEV_SET_UART_TST_DSP">DSP port</STRING>
 #endif /* __DSP_FCORE4__ */

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_DEV_SET_UART" type = "APP_SUB" str = "STR_ID_EM_DEV_SET_UART">
        <MENUITEM id = "MENU_ID_EM_DEV_UART_SETTING" str = "STR_ID_EM_DEV_SET_UART_SETTING"/>
    </MENU>

#endif/*__MMI_EM_DEV_SET_UART__*/ 
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Device | Sleep Mode --------------------------------------->
#ifdef __MMI_EM_DEV_SLEEP_MODE__
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_DEV_SLEEP_MODE">Sleep mode</STRING>                     <!-- Engineer Mode Menu Caption String -->
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_DEV_SLEEP_MODE" type = "APP_SUB" str = "STR_ID_EM_DEV_SLEEP_MODE" flag = "RADIO">
        <MENUITEM id = "MENU_ID_EM_DEV_SLEEP_MODE_ON" str = "STR_GLOBAL_ON"/>
        <MENUITEM id = "MENU_ID_EM_DEV_SLEEP_MODE_OFF" str = "STR_GLOBAL_OFF"/>
    </MENU>
#endif/*__MMI_EM_DEV_SLEEP_MODE__*/  
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Device | DCM Mode ----------------------------------------->
#ifdef __MMI_EM_DEV_DCM_MODE__

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_DEV_DCM_MODE">DCM mode</STRING>                         <!-- Engineer Mode Menu Caption String -->

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_DEV_DCM_MODE" type = "APP_SUB" str = "STR_ID_EM_DEV_DCM_MODE" flag = "RADIO">
        <MENUITEM id = "MENU_ID_EM_DEV_DCM_MODE_ON" str = "STR_GLOBAL_ON"/>
        <MENUITEM id = "MENU_ID_EM_DEV_DCM_MODE_OFF" str = "STR_GLOBAL_OFF"/>
    </MENU>
    
#endif /* __MMI_EM_DEV_DCM_MODE__ */    
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Device | BQB Mode ----------------------------------------->
#ifdef __MMI_BT_DIALER_SUPPORT__

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_DEV_BQB_MODE">BQB mode</STRING>                         <!-- Engineer Mode Menu Caption String -->

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_DEV_BQB_MODE" type = "APP_SUB" str = "STR_ID_EM_DEV_BQB_MODE" flag = "RADIO">
        <MENUITEM id = "MENU_ID_EM_DEV_BQB_MODE_ON" str = "STR_GLOBAL_ON"/>
        <MENUITEM id = "MENU_ID_EM_DEV_BQB_MODE_OFF" str = "STR_GLOBAL_OFF"/>
    </MENU>
    
#endif /* __MMI_BT_DIALER_SUPPORT__ */    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Device | NAND Format -------------------------------------->
#ifdef __MMI_EM_DEV_NAND_FORMAT__

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_DEV_NAND_FORMAT">Nand format</STRING>                   <!-- Engineer Mode Menu Caption String -->
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_DEV_NAND_FORMAT" type = "APP_SUB" str = "STR_ID_EM_DEV_NAND_FORMAT">
    </MENU>
    
#endif /* __MMI_EM_DEV_NAND_FORMAT__ */    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- EM Item End ----------------------------------------------->


<!----------------- Device | MTV Setting --------------------------------------->
#ifdef __MMI_EM_MOBILE_TV_SETTING__
	<!----------------- Screen Id ----------------------------------------->
	<SCREEN id = "GRP_ID_EM_DEV_MTV_SETTING"/>

	<!----------------- Menu Id ----------------------------------------->
	<MENUITEM id = "MENU_ID_EM_DEV_MTV_SETTING" str = "STR_ID_EM_DEV_MTV_SETTING"/>
       
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_DEV_MTV_SETTING">Mobile TV</STRING>                     <!-- Engineer Mode Menu Caption String -->
    
//#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
	<STRING id = "STR_ID_EM_DEV_MTV_SETTING_SET_MTS">Set MTS</STRING> 
    <STRING id = "STR_ID_EM_DEV_MTV_SETTING_DUMP_CHANNEL">Dump channel</STRING> 
    <STRING id = "STR_ID_EM_DEV_MTV_SETTING_DEMOD_SIM">Demod simulation</STRING> 
    <STRING id = "STR_ID_EM_DEV_MTV_SETTING_SHOW_DEMOD_STATUS">Show demod status</STRING>
    <STRING id = "STR_ID_EM_DEV_MTV_SETTING_SAVE_ESG">Save ESG</STRING>
    <STRING id = "STR_ID_EM_DEV_MTV_SETTING_MFS">.mfs</STRING> 
    <STRING id = "STR_ID_EM_DEV_MTV_SETTING_CMMB">.cmmb</STRING> 
//#endif
#if defined(__MMI_ATV_SUPPORT__)
	<STRING id = "STR_ID_EM_DEV_MTV_SETTING_CLI">Set CLI</STRING> 
#endif
    
#endif /* __MMI_EM_MOBILE_TV_SETTING__ */    
<!----------------- EM Item End ----------------------------------------------->

<!----------------- Device | Video Setting --------------------------------------->
#ifdef __MMI_EM_VIDEO_SETTING__
	<!----------------- Screen Id ----------------------------------------->
	<SCREEN id = "GRP_ID_EM_DEV_VIDEO_SETTING"/>

	<!----------------- Menu Id ----------------------------------------->

	<MENU id = "EM_DEV_VIDEO_SETTING_MENUID" type = "APP_SUB" str = "STR_ID_EM_DEV_VIDEO_SETTING">
       <MENUITEM id = "EM_DEV_VIDEO_SETTING_MP4_MENUID" str = "STR_ID_EM_DEV_VIDEO_SETTING_MP4"/>
       <MENUITEM id = "EM_DEV_VIDEO_SETTING_H264_MENUID" str = "STR_ID_EM_DEV_VIDEO_SETTING_H264"/>
       <MENUITEM id = "EM_DEV_VIDEO_SETTING_RM_MENUID" str = "STR_ID_EM_DEV_VIDEO_SETTING_RM"/>
       <MENUITEM id = "EM_DEV_VIDEO_SETTING_VP8_MENUID" str = "STR_ID_EM_DEV_VIDEO_SETTING_VP8"/>

       <MENUITEM id = "EM_DEV_VIDEO_SETTING_CODEC_MP4_MENUID" str = "STR_ID_EM_DEV_VIDEO_SETTING_CODEC_MP4"/>
       <MENUITEM id = "EM_DEV_VIDEO_SETTING_CODEC_H264_MENUID" str = "STR_ID_EM_DEV_VIDEO_SETTING_CODEC_H264"/>
       <MENUITEM id = "EM_DEV_VIDEO_SETTING_CODEC_RM_MENUID" str = "STR_ID_EM_DEV_VIDEO_SETTING_CODEC_RM"/>
       <MENUITEM id = "EM_DEV_VIDEO_SETTING_CODEC_VP8_MENUID" str = "STR_ID_EM_DEV_VIDEO_SETTING_CODEC_VP8"/>

       <MENUITEM id = "EM_DEV_VIDEO_SETTING_MODE_MP4_MENUID" str = "STR_ID_EM_DEV_VIDEO_SETTING_MODE_MP4"/>
       <MENUITEM id = "EM_DEV_VIDEO_SETTING_MODE_H264_MENUID" str = "STR_ID_EM_DEV_VIDEO_SETTING_MODE_H264"/>
       <MENUITEM id = "EM_DEV_VIDEO_SETTING_MODE_RM_MENUID" str = "STR_ID_EM_DEV_VIDEO_SETTING_MODE_RM"/>
       <MENUITEM id = "EM_DEV_VIDEO_SETTING_MODE_VP8_MENUID" str = "STR_ID_EM_DEV_VIDEO_SETTING_MODE_VP8"/>
        
    </MENU>
    <!----------------- String Id -----------------------------------------> 
    <STRING id = "STR_ID_EM_DEV_VIDEO_SETTING">Video setting</STRING>  
    <STRING id = "STR_ID_EM_DEV_VIDEO_SETTING_MP4">MP4</STRING>
    <STRING id = "STR_ID_EM_DEV_VIDEO_SETTING_H264">H264</STRING>
	<STRING id = "STR_ID_EM_DEV_VIDEO_SETTING_RM">RM</STRING>
	<STRING id = "STR_ID_EM_DEV_VIDEO_SETTING_VP8">VP8</STRING>
	
	<STRING id = "STR_ID_EM_DEV_VIDEO_SETTING_CODEC_MP4">Codec MP4</STRING>
	<STRING id = "STR_ID_EM_DEV_VIDEO_SETTING_CODEC_H264">Codec H264</STRING>
	<STRING id = "STR_ID_EM_DEV_VIDEO_SETTING_CODEC_RM">Codec RM</STRING>
	<STRING id = "STR_ID_EM_DEV_VIDEO_SETTING_CODEC_VP8">Codec VP8</STRING>
	
    <STRING id = "STR_ID_EM_DEV_VIDEO_SETTING_MODE_MP4">Mode MP4</STRING>
    <STRING id = "STR_ID_EM_DEV_VIDEO_SETTING_MODE_H264">Mode H264</STRING>
    <STRING id = "STR_ID_EM_DEV_VIDEO_SETTING_MODE_RM">Mode RM</STRING>
    <STRING id = "STR_ID_EM_DEV_VIDEO_SETTING_MODE_VP8">Mode VP8</STRING>
		
    <STRING id = "STR_ID_EM_DEV_VIDEO_SETTING_PLAY_MODE">Play mode</STRING>
    <STRING id = "STR_ID_EM_DEV_VIDEO_SETTING_FLUENCY">Fluency</STRING>
    <STRING id = "STR_ID_EM_DEV_VIDEO_SETTING_BALANCE">Balance</STRING>
    <STRING id = "STR_ID_EM_DEV_VIDEO_SETTING_QUALITY">Quality</STRING>
    <STRING id = "STR_ID_EM_DEV_VIDEO_SETTING_LAST_MODE">Last mode</STRING>
    
    <STRING id = "STR_ID_EM_DEV_VIDEO_SETTING_FLUENCY_SETTING">Fluency setting</STRING>
#endif /* __MMI_EM_VIDEO_SETTING__ */    
<!----------------- EM Item End ----------------------------------------------->

<!----------------- Device | Video Streaming setting --------------------------------------->
#ifdef __MMI_EM_VIDEO_STREAMING_SETTING__
	<!----------------- Screen Id ----------------------------------------->
	<SCREEN id = "GRP_ID_EM_DEV_VIDEO_STREAMING_SETTING"/>

	<!----------------- Menu Id ----------------------------------------->
	<MENUITEM id = "MENU_ID_EM_DEV_VIDEO_STREAMING_SETTING" str = "STR_ID_EM_DEV_VIDEO_STREAMING_SETTING"/>

    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_EM_DEV_VIDEO_STREAMING_SETTING">Video Streaming</STRING>  <!-- Engineer Mode Menu Caption String -->

    <STRING id = "STR_ID_EM_DEV_VIDEO_STREAMING_UA">User Agent</STRING>
	<STRING id = "STR_ID_EM_DEV_VIDEO_STREAMING_UA_MTK">MTK</STRING>
    <STRING id = "STR_ID_EM_DEV_VIDEO_STREAMING_UA_RM">RM</STRING>
    <STRING id = "STR_ID_EM_DEV_VIDEO_STREAMING_TRANSPORT">Transport Type</STRING>
	<STRING id = "STR_ID_EM_DEV_VIDEO_STREAMING_TRANSPORT_UDP">UDP</STRING>
    <STRING id = "STR_ID_EM_DEV_VIDEO_STREAMING_TRANSPORT_TCP">TCP</STRING>
    <STRING id = "STR_ID_EM_DEV_VIDEO_STREAMING_SETTING_PREBUFFER_TIME">Prebuffer Time</STRING>

#endif /* __MMI_EM_VIDEO_STREAMING_SETTING__ */
<!----------------- EM Item End ----------------------------------------------->

<!----------------- Device | USB ---------------------------------------------->
#if (defined(__MMI_EM_DEV_USB_OTG_SRP__) || defined(__MMI_EM_DEV_USB_BOOT_MODE__) || defined(__MMI_EM_DEV_USB_TETHERING__))
    <SCREEN id = "SCR_ID_EM_DEV_USB_BOOT_MODE"/>
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_DEV_USB">USB</STRING>                                   <!-- Engineer Mode Menu Caption String --> 
#if defined(__MMI_EM_DEV_USB_OTG_SRP__)
    <STRING id = "STR_ID_EM_DEVICE_USB_OTG_SRP">OTG SRP</STRING>                    <!-- Engineer Mode Menu Caption String --> 
#endif
#if defined(__MMI_EM_DEV_USB_BOOT_MODE__)
    <STRING id = "STR_ID_EM_DEVICE_USB_ROOT_MODE">USB boot mode</STRING>            <!-- Engineer Mode Menu Caption String --> 
#endif
#if defined(__MMI_EM_DEV_USB_TETHERING__)
    <STRING id = "STR_ID_EM_DEV_USB_TETHERING">USB tethering</STRING>            <!-- Engineer Mode Menu Caption String --> 
#endif

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_DEV_USB" type = "APP_SUB" str = "STR_ID_EM_DEV_USB">
    #if defined(__MMI_EM_DEV_USB_OTG_SRP__)
        <MENUITEM id = "MENU_ID_EM_DEVICE_USB_OTG_SRP" str = "STR_ID_EM_DEVICE_USB_OTG_SRP"/>
    #endif
    #if defined(__MMI_EM_DEV_USB_BOOT_MODE__)
        <MENUITEM id = "MENU_ID_EM_DEVICE_USB_ROOT_MODE" str = "STR_ID_EM_DEVICE_USB_ROOT_MODE"/>
    #endif
    #if defined(__MMI_EM_DEV_USB_TETHERING__)
    	<MENUITEM id = "MENU_ID_EM_DEVICE_USB_TETHERING" str = "STR_ID_EM_DEV_USB_TETHERING"/>
    #endif
    </MENU>
    #if defined(__MMI_EM_DEV_USB_TETHERING__)
    <MENU id = "MENU_ID_EM_DEV_USB_TETHERING" str = "STR_ID_EM_DEV_USB_TETHERING" flag = "RADIO">         <!-- Add by mtk80729 -->
	<MENUITEM id = "MENU_ID_EM_DEV_USB_TETHERING_ENABLE" str = "STR_GLOBAL_ON"/>     <!-- Add by mtk80729 -->
	<MENUITEM id = "MENU_ID_EM_DEV_USB_TETHERING_DISABLE" str = "STR_GLOBAL_OFF"/>   <!-- Add by mtk80729 -->
    </MENU>
    #endif
    
#endif /* __MMI_EM_DEV_USB_OTG_SRP__ || __MMI_EM_DEV_USB_BOOT_MODE__ */    
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Device | Memory TEST ---------------------------------------------->
#ifdef __MMI_EM_DEV_MEMORY_TEST__

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_DEV_MEMORY_TEST">Memory info</STRING>                          <!-- Engineer Mode Menu Caption String --> 
    <STRING id = "STR_ID_EM_DEV_MEMORY_TEST_EMI_SETTING">EMI register settings</STRING>    <!-- Engineer Mode Menu Caption String --> 
    <STRING id = "STR_ID_EM_DEV_MEMORY_TEST_CUSTOM_SETTING">Custom settings</STRING>       <!-- Engineer Mode Menu Caption String --> 
    <STRING id = "STR_ID_EM_DEV_MEMORY_TEST_FLASH_INFO">Flash physical info</STRING>       <!-- Engineer Mode Menu Caption String --> 

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_DEV_MEMORY_TEST" type = "APP_SUB" str = "STR_ID_EM_DEV_MEMORY_TEST">
        <MENUITEM id = "MENU_ID_EM_DEV_MEMORY_TEST_EMI_SETTING" str = "STR_ID_EM_DEV_MEMORY_TEST_EMI_SETTING"/>
        <MENUITEM id = "MENU_ID_EM_DEV_MEMORY_TEST_CUSTOM_SETTING" str = "STR_ID_EM_DEV_MEMORY_TEST_CUSTOM_SETTING"/>
        <MENUITEM id = "MENU_ID_EM_DEV_MEMORY_TEST_FLASH_INFO" str = "STR_ID_EM_DEV_MEMORY_TEST_FLASH_INFO"/>
    </MENU>
    
#endif /* __MMI_EM_DEV_MEMORY_TEST__ */    
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Device | FM Radio ----------------------------------------->
#if (defined(__MMI_FM_RADIO__) && defined(__MMI_EM_DEV_FM_RADIO__))
    <SCREEN id  = "SCR_ID_EM_DEV_FM_RADIO_RSSI_INFO"/>
#ifndef __MMI_SLIM_ENGINEER_MODE__
    <SCREEN id  = "SCR_ID_EM_DEV_FM_RADIO_RSSI_INFO_OTHER"/>
#endif /* __MMI_SLIM_ENGINEER_MODE__ */
    
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_DEV_FM_RADIO">FM radio</STRING>                         <!-- Engineer Mode Menu Caption String --> 
#ifndef __MMI_SLIM_ENGINEER_MODE__
    <STRING id = "STR_ID_EM_DEVICE_FM_RADIO_MONO">Mono</STRING>                     <!-- Engineer Mode Menu Caption String --> 
    <STRING id = "STR_ID_EM_DEVICE_FM_RADIO_STEREO">Stereo</STRING>                <!-- Engineer Mode Menu Caption String --> 
    <STRING id = "STR_ID_EM_DEVICE_FM_RADIO_RSSI">Rssi</STRING>                     <!-- Engineer Mode Menu Caption String --> 
    <STRING id = "STR_ID_EM_DEVICE_FM_RADIO_THOSRHELD">Radio threshold</STRING>     <!-- Engineer Mode Menu Caption String --> 
#endif /* __MMI_SLIM_ENGINEER_MODE__ */
    <STRING id = "STR_ID_EM_DEVICE_FM_RADIO_STATUS">Radio status</STRING>           <!-- Engineer Mode Menu Caption String --> 
    <STRING id = "STR_ID_EM_DEV_FMR_FRE_MHZ">Fre(KHz)</STRING>                      <!-- Engineer Mode FM Radio Stereo Menu Caption String --> 
#ifndef __MMI_SLIM_ENGINEER_MODE__
    <STRING id = "STR_ID_EM_DEV_FMR_FORCE_SET">Force set</STRING>                   <!-- Engineer Mode FM Radio Stereo Menu Caption String --> 	
    <STRING id = "STR_ID_EM_DEV_FMR_ANTENNA_TYPE">Antenna type</STRING>             <!-- Engineer Mode FM Radio IF count delta 10 Caption String --> 	
    <STRING id = "STR_ID_EM_DEV_FMR_LONG_ANT">Long ANT.(Hex)</STRING>               <!-- Engineer Mode FM Radio IF count delta 15 Caption String --> 	
    <STRING id = "STR_ID_EM_DEV_FMR_SHORT_ANT">Short ANT.(Hex)</STRING>             <!-- Engineer Mode FM Radio IF count delta 20 Caption String --> 	
    <STRING id = "STR_ID_EM_DEV_FMR_ANT_LONG">Long ant</STRING>               <!-- Engineer Mode FM Radio IF count delta 15 Caption String --> 	
    <STRING id = "STR_ID_EM_DEV_FMR_ANT_SHORT">Short ant</STRING>             <!-- Engineer Mode FM Radio IF count delta 20 Caption String --> 	
#endif /* __MMI_SLIM_ENGINEER_MODE__ */
    <STRING id = "STR_ID_EM_DEVICE_FM_RADIO_COMN_CMD">Radio common cmd</STRING>
    <STRING id = "STR_ID_EM_DEVICE_FM_RADIO_COMN_CMD_INPUT">Input:</STRING>
    <STRING id = "STR_ID_EM_DEVICE_FM_RADIO_COMN_CMD_OUTPUT">Cmd output</STRING>
 
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_DEV_FM_RADIO" type = "APP_SUB" str = "STR_ID_EM_DEV_FM_RADIO">
        <MENUITEM id = "MENU_ID_EM_DEVICE_FM_RADIO_STATUS" str = "STR_ID_EM_DEVICE_FM_RADIO_STATUS"/>
    #ifndef __MMI_SLIM_ENGINEER_MODE__
        <MENUITEM id = "MENU_ID_EM_DEVICE_FM_RADIO_THOSRHELD" str = "STR_ID_EM_DEVICE_FM_RADIO_THOSRHELD"/>
    #endif /* __MMI_SLIM_ENGINEER_MODE__ */
        <MENUITEM id = "MENU_ID_EM_DEVICE_FM_RADIO_COMN_CMD" str = "STR_ID_EM_DEVICE_FM_RADIO_COMN_CMD"/>
    </MENU>
#endif /* __MMI_FM_RADIO__ &&  __MMI_EM_DEV_FM_RADIO__*/    
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Device | TST Output Mode----------------------------------->
#ifdef __MMI_EM_DEV_TST_OUTPUT_MODE__
    <!----------------- String Id ----------------------------------------->
    <SCREEN id = "SCR_ID_EM_DEV_TST_OUTPUT_MODE"/>

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_DEV_TST_OUTPUT_MODE">TST output mode</STRING>           <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_TST_OUTPUT_MODE_UART">UART</STRING>
    <STRING id = "STR_ID_EM_DEV_TST_OUTPUT_MODE_FILE">File</STRING>
    <STRING id = "STR_ID_EM_DEV_TST_OUTPUT_MODE_BOTH">Both</STRING>
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_DEV_TST_OUTPUT_MODE" type = "APP_SUB" str = "STR_ID_EM_DEV_TST_OUTPUT_MODE">
    </MENU>
    
#endif /* __MMI_EM_DEV_TST_OUTPUT_MODE__ */    
<!----------------- EM Item End ----------------------------------------------->




<!----------------- Device | USB Logging -------------------------------------->
#ifdef __MMI_EM_DEV_USB_LOGGING__
    <!----------------- String Id ----------------------------------------->
    <SCREEN id = "SCR_ID_EM_DEV_USB_LOGGING"/>

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_DEV_USB_LOGGING">USB logging</STRING>                   <!-- Engineer Mode Menu Caption String -->
#ifdef __DSPIRDBG__
    <STRING id = "STR_ID_EM_SWDBG_MCU_DSP_IRDBG">DSP IRDBG</STRING>                 <!-- Engineer Mode Menu Caption String -->	 
#endif /* #ifdef __DSPIRDBG__ */
#ifdef __MODEM_3G_LOGGING__
    <STRING id = "STR_ID_EM_DEV_USB_LOGGING_3G_LOGGING">3G Logging</STRING>         <!-- Engineer Mode Menu Caption String -->	 
#endif /* #ifdef __MODEM_3G_LOGGING__ */
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_DEV_USB_LOGGING" type = "APP_SUB" str = "STR_ID_EM_DEV_USB_LOGGING">
       
    </MENU>
    
#endif /* __MMI_EM_DEV_USB_LOGGING__ */    
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Device | CAM AF Constshot --------------------------------->
#ifdef __MMI_EM_CAM_AF_CONTSHOT__
    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id = "GRP_ID_EM_DEV_CAM_AF_CONTSHOT"/>
    <SCREEN id = "GRP_ID_EM_DEV_CAM_AF_CONTSHOT_AF_RANGE"/>
    <SCREEN id = "GRP_ID_EM_DEV_CAM_AF_CONTSHOT_RAW_SAVE"/>
    <SCREEN id = "GRP_ID_EM_DEV_CAM_AF_CONTSHOT_APP_START"/>
    <SCREEN id = "GRP_ID_EM_DEV_CAM_AF_CONTSHOT_CAP_SIZE"/>
    <SCREEN id = "GRP_ID_EM_DEV_CAM_AF_CONTSHOT_STORAGE"/>
    <SCREEN id = "GRP_ID_EM_DEV_CAM_AF_CONTSHOT_SHADING"/>
    
    <SCREEN id = "SCR_ID_EM_DEV_CAM_AF_CONTSHOT"/>
    <SCREEN id = "SCR_ID_EM_DEV_CAM_AF_CONTSHOT_AF_RANGE"/>
	<SCREEN id = "SCR_ID_EM_DEV_CAM_AF_CONTSHOT_RAW_SAVE"/>
	<SCREEN id = "SCR_ID_EM_DEV_CAM_AF_CONTSHOT_RAW_SAVE_TYPE"/>
	<SCREEN id = "SCR_ID_EM_DEV_CAM_AF_CONTSHOT_CAP_SIZE"/>
	<SCREEN id = "SCR_ID_EM_DEV_CAM_AF_CONTSHOT_APP_START"/>
	<SCREEN id = "SCR_ID_EM_DEV_CAM_AF_CONTSHOT_SHADING"/>
	
    <!----------------- String Id ----------------------------------------->             
	<STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_AF_RANGE_MODE0">AF_FULL_SCAN_FORW1</STRING>			<!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_AF_RANGE_MODE1">AF_FULL_SCAN_FORW4</STRING>  		<!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_AF_RANGE_MODE2">AF_FULL_SCAN_BACK1</STRING>   		<!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_AF_RANGE_MODE3">AF_FULL_SCAN_BACK4</STRING>    		<!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_AF_RANGE_MODE4">AF_CONT_FOCUS_SHOT</STRING>    		<!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_AF_RANGE_MODE5">AF_BEST_BRACKET_SHOT</STRING>  		<!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_AF_RANGE_MODE6">AF_CONT_FOWARD_LOG</STRING> 		<!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_AF_RANGE_MODE7">AF_CONT_BACKWARD_LOG</STRING> 		<!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_AF_RANGE_MODE8">AF_SINGLE_FORWARD_LOG</STRING> 		<!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_AF_RANGE_MODE9">AE_FULL_SCAN</STRING> 				<!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_AF_RANGE_MODE10">AE_EV_CONVERGE</STRING> 			<!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_AF_RANGE_MODE11">AWB_SEQ_PREVIEW_log_SAVE</STRING> 			<!-- Engineer Mode Menu Caption String -->

    <STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT">Camera 3A test</STRING>             			<!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_STORAGE">Storages</STRING>   			<!-- Engineer Mode Menu Caption String --> 
    <STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_AF_RANGE">Test mode</STRING>      		<!-- Engineer Mode Menu Caption String --> 
    <STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_RAW_SAVE">Raw save option</STRING>		<!-- Engineer Mode Menu Caption String --> 
    <STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_CAPSIZE">Capture size</STRING>    		<!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_RAW_SAVE_DISABLE">Disable</STRING>          		<!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_RAW_SAVE_8BITS">Enable, 8 bits</STRING>    					<!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_RAW_SAVE_10BITS">Enable, 10 bits</STRING>    				<!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_APP">Start</STRING>               		<!-- Engineer Mode Menu Caption String --> 
    <STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_RAW_SAVE_TYPE">Raw Type</STRING>    		<!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_CAPSIZE_PREVIEW">Preview size</STRING>    			<!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_CAPSIZE_MAXRESOLUTION">Max capture size</STRING>   	<!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_SHADING">Shading compensate</STRING>   	<!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_SHADING_ENABLE">Enable</STRING>          		<!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_SHADING_DISABLE">Disable</STRING>          		<!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_AUTO_TEST">AutoTest</STRING>          			<!-- Engineer Mode Menu Caption String -->

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_DEV_CAM_AF_CONTSHOT" type = "APP_SUB" str = "STR_ID_EM_DEV_CAM_AF_CONTSHOT">
    	<MENUITEM id = "MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_STORAGE" str = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_STORAGE"/>
    	<MENUITEM_ID>MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_AF_RANGE</MENUITEM_ID>
    	<MENUITEM_ID>MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_RAW_SAVE</MENUITEM_ID>
    	<MENUITEM_ID>MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_CAPSIZE</MENUITEM_ID>
    	<MENUITEM_ID>MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_SHADING</MENUITEM_ID>
        <MENUITEM id = "MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_APP" str = "STR_GLOBAL_START"/>
    </MENU>


    <MENU id = "MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_AF_RANGE" type = "APP_SUB" str = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_AF_RANGE">
        <MENUITEM id = "MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_AF_RANGE_MODE0" str = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_AF_RANGE_MODE0"/>
        <MENUITEM id = "MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_AF_RANGE_MODE1" str = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_AF_RANGE_MODE1"/>
        <MENUITEM id = "MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_AF_RANGE_MODE2" str = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_AF_RANGE_MODE2"/>
        <MENUITEM id = "MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_AF_RANGE_MODE3" str = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_AF_RANGE_MODE3"/>
        <MENUITEM id = "MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_AF_RANGE_MODE4" str = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_AF_RANGE_MODE4"/>
        <MENUITEM id = "MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_AF_RANGE_MODE5" str = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_AF_RANGE_MODE5"/>
        <MENUITEM id = "MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_AF_RANGE_MODE6" str = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_AF_RANGE_MODE6"/>
        <MENUITEM id = "MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_AF_RANGE_MODE7" str = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_AF_RANGE_MODE7"/>
        <MENUITEM id = "MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_AF_RANGE_MODE8" str = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_AF_RANGE_MODE8"/>
        <MENUITEM id = "MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_AF_RANGE_MODE9" str = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_AF_RANGE_MODE9"/>
        <MENUITEM id = "MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_AF_RANGE_MODE10" str = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_AF_RANGE_MODE10"/>
    </MENU>

    <MENU id = "MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_RAW_SAVE" type = "APP_SUB" str = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_RAW_SAVE">
        <MENUITEM id = "MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_RAW_SAVE_DISABLE" str = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_RAW_SAVE_DISABLE"/>
        <MENUITEM id = "MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_RAW_SAVE_8BITS" str = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_RAW_SAVE_8BITS"/>
		#ifdef __CAMCORDER_PACKAGE_FULL__
        <MENUITEM id = "MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_RAW_SAVE_10BITS" str = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_RAW_SAVE_10BITS"/>
        #endif
    </MENU>  

    <MENU id = "MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_CAPSIZE" type = "APP_SUB" str = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_CAPSIZE">
        <MENUITEM id = "MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_CAPSIZE_PREVIEW" str = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_CAPSIZE_PREVIEW"/>
        <MENUITEM id = "MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_CAPSIZE_MAXRES" str = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_CAPSIZE_MAXRESOLUTION"/>    
    </MENU> 

    <MENU id = "MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_SHADING" type = "APP_SUB" str = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_SHADING">
        <MENUITEM id = "MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_SHADING_ENABLE" str = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_SHADING_ENABLE"/>
        <MENUITEM id = "MENU_ID_EM_DEV_CAM_AF_CONTSHOT_SETTING_SHADING_DISABLE" str = "STR_ID_EM_DEV_CAM_AF_CONTSHOT_SHADING_DISABLE"/>    
    </MENU> 
    
    <MENU id="MENU_ID_EM_DEV_CAM_AF_CONTSHOT_STORAGE_0"></MENU>
    <MENU id="MENU_ID_EM_DEV_CAM_AF_CONTSHOT_STORAGE_1"></MENU>
    <MENU id="MENU_ID_EM_DEV_CAM_AF_CONTSHOT_STORAGE_2"></MENU>
    <MENU id="MENU_ID_EM_DEV_CAM_AF_CONTSHOT_STORAGE_3"></MENU>
    <MENU id="MENU_ID_EM_DEV_CAM_AF_CONTSHOT_STORAGE_4"></MENU>
    <MENU id="MENU_ID_EM_DEV_CAM_AF_CONTSHOT_STORAGE_5"></MENU>
#endif /* __MMI_EM_CAM_AF_CONTSHOT__ */    
<!----------------- EM Item End ----------------------------------------------->




<!----------------- Device | Mini GPS ----------------------------------------->
#if defined(__GPS_SUPPORT__)

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_DEV_MINI_GPS">GPS</STRING>                              <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_MINI_GPS_MINIGPS">MiniGPS</STRING>                              <!-- Engineer Mode Menu Caption String -->
#if defined(__AGPS_USER_PLANE__)||defined(__AGPS_CONTROL_PLANE__)
    <STRING id = "STR_ID_EM_DEV_MINI_GPS_RESET_AGPS">Reset AGPS data</STRING>                              <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_MINI_GPS_AUTO_RESET_AGPS">Auto reset AGPS data</STRING>							   <!-- Engineer Mode Menu Caption String -->
#endif
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_FACTORY_RESET">GPS factory reset</STRING>								<!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_GPS_EM_SHORTCUT">GPS EM shortcut</STRING>                              <!-- Engineer Mode Menu Caption String -->
#if defined(__AGPS_USER_PLANE__)||defined(__AGPS_CONTROL_PLANE__)	
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_MOLR_SETTING">MOLR settings</STRING>							   <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_MOLR_SETTING_POS_TYPE">MOLR position type</STRING>                              <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_MINI_GPS_MOLR_SETTING_POS_TYPE_UP">UP</STRING>                              <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_MINI_GPS_MOLR_SETTING_POS_TYPE_CP">CP</STRING>                              <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_MINI_GPS_MOLR_SETTING_POS_TYPE_GPS">GPS only</STRING>                              <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_MINI_GPS_QOP_SETTING_POS_TYPE_CP">CP</STRING> 
    <STRING id = "STR_ID_EM_DEV_MINI_GPS_QOP_HOR_ACCU_VAL">H-accuracy value [1~254]</STRING>                              <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_MINI_GPS_QOP_VER_ACCU">V-accuracy</STRING>                             <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_MINI_GPS_QOP_VER_ACCU_VAL">V-accuracy value [1~254]</STRING>                              <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_MINI_GPS_QOP_MAX_LOC_AGE">Max loc age</STRING>                              <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_MINI_GPS_QOP_MAX_LOC_AGE_VAL">Max loc age value [1~65534]</STRING>                              <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_MINI_GPS_QOP_RSP_TIME">AGPS rsp time</STRING>                              <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_MINI_GPS_QOP_RSP_TIME_VAL">AGPS rsp time value</STRING>                              <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_MINI_GPS_RSP_TIME_0">1</STRING> 
    <STRING id = "STR_ID_EM_DEV_MINI_GPS_RSP_TIME_1">2</STRING>                              <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_MINI_GPS_RSP_TIME_2">4</STRING>                             <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_MINI_GPS_RSP_TIME_3">8</STRING>                              <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_MINI_GPS_RSP_TIME_4">16</STRING>                              <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_MINI_GPS_RSP_TIME_5">32</STRING>                              <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_MINI_GPS_RSP_TIME_6">64</STRING>                              <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_MINI_GPS_RSP_TIME_7">128</STRING>                              <!-- Engineer Mode Menu Caption String -->

#endif
#ifdef __AGPS_USER_PLANE__
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_UP_SETTING">UP EM settings</STRING>							  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_UP_SETTING_PAYLOAD">Payload capability</STRING>                              <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_UP_SETTING_PAYLOAD_RRC">RRC</STRING>                              <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_UP_SETTING_PAYLOAD_RRLP">RRLP</STRING>                              <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_UP_SETTING_PAYLOAD_BOTH">BOTH</STRING>                              <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_UP_SETTING_MOLR_PREF">MOLR prefer mode</STRING>							  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_UP_SETTING_MOLR_PREF_MB">MB preferred</STRING>							  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_UP_SETTING_MOLR_PREF_MA">MA preferred</STRING>							  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_UP_SETTING_MOLR_PREF_MB_ONLY">MB only</STRING>							  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_UP_SETTING_MOLR_PREF_MA_ONLY">MA only</STRING>							  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_UP_SETTING_MOLR_PREF_NONE">No preferred</STRING>							  <!-- Engineer Mode Menu Caption String -->	
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_UP_SETTING_SOC_CONN">Socket connection</STRING>							  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_UP_SETTING_SUPL_TLS_SETTING">SUPL TLS setting</STRING>							  <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_MINI_GPS_UP_SETTING_SUPL_NOTIFY">SUPL Notify Timer [1~65534]</STRING>							  <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_MINI_GPS_UP_SETTING_SUPL_UT_TIMER">SUPL UT Timer [1~254]</STRING>							  <!-- Engineer Mode Menu Caption String -->
#endif
#ifdef __AGPS_CONTROL_PLANE__
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_CP_SETTING">CP EM settings</STRING>                              <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_CP_SETTING_MOLR">MOLR type</STRING>							  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_CP_SETTING_MOLR_LOC_EST">LocationEstimate</STRING>							  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_CP_SETTING_MOLR_ASS_DATA">AssistanceData</STRING>							  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_CP_SETTING_LOC_METHOD">Location method</STRING>							  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_CP_SETTING_LOC_METHOD_NONE">None</STRING> 						  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_CP_SETTING_LOC_METHOD_AGPS">AssistedGPS</STRING>							  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_CP_SETTING_LOC_METHOD_MB_EOTD">msBasedEOTD</STRING> 						  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_CP_SETTING_LOC_METHOD_MA_EOTD">msAssistedEOTD</STRING>							  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_CP_SETTING_LOC_METHOD_MB_OTDOA">msBasedOTDOA</STRING>						  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_CP_SETTING_EADDR">External address</STRING> 						  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_CP_SETTING_EADDR_VALUE">External address value</STRING> 						  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_CP_SETTING_MLC">MLC number</STRING>						  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_CP_SETTING_MLC_VALUE">MLC number value</STRING>						  <!-- Engineer Mode Menu Caption String -->
#endif
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_MINI_SKY_CHART">Sky Chart</STRING>						  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_MINI_STATUS">Status</STRING>						  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_MINI_NMEA">NMEA</STRING>						  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_MINI_SETTING">Setting</STRING>						  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_MINI_TTFF">TTFF</STRING>						  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_MINI_MA_STATUS">MA Status</STRING>						  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_MINI_SETTING_CATCHER">Logging - Catcher</STRING>						  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_MINI_SETTING_FILE_DUMP">Logging - File Dump</STRING>						  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_MINI_SETTING_PC_TOOL">Logging - PC Tool</STRING>						  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_MINI_SETTING_DUBG_MSG">Debug Message</STRING>						  <!-- Engineer Mode Menu Caption String -->
//#ifdef __BEE_SUPPORT__
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_MINI_SETTING_BEE_SWITCH">HotStill Switch</STRING>						  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_MINI_SETTING_BEE_DEBUG">HotStill Debug</STRING>						  <!-- Engineer Mode Menu Caption String -->
/*	<STRING id = "STR_ID_EM_DEV_MINI_GPS_MINI_SETTING_BEE_DEBUG_DISABLE">Disable</STRING>						  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_MINI_SETTING_BEE_DEBUG_FILE">File log</STRING>						  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_MINI_SETTING_BEE_DEBUG_CATCHER">Catcher log</STRING>						  <!-- Engineer Mode Menu Caption String -->*/
//#endif __BEE_SUPPORT__
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_MINI_TTFF_HOT">Hot Start</STRING>						  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_MINI_TTFF_WARM">Warm Start</STRING>						  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_MINI_TTFF_COLD">Cold Start</STRING>						  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_MINI_POWER_SAVING">GPS power saving mode</STRING>						  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_MINI_SLEEP_MODE">Sleep Mode</STRING>						  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_MINI_WAKE_MODE">Wake Mode</STRING>						  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_MINI_STOP_MODE">Stop Mode</STRING>						  <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_DEV_MINI_GPS_AGPS_IS_ON">AGPS setting is on</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_DEV_MINI_GPS" type = "APP_SUB" str = "STR_ID_EM_DEV_MINI_GPS">
		<MENUITEM_ID>MENU_ID_EM_DEV_MINI_GPS_MINIGPS</MENUITEM_ID>
	#if defined(__AGPS_USER_PLANE__)||defined(__AGPS_CONTROL_PLANE__)
		<MENUITEM_ID>MENU_ID_EM_DEV_MINI_GPS_MOLR_SETTING</MENUITEM_ID>
	#endif
	#ifdef __AGPS_CONTROL_PLANE__
		<MENUITEM_ID>MENU_ID_EM_DEV_MINI_GPS_CP_SETTING</MENUITEM_ID>
	#endif
	#ifdef __AGPS_USER_PLANE__
		<MENUITEM_ID>MENU_ID_EM_DEV_MINI_GPS_UP_SETTING</MENUITEM_ID>
	#endif
    #if defined(__AGPS_USER_PLANE__)||defined(__AGPS_CONTROL_PLANE__)
		<MENUITEM_ID>MENU_ID_EM_DEV_MINI_GPS_RESET_AGPS</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_EM_DEV_MINI_GPS_AUTO_RESET_AGPS</MENUITEM_ID>
    #endif
		<MENUITEM_ID>MENU_ID_EM_DEV_MINI_GPS_FACTORY_RESET</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_EM_DEV_MINI_GPS_GPS_EM_SHORTCUT</MENUITEM_ID>
	</MENU>

		<MENUITEM id = "MENU_ID_EM_DEV_MINI_GPS_MINI_SKY_CHART" str = "STR_ID_EM_DEV_MINI_GPS_MINI_SKY_CHART"/>
		<MENUITEM id = "MENU_ID_EM_DEV_MINI_GPS_MINI_STATUS" str = "STR_ID_EM_DEV_MINI_GPS_MINI_STATUS"/>
		<MENUITEM id = "MENU_ID_EM_DEV_MINI_GPS_MINI_NMEA" str = "STR_ID_EM_DEV_MINI_GPS_MINI_NMEA"/>
		<MENUITEM id = "MENU_ID_EM_DEV_MINI_GPS_MINI_SETTING" str = "STR_ID_EM_DEV_MINI_GPS_MINI_SETTING"/>
		<MENUITEM id = "MENU_ID_EM_DEV_MINI_GPS_MINI_MA_STATUS" str = "STR_ID_EM_DEV_MINI_GPS_MINI_MA_STATUS"/>
	<MENU id = "MENU_ID_EM_DEV_MINI_GPS_MINIGPS" type = "APP_SUB" str = "STR_ID_EM_DEV_MINI_GPS_MINIGPS">
		<MENUITEM_ID>MENU_ID_EM_DEV_MINI_GPS_MINI_SKY_CHART</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_EM_DEV_MINI_GPS_MINI_STATUS</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_EM_DEV_MINI_GPS_MINI_NMEA</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_EM_DEV_MINI_GPS_MINI_SETTING</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_EM_DEV_MINI_GPS_MINI_TTFF</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_EM_DEV_MINI_GPS_MINI_MA_STATUS</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_EM_DEV_MINI_GPS_MINI_POWER_SAVING</MENUITEM_ID>
    </MENU>

    <MENU id = "MENU_ID_EM_DEV_MINI_GPS_MINI_TTFF" type = "APP_SUB" str = "STR_ID_EM_DEV_MINI_GPS_MINI_TTFF">
		<MENUITEM id = "MENU_ID_EM_DEV_MINI_GPS_MINI_TTFF_HOT_START" str = "STR_ID_EM_DEV_MINI_GPS_MINI_TTFF_HOT"/>
		<MENUITEM id = "MENU_ID_EM_DEV_MINI_GPS_MINI_TTFF_WARM_START" str = "STR_ID_EM_DEV_MINI_GPS_MINI_TTFF_WARM"/>
		<MENUITEM id = "MENU_ID_EM_DEV_MINI_GPS_MINI_TTFF_COLD_START" str = "STR_ID_EM_DEV_MINI_GPS_MINI_TTFF_COLD"/>
    </MENU>
    
	<MENU id = "MENU_ID_EM_DEV_MINI_GPS_MINI_POWER_SAVING" type = "APP_SUB" str = "STR_ID_EM_DEV_MINI_GPS_MINI_POWER_SAVING">
		<MENUITEM id = "MENU_ID_EM_DEV_MINI_GPS_MINI_SLEEP_MODE" str = "STR_ID_EM_DEV_MINI_GPS_MINI_SLEEP_MODE"/>
		<MENUITEM id = "MENU_ID_EM_DEV_MINI_GPS_MINI_WAKE_MODE" str = "STR_ID_EM_DEV_MINI_GPS_MINI_WAKE_MODE"/>
		<MENUITEM id = "MENU_ID_EM_DEV_MINI_GPS_MINI_STOP_MODE" str = "STR_ID_EM_DEV_MINI_GPS_MINI_STOP_MODE"/>
	</MENU>
#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)    
	<MENU id = "MENU_ID_EM_DEV_MINI_GPS_MOLR_SETTING" type = "APP_SUB" str = "STR_ID_EM_DEV_MINI_GPS_MOLR_SETTING">
    </MENU>
#endif	
#ifdef __AGPS_CONTROL_PLANE__
	<MENU id = "MENU_ID_EM_DEV_MINI_GPS_CP_SETTING" type = "APP_SUB" str = "STR_ID_EM_DEV_MINI_GPS_CP_SETTING">
	</MENU>
#endif
#if defined(__AGPS_USER_PLANE__)	
	<MENU id = "MENU_ID_EM_DEV_MINI_GPS_UP_SETTING" type = "APP_SUB" str = "STR_ID_EM_DEV_MINI_GPS_UP_SETTING">
	</MENU>
#endif	

#if defined(__AGPS_USER_PLANE__)||defined(__AGPS_CONTROL_PLANE__)
    <MENUITEM id = "MENU_ID_EM_DEV_MINI_GPS_RESET_AGPS" str = "STR_ID_EM_DEV_MINI_GPS_RESET_AGPS"/>
    <MENU id = "MENU_ID_EM_DEV_MINI_GPS_AUTO_RESET_AGPS" str = "STR_ID_EM_DEV_MINI_GPS_AUTO_RESET_AGPS" flag = "RADIO">
        <MENUITEM id = "MENU_ID_EM_DEV_MINI_GPS_AUTO_RESET_AGPS_ON" str = "STR_GLOBAL_ON"/>
        <MENUITEM id = "MENU_ID_EM_DEV_MINI_GPS_AUTO_RESET_AGPS_OFF" str = "STR_GLOBAL_OFF"/>
    </MENU>
#endif
    <MENUITEM id = "MENU_ID_EM_DEV_MINI_GPS_FACTORY_RESET" str = "STR_ID_EM_DEV_MINI_GPS_FACTORY_RESET"/>
    <MENU id = "MENU_ID_EM_DEV_MINI_GPS_GPS_EM_SHORTCUT" type = "APP_SUB" str = "STR_ID_EM_DEV_MINI_GPS_GPS_EM_SHORTCUT" flag = "RADIO">
        <MENUITEM id = "MENU_ID_EM_DEV_MINI_GPS_GPS_EM_SHORTCUT_ON" str = "STR_GLOBAL_ON"/>
        <MENUITEM id = "MENU_ID_EM_DEV_MINI_GPS_GPS_EM_SHORTCUT_OFF" str = "STR_GLOBAL_OFF"/>
    </MENU>
	<!----------------- Screen Id ------------------------------------------->			 
	  <SCREEN id = "SCR_ID_EM_DEV_MINIGPS_MAIN"/>
	  <SCREEN id = "SCR_ID_EM_DEV_MINIGPS_SKY_CHART"/>
	  <SCREEN id = "SCR_ID_EM_DEV_MINIGPS_STATUS"/>
	  <SCREEN id = "SCR_ID_EM_DEV_MINIGPS_NMEA"/>	  
	  <SCREEN id = "SCR_ID_EM_DEV_MINIGPS_SETTING"/>
	  <SCREEN id = "SCR_ID_EM_DEV_MINIGPS_TTFF"/>
	  <SCREEN id = "SCR_ID_EM_DEV_MINIGPS_MA_STATUS"/>
    
#endif /* __GPS_SUPPORT__  */    
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Device | Motion ------------------------------------------->
#ifdef __MMI_EM_MOTION_APP__

   <!--------------------------SCR Id--------------------------------------------->
   <SCREEN id="SCR_ID_EM_MOTION_APP_SHOW"/>

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_DEV_MOTION">Motion</STRING>                             <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_MOTION_TILT_NORMAL">Tilt normal detect</STRING>

#ifdef __MTK_INTERNAL__
    <STRING id = "STR_ID_EM_DEV_MOTION_TILT_DETAIL">Draw detail detect</STRING>
    <STRING id = "STR_ID_EM_DEV_MOTION_SET_DIRECT_SEN">Direct sensitive</STRING>
#endif /*__MTK_INTERNAL__*/

    <STRING id = "STR_ID_EM_DEV_MOTION_SHAKE">Shake detect</STRING>
    <STRING id = "STR_ID_EM_DEV_MOTION_SEN_HIGH">Sensitive high</STRING>
    <STRING id = "STR_ID_EM_DEV_MOTION_SEN_NORMAL">Sensitive normal</STRING>
    <STRING id = "STR_ID_EM_DEV_MOTION_SEN_LOW">Sensitive low</STRING>


    <STRING id = "STR_ID_EM_DEV_MOTION_DRAW_DETAIL">Draw tilt detail</STRING>
    <STRING id = "STR_ID_EM_DEV_MOTION_DRAW_DETAIL_FILTER_NOISE">Draw tilt detail(filter noise)</STRING>
    
    <STRING id = "STR_ID_EM_DEV_MOTION_ADVANCED_SHAKE">Advanced shake test</STRING>
    <STRING id = "STR_ID_EM_DEV_MOTION_TURNOVER">Turnover test</STRING>
    <STRING id = "STR_ID_EM_DEV_MOTION_TAP">Tap test</STRING>
    <STRING id = "STR_ID_EM_DEV_MOTION_DOUBLE_TAP">Double tap test</STRING>
    <STRING id = "STR_ID_EM_DEV_MOTION_DROP">Drop test</STRING>
    <STRING id = "STR_ID_EM_DEV_MOTION_STEP">Step test</STRING>
    <STRING id = "STR_ID_EM_MOTION_SET_TAP_PLUS">Tap plus(hex)</STRING>
    <STRING id = "STR_ID_EM_MOTION_SET_TAP_THRESHOLD">Tap threshold(hex)</STRING>
    <STRING id = "STR_ID_EM_DEV_MOTION_SET_TAP_PARA">Set tap para</STRING>
	<STRING id = "STR_ID_EM_DEV_MOTION_SET_FLIP_PARA">Set flip para</STRING>`
	<STRING id = "STR_ID_EM_DEV_MOTION_OUT_OF_RANGE">Out of range</STRING>

    <STRING id = "STR_ID_EM_MOTION_SET_FLIP_ENABLE">Set flip enable(1/0)</STRING>
	<STRING id = "STR_ID_EM_MOTION_SET_FLIP_FILTER">Set flip filter</STRING>
	<STRING id = "STR_ID_EM_MOTION_SET_FLIP_THRESHOLD">Set flip threshold</STRING>
	<STRING id = "STR_ID_EM_MOTION_SET_FLIP_DEBOUNCE">Set flip debounce</STRING>
	<STRING id = "STR_ID_EM_MOTION_SET_FLIP_INTERVAL">Set flip interval</STRING>



    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_DEV_MOTION" type = "APP_SUB" str = "STR_ID_EM_DEV_MOTION">
    </MENU>

    <MENU id = "MENU_ID_EM_DEV_MOTION_APP_MAIN" type = "APP_MAIN" str = "STR_ID_EM_DEV_MOTION">
    	<MENUITEM id = "MENU_ID_EM_DEV_MOTION_TILT_NORMAL" str = "STR_ID_EM_DEV_MOTION_TILT_NORMAL"/>
    	 <MENUITEM_ID>MENU_ID_EM_DEV_MOTION_SHAKE</MENUITEM_ID>
    

#ifdef __MTK_INTERNAL__

    	<MENUITEM id = "MENU_ID_EM_DEV_MOTION_TILT_DETAIL" str = "STR_ID_EM_DEV_MOTION_TILT_DETAIL"/>
		/*
    	<MENUITEM id = "MENU_ID_EM_DEV_MOTION_SHAKE" str = "STR_ID_EM_DEV_MOTION_SHAKE"/>
    	<MENUITEM id = "MENU_ID_EM_DEV_MOTION_SEN_HIGH" str = "STR_ID_EM_DEV_MOTION_SEN_HIGH"/>
    	<MENUITEM id = "MENU_ID_EM_DEV_MOTION_SEN_NORMAL" str = "STR_ID_EM_DEV_MOTION_SEN_NORMAL"/>
    	<MENUITEM id = "MENU_ID_EM_DEV_MOTION_SEN_LOW" str = "STR_ID_EM_DEV_MOTION_SEN_LOW"/>
		*/
    	<MENUITEM id = "MENU_ID_EM_DEV_MOTION_SET_DIRECT_SEN" str = "STR_ID_EM_DEV_MOTION_SET_DIRECT_SEN"/>
#endif /*__MTK_INTERNAL__*/

    	<MENUITEM id = "MENU_ID_EM_DEV_MOTION_DRAW_DETAIL" str = "STR_ID_EM_DEV_MOTION_DRAW_DETAIL"/>

		<MENUITEM id = "MENU_ID_EM_DEV_MOTION_DRAW_DETAIL_FILTER_NOISE" str = "STR_ID_EM_DEV_MOTION_DRAW_DETAIL_FILTER_NOISE"/>


    	<MENUITEM id = "MENU_ID_EM_DEV_MOTION_ADVANCED_SHAKE" str = "STR_ID_EM_DEV_MOTION_ADVANCED_SHAKE"/>
    	<MENUITEM id = "MENU_ID_EM_DEV_MOTION_TURNOVER" str = "STR_ID_EM_DEV_MOTION_TURNOVER"/>

  #ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
    	<MENUITEM id = "MENU_ID_EM_DEV_MOTION_TAP" str = "STR_ID_EM_DEV_MOTION_TAP"/>
    	<MENUITEM id = "MENU_ID_EM_DEV_MOTION_DOUBLE_TAP" str = "STR_ID_EM_DEV_MOTION_DOUBLE_TAP"/>
    	<MENUITEM id = "MENU_ID_EM_DEV_MOTION_DROP" str = "STR_ID_EM_DEV_MOTION_DROP"/>
    	//<MENUITEM id = "MENU_ID_EM_DEV_MOTION_STEP" str = "STR_ID_EM_DEV_MOTION_STEP"/>
    	<MENUITEM_ID>MENU_ID_EM_DEV_MOTION_STEP</MENUITEM_ID>
    	<MENUITEM id = "MENU_ID_EM_DEV_MOTION_SET_TAP_PARA" str = "STR_ID_EM_DEV_MOTION_SET_TAP_PARA"/>
 #endif /*__MOTION_SENSOR_ADVANCED_GESTURE__*/
		
    	<MENUITEM id = "MENU_ID_EM_DEV_MOTION_SET_FLIP_PARA" str = "STR_ID_EM_DEV_MOTION_SET_FLIP_PARA"/>
    </MENU>
    

 	/* shake sub menu */
 	 <MENU id = "MENU_ID_EM_DEV_MOTION_SHAKE" type = "APP_MAIN" str = "STR_ID_EM_DEV_MOTION_SHAKE">
  		 <MENUITEM id = "MENU_ID_EM_DEV_MOTION_SEN_HIGH" str = "STR_ID_EM_DEV_MOTION_SEN_HIGH"/>
		 <MENUITEM id = "MENU_ID_EM_DEV_MOTION_SEN_NORMAL" str = "STR_ID_EM_DEV_MOTION_SEN_NORMAL"/>
		 <MENUITEM id = "MENU_ID_EM_DEV_MOTION_SEN_LOW" str = "STR_ID_EM_DEV_MOTION_SEN_LOW"/>
 	 </MENU>
    

     /* Step sub menu */
     <MENU id = "MENU_ID_EM_DEV_MOTION_STEP" type = "APP_MAIN" str = "STR_ID_EM_DEV_MOTION_STEP">
  		 <MENUITEM id = "MENU_ID_EM_DEV_MOTION_STEP_SEN_HIGH" str = "STR_ID_EM_DEV_MOTION_SEN_HIGH"/>
		 <MENUITEM id = "MENU_ID_EM_DEV_MOTION_STEP_SEN_NORMAL" str = "STR_ID_EM_DEV_MOTION_SEN_NORMAL"/>
		 <MENUITEM id = "MENU_ID_EM_DEV_MOTION_STEP_SEN_LOW" str = "STR_ID_EM_DEV_MOTION_SEN_LOW"/>
 	 </MENU>
     
    
#endif /* __MMI_EM_MOTION_APP__ */    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Device | Speed lcd ------------------------------------>
#ifdef __MMI_EM_DEV_SPEECH_LCD__
    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id = "SCR_ID_EM_DEV_SPEECH_LCD"/>
    <SCREEN id = "SCR_ID_EM_AUD_SIDE_TONE"/>

    <!----------------- String Id -----------------------------------------> 
    <STRING id = "STR_ID_EM_DEV_SPEECH_LCD">Speech LCD interface test</STRING>

    <!----------------- Menu Id ------------------------------------------->
    <MENUITEM id = "MENU_ID_EM_DEV_SPEECH_LCD" str = "STR_ID_EM_DEV_SPEECH_LCD"/>
#endif /* __MMI_EM_DEV_SPEECH_LCD__ */     
<!----------------- Speech lcd End ---------------------------------------->

<!----------------- Device | PMU register setting ------------------------->
#ifdef __MMI_EM_DEV_PMU_REGISTER_SETTING__
    <!----------------- Screen Id ----------------------------------------->

    <!----------------- String Id -----------------------------------------> 
    <STRING id = "STR_ID_EM_DEV_PMU_REG_SET">PMU register setting</STRING>
    <STRING id = "STR_ID_EM_DEV_PMU_REG_SET_WRITE">Write</STRING>
    <STRING id = "STR_ID_EM_DEV_PMU_REG_SET_Addr">Address(Hex)</STRING>
    <STRING id = "STR_ID_EM_DEV_PMU_REG_SET_VALUE">Value(Hex)</STRING>
    <STRING id = "STR_ID_EM_DEV_PMU_REG_SET_HIGH_LOW">High\low bit(in order)</STRING>

    <!----------------- Menu Id ------------------------------------------->
    <MENUITEM id = "MENU_ID_EM_DEV_PMU_REG_SET" str = "STR_ID_EM_DEV_PMU_REG_SET"/>
#endif /* __MMI_EM_DEV_PMU_REGISTER_SETTING__ */
<!----------------- Speech lcd End ---------------------------------------->

<!----------------- Device | PXS sensor ------------------------------------------->
#ifdef __MMI_EM_DEV_PXS_SENSOR__

   <!----------------- Screen Id ----------------------------------------->
   <SCREEN id = "SCR_ID_EM_PXS_RAW_DATA"/>

   <!--------------------------STR Id--------------------------------------------->
   <STRING id = "STR_ID_EM_DEV_PXS">Proximity Sensor</STRING>  
   <STRING id = "STR_ID_EM_DEV_PXS_RAW_DATA">Raw Data</STRING> 
   <STRING id = "STR_ID_EM_DEV_PXS_OBJ_STATUS">Object Status</STRING> 
   <STRING id = "STR_ID_EM_DEV_PXS_READ_WRITE_PARA">R/W Parameters</STRING> 

   <STRING id = "STR_ID_EM_DEV_PXS_CAPTION_P1">P1:</STRING> 
   <STRING id = "STR_ID_EM_DEV_PXS_CAPTION_P2">P2:</STRING> 
   <STRING id = "STR_ID_EM_DEV_PXS_CAPTION_P3">P3:</STRING> 
   <STRING id = "STR_ID_EM_DEV_PXS_CAPTION_P4">P4:</STRING> 
   <STRING id = "STR_ID_EM_DEV_PXS_CAPTION_P5">P5:</STRING> 
   <STRING id = "STR_ID_EM_DEV_PXS_CAPTION_P6">P6:</STRING> 
   <STRING id = "STR_ID_EM_DEV_PXS_CAPTION_P7">P7:</STRING> 
   <STRING id = "STR_ID_EM_DEV_PXS_CAPTION_P8">P8:</STRING> 
     
   <!--------------------------MENU Id--------------------------------------------->
   <MENU id = "MENU_ID_EM_DEV_PXS" type = "APP_SUB" str = "STR_ID_EM_DEV_PXS">
   </MENU>

   <MENU id = "MENU_ID_EM_DEV_PXS_MAIN" type = "APP_SUB" str = "STR_ID_EM_DEV_PXS">
       <MENUITEM_ID>MENU_ID_EM_DEV_PXS_RAW_DATA</MENUITEM_ID>
       <MENUITEM_ID>MENU_ID_EM_DEV_PXS_OBJ_STATUS</MENUITEM_ID>
       <MENUITEM_ID>MENU_ID_EM_DEV_PXS_READ_WRITE_PARA</MENUITEM_ID>    
   </MENU>
   
   <MENUITEM id = "MENU_ID_EM_DEV_PXS_RAW_DATA" str = "STR_ID_EM_DEV_PXS_RAW_DATA"/>
   <MENUITEM id = "MENU_ID_EM_DEV_PXS_OBJ_STATUS" str = "STR_ID_EM_DEV_PXS_OBJ_STATUS"/>
   <MENUITEM id = "MENU_ID_EM_DEV_PXS_READ_WRITE_PARA" str = "STR_ID_EM_DEV_PXS_READ_WRITE_PARA"/>


    <TIMER id = "PXS_SENSOR_GET_RAW_DATA_TIMER"/>
#endif /*__MMI_EM_DEV_PXS_SENSOR__*/ 

<!----------------- EM Item End ----------------------------------------------->



<!----------------- Device | WLAN EAP Mode ------------------------------------>

#ifdef __MMI_EM_DEV_WLAN_EAP_MODE__

    <!----------------- Screen Id ----------------------------------------->

    <!----------------- String Id -----------------------------------------> 
    <STRING id = "STR_ID_EM_DEV_WLAN_SETTING">WLAN setting</STRING>
    <STRING id = "STR_ID_EM_DEV_SET_WLAN_EAP_MODE">EAP mode</STRING>
    <STRING id = "STR_ID_EM_DEV_WLAN_EAP_MODE_SIMULATION">Milenage simulation</STRING>
    <STRING id = "STR_ID_EM_DEV_WLAN_EAP_MODE_REAL_NETWORK">Real network</STRING>

    <!----------------- Menu Id ------------------------------------------->
    <MENUITEM id = "MENU_ID_EM_DEV_WLAN_EAP_MODE_SIMULATION" str = "STR_ID_EM_DEV_WLAN_EAP_MODE_SIMULATION"/>
    <MENUITEM id = "MENU_ID_EM_DEV_WLAN_EAP_MODE_REAL_NETWORK" str = "STR_ID_EM_DEV_WLAN_EAP_MODE_REAL_NETWORK"/>
    
    <MENU id = "MENU_ID_EM_DEV_SET_WLAN_EAP_MODE" type = "APP_SUB" str = "STR_ID_EM_DEV_SET_WLAN_EAP_MODE">
       <MENUITEM_ID>MENU_ID_EM_DEV_WLAN_EAP_MODE_SIMULATION</MENUITEM_ID>
       <MENUITEM_ID>MENU_ID_EM_DEV_WLAN_EAP_MODE_REAL_NETWORK</MENUITEM_ID>
    </MENU>

    <MENU id = "MENU_ID_EM_DEV_WLAN_SETTING" type = "APP_SUB" str = "STR_ID_EM_DEV_WLAN_SETTING">
       <MENUITEM_ID>MENU_ID_EM_DEV_SET_WLAN_EAP_MODE</MENUITEM_ID>
    </MENU>
    
#endif /* __MMI_EM_DEV_WLAN_EAP_MODE__ */

<!------------------------- Switch End ---------------------------------------->


<!----------------- Device | NFC ----------------------------------------->
#ifdef __MMI_EM_NFC_SUPPORT__
    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id = "SCR_ID_EM_NFC"/>
    <SCREEN id = "GRP_ID_EM_NFC"/>
    <SCREEN id = "SCR_ID_MMI_EM_NFC_START_PROGRESS"/>
    <SCREEN id = "SCR_ID_MMI_EM_NFC_STOP_PROGRESS"/>
    <SCREEN id = "SCR_ID_MMI_EM_NFC_TAG_DET_INFO"/>
    <SCREEN id = "SCR_ID_MMI_EM_NFC_P2P_INFO"/>
    <SCREEN id = "SCR_ID_MMI_EM_NFC_SHOW_TEXT"/>
    
    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_EM_NFC">NFC</STRING>
    <STRING id = "STR_ID_EM_NFC_SETTING">Setting</STRING>
    <STRING id = "STR_ID_EM_NFC_SW_STACK">Software stack</STRING>
       
    <STRING id = "STR_ID_EM_NFC_FEATURE">Feature</STRING>
    <STRING id = "STR_ID_EM_NFC_DEBUG">Debug</STRING>
    <STRING id = "STR_ID_EM_NFC_SW_PROTOCOL_SWITCH">SW protocol Switch</STRING>
    <STRING id = "STR_ID_EM_NFC_SW_PROTOCOL_RAW_DATA">HW test</STRING>
    <STRING id = "STR_ID_EM_NFC_SW_PROTOCAL_SW_STACK">SW stack</STRING>
        
    <STRING id = "STR_ID_EM_NFC_SW_STACK_REG_NOTIFICATION">Register notification</STRING>
    <STRING id = "STR_ID_EM_NFC_SW_STACK_DISCOVERY_NOTIFICATION">Discovery notification</STRING>
    
    <STRING id = "STR_ID_EM_NFC_STR_MIFAREUL">MifareUL</STRING>
    <STRING id = "STR_ID_EM_NFC_STR_MIFARESTD">MifareStd</STRING>
    <STRING id = "STR_ID_EM_NFC_STR_ISO14434A">ISO1443_4A</STRING>
    <STRING id = "STR_ID_EM_NFC_STR_ISO14434B">ISO1443_4B</STRING>
    <STRING id = "STR_ID_EM_NFC_STR_JEWEL">Jewel</STRING>
    <STRING id = "STR_ID_EM_NFC_STR_FELICA">Felica</STRING>
    <STRING id = "STR_ID_EM_NFC_STR_ISO15693">ISO15693</STRING>
    <STRING id = "STR_ID_EM_NFC_STR_NDEF">NDEF</STRING>
    
    <STRING id = "STR_ID_EM_NFC_DIS_NOTIFY_BITMAP_0">ISO14443A</STRING>
    <STRING id = "STR_ID_EM_NFC_DIS_NOTIFY_BITMAP_1">ISO14443B</STRING>
    <STRING id = "STR_ID_EM_NFC_DIS_NOTIFY_BITMAP_2">Felica 212</STRING>
    <STRING id = "STR_ID_EM_NFC_DIS_NOTIFY_BITMAP_3">Felica 424</STRING>
    <STRING id = "STR_ID_EM_NFC_DIS_NOTIFY_BITMAP_5">NFC Active</STRING>
    <STRING id = "STR_ID_EM_NFC_DIS_NOTIFY_BITMAP_6">Discard card emulation</STRING>
    <STRING id = "STR_ID_EM_NFC_DIS_NOTIFY_BITMAP_7">Disable p2p ip target</STRING>
    
    <STRING id = "STR_ID_EM_NFC_SE">Secure element</STRING>
    <STRING id = "STR_ID_EM_NFC_SE_VIRTUAL">Virtual</STRING>
    <STRING id = "STR_ID_EM_NFC_SE_WIRED">Wired</STRING>
    <STRING id = "STR_ID_EM_NFC_SE_BITMAP_0">Start of transaction</STRING>
    <STRING id = "STR_ID_EM_NFC_SE_BITMAP_1">End of transaction</STRING>
    <STRING id = "STR_ID_EM_NFC_SE_BITMAP_2">Transaction</STRING>
    <STRING id = "STR_ID_EM_NFC_SE_BITMAP_3">RF field on</STRING>
    <STRING id = "STR_ID_EM_NFC_SE_BITMAP_4">RF filed off</STRING>
    <STRING id = "STR_ID_EM_NFC_SE_BITMAP_5">Connectivity</STRING>
    
    <STRING id = "STR_ID_EM_NFC_CARD_TYPE_1">Mifare classic 1K</STRING>
    <STRING id = "STR_ID_EM_NFC_CARD_TYPE_2">Mifare classic 4K</STRING>
    <STRING id = "STR_ID_EM_NFC_TAG_DET">Tag Detected</STRING>
    <STRING id = "STR_ID_EM_NFC_P2P">P2P</STRING>    
    
    <STRING id = "STR_ID_EM_NFC_RD_PARAM_SETTING">Reader Param setting</STRING>
    <STRING id = "STR_ID_EM_NFC_CARD_PARAM_SETTING">Card param setting</STRING>
    <STRING id = "STR_ID_EM_NFC_P2P_PARAM_SETTING">P2P param setting</STRING>
    
    <STRING id = "STR_ID_EM_NFC_RD_TECHNOLOGY">Technology</STRING>
    <STRING id = "STR_ID_EM_NFC_RD_PROTOCOL">Protocols</STRING>
    <STRING id = "STR_ID_EM_NFC_RD_TX_ON_WITH_ASK">TX on with ask</STRING>
    <STRING id = "STR_ID_EM_NFC_RD_TX_ON_WO_ASK">TX on without ask</STRING>
    <STRING id = "STR_ID_EM_NFC_RD_CARD_EMU_MODE">Card emulation mode</STRING>
    <STRING id = "STR_ID_EM_NFC_RD_READER_MODE">Reader mode</STRING>
    <STRING id = "STR_ID_EM_NFC_RD_P2P_MODE">P2P mode</STRING>
    <STRING id = "STR_ID_EM_NFC_RD_ANTANNA_TEST">Antenna test</STRING>
    
    <STRING id = "STR_ID_EM_NFC_RD_P2P_PROTOCOL_NFC_ACTIVE">NFC active</STRING>
    <STRING id = "STR_ID_EM_NFC_RD_P2P_PROTOCOL_DISCARD_CARD">Discard card emulation</STRING>
    <STRING id = "STR_ID_EM_NFC_RD_P2P_PROTOCOL_DISABLE_IP_TARGET">Disable P2P IP target</STRING>

    <STRING id = "STR_ID_EM_NFC_RD_P2P_MODE_OPT">P2P option</STRING>
    <STRING id = "STR_ID_EM_NFC_RD_P2P_OPT_DEFAULT">Default</STRING>
    <STRING id = "STR_ID_EM_NFC_RD_P2P_OPT_P106">Passive106</STRING>
    <STRING id = "STR_ID_EM_NFC_RD_P2P_OPT_P212">Passive212</STRING>
    <STRING id = "STR_ID_EM_NFC_RD_P2P_OPT_P424">Passive424</STRING>
    <STRING id = "STR_ID_EM_NFC_RD_P2P_OPT_ACTIVE">Active</STRING>    
    <STRING id = "STR_ID_EM_NFC_RD_P2P_OPT_ALL">P2P all</STRING>
    
    <STRING id = "STR_ID_EM_NFC_MOD_TYPE">Modulation type</STRING>
    <STRING id = "STR_ID_EM_NFC_MOD_TYPE_A">A</STRING>
    <STRING id = "STR_ID_EM_NFC_MOD_TYPE_B">B</STRING>
    <STRING id = "STR_ID_EM_NFC_MOD_TYPE_F">F</STRING>
    <STRING id = "STR_ID_EM_NFC_BIT_RATE">Bit rate</STRING>
    <STRING id = "STR_ID_EM_NFC_BIT_RATE_106">106</STRING>
    <STRING id = "STR_ID_EM_NFC_BIT_RATE_212">212</STRING>
    <STRING id = "STR_ID_EM_NFC_BIT_RATE_424">424</STRING>
    <STRING id = "STR_ID_EM_NFC_BIT_RATE_848">848</STRING>
    
    <STRING id = "STR_ID_EM_NFC_TESTING">Testing</STRING>
    <STRING id = "STR_ID_EM_NFC_WRITE">Write</STRING>
    <STRING id = "STR_ID_EM_NFC_RECEIVE">Receive</STRING>
    <STRING id = "STR_ID_EM_NFC_F2NDEF">Format to NDEF</STRING>
    
    <STRING id = "STR_ID_EM_NFC_NDEF_RW_TAG_TYPE_URL">URL</STRING>
    <STRING id = "STR_ID_EM_NFC_NDEF_RW_TAG_TYPE_TEXT">Text</STRING>
    <STRING id = "STR_ID_EM_NFC_NDEF_RW_TAG_TYPE_SMART_POSTER">Smart Poster</STRING>
    <STRING id = "STR_ID_EM_NFC_NDEF_RW_TAG_TYPE">Type</STRING>
    <STRING id = "STR_ID_EM_NFC_NDEF_RW_TAG_DATA">Data</STRING>
    
    <STRING id = "STR_ID_EM_NFC_CARD_EMU_MODE_SE_TYPE_UICC">UICC</STRING>
    <STRING id = "STR_ID_EM_NFC_CARD_EMU_MODE_SE_TYPE_SMX">SMX</STRING>
    <STRING id = "STR_ID_EM_NFC_CARD_EMU_MODE_SE_TYPE_BOTH">Both</STRING>
    <STRING id = "STR_ID_EM_NFC_ANTENNA_TEST_PARAM_1">Param 1(0~255)</STRING>
    <STRING id = "STR_ID_EM_NFC_ANTENNA_TEST_PARAM_2">Param 2(0~255)</STRING>
    <STRING id = "STR_ID_EM_NFC_ANTENNA_TEST_PARAM_3">Param 3(0~255)</STRING>
    <STRING id = "STR_ID_EM_NFC_ANTENNA_TEST_PARAM_4">Param 4(0~255)</STRING>
    
    <STRING id = "STR_ID_EM_NFC_BG">BackGroud</STRING>
    <STRING id = "STR_ID_EM_NFC_SUCCESS">Success</STRING>
    <STRING id = "STR_ID_EM_NFC_FAIL">Fail</STRING>
    <STRING id = "STR_ID_EM_NFC_STOPING">Stoping</STRING>
    <STRING id = "STR_ID_EM_NFC_CONFIG_SUCCESS">Config success</STRING>
    <STRING id = "STR_ID_EM_NFC_CONFIG_FAIL">Config fail</STRING>
        
    <!----------------- Menu Id   ----------------------------------------->
    <MENU id = "MENU_ID_EM_NFC" type = "APP_SUB"  str = "STR_ID_EM_NFC">
        <MENUITEM id = "MENU_ID_EM_NFC_SETTING" str = "STR_ID_EM_NFC_SETTING"/>
        <MENUITEM_ID>MENU_ID_EM_NFC_SW_STACK</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_NFC_RD</MENUITEM_ID>       
    </MENU>
    
    <MENU id = "MENU_ID_EM_NFC_SW_STACK" type = "APP_SUB"  str = "STR_ID_EM_NFC_SW_STACK">
        <MENUITEM_ID>MENU_ID_EM_NFC_SW_STACK_REG_NOTIFICATION</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_NFC_SW_STACK_DISCOVERY_NOTIFICATION</MENUITEM_ID>
    </MENU>
    
    <MENU id = "MENU_ID_EM_NFC_SW_STACK_REG_NOTIFICATION" type = "APP_SUB"  str = "STR_ID_EM_NFC_SW_STACK_REG_NOTIFICATION">
        /*menu id order don't change for below 8 items */
        <MENUITEM id = "MENU_ID_EM_NFC_SETTING_NOTIFY_BITAMP_0" str = "STR_ID_EM_NFC_STR_MIFAREUL"/>
        <MENUITEM id = "MENU_ID_EM_NFC_SETTING_NOTIFY_BITAMP_1" str = "STR_ID_EM_NFC_STR_MIFARESTD"/>
        <MENUITEM id = "MENU_ID_EM_NFC_SETTING_NOTIFY_BITAMP_2" str = "STR_ID_EM_NFC_STR_ISO14434A"/>
        <MENUITEM id = "MENU_ID_EM_NFC_SETTING_NOTIFY_BITAMP_3" str = "STR_ID_EM_NFC_STR_ISO14434B"/>
        <MENUITEM id = "MENU_ID_EM_NFC_SETTING_NOTIFY_BITAMP_4" str = "STR_ID_EM_NFC_STR_JEWEL"/>
        <MENUITEM id = "MENU_ID_EM_NFC_SETTING_NOTIFY_BITAMP_5" str = "STR_ID_EM_NFC"/>
        <MENUITEM id = "MENU_ID_EM_NFC_SETTING_NOTIFY_BITAMP_6" str = "STR_ID_EM_NFC_STR_FELICA"/>
        <MENUITEM id = "MENU_ID_EM_NFC_SETTING_NOTIFY_BITAMP_7" str = "STR_ID_EM_NFC_STR_ISO15693"/>
    </MENU>
    
    <MENU id = "MENU_ID_EM_NFC_SW_STACK_DISCOVERY_NOTIFICATION" type = "APP_SUB"  str = "STR_ID_EM_NFC_SW_STACK_DISCOVERY_NOTIFICATION">
        /*menu id order don't change for below 8 items */    
        <MENUITEM id = "MENU_ID_EM_NFC_DIS_NOTIFY_BITAMP_0" str = "STR_ID_EM_NFC_DIS_NOTIFY_BITMAP_0"/>
        <MENUITEM id = "MENU_ID_EM_NFC_DIS_NOTIFY_BITAMP_1" str = "STR_ID_EM_NFC_DIS_NOTIFY_BITMAP_1"/>
        <MENUITEM id = "MENU_ID_EM_NFC_DIS_NOTIFY_BITAMP_2" str = "STR_ID_EM_NFC_DIS_NOTIFY_BITMAP_2"/>
        <MENUITEM id = "MENU_ID_EM_NFC_DIS_NOTIFY_BITAMP_3" str = "STR_ID_EM_NFC_DIS_NOTIFY_BITMAP_3"/>
        <MENUITEM id = "MENU_ID_EM_NFC_DIS_NOTIFY_BITAMP_4" str = "STR_ID_EM_NFC_STR_ISO15693"/>
        <MENUITEM id = "MENU_ID_EM_NFC_DIS_NOTIFY_BITAMP_5" str = "STR_ID_EM_NFC_DIS_NOTIFY_BITMAP_5"/>
        <MENUITEM id = "MENU_ID_EM_NFC_DIS_NOTIFY_BITAMP_6" str = "STR_ID_EM_NFC_DIS_NOTIFY_BITMAP_6"/>
        <MENUITEM id = "MENU_ID_EM_NFC_DIS_NOTIFY_BITAMP_7" str = "STR_ID_EM_NFC_DIS_NOTIFY_BITMAP_7"/>
    </MENU>   
    
    <MENU id = "MENU_ID_EM_NFC_RD" type = "APP_SUB"  str = "STR_ID_EM_NFC_SW_PROTOCOL_RAW_DATA">
        <MENUITEM_ID>MENU_ID_EM_NFC_RD_PARAM_SETTING</MENUITEM_ID>
        <MENUITEM id = "MENU_ID_EM_NFC_RD_READER_MODE" str = "STR_ID_EM_NFC_RD_READER_MODE"/>
        <MENUITEM_ID>MENU_ID_EM_NFC_CARD_PARAM_SETTING</MENUITEM_ID>
        <MENUITEM id = "MENU_ID_EM_NFC_RD_CARD_EMU_MODE" str = "STR_ID_EM_NFC_RD_CARD_EMU_MODE"/>
        <MENUITEM_ID>MENU_ID_EM_NFC_P2P_PARAM_SETTING</MENUITEM_ID>
        <MENUITEM id = "MENU_ID_EM_NFC_RD_P2P_MODE" str = "STR_ID_EM_NFC_RD_P2P_MODE"/>
        <MENUITEM id = "MENU_ID_EM_NFC_RD_TX_ON_WO_ASK" str = "STR_ID_EM_NFC_RD_TX_ON_WO_ASK"/>
        <MENUITEM id = "MENU_ID_EM_NFC_RD_TX_ON_WITH_ASK" str = "STR_ID_EM_NFC_RD_TX_ON_WITH_ASK"/>
        <MENUITEM id = "MENU_ID_EM_NFC_RD_ANTENNA_TEST" str = "STR_ID_EM_NFC_RD_ANTANNA_TEST"/>
    </MENU>

    /*reader param setting*/
    <MENU id = "MENU_ID_EM_NFC_RD_PARAM_SETTING" type = "APP_SUB"  str = "STR_ID_EM_NFC_RD_PARAM_SETTING">
        <MENU id = "MENU_ID_EM_NFC_RD_PROTOCOLS" type = "APP_SUB"  str = "STR_ID_EM_NFC_RD_PROTOCOL">
            <MENUITEM_ID>MENU_ID_EM_NFC_DIS_NOTIFY_BITAMP_0</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_EM_NFC_DIS_NOTIFY_BITAMP_1</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_EM_NFC_DIS_NOTIFY_BITAMP_2</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_EM_NFC_DIS_NOTIFY_BITAMP_3</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_EM_NFC_DIS_NOTIFY_BITAMP_4</MENUITEM_ID>
        </MENU>
    </MENU>
    
    /*card param seting*/    
    <MENU id = "MENU_ID_EM_NFC_CARD_PARAM_SETTING" type = "APP_SUB"  str = "STR_ID_EM_NFC_CARD_PARAM_SETTING">
        <MENU id = "MENU_ID_EM_NFC_CARD_PARAM_SE_TYPE" type = "APP_SUB"  str = "STR_ID_EM_NFC_SE">
        /*menu id order don't change for below 3 items */
            <MENUITEM id = "MENU_ID_EM_NFC_CARD_EMU_TYPE_UICC" str = "STR_ID_EM_NFC_CARD_EMU_MODE_SE_TYPE_UICC"/>
            <MENUITEM id = "MENU_ID_EM_NFC_CARD_EMU_TYPE_SMX" str = "STR_ID_EM_NFC_CARD_EMU_MODE_SE_TYPE_SMX"/>
            <MENUITEM id = "MENU_ID_EM_NFC_CARD_EMU_TYPE_NONE" str = "STR_GLOBAL_NONE"/>
        </MENU>
    </MENU>
    
    /*p2p param setting*/
    <MENU id = "MENU_ID_EM_NFC_P2P_PARAM_SETTING" type = "APP_SUB"  str = "STR_ID_EM_NFC_P2P_PARAM_SETTING">
        <MENU id = "MENU_ID_EM_NFC_P2P_PROTOCAL" type = "APP_SUB"  str = "STR_ID_EM_NFC_RD_PROTOCOL">
            /*menu id order don't change for below 3 items */
            <MENUITEM id = "MENU_ID_EM_NFC_P2P_PROTOCAL_NFC_ACTIVE" str = "STR_ID_EM_NFC_RD_P2P_PROTOCOL_NFC_ACTIVE"/>
            <MENUITEM id = "MENU_ID_EM_NFC_P2P_PROTOCAL_DISCARD_CARD" str = "STR_ID_EM_NFC_RD_P2P_PROTOCOL_DISCARD_CARD"/>
            <MENUITEM id = "MENU_ID_EM_NFC_P2P_PROTOCAL_DISABLE_IP_TARGET" str = "STR_ID_EM_NFC_RD_P2P_PROTOCOL_DISABLE_IP_TARGET"/>
        </MENU>
        <MENU id = "MENU_ID_EM_NFC_P2P_MODE_OPT" type = "APP_SUB"  str = "STR_ID_EM_NFC_RD_P2P_MODE_OPT">
            /*menu id order don't change for below 7 items */
            <MENUITEM id = "MENU_ID_EM_NFC_P2P_OPT_DEFAULT" str = "STR_GLOBAL_DEFAULT"/>
            <MENUITEM id = "MENU_ID_EM_NFC_P2P_OPT_P106" str = "STR_ID_EM_NFC_RD_P2P_OPT_P106"/>
            <MENUITEM id = "MENU_ID_EM_NFC_P2P_OPT_P212" str = "STR_ID_EM_NFC_RD_P2P_OPT_P212"/>
            <MENUITEM id = "MENU_ID_EM_NFC_P2P_OPT_P424" str = "STR_ID_EM_NFC_RD_P2P_OPT_P424"/>
            <MENUITEM id = "MENU_ID_EM_NFC_P2P_OPT_ACTIVE" str = "STR_ID_EM_NFC_RD_P2P_OPT_ACTIVE"/>
            <MENUITEM id = "MENU_ID_EM_NFC_P2P_OPT_ALL" str = "STR_ID_EM_NFC_RD_P2P_OPT_ALL"/>
            <MENUITEM id = "MENU_ID_EM_NFC_P2P_OPT_INVALID" str = "STR_GLOBAL_INVALID"/>
        </MENU>    
    </MENU>
    
 
    
    <MENU id = "MENU_ID_EM_NFC_TAG_DET_OPT" type = "APP_SUB"  str = "STR_GLOBAL_OPTIONS">
        /*menu id order don't change for below 3 items */
        <MENUITEM id = "MENU_ID_EM_NFC_TAG_DET_READ" str = "STR_GLOBAL_READ"/>
        <MENUITEM id = "MENU_ID_EM_NFC_TAG_DET_WRITE" str = "STR_ID_EM_NFC_WRITE"/>
        <MENUITEM id = "MENU_ID_EM_NFC_TAG_DET_F2NDEF" str = "STR_ID_EM_NFC_F2NDEF"/>
    </MENU>
    
    <MENU id = "MENU_ID_EM_NFC_P2P_OPT" type = "APP_SUB"  str = "STR_GLOBAL_OPTIONS">
        <MENUITEM id = "MENU_ID_EM_NFC_P2P_SEND" str = "STR_GLOBAL_SEND"/>
        <MENUITEM id = "MENU_ID_EM_NFC_P2P_RECEIVE" str = "STR_ID_EM_NFC_RECEIVE"/>
    </MENU>

    
    
    <!----------------- Menu Id   ----------------------------------------->    
#endif /* __MMI_EM_NFC_SUPPORT__ */
<!----------------- Device | NFC end ------------------------------------->
<!----------------- EM Item End ----------------------------------------------->


#if defined(__MMI_EM_AUDIO__) || defined(__MMI_EM_AUDIO_DEBUG_INFO__) || defined(__MMI_EM_AUDIO_AUTO_VM__)  
<!----------------- Level2 Menu | Audio --------------------------------------->
    <!----------------- Screen Id -----------------------------------------> 

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_AUDIO">Audio</STRING>
 #if defined(__MMI_EM_AUDIO__) 
    <STRING id = "STR_ID_EM_AUD_16_LELVEL_MAX_GAIN">Max analog gain</STRING>
    <STRING id = "STR_ID_EM_AUD_16_LELVEL_STEP">Step</STRING>
 #endif
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_AUDIO" type = "APP_SUB" str = "STR_ID_EM_AUDIO">
    #ifdef __MMI_EM_AUDIO__   /* need revise option!!! */
        <MENUITEM_ID>MENU_ID_EM_AUD_SET_MODE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_AUD_NORMAL_MODE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_AUD_LOUDSP_MODE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_AUD_HEADSET_MODE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_AUD_RING_TONE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_AUD_SPEECH_ENHANCEMENT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_AUD_SET_MAX_SWING</MENUITEM_ID>
    #endif /* __MMI_EM_AUDIO__ */

    #ifdef __MMI_EM_AUDIO_DEBUG_INFO__
        <MENUITEM_ID>MENU_ID_EM_AUD_DEBUG_INFO</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_AUDIO_AUTO_VM__
        <MENUITEM_ID>MENU_ID_EM_AUD_AUTO_VM_SETTING</MENUITEM_ID>
    #endif
    </MENU>
    
    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Audio | Set Mode ------------------------------------------>
#ifdef __MMI_EM_AUDIO__   /* may need to revise __MMI_EM_AUDIO__ defines!!! */

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_AUD_SET_MODE">Set mode</STRING>
    <STRING id = "STR_ID_EM_AUD_SET_VOLUME">Set volume</STRING>
    <STRING id = "STR_ID_EM_AUD_NORMAL_MODE">Normal mode</STRING>
    <STRING id = "STR_ID_EM_AUD_FIR">Fir</STRING>
    <STRING id = "STR_ID_EM_AUD_SPEECH">Speech</STRING>
    <STRING id = "STR_ID_EM_AUD_KEY_TONE">Key tone</STRING>
    <STRING id = "STR_ID_EM_AUD_MELODY">Melody</STRING>
    <STRING id = "STR_ID_EM_AUD_SOUND">FM radio</STRING>
    <STRING id = "STR_ID_EM_AUD_MICROPHONE">Microphone</STRING>
    <STRING id = "STR_ID_EM_AUD_SIDE_TONE">Side tone</STRING>
    <STRING id = "STR_ID_EM_AUD_LOUDSP_MODE">LoudSp mode</STRING>
    <STRING id = "STR_ID_EM_AUD_HEADSET_MODE">Headset mode</STRING>

    <STRING id = "STR_ID_EM_AUD_FIR_0">FIR 0</STRING>
    <STRING id = "STR_ID_EM_AUD_FIR_1">FIR 1</STRING>
    <STRING id = "STR_ID_EM_AUD_FIR_2">FIR 2</STRING>
    <STRING id = "STR_ID_EM_AUD_FIR_3">FIR 3</STRING>
    <STRING id = "STR_ID_EM_AUD_FIR_4">FIR 4</STRING>
    <STRING id = "STR_ID_EM_AUD_FIR_5">FIR 5</STRING>    

    <STRING id = "STR_ID_EM_AUD_TV_OUT">TV out</STRING>
    <STRING id = "STR_ID_EM_AUD_VOLUME_0">Volume 0</STRING>
    <STRING id = "STR_ID_EM_AUD_VOLUME_1">Volume 1</STRING>
    <STRING id = "STR_ID_EM_AUD_VOLUME_2">Volume 2</STRING>
    <STRING id = "STR_ID_EM_AUD_VOLUME_3">Volume 3</STRING>
    <STRING id = "STR_ID_EM_AUD_VOLUME_4">Volume 4</STRING>
    <STRING id = "STR_ID_EM_AUD_VOLUME_5">Volume 5</STRING>
    <STRING id = "STR_ID_EM_AUD_VOLUME_6">Volume 6</STRING>
    <STRING id = "STR_ID_EM_AUD_16_LELVEL_VOLUME">16 level setting</STRING>
    <STRING id = "STR_ID_EM_AUD_DIRECT_APPLY">Direct Apply</STRING>
	
    <!----------------- Menu Id ------------------------------------------->             
    <MENUSET id = "AUDIO_VOL_LIST">
        <MENUITEM id = "MENU_ID_EM_AUD_VOL_0" str = "STR_ID_EM_AUD_VOLUME_0"/>
        <MENUITEM id = "MENU_ID_EM_AUD_VOL_1" str = "STR_ID_EM_AUD_VOLUME_1"/>
        <MENUITEM id = "MENU_ID_EM_AUD_VOL_2" str = "STR_ID_EM_AUD_VOLUME_2"/>
        <MENUITEM id = "MENU_ID_EM_AUD_VOL_3" str = "STR_ID_EM_AUD_VOLUME_3"/>
        <MENUITEM id = "MENU_ID_EM_AUD_VOL_4" str = "STR_ID_EM_AUD_VOLUME_4"/>
        <MENUITEM id = "MENU_ID_EM_AUD_VOL_5" str = "STR_ID_EM_AUD_VOLUME_5"/>
        <MENUITEM id = "MENU_ID_EM_AUD_VOL_6" str = "STR_ID_EM_AUD_VOLUME_6"/>
        <MENUITEM id = "MENU_ID_EM_AUD_16_LELVEL_VOLUME" str = "STR_ID_EM_AUD_16_LELVEL_VOLUME"/>
    </MENUSET>

    <MENU id = "MENU_ID_EM_AUD_SPEECH" type = "APP_SUB" str = "STR_ID_EM_AUD_SPEECH">
        <MENUSET_ID>AUDIO_VOL_LIST</MENUSET_ID>
    </MENU>
    <MENU id = "MENU_ID_EM_AUD_KEY_TONE" type = "APP_SUB" str = "STR_ID_EM_AUD_KEY_TONE">
        <MENUSET_ID>AUDIO_VOL_LIST</MENUSET_ID>
    </MENU>
    <MENU id = "MENU_ID_EM_AUD_MELODY" type = "APP_SUB" str = "STR_ID_EM_AUD_MELODY">
        <MENUSET_ID>AUDIO_VOL_LIST</MENUSET_ID>
    </MENU>
    <MENU id = "MENU_ID_EM_AUD_SOUND" type = "APP_SUB" str = "STR_ID_EM_AUD_SOUND">
        <MENUSET_ID>AUDIO_VOL_LIST</MENUSET_ID>
    </MENU>
    <MENU id = "MENU_ID_EM_AUD_MICROPHONE" type = "APP_SUB" str = "STR_ID_EM_AUD_MICROPHONE">
        <MENUSET_ID>AUDIO_VOL_LIST</MENUSET_ID>
    </MENU>
    <MENU id = "MENU_ID_EM_AUD_SIDE_TONE" type = "APP_SUB" str = "STR_ID_EM_AUD_SIDE_TONE">
        <MENUSET_ID>AUDIO_VOL_LIST</MENUSET_ID>
    </MENU>
    
    <MENUSET id = "AUDIO_MODE">
        <MENUITEM_ID>MENU_ID_EM_AUD_SPEECH</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_AUD_KEY_TONE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_AUD_MELODY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_AUD_SOUND</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_AUD_MICROPHONE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_AUD_SIDE_TONE</MENUITEM_ID>
    </MENUSET>

    <MENU id = "MENU_ID_EM_AUD_SET_MODE" type = "APP_SUB" str = "STR_ID_EM_AUD_SET_MODE" flag = "RADIO">
        <MENUITEM id = "MENU_ID_EM_AUD_SET_NORMAL_MODE" str = "STR_ID_EM_AUD_NORMAL_MODE"/>
        <MENUITEM id = "MENU_ID_EM_AUD_SET_LOUDSP_MODE" str = "STR_ID_EM_AUD_LOUDSP_MODE"/>
        <MENUITEM id = "MENU_ID_EM_AUD_SET_HEADSET_MODE" str = "STR_ID_EM_AUD_HEADSET_MODE"/>
    </MENU>

    <MENU id = "MENU_ID_EM_AUD_FIR" type = "APP_SUB" str = "STR_ID_EM_AUD_FIR" flag = "RADIO">
        <MENUITEM id = "MENU_ID_EM_AUD_FIR_0" str = "STR_ID_EM_AUD_FIR_0"/>
        <MENUITEM id = "MENU_ID_EM_AUD_FIR_1" str = "STR_ID_EM_AUD_FIR_1"/>
        <MENUITEM id = "MENU_ID_EM_AUD_FIR_2" str = "STR_ID_EM_AUD_FIR_2"/>
        <MENUITEM id = "MENU_ID_EM_AUD_FIR_3" str = "STR_ID_EM_AUD_FIR_3"/>
        <MENUITEM id = "MENU_ID_EM_AUD_FIR_4" str = "STR_ID_EM_AUD_FIR_4"/>
        <MENUITEM id = "MENU_ID_EM_AUD_FIR_5" str = "STR_ID_EM_AUD_FIR_5"/>
    </MENU>
     
    <MENU id = "MENU_ID_EM_AUD_NORMAL_MODE" type = "APP_SUB" str = "STR_ID_EM_AUD_NORMAL_MODE">
        <MENUITEM_ID>MENU_ID_EM_AUD_FIR</MENUITEM_ID>
        <MENUSET_ID>AUDIO_MODE</MENUSET_ID>
    </MENU>

    <MENU id = "MENU_ID_EM_AUD_LOUDSP_MODE" type = "APP_SUB" str = "STR_ID_EM_AUD_LOUDSP_MODE">
        <MENUSET_ID>AUDIO_MODE</MENUSET_ID>
    </MENU>

    <MENU id = "MENU_ID_EM_AUD_HEADSET_MODE" type = "APP_SUB" str = "STR_ID_EM_AUD_HEADSET_MODE">
        <MENUSET_ID>AUDIO_MODE</MENUSET_ID>
    </MENU>
#endif /* __MMI_EM_AUDIO__ */    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Audio | Speech Enhancement -------------------------------->
#ifdef __MMI_EM_AUDIO__
    <!----------------- String Id -----------------------------------------> 
    <STRING id = "STR_ID_EM_AUD_SPEECH_ENHANCEMENT">Speech enhancement</STRING>
    <STRING id = "STR_ID_EM_AUD_SPH_ENH_COMMON_PARA">Common parameters</STRING>
    <STRING id = "STR_ID_EM_AUD_SPH_ENH_BT_EARPHONE_MODE">BT earphone mode</STRING>
    <STRING id = "STR_ID_EM_AUD_SPH_ENH_BT_CORDLESS_MODE">BT cordless mode</STRING>
    <STRING id = "STR_ID_EM_AUD_SPH_ENH_AUX1_MODE">AUX1 mode</STRING>
    <STRING id = "STR_ID_EM_AUD_SPH_ENH_AUX2_MODE">AUX2 mode</STRING>
    <STRING id = "STR_ID_EM_AUD_SPH_ENH_AUX3_MODE">AUX3 mode</STRING>
#endif

#if defined( __MMI_EM_AUDIO__) || defined(__MMI_EM_AUDIO_DEBUG_INFO__)  
    <STRING id = "STR_ID_EM_AUD_PARAMETER">Parameter</STRING>
    
    <!----------------- Menu Id ----------------------------------------->
    <MENUSET id = "SPH_PARAM_LIST_9">
        <MENUITEM id = "MENU_ID_EM_AUD_PARAM_0" str = "STR_ID_EM_AUD_PARAMETER"/>
        <MENUITEM id = "MENU_ID_EM_AUD_PARAM_1" str = "STR_ID_EM_AUD_PARAMETER"/>
        <MENUITEM id = "MENU_ID_EM_AUD_PARAM_2" str = "STR_ID_EM_AUD_PARAMETER"/>
        <MENUITEM id = "MENU_ID_EM_AUD_PARAM_3" str = "STR_ID_EM_AUD_PARAMETER"/>
        <MENUITEM id = "MENU_ID_EM_AUD_PARAM_4" str = "STR_ID_EM_AUD_PARAMETER"/>
        <MENUITEM id = "MENU_ID_EM_AUD_PARAM_5" str = "STR_ID_EM_AUD_PARAMETER"/>
        <MENUITEM id = "MENU_ID_EM_AUD_PARAM_6" str = "STR_ID_EM_AUD_PARAMETER"/>
        <MENUITEM id = "MENU_ID_EM_AUD_PARAM_7" str = "STR_ID_EM_AUD_PARAMETER"/>
        <MENUITEM id = "MENU_ID_EM_AUD_PARAM_8" str = "STR_ID_EM_AUD_PARAMETER"/>
    </MENUSET>

    <MENUSET id = "SPH_PARAM_LIST_16">
        <MENUITEM_ID>MENU_ID_EM_AUD_PARAM_0</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_AUD_PARAM_1</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_AUD_PARAM_2</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_AUD_PARAM_3</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_AUD_PARAM_4</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_AUD_PARAM_5</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_AUD_PARAM_6</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_AUD_PARAM_7</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_AUD_PARAM_8</MENUITEM_ID>
        <MENUITEM id = "MENU_ID_EM_AUD_PARAM_9" str = "STR_ID_EM_AUD_PARAMETER"/>
        <MENUITEM id = "MENU_ID_EM_AUD_PARAM_10" str = "STR_ID_EM_AUD_PARAMETER"/>
        <MENUITEM id = "MENU_ID_EM_AUD_PARAM_11" str = "STR_ID_EM_AUD_PARAMETER"/>
        <MENUITEM id = "MENU_ID_EM_AUD_PARAM_12" str = "STR_ID_EM_AUD_PARAMETER"/>
        <MENUITEM id = "MENU_ID_EM_AUD_PARAM_13" str = "STR_ID_EM_AUD_PARAMETER"/>
        <MENUITEM id = "MENU_ID_EM_AUD_PARAM_14" str = "STR_ID_EM_AUD_PARAMETER"/>
        <MENUITEM id = "MENU_ID_EM_AUD_PARAM_15" str = "STR_ID_EM_AUD_PARAMETER"/>
    </MENUSET>
#endif

#ifdef __MMI_EM_AUDIO__
    <MENU id = "MENU_ID_EM_AUD_SPEECH_ENHANCEMENT" type = "APP_SUB" str = "STR_ID_EM_AUD_SPEECH_ENHANCEMENT">
        <MENU id = "MENU_ID_EM_AUD_SPH_ENH_COMMON_PARA" type = "APP_SUB" str = "STR_ID_EM_AUD_SPH_ENH_COMMON_PARA">
            <MENUSET_ID>SPH_PARAM_LIST_9</MENUSET_ID>
        </MENU>
        <MENU id = "MENU_ID_EM_AUD_SPH_ENH_NORMAL_MODE" type = "APP_SUB" str = "STR_ID_EM_AUD_NORMAL_MODE">
            <MENUSET_ID>SPH_PARAM_LIST_16</MENUSET_ID>
        </MENU>
        <MENU id = "MENU_ID_EM_AUD_SPH_ENH_HEADSET_MODE" type = "APP_SUB" str = "STR_ID_EM_AUD_HEADSET_MODE">
            <MENUSET_ID>SPH_PARAM_LIST_16</MENUSET_ID>
        </MENU>
        <MENU id = "MENU_ID_EM_AUD_SPH_ENH_LOUDSPK_MODE" type = "APP_SUB" str = "STR_ID_EM_AUD_LOUDSP_MODE">
            <MENUSET_ID>SPH_PARAM_LIST_16</MENUSET_ID>
        </MENU>
        <MENU id = "MENU_ID_EM_AUD_SPH_ENH_BT_EARPHONE_MODE" type = "APP_SUB" str = "STR_ID_EM_AUD_SPH_ENH_BT_EARPHONE_MODE">
            <MENUSET_ID>SPH_PARAM_LIST_16</MENUSET_ID>
        </MENU>
        <MENU id = "MENU_ID_EM_AUD_SPH_ENH_BT_CORDLESS_MODE" type = "APP_SUB" str = "STR_ID_EM_AUD_SPH_ENH_BT_CORDLESS_MODE">
            <MENUSET_ID>SPH_PARAM_LIST_16</MENUSET_ID>
        </MENU>
        <MENU id = "MENU_ID_EM_AUD_SPH_ENH_AUX1_MODE" type = "APP_SUB" str = "STR_ID_EM_AUD_SPH_ENH_AUX1_MODE">
            <MENUSET_ID>SPH_PARAM_LIST_16</MENUSET_ID>
        </MENU>
        <MENU id = "MENU_ID_EM_AUD_SPH_ENH_AUX2_MODE" type = "APP_SUB" str = "STR_ID_EM_AUD_SPH_ENH_AUX2_MODE">
            <MENUSET_ID>SPH_PARAM_LIST_16</MENUSET_ID>
        </MENU>
        <MENU id = "MENU_ID_EM_AUD_SPH_ENH_AUX3_MODE" type = "APP_SUB" str = "STR_ID_EM_AUD_SPH_ENH_AUX3_MODE">
            <MENUSET_ID>SPH_PARAM_LIST_16</MENUSET_ID>
        </MENU>
    </MENU>
#endif /* __MMI_EM_AUDIO__ */    
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Audio | Ring Tone ----------------------------------------->
#ifdef __MMI_EM_AUDIO__
    <!----------------- Screen Id ----------------------------------------->             
    <SCREEN id = "SCR_ID_EM_AUD_RING_TONE"/>
    <SCREEN id = "SCR_ID_EM_AUD_RING_TONE_MENU"/>

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_AUD_RING_TONE">Ring tone</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_AUD_RING_TONE" type = "APP_SUB" str = "STR_ID_EM_AUD_RING_TONE">
    </MENU>
    
#endif /* __MMI_EM_AUDIO__ */    
<!----------------- EM Item End ----------------------------------------------->

<!----------------- EM Item End ----------------------------------------------->



<!----------------- Audio | Debug Info ---------------------------------------->
#ifdef __MMI_EM_AUDIO_DEBUG_INFO__
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_AUD_DEBUG_INFO">Debug info</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_AUD_DEBUG_INFO" type = "APP_SUB" str = "STR_ID_EM_AUD_DEBUG_INFO">
        <MENUSET_ID>SPH_PARAM_LIST_16</MENUSET_ID>
    </MENU>
#endif/*__MMI_EM_AUDIO_DEBUG_INFO__*/   
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Audio | Auto VM Setting ----------------------------------->
#ifdef __MMI_EM_AUDIO_AUTO_VM__
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_AUD_AUTO_VM_SETTING">Auto record setting</STRING>
    <STRING id = "STR_ID_EM_AUD_VM_SUPPORT">VM Support</STRING>
    <STRING id = "STR_ID_EM_AUD_AUTO_VM_SPH">Auto Speech Record</STRING>
	
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_AUD_VM_SUPPORT" type = "APP_SUB" str = "STR_ID_EM_AUD_VM_SUPPORT" flag = "RADIO">
        <MENUSET_ID>MENUSET_ON_OFF</MENUSET_ID>
    </MENU>
    <MENU id = "MENU_ID_EM_AUD_AUTO_VM_SPH" type = "APP_SUB" str = "STR_ID_EM_AUD_AUTO_VM_SPH" flag = "RADIO">
        <MENUSET_ID>MENUSET_ON_OFF</MENUSET_ID>
    </MENU>
    <MENU id = "MENU_ID_EM_AUD_AUTO_VM_SETTING" type = "APP_SUB" str = "STR_ID_EM_AUD_AUTO_VM_SETTING">
        //<MENUITEM_ID>MENU_ID_EM_AUD_VM_SUPPORT</MENUITEM_ID>
        //<MENUITEM_ID>MENU_ID_EM_AUD_AUTO_VM_SPH</MENUITEM_ID>
        <MENUSET_ID>MENUSET_ON_OFF</MENUSET_ID>
    </MENU>
#endif/*__MMI_EM_AUDIO_AUTO_VM__*/    

#endif   // defined(__MMI_EM_AUDIO__) || defined(__MMI_EM_AUDIO_DEBUG_INFO__) || defined(__MMI_EM_AUDIO_AUTO_VM__)  
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Level2 Menu | GPRS Act ------------------------------------>
#if defined(__MMI_EM_GPRS_AUTO_ATTACH__) || defined(__MMI_EM_GPRS_PDP__) || defined(__MMI_EM_GPRS_CNMGR_SCRI_SUPPORT__)
    <!----------------- String Id ----------------------------------------->

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_GPRS_ACT">GPRS act</STRING>

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_GPRS_ACT" type = "APP_SUB" str = "STR_ID_EM_GPRS_ACT">
    #ifdef __MMI_EM_GPRS_AUTO_ATTACH__
        <MENUITEM_ID>MENU_ID_EM_GPRS_AUTO_ATTACH</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_GPRS_PDP__
        <MENUITEM_ID>MENU_ID_EM_GPRS_PDP_1</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_GPRS_PDP_2</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_GPRS_CNMGR_SCRI_SUPPORT__
        <MENUITEM_ID>MENU_ID_EM_GPRS_CNMGR_SCRI_CONFIG</MENUITEM_ID>
    #endif

	/*Fast dormancy*/
	#ifdef __MMI_EM_GPRS_FAST_DORMANCY__
		<MENUITEM_ID>MENU_ID_EM_GPRS_FAST_DORMANCY</MENUITEM_ID>
	#endif

	
    </MENU>
 
<!----------------- EM Item End ----------------------------------------------->


<!----------------- GPRS Act | GPRS Auto Attach ------------------------------->
#ifdef __MMI_EM_GPRS_AUTO_ATTACH__
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_GPRS_AUTO_ATTACH">Attach</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_GPRS_AUTO_ATTACH" type = "APP_SUB" str = "STR_ID_EM_GPRS_AUTO_ATTACH">
    </MENU>

#endif /* __MMI_EM_GPRS_AUTO_ATTACH__ */    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- GPRS Act | GPRS 1st PDP ----------------------------------->
#ifdef __MMI_EM_GPRS_PDP__
    <SCREEN id = "SCR_ID_EM_GPRS_SEND_DATA_EDITOR"/>
    <SCREEN id = "SCR_ID_EM_GPRS_ACTIVATE_PDP_MENU"/>
    
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_GPRS_PDP_1">1st PDP</STRING>
    <STRING id = "STR_ID_EM_GPRS_ACTIVATE_PDP">Activate PDP</STRING>
    <STRING id = "STR_ID_EM_GPRS_DEACTIVATE_PDP">Deactivate PDP</STRING>
    <STRING id = "STR_ID_EM_GPRS_SEND_DATA">Send data</STRING>
    <STRING id = "STR_ID_EM_GPRS_SEND_DATA_NORM">Send norm data</STRING>
    <STRING id = "STR_ID_EM_GPRS_SEND_DATA_HDR">Send RLC data</STRING>

    <STRING id = "STR_ID_EM_GPRS_PDP_CONTEXT">PDP context</STRING>
    #ifdef __R99__
    #if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
    <!----------------------------------keep order for below 4 items------------------------->
    <STRING id = "STR_ID_EM_GPRS_PDP_CONTEXT_GHIJK_INTERACTIVE">PDP GHIJK, interActive</STRING>
    <STRING id = "STR_ID_EM_GPRS_PDP_CONTEXT_GHIJK_BACKGROUND">PDP GHIJK, background</STRING>
    <STRING id = "STR_ID_EM_GPRS_PDP_CONTEXT_ABCDEF_INTERACTIVE">PDP ABCDEF interActive</STRING>
    <STRING id = "STR_ID_EM_GPRS_PDP_CONTEXT_ABCDEF_BACKGROUND">PDP ABCDEF background</STRING>
    #endif
    #endif
    
    <!----------------- Menu Id ------------------------------------------->    
    <MENU id = "MENU_ID_EM_GPRS_SEND_DATA" type = "APP_SUB" str = "STR_ID_EM_GPRS_SEND_DATA">
        <MENUITEM id = "MENU_ID_EM_GPRS_SEND_DATA_NORM" str = "STR_ID_EM_GPRS_SEND_DATA_NORM"/>
        <MENUITEM id = "MENU_ID_EM_GPRS_SEND_DATA_HDR" str = "STR_ID_EM_GPRS_SEND_DATA_HDR"/>
    </MENU>    

    <MENU id = "MENU_ID_EM_GPRS_PDP_1" type = "APP_SUB" str = "STR_ID_EM_GPRS_PDP_1">
        <MENUITEM id = "MENU_ID_EM_GPRS_ACTIVATE_PDP" str = "STR_ID_EM_GPRS_ACTIVATE_PDP"/>
        <MENUITEM id = "MENU_ID_EM_GPRS_DEACTIVATE_PDP" str = "STR_ID_EM_GPRS_DEACTIVATE_PDP"/>
        <MENUITEM_ID>MENU_ID_EM_GPRS_SEND_DATA</MENUITEM_ID>
    </MENU>
#endif/*__MMI_EM_GPRS_PDP__*/
<!----------------- EM Item End ----------------------------------------------->


<!----------------- GPRS Act | GPRS 2nd PDP ----------------------------------->
#ifdef __MMI_EM_GPRS_PDP__
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_GPRS_PDP_2">2nd PDP</STRING>
    <STRING id = "STR_ID_EM_GPRS_ACTIVATE_2ND_PDP_PRIMARY">As primary</STRING>
    <STRING id = "STR_ID_EM_GPRS_ACTIVATE_2ND_PDP_SECOND">As secondary</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_GPRS_ACTIVATE_2ND_PDP" type = "APP_SUB" str = "STR_ID_EM_GPRS_ACTIVATE_PDP">
            <MENUITEM id = "MENU_ID_EM_GPRS_ACTIVATE_2ND_PDP_PRIMARY" str = "STR_ID_EM_GPRS_ACTIVATE_2ND_PDP_PRIMARY"/>
            <MENUITEM id = "MENU_ID_EM_GPRS_ACTIVATE_2ND_PDP_SECOND" str = "STR_ID_EM_GPRS_ACTIVATE_2ND_PDP_SECOND"/>
    </MENU> 
        
    <MENU id = "MENU_ID_EM_GPRS_PDP_2" type = "APP_SUB" str = "STR_ID_EM_GPRS_PDP_2">
        <MENUITEM_ID>MENU_ID_EM_GPRS_ACTIVATE_2ND_PDP</MENUITEM_ID>
        <MENUITEM id = "MENU_ID_EM_GPRS_PDP_2_DEACTIVATE_PDP" str = "STR_ID_EM_GPRS_DEACTIVATE_PDP"/>
        <MENUITEM_ID>MENU_ID_EM_GPRS_SEND_DATA</MENUITEM_ID>
    </MENU>
#endif/*__MMI_EM_GPRS_PDP__*/
<!----------------- EM Item End ----------------------------------------------->

<!----------------- GPRS Act | Connection management -------------------------------->
#ifdef __MMI_EM_GPRS_CNMGR_SCRI_SUPPORT__

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_GPRS_CNMGR_SCRI_CHECK_TIME">SCRI check time</STRING>
    <STRING id = "STR_ID_EM_GPRS_CNMGR_LCD_ON">LCD on</STRING>
    <STRING id = "STR_ID_EM_GPRS_CNMGR_LCD_OFF">LCD off</STRING>
    <STRING id = "STR_ID_EM_GPRS_CNMGR_SET">Set</STRING>
    <STRING id = "STR_ID_EM_GPRS_CNMGR_UNSET">Unset</STRING>

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_GPRS_CNMGR_SCRI_CONFIG" type = "APP_SUB" str = "STR_ID_EM_GPRS_CNMGR_SCRI_CHECK_TIME">
        <MENUITEM_ID>MENU_ID_EM_GPRS_CNMGR_SCRI_LCD_ON_CHECK_TIME</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_GPRS_CNMGR_SCRI_LCD_OFF_CHECK_TIME</MENUITEM_ID>
    </MENU>
    
    <MENU id = "MENU_ID_EM_GPRS_CNMGR_SCRI_LCD_ON_CHECK_TIME" type = "APP_SUB" str = "STR_ID_EM_GPRS_CNMGR_LCD_ON">
        <MENUITEM_ID>MENU_ID_EM_GPRS_CNMGR_SET_SCRI_LCD_ON_CHECK_TIME</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_GPRS_CNMGR_UNSET_SCRI_LCD_ON_CHECK_TIME</MENUITEM_ID>
    </MENU>
    
    <MENU id = "MENU_ID_EM_GPRS_CNMGR_SCRI_LCD_OFF_CHECK_TIME" type = "APP_SUB" str = "STR_ID_EM_GPRS_CNMGR_LCD_OFF">
        <MENUITEM_ID>MENU_ID_EM_GPRS_CNMGR_SET_SCRI_LCD_OFF_CHECK_TIME</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_GPRS_CNMGR_UNSET_SCRI_LCD_OFF_CHECK_TIME</MENUITEM_ID>
    </MENU>
    
    <MENU id = "MENU_ID_EM_GPRS_CNMGR_SET_SCRI_LCD_ON_CHECK_TIME" type = "APP_SUB" str = "STR_ID_EM_GPRS_CNMGR_SET"/>
    <MENU id = "MENU_ID_EM_GPRS_CNMGR_UNSET_SCRI_LCD_ON_CHECK_TIME" type = "APP_SUB" str = "STR_ID_EM_GPRS_CNMGR_UNSET"/>
    <MENU id = "MENU_ID_EM_GPRS_CNMGR_SET_SCRI_LCD_OFF_CHECK_TIME" type = "APP_SUB" str = "STR_ID_EM_GPRS_CNMGR_SET"/>
    <MENU id = "MENU_ID_EM_GPRS_CNMGR_UNSET_SCRI_LCD_OFF_CHECK_TIME" type = "APP_SUB" str = "STR_ID_EM_GPRS_CNMGR_UNSET"/>

#endif /* __MMI_EM_GPRS_CNMGR_SCRI_SUPPORT__ */ 


<!----------------- GPRS Act | Fast dormancy ------------------------------->
#ifdef __MMI_EM_GPRS_FAST_DORMANCY__
    <!----------------- String Id ----------------------------------------->             
	<SCREEN id = "GRP_ID_FAST_DORMANCY"/>

	<STRING id = "STR_ID_EM_GPRS_FAST_DORMANCY_SELECT_POWER_OFF">"Select and power off?" </STRING>


	<STRING id = "STR_ID_EM_GPRS_FAST_DORMANCY">Fast dormancy</STRING>
    <STRING id = "STR_ID_EM_GPRS_FAST_DORMANCY_ON">On</STRING>
    <STRING id = "STR_ID_EM_GPRS_FAST_DORMANCY_OFF">Off</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             

	<MENU id = "MENU_ID_EM_GPRS_FAST_DORMANCY" type = "APP_SUB" str = "STR_ID_EM_GPRS_FAST_DORMANCY"/>

    <MENU id = "MENU_ID_EM_GPRS_FAST_DORMANCY_ROOT" type = "APP_SUB" str = "STR_ID_EM_GPRS_FAST_DORMANCY" flag="RADIO">
		<MENUITEM_ID>MENU_ID_EM_GPRS_FAST_DORMANCY_ON</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_EM_GPRS_FAST_DORMANCY_OFF</MENUITEM_ID>
	</MENU>

	<MENU id = "MENU_ID_EM_GPRS_FAST_DORMANCY_ON" type = "APP_SUB" str = "STR_ID_EM_GPRS_FAST_DORMANCY_ON"/>
	<MENU id = "MENU_ID_EM_GPRS_FAST_DORMANCY_OFF" type = "APP_SUB" str = "STR_ID_EM_GPRS_FAST_DORMANCY_OFF"/>
	
	
#endif /*__MMI_EM_GPRS_FAST_DORMANCY__*/
   
<!----------------- EM Item End ----------------------------------------------->


#endif /*defined(__MMI_EM_GPRS_AUTO_ATTACH__) || defined(__MMI_EM_GPRS_PDP__) ||defined(__MMI_EM_GPRS_CNMGR_SCRI_SUPPORT__) */ 
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Level2 Menu | Misc.---------------------------------------->

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_MISC">Misc.</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_MISC" type = "APP_SUB" str = "STR_ID_EM_MISC">
    #ifdef __MMI_EM_MISC_AUTO_ANSWER__
        <MENUITEM_ID>MENU_ID_EM_MISC_AUTO_ANSWER</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_MISC_HIGHSPEED_SIM__
        <MENUITEM_ID>MENU_ID_EM_MISC_HIGH_SPEED_SIM</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_MISC_BACKLIGHT__
        <MENUITEM_ID>MENU_ID_EM_MISC_BACKLIGHT_MODE</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_MISC_AUTO_RESET__
        <MENUITEM_ID>MENU_ID_EM_MISC_AUTO_RESET</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_MISC_RAM_TEST__
        <MENUITEM_ID>MENU_ID_EM_MISC_RAM_TEST</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_MISC_MEMORY_DUMP__
        <MENUITEM_ID>MENU_ID_EM_MISC_MEMORY_DUMP</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_MISC_AMR__
        <MENUITEM_ID>MENU_ID_EM_MISC_AMR</MENUITEM_ID>
    #endif

    #if !defined(__MMI_EM_INET_APP_SLIM__)
        <MENUITEM_ID>MENU_ID_EM_MISC_INTERNET_APPLICATION</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_MISC_TOUCH_SCREEN__
        <MENUITEM_ID>MENU_ID_EM_MISC_TOUCH_SCREEN</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_MISC_VIDEO_HI_BITRATE__
        <MENUITEM_ID>MENU_ID_EM_MISC_VIDEO_HIGH_BITRATE</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_MISC_CELL_RESELECTION__ 
        <MENUITEM_ID>MENU_ID_EM_MISC_CELL_RESELECTION</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_MISC_CASCADE_MENU__ 
        <MENUITEM_ID>MENU_ID_EM_MISC_CASCADE_MENU</MENUITEM_ID>
    #endif

    #if (defined(__MMI_EM_MISC_CHECK_DRIVE__) && defined(__PLUTO_MMI_PACKAGE__)  && !defined(__MMI_SLIM_FILE_MANAGER__))
        <MENUITEM_ID>MENU_ID_MMI_EM_MISC_CHECK_DRIVE</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_MISC_SOFTWARE_TRACER__ 
        <MENUITEM_ID>MENU_ID_EM_MISC_SOFTWARE_TRACER</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_MISC_DM_REGISTER__ 
        <MENUITEM_ID>MENU_ID_EM_MISC_DM_SELF_REGISTER</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_MISC_DCD__ 
        <MENUITEM_ID>MENU_ID_EM_MISC_DCD_NW_PARAM</MENUITEM_ID>
    #ifdef __MMI_OP01_DCD_V30__
        <MENUITEM_ID>MENU_ID_EM_MISC_DCD_STORAGE_SWITCH</MENUITEM_ID>
    #endif
    #endif
    
    #ifdef __MMI_EM_MISC_FOTA_DEBUG__
        <MENUITEM_ID>MENU_ID_EM_MISC_F0TA_DEBUG</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_EM_MISC_DM_ADD_APN__ 
        <MENUITEM_ID>MENU_ID_EM_MISC_DM_ADD_APN</MENUITEM_ID>
    #endif
    
    #ifdef  __MMI_EM_MISC_VIDEO_PARAM__
        <MENUITEM_ID>MENU_ID_EM_MISC_VIDEO_PARAM</MENUITEM_ID>
    #endif
    
    #if 0
    #ifdef __MMI_FM_AUTO_TEST__
        <MENUITEM_ID>MENU_ID_EM_MISC_AUTO_TEST_SETTING</MENUITEM_ID>
    #endif 
    #endif

    #if defined( __MMI_EM_MISC_RECORDER_SETTING__)        
        <MENUITEM_ID>EM_MISC_RECORDER_SETTING_MENUID</MENUITEM_ID>            
    #endif
    
    #ifdef __MMI_EM_SW_PATCH__ 
        <MENUITEM_ID>MENU_ID_EM_MISC_SOFTWARE_PATCH</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_EM_JAVA_SUPPORT__ 
        <MENUITEM_ID>MENU_ID_EM_JAVA</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_EM_MISC_MEDIA_MEMORY_SETTING__
        <MENUITEM_ID>EM_MISC_MEDIA_MEMORY_SETTING_MENUID</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_RF_DESENSE_TEST__
        <MENUITEM_ID>MENU_ID_EM_MISC_RF_DESENSE</MENUITEM_ID>
    #endif /* __MMI_EM_RF_DESENSE_TEST__ */

    #ifdef __MMI_EM_MISC_X_DOWNLOAD__
        <MENUITEM_ID>MENU_ID_EM_MISC_X_DOWNLOAD</MENUITEM_ID>
    #endif
 #ifndef __MMI_MAINLCD_96X64__
        <MENUITEM_ID>MENU_ID_EM_MRE</MENUITEM_ID>
 #endif
	#ifdef __MMI_EM_MISC_POWER_ON_CPU_QUERY__
		<MENUITEM_ID>MENU_ID_EM_MISC_POWER_ON_CPU_QUERY</MENUITEM_ID>
	#endif
	
    </MENU>
    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | Auto Answer --------------------------------------->
#ifdef __MMI_EM_MISC_AUTO_ANSWER__
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_MISC_AUTO_ANSWER">Auto answer</STRING>
    
    <!----------------- Menu Id ------------------------------------------->    
    <MENU id = "MENU_ID_EM_MISC_AUTO_ANSWER" type = "APP_SUB" str = "STR_ID_EM_MISC_AUTO_ANSWER" flag = "RADIO">
        <MENUSET_ID>MENUSET_ON_OFF</MENUSET_ID>
    </MENU>
#endif/*__MMI_EM_MISC_AUTO_ANSWER__*/   
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | High Speed SIM ------------------------------------>
#ifdef __MMI_EM_MISC_HIGHSPEED_SIM__
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_MISC_HIGH_SPEED_SIM">High speed SIM</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_MISC_HIGH_SPEED_SIM" type = "APP_SUB" str = "STR_ID_EM_MISC_HIGH_SPEED_SIM" flag = "RADIO">
        <MENUSET_ID>MENUSET_ON_OFF</MENUSET_ID>
    </MENU>

#endif /* __MMI_EM_MISC_HIGHSPEED_SIM__ */    
<!----------------- EM Item End ----------------------------------------------->

<!----------------- Misc. | Backlight Mode ------------------------------------>
#ifdef __MMI_EM_MISC_BACKLIGHT__
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_MISC_BACKLIGHT_MODE">Backlight mode</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_MISC_BACKLIGHT_MODE" type = "APP_SUB" str = "STR_ID_EM_MISC_BACKLIGHT_MODE" flag = "RADIO">
        <MENUSET_ID>MENUSET_ON_OFF</MENUSET_ID>
    </MENU>

#endif /* __MMI_EM_MISC_BACKLIGHT__ */    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | Auto Reset -------------------------------->
#ifdef __MMI_EM_MISC_AUTO_RESET__
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_MISC_AUTO_RESET">Assert test</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_MISC_AUTO_RESET" type = "APP_SUB" str = "STR_ID_EM_MISC_AUTO_RESET">
    </MENU>

#endif /* __MMI_EM_MISC_AUTO_RESET__ */    
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Misc. | RAM Test ------------------------------------------>
#ifdef __MMI_EM_MISC_RAM_TEST__
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_MISC_RAM_TEST">RAM test</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENUITEM id = "MENU_ID_EM_MISC_RAM_TEST" str = "STR_ID_EM_MISC_RAM_TEST"/>
#endif/*__MMI_EM_MISC_RAM_TEST__*/
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Misc. | Memory Dump --------------------------------------->
#ifdef __MMI_EM_MISC_MEMORY_DUMP__
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_MISC_MEMORY_DUMP">Memory dump</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_MISC_MEMORY_DUMP" type = "APP_SUB" str = "STR_ID_EM_MISC_MEMORY_DUMP" flag = "RADIO">
        <MENUSET_ID>MENUSET_ON_OFF</MENUSET_ID>
    </MENU>
#endif/*__MMI_EM_MISC_MEMORY_DUMP__*/
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | AMR ----------------------------------------------->
#ifdef __MMI_EM_MISC_AMR__
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_MISC_AMR">AMR</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_MISC_AMR" type = "APP_SUB" str = "STR_ID_EM_MISC_AMR" flag = "RADIO">
        <MENUSET_ID>MENUSET_ON_OFF</MENUSET_ID>
    </MENU>

#endif /* __MMI_EM_MISC_AMR__ */
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Misc. | Internet Application ------------------------------>
#if !defined(__MMI_EM_INET_APP_SLIM__)
    <!----------------- Screen Id ----------------------------------------->             
    <SCREEN id = "GRP_ID_EM_MISC_INET_APP_USER_AGENT"/>
    <SCREEN id = "GRP_ID_EM_MISC_INET_APP_ACCEPT_HEADER"/>
    <SCREEN id = "GRP_ID_EM_MISC_INET_APP_MMS_VERSION"/>

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_MISC_INTERNET_APPLICATION">Internet application</STRING>
    <STRING id = "STR_ID_EM_MISC_INET_APP_USER_AGENT">User agent</STRING>
    <STRING id = "STR_ID_EM_MISC_INET_APP_ACCEPT_HEADER">Accept header</STRING>
    <STRING id = "STR_ID_EM_MISC_INET_APP_MMS_VERSION">MMS version</STRING>
    
    <STRING id = "STR_ID_EM_MISC_INET_APP_AH_WAP_1_2_1">WAP 1.2.1</STRING>
    <STRING id = "STR_ID_EM_MISC_INET_APP_AH_WAP_2_0">WAP 2.0</STRING>
    <STRING id = "STR_ID_EM_MISC_INET_APP_AH_WML">WML</STRING>
    <STRING id = "STR_ID_EM_MISC_INET_APP_AH_XHTML">XHTML</STRING>
    <STRING id = "STR_ID_EM_MISC_INET_APP_AH_HTML">HTML</STRING>
    
    <STRING id = "STR_ID_EM_MISC_INET_APP_MV_MMS_1_0">MMS 1.0</STRING>
    <STRING id = "STR_ID_EM_MISC_INET_APP_MV_MMS_1_1">MMS 1.1</STRING>
    <STRING id = "STR_ID_EM_MISC_INET_APP_MV_MMS_1_2">MMS 1.2</STRING>

    <STRING id = "STR_ID_EM_MISC_INET_APP_USER_AGENT_STRING">User agent string</STRING>
    <STRING id = "STR_ID_EM_MISC_INET_APP_USER_AGENT_PROFILE">User agent profile</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_MISC_INTERNET_APPLICATION" type = "APP_SUB" str = "STR_ID_EM_MISC_INTERNET_APPLICATION" flag = "CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS">
        <MENUITEM id = "MENU_ID_EM_MISC_INET_APP_USER_AGENT" str = "STR_ID_EM_MISC_INET_APP_USER_AGENT"/>
        <MENUITEM_ID>MENU_ID_EM_MISC_INET_APP_ACCEPT_HEADER</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_MISC_INET_APP_MMS_VERSION</MENUITEM_ID> 
    </MENU>

    <MENU id = "MENU_ID_EM_MISC_INET_APP_ACCEPT_HEADER" type = "APP_SUB" str = "STR_ID_EM_MISC_INET_APP_ACCEPT_HEADER" flag = "CUI_MENU_NORMAL_RADIO_BUTTON_LIST">
        <MENUITEM id = "MENU_ID_EM_MISC_INET_APP_AH_WAP_1_2_1" str = "STR_ID_EM_MISC_INET_APP_AH_WAP_1_2_1"/>
        <MENUITEM id = "MENU_ID_EM_MISC_INET_APP_AH_WAP_2_0" str = "STR_ID_EM_MISC_INET_APP_AH_WAP_2_0"/>
        <MENUITEM id = "MENU_ID_EM_MISC_INET_APP_AH_WML" str = "STR_ID_EM_MISC_INET_APP_AH_WML"/>
        <MENUITEM id = "MENU_ID_EM_MISC_INET_APP_AH_XHTML" str = "STR_ID_EM_MISC_INET_APP_AH_XHTML"/>
        <MENUITEM id = "MENU_ID_EM_MISC_INET_APP_AH_HTML" str = "STR_ID_EM_MISC_INET_APP_AH_HTML"/>                
    </MENU>

    <MENU id = "MENU_ID_EM_MISC_INET_APP_MMS_VERSION" type = "APP_SUB" str = "STR_ID_EM_MISC_INET_APP_MMS_VERSION" flag = "CUI_MENU_NORMAL_RADIO_BUTTON_LIST">
        <MENUITEM id = "MENU_ID_EM_MISC_INET_APP_MV_MMS_1_0" str = "STR_ID_EM_MISC_INET_APP_MV_MMS_1_0"/>
        <MENUITEM id = "MENU_ID_EM_MISC_INET_APP_MV_MMS_1_1" str = "STR_ID_EM_MISC_INET_APP_MV_MMS_1_1"/>
        <MENUITEM id = "MENU_ID_EM_MISC_INET_APP_MV_MMS_1_2" str = "STR_ID_EM_MISC_INET_APP_MV_MMS_1_2"/>
    </MENU>

    <MENU id = "MENU_ID_EM_MISC_INET_APP_UA_OPTIONS" type = "APP_SUB" str = "STR_GLOBAL_OPTIONS" flag = "CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS">
        <MENUITEM id = "MENU_ID_EM_MISC_INET_APP_UA_ACTIVATE" str = "STR_GLOBAL_ACTIVATE"/>
        <MENUITEM id = "MENU_ID_EM_MISC_INET_APP_UA_EDIT" str = "STR_GLOBAL_EDIT"/>        
    </MENU>

    <!----------------- MMI Caches ------------------------------------------->     
    <CACHEDATA type="byte" id="NVRAM_EM_INET_ACTIVE_USER_AGENT">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_EM_INET_ACTIVE_ACCEPT_HEADER">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_EM_INET_ACTIVE_MMS_VERSION">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
#endif
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Misc. | Touch Screen -------------------------------------->
#ifdef __MMI_EM_MISC_TOUCH_SCREEN__
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_MISC_TOUCH_SCREEN">Touch screen</STRING>
    
    <!----------------- Menu Id ------------------------------------------->
    <MENU id = "MENU_ID_EM_MISC_TOUCH_SCREEN" type = "APP_SUB" str = "STR_ID_EM_MISC_TOUCH_SCREEN"> 
        <MENUITEM_ID>MENU_ID_SSP_SETTINGS</MENUITEM_ID>        
        <MENUITEM_ID>MENU_ID_EM_MISC_TOUCH_SCREEN_PEN_EVENT</MENUITEM_ID>
    
        <MENUITEM_ID>MENU_ID_EM_MISC_TOUCH_SCREEN_ACCURACY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_RESET</MENUITEM_ID>
    
    #ifdef __MMI_EM_MISC_MULTI_TOUCH__
        <MENUITEM_ID>MENU_ID_EM_MISC_TOUCH_SCREEN_MULTI_TOUCH</MENUITEM_ID>
    #endif
    </MENU>

#endif /* __MMI_EM_MISC_TOUCH_SCREEN__ */    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | Video High Bit Rate ------------------------------->
#ifdef __MMI_EM_MISC_VIDEO_HI_BITRATE__
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_MISC_VIDEO_HIGH_BITRATE">Video high bitrate</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_MISC_VIDEO_HIGH_BITRATE" type = "APP_SUB" str = "STR_ID_EM_MISC_VIDEO_HIGH_BITRATE" flag = "RADIO">
        <MENUSET_ID>MENUSET_ON_OFF</MENUSET_ID>
    </MENU>

#endif /* __MMI_EM_MISC_VIDEO_HI_BITRATE__ */    
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Misc. | Cell reselection ---------------------------------->
#ifdef __MMI_EM_MISC_CELL_RESELECTION__
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_MISC_CELL_RESELECTION">Cell reselection</STRING>
    <STRING id = "STR_ID_EM_MISC_CELL_RESELECT_SUSPEND">Resume</STRING>
    <STRING id = "STR_ID_EM_MISC_CELL_RESELECT_RESUME_IN_TANSFER">Suspend(trans. state)</STRING>
    <STRING id = "STR_ID_EM_MISC_CELL_RESELECT_RESUME_IN_ALL">Suspend(all state)</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_MISC_CELL_RESELECTION" type = "APP_SUB" str = "STR_ID_EM_MISC_CELL_RESELECTION" flag = "RADIO">
        <MENUITEM id = "MENU_ID_EM_MISC_CELL_RESELECT_SUSPEND" str = "STR_ID_EM_MISC_CELL_RESELECT_SUSPEND"/>
        <MENUITEM id = "MENU_ID_EM_MISC_CELL_RESELECT_RESUME_IN_TANSFER" str = "STR_ID_EM_MISC_CELL_RESELECT_RESUME_IN_TANSFER"/>
        <MENUITEM id = "MENU_ID_EM_MISC_CELL_RESELECT_RESUME_IN_ALL" str = "STR_ID_EM_MISC_CELL_RESELECT_RESUME_IN_ALL"/>
    </MENU>

#endif /* __MMI_EM_MISC_CELL_RESELECTION__ */    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | Cascade Menu ---------------------------------------->
#ifdef __MMI_EM_MISC_CASCADE_MENU__  /* better move to FW Profiling Level1 menu!!! */  
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_MISC_CASCADE_MENU">Cascade menu test</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_MISC_CASCADE_MENU" type = "APP_SUB" str = "STR_ID_EM_MISC_CASCADE_MENU">
    </MENU>

#endif /* __MMI_EM_MISC_CASCADE_MENU__ */    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | Check Drive --------------------------------------->
#ifdef __MMI_EM_MISC_CHECK_DRIVE__
    <!----------------- Screen Id ----------------------------------------->    
    <SCREEN id="GRP_ID_MMI_EM_MISC_CHECK_DRIVE"/>
    <SCREEN id="SCR_ID_MMI_EM_MISC_CHECK_DRIVE_ANIMATION"/>
    
    <!----------------- String Id ----------------------------------------->             
    <STRING id="STR_ID_MMI_EM_MISC_CHECK_DRIVE">Scan disk</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id="MENU_ID_MMI_EM_MISC_CHECK_DRIVE" type="APP_SUB" str="STR_ID_MMI_EM_MISC_CHECK_DRIVE">
    </MENU>

#endif /* __MMI_EM_MISC_CHECK_DRIVE__ */    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | Software Tracer ----------------------------------->
#ifdef __MMI_EM_MISC_SOFTWARE_TRACER__   
    <!----------------- String Id ----------------------------------------->
    /* It have not string resource */
    <STRING id = "STR_ID_EM_MISC_SOFTWARE_TRACER">Software tracer</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_MISC_SOFTWARE_TRACER" type = "APP_SUB" str = "STR_ID_EM_MISC_SOFTWARE_TRACER">
    </MENU>

#endif /* __MMI_EM_MISC_SOFTWARE_TRACER__ */    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | DM Self Register --------------------------------------->
#ifdef __MMI_EM_MISC_DM_REGISTER__   

    <!----------------- Screen Id ----------------------------------------->    
    <SCREEN id = "GRP_ID_EM_MISC_DM_SELF_REGISTER"/>
    <SCREEN id = "SCR_ID_EM_MISC_DM_SELF_REGISTER"/>
#ifdef __MMI_DUAL_SIM_MASTER__
    <SCREEN id = "GRP_ID_EM_MISC_DM_SELF_REGISTER_RESULT_SIM"/>
    <SCREEN id = "SCR_ID_EM_MISC_DM_SELF_REGISTER_RESULT_SIM"/>
#endif
#ifdef __OP02_DM__
    <SCREEN id = "GRP_ID_EM_MISC_DM_SELF_REGISTER_PORT"/>
    <SCREEN id = "SCR_ID_EM_MISC_DM_SELF_REGISTER_PORT"/>
#endif
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_MISC_DM_SELF_REGISTER">DM self register</STRING>
    <STRING id = "STR_ID_EM_MISC_DM_SELF_REGISTER_NUMBER">Register no.</STRING>
    <STRING id = "STR_ID_EM_MISC_DM_SELF_REGISTER_NOTICE_SUCCESS">Success</STRING>
    <STRING id = "STR_ID_EM_MISC_DM_SELF_REGISTER_DEVICE_NAME">Device name.</STRING>
    <STRING id = "STR_ID_EM_MISC_DM_SELF_REGISTER_MASTER_SWITCH">Master switch.</STRING>
#ifdef __OP02_DM__
    <STRING id = "STR_ID_EM_MISC_DM_SELF_REGISTER_PORT">Register port no.</STRING>
#endif
    <STRING id = "STR_ID_EM_MISC_DM_SELF_REGISTER_RESULT">Register Result</STRING>
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_MISC_DM_SELF_REGISTER" type = "APP_SUB" str = "STR_ID_EM_MISC_DM_SELF_REGISTER">
        <MENUITEM id = "MENU_ID_EM_MISC_DM_SELF_REGISTER_NUMBER" str = "STR_ID_EM_MISC_DM_SELF_REGISTER_NUMBER"/>
    #ifdef __OP02_DM__
        <MENUITEM id = "MENU_ID_EM_MISC_DM_SELF_REGISTER_PORT" str = "STR_ID_EM_MISC_DM_SELF_REGISTER_PORT"/>
    #endif
        <MENUITEM_ID>MENU_ID_EM_MISC_DM_SELF_REGISTER_RESULT</MENUITEM_ID>

        <MENUITEM id = "MENU_ID_EM_MISC_DM_SELF_REGISTER_DEVICE_NAME" str = "STR_ID_EM_MISC_DM_SELF_REGISTER_DEVICE_NAME"/>
        <MENUITEM_ID>MENU_ID_EM_MISC_DM_SELF_REGISTER_MASTER_SWITCH</MENUITEM_ID>
    </MENU>

#endif /* __MMI_EM_MISC_DM_REGISTER__ */    
<!----------------- DM Self Register Item End ----------------------------->

<!----------------- Misc. | DM Self Register --------------------------------------->
#ifdef __MMI_EM_MISC_DM_REGISTER__
    <!----------------- String Id ----------------------------------------->      
    <STRING id = "STR_ID_EM_MISC_DM_SELF_REGISTER_RESULT">Register result</STRING>
    <STRING id = "STR_ID_EM_MISC_DM_SELF_REGISTER_RESULT_DUAL">Dual result</STRING>
    <STRING id = "STR_ID_EM_MISC_DM_SELF_REGISTER_RESULT_SIM">SIM card</STRING>

    <!----------------- Menu Id ------------------------------------------->  
    
#ifdef __MMI_DUAL_SIM_MASTER__                   
    <MENU id = "MENU_ID_EM_MISC_DM_SELF_REGISTER_RESULT" type = "APP_SUB" str = "STR_ID_EM_MISC_DM_SELF_REGISTER_RESULT">
        <MENU id = "MENU_ID_EM_MISC_DM_SELF_REGISTER_RESULT_DUAL" type = "APP_SUB" str = "STR_ID_EM_MISC_DM_SELF_REGISTER_RESULT_DUAL" flag = "RADIO">
            <MENUSET_ID>MENUSET_TRUE_FALSE</MENUSET_ID>
        </MENU>
        <MENUITEM id = "MENU_ID_EM_MISC_DM_SELF_REGISTER_RESULT_SIM" str = "STR_ID_EM_MISC_DM_SELF_REGISTER_RESULT_SIM"/>
    </MENU>
#else
    <MENU id = "MENU_ID_EM_MISC_DM_SELF_REGISTER_RESULT" type = "APP_SUB" str = "STR_ID_EM_MISC_DM_SELF_REGISTER_RESULT" flag = "RADIO">
        <MENUSET_ID>MENUSET_TRUE_FALSE</MENUSET_ID>
    </MENU>
#endif  /* __MMI_EM_MISC_DM_REGISTER__ */
    <MENU id = "MENU_ID_EM_MISC_DM_SELF_REGISTER_MASTER_SWITCH" type = "APP_SUB" str = "STR_ID_EM_MISC_DM_SELF_REGISTER_MASTER_SWITCH" flag = "RADIO">
        <MENUSET_ID>MENUSET_TRUE_FALSE</MENUSET_ID>
    </MENU>
    

#endif /* __MMI_EM_MISC_DM_REGISTER__ */   
<!----------------- DM Self Register Item End ----------------------------->


<!----------------- Misc. | DCD Network Paramter ------------------------------>
#ifdef __MMI_EM_MISC_DCD__   
    <!----------------- Screen Id ----------------------------------------->    
    <SCREEN id = "GRP_ID_EM_MISC_DCD_NW_PARAM"/>
    
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_MISC_DCD_NW_PARAM">DCD NW parameter</STRING>
    <STRING id = "STR_ID_EM_MISC_DCD_NW_PARAM_APN">APN</STRING>
    <STRING id = "STR_ID_EM_MISC_DCD_NW_PARAM_GATEWAY">Gateway</STRING>
    <STRING id = "STR_ID_EM_MISC_DCD_NW_PARAM_PORT">Port</STRING>
    <STRING id = "STR_ID_EM_MISC_DCD_NW_PARAM_ADD_CHAN_URL">Add channel</STRING>
    <STRING id = "STR_ID_EM_MISC_DCD_NW_PARAM_DEL_CHAN_URL">Del channel</STRING>
    <STRING id = "STR_ID_EM_MISC_DCD_NW_PARAM_REFRESH_URL">Refresh url</STRING>
    <STRING id = "STR_ID_EM_MISC_DCD_NW_PARAM_HELP_URL">Help url</STRING>
    <STRING id = "STR_ID_EM_MISC_DCD_NW_PARAM">DCD NW parameter</STRING>
#ifdef __MMI_OP01_DCD_V30__    
    <STRING id = "STR_ID_EM_MISC_DCD_STORAGE_SWITCH">DCD Storage Switch</STRING>
#endif
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_MISC_DCD_NW_PARAM" type = "APP_SUB" str = "STR_ID_EM_MISC_DCD_NW_PARAM">
    </MENU>

#ifdef __MMI_OP01_DCD_V30__
    <MENU id = "MENU_ID_EM_MISC_DCD_STORAGE_SWITCH" type = "APP_SUB" str = "STR_ID_EM_MISC_DCD_STORAGE_SWITCH" flag = "RADIO">
        <MENUSET_ID>MENUSET_ON_OFF</MENUSET_ID>
    </MENU>
#endif
#endif /* __MMI_EM_MISC_DCD__ */    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | FOTA Debug ---------------------------------------->
#ifdef __MMI_EM_MISC_FOTA_DEBUG__   
    <!----------------- Screen Id -----------------------------------------> 
    <SCREEN id = "SCR_ID_EM_MISC_FOTA_DEBUG_UPGRADE_ANIMATION"/>

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_MISC_F0TA_DEBUG">FOTA debug</STRING>
    <STRING id = "STR_ID_EM_MISC_FOTA_DEBUG_DOWNLOAD_NOW">Download now</STRING>
    <STRING id = "STR_ID_EM_MISC_FOTA_DEBUG_QUESTION_MARK">?</STRING>
    <STRING id = "STR_ID_EM_MISC_FOTA_DEBUG_DOWNLOADING">Downloading</STRING>
    <STRING id = "STR_ID_EM_MISC_FOTA_DEBUG_UPGRADE_NOW">Done!\n\nupgrade now?</STRING>
    <STRING id = "STR_ID_EM_MISC_FOTA_DEBUG_SHUTDOWN_NOTIFY">Shutdown for upgrade</STRING>
    <STRING id = "STR_ID_EM_MISC_FOTA_DEBUG_RESULT_FILE_NOT_FOUND">File not found</STRING>
    <STRING id = "STR_ID_EM_MISC_FOTA_DEBUG_RESULT_ACCESS_DENIED">Access denied</STRING>
    <STRING id = "STR_ID_EM_MISC_FOTA_DEBUG_RESULT_SOC_ERROR">Network error</STRING>
    <STRING id = "STR_ID_EM_MISC_FOTA_DEBUG_RESULT_TIMEOUT">Time out</STRING>
    <STRING id = "STR_ID_EM_MISC_FOTA_DEBUG_RESULT_AUTH_FAIL">Authentication fail</STRING>
    <STRING id = "STR_ID_EM_MISC_FOTA_DEBUG_RESULT_FINAL_CHECK_FAIL">Checksum fail</STRING>  
   
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_MISC_F0TA_DEBUG" type = "APP_SUB" str = "STR_ID_EM_MISC_F0TA_DEBUG">
    </MENU>
    
#endif /* __MMI_EM_MISC_FOTA_DEBUG__ */    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | DM Add APN ---------------------------------------->
#ifdef __MMI_EM_MISC_DM_ADD_APN__  
    <!----------------- Screen id ----------------------------------------->
    <SCREEN id "SCR_ID_EM_MISC_DM_ADD_APN_SEL_SERVER"/>
    <SCREEN id "SCR_ID_EM_MISC_DM_ADD_APN_SEL_APN"/>
    <SCREEN id "SCR_ID_EM_MISC_DM_ADD_APN_WAITING"/>
    
    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_EM_MISC_DM_ADD_APN">DM add APN</STRING>
    <STRING id = "STR_ID_EM_DM_ADD_APN_DM_SERVERS">DM servers</STRING>
    <STRING id = "STR_ID_EM_DM_ADD_APN_SEL_APN">Select APN</STRING>
    <STRING id = "STR_ID_EM_DM_ADD_APN_CMWAP">CMWAP</STRING>
    <STRING id = "STR_ID_EM_DM_ADD_APN_CMNET">CMNET</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_MISC_DM_ADD_APN" type = "APP_SUB" str = "STR_ID_EM_MISC_DM_ADD_APN">
    </MENU>
#endif /* __MMI_EM_MISC_DM_ADD_APN__ */    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | Video Parameter ----------------------------------->
#ifdef __MMI_EM_MISC_VIDEO_PARAM__   
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_MISC_VIDEO_PARAM">Video parameter</STRING>
    <STRING id = "STR_ID_EM_MISC_VIDEO_PARAM_CBR_FUNC">CBR FUNC</STRING>
    <STRING id = "STR_ID_EM_MISC_VIDEO_PARAM_DCT_CUT">DCT CUT</STRING>
    <STRING id = "STR_ID_EM_MISC_VIDEO_PARAM_MD_THRE">MD THRE</STRING>
    <STRING id = "STR_ID_EM_MISC_VIDEO_PARAM_MBRC_THRE">MBRC THRE</STRING>
    <STRING id = "STR_ID_EM_MISC_VIDEO_PARAM_MB_BIT_BUDGET">MB BIT BUDGET</STRING>
    <STRING id = "STR_ID_EM_MISC_VIDEO_PARAM_MBQ">MBQ</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_MISC_VIDEO_PARAM" type = "APP_SUB" str = "STR_ID_EM_MISC_VIDEO_PARAM">
        <MENUITEM id = "MENU_ID_EM_MISC_VIDEO_PARAM_CBR_FUNC" str = "STR_ID_EM_MISC_VIDEO_PARAM_CBR_FUNC"/>
        <MENUITEM id = "MENU_ID_EM_MISC_VIDEO_PARAM_DCT_CUT" str = "STR_ID_EM_MISC_VIDEO_PARAM_DCT_CUT"/>
        <MENUITEM id = "MENU_ID_EM_MISC_VIDEO_PARAM_MD_THRE" str = "STR_ID_EM_MISC_VIDEO_PARAM_MD_THRE"/>
        <MENUITEM id = "MENU_ID_EM_MISC_VIDEO_PARAM_MBRC_THRE" str = "STR_ID_EM_MISC_VIDEO_PARAM_MBRC_THRE"/>
        <MENUITEM id = "MENU_ID_EM_MISC_VIDEO_PARAM_MB_BIT_BUDGET" str = "STR_ID_EM_MISC_VIDEO_PARAM_MB_BIT_BUDGET"/>
        <MENUITEM id = "MENU_ID_EM_MISC_VIDEO_PARAM_MBQ" str = "STR_ID_EM_MISC_VIDEO_PARAM_MBQ"/>
    </MENU>

#endif /* __MMI_EM_MISC_DM_ADD_APN__ */    
<!----------------- EM Item End ----------------------------------------------->


#if 0
<!----------------- Misc. | Auto Test Setting --------------------------------->
#ifdef __MMI_FM_AUTO_TEST__
    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id = "SCR_ID_EM_MISC_AUTO_TEST_SETTING"/>
    <SCREEN id = "SCR_ID_EM_MISC_AUTO_TEST_ADD"/>
    <SCREEN id = "SCR_ID_EM_AUTO_TEST_ENTER_PRIORITY"/>
    <SCREEN id = "SCR_ID_EM_MISC_AUTO_TEST_CHANGE_PRIORITY"/>

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_MISC_AUTO_TEST_SETTING">Auto test list</STRING>
    <STRING id = "STR_ID_EM_AUTO_TEST_ADD">Add from list</STRING>
    <STRING id = "STR_ID_EM_AUTO_TEST_CHANGE_PRIORITY">Change priority</STRING>
    <STRING id = "STR_ID_EM_AUTO_TEST_REMOVE">Remove</STRING>
    <STRING id = "STR_ID_EM_AUTO_TEST_ENTER_PRIORITY">Enter priority</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_MISC_AUTO_TEST_SETTING" type = "APP_SUB" str = "STR_ID_EM_MISC_AUTO_TEST_SETTING">
    </MENU>

    <MENU id = "MENU_ID_EM_AUTO_TEST_OPTIONS" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM id = "MENU_ID_EM_AUTO_TEST_ADD" str = "STR_ID_EM_AUTO_TEST_ADD"/>
        <MENUITEM id = "MENU_ID_EM_AUTO_TEST_CHANGE_PRIORITY" str = "STR_ID_EM_AUTO_TEST_CHANGE_PRIORITY"/>
        <MENUITEM id = "MENU_ID_EM_AUTO_TEST_REMOVE" str = "STR_ID_EM_AUTO_TEST_REMOVE"/>
    </MENU>
#endif/*__MMI_FM_AUTO_TEST__*/    
<!----------------- EM Item End ----------------------------------------------->
#endif




<!----------------- Misc. | Software Patch ------------------------------------>
#ifdef __MMI_EM_SW_PATCH__   
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_MISC_SOFTWARE_PATCH">SW patch select</STRING>
    <STRING id = "STR_ID_EM_MISC_SOFTWARE_PATCH_DSP">DSP Patch</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_MISC_SOFTWARE_PATCH" type = "APP_SUB" str = "STR_ID_EM_MISC_SOFTWARE_PATCH">
    </MENU>

#endif /* __MMI_EM_SW_PATCH__ */    
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Level3 Menu | JAVA ---------------------------------------->
#ifdef __MMI_EM_JAVA_SUPPORT__
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_JAVA">Java</STRING>

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_JAVA" type = "APP_SUB" str = "STR_ID_EM_JAVA">
#ifdef __J2ME__    
    <MENUITEM_ID>MENU_ID_JAVA_EM_TCK</MENUITEM_ID>
#endif
#ifdef __MMI_EM_JAVA_HEAP_SIZE_SETTING__
    <MENUITEM_ID>MENU_ID_EM_JAVA_HEAP_SIZE_SETTING</MENUITEM_ID>
#endif
#ifdef __MMI_EM_MISC_JAVA_PERFORMANCE__    
    <MENUITEM_ID>MENU_ID_EM_JAVA_PERFORMANCE</MENUITEM_ID>
#endif
#ifdef __MMI_EM_MISC_JUI_DEBUG__
    <MENUITEM_ID>MENU_ID_EM_JUI_DEBUG</MENUITEM_ID>
#endif
    </MENU>
    
#endif /* __MMI_EM_JAVA_SUPPORT__ */    
<!----------------- EM Item End ----------------------------------------------->

#ifdef __MMI_EM_MISC_TOUCH_SCREEN__ 
<!----------------- Level3 Menu | SSP Settings ---------------------------------------->
    <STRING id = "STR_ID_EM_MAIN_SSP_SETTINGS">SSP Setting</STRING>
    <STRING id = "STR_ID_EM_LIST_SSP_SETTING">List SSP setting</STRING>
    <STRING id = "STR_ID_EM_EDITOR_SSP_SETTING">Editor SSP setting</STRING>

    <STRING id = "STR_ID_EM_LIST_DEFAULT_VALUE">Restore List setting</STRING>
    <STRING id = "STR_ID_EM_EDITOR_DEFAULT_VALUE">Restore Editor setting</STRING>
    <STRING id = "STR_ID_EM_LIST_SSP_DATA">List SSP Data</STRING>
    <STRING id = "STR_ID_EM_EDITOR_SSP_DATA">Editor SSP Data</STRING>

    <!----------------- Menu Id ------------------------------------------->
    <SCREEN id = "SCR_ID_EM_SSP_STATUS"></SCREEN>

    <!----------------- Menu Id ------------------------------------------->
    <MENUITEM id = "MENU_ID_SSP_SETTINGS" str = "STR_ID_EM_MAIN_SSP_SETTINGS"/>
    <MENUITEM id = "MENU_ID_LIST_SSP_SETTING" str = "STR_ID_EM_LIST_SSP_SETTING"/>
    <MENUITEM id = "MENU_ID_EDITOR_SSP_SETTING" str = "STR_ID_EM_EDITOR_SSP_SETTING"/>
    <MENUITEM id = "MENU_ID_LIST_SSP_DEFAULT_VALUE" str = "STR_ID_EM_LIST_DEFAULT_VALUE"/>
    <MENUITEM id = "MENU_ID_EDITOR_SSP_DEFAULT_VALUE" str = "STR_ID_EM_EDITOR_DEFAULT_VALUE"/>
    
    <MENU id = "MENU_ID_SSP_SETTINGS_OPTION" type = "APP_SUB">
        <MENUITEM_ID>MENU_ID_LIST_SSP_SETTING</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EDITOR_SSP_SETTING</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_LIST_SSP_DEFAULT_VALUE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EDITOR_SSP_DEFAULT_VALUE</MENUITEM_ID>
    </MENU>


<!----------------- Level3 Menu | Misc->Touch Screen->Pen event test ------------------>

    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_EM_MISC_TOUCH_SCREEN_PEN_EVENT">Pen event test</STRING>
    
    <!----------------- Menu Id ------------------------------------------->
    <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_PEN_EVENT" str="STR_ID_EM_MISC_TOUCH_SCREEN_PEN_EVENT"/>
    <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_PEN_EVENT_EXIT" str="STR_GLOBAL_EXIT"/>

    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id="SCR_ID_EM_MISC_TOUCH_SCREEN_PEN_EVENT"/>
    <SCREEN id="GRP_ID_EM_MISC_TOUCH_SCREEN_PEN_EVENT"/>

    
    
    <!----------------- Level3 Menu | Misc->Touch Screen->Accuracy test ----------------------->

    <!----------------- String Id ----------------------------------------->
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_ACCURACY_TEST">Accuracy test</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_AUTO">Auto test all</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_ACCURACY">Pen down location</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_LINEAR_SLOPE">Linear-slope</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_LINEAR_HORIZONTAL">Linear-horizontal</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_LINEAR_VERTICAL">Linear-vertical</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_CURCUIT">Circuit</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_RECT">Rectangle</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_FUNNEL">Funnel</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_2RECT">2 Rectangle</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_JITTER">Jitter</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_FAIL">Fail-distance:</STRING>
    
    
    <!----------------- Menu Id ------------------------------------------->
    <MENU id="MENU_ID_EM_MISC_TOUCH_SCREEN_ACCURACY" type = "APP_SUB" str="STR_ID_EM_MISC_TOUCH_SCREEN_ACCURACY_TEST">
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_AUTO" str="STR_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_AUTO"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_ACCURACY" str="STR_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_ACCURACY"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_LINEAR_SLOPE" str="STR_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_LINEAR_SLOPE"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_LINEAR_HORIZONTAL" str="STR_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_LINEAR_HORIZONTAL"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_LINEAR_VERTICAL" str="STR_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_LINEAR_VERTICAL"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_CURCUIT" str="STR_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_CURCUIT"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_RECT" str="STR_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_RECT"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_FUNNEL" str="STR_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_FUNNEL"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_2RECT" str="STR_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_2RECT"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_JITTER" str="STR_ID_EM_MISC_TOUCH_SCREEN_ACC_TEST_JITTER"/>
    </MENU>   

    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id="GRP_ID_EM_MISC_TOUCH_SCREEN_ACCUCARY"/>
    <SCREEN id="SCR_ID_EM_MISC_TOUCH_SCREEN_ACC_ACCURACY"/>
    
    
<!----------------- Level3 Menu | Misc->Touch Screen->parameters setting ----------------------->

    <!----------------- String Id ----------------------------------------->
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING">Driver param setting</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_DEBOUNCE_TIME">Debounce time</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_CALIB_CHECK_OFFSET">Calibration check offset</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MIN_PEN_MOVE_OFFSET">Min pen move offset</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MAX_HANDWRITE_OFFSET">Max hand writing offset</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MAX_NON_HANDWRITE_OFFSET">Max nonhand writing offset</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MAX_STROKE_OFFSET">Max stroke offset</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MULTI_POING_SELECTION">Multiple point selection</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_PRESSURE_HIGN_THRESHOLD">Pressure high threshold</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_PRESSURE_CHECK_BOUNDARY">Pressure check boundary</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_PRESSURE_SHIFTING">Pressure shifting</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_BORDER_PASS_CRITERION">Border pass criterion</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_NON_BORDER_PASS_CRITERION">Non-Border pass criterion</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_BORDER_RANGE">Border range</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_ITEM_INTERVAL">Item interval</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_DUMP_SCREEN">Dump screen</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RESERVE_PARAM_1">Reserve parameter 1</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RESERVE_PARAM_2">Reserve parameter 2</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RESERVE_PARAM_3">Reserve parameter 3</STRING>
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RANGE">Range:</STRING>
    
    <!----------------- Menu Id ------------------------------------------->
    <MENU id="MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING" type = "APP_SUB" str="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING">
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_DEBOUNCE_TIME" str="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_DEBOUNCE_TIME"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_CALIB_CHECK_OFFSET" str="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_CALIB_CHECK_OFFSET"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MIN_PEN_MOVE_OFFSET" str="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MIN_PEN_MOVE_OFFSET"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MAX_HANDWRITE_OFFSET" str="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MAX_HANDWRITE_OFFSET"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MAX_NON_HANDWRITE_OFFSET" str="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MAX_NON_HANDWRITE_OFFSET"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MAX_STROKE_OFFSET" str="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MAX_STROKE_OFFSET"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MULTI_POING_SELECTION" str="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_MULTI_POING_SELECTION"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_PRESSURE_HIGN_THRESHOLD" str="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_PRESSURE_HIGN_THRESHOLD"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_PRESSURE_CHECK_BOUNDARY" str="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_PRESSURE_CHECK_BOUNDARY"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_PRESSURE_SHIFTING" str="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_PRESSURE_SHIFTING"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_BORDER_PASS_CRITERION" str="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_BORDER_PASS_CRITERION"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_NON_BORDER_PASS_CRITERION" str="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_NON_BORDER_PASS_CRITERION"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_BORDER_RANGE" str="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_BORDER_RANGE"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_ITEM_INTERVAL" str="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_ITEM_INTERVAL"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_DUMP_SCREEN" str="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_DUMP_SCREEN"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RESERVE_PARAM_1" str="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RESERVE_PARAM_1"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RESERVE_PARAM_2" str="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RESERVE_PARAM_2"/>
        <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RESERVE_PARAM_3" str="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING_RESERVE_PARAM_3"/>
    </MENU> 

    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id="GRP_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING"/>
    
    <!----------------- Level3 Menu | Misc->Touch Screen->parameters setting ----------------------->

    <!----------------- String Id ----------------------------------------->
    <STRING id="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_RESET">Driver param reset</STRING>
    
    <!----------------- Menu Id ------------------------------------------->
    <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_RESET" str="STR_ID_EM_MISC_TOUCH_SCREEN_PARAM_RESET"/>

#ifdef __MMI_EM_MISC_MULTI_TOUCH__
<!----------------- Level3 Menu | Misc->Touch Screen->Multi touch ---------------------------------------->

    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_EM_MISC_TOUCH_SCREEN_MULTI_TOUCH">Multi touch</STRING>

    <!----------------- Menu Id ------------------------------------------->
    <MENUITEM id="MENU_ID_EM_MISC_TOUCH_SCREEN_MULTI_TOUCH" str="STR_ID_EM_MISC_TOUCH_SCREEN_MULTI_TOUCH"/>

    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id="SCR_ID_EM_MISC_TOUCH_SCREEN_MULTI_TOUCH"/>
    <SCREEN id="GRP_ID_EM_MISC_TOUCH_SCREEN_MULTI_TOUCH"/>
#endif /* __MMI_EM_MISC_MULTI_TOUCH__ */

#endif

<!----------------- JAVA | Heap Size Setting ---------------------------------->
#ifdef __MMI_EM_JAVA_HEAP_SIZE_SETTING__
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_JAVA_HEAP_SIZE_SETTING">Java heep size</STRING>
    <STRING id = "STR_ID_EM_MISC_JAVA_HEAP_SIZE_384K">384K</STRING>
    <STRING id = "STR_ID_EM_MISC_JAVA_HEAP_SIZE_448K">448K</STRING>
    <STRING id = "STR_ID_EM_MISC_JAVA_HEAP_SIZE_512K">512K</STRING>
    <STRING id = "STR_ID_EM_MISC_JAVA_HEAP_SIZE_768K">768K</STRING>
    <STRING id = "STR_ID_EM_MISC_JAVA_HEAP_SIZE_1024K">1024K</STRING>
    <STRING id = "STR_ID_EM_MISC_JAVA_HEAP_SIZE_1024_1_256K">1024*1 + 256K</STRING>
    <STRING id = "STR_ID_EM_MISC_JAVA_HEAP_SIZE_1024_1_512K">1024*2 + 512K</STRING>
    <STRING id = "STR_ID_EM_MISC_JAVA_HEAP_SIZE_1024_2K">1024*2K</STRING>
    <STRING id = "STR_ID_EM_MISC_JAVA_HEAP_SIZE_1024_3K">1024*3K</STRING>
    <STRING id = "STR_ID_EM_MISC_JAVA_HEAP_SIZE_1024_4K">1024*4K</STRING>
    <STRING id = "STR_ID_EM_MISC_JAVA_HEAP_SIZE_1024_6K">1024*6K</STRING>
    <STRING id = "STR_ID_EM_MISC_JAVA_HEAP_SIZE_1024_8K">1024*8K</STRING>

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_JAVA_HEAP_SIZE_SETTING" type = "APP_SUB" str = "STR_ID_EM_JAVA_HEAP_SIZE_SETTING" flag = "RADIO">
        <MENUITEM id = "MENU_ID_EM_JAVA_HEAP_SIZE_384K" str = "STR_ID_EM_MISC_JAVA_HEAP_SIZE_384K"/>
        <MENUITEM id = "MENU_ID_EM_JAVA_HEAP_SIZE_448K" str = "STR_ID_EM_MISC_JAVA_HEAP_SIZE_448K"/>
        <MENUITEM id = "MENU_ID_EM_JAVA_HEAP_SIZE_512K" str = "STR_ID_EM_MISC_JAVA_HEAP_SIZE_512K"/>
        <MENUITEM id = "MENU_ID_EM_JAVA_HEAP_SIZE_768K" str = "STR_ID_EM_MISC_JAVA_HEAP_SIZE_768K"/>
        <MENUITEM id = "MENU_ID_EM_JAVA_HEAP_SIZE_1024K" str = "STR_ID_EM_MISC_JAVA_HEAP_SIZE_1024K"/>
        <MENUITEM id = "MENU_ID_EM_JAVA_HEAP_SIZE_1024_1_256K" str = "STR_ID_EM_MISC_JAVA_HEAP_SIZE_1024_1_256K"/>
        <MENUITEM id = "MENU_ID_EM_JAVA_HEAP_SIZE_1024_1_512K" str = "STR_ID_EM_MISC_JAVA_HEAP_SIZE_1024_1_512K"/>
        <MENUITEM id = "MENU_ID_EM_JAVA_HEAP_SIZE_1024_2K" str = "STR_ID_EM_MISC_JAVA_HEAP_SIZE_1024_2K"/>
        <MENUITEM id = "MENU_ID_EM_JAVA_HEAP_SIZE_1024_3K" str = "STR_ID_EM_MISC_JAVA_HEAP_SIZE_1024_3K"/>
        <MENUITEM id = "MENU_ID_EM_JAVA_HEAP_SIZE_1024_4K" str = "STR_ID_EM_MISC_JAVA_HEAP_SIZE_1024_4K"/>
        <MENUITEM id = "MENU_ID_EM_JAVA_HEAP_SIZE_1024_6K" str = "STR_ID_EM_MISC_JAVA_HEAP_SIZE_1024_6K"/>
        <MENUITEM id = "MENU_ID_EM_JAVA_HEAP_SIZE_1024_8K" str = "STR_ID_EM_MISC_JAVA_HEAP_SIZE_1024_8K"/>   
    </MENU>
    
#endif /* __MMI_EM_JAVA_HEAP_SIZE_SETTING__ */    
<!----------------- EM Item End ----------------------------------------------->



<!----------------- JAVA | Performance ---------------------------------------->
#ifdef __MMI_EM_MISC_JAVA_PERFORMANCE__
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_JAVA_PERFORMANCE">Java Performance</STRING>
    <STRING id="STR_ID_EM_JAVA_PERFORMANCE_OVERALL_TEST">Over all test</STRING>
    <STRING id="STR_ID_EM_JAVA_PERFORMANCE_WITHOUT_INT">CPU Test Without INT</STRING>
    <STRING id="STR_ID_EM_JAVA_RUNNING_WARNING">Please termanite running Java first!</STRING>  
 
		<STRING id="STR_ID_EM_JAVA_PERFORMANCE_DRAW_STRING_TEST">Draw String Test</STRING>
		<STRING id="STR_ID_EM_JAVA_PERFORMANCE_CPU_TEST">CPU Test</STRING>
		<STRING id="STR_ID_EM_JAVA_PERFORMANCE_MEM_TEST">Memory Test</STRING>
		<STRING id="STR_ID_EM_JAVA_PERFORMANCE_UPDATE_TIME">Test Over</STRING>
		<STRING id="STR_ID_EM_JAVA_PERFORMANCE_TEST_OVER">Over All Test</STRING>
		<STRING id="STR_ID_EM_JAVA_PERFORMANCE_TEST_RUNNING">Test is running...</STRING>
		<STRING id="STR_ID_EM_JAVA_PERFORMANCE_WITHOUT_INT_HINT">Disable interrupt will crash</STRING>

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_JAVA_PERFORMANCE" type = "APP_SUB" str = "STR_ID_EM_JAVA_PERFORMANCE">
			<MENUITEM_ID>MENU_ID_EM_JAVA_PERFORMANCE_OVERALL_TEST</MENUITEM_ID>
			<MENUITEM_ID>MENU_ID_EM_CPU_TEST_WITHOUT_INT</MENUITEM_ID>
    </MENU>
		<MENUITEM id="MENU_ID_EM_JAVA_PERFORMANCE_OVERALL_TEST" str="STR_ID_EM_JAVA_PERFORMANCE_OVERALL_TEST" />
		<MENUITEM id="MENU_ID_EM_CPU_TEST_WITHOUT_INT" str="STR_ID_EM_JAVA_PERFORMANCE_WITHOUT_INT" />
#endif /* __MMI_EM_MISC_JAVA_PERFORMANCE__ */    
<!----------------- EM Item End ----------------------------------------------->



<!----------------- JAVA | JUI Debug ------------------------------------------>
#ifdef __MMI_EM_MISC_JUI_DEBUG__
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_MISC_JUI_DEBUG">Jui debug</STRING> 
    <STRING id = "STR_ID_EM_MISC_JUI_DEBUG_DRAW_STRING">Draw String</STRING>
    <STRING id = "STR_ID_EM_MISC_JUI_DEBUG_BLT_LCD">BLT LCD</STRING>
    <STRING id = "STR_ID_EM_MISC_JUI_DEBUG_DECODE_BMP">Decode BMP</STRING>
    <STRING id = "STR_ID_EM_MISC_JUI_DEBUG_DECODE_GIF">Decode GIF</STRING>
    <STRING id = "STR_ID_EM_MISC_JUI_DEBUG_DECODE_JPEG">Decode JPEG</STRING>
    <STRING id = "STR_ID_EM_MISC_JUI_DEBUG_DECODE_WBMP">Decode WBMP</STRING>
    <STRING id = "STR_ID_EM_MISC_JUI_DEBUG_DRAW_TRANSFORM">Draw Transform</STRING>
    <STRING id = "STR_ID_EM_MISC_JUI_DEBUG_BLT_COUNT">BLT Count</STRING>
    <STRING id = "STR_ID_EM_MISC_JUI_DEBUG_DRAW_RECT">Draw Rectangle</STRING>
    <STRING id = "STR_ID_EM_MISC_JUI_DEBUG_DRAW_ARC">Draw Arc</STRING>
    <STRING id = "STR_ID_EM_MISC_JUI_DEBUG_DRAW_TRI">Draw Triangle</STRING>
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_JUI_DEBUG" type = "APP_SUB" str = "STR_ID_EM_MISC_JUI_DEBUG">
    </MENU>
    
#endif /* __MMI_EM_MISC_JUI_DEBUG__ */    
<!----------------- EM Item End ----------------------------------------------->

<!----------------- MED Memory Setting ------------------------------------------>
#ifdef __MMI_EM_MISC_MEDIA_MEMORY_SETTING__
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_MISC_MEDIA_MEMORY_SETTING">MED Memory Setting</STRING> 
    <STRING id = "STR_ID_EM_MISC_MEDIA_MEMORY_SETTING_DEBUG">Debug Info</STRING> 
    <STRING id = "STR_ID_EM_MISC_MEDIA_MEMORY_SETTING_DEBUG_ON">ON</STRING> 
    <STRING id = "STR_ID_EM_MISC_MEDIA_MEMORY_SETTING_DEBUG_OFF">OFF</STRING> 


    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "EM_MISC_MEDIA_MEMORY_SETTING_MENUID" type = "APP_SUB" str = "STR_ID_EM_MISC_MEDIA_MEMORY_SETTING">
        <MENUITEM_ID>EM_MISC_MEDIA_MEMORY_SETTING_DEBUG_INFO_MENUID</MENUITEM_ID>    
    </MENU>    
    
    <MENU id = "EM_MISC_MEDIA_MEMORY_SETTING_DEBUG_INFO_MENUID" type = "APP_SUB" str = "STR_ID_EM_MISC_MEDIA_MEMORY_SETTING_DEBUG"/>
#endif /* __MMI_EM_MISC_MEDIA_MEMORY_SETTING__ */    
<!----------------- EM Item End ----------------------------------------------->

<!----------------- Misc | Rf desense ----------------------------------------->
#ifdef __MMI_EM_RF_DESENSE_TEST__
    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id  = "SCR_ID_EM_MISC_RF_DESENSE_LIST"/>
    <SCREEN id  = "SCR_ID_EM_MISC_RF_DESENSE_EDIT"/>

    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_EM_MISC_RF_DESENSE_TEST">RF desense test</STRING>
    <STRING id = "STR_ID_EM_MISC_RF_DESENSE_CUR_MODE">Current RF desense mode</STRING>
    <STRING id = "STR_ID_EM_MISC_RF_DESENSE_SEL_MODE">Please select RF desense mode:</STRING>
    <STRING id = "STR_ID_EM_MISC_RF_DESENSE_BAD_MODE">Mode should between</STRING>

    <!----------------- Menu Id   ----------------------------------------->
    <MENUITEM id = "MENU_ID_EM_MISC_RF_DESENSE" str = "STR_ID_EM_MISC_RF_DESENSE_TEST"/>
#endif /* __MMI_EM_RF_DESENSE_TEST__ */
<!----------------- Misc | Rf desense end ------------------------------------->


<!----------------- X download  ----------------------------------------------->
#ifdef __MMI_EM_MISC_X_DOWNLOAD__
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_MISC_X_DOWNLOAD">Card Download Test</STRING> 
    <STRING id = "STR_ID_EM_MISC_X_DOWNLOAD_FULL_DOWNLOAD">Full Download</STRING> 
    <STRING id = "STR_ID_EM_MISC_X_DOWNLOAD_FULL_DOWNLOAD_CONFIRM">Perform the test and reboot?</STRING> 

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_MISC_X_DOWNLOAD" type = "APP_SUB" str = "STR_ID_EM_MISC_X_DOWNLOAD">
        <MENUITEM id = "MENU_ID_EM_MISC_X_DOWNLOAD_FULL_DOWNLOAD" str = "STR_ID_EM_MISC_X_DOWNLOAD_FULL_DOWNLOAD"/>
    </MENU>    
#endif /* __MMI_EM_MISC_X_DOWNLOAD__ */    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Level3 Menu | MRE ---------------------------------------->
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_MRE">MRE</STRING>

    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id  = "SCR_ID_EM_MISC_MRE_INFO"></SCREEN>
    
    <!----------------- Menu Id -------------------------------------------> 
#ifndef __MMI_MAINLCD_96X64__           
    <MENUITEM id = "MENU_ID_EM_MRE" str = "STR_ID_EM_MRE"/>
#endif
      
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | Power on CPU query ------------------------------->
#ifdef __MMI_EM_MISC_POWER_ON_CPU_QUERY__
    <!----------------- String Id ----------------------------------------->  
    <STRING id = "STR_ID_EM_MISC_POWER_ON_CPU_QUERY">Power on CFU query</STRING>
    <STRING id = "STR_ID_EM_MISC_POWER_ON_DEFAULT">Default</STRING>
    <STRING id = "STR_ID_EM_MISC_POWER_ON_NO_QUERY">Power on no query</STRING>
    <STRING id = "STR_ID_EM_MISC_POWER_ON_QUERY">Power on query</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_MISC_POWER_ON_CPU_QUERY" type = "APP_SUB" str = "STR_ID_EM_MISC_POWER_ON_CPU_QUERY" flag = "RADIO">
        <MENUITEM id = "MENU_ID_EM_MISC_POWER_ON_DEFAULT" str = "STR_ID_EM_MISC_POWER_ON_DEFAULT"/>
        <MENUITEM id = "MENU_ID_EM_MISC_POWER_ON_NO_QUERY" str = "STR_ID_EM_MISC_POWER_ON_NO_QUERY"/>
        <MENUITEM id = "MENU_ID_EM_MISC_POWER_ON_QUERY" str = "STR_ID_EM_MISC_POWER_ON_QUERY"/>
    </MENU>

#endif  /*__MMI_EM_MISC_POWER_ON_CPU_QUERY__ */    
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Level2 Menu | Debug Info ---------------------------------->
#if defined(__MMI_EM_LAST_EXCEPTION__) || defined(__MMI_EM_DEBUG_INFO_SYS_STATS__) || defined(__MMI_EM_DEBUG_INFO_DRIVE_LETTER__)
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_DEBUG_INFO">Debug info</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_DEBUG_INFO" type = "APP_SUB" str = "STR_ID_EM_DEBUG_INFO">
    #ifdef __MMI_EM_LAST_EXCEPTION__
	    <MENUITEM_ID>MENU_ID_EM_DEBUG_LAST_EXCEPTION</MENUITEM_ID>
    #endif
	    
    #ifdef __MMI_EM_DEBUG_INFO_SYS_STATS__
	    <MENUITEM_ID>MENU_ID_EM_DEBUG_SYS_STATS</MENUITEM_ID>    
    #endif

    #ifdef __MMI_EM_DEBUG_INFO_DRIVE_LETTER__
	    <MENUITEM_ID>MENU_ID_MMI_EM_DEBUG_DRIVE_LETTER</MENUITEM_ID>    
    #endif
    </MENU>
#endif /*defined(__MMI_EM_LAST_EXCEPTION__) || defined(__MMI_EM_DEBUG_INFO_SYS_STATS__) || defined(__MMI_EM_DEBUG_INFO_DRIVE_LETTER__)*/    
    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Debug Info | Last Exception ------------------------------->
#ifdef __MMI_EM_LAST_EXCEPTION__
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_DEBUG_LAST_EXCEPTION">Last exception</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_DEBUG_LAST_EXCEPTION" type = "APP_SUB" str = "STR_ID_EM_DEBUG_LAST_EXCEPTION">
    </MENU>
#endif/*__MMI_EM_LAST_EXCEPTION__*/    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Debug Info | System Stats --------------------------------->
#if defined(__MMI_EM_DEBUG_INFO_SYS_STATS__)

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_DEBUG_SYS_STATS">System stats</STRING>
    <STRING id = "STR_ID_EM_DEBUG_WRITE_SYS_STATS">Write stats</STRING>
    <STRING id = "STR_ID_EM_SAVING_STAT_PWROFF">System stats</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_DEBUG_SYS_STATS" type = "APP_SUB" str = "STR_ID_EM_DEBUG_SYS_STATS">
        <MENUITEM id = "MENU_ID_EM_WRITE_SYS_STATS" str = "STR_ID_EM_DEBUG_WRITE_SYS_STATS"/>
    </MENU>

#endif /* (__MMI_EM_DEBUG_INFO_SYS_STATS__) */
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Debug Info | Drive Letter --------------------------------->
#ifdef __MMI_EM_DEBUG_INFO_DRIVE_LETTER__

    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id="SCR_ID_MMI_EM_DEBUG_DRIVE_LETTER"/>

    <!----------------- String Id ----------------------------------------->             
    <STRING id="STR_ID_MMI_EM_DEBUG_DRIVE_LETTER">Drive letter</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id="MENU_ID_MMI_EM_DEBUG_DRIVE_LETTER" type="APP_SUB" str="STR_ID_MMI_EM_DEBUG_DRIVE_LETTER">
    </MENU>
    
#endif /* __MMI_EM_DEBUG_INFO_DRIVE_LETTER__ */    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Iperf ----------------------------------------------------->
#ifdef __MMI_EM_IPERF__

    <!----------------- Timer Id ------------------------------------------>             

    <!----------------- Event Id ------------------------------------------>             

    <!----------------- Screen Id ----------------------------------------->             
    <SCREEN id="GRP_ID_IPERF"/>
    <SCREEN id="SCR_ID_EM_IPERF_SETTING"/>
    <SCREEN id="SCR_ID_EM_IPERF_REPORT"/>

    <!----------------- String Id ----------------------------------------->             
    <STRING id="STR_ID_EM_IPERF"> "Iperf" </STRING>
    <STRING id="STR_ID_EM_IPERF_IPERF_SETTING"> "Iperf Setting" </STRING>
    <STRING id="STR_ID_EM_IPERF_TCP_TESTING"> "TCP Testing" </STRING>
    <STRING id="STR_ID_EM_IPERF_UDP_TESTING"> "UDP Testing" </STRING>
    <STRING id="STR_ID_EM_IPERF_TCP_SETTING"> "TCP Setting" </STRING>
    <STRING id="STR_ID_EM_IPERF_UDP_SETTING"> "UDP Setting" </STRING>
    <STRING id="STR_ID_EM_IPERF_CLIENT_SERVER"> "Client/Server" </STRING>
    //<STRING id="STR_ID_EM_IPERF_RW_FILE"> "R/W File" </STRING>
    <STRING id="STR_ID_EM_IPERF_CLIENT"> "Client" </STRING>
    <STRING id="STR_ID_EM_IPERF_SERVER"> "Server" </STRING>
    <STRING id="STR_ID_EM_IPERF_FADDR"> "Faddr" </STRING>
    <STRING id="STR_ID_EM_IPERF_LEN"> "Len" </STRING>
    <STRING id="STR_ID_EM_IPERF_PORT"> "Port" </STRING>
    <STRING id="STR_ID_EM_IPERF_WINDOW"> "Window" </STRING>
    <STRING id="STR_ID_EM_IPERF_BUFFER"> "Buffer" </STRING>
    <STRING id="STR_ID_EM_IPERF_MSS"> "MSS" </STRING>
    <STRING id="STR_ID_EM_IPERF_BANDWIDTH"> "Bandwidth (Kbps)" </STRING>
    <STRING id="STR_ID_EM_IPERF_NUM_BYTES"> "Num(Bytes)" </STRING>
    <STRING id="STR_ID_EM_IPERF_TIME_SECS"> "Time(Secs)" </STRING>
    <STRING id="STR_ID_EM_IPERF_TOS"> "ToS" </STRING>
    //<STRING id="STR_ID_EM_IPERF_DUAL"> "Dual Test" </STRING>
    //<STRING id="STR_ID_EM_IPERF_BEST_EFFORT"> "BEST_EFFORT" </STRING>
    //<STRING id="STR_ID_EM_IPERF_BACK_GROUND"> "BACK_GROUND" </STRING>
    //<STRING id="STR_ID_EM_IPERF_VIDEO"> "VIDEO" </STRING>
    //<STRING id="STR_ID_EM_IPERF_VOICE"> "VOICE" </STRING>
    <STRING id="STR_ID_EM_IPERF_LEN_ERR"> "Invalid Length" </STRING>
    <STRING id="STR_ID_EM_IPERF_PORT_ERR"> "Invalid Port" </STRING>
    <STRING id="STR_ID_EM_IPERF_WINDOW_ERR"> "Invalid Window" </STRING>
    <STRING id="STR_ID_EM_IPERF_BUFFER_ERR"> "Invalid Buffer" </STRING>
    <STRING id="STR_ID_EM_IPERF_MSS_ERR"> "Invalid MSS" </STRING>
    <STRING id="STR_ID_EM_IPERF_BANDWIDTH_ERR"> "Invalid Bandwidth" </STRING>
    <STRING id="STR_ID_EM_IPERF_NUM_BYTES_ERR"> "Invalid Num(Bytes)" </STRING>
    <STRING id="STR_ID_EM_IPERF_TIME_SECS_ERR"> "Invalid Num(Bytes)" </STRING>
    <STRING id="STR_ID_EM_IPERF_FADDR_ERR"> "Invalid Faddr" </STRING>
    <STRING id="STR_ID_EM_IPERF_SERVER_DUAL_ERR"> "Not Support Server Dual Mode Testing" </STRING>
    <STRING id="STR_ID_EM_IPERF_CNF_FAILED_ERR"> "Confirm Failed" </STRING>
    <STRING id="STR_ID_EM_IPERF_PROGRESSING"> "Progressing" </STRING>
    <STRING id="STR_ID_EM_IPERF_REPORT"> "Iperf Report" </STRING>
    <STRING id="STR_ID_EM_IPERF_TEST_FAILED_ERR"> "Test Failed" </STRING>
    <STRING id="STR_ID_EM_IPERF_RUN"> "Run" </STRING>
    <STRING id="STR_ID_EM_IPERF_RESET_SETTINGS"> "Reset settings" </STRING>
    <STRING id="STR_ID_EM_IPERF_DUAL_TEST_OFF"> "Dual Test Off" </STRING>
    <STRING id="STR_ID_EM_IPERF_DUAL_TEST_ON"> "Dual Test On" </STRING>

    <!----------------- Image Id ------------------------------------------>

    <!----------------- Audio Id ------------------------------------------>      

    <!----------------- Menu Id ------------------------------------------->
    <MENUITEM id="MENU_ID_EM_IPERF" str="STR_ID_EM_IPERF"/>
    <MENUITEM id="MENU_ID_EM_IPERF_TCP" str="STR_ID_EM_IPERF_TCP_TESTING"/>
    <MENUITEM id="MENU_ID_EM_IPERF_UDP" str="STR_ID_EM_IPERF_UDP_TESTING"/>
    <MENUITEM id="MENU_ID_EM_IPERF_DTCNT" str="STR_GLOBAL_DATA_CONN_SETTING"/>
    <MENUITEM id="MENU_ID_EM_IPERF_OPTIONS_RESET_SETTINGS" str="STR_ID_EM_IPERF_RESET_SETTINGS"/>

    <!--Menu Tree Area-->
    /* Type Support:OPTION, APP_MAIN, APP_SUB, default value is ORIGINAL */
    /* default="TRUE" means this item is active item when use CSK.       */
    /* type="SEPARATOR" means that CUI will show a separator here        */

    <MENU id="MENU_ID_EM_IPERF_APP" type="APP_MAIN" str="STR_ID_EM_IPERF">
        <MENUITEM_ID>MENU_ID_EM_IPERF_TCP</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_IPERF_UDP</MENUITEM_ID>
    #ifdef __PLUTO_MMI_PACKAGE__
        <MENUITEM_ID>MENU_ID_EM_IPERF_DTCNT</MENUITEM_ID>
    #endif /* __PLUTO_MMI_PACKAGE__ */
        <MENUITEM_ID>MENU_ID_EM_IPERF_OPTIONS_RESET_SETTINGS</MENUITEM_ID>
    </MENU>

#endif /* __MMI_EM_IPERF__ */
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Level2 Menu | Bluetooth ----------------------------------->
#ifdef __MMI_BT_SUPPORT__

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_BLUETOOTH">Bluetooth</STRING>

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_BLUETOOTH" type = "APP_SUB" str = "STR_ID_EM_BLUETOOTH">
    #ifdef __MMI_EM_BT_GENERAL_TEST__
        <MENUITEM_ID>MENU_ID_EM_BT_GENERAL_TEST</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_EM_BT_RF_TEST__
        <MENUITEM_ID>MENU_ID_EM_BT_RF_TEST</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_BT_GET_CHIP_VERION__
        <MENUITEM_ID>MENU_ID_EM_BT_GET_CHIP_VERSION</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_BT_UPF_IOT_TEST__
        <MENUITEM_ID>MENU_ID_EM_BT_UPF_IOT_TEST</MENUITEM_ID>
    #endif

	#ifdef __MMI_EM_BT_BQB_SUPPORT__
		<MENUITEM_ID>MENU_ID_EM_BT_BQB_TEST</MENUITEM_ID>
	#endif
    </MENU>
    
#endif /* __MMI_BT_SUPPORT__ */    
<!----------------- Bluetooth Item End ----------------------------------------------->



<!----------------- Bluetooth | General Test --------------------------------->

    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_EM_BT_BD_ADDR">BD address</STRING>
    
#ifdef __MMI_EM_BT_GENERAL_TEST__
    <STRING id = "STR_ID_EM_BT_GENERAL_TEST">Genernal test</STRING>
    <STRING id = "STR_ID_EM_BT_ENTRY_TEST">Start testing</STRING>
    <STRING id = "STR_ID_EM_BT_ENTRY_TEST_RESERVED">Reserved</STRING>
    <STRING id = "STR_ID_EM_BT_LOOKBACK">Far end lookback</STRING>
    <STRING id = "STR_ID_EM_BT_BD_ADDR">BD address</STRING>
    <STRING id = "STR_ID_EM_BT_BD_PASSWORD">BD password</STRING>
    <STRING id = "STR_ID_EM_BT_EXIT_TEST_MODE">Exit test moded</STRING>

#ifdef __MMI_EM_BT_AUDIO_CONN__
    <STRING id = "STR_ID_EM_BT_ADD_AUDIO_CONNECTION">Add audio conn</STRING>
    <STRING id = "STR_ID_EM_BT_REMOVE_AUDIO_CONNECTION">Remove audio conn</STRING>
#endif /* __MMI_EM_BT_AUDIO_CONN__ */ 

#if defined(__MMI_BT_SUPPORT__) && defined(__MMI_AVRCP_DEBUG__) && defined(__MMI_AVRCP_CT_SUPPORT__)
    <STRING id = "STR_ID_EM_BT_AVRCP_CMD_LIST">AVRCP command</STRING>
#endif

#ifdef __MMI_EM_BT_AVRCP_CONNECT_TG_ACTIVELY__
    <STRING id = "STR_ID_EM_BT_AVRCP_CONNECT_TG_ACTIVELY">AVRCP connect TG actively</STRING>
#endif
    
#ifdef __MMI_EM_BT_BQB_SUPPORT__
	<STRING id = "STR_ID_EM_BT_BQB_TEST">Bluetooth BQB Test</STRING>

	<MENU id = "MENU_ID_EM_BT_BQB_TEST" type = "APP_SUB" str = "STR_ID_EM_BT_BQB_TEST">
	#ifdef __MMI_EM_BT_BQB_HID_SUPPORT__
		<MENUITEM_ID>MENU_ID_EM_BT_BQB_TEST_HID</MENUITEM_ID>
	#endif
	</MENU>


	#ifdef __MMI_EM_BT_BQB_HID_SUPPORT__
	<STRING id = "STR_ID_EM_BT_BQB_TEST_HID">HID</STRING>
	<STRING id = "STR_ID_EM_BT_HID_CONNECTABLE">Connectable</STRING>
	<STRING id = "STR_ID_EM_BT_HID_CONNECT">Connect remote device</STRING>
	<STRING id = "STR_ID_EM_BT_HID_TRANS_DATA_LEFT">Left</STRING>
	<STRING id = "STR_ID_EM_BT_HID_TRANS_DATA_RIGHT">Right</STRING>
	<STRING id = "STR_ID_EM_BT_HID_TRANS_DATA_UP">Up</STRING>
	<STRING id = "STR_ID_EM_BT_HID_TRANS_DATA_DOWN">Down</STRING>
	<STRING id = "STR_ID_EM_BT_HID_TEST_SCREEN_TITLE">BT HID TEST</STRING>
	<STRING id = "STR_ID_EM_BT_HID_CONNECTABLE_SCREEN_TITLE">Connectable Mode</STRING>
	<STRING id = "STR_ID_EM_BT_HID_CONNECT_SCREEN_TITLE">Connect</STRING>
	<STRING id = "STR_ID_EM_BT_HID_LIMIT_DISCOVER">"Limit Discover"</STRING>

	<SCREEN id = "SCR_ID_EM_BT_HID_TEST"></SCREEN>
	<SCREEN id = "SCR_ID_EM_BT_HID_CONNECTABLE"></SCREEN>
	<SCREEN id = "SCR_ID_EM_BT_HID_CONNECTED"></SCREEN>
	<SCREEN id = "SCR_ID_EM_BT_HID_WAIT"></SCREEN>
	<SCREEN id = "SCR_ID_EM_BT_HID_LIMIT_DISCOVER_MODE"></SCREEN>

	<MENUITEM id = "MENU_ID_EM_BT_BQB_TEST_HID" str = "STR_ID_EM_BT_BQB_TEST_HID"/>

	<MENU id = "MENU_ID_EM_BT_BQB_TEST_HID_SCREEN" type = "APP_SUB" str = "STR_ID_EM_BT_BQB_TEST_HID">
		<MENUITEM id = "MENU_ID_EM_BT_HID_CONNECTABLE" str = "STR_ID_EM_BT_HID_CONNECTABLE"/>
		<MENUITEM id = "MENU_ID_EM_BT_HID_CONNECT" str = "STR_ID_EM_BT_HID_CONNECT"/>
		<MENUITEM id = "MENU_ID_EM_BT_HID_LIMIT_DISCOVER" str = "STR_ID_EM_BT_HID_LIMIT_DISCOVER"/>
	</MENU>

	<MENU id = "MENU_ID_EM_BT_HID_TRANS_DATA_SCREEN" type = "APP_SUB">
		<MENUITEM id = "MENU_ID_EM_BT_HID_TRANS_DATA_LEFT" str = "STR_ID_EM_BT_HID_TRANS_DATA_LEFT"/>
		<MENUITEM id = "MENU_ID_EM_BT_HID_TRANS_DATA_RIGHT" str = "STR_ID_EM_BT_HID_TRANS_DATA_RIGHT"/>
		<MENUITEM id = "MENU_ID_EM_BT_HID_TRANS_DATA_UP" str = "STR_ID_EM_BT_HID_TRANS_DATA_UP"/>
		<MENUITEM id = "MENU_ID_EM_BT_HID_TRANS_DATA_DOWN" str = "STR_ID_EM_BT_HID_TRANS_DATA_DOWN"/>
	</MENU>
	#endif
#endif

    <!----------------- Menu Id ------------------------------------------->
 #ifdef __MMI_EM_BT_GENERAL_TEST__
    <MENU id = "MENU_ID_EM_BT_GENERAL_TEST" type = "APP_SUB" str = "STR_ID_EM_BT_GENERAL_TEST">
    
    #ifdef __MMI_EM_BT_GENERAL_TEST__
        <MENUITEM id = "MENU_ID_EM_BT_ENTRY_TEST" str = "STR_ID_EM_BT_ENTRY_TEST"/>
    #endif

    #ifdef __MMI_EM_BT_AUDIO_CONN__
        <MENUITEM id = "MENU_ID_EM_BT_ADD_AUDIO_CONNECTION" str = "STR_ID_EM_BT_ADD_AUDIO_CONNECTION"/>    
        <MENUITEM id = "MENU_ID_EM_BT_REMOVE_AUDIO_CONNECTION" str = "STR_ID_EM_BT_REMOVE_AUDIO_CONNECTION"/>
    #endif /* __MMI_EM_BT_AUDIO_CONN__ */    
    
    #ifdef __MMI_EM_BT_GENERAL_TEST__
        <MENUITEM id = "MENU_ID_EM_BT_ENTRY_LOOKBACK" str = "STR_ID_EM_BT_LOOKBACK"/>
        <MENUITEM id = "MENU_ID_EM_BT_EXIT_TEST_MODE" str = "STR_ID_EM_BT_EXIT_TEST_MODE"/>
    #endif
        
    #if defined(__MMI_BT_SUPPORT__) && defined(__MMI_AVRCP_DEBUG__) && defined(__MMI_AVRCP_CT_SUPPORT__)
        <MENUITEM id = "MENU_ID_EM_BT_AVRCP_CMD_LIST" str = "STR_ID_EM_BT_AVRCP_CMD_LIST"/>
    #endif
    
    #ifdef __MMI_EM_BT_AVRCP_CONNECT_TG_ACTIVELY__
        <MENUITEM_ID>MENU_ID_EM_BT_AVRCP_CONNECT_TG_ACTIVELY</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_EM_BT_GENERAL_TEST__
        <MENUITEM id = "MENU_ID_EM_BT_ENTRY_TEST_RESERVED" str = "STR_ID_EM_BT_ENTRY_TEST_RESERVED"/>
    #endif
    </MENU>
#endif
#endif /* __MMI_EM_BT_GENERAL_TEST__ */
    
<!----------------- Bluetooth | Avrcp connect tg actively -------------------->
#ifdef __MMI_EM_BT_AVRCP_CONNECT_TG_ACTIVELY__       
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_BT_AVRCP_CONNECT_TG_ACTIVELY" type = "APP_SUB" str = "STR_ID_EM_BT_AVRCP_CONNECT_TG_ACTIVELY">
        <MENUSET_ID>MENUSET_ON_OFF</MENUSET_ID>
    </MENU>

#endif /* __MMI_EM_BT_AVRCP_CONNECT_TG_ACTIVELY__ */    
<!----------------- Avrcp connect tg actively Item End ------------------------>



<!----------------- Bluetooth | RF Test --------------------------------------->
#ifdef __MMI_EM_BT_RF_TEST__  /* may need move to RF Test Tool */
    <!----------------- Screen Id ----------------------------------------->  
    <SCREEN id = "SCR_ID_EM_BT_RF_TEST_RESLUT_SCRN"></SCREEN>
    <SCREEN id = "SCR_ID_EM_BT_NON_SIGNALING_RX_RET_SCRN"></SCREEN>
    
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_BT_RF_TEST">Bluetooth RF Test</STRING>
    <STRING id = "STR_ID_EM_DEVICE_BT_RF_TEST_TX">TX Test</STRING>
    <STRING id = "STR_ID_EM_DEVICE_BT_RF_TEST_RX">RX Test</STRING>
    <STRING id = "STR_ID_EM_BT_RF_TEST_NON_SIGNALING_RX">Non_Signaling Rx Test</STRING>   
    <STRING id = "STR_ID_EM_DEVICE_BT_RF_TEST_MODE">Enter Test Mode</STRING>

    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_NO_HOPING">No hoping</STRING>
    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_HOPIN">Hoping</STRING>
    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_CHANNEL">Channel</STRING>
    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_CTRL_PWR_LEVEL">Ctrl pwr lvl</STRING>
    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE">Packet type</STRING>
    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_DH1">DH 1</STRING>
    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_DH3">DH 3</STRING>
    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_DH5">DH 5</STRING>
    
    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_DM1">DM 1</STRING>
    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_DM3">DM 3</STRING>
    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_DM5">DM 5</STRING>
    
    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_2DH1">2DH 1</STRING>
    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_2DH3">2DH 3</STRING>
    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_2DH5">2DH 5</STRING>
    
    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_3DH1">3DH 1</STRING>
    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_3DH3">3DH 3</STRING>
    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_3DH5">3DH 5</STRING>

    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_PATTERN_TYPE">Pattern Type</STRING>
    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_PATTERN_TYPE_1">0000</STRING>
    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_PATTERN_TYPE_2">1111</STRING>
    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_PATTERN_TYPE_3">1010</STRING>
    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_PATTERN_TYPE_4">Pseudo Random</STRING>
    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_PATTERN_TYPE_5">11110000</STRING>

	<STRING id = "STR_ID_EM_DEV_BT_RF_TEST_BT_ADDR">BT addr(0x+8)</STRING>
    
    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_PACKET_TYPE_NON_MOD">Non-modulate</STRING>
    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_DATA_LEN">Data len</STRING>
    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_POLL_PERIOD">Poll period</STRING>
    <STRING id = "STR_ID_EM_DEV_BT_RF_TEST_TURN_OFF_BT">Turn off BT first!</STRING>

    <!----------------- Menu Id ------------------------------------------->             
    <MENUITEM id = "MENU_ID_EM_BT_RF_TEST" str = "STR_ID_EM_BT_RF_TEST"/>
    <MENU id = "MENU_ID_EM_BT_RF_TEST_LIST" type = "APP_SUB" str = "STR_ID_EM_BT_RF_TEST">
        <MENUITEM id = "MENU_ID_EM_DEVICE_BT_RF_TEST_TX" str = "STR_ID_EM_DEVICE_BT_RF_TEST_TX"/>
        <MENUITEM id = "MENU_ID_EM_DEVICE_BT_RF_TEST_RX" str = "STR_ID_EM_DEVICE_BT_RF_TEST_RX"/>
        <MENUITEM id = "MENU_ID_EM_BT_RF_TEST_NON_SIGNALING_RX" str = "STR_ID_EM_BT_RF_TEST_NON_SIGNALING_RX"/>
        <MENUITEM id = "MENU_ID_EM_DEVICE_BT_RF_TEST_BD_ADDR" str = "STR_ID_EM_BT_BD_ADDR"/>
        <MENUITEM id = "MENU_ID_EM_DEVICE_BT_RF_TEST_MODE" str = "STR_ID_EM_DEVICE_BT_RF_TEST_MODE"/>
    </MENU>

#endif /* __MMI_EM_BT_RF_TEST__ */    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Bluetooth | Get Chip Version ------------------------------>
#ifdef __MMI_EM_BT_GET_CHIP_VERION__ 
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_BT_GET_CHIP_VERSION">Get chip version</STRING>

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_BT_GET_CHIP_VERSION" type = "APP_SUB" str = "STR_ID_EM_BT_GET_CHIP_VERSION">
    </MENU>

#endif /* __MMI_EM_BT_GET_CHIP_VERION__ */    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Bluetooth | UPF IOT Test ---------------------------------->
#ifdef __MMI_EM_BT_UPF_IOT_TEST__ 
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_BT_UPF_IOT_TEST">Bluetooth UPF test</STRING>

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_BT_UPF_IOT_TEST" type = "APP_SUB" str = "STR_ID_EM_BT_UPF_IOT_TEST">
    </MENU>

#endif /* __MMI_EM_BT_UPF_IOT_TEST__ */    

<!----------------- EM Item End ----------------------------------------------->





<!----------------- Level2 Menu | Profiling ----------------------------------->
    <SCREEN id = "GRP_ID_EM_MISC_MEDIA_MEMORY_SETTING"></SCREEN>

#ifdef __MMI_EM_PROFILING__
    <!----------------- String Id -----------------------------------------> 
    <STRING id = "STR_ID_EM_PROFILING">Profiling</STRING>

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_PROFILING" type = "APP_SUB" str = "STR_ID_EM_PROFILING">

    #ifdef __MMI_EM_PROFILING_MULTIMEDIA_PROFILING__
        <MENUITEM_ID>MENU_ID_EM_PROFILING_MULTIMEIDA</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_EM_PROFILING_GDI_PROFILING__
        <MENUITEM_ID>MENU_ID_EM_PROFILING_GDI</MENUITEM_ID>
    #endif

    #ifdef __MMI_INTERACTIVE_PROFILNG__
        <MENUITEM_ID>MENU_ID_EM_PROFILING_FRAMEWORK</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_UI_BENCHMARK__
        <MENUITEM_ID>MENU_ID_EM_PROFILING_UI_BENCHMARK</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_MEMORY_MONITOR__
        <MENUITEM_ID>MENU_ID_EM_PROFILING_MEMORY_MONITOR</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_PROFILING_MEMORY_STATISTIC</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_EM_PROFILING_VENUS_DEBUG_PANEL__
        <MENUITEM_ID>MENU_ID_EM_PROFILING_VENUS_DEBUG_PANEL</MENUITEM_ID>
    #endif

    #ifdef __MMI_EM_PROFILING_FS_TEST__
        <MENUITEM_ID>MENU_ID_EM_PROFILING_FS_TEST</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_CSB_BROWSER__
        <MENUITEM_ID>MENU_ID_EM_PROFILING_CSB_BROWSER</MENUITEM_ID>
    #endif

    #if defined(__MMI_EM_MISC_TOUCH_SCREEN__) && defined(__COSMOS_MMI__)
        <MENUITEM_ID>MENU_ID_EM_PROFILING_GESTURE_TEST</MENUITEM_ID>
    #endif   
    
    #ifdef __MMI_EM_PROFILING_SWLA__
		<MENUITEM_ID>MENU_ID_EM_PROFILING_SWLA</MENUITEM_ID>
    #endif
    
    </MENU>
#endif /* __MMI_EM_PROFILING__ */
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Profiling | SWLA ----------------------------->
    #ifdef __MMI_EM_PROFILING_SWLA__

    <!----------------- Screen Id ----------------------------------------->             
    <SCREEN id="GRP_ID_EM_PROFILING_SWLA_RESULT_INFOR_GROUP"/>
    <SCREEN id="SCR_ID_EM_PROFILING_SWLA_RESULT_INFOR_SCRN"/>
    
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_PROFILING_SWLA">SWLA</STRING>
    <STRING id = "STR_ID_EM_PROFILING_SWLA_RESUILT_INFOR">SWLA result infor</STRING>

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_PROFILING_SWLA" type = "APP_SUB" str = "STR_ID_EM_PROFILING_SWLA" flag="RADIO">
    
        <MENUITEM id = "MENU_ID_EM_PROFILING_SWLA_ON" str = "STR_GLOBAL_ON"/>
        <MENUITEM id = "MENU_ID_EM_PROFILING_SWLA_OFF" str = "STR_GLOBAL_OFF"/>
    
    </MENU>

   #endif
<!----------------- EM Item End ----------------------------------------------->






<!----------------- Profiling | GDI Profiling -------------------------->
#ifdef __MMI_EM_PROFILING_GDI_PROFILING__
    <!----------------- Screen Id -----------------------------------------> 
    
    <SCREEN id = "GRP_ID_EM_PROFILING_GDI"></SCREEN>
    <SCREEN id = "SCR_ID_EM_PROFILING_GDI"></SCREEN>
    <SCREEN id = "SCR_ID_EM_PROFILING_IMGDEC_OPTION"></SCREEN>
    <SCREEN id = "SCR_ID_EM_PROFILING_IMGDEC_GEN_DISP"></SCREEN>
    <SCREEN id = "SCR_ID_EM_PROFILING_IMGDEC_FULL_DISP"></SCREEN>
    
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_PROFILING_GDI_PROFILING">GDI</STRING>
    <STRING id = "STR_ID_EM_PROFILING_IMAGE_DECODE">Image decode</STRING>
    <STRING id = "STR_ID_EM_PROFILING_SINGLE_FOLDER">Single Folder</STRING>
    <STRING id = "STR_ID_EM_PROFILING_SINGLE_FOLDER_ROTATE">Single Folder(ROTATE)</STRING>
    
    <STRING id = "STR_ID_EM_PROFILING_NO_CR">QA do NOT submit CR</STRING>
    <STRING id = "STR_ID_EM_PROFILING_NO_CR_DETAIL">Only for RD internal evaluation, not formal feature</STRING>
    
    <STRING id = "STR_ID_EM_PROFILING_PLATFORM_SPEED">Platform speed</STRING>
    <STRING id = "STR_ID_EM_PROFILING_GDI_BLT_SPEED">Blt speed</STRING>
    <STRING id = "STR_ID_EM_PROFILING_GDI_FLATTEN_SPEED">Flatten speed</STRING>
    <STRING id = "STR_ID_EM_PROFILING_GDI_LT_SPEED">Linear transform speed</STRING>
    <STRING id = "STR_ID_EM_PROFILING_GDI_DECODER_SPEED">Decoder speed</STRING>
    <STRING id = "STR_ID_EM_PROFILING_GDI_MISC_SPEED">Misc speed</STRING>
    <STRING id = "STR_ID_EM_PROFILING_GDI_BLT_FUNC">Blt functional</STRING>
    <STRING id = "STR_ID_EM_PROFILING_GDI_FLA_FUNC">Flatten functional</STRING>
    <STRING id = "STR_ID_EM_PROFILING_GDI_FRECT_FUNC">Fill rect functional</STRING>
    <STRING id = "STR_ID_EM_PROFILING_GDI_DECODER_FUNC">Decoder functional</STRING>
    <STRING id = "STR_ID_EM_PROFILING_GDI_TEMP">Temp</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_PROFILING_GDI" type = "APP_SUB" str = "STR_ID_EM_PROFILING_GDI_PROFILING">

    #ifdef __MMI_EM_PROFILING_IMG_DEC__
    	<MENUITEM_ID>MENU_ID_EM_PROFILING_IMAGE_DECODE</MENUITEM_ID>
    #endif /* __MMI_EM_PROFILING_IMG_DEC__ */
    
        <MENUITEM id = "MENU_ID_EM_PROFILING_HINT" str = "STR_ID_EM_PROFILING_NO_CR"/>
        <MENUITEM id = "MENU_ID_EM_PROFILING_PLATFORM_SPEED" str = "STR_ID_EM_PROFILING_PLATFORM_SPEED"/>
        <MENUITEM id = "MENU_ID_EM_PROFILING_GDI_BLT_SPEED" str = "STR_ID_EM_PROFILING_GDI_BLT_SPEED"/>
        <MENUITEM id = "MENU_ID_EM_PROFILING_GDI_FLATTEN_SPEED" str = "STR_ID_EM_PROFILING_GDI_FLATTEN_SPEED"/>
        <MENUITEM id = "MENU_ID_EM_PROFILING_GDI_LT_SPEED" str = "STR_ID_EM_PROFILING_GDI_LT_SPEED"/>
        <MENUITEM id = "MENU_ID_EM_PROFILING_GDI_DECODER_SPEED" str = "STR_ID_EM_PROFILING_GDI_DECODER_SPEED"/>
        <MENUITEM id = "MENU_ID_EM_PROFILING_GDI_MISC_SPEED" str = "STR_ID_EM_PROFILING_GDI_MISC_SPEED"/>
        <MENUITEM id = "MENU_ID_EM_PROFILING_GDI_BLT_FUNC" str = "STR_ID_EM_PROFILING_GDI_BLT_FUNC"/>
        <MENUITEM id = "MENU_ID_EM_PROFILING_GDI_FLA_FUNC" str = "STR_ID_EM_PROFILING_GDI_FLA_FUNC"/>
        <MENUITEM id = "MENU_ID_EM_PROFILING_GDI_FRECT_FUNC" str = "STR_ID_EM_PROFILING_GDI_FRECT_FUNC"/>
        <MENUITEM id = "MENU_ID_EM_PROFILING_GDI_DECODER_FUNC" str = "STR_ID_EM_PROFILING_GDI_DECODER_FUNC"/>
        <MENUITEM id = "MENU_ID_EM_PROFILING_GDI_TEMP" str = "STR_ID_EM_PROFILING_GDI_TEMP"/>

    </MENU>
    
    <TIMER id="TIMER_ID_EM_PROFILING_GDI_TEST"/>

	#if defined(__MMI_EM_PROFILING_IMG_DEC__)
    <MENU id = "MENU_ID_EM_PROFILING_IMAGE_DECODE" type = "APP_SUB" str = "STR_ID_EM_PROFILING_IMAGE_DECODE">
        <MENUITEM id = "MENU_ID_EM_PROFILING_IMAGE_DECODE_FOLDER" str = "STR_ID_EM_PROFILING_SINGLE_FOLDER"/>
        <MENUITEM id = "MENU_ID_EM_PROFILING_IMAGE_DECODE_FOLDER_ROTATE" str = "STR_ID_EM_PROFILING_SINGLE_FOLDER_ROTATE"/>    
    </MENU>
	#endif  

#endif /* __MMI_EM_PROFILING_GDI_PROFILING__ */    
<!----------------- EM Item End ----------------------------------------------->

<!----------------- Profiling | MultiMedia Profiling -------------------------->
#ifdef __MMI_EM_PROFILING_MULTIMEDIA_PROFILING__
    <!----------------- Screen Id -----------------------------------------> 
    
    <SCREEN id = "SCR_ID_EM_PROFILING_MULTIMEDIA"></SCREEN>
    <SCREEN id = "SCR_ID_EM_PROFILING_AUTO_PLAY"></SCREEN>
    <SCREEN id = "SCR_ID_EM_PROFILING_VDOREC_PLAY"></SCREEN>
    <SCREEN id = "SCR_ID_EM_PROFILING_VDOPLY_PLAY"></SCREEN>
    <SCREEN id = "SCR_ID_EM_PROFILING_CAMERA_PLAY"></SCREEN>
    <SCREEN id = "SCR_ID_EM_PROFILING_VDOREC_OPTION"></SCREEN>
    <SCREEN id = "SCR_ID_EM_PROFILING_CAMERA_OPTION"></SCREEN>
    <SCREEN id = "SCR_ID_EM_PROFILING_VDOREC_SETTING"></SCREEN>
    <SCREEN id = "SCR_ID_EM_PROFILING_CAMERA_SETTING"></SCREEN>
    <SCREEN id = "SCR_ID_EM_PROFILING_CAMERA_APP_CAPTURE"></SCREEN>
    <SCREEN id = "SCR_ID_EM_PROFILING_VTCS_LOOK_BACK"></SCREEN>    
    <SCREEN id = "GRP_ID_EM_PROFILING_VTCS_LOOK_BACK"></SCREEN> 
    
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_PROFILING_MULTIMEIDA_PROFILING">Multimedia</STRING>
    <STRING id = "STR_ID_EM_PROFILING_AUTO_PLAY">Auto play files</STRING>
    <STRING id = "STR_ID_EM_PROFILING_CAMERA">Camera</STRING>
    <STRING id = "STR_ID_EM_PROFILING_CAMERA_APP_CAPTURE">Camera app capture</STRING>
    <STRING id = "STR_ID_EM_PROFILING_VDOPLY">Video player</STRING>
    <STRING id = "STR_ID_EM_PROFILING_VDOREC">Video recorder</STRING>
    <STRING id = "STR_ID_EM_PROFILING_VTCS_LOOK_BACK">VTCS lookback mode</STRING>
    <STRING id = "STR_ID_EM_PROFILING_START">Start</STRING>
    
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_PROFILING_MULTIMEIDA" type = "APP_SUB" str = "STR_ID_EM_PROFILING_MULTIMEIDA_PROFILING">
    #ifndef __COSMOS_MMI_PACKAGE__
        <MENUITEM id = "MENU_ID_EM_PROFILING_AUTO_PLAY" str = "STR_ID_EM_PROFILING_AUTO_PLAY"/>
        
    #ifdef __MMI_CAMERA__
    	<MENUITEM_ID>MENU_ID_EM_PROFILING_CAMERA</MENUITEM_ID>
    	<MENUITEM_ID>MENU_ID_EM_PROFILING_CAMERA_APP_CAPTURE</MENUITEM_ID>
    #endif /* __MMI_CAMERA__ */
    
    #ifdef __MMI_VIDEO_PLAY_SUPPORT__
	    <MENUITEM id = "MENU_ID_EM_PROFILING_VDOPLY" str = "STR_ID_EM_PROFILING_VDOPLY"/> 
	#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
    #endif /* __COSMOS_MMI_PACKAGE__ */

    #ifdef __MMI_EM_PROFILING_VT_LOOKBACK__						
		<MENUITEM id = "MENU_ID_EM_PROFILING_VTCS_LOOK_BACK" str = "STR_ID_EM_PROFILING_VTCS_LOOK_BACK"/>
    #endif /* __MMI_EM_PROFILING_VT_LOOKBACK__ */
    </MENU>

	#ifdef __MMI_CAMERA__
    <MENU id = "MENU_ID_EM_PROFILING_CAMERA" type = "APP_SUB" str = "STR_ID_EM_PROFILING_CAMERA">
        <MENUITEM id = "MENU_ID_EM_PROFILING_CAMERA_START" str = "STR_ID_EM_PROFILING_START"/>
        <MENUITEM id = "MENU_ID_EM_PROFILING_CAMERA_SETTING" str = "STR_ID_EM_PROFILING_SETTING"/>    
    </MENU>

    <MENU id = "MENU_ID_EM_PROFILING_CAMERA_APP_CAPTURE" type = "APP_SUB" str = "STR_ID_EM_PROFILING_CAMERA_APP_CAPTURE">
        <MENUITEM id = "MENU_ID_EM_PROFILING_CAMERA_APP_CAPTURE_ON" str = "STR_GLOBAL_ON"/>
        <MENUITEM id = "MENU_ID_EM_PROFILING_CAMERA_APP_CAPTURE_OFF" str = "STR_GLOBAL_OFF"/>    
    </MENU>   
	#endif 

    #ifdef __MMI_VIDEO_RECORDER__
    <MENU id = "MENU_ID_EM_PROFILING_VDOREC" type = "APP_SUB" str = "STR_ID_EM_PROFILING_VDOREC">
        <MENUITEM id = "MENU_ID_EM_PROFILING_VDOREC_START" str = "STR_ID_EM_PROFILING_START"/>
        <MENUITEM id = "MENU_ID_EM_PROFILING_VDOREC_SETTING" str = "STR_ID_EM_PROFILING_SETTING"/>    
    </MENU>
    #endif  
#endif /* __MMI_EM_PROFILING_MULTIMEDIA_PROFILING__ */    
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Profiling | Framework Profiling -------------------------->
#ifdef __MMI_INTERACTIVE_PROFILNG__
    <!----------------- Screen Id -----------------------------------------> 
    <SCREEN id = "SCR_ID_EM_PROFILING_FRM"></SCREEN>
    
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_PROFILING_FRM">Frame profiling</STRING>
    <STRING id = "STR_ID_EM_PROFILING_FRM_DISPLAY_TIME_TEXT">Display Time</STRING>
    <STRING id = "STR_ID_EM_PROFILING_FRM_GDI_PROFILE_TEXT">GDI Image Profile</STRING>
    <STRING id = "STR_ID_EM_PROFILING_FRM_SCREEN_DELAY_TEXT">Screen Delay (ms)</STRING>
    <STRING id = "STR_ID_EM_PROFILING_FRM_MATRIX_DELAY_TEXT">Matrix Delay (ms)</STRING>
    <STRING id = "STR_ID_EM_PROFILING_FRM_LIST_DELAY_TEXT">List Delay (ms)</STRING>
    <STRING id = "STR_ID_EM_PROFILING_FRM_DELAY_OFFSET_TEXT">Time Offset (ms)</STRING>

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_PROFILING_FRAMEWORK" type = "APP_SUB" str = "STR_ID_EM_PROFILING_FRM">
    </MENU>
    
#endif /* __MMI_INTERACTIVE_PROFILNG__ */    
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Profiling | UI Benchmark ---------------------------------->
#ifdef __MMI_UI_BENCHMARK__

    <!----------------- Screen Id -----------------------------------------> 
    <SCREEN id = "SCR_ID_EM_PROFILING_UI_BENCHMARK"></SCREEN>
    <SCREEN id = "SCR_ID_EM_PROFILING_UI_BENCHMARK_RESULT"></SCREEN>

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_PROFILING_UI_BENCHMARK">UI benchmark</STRING>

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_PROFILING_UI_BENCHMARK" type = "APP_SUB" str = "STR_ID_EM_PROFILING_UI_BENCHMARK">
    </MENU>
    
#endif /* __MMI_UI_BENCHMARK__ */    
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Profiling | Memory Monitor -------------------------------->
#ifdef __MMI_MEMORY_MONITOR__

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_PROFILING_MEMORY_MONITOR">Memory monitor</STRING>
    <STRING id = "STR_ID_EM_PROFILING_MEMORY_MONITOR_OFF">Off</STRING>
    <STRING id = "STR_ID_EM_PROFILING_MEMORY_MONITOR_CONTROL_BUFFER">Control Buffer</STRING>
    <STRING id = "STR_ID_EM_PROFILING_MEMORY_MONITOR_ASM">ASM</STRING>
    #ifdef __MMI_VUI_ENGINE__
    <STRING id = "STR_ID_EM_PROFILING_MEMORY_MONITOR_VUI">VUI</STRING>
    #endif
    <STRING id = "STR_ID_EM_PROFILING_MEMORY_MONITOR_AFM">AFM</STRING>	

    <!----------------- Menu Id ------------------------------------------->
    <MENU id = "MENU_ID_EM_PROFILING_MEMORY_MONITOR" type = "APP_SUB" str = "STR_ID_EM_PROFILING_MEMORY_MONITOR" flag = "RADIO">
        <MENUITEM id = "MENU_ID_EM_PROFILING_MEMORY_MONITOR_OFF" str = "STR_ID_EM_PROFILING_MEMORY_MONITOR_OFF"/>
        <MENUITEM id = "MENU_ID_EM_PROFILING_MEMORY_MONITOR_CONTROL_BUFFER" str = "STR_ID_EM_PROFILING_MEMORY_MONITOR_CONTROL_BUFFER"/>
        <MENUITEM id = "MENU_ID_EM_PROFILING_MEMORY_MONITOR_ASM" str = "STR_ID_EM_PROFILING_MEMORY_MONITOR_ASM"/>
        #ifdef __MMI_VUI_ENGINE__
        <MENUITEM id = "MENU_ID_EM_PROFILING_MEMORY_MONITOR_VUI" str = "STR_ID_EM_PROFILING_MEMORY_MONITOR_VUI"/>
        #endif
        <MENUITEM id = "MENU_ID_EM_PROFILING_MEMORY_MONITOR_AFM" str = "STR_ID_EM_PROFILING_MEMORY_MONITOR_AFM"/>
    </MENU>

    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id="SCR_ID_EM_PROFILING_MEMORY_MONITOR"/>
    <SCREEN id="GRP_ID_EM_PROFILING_MEMORY_MONITOR"/>
    
#endif /* __MMI_MEMORY_MONITOR__ */    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Profiling | Memory Stat. ---------------------------------->
#ifdef __MMI_MEMORY_MONITOR__

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_PROFILING_MEMORY_STATISTIC">Memory statistic</STRING>

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_PROFILING_MEMORY_STATISTIC" type = "APP_SUB" str = "STR_ID_EM_PROFILING_MEMORY_STATISTIC">
    </MENU>

    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id="SCR_ID_EM_PROFILING_MEMORY_STATISTIC"/>
    <SCREEN id="GRP_ID_EM_PROFILING_MEMORY_STATISTIC"/>

    <!----------------- NVRAM CacheData ----------------------------------->
    <CACHEDATA type="byte" id="NVRAM_MEMORY_PROFILING_ENABLE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> MMI Memory </DESCRIPTION>
    </CACHEDATA>
    
#endif /* __MMI_MEMORY_MONITOR__ */    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Profiling | Venus Debug Panel ----------------------------->
#ifdef __MMI_EM_PROFILING_VENUS_DEBUG_PANEL__

    <!----------------- Screen Id ----------------------------------------->             
    <SCREEN id="SCR_ID_EM_PROFILING_VENUS_DEBUG_PANEL"/>
    <SCREEN id="GRP_ID_EM_PROFILING_VENUS_DEBUG_PANEL"/>

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_PROFILING_VENUS_DEBUG_PANEL">Venus debug panel</STRING>

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_PROFILING_VENUS_DEBUG_PANEL" type = "APP_SUB" str = "STR_ID_EM_PROFILING_VENUS_DEBUG_PANEL" flag="RADIO">
        <MENUITEM id = "MENU_ID_EM_PROFILING_VENUS_DEBUG_PANEL_ON" str = "STR_GLOBAL_ON"/>
        <MENUITEM id = "MENU_ID_EM_PROFILING_VENUS_DEBUG_PANEL_OFF" str = "STR_GLOBAL_OFF"/>
    </MENU>

    <!----------------- NVRAM CacheData ----------------------------------->
    <CACHEDATA type="byte" id="NVRAM_VENUS_DEBUG_PANEL_ENABLE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Venus debug panel </DESCRIPTION>
    </CACHEDATA>

#endif /* __MMI_EM_PROFILING_VENUS_DEBUG_PANEL__ */
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Profiling | FS Test -------------------------------------->
#ifdef __MMI_EM_PROFILING_FS_TEST__

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_PROFILING_FS_TEST">Fs test</STRING>

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_PROFILING_FS_TEST" type = "APP_SUB" str = "STR_ID_EM_PROFILING_FS_TEST">
    </MENU>
    
#endif /* __MMI_EM_PROFILING_FS_TEST__ */    
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Profiling | CSB Browser ----------------------------------->
#ifdef __MMI_CSB_BROWSER__

    <!----------------- String Id ----------------------------------------->
    /* IT */
    <STRING id = "STR_ID_EM_PROFILING_CSB_BROWSER">Category screen browser</STRING>

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_PROFILING_CSB_BROWSER" type = "APP_SUB" str = "STR_ID_EM_PROFILING_CSB_BROWSER">
    </MENU>
    
#endif /* __MMI_CSB_BROWSER__ */    
<!----------------- EM Item End ----------------------------------------------->

<!----------------- Profiling | Multimedia | xxx --------------------------------->
    <!----------------- Screen Id -----------------------------------------> 
    <SCREEN id = "GRP_ID_EM_PROFILING_AUTO_PLAY"></SCREEN>
    <SCREEN id = "GRP_ID_EM_PROFILING_VDOPLY"></SCREEN>
#if defined(__MMI_EM_PROFILING_VT_LOOKBACK__)
    <SCREEN id = "GRP_ID_EM_PROFILING_VTCS_LOOK_BACK"></SCREEN>
    <SCREEN id = "SCR_ID_EM_PROFILING_VTCS_LOOK_BACK"></SCREEN>
#endif    
#if defined( __MMI_EM_MISC_RECORDER_SETTING__)    
    <SCREEN id = "SCR_ID_EM_RECORDER_SETTING"></SCREEN>
    <SCREEN id = "GRP_ID_EM_MISC_RECORDER_SETTING"></SCREEN>
#endif    
    <SCREEN id = "GRP_ID_EM_PROFILING_CAMERA"></SCREEN>
    <SCREEN id = "GRP_ID_EM_PROFILING_CAMERA_APP_CAPTURE"></SCREEN>
    <SCREEN id = "GRP_ID_EM_PROFILING_IMAGE_DECODE"></SCREEN>
    <SCREEN id = "GRP_ID_EM_PROFILING_VDOREC"></SCREEN>
	
    <!----------------- String Id ------------------------------------------->   	
#if defined( __MMI_EM_MISC_RECORDER_SETTING__)
    <STRING id = "STR_ID_EM_MISC_RECORDER_SETTING">Recorder Setting</STRING>    
    <STRING id = "STR_ID_EM_MISC_RECORDER_SETTING_SOURCE">Recorder Source</STRING>   
    <STRING id = "STR_ID_EM_MISC_RECORDER_SETTING_SOURCE_YUV">YUV</STRING>        
    <STRING id = "STR_ID_EM_MISC_RECORDER_SETTING_SOURCE_RGB">MP4</STRING>    
    <STRING id = "STR_ID_EM_MISC_RECORDER_SETTING_MODE">Recorder Mode</STRING>      
    <STRING id = "STR_ID_EM_MISC_RECORDER_SETTING_MODE_REC">Normal</STRING>     
    <STRING id = "STR_ID_EM_MISC_RECORDER_SETTING_MODE_VT">VT</STRING> 
#if defined(__MMI_EM_MISC_RECORDER_PARAM_AJUST__)
    <STRING id = "STR_ID_EM_MISC_RECORDER_SETTING_PARAM_AJUST">Recorder Param Ajust</STRING> 
#endif     

    <MENU id="EM_MISC_RECORDER_SETTING_MENUID" type="APP_SUB" str="STR_ID_EM_MISC_RECORDER_SETTING">
        <MENUITEM_ID>EM_MISC_RECORDER_SETTING_SOURCE_MENUID</MENUITEM_ID>		
        <MENUITEM_ID>EM_MISC_RECORDER_SETTING_MODE_MENUID</MENUITEM_ID>	
    #if defined(__MMI_EM_MISC_RECORDER_PARAM_AJUST__)
        <MENUITEM_ID>MENU_ID_EM_MISC_RECORDER_SETTING_PARAM_AJUST</MENUITEM_ID>	
    #endif			
    </MENU>
    <MENUITEM id="EM_MISC_RECORDER_SETTING_SOURCE_MENUID" str="STR_ID_EM_MISC_RECORDER_SETTING_SOURCE"/> 
    <MENUITEM id="EM_MISC_RECORDER_SETTING_MODE_MENUID" str="STR_ID_EM_MISC_RECORDER_SETTING_MODE"/> 
    <MENUITEM id="EM_MISC_RECORDER_SETTING_RESOLUTION_MENUID" str="STR_ID_EM_MISC_RECORDER_SETTING_SOURCE"/> 
#if defined(__MMI_EM_MISC_RECORDER_PARAM_AJUST__)
    <MENUITEM id="MENU_ID_EM_MISC_RECORDER_SETTING_PARAM_AJUST" str="STR_ID_EM_MISC_RECORDER_SETTING_PARAM_AJUST"/> 
#endif
#endif

#if defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMERA__)
    <!----------------- String Id ------------------------------------------->   
    <STRING id = "STR_ID_EM_PROFILING_EXTRA_LAYER">Extra layer</STRING>
    <STRING id = "STR_ID_EM_PROFILING_ROTATE">Rotate</STRING>
    <STRING id = "STR_ID_EM_PROFILING_PLAY_SIZE">Play size</STRING>
    <STRING id = "STR_ID_EM_PROFILING_TVOUT_MODE">TV-Out mode</STRING>
    <STRING id = "STR_ID_EM_PROFILING_ROTATE_0">Rotate 0</STRING>
    <STRING id = "STR_ID_EM_PROFILING_ROTATE_90">Rotate 90</STRING>
    <STRING id = "STR_ID_EM_PROFILING_ROTATE_180">Rotate 180</STRING>
    <STRING id = "STR_ID_EM_PROFILING_ROTATE_270">Rotate 270</STRING>
    <STRING id = "STR_ID_EM_PROFILING_TV_FULL_SCREEN">Full screen</STRING>
    <STRING id = "STR_ID_EM_PROFILING_TV_LCD_SCREEN">LCD screen</STRING>
    <STRING id = "STR_ID_EM_PROFILING_SIZE_SQCIF">SQCIF (128x96)</STRING>
    <STRING id = "STR_ID_EM_PROFILING_SIZE_QCIF">SQCIF (128x96)</STRING>
    <STRING id = "STR_ID_EM_PROFILING_SIZE_CIF">CIF (352x288)</STRING>
    <STRING id = "STR_ID_EM_PROFILING_SIZE_QQVGA">QQVGA (160x120)</STRING>
    <STRING id = "STR_ID_EM_PROFILING_SIZE_QVGA">QVGA (320x240)</STRING>
    <STRING id = "STR_ID_EM_PROFILING_SIZE_VGA">VGA (640x480)</STRING>
    <STRING id = "STR_ID_EM_PROFILING_SIZE_LCD">LCD Size</STRING>
    <STRING id = "STR_ID_EM_PROFILING_RECORD_SIZE">Record Size</STRING>
    <STRING id = "STR_ID_EM_PROFILING_PREVIEW_SIZE">Preview Size</STRING>
    <STRING id = "STR_ID_EM_PROFILING_SETTING">Setting</STRING>
 
    <!----------------- Menu Id ------------------------------------------->

    <MENU id="MENU_ID_EM_PROFILING_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_EM_PROFILING_START</MENUITEM_ID>		
        <MENUITEM_ID>MENU_ID_EM_PROFILING_SETTING</MENUITEM_ID>			
    </MENU>
    <MENUITEM id="MENU_ID_EM_PROFILING_START" str="STR_GLOBAL_START"/> 
    <MENUITEM id="MENU_ID_EM_PROFILING_SETTING" str="STR_GLOBAL_SETTINGS"/> 
    
#endif /* defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMERA__) */
	
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Profiling | Gesture Test --------------------------------->
#if defined(__MMI_EM_MISC_TOUCH_SCREEN__) && defined(__COSMOS_MMI__)
    <!----------------- String Id ------------------------------------------->   
    <STRING id="STR_ID_EM_PROFILING_GESTURE_TEST">Gesture Test</STRING>

    <!----------------- Menu Id ------------------------------------------->	
    <MENU id="MENU_ID_EM_PROFILING_GESTURE_TEST" type="APP_SUB" str="STR_ID_EM_PROFILING_GESTURE_TEST">
    </MENU>

#endif /* defined(__MMI_EM_MISC_TOUCH_SCREEN__) && defined(__COSMOS_MMI__) */
<!----------------- EM Item End ----------------------------------------------->

<!----------------- Level2 Menu | RF Test Tool -------------------------------->
    <!----------------- Screen Id -----------------------------------------> 
    <SCREEN id = "SCR_ID_EM_DUALMODE_SWITCH_PROGRESS"/>

    <!----------------- String Id ----------------------------------------->  
#if defined(__MMI_EM_RF_GSM__) || defined(__MMI_EM_RF_WIFI__)
    <STRING id = "STR_ID_EM_RF_TEST_TOOL">RF test tool</STRING>
#endif 
    <STRING id = "STR_ID_EM_RF_TEST_GSM_CONFIRM_NOTIFY_TEST">Wifi must be off. Will power off after test.</STRING>  <!-- Engineer Mode RF Test GSM Menu Caption String-->

    <!----------------- Menu Id ------------------------------------------->    
#if defined(__MMI_EM_RF_GSM__) || defined(__MMI_EM_RF_WIFI__)
    <MENU id = "MENU_ID_EM_RF_TEST_TOOL" type = "APP_SUB" str = "STR_ID_EM_RF_TEST_TOOL">

    #ifdef __MMI_EM_RF_GSM__
        <MENUITEM_ID>MENU_ID_EM_RF_TEST_TOOL_GSM</MENUITEM_ID>
    #endif
    
    #ifdef __MMI_EM_RF_WIFI__
        <MENUITEM_ID>MENU_ID_EM_RF_TEST_TOOL_WIFI</MENUITEM_ID>
    #endif  
    </MENU> 
#endif /* __MMI_EM_RF_GSM__ || __MMI_EM_RF_WIFI__ */    


#ifdef __MMI_EM_CTM_CTA_TDD__
<!---------------------------------   CTA   -------------------------------------->
    <!--------------- string Id ------------------------------------------->
    <STRING id="STR_ID_EM_CONFORMANCE_TEST"> "Conf test mode" </STRING>
    <STRING id="STR_ID_EM_CONFORMANCE_TEST_REALNW"> "Real NW" </STRING>

    <STRING id="STR_ID_EM_CONFORMANCE_TEST_CTA"> "CTA" </STRING>
    <STRING id="STR_ID_EM_CONFORMANCE_TEST_CTA_INTEGRITY"> "Integrity check" </STRING>
    <STRING id="STR_ID_EM_CONFORMANCE_TEST_CTA_TL1"> "TL1" </STRING>
    <STRING id="STR_ID_EM_CONFORMANCE_TEST_CTA_K1297"> "K1297" </STRING>
    <STRING id="STR_ID_EM_CONFORMANCE_TEST_CTA_SN"> "SN conflict" </STRING>
    <STRING id="STR_ID_EM_CONFORMANCE_TEST_CTA_CF"> "CF query" </STRING>
    <STRING id="STR_ID_EM_CONFORMANCE_TEST_CTA_PLMN_LOCK"> "PLMN lock" </STRING>
    <STRING id="STR_ID_EM_CONFORMANCE_TEST_CTA_MEASUREMENT_OPEN"> "Measurement Open" </STRING>
    <STRING id="STR_ID_EM_CONFORMANCE_TEST_CTA_DISABLE_DPA"> "Disable DPA" </STRING>
    <STRING id="STR_ID_EM_CONFORMANCE_TEST_CTA_INTRA_CMR"> "Intra CMR" </STRING>
    		
    <STRING id="STR_ID_EM_CONFORMANCE_TEST_FTA"> "FTA" </STRING>
    <STRING id="STR_ID_EM_CONFORMANCE_TEST_IOT"> "IOT" </STRING>
    
#ifdef __MMI_EM_CTA_OPERATOR_TEST__
	<STRING id="STR_ID_EM_CONFORMANCE_TEST_OPERATOR_TEST"> "Operator test" </STRING>
	<STRING id="STR_ID_EM_CONFORMANCE_TEST_MS_USIM_COMPATIBLE"> "MS USIM Compatible" </STRING>
#endif
    
    <STRING id="STR_ID_EM_CONFORMANCE_TEST_GET_DATA_FAIL"> "Get data fail" </STRING>
    <STRING id="STR_ID_EM_CONFORMANCE_TEST_SET_DATA_FAIL"> "Set data fail" </STRING>
    <STRING id="STR_ID_EM_CONFORMANCE_TEST_SELECT_POWER_OFF"> "Select and power off?" </STRING>
    <STRING id="STR_ID_EM_CONFORMANCE_TEST_SELECT_COMMON_POWER_OFF"> "Select common and power off?" </STRING>
    <STRING id="STR_ID_EM_CONFORMANCE_TEST_SELECT_MULTIPLE_POWER_OFF"> "Select multiple and power off?" </STRING>

    <!------------------- screen Id  -------------------------------------->
    <SCREEN id="GRP_ID_CONF_TEST"/>
    <SCREEN id="GRP_ID_CONF_TEST_CTA"/>  

 #ifdef __MMI_EM_CTA_OPERATOR_TEST__   
    <SCREEN id="GRP_ID_CONF_TEST_OPERATOR_TEST"/>
 #endif

    <!------------------- Menu Tree Area----------------------------------->
      /* Type Support:OPTION, APP_MAIN, APP_SUB, default value is ORIGINAL */
      /* default="TRUE" means this item is active item when use CSK.       */
      /* type="SEPARATOR" means that CUI will show a separator here        */

    <MENUITEM id="MENU_ID_EM_CONFORMANCE_TEST" str="STR_ID_EM_CONFORMANCE_TEST"/>

    <MENU id="MENU_ID_EM_CONFORMANCE_TEST_2" type="APP_MAIN" str="STR_ID_EM_CONFORMANCE_TEST">
        <MENUITEM_ID>MENU_ID_EM_CONFORMANCE_TEST_REALNW</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_CONFORMANCE_TEST_CTA</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_CONFORMANCE_TEST_FTA</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_CONFORMANCE_TEST_IOT</MENUITEM_ID>	
   
   #ifdef __MMI_EM_CTA_OPERATOR_TEST__
        <MENUITEM_ID>MENU_ID_EM_CONFORMANCE_TEST_OPERATOR_TEST</MENUITEM_ID>
   #endif
   
    </MENU>
    
    
     <MENUITEM id="MENU_ID_EM_CONFORMANCE_TEST_REALNW" str="STR_ID_EM_CONFORMANCE_TEST_REALNW"/>
     
     <MENU id="MENU_ID_EM_CONFORMANCE_TEST_CTA" type="APP_SUB"  str="STR_ID_EM_CONFORMANCE_TEST_CTA" flag="CHECKBOX">
         <MENUITEM_ID>MENU_ID_EM_CONFORMANCE_TEST_CTA_INTEGRITY</MENUITEM_ID>
     	 <MENUITEM_ID>MENU_ID_EM_CONFORMANCE_TEST_CTA_TL1</MENUITEM_ID>
     	 <MENUITEM_ID>MENU_ID_EM_CONFORMANCE_TEST_CTA_K1297</MENUITEM_ID>
     	 <MENUITEM_ID>MENU_ID_EM_CONFORMANCE_TEST_CTA_SN</MENUITEM_ID>
     	 <MENUITEM_ID>MENU_ID_EM_CONFORMANCE_TEST_CTA_CF</MENUITEM_ID>
     	 <MENUITEM_ID>MENU_ID_EM_CONFORMANCE_TEST_CTA_PLMN_LOCK</MENUITEM_ID>
     	 <MENUITEM_ID>MENU_ID_EM_CONFORMANCE_TEST_CTA_MEASUREMENT_OPEN</MENUITEM_ID>
     	 <MENUITEM_ID>MENU_ID_EM_CONFORMANCE_TEST_CTA_DISABLE_DPA</MENUITEM_ID>
     	 <MENUITEM_ID>MENU_ID_EM_CONFORMANCE_TEST_CTA_INTRA_CMR</MENUITEM_ID>
     </MENU>
     
      <MENUITEM id="MENU_ID_EM_CONFORMANCE_TEST_FTA" str="STR_ID_EM_CONFORMANCE_TEST_FTA"/>
      <MENUITEM id="MENU_ID_EM_CONFORMANCE_TEST_IOT" str="STR_ID_EM_CONFORMANCE_TEST_IOT"/>
     
      
 #ifdef __MMI_EM_CTA_OPERATOR_TEST__

	  <MENUITEM id="MENU_ID_EM_CONFORMANCE_TEST_OPERATOR_TEST" str="STR_ID_EM_CONFORMANCE_TEST_OPERATOR_TEST"/>

	  <MENU id="MENU_ID_EM_CONFORMANCE_TEST_OPERATOR_TEST_2" type="APP_SUB"  str="STR_ID_EM_CONFORMANCE_TEST_OPERATOR_TEST" flag="CHECKBOX">
	  	<MENUITEM_ID>MENU_ID_EM_CONFORMANCE_TEST_MS_USIM_COMPATIBLE</MENUITEM_ID>
	  </MENU>

	  <MENUITEM id="MENU_ID_EM_CONFORMANCE_TEST_MS_USIM_COMPATIBLE" str="STR_ID_EM_CONFORMANCE_TEST_MS_USIM_COMPATIBLE"/>

#endif

     
      <MENUITEM id="MENU_ID_EM_CONFORMANCE_TEST_CTA_INTEGRITY" str="STR_ID_EM_CONFORMANCE_TEST_CTA_INTEGRITY"/>
      <MENUITEM id="MENU_ID_EM_CONFORMANCE_TEST_CTA_TL1" str="STR_ID_EM_CONFORMANCE_TEST_CTA_TL1"/>
      <MENUITEM id="MENU_ID_EM_CONFORMANCE_TEST_CTA_K1297" str="STR_ID_EM_CONFORMANCE_TEST_CTA_K1297"/>
      <MENUITEM id="MENU_ID_EM_CONFORMANCE_TEST_CTA_SN" str="STR_ID_EM_CONFORMANCE_TEST_CTA_SN"/>
      <MENUITEM id="MENU_ID_EM_CONFORMANCE_TEST_CTA_CF" str="STR_ID_EM_CONFORMANCE_TEST_CTA_CF"/>
      <MENUITEM id="MENU_ID_EM_CONFORMANCE_TEST_CTA_PLMN_LOCK" str="STR_ID_EM_CONFORMANCE_TEST_CTA_PLMN_LOCK"/>
      <MENUITEM id="MENU_ID_EM_CONFORMANCE_TEST_CTA_MEASUREMENT_OPEN" str="STR_ID_EM_CONFORMANCE_TEST_CTA_MEASUREMENT_OPEN"/>
      <MENUITEM id="MENU_ID_EM_CONFORMANCE_TEST_CTA_DISABLE_DPA" str="STR_ID_EM_CONFORMANCE_TEST_CTA_DISABLE_DPA"/>
      <MENUITEM id="MENU_ID_EM_CONFORMANCE_TEST_CTA_INTRA_CMR" str="STR_ID_EM_CONFORMANCE_TEST_CTA_INTRA_CMR"/>

<!----------------- EM Item End ----------------------------------------------->

#endif /*__MMI_EM_CTM_CTA_TDD__*/


<!----------------- RF Test Tool | GSM RF Test -------------------------------->
#ifdef __MMI_EM_RF_GSM__ 
    <!----------------- String Id ----------------------------------------->             
    <SCREEN id = "SCR_ID_EM_RF_TEST_GSM_POWER_SCAN_RESULT"/>

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_RF_TEST_TOOL_GSM">GSM</STRING>
    <STRING id = "STR_ID_EM_RF_GSM_TX_TEST">TX test</STRING>
    <STRING id = "STR_ID_EM_RF_GSM_RX_TEST">RX test</STRING>
    <STRING id = "STR_ID_EM_RF_GSM_POWER_SCAN">Power scan</STRING>
    <STRING id = "STR_ID_EM_AUD_SET_SUCCES">Successfully Set!!</STRING>
	<STRING id = "STR_ID_EM_AUD_SET_ERROR">Set Error!!</STRING>
	
    
    <STRING id = "STR_ID_EM_RF_GSM_TX_BAND">Band</STRING>
    <STRING id = "STR_ID_EM_RF_GSM_TX_BAND_GSM850">GSM850</STRING>
    <STRING id = "STR_ID_EM_RF_GSM_TX_BAND_GSM900">GSM900</STRING>
    <STRING id = "STR_ID_EM_RF_GSM_TX_BAND_DCS1800">DCS1800</STRING>
    <STRING id = "STR_ID_EM_RF_GSM_TX_BAND_PCS1900">PCS1900</STRING>
    
    <STRING id = "STR_ID_EM_RF_GSM_TX_ARFCN">ARFCN</STRING>
    <STRING id = "STR_ID_EM_RF_GSM_TX_TSC">TSC</STRING>
    <STRING id = "STR_ID_EM_RF_GSM_TX_PCL">PCL</STRING>
    <STRING id = "STR_ID_EM_RF_GSM_TX_AFC">AFC</STRING>
    
    <STRING id = "STR_ID_EM_RF_GSM_TX_BURST_TYPE">Burst type</STRING>
    <STRING id = "STR_ID_EM_RF_GSM_TX_BURST_NB">NB</STRING>
    <STRING id = "STR_ID_EM_RF_GSM_TX_BURST_AB">AB</STRING>
    
    <STRING id = "STR_ID_EM_RF_GSM_TX_GAIN">Gain</STRING>
    <STRING id = "STR_ID_EM_RF_GSM_RX_BURST_BURST_RX">Burst RX</STRING>

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_RF_TEST_TOOL_GSM" str = "STR_ID_EM_RF_TEST_TOOL_GSM"/>

    <MENU id = "MENU_ID_EM_RF_TEST_TOOL_GSM_LIST" type = "APP_SUB" str = "STR_ID_EM_RF_TEST_TOOL_GSM">
        <MENUITEM id = "MENU_ID_EM_RF_GSM_TX_TEST" str = "STR_ID_EM_RF_GSM_TX_TEST"/>
        <MENUITEM id = "MENU_ID_EM_RF_GSM_RX_TEST" str = "STR_ID_EM_RF_GSM_RX_TEST"/>
        <MENUITEM id = "MENU_ID_EM_RF_GSM_POWER_SCAN" str = "STR_ID_EM_RF_GSM_POWER_SCAN"/>
    </MENU>
    
#endif /* __MMI_EM_RF_GSM__ */    
<!----------------- EM Item End ----------------------------------------------->



<!----------------- RF Test Tool | WIFI RF Test ------------------------------->
#ifdef __MMI_EM_RF_WIFI__ 
    <!----------------- Screen Id ----------------------------------------->    
    <SCREEN id = "SCR_ID_EM_RF_WIFI_TX_DAC_OFFSET"/>
    <SCREEN id = "SCR_ID_EM_RF_WIFI_RX_CONT_PKT"/>
    
    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_RF_TEST_TOOL_WIFI">Wifi</STRING>
    <STRING id = "STR_ID_EM_RF_TEST_WIFI_CLOSE">Please close wifi first.</STRING>
    /* WiFi */   
	<STRING id = "STR_ID_EM_RF_WIFI_TX_TESTS">Tx test</STRING>                       <!-- Engineer Mode RF Test WiFi TX Tests Menu Caption String -->                     
	<STRING id = "STR_ID_EM_RF_WIFI_CONT_PKT_RX">Rx test</STRING>                 <!-- Engineer Mode RF Test WiFi PKT RX Menu Caption String -->                     
	<STRING id = "STR_ID_EM_RF_WIFI_POWER_SAVE">Sleep mode</STRING>                   <!-- Engineer Mode RF Test WiFi Power Save Menu Caption String -->                     
	<STRING id = "STR_ID_EM_RF_WIFI_STORAGE">Storage access</STRING>                <!-- Engineer Mode RF Test WiFi Register Access Menu Caption String -->                             
	<STRING id = "STR_ID_EM_RF_WIFI_REGISTER">Register access</STRING>                <!-- Engineer Mode RF Test WiFi Register Access Menu Caption String -->	

	/* WiFi TX */
	<STRING id = "STR_ID_EM_RF_WIFI_TX_OUTPUT_POWER">Tx output power</STRING>         <!-- Engineer Mode RF Test WiFi TX Output Power Menu Caption String -->                     
	<STRING id = "STR_ID_EM_RF_WIFI_TX_LOCAL_FREQUENCY">Local frequency</STRING>      <!-- Engineer Mode RF Test WiFi TX Local Freq. Menu Caption String -->                     
	<STRING id = "STR_ID_EM_RF_WIFI_TX_CONT_PKT_TX">Cont PKT tx</STRING>              <!-- Engineer Mode RF Test WiFi TX Cont PKT Menu Caption String -->                            
	/* WiFi TX -- Domain */
	/* WiFi TX -- Channel Freq. */
	<STRING id = "STR_ID_EM_RF_WIFI_TX_CH_FREQ">CH freq (MHz)</STRING>                <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_CH_FREQ_1">2412</STRING>                <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_CH_FREQ_2">2417</STRING>                <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_CH_FREQ_3">2422</STRING>                <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_CH_FREQ_4">2427</STRING>                <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_CH_FREQ_5">2432</STRING>                <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_CH_FREQ_6">2437</STRING>                <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_CH_FREQ_7">2442</STRING>                <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_CH_FREQ_8">2447</STRING>                <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_CH_FREQ_9">2452</STRING>                <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_CH_FREQ_10">2457</STRING>              <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_CH_FREQ_11">2462</STRING>              <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_CH_FREQ_12">2467</STRING>              <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_CH_FREQ_13">2472</STRING>              <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_CH_FREQ_14">2483.5</STRING>              <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	/* WiFi TX -- TX Rate */

    /*keep string id order below*/
	<STRING id = "STR_ID_EM_RF_WIFI_TX_RATE">TX rate</STRING>                         <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_RATE_1M">1M</STRING>                            <!-- Engineer Mode RF Test WiFi TX Caption String -->
	<STRING id = "STR_ID_EM_RF_WIFI_TX_RATE_2M">2M</STRING>                            <!-- Engineer Mode RF Test WiFi TX Caption String -->  
	<STRING id = "STR_ID_EM_RF_WIFI_TX_RATE_5_5M">5.5M</STRING>                          <!-- Engineer Mode RF Test WiFi TX Caption String -->
	<STRING id = "STR_ID_EM_RF_WIFI_TX_RATE_11M">11M</STRING>                            <!-- Engineer Mode RF Test WiFi TX Caption String -->
	<STRING id = "STR_ID_EM_RF_WIFI_TX_RATE_6M">6M</STRING>                            <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_RATE_9M">9M</STRING>                            <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_RATE_12M">12M</STRING>                           <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_RATE_18M">18M</STRING>                           <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_RATE_24M">24M</STRING>                           <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_RATE_36M">36M</STRING>                          <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_RATE_48M">48M</STRING>                          <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_RATE_54M">54M</STRING>                          <!-- Engineer Mode RF Test WiFi TX Caption String -->
	<STRING id = "STR_ID_EM_RF_WIFI_TX_RATE_MCS0">MCS0</STRING>
	<STRING id = "STR_ID_EM_RF_WIFI_TX_RATE_MCS1">MCS1</STRING>                             
	<STRING id = "STR_ID_EM_RF_WIFI_TX_RATE_MCS2">MCS2</STRING>
	<STRING id = "STR_ID_EM_RF_WIFI_TX_RATE_MCS3">MCS3</STRING>
	<STRING id = "STR_ID_EM_RF_WIFI_TX_RATE_MCS4">MCS4</STRING>
	<STRING id = "STR_ID_EM_RF_WIFI_TX_RATE_MCS5">MCS5</STRING>
	<STRING id = "STR_ID_EM_RF_WIFI_TX_RATE_MCS6">MCS6</STRING>
	<STRING id = "STR_ID_EM_RF_WIFI_TX_RATE_MCS7">MCS7</STRING>
	<STRING id = "STR_ID_EM_RF_WIFI_TX_RATE_MCS32">MCS32</STRING>
	
	<STRING id = "STR_ID_EM_RF_WIFI_11NBW">11n BW</STRING>
	/*keep string id order below*/
	<STRING id = "STR_ID_EM_RF_WIFI_11NBW_HT20">HT20</STRING>
	<STRING id = "STR_ID_EM_RF_WIFI_11NBW_HT40">HT40</STRING>
	<STRING id = "STR_ID_EM_RF_WIFI_11NBW_L20">L20</STRING>
	<STRING id = "STR_ID_EM_RF_WIFI_11NBW_U20">U20</STRING>
	
	<STRING id = "STR_ID_EM_RF_WIFI_11NGI">11n GI</STRING>
	<STRING id = "STR_ID_EM_RF_WIFI_11NGI_NG">NG</STRING>
	<STRING id = "STR_ID_EM_RF_WIFI_11NGI_SG">SG</STRING>
	<STRING id = "STR_ID_EM_RF_WIFI_11NPF">11n PF</STRING>
    <STRING id = "STR_ID_EM_RF_WIFI_11NPF_GF">GF</STRING>
    <STRING id = "STR_ID_EM_RF_WIFI_11NPF_MM">MM</STRING>
    <STRING id = "STR_ID_EM_RF_WIFI_REGISTER_EFUSE">EFuse(32bit)</STRING>
    <STRING id = "STR_ID_EM_RF_WIFI_POWER_UPDATE">Power(dBm)</STRING>

	/* WiFi TX -- TX Ant, Gain, pkt Count, pkt Interval, pkt Length */
	<STRING id = "STR_ID_EM_RF_WIFI_TX_GAIN">Gain (hex)</STRING>                      <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_PKT_COUNT">PKT count</STRING>                  <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_PKT_LENGTH">PKT length (byte)</STRING>         <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	/* WiFi TX -- TX Pattern */
	<STRING id = "STR_ID_EM_RF_WIFI_TX_PATTERN">TX pattern</STRING>                   <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_PATTERN_ALL_0">All 0</STRING>                  <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_PATTERN_ALL_1">All 1</STRING>                  <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_PATTERN_ALTER_BITS">Alter bits</STRING>   <!-- Engineer Mode RF Test WiFi TX Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_TX_PATTERN_RANDOM">Random</STRING>                <!-- Engineer Mode RF Test WiFi TX Caption String -->
	/* WiFi Power Save -- Mode */
	<STRING id = "STR_ID_EM_RF_WIFI_POWER_SAVE_NORMAL">Normal</STRING>                <!-- Engineer Mode RF Test WiFi Power Save Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_POWER_SAVE_IDLE">Idle</STRING>                    <!-- Engineer Mode RF Test WiFi Power Save Caption String -->                            
	<STRING id = "STR_ID_EM_RF_WIFI_POWER_SAVE_SLEEP">Sleep</STRING>                  <!-- Engineer Mode RF Test WiFi Power Save Caption String -->                            
	/* WiFi Register */

	<STRING id = "STR_ID_EM_RF_WIFI_REGISTER_MCR">Mcr</STRING>                        <!-- Engineer Mode RF Test WiFi Register MCR Menu Caption String -->

	<STRING id = "STR_ID_EM_RF_WIFI_REGISTER_EEPROM">Eeprom</STRING>                  <!-- Engineer Mode RF Test WiFi Register EEPROM Menu Caption String -->                            
	/* WiFi Register -- Type */
	<STRING id = "STR_ID_EM_RF_WIFI_REGISTER_TYPE">Type</STRING>                      <!-- Engineer Mode RF Test WiFi Caption String -->     
	<STRING id = "STR_ID_EM_RF_WIFI_REGISTER_16">16</STRING>                          <!-- Engineer Mode RF Test WiFi Caption String -->     
	<STRING id = "STR_ID_EM_RF_WIFI_REGISTER_32">32</STRING>                          <!-- Engineer Mode RF Test WiFi Caption String -->     
	/* WiFI Register -- Access */
	<STRING id = "STR_ID_EM_RF_WIFI_REGISTER_ACCESS">Access</STRING>                  <!-- Engineer Mode RF Test WiFi Caption String -->     
	<STRING id = "STR_ID_EM_RF_WIFI_REGISTER_WRITE">Write</STRING>                    <!-- Engineer Mode RF Test WiFi Caption String -->            
	/* WiFi Register -- Address, index, data */
	<STRING id = "STR_ID_EM_RF_WIFI_REGISTER_ADDRESS">Address(hex)</STRING>           <!-- Engineer Mode RF Test WiFi Caption String -->     
	<STRING id = "STR_ID_EM_RF_WIFI_REGISTER_DATA">Data (hex)</STRING>                <!-- Engineer Mode RF Test WiFi Caption String --> 

    <!----------------- Menu Id ------------------------------------------->             
    <MENUITEM id = "MENU_ID_EM_RF_TEST_TOOL_WIFI" str = "STR_ID_EM_RF_TEST_TOOL_WIFI"/>
    <MENU id = "MENU_ID_EM_RF_TEST_TOOL_WIFI_LIST" type = "APP_SUB" str = "STR_ID_EM_RF_TEST_TOOL_WIFI">
        <MENU id = "MENU_ID_EM_RF_WIFI_TX_TESTS" str = "STR_ID_EM_RF_WIFI_TX_TESTS">
            <MENUITEM id = "MENU_ID_EM_RF_WIFI_TX_OUTPUT_POWER" str = "STR_ID_EM_RF_WIFI_TX_OUTPUT_POWER"/>          
            <MENUITEM id = "MENU_ID_EM_RF_WIFI_TX_LOCAL_FREQUENCY" str = "STR_ID_EM_RF_WIFI_TX_LOCAL_FREQUENCY"/>            
            <MENUITEM id = "MENU_ID_EM_RF_WIFI_TX_CONT_PKT_TX" str = "STR_ID_EM_RF_WIFI_TX_CONT_PKT_TX"/>
        </MENU>
        <MENUITEM id = "MENU_ID_EM_RF_WIFI_CONT_PKT_RX" str = "STR_ID_EM_RF_WIFI_CONT_PKT_RX"/>
        <MENUITEM id = "MENU_ID_EM_RF_WIFI_POWER_SAVE" str = "STR_ID_EM_RF_WIFI_POWER_SAVE"/>
        <MENU id = "MENU_ID_EM_RF_WIFI_REGISTER_ACCESS" str = "STR_ID_EM_RF_WIFI_REGISTER">
            <MENUITEM id = "MENU_ID_EM_RF_WIFI_REGISTER_MCR" str = "STR_ID_EM_RF_WIFI_REGISTER_MCR"/>        
            <MENUITEM id = "MENU_ID_EM_RF_WIFI_REGISTER_EEPROM" str = "STR_ID_EM_RF_WIFI_REGISTER_EEPROM"/>
			<MENUITEM id = "MENU_ID_EM_RF_WIFI_REGISTER_EFUSE" str = "STR_ID_EM_RF_WIFI_REGISTER_EFUSE"/>
        </MENU>   
    </MENU>
    
#endif /* __MMI_EM_RF_WIFI__ */    
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Level2 Menu | VoIP ---------------------------------------->
#ifdef __MMI_EM_VOIP__    

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_VOIP">Voip</STRING>	
	<STRING id = "STR_ID_EM_VOIP_P2P_CALL">P2P Call</STRING>                          <!-- Engineer Mode VOIP -->		
	<STRING id = "STR_ID_EM_VOIP_REREGISTER_TIMER">Re-register Timer</STRING>         <!-- Engineer Mode VOIP -->		
	<STRING id = "STR_ID_EM_VOIP_CALL_REFRESH_TIMER">Call Refresh Timer</STRING>      <!-- Engineer Mode VOIP -->		
	<STRING id = "STR_ID_EM_VOIP_REFER_SUB_TIMER">Refer Sub Timer</STRING>            <!-- Engineer Mode VOIP -->		
	<STRING id = "STR_ID_EM_VOIP_MWI_SUB_TIMER">MWI Sub Timer</STRING>                <!-- Engineer Mode VOIP -->		
	<STRING id = "STR_ID_EM_VOIP_MWI_RETRY_TIME">MWI Retry Time</STRING>              <!-- Engineer Mode VOIP -->			
	<STRING id = "STR_ID_EM_VOIP_SETTINGS">Settings</STRING>                          <!-- Engineer Mode VOIP -->					
	<STRING id = "STR_ID_EM_VOIP_SIP_REQUIRE">SIP Require</STRING>                    <!-- Engineer Mode VOIP -->				

	<STRING id = "STR_ID_EM_VOIP_UAS_Refresher">UAS Refresher</STRING>                <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_VOIP_UAC_Refresher">UAC Refresher</STRING>                <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_VOIP_UAS">UAS</STRING>                                    <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_VOIP_UAC">UAC</STRING>                                    <!-- Engineer Mode Menu Caption String -->
	<STRING id = "STR_ID_EM_VOIP_RPORT_SUPPORT">RPort Support</STRING>                <!-- Engineer Mode Menu Caption String -->	
	<STRING id = "STR_ID_EM_VOIP_LOCAL_ADDR">Local Address</STRING>                   <!-- Engineer Mode Menu Caption String -->	

    <STRING id = "STR_ID_EM_VOIP_LOG">Log</STRING>                                    <!-- Engineer Mode VOIP Log -->
    <STRING id = "STR_ID_EM_VOIP_LOG_CONTENT">Content</STRING>                        <!-- Engineer Mode vOIP Log Content -->
    <STRING id = "STR_ID_EM_VOIP_LOG_SETTINGS">Setting</STRING>                       <!-- VOIP Log Setting -->
    <STRING id = "STR_ID_EM_VOIP_LOG_AUTO_DELETE">Auto Delete</STRING>                <!-- auto delete voip logs -->
    <STRING id = "STR_ID_EM_VOIP_LOG_DELETE_ALL">All</STRING>                         <!-- Delete all voip logs -->
    <STRING id = "STR_ID_EM_VOIP_LOG_DELETE_ONE_DAY">One Day</STRING>                 <!-- Delete all logs one day before -->
    <STRING id = "STR_ID_EM_VOIP_LOG_DELETE_HALF_MONTH">Half Month</STRING>           <!-- Delete all logs half month before -->
    <STRING id = "STR_ID_EM_VOIP_LOG_DELETE_ONE_MONTH">One Month</STRING>             <!-- Delete all logs one month before -->


    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_VOIP" type = "APP_SUB" str = "STR_ID_EM_VOIP">
        <MENUITEM_ID>MENU_ID_EM_VOIP_SETTINGS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_VOIP_SIP_SUPPORT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_VOIP_SIP_REQUIRE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_VOIP_LOG</MENUITEM_ID>
    </MENU>
    
#endif /* __MMI_EM_VOIP__ */    
<!----------------- EM Item End ----------------------------------------------->



<!----------------- VoIP | VoIP Settings -------------------------------------->
#ifdef __MMI_EM_VOIP__ 
    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_VOIP_SETTINGS" type = "APP_SUB" str = "STR_ID_EM_VOIP_SETTINGS">
    </MENU>
    
#endif /* __MMI_EM_VOIP__ */    
<!----------------- EM Item End ----------------------------------------------->



<!----------------- VoIP | SIP Support ---------------------------------------->
#ifdef __MMI_EM_VOIP__    

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_VOIP_SIP_SUPPORT">SIP supported</STRING>

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_VOIP_SIP_SUPPORT" type = "APP_SUB" str = "STR_ID_EM_VOIP_SIP_SUPPORT">
    </MENU>
    
#endif /* __MMI_EM_VOIP__ */    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- VoIP | SIP Require ---------------------------------------->
#ifdef __MMI_EM_VOIP__    

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_VOIP_SIP_REQUIRE">SIP require</STRING>

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_VOIP_SIP_REQUIRE" type = "APP_SUB" str = "STR_ID_EM_VOIP_SIP_REQUIRE">
    </MENU>
    
#endif /* __MMI_EM_VOIP__ */    
<!----------------- EM Item End ----------------------------------------------->


<!----------------- VoIP | VoIP Log ------------------------------------------->
#ifdef __MMI_EM_VOIP__    

    <!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_ID_EM_VOIP_LOG">Log</STRING>

    <!----------------- Menu Id ------------------------------------------->             
    <MENU id = "MENU_ID_EM_VOIP_LOG" type = "APP_SUB" str = "STR_ID_EM_VOIP_LOG">
    </MENU>
    
#endif /* __MMI_EM_VOIP__ */    

<!----------------- EM Item End ----------------------------------------------->




<!----------------- Audio | CacheData ----------------------------------------->
    <CACHEDATA type="double" id="NVRAM_AUDIO_DEBUG_INFO1" restore_flag="FALSE" restore_id="@NVRAM_CACHE_ID_RESERVED">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Double cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NVRAM_AUDIO_DEBUG_INFO2" restore_flag="FALSE" restore_id="@NVRAM_CACHE_ID_RESERVED">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Double cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NVRAM_AUDIO_DEBUG_INFO3" restore_flag="FALSE" restore_id="@NVRAM_CACHE_ID_RESERVED">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Double cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NVRAM_AUDIO_DEBUG_INFO4" restore_flag="FALSE" restore_id="@NVRAM_CACHE_ID_RESERVED">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Double cache </DESCRIPTION>
    </CACHEDATA>



<!----------------- EM Item End ----------------------------------------------->

<!----------------- GDI image decode ------------------------------------------>
#ifndef __LOW_COST_SUPPORT_COMMON__
    <IMAGE id="IMG_ID_EM_GDIPROFILING_9SLICE_REPEAT_1" >CUST_IMG_PATH"\\\\MainLCD\\\\GdiProfiling\\\\9slice\\\\Point_BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_EM_GDIPROFILING_9SLICE_REPEAT_2" >CUST_IMG_PATH"\\\\MainLCD\\\\GdiProfiling\\\\9slice\\\\speaker_hole.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_EM_GDIPROFILING_9SLICE_STRETCH" >CUST_IMG_PATH"\\\\MainLCD\\\\GdiProfiling\\\\9slice\\\\tune_bg_light.9slice.png"</IMAGE>

    <IMAGE id="IMG_ID_EM_GDIPROFILING_AB2_ALPHA" >CUST_IMG_PATH"\\\\MainLCD\\\\GdiProfiling\\\\ab2\\\\icon_select.png"</IMAGE>		
    <IMAGE id="IMG_ID_EM_GDIPROFILING_AB2_FULLY_OPAQUE" >CUST_IMG_PATH"\\\\MainLCD\\\\GdiProfiling\\\\ab2\\\\Normal.png"</IMAGE>
    <IMAGE id="IMG_ID_EM_GDIPROFILING_AB2_SOURCE_KEY" >CUST_IMG_PATH"\\\\MainLCD\\\\GdiProfiling\\\\ab2\\\\drag_bar.png"</IMAGE>
		
    <IMAGE id="IMG_ID_EM_GDIPROFILING_ABM_ALPHA" >CUST_IMG_PATH"\\\\MainLCD\\\\GdiProfiling\\\\abm\\\\time_PM.png"</IMAGE>
    #if defined(__COSMOS_MMI__)
    <IMAGE id="IMG_ID_EM_GDIPROFILING_ABM_NO_ALPHA" >CUST_IMG_PATH"\\\\MainLCD\\\\GdiProfiling\\\\abm\\\\meeting.pbm"</IMAGE>
    #else
    <IMAGE id="IMG_ID_EM_GDIPROFILING_ABM_NO_ALPHA" >CUST_IMG_PATH"\\\\MainLCD\\\\GdiProfiling\\\\abm\\\\meeting.bmp"</IMAGE>
    #endif
#endif

<!----------------- EM Item End ----------------------------------------------->

<!----------------- XML END --------------------------------------------------->

</APP>

#endif /* __MMI_ENGINEER_MODE__ */




