/*
 * IRQ1���荞�ݏ���
*/
#include "task.h"
#include "def_monitor_printf.h"

// IRQ1�̏�Ԃ�IRQ1_DATA�ɔ��f����B (�g���K: IRQ1)
//  - Parameters: �Ȃ�
//  - Returns: �Ȃ�
#pragma interrupt itask_irq1
void itask_irq1(void){

    // IRQ1���荞�݂�itask_control�ɒʒm
    IRQ1_DATA = 1;
    ISR &= 0xFD;
    return;
}
