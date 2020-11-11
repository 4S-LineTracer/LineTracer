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
    static unsigned char sens_data;

    SW_DATA = bios_sw_input();

    if (bios_sensor_input() == 0x00){

        SENS_DATA = sens_data;
        //return;
    }else{
        SENS_DATA = bios_sensor_input();
        sens_data = SENS_DATA;
        //return;
    }
}