# Define source file lists to SRC_LIST
SRC_LIST = hal\peripheral\src\dcl_pfc.c \
       hal\peripheral\src\dcl_rtc.c \
       hal\peripheral\src\dcl_i2c.c \
       hal\peripheral\src\dcl_i2c_dual.c \
       hal\peripheral\src\dcl_aux.c \
       hal\peripheral\src\auxmain.c \
       hal\peripheral\src\i2c.c \
       hal\peripheral\src\pfc.c \
       hal\peripheral\src\rtc.c \
       hal\peripheral\src\drv_comm.c \
       hal\peripheral\src\drv_hisr.c \
       hal\peripheral\src\lpwr.c \
       hal\peripheral\src\dcl_gpio.c \
       hal\peripheral\src\dcl_wdt.c \
       hal\peripheral\src\dcl_gpt.c \
       hal\peripheral\src\dcl_gpt_hw.c \
       hal\peripheral\src\dcl_pwm.c \
       hal\peripheral\src\dcl_adc.c \
       hal\peripheral\src\adc.c \
       hal\peripheral\src\gpio.c \
       hal\peripheral\src\wdt.c \
       hal\peripheral\src\pwm.c \
       hal\peripheral\src\rwg.c \
       hal\peripheral\src\alerter.c \
       hal\peripheral\src\dcl_pmu.c \
       hal\peripheral\src\dcl_pmu_common.c \
       hal\peripheral\src\dcl_pw.c \
       hal\peripheral\src\kbdmain.c\
       hal\peripheral\src\kbd_jogball.c\
       hal\peripheral\src\DclS_kbd.c\
       hal\peripheral\src\DclH_kbd.c\
       hal\peripheral\src\dbgprint.c\
       hal\peripheral\src\Dcl_SeriPortDrv.c\
       hal\peripheral\src\Dcl_extuartdrv.c\
       hal\peripheral\src\uart.c\
       hal\peripheral\src\ext_uart.c\
       hal\peripheral\src\uart_vfifo.c\
       hal\peripheral\src\uart_handler.c\
       hal\peripheral\src\ext_uart_handler.c\
       hal\peripheral\src\dcl_pxs.c \
       hal\peripheral\src\i2c_dual.c \
       hal\peripheral\src\dcl_irda.c \
       hal\peripheral\src\motion_sensor.c \
       hal\peripheral\src\spi.c \
       hal\peripheral\src\spi_hal.c \
       hal\peripheral\src\hif_v1.c \
       hal\peripheral\src\hif_v2.c \
       hal\peripheral\src\hif_legacy.c \
       hal\peripheral\src\touch_panel_main.c \
       hal\peripheral\src\ts_drv.c \
       hal\peripheral\src\touch_panel.c \
       hal\peripheral\src\dcl_hts.c \
       hal\peripheral\src\dcl_sts.c \
       hal\peripheral\src\f32k_clk.c \
       hal\peripheral\src\dcl_f32k_clk.c \
       hal\peripheral\src\nli_arb.c \
       hal\peripheral\src\gpt_udvt_test.c \
       hal\peripheral\src\i2c_udvt_test.c \
       hal\peripheral\src\sw_keypad.c \
       hal\peripheral\src\dcl_common.c \
       hal\peripheral\src\dcl_eint.c \
      hal\peripheral\src\spi_slave.c \
      hal\peripheral\src\dcl_spi_slave.c 


OLD_BMT_ARCHITECTURE_PLATFORM = MT6252 MT6253 MT6276 MT6255 MT6256 MT6251 MT6235 MT6235B MT6236 MT6921 MT6922 MT6326 MT6268 MT6573 MT6575
#OLD_BMT_ARCHITECTURE_PLATFORM = MT6252 MT6253 MT6276 MT6251 MT6235 MT6235B MT6236 MT6921 MT6922 MT6326 MT6268 MT6573 MT6575
ifneq ($(filter $(strip $(PLATFORM)) ,$(OLD_BMT_ARCHITECTURE_PLATFORM)),)
    SRC_LIST += hal\peripheral\src\adcmeasure_old.c \
                hal\peripheral\src\adcsche_old.c \
                hal\peripheral\src\dcl_chr_det_old.c 
                
else
   SRC_LIST += hal\peripheral\src\adcmeasure.c \
               hal\peripheral\src\adcsche.c \
               hal\peripheral\src\adc_msg_handle.c \
               hal\peripheral\src\dcl_chr_det.c
endif
		    

