#include    "keypad.h"
#include 	"sw_keypad.h"
#include  	"us_timer.h"
#ifdef DRV_KBD_SW_KBD
#ifndef     __UBL__
#include 	"stack_common.h"
#include 	"stack_msgs.h"
#include 	"app_ltlcom.h"       /* Task message communiction */
#include 	"syscomp_config.h"
#include 	"drv_comm.h"
#include    "keypad_hw.h"
#include 	"drv_features.h"
#include    "keypad.h"
#include    "dcl.h"
#include    "gpt_sw.h"
#include    "intrCtrl.h"
#include    "kbd_table.h"

#include    "drv_trc.h"
#include 	"task_main_func.h"
#include 	"stack_config.h"
#include 	"kal_trace.h"
#include 	"stack_ltlcom.h"

#include 	"kal_general_types.h"
#include 	"kal_public_api.h"
#include 	"kal_public_defs.h"
#include    "eint.h"
#include    "cache_sw_int.h"
extern void SLA_CustomLogging(kal_char *customJob, kal_uint32 saAction);
#endif

//code review: remove the option,always optional scan
#ifdef SW_KBD_OPTIONAL_SCAN
/******************************************************************
  * bit0~bit7 inidicate  in which col the groups pressed   (double/triple keypad)             * 
  * bit8~bit15 inidicate in which row the groups pressed (double/triple keypad)              *
  * bit16~bit23 inidicate  in which col the keys(KEYr5k or KEYr0) pressed   (triple keypad)   *
  * bit24~bit31 inidicate in which row the keys(KEYr5k or KEYr0) pressed   (triple keypad)    *
  *  1: press 0: release
  *****************************************************************/
kal_uint32 sw_kbd_optional_scan_bit =0;
#endif

kal_uint8  sw_kbd_row[RowNum];
kal_uint8  sw_kbd_col[ColNum];

#ifndef __UBL__
#ifdef SW_KBD_DEBUG
kal_uint32 sw_kbd_eint_hisr_cnt = 0;
kal_uint32 sw_kbd_pass_debounce_cnt = 0;
kal_uint32 sw_kbd_not_pass_debounce_times = 0;
#endif
kal_uint32 Sw_kbd_polling_timer_handler;

kal_uint32 Sw_kbd_debounce_timer_handler;
kal_uint32 Sw_kbd_debounce_timer=1;
#ifdef SW_KBD_DEBUG
kal_uint32 Sw_kbd_performace_test_timer_handler;
#endif

kal_uint8  debouce_state =0;
KEY_STATUS sw_kbd_debounce_key_status;
KEY_STATUS sw_kbd_debounce_key_status_mask;
KEY_STATUS sw_kbd_current_key_status;
extern kbd_struct KBD;
void Sw_kbd_polling_timer_cb(void *parameter);
void Sw_kbd_debounce_timer_cb(void *parameter);

#ifdef SW_KBD_DEBUG
void Sw_kbd_performace_test_timer_cb(void *parameter);
#endif

void sw_kbd_set_timer(kal_uint32 handle, SW_KBD_TIMER_CB cb, kal_uint32 tick);
#endif

void sw_kbd_paremeter_init(void)
{
    /*now it's 5*5 matrix type, if want to change the matrix type,1 modify the the col and row num and 2 init it*/
	sw_kbd_row[0] = gpio_keypad_row0_pin;
    sw_kbd_row[1] = gpio_keypad_row1_pin;
    sw_kbd_row[2] = gpio_keypad_row2_pin;
    sw_kbd_row[3] = gpio_keypad_row3_pin;
    sw_kbd_row[4] = gpio_keypad_row4_pin;
    
    sw_kbd_col[0] = gpio_keypad_col0_pin;
    sw_kbd_col[1] = gpio_keypad_col1_pin;
    sw_kbd_col[2] = gpio_keypad_col2_pin;
    sw_kbd_col[3] = gpio_keypad_col3_pin;
    sw_kbd_col[4] = gpio_keypad_col4_pin; 
/*----------------------------------------------------------------*/
#if defined(__MTK_INTERNAL__) 
#if defined(__FLAVOR_BTDV3_FTE_QVGA_ON_61PHONE__) || defined(__FLAVOR_BTDV3_PLUTO_128X128_ON_61PHONE__) || defined(__FLAVOR_BTDV3_PLUTO_128X128_1LINK_ON_61PHONE__) || defined(__FLAVOR_BTDV3_PLUTO_128X128_ON_61PHONE_BQB__)
/* under construction !*/
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
#endif
/*-----------------------------------------------------------------*/
    

 }
void SW_KBD_SetGPIO(kal_uint8 keypadPin, kal_uint8 setModeCmd, kal_bool outin, kal_bool highlow)
{
    DCL_HANDLE handle;

    DCL_CTRL_DATA_T data;
    GPIO_CTRL_SET_PUPD_R0_R1_T   *prSetPupdR0R1;
    if(keypadPin != 0xff)
    {
        handle = DclGPIO_Open(DCL_GPIO, keypadPin);
        DclGPIO_Control(handle, setModeCmd, NULL);

        if(outin)  /*output*/
        {
            DclGPIO_Control(handle, GPIO_CMD_SET_DIR_OUT, NULL);
            if(highlow) /*ouput high*/
            {
                DclGPIO_Control(handle, GPIO_CMD_WRITE_HIGH, NULL);
            }
            else  /* ouput low*/
            {
                DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, NULL);
            }
        }
        else  /*input and disable PUPD -> hi-z*/
        {
            prSetPupdR0R1 = &(data.rSetPupdR0R1);
            prSetPupdR0R1->fgSetPupd =0;
            prSetPupdR0R1->fgSetR0 =0;
            prSetPupdR0R1->fgSetR1 =0;
            DclGPIO_Control(handle, GPIO_CMD_SET_DIR_IN, NULL);
            DclGPIO_Control(handle, GPIO_CMD_SET_PUPD_R0_R1, &data);

        }

        DclGPIO_Close(handle);
    }
}


#define SW_KBD_ROW_SCAN(x,outin,highlow) SW_KBD_SetGPIO(sw_kbd_row[x], GPIO_CMD_SET_MODE_0,outin, highlow)

