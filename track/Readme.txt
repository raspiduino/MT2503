
一、模块

Track根目录下分以下模块

1、os
    硬件系统正常工作的必须接口 (task+timer+log)

2、drv 
    硬件驱动层

/***** （os+drv）保证可测试PCBA   *****/
3、at
    相关的适配层 （at+sms+call+nvram+factory）
    封装MTK底层相关接口，便于上层扩展功能

4、cmd


5、soc 
    与后台服务器可靠通信

6、fun
    与平台无关或低耦合的通用功能接口

7、cust
    通用功能业务逻辑层

8、res
    字符、铃声等资源文件

9、project
   划分不同项目，独立维护

二、命名

1、每个模块文件夹下再分（模块_inc）和（模块_src）两个子文件夹

2、模块对外函数全部集中，文件命名为 （track_模块）；函数命名（track_模块_XX）表示全局函数，公用的特殊函数如定时器等可省去（_模块）

3、模块内部函数，文件名按功能划分为 (track_模块_功能_XX)；函数则命名为（track_XX_XX），前缀track_不带模块名，与全局函数区分，加static限制

4、全局宏为 __GPS_TRACK__，除非必须如RF参数等与硬件接口相关的，以按项目区分，其它一律以功能宏划分


三、功能划分说明

1、os

track_main.c 		//自定义函数入口
track_timer.c		//定时器，包括精确定时器

2、drv
track_drv.c		//驱动对外接口，包括track_drv.h可对外引用，其他不得使用
track_drv_pmu.c	//与充电电池管理，以及休眠相关
track_drv_eint_gpio.c	//与中断配置，GOIO处理相关
track_drv_gps_decode.c	//独立的GPS解码
track_drv_gps_drive.c	//GPS驱动，主要是控制开关以及与其他task的交互
track_drv_gps_epo.c	//EPO功能（自动测试中注入EPO星历）
track_drv_key.c		//自定义键盘处理
track_drv_lbs_data.c	//LBS多基站信息
track_drv_led.c		//LED控制
track_drv_sensor.c		//sensor驱动的公共部分
track_drv_system_param.c	//系统硬件参数截取
track_drv_test.c		//驱动测试指令，用于PCBA验证
track_drv_watch_dog.c	//152喂狗信号
track_drv_sensor.c		//sensor驱动

3、at


4、cmd


5、soc 


6、fun


7、cust


8、res


--------------------------------
程俊

19:32 2013/4/12


