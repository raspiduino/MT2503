;/*****************************************************************************
;*  Copyright Statement:
;*  --------------------
;*  This software is protected by Copyright and the information contained
;*  herein is confidential. The software may not be copied and the information
;*  contained herein may not be used or disclosed except with the written
;*  permission of MediaTek Inc. (C) 2005
;*
;*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
;*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
;*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
;*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
;*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
;*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
;*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
;*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
;*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
;*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
;*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
;*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
;*
;*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
;*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
;*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
;*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
;*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
;*
;*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
;*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
;*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
;*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
;*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
;*
;*****************************************************************************/
;
;/*****************************************************************************
; *
; * Filename:
; * ---------
; *   bootarm.inc
; *
; * Project:
; * --------
; *   Maui_Software
; *
; * Description:
; * ------------
; *   This Module defines the platform dependent setting for boot sequence of asm level.
; *
; * Author:
; * -------
; *   Kengchu   Lin  (mtk01866)
; *
; *============================================================================
; *             HISTORY
; * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
; *------------------------------------------------------------------------------
; * $Revision:   1.00  $
; * $Modtime:   3/13/2012 9:37:34 AM  $
; * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/hal/system/init/inc/bootarm.inc-arc  $
; *
; * 01 22 2014 weiyu.chen
; * [MAUI_03484130] [MT6261] Init, MPU, Cahce, and USC driver porting
; * 	.
; *
; * 11 07 2012 dot.li
; * [MAUI_03258477] [MT6260] Check-in MT6260 SS relevant support
; * .
;*****************************************************************************/

; Define to allow conditional assembling of lowlevel ISR hook.
; Setting this to TRUE will allow a low-level hook to be executed in the
; interrupt handlers

; [BB porting] copy a template and fill in the correct setting for BB platform dependent setting


    GBLL REMAP_OFFSET_SUPPORT
    GBLL EMI_REMAP_OFFSET_MIXED
    GBLL EMI_26MHZ_FILL


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Define MT6253T/53/53E/53L/52H/52 related setting 
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    IF :DEF: MT6253T :LOR: :DEF: MT6253 :LOR: :DEF: MT6253E :LOR: :DEF: MT6253L :LOR: :DEF: MT6252H :LOR: :DEF: MT6252

;   if the remap register exist
REMAP_OFFSET_SUPPORT SETL    {TRUE}

;   if the remap resgister mix with other function bit
EMI_REMAP_OFFSET_MIXED   SETL    {FALSE}

;   if the 26MHZ setting need to fill in 
EMI_26MHZ_FILL           SETL    {TRUE}

;   the offset of the remap register
REMAP_OFFSET EQU &40

;		mask bit for remap register
REMAP_REG_MASK   EQU   &00000003

;   mask bit for 1 emi bank
REMAP_NOR_MASK
    DCD     0x7FFFFFF

;   bank1 address
REMAP_NOR_ADDR
    DCD     0x8000000

;   EMI setting for 26MHZ 
EMI_26MHZ_SETTING
    DCD     0x13000310

    ENDIF ; MT6253T || MT6253 || MT6253E || MT6253L || MT6252H || MT6252

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Define MT6250 related setting 
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    IF :DEF: MT6250 :LOR: :DEF: MT6260 :LOR: :DEF: MT6261 :LOR: :DEF: MT2501 :LOR: :DEF: MT2502

;   if the remap register exist (Actually not an EMI register)
REMAP_OFFSET_SUPPORT SETL    {TRUE}

;   if the remap resgister mix with other function bit
EMI_REMAP_OFFSET_MIXED   SETL    {FALSE}

;   if the 26MHZ setting need to fill in 
EMI_26MHZ_FILL           SETL    {TRUE}

;   the offset of the remap register
REMAP_OFFSET EQU &0

;		mask bit for remap register
REMAP_REG_MASK   EQU   &00000003

;   mask bit for 1 emi bank
REMAP_NOR_MASK
    DCD     0xFFFFFFF

;   bank1 address
REMAP_NOR_ADDR
    DCD     0x10000000

;   EMI setting for 26MHZ (Actually not used)
EMI_26MHZ_SETTING
    DCD     0x20404405

    ENDIF ; MT6250 || MT6260 || MT6261 || MT2501 || MT2502


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Define MT6270A/76 related setting 
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    IF :DEF: MT6270A :LOR: :DEF: MT6276

;   if the remap register exist
REMAP_OFFSET_SUPPORT SETL    {TRUE}

;   if the remap resgister mix with other function bit
EMI_REMAP_OFFSET_MIXED   SETL    {TRUE}

;   if the 26MHZ setting need to fill in 
EMI_26MHZ_FILL           SETL    {FALSE}

