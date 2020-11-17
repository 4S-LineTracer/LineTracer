/*
 * ���̓C���^�t�F�[�X�A�N�Z�T
*/
#include "ifAccessor.h"

// �X�C�b�`�̒l���X�V����B
//  - Returns: �X�C�b�`�̒l
unsigned char swInput(){
    static unsigned char swBuffer[] = {0x00, 0x00, 0x00, 0x00};
    static unsigned int index = 0;
	unsigned char i = 0;
	unsigned char tmp = 0xFF;

    // �X�C�b�`�̒l���o�b�t�@�Ɋi�[
    swBuffer[index] = bios_sw_input();
    index++;
    index &= 0x03;

    // �o�b�t�@�̓��e�����ƂɃX�C�b�`�̒l����� �����4ms���̃`���^�����O�ɑς�����
    for (i = 0; i < 4; i++){
        tmp &= swBuffer[i];
    }
    return tmp;
}

// �Z���T�̒l���X�V����B
//  - Returns: �Z���T�̒l
unsigned char sensInput(unsigned char zeroProof){
    static unsigned char zeroCount = 0; // �[�����o��
    static unsigned char prevValue = 0; // �Ō�Ɍ��o���ꂽ�܂��Ƃ��Ȓl
	static unsigned char zeroFlag = 0; // �[�����o�t���O

    // �Z���T�̒l���擾
    unsigned char sensValue = bios_sensor_input();
    
    if(sensValue != 0){
        // �܂��Ƃ��Ȓl����ꂽ��X�V
        prevValue = sensValue;
		zeroCount = 0;
		zeroFlag = 0;
    }else{
        zeroCount++;
        // �[�����o�񐔂��K��l�𒴂�����0x00��Ԃ�
        if(zeroCount >= zeroProof){
            zeroCount = 0;
			zeroFlag = 1;
            prevValue = 0x00;
        }
    }

    // TODO: �Z���T�̒l��itask_input�Ńo�b�t�@�����O����ׂ���?
    return prevValue;
}
