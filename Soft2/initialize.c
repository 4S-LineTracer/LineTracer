/*
 * �����ԏ��������[�`��
*/
#include "initialize.h"

// �����Ԃ̃��W�X�^�Q������������B
//  - Parameters: �Ȃ�
//  - Returns: �Ȃ�
void initialize(){
    // ITU0��0.1ms�Ԋu�̃p���X���o�́AITU1�͂�����J�E���^�Ƃ���
    TCR0 = 0xA0;
    TIOR0 = 0x8B;
    GRA0 = 625 - 1;

    TCR1 = 0xA6;
    TIER1 = 0x01;
    GRA1 = 999 - 1; // �����l(�_�~�[)

    // ITU2: 1ms/interrupt
    TCR2 = 0xA6; // 1010 0001
    TIER2 = 0x01;
    GRA2 = 100 - 1;

	// ITU3: 10ms/interrupt
    TCR3 = 0xA6; // 1010 0100
    TIER3 = 0x01;
    GRA3 = 10 - 1;

    // �e�틤�L�ϐ��̒l��������
    MOTOR_SPEED = 0x00;
    MOTOR_STATE = MOTOR_STOP;
    AGV_STATE = AGV_BOOT;
    SW_DATA = 0;
    SENS_DATA = 0;
    IRQ1_DATA = 0;

    // �^�C�}�L����
    TSTR |= 0x0F;

    // �����ݗL����
	and_ccr(0x7F);
}
