/*
 * LED�o��
*/
#include "bios.h"

// LED_PORT�ɒl���o�͂���B
//  - Parameters: 
//    - value: �o�͂���l
//  - Return: �Ȃ�
void bios_led_output(unsigned char value){
    LED_PORT = value;
}
