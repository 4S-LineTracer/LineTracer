/*
 * ステッピングモータ励磁
*/
#include "bios.h"

// ステッピングモータに励磁信号を出力する。
//  - Parameters:
//    - i: 励磁信号インデックス
//  - Returns: なし
void bios_step_output (unsigned char i){
    unsigned char STEP_DATA[4] = {0x03, 0x09, 0x0c, 0x06};

    if(i>3||i<0){
        return;
    }

    STEP_PORT = STEP_DATA[i];
}