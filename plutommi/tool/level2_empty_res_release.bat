rem
rem  Copyright Statement:
rem  --------------------
rem  This software is protected by Copyright and the information contained
rem  herein is confidential. The software may not be copied and the information
rem  contained herein may not be used or disclosed except with the written
rem  permission of MediaTek Inc. (C) 2005
rem
rem  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
rem  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
rem  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
rem  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
rem  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
rem  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
rem  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
rem  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
rem  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
rem  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
rem  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
rem  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
rem
rem  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
rem  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
rem  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
rem  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
rem  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
rem
rem  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
rem  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
rem  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
rem  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
rem  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
rem
cd ..

rem ************************************************************
rem ***************** Copy Empty Resource to PLUTO *************
rem ************************************************************
if not exist %1\plutommi\Customer\CustResource\PLUTO_MMI\ md %1\plutommi\Customer\CustResource\PLUTO_MMI
xcopy Customer\custresource\EMPTY_MMI %1\plutommi\Customer\CustResource\PLUTO_MMI\*.*  /E /Q /Y /I

if not exist %1\plutommi\Customer\CustResource\ md %1\plutommi\Customer\CustResource
xcopy Customer\custresource\EMPTY_MMI %1\plutommi\Customer\CustResource\*.*  /E /Q /Y /I

rem ****Remove empty folder copy****

rem ******* copy even the destination folder not existed *******
if not exist %1\plutommi\Customer\LcdResource\MainLcd128X128\ md %1\plutommi\Customer\LcdResource\MainLcd128X128
xcopy Customer\custresource\EMPTY_MMI %1\plutommi\Customer\LcdResource\MainLcd128X128\*.*  /E /Q /Y /I
if not exist %1\plutommi\Customer\LcdResource\MainLcd128X160\ md %1\plutommi\Customer\LcdResource\MainLcd128X160
xcopy Customer\custresource\EMPTY_MMI %1\plutommi\Customer\LcdResource\MainLcd128X160\*.*  /E /Q /Y /I
if not exist %1\plutommi\Customer\LcdResource\MainLcd176X220\ md %1\plutommi\Customer\LcdResource\MainLcd176X220
xcopy Customer\custresource\EMPTY_MMI %1\plutommi\Customer\LcdResource\MainLcd176X220\*.*  /E /Q /Y /I
if not exist %1\plutommi\Customer\LcdResource\MainLcd240X320\ md %1\plutommi\Customer\LcdResource\MainLcd240X320
xcopy Customer\custresource\EMPTY_MMI %1\plutommi\Customer\LcdResource\MainLcd240X320\*.*  /E /Q /Y /I
if not exist %1\plutommi\Customer\LcdResource\MainLcd320X240\ md %1\plutommi\Customer\LcdResource\MainLcd320X240
xcopy Customer\custresource\EMPTY_MMI %1\plutommi\Customer\LcdResource\MainLcd320X240\*.*  /E /Q /Y /I
if not exist %1\plutommi\Customer\LcdResource\MainLcd240X400\ md %1\plutommi\Customer\LcdResource\MainLcd240X400
xcopy Customer\custresource\EMPTY_MMI %1\plutommi\Customer\LcdResource\MainLcd240X400\*.*  /E /Q /Y /I
if not exist %1\plutommi\Customer\LcdResource\MainLcd320X480\ md %1\plutommi\Customer\LcdResource\MainLcd320X480
xcopy Customer\custresource\EMPTY_MMI %1\plutommi\Customer\LcdResource\MainLcd320X480\*.*  /E /Q /Y /I

rem ******* remove %1\plutommi\Customer\CustResource\PLUTO_MMI\InputMethod *******
if exist %1\plutommi\Customer\CustResource\PLUTO_MMI\InputMethod rd /s /q %1\plutommi\Customer\CustResource\PLUTO_MMI\InputMethod\

rem ******* clean ref_list.txt *******
rem if exist %1\plutommi\Tool\ref_list_release.pl perl %1\plutommi\Tool\ref_list_release.pl %1

rem ******* clean STMT *******
rem if exist %1\plutommi\Customer\STMT_G.dll del /F /Q %1\plutommi\Customer\STMT.dll

cd tool
