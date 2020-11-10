/*
 * �X�e�b�s���O���[�^����
*/
#include "motorDrive.h"

// �^�C�~���O�𒲐����ă��[�^��㎥
void motorDrive(unsigned char* motorState, unsigned char* motorSpeed){
    static unsigned int pulseIndex = 0;

    // GRA1���X�V
    GRA1 = accTable[pulseIndex];

    // �㎥
    if(*motorState != MOTOR_STOP){
        stepOutput();
    }

    // �p���X���g���e�[�u���̎Q�Ɛ���ړ�����
    calcPulseFreqTableIndex(&pulseIndex, motorState, motorSpeed);
}

// �p���X���g���e�[�u����ǂݍ��ވʒu���ړ�
void calcPulseFreqTableIndex(unsigned int *index, unsigned char *motorState, unsigned char *motorSpeed){
    // motorSpeed�����}�b�v���A�ō����x���v�Z
    // 00~FF�̒l��0~accDataSize-1�ɕϊ�
    unsigned int maxSpeed = (float)*motorSpeed * (((float)accDataSize - 1) / 255.0);
    #ifdef DEBUG
        // �������matplotlib�ʂ�
        // printf("index: %d\n", *index);
        // printf("maxSpeed: %d\n", maxSpeed);
        printf("%d, %d, %d\n", *index, maxSpeed, *motorState);
    #endif

    // �ō����x�ƍ��̃p���X���g���C���f�b�N�X���r���ĉ�����
    if(maxSpeed > *index){
        // ����
        MOTOR_STATE = MOTOR_ACCEL;
        (*index)++;
        return;
		
    } else if(maxSpeed < *index){
        // ����
        MOTOR_STATE = MOTOR_BREAK;
        (*index)--;
        return;
		
    } else if(maxSpeed == *index){
        // �������Ȃ�CONST �������Ȃ�STOP�ɑJ��
        MOTOR_STATE = (maxSpeed > 0) ? MOTOR_CONST : MOTOR_STOP;

        return;
    }
}

// �X�e�b�s���O���[�^�ɗ㎥�M�����o��
void stepOutput(){
    static int index = 0;

    #ifndef DEBUG
        bios_step_output(index);
    #else
        printf("bios_step_output: %d\n", index);
    #endif

    // �C���f�b�N�X���ړ�����
    index++;
    index &= 3;
}
