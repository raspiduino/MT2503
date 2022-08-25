#ifndef _GPIO_HW_MT6261_H 
#define _GPIO_HW_MT6261_H 
//#include "drv_features_gpio.h" 
#include "reg_base.h" 


#if !defined(DRV_GPIO_OFF)



/*D die macro ****************************************************************************************/

#define   DDIE_GPIO_PULLSEL_UP_IS_1
/*if no define 
ADIE_GPIO_PULLSEL_UP_IS_1 
or DDIE_GPIO_PUPD_UP_IS_1 
or DDIE_GPIO_PULLSEL_UP_IS_1 
means: down is 1*/

#define    GPIO_MODE0                               (GPIO_base+0x0C00)
#define    GPIO_MODE0_SET                           (GPIO_base+0x0C04)
#define    GPIO_MODE0_CLR                           (GPIO_base+0x0C08)
#define    GPIO_MODE_OFFSET_TO_NEXT                 0x10
#define    GPIO_MODE_REG_MAX_NUM                    6
#define    GPIO_MODE_REG_BITS                       32
#define    GPIO_MODE_ONE_CONTROL_BITS               4
#define    GPIO_MODE_ONE_REG_CONTROL_NUM            8
#define    GPIO_MODE_REG0    GPIO_HWORD_REG_VAL(MODE, 0,  1,  2,  3,  4,  5,  6,  7, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
#define    GPIO_MODE_REG1    GPIO_HWORD_REG_VAL(MODE,  8,  9,  10,  11,  12,  13,  14,  15, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
#define    GPIO_MODE_REG2    GPIO_HWORD_REG_VAL(MODE,  16,  17,  18,  19,  20,  21,  22,  23, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
#define    GPIO_MODE_REG3    GPIO_HWORD_REG_VAL(MODE,  24,  25,  26,  27,  28,  29,  30,  31, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
#define    GPIO_MODE_REG4    GPIO_HWORD_REG_VAL(MODE, 32,  33,  34,  35,  36,  37,  38,  39, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
#define    GPIO_MODE_REG5    GPIO_HWORD_REG_VAL(MODE,  40,  41,  42,  43,  44,  45,  46,  47, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
#define    GPIO_MODE_REG6    GPIO_HWORD_REG_VAL(MODE,  48, 49,  50,  51,  52,  53,  54,  55, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
#define    GPIO_MODE_ALL_VALUE     GPIO_MODE_REG0,GPIO_MODE_REG1,GPIO_MODE_REG2,GPIO_MODE_REG3,GPIO_MODE_REG4,GPIO_MODE_REG5,GPIO_MODE_REG6 

#define    GPIO_DIR0                                (GPIO_base+0x0000)
#define    GPIO_DIR0_SET                            (GPIO_base+0x0004)
#define    GPIO_DIR0_CLR                            (GPIO_base+0x0008)
#define    GPIO_DIR_OFFSET_TO_NEXT                  0x10
#define    GPIO_DIR_REG_MAX_NUM                     1
#define    GPIO_DIR_REG_BITS                        32
#define    GPIO_DIR_ONE_CONTROL_BITS                1
#define    GPIO_DIR_ONE_REG_CONTROL_NUM             32
#define    GPIO_DIR_REG0    GPIO_HWORD_REG_VAL(DIR, 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31)
#define    GPIO_DIR_REG1    GPIO_HWORD_REG_VAL(DIR,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47, 48, 49, 50, 51, 52, 53, 54, 55, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
#define    GPIO_DIR_ALL_VALUE     GPIO_DIR_REG0,GPIO_DIR_REG1  

#define    GPIO_PULL0                               (GPIO_base+0x0100)
#define    GPIO_PULL0_SET                           (GPIO_base+0x0104)
#define    GPIO_PULL0_CLR                           (GPIO_base+0x0108)
#define    GPIO_PULL_OFFSET_TO_NEXT                 0x10
#define    GPIO_PULL_REG_MAX_NUM                    1
#define    GPIO_PULL_REG_BITS                       32
#define    GPIO_PULL_ONE_CONTROL_BITS               1
#define    GPIO_PULL_ONE_REG_CONTROL_NUM            32
#define    GPIO_PULL_REG0    GPIO_HWORD_REG_VAL(PULL, 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31)
#define    GPIO_PULL_REG1    GPIO_HWORD_REG_VAL(PULL,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47, 48, 49, 50, 51, 52, 53, 54, 55, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
#define    GPIO_PULL_ALL_VALUE     GPIO_PULL_REG0,GPIO_PULL_REG1

#define    GPIO_DINV0                               (GPIO_base+0x0200)
#define    GPIO_DINV_OFFSET_TO_NEXT                 0x10
#define    GPIO_INV_REG_MAX_NUM                     1
#define    GPIO_INV_REG_BITS                        32
#define    GPIO_INV_ONE_CONTROL_BITS                1
#define    GPIO_INV_ONE_REG_CONTROL_NUM             32
#define    GPIO_INV_REG0    GPIO_HWORD_REG_VAL(INV, 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31)
#define    GPIO_INV_REG1    GPIO_HWORD_REG_VAL(INV, 32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47, 48, 49, 50, 51, 52, 53, 54, 55, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
#define    GPIO_INV_ALL_VALUE     GPIO_INV_REG0,GPIO_INV_REG1  

