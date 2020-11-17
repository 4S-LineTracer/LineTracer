/*
 * 入力インタフェースアクセサ
*/
#ifndef _IF_ACCESSOR_H_
#define _IF_ACCESSOR_H_

#include "bios.h"

/* -------- */
extern unsigned char SENS_PROOF_TIME;

/* -------- */
unsigned char swInput();
unsigned char sensInput(unsigned char zeroProof);

#endif
