/******************************************************************************
 * track_drv_lcd.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        modem 工程OLED驱动层接口
 *        一般来说不提供给应用层直接访问，应用层track_cust_lcd.h有转接口供应用层访问
 *
 * modification history
 * --------------------
 * v1.0   2014-4-19,  wangqi create this file
 *
 ******************************************************************************/

#if defined (__OLED__)

/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/
#include "track_drv_lcd.h"
#include "track_OS_ELL.h"
#include "us_timer.h"
/*****************************************************************************
 *  Define					宏定义
*****************************************************************************/

#define OLED_CTRLWRITE(y,x)\
{\
    CtrlWrite_SPI(0xb0 + y);\
    CtrlWrite_SPI(0x02 + x);\
    CtrlWrite_SPI(0x10);\
}\

/*****************************************************************************
* Typedef  Enum
*****************************************************************************/


/*****************************************************************************
 *  Struct					数据结构定义
*****************************************************************************/
//static keypad_handle_struct keypad_buff = {0};

/*****************************************************************************
* Local variable				局部变量
*****************************************************************************/
#define START_SP_COLS           2                     //Start space colums
#define TIME_SP_COLS            6        //时间两侧
#define START_TIME_COLS         START_SP_COLS+20+TIME_SP_COLS-1     //Start space colums
#define NUMBER_SP_COLS          2
#define OLED_ROWS                   (OLED_HEIGTH / 8)

#define NUMBER_WIDTH                17
#define NUMBER_BUF_SIZE             NUMBER_WIDTH * OLED_ROWS
#define COLON_WIDTH                 7

static char OLED_BUFFER[4][128] =   {0};

static kal_bool lcd_sleepin = 0;
static kal_bool lcd_init_ok = 0;
static kal_bool lcd_sos_dispaly = 0;


static lcd_mode_position oled_lcd_position[LCD_MODE_SIZE_MAX] =
{ /*row col endcol hight width*/
    {0, 0,                                              4,  START_SP_COLS-1},//起始位空白
    
    {0, START_SP_COLS,                                  2,  10},//
    {0, START_SP_COLS+10,                               2,  10},//
    {2, START_SP_COLS,                                  2,  10},//
    {2, START_SP_COLS+10,                               2,  10},//
    
    {0, START_SP_COLS+20,                               4,  TIME_SP_COLS}, //5 GSM前面的空白
    
    {0, START_TIME_COLS,                                4,  NUMBER_WIDTH},//第一个数据
    {0, START_TIME_COLS+NUMBER_WIDTH,                   4,  NUMBER_WIDTH},//第二个数据 
    {0, START_TIME_COLS+NUMBER_WIDTH*2,                 4,  COLON_WIDTH}, //冒号
    {0, START_TIME_COLS+COLON_WIDTH+NUMBER_WIDTH*2,     4,  NUMBER_WIDTH},//数字
    /*10*/{0, START_TIME_COLS+COLON_WIDTH+NUMBER_WIDTH*3,     4,  NUMBER_WIDTH}, //数字
    
    {0, START_TIME_COLS+COLON_WIDTH+NUMBER_WIDTH*4,     4,  TIME_SP_COLS}, //5 GSM前面的空白
    
    {0, START_TIME_COLS+COLON_WIDTH+NUMBER_WIDTH*4+TIME_SP_COLS,   2,  NUMBER_WIDTH+1}, //GSM
    {2, START_TIME_COLS+COLON_WIDTH+NUMBER_WIDTH*4+TIME_SP_COLS,   2,  NUMBER_WIDTH+1}, //电池标
    //{0, START_TIME_COLS+COLON_WIDTH+NUMBER_WIDTH*5+NUMBER_SP_COLS*4+TIME_SP_COLS,   4,  NUMBER_SP_COLS-1} //
    {0, 28,   4,  45}, //SOS
    {0, 78,   4,  11}, //
    {0, 89,   4,  11}, //
    {0, 100,  4,  11} //
    
};
static kal_uint8 dZero[] = 
{
    0x0, 0x1f, 0x3f, 0x70, 0x60, 0x60, 0x70, 0x3f, 0x1f, 0x0,
    0x0, 0xf8, 0xfc, 0x0e, 0x06, 0x06, 0x0e, 0xfc, 0xf8, 0x0
};
static kal_uint8 dOne[] = 
{
    0x0, 0x0, 0x0C, 0x1C, 0x38, 0x7F, 0x7f, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x0, 0x0, 0x0
};
static kal_uint8 dTwo[] = 
{
    0x00, 0x18, 0x38, 0x70, 0x60, 0x60, 0x71, 0x3f, 0x1e, 0x00, 
    0x00, 0x06, 0x0e, 0x1e, 0x36, 0x66, 0xc6, 0x06, 0x06, 0x00
};
static kal_uint8 dThree[] = 
{
    0x00, 0x10, 0x38, 0x71, 0x61, 0x61, 0x63, 0x3f, 0x1e, 0x00, 
    0x00, 0x18, 0x1c, 0x0e, 0x06, 0x06, 0x06, 0xfc, 0x78, 0x00
};
static kal_uint8 dFour[] = 
{
    0x00, 0x00, 0x01, 0x07, 0x1e, 0x38, 0x7f, 0x7f, 0x00, 0x00, 
    0x00, 0x70, 0xf0, 0xb0, 0x30, 0x30, 0xfe, 0xfe, 0x30, 0x00
};
static kal_uint8 dFive[] = 
{
    0x00, 0x3f, 0x7f, 0x61, 0x63, 0x63, 0x63, 0x61, 0x00, 0x00, 
    0x00, 0x98, 0x9c, 0x86, 0x06, 0x06, 0x06, 0xfc, 0xf8, 0x00
};
static kal_uint8 dSix[] = 
{
    0x00, 0x0f, 0x3f, 0x31, 0x63, 0x63, 0x73, 0x39, 0x18, 0x00, 
    0x00, 0x70, 0xfc, 0x8e, 0x86, 0x86, 0x86, 0xfc, 0xf8, 0x00
};
static kal_uint8 dSeven[] = 
{
    0x00, 0x60, 0x60, 0x60, 0x60, 0x63, 0x6f, 0x78, 0x60, 0x00, 
    0x00, 0x00, 0x00, 0x1e, 0xfe, 0xe0, 0x00, 0x00, 0x00, 0x00
};
static kal_uint8 dEight[] = 
{
    0x00, 0x1e, 0x3f, 0x61, 0x61, 0x61, 0x61, 0x3f, 0x1e, 0x00, 
    0x00, 0x78, 0xfc, 0x86, 0x86, 0x86, 0x86, 0xfc, 0x78, 0x00
};
static kal_uint8 dNine[] = 
{
    0x00, 0x1f, 0x3f, 0x70, 0x60, 0x60, 0x61, 0x3f, 0x1f, 0x00, 
    0x00, 0x98, 0x9c, 0xce, 0xc6, 0xc6, 0x8c, 0xfc, 0xf0, 0x00
};

