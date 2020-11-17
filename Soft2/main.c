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

void beep(void);

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
	unsigned char LED_DATA = 0;

    agv_init();
		
    while (1){
		LED_DATA = 0x00;
		
		if(AGV_STATE == AGV_BOOT){
			LED_DATA |= 0x01;
		}
		if(AGV_STATE == AGV_READY){
			LED_DATA |= 0x02;
		}
		if(AGV_STATE ==AGV_RUN){
			LED_DATA |= 0x04;
		}
		if(AGV_STATE ==AGV_SEARCH){
			LED_DATA |= 0x08;
		}
		if(MOTOR_STATE == MOTOR_ACCEL){
			LED_DATA |= 0x10;
		}
		if(MOTOR_STATE == MOTOR_CONST){
			LED_DATA |= 0x20;
		}
		if(MOTOR_STATE == MOTOR_BREAK){
			LED_DATA |= 0x40;
		}
		if(AGV_STATE == AGV_BOOT_ALM || AGV_STATE == AGV_READY_ALM || AGV_STATE == AGV_RUN_ALM){
			LED_DATA |= 0x80;
        }
  
  		bios_led_output(LED_DATA);
		beep();
    }
}

/****************************************************************************************************************/
/*	beepモジュール beep																							*/
/****************************************************************************************************************/
void beep(void){
	unsigned char isError = 0;
	if(AGV_STATE == AGV_BOOT_ALM || AGV_STATE== AGV_READY_ALM || AGV_STATE == AGV_RUN_ALM){
		isError = 1;
	}
	bios_beep_output(isError);
}
