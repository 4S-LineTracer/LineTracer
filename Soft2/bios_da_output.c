/*
 * �T�[�{���[�^����, IRQ1���荞�ݏ���
*/
#include "bios.h"

// ���͒l�ɏ]���A�T�[�{���[�^���쓮����B
//  - Parameters: 
//    - DA_DATA: �쓮�M��(0x00:���[ 0xFF:�E�[)
//  - Returns: �Ȃ�
void bios_da_output(unsigned char DA_DATA){
	DA_PORT = DA_DATA;
}

// IRQ1(P8DR)�̓��͂��m�F����B
//  - Parameters: �Ȃ�
//  - Returns: IRQ1���͏��
unsigned char bios_irq1_input(void){
	unsigned char IRQ1_DATA;
	IRQ1_DATA = P8DR & 0x02;
	return IRQ1_DATA;
}
