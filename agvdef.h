/*****************************************************************************************************************
	FILE        :agvdef.h
	DATE        :Tue, Oct 18, 2011
	DESCRIPTION :AGV�̓��o�̓f�o�C�X�ւ����`���s��
	CPU TYPE    :H8/3052F

*****************************************************************************************************************/

/****	�f�B�W�^�����o�̓|�[�g�Ɋւ���A�h���X��`															*****/
#define	STEP_PORT	(*(volatile unsigned char *)0xa0000)		/* �X�e�b�s���O���[�^���o�̓|�[�g�̃A�h���X��`	*/
#define	SENS_PORT	(*(volatile unsigned char *)0xa0000)		/* �Z���T�����̓|�[�g�̃A�h���X��`			*/

/****	���[�N�x���`�p�l���f�o�C�X�̃|�[�g�Ɋւ���A�h���X��`												*****/
#define	SW_PORT		(*(volatile unsigned char *)0xa0007)		/* SW�|�[�g�̃A�h���X��`						*/
#define	LED_PORT	(*(volatile unsigned char *)0xa0007)		/* LED�|�[�g�̃A�h���X��`						*/
#define	BEEP_PORT	(*(volatile unsigned char *)0xa0006)		/* BEEP�|�[�g�̃A�h���X��`						*/

#define	BEEP_ON		0x01										/* BEEP ON �R�[�h								*/
#define	BEEP_OFF	0x00										/* BEEP OFF �R�[�h								*/	

/****	A/D�֌W�̃|�[�g�Ɋւ���A�h���X��`�����bit��`													*****/
#define	SH_PORT		(*(volatile unsigned char *)0xa0003)		/* S&H����w��|�[�g�̃A�h���X��`				*/
																/* bit7=1�ŃT���v�����[�h/0�Ńz�[���h			*/
#define	SAMPLE_MODE	0x80										/* �T���v�����[�h��bit��`						*/
#define	HOLD_MODE	0x00										/* �z�[���h���[�h��bit��`						*/

#define	AD_PORT		(*(volatile unsigned char *)0xa0002)		/* �C�Ӓl�����݂ŕϊ��J�n/�Ǐo��=�ϊ��l			*/

/****	D/A�|�[�g�Ɋւ���A�h���X��`																		*****/
#define DA_PORT		(*(volatile unsigned char *)0xa0004)		/* D/A�|�[�g�̃A�h���X��`						*/

/**** ����X�C�b�`�Ɋ֘A�����`																			*****/
#define	RUN_SW	0x01											/* SW_DATA�̂���bit�����Ƒ��s�J�n				*/

/****	�Z���T����уn���h���Ɋ֘A�����`																	*****/
#define SENS_CENTER		0x80									/* �Z���T�̒����l								*/
#define HANDLE_CENTER	0x80									/* �n���h���̒����l								*/

#define	Kp		0.8												/* �n���h��������W��							*/
#define	Ki		0.05											/* �n���h������ϕ��W��							*/
#define	INT_MAX	1000											/* �ϕ��v�Z�̏���l								*/


// �����ԓ�����
#define AGV_BOOT 0
#define AGV_BOOT_ALM 1
#define AGV_READY 2
#define AGV_READY_ALM 3
#define AGV_RUN 4
#define AGV_SEARCH 5
#define AGV_RUN_ALM 6

// ���[�^������
#define MOTOR_STOP 0
#define MOTOR_ACCEL 1
#define MOTOR_CONST 2
#define MOTOR_BREAK 3

