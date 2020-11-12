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
    // TODO: ������static����Ȃ��ƒl���ۑ�����Ȃ��č���C�����܂�
    unsigned char sens_data;

    // TODO: �`���^�����O�΍􂵂Ƃ���������������?

    /*
    // �Ⴆ�΂���Ȋ��� �f�o�b�O���ĂȂ��̂ł��̂܂܃R�s�[�͂��Ɗ댯
    static unsigned char switchBuffer[] = {0x00, 0x00, 0x00, 0x00};
    static unsigned char index = 0;
    unsigned char tmp = 0xFF;
    unsigned char i = 0;
    switchBuffer[index] = bios_sw_input();
    index++;
    index &= 3; // index��3�ȏ�ɂȂ�̂�h��

    for (i = 0; i < 4; i++){
        tmp &= switchBuffer[i];
    }
    SW_DATA = tmp;
    */

    SW_DATA = bios_sw_input();

    // TODO:�Z���T�����o�ł��Ȃ��Ȃ������̏������ǂ���������Ȃ�
    // itask_control�ł���Ă��������ǁA��莞�Ԃ�itask_input�őς��Ă�����
    // itask_control�̎�������l�����S�ł������ł͂���
    // �e�X�g�\�[�X�����Ȃ��Ă��܂� �Ƃ肠�����c���ɕ����΂����̃e�X�g�\�[�X�͏o���܂�
    if (bios_sensor_input() == 0x00){

        SENS_DATA = sens_data;
        //return;
    }else{
        SENS_DATA = bios_sensor_input();
        sens_data = SENS_DATA;
        //return;
    }
}