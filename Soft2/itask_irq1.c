/*
 * IRQ1���荞�ݏ���
*/
#include "task.h"

// IRQ1�̏�Ԃ�IRQ1_DATA�ɔ��f����B (�g���K: IRQ1)
//  - Parameters: �Ȃ�
//  - Returns: �Ȃ�
#pragma	interrupt itask_irq1
void  itask_irq1(void){
	unsigned char IRQ1_P = bios_irq1_input();
	if(IRQ1_P == 0x00 && IRQ1_DATA == 1){IRQ1_DATA = 0;}
	if(IRQ1_P == 0x00 && IRQ1_DATA == 0){IRQ1_DATA = 1;}	
}
