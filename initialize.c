/*
 * �����ԏ��������[�`��
*/
#include "initialize.h"

// �����Ԃ̃��W�X�^�Q������������B
//  - Parameters: �Ȃ�
//  - Returns: �Ȃ�
void initialize(){
    // TODO: ITU0��0.1ms�Ԋu�̃p���X���o�́AITU1�͂�����J�E���^�Ƃ���

    // TODO: ITU2,3�͂��ꂼ��1ms, 10ms/interrupt�ɐݒ�

    // �e�틤�L�ϐ��̒l��������
    MOTOR_SPEED = 0;
    MOTOR_STATE = MOTOR_STOP;
    AGV_STATE = AGV_BOOT;

    SW_DATA = 0;
    SENS_DATA = 0;
    IRQ1_DATA = 0;

}
