/****************************************************************************************************************/
/*	FILE        :main.c																							*/
/*	DATE        :Tue, Jan 17, 2012																				*/
/*	DESCRIPTION :AGV Main Program																				*/
/*	CPU TYPE    :H8/3052F																						*/
/****************************************************************************************************************/
#include "stdio.h"
#define MAIN

#include "machine.h"
#include "reg3052.h"
#include "agvdef.h"
#include "agvvars.h"
#include "def_monitor_printf.h"

#include "initialize.h"

void agv_init(void);
unsigned char setLEDData();
unsigned char isErrorState(unsigned char state);
void beep(unsigned char stat);

/****************************************************************************************************************/
/*	main�֐�																									*/
/****************************************************************************************************************/
int main(){
    // ���W�X�^�ޏ�����
    agv_init();

    // ���C�����[�v
    while(1){
        // LED�ɏo�͂�����e���X�V
        bios_led_output(setLEDData());

        // �G���[��ԂȂ�u�U�[����
        beep(isErrorState(AGV_STATE));
		
    }

    return 0;
}

// agv������
void agv_init(void){
    initialize();
}

// LED�ɏo�͂�����e�����߂�B
//  - Parameters: �Ȃ�
//  - Return: LED�ɗ������ޒl
unsigned char setLEDData(){
    unsigned char value = 0x00;

    value |= ((AGV_STATE == AGV_BOOT) << 0);
    value |= ((AGV_STATE == AGV_READY) << 1);
    value |= ((AGV_STATE == AGV_RUN) << 2);
    value |= ((AGV_STATE == AGV_SEARCH) << 3);
    value |= ((MOTOR_STATE == MOTOR_ACCEL) << 4);
    value |= ((MOTOR_STATE == MOTOR_BREAK) << 5);
    value |= ((MOTOR_STATE == MOTOR_STOP) << 6);
    value |= (isErrorState(AGV_STATE) << 7);
	
    return value;
}

// �u�U�[��炷�B
//  - Parameters: �Ȃ�
//  - Return: �Ȃ�
void beep(unsigned char stat){
    // TODO: �炵����ς����Ȃ���?
    bios_beep_output(stat);
}

// �G���[��Ԃ��ǂ������擾����B
//  - Parameters:
//      - state: �����Ԃ̏�� (AGV_STATE)
//  - Return: �G���[��ԂȂ��1 �����łȂ����0
unsigned char isErrorState(unsigned char state){
    switch (state){
        case AGV_BOOT_ALM:
        case AGV_READY_ALM:
        case AGV_RUN_ALM:
            return 1;
        
        default:
            return 0;
    }
}