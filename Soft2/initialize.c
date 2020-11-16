/*
 * �����ԏ��������[�`��
*/
#include "initialize.h"

// �����Ԃ̃��W�X�^�Q������������B
//  - Parameters: �Ȃ�
//  - Returns: �Ȃ�
void initialize(){
    // ITU0��0.1ms�Ԋu�̃p���X���o�́AITU1�͂�����J�E���^�Ƃ���
    TCR0 = ITU_CLR_GRA | ITU_EDGE_RISE | ITU_PS_1;
    TIOR0 = 0x8B;
    GRA0 = 625 - 1;

    TCR1 = ITU_CLR_GRA | ITU_EDGE_RISE | ITU_PS_EXT_C;
    TIER1 = 0x01;
    GRA1 = 999 - 1; // �����l(�_�~�[)

    // ITU2: 1ms/interrupt
    TCR2 = ITU_CLR_GRA | ITU_EDGE_RISE | ITU_PS_8;
    TIER2 = 0x01;
    GRA2 = 3125 - 1; // 40 * 8 = 320ns 0.32us. 1ms / 320n = 3,125.

	// ITU3: 10ms/interrupt
    TCR3 = ITU_CLR_GRA | ITU_EDGE_RISE | ITU_PS_8;
    TIER3 = 0x01;
    GRA3 = 31250 - 1; // 40 * 8 = 320ns 0.32us. 10ms / 320n = 31,250.
	
	// IRQ1
	IER |= 0x02;
	ISCR |= 0x02;

    // �e�틤�L�ϐ��̒l��������
    MOTOR_SPEED = 0x00;
    MOTOR_STATE = MOTOR_STOP;
    AGV_STATE = AGV_BOOT;
    SW_DATA = 0;
    SENS_DATA = 0;
    IRQ1_DATA = 0;
	SENS_PROOF_TIME = 50; // Nms

    // �^�C�}�L����
    TSTR |= 0x0F;

    // �����ݗL����
	and_ccr(0x7F);
}

