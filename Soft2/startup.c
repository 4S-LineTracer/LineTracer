/************************************************************************/
/*  FILE        :startup.c												*/
/*	DATE        :Tue, Jan 17, 2012										*/
/*  DESCRIPTION :Reset Program											*/
/*  CPU TYPE    :H8/3052F												*/
/************************************************************************/
#include	"stacksct.h"

extern void main(void);				/* main�֐��͊O���錾�ł���					*/

#pragma	entry PowerON_Reset			/* PowerON_Reset�֐�����v���O�����J�n�@	*/


void  PowerON_Reset(void)
{ 
	_INITSCT();						/* �f�[�^�����̈�̏������֐�(���C�u����)	*/

	main();							/* main�֐��̌ďo��							*/
}

