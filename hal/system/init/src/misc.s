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
; *   misc.s
; *
; * Project:
; * --------
; *   Maui_Software
; *
; * Description:
; * ------------
; *   This file defines memcpy functions forthe following chips:
; *    MT6235
; *    MT6235B
; *    MT6268A
; *    MT6268
; *    MT6236
; *    MT6236B
; *
; * Author:
; * -------
; * -------
; *
; *============================================================================
; *             HISTORY
; * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
; *------------------------------------------------------------------------------
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; *------------------------------------------------------------------------------
; * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
; *============================================================================
; ****************************************************************************/


   IF :DEF: MT6235 :LOR: :DEF: MT6235B :LOR: :DEF: MT6268A :LOR: :DEF: MT6268 :LOR: :DEF: MT6236 :LOR: :DEF: MT6236B


; If assembled with TASM the variable {CONFIG} will be set to 16
; If assembled with ARMASM the variable {CONFIG} will be set to 32
; Set the variable THUMB to TRUE or false depending on whether the
; file is being assembled with TASM or ARMASM.

        GBLL    THUMB
        GBLL    ARM
    [ {CONFIG} = 16
THUMB   SETL    {TRUE}
ARM     SETL    {FALSE}

; If assembling with TASM go into 32 bit mode as the Armulator will
; start up the program in ARM state.

        CODE32
    |
THUMB   SETL    {FALSE}
ARM     SETL    {TRUE}
    ]


   CODE32
   AREA |INTSRAM_ROCODE|, CODE, READONLY

; /*----------------------------*/
; /*  Definitions               */
; /*----------------------------*/

INT_BIT                 EQU      &C0         ; Interrupt bits

; /*----------------------------*/
; /*  Import functions          */
; /*----------------------------*/

   IMPORT  __rt_memcpy
   
; /*----------------------------*/
; /*  Export functions          */
; /*----------------------------*/

   
   IF :DEF: MT6235 :LOR: :DEF: MT6235B

;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*      INT_Memcpy                                                       */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*      Wrapper to memory copy function (ADS library) in TCM             */
;/*                                                                       */
;/* CALLS                                                                 */
;/*                                                                       */
;/* INPUTS                                                                */
;/*      None                                                             */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*      None                                                             */
;/*************************************************************************/
; VOID INT_Memcpy(Dest , Source , Size)
; {
   EXPORT  INT_Memcpy
INT_Memcpy
   STMDB    SP!,{R0,R14}
   BL       __rt_memcpy
   LDMIA    SP!,{R0,R14}
    [ THUMB
   BX       lr                              ; Return to caller
   |
   MOV      pc,lr                           ; Return to caller
    ]
;}

   ENDIF

   IF :DEF: MT6268A 
;
;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*   WriteHWRegister                                                     */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*   This function writes a value to a given address in a special        */
;/*   sequence. It is for MT6268A special usage (SW workaround for 3G HW).*/
;/*                                                                       */
;/* INPUTS                                                                */
;/*   addr    -   the specified target address                            */
;/*   value   -   the specified value to write                            */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*   None                                                                */
;/*************************************************************************/
; VOID WriteHWRegister(UINT addr, UINT value)
;{
WriteHWRegister
   EXPORT  WriteHWRegister
   ; Save Previous CPSR into R3
   MRS      R2,CPSR
   MOV      R3,R2
   ORR      R2,R2,#INT_BIT   
   MSR      CPSR_c, R2

   NOP
   NOP
   NOP
   NOP
   NOP
   NOP
   NOP
   NOP
   NOP
   NOP   
   LDRH r2,[r0,#0]
   STRH r1,[r0,#0]
   NOP   
   NOP
   NOP
   NOP
   STRH r1,[r0,#0]
   
   LDRH r2,[r0,#0]
   
   MRS      R1,CPSR
   AND      R2,R3,#INT_BIT
   BIC      R1,R1,#INT_BIT
   ORR      R3,R1,R2
   MSR      CPSR_c,R3
    [ THUMB
   BX       lr                              ; Return to caller
   |
   MOV      pc,lr                           ; Return to caller
    ]
;}

   ENDIF   ; MT6268A || MT6268 || MT6270A

   IF :DEF: MT6268 :LOR: :DEF: MT6236 :LOR: :DEF: MT6236B

   AREA |INTSRAM_ROCODE|, CODE, READONLY
  
; 
;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*   store_8word                                                         */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*   This function repeatedly writes 8-word data to a given address      */
;/*   with given patterns.                                                */
;/*   It is for MT6268 EMI's DDR-DQS-auto-track calibration mechanism.    */ 
;/*                                                                       */
;/* INPUTS                                                                */
;/*   addr      -   the specified target address                          */
;/*   pattern   -   the specified pattern to use                          */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*   None                                                                */
;/*************************************************************************/
; INT store_8word(UINT addr, UINT pattern)
;{
store_8word
   EXPORT   store_8word

   STMDB   sp!, {r4,r5,r6,r7,r8,r9}
   MVN r3,r1
   ADD r4, r1, r1
   ADD r5, r3, r3
   ADD r6, r4, r4
   ADD r7, r5, r5
   ADD r8, r6, r6
   ADD r9, r7, r7
   STMIA   r0, {r1,r3,r4,r5,r6,r7,r8,r9}   
   
StoreEnd
   LDMIA   sp!, {r4,r5,r6,r7,r8,r9}

    [ THUMB
   BX       lr                              ; Return to caller
   |
   MOV      pc,lr                           ; Return to caller
    ]
;}

;
;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*   load_8word                                                          */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*   This function repeatedly reads 8-word data from a given address     */
;/*   and compare with given patterns.                                    */
;/*   It is for MT6268 EMI's DDR-DQS-auto-track calibration mechanism.    */ 
;/*                                                                       */
;/* INPUTS                                                                */
;/*   addr      -   the specified target address                          */
;/*   pattern   -   the specified pattern to compare                      */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*   0 if the result is match; non-zero if no match                      */
;/*************************************************************************/
; INT load_8word(UINT addr, UINT value)
;{
load_8word
   EXPORT   load_8word
   STMDB   sp!, {r4-r12}
   MOV r12,#0
   MVN r3,r1
   LDMIA   r0, {r4,r5,r6,r7,r8,r9,r10,r11}   
   CMP r4, r1
   MOVNE r12, #9
   BNE LoadEnd
   CMP r5, r3
   MOVNE r12, #10
   BNE LoadEnd
   ADD r1, r1, r1
   CMP r6, r1
   MOVNE r12, #11
   BNE LoadEnd
   ADD r3, r3, r3
   CMP r7, r3
   MOVNE r12, #12
   BNE LoadEnd
   
   ADD r1, r1, r1
   CMP r8, r1
   MOVNE r12, #13
   BNE LoadEnd
   ADD r3, r3, r3
   CMP r9, r3
   MOVNE r12, #14
   BNE LoadEnd
   ADD r1, r1, r1
   CMP r10, r1
   MOVNE r12, #15
   BNE LoadEnd
   ADD r3, r3, r3
   CMP r11, r3
   MOVNE r12, #16
   
LoadEnd
   mov r0, r12
   LDMIA   sp!, {r4-r12}

    [ THUMB
   BX       lr                              ; Return to caller
   |
   MOV      pc,lr                           ; Return to caller
    ]  
;}

   ENDIF    ; MT6268 || MT6236 || MT62636B
   ENDIF
   END
