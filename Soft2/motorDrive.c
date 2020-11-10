/*
 * ステッピングモータ制御
*/
#include "motorDrive.h"

// タイミングを調整してモータを励磁
void motorDrive(unsigned char* motorState, unsigned char* motorSpeed){
    static unsigned int pulseIndex = 0;

    // GRA1を更新
    GRA1 = accTable[pulseIndex];

    // 励磁
    if(*motorState != MOTOR_STOP){
        stepOutput();
    }

    // パルス周波数テーブルの参照先を移動する
    calcPulseFreqTableIndex(&pulseIndex, motorState, motorSpeed);
}

// パルス周波数テーブルを読み込む位置を移動
void calcPulseFreqTableIndex(unsigned int *index, unsigned char *motorState, unsigned char *motorSpeed){
    // motorSpeedをリマップし、最高速度を計算
    // 00~FFの値を0~accDataSize-1に変換
    unsigned int maxSpeed = (float)*motorSpeed * (((float)accDataSize - 1) / 255.0);
    #ifdef DEBUG
        // ちょっとmatplotlib通す
        // printf("index: %d\n", *index);
        // printf("maxSpeed: %d\n", maxSpeed);
        printf("%d, %d, %d\n", *index, maxSpeed, *motorState);
    #endif

    // 最高速度と今のパルス周波数インデックスを比較して加減速
    if(maxSpeed > *index){
        // 加速
        MOTOR_STATE = MOTOR_ACCEL;
        (*index)++;
        return;
		
    } else if(maxSpeed < *index){
        // 減速
        MOTOR_STATE = MOTOR_BREAK;
        (*index)--;
        return;
		
    } else if(maxSpeed == *index){
        // 加速中ならCONST 減速中ならSTOPに遷移
        MOTOR_STATE = (maxSpeed > 0) ? MOTOR_CONST : MOTOR_STOP;

        return;
    }
}

// ステッピングモータに励磁信号を出力
void stepOutput(){
    static int index = 0;

    #ifndef DEBUG
        bios_step_output(index);
    #else
        printf("bios_step_output: %d\n", index);
    #endif

    // インデックスを移動する
    index++;
    index &= 3;
}