#define SW_KBD_COL_SCAN(x,outin,highlow) SW_KBD_SetGPIO(sw_kbd_col[x], GPIO_CMD_SET_MODE_0,outin, highlow)
void sw_kbd_gpio_pupd(kal_uint8 keypadPin,kal_uint32 pupd, kal_uint32 r0, kal_uint32 r1)
{
    DCL_HANDLE handle;
    DCL_CTRL_DATA_T data;
    GPIO_CTRL_SET_PUPD_R0_R1_T   *prSetPupdR0R1;
    if(keypadPin != 0xff)
    {
        handle = DclGPIO_Open(DCL_GPIO, keypadPin);
        DclGPIO_Control(handle, GPIO_CMD_SET_MODE_0, NULL);

        prSetPupdR0R1 = &(data.rSetPupdR0R1);
        prSetPupdR0R1->fgSetPupd =(DCL_BOOL)pupd;
        prSetPupdR0R1->fgSetR0 =(DCL_BOOL)r0;
        prSetPupdR0R1->fgSetR1 =(DCL_BOOL)r1;
        DclGPIO_Control(handle, GPIO_CMD_SET_PUPD_R0_R1, &data);

    }
}

/*triple keypad, chips from 61*/
#if defined(DRV_KBD_TRIPLE_KEYPAD)
/*code review : use macro for R0,R1*/
void SW_KBD_COL_PU(void)
{
	kal_uint32 temp; 
	for(temp = 0; temp<ColNum ;temp++)
	{
		sw_kbd_gpio_pupd(sw_kbd_col[temp],1,0,1);
	}
}

void SW_KBD_COL_PD(void)
{	
	kal_uint32 temp; 
    for(temp = 0; temp<ColNum ;temp++)
    {
        sw_kbd_gpio_pupd(sw_kbd_col[temp],0,0,1);
    }
}
void SW_KBD_ROW_PD_1K(void)
{
	kal_uint32 temp; 
    for(temp=0; temp<RowNum; temp++)
    {
        sw_kbd_gpio_pupd(sw_kbd_row[temp],0,0,1);
    }
}
void SW_KBD_ROW_PD_36K(void)
{
	kal_uint32 temp; 
    for(temp=0; temp<RowNum; temp++)
    {
        sw_kbd_gpio_pupd(sw_kbd_row[temp],0,1,0);
    }
}
void SW_KBD_DISABLE_PUPD(void)
{	
	kal_uint32 temp; 
    for(temp=0; temp<RowNum; temp++)
    {
        sw_kbd_gpio_pupd(sw_kbd_row[temp],0,0,0);
    }
    for(temp=0; temp<ColNum; temp++)
    {
        sw_kbd_gpio_pupd(sw_kbd_col[temp],0,0,0);
    }
}
void sw_kbd_rows_scan_t_key(kal_uint32 row)
{
    kal_uint32 i;

    for(i=0; i<RowNum ; i++)
    {
        if(i==row) //  one row output high
        {
            SW_KBD_ROW_SCAN(i,KAL_TRUE,KAL_TRUE);
        }
        else    //other row hi-z
        {
            SW_KBD_ROW_SCAN(i,KAL_FALSE,KAL_FALSE);
        }
    }
    ust_busy_wait(SW_KBD_ROW_SCAN_TIME);

}
/*group detect*/
void sw_kbd_cols_detect_t_key(kal_uint32 row, KEY_STATUS*  key_status_temp)
{
    kal_uint32 temp;
    kal_uint32  col;
    DCL_HANDLE handle;
    DCL_CTRL_DATA_T data;
    GPIO_CTRL_READ_T   *prRead;
    prRead = &(data.rRead);
    for(col = 0; col < ColNum; col++)
    {
		if(sw_kbd_col[col] == 0xff)
			continue;
        handle = DclGPIO_Open(DCL_GPIO, sw_kbd_col[col]);
        DclGPIO_Control(handle, GPIO_CMD_SET_DIR_IN, NULL);
        DclGPIO_Control(handle, GPIO_CMD_READ, &data);
#ifdef SW_KBD_OPTIONAL_SCAN       
		 sw_kbd_optional_scan_bit |= prRead->u1IOData ? (1<<col) : 0;
		 sw_kbd_optional_scan_bit |= prRead->u1IOData ? (1<<(row+8)) : 0;
#endif
        /* keep the style as 6260/6250--double keypad*/
        /**********************************************************************************
			        col0		      col1		      col2		    col3		            col4		 power key
		row0	bit0~bit2		bit3~bit5		bit6~bit8		bit9~bit11		bit12~bit14		bit15
		row1	bit16~bit18    bit19~bit21    bit22~bit24	bit25~bit27		bit28~bit30		bit31
		row2	bit0~bit2		bit3~bit5		bit6~bit8		bit9~bit11		bit12~bit14		bit15
		row3	bit16~bit18    bit19~bit21	bit22~bit24	bit25~bit27		bit28~bit30		bit31
		row4	bit0~bit2		bit3~bit5		bit6~bit8		bit9~bit11		bit12~bit14		bit15

		 bit in one group    	high		 mid		low       
		                           KEYr240K    KEYr5K   KEYr0K     
		**********************************************************************************/
        temp = (row*KBD_COLUMN+(col*3));/* triple key multiple 3*/
        ((kal_uint32*)key_status_temp)[temp/32] &= prRead->u1IOData ? (kal_uint32)(~(1<<(temp%32))) : 0xFFFFFFFF ;
    }



}
void sw_kbd_cols_scan_t_key(kal_uint32 col)
{
    kal_uint32 i;
    for(i=0; i<ColNum ; i++)
    {
        if(i==col) /*one col  output high*/
        {
            SW_KBD_COL_SCAN(i,KAL_TRUE,KAL_TRUE);
        }
        else    /*other col  hi-z*/
        {
            SW_KBD_COL_SCAN(i,KAL_FALSE,KAL_FALSE);
        }
    }
    ust_busy_wait(SW_KBD_COL_SCAN_TIME);

}
void sw_kbd_rows_detect_t_key(kal_uint32 rows_detect_stage, kal_uint32 col,KEY_STATUS* col_detect_key_status/*input para*/,KEY_STATUS* row_detect_key_status/*ouput para*/)
{		
	kal_uint32  row;
    DCL_HANDLE handle;
    DCL_CTRL_DATA_T data;
    GPIO_CTRL_READ_T   *prRead;
    kal_uint32 temp =0;
    prRead = &(data.rRead);
    for(row = 0; row < RowNum; row++)
    {
#ifdef SW_KBD_OPTIONAL_SCAN
		if((sw_kbd_optional_scan_bit&(1<<(row+8)))==0)
		 	continue ;
#endif
		if(sw_kbd_row[row]== 0xff)
		   continue;
        handle = DclGPIO_Open(DCL_GPIO, sw_kbd_row[row]);
        DclGPIO_Control(handle, GPIO_CMD_SET_DIR_IN, NULL);
        DclGPIO_Control(handle, GPIO_CMD_READ, &data);
        /*keep the style as 6260/6250--double keypad*/ 
        temp = (row*KBD_COLUMN+(col*3)); /* triple key multiple 3*/
        
        if(0==(((kal_uint32*)col_detect_key_status)[temp/32]&(1<<(temp%32)))) /*key press in one group*/ 
        {
		    if(rows_detect_stage == ROWS_DETECT_STAGE1)
            {
				if(prRead->u1IOData)
				{
					// row_detect_key_status->reg1 &= 0xFFFFFFFF/*KEYr5K or KEYr0 press */
	                sw_kbd_optional_scan_bit |= prRead->u1IOData ? (1<<(col+16)) : 0;
			        sw_kbd_optional_scan_bit |= prRead->u1IOData ? (1<<(row+24)) : 0;
				}
				else
				{
				 	((kal_uint32*)row_detect_key_status)[temp/32] &= (kal_uint32)(~(1<<(temp%32+2)));/*KEYr240K press*/ 
				}
       			
	        }
	        else if(rows_detect_stage == ROWS_DETECT_STAGE2)
	        {	
				if(prRead->u1IOData)
				{
					((kal_uint32 *)row_detect_key_status)[temp/32] &= (kal_uint32)(~(1<<temp%32));/*KEYr0 press */
				}
				else
				{
					((kal_uint32 *)row_detect_key_status)[temp/32] &= (kal_uint32)(~(1<<(temp%32+1)));/*KEYr5K*/
				}

	        }
        }
       
    }
        
}

