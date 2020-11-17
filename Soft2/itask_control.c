/****************************************************************************************************************/
/* FILE        : itask_control.c                    */
/* DATE        :Tue, Jan 17, 2012                    */
/* DESCRIPTION :AGV�̓����ԊǗ����荞�݃^�X�N                */
/* CPU TYPE    :H8/3052F                      */
/****************************************************************************************************************/
#include "task.h"

unsigned char getMaxSpeed(unsigned char sw_data);
void handle_control();
void agv_state();

// ���[�^���x�ő�/�ŏ�
unsigned char MAX_SPEED = 0;
unsigned char MIN_SPEED = 0;

/****************************************************************************************************************/
/* �����ԓ����ԊĎ��E�n���h������^�X�N itask_control              */
/****************************************************************************************************************/
#pragma interrupt itask_control
void itask_control(void){

    // �ő呬�x���X�C�b�`�̏�Ԃ���擾���A�ݒ�
    // TODO: �Ȃ񂩃��[�^�̒��q���������� �C���f�b�N�X�̐ݒ�~�X������?
    MAX_SPEED = getMaxSpeed(SW_DATA);

    // AGV�X�e�[�g�Ǘ�
    agv_state();

    // ���[�^���x����
    // TODO: �֐��ŕ�����
    if (AGV_STATE == AGV_RUN){
        MOTOR_SPEED = MAX_SPEED;
    }
    else{
        MOTOR_SPEED = MIN_SPEED;
    }

    // �n���h������
    handle_control();

    TSR2 &= ~0x01;
}

// �ő呬�x���v�Z����
unsigned char getMaxSpeed(unsigned char sw_data){
    unsigned char sw_data_speed = sw_data & 0x30;
    if (sw_data_speed == 0x00){
        return 0x90;
    }
    else if (sw_data_speed == 0x10){
        return 0xB0;
    }
    else if (sw_data_speed == 0x20){
        return 0xD0;
    }
    else if (sw_data_speed == 0x30){
        return 0xF0;
    }
    return 0x00;
}

// AGV�X�e�[�g�Ǘ�
void agv_state(){

    // AGV_BOOT -> AGV_READY�ɑJ��
    if (AGV_STATE == AGV_BOOT || AGV_STATE == AGV_BOOT_ALM){
        if (IRQ1_DATA == 0){
            AGV_STATE = AGV_READY;
        }
        else{
            AGV_STATE = AGV_BOOT_ALM;
        }
    }

    if (AGV_STATE == AGV_RUN_ALM && MOTOR_STATE == MOTOR_STOP){
        AGV_STATE = AGV_READY;
    }

    if (AGV_STATE == AGV_READY && IRQ1_DATA == 1 && SENS_DATA == 0x00){
        AGV_STATE = AGV_READY_ALM;
    }
    if (AGV_STATE == AGV_READY_ALM && SENS_DATA != 0x00){
        AGV_STATE = AGV_READY;
    }

    // IRQ1���荞�݂����m������
    if (IRQ1_DATA == 0x01 && COOL_TIME == 0){
        // ���荞�݌��m�t���O��܂�A�N�[���^�C����ݒ�
        IRQ1_DATA = 0x00;
        COOL_TIME = 50;

        // AGV_READY�Ȃ�AGV_RUN�Ɉڍs���A�ō����x��ݒ�
        // AGV_RUN�Ȃ�AGV_READY�Ɉڍs���A�~�߂������
        switch (AGV_STATE){
        case AGV_READY:
            AGV_STATE = AGV_RUN;
            break;

        case AGV_RUN:
            AGV_STATE = AGV_READY;
            break;
        }
    }

    // �N�[���^�C������
    COOL_TIME -= (COOL_TIME > 0);
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
    unsigned char SENS_DATA_R = 0;
    unsigned char SENS_DATA_L = 0;

    // �Z���T����l���擾���A���E�ɕ���
    SENS_DATA_R = (SENS_DATA & 0xF0) >> 4;
    SENS_DATA_L = SENS_DATA & 0x0F;

    switch (AGV_STATE){
    case AGV_READY:
        break;

    case AGV_RUN:

        // 臒l�𒴂����瓮����
        // TODO: �n���h���������ʂ͒��S���痣��Ă���قǑ傫���ق�������?
        if (SENS_DATA_L > 0x02){
            HANDLE_DATA--;
        }
        if (SENS_DATA_R > 0x04){
            HANDLE_DATA++;
        }

        // �n���h���l�͈̓`�F�b�N (�Z�[�t�e�B)
        if (HANDLE_DATA > 0xFE){
            HANDLE_DATA = 0xFE;
        }
        if (HANDLE_DATA < 1){
            HANDLE_DATA = 0x01;
        }

        if (SENS_DATA == 0){
            HANDLE_DATA = 0x80;
            AGV_STATE = AGV_RUN_ALM;
        }

        break;

    default:
        break;
    }

    // �T�[�{�ɏo��
    bios_da_output(HANDLE_DATA);
}
