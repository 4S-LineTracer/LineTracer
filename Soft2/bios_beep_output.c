/*
 * ブザー制御
*/
#include "bios.h"

// ブザーを鳴動させる。
//  - Parameters:
//    - beep: ブザー制御(0: OFF 1: ON)
void bios_beep_output(unsigned char beep){
    if (beep == 1){
        BEEP_PORT=1;
    }
    else if (beep == 0){
        BEEP_PORT=0;
    }
}

