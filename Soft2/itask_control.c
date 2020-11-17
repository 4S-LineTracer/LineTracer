/****************************************************************************************************************/
/* FILE        : itask_control.c                    */
/* DATE        :Tue, Jan 17, 2012                    */
/* DESCRIPTION :AGVの動作状態管理割り込みタスク                */
/* CPU TYPE    :H8/3052F                      */
/****************************************************************************************************************/
#include "task.h"

unsigned char getMaxSpeed(unsigned char sw_data);
void handle_control();
void agv_state();

// モータ速度最大/最小
unsigned char MAX_SPEED = 0;
unsigned char MIN_SPEED = 0;

/****************************************************************************************************************/
/* 搬送車動作状態監視・ハンドル制御タスク itask_control              */
/****************************************************************************************************************/
#pragma interrupt itask_control
void itask_control(void){

    // 最大速度をスイッチの状態から取得し、設定
    // TODO: なんかモータの調子がおかしい インデックスの設定ミスかこれ?
    MAX_SPEED = getMaxSpeed(SW_DATA);

    // AGVステート管理
    agv_state();

    // モータ速度制御
    // TODO: 関数で分ける
    if (AGV_STATE == AGV_RUN){
        MOTOR_SPEED = MAX_SPEED;
    }
    else{
        MOTOR_SPEED = MIN_SPEED;
    }

    // ハンドル制御
    handle_control();

    TSR2 &= ~0x01;
}

// 最大速度を計算する
unsigned char getMaxSpeed(unsigned char sw_data){
    unsigned char sw_data_speed = sw_data & 0x30;
    if (sw_data_speed == 0x00){
        return 0x90;
    }
    else if (sw_data_speed == 0x10){
        return 0xB0;
    }
    else if (sw_data_speed == 0x20){
        return 0xD0;
    }
    else if (sw_data_speed == 0x30){
        return 0xF0;
    }
    return 0x00;
}

// AGVステート管理
void agv_state(){

    // AGV_BOOT -> AGV_READYに遷移
    if (AGV_STATE == AGV_BOOT || AGV_STATE == AGV_BOOT_ALM){
        if (IRQ1_DATA == 0){
            AGV_STATE = AGV_READY;
        }
        else{
            AGV_STATE = AGV_BOOT_ALM;
        }
    }

    if (AGV_STATE == AGV_RUN_ALM && MOTOR_STATE == MOTOR_STOP){
        AGV_STATE = AGV_READY;
    }

    if (AGV_STATE == AGV_READY && IRQ1_DATA == 1 && SENS_DATA == 0x00){
        AGV_STATE = AGV_READY_ALM;
    }
    if (AGV_STATE == AGV_READY_ALM && SENS_DATA != 0x00){
        AGV_STATE = AGV_READY;
    }

    // IRQ1割り込みを検知したら
    if (IRQ1_DATA == 0x01 && COOL_TIME == 0){
        // 割り込み検知フラグを折り、クールタイムを設定
        IRQ1_DATA = 0x00;
        COOL_TIME = 50;

        // AGV_READYならAGV_RUNに移行し、最高速度を設定
        // AGV_RUNならAGV_READYに移行し、止める方向へ
        switch (AGV_STATE){
        case AGV_READY:
            AGV_STATE = AGV_RUN;
            break;

        case AGV_RUN:
            AGV_STATE = AGV_READY;
            break;
        }
    }

    // クールタイム消化
    COOL_TIME -= (COOL_TIME > 0);
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
    unsigned char SENS_DATA_R = 0;
    unsigned char SENS_DATA_L = 0;

    // センサから値を取得し、左右に分割
    SENS_DATA_R = (SENS_DATA & 0xF0) >> 4;
    SENS_DATA_L = SENS_DATA & 0x0F;

    switch (AGV_STATE){
    case AGV_READY:
        break;

    case AGV_RUN:

        // 閾値を超えたら動かす
        // TODO: ハンドル動かす量は中心から離れているほど大きいほうがいい?
        if (SENS_DATA_L > 0x02){
            HANDLE_DATA--;
        }
        if (SENS_DATA_R > 0x04){
            HANDLE_DATA++;
        }

        // ハンドル値範囲チェック (セーフティ)
        if (HANDLE_DATA > 0xFE){
            HANDLE_DATA = 0xFE;
        }
        if (HANDLE_DATA < 1){
            HANDLE_DATA = 0x01;
        }

        if (SENS_DATA == 0){
            HANDLE_DATA = 0x80;
            AGV_STATE = AGV_RUN_ALM;
        }

        break;

    default:
        break;
    }

    // サーボに出力
    bios_da_output(HANDLE_DATA);
}