void sw_kbd_get_key_status_t(KEY_STATUS* key_status)
{
	kal_uint32 row, col,i;
    KEY_STATUS col_detect_key_status;
    kal_uint32 sw_kbd_get_status_consuming_time =0;
//    extern kal_uint16 L1_ASSERT_BYPASS;
//    kal_uint16 L1_ASSERT_BYPASS_saved;
//    kal_uint32 savedMask;
    
    col_detect_key_status.reg1=  0xffffffff;
    col_detect_key_status.reg2=  0xffffffff;
    col_detect_key_status.reg3 = 0xffffffff;
#ifndef __UBL__  
    SLA_CustomLogging("SWK",1);
    sw_kbd_get_status_consuming_time = ust_get_current_time();
#endif
//    L1_ASSERT_BYPASS_saved = L1_ASSERT_BYPASS;
//    L1_ASSERT_BYPASS  = 3;
//	 savedMask = SaveAndSetIRQMask();

   
 /****************************************************/
 /*row scan ,col detect stage*/
    /* col pd 1.2M*/
    SW_KBD_DISABLE_PUPD();
    SW_KBD_COL_PD();
    for(i=0; i<RowNum ; i++)
    {
        SW_KBD_ROW_SCAN(i,KAL_FALSE,KAL_FALSE); /*all row  h-zi*/
    }
    /* row scan ,col detect stage*/
    for(row =0 ; row< RowNum; row++)
    { 
		if(sw_kbd_row[row] == 0xff)
			continue;
        sw_kbd_rows_scan_t_key(row); /*row scan*/
        sw_kbd_cols_detect_t_key(row,&col_detect_key_status);/*col detect*/
        for(i=0; i<RowNum ; i++)   /*all rows output low to  release voltage in keys*/
        {
            SW_KBD_ROW_SCAN(i,KAL_TRUE,KAL_FALSE);
        }
        ust_busy_wait(SW_KBD_ROW_INTERVAL_TIME);
    }
    for(i=0; i<RowNum ; i++)
    {
        SW_KBD_ROW_SCAN(i,KAL_FALSE,KAL_FALSE); /*all row  h-zi*/
    }
   ust_busy_wait(30);/* 1T(32K)*/
/******************************************************************/   
/*col scan ,row detect stage1*/
/******************************************************************/ 
   if(0 ==(sw_kbd_optional_scan_bit&0xFF))
    	goto scan_end;
   /* row pd 36K*/
    SW_KBD_DISABLE_PUPD();
    SW_KBD_ROW_PD_36K();
    for(col =0 ; col< ColNum; col++)
    {
    	if(sw_kbd_col[col] == 0xff)
			continue;
#ifdef SW_KBD_OPTIONAL_SCAN
		 if((sw_kbd_optional_scan_bit&(1<<col))==0)
		 	continue ;
#endif
        sw_kbd_cols_scan_t_key(col); /*col scan*/
		sw_kbd_rows_detect_t_key(ROWS_DETECT_STAGE1,col,&col_detect_key_status,key_status);/*row detect stage1*/
        for(i=0; i<ColNum ; i++)/*all cols output low to  release voltage in keys*/
        {
            SW_KBD_COL_SCAN(i,KAL_TRUE,KAL_FALSE);
        }
        ust_busy_wait(SW_KBD_COL_INTERVAL_TIME); 
    }

    /*if all keys are  KEYr240k, need not col scan row detect stage2*/
    sw_kbd_optional_scan_bit = sw_kbd_optional_scan_bit>>16;
	if(0 ==(sw_kbd_optional_scan_bit&0xFF))
    	goto scan_end;
/******************************************************************/    
/*col scan ,row detect stage2*/
/******************************************************************/ 
   /* row pd 1K*/
    SW_KBD_DISABLE_PUPD();
    SW_KBD_ROW_PD_1K();   
    for(col =0 ; col< ColNum; col++)
    {
    	if(sw_kbd_col[col] == 0xff)
    		continue;
#ifdef SW_KBD_OPTIONAL_SCAN
		 if((sw_kbd_optional_scan_bit&(1<<col))==0)
		 	continue ;
#endif
        sw_kbd_cols_scan_t_key(col); /*col scan*/
		sw_kbd_rows_detect_t_key(ROWS_DETECT_STAGE2,col,&col_detect_key_status,key_status);/*row detect stage2*/
        for(i=0; i<ColNum ; i++)/*all cols output low to  release voltage in keys*/
        {
            SW_KBD_COL_SCAN(i,KAL_TRUE,KAL_FALSE);
        }
        ust_busy_wait(SW_KBD_COL_INTERVAL_TIME); 
    }

scan_end:
    for(i=0; i<ColNum ; i++)
    {
        SW_KBD_COL_SCAN(i,KAL_FALSE,KAL_FALSE);  /*all col h-zi*/
    }
/****************************************************/
//   ust_busy_wait(30);/* 1T(32K)*/

/*keypad sw  idle stage waiting for key press*/
    SW_KBD_DISABLE_PUPD();
    sw_kbd_idle_stage();
#ifndef __UBL__
	if (kal_query_systemInit() == KAL_FALSE)
		{
    drv_trace1(TRACE_GROUP_8, KBD_SW_KBD_T_GET_STATUS_TIME_CONSUMING,  (ust_get_current_time() - sw_kbd_get_status_consuming_time));
    SLA_CustomLogging("SWK",0);
		}
#endif
	
//	RestoreIRQMask(savedMask);
//	L1_ASSERT_BYPASS = L1_ASSERT_BYPASS_saved;
    
}

