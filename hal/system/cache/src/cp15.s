;/******************************************************************************* 
;*  Copyright Statement: 
;*  -------------------- 
;*  This software is protected by Copyright and the information contained 
;*  herein is confidential. The software may not be copied and the information 
;*  contained herein may not be used or disclosed except with the written 
;*  permission of MediaTek Inc. (C) 2001 
;* 
;*******************************************************************************/ 
; 
;/******************************************************************************* 
; * 
; * Filename: 
; * --------- 
; *   cp15.s 
; * 
; * Project: 
; * -------- 
; *   MAUI 
; * 
; * Description: 
; * ------------ 
; *   This files implements coprocessor(CP15) control. 
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
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
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
    IF :DEF: ARM9_MMU
      INCLUDE arm9_cp15.inc
      
    ELIF :DEF: ARM11_MMU
      INCLUDE arm11_cp15.inc
      
    ELIF :DEF: CR4
      INCLUDE cr4_cp15.inc
      
    ELSE
      ; Empty CP15
      
    ENDIF

    END 
