/****************************************************************************************************************/
/*	FILE        : itask_input.c																					*/
/*	DATE        :Tue, Jan 17, 2012																				*/
/*	DESCRIPTION :AGV�̓��͊��荞�݃^�X�N																		*/
/*	CPU TYPE    :H8/3052F																						*/
/****************************************************************************************************************/
#include "task.h"
/*
    // ����task.h�̃C���N���[�h�ōςދC������ �R���p�C���ʂ�Ȃ������炱��ɖ߂��܂�
    #include "machine.h"
    #include "reg3052.h"
    #include "agvdef.h"
    #include "agvvars.h"
    #include "def_monitor_printf.h"
*/

/****************************************************************************************************************/
/*	���̓^�X�N itask_input			                                                    						*/
/****************************************************************************************************************/
#pragma interrupt itask_input
void itask_input(void){
    unsigned char sens_data = bios_sensor_input();
	
	unsigned char zeroLimit = SENS_PROOF_TIME;
	static unsigned char zeroCount = 0;
	static unsigned char prev_data = 0;
	static unsigned char zeroFlag = 0;

    SW_DATA = bios_sw_input();

	
	if(sens_data != 0){
		prev_data = sens_data;
		zeroCount = 0;
		zeroFlag = 0;
	}else{
		zeroCount++;
		if(zeroCount >= zeroLimit || zeroFlag == 1){
			zeroCount = 0;
			zeroFlag = 1;
			prev_data = 0x00;
		}
	}
	
	SENS_DATA = prev_data;
}