/*double keypad*/ /*chips From 50*/
#elif defined(__COLUMN_EXTEND_KEYPAD__)
/*50,60 COL PU 200K,61 COL PU1.2M*/
void SW_KBD_COL_PU(void)
{
	kal_uint32 temp; 
	for(temp = 0; temp<ColNum ;temp++)
		sw_kbd_gpio_pupd(sw_kbd_col[temp],1,0,1);
}
/*50,60 COL PD 200K,61 COL PD1.2M*/
void SW_KBD_COL_PD(void)
{	
	kal_uint32 temp; 
    for(temp = 0; temp<ColNum ;temp++)
        sw_kbd_gpio_pupd(sw_kbd_col[temp],0,0,1);
}
/*50,60 ROW PD 2K,61 COL PD1k*/
void SW_KBD_ROW_PD(void)
{
	kal_uint32 temp; 
    for(temp = 0; temp<RowNum;temp++)
        sw_kbd_gpio_pupd(sw_kbd_row[temp],0,0,1);
}
/*50,60 COL PD 200K,61 COL PD1.2M*/
void SW_KBD_DISABLE_PUPD(void)
{	
	kal_uint32 temp; 
    for(temp = 0; temp<RowNum;temp++)
        sw_kbd_gpio_pupd(sw_kbd_row[temp],0,0,0);
    for(temp = 0; temp<ColNum;temp++)
        sw_kbd_gpio_pupd(sw_kbd_col[temp],0,0,0);
}

void sw_kbd_rows_scan_d_key(kal_uint32 row)

{
    kal_uint32 i;

    for(i=0; i<RowNum ; i++)
    {
        if(i==row) /*  one row output high*/
        {
            SW_KBD_ROW_SCAN(i,KAL_TRUE,KAL_TRUE);
        }
        else    /*other row hi-z*/
        {
            SW_KBD_ROW_SCAN(i,KAL_FALSE,KAL_FALSE);
        }


    }
    ust_busy_wait(SW_KBD_ROW_SCAN_TIME);

}



void sw_kbd_cols_detect_d_key(kal_uint32 row, KEY_STATUS*  key_status_temp)
{
    kal_uint32 temp;
    kal_uint32  col;
    DCL_HANDLE handle;
    DCL_CTRL_DATA_T data;
    GPIO_CTRL_READ_T   *prRead;
    prRead = &(data.rRead);
    for(col = 0; col < ColNum; col++)
    {
		if(sw_kbd_col[col] == 0xff)
			continue;		
        handle = DclGPIO_Open(DCL_GPIO, sw_kbd_col[col]);
        DclGPIO_Control(handle, GPIO_CMD_SET_DIR_IN, NULL);
        DclGPIO_Control(handle, GPIO_CMD_READ, &data);
#ifdef SW_KBD_OPTIONAL_SCAN
		 sw_kbd_optional_scan_bit |= prRead->u1IOData ? (1<<col) : 0;
		 sw_kbd_optional_scan_bit |= prRead->u1IOData ? (1<<(row+8)) : 0;

#endif
        /* keep the style as 6260/6250--double keypad*/
        temp = (row*KBD_COLUMN+(col<<1));
        //need slim
        if(temp<32)
        {
            key_status_temp->reg1 &= prRead->u1IOData ? (kal_uint32)(~(1<<temp)) : 0xFFFFFFFF ;

        }
        else if(temp<64)
        {
            key_status_temp->reg2 &= prRead->u1IOData ? (kal_uint32)(~(1<<(temp-32))): 0xFFFFFFFF ;

        }
        else if(temp<96)
        {
            key_status_temp->reg3 &= prRead->u1IOData ? (kal_uint32)(~(1<<(temp-64))): 0xFFFFFFFF ;
        }
    }



}



