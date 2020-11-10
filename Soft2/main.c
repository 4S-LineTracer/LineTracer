/****************************************************************************************************************/
/*	FILE        :main.c																							*/
/*	DATE        :Tue, Jan 17, 2012																				*/
/*	DESCRIPTION :AGV Main Program																				*/
/*	CPU TYPE    :H8/3052F																						*/
/****************************************************************************************************************/
#include "stdio.h"
#define MAIN

#include "machine.h"
#include "reg3052.h"
#include "agvdef.h"
#include "agvvars.h"
#include "def_monitor_printf.h"

#include "initialize.h"

/****************************************************************************************************************/
/*	AGVデバイス初期化モジュール agv_init																		*/
/****************************************************************************************************************/
void agv_init(void){
    initialize();
}

/****************************************************************************************************************/
/*	main関数																									*/
/****************************************************************************************************************/
int main(void){
    unsigned int i = 0;
    while (1){
        switch (AGV_STATE){

        case AGV_BOOT:
            bios_led_output(0x01);
            break;
        case AGV_READY:
            bios_led_output(0x02);
            break;
        case AGV_RUN_WAIT:
            bios_led_output(0x04);
            break;
        case AGV_STOP_WAIT:
            bios_led_output(0x08);
            break;
        case AGV_RUN:
            bios_led_output(0x10);
            break;
        case AGV_BOOT_ALM:
            bios_led_output(0x20);
            break;
        case AGV_READY_ALM:
            bios_led_output(0x40);
            break;
        case AGV_RUN_ALM:
            bios_led_output(0x80);
            break;
        }
        sleep();
    }
    return 0;
}

/****************************************************************************************************************/
/*	beepモジュール beep																							*/
/****************************************************************************************************************/
void beep(void){
}
