/************************************************************************
	RAM�̈�Ɋ����݃x�N�^��ݒ肷��
	���j�^�@�\�ł��鉼�z�����݃x�N�^�̎g�p��O��Ƃ��邽�߁C
	�����ݔԍ�1�Ԃ���ݒ肷��
	ROM������ꍇ�͕ύX���K�v
	�f�t�H���g�l��PowerONReset���`����
*************************************************************************/

/************************************************************************
	�O���錾�̈�				
	�����݊֐����O���t�@�C���Œ�`����ꍇ�́C�����ŊO���錾���s�Ȃ�
*************************************************************************/

	extern void PowerON_Reset(void);

    extern void itask_control(); // ITU2 10ms
    extern void itask_motor(); // ITU1 variable
    extern void itask_input(); // ITU3 1ms

/************************************************************************
	�����݃x�N�^�̒�`
	�����݃x�N�^�̓Z�N�V����VectTable�ɒu��				
*************************************************************************/

#pragma section VectTable

const	unsigned int *IntVect[]={
	PowerON_Reset,						/* 0:  Reset		*/
	PowerON_Reset,						/* 1:  Reserved		*/
	PowerON_Reset,						/* 2:  Reserved		*/
	PowerON_Reset,						/* 3:  Reserved		*/
	PowerON_Reset,						/* 4:  Reserved		*/
	PowerON_Reset,						/* 5:  Reserved		*/
	PowerON_Reset,						/* 6:  Reserved		*/
	PowerON_Reset,						/* 7:  NMI			*/
	PowerON_Reset,						/* 8:  TRAPA0		*/
	PowerON_Reset,						/* 9:  TRAPA1		*/
	PowerON_Reset,						/* 10: TRAPA2		*/
	PowerON_Reset,						/* 11: TRAPA3		*/

	PowerON_Reset,						/* 12: IRQ0			*/
	PowerON_Reset,						/* 13: IRQ1			*/
	PowerON_Reset,						/* 14: IRQ2			*/
	PowerON_Reset,						/* 15: IRQ3			*/
	PowerON_Reset,						/* 16: IRQ4			*/
	PowerON_Reset,						/* 17: IRQ5			*/

	PowerON_Reset,						/* 18: Reserve		*/
	PowerON_Reset,						/* 19: Reserve		*/

	PowerON_Reset,						/* 20: WOVI(�C���^�[�o���^�C�})		*/
	PowerON_Reset,						/* 21: CMI(�R���y�A�}�b�`)			*/

	PowerON_Reset,						/* 22: Reserve		*/
	PowerON_Reset,						/* 23: Reserve		*/

	PowerON_Reset,						/* 24: IMIA0(TIU0�R���y�A�}�b�`/�C���v�b�g�L���v�`��A0)		*/
	PowerON_Reset,						/* 25: IMIB0(TIU0�R���y�A�}�b�`/�C���v�b�g�L���v�`��B0)		*/
	PowerON_Reset,						/* 26: OVI0(TIU0�I�[�o�[�t���[0)							*/

	PowerON_Reset,						/* 27: Reserve		*/

	itask_motor,						/* 28: IMIA1(TIU1�R���y�A�}�b�`/�C���v�b�g�L���v�`��A1)		*/
	PowerON_Reset,						/* 29: IMIB1(TIU1�R���y�A�}�b�`/�C���v�b�g�L���v�`��B1)		*/
	PowerON_Reset,						/* 30: OVI1(TIU1�I�[�o�[�t���[1)							*/

	PowerON_Reset,						/* 31: Reserve		*/

	itask_control,						/* 32: IMIA2(TIU2�R���y�A�}�b�`/�C���v�b�g�L���v�`��A2)		*/
	PowerON_Reset,						/* 33: IMIB2(TIU2�R���y�A�}�b�`/�C���v�b�g�L���v�`��B2)		*/
	PowerON_Reset,						/* 34: OVI2(TIU2�I�[�o�[�t���[2)							*/

	PowerON_Reset,						/* 35: Reserve		*/

	itask_input,						/* 36: IMIA3(TIU3�R���y�A�}�b�`/�C���v�b�g�L���v�`��A3)		*/
	PowerON_Reset,						/* 37: IMIB3(TIU3�R���y�A�}�b�`/�C���v�b�g�L���v�`��B3)		*/
	PowerON_Reset,						/* 38: OVI3(TIU3�I�[�o�[�t���[3)							*/

	PowerON_Reset,						/* 39: Reserve		*/

	PowerON_Reset,						/* 40: IMIA4(TIU4�R���y�A�}�b�`/�C���v�b�g�L���v�`��A4)		*/
	PowerON_Reset,						/* 41: IMIB4(TIU4�R���y�A�}�b�`/�C���v�b�g�L���v�`��B4)		*/
	PowerON_Reset,						/* 42: OVI4(TIU4�I�[�o�[�t���[4)							*/

	PowerON_Reset,						/* 43: Reserve		*/

	PowerON_Reset,						/* 44: DEND0A(DMAC0A �]������)		*/
	PowerON_Reset,						/* 45: DEND0B(DMAC0B �]������)		*/
	PowerON_Reset,						/* 46: DEND1A(DMAC1A �]������)		*/
	PowerON_Reset,						/* 47: DEND1B(DMAC1B �]������)		*/

	PowerON_Reset,						/* 48: Reserve		*/
	PowerON_Reset,						/* 49: Reserve		*/
	PowerON_Reset,						/* 50: Reserve		*/
	PowerON_Reset,						/* 51: Reserve		*/

	PowerON_Reset,						/* 52: ERI0 (SCI0 ��M�G���[)				*/
	PowerON_Reset,						/* 53: RXI0 (SCI0 ��M����)					*/
	PowerON_Reset,						/* 54: TXI0 (SCI0 ���M�f�[�^�G���v�e�B)		*/
	PowerON_Reset,						/* 55: TEI0 (SCI0 ���M�I��)					*/

	PowerON_Reset,						/* 56: ERI1 (SCI1 ��M�G���[)				*/
	PowerON_Reset,						/* 57: RXI1 (SCI1 ��M����)					*/
	PowerON_Reset,						/* 58: TXI1 (SCI1 ���M�f�[�^�G���v�e�B)		*/
	PowerON_Reset,						/* 59: TEI1 (SCI1 ���M�I��)					*/

	PowerON_Reset						/* 60: ADI (AD�ϊ�����)		*/
};

#pragma	section	