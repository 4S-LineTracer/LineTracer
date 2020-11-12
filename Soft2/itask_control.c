/****************************************************************************************************************/
/* FILE        : itask_control.c                    */
/* DATE        :Tue, Jan 17, 2012                    */
/* DESCRIPTION :AGV�̓����ԊǗ����荞�݃^�X�N                */
/* CPU TYPE    :H8/3052F                      */
/****************************************************************************************************************/
#include "task.h"

void handle_control(void);

/****************************************************************************************************************/
/* �����ԓ����ԊĎ��E�n���h������^�X�N itask_control              */
/****************************************************************************************************************/
#pragma interrupt itask_control
void itask_control(void){

    // ���[�^���x�ő�/�ŏ�
    unsigned char MAX_SPPED = 0;
    unsigned char MIN_SPPED = 0;

    // �N�[���^�C�� COUNT�~���b�Ԃ͎���IRQ1���󂯕t���Ȃ�
    static unsigned char COUNT = 0;

    // �n���h������
    handle_control();

    // ���[�^�[�X�s�[�h����
    // TODO: switch�ł��������� getMaxSpeed()�Ƃ��֐��ɋN�����̂��A��
    /*
        unsigned char getMaxSpeed(unsigned char sw_data){
            switch(sw_data & 0x30){
                case 0x00:
                    return 0x40;
                case 0x10:
                    return 0x80;
                
                ...

                default:
                    return 0x00; // �s���l���͂̍ۂ̃Z�[�t�e�B
            }
        }

        MOTOR_SPEED = getMaxSpeed(SW_DATA);
    */
    if (SW_DATA & 0x30 == 0x00){
        MAX_SPPED = 0x40;
    }
    else if (SW_DATA & 0x30 == 0x10){
        MAX_SPPED = 0x80;
    }
    else if (SW_DATA & 0x30 == 0x20){
        MAX_SPPED = 0xc0;
    }
    else if (SW_DATA & 0x30 == 0x30){
        MAX_SPPED = 0xff;
    }

    // AGV�X�e�[�g�G��+���[�^�[���x�ύX
    if (IRQ1_DATA == 1 && COUNT == 0){
        IRQ1_DATA = 0;
        switch (AGV_STATE){

        case AGV_READY:
            AGV_STATE = AGV_RUN;
            MOTOR_SPEED = MAX_SPPED;
            break;

        case AGV_RUN:
            MOTOR_SPEED = MIN_SPPED;
            break;
        }

        COUNT = 10;
    }
    // TODO: ����኱�댯�ȋC������ ���[�^����~������Ƃ肠����AGV_READY���Ă̂͂܂���
    // MOTOR_SPEED = 0x00; �Ƃ������܂Ȃ��Ƃ�����Ƃ��킢����
    if (MOTOR_STATE == MOTOR_STOP){
        AGV_STATE = AGV_READY;
    }

    if (COUNT > 0){
        COUNT--;
    }
    TSR2 &= ~0x01;
}

/****************************************************************************************************************/
/* AGV�X�e�[�g�Ǘ����W���[�� agv_state                   */
/****************************************************************************************************************/
void agv_state(void){
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
