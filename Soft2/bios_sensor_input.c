/*
 * �Z���T����
*/
#include "bios.h"

// �Z���T�̏�Ԃ��擾����B
//  - Parameters: �Ȃ�
//  - Returns: �Z���T�̌��o���(0:�����o 1:���o)
unsigned char bios_sensor_input(){
	return ~SENS_PORT;
}