#define    GPIO_OUTPUT_LEVEL0                       (GPIO_base+0x0300)
#define    GPIO_OUTPUT_LEVEL0_SET                   (GPIO_base+0x0304)
#define    GPIO_OUTPUT_LEVEL0_CLR                   (GPIO_base+0x0308)
#define    GPIO_OUTPUT_LEVEL_OFFSET_TO_NEXT         0x10
#define    GPIO_OUTPUT_LEVEL_REG_MAX_NUM            1
#define    GPIO_OUTPUT_LEVEL_REG_BITS               32
#define    GPIO_OUTPUT_LEVEL_ONE_CONTROL_BITS       1
#define    GPIO_OUTPUT_LEVEL_ONE_REG_CONTROL_NUM    32
#define    GPIO_OUTPUT_LEVEL_REG0    GPIO_HWORD_REG_VAL(OUTPUT_LEVEL, 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31)
#define    GPIO_OUTPUT_LEVEL_REG1    GPIO_HWORD_REG_VAL(OUTPUT_LEVEL, 32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47, 48, 49, 50, 51, 52, 53, 54, 55, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
#define    GPIO_OUTPUT_LEVEL_ALL_VALUE     GPIO_OUTPUT_LEVEL_REG0,GPIO_OUTPUT_LEVEL_REG1

#define    GPIO_DIN0                                (GPIO_base+0x0400)
#define    GPIO_DIN_OFFSET_TO_NEXT                  0x10
#define    GPIO_DIN_REG_MAX_NUM                     1
#define    GPIO_DIN_REG_BITS                        32
#define    GPIO_DIN_ONE_CONTROL_BITS                1
#define    GPIO_DIN_ONE_REG_CONTROL_NUM             32
#define    GPIO_DIN_REG0    GPIO_HWORD_REG_VAL(DIN, 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31)
#define    GPIO_DIN_REG1    GPIO_HWORD_REG_VAL(DIN,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47, 48, 49, 50, 51, 52, 53, 54, 55, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
#define    GPIO_DIN_ALL_VALUE     GPIO_DIN_REG0,GPIO_DIN_REG1

#define    GPIO_PULLSEL0                            (GPIO_base+0x0500)
#define    GPIO_PULLSEL0_SET                        (GPIO_base+0x0504)
#define    GPIO_PULLSEL0_CLR                        (GPIO_base+0x0508)
#define    GPIO_PULL_SEL_OFFSET_TO_NEXT             0x10
#define    GPIO_PULL_SEL_REG_MAX_NUM                1
#define    GPIO_PULL_SEL_REG_BITS                   32
#define    GPIO_PULL_SEL_ONE_CONTROL_BITS           1
#define    GPIO_PULL_SEL_ONE_REG_CONTROL_NUM        32
#define    GPIO_PULL_SEL_REG0    GPIO_HWORD_REG_VAL(PULL_SEL, 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31)
#define    GPIO_PULL_SEL_REG1    GPIO_HWORD_REG_VAL(PULL_SEL,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47, 48, 49, 50, 51, 52, 53, 54, 55, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
#define    GPIO_PULL_SEL_ALL_VALUE     GPIO_PULL_SEL_REG0,GPIO_PULL_SEL_REG1

#define    GPIO_DRV0                                (GPIO_base+0x0800)
#define    GPIO_DRV_OFFSET_TO_NEXT                  0x10
#define    GPIO_DRV_REG_MAX_NUM                     1
#define    GPIO_IES0                                (GPIO_base+0x0900)
#define    GPIO_IES_OFFSET_TO_NEXT                  0x10
#define    GPIO_DRV_IES_MAX_NUM                     1
#define    GPIO_PUPD0                               (GPIO_base+0x0a00)
#define    GPIO_PUPD0_SET                           (GPIO_base+0x0a04)
#define    GPIO_PUPD0_CLR                           (GPIO_base+0x0a08)
#define    GPIO_PUPD_OFFSET_TO_NEXT                 0x10
#define    GPIO_PUPD_REG_MAX_NUM                    1
#define    GPIO_PUPD_REG_BITS                       32
#define    GPIO_PUPD_ONE_CONTROL_BITS               1
#define    GPIO_PUPD_ONE_REG_CONTROL_NUM            32
#define    GPIO_PUPD_REG0    GPIO_HWORD_REG_VAL(PUPD, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 10, NULL, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, NULL, NULL, NULL, NULL, 26, 27, 28, 29, NULL, 31)
#define    GPIO_PUPD_REG1    GPIO_HWORD_REG_VAL(PUPD, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, NULL, NULL, 45, 46, 47, 48, 49, 50, 51, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
#define    GPIO_PUPD_ALL_VALUE     GPIO_PUPD_REG0,GPIO_PUPD_REG1  

