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

/*
// ���������͂��̂܂܃y�^�[�ł̓_���ł�
// �K�X���������Ă�������
#pragma interrupt imitation
void imitation(void){
	IRQ1_DATA = 0x01;
	ISR &= 0xFD;
	return;
}

// ---- itask_control ----
void itask_control(){
	if(IRQ1_DATA == 1){
		IRQ1_DATA = 0;	
		// interrupt process...
		// example:
		switch(AGV_STATE){
			
		}
		// MOTOR_SPEED = 0x00; // �\�Ȍ���̃X�s�[�h�Ō���
	}
}
*/