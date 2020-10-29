/*
 * LED出力
*/
#include "bios.h"

// LED_PORTに値を出力する。
//  - Parameters: 
//    - value: 出力する値
//  - Return: なし
void bios_led_output(unsigned char value){
    LED_PORT = value;
}