;   the offset of the remap register
REMAP_OFFSET EQU &70

;		mask bit for remap register
REMAP_REG_MASK   EQU   &00000003
    
;   mask bit for 1 emi bank
REMAP_NOR_MASK
    DCD     0xFFFFFFF

;   bank1 address
REMAP_NOR_ADDR
    DCD     0x10000000

;   EMI setting for 26MHZ 
EMI_26MHZ_SETTING
    DCD     0x20404405

    ENDIF ; MT6270A || MT6276



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Define MT6256 related setting 
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    IF :DEF: MT6256 :LOR: :DEF: MT6255

;   if the remap register exist
REMAP_OFFSET_SUPPORT SETL    {TRUE}

;   if the remap resgister mix with other function bit
EMI_REMAP_OFFSET_MIXED   SETL    {TRUE}

;   if the 26MHZ setting need to fill in 
EMI_26MHZ_FILL           SETL    {FALSE}

;   the offset of the remap register
REMAP_OFFSET EQU &70

;		mask bit for remap register
REMAP_REG_MASK   EQU   &00000003
    
;   mask bit for 1 emi bank
REMAP_NOR_MASK
    DCD     0xFFFFFFF

;   bank1 address
REMAP_NOR_ADDR
    DCD     0x10000000

;   EMI setting for 26MHZ 
EMI_26MHZ_SETTING
    DCD     0x20404405

    ENDIF ; MT6256


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Define MT6251 related setting 
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    IF :DEF: MT6251

;   if the remap register exist
REMAP_OFFSET_SUPPORT SETL    {TRUE}

;   if the remap resgister mix with other function bit
EMI_REMAP_OFFSET_MIXED   SETL    {FALSE}

;   if the 26MHZ setting need to fill in 
EMI_26MHZ_FILL           SETL    {TRUE}

;   the offset of the remap register
REMAP_OFFSET EQU &0

;		mask bit for remap register
REMAP_REG_MASK   EQU   &00010000
    
;   mask bit for 1 emi bank
REMAP_NOR_MASK
    DCD     0x7FFFFFF

;   bank1 address
REMAP_NOR_ADDR
    DCD     0x40000000

;   EMI setting for 26MHZ 
EMI_26MHZ_SETTING
    DCD     0x13000310


SYSRAM_Base_Ptr
   DCD     0x40000000
   
SYSRAM_REMAP_REG   
   DCD     0x85000040

SYSRAM_REMAP_KEY
   DCD     0x00006251


   ENDIF ; MT6251



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Define MT6238/39/35/35B related setting 
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    IF :DEF: MT6238 :LOR: :DEF: MT6239 :LOR: :DEF: MT6235 :LOR: :DEF: MT6235B

;   if the remap register exist
REMAP_OFFSET_SUPPORT SETL    {TRUE}

;   if the remap resgister mix with other function bit
EMI_REMAP_OFFSET_MIXED   SETL    {TRUE}

;   if the 26MHZ setting need to fill in 
EMI_26MHZ_FILL           SETL    {FALSE}

;   the offset of the remap register
REMAP_OFFSET EQU &70

;		mask bit for remap register
REMAP_REG_MASK   EQU   &00000003
    
;   mask bit for 1 emi bank
REMAP_NOR_MASK
    DCD     0xFFFFFFF

;   bank1 address
REMAP_NOR_ADDR
    DCD     0x10000000

;   EMI setting for 26MHZ 
EMI_26MHZ_SETTING
    DCD     0x20404405

    ENDIF ; MT6238 || MT6239 || MT6235 || MT6235B 


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Define MT6236/36B/68A/68 related setting 
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    IF :DEF: MT6236 :LOR: :DEF: MT6236B :LOR: :DEF: MT6268A :LOR: :DEF: MT6268

;   if the remap register exist
REMAP_OFFSET_SUPPORT SETL    {TRUE}

;   if the remap resgister mix with other function bit
EMI_REMAP_OFFSET_MIXED   SETL    {TRUE}

;   if the 26MHZ setting need to fill in 
EMI_26MHZ_FILL           SETL    {FALSE}

;   the offset of the remap register
REMAP_OFFSET EQU &70

;		mask bit for remap register
REMAP_REG_MASK   EQU   &00000003
    
;   mask bit for 1 emi bank
REMAP_NOR_MASK
    DCD     0xFFFFFFF
    
;   bank1 address
REMAP_NOR_ADDR
    DCD     0x10000000

;   EMI setting for 26MHZ 
EMI_26MHZ_SETTING
    DCD     0x20404405

    ENDIF ; MT6238 || MT6239 || MT6235 || MT6235B 


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Define MT6223/23P related setting 
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    IF :DEF: MT6223 :LOR: :DEF: MT6223P

