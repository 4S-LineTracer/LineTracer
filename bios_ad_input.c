/*
 * AD•ÏŠ· 
*/
#include "bios.h"

// AD•ÏŠ·‚ğs‚¢A•ÏŠ·Œ‹‰Ê‚ğ•Ô‚·B
//  - Parameters: ‚È‚µ
//  - Returns: •ÏŠ·Œ‹‰Ê
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