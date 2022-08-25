#ifndef __NLD_CENTRAL_H__
#define __NLD_CENTRAL_H__

#define __NLD_CENTRAL_CTRL__

typedef enum
{
   NLD_DRIVING_2MA      = 0,
   NLD_DRIVING_4MA      = 1,
   NLD_DRIVING_6MA      = 2,
   NLD_DRIVING_8MA      = 3,
   NLD_DRIVING_10MA     = 4,
   NLD_DRIVING_12MA     = 5,
   NLD_DRIVING_14MA     = 6,
   NLD_DRIVING_16MA     = 7,
   NLD_DRIVING_RESERVED = 0x7FFFFFFF
}  NLD_DRIVING_CURRENT_ENUM;

//the default drving current,type: NLD_DRIVING_CURRENT_ENUM
#define NLD_DEFAULT_DRIVING_CURRENT  NLD_DRIVING_4MA 

#if defined(__NLD_CENTRAL_CTRL__) 
typedef enum
{
    NLI_ARB_HANDOVER_ENTER_LCD_EN  = 0x01,
    NLI_ARB_HANDOVER_ENTER_NF_EN   = 0x02,
    NLI_ARB_HANDOVER_ENTER_HIF0_EN = 0x04,
    NLI_ARB_HANDOVER_ENTER_HIF1_EN = 0x08,
    NLI_ARB_HANDOVER_LEAVE_LCD_EN  = 0x10,
    NLI_ARB_HANDOVER_LEAVE_NF_EN   = 0x20,
    NLI_ARB_HANDOVER_LEAVE_HIF0_EN = 0x40,
    NLI_ARB_HANDOVER_LEAVE_HIF1_EN = 0x80,

    NLI_ARB_HANDOVER_NUMBER
}NLI_ARB_HANDOVER_ENUM;

//Nli arbiter handover cycle central control
#define NLI_DEFAULT_HANDOVER_CYCLE 0
#define NLI_DEFAULT_HANDOVER_TYPE (0x0)
//example:if you want to setting ENTER_LCD and LEAVE_HIF0 handover cycle.pls set as:
//#define NLI_DEFAULT_HANDOVER_TYPE (NLI_ARB_HANDOVER_ENTER_LCD_EN | NLI_ARB_HANDOVER_LEAVE_HIF0_EN)
#endif

void NLDShareBusCenCtrl(void);
#endif //__NLD_CENTRAL_H__