void sw_kbd_cols_scan_d_key(kal_uint32 col)
{
    kal_uint32 i;
    for(i=0; i<ColNum ; i++)
    {
        if(i==col) /*  one col  output high*/
        {
            SW_KBD_COL_SCAN(i,KAL_TRUE,KAL_TRUE);
        }
        else    /*other col  hi-z*/
        {
            SW_KBD_COL_SCAN(i,KAL_FALSE,KAL_FALSE);
        }


    }
    ust_busy_wait(SW_KBD_COL_SCAN_TIME);

}
void sw_kbd_rows_detect_d_key(kal_uint32 col,KEY_STATUS* col_detect_key_status/*input para*/,KEY_STATUS* row_detect_key_status/*ouput para*/)
{
    kal_uint32  row;
    DCL_HANDLE handle;
    DCL_CTRL_DATA_T data;
    GPIO_CTRL_READ_T   *prRead;
    kal_uint32 temp =0;
    prRead = &(data.rRead);
    for(row = 0; row < RowNum; row++)
    {
#ifdef SW_KBD_OPTIONAL_SCAN
		 if((sw_kbd_optional_scan_bit&(1<<(row+8)))==0)
		 	continue ;
#endif
		if(sw_kbd_row[row]== 0xff)
		   continue;
        handle = DclGPIO_Open(DCL_GPIO, sw_kbd_row[row]);
        DclGPIO_Control(handle, GPIO_CMD_SET_DIR_IN, NULL);
        DclGPIO_Control(handle, GPIO_CMD_READ, &data);
        /* keep the style as 6260/6250--double keypad*/
        temp = (row*KBD_COLUMN+(col<<1));
        /*need slim*/
        if(temp<32)
        {
            if(0==((col_detect_key_status->reg1)&(1<<temp))) /* key press in one group*/
                row_detect_key_status->reg1 &= prRead->u1IOData ? (kal_uint32)(~(1<<temp)) : (kal_uint32)(~(1<<(temp+1))) ;

        }
        else if(temp<64)
        {
            if(0 ==((col_detect_key_status->reg2)&(1<<(temp-32)))) /* key press in one group*/
                row_detect_key_status->reg2 &= prRead->u1IOData ? (kal_uint32)(~(1<<(temp-32))): (kal_uint32)(~(1<<(temp-32+1))) ;
        }
        else if(temp<96)
        {
            if(0 ==((col_detect_key_status->reg3)&(1<<(temp-64)))) /* key press in one group*/
                row_detect_key_status->reg3 &= prRead->u1IOData ? (kal_uint32)(~(1<<(temp-64))): (kal_uint32)(~(1<<(temp-64+1))) ;
        }
    }
}
void sw_kbd_get_key_status_d(KEY_STATUS* key_status)
{
    kal_uint32 row, col,i;
    DCL_CTRL_DATA_T data;
    GPIO_CTRL_READ_T   *prRead;
    kal_uint32 temp =0;
    DCL_HANDLE handle;
    KEY_STATUS col_detect_key_status;
    kal_uint32 sw_kbd_get_status_consuming_time =0;
    col_detect_key_status.reg1 =  0xffffffff;
    col_detect_key_status.reg2 =  0xffffffff;
    col_detect_key_status.reg3 =  0xffffffff;
    prRead = &(data.rRead);
#ifndef __UBL__    
    SLA_CustomLogging("SWK",1);
    sw_kbd_get_status_consuming_time = ust_get_current_time();
#endif
    /* col pd 200k*/
    SW_KBD_DISABLE_PUPD();
    SW_KBD_COL_PD();
    for(i=0; i<RowNum ; i++)
    {
        SW_KBD_ROW_SCAN(i,KAL_FALSE,KAL_FALSE); /*all row  h-zi*/
    }
    /* row scan ,col detect stage*/
    for(row =0 ; row< RowNum; row++)
    {
		if(sw_kbd_row[row] == 0xff)
			continue;
        sw_kbd_rows_scan_d_key(row); /*row scan*/
        sw_kbd_cols_detect_d_key(row,&col_detect_key_status);/*col detect*/
        for(i=0; i<RowNum ; i++)   /*all rows output low to  release voltage in keys*/
        {
            SW_KBD_ROW_SCAN(i,KAL_TRUE,KAL_FALSE);
        }
        ust_busy_wait(SW_KBD_ROW_INTERVAL_TIME);
    }

    for(i=0; i<RowNum ; i++)
    {
        SW_KBD_ROW_SCAN(i,KAL_FALSE,KAL_FALSE); /*all row  h-zi*/
    }
   ust_busy_wait(30);/* 1T(32K)*/
 
    /* row pd 2k*/
    SW_KBD_DISABLE_PUPD();
    SW_KBD_ROW_PD();
    /* col scan ,row detect stage*/
    for(col =0 ; col< ColNum; col++)
    {
        if(sw_kbd_col[col] == 0xff)
			continue;
#ifdef SW_KBD_OPTIONAL_SCAN
		 if((sw_kbd_optional_scan_bit&(1<<col))==0)
		 	continue ;
#endif
        sw_kbd_cols_scan_d_key(col); /*col scan*/
        sw_kbd_rows_detect_d_key(col,&col_detect_key_status,key_status);/*row detect*/

        for(i=0; i<ColNum ; i++)/*all cols output low to  release voltage in keys*/
        {
            SW_KBD_COL_SCAN(i,KAL_TRUE,KAL_FALSE);
        }
        ust_busy_wait(SW_KBD_COL_INTERVAL_TIME); 
    }

    for(i=0; i<ColNum ; i++)
    {
        SW_KBD_COL_SCAN(i,KAL_FALSE,KAL_FALSE);  /*all col h-zi*/
    }
//   ust_busy_wait(30);/* 1T(32K)*/

/*keypad sw  idle stage waiting for key press*/
    SW_KBD_DISABLE_PUPD();
    sw_kbd_idle_stage();
#ifndef __UBL__
	if (kal_query_systemInit() == KAL_FALSE)
	{
    drv_trace1(TRACE_GROUP_8, KBD_SW_KBD_D_GET_STATUS_TIME_CONSUMING,  (ust_get_current_time() - sw_kbd_get_status_consuming_time));
    SLA_CustomLogging("SWK",0);
	}
#endif
}

#else  
/*signle keypad*/ /*all chips*/
/*50,60 COL PU 200K,61 COL PU1.2M,others 75k*/
void SW_KBD_COL_PU(void)
{
	kal_uint32 temp; 
	for(temp = 0; temp<ColNum ;temp++)
		sw_kbd_gpio_pupd(sw_kbd_col[temp],1,0,1);
}

void SW_KBD_ROW_PU(kal_uint32 row_number)
{
        sw_kbd_gpio_pupd(sw_kbd_row[row_number],1,0,1);
}


void sw_kbd_rows_scan_s_key(kal_uint32 row)
{
    kal_uint32 i;
    for(i=0; i<RowNum ; i++)
    {
        if(i==row) /*  one row output low*/
        {
            SW_KBD_ROW_SCAN(i,KAL_TRUE,KAL_FALSE);
        }
        else    /*other  row  input and pull high*/
        {
		   SW_KBD_ROW_SCAN(i,KAL_FALSE,KAL_FALSE);// inupt and h-zi
		   SW_KBD_ROW_PU(i);//pull high
        }

    }
    ust_busy_wait(SW_KBD_ROW_SCAN_TIME);

}
void sw_kbd_get_key_status_s(KEY_STATUS* key_status)
{
    kal_uint32 row, col,i;
    DCL_CTRL_DATA_T data;
    GPIO_CTRL_READ_T   *prRead;
    kal_uint32 temp =0;
    DCL_HANDLE handle;
    kal_uint32 sw_kbd_get_status_consuming_time =0;
    prRead = &(data.rRead);
    #ifndef __UBL__
     sw_kbd_get_status_consuming_time = ust_get_current_time();
    #endif
    /*init row*/
    for(i=0; i<RowNum ; i++)
    {
        SW_KBD_ROW_SCAN(i,KAL_TRUE,KAL_FALSE);  /*all row ouput low*/ 
    }
    /*init col*/
    SW_KBD_COL_PU();
    
    for(row =0 ; row< RowNum; row++)
    {
        sw_kbd_rows_scan_s_key(row); /*row scan*/

        for(col = 0; col < ColNum; col++)
        {
			if(sw_kbd_col[col] == 0xff)
			continue;
            handle = DclGPIO_Open(DCL_GPIO, sw_kbd_col[col]);
            DclGPIO_Control(handle, GPIO_CMD_SET_DIR_IN, NULL);
            DclGPIO_Control(handle, GPIO_CMD_READ, &data);
            /* keep the style as 6260/6250*/
            temp = row*KBD_COLUMN+col;
            if(temp<32)
                (*key_status).reg1 &= prRead->u1IOData ? 0xFFFFFFFF : (kal_uint32)(~(1<<temp));
            else if(temp<64)
                (*key_status).reg2 &= prRead->u1IOData ? 0xFFFFFFFF : (kal_uint32)(~(1<<(temp-32)));
            else if(temp<96)
                (*key_status).reg3 &= prRead->u1IOData ? 0xFFFFFFFF : (kal_uint32)(~(1<<(temp-64)));

        }

        for(i=0; i<RowNum ; i++)
        {
            SW_KBD_ROW_SCAN(i,KAL_TRUE,KAL_TRUE);  /* all row output high*/
        }

        ust_busy_wait(SW_KBD_ROW_INTERVAL_TIME);

    }

    sw_kbd_idle_stage();
    #ifndef __UBL__
	if (kal_query_systemInit() == KAL_FALSE)
	{
    drv_trace1(TRACE_GROUP_8, KBD_SW_KBD_S_GET_STATUS_TIME_CONSUMING,  (ust_get_current_time() - sw_kbd_get_status_consuming_time));
	}
    #endif

}
#endif

