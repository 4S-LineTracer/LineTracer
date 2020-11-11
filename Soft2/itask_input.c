/****************************************************************************************************************/
/*	FILE        : itask_input.c																					*/
/*	DATE        :Tue, Jan 17, 2012																				*/
/*	DESCRIPTION :AGVの入力割り込みタスク																		*/
/*	CPU TYPE    :H8/3052F																						*/
/****************************************************************************************************************/
#include "task.h"
/*
    // これtask.hのインクルードで済む気がする コンパイル通らなかったらこれに戻します
    #include "machine.h"
    #include "reg3052.h"
    #include "agvdef.h"
    #include "agvvars.h"
    #include "def_monitor_printf.h"
*/

/****************************************************************************************************************/
/*	入力タスク itask_input			                                                    						*/
/****************************************************************************************************************/
#pragma interrupt itask_input
void itask_input(void){
    static unsigned char sens_data;

    SW_DATA = bios_sw_input();

    if (bios_sensor_input() == 0x00){

        SENS_DATA = sens_data;
        //return;
    }else{
        SENS_DATA = bios_sensor_input();
        sens_data = SENS_DATA;
        //return;
    }
}