/*
 * 搬送車初期化ルーチン
*/
#include "initialize.h"

// 搬送車のレジスタ群を初期化する。
//  - Parameters: なし
//  - Returns: なし
void initialize(){
    // TODO: ITU0は0.1ms間隔のパルスを出力、ITU1はそれをカウンタとする

    // TODO: ITU2,3はそれぞれ1ms, 10ms/interruptに設定

    // 各種共有変数の値を初期化
    MOTOR_SPEED = 0;
    MOTOR_STATE = MOTOR_STOP;
    AGV_STATE = AGV_BOOT;

    SW_DATA = 0;
    SENS_DATA = 0;
    IRQ1_DATA = 0;

}