#ifndef __UBL__
void sw_kbd_set_keypad_mode(void)
{

    DCL_HANDLE handle;
    kal_uint32 i;
    for(i =0; i<ColNum; i++)
    {
    	if(sw_kbd_col[i] == 0xff)
			continue;
        handle = DclGPIO_Open(DCL_GPIO, sw_kbd_col[i]);
        DclGPIO_Control(handle, GPIO_CMD_SET_MODE_1, NULL);
    }
}
#endif

/* wait for eint*/
void sw_kbd_idle_stage(void)
{
	 kal_uint32 i =0;
	/* reset col scan bit to 0*/
#ifdef SW_KBD_OPTIONAL_SCAN
	sw_kbd_optional_scan_bit =0x0;
#endif

#ifndef __UBL__
    /*init row*/
    for(i=0; i<RowNum ; i++)
    {
        SW_KBD_ROW_SCAN(i,KAL_TRUE,KAL_FALSE);  /*all row ouput low*/ 
    }
    /*init col*/
    SW_KBD_COL_PU();
    /*disable keypad hw module*/ 
 	DRV_KBD_WriteReg(KEYPAD_ENBALE_REG, 0);
    sw_kbd_set_keypad_mode();
#endif
}

#ifndef __UBL__
static kal_bool polarity = KAL_FALSE;

#ifdef SW_KBD_DEBUG
static kal_bool sw_kbd_performace_test = KAL_FALSE;
kal_uint8 sw_key_press = 17;
#endif

void SW_KBD_EINT_HISR(void)
{

  KEY_STATUS sw_kbd_temp_key_status;
 /*For get key status API*/ 
 
#ifdef SW_KBD_DEBUG
	DCL_HANDLE sw_kbdhandle;
	DCL_CTRL_DATA_T data;
	HKBD_CTRL_KEY_STA_T* pCtrlKeySta;
	sw_kbdhandle = DclHKBD_Open(DCL_KBD, MOD_DRVKBD);
	pCtrlKeySta = &(data.rKBDCtrlKeySta);
	pCtrlKeySta->key = sw_key_press;	
	DclHKBD_Control(sw_kbdhandle, HKBD_CMD_GET_KEY_STATUS, (DCL_CTRL_DATA_T*)&data);
	if( pCtrlKeySta->sta)
	{
		drv_trace1(TRACE_GROUP_8, KBD_KEY_QUERY_PRESSED, sw_key_press);
	}

#endif
 /*test for performace */
#ifdef SW_KBD_DEBUG
	if(sw_kbd_performace_test)
	{
		sw_kbd_performace_test = KAL_FALSE;
		sw_kbd_set_timer(Sw_kbd_performace_test_timer_handler,Sw_kbd_performace_test_timer_cb,2000);
	}
#endif
#ifdef SW_KBD_DEBUG	
	drv_trace1(TRACE_GROUP_8, KBD_SW_KBD_EINTHISR_START,  ust_get_current_time());
#endif  
    sw_kbd_temp_key_status.reg1 = 0xFFFFFFFF;
    sw_kbd_temp_key_status.reg2 = 0xFFFFFFFF;
    sw_kbd_temp_key_status.reg3 = 0xFFFFFFFF;
#ifdef SW_KBD_DEBUG
	sw_kbd_eint_hisr_cnt++;
    drv_trace1(TRACE_GROUP_8, KBD_SW_KBD_EINT_CNT,  sw_kbd_eint_hisr_cnt);
#endif
    SLA_CustomLogging("SWK",1);
     polarity = ~polarity;  /*reverse EINT polarity*/ 
    if(polarity) /*key press state*/ 
        EINT_Set_Polarity(SW_KBD_EINT_NO, KAL_TRUE);
    else          /*key release state*/
        EINT_Set_Polarity(SW_KBD_EINT_NO, KAL_FALSE);
//        MTKL1CACHE_CleanAllCacheLines();
//        MTKL1CACHE_InvalidAllCacheLines();

    SW_KBD_GET_KEY_STATUS(&sw_kbd_temp_key_status);
	if(sw_kbd_temp_key_status.reg1 ==0xffffffff &&
		sw_kbd_temp_key_status.reg2 ==0xffffffff &&
		sw_kbd_temp_key_status.reg3 ==0xffffffff)
	{  
	 /*all key release is reliable*/
		DclSGPT_Control(Sw_kbd_polling_timer_handler,SGPT_CMD_STOP,0); /*stop polling timer*/
	    DclSGPT_Control(Sw_kbd_debounce_timer_handler,SGPT_CMD_STOP,0); /*stop debounce timer*/	
		sw_kbd_current_key_status.reg1 = sw_kbd_temp_key_status.reg1;
		sw_kbd_current_key_status.reg2 = sw_kbd_temp_key_status.reg2;
		sw_kbd_current_key_status.reg3 = sw_kbd_temp_key_status.reg3;
		kal_set_eg_events(KBD.event,KBD_STATUS_CHANGE_EVENT,KAL_OR);  /*send msg to task*/
#ifdef SW_KBD_DEBUG
		drv_trace1(TRACE_GROUP_8, KBD_SW_KBD_STOP_POLLING_IN_EINT_HISR,  0);
#endif
		
		
	}
	else  
	{
	/* key press is not reliable,because when 1st key press first and it pass eint hw bebounce, 
			but before eint hisr is active, 2nd key maybe press, so the 2nd is not reliable*/
		if((sw_kbd_temp_key_status.reg1!=sw_kbd_current_key_status.reg1)||
			   (sw_kbd_temp_key_status.reg2!=sw_kbd_current_key_status.reg2)||
			   (sw_kbd_temp_key_status.reg3!=sw_kbd_current_key_status.reg3))
		   {
#ifdef SW_KBD_DEBUG
		   		drv_trace1(TRACE_GROUP_8, KBD_SW_KBD_START_DEBOUNCE_IN_EINT,  1);
#endif

				
			   /*bit debounce*/
			   /*get which bits have change*/
			   sw_kbd_debounce_key_status_mask.reg1 = sw_kbd_current_key_status.reg1 ^ sw_kbd_temp_key_status.reg1;
			   sw_kbd_debounce_key_status_mask.reg2 = sw_kbd_current_key_status.reg2 ^ sw_kbd_temp_key_status.reg2;
			   sw_kbd_debounce_key_status_mask.reg3 = sw_kbd_current_key_status.reg3 ^ sw_kbd_temp_key_status.reg3;
				/*start debouce*/  
			   sw_kbd_debounce_key_status.reg1 = sw_kbd_temp_key_status.reg1;
			   sw_kbd_debounce_key_status.reg2 = sw_kbd_temp_key_status.reg2;
			   sw_kbd_debounce_key_status.reg3 = sw_kbd_temp_key_status.reg3;
			   sw_kbd_set_timer(Sw_kbd_debounce_timer_handler,Sw_kbd_debounce_timer_cb,Sw_kbd_debounce_timer);	/*debounce time*/			   
			   sw_kbd_set_timer(Sw_kbd_polling_timer_handler,Sw_kbd_polling_timer_cb,Sw_kbd_polling_time);	/*polling	 time*/
#ifdef SW_KBD_DEBUG
			   drv_trace1(TRACE_GROUP_8, KBD_SW_KBD_START_POLLING_IN_EINT,	1);
#endif

			   

		
	     }
  
	}
#ifdef SW_KBD_DEBUG
	drv_trace1(TRACE_GROUP_8, KBD_SW_KBD_EINTHISR_END,  ust_get_current_time());
    SLA_CustomLogging("SWK",0);
#endif
}



