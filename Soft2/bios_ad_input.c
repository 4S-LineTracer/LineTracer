/*
 * AD�ϊ� 
*/
#include "bios.h"

// AD�ϊ����s���A�ϊ����ʂ�Ԃ��B
//  - Parameters: �Ȃ�
//  - Returns: �ϊ�����
unsigned char bios_ad_input() {
    SH_PORT=SAMPLE_MODE;
    nop();
    nop();
    nop();
    nop();
    SH_PORT=HOLD_MODE;

    AD_PORT=0x01;
    while(P8DR&0x01){}

    return AD_PORT;
}