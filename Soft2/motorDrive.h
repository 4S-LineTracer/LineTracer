/*
 * �X�e�b�s���O���[�^����
*/
#ifndef _MOTORDRIVE_H_
#define _MOTORDRIVE_H_

#include "accTable.h"
#include "bios.h"

/* -------- */

void motorDrive(unsigned char* motorState, unsigned char* motorSpeed);
void stepOutput();
void calcPulseFreqTableIndex(unsigned int* index, unsigned char* motorState, unsigned char* motorSpeed);

#endif