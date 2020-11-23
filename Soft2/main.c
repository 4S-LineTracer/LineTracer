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

void agv_init(void);
unsigned char setLEDData();
unsigned char isErrorState(unsigned char state);
void beep(unsigned char stat);

/****************************************************************************************************************/
/*	main関数																									*/
/****************************************************************************************************************/
int main(){
    // レジスタ類初期化
    agv_init();

    // メインループ
    while(1){
        // LEDに出力する内容を更新
        bios_led_output(setLEDData());

        // エラー状態ならブザーも鳴動
        beep(isErrorState(AGV_STATE));
		
    }

    return 0;
}

// agv初期化
void agv_init(void){
    initialize();
}

// LEDに出力する内容を決める。
//  - Parameters: なし
//  - Return: LEDに流し込む値
unsigned char setLEDData(){
    unsigned char value = 0x00;

    value |= ((AGV_STATE == AGV_BOOT) << 0);
    value |= ((AGV_STATE == AGV_READY) << 1);
    value |= ((AGV_STATE == AGV_RUN) << 2);
    value |= ((AGV_STATE == AGV_SEARCH) << 3);
    value |= ((MOTOR_STATE == MOTOR_ACCEL) << 4);
    value |= ((MOTOR_STATE == MOTOR_BREAK) << 5);
    value |= ((MOTOR_STATE == MOTOR_STOP) << 6);
    value |= (isErrorState(AGV_STATE) << 7);
	
    return value;
}

// ブザーを鳴らす。
//  - Parameters: なし
//  - Return: なし
void beep(unsigned char stat){
    // TODO: 鳴らし方を変えられないか?
    bios_beep_output(stat);
}

// エラー状態かどうかを取得する。
//  - Parameters:
//      - state: 搬送車の状態 (AGV_STATE)
//  - Return: エラー状態ならば1 そうでなければ0
unsigned char isErrorState(unsigned char state){
    switch (state){
        case AGV_BOOT_ALM:
        case AGV_READY_ALM:
        case AGV_RUN_ALM:
            return 1;
        
        default:
            return 0;
    }
}