/*
 * サーボモータ制御, IRQ1割り込み処理
*/
#include "bios.h"

// 入力値に従い、サーボモータを駆動する。
//  - Parameters: 
//    - DA_DATA: 駆動信号(0x00:左端 0xFF:右端)
//  - Returns: なし
void bios_da_output(unsigned char DA_DATA){
	DA_PORT = DA_DATA;
}

// IRQ1(P8DR)の入力を確認する。
//  - Parameters: なし
//  - Returns: IRQ1入力状態
unsigned char bios_irq1_input(void){
	unsigned char IRQ1_DATA;
	IRQ1_DATA = P8DR & 0x02;
	return IRQ1_DATA;
}