#define    GPIO_R0_ADDR0                            (GPIO_base+0x0b00)
#define    GPIO_R0_SET_REG0                         (GPIO_base+0x0b04)
#define    GPIO_R0_CLR_REG0                         (GPIO_base+0x0b08)
#define    GPIO_R0_OFFSET_TO_NEXT                   0x10
#define    GPIO_R0_REG_MAX_NUM                      1
#define    GPIO_R0_REG_BITS                         32
#define    GPIO_R0_ONE_CONTROL_BITS                 1
#define    GPIO_R0_ONE_REG_CONTROL_NUM              32
#define    GPIO_R0_REG0    GPIO_HWORD_REG_VAL(R0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 10, NULL, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, NULL, NULL, NULL, NULL, 26, 27, 28, 29, NULL, 31)
#define    GPIO_R0_REG1    GPIO_HWORD_REG_VAL(R0, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, NULL, NULL, 45, 46, 47, 48, 49, 50, 51, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
#define    GPIO_R0_ALL_VALUE     GPIO_R0_REG0,GPIO_R0_REG1

#define    GPIO_R1_ADDR0                            (GPIO_base+0x0b20)
#define    GPIO_R1_SET_REG0                         (GPIO_base+0x0b24)
#define    GPIO_R1_CLR_REG0                         (GPIO_base+0x0b28)
#define    GPIO_R1_OFFSET_TO_NEXT                   0x10
#define    GPIO_R1_REG_MAX_NUM                      1
#define    GPIO_R1_REG_BITS                         32
#define    GPIO_R1_ONE_CONTROL_BITS                 1
#define    GPIO_R1_ONE_REG_CONTROL_NUM              32
#define    GPIO_R1_REG0    GPIO_HWORD_REG_VAL(R1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 10, NULL, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, NULL, NULL, NULL, NULL, 26, 27, 28, 29, NULL, 31)
#define    GPIO_R1_REG1    GPIO_HWORD_REG_VAL(R1, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, NULL, NULL, 45, 46, 47, 48, 49, 50, 51, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
#define    GPIO_R1_ALL_VALUE     GPIO_R1_REG0,GPIO_R1_REG1

#define    CLKO_MODE0                               (GPIO_base+0x0e00)
#define    GPIO_CLK_MODE_OFFSET_TO_NEXT             0x10
#define    GPIO_CLK_MODE_REG_MAX_NUM                5
#define    GPIO_CLOCK_SEL_REG_BITS                  32
#define    GPIO_CLOCK_SEL_ONE_CONTROL_BITS          4
#define    GPIO_CLOCK_SEL_ONE_REG_CONTROL_NUM       1
#define    GPIO_F32K_CK                             0x04
#define    GPIO_HAVE_MAX_MODE                       9
#define    GPIO_DDIE_MIN_GPIO_PIN                   0
#define    GPIO_DDIE_MAX_GPIO_PIN                   55

#define    GPIO_PUPD_R_MAP   NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 10, NULL, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, NULL, NULL, NULL, NULL, 26, 27, 28, 29, NULL, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, NULL, NULL, 45, 46, 47, 48, 49, 50, 51


#define    GPIO_WORD_VAR0(name)    GPIO_WORD_VAR_FOR_1BIT(name, 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  31)
#define    GPIO_WORD_VAR1(name)    GPIO_WORD_VAR_FOR_1BIT(name, 32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47,  48, 49,  50,  51,  52,  53,  54,  55,  NULL,  NULL,  NULL,  NULL,  NULL,  NULL,  NULL,  NULL)
#define    GPIO_DIR_IN_ALLOWED_ARRAY    GPIO_WORD_VAR0(DIR_IN),GPIO_WORD_VAR1(DIR_OUT)
#define    GPIO_DIR_OUT_ALLOWED_ARRAY    GPIO_WORD_VAR0(DIR_OUT),GPIO_WORD_VAR1(DIR_OUT)
#define    GPIO_CHECK_FOR_READ_ARRAY    0xffffffff,0xffffffff
#define    GPIO_CHECK_FOR_WRITE_ARRAY    0xffffffff,0xffffffff
#define    GPIO_MODE_ALLOWED_ARRAY    { GPIO_WORD_VAR0(MODE0),GPIO_WORD_VAR0(MODE1),GPIO_WORD_VAR0(MODE2),GPIO_WORD_VAR0(MODE3),GPIO_WORD_VAR0(MODE4),GPIO_WORD_VAR0(MODE5),GPIO_WORD_VAR0(MODE6),GPIO_WORD_VAR0(MODE7),GPIO_WORD_VAR0(MODE8),GPIO_WORD_VAR0(MODE9)} \
,{GPIO_WORD_VAR1(MODE0),GPIO_WORD_VAR1(MODE1),GPIO_WORD_VAR1(MODE2),GPIO_WORD_VAR1(MODE3),GPIO_WORD_VAR1(MODE4),GPIO_WORD_VAR1(MODE5),GPIO_WORD_VAR1(MODE6),GPIO_WORD_VAR1(MODE7),GPIO_WORD_VAR1(MODE8),GPIO_WORD_VAR1(MODE9)}




/*A die macro ****************************************************************************************/


#endif /*!defined(DRV_GPIO_OFF)*/
 #endif   /*_GPIO_HW_MT6260_H*/ 