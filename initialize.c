/*
 * 搬送車初期化ルーチン
*/
#include "initialize.h"

// 搬送車のレジスタ群を初期化する。
//  - Parameters: なし
//  - Returns: なし
void initialize(){
    // ITU0は0.1ms間隔のパルスを出力、ITU1はそれをカウンタとする
    TCR0 = 0xA0;
    TIOR0 = 0x8B;
    GRA0 = 1250 - 1;

    TCR1 = 0xA6;
    TIER1 = 0x01;
    GRA1 =  999 - 1; // 初期値(ダミー)

    // TODO: ITU2,3はそれぞれ1ms, 10ms/interruptに設定
    // TCR2 = 
    // TIOR2 = 
    // GRA2 = - 1;

    // TCR3 = 
    // TIOR3 = 
    // GRA3 = - 1;

    // タイマ有効化
    TSTR = 0b00000011;

    // 各種共有変数の値を初期化
    MOTOR_SPEED = 0;
    MOTOR_STATE = MOTOR_STOP;
    AGV_STATE = AGV_BOOT;

    SW_DATA = 0;
    SENS_DATA = 0;
    IRQ1_DATA = 0;

}
