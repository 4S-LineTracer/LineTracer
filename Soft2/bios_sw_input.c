/*
 * �X�C�b�`���͎擾
*/
#include "bios.h"

// SW_PORT����l���擾����B
//  - Parameters: �Ȃ�
//  - Return: SW_PORT����擾�����l
unsigned char bios_sw_input(){
    return SW_PORT;
}
