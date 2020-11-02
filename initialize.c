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
    GRA0 = 1250 - 1;

    TCR1 = 0xA6;
    TIER1 = 0x01;
    GRA1 =  999 - 1; // �����l(�_�~�[)

    // TODO: ITU2,3�͂��ꂼ��1ms, 10ms/interrupt�ɐݒ�
    // TCR2 = 
    // TIOR2 = 
    // GRA2 = - 1;

    // TCR3 = 
    // TIOR3 = 
    // GRA3 = - 1;

    // �^�C�}�L����
    TSTR = 0b00000011;

    // �e�틤�L�ϐ��̒l��������
    MOTOR_SPEED = 0;
    MOTOR_STATE = MOTOR_STOP;
    AGV_STATE = AGV_BOOT;

    SW_DATA = 0;
    SENS_DATA = 0;
    IRQ1_DATA = 0;

}
