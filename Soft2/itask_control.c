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
    handle_control();
	bios_led_output(0xff);
	
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
void handle_control(void) {
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
	if(SENS_DATA_L > 0x03){
	    HANDLE_DATA--;
    }
    if(SENS_DATA_R > 0x0c){
        HANDLE_DATA++;
    }
	
	// �n���h���l�͈̓`�F�b�N (�Z�[�t�e�B)
	if(HANDLE_DATA > 0xFE){
		HANDLE_DATA = 0xFE;
	}
	if(HANDLE_DATA < 1){
	    HANDLE_DATA = 0x01;	
	}
	
	// �T�[�{�ɏo��
	bios_da_output(HANDLE_DATA);
}