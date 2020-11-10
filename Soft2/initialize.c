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
    GRA0 = 625 - 1;

    TCR1 = 0xA6;
    TIER1 = 0x01;
    GRA1 = 999 - 1; // 初期値(ダミー)

    // ITU2: 1ms/interrupt
    TCR2 = 0xA6; // 1010 0001
    TIER2 = 0x01;
    GRA2 = 100 - 1;

	// ITU3: 10ms/interrupt
    TCR3 = 0xA6; // 1010 0100
    TIER3 = 0x01;
    GRA3 = 10 - 1;

    // 各種共有変数の値を初期化
    MOTOR_SPEED = 0x00;
    MOTOR_STATE = MOTOR_STOP;
    AGV_STATE = AGV_BOOT;
    SW_DATA = 0;
    SENS_DATA = 0;
    IRQ1_DATA = 0;

    // タイマ有効化
    TSTR |= 0x0F;

    // 割込み有効化
	and_ccr(0x7F);
}
