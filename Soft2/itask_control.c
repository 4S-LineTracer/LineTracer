/****************************************************************************************************************/
/* FILE        : itask_control.c                    */
/* DATE        :Tue, Jan 17, 2012                    */
/* DESCRIPTION :AGVの動作状態管理割り込みタスク                */
/* CPU TYPE    :H8/3052F                      */
/****************************************************************************************************************/
#include "task.h"

unsigned char getMaxSpeed(unsigned char sw_data);
void handle_control(void);

// モータ速度最大/最小
unsigned char MAX_SPEED = 0;
unsigned char MIN_SPEED = 0;

/****************************************************************************************************************/
/* 搬送車動作状態監視・ハンドル制御タスク itask_control              */
/****************************************************************************************************************/
#pragma interrupt itask_control
void itask_control(void){

    // 最大速度をスイッチの状態から取得し、設定
    MAX_SPEED = getMaxSpeed(SW_DATA);

    // AGVステート管理
    agv_state();

    // ハンドル制御
    handle_control();

    TSR2 &= ~0x01;
}

// 最大速度を計算する
unsigned char getMaxSpeed(unsigned char sw_data){
    unsigned char sw_data_speed = sw_data & 0x30;
    if (sw_data_speed == 0x00){
        return 0x40;
    }
    else if (sw_data_speed == 0x10){
        return 0x80;
    }
    else if (sw_data_speed == 0x20){
        return 0xc0;
    }
    else if (sw_data_speed == 0x30){
        return 0xff;
    }
    return 0x00;
}

// AGVステート管理
void agv_state(void){
    // クールタイム COUNTミリ秒間は次のIRQ1を受け付けない
    static unsigned char COUNT = 0;

    // IRQ1割り込みが検出され、かつクールタイムが消化されていた場合
    if (IRQ1_DATA == 1 && COUNT == 0){
        // モータ速度を変更
        if(AGV_STATE == AGV_RUN){
            MOTOR_SPEED = MIN_SPEED;
        }else if (AGV_STATE == AGV_READY){
            MOTOR_SPEED = MAX_SPEED; 
        }

        // クールタイムを初期化
        IRQ1_DATA = 0;
        COUNT = 10;

    }

    // モータが停止したら常にREADYに遷移
    if (MOTOR_STATE == MOTOR_STOP){
        AGV_STATE = AGV_READY;
    }

    // センサが0を検出したらSEARCHに遷移
    if(SENS_DATA == 0x00){
        AGV_STATE = AGV_SEARCH;
    }

    // クールタイムを消化する
    if (COUNT > 0){
        COUNT--;
    }
}

/****************************************************************************************************************/
/* センサ位置計算モジュール cal_sensor_position                */
/****************************************************************************************************************/
void cal_sensor_position(void){
}
/****************************************************************************************************************/
/* ハンドル制御モジュール handle_control                  */
/****************************************************************************************************************/
void handle_control(void){
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
    if (SENS_DATA_L > 0x03){
        HANDLE_DATA--;
    }
    if (SENS_DATA_R > 0x0c){
        HANDLE_DATA++;
    }

    // ハンドル値範囲チェック (セーフティ)
    if (HANDLE_DATA > 0xFE){
        HANDLE_DATA = 0xFE;
    }
    if (HANDLE_DATA < 1){
        HANDLE_DATA = 0x01;
    }

    // サーボに出力
    bios_da_output(HANDLE_DATA);
}
