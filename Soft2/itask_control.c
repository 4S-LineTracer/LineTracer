/****************************************************************************************************************/
/* FILE        : itask_control.c                    */
/* DATE        :Tue, Jan 17, 2012                    */
/* DESCRIPTION :AGV�̓����ԊǗ����荞�݃^�X�N                */
/* CPU TYPE    :H8/3052F                      */
/****************************************************************************************************************/
#include "task.h"

unsigned char getMaxSpeed(unsigned char sw_data);
void handle_control(void);

// ���[�^���x�ő�/�ŏ�
unsigned char MAX_SPEED = 0;
unsigned char MIN_SPEED = 0;

/****************************************************************************************************************/
/* �����ԓ����ԊĎ��E�n���h������^�X�N itask_control              */
/****************************************************************************************************************/
#pragma interrupt itask_control
void itask_control(void){

    // �ő呬�x���X�C�b�`�̏�Ԃ���擾���A�ݒ�
    MAX_SPEED = getMaxSpeed(SW_DATA);

    // AGV�X�e�[�g�Ǘ�
    agv_state();

    // �n���h������
    handle_control();

    TSR2 &= ~0x01;
}

// �ő呬�x���v�Z����
unsigned char getMaxSpeed(unsigned char sw_data){
    unsigned char sw_data_speed = sw_data & 0x30;
    if (sw_data_speed == 0x00){
        return 0x40;
    }
    else if (sw_data_speed == 0x10){
        return 0x80;
    }
    else if (sw_data_speed == 0x20){
        return 0xc0;
    }
    else if (sw_data_speed == 0x30){
        return 0xff;
    }
    return 0x00;
}

// AGV�X�e�[�g�Ǘ�
void agv_state(void){
    // �N�[���^�C�� COUNT�~���b�Ԃ͎���IRQ1���󂯕t���Ȃ�
    static unsigned char COUNT = 0;

    // IRQ1���荞�݂����o����A���N�[���^�C������������Ă����ꍇ
    if (IRQ1_DATA == 1 && COUNT == 0){
        // ���[�^���x��ύX
        if(AGV_STATE == AGV_RUN){
            MOTOR_SPEED = MIN_SPEED;
        }else if (AGV_STATE == AGV_READY){
            MOTOR_SPEED = MAX_SPEED; 
        }

        // �N�[���^�C����������
        IRQ1_DATA = 0;
        COUNT = 10;

    }

    // ���[�^����~��������READY�ɑJ��
    if (MOTOR_STATE == MOTOR_STOP){
        AGV_STATE = AGV_READY;
    }

    // �Z���T��0�����o������SEARCH�ɑJ��
    if(SENS_DATA == 0x00){
        AGV_STATE = AGV_SEARCH;
    }

    // �N�[���^�C������������
    if (COUNT > 0){
        COUNT--;
    }
}

/****************************************************************************************************************/
/* �Z���T�ʒu�v�Z���W���[�� cal_sensor_position                */
/****************************************************************************************************************/
void cal_sensor_position(void){
}
/****************************************************************************************************************/
/* �n���h�����䃂�W���[�� handle_control                  */
/****************************************************************************************************************/
void handle_control(void){
    static unsigned char HANDLE_DATA = 0x80;
    unsigned char SENS_DATA = 0;
    unsigned char SENS_DATA_R = 0;
    unsigned char SENS_DATA_L = 0;

    // �Z���T����l���擾���A���E�ɕ���
    SENS_DATA = bios_sensor_input();
    SENS_DATA_R = (SENS_DATA & 0xF0) >> 4;
    SENS_DATA_L = SENS_DATA & 0x0F;

    // 臒l�𒴂����瓮����
    // TODO: �n���h���������ʂ͒��S���痣��Ă���قǑ傫���ق�������?
    if (SENS_DATA_L > 0x03){
        HANDLE_DATA--;
    }
    if (SENS_DATA_R > 0x0c){
        HANDLE_DATA++;
    }

    // �n���h���l�͈̓`�F�b�N (�Z�[�t�e�B)
    if (HANDLE_DATA > 0xFE){
        HANDLE_DATA = 0xFE;
    }
    if (HANDLE_DATA < 1){
        HANDLE_DATA = 0x01;
    }

    // �T�[�{�ɏo��
    bios_da_output(HANDLE_DATA);
}