void sw_kbd_set_timer(kal_uint32 handle, SW_KBD_TIMER_CB cb, kal_uint32 tick)

{
    SGPT_CTRL_START_T start;
    start.pfCallback=(void(*)(void*))cb;
    start.vPara=NULL;

    IRQMask(IRQ_GPT_CODE);
    start.u2Tick=tick;
    DclSGPT_Control(handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
    IRQUnmask(IRQ_GPT_CODE);

}

void Sw_kbd_performace_test_timer_cb(void *parameter)
{
	ASSERT(0);
}

void Sw_kbd_debounce_timer_cb(void *parameter)
{
    KEY_STATUS sw_kbd_temp_key_status;
    sw_kbd_temp_key_status.reg1 = 0xFFFFFFFF;
    sw_kbd_temp_key_status.reg2 = 0xFFFFFFFF;
    sw_kbd_temp_key_status.reg3 = 0xFFFFFFFF;
#ifdef SW_KBD_DEBUG
    SLA_CustomLogging("SWK",1);
    drv_trace1(TRACE_GROUP_8, KBD_SW_KBD_DEBOUNCE_START,  ust_get_current_time());
#endif
  	EINT_Mask(SW_KBD_EINT_NO);
 //       MTKL1CACHE_CleanAllCacheLines();
 //       MTKL1CACHE_InvalidAllCacheLines();
    SW_KBD_GET_KEY_STATUS(&sw_kbd_temp_key_status);
	
      /*key debounce  pass*/ 
		if((sw_kbd_debounce_key_status.reg1&sw_kbd_debounce_key_status_mask.reg1) == (sw_kbd_temp_key_status.reg1&sw_kbd_debounce_key_status_mask.reg1)&&
			(sw_kbd_debounce_key_status.reg2&sw_kbd_debounce_key_status_mask.reg2) == (sw_kbd_temp_key_status.reg2&sw_kbd_debounce_key_status_mask.reg2)&&
			(sw_kbd_debounce_key_status.reg3&sw_kbd_debounce_key_status_mask.reg3) == (sw_kbd_temp_key_status.reg3&sw_kbd_debounce_key_status_mask.reg3))

		{
			sw_kbd_current_key_status.reg1 = sw_kbd_debounce_key_status.reg1;
			sw_kbd_current_key_status.reg2 = sw_kbd_debounce_key_status.reg2;
			sw_kbd_current_key_status.reg3 = sw_kbd_debounce_key_status.reg3;
			kal_set_eg_events(KBD.event,KBD_STATUS_CHANGE_EVENT,KAL_OR);  /*send msg to task*/
#ifdef SW_KBD_DEBUG
			sw_kbd_pass_debounce_cnt++;
			drv_trace1(TRACE_GROUP_8, KBD_SW_KBD_PASS_DEBOUNCE,  sw_kbd_pass_debounce_cnt);
#endif

		}
		else
		{
#ifdef SW_KBD_DEBUG
			sw_kbd_not_pass_debounce_times++;
			drv_trace1(TRACE_GROUP_8, KBD_SW_KBD_NOT_PASS_DEBOUNCE,  sw_kbd_not_pass_debounce_times);
#endif
			
		}

  /*restart  debounce*/
		if((sw_kbd_temp_key_status.reg1!=sw_kbd_current_key_status.reg1)||
				   (sw_kbd_temp_key_status.reg2!=sw_kbd_current_key_status.reg2)||
				   (sw_kbd_temp_key_status.reg3!=sw_kbd_current_key_status.reg3))
			{

				/*bit debounce*/
				/*get which bits have changge*/
				sw_kbd_debounce_key_status_mask.reg1 = sw_kbd_current_key_status.reg1 ^ sw_kbd_temp_key_status.reg1;
				sw_kbd_debounce_key_status_mask.reg2 = sw_kbd_current_key_status.reg2 ^ sw_kbd_temp_key_status.reg2;
				sw_kbd_debounce_key_status_mask.reg3 = sw_kbd_current_key_status.reg3 ^ sw_kbd_temp_key_status.reg3;
				/*start debouce*/	
				sw_kbd_debounce_key_status.reg1 = sw_kbd_temp_key_status.reg1;
				sw_kbd_debounce_key_status.reg2 = sw_kbd_temp_key_status.reg2;
				sw_kbd_debounce_key_status.reg3 = sw_kbd_temp_key_status.reg3;
				sw_kbd_set_timer(Sw_kbd_debounce_timer_handler,Sw_kbd_debounce_timer_cb,Sw_kbd_debounce_timer);  /*debounce time*/
				
#ifdef SW_KBD_DEBUG
				drv_trace1(TRACE_GROUP_8, KBD_SW_KBD_DEBOUNCE_THEN_DEBOUNCE,  1);
#endif			
			}
	EINT_UnMask(SW_KBD_EINT_NO);
	
#ifdef SW_KBD_DEBUG
    drv_trace1(TRACE_GROUP_8, KBD_SW_KBD_DEBOUNCE_END,  ust_get_current_time());
    SLA_CustomLogging("SWK",0);
#endif
}

void Sw_kbd_polling_timer_cb(void *parameter)
{
    KEY_STATUS sw_kbd_temp_key_status;
    sw_kbd_temp_key_status.reg1 = 0xFFFFFFFF;
    sw_kbd_temp_key_status.reg2 = 0xFFFFFFFF;
    sw_kbd_temp_key_status.reg3 = 0xFFFFFFFF;
#ifdef SW_KBD_DEBUG
    drv_trace1(TRACE_GROUP_8, KBD_SW_KBD_POLLING_START,  ust_get_current_time());
    SLA_CustomLogging("SWK",1);
#endif
	EINT_Mask(SW_KBD_EINT_NO);
        //MTKL1CACHE_CleanAllCacheLines();
        //MTKL1CACHE_InvalidAllCacheLines();
    SW_KBD_GET_KEY_STATUS(&sw_kbd_temp_key_status);
    if((sw_kbd_temp_key_status.reg1!=sw_kbd_current_key_status.reg1)||
        (sw_kbd_temp_key_status.reg2!=sw_kbd_current_key_status.reg2)||
        (sw_kbd_temp_key_status.reg3!=sw_kbd_current_key_status.reg3))
    {
#ifdef SW_KBD_DEBUG
		drv_trace1(TRACE_GROUP_8, KBD_SW_KBD_START_DEBOUNCE_IN_POLLING,  1);
#endif
		/*bit debounce*/
		/*get which bits have change*/
		sw_kbd_debounce_key_status_mask.reg1 = sw_kbd_current_key_status.reg1 ^ sw_kbd_temp_key_status.reg1;
		sw_kbd_debounce_key_status_mask.reg2 = sw_kbd_current_key_status.reg2 ^ sw_kbd_temp_key_status.reg2;
		sw_kbd_debounce_key_status_mask.reg3 = sw_kbd_current_key_status.reg3 ^ sw_kbd_temp_key_status.reg3;
         /*start debounce */ 
        sw_kbd_debounce_key_status.reg1 = sw_kbd_temp_key_status.reg1;
        sw_kbd_debounce_key_status.reg2 = sw_kbd_temp_key_status.reg2;
        sw_kbd_debounce_key_status.reg3 = sw_kbd_temp_key_status.reg3;
        sw_kbd_set_timer(Sw_kbd_debounce_timer_handler,Sw_kbd_debounce_timer_cb,Sw_kbd_debounce_timer);  /*debounce time*/
        
       
    }
    sw_kbd_set_timer(Sw_kbd_polling_timer_handler,Sw_kbd_polling_timer_cb,Sw_kbd_polling_time);   /*polling  time*/
	EINT_UnMask(SW_KBD_EINT_NO);
#ifdef SW_KBD_DEBUG
    drv_trace1(TRACE_GROUP_8, KBD_SW_KBD_POLLING_END,  ust_get_current_time());
    SLA_CustomLogging("SWK",0);
#endif
    
}
#ifdef SW_KBD_DEBUG
    #define GPIO_PORT_9    (9|0x80)
    #define GPIO_PORT_11   (11|0x80)
    #define GPIO_PORT_12   (12|0x80)
    #define GPIO_PORT_13   (13|0x80)  
    #define GPIO_PORT_14   (14|0x80)
    #define GPIO_PORT_15   (15|0x80)
	static kal_bool GPIO_test_v_level =KAL_FALSE;
	kal_uint32 sw_kbd_GPIO_test_timer_handler;
void sw_kbd_GPIO_test_cb(void *parameter)
{
	DCL_HANDLE handle;
    DCL_CTRL_DATA_T data;
    GPIO_CTRL_READ_T   *prRead;
    prRead = &(data.rRead);
    
	SW_KBD_SetGPIO(GPIO_PORT_13, GPIO_CMD_SET_MODE_0,KAL_TRUE,GPIO_test_v_level);
	GPIO_test_v_level = ~GPIO_test_v_level;
	
	ust_busy_wait(30);
	
	handle = DclGPIO_Open(DCL_GPIO, GPIO_PORT_9);
    DclGPIO_Control(handle, GPIO_CMD_SET_DIR_IN, NULL);
    DclGPIO_Control(handle, GPIO_CMD_READ, &data);
    drv_trace1(TRACE_GROUP_8, KBD_SW_KBD_T_GET_STATUS_START,  prRead->u1IOData);
    sw_kbd_set_timer(sw_kbd_GPIO_test_timer_handler,sw_kbd_GPIO_test_cb,5); 
    
	
}
#endif
void sw_kbd_init(void)
{

    EINT_Registration(SW_KBD_EINT_NO,KAL_TRUE,KAL_FALSE,SW_KBD_EINT_HISR, KAL_TRUE);
    EINT_Set_Sensitivity(SW_KBD_EINT_NO, LEVEL_SENSITIVE);
    EINT_Set_Polarity(SW_KBD_EINT_NO, KAL_FALSE);
    EINT_Set_HW_Debounce(SW_KBD_EINT_NO, 5);/*eint debounce 5ms*/
    Sw_kbd_polling_timer_handler=DclSGPT_Open(DCL_GPT_CB,0);
    Sw_kbd_debounce_timer_handler=DclSGPT_Open(DCL_GPT_CB,0);

#ifdef SW_KBD_DEBUG
	 Sw_kbd_performace_test_timer_handler = DclSGPT_Open(DCL_GPT_CB,0);
	 sw_kbd_GPIO_test_timer_handler = DclSGPT_Open(DCL_GPT_CB,0);
     sw_kbd_set_timer(sw_kbd_GPIO_test_timer_handler,sw_kbd_GPIO_test_cb,5); 
#endif       
    /*init  variable*/ 
    sw_kbd_paremeter_init();
    sw_kbd_current_key_status.reg1 = 0xFFFFFFFF;
    sw_kbd_current_key_status.reg2 = 0xFFFFFFFF;
    sw_kbd_current_key_status.reg3 = 0xFFFFFFFF;
    /*init sw keypad gpio*/
    sw_kbd_idle_stage();
    
    #ifdef DRV_KBD_6261_SERIES
 /*set pupd when disable keypad and GPIO in keypad mode,reference confgsys.doc.0x1080 mean col PU 1.2M and row disable PUPD*/
    /*Used SW keypad,in order to uses the AND gate on HW keypad, we will be config the COLs as keypad mode when key idle.But we do not use HW keypad irq,so will disable HW keypad
    But the problem is the pull 1.2M will be unused!!! So we must set 0xa0010240 to config the pull high 1.2M*/
    DRV_WriteReg32(0xa0010240,0x00001080);
   #endif
}
#endif
#endif



