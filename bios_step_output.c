/*
 * �X�e�b�s���O���[�^�㎥
*/
#include "bios.h"

// �X�e�b�s���O���[�^�ɗ㎥�M�����o�͂���B
//  - Parameters:
//    - i: �㎥�M���C���f�b�N�X
//  - Returns: �Ȃ�
void bios_step_output (unsigned char i){
    unsigned char STEP_DATA[4] = {0x03, 0x09, 0x0c, 0x06};

    if(i>3||i<0){
        return;
    }

    STEP_PORT = STEP_DATA[i];
}