# accdet
ifneq ($(filter __ACCDET_SUPPORT__, $(strip $(MODULE_DEFS))),)
  ifeq ($(filter __L1_STANDALONE__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += hal\peripheral\src\accdet.c
  endif
endif
ifneq ($(filter __ACCDET_HYBRID_SOLUTION_SUPPORT__, $(strip $(MODULE_DEFS))),)
  ifeq ($(filter __L1_STANDALONE__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += hal\peripheral\src\accdet.c
  endif
endif


# PMU
ifeq ($(strip $(PMIC)),MT6235PMU)
   SRC_LIST += hal\peripheral\src\dcl_pmu6235.c
endif
ifneq ($(filter MT6236PMU MT6921PMU, $(strip $(PMIC))),)
   SRC_LIST += hal\peripheral\src\dcl_pmu6236.c
   SRC_LIST += hal\peripheral\src\pmic_MT6236PMU_drv.c
endif
ifeq ($(strip $(PMIC)),MT6253PMU)
   SRC_LIST += hal\peripheral\src\dcl_pmu6253.c
endif
ifeq ($(strip $(PMIC)),MT6326_CCCI)
   SRC_LIST += hal\peripheral\src\dcl_pmic6326_ccci.c
endif
ifeq ($(strip $(PMIC)),MT6326)
   SRC_LIST += hal\peripheral\src\dcl_pmic6326.c
endif
ifeq ($(strip $(PMIC)),MT6250PMU)
	SRC_LIST += hal\peripheral\src\dcl_pmu6250.c \
				hal\peripheral\src\dcl_pmu6250_init.c 	
endif
ifeq ($(strip $(PMIC)),MT6251PMU)
   SRC_LIST += hal\peripheral\src\dcl_pmu6251.c
   SRC_LIST += hal\peripheral\src\pmic_MT6251PMU_drv.c
endif
ifeq ($(strip $(PMIC)),MT6252PMU)
   SRC_LIST += hal\peripheral\src\dcl_pmu6252.c
endif
ifeq ($(strip $(PMIC)),MT6253ELPMU)
   SRC_LIST += hal\peripheral\src\dcl_pmu6252.c
endif
ifeq ($(strip $(PMIC)),MT6256PMU)
   SRC_LIST += hal\peripheral\src\dcl_pmu6256.c \
               hal\peripheral\src\dcl_pmu6256_init.c
endif
ifeq ($(strip $(PMIC)),MT6255PMU)
   SRC_LIST += hal\peripheral\src\dcl_pmu6255.c \
               hal\peripheral\src\dcl_pmu6255_init.c
endif
ifeq ($(strip $(PMIC)),MT6260PMU)
	SRC_LIST += hal\peripheral\src\dcl_pmu6260.c \
				hal\peripheral\src\dcl_pmu6260_init.c 	
endif
ifeq ($(strip $(PMIC)),MT6261PMU)
	SRC_LIST += hal\peripheral\src\dcl_pmu6261.c \
				hal\peripheral\src\dcl_pmu6261_init.c 	
endif
ifeq ($(strip $(PMIC)),MT6276PMU)
   SRC_LIST += hal\peripheral\src\dcl_pmu6276.c
   SRC_LIST += hal\peripheral\src\pmic_MT6276PMU_drv.c
endif
ifeq ($(strip $(PMIC)),MT6573PMU)
   SRC_LIST += hal\peripheral\src\dcl_pmu6573.c
endif


ifneq ($(filter __DMA_UART_VIRTUAL_FIFO__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\peripheral\src\uart_vfifo.c
endif

ifneq ($(filter __MAUI_BASIC__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += hal\peripheral\src\uart_test.c
  SRC_LIST += hal\peripheral\src\spi_test.c
endif

# Define include path lists to INC_DIR
INC_DIR = interface\hal \
          hal\peripheral\inc \
          hal\system\dcmgr\inc \
          interface\hal\connectivity\usb_driver \
          hal\connectivity\usb_driver\inc \
          interface\hwdrv \
          drv\include \
          hal\bluetooth\btif\include \
          interface\hal\audio \
          interface\hal\video\
          hal\display\common\include \
          custom\drv\ast \
          interface\hal\L1 \
            track\at\at_inc \
          track\drv\drv_inc \
          ELL\ell-common \
	  gps\mnl\include \
	  track\fun\fun_inc \
	  track\os\os_inc\
          custom\codegen\$(strip $(BOARD_VER)) \
          hal\system\AP_BtSS\inc \
          hal\system\cache\inc \
          hal\system\csci\inc
        
# Define the specified compile options to COMP_DEFS
COMP_DEFS = __DRV_COMM_INIT_DEINIT__


