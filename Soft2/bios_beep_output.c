/*
 * �u�U�[����
*/
#include "bios.h"

// �u�U�[���������B
//  - Parameters:
//    - beep: �u�U�[����(0: OFF 1: ON)
void bios_beep_output(unsigned char beep){
    if (beep == 1){
        BEEP_PORT=1;
    }
    else if (beep == 0){
        BEEP_PORT=0;
    }
}