static kal_uint8 Zero[] = 
{
    0x00, 0x01, 0x03, 0x07, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x07, 0x03, 0x01, 0x00,
    0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00,
    0x00, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0x7F, 0x00,
    0x00, 0xc0, 0xc0, 0xa0, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0xa0, 0xc0, 0xc0, 0x00
};
static kal_uint8 One[] = 
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
static kal_uint8 Two[] = 
{
    0x00, 0x00, 0x04, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x07, 0x03, 0x01, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFF, 0xFF, 0xFF, 0x00,
    0x00, 0x7F, 0xFF, 0xFF, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00,
    0x00, 0x80, 0xc0, 0xa0, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x20, 0x00, 0x00, 0x00
};
static kal_uint8 Three[] = 
{
    0x00, 0x00, 0x00, 0x04, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x07, 0x03, 0x01, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFF, 0xFF, 0xFF, 0x00,
    0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xFF, 0xFF, 0x7F, 0x00,
    0x00, 0x00, 0x00, 0x20, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0xa0, 0xc0, 0xc0, 0x00
};
static kal_uint8 Four[] = 
{
    0x00, 0x01, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x01, 0x00,
    0x00, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFF, 0xFF, 0xFF, 0x00,
    0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xFF, 0xFF, 0x7F, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x80, 0x00
};
static kal_uint8 Five[] = 
{
    0x00, 0x01, 0x03, 0x07, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x06, 0x00, 0x00, 0x00,
    0x00, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xFF, 0xFF, 0x7F, 0x00,
    0x00, 0x00, 0x00, 0x20, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0xa0, 0xc0, 0x80, 0x00
};
static kal_uint8 Six[] = 
{
    0x00, 0x01, 0x03, 0x07, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x04, 0x00, 0x00, 0x00,
    0x00, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x7f, 0xff, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xFF, 0xFF, 0x7F, 0x00,
    0x00, 0x00, 0xc0, 0xa0, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0xa0, 0xc0, 0x80, 0x00
};
static kal_uint8 Seven[] = 
{
    0x00, 0x00, 0x00, 0x04, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x07, 0x03, 0x01, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0x7F, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x80, 0x00
};
static kal_uint8 Eight[] = 
{
    0x00, 0x01, 0x03, 0x07, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x07, 0x03, 0x01, 0x00,
    0x00, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFF, 0xFF, 0xFF, 0x00,
    0x00, 0x7F, 0xFF, 0xFF, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xFF, 0xFF, 0x7F, 0x00,
    0x00, 0x00, 0xc0, 0xa0, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0xa0, 0xc0, 0x80, 0x00
};
static kal_uint8 Nine[] = 
{
    0x00, 0x01, 0x03, 0x07, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x07, 0x03, 0x01, 0x00,
    0x00, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFF, 0xFF, 0xFF, 0x00,
    0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xFF, 0xFF, 0x7F, 0x00,
    0x00, 0x00, 0x00, 0x20, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0xa0, 0xc0, 0x80, 0x00
};
static kal_uint8 Colon[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x38, 0x38, 0x38, 0x00, 0x00, 
    0x00, 0x00, 0x1c, 0x1c, 0x1c, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static char Signal_0[] =
{
    0x30, 0x28, 0x24, 0x22, 0x3f, 0x3f, 0x22, 0x24, 0x28, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static char Signal_1[] =
{
    0x30,0x28,0x24,0x22,0x3f,0x3f,0x22,0x24,0x28,0x30,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
    0x0,0x0,0x0,0x0,0xf8,0xf8,0x0,0x18,0x18,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0
};
static char Signal_2[] =
{
    0x30,0x28,0x24,0x22,0x3f,0x3f,0x22,0x24,0x28,0x30,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
    0x0,0x0,0x0,0x0,0xf8,0xf8,0x0,0x18,0x18,0x0,0x78,0x78,0x0,0x0,0x0,0x0,0x0,0x0
};
static char Signal_3[] =
{
    0x30,0x28,0x24,0x22,0x3f,0x3f,0x22,0x24,0x28,0x30,0x0,0x0,0x0,0x1,0x1,0x0,0x0,0x0,
    0x0,0x0,0x0,0x0,0xf8,0xf8,0x0,0x18,0x18,0x0,0x78,0x78,0x0,0xf8,0xf8,0x0,0x0,0x0
};
static char Signal_4[] =
{
    0x30,0x28,0x24,0x22,0x3f,0x3f,0x22,0x24,0x28,0x30,0x0,0x0,0x0,0x1,0x1,0x0,0x7,0x7,
    0x0,0x0,0x0,0x0,0xf8,0xf8,0x0,0x18,0x18,0x0,0x78,0x78,0x0,0xf8,0xf8,0x0,0xf8,0xf8
};

static char Gps[] =
{
    0x0,0xf,0xf,0x7,0x3,0x1,0x3,0x49,0x4a,0x6c,0x27,0x30,0x1c,0x7,0x0,0x0,0x0,0x0,
    0x0,0xf0,0xf8,0xfc,0xfc,0xfc,0xfc,0xfc,0xbc,0x1c,0xc,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
};

static char EChr[] = 
{
    0x00, 0x03, 0x3f, 0x20, 0x22, 0x22, 0x2f, 0x2f, 0x2f, 0x27, 0x23, 0x21, 0x21, 0x2f, 0x2f, 0x20, 0x3f, 0x0,
    0x00, 0xc0, 0xfc, 0x04, 0x44, 0x44, 0xf4, 0xf4, 0xf4, 0xe4, 0xc4, 0x84, 0x84, 0xf4, 0xf4, 0x04, 0xfc, 0x0
};

static char EChrOK[] = 
{
    0x00, 0x03, 0x3f, 0x20, 0x20, 0x23, 0x24, 0x24, 0x23, 0x20, 0x27, 0x21, 0x22, 0x24, 0x20, 0x20, 0x3f, 0x0,
    0x00, 0xc0, 0xfc, 0x04, 0x04, 0xc4, 0x24, 0x24, 0xc4, 0x04, 0xe4, 0x84, 0x44, 0x24, 0x04, 0x04, 0xfc, 0x0
};

static char ELOW[] = 
{
    0x00, 0x03, 0x3f, 0x20, 0x20, 0x21, 0x23, 0x27, 0x2d, 0x29, 0x21, 0x20, 0x20, 0x2f, 0x2f, 0x20, 0x3f, 0x0,
    0x00, 0xc0, 0xfc, 0x04, 0x04, 0x84, 0x94, 0xb4, 0xe4, 0xc4, 0x84, 0x04, 0x04, 0xf4, 0xf4, 0x04, 0xfc, 0x0
};

static char EBat1[] = 
{
    0x00, 0x03, 0x3f, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3f, 0x0,
    0x00, 0xc0, 0xfc, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xfc, 0x0
};

static char EBat2[] = 
{
    0x00, 0x03, 0x3f, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x2f, 0x2f, 0x20, 0x3f, 0x0,
    0x00, 0xc0, 0xfc, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xf4, 0xf4, 0x04, 0xfc, 0x0
};

static char EBat3[] = 
{
    0x00, 0x03, 0x3f, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x2f, 0x2f, 0x20, 0x2f, 0x2f, 0x20, 0x3f, 0x0,
    0x00, 0xc0, 0xfc, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xf4, 0xf4, 0x04, 0xf4, 0xf4, 0x04, 0xfc, 0x0
};

static char EBat4[] = 
{
    0x00, 0x03, 0x3f, 0x20, 0x20, 0x20, 0x20, 0x2f, 0x2f, 0x20, 0x2f, 0x2f, 0x20, 0x2f, 0x2f, 0x20, 0x3f, 0x0,
    0x00, 0xc0, 0xfc, 0x04, 0x04, 0x04, 0x04, 0xf4, 0xf4, 0x04, 0xf4, 0xf4, 0x04, 0xf4, 0xf4, 0x04, 0xfc, 0x0
};

static char EBat5[] = 
{
    0x00, 0x03, 0x3f, 0x20, 0x2f, 0x2f, 0x20, 0x2f, 0x2f, 0x20, 0x2f, 0x2f, 0x20, 0x2f, 0x2f, 0x20, 0x3f, 0x0,
    0x00, 0xc0, 0xfc, 0x04, 0xf4, 0xf4, 0x04, 0xf4, 0xf4, 0x04, 0xf4, 0xf4, 0x04, 0xf4, 0xf4, 0x04, 0xfc, 0x0
};
//45*4  三行为一行
static char sos[] = 
{
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 
    
    0x00, 0x3e, 0xff, 0xff, 0xe7, 0xc7, 0xc3, 0xc3, 0xc1, 0xe1, 0xf0, 0x70, 0x30, 0x00, 0x00, 
    0x07, 0x3f, 0x7f, 0xf8, 0xe0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xf8, 0x7f, 0x3f, 0x07, 
    0x00, 0x00, 0x00, 0x3e, 0xff, 0xff, 0xe7, 0xc7, 0xc3, 0xc3, 0xc1, 0xe1, 0xf0, 0x70, 0x30, 

    0x0c, 0x0f, 0x0f, 0x87, 0x83, 0xc1, 0xc1, 0xc1, 0xe1, 0xe3, 0xff, 0xff, 0x3e, 0x00, 0x00, 
    0xf0, 0xfe, 0xff, 0x0f, 0x03, 0x03, 0x01, 0x01, 0x01, 0x03, 0x03, 0x0f, 0xff, 0xfe, 0xf0, 
    0x00, 0x00, 0x0c, 0x0f, 0x0f, 0x87, 0x83, 0xc1, 0xc1, 0xc1, 0xe1, 0xe3, 0xff, 0xff, 0x3e, 

    0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00 
};
static char sosdot[] = 
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,  
    0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
};

typedef enum 
{
    DATE0= 0,
    DATE1,
    DATE2,
    DATE3,
    DATE4,
    DATE5,
    DATE6,
    DATE7,
    DATE8,
    DATE9,
    ZERO0 , 
    ONE1,
    TWO2,
    THRESS3,
    FOUR4,
    FIVE5,
    SIX6,
    SEVEN7,
    EIGHT8,
    NINE9,
    COLON20,
    SIGNAL0_21,
    SIGNAL_BASE = SIGNAL0_21,
    SIGNAL1_22,
    SIGNAL2_23,
    SIGNAL3_24,
    SIGNAL4_25,
    BATLOW,
    BAT1,
    BAT2,
    BAT3,
    BAT4,
    BAT5,
    ECHARIN,
    ECHAROK,
    SOS_SIGN,
    SOSDOT1,
    SOSDOT2,
    SOSDOT3,
    GPS26,
    SOURCES_ITEM_MAX
}sources_item_enum;

static lcd_source Soruces[] =
{
    {20, dZero},
    {20, dOne},
    {20, dTwo},
    {20, dThree},
    {20, dFour},
    {20, dFive},
    {20, dSix},
    {20, dSeven},
    {20, dEight},
    {20, dNine},
    {68, Zero},
    {68, One},
    {68, Two},
    {68, Three},
    {68, Four},
    {68, Five},
    {68, Six},
    {68, Seven},
    {68, Eight},
    {68, Nine},
    {28, Colon},//20
    {36, Signal_0},
    {36, Signal_1},
    {36, Signal_2},
    {36, Signal_3},
    {36, Signal_4},
    {36, ELOW},
    {36, EBat1},
    {36, EBat2},
    {36, EBat3},
    {36, EBat4},
    {36, EBat5},
    {36, EChr},
    {36, EChrOK},
    {180, sos},
    {44, sosdot},
    {36, Gps},
};


/****************************************************************************
* Global Variable - Extern          全局变量
*****************************************************************************/

/****************************************************************************
* Global Variable - Extern              引用全局变量
*****************************************************************************/


/*****************************************************************************
 *  Local Functions			本地函数
*****************************************************************************/

static void Delayus(kal_uint32 u4MicroSec)
{
    ust_busy_wait(u4MicroSec);
}

static void LCD_Delay(kal_uint32 delay_count)
{
    volatile kal_uint32 delay;
    for(delay = 0; delay < (delay_count * 4); delay++) {}
}
/******************************************************************************
 *  Function    -  DataWrite_SPI
 *  Purpose     -  
 *  Description -  写数据
 *  
 *  modification history
 * ----------------------------------------
 * v1.0  , 2014-4-19,  wangqi  written
 * ----------------------------------------
*******************************************************************************/
static void DataWrite_SPI(unsigned char Data)
{
    unsigned char i;
    LOGD(L_DRV, L_V7, "Data:0x%x", Data);
    GPIO_WriteIO(0, SUBLCD_CS_PIN);
    GPIO_WriteIO(1, SUBLCD_DC_PIN);

    for(i = 0; i < 8; i++)
    {
        SET_SUBLCD_CLK_LOW;
        if((Data & (1 << i)))
        {
            SET_SUBLCD_DATA_HIGH;
        }
        else
        {
            SET_SUBLCD_DATA_LOW;
        }
        Delayus(2);

        SET_SUBLCD_CLK_HIGH;
        Delayus(1);
    }


    GPIO_WriteIO(1, SUBLCD_DC_PIN);
    GPIO_WriteIO(1, SUBLCD_CS_PIN);
}
/******************************************************************************
 *  Function    -  CtrlWrite_SPI
 *  Purpose     -  
 *  Description -  写指令
 *  
 *  modification history
 * ----------------------------------------
 * v1.0  , 2014-4-19,  wangqi  written
 * ----------------------------------------
*******************************************************************************/
static void CtrlWrite_SPI(unsigned char ins)
{
    unsigned char m, da;
    unsigned int i;
    LOGD(L_DRV, L_V8, "0x%x", ins);
    GPIO_WriteIO(0, SUBLCD_CS_PIN);
    GPIO_WriteIO(0, SUBLCD_DC_PIN);

    da = ins;

    for(i = 0; i < 8; i++)
    {
        m = da;
        SET_SUBLCD_CLK_LOW;
        m = m & 0x80;
        if(m == 0x80)
        {
            SET_SUBLCD_DATA_HIGH;
        }
        else
        {
            SET_SUBLCD_DATA_LOW;
        }
        Delayus(2);
        da = da << 1;
        SET_SUBLCD_CLK_HIGH;
        Delayus(1);
    }

    //GPIO_WriteIO(1,SUBLCD_DC_PIN);
    GPIO_WriteIO(1, SUBLCD_CS_PIN);
}
/******************************************************************************
 *  Function    -  track_drv_lcd_write
 *  Purpose     -  
 *  Description -  唯一对屏进行写入提供给应用层用的接口
 *  
 *  modification history
 * ----------------------------------------
 * v1.0  , 2014-4-19,  wangqi  written
 * ----------------------------------------
*******************************************************************************/
void track_drv_lcd_write(void)
{
    kal_uint8 row, col, i, in;
    
    if(lcd_sleepin)
    {
        return;
    }
    
    for(row = 0; row < OLED_ROWS; row++)
    {
        OLED_CTRLWRITE(row, 0);
#if 0
        for(i = 0; i < 4; i++)
        {
            in = i * 32;
            
        LOGD(L_DRV, L_V7, "[%d %d-%d]0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x",
            row,i*32,(i + 1)*32,OLED_BUFFER[row][in+0],OLED_BUFFER[row][in+1],OLED_BUFFER[row][in+2],OLED_BUFFER[row][in+3],OLED_BUFFER[row][in+4],
            OLED_BUFFER[row][in+5],OLED_BUFFER[row][in+6],OLED_BUFFER[row][in+7],OLED_BUFFER[row][in+8],OLED_BUFFER[row][in+9],
            OLED_BUFFER[row][in+10],OLED_BUFFER[row][in+11],OLED_BUFFER[row][in+12],OLED_BUFFER[row][in+13],OLED_BUFFER[row][in+14],
            OLED_BUFFER[row][in+15],OLED_BUFFER[row][in+16],OLED_BUFFER[row][in+17],OLED_BUFFER[row][in+18],OLED_BUFFER[row][in+19],
            OLED_BUFFER[row][in+20],OLED_BUFFER[row][in+21],OLED_BUFFER[row][in+22],OLED_BUFFER[row][in+23],OLED_BUFFER[row][in+24],
            OLED_BUFFER[row][in+25],OLED_BUFFER[row][in+26],OLED_BUFFER[row][in+27],OLED_BUFFER[row][in+28],OLED_BUFFER[row][in+29],
            OLED_BUFFER[row][in+30],OLED_BUFFER[row][in+31]);
        }
#endif
        for(col = 0; col < OLED_WIDTH; col++)
        {
            DataWrite_SPI(OLED_BUFFER[row][col]);//写
        }
    }
}
/******************************************************************************
 *  Function    -  track_drv_spi_set_background
 *  Purpose     -  
 *  Description -  全写白
 *  
 *  modification history
 * ----------------------------------------
 * v1.0  , 2014-4-19,  wangqi  written
 * ----------------------------------------
*******************************************************************************/
void track_drv_spi_set_background(char d)
{
    kal_uint8 i = 0, j;

    for(i = 0; i < OLED_ROWS; i++)
    {   
        //OLED_CTRLWRITE(i, 0);
        for(j = 0; j < OLED_WIDTH; j++)
        {
            OLED_BUFFER[i][j] = d;//写白
            //DataWrite_SPI(d);//写
        }
    }
    track_drv_lcd_write();
}
/******************************************************************************
 *  Function    -  track_drv_Init_OLED_IC
 *  Purpose     -  
 *  Description -  OLED驱动初始化
 *  
 *  modification history
 * ----------------------------------------
 * v1.0  , 2014-4-19,  wangqi  written
 * ----------------------------------------
*******************************************************************************/
void track_drv_Init_OLED_IC(void)
{
    GPIO_ModeSetup(SUBLCD_CS_PIN, 0);
    GPIO_InitIO(1, SUBLCD_CS_PIN);
    GPIO_WriteIO(1, SUBLCD_CS_PIN);

    GPIO_ModeSetup(SUBLCD_DC_PIN, 0);
    GPIO_InitIO(1, SUBLCD_DC_PIN);
    GPIO_WriteIO(1, SUBLCD_DC_PIN);

    GPIO_ModeSetup(SUBLCD_CLK_PIN, 0);
    GPIO_InitIO(1, SUBLCD_CLK_PIN);
    GPIO_WriteIO(1, SUBLCD_CLK_PIN);

    GPIO_ModeSetup(SUBLCD_DATA_PIN, 0);
    GPIO_InitIO(1, SUBLCD_DATA_PIN);
    GPIO_WriteIO(1, SUBLCD_DATA_PIN);

//      GPIO_ModeSetup( SUBLCD_PWREN_PIN, 0 );
//      GPIO_InitIO( 1, SUBLCD_PWREN_PIN );
//      GPIO_WriteIO( 1, SUBLCD_PWREN_PIN );
//      LCDDelayms(10);

    GPIO_ModeSetup(SUBLCD_RESET_PIN, 0); //serial LCD chip select 1 LSRSTB#
    GPIO_WriteIO(0, SUBLCD_RESET_PIN);
    Delayus(5);
    
    GPIO_WriteIO(1, SUBLCD_RESET_PIN);

    CtrlWrite_SPI(0xAE);     //Display Off
    CtrlWrite_SPI(0xd5);     //Divide Ratio/Oscillator Frequency Mode Set
    CtrlWrite_SPI(0x91);     //
    CtrlWrite_SPI(0xA8);     //Multiplex Ration Mode Set
    CtrlWrite_SPI(0x1f);
    
    CtrlWrite_SPI(0xD3);     //Display Offset Mode Set D3
    
    //CtrlWrite_SPI(0x2E);     //-------10 与C8正常显示-20140613-----2E与C0对应上下翻转-------
    /*0x2E时分辨率实际不128*30*/
    //CtrlWrite_SPI(0x31);
    CtrlWrite_SPI(0x31);
    
    CtrlWrite_SPI(0x40);     //Set Display Start Line
    
    CtrlWrite_SPI(0xAD);     //DC-DC Control Mode Set
    //CtrlWrite_SPI(0x8a);     //DC-DC ON/OFF Mode Set
    CtrlWrite_SPI(0x8b);     //DC-DC ON/OFF Mode Set
    //CtrlWrite_SPI(0x30);     //0x33是9V，0x32是8.4V，0x31是8.0V，0x30是7.4V
    CtrlWrite_SPI(0x31);     //0x33是9V，0x32是8.4V，0x31是8.0V，0x30是7.4V
    
    CtrlWrite_SPI(0xA0);     //Set Segment Re-map A1 水平翻转的 
    //----------------------------------
    CtrlWrite_SPI(0xC0);     //Set Common Output Scan Direction:C8  C0是上下翻转的      
    //----------------------------------
    CtrlWrite_SPI(0xDA);    //Common Pads Hardware Configuration Mode Set
    CtrlWrite_SPI(0x12);
    /*对比度*/
    CtrlWrite_SPI(0x81);     //The Contrast Control Mode Set
    
    CtrlWrite_SPI(0x80);     //
    CtrlWrite_SPI(0xD9);     //Pre-charge Period Mode Set:
    CtrlWrite_SPI(0x1f);
    CtrlWrite_SPI(0xDB);     //VCOM Deselect Level Mode Set
    CtrlWrite_SPI(0x25);     //
    
    CtrlWrite_SPI(0xA4);     //Set Entire Display OFF/ON
    
    CtrlWrite_SPI(0xA6);     //Set Normal/Reverse Display
    CtrlWrite_SPI(0xAF);     //Display On
    
    lcd_sleepin = 0;
    lcd_init_ok = 1;
    
//  track_drv_spi_set_background(0xAA);

}

void track_drv_lcd_reset(void)
{
    GPIO_ModeSetup(SUBLCD_RESET_PIN, 0); //serial LCD chip select 1 LSRSTB#
    GPIO_WriteIO(0, SUBLCD_RESET_PIN);
    Delayus(3);
}

/******************************************************************************
 *  Function    -  lcd_updata_number
 *  Purpose     -  
 *  Description -  根据位置更新数字列
 *  pIndex 位置 oled_lcd_position    number 资源号 Soruces
 *  modification history
 * ----------------------------------------
 * v1.0  , 2014-4-19,  wangqi  written
 * ----------------------------------------
*******************************************************************************/
static void lcd_updata_number(int pIndex, int number)
{
    int row = 0, column = 0, end_row, end_col = 0, index = 0;

    if(pIndex >= LCD_MODE_SIZE_MAX)
    {
        LOGS("lcd_updata_number:%d",pIndex);
        return;
    }
    
    end_row = oled_lcd_position[pIndex].row+oled_lcd_position[pIndex].hight;
    
    if(end_row > OLED_ROWS)
    {
        LOGS("lcd_updata_number: row outof rangs:%d",end_row);
        return;
    }
    
    end_col = oled_lcd_position[pIndex].column + oled_lcd_position[pIndex].width;
    for(row = oled_lcd_position[pIndex].row; row < end_row; row++)
    {
        //OLED_CTRLWRITE(row, oled_lcd_position[pIndex].column);
        for(column = oled_lcd_position[pIndex].column; column < end_col; column++)
        {
            if(index >= Soruces[number].length)
            {
                return;
            }
            OLED_BUFFER[row][column] = Soruces[number].data[index];
            //DataWrite_SPI(Soruces[number].data[index]);//写
            index ++;
        }
    }
}


/******************************************************************************
 *  Function    -  lcd_updata_space
 *  Purpose     -  
 *  Description -  根据位置更新占位符列
 *  
 *  modification history
 * ----------------------------------------
 * v1.0  , 2014-4-19,  wangqi  written
 * ----------------------------------------
*******************************************************************************/
static void lcd_updata_space(int pIndex)
{
    int row = 0, column = 0, end_col = 0;

    end_col = oled_lcd_position[pIndex].column + oled_lcd_position[pIndex].width;
    for(row = oled_lcd_position[pIndex].row; row < OLED_ROWS; row++)
    {
        //OLED_CTRLWRITE(row, oled_lcd_position[pIndex].column);
        for(column = oled_lcd_position[pIndex].column; column < end_col; column++)
        {
            OLED_BUFFER[row][column] = 0x00;
            //DataWrite_SPI(0x00);//写
        }
    }
}

/******************************************************************************
 *  Function    -  track_drv_lcd_write_time
 *  Purpose     -  更新时间
 *  Description -  传入当前时间，小时分钟
 *  整个时间有4个数字和1个符号，5部分组成另外要加6个空白做间隔
 *  modification history
 * ----------------------------------------
 * v1.0  , 2014-4-19,  wangqi  written
 * ----------------------------------------
*******************************************************************************/
void track_drv_lcd_write_time(kal_uint8 month, kal_uint8 day, kal_uint8 hour, kal_uint8 mins)
{
    kal_uint8 monH = month / 10, monL = month % 10;
    kal_uint8 dayH = day / 10, dayL = day % 10;
    kal_uint8 hourH = hour / 10, hourL = hour % 10;
    kal_uint8 minsH = mins / 10, minsL = mins % 10;

    if(hourH  > 2)
    {
        hourH = 0;
    }
    if(hourL > 0x0A)
    {
        hourL = 0;
    }
    if(minsH > 5)
    {
        minsH = 0;
    }
    if(minsL > 0x0A)
    {
        minsL = 0;
    }
    if(month > 12)
    {
        monH = 0;
        monL = 0;
    }
    if(day > 31)
    {
        dayH = 0;
        dayL = 0;
    }

    LOGD(L_DRV, L_V5, "mon[%d,%d,%d] day[%d,%d,%d] Hour:%d%d,Min:%d%d",month, day, monH, monL, dayH, dayL, hourH, hourL, minsH, minsL);
    
    //lcd_updata_space(0);
    lcd_updata_number(1, monH);
    lcd_updata_number(2, monL);
    lcd_updata_number(3, dayH);
    lcd_updata_number(4, dayL);
    
    lcd_updata_space(5);
    
    lcd_updata_number(6, hourH+10);
    lcd_updata_number(7, hourL+10);
    lcd_updata_number(8, COLON20);//maohao
    lcd_updata_number(9, minsH+10);
    lcd_updata_number(10, minsL+10);
    lcd_updata_space(11);//gsm前面空白
    
    //drv_lcd_write();
}


/******************************************************************************
 *  Function    -  track_drv_lcd_updata_gsm
 *  Purpose     -  
 *  Description -  更新GSM图标
 *  [0-31]
 *  modification history
 * ----------------------------------------
 * v1.0  , 2014-4-19,  wangqi  written
 * ----------------------------------------
*******************************************************************************/
void track_drv_lcd_updata_gsm(int level)
{
    LOGD(L_DRV, L_V6, "sleep:%d ,gsm level:%d", lcd_sleepin, level);

    if(level > 4)
    {
        LOGS("track_drv_lcd_updata_gsm: gsm level outof rangs:%d",level);
        return;
    }

    if(lcd_sleepin)
    {
        return;
    }
    lcd_updata_number(12, SIGNAL_BASE + level);
    lcd_updata_space(11);//gsm后面空白
    //drv_lcd_write();
    
}

kal_bool track_drv_lcd_is_sos(void)
{
    LOGD(L_DRV, L_V5,"%d", lcd_sos_dispaly);
    return lcd_sos_dispaly;
}
/******************************************************************************
 *  Function    -  track_drv_lcd_updata_charge
 *  Purpose     -  
 *  Description -  更新电量图标
 *  type  充电状态 :充电中  充电完成  
 *  level 电池电量等级
 *  modification history
 * ----------------------------------------
 * v1.0  , 2014-4-19,  wangqi  written
 * ----------------------------------------
*******************************************************************************/
void track_drv_lcd_updata_charge(kal_uint8 type, kal_uint8 level)
{
    kal_uint8 lev = level;
    LOGD(L_DRV, L_V5, "sleepin:%d type :%d level:%d",lcd_sleepin, type, level);


    if(lcd_sleepin)
    {
        return;
    }
    if(lcd_init_ok == 0)
    {
        track_drv_Init_OLED_IC();
        Delayus(50);
    }
    if(lev > 5)
    {
        lev = 5;
    }
    if(type > 4)
    {
        return;
    }
    
    if(type == 1)
    {
        lcd_updata_number(13, ECHARIN);
    }
    else if(type == 3)
    {
        lcd_updata_number(13, ECHAROK);
    }
    else if(type == 4)
    {
        lcd_updata_number(13, BATLOW);//gps
    }
    else
    {
        lcd_updata_number(13, lev + BATLOW);//gps
    }
    
    lcd_updata_space(11);//gsm后面空白
    //drv_lcd_write();
}

void track_drv_lcd_write_sos(void)
{
    static int index = 0, base = 0;
    track_stop_timer(LED_DISPALY_TIMER_ID);
    base = index % 3;
    LOGD(L_DRV, L_V5, "lcd_sleepin:%d, lcd_init_ok:%d, index:%d, base:%d", lcd_sleepin, lcd_init_ok, index, base);

    lcd_sos_dispaly = 1;
    if(lcd_sleepin || lcd_init_ok == 0)
    {
        track_drv_Init_OLED_IC();
        Delayus(50);
    }
    if(0 == base)
    {
        //track_drv_Init_OLED_IC();
        memset(OLED_BUFFER, 0, sizeof(OLED_BUFFER));
        lcd_updata_number(14, 34);
        lcd_updata_number(15, 35);
        index ++ ;
    }
    else if(1 == base)
    {
        lcd_updata_number(16, 35);
        index ++ ;
    }
    else if(2 == base)
    {
        lcd_updata_number(17, 35);
        index ++ ;
    }
    
    if(index != 9)
    {
        tr_start_timer(LED_DISPALY_TIMER_ID, 1000, track_drv_lcd_write_sos);
        track_drv_lcd_write();
    }
    else
    {
        index = 0;
        memset(OLED_BUFFER, 0, sizeof(OLED_BUFFER));
        lcd_sos_dispaly = 0;
        if(1 == lcd_sleepin)
        {
            track_drv_lcd_enter_sleep();
        }
        else
        {
            track_cust_lcd_sos_callback();
            /*逻辑处理不太好，应用层应该放到上面去*/
        }
    }
}


void track_drv_lcd_enter_sleep(void)
{
    LOGD(L_DRV, L_V5, "%d",lcd_sleepin);

    if(0 == track_drv_lcd_is_sos())
    {
        CtrlWrite_SPI(0xAE);			// Set Display On/Off
        CtrlWrite_SPI(0xA4);			// Set Entire Display On / Off
    }

    lcd_sleepin = 1;
    //GPIO_WriteIO( 0, SUBLCD_PWREN_PIN );
}

void track_drv_lcd_exit_sleep(void)
{
    LOGD(L_DRV, L_V5, "%d",lcd_sleepin);
    lcd_sleepin = 0;
    track_drv_Init_OLED_IC();

}


/******************************************************************************
 *  Function    -  track_drv_lcd_display_test
 *  Purpose     -  
 *  Description -  PCBA测试指令
 *  
 *  modification history
 * ----------------------------------------
 * v1.0  , 2014-4-19,  wangqi  written
 * ----------------------------------------
*******************************************************************************/
void track_drv_lcd_display_test(int index)
{
    int row = 0 , i = 0 , tpoint = 0, charWidth = 0;
    LOGS("track_drv_lcd_display_test:%d",index);
    if(1 == index)
    {
        for(row = 0; row < 4; row++)
        {
            //OLED_CTRLWRITE(row, 64);
            //charWidth = ;
            for(i = 0; i < NUMBER_WIDTH; i++)//每个字9位宽
            {
                tpoint = row * NUMBER_WIDTH + i ;
                if(tpoint > NUMBER_BUF_SIZE)break;
                OLED_BUFFER[row][i + 64] = (Soruces[NINE9].data)[tpoint];
                //DataWrite_SPI((Soruces[EIGHT8].data)[tpoint]);//写
            }
        }
        track_drv_lcd_write();
    }
    else if(2 == index)
    {
        track_drv_lcd_write_time(1,1,0,0);
        track_drv_lcd_write();
    }
    else if(3 == index)
    {
        track_drv_lcd_updata_gsm(4);
        track_drv_lcd_write();
    }
    else if(4 == index)
    {
        track_cust_lcd_updata_time();
        track_drv_lcd_write();
    }
    else if(5 == index)
    {
        track_drv_lcd_updata_charge(1,0xff);
        track_drv_lcd_write();
    }
    else if(6 == index)
    {
        track_drv_lcd_updata_charge(3,0xff);
        track_drv_lcd_write();
    }
    else if(7 == index)
    {
        track_drv_lcd_updata_charge(0,0xff);
        track_drv_lcd_write();
    }
    else if(8 == index)
    {
        int in = 0;
        for(row = 0; row < OLED_ROWS; row++)
        {
            for(i = 0; i < 4; i++)
            {
                in = i * 32;
                
            LOGS("[%d %d-%d]0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x0x%x",
                row,i*32,(i + 1)*32,OLED_BUFFER[row][in+0],OLED_BUFFER[row][in+1],OLED_BUFFER[row][in+2],OLED_BUFFER[row][in+3],OLED_BUFFER[row][in+4],
                OLED_BUFFER[row][in+5],OLED_BUFFER[row][in+6],OLED_BUFFER[row][in+7],OLED_BUFFER[row][in+8],OLED_BUFFER[row][in+9],
                OLED_BUFFER[row][in+10],OLED_BUFFER[row][in+11],OLED_BUFFER[row][in+12],OLED_BUFFER[row][in+13],OLED_BUFFER[row][in+14],
                OLED_BUFFER[row][in+15],OLED_BUFFER[row][in+16],OLED_BUFFER[row][in+17],OLED_BUFFER[row][in+18],OLED_BUFFER[row][in+19],
                OLED_BUFFER[row][in+20],OLED_BUFFER[row][in+21],OLED_BUFFER[row][in+22],OLED_BUFFER[row][in+23],OLED_BUFFER[row][in+24],
                OLED_BUFFER[row][in+25],OLED_BUFFER[row][in+26],OLED_BUFFER[row][in+27],OLED_BUFFER[row][in+28],OLED_BUFFER[row][in+29],
                OLED_BUFFER[row][in+30],OLED_BUFFER[row][in+31]);
            }
        }
    }
    else if(9 == index)
    {
        track_drv_lcd_reset();
    }
    else if(10 == index)
    {
        track_drv_lcd_write_sos();
    }
}

#endif /* __OLED__ */

