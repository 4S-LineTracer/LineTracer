/****************************************************************************************************************/
/* FILE        : itask_control.c                    */
/* DATE        :Tue, Jan 17, 2012                    */
/* DESCRIPTION :AGVの動作状態管理割り込みタスク                */
/* CPU TYPE    :H8/3052F                      */
/****************************************************************************************************************/
#include "task.h"

void handle_control(void);

/****************************************************************************************************************/
/* 搬送車動作状態監視・ハンドル制御タスク itask_control              */
/****************************************************************************************************************/
#pragma interrupt itask_control
void itask_control(void){
	
	unsigned char MAX_SPPED=0;
	unsigned char MIN_SPPED=0;
	static unsigned char COUNT=0;
	
    handle_control();
	
    //モータースピード触る
	if(SW_DATA&0x30 == 0x00){MAX_SPPED=0x40;}
	else if(SW_DATA&0x30 == 0x10){MAX_SPPED=0x80;}
	else if(SW_DATA&0x30 == 0x20){MAX_SPPED=0xc0;}
	else if(SW_DATA&0x30 == 0x30){MAX_SPPED=0xff;}
	
	//AGVステート触る+モーター速度変更
	if(IRQ1_DATA==1 && COUNT==0){
		IRQ1_DATA=0;
		switch(AGV_STATE){
			
			case AGV_READY:
			AGV_STATE=AGV_RUN;
		    MOTOR_SPEED=MAX_SPPED;
		    break;
			
			case AGV_RUN:
		    MOTOR_SPEED=MIN_SPPED;
		    break;
			
		}
		
		COUNT=10;
		
		}
	if(MOTOR_STATE==MOTOR_STOP){
		AGV_STATE=AGV_READY;
		}
	
	//テスト用？
	//bios_led_output(0xff);
	
	if(COUNT>0){COUNT--;}
	TSR2 &= ~0x01;
}

/****************************************************************************************************************/
/* AGVステート管理モジュール agv_state                   */
/****************************************************************************************************************/
void agv_state(void){

} 

/****************************************************************************************************************/
/* センサ位置計算モジュール cal_sensor_position                */
/****************************************************************************************************************/
void cal_sensor_position(void){

}
/****************************************************************************************************************/
/* ハンドル制御モジュール handle_control                  */
/****************************************************************************************************************/
void handle_control(void) {
    static unsigned char HANDLE_DATA = 0x80;
	unsigned char SENS_DATA = 0;
	unsigned char SENS_DATA_R = 0;
	unsigned char SENS_DATA_L = 0;
	
	// センサから値を取得し、左右に分割
	SENS_DATA = bios_sensor_input();
	SENS_DATA_R = (SENS_DATA & 0xF0) >> 4;
    SENS_DATA_L = SENS_DATA & 0x0F;
	
	// 閾値を超えたら動かす
	// TODO: ハンドル動かす量は中心から離れているほど大きいほうがいい?
	if(SENS_DATA_L > 0x03){
	    HANDLE_DATA--;
    }
    if(SENS_DATA_R > 0x0c){
        HANDLE_DATA++;
    }
	
	// ハンドル値範囲チェック (セーフティ)
	if(HANDLE_DATA > 0xFE){
		HANDLE_DATA = 0xFE;
	}
	if(HANDLE_DATA < 1){
	    HANDLE_DATA = 0x01;	
	}
	
	// サーボに出力
	bios_da_output(HANDLE_DATA);
}
