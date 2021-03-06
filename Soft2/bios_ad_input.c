/*
 * AD変換 
*/
#include "bios.h"

// AD変換を行い、変換結果を返す。
//  - Parameters: なし
//  - Returns: 変換結果
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