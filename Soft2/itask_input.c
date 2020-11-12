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
    // TODO: ここはstaticじゃないと値が保存されなくて困る気がします
    unsigned char sens_data;

    // TODO: チャタリング対策しといた方がいいかも?

    /*
    // 例えばこんな感じ デバッグしてないのでそのままコピーはちと危険
    static unsigned char switchBuffer[] = {0x00, 0x00, 0x00, 0x00};
    static unsigned char index = 0;
    unsigned char tmp = 0xFF;
    unsigned char i = 0;
    switchBuffer[index] = bios_sw_input();
    index++;
    index &= 3; // indexが3以上になるのを防ぐ

    for (i = 0; i < 4; i++){
        tmp &= switchBuffer[i];
    }
    SW_DATA = tmp;
    */

    SW_DATA = bios_sw_input();

    // TODO:センサが検出できなくなった時の処理をどう書くかやなぁ
    // itask_controlでやってもいいけど、一定時間はitask_inputで耐えてた方が
    // itask_controlの実装する人も安心できそうではある
    // テストソースかけなくてすまん とりあえず田中に聞けばここのテストソースは出せます
    if (bios_sensor_input() == 0x00){

        SENS_DATA = sens_data;
        //return;
    }else{
        SENS_DATA = bios_sensor_input();
        sens_data = SENS_DATA;
        //return;
    }
}