;   if the remap register exist
REMAP_OFFSET_SUPPORT SETL    {TRUE}

;   if the remap resgister mix with other function bit
EMI_REMAP_OFFSET_MIXED   SETL    {FALSE}

;   the offset of the remap register
REMAP_OFFSET EQU &40

;		mask bit for remap register
REMAP_REG_MASK   EQU   &00000003
    
;   mask bit for 1 emi bank
REMAP_NOR_MASK
    DCD     0x7FFFFFF

;   bank1 address
REMAP_NOR_ADDR
    DCD     0x8000000

;   EMI setting for 26MHZ 
EMI_26MHZ_SETTING
    DCD     0x44004404

    ENDIF ; MT6223 || MT6223P


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Define MT6225 related setting 
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    IF :DEF: MT6225

;   if the remap register exist
REMAP_OFFSET_SUPPORT SETL    {TRUE}

;   if the remap resgister mix with other function bit
EMI_REMAP_OFFSET_MIXED   SETL    {FALSE}

;   if the 26MHZ setting need to fill in 
EMI_26MHZ_FILL           SETL    {TRUE}

;   the offset of the remap register
REMAP_OFFSET EQU &60

;		mask bit for remap register
REMAP_REG_MASK   EQU   &00000003
    
;   mask bit for 1 emi bank
REMAP_NOR_MASK
    DCD     0x7FFFFFF

;   bank1 address
REMAP_NOR_ADDR
    DCD     0x8000000

;   EMI setting for 26MHZ 
EMI_26MHZ_SETTING
    DCD     0x44004404

    ENDIF ; MT6225


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Define MT6226/26M/26D/27/27D related setting 
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    IF :DEF: MT6226 :LOR: :DEF: MT6226M :LOR: :DEF: MT6226D :LOR: :DEF: MT6227 :LOR: :DEF: MT6227D

;   if the remap register exist
REMAP_OFFSET_SUPPORT SETL    {TRUE}

;   if the remap resgister mix with other function bit
EMI_REMAP_OFFSET_MIXED   SETL    {FALSE}

;   if the 26MHZ setting need to fill in 
EMI_26MHZ_FILL           SETL    {TRUE}

;   the offset of the remap register
REMAP_OFFSET EQU &60

;		mask bit for remap register
REMAP_REG_MASK   EQU   &00000003
    
;   mask bit for 1 emi bank
REMAP_NOR_MASK
    DCD     0x7FFFFFF

;   bank1 address
REMAP_NOR_ADDR
    DCD     0x8000000

;   EMI setting for 26MHZ 
EMI_26MHZ_SETTING
    DCD     0x44004404

    ENDIF ; MT6226 || MT6226M || MT6226D || MT6227 || MT6227D

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Define MT6229/MT6228/MT6230 related setting 
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    IF :DEF: MT6229 :LOR: :DEF: MT6228 :LOR: :DEF: MT6230

;   if the remap register exist
REMAP_OFFSET_SUPPORT SETL    {TRUE}

;   if the remap resgister mix with other function bit
EMI_REMAP_OFFSET_MIXED   SETL    {FALSE}

;   if the 26MHZ setting need to fill in 
EMI_26MHZ_FILL           SETL    {TRUE}

;   the offset of the remap register
REMAP_OFFSET EQU &60

;		mask bit for remap register
REMAP_REG_MASK   EQU   &00000003
    
;   mask bit for 1 emi bank
REMAP_NOR_MASK
    DCD     0x7FFFFFF

;   bank1 address
REMAP_NOR_ADDR
    DCD     0x8000000

;   EMI setting for 26MHZ 
EMI_26MHZ_SETTING
    DCD     0x20404405

    ENDIF ; MT6229 || MT6228 || MT6230


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Define MT6217/18/18B/19 related setting 
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    IF :DEF: MT6217 :LOR: :DEF: MT6218 :LOR: :DEF: MT6218B :LOR: :DEF: MT6219

;   if the remap register exist
EMI_REMAP_OFFSET_SUPPORT SETL    {FALSE}

;   if the remap resgister mix with other function bit
EMI_REMAP_OFFSET_MIXED   SETL    {FALSE}

;   if the 26MHZ setting need to fill in 
EMI_26MHZ_FILL           SETL    {TRUE}

;   the offset of the remap register
REMAP_OFFSET EQU &40

;   mask bit for 1 emi bank
REMAP_NOR_MASK
    DCD     0x7FFFFFF

;   bank1 address
REMAP_NOR_ADDR
    DCD     0x8000000

;   EMI setting for 26MHZ 
EMI_26MHZ_SETTING
    DCD     0x44004404

    ENDIF ; MT6217 || MT6218 || MT6218B || MT6219

   END

