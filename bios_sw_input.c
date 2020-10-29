/*
 * スイッチ入力取得
*/
#include "bios.h"

// SW_PORTから値を取得する。
//  - Parameters: なし
//  - Return: SW_PORTから取得した値
unsigned char bios_sw_input(){
    return SW_PORT;
}
