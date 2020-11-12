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

    // TODO: IRQ1_DATA�͂����ł̓A�T�[�g���邾���ɂ��������ǂ�����?
    // �����ŒZ���Ԃŏ������I�����Ȃ��ƃX�e�b�s���O���[�^�̐���ɉe�����Ă���̂�
    /*
    // �Ⴆ�΂���Ȋ���
    IRQ1_DATA = 1;
    ISR &= 0xFD;
    return;
    */


    unsigned int i = 0;

    if (IRQ1_DATA == 1){
        IRQ1_DATA = 0;
    }else if (IRQ1_DATA == 0){
        IRQ1_DATA = 1;
    }

    while (--i){}

    ISR &= 0xfd;
    return;
